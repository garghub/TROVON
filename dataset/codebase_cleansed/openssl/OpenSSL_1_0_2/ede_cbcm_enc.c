void DES_ede3_cbcm_encrypt(const unsigned char *in, unsigned char *out,
long length, DES_key_schedule *ks1,
DES_key_schedule *ks2, DES_key_schedule *ks3,
DES_cblock *ivec1, DES_cblock *ivec2, int enc)
{
register DES_LONG tin0, tin1;
register DES_LONG tout0, tout1, xor0, xor1, m0, m1;
register long l = length;
DES_LONG tin[2];
unsigned char *iv1, *iv2;
iv1 = &(*ivec1)[0];
iv2 = &(*ivec2)[0];
if (enc) {
c2l(iv1, m0);
c2l(iv1, m1);
c2l(iv2, tout0);
c2l(iv2, tout1);
for (l -= 8; l >= -7; l -= 8) {
tin[0] = m0;
tin[1] = m1;
DES_encrypt1(tin, ks3, 1);
m0 = tin[0];
m1 = tin[1];
if (l < 0) {
c2ln(in, tin0, tin1, l + 8);
} else {
c2l(in, tin0);
c2l(in, tin1);
}
tin0 ^= tout0;
tin1 ^= tout1;
tin[0] = tin0;
tin[1] = tin1;
DES_encrypt1(tin, ks1, 1);
tin[0] ^= m0;
tin[1] ^= m1;
DES_encrypt1(tin, ks2, 0);
tin[0] ^= m0;
tin[1] ^= m1;
DES_encrypt1(tin, ks1, 1);
tout0 = tin[0];
tout1 = tin[1];
l2c(tout0, out);
l2c(tout1, out);
}
iv1 = &(*ivec1)[0];
l2c(m0, iv1);
l2c(m1, iv1);
iv2 = &(*ivec2)[0];
l2c(tout0, iv2);
l2c(tout1, iv2);
} else {
register DES_LONG t0, t1;
c2l(iv1, m0);
c2l(iv1, m1);
c2l(iv2, xor0);
c2l(iv2, xor1);
for (l -= 8; l >= -7; l -= 8) {
tin[0] = m0;
tin[1] = m1;
DES_encrypt1(tin, ks3, 1);
m0 = tin[0];
m1 = tin[1];
c2l(in, tin0);
c2l(in, tin1);
t0 = tin0;
t1 = tin1;
tin[0] = tin0;
tin[1] = tin1;
DES_encrypt1(tin, ks1, 0);
tin[0] ^= m0;
tin[1] ^= m1;
DES_encrypt1(tin, ks2, 1);
tin[0] ^= m0;
tin[1] ^= m1;
DES_encrypt1(tin, ks1, 0);
tout0 = tin[0];
tout1 = tin[1];
tout0 ^= xor0;
tout1 ^= xor1;
if (l < 0) {
l2cn(tout0, tout1, out, l + 8);
} else {
l2c(tout0, out);
l2c(tout1, out);
}
xor0 = t0;
xor1 = t1;
}
iv1 = &(*ivec1)[0];
l2c(m0, iv1);
l2c(m1, iv1);
iv2 = &(*ivec2)[0];
l2c(xor0, iv2);
l2c(xor1, iv2);
}
tin0 = tin1 = tout0 = tout1 = xor0 = xor1 = 0;
tin[0] = tin[1] = 0;
}
