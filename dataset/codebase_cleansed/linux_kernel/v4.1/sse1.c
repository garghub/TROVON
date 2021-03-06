static int raid6_have_sse1_or_mmxext(void)
{
return boot_cpu_has(X86_FEATURE_MMX) &&
(boot_cpu_has(X86_FEATURE_XMM) ||
boot_cpu_has(X86_FEATURE_MMXEXT));
}
static void raid6_sse11_gen_syndrome(int disks, size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = disks - 3;
p = dptr[z0+1];
q = dptr[z0+2];
kernel_fpu_begin();
asm volatile("movq %0,%%mm0" : : "m" (raid6_mmx_constants.x1d));
asm volatile("pxor %mm5,%mm5");
for ( d = 0 ; d < bytes ; d += 8 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("movq %0,%%mm2" : : "m" (dptr[z0][d]));
asm volatile("prefetchnta %0" : : "m" (dptr[z0-1][d]));
asm volatile("movq %mm2,%mm4");
asm volatile("movq %0,%%mm6" : : "m" (dptr[z0-1][d]));
for ( z = z0-2 ; z >= 0 ; z-- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("pcmpgtb %mm4,%mm5");
asm volatile("paddb %mm4,%mm4");
asm volatile("pand %mm0,%mm5");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm6,%mm2");
asm volatile("pxor %mm6,%mm4");
asm volatile("movq %0,%%mm6" : : "m" (dptr[z][d]));
}
asm volatile("pcmpgtb %mm4,%mm5");
asm volatile("paddb %mm4,%mm4");
asm volatile("pand %mm0,%mm5");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm6,%mm2");
asm volatile("pxor %mm6,%mm4");
asm volatile("movntq %%mm2,%0" : "=m" (p[d]));
asm volatile("movntq %%mm4,%0" : "=m" (q[d]));
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
static void raid6_sse12_gen_syndrome(int disks, size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = disks - 3;
p = dptr[z0+1];
q = dptr[z0+2];
kernel_fpu_begin();
asm volatile("movq %0,%%mm0" : : "m" (raid6_mmx_constants.x1d));
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm7,%mm7");
for ( d = 0 ; d < bytes ; d += 16 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("movq %0,%%mm2" : : "m" (dptr[z0][d]));
asm volatile("movq %0,%%mm3" : : "m" (dptr[z0][d+8]));
asm volatile("movq %mm2,%mm4");
asm volatile("movq %mm3,%mm6");
for ( z = z0-1 ; z >= 0 ; z-- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("pcmpgtb %mm4,%mm5");
asm volatile("pcmpgtb %mm6,%mm7");
asm volatile("paddb %mm4,%mm4");
asm volatile("paddb %mm6,%mm6");
asm volatile("pand %mm0,%mm5");
asm volatile("pand %mm0,%mm7");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm7,%mm6");
asm volatile("movq %0,%%mm5" : : "m" (dptr[z][d]));
asm volatile("movq %0,%%mm7" : : "m" (dptr[z][d+8]));
asm volatile("pxor %mm5,%mm2");
asm volatile("pxor %mm7,%mm3");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm7,%mm6");
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm7,%mm7");
}
asm volatile("movntq %%mm2,%0" : "=m" (p[d]));
asm volatile("movntq %%mm3,%0" : "=m" (p[d+8]));
asm volatile("movntq %%mm4,%0" : "=m" (q[d]));
asm volatile("movntq %%mm6,%0" : "=m" (q[d+8]));
}
asm volatile("sfence" : :: "memory");
kernel_fpu_end();
}
