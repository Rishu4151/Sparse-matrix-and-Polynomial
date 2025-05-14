#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int row, col, value;
    struct Node* next;
} Node;
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
Node* createSparseMatrix() {
    Node *head = NULL, *tail = NULL;
    int rows, cols, nonZeroCount;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Number of non-zero elements: ");
    scanf("%d", &nonZeroCount);
    for (int i = 0; i < nonZeroCount; i++) {
        int row, col, value;
        printf("Row, column, value for non-zero element %d: ", i + 1);
        scanf("%d %d %d", &row, &col, &value);
        Node* newNode = createNode(row, col, value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void displaySparseMatrix(Node* head) {
    printf("Sparse Matrix Representation (row, column, value):\n");
    while (head) {
        printf("(%d, %d, %d)\n", head->row, head->col, head->value);
        head = head->next;
    }
}
void freeSparseMatrix(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    Node* sparseMatrix = createSparseMatrix();
    displaySparseMatrix(sparseMatrix);
    freeSparseMatrix(sparseMatrix);
    return 0;
}