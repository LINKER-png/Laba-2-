#include <stdlib.h>
#include <stdio.h>
#include "MYLIB.h"

int main(){
    struct Node *head = NULL;
    struct Node *head1 = NULL;
    for(int i=1;i<=8;i++){
        if(i%2!=0){
            append(&head,i);
        }else{
            append(&head1,i);
        }
    }
    printf("first list:\n");
    Print(&head);
    printf("second list:\n");
    Print(&head1);
    chered(&head,&head1);
    printf("after chered\n");
    printf("first list:\n");
    Print(&head);
    printf("second list:\n");
    Print(&head1);
    struct TreeNode *root = NULL;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int n = 7;
    for (int i = 0; i < n; i++)
        root = appen(root, values[i]);
    printf("NLR: ");
    NLR(root);
    printf("\n");

    printf("LNR: ");
    LNR(root);
    printf("\n");

    printf("RNL: ");
    RNL(root);
    printf("\n");

    printf("width: ");
    width(root);
    printf("\n");

    return 0;

}
