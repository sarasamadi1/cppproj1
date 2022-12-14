#include<iostream>
#include <string>
#include <array>


using namespace std;

class BookStore{
      protected:


              struct Customers {   //customers data structure
                     string nameOfCustomer;
                     string wantedBooks ;
                     int copiesNeeded;
              };
              struct Inventory {       //inventory data structure
                     string book_name;
                     int copies;
                     int price;
              };

      public:

              Inventory InArray[100];    //array of structure
              Customers CuArray[100];
              Inventory InArray1[1];    //array of structure
              Customers CuArray2[1];


              Inventory * resizeInventory(int n){
                  InArray[n];
                  return InArray;
              }

              Customers * resizeCustomers(int x){
                  CuArray[x];
                  return CuArray;
              }


              Inventory * printInventory(int n) {
                  cout<<"copies     price     book name"<<endl;
                  for(int i=0;i<n;i++){string n=InArray[i].book_name;
                     printf("%d",InArray[i].copies);     //format the inventory
                     printf("%15d",InArray[i].price);
                     printf("%5s", " ");
                     cout<<n;
                     cout<<endl;
                  }
                  return InArray;
              }

                Customers * printCustomers(int x){
                  cout<<"copies    wanted book          name of the customer"<<endl;
                  for(int i=0;i<x;i++){
                      printf("%d",CuArray[i].copiesNeeded);    //format customer
                      printf("%11s", " ");
                      cout<<CuArray[i].wantedBooks;
                      printf("%9s", " ");
                      cout<<CuArray[i].nameOfCustomer<<endl;

                  }
                  return CuArray;
              }


              Inventory * addBook(string Books, int c, int price,int n) {

                  Inventory In;


                      In.book_name = Books;
                      In.copies = c;
                      In.price = price;

                      for(int i=0;i<n;i++){
                          if(InArray[i].book_name==Books){
                              InArray[i].copies=InArray[i].copies+c;  //edit copies if book exist
                              break;
                          }
                          else if(InArray[i].book_name.empty()) {   //if it does not exist
                              InArray[i] = In;
                              break;
                          }
                      }
                      return InArray;
              }

              Inventory * deleteBook(string Books,int c ,int n){
                  int i;
                  for(i=0;i<n+1;i++){
                      if(InArray[i].book_name==Books && InArray[i].copies==c){  //shift elements for deleting
                          InArray[i] =InArray[i+1];


                      }
                      else if (InArray[i].book_name==Books && InArray[i].copies>c) { //edit the existing copies
                          int k;
                          k = InArray[i].copies - c;
                          InArray[i].copies = k;
                          k=0;


                      }
                      }

                  return InArray;
                 }




              void requestAdelivery(string Books,int co,int price,int n){  //request books
                  cout<<co<<" copies of "<<Books<<" is needed "<<endl;
                  addBook(Books,co,price,n);

              }

              Customers * addCustomersToList(string name,string Books,int co,int x){ //make the array of structure
                  Customers c;

                  c.nameOfCustomer=name;
                  c.wantedBooks=Books;
                  c.copiesNeeded=co;


                  for(int i=0;i<x;i++){
                      if(CuArray[i].nameOfCustomer.empty()) {
                          CuArray[i] = c;
                          break;
                      }
                  }
                  return CuArray;

              }

              Customers * addCustomer(string Books,int co,int n,int x){ //manage the customers

                      for (int j= 0; j < n; j++) {
                          for(int i=0;i<x;i++) {
                              if (CuArray[i].wantedBooks == InArray[j].book_name &&
                                  CuArray[i].copiesNeeded == InArray[j].copies) {
                                  deleteBook(Books, co, n);
                              } else if (CuArray[i].wantedBooks == InArray[j].book_name && CuArray[i].copiesNeeded < InArray[j].copies) {
                                  deleteBook(Books, co, n);

                              }
                          }
                      }

                  return CuArray;
              }

              Customers * deleteCustomer(string name,string book, int x){
                  for(int i=0;i<x ;i++){
                      if(CuArray[i].nameOfCustomer==name && CuArray[i].wantedBooks==book ) {
                          CuArray[i]=CuArray[i+1];



                      }

                  }
                  return CuArray;
              }






};

int main(){
    //test code
     BookStore bs;
     //initializing 5 books in the inventory
     bs.addBook("Alice In Wonderland", 5, 70,5);
     bs.addBook("Adam And Eva",3, 85,5);
     bs.addBook("The Clean Code",10,100,5);
     bs.addBook("Theory of living ",7,60,5);
     bs.addBook("mindfulness",15,80,5);


     cout<<"Hello dear customer these are the books that we have today "<<endl;
     bs.printInventory(5);

     //taking first customers
     bs.addCustomersToList("sedra","Alice In Wonderland",2,5);
     bs.addCustomersToList("sahar","The Clean Code",2,5);
     bs.addCustomersToList("yazan","Mindfulness",1,5);
     bs.addCustomersToList("sara","Theory Of Living",2,5);
     bs.addCustomersToList("ahmet","Adam And Eva",2,5);

     cout<<"our customers for today and their requests"<<endl;
     bs.printCustomers(5);

     //serve the customers
     bs.addCustomer("Alice In Wonderland",2,5,5);
     bs.addCustomer("The Clean Code",2,5,5);
     bs.addCustomer("Mindfulness",1,5,5);
     bs.addCustomer("Theory Of Living",2,5,5);
     bs.addCustomer("Adam And Eva",2,5,5);

     cout<<"serves is done thank you for visiting the store"<<endl;
     cout<<"the left books are:"<<endl;
     bs.printInventory(5);

     //delete the customers that we served

     bs.deleteCustomer("sedra","Alice In Wonderland",5);
     bs.deleteCustomer("sahar","The Clean Code",5);
     bs.deleteCustomer("yazan","Mindfulness",5);
     bs.deleteCustomer("sara","Theory Of Living",5);
     bs.deleteCustomer("ahmet","Adam And Eva",5);

     //bs.printCustomers(5);

     //Books delivery
     cout<<"Hello delivery man please but the books in the inventory"<<endl;
     string book [4]= {"Neverland","Music","Cook With Maria","Adam And Eva"};
     int copies[4]={12,5,3,2};
     int price[4]={70,66,90,78};

     for(int i=0;i<4;i++){
         bs.addBook(book[i],copies[i],price[i],8);
     }
     bs.printInventory(8);

     cout<<endl;
     cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;

     cout<<"welcoming customer again"<<endl;

    bs.addCustomersToList("naser","neverland",2,10);
    bs.addCustomersToList("betul","Music",2,10);
    bs.addCustomersToList("hasan","Cook With Maria",1,10);
    bs.addCustomersToList("selim","Theory Of Living",1,10);
    bs.addCustomersToList("taleen","The Clean Code",1,10);

    cout<<"our customers for today and their requests"<<endl;
    bs.printCustomers(10);

    //serve the customers
    bs.addCustomer("neverland",2,12,5);
    bs.addCustomer("Music",2,12,5);
    bs.addCustomer("Cook With Maria",1,12,5);
    bs.addCustomer("Theory Of Living",1,12,5);
    bs.addCustomer("The Clean Code",1,12,5);

    cout<<"serves is done thank you for visiting the store"<<endl;
    cout<<"the left books are:"<<endl;
    bs.printInventory(8);

    //delete the customers that we served

    bs.deleteCustomer("naser","neverland",5);
    bs.deleteCustomer("betul","Music",5);
    bs.deleteCustomer("hasan","Cook with maria",5);
    bs.deleteCustomer("selim","Theory Of Living",5);
    bs.deleteCustomer("taleen","The clean code",5);

    //bs.printCustomers(10);

    //Books delivery
    cout<<"Hello delivery man please but the books in the inventory"<<endl;
    string book1 [4]= {"Alice In Wonderland","Music","introduction to c++","Networks"};
    int copies1[4]={4,2,5,2};
    int price1[4]={75,60,80,78};

    for(int i=0;i<4;i++){
        bs.addBook(book1[i],copies1[i],price1[i],10);
    }
    bs.printInventory(10);







}









