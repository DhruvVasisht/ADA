#include <stdio.h>

int BinarySearch(int a[],int fi,int li,int key){
    int middle;
    if(li>=fi){
        middle = (fi+li)/2;
        if(a[middle] == key){
            return middle;
        }
        if(a[middle]>key){
            return BinarySearch(a,fi,middle-1,key);

        }
        return BinarySearch(a,middle+1,li,key);
    }
    return -1;
}

int main(){
    int i,n,a[100],key;
    int fi=0,li,keyIndex;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    li = n-1;
     printf("Enter the elements of the array in sorted manner: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Element to be searched: ");
    scanf("%d",&key);
    keyIndex = BinarySearch(a,fi,li,key);
    if (keyIndex == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n",keyIndex);
    }

    return 0;
}
