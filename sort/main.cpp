#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
typedef long (*cmp)(long,long);
long f(long a,long b){
    return a>b;
}
long f1(long a,long b){
    return a<b;
}
void clean(){
    while ( getchar() != '\n' );
}
int main(){
    srand(NULL);
    long* a;
    long* a1;
    long n;
    printf("number of elements: "); scanf("%ld",&n);clean();
    a=(long*)malloc(sizeof(long)*n);
    a1=(long*)malloc(sizeof(long)*n);
    char fl='\0';
    printf("do you prefer random fill y/n? ");scanf("%c",&fl);clean();
    if (fl=='y'){
        long l,r;
        printf("lower bound: ");scanf("%ld",&l);clean();
        printf("upper bound: ");scanf("%ld",&r);clean();
        for (long i=0;i<n;++i){
            a[i]=l+rand()%(r-l+1);
        }
    }else{
        for (long i=0;i<n;++i){
            printf("%ld elem: ",i);scanf("%ld",&a[i]);clean();
        }
    }
    int ch;
    int s;
    cmp func[2]={&f,&f1};
    for (int i=0;i<n;++i) a1[i]=a[i];
    printf("choose type of sort\n1 bubble sort\n2 insert sort\n3 select sort\n4 quick sort\n");scanf("%d",&ch);clean();
    printf("do you prefer ascending order 1/0 ");scanf("%d",&s);clean();
    if (ch==1){
        bubble_sort(a, n, func[s]);
    }else if (ch==2){
        insert_sort(a, n, func[s]);
    }else if (ch==3){
        select_sort(a, n, func[s]);
    }else if (ch==4){
        quick_sort(0, n-1, a, func[s], func[(s+1)%2]);
    }
    if (n>1500){
        printf("array is too big, no output(\n");
    }else{
        printf("default array:");for(int i=0;i<n;++i) printf("%ld ",a1[i]);
        printf("\nsorted array:");for(int i=0;i<n;++i) printf("%ld ",a[i]);
    }
}
