
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short uint16_t;

typedef unsigned int uint32_t;

int main() {
    uint16_t* ptr;
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

    return 0;
}