/**
               
                            Priority Queue Implementation (Array-Based Max-Heap) : 


              Description :
              
 This code implements a Priority Queue using an array-based Max-Heap, where the highest value always has the highest priority.
The heap is stored in a dynamic array (vector<int>), and the structure maintains the max-heap property:

Every parent node is greater than or equal to its children.

The priority queue supports efficient insertion, removal of the maximum element, and priority retrieval.
It uses Shift-Up to insert new nodes in O(log N) and Shift-Down (heapify) after deletion in O(log N).
The memory footprint is minimal, using only a dynamic vector with no additional structures.

This implementation achieves:

Insertion: O(log N)

Deletion (pop max): O(log N)

Get Maximum: O(1)

Space Complexity: O(N)


  ✅ Summary of All Operations:


1. PUSH_NODE(int x) — Insert element (Shift-Up)

Adds a new element at the end of the array.

Shifts it upward until the max-heap property is restored.

Time Complexity: O(log N)

What it does: Ensures the inserted element reaches its correct position.




2. POP_NODE() — Remove the maximum (Shift-Down)

Swaps the root (max) with the last element.

Removes the last element.

Calls heapify(0) to restore heap order.

Time Complexity: O(log N)

What it does: Always removes the highest-priority value.





3. TOP() — Get maximum element

Returns the root of the heap (v[0]).

Time Complexity: O(1)

What it does: Provides instant access to the highest-priority value.

4. GET_SIZE() — Number of elements

Returns SIZE.

Time Complexity: O(1)





5. IS_EMPTY() — Check if PQ is empty

Returns true if SIZE == 0

Time Complexity: O(1)




6. ~Priority_Queue() — Destructor

Clears the vector.

Ensures clean memory deallocation.



7. heapify(int i) — Internal (Shift-Down)

Ensures max-heap property from index i downward.

Used only by deletion.

Time Complexity: O(log N)




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



     struct Priority_Queue  {

         ////  ******************************** All Operations ********************************** ////

         //// 1.PUSH_NODE(int x) — Insert element (Shift-Up)
         //// 2.POP_NODE() — Remove the maximum (Shift-Down)
         //// 3.TOP() — Get maximum element
         //// 4.GET_SIZE() — Number of elements
         //// 5.IS_EMPTY() — Check if PQ is empty
         //// 6.~Priority_Queue() — Destructor : Clears the vector.
         //// 7.heapify(int i) — Internal (Shift-Down)
         
         //// ****************************************************************************************//// 
         
         
     private:

         int SIZE = 0;
         vector< int > v ;


         void heapify(int i) {   // Shift Down //

             int left = 2 * i + 1;

             int right = 2 * i + 2;

             int maxi = i;

             if (left < SIZE and v[left] > v[maxi]) {

                 maxi = left;
             }

             if (right < SIZE and v[right] > v[maxi]) {

                 maxi = right;
             }


             if (maxi != i) {

                 swap(v[i], v[maxi]);

                 heapify(maxi);
             }

         }







     public:






         void PUSH_NODE ( int x ) {

             v.push_back(x); // add at the end

             SIZE++;            // increase heap size

             // build ( ) Shift Down : Time O(N)/2  or

             // Shift UP :  O(log(N)) //

             int i = SIZE - 1;
             while (i != 0 && v[(i - 1) / 2] < v[i]) {

                 swap(v[i], v[(i - 1) / 2]);

                 i = (i - 1) / 2;

             }

         }








         void POP_NODE( ) {

             if (SIZE == 0) {
                 cout << "Priority_Queue is empty!\n";
                 // or throw error
             }

             swap(v[0], v[SIZE - 1]);     // move last element to root

             v.pop_back();            // remove last

             SIZE--;

             heapify(0);    // restore heap property


         }








         int GET_SIZE( ) {

             return SIZE;

         }







         int TOP ( ){

             if (SIZE == 0) {

                 throw runtime_error("Priority_Queue is empty!");

             }

             return v[0] ;

         }







         bool IS_EMPTY ( ) {

             if ( GET_SIZE() == 0  ) {

                 return true;

             } else {

                     return false  ;
             }

         }




         ~Priority_Queue() {

             v.clear() ;


         }





     } ;






 //  void getAnswer ( ) {

   //       cin >> SIZE ;
     //   v = vector<int >(SIZE) ;

       // for (auto &it : v ) {

         //   cin >> it ;
        //}

        //build ( ) ;

        //for (int i = 0; i < SIZE  ; ++i) {

          //  cout<<v[i] <<"\SIZE" ;
        //} cout <<el ;

        // heapsort( ) ;

    // }






int main() {


         ////   100 60 110 70 80 130 105   ////


    FastIO       //   input.txt   output.txt

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    Priority_Queue s ;
    s.PUSH_NODE(100) ;
    s.PUSH_NODE(60) ;
    s.PUSH_NODE(110) ;
    s.PUSH_NODE(70 ) ;
    s.PUSH_NODE(80) ;
    s.PUSH_NODE(130) ;
    s.PUSH_NODE(105) ;


    cout<<s.IS_EMPTY()<<el ;




    return 0 ;

}


