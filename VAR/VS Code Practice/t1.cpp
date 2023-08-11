#include <bits/stdc++.h>
using namespace std;


struct Book
{
    char product[5];
    int price;
    int seqNum;
} b[55];

int i=0;
void load()
{
    printf("-------------------------\n");
    printf("Adding the Book Details by load() function\n");
	printf("-------------------------\n");
    //Pri
    strcpy(b[i].product,"K7");
    b[i].price=100;
    b[i].seqNum=1;
    i = i + 1;

}

void print()
{
    printf("\n\n-------------------------\n");
    printf("Printing the Book Details by print() function\n");
	printf("-------------------------\n");
    for(int j=0; j<i; j++)
    {
    //   printf("Book %d\n",i+1);
        cout<<"Book: "<<j+1<<endl;
        cout<<"Product Type: "<<b[j].product<<endl;
        cout<<"Price: "<<b[j].price<<endl;
        cout<<"Squence No: "<<b[j].seqNum<<endl;
    }
}

int main()
{
    load();
    print();
//   struct Book books[5];
//    Book b;    
    // cout << "Enter name of book\n";
    // cin.getline(b.product, 100);
    // cout << "Enter price of employee\n";
    // cin >> b.price;
    // cout << "Enter ISBN code\n";
    // cin >> b.seqNum;
    
  return 0;
}