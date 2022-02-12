void engine_load_padlock_int(void)
{
# ifdef COMPILE_HW_PADLOCK
ENGINE *toadd = ENGINE_padlock();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
# endif
}
static int padlock_bind_helper(ENGINE *e)
{
padlock_available();
padlock_use_rng = 0;
BIO_snprintf(padlock_name, sizeof(padlock_name),
"VIA PadLock (%s, %s)",
padlock_use_rng ? "RNG" : "no-RNG",
padlock_use_ace ? "ACE" : "no-ACE");
if (!ENGINE_set_id(e, padlock_id) ||
!ENGINE_set_name(e, padlock_name) ||
!ENGINE_set_init_function(e, padlock_init) ||
(padlock_use_ace && !ENGINE_set_ciphers(e, padlock_ciphers)) ||
(padlock_use_rng && !ENGINE_set_RAND(e, &padlock_rand))) {
return 0;
}
return 1;
}
static ENGINE *ENGINE_padlock(void)
{
ENGINE *eng = ENGINE_new();
if (eng == NULL) {
return NULL;
}
if (!padlock_bind_helper(eng)) {
ENGINE_free(eng);
return NULL;
}
return eng;
}
static int padlock_init(ENGINE *e)
{
return (padlock_use_rng || padlock_use_ace);
}
static int padlock_bind_fn(ENGINE *e, const char *id)
{
if (id && (strcmp(id, padlock_id) != 0)) {
return 0;
}
if (!padlock_bind_helper(e)) {
return 0;
}
return 1;
}
static int padlock_available(void)
{
unsigned int edx = padlock_capability();
padlock_use_ace = ((edx & (0x3 << 6)) == (0x3 << 6));
padlock_use_rng = ((edx & (0x3 << 2)) == (0x3 << 2));
return padlock_use_ace + padlock_use_rng;
}
static int
padlock_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out_arg,
const unsigned char *in_arg, size_t nbytes)
{
return padlock_ecb_encrypt(out_arg, in_arg,
ALIGNED_CIPHER_DATA(ctx), nbytes);
}
static int
padlock_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out_arg,
const unsigned char *in_arg, size_t nbytes)
{
struct padlock_cipher_data *cdata = ALIGNED_CIPHER_DATA(ctx);
int ret;
memcpy(cdata->iv, EVP_CIPHER_CTX_iv(ctx), AES_BLOCK_SIZE);
if ((ret = padlock_cbc_encrypt(out_arg, in_arg, cdata, nbytes)))
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), cdata->iv, AES_BLOCK_SIZE);
return ret;
}
static int
padlock_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out_arg,
const unsigned char *in_arg, size_t nbytes)
{
struct padlock_cipher_data *cdata = ALIGNED_CIPHER_DATA(ctx);
size_t chunk;
if ((chunk = EVP_CIPHER_CTX_num(ctx))) {
unsigned char *ivp = EVP_CIPHER_CTX_iv_noconst(ctx);
if (chunk >= AES_BLOCK_SIZE)
return 0;
if (EVP_CIPHER_CTX_encrypting(ctx))
while (chunk < AES_BLOCK_SIZE && nbytes != 0) {
ivp[chunk] = *(out_arg++) = *(in_arg++) ^ ivp[chunk];
chunk++, nbytes--;
} else
while (chunk < AES_BLOCK_SIZE && nbytes != 0) {
unsigned char c = *(in_arg++);
*(out_arg++) = c ^ ivp[chunk];
ivp[chunk++] = c, nbytes--;
}
EVP_CIPHER_CTX_set_num(ctx, chunk % AES_BLOCK_SIZE);
}
if (nbytes == 0)
return 1;
memcpy(cdata->iv, EVP_CIPHER_CTX_iv(ctx), AES_BLOCK_SIZE);
if ((chunk = nbytes & ~(AES_BLOCK_SIZE - 1))) {
if (!padlock_cfb_encrypt(out_arg, in_arg, cdata, chunk))
return 0;
nbytes -= chunk;
}
if (nbytes) {
unsigned char *ivp = cdata->iv;
out_arg += chunk;
in_arg += chunk;
EVP_CIPHER_CTX_set_num(ctx, nbytes);
if (cdata->cword.b.encdec) {
cdata->cword.b.encdec = 0;
padlock_reload_key();
padlock_aes_block(ivp, ivp, cdata);
cdata->cword.b.encdec = 1;
padlock_reload_key();
while (nbytes) {
unsigned char c = *(in_arg++);
*(out_arg++) = c ^ *ivp;
*(ivp++) = c, nbytes--;
}
} else {
padlock_reload_key();
padlock_aes_block(ivp, ivp, cdata);
padlock_reload_key();
while (nbytes) {
*ivp = *(out_arg++) = *(in_arg++) ^ *ivp;
ivp++, nbytes--;
}
}
}
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), cdata->iv, AES_BLOCK_SIZE);
return 1;
}
static int
padlock_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out_arg,
const unsigned char *in_arg, size_t nbytes)
{
struct padlock_cipher_data *cdata = ALIGNED_CIPHER_DATA(ctx);
size_t chunk;
if ((chunk = EVP_CIPHER_CTX_num(ctx))) {
unsigned char *ivp = EVP_CIPHER_CTX_iv_noconst(ctx);
if (chunk >= AES_BLOCK_SIZE)
return 0;
while (chunk < AES_BLOCK_SIZE && nbytes != 0) {
*(out_arg++) = *(in_arg++) ^ ivp[chunk];
chunk++, nbytes--;
}
EVP_CIPHER_CTX_set_num(ctx, chunk % AES_BLOCK_SIZE);
}
if (nbytes == 0)
return 1;
memcpy(cdata->iv, EVP_CIPHER_CTX_iv(ctx), AES_BLOCK_SIZE);
if ((chunk = nbytes & ~(AES_BLOCK_SIZE - 1))) {
if (!padlock_ofb_encrypt(out_arg, in_arg, cdata, chunk))
return 0;
nbytes -= chunk;
}
if (nbytes) {
unsigned char *ivp = cdata->iv;
out_arg += chunk;
in_arg += chunk;
EVP_CIPHER_CTX_set_num(ctx, nbytes);
padlock_reload_key();
padlock_aes_block(ivp, ivp, cdata);
padlock_reload_key();
while (nbytes) {
*(out_arg++) = *(in_arg++) ^ *ivp;
ivp++, nbytes--;
}
}
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), cdata->iv, AES_BLOCK_SIZE);
return 1;
}
static void padlock_ctr32_encrypt_glue(const unsigned char *in,
unsigned char *out, size_t blocks,
struct padlock_cipher_data *ctx,
const unsigned char *ivec)
{
memcpy(ctx->iv, ivec, AES_BLOCK_SIZE);
padlock_ctr32_encrypt(out, in, ctx, AES_BLOCK_SIZE * blocks);
}
static int
padlock_ctr_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out_arg,
const unsigned char *in_arg, size_t nbytes)
{
struct padlock_cipher_data *cdata = ALIGNED_CIPHER_DATA(ctx);
unsigned int num = EVP_CIPHER_CTX_num(ctx);
CRYPTO_ctr128_encrypt_ctr32(in_arg, out_arg, nbytes,
cdata, EVP_CIPHER_CTX_iv_noconst(ctx),
EVP_CIPHER_CTX_buf_noconst(ctx), &num,
(ctr128_f) padlock_ctr32_encrypt_glue);
EVP_CIPHER_CTX_set_num(ctx, (size_t)num);
return 1;
}
static int
padlock_ciphers(ENGINE *e, const EVP_CIPHER **cipher, const int **nids,
int nid)
{
if (!cipher) {
*nids = padlock_cipher_nids;
return padlock_cipher_nids_num;
}
switch (nid) {
case NID_aes_128_ecb:
*cipher = padlock_aes_128_ecb();
break;
case NID_aes_128_cbc:
*cipher = padlock_aes_128_cbc();
break;
case NID_aes_128_cfb:
*cipher = padlock_aes_128_cfb();
break;
case NID_aes_128_ofb:
*cipher = padlock_aes_128_ofb();
break;
case NID_aes_128_ctr:
*cipher = padlock_aes_128_ctr();
break;
case NID_aes_192_ecb:
*cipher = padlock_aes_192_ecb();
break;
case NID_aes_192_cbc:
*cipher = padlock_aes_192_cbc();
break;
case NID_aes_192_cfb:
*cipher = padlock_aes_192_cfb();
break;
case NID_aes_192_ofb:
*cipher = padlock_aes_192_ofb();
break;
case NID_aes_192_ctr:
*cipher = padlock_aes_192_ctr();
break;
case NID_aes_256_ecb:
*cipher = padlock_aes_256_ecb();
break;
case NID_aes_256_cbc:
*cipher = padlock_aes_256_cbc();
break;
case NID_aes_256_cfb:
*cipher = padlock_aes_256_cfb();
break;
case NID_aes_256_ofb:
*cipher = padlock_aes_256_ofb();
break;
case NID_aes_256_ctr:
*cipher = padlock_aes_256_ctr();
break;
default:
*cipher = NULL;
return 0;
}
return 1;
}
static int
padlock_aes_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
struct padlock_cipher_data *cdata;
int key_len = EVP_CIPHER_CTX_key_length(ctx) * 8;
unsigned long mode = EVP_CIPHER_CTX_mode(ctx);
if (key == NULL)
return 0;
cdata = ALIGNED_CIPHER_DATA(ctx);
memset(cdata, 0, sizeof(*cdata));
if (mode == EVP_CIPH_OFB_MODE || mode == EVP_CIPH_CTR_MODE)
cdata->cword.b.encdec = 0;
else
cdata->cword.b.encdec = (EVP_CIPHER_CTX_encrypting(ctx) == 0);
cdata->cword.b.rounds = 10 + (key_len - 128) / 32;
cdata->cword.b.ksize = (key_len - 128) / 64;
switch (key_len) {
case 128:
memcpy(cdata->ks.rd_key, key, AES_KEY_SIZE_128);
cdata->cword.b.keygen = 0;
break;
case 192:
case 256:
if ((mode == EVP_CIPH_ECB_MODE || mode == EVP_CIPH_CBC_MODE)
&& !enc)
AES_set_decrypt_key(key, key_len, &cdata->ks);
else
AES_set_encrypt_key(key, key_len, &cdata->ks);
# ifndef AES_ASM
padlock_key_bswap(&cdata->ks);
# endif
cdata->cword.b.keygen = 1;
break;
default:
return 0;
}
padlock_reload_key();
return 1;
}
static int padlock_rand_bytes(unsigned char *output, int count)
{
unsigned int eax, buf;
while (count >= 8) {
eax = padlock_xstore(output, 0);
if (!(eax & (1 << 6)))
return 0;
if (eax & (0x1F << 10))
return 0;
if ((eax & 0x1F) == 0)
continue;
if ((eax & 0x1F) != 8)
return 0;
output += 8;
count -= 8;
}
while (count > 0) {
eax = padlock_xstore(&buf, 3);
if (!(eax & (1 << 6)))
return 0;
if (eax & (0x1F << 10))
return 0;
if ((eax & 0x1F) == 0)
continue;
if ((eax & 0x1F) != 1)
return 0;
*output++ = (unsigned char)buf;
count--;
}
OPENSSL_cleanse(&buf, sizeof(buf));
return 1;
}
static int padlock_rand_status(void)
{
return 1;
}
OPENSSL_EXPORT
int bind_engine(ENGINE *e, const char *id, const dynamic_fns *fns)
{
return 0;
}
