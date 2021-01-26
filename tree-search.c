/*
 * Author: Michael Lakostik
 *
 * Created on April 17, 2020, 6:08 PM
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_SIZE 25

typedef struct{
	char word[MAX_WORD_SIZE];
}NodeData;

typedef struct treenode{
	NodeData data;
	struct treenode* left;
	struct treenode* right;
}TreeNode;



typedef struct{
	TreeNode* root;
}BinaryTree;

TreeNode* newTreeNode(NodeData node) {
	TreeNode* p = (TreeNode*) malloc(sizeof(TreeNode));
	p->data = node; // Copies the node data
	p->left = p->right = NULL;
	return p;
}

TreeNode* findOrInsert(BinaryTree* bt, char str[]) {
	NodeData node;
	strcpy(node.word, str); // Put 'str' in a node data structure

	if (bt->root == NULL) // Is tree empty?
		return bt->root = newTreeNode(node); // Returns value assigned

	TreeNode* curr = bt->root; // Temporary pointer, current position
	int cmp;
	while ((cmp = strcmp(node.word, curr->data.word)) != 0) {
		if (cmp < 0) { // Should we go left?
			if (curr->left == NULL)
				return curr->left = newTreeNode(node);
			curr = curr-> left;
		} else {
			// Must be right
			if (curr->right == NULL)
				return curr->right = newTreeNode(node);
			curr = curr->right;
		}
	}
	printf("Item was found\n"); // If we reach here, item was found in the tree!
	return curr;
}

// Method to print the data/word of the node
void visit(TreeNode *node){
	printf("%s ",node->data.word);
}

void inOrder(TreeNode* node){
	if(node!=NULL)
	{
    visit(node);
		inOrder(node->left);
		inOrder(node->right);
	}
}

int main() {
    char input[MAX_WORD_SIZE];
	BinaryTree bt;
	bt.root = NULL;
        //Prompt user for input of 10 words
	printf("Enter 10 words: \n");
        for(int i=0; i<10; i++){
            printf("Word %d: ", i+1);
            int cnt = scanf("%s", input);
		if (cnt != 1)
			break;
		findOrInsert(&bt, input); //Add user's input to the tree
        }

	inOrder(bt.root);

	char search[MAX_WORD_SIZE];

        //Search for a string in the tree
	printf("\nEnter the string you would like to search: \n");
	scanf("%s", search);
	findOrInsert(&bt, search);
  return 0;
}
