#ifndef DequeH
#define DequeH
//---------------------------------------------------------------------------

template <class T>
class Deque
{
     public:
     class Node
     {
          public:
          T value;
          Node* prev;
          Node* next;

          Node(T val = 0)
          {
              value = val;
              prev = NULL;
              next = NULL;
          }
     };

     int size;
     Node* front;
     Node* tail;


     Deque()
     {
          front = NULL;
          tail = NULL;
          size = 0;
     }

     void AddFront(T item)
     {
          Node *node = new Node(item);

          if (front != NULL)            // if it's not the first item
               front->next = node;
          else tail = node;

          node->prev = front;
          front = node;

          size += 1;
     }

     void AddTail(T item)
     {
          Node *node = new Node(item);

          if (front != NULL)            // if it's not the first item
               tail->prev = node;
          else front = node;

          node->next = tail;
          tail = node;
          size += 1;
     }

     T RemoveFront()
     {
          if(front != NULL)
          {
               T val = front->value;
               front = front->prev;

               if(size == 1)         //only one item in the deque
                    tail = NULL;
               else front->next = NULL;

               size -= 1;
               return val;
          }
          return NULL;
     }

     T RemoveTail()
     {
          if(front != NULL)
          {
               T val = tail->value;
               tail = tail->next;

               if(size == 1)         //only one item in the deque
                    front = NULL;
               else tail->prev = NULL;

               size -= 1;
               return val;
          }
          return NULL;

     }
        
     int Size()
     {
          return size;
     }
}; 

//---------------------------------------------------------------------------
#endif


//===========================================================================
//The following code snippet is in another head-file.
//Given here for readability:
//===========================================================================

//--------------------*** TEST  ***----------------------

bool Compare (Deque<int>* deque, int* answer, int size_of_answer)
{
     if ( deque->Size() == size_of_answer )
     {
          Deque<int>::Node* node = new Deque<int>::Node();
          node = deque->front;

          for (int i = 0; i < size_of_answer; i++)
          {
               int r = node->value;
               node = node->prev;
               int t = answer[i];
               if(r != t)
                    return false;
          }
          return true;
     }
     else
          return false;
}

int TestDeque ()
{
     int result = 0;
     Deque<int> *deque = new Deque<int>;

     int answer1[] = {4, 3, 2, 1};
     int size_of_answer = sizeof(answer1)/sizeof(answer1[0]);

     //-------- AS A FRONT STACK --------
     deque->AddFront(1);
     deque->AddFront(2);
     deque->AddFront(3);
     deque->AddFront(4);
     result += !Compare(deque, answer1, size_of_answer);

     if (deque->RemoveFront() != 4) result++;
     if (deque->RemoveFront() != 3) result++;
     if (deque->RemoveFront() != 2) result++;
     if (deque->RemoveFront() != 1) result++;

     //-------- AS A TAIL STACK --------
     deque->AddTail(4);
     deque->AddTail(3);
     deque->AddTail(2);
     deque->AddTail(1);
     result += !Compare(deque, answer1, size_of_answer);

     if (deque->RemoveTail() != 1) result++;
     if (deque->RemoveTail() != 2) result++;
     if (deque->RemoveTail() != 3) result++;
     if (deque->RemoveTail() != 4) result++;

     //-------- AS A FRONT QUEUE --------

     deque->AddFront(1);
     deque->AddFront(2);
     deque->AddFront(3);
     deque->AddFront(4);
     if (deque->RemoveTail() != 1) result++;
     if (deque->RemoveTail() != 2) result++;
     if (deque->RemoveTail() != 3) result++;
     if (deque->RemoveTail() != 4) result++;

     //-------- AS A TAIL QUEUE --------
     deque->AddTail(4);
     deque->AddTail(3);
     deque->AddTail(2);
     deque->AddTail(1);
     if (deque->RemoveFront() != 4) result++;
     if (deque->RemoveFront() != 3) result++;
     if (deque->RemoveFront() != 2) result++;
     if (deque->RemoveFront() != 1) result++;

     delete deque;
     return result;
}
//===========================================================================
