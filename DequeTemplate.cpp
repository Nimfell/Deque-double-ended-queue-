#include <stdio.h>

class Deque
{
    public:
     class Node
     {
          public:
          int value;
          Node* prev;
          Node* next;

          Node(int val = 0)
          {
              value = val;
              prev = NULL;
              next = NULL;
          }
     };

     int Size;
     Node* front;
     Node* tail;

     Deque()
     {
          front = NULL;
          tail = NULL;
          Size = 0;
     }

     void add_front(int item)
     {
          Node* node = new Node(item);

          if (front != NULL)            // if it's not the first item
               front->next = node;
          else tail = node;

          node->prev = front;
          front = node;

          Size += 1;
     }

     void add_tail(int item)
     {
          Node* node = new Node(item);

          if (front != NULL)            // if it's not the first item
               tail->prev = node;
          else front = node;

          node->next = tail;
          tail = node;
          Size += 1;
     }

     int remove_front()
     {
          if(front != NULL)
          {
               int val = front->value;
               front = front->prev;

               if(Size == 1)         //only one item in the deque
                    tail = NULL;
               else front->next = NULL;

               Size -= 1;
               return val;
          }
          return -1;  // if empty
     }

     int remove_tail()
     {
          if(front != NULL)
          {
               int val = tail->value;
               tail = tail->next;

               if(Size == 1)         //only one item in the deque
                    front = NULL;
               else tail->prev = NULL;

               Size -= 1;
               return val;
          }
          return -1; // if empty
     }

     int size()
     {
          return Size;
     }
};

