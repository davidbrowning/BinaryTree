#include<iostream>
#include<memory>

// My implementation of a Binary Tree from scratch

template<typename T>
struct Node
{
  Node<T>();
  Node<T>(T val);
  T value;
  std::shared_ptr<Node<T> > left;
  std::shared_ptr<Node<T> > right;

  Node<T>()
  {
    left = nullptr;
    right = nullptr;
  }

  Node<T>(T val)
  {
    value = val;
    left = nullptr;
    right = nullptr;
  }
};

template<typename T>
class binary_tree
{
  public:
    binary_tree<T>();
    binary_tree<T>(T r);

    void insert(T value);
    void print();

    binary_tree<T>()
    {
      root = nullptr;
    }

    binary_tree<T>(T r){
      root = std::make_shared<Node<T> >(r);
      root->right = nullptr;
      root->left = nullptr;
    }

    void insert(T value){
      insert_into_tree(root, value);
    }

    void print(){
      std::cout << "Pre-Order:" << std::endl;
      pre_order_traversal(root);
      std::cout << "\n\nIn-Order:" << std::endl;
      in_order_traversal(root);
      std::cout << "\n\nPost-Order:" << std::endl;
      post_order_traversal(root);
      std::cout << std::endl;
    }
  private:
    void pre_order_traversal (std::shared_ptr<Node<T> > n);
    void in_order_traversal (std::shared_ptr<Node<T> > n);
    void post_order_traversal (std::shared_ptr<Node<T> > n);
    void insert_into_tree (std::shared_ptr<Node<T> > n, T value);

    std::shared_ptr<Node<T> > root;

    void pre_order_traversal (std::shared_ptr<Node<T> > n){
      if(n == nullptr){
        return;
      }
      std::cout << n->value << " -> ";
      pre_order_traversal (n->left);
      pre_order_traversal (n->right);
    }
    
    void in_order_traversal (std::shared_ptr<Node<T> > n){
      if(n == nullptr){
        return;
      }
      in_order_traversal (n->left);
      std::cout << n->value << " -> ";
      in_order_traversal (n->right);
    }
    
    void post_order_traversal (std::shared_ptr<Node<T> > n){
      if(n == nullptr){
        return;
      }
      post_order_traversal (n->left);
      post_order_traversal (n->right);
      std::cout << n->value << " -> ";
    }
    
    void insert_into_tree (std::shared_ptr<Node<T> > n, T value){
      if(n == nullptr)
      {
        root = std::make_shared<Node<T> >(Node<T>(value));
        return;
      }
      if(value > n->value)
        if(n->right != nullptr)
          insert_into_tree(n->right, value);
        else
          n->right = std::make_shared<Node<T> >(Node<T>(value));
      else if(value < n->value)
        if(n->left != nullptr)
          insert_into_tree(n->left, value);
        else
          n->left = std::make_shared<Node<T> >(Node<T>(value));
    }
};
