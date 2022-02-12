int EC_GROUP_check(const EC_GROUP *group, BN_CTX *ctx)
{
int ret = 0;
BIGNUM *order;
BN_CTX *new_ctx = NULL;
EC_POINT *point = NULL;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
{
ECerr(EC_F_EC_GROUP_CHECK, ERR_R_MALLOC_FAILURE);
goto err;
}
}
BN_CTX_start(ctx);
if ((order = BN_CTX_get(ctx)) == NULL) goto err;
if (!EC_GROUP_check_discriminant(group, ctx))
{
ECerr(EC_F_EC_GROUP_CHECK, EC_R_DISCRIMINANT_IS_ZERO);
goto err;
}
if (group->generator == NULL)
{
ECerr(EC_F_EC_GROUP_CHECK, EC_R_UNDEFINED_GENERATOR);
goto err;
}
if (!EC_POINT_is_on_curve(group, group->generator, ctx))
{
ECerr(EC_F_EC_GROUP_CHECK, EC_R_POINT_IS_NOT_ON_CURVE);
goto err;
}
if ((point = EC_POINT_new(group)) == NULL) goto err;
if (!EC_GROUP_get_order(group, order, ctx)) goto err;
if (BN_is_zero(order))
{
ECerr(EC_F_EC_GROUP_CHECK, EC_R_UNDEFINED_ORDER);
goto err;
}
if (!EC_POINT_mul(group, point, order, NULL, NULL, ctx)) goto err;
if (!EC_POINT_is_at_infinity(group, point))
{
ECerr(EC_F_EC_GROUP_CHECK, EC_R_INVALID_GROUP_ORDER);
goto err;
}
ret = 1;
err:
if (ctx != NULL)
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
if (point)
EC_POINT_free(point);
return ret;
}
