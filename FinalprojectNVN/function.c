#include "datatype.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int numBook = 0;
int numUser = 0;
Book b01[100];
Member m01[100];

void loginAccount(char email[], char pass[], int *size,int *size1) {
    char ch;
    int indexPass = 0;
    printf("\n\n               LOGIN     \n");
    printf(" Note email: Nam;pass:06082006\n");
    printf("       ======================\n");
    printf("       Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    printf("       Pass: ");
    while ((ch = getch()) != '\r') {
        if (ch == '\b') {
            if (indexPass > 0) {
                indexPass--;
                printf("\b \b");
            }
        } else {
            printf("*");
            pass[indexPass++] = ch;
        }
    }
    pass[indexPass] = '\0';
    if (strcmp(email, "Nam") == 0 && strcmp(pass, "06082006") == 0) {
      	 
	    printf("\n       ======================\n");
        printf("       Login successful ! \n\n");
        menu();
    } else {
        printf("\n       ======================\n");
        printf("       Login failed ! \n\n");
   		printf(" Note email: Nam;pass:06082006\n");
    }
}
	void menu(){
		int choice;
		int size = 0;
		int *sizePtr=&size;
		
	
	do {
	("\n      ***Admin***\n");
        printf("================================\n");
        printf("1. Library Book\n");
        printf("2. Customer Management\n");
        printf("0. Exit\n");
		printf("================================\n");
	    printf("Enter The Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
               menu1();
                break;

            case 2:
                menu2();
			    break;

            case 0:
                  printf("Exit program\n");
                
                break;
			default:
				 printf("Invalid selection. Please try again!\n");
		}
	}while(choice!=0);
}
void menu1() {
    int choice;
    int size = 0;
    int *sizePtr = &size;
    

    loadFile(); 

    do {
        printf("\n      ***Library Management***\n");
        printf("================================\n");
        printf("1. Show book list\n");
        printf("2. Add book\n");
        printf("3. Edit book information\n");
        printf("4. Delete Book\n");
        printf("5. Sort books by price\n");
        printf("6. Search Book\n");
        printf("7. Exit\n");
	
		printf("================================\n");
	    printf("Enter The Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayBookScreen(b01, numBook);
                break;

            case 2:
                addBookScreen(b01, sizePtr);
			    saveFile();
				break;

            case 3:
                 editBookScreen(b01, numBook);
                 saveFile();
                break;

            case 4:
	             delteteBookScreen(b01,numBook);
			    	saveFile();
				break;

            case 5:
               sortBookScreen(b01,numBook);
				break;

            case 6:
                searchBook(b01,numBook);
				break;

            case 7:
                printf("Exit program\n");
                break;
         
            default:
                printf("Invalid selection. Please try again!\n");
        }
    } while (choice != 7);
    saveFile();
}


	
void loadFile() {
    FILE *file = fopen("book.bin", "rb");
    if (file == NULL) {
        printf("Error loading file!\n"); 
        numBook = 0;
        return;
    }
    numBook = fread(b01, sizeof(Book), 100, file); 
    fclose(file);

}




void displayBook(Book b01[], int size) {
    if (size == 0) {
        printf("\nDanh sach trong\n\n");
        return;
    }
    printf("|=======|====================|====================|===============|===============|\n");
    printf("|   ID  |         Bookname   |        Author      |       Type    |      Price    |\n");
   for (int i = 0; i < size; i++) {
    printf("|=======|====================|====================|===============|===============|\n");
    printf("|%-7s|%-20s|%-20s|%-15s|%-15.2f|\n", b01[i].id, b01[i].bookname, b01[i].author, b01[i].type, b01[i].price);
    }
    printf("\n");
}



void addBook(Book book[], int *sizePtr) {
    FILE *ptr = fopen("book.bin", "ab");
    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < *sizePtr; i++) {
        int isDuplicateId = 0, isDuplicateName = 0;

        getchar(); 

        do {
            isDuplicateId = 0;
            printf("Enter ID: ");
            fgets(b01[numBook + i].id, 10, stdin);
            b01[numBook + i].id[strcspn(b01[numBook + i].id, "\n")] = '\0';

            
            for (int j = 0; j < numBook; ++j) {
                if (strcmp(b01[numBook + i].id, b01[j].id) == 0) {
                    printf("Error: ID already exists. Please enter a unique ID.\n");
                    isDuplicateId = 1;
                    break;
                }
            }
            if (strlen(b01[numBook + i].id) == 0) {
                printf("Error: ID cannot be empty.\n");
                isDuplicateId = 1;
            }
        } while (isDuplicateId);

        do {
            isDuplicateName = 0;
            printf("Enter Bookname: ");
            fgets(b01[numBook + i].bookname, 100, stdin);
            b01[numBook + i].bookname[strcspn(b01[numBook + i].bookname, "\n")] = '\0';

            
            for (int j = 0; j < numBook; ++j) {
                if (strcmp(b01[numBook + i].bookname, b01[j].bookname) == 0) {
                    printf("Error: Book name already exists. Please enter a unique name.\n");
                    isDuplicateName = 1;
                    break;
                }
            }
            if (strlen(b01[numBook + i].bookname) == 0) {
                printf("Error: Book name cannot be empty.\n");
                isDuplicateName = 1;
            }
        } while (isDuplicateName);


        printf("Enter the author: ");
        fgets(b01[numBook + i].author, 100, stdin);
        b01[numBook + i].author[strcspn(b01[numBook + i].author, "\n")] = '\0';

        printf("Enter the type: ");
        fgets(b01[numBook + i].type, 50, stdin);
        b01[numBook + i].type[strcspn(b01[numBook + i].type, "\n")] = '\0';

        printf("Enter the price: ");
        scanf("%f", &b01[numBook + i].price);
        getchar(); 

        fwrite(&book[numBook + i], sizeof(Book), 1, ptr); 
    }

    fclose(ptr);
    printf("Add book successfully\n");
}



void editBook(Book books[], int size) {
    char idToEdit[10];
    int foundIndex = -1;

    getchar();

    printf("Enter the ID of the book you want to edit: ");
    fgets(idToEdit, sizeof(idToEdit), stdin);
    idToEdit[strcspn(idToEdit, "\n")] = '\0';

    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].id, idToEdit) == 0) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        printf("Book with ID '%s' not found.\n\n", idToEdit);
        return;
    } else {
        printf("\n--- Current Book Information ---\n");
        printf("ID: %s\n", books[foundIndex].id);
        printf("Bookname: %s\n", books[foundIndex].bookname);
        printf("Author: %s\n", books[foundIndex].author);
        printf("Type: %s\n", books[foundIndex].type);
        printf("Price: %.2f\n\n", books[foundIndex].price);

        printf("--- Enter New Information ---\n");

       
        }

        printf("Enter new Bookname (): ");
        char newBookName[100];
        fgets(newBookName, sizeof(newBookName), stdin);
        newBookName[strcspn(newBookName, "\n")] = '\0';

        if (strlen(newBookName) > 0) {
            strcpy(books[foundIndex].bookname, newBookName);
        }
        
        printf("Enter new Author : ");
        char newAuthor[100];
        fgets(newAuthor, sizeof(newAuthor), stdin);
        newAuthor[strcspn(newAuthor, "\n")] = '\0';
          if (strlen(newAuthor) > 0) {
            strcpy(books[foundIndex].author, newAuthor);
        }
        
        printf("Enter new Type : ");
        char newType[50];
        fgets(newType, sizeof(newType), stdin);
        newType[strcspn(newType, "\n")] = '\0';
         if (strlen(newType) > 0) {
            strcpy(books[foundIndex].type, newType);
        }

        printf("Enter new price : ");
        float newPrice;
        scanf("%f", &newPrice);
        if (newPrice != 0) {
            books[foundIndex].price = newPrice;
        }

        printf("\nBook information updated successfully!\n\n");
        saveFile();
    }


void saveFile() {
    FILE *file = fopen("book.bin", "wb");
    if (file == NULL) {
        printf("Error opening file (when saving)!\n");
    } else {
        fwrite(b01, sizeof(Book), numBook, file);
        fclose(file);
        printf("Luu file thanh cong");
    }
}
void displayBookScreen(Book b01[], int size) {
    int choice;
    do {
       printf("\n        ***Show Book List***   \n");
       printf("==============================\n");
       displayBook(b01, size);
       printf("1. Back to menu\n");
        printf("==============================\n");
        printf("Enter your choice: ");
         scanf("%d", &choice);
        if(choice != 1){
            printf("Invalid selection. Please try again!\n");
        }
    } while(choice != 1);
}

void addBookScreen(Book book[], int *sizePtr) {
    int choice;
    do {
        printf("\n          ***Add Book*** \n");
        printf("========================\n");
        printf("\nEnter quantity of books (Max 100): ");
        scanf("%d", sizePtr);
        if (*sizePtr <= 0 || *sizePtr > 100) {
            printf("\nInvalid entry\n\n");
            break;
        } else {
            addBook(b01, sizePtr);
            numBook += *sizePtr; 
        }
        printf("========================\n");
        printf("1. Back to menu\n");
        printf("========================\n");
        printf("Enter your choice: ");
         scanf("%d", &choice);
         if(choice != 1){
             printf("Invalid selection. Please try again!\n");
        }
    } while (choice != 1);
}

void editBookScreen(Book books[], int size) {
    int choice;
    do {
         printf("=====================================\n");
         editBook(books, size);
          printf("1. Back to menu\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice != 1){
             printf("Invalid selection. Please try again!\n");
        }
    } while (choice != 1);
}

	
 void delteteBook(Book books[], int *size) {
    char idToDelete[10];
    int foundIndex1 = -1;
    int confirmDelete = 0; 

    getchar(); 

    printf("Enter the ID of the book you want to delete: ");
    fgets(idToDelete, sizeof(idToDelete), stdin);
    idToDelete[strcspn(idToDelete, "\n")] = '\0';

    for (int i = 0; i < *size; i++) {
        if (strcmp(books[i].id, idToDelete) == 0) {
            foundIndex1 = i;
            break;
        }
    }

    if (foundIndex1 == -1) {
        printf("Book with ID '%s' not found.\n\n", idToDelete);
        return;
    }
    else {
        printf("--- Book Information to be Deleted ---\n");
        printf("ID: %s\n", books[foundIndex1].id);
        printf("Bookname: %s\n", books[foundIndex1].bookname);
        printf("Author: %s\n", books[foundIndex1].author);
        printf("Type: %s\n", books[foundIndex1].type);
        printf("Price: %.2f\n\n", books[foundIndex1].price);
    }
    char confirmation;
    printf("Are you sure you want to delete this book? (y/n): ");
        scanf(" %c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y') {
        confirmDelete = 1;
    }


    if (confirmDelete == 1) {
        for (int i = foundIndex1; i < *size - 1; i++) {
            books[i] = books[i + 1];
        }
        numBook--;
        
        printf("\nBook deleted successfully!\n\n");
        saveFile();
    } else {
        printf("\nDeletion cancelled.\n\n");
    }
}




void delteteBookScreen(Book books[], int size) {
    int choice;
    do {
        printf("=====================================\n");
        delteteBook(books, &numBook);
        printf("1. Back to menu\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice != 1) {
            printf("Invalid selection. Please try again!\n");
        }
    } while (choice != 1);
}
void  sortBook(Book books[], int size){
	int compare;
	
	printf("\nSort by ascending(1) or descending(2): ");
	scanf("%d",&compare);
	switch(compare){
		case 1:
			
			for(int i =0;i<size;i++){
				
				for(int j=0;j<size-1-i;j++){
					if(books[j+1].price<books[j].price){
						Book srt=books[j+1];
						books[j+1]=books[j];
						books[j]=srt;
					}
				}
			}
			break;
		case 2:
			for(int i=0;i<size;i++){
				for(int j=0;j<size-1-i;j++){
					if(books[j+1].price>books[j].price){
						Book srt=books[j];
						books[j]=books[j+1];
						books[j+1]=srt;
					}
				}
			}
			break;
		default:
			printf("Incorrect choice");
			break;
	}
		printf("|=======|====================|====================|===============|===============|\n");
    	printf("|   ID  |         Bookname   |        Author      |       Type    |      Price    |\n");
   for (int i = 0; i < size; i++) {
   		 printf("|=======|====================|====================|===============|===============|\n");
   		 printf("|%-7s|%-20s|%-20s|%-15s|%-15.2f|\n", b01[i].id, b01[i].bookname, b01[i].author, b01[i].type, b01[i].price);
    }
}



void sortBookScreen(Book books[], int size) {
     int choice;
     do{
        printf("\n        ***Sort Book By Price***   \n");
        printf("====================================\n");
        sortBook(books,size);
		
        printf("1. Back to menu\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice != 1) {
            printf("Invalid selection. Please try again!\n");
        }
    } while (choice != 1);
}

void searchBook(Book books[], int size) {
    char booknameToSearch[100]; 
    int found = 0; 

    getchar(); 
    printf("Enter bookname to find: ");
    fgets(booknameToSearch, sizeof(booknameToSearch), stdin);
    booknameToSearch[strcspn(booknameToSearch, "\n")] = '\0';

    printf("\nSearch results for \"%s\":\n", booknameToSearch); 

    for (int i = 0; i < size; i++) {
        if (strstr(books[i].bookname, booknameToSearch) != NULL) {
            if (!found) { 
                printf("|=======|====================|====================|===============|===============|\n");
                printf("|    ID |        Bookname    |        Author      |       Type    |      Price    |\n");
                printf("|=======|====================|====================|===============|===============|\n");
            }
            printf("|%-7s|%-20s|%-20s|%-15s|%-15.2f|\n", books[i].id, books[i].bookname, books[i].author, books[i].type, books[i].price);
            found = 1; 
        }
    }

    if (!found) { 
        printf("No books with bookname containing \"%s\" found.\n\n", booknameToSearch);
    } else {
        printf("|=======|====================|====================|===============|===============|\n"); 
    }
}
void menu2(){
	int choice;
    int size = 0;
    int *sizePtr = &size;
    

    loadMemberFile(); 

    do {
        printf("\n      ***Custom Management***\n");
        printf("================================\n");
        printf("1. Show custom list\n");
        printf("2. Add custom\n");
        printf("3. Edit custom information\n");
        printf("4. Search Custom\n");
        printf("5. Exit\n");
	
		printf("================================\n");
	    printf("Enter The Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayMember(m01,numUser);
                break;

            case 2:
                addMemberScreen(m01, &numUser);
			    break;

            case 3:
                editMemberScreen(m01, numUser);
                break;

            case 4:
	             searchMember(m01, numUser);
			    break;

            case 5:
                printf("Exit program\n");
				break;
         
            default:
                printf("Invalid selection. Please try again!\n");
        }
    } while (choice != 5);
    saveMemberFile();
}
void addMember(Member members[], int *size) {
    if (*size >= 100) {
        printf("Maximum number of members reached.\n");
        return;
    }
    getchar(); 
    
    printf("Enter member ID: ");
    fgets(members[*size].memberId, 10, stdin);
    members[*size].memberId[strcspn(members[*size].memberId, "\n")] = '\0';
    
        
    printf("Enter member name: ");
    fgets(members[*size].name, 100, stdin);
    members[*size].name[strcspn(members[*size].name, "\n")] = '\0';
    printf("Enter member phone: ");
    scanf("%s",members[*size].phone);
    (*size)++;
    printf("Member added successfully.\n");
}

void addMemberScreen(Member members[], int *size) {
    int quantity;
    printf("Enter the quantity of member to add: ");
    scanf("%d", &quantity);
    if(quantity + *size > 100){
        printf("Vuot qua so luong cho phep\n");
        return;
    }
    for(int i =0; i<quantity;i++){
        addMember(members,size);
    }
}

void displayMember(Member members[], int size1) {
    if (size1 == 0) {
        printf("\nDanh sach trong\n\n");
        return;
    }
    printf("|=======|====================|===============|\n");
    printf("|   ID  |        Name        |     Phone     |\n");
    for (int i = 0; i < size1; i++) {
        printf("|=======|====================|===============|\n");
        printf("|%-7s|%-20s|%-15s|\n", members[i].memberId, members[i].name, members[i].phone); 
    }
    printf("|=======|====================|===============|\n");
    printf("\n");
}

 void editMember(Member members[], int size) {
    char idToEdit[10];
    int foundIndex = -1;
    getchar();
    printf("Enter ID of member to edit: ");
    fgets(idToEdit, 10, stdin);
    idToEdit[strcspn(idToEdit, "\n")] = '\0';

    for (int i = 0; i < size; i++) {
        if (strcmp(members[i].memberId, idToEdit) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Member not found.\n");
        return;
    }else {
        printf("\n--- Current Book Information ---\n");
        printf("ID: %s\n", members[foundIndex].memberId);
        printf("Bookname: %s\n", members[foundIndex].name);
        printf("Phone: %s\n\n", members[foundIndex].phone);

        printf("--- Enter New Information ---\n");

       
        }


    printf("Enter new name (or press Enter to keep current): ");
    char newName[100];
    fgets(newName, 100, stdin);
    newName[strcspn(newName, "\n")] = '\0';
    if (strlen(newName) > 0) {
        strcpy(members[foundIndex].name, newName);
    }  else {
        printf("\n--- Current Book Information ---\n");
        printf("ID: %s\n", members[foundIndex].memberId);
        printf("Bookname: %s\n", members[foundIndex].name);
        printf("Phone: %.2f\n\n", members[foundIndex].phone);

        printf("--- Enter New Information ---\n");

       
        }

    printf("Enter new phone (or press Enter to keep current): ");
    char newPhone[20];
    fgets(newPhone, 20, stdin);
    newPhone[strcspn(newPhone, "\n")] = '\0';
    if (strlen(newPhone) > 0) {
        strcpy(members[foundIndex].phone, newPhone);
    }

    printf("Member information updated.\n");
}
void editMemberScreen(Member members[], int size) {
    int choice;
    do {
        printf("=====================================\n");
        editMember(members, size);
        printf("1. Back to menu\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice != 1) {
            printf("Invalid selection. Please try again!\n");
        }
    } while (choice != 1);
    
}
void loadMemberFile() {
    FILE *file = fopen("member.bin", "rb");
    if (file == NULL) {
        printf("No member data found. Starting with an empty member list.\n");
        numUser = 0;
        return;
    }
    numUser = fread(m01, sizeof(Member), 100, file);
    fclose(file);
}

void saveMemberFile() {
    FILE *file = fopen("member.bin", "wb");
    if (file == NULL) {
        printf("Error opening file (when saving members)!\n");
    } else {
        fwrite(m01, sizeof(Member), numUser, file);
        fclose(file);
        printf("Luu file member thanh cong\n");
    }
}
void searchMember(Member members[], int size) {
    char nameToSearch[100];
    int found = 0;

    getchar(); 
    printf("Enter name to search: ");
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    nameToSearch[strcspn(nameToSearch, "\n")] = '\0';

    
    for (int i = 0; nameToSearch[i]; i++) {
        nameToSearch[i] = tolower(nameToSearch[i]);
    }

    printf("\nSearch results for \"%s\":\n", nameToSearch);

    for (int i = 0; i < size; i++) {
        char memberNameLower[100];
        strcpy(memberNameLower, members[i].name);
       
        for (int j = 0; memberNameLower[j]; j++) {
            memberNameLower[j] = tolower(memberNameLower[j]);
        }
        if (strstr(memberNameLower, nameToSearch) != NULL) {
            if (!found) { 
               	 printf("|=======|====================|===============|\n");
			    printf("| ID      | Name                 | Phone             |\n");
                printf("|---------|----------------------|-------------------|\n");
            }
            printf("| %-7s | %-20s | %-17s |\n", members[i].memberId, members[i].name, members[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("No members with name containing \"%s\" found.\n\n", nameToSearch);
    } else {
        printf("|---------|----------------------|-------------------|\n"); 
    }
}
