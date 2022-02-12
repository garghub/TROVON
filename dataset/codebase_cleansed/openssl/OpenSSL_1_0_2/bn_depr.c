BIGNUM *BN_generate_prime(BIGNUM *ret, int bits, int safe,
const BIGNUM *add, const BIGNUM *rem,
void (*callback) (int, int, void *), void *cb_arg)
{
BN_GENCB cb;
BIGNUM *rnd = NULL;
int found = 0;
BN_GENCB_set_old(&cb, callback, cb_arg);
if (ret == NULL) {
if ((rnd = BN_new()) == NULL)
goto err;
} else
rnd = ret;
if (!BN_generate_prime_ex(rnd, bits, safe, add, rem, &cb))
goto err;
found = 1;
err:
if (!found && (ret == NULL) && (rnd != NULL))
BN_free(rnd);
return (found ? rnd : NULL);
}
int BN_is_prime(const BIGNUM *a, int checks,
void (*callback) (int, int, void *), BN_CTX *ctx_passed,
void *cb_arg)
{
BN_GENCB cb;
BN_GENCB_set_old(&cb, callback, cb_arg);
return BN_is_prime_ex(a, checks, ctx_passed, &cb);
}
int BN_is_prime_fasttest(const BIGNUM *a, int checks,
void (*callback) (int, int, void *),
BN_CTX *ctx_passed, void *cb_arg,
int do_trial_division)
{
BN_GENCB cb;
BN_GENCB_set_old(&cb, callback, cb_arg);
return BN_is_prime_fasttest_ex(a, checks, ctx_passed,
do_trial_division, &cb);
}
