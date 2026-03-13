#include <stdlib.h>
#include <stdio.h>
struct Node {
          int data;
          struct Node* next;
};
struct Node* createNode(int data){
    struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    if (!NewNode){
        exit(1);
    }
    NewNode -> data = data;
    NewNode -> next = NULL;
    return NewNode;
};
void append(struct Node** head, int data){
    struct Node* NewNode=createNode(data);
    if(*head==NULL){
        *head = NewNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next = NewNode;
}
void Print(struct Node** head){
    struct Node* temp = *head;
    while(temp!=NULL){
        printf("[%i]\n",temp->data);
        temp=temp->next;}
}
int len(struct Node** head){
    int z=0;
    struct Node* temp = *head;
    while(temp!=NULL){
        z++;
        temp=temp->next;}
    return z;
}
int elementK(struct Node** head,int k){//найти элемент по номеру к
    struct Node* temp = *head;
    int z=len(head);
    if(k>z){
        printf("error\n");
        return -1;
    }
    int i=0;
    while(i<k){
        temp=temp->next;
        i++;
    }
    return temp->data;
}
void InK(struct Node** head,int k,int v){//добавить элемент по номеру к
    struct Node* temp = *head;
    struct Node* NewNode=createNode(v);
    int z=len(head);
    if(k>z){
        printf("error\n");
        return;
    }
    if (k==0){
            NewNode->next = *head;
            *head=NewNode;
            return;
    }
    int i=0;
    int p=0;
    while(i<k-1){
        temp=temp->next;
        i++;
    }
    NewNode->next=temp->next;
    temp->next=NewNode;
}
void delK(struct Node** head,int k){//удалить элемент
    struct Node* temp = *head;
    int z=len(head);
    if(k>z){
        printf("error\n");
        return;
    }
    if(k==0){
        struct Node* DelNote = *head;
        struct Node* Prom = DelNote;
        *head=DelNote->next;
        free(Prom);
        return;
    }
    int i = 0;
    while(i<k-1){
        temp=temp->next;
        i++;
    }
    struct Node* DelNote = temp->next;
    temp->next=temp->next->next;
    free(DelNote);
}
void chered(struct Node** head1, struct Node** head2) {
    struct Node* temp1 = *head1;
    struct Node* temp2 = *head2;
    struct Node* next2;//для хранения след эл-та второго списка
    while (temp1 != NULL && temp2 != NULL) {
        next2 = temp2->next;
        temp2->next = temp1->next;//эл 2 указывает на след эл 1
        temp1->next = temp2;//эл 1 указывает на эл 2(тобишь ставим второй перед первым)
        temp1 = temp2->next;//переходим к след эл первого списка(см две строки выше)
        temp2 = next2;//к след элементу второго
    }
    if (*head1 != NULL && (*head1)->next != NULL) {//делаем второй список он должен быть как первый но без 1 элта
        *head2 = (*head1)->next;
    } else {
        *head2 = NULL;
    }
}
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode *creatNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

struct TreeNode *appen(struct TreeNode *cursor, int data) {
    if (cursor == NULL) return creatNode(data);

    if (data < cursor->data) cursor->left = appen(cursor->left, data);
    else if (data > cursor->data) cursor->right = appen(cursor->right, data);

    return cursor;
}


void NLR(struct TreeNode *root) {
    if (root != NULL) {
        printf("%i ", root->data);
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(struct TreeNode *root) {
    if (root != NULL) {
        LNR(root->left);
        printf("%i ", root->data);
        LNR(root->right);
    }
}

void RNL(struct TreeNode *root) {
    if (root != NULL) {
        RNL(root->right);
        printf("%i ", root->data);
        RNL(root->left);
    }
}

void width(struct TreeNode *root) {
    if (root != NULL) {
        struct TreeNode *ptrs[100];
        int Top = 0, i = 0;
        ptrs[i] = root;
        i++;

        while (Top < i) {
            struct TreeNode *current = ptrs[Top];
            printf("%i ", current->data);

            if (current->left != NULL) {
                ptrs[i] = current->left;
                i++;
            }

            if (current->right != NULL) {
                ptrs[i] = current->right;
                i++;
            }
            Top++;
        }
    }
}

