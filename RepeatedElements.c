#include <stdio.h>

#define MAX_SIZE 10000 

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int hashtable[MAX_SIZE] = {0}; 

    printf("Repeated elements in the array: ");
    for(int i = 0; i < size; i++) {
        if(hashtable[arr[i]] == 1) {
            printf("%d ", arr[i]);
        } else {
            hashtable[arr[i]] = 1;
        }
    }

    return 0;
}