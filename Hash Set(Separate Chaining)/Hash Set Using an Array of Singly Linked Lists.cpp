/**


        ( Hash Set Using an Array of Singly Linked Lists ): 


   ✅ Description

This data structure is a Hash Set implemented using an array of Singly Linked Lists.
It uses separate chaining to resolve collisions: each index of the array represents a bucket, and every bucket is managed by a singly linked list that stores all elements that hash to that index.

The structure guarantees unique elements, supports fast average-time operations, and handles collisions efficiently.


   ✅ Summary of All Operations
1. insert(int val)

Adds a value if it does not already exist.

Compute the hash index.

Check if the value is inside the bucket.

If not present, append it to the linked list.

Increase total size.

Time Complexity:

Average: O(1)

Worst: O(n) (if many elements in same list)

2. remove(int val)

Deletes a value from its corresponding bucket.

Compute hash index.

Search inside bucket’s linked list.

If found, remove it and decrease size.

Time Complexity:

Average: O(1)

Worst: O(n)

3. contains(int val)

Checks whether a value exists in the set.

Time Complexity:

Average: O(1)

Worst: O(n)

4. clear()

Removes all elements from the hash set by clearing each linked list.

Time Complexity: O(n)

5. print()

Prints all non-empty buckets of the hash table.

Time Complexity: O(n)

6. get_size()

Returns the total number of elements stored.

Time Complexity: O(1)

7. get_capacity()

Returns the total number of buckets.

Time Complexity: O(1)

Destructor

Releases the array of linked lists to avoid memory leaks.



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

         ////******************************** All Operations ************************************************** ////
        
        //// 1. insert(int val)
        //// 2. remove(int val)
        //// 3. contains(int val)
        //// 4. clear()
        //// 5. print()
        //// 6. get_size()
        //// 7. get_capacity()
        //// 8. print_sorted()
 
        //// ****************************************************************************************************////





         int value ;
    node *next = nullptr ;

    node(int val) {

        value = val ;


    }

  };



   class  linkedlist {

    int size = 0 ;
   
   public:

 node *head = nullptr ;
    node *tail = nullptr ;


    void insert (int val ) {


        node *tmp = new node ( val ) ;

        if (size == 0 ) {

            head = tail = tmp ;

        } else {


            tail->next = tmp ;
            tail = tmp ;


        }
        size++;
    }








    void remove (int val ){


        if (size > 0 )
        {
            if (head->value == val )
            {
                node *tmp = head ;
                head = head->next ;
                delete tmp ;
                size-- ;

            } else

            {
                node *prev = head ;
                node *curr = head->next ;
                while (curr!= nullptr && curr->value != val ){

                    prev = curr ;
                    curr = curr->next ;

                }

                if (curr != nullptr ) {

                    prev->next = curr->next;
                    delete curr;
                    size--;

                }

            }
        }
    }






    int get_size ( ){

        return  size ;

    }




    void clear ( ) {

        while (size ) {

            remove(head->value) ;

        }

    }






    bool contains ( int val ){


        node *tmp = head ;
        while (tmp != nullptr  ){

            if (tmp->value == val )
                return true ;
            tmp = tmp->next ;
        }
        return false ;

    }




    void print ( ){

        node *tmp = head ;
        while (tmp != nullptr ){

            cout<<tmp->value <<" " ;
            tmp = tmp->next ;

        }

        cout<<el ;

    }





};








    class HashSet {

    linkedlist *data = nullptr ;
    int capacity =  0 ;
    int size = 0 ;

 public:
    HashSet(int c ) {

        capacity = c ;
        data = new linkedlist [c] ;

    }






    int hash (int val  ){


        return (val % capacity + capacity ) % capacity ; // positive or negative number //

    }





    void insert (int val  ){

        int index = hash( val ) ;

        if (!data[index].contains(val)) { // prevent duplicates

            data[index].insert(val);

            size++;
        }

    }






    void remove (int val ) {

        int idx = hash(val) ;
        if (data[idx].contains(val)) { // remove only if exists

            data[idx].remove(val);

            size--;
        }
    }






    bool contains (int val ) {

        int idx = hash(val) ;

        return  data[idx].contains(val) ;

    }






    int get_size ( ){

        return size ;
    }





    int get_capcity( ) {

        return capacity ;

    }






    void clear ( ){

        for (int i = 0; i < capacity ; ++i) {

            data[i].clear() ;

        }
        size = 0 ;
        // capacity = 0 ;

    }






    void print() {

        for (int i = 0; i < capacity; i++) {

            if ( data[i].get_size() > 0 ) {

                data[i].print();
            }
        }
    }

    void print_sorted() {

    vector<int> vec;

    // Collect all elements from all buckets

    for (int i = 0; i < capacity; ++i) {

        linkedlist &lst = data[i];

        node* curr = lst.head; // make head public or add a getter in linkedlist

        while (curr) {

            vec.push_back(curr->value);

            curr = curr->next;

        }
    }

    // Sort the vector

    sort(vec.begin(), vec.end());

    // Print sorted elements

    for (int val : vec) {


        cout << val << " ";
    }

    cout << el;
}







    ~HashSet(){

        delete[] data;

    }




};






int main() {

    FastIO       //   input.txt   output.txt

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);


    HashSet s(100) ;

    s.insert(1);
    s.insert(7);
    s.insert(2);
    s.insert(0);
    s.print() ;
    cout <<s.get_capcity()<<"\n";




    return 0 ;

}





