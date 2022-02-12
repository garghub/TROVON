static inline int
aes_hw_extkey_available(uint8_t key_len)
{
if (key_len == 16)
return 1;
return 0;
}
static inline struct aes_ctx *aes_ctx_common(void *ctx)
{
unsigned long addr = (unsigned long)ctx;
unsigned long align = PADLOCK_ALIGNMENT;
if (align <= crypto_tfm_ctx_alignment())
align = 1;
return (struct aes_ctx *)ALIGN(addr, align);
}
static inline struct aes_ctx *aes_ctx(struct crypto_tfm *tfm)
{
return aes_ctx_common(crypto_tfm_ctx(tfm));
}
static inline struct aes_ctx *blk_aes_ctx(struct crypto_blkcipher *tfm)
{
return aes_ctx_common(crypto_blkcipher_ctx(tfm));
}
static int aes_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aes_ctx *ctx = aes_ctx(tfm);
const __le32 *key = (const __le32 *)in_key;
u32 *flags = &tfm->crt_flags;
struct crypto_aes_ctx gen_aes;
int cpu;
if (key_len % 8) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
ctx->D = ctx->E;
ctx->E[0] = le32_to_cpu(key[0]);
ctx->E[1] = le32_to_cpu(key[1]);
ctx->E[2] = le32_to_cpu(key[2]);
ctx->E[3] = le32_to_cpu(key[3]);
memset(&ctx->cword, 0, sizeof(ctx->cword));
ctx->cword.decrypt.encdec = 1;
ctx->cword.encrypt.rounds = 10 + (key_len - 16) / 4;
ctx->cword.decrypt.rounds = ctx->cword.encrypt.rounds;
ctx->cword.encrypt.ksize = (key_len - 16) / 8;
ctx->cword.decrypt.ksize = ctx->cword.encrypt.ksize;
if (aes_hw_extkey_available(key_len))
goto ok;
ctx->D = ctx->d_data;
ctx->cword.encrypt.keygen = 1;
ctx->cword.decrypt.keygen = 1;
if (crypto_aes_expand_key(&gen_aes, in_key, key_len)) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
memcpy(ctx->E, gen_aes.key_enc, AES_MAX_KEYLENGTH);
memcpy(ctx->D, gen_aes.key_dec, AES_MAX_KEYLENGTH);
ok:
for_each_online_cpu(cpu)
if (&ctx->cword.encrypt == per_cpu(paes_last_cword, cpu) ||
&ctx->cword.decrypt == per_cpu(paes_last_cword, cpu))
per_cpu(paes_last_cword, cpu) = NULL;
return 0;
}
static inline void padlock_reset_key(struct cword *cword)
{
int cpu = raw_smp_processor_id();
if (cword != per_cpu(paes_last_cword, cpu))
#ifndef CONFIG_X86_64
asm volatile ("pushfl; popfl");
#else
asm volatile ("pushfq; popfq");
#endif
}
static inline void padlock_store_cword(struct cword *cword)
{
per_cpu(paes_last_cword, raw_smp_processor_id()) = cword;
}
static inline void rep_xcrypt_ecb(const u8 *input, u8 *output, void *key,
struct cword *control_word, int count)
{
asm volatile (".byte 0xf3,0x0f,0xa7,0xc8"
: "+S"(input), "+D"(output)
: "d"(control_word), "b"(key), "c"(count));
}
static inline u8 *rep_xcrypt_cbc(const u8 *input, u8 *output, void *key,
u8 *iv, struct cword *control_word, int count)
{
asm volatile (".byte 0xf3,0x0f,0xa7,0xd0"
: "+S" (input), "+D" (output), "+a" (iv)
: "d" (control_word), "b" (key), "c" (count));
return iv;
}
static void ecb_crypt_copy(const u8 *in, u8 *out, u32 *key,
struct cword *cword, int count)
{
u8 buf[AES_BLOCK_SIZE * (MAX_ECB_FETCH_BLOCKS - 1) + PADLOCK_ALIGNMENT - 1];
u8 *tmp = PTR_ALIGN(&buf[0], PADLOCK_ALIGNMENT);
memcpy(tmp, in, count * AES_BLOCK_SIZE);
rep_xcrypt_ecb(tmp, out, key, cword, count);
}
static u8 *cbc_crypt_copy(const u8 *in, u8 *out, u32 *key,
u8 *iv, struct cword *cword, int count)
{
u8 buf[AES_BLOCK_SIZE * (MAX_CBC_FETCH_BLOCKS - 1) + PADLOCK_ALIGNMENT - 1];
u8 *tmp = PTR_ALIGN(&buf[0], PADLOCK_ALIGNMENT);
memcpy(tmp, in, count * AES_BLOCK_SIZE);
return rep_xcrypt_cbc(tmp, out, key, iv, cword, count);
}
static inline void ecb_crypt(const u8 *in, u8 *out, u32 *key,
struct cword *cword, int count)
{
if (unlikely(offset_in_page(in) + ecb_fetch_bytes > PAGE_SIZE)) {
ecb_crypt_copy(in, out, key, cword, count);
return;
}
rep_xcrypt_ecb(in, out, key, cword, count);
}
static inline u8 *cbc_crypt(const u8 *in, u8 *out, u32 *key,
u8 *iv, struct cword *cword, int count)
{
if (unlikely(offset_in_page(in) + cbc_fetch_bytes > PAGE_SIZE))
return cbc_crypt_copy(in, out, key, iv, cword, count);
return rep_xcrypt_cbc(in, out, key, iv, cword, count);
}
static inline void padlock_xcrypt_ecb(const u8 *input, u8 *output, void *key,
void *control_word, u32 count)
{
u32 initial = count & (ecb_fetch_blocks - 1);
if (count < ecb_fetch_blocks) {
ecb_crypt(input, output, key, control_word, count);
return;
}
if (initial)
asm volatile (".byte 0xf3,0x0f,0xa7,0xc8"
: "+S"(input), "+D"(output)
: "d"(control_word), "b"(key), "c"(initial));
asm volatile (".byte 0xf3,0x0f,0xa7,0xc8"
: "+S"(input), "+D"(output)
: "d"(control_word), "b"(key), "c"(count - initial));
}
static inline u8 *padlock_xcrypt_cbc(const u8 *input, u8 *output, void *key,
u8 *iv, void *control_word, u32 count)
{
u32 initial = count & (cbc_fetch_blocks - 1);
if (count < cbc_fetch_blocks)
return cbc_crypt(input, output, key, iv, control_word, count);
if (initial)
asm volatile (".byte 0xf3,0x0f,0xa7,0xd0"
: "+S" (input), "+D" (output), "+a" (iv)
: "d" (control_word), "b" (key), "c" (initial));
asm volatile (".byte 0xf3,0x0f,0xa7,0xd0"
: "+S" (input), "+D" (output), "+a" (iv)
: "d" (control_word), "b" (key), "c" (count-initial));
return iv;
}
static void aes_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct aes_ctx *ctx = aes_ctx(tfm);
int ts_state;
padlock_reset_key(&ctx->cword.encrypt);
ts_state = irq_ts_save();
ecb_crypt(in, out, ctx->E, &ctx->cword.encrypt, 1);
irq_ts_restore(ts_state);
padlock_store_cword(&ctx->cword.encrypt);
}
static void aes_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct aes_ctx *ctx = aes_ctx(tfm);
int ts_state;
padlock_reset_key(&ctx->cword.encrypt);
ts_state = irq_ts_save();
ecb_crypt(in, out, ctx->D, &ctx->cword.decrypt, 1);
irq_ts_restore(ts_state);
padlock_store_cword(&ctx->cword.encrypt);
}
static int ecb_aes_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct aes_ctx *ctx = blk_aes_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
int ts_state;
padlock_reset_key(&ctx->cword.encrypt);
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
ts_state = irq_ts_save();
while ((nbytes = walk.nbytes)) {
padlock_xcrypt_ecb(walk.src.virt.addr, walk.dst.virt.addr,
ctx->E, &ctx->cword.encrypt,
nbytes / AES_BLOCK_SIZE);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
irq_ts_restore(ts_state);
padlock_store_cword(&ctx->cword.encrypt);
return err;
}
static int ecb_aes_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct aes_ctx *ctx = blk_aes_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
int ts_state;
padlock_reset_key(&ctx->cword.decrypt);
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
ts_state = irq_ts_save();
while ((nbytes = walk.nbytes)) {
padlock_xcrypt_ecb(walk.src.virt.addr, walk.dst.virt.addr,
ctx->D, &ctx->cword.decrypt,
nbytes / AES_BLOCK_SIZE);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
irq_ts_restore(ts_state);
padlock_store_cword(&ctx->cword.encrypt);
return err;
}
static int cbc_aes_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct aes_ctx *ctx = blk_aes_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
int ts_state;
padlock_reset_key(&ctx->cword.encrypt);
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
ts_state = irq_ts_save();
while ((nbytes = walk.nbytes)) {
u8 *iv = padlock_xcrypt_cbc(walk.src.virt.addr,
walk.dst.virt.addr, ctx->E,
walk.iv, &ctx->cword.encrypt,
nbytes / AES_BLOCK_SIZE);
memcpy(walk.iv, iv, AES_BLOCK_SIZE);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
irq_ts_restore(ts_state);
padlock_store_cword(&ctx->cword.decrypt);
return err;
}
static int cbc_aes_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct aes_ctx *ctx = blk_aes_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
int ts_state;
padlock_reset_key(&ctx->cword.encrypt);
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
ts_state = irq_ts_save();
while ((nbytes = walk.nbytes)) {
padlock_xcrypt_cbc(walk.src.virt.addr, walk.dst.virt.addr,
ctx->D, walk.iv, &ctx->cword.decrypt,
nbytes / AES_BLOCK_SIZE);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
irq_ts_restore(ts_state);
padlock_store_cword(&ctx->cword.encrypt);
return err;
}
static int __init padlock_init(void)
{
int ret;
struct cpuinfo_x86 *c = &cpu_data(0);
if (!x86_match_cpu(padlock_cpu_id))
return -ENODEV;
if (!boot_cpu_has(X86_FEATURE_XCRYPT_EN)) {
printk(KERN_NOTICE PFX "VIA PadLock detected, but not enabled. Hmm, strange...\n");
return -ENODEV;
}
if ((ret = crypto_register_alg(&aes_alg)))
goto aes_err;
if ((ret = crypto_register_alg(&ecb_aes_alg)))
goto ecb_aes_err;
if ((ret = crypto_register_alg(&cbc_aes_alg)))
goto cbc_aes_err;
printk(KERN_NOTICE PFX "Using VIA PadLock ACE for AES algorithm.\n");
if (c->x86 == 6 && c->x86_model == 15 && c->x86_mask == 2) {
ecb_fetch_blocks = MAX_ECB_FETCH_BLOCKS;
cbc_fetch_blocks = MAX_CBC_FETCH_BLOCKS;
printk(KERN_NOTICE PFX "VIA Nano stepping 2 detected: enabling workaround.\n");
}
out:
return ret;
cbc_aes_err:
crypto_unregister_alg(&ecb_aes_alg);
ecb_aes_err:
crypto_unregister_alg(&aes_alg);
aes_err:
printk(KERN_ERR PFX "VIA PadLock AES initialization failed.\n");
goto out;
}
static void __exit padlock_fini(void)
{
crypto_unregister_alg(&cbc_aes_alg);
crypto_unregister_alg(&ecb_aes_alg);
crypto_unregister_alg(&aes_alg);
}
