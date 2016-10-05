#include "Tree.h"
#include <iostream> //debugging
#include <stdlib.h> //used for rand()
using namespace std;

Tree::Tree(int depth){

  this->root = Node();
  this->depth = depth;
  this->turn = rand() % 2;
  recurCreate(&root, 0); 

}

void Tree::recurCreate(Node *myRoot, int level){
  if(level + 1 < depth){
    //Sets up left node
    Node *left = new Node();
    myRoot->childL = left;
    
    //Sets up right nde
    Node *right = new Node();
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
