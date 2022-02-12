size_t CRYPTO_cts128_encrypt_block(const unsigned char *in,
unsigned char *out, size_t len,
const void *key, unsigned char ivec[16],
block128_f block)
{
size_t residue, n;
if (len <= 16)
return 0;
if ((residue = len % 16) == 0)
residue = 16;
len -= residue;
CRYPTO_cbc128_encrypt(in, out, len, key, ivec, block);
in += len;
out += len;
for (n = 0; n < residue; ++n)
ivec[n] ^= in[n];
(*block) (ivec, ivec, key);
memcpy(out, out - 16, residue);
memcpy(out - 16, ivec, 16);
return len + residue;
}
size_t CRYPTO_nistcts128_encrypt_block(const unsigned char *in,
unsigned char *out, size_t len,
const void *key,
unsigned char ivec[16],
block128_f block)
{
size_t residue, n;
if (len < 16)
return 0;
residue = len % 16;
len -= residue;
CRYPTO_cbc128_encrypt(in, out, len, key, ivec, block);
if (residue == 0)
return len;
in += len;
out += len;
for (n = 0; n < residue; ++n)
ivec[n] ^= in[n];
(*block) (ivec, ivec, key);
memcpy(out - 16 + residue, ivec, 16);
return len + residue;
}
size_t CRYPTO_cts128_encrypt(const unsigned char *in, unsigned char *out,
size_t len, const void *key,
unsigned char ivec[16], cbc128_f cbc)
{
size_t residue;
union {
size_t align;
unsigned char c[16];
} tmp;
if (len <= 16)
return 0;
if ((residue = len % 16) == 0)
residue = 16;
len -= residue;
(*cbc) (in, out, len, key, ivec, 1);
in += len;
out += len;
#if defined(CBC_HANDLES_TRUNCATED_IO)
memcpy(tmp.c, out - 16, 16);
(*cbc) (in, out - 16, residue, key, ivec, 1);
memcpy(out, tmp.c, residue);
#else
memset(tmp.c, 0, sizeof(tmp));
memcpy(tmp.c, in, residue);
memcpy(out, out - 16, residue);
(*cbc) (tmp.c, out - 16, 16, key, ivec, 1);
#endif
return len + residue;
}
size_t CRYPTO_nistcts128_encrypt(const unsigned char *in, unsigned char *out,
size_t len, const void *key,
unsigned char ivec[16], cbc128_f cbc)
{
size_t residue;
union {
size_t align;
unsigned char c[16];
} tmp;
if (len < 16)
return 0;
residue = len % 16;
len -= residue;
(*cbc) (in, out, len, key, ivec, 1);
if (residue == 0)
return len;
in += len;
out += len;
#if defined(CBC_HANDLES_TRUNCATED_IO)
(*cbc) (in, out - 16 + residue, residue, key, ivec, 1);
#else
memset(tmp.c, 0, sizeof(tmp));
memcpy(tmp.c, in, residue);
(*cbc) (tmp.c, out - 16 + residue, 16, key, ivec, 1);
#endif
return len + residue;
}
size_t CRYPTO_cts128_decrypt_block(const unsigned char *in,
unsigned char *out, size_t len,
const void *key, unsigned char ivec[16],
block128_f block)
{
size_t residue, n;
union {
size_t align;
unsigned char c[32];
} tmp;
if (len <= 16)
return 0;
if ((residue = len % 16) == 0)
residue = 16;
len -= 16 + residue;
if (len) {
CRYPTO_cbc128_decrypt(in, out, len, key, ivec, block);
in += len;
out += len;
}
(*block) (in, tmp.c + 16, key);
memcpy(tmp.c, tmp.c + 16, 16);
memcpy(tmp.c, in + 16, residue);
(*block) (tmp.c, tmp.c, key);
for (n = 0; n < 16; ++n) {
unsigned char c = in[n];
out[n] = tmp.c[n] ^ ivec[n];
ivec[n] = c;
}
for (residue += 16; n < residue; ++n)
out[n] = tmp.c[n] ^ in[n];
return 16 + len + residue;
}
size_t CRYPTO_nistcts128_decrypt_block(const unsigned char *in,
unsigned char *out, size_t len,
const void *key,
unsigned char ivec[16],
block128_f block)
{
size_t residue, n;
union {
size_t align;
unsigned char c[32];
} tmp;
if (len < 16)
return 0;
residue = len % 16;
if (residue == 0) {
CRYPTO_cbc128_decrypt(in, out, len, key, ivec, block);
return len;
}
len -= 16 + residue;
if (len) {
CRYPTO_cbc128_decrypt(in, out, len, key, ivec, block);
in += len;
out += len;
}
(*block) (in + residue, tmp.c + 16, key);
memcpy(tmp.c, tmp.c + 16, 16);
memcpy(tmp.c, in, residue);
(*block) (tmp.c, tmp.c, key);
for (n = 0; n < 16; ++n) {
unsigned char c = in[n];
out[n] = tmp.c[n] ^ ivec[n];
ivec[n] = in[n + residue];
tmp.c[n] = c;
}
for (residue += 16; n < residue; ++n)
out[n] = tmp.c[n] ^ tmp.c[n - 16];
return 16 + len + residue;
}
size_t CRYPTO_cts128_decrypt(const unsigned char *in, unsigned char *out,
size_t len, const void *key,
unsigned char ivec[16], cbc128_f cbc)
{
size_t residue;
union {
size_t align;
unsigned char c[32];
} tmp;
if (len <= 16)
return 0;
if ((residue = len % 16) == 0)
residue = 16;
len -= 16 + residue;
if (len) {
(*cbc) (in, out, len, key, ivec, 0);
in += len;
out += len;
}
memset(tmp.c, 0, sizeof(tmp));
(*cbc) (in, tmp.c, 16, key, tmp.c + 16, 0);
memcpy(tmp.c, in + 16, residue);
#if defined(CBC_HANDLES_TRUNCATED_IO)
(*cbc) (tmp.c, out, 16 + residue, key, ivec, 0);
#else
(*cbc) (tmp.c, tmp.c, 32, key, ivec, 0);
memcpy(out, tmp.c, 16 + residue);
#endif
return 16 + len + residue;
}
size_t CRYPTO_nistcts128_decrypt(const unsigned char *in, unsigned char *out,
size_t len, const void *key,
unsigned char ivec[16], cbc128_f cbc)
{
size_t residue;
union {
size_t align;
unsigned char c[32];
} tmp;
if (len < 16)
return 0;
residue = len % 16;
if (residue == 0) {
(*cbc) (in, out, len, key, ivec, 0);
return len;
}
len -= 16 + residue;
if (len) {
(*cbc) (in, out, len, key, ivec, 0);
in += len;
out += len;
}
memset(tmp.c, 0, sizeof(tmp));
(*cbc) (in + residue, tmp.c, 16, key, tmp.c + 16, 0);
memcpy(tmp.c, in, residue);
#if defined(CBC_HANDLES_TRUNCATED_IO)
(*cbc) (tmp.c, out, 16 + residue, key, ivec, 0);
#else
(*cbc) (tmp.c, tmp.c, 32, key, ivec, 0);
memcpy(out, tmp.c, 16 + residue);
#endif
return 16 + len + residue;
}
void test_vector(const unsigned char *vector, size_t len)
{
unsigned char iv[sizeof(test_iv)];
unsigned char cleartext[64], ciphertext[64];
size_t tail;
printf("vector_%d\n", len);
fflush(stdout);
if ((tail = len % 16) == 0)
tail = 16;
tail += 16;
memcpy(iv, test_iv, sizeof(test_iv));
CRYPTO_cts128_encrypt_block(test_input, ciphertext, len, &encks, iv,
(block128_f) AES_encrypt);
if (memcmp(ciphertext, vector, len))
fprintf(stderr, "output_%d mismatch\n", len), exit(1);
if (memcmp(iv, vector + len - tail, sizeof(iv)))
fprintf(stderr, "iv_%d mismatch\n", len), exit(1);
memcpy(iv, test_iv, sizeof(test_iv));
CRYPTO_cts128_decrypt_block(ciphertext, cleartext, len, &decks, iv,
(block128_f) AES_decrypt);
if (memcmp(cleartext, test_input, len))
fprintf(stderr, "input_%d mismatch\n", len), exit(2);
if (memcmp(iv, vector + len - tail, sizeof(iv)))
fprintf(stderr, "iv_%d mismatch\n", len), exit(2);
memcpy(iv, test_iv, sizeof(test_iv));
CRYPTO_cts128_encrypt(test_input, ciphertext, len, &encks, iv,
(cbc128_f) AES_cbc_encrypt);
if (memcmp(ciphertext, vector, len))
fprintf(stderr, "output_%d mismatch\n", len), exit(3);
if (memcmp(iv, vector + len - tail, sizeof(iv)))
fprintf(stderr, "iv_%d mismatch\n", len), exit(3);
memcpy(iv, test_iv, sizeof(test_iv));
CRYPTO_cts128_decrypt(ciphertext, cleartext, len, &decks, iv,
(cbc128_f) AES_cbc_encrypt);
if (memcmp(cleartext, test_input, len))
fprintf(stderr, "input_%d mismatch\n", len), exit(4);
if (memcmp(iv, vector + len - tail, sizeof(iv)))
fprintf(stderr, "iv_%d mismatch\n", len), exit(4);
}
void test_nistvector(const unsigned char *vector, size_t len)
{
unsigned char iv[sizeof(test_iv)];
unsigned char cleartext[64], ciphertext[64], nistvector[64];
size_t tail;
printf("nistvector_%d\n", len);
fflush(stdout);
if ((tail = len % 16) == 0)
tail = 16;
len -= 16 + tail;
memcpy(nistvector, vector, len);
memcpy(nistvector + len, vector + len + 16, tail);
memcpy(nistvector + len + tail, vector + len, 16);
len += 16 + tail;
tail = 16;
memcpy(iv, test_iv, sizeof(test_iv));
CRYPTO_nistcts128_encrypt_block(test_input, ciphertext, len, &encks, iv,
(block128_f) AES_encrypt);
if (memcmp(ciphertext, nistvector, len))
fprintf(stderr, "output_%d mismatch\n", len), exit(1);
if (memcmp(iv, nistvector + len - tail, sizeof(iv)))
fprintf(stderr, "iv_%d mismatch\n", len), exit(1);
memcpy(iv, test_iv, sizeof(test_iv));
CRYPTO_nistcts128_decrypt_block(ciphertext, cleartext, len, &decks, iv,
(block128_f) AES_decrypt);
if (memcmp(cleartext, test_input, len))
fprintf(stderr, "input_%d mismatch\n", len), exit(2);
if (memcmp(iv, nistvector + len - tail, sizeof(iv)))
fprintf(stderr, "iv_%d mismatch\n", len), exit(2);
memcpy(iv, test_iv, sizeof(test_iv));
CRYPTO_nistcts128_encrypt(test_input, ciphertext, len, &encks, iv,
(cbc128_f) AES_cbc_encrypt);
if (memcmp(ciphertext, nistvector, len))
fprintf(stderr, "output_%d mismatch\n", len), exit(3);
if (memcmp(iv, nistvector + len - tail, sizeof(iv)))
fprintf(stderr, "iv_%d mismatch\n", len), exit(3);
memcpy(iv, test_iv, sizeof(test_iv));
CRYPTO_nistcts128_decrypt(ciphertext, cleartext, len, &decks, iv,
(cbc128_f) AES_cbc_encrypt);
if (memcmp(cleartext, test_input, len))
fprintf(stderr, "input_%d mismatch\n", len), exit(4);
if (memcmp(iv, nistvector + len - tail, sizeof(iv)))
fprintf(stderr, "iv_%d mismatch\n", len), exit(4);
}
int main()
{
AES_set_encrypt_key(test_key, 128, &encks);
AES_set_decrypt_key(test_key, 128, &decks);
test_vector(vector_17, sizeof(vector_17));
test_vector(vector_31, sizeof(vector_31));
test_vector(vector_32, sizeof(vector_32));
test_vector(vector_47, sizeof(vector_47));
test_vector(vector_48, sizeof(vector_48));
test_vector(vector_64, sizeof(vector_64));
test_nistvector(vector_17, sizeof(vector_17));
test_nistvector(vector_31, sizeof(vector_31));
test_nistvector(vector_32, sizeof(vector_32));
test_nistvector(vector_47, sizeof(vector_47));
test_nistvector(vector_48, sizeof(vector_48));
test_nistvector(vector_64, sizeof(vector_64));
return 0;
}
