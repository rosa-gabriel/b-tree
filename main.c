#include<stdio.h>
#include<stdlib.h>

#define MAX 3

struct node {
    int size;
    int keys[MAX - 1];
    struct node *children[MAX];
};

typedef struct node node_t; 

node_t* new_node() {
    node_t* new_node = malloc(sizeof(node_t));

    for (int i = 0; i < MAX; i++) {
        new_node->children[i] = NULL;
    }
}

node_t* insert_value(node_t *root, int value) {
    if (root == NULL) {
        root = new_node();
        root->keys[0] = value;
        root->size = 1;
    } else {
        for (int i = 0; i < MAX; i++) {
            int* i_num = &(root->keys[i]);
            printf("\n--\ni_num: %d\n", *i_num);
            printf("value: %d\n", value);
            if (*i_num == value) {
                return root;
            } else if (i >= root->size) {
                printf("append\n");
                root->keys[i] = value;
                root->size += 1;
                break;
            } else if (*i_num > value) {
                printf("start\n");
                node_t* child = root->children[i];
                root->children[i] = insert_value(child, value);
                break;
            } else if (i == MAX-1){
                printf("end\n", value);
                node_t* child = root->children[i+1];
                root->children[i+1] = insert_value(child, value);
                break;
            }
        }
    }

    return root;
}

void main() {
    printf("1");
    node_t* root = insert_value(NULL, 10);
    printf("2");
    root = insert_value(root, 5);
    printf("3");
    root = insert_value(root, 20);
    printf("4");
    root = insert_value(root, 15);
    printf("5");

    printf("Root:\n");
    for (int i = 0; i < root->size; i++) {
        printf("%d, ", root->keys[i]);
    }
}
