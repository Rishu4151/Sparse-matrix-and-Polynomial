#include <stdio.h>
#include <stdlib.h>
struct Term {
    int coeff;
    int exp;
    struct Term* next;
};
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}
int main() {
    int c1, e1, c2, e2, c3, e3;
    printf("Coeff for term 1: ");
    scanf("%d", &c1);
    printf("Exp for term 1: ");
    scanf("%d", &e1);
    printf("Coeff for term 2: ");
    scanf("%d", &c2);
    printf("Exp for term 2: ");
    scanf("%d", &e2);
    printf("Coeff for term 3: ");
    scanf("%d", &c3);
    printf("Exp for term 3: ");
    scanf("%d", &e3);
    struct Term* head = createTerm(c1, e1);
    head->next = createTerm(c2, e2);
    head->next->next = createTerm(c3, e3);
    struct Term* curr = head;
    printf("Polynomial: ");
    while (curr != NULL) {
        printf("%d x^%d -> ", curr->coeff, curr->exp);
        curr = curr->next;
    }
    printf("NULL\n");
    curr = head;
    struct Term* temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    return 0;
}