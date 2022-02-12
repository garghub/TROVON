static int rc4_hmac_md5_init_key(EVP_CIPHER_CTX *ctx,
const unsigned char *inkey,
const unsigned char *iv, int enc)
{
EVP_RC4_HMAC_MD5 *key = data(ctx);
RC4_set_key(&key->ks,EVP_CIPHER_CTX_key_length(ctx),
inkey);
MD5_Init(&key->head);
key->tail = key->head;
key->md = key->head;
key->payload_length = 0;
return 1;
}
static int rc4_hmac_md5_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_RC4_HMAC_MD5 *key = data(ctx);
#if defined(STITCHED_CALL)
size_t rc4_off = 32-1-(key->ks.x&(32-1)),
md5_off = MD5_CBLOCK-key->md.num,
blocks;
unsigned int l;
#endif
size_t plen = key->payload_length;
if (plen && len!=(plen+MD5_DIGEST_LENGTH)) return 0;
if (ctx->encrypt) {
if (plen==0) plen = len;
#if defined(STITCHED_CALL)
if (rc4_off>md5_off) md5_off+=MD5_CBLOCK;
if (plen>md5_off && (blocks=(plen-md5_off)/MD5_CBLOCK)) {
MD5_Update(&key->md,in,md5_off);
RC4(&key->ks,rc4_off,in,out);
rc4_md5_enc(&key->ks,in+rc4_off,out+rc4_off,
&key->md,in+md5_off,blocks);
blocks *= MD5_CBLOCK;
rc4_off += blocks;
md5_off += blocks;
key->md.Nh += blocks>>29;
key->md.Nl += blocks<<=3;
if (key->md.Nl<(unsigned int)blocks) key->md.Nh++;
} else {
rc4_off = 0;
md5_off = 0;
}
#endif
MD5_Update(&key->md,in+md5_off,plen-md5_off);
if (plen!=len) {
if (in!=out)
memcpy(out+rc4_off,in+rc4_off,plen-rc4_off);
MD5_Final(out+plen,&key->md);
key->md = key->tail;
MD5_Update(&key->md,out+plen,MD5_DIGEST_LENGTH);
MD5_Final(out+plen,&key->md);
RC4(&key->ks,len-rc4_off,out+rc4_off,out+rc4_off);
} else {
RC4(&key->ks,len-rc4_off,in+rc4_off,out+rc4_off);
}
} else {
unsigned char mac[MD5_DIGEST_LENGTH];
#if defined(STITCHED_CALL)
if (md5_off>rc4_off) rc4_off += 2*MD5_CBLOCK;
else rc4_off += MD5_CBLOCK;
if (len>rc4_off && (blocks=(len-rc4_off)/MD5_CBLOCK)) {
RC4(&key->ks,rc4_off,in,out);
MD5_Update(&key->md,out,md5_off);
rc4_md5_enc(&key->ks,in+rc4_off,out+rc4_off,
&key->md,out+md5_off,blocks);
blocks *= MD5_CBLOCK;
rc4_off += blocks;
md5_off += blocks;
l = (key->md.Nl+(blocks<<3))&0xffffffffU;
if (l<key->md.Nl) key->md.Nh++;
key->md.Nl = l;
key->md.Nh += blocks>>29;
} else {
md5_off=0;
rc4_off=0;
}
#endif
RC4(&key->ks,len-rc4_off,in+rc4_off,out+rc4_off);
if (plen) {
MD5_Update(&key->md,out+md5_off,plen-md5_off);
MD5_Final(mac,&key->md);
key->md = key->tail;
MD5_Update(&key->md,mac,MD5_DIGEST_LENGTH);
MD5_Final(mac,&key->md);
if (memcmp(out+plen,mac,MD5_DIGEST_LENGTH))
return 0;
} else {
MD5_Update(&key->md,out+md5_off,len-md5_off);
}
}
key->payload_length = 0;
return 1;
}
static int rc4_hmac_md5_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr)
{
EVP_RC4_HMAC_MD5 *key = data(ctx);
switch (type)
{
case EVP_CTRL_AEAD_SET_MAC_KEY:
{
unsigned int i;
unsigned char hmac_key[64];
memset (hmac_key,0,sizeof(hmac_key));
if (arg > (int)sizeof(hmac_key)) {
MD5_Init(&key->head);
MD5_Update(&key->head,ptr,arg);
MD5_Final(hmac_key,&key->head);
} else {
memcpy(hmac_key,ptr,arg);
}
for (i=0;i<sizeof(hmac_key);i++)
hmac_key[i] ^= 0x36;
MD5_Init(&key->head);
MD5_Update(&key->head,hmac_key,sizeof(hmac_key));
for (i=0;i<sizeof(hmac_key);i++)
hmac_key[i] ^= 0x36^0x5c;
MD5_Init(&key->tail);
MD5_Update(&key->tail,hmac_key,sizeof(hmac_key));
return 1;
}
case EVP_CTRL_AEAD_TLS1_AAD:
{
unsigned char *p=ptr;
unsigned int len=p[arg-2]<<8|p[arg-1];
if (!ctx->encrypt)
{
len -= MD5_DIGEST_LENGTH;
p[arg-2] = len>>8;
p[arg-1] = len;
}
key->payload_length=len;
key->md = key->head;
MD5_Update(&key->md,p,arg);
return MD5_DIGEST_LENGTH;
}
default:
return -1;
}
}
const EVP_CIPHER *EVP_rc4_hmac_md5(void)
{
return(&r4_hmac_md5_cipher);
}
