void AES_cbc_encrypt(const unsigned char *in, unsigned char *out,
const unsigned long length, const AES_KEY *key,
unsigned char *ivec, const int enc) {
unsigned long n;
unsigned long len = length;
unsigned char tmp[AES_BLOCK_SIZE];
assert(in && out && key && ivec);
assert((AES_ENCRYPT == enc)||(AES_DECRYPT == enc));
if (AES_ENCRYPT == enc) {
while (len >= AES_BLOCK_SIZE) {
for(n=0; n < sizeof tmp; ++n)
tmp[n] = in[n] ^ ivec[n];
AES_encrypt(tmp, out, key);
memcpy(ivec, out, AES_BLOCK_SIZE);
len -= AES_BLOCK_SIZE;
in += AES_BLOCK_SIZE;
out += AES_BLOCK_SIZE;
}
if (len) {
for(n=0; n < len; ++n)
tmp[n] = in[n] ^ ivec[n];
for(n=len; n < AES_BLOCK_SIZE; ++n)
tmp[n] = ivec[n];
AES_encrypt(tmp, tmp, key);
memcpy(out, tmp, len);
memcpy(ivec, tmp, sizeof tmp);
}
} else {
while (len >= AES_BLOCK_SIZE) {
memcpy(tmp, in, sizeof tmp);
AES_decrypt(in, out, key);
for(n=0; n < AES_BLOCK_SIZE; ++n)
out[n] ^= ivec[n];
memcpy(ivec, tmp, AES_BLOCK_SIZE);
len -= AES_BLOCK_SIZE;
in += AES_BLOCK_SIZE;
out += AES_BLOCK_SIZE;
}
if (len) {
memcpy(tmp, in, sizeof tmp);
AES_decrypt(tmp, tmp, key);
for(n=0; n < len; ++n)
out[n] ^= ivec[n];
memcpy(ivec, tmp, sizeof tmp);
}
}
}
