#pragma once

template <typename T>
class List
{

public:

   virtual void operator=(
      const List& copyObject) = 0;

   virtual int size() = 0;

   // Add/Remove
   
   virtual void push_back(const T& value) = 0;
   
   virtual void push_front(const T& value) = 0;
   
   virtual void pop_back() = 0;
   
   virtual void pop_front() = 0;

   virtual void clear() = 0;
  
   virtual void clear(
      unsigned int index) = 0;

   // Access

   virtual T front() = 0;
   
   virtual T back() = 0;

   virtual T get(
      unsigned int index) = 0;
   
   virtual T& at(
      unsigned int index) = 0;

   virtual T& operator[](unsigned int index) = 0;

   virtual int indexOf(
      const T& value) = 0;
};
