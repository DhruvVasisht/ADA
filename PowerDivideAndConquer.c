 #include <stdio.h>
 #include <time.h>
 long power(int a, int n)
    {
        if(n==0)
            return 1;
        if(a == 0)
            return 0;
        if(n%2 == 0) 
            return power(a*a, n/2);
        else
            return a * power(a*a, n/2);
    }


    int main(){
        clock_t t;
        t = clock();
        int a , n, result;
        printf("Enter the base: ");
        scanf("%d",&a);
        printf("Enter the power: ");
        scanf("%d",&n);
        result = power(a,n);
        t = clock() - t;
        double timeTaken = ((double)t)/CLOCKS_PER_SEC;
        printf("Result is: %d\n",result);
        printf("time taken: %f\n",timeTaken);
        return 0;
    }
