#include#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ADMIN "HoaiNam"
#define PASSWORD "06082006"

void addBook(struct Book book01[],int *n);
void Savefile(struct Book book01[],int n);
void Load(struct Book book01[],int *n);
bool checkPass();
void showMenu();
void choose();
int main(int argc, char *argv[]){
	if (checkPass()) {
        printf("Login successful! Welcome to the system.\n");
        choose();
    } else {
        printf("Login failed! Incorrect username or password.\n");
    }
	return 0;
}
bool checkPass() {
	char inputAdmin[50];
	char inputPass[50];
	printf("=============================\n");
	printf(" Log in to your account: \n");
	printf("=============================\n");
	printf("Enter admin: ");
	scanf("%s",inputAdmin);
	printf("Enter password: ");
	scanf("%s",inputPass);
	if (strcmp(inputAdmin, ADMIN) == 0 && strcmp(inputPass, PASSWORD) == 0) {
        return true;
    } else {
        return false;
    }
 void showMenu(){

   
	printf("********Library Management System Using C********\n");
	printf("/n           MENU                      ");
	printf("/n      ============                    ");
	printf("[1] Addn a New Book                                  \n");
	printf("[2] Show all Book                                 ");
	printf("[3] Sreach A Book                                        ");
	printf("[4] Edit A Book                                            ");
	printf("[5] Delete A Book                                             ");
	printf("[6] Exit The Program                                              ");
	printf("	===========		");
	printf("Enter the choice: !");
}
void choice(){
	int choice;
	do{
	showMenu();
	printf("Enter your choice: ");
	scanf("%d ",&choice);
		switch (choice) {
			case 1: {
				addBook(book,&n);	
				break;
			}
			case 2:{
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				break;
			}
			case 5:{
				break;
			}
			case 6:{
				break;
			}
			default:
				printf("Lua chon khong hop le. Vui long nhap lai.\n");
			
	}while(choice!=6)
	
	return 0;
}
void addBook(struct Book book1[],int *n){
		printf("Moi ban nhap so luong sach : ");
 	scanf("%d",n);
 	getchar();
	 for(int i=0; i<*n;i++){
	 	book1[i].id++;
 	
 		printf("Moi ban nhap ten sach: \n");
 		fgets(book01[i].tille,sizeof(book01[i].tille),stdin);
 		book01[i].tille[strcspn(book01[i].tille,"\n")]= '0';
		printf("Moi ban nhap ten tac gia: \n");
		fgets(book01[i].author,sizeof(book01[i].author), stdin); 	
		book01[i].author[strcspn(book01[i].author, "\n")] = '\0';
 		Printf("moi ban nhap gia sach");
 		scanf("%f",&book01[i].price);
 		getchar();
 		printf("nhap the loai sach: ");
 		fgets(book01[i].category,sizeof(book01[i].category),stdin);
 		book01[i].category[strcspn(book01[i].category,"\n")] = '\0';
 	}
void printLibrary(struct Book book1[], int *n) {
    if (Book1[].id == 0) {
        printf("No books in the list.\n");
        return;
    }

    printf("\n+-----+---------------------------------------+---------------------------------------+------------+----------------------+\n");
    printf("| ID  | Title                                   | Author                                 | Price      | Category             |\n");
    printf("+-----+---------------------------------------+---------------------------------------+------------+----------------------+\n");

    for (int i = 0; i < book01[i].id; i++) {
        printf("| %-3d | %-37s | %-37s | %-10.2f | %-20s |\n", 
               books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
         printf("+-----+---------------------------------------+---------------------------------------+------------+----------------------+\n");

    }
}
}   

