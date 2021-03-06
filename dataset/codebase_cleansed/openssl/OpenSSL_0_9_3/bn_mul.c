void bn_mul_recursive(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, int n2,
BN_ULONG *t)
{
int n=n2/2,c1,c2;
unsigned int neg,zero;
BN_ULONG ln,lo,*p;
#ifdef BN_COUNT
printf(" bn_mul_recursive %d * %d\n",n2,n2);
#endif
#ifdef BN_MUL_COMBA
if (n2 == 8)
{
bn_mul_comba8(r,a,b);
return;
}
#endif
if (n2 < BN_MUL_RECURSIVE_SIZE_NORMAL)
{
bn_mul_normal(r,a,n2,b,n2);
return;
}
c1=bn_cmp_words(a,&(a[n]),n);
c2=bn_cmp_words(&(b[n]),b,n);
zero=neg=0;
switch (c1*3+c2)
{
case -4:
bn_sub_words(t, &(a[n]),a, n);
bn_sub_words(&(t[n]),b, &(b[n]),n);
break;
case -3:
zero=1;
break;
case -2:
bn_sub_words(t, &(a[n]),a, n);
bn_sub_words(&(t[n]),&(b[n]),b, n);
neg=1;
break;
case -1:
case 0:
case 1:
zero=1;
break;
case 2:
bn_sub_words(t, a, &(a[n]),n);
bn_sub_words(&(t[n]),b, &(b[n]),n);
neg=1;
break;
case 3:
zero=1;
break;
case 4:
bn_sub_words(t, a, &(a[n]),n);
bn_sub_words(&(t[n]),&(b[n]),b, n);
break;
}
#ifdef BN_MUL_COMBA
if (n == 4)
{
if (!zero)
bn_mul_comba4(&(t[n2]),t,&(t[n]));
else
memset(&(t[n2]),0,8*sizeof(BN_ULONG));
bn_mul_comba4(r,a,b);
bn_mul_comba4(&(r[n2]),&(a[n]),&(b[n]));
}
else if (n == 8)
{
if (!zero)
bn_mul_comba8(&(t[n2]),t,&(t[n]));
else
memset(&(t[n2]),0,16*sizeof(BN_ULONG));
bn_mul_comba8(r,a,b);
bn_mul_comba8(&(r[n2]),&(a[n]),&(b[n]));
}
else
#endif
{
p= &(t[n2*2]);
if (!zero)
bn_mul_recursive(&(t[n2]),t,&(t[n]),n,p);
else
memset(&(t[n2]),0,n2*sizeof(BN_ULONG));
bn_mul_recursive(r,a,b,n,p);
bn_mul_recursive(&(r[n2]),&(a[n]),&(b[n]),n,p);
}
c1=(int)(bn_add_words(t,r,&(r[n2]),n2));
if (neg)
{
c1-=(int)(bn_sub_words(&(t[n2]),t,&(t[n2]),n2));
}
else
{
c1+=(int)(bn_add_words(&(t[n2]),&(t[n2]),t,n2));
}
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
void bn_mul_part_recursive(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, int tn,
int n, BN_ULONG *t)
{
int i,j,n2=n*2;
unsigned int c1;
BN_ULONG ln,lo,*p;
#ifdef BN_COUNT
printf(" bn_mul_part_recursive %d * %d\n",tn+n,tn+n);
#endif
if (n < 8)
{
i=tn+n;
bn_mul_normal(r,a,i,b,i);
return;
}
bn_sub_words(t, a, &(a[n]),n);
bn_sub_words(&(t[n]),b, &(b[n]),n);
if (n == 8)
{
bn_mul_comba8(&(t[n2]),t,&(t[n]));
bn_mul_comba8(r,a,b);
bn_mul_normal(&(r[n2]),&(a[n]),tn,&(b[n]),tn);
memset(&(r[n2+tn*2]),0,sizeof(BN_ULONG)*(n2-tn*2));
}
else
{
p= &(t[n2*2]);
bn_mul_recursive(&(t[n2]),t,&(t[n]),n,p);
bn_mul_recursive(r,a,b,n,p);
i=n/2;
j=tn-i;
if (j == 0)
{
bn_mul_recursive(&(r[n2]),&(a[n]),&(b[n]),i,p);
memset(&(r[n2+i*2]),0,sizeof(BN_ULONG)*(n2-i*2));
}
else if (j > 0)
{
bn_mul_part_recursive(&(r[n2]),&(a[n]),&(b[n]),
j,i,p);
memset(&(r[n2+tn*2]),0,
sizeof(BN_ULONG)*(n2-tn*2));
}
else
{
memset(&(r[n2]),0,sizeof(BN_ULONG)*n2);
if (tn < BN_MUL_RECURSIVE_SIZE_NORMAL)
{
bn_mul_normal(&(r[n2]),&(a[n]),tn,&(b[n]),tn);
}
else
{
for (;;)
{
i/=2;
if (i < tn)
{
bn_mul_part_recursive(&(r[n2]),
&(a[n]),&(b[n]),
tn-i,i,p);
break;
}
else if (i == tn)
{
bn_mul_recursive(&(r[n2]),
&(a[n]),&(b[n]),
i,p);
break;
}
}
}
}
}
c1=(int)(bn_add_words(t,r,&(r[n2]),n2));
c1-=(int)(bn_sub_words(&(t[n2]),t,&(t[n2]),n2));
c1+=(int)(bn_add_words(&(r[n]),&(r[n]),&(t[n2]),n2));
if (c1)
{
p= &(r[n+n2]);
lo= *p;
ln=(lo+c1)&BN_MASK2;
*p=ln;
if (ln < c1)
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
void bn_mul_low_recursive(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, int n2,
BN_ULONG *t)
{
int n=n2/2;
#ifdef BN_COUNT
printf(" bn_mul_low_recursive %d * %d\n",n2,n2);
#endif
bn_mul_recursive(r,a,b,n,&(t[0]));
if (n >= BN_MUL_LOW_RECURSIVE_SIZE_NORMAL)
{
bn_mul_low_recursive(&(t[0]),&(a[0]),&(b[n]),n,&(t[n2]));
bn_add_words(&(r[n]),&(r[n]),&(t[0]),n);
bn_mul_low_recursive(&(t[0]),&(a[n]),&(b[0]),n,&(t[n2]));
bn_add_words(&(r[n]),&(r[n]),&(t[0]),n);
}
else
{
bn_mul_low_normal(&(t[0]),&(a[0]),&(b[n]),n);
bn_mul_low_normal(&(t[n]),&(a[n]),&(b[0]),n);
bn_add_words(&(r[n]),&(r[n]),&(t[0]),n);
bn_add_words(&(r[n]),&(r[n]),&(t[n]),n);
}
}
void bn_mul_high(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, BN_ULONG *l, int n2,
BN_ULONG *t)
{
int i,n;
int c1,c2;
int neg,oneg,zero;
BN_ULONG ll,lc,*lp,*mp;
#ifdef BN_COUNT
printf(" bn_mul_high %d * %d\n",n2,n2);
#endif
n=n2/2;
neg=zero=0;
c1=bn_cmp_words(&(a[0]),&(a[n]),n);
c2=bn_cmp_words(&(b[n]),&(b[0]),n);
switch (c1*3+c2)
{
case -4:
bn_sub_words(&(r[0]),&(a[n]),&(a[0]),n);
bn_sub_words(&(r[n]),&(b[0]),&(b[n]),n);
break;
case -3:
zero=1;
break;
case -2:
bn_sub_words(&(r[0]),&(a[n]),&(a[0]),n);
bn_sub_words(&(r[n]),&(b[n]),&(b[0]),n);
neg=1;
break;
case -1:
case 0:
case 1:
zero=1;
break;
case 2:
bn_sub_words(&(r[0]),&(a[0]),&(a[n]),n);
bn_sub_words(&(r[n]),&(b[0]),&(b[n]),n);
neg=1;
break;
case 3:
zero=1;
break;
case 4:
bn_sub_words(&(r[0]),&(a[0]),&(a[n]),n);
bn_sub_words(&(r[n]),&(b[n]),&(b[0]),n);
break;
}
oneg=neg;
#ifdef BN_MUL_COMBA
if (n == 8)
{
bn_mul_comba8(&(t[0]),&(r[0]),&(r[n]));
bn_mul_comba8(r,&(a[n]),&(b[n]));
}
else
#endif
{
bn_mul_recursive(&(t[0]),&(r[0]),&(r[n]),n,&(t[n2]));
bn_mul_recursive(r,&(a[n]),&(b[n]),n,&(t[n2]));
}
if (l != NULL)
{
lp= &(t[n2+n]);
c1=(int)(bn_add_words(lp,&(r[0]),&(l[0]),n));
}
else
{
c1=0;
lp= &(r[0]);
}
if (neg)
neg=(int)(bn_sub_words(&(t[n2]),lp,&(t[0]),n));
else
{
bn_add_words(&(t[n2]),lp,&(t[0]),n);
neg=0;
}
if (l != NULL)
{
bn_sub_words(&(t[n2+n]),&(l[n]),&(t[n2]),n);
}
else
{
lp= &(t[n2+n]);
mp= &(t[n2]);
for (i=0; i<n; i++)
lp[i]=((~mp[i])+1)&BN_MASK2;
}
if (l != NULL)
{
lp= &(t[n2]);
c1= (int)(bn_add_words(lp,&(t[n2+n]),&(l[0]),n));
}
else
{
lp= &(t[n2+n]);
c1=0;
}
c1+=(int)(bn_add_words(&(t[n2]),lp, &(r[0]),n));
if (oneg)
c1-=(int)(bn_sub_words(&(t[n2]),&(t[n2]),&(t[0]),n));
else
c1+=(int)(bn_add_words(&(t[n2]),&(t[n2]),&(t[0]),n));
c2 =(int)(bn_add_words(&(r[0]),&(r[0]),&(t[n2+n]),n));
c2+=(int)(bn_add_words(&(r[0]),&(r[0]),&(r[n]),n));
if (oneg)
c2-=(int)(bn_sub_words(&(r[0]),&(r[0]),&(t[n]),n));
else
c2+=(int)(bn_add_words(&(r[0]),&(r[0]),&(t[n]),n));
if (c1 != 0)
{
i=0;
if (c1 > 0)
{
lc=c1;
do {
ll=(r[i]+lc)&BN_MASK2;
r[i++]=ll;
lc=(lc > ll);
} while (lc);
}
else
{
lc= -c1;
do {
ll=r[i];
r[i++]=(ll-lc)&BN_MASK2;
lc=(lc > ll);
} while (lc);
}
}
if (c2 != 0)
{
i=n;
if (c2 > 0)
{
lc=c2;
do {
ll=(r[i]+lc)&BN_MASK2;
r[i++]=ll;
lc=(lc > ll);
} while (lc);
}
else
{
lc= -c2;
do {
ll=r[i];
r[i++]=(ll-lc)&BN_MASK2;
lc=(lc > ll);
} while (lc);
}
}
}
int BN_mul(BIGNUM *r, BIGNUM *a, BIGNUM *b, BN_CTX *ctx)
{
int top,al,bl;
BIGNUM *rr;
#ifdef BN_RECURSION
BIGNUM *t;
int i,j,k;
#endif
#ifdef BN_COUNT
printf("BN_mul %d * %d\n",a->top,b->top);
#endif
bn_check_top(a);
bn_check_top(b);
bn_check_top(r);
al=a->top;
bl=b->top;
r->neg=a->neg^b->neg;
if ((al == 0) || (bl == 0))
{
BN_zero(r);
return(1);
}
top=al+bl;
if ((r == a) || (r == b))
rr= &(ctx->bn[ctx->tos+1]);
else
rr=r;
#if defined(BN_MUL_COMBA) || defined(BN_RECURSION)
if (al == bl)
{
# ifdef BN_MUL_COMBA
if (al == 8)
{
if (bn_wexpand(rr,16) == NULL) return(0);
r->top=16;
bn_mul_comba8(rr->d,a->d,b->d);
goto end;
}
else
# endif
#ifdef BN_RECURSION
if (al < BN_MULL_SIZE_NORMAL)
#endif
{
if (bn_wexpand(rr,top) == NULL) return(0);
rr->top=top;
bn_mul_normal(rr->d,a->d,al,b->d,bl);
goto end;
}
# ifdef BN_RECURSION
goto symetric;
# endif
}
#endif
#ifdef BN_RECURSION
else if ((al < BN_MULL_SIZE_NORMAL) || (bl < BN_MULL_SIZE_NORMAL))
{
if (bn_wexpand(rr,top) == NULL) return(0);
rr->top=top;
bn_mul_normal(rr->d,a->d,al,b->d,bl);
goto end;
}
else
{
i=(al-bl);
if ((i == 1) && !BN_get_flags(b,BN_FLG_STATIC_DATA))
{
bn_wexpand(b,al);
b->d[bl]=0;
bl++;
goto symetric;
}
else if ((i == -1) && !BN_get_flags(a,BN_FLG_STATIC_DATA))
{
bn_wexpand(a,bl);
a->d[al]=0;
al++;
goto symetric;
}
}
#endif
if (bn_wexpand(rr,top) == NULL) return(0);
rr->top=top;
bn_mul_normal(rr->d,a->d,al,b->d,bl);
#ifdef BN_RECURSION
if (0)
{
symetric:
j=BN_num_bits_word((BN_ULONG)al);
j=1<<(j-1);
k=j+j;
t= &(ctx->bn[ctx->tos]);
if (al == j)
{
bn_wexpand(t,k*2);
bn_wexpand(rr,k*2);
bn_mul_recursive(rr->d,a->d,b->d,al,t->d);
}
else
{
bn_wexpand(a,k);
bn_wexpand(b,k);
bn_wexpand(t,k*4);
bn_wexpand(rr,k*4);
for (i=a->top; i<k; i++)
a->d[i]=0;
for (i=b->top; i<k; i++)
b->d[i]=0;
bn_mul_part_recursive(rr->d,a->d,b->d,al-j,j,t->d);
}
rr->top=top;
}
#endif
#if defined(BN_MUL_COMBA) || defined(BN_RECURSION)
end:
#endif
bn_fix_top(rr);
if (r != rr) BN_copy(r,rr);
return(1);
}
void bn_mul_normal(BN_ULONG *r, BN_ULONG *a, int na, BN_ULONG *b, int nb)
{
BN_ULONG *rr;
#ifdef BN_COUNT
printf(" bn_mul_normal %d * %d\n",na,nb);
#endif
if (na < nb)
{
int itmp;
BN_ULONG *ltmp;
itmp=na; na=nb; nb=itmp;
ltmp=a; a=b; b=ltmp;
}
rr= &(r[na]);
rr[0]=bn_mul_words(r,a,na,b[0]);
for (;;)
{
if (--nb <= 0) return;
rr[1]=bn_mul_add_words(&(r[1]),a,na,b[1]);
if (--nb <= 0) return;
rr[2]=bn_mul_add_words(&(r[2]),a,na,b[2]);
if (--nb <= 0) return;
rr[3]=bn_mul_add_words(&(r[3]),a,na,b[3]);
if (--nb <= 0) return;
rr[4]=bn_mul_add_words(&(r[4]),a,na,b[4]);
rr+=4;
r+=4;
b+=4;
}
}
void bn_mul_low_normal(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, int n)
{
#ifdef BN_COUNT
printf(" bn_mul_low_normal %d * %d\n",n,n);
#endif
bn_mul_words(r,a,n,b[0]);
for (;;)
{
if (--n <= 0) return;
bn_mul_add_words(&(r[1]),a,n,b[1]);
if (--n <= 0) return;
bn_mul_add_words(&(r[2]),a,n,b[2]);
if (--n <= 0) return;
bn_mul_add_words(&(r[3]),a,n,b[3]);
if (--n <= 0) return;
bn_mul_add_words(&(r[4]),a,n,b[4]);
r+=4;
b+=4;
}
}
