#pragma once
void swap(long* x, long* y);
void bubble_sort(long *a,long n,long (*comp)(long,long));
void insert_sort(long *a,long n,long(*comp)(long,long));
void select_sort(long *a,long n,long(*comp)(long,long));
void quick_sort(long L,long R,long *a,long(*comp)(long,long),long(*neg_comp)(long,long));
