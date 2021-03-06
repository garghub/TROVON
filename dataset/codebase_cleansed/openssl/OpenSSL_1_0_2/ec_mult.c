static EC_PRE_COMP *ec_pre_comp_new(const EC_GROUP *group)
{
EC_PRE_COMP *ret = NULL;
if (!group)
return NULL;
ret = (EC_PRE_COMP *)OPENSSL_malloc(sizeof(EC_PRE_COMP));
if (!ret) {
ECerr(EC_F_EC_PRE_COMP_NEW, ERR_R_MALLOC_FAILURE);
return ret;
}
ret->group = group;
ret->blocksize = 8;
ret->numblocks = 0;
ret->w = 4;
ret->points = NULL;
ret->num = 0;
ret->references = 1;
return ret;
}
static void *ec_pre_comp_dup(void *src_)
{
EC_PRE_COMP *src = src_;
CRYPTO_add(&src->references, 1, CRYPTO_LOCK_EC_PRE_COMP);
return src_;
}
static void ec_pre_comp_free(void *pre_)
{
int i;
EC_PRE_COMP *pre = pre_;
if (!pre)
return;
i = CRYPTO_add(&pre->references, -1, CRYPTO_LOCK_EC_PRE_COMP);
if (i > 0)
return;
if (pre->points) {
EC_POINT **p;
for (p = pre->points; *p != NULL; p++)
EC_POINT_free(*p);
OPENSSL_free(pre->points);
}
OPENSSL_free(pre);
}
static void ec_pre_comp_clear_free(void *pre_)
{
int i;
EC_PRE_COMP *pre = pre_;
if (!pre)
return;
i = CRYPTO_add(&pre->references, -1, CRYPTO_LOCK_EC_PRE_COMP);
if (i > 0)
return;
if (pre->points) {
EC_POINT **p;
for (p = pre->points; *p != NULL; p++) {
EC_POINT_clear_free(*p);
OPENSSL_cleanse(p, sizeof *p);
}
OPENSSL_free(pre->points);
}
OPENSSL_cleanse(pre, sizeof *pre);
OPENSSL_free(pre);
}
static signed char *compute_wNAF(const BIGNUM *scalar, int w, size_t *ret_len)
{
int window_val;
int ok = 0;
signed char *r = NULL;
int sign = 1;
int bit, next_bit, mask;
size_t len = 0, j;
if (BN_is_zero(scalar)) {
r = OPENSSL_malloc(1);
if (!r) {
ECerr(EC_F_COMPUTE_WNAF, ERR_R_MALLOC_FAILURE);
goto err;
}
r[0] = 0;
*ret_len = 1;
return r;
}
if (w <= 0 || w > 7) {
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
bit = 1 << w;
next_bit = bit << 1;
mask = next_bit - 1;
if (BN_is_negative(scalar)) {
sign = -1;
}
if (scalar->d == NULL || scalar->top == 0) {
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
len = BN_num_bits(scalar);
r = OPENSSL_malloc(len + 1);
if (r == NULL) {
ECerr(EC_F_COMPUTE_WNAF, ERR_R_MALLOC_FAILURE);
goto err;
}
window_val = scalar->d[0] & mask;
j = 0;
while ((window_val != 0) || (j + w + 1 < len)) {
int digit = 0;
if (window_val & 1) {
if (window_val & bit) {
digit = window_val - next_bit;
#if 1
if (j + w + 1 >= len) {
digit = window_val & (mask >> 1);
}
#endif
} else {
digit = window_val;
}
if (digit <= -bit || digit >= bit || !(digit & 1)) {
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
window_val -= digit;
if (window_val != 0 && window_val != next_bit
&& window_val != bit) {
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
}
r[j++] = sign * digit;
window_val >>= 1;
window_val += bit * BN_is_bit_set(scalar, j + w);
if (window_val > next_bit) {
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
}
if (j > len + 1) {
ECerr(EC_F_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
len = j;
ok = 1;
err:
if (!ok) {
OPENSSL_free(r);
r = NULL;
}
if (ok)
*ret_len = len;
return r;
}
int ec_wNAF_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar,
size_t num, const EC_POINT *points[], const BIGNUM *scalars[],
BN_CTX *ctx)
{
BN_CTX *new_ctx = NULL;
const EC_POINT *generator = NULL;
EC_POINT *tmp = NULL;
size_t totalnum;
size_t blocksize = 0, numblocks = 0;
size_t pre_points_per_block = 0;
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
const EC_PRE_COMP *pre_comp = NULL;
int num_scalar = 0;
int ret = 0;
if (group->meth != r->meth) {
ECerr(EC_F_EC_WNAF_MUL, EC_R_INCOMPATIBLE_OBJECTS);
return 0;
}
if ((scalar == NULL) && (num == 0)) {
return EC_POINT_set_to_infinity(group, r);
}
for (i = 0; i < num; i++) {
if (group->meth != points[i]->meth) {
ECerr(EC_F_EC_WNAF_MUL, EC_R_INCOMPATIBLE_OBJECTS);
return 0;
}
}
if (ctx == NULL) {
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
}
if (scalar != NULL) {
generator = EC_GROUP_get0_generator(group);
if (generator == NULL) {
ECerr(EC_F_EC_WNAF_MUL, EC_R_UNDEFINED_GENERATOR);
goto err;
}
pre_comp =
EC_EX_DATA_get_data(group->extra_data, ec_pre_comp_dup,
ec_pre_comp_free, ec_pre_comp_clear_free);
if (pre_comp && pre_comp->numblocks
&& (EC_POINT_cmp(group, generator, pre_comp->points[0], ctx) ==
0)) {
blocksize = pre_comp->blocksize;
numblocks = (BN_num_bits(scalar) / blocksize) + 1;
if (numblocks > pre_comp->numblocks)
numblocks = pre_comp->numblocks;
pre_points_per_block = (size_t)1 << (pre_comp->w - 1);
if (pre_comp->num != (pre_comp->numblocks * pre_points_per_block)) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_INTERNAL_ERROR);
goto err;
}
} else {
pre_comp = NULL;
numblocks = 1;
num_scalar = 1;
}
}
totalnum = num + numblocks;
wsize = OPENSSL_malloc(totalnum * sizeof wsize[0]);
wNAF_len = OPENSSL_malloc(totalnum * sizeof wNAF_len[0]);
wNAF = OPENSSL_malloc((totalnum + 1) * sizeof wNAF[0]);
val_sub = OPENSSL_malloc(totalnum * sizeof val_sub[0]);
if (wNAF)
wNAF[0] = NULL;
if (!wsize || !wNAF_len || !wNAF || !val_sub) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_MALLOC_FAILURE);
goto err;
}
num_val = 0;
for (i = 0; i < num + num_scalar; i++) {
size_t bits;
bits = i < num ? BN_num_bits(scalars[i]) : BN_num_bits(scalar);
wsize[i] = EC_window_bits_for_scalar_size(bits);
num_val += (size_t)1 << (wsize[i] - 1);
wNAF[i + 1] = NULL;
wNAF[i] =
compute_wNAF((i < num ? scalars[i] : scalar), wsize[i],
&wNAF_len[i]);
if (wNAF[i] == NULL)
goto err;
if (wNAF_len[i] > max_len)
max_len = wNAF_len[i];
}
if (numblocks) {
if (pre_comp == NULL) {
if (num_scalar != 1) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_INTERNAL_ERROR);
goto err;
}
} else {
signed char *tmp_wNAF = NULL;
size_t tmp_len = 0;
if (num_scalar != 0) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_INTERNAL_ERROR);
goto err;
}
wsize[num] = pre_comp->w;
tmp_wNAF = compute_wNAF(scalar, wsize[num], &tmp_len);
if (!tmp_wNAF)
goto err;
if (tmp_len <= max_len) {
numblocks = 1;
totalnum = num + 1;
wNAF[num] = tmp_wNAF;
wNAF[num + 1] = NULL;
wNAF_len[num] = tmp_len;
if (tmp_len > max_len)
max_len = tmp_len;
val_sub[num] = pre_comp->points;
} else {
signed char *pp;
EC_POINT **tmp_points;
if (tmp_len < numblocks * blocksize) {
numblocks = (tmp_len + blocksize - 1) / blocksize;
if (numblocks > pre_comp->numblocks) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_INTERNAL_ERROR);
goto err;
}
totalnum = num + numblocks;
}
pp = tmp_wNAF;
tmp_points = pre_comp->points;
for (i = num; i < totalnum; i++) {
if (i < totalnum - 1) {
wNAF_len[i] = blocksize;
if (tmp_len < blocksize) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_INTERNAL_ERROR);
goto err;
}
tmp_len -= blocksize;
} else
wNAF_len[i] = tmp_len;
wNAF[i + 1] = NULL;
wNAF[i] = OPENSSL_malloc(wNAF_len[i]);
if (wNAF[i] == NULL) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_MALLOC_FAILURE);
OPENSSL_free(tmp_wNAF);
goto err;
}
memcpy(wNAF[i], pp, wNAF_len[i]);
if (wNAF_len[i] > max_len)
max_len = wNAF_len[i];
if (*tmp_points == NULL) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_INTERNAL_ERROR);
OPENSSL_free(tmp_wNAF);
goto err;
}
val_sub[i] = tmp_points;
tmp_points += pre_points_per_block;
pp += blocksize;
}
OPENSSL_free(tmp_wNAF);
}
}
}
val = OPENSSL_malloc((num_val + 1) * sizeof val[0]);
if (val == NULL) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_MALLOC_FAILURE);
goto err;
}
val[num_val] = NULL;
v = val;
for (i = 0; i < num + num_scalar; i++) {
val_sub[i] = v;
for (j = 0; j < ((size_t)1 << (wsize[i] - 1)); j++) {
*v = EC_POINT_new(group);
if (*v == NULL)
goto err;
v++;
}
}
if (!(v == val + num_val)) {
ECerr(EC_F_EC_WNAF_MUL, ERR_R_INTERNAL_ERROR);
goto err;
}
if (!(tmp = EC_POINT_new(group)))
goto err;
for (i = 0; i < num + num_scalar; i++) {
if (i < num) {
if (!EC_POINT_copy(val_sub[i][0], points[i]))
goto err;
} else {
if (!EC_POINT_copy(val_sub[i][0], generator))
goto err;
}
if (wsize[i] > 1) {
if (!EC_POINT_dbl(group, tmp, val_sub[i][0], ctx))
goto err;
for (j = 1; j < ((size_t)1 << (wsize[i] - 1)); j++) {
if (!EC_POINT_add
(group, val_sub[i][j], val_sub[i][j - 1], tmp, ctx))
goto err;
}
}
}
#if 1
if (!EC_POINTs_make_affine(group, num_val, val, ctx))
goto err;
#endif
r_is_at_infinity = 1;
for (k = max_len - 1; k >= 0; k--) {
if (!r_is_at_infinity) {
if (!EC_POINT_dbl(group, r, r, ctx))
goto err;
}
for (i = 0; i < totalnum; i++) {
if (wNAF_len[i] > (size_t)k) {
int digit = wNAF[i][k];
int is_neg;
if (digit) {
is_neg = digit < 0;
if (is_neg)
digit = -digit;
if (is_neg != r_is_inverted) {
if (!r_is_at_infinity) {
if (!EC_POINT_invert(group, r, ctx))
goto err;
}
r_is_inverted = !r_is_inverted;
}
if (r_is_at_infinity) {
if (!EC_POINT_copy(r, val_sub[i][digit >> 1]))
goto err;
r_is_at_infinity = 0;
} else {
if (!EC_POINT_add
(group, r, r, val_sub[i][digit >> 1], ctx))
goto err;
}
}
}
}
}
if (r_is_at_infinity) {
if (!EC_POINT_set_to_infinity(group, r))
goto err;
} else {
if (r_is_inverted)
if (!EC_POINT_invert(group, r, ctx))
goto err;
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
if (wNAF != NULL) {
signed char **w;
for (w = wNAF; *w != NULL; w++)
OPENSSL_free(*w);
OPENSSL_free(wNAF);
}
if (val != NULL) {
for (v = val; *v != NULL; v++)
EC_POINT_clear_free(*v);
OPENSSL_free(val);
}
if (val_sub != NULL) {
OPENSSL_free(val_sub);
}
return ret;
}
int ec_wNAF_precompute_mult(EC_GROUP *group, BN_CTX *ctx)
{
const EC_POINT *generator;
EC_POINT *tmp_point = NULL, *base = NULL, **var;
BN_CTX *new_ctx = NULL;
BIGNUM *order;
size_t i, bits, w, pre_points_per_block, blocksize, numblocks, num;
EC_POINT **points = NULL;
EC_PRE_COMP *pre_comp;
int ret = 0;
EC_EX_DATA_free_data(&group->extra_data, ec_pre_comp_dup,
ec_pre_comp_free, ec_pre_comp_clear_free);
if ((pre_comp = ec_pre_comp_new(group)) == NULL)
return 0;
generator = EC_GROUP_get0_generator(group);
if (generator == NULL) {
ECerr(EC_F_EC_WNAF_PRECOMPUTE_MULT, EC_R_UNDEFINED_GENERATOR);
goto err;
}
if (ctx == NULL) {
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
}
BN_CTX_start(ctx);
order = BN_CTX_get(ctx);
if (order == NULL)
goto err;
if (!EC_GROUP_get_order(group, order, ctx))
goto err;
if (BN_is_zero(order)) {
ECerr(EC_F_EC_WNAF_PRECOMPUTE_MULT, EC_R_UNKNOWN_ORDER);
goto err;
}
bits = BN_num_bits(order);
blocksize = 8;
w = 4;
if (EC_window_bits_for_scalar_size(bits) > w) {
w = EC_window_bits_for_scalar_size(bits);
}
numblocks = (bits + blocksize - 1) / blocksize;
pre_points_per_block = (size_t)1 << (w - 1);
num = pre_points_per_block * numblocks;
points = OPENSSL_malloc(sizeof(EC_POINT *) * (num + 1));
if (!points) {
ECerr(EC_F_EC_WNAF_PRECOMPUTE_MULT, ERR_R_MALLOC_FAILURE);
goto err;
}
var = points;
var[num] = NULL;
for (i = 0; i < num; i++) {
if ((var[i] = EC_POINT_new(group)) == NULL) {
ECerr(EC_F_EC_WNAF_PRECOMPUTE_MULT, ERR_R_MALLOC_FAILURE);
goto err;
}
}
if (!(tmp_point = EC_POINT_new(group)) || !(base = EC_POINT_new(group))) {
ECerr(EC_F_EC_WNAF_PRECOMPUTE_MULT, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!EC_POINT_copy(base, generator))
goto err;
for (i = 0; i < numblocks; i++) {
size_t j;
if (!EC_POINT_dbl(group, tmp_point, base, ctx))
goto err;
if (!EC_POINT_copy(*var++, base))
goto err;
for (j = 1; j < pre_points_per_block; j++, var++) {
if (!EC_POINT_add(group, *var, tmp_point, *(var - 1), ctx))
goto err;
}
if (i < numblocks - 1) {
size_t k;
if (blocksize <= 2) {
ECerr(EC_F_EC_WNAF_PRECOMPUTE_MULT, ERR_R_INTERNAL_ERROR);
goto err;
}
if (!EC_POINT_dbl(group, base, tmp_point, ctx))
goto err;
for (k = 2; k < blocksize; k++) {
if (!EC_POINT_dbl(group, base, base, ctx))
goto err;
}
}
}
if (!EC_POINTs_make_affine(group, num, points, ctx))
goto err;
pre_comp->group = group;
pre_comp->blocksize = blocksize;
pre_comp->numblocks = numblocks;
pre_comp->w = w;
pre_comp->points = points;
points = NULL;
pre_comp->num = num;
if (!EC_EX_DATA_set_data(&group->extra_data, pre_comp,
ec_pre_comp_dup, ec_pre_comp_free,
ec_pre_comp_clear_free))
goto err;
pre_comp = NULL;
ret = 1;
err:
if (ctx != NULL)
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
if (pre_comp)
ec_pre_comp_free(pre_comp);
if (points) {
EC_POINT **p;
for (p = points; *p != NULL; p++)
EC_POINT_free(*p);
OPENSSL_free(points);
}
if (tmp_point)
EC_POINT_free(tmp_point);
if (base)
EC_POINT_free(base);
return ret;
}
int ec_wNAF_have_precompute_mult(const EC_GROUP *group)
{
if (EC_EX_DATA_get_data
(group->extra_data, ec_pre_comp_dup, ec_pre_comp_free,
ec_pre_comp_clear_free) != NULL)
return 1;
else
return 0;
}
