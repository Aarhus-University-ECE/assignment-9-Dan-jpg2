#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x) //finding integer "x" in array "a" witht he length of "n"
{
    if(n > 0 && a[n-1] == x) //base case
    {
        return true;
    }
    else if (n>0 && a[n-1] != x) //recursive step
    {
        return search(a, n-1, x);
    }
    else if (n == 0) //base case 
    {
        return false;
    }
}