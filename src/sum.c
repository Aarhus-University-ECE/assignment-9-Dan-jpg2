#include "sum.h"

int sum(int a[], int n) //returning sum of the array a[0..n-1] with recurssion
{
    if (n <= 0) //base case
        return 0;
    return sum(a, n-1) + a[n-1]; //recursive step
}