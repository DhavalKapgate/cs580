#include "BST.h"
/////////////////////////////////////////////////////////////
Tree * createTree()
{
	Tree *tree;
	tree=malloc(sizeof(Tree));
	if(tree==NULL)
	{
		printf("No memory was alocated for tree");
		exit(0);
	}
	tree->root=NULL;
	return tree;
}
/////////////////////////////////////////////////////////////
Node * createNode(Data d)
{
        Node *node;
        node=malloc(sizeof(Node));
        if(node==NULL)
        {
                printf("No memory was allocated for Node");
                exit(0);
        }
        node->data.number=0;
	node->parent=NULL;
        node->left=NULL;
        node->right=NULL;
	node->data.number=d.number;
        return node;
}
////////////////////////////////////////////////////////////////
void insert(Tree * bst, Data value)
{
	if(bst->root==NULL)
	{
		Node *node;
		node=createNode(value);
		bst->root=node;
	}
	else
		insertNode(bst->root,value);
}
////////////////////////////////////////////////////////////////
void insertNode(Node * node, Data value)
{
	if(node->data.number==value.number)
		printf("<-Cannot insert this duplicate value");
	else if(value.number < node->data.number)
	{
		if(node->left!=NULL)
			insertNode(node->left,value);
		else
		{
			Node *nod;
			nod=createNode(value);
			nod->parent=node;
			node->left=nod;
		}
	}
	else if(value.number > node->data.number)
     	{
                if(node->right!=NULL)
                        insertNode(node->right,value);
                else
                {
                        Node *nod;
			nod=createNode(value);
			nod->parent=node;
                        node->right=nod;
                }
        }
}
////////////////////////////////////////////////////////////////
void display(Node *node)
{
	if(node==NULL)
                return;
	display(node->left);
	printf(" %d ",node->data.number);
	display(node->right);
}
//////////////////////////////////////////////////////////////
void LeafList(Node *node)
{
        if(node==NULL)
                return;
        LeafList(node->left);
        LeafList(node->right);
        printf(" %d ",node->data.number);
}
///////////////////////////////////////////////////////////////
Node * search(Tree * bst, Data value)
{
	Node *search_node;
	search_node=NULL;
	if(bst->root==NULL)
       	{
		printf("\nEMPTY TREE!!!!!!!!!!!\n");
		return NULL;
	}
        else
                search_node=searchNode(bst->root,value);
	return search_node;
}
//////////////////////////////////////////////////////////////
Node * searchNode(Node * node, Data value)
{
	if(node->data.number!=value.number)
        {
		Node *nod;
		if(value.number < node->data.number && node->left!=NULL)
                {
			nod=searchNode(node->left,value);
			return nod;
		}
                else if(node->right!=NULL)
                {
			nod=searchNode(node->right,value);
			return nod;
		}
	}
       else
                return node;
}
////////////////////////////////////////////////////////////////
void removeLeaf(Tree * bst, Node * d_node)
{
	Node *Parent;
	Parent=d_node->parent;
	if(Parent==NULL)
		bst->root=NULL;
	else
	{
		if(Parent->left==d_node)
			Parent->left=NULL;
		else if(Parent->right==d_node)
        	        Parent->right=NULL;
	}
	free(d_node);
}
///////////////////////////////////////////////////////////////////
void shortCircuit(Tree * bst, Node * d_node)
{
	if(bst->root!=d_node)
	{
		Node *Parent;
        	Parent=d_node->parent;
        	if(Parent->left==d_node)
        	 	if(d_node->left!=NULL)
			{
				Parent->left=d_node->left;
				d_node->left->parent=Parent;
			}
			else
			{
        	        	Parent->left=d_node->right;
				d_node->right->parent=Parent;
 			}
		else if(Parent->right==d_node)
			if(d_node->left!=NULL)
        	        {
				Parent->right=d_node->left;
				d_node->left->parent=Parent;
			}
			else
			{
               		         Parent->right=d_node->right;
				d_node->right->parent=Parent;
			}
	}
	else								//incase d_node is root and one branched
	{
		if(d_node->right!=NULL)	
		{
			bst->root=d_node->right;
			d_node->right->parent=NULL;
		}
		else if(d_node->left!=NULL)
		{
			bst->root=d_node->left;
                        d_node->left->parent=NULL;
		}
	}
        free(d_node);
}
///////////////////////finds the leftmost leaf of a branch///////////////////////////////////////
Node * getMinNode(Node * node)
{
	if(node->left!=NULL)
		getMinNode(node->left);
	else
		return node;
}
///////////////////////////////////////////////////////////////
void promotion(Tree * bst, Node * d_node)
{
	if(d_node->left==NULL && d_node->right==NULL)
		removeLeaf(bst,d_node);
	else if(d_node->left==NULL || d_node->right==NULL)
		shortCircuit(bst,d_node);
	else
	{
		Node *successor;
		successor=getMinNode(d_node->right);
		if(bst->root==d_node)					//if root is to be deleted
			bst->root=successor;
		if(d_node->left!=successor)				//this check is to avoid linking the successor to itself
			successor->left=d_node->left;
		if(d_node->right!=successor)				//this check is to avoid linking the successor to itself
			successor->right=d_node->right;
		if(d_node->parent!=NULL)				//if root is to be deleted then parent is absent so check parent for such cases
			if(d_node->parent->left==d_node)
				d_node->parent->left=successor;
			else
				d_node->parent->right=successor;
		if(successor->left!=NULL)				//managing left node of node being deleted
			if(successor->left->parent==d_node)
				successor->left->parent=successor;
		if(successor->right!=NULL)				//managing right node of node being deleted
			if(successor->right->parent==d_node)
                        	successor->right->parent=successor;
		if(successor->parent->left==successor)
			successor->parent->left=NULL;
		successor->parent=d_node->parent;

		d_node->right=d_node->left=d_node->parent=NULL;
		free(d_node);
	}
}
//////////////////////////////////////////////////////////////
//usr/include/stdio.h:175:12: note: previous declaration of ‘remove’ was here is error encountered when the function name is remove.
void Remove(Tree * bst, Data value)
{
	Node *nod;
	nod=search(bst,value);
	if(nod!=NULL)
		promotion(bst,nod);
	else
		printf("Node doesnot exist\n");
}
////////////////////////////////////////////////////////////////
void deleteTree(Tree *tree,Node *node)
{
	if(node==NULL)
		return;
        deleteTree(tree,node->left);
        deleteTree(tree,node->right);
	printf("Node deleted : %d \n",node->data.number);
        removeLeaf(tree,node);
}
////////////////////////////////////////////////////////////////
int main()
{
	printf("<------------------Binary Search Tree------------------------->");
	Tree *tree=createTree();
	FILE *ptr;
	char char_value;
	Data value;
	ptr=fopen("data.txt","r");
	while((char_value=fgetc(ptr))!=EOF)
	{
		value.number=char_value-48;
		insert(tree,value);
		fscanf(ptr,"%c",&char_value);
	}
	printf("\n==============================================\n");
	display(tree->root);
	printf("\n==============================================\n");
	printf("\n");
	printf("\nEnter value to be searched : ");
        scanf("%d",&value.number);
	while(value.number!=0)
	{
		Node *nod;
		nod=search(tree,value);
		if(nod==NULL)
			printf("VALUE NOT FOUND!!!!");
		else
		{
			printf("NODE WITH VALUE %d FOUND!!!!",nod->data.number);
			if(nod->parent!=NULL)
				printf("\tITS PARENT NODE : %d",nod->parent->data.number);
			if(nod->left!=NULL)
				printf(", LEFT CHILD : %d",nod->left->data.number);
			if(nod->right!=NULL)
				printf(", RIGHT CHILD : %d",nod->right->data.number);
		}
		printf("\nEnter value to be searched : ");
                scanf("%d",&value.number);
	}
	printf("\n");
        do
        {
		printf("\nEnter node value to be deleted : ");
                scanf("%d",&value.number);
                Remove(tree,value);
		if(tree->root==NULL)break;
		printf("\n==============================================\n");
		display(tree->root);
		printf("\n==============================================\n");
        }
	while(value.number!=0);
	if(tree->root!=NULL)
	{
		printf("The Post Order Form of tree:\n");
		printf("\n==============================================\n");
        	LeafList(tree->root);
        	printf("\n==============================================\n");
		deleteTree(tree,tree->root);
	}
	free(tree);
	fclose(ptr);
	return 0;
}
////////////////////////////////////////////////////////////////

