static int aesni_cbc_hmac_sha1_init_key(EVP_CIPHER_CTX *ctx,
const unsigned char *inkey,
const unsigned char *iv, int enc)
{
EVP_AES_HMAC_SHA1 *key = data(ctx);
int ret;
if (enc)
ret=aesni_set_encrypt_key(inkey,ctx->key_len*8,&key->ks);
else
ret=aesni_set_decrypt_key(inkey,ctx->key_len*8,&key->ks);
SHA1_Init(&key->head);
key->tail = key->head;
key->md = key->head;
key->payload_length = 0;
return ret<0?0:1;
}
static void sha1_update(SHA_CTX *c,const void *data,size_t len)
{ const unsigned char *ptr = data;
size_t res;
if ((res = c->num)) {
res = SHA_CBLOCK-res;
if (len<res) res=len;
SHA1_Update (c,ptr,res);
ptr += res;
len -= res;
}
res = len % SHA_CBLOCK;
len -= res;
if (len) {
sha1_block_data_order(c,ptr,len/SHA_CBLOCK);
ptr += len;
c->Nh += len>>29;
c->Nl += len<<=3;
if (c->Nl<(unsigned int)len) c->Nh++;
}
if (res)
SHA1_Update(c,ptr,res);
}
static int aesni_cbc_hmac_sha1_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_HMAC_SHA1 *key = data(ctx);
unsigned int l;
size_t plen = key->payload_length,
iv = 0,
sha_off = 0;
#if defined(STITCHED_CALL)
size_t aes_off = 0,
blocks;
sha_off = SHA_CBLOCK-key->md.num;
#endif
if (len%AES_BLOCK_SIZE) return 0;
if (ctx->encrypt) {
if (plen==0)
plen = len;
else if (len!=((plen+SHA_DIGEST_LENGTH+AES_BLOCK_SIZE)&-AES_BLOCK_SIZE))
return 0;
else if (key->aux.tls_ver >= TLS1_1_VERSION)
iv = AES_BLOCK_SIZE;
#if defined(STITCHED_CALL)
if (plen>(sha_off+iv) && (blocks=(plen-(sha_off+iv))/SHA_CBLOCK)) {
SHA1_Update(&key->md,in+iv,sha_off);
aesni_cbc_sha1_enc(in,out,blocks,&key->ks,
ctx->iv,&key->md,in+iv+sha_off);
blocks *= SHA_CBLOCK;
aes_off += blocks;
sha_off += blocks;
key->md.Nh += blocks>>29;
key->md.Nl += blocks<<=3;
if (key->md.Nl<(unsigned int)blocks) key->md.Nh++;
} else {
sha_off = 0;
}
#endif
sha_off += iv;
SHA1_Update(&key->md,in+sha_off,plen-sha_off);
if (plen!=len) {
if (in!=out)
memcpy(out+aes_off,in+aes_off,plen-aes_off);
SHA1_Final(out+plen,&key->md);
key->md = key->tail;
SHA1_Update(&key->md,out+plen,SHA_DIGEST_LENGTH);
SHA1_Final(out+plen,&key->md);
plen += SHA_DIGEST_LENGTH;
for (l=len-plen-1;plen<len;plen++) out[plen]=l;
aesni_cbc_encrypt(out+aes_off,out+aes_off,len-aes_off,
&key->ks,ctx->iv,1);
} else {
aesni_cbc_encrypt(in+aes_off,out+aes_off,len-aes_off,
&key->ks,ctx->iv,1);
}
} else {
unsigned char mac[SHA_DIGEST_LENGTH];
aesni_cbc_encrypt(in,out,len,
&key->ks,ctx->iv,0);
if (plen) {
if (len<(size_t)(out[len-1]+1+SHA_DIGEST_LENGTH))
return 0;
len -= (out[len-1]+1+SHA_DIGEST_LENGTH);
if ((key->aux.tls_aad[plen-4]<<8|key->aux.tls_aad[plen-3])
>= TLS1_1_VERSION) {
len -= AES_BLOCK_SIZE;
iv = AES_BLOCK_SIZE;
}
key->aux.tls_aad[plen-2] = len>>8;
key->aux.tls_aad[plen-1] = len;
key->md = key->head;
SHA1_Update(&key->md,key->aux.tls_aad,plen);
SHA1_Update(&key->md,out+iv,len);
SHA1_Final(mac,&key->md);
key->md = key->tail;
SHA1_Update(&key->md,mac,SHA_DIGEST_LENGTH);
SHA1_Final(mac,&key->md);
if (memcmp(out+iv+len,mac,SHA_DIGEST_LENGTH))
return 0;
} else {
SHA1_Update(&key->md,out,len);
}
}
key->payload_length = 0;
return 1;
}
static int aesni_cbc_hmac_sha1_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr)
{
EVP_AES_HMAC_SHA1 *key = data(ctx);
switch (type)
{
case EVP_CTRL_AEAD_SET_MAC_KEY:
{
unsigned int i;
unsigned char hmac_key[64];
memset (hmac_key,0,sizeof(hmac_key));
if (arg > (int)sizeof(hmac_key)) {
SHA1_Init(&key->head);
SHA1_Update(&key->head,ptr,arg);
SHA1_Final(hmac_key,&key->head);
} else {
memcpy(hmac_key,ptr,arg);
}
for (i=0;i<sizeof(hmac_key);i++)
hmac_key[i] ^= 0x36;
SHA1_Init(&key->head);
SHA1_Update(&key->head,hmac_key,sizeof(hmac_key));
for (i=0;i<sizeof(hmac_key);i++)
hmac_key[i] ^= 0x36^0x5c;
SHA1_Init(&key->tail);
SHA1_Update(&key->tail,hmac_key,sizeof(hmac_key));
return 1;
}
case EVP_CTRL_AEAD_TLS1_AAD:
{
unsigned char *p=ptr;
unsigned int len=p[arg-2]<<8|p[arg-1];
if (ctx->encrypt)
{
key->payload_length = len;
if ((key->aux.tls_ver=p[arg-4]<<8|p[arg-3]) >= TLS1_1_VERSION) {
len -= AES_BLOCK_SIZE;
p[arg-2] = len>>8;
p[arg-1] = len;
}
key->md = key->head;
SHA1_Update(&key->md,p,arg);
return (int)(((len+SHA_DIGEST_LENGTH+AES_BLOCK_SIZE)&-AES_BLOCK_SIZE)
- len);
}
else
{
if (arg>13) arg = 13;
memcpy(key->aux.tls_aad,ptr,arg);
key->payload_length = arg;
return SHA_DIGEST_LENGTH;
}
}
default:
return -1;
}
}
const EVP_CIPHER *EVP_aes_128_cbc_hmac_sha1(void)
{
return(OPENSSL_ia32cap_P[1]&AESNI_CAPABLE?
&aesni_128_cbc_hmac_sha1_cipher:NULL);
}
const EVP_CIPHER *EVP_aes_256_cbc_hmac_sha1(void)
{
return(OPENSSL_ia32cap_P[1]&AESNI_CAPABLE?
&aesni_256_cbc_hmac_sha1_cipher:NULL);
}
const EVP_CIPHER *EVP_aes_128_cbc_hmac_sha1(void)
{
return NULL;
}
const EVP_CIPHER *EVP_aes_256_cbc_hmac_sha1(void)
{
return NULL;
}
