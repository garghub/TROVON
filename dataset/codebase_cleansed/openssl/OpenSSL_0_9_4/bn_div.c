int BN_div(BIGNUM *dv, BIGNUM *rm, const BIGNUM *num, const BIGNUM *divisor,
BN_CTX *ctx)
{
int norm_shift,i,j,loop;
BIGNUM *tmp,wnum,*snum,*sdiv,*res;
BN_ULONG *resp,*wnump;
BN_ULONG d0,d1;
int num_n,div_n;
bn_check_top(num);
bn_check_top(divisor);
if (BN_is_zero(divisor))
{
BNerr(BN_F_BN_DIV,BN_R_DIV_BY_ZERO);
return(0);
}
if (BN_ucmp(num,divisor) < 0)
{
if (rm != NULL)
{ if (BN_copy(rm,num) == NULL) return(0); }
if (dv != NULL) BN_zero(dv);
return(1);
}
tmp= &(ctx->bn[ctx->tos]);
tmp->neg=0;
snum= &(ctx->bn[ctx->tos+1]);
sdiv= &(ctx->bn[ctx->tos+2]);
if (dv == NULL)
res= &(ctx->bn[ctx->tos+3]);
else res=dv;
norm_shift=BN_BITS2-((BN_num_bits(divisor))%BN_BITS2);
BN_lshift(sdiv,divisor,norm_shift);
sdiv->neg=0;
norm_shift+=BN_BITS2;
BN_lshift(snum,num,norm_shift);
snum->neg=0;
div_n=sdiv->top;
num_n=snum->top;
loop=num_n-div_n;
BN_init(&wnum);
wnum.d= &(snum->d[loop]);
wnum.top= div_n;
wnum.max= snum->max+1;
d0=sdiv->d[div_n-1];
d1=(div_n == 1)?0:sdiv->d[div_n-2];
wnump= &(snum->d[num_n-1]);
res->neg= (num->neg^divisor->neg);
if (!bn_wexpand(res,(loop+1))) goto err;
res->top=loop;
resp= &(res->d[loop-1]);
if (!bn_wexpand(tmp,(div_n+1))) goto err;
if (BN_ucmp(&wnum,sdiv) >= 0)
{
if (!BN_usub(&wnum,&wnum,sdiv)) goto err;
*resp=1;
res->d[res->top-1]=1;
}
else
res->top--;
resp--;
for (i=0; i<loop-1; i++)
{
BN_ULONG q,l0;
#ifdef BN_DIV3W
q=bn_div_3_words(wnump,d0,d1);
#else
#if !defined(NO_ASM) && !defined(PEDANTIC)
# if defined(__GNUC__) && __GNUC__>=2
# if defined(__i386)
# define bn_div_words(n0,n1,d0) \
({ asm volatile ( \
"divl %4" \
: "=a"(q), "=d"(rem) \
: "a"(n1), "d"(n0), "g"(d0) \
: "cc"); \
q; \
})
# define REMINDER_IS_ALREADY_CALCULATED
# endif
# endif
#endif
BN_ULONG n0,n1,rem=0;
n0=wnump[0];
n1=wnump[-1];
if (n0 == d0)
q=BN_MASK2;
else
#if defined(BN_LLONG) && defined(BN_DIV2W) && !defined(bn_div_words)
q=((((BN_ULLONG)n0)<<BN_BITS2)|n1)/d0;
#else
q=bn_div_words(n0,n1,d0);
#endif
{
#ifdef BN_LLONG
BN_ULLONG t2;
#ifndef REMINDER_IS_ALREADY_CALCULATED
rem=(n1-q*d0)&BN_MASK2;
#endif
t2=(BN_ULLONG)d1*q;
for (;;)
{
if (t2 <= ((((BN_ULLONG)rem)<<BN_BITS2)|wnump[-2]))
break;
q--;
rem += d0;
if (rem < d0) break;
t2 -= d1;
}
#else
BN_ULONG t2l,t2h,ql,qh;
#ifndef REMINDER_IS_ALREADY_CALCULATED
rem=(n1-q*d0)&BN_MASK2;
#endif
t2l=LBITS(d1); t2h=HBITS(d1);
ql =LBITS(q); qh =HBITS(q);
mul64(t2l,t2h,ql,qh);
for (;;)
{
if ((t2h < rem) ||
((t2h == rem) && (t2l <= wnump[-2])))
break;
q--;
rem += d0;
if (rem < d0) break;
if (t2l < d1) t2h--; t2l -= d1;
}
#endif
}
#endif
wnum.d--; wnum.top++;
l0=bn_mul_words(tmp->d,sdiv->d,div_n,q);
tmp->d[div_n]=l0;
for (j=div_n+1; j>0; j--)
if (tmp->d[j-1]) break;
tmp->top=j;
j=wnum.top;
BN_sub(&wnum,&wnum,tmp);
snum->top=snum->top+wnum.top-j;
if (wnum.neg)
{
q--;
j=wnum.top;
BN_add(&wnum,&wnum,sdiv);
snum->top+=wnum.top-j;
}
*(resp--)=q;
wnump--;
}
if (rm != NULL)
{
BN_rshift(rm,snum,norm_shift);
rm->neg=num->neg;
}
return(1);
err:
return(0);
}
int BN_mod(BIGNUM *rem, const BIGNUM *m, const BIGNUM *d, BN_CTX *ctx)
{
#if 0
int i,nm,nd;
BIGNUM *dv;
if (BN_ucmp(m,d) < 0)
return((BN_copy(rem,m) == NULL)?0:1);
dv= &(ctx->bn[ctx->tos]);
if (!BN_copy(rem,m)) return(0);
nm=BN_num_bits(rem);
nd=BN_num_bits(d);
if (!BN_lshift(dv,d,nm-nd)) return(0);
for (i=nm-nd; i>=0; i--)
{
if (BN_cmp(rem,dv) >= 0)
{
if (!BN_sub(rem,rem,dv)) return(0);
}
if (!BN_rshift1(dv,dv)) return(0);
}
return(1);
#else
return(BN_div(NULL,rem,m,d,ctx));
#endif
}
