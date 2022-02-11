static int F_1 ( void )
{
return F_2 ( V_1 ) &&
F_2 ( V_2 ) &&
F_2 ( V_3 ) &&
F_2 ( V_4 ) &&
F_2 ( V_5 ) &&
F_2 ( V_6 ) ;
}
static void F_3 ( int V_7 , T_1 V_8 , void * * V_9 )
{
T_2 * * V_10 = ( T_2 * * ) V_9 ;
T_2 * V_11 , * V_12 ;
int V_13 , V_14 , V_15 ;
V_15 = V_7 - 3 ;
V_11 = V_10 [ V_15 + 1 ] ;
V_12 = V_10 [ V_15 + 2 ] ;
F_4 () ;
asm volatile("vmovdqa64 %0,%%zmm0\n\t"
"vpxorq %%zmm1,%%zmm1,%%zmm1"
:
: "m" (raid6_avx512_constants.x1d[0]));
for ( V_13 = 0 ; V_13 < V_8 ; V_13 += 64 ) {
asm volatile("prefetchnta %0\n\t"
"vmovdqa64 %0,%%zmm2\n\t"
"prefetchnta %1\n\t"
"vmovdqa64 %%zmm2,%%zmm4\n\t"
"vmovdqa64 %1,%%zmm6"
:
: "m" (dptr[z0][d]), "m" (dptr[z0-1][d]));
for ( V_14 = V_15 - 2 ; V_14 >= 0 ; V_14 -- ) {
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
F_5 () ;
}
static void F_6 ( int V_7 , int V_16 , int V_17 ,
T_1 V_8 , void * * V_9 )
{
T_2 * * V_10 = ( T_2 * * ) V_9 ;
T_2 * V_11 , * V_12 ;
int V_13 , V_14 , V_15 ;
V_15 = V_17 ;
V_11 = V_10 [ V_7 - 2 ] ;
V_12 = V_10 [ V_7 - 1 ] ;
F_4 () ;
asm volatile("vmovdqa64 %0,%%zmm0"
: : "m" (raid6_avx512_constants.x1d[0]));
for ( V_13 = 0 ; V_13 < V_8 ; V_13 += 64 ) {
asm volatile("vmovdqa64 %0,%%zmm4\n\t"
"vmovdqa64 %1,%%zmm2\n\t"
"vpxorq %%zmm4,%%zmm2,%%zmm2"
:
: "m" (dptr[z0][d]), "m" (p[d]));
for ( V_14 = V_15 - 1 ; V_14 >= V_16 ; V_14 -- ) {
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
for ( V_14 = V_16 - 1 ; V_14 >= 0 ; V_14 -- ) {
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
F_5 () ;
}
static void F_7 ( int V_7 , T_1 V_8 , void * * V_9 )
{
T_2 * * V_10 = ( T_2 * * ) V_9 ;
T_2 * V_11 , * V_12 ;
int V_13 , V_14 , V_15 ;
V_15 = V_7 - 3 ;
V_11 = V_10 [ V_15 + 1 ] ;
V_12 = V_10 [ V_15 + 2 ] ;
F_4 () ;
asm volatile("vmovdqa64 %0,%%zmm0\n\t"
"vpxorq %%zmm1,%%zmm1,%%zmm1"
:
: "m" (raid6_avx512_constants.x1d[0]));
for ( V_13 = 0 ; V_13 < V_8 ; V_13 += 128 ) {
asm volatile("prefetchnta %0\n\t"
"prefetchnta %1\n\t"
"vmovdqa64 %0,%%zmm2\n\t"
"vmovdqa64 %1,%%zmm3\n\t"
"vmovdqa64 %%zmm2,%%zmm4\n\t"
"vmovdqa64 %%zmm3,%%zmm6"
:
: "m" (dptr[z0][d]), "m" (dptr[z0][d+64]));
for ( V_14 = V_15 - 1 ; V_14 >= 0 ; V_14 -- ) {
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
F_5 () ;
}
static void F_8 ( int V_7 , int V_16 , int V_17 ,
T_1 V_8 , void * * V_9 )
{
T_2 * * V_10 = ( T_2 * * ) V_9 ;
T_2 * V_11 , * V_12 ;
int V_13 , V_14 , V_15 ;
V_15 = V_17 ;
V_11 = V_10 [ V_7 - 2 ] ;
V_12 = V_10 [ V_7 - 1 ] ;
F_4 () ;
asm volatile("vmovdqa64 %0,%%zmm0"
: : "m" (raid6_avx512_constants.x1d[0]));
for ( V_13 = 0 ; V_13 < V_8 ; V_13 += 128 ) {
asm volatile("vmovdqa64 %0,%%zmm4\n\t"
"vmovdqa64 %1,%%zmm6\n\t"
"vmovdqa64 %2,%%zmm2\n\t"
"vmovdqa64 %3,%%zmm3\n\t"
"vpxorq %%zmm4,%%zmm2,%%zmm2\n\t"
"vpxorq %%zmm6,%%zmm3,%%zmm3"
:
: "m" (dptr[z0][d]), "m" (dptr[z0][d+64]),
"m" (p[d]), "m" (p[d+64]));
for ( V_14 = V_15 - 1 ; V_14 >= V_16 ; V_14 -- ) {
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
for ( V_14 = V_16 - 1 ; V_14 >= 0 ; V_14 -- ) {
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
F_5 () ;
}
static void F_9 ( int V_7 , T_1 V_8 , void * * V_9 )
{
T_2 * * V_10 = ( T_2 * * ) V_9 ;
T_2 * V_11 , * V_12 ;
int V_13 , V_14 , V_15 ;
V_15 = V_7 - 3 ;
V_11 = V_10 [ V_15 + 1 ] ;
V_12 = V_10 [ V_15 + 2 ] ;
F_4 () ;
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
for ( V_13 = 0 ; V_13 < V_8 ; V_13 += 256 ) {
for ( V_14 = V_15 ; V_14 >= 0 ; V_14 -- ) {
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
F_5 () ;
}
static void F_10 ( int V_7 , int V_16 , int V_17 ,
T_1 V_8 , void * * V_9 )
{
T_2 * * V_10 = ( T_2 * * ) V_9 ;
T_2 * V_11 , * V_12 ;
int V_13 , V_14 , V_15 ;
V_15 = V_17 ;
V_11 = V_10 [ V_7 - 2 ] ;
V_12 = V_10 [ V_7 - 1 ] ;
F_4 () ;
asm volatile("vmovdqa64 %0,%%zmm0"
:: "m" (raid6_avx512_constants.x1d[0]));
for ( V_13 = 0 ; V_13 < V_8 ; V_13 += 256 ) {
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
for ( V_14 = V_15 - 1 ; V_14 >= V_16 ; V_14 -- ) {
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
for ( V_14 = V_16 - 1 ; V_14 >= 0 ; V_14 -- ) {
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
F_5 () ;
}
