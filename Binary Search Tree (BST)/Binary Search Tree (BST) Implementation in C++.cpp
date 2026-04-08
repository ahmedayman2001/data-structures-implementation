/**
                 

                ( Dynamic Binary Search Tree (BST) Implementation in C++ ) :

      

             Description:
         
This implementation provides a fully-functional Binary Search Tree (BST) in C++ using dynamically allocated nodes. Each node contains an integer value and pointers to its left and right children. The BST maintains the binary search tree property:

Left subtree: All nodes have values less than the parent node.

Right subtree: All nodes have values greater than the parent node.

The implementation supports all standard operations including insertion, deletion, search, traversal, finding minimum and maximum values, and memory management through tree clearing.

This design ensures:

Efficient data organization for quick search, insertion, and deletion.

Automatic memory management with proper destructors.

Sorted data retrieval via in-order traversal.

Correct handling of all deletion scenarios: leaf nodes, single child, and nodes with two children.



   Class Structure
Node Class

Attributes:

int data — Value stored in the node.

Node* left — Pointer to the left child.

Node* right — Pointer to the right child.

Constructor initializes the node with a value and null child pointers.

Binary_Search_Tree Class

Attributes:

Node* root — Pointer to the root node.

int Size — Tracks the number of nodes in the tree.

Provides public methods to interact with the BST and private helper functions for recursive operations.




  Operations Provided:

         | Operation                | Method                  | Description                                                                                                                                   |
| ------------------------ | ----------------------- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| **Insert**               | Insert(int item)      | Adds a new value while maintaining BST property. Increments tree size.                                                                        |
| **Search**               | Search(int key)       | Returns `true` if the key exists, otherwise `false`.                                                                                          |
| **Delete**               | Delete_Node(int item) | Removes a node. Handles leaf nodes, nodes with one child, and nodes with two children (replaces with max from left subtree).  
                                                        Decrements size.
                                                                 	
| **Pre-Order Traversal**  | Pre_Order(Node* r)    | Root → Left → Right. Useful for copying the tree structure.                                                                                   |
| **In-Order Traversal**   | In_Order(Node* r)     | Left → Root → Right. Returns sorted sequence of elements.                                                                                     |
| **Post-Order Traversal** | Post_Order(Node* r)   | Left → Right → Root. Useful for deleting the tree.                                                                                            |
| **Find Minimum**         | Find_Min()          | Returns the smallest value in the BST.                                                                                                        |
| **Find Maximum**         | Find_Max()            | Returns the largest value in the BST.                                                                                                         |
| **Get Size**             | Get_Size()            | Returns the number of nodes in the tree.                                                                                                      |
| **Clear Tree**           | Clear_BST()           | Deletes all nodes, frees memory, and resets size.                                                                                             |


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

    class Node {


       //// ************************************* All Operations **************************************** ////

      //// 1. Insert(int item)
      //// 2. Search(int key)
      //// 3. Delete_Node(int item)
      //// 4. Pre_Order(Node* r)
      //// 5. In_Order(Node* r)
      //// 6. Post_Order(Node* r)
      //// 7. Find_Min()
      //// 8. Find_Max()
      //// 9. Get_Size()
      //// 10. Clear_BST()  

      //// *******************************************************************************************////
      


    public:

        int data ;
        Node *left , *right ;

        Node (int x ){

            data = x ;
            left = right = NULL ;

        }


    };



    class Binary_Search_Tree {


    public:

        Node *root ;

        Binary_Search_Tree ( ){

            root = NULL ;

        }



    private:


        int Size = 0 ;




        Node *Insert(Node *r , int item ) {


            if (r == NULL ){

                Size++ ;

               Node *new_node = new Node(item) ;

                r = new_node ;


            }

              else if ( item < r->data  ) {


                r->left =  Insert(r->left , item ) ;

            }

              else {

               r->right =  Insert(r->right , item ) ;

            }


            return  r ; // after end function : backtrack then return  r == root address //

        }








        Node *Search (Node *r , int item ){


            if (r == NULL ) {

                return NULL;
            }


            else if ( item == r->data ){

                return r ;

            }

               else if (item < r->data ) {


                return Search(r->left , item ) ;
            }
               else {


                return Search( r->right , item ) ;
            }


        }








        Node *Find_Min ( Node * r ) {


            if (r == NULL ) {

                return NULL;
            }

            while (r->left != NULL ){

                r = r->left ;

            }

            return  r ;

        }








        Node *Find_Max ( Node *r ){

            if (r == NULL ) {

                return NULL;
            }


            while (r->right != NULL ) {

                r = r->right ;
            }

            return r ;

        }






        Node *Delete ( Node *r , int key ) {

            if (r == NULL ) { //// Empty Tree ///

                return NULL;
            }

            if ( key < r->data )     //// Item exists in left sub tree ////

               r->left =  Delete(r->left , key ) ;

            else if (key > r->data )     //// Item exists in right sub tree ////

                r->right = Delete(r->right , key ) ;


            else {


                if (r->left == NULL && r->right == NULL ) {     //// Leaf Node ////

                    Size-- ;

                    r = NULL ;


                }


                else if (  r->left != NULL && r->right == NULL ){  ////  One Child on the Left  ////

                    r->data= r->left->data ;

                    delete r->left ;

                    Size-- ;

                  r->left = NULL ;

                }


                else if ( r->left == NULL && r->right != NULL ) {  //// One Child on the Right ////

                    r->data= r->right->data ;

                    delete r->right;

                    Size-- ;

                    r->right = NULL ;


                }

                else { //// Two Children   //// : replace Node with Greater Node in the Left
                                            //// or : replace Node with Smaller Node in the Right

                 Node *max_left = Find_Max(r->left ) ;

                 r->data = max_left->data ;

                  r->left = Delete(r->left , max_left->data  ) ;

                }

            }


            return r ;

        }

        void Clear(Node* r) {

            if (!r) return;

            Clear(r->left);

            Clear(r->right);

            delete r ;
        }


    public:


        int Get_Size ( ){

            return Size ;

        }









        bool Search (int key ) {


            Node*result = Search(root , key ) ;

            if (result == NULL )
                return false ;
            else
                return true ;


        }









        void Insert (int item ) {

           root  =  Insert( root , item ) ;

        }









        void Pre_Order (Node *r) { ////  Root - Left - Right ////

            if (r == NULL)
                return ;

            cout <<r->data <<" " ;
            Pre_Order (r->left ) ;
            Pre_Order(r->right );

        }











        void In_Order ( Node *r ) { ////  Sorted : Left - Root - Right  ////

            if (r == NULL )
                return ;

            In_Order(r->left) ;

            cout <<r->data <<" " ;

            In_Order(r->right) ;

        }








        void Post_Order ( Node * r ){ ////  Left - Right - Root  ////

            if (r == NULL)
                return ;
            Post_Order(r->left)  ;

            Post_Order(r->right) ;

            cout<< r->data <<" " ;

        }










        int Find_Min ( ){

            Node * result = Find_Min(root ) ;

            if (result == NULL ) {

                return -1;

            }

            else {

                return result->data;

            }
        }











        int Find_Max ( ) {

            Node *result = Find_Max(root ) ;

            if (result == NULL )

            {
                return -1 ;

            }
            else {


                return  result->data ;

            }
        }









        void Delete_Node ( int item ) {

            root  = Delete(root , item ) ;

        }









        void Clear_BST() {

            Clear(root);

            root = nullptr;

            Size = 0;
        }










        ~Binary_Search_Tree( ) {   //// The destructor

            Clear_BST();  ////  Delete all nodes when the object is destroyed

        }

    };











int main() {

    FastIO       //   input.txt   output.txt

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    //// 45 , 15 , 79 , 90 , 10 , 55 , 12 , 20 ,50 ////
    Binary_Search_Tree Tree ;
    Tree.Insert(45 ) ;
    Tree.Insert(15) ;
    Tree.Insert(79) ;
    Tree.Insert(10) ;
    Tree.Insert(55) ;
    Tree.Insert(12) ;
    Tree.Insert(20) ;
    Tree.Insert(50) ;

    Tree.Delete_Node(45);
    Tree.Delete_Node(10) ;
    cout<<"Display Binary Search Tree Content Pre_Order Traversal Root - Left - Right\n " ;
    Tree.Pre_Order(Tree.root ) ; cout << el << el ;
    cout<<"Display Binary Search Tree Content Sorted elements In_Order Traversal Left - Root - Right \n " ;
    Tree.In_Order(Tree.root ) ; cout << el << el ;
    cout<<"Display Binary Search Tree Content Post_Order Traversal Left - Right - Root\n " ;
    Tree.Post_Order(Tree.root ) ; cout << "\n" ;

    cout<<"Enter Item to Search For"<< el  ;
    int key ;
    cin >> key ;
       int res =  Tree.Search( key ) ;
    if ( res ){

        cout<<"Item Found "<<el ;

    }else {

        cout<<"Item Not Found "<<el ;

    }

    cout << "Maximum Value in Binary_Search_Tree is = " << Tree.Find_Max() << el;
    cout << "Minimum Value in Binary_Search_Tree is = " << Tree.Find_Min() << el ;
    cout<<"Binary_Search_Tree Size = " << Tree.Get_Size() <<el ;

    Tree.Clear_BST();

    cout<<"Size Now = " << Tree.Get_Size() <<el ;



    return 0 ;

}







