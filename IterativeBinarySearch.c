#include <stdio.h>

int main(){
    int i,key,a[100],flag=0;
    int n,startIndex=0,lastIndex,keyIndex;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    lastIndex = n-1;
    printf("Enter the elements of the array in sorted manner: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("Element to be searched: ");
    scanf("%d",&key);
    while (startIndex <= lastIndex)
    {
     int middle = (startIndex+lastIndex)/2;   
     if (a[middle] == key)
     {
      flag = 1;
      keyIndex = middle; 
     }
      if(a[middle]<key)
     {
        startIndex = middle+1;
     }
     else 
     {
        lastIndex = middle-1;
     }
     
    }
    if (flag == 1){
        printf("Element found at %d\n",keyIndex);
    }
    else
    {
        printf("element not found\n");
    }
    
        return 0;
}
