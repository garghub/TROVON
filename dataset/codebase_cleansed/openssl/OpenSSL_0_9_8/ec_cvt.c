EC_GROUP *EC_GROUP_new_curve_GFp(const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
const EC_METHOD *meth;
EC_GROUP *ret;
meth = EC_GFp_nist_method();
ret = EC_GROUP_new(meth);
if (ret == NULL)
return NULL;
if (!EC_GROUP_set_curve_GFp(ret, p, a, b, ctx))
{
unsigned long err;
err = ERR_peek_last_error();
if (!(ERR_GET_LIB(err) == ERR_LIB_EC &&
((ERR_GET_REASON(err) == EC_R_NOT_A_NIST_PRIME) ||
(ERR_GET_REASON(err) == EC_R_NOT_A_SUPPORTED_NIST_PRIME))))
{
EC_GROUP_clear_free(ret);
return NULL;
}
ERR_clear_error();
EC_GROUP_clear_free(ret);
meth = EC_GFp_mont_method();
ret = EC_GROUP_new(meth);
if (ret == NULL)
return NULL;
if (!EC_GROUP_set_curve_GFp(ret, p, a, b, ctx))
{
EC_GROUP_clear_free(ret);
return NULL;
}
}
return ret;
}
EC_GROUP *EC_GROUP_new_curve_GF2m(const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
const EC_METHOD *meth;
EC_GROUP *ret;
meth = EC_GF2m_simple_method();
ret = EC_GROUP_new(meth);
if (ret == NULL)
return NULL;
if (!EC_GROUP_set_curve_GF2m(ret, p, a, b, ctx))
{
EC_GROUP_clear_free(ret);
return NULL;
}
return ret;
}
