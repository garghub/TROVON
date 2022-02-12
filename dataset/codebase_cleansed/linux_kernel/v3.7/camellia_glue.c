static int camellia_set_key(struct crypto_tfm *tfm, const u8 *_in_key,
unsigned int key_len)
{
struct camellia_sparc64_ctx *ctx = crypto_tfm_ctx(tfm);
const u32 *in_key = (const u32 *) _in_key;
u32 *flags = &tfm->crt_flags;
if (key_len != 16 && key_len != 24 && key_len != 32) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
ctx->key_len = key_len;
camellia_sparc64_key_expand(in_key, &ctx->encrypt_key[0],
key_len, &ctx->decrypt_key[0]);
return 0;
}
static void camellia_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct camellia_sparc64_ctx *ctx = crypto_tfm_ctx(tfm);
camellia_sparc64_crypt(&ctx->encrypt_key[0],
(const u32 *) src,
(u32 *) dst, ctx->key_len);
}
static void camellia_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct camellia_sparc64_ctx *ctx = crypto_tfm_ctx(tfm);
camellia_sparc64_crypt(&ctx->decrypt_key[0],
(const u32 *) src,
(u32 *) dst, ctx->key_len);
}
static int __ecb_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes, bool encrypt)
{
struct camellia_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
ecb_crypt_op *op;
const u64 *key;
int err;
op = camellia_sparc64_ecb_crypt_3_grand_rounds;
if (ctx->key_len != 16)
op = camellia_sparc64_ecb_crypt_4_grand_rounds;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
if (encrypt)
key = &ctx->encrypt_key[0];
else
key = &ctx->decrypt_key[0];
camellia_sparc64_load_keys(key, ctx->key_len);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & CAMELLIA_BLOCK_MASK;
if (likely(block_len)) {
const u64 *src64;
u64 *dst64;
src64 = (const u64 *)walk.src.virt.addr;
dst64 = (u64 *) walk.dst.virt.addr;
op(src64, dst64, block_len, key);
}
nbytes &= CAMELLIA_BLOCK_SIZE - 1;
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
struct camellia_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
cbc_crypt_op *op;
const u64 *key;
int err;
op = camellia_sparc64_cbc_encrypt_3_grand_rounds;
if (ctx->key_len != 16)
op = camellia_sparc64_cbc_encrypt_4_grand_rounds;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
key = &ctx->encrypt_key[0];
camellia_sparc64_load_keys(key, ctx->key_len);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & CAMELLIA_BLOCK_MASK;
if (likely(block_len)) {
const u64 *src64;
u64 *dst64;
src64 = (const u64 *)walk.src.virt.addr;
dst64 = (u64 *) walk.dst.virt.addr;
op(src64, dst64, block_len, key,
(u64 *) walk.iv);
}
nbytes &= CAMELLIA_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int cbc_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct camellia_sparc64_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
cbc_crypt_op *op;
const u64 *key;
int err;
op = camellia_sparc64_cbc_decrypt_3_grand_rounds;
if (ctx->key_len != 16)
op = camellia_sparc64_cbc_decrypt_4_grand_rounds;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
key = &ctx->decrypt_key[0];
camellia_sparc64_load_keys(key, ctx->key_len);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & CAMELLIA_BLOCK_MASK;
if (likely(block_len)) {
const u64 *src64;
u64 *dst64;
src64 = (const u64 *)walk.src.virt.addr;
dst64 = (u64 *) walk.dst.virt.addr;
op(src64, dst64, block_len, key,
(u64 *) walk.iv);
}
nbytes &= CAMELLIA_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static bool __init sparc64_has_camellia_opcode(void)
{
unsigned long cfr;
if (!(sparc64_elf_hwcap & HWCAP_SPARC_CRYPTO))
return false;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if (!(cfr & CFR_CAMELLIA))
return false;
return true;
}
static int __init camellia_sparc64_mod_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(algs); i++)
INIT_LIST_HEAD(&algs[i].cra_list);
if (sparc64_has_camellia_opcode()) {
pr_info("Using sparc64 camellia opcodes optimized CAMELLIA implementation\n");
return crypto_register_algs(algs, ARRAY_SIZE(algs));
}
pr_info("sparc64 camellia opcodes not available.\n");
return -ENODEV;
}
static void __exit camellia_sparc64_mod_fini(void)
{
crypto_unregister_algs(algs, ARRAY_SIZE(algs));
}
