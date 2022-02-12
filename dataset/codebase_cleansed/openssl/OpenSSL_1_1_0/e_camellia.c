static int cmll_t4_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
int ret, mode, bits;
EVP_CAMELLIA_KEY *dat =
(EVP_CAMELLIA_KEY *)EVP_CIPHER_CTX_get_cipher_data(ctx);
mode = EVP_CIPHER_CTX_mode(ctx);
bits = EVP_CIPHER_CTX_key_length(ctx) * 8;
cmll_t4_set_key(key, bits, &dat->ks);
if ((mode == EVP_CIPH_ECB_MODE || mode == EVP_CIPH_CBC_MODE)
&& !enc) {
ret = 0;
dat->block = (block128_f) cmll_t4_decrypt;
switch (bits) {
case 128:
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) cmll128_t4_cbc_decrypt : NULL;
break;
case 192:
case 256:
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) cmll256_t4_cbc_decrypt : NULL;
break;
default:
ret = -1;
}
} else {
ret = 0;
dat->block = (block128_f) cmll_t4_encrypt;
switch (bits) {
case 128:
if (mode == EVP_CIPH_CBC_MODE)
dat->stream.cbc = (cbc128_f) cmll128_t4_cbc_encrypt;
else if (mode == EVP_CIPH_CTR_MODE)
dat->stream.ctr = (ctr128_f) cmll128_t4_ctr32_encrypt;
else
dat->stream.cbc = NULL;
break;
case 192:
case 256:
if (mode == EVP_CIPH_CBC_MODE)
dat->stream.cbc = (cbc128_f) cmll256_t4_cbc_encrypt;
else if (mode == EVP_CIPH_CTR_MODE)
dat->stream.ctr = (ctr128_f) cmll256_t4_ctr32_encrypt;
else
dat->stream.cbc = NULL;
break;
default:
ret = -1;
}
}
if (ret < 0) {
EVPerr(EVP_F_CMLL_T4_INIT_KEY, EVP_R_CAMELLIA_KEY_SETUP_FAILED);
return 0;
}
return 1;
}
static int camellia_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
int ret, mode;
EVP_CAMELLIA_KEY *dat = EVP_C_DATA(EVP_CAMELLIA_KEY,ctx);
ret = Camellia_set_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8, &dat->ks);
if (ret < 0) {
EVPerr(EVP_F_CAMELLIA_INIT_KEY, EVP_R_CAMELLIA_KEY_SETUP_FAILED);
return 0;
}
mode = EVP_CIPHER_CTX_mode(ctx);
if ((mode == EVP_CIPH_ECB_MODE || mode == EVP_CIPH_CBC_MODE)
&& !enc) {
dat->block = (block128_f) Camellia_decrypt;
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) Camellia_cbc_encrypt : NULL;
} else {
dat->block = (block128_f) Camellia_encrypt;
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) Camellia_cbc_encrypt : NULL;
}
return 1;
}
static int camellia_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_CAMELLIA_KEY *dat = EVP_C_DATA(EVP_CAMELLIA_KEY,ctx);
if (dat->stream.cbc)
(*dat->stream.cbc) (in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx),
EVP_CIPHER_CTX_encrypting(ctx));
else if (EVP_CIPHER_CTX_encrypting(ctx))
CRYPTO_cbc128_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), dat->block);
else
CRYPTO_cbc128_decrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), dat->block);
return 1;
}
static int camellia_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
size_t bl = EVP_CIPHER_CTX_block_size(ctx);
size_t i;
EVP_CAMELLIA_KEY *dat = EVP_C_DATA(EVP_CAMELLIA_KEY,ctx);
if (len < bl)
return 1;
for (i = 0, len -= bl; i <= len; i += bl)
(*dat->block) (in + i, out + i, &dat->ks);
return 1;
}
static int camellia_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_CAMELLIA_KEY *dat = EVP_C_DATA(EVP_CAMELLIA_KEY,ctx);
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_ofb128_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num, dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
static int camellia_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_CAMELLIA_KEY *dat = EVP_C_DATA(EVP_CAMELLIA_KEY,ctx);
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num, EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
static int camellia_cfb8_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_CAMELLIA_KEY *dat = EVP_C_DATA(EVP_CAMELLIA_KEY,ctx);
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_8_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num, EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
static int camellia_cfb1_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_CAMELLIA_KEY *dat = EVP_C_DATA(EVP_CAMELLIA_KEY,ctx);
if (EVP_CIPHER_CTX_test_flags(ctx, EVP_CIPH_FLAG_LENGTH_BITS)) {
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_1_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num, EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
while (len >= MAXBITCHUNK) {
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_1_encrypt(in, out, MAXBITCHUNK * 8, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num, EVP_CIPHER_CTX_encrypting(ctx), dat->block);
len -= MAXBITCHUNK;
EVP_CIPHER_CTX_set_num(ctx, num);
}
if (len) {
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_1_encrypt(in, out, len * 8, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num, EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
}
return 1;
}
static int camellia_ctr_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
unsigned int num = EVP_CIPHER_CTX_num(ctx);
EVP_CAMELLIA_KEY *dat = EVP_C_DATA(EVP_CAMELLIA_KEY,ctx);
if (dat->stream.ctr)
CRYPTO_ctr128_encrypt_ctr32(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx),
EVP_CIPHER_CTX_buf_noconst(ctx), &num,
dat->stream.ctr);
else
CRYPTO_ctr128_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx),
EVP_CIPHER_CTX_buf_noconst(ctx), &num,
dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
