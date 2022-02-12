static unsigned int _booth_recode_w5(unsigned int in)
{
unsigned int s, d;
s = ~((in >> 5) - 1);
d = (1 << 6) - in - 1;
d = (d & s) | (in & ~s);
d = (d >> 1) + (d & 1);
return (d << 1) + (s & 1);
}
static unsigned int _booth_recode_w7(unsigned int in)
{
unsigned int s, d;
s = ~((in >> 7) - 1);
d = (1 << 8) - in - 1;
d = (d & s) | (in & ~s);
d = (d >> 1) + (d & 1);
return (d << 1) + (s & 1);
}
static void copy_conditional(BN_ULONG dst[P256_LIMBS],
const BN_ULONG src[P256_LIMBS], BN_ULONG move)
{
BN_ULONG mask1 = 0-move;
BN_ULONG mask2 = ~mask1;
dst[0] = (src[0] & mask1) ^ (dst[0] & mask2);
dst[1] = (src[1] & mask1) ^ (dst[1] & mask2);
dst[2] = (src[2] & mask1) ^ (dst[2] & mask2);
dst[3] = (src[3] & mask1) ^ (dst[3] & mask2);
if (P256_LIMBS == 8) {
dst[4] = (src[4] & mask1) ^ (dst[4] & mask2);
dst[5] = (src[5] & mask1) ^ (dst[5] & mask2);
dst[6] = (src[6] & mask1) ^ (dst[6] & mask2);
dst[7] = (src[7] & mask1) ^ (dst[7] & mask2);
}
}
static BN_ULONG is_zero(BN_ULONG in)
{
in |= (0 - in);
in = ~in;
in >>= BN_BITS2 - 1;
return in;
}
static BN_ULONG is_equal(const BN_ULONG a[P256_LIMBS],
const BN_ULONG b[P256_LIMBS])
{
BN_ULONG res;
res = a[0] ^ b[0];
res |= a[1] ^ b[1];
res |= a[2] ^ b[2];
res |= a[3] ^ b[3];
if (P256_LIMBS == 8) {
res |= a[4] ^ b[4];
res |= a[5] ^ b[5];
res |= a[6] ^ b[6];
res |= a[7] ^ b[7];
}
return is_zero(res);
}
static BN_ULONG is_one(const BIGNUM *z)
{
BN_ULONG res = 0;
BN_ULONG *a = bn_get_words(z);
if (bn_get_top(z) == (P256_LIMBS - P256_LIMBS / 8)) {
res = a[0] ^ ONE[0];
res |= a[1] ^ ONE[1];
res |= a[2] ^ ONE[2];
res |= a[3] ^ ONE[3];
if (P256_LIMBS == 8) {
res |= a[4] ^ ONE[4];
res |= a[5] ^ ONE[5];
res |= a[6] ^ ONE[6];
}
res = is_zero(res);
}
return res;
}
static void ecp_nistz256_point_double(P256_POINT *r, const P256_POINT *a)
{
BN_ULONG S[P256_LIMBS];
BN_ULONG M[P256_LIMBS];
BN_ULONG Zsqr[P256_LIMBS];
BN_ULONG tmp0[P256_LIMBS];
const BN_ULONG *in_x = a->X;
const BN_ULONG *in_y = a->Y;
const BN_ULONG *in_z = a->Z;
BN_ULONG *res_x = r->X;
BN_ULONG *res_y = r->Y;
BN_ULONG *res_z = r->Z;
ecp_nistz256_mul_by_2(S, in_y);
ecp_nistz256_sqr_mont(Zsqr, in_z);
ecp_nistz256_sqr_mont(S, S);
ecp_nistz256_mul_mont(res_z, in_z, in_y);
ecp_nistz256_mul_by_2(res_z, res_z);
ecp_nistz256_add(M, in_x, Zsqr);
ecp_nistz256_sub(Zsqr, in_x, Zsqr);
ecp_nistz256_sqr_mont(res_y, S);
ecp_nistz256_div_by_2(res_y, res_y);
ecp_nistz256_mul_mont(M, M, Zsqr);
ecp_nistz256_mul_by_3(M, M);
ecp_nistz256_mul_mont(S, S, in_x);
ecp_nistz256_mul_by_2(tmp0, S);
ecp_nistz256_sqr_mont(res_x, M);
ecp_nistz256_sub(res_x, res_x, tmp0);
ecp_nistz256_sub(S, S, res_x);
ecp_nistz256_mul_mont(S, S, M);
ecp_nistz256_sub(res_y, S, res_y);
}
static void ecp_nistz256_point_add(P256_POINT *r,
const P256_POINT *a, const P256_POINT *b)
{
BN_ULONG U2[P256_LIMBS], S2[P256_LIMBS];
BN_ULONG U1[P256_LIMBS], S1[P256_LIMBS];
BN_ULONG Z1sqr[P256_LIMBS];
BN_ULONG Z2sqr[P256_LIMBS];
BN_ULONG H[P256_LIMBS], R[P256_LIMBS];
BN_ULONG Hsqr[P256_LIMBS];
BN_ULONG Rsqr[P256_LIMBS];
BN_ULONG Hcub[P256_LIMBS];
BN_ULONG res_x[P256_LIMBS];
BN_ULONG res_y[P256_LIMBS];
BN_ULONG res_z[P256_LIMBS];
BN_ULONG in1infty, in2infty;
const BN_ULONG *in1_x = a->X;
const BN_ULONG *in1_y = a->Y;
const BN_ULONG *in1_z = a->Z;
const BN_ULONG *in2_x = b->X;
const BN_ULONG *in2_y = b->Y;
const BN_ULONG *in2_z = b->Z;
in1infty = (in1_z[0] | in1_z[1] | in1_z[2] | in1_z[3]);
if (P256_LIMBS == 8)
in1infty |= (in1_z[4] | in1_z[5] | in1_z[6] | in1_z[7]);
in2infty = (in2_z[0] | in2_z[1] | in2_z[2] | in2_z[3]);
if (P256_LIMBS == 8)
in2infty |= (in2_z[4] | in2_z[5] | in2_z[6] | in2_z[7]);
in1infty = is_zero(in1infty);
in2infty = is_zero(in2infty);
ecp_nistz256_sqr_mont(Z2sqr, in2_z);
ecp_nistz256_sqr_mont(Z1sqr, in1_z);
ecp_nistz256_mul_mont(S1, Z2sqr, in2_z);
ecp_nistz256_mul_mont(S2, Z1sqr, in1_z);
ecp_nistz256_mul_mont(S1, S1, in1_y);
ecp_nistz256_mul_mont(S2, S2, in2_y);
ecp_nistz256_sub(R, S2, S1);
ecp_nistz256_mul_mont(U1, in1_x, Z2sqr);
ecp_nistz256_mul_mont(U2, in2_x, Z1sqr);
ecp_nistz256_sub(H, U2, U1);
if (is_equal(U1, U2) && !in1infty && !in2infty) {
if (is_equal(S1, S2)) {
ecp_nistz256_point_double(r, a);
return;
} else {
memset(r, 0, sizeof(*r));
return;
}
}
ecp_nistz256_sqr_mont(Rsqr, R);
ecp_nistz256_mul_mont(res_z, H, in1_z);
ecp_nistz256_sqr_mont(Hsqr, H);
ecp_nistz256_mul_mont(res_z, res_z, in2_z);
ecp_nistz256_mul_mont(Hcub, Hsqr, H);
ecp_nistz256_mul_mont(U2, U1, Hsqr);
ecp_nistz256_mul_by_2(Hsqr, U2);
ecp_nistz256_sub(res_x, Rsqr, Hsqr);
ecp_nistz256_sub(res_x, res_x, Hcub);
ecp_nistz256_sub(res_y, U2, res_x);
ecp_nistz256_mul_mont(S2, S1, Hcub);
ecp_nistz256_mul_mont(res_y, R, res_y);
ecp_nistz256_sub(res_y, res_y, S2);
copy_conditional(res_x, in2_x, in1infty);
copy_conditional(res_y, in2_y, in1infty);
copy_conditional(res_z, in2_z, in1infty);
copy_conditional(res_x, in1_x, in2infty);
copy_conditional(res_y, in1_y, in2infty);
copy_conditional(res_z, in1_z, in2infty);
memcpy(r->X, res_x, sizeof(res_x));
memcpy(r->Y, res_y, sizeof(res_y));
memcpy(r->Z, res_z, sizeof(res_z));
}
static void ecp_nistz256_point_add_affine(P256_POINT *r,
const P256_POINT *a,
const P256_POINT_AFFINE *b)
{
BN_ULONG U2[P256_LIMBS], S2[P256_LIMBS];
BN_ULONG Z1sqr[P256_LIMBS];
BN_ULONG H[P256_LIMBS], R[P256_LIMBS];
BN_ULONG Hsqr[P256_LIMBS];
BN_ULONG Rsqr[P256_LIMBS];
BN_ULONG Hcub[P256_LIMBS];
BN_ULONG res_x[P256_LIMBS];
BN_ULONG res_y[P256_LIMBS];
BN_ULONG res_z[P256_LIMBS];
BN_ULONG in1infty, in2infty;
const BN_ULONG *in1_x = a->X;
const BN_ULONG *in1_y = a->Y;
const BN_ULONG *in1_z = a->Z;
const BN_ULONG *in2_x = b->X;
const BN_ULONG *in2_y = b->Y;
in1infty = (in1_z[0] | in1_z[1] | in1_z[2] | in1_z[3]);
if (P256_LIMBS == 8)
in1infty |= (in1_z[4] | in1_z[5] | in1_z[6] | in1_z[7]);
in2infty = (in2_x[0] | in2_x[1] | in2_x[2] | in2_x[3] |
in2_y[0] | in2_y[1] | in2_y[2] | in2_y[3]);
if (P256_LIMBS == 8)
in2infty |= (in2_x[4] | in2_x[5] | in2_x[6] | in2_x[7] |
in2_y[4] | in2_y[5] | in2_y[6] | in2_y[7]);
in1infty = is_zero(in1infty);
in2infty = is_zero(in2infty);
ecp_nistz256_sqr_mont(Z1sqr, in1_z);
ecp_nistz256_mul_mont(U2, in2_x, Z1sqr);
ecp_nistz256_sub(H, U2, in1_x);
ecp_nistz256_mul_mont(S2, Z1sqr, in1_z);
ecp_nistz256_mul_mont(res_z, H, in1_z);
ecp_nistz256_mul_mont(S2, S2, in2_y);
ecp_nistz256_sub(R, S2, in1_y);
ecp_nistz256_sqr_mont(Hsqr, H);
ecp_nistz256_sqr_mont(Rsqr, R);
ecp_nistz256_mul_mont(Hcub, Hsqr, H);
ecp_nistz256_mul_mont(U2, in1_x, Hsqr);
ecp_nistz256_mul_by_2(Hsqr, U2);
ecp_nistz256_sub(res_x, Rsqr, Hsqr);
ecp_nistz256_sub(res_x, res_x, Hcub);
ecp_nistz256_sub(H, U2, res_x);
ecp_nistz256_mul_mont(S2, in1_y, Hcub);
ecp_nistz256_mul_mont(H, H, R);
ecp_nistz256_sub(res_y, H, S2);
copy_conditional(res_x, in2_x, in1infty);
copy_conditional(res_x, in1_x, in2infty);
copy_conditional(res_y, in2_y, in1infty);
copy_conditional(res_y, in1_y, in2infty);
copy_conditional(res_z, ONE, in1infty);
copy_conditional(res_z, in1_z, in2infty);
memcpy(r->X, res_x, sizeof(res_x));
memcpy(r->Y, res_y, sizeof(res_y));
memcpy(r->Z, res_z, sizeof(res_z));
}
static void ecp_nistz256_mod_inverse(BN_ULONG r[P256_LIMBS],
const BN_ULONG in[P256_LIMBS])
{
BN_ULONG p2[P256_LIMBS];
BN_ULONG p4[P256_LIMBS];
BN_ULONG p8[P256_LIMBS];
BN_ULONG p16[P256_LIMBS];
BN_ULONG p32[P256_LIMBS];
BN_ULONG res[P256_LIMBS];
int i;
ecp_nistz256_sqr_mont(res, in);
ecp_nistz256_mul_mont(p2, res, in);
ecp_nistz256_sqr_mont(res, p2);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(p4, res, p2);
ecp_nistz256_sqr_mont(res, p4);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(p8, res, p4);
ecp_nistz256_sqr_mont(res, p8);
for (i = 0; i < 7; i++)
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(p16, res, p8);
ecp_nistz256_sqr_mont(res, p16);
for (i = 0; i < 15; i++)
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(p32, res, p16);
ecp_nistz256_sqr_mont(res, p32);
for (i = 0; i < 31; i++)
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(res, res, in);
for (i = 0; i < 32 * 4; i++)
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(res, res, p32);
for (i = 0; i < 32; i++)
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(res, res, p32);
for (i = 0; i < 16; i++)
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(res, res, p16);
for (i = 0; i < 8; i++)
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(res, res, p8);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(res, res, p4);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(res, res, p2);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_sqr_mont(res, res);
ecp_nistz256_mul_mont(res, res, in);
memcpy(r, res, sizeof(res));
}
__owur static int ecp_nistz256_bignum_to_field_elem(BN_ULONG out[P256_LIMBS],
const BIGNUM *in)
{
return bn_copy_words(out, in, P256_LIMBS);
}
__owur static int ecp_nistz256_windowed_mul(const EC_GROUP *group,
P256_POINT *r,
const BIGNUM **scalar,
const EC_POINT **point,
size_t num, BN_CTX *ctx)
{
size_t i;
int j, ret = 0;
unsigned int idx;
unsigned char (*p_str)[33] = NULL;
const unsigned int window_size = 5;
const unsigned int mask = (1 << (window_size + 1)) - 1;
unsigned int wvalue;
P256_POINT *temp;
const BIGNUM **scalars = NULL;
P256_POINT (*table)[16] = NULL;
void *table_storage = NULL;
if ((num * 16 + 6) > OPENSSL_MALLOC_MAX_NELEMS(P256_POINT)
|| (table_storage =
OPENSSL_malloc((num * 16 + 5) * sizeof(P256_POINT) + 64)) == NULL
|| (p_str =
OPENSSL_malloc(num * 33 * sizeof(unsigned char))) == NULL
|| (scalars = OPENSSL_malloc(num * sizeof(BIGNUM *))) == NULL) {
ECerr(EC_F_ECP_NISTZ256_WINDOWED_MUL, ERR_R_MALLOC_FAILURE);
goto err;
}
table = (void *)ALIGNPTR(table_storage, 64);
temp = (P256_POINT *)(table + num);
for (i = 0; i < num; i++) {
P256_POINT *row = table[i];
if ((BN_num_bits(scalar[i]) > 256) || BN_is_negative(scalar[i])) {
BIGNUM *mod;
if ((mod = BN_CTX_get(ctx)) == NULL)
goto err;
if (!BN_nnmod(mod, scalar[i], group->order, ctx)) {
ECerr(EC_F_ECP_NISTZ256_WINDOWED_MUL, ERR_R_BN_LIB);
goto err;
}
scalars[i] = mod;
} else
scalars[i] = scalar[i];
for (j = 0; j < bn_get_top(scalars[i]) * BN_BYTES; j += BN_BYTES) {
BN_ULONG d = bn_get_words(scalars[i])[j / BN_BYTES];
p_str[i][j + 0] = (unsigned char)d;
p_str[i][j + 1] = (unsigned char)(d >> 8);
p_str[i][j + 2] = (unsigned char)(d >> 16);
p_str[i][j + 3] = (unsigned char)(d >>= 24);
if (BN_BYTES == 8) {
d >>= 8;
p_str[i][j + 4] = (unsigned char)d;
p_str[i][j + 5] = (unsigned char)(d >> 8);
p_str[i][j + 6] = (unsigned char)(d >> 16);
p_str[i][j + 7] = (unsigned char)(d >> 24);
}
}
for (; j < 33; j++)
p_str[i][j] = 0;
if (!ecp_nistz256_bignum_to_field_elem(temp[0].X, point[i]->X)
|| !ecp_nistz256_bignum_to_field_elem(temp[0].Y, point[i]->Y)
|| !ecp_nistz256_bignum_to_field_elem(temp[0].Z, point[i]->Z)) {
ECerr(EC_F_ECP_NISTZ256_WINDOWED_MUL,
EC_R_COORDINATES_OUT_OF_RANGE);
goto err;
}
ecp_nistz256_scatter_w5 (row, &temp[0], 1);
ecp_nistz256_point_double(&temp[1], &temp[0]);
ecp_nistz256_scatter_w5 (row, &temp[1], 2);
ecp_nistz256_point_add (&temp[2], &temp[1], &temp[0]);
ecp_nistz256_scatter_w5 (row, &temp[2], 3);
ecp_nistz256_point_double(&temp[1], &temp[1]);
ecp_nistz256_scatter_w5 (row, &temp[1], 4);
ecp_nistz256_point_double(&temp[2], &temp[2]);
ecp_nistz256_scatter_w5 (row, &temp[2], 6);
ecp_nistz256_point_add (&temp[3], &temp[1], &temp[0]);
ecp_nistz256_scatter_w5 (row, &temp[3], 5);
ecp_nistz256_point_add (&temp[4], &temp[2], &temp[0]);
ecp_nistz256_scatter_w5 (row, &temp[4], 7);
ecp_nistz256_point_double(&temp[1], &temp[1]);
ecp_nistz256_scatter_w5 (row, &temp[1], 8);
ecp_nistz256_point_double(&temp[2], &temp[2]);
ecp_nistz256_scatter_w5 (row, &temp[2], 12);
ecp_nistz256_point_double(&temp[3], &temp[3]);
ecp_nistz256_scatter_w5 (row, &temp[3], 10);
ecp_nistz256_point_double(&temp[4], &temp[4]);
ecp_nistz256_scatter_w5 (row, &temp[4], 14);
ecp_nistz256_point_add (&temp[2], &temp[2], &temp[0]);
ecp_nistz256_scatter_w5 (row, &temp[2], 13);
ecp_nistz256_point_add (&temp[3], &temp[3], &temp[0]);
ecp_nistz256_scatter_w5 (row, &temp[3], 11);
ecp_nistz256_point_add (&temp[4], &temp[4], &temp[0]);
ecp_nistz256_scatter_w5 (row, &temp[4], 15);
ecp_nistz256_point_add (&temp[2], &temp[1], &temp[0]);
ecp_nistz256_scatter_w5 (row, &temp[2], 9);
ecp_nistz256_point_double(&temp[1], &temp[1]);
ecp_nistz256_scatter_w5 (row, &temp[1], 16);
}
idx = 255;
wvalue = p_str[0][(idx - 1) / 8];
wvalue = (wvalue >> ((idx - 1) % 8)) & mask;
ecp_nistz256_gather_w5(&temp[0], table[0], _booth_recode_w5(wvalue) >> 1);
memcpy(r, &temp[0], sizeof(temp[0]));
while (idx >= 5) {
for (i = (idx == 255 ? 1 : 0); i < num; i++) {
unsigned int off = (idx - 1) / 8;
wvalue = p_str[i][off] | p_str[i][off + 1] << 8;
wvalue = (wvalue >> ((idx - 1) % 8)) & mask;
wvalue = _booth_recode_w5(wvalue);
ecp_nistz256_gather_w5(&temp[0], table[i], wvalue >> 1);
ecp_nistz256_neg(temp[1].Y, temp[0].Y);
copy_conditional(temp[0].Y, temp[1].Y, (wvalue & 1));
ecp_nistz256_point_add(r, r, &temp[0]);
}
idx -= window_size;
ecp_nistz256_point_double(r, r);
ecp_nistz256_point_double(r, r);
ecp_nistz256_point_double(r, r);
ecp_nistz256_point_double(r, r);
ecp_nistz256_point_double(r, r);
}
for (i = 0; i < num; i++) {
wvalue = p_str[i][0];
wvalue = (wvalue << 1) & mask;
wvalue = _booth_recode_w5(wvalue);
ecp_nistz256_gather_w5(&temp[0], table[i], wvalue >> 1);
ecp_nistz256_neg(temp[1].Y, temp[0].Y);
copy_conditional(temp[0].Y, temp[1].Y, wvalue & 1);
ecp_nistz256_point_add(r, r, &temp[0]);
}
ret = 1;
err:
OPENSSL_free(table_storage);
OPENSSL_free(p_str);
OPENSSL_free(scalars);
return ret;
}
static int ecp_nistz256_is_affine_G(const EC_POINT *generator)
{
return (bn_get_top(generator->X) == P256_LIMBS) &&
(bn_get_top(generator->Y) == P256_LIMBS) &&
is_equal(bn_get_words(generator->X), def_xG) &&
is_equal(bn_get_words(generator->Y), def_yG) &&
is_one(generator->Z);
}
__owur static int ecp_nistz256_mult_precompute(EC_GROUP *group, BN_CTX *ctx)
{
const BIGNUM *order;
EC_POINT *P = NULL, *T = NULL;
const EC_POINT *generator;
NISTZ256_PRE_COMP *pre_comp;
BN_CTX *new_ctx = NULL;
int i, j, k, ret = 0;
size_t w;
PRECOMP256_ROW *preComputedTable = NULL;
unsigned char *precomp_storage = NULL;
EC_pre_comp_free(group);
generator = EC_GROUP_get0_generator(group);
if (generator == NULL) {
ECerr(EC_F_ECP_NISTZ256_MULT_PRECOMPUTE, EC_R_UNDEFINED_GENERATOR);
return 0;
}
if (ecp_nistz256_is_affine_G(generator)) {
return 1;
}
if ((pre_comp = ecp_nistz256_pre_comp_new(group)) == NULL)
return 0;
if (ctx == NULL) {
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
}
BN_CTX_start(ctx);
order = EC_GROUP_get0_order(group);
if (order == NULL)
goto err;
if (BN_is_zero(order)) {
ECerr(EC_F_ECP_NISTZ256_MULT_PRECOMPUTE, EC_R_UNKNOWN_ORDER);
goto err;
}
w = 7;
if ((precomp_storage =
OPENSSL_malloc(37 * 64 * sizeof(P256_POINT_AFFINE) + 64)) == NULL) {
ECerr(EC_F_ECP_NISTZ256_MULT_PRECOMPUTE, ERR_R_MALLOC_FAILURE);
goto err;
}
preComputedTable = (void *)ALIGNPTR(precomp_storage, 64);
P = EC_POINT_new(group);
T = EC_POINT_new(group);
if (P == NULL || T == NULL)
goto err;
if (!EC_POINT_copy(T, generator))
goto err;
for (k = 0; k < 64; k++) {
if (!EC_POINT_copy(P, T))
goto err;
for (j = 0; j < 37; j++) {
P256_POINT_AFFINE temp;
if (!EC_POINT_make_affine(group, P, ctx))
goto err;
if (!ecp_nistz256_bignum_to_field_elem(temp.X, P->X) ||
!ecp_nistz256_bignum_to_field_elem(temp.Y, P->Y)) {
ECerr(EC_F_ECP_NISTZ256_MULT_PRECOMPUTE,
EC_R_COORDINATES_OUT_OF_RANGE);
goto err;
}
ecp_nistz256_scatter_w7(preComputedTable[j], &temp, k);
for (i = 0; i < 7; i++) {
if (!EC_POINT_dbl(group, P, P, ctx))
goto err;
}
}
if (!EC_POINT_add(group, T, T, generator, ctx))
goto err;
}
pre_comp->group = group;
pre_comp->w = w;
pre_comp->precomp = preComputedTable;
pre_comp->precomp_storage = precomp_storage;
precomp_storage = NULL;
SETPRECOMP(group, nistz256, pre_comp);
pre_comp = NULL;
ret = 1;
err:
if (ctx != NULL)
BN_CTX_end(ctx);
BN_CTX_free(new_ctx);
EC_nistz256_pre_comp_free(pre_comp);
OPENSSL_free(precomp_storage);
EC_POINT_free(P);
EC_POINT_free(T);
return ret;
}
static void booth_recode_w7(unsigned char *sign,
unsigned char *digit, unsigned char in)
{
unsigned char s, d;
s = ~((in >> 7) - 1);
d = (1 << 8) - in - 1;
d = (d & s) | (in & ~s);
d = (d >> 1) + (d & 1);
*sign = s & 1;
*digit = d;
}
__owur static int ecp_nistz256_set_from_affine(EC_POINT *out, const EC_GROUP *group,
const P256_POINT_AFFINE *in,
BN_CTX *ctx)
{
BIGNUM *x, *y;
BN_ULONG d_x[P256_LIMBS], d_y[P256_LIMBS];
int ret = 0;
x = BN_new();
if (x == NULL)
return 0;
y = BN_new();
if (y == NULL) {
BN_free(x);
return 0;
}
memcpy(d_x, in->X, sizeof(d_x));
bn_set_static_words(x, d_x, P256_LIMBS);
memcpy(d_y, in->Y, sizeof(d_y));
bn_set_static_words(y, d_y, P256_LIMBS);
ret = EC_POINT_set_affine_coordinates_GFp(group, out, x, y, ctx);
BN_free(x);
BN_free(y);
return ret;
}
__owur static int ecp_nistz256_points_mul(const EC_GROUP *group,
EC_POINT *r,
const BIGNUM *scalar,
size_t num,
const EC_POINT *points[],
const BIGNUM *scalars[], BN_CTX *ctx)
{
int i = 0, ret = 0, no_precomp_for_generator = 0, p_is_infinity = 0;
size_t j;
unsigned char p_str[33] = { 0 };
const PRECOMP256_ROW *preComputedTable = NULL;
const NISTZ256_PRE_COMP *pre_comp = NULL;
const EC_POINT *generator = NULL;
BN_CTX *new_ctx = NULL;
const BIGNUM **new_scalars = NULL;
const EC_POINT **new_points = NULL;
unsigned int idx = 0;
const unsigned int window_size = 7;
const unsigned int mask = (1 << (window_size + 1)) - 1;
unsigned int wvalue;
ALIGN32 union {
P256_POINT p;
P256_POINT_AFFINE a;
} t, p;
BIGNUM *tmp_scalar;
if ((num + 1) == 0 || (num + 1) > OPENSSL_MALLOC_MAX_NELEMS(void *)) {
ECerr(EC_F_ECP_NISTZ256_POINTS_MUL, ERR_R_MALLOC_FAILURE);
return 0;
}
if (group->meth != r->meth) {
ECerr(EC_F_ECP_NISTZ256_POINTS_MUL, EC_R_INCOMPATIBLE_OBJECTS);
return 0;
}
if ((scalar == NULL) && (num == 0))
return EC_POINT_set_to_infinity(group, r);
for (j = 0; j < num; j++) {
if (group->meth != points[j]->meth) {
ECerr(EC_F_ECP_NISTZ256_POINTS_MUL, EC_R_INCOMPATIBLE_OBJECTS);
return 0;
}
}
if (ctx == NULL) {
ctx = new_ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
}
BN_CTX_start(ctx);
if (scalar) {
generator = EC_GROUP_get0_generator(group);
if (generator == NULL) {
ECerr(EC_F_ECP_NISTZ256_POINTS_MUL, EC_R_UNDEFINED_GENERATOR);
goto err;
}
pre_comp = group->pre_comp.nistz256;
if (pre_comp) {
EC_POINT *pre_comp_generator = EC_POINT_new(group);
if (pre_comp_generator == NULL)
goto err;
if (!ecp_nistz256_set_from_affine(pre_comp_generator,
group, pre_comp->precomp[0],
ctx)) {
EC_POINT_free(pre_comp_generator);
goto err;
}
if (0 == EC_POINT_cmp(group, generator, pre_comp_generator, ctx))
preComputedTable = (const PRECOMP256_ROW *)pre_comp->precomp;
EC_POINT_free(pre_comp_generator);
}
if (preComputedTable == NULL && ecp_nistz256_is_affine_G(generator)) {
preComputedTable = ecp_nistz256_precomputed;
}
if (preComputedTable) {
if ((BN_num_bits(scalar) > 256)
|| BN_is_negative(scalar)) {
if ((tmp_scalar = BN_CTX_get(ctx)) == NULL)
goto err;
if (!BN_nnmod(tmp_scalar, scalar, group->order, ctx)) {
ECerr(EC_F_ECP_NISTZ256_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
scalar = tmp_scalar;
}
for (i = 0; i < bn_get_top(scalar) * BN_BYTES; i += BN_BYTES) {
BN_ULONG d = bn_get_words(scalar)[i / BN_BYTES];
p_str[i + 0] = (unsigned char)d;
p_str[i + 1] = (unsigned char)(d >> 8);
p_str[i + 2] = (unsigned char)(d >> 16);
p_str[i + 3] = (unsigned char)(d >>= 24);
if (BN_BYTES == 8) {
d >>= 8;
p_str[i + 4] = (unsigned char)d;
p_str[i + 5] = (unsigned char)(d >> 8);
p_str[i + 6] = (unsigned char)(d >> 16);
p_str[i + 7] = (unsigned char)(d >> 24);
}
}
for (; i < 33; i++)
p_str[i] = 0;
#if defined(ECP_NISTZ256_AVX2)
if (ecp_nistz_avx2_eligible()) {
ecp_nistz256_avx2_mul_g(&p.p, p_str, preComputedTable);
} else
#endif
{
BN_ULONG infty;
wvalue = (p_str[0] << 1) & mask;
idx += window_size;
wvalue = _booth_recode_w7(wvalue);
ecp_nistz256_gather_w7(&p.a, preComputedTable[0],
wvalue >> 1);
ecp_nistz256_neg(p.p.Z, p.p.Y);
copy_conditional(p.p.Y, p.p.Z, wvalue & 1);
infty = (p.p.X[0] | p.p.X[1] | p.p.X[2] | p.p.X[3] |
p.p.Y[0] | p.p.Y[1] | p.p.Y[2] | p.p.Y[3]);
if (P256_LIMBS == 8)
infty |= (p.p.X[4] | p.p.X[5] | p.p.X[6] | p.p.X[7] |
p.p.Y[4] | p.p.Y[5] | p.p.Y[6] | p.p.Y[7]);
infty = 0 - is_zero(infty);
infty = ~infty;
p.p.Z[0] = ONE[0] & infty;
p.p.Z[1] = ONE[1] & infty;
p.p.Z[2] = ONE[2] & infty;
p.p.Z[3] = ONE[3] & infty;
if (P256_LIMBS == 8) {
p.p.Z[4] = ONE[4] & infty;
p.p.Z[5] = ONE[5] & infty;
p.p.Z[6] = ONE[6] & infty;
p.p.Z[7] = ONE[7] & infty;
}
for (i = 1; i < 37; i++) {
unsigned int off = (idx - 1) / 8;
wvalue = p_str[off] | p_str[off + 1] << 8;
wvalue = (wvalue >> ((idx - 1) % 8)) & mask;
idx += window_size;
wvalue = _booth_recode_w7(wvalue);
ecp_nistz256_gather_w7(&t.a,
preComputedTable[i], wvalue >> 1);
ecp_nistz256_neg(t.p.Z, t.a.Y);
copy_conditional(t.a.Y, t.p.Z, wvalue & 1);
ecp_nistz256_point_add_affine(&p.p, &p.p, &t.a);
}
}
} else {
p_is_infinity = 1;
no_precomp_for_generator = 1;
}
} else
p_is_infinity = 1;
if (no_precomp_for_generator) {
new_scalars = OPENSSL_malloc((num + 1) * sizeof(BIGNUM *));
if (new_scalars == NULL) {
ECerr(EC_F_ECP_NISTZ256_POINTS_MUL, ERR_R_MALLOC_FAILURE);
goto err;
}
new_points = OPENSSL_malloc((num + 1) * sizeof(EC_POINT *));
if (new_points == NULL) {
ECerr(EC_F_ECP_NISTZ256_POINTS_MUL, ERR_R_MALLOC_FAILURE);
goto err;
}
memcpy(new_scalars, scalars, num * sizeof(BIGNUM *));
new_scalars[num] = scalar;
memcpy(new_points, points, num * sizeof(EC_POINT *));
new_points[num] = generator;
scalars = new_scalars;
points = new_points;
num++;
}
if (num) {
P256_POINT *out = &t.p;
if (p_is_infinity)
out = &p.p;
if (!ecp_nistz256_windowed_mul(group, out, scalars, points, num, ctx))
goto err;
if (!p_is_infinity)
ecp_nistz256_point_add(&p.p, &p.p, out);
}
if (!bn_set_words(r->X, p.p.X, P256_LIMBS) ||
!bn_set_words(r->Y, p.p.Y, P256_LIMBS) ||
!bn_set_words(r->Z, p.p.Z, P256_LIMBS)) {
goto err;
}
r->Z_is_one = is_one(r->Z) & 1;
ret = 1;
err:
if (ctx)
BN_CTX_end(ctx);
BN_CTX_free(new_ctx);
OPENSSL_free(new_points);
OPENSSL_free(new_scalars);
return ret;
}
__owur static int ecp_nistz256_get_affine(const EC_GROUP *group,
const EC_POINT *point,
BIGNUM *x, BIGNUM *y, BN_CTX *ctx)
{
BN_ULONG z_inv2[P256_LIMBS];
BN_ULONG z_inv3[P256_LIMBS];
BN_ULONG x_aff[P256_LIMBS];
BN_ULONG y_aff[P256_LIMBS];
BN_ULONG point_x[P256_LIMBS], point_y[P256_LIMBS], point_z[P256_LIMBS];
BN_ULONG x_ret[P256_LIMBS], y_ret[P256_LIMBS];
if (EC_POINT_is_at_infinity(group, point)) {
ECerr(EC_F_ECP_NISTZ256_GET_AFFINE, EC_R_POINT_AT_INFINITY);
return 0;
}
if (!ecp_nistz256_bignum_to_field_elem(point_x, point->X) ||
!ecp_nistz256_bignum_to_field_elem(point_y, point->Y) ||
!ecp_nistz256_bignum_to_field_elem(point_z, point->Z)) {
ECerr(EC_F_ECP_NISTZ256_GET_AFFINE, EC_R_COORDINATES_OUT_OF_RANGE);
return 0;
}
ecp_nistz256_mod_inverse(z_inv3, point_z);
ecp_nistz256_sqr_mont(z_inv2, z_inv3);
ecp_nistz256_mul_mont(x_aff, z_inv2, point_x);
if (x != NULL) {
ecp_nistz256_from_mont(x_ret, x_aff);
if (!bn_set_words(x, x_ret, P256_LIMBS))
return 0;
}
if (y != NULL) {
ecp_nistz256_mul_mont(z_inv3, z_inv3, z_inv2);
ecp_nistz256_mul_mont(y_aff, z_inv3, point_y);
ecp_nistz256_from_mont(y_ret, y_aff);
if (!bn_set_words(y, y_ret, P256_LIMBS))
return 0;
}
return 1;
}
static NISTZ256_PRE_COMP *ecp_nistz256_pre_comp_new(const EC_GROUP *group)
{
NISTZ256_PRE_COMP *ret = NULL;
if (!group)
return NULL;
ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL) {
ECerr(EC_F_ECP_NISTZ256_PRE_COMP_NEW, ERR_R_MALLOC_FAILURE);
return ret;
}
ret->group = group;
ret->w = 6;
ret->references = 1;
ret->lock = CRYPTO_THREAD_lock_new();
if (ret->lock == NULL) {
ECerr(EC_F_ECP_NISTZ256_PRE_COMP_NEW, ERR_R_MALLOC_FAILURE);
OPENSSL_free(ret);
return NULL;
}
return ret;
}
NISTZ256_PRE_COMP *EC_nistz256_pre_comp_dup(NISTZ256_PRE_COMP *p)
{
int i;
if (p != NULL)
CRYPTO_atomic_add(&p->references, 1, &i, p->lock);
return p;
}
void EC_nistz256_pre_comp_free(NISTZ256_PRE_COMP *pre)
{
int i;
if (pre == NULL)
return;
CRYPTO_atomic_add(&pre->references, -1, &i, pre->lock);
REF_PRINT_COUNT("EC_nistz256", x);
if (i > 0)
return;
REF_ASSERT_ISNT(i < 0);
OPENSSL_free(pre->precomp_storage);
CRYPTO_THREAD_lock_free(pre->lock);
OPENSSL_free(pre);
}
static int ecp_nistz256_window_have_precompute_mult(const EC_GROUP *group)
{
const EC_POINT *generator = EC_GROUP_get0_generator(group);
if (generator != NULL && ecp_nistz256_is_affine_G(generator)) {
return 1;
}
return HAVEPRECOMP(group, nistz256);
}
const EC_METHOD *EC_GFp_nistz256_method(void)
{
static const EC_METHOD ret = {
EC_FLAGS_DEFAULT_OCT,
NID_X9_62_prime_field,
ec_GFp_mont_group_init,
ec_GFp_mont_group_finish,
ec_GFp_mont_group_clear_finish,
ec_GFp_mont_group_copy,
ec_GFp_mont_group_set_curve,
ec_GFp_simple_group_get_curve,
ec_GFp_simple_group_get_degree,
ec_group_simple_order_bits,
ec_GFp_simple_group_check_discriminant,
ec_GFp_simple_point_init,
ec_GFp_simple_point_finish,
ec_GFp_simple_point_clear_finish,
ec_GFp_simple_point_copy,
ec_GFp_simple_point_set_to_infinity,
ec_GFp_simple_set_Jprojective_coordinates_GFp,
ec_GFp_simple_get_Jprojective_coordinates_GFp,
ec_GFp_simple_point_set_affine_coordinates,
ecp_nistz256_get_affine,
0, 0, 0,
ec_GFp_simple_add,
ec_GFp_simple_dbl,
ec_GFp_simple_invert,
ec_GFp_simple_is_at_infinity,
ec_GFp_simple_is_on_curve,
ec_GFp_simple_cmp,
ec_GFp_simple_make_affine,
ec_GFp_simple_points_make_affine,
ecp_nistz256_points_mul,
ecp_nistz256_mult_precompute,
ecp_nistz256_window_have_precompute_mult,
ec_GFp_mont_field_mul,
ec_GFp_mont_field_sqr,
0,
ec_GFp_mont_field_encode,
ec_GFp_mont_field_decode,
ec_GFp_mont_field_set_to_one,
ec_key_simple_priv2oct,
ec_key_simple_oct2priv,
0,
ec_key_simple_generate_key,
ec_key_simple_check_key,
ec_key_simple_generate_public_key,
0,
0,
ecdh_simple_compute_key
};
return &ret;
}
