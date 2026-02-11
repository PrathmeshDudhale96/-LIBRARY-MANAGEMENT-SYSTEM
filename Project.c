#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for book
struct Book
{
    int bookID;
    char title[100];
    char author[50];
    int available; // 1 = available, 0 = issued
    char borrower[50];
};

struct Book books[100];
int totalBooks = 0;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void saveToFile();
void loadFromFile();

int main()
{
    int choice;

    loadFromFile();

    printf("   LIBRARY MANAGEMENT SYSTEM\n");

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            issueBook();
            break;
        case 5:
            returnBook();
            break;
        case 6:
            saveToFile();
            printf("\nThank you for using Library System!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// function to add new book
void addBook()
{
    struct Book newBook;

    printf("\n--- Add New Book ---\n");

    newBook.bookID = totalBooks + 1;

    printf("Enter book title: ");
    getchar();
    fgets(newBook.title, 100, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

    printf("Enter author name: ");
    fgets(newBook.author, 50, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    newBook.available = 1;
    strcpy(newBook.borrower, "None");

    books[totalBooks] = newBook;
    totalBooks++;

    printf("\nBook added successfully! Book ID: %d\n", newBook.bookID);
}

// function to display all books
void displayBooks()
{
    int i;

    printf("  LIBRARY BOOK RECORDS\n");

    if (totalBooks == 0)
    {
        printf("No books in library!\n");
        return;
    }

    for (i = 0; i < totalBooks; i++)
    {
        printf("\nBook ID: %d\n", books[i].bookID);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);

        if (books[i].available == 1)
        {
            printf("Status: Available\n");
        }
        else
        {
            printf("Status: Issued to %s\n", books[i].borrower);
        }
        printf("----------------------------------------\n");
    }
}

// function to search book
void searchBook()
{
    char searchTitle[100];
    int i;
    int found = 0;

    printf("\n Search Book \n");
    printf("Enter book title to search: ");
    getchar();
    fgets(searchTitle, 100, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    for (i = 0; i < totalBooks; i++)
    {
        if (strcmp(books[i].title, searchTitle) == 0)
        {
            printf("\nBook Found!\n");
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);

            if (books[i].available == 1)
            {
                printf("Status: Available\n");
            }
            else
            {
                printf("Status: Issued to %s\n", books[i].borrower);
            }

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBook not found in library!\n");
    }
}

// function to issue book
void issueBook()
{
    int bookID;
    char borrowerName[50];
    int i;
    int found = 0;

    printf("\n--- Issue Book ---\n");
    printf("Enter Book ID to issue: ");
    scanf("%d", &bookID);

    for (i = 0; i < totalBooks; i++)
    {
        if (books[i].bookID == bookID)
        {
            found = 1;

            if (books[i].available == 0)
            {
                printf("\nSorry! This book is already issued to %s\n", books[i].borrower);
                return;
            }

            printf("Enter borrower name: ");
            getchar();
            fgets(borrowerName, 50, stdin);
            borrowerName[strcspn(borrowerName, "\n")] = 0;

            strcpy(books[i].borrower, borrowerName);
            books[i].available = 0;

            printf("\nBook issued successfully to %s!\n", borrowerName);
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBook ID not found!\n");
    }
}

// function to return book
void returnBook()
{
    int bookID;
    int i;
    int found = 0;

    printf("\n--- Return Book ---\n");
    printf("Enter Book ID to return: ");
    scanf("%d", &bookID);

    for (i = 0; i < totalBooks; i++)
    {
        if (books[i].bookID == bookID)
        {
            found = 1;

            if (books[i].available == 1)
            {
                printf("\nThis book is already available in library!\n");
                return;
            }

            printf("\nBook returned by: %s\n", books[i].borrower);
            strcpy(books[i].borrower, "None");
            books[i].available = 1;

            printf("Book returned successfully!\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBook ID not found!\n");
    }
}

// function to save data to file
void saveToFile()
{
    FILE *fp;
    int i;

    fp = fopen("library_data.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%d\n", totalBooks);

    for (i = 0; i < totalBooks; i++)
    {
        fprintf(fp, "%d\n", books[i].bookID);
        fprintf(fp, "%s\n", books[i].title);
        fprintf(fp, "%s\n", books[i].author);
        fprintf(fp, "%d\n", books[i].available);
        fprintf(fp, "%s\n", books[i].borrower);
    }

    fclose(fp);
    printf("\nData saved successfully!\n");
}

// function to load data from file
void loadFromFile()
{
    FILE *fp;
    int i;

    fp = fopen("library_data.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    fscanf(fp, "%d\n", &totalBooks);

    for (i = 0; i < totalBooks; i++)
    {
        fscanf(fp, "%d\n", &books[i].bookID);
        fgets(books[i].title, 100, fp);
        books[i].title[strcspn(books[i].title, "\n")] = 0;
        fgets(books[i].author, 50, fp);
        books[i].author[strcspn(books[i].author, "\n")] = 0;
        fscanf(fp, "%d\n", &books[i].available);
        fgets(books[i].borrower, 50, fp);
        books[i].borrower[strcspn(books[i].borrower, "\n")] = 0;
    }

    fclose(fp);
}