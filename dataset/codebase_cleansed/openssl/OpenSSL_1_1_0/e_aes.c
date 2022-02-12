static int aesni_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
int ret, mode;
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
mode = EVP_CIPHER_CTX_mode(ctx);
if ((mode == EVP_CIPH_ECB_MODE || mode == EVP_CIPH_CBC_MODE)
&& !enc) {
ret = aesni_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) aesni_decrypt;
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) aesni_cbc_encrypt : NULL;
} else {
ret = aesni_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) aesni_encrypt;
if (mode == EVP_CIPH_CBC_MODE)
dat->stream.cbc = (cbc128_f) aesni_cbc_encrypt;
else if (mode == EVP_CIPH_CTR_MODE)
dat->stream.ctr = (ctr128_f) aesni_ctr32_encrypt_blocks;
else
dat->stream.cbc = NULL;
}
if (ret < 0) {
EVPerr(EVP_F_AESNI_INIT_KEY, EVP_R_AES_KEY_SETUP_FAILED);
return 0;
}
return 1;
}
static int aesni_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
aesni_cbc_encrypt(in, out, len, &EVP_C_DATA(EVP_AES_KEY,ctx)->ks.ks,
EVP_CIPHER_CTX_iv_noconst(ctx),
EVP_CIPHER_CTX_encrypting(ctx));
return 1;
}
static int aesni_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
size_t bl = EVP_CIPHER_CTX_block_size(ctx);
if (len < bl)
return 1;
aesni_ecb_encrypt(in, out, len, &EVP_C_DATA(EVP_AES_KEY,ctx)->ks.ks,
EVP_CIPHER_CTX_encrypting(ctx));
return 1;
}
static int aesni_gcm_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_GCM_CTX *gctx = EVP_C_DATA(EVP_AES_GCM_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
aesni_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&gctx->ks.ks);
CRYPTO_gcm128_init(&gctx->gcm, &gctx->ks, (block128_f) aesni_encrypt);
gctx->ctr = (ctr128_f) aesni_ctr32_encrypt_blocks;
if (iv == NULL && gctx->iv_set)
iv = gctx->iv;
if (iv) {
CRYPTO_gcm128_setiv(&gctx->gcm, iv, gctx->ivlen);
gctx->iv_set = 1;
}
gctx->key_set = 1;
} else {
if (gctx->key_set)
CRYPTO_gcm128_setiv(&gctx->gcm, iv, gctx->ivlen);
else
memcpy(gctx->iv, iv, gctx->ivlen);
gctx->iv_set = 1;
gctx->iv_gen = 0;
}
return 1;
}
static int aesni_xts_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_XTS_CTX *xctx = EVP_C_DATA(EVP_AES_XTS_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
if (enc) {
aesni_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) aesni_encrypt;
xctx->stream = aesni_xts_encrypt;
} else {
aesni_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) aesni_decrypt;
xctx->stream = aesni_xts_decrypt;
}
aesni_set_encrypt_key(key + EVP_CIPHER_CTX_key_length(ctx) / 2,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks2.ks);
xctx->xts.block2 = (block128_f) aesni_encrypt;
xctx->xts.key1 = &xctx->ks1;
}
if (iv) {
xctx->xts.key2 = &xctx->ks2;
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), iv, 16);
}
return 1;
}
static int aesni_ccm_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_CCM_CTX *cctx = EVP_C_DATA(EVP_AES_CCM_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
aesni_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&cctx->ks.ks);
CRYPTO_ccm128_init(&cctx->ccm, cctx->M, cctx->L,
&cctx->ks, (block128_f) aesni_encrypt);
cctx->str = enc ? (ccm128_f) aesni_ccm64_encrypt_blocks :
(ccm128_f) aesni_ccm64_decrypt_blocks;
cctx->key_set = 1;
}
if (iv) {
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), iv, 15 - cctx->L);
cctx->iv_set = 1;
}
return 1;
}
static int aesni_ocb_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_OCB_CTX *octx = EVP_C_DATA(EVP_AES_OCB_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
do {
aesni_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksenc.ks);
aesni_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksdec.ks);
if (!CRYPTO_ocb128_init(&octx->ocb,
&octx->ksenc.ks, &octx->ksdec.ks,
(block128_f) aesni_encrypt,
(block128_f) aesni_decrypt,
enc ? aesni_ocb_encrypt
: aesni_ocb_decrypt))
return 0;
}
while (0);
if (iv == NULL && octx->iv_set)
iv = octx->iv;
if (iv) {
if (CRYPTO_ocb128_setiv(&octx->ocb, iv, octx->ivlen, octx->taglen)
!= 1)
return 0;
octx->iv_set = 1;
}
octx->key_set = 1;
} else {
if (octx->key_set)
CRYPTO_ocb128_setiv(&octx->ocb, iv, octx->ivlen, octx->taglen);
else
memcpy(octx->iv, iv, octx->ivlen);
octx->iv_set = 1;
}
return 1;
}
static int aes_t4_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
int ret, mode, bits;
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
mode = EVP_CIPHER_CTX_mode(ctx);
bits = EVP_CIPHER_CTX_key_length(ctx) * 8;
if ((mode == EVP_CIPH_ECB_MODE || mode == EVP_CIPH_CBC_MODE)
&& !enc) {
ret = 0;
aes_t4_set_decrypt_key(key, bits, &dat->ks.ks);
dat->block = (block128_f) aes_t4_decrypt;
switch (bits) {
case 128:
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) aes128_t4_cbc_decrypt : NULL;
break;
case 192:
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) aes192_t4_cbc_decrypt : NULL;
break;
case 256:
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) aes256_t4_cbc_decrypt : NULL;
break;
default:
ret = -1;
}
} else {
ret = 0;
aes_t4_set_encrypt_key(key, bits, &dat->ks.ks);
dat->block = (block128_f) aes_t4_encrypt;
switch (bits) {
case 128:
if (mode == EVP_CIPH_CBC_MODE)
dat->stream.cbc = (cbc128_f) aes128_t4_cbc_encrypt;
else if (mode == EVP_CIPH_CTR_MODE)
dat->stream.ctr = (ctr128_f) aes128_t4_ctr32_encrypt;
else
dat->stream.cbc = NULL;
break;
case 192:
if (mode == EVP_CIPH_CBC_MODE)
dat->stream.cbc = (cbc128_f) aes192_t4_cbc_encrypt;
else if (mode == EVP_CIPH_CTR_MODE)
dat->stream.ctr = (ctr128_f) aes192_t4_ctr32_encrypt;
else
dat->stream.cbc = NULL;
break;
case 256:
if (mode == EVP_CIPH_CBC_MODE)
dat->stream.cbc = (cbc128_f) aes256_t4_cbc_encrypt;
else if (mode == EVP_CIPH_CTR_MODE)
dat->stream.ctr = (ctr128_f) aes256_t4_ctr32_encrypt;
else
dat->stream.cbc = NULL;
break;
default:
ret = -1;
}
}
if (ret < 0) {
EVPerr(EVP_F_AES_T4_INIT_KEY, EVP_R_AES_KEY_SETUP_FAILED);
return 0;
}
return 1;
}
static int aes_t4_gcm_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_GCM_CTX *gctx = EVP_C_DATA(EVP_AES_GCM_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
int bits = EVP_CIPHER_CTX_key_length(ctx) * 8;
aes_t4_set_encrypt_key(key, bits, &gctx->ks.ks);
CRYPTO_gcm128_init(&gctx->gcm, &gctx->ks,
(block128_f) aes_t4_encrypt);
switch (bits) {
case 128:
gctx->ctr = (ctr128_f) aes128_t4_ctr32_encrypt;
break;
case 192:
gctx->ctr = (ctr128_f) aes192_t4_ctr32_encrypt;
break;
case 256:
gctx->ctr = (ctr128_f) aes256_t4_ctr32_encrypt;
break;
default:
return 0;
}
if (iv == NULL && gctx->iv_set)
iv = gctx->iv;
if (iv) {
CRYPTO_gcm128_setiv(&gctx->gcm, iv, gctx->ivlen);
gctx->iv_set = 1;
}
gctx->key_set = 1;
} else {
if (gctx->key_set)
CRYPTO_gcm128_setiv(&gctx->gcm, iv, gctx->ivlen);
else
memcpy(gctx->iv, iv, gctx->ivlen);
gctx->iv_set = 1;
gctx->iv_gen = 0;
}
return 1;
}
static int aes_t4_xts_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_XTS_CTX *xctx = EVP_C_DATA(EVP_AES_XTS_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
int bits = EVP_CIPHER_CTX_key_length(ctx) * 4;
xctx->stream = NULL;
if (enc) {
aes_t4_set_encrypt_key(key, bits, &xctx->ks1.ks);
xctx->xts.block1 = (block128_f) aes_t4_encrypt;
switch (bits) {
case 128:
xctx->stream = aes128_t4_xts_encrypt;
break;
case 256:
xctx->stream = aes256_t4_xts_encrypt;
break;
default:
return 0;
}
} else {
aes_t4_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) aes_t4_decrypt;
switch (bits) {
case 128:
xctx->stream = aes128_t4_xts_decrypt;
break;
case 256:
xctx->stream = aes256_t4_xts_decrypt;
break;
default:
return 0;
}
}
aes_t4_set_encrypt_key(key + EVP_CIPHER_CTX_key_length(ctx) / 2,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks2.ks);
xctx->xts.block2 = (block128_f) aes_t4_encrypt;
xctx->xts.key1 = &xctx->ks1;
}
if (iv) {
xctx->xts.key2 = &xctx->ks2;
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), iv, 16);
}
return 1;
}
static int aes_t4_ccm_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_CCM_CTX *cctx = EVP_C_DATA(EVP_AES_CCM_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
int bits = EVP_CIPHER_CTX_key_length(ctx) * 8;
aes_t4_set_encrypt_key(key, bits, &cctx->ks.ks);
CRYPTO_ccm128_init(&cctx->ccm, cctx->M, cctx->L,
&cctx->ks, (block128_f) aes_t4_encrypt);
cctx->str = NULL;
cctx->key_set = 1;
}
if (iv) {
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), iv, 15 - cctx->L);
cctx->iv_set = 1;
}
return 1;
}
static int aes_t4_ocb_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_OCB_CTX *octx = EVP_C_DATA(EVP_AES_OCB_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
do {
aes_t4_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksenc.ks);
aes_t4_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksdec.ks);
if (!CRYPTO_ocb128_init(&octx->ocb,
&octx->ksenc.ks, &octx->ksdec.ks,
(block128_f) aes_t4_encrypt,
(block128_f) aes_t4_decrypt,
NULL))
return 0;
}
while (0);
if (iv == NULL && octx->iv_set)
iv = octx->iv;
if (iv) {
if (CRYPTO_ocb128_setiv(&octx->ocb, iv, octx->ivlen, octx->taglen)
!= 1)
return 0;
octx->iv_set = 1;
}
octx->key_set = 1;
} else {
if (octx->key_set)
CRYPTO_ocb128_setiv(&octx->ocb, iv, octx->ivlen, octx->taglen);
else
memcpy(octx->iv, iv, octx->ivlen);
octx->iv_set = 1;
}
return 1;
}
static int aes_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
int ret, mode;
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
mode = EVP_CIPHER_CTX_mode(ctx);
if ((mode == EVP_CIPH_ECB_MODE || mode == EVP_CIPH_CBC_MODE)
&& !enc) {
#ifdef HWAES_CAPABLE
if (HWAES_CAPABLE) {
ret = HWAES_set_decrypt_key(key,
EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) HWAES_decrypt;
dat->stream.cbc = NULL;
# ifdef HWAES_cbc_encrypt
if (mode == EVP_CIPH_CBC_MODE)
dat->stream.cbc = (cbc128_f) HWAES_cbc_encrypt;
# endif
} else
#endif
#ifdef BSAES_CAPABLE
if (BSAES_CAPABLE && mode == EVP_CIPH_CBC_MODE) {
ret = AES_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) AES_decrypt;
dat->stream.cbc = (cbc128_f) bsaes_cbc_encrypt;
} else
#endif
#ifdef VPAES_CAPABLE
if (VPAES_CAPABLE) {
ret = vpaes_set_decrypt_key(key,
EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) vpaes_decrypt;
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) vpaes_cbc_encrypt : NULL;
} else
#endif
{
ret = AES_set_decrypt_key(key,
EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) AES_decrypt;
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) AES_cbc_encrypt : NULL;
}
} else
#ifdef HWAES_CAPABLE
if (HWAES_CAPABLE) {
ret = HWAES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) HWAES_encrypt;
dat->stream.cbc = NULL;
# ifdef HWAES_cbc_encrypt
if (mode == EVP_CIPH_CBC_MODE)
dat->stream.cbc = (cbc128_f) HWAES_cbc_encrypt;
else
# endif
# ifdef HWAES_ctr32_encrypt_blocks
if (mode == EVP_CIPH_CTR_MODE)
dat->stream.ctr = (ctr128_f) HWAES_ctr32_encrypt_blocks;
else
# endif
(void)0;
} else
#endif
#ifdef BSAES_CAPABLE
if (BSAES_CAPABLE && mode == EVP_CIPH_CTR_MODE) {
ret = AES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) AES_encrypt;
dat->stream.ctr = (ctr128_f) bsaes_ctr32_encrypt_blocks;
} else
#endif
#ifdef VPAES_CAPABLE
if (VPAES_CAPABLE) {
ret = vpaes_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) vpaes_encrypt;
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) vpaes_cbc_encrypt : NULL;
} else
#endif
{
ret = AES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&dat->ks.ks);
dat->block = (block128_f) AES_encrypt;
dat->stream.cbc = mode == EVP_CIPH_CBC_MODE ?
(cbc128_f) AES_cbc_encrypt : NULL;
#ifdef AES_CTR_ASM
if (mode == EVP_CIPH_CTR_MODE)
dat->stream.ctr = (ctr128_f) AES_ctr32_encrypt;
#endif
}
if (ret < 0) {
EVPerr(EVP_F_AES_INIT_KEY, EVP_R_AES_KEY_SETUP_FAILED);
return 0;
}
return 1;
}
static int aes_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
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
static int aes_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
size_t bl = EVP_CIPHER_CTX_block_size(ctx);
size_t i;
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
if (len < bl)
return 1;
for (i = 0, len -= bl; i <= len; i += bl)
(*dat->block) (in + i, out + i, &dat->ks);
return 1;
}
static int aes_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_ofb128_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num, dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
static int aes_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num,
EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
static int aes_cfb8_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_8_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num,
EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
static int aes_cfb1_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
if (EVP_CIPHER_CTX_test_flags(ctx, EVP_CIPH_FLAG_LENGTH_BITS)) {
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_1_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num,
EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
while (len >= MAXBITCHUNK) {
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_1_encrypt(in, out, MAXBITCHUNK * 8, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num,
EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
len -= MAXBITCHUNK;
}
if (len) {
int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_cfb128_1_encrypt(in, out, len * 8, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx), &num,
EVP_CIPHER_CTX_encrypting(ctx), dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
}
return 1;
}
static int aes_ctr_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
unsigned int num = EVP_CIPHER_CTX_num(ctx);
EVP_AES_KEY *dat = EVP_C_DATA(EVP_AES_KEY,ctx);
if (dat->stream.ctr)
CRYPTO_ctr128_encrypt_ctr32(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx),
EVP_CIPHER_CTX_buf_noconst(ctx),
&num, dat->stream.ctr);
else
CRYPTO_ctr128_encrypt(in, out, len, &dat->ks,
EVP_CIPHER_CTX_iv_noconst(ctx),
EVP_CIPHER_CTX_buf_noconst(ctx), &num,
dat->block);
EVP_CIPHER_CTX_set_num(ctx, num);
return 1;
}
static int aes_gcm_cleanup(EVP_CIPHER_CTX *c)
{
EVP_AES_GCM_CTX *gctx = EVP_C_DATA(EVP_AES_GCM_CTX,c);
OPENSSL_cleanse(&gctx->gcm, sizeof(gctx->gcm));
if (gctx->iv != EVP_CIPHER_CTX_iv_noconst(c))
OPENSSL_free(gctx->iv);
return 1;
}
static void ctr64_inc(unsigned char *counter)
{
int n = 8;
unsigned char c;
do {
--n;
c = counter[n];
++c;
counter[n] = c;
if (c)
return;
} while (n);
}
static int aes_gcm_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
EVP_AES_GCM_CTX *gctx = EVP_C_DATA(EVP_AES_GCM_CTX,c);
switch (type) {
case EVP_CTRL_INIT:
gctx->key_set = 0;
gctx->iv_set = 0;
gctx->ivlen = EVP_CIPHER_CTX_iv_length(c);
gctx->iv = EVP_CIPHER_CTX_iv_noconst(c);
gctx->taglen = -1;
gctx->iv_gen = 0;
gctx->tls_aad_len = -1;
return 1;
case EVP_CTRL_AEAD_SET_IVLEN:
if (arg <= 0)
return 0;
if ((arg > EVP_MAX_IV_LENGTH) && (arg > gctx->ivlen)) {
if (gctx->iv != EVP_CIPHER_CTX_iv_noconst(c))
OPENSSL_free(gctx->iv);
gctx->iv = OPENSSL_malloc(arg);
if (gctx->iv == NULL)
return 0;
}
gctx->ivlen = arg;
return 1;
case EVP_CTRL_AEAD_SET_TAG:
if (arg <= 0 || arg > 16 || EVP_CIPHER_CTX_encrypting(c))
return 0;
memcpy(EVP_CIPHER_CTX_buf_noconst(c), ptr, arg);
gctx->taglen = arg;
return 1;
case EVP_CTRL_AEAD_GET_TAG:
if (arg <= 0 || arg > 16 || !EVP_CIPHER_CTX_encrypting(c)
|| gctx->taglen < 0)
return 0;
memcpy(ptr, EVP_CIPHER_CTX_buf_noconst(c), arg);
return 1;
case EVP_CTRL_GCM_SET_IV_FIXED:
if (arg == -1) {
memcpy(gctx->iv, ptr, gctx->ivlen);
gctx->iv_gen = 1;
return 1;
}
if ((arg < 4) || (gctx->ivlen - arg) < 8)
return 0;
if (arg)
memcpy(gctx->iv, ptr, arg);
if (EVP_CIPHER_CTX_encrypting(c)
&& RAND_bytes(gctx->iv + arg, gctx->ivlen - arg) <= 0)
return 0;
gctx->iv_gen = 1;
return 1;
case EVP_CTRL_GCM_IV_GEN:
if (gctx->iv_gen == 0 || gctx->key_set == 0)
return 0;
CRYPTO_gcm128_setiv(&gctx->gcm, gctx->iv, gctx->ivlen);
if (arg <= 0 || arg > gctx->ivlen)
arg = gctx->ivlen;
memcpy(ptr, gctx->iv + gctx->ivlen - arg, arg);
ctr64_inc(gctx->iv + gctx->ivlen - 8);
gctx->iv_set = 1;
return 1;
case EVP_CTRL_GCM_SET_IV_INV:
if (gctx->iv_gen == 0 || gctx->key_set == 0
|| EVP_CIPHER_CTX_encrypting(c))
return 0;
memcpy(gctx->iv + gctx->ivlen - arg, ptr, arg);
CRYPTO_gcm128_setiv(&gctx->gcm, gctx->iv, gctx->ivlen);
gctx->iv_set = 1;
return 1;
case EVP_CTRL_AEAD_TLS1_AAD:
if (arg != EVP_AEAD_TLS1_AAD_LEN)
return 0;
memcpy(EVP_CIPHER_CTX_buf_noconst(c), ptr, arg);
gctx->tls_aad_len = arg;
{
unsigned int len =
EVP_CIPHER_CTX_buf_noconst(c)[arg - 2] << 8
| EVP_CIPHER_CTX_buf_noconst(c)[arg - 1];
len -= EVP_GCM_TLS_EXPLICIT_IV_LEN;
if (!EVP_CIPHER_CTX_encrypting(c))
len -= EVP_GCM_TLS_TAG_LEN;
EVP_CIPHER_CTX_buf_noconst(c)[arg - 2] = len >> 8;
EVP_CIPHER_CTX_buf_noconst(c)[arg - 1] = len & 0xff;
}
return EVP_GCM_TLS_TAG_LEN;
case EVP_CTRL_COPY:
{
EVP_CIPHER_CTX *out = ptr;
EVP_AES_GCM_CTX *gctx_out = EVP_C_DATA(EVP_AES_GCM_CTX,out);
if (gctx->gcm.key) {
if (gctx->gcm.key != &gctx->ks)
return 0;
gctx_out->gcm.key = &gctx_out->ks;
}
if (gctx->iv == EVP_CIPHER_CTX_iv_noconst(c))
gctx_out->iv = EVP_CIPHER_CTX_iv_noconst(out);
else {
gctx_out->iv = OPENSSL_malloc(gctx->ivlen);
if (gctx_out->iv == NULL)
return 0;
memcpy(gctx_out->iv, gctx->iv, gctx->ivlen);
}
return 1;
}
default:
return -1;
}
}
static int aes_gcm_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_GCM_CTX *gctx = EVP_C_DATA(EVP_AES_GCM_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
do {
#ifdef HWAES_CAPABLE
if (HWAES_CAPABLE) {
HWAES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&gctx->ks.ks);
CRYPTO_gcm128_init(&gctx->gcm, &gctx->ks,
(block128_f) HWAES_encrypt);
# ifdef HWAES_ctr32_encrypt_blocks
gctx->ctr = (ctr128_f) HWAES_ctr32_encrypt_blocks;
# else
gctx->ctr = NULL;
# endif
break;
} else
#endif
#ifdef BSAES_CAPABLE
if (BSAES_CAPABLE) {
AES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&gctx->ks.ks);
CRYPTO_gcm128_init(&gctx->gcm, &gctx->ks,
(block128_f) AES_encrypt);
gctx->ctr = (ctr128_f) bsaes_ctr32_encrypt_blocks;
break;
} else
#endif
#ifdef VPAES_CAPABLE
if (VPAES_CAPABLE) {
vpaes_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&gctx->ks.ks);
CRYPTO_gcm128_init(&gctx->gcm, &gctx->ks,
(block128_f) vpaes_encrypt);
gctx->ctr = NULL;
break;
} else
#endif
(void)0;
AES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&gctx->ks.ks);
CRYPTO_gcm128_init(&gctx->gcm, &gctx->ks,
(block128_f) AES_encrypt);
#ifdef AES_CTR_ASM
gctx->ctr = (ctr128_f) AES_ctr32_encrypt;
#else
gctx->ctr = NULL;
#endif
} while (0);
if (iv == NULL && gctx->iv_set)
iv = gctx->iv;
if (iv) {
CRYPTO_gcm128_setiv(&gctx->gcm, iv, gctx->ivlen);
gctx->iv_set = 1;
}
gctx->key_set = 1;
} else {
if (gctx->key_set)
CRYPTO_gcm128_setiv(&gctx->gcm, iv, gctx->ivlen);
else
memcpy(gctx->iv, iv, gctx->ivlen);
gctx->iv_set = 1;
gctx->iv_gen = 0;
}
return 1;
}
static int aes_gcm_tls_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_GCM_CTX *gctx = EVP_C_DATA(EVP_AES_GCM_CTX,ctx);
int rv = -1;
if (out != in
|| len < (EVP_GCM_TLS_EXPLICIT_IV_LEN + EVP_GCM_TLS_TAG_LEN))
return -1;
if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CIPHER_CTX_encrypting(ctx) ?
EVP_CTRL_GCM_IV_GEN : EVP_CTRL_GCM_SET_IV_INV,
EVP_GCM_TLS_EXPLICIT_IV_LEN, out) <= 0)
goto err;
if (CRYPTO_gcm128_aad(&gctx->gcm, EVP_CIPHER_CTX_buf_noconst(ctx),
gctx->tls_aad_len))
goto err;
in += EVP_GCM_TLS_EXPLICIT_IV_LEN;
out += EVP_GCM_TLS_EXPLICIT_IV_LEN;
len -= EVP_GCM_TLS_EXPLICIT_IV_LEN + EVP_GCM_TLS_TAG_LEN;
if (EVP_CIPHER_CTX_encrypting(ctx)) {
if (gctx->ctr) {
size_t bulk = 0;
#if defined(AES_GCM_ASM)
if (len >= 32 && AES_GCM_ASM(gctx)) {
if (CRYPTO_gcm128_encrypt(&gctx->gcm, NULL, NULL, 0))
return -1;
bulk = AES_gcm_encrypt(in, out, len,
gctx->gcm.key,
gctx->gcm.Yi.c, gctx->gcm.Xi.u);
gctx->gcm.len.u[1] += bulk;
}
#endif
if (CRYPTO_gcm128_encrypt_ctr32(&gctx->gcm,
in + bulk,
out + bulk,
len - bulk, gctx->ctr))
goto err;
} else {
size_t bulk = 0;
#if defined(AES_GCM_ASM2)
if (len >= 32 && AES_GCM_ASM2(gctx)) {
if (CRYPTO_gcm128_encrypt(&gctx->gcm, NULL, NULL, 0))
return -1;
bulk = AES_gcm_encrypt(in, out, len,
gctx->gcm.key,
gctx->gcm.Yi.c, gctx->gcm.Xi.u);
gctx->gcm.len.u[1] += bulk;
}
#endif
if (CRYPTO_gcm128_encrypt(&gctx->gcm,
in + bulk, out + bulk, len - bulk))
goto err;
}
out += len;
CRYPTO_gcm128_tag(&gctx->gcm, out, EVP_GCM_TLS_TAG_LEN);
rv = len + EVP_GCM_TLS_EXPLICIT_IV_LEN + EVP_GCM_TLS_TAG_LEN;
} else {
if (gctx->ctr) {
size_t bulk = 0;
#if defined(AES_GCM_ASM)
if (len >= 16 && AES_GCM_ASM(gctx)) {
if (CRYPTO_gcm128_decrypt(&gctx->gcm, NULL, NULL, 0))
return -1;
bulk = AES_gcm_decrypt(in, out, len,
gctx->gcm.key,
gctx->gcm.Yi.c, gctx->gcm.Xi.u);
gctx->gcm.len.u[1] += bulk;
}
#endif
if (CRYPTO_gcm128_decrypt_ctr32(&gctx->gcm,
in + bulk,
out + bulk,
len - bulk, gctx->ctr))
goto err;
} else {
size_t bulk = 0;
#if defined(AES_GCM_ASM2)
if (len >= 16 && AES_GCM_ASM2(gctx)) {
if (CRYPTO_gcm128_decrypt(&gctx->gcm, NULL, NULL, 0))
return -1;
bulk = AES_gcm_decrypt(in, out, len,
gctx->gcm.key,
gctx->gcm.Yi.c, gctx->gcm.Xi.u);
gctx->gcm.len.u[1] += bulk;
}
#endif
if (CRYPTO_gcm128_decrypt(&gctx->gcm,
in + bulk, out + bulk, len - bulk))
goto err;
}
CRYPTO_gcm128_tag(&gctx->gcm, EVP_CIPHER_CTX_buf_noconst(ctx),
EVP_GCM_TLS_TAG_LEN);
if (CRYPTO_memcmp(EVP_CIPHER_CTX_buf_noconst(ctx), in + len,
EVP_GCM_TLS_TAG_LEN)) {
OPENSSL_cleanse(out, len);
goto err;
}
rv = len;
}
err:
gctx->iv_set = 0;
gctx->tls_aad_len = -1;
return rv;
}
static int aes_gcm_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_GCM_CTX *gctx = EVP_C_DATA(EVP_AES_GCM_CTX,ctx);
if (!gctx->key_set)
return -1;
if (gctx->tls_aad_len >= 0)
return aes_gcm_tls_cipher(ctx, out, in, len);
if (!gctx->iv_set)
return -1;
if (in) {
if (out == NULL) {
if (CRYPTO_gcm128_aad(&gctx->gcm, in, len))
return -1;
} else if (EVP_CIPHER_CTX_encrypting(ctx)) {
if (gctx->ctr) {
size_t bulk = 0;
#if defined(AES_GCM_ASM)
if (len >= 32 && AES_GCM_ASM(gctx)) {
size_t res = (16 - gctx->gcm.mres) % 16;
if (CRYPTO_gcm128_encrypt(&gctx->gcm, in, out, res))
return -1;
bulk = AES_gcm_encrypt(in + res,
out + res, len - res,
gctx->gcm.key, gctx->gcm.Yi.c,
gctx->gcm.Xi.u);
gctx->gcm.len.u[1] += bulk;
bulk += res;
}
#endif
if (CRYPTO_gcm128_encrypt_ctr32(&gctx->gcm,
in + bulk,
out + bulk,
len - bulk, gctx->ctr))
return -1;
} else {
size_t bulk = 0;
#if defined(AES_GCM_ASM2)
if (len >= 32 && AES_GCM_ASM2(gctx)) {
size_t res = (16 - gctx->gcm.mres) % 16;
if (CRYPTO_gcm128_encrypt(&gctx->gcm, in, out, res))
return -1;
bulk = AES_gcm_encrypt(in + res,
out + res, len - res,
gctx->gcm.key, gctx->gcm.Yi.c,
gctx->gcm.Xi.u);
gctx->gcm.len.u[1] += bulk;
bulk += res;
}
#endif
if (CRYPTO_gcm128_encrypt(&gctx->gcm,
in + bulk, out + bulk, len - bulk))
return -1;
}
} else {
if (gctx->ctr) {
size_t bulk = 0;
#if defined(AES_GCM_ASM)
if (len >= 16 && AES_GCM_ASM(gctx)) {
size_t res = (16 - gctx->gcm.mres) % 16;
if (CRYPTO_gcm128_decrypt(&gctx->gcm, in, out, res))
return -1;
bulk = AES_gcm_decrypt(in + res,
out + res, len - res,
gctx->gcm.key,
gctx->gcm.Yi.c, gctx->gcm.Xi.u);
gctx->gcm.len.u[1] += bulk;
bulk += res;
}
#endif
if (CRYPTO_gcm128_decrypt_ctr32(&gctx->gcm,
in + bulk,
out + bulk,
len - bulk, gctx->ctr))
return -1;
} else {
size_t bulk = 0;
#if defined(AES_GCM_ASM2)
if (len >= 16 && AES_GCM_ASM2(gctx)) {
size_t res = (16 - gctx->gcm.mres) % 16;
if (CRYPTO_gcm128_decrypt(&gctx->gcm, in, out, res))
return -1;
bulk = AES_gcm_decrypt(in + res,
out + res, len - res,
gctx->gcm.key,
gctx->gcm.Yi.c, gctx->gcm.Xi.u);
gctx->gcm.len.u[1] += bulk;
bulk += res;
}
#endif
if (CRYPTO_gcm128_decrypt(&gctx->gcm,
in + bulk, out + bulk, len - bulk))
return -1;
}
}
return len;
} else {
if (!EVP_CIPHER_CTX_encrypting(ctx)) {
if (gctx->taglen < 0)
return -1;
if (CRYPTO_gcm128_finish(&gctx->gcm,
EVP_CIPHER_CTX_buf_noconst(ctx),
gctx->taglen) != 0)
return -1;
gctx->iv_set = 0;
return 0;
}
CRYPTO_gcm128_tag(&gctx->gcm, EVP_CIPHER_CTX_buf_noconst(ctx), 16);
gctx->taglen = 16;
gctx->iv_set = 0;
return 0;
}
}
static int aes_xts_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
EVP_AES_XTS_CTX *xctx = EVP_C_DATA(EVP_AES_XTS_CTX,c);
if (type == EVP_CTRL_COPY) {
EVP_CIPHER_CTX *out = ptr;
EVP_AES_XTS_CTX *xctx_out = EVP_C_DATA(EVP_AES_XTS_CTX,out);
if (xctx->xts.key1) {
if (xctx->xts.key1 != &xctx->ks1)
return 0;
xctx_out->xts.key1 = &xctx_out->ks1;
}
if (xctx->xts.key2) {
if (xctx->xts.key2 != &xctx->ks2)
return 0;
xctx_out->xts.key2 = &xctx_out->ks2;
}
return 1;
} else if (type != EVP_CTRL_INIT)
return -1;
xctx->xts.key1 = NULL;
xctx->xts.key2 = NULL;
return 1;
}
static int aes_xts_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_XTS_CTX *xctx = EVP_C_DATA(EVP_AES_XTS_CTX,ctx);
if (!iv && !key)
return 1;
if (key)
do {
#ifdef AES_XTS_ASM
xctx->stream = enc ? AES_xts_encrypt : AES_xts_decrypt;
#else
xctx->stream = NULL;
#endif
#ifdef HWAES_CAPABLE
if (HWAES_CAPABLE) {
if (enc) {
HWAES_set_encrypt_key(key,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) HWAES_encrypt;
# ifdef HWAES_xts_encrypt
xctx->stream = HWAES_xts_encrypt;
# endif
} else {
HWAES_set_decrypt_key(key,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) HWAES_decrypt;
# ifdef HWAES_xts_decrypt
xctx->stream = HWAES_xts_decrypt;
#endif
}
HWAES_set_encrypt_key(key + EVP_CIPHER_CTX_key_length(ctx) / 2,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks2.ks);
xctx->xts.block2 = (block128_f) HWAES_encrypt;
xctx->xts.key1 = &xctx->ks1;
break;
} else
#endif
#ifdef BSAES_CAPABLE
if (BSAES_CAPABLE)
xctx->stream = enc ? bsaes_xts_encrypt : bsaes_xts_decrypt;
else
#endif
#ifdef VPAES_CAPABLE
if (VPAES_CAPABLE) {
if (enc) {
vpaes_set_encrypt_key(key,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) vpaes_encrypt;
} else {
vpaes_set_decrypt_key(key,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) vpaes_decrypt;
}
vpaes_set_encrypt_key(key + EVP_CIPHER_CTX_key_length(ctx) / 2,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks2.ks);
xctx->xts.block2 = (block128_f) vpaes_encrypt;
xctx->xts.key1 = &xctx->ks1;
break;
} else
#endif
(void)0;
if (enc) {
AES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) AES_encrypt;
} else {
AES_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks1.ks);
xctx->xts.block1 = (block128_f) AES_decrypt;
}
AES_set_encrypt_key(key + EVP_CIPHER_CTX_key_length(ctx) / 2,
EVP_CIPHER_CTX_key_length(ctx) * 4,
&xctx->ks2.ks);
xctx->xts.block2 = (block128_f) AES_encrypt;
xctx->xts.key1 = &xctx->ks1;
} while (0);
if (iv) {
xctx->xts.key2 = &xctx->ks2;
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), iv, 16);
}
return 1;
}
static int aes_xts_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_XTS_CTX *xctx = EVP_C_DATA(EVP_AES_XTS_CTX,ctx);
if (!xctx->xts.key1 || !xctx->xts.key2)
return 0;
if (!out || !in || len < AES_BLOCK_SIZE)
return 0;
if (xctx->stream)
(*xctx->stream) (in, out, len,
xctx->xts.key1, xctx->xts.key2,
EVP_CIPHER_CTX_iv_noconst(ctx));
else if (CRYPTO_xts128_encrypt(&xctx->xts, EVP_CIPHER_CTX_iv_noconst(ctx),
in, out, len,
EVP_CIPHER_CTX_encrypting(ctx)))
return 0;
return 1;
}
static int aes_ccm_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
EVP_AES_CCM_CTX *cctx = EVP_C_DATA(EVP_AES_CCM_CTX,c);
switch (type) {
case EVP_CTRL_INIT:
cctx->key_set = 0;
cctx->iv_set = 0;
cctx->L = 8;
cctx->M = 12;
cctx->tag_set = 0;
cctx->len_set = 0;
cctx->tls_aad_len = -1;
return 1;
case EVP_CTRL_AEAD_TLS1_AAD:
if (arg != EVP_AEAD_TLS1_AAD_LEN)
return 0;
memcpy(EVP_CIPHER_CTX_buf_noconst(c), ptr, arg);
cctx->tls_aad_len = arg;
{
uint16_t len =
EVP_CIPHER_CTX_buf_noconst(c)[arg - 2] << 8
| EVP_CIPHER_CTX_buf_noconst(c)[arg - 1];
len -= EVP_CCM_TLS_EXPLICIT_IV_LEN;
if (!EVP_CIPHER_CTX_encrypting(c))
len -= cctx->M;
EVP_CIPHER_CTX_buf_noconst(c)[arg - 2] = len >> 8;
EVP_CIPHER_CTX_buf_noconst(c)[arg - 1] = len & 0xff;
}
return cctx->M;
case EVP_CTRL_CCM_SET_IV_FIXED:
if (arg != EVP_CCM_TLS_FIXED_IV_LEN)
return 0;
memcpy(EVP_CIPHER_CTX_iv_noconst(c), ptr, arg);
return 1;
case EVP_CTRL_AEAD_SET_IVLEN:
arg = 15 - arg;
case EVP_CTRL_CCM_SET_L:
if (arg < 2 || arg > 8)
return 0;
cctx->L = arg;
return 1;
case EVP_CTRL_AEAD_SET_TAG:
if ((arg & 1) || arg < 4 || arg > 16)
return 0;
if (EVP_CIPHER_CTX_encrypting(c) && ptr)
return 0;
if (ptr) {
cctx->tag_set = 1;
memcpy(EVP_CIPHER_CTX_buf_noconst(c), ptr, arg);
}
cctx->M = arg;
return 1;
case EVP_CTRL_AEAD_GET_TAG:
if (!EVP_CIPHER_CTX_encrypting(c) || !cctx->tag_set)
return 0;
if (!CRYPTO_ccm128_tag(&cctx->ccm, ptr, (size_t)arg))
return 0;
cctx->tag_set = 0;
cctx->iv_set = 0;
cctx->len_set = 0;
return 1;
case EVP_CTRL_COPY:
{
EVP_CIPHER_CTX *out = ptr;
EVP_AES_CCM_CTX *cctx_out = EVP_C_DATA(EVP_AES_CCM_CTX,out);
if (cctx->ccm.key) {
if (cctx->ccm.key != &cctx->ks)
return 0;
cctx_out->ccm.key = &cctx_out->ks;
}
return 1;
}
default:
return -1;
}
}
static int aes_ccm_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_CCM_CTX *cctx = EVP_C_DATA(EVP_AES_CCM_CTX,ctx);
if (!iv && !key)
return 1;
if (key)
do {
#ifdef HWAES_CAPABLE
if (HWAES_CAPABLE) {
HWAES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&cctx->ks.ks);
CRYPTO_ccm128_init(&cctx->ccm, cctx->M, cctx->L,
&cctx->ks, (block128_f) HWAES_encrypt);
cctx->str = NULL;
cctx->key_set = 1;
break;
} else
#endif
#ifdef VPAES_CAPABLE
if (VPAES_CAPABLE) {
vpaes_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&cctx->ks.ks);
CRYPTO_ccm128_init(&cctx->ccm, cctx->M, cctx->L,
&cctx->ks, (block128_f) vpaes_encrypt);
cctx->str = NULL;
cctx->key_set = 1;
break;
}
#endif
AES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&cctx->ks.ks);
CRYPTO_ccm128_init(&cctx->ccm, cctx->M, cctx->L,
&cctx->ks, (block128_f) AES_encrypt);
cctx->str = NULL;
cctx->key_set = 1;
} while (0);
if (iv) {
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), iv, 15 - cctx->L);
cctx->iv_set = 1;
}
return 1;
}
static int aes_ccm_tls_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_CCM_CTX *cctx = EVP_C_DATA(EVP_AES_CCM_CTX,ctx);
CCM128_CONTEXT *ccm = &cctx->ccm;
if (out != in || len < (EVP_CCM_TLS_EXPLICIT_IV_LEN + (size_t)cctx->M))
return -1;
if (EVP_CIPHER_CTX_encrypting(ctx))
memcpy(out, EVP_CIPHER_CTX_buf_noconst(ctx),
EVP_CCM_TLS_EXPLICIT_IV_LEN);
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx) + EVP_CCM_TLS_FIXED_IV_LEN, in,
EVP_CCM_TLS_EXPLICIT_IV_LEN);
len -= EVP_CCM_TLS_EXPLICIT_IV_LEN + cctx->M;
if (CRYPTO_ccm128_setiv(ccm, EVP_CIPHER_CTX_iv_noconst(ctx), 15 - cctx->L,
len))
return -1;
CRYPTO_ccm128_aad(ccm, EVP_CIPHER_CTX_buf_noconst(ctx), cctx->tls_aad_len);
in += EVP_CCM_TLS_EXPLICIT_IV_LEN;
out += EVP_CCM_TLS_EXPLICIT_IV_LEN;
if (EVP_CIPHER_CTX_encrypting(ctx)) {
if (cctx->str ? CRYPTO_ccm128_encrypt_ccm64(ccm, in, out, len,
cctx->str) :
CRYPTO_ccm128_encrypt(ccm, in, out, len))
return -1;
if (!CRYPTO_ccm128_tag(ccm, out + len, cctx->M))
return -1;
return len + EVP_CCM_TLS_EXPLICIT_IV_LEN + cctx->M;
} else {
if (cctx->str ? !CRYPTO_ccm128_decrypt_ccm64(ccm, in, out, len,
cctx->str) :
!CRYPTO_ccm128_decrypt(ccm, in, out, len)) {
unsigned char tag[16];
if (CRYPTO_ccm128_tag(ccm, tag, cctx->M)) {
if (!CRYPTO_memcmp(tag, in + len, cctx->M))
return len;
}
}
OPENSSL_cleanse(out, len);
return -1;
}
}
static int aes_ccm_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
EVP_AES_CCM_CTX *cctx = EVP_C_DATA(EVP_AES_CCM_CTX,ctx);
CCM128_CONTEXT *ccm = &cctx->ccm;
if (!cctx->key_set)
return -1;
if (cctx->tls_aad_len >= 0)
return aes_ccm_tls_cipher(ctx, out, in, len);
if (!cctx->iv_set)
return -1;
if (!EVP_CIPHER_CTX_encrypting(ctx) && !cctx->tag_set)
return -1;
if (!out) {
if (!in) {
if (CRYPTO_ccm128_setiv(ccm, EVP_CIPHER_CTX_iv_noconst(ctx),
15 - cctx->L, len))
return -1;
cctx->len_set = 1;
return len;
}
if (!cctx->len_set && len)
return -1;
CRYPTO_ccm128_aad(ccm, in, len);
return len;
}
if (!in)
return 0;
if (!cctx->len_set) {
if (CRYPTO_ccm128_setiv(ccm, EVP_CIPHER_CTX_iv_noconst(ctx),
15 - cctx->L, len))
return -1;
cctx->len_set = 1;
}
if (EVP_CIPHER_CTX_encrypting(ctx)) {
if (cctx->str ? CRYPTO_ccm128_encrypt_ccm64(ccm, in, out, len,
cctx->str) :
CRYPTO_ccm128_encrypt(ccm, in, out, len))
return -1;
cctx->tag_set = 1;
return len;
} else {
int rv = -1;
if (cctx->str ? !CRYPTO_ccm128_decrypt_ccm64(ccm, in, out, len,
cctx->str) :
!CRYPTO_ccm128_decrypt(ccm, in, out, len)) {
unsigned char tag[16];
if (CRYPTO_ccm128_tag(ccm, tag, cctx->M)) {
if (!CRYPTO_memcmp(tag, EVP_CIPHER_CTX_buf_noconst(ctx),
cctx->M))
rv = len;
}
}
if (rv == -1)
OPENSSL_cleanse(out, len);
cctx->iv_set = 0;
cctx->tag_set = 0;
cctx->len_set = 0;
return rv;
}
}
static int aes_wrap_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_WRAP_CTX *wctx = EVP_C_DATA(EVP_AES_WRAP_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
if (EVP_CIPHER_CTX_encrypting(ctx))
AES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&wctx->ks.ks);
else
AES_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&wctx->ks.ks);
if (!iv)
wctx->iv = NULL;
}
if (iv) {
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), iv, EVP_CIPHER_CTX_iv_length(ctx));
wctx->iv = EVP_CIPHER_CTX_iv_noconst(ctx);
}
return 1;
}
static int aes_wrap_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inlen)
{
EVP_AES_WRAP_CTX *wctx = EVP_C_DATA(EVP_AES_WRAP_CTX,ctx);
size_t rv;
int pad = EVP_CIPHER_CTX_iv_length(ctx) == 4;
if (!in)
return 0;
if (!inlen)
return -1;
if (!EVP_CIPHER_CTX_encrypting(ctx) && (inlen < 16 || inlen & 0x7))
return -1;
if (!pad && inlen & 0x7)
return -1;
if (!out) {
if (EVP_CIPHER_CTX_encrypting(ctx)) {
if (pad)
inlen = (inlen + 7) / 8 * 8;
return inlen + 8;
} else {
return inlen - 8;
}
}
if (pad) {
if (EVP_CIPHER_CTX_encrypting(ctx))
rv = CRYPTO_128_wrap_pad(&wctx->ks.ks, wctx->iv,
out, in, inlen,
(block128_f) AES_encrypt);
else
rv = CRYPTO_128_unwrap_pad(&wctx->ks.ks, wctx->iv,
out, in, inlen,
(block128_f) AES_decrypt);
} else {
if (EVP_CIPHER_CTX_encrypting(ctx))
rv = CRYPTO_128_wrap(&wctx->ks.ks, wctx->iv,
out, in, inlen, (block128_f) AES_encrypt);
else
rv = CRYPTO_128_unwrap(&wctx->ks.ks, wctx->iv,
out, in, inlen, (block128_f) AES_decrypt);
}
return rv ? (int)rv : -1;
}
const EVP_CIPHER *EVP_aes_128_wrap(void)
{
return &aes_128_wrap;
}
const EVP_CIPHER *EVP_aes_192_wrap(void)
{
return &aes_192_wrap;
}
const EVP_CIPHER *EVP_aes_256_wrap(void)
{
return &aes_256_wrap;
}
const EVP_CIPHER *EVP_aes_128_wrap_pad(void)
{
return &aes_128_wrap_pad;
}
const EVP_CIPHER *EVP_aes_192_wrap_pad(void)
{
return &aes_192_wrap_pad;
}
const EVP_CIPHER *EVP_aes_256_wrap_pad(void)
{
return &aes_256_wrap_pad;
}
static int aes_ocb_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
EVP_AES_OCB_CTX *octx = EVP_C_DATA(EVP_AES_OCB_CTX,c);
EVP_CIPHER_CTX *newc;
EVP_AES_OCB_CTX *new_octx;
switch (type) {
case EVP_CTRL_INIT:
octx->key_set = 0;
octx->iv_set = 0;
octx->ivlen = EVP_CIPHER_CTX_iv_length(c);
octx->iv = EVP_CIPHER_CTX_iv_noconst(c);
octx->taglen = 16;
octx->data_buf_len = 0;
octx->aad_buf_len = 0;
return 1;
case EVP_CTRL_AEAD_SET_IVLEN:
if (arg <= 0 || arg > 15)
return 0;
octx->ivlen = arg;
return 1;
case EVP_CTRL_AEAD_SET_TAG:
if (!ptr) {
if (arg < 0 || arg > 16)
return 0;
octx->taglen = arg;
return 1;
}
if (arg != octx->taglen || EVP_CIPHER_CTX_encrypting(c))
return 0;
memcpy(octx->tag, ptr, arg);
return 1;
case EVP_CTRL_AEAD_GET_TAG:
if (arg != octx->taglen || !EVP_CIPHER_CTX_encrypting(c))
return 0;
memcpy(ptr, octx->tag, arg);
return 1;
case EVP_CTRL_COPY:
newc = (EVP_CIPHER_CTX *)ptr;
new_octx = EVP_C_DATA(EVP_AES_OCB_CTX,newc);
return CRYPTO_ocb128_copy_ctx(&new_octx->ocb, &octx->ocb,
&new_octx->ksenc.ks,
&new_octx->ksdec.ks);
default:
return -1;
}
}
static int aes_ocb_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
EVP_AES_OCB_CTX *octx = EVP_C_DATA(EVP_AES_OCB_CTX,ctx);
if (!iv && !key)
return 1;
if (key) {
do {
# ifdef HWAES_CAPABLE
if (HWAES_CAPABLE) {
HWAES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksenc.ks);
HWAES_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksdec.ks);
if (!CRYPTO_ocb128_init(&octx->ocb,
&octx->ksenc.ks, &octx->ksdec.ks,
(block128_f) HWAES_encrypt,
(block128_f) HWAES_decrypt,
enc ? HWAES_ocb_encrypt
: HWAES_ocb_decrypt))
return 0;
break;
}
# endif
# ifdef VPAES_CAPABLE
if (VPAES_CAPABLE) {
vpaes_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksenc.ks);
vpaes_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksdec.ks);
if (!CRYPTO_ocb128_init(&octx->ocb,
&octx->ksenc.ks, &octx->ksdec.ks,
(block128_f) vpaes_encrypt,
(block128_f) vpaes_decrypt,
NULL))
return 0;
break;
}
# endif
AES_set_encrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksenc.ks);
AES_set_decrypt_key(key, EVP_CIPHER_CTX_key_length(ctx) * 8,
&octx->ksdec.ks);
if (!CRYPTO_ocb128_init(&octx->ocb,
&octx->ksenc.ks, &octx->ksdec.ks,
(block128_f) AES_encrypt,
(block128_f) AES_decrypt,
NULL))
return 0;
}
while (0);
if (iv == NULL && octx->iv_set)
iv = octx->iv;
if (iv) {
if (CRYPTO_ocb128_setiv(&octx->ocb, iv, octx->ivlen, octx->taglen)
!= 1)
return 0;
octx->iv_set = 1;
}
octx->key_set = 1;
} else {
if (octx->key_set)
CRYPTO_ocb128_setiv(&octx->ocb, iv, octx->ivlen, octx->taglen);
else
memcpy(octx->iv, iv, octx->ivlen);
octx->iv_set = 1;
}
return 1;
}
static int aes_ocb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t len)
{
unsigned char *buf;
int *buf_len;
int written_len = 0;
size_t trailing_len;
EVP_AES_OCB_CTX *octx = EVP_C_DATA(EVP_AES_OCB_CTX,ctx);
if (!octx->iv_set)
return -1;
if (!octx->key_set)
return -1;
if (in) {
if (out == NULL) {
buf = octx->aad_buf;
buf_len = &(octx->aad_buf_len);
} else {
buf = octx->data_buf;
buf_len = &(octx->data_buf_len);
}
if (*buf_len) {
unsigned int remaining;
remaining = 16 - (*buf_len);
if (remaining > len) {
memcpy(buf + (*buf_len), in, len);
*(buf_len) += len;
return 0;
}
memcpy(buf + (*buf_len), in, remaining);
len -= remaining;
in += remaining;
if (out == NULL) {
if (!CRYPTO_ocb128_aad(&octx->ocb, buf, 16))
return -1;
} else if (EVP_CIPHER_CTX_encrypting(ctx)) {
if (!CRYPTO_ocb128_encrypt(&octx->ocb, buf, out, 16))
return -1;
} else {
if (!CRYPTO_ocb128_decrypt(&octx->ocb, buf, out, 16))
return -1;
}
written_len = 16;
*buf_len = 0;
}
trailing_len = len % 16;
if (len != trailing_len) {
if (out == NULL) {
if (!CRYPTO_ocb128_aad(&octx->ocb, in, len - trailing_len))
return -1;
} else if (EVP_CIPHER_CTX_encrypting(ctx)) {
if (!CRYPTO_ocb128_encrypt
(&octx->ocb, in, out, len - trailing_len))
return -1;
} else {
if (!CRYPTO_ocb128_decrypt
(&octx->ocb, in, out, len - trailing_len))
return -1;
}
written_len += len - trailing_len;
in += len - trailing_len;
}
if (trailing_len) {
memcpy(buf, in, trailing_len);
*buf_len = trailing_len;
}
return written_len;
} else {
if (octx->data_buf_len) {
if (EVP_CIPHER_CTX_encrypting(ctx)) {
if (!CRYPTO_ocb128_encrypt(&octx->ocb, octx->data_buf, out,
octx->data_buf_len))
return -1;
} else {
if (!CRYPTO_ocb128_decrypt(&octx->ocb, octx->data_buf, out,
octx->data_buf_len))
return -1;
}
written_len = octx->data_buf_len;
octx->data_buf_len = 0;
}
if (octx->aad_buf_len) {
if (!CRYPTO_ocb128_aad
(&octx->ocb, octx->aad_buf, octx->aad_buf_len))
return -1;
octx->aad_buf_len = 0;
}
if (!EVP_CIPHER_CTX_encrypting(ctx)) {
if (octx->taglen < 0)
return -1;
if (CRYPTO_ocb128_finish(&octx->ocb,
octx->tag, octx->taglen) != 0)
return -1;
octx->iv_set = 0;
return written_len;
}
if (CRYPTO_ocb128_tag(&octx->ocb, octx->tag, 16) != 1)
return -1;
octx->iv_set = 0;
return written_len;
}
}
static int aes_ocb_cleanup(EVP_CIPHER_CTX *c)
{
EVP_AES_OCB_CTX *octx = EVP_C_DATA(EVP_AES_OCB_CTX,c);
CRYPTO_ocb128_cleanup(&octx->ocb);
return 1;
}
