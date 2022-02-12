static void bin66_to_felem(felem out, const u8 in[66])
{
out[0] = (*((limb *) & in[0])) & bottom58bits;
out[1] = (*((limb *) & in[7]) >> 2) & bottom58bits;
out[2] = (*((limb *) & in[14]) >> 4) & bottom58bits;
out[3] = (*((limb *) & in[21]) >> 6) & bottom58bits;
out[4] = (*((limb *) & in[29])) & bottom58bits;
out[5] = (*((limb *) & in[36]) >> 2) & bottom58bits;
out[6] = (*((limb *) & in[43]) >> 4) & bottom58bits;
out[7] = (*((limb *) & in[50]) >> 6) & bottom58bits;
out[8] = (*((limb *) & in[58])) & bottom57bits;
}
static void felem_to_bin66(u8 out[66], const felem in)
{
memset(out, 0, 66);
(*((limb *) & out[0])) = in[0];
(*((limb *) & out[7])) |= in[1] << 2;
(*((limb *) & out[14])) |= in[2] << 4;
(*((limb *) & out[21])) |= in[3] << 6;
(*((limb *) & out[29])) = in[4];
(*((limb *) & out[36])) |= in[5] << 2;
(*((limb *) & out[43])) |= in[6] << 4;
(*((limb *) & out[50])) |= in[7] << 6;
(*((limb *) & out[58])) = in[8];
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
memset(b_out, 0, sizeof(b_out));
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
bin66_to_felem(out, b_out);
return 1;
}
static BIGNUM *felem_to_BN(BIGNUM *out, const felem in)
{
felem_bytearray b_in, b_out;
felem_to_bin66(b_in, in);
flip_endian(b_out, b_in, sizeof b_out);
return BN_bin2bn(b_out, sizeof b_out, out);
}
static void felem_one(felem out)
{
out[0] = 1;
out[1] = 0;
out[2] = 0;
out[3] = 0;
out[4] = 0;
out[5] = 0;
out[6] = 0;
out[7] = 0;
out[8] = 0;
}
static void felem_assign(felem out, const felem in)
{
out[0] = in[0];
out[1] = in[1];
out[2] = in[2];
out[3] = in[3];
out[4] = in[4];
out[5] = in[5];
out[6] = in[6];
out[7] = in[7];
out[8] = in[8];
}
static void felem_sum64(felem out, const felem in)
{
out[0] += in[0];
out[1] += in[1];
out[2] += in[2];
out[3] += in[3];
out[4] += in[4];
out[5] += in[5];
out[6] += in[6];
out[7] += in[7];
out[8] += in[8];
}
static void felem_scalar(felem out, const felem in, limb scalar)
{
out[0] = in[0] * scalar;
out[1] = in[1] * scalar;
out[2] = in[2] * scalar;
out[3] = in[3] * scalar;
out[4] = in[4] * scalar;
out[5] = in[5] * scalar;
out[6] = in[6] * scalar;
out[7] = in[7] * scalar;
out[8] = in[8] * scalar;
}
static void felem_scalar64(felem out, limb scalar)
{
out[0] *= scalar;
out[1] *= scalar;
out[2] *= scalar;
out[3] *= scalar;
out[4] *= scalar;
out[5] *= scalar;
out[6] *= scalar;
out[7] *= scalar;
out[8] *= scalar;
}
static void felem_scalar128(largefelem out, limb scalar)
{
out[0] *= scalar;
out[1] *= scalar;
out[2] *= scalar;
out[3] *= scalar;
out[4] *= scalar;
out[5] *= scalar;
out[6] *= scalar;
out[7] *= scalar;
out[8] *= scalar;
}
static void felem_neg(felem out, const felem in)
{
static const limb two62m3 = (((limb) 1) << 62) - (((limb) 1) << 5);
static const limb two62m2 = (((limb) 1) << 62) - (((limb) 1) << 4);
out[0] = two62m3 - in[0];
out[1] = two62m2 - in[1];
out[2] = two62m2 - in[2];
out[3] = two62m2 - in[3];
out[4] = two62m2 - in[4];
out[5] = two62m2 - in[5];
out[6] = two62m2 - in[6];
out[7] = two62m2 - in[7];
out[8] = two62m2 - in[8];
}
static void felem_diff64(felem out, const felem in)
{
static const limb two62m3 = (((limb) 1) << 62) - (((limb) 1) << 5);
static const limb two62m2 = (((limb) 1) << 62) - (((limb) 1) << 4);
out[0] += two62m3 - in[0];
out[1] += two62m2 - in[1];
out[2] += two62m2 - in[2];
out[3] += two62m2 - in[3];
out[4] += two62m2 - in[4];
out[5] += two62m2 - in[5];
out[6] += two62m2 - in[6];
out[7] += two62m2 - in[7];
out[8] += two62m2 - in[8];
}
static void felem_diff_128_64(largefelem out, const felem in)
{
static const limb two63m6 = (((limb) 1) << 62) - (((limb) 1) << 5);
static const limb two63m5 = (((limb) 1) << 62) - (((limb) 1) << 4);
out[0] += two63m6 - in[0];
out[1] += two63m5 - in[1];
out[2] += two63m5 - in[2];
out[3] += two63m5 - in[3];
out[4] += two63m5 - in[4];
out[5] += two63m5 - in[5];
out[6] += two63m5 - in[6];
out[7] += two63m5 - in[7];
out[8] += two63m5 - in[8];
}
static void felem_diff128(largefelem out, const largefelem in)
{
static const uint128_t two127m70 =
(((uint128_t) 1) << 127) - (((uint128_t) 1) << 70);
static const uint128_t two127m69 =
(((uint128_t) 1) << 127) - (((uint128_t) 1) << 69);
out[0] += (two127m70 - in[0]);
out[1] += (two127m69 - in[1]);
out[2] += (two127m69 - in[2]);
out[3] += (two127m69 - in[3]);
out[4] += (two127m69 - in[4]);
out[5] += (two127m69 - in[5]);
out[6] += (two127m69 - in[6]);
out[7] += (two127m69 - in[7]);
out[8] += (two127m69 - in[8]);
}
static void felem_square(largefelem out, const felem in)
{
felem inx2, inx4;
felem_scalar(inx2, in, 2);
felem_scalar(inx4, in, 4);
out[0] = ((uint128_t) in[0]) * in[0];
out[1] = ((uint128_t) in[0]) * inx2[1];
out[2] = ((uint128_t) in[0]) * inx2[2] + ((uint128_t) in[1]) * in[1];
out[3] = ((uint128_t) in[0]) * inx2[3] + ((uint128_t) in[1]) * inx2[2];
out[4] = ((uint128_t) in[0]) * inx2[4] +
((uint128_t) in[1]) * inx2[3] + ((uint128_t) in[2]) * in[2];
out[5] = ((uint128_t) in[0]) * inx2[5] +
((uint128_t) in[1]) * inx2[4] + ((uint128_t) in[2]) * inx2[3];
out[6] = ((uint128_t) in[0]) * inx2[6] +
((uint128_t) in[1]) * inx2[5] +
((uint128_t) in[2]) * inx2[4] + ((uint128_t) in[3]) * in[3];
out[7] = ((uint128_t) in[0]) * inx2[7] +
((uint128_t) in[1]) * inx2[6] +
((uint128_t) in[2]) * inx2[5] + ((uint128_t) in[3]) * inx2[4];
out[8] = ((uint128_t) in[0]) * inx2[8] +
((uint128_t) in[1]) * inx2[7] +
((uint128_t) in[2]) * inx2[6] +
((uint128_t) in[3]) * inx2[5] + ((uint128_t) in[4]) * in[4];
out[0] += ((uint128_t) in[1]) * inx4[8] +
((uint128_t) in[2]) * inx4[7] +
((uint128_t) in[3]) * inx4[6] + ((uint128_t) in[4]) * inx4[5];
out[1] += ((uint128_t) in[2]) * inx4[8] +
((uint128_t) in[3]) * inx4[7] +
((uint128_t) in[4]) * inx4[6] + ((uint128_t) in[5]) * inx2[5];
out[2] += ((uint128_t) in[3]) * inx4[8] +
((uint128_t) in[4]) * inx4[7] + ((uint128_t) in[5]) * inx4[6];
out[3] += ((uint128_t) in[4]) * inx4[8] +
((uint128_t) in[5]) * inx4[7] + ((uint128_t) in[6]) * inx2[6];
out[4] += ((uint128_t) in[5]) * inx4[8] + ((uint128_t) in[6]) * inx4[7];
out[5] += ((uint128_t) in[6]) * inx4[8] + ((uint128_t) in[7]) * inx2[7];
out[6] += ((uint128_t) in[7]) * inx4[8];
out[7] += ((uint128_t) in[8]) * inx2[8];
}
static void felem_mul(largefelem out, const felem in1, const felem in2)
{
felem in2x2;
felem_scalar(in2x2, in2, 2);
out[0] = ((uint128_t) in1[0]) * in2[0];
out[1] = ((uint128_t) in1[0]) * in2[1] +
((uint128_t) in1[1]) * in2[0];
out[2] = ((uint128_t) in1[0]) * in2[2] +
((uint128_t) in1[1]) * in2[1] +
((uint128_t) in1[2]) * in2[0];
out[3] = ((uint128_t) in1[0]) * in2[3] +
((uint128_t) in1[1]) * in2[2] +
((uint128_t) in1[2]) * in2[1] +
((uint128_t) in1[3]) * in2[0];
out[4] = ((uint128_t) in1[0]) * in2[4] +
((uint128_t) in1[1]) * in2[3] +
((uint128_t) in1[2]) * in2[2] +
((uint128_t) in1[3]) * in2[1] +
((uint128_t) in1[4]) * in2[0];
out[5] = ((uint128_t) in1[0]) * in2[5] +
((uint128_t) in1[1]) * in2[4] +
((uint128_t) in1[2]) * in2[3] +
((uint128_t) in1[3]) * in2[2] +
((uint128_t) in1[4]) * in2[1] +
((uint128_t) in1[5]) * in2[0];
out[6] = ((uint128_t) in1[0]) * in2[6] +
((uint128_t) in1[1]) * in2[5] +
((uint128_t) in1[2]) * in2[4] +
((uint128_t) in1[3]) * in2[3] +
((uint128_t) in1[4]) * in2[2] +
((uint128_t) in1[5]) * in2[1] +
((uint128_t) in1[6]) * in2[0];
out[7] = ((uint128_t) in1[0]) * in2[7] +
((uint128_t) in1[1]) * in2[6] +
((uint128_t) in1[2]) * in2[5] +
((uint128_t) in1[3]) * in2[4] +
((uint128_t) in1[4]) * in2[3] +
((uint128_t) in1[5]) * in2[2] +
((uint128_t) in1[6]) * in2[1] +
((uint128_t) in1[7]) * in2[0];
out[8] = ((uint128_t) in1[0]) * in2[8] +
((uint128_t) in1[1]) * in2[7] +
((uint128_t) in1[2]) * in2[6] +
((uint128_t) in1[3]) * in2[5] +
((uint128_t) in1[4]) * in2[4] +
((uint128_t) in1[5]) * in2[3] +
((uint128_t) in1[6]) * in2[2] +
((uint128_t) in1[7]) * in2[1] +
((uint128_t) in1[8]) * in2[0];
out[0] += ((uint128_t) in1[1]) * in2x2[8] +
((uint128_t) in1[2]) * in2x2[7] +
((uint128_t) in1[3]) * in2x2[6] +
((uint128_t) in1[4]) * in2x2[5] +
((uint128_t) in1[5]) * in2x2[4] +
((uint128_t) in1[6]) * in2x2[3] +
((uint128_t) in1[7]) * in2x2[2] +
((uint128_t) in1[8]) * in2x2[1];
out[1] += ((uint128_t) in1[2]) * in2x2[8] +
((uint128_t) in1[3]) * in2x2[7] +
((uint128_t) in1[4]) * in2x2[6] +
((uint128_t) in1[5]) * in2x2[5] +
((uint128_t) in1[6]) * in2x2[4] +
((uint128_t) in1[7]) * in2x2[3] +
((uint128_t) in1[8]) * in2x2[2];
out[2] += ((uint128_t) in1[3]) * in2x2[8] +
((uint128_t) in1[4]) * in2x2[7] +
((uint128_t) in1[5]) * in2x2[6] +
((uint128_t) in1[6]) * in2x2[5] +
((uint128_t) in1[7]) * in2x2[4] +
((uint128_t) in1[8]) * in2x2[3];
out[3] += ((uint128_t) in1[4]) * in2x2[8] +
((uint128_t) in1[5]) * in2x2[7] +
((uint128_t) in1[6]) * in2x2[6] +
((uint128_t) in1[7]) * in2x2[5] +
((uint128_t) in1[8]) * in2x2[4];
out[4] += ((uint128_t) in1[5]) * in2x2[8] +
((uint128_t) in1[6]) * in2x2[7] +
((uint128_t) in1[7]) * in2x2[6] +
((uint128_t) in1[8]) * in2x2[5];
out[5] += ((uint128_t) in1[6]) * in2x2[8] +
((uint128_t) in1[7]) * in2x2[7] +
((uint128_t) in1[8]) * in2x2[6];
out[6] += ((uint128_t) in1[7]) * in2x2[8] +
((uint128_t) in1[8]) * in2x2[7];
out[7] += ((uint128_t) in1[8]) * in2x2[8];
}
static void felem_reduce(felem out, const largefelem in)
{
u64 overflow1, overflow2;
out[0] = ((limb) in[0]) & bottom58bits;
out[1] = ((limb) in[1]) & bottom58bits;
out[2] = ((limb) in[2]) & bottom58bits;
out[3] = ((limb) in[3]) & bottom58bits;
out[4] = ((limb) in[4]) & bottom58bits;
out[5] = ((limb) in[5]) & bottom58bits;
out[6] = ((limb) in[6]) & bottom58bits;
out[7] = ((limb) in[7]) & bottom58bits;
out[8] = ((limb) in[8]) & bottom58bits;
out[1] += ((limb) in[0]) >> 58;
out[1] += (((limb) (in[0] >> 64)) & bottom52bits) << 6;
out[2] += ((limb) (in[0] >> 64)) >> 52;
out[2] += ((limb) in[1]) >> 58;
out[2] += (((limb) (in[1] >> 64)) & bottom52bits) << 6;
out[3] += ((limb) (in[1] >> 64)) >> 52;
out[3] += ((limb) in[2]) >> 58;
out[3] += (((limb) (in[2] >> 64)) & bottom52bits) << 6;
out[4] += ((limb) (in[2] >> 64)) >> 52;
out[4] += ((limb) in[3]) >> 58;
out[4] += (((limb) (in[3] >> 64)) & bottom52bits) << 6;
out[5] += ((limb) (in[3] >> 64)) >> 52;
out[5] += ((limb) in[4]) >> 58;
out[5] += (((limb) (in[4] >> 64)) & bottom52bits) << 6;
out[6] += ((limb) (in[4] >> 64)) >> 52;
out[6] += ((limb) in[5]) >> 58;
out[6] += (((limb) (in[5] >> 64)) & bottom52bits) << 6;
out[7] += ((limb) (in[5] >> 64)) >> 52;
out[7] += ((limb) in[6]) >> 58;
out[7] += (((limb) (in[6] >> 64)) & bottom52bits) << 6;
out[8] += ((limb) (in[6] >> 64)) >> 52;
out[8] += ((limb) in[7]) >> 58;
out[8] += (((limb) (in[7] >> 64)) & bottom52bits) << 6;
overflow1 = ((limb) (in[7] >> 64)) >> 52;
overflow1 += ((limb) in[8]) >> 58;
overflow1 += (((limb) (in[8] >> 64)) & bottom52bits) << 6;
overflow2 = ((limb) (in[8] >> 64)) >> 52;
overflow1 <<= 1;
overflow2 <<= 1;
out[0] += overflow1;
out[1] += overflow2;
out[1] += out[0] >> 58;
out[0] &= bottom58bits;
}
static void felem_square_reduce(felem out, const felem in)
{
largefelem tmp;
felem_square(tmp, in);
felem_reduce(out, tmp);
}
static void felem_mul_reduce(felem out, const felem in1, const felem in2)
{
largefelem tmp;
felem_mul(tmp, in1, in2);
felem_reduce(out, tmp);
}
static void felem_inv(felem out, const felem in)
{
felem ftmp, ftmp2, ftmp3, ftmp4;
largefelem tmp;
unsigned i;
felem_square(tmp, in);
felem_reduce(ftmp, tmp);
felem_mul(tmp, in, ftmp);
felem_reduce(ftmp, tmp);
felem_assign(ftmp2, ftmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_mul(tmp, in, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_square(tmp, ftmp2);
felem_reduce(ftmp3, tmp);
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp2, ftmp3);
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp4, ftmp3);
felem_mul(tmp, ftmp3, ftmp);
felem_reduce(ftmp4, tmp);
felem_square(tmp, ftmp4);
felem_reduce(ftmp4, tmp);
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp2, ftmp3);
for (i = 0; i < 8; i++) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp2, ftmp3);
for (i = 0; i < 16; i++) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp2, ftmp3);
for (i = 0; i < 32; i++) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp2, ftmp3);
for (i = 0; i < 64; i++) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp2, ftmp3);
for (i = 0; i < 128; i++) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp2, ftmp3);
for (i = 0; i < 256; i++) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp2);
felem_reduce(ftmp3, tmp);
for (i = 0; i < 9; i++) {
felem_square(tmp, ftmp3);
felem_reduce(ftmp3, tmp);
}
felem_mul(tmp, ftmp3, ftmp4);
felem_reduce(ftmp3, tmp);
felem_mul(tmp, ftmp3, in);
felem_reduce(out, tmp);
}
static limb felem_is_zero(const felem in)
{
felem ftmp;
limb is_zero, is_p;
felem_assign(ftmp, in);
ftmp[0] += ftmp[8] >> 57;
ftmp[8] &= bottom57bits;
ftmp[1] += ftmp[0] >> 58;
ftmp[0] &= bottom58bits;
ftmp[2] += ftmp[1] >> 58;
ftmp[1] &= bottom58bits;
ftmp[3] += ftmp[2] >> 58;
ftmp[2] &= bottom58bits;
ftmp[4] += ftmp[3] >> 58;
ftmp[3] &= bottom58bits;
ftmp[5] += ftmp[4] >> 58;
ftmp[4] &= bottom58bits;
ftmp[6] += ftmp[5] >> 58;
ftmp[5] &= bottom58bits;
ftmp[7] += ftmp[6] >> 58;
ftmp[6] &= bottom58bits;
ftmp[8] += ftmp[7] >> 58;
ftmp[7] &= bottom58bits;
is_zero = 0;
is_zero |= ftmp[0];
is_zero |= ftmp[1];
is_zero |= ftmp[2];
is_zero |= ftmp[3];
is_zero |= ftmp[4];
is_zero |= ftmp[5];
is_zero |= ftmp[6];
is_zero |= ftmp[7];
is_zero |= ftmp[8];
is_zero--;
is_zero = ((s64) is_zero) >> 63;
is_p = ftmp[0] ^ kPrime[0];
is_p |= ftmp[1] ^ kPrime[1];
is_p |= ftmp[2] ^ kPrime[2];
is_p |= ftmp[3] ^ kPrime[3];
is_p |= ftmp[4] ^ kPrime[4];
is_p |= ftmp[5] ^ kPrime[5];
is_p |= ftmp[6] ^ kPrime[6];
is_p |= ftmp[7] ^ kPrime[7];
is_p |= ftmp[8] ^ kPrime[8];
is_p--;
is_p = ((s64) is_p) >> 63;
is_zero |= is_p;
return is_zero;
}
static int felem_is_zero_int(const felem in)
{
return (int)(felem_is_zero(in) & ((limb) 1));
}
static void felem_contract(felem out, const felem in)
{
limb is_p, is_greater, sign;
static const limb two58 = ((limb) 1) << 58;
felem_assign(out, in);
out[0] += out[8] >> 57;
out[8] &= bottom57bits;
out[1] += out[0] >> 58;
out[0] &= bottom58bits;
out[2] += out[1] >> 58;
out[1] &= bottom58bits;
out[3] += out[2] >> 58;
out[2] &= bottom58bits;
out[4] += out[3] >> 58;
out[3] &= bottom58bits;
out[5] += out[4] >> 58;
out[4] &= bottom58bits;
out[6] += out[5] >> 58;
out[5] &= bottom58bits;
out[7] += out[6] >> 58;
out[6] &= bottom58bits;
out[8] += out[7] >> 58;
out[7] &= bottom58bits;
is_p = out[0] ^ kPrime[0];
is_p |= out[1] ^ kPrime[1];
is_p |= out[2] ^ kPrime[2];
is_p |= out[3] ^ kPrime[3];
is_p |= out[4] ^ kPrime[4];
is_p |= out[5] ^ kPrime[5];
is_p |= out[6] ^ kPrime[6];
is_p |= out[7] ^ kPrime[7];
is_p |= out[8] ^ kPrime[8];
is_p--;
is_p &= is_p << 32;
is_p &= is_p << 16;
is_p &= is_p << 8;
is_p &= is_p << 4;
is_p &= is_p << 2;
is_p &= is_p << 1;
is_p = ((s64) is_p) >> 63;
is_p = ~is_p;
out[0] &= is_p;
out[1] &= is_p;
out[2] &= is_p;
out[3] &= is_p;
out[4] &= is_p;
out[5] &= is_p;
out[6] &= is_p;
out[7] &= is_p;
out[8] &= is_p;
is_greater = out[8] >> 57;
is_greater |= is_greater << 32;
is_greater |= is_greater << 16;
is_greater |= is_greater << 8;
is_greater |= is_greater << 4;
is_greater |= is_greater << 2;
is_greater |= is_greater << 1;
is_greater = ((s64) is_greater) >> 63;
out[0] -= kPrime[0] & is_greater;
out[1] -= kPrime[1] & is_greater;
out[2] -= kPrime[2] & is_greater;
out[3] -= kPrime[3] & is_greater;
out[4] -= kPrime[4] & is_greater;
out[5] -= kPrime[5] & is_greater;
out[6] -= kPrime[6] & is_greater;
out[7] -= kPrime[7] & is_greater;
out[8] -= kPrime[8] & is_greater;
sign = -(out[0] >> 63);
out[0] += (two58 & sign);
out[1] -= (1 & sign);
sign = -(out[1] >> 63);
out[1] += (two58 & sign);
out[2] -= (1 & sign);
sign = -(out[2] >> 63);
out[2] += (two58 & sign);
out[3] -= (1 & sign);
sign = -(out[3] >> 63);
out[3] += (two58 & sign);
out[4] -= (1 & sign);
sign = -(out[4] >> 63);
out[4] += (two58 & sign);
out[5] -= (1 & sign);
sign = -(out[0] >> 63);
out[5] += (two58 & sign);
out[6] -= (1 & sign);
sign = -(out[6] >> 63);
out[6] += (two58 & sign);
out[7] -= (1 & sign);
sign = -(out[7] >> 63);
out[7] += (two58 & sign);
out[8] -= (1 & sign);
sign = -(out[5] >> 63);
out[5] += (two58 & sign);
out[6] -= (1 & sign);
sign = -(out[6] >> 63);
out[6] += (two58 & sign);
out[7] -= (1 & sign);
sign = -(out[7] >> 63);
out[7] += (two58 & sign);
out[8] -= (1 & sign);
}
static void
point_double(felem x_out, felem y_out, felem z_out,
const felem x_in, const felem y_in, const felem z_in)
{
largefelem tmp, tmp2;
felem delta, gamma, beta, alpha, ftmp, ftmp2;
felem_assign(ftmp, x_in);
felem_assign(ftmp2, x_in);
felem_square(tmp, z_in);
felem_reduce(delta, tmp);
felem_square(tmp, y_in);
felem_reduce(gamma, tmp);
felem_mul(tmp, x_in, gamma);
felem_reduce(beta, tmp);
felem_diff64(ftmp, delta);
felem_sum64(ftmp2, delta);
felem_scalar64(ftmp2, 3);
felem_mul(tmp, ftmp, ftmp2);
felem_reduce(alpha, tmp);
felem_square(tmp, alpha);
felem_assign(ftmp, beta);
felem_scalar64(ftmp, 8);
felem_diff_128_64(tmp, ftmp);
felem_reduce(x_out, tmp);
felem_sum64(delta, gamma);
felem_assign(ftmp, y_in);
felem_sum64(ftmp, z_in);
felem_square(tmp, ftmp);
felem_diff_128_64(tmp, delta);
felem_reduce(z_out, tmp);
felem_scalar64(beta, 4);
felem_diff64(beta, x_out);
felem_mul(tmp, alpha, beta);
felem_square(tmp2, gamma);
felem_scalar128(tmp2, 8);
felem_diff128(tmp, tmp2);
felem_reduce(y_out, tmp);
}
static void copy_conditional(felem out, const felem in, limb mask)
{
unsigned i;
for (i = 0; i < NLIMBS; ++i) {
const limb tmp = mask & (in[i] ^ out[i]);
out[i] ^= tmp;
}
}
static void point_add(felem x3, felem y3, felem z3,
const felem x1, const felem y1, const felem z1,
const int mixed, const felem x2, const felem y2,
const felem z2)
{
felem ftmp, ftmp2, ftmp3, ftmp4, ftmp5, ftmp6, x_out, y_out, z_out;
largefelem tmp, tmp2;
limb x_equal, y_equal, z1_is_zero, z2_is_zero;
z1_is_zero = felem_is_zero(z1);
z2_is_zero = felem_is_zero(z2);
felem_square(tmp, z1);
felem_reduce(ftmp, tmp);
if (!mixed) {
felem_square(tmp, z2);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, x1, ftmp2);
felem_reduce(ftmp3, tmp);
felem_assign(ftmp5, z1);
felem_sum64(ftmp5, z2);
felem_square(tmp, ftmp5);
felem_diff_128_64(tmp, ftmp);
felem_diff_128_64(tmp, ftmp2);
felem_reduce(ftmp5, tmp);
felem_mul(tmp, ftmp2, z2);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, y1, ftmp2);
felem_reduce(ftmp6, tmp);
} else {
felem_assign(ftmp3, x1);
felem_scalar(ftmp5, z1, 2);
felem_assign(ftmp6, y1);
}
felem_mul(tmp, x2, ftmp);
felem_diff_128_64(tmp, ftmp3);
felem_reduce(ftmp4, tmp);
x_equal = felem_is_zero(ftmp4);
felem_mul(tmp, ftmp5, ftmp4);
felem_reduce(z_out, tmp);
felem_mul(tmp, ftmp, z1);
felem_reduce(ftmp, tmp);
felem_mul(tmp, y2, ftmp);
felem_diff_128_64(tmp, ftmp6);
felem_reduce(ftmp5, tmp);
y_equal = felem_is_zero(ftmp5);
felem_scalar64(ftmp5, 2);
if (x_equal && y_equal && !z1_is_zero && !z2_is_zero) {
point_double(x3, y3, z3, x1, y1, z1);
return;
}
felem_assign(ftmp, ftmp4);
felem_scalar64(ftmp, 2);
felem_square(tmp, ftmp);
felem_reduce(ftmp, tmp);
felem_mul(tmp, ftmp4, ftmp);
felem_reduce(ftmp2, tmp);
felem_mul(tmp, ftmp3, ftmp);
felem_reduce(ftmp4, tmp);
felem_square(tmp, ftmp5);
felem_diff_128_64(tmp, ftmp2);
felem_assign(ftmp3, ftmp4);
felem_scalar64(ftmp4, 2);
felem_diff_128_64(tmp, ftmp4);
felem_reduce(x_out, tmp);
felem_diff64(ftmp3, x_out);
felem_mul(tmp, ftmp5, ftmp3);
felem_mul(tmp2, ftmp6, ftmp2);
felem_scalar128(tmp2, 2);
felem_diff128(tmp, tmp2);
felem_reduce(y_out, tmp);
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
static void select_point(const limb idx, unsigned int size,
const felem pre_comp[][3], felem out[3])
{
unsigned i, j;
limb *outlimbs = &out[0][0];
memset(out, 0, sizeof(*out) * 3);
for (i = 0; i < size; i++) {
const limb *inlimbs = &pre_comp[i][0][0];
limb mask = i ^ idx;
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
if (i < 0)
return 0;
return (in[i >> 3] >> (i & 7)) & 1;
}
static void batch_mul(felem x_out, felem y_out, felem z_out,
const felem_bytearray scalars[],
const unsigned num_points, const u8 *g_scalar,
const int mixed, const felem pre_comp[][17][3],
const felem g_pre_comp[16][3])
{
int i, skip;
unsigned num, gen_mul = (g_scalar != NULL);
felem nq[3], tmp[4];
limb bits;
u8 sign, digit;
memset(nq, 0, sizeof(nq));
skip = 1;
for (i = (num_points ? 520 : 130); i >= 0; --i) {
if (!skip)
point_double(nq[0], nq[1], nq[2], nq[0], nq[1], nq[2]);
if (gen_mul && (i <= 130)) {
bits = get_bit(g_scalar, i + 390) << 3;
if (i < 130) {
bits |= get_bit(g_scalar, i + 260) << 2;
bits |= get_bit(g_scalar, i + 130) << 1;
bits |= get_bit(g_scalar, i);
}
select_point(bits, 16, g_pre_comp, tmp);
if (!skip) {
point_add(nq[0], nq[1], nq[2],
nq[0], nq[1], nq[2], 1, tmp[0], tmp[1], tmp[2]);
} else {
memcpy(nq, tmp, 3 * sizeof(felem));
skip = 0;
}
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
copy_conditional(tmp[1], tmp[3], (-(limb) sign));
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
const EC_METHOD *EC_GFp_nistp521_method(void)
{
static const EC_METHOD ret = {
EC_FLAGS_DEFAULT_OCT,
NID_X9_62_prime_field,
ec_GFp_nistp521_group_init,
ec_GFp_simple_group_finish,
ec_GFp_simple_group_clear_finish,
ec_GFp_nist_group_copy,
ec_GFp_nistp521_group_set_curve,
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
ec_GFp_nistp521_point_get_affine_coordinates,
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
ec_GFp_nistp521_points_mul,
ec_GFp_nistp521_precompute_mult,
ec_GFp_nistp521_have_precompute_mult,
ec_GFp_nist_field_mul,
ec_GFp_nist_field_sqr,
0 ,
0 ,
0 ,
0,
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
static NISTP521_PRE_COMP *nistp521_pre_comp_new()
{
NISTP521_PRE_COMP *ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL) {
ECerr(EC_F_NISTP521_PRE_COMP_NEW, ERR_R_MALLOC_FAILURE);
return ret;
}
ret->references = 1;
ret->lock = CRYPTO_THREAD_lock_new();
if (ret->lock == NULL) {
ECerr(EC_F_NISTP521_PRE_COMP_NEW, ERR_R_MALLOC_FAILURE);
OPENSSL_free(ret);
return NULL;
}
return ret;
}
NISTP521_PRE_COMP *EC_nistp521_pre_comp_dup(NISTP521_PRE_COMP *p)
{
int i;
if (p != NULL)
CRYPTO_atomic_add(&p->references, 1, &i, p->lock);
return p;
}
void EC_nistp521_pre_comp_free(NISTP521_PRE_COMP *p)
{
int i;
if (p == NULL)
return;
CRYPTO_atomic_add(&p->references, -1, &i, p->lock);
REF_PRINT_COUNT("EC_nistp521", x);
if (i > 0)
return;
REF_ASSERT_ISNT(i < 0);
CRYPTO_THREAD_lock_free(p->lock);
OPENSSL_free(p);
}
int ec_GFp_nistp521_group_init(EC_GROUP *group)
{
int ret;
ret = ec_GFp_simple_group_init(group);
group->a_is_minus3 = 1;
return ret;
}
int ec_GFp_nistp521_group_set_curve(EC_GROUP *group, const BIGNUM *p,
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
BN_bin2bn(nistp521_curve_params[0], sizeof(felem_bytearray), curve_p);
BN_bin2bn(nistp521_curve_params[1], sizeof(felem_bytearray), curve_a);
BN_bin2bn(nistp521_curve_params[2], sizeof(felem_bytearray), curve_b);
if ((BN_cmp(curve_p, p)) || (BN_cmp(curve_a, a)) || (BN_cmp(curve_b, b))) {
ECerr(EC_F_EC_GFP_NISTP521_GROUP_SET_CURVE,
EC_R_WRONG_CURVE_PARAMETERS);
goto err;
}
group->field_mod_func = BN_nist_mod_521;
ret = ec_GFp_simple_group_set_curve(group, p, a, b, ctx);
err:
BN_CTX_end(ctx);
BN_CTX_free(new_ctx);
return ret;
}
int ec_GFp_nistp521_point_get_affine_coordinates(const EC_GROUP *group,
const EC_POINT *point,
BIGNUM *x, BIGNUM *y,
BN_CTX *ctx)
{
felem z1, z2, x_in, y_in, x_out, y_out;
largefelem tmp;
if (EC_POINT_is_at_infinity(group, point)) {
ECerr(EC_F_EC_GFP_NISTP521_POINT_GET_AFFINE_COORDINATES,
EC_R_POINT_AT_INFINITY);
return 0;
}
if ((!BN_to_felem(x_in, point->X)) || (!BN_to_felem(y_in, point->Y)) ||
(!BN_to_felem(z1, point->Z)))
return 0;
felem_inv(z2, z1);
felem_square(tmp, z2);
felem_reduce(z1, tmp);
felem_mul(tmp, x_in, z1);
felem_reduce(x_in, tmp);
felem_contract(x_out, x_in);
if (x != NULL) {
if (!felem_to_BN(x, x_out)) {
ECerr(EC_F_EC_GFP_NISTP521_POINT_GET_AFFINE_COORDINATES,
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
ECerr(EC_F_EC_GFP_NISTP521_POINT_GET_AFFINE_COORDINATES,
ERR_R_BN_LIB);
return 0;
}
}
return 1;
}
static void make_points_affine(size_t num, felem points[][3],
felem tmp_felems[])
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
int ec_GFp_nistp521_points_mul(const EC_GROUP *group, EC_POINT *r,
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
felem (*pre_comp)[17][3] = NULL;
felem *tmp_felems = NULL;
felem_bytearray tmp;
unsigned i, num_bytes;
int have_pre_comp = 0;
size_t num_points = num;
felem x_in, y_in, z_in, x_out, y_out, z_out;
NISTP521_PRE_COMP *pre = NULL;
felem(*g_pre_comp)[3] = NULL;
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
pre = group->pre_comp.nistp521;
if (pre)
g_pre_comp = &pre->g_pre_comp[0];
else
g_pre_comp = (felem(*)[3]) gmul;
generator = EC_POINT_new(group);
if (generator == NULL)
goto err;
if (!felem_to_BN(x, g_pre_comp[1][0]) ||
!felem_to_BN(y, g_pre_comp[1][1]) ||
!felem_to_BN(z, g_pre_comp[1][2])) {
ECerr(EC_F_EC_GFP_NISTP521_POINTS_MUL, ERR_R_BN_LIB);
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
if (num_points >= 2) {
mixed = 1;
}
secrets = OPENSSL_zalloc(sizeof(*secrets) * num_points);
pre_comp = OPENSSL_zalloc(sizeof(*pre_comp) * num_points);
if (mixed)
tmp_felems =
OPENSSL_malloc(sizeof(*tmp_felems) * (num_points * 17 + 1));
if ((secrets == NULL) || (pre_comp == NULL)
|| (mixed && (tmp_felems == NULL))) {
ECerr(EC_F_EC_GFP_NISTP521_POINTS_MUL, ERR_R_MALLOC_FAILURE);
goto err;
}
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
if ((BN_num_bits(p_scalar) > 521)
|| (BN_is_negative(p_scalar))) {
if (!BN_nnmod(tmp_scalar, p_scalar, group->order, ctx)) {
ECerr(EC_F_EC_GFP_NISTP521_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
num_bytes = BN_bn2bin(tmp_scalar, tmp);
} else
num_bytes = BN_bn2bin(p_scalar, tmp);
flip_endian(secrets[i], tmp, num_bytes);
if ((!BN_to_felem(x_out, p->X)) ||
(!BN_to_felem(y_out, p->Y)) ||
(!BN_to_felem(z_out, p->Z)))
goto err;
memcpy(pre_comp[i][1][0], x_out, sizeof(felem));
memcpy(pre_comp[i][1][1], y_out, sizeof(felem));
memcpy(pre_comp[i][1][2], z_out, sizeof(felem));
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
memset(g_secret, 0, sizeof(g_secret));
if ((BN_num_bits(scalar) > 521) || (BN_is_negative(scalar))) {
if (!BN_nnmod(tmp_scalar, scalar, group->order, ctx)) {
ECerr(EC_F_EC_GFP_NISTP521_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
num_bytes = BN_bn2bin(tmp_scalar, tmp);
} else
num_bytes = BN_bn2bin(scalar, tmp);
flip_endian(g_secret, tmp, num_bytes);
batch_mul(x_out, y_out, z_out,
(const felem_bytearray(*))secrets, num_points,
g_secret,
mixed, (const felem(*)[17][3])pre_comp,
(const felem(*)[3])g_pre_comp);
} else
batch_mul(x_out, y_out, z_out,
(const felem_bytearray(*))secrets, num_points,
NULL, mixed, (const felem(*)[17][3])pre_comp, NULL);
felem_contract(x_in, x_out);
felem_contract(y_in, y_out);
felem_contract(z_in, z_out);
if ((!felem_to_BN(x, x_in)) || (!felem_to_BN(y, y_in)) ||
(!felem_to_BN(z, z_in))) {
ECerr(EC_F_EC_GFP_NISTP521_POINTS_MUL, ERR_R_BN_LIB);
goto err;
}
ret = EC_POINT_set_Jprojective_coordinates_GFp(group, r, x, y, z, ctx);
err:
BN_CTX_end(ctx);
EC_POINT_free(generator);
BN_CTX_free(new_ctx);
OPENSSL_free(secrets);
OPENSSL_free(pre_comp);
OPENSSL_free(tmp_felems);
return ret;
}
int ec_GFp_nistp521_precompute_mult(EC_GROUP *group, BN_CTX *ctx)
{
int ret = 0;
NISTP521_PRE_COMP *pre = NULL;
int i, j;
BN_CTX *new_ctx = NULL;
BIGNUM *x, *y;
EC_POINT *generator = NULL;
felem tmp_felems[16];
EC_pre_comp_free(group);
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
BN_bin2bn(nistp521_curve_params[3], sizeof(felem_bytearray), x);
BN_bin2bn(nistp521_curve_params[4], sizeof(felem_bytearray), y);
if (!EC_POINT_set_affine_coordinates_GFp(group, generator, x, y, ctx))
goto err;
if ((pre = nistp521_pre_comp_new()) == NULL)
goto err;
if (0 == EC_POINT_cmp(group, generator, group->generator, ctx)) {
memcpy(pre->g_pre_comp, gmul, sizeof(pre->g_pre_comp));
goto done;
}
if ((!BN_to_felem(pre->g_pre_comp[1][0], group->generator->X)) ||
(!BN_to_felem(pre->g_pre_comp[1][1], group->generator->Y)) ||
(!BN_to_felem(pre->g_pre_comp[1][2], group->generator->Z)))
goto err;
for (i = 1; i <= 4; i <<= 1) {
point_double(pre->g_pre_comp[2 * i][0], pre->g_pre_comp[2 * i][1],
pre->g_pre_comp[2 * i][2], pre->g_pre_comp[i][0],
pre->g_pre_comp[i][1], pre->g_pre_comp[i][2]);
for (j = 0; j < 129; ++j) {
point_double(pre->g_pre_comp[2 * i][0],
pre->g_pre_comp[2 * i][1],
pre->g_pre_comp[2 * i][2],
pre->g_pre_comp[2 * i][0],
pre->g_pre_comp[2 * i][1],
pre->g_pre_comp[2 * i][2]);
}
}
memset(pre->g_pre_comp[0], 0, sizeof(pre->g_pre_comp[0]));
point_add(pre->g_pre_comp[6][0], pre->g_pre_comp[6][1],
pre->g_pre_comp[6][2], pre->g_pre_comp[4][0],
pre->g_pre_comp[4][1], pre->g_pre_comp[4][2],
0, pre->g_pre_comp[2][0], pre->g_pre_comp[2][1],
pre->g_pre_comp[2][2]);
point_add(pre->g_pre_comp[10][0], pre->g_pre_comp[10][1],
pre->g_pre_comp[10][2], pre->g_pre_comp[8][0],
pre->g_pre_comp[8][1], pre->g_pre_comp[8][2],
0, pre->g_pre_comp[2][0], pre->g_pre_comp[2][1],
pre->g_pre_comp[2][2]);
point_add(pre->g_pre_comp[12][0], pre->g_pre_comp[12][1],
pre->g_pre_comp[12][2], pre->g_pre_comp[8][0],
pre->g_pre_comp[8][1], pre->g_pre_comp[8][2],
0, pre->g_pre_comp[4][0], pre->g_pre_comp[4][1],
pre->g_pre_comp[4][2]);
point_add(pre->g_pre_comp[14][0], pre->g_pre_comp[14][1],
pre->g_pre_comp[14][2], pre->g_pre_comp[12][0],
pre->g_pre_comp[12][1], pre->g_pre_comp[12][2],
0, pre->g_pre_comp[2][0], pre->g_pre_comp[2][1],
pre->g_pre_comp[2][2]);
for (i = 1; i < 8; ++i) {
point_add(pre->g_pre_comp[2 * i + 1][0],
pre->g_pre_comp[2 * i + 1][1],
pre->g_pre_comp[2 * i + 1][2], pre->g_pre_comp[2 * i][0],
pre->g_pre_comp[2 * i][1], pre->g_pre_comp[2 * i][2], 0,
pre->g_pre_comp[1][0], pre->g_pre_comp[1][1],
pre->g_pre_comp[1][2]);
}
make_points_affine(15, &(pre->g_pre_comp[1]), tmp_felems);
done:
SETPRECOMP(group, nistp521, pre);
ret = 1;
pre = NULL;
err:
BN_CTX_end(ctx);
EC_POINT_free(generator);
BN_CTX_free(new_ctx);
EC_nistp521_pre_comp_free(pre);
return ret;
}
int ec_GFp_nistp521_have_precompute_mult(const EC_GROUP *group)
{
return HAVEPRECOMP(group, nistp521);
}
