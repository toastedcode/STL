#pragma once

#include "List.hpp"

#ifndef NULL
  #define NULL 0
#endif

template <typename T>
class LinkedList : public List<T>
{

public:

   LinkedList();

   ~LinkedList();

   virtual void operator=(
      const List<T>& copyObject);

   virtual int size();

   // Add/Remove
   
   virtual void push_back(const T& value);
   
   virtual void push_front(const T& value);
   
   virtual void pop_back();
   
   virtual void pop_front();

   virtual void clear();
  
   virtual void clear(
      unsigned int index);

   // Access

   virtual T front();
   
   virtual T back();

   virtual T get(
      unsigned int index);
   
   virtual T& at(
      unsigned int index);

   virtual T& operator[](unsigned int index);

   virtual int indexOf(
      const T& value);

private:

   typedef struct Node
   {
      T item;
      Node *next;
      Node *prev;
   };

   int len; // Size of list 
  
   Node* start;
  
   Node* end;
};

// Constructor
template<class T>
LinkedList<T>::LinkedList()
{
  len = 0;
  start = NULL;
  end = NULL;
}

// Destructor
template<class T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template<class T>
void LinkedList<T>::operator=(
   const List<T>& copyObject)
{
}

// Push at front
template<class T>
void LinkedList<T>::push_front(const T& i)
{
  Node *tmp = new Node;
  tmp->item = i;
  tmp->next = NULL;
  tmp->prev = NULL;

  if(start==NULL) // If list is empty
  {
    start = tmp;
    end = tmp;
  }
  else // Insert at start
  {
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
  }
  len++; // Increase size counter
}

// Push at back
template<class T>
void LinkedList<T>::push_back(const T& i)
{
  Node *tmp = new Node;
  tmp->item = i;
  tmp->next = NULL;
  tmp->prev = NULL;

  if(end==NULL) // If list is empty
  {
    start = tmp;
    end = tmp;
  }
  else // Insert at the end
  {
    tmp->prev = end;
    end->next = tmp;
    end = tmp;
  }
  len++; // Increase size counter
}

// Pop from front
template<class T>
void LinkedList<T>::pop_front()
{
  if(start!=NULL)
  {
    Node *tmp = start;
    start = start->next;
    if(start!=NULL) // Re-link next item to NULL
    start->prev = NULL;
    else // List became empty so we need to clear end
    end = NULL;
    delete tmp;
    len--; // Decrease counter
  }
}

// Pop from back
template<class T>
void LinkedList<T>::pop_back()
{
  if(end!=NULL)
  {
    Node *tmp = end;
    end = end->prev;
    if(end!=NULL) //Re-link previous item to NULL
    end->next = NULL;
    else // List became empty so we need to clear start
    start = NULL;
    delete tmp;
    len--; // Decrease counter
  }
}

// Get item from front
template<class T>
T LinkedList<T>::front()
{
  if(start!=NULL)
  return start->item;
  //TODO: Catch error when list is empty
}

//Get item from back
template<class T>
T LinkedList<T>::back()
{
  if(end!=NULL)
  return end->item;
  //TODO: Catch error when list is empty
}

// Get size
template<class T>
int LinkedList<T>::size()
{
  return this->len;
}

// Clear list
template<class T>
void LinkedList<T>::clear()
{
  Node *tmp = start;
  while(start!=NULL)
  {
    tmp = start;
    start = start->next;
    delete tmp; // Delete item
    len--; // Decrease counter
  }
  end = NULL;
}
template<class T>
void LinkedList<T>::clear(unsigned int index)
{
  Node *tmp = start;
  for(int i=0;i<=index&&tmp!=NULL;i++)
  {
    if(i==index)
    {
      if(tmp->prev!=NULL)
      tmp->prev->next = tmp->next;
      else
      start = tmp->next;

      if(tmp->next!=NULL)
      tmp->next->prev = tmp->prev;
      else
      end = tmp->prev;

      len--; // Decrease counter
      delete tmp; // Delete item
      break;
    }
  }
}

// Get at index
template<class T>
T LinkedList<T>::get(unsigned int index)
{
  Node *tmp = start;
  for(int i=0;i<=index&&tmp!=NULL;i++)
  {
    if(i==index)
    return tmp->item;
    else
    tmp=tmp->next;
  }
  //TODO: Catch error when index is out of range
}

template<class T>
T& LinkedList<T>::at(unsigned int index)
{
  Node *tmp = start;
  for(int i=0;i<=index&&tmp!=NULL;i++)
  {
    if(i==index)
    return tmp->item;
    else
    tmp=tmp->next;
  }
  //TODO: Catch error when index is out of range
}

// Get index of value
template<class T>
int LinkedList<T>::indexOf(const T& val)
{
  for(int i=0;i<this->size();i++)
  if(this->at(i) == val)
  return i;
  return -1;
}

template<class T>
T& LinkedList<T>::operator[](unsigned int index)
{
  Node *tmp = start;
  for(int i=0;i<=index&&tmp!=NULL;i++)
  {
    if(i==index)
    return tmp->item;
    else
    tmp=tmp->next;
  }
  //TODO: Catch error when index is out of range
}
