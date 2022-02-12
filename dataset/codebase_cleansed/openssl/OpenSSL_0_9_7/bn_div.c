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
BN_CTX_start(ctx);
tmp=BN_CTX_get(ctx);
snum=BN_CTX_get(ctx);
sdiv=BN_CTX_get(ctx);
if (dv == NULL)
res=BN_CTX_get(ctx);
else res=dv;
if (sdiv == NULL || res == NULL) goto err;
tmp->neg=0;
norm_shift=BN_BITS2-((BN_num_bits(divisor))%BN_BITS2);
if (!(BN_lshift(sdiv,divisor,norm_shift))) goto err;
sdiv->neg=0;
norm_shift+=BN_BITS2;
if (!(BN_lshift(snum,num,norm_shift))) goto err;
snum->neg=0;
div_n=sdiv->top;
num_n=snum->top;
loop=num_n-div_n;
BN_init(&wnum);
wnum.d= &(snum->d[loop]);
wnum.top= div_n;
wnum.dmax= snum->dmax+1;
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
if (res->top == 0)
res->neg = 0;
resp--;
for (i=0; i<loop-1; i++)
{
BN_ULONG q,l0;
#if defined(BN_DIV3W) && !defined(OPENSSL_NO_ASM)
BN_ULONG bn_div_3_words(BN_ULONG*,BN_ULONG,BN_ULONG);
q=bn_div_3_words(wnump,d1,d0);
#else
BN_ULONG n0,n1,rem=0;
n0=wnump[0];
n1=wnump[-1];
if (n0 == d0)
q=BN_MASK2;
else
{
#ifdef BN_LLONG
BN_ULLONG t2;
#if defined(BN_LLONG) && defined(BN_DIV2W) && !defined(bn_div_words)
q=(BN_ULONG)(((((BN_ULLONG)n0)<<BN_BITS2)|n1)/d0);
#else
q=bn_div_words(n0,n1,d0);
#ifdef BN_DEBUG_LEVITTE
fprintf(stderr,"DEBUG: bn_div_words(0x%08X,0x%08X,0x%08\
X) -> 0x%08X\n",
n0, n1, d0, q);
#endif
#endif
#ifndef REMAINDER_IS_ALREADY_CALCULATED
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
q=bn_div_words(n0,n1,d0);
#ifdef BN_DEBUG_LEVITTE
fprintf(stderr,"DEBUG: bn_div_words(0x%08X,0x%08X,0x%08\
X) -> 0x%08X\n",
n0, n1, d0, q);
#endif
#ifndef REMAINDER_IS_ALREADY_CALCULATED
rem=(n1-q*d0)&BN_MASK2;
#endif
#if defined(BN_UMULT_LOHI)
BN_UMULT_LOHI(t2l,t2h,d1,q);
#elif defined(BN_UMULT_HIGH)
t2l = d1 * q;
t2h = BN_UMULT_HIGH(d1,q);
#else
t2l=LBITS(d1); t2h=HBITS(d1);
ql =LBITS(q); qh =HBITS(q);
mul64(t2l,t2h,ql,qh);
#endif
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
l0=bn_mul_words(tmp->d,sdiv->d,div_n,q);
wnum.d--; wnum.top++;
tmp->d[div_n]=l0;
for (j=div_n+1; j>0; j--)
if (tmp->d[j-1]) break;
tmp->top=j;
j=wnum.top;
if (!BN_sub(&wnum,&wnum,tmp)) goto err;
snum->top=snum->top+wnum.top-j;
if (wnum.neg)
{
q--;
j=wnum.top;
if (!BN_add(&wnum,&wnum,sdiv)) goto err;
snum->top+=wnum.top-j;
}
*(resp--)=q;
wnump--;
}
if (rm != NULL)
{
int neg = num->neg;
BN_rshift(rm,snum,norm_shift);
if (!BN_is_zero(rm))
rm->neg = neg;
}
BN_CTX_end(ctx);
return(1);
err:
BN_CTX_end(ctx);
return(0);
}
