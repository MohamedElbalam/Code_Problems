#include <iostream>
#include <list>
using namespace std;

struct Node{
  int data;
  Node *next;
};


void insertNode(Node** head_ref, int new_data)
{
    //create new node to hold the parameter data
    Node *new_node = new Node();

//assign data to the new node
    new_node->data = new_data;

//hold the head in the next new node
    new_node->next = (*head_ref);

    *head_ref = new_node;
}

int main(){

    return 0;
}