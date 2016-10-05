#ifndef TREE_H
#define TREE_H

#include "Node.h"

using namespace std;

class Tree{
 public: 
 
  Tree(int depth);

  int depth;
  int value;
  Node root;
  bool turn;
  void retAnalysisIter(bool player, Node *myRoot);
  void recurCreate(Node *myRoot, int level);
  //Recursive approach here
};

#endif
