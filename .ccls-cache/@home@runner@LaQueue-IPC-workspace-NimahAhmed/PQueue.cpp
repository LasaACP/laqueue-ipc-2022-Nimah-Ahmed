/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */



		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	/* Your code here */

  // Create a new node that copies over item's data into its own
  node* newNode =  (node*)malloc(sizeof(node));
  newNode->data = item;
  newNode->priority = priority;
  newNode->link = NULL;

  // If the queue is empty, set the new node as the head
  if(front == NULL){
    front = newNode;
  }
  // If the new node has a higher priority (lower number) than the head, set the new node as the head
  else if(priority < front->priority){
    newNode->link = front;
    front = newNode;
  }
  // If the new node has a lower priority (higher number) than the head, traverse the queue to find the correct spot to insert the new node
  else{
    node* temp = (node*)malloc(sizeof(node));
    temp=front;
    while(temp->link != NULL && temp->link->priority <= priority){
      temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;

  }

}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	/* Your code here */
  // If the queue is empty, return NULL
  if(front == NULL){
    return NULL;
  }
  // If the queue is not empty, return
  else{
    return front->data;
  }
  
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	/* Your code here */
  // If queue is empty, do nothing, since it is a void function
  if(front == NULL){
    
  }
  // If queue is not empty, set the head to the next node, set temp to the old head, and delete the old head
  else{
    node* temp = front;
    front = front->link;
    delete temp;
  }
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{
	/* Your code here */
  node *ptr = front;
  while (ptr != NULL)
  {
    std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
    ptr = ptr->link;
  }
  std::cout<<"\n"; 
	/* Use the following out command for the data */
}
	