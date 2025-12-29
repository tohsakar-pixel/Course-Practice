#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) 
{
    return (*(unsigned int*)a - *(unsigned int*)b);
}

int main() 
{
    int n;
    scanf("%d", &n);
    int pos_monitor[n], pos_owerSocket[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pos_monitor[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pos_owerSocket[i]);
    }

    qsort(pos_monitor, n, sizeof(int), compare);
    qsort(pos_owerSocket, n, sizeof(int), compare);

    long long length = 0;
    for (int i = 0; i < n; i++)
    {
        int distance = abs(pos_owerSocket[i] - pos_monitor[i]);
        length += distance;
    }
    printf("%lld", length);
    return 0;   
}
