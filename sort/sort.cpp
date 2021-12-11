#include "sort.h"
void swap(long* x, long* y){
    long t = *x;
    *x = *y;
    *y = t;
}
void bubble_sort(long* a,long n,long (*comp)(long,long)){
    for (long i=0;i<n-1;i++)
        for (long j=n-1;j>i;j--)
            if (comp(a[j],a[j-1]))
                swap(&a[j-1],&a[j]);
}
void insert_sort(long *a,long n,long(*comp)(long,long)){
    for (long i=1;i<n;i++){
        long j = i;
        while (j>0 && comp(a[j],a[j-1])){
            swap(&a[j],&a[j-1]);
            j--;
        }
    }
}
void select_sort(long *a,long n,long(*comp)(long,long)){
    for (long i=0;i<n-1;i++){
        long LowKey = a[i],LowInd = i;
        for (long j=i+1;j<n;j++)
            if (comp(a[j],LowKey)){
                LowInd = j;
                LowKey = a[j];
            }
        swap(&a[i],&a[LowInd]);
    }
}
void quick_sort(long L,long R,long *a,long(*comp)(long,long),long(*neg_comp)(long,long)){
    if (L<R){
        long i = L, j = R;
        long x = a[(L+R)/2];
        do{
            while (comp(a[i],x)) {
                i++;
            }
            while (neg_comp(a[j],x)){
                j--;
            }
            if (i <= j){
                swap(&a[i],&a[j]);
                i++;
                j--;
            }
        }while (i <= j);
        quick_sort(L,j,a,(*comp),(*neg_comp));
        quick_sort(i,R,a,(*comp),(*neg_comp));
    }
}


