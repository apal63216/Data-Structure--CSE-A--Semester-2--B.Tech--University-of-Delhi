#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    float grade;
} Student;

typedef struct TreeNode {
    Student data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode* root;
} BinaryTree;

// Function prototypes
TreeNode* create_tree_node(Student data);
void insert_node(TreeNode** node, Student data);
void inorder_traversal(TreeNode* node);
TreeNode* find_minimum(TreeNode* node);
TreeNode* find_maximum(TreeNode* node);

int main() {
    BinaryTree tree;
    tree.root = NULL;

    // Example students
    Student students[] = {
        {"Alice", 85.5},
        {"Bob", 92.0},
        {"Charlie", 78.0},
        {"David", 92.0},
        {"Eve", 85.5},
        {"Faythe", 88.0}
    };

    int num_students = sizeof(students) / sizeof(students[0]);
    for (int i = 0; i < num_students; i++) {
        insert_node(&tree.root, students[i]);
    }

    // Perform in-order traversal to print the sorted sequence of grades
    printf("In-order traversal of the students' grades:\n");
    inorder_traversal(tree.root);
    printf("\n");

    // Find and print the minimum and maximum grades
    TreeNode* min = find_minimum(tree.root);
    TreeNode* max = find_maximum(tree.root);
    
    if (min != NULL) {
        printf("Minimum grade is: %.2f by %s\n", min->data.grade, min->data.name);
    }

    if (max != NULL) {
        printf("Maximum grade is: %.2f by %s\n", max->data.grade, max->data.name);
    }

    return 0;
}

TreeNode* create_tree_node(Student data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void insert_node(TreeNode** node, Student data) {
    if (*node == NULL) {
        *node = create_tree_node(data);
    } else if (data.grade < (*node)->data.grade) {
        insert_node(&(*node)->left, data);
    } else {
        // Insert duplicates or greater values on the right subtree
        insert_node(&(*node)->right, data);
    }
}

void inorder_traversal(TreeNode* node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%s - %.2f\n", node->data.name, node->data.grade);
        inorder_traversal(node->right);
    }
}

TreeNode* find_minimum(TreeNode* node) {
    if (node == NULL) {
        return NULL;
    } else if (node->left == NULL) {
        return node;
    } else {
        return find_minimum(node->left);
    }
}

TreeNode* find_maximum(TreeNode* node) {
    if (node == NULL) {
        return NULL;
    } else if (node->right == NULL) {
        return node;
    } else {
        return find_maximum(node->right);
    }
}