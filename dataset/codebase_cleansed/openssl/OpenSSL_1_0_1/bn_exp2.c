int BN_mod_exp2_mont(BIGNUM *rr, const BIGNUM *a1, const BIGNUM *p1,
const BIGNUM *a2, const BIGNUM *p2, const BIGNUM *m,
BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
int i,j,bits,b,bits1,bits2,ret=0,wpos1,wpos2,window1,window2,wvalue1,wvalue2;
int r_is_one=1;
BIGNUM *d,*r;
const BIGNUM *a_mod_m;
BIGNUM *val1[TABLE_SIZE], *val2[TABLE_SIZE];
BN_MONT_CTX *mont=NULL;
bn_check_top(a1);
bn_check_top(p1);
bn_check_top(a2);
bn_check_top(p2);
bn_check_top(m);
if (!(m->d[0] & 1))
{
BNerr(BN_F_BN_MOD_EXP2_MONT,BN_R_CALLED_WITH_EVEN_MODULUS);
return(0);
}
bits1=BN_num_bits(p1);
bits2=BN_num_bits(p2);
if ((bits1 == 0) && (bits2 == 0))
{
ret = BN_one(rr);
return ret;
}
bits=(bits1 > bits2)?bits1:bits2;
BN_CTX_start(ctx);
d = BN_CTX_get(ctx);
r = BN_CTX_get(ctx);
val1[0] = BN_CTX_get(ctx);
val2[0] = BN_CTX_get(ctx);
if(!d || !r || !val1[0] || !val2[0]) goto err;
if (in_mont != NULL)
mont=in_mont;
else
{
if ((mont=BN_MONT_CTX_new()) == NULL) goto err;
if (!BN_MONT_CTX_set(mont,m,ctx)) goto err;
}
window1 = BN_window_bits_for_exponent_size(bits1);
window2 = BN_window_bits_for_exponent_size(bits2);
if (a1->neg || BN_ucmp(a1,m) >= 0)
{
if (!BN_mod(val1[0],a1,m,ctx))
goto err;
a_mod_m = val1[0];
}
else
a_mod_m = a1;
if (BN_is_zero(a_mod_m))
{
BN_zero(rr);
ret = 1;
goto err;
}
if (!BN_to_montgomery(val1[0],a_mod_m,mont,ctx)) goto err;
if (window1 > 1)
{
if (!BN_mod_mul_montgomery(d,val1[0],val1[0],mont,ctx)) goto err;
j=1<<(window1-1);
for (i=1; i<j; i++)
{
if(((val1[i] = BN_CTX_get(ctx)) == NULL) ||
!BN_mod_mul_montgomery(val1[i],val1[i-1],
d,mont,ctx))
goto err;
}
}
if (a2->neg || BN_ucmp(a2,m) >= 0)
{
if (!BN_mod(val2[0],a2,m,ctx))
goto err;
a_mod_m = val2[0];
}
else
a_mod_m = a2;
if (BN_is_zero(a_mod_m))
{
BN_zero(rr);
ret = 1;
goto err;
}
if (!BN_to_montgomery(val2[0],a_mod_m,mont,ctx)) goto err;
if (window2 > 1)
{
if (!BN_mod_mul_montgomery(d,val2[0],val2[0],mont,ctx)) goto err;
j=1<<(window2-1);
for (i=1; i<j; i++)
{
if(((val2[i] = BN_CTX_get(ctx)) == NULL) ||
!BN_mod_mul_montgomery(val2[i],val2[i-1],
d,mont,ctx))
goto err;
}
}
r_is_one=1;
wvalue1=0;
wvalue2=0;
wpos1=0;
wpos2=0;
if (!BN_to_montgomery(r,BN_value_one(),mont,ctx)) goto err;
for (b=bits-1; b>=0; b--)
{
if (!r_is_one)
{
if (!BN_mod_mul_montgomery(r,r,r,mont,ctx))
goto err;
}
if (!wvalue1)
if (BN_is_bit_set(p1, b))
{
i = b-window1+1;
while (!BN_is_bit_set(p1, i))
i++;
wpos1 = i;
wvalue1 = 1;
for (i = b-1; i >= wpos1; i--)
{
wvalue1 <<= 1;
if (BN_is_bit_set(p1, i))
wvalue1++;
}
}
if (!wvalue2)
if (BN_is_bit_set(p2, b))
{
i = b-window2+1;
while (!BN_is_bit_set(p2, i))
i++;
wpos2 = i;
wvalue2 = 1;
for (i = b-1; i >= wpos2; i--)
{
wvalue2 <<= 1;
if (BN_is_bit_set(p2, i))
wvalue2++;
}
}
if (wvalue1 && b == wpos1)
{
if (!BN_mod_mul_montgomery(r,r,val1[wvalue1>>1],mont,ctx))
goto err;
wvalue1 = 0;
r_is_one = 0;
}
if (wvalue2 && b == wpos2)
{
if (!BN_mod_mul_montgomery(r,r,val2[wvalue2>>1],mont,ctx))
goto err;
wvalue2 = 0;
r_is_one = 0;
}
}
if (!BN_from_montgomery(rr,r,mont,ctx))
goto err;
ret=1;
err:
if ((in_mont == NULL) && (mont != NULL)) BN_MONT_CTX_free(mont);
BN_CTX_end(ctx);
bn_check_top(rr);
return(ret);
}
