#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <stdio.h>


 
using namespace std;
unsigned int maxStackLocation ; 
unsigned int minStackLocation ; 

int main(){
  for (int i = 10; i <= 24; i++){
    Tree *test = new Tree(i);
    test->retAnalysisRecursive();
    printf("Recursive on %d levels: got %d \n",
            i,test->value);
    }
    return 0;
}
