#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

struct Book books[100];
int count = 0;

void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);
    count++;
    printf("\nBook Added Successfully!\n");
}

void displayBooks() {
    if(count==0){ printf("\nNo books available.\n"); return; }
    for(int i=0;i<count;i++){
        printf("\nID: %d\nTitle: %s\nAuthor: %s\n",
               books[i].id, books[i].title, books[i].author);
    }
}

void searchBook() {
    int id, found=0;
    printf("\nEnter Book ID: ");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(books[i].id==id){
            printf("\nFound!\nTitle: %s\nAuthor: %s\n", books[i].title, books[i].author);
            found=1;
        }
    }
    if(!found) printf("\nBook Not Found!\n");
}

void deleteBook() {
    int id;
    printf("\nEnter Book ID: ");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(books[i].id==id){
            for(int j=i;j<count-1;j++) books[j]=books[j+1];
            count--;
            printf("\nBook Deleted.\n");
            return;
        }
    }
    printf("\nBook Not Found!\n");
}

int main() {
    int choice;
    while(1){
        printf("\n1.Add Book\n2.Display Books\n3.Search Book\n4.Delete Book\n5.Exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:addBook();break;
            case 2:displayBooks();break;
            case 3:searchBook();break;
            case 4:deleteBook();break;
            case 5:return 0;
            default:printf("Invalid Choice\n");
        }
    }
}
