size_t CRYPTO_128_wrap(void *key, const unsigned char *iv,
unsigned char *out,
const unsigned char *in, size_t inlen,
block128_f block)
{
unsigned char *A, B[16], *R;
size_t i, j, t;
if ((inlen & 0x7) || (inlen < 8) || (inlen > CRYPTO128_WRAP_MAX))
return 0;
A = B;
t = 1;
memcpy(out + 8, in, inlen);
if (!iv)
iv = default_iv;
memcpy(A, iv, 8);
for (j = 0; j < 6; j++) {
R = out + 8;
for (i = 0; i < inlen; i += 8, t++, R += 8) {
memcpy(B + 8, R, 8);
block(B, B, key);
A[7] ^= (unsigned char)(t & 0xff);
if (t > 0xff) {
A[6] ^= (unsigned char)((t >> 8) & 0xff);
A[5] ^= (unsigned char)((t >> 16) & 0xff);
A[4] ^= (unsigned char)((t >> 24) & 0xff);
}
memcpy(R, B + 8, 8);
}
}
memcpy(out, A, 8);
return inlen + 8;
}
size_t CRYPTO_128_unwrap(void *key, const unsigned char *iv,
unsigned char *out,
const unsigned char *in, size_t inlen,
block128_f block)
{
unsigned char *A, B[16], *R;
size_t i, j, t;
inlen -= 8;
if ((inlen & 0x7) || (inlen < 16) || (inlen > CRYPTO128_WRAP_MAX))
return 0;
A = B;
t = 6 * (inlen >> 3);
memcpy(A, in, 8);
memcpy(out, in + 8, inlen);
for (j = 0; j < 6; j++) {
R = out + inlen - 8;
for (i = 0; i < inlen; i += 8, t--, R -= 8) {
A[7] ^= (unsigned char)(t & 0xff);
if (t > 0xff) {
A[6] ^= (unsigned char)((t >> 8) & 0xff);
A[5] ^= (unsigned char)((t >> 16) & 0xff);
A[4] ^= (unsigned char)((t >> 24) & 0xff);
}
memcpy(B + 8, R, 8);
block(B, B, key);
memcpy(R, B + 8, 8);
}
}
if (!iv)
iv = default_iv;
if (memcmp(A, iv, 8)) {
OPENSSL_cleanse(out, inlen);
return 0;
}
return inlen;
}
