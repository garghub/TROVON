int DH_check(const DH *dh, int *ret)
{
int ok = 0;
BN_CTX *ctx = NULL;
BN_ULONG l;
BIGNUM *t1 = NULL, *t2 = NULL;
*ret = 0;
ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
BN_CTX_start(ctx);
t1 = BN_CTX_get(ctx);
if (t1 == NULL)
goto err;
t2 = BN_CTX_get(ctx);
if (t2 == NULL)
goto err;
if (dh->q) {
if (BN_cmp(dh->g, BN_value_one()) <= 0)
*ret |= DH_NOT_SUITABLE_GENERATOR;
else if (BN_cmp(dh->g, dh->p) >= 0)
*ret |= DH_NOT_SUITABLE_GENERATOR;
else {
if (!BN_mod_exp(t1, dh->g, dh->q, dh->p, ctx))
goto err;
if (!BN_is_one(t1))
*ret |= DH_NOT_SUITABLE_GENERATOR;
}
if (!BN_is_prime_ex(dh->q, BN_prime_checks, ctx, NULL))
*ret |= DH_CHECK_Q_NOT_PRIME;
if (!BN_div(t1, t2, dh->p, dh->q, ctx))
goto err;
if (!BN_is_one(t2))
*ret |= DH_CHECK_INVALID_Q_VALUE;
if (dh->j && BN_cmp(dh->j, t1))
*ret |= DH_CHECK_INVALID_J_VALUE;
} else if (BN_is_word(dh->g, DH_GENERATOR_2)) {
l = BN_mod_word(dh->p, 24);
if (l != 11)
*ret |= DH_NOT_SUITABLE_GENERATOR;
}
#if 0
else if (BN_is_word(dh->g, DH_GENERATOR_3)) {
l = BN_mod_word(dh->p, 12);
if (l != 5)
*ret |= DH_NOT_SUITABLE_GENERATOR;
}
#endif
else if (BN_is_word(dh->g, DH_GENERATOR_5)) {
l = BN_mod_word(dh->p, 10);
if ((l != 3) && (l != 7))
*ret |= DH_NOT_SUITABLE_GENERATOR;
} else
*ret |= DH_UNABLE_TO_CHECK_GENERATOR;
if (!BN_is_prime_ex(dh->p, BN_prime_checks, ctx, NULL))
*ret |= DH_CHECK_P_NOT_PRIME;
else if (!dh->q) {
if (!BN_rshift1(t1, dh->p))
goto err;
if (!BN_is_prime_ex(t1, BN_prime_checks, ctx, NULL))
*ret |= DH_CHECK_P_NOT_SAFE_PRIME;
}
ok = 1;
err:
if (ctx != NULL) {
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
return (ok);
}
int DH_check_pub_key(const DH *dh, const BIGNUM *pub_key, int *ret)
{
int ok = 0;
BIGNUM *q = NULL;
*ret = 0;
q = BN_new();
if (q == NULL)
goto err;
BN_set_word(q, 1);
if (BN_cmp(pub_key, q) <= 0)
*ret |= DH_CHECK_PUBKEY_TOO_SMALL;
BN_copy(q, dh->p);
BN_sub_word(q, 1);
if (BN_cmp(pub_key, q) >= 0)
*ret |= DH_CHECK_PUBKEY_TOO_LARGE;
ok = 1;
err:
if (q != NULL)
BN_free(q);
return (ok);
}
