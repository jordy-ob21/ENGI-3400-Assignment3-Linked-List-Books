#include <iostream>
#include <string>

using namespace std;

// Creating the structure
struct book {
        string title;
        string author;
        string pub;
        string pubYear;
        string Inum;
        book* next;
};

//Functions Prototypes
book* add_node(book *head);
void print_list(book *head);
void delete_list(book ** head, int position);

int main() {
//Define head pointer and setting to NULL
    book* head = NULL;
//While loop to repeat switch case until Q is entered
    while(true){
        char choice;
        cout << "Add book details [A]" << endl << "Print book details [P]" << endl;
        cout << "Delete book details [D]" << endl << "Quit [Q]" << endl;
        cin >> choice;
// Switch case to call functions
        switch (choice){
            case 'A':
                head = add_node(head);
                break;
            case 'P':
                print_list(head);
                break;
            case 'Q':
                return 0;
            case 'D':
                int select;
                cout << "Which book would you like to delete?"<< endl;
                cin >> select;
                delete_list(&head,select);
                break;
        }
    }
}
book* add_node (book*head){
//Getting user input

//Creating a new book in dynamic memory and assigning it to 'temp'
    book* temp= new book;
//Assigning user input to the book
    cout << "Enter book title: " << endl;
    cin.ignore();
    getline(cin,temp -> title);
    cout << "Enter author's name:" << endl;
    getline(cin, temp -> author);
    cout << "Enter publisher:" << endl;
    getline(cin, temp -> pub);
    cout << "Enter year published: ";
    cin >> temp -> pubYear;
    cout << "Enter ISBN number: ";
    cin >> temp -> Inum;
    temp -> next = head;
// The new book becomes the head, pushing previously entered books forward
    head = temp;
    return head;
}

void print_list(book* head ){
// count created to count how many times loop is executed (Used to number books)
    int count = 0;
// for loop prints head of list then changes head to the next
    for ( ; head; head = head->next ){
        count++;
        cout<< "Book: "<< count<< endl;
        cout << "Title: " << head->title << endl;
        cout << "Author: " << head->author << endl;
        cout << "Publisher: " << head->pub << endl;
        cout << "Year Published: " << head->pubYear << endl;
        cout << "ISBN Number: " << head->Inum << endl;
      
      }

}

void delete_list(book** head, int booknum){
    book* temp= *head;
    book* prev= *head;

    for (int i = 0; i < booknum; i++) {
        if (i == 0 && booknum == 1) {
            *head = (*head)->next;
            delete(temp);
           }
        else {
            if (i == booknum - 1 && temp) {
                prev->next = temp->next;
                delete(temp);
               }
        else {
            prev = temp;
            if (prev == NULL){
                break;}
            temp = temp->next;
               }
           }
       }
}

