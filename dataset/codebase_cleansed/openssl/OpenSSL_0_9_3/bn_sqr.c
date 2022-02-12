int BN_sqr(BIGNUM *r, BIGNUM *a, BN_CTX *ctx)
{
int max,al;
BIGNUM *tmp,*rr;
#ifdef BN_COUNT
printf("BN_sqr %d * %d\n",a->top,a->top);
#endif
bn_check_top(a);
tmp= &(ctx->bn[ctx->tos]);
rr=(a != r)?r: (&ctx->bn[ctx->tos+1]);
al=a->top;
if (al <= 0)
{
r->top=0;
return(1);
}
max=(al+al);
if (bn_wexpand(rr,max+1) == NULL) return(0);
r->neg=0;
if (al == 4)
{
#ifndef BN_SQR_COMBA
BN_ULONG t[8];
bn_sqr_normal(rr->d,a->d,4,t);
#else
bn_sqr_comba4(rr->d,a->d);
#endif
}
else if (al == 8)
{
#ifndef BN_SQR_COMBA
BN_ULONG t[16];
bn_sqr_normal(rr->d,a->d,8,t);
#else
bn_sqr_comba8(rr->d,a->d);
#endif
}
else
{
#if defined(BN_RECURSION)
if (al < BN_SQR_RECURSIVE_SIZE_NORMAL)
{
BN_ULONG t[BN_SQR_RECURSIVE_SIZE_NORMAL*2];
bn_sqr_normal(rr->d,a->d,al,t);
}
else
{
int j,k;
j=BN_num_bits_word((BN_ULONG)al);
j=1<<(j-1);
k=j+j;
if (al == j)
{
if (bn_wexpand(a,k*2) == NULL) return(0);
if (bn_wexpand(tmp,k*2) == NULL) return(0);
bn_sqr_recursive(rr->d,a->d,al,tmp->d);
}
else
{
if (bn_wexpand(tmp,max) == NULL) return(0);
bn_sqr_normal(rr->d,a->d,al,tmp->d);
}
}
#else
if (bn_wexpand(tmp,max) == NULL) return(0);
bn_sqr_normal(rr->d,a->d,al,tmp->d);
#endif
}
rr->top=max;
if ((max > 0) && (rr->d[max-1] == 0)) rr->top--;
if (rr != r) BN_copy(r,rr);
return(1);
}
void bn_sqr_normal(BN_ULONG *r, BN_ULONG *a, int n, BN_ULONG *tmp)
{
int i,j,max;
BN_ULONG *ap,*rp;
max=n*2;
ap=a;
rp=r;
rp[0]=rp[max-1]=0;
rp++;
j=n;
if (--j > 0)
{
ap++;
rp[j]=bn_mul_words(rp,ap,j,ap[-1]);
rp+=2;
}
for (i=n-2; i>0; i--)
{
j--;
ap++;
rp[j]=bn_mul_add_words(rp,ap,j,ap[-1]);
rp+=2;
}
bn_add_words(r,r,r,max);
bn_sqr_words(tmp,a,n);
bn_add_words(r,r,tmp,max);
}
void bn_sqr_recursive(BN_ULONG *r, BN_ULONG *a, int n2, BN_ULONG *t)
{
int n=n2/2;
int zero,c1;
BN_ULONG ln,lo,*p;
#ifdef BN_COUNT
printf(" bn_sqr_recursive %d * %d\n",n2,n2);
#endif
if (n2 == 4)
{
#ifndef BN_SQR_COMBA
bn_sqr_normal(r,a,4,t);
#else
bn_sqr_comba4(r,a);
#endif
return;
}
else if (n2 == 8)
{
#ifndef BN_SQR_COMBA
bn_sqr_normal(r,a,8,t);
#else
bn_sqr_comba8(r,a);
#endif
return;
}
if (n2 < BN_SQR_RECURSIVE_SIZE_NORMAL)
{
bn_sqr_normal(r,a,n2,t);
return;
}
c1=bn_cmp_words(a,&(a[n]),n);
zero=0;
if (c1 > 0)
bn_sub_words(t,a,&(a[n]),n);
else if (c1 < 0)
bn_sub_words(t,&(a[n]),a,n);
else
zero=1;
p= &(t[n2*2]);
if (!zero)
bn_sqr_recursive(&(t[n2]),t,n,p);
else
memset(&(t[n2]),0,n*sizeof(BN_ULONG));
bn_sqr_recursive(r,a,n,p);
bn_sqr_recursive(&(r[n2]),&(a[n]),n,p);
c1=(int)(bn_add_words(t,r,&(r[n2]),n2));
c1-=(int)(bn_sub_words(&(t[n2]),t,&(t[n2]),n2));
c1+=(int)(bn_add_words(&(r[n]),&(r[n]),&(t[n2]),n2));
if (c1)
{
p= &(r[n+n2]);
lo= *p;
ln=(lo+c1)&BN_MASK2;
*p=ln;
if (ln < (BN_ULONG)c1)
{
do {
p++;
lo= *p;
ln=(lo+1)&BN_MASK2;
*p=ln;
} while (ln == 0);
}
}
}
