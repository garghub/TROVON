int AES_wrap_key(AES_KEY *key, const unsigned char *iv,
unsigned char *out,
const unsigned char *in, unsigned int inlen)
{
return CRYPTO_128_wrap(key, iv, out, in, inlen, (block128_f) AES_encrypt);
}
int AES_unwrap_key(AES_KEY *key, const unsigned char *iv,
unsigned char *out,
const unsigned char *in, unsigned int inlen)
{
return CRYPTO_128_unwrap(key, iv, out, in, inlen,
(block128_f) AES_decrypt);
}
