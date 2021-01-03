/*myvector.h*/

// 
// Bhavana Laxmi Radharapu
// U. of Illinois, Chicago
// CS 251: Fall 2019
// 
// Project #01: myvector class that mimics std::vector, but with my own
// implemenation outlined as follows:
//
// ???
//

#pragma once

#include <iostream>  // print debugging
#include <cstdlib>   // malloc, free

using namespace std;

template<typename T>
class myvector
{
private:
  T*   A;
  int  Size;
  int  Capacity;
//--------------
struct NODE
{
   T Data;
   struct NODE* Next;
};

struct NODE* Head;
struct NODE* Tail;
struct NODE* lastnode;
int lastindex;



public:
  // default constructor:
  myvector()
  {
     //
     // TODO
     //
     Head = nullptr;
     Tail = nullptr;
     Size = 0;
  }

  // constructor with initial size:
  myvector(int initial_size)
  {
     Head = nullptr;
     Tail = nullptr;
     Size = 0;
     for(int i = 0;i< initial_size; ++i){
      push_back(T{});
      } 
      Size = initial_size;
     //
     // TODO:
     //
     // Note: to initialize an element to a default value where 
     // the type is unknown, use T{}.  Example: A[i] = T{};
     //
  
  
  }

  // copy constructor for parameter passing:
  myvector(const myvector& other)
  {
    //
    // we have to make a copy of the "other" vector, so...
  
  Size = 0;
  Head = NULL;
  Tail = NULL;
  
  NODE* temp = other.Head;
   while(temp!=nullptr)
   {
      push_back(temp->Data);
      temp = temp->Next;
   }
  
  }

  int size()
  {
    //
    // TODO
    //
    return Size;
  }

  T& at(int i)
  {
    //
    // TODO
    //
   //  NODE* temp = Head;
    lastnode = nullptr;
    lastindex = -1;
    
    if( i == 0){
       lastnode = Head;
       lastindex = 0;
       return lastnode->Data;
    }
    else if (i == lastindex +1){
       lastindex = i;
       lastnode = lastnode->Next;
       return lastnode->Data;
    }
    else{
        NODE* temp = Head;

    for(int j=0;j<i;j++){
       
       temp = temp->Next;
       }
       return temp->Data;  // this is WRONG, but compiles
       }
  }

  void push_back(T value)
  {
     //
     // TODO
     //
     struct NODE* newNode = new struct NODE();
     newNode->Data = value;
     newNode->Next = nullptr;
     
   //  struct NODE* curNode = Head;
     
     if(Head == nullptr){
        Head = newNode;
        Tail = newNode;
     }
     else{
        Tail->Next = newNode;
        Tail = newNode;
     }
     Size++;
  }
  
  
 T erase(int i){
    T val;
    NODE* curNode = Head;
    NODE* temp = Head;
    for( int j=0;j<i;j++)
    {
       temp = curNode;
       curNode = curNode->Next;
    }
    
    if(curNode == Head)
    {
       Head = curNode->Next;
    }
     
    else if( curNode == Tail){
       temp->Next = NULL;
       Tail = temp;
    }
   else
      temp->Next = curNode->Next;
    
    val = curNode->Data;
    delete curNode;
    Size--;
    return val;
     
 }
 T& operator[](int i){
    return at(i);
 }
  
 T* rangeof(int i,int j){
    int size = j-i+1;
    T* V = new T[size];
    for(int k=0; k<size; k++){
       V[k] = at(k+i);
       }
       return V;
       }
};
