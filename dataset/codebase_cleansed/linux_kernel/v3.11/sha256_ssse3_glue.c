static int sha256_ssse3_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA256_H0;
sctx->state[1] = SHA256_H1;
sctx->state[2] = SHA256_H2;
sctx->state[3] = SHA256_H3;
sctx->state[4] = SHA256_H4;
sctx->state[5] = SHA256_H5;
sctx->state[6] = SHA256_H6;
sctx->state[7] = SHA256_H7;
sctx->count = 0;
return 0;
}
static int __sha256_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len, unsigned int partial)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
unsigned int done = 0;
sctx->count += len;
if (partial) {
done = SHA256_BLOCK_SIZE - partial;
memcpy(sctx->buf + partial, data, done);
sha256_transform_asm(sctx->buf, sctx->state, 1);
}
if (len - done >= SHA256_BLOCK_SIZE) {
const unsigned int rounds = (len - done) / SHA256_BLOCK_SIZE;
sha256_transform_asm(data + done, sctx->state, (u64) rounds);
done += rounds * SHA256_BLOCK_SIZE;
}
memcpy(sctx->buf, data + done, len - done);
return 0;
}
static int sha256_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count % SHA256_BLOCK_SIZE;
int res;
if (partial + len < SHA256_BLOCK_SIZE) {
sctx->count += len;
memcpy(sctx->buf + partial, data, len);
return 0;
}
if (!irq_fpu_usable()) {
res = crypto_sha256_update(desc, data, len);
} else {
kernel_fpu_begin();
res = __sha256_ssse3_update(desc, data, len, partial);
kernel_fpu_end();
}
return res;
}
static int sha256_ssse3_final(struct shash_desc *desc, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, padlen;
__be32 *dst = (__be32 *)out;
__be64 bits;
static const u8 padding[SHA256_BLOCK_SIZE] = { 0x80, };
bits = cpu_to_be64(sctx->count << 3);
index = sctx->count % SHA256_BLOCK_SIZE;
padlen = (index < 56) ? (56 - index) : ((SHA256_BLOCK_SIZE+56)-index);
if (!irq_fpu_usable()) {
crypto_sha256_update(desc, padding, padlen);
crypto_sha256_update(desc, (const u8 *)&bits, sizeof(bits));
} else {
kernel_fpu_begin();
if (padlen <= 56) {
sctx->count += padlen;
memcpy(sctx->buf + index, padding, padlen);
} else {
__sha256_ssse3_update(desc, padding, padlen, index);
}
__sha256_ssse3_update(desc, (const u8 *)&bits,
sizeof(bits), 56);
kernel_fpu_end();
}
for (i = 0; i < 8; i++)
dst[i] = cpu_to_be32(sctx->state[i]);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int sha256_ssse3_export(struct shash_desc *desc, void *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha256_ssse3_import(struct shash_desc *desc, const void *in)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int sha224_ssse3_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA224_H0;
sctx->state[1] = SHA224_H1;
sctx->state[2] = SHA224_H2;
sctx->state[3] = SHA224_H3;
sctx->state[4] = SHA224_H4;
sctx->state[5] = SHA224_H5;
sctx->state[6] = SHA224_H6;
sctx->state[7] = SHA224_H7;
sctx->count = 0;
return 0;
}
static int sha224_ssse3_final(struct shash_desc *desc, u8 *hash)
{
u8 D[SHA256_DIGEST_SIZE];
sha256_ssse3_final(desc, D);
memcpy(hash, D, SHA224_DIGEST_SIZE);
memset(D, 0, SHA256_DIGEST_SIZE);
return 0;
}
static bool __init avx_usable(void)
{
u64 xcr0;
if (!cpu_has_avx || !cpu_has_osxsave)
return false;
xcr0 = xgetbv(XCR_XFEATURE_ENABLED_MASK);
if ((xcr0 & (XSTATE_SSE | XSTATE_YMM)) != (XSTATE_SSE | XSTATE_YMM)) {
pr_info("AVX detected but unusable.\n");
return false;
}
return true;
}
static int __init sha256_ssse3_mod_init(void)
{
if (cpu_has_ssse3)
sha256_transform_asm = sha256_transform_ssse3;
#ifdef CONFIG_AS_AVX
if (avx_usable()) {
#ifdef CONFIG_AS_AVX2
if (boot_cpu_has(X86_FEATURE_AVX2))
sha256_transform_asm = sha256_transform_rorx;
else
#endif
sha256_transform_asm = sha256_transform_avx;
}
#endif
if (sha256_transform_asm) {
#ifdef CONFIG_AS_AVX
if (sha256_transform_asm == sha256_transform_avx)
pr_info("Using AVX optimized SHA-256 implementation\n");
#ifdef CONFIG_AS_AVX2
else if (sha256_transform_asm == sha256_transform_rorx)
pr_info("Using AVX2 optimized SHA-256 implementation\n");
#endif
else
#endif
pr_info("Using SSSE3 optimized SHA-256 implementation\n");
return crypto_register_shashes(algs, ARRAY_SIZE(algs));
}
pr_info("Neither AVX nor SSSE3 is available/usable.\n");
return -ENODEV;
}
static void __exit sha256_ssse3_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
