static int raid6_have_sse2(void)
{
return boot_cpu_has(X86_FEATURE_MMX) &&
boot_cpu_has(X86_FEATURE_FXSR) &&
boot_cpu_has(X86_FEATURE_XMM) &&
boot_cpu_has(X86_FEATURE_XMM2);
}
static void raid6_sse21_gen_syndrome(int disks, size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = disks - 3;
p = dptr[z0+1];
q = dptr[z0+2];
kernel_fpu_begin();
asm volatile("movdqa %0,%%xmm0" : : "m" (raid6_sse_constants.x1d[0]));
asm volatile("pxor %xmm5,%xmm5");
for ( d = 0 ; d < bytes ; d += 16 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm2" : : "m" (dptr[z0][d]));
asm volatile("prefetchnta %0" : : "m" (dptr[z0-1][d]));
asm volatile("movdqa %xmm2,%xmm4");
asm volatile("movdqa %0,%%xmm6" : : "m" (dptr[z0-1][d]));
for ( z = z0-2 ; z >= 0 ; z-- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("pcmpgtb %xmm4,%xmm5");
asm volatile("paddb %xmm4,%xmm4");
asm volatile("pand %xmm0,%xmm5");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm6,%xmm2");
asm volatile("pxor %xmm6,%xmm4");
asm volatile("movdqa %0,%%xmm6" : : "m" (dptr[z][d]));
}
asm volatile("pcmpgtb %xmm4,%xmm5");
asm volatile("paddb %xmm4,%xmm4");
asm volatile("pand %xmm0,%xmm5");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm6,%xmm2");
asm volatile("pxor %xmm6,%xmm4");
asm volatile("movntdq %%xmm2,%0" : "=m" (p[d]));
asm volatile("pxor %xmm2,%xmm2");
asm volatile("movntdq %%xmm4,%0" : "=m" (q[d]));
asm volatile("pxor %xmm4,%xmm4");
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
static void raid6_sse22_gen_syndrome(int disks, size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = disks - 3;
p = dptr[z0+1];
q = dptr[z0+2];
kernel_fpu_begin();
asm volatile("movdqa %0,%%xmm0" : : "m" (raid6_sse_constants.x1d[0]));
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm7,%xmm7");
for ( d = 0 ; d < bytes ; d += 32 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm2" : : "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm3" : : "m" (dptr[z0][d+16]));
asm volatile("movdqa %xmm2,%xmm4");
asm volatile("movdqa %xmm3,%xmm6");
for ( z = z0-1 ; z >= 0 ; z-- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("pcmpgtb %xmm4,%xmm5");
asm volatile("pcmpgtb %xmm6,%xmm7");
asm volatile("paddb %xmm4,%xmm4");
asm volatile("paddb %xmm6,%xmm6");
asm volatile("pand %xmm0,%xmm5");
asm volatile("pand %xmm0,%xmm7");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm7,%xmm6");
asm volatile("movdqa %0,%%xmm5" : : "m" (dptr[z][d]));
asm volatile("movdqa %0,%%xmm7" : : "m" (dptr[z][d+16]));
asm volatile("pxor %xmm5,%xmm2");
asm volatile("pxor %xmm7,%xmm3");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm7,%xmm6");
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm7,%xmm7");
}
asm volatile("movntdq %%xmm2,%0" : "=m" (p[d]));
asm volatile("movntdq %%xmm3,%0" : "=m" (p[d+16]));
asm volatile("movntdq %%xmm4,%0" : "=m" (q[d]));
asm volatile("movntdq %%xmm6,%0" : "=m" (q[d+16]));
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
static void raid6_sse24_gen_syndrome(int disks, size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = disks - 3;
p = dptr[z0+1];
q = dptr[z0+2];
kernel_fpu_begin();
asm volatile("movdqa %0,%%xmm0" :: "m" (raid6_sse_constants.x1d[0]));
asm volatile("pxor %xmm2,%xmm2");
asm volatile("pxor %xmm3,%xmm3");
asm volatile("pxor %xmm4,%xmm4");
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm6,%xmm6");
asm volatile("pxor %xmm7,%xmm7");
asm volatile("pxor %xmm10,%xmm10");
asm volatile("pxor %xmm11,%xmm11");
asm volatile("pxor %xmm12,%xmm12");
asm volatile("pxor %xmm13,%xmm13");
asm volatile("pxor %xmm14,%xmm14");
asm volatile("pxor %xmm15,%xmm15");
for ( d = 0 ; d < bytes ; d += 64 ) {
for ( z = z0 ; z >= 0 ; z-- ) {
asm volatile("prefetchnta %0" :: "m" (dptr[z][d]));
asm volatile("prefetchnta %0" :: "m" (dptr[z][d+32]));
asm volatile("pcmpgtb %xmm4,%xmm5");
asm volatile("pcmpgtb %xmm6,%xmm7");
asm volatile("pcmpgtb %xmm12,%xmm13");
asm volatile("pcmpgtb %xmm14,%xmm15");
asm volatile("paddb %xmm4,%xmm4");
asm volatile("paddb %xmm6,%xmm6");
asm volatile("paddb %xmm12,%xmm12");
asm volatile("paddb %xmm14,%xmm14");
asm volatile("pand %xmm0,%xmm5");
asm volatile("pand %xmm0,%xmm7");
asm volatile("pand %xmm0,%xmm13");
asm volatile("pand %xmm0,%xmm15");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm7,%xmm6");
asm volatile("pxor %xmm13,%xmm12");
asm volatile("pxor %xmm15,%xmm14");
asm volatile("movdqa %0,%%xmm5" :: "m" (dptr[z][d]));
asm volatile("movdqa %0,%%xmm7" :: "m" (dptr[z][d+16]));
asm volatile("movdqa %0,%%xmm13" :: "m" (dptr[z][d+32]));
asm volatile("movdqa %0,%%xmm15" :: "m" (dptr[z][d+48]));
asm volatile("pxor %xmm5,%xmm2");
asm volatile("pxor %xmm7,%xmm3");
asm volatile("pxor %xmm13,%xmm10");
asm volatile("pxor %xmm15,%xmm11");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm7,%xmm6");
asm volatile("pxor %xmm13,%xmm12");
asm volatile("pxor %xmm15,%xmm14");
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm7,%xmm7");
asm volatile("pxor %xmm13,%xmm13");
asm volatile("pxor %xmm15,%xmm15");
}
asm volatile("movntdq %%xmm2,%0" : "=m" (p[d]));
asm volatile("pxor %xmm2,%xmm2");
asm volatile("movntdq %%xmm3,%0" : "=m" (p[d+16]));
asm volatile("pxor %xmm3,%xmm3");
asm volatile("movntdq %%xmm10,%0" : "=m" (p[d+32]));
asm volatile("pxor %xmm10,%xmm10");
asm volatile("movntdq %%xmm11,%0" : "=m" (p[d+48]));
asm volatile("pxor %xmm11,%xmm11");
asm volatile("movntdq %%xmm4,%0" : "=m" (q[d]));
asm volatile("pxor %xmm4,%xmm4");
asm volatile("movntdq %%xmm6,%0" : "=m" (q[d+16]));
asm volatile("pxor %xmm6,%xmm6");
asm volatile("movntdq %%xmm12,%0" : "=m" (q[d+32]));
asm volatile("pxor %xmm12,%xmm12");
asm volatile("movntdq %%xmm14,%0" : "=m" (q[d+48]));
asm volatile("pxor %xmm14,%xmm14");
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
