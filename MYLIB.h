#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

struct Node {
    int data;
    struct Node* next;
};

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Функции для списка
struct Node* createNode(int data);
void append(struct Node** head, int data);
void Print(struct Node** head);
int len(struct Node** head);
int elementK(struct Node** head, int k);
void InK(struct Node** head, int k, int v);
void delK(struct Node** head, int k);
void chered(struct Node** head1, struct Node** head2);

// Функции для дерева
struct TreeNode* creatNode(int data);
struct TreeNode* appen(struct TreeNode* cursor, int data);
void NLR(struct TreeNode* root);
void LNR(struct TreeNode* root);
void RNL(struct TreeNode* root);
void width(struct TreeNode* root);

#endif // MYLIB_H_INCLUDED
