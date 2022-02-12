static void __memcpy_ntdqa(void *dst, const void *src, unsigned long len)
{
kernel_fpu_begin();
len >>= 4;
while (len >= 4) {
asm("movntdqa (%0), %%xmm0\n"
"movntdqa 16(%0), %%xmm1\n"
"movntdqa 32(%0), %%xmm2\n"
"movntdqa 48(%0), %%xmm3\n"
"movaps %%xmm0, (%1)\n"
"movaps %%xmm1, 16(%1)\n"
"movaps %%xmm2, 32(%1)\n"
"movaps %%xmm3, 48(%1)\n"
:: "r" (src), "r" (dst) : "memory");
src += 64;
dst += 64;
len -= 4;
}
while (len--) {
asm("movntdqa (%0), %%xmm0\n"
"movaps %%xmm0, (%1)\n"
:: "r" (src), "r" (dst) : "memory");
src += 16;
dst += 16;
}
kernel_fpu_end();
}
bool i915_memcpy_from_wc(void *dst, const void *src, unsigned long len)
{
if (unlikely(((unsigned long)dst | (unsigned long)src | len) & 15))
return false;
#ifdef CONFIG_AS_MOVNTDQA
if (static_branch_likely(&has_movntdqa)) {
if (likely(len))
__memcpy_ntdqa(dst, src, len);
return true;
}
#endif
return false;
}
void i915_memcpy_init_early(struct drm_i915_private *dev_priv)
{
if (static_cpu_has(X86_FEATURE_XMM4_1))
static_branch_enable(&has_movntdqa);
}
