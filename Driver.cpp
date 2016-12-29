#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <stdio.h>
#include <ctime> //used to measure runtime

 
using namespace std;

int main(){
  for (int i = 10; i <= 21; i++){
    Tree *test = new Tree(i);
    clock_t begin = clock();
    test->retAnalysisIter(true, &(test->root));
    clock_t end = clock();
    printf("Iterative on %d levels: got %d in %f seconds.\n",
            i,test->value,double(end-begin)/CLOCKS_PER_SEC);
    }
  for (int i = 10; i <= 21; i++){
    Tree *test = new Tree(i);
    clock_t begin = clock();
    test->retAnalysisRecursive();
    clock_t end = clock();
    printf("Recursive on %d levels: got %d in %f seconds.\n",
            i,test->value,double(end-begin)/CLOCKS_PER_SEC);
    }
	cin.get();
    return 0;
}
