void bn_mul_recursive(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, int n2,
BN_ULONG *t)
{
int n=n2/2;
int neg,zero,c1,c2;
BN_ULONG ln,lo,*p;
#ifdef BN_COUNT
printf(" bn_mul_recursive %d * %d\n",n2,n2);
#endif
if (n2 <= 8)
{
if (n2 == 8)
bn_mul_comba8(r,a,b);
else
bn_mul_normal(r,a,n2,b,n2);
return;
}
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
if (n == 8)
{
if (!zero)
bn_mul_comba8(&(t[n2]),t,&(t[n]));
else
memset(&(t[n2]),0,8*sizeof(BN_ULONG));
bn_mul_comba8(r,a,b);
bn_mul_comba8(&(r[n2]),&(a[n]),&(b[n]));
}
else
{
p= &(t[n2*2]);
if (!zero)
bn_mul_recursive(&(t[n2]),t,&(t[n]),n,p);
else
memset(&(t[n2]),0,n*sizeof(BN_ULONG));
bn_mul_recursive(r,a,b,n,p);
bn_mul_recursive(&(r[n2]),&(a[n]),&(b[n]),n,p);
}
c1=bn_add_words(t,r,&(r[n2]),n2);
if (neg)
{
c1-=bn_sub_words(&(t[n2]),t,&(t[n2]),n2);
}
else
{
c1+=bn_add_words(&(t[n2]),&(t[n2]),t,n2);
}
c1+=bn_add_words(&(r[n]),&(r[n]),&(t[n2]),n2);
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
void bn_mul_part_recursive(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, int tn,
int n, BN_ULONG *t)
{
int n2=n*2,i,j;
int c1;
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
memset(&(r[n2]),0,sizeof(BN_ULONG)*(tn*2));
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
c1=bn_add_words(t,r,&(r[n2]),n2);
c1-=bn_sub_words(&(t[n2]),t,&(t[n2]),n2);
c1+=bn_add_words(&(r[n]),&(r[n]),&(t[n2]),n2);
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
bn_sqr_comba4(r,a);
return;
}
else if (n2 == 8)
{
bn_sqr_comba8(r,a);
return;
}
if (n2 < BN_SQR_RECURSIVE_SIZE_NORMAL)
{
bn_sqr_normal(r,a,n2,t);
return;
abort();
}
c1=bn_cmp_words(a,&(a[n]),n);
zero=0;
if (c1 > 0)
bn_sub_words(t,a,&(a[n]),n);
else if (c1 < 0)
bn_sub_words(t,&(a[n]),a,n);
else
zero=1;
if (n == 8)
{
if (!zero)
bn_sqr_comba8(&(t[n2]),t);
else
memset(&(t[n2]),0,8*sizeof(BN_ULONG));
bn_sqr_comba8(r,a);
bn_sqr_comba8(&(r[n2]),&(a[n]));
}
else
{
p= &(t[n2*2]);
if (!zero)
bn_sqr_recursive(&(t[n2]),t,n,p);
else
memset(&(t[n2]),0,n*sizeof(BN_ULONG));
bn_sqr_recursive(r,a,n,p);
bn_sqr_recursive(&(r[n2]),&(a[n]),n,p);
}
c1=bn_add_words(t,r,&(r[n2]),n2);
c1-=bn_sub_words(&(t[n2]),t,&(t[n2]),n2);
c1+=bn_add_words(&(r[n]),&(r[n]),&(t[n2]),n2);
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
if (n > BN_MUL_LOW_RECURSIVE_SIZE_NORMAL)
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
int j,i,n,c1,c2;
int neg,oneg,zero;
BN_ULONG ll,lc,*lp,*mp;
#ifdef BN_COUNT
printf(" bn_mul_high %d * %d\n",n2,n2);
#endif
n=(n2+1)/2;
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
bn_mul_recursive(&(t[0]),&(r[0]),&(r[n]),n,&(t[n2]));
bn_mul_recursive(r,&(a[n]),&(b[n]),n,&(t[n2]));
if (l != NULL)
{
lp= &(t[n2+n]);
c1=bn_add_words(lp,&(r[0]),&(l[0]),n);
}
else
{
c1=0;
lp= &(r[0]);
}
if (neg)
neg=bn_sub_words(&(t[n2]),lp,&(t[0]),n);
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
c1= bn_add_words(lp,&(t[n2+n]),&(l[0]),n);
}
else
{
lp= &(t[n2+n]);
c1=0;
}
c1+=bn_add_words(&(t[n2]),lp, &(r[0]),n);
if (oneg)
c1-=bn_sub_words(&(t[n2]),&(t[n2]),&(t[0]),n);
else
c1+=bn_add_words(&(t[n2]),&(t[n2]),&(t[0]),n);
c2 =bn_add_words(&(r[0]),&(r[0]),&(t[n2+n]),n);
c2+=bn_add_words(&(r[0]),&(r[0]),&(r[n]),n);
if (oneg)
c2-=bn_sub_words(&(r[0]),&(r[0]),&(t[n]),n);
else
c2+=bn_add_words(&(r[0]),&(r[0]),&(t[n]),n);
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
