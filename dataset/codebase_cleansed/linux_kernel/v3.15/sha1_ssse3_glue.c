static int sha1_ssse3_init(struct shash_desc *desc)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
*sctx = (struct sha1_state){
.state = { SHA1_H0, SHA1_H1, SHA1_H2, SHA1_H3, SHA1_H4 },
};
return 0;
}
static int __sha1_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len, unsigned int partial)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int done = 0;
sctx->count += len;
if (partial) {
done = SHA1_BLOCK_SIZE - partial;
memcpy(sctx->buffer + partial, data, done);
sha1_transform_asm(sctx->state, sctx->buffer, 1);
}
if (len - done >= SHA1_BLOCK_SIZE) {
const unsigned int rounds = (len - done) / SHA1_BLOCK_SIZE;
sha1_transform_asm(sctx->state, data + done, rounds);
done += rounds * SHA1_BLOCK_SIZE;
}
memcpy(sctx->buffer, data + done, len - done);
return 0;
}
static int sha1_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count % SHA1_BLOCK_SIZE;
int res;
if (partial + len < SHA1_BLOCK_SIZE) {
sctx->count += len;
memcpy(sctx->buffer + partial, data, len);
return 0;
}
if (!irq_fpu_usable()) {
res = crypto_sha1_update(desc, data, len);
} else {
kernel_fpu_begin();
res = __sha1_ssse3_update(desc, data, len, partial);
kernel_fpu_end();
}
return res;
}
static int sha1_ssse3_final(struct shash_desc *desc, u8 *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, padlen;
__be32 *dst = (__be32 *)out;
__be64 bits;
static const u8 padding[SHA1_BLOCK_SIZE] = { 0x80, };
bits = cpu_to_be64(sctx->count << 3);
index = sctx->count % SHA1_BLOCK_SIZE;
padlen = (index < 56) ? (56 - index) : ((SHA1_BLOCK_SIZE+56) - index);
if (!irq_fpu_usable()) {
crypto_sha1_update(desc, padding, padlen);
crypto_sha1_update(desc, (const u8 *)&bits, sizeof(bits));
} else {
kernel_fpu_begin();
if (padlen <= 56) {
sctx->count += padlen;
memcpy(sctx->buffer + index, padding, padlen);
} else {
__sha1_ssse3_update(desc, padding, padlen, index);
}
__sha1_ssse3_update(desc, (const u8 *)&bits, sizeof(bits), 56);
kernel_fpu_end();
}
for (i = 0; i < 5; i++)
dst[i] = cpu_to_be32(sctx->state[i]);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int sha1_ssse3_export(struct shash_desc *desc, void *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha1_ssse3_import(struct shash_desc *desc, const void *in)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static void sha1_apply_transform_avx2(u32 *digest, const char *data,
unsigned int rounds)
{
if (rounds >= SHA1_AVX2_BLOCK_OPTSIZE)
sha1_transform_avx2(digest, data, rounds);
else
sha1_transform_avx(digest, data, rounds);
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
static bool __init avx2_usable(void)
{
if (avx_usable() && cpu_has_avx2 && boot_cpu_has(X86_FEATURE_BMI1) &&
boot_cpu_has(X86_FEATURE_BMI2))
return true;
return false;
}
static int __init sha1_ssse3_mod_init(void)
{
char *algo_name;
if (cpu_has_ssse3) {
sha1_transform_asm = sha1_transform_ssse3;
algo_name = "SSSE3";
}
#ifdef CONFIG_AS_AVX
if (avx_usable()) {
sha1_transform_asm = sha1_transform_avx;
algo_name = "AVX";
#ifdef CONFIG_AS_AVX2
if (avx2_usable()) {
sha1_transform_asm = sha1_apply_transform_avx2;
algo_name = "AVX2";
}
#endif
}
#endif
if (sha1_transform_asm) {
pr_info("Using %s optimized SHA-1 implementation\n", algo_name);
return crypto_register_shash(&alg);
}
pr_info("Neither AVX nor AVX2 nor SSSE3 is available/usable.\n");
return -ENODEV;
}
static void __exit sha1_ssse3_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
