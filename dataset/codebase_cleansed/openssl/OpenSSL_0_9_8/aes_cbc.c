void AES_cbc_encrypt(const unsigned char *in, unsigned char *out,
const unsigned long length, const AES_KEY *key,
unsigned char *ivec, const int enc) {
unsigned long n;
unsigned long len = length;
unsigned char tmp[AES_BLOCK_SIZE];
const unsigned char *iv = ivec;
assert(in && out && key && ivec);
assert((AES_ENCRYPT == enc)||(AES_DECRYPT == enc));
if (AES_ENCRYPT == enc) {
while (len >= AES_BLOCK_SIZE) {
for(n=0; n < AES_BLOCK_SIZE; ++n)
out[n] = in[n] ^ iv[n];
AES_encrypt(out, out, key);
iv = out;
len -= AES_BLOCK_SIZE;
in += AES_BLOCK_SIZE;
out += AES_BLOCK_SIZE;
}
if (len) {
for(n=0; n < len; ++n)
out[n] = in[n] ^ iv[n];
for(n=len; n < AES_BLOCK_SIZE; ++n)
out[n] = iv[n];
AES_encrypt(out, out, key);
iv = out;
}
memcpy(ivec,iv,AES_BLOCK_SIZE);
} else if (in != out) {
while (len >= AES_BLOCK_SIZE) {
AES_decrypt(in, out, key);
for(n=0; n < AES_BLOCK_SIZE; ++n)
out[n] ^= iv[n];
iv = in;
len -= AES_BLOCK_SIZE;
in += AES_BLOCK_SIZE;
out += AES_BLOCK_SIZE;
}
if (len) {
AES_decrypt(in,tmp,key);
for(n=0; n < len; ++n)
out[n] = tmp[n] ^ iv[n];
iv = in;
}
memcpy(ivec,iv,AES_BLOCK_SIZE);
} else {
while (len >= AES_BLOCK_SIZE) {
memcpy(tmp, in, AES_BLOCK_SIZE);
AES_decrypt(in, out, key);
for(n=0; n < AES_BLOCK_SIZE; ++n)
out[n] ^= ivec[n];
memcpy(ivec, tmp, AES_BLOCK_SIZE);
len -= AES_BLOCK_SIZE;
in += AES_BLOCK_SIZE;
out += AES_BLOCK_SIZE;
}
if (len) {
memcpy(tmp, in, AES_BLOCK_SIZE);
AES_decrypt(tmp, out, key);
for(n=0; n < len; ++n)
out[n] ^= ivec[n];
for(n=len; n < AES_BLOCK_SIZE; ++n)
out[n] = tmp[n];
memcpy(ivec, tmp, AES_BLOCK_SIZE);
}
}
}
