/**
    
                 ( Vector Data Structure Implementation (Template-Based) ) :



 Description:

This is a template-based implementation of a dynamic array (vector) in C++, similar to the standard std::vector. It allows storage of elements of any type and provides flexible operations for insertion, deletion, access, and traversal. The class automatically handles memory allocation and resizing to ensure efficient dynamic storage.

Key Features:

Dynamic Resizing: Automatically doubles capacity when the array is full (expand() method).

Element Access: Safe element access with bounds checking using at(idx).

Insertion & Deletion: Supports inserting and deleting elements at any index with automatic element shifting.

Front & Back Access: Retrieve first and last elements via front() and back().

Push & Pop Operations: Add elements to the end with push_back() and remove the last element with pop_back().

Searching: Find the index of a specific element using find(value); returns -1 if not found.

Iterators: Provides begin(), end(), rbegin(), and rend() pointers for traversal.

Memory Management: clear() resets the vector, and the destructor frees allocated memory to prevent leaks.


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



template<typename T>
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
    //find()
    // begin()
    // end()
    // rbegin()
    // rend()
    // Destructor ~Vector() Deletes allocated array to prevent memory leak.
// ********************************************************************************** //

private :

    int sz ;
    int cap ;
    T* arr ;

public :

    Vector() {

        sz = 0 ;
        cap = 10 ;

        arr = new T [ cap ] ;

    }






    int length ( ) {

        return sz ;
    }





    int  capacity ( ) {

        return cap ;
    }









    void push_back (T value ) {

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

        T *tmp = new T [cap] ;

        for (int i = 0; i < sz; ++i) {

            tmp[i] = arr[i] ;
        }

        delete[] arr ;
        arr = tmp ;
    }






    T at (int idx){

        if (idx >= sz )
        {

            throw invalid_argument("Index Should be between 0 and Vector size ") ;
        }

        return  arr[idx] ;

    }






    void insert_at ( int  idx , T val   ) {


        if (idx > sz )
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
        arr =new T [ cap ] ;
    }






    T front()
    const {
        if (sz==0)
            throw out_of_range("empty");
        return arr[0];

    }





    T back()
    const  {

        if (sz==0)
            throw out_of_range("empty");

        return arr[sz-1];

    }





    void pop_back()

    {
        if (sz == 0)

            throw out_of_range("Vector is empty, cannot pop_back");

       // arr[sz-1] = 0 ;
        sz--;
    }



    int find(const T& value) const

    {

        for(int i = 0; i < sz; ++i) {

            if(arr[i] == value)
                return i;

        }

        return -1; // not found

    }




    T* begin() {

        return arr;
    }




    T* end() {

        return arr + sz;

    }



    T* rbegin() {

        return arr + sz - 1;    // pointer to last element
    }




    T* rend() {

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


    Vector<int>v;
    v.push_back(6) ;

    for (int i = 0; i < v.length() ; ++i ) {

        cout<<v.at(i) <<el ;

    }
    v.pop_back();
    cout<<v.length()<<el;
    cout<<v.find(900) <<el ;
    cout<< v.begin() <<el;



    return 0 ;

}





