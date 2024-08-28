#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int maxB = 100;

class Library {
private:
    string titles[maxB];
    string authors[maxB];
    int years[maxB];
    int bookCount;

public:
    Library() : bookCount(0) {}

    void clearScreen() const {
        system("cls"); 
    }

    void addBook() {
        if (bookCount >= maxB) {
            cout << "Library is full. Cannot add more books.\n";
            return;
        }

        cout << "Enter the title: ";
        cin.ignore();
        getline(cin, titles[bookCount]);

        cout << "Enter the author: ";
        getline(cin, authors[bookCount]);

        cout << "Enter the year: ";
        cin >> years[bookCount];

        bookCount++;
        clearScreen();
    }

    void displayBooks() const {
        if (bookCount == 0) {
            cout << "\nNo books found in the library.\n";
        } else {
            cout << "\nDisplaying All Books in the Library:\n";
            for (int i = 0; i < bookCount; ++i) {
                cout << "Book " << i + 1 << ":\n";
                cout << "Title: " << titles[i] << endl;
                cout << "Author: " << authors[i] << endl;
                cout << "Year: " << years[i] << endl << endl;
            }
        }
        cout << "Press Enter to return.";
        cin.ignore();
        cin.get();
        clearScreen();
    }

    void searchBooks() const {
        string searchB;
        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, searchB);

        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (titles[i] == searchB) {
                cout << "Book found:\n";
                cout << "Title: " << titles[i] << endl;
                cout << "Author: " << authors[i] << endl;
                cout << "Year: " << years[i] << endl << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found.\n";
        }
        cout << "Press Enter to return.";
        cin.ignore();
        cin.get();
        clearScreen();
    }
};

int main() {
    Library library;
    int option;

    library.clearScreen();

    do {
        cout << "\nLibrary Books\n";
        cout << "1 - Add book to library\n";
        cout << "2 - Display all books in library\n";
        cout << "3 - Search for a book\n";
        cout << "4 - Exit\n";
        cout << "Select Option: ";
        cin >> option;

        library.clearScreen();

        if (option == 1) {
            library.addBook();
        } else if (option == 2) {
            library.displayBooks();
        } else if (option == 3) {
            library.searchBooks();
        } else if (option == 4) {
            cout << "Exiting the program.\n";
        } else {
            cout << "Invalid option. Please try again.\n";
            cout << "Press Enter to return.";
            cin.ignore();
            cin.get();
            library.clearScreen();
        }
    } while (option != 4);

    return 0;
}
