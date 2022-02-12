void BN_set_params(int mult, int high, int low, int mont)
{
if (mult >= 0)
{
if (mult > (sizeof(int)*8)-1)
mult=sizeof(int)*8-1;
bn_limit_bits=mult;
bn_limit_num=1<<mult;
}
if (high >= 0)
{
if (high > (sizeof(int)*8)-1)
high=sizeof(int)*8-1;
bn_limit_bits_high=high;
bn_limit_num_high=1<<high;
}
if (low >= 0)
{
if (low > (sizeof(int)*8)-1)
low=sizeof(int)*8-1;
bn_limit_bits_low=low;
bn_limit_num_low=1<<low;
}
if (mont >= 0)
{
if (mont > (sizeof(int)*8)-1)
mont=sizeof(int)*8-1;
bn_limit_bits_mont=mont;
bn_limit_num_mont=1<<mont;
}
}
int BN_get_params(int which)
{
if (which == 0) return(bn_limit_bits);
else if (which == 1) return(bn_limit_bits_high);
else if (which == 2) return(bn_limit_bits_low);
else if (which == 3) return(bn_limit_bits_mont);
else return(0);
}
const BIGNUM *BN_value_one(void)
{
static BN_ULONG data_one=1L;
static BIGNUM const_one={&data_one,1,1,0};
return(&const_one);
}
char *BN_options(void)
{
static int init=0;
static char data[16];
if (!init)
{
init++;
#ifdef BN_LLONG
sprintf(data,"bn(%d,%d)",(int)sizeof(BN_ULLONG)*8,
(int)sizeof(BN_ULONG)*8);
#else
sprintf(data,"bn(%d,%d)",(int)sizeof(BN_ULONG)*8,
(int)sizeof(BN_ULONG)*8);
#endif
}
return(data);
}
int BN_num_bits_word(BN_ULONG l)
{
static const char bits[256]={
0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};
#if defined(SIXTY_FOUR_BIT_LONG)
if (l & 0xffffffff00000000L)
{
if (l & 0xffff000000000000L)
{
if (l & 0xff00000000000000L)
{
return(bits[(int)(l>>56)]+56);
}
else return(bits[(int)(l>>48)]+48);
}
else
{
if (l & 0x0000ff0000000000L)
{
return(bits[(int)(l>>40)]+40);
}
else return(bits[(int)(l>>32)]+32);
}
}
else
#else
#ifdef SIXTY_FOUR_BIT
if (l & 0xffffffff00000000LL)
{
if (l & 0xffff000000000000LL)
{
if (l & 0xff00000000000000LL)
{
return(bits[(int)(l>>56)]+56);
}
else return(bits[(int)(l>>48)]+48);
}
else
{
if (l & 0x0000ff0000000000LL)
{
return(bits[(int)(l>>40)]+40);
}
else return(bits[(int)(l>>32)]+32);
}
}
else
#endif
#endif
{
#if defined(THIRTY_TWO_BIT) || defined(SIXTY_FOUR_BIT) || defined(SIXTY_FOUR_BIT_LONG)
if (l & 0xffff0000L)
{
if (l & 0xff000000L)
return(bits[(int)(l>>24L)]+24);
else return(bits[(int)(l>>16L)]+16);
}
else
#endif
{
#if defined(SIXTEEN_BIT) || defined(THIRTY_TWO_BIT) || defined(SIXTY_FOUR_BIT) || defined(SIXTY_FOUR_BIT_LONG)
if (l & 0xff00L)
return(bits[(int)(l>>8)]+8);
else
#endif
return(bits[(int)(l )] );
}
}
}
int BN_num_bits(const BIGNUM *a)
{
BN_ULONG l;
int i;
bn_check_top(a);
if (a->top == 0) return(0);
l=a->d[a->top-1];
assert(l != 0);
i=(a->top-1)*BN_BITS2;
return(i+BN_num_bits_word(l));
}
void BN_clear_free(BIGNUM *a)
{
int i;
if (a == NULL) return;
if (a->d != NULL)
{
OPENSSL_cleanse(a->d,a->dmax*sizeof(a->d[0]));
if (!(BN_get_flags(a,BN_FLG_STATIC_DATA)))
OPENSSL_free(a->d);
}
i=BN_get_flags(a,BN_FLG_MALLOCED);
OPENSSL_cleanse(a,sizeof(BIGNUM));
if (i)
OPENSSL_free(a);
}
void BN_free(BIGNUM *a)
{
if (a == NULL) return;
if ((a->d != NULL) && !(BN_get_flags(a,BN_FLG_STATIC_DATA)))
OPENSSL_free(a->d);
a->flags|=BN_FLG_FREE;
if (a->flags & BN_FLG_MALLOCED)
OPENSSL_free(a);
}
void BN_init(BIGNUM *a)
{
memset(a,0,sizeof(BIGNUM));
}
BIGNUM *BN_new(void)
{
BIGNUM *ret;
if ((ret=(BIGNUM *)OPENSSL_malloc(sizeof(BIGNUM))) == NULL)
{
BNerr(BN_F_BN_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->flags=BN_FLG_MALLOCED;
ret->top=0;
ret->neg=0;
ret->dmax=0;
ret->d=NULL;
return(ret);
}
static BN_ULONG *bn_expand_internal(const BIGNUM *b, int words)
{
BN_ULONG *A,*a = NULL;
const BN_ULONG *B;
int i;
if (words > (INT_MAX/(4*BN_BITS2)))
{
BNerr(BN_F_BN_EXPAND_INTERNAL,BN_R_BIGNUM_TOO_LONG);
return NULL;
}
bn_check_top(b);
if (BN_get_flags(b,BN_FLG_STATIC_DATA))
{
BNerr(BN_F_BN_EXPAND_INTERNAL,BN_R_EXPAND_ON_STATIC_BIGNUM_DATA);
return(NULL);
}
a=A=(BN_ULONG *)OPENSSL_malloc(sizeof(BN_ULONG)*(words+1));
if (A == NULL)
{
BNerr(BN_F_BN_EXPAND_INTERNAL,ERR_R_MALLOC_FAILURE);
return(NULL);
}
#if 1
B=b->d;
if (B != NULL)
{
for (i=b->top>>2; i>0; i--,A+=4,B+=4)
{
BN_ULONG a0,a1,a2,a3;
a0=B[0]; a1=B[1]; a2=B[2]; a3=B[3];
A[0]=a0; A[1]=a1; A[2]=a2; A[3]=a3;
}
switch (b->top&3)
{
case 3: A[2]=B[2];
case 2: A[1]=B[1];
case 1: A[0]=B[0];
case 0:
;
}
}
A= &(a[b->top]);
for (i=(words - b->top)>>3; i>0; i--,A+=8)
{
A[0]=0; A[1]=0; A[2]=0; A[3]=0;
A[4]=0; A[5]=0; A[6]=0; A[7]=0;
}
for (i=(words - b->top)&7; i>0; i--,A++)
A[0]=0;
#else
memset(A,0,sizeof(BN_ULONG)*(words+1));
memcpy(A,b->d,sizeof(b->d[0])*b->top);
#endif
return(a);
}
BIGNUM *bn_dup_expand(const BIGNUM *b, int words)
{
BIGNUM *r = NULL;
if (words > b->dmax)
{
BN_ULONG *a = bn_expand_internal(b, words);
if (a)
{
r = BN_new();
if (r)
{
r->top = b->top;
r->dmax = words;
r->neg = b->neg;
r->d = a;
}
else
{
OPENSSL_free(a);
}
}
}
else
{
r = BN_dup(b);
}
return r;
}
BIGNUM *bn_expand2(BIGNUM *b, int words)
{
if (words > b->dmax)
{
BN_ULONG *a = bn_expand_internal(b, words);
if (a)
{
if (b->d)
OPENSSL_free(b->d);
b->d=a;
b->dmax=words;
}
else
b = NULL;
}
return b;
}
BIGNUM *BN_dup(const BIGNUM *a)
{
BIGNUM *r, *t;
if (a == NULL) return NULL;
bn_check_top(a);
t = BN_new();
if (t == NULL) return(NULL);
r = BN_copy(t, a);
if (r == NULL)
BN_free(t);
return r;
}
BIGNUM *BN_copy(BIGNUM *a, const BIGNUM *b)
{
int i;
BN_ULONG *A;
const BN_ULONG *B;
bn_check_top(b);
if (a == b) return(a);
if (bn_wexpand(a,b->top) == NULL) return(NULL);
#if 1
A=a->d;
B=b->d;
for (i=b->top>>2; i>0; i--,A+=4,B+=4)
{
BN_ULONG a0,a1,a2,a3;
a0=B[0]; a1=B[1]; a2=B[2]; a3=B[3];
A[0]=a0; A[1]=a1; A[2]=a2; A[3]=a3;
}
switch (b->top&3)
{
case 3: A[2]=B[2];
case 2: A[1]=B[1];
case 1: A[0]=B[0];
case 0: ;
}
#else
memcpy(a->d,b->d,sizeof(b->d[0])*b->top);
#endif
a->top=b->top;
if ((a->top == 0) && (a->d != NULL))
a->d[0]=0;
a->neg=b->neg;
return(a);
}
void BN_swap(BIGNUM *a, BIGNUM *b)
{
int flags_old_a, flags_old_b;
BN_ULONG *tmp_d;
int tmp_top, tmp_dmax, tmp_neg;
flags_old_a = a->flags;
flags_old_b = b->flags;
tmp_d = a->d;
tmp_top = a->top;
tmp_dmax = a->dmax;
tmp_neg = a->neg;
a->d = b->d;
a->top = b->top;
a->dmax = b->dmax;
a->neg = b->neg;
b->d = tmp_d;
b->top = tmp_top;
b->dmax = tmp_dmax;
b->neg = tmp_neg;
a->flags = (flags_old_a & BN_FLG_MALLOCED) | (flags_old_b & BN_FLG_STATIC_DATA);
b->flags = (flags_old_b & BN_FLG_MALLOCED) | (flags_old_a & BN_FLG_STATIC_DATA);
}
void BN_clear(BIGNUM *a)
{
if (a->d != NULL)
memset(a->d,0,a->dmax*sizeof(a->d[0]));
a->top=0;
a->neg=0;
}
BN_ULONG BN_get_word(const BIGNUM *a)
{
int i,n;
BN_ULONG ret=0;
n=BN_num_bytes(a);
if (n > sizeof(BN_ULONG))
return(BN_MASK2);
for (i=a->top-1; i>=0; i--)
{
#ifndef SIXTY_FOUR_BIT
ret<<=BN_BITS4;
ret<<=BN_BITS4;
#else
ret=0;
#endif
ret|=a->d[i];
}
return(ret);
}
int BN_set_word(BIGNUM *a, BN_ULONG w)
{
int i,n;
if (bn_expand(a,sizeof(BN_ULONG)*8) == NULL) return(0);
n=sizeof(BN_ULONG)/BN_BYTES;
a->neg=0;
a->top=0;
a->d[0]=(BN_ULONG)w&BN_MASK2;
if (a->d[0] != 0) a->top=1;
for (i=1; i<n; i++)
{
#ifndef SIXTY_FOUR_BIT
w>>=BN_BITS4;
w>>=BN_BITS4;
#else
w=0;
#endif
a->d[i]=(BN_ULONG)w&BN_MASK2;
if (a->d[i] != 0) a->top=i+1;
}
return(1);
}
BIGNUM *BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret)
{
unsigned int i,m;
unsigned int n;
BN_ULONG l;
if (ret == NULL) ret=BN_new();
if (ret == NULL) return(NULL);
l=0;
n=len;
if (n == 0)
{
ret->top=0;
return(ret);
}
if (bn_expand(ret,(int)(n+2)*8) == NULL)
return(NULL);
i=((n-1)/BN_BYTES)+1;
m=((n-1)%(BN_BYTES));
ret->top=i;
ret->neg=0;
while (n-- > 0)
{
l=(l<<8L)| *(s++);
if (m-- == 0)
{
ret->d[--i]=l;
l=0;
m=BN_BYTES-1;
}
}
bn_fix_top(ret);
return(ret);
}
int BN_bn2bin(const BIGNUM *a, unsigned char *to)
{
int n,i;
BN_ULONG l;
n=i=BN_num_bytes(a);
while (i-- > 0)
{
l=a->d[i/BN_BYTES];
*(to++)=(unsigned char)(l>>(8*(i%BN_BYTES)))&0xff;
}
return(n);
}
int BN_ucmp(const BIGNUM *a, const BIGNUM *b)
{
int i;
BN_ULONG t1,t2,*ap,*bp;
bn_check_top(a);
bn_check_top(b);
i=a->top-b->top;
if (i != 0) return(i);
ap=a->d;
bp=b->d;
for (i=a->top-1; i>=0; i--)
{
t1= ap[i];
t2= bp[i];
if (t1 != t2)
return(t1 > t2?1:-1);
}
return(0);
}
int BN_cmp(const BIGNUM *a, const BIGNUM *b)
{
int i;
int gt,lt;
BN_ULONG t1,t2;
if ((a == NULL) || (b == NULL))
{
if (a != NULL)
return(-1);
else if (b != NULL)
return(1);
else
return(0);
}
bn_check_top(a);
bn_check_top(b);
if (a->neg != b->neg)
{
if (a->neg)
return(-1);
else return(1);
}
if (a->neg == 0)
{ gt=1; lt= -1; }
else { gt= -1; lt=1; }
if (a->top > b->top) return(gt);
if (a->top < b->top) return(lt);
for (i=a->top-1; i>=0; i--)
{
t1=a->d[i];
t2=b->d[i];
if (t1 > t2) return(gt);
if (t1 < t2) return(lt);
}
return(0);
}
int BN_set_bit(BIGNUM *a, int n)
{
int i,j,k;
i=n/BN_BITS2;
j=n%BN_BITS2;
if (a->top <= i)
{
if (bn_wexpand(a,i+1) == NULL) return(0);
for(k=a->top; k<i+1; k++)
a->d[k]=0;
a->top=i+1;
}
a->d[i]|=(((BN_ULONG)1)<<j);
return(1);
}
int BN_clear_bit(BIGNUM *a, int n)
{
int i,j;
i=n/BN_BITS2;
j=n%BN_BITS2;
if (a->top <= i) return(0);
a->d[i]&=(~(((BN_ULONG)1)<<j));
bn_fix_top(a);
return(1);
}
int BN_is_bit_set(const BIGNUM *a, int n)
{
int i,j;
if (n < 0) return(0);
i=n/BN_BITS2;
j=n%BN_BITS2;
if (a->top <= i) return(0);
return((a->d[i]&(((BN_ULONG)1)<<j))?1:0);
}
int BN_mask_bits(BIGNUM *a, int n)
{
int b,w;
w=n/BN_BITS2;
b=n%BN_BITS2;
if (w >= a->top) return(0);
if (b == 0)
a->top=w;
else
{
a->top=w+1;
a->d[w]&= ~(BN_MASK2<<b);
}
bn_fix_top(a);
return(1);
}
int bn_cmp_words(const BN_ULONG *a, const BN_ULONG *b, int n)
{
int i;
BN_ULONG aa,bb;
aa=a[n-1];
bb=b[n-1];
if (aa != bb) return((aa > bb)?1:-1);
for (i=n-2; i>=0; i--)
{
aa=a[i];
bb=b[i];
if (aa != bb) return((aa > bb)?1:-1);
}
return(0);
}
int bn_cmp_part_words(const BN_ULONG *a, const BN_ULONG *b,
int cl, int dl)
{
int n,i;
n = cl-1;
if (dl < 0)
{
for (i=dl; i<0; i++)
{
if (b[n-i] != 0)
return -1;
}
}
if (dl > 0)
{
for (i=dl; i>0; i--)
{
if (a[n+i] != 0)
return 1;
}
}
return bn_cmp_words(a,b,cl);
}
