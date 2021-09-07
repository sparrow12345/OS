#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  struct ListNode* next;
  int data;
  int s;
};
struct ListNode* first = NULL;

void insert_node(int new_data,int after){
  struct ListNode* node = first;
  for (;node!=NULL;) {
    if (node->data==after) {
      struct ListNode* new_ = (struct ListNode*) malloc(sizeof(struct ListNode));
      new_->next = node->next;
      new_->data = new_data;
      node->next = new_;
      break;
    }
    node = node->next;
  }
}

void delete_node(int deleted) {
  struct ListNode* node = first;
  if (node->data==deleted){
    first = node->next;
    return ;
  }

  for (;node->next!=NULL;) {
    if (node->next->data==deleted) {
      node->next = node->next->next;
      break;
    }
  }
}

void print_list(){
  struct ListNode* node = first;
  for (;node!=NULL;) {
    printf("%d ",node->data);
    node = node->next;
  }
  printf("\n");
}

int main() {
  first = (struct ListNode*) malloc(sizeof(struct ListNode));
  first->data=10;
  insert_node(10,1);
  print_list();
  insert_node(2,10);
  print_list();
  insert_node(3,2);
  print_list();
  delete_node(2);
  print_list();
}
