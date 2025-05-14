#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int coefficient, exponent;
    struct Node* next;
} Node;
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}
Node* createPolynomial() {
    Node *head = NULL, *tail = NULL;
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        Node* newNode = createNode(coeff, exp);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void displayPolynomial(Node* head) {
    while (head) {
        printf("%dx^%d", head->coefficient, head->exponent);
        if (head->next) printf(" + ");
        head = head->next;
    }
    printf("\n");
}
Node* addPolynomials(Node* p1, Node* p2) {
    Node *result = NULL, *tail = NULL;
    while (p1 || p2) {
        int coeff, exp;
        if (p1 && (!p2 || p1->exponent > p2->exponent)) {
            coeff = p1->coefficient;
            exp = p1->exponent;
            p1 = p1->next;
        } else if (p2 && (!p1 || p2->exponent > p1->exponent)) {
            coeff = p2->coefficient;
            exp = p2->exponent;
            p2 = p2->next;
        } else {
            coeff = p1->coefficient + p2->coefficient;
            exp = p1->exponent;
            p1 = p1->next;
            p2 = p2->next;
        }
        Node* newNode = createNode(coeff, exp);
        if (!result) result = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return result;
}
void freePolynomial(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    printf("First Polynomial:\n");
    Node* poly1 = createPolynomial();
    printf("Second Polynomial:\n");
    Node* poly2 = createPolynomial();
    printf("First polynomial: ");
    displayPolynomial(poly1);
    printf("Second polynomial: ");
    displayPolynomial(poly2);
    Node* sum = addPolynomials(poly1, poly2);
    printf("Sum of polynomials: ");
    displayPolynomial(sum);
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    return 0;
}