/*Implementation of an AVL TREE
 *Functions: Insert and Delete
 *References:CLRS, http://en.wikipedia.org/wiki/AVL_tree, AVL Tree: MIT OCW
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a,b) a>b?a:b

struct node* rightRotate(struct node*);
struct node *leftRotate(struct node*);
struct node* insert(struct node*, int);

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
      printf("%d ", root->value);
      printPreOrder(root->left);
      printPreOrder(root->right);
   }
}

/*The core functions follow*/

int findBalance(struct node* node){
   if(node == NULL)
      return 0;
   return getHeight(node->left) - getHeight(node->right);
}



struct node* insert(struct node* node, int value){
   if(!node)
      return createNode(value);

   if(value<node->value)
      node->left = insert(node->left, value);
   else
      node->right = insert(node->right, value);

   node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

   int balance = findBalance(node);

   //RR ROTATION: Root->height: 2 or more 
   if(balance > 1 && value < node->left->value)
      return rightRotate(node);
   //LL ROTATION: Root->height: -2 0r less
   else if(balance < -1 && value < node->right->value)
      return leftRotate(node);
   //RL ROTATION

   else if(balance > 1 && value > node->left->value){
      node->left = leftRotate(node->left);
      return rightRotate(node);
   }
   //LR ROTATION
   else if(balance < -1 && value < node->right->value){
      node->right = rightRotate(node->right);
      return leftRotate(node);
   }

   return node;
}


struct node* rightRotate(struct node* y){
   struct node* x = y->left;
   struct node* temp = y->right;

   //Rotation
   x->right = y;
   y->left  = temp;

   //Update Heights
   x->height = max(getHeight(x->left), getHeight(x->right)) +1;
   y->height = max(getHeight(y->left), getHeight(y->right)) +1;

   return x;

}

struct node *leftRotate(struct node *x){
    struct node *y = x->right;
    struct node *temp = y->left;
 
    //Rotation
    y->left = x;
    x->right = temp;
 
    //Update heights
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    y->height = max(getHeight(y->left), getHeight(y->right))+1;
 
    
    return y;
}

/*Test Driver*/

int main(){
  struct node *root = NULL;
 
  
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Pre order traversal of the constructed AVL tree is \n");
  printPreOrder(root);
  printf("\n");
 
  return 0;
}

