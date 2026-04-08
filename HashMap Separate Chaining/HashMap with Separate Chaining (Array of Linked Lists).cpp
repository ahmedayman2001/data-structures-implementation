
/**
                          
               ( HashMap with Separate Chaining (Array of Linked Lists )  ) : 



      Description

This is a hash table (hash map) implementation in C++ that uses linked lists for collision handling (separate chaining). Each bucket of the hash table contains a LinkedList of nodes storing key-value pairs.

It supports dynamic insertion, deletion, retrieval, and lookup of key-value pairs, as well as operations like clearing all data and printing in sorted order. The hash function is a polynomial rolling hash for strings.

This structure is similar in concept to the standard C++ unordered_map, but is implemented from scratch for educational purposes and demonstrates how hash tables work internally.


Key Components :


  1. Node (node)

Stores a Key (string) and value (int).

Points to the next node in the linked list.



2. LinkedList (LinkedList)

Stores multiple nodes in a single bucket.

Supports:

insert(key, value) — insert at head.

remove(key) — remove a node by key.

getvalue(key) — get reference to value (creates node if not present).

contains(key) — check existence of key.

clear() — remove all nodes.

get_size() — number of nodes in the list.

print() — prints all nodes in the list.




3. HashMap (HashMap)

An array of LinkedLists.

Handles collisions via separate chaining.

Uses a polynomial rolling hash for strings to compute bucket indices.

Supports operations:

insert(key, value) — add or update a key-value pair.

remove(key) — delete a key-value pair.

contains(key) — check if a key exists.

get_value(key) — get reference to value of a key.

clear() — remove all key-value pairs.

get_size() — total number of key-value pairs.

get_capacity() — number of buckets.

print() — print all key-value pairs in insertion order.

print_sorted() — print all key-value pairs sorted by key.




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

        //// *******************************  All Operations  *********************************** ////

        //// 1. insert(key, value)
        //// 2. remove(key)
        //// 3. contains(key)
        //// 4. get_value(key)
        //// 5. clear()
        //// 6. get_size()
        //// 7. get_capacity()
        //// 8. print()
        //// 9. print_sorted() 
        
        //// ************************************************************************************ ////
        

        string Key ;
        int value ;
        node *next = nullptr ;
        node (string s , int v ) {

            Key = s ;
            value = v ;

        }


    };



    class LinkedList {


        int size = 0 ;

    public:
        node *head = nullptr ;
        node *tail = nullptr ;







        void insert (string key , int value ){

            node *tmp = new node (key , value ) ;
            if (size == 0 ){

                head = tail = tmp ;

            } else {


                tmp->next = head ;
                head = tmp ;
            }

            size++ ;

        }







        void remove(string s) {

            if (!head) return;

            node* curr = head;
            node* prev = nullptr;

            while (curr && curr->Key != s) {
                prev = curr;
                curr = curr->next;
            }

            if (!curr) return; // not found

            if (!prev) {
                head = head->next;
            } else {

                prev->next = curr->next;
            }

            if (curr == tail) {

                tail = prev;   // update tail if last node removed
            }

            delete curr;
            size--;
        }








        int& getvalue(string s) {

            node* tmp = head;

            while (tmp) {

                if (tmp->Key == s)  return tmp->value ;

                tmp = tmp->next;

            }

            // key not found, insert at head

            node* n = new node(s, 0);
            n->next = head;
            head = n;
            if (!tail) tail = n;
            size++;
            return n->value;
        }








        bool contains ( string s ){


            node *tmp = head ;
            while (tmp != nullptr && tmp->Key != s ){

                tmp= tmp->next ;

            }
            if (tmp != nullptr ){


                return true ;

            } else {

                return false ;

            }


        }








        void clear ( ){


            while ( size > 0){


                remove(head->Key );

            }


        }







        int get_size ( ){


            return size ;
        }








        void print( ){

            node *curr_elem = head ;
            while (curr_elem != nullptr ){


                cout<<curr_elem->Key<<" : "<<curr_elem->value ;
                curr_elem = curr_elem->next ;
            }
            cout<<endl ;

        }






    };







      class HashMap {

          LinkedList *data = nullptr ;
          int size  = 0 ;
          int capacity = 0 ;


      public:


          HashMap ( int c ){


              capacity = c ;
              data = new  LinkedList[c] ;

          }








          int hashing(const string& s) {

              unsigned long long hash = 0;

              for (char c : s) hash = hash * 31 + c; // classic polynomial rolling hash

              return hash % capacity;
          }









          void insert (string key , int val ) {

              int index = hashing(key);

              if (data[index].contains(key)) {

                  data[index].getvalue(key) = val; // update existing

              } else {

                  data[index].insert(key, val);

                  size++;
              }

          }








          void remove ( string key ){


              int index = hashing( key) ;

              if (data[index].contains(key)) {

                  data[index].remove(key);
                  size--;

              }
          }








          int get_size ( ) {

              return size ;

          }







          int get_capacity ( ) {

              return capacity ;

          }







          bool contains( string key ){

              int index = hashing(key) ;

             return data[index].contains(key) ;

          }







          void clear ( ){

              for (int i = 0; i < capacity ; ++i) {

                  data[i].clear() ;

              }
              size = 0 ;


          }








           int &get_value ( string key ) {



              int index = hashing(key) ;

               return data[index].getvalue(key) ;

          }








          void print ( ){

              for (int i = 0; i < capacity; ++i) {

                  if (data[i].get_size() > 0 ){

                      data[i].print() ;

                  }

              }
              cout<<endl ;

          }










          void print_sorted() {

              vector<pair<string, int>> vec;

              // Collect all key-value pairs

              for (int i = 0; i < capacity; ++i) {

                  node* curr = data[i].head; // you need to make 'head' public or add a getter

                  while (curr) {

                      vec.push_back({curr->Key, curr->value});

                      curr = curr->next;

                  }
              }



              // Sort alphabetically by key

              sort(vec.begin(), vec.end(), [](const pair<string,int>& a, const pair<string,int>& b){
                  return a.first < b.first;

              });

              // Print sorted key-value pairs
              for (auto &p : vec) {
                  cout << p.first << " : " << p.second << endl;
              }
              cout<<endl ;
          }










          ~HashMap() {

              delete[]data ;

          }



      };






int main() {

    FastIO       //   input.txt   output.txt

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    HashMap h(7) ;


    h.insert("Ahmed" , 1) ;
    h.insert("Mahmoud", 9) ;
    h.insert("Adel" , 100) ;
    h.print_sorted();
    h.print();


////   ***********************      Frequency Map     ***************************************  ////

 //// HashMap freqMap(100); // create hash map with enough buckets

   //// vector<string> words = {"apple", "banana", "apple", "orange", //"banana", "apple"};

  ////  for (auto &word : words) {
    ////    freqMap.get_value(word)++; // increment frequency
   //// }

    //// cout << "Frequency map (sorted by key):\n";
     ////  freqMap.print_sorted();

    ////  cout << "\nFrequency map (unsorted, by insertion in buckets):\n";
    ////  freqMap.print();


    return 0 ;

}













