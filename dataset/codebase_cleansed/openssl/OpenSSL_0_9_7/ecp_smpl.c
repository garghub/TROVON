const EC_METHOD *EC_GFp_simple_method(void)
{
static const EC_METHOD ret = {
ec_GFp_simple_group_init,
ec_GFp_simple_group_finish,
ec_GFp_simple_group_clear_finish,
ec_GFp_simple_group_copy,
ec_GFp_simple_group_set_curve_GFp,
ec_GFp_simple_group_get_curve_GFp,
ec_GFp_simple_group_set_generator,
ec_GFp_simple_group_get0_generator,
ec_GFp_simple_group_get_order,
ec_GFp_simple_group_get_cofactor,
ec_GFp_simple_point_init,
ec_GFp_simple_point_finish,
ec_GFp_simple_point_clear_finish,
ec_GFp_simple_point_copy,
ec_GFp_simple_point_set_to_infinity,
ec_GFp_simple_set_Jprojective_coordinates_GFp,
ec_GFp_simple_get_Jprojective_coordinates_GFp,
ec_GFp_simple_point_set_affine_coordinates_GFp,
ec_GFp_simple_point_get_affine_coordinates_GFp,
ec_GFp_simple_set_compressed_coordinates_GFp,
ec_GFp_simple_point2oct,
ec_GFp_simple_oct2point,
ec_GFp_simple_add,
ec_GFp_simple_dbl,
ec_GFp_simple_invert,
ec_GFp_simple_is_at_infinity,
ec_GFp_simple_is_on_curve,
ec_GFp_simple_cmp,
ec_GFp_simple_make_affine,
ec_GFp_simple_points_make_affine,
ec_GFp_simple_field_mul,
ec_GFp_simple_field_sqr,
0 ,
0 ,
0 };
return &ret;
}
int ec_GFp_simple_group_init(EC_GROUP *group)
{
BN_init(&group->field);
BN_init(&group->a);
BN_init(&group->b);
group->a_is_minus3 = 0;
group->generator = NULL;
BN_init(&group->order);
BN_init(&group->cofactor);
return 1;
}
void ec_GFp_simple_group_finish(EC_GROUP *group)
{
BN_free(&group->field);
BN_free(&group->a);
BN_free(&group->b);
if (group->generator != NULL)
EC_POINT_free(group->generator);
BN_free(&group->order);
BN_free(&group->cofactor);
}
void ec_GFp_simple_group_clear_finish(EC_GROUP *group)
{
BN_clear_free(&group->field);
BN_clear_free(&group->a);
BN_clear_free(&group->b);
if (group->generator != NULL)
{
EC_POINT_clear_free(group->generator);
group->generator = NULL;
}
BN_clear_free(&group->order);
BN_clear_free(&group->cofactor);
}
int ec_GFp_simple_group_copy(EC_GROUP *dest, const EC_GROUP *src)
{
if (!BN_copy(&dest->field, &src->field)) return 0;
if (!BN_copy(&dest->a, &src->a)) return 0;
if (!BN_copy(&dest->b, &src->b)) return 0;
dest->a_is_minus3 = src->a_is_minus3;
if (src->generator != NULL)
{
if (dest->generator == NULL)
{
dest->generator = EC_POINT_new(dest);
if (dest->generator == NULL) return 0;
}
if (!EC_POINT_copy(dest->generator, src->generator)) return 0;
}
else
{
if (dest->generator != NULL)
{
EC_POINT_clear_free(dest->generator);
dest->generator = NULL;
}
}
if (!BN_copy(&dest->order, &src->order)) return 0;
if (!BN_copy(&dest->cofactor, &src->cofactor)) return 0;
return 1;
}
int ec_GFp_simple_group_set_curve_GFp(EC_GROUP *group,
const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
int ret = 0;
BN_CTX *new_ctx = NULL;
BIGNUM *tmp_a;
if (BN_num_bits(p) <= 2 || !BN_is_odd(p))
{
ECerr(EC_F_EC_GFP_SIMPLE_GROUP_SET_CURVE_GFP, EC_R_INVALID_FIELD);
return 0;
}
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
tmp_a = BN_CTX_get(ctx);
if (tmp_a == NULL) goto err;
if (!BN_copy(&group->field, p)) goto err;
group->field.neg = 0;
if (!BN_nnmod(tmp_a, a, p, ctx)) goto err;
if (group->meth->field_encode)
{ if (!group->meth->field_encode(group, &group->a, tmp_a, ctx)) goto err; }
else
if (!BN_copy(&group->a, tmp_a)) goto err;
if (!BN_nnmod(&group->b, b, p, ctx)) goto err;
if (group->meth->field_encode)
if (!group->meth->field_encode(group, &group->b, &group->b, ctx)) goto err;
if (!BN_add_word(tmp_a, 3)) goto err;
group->a_is_minus3 = (0 == BN_cmp(tmp_a, &group->field));
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_group_get_curve_GFp(const EC_GROUP *group, BIGNUM *p, BIGNUM *a, BIGNUM *b, BN_CTX *ctx)
{
int ret = 0;
BN_CTX *new_ctx = NULL;
if (p != NULL)
{
if (!BN_copy(p, &group->field)) return 0;
}
if (a != NULL || b != NULL)
{
if (group->meth->field_decode)
{
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
if (a != NULL)
{
if (!group->meth->field_decode(group, a, &group->a, ctx)) goto err;
}
if (b != NULL)
{
if (!group->meth->field_decode(group, b, &group->b, ctx)) goto err;
}
}
else
{
if (a != NULL)
{
if (!BN_copy(a, &group->a)) goto err;
}
if (b != NULL)
{
if (!BN_copy(b, &group->b)) goto err;
}
}
}
ret = 1;
err:
if (new_ctx)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_group_set_generator(EC_GROUP *group, const EC_POINT *generator,
const BIGNUM *order, const BIGNUM *cofactor)
{
if (generator == NULL)
{
ECerr(EC_F_EC_GFP_SIMPLE_GROUP_SET_GENERATOR, ERR_R_PASSED_NULL_PARAMETER);
return 0 ;
}
if (group->generator == NULL)
{
group->generator = EC_POINT_new(group);
if (group->generator == NULL) return 0;
}
if (!EC_POINT_copy(group->generator, generator)) return 0;
if (order != NULL)
{ if (!BN_copy(&group->order, order)) return 0; }
else
{ if (!BN_zero(&group->order)) return 0; }
if (cofactor != NULL)
{ if (!BN_copy(&group->cofactor, cofactor)) return 0; }
else
{ if (!BN_zero(&group->cofactor)) return 0; }
return 1;
}
EC_POINT *ec_GFp_simple_group_get0_generator(const EC_GROUP *group)
{
return group->generator;
}
int ec_GFp_simple_group_get_order(const EC_GROUP *group, BIGNUM *order, BN_CTX *ctx)
{
if (!BN_copy(order, &group->order))
return 0;
return !BN_is_zero(&group->order);
}
int ec_GFp_simple_group_get_cofactor(const EC_GROUP *group, BIGNUM *cofactor, BN_CTX *ctx)
{
if (!BN_copy(cofactor, &group->cofactor))
return 0;
return !BN_is_zero(&group->cofactor);
}
int ec_GFp_simple_point_init(EC_POINT *point)
{
BN_init(&point->X);
BN_init(&point->Y);
BN_init(&point->Z);
point->Z_is_one = 0;
return 1;
}
void ec_GFp_simple_point_finish(EC_POINT *point)
{
BN_free(&point->X);
BN_free(&point->Y);
BN_free(&point->Z);
}
void ec_GFp_simple_point_clear_finish(EC_POINT *point)
{
BN_clear_free(&point->X);
BN_clear_free(&point->Y);
BN_clear_free(&point->Z);
point->Z_is_one = 0;
}
int ec_GFp_simple_point_copy(EC_POINT *dest, const EC_POINT *src)
{
if (!BN_copy(&dest->X, &src->X)) return 0;
if (!BN_copy(&dest->Y, &src->Y)) return 0;
if (!BN_copy(&dest->Z, &src->Z)) return 0;
dest->Z_is_one = src->Z_is_one;
return 1;
}
int ec_GFp_simple_point_set_to_infinity(const EC_GROUP *group, EC_POINT *point)
{
point->Z_is_one = 0;
return (BN_zero(&point->Z));
}
int ec_GFp_simple_set_Jprojective_coordinates_GFp(const EC_GROUP *group, EC_POINT *point,
const BIGNUM *x, const BIGNUM *y, const BIGNUM *z, BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
int ret = 0;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
if (x != NULL)
{
if (!BN_nnmod(&point->X, x, &group->field, ctx)) goto err;
if (group->meth->field_encode)
{
if (!group->meth->field_encode(group, &point->X, &point->X, ctx)) goto err;
}
}
if (y != NULL)
{
if (!BN_nnmod(&point->Y, y, &group->field, ctx)) goto err;
if (group->meth->field_encode)
{
if (!group->meth->field_encode(group, &point->Y, &point->Y, ctx)) goto err;
}
}
if (z != NULL)
{
int Z_is_one;
if (!BN_nnmod(&point->Z, z, &group->field, ctx)) goto err;
Z_is_one = BN_is_one(&point->Z);
if (group->meth->field_encode)
{
if (Z_is_one && (group->meth->field_set_to_one != 0))
{
if (!group->meth->field_set_to_one(group, &point->Z, ctx)) goto err;
}
else
{
if (!group->meth->field_encode(group, &point->Z, &point->Z, ctx)) goto err;
}
}
point->Z_is_one = Z_is_one;
}
ret = 1;
err:
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_get_Jprojective_coordinates_GFp(const EC_GROUP *group, const EC_POINT *point,
BIGNUM *x, BIGNUM *y, BIGNUM *z, BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
int ret = 0;
if (group->meth->field_decode != 0)
{
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
if (x != NULL)
{
if (!group->meth->field_decode(group, x, &point->X, ctx)) goto err;
}
if (y != NULL)
{
if (!group->meth->field_decode(group, y, &point->Y, ctx)) goto err;
}
if (z != NULL)
{
if (!group->meth->field_decode(group, z, &point->Z, ctx)) goto err;
}
}
else
{
if (x != NULL)
{
if (!BN_copy(x, &point->X)) goto err;
}
if (y != NULL)
{
if (!BN_copy(y, &point->Y)) goto err;
}
if (z != NULL)
{
if (!BN_copy(z, &point->Z)) goto err;
}
}
ret = 1;
err:
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_point_set_affine_coordinates_GFp(const EC_GROUP *group, EC_POINT *point,
const BIGNUM *x, const BIGNUM *y, BN_CTX *ctx)
{
if (x == NULL || y == NULL)
{
ECerr(EC_F_EC_GFP_SIMPLE_POINT_SET_AFFINE_COORDINATES_GFP, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
return EC_POINT_set_Jprojective_coordinates_GFp(group, point, x, y, BN_value_one(), ctx);
}
int ec_GFp_simple_point_get_affine_coordinates_GFp(const EC_GROUP *group, const EC_POINT *point,
BIGNUM *x, BIGNUM *y, BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
BIGNUM *X, *Y, *Z, *Z_1, *Z_2, *Z_3;
const BIGNUM *X_, *Y_, *Z_;
int ret = 0;
if (EC_POINT_is_at_infinity(group, point))
{
ECerr(EC_F_EC_GFP_SIMPLE_POINT_GET_AFFINE_COORDINATES_GFP, EC_R_POINT_AT_INFINITY);
return 0;
}
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
X = BN_CTX_get(ctx);
Y = BN_CTX_get(ctx);
Z = BN_CTX_get(ctx);
Z_1 = BN_CTX_get(ctx);
Z_2 = BN_CTX_get(ctx);
Z_3 = BN_CTX_get(ctx);
if (Z_3 == NULL) goto err;
if (group->meth->field_decode)
{
if (!group->meth->field_decode(group, X, &point->X, ctx)) goto err;
if (!group->meth->field_decode(group, Y, &point->Y, ctx)) goto err;
if (!group->meth->field_decode(group, Z, &point->Z, ctx)) goto err;
X_ = X; Y_ = Y; Z_ = Z;
}
else
{
X_ = &point->X;
Y_ = &point->Y;
Z_ = &point->Z;
}
if (BN_is_one(Z_))
{
if (x != NULL)
{
if (!BN_copy(x, X_)) goto err;
}
if (y != NULL)
{
if (!BN_copy(y, Y_)) goto err;
}
}
else
{
if (!BN_mod_inverse(Z_1, Z_, &group->field, ctx))
{
ECerr(EC_F_EC_GFP_SIMPLE_POINT_GET_AFFINE_COORDINATES_GFP, ERR_R_BN_LIB);
goto err;
}
if (group->meth->field_encode == 0)
{
if (!group->meth->field_sqr(group, Z_2, Z_1, ctx)) goto err;
}
else
{
if (!BN_mod_sqr(Z_2, Z_1, &group->field, ctx)) goto err;
}
if (x != NULL)
{
if (group->meth->field_encode == 0)
{
if (!group->meth->field_mul(group, x, X_, Z_2, ctx)) goto err;
}
else
{
if (!BN_mod_mul(x, X_, Z_2, &group->field, ctx)) goto err;
}
}
if (y != NULL)
{
if (group->meth->field_encode == 0)
{
if (!group->meth->field_mul(group, Z_3, Z_2, Z_1, ctx)) goto err;
if (!group->meth->field_mul(group, y, Y_, Z_3, ctx)) goto err;
}
else
{
if (!BN_mod_mul(Z_3, Z_2, Z_1, &group->field, ctx)) goto err;
if (!BN_mod_mul(y, Y_, Z_3, &group->field, ctx)) goto err;
}
}
}
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_set_compressed_coordinates_GFp(const EC_GROUP *group, EC_POINT *point,
const BIGNUM *x_, int y_bit, BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
BIGNUM *tmp1, *tmp2, *x, *y;
int ret = 0;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
y_bit = (y_bit != 0);
BN_CTX_start(ctx);
tmp1 = BN_CTX_get(ctx);
tmp2 = BN_CTX_get(ctx);
x = BN_CTX_get(ctx);
y = BN_CTX_get(ctx);
if (y == NULL) goto err;
if (!BN_nnmod(x, x_, &group->field,ctx)) goto err;
if (group->meth->field_decode == 0)
{
if (!group->meth->field_sqr(group, tmp2, x_, ctx)) goto err;
if (!group->meth->field_mul(group, tmp1, tmp2, x_, ctx)) goto err;
}
else
{
if (!BN_mod_sqr(tmp2, x_, &group->field, ctx)) goto err;
if (!BN_mod_mul(tmp1, tmp2, x_, &group->field, ctx)) goto err;
}
if (group->a_is_minus3)
{
if (!BN_mod_lshift1_quick(tmp2, x, &group->field)) goto err;
if (!BN_mod_add_quick(tmp2, tmp2, x, &group->field)) goto err;
if (!BN_mod_sub_quick(tmp1, tmp1, tmp2, &group->field)) goto err;
}
else
{
if (group->meth->field_decode)
{
if (!group->meth->field_decode(group, tmp2, &group->a, ctx)) goto err;
if (!BN_mod_mul(tmp2, tmp2, x, &group->field, ctx)) goto err;
}
else
{
if (!group->meth->field_mul(group, tmp2, &group->a, x, ctx)) goto err;
}
if (!BN_mod_add_quick(tmp1, tmp1, tmp2, &group->field)) goto err;
}
if (group->meth->field_decode)
{
if (!group->meth->field_decode(group, tmp2, &group->b, ctx)) goto err;
if (!BN_mod_add_quick(tmp1, tmp1, tmp2, &group->field)) goto err;
}
else
{
if (!BN_mod_add_quick(tmp1, tmp1, &group->b, &group->field)) goto err;
}
if (!BN_mod_sqrt(y, tmp1, &group->field, ctx))
{
unsigned long err = ERR_peek_error();
if (ERR_GET_LIB(err) == ERR_LIB_BN && ERR_GET_REASON(err) == BN_R_NOT_A_SQUARE)
{
(void)ERR_get_error();
ECerr(EC_F_EC_GFP_SIMPLE_SET_COMPRESSED_COORDINATES_GFP, EC_R_INVALID_COMPRESSED_POINT);
}
else
ECerr(EC_F_EC_GFP_SIMPLE_SET_COMPRESSED_COORDINATES_GFP, ERR_R_BN_LIB);
goto err;
}
if (y_bit != BN_is_odd(y))
{
if (BN_is_zero(y))
{
int kron;
kron = BN_kronecker(x, &group->field, ctx);
if (kron == -2) goto err;
if (kron == 1)
ECerr(EC_F_EC_GFP_SIMPLE_SET_COMPRESSED_COORDINATES_GFP, EC_R_INVALID_COMPRESSION_BIT);
else
ECerr(EC_F_EC_GFP_SIMPLE_SET_COMPRESSED_COORDINATES_GFP, EC_R_INVALID_COMPRESSED_POINT);
goto err;
}
if (!BN_usub(y, &group->field, y)) goto err;
}
if (y_bit != BN_is_odd(y))
{
ECerr(EC_F_EC_GFP_SIMPLE_SET_COMPRESSED_COORDINATES_GFP, ERR_R_INTERNAL_ERROR);
goto err;
}
if (!EC_POINT_set_affine_coordinates_GFp(group, point, x, y, ctx)) goto err;
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
size_t ec_GFp_simple_point2oct(const EC_GROUP *group, const EC_POINT *point, point_conversion_form_t form,
unsigned char *buf, size_t len, BN_CTX *ctx)
{
size_t ret;
BN_CTX *new_ctx = NULL;
int used_ctx = 0;
BIGNUM *x, *y;
size_t field_len, i, skip;
if ((form != POINT_CONVERSION_COMPRESSED)
&& (form != POINT_CONVERSION_UNCOMPRESSED)
&& (form != POINT_CONVERSION_HYBRID))
{
ECerr(EC_F_EC_GFP_SIMPLE_POINT2OCT, EC_R_INVALID_FORM);
goto err;
}
if (EC_POINT_is_at_infinity(group, point))
{
if (buf != NULL)
{
if (len < 1)
{
ECerr(EC_F_EC_GFP_SIMPLE_POINT2OCT, EC_R_BUFFER_TOO_SMALL);
return 0;
}
buf[0] = 0;
}
return 1;
}
field_len = BN_num_bytes(&group->field);
ret = (form == POINT_CONVERSION_COMPRESSED) ? 1 + field_len : 1 + 2*field_len;
if (buf != NULL)
{
if (len < ret)
{
ECerr(EC_F_EC_GFP_SIMPLE_POINT2OCT, EC_R_BUFFER_TOO_SMALL);
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
if (y == NULL) goto err;
if (!EC_POINT_get_affine_coordinates_GFp(group, point, x, y, ctx)) goto err;
if ((form == POINT_CONVERSION_COMPRESSED || form == POINT_CONVERSION_HYBRID) && BN_is_odd(y))
buf[0] = form + 1;
else
buf[0] = form;
i = 1;
skip = field_len - BN_num_bytes(x);
if (skip > field_len)
{
ECerr(EC_F_EC_GFP_SIMPLE_POINT2OCT, ERR_R_INTERNAL_ERROR);
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
ECerr(EC_F_EC_GFP_SIMPLE_POINT2OCT, ERR_R_INTERNAL_ERROR);
goto err;
}
if (form == POINT_CONVERSION_UNCOMPRESSED || form == POINT_CONVERSION_HYBRID)
{
skip = field_len - BN_num_bytes(y);
if (skip > field_len)
{
ECerr(EC_F_EC_GFP_SIMPLE_POINT2OCT, ERR_R_INTERNAL_ERROR);
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
ECerr(EC_F_EC_GFP_SIMPLE_POINT2OCT, ERR_R_INTERNAL_ERROR);
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
int ec_GFp_simple_oct2point(const EC_GROUP *group, EC_POINT *point,
const unsigned char *buf, size_t len, BN_CTX *ctx)
{
point_conversion_form_t form;
int y_bit;
BN_CTX *new_ctx = NULL;
BIGNUM *x, *y;
size_t field_len, enc_len;
int ret = 0;
if (len == 0)
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_BUFFER_TOO_SMALL);
return 0;
}
form = buf[0];
y_bit = form & 1;
form = form & ~1;
if ((form != 0) && (form != POINT_CONVERSION_COMPRESSED)
&& (form != POINT_CONVERSION_UNCOMPRESSED)
&& (form != POINT_CONVERSION_HYBRID))
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
return 0;
}
if ((form == 0 || form == POINT_CONVERSION_UNCOMPRESSED) && y_bit)
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
return 0;
}
if (form == 0)
{
if (len != 1)
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
return 0;
}
return EC_POINT_set_to_infinity(group, point);
}
field_len = BN_num_bytes(&group->field);
enc_len = (form == POINT_CONVERSION_COMPRESSED) ? 1 + field_len : 1 + 2*field_len;
if (len != enc_len)
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
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
if (y == NULL) goto err;
if (!BN_bin2bn(buf + 1, field_len, x)) goto err;
if (BN_ucmp(x, &group->field) >= 0)
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
goto err;
}
if (form == POINT_CONVERSION_COMPRESSED)
{
if (!EC_POINT_set_compressed_coordinates_GFp(group, point, x, y_bit, ctx)) goto err;
}
else
{
if (!BN_bin2bn(buf + 1 + field_len, field_len, y)) goto err;
if (BN_ucmp(y, &group->field) >= 0)
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
goto err;
}
if (form == POINT_CONVERSION_HYBRID)
{
if (y_bit != BN_is_odd(y))
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_INVALID_ENCODING);
goto err;
}
}
if (!EC_POINT_set_affine_coordinates_GFp(group, point, x, y, ctx)) goto err;
}
if (!EC_POINT_is_on_curve(group, point, ctx))
{
ECerr(EC_F_EC_GFP_SIMPLE_OCT2POINT, EC_R_POINT_IS_NOT_ON_CURVE);
goto err;
}
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_add(const EC_GROUP *group, EC_POINT *r, const EC_POINT *a, const EC_POINT *b, BN_CTX *ctx)
{
int (*field_mul)(const EC_GROUP *, BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
int (*field_sqr)(const EC_GROUP *, BIGNUM *, const BIGNUM *, BN_CTX *);
const BIGNUM *p;
BN_CTX *new_ctx = NULL;
BIGNUM *n0, *n1, *n2, *n3, *n4, *n5, *n6;
int ret = 0;
if (a == b)
return EC_POINT_dbl(group, r, a, ctx);
if (EC_POINT_is_at_infinity(group, a))
return EC_POINT_copy(r, b);
if (EC_POINT_is_at_infinity(group, b))
return EC_POINT_copy(r, a);
field_mul = group->meth->field_mul;
field_sqr = group->meth->field_sqr;
p = &group->field;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
n0 = BN_CTX_get(ctx);
n1 = BN_CTX_get(ctx);
n2 = BN_CTX_get(ctx);
n3 = BN_CTX_get(ctx);
n4 = BN_CTX_get(ctx);
n5 = BN_CTX_get(ctx);
n6 = BN_CTX_get(ctx);
if (n6 == NULL) goto end;
if (b->Z_is_one)
{
if (!BN_copy(n1, &a->X)) goto end;
if (!BN_copy(n2, &a->Y)) goto end;
}
else
{
if (!field_sqr(group, n0, &b->Z, ctx)) goto end;
if (!field_mul(group, n1, &a->X, n0, ctx)) goto end;
if (!field_mul(group, n0, n0, &b->Z, ctx)) goto end;
if (!field_mul(group, n2, &a->Y, n0, ctx)) goto end;
}
if (a->Z_is_one)
{
if (!BN_copy(n3, &b->X)) goto end;
if (!BN_copy(n4, &b->Y)) goto end;
}
else
{
if (!field_sqr(group, n0, &a->Z, ctx)) goto end;
if (!field_mul(group, n3, &b->X, n0, ctx)) goto end;
if (!field_mul(group, n0, n0, &a->Z, ctx)) goto end;
if (!field_mul(group, n4, &b->Y, n0, ctx)) goto end;
}
if (!BN_mod_sub_quick(n5, n1, n3, p)) goto end;
if (!BN_mod_sub_quick(n6, n2, n4, p)) goto end;
if (BN_is_zero(n5))
{
if (BN_is_zero(n6))
{
BN_CTX_end(ctx);
ret = EC_POINT_dbl(group, r, a, ctx);
ctx = NULL;
goto end;
}
else
{
if (!BN_zero(&r->Z)) goto end;
r->Z_is_one = 0;
ret = 1;
goto end;
}
}
if (!BN_mod_add_quick(n1, n1, n3, p)) goto end;
if (!BN_mod_add_quick(n2, n2, n4, p)) goto end;
if (a->Z_is_one && b->Z_is_one)
{
if (!BN_copy(&r->Z, n5)) goto end;
}
else
{
if (a->Z_is_one)
{ if (!BN_copy(n0, &b->Z)) goto end; }
else if (b->Z_is_one)
{ if (!BN_copy(n0, &a->Z)) goto end; }
else
{ if (!field_mul(group, n0, &a->Z, &b->Z, ctx)) goto end; }
if (!field_mul(group, &r->Z, n0, n5, ctx)) goto end;
}
r->Z_is_one = 0;
if (!field_sqr(group, n0, n6, ctx)) goto end;
if (!field_sqr(group, n4, n5, ctx)) goto end;
if (!field_mul(group, n3, n1, n4, ctx)) goto end;
if (!BN_mod_sub_quick(&r->X, n0, n3, p)) goto end;
if (!BN_mod_lshift1_quick(n0, &r->X, p)) goto end;
if (!BN_mod_sub_quick(n0, n3, n0, p)) goto end;
if (!field_mul(group, n0, n0, n6, ctx)) goto end;
if (!field_mul(group, n5, n4, n5, ctx)) goto end;
if (!field_mul(group, n1, n2, n5, ctx)) goto end;
if (!BN_mod_sub_quick(n0, n0, n1, p)) goto end;
if (BN_is_odd(n0))
if (!BN_add(n0, n0, p)) goto end;
if (!BN_rshift1(&r->Y, n0)) goto end;
ret = 1;
end:
if (ctx)
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_dbl(const EC_GROUP *group, EC_POINT *r, const EC_POINT *a, BN_CTX *ctx)
{
int (*field_mul)(const EC_GROUP *, BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
int (*field_sqr)(const EC_GROUP *, BIGNUM *, const BIGNUM *, BN_CTX *);
const BIGNUM *p;
BN_CTX *new_ctx = NULL;
BIGNUM *n0, *n1, *n2, *n3;
int ret = 0;
if (EC_POINT_is_at_infinity(group, a))
{
if (!BN_zero(&r->Z)) return 0;
r->Z_is_one = 0;
return 1;
}
field_mul = group->meth->field_mul;
field_sqr = group->meth->field_sqr;
p = &group->field;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
n0 = BN_CTX_get(ctx);
n1 = BN_CTX_get(ctx);
n2 = BN_CTX_get(ctx);
n3 = BN_CTX_get(ctx);
if (n3 == NULL) goto err;
if (a->Z_is_one)
{
if (!field_sqr(group, n0, &a->X, ctx)) goto err;
if (!BN_mod_lshift1_quick(n1, n0, p)) goto err;
if (!BN_mod_add_quick(n0, n0, n1, p)) goto err;
if (!BN_mod_add_quick(n1, n0, &group->a, p)) goto err;
}
else if (group->a_is_minus3)
{
if (!field_sqr(group, n1, &a->Z, ctx)) goto err;
if (!BN_mod_add_quick(n0, &a->X, n1, p)) goto err;
if (!BN_mod_sub_quick(n2, &a->X, n1, p)) goto err;
if (!field_mul(group, n1, n0, n2, ctx)) goto err;
if (!BN_mod_lshift1_quick(n0, n1, p)) goto err;
if (!BN_mod_add_quick(n1, n0, n1, p)) goto err;
}
else
{
if (!field_sqr(group, n0, &a->X, ctx)) goto err;
if (!BN_mod_lshift1_quick(n1, n0, p)) goto err;
if (!BN_mod_add_quick(n0, n0, n1, p)) goto err;
if (!field_sqr(group, n1, &a->Z, ctx)) goto err;
if (!field_sqr(group, n1, n1, ctx)) goto err;
if (!field_mul(group, n1, n1, &group->a, ctx)) goto err;
if (!BN_mod_add_quick(n1, n1, n0, p)) goto err;
}
if (a->Z_is_one)
{
if (!BN_copy(n0, &a->Y)) goto err;
}
else
{
if (!field_mul(group, n0, &a->Y, &a->Z, ctx)) goto err;
}
if (!BN_mod_lshift1_quick(&r->Z, n0, p)) goto err;
r->Z_is_one = 0;
if (!field_sqr(group, n3, &a->Y, ctx)) goto err;
if (!field_mul(group, n2, &a->X, n3, ctx)) goto err;
if (!BN_mod_lshift_quick(n2, n2, 2, p)) goto err;
if (!BN_mod_lshift1_quick(n0, n2, p)) goto err;
if (!field_sqr(group, &r->X, n1, ctx)) goto err;
if (!BN_mod_sub_quick(&r->X, &r->X, n0, p)) goto err;
if (!field_sqr(group, n0, n3, ctx)) goto err;
if (!BN_mod_lshift_quick(n3, n0, 3, p)) goto err;
if (!BN_mod_sub_quick(n0, n2, &r->X, p)) goto err;
if (!field_mul(group, n0, n1, n0, ctx)) goto err;
if (!BN_mod_sub_quick(&r->Y, n0, n3, p)) goto err;
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_invert(const EC_GROUP *group, EC_POINT *point, BN_CTX *ctx)
{
if (EC_POINT_is_at_infinity(group, point) || BN_is_zero(&point->Y))
return 1;
return BN_usub(&point->Y, &group->field, &point->Y);
}
int ec_GFp_simple_is_at_infinity(const EC_GROUP *group, const EC_POINT *point)
{
return BN_is_zero(&point->Z);
}
int ec_GFp_simple_is_on_curve(const EC_GROUP *group, const EC_POINT *point, BN_CTX *ctx)
{
int (*field_mul)(const EC_GROUP *, BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
int (*field_sqr)(const EC_GROUP *, BIGNUM *, const BIGNUM *, BN_CTX *);
const BIGNUM *p;
BN_CTX *new_ctx = NULL;
BIGNUM *rh, *tmp1, *tmp2, *Z4, *Z6;
int ret = -1;
if (EC_POINT_is_at_infinity(group, point))
return 1;
field_mul = group->meth->field_mul;
field_sqr = group->meth->field_sqr;
p = &group->field;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return -1;
}
BN_CTX_start(ctx);
rh = BN_CTX_get(ctx);
tmp1 = BN_CTX_get(ctx);
tmp2 = BN_CTX_get(ctx);
Z4 = BN_CTX_get(ctx);
Z6 = BN_CTX_get(ctx);
if (Z6 == NULL) goto err;
if (!field_sqr(group, rh, &point->X, ctx)) goto err;
if (!field_mul(group, rh, rh, &point->X, ctx)) goto err;
if (!point->Z_is_one)
{
if (!field_sqr(group, tmp1, &point->Z, ctx)) goto err;
if (!field_sqr(group, Z4, tmp1, ctx)) goto err;
if (!field_mul(group, Z6, Z4, tmp1, ctx)) goto err;
if (!field_mul(group, tmp1, &point->X, Z4, ctx)) goto err;
if (group->a_is_minus3)
{
if (!BN_mod_lshift1_quick(tmp2, tmp1, p)) goto err;
if (!BN_mod_add_quick(tmp2, tmp2, tmp1, p)) goto err;
if (!BN_mod_sub_quick(rh, rh, tmp2, p)) goto err;
}
else
{
if (!field_mul(group, tmp2, tmp1, &group->a, ctx)) goto err;
if (!BN_mod_add_quick(rh, rh, tmp2, p)) goto err;
}
if (!field_mul(group, tmp1, &group->b, Z6, ctx)) goto err;
if (!BN_mod_add_quick(rh, rh, tmp1, p)) goto err;
}
else
{
if (group->a_is_minus3)
{
if (!BN_mod_lshift1_quick(tmp2, &point->X, p)) goto err;
if (!BN_mod_add_quick(tmp2, tmp2, &point->X, p)) goto err;
if (!BN_mod_sub_quick(rh, rh, tmp2, p)) goto err;
}
else
{
if (!field_mul(group, tmp2, &point->X, &group->a, ctx)) goto err;
if (!BN_mod_add_quick(rh, rh, tmp2, p)) goto err;
}
if (!BN_mod_add_quick(rh, rh, &group->b, p)) goto err;
}
if (!field_sqr(group, tmp1, &point->Y, ctx)) goto err;
ret = (0 == BN_cmp(tmp1, rh));
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_cmp(const EC_GROUP *group, const EC_POINT *a, const EC_POINT *b, BN_CTX *ctx)
{
int (*field_mul)(const EC_GROUP *, BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
int (*field_sqr)(const EC_GROUP *, BIGNUM *, const BIGNUM *, BN_CTX *);
BN_CTX *new_ctx = NULL;
BIGNUM *tmp1, *tmp2, *Za23, *Zb23;
const BIGNUM *tmp1_, *tmp2_;
int ret = -1;
if (EC_POINT_is_at_infinity(group, a))
{
return EC_POINT_is_at_infinity(group, b) ? 0 : 1;
}
if (a->Z_is_one && b->Z_is_one)
{
return ((BN_cmp(&a->X, &b->X) == 0) && BN_cmp(&a->Y, &b->Y) == 0) ? 0 : 1;
}
field_mul = group->meth->field_mul;
field_sqr = group->meth->field_sqr;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return -1;
}
BN_CTX_start(ctx);
tmp1 = BN_CTX_get(ctx);
tmp2 = BN_CTX_get(ctx);
Za23 = BN_CTX_get(ctx);
Zb23 = BN_CTX_get(ctx);
if (Zb23 == NULL) goto end;
if (!b->Z_is_one)
{
if (!field_sqr(group, Zb23, &b->Z, ctx)) goto end;
if (!field_mul(group, tmp1, &a->X, Zb23, ctx)) goto end;
tmp1_ = tmp1;
}
else
tmp1_ = &a->X;
if (!a->Z_is_one)
{
if (!field_sqr(group, Za23, &a->Z, ctx)) goto end;
if (!field_mul(group, tmp2, &b->X, Za23, ctx)) goto end;
tmp2_ = tmp2;
}
else
tmp2_ = &b->X;
if (BN_cmp(tmp1_, tmp2_) != 0)
{
ret = 1;
goto end;
}
if (!b->Z_is_one)
{
if (!field_mul(group, Zb23, Zb23, &b->Z, ctx)) goto end;
if (!field_mul(group, tmp1, &a->Y, Zb23, ctx)) goto end;
}
else
tmp1_ = &a->Y;
if (!a->Z_is_one)
{
if (!field_mul(group, Za23, Za23, &a->Z, ctx)) goto end;
if (!field_mul(group, tmp2, &b->Y, Za23, ctx)) goto end;
}
else
tmp2_ = &b->Y;
if (BN_cmp(tmp1_, tmp2_) != 0)
{
ret = 1;
goto end;
}
ret = 0;
end:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_make_affine(const EC_GROUP *group, EC_POINT *point, BN_CTX *ctx)
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
if (!EC_POINT_get_affine_coordinates_GFp(group, point, x, y, ctx)) goto err;
if (!EC_POINT_set_affine_coordinates_GFp(group, point, x, y, ctx)) goto err;
if (!point->Z_is_one)
{
ECerr(EC_F_EC_GFP_SIMPLE_MAKE_AFFINE, ERR_R_INTERNAL_ERROR);
goto err;
}
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_simple_points_make_affine(const EC_GROUP *group, size_t num, EC_POINT *points[], BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
BIGNUM *tmp0, *tmp1;
size_t pow2 = 0;
BIGNUM **heap = NULL;
size_t i;
int ret = 0;
if (num == 0)
return 1;
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
tmp0 = BN_CTX_get(ctx);
tmp1 = BN_CTX_get(ctx);
if (tmp0 == NULL || tmp1 == NULL) goto err;
pow2 = 1;
while (num > pow2)
pow2 <<= 1;
pow2 <<= 1;
heap = OPENSSL_malloc(pow2 * sizeof heap[0]);
if (heap == NULL) goto err;
heap[0] = NULL;
for (i = pow2/2 - 1; i > 0; i--)
heap[i] = NULL;
for (i = 0; i < num; i++)
heap[pow2/2 + i] = &points[i]->Z;
for (i = pow2/2 + num; i < pow2; i++)
heap[i] = NULL;
for (i = pow2/2 - 1; i > 0; i--)
{
heap[i] = BN_new();
if (heap[i] == NULL) goto err;
if (heap[2*i] != NULL)
{
if ((heap[2*i + 1] == NULL) || BN_is_zero(heap[2*i + 1]))
{
if (!BN_copy(heap[i], heap[2*i])) goto err;
}
else
{
if (BN_is_zero(heap[2*i]))
{
if (!BN_copy(heap[i], heap[2*i + 1])) goto err;
}
else
{
if (!group->meth->field_mul(group, heap[i],
heap[2*i], heap[2*i + 1], ctx)) goto err;
}
}
}
}
if (!BN_is_zero(heap[1]))
{
if (!BN_mod_inverse(heap[1], heap[1], &group->field, ctx))
{
ECerr(EC_F_EC_GFP_SIMPLE_POINTS_MAKE_AFFINE, ERR_R_BN_LIB);
goto err;
}
}
if (group->meth->field_encode != 0)
{
if (!group->meth->field_encode(group, heap[1], heap[1], ctx)) goto err;
if (!group->meth->field_encode(group, heap[1], heap[1], ctx)) goto err;
}
for (i = 2; i < pow2/2 + num; i += 2)
{
if ((heap[i + 1] != NULL) && !BN_is_zero(heap[i + 1]))
{
if (!group->meth->field_mul(group, tmp0, heap[i/2], heap[i + 1], ctx)) goto err;
if (!group->meth->field_mul(group, tmp1, heap[i/2], heap[i], ctx)) goto err;
if (!BN_copy(heap[i], tmp0)) goto err;
if (!BN_copy(heap[i + 1], tmp1)) goto err;
}
else
{
if (!BN_copy(heap[i], heap[i/2])) goto err;
}
}
for (i = 0; i < num; i++)
{
EC_POINT *p = points[i];
if (!BN_is_zero(&p->Z))
{
if (!group->meth->field_sqr(group, tmp1, &p->Z, ctx)) goto err;
if (!group->meth->field_mul(group, &p->X, &p->X, tmp1, ctx)) goto err;
if (!group->meth->field_mul(group, tmp1, tmp1, &p->Z, ctx)) goto err;
if (!group->meth->field_mul(group, &p->Y, &p->Y, tmp1, ctx)) goto err;
if (group->meth->field_set_to_one != 0)
{
if (!group->meth->field_set_to_one(group, &p->Z, ctx)) goto err;
}
else
{
if (!BN_one(&p->Z)) goto err;
}
p->Z_is_one = 1;
}
}
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
if (heap != NULL)
{
for (i = pow2/2 - 1; i > 0; i--)
{
if (heap[i] != NULL)
BN_clear_free(heap[i]);
}
OPENSSL_free(heap);
}
return ret;
}
int ec_GFp_simple_field_mul(const EC_GROUP *group, BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx)
{
return BN_mod_mul(r, a, b, &group->field, ctx);
}
int ec_GFp_simple_field_sqr(const EC_GROUP *group, BIGNUM *r, const BIGNUM *a, BN_CTX *ctx)
{
return BN_mod_sqr(r, a, &group->field, ctx);
}
