#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
        int number;
}Data;

typedef struct node
{
        Data data;
       	struct node *parent;
        struct node *left;
        struct node *right;
}Node;

typedef struct tree
{
        struct node *root;
}Tree;

Tree * createTree();
Node * createNode(Data d);
void insert(Tree * bst, Data value);
void insertNode(Node * node, Data value);
Node * search(Tree * bst, Data value);
Node * searchNode(Node * node, Data value);
void removeLeaf(Tree * bst, Node * d_node);
void shortCircuit(Tree * bst, Node * d_node);
Node * getMinNode(Node * node);
void promotion(Tree * bst, Node * d_node);
void Remove(Tree * bst, Data value);
void LeafList(Node *node);
