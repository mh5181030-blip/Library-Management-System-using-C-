#include<iostream>
#include<string>
using namespace std;

// BOOK CLASS 

class Book
{
private:
    int bookID;
    string title;
    string author;
    bool issue;
    int issueDay;
    int dueDay;

public:
    Book()
    {
      bookID = 0;
      title = "";
      author = "";
      issue = false;
      issueDay = 0;
      dueDay = 0;
    }
    
    Book(int id, string t, string a)
    {
      bookID = id;
      title = t;
      author = a;
      issue = false;
      issueDay = 0;
      dueDay = 0;
    }
    
    void displayBooksDetails()
    {
        cout<<"Book ID : " << bookID << endl;
        cout<<"Book Title : " << title << endl;
        cout<<"Book Author : " << author << endl;
        if(issue == true)
        {
          cout<<"Status : Not Available"<<endl;
        }
        else
        {
          cout<<"Status : Available"<<endl;
        }
    }

    int getBookID()
    {
      return bookID;
    }

    string getTitle()
    {
      return title;
    }

    string getAuthor()
    {
      return author;
    }
    
    bool isIssued()    // Check whether book is issued
    {
      return issue;
    }

    void issued(int day)
    {
      issue = true;
      issueDay = day;
      dueDay = day + 7;
    }
    
    int getIssueDay()
    {
      return issueDay;
    }
    
    int getDueDay()
    {
      return dueDay;
    }

    void returned()
    {
      issue = false;
    }
};

// MEMBER CLASS 

class Member
{
private:
    int id;
    string name;
public:
	
    Member()
    {
      id = 0;
      name = "";
    }

    Member(int i, string n)
    {
      id = i;
      name = n;
    }

    void displayMemberDetails()
    {
      cout<<"Member ID : "<<id <<endl;
	  cout<<"Member Name : "<<name <<endl;
    }

    int getMemberID()
    {
      return id;
    }
    
    string getMemberName()
    {
      return name;
    }
};

// LIBRARY CLASS 

class Library
{
private:
    static const int max = 100;
    Book book[max];
    Member member[max];
    int bookCount;
    int memberCount;
public:
	
    Library()
    {
        bookCount = 0;
        memberCount = 0;
    }

//ADD BOOK

    void addBook()
    {
        if(bookCount < max)
        {
            int id;
            string title;
            string author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Name: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            book[bookCount] = Book(id, title, author);
            bookCount++;
            cout << "Book Added Successfully!" << endl;
        }
        else
        {
            cout << "Library is Full!" << endl;
        }
    }
    
// ADD MEMBER

    void addMember()
    {
        if(memberCount < max)
        {
            int id;
            string name;
            cout << "Enter Member ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Member Name: ";
            getline(cin, name);
            member[memberCount] = Member(id, name);
            memberCount++;
            cout << "Member Added Successfully!" << endl;
        }
        else
        {
            cout << "Member List is Full!" << endl;
        }
    }


//DISPLAY ALL BOOKS

    void displayBooks()
    {
        if(bookCount == 0)
        {
            cout << "No Books Available!" << endl;
            return;
        }

        for(int i = 0; i < bookCount; i++)
        {
            book[i].displayBooksDetails();
            if(book[i].isIssued())
            {
                cout << "Issue Day : " << book[i].getIssueDay() << endl;
                cout << "Due Day : " << book[i].getDueDay() << endl;
            }
            cout<<endl;
        }
    }


//DISPLAY MEMBERS 

    void displayMembers()
    {
        if(memberCount == 0)
        {
            cout << "No Members Available!" << endl;
            return;
        }

        for(int i = 0; i < memberCount; i++)
        {

            member[i].displayMemberDetails();
            cout<<endl;
        }
    }

// ISSUE BOOK

    void issueBook()
    {
        int memberID;
        int bookID;
        int issueDay;
        bool memberFound = false;
        bool bookFound = false;
        cout << "Enter Member ID: ";
        cin >> memberID;
        // Find Member
        for(int i = 0; i < memberCount; i++)
        {
            if(member[i].getMemberID() == memberID)
            {
                memberFound = true;
                break;
            }
        }

        if(memberFound == false)
        {
            cout << "Member Not Found!" << endl;
            return;
        }
        else
		{
        cout << "Enter Book ID: ";
        cin >> bookID;
        // Find Book
        for(int i = 0; i < bookCount; i++)
        {
            if(book[i].getBookID() == bookID)
            {
                bookFound = true;
                if(book[i].isIssued())
                {
                    cout << "Book is Already Issued!" << endl;
                    return;
                }
                cout << "Enter Current Day Number: ";
                cin >> issueDay;
                book[i].issued(issueDay);
                cout << "\nBook Issued Successfully!" << endl;
                cout << "Issue Day: " << book[i].getIssueDay() << endl;
                cout << "Due Day: " << book[i].getDueDay() << endl;
                cout << "Book can be returned within 7 days." << endl;
                return;
            }
        }
        }
        if(bookFound == false)
        {
            cout << "Book Not Found!" << endl;
        }
    }
    
// RETURN BOOK

    void returnBook()
    {
        int memberID;
        int bookID;
        int returnDay;
        bool memberFound = false;
        bool bookFound = false;
        cout << "Enter Member ID: ";
        cin >> memberID;
        // Find Member
        for(int i = 0; i < memberCount; i++)
        {
            if(member[i].getMemberID() == memberID)
            {
                memberFound = true;
                break;
            }
        }
        if(memberFound == false)
        {
            cout << "Member Not Found!" << endl;
            return;
        }
        else
		{
        cout << "Enter Book ID: ";
        cin >> bookID;
        // Find Book
        for(int i = 0; i < bookCount; i++)
        {
            if(book[i].getBookID() == bookID)
            {
                bookFound = true;
                if(book[i].isIssued() == false)
                {
                    cout << "This Book Was Not Issued!" << endl;
                    return;
                }
                cout << "Enter Return Day Number: ";
                cin >> returnDay;

                int dueDay = book[i].getDueDay();
                int daysLate = returnDay - dueDay;
                int fine = 0;
                if(daysLate > 0)
                {
                    fine = daysLate * 500;
                }
                book[i].returned();
                cout << "\nBook Returned Successfully!" << endl;

                // RECEIPT 

                cout << "\n\t\t\t\t====================================" << endl;
                cout << "\t\t\t\t          RETURN RECEIPT            " << endl;
                cout << "\t\t\t\t====================================" << endl;
                
                cout << "Member ID   : " << memberID << endl;
                // Find Member Name
                for(int j = 0; j < memberCount; j++)
                {
                    if(member[j].getMemberID() == memberID)
                    {
                        cout << "Member Name : "<< member[j].getMemberName() << endl;
                        break;
                    }
                }
                cout << "Book ID : " << book[i].getBookID() << endl;
                cout << "Book Name : " << book[i].getTitle() << endl;
                cout << "Author : " << book[i].getAuthor() << endl;
                cout << "Issue Day : " << book[i].getIssueDay() << endl;
                cout << "Due Day : " << book[i].getDueDay() << endl;
                cout << "Return Day : " << returnDay << endl;
                if(daysLate > 0)
                {
                    cout << "Days Late : " << daysLate << endl;
                }
                else
                {
                    cout << "Days Late : 0" << endl;
                }
                cout << "Fine : Rs. " << fine << endl;
                return;
            }
        }
     }
        if(bookFound == false)
        {
            cout << "Book Not Found!" << endl;
        }
    }
};

//  MAIN FUNCTION 

int main()
{
    Library l;
    int choice;
    do
    {
        cout <<endl;
        cout << "\t\t\t\t============================================" << endl;
        cout << "\t\t\t\t       LIBRARY MANAGEMENT SYSTEM            " << endl;
        cout << "\t\t\t\t============================================" << endl;

        cout << "\n1. Add Book" << endl;
        cout << "2. Add Member" << endl;
        cout << "3. Display All Books" << endl;
        cout << "4. Display All Members" << endl;
        cout << "5. Issue Book" << endl;
        cout << "6. Return Book" << endl;
        cout << "7. Exit" << endl;
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        
        if(choice == 1)
        {
            l.addBook();
        }
        else if(choice == 2)
        {
            l.addMember();
        }
        else if(choice == 3)
        {
            l.displayBooks();
        }
        else if(choice == 4)
        {
            l.displayMembers();
        }
        else if(choice == 5)
        {
            l.issueBook();
        }
        else if(choice == 6)
        {
            l.returnBook();
        }
        else if(choice == 7)
        {
            cout << "Thank You!" << endl;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }

    }
    while(choice != 7);
    return 0;
}