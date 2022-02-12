static int num_rounds(struct crypto_aes_ctx *ctx)
{
return 6 + ctx->key_length / 4;
}
static int ce_aes_expandkey(struct crypto_aes_ctx *ctx, const u8 *in_key,
unsigned int key_len)
{
static u8 const rcon[] = {
0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36,
};
u32 kwords = key_len / sizeof(u32);
struct aes_block *key_enc, *key_dec;
int i, j;
if (key_len != AES_KEYSIZE_128 &&
key_len != AES_KEYSIZE_192 &&
key_len != AES_KEYSIZE_256)
return -EINVAL;
memcpy(ctx->key_enc, in_key, key_len);
ctx->key_length = key_len;
kernel_neon_begin();
for (i = 0; i < sizeof(rcon); i++) {
u32 *rki = ctx->key_enc + (i * kwords);
u32 *rko = rki + kwords;
#ifndef CONFIG_CPU_BIG_ENDIAN
rko[0] = ror32(ce_aes_sub(rki[kwords - 1]), 8);
rko[0] = rko[0] ^ rki[0] ^ rcon[i];
#else
rko[0] = rol32(ce_aes_sub(rki[kwords - 1]), 8);
rko[0] = rko[0] ^ rki[0] ^ (rcon[i] << 24);
#endif
rko[1] = rko[0] ^ rki[1];
rko[2] = rko[1] ^ rki[2];
rko[3] = rko[2] ^ rki[3];
if (key_len == AES_KEYSIZE_192) {
if (i >= 7)
break;
rko[4] = rko[3] ^ rki[4];
rko[5] = rko[4] ^ rki[5];
} else if (key_len == AES_KEYSIZE_256) {
if (i >= 6)
break;
rko[4] = ce_aes_sub(rko[3]) ^ rki[4];
rko[5] = rko[4] ^ rki[5];
rko[6] = rko[5] ^ rki[6];
rko[7] = rko[6] ^ rki[7];
}
}
key_enc = (struct aes_block *)ctx->key_enc;
key_dec = (struct aes_block *)ctx->key_dec;
j = num_rounds(ctx);
key_dec[0] = key_enc[j];
for (i = 1, j--; j > 0; i++, j--)
ce_aes_invert(key_dec + i, key_enc + j);
key_dec[i] = key_enc[0];
kernel_neon_end();
return 0;
}
static int ce_aes_setkey(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
int ret;
ret = ce_aes_expandkey(ctx, in_key, key_len);
if (!ret)
return 0;
crypto_skcipher_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int xts_set_key(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int ret;
ret = xts_verify_key(tfm, in_key, key_len);
if (ret)
return ret;
ret = ce_aes_expandkey(&ctx->key1, in_key, key_len / 2);
if (!ret)
ret = ce_aes_expandkey(&ctx->key2, &in_key[key_len / 2],
key_len / 2);
if (!ret)
return 0;
crypto_skcipher_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int ecb_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
unsigned int blocks;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_ecb_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, num_rounds(ctx), blocks);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ecb_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
unsigned int blocks;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_ecb_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_dec, num_rounds(ctx), blocks);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
unsigned int blocks;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_cbc_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, num_rounds(ctx), blocks,
walk.iv);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
unsigned int blocks;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_cbc_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_dec, num_rounds(ctx), blocks,
walk.iv);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ctr_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
int err, blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_ctr_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, num_rounds(ctx), blocks,
walk.iv);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
if (walk.nbytes) {
u8 __aligned(8) tail[AES_BLOCK_SIZE];
unsigned int nbytes = walk.nbytes;
u8 *tdst = walk.dst.virt.addr;
u8 *tsrc = walk.src.virt.addr;
blocks = -1;
ce_aes_ctr_encrypt(tail, NULL, (u8 *)ctx->key_enc,
num_rounds(ctx), blocks, walk.iv);
crypto_xor_cpy(tdst, tsrc, tail, nbytes);
err = skcipher_walk_done(&walk, 0);
}
kernel_neon_end();
return err;
}
static int xts_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = num_rounds(&ctx->key1);
struct skcipher_walk walk;
unsigned int blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
ce_aes_xts_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key1.key_enc, rounds, blocks,
walk.iv, (u8 *)ctx->key2.key_enc, first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int xts_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = num_rounds(&ctx->key1);
struct skcipher_walk walk;
unsigned int blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
ce_aes_xts_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key1.key_dec, rounds, blocks,
walk.iv, (u8 *)ctx->key2.key_enc, first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static void aes_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(aes_simd_algs) && aes_simd_algs[i]; i++)
simd_skcipher_free(aes_simd_algs[i]);
crypto_unregister_skciphers(aes_algs, ARRAY_SIZE(aes_algs));
}
static int __init aes_init(void)
{
struct simd_skcipher_alg *simd;
const char *basename;
const char *algname;
const char *drvname;
int err;
int i;
err = crypto_register_skciphers(aes_algs, ARRAY_SIZE(aes_algs));
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(aes_algs); i++) {
algname = aes_algs[i].base.cra_name + 2;
drvname = aes_algs[i].base.cra_driver_name + 2;
basename = aes_algs[i].base.cra_driver_name;
simd = simd_skcipher_create_compat(algname, drvname, basename);
err = PTR_ERR(simd);
if (IS_ERR(simd))
goto unregister_simds;
aes_simd_algs[i] = simd;
}
return 0;
unregister_simds:
aes_exit();
return err;
}
