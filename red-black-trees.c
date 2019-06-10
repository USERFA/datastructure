#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	char colour;
	struct node *left;
	struct node *right;
	struct node *parent;
};
struct node* insert(struct node* ,int);
struct node* Grandparent(struct node*);
struct node* sibling(struct node*);
struct node* uncle(struct node*);
void replace(struct node*,struct node*);
void LR(struct node *);
void LR(struct node *);
void C1(struct node *);
void C2(struct node *);
void C3(struct node *);
void C4(struct node *);
void C5(struct node *);
void deletee(struct node *);
void DelC1(struct node *);
void DelC2(struct node *);
void DelC3(struct node *);
void DelC4(struct node *);
void DelC5(struct node *);
void DelC6(struct node *);
int main(){
}
//to create a node
//inserting a node
struct node* insert(struct node *root,int val){
	if(root == NULL )
		root->data = val;
		root->left = root->right = NULL;
    return root;
	if (val < root->data)
    root->left  = insert(root->left,val);
	else if (val > root->data)
    root->right = insert(root->right,val);  
	return root;
}
// grandparent code
struct node* Grandparent(struct node *N){
	if ((N == NULL)&&(N->parent ==  NULL))//no parent => no grandparent
		return N;
	else
		return NULL; }
//uncle code
struct node* uncle(struct node *N){
	struct node *G = Grandparent(N);
		if(G == NULL)//no grandparent =>no siblings
			return NULL;
		if(N->parent = G->left)				
			return G->right;//the uncle will be the right child of the grandparent
		else
			return G->left;}
// insert case1
void C1(struct node *N){
	if(N->parent == NULL)  // root node
		N->colour=='B';
	else
		C2(N);}
//insert case2
void C2(struct node *N){
	if(N->parent->colour == 'B')
			return;  //correct tree
		else
			C3(N);}
//insert case3
void C3(struct node *N){ 
	struct node *G=Grandparent(N);
	struct node *U=uncle(N);
	if ((U != NULL) && (U->colour == 'R')){
		N->parent->colour='B';
		G->colour='R';
		C1(G);
	}
	else 
	C4(N);}
//left rotation
void LR(struct node *N){
	struct node *root;
	struct node *y = N->right;  //y points to the right child of x
	N->right = y->left; 
	if(N->right != NULL){
		N->right->parent =N;
		y->parent = N->parent;}
	if(N->parent == NULL)
		root = y; //making y as the new root
	else if(N ==N->parent->left)
		N->parent->left = y;
	else{
		N->parent->right = y;
		y->left =N;
		N->parent = y;}
}
//right rotation
void RR(struct node *N){
	struct node *root;
	struct node*y = N->left ;
	N->left = y->right;
	if(y->right != NULL){
		y->right->parent = N;
		y->parent = N->parent;}
	if(y->parent == NULL)
		root = y ;
	else if(N = N->parent->left){
		N->parent->right = y;
		y->right = N;
		N->parent = y;}
}
//insert case4
void C4(struct node *N){
	struct node *G = Grandparent(N);
	if((N == N->parent->right)&&(N->parent == G->right)){
		RR(N->parent);
		N=N->left ;}
	else if((N == N->parent->left)&&(N->parent == G->right)){
		N=N->right ;}
	C5(N) ;}	
//insert case5
void C5(struct node *N){
	struct node *G = Grandparent (N);
	if((N == N->parent->left)&&(N->parent == G->left)){
		RR(G);}
	else if((N == N->parent->right)&&(N->parent == G->right)){
		LR(G);}
	N->parent->colour='B';
	G->colour='R' ; }
//repalcing or switching two nodes
void replace(struct node *N,struct node *child){
	struct node *temp;
	temp->data = N->data;
	N->data = child->data;
	child->data = temp->data;
	child->left = N;
	N->right = N->left = NULL;
}
// deleting a node's code
void deletee(struct node *N){
	struct node *child;
	if(N->right->data == N->left->data == (-1))
 		child = N->left;
	else 
		child = N->right;
		replace(N, child);//substitutes the N by its child
	if(N->colour == 'B'){
		if(child->colour='R')
			child->colour='B';
		else
	 	DelC1(N);}
	free(N);} 
//delete case1
void DelC1(struct node *N){
	if(N->parent = NULL)
		DelC2(N);}			
// find sibling
struct node* sibling(struct node *N){
	if(N = N->parent->left)
		return N->parent->right;
	else 
		return N->parent->left ;}
//delete case2
void DelC2(struct node *N){
	struct node *S = sibling(N);
	if(S->colour == 'R'){
		if(N == N->parent->left)
			LR(N->parent);
		else
	    	RR(N->parent);}
	N->parent->colour='R';
	S->colour='B' ;
	DelC3(N); }
//delete case3
void DelC3(struct node *N) {
	struct node *S = sibling(N);
	if((N->parent->colour=='B')&&(S->colour=='B')&&(S->left->colour=='B')){
		S->colour='R';
		DelC1(N->parent);
	}
	else DelC4(N);
}
//delete case4
void DelC4(struct node *N){
	struct node *S = sibling(N);
	if((N->parent->colour=='R')&&(S->colour=='B')&&(S->left->colour=='B')&&(S->right->colour=='B')){
		S->colour='R';
		N->parent->colour='B' ;}
	else DelC5(N);
}
//delete case5
void DelC5(struct node *N){
	struct node *S = sibling(N);
	if(S->colour='B'){
    	if((N==N->parent->left)&&(S->right->colour=='B')&&(S->left->colour=='R')){
			RR(S);}
    	else if((N == N->parent->right)&&(S->right->colour=='R')&&(S->left->colour=='B')){
			LR(S);
			S->colour='R';
			S->right->colour='B' ;}
	}
	DelC6(N);
}
//delete case6
void DelC6(struct node *N){ 
	struct node *S = sibling(N);
	S->colour=N->parent->colour='R';
	N->parent->colour='B';
	if(N == N->parent->left){
		S->right->colour='B';
		LR(N->parent);}
	else{
		S->left->colour='B';
		RR(N->parent);}
}


