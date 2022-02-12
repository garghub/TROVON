static void salsa208_word_specification(uint32_t inout[16])
{
int i;
uint32_t x[16];
memcpy(x, inout, sizeof(x));
for (i = 8; i > 0; i -= 2) {
x[4] ^= R(x[0] + x[12], 7);
x[8] ^= R(x[4] + x[0], 9);
x[12] ^= R(x[8] + x[4], 13);
x[0] ^= R(x[12] + x[8], 18);
x[9] ^= R(x[5] + x[1], 7);
x[13] ^= R(x[9] + x[5], 9);
x[1] ^= R(x[13] + x[9], 13);
x[5] ^= R(x[1] + x[13], 18);
x[14] ^= R(x[10] + x[6], 7);
x[2] ^= R(x[14] + x[10], 9);
x[6] ^= R(x[2] + x[14], 13);
x[10] ^= R(x[6] + x[2], 18);
x[3] ^= R(x[15] + x[11], 7);
x[7] ^= R(x[3] + x[15], 9);
x[11] ^= R(x[7] + x[3], 13);
x[15] ^= R(x[11] + x[7], 18);
x[1] ^= R(x[0] + x[3], 7);
x[2] ^= R(x[1] + x[0], 9);
x[3] ^= R(x[2] + x[1], 13);
x[0] ^= R(x[3] + x[2], 18);
x[6] ^= R(x[5] + x[4], 7);
x[7] ^= R(x[6] + x[5], 9);
x[4] ^= R(x[7] + x[6], 13);
x[5] ^= R(x[4] + x[7], 18);
x[11] ^= R(x[10] + x[9], 7);
x[8] ^= R(x[11] + x[10], 9);
x[9] ^= R(x[8] + x[11], 13);
x[10] ^= R(x[9] + x[8], 18);
x[12] ^= R(x[15] + x[14], 7);
x[13] ^= R(x[12] + x[15], 9);
x[14] ^= R(x[13] + x[12], 13);
x[15] ^= R(x[14] + x[13], 18);
}
for (i = 0; i < 16; ++i)
inout[i] += x[i];
OPENSSL_cleanse(x, sizeof(x));
}
static void scryptBlockMix(uint32_t *B_, uint32_t *B, uint64_t r)
{
uint64_t i, j;
uint32_t X[16], *pB;
memcpy(X, B + (r * 2 - 1) * 16, sizeof(X));
pB = B;
for (i = 0; i < r * 2; i++) {
for (j = 0; j < 16; j++)
X[j] ^= *pB++;
salsa208_word_specification(X);
memcpy(B_ + (i / 2 + (i & 1) * r) * 16, X, sizeof(X));
}
OPENSSL_cleanse(X, sizeof(X));
}
static void scryptROMix(unsigned char *B, uint64_t r, uint64_t N,
uint32_t *X, uint32_t *T, uint32_t *V)
{
unsigned char *pB;
uint32_t *pV;
uint64_t i, k;
for (pV = V, i = 0, pB = B; i < 32 * r; i++, pV++) {
*pV = *pB++;
*pV |= *pB++ << 8;
*pV |= *pB++ << 16;
*pV |= (uint32_t)*pB++ << 24;
}
for (i = 1; i < N; i++, pV += 32 * r)
scryptBlockMix(pV, pV - 32 * r, r);
scryptBlockMix(X, V + (N - 1) * 32 * r, r);
for (i = 0; i < N; i++) {
uint32_t j;
j = X[16 * (2 * r - 1)] % N;
pV = V + 32 * r * j;
for (k = 0; k < 32 * r; k++)
T[k] = X[k] ^ *pV++;
scryptBlockMix(X, T, r);
}
for (i = 0, pB = B; i < 32 * r; i++) {
uint32_t xtmp = X[i];
*pB++ = xtmp & 0xff;
*pB++ = (xtmp >> 8) & 0xff;
*pB++ = (xtmp >> 16) & 0xff;
*pB++ = (xtmp >> 24) & 0xff;
}
}
int EVP_PBE_scrypt(const char *pass, size_t passlen,
const unsigned char *salt, size_t saltlen,
uint64_t N, uint64_t r, uint64_t p, uint64_t maxmem,
unsigned char *key, size_t keylen)
{
int rv = 0;
unsigned char *B;
uint32_t *X, *V, *T;
uint64_t i, Blen, Vlen;
size_t allocsize;
if (r == 0 || p == 0 || N < 2 || (N & (N - 1)))
return 0;
if (p > SCRYPT_PR_MAX / r)
return 0;
if (16 * r <= LOG2_UINT64_MAX) {
if (N >= (((uint64_t)1) << (16 * r)))
return 0;
}
Blen = p * 128 * r;
i = UINT64_MAX / (32 * sizeof(uint32_t));
if (N + 2 > i / r)
return 0;
Vlen = 32 * r * (N + 2) * sizeof(uint32_t);
if (Blen > UINT64_MAX - Vlen)
return 0;
if (Blen > SIZE_MAX - Vlen)
return 0;
allocsize = (size_t)(Blen + Vlen);
if (maxmem == 0)
maxmem = SCRYPT_MAX_MEM;
if (allocsize > maxmem) {
EVPerr(EVP_F_EVP_PBE_SCRYPT, EVP_R_MEMORY_LIMIT_EXCEEDED);
return 0;
}
if (key == NULL)
return 1;
B = OPENSSL_malloc(allocsize);
if (B == NULL)
return 0;
X = (uint32_t *)(B + Blen);
T = X + 32 * r;
V = T + 32 * r;
if (PKCS5_PBKDF2_HMAC(pass, passlen, salt, saltlen, 1, EVP_sha256(),
Blen, B) == 0)
goto err;
for (i = 0; i < p; i++)
scryptROMix(B + 128 * r * i, r, N, X, T, V);
if (PKCS5_PBKDF2_HMAC(pass, passlen, B, Blen, 1, EVP_sha256(),
keylen, key) == 0)
goto err;
rv = 1;
err:
OPENSSL_clear_free(B, allocsize);
return rv;
}
