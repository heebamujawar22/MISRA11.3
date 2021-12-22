
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef unsigned short uint16_t;

typedef unsigned int uint32_t;
struct Student
{
	char grade;
	int id;
}s1;
struct Item
{

	int price;
	char name[30];
};
int main() {

#pragma region thirtytwotosixteenbit

	uint16_t* ptr;
	int t;
	uint32_t noOfElements;
	printf("Enter the number of elements: ");
	scanf_s("%d", &noOfElements);

	// Memory allocation for noOfElements 


	 //uint32_t* ptr_32= (uint32_t*)malloc(noOfElements * sizeof(uint32_t));  
	 //ptr = (uint16_t*)ptr_32; //Non-compliant code trying to cast 32 bit-int pointer to 16 bit -int pointer

	//Compliant code
	ptr = (uint16_t*)malloc(noOfElements * sizeof(uint32_t));

	for (int i = 0; i < noOfElements; ++i) {
		printf("Enter element:\n");
		scanf_s("%d", (ptr + i));

	}

	printf("Displaying Elements:\n");
	for (int i = 0; i < noOfElements; ++i) {
		printf("%d\n", *(ptr + i));

	}

	free(ptr);

#pragma endregion  thirtytwotosixteenbit

#pragma region chartoint


	s1.grade = 'A';
	s1.id = 65;

	char* cptr = (char*)&s1.id; // Non-Compliant code
	 //Compliant code
   // char *cptr=(char *)&s1.grade;


	int* iptr = (int*)&s1.grade;  // Non-Compliant code
	//Compliant code
   // int *iptr=(int *)&s1.id;

	printf("Grade of student with id %d =  %c\n", *iptr, *cptr);

#pragma endregion chartoint

#pragma region structtoint
	struct Item item;
	item.price = 30000;
	char myItem[30] = "Book";
	strcpy_s(item.name, strlen(myItem) + 1, myItem);
	int* pricePointer = (int*)&item;      //non-compliant
	//compliant
	// int *pricePointer=(int*)&item.price; 
	printf("Price of %s is  %d ", item.name, *pricePointer);
#pragma endregion structtoint

	return 0;
}