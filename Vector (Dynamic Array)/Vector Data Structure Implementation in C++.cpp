/**


   Vector Data Structure Implementation in C++  :


   Overview:
Implemented a dynamic array class in C++ that mimics the behavior of std::vector, supporting core operations like insertion, deletion, resizing, and element access. This project demonstrates a solid understanding of dynamic memory management and fundamental data structure concepts.

Key Features:

push_back() – Add elements to the end of the vector.

pop_back() – Remove the last element.

insert_at(idx, val) – Insert an element at a specific index.

delete_at(idx) – Delete an element at a specific index.

clear() – Remove all elements and reset capacity.

at(idx) – Access elements with bounds checking.

front() / back() – Access the first and last elements.

length() / capacity() – Track current size and storage capacity.

Automatic dynamic resizing when capacity is exceeded.

Destructor ensures safe memory deallocation to prevent memory leaks.





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




   class Vector {

  // ********************************************************************************* //
       // push_back(int value)
       // at(int idx)
       // insert_at(int idx, int val)
       // delete_at(int idx)
       // clear()
       // front()
       // back()
       // pop_back()
       // int length()
       // int capacity()
       // begin()
       // end()
       // rbegin()
       // rend()
       // Destructor ~Vector() Deletes allocated array to prevent memory leak.
// ********************************************************************************** //

   private :

     int sz ;
     int cap ;
     int *arr ;

    public :

     Vector() {

        sz = 0 ;
        cap = 10 ;

        arr = new int [ cap ] ;

    }



     int length ( ) {

         return sz ;
    }

    int  capacity ( ) {

        return cap ;
    }




    void push_back (int value ) {

        if (sz == cap) {

            expand();

        }
        else {

            arr[sz] = value;
            sz++;

        }

    }



        void expand ( ) {

            cap*=2 ;

            int *tmp = new int [cap] ;

            for (int i = 0; i < sz; ++i) {

                tmp[i] = arr[i] ;
            }

            delete[] arr ;
            arr = tmp ;
        }


        int at (int idx){

            if (idx >= sz )
            {

                throw invalid_argument("Index Should be between 0 and Vector size ") ;
            }

            return  arr[idx] ;

    }





      void insert_at ( int  idx , int val   ) {


          if (idx >= sz )
          {
              throw invalid_argument("Index Should be between 0 and Vector size ") ;

          }
          if (sz == cap) {

              expand();

          }
          // Shifting Right //
          for (int i = sz ; i > idx  ; --i) {

              arr[i] = arr[i-1] ;
          }
          arr[idx] = val ;
          sz++ ;

    }





     void  delete_at (int idx ) {

         if (idx >= sz){

             throw invalid_argument("Index Should be between 0 and Vector size ") ;

         }
         // Shifting Left //
         for (int i = idx ; i < sz-1   ; ++i) {

             arr[i] = arr [i+1] ;
         }
         sz-- ;

    }





    // Clear //
    void clear () {

        delete[] arr ;
        sz = 0 ;
        cap = 10 ;
        arr =new int [ cap ] ;
    }





     int front()

     const {
        if (sz==0)
            throw out_of_range("empty");
        return arr[0];

    }




     int back()

     const  {

        if (sz==0)
            throw out_of_range("empty");

        return arr[sz-1];

    }




    void pop_back()

    {
        if (sz == 0) {

            throw out_of_range("Vector is empty, cannot pop_back");

        }

        arr[sz-1] = 0 ;
        sz--;
    }
     
     
    int* begin() {
        
        return arr;
    }

    
    int* end() {
        return arr + sz;
    }

    
    int* rbegin() {

        return arr + size - 1;    // pointer to last element
    }

    

    int* rend() {

        return arr - 1;           // pointer before first element
    }




    ~Vector( void ) {


        delete[] arr ;
    }

 };




int main() {

    FastIO       //   input.txt   output.txt

     freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);


      Vector v ;
      v.push_back(6) ;

    for (int i = 0; i < v.length() ; ++i ) {

        cout<<v.at(i) <<el ;

    }
    v.pop_back();
    cout<<v.length();



    return 0 ;

}




