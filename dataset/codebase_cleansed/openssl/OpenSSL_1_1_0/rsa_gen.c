int RSA_generate_key_ex(RSA *rsa, int bits, BIGNUM *e_value, BN_GENCB *cb)
{
if (rsa->meth->rsa_keygen)
return rsa->meth->rsa_keygen(rsa, bits, e_value, cb);
return rsa_builtin_keygen(rsa, bits, e_value, cb);
}
static int rsa_builtin_keygen(RSA *rsa, int bits, BIGNUM *e_value,
BN_GENCB *cb)
{
BIGNUM *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *tmp;
int bitsp, bitsq, ok = -1, n = 0;
BN_CTX *ctx = NULL;
ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
BN_CTX_start(ctx);
r0 = BN_CTX_get(ctx);
r1 = BN_CTX_get(ctx);
r2 = BN_CTX_get(ctx);
r3 = BN_CTX_get(ctx);
if (r3 == NULL)
goto err;
bitsp = (bits + 1) / 2;
bitsq = bits - bitsp;
if (!rsa->n && ((rsa->n = BN_new()) == NULL))
goto err;
if (!rsa->d && ((rsa->d = BN_secure_new()) == NULL))
goto err;
if (!rsa->e && ((rsa->e = BN_new()) == NULL))
goto err;
if (!rsa->p && ((rsa->p = BN_secure_new()) == NULL))
goto err;
if (!rsa->q && ((rsa->q = BN_secure_new()) == NULL))
goto err;
if (!rsa->dmp1 && ((rsa->dmp1 = BN_secure_new()) == NULL))
goto err;
if (!rsa->dmq1 && ((rsa->dmq1 = BN_secure_new()) == NULL))
goto err;
if (!rsa->iqmp && ((rsa->iqmp = BN_secure_new()) == NULL))
goto err;
BN_copy(rsa->e, e_value);
for (;;) {
if (!BN_generate_prime_ex(rsa->p, bitsp, 0, NULL, NULL, cb))
goto err;
if (!BN_sub(r2, rsa->p, BN_value_one()))
goto err;
if (!BN_gcd(r1, r2, rsa->e, ctx))
goto err;
if (BN_is_one(r1))
break;
if (!BN_GENCB_call(cb, 2, n++))
goto err;
}
if (!BN_GENCB_call(cb, 3, 0))
goto err;
for (;;) {
unsigned int degenerate = 0;
do {
if (!BN_generate_prime_ex(rsa->q, bitsq, 0, NULL, NULL, cb))
goto err;
} while ((BN_cmp(rsa->p, rsa->q) == 0) && (++degenerate < 3));
if (degenerate == 3) {
ok = 0;
RSAerr(RSA_F_RSA_BUILTIN_KEYGEN, RSA_R_KEY_SIZE_TOO_SMALL);
goto err;
}
if (!BN_sub(r2, rsa->q, BN_value_one()))
goto err;
if (!BN_gcd(r1, r2, rsa->e, ctx))
goto err;
if (BN_is_one(r1))
break;
if (!BN_GENCB_call(cb, 2, n++))
goto err;
}
if (!BN_GENCB_call(cb, 3, 1))
goto err;
if (BN_cmp(rsa->p, rsa->q) < 0) {
tmp = rsa->p;
rsa->p = rsa->q;
rsa->q = tmp;
}
if (!BN_mul(rsa->n, rsa->p, rsa->q, ctx))
goto err;
if (!BN_sub(r1, rsa->p, BN_value_one()))
goto err;
if (!BN_sub(r2, rsa->q, BN_value_one()))
goto err;
if (!BN_mul(r0, r1, r2, ctx))
goto err;
{
BIGNUM *pr0 = BN_new();
if (pr0 == NULL)
goto err;
BN_with_flags(pr0, r0, BN_FLG_CONSTTIME);
if (!BN_mod_inverse(rsa->d, rsa->e, pr0, ctx)) {
BN_free(pr0);
goto err;
}
BN_free(pr0);
}
{
BIGNUM *d = BN_new();
if (d == NULL)
goto err;
BN_with_flags(d, rsa->d, BN_FLG_CONSTTIME);
if (
!BN_mod(rsa->dmp1, d, r1, ctx)
|| !BN_mod(rsa->dmq1, d, r2, ctx)) {
BN_free(d);
goto err;
}
BN_free(d);
}
{
BIGNUM *p = BN_new();
if (p == NULL)
goto err;
BN_with_flags(p, rsa->p, BN_FLG_CONSTTIME);
if (!BN_mod_inverse(rsa->iqmp, rsa->q, p, ctx)) {
BN_free(p);
goto err;
}
BN_free(p);
}
ok = 1;
err:
if (ok == -1) {
RSAerr(RSA_F_RSA_BUILTIN_KEYGEN, ERR_LIB_BN);
ok = 0;
}
if (ctx != NULL)
BN_CTX_end(ctx);
BN_CTX_free(ctx);
return ok;
}
