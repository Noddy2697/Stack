#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *next;
};

struct node *head;  //******head is global******

struct node *createNode(int data) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void push(int data) 
{
  struct node *temp = createNode(data);
  temp->next = head;
  head = temp;
}

int pop() 
{
  struct node *temp = head;
  int data = temp->data;
  head = head->next;
  return data;
}

int isEmpty() 
{ 
  return !head; 
}

int peek()
{ 
  return head->data; 
}

int main()
{
	printf("Testing Stack...\n");
	push(1);
	push(2);
	push(3);
	assert(isEmpty() == 0);
	assert(peek() == 3);
	assert(pop() == 3);
	assert(pop() == 2);
	assert(pop() == 1);
	assert(isEmpty() == 1);
	printf("stack : all test cases passed\n");
}
