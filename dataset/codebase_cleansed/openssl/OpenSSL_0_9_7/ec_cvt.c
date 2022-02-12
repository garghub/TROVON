EC_GROUP *EC_GROUP_new_curve_GFp(const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
const EC_METHOD *meth;
EC_GROUP *ret;
meth = EC_GFp_mont_method();
ret = EC_GROUP_new(meth);
if (ret == NULL)
return NULL;
if (!EC_GROUP_set_curve_GFp(ret, p, a, b, ctx))
{
EC_GROUP_clear_free(ret);
return NULL;
}
return ret;
}
