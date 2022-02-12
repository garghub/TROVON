void Camellia_ecb_encrypt(const unsigned char *in, unsigned char *out,
const CAMELLIA_KEY *key, const int enc)
{
if (CAMELLIA_ENCRYPT == enc)
Camellia_encrypt(in, out, key);
else
Camellia_decrypt(in, out, key);
}
