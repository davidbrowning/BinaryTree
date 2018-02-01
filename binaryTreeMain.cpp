#include "binaryTree.hpp"
#include<cstdlib>
#include<ctime>

// Sample usage of the binary tree template.  

int main(int argc, char** argv){
  std::srand(std::time(nullptr));
  binary_tree<int> b;
  std::cout << "Inserting into tree:" << std::endl;
  for(int i = 0; i < 10; i++){
    int r = std::rand() % 100;
    std::cout << r << " -> ";
    b.insert(r);
  }
  std::cout << std::endl;
  b.print();
  return EXIT_SUCCESS;
}
