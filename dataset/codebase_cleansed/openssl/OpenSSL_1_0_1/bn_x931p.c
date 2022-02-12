static int bn_x931_derive_pi(BIGNUM *pi, const BIGNUM *Xpi, BN_CTX *ctx,
BN_GENCB *cb)
{
int i = 0;
if (!BN_copy(pi, Xpi))
return 0;
if (!BN_is_odd(pi) && !BN_add_word(pi, 1))
return 0;
for(;;)
{
i++;
BN_GENCB_call(cb, 0, i);
if (BN_is_prime_fasttest_ex(pi, 27, ctx, 1, cb))
break;
if (!BN_add_word(pi, 2))
return 0;
}
BN_GENCB_call(cb, 2, i);
return 1;
}
int BN_X931_derive_prime_ex(BIGNUM *p, BIGNUM *p1, BIGNUM *p2,
const BIGNUM *Xp, const BIGNUM *Xp1, const BIGNUM *Xp2,
const BIGNUM *e, BN_CTX *ctx, BN_GENCB *cb)
{
int ret = 0;
BIGNUM *t, *p1p2, *pm1;
if (!BN_is_odd(e))
return 0;
BN_CTX_start(ctx);
if (!p1)
p1 = BN_CTX_get(ctx);
if (!p2)
p2 = BN_CTX_get(ctx);
t = BN_CTX_get(ctx);
p1p2 = BN_CTX_get(ctx);
pm1 = BN_CTX_get(ctx);
if (!bn_x931_derive_pi(p1, Xp1, ctx, cb))
goto err;
if (!bn_x931_derive_pi(p2, Xp2, ctx, cb))
goto err;
if (!BN_mul(p1p2, p1, p2, ctx))
goto err;
if (!BN_mod_inverse(p, p2, p1, ctx))
goto err;
if (!BN_mul(p, p, p2, ctx))
goto err;
if (!BN_mod_inverse(t, p1, p2, ctx))
goto err;
if (!BN_mul(t, t, p1, ctx))
goto err;
if (!BN_sub(p, p, t))
goto err;
if (p->neg && !BN_add(p, p, p1p2))
goto err;
if (!BN_mod_sub(p, p, Xp, p1p2, ctx))
goto err;
if (!BN_add(p, p, Xp))
goto err;
for (;;)
{
int i = 1;
BN_GENCB_call(cb, 0, i++);
if (!BN_copy(pm1, p))
goto err;
if (!BN_sub_word(pm1, 1))
goto err;
if (!BN_gcd(t, pm1, e, ctx))
goto err;
if (BN_is_one(t)
&& BN_is_prime_fasttest_ex(p, 50, ctx, 1, cb))
break;
if (!BN_add(p, p, p1p2))
goto err;
}
BN_GENCB_call(cb, 3, 0);
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
int BN_X931_generate_Xpq(BIGNUM *Xp, BIGNUM *Xq, int nbits, BN_CTX *ctx)
{
BIGNUM *t;
int i;
if ((nbits < 1024) || (nbits & 0xff))
return 0;
nbits >>= 1;
if (!BN_rand(Xp, nbits, 1, 0))
return 0;
BN_CTX_start(ctx);
t = BN_CTX_get(ctx);
for (i = 0; i < 1000; i++)
{
if (!BN_rand(Xq, nbits, 1, 0))
return 0;
BN_sub(t, Xp, Xq);
if (BN_num_bits(t) > (nbits - 100))
break;
}
BN_CTX_end(ctx);
if (i < 1000)
return 1;
return 0;
}
int BN_X931_generate_prime_ex(BIGNUM *p, BIGNUM *p1, BIGNUM *p2,
BIGNUM *Xp1, BIGNUM *Xp2,
const BIGNUM *Xp,
const BIGNUM *e, BN_CTX *ctx,
BN_GENCB *cb)
{
int ret = 0;
BN_CTX_start(ctx);
if (!Xp1)
Xp1 = BN_CTX_get(ctx);
if (!Xp2)
Xp2 = BN_CTX_get(ctx);
if (!BN_rand(Xp1, 101, 0, 0))
goto error;
if (!BN_rand(Xp2, 101, 0, 0))
goto error;
if (!BN_X931_derive_prime_ex(p, p1, p2, Xp, Xp1, Xp2, e, ctx, cb))
goto error;
ret = 1;
error:
BN_CTX_end(ctx);
return ret;
}
