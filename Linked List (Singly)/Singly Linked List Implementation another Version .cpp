/**
       
              Singly Linked List Data Structure  Implementation another Version :


  Algorithm Description:

A complete implementation of a singly linked list supporting all fundamental operations including:

insertion (front, back, index)

deletion (front, back, index, by value)

search

traversal

random access (via linear traversal)

clearing

iterator-like begin/end

size tracking


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





struct  node {

    // ****************************************************************************** //
    //         ***************             All Operations        *************                //
    //1. Push_back(value)
    //2. Push_front(value)
    //3. Pop_front()
    //4. Pop_back()
    //5. insert_at(index, value)
    //6. delete_at(index)
    //7. erase_node(value)
    //8. find(value)
    //9. at(index)
    // 10. front()
    //11. back()
    //12. display()
    //13. begin()
    //14. end()
    //15. Length()
    //16. Clear()

// ************************************************************************************** //









        int data ;
        node *next ;

    };



    struct linked_list {

    private:
        int SZ = 0 ;

    public:

        node *head = NULL ;





        void Push_back( int value ) {

            node *newnode , *last  ;
            newnode = new node  ;
            newnode->data = value ;
            if (head == NULL ){

                head = newnode ;
                newnode->next = NULL ;

            } else {

                last = head ;
                while ( last->next != NULL ) {
                    last = last->next ;

                }
                last->next = newnode ;
                newnode->next = NULL ;

            }
            SZ++;
        }







        void display  ( ) {


            if ( head == NULL ) {

                cout <<"Linked List is empty.\n" ;
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





        void erase_node (  int value  ) {


            if (head == NULL ) {

                cout << "Linked List is empty.\n";
                return;
            }

            node *current , *previous ;
            current = head ;
            previous = head ;

            if ( current->data == value  ) {

                head= current->next ;
                delete current ;
                SZ--;
                return ;

            }

            while ( current!= NULL && current->data != value ) {

                previous = current ;
                current = current->next ;

            }

            // Value not found

            if (current == NULL) {

                cout << "Value not found in list.\n";
                return;
            }

            previous->next = current->next ;
            delete current ;

            SZ--;

        }







        void Push_front ( int val  ) {

            node *new_node = new node ;
            new_node->data = val ;
            new_node->next = head ;
            head = new_node ;
            SZ++;

        }






        void Pop_front ( ) {

            if (head == NULL ){

               cout<<"LINKED List is empty \n";
                return;

            } else {
                node *first_node = head ;
                head = first_node->next ;
                delete first_node ;

            }
            SZ--;
        }








        void Pop_back ( ) {

            if (head == NULL ){

                cout <<"Linked List is empty \n" ;
                return;
            }

            else if (head->next == NULL ){

                delete head ;
                head = NULL ;
                SZ-- ;
                return;
            }

            else {

                node *current , *previous ;
                current = head ;
                previous = head ;

                while ( current->next != NULL ) {

                    previous = current ;
                    current = current->next ;

                }
                previous->next = NULL ;
                delete current ;
                SZ-- ;
            }


        }







        int front() const {


            if (head == nullptr)
                throw out_of_range("Linked List is empty");
            return head->data;
        }






        int back() const {
            if (head == nullptr)
                throw out_of_range("Linked List is empty");

            node *curr = head;
            while (curr->next != nullptr) curr = curr->next;
            return curr->data;
        }






        node* begin() {

            return head;
        }




        node* end() {
            return nullptr;  // same as C++ STL convention
        }







        int Length ( ) {

            return SZ ;

        }








        void Clear ( ) {

            while (SZ > 0) {
                Pop_front();
            }

        }








        int at(int index ) {


            // Check for invalid index
            if (index < 0 || index >= SZ) {

                throw out_of_range("Index out of range");
            }

            node *curr = head ;
            for (int i = 0; i < index ; ++i) {

                curr = curr->next ;

            }
            return  curr->data ;

        }










        void insert_at ( int index , int value ) {

            if (index < 0 || index > SZ )
            {
                cout << " Index should be between 0 and Size \n " ;
                return ;
            }

            if (index == 0 ) {

                Push_front(value ) ;
                return;
            }

            if (index ==  SZ ) {

                Push_back( value ) ;
                return ;
            }

            else {

              node *new_node = new node ;
              node *cur = head ;

                for (int i = 0; i < index-1 ; ++i) {

                    cur = cur->next ;

                }

                new_node->next = cur->next ;

                cur->next = new_node ;
                SZ++ ;

            }


        }










        void delete_at ( int index  ){


            if (index < 0 || index >= SZ ){

                cout <<"Index should be between 0 and Size - 1 \n" ;
                return ;
            }

            if ( index == 0 ) {

            Pop_front() ;
                return ;

            }

            if (index == SZ-1 ){

                Pop_back( ) ;
                return ;
            }

            else {

                node *previous_ele ;
                previous_ele = head ;

                for (int i = 0; i < index - 1 ; ++i) {

                    previous_ele = previous_ele->next;

                }

                node *curr = previous_ele->next ;
                previous_ele->next = curr->next ;
                delete curr ;

                SZ-- ;
            }

        }







        int find(int value) {

            node* curr = head;
            int index = 0;

            while (curr != nullptr) {

                if ( curr->data == value ) {

                    return index;  // Found
                }

                curr = curr->next;
                index++;
            }

            return -1;  // Not found
        }




        ~linked_list() {

            Clear();   // You already have a proper Clear() function

        }





        // void sort_easy ( ) {

          //  Vector v ;
           // node *curr_elem = head ;

           //   while (curr_elem != NULL ){


                //  v.push_back(curr_elem->data ) ;
                //  curr_elem =curr_elem->next ;
             // }

             // sort(v.begin() , v.end() ) ;

             // curr_elem = head ;
             // int idx = 0 ;
             // while (curr_elem != NULL ){

              //    curr_elem->data = v.at(idx++) ;
               //   curr_elem =curr_elem->next ;

             // }
       // }




    };




int main() {

    FastIO       //   input.txt   output.txt

     freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);

      linked_list l;
      l.Push_back(9) ;
      l.Push_back(8);
      l.Push_front(7);
      cout<<l.Length()<<el;
      l.Clear() ;
      cout<<l.Length()<<el ;

      l.delete_at(5);

      // node* it = l.begin(); or // auto it = l.begin();
    for ( node* it = l.begin(); it != l.end(); it = it->next) {

        cout << it->data << " " ;

    }



    return 0 ;

}





