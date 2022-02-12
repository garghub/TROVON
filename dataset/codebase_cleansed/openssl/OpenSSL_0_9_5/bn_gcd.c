int BN_gcd(BIGNUM *r, BIGNUM *in_a, BIGNUM *in_b, BN_CTX *ctx)
{
BIGNUM *a,*b,*t;
int ret=0;
bn_check_top(in_a);
bn_check_top(in_b);
BN_CTX_start(ctx);
a = BN_CTX_get(ctx);
b = BN_CTX_get(ctx);
if (a == NULL || b == NULL) goto err;
if (BN_copy(a,in_a) == NULL) goto err;
if (BN_copy(b,in_b) == NULL) goto err;
if (BN_cmp(a,b) < 0) { t=a; a=b; b=t; }
t=euclid(a,b);
if (t == NULL) goto err;
if (BN_copy(r,t) == NULL) goto err;
ret=1;
err:
BN_CTX_end(ctx);
return(ret);
}
static BIGNUM *euclid(BIGNUM *a, BIGNUM *b)
{
BIGNUM *t;
int shifts=0;
bn_check_top(a);
bn_check_top(b);
for (;;)
{
if (BN_is_zero(b))
break;
if (BN_is_odd(a))
{
if (BN_is_odd(b))
{
if (!BN_sub(a,a,b)) goto err;
if (!BN_rshift1(a,a)) goto err;
if (BN_cmp(a,b) < 0)
{ t=a; a=b; b=t; }
}
else
{
if (!BN_rshift1(b,b)) goto err;
if (BN_cmp(a,b) < 0)
{ t=a; a=b; b=t; }
}
}
else
{
if (BN_is_odd(b))
{
if (!BN_rshift1(a,a)) goto err;
if (BN_cmp(a,b) < 0)
{ t=a; a=b; b=t; }
}
else
{
if (!BN_rshift1(a,a)) goto err;
if (!BN_rshift1(b,b)) goto err;
shifts++;
}
}
}
if (shifts)
{
if (!BN_lshift(a,a,shifts)) goto err;
}
return(a);
err:
return(NULL);
}
BIGNUM *BN_mod_inverse(BIGNUM *in, BIGNUM *a, const BIGNUM *n, BN_CTX *ctx)
{
BIGNUM *A,*B,*X,*Y,*M,*D,*R=NULL;
BIGNUM *T,*ret=NULL;
int sign;
bn_check_top(a);
bn_check_top(n);
BN_CTX_start(ctx);
A = BN_CTX_get(ctx);
B = BN_CTX_get(ctx);
X = BN_CTX_get(ctx);
D = BN_CTX_get(ctx);
M = BN_CTX_get(ctx);
Y = BN_CTX_get(ctx);
if (Y == NULL) goto err;
if (in == NULL)
R=BN_new();
else
R=in;
if (R == NULL) goto err;
BN_zero(X);
BN_one(Y);
if (BN_copy(A,a) == NULL) goto err;
if (BN_copy(B,n) == NULL) goto err;
sign=1;
while (!BN_is_zero(B))
{
if (!BN_div(D,M,A,B,ctx)) goto err;
T=A;
A=B;
B=M;
if (!BN_mul(T,D,X,ctx)) goto err;
if (!BN_add(T,T,Y)) goto err;
M=Y;
Y=X;
X=T;
sign= -sign;
}
if (sign < 0)
{
if (!BN_sub(Y,n,Y)) goto err;
}
if (BN_is_one(A))
{ if (!BN_mod(R,Y,n,ctx)) goto err; }
else
{
BNerr(BN_F_BN_MOD_INVERSE,BN_R_NO_INVERSE);
goto err;
}
ret=R;
err:
if ((ret == NULL) && (in == NULL)) BN_free(R);
BN_CTX_end(ctx);
return(ret);
}
