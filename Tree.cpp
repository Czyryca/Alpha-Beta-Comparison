#include "Tree.h"
#include <iostream> //debugging
#include <stdlib.h> //used for rand()
using namespace std;

Tree::Tree(int depth){

  this->root = Node();
  this->depth = depth;
  this->turn = rand() % 2; //unused?
  recurCreate(&root, 0); 

}

void Tree::recurCreate(Node *myRoot, int level){
  if(level + 1 < depth){
    //Sets up left node
    Node *left = new Node();
    left->value = -2;
    myRoot->childL = left;
    
    //Sets up right node
    Node *right = new Node();
    right->value = -2;
    myRoot->childR = right;

    //Continues down tree
    recurCreate(left, level + 1);
    recurCreate(right, level + 1);

  } else {
    //Base case
    myRoot->value = rand() % 3 - 1;
    //Below used for debugging
    //cout << "Generated child node value: " << myRoot->value << endl;
  }
}
//Recursive Bootstrap
int Tree::retAnalysisRecursive(){
    return retSub(true,&root);
}

int Tree::retSub(bool player1, Node *parent){
    if((parent->childL==NULL) & (parent->childR==NULL)){
        return parent->value;
    }
    else if(player1){
        return max(retSub(false,parent->childL),retSub(false,parent->childR));
    }
    else{
        
        return min(retSub(true,parent->childL),retSub(true,parent->childR));
    }
}

void Tree::retAnalysisIter(bool player, Node *myRoot){
	//int level = 0;
	//Run until root node's value is determined
	while(myRoot->value == NULL){
		Node *next = myRoot;
		bool tempPlayer = player;
		//Scan down the tree, solving sub-trees when possible
		while(next->value == NULL){
			//Left child undefined, continue scanning left
			//cout << "Trying to print next child's value" << endl;
			//cout << next->childL->value << endl;

			if(next->childL != NULL && next->childL->value == NULL){
				next = next->childL;
				tempPlayer = !tempPlayer;
			//Right child undefined, continue scanning right
			} else if(next->childR != NULL && next->childR->value == NULL){
				next = next->childR;
				tempPlayer = !tempPlayer;
			//Both children defined, solve for current node
			} else {
				//Player 1's turn
				if(!tempPlayer){
					//At least one child is 1, so this node is 1
					if((next->childL != NULL && next->childL->value == 1 )||(next->childR != NULL && next->childR->value == 1)){
						next->value = 1;
					//Neither child is one, but at least one is 0
					} else if((next->childL != NULL && next->childL->value == 0) || (next->childR != NULL && next->childR->value == 0)){
						next->value = 0;
					//All routes lead to a -1
					} else {
						next->value = -1;
					} 
				//Player 2's turn
				} else {
					//At least one child is a -1, so this node is a -1
					if((next->childL != NULL && next->childL->value == -1) || (next->childR != NULL &&next->childR->value == -1)){
						next->value = -1;
					//Neither child is -1, but at least one is 0
					} else if((next->childL != NULL && next->childL->value == 0) || (next->childR != NULL &&next->childR->value == 0)){
						next->value = 0;
					//All routes lead to a 1
					} else {
						next->value = 1;
					}
				}
			}

		}
	}
	//At algorithm's end, set tree's value to value of root node
	this->value = myRoot->value;
}
