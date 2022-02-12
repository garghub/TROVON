static int raid6_have_avx512(void)
{
return boot_cpu_has(X86_FEATURE_AVX2) &&
boot_cpu_has(X86_FEATURE_AVX) &&
boot_cpu_has(X86_FEATURE_AVX512F) &&
boot_cpu_has(X86_FEATURE_AVX512BW) &&
boot_cpu_has(X86_FEATURE_AVX512VL) &&
boot_cpu_has(X86_FEATURE_AVX512DQ);
}
static void raid6_avx5121_gen_syndrome(int disks, size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = disks - 3;
p = dptr[z0+1];
q = dptr[z0+2];
kernel_fpu_begin();
asm volatile("vmovdqa64 %0,%%zmm0\n\t"
"vpxorq %%zmm1,%%zmm1,%%zmm1"
:
: "m" (raid6_avx512_constants.x1d[0]));
for (d = 0; d < bytes; d += 64) {
asm volatile("prefetchnta %0\n\t"
"vmovdqa64 %0,%%zmm2\n\t"
"prefetchnta %1\n\t"
"vmovdqa64 %%zmm2,%%zmm4\n\t"
"vmovdqa64 %1,%%zmm6"
:
: "m" (dptr[z0][d]), "m" (dptr[z0-1][d]));
for (z = z0-2; z >= 0; z--) {
asm volatile("prefetchnta %0\n\t"
"vpcmpgtb %%zmm4,%%zmm1,%%k1\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm6,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm6,%%zmm4,%%zmm4\n\t"
"vmovdqa64 %0,%%zmm6"
:
: "m" (dptr[z][d]));
}
asm volatile("vpcmpgtb %%zmm4,%%zmm1,%%k1\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm6,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm6,%%zmm4,%%zmm4\n\t"
"vmovntdq %%zmm2,%0\n\t"
"vpxorq %%zmm2,%%zmm2,%%zmm2\n\t"
"vmovntdq %%zmm4,%1\n\t"
"vpxorq %%zmm4,%%zmm4,%%zmm4"
:
: "m" (p[d]), "m" (q[d]));
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
static void raid6_avx5121_xor_syndrome(int disks, int start, int stop,
size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = stop;
p = dptr[disks-2];
q = dptr[disks-1];
kernel_fpu_begin();
asm volatile("vmovdqa64 %0,%%zmm0"
: : "m" (raid6_avx512_constants.x1d[0]));
for (d = 0 ; d < bytes ; d += 64) {
asm volatile("vmovdqa64 %0,%%zmm4\n\t"
"vmovdqa64 %1,%%zmm2\n\t"
"vpxorq %%zmm4,%%zmm2,%%zmm2"
:
: "m" (dptr[z0][d]), "m" (p[d]));
for (z = z0-1 ; z >= start ; z--) {
asm volatile("vpxorq %%zmm5,%%zmm5,%%zmm5\n\t"
"vpcmpgtb %%zmm4,%%zmm5,%%k1\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vmovdqa64 %0,%%zmm5\n\t"
"vpxorq %%zmm5,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4"
:
: "m" (dptr[z][d]));
}
for (z = start-1 ; z >= 0 ; z--) {
asm volatile("vpxorq %%zmm5,%%zmm5,%%zmm5\n\t"
"vpcmpgtb %%zmm4,%%zmm5,%%k1\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4"
:
: );
}
asm volatile("vpxorq %0,%%zmm4,%%zmm4\n\t"
"vmovdqa64 %%zmm4,%0\n\t"
"vmovdqa64 %%zmm2,%1"
:
: "m" (q[d]), "m" (p[d]));
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
static void raid6_avx5122_gen_syndrome(int disks, size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = disks - 3;
p = dptr[z0+1];
q = dptr[z0+2];
kernel_fpu_begin();
asm volatile("vmovdqa64 %0,%%zmm0\n\t"
"vpxorq %%zmm1,%%zmm1,%%zmm1"
:
: "m" (raid6_avx512_constants.x1d[0]));
for (d = 0; d < bytes; d += 128) {
asm volatile("prefetchnta %0\n\t"
"prefetchnta %1\n\t"
"vmovdqa64 %0,%%zmm2\n\t"
"vmovdqa64 %1,%%zmm3\n\t"
"vmovdqa64 %%zmm2,%%zmm4\n\t"
"vmovdqa64 %%zmm3,%%zmm6"
:
: "m" (dptr[z0][d]), "m" (dptr[z0][d+64]));
for (z = z0-1; z >= 0; z--) {
asm volatile("prefetchnta %0\n\t"
"prefetchnta %1\n\t"
"vpcmpgtb %%zmm4,%%zmm1,%%k1\n\t"
"vpcmpgtb %%zmm6,%%zmm1,%%k2\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpmovm2b %%k2,%%zmm7\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpaddb %%zmm6,%%zmm6,%%zmm6\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpandq %%zmm0,%%zmm7,%%zmm7\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6\n\t"
"vmovdqa64 %0,%%zmm5\n\t"
"vmovdqa64 %1,%%zmm7\n\t"
"vpxorq %%zmm5,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm7,%%zmm3,%%zmm3\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6"
:
: "m" (dptr[z][d]), "m" (dptr[z][d+64]));
}
asm volatile("vmovntdq %%zmm2,%0\n\t"
"vmovntdq %%zmm3,%1\n\t"
"vmovntdq %%zmm4,%2\n\t"
"vmovntdq %%zmm6,%3"
:
: "m" (p[d]), "m" (p[d+64]), "m" (q[d]),
"m" (q[d+64]));
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
static void raid6_avx5122_xor_syndrome(int disks, int start, int stop,
size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = stop;
p = dptr[disks-2];
q = dptr[disks-1];
kernel_fpu_begin();
asm volatile("vmovdqa64 %0,%%zmm0"
: : "m" (raid6_avx512_constants.x1d[0]));
for (d = 0 ; d < bytes ; d += 128) {
asm volatile("vmovdqa64 %0,%%zmm4\n\t"
"vmovdqa64 %1,%%zmm6\n\t"
"vmovdqa64 %2,%%zmm2\n\t"
"vmovdqa64 %3,%%zmm3\n\t"
"vpxorq %%zmm4,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm6,%%zmm3,%%zmm3"
:
: "m" (dptr[z0][d]), "m" (dptr[z0][d+64]),
"m" (p[d]), "m" (p[d+64]));
for (z = z0-1 ; z >= start ; z--) {
asm volatile("vpxorq %%zmm5,%%zmm5,%%zmm5\n\t"
"vpxorq %%zmm7,%%zmm7,%%zmm7\n\t"
"vpcmpgtb %%zmm4,%%zmm5,%%k1\n\t"
"vpcmpgtb %%zmm6,%%zmm7,%%k2\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpmovm2b %%k2,%%zmm7\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpaddb %%zmm6,%%zmm6,%%zmm6\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpandq %%zmm0,%%zmm7,%%zmm7\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6\n\t"
"vmovdqa64 %0,%%zmm5\n\t"
"vmovdqa64 %1,%%zmm7\n\t"
"vpxorq %%zmm5,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm7,%%zmm3,%%zmm3\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6"
:
: "m" (dptr[z][d]), "m" (dptr[z][d+64]));
}
for (z = start-1 ; z >= 0 ; z--) {
asm volatile("vpxorq %%zmm5,%%zmm5,%%zmm5\n\t"
"vpxorq %%zmm7,%%zmm7,%%zmm7\n\t"
"vpcmpgtb %%zmm4,%%zmm5,%%k1\n\t"
"vpcmpgtb %%zmm6,%%zmm7,%%k2\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpmovm2b %%k2,%%zmm7\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpaddb %%zmm6,%%zmm6,%%zmm6\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpandq %%zmm0,%%zmm7,%%zmm7\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6"
:
: );
}
asm volatile("vpxorq %0,%%zmm4,%%zmm4\n\t"
"vpxorq %1,%%zmm6,%%zmm6\n\t"
"vmovdqa64 %%zmm4,%0\n\t"
"vmovdqa64 %%zmm6,%1\n\t"
"vmovdqa64 %%zmm2,%2\n\t"
"vmovdqa64 %%zmm3,%3"
:
: "m" (q[d]), "m" (q[d+64]), "m" (p[d]),
"m" (p[d+64]));
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
static void raid6_avx5124_gen_syndrome(int disks, size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = disks - 3;
p = dptr[z0+1];
q = dptr[z0+2];
kernel_fpu_begin();
asm volatile("vmovdqa64 %0,%%zmm0\n\t"
"vpxorq %%zmm1,%%zmm1,%%zmm1\n\t"
"vpxorq %%zmm2,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm3,%%zmm3,%%zmm3\n\t"
"vpxorq %%zmm4,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm6,%%zmm6,%%zmm6\n\t"
"vpxorq %%zmm10,%%zmm10,%%zmm10\n\t"
"vpxorq %%zmm11,%%zmm11,%%zmm11\n\t"
"vpxorq %%zmm12,%%zmm12,%%zmm12\n\t"
"vpxorq %%zmm14,%%zmm14,%%zmm14"
:
: "m" (raid6_avx512_constants.x1d[0]));
for (d = 0; d < bytes; d += 256) {
for (z = z0; z >= 0; z--) {
asm volatile("prefetchnta %0\n\t"
"prefetchnta %1\n\t"
"prefetchnta %2\n\t"
"prefetchnta %3\n\t"
"vpcmpgtb %%zmm4,%%zmm1,%%k1\n\t"
"vpcmpgtb %%zmm6,%%zmm1,%%k2\n\t"
"vpcmpgtb %%zmm12,%%zmm1,%%k3\n\t"
"vpcmpgtb %%zmm14,%%zmm1,%%k4\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpmovm2b %%k2,%%zmm7\n\t"
"vpmovm2b %%k3,%%zmm13\n\t"
"vpmovm2b %%k4,%%zmm15\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpaddb %%zmm6,%%zmm6,%%zmm6\n\t"
"vpaddb %%zmm12,%%zmm12,%%zmm12\n\t"
"vpaddb %%zmm14,%%zmm14,%%zmm14\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpandq %%zmm0,%%zmm7,%%zmm7\n\t"
"vpandq %%zmm0,%%zmm13,%%zmm13\n\t"
"vpandq %%zmm0,%%zmm15,%%zmm15\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6\n\t"
"vpxorq %%zmm13,%%zmm12,%%zmm12\n\t"
"vpxorq %%zmm15,%%zmm14,%%zmm14\n\t"
"vmovdqa64 %0,%%zmm5\n\t"
"vmovdqa64 %1,%%zmm7\n\t"
"vmovdqa64 %2,%%zmm13\n\t"
"vmovdqa64 %3,%%zmm15\n\t"
"vpxorq %%zmm5,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm7,%%zmm3,%%zmm3\n\t"
"vpxorq %%zmm13,%%zmm10,%%zmm10\n\t"
"vpxorq %%zmm15,%%zmm11,%%zmm11\n"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6\n\t"
"vpxorq %%zmm13,%%zmm12,%%zmm12\n\t"
"vpxorq %%zmm15,%%zmm14,%%zmm14"
:
: "m" (dptr[z][d]), "m" (dptr[z][d+64]),
"m" (dptr[z][d+128]), "m" (dptr[z][d+192]));
}
asm volatile("vmovntdq %%zmm2,%0\n\t"
"vpxorq %%zmm2,%%zmm2,%%zmm2\n\t"
"vmovntdq %%zmm3,%1\n\t"
"vpxorq %%zmm3,%%zmm3,%%zmm3\n\t"
"vmovntdq %%zmm10,%2\n\t"
"vpxorq %%zmm10,%%zmm10,%%zmm10\n\t"
"vmovntdq %%zmm11,%3\n\t"
"vpxorq %%zmm11,%%zmm11,%%zmm11\n\t"
"vmovntdq %%zmm4,%4\n\t"
"vpxorq %%zmm4,%%zmm4,%%zmm4\n\t"
"vmovntdq %%zmm6,%5\n\t"
"vpxorq %%zmm6,%%zmm6,%%zmm6\n\t"
"vmovntdq %%zmm12,%6\n\t"
"vpxorq %%zmm12,%%zmm12,%%zmm12\n\t"
"vmovntdq %%zmm14,%7\n\t"
"vpxorq %%zmm14,%%zmm14,%%zmm14"
:
: "m" (p[d]), "m" (p[d+64]), "m" (p[d+128]),
"m" (p[d+192]), "m" (q[d]), "m" (q[d+64]),
"m" (q[d+128]), "m" (q[d+192]));
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
static void raid6_avx5124_xor_syndrome(int disks, int start, int stop,
size_t bytes, void **ptrs)
{
u8 **dptr = (u8 **)ptrs;
u8 *p, *q;
int d, z, z0;
z0 = stop;
p = dptr[disks-2];
q = dptr[disks-1];
kernel_fpu_begin();
asm volatile("vmovdqa64 %0,%%zmm0"
:: "m" (raid6_avx512_constants.x1d[0]));
for (d = 0 ; d < bytes ; d += 256) {
asm volatile("vmovdqa64 %0,%%zmm4\n\t"
"vmovdqa64 %1,%%zmm6\n\t"
"vmovdqa64 %2,%%zmm12\n\t"
"vmovdqa64 %3,%%zmm14\n\t"
"vmovdqa64 %4,%%zmm2\n\t"
"vmovdqa64 %5,%%zmm3\n\t"
"vmovdqa64 %6,%%zmm10\n\t"
"vmovdqa64 %7,%%zmm11\n\t"
"vpxorq %%zmm4,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm6,%%zmm3,%%zmm3\n\t"
"vpxorq %%zmm12,%%zmm10,%%zmm10\n\t"
"vpxorq %%zmm14,%%zmm11,%%zmm11"
:
: "m" (dptr[z0][d]), "m" (dptr[z0][d+64]),
"m" (dptr[z0][d+128]), "m" (dptr[z0][d+192]),
"m" (p[d]), "m" (p[d+64]), "m" (p[d+128]),
"m" (p[d+192]));
for (z = z0-1 ; z >= start ; z--) {
asm volatile("vpxorq %%zmm5,%%zmm5,%%zmm5\n\t"
"vpxorq %%zmm7,%%zmm7,%%zmm7\n\t"
"vpxorq %%zmm13,%%zmm13,%%zmm13\n\t"
"vpxorq %%zmm15,%%zmm15,%%zmm15\n\t"
"prefetchnta %0\n\t"
"prefetchnta %2\n\t"
"vpcmpgtb %%zmm4,%%zmm5,%%k1\n\t"
"vpcmpgtb %%zmm6,%%zmm7,%%k2\n\t"
"vpcmpgtb %%zmm12,%%zmm13,%%k3\n\t"
"vpcmpgtb %%zmm14,%%zmm15,%%k4\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpmovm2b %%k2,%%zmm7\n\t"
"vpmovm2b %%k3,%%zmm13\n\t"
"vpmovm2b %%k4,%%zmm15\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpaddb %%zmm6,%%zmm6,%%zmm6\n\t"
"vpaddb %%zmm12,%%zmm12,%%zmm12\n\t"
"vpaddb %%Zmm14,%%zmm14,%%zmm14\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpandq %%zmm0,%%zmm7,%%zmm7\n\t"
"vpandq %%zmm0,%%zmm13,%%zmm13\n\t"
"vpandq %%zmm0,%%zmm15,%%zmm15\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6\n\t"
"vpxorq %%zmm13,%%zmm12,%%zmm12\n\t"
"vpxorq %%zmm15,%%zmm14,%%zmm14\n\t"
"vmovdqa64 %0,%%zmm5\n\t"
"vmovdqa64 %1,%%zmm7\n\t"
"vmovdqa64 %2,%%zmm13\n\t"
"vmovdqa64 %3,%%zmm15\n\t"
"vpxorq %%zmm5,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm7,%%zmm3,%%zmm3\n\t"
"vpxorq %%zmm13,%%zmm10,%%zmm10\n\t"
"vpxorq %%zmm15,%%zmm11,%%zmm11\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6\n\t"
"vpxorq %%zmm13,%%zmm12,%%zmm12\n\t"
"vpxorq %%zmm15,%%zmm14,%%zmm14"
:
: "m" (dptr[z][d]), "m" (dptr[z][d+64]),
"m" (dptr[z][d+128]),
"m" (dptr[z][d+192]));
}
asm volatile("prefetchnta %0\n\t"
"prefetchnta %1\n\t"
:
: "m" (q[d]), "m" (q[d+128]));
for (z = start-1 ; z >= 0 ; z--) {
asm volatile("vpxorq %%zmm5,%%zmm5,%%zmm5\n\t"
"vpxorq %%zmm7,%%zmm7,%%zmm7\n\t"
"vpxorq %%zmm13,%%zmm13,%%zmm13\n\t"
"vpxorq %%zmm15,%%zmm15,%%zmm15\n\t"
"vpcmpgtb %%zmm4,%%zmm5,%%k1\n\t"
"vpcmpgtb %%zmm6,%%zmm7,%%k2\n\t"
"vpcmpgtb %%zmm12,%%zmm13,%%k3\n\t"
"vpcmpgtb %%zmm14,%%zmm15,%%k4\n\t"
"vpmovm2b %%k1,%%zmm5\n\t"
"vpmovm2b %%k2,%%zmm7\n\t"
"vpmovm2b %%k3,%%zmm13\n\t"
"vpmovm2b %%k4,%%zmm15\n\t"
"vpaddb %%zmm4,%%zmm4,%%zmm4\n\t"
"vpaddb %%zmm6,%%zmm6,%%zmm6\n\t"
"vpaddb %%zmm12,%%zmm12,%%zmm12\n\t"
"vpaddb %%zmm14,%%zmm14,%%zmm14\n\t"
"vpandq %%zmm0,%%zmm5,%%zmm5\n\t"
"vpandq %%zmm0,%%zmm7,%%zmm7\n\t"
"vpandq %%zmm0,%%zmm13,%%zmm13\n\t"
"vpandq %%zmm0,%%zmm15,%%zmm15\n\t"
"vpxorq %%zmm5,%%zmm4,%%zmm4\n\t"
"vpxorq %%zmm7,%%zmm6,%%zmm6\n\t"
"vpxorq %%zmm13,%%zmm12,%%zmm12\n\t"
"vpxorq %%zmm15,%%zmm14,%%zmm14"
:
: );
}
asm volatile("vmovntdq %%zmm2,%0\n\t"
"vmovntdq %%zmm3,%1\n\t"
"vmovntdq %%zmm10,%2\n\t"
"vmovntdq %%zmm11,%3\n\t"
"vpxorq %4,%%zmm4,%%zmm4\n\t"
"vpxorq %5,%%zmm6,%%zmm6\n\t"
"vpxorq %6,%%zmm12,%%zmm12\n\t"
"vpxorq %7,%%zmm14,%%zmm14\n\t"
"vmovntdq %%zmm4,%4\n\t"
"vmovntdq %%zmm6,%5\n\t"
"vmovntdq %%zmm12,%6\n\t"
"vmovntdq %%zmm14,%7"
:
: "m" (p[d]), "m" (p[d+64]), "m" (p[d+128]),
"m" (p[d+192]), "m" (q[d]), "m" (q[d+64]),
"m" (q[d+128]), "m" (q[d+192]));
}
asm volatile("sfence" : : : "memory");
kernel_fpu_end();
}
