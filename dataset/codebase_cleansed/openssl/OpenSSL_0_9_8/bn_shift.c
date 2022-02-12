int BN_lshift1(BIGNUM *r, const BIGNUM *a)
{
register BN_ULONG *ap,*rp,t,c;
int i;
bn_check_top(r);
bn_check_top(a);
if (r != a)
{
r->neg=a->neg;
if (bn_wexpand(r,a->top+1) == NULL) return(0);
r->top=a->top;
}
else
{
if (bn_wexpand(r,a->top+1) == NULL) return(0);
}
ap=a->d;
rp=r->d;
c=0;
for (i=0; i<a->top; i++)
{
t= *(ap++);
*(rp++)=((t<<1)|c)&BN_MASK2;
c=(t & BN_TBIT)?1:0;
}
if (c)
{
*rp=1;
r->top++;
}
bn_check_top(r);
return(1);
}
int BN_rshift1(BIGNUM *r, const BIGNUM *a)
{
BN_ULONG *ap,*rp,t,c;
int i;
bn_check_top(r);
bn_check_top(a);
if (BN_is_zero(a))
{
BN_zero(r);
return(1);
}
if (a != r)
{
if (bn_wexpand(r,a->top) == NULL) return(0);
r->top=a->top;
r->neg=a->neg;
}
ap=a->d;
rp=r->d;
c=0;
for (i=a->top-1; i>=0; i--)
{
t=ap[i];
rp[i]=((t>>1)&BN_MASK2)|c;
c=(t&1)?BN_TBIT:0;
}
bn_correct_top(r);
bn_check_top(r);
return(1);
}
int BN_lshift(BIGNUM *r, const BIGNUM *a, int n)
{
int i,nw,lb,rb;
BN_ULONG *t,*f;
BN_ULONG l;
bn_check_top(r);
bn_check_top(a);
r->neg=a->neg;
nw=n/BN_BITS2;
if (bn_wexpand(r,a->top+nw+1) == NULL) return(0);
lb=n%BN_BITS2;
rb=BN_BITS2-lb;
f=a->d;
t=r->d;
t[a->top+nw]=0;
if (lb == 0)
for (i=a->top-1; i>=0; i--)
t[nw+i]=f[i];
else
for (i=a->top-1; i>=0; i--)
{
l=f[i];
t[nw+i+1]|=(l>>rb)&BN_MASK2;
t[nw+i]=(l<<lb)&BN_MASK2;
}
memset(t,0,nw*sizeof(t[0]));
r->top=a->top+nw+1;
bn_correct_top(r);
bn_check_top(r);
return(1);
}
int BN_rshift(BIGNUM *r, const BIGNUM *a, int n)
{
int i,j,nw,lb,rb;
BN_ULONG *t,*f;
BN_ULONG l,tmp;
bn_check_top(r);
bn_check_top(a);
nw=n/BN_BITS2;
rb=n%BN_BITS2;
lb=BN_BITS2-rb;
if (nw > a->top || a->top == 0)
{
BN_zero(r);
return(1);
}
if (r != a)
{
r->neg=a->neg;
if (bn_wexpand(r,a->top-nw+1) == NULL) return(0);
}
else
{
if (n == 0)
return 1;
}
f= &(a->d[nw]);
t=r->d;
j=a->top-nw;
r->top=j;
if (rb == 0)
{
for (i=j; i != 0; i--)
*(t++)= *(f++);
}
else
{
l= *(f++);
for (i=j-1; i != 0; i--)
{
tmp =(l>>rb)&BN_MASK2;
l= *(f++);
*(t++) =(tmp|(l<<lb))&BN_MASK2;
}
*(t++) =(l>>rb)&BN_MASK2;
}
bn_correct_top(r);
bn_check_top(r);
return(1);
}
