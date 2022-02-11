static int F_1 ( void )
{
return F_2 ( V_1 ) && F_2 ( V_2 ) ;
}
static void F_3 ( int V_3 , T_1 V_4 , void * * V_5 )
{
T_2 * * V_6 = ( T_2 * * ) V_5 ;
T_2 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = V_3 - 3 ;
V_7 = V_6 [ V_11 + 1 ] ;
V_8 = V_6 [ V_11 + 2 ] ;
F_4 () ;
asm volatile("vmovdqa %0,%%ymm0" : : "m" (raid6_avx2_constants.x1d[0]));
asm volatile("vpxor %ymm3,%ymm3,%ymm3");
for ( V_9 = 0 ; V_9 < V_4 ; V_9 += 32 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("vmovdqa %0,%%ymm2" : : "m" (dptr[z0][d]));
asm volatile("prefetchnta %0" : : "m" (dptr[z0-1][d]));
asm volatile("vmovdqa %ymm2,%ymm4");
asm volatile("vmovdqa %0,%%ymm6" : : "m" (dptr[z0-1][d]));
for ( V_10 = V_11 - 2 ; V_10 >= 0 ; V_10 -- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("vpcmpgtb %ymm4,%ymm3,%ymm5");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm6,%ymm2,%ymm2");
asm volatile("vpxor %ymm6,%ymm4,%ymm4");
asm volatile("vmovdqa %0,%%ymm6" : : "m" (dptr[z][d]));
}
asm volatile("vpcmpgtb %ymm4,%ymm3,%ymm5");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm6,%ymm2,%ymm2");
asm volatile("vpxor %ymm6,%ymm4,%ymm4");
asm volatile("vmovntdq %%ymm2,%0" : "=m" (p[d]));
asm volatile("vpxor %ymm2,%ymm2,%ymm2");
asm volatile("vmovntdq %%ymm4,%0" : "=m" (q[d]));
asm volatile("vpxor %ymm4,%ymm4,%ymm4");
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
static void F_6 ( int V_3 , int V_12 , int V_13 ,
T_1 V_4 , void * * V_5 )
{
T_2 * * V_6 = ( T_2 * * ) V_5 ;
T_2 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = V_13 ;
V_7 = V_6 [ V_3 - 2 ] ;
V_8 = V_6 [ V_3 - 1 ] ;
F_4 () ;
asm volatile("vmovdqa %0,%%ymm0" : : "m" (raid6_avx2_constants.x1d[0]));
for ( V_9 = 0 ; V_9 < V_4 ; V_9 += 32 ) {
asm volatile("vmovdqa %0,%%ymm4" :: "m" (dptr[z0][d]));
asm volatile("vmovdqa %0,%%ymm2" : : "m" (p[d]));
asm volatile("vpxor %ymm4,%ymm2,%ymm2");
for ( V_10 = V_11 - 1 ; V_10 >= V_12 ; V_10 -- ) {
asm volatile("vpxor %ymm5,%ymm5,%ymm5");
asm volatile("vpcmpgtb %ymm4,%ymm5,%ymm5");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vmovdqa %0,%%ymm5" :: "m" (dptr[z][d]));
asm volatile("vpxor %ymm5,%ymm2,%ymm2");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
}
for ( V_10 = V_12 - 1 ; V_10 >= 0 ; V_10 -- ) {
asm volatile("vpxor %ymm5,%ymm5,%ymm5");
asm volatile("vpcmpgtb %ymm4,%ymm5,%ymm5");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
}
asm volatile("vpxor %0,%%ymm4,%%ymm4" : : "m" (q[d]));
asm volatile("vmovdqa %%ymm4,%0" : "=m" (q[d]));
asm volatile("vmovdqa %%ymm2,%0" : "=m" (p[d]));
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
static void F_7 ( int V_3 , T_1 V_4 , void * * V_5 )
{
T_2 * * V_6 = ( T_2 * * ) V_5 ;
T_2 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = V_3 - 3 ;
V_7 = V_6 [ V_11 + 1 ] ;
V_8 = V_6 [ V_11 + 2 ] ;
F_4 () ;
asm volatile("vmovdqa %0,%%ymm0" : : "m" (raid6_avx2_constants.x1d[0]));
asm volatile("vpxor %ymm1,%ymm1,%ymm1");
for ( V_9 = 0 ; V_9 < V_4 ; V_9 += 64 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d+32]));
asm volatile("vmovdqa %0,%%ymm2" : : "m" (dptr[z0][d]));
asm volatile("vmovdqa %0,%%ymm3" : : "m" (dptr[z0][d+32]));
asm volatile("vmovdqa %ymm2,%ymm4");
asm volatile("vmovdqa %ymm3,%ymm6");
for ( V_10 = V_11 - 1 ; V_10 >= 0 ; V_10 -- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("prefetchnta %0" : : "m" (dptr[z][d+32]));
asm volatile("vpcmpgtb %ymm4,%ymm1,%ymm5");
asm volatile("vpcmpgtb %ymm6,%ymm1,%ymm7");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpaddb %ymm6,%ymm6,%ymm6");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpand %ymm0,%ymm7,%ymm7");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
asm volatile("vmovdqa %0,%%ymm5" : : "m" (dptr[z][d]));
asm volatile("vmovdqa %0,%%ymm7" : : "m" (dptr[z][d+32]));
asm volatile("vpxor %ymm5,%ymm2,%ymm2");
asm volatile("vpxor %ymm7,%ymm3,%ymm3");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
}
asm volatile("vmovntdq %%ymm2,%0" : "=m" (p[d]));
asm volatile("vmovntdq %%ymm3,%0" : "=m" (p[d+32]));
asm volatile("vmovntdq %%ymm4,%0" : "=m" (q[d]));
asm volatile("vmovntdq %%ymm6,%0" : "=m" (q[d+32]));
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
static void F_8 ( int V_3 , int V_12 , int V_13 ,
T_1 V_4 , void * * V_5 )
{
T_2 * * V_6 = ( T_2 * * ) V_5 ;
T_2 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = V_13 ;
V_7 = V_6 [ V_3 - 2 ] ;
V_8 = V_6 [ V_3 - 1 ] ;
F_4 () ;
asm volatile("vmovdqa %0,%%ymm0" : : "m" (raid6_avx2_constants.x1d[0]));
for ( V_9 = 0 ; V_9 < V_4 ; V_9 += 64 ) {
asm volatile("vmovdqa %0,%%ymm4" :: "m" (dptr[z0][d]));
asm volatile("vmovdqa %0,%%ymm6" :: "m" (dptr[z0][d+32]));
asm volatile("vmovdqa %0,%%ymm2" : : "m" (p[d]));
asm volatile("vmovdqa %0,%%ymm3" : : "m" (p[d+32]));
asm volatile("vpxor %ymm4,%ymm2,%ymm2");
asm volatile("vpxor %ymm6,%ymm3,%ymm3");
for ( V_10 = V_11 - 1 ; V_10 >= V_12 ; V_10 -- ) {
asm volatile("vpxor %ymm5,%ymm5,%ymm5");
asm volatile("vpxor %ymm7,%ymm7,%ymm7");
asm volatile("vpcmpgtb %ymm4,%ymm5,%ymm5");
asm volatile("vpcmpgtb %ymm6,%ymm7,%ymm7");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpaddb %ymm6,%ymm6,%ymm6");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpand %ymm0,%ymm7,%ymm7");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
asm volatile("vmovdqa %0,%%ymm5" :: "m" (dptr[z][d]));
asm volatile("vmovdqa %0,%%ymm7"
:: "m" (dptr[z][d+32]));
asm volatile("vpxor %ymm5,%ymm2,%ymm2");
asm volatile("vpxor %ymm7,%ymm3,%ymm3");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
}
for ( V_10 = V_12 - 1 ; V_10 >= 0 ; V_10 -- ) {
asm volatile("vpxor %ymm5,%ymm5,%ymm5");
asm volatile("vpxor %ymm7,%ymm7,%ymm7");
asm volatile("vpcmpgtb %ymm4,%ymm5,%ymm5");
asm volatile("vpcmpgtb %ymm6,%ymm7,%ymm7");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpaddb %ymm6,%ymm6,%ymm6");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpand %ymm0,%ymm7,%ymm7");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
}
asm volatile("vpxor %0,%%ymm4,%%ymm4" : : "m" (q[d]));
asm volatile("vpxor %0,%%ymm6,%%ymm6" : : "m" (q[d+32]));
asm volatile("vmovdqa %%ymm4,%0" : "=m" (q[d]));
asm volatile("vmovdqa %%ymm6,%0" : "=m" (q[d+32]));
asm volatile("vmovdqa %%ymm2,%0" : "=m" (p[d]));
asm volatile("vmovdqa %%ymm3,%0" : "=m" (p[d+32]));
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
static void F_9 ( int V_3 , T_1 V_4 , void * * V_5 )
{
T_2 * * V_6 = ( T_2 * * ) V_5 ;
T_2 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = V_3 - 3 ;
V_7 = V_6 [ V_11 + 1 ] ;
V_8 = V_6 [ V_11 + 2 ] ;
F_4 () ;
asm volatile("vmovdqa %0,%%ymm0" : : "m" (raid6_avx2_constants.x1d[0]));
asm volatile("vpxor %ymm1,%ymm1,%ymm1");
asm volatile("vpxor %ymm2,%ymm2,%ymm2");
asm volatile("vpxor %ymm3,%ymm3,%ymm3");
asm volatile("vpxor %ymm4,%ymm4,%ymm4");
asm volatile("vpxor %ymm6,%ymm6,%ymm6");
asm volatile("vpxor %ymm10,%ymm10,%ymm10");
asm volatile("vpxor %ymm11,%ymm11,%ymm11");
asm volatile("vpxor %ymm12,%ymm12,%ymm12");
asm volatile("vpxor %ymm14,%ymm14,%ymm14");
for ( V_9 = 0 ; V_9 < V_4 ; V_9 += 128 ) {
for ( V_10 = V_11 ; V_10 >= 0 ; V_10 -- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("prefetchnta %0" : : "m" (dptr[z][d+32]));
asm volatile("prefetchnta %0" : : "m" (dptr[z][d+64]));
asm volatile("prefetchnta %0" : : "m" (dptr[z][d+96]));
asm volatile("vpcmpgtb %ymm4,%ymm1,%ymm5");
asm volatile("vpcmpgtb %ymm6,%ymm1,%ymm7");
asm volatile("vpcmpgtb %ymm12,%ymm1,%ymm13");
asm volatile("vpcmpgtb %ymm14,%ymm1,%ymm15");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpaddb %ymm6,%ymm6,%ymm6");
asm volatile("vpaddb %ymm12,%ymm12,%ymm12");
asm volatile("vpaddb %ymm14,%ymm14,%ymm14");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpand %ymm0,%ymm7,%ymm7");
asm volatile("vpand %ymm0,%ymm13,%ymm13");
asm volatile("vpand %ymm0,%ymm15,%ymm15");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
asm volatile("vpxor %ymm13,%ymm12,%ymm12");
asm volatile("vpxor %ymm15,%ymm14,%ymm14");
asm volatile("vmovdqa %0,%%ymm5" : : "m" (dptr[z][d]));
asm volatile("vmovdqa %0,%%ymm7" : : "m" (dptr[z][d+32]));
asm volatile("vmovdqa %0,%%ymm13" : : "m" (dptr[z][d+64]));
asm volatile("vmovdqa %0,%%ymm15" : : "m" (dptr[z][d+96]));
asm volatile("vpxor %ymm5,%ymm2,%ymm2");
asm volatile("vpxor %ymm7,%ymm3,%ymm3");
asm volatile("vpxor %ymm13,%ymm10,%ymm10");
asm volatile("vpxor %ymm15,%ymm11,%ymm11");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
asm volatile("vpxor %ymm13,%ymm12,%ymm12");
asm volatile("vpxor %ymm15,%ymm14,%ymm14");
}
asm volatile("vmovntdq %%ymm2,%0" : "=m" (p[d]));
asm volatile("vpxor %ymm2,%ymm2,%ymm2");
asm volatile("vmovntdq %%ymm3,%0" : "=m" (p[d+32]));
asm volatile("vpxor %ymm3,%ymm3,%ymm3");
asm volatile("vmovntdq %%ymm10,%0" : "=m" (p[d+64]));
asm volatile("vpxor %ymm10,%ymm10,%ymm10");
asm volatile("vmovntdq %%ymm11,%0" : "=m" (p[d+96]));
asm volatile("vpxor %ymm11,%ymm11,%ymm11");
asm volatile("vmovntdq %%ymm4,%0" : "=m" (q[d]));
asm volatile("vpxor %ymm4,%ymm4,%ymm4");
asm volatile("vmovntdq %%ymm6,%0" : "=m" (q[d+32]));
asm volatile("vpxor %ymm6,%ymm6,%ymm6");
asm volatile("vmovntdq %%ymm12,%0" : "=m" (q[d+64]));
asm volatile("vpxor %ymm12,%ymm12,%ymm12");
asm volatile("vmovntdq %%ymm14,%0" : "=m" (q[d+96]));
asm volatile("vpxor %ymm14,%ymm14,%ymm14");
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
static void F_10 ( int V_3 , int V_12 , int V_13 ,
T_1 V_4 , void * * V_5 )
{
T_2 * * V_6 = ( T_2 * * ) V_5 ;
T_2 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = V_13 ;
V_7 = V_6 [ V_3 - 2 ] ;
V_8 = V_6 [ V_3 - 1 ] ;
F_4 () ;
asm volatile("vmovdqa %0,%%ymm0" :: "m" (raid6_avx2_constants.x1d[0]));
for ( V_9 = 0 ; V_9 < V_4 ; V_9 += 128 ) {
asm volatile("vmovdqa %0,%%ymm4" :: "m" (dptr[z0][d]));
asm volatile("vmovdqa %0,%%ymm6" :: "m" (dptr[z0][d+32]));
asm volatile("vmovdqa %0,%%ymm12" :: "m" (dptr[z0][d+64]));
asm volatile("vmovdqa %0,%%ymm14" :: "m" (dptr[z0][d+96]));
asm volatile("vmovdqa %0,%%ymm2" : : "m" (p[d]));
asm volatile("vmovdqa %0,%%ymm3" : : "m" (p[d+32]));
asm volatile("vmovdqa %0,%%ymm10" : : "m" (p[d+64]));
asm volatile("vmovdqa %0,%%ymm11" : : "m" (p[d+96]));
asm volatile("vpxor %ymm4,%ymm2,%ymm2");
asm volatile("vpxor %ymm6,%ymm3,%ymm3");
asm volatile("vpxor %ymm12,%ymm10,%ymm10");
asm volatile("vpxor %ymm14,%ymm11,%ymm11");
for ( V_10 = V_11 - 1 ; V_10 >= V_12 ; V_10 -- ) {
asm volatile("prefetchnta %0" :: "m" (dptr[z][d]));
asm volatile("prefetchnta %0" :: "m" (dptr[z][d+64]));
asm volatile("vpxor %ymm5,%ymm5,%ymm5");
asm volatile("vpxor %ymm7,%ymm7,%ymm7");
asm volatile("vpxor %ymm13,%ymm13,%ymm13");
asm volatile("vpxor %ymm15,%ymm15,%ymm15");
asm volatile("vpcmpgtb %ymm4,%ymm5,%ymm5");
asm volatile("vpcmpgtb %ymm6,%ymm7,%ymm7");
asm volatile("vpcmpgtb %ymm12,%ymm13,%ymm13");
asm volatile("vpcmpgtb %ymm14,%ymm15,%ymm15");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpaddb %ymm6,%ymm6,%ymm6");
asm volatile("vpaddb %ymm12,%ymm12,%ymm12");
asm volatile("vpaddb %ymm14,%ymm14,%ymm14");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpand %ymm0,%ymm7,%ymm7");
asm volatile("vpand %ymm0,%ymm13,%ymm13");
asm volatile("vpand %ymm0,%ymm15,%ymm15");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
asm volatile("vpxor %ymm13,%ymm12,%ymm12");
asm volatile("vpxor %ymm15,%ymm14,%ymm14");
asm volatile("vmovdqa %0,%%ymm5" :: "m" (dptr[z][d]));
asm volatile("vmovdqa %0,%%ymm7"
:: "m" (dptr[z][d+32]));
asm volatile("vmovdqa %0,%%ymm13"
:: "m" (dptr[z][d+64]));
asm volatile("vmovdqa %0,%%ymm15"
:: "m" (dptr[z][d+96]));
asm volatile("vpxor %ymm5,%ymm2,%ymm2");
asm volatile("vpxor %ymm7,%ymm3,%ymm3");
asm volatile("vpxor %ymm13,%ymm10,%ymm10");
asm volatile("vpxor %ymm15,%ymm11,%ymm11");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
asm volatile("vpxor %ymm13,%ymm12,%ymm12");
asm volatile("vpxor %ymm15,%ymm14,%ymm14");
}
asm volatile("prefetchnta %0" :: "m" (q[d]));
asm volatile("prefetchnta %0" :: "m" (q[d+64]));
for ( V_10 = V_12 - 1 ; V_10 >= 0 ; V_10 -- ) {
asm volatile("vpxor %ymm5,%ymm5,%ymm5");
asm volatile("vpxor %ymm7,%ymm7,%ymm7");
asm volatile("vpxor %ymm13,%ymm13,%ymm13");
asm volatile("vpxor %ymm15,%ymm15,%ymm15");
asm volatile("vpcmpgtb %ymm4,%ymm5,%ymm5");
asm volatile("vpcmpgtb %ymm6,%ymm7,%ymm7");
asm volatile("vpcmpgtb %ymm12,%ymm13,%ymm13");
asm volatile("vpcmpgtb %ymm14,%ymm15,%ymm15");
asm volatile("vpaddb %ymm4,%ymm4,%ymm4");
asm volatile("vpaddb %ymm6,%ymm6,%ymm6");
asm volatile("vpaddb %ymm12,%ymm12,%ymm12");
asm volatile("vpaddb %ymm14,%ymm14,%ymm14");
asm volatile("vpand %ymm0,%ymm5,%ymm5");
asm volatile("vpand %ymm0,%ymm7,%ymm7");
asm volatile("vpand %ymm0,%ymm13,%ymm13");
asm volatile("vpand %ymm0,%ymm15,%ymm15");
asm volatile("vpxor %ymm5,%ymm4,%ymm4");
asm volatile("vpxor %ymm7,%ymm6,%ymm6");
asm volatile("vpxor %ymm13,%ymm12,%ymm12");
asm volatile("vpxor %ymm15,%ymm14,%ymm14");
}
asm volatile("vmovntdq %%ymm2,%0" : "=m" (p[d]));
asm volatile("vmovntdq %%ymm3,%0" : "=m" (p[d+32]));
asm volatile("vmovntdq %%ymm10,%0" : "=m" (p[d+64]));
asm volatile("vmovntdq %%ymm11,%0" : "=m" (p[d+96]));
asm volatile("vpxor %0,%%ymm4,%%ymm4" : : "m" (q[d]));
asm volatile("vpxor %0,%%ymm6,%%ymm6" : : "m" (q[d+32]));
asm volatile("vpxor %0,%%ymm12,%%ymm12" : : "m" (q[d+64]));
asm volatile("vpxor %0,%%ymm14,%%ymm14" : : "m" (q[d+96]));
asm volatile("vmovntdq %%ymm4,%0" : "=m" (q[d]));
asm volatile("vmovntdq %%ymm6,%0" : "=m" (q[d+32]));
asm volatile("vmovntdq %%ymm12,%0" : "=m" (q[d+64]));
asm volatile("vmovntdq %%ymm14,%0" : "=m" (q[d+96]));
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
