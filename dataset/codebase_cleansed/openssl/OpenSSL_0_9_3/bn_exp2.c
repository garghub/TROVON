int BN_mod_exp2_mont(BIGNUM *rr, BIGNUM *a1, BIGNUM *p1, BIGNUM *a2,
BIGNUM *p2, BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
int i,j,k,bits,bits1,bits2,ret=0,wstart,wend,window,xvalue,yvalue;
int start=1,ts=0,x,y;
BIGNUM *d,*aa1,*aa2,*r;
BIGNUM val[EXP2_TABLE_SIZE][EXP2_TABLE_SIZE];
BN_MONT_CTX *mont=NULL;
bn_check_top(a1);
bn_check_top(p1);
bn_check_top(a2);
bn_check_top(p2);
bn_check_top(m);
if (!(m->d[0] & 1))
{
BNerr(BN_F_BN_MOD_EXP_MONT,BN_R_CALLED_WITH_EVEN_MODULUS);
return(0);
}
d= &(ctx->bn[ctx->tos++]);
r= &(ctx->bn[ctx->tos++]);
bits1=BN_num_bits(p1);
bits2=BN_num_bits(p2);
if ((bits1 == 0) && (bits2 == 0))
{
BN_one(r);
return(1);
}
bits=(bits1 > bits2)?bits1:bits2;
if (in_mont != NULL)
mont=in_mont;
else
{
if ((mont=BN_MONT_CTX_new()) == NULL) goto err;
if (!BN_MONT_CTX_set(mont,m,ctx)) goto err;
}
BN_init(&(val[0][0]));
BN_init(&(val[1][1]));
BN_init(&(val[0][1]));
BN_init(&(val[1][0]));
ts=1;
if (BN_ucmp(a1,m) >= 0)
{
BN_mod(&(val[1][0]),a1,m,ctx);
aa1= &(val[1][0]);
}
else
aa1=a1;
if (BN_ucmp(a2,m) >= 0)
{
BN_mod(&(val[0][1]),a2,m,ctx);
aa2= &(val[0][1]);
}
else
aa2=a2;
if (!BN_to_montgomery(&(val[1][0]),aa1,mont,ctx)) goto err;
if (!BN_to_montgomery(&(val[0][1]),aa2,mont,ctx)) goto err;
if (!BN_mod_mul_montgomery(&(val[1][1]),
&(val[1][0]),&(val[0][1]),mont,ctx))
goto err;
#if 0
if (bits <= 20)
window=1;
else if (bits > 250)
window=5;
else if (bits >= 120)
window=4;
else
window=3;
#else
window=EXP2_TABLE_BITS;
#endif
k=1<<window;
for (x=0; x<k; x++)
{
if (x >= 2)
{
BN_init(&(val[x][0]));
BN_init(&(val[x][1]));
if (!BN_mod_mul_montgomery(&(val[x][0]),
&(val[1][0]),&(val[x-1][0]),mont,ctx)) goto err;
if (!BN_mod_mul_montgomery(&(val[x][1]),
&(val[1][0]),&(val[x-1][1]),mont,ctx)) goto err;
}
for (y=2; y<k; y++)
{
BN_init(&(val[x][y]));
if (!BN_mod_mul_montgomery(&(val[x][y]),
&(val[x][y-1]),&(val[0][1]),mont,ctx))
goto err;
}
}
ts=k;
start=1;
xvalue=0;
yvalue=0;
wstart=bits-1;
wend=0;
if (!BN_to_montgomery(r,BN_value_one(),mont,ctx)) goto err;
for (;;)
{
xvalue=BN_is_bit_set(p1,wstart);
yvalue=BN_is_bit_set(p2,wstart);
if (!(xvalue || yvalue))
{
if (!start)
{
if (!BN_mod_mul_montgomery(r,r,r,mont,ctx))
goto err;
}
wstart--;
if (wstart < 0) break;
continue;
}
j=wstart;
wend=0;
for (i=1; i<window; i++)
{
if (wstart-i < 0) break;
xvalue+=xvalue;
xvalue|=BN_is_bit_set(p1,wstart-i);
yvalue+=yvalue;
yvalue|=BN_is_bit_set(p2,wstart-i);
}
if (!start)
for (j=0; j<i; j++)
{
if (!BN_mod_mul_montgomery(r,r,r,mont,ctx))
goto err;
}
if (xvalue || yvalue)
{
if (!BN_mod_mul_montgomery(r,r,&(val[xvalue][yvalue]),
mont,ctx)) goto err;
}
wstart-=i;
start=0;
if (wstart < 0) break;
}
BN_from_montgomery(rr,r,mont,ctx);
ret=1;
err:
if ((in_mont == NULL) && (mont != NULL)) BN_MONT_CTX_free(mont);
ctx->tos-=2;
for (i=0; i<ts; i++)
{
for (j=0; j<ts; j++)
{
BN_clear_free(&(val[i][j]));
}
}
return(ret);
}
