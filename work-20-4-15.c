//
//  main.c
//  binary search tree
//
//  Created by edz on 2020/4/15.
//  Copyright © 2020 twh. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 7

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}TreeNode;
    TreeNode* creat_empty_tree(void);
    TreeNode* find_parent(TreeNode* tree, int elem);
        void add_leaf(TreeNode* father, int elem);
        void display_tree(TreeNode* tree);

TreeNode* creat_empty_tree(void){
    TreeNode* tree = (TreeNode*) malloc(sizeof(TreeNode));
    tree->lchild = NULL;
    tree->rchild = NULL;
    return tree;
}

TreeNode* find_parent(TreeNode* tree, int elem){
    TreeNode* p = tree;
    while(!(p->lchild == NULL && p->rchild == NULL) && !(elem < p->data && p->lchild == NULL) && !(elem > p->data && p->rchild == NULL)){
        if(elem < p->data){
            p = p->lchild;
        }else{
            p = p->rchild;
        }
    }
    return p;
}

void add_leaf(TreeNode* father, int elem){
    TreeNode* leaf = (TreeNode*) malloc(sizeof(TreeNode));
    leaf->data = elem;
    leaf->lchild = NULL;
    leaf->rchild = NULL;
    if(elem < father->data){
        father->lchild = leaf;
    }else{
        father->rchild = leaf;
    }
    
}

void display_tree(TreeNode* tree){
    if(tree->lchild){
        display_tree(tree->lchild);
    }
    
    printf("%d ", tree->data);
    
    if(tree->rchild){
        display_tree(tree->rchild);
    }
}


int main(){
    
    int a[SIZE] = {2, 9, 8, 6 ,1 ,7, 5}
    TreeNode* tree = creat_empty_tree();
    tree->data = a[0];
    for(int i = 1; i < SIZE; i++){
        TreeNode* pos = find_parent(tree, a[i]);
        add_leaf(pos, a[i]);
    }
    display_tree(tree);
    printf("\n");
    return 0;
}

