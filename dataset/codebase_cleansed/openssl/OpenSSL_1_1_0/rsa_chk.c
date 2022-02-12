int RSA_check_key(const RSA *key)
{
return RSA_check_key_ex(key, NULL);
}
int RSA_check_key_ex(const RSA *key, BN_GENCB *cb)
{
BIGNUM *i, *j, *k, *l, *m;
BN_CTX *ctx;
int ret = 1;
if (key->p == NULL || key->q == NULL || key->n == NULL
|| key->e == NULL || key->d == NULL) {
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_VALUE_MISSING);
return 0;
}
i = BN_new();
j = BN_new();
k = BN_new();
l = BN_new();
m = BN_new();
ctx = BN_CTX_new();
if (i == NULL || j == NULL || k == NULL || l == NULL
|| m == NULL || ctx == NULL) {
ret = -1;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, ERR_R_MALLOC_FAILURE);
goto err;
}
if (BN_is_one(key->e)) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_BAD_E_VALUE);
}
if (!BN_is_odd(key->e)) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_BAD_E_VALUE);
}
if (BN_is_prime_ex(key->p, BN_prime_checks, NULL, cb) != 1) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_P_NOT_PRIME);
}
if (BN_is_prime_ex(key->q, BN_prime_checks, NULL, cb) != 1) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_Q_NOT_PRIME);
}
if (!BN_mul(i, key->p, key->q, ctx)) {
ret = -1;
goto err;
}
if (BN_cmp(i, key->n) != 0) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_N_DOES_NOT_EQUAL_P_Q);
}
if (!BN_sub(i, key->p, BN_value_one())) {
ret = -1;
goto err;
}
if (!BN_sub(j, key->q, BN_value_one())) {
ret = -1;
goto err;
}
if (!BN_mul(l, i, j, ctx)) {
ret = -1;
goto err;
}
if (!BN_gcd(m, i, j, ctx)) {
ret = -1;
goto err;
}
if (!BN_div(k, NULL, l, m, ctx)) {
ret = -1;
goto err;
}
if (!BN_mod_mul(i, key->d, key->e, k, ctx)) {
ret = -1;
goto err;
}
if (!BN_is_one(i)) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_D_E_NOT_CONGRUENT_TO_1);
}
if (key->dmp1 != NULL && key->dmq1 != NULL && key->iqmp != NULL) {
if (!BN_sub(i, key->p, BN_value_one())) {
ret = -1;
goto err;
}
if (!BN_mod(j, key->d, i, ctx)) {
ret = -1;
goto err;
}
if (BN_cmp(j, key->dmp1) != 0) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_DMP1_NOT_CONGRUENT_TO_D);
}
if (!BN_sub(i, key->q, BN_value_one())) {
ret = -1;
goto err;
}
if (!BN_mod(j, key->d, i, ctx)) {
ret = -1;
goto err;
}
if (BN_cmp(j, key->dmq1) != 0) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_DMQ1_NOT_CONGRUENT_TO_D);
}
if (!BN_mod_inverse(i, key->q, key->p, ctx)) {
ret = -1;
goto err;
}
if (BN_cmp(i, key->iqmp) != 0) {
ret = 0;
RSAerr(RSA_F_RSA_CHECK_KEY_EX, RSA_R_IQMP_NOT_INVERSE_OF_Q);
}
}
err:
BN_free(i);
BN_free(j);
BN_free(k);
BN_free(l);
BN_free(m);
BN_CTX_free(ctx);
return ret;
}
