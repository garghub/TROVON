static int sha1_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
if (!irq_fpu_usable() ||
(sctx->count % SHA1_BLOCK_SIZE) + len < SHA1_BLOCK_SIZE)
return crypto_sha1_update(desc, data, len);
BUILD_BUG_ON(offsetof(struct sha1_state, state) != 0);
kernel_fpu_begin();
sha1_base_do_update(desc, data, len,
(sha1_block_fn *)sha1_transform_asm);
kernel_fpu_end();
return 0;
}
static int sha1_ssse3_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
if (!irq_fpu_usable())
return crypto_sha1_finup(desc, data, len, out);
kernel_fpu_begin();
if (len)
sha1_base_do_update(desc, data, len,
(sha1_block_fn *)sha1_transform_asm);
sha1_base_do_finalize(desc, (sha1_block_fn *)sha1_transform_asm);
kernel_fpu_end();
return sha1_base_finish(desc, out);
}
static int sha1_ssse3_final(struct shash_desc *desc, u8 *out)
{
return sha1_ssse3_finup(desc, NULL, 0, out);
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
