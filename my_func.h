#include<stdio.h>
#ifndef MY_FUNC_H
#define MY_FUNC_H

int digits(int a);
double eps1(double *in,int size);
void mxv1(double *A,double *x,double *out,int size);
void mxm2(double *a,double *b,double *out,int size);
double max_d(double *in,int size);
int gcd(int a,int b);
double lcm(int a,int b);
void gauss(double *A,double *B,double *x,int n);
void array_init(double *out,int n);
void print_a1(double *out,int n);
void print_a2(double *out,int n);
void print_d(double a);
void print_i(int a);

#endif
