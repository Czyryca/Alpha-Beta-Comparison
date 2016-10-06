#ifndef TREE_H
#define TREE_H

#include "Node.h"

using namespace std;

class Tree{
 public: 
 
  Tree(int depth);

  //Height of the tree
  int depth;

  //Winner of tree / tie
  //-1 = Player 2 wins
  // 0 = tie
  // 1 = Player 1 wins
  int value;

  //Holds root node
  Node root;

  //false = Player 1's turn
  //true  = Player 2's turn
  bool turn;

  //Iterative Alpha Beta Analysis Algorithm
  void retAnalysisIter(bool player, Node *myRoot);

  //Recursive function used to populate tree
  void recurCreate(Node *myRoot, int level);

  //Recursive approach here
};

#endif
