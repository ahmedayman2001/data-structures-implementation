/**


    Singly Linked List Implementation  :

 ✅ Description

This code implements a dynamic singly linked list data structure using a custom Node class and a linked_list class.
The linked list stores integers, and each node contains a value and a pointer to the next node.

The linked_list class supports operations to:

Insert elements at the beginning, end, or any index

Delete nodes

Access elements by index

Print the list

Clear all elements

Track the current size of the list

This implementation manually manages memory using new and delete.


 ✅All Operations:

  🔹 1. append(int val)
   🔹 2. length()
   🔹 3. element_at(int idx)
   🔹 4. insert_at(int idx, int val)
   🔹 5. delete_at(int idx)
   🔹 6. clear()
   🔹 7. print()
   🔹 8. Destructor ~linked_list()

Automatically calls clear() to free all memory before the object is destroyed.


       ( ALGORITHM : )

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

  class Node {

  public:
      int value ;
      Node *nxt ;

      Node () {

          value = 0 ;
          nxt = nullptr ;


      }
      Node(int val ) {

          value = val ;
          nxt = nullptr ;
      }

  };



  class linked_list {

  private:

         Node *head , *tail ;

         int sz ;
  public:

      linked_list (){

          sz = 0 ;
          head = tail = nullptr ;

      }




      int length( ) {

          return  sz ;
      }



       void append (int val  )  {

           Node *tmp = new Node(val);

           if (sz == 0 )
           {
               head = tail = tmp ;

           } else {

               tail->nxt = tmp ;
               tail = tmp ;

           }
        sz++ ;

      }




      int element_at (int idx ) {


          if (idx >= sz )
          {

              throw invalid_argument("index should be between 0 and Size-1\n") ;
          }

          Node *tmp = head ;
          for (int i = 0; i < idx ; ++i) {

              tmp = tmp->nxt ;

          }
          return  tmp->value ;
      }







      void insert_at (int idx , int val) {


          if (idx < 0 || idx > sz) {

              throw invalid_argument("index should be between 0 and Size\n");
          }


          Node* newnode = new Node(val);



          // insert at empty list
          if (sz == 0) {
              head = tail = newnode;
          }



              // insert at the beginning
          else if (idx == 0) {

              newnode->nxt = head;
              head = newnode;
          }


              // insert at the end
          else if (idx == sz) {

              tail->nxt = newnode;

              tail = newnode;
          }


              // insert in the middle
          else {

              Node* tmp = head;

              for (int i = 0; i < idx - 1; i++) {

                  tmp = tmp->nxt;
              }

              newnode->nxt = tmp->nxt;

              tmp->nxt = newnode;
          }

          sz++;
      }








      void delete_at ( int idx ){


          if (idx >= sz ){

             throw invalid_argument("index should be between 0 and Size-1\n") ;

          }
          Node *tmp = head ;
          if (idx == 0 ){



              head = head->nxt ;
              delete tmp ;

          } else {

              for (int i = 0; i < idx - 1; ++i) {
                  tmp = tmp->nxt;

              }
              Node *tobedeleted = tmp->nxt;
              tmp->nxt = tobedeleted->nxt;
              delete tobedeleted;
              if (idx+1 == sz ) {

                  tail = tmp ;

              }

          }
          sz-- ;
      }







      void clear ( )
      {

          while (sz > 0 ) {

              delete_at(0) ;

          }

      }



      void print() {

          Node* tmp = head;

          while (tmp) {

              cout << tmp->value << " ";
              tmp = tmp->nxt;
          }

          cout << "\n";

      }





      ~linked_list()
      {
          clear() ;

      }

  };





int main() {

    FastIO       //   input.txt   output.txt

     freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);


      linked_list l  ;

      l.append(9);
      l.append(0) ;

      cout<<l.element_at(3)<<el ;


    return 0 ;

}




