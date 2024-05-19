
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* makeNode(int num) {
    struct ListNode* newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = num;
    newNode->next = NULL;

    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    
    struct ListNode* l1 = makeNode(2);
    l1->next = makeNode(4);
    l1->next->next = makeNode(3);

    struct ListNode* l2 = makeNode(5);
    l2->next = makeNode(6);
    l2->next->next = makeNode(4);

    
    struct ListNode* result = addTwoNumbers(l1, l2);

    
    printf("Result: ");
    printList(result);

    
    free(l1);
    free(l2);
    free(result);

    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = NULL;
    struct ListNode* tail = NULL;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;

        struct ListNode* newNode = makeNode(sum % 10);

        if (!l3) {
            l3 = newNode;
            tail = l3;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return l3;
}