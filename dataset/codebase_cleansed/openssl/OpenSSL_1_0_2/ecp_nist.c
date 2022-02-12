const EC_METHOD *EC_GFp_nist_method(void)
{
static const EC_METHOD ret = {
EC_FLAGS_DEFAULT_OCT,
NID_X9_62_prime_field,
ec_GFp_simple_group_init,
ec_GFp_simple_group_finish,
ec_GFp_simple_group_clear_finish,
ec_GFp_nist_group_copy,
ec_GFp_nist_group_set_curve,
ec_GFp_simple_group_get_curve,
ec_GFp_simple_group_get_degree,
ec_GFp_simple_group_check_discriminant,
ec_GFp_simple_point_init,
ec_GFp_simple_point_finish,
ec_GFp_simple_point_clear_finish,
ec_GFp_simple_point_copy,
ec_GFp_simple_point_set_to_infinity,
ec_GFp_simple_set_Jprojective_coordinates_GFp,
ec_GFp_simple_get_Jprojective_coordinates_GFp,
ec_GFp_simple_point_set_affine_coordinates,
ec_GFp_simple_point_get_affine_coordinates,
0, 0, 0,
ec_GFp_simple_add,
ec_GFp_simple_dbl,
ec_GFp_simple_invert,
ec_GFp_simple_is_at_infinity,
ec_GFp_simple_is_on_curve,
ec_GFp_simple_cmp,
ec_GFp_simple_make_affine,
ec_GFp_simple_points_make_affine,
0 ,
0 ,
0 ,
ec_GFp_nist_field_mul,
ec_GFp_nist_field_sqr,
0 ,
0 ,
0 ,
0
};
#ifdef OPENSSL_FIPS
if (FIPS_mode())
return fips_ec_gfp_nist_method();
#endif
return &ret;
}
int ec_GFp_nist_group_copy(EC_GROUP *dest, const EC_GROUP *src)
{
dest->field_mod_func = src->field_mod_func;
return ec_GFp_simple_group_copy(dest, src);
}
int ec_GFp_nist_group_set_curve(EC_GROUP *group, const BIGNUM *p,
const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
int ret = 0;
BN_CTX *new_ctx = NULL;
BIGNUM *tmp_bn;
if (ctx == NULL)
if ((ctx = new_ctx = BN_CTX_new()) == NULL)
return 0;
BN_CTX_start(ctx);
if ((tmp_bn = BN_CTX_get(ctx)) == NULL)
goto err;
if (BN_ucmp(BN_get0_nist_prime_192(), p) == 0)
group->field_mod_func = BN_nist_mod_192;
else if (BN_ucmp(BN_get0_nist_prime_224(), p) == 0)
group->field_mod_func = BN_nist_mod_224;
else if (BN_ucmp(BN_get0_nist_prime_256(), p) == 0)
group->field_mod_func = BN_nist_mod_256;
else if (BN_ucmp(BN_get0_nist_prime_384(), p) == 0)
group->field_mod_func = BN_nist_mod_384;
else if (BN_ucmp(BN_get0_nist_prime_521(), p) == 0)
group->field_mod_func = BN_nist_mod_521;
else {
ECerr(EC_F_EC_GFP_NIST_GROUP_SET_CURVE, EC_R_NOT_A_NIST_PRIME);
goto err;
}
ret = ec_GFp_simple_group_set_curve(group, p, a, b, ctx);
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_nist_field_mul(const EC_GROUP *group, BIGNUM *r, const BIGNUM *a,
const BIGNUM *b, BN_CTX *ctx)
{
int ret = 0;
BN_CTX *ctx_new = NULL;
if (!group || !r || !a || !b) {
ECerr(EC_F_EC_GFP_NIST_FIELD_MUL, ERR_R_PASSED_NULL_PARAMETER);
goto err;
}
if (!ctx)
if ((ctx_new = ctx = BN_CTX_new()) == NULL)
goto err;
if (!BN_mul(r, a, b, ctx))
goto err;
if (!group->field_mod_func(r, r, &group->field, ctx))
goto err;
ret = 1;
err:
if (ctx_new)
BN_CTX_free(ctx_new);
return ret;
}
int ec_GFp_nist_field_sqr(const EC_GROUP *group, BIGNUM *r, const BIGNUM *a,
BN_CTX *ctx)
{
int ret = 0;
BN_CTX *ctx_new = NULL;
if (!group || !r || !a) {
ECerr(EC_F_EC_GFP_NIST_FIELD_SQR, EC_R_PASSED_NULL_PARAMETER);
goto err;
}
if (!ctx)
if ((ctx_new = ctx = BN_CTX_new()) == NULL)
goto err;
if (!BN_sqr(r, a, ctx))
goto err;
if (!group->field_mod_func(r, r, &group->field, ctx))
goto err;
ret = 1;
err:
if (ctx_new)
BN_CTX_free(ctx_new);
return ret;
}
