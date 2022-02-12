static int aesbs_cbc_set_key(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
int bits = key_len * 8;
if (private_AES_set_encrypt_key(in_key, bits, &ctx->enc)) {
crypto_skcipher_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
ctx->dec.rk = ctx->enc;
private_AES_set_decrypt_key(in_key, bits, &ctx->dec.rk);
ctx->dec.converted = 0;
return 0;
}
static int aesbs_ctr_set_key(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_ctr_ctx *ctx = crypto_skcipher_ctx(tfm);
int bits = key_len * 8;
if (private_AES_set_encrypt_key(in_key, bits, &ctx->enc.rk)) {
crypto_skcipher_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
ctx->enc.converted = 0;
return 0;
}
static int aesbs_xts_set_key(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int bits = key_len * 4;
int err;
err = xts_verify_key(tfm, in_key, key_len);
if (err)
return err;
if (private_AES_set_encrypt_key(in_key, bits, &ctx->enc.rk)) {
crypto_skcipher_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
ctx->dec.rk = ctx->enc.rk;
private_AES_set_decrypt_key(in_key, bits, &ctx->dec.rk);
private_AES_set_encrypt_key(in_key + key_len / 2, bits, &ctx->twkey);
ctx->enc.converted = ctx->dec.converted = 0;
return 0;
}
static inline void aesbs_encrypt_one(struct crypto_skcipher *tfm,
const u8 *src, u8 *dst)
{
struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
AES_encrypt(src, dst, &ctx->enc);
}
static int aesbs_cbc_encrypt(struct skcipher_request *req)
{
return crypto_cbc_encrypt_walk(req, aesbs_encrypt_one);
}
static inline void aesbs_decrypt_one(struct crypto_skcipher *tfm,
const u8 *src, u8 *dst)
{
struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
AES_decrypt(src, dst, &ctx->dec.rk);
}
static int aesbs_cbc_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
unsigned int nbytes;
int err;
for (err = skcipher_walk_virt(&walk, req, false);
(nbytes = walk.nbytes); err = skcipher_walk_done(&walk, nbytes)) {
u32 blocks = nbytes / AES_BLOCK_SIZE;
u8 *dst = walk.dst.virt.addr;
u8 *src = walk.src.virt.addr;
u8 *iv = walk.iv;
if (blocks >= 8) {
kernel_neon_begin();
bsaes_cbc_encrypt(src, dst, nbytes, &ctx->dec, iv);
kernel_neon_end();
nbytes %= AES_BLOCK_SIZE;
continue;
}
nbytes = crypto_cbc_decrypt_blocks(&walk, tfm,
aesbs_decrypt_one);
}
return err;
}
static void inc_be128_ctr(__be32 ctr[], u32 addend)
{
int i;
for (i = 3; i >= 0; i--, addend = 1) {
u32 n = be32_to_cpu(ctr[i]) + addend;
ctr[i] = cpu_to_be32(n);
if (n >= addend)
break;
}
}
static int aesbs_ctr_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesbs_ctr_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
u32 blocks;
int err;
err = skcipher_walk_virt(&walk, req, false);
while ((blocks = walk.nbytes / AES_BLOCK_SIZE)) {
u32 tail = walk.nbytes % AES_BLOCK_SIZE;
__be32 *ctr = (__be32 *)walk.iv;
u32 headroom = UINT_MAX - be32_to_cpu(ctr[3]);
if (unlikely(headroom < blocks)) {
blocks = headroom + 1;
tail = walk.nbytes - blocks * AES_BLOCK_SIZE;
}
kernel_neon_begin();
bsaes_ctr32_encrypt_blocks(walk.src.virt.addr,
walk.dst.virt.addr, blocks,
&ctx->enc, walk.iv);
kernel_neon_end();
inc_be128_ctr(ctr, blocks);
err = skcipher_walk_done(&walk, tail);
}
if (walk.nbytes) {
u8 *tdst = walk.dst.virt.addr + blocks * AES_BLOCK_SIZE;
u8 *tsrc = walk.src.virt.addr + blocks * AES_BLOCK_SIZE;
u8 ks[AES_BLOCK_SIZE];
AES_encrypt(walk.iv, ks, &ctx->enc.rk);
if (tdst != tsrc)
memcpy(tdst, tsrc, walk.nbytes);
crypto_xor(tdst, ks, walk.nbytes);
err = skcipher_walk_done(&walk, 0);
}
return err;
}
static int aesbs_xts_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesbs_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
int err;
err = skcipher_walk_virt(&walk, req, false);
AES_encrypt(walk.iv, walk.iv, &ctx->twkey);
while (walk.nbytes) {
kernel_neon_begin();
bsaes_xts_encrypt(walk.src.virt.addr, walk.dst.virt.addr,
walk.nbytes, &ctx->enc, walk.iv);
kernel_neon_end();
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
return err;
}
static int aesbs_xts_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesbs_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
struct skcipher_walk walk;
int err;
err = skcipher_walk_virt(&walk, req, false);
AES_encrypt(walk.iv, walk.iv, &ctx->twkey);
while (walk.nbytes) {
kernel_neon_begin();
bsaes_xts_decrypt(walk.src.virt.addr, walk.dst.virt.addr,
walk.nbytes, &ctx->dec, walk.iv);
kernel_neon_end();
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
return err;
}
static void aesbs_mod_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(aesbs_simd_algs) && aesbs_simd_algs[i]; i++)
simd_skcipher_free(aesbs_simd_algs[i]);
crypto_unregister_skciphers(aesbs_algs, ARRAY_SIZE(aesbs_algs));
}
static int __init aesbs_mod_init(void)
{
struct simd_skcipher_alg *simd;
const char *basename;
const char *algname;
const char *drvname;
int err;
int i;
if (!cpu_has_neon())
return -ENODEV;
err = crypto_register_skciphers(aesbs_algs, ARRAY_SIZE(aesbs_algs));
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(aesbs_algs); i++) {
algname = aesbs_algs[i].base.cra_name + 2;
drvname = aesbs_algs[i].base.cra_driver_name + 2;
basename = aesbs_algs[i].base.cra_driver_name;
simd = simd_skcipher_create_compat(algname, drvname, basename);
err = PTR_ERR(simd);
if (IS_ERR(simd))
goto unregister_simds;
aesbs_simd_algs[i] = simd;
}
return 0;
unregister_simds:
aesbs_mod_exit();
return err;
}
