
/**


         (   STACK Data structure Implementation Using Linked List  ) :


      Description :

      This algorithm implements a Stack (Last-In First-Out – LIFO) data structure using a singly linked list.
Each element is stored inside a dynamically allocated node, and the stack grows or shrinks by manipulating the head pointer, which represents the top of the stack.

Key Operations

PUSH(x)
Creates a new node containing value x, inserts it at the head of the linked list, and updates the stack size.

POP()
Removes the topmost node (pointed to by head).
The operation safely deletes the removed node and decreases the size.
If the stack is empty, it prints an error message.

TOP()
Returns the value stored in the top node without removing it.
Throws an exception if the stack is empty.

Length()
Returns the current number of elements in the stack.

display()
Traverses the linked list from head to NULL and prints all stack elements from top to bottom.

Destructor
Automatically frees all dynamically allocated nodes when the stack goes out of scope, preventing memory leaks.





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


    //// ******************  STACK Data structure Implementation Using Linked List *********** ////
     //// ***************** All Operations ****************** ////

     ////1. PUSH(x)
     ////2. POP()
     ////3. TOP()
     ////4. Length()
     ////5. display()

     //// **************************************************************************** ////



    int data ;
    node *next ;


};



 struct Stack {

 private:
     int SZ = 0 ;

 public:

     node *head = NULL ;









     void PUSH ( int val  ) {

         node *new_node = new node ;
         new_node->data = val ;
         new_node->next = head ;
         head = new_node ;
         SZ++;

     }








     void POP ( ) {

         if (head == NULL ){

             cout<<"STACK is empty \n";
             return;

         } else {
             node *first_node = head ;
             head = first_node->next ;
             delete first_node ;

         }
         SZ--;
     }








     int TOP () const {


         if (head == nullptr)
             throw out_of_range("Linked List is empty");
         return head->data;
     }








     int Length ( ) {

         return SZ ;

     }






     void display  ( ) {


         if ( head == NULL ) {

             cout <<"STACK is empty.\n" ;
             return ;
         } else {

             node * current_node = head ;
             while (current_node != NULL ) {

                 cout << current_node->data <<" " ;
                 current_node= current_node->next ;
             }

         }

         cout<<el ;

     }








     ~Stack() {

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


    Stack s ;
    s.PUSH(9);
    s.PUSH(6);  // 7 6 9
    s.PUSH(7);
    s.POP();
    cout<<s.Length() <<el ;
    cout<<s.TOP()<<el ;
    s.display();

    return 0 ;

}




























