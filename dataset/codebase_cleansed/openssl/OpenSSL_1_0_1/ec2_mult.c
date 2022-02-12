static int gf2m_Mdouble(const EC_GROUP *group, BIGNUM *x, BIGNUM *z, BN_CTX *ctx)
{
BIGNUM *t1;
int ret = 0;
BN_CTX_start(ctx);
t1 = BN_CTX_get(ctx);
if (t1 == NULL) goto err;
if (!group->meth->field_sqr(group, x, x, ctx)) goto err;
if (!group->meth->field_sqr(group, t1, z, ctx)) goto err;
if (!group->meth->field_mul(group, z, x, t1, ctx)) goto err;
if (!group->meth->field_sqr(group, x, x, ctx)) goto err;
if (!group->meth->field_sqr(group, t1, t1, ctx)) goto err;
if (!group->meth->field_mul(group, t1, &group->b, t1, ctx)) goto err;
if (!BN_GF2m_add(x, x, t1)) goto err;
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
static int gf2m_Madd(const EC_GROUP *group, const BIGNUM *x, BIGNUM *x1, BIGNUM *z1,
const BIGNUM *x2, const BIGNUM *z2, BN_CTX *ctx)
{
BIGNUM *t1, *t2;
int ret = 0;
BN_CTX_start(ctx);
t1 = BN_CTX_get(ctx);
t2 = BN_CTX_get(ctx);
if (t2 == NULL) goto err;
if (!BN_copy(t1, x)) goto err;
if (!group->meth->field_mul(group, x1, x1, z2, ctx)) goto err;
if (!group->meth->field_mul(group, z1, z1, x2, ctx)) goto err;
if (!group->meth->field_mul(group, t2, x1, z1, ctx)) goto err;
if (!BN_GF2m_add(z1, z1, x1)) goto err;
if (!group->meth->field_sqr(group, z1, z1, ctx)) goto err;
if (!group->meth->field_mul(group, x1, z1, t1, ctx)) goto err;
if (!BN_GF2m_add(x1, x1, t2)) goto err;
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
static int gf2m_Mxy(const EC_GROUP *group, const BIGNUM *x, const BIGNUM *y, BIGNUM *x1,
BIGNUM *z1, BIGNUM *x2, BIGNUM *z2, BN_CTX *ctx)
{
BIGNUM *t3, *t4, *t5;
int ret = 0;
if (BN_is_zero(z1))
{
BN_zero(x2);
BN_zero(z2);
return 1;
}
if (BN_is_zero(z2))
{
if (!BN_copy(x2, x)) return 0;
if (!BN_GF2m_add(z2, x, y)) return 0;
return 2;
}
BN_CTX_start(ctx);
t3 = BN_CTX_get(ctx);
t4 = BN_CTX_get(ctx);
t5 = BN_CTX_get(ctx);
if (t5 == NULL) goto err;
if (!BN_one(t5)) goto err;
if (!group->meth->field_mul(group, t3, z1, z2, ctx)) goto err;
if (!group->meth->field_mul(group, z1, z1, x, ctx)) goto err;
if (!BN_GF2m_add(z1, z1, x1)) goto err;
if (!group->meth->field_mul(group, z2, z2, x, ctx)) goto err;
if (!group->meth->field_mul(group, x1, z2, x1, ctx)) goto err;
if (!BN_GF2m_add(z2, z2, x2)) goto err;
if (!group->meth->field_mul(group, z2, z2, z1, ctx)) goto err;
if (!group->meth->field_sqr(group, t4, x, ctx)) goto err;
if (!BN_GF2m_add(t4, t4, y)) goto err;
if (!group->meth->field_mul(group, t4, t4, t3, ctx)) goto err;
if (!BN_GF2m_add(t4, t4, z2)) goto err;
if (!group->meth->field_mul(group, t3, t3, x, ctx)) goto err;
if (!group->meth->field_div(group, t3, t5, t3, ctx)) goto err;
if (!group->meth->field_mul(group, t4, t3, t4, ctx)) goto err;
if (!group->meth->field_mul(group, x2, x1, t3, ctx)) goto err;
if (!BN_GF2m_add(z2, x2, x)) goto err;
if (!group->meth->field_mul(group, z2, z2, t4, ctx)) goto err;
if (!BN_GF2m_add(z2, z2, y)) goto err;
ret = 2;
err:
BN_CTX_end(ctx);
return ret;
}
static int ec_GF2m_montgomery_point_multiply(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar,
const EC_POINT *point, BN_CTX *ctx)
{
BIGNUM *x1, *x2, *z1, *z2;
int ret = 0, i;
BN_ULONG mask,word;
if (r == point)
{
ECerr(EC_F_EC_GF2M_MONTGOMERY_POINT_MULTIPLY, EC_R_INVALID_ARGUMENT);
return 0;
}
if ((scalar == NULL) || BN_is_zero(scalar) || (point == NULL) ||
EC_POINT_is_at_infinity(group, point))
{
return EC_POINT_set_to_infinity(group, r);
}
if (!point->Z_is_one) return 0;
BN_CTX_start(ctx);
x1 = BN_CTX_get(ctx);
z1 = BN_CTX_get(ctx);
if (z1 == NULL) goto err;
x2 = &r->X;
z2 = &r->Y;
if (!BN_GF2m_mod_arr(x1, &point->X, group->poly)) goto err;
if (!BN_one(z1)) goto err;
if (!group->meth->field_sqr(group, z2, x1, ctx)) goto err;
if (!group->meth->field_sqr(group, x2, z2, ctx)) goto err;
if (!BN_GF2m_add(x2, x2, &group->b)) goto err;
i = scalar->top - 1;
mask = BN_TBIT;
word = scalar->d[i];
while (!(word & mask)) mask >>= 1;
mask >>= 1;
if (!mask)
{
i--;
mask = BN_TBIT;
}
for (; i >= 0; i--)
{
word = scalar->d[i];
while (mask)
{
if (word & mask)
{
if (!gf2m_Madd(group, &point->X, x1, z1, x2, z2, ctx)) goto err;
if (!gf2m_Mdouble(group, x2, z2, ctx)) goto err;
}
else
{
if (!gf2m_Madd(group, &point->X, x2, z2, x1, z1, ctx)) goto err;
if (!gf2m_Mdouble(group, x1, z1, ctx)) goto err;
}
mask >>= 1;
}
mask = BN_TBIT;
}
i = gf2m_Mxy(group, &point->X, &point->Y, x1, z1, x2, z2, ctx);
if (i == 0) goto err;
else if (i == 1)
{
if (!EC_POINT_set_to_infinity(group, r)) goto err;
}
else
{
if (!BN_one(&r->Z)) goto err;
r->Z_is_one = 1;
}
BN_set_negative(&r->X, 0);
BN_set_negative(&r->Y, 0);
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
int ec_GF2m_simple_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar,
size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
int ret = 0;
size_t i;
EC_POINT *p=NULL;
EC_POINT *acc = NULL;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
if ((scalar && (num > 1)) || (num > 2) || (num == 0 && EC_GROUP_have_precompute_mult(group)))
{
ret = ec_wNAF_mul(group, r, scalar, num, points, scalars, ctx);
goto err;
}
if ((p = EC_POINT_new(group)) == NULL) goto err;
if ((acc = EC_POINT_new(group)) == NULL) goto err;
if (!EC_POINT_set_to_infinity(group, acc)) goto err;
if (scalar)
{
if (!ec_GF2m_montgomery_point_multiply(group, p, scalar, group->generator, ctx)) goto err;
if (BN_is_negative(scalar))
if (!group->meth->invert(group, p, ctx)) goto err;
if (!group->meth->add(group, acc, acc, p, ctx)) goto err;
}
for (i = 0; i < num; i++)
{
if (!ec_GF2m_montgomery_point_multiply(group, p, scalars[i], points[i], ctx)) goto err;
if (BN_is_negative(scalars[i]))
if (!group->meth->invert(group, p, ctx)) goto err;
if (!group->meth->add(group, acc, acc, p, ctx)) goto err;
}
if (!EC_POINT_copy(r, acc)) goto err;
ret = 1;
err:
if (p) EC_POINT_free(p);
if (acc) EC_POINT_free(acc);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GF2m_precompute_mult(EC_GROUP *group, BN_CTX *ctx)
{
return ec_wNAF_precompute_mult(group, ctx);
}
int ec_GF2m_have_precompute_mult(const EC_GROUP *group)
{
return ec_wNAF_have_precompute_mult(group);
}
