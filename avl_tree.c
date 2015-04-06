/*Implementation of an AVL TREE
 *Functions: Insert and Delete
 *References:CLRS, http://en.wikipedia.org/wiki/AVL_tree, AVL Tree: MIT OCW
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a,b) a>b?a:b


struct node{
   struct node* right;
   struct node* left;
   int value;
   int height;
};

int getHeight(struct node* node_ptr){
   if(node_ptr == NULL)
      return 0;
   return node_ptr->height;
}
/*The Helper Functions Follow*/
struct node* createNode(int value){
   struct node* new_node = (struct node*)malloc(sizeof(struct node*));
   new_node->value = value;
   new_node->height = 1;
   new_node->left = NULL;
   new_node->right = NULL;
   return new_node;
}

int printPreOrder(struct node* root){
   if(root!=NULL){
      printf("%d ", root->key);
      printPreOrder(root->left);
      printPreOrder(root->right);
   }
}

/*The vital functions follow*/

int findBalance(struct node* node){
   if(node == NULL)
      return 0;
   return height(node->left) - height(node->right);
}

int insert(struct node* node, int value){
   if(!node)
      return createNode(value);

   if(value<root->value)
      root->left = insert(root->left, value);
   else
      root->right = insert(root->right, value);

   root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

   int balance = findBalance(root);

   //RR ROTATION: Root->height: 2 or more 
   if(balance > 1 && value < node->left->value)
      return rightRotate(root);
   //LL ROTATION: Root->height: -2 0r less
   else if(balance < 1 && value < node->right->value)
      return leftRotate(
}


struct node* rightRotate(struct node* ptr){
   
}
