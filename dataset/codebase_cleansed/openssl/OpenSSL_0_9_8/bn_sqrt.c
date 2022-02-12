BIGNUM *BN_mod_sqrt(BIGNUM *in, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx)
{
BIGNUM *ret = in;
int err = 1;
int r;
BIGNUM *A, *b, *q, *t, *x, *y;
int e, i, j;
if (!BN_is_odd(p) || BN_abs_is_word(p, 1))
{
if (BN_abs_is_word(p, 2))
{
if (ret == NULL)
ret = BN_new();
if (ret == NULL)
goto end;
if (!BN_set_word(ret, BN_is_bit_set(a, 0)))
{
BN_free(ret);
return NULL;
}
bn_check_top(ret);
return ret;
}
BNerr(BN_F_BN_MOD_SQRT, BN_R_P_IS_NOT_PRIME);
return(NULL);
}
if (BN_is_zero(a) || BN_is_one(a))
{
if (ret == NULL)
ret = BN_new();
if (ret == NULL)
goto end;
if (!BN_set_word(ret, BN_is_one(a)))
{
BN_free(ret);
return NULL;
}
bn_check_top(ret);
return ret;
}
BN_CTX_start(ctx);
A = BN_CTX_get(ctx);
b = BN_CTX_get(ctx);
q = BN_CTX_get(ctx);
t = BN_CTX_get(ctx);
x = BN_CTX_get(ctx);
y = BN_CTX_get(ctx);
if (y == NULL) goto end;
if (ret == NULL)
ret = BN_new();
if (ret == NULL) goto end;
if (!BN_nnmod(A, a, p, ctx)) goto end;
e = 1;
while (!BN_is_bit_set(p, e))
e++;
if (e == 1)
{
if (!BN_rshift(q, p, 2)) goto end;
q->neg = 0;
if (!BN_add_word(q, 1)) goto end;
if (!BN_mod_exp(ret, A, q, p, ctx)) goto end;
err = 0;
goto vrfy;
}
if (e == 2)
{
if (!BN_mod_lshift1_quick(t, A, p)) goto end;
if (!BN_rshift(q, p, 3)) goto end;
q->neg = 0;
if (!BN_mod_exp(b, t, q, p, ctx)) goto end;
if (!BN_mod_sqr(y, b, p, ctx)) goto end;
if (!BN_mod_mul(t, t, y, p, ctx)) goto end;
if (!BN_sub_word(t, 1)) goto end;
if (!BN_mod_mul(x, A, b, p, ctx)) goto end;
if (!BN_mod_mul(x, x, t, p, ctx)) goto end;
if (!BN_copy(ret, x)) goto end;
err = 0;
goto vrfy;
}
if (!BN_copy(q, p)) goto end;
q->neg = 0;
i = 2;
do
{
if (i < 22)
{
if (!BN_set_word(y, i)) goto end;
}
else
{
if (!BN_pseudo_rand(y, BN_num_bits(p), 0, 0)) goto end;
if (BN_ucmp(y, p) >= 0)
{
if (!(p->neg ? BN_add : BN_sub)(y, y, p)) goto end;
}
if (BN_is_zero(y))
if (!BN_set_word(y, i)) goto end;
}
r = BN_kronecker(y, q, ctx);
if (r < -1) goto end;
if (r == 0)
{
BNerr(BN_F_BN_MOD_SQRT, BN_R_P_IS_NOT_PRIME);
goto end;
}
}
while (r == 1 && ++i < 82);
if (r != -1)
{
BNerr(BN_F_BN_MOD_SQRT, BN_R_TOO_MANY_ITERATIONS);
goto end;
}
if (!BN_rshift(q, q, e)) goto end;
if (!BN_mod_exp(y, y, q, p, ctx)) goto end;
if (BN_is_one(y))
{
BNerr(BN_F_BN_MOD_SQRT, BN_R_P_IS_NOT_PRIME);
goto end;
}
if (!BN_rshift1(t, q)) goto end;
if (BN_is_zero(t))
{
if (!BN_nnmod(t, A, p, ctx)) goto end;
if (BN_is_zero(t))
{
BN_zero(ret);
err = 0;
goto end;
}
else
if (!BN_one(x)) goto end;
}
else
{
if (!BN_mod_exp(x, A, t, p, ctx)) goto end;
if (BN_is_zero(x))
{
BN_zero(ret);
err = 0;
goto end;
}
}
if (!BN_mod_sqr(b, x, p, ctx)) goto end;
if (!BN_mod_mul(b, b, A, p, ctx)) goto end;
if (!BN_mod_mul(x, x, A, p, ctx)) goto end;
while (1)
{
if (BN_is_one(b))
{
if (!BN_copy(ret, x)) goto end;
err = 0;
goto vrfy;
}
i = 1;
if (!BN_mod_sqr(t, b, p, ctx)) goto end;
while (!BN_is_one(t))
{
i++;
if (i == e)
{
BNerr(BN_F_BN_MOD_SQRT, BN_R_NOT_A_SQUARE);
goto end;
}
if (!BN_mod_mul(t, t, t, p, ctx)) goto end;
}
if (!BN_copy(t, y)) goto end;
for (j = e - i - 1; j > 0; j--)
{
if (!BN_mod_sqr(t, t, p, ctx)) goto end;
}
if (!BN_mod_mul(y, t, t, p, ctx)) goto end;
if (!BN_mod_mul(x, x, t, p, ctx)) goto end;
if (!BN_mod_mul(b, b, y, p, ctx)) goto end;
e = i;
}
vrfy:
if (!err)
{
if (!BN_mod_sqr(x, ret, p, ctx))
err = 1;
if (!err && 0 != BN_cmp(x, A))
{
BNerr(BN_F_BN_MOD_SQRT, BN_R_NOT_A_SQUARE);
err = 1;
}
}
end:
if (err)
{
if (ret != NULL && ret != in)
{
BN_clear_free(ret);
}
ret = NULL;
}
BN_CTX_end(ctx);
bn_check_top(ret);
return ret;
}
