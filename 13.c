#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode* root;
} BinaryTree;

TreeNode* create_tree_node(int data) {
    TreeNode* new_node = (TreeNode) malloc(sizeof(TreeNode));
    
}