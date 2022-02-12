static int aesbs_setkey(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_ctx *ctx = crypto_skcipher_ctx(tfm);
struct crypto_aes_ctx rk;
int err;
err = crypto_aes_expand_key(&rk, in_key, key_len);
if (err)
return err;
ctx->rounds = 6 + key_len / 4;
kernel_neon_begin();
aesbs_convert_key(ctx->rk, rk.key_enc, ctx->rounds);
kernel_neon_end();
return 0;
}
static int __ecb_crypt(struct skcipher_request *req,
void (*fn)(u8 out[], u8 const in[], u8 const rk[],
int rounds, int blocks))
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesbs_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
while (walk.nbytes >= AES_BLOCK_SIZE) {
unsigned int blocks = walk.nbytes / AES_BLOCK_SIZE;
if (walk.nbytes < walk.total)
blocks = round_down(blocks,
walk.stride / AES_BLOCK_SIZE);
fn(walk.dst.virt.addr, walk.src.virt.addr, ctx->rk,
ctx->rounds, blocks);
err = skcipher_walk_done(&walk,
walk.nbytes - blocks * AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ecb_encrypt(struct skcipher_request *req)
{
return __ecb_crypt(req, aesbs_ecb_encrypt);
}
static int ecb_decrypt(struct skcipher_request *req)
{
return __ecb_crypt(req, aesbs_ecb_decrypt);
}
static int aesbs_cbc_setkey(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
struct crypto_aes_ctx rk;
int err;
err = crypto_aes_expand_key(&rk, in_key, key_len);
if (err)
return err;
ctx->key.rounds = 6 + key_len / 4;
kernel_neon_begin();
aesbs_convert_key(ctx->key.rk, rk.key_enc, ctx->key.rounds);
kernel_neon_end();
return crypto_cipher_setkey(ctx->enc_tfm, in_key, key_len);
}
static void cbc_encrypt_one(struct crypto_skcipher *tfm, const u8 *src, u8 *dst)
{
struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
crypto_cipher_encrypt_one(ctx->enc_tfm, dst, src);
}
static int cbc_encrypt(struct skcipher_request *req)
{
return crypto_cbc_encrypt_walk(req, cbc_encrypt_one);
}
static int cbc_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
while (walk.nbytes >= AES_BLOCK_SIZE) {
unsigned int blocks = walk.nbytes / AES_BLOCK_SIZE;
if (walk.nbytes < walk.total)
blocks = round_down(blocks,
walk.stride / AES_BLOCK_SIZE);
aesbs_cbc_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
ctx->key.rk, ctx->key.rounds, blocks,
walk.iv);
err = skcipher_walk_done(&walk,
walk.nbytes - blocks * AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_init(struct crypto_tfm *tfm)
{
struct aesbs_cbc_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->enc_tfm = crypto_alloc_cipher("aes", 0, 0);
if (IS_ERR(ctx->enc_tfm))
return PTR_ERR(ctx->enc_tfm);
return 0;
}
static void cbc_exit(struct crypto_tfm *tfm)
{
struct aesbs_cbc_ctx *ctx = crypto_tfm_ctx(tfm);
crypto_free_cipher(ctx->enc_tfm);
}
static int ctr_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesbs_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
u8 buf[AES_BLOCK_SIZE];
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
while (walk.nbytes > 0) {
unsigned int blocks = walk.nbytes / AES_BLOCK_SIZE;
u8 *final = (walk.total % AES_BLOCK_SIZE) ? buf : NULL;
if (walk.nbytes < walk.total) {
blocks = round_down(blocks,
walk.stride / AES_BLOCK_SIZE);
final = NULL;
}
aesbs_ctr_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
ctx->rk, ctx->rounds, blocks, walk.iv, final);
if (final) {
u8 *dst = walk.dst.virt.addr + blocks * AES_BLOCK_SIZE;
u8 *src = walk.src.virt.addr + blocks * AES_BLOCK_SIZE;
if (dst != src)
memcpy(dst, src, walk.total % AES_BLOCK_SIZE);
crypto_xor(dst, final, walk.total % AES_BLOCK_SIZE);
err = skcipher_walk_done(&walk, 0);
break;
}
err = skcipher_walk_done(&walk,
walk.nbytes - blocks * AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int aesbs_xts_setkey(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int err;
err = xts_verify_key(tfm, in_key, key_len);
if (err)
return err;
key_len /= 2;
err = crypto_cipher_setkey(ctx->tweak_tfm, in_key + key_len, key_len);
if (err)
return err;
return aesbs_setkey(tfm, in_key, key_len);
}
static int xts_init(struct crypto_tfm *tfm)
{
struct aesbs_xts_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->tweak_tfm = crypto_alloc_cipher("aes", 0, 0);
if (IS_ERR(ctx->tweak_tfm))
return PTR_ERR(ctx->tweak_tfm);
return 0;
}
static void xts_exit(struct crypto_tfm *tfm)
{
struct aesbs_xts_ctx *ctx = crypto_tfm_ctx(tfm);
crypto_free_cipher(ctx->tweak_tfm);
}
static int __xts_crypt(struct skcipher_request *req,
void (*fn)(u8 out[], u8 const in[], u8 const rk[],
int rounds, int blocks, u8 iv[]))
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesbs_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
int err;
err = skcipher_walk_virt(&walk, req, true);
crypto_cipher_encrypt_one(ctx->tweak_tfm, walk.iv, walk.iv);
kernel_neon_begin();
while (walk.nbytes >= AES_BLOCK_SIZE) {
unsigned int blocks = walk.nbytes / AES_BLOCK_SIZE;
if (walk.nbytes < walk.total)
blocks = round_down(blocks,
walk.stride / AES_BLOCK_SIZE);
fn(walk.dst.virt.addr, walk.src.virt.addr, ctx->key.rk,
ctx->key.rounds, blocks, walk.iv);
err = skcipher_walk_done(&walk,
walk.nbytes - blocks * AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int xts_encrypt(struct skcipher_request *req)
{
return __xts_crypt(req, aesbs_xts_encrypt);
}
static int xts_decrypt(struct skcipher_request *req)
{
return __xts_crypt(req, aesbs_xts_decrypt);
}
static void aes_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(aes_simd_algs); i++)
if (aes_simd_algs[i])
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
if (!(elf_hwcap & HWCAP_NEON))
return -ENODEV;
err = crypto_register_skciphers(aes_algs, ARRAY_SIZE(aes_algs));
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(aes_algs); i++) {
if (!(aes_algs[i].base.cra_flags & CRYPTO_ALG_INTERNAL))
continue;
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
