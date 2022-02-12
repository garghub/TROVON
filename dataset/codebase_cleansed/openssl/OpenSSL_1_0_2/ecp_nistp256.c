static void bin32_to_felem(felem out, const u8 in[32])
{
out[0] = *((u64 *)&in[0]);
out[1] = *((u64 *)&in[8]);
out[2] = *((u64 *)&in[16]);
out[3] = *((u64 *)&in[24]);
}
static void smallfelem_to_bin32(u8 out[32], const smallfelem in)
{
*((u64 *)&out[0]) = in[0];
*((u64 *)&out[8]) = in[1];
*((u64 *)&out[16]) = in[2];
*((u64 *)&out[24]) = in[3];
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
bin32_to_felem(out, b_out);
return 1;
}
static BIGNUM *smallfelem_to_BN(BIGNUM *out, const smallfelem in)
{
felem_bytearray b_in, b_out;
smallfelem_to_bin32(b_in, in);
flip_endian(b_out, b_in, sizeof b_out);
return BN_bin2bn(b_out, sizeof b_out, out);
}
static void smallfelem_one(smallfelem out)
{
out[0] = 1;
out[1] = 0;
out[2] = 0;
out[3] = 0;
}
static void smallfelem_assign(smallfelem out, const smallfelem in)
{
out[0] = in[0];
out[1] = in[1];
out[2] = in[2];
out[3] = in[3];
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
static void felem_small_sum(felem out, const smallfelem in)
{
out[0] += in[0];
out[1] += in[1];
out[2] += in[2];
out[3] += in[3];
}
static void felem_scalar(felem out, const u64 scalar)
{
out[0] *= scalar;
out[1] *= scalar;
out[2] *= scalar;
out[3] *= scalar;
}
static void longfelem_scalar(longfelem out, const u64 scalar)
{
out[0] *= scalar;
out[1] *= scalar;
out[2] *= scalar;
out[3] *= scalar;
out[4] *= scalar;
out[5] *= scalar;
out[6] *= scalar;
out[7] *= scalar;
}
static void smallfelem_neg(felem out, const smallfelem small)
{
out[0] = zero105[0] - small[0];
out[1] = zero105[1] - small[1];
out[2] = zero105[2] - small[2];
out[3] = zero105[3] - small[3];
}
static void felem_diff(felem out, const felem in)
{
out[0] += zero105[0];
out[1] += zero105[1];
out[2] += zero105[2];
out[3] += zero105[3];
out[0] -= in[0];
out[1] -= in[1];
out[2] -= in[2];
out[3] -= in[3];
}
static void felem_diff_zero107(felem out, const felem in)
{
out[0] += zero107[0];
out[1] += zero107[1];
out[2] += zero107[2];
out[3] += zero107[3];
out[0] -= in[0];
out[1] -= in[1];
out[2] -= in[2];
out[3] -= in[3];
}
static void longfelem_diff(longfelem out, const longfelem in)
{
static const limb two70m8p6 =
(((limb) 1) << 70) - (((limb) 1) << 8) + (((limb) 1) << 6);
static const limb two70p40 = (((limb) 1) << 70) + (((limb) 1) << 40);
static const limb two70 = (((limb) 1) << 70);
static const limb two70m40m38p6 =
(((limb) 1) << 70) - (((limb) 1) << 40) - (((limb) 1) << 38) +
(((limb) 1) << 6);
static const limb two70m6 = (((limb) 1) << 70) - (((limb) 1) << 6);
out[0] += two70m8p6;
out[1] += two70p40;
out[2] += two70;
out[3] += two70m40m38p6;
out[4] += two70m6;
out[5] += two70m6;
out[6] += two70m6;
out[7] += two70m6;
out[0] -= in[0];
out[1] -= in[1];
out[2] -= in[2];
out[3] -= in[3];
out[4] -= in[4];
out[5] -= in[5];
out[6] -= in[6];
out[7] -= in[7];
}
static void felem_shrink(smallfelem out, const felem in)
{
felem tmp;
u64 a, b, mask;
s64 high, low;
static const u64 kPrime3Test = 0x7fffffff00000001ul;
tmp[3] = zero110[3] + in[3] + ((u64)(in[2] >> 64));
tmp[2] = zero110[2] + (u64)in[2];
tmp[0] = zero110[0] + in[0];
tmp[1] = zero110[1] + in[1];
a = tmp[3] >> 64;
tmp[3] = (u64)tmp[3];
tmp[3] -= a;
tmp[3] += ((limb) a) << 32;
b = a;
a = tmp[3] >> 64;
b += a;
tmp[3] = (u64)tmp[3];
tmp[3] -= a;
tmp[3] += ((limb) a) << 32;
tmp[0] += b;
tmp[1] -= (((limb) b) << 32);
high = tmp[3] >> 64;
high <<= 63;
high >>= 63;
low = tmp[3];
mask = low >> 63;
low &= bottom63bits;
low -= kPrime3Test;
low = ~low;
low >>= 63;
mask = (mask & low) | high;
tmp[0] -= mask & kPrime[0];
tmp[1] -= mask & kPrime[1];
tmp[3] -= mask & kPrime[3];
tmp[1] += ((u64)(tmp[0] >> 64));
tmp[0] = (u64)tmp[0];
tmp[2] += ((u64)(tmp[1] >> 64));
tmp[1] = (u64)tmp[1];
tmp[3] += ((u64)(tmp[2] >> 64));
tmp[2] = (u64)tmp[2];
out[0] = tmp[0];
out[1] = tmp[1];
out[2] = tmp[2];
out[3] = tmp[3];
}
static void smallfelem_expand(felem out, const smallfelem in)
{
out[0] = in[0];
out[1] = in[1];
out[2] = in[2];
out[3] = in[3];
}
static void smallfelem_square(longfelem out, const smallfelem small)
{
limb a;
u64 high, low;
a = ((uint128_t) small[0]) * small[0];
low = a;
high = a >> 64;
out[0] = low;
out[1] = high;
a = ((uint128_t) small[0]) * small[1];
low = a;
high = a >> 64;
out[1] += low;
out[1] += low;
out[2] = high;
a = ((uint128_t) small[0]) * small[2];
low = a;
high = a >> 64;
out[2] += low;
out[2] *= 2;
out[3] = high;
a = ((uint128_t) small[0]) * small[3];
low = a;
high = a >> 64;
out[3] += low;
out[4] = high;
a = ((uint128_t) small[1]) * small[2];
low = a;
high = a >> 64;
out[3] += low;
out[3] *= 2;
out[4] += high;
a = ((uint128_t) small[1]) * small[1];
low = a;
high = a >> 64;
out[2] += low;
out[3] += high;
a = ((uint128_t) small[1]) * small[3];
low = a;
high = a >> 64;
out[4] += low;
out[4] *= 2;
out[5] = high;
a = ((uint128_t) small[2]) * small[3];
low = a;
high = a >> 64;
out[5] += low;
out[5] *= 2;
out[6] = high;
out[6] += high;
a = ((uint128_t) small[2]) * small[2];
low = a;
high = a >> 64;
out[4] += low;
out[5] += high;
a = ((uint128_t) small[3]) * small[3];
low = a;
high = a >> 64;
out[6] += low;
out[7] = high;
}
static void felem_square(longfelem out, const felem in)
{
u64 small[4];
felem_shrink(small, in);
smallfelem_square(out, small);
}
static void smallfelem_mul(longfelem out, const smallfelem small1,
const smallfelem small2)
{
limb a;
u64 high, low;
a = ((uint128_t) small1[0]) * small2[0];
low = a;
high = a >> 64;
out[0] = low;
out[1] = high;
a = ((uint128_t) small1[0]) * small2[1];
low = a;
high = a >> 64;
out[1] += low;
out[2] = high;
a = ((uint128_t) small1[1]) * small2[0];
low = a;
high = a >> 64;
out[1] += low;
out[2] += high;
a = ((uint128_t) small1[0]) * small2[2];
low = a;
high = a >> 64;
out[2] += low;
out[3] = high;
a = ((uint128_t) small1[1]) * small2[1];
low = a;
high = a >> 64;
out[2] += low;
out[3] += high;
a = ((uint128_t) small1[2]) * small2[0];
low = a;
high = a >> 64;
out[2] += low;
out[3] += high;
a = ((uint128_t) small1[0]) * small2[3];
low = a;
high = a >> 64;
out[3] += low;
out[4] = high;
a = ((uint128_t) small1[1]) * small2[2];
low = a;
high = a >> 64;
out[3] += low;
out[4] += high;
a = ((uint128_t) small1[2]) * small2[1];
low = a;
high = a >> 64;
out[3] += low;
out[4] += high;
a = ((uint128_t) small1[3]) * small2[0];
low = a;
high = a >> 64;
out[3] += low;
out[4] += high;
a = ((uint128_t) small1[1]) * small2[3];
low = a;
high = a >> 64;
out[4] += low;
out[5] = high;
a = ((uint128_t) small1[2]) * small2[2];
low = a;
high = a >> 64;
out[4] += low;
out[5] += high;
a = ((uint128_t) small1[3]) * small2[1];
low = a;
high = a >> 64;
out[4] += low;
out[5] += high;
a = ((uint128_t) small1[2]) * small2[3];
low = a;
high = a >> 64;
out[5] += low;
out[6] = high;
a = ((uint128_t) small1[3]) * small2[2];
low = a;
high = a >> 64;
out[5] += low;
out[6] += high;
a = ((uint128_t) small1[3]) * small2[3];
low = a;
high = a >> 64;
out[6] += low;
out[7] = high;
}
static void felem_mul(longfelem out, const felem in1, const felem in2)
{
smallfelem small1, small2;
felem_shrink(small1, in1);
felem_shrink(small2, in2);
smallfelem_mul(out, small1, small2);
}
static void felem_small_mul(longfelem out, const smallfelem small1,
const felem in2)
{
smallfelem small2;
felem_shrink(small2, in2);
smallfelem_mul(out, small1, small2);
}
static void felem_reduce_(felem out, const longfelem in)
{
int128_t c;
c = in[4] + (in[5] << 32);
out[0] += c;
out[3] -= c;
c = in[5] - in[7];
out[1] += c;
out[2] -= c;
out[1] -= (in[4] << 32);
out[3] += (in[4] << 32);
out[2] -= (in[5] << 32);
out[0] -= in[6];
out[0] -= (in[6] << 32);
out[1] += (in[6] << 33);
out[2] += (in[6] * 2);
out[3] -= (in[6] << 32);
out[0] -= in[7];
out[0] -= (in[7] << 32);
out[2] += (in[7] << 33);
out[3] += (in[7] * 3);
}
static void felem_reduce(felem out, const longfelem in)
{
out[0] = zero100[0] + in[0];
out[1] = zero100[1] + in[1];
out[2] = zero100[2] + in[2];
out[3] = zero100[3] + in[3];
felem_reduce_(out, in);
}
static void felem_reduce_zero105(felem out, const longfelem in)
{
out[0] = zero105[0] + in[0];
out[1] = zero105[1] + in[1];
out[2] = zero105[2] + in[2];
out[3] = zero105[3] + in[3];
felem_reduce_(out, in);
}
static void subtract_u64(u64 *result, u64 *carry, u64 v)
{
uint128_t r = *result;
r -= v;
*carry = (r >> 64) & 1;
*result = (u64)r;
}
static void felem_contract(smallfelem out, const felem in)
{
unsigned i;
u64 all_equal_so_far = 0, result = 0, carry;
felem_shrink(out, in);
all_equal_so_far--;
for (i = 3; i < 4; i--) {
u64 equal;
uint128_t a = ((uint128_t) kPrime[i]) - out[i];
result |= all_equal_so_far & ((u64)(a >> 64));
equal = kPrime[i] ^ out[i];
equal--;
equal &= equal << 32;
equal &= equal << 16;
equal &= equal << 8;
equal &= equal << 4;
equal &= equal << 2;
equal &= equal << 1;
equal = ((s64) equal) >> 63;
all_equal_so_far &= equal;
}
result |= all_equal_so_far;
subtract_u64(&out[0], &carry, result & kPrime[0]);
subtract_u64(&out[1], &carry, carry);
subtract_u64(&out[2], &carry, carry);
subtract_u64(&out[3], &carry, carry);
subtract_u64(&out[1], &carry, result & kPrime[1]);
subtract_u64(&out[2], &carry, carry);
subtract_u64(&out[3], &carry, carry);
subtract_u64(&out[2], &carry, result & kPrime[2]);
subtract_u64(&out[3], &carry, carry);
subtract_u64(&out[3], &carry, result & kPrime[3]);
}
static void smallfelem_square_contract(smallfelem out, const smallfelem in)
{
longfelem longtmp;
felem tmp;
smallfelem_square(longtmp, in);
felem_reduce(tmp, longtmp);
felem_contract(out, tmp);
}
static void smallfelem_mul_contract(smallfelem out, const smallfelem in1,
const smallfelem in2)
{
longfelem longtmp;
felem tmp;
smallfelem_mul(longtmp, in1, in2);
felem_reduce(tmp, longtmp);
felem_contract(out, tmp);
}
static limb smallfelem_is_zero(const smallfelem small)
{
limb result;
u64 is_p;
u64 is_zero = small[0] | small[1] | small[2] | small[3];
is_zero--;
is_zero &= is_zero << 32;
is_zero &= is_zero << 16;
is_zero &= is_zero << 8;
is_zero &= is_zero << 4;
is_zero &= is_zero << 2;
is_zero &= is_zero << 1;
is_zero = ((s64) is_zero) >> 63;
is_p = (small[0] ^ kPrime[0]) |
(small[1] ^ kPrime[1]) |
(small[2] ^ kPrime[2]) | (small[3] ^ kPrime[3]);
is_p--;
is_p &= is_p << 32;
is_p &= is_p << 16;
is_p &= is_p << 8;
is_p &= is_p << 4;
is_p &= is_p << 2;
is_p &= is_p << 1;
is_p = ((s64) is_p) >> 63;
is_zero |= is_p;
result = is_zero;
result |= ((limb) is_zero) << 64;
return result;
}
static int smallfelem_is_zero_int(const smallfelem small)
{
return (int)(smallfelem_is_zero(small) & ((limb) 1));
}
static void felem_inv(felem out, const felem in)
{
felem ftmp, ftmp2;
felem e2, e4, e8, e16, e32, e64;
longfelem tmp;
unsigned i;
felem_square(tmp, in);
felem_reduce(ftmp, tmp);
felem_mul(tmp, in, ftmp);
felem_reduce(ftmp, tmp);
felem_assign(e2, ftmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_mul(tmp, ftmp, e2);
felem_reduce(ftmp, tmp);
felem_assign(e4, ftmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_mul(tmp, ftmp, e4);
felem_reduce(ftmp, tmp);
felem_assign(e8, ftmp);
for (i = 0; i < 8; i++) {
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
}
felem_mul(tmp, ftmp, e8);
felem_reduce(ftmp, tmp);
felem_assign(e16, ftmp);
for (i = 0; i < 16; i++) {
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
}
felem_mul(tmp, ftmp, e16);
felem_reduce(ftmp, tmp);
felem_assign(e32, ftmp);
for (i = 0; i < 32; i++) {
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
}
felem_assign(e64, ftmp);
felem_mul(tmp, ftmp, in);
felem_reduce(ftmp, tmp);
for (i = 0; i < 192; i++) {
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
}
felem_mul(tmp, e64, e32);
felem_reduce(ftmp2, tmp);
for (i = 0; i < 16; i++) {
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
}
felem_mul(tmp, ftmp2, e16);
felem_reduce(ftmp2, tmp);
for (i = 0; i < 8; i++) {
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
}
felem_mul(tmp, ftmp2, e8);
felem_reduce(ftmp2, tmp);
for (i = 0; i < 4; i++) {
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
}
felem_mul(tmp, ftmp2, e4);
felem_reduce(ftmp2, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, ftmp2, e2);
felem_reduce(ftmp2, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, ftmp2, in);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, ftmp2, ftmp);
felem_reduce(out, tmp);
}
static void smallfelem_inv_contract(smallfelem out, const smallfelem in)
{
felem tmp;
smallfelem_expand(tmp, in);
felem_inv(tmp, tmp);
felem_contract(out, tmp);
}
static void
point_double(felem x_out, felem y_out, felem z_out,
const felem x_in, const felem y_in, const felem z_in)
{
longfelem tmp, tmp2;
felem delta, gamma, beta, alpha, ftmp, ftmp2;
smallfelem small1, small2;
felem_assign(ftmp, x_in);
felem_assign(ftmp2, x_in);
felem_square(tmp, z_in);
felem_reduce(delta, tmp);
felem_square(tmp, y_in);
felem_reduce(gamma, tmp);
felem_shrink(small1, gamma);
felem_small_mul(tmp, small1, x_in);
felem_reduce(beta, tmp);
felem_diff(ftmp, delta);
felem_sum(ftmp2, delta);
felem_scalar(ftmp2, 3);
felem_mul(tmp, ftmp, ftmp2);
felem_reduce(alpha, tmp);
felem_shrink(small2, alpha);
smallfelem_square(tmp, small2);
felem_reduce(x_out, tmp);
felem_assign(ftmp, beta);
felem_scalar(ftmp, 8);
felem_diff(x_out, ftmp);
felem_sum(delta, gamma);
felem_assign(ftmp, y_in);
felem_sum(ftmp, z_in);
felem_square(tmp, ftmp);
felem_reduce(z_out, tmp);
felem_diff(z_out, delta);
felem_scalar(beta, 4);
felem_diff_zero107(beta, x_out);
felem_small_mul(tmp, small2, beta);
smallfelem_square(tmp2, small1);
longfelem_scalar(tmp2, 8);
longfelem_diff(tmp, tmp2);
felem_reduce_zero105(y_out, tmp);
}
static void
point_double_small(smallfelem x_out, smallfelem y_out, smallfelem z_out,
const smallfelem x_in, const smallfelem y_in,
const smallfelem z_in)
{
felem felem_x_out, felem_y_out, felem_z_out;
felem felem_x_in, felem_y_in, felem_z_in;
smallfelem_expand(felem_x_in, x_in);
smallfelem_expand(felem_y_in, y_in);
smallfelem_expand(felem_z_in, z_in);
point_double(felem_x_out, felem_y_out, felem_z_out,
felem_x_in, felem_y_in, felem_z_in);
felem_shrink(x_out, felem_x_out);
felem_shrink(y_out, felem_y_out);
felem_shrink(z_out, felem_z_out);
}
static void copy_conditional(felem out, const felem in, limb mask)
{
unsigned i;
for (i = 0; i < NLIMBS; ++i) {
const limb tmp = mask & (in[i] ^ out[i]);
out[i] ^= tmp;
}
}
static void copy_small_conditional(felem out, const smallfelem in, limb mask)
{
unsigned i;
const u64 mask64 = mask;
for (i = 0; i < NLIMBS; ++i) {
out[i] = ((limb) (in[i] & mask64)) | (out[i] & ~mask);
}
}
static void point_add(felem x3, felem y3, felem z3,
const felem x1, const felem y1, const felem z1,
const int mixed, const smallfelem x2,
const smallfelem y2, const smallfelem z2)
{
felem ftmp, ftmp2, ftmp3, ftmp4, ftmp5, ftmp6, x_out, y_out, z_out;
longfelem tmp, tmp2;
smallfelem small1, small2, small3, small4, small5;
limb x_equal, y_equal, z1_is_zero, z2_is_zero;
felem_shrink(small3, z1);
z1_is_zero = smallfelem_is_zero(small3);
z2_is_zero = smallfelem_is_zero(z2);
smallfelem_square(tmp, small3);
felem_reduce(ftmp, tmp);
felem_shrink(small1, ftmp);
if (!mixed) {
smallfelem_square(tmp, z2);
felem_reduce(ftmp2, tmp);
felem_shrink(small2, ftmp2);
felem_shrink(small5, x1);
smallfelem_mul(tmp, small5, small2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp5, z1);
felem_small_sum(ftmp5, z2);
felem_square(tmp, ftmp5);
felem_reduce(ftmp5, tmp);
felem_sum(ftmp2, ftmp);
felem_diff(ftmp5, ftmp2);
smallfelem_mul(tmp, small2, z2);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, y1, ftmp2);
felem_reduce(ftmp6, tmp);
} else {
felem_assign(ftmp3, x1);
felem_assign(ftmp5, z1);
felem_scalar(ftmp5, 2);
felem_assign(ftmp6, y1);
}
smallfelem_mul(tmp, x2, small1);
felem_reduce(ftmp4, tmp);
felem_diff_zero107(ftmp4, ftmp3);
felem_shrink(small4, ftmp4);
x_equal = smallfelem_is_zero(small4);
felem_small_mul(tmp, small4, ftmp5);
felem_reduce(z_out, tmp);
smallfelem_mul(tmp, small1, small3);
felem_reduce(ftmp, tmp);
felem_small_mul(tmp, y2, ftmp);
felem_reduce(ftmp5, tmp);
felem_diff_zero107(ftmp5, ftmp6);
felem_scalar(ftmp5, 2);
felem_shrink(small1, ftmp5);
y_equal = smallfelem_is_zero(small1);
if (x_equal && y_equal && !z1_is_zero && !z2_is_zero) {
point_double(x3, y3, z3, x1, y1, z1);
return;
}
felem_assign(ftmp, ftmp4);
felem_scalar(ftmp, 2);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_mul(tmp, ftmp4, ftmp);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, ftmp3, ftmp);
felem_reduce(ftmp4, tmp);
smallfelem_square(tmp, small1);
felem_reduce(x_out, tmp);
felem_assign(ftmp3, ftmp4);
felem_scalar(ftmp4, 2);
felem_sum(ftmp4, ftmp2);
felem_diff(x_out, ftmp4);
felem_diff_zero107(ftmp3, x_out);
felem_small_mul(tmp, small1, ftmp3);
felem_mul(tmp2, ftmp6, ftmp2);
longfelem_scalar(tmp2, 2);
longfelem_diff(tmp, tmp2);
felem_reduce_zero105(y_out, tmp);
copy_small_conditional(x_out, x2, z1_is_zero);
copy_conditional(x_out, x1, z2_is_zero);
copy_small_conditional(y_out, y2, z1_is_zero);
copy_conditional(y_out, y1, z2_is_zero);
copy_small_conditional(z_out, z2, z1_is_zero);
copy_conditional(z_out, z1, z2_is_zero);
felem_assign(x3, x_out);
felem_assign(y3, y_out);
felem_assign(z3, z_out);
}
static void point_add_small(smallfelem x3, smallfelem y3, smallfelem z3,
smallfelem x1, smallfelem y1, smallfelem z1,
smallfelem x2, smallfelem y2, smallfelem z2)
{
felem felem_x3, felem_y3, felem_z3;
felem felem_x1, felem_y1, felem_z1;
smallfelem_expand(felem_x1, x1);
smallfelem_expand(felem_y1, y1);
smallfelem_expand(felem_z1, z1);
point_add(felem_x3, felem_y3, felem_z3, felem_x1, felem_y1, felem_z1, 0,
x2, y2, z2);
felem_shrink(x3, felem_x3);
felem_shrink(y3, felem_y3);
felem_shrink(z3, felem_z3);
}
static void select_point(const u64 idx, unsigned int size,
const smallfelem pre_comp[16][3], smallfelem out[3])
{
unsigned i, j;
u64 *outlimbs = &out[0][0];
memset(outlimbs, 0, 3 * sizeof(smallfelem));
for (i = 0; i < size; i++) {
const u64 *inlimbs = (u64 *)&pre_comp[i][0][0];
u64 mask = i ^ idx;
mask |= mask >> 4;
mask |= mask >> 2;
mask |= mask >> 1;
mask &= 1;
mask--;
for (j = 0; j < NLIMBS * 3; j++)
outlimbs[j] |= inlimbs[j] & mask;
}
}
static char get_bit(const felem_bytearray in, int i)
{
if ((i < 0) || (i >= 256))
return 0;
return (in[i >> 3] >> (i & 7)) & 1;
}
static void batch_mul(felem x_out, felem y_out, felem z_out,
const felem_bytearray scalars[],
const unsigned num_points, const u8 *g_scalar,
const int mixed, const smallfelem pre_comp[][17][3],
const smallfelem g_pre_comp[2][16][3])
{
int i, skip;
unsigned num, gen_mul = (g_scalar != NULL);
felem nq[3], ftmp;
smallfelem tmp[3];
u64 bits;
u8 sign, digit;
memset(nq, 0, 3 * sizeof(felem));
skip = 1;
for (i = (num_points ? 255 : 31); i >= 0; --i) {
if (!skip)
point_double(nq[0], nq[1], nq[2], nq[0], nq[1], nq[2]);
if (gen_mul && (i <= 31)) {
bits = get_bit(g_scalar, i + 224) << 3;
bits |= get_bit(g_scalar, i + 160) << 2;
bits |= get_bit(g_scalar, i + 96) << 1;
bits |= get_bit(g_scalar, i + 32);
select_point(bits, 16, g_pre_comp[1], tmp);
if (!skip) {
point_add(nq[0], nq[1], nq[2],
nq[0], nq[1], nq[2], 1, tmp[0], tmp[1], tmp[2]);
} else {
smallfelem_expand(nq[0], tmp[0]);
smallfelem_expand(nq[1], tmp[1]);
smallfelem_expand(nq[2], tmp[2]);
skip = 0;
}
bits = get_bit(g_scalar, i + 192) << 3;
bits |= get_bit(g_scalar, i + 128) << 2;
bits |= get_bit(g_scalar, i + 64) << 1;
bits |= get_bit(g_scalar, i);
select_point(bits, 16, g_pre_comp[0], tmp);
point_add(nq[0], nq[1], nq[2],
nq[0], nq[1], nq[2], 1, tmp[0], tmp[1], tmp[2]);
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
smallfelem_neg(ftmp, tmp[1]);
copy_small_conditional(ftmp, tmp[1], (((limb) sign) - 1));
felem_contract(tmp[1], ftmp);
if (!skip) {
point_add(nq[0], nq[1], nq[2],
nq[0], nq[1], nq[2],
mixed, tmp[0], tmp[1], tmp[2]);
} else {
smallfelem_expand(nq[0], tmp[0]);
smallfelem_expand(nq[1], tmp[1]);
smallfelem_expand(nq[2], tmp[2]);
skip = 0;
}
}
}
}
felem_assign(x_out, nq[0]);
felem_assign(y_out, nq[1]);
felem_assign(z_out, nq[2]);
}
const EC_METHOD *EC_GFp_nistp256_method(void)
{
static const EC_METHOD ret = {
EC_FLAGS_DEFAULT_OCT,
NID_X9_62_prime_field,
ec_GFp_nistp256_group_init,
ec_GFp_simple_group_finish,
ec_GFp_simple_group_clear_finish,
ec_GFp_nist_group_copy,
ec_GFp_nistp256_group_set_curve,
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
ec_GFp_nistp256_point_get_affine_coordinates,
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
ec_GFp_nistp256_points_mul,
ec_GFp_nistp256_precompute_mult,
ec_GFp_nistp256_have_precompute_mult,
ec_GFp_nist_field_mul,
ec_GFp_nist_field_sqr,
0 ,
0 ,
0 ,
0
};
return &ret;
}
static NISTP256_PRE_COMP *nistp256_pre_comp_new()
{
NISTP256_PRE_COMP *ret = NULL;
ret = (NISTP256_PRE_COMP *) OPENSSL_malloc(sizeof *ret);
if (!ret) {
ECerr(EC_F_NISTP256_PRE_COMP_NEW, ERR_R_MALLOC_FAILURE);
return ret;
}
memset(ret->g_pre_comp, 0, sizeof(ret->g_pre_comp));
ret->references = 1;
return ret;
}
static void *nistp256_pre_comp_dup(void *src_)
{
NISTP256_PRE_COMP *src = src_;
CRYPTO_add(&src->references, 1, CRYPTO_LOCK_EC_PRE_COMP);
return src_;
}
static void nistp256_pre_comp_free(void *pre_)
{
int i;
NISTP256_PRE_COMP *pre = pre_;
if (!pre)
return;
i = CRYPTO_add(&pre->references, -1, CRYPTO_LOCK_EC_PRE_COMP);
if (i > 0)
return;
OPENSSL_free(pre);
}
static void nistp256_pre_comp_clear_free(void *pre_)
{
int i;
NISTP256_PRE_COMP *pre = pre_;
if (!pre)
return;
i = CRYPTO_add(&pre->references, -1, CRYPTO_LOCK_EC_PRE_COMP);
if (i > 0)
return;
OPENSSL_cleanse(pre, sizeof *pre);
OPENSSL_free(pre);
}
int ec_GFp_nistp256_group_init(EC_GROUP *group)
{
int ret;
ret = ec_GFp_simple_group_init(group);
group->a_is_minus3 = 1;
return ret;
}
int ec_GFp_nistp256_group_set_curve(EC_GROUP *group, const BIGNUM *p,
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
BN_bin2bn(nistp256_curve_params[0], sizeof(felem_bytearray), curve_p);
BN_bin2bn(nistp256_curve_params[1], sizeof(felem_bytearray), curve_a);
BN_bin2bn(nistp256_curve_params[2], sizeof(felem_bytearray), curve_b);
if ((BN_cmp(curve_p, p)) || (BN_cmp(curve_a, a)) || (BN_cmp(curve_b, b))) {
ECerr(EC_F_EC_GFP_NISTP256_GROUP_SET_CURVE,
EC_R_WRONG_CURVE_PARAMETERS);
goto err;
}
group->field_mod_func = BN_nist_mod_256;
ret = ec_GFp_simple_group_set_curve(group, p, a, b, ctx);
err:
BN_CTX_end(ctx);
if (new_ctx != NULL)
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_nistp256_point_get_affine_coordinates(const EC_GROUP *group,
const EC_POINT *point,
BIGNUM *x, BIGNUM *y,
BN_CTX *ctx)
{
felem z1, z2, x_in, y_in;
smallfelem x_out, y_out;
longfelem tmp;
if (EC_POINT_is_at_infinity(group, point)) {
ECerr(EC_F_EC_GFP_NISTP256_POINT_GET_AFFINE_COORDINATES,
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
if (!smallfelem_to_BN(x, x_out)) {
ECerr(EC_F_EC_GFP_NISTP256_POINT_GET_AFFINE_COORDINATES,
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
if (!smallfelem_to_BN(y, y_out)) {
ECerr(EC_F_EC_GFP_NISTP256_POINT_GET_AFFINE_COORDINATES,
ERR_R_BN_LIB);
return 0;
}
}
return 1;
}
static void make_points_affine(size_t num, smallfelem points[][3],
smallfelem tmp_smallfelems[])
{
ec_GFp_nistp_points_make_affine_internal(num,
points,
sizeof(smallfelem),
tmp_smallfelems,
(void (*)(void *))smallfelem_one,
(int (*)(const void *))
smallfelem_is_zero_int,
(void (*)(void *, const void *))
smallfelem_assign,
(void (*)(void *, const void *))
smallfelem_square_contract,
(void (*)
(void *, const void *,
const void *))
smallfelem_mul_contract,
(void (*)(void *, const void *))
smallfelem_inv_contract,
(void (*)(void *, const void *))
smallfelem_assign);
}
int ec_GFp_nistp256_points_mul(const EC_GROUP *group, EC_POINT *r,
const BIGNUM *scalar, size_t num,
const EC_POINT *points[],
const BIGNUM *scalars[], BN_CTX *ctx)
{
int ret = 0;
int j;
int mixed = 0;
BN_CTX *new_ctx = NULL;
BIGNUM *x, *y, *z, *tmp_scalar;
felem_bytearray g_secret;
felem_bytearray *secrets = NULL;
smallfelem(*pre_comp)[17][3] = NULL;
smallfelem *tmp_smallfelems = NULL;
felem_bytearray tmp;
unsigned i, num_bytes;
int have_pre_comp = 0;
size_t num_points = num;
smallfelem x_in, y_in, z_in;
felem x_out, y_out, z_out;
NISTP256_PRE_COMP *pre = NULL;
const smallfelem(*g_pre_comp)[16][3] = NULL;
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
nistp256_pre_comp_dup,
nistp256_pre_comp_free,
nistp256_pre_comp_clear_free);
if (pre)
g_pre_comp = (const smallfelem(*)[16][3])pre->g_pre_comp;
else
g_pre_comp = &gmul[0];
generator = EC_POINT_new(group);
if (generator == NULL)
goto err;
if (!smallfelem_to_BN(x, g_pre_comp[0][1][0]) ||
!smallfelem_to_BN(y, g_pre_comp[0][1][1]) ||
!smallfelem_to_BN(z, g_pre_comp[0][1][2])) {
ECerr(EC_F_EC_GFP_NISTP256_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
if (!EC_POINT_set_Jprojective_coordinates_GFp(group,
generator, x, y, z,
ctx))
goto err;
if (0 == EC_POINT_cmp(group, generator, group->generator, ctx))
have_pre_comp = 1;
else
num_points++;
}
if (num_points > 0) {
if (num_points >= 3) {
mixed = 1;
}
secrets = OPENSSL_malloc(num_points * sizeof(felem_bytearray));
pre_comp = OPENSSL_malloc(num_points * 17 * 3 * sizeof(smallfelem));
if (mixed)
tmp_smallfelems =
OPENSSL_malloc((num_points * 17 + 1) * sizeof(smallfelem));
if ((secrets == NULL) || (pre_comp == NULL)
|| (mixed && (tmp_smallfelems == NULL))) {
ECerr(EC_F_EC_GFP_NISTP256_POINTS_MUL, ERR_R_MALLOC_FAILURE);
goto err;
}
memset(secrets, 0, num_points * sizeof(felem_bytearray));
memset(pre_comp, 0, num_points * 17 * 3 * sizeof(smallfelem));
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
if ((BN_num_bits(p_scalar) > 256)
|| (BN_is_negative(p_scalar))) {
if (!BN_nnmod(tmp_scalar, p_scalar, &group->order, ctx)) {
ECerr(EC_F_EC_GFP_NISTP256_POINTS_MUL, ERR_R_BN_LIB);
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
felem_shrink(pre_comp[i][1][0], x_out);
felem_shrink(pre_comp[i][1][1], y_out);
felem_shrink(pre_comp[i][1][2], z_out);
for (j = 2; j <= 16; ++j) {
if (j & 1) {
point_add_small(pre_comp[i][j][0], pre_comp[i][j][1],
pre_comp[i][j][2], pre_comp[i][1][0],
pre_comp[i][1][1], pre_comp[i][1][2],
pre_comp[i][j - 1][0],
pre_comp[i][j - 1][1],
pre_comp[i][j - 1][2]);
} else {
point_double_small(pre_comp[i][j][0],
pre_comp[i][j][1],
pre_comp[i][j][2],
pre_comp[i][j / 2][0],
pre_comp[i][j / 2][1],
pre_comp[i][j / 2][2]);
}
}
}
}
if (mixed)
make_points_affine(num_points * 17, pre_comp[0], tmp_smallfelems);
}
if ((scalar != NULL) && (have_pre_comp)) {
memset(g_secret, 0, sizeof(g_secret));
if ((BN_num_bits(scalar) > 256) || (BN_is_negative(scalar))) {
if (!BN_nnmod(tmp_scalar, scalar, &group->order, ctx)) {
ECerr(EC_F_EC_GFP_NISTP256_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
num_bytes = BN_bn2bin(tmp_scalar, tmp);
} else
num_bytes = BN_bn2bin(scalar, tmp);
flip_endian(g_secret, tmp, num_bytes);
batch_mul(x_out, y_out, z_out,
(const felem_bytearray(*))secrets, num_points,
g_secret,
mixed, (const smallfelem(*)[17][3])pre_comp, g_pre_comp);
} else
batch_mul(x_out, y_out, z_out,
(const felem_bytearray(*))secrets, num_points,
NULL, mixed, (const smallfelem(*)[17][3])pre_comp, NULL);
felem_contract(x_in, x_out);
felem_contract(y_in, y_out);
felem_contract(z_in, z_out);
if ((!smallfelem_to_BN(x, x_in)) || (!smallfelem_to_BN(y, y_in)) ||
(!smallfelem_to_BN(z, z_in))) {
ECerr(EC_F_EC_GFP_NISTP256_POINTS_MUL, ERR_R_BN_LIB);
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
if (tmp_smallfelems != NULL)
OPENSSL_free(tmp_smallfelems);
return ret;
}
int ec_GFp_nistp256_precompute_mult(EC_GROUP *group, BN_CTX *ctx)
{
int ret = 0;
NISTP256_PRE_COMP *pre = NULL;
int i, j;
BN_CTX *new_ctx = NULL;
BIGNUM *x, *y;
EC_POINT *generator = NULL;
smallfelem tmp_smallfelems[32];
felem x_tmp, y_tmp, z_tmp;
EC_EX_DATA_free_data(&group->extra_data, nistp256_pre_comp_dup,
nistp256_pre_comp_free,
nistp256_pre_comp_clear_free);
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
BN_bin2bn(nistp256_curve_params[3], sizeof(felem_bytearray), x);
BN_bin2bn(nistp256_curve_params[4], sizeof(felem_bytearray), y);
if (!EC_POINT_set_affine_coordinates_GFp(group, generator, x, y, ctx))
goto err;
if ((pre = nistp256_pre_comp_new()) == NULL)
goto err;
if (0 == EC_POINT_cmp(group, generator, group->generator, ctx)) {
memcpy(pre->g_pre_comp, gmul, sizeof(pre->g_pre_comp));
ret = 1;
goto err;
}
if ((!BN_to_felem(x_tmp, &group->generator->X)) ||
(!BN_to_felem(y_tmp, &group->generator->Y)) ||
(!BN_to_felem(z_tmp, &group->generator->Z)))
goto err;
felem_shrink(pre->g_pre_comp[0][1][0], x_tmp);
felem_shrink(pre->g_pre_comp[0][1][1], y_tmp);
felem_shrink(pre->g_pre_comp[0][1][2], z_tmp);
for (i = 1; i <= 8; i <<= 1) {
point_double_small(pre->g_pre_comp[1][i][0], pre->g_pre_comp[1][i][1],
pre->g_pre_comp[1][i][2], pre->g_pre_comp[0][i][0],
pre->g_pre_comp[0][i][1],
pre->g_pre_comp[0][i][2]);
for (j = 0; j < 31; ++j) {
point_double_small(pre->g_pre_comp[1][i][0],
pre->g_pre_comp[1][i][1],
pre->g_pre_comp[1][i][2],
pre->g_pre_comp[1][i][0],
pre->g_pre_comp[1][i][1],
pre->g_pre_comp[1][i][2]);
}
if (i == 8)
break;
point_double_small(pre->g_pre_comp[0][2 * i][0],
pre->g_pre_comp[0][2 * i][1],
pre->g_pre_comp[0][2 * i][2],
pre->g_pre_comp[1][i][0], pre->g_pre_comp[1][i][1],
pre->g_pre_comp[1][i][2]);
for (j = 0; j < 31; ++j) {
point_double_small(pre->g_pre_comp[0][2 * i][0],
pre->g_pre_comp[0][2 * i][1],
pre->g_pre_comp[0][2 * i][2],
pre->g_pre_comp[0][2 * i][0],
pre->g_pre_comp[0][2 * i][1],
pre->g_pre_comp[0][2 * i][2]);
}
}
for (i = 0; i < 2; i++) {
memset(pre->g_pre_comp[i][0], 0, sizeof(pre->g_pre_comp[i][0]));
point_add_small(pre->g_pre_comp[i][6][0], pre->g_pre_comp[i][6][1],
pre->g_pre_comp[i][6][2], pre->g_pre_comp[i][4][0],
pre->g_pre_comp[i][4][1], pre->g_pre_comp[i][4][2],
pre->g_pre_comp[i][2][0], pre->g_pre_comp[i][2][1],
pre->g_pre_comp[i][2][2]);
point_add_small(pre->g_pre_comp[i][10][0], pre->g_pre_comp[i][10][1],
pre->g_pre_comp[i][10][2], pre->g_pre_comp[i][8][0],
pre->g_pre_comp[i][8][1], pre->g_pre_comp[i][8][2],
pre->g_pre_comp[i][2][0], pre->g_pre_comp[i][2][1],
pre->g_pre_comp[i][2][2]);
point_add_small(pre->g_pre_comp[i][12][0], pre->g_pre_comp[i][12][1],
pre->g_pre_comp[i][12][2], pre->g_pre_comp[i][8][0],
pre->g_pre_comp[i][8][1], pre->g_pre_comp[i][8][2],
pre->g_pre_comp[i][4][0], pre->g_pre_comp[i][4][1],
pre->g_pre_comp[i][4][2]);
point_add_small(pre->g_pre_comp[i][14][0], pre->g_pre_comp[i][14][1],
pre->g_pre_comp[i][14][2], pre->g_pre_comp[i][12][0],
pre->g_pre_comp[i][12][1], pre->g_pre_comp[i][12][2],
pre->g_pre_comp[i][2][0], pre->g_pre_comp[i][2][1],
pre->g_pre_comp[i][2][2]);
for (j = 1; j < 8; ++j) {
point_add_small(pre->g_pre_comp[i][2 * j + 1][0],
pre->g_pre_comp[i][2 * j + 1][1],
pre->g_pre_comp[i][2 * j + 1][2],
pre->g_pre_comp[i][2 * j][0],
pre->g_pre_comp[i][2 * j][1],
pre->g_pre_comp[i][2 * j][2],
pre->g_pre_comp[i][1][0],
pre->g_pre_comp[i][1][1],
pre->g_pre_comp[i][1][2]);
}
}
make_points_affine(31, &(pre->g_pre_comp[0][1]), tmp_smallfelems);
if (!EC_EX_DATA_set_data(&group->extra_data, pre, nistp256_pre_comp_dup,
nistp256_pre_comp_free,
nistp256_pre_comp_clear_free))
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
nistp256_pre_comp_free(pre);
return ret;
}
int ec_GFp_nistp256_have_precompute_mult(const EC_GROUP *group)
{
if (EC_EX_DATA_get_data(group->extra_data, nistp256_pre_comp_dup,
nistp256_pre_comp_free,
nistp256_pre_comp_clear_free)
!= NULL)
return 1;
else
return 0;
}
