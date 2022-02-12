const EC_METHOD *EC_GF2m_simple_method(void)
{
static const EC_METHOD ret = {
NID_X9_62_characteristic_two_field,
ec_GF2m_simple_group_init,
ec_GF2m_simple_group_finish,
ec_GF2m_simple_group_clear_finish,
ec_GF2m_simple_group_copy,
ec_GF2m_simple_group_set_curve,
ec_GF2m_simple_group_get_curve,
ec_GF2m_simple_group_get_degree,
ec_GF2m_simple_group_check_discriminant,
ec_GF2m_simple_point_init,
ec_GF2m_simple_point_finish,
ec_GF2m_simple_point_clear_finish,
ec_GF2m_simple_point_copy,
ec_GF2m_simple_point_set_to_infinity,
0 ,
0 ,
ec_GF2m_simple_point_set_affine_coordinates,
ec_GF2m_simple_point_get_affine_coordinates,
ec_GF2m_simple_set_compressed_coordinates,
ec_GF2m_simple_point2oct,
ec_GF2m_simple_oct2point,
ec_GF2m_simple_add,
ec_GF2m_simple_dbl,
ec_GF2m_simple_invert,
ec_GF2m_simple_is_at_infinity,
ec_GF2m_simple_is_on_curve,
ec_GF2m_simple_cmp,
ec_GF2m_simple_make_affine,
ec_GF2m_simple_points_make_affine,
ec_GF2m_simple_mul,
ec_GF2m_precompute_mult,
ec_GF2m_have_precompute_mult,
ec_GF2m_simple_field_mul,
ec_GF2m_simple_field_sqr,
ec_GF2m_simple_field_div,
0 ,
0 ,
0 };
return &ret;
}
int ec_GF2m_simple_group_init(EC_GROUP *group)
{
BN_init(&group->field);
BN_init(&group->a);
BN_init(&group->b);
return 1;
}
void ec_GF2m_simple_group_finish(EC_GROUP *group)
{
BN_free(&group->field);
BN_free(&group->a);
BN_free(&group->b);
}
void ec_GF2m_simple_group_clear_finish(EC_GROUP *group)
{
BN_clear_free(&group->field);
BN_clear_free(&group->a);
BN_clear_free(&group->b);
group->poly[0] = 0;
group->poly[1] = 0;
group->poly[2] = 0;
group->poly[3] = 0;
group->poly[4] = 0;
group->poly[5] = -1;
}
int ec_GF2m_simple_group_copy(EC_GROUP *dest, const EC_GROUP *src)
{
int i;
if (!BN_copy(&dest->field, &src->field)) return 0;
if (!BN_copy(&dest->a, &src->a)) return 0;
if (!BN_copy(&dest->b, &src->b)) return 0;
dest->poly[0] = src->poly[0];
dest->poly[1] = src->poly[1];
dest->poly[2] = src->poly[2];
dest->poly[3] = src->poly[3];
dest->poly[4] = src->poly[4];
dest->poly[5] = src->poly[5];
if (bn_wexpand(&dest->a, (int)(dest->poly[0] + BN_BITS2 - 1) / BN_BITS2) == NULL) return 0;
if (bn_wexpand(&dest->b, (int)(dest->poly[0] + BN_BITS2 - 1) / BN_BITS2) == NULL) return 0;
for (i = dest->a.top; i < dest->a.dmax; i++) dest->a.d[i] = 0;
for (i = dest->b.top; i < dest->b.dmax; i++) dest->b.d[i] = 0;
return 1;
}
int ec_GF2m_simple_group_set_curve(EC_GROUP *group,
const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
int ret = 0, i;
if (!BN_copy(&group->field, p)) goto err;
i = BN_GF2m_poly2arr(&group->field, group->poly, 6) - 1;
if ((i != 5) && (i != 3))
{
ECerr(EC_F_EC_GF2M_SIMPLE_GROUP_SET_CURVE, EC_R_UNSUPPORTED_FIELD);
goto err;
}
if (!BN_GF2m_mod_arr(&group->a, a, group->poly)) goto err;
if(bn_wexpand(&group->a, (int)(group->poly[0] + BN_BITS2 - 1) / BN_BITS2) == NULL) goto err;
for (i = group->a.top; i < group->a.dmax; i++) group->a.d[i] = 0;
if (!BN_GF2m_mod_arr(&group->b, b, group->poly)) goto err;
if(bn_wexpand(&group->b, (int)(group->poly[0] + BN_BITS2 - 1) / BN_BITS2) == NULL) goto err;
for (i = group->b.top; i < group->b.dmax; i++) group->b.d[i] = 0;
ret = 1;
err:
return ret;
}
int ec_GF2m_simple_group_get_curve(const EC_GROUP *group, BIGNUM *p, BIGNUM *a, BIGNUM *b, BN_CTX *ctx)
{
int ret = 0;
if (p != NULL)
{
if (!BN_copy(p, &group->field)) return 0;
}
if (a != NULL)
{
if (!BN_copy(a, &group->a)) goto err;
}
if (b != NULL)
{
if (!BN_copy(b, &group->b)) goto err;
}
ret = 1;
err:
return ret;
}
int ec_GF2m_simple_group_get_degree(const EC_GROUP *group)
{
return BN_num_bits(&group->field)-1;
}
int ec_GF2m_simple_group_check_discriminant(const EC_GROUP *group, BN_CTX *ctx)
{
int ret = 0;
BIGNUM *b;
BN_CTX *new_ctx = NULL;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
{
ECerr(EC_F_EC_GF2M_SIMPLE_GROUP_CHECK_DISCRIMINANT, ERR_R_MALLOC_FAILURE);
goto err;
}
}
BN_CTX_start(ctx);
b = BN_CTX_get(ctx);
if (b == NULL) goto err;
if (!BN_GF2m_mod_arr(b, &group->b, group->poly)) goto err;
if (BN_is_zero(b)) goto err;
ret = 1;
err:
if (ctx != NULL)
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GF2m_simple_point_init(EC_POINT *point)
{
BN_init(&point->X);
BN_init(&point->Y);
BN_init(&point->Z);
return 1;
}
void ec_GF2m_simple_point_finish(EC_POINT *point)
{
BN_free(&point->X);
BN_free(&point->Y);
BN_free(&point->Z);
}
void ec_GF2m_simple_point_clear_finish(EC_POINT *point)
{
BN_clear_free(&point->X);
BN_clear_free(&point->Y);
BN_clear_free(&point->Z);
point->Z_is_one = 0;
}
int ec_GF2m_simple_point_copy(EC_POINT *dest, const EC_POINT *src)
{
if (!BN_copy(&dest->X, &src->X)) return 0;
if (!BN_copy(&dest->Y, &src->Y)) return 0;
if (!BN_copy(&dest->Z, &src->Z)) return 0;
dest->Z_is_one = src->Z_is_one;
return 1;
}
int ec_GF2m_simple_point_set_to_infinity(const EC_GROUP *group, EC_POINT *point)
{
point->Z_is_one = 0;
BN_zero(&point->Z);
return 1;
}
int ec_GF2m_simple_point_set_affine_coordinates(const EC_GROUP *group, EC_POINT *point,
const BIGNUM *x, const BIGNUM *y, BN_CTX *ctx)
{
int ret = 0;
if (x == NULL || y == NULL)
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT_SET_AFFINE_COORDINATES, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if (!BN_copy(&point->X, x)) goto err;
BN_set_negative(&point->X, 0);
if (!BN_copy(&point->Y, y)) goto err;
BN_set_negative(&point->Y, 0);
if (!BN_copy(&point->Z, BN_value_one())) goto err;
BN_set_negative(&point->Z, 0);
point->Z_is_one = 1;
ret = 1;
err:
return ret;
}
int ec_GF2m_simple_point_get_affine_coordinates(const EC_GROUP *group, const EC_POINT *point,
BIGNUM *x, BIGNUM *y, BN_CTX *ctx)
{
int ret = 0;
if (EC_POINT_is_at_infinity(group, point))
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT_GET_AFFINE_COORDINATES, EC_R_POINT_AT_INFINITY);
return 0;
}
if (BN_cmp(&point->Z, BN_value_one()))
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT_GET_AFFINE_COORDINATES, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return 0;
}
if (x != NULL)
{
if (!BN_copy(x, &point->X)) goto err;
BN_set_negative(x, 0);
}
if (y != NULL)
{
if (!BN_copy(y, &point->Y)) goto err;
BN_set_negative(y, 0);
}
ret = 1;
err:
return ret;
}
int ec_GF2m_simple_set_compressed_coordinates(const EC_GROUP *group, EC_POINT *point,
const BIGNUM *x_, int y_bit, BN_CTX *ctx)
{
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
}
size_t ec_GF2m_simple_point2oct(const EC_GROUP *group, const EC_POINT *point, point_conversion_form_t form,
unsigned char *buf, size_t len, BN_CTX *ctx)
{
size_t ret;
BN_CTX *new_ctx = NULL;
int used_ctx = 0;
BIGNUM *x, *y, *yxi;
size_t field_len, i, skip;
if ((form != POINT_CONVERSION_COMPRESSED)
&& (form != POINT_CONVERSION_UNCOMPRESSED)
&& (form != POINT_CONVERSION_HYBRID))
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT2OCT, EC_R_INVALID_FORM);
goto err;
}
if (EC_POINT_is_at_infinity(group, point))
{
if (buf != NULL)
{
if (len < 1)
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT2OCT, EC_R_BUFFER_TOO_SMALL);
return 0;
}
buf[0] = 0;
}
return 1;
}
field_len = (EC_GROUP_get_degree(group) + 7) / 8;
ret = (form == POINT_CONVERSION_COMPRESSED) ? 1 + field_len : 1 + 2*field_len;
if (buf != NULL)
{
if (len < ret)
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT2OCT, EC_R_BUFFER_TOO_SMALL);
goto err;
}
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
used_ctx = 1;
x = BN_CTX_get(ctx);
y = BN_CTX_get(ctx);
yxi = BN_CTX_get(ctx);
if (yxi == NULL) goto err;
if (!EC_POINT_get_affine_coordinates_GF2m(group, point, x, y, ctx)) goto err;
buf[0] = form;
if ((form != POINT_CONVERSION_UNCOMPRESSED) && !BN_is_zero(x))
{
if (!group->meth->field_div(group, yxi, y, x, ctx)) goto err;
if (BN_is_odd(yxi)) buf[0]++;
}
i = 1;
skip = field_len - BN_num_bytes(x);
if (skip > field_len)
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT2OCT, ERR_R_INTERNAL_ERROR);
goto err;
}
while (skip > 0)
{
buf[i++] = 0;
skip--;
}
skip = BN_bn2bin(x, buf + i);
i += skip;
if (i != 1 + field_len)
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT2OCT, ERR_R_INTERNAL_ERROR);
goto err;
}
if (form == POINT_CONVERSION_UNCOMPRESSED || form == POINT_CONVERSION_HYBRID)
{
skip = field_len - BN_num_bytes(y);
if (skip > field_len)
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT2OCT, ERR_R_INTERNAL_ERROR);
goto err;
}
while (skip > 0)
{
buf[i++] = 0;
skip--;
}
skip = BN_bn2bin(y, buf + i);
i += skip;
}
if (i != ret)
{
ECerr(EC_F_EC_GF2M_SIMPLE_POINT2OCT, ERR_R_INTERNAL_ERROR);
goto err;
}
}
if (used_ctx)
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
err:
if (used_ctx)
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return 0;
}
int ec_GF2m_simple_oct2point(const EC_GROUP *group, EC_POINT *point,
const unsigned char *buf, size_t len, BN_CTX *ctx)
{
point_conversion_form_t form;
int y_bit;
BN_CTX *new_ctx = NULL;
BIGNUM *x, *y, *yxi;
size_t field_len, enc_len;
int ret = 0;
if (len == 0)
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_BUFFER_TOO_SMALL);
return 0;
}
form = buf[0];
y_bit = form & 1;
form = form & ~1U;
if ((form != 0) && (form != POINT_CONVERSION_COMPRESSED)
&& (form != POINT_CONVERSION_UNCOMPRESSED)
&& (form != POINT_CONVERSION_HYBRID))
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
return 0;
}
if ((form == 0 || form == POINT_CONVERSION_UNCOMPRESSED) && y_bit)
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
return 0;
}
if (form == 0)
{
if (len != 1)
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
return 0;
}
return EC_POINT_set_to_infinity(group, point);
}
field_len = (EC_GROUP_get_degree(group) + 7) / 8;
enc_len = (form == POINT_CONVERSION_COMPRESSED) ? 1 + field_len : 1 + 2*field_len;
if (len != enc_len)
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
return 0;
}
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
x = BN_CTX_get(ctx);
y = BN_CTX_get(ctx);
yxi = BN_CTX_get(ctx);
if (yxi == NULL) goto err;
if (!BN_bin2bn(buf + 1, field_len, x)) goto err;
if (BN_ucmp(x, &group->field) >= 0)
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
goto err;
}
if (form == POINT_CONVERSION_COMPRESSED)
{
if (!EC_POINT_set_compressed_coordinates_GF2m(group, point, x, y_bit, ctx)) goto err;
}
else
{
if (!BN_bin2bn(buf + 1 + field_len, field_len, y)) goto err;
if (BN_ucmp(y, &group->field) >= 0)
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
goto err;
}
if (form == POINT_CONVERSION_HYBRID)
{
if (!group->meth->field_div(group, yxi, y, x, ctx)) goto err;
if (y_bit != BN_is_odd(yxi))
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
goto err;
}
}
if (!EC_POINT_set_affine_coordinates_GF2m(group, point, x, y, ctx)) goto err;
}
if (!EC_POINT_is_on_curve(group, point, ctx))
{
ECerr(EC_F_EC_GF2M_SIMPLE_OCT2POINT, EC_R_POINT_IS_NOT_ON_CURVE);
goto err;
}
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GF2m_simple_add(const EC_GROUP *group, EC_POINT *r, const EC_POINT *a, const EC_POINT *b, BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
BIGNUM *x0, *y0, *x1, *y1, *x2, *y2, *s, *t;
int ret = 0;
if (EC_POINT_is_at_infinity(group, a))
{
if (!EC_POINT_copy(r, b)) return 0;
return 1;
}
if (EC_POINT_is_at_infinity(group, b))
{
if (!EC_POINT_copy(r, a)) return 0;
return 1;
}
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
x0 = BN_CTX_get(ctx);
y0 = BN_CTX_get(ctx);
x1 = BN_CTX_get(ctx);
y1 = BN_CTX_get(ctx);
x2 = BN_CTX_get(ctx);
y2 = BN_CTX_get(ctx);
s = BN_CTX_get(ctx);
t = BN_CTX_get(ctx);
if (t == NULL) goto err;
if (a->Z_is_one)
{
if (!BN_copy(x0, &a->X)) goto err;
if (!BN_copy(y0, &a->Y)) goto err;
}
else
{
if (!EC_POINT_get_affine_coordinates_GF2m(group, a, x0, y0, ctx)) goto err;
}
if (b->Z_is_one)
{
if (!BN_copy(x1, &b->X)) goto err;
if (!BN_copy(y1, &b->Y)) goto err;
}
else
{
if (!EC_POINT_get_affine_coordinates_GF2m(group, b, x1, y1, ctx)) goto err;
}
if (BN_GF2m_cmp(x0, x1))
{
if (!BN_GF2m_add(t, x0, x1)) goto err;
if (!BN_GF2m_add(s, y0, y1)) goto err;
if (!group->meth->field_div(group, s, s, t, ctx)) goto err;
if (!group->meth->field_sqr(group, x2, s, ctx)) goto err;
if (!BN_GF2m_add(x2, x2, &group->a)) goto err;
if (!BN_GF2m_add(x2, x2, s)) goto err;
if (!BN_GF2m_add(x2, x2, t)) goto err;
}
else
{
if (BN_GF2m_cmp(y0, y1) || BN_is_zero(x1))
{
if (!EC_POINT_set_to_infinity(group, r)) goto err;
ret = 1;
goto err;
}
if (!group->meth->field_div(group, s, y1, x1, ctx)) goto err;
if (!BN_GF2m_add(s, s, x1)) goto err;
if (!group->meth->field_sqr(group, x2, s, ctx)) goto err;
if (!BN_GF2m_add(x2, x2, s)) goto err;
if (!BN_GF2m_add(x2, x2, &group->a)) goto err;
}
if (!BN_GF2m_add(y2, x1, x2)) goto err;
if (!group->meth->field_mul(group, y2, y2, s, ctx)) goto err;
if (!BN_GF2m_add(y2, y2, x2)) goto err;
if (!BN_GF2m_add(y2, y2, y1)) goto err;
if (!EC_POINT_set_affine_coordinates_GF2m(group, r, x2, y2, ctx)) goto err;
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GF2m_simple_dbl(const EC_GROUP *group, EC_POINT *r, const EC_POINT *a, BN_CTX *ctx)
{
return ec_GF2m_simple_add(group, r, a, a, ctx);
}
int ec_GF2m_simple_invert(const EC_GROUP *group, EC_POINT *point, BN_CTX *ctx)
{
if (EC_POINT_is_at_infinity(group, point) || BN_is_zero(&point->Y))
return 1;
if (!EC_POINT_make_affine(group, point, ctx)) return 0;
return BN_GF2m_add(&point->Y, &point->X, &point->Y);
}
int ec_GF2m_simple_is_at_infinity(const EC_GROUP *group, const EC_POINT *point)
{
return BN_is_zero(&point->Z);
}
int ec_GF2m_simple_is_on_curve(const EC_GROUP *group, const EC_POINT *point, BN_CTX *ctx)
{
int ret = -1;
BN_CTX *new_ctx = NULL;
BIGNUM *lh, *y2;
int (*field_mul)(const EC_GROUP *, BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
int (*field_sqr)(const EC_GROUP *, BIGNUM *, const BIGNUM *, BN_CTX *);
if (EC_POINT_is_at_infinity(group, point))
return 1;
field_mul = group->meth->field_mul;
field_sqr = group->meth->field_sqr;
if (!point->Z_is_one) goto err;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return -1;
}
BN_CTX_start(ctx);
y2 = BN_CTX_get(ctx);
lh = BN_CTX_get(ctx);
if (lh == NULL) goto err;
if (!BN_GF2m_add(lh, &point->X, &group->a)) goto err;
if (!field_mul(group, lh, lh, &point->X, ctx)) goto err;
if (!BN_GF2m_add(lh, lh, &point->Y)) goto err;
if (!field_mul(group, lh, lh, &point->X, ctx)) goto err;
if (!BN_GF2m_add(lh, lh, &group->b)) goto err;
if (!field_sqr(group, y2, &point->Y, ctx)) goto err;
if (!BN_GF2m_add(lh, lh, y2)) goto err;
ret = BN_is_zero(lh);
err:
if (ctx) BN_CTX_end(ctx);
if (new_ctx) BN_CTX_free(new_ctx);
return ret;
}
int ec_GF2m_simple_cmp(const EC_GROUP *group, const EC_POINT *a, const EC_POINT *b, BN_CTX *ctx)
{
BIGNUM *aX, *aY, *bX, *bY;
BN_CTX *new_ctx = NULL;
int ret = -1;
if (EC_POINT_is_at_infinity(group, a))
{
return EC_POINT_is_at_infinity(group, b) ? 0 : 1;
}
if (a->Z_is_one && b->Z_is_one)
{
return ((BN_cmp(&a->X, &b->X) == 0) && BN_cmp(&a->Y, &b->Y) == 0) ? 0 : 1;
}
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return -1;
}
BN_CTX_start(ctx);
aX = BN_CTX_get(ctx);
aY = BN_CTX_get(ctx);
bX = BN_CTX_get(ctx);
bY = BN_CTX_get(ctx);
if (bY == NULL) goto err;
if (!EC_POINT_get_affine_coordinates_GF2m(group, a, aX, aY, ctx)) goto err;
if (!EC_POINT_get_affine_coordinates_GF2m(group, b, bX, bY, ctx)) goto err;
ret = ((BN_cmp(aX, bX) == 0) && BN_cmp(aY, bY) == 0) ? 0 : 1;
err:
if (ctx) BN_CTX_end(ctx);
if (new_ctx) BN_CTX_free(new_ctx);
return ret;
}
int ec_GF2m_simple_make_affine(const EC_GROUP *group, EC_POINT *point, BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
BIGNUM *x, *y;
int ret = 0;
if (point->Z_is_one || EC_POINT_is_at_infinity(group, point))
return 1;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
x = BN_CTX_get(ctx);
y = BN_CTX_get(ctx);
if (y == NULL) goto err;
if (!EC_POINT_get_affine_coordinates_GF2m(group, point, x, y, ctx)) goto err;
if (!BN_copy(&point->X, x)) goto err;
if (!BN_copy(&point->Y, y)) goto err;
if (!BN_one(&point->Z)) goto err;
ret = 1;
err:
if (ctx) BN_CTX_end(ctx);
if (new_ctx) BN_CTX_free(new_ctx);
return ret;
}
int ec_GF2m_simple_points_make_affine(const EC_GROUP *group, size_t num, EC_POINT *points[], BN_CTX *ctx)
{
size_t i;
for (i = 0; i < num; i++)
{
if (!group->meth->make_affine(group, points[i], ctx)) return 0;
}
return 1;
}
int ec_GF2m_simple_field_mul(const EC_GROUP *group, BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
return BN_GF2m_mod_mul_arr(r, a, b, group->poly, ctx);
}
int ec_GF2m_simple_field_sqr(const EC_GROUP *group, BIGNUM *r, const BIGNUM *a, BN_CTX *ctx)
{
return BN_GF2m_mod_sqr_arr(r, a, group->poly, ctx);
}
int ec_GF2m_simple_field_div(const EC_GROUP *group, BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
return BN_GF2m_mod_div(r, a, b, &group->field, ctx);
}
