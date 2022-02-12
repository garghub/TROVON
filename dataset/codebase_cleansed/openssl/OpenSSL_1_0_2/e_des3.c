static int des_ede_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
BLOCK_CIPHER_ecb_loop()
DES_ecb3_encrypt((const_DES_cblock *)(in + i),
(DES_cblock *)(out + i),
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3, ctx->encrypt);
return 1;
}
static int des_ede_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
while (inl >= EVP_MAXCHUNK) {
DES_ede3_ofb64_encrypt(in, out, (long)EVP_MAXCHUNK,
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3, (DES_cblock *)ctx->iv,
&ctx->num);
inl -= EVP_MAXCHUNK;
in += EVP_MAXCHUNK;
out += EVP_MAXCHUNK;
}
if (inl)
DES_ede3_ofb64_encrypt(in, out, (long)inl,
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3, (DES_cblock *)ctx->iv,
&ctx->num);
return 1;
}
static int des_ede_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
DES_EDE_KEY *dat = data(ctx);
# ifdef KSSL_DEBUG
{
int i;
fprintf(stderr, "des_ede_cbc_cipher(ctx=%p, buflen=%d)\n", ctx,
ctx->buf_len);
fprintf(stderr, "\t iv= ");
for (i = 0; i < 8; i++)
fprintf(stderr, "%02X", ctx->iv[i]);
fprintf(stderr, "\n");
}
# endif
if (dat->stream.cbc) {
(*dat->stream.cbc) (in, out, inl, &dat->ks, ctx->iv);
return 1;
}
while (inl >= EVP_MAXCHUNK) {
DES_ede3_cbc_encrypt(in, out, (long)EVP_MAXCHUNK,
&dat->ks1, &dat->ks2, &dat->ks3,
(DES_cblock *)ctx->iv, ctx->encrypt);
inl -= EVP_MAXCHUNK;
in += EVP_MAXCHUNK;
out += EVP_MAXCHUNK;
}
if (inl)
DES_ede3_cbc_encrypt(in, out, (long)inl,
&dat->ks1, &dat->ks2, &dat->ks3,
(DES_cblock *)ctx->iv, ctx->encrypt);
return 1;
}
static int des_ede_cfb64_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
while (inl >= EVP_MAXCHUNK) {
DES_ede3_cfb64_encrypt(in, out, (long)EVP_MAXCHUNK,
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3, (DES_cblock *)ctx->iv,
&ctx->num, ctx->encrypt);
inl -= EVP_MAXCHUNK;
in += EVP_MAXCHUNK;
out += EVP_MAXCHUNK;
}
if (inl)
DES_ede3_cfb64_encrypt(in, out, (long)inl,
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3, (DES_cblock *)ctx->iv,
&ctx->num, ctx->encrypt);
return 1;
}
static int des_ede3_cfb1_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
size_t n;
unsigned char c[1], d[1];
for (n = 0; n < inl; ++n) {
c[0] = (in[n / 8] & (1 << (7 - n % 8))) ? 0x80 : 0;
DES_ede3_cfb_encrypt(c, d, 1, 1,
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3, (DES_cblock *)ctx->iv,
ctx->encrypt);
out[n / 8] = (out[n / 8] & ~(0x80 >> (unsigned int)(n % 8)))
| ((d[0] & 0x80) >> (unsigned int)(n % 8));
}
return 1;
}
static int des_ede3_cfb8_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
while (inl >= EVP_MAXCHUNK) {
DES_ede3_cfb_encrypt(in, out, 8, (long)EVP_MAXCHUNK,
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3, (DES_cblock *)ctx->iv,
ctx->encrypt);
inl -= EVP_MAXCHUNK;
in += EVP_MAXCHUNK;
out += EVP_MAXCHUNK;
}
if (inl)
DES_ede3_cfb_encrypt(in, out, 8, (long)inl,
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3, (DES_cblock *)ctx->iv,
ctx->encrypt);
return 1;
}
static int des_ede_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
DES_cblock *deskey = (DES_cblock *)key;
DES_EDE_KEY *dat = data(ctx);
dat->stream.cbc = NULL;
# if defined(SPARC_DES_CAPABLE)
if (SPARC_DES_CAPABLE) {
int mode = ctx->cipher->flags & EVP_CIPH_MODE;
if (mode == EVP_CIPH_CBC_MODE) {
des_t4_key_expand(&deskey[0], &dat->ks1);
des_t4_key_expand(&deskey[1], &dat->ks2);
memcpy(&dat->ks3, &dat->ks1, sizeof(dat->ks1));
dat->stream.cbc = enc ? des_t4_ede3_cbc_encrypt :
des_t4_ede3_cbc_decrypt;
return 1;
}
}
# endif
# ifdef EVP_CHECK_DES_KEY
if (DES_set_key_checked(&deskey[0], &dat->ks1)
! !DES_set_key_checked(&deskey[1], &dat->ks2))
return 0;
# else
DES_set_key_unchecked(&deskey[0], &dat->ks1);
DES_set_key_unchecked(&deskey[1], &dat->ks2);
# endif
memcpy(&dat->ks3, &dat->ks1, sizeof(dat->ks1));
return 1;
}
static int des_ede3_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
DES_cblock *deskey = (DES_cblock *)key;
DES_EDE_KEY *dat = data(ctx);
# ifdef KSSL_DEBUG
{
int i;
fprintf(stderr, "des_ede3_init_key(ctx=%p)\n", ctx);
fprintf(stderr, "\tKEY= ");
for (i = 0; i < 24; i++)
fprintf(stderr, "%02X", key[i]);
fprintf(stderr, "\n");
if (iv) {
fprintf(stderr, "\t IV= ");
for (i = 0; i < 8; i++)
fprintf(stderr, "%02X", iv[i]);
fprintf(stderr, "\n");
}
}
# endif
dat->stream.cbc = NULL;
# if defined(SPARC_DES_CAPABLE)
if (SPARC_DES_CAPABLE) {
int mode = ctx->cipher->flags & EVP_CIPH_MODE;
if (mode == EVP_CIPH_CBC_MODE) {
des_t4_key_expand(&deskey[0], &dat->ks1);
des_t4_key_expand(&deskey[1], &dat->ks2);
des_t4_key_expand(&deskey[2], &dat->ks3);
dat->stream.cbc = enc ? des_t4_ede3_cbc_encrypt :
des_t4_ede3_cbc_decrypt;
return 1;
}
}
# endif
# ifdef EVP_CHECK_DES_KEY
if (DES_set_key_checked(&deskey[0], &dat->ks1)
|| DES_set_key_checked(&deskey[1], &dat->ks2)
|| DES_set_key_checked(&deskey[2], &dat->ks3))
return 0;
# else
DES_set_key_unchecked(&deskey[0], &dat->ks1);
DES_set_key_unchecked(&deskey[1], &dat->ks2);
DES_set_key_unchecked(&deskey[2], &dat->ks3);
# endif
return 1;
}
static int des3_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
DES_cblock *deskey = ptr;
switch (type) {
case EVP_CTRL_RAND_KEY:
if (RAND_bytes(ptr, c->key_len) <= 0)
return 0;
DES_set_odd_parity(deskey);
if (c->key_len >= 16)
DES_set_odd_parity(deskey + 1);
if (c->key_len >= 24)
DES_set_odd_parity(deskey + 2);
return 1;
default:
return -1;
}
}
const EVP_CIPHER *EVP_des_ede(void)
{
return &des_ede_ecb;
}
const EVP_CIPHER *EVP_des_ede3(void)
{
return &des_ede3_ecb;
}
static int des_ede3_unwrap(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
unsigned char icv[8], iv[8], sha1tmp[SHA_DIGEST_LENGTH];
int rv = -1;
if (inl < 24)
return -1;
if (!out)
return inl - 16;
memcpy(ctx->iv, wrap_iv, 8);
des_ede_cbc_cipher(ctx, icv, in, 8);
if (out == in) {
memmove(out, out + 8, inl - 8);
in -= 8;
}
des_ede_cbc_cipher(ctx, out, in + 8, inl - 16);
des_ede_cbc_cipher(ctx, iv, in + inl - 8, 8);
BUF_reverse(icv, NULL, 8);
BUF_reverse(out, NULL, inl - 16);
BUF_reverse(ctx->iv, iv, 8);
des_ede_cbc_cipher(ctx, out, out, inl - 16);
des_ede_cbc_cipher(ctx, icv, icv, 8);
SHA1(out, inl - 16, sha1tmp);
if (!CRYPTO_memcmp(sha1tmp, icv, 8))
rv = inl - 16;
OPENSSL_cleanse(icv, 8);
OPENSSL_cleanse(sha1tmp, SHA_DIGEST_LENGTH);
OPENSSL_cleanse(iv, 8);
OPENSSL_cleanse(ctx->iv, 8);
if (rv == -1)
OPENSSL_cleanse(out, inl - 16);
return rv;
}
static int des_ede3_wrap(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
unsigned char sha1tmp[SHA_DIGEST_LENGTH];
if (!out)
return inl + 16;
memmove(out + 8, in, inl);
SHA1(in, inl, sha1tmp);
memcpy(out + inl + 8, sha1tmp, 8);
OPENSSL_cleanse(sha1tmp, SHA_DIGEST_LENGTH);
RAND_bytes(ctx->iv, 8);
memcpy(out, ctx->iv, 8);
des_ede_cbc_cipher(ctx, out + 8, out + 8, inl + 8);
BUF_reverse(out, NULL, inl + 16);
memcpy(ctx->iv, wrap_iv, 8);
des_ede_cbc_cipher(ctx, out, out, inl + 16);
return inl + 16;
}
static int des_ede3_wrap_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
if (inl >= EVP_MAXCHUNK || inl % 8)
return -1;
if (ctx->encrypt)
return des_ede3_wrap(ctx, out, in, inl);
else
return des_ede3_unwrap(ctx, out, in, inl);
}
const EVP_CIPHER *EVP_des_ede3_wrap(void)
{
return &des3_wrap;
}
