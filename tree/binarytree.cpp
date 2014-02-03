#include <stdio.h>
#include <algorithm>

typedef struct _node{
    struct _node* left;
    struct _node* right;
    int data;
    
    _node() : left(0), right(0) {}
}Node;

int checkBalanced(Node* head){
    if (head==0){
        return 0;
    }

    int leftDepth = checkBalanced(head->left);
    int rightDepth = checkBalanced(head->right);

    if(leftDepth-rightDepth>1 || rightDepth-leftDepth>1){
        return -1;
    }else{
        return 1+std::max(leftDepth,rightDepth);
    }
}

int main(){
    Node a;
    Node b;
    Node c;
    Node d;
    
    printf("right value is %p\n", a.right);

    a.left = &b;
    a.right = &c;
    c.left = &d;

    printf("this tree is balanced? %d\n", checkBalanced(&a));
}
