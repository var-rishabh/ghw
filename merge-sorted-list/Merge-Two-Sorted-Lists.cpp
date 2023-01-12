/* C++ program to merge two sorted linked lists */
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
    int data;
    Node *next;
};

void MoveNode(Node **destRef, Node **sourceRef);

Node *SortedMerge(Node *a, Node *b) {
    Node dummy;

    Node *tail = &dummy;

    dummy.next = NULL;
    while (1) {
        if (a == NULL) {
            tail->next = b;
            break;
        } else if (b == NULL) {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);

        tail = tail->next;
    }
    return (dummy.next);
}

void MoveNode(Node **destRef, Node **sourceRef) {
    Node *newNode = *sourceRef;
    assert(newNode != NULL);

    *sourceRef = newNode->next;

    newNode->next = *destRef;

    *destRef = newNode;
}

void push(Node **head_ref, int new_data) {
    /* allocate node */
    Node *new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node *res = NULL;
    Node *a = NULL;
    Node *b = NULL;

    push(&a, 45);
    push(&a, 40);
    push(&a, 35);
 
    push(&b, 70);
    push(&b, 60);
    push(&b, 10);

    res = SortedMerge(a, b);

    cout << "Merged Linked List is: \n";
    printList(res);

    return 0;
}