const EC_METHOD *EC_GFp_nistp224_method(void)
{
static const EC_METHOD ret = {
EC_FLAGS_DEFAULT_OCT,
NID_X9_62_prime_field,
ec_GFp_nistp224_group_init,
ec_GFp_simple_group_finish,
ec_GFp_simple_group_clear_finish,
ec_GFp_nist_group_copy,
ec_GFp_nistp224_group_set_curve,
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
ec_GFp_nistp224_point_get_affine_coordinates,
0 ,
0 ,
0 ,
ec_GFp_simple_add,
ec_GFp_simple_dbl,
ec_GFp_simple_invert,
ec_GFp_simple_is_at_infinity,
ec_GFp_simple_is_on_curve,
ec_GFp_simple_cmp,
ec_GFp_simple_make_affine,
ec_GFp_simple_points_make_affine,
ec_GFp_nistp224_points_mul,
ec_GFp_nistp224_precompute_mult,
ec_GFp_nistp224_have_precompute_mult,
ec_GFp_nist_field_mul,
ec_GFp_nist_field_sqr,
0 ,
0 ,
0 ,
0
};
return &ret;
}
static void bin28_to_felem(felem out, const u8 in[28])
{
out[0] = *((const uint64_t *)(in)) & 0x00ffffffffffffff;
out[1] = (*((const uint64_t *)(in + 7))) & 0x00ffffffffffffff;
out[2] = (*((const uint64_t *)(in + 14))) & 0x00ffffffffffffff;
out[3] = (*((const uint64_t *)(in + 21))) & 0x00ffffffffffffff;
}
static void felem_to_bin28(u8 out[28], const felem in)
{
unsigned i;
for (i = 0; i < 7; ++i) {
out[i] = in[0] >> (8 * i);
out[i + 7] = in[1] >> (8 * i);
out[i + 14] = in[2] >> (8 * i);
out[i + 21] = in[3] >> (8 * i);
}
}
static void flip_endian(u8 *out, const u8 *in, unsigned len)
{
unsigned i;
for (i = 0; i < len; ++i)
out[i] = in[len - 1 - i];
}
static int BN_to_felem(felem out, const BIGNUM *bn)
{
felem_bytearray b_in;
felem_bytearray b_out;
unsigned num_bytes;
memset(b_out, 0, sizeof b_out);
num_bytes = BN_num_bytes(bn);
if (num_bytes > sizeof b_out) {
ECerr(EC_F_BN_TO_FELEM, EC_R_BIGNUM_OUT_OF_RANGE);
return 0;
}
if (BN_is_negative(bn)) {
ECerr(EC_F_BN_TO_FELEM, EC_R_BIGNUM_OUT_OF_RANGE);
return 0;
}
num_bytes = BN_bn2bin(bn, b_in);
flip_endian(b_out, b_in, num_bytes);
bin28_to_felem(out, b_out);
return 1;
}
static BIGNUM *felem_to_BN(BIGNUM *out, const felem in)
{
felem_bytearray b_in, b_out;
felem_to_bin28(b_in, in);
flip_endian(b_out, b_in, sizeof b_out);
return BN_bin2bn(b_out, sizeof b_out, out);
}
static void felem_one(felem out)
{
out[0] = 1;
out[1] = 0;
out[2] = 0;
out[3] = 0;
}
static void felem_assign(felem out, const felem in)
{
out[0] = in[0];
out[1] = in[1];
out[2] = in[2];
out[3] = in[3];
}
static void felem_sum(felem out, const felem in)
{
out[0] += in[0];
out[1] += in[1];
out[2] += in[2];
out[3] += in[3];
}
static void felem_neg(felem out, const felem in)
{
static const limb two58p2 = (((limb) 1) << 58) + (((limb) 1) << 2);
static const limb two58m2 = (((limb) 1) << 58) - (((limb) 1) << 2);
static const limb two58m42m2 = (((limb) 1) << 58) -
(((limb) 1) << 42) - (((limb) 1) << 2);
out[0] = two58p2 - in[0];
out[1] = two58m42m2 - in[1];
out[2] = two58m2 - in[2];
out[3] = two58m2 - in[3];
}
static void felem_diff(felem out, const felem in)
{
static const limb two58p2 = (((limb) 1) << 58) + (((limb) 1) << 2);
static const limb two58m2 = (((limb) 1) << 58) - (((limb) 1) << 2);
static const limb two58m42m2 = (((limb) 1) << 58) -
(((limb) 1) << 42) - (((limb) 1) << 2);
out[0] += two58p2;
out[1] += two58m42m2;
out[2] += two58m2;
out[3] += two58m2;
out[0] -= in[0];
out[1] -= in[1];
out[2] -= in[2];
out[3] -= in[3];
}
static void widefelem_diff(widefelem out, const widefelem in)
{
static const widelimb two120 = ((widelimb) 1) << 120;
static const widelimb two120m64 = (((widelimb) 1) << 120) -
(((widelimb) 1) << 64);
static const widelimb two120m104m64 = (((widelimb) 1) << 120) -
(((widelimb) 1) << 104) - (((widelimb) 1) << 64);
out[0] += two120;
out[1] += two120m64;
out[2] += two120m64;
out[3] += two120;
out[4] += two120m104m64;
out[5] += two120m64;
out[6] += two120m64;
out[0] -= in[0];
out[1] -= in[1];
out[2] -= in[2];
out[3] -= in[3];
out[4] -= in[4];
out[5] -= in[5];
out[6] -= in[6];
}
static void felem_diff_128_64(widefelem out, const felem in)
{
static const widelimb two64p8 = (((widelimb) 1) << 64) +
(((widelimb) 1) << 8);
static const widelimb two64m8 = (((widelimb) 1) << 64) -
(((widelimb) 1) << 8);
static const widelimb two64m48m8 = (((widelimb) 1) << 64) -
(((widelimb) 1) << 48) - (((widelimb) 1) << 8);
out[0] += two64p8;
out[1] += two64m48m8;
out[2] += two64m8;
out[3] += two64m8;
out[0] -= in[0];
out[1] -= in[1];
out[2] -= in[2];
out[3] -= in[3];
}
static void felem_scalar(felem out, const limb scalar)
{
out[0] *= scalar;
out[1] *= scalar;
out[2] *= scalar;
out[3] *= scalar;
}
static void widefelem_scalar(widefelem out, const widelimb scalar)
{
out[0] *= scalar;
out[1] *= scalar;
out[2] *= scalar;
out[3] *= scalar;
out[4] *= scalar;
out[5] *= scalar;
out[6] *= scalar;
}
static void felem_square(widefelem out, const felem in)
{
limb tmp0, tmp1, tmp2;
tmp0 = 2 * in[0];
tmp1 = 2 * in[1];
tmp2 = 2 * in[2];
out[0] = ((widelimb) in[0]) * in[0];
out[1] = ((widelimb) in[0]) * tmp1;
out[2] = ((widelimb) in[0]) * tmp2 + ((widelimb) in[1]) * in[1];
out[3] = ((widelimb) in[3]) * tmp0 + ((widelimb) in[1]) * tmp2;
out[4] = ((widelimb) in[3]) * tmp1 + ((widelimb) in[2]) * in[2];
out[5] = ((widelimb) in[3]) * tmp2;
out[6] = ((widelimb) in[3]) * in[3];
}
static void felem_mul(widefelem out, const felem in1, const felem in2)
{
out[0] = ((widelimb) in1[0]) * in2[0];
out[1] = ((widelimb) in1[0]) * in2[1] + ((widelimb) in1[1]) * in2[0];
out[2] = ((widelimb) in1[0]) * in2[2] + ((widelimb) in1[1]) * in2[1] +
((widelimb) in1[2]) * in2[0];
out[3] = ((widelimb) in1[0]) * in2[3] + ((widelimb) in1[1]) * in2[2] +
((widelimb) in1[2]) * in2[1] + ((widelimb) in1[3]) * in2[0];
out[4] = ((widelimb) in1[1]) * in2[3] + ((widelimb) in1[2]) * in2[2] +
((widelimb) in1[3]) * in2[1];
out[5] = ((widelimb) in1[2]) * in2[3] + ((widelimb) in1[3]) * in2[2];
out[6] = ((widelimb) in1[3]) * in2[3];
}
static void felem_reduce(felem out, const widefelem in)
{
static const widelimb two127p15 = (((widelimb) 1) << 127) +
(((widelimb) 1) << 15);
static const widelimb two127m71 = (((widelimb) 1) << 127) -
(((widelimb) 1) << 71);
static const widelimb two127m71m55 = (((widelimb) 1) << 127) -
(((widelimb) 1) << 71) - (((widelimb) 1) << 55);
widelimb output[5];
output[0] = in[0] + two127p15;
output[1] = in[1] + two127m71m55;
output[2] = in[2] + two127m71;
output[3] = in[3];
output[4] = in[4];
output[4] += in[6] >> 16;
output[3] += (in[6] & 0xffff) << 40;
output[2] -= in[6];
output[3] += in[5] >> 16;
output[2] += (in[5] & 0xffff) << 40;
output[1] -= in[5];
output[2] += output[4] >> 16;
output[1] += (output[4] & 0xffff) << 40;
output[0] -= output[4];
output[3] += output[2] >> 56;
output[2] &= 0x00ffffffffffffff;
output[4] = output[3] >> 56;
output[3] &= 0x00ffffffffffffff;
output[2] += output[4] >> 16;
output[1] += (output[4] & 0xffff) << 40;
output[0] -= output[4];
output[1] += output[0] >> 56;
out[0] = output[0] & 0x00ffffffffffffff;
output[2] += output[1] >> 56;
out[1] = output[1] & 0x00ffffffffffffff;
output[3] += output[2] >> 56;
out[2] = output[2] & 0x00ffffffffffffff;
out[3] = output[3];
}
static void felem_square_reduce(felem out, const felem in)
{
widefelem tmp;
felem_square(tmp, in);
felem_reduce(out, tmp);
}
static void felem_mul_reduce(felem out, const felem in1, const felem in2)
{
widefelem tmp;
felem_mul(tmp, in1, in2);
felem_reduce(out, tmp);
}
static void felem_contract(felem out, const felem in)
{
static const int64_t two56 = ((limb) 1) << 56;
int64_t tmp[4], a;
tmp[0] = in[0];
tmp[1] = in[1];
tmp[2] = in[2];
tmp[3] = in[3];
a = (in[3] >> 56);
tmp[0] -= a;
tmp[1] += a << 40;
tmp[3] &= 0x00ffffffffffffff;
a = ((in[3] & in[2] & (in[1] | 0x000000ffffffffff)) + 1) |
(((int64_t) (in[0] + (in[1] & 0x000000ffffffffff)) - 1) >> 63);
a &= 0x00ffffffffffffff;
a = (a - 1) >> 63;
tmp[3] &= a ^ 0xffffffffffffffff;
tmp[2] &= a ^ 0xffffffffffffffff;
tmp[1] &= (a ^ 0xffffffffffffffff) | 0x000000ffffffffff;
tmp[0] -= 1 & a;
a = tmp[0] >> 63;
tmp[0] += two56 & a;
tmp[1] -= 1 & a;
tmp[2] += tmp[1] >> 56;
tmp[1] &= 0x00ffffffffffffff;
tmp[3] += tmp[2] >> 56;
tmp[2] &= 0x00ffffffffffffff;
out[0] = tmp[0];
out[1] = tmp[1];
out[2] = tmp[2];
out[3] = tmp[3];
}
static limb felem_is_zero(const felem in)
{
limb zero, two224m96p1, two225m97p2;
zero = in[0] | in[1] | in[2] | in[3];
zero = (((int64_t) (zero) - 1) >> 63) & 1;
two224m96p1 = (in[0] ^ 1) | (in[1] ^ 0x00ffff0000000000)
| (in[2] ^ 0x00ffffffffffffff) | (in[3] ^ 0x00ffffffffffffff);
two224m96p1 = (((int64_t) (two224m96p1) - 1) >> 63) & 1;
two225m97p2 = (in[0] ^ 2) | (in[1] ^ 0x00fffe0000000000)
| (in[2] ^ 0x00ffffffffffffff) | (in[3] ^ 0x01ffffffffffffff);
two225m97p2 = (((int64_t) (two225m97p2) - 1) >> 63) & 1;
return (zero | two224m96p1 | two225m97p2);
}
static limb felem_is_zero_int(const felem in)
{
return (int)(felem_is_zero(in) & ((limb) 1));
}
static void felem_inv(felem out, const felem in)
{
felem ftmp, ftmp2, ftmp3, ftmp4;
widefelem tmp;
unsigned i;
felem_square(tmp, in);
felem_reduce(ftmp, tmp);
felem_mul(tmp, in, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_mul(tmp, in, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp2, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, ftmp2, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp2, tmp);
for (i = 0; i < 5; ++i) {
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
}
felem_mul(tmp, ftmp2, ftmp);
felem_reduce(ftmp2, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp3, tmp);
for (i = 0; i < 11; ++i) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp2, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp3, tmp);
for (i = 0; i < 23; ++i) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
felem_square(tmp, ftmp3);
felem_reduce(ftmp4, tmp);
for (i = 0; i < 47; ++i) {
felem_square(tmp, ftmp4);
felem_reduce(ftmp4, tmp);
}
felem_mul(tmp, ftmp3, ftmp4);
felem_reduce(ftmp3, tmp);
felem_square(tmp, ftmp3);
felem_reduce(ftmp4, tmp);
for (i = 0; i < 23; ++i) {
felem_square(tmp, ftmp4);
felem_reduce(ftmp4, tmp);
}
felem_mul(tmp, ftmp2, ftmp4);
felem_reduce(ftmp2, tmp);
for (i = 0; i < 6; ++i) {
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
}
felem_mul(tmp, ftmp2, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_mul(tmp, ftmp, in);
felem_reduce(ftmp, tmp);
for (i = 0; i < 97; ++i) {
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
}
felem_mul(tmp, ftmp, ftmp3);
felem_reduce(out, tmp);
}
static void copy_conditional(felem out, const felem in, limb icopy)
{
unsigned i;
const limb copy = -icopy;
for (i = 0; i < 4; ++i) {
const limb tmp = copy & (in[i] ^ out[i]);
out[i] ^= tmp;
}
}
static void
point_double(felem x_out, felem y_out, felem z_out,
const felem x_in, const felem y_in, const felem z_in)
{
widefelem tmp, tmp2;
felem delta, gamma, beta, alpha, ftmp, ftmp2;
felem_assign(ftmp, x_in);
felem_assign(ftmp2, x_in);
felem_square(tmp, z_in);
felem_reduce(delta, tmp);
felem_square(tmp, y_in);
felem_reduce(gamma, tmp);
felem_mul(tmp, x_in, gamma);
felem_reduce(beta, tmp);
felem_diff(ftmp, delta);
felem_sum(ftmp2, delta);
felem_scalar(ftmp2, 3);
felem_mul(tmp, ftmp, ftmp2);
felem_reduce(alpha, tmp);
felem_square(tmp, alpha);
felem_assign(ftmp, beta);
felem_scalar(ftmp, 8);
felem_diff_128_64(tmp, ftmp);
felem_reduce(x_out, tmp);
felem_sum(delta, gamma);
felem_assign(ftmp, y_in);
felem_sum(ftmp, z_in);
felem_square(tmp, ftmp);
felem_diff_128_64(tmp, delta);
felem_reduce(z_out, tmp);
felem_scalar(beta, 4);
felem_diff(beta, x_out);
felem_mul(tmp, alpha, beta);
felem_square(tmp2, gamma);
widefelem_scalar(tmp2, 8);
widefelem_diff(tmp, tmp2);
felem_reduce(y_out, tmp);
}
static void point_add(felem x3, felem y3, felem z3,
const felem x1, const felem y1, const felem z1,
const int mixed, const felem x2, const felem y2,
const felem z2)
{
felem ftmp, ftmp2, ftmp3, ftmp4, ftmp5, x_out, y_out, z_out;
widefelem tmp, tmp2;
limb z1_is_zero, z2_is_zero, x_equal, y_equal;
if (!mixed) {
felem_square(tmp, z2);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, ftmp2, z2);
felem_reduce(ftmp4, tmp);
felem_mul(tmp2, ftmp4, y1);
felem_reduce(ftmp4, tmp2);
felem_mul(tmp2, ftmp2, x1);
felem_reduce(ftmp2, tmp2);
} else {
felem_assign(ftmp4, y1);
felem_assign(ftmp2, x1);
}
felem_square(tmp, z1);
felem_reduce(ftmp, tmp);
felem_mul(tmp, ftmp, z1);
felem_reduce(ftmp3, tmp);
felem_mul(tmp, ftmp3, y2);
felem_diff_128_64(tmp, ftmp4);
felem_reduce(ftmp3, tmp);
felem_mul(tmp, ftmp, x2);
felem_diff_128_64(tmp, ftmp2);
felem_reduce(ftmp, tmp);
x_equal = felem_is_zero(ftmp);
y_equal = felem_is_zero(ftmp3);
z1_is_zero = felem_is_zero(z1);
z2_is_zero = felem_is_zero(z2);
if (x_equal && y_equal && !z1_is_zero && !z2_is_zero) {
point_double(x3, y3, z3, x1, y1, z1);
return;
}
if (!mixed) {
felem_mul(tmp, z1, z2);
felem_reduce(ftmp5, tmp);
} else {
felem_assign(ftmp5, z1);
}
felem_mul(tmp, ftmp, ftmp5);
felem_reduce(z_out, tmp);
felem_assign(ftmp5, ftmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_mul(tmp, ftmp, ftmp5);
felem_reduce(ftmp5, tmp);
felem_mul(tmp, ftmp2, ftmp);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, ftmp4, ftmp5);
felem_square(tmp2, ftmp3);
felem_diff_128_64(tmp2, ftmp5);
felem_assign(ftmp5, ftmp2);
felem_scalar(ftmp5, 2);
felem_diff_128_64(tmp2, ftmp5);
felem_reduce(x_out, tmp2);
felem_diff(ftmp2, x_out);
felem_mul(tmp2, ftmp3, ftmp2);
widefelem_diff(tmp2, tmp);
felem_reduce(y_out, tmp2);
copy_conditional(x_out, x2, z1_is_zero);
copy_conditional(x_out, x1, z2_is_zero);
copy_conditional(y_out, y2, z1_is_zero);
copy_conditional(y_out, y1, z2_is_zero);
copy_conditional(z_out, z2, z1_is_zero);
copy_conditional(z_out, z1, z2_is_zero);
felem_assign(x3, x_out);
felem_assign(y3, y_out);
felem_assign(z3, z_out);
}
static void select_point(const u64 idx, unsigned int size,
const felem pre_comp[][3], felem out[3])
{
unsigned i, j;
limb *outlimbs = &out[0][0];
memset(outlimbs, 0, 3 * sizeof(felem));
for (i = 0; i < size; i++) {
const limb *inlimbs = &pre_comp[i][0][0];
u64 mask = i ^ idx;
mask |= mask >> 4;
mask |= mask >> 2;
mask |= mask >> 1;
mask &= 1;
mask--;
for (j = 0; j < 4 * 3; j++)
outlimbs[j] |= inlimbs[j] & mask;
}
}
static char get_bit(const felem_bytearray in, unsigned i)
{
if (i >= 224)
return 0;
return (in[i >> 3] >> (i & 7)) & 1;
}
static void batch_mul(felem x_out, felem y_out, felem z_out,
const felem_bytearray scalars[],
const unsigned num_points, const u8 *g_scalar,
const int mixed, const felem pre_comp[][17][3],
const felem g_pre_comp[2][16][3])
{
int i, skip;
unsigned num;
unsigned gen_mul = (g_scalar != NULL);
felem nq[3], tmp[4];
u64 bits;
u8 sign, digit;
memset(nq, 0, 3 * sizeof(felem));
skip = 1;
for (i = (num_points ? 220 : 27); i >= 0; --i) {
if (!skip)
point_double(nq[0], nq[1], nq[2], nq[0], nq[1], nq[2]);
if (gen_mul && (i <= 27)) {
bits = get_bit(g_scalar, i + 196) << 3;
bits |= get_bit(g_scalar, i + 140) << 2;
bits |= get_bit(g_scalar, i + 84) << 1;
bits |= get_bit(g_scalar, i + 28);
select_point(bits, 16, g_pre_comp[1], tmp);
if (!skip) {
point_add(nq[0], nq[1], nq[2],
nq[0], nq[1], nq[2], 1, tmp[0], tmp[1], tmp[2]);
} else {
memcpy(nq, tmp, 3 * sizeof(felem));
skip = 0;
}
bits = get_bit(g_scalar, i + 168) << 3;
bits |= get_bit(g_scalar, i + 112) << 2;
bits |= get_bit(g_scalar, i + 56) << 1;
bits |= get_bit(g_scalar, i);
select_point(bits, 16, g_pre_comp[0], tmp);
point_add(nq[0], nq[1], nq[2],
nq[0], nq[1], nq[2],
1 , tmp[0], tmp[1], tmp[2]);
}
if (num_points && (i % 5 == 0)) {
for (num = 0; num < num_points; ++num) {
bits = get_bit(scalars[num], i + 4) << 5;
bits |= get_bit(scalars[num], i + 3) << 4;
bits |= get_bit(scalars[num], i + 2) << 3;
bits |= get_bit(scalars[num], i + 1) << 2;
bits |= get_bit(scalars[num], i) << 1;
bits |= get_bit(scalars[num], i - 1);
ec_GFp_nistp_recode_scalar_bits(&sign, &digit, bits);
select_point(digit, 17, pre_comp[num], tmp);
felem_neg(tmp[3], tmp[1]);
copy_conditional(tmp[1], tmp[3], sign);
if (!skip) {
point_add(nq[0], nq[1], nq[2],
nq[0], nq[1], nq[2],
mixed, tmp[0], tmp[1], tmp[2]);
} else {
memcpy(nq, tmp, 3 * sizeof(felem));
skip = 0;
}
}
}
}
felem_assign(x_out, nq[0]);
felem_assign(y_out, nq[1]);
felem_assign(z_out, nq[2]);
}
static NISTP224_PRE_COMP *nistp224_pre_comp_new()
{
NISTP224_PRE_COMP *ret = NULL;
ret = (NISTP224_PRE_COMP *) OPENSSL_malloc(sizeof *ret);
if (!ret) {
ECerr(EC_F_NISTP224_PRE_COMP_NEW, ERR_R_MALLOC_FAILURE);
return ret;
}
memset(ret->g_pre_comp, 0, sizeof(ret->g_pre_comp));
ret->references = 1;
return ret;
}
static void *nistp224_pre_comp_dup(void *src_)
{
NISTP224_PRE_COMP *src = src_;
CRYPTO_add(&src->references, 1, CRYPTO_LOCK_EC_PRE_COMP);
return src_;
}
static void nistp224_pre_comp_free(void *pre_)
{
int i;
NISTP224_PRE_COMP *pre = pre_;
if (!pre)
return;
i = CRYPTO_add(&pre->references, -1, CRYPTO_LOCK_EC_PRE_COMP);
if (i > 0)
return;
OPENSSL_free(pre);
}
static void nistp224_pre_comp_clear_free(void *pre_)
{
int i;
NISTP224_PRE_COMP *pre = pre_;
if (!pre)
return;
i = CRYPTO_add(&pre->references, -1, CRYPTO_LOCK_EC_PRE_COMP);
if (i > 0)
return;
OPENSSL_cleanse(pre, sizeof *pre);
OPENSSL_free(pre);
}
int ec_GFp_nistp224_group_init(EC_GROUP *group)
{
int ret;
ret = ec_GFp_simple_group_init(group);
group->a_is_minus3 = 1;
return ret;
}
int ec_GFp_nistp224_group_set_curve(EC_GROUP *group, const BIGNUM *p,
const BIGNUM *a, const BIGNUM *b,
BN_CTX *ctx)
{
int ret = 0;
BN_CTX *new_ctx = NULL;
BIGNUM *curve_p, *curve_a, *curve_b;
if (ctx == NULL)
if ((ctx = new_ctx = BN_CTX_new()) == NULL)
return 0;
BN_CTX_start(ctx);
if (((curve_p = BN_CTX_get(ctx)) == NULL) ||
((curve_a = BN_CTX_get(ctx)) == NULL) ||
((curve_b = BN_CTX_get(ctx)) == NULL))
goto err;
BN_bin2bn(nistp224_curve_params[0], sizeof(felem_bytearray), curve_p);
BN_bin2bn(nistp224_curve_params[1], sizeof(felem_bytearray), curve_a);
BN_bin2bn(nistp224_curve_params[2], sizeof(felem_bytearray), curve_b);
if ((BN_cmp(curve_p, p)) || (BN_cmp(curve_a, a)) || (BN_cmp(curve_b, b))) {
ECerr(EC_F_EC_GFP_NISTP224_GROUP_SET_CURVE,
EC_R_WRONG_CURVE_PARAMETERS);
goto err;
}
group->field_mod_func = BN_nist_mod_224;
ret = ec_GFp_simple_group_set_curve(group, p, a, b, ctx);
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_nistp224_point_get_affine_coordinates(const EC_GROUP *group,
const EC_POINT *point,
BIGNUM *x, BIGNUM *y,
BN_CTX *ctx)
{
felem z1, z2, x_in, y_in, x_out, y_out;
widefelem tmp;
if (EC_POINT_is_at_infinity(group, point)) {
ECerr(EC_F_EC_GFP_NISTP224_POINT_GET_AFFINE_COORDINATES,
EC_R_POINT_AT_INFINITY);
return 0;
}
if ((!BN_to_felem(x_in, &point->X)) || (!BN_to_felem(y_in, &point->Y)) ||
(!BN_to_felem(z1, &point->Z)))
return 0;
felem_inv(z2, z1);
felem_square(tmp, z2);
felem_reduce(z1, tmp);
felem_mul(tmp, x_in, z1);
felem_reduce(x_in, tmp);
felem_contract(x_out, x_in);
if (x != NULL) {
if (!felem_to_BN(x, x_out)) {
ECerr(EC_F_EC_GFP_NISTP224_POINT_GET_AFFINE_COORDINATES,
ERR_R_BN_LIB);
return 0;
}
}
felem_mul(tmp, z1, z2);
felem_reduce(z1, tmp);
felem_mul(tmp, y_in, z1);
felem_reduce(y_in, tmp);
felem_contract(y_out, y_in);
if (y != NULL) {
if (!felem_to_BN(y, y_out)) {
ECerr(EC_F_EC_GFP_NISTP224_POINT_GET_AFFINE_COORDINATES,
ERR_R_BN_LIB);
return 0;
}
}
return 1;
}
static void make_points_affine(size_t num, felem points[ ][3],
felem tmp_felems[ ])
{
ec_GFp_nistp_points_make_affine_internal(num,
points,
sizeof(felem),
tmp_felems,
(void (*)(void *))felem_one,
(int (*)(const void *))
felem_is_zero_int,
(void (*)(void *, const void *))
felem_assign,
(void (*)(void *, const void *))
felem_square_reduce, (void (*)
(void *,
const void
*,
const void
*))
felem_mul_reduce,
(void (*)(void *, const void *))
felem_inv,
(void (*)(void *, const void *))
felem_contract);
}
int ec_GFp_nistp224_points_mul(const EC_GROUP *group, EC_POINT *r,
const BIGNUM *scalar, size_t num,
const EC_POINT *points[],
const BIGNUM *scalars[], BN_CTX *ctx)
{
int ret = 0;
int j;
unsigned i;
int mixed = 0;
BN_CTX *new_ctx = NULL;
BIGNUM *x, *y, *z, *tmp_scalar;
felem_bytearray g_secret;
felem_bytearray *secrets = NULL;
felem(*pre_comp)[17][3] = NULL;
felem *tmp_felems = NULL;
felem_bytearray tmp;
unsigned num_bytes;
int have_pre_comp = 0;
size_t num_points = num;
felem x_in, y_in, z_in, x_out, y_out, z_out;
NISTP224_PRE_COMP *pre = NULL;
const felem(*g_pre_comp)[16][3] = NULL;
EC_POINT *generator = NULL;
const EC_POINT *p = NULL;
const BIGNUM *p_scalar = NULL;
if (ctx == NULL)
if ((ctx = new_ctx = BN_CTX_new()) == NULL)
return 0;
BN_CTX_start(ctx);
if (((x = BN_CTX_get(ctx)) == NULL) ||
((y = BN_CTX_get(ctx)) == NULL) ||
((z = BN_CTX_get(ctx)) == NULL) ||
((tmp_scalar = BN_CTX_get(ctx)) == NULL))
goto err;
if (scalar != NULL) {
pre = EC_EX_DATA_get_data(group->extra_data,
nistp224_pre_comp_dup,
nistp224_pre_comp_free,
nistp224_pre_comp_clear_free);
if (pre)
g_pre_comp = (const felem(*)[16][3])pre->g_pre_comp;
else
g_pre_comp = &gmul[0];
generator = EC_POINT_new(group);
if (generator == NULL)
goto err;
if (!felem_to_BN(x, g_pre_comp[0][1][0]) ||
!felem_to_BN(y, g_pre_comp[0][1][1]) ||
!felem_to_BN(z, g_pre_comp[0][1][2])) {
ECerr(EC_F_EC_GFP_NISTP224_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
if (!EC_POINT_set_Jprojective_coordinates_GFp(group,
generator, x, y, z,
ctx))
goto err;
if (0 == EC_POINT_cmp(group, generator, group->generator, ctx))
have_pre_comp = 1;
else
num_points = num_points + 1;
}
if (num_points > 0) {
if (num_points >= 3) {
mixed = 1;
}
secrets = OPENSSL_malloc(num_points * sizeof(felem_bytearray));
pre_comp = OPENSSL_malloc(num_points * 17 * 3 * sizeof(felem));
if (mixed)
tmp_felems =
OPENSSL_malloc((num_points * 17 + 1) * sizeof(felem));
if ((secrets == NULL) || (pre_comp == NULL)
|| (mixed && (tmp_felems == NULL))) {
ECerr(EC_F_EC_GFP_NISTP224_POINTS_MUL, ERR_R_MALLOC_FAILURE);
goto err;
}
memset(secrets, 0, num_points * sizeof(felem_bytearray));
memset(pre_comp, 0, num_points * 17 * 3 * sizeof(felem));
for (i = 0; i < num_points; ++i) {
if (i == num)
{
p = EC_GROUP_get0_generator(group);
p_scalar = scalar;
} else
{
p = points[i];
p_scalar = scalars[i];
}
if ((p_scalar != NULL) && (p != NULL)) {
if ((BN_num_bits(p_scalar) > 224)
|| (BN_is_negative(p_scalar))) {
if (!BN_nnmod(tmp_scalar, p_scalar, &group->order, ctx)) {
ECerr(EC_F_EC_GFP_NISTP224_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
num_bytes = BN_bn2bin(tmp_scalar, tmp);
} else
num_bytes = BN_bn2bin(p_scalar, tmp);
flip_endian(secrets[i], tmp, num_bytes);
if ((!BN_to_felem(x_out, &p->X)) ||
(!BN_to_felem(y_out, &p->Y)) ||
(!BN_to_felem(z_out, &p->Z)))
goto err;
felem_assign(pre_comp[i][1][0], x_out);
felem_assign(pre_comp[i][1][1], y_out);
felem_assign(pre_comp[i][1][2], z_out);
for (j = 2; j <= 16; ++j) {
if (j & 1) {
point_add(pre_comp[i][j][0], pre_comp[i][j][1],
pre_comp[i][j][2], pre_comp[i][1][0],
pre_comp[i][1][1], pre_comp[i][1][2], 0,
pre_comp[i][j - 1][0],
pre_comp[i][j - 1][1],
pre_comp[i][j - 1][2]);
} else {
point_double(pre_comp[i][j][0], pre_comp[i][j][1],
pre_comp[i][j][2], pre_comp[i][j / 2][0],
pre_comp[i][j / 2][1],
pre_comp[i][j / 2][2]);
}
}
}
}
if (mixed)
make_points_affine(num_points * 17, pre_comp[0], tmp_felems);
}
if ((scalar != NULL) && (have_pre_comp)) {
memset(g_secret, 0, sizeof g_secret);
if ((BN_num_bits(scalar) > 224) || (BN_is_negative(scalar))) {
if (!BN_nnmod(tmp_scalar, scalar, &group->order, ctx)) {
ECerr(EC_F_EC_GFP_NISTP224_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
num_bytes = BN_bn2bin(tmp_scalar, tmp);
} else
num_bytes = BN_bn2bin(scalar, tmp);
flip_endian(g_secret, tmp, num_bytes);
batch_mul(x_out, y_out, z_out,
(const felem_bytearray(*))secrets, num_points,
g_secret,
mixed, (const felem(*)[17][3])pre_comp, g_pre_comp);
} else
batch_mul(x_out, y_out, z_out,
(const felem_bytearray(*))secrets, num_points,
NULL, mixed, (const felem(*)[17][3])pre_comp, NULL);
felem_contract(x_in, x_out);
felem_contract(y_in, y_out);
felem_contract(z_in, z_out);
if ((!felem_to_BN(x, x_in)) || (!felem_to_BN(y, y_in)) ||
(!felem_to_BN(z, z_in))) {
ECerr(EC_F_EC_GFP_NISTP224_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
ret = EC_POINT_set_Jprojective_coordinates_GFp(group, r, x, y, z, ctx);
err:
BN_CTX_end(ctx);
if (generator != NULL)
EC_POINT_free(generator);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
if (secrets != NULL)
OPENSSL_free(secrets);
if (pre_comp != NULL)
OPENSSL_free(pre_comp);
if (tmp_felems != NULL)
OPENSSL_free(tmp_felems);
return ret;
}
int ec_GFp_nistp224_precompute_mult(EC_GROUP *group, BN_CTX *ctx)
{
int ret = 0;
NISTP224_PRE_COMP *pre = NULL;
int i, j;
BN_CTX *new_ctx = NULL;
BIGNUM *x, *y;
EC_POINT *generator = NULL;
felem tmp_felems[32];
EC_EX_DATA_free_data(&group->extra_data, nistp224_pre_comp_dup,
nistp224_pre_comp_free,
nistp224_pre_comp_clear_free);
if (ctx == NULL)
if ((ctx = new_ctx = BN_CTX_new()) == NULL)
return 0;
BN_CTX_start(ctx);
if (((x = BN_CTX_get(ctx)) == NULL) || ((y = BN_CTX_get(ctx)) == NULL))
goto err;
if (group->generator == NULL)
goto err;
generator = EC_POINT_new(group);
if (generator == NULL)
goto err;
BN_bin2bn(nistp224_curve_params[3], sizeof(felem_bytearray), x);
BN_bin2bn(nistp224_curve_params[4], sizeof(felem_bytearray), y);
if (!EC_POINT_set_affine_coordinates_GFp(group, generator, x, y, ctx))
goto err;
if ((pre = nistp224_pre_comp_new()) == NULL)
goto err;
if (0 == EC_POINT_cmp(group, generator, group->generator, ctx)) {
memcpy(pre->g_pre_comp, gmul, sizeof(pre->g_pre_comp));
ret = 1;
goto err;
}
if ((!BN_to_felem(pre->g_pre_comp[0][1][0], &group->generator->X)) ||
(!BN_to_felem(pre->g_pre_comp[0][1][1], &group->generator->Y)) ||
(!BN_to_felem(pre->g_pre_comp[0][1][2], &group->generator->Z)))
goto err;
for (i = 1; i <= 8; i <<= 1) {
point_double(pre->g_pre_comp[1][i][0], pre->g_pre_comp[1][i][1],
pre->g_pre_comp[1][i][2], pre->g_pre_comp[0][i][0],
pre->g_pre_comp[0][i][1], pre->g_pre_comp[0][i][2]);
for (j = 0; j < 27; ++j) {
point_double(pre->g_pre_comp[1][i][0], pre->g_pre_comp[1][i][1],
pre->g_pre_comp[1][i][2], pre->g_pre_comp[1][i][0],
pre->g_pre_comp[1][i][1], pre->g_pre_comp[1][i][2]);
}
if (i == 8)
break;
point_double(pre->g_pre_comp[0][2 * i][0],
pre->g_pre_comp[0][2 * i][1],
pre->g_pre_comp[0][2 * i][2], pre->g_pre_comp[1][i][0],
pre->g_pre_comp[1][i][1], pre->g_pre_comp[1][i][2]);
for (j = 0; j < 27; ++j) {
point_double(pre->g_pre_comp[0][2 * i][0],
pre->g_pre_comp[0][2 * i][1],
pre->g_pre_comp[0][2 * i][2],
pre->g_pre_comp[0][2 * i][0],
pre->g_pre_comp[0][2 * i][1],
pre->g_pre_comp[0][2 * i][2]);
}
}
for (i = 0; i < 2; i++) {
memset(pre->g_pre_comp[i][0], 0, sizeof(pre->g_pre_comp[i][0]));
point_add(pre->g_pre_comp[i][6][0], pre->g_pre_comp[i][6][1],
pre->g_pre_comp[i][6][2], pre->g_pre_comp[i][4][0],
pre->g_pre_comp[i][4][1], pre->g_pre_comp[i][4][2],
0, pre->g_pre_comp[i][2][0], pre->g_pre_comp[i][2][1],
pre->g_pre_comp[i][2][2]);
point_add(pre->g_pre_comp[i][10][0], pre->g_pre_comp[i][10][1],
pre->g_pre_comp[i][10][2], pre->g_pre_comp[i][8][0],
pre->g_pre_comp[i][8][1], pre->g_pre_comp[i][8][2],
0, pre->g_pre_comp[i][2][0], pre->g_pre_comp[i][2][1],
pre->g_pre_comp[i][2][2]);
point_add(pre->g_pre_comp[i][12][0], pre->g_pre_comp[i][12][1],
pre->g_pre_comp[i][12][2], pre->g_pre_comp[i][8][0],
pre->g_pre_comp[i][8][1], pre->g_pre_comp[i][8][2],
0, pre->g_pre_comp[i][4][0], pre->g_pre_comp[i][4][1],
pre->g_pre_comp[i][4][2]);
point_add(pre->g_pre_comp[i][14][0], pre->g_pre_comp[i][14][1],
pre->g_pre_comp[i][14][2], pre->g_pre_comp[i][12][0],
pre->g_pre_comp[i][12][1], pre->g_pre_comp[i][12][2],
0, pre->g_pre_comp[i][2][0], pre->g_pre_comp[i][2][1],
pre->g_pre_comp[i][2][2]);
for (j = 1; j < 8; ++j) {
point_add(pre->g_pre_comp[i][2 * j + 1][0],
pre->g_pre_comp[i][2 * j + 1][1],
pre->g_pre_comp[i][2 * j + 1][2],
pre->g_pre_comp[i][2 * j][0],
pre->g_pre_comp[i][2 * j][1],
pre->g_pre_comp[i][2 * j][2], 0,
pre->g_pre_comp[i][1][0], pre->g_pre_comp[i][1][1],
pre->g_pre_comp[i][1][2]);
}
}
make_points_affine(31, &(pre->g_pre_comp[0][1]), tmp_felems);
if (!EC_EX_DATA_set_data(&group->extra_data, pre, nistp224_pre_comp_dup,
nistp224_pre_comp_free,
nistp224_pre_comp_clear_free))
goto err;
ret = 1;
pre = NULL;
err:
BN_CTX_end(ctx);
if (generator != NULL)
EC_POINT_free(generator);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
if (pre)
nistp224_pre_comp_free(pre);
return ret;
}
int ec_GFp_nistp224_have_precompute_mult(const EC_GROUP *group)
{
if (EC_EX_DATA_get_data(group->extra_data, nistp224_pre_comp_dup,
nistp224_pre_comp_free,
nistp224_pre_comp_clear_free)
!= NULL)
return 1;
else
return 0;
}
