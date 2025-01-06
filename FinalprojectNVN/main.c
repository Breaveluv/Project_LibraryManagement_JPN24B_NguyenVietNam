#include "function.h"


int main(){
	int size1 =0;
	int *sizePtr1 = &size1;
	int size = 0;
	int *sizePtr = &size;
	char emailSign[100];
	char passSign[100]; 
	int choice;
	char *fileBook="book.bin";
	do{
		printf("***Library Management System Using C***\n\n");
		printf("          CHOOSE YOUR ROLE			\n");
		printf("       ======================  		\n");
		printf("       [1] Admin.                   \n");
		printf("       [0] Exit.                   \n");
		printf("       ======================  		\n");
		printf("       Enter the choice: ");
        scanf("%d", &choice);
        getchar();
		switch (choice){
			case 0:
				printf("Exit succesful !\n");
				break;
			
			case 1:
				loginAccount(emailSign, passSign, sizePtr);
				break;
			
	}
		
	}while (choice != 0);

	return 0;
}
