int RSA_check_key(RSA *key)
{
BIGNUM *i, *j, *k, *l, *m;
BN_CTX *ctx;
int r;
int ret=1;
i = BN_new();
j = BN_new();
k = BN_new();
l = BN_new();
m = BN_new();
ctx = BN_CTX_new();
if (i == NULL || j == NULL || k == NULL || l == NULL ||
m == NULL || ctx == NULL)
{
ret = -1;
RSAerr(RSA_F_RSA_CHECK_KEY, ERR_R_MALLOC_FAILURE);
goto err;
}
r = BN_is_prime(key->p, BN_prime_checks, NULL, NULL, NULL);
if (r != 1)
{
ret = r;
if (r != 0)
goto err;
RSAerr(RSA_F_RSA_CHECK_KEY, RSA_R_P_NOT_PRIME);
}
r = BN_is_prime(key->q, BN_prime_checks, NULL, NULL, NULL);
if (r != 1)
{
ret = r;
if (r != 0)
goto err;
RSAerr(RSA_F_RSA_CHECK_KEY, RSA_R_Q_NOT_PRIME);
}
r = BN_mul(i, key->p, key->q, ctx);
if (!r) { ret = -1; goto err; }
if (BN_cmp(i, key->n) != 0)
{
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY, RSA_R_N_DOES_NOT_EQUAL_P_Q);
}
r = BN_sub(i, key->p, BN_value_one());
if (!r) { ret = -1; goto err; }
r = BN_sub(j, key->q, BN_value_one());
if (!r) { ret = -1; goto err; }
r = BN_mul(l, i, j, ctx);
if (!r) { ret = -1; goto err; }
r = BN_gcd(m, i, j, ctx);
if (!r) { ret = -1; goto err; }
r = BN_div(k, NULL, l, m, ctx);
if (!r) { ret = -1; goto err; }
r = BN_mod_mul(i, key->d, key->e, k, ctx);
if (!r) { ret = -1; goto err; }
if (!BN_is_one(i))
{
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY, RSA_R_D_E_NOT_CONGRUENT_TO_1);
}
if (key->dmp1 != NULL && key->dmq1 != NULL && key->iqmp != NULL)
{
r = BN_sub(i, key->p, BN_value_one());
if (!r) { ret = -1; goto err; }
r = BN_mod(j, key->d, i, ctx);
if (!r) { ret = -1; goto err; }
if (BN_cmp(j, key->dmp1) != 0)
{
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY,
RSA_R_DMP1_NOT_CONGRUENT_TO_D);
}
r = BN_sub(i, key->q, BN_value_one());
if (!r) { ret = -1; goto err; }
r = BN_mod(j, key->d, i, ctx);
if (!r) { ret = -1; goto err; }
if (BN_cmp(j, key->dmq1) != 0)
{
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY,
RSA_R_DMQ1_NOT_CONGRUENT_TO_D);
}
if(!BN_mod_inverse(i, key->q, key->p, ctx))
{
ret = -1;
goto err;
}
if (BN_cmp(i, key->iqmp) != 0)
{
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY,
RSA_R_IQMP_NOT_INVERSE_OF_Q);
}
}
err:
if (i != NULL) BN_free(i);
if (j != NULL) BN_free(j);
if (k != NULL) BN_free(k);
if (l != NULL) BN_free(l);
if (m != NULL) BN_free(m);
if (ctx != NULL) BN_CTX_free(ctx);
return (ret);
}
