/**
            (  QUEUE Data Structure  Implementation Using Linked List ) :


        /********************************************************************************************
 *  Queue Data Structure (Linked List Implementation)
 *
 *  Description:
 *  This implementation provides a dynamic Queue using a singly linked list. 
 *  It supports all fundamental queue operations in O(1) time, including:
 *
 *      • PUSH(value)   → Enqueue: Insert an element at the rear of the queue
 *      • POP()         → Dequeue: Remove an element from the front
 *      • FRONT()       → Retrieve the front element without removing it
 *      • BACK()        → Retrieve the rear element without removing it
 *      • LENGTH()      → Return the current number of elements
 *      • DISPLAY()     → Print all elements from front to back
 *
 *  Properties:
 *      - FIFO (First In → First Out) behavior
 *      - Dynamic memory allocation (no size limit)
 *      - Uses two pointers: head (front) and tail (rear)
 *      - All operations run in constant time O(1)
 *
 *  Additional Notes:
 *      - A destructor (~Queue) is implemented to free all allocated memory
 *      - Exception handling is used for empty queue access
 *
 ********************************************************************************************/




  ( Algorithm ) : 

**/

        
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;


   struct node {

       //// ************* QUEUE Data Structure  Implementation Using Linked List  **********  /////
       ///// *************************** ALL OPERATIONS ********************** /////

       ///// 1. PUSH()
       ///// 2. POP()
       ///// 3. FRONT()
       ///// 4. BACK()
       ///// 5. LENGTH()
       ///// 6. DISPLAY()

       //// ******************************************************************** ////

       int data ;
       node *next ;


   };


   struct Queue {

   private:
       int SIZE = 0 ;

   public:
       node *head = NULL  ;
       node *tail = NULL ;







       void PUSH (int value ) {

            node *new_node = new node ;
            new_node->data = value ;
            new_node->next = NULL ;

           if (head == NULL ) {

               head = tail = new_node ;


           } else {

               tail->next = new_node ;
               tail = new_node ;

           }
           SIZE++ ;


       }








       void POP ( ) {

           if (tail == NULL || head == NULL ){

               cout <<"QUEUE IS EMPTY \n" ;
               return ;

           } else if ( head == tail ){

               node *curr  = head ;
               head = tail = NULL;
               delete curr ;
               SIZE-- ;

           } else {

               node *cur = head ;
               head = head->next ;
               delete cur ;
               SIZE-- ;

           }

       }






       int FRONT ( ){

           if (head == NULL ) {

               throw invalid_argument(" QUEUE IS EMPTY \n ") ;

           } else {

               return head->data ;


           }

       }






         int BACK ( ) {

           if ( tail == NULL ) {

               throw invalid_argument(" QUEUE IS EMPTY \n ") ;


           } else {

              return tail->data ;

           }

       }







       int LENGTH ( ) {

           return SIZE ;

       }







       void  DISPLAY ( ) {


           if (head == NULL ){

               cout <<" QUEUE IS EMPTY \n " ;
               return ;
           } else {

               node * curr_elem = head ;

               while (curr_elem != NULL ){


                   cout << curr_elem->data<<" " ;
                   curr_elem = curr_elem->next ;
               }
               cout<<endl;

           }

       }







       ~Queue() {

           node* curr = head;
           node* prev ;

           while (curr != NULL ) {
               prev = curr ;
               curr = curr->next ;
               delete prev ;

           }
       }


   };




int main() {


    FastIO       //   input.txt   output.txt

     freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);

      Queue Q ;
      Q.PUSH(9) ;
      Q.PUSH(100) ;
      Q.PUSH(80);
      Q.DISPLAY() ;
      Q.POP() ;
      Q.DISPLAY();
      cout<< Q.LENGTH() <<" "<<Q.BACK()<<" "<<Q.FRONT() << endl ;



    return 0 ;

}















