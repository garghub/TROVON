static int sha512_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
if (!irq_fpu_usable() ||
(sctx->count[0] % SHA512_BLOCK_SIZE) + len < SHA512_BLOCK_SIZE)
return crypto_sha512_update(desc, data, len);
BUILD_BUG_ON(offsetof(struct sha512_state, state) != 0);
kernel_fpu_begin();
sha512_base_do_update(desc, data, len,
(sha512_block_fn *)sha512_transform_asm);
kernel_fpu_end();
return 0;
}
static int sha512_ssse3_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
if (!irq_fpu_usable())
return crypto_sha512_finup(desc, data, len, out);
kernel_fpu_begin();
if (len)
sha512_base_do_update(desc, data, len,
(sha512_block_fn *)sha512_transform_asm);
sha512_base_do_finalize(desc, (sha512_block_fn *)sha512_transform_asm);
kernel_fpu_end();
return sha512_base_finish(desc, out);
}
static int sha512_ssse3_final(struct shash_desc *desc, u8 *out)
{
return sha512_ssse3_finup(desc, NULL, 0, out);
}
static bool __init avx_usable(void)
{
if (!cpu_has_xfeatures(XSTATE_SSE | XSTATE_YMM, NULL)) {
if (cpu_has_avx)
pr_info("AVX detected but unusable.\n");
return false;
}
return true;
}
static int __init sha512_ssse3_mod_init(void)
{
if (cpu_has_ssse3)
sha512_transform_asm = sha512_transform_ssse3;
#ifdef CONFIG_AS_AVX
if (avx_usable()) {
#ifdef CONFIG_AS_AVX2
if (boot_cpu_has(X86_FEATURE_AVX2))
sha512_transform_asm = sha512_transform_rorx;
else
#endif
sha512_transform_asm = sha512_transform_avx;
}
#endif
if (sha512_transform_asm) {
#ifdef CONFIG_AS_AVX
if (sha512_transform_asm == sha512_transform_avx)
pr_info("Using AVX optimized SHA-512 implementation\n");
#ifdef CONFIG_AS_AVX2
else if (sha512_transform_asm == sha512_transform_rorx)
pr_info("Using AVX2 optimized SHA-512 implementation\n");
#endif
else
#endif
pr_info("Using SSSE3 optimized SHA-512 implementation\n");
return crypto_register_shashes(algs, ARRAY_SIZE(algs));
}
pr_info("Neither AVX nor SSSE3 is available/usable.\n");
return -ENODEV;
}
static void __exit sha512_ssse3_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
