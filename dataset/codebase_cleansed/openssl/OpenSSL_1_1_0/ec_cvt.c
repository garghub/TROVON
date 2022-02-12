EC_GROUP *EC_GROUP_new_curve_GFp(const BIGNUM *p, const BIGNUM *a,
const BIGNUM *b, BN_CTX *ctx)
{
const EC_METHOD *meth;
EC_GROUP *ret;
#if defined(OPENSSL_BN_ASM_MONT)
meth = EC_GFp_mont_method();
#else
if (BN_nist_mod_func(p))
meth = EC_GFp_nist_method();
else
meth = EC_GFp_mont_method();
#endif
ret = EC_GROUP_new(meth);
if (ret == NULL)
return NULL;
if (!EC_GROUP_set_curve_GFp(ret, p, a, b, ctx)) {
EC_GROUP_clear_free(ret);
return NULL;
}
return ret;
}
EC_GROUP *EC_GROUP_new_curve_GF2m(const BIGNUM *p, const BIGNUM *a,
const BIGNUM *b, BN_CTX *ctx)
{
const EC_METHOD *meth;
EC_GROUP *ret;
meth = EC_GF2m_simple_method();
ret = EC_GROUP_new(meth);
if (ret == NULL)
return NULL;
if (!EC_GROUP_set_curve_GF2m(ret, p, a, b, ctx)) {
EC_GROUP_clear_free(ret);
return NULL;
}
return ret;
}
