#include "Node.h"
#include "Tree.h"
#include <iostream>

 
using namespace std;

int main(){

  Tree *test = new Tree(8);
  test->retAnalysisIter(true, &(test->root));
  cout << "Tree value: " << test->value << endl;
  return 0;
}
