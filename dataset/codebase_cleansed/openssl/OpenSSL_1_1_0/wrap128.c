size_t CRYPTO_128_wrap(void *key, const unsigned char *iv,
unsigned char *out,
const unsigned char *in, size_t inlen,
block128_f block)
{
unsigned char *A, B[16], *R;
size_t i, j, t;
if ((inlen & 0x7) || (inlen < 16) || (inlen > CRYPTO128_WRAP_MAX))
return 0;
A = B;
t = 1;
memmove(out + 8, in, inlen);
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
static size_t crypto_128_unwrap_raw(void *key, unsigned char *iv,
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
memmove(out, in + 8, inlen);
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
memcpy(iv, A, 8);
return inlen;
}
size_t CRYPTO_128_unwrap(void *key, const unsigned char *iv,
unsigned char *out, const unsigned char *in,
size_t inlen, block128_f block)
{
size_t ret;
unsigned char got_iv[8];
ret = crypto_128_unwrap_raw(key, got_iv, out, in, inlen, block);
if (ret == 0)
return 0;
if (!iv)
iv = default_iv;
if (CRYPTO_memcmp(got_iv, iv, 8)) {
OPENSSL_cleanse(out, ret);
return 0;
}
return ret;
}
size_t CRYPTO_128_wrap_pad(void *key, const unsigned char *icv,
unsigned char *out,
const unsigned char *in, size_t inlen,
block128_f block)
{
const size_t blocks_padded = (inlen + 7) / 8;
const size_t padded_len = blocks_padded * 8;
const size_t padding_len = padded_len - inlen;
unsigned char aiv[8];
int ret;
if (inlen == 0 || inlen >= CRYPTO128_WRAP_MAX)
return 0;
if (!icv)
memcpy(aiv, default_aiv, 4);
else
memcpy(aiv, icv, 4);
aiv[4] = (inlen >> 24) & 0xFF;
aiv[5] = (inlen >> 16) & 0xFF;
aiv[6] = (inlen >> 8) & 0xFF;
aiv[7] = inlen & 0xFF;
if (padded_len == 8) {
memmove(out + 8, in, inlen);
memcpy(out, aiv, 8);
memset(out + 8 + inlen, 0, padding_len);
block(out, out, key);
ret = 16;
} else {
memmove(out, in, inlen);
memset(out + inlen, 0, padding_len);
ret = CRYPTO_128_wrap(key, aiv, out, out, padded_len, block);
}
return ret;
}
size_t CRYPTO_128_unwrap_pad(void *key, const unsigned char *icv,
unsigned char *out,
const unsigned char *in, size_t inlen,
block128_f block)
{
size_t n = inlen / 8 - 1;
size_t padded_len;
size_t padding_len;
size_t ptext_len;
unsigned char aiv[8];
static unsigned char zeros[8] = { 0x0 };
size_t ret;
if ((inlen & 0x7) != 0 || inlen < 16 || inlen >= CRYPTO128_WRAP_MAX)
return 0;
memmove(out, in, inlen);
if (inlen == 16) {
block(out, out, key);
memcpy(aiv, out, 8);
memmove(out, out + 8, 8);
padded_len = 8;
} else {
padded_len = inlen - 8;
ret = crypto_128_unwrap_raw(key, aiv, out, out, inlen, block);
if (padded_len != ret) {
OPENSSL_cleanse(out, inlen);
return 0;
}
}
if ((!icv && CRYPTO_memcmp(aiv, default_aiv, 4))
|| (icv && CRYPTO_memcmp(aiv, icv, 4))) {
OPENSSL_cleanse(out, inlen);
return 0;
}
ptext_len = ((unsigned int)aiv[4] << 24)
| ((unsigned int)aiv[5] << 16)
| ((unsigned int)aiv[6] << 8)
| (unsigned int)aiv[7];
if (8 * (n - 1) >= ptext_len || ptext_len > 8 * n) {
OPENSSL_cleanse(out, inlen);
return 0;
}
padding_len = padded_len - ptext_len;
if (CRYPTO_memcmp(out + ptext_len, zeros, padding_len) != 0) {
OPENSSL_cleanse(out, inlen);
return 0;
}
return ptext_len;
}
