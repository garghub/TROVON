void Camellia_cfb128_encrypt(const unsigned char *in, unsigned char *out,
size_t length, const CAMELLIA_KEY *key,
unsigned char *ivec, int *num, const int enc)
{
CRYPTO_cfb128_encrypt(in, out, length, key, ivec, num, enc,
(block128_f) Camellia_encrypt);
}
void Camellia_cfb1_encrypt(const unsigned char *in, unsigned char *out,
size_t length, const CAMELLIA_KEY *key,
unsigned char *ivec, int *num, const int enc)
{
CRYPTO_cfb128_1_encrypt(in, out, length, key, ivec, num, enc,
(block128_f) Camellia_encrypt);
}
void Camellia_cfb8_encrypt(const unsigned char *in, unsigned char *out,
size_t length, const CAMELLIA_KEY *key,
unsigned char *ivec, int *num, const int enc)
{
CRYPTO_cfb128_8_encrypt(in, out, length, key, ivec, num, enc,
(block128_f) Camellia_encrypt);
}
