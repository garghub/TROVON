static signed char *compute_wNAF(const BIGNUM *scalar, int w, size_t *ret_len, BN_CTX *ctx)
{
BIGNUM *c;
int ok = 0;
signed char *r = NULL;
int sign = 1;
int bit, next_bit, mask;
size_t len = 0, j;
BN_CTX_start(ctx);
c = BN_CTX_get(ctx);
if (c == NULL) goto err;
if (w <= 0 || w > 7)
{
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
bit = 1 << w;
next_bit = bit << 1;
mask = next_bit - 1;
if (!BN_copy(c, scalar)) goto err;
if (c->neg)
{
sign = -1;
c->neg = 0;
}
len = BN_num_bits(c) + 1;
r = OPENSSL_malloc(len);
if (r == NULL) goto err;
j = 0;
while (!BN_is_zero(c))
{
int u = 0;
if (BN_is_odd(c))
{
if (c->d == NULL || c->top == 0)
{
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
u = c->d[0] & mask;
if (u & bit)
{
u -= next_bit;
if (!BN_add_word(c, -u)) goto err;
}
else
{
if (!BN_sub_word(c, u)) goto err;
}
if (u <= -bit || u >= bit || !(u & 1) || c->neg)
{
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
}
r[j++] = sign * u;
if (BN_is_odd(c))
{
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
if (!BN_rshift1(c, c)) goto err;
}
if (j > len)
{
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
len = j;
ok = 1;
err:
BN_CTX_end(ctx);
if (!ok)
{
OPENSSL_free(r);
r = NULL;
}
if (ok)
*ret_len = len;
return r;
}
int EC_POINTs_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar,
size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
EC_POINT *generator = NULL;
EC_POINT *tmp = NULL;
size_t totalnum;
size_t i, j;
int k;
int r_is_inverted = 0;
int r_is_at_infinity = 1;
size_t *wsize = NULL;
signed char **wNAF = NULL;
size_t *wNAF_len = NULL;
size_t max_len = 0;
size_t num_val;
EC_POINT **val = NULL;
EC_POINT **v;
EC_POINT ***val_sub = NULL;
int ret = 0;
if (scalar != NULL)
{
generator = EC_GROUP_get0_generator(group);
if (generator == NULL)
{
ECerr(EC_F_EC_POINTS_MUL, EC_R_UNDEFINED_GENERATOR);
return 0;
}
}
for (i = 0; i < num; i++)
{
if (group->meth != points[i]->meth)
{
ECerr(EC_F_EC_POINTS_MUL, EC_R_INCOMPATIBLE_OBJECTS);
return 0;
}
}
totalnum = num + (scalar != NULL);
wsize = OPENSSL_malloc(totalnum * sizeof wsize[0]);
wNAF_len = OPENSSL_malloc(totalnum * sizeof wNAF_len[0]);
wNAF = OPENSSL_malloc((totalnum + 1) * sizeof wNAF[0]);
if (wNAF != NULL)
{
wNAF[0] = NULL;
}
if (wsize == NULL || wNAF_len == NULL || wNAF == NULL) goto err;
num_val = 0;
for (i = 0; i < totalnum; i++)
{
size_t bits;
bits = i < num ? BN_num_bits(scalars[i]) : BN_num_bits(scalar);
wsize[i] = EC_window_bits_for_scalar_size(bits);
num_val += 1u << (wsize[i] - 1);
}
val = OPENSSL_malloc((num_val + 1) * sizeof val[0]);
if (val == NULL) goto err;
val[num_val] = NULL;
val_sub = OPENSSL_malloc(totalnum * sizeof val_sub[0]);
if (val_sub == NULL) goto err;
v = val;
for (i = 0; i < totalnum; i++)
{
val_sub[i] = v;
for (j = 0; j < (1u << (wsize[i] - 1)); j++)
{
*v = EC_POINT_new(group);
if (*v == NULL) goto err;
v++;
}
}
if (!(v == val + num_val))
{
ECerr(EC_F_EC_POINTS_MUL, ERR_R_INTERNAL_ERROR);
goto err;
}
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
}
tmp = EC_POINT_new(group);
if (tmp == NULL) goto err;
for (i = 0; i < totalnum; i++)
{
if (i < num)
{
if (!EC_POINT_copy(val_sub[i][0], points[i])) goto err;
}
else
{
if (!EC_POINT_copy(val_sub[i][0], generator)) goto err;
}
if (wsize[i] > 1)
{
if (!EC_POINT_dbl(group, tmp, val_sub[i][0], ctx)) goto err;
for (j = 1; j < (1u << (wsize[i] - 1)); j++)
{
if (!EC_POINT_add(group, val_sub[i][j], val_sub[i][j - 1], tmp, ctx)) goto err;
}
}
wNAF[i + 1] = NULL;
wNAF[i] = compute_wNAF((i < num ? scalars[i] : scalar), wsize[i], &wNAF_len[i], ctx);
if (wNAF[i] == NULL) goto err;
if (wNAF_len[i] > max_len)
max_len = wNAF_len[i];
}
#if 1
if (!EC_POINTs_make_affine(group, num_val, val, ctx)) goto err;
#endif
r_is_at_infinity = 1;
for (k = max_len - 1; k >= 0; k--)
{
if (!r_is_at_infinity)
{
if (!EC_POINT_dbl(group, r, r, ctx)) goto err;
}
for (i = 0; i < totalnum; i++)
{
if (wNAF_len[i] > (size_t)k)
{
int digit = wNAF[i][k];
int is_neg;
if (digit)
{
is_neg = digit < 0;
if (is_neg)
digit = -digit;
if (is_neg != r_is_inverted)
{
if (!r_is_at_infinity)
{
if (!EC_POINT_invert(group, r, ctx)) goto err;
}
r_is_inverted = !r_is_inverted;
}
if (r_is_at_infinity)
{
if (!EC_POINT_copy(r, val_sub[i][digit >> 1])) goto err;
r_is_at_infinity = 0;
}
else
{
if (!EC_POINT_add(group, r, r, val_sub[i][digit >> 1], ctx)) goto err;
}
}
}
}
}
if (r_is_at_infinity)
{
if (!EC_POINT_set_to_infinity(group, r)) goto err;
}
else
{
if (r_is_inverted)
if (!EC_POINT_invert(group, r, ctx)) goto err;
}
ret = 1;
err:
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
if (tmp != NULL)
EC_POINT_free(tmp);
if (wsize != NULL)
OPENSSL_free(wsize);
if (wNAF_len != NULL)
OPENSSL_free(wNAF_len);
if (wNAF != NULL)
{
signed char **w;
for (w = wNAF; *w != NULL; w++)
OPENSSL_free(*w);
OPENSSL_free(wNAF);
}
if (val != NULL)
{
for (v = val; *v != NULL; v++)
EC_POINT_clear_free(*v);
OPENSSL_free(val);
}
if (val_sub != NULL)
{
OPENSSL_free(val_sub);
}
return ret;
}
int EC_POINT_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *g_scalar, const EC_POINT *point, const BIGNUM *p_scalar, BN_CTX *ctx)
{
const EC_POINT *points[1];
const BIGNUM *scalars[1];
points[0] = point;
scalars[0] = p_scalar;
return EC_POINTs_mul(group, r, g_scalar, (point != NULL && p_scalar != NULL), points, scalars, ctx);
}
int EC_GROUP_precompute_mult(EC_GROUP *group, BN_CTX *ctx)
{
const EC_POINT *generator;
BN_CTX *new_ctx = NULL;
BIGNUM *order;
int ret = 0;
generator = EC_GROUP_get0_generator(group);
if (generator == NULL)
{
ECerr(EC_F_EC_GROUP_PRECOMPUTE_MULT, EC_R_UNDEFINED_GENERATOR);
return 0;
}
if (ctx == NULL)
{
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
return 0;
}
BN_CTX_start(ctx);
order = BN_CTX_get(ctx);
if (order == NULL) goto err;
if (!EC_GROUP_get_order(group, order, ctx)) return 0;
if (BN_is_zero(order))
{
ECerr(EC_F_EC_GROUP_PRECOMPUTE_MULT, EC_R_UNKNOWN_ORDER);
goto err;
}
ret = 1;
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
