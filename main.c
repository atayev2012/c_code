#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node* left;
    struct node* right;
}NODE;

NODE** readFile(int* qty){
    FILE* filePtr = fopen("../input.txt", "rt");
    fscanf(filePtr, "%d", qty);

    NODE ** tree = (NODE**)malloc((*qty)*sizeof(NODE*));
    for(int i=0; i<*qty; i++){
        tree[i] = (NODE*)malloc(sizeof(NODE));
    }

    for(int i=0; i<*qty; i++){
        int key=0, left=0, right=0;
        fscanf(filePtr, "%d %d %d", &key, &left, &right);
//        printf("%d %d %d\n", key, left, right);
        tree[i]->key = key;

        if(left != -1){
            tree[i]->left = tree[left];
        }

        if(right != -1){
            tree[i]->right = tree[right];
        }

    }

    fclose(filePtr);
    return tree;
}

void printTreeInOrder(NODE* root){
    NODE* newRoot = root;
    if(newRoot == NULL){
        return;
    }
    printTreeInOrder(newRoot->left);
    printf("%d ", newRoot->key);
    printTreeInOrder(newRoot->right);
}

void printTreePreOrder(NODE* root){
    NODE* newRoot = root;
    if(newRoot == NULL){
        return;
    }
    printf("%d ", newRoot->key);
    printTreePreOrder(newRoot->left);
    printTreePreOrder(newRoot->right);
}

void printTreePostOrder(NODE* root){
    NODE* newRoot = root;
    if(newRoot == NULL){
        return;
    }
    printTreePostOrder(newRoot->left);
    printTreePostOrder(newRoot->right);
    printf("%d ", newRoot->key);
}

void freeTree(NODE* root){
    if(root->left != NULL){
        freeTree(root->left);
    }

    if(root->right != NULL){
        freeTree(root->right);
    }
    free(root);
}


int main() {
    int qty=0;
    NODE** tree = readFile(&qty);

    printTreeInOrder(*tree);
    printf("\n");
    printTreePreOrder(*tree);
    printf("\n");
    printTreePostOrder(*tree);

    freeTree(*tree);
    free(tree);

    return 0;
}
