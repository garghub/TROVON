int ec_GF2m_simple_set_compressed_coordinates(const EC_GROUP *group, EC_POINT *point,
const BIGNUM *x_, int y_bit, BN_CTX *ctx)
{
#ifndef OPENSSL_EC_BIN_PT_COMP
ECerr(EC_F_EC_GF2M_SIMPLE_SET_COMPRESSED_COORDINATES, ERR_R_DISABLED);
return 0;
#else
BN_CTX *new_ctx = NULL;
BIGNUM *tmp, *x, *y, *z;
int ret = 0, z0;
ERR_clear_error();
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
y_bit = (y_bit != 0) ? 1 : 0;
BN_CTX_start(ctx);
tmp = BN_CTX_get(ctx);
x = BN_CTX_get(ctx);
y = BN_CTX_get(ctx);
z = BN_CTX_get(ctx);
if (z == NULL) goto err;
if (!BN_GF2m_mod_arr(x, x_, group->poly)) goto err;
if (BN_is_zero(x))
{
if (!BN_GF2m_mod_sqrt_arr(y, &group->b, group->poly, ctx)) goto err;
}
else
{
if (!group->meth->field_sqr(group, tmp, x, ctx)) goto err;
if (!group->meth->field_div(group, tmp, &group->b, tmp, ctx)) goto err;
if (!BN_GF2m_add(tmp, &group->a, tmp)) goto err;
if (!BN_GF2m_add(tmp, x, tmp)) goto err;
if (!BN_GF2m_mod_solve_quad_arr(z, tmp, group->poly, ctx))
{
unsigned long err = ERR_peek_last_error();
if (ERR_GET_LIB(err) == ERR_LIB_BN && ERR_GET_REASON(err) == BN_R_NO_SOLUTION)
{
ERR_clear_error();
ECerr(EC_F_EC_GF2M_SIMPLE_SET_COMPRESSED_COORDINATES, EC_R_INVALID_COMPRESSED_POINT);
}
else
ECerr(EC_F_EC_GF2M_SIMPLE_SET_COMPRESSED_COORDINATES, ERR_R_BN_LIB);
goto err;
}
z0 = (BN_is_odd(z)) ? 1 : 0;
if (!group->meth->field_mul(group, y, x, z, ctx)) goto err;
if (z0 != y_bit)
{
if (!BN_GF2m_add(y, y, x)) goto err;
}
}
if (!EC_POINT_set_affine_coordinates_GF2m(group, point, x, y, ctx)) goto err;
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
#endif
}
