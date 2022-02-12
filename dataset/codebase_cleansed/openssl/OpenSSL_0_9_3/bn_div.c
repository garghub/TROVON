int BN_div(BIGNUM *dv, BIGNUM *rm, BIGNUM *num, BIGNUM *divisor,
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
BN_ULONG q,n0,n1;
BN_ULONG l0;
wnum.d--; wnum.top++;
n0=wnump[0];
n1=wnump[-1];
if (n0 == d0)
q=BN_MASK2;
else
q=bn_div_words(n0,n1,d0);
{
#ifdef BN_LLONG
BN_ULLONG t1,t2,rem;
t1=((BN_ULLONG)n0<<BN_BITS2)|n1;
for (;;)
{
t2=(BN_ULLONG)d1*q;
rem=t1-(BN_ULLONG)q*d0;
if ((rem>>BN_BITS2) ||
(t2 <= ((BN_ULLONG)(rem<<BN_BITS2)+wnump[-2])))
break;
q--;
}
#else
BN_ULONG t1l,t1h,t2l,t2h,t3l,t3h,ql,qh,t3t;
t1h=n0;
t1l=n1;
for (;;)
{
t2l=LBITS(d1); t2h=HBITS(d1);
ql =LBITS(q); qh =HBITS(q);
mul64(t2l,t2h,ql,qh);
t3t=LBITS(d0); t3h=HBITS(d0);
mul64(t3t,t3h,ql,qh);
t3l=(t1l-t3t)&BN_MASK2;
if (t3l > t1l) t3h++;
t3h=(t1h-t3h)&BN_MASK2;
if (t3h) break;
if (t2h < t3l) break;
if ((t2h == t3l) && (t2l <= wnump[-2])) break;
q--;
}
#endif
}
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
int BN_mod(BIGNUM *rem, BIGNUM *m, BIGNUM *d, BN_CTX *ctx)
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
