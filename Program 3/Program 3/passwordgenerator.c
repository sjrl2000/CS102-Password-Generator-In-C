// Student Name: Sebastián J. Rivera-Leal

// Program: Program 3 
#ifdef _MSC_FULL_VER 
#pragma warning( disable : 4996 ) 
#endif // _MSC_FULL_VER 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_password(int complexity, char password[], int password_length);

int main(void) {
	
	//Inputs
	char a;
	int batch = 0;
	int length = 0;
	int temp;

	//Function
	int complexity=0;
	char password[20];
	int password_length=0;

		//Prompt User
		printf("Hello & Welcome to El GENERATOR: A password generator!\n\tFor ALL your password needs!\n\n");
		printf("How to Use:\n\nThis program has 4 levels of complexity to choose from and you will be prompted once you start:\n\n");

		//Levels of Complexity
		printf(" Level 1: shall generate passwords containing only lowercase ASCII characters\n Level 2: includes Level 1 and contain at least 1 digit.\n Level 3: includes Level 1 and Level 2 and contain at least 1 uppercase ASCII character.\n Level 4: includes Level 1, Level 2, Level 3, and contains at least 1 punctuation character.\n\n");

		//How to Use
		printf("Commands to use the program:\n\nRemember Password length will be limited to a maximum of 20 characters!\n\n");
		printf("Input 'C' or 'c' to begin creating a password: \n\n\tOR \n\nInput 'B' or 'b' to create a batch of passwords: \n\n");
		printf("If in doubt input 'H' or 'h' to see the instructions again! If you wish to exit the program input 'Q' or 'q'.\n\n");
		scanf("%c", &a);

		while (getchar() != '\n');
		do {
			switch (a)
			{
			case 'C':
			case 'c':
				printf("You have chosen create a password!\n");
				
				generate_password(complexity, password, password_length);

				while (getchar() != '\n');
				break;
			case 'B':
			case 'b':
				printf("You have chosen create a batch of passwords!\n");
				printf("Enter the length of the password: ");
				scanf("%d", &length);
				printf("Enter amount of passwords you wish to generate:\n");
				scanf("%d", &batch);
				while (batch--)
				{
					temp = length;
					printf("\n");
					while (temp--) {
						putchar(rand() % 56 + 65);
						srand(rand());
					}
					printf("\n\n");
				}
					temp = length;
				while (getchar() != '\n');
				break;
			case'H':
			case'h':
				printf(" How to Use:\n\n This program has 4 levels of complexity to choose from and you will be prompted once you start:\n\n");
				printf(" Level 1: shall generate passwords containing only lowercase ASCII characters\n Level 2: includes Level 1 and contain at least 1 digit.\n Level 3: includes Level 1 and Level 2 and contain at least 1 uppercase ASCII character.\n Level 4: includes Level 1, Level 2, Level 3, and contains at least 1 punctuation character.\n\n");
				printf("Input 'C' or 'c' to begin creating a password: \n\n\tOR \n\nInput 'B' or 'b' to create a batch of passwords: \n\nIf in doubt input 'H' or 'h' to see the instructions again! If you wish to exit the program input 'Q' or 'q'.\n\n");
				while (getchar() != '\n');
				break;
			case'Q':
			case'q':
				exit(0);
				break;
			default:
				printf("That is not a valid input... Reiniciando...¡!?¿\n\n");
				break;
			}
		} while (a != 'q' && a != 'Q');
		while (getchar() != '\n');
	system("pause");
	return 0;
}

//Generate Password
void generate_password(int complexity, char password[], int password_length)
{
	srand((unsigned int)time(NULL));;

	//Alphabets
	char L1[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char L2[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
	char L3[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char L4[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','.',',','!','$','#','@','?','*','%','(',')','+','-','_','=' };

		
	int i=0;
	
	
	printf("Enter the desired password length: \n");
	scanf("%d", &password_length);
	printf("Enter level of complexity from 1-4: \n");
	scanf("%d", &complexity);

	if (complexity == 1)

		for (int i = 0; i < password_length; ++i)
		{
		
			password[i] = L1[rand() % 26];
			
		}

	else if (complexity == 2)
	
		
		for (int i = 0; i < password_length; ++i) 
		{
			
			password[i] = L2[rand() % 36];
			
		}
		
	
	if (complexity == 3)
	
		for (int i = 0; i < password_length; ++i) 
		{
			
			password[i] = L3[rand() % 62];
		
		}
		
	
	else if  (complexity == 4)
	
		
		for (int i = 0; i < password_length; ++i) 
		{
		
			password[i] = L4[rand() % 75];
			
		}

	printf("Password generated: ");
	for (int i = 0; i < password_length; ++i) { printf("%c", password[i]); }  printf("\n\n");
}
