static void encrypt_to_decrypt(u64 *d, const u64 *e)
{
const u64 *s = e + (DES_EXPKEY_WORDS / 2) - 1;
int i;
for (i = 0; i < DES_EXPKEY_WORDS / 2; i++)
*d++ = *s--;
}
static int des_set_key(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct des_sparc64_ctx *dctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
u32 tmp[DES_EXPKEY_WORDS];
int ret;
ret = des_ekey(tmp, key);
if (unlikely(ret == 0) && (*flags & CRYPTO_TFM_REQ_WEAK_KEY)) {
*flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
des_sparc64_key_expand((const u32 *) key, &dctx->encrypt_expkey[0]);
encrypt_to_decrypt(&dctx->decrypt_expkey[0], &dctx->encrypt_expkey[0]);
return 0;
}
static void des_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct des_sparc64_ctx *ctx = crypto_tfm_ctx(tfm);
const u64 *K = ctx->encrypt_expkey;
des_sparc64_crypt(K, (const u64 *) src, (u64 *) dst);
}
static void des_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct des_sparc64_ctx *ctx = crypto_tfm_ctx(tfm);
const u64 *K = ctx->decrypt_expkey;
des_sparc64_crypt(K, (const u64 *) src, (u64 *) dst);
}
static int __ecb_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes, bool encrypt)
{
struct des_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
if (encrypt)
des_sparc64_load_keys(&ctx->encrypt_expkey[0]);
else
des_sparc64_load_keys(&ctx->decrypt_expkey[0]);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & DES_BLOCK_MASK;
if (likely(block_len)) {
des_sparc64_ecb_crypt((const u64 *)walk.src.virt.addr,
(u64 *) walk.dst.virt.addr,
block_len);
}
nbytes &= DES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int ecb_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
return __ecb_crypt(desc, dst, src, nbytes, true);
}
static int ecb_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
return __ecb_crypt(desc, dst, src, nbytes, false);
}
static int cbc_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct des_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
des_sparc64_load_keys(&ctx->encrypt_expkey[0]);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & DES_BLOCK_MASK;
if (likely(block_len)) {
des_sparc64_cbc_encrypt((const u64 *)walk.src.virt.addr,
(u64 *) walk.dst.virt.addr,
block_len, (u64 *) walk.iv);
}
nbytes &= DES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int cbc_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct des_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
des_sparc64_load_keys(&ctx->decrypt_expkey[0]);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & DES_BLOCK_MASK;
if (likely(block_len)) {
des_sparc64_cbc_decrypt((const u64 *)walk.src.virt.addr,
(u64 *) walk.dst.virt.addr,
block_len, (u64 *) walk.iv);
}
nbytes &= DES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int des3_ede_set_key(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct des3_ede_sparc64_ctx *dctx = crypto_tfm_ctx(tfm);
const u32 *K = (const u32 *)key;
u32 *flags = &tfm->crt_flags;
u64 k1[DES_EXPKEY_WORDS / 2];
u64 k2[DES_EXPKEY_WORDS / 2];
u64 k3[DES_EXPKEY_WORDS / 2];
if (unlikely(!((K[0] ^ K[2]) | (K[1] ^ K[3])) ||
!((K[2] ^ K[4]) | (K[3] ^ K[5]))) &&
(*flags & CRYPTO_TFM_REQ_WEAK_KEY)) {
*flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
des_sparc64_key_expand((const u32 *)key, k1);
key += DES_KEY_SIZE;
des_sparc64_key_expand((const u32 *)key, k2);
key += DES_KEY_SIZE;
des_sparc64_key_expand((const u32 *)key, k3);
memcpy(&dctx->encrypt_expkey[0], &k1[0], sizeof(k1));
encrypt_to_decrypt(&dctx->encrypt_expkey[DES_EXPKEY_WORDS / 2], &k2[0]);
memcpy(&dctx->encrypt_expkey[(DES_EXPKEY_WORDS / 2) * 2],
&k3[0], sizeof(k3));
encrypt_to_decrypt(&dctx->decrypt_expkey[0], &k3[0]);
memcpy(&dctx->decrypt_expkey[DES_EXPKEY_WORDS / 2],
&k2[0], sizeof(k2));
encrypt_to_decrypt(&dctx->decrypt_expkey[(DES_EXPKEY_WORDS / 2) * 2],
&k1[0]);
return 0;
}
static void des3_ede_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct des3_ede_sparc64_ctx *ctx = crypto_tfm_ctx(tfm);
const u64 *K = ctx->encrypt_expkey;
des3_ede_sparc64_crypt(K, (const u64 *) src, (u64 *) dst);
}
static void des3_ede_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct des3_ede_sparc64_ctx *ctx = crypto_tfm_ctx(tfm);
const u64 *K = ctx->decrypt_expkey;
des3_ede_sparc64_crypt(K, (const u64 *) src, (u64 *) dst);
}
static int __ecb3_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes, bool encrypt)
{
struct des3_ede_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
const u64 *K;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
if (encrypt)
K = &ctx->encrypt_expkey[0];
else
K = &ctx->decrypt_expkey[0];
des3_ede_sparc64_load_keys(K);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & DES_BLOCK_MASK;
if (likely(block_len)) {
const u64 *src64 = (const u64 *)walk.src.virt.addr;
des3_ede_sparc64_ecb_crypt(K, src64,
(u64 *) walk.dst.virt.addr,
block_len);
}
nbytes &= DES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int ecb3_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
return __ecb3_crypt(desc, dst, src, nbytes, true);
}
static int ecb3_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
return __ecb3_crypt(desc, dst, src, nbytes, false);
}
static int cbc3_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct des3_ede_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
const u64 *K;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
K = &ctx->encrypt_expkey[0];
des3_ede_sparc64_load_keys(K);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & DES_BLOCK_MASK;
if (likely(block_len)) {
const u64 *src64 = (const u64 *)walk.src.virt.addr;
des3_ede_sparc64_cbc_encrypt(K, src64,
(u64 *) walk.dst.virt.addr,
block_len,
(u64 *) walk.iv);
}
nbytes &= DES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int cbc3_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct des3_ede_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
const u64 *K;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
K = &ctx->decrypt_expkey[0];
des3_ede_sparc64_load_keys(K);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & DES_BLOCK_MASK;
if (likely(block_len)) {
const u64 *src64 = (const u64 *)walk.src.virt.addr;
des3_ede_sparc64_cbc_decrypt(K, src64,
(u64 *) walk.dst.virt.addr,
block_len,
(u64 *) walk.iv);
}
nbytes &= DES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static bool __init sparc64_has_des_opcode(void)
{
unsigned long cfr;
if (!(sparc64_elf_hwcap & HWCAP_SPARC_CRYPTO))
return false;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if (!(cfr & CFR_DES))
return false;
return true;
}
static int __init des_sparc64_mod_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(algs); i++)
INIT_LIST_HEAD(&algs[i].cra_list);
if (sparc64_has_des_opcode()) {
pr_info("Using sparc64 des opcodes optimized DES implementation\n");
return crypto_register_algs(algs, ARRAY_SIZE(algs));
}
pr_info("sparc64 des opcodes not available.\n");
return -ENODEV;
}
static void __exit des_sparc64_mod_fini(void)
{
crypto_unregister_algs(algs, ARRAY_SIZE(algs));
}
