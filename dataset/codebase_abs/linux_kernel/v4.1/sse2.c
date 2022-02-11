static int F_1 ( void )
{
return F_2 ( V_1 ) &&
F_2 ( V_2 ) &&
F_2 ( V_3 ) &&
F_2 ( V_4 ) ;
}
static void F_3 ( int V_5 , T_1 V_6 , void * * V_7 )
{
T_2 * * V_8 = ( T_2 * * ) V_7 ;
T_2 * V_9 , * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = V_5 - 3 ;
V_9 = V_8 [ V_13 + 1 ] ;
V_10 = V_8 [ V_13 + 2 ] ;
F_4 () ;
asm volatile("movdqa %0,%%xmm0" : : "m" (raid6_sse_constants.x1d[0]));
asm volatile("pxor %xmm5,%xmm5");
for ( V_11 = 0 ; V_11 < V_6 ; V_11 += 16 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm2" : : "m" (dptr[z0][d]));
asm volatile("prefetchnta %0" : : "m" (dptr[z0-1][d]));
asm volatile("movdqa %xmm2,%xmm4");
asm volatile("movdqa %0,%%xmm6" : : "m" (dptr[z0-1][d]));
for ( V_12 = V_13 - 2 ; V_12 >= 0 ; V_12 -- ) {
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
F_5 () ;
}
static void F_6 ( int V_5 , int V_14 , int V_15 ,
T_1 V_6 , void * * V_7 )
{
T_2 * * V_8 = ( T_2 * * ) V_7 ;
T_2 * V_9 , * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = V_15 ;
V_9 = V_8 [ V_5 - 2 ] ;
V_10 = V_8 [ V_5 - 1 ] ;
F_4 () ;
asm volatile("movdqa %0,%%xmm0" : : "m" (raid6_sse_constants.x1d[0]));
for ( V_11 = 0 ; V_11 < V_6 ; V_11 += 16 ) {
asm volatile("movdqa %0,%%xmm4" :: "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm2" : : "m" (p[d]));
asm volatile("pxor %xmm4,%xmm2");
for ( V_12 = V_13 - 1 ; V_12 >= V_14 ; V_12 -- ) {
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pcmpgtb %xmm4,%xmm5");
asm volatile("paddb %xmm4,%xmm4");
asm volatile("pand %xmm0,%xmm5");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("movdqa %0,%%xmm5" :: "m" (dptr[z][d]));
asm volatile("pxor %xmm5,%xmm2");
asm volatile("pxor %xmm5,%xmm4");
}
for ( V_12 = V_14 - 1 ; V_12 >= 0 ; V_12 -- ) {
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pcmpgtb %xmm4,%xmm5");
asm volatile("paddb %xmm4,%xmm4");
asm volatile("pand %xmm0,%xmm5");
asm volatile("pxor %xmm5,%xmm4");
}
asm volatile("pxor %0,%%xmm4" : : "m" (q[d]));
asm volatile("movdqa %%xmm4,%0" : "=m" (q[d]));
asm volatile("movdqa %%xmm2,%0" : "=m" (p[d]));
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
static void F_7 ( int V_5 , T_1 V_6 , void * * V_7 )
{
T_2 * * V_8 = ( T_2 * * ) V_7 ;
T_2 * V_9 , * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = V_5 - 3 ;
V_9 = V_8 [ V_13 + 1 ] ;
V_10 = V_8 [ V_13 + 2 ] ;
F_4 () ;
asm volatile("movdqa %0,%%xmm0" : : "m" (raid6_sse_constants.x1d[0]));
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm7,%xmm7");
for ( V_11 = 0 ; V_11 < V_6 ; V_11 += 32 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm2" : : "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm3" : : "m" (dptr[z0][d+16]));
asm volatile("movdqa %xmm2,%xmm4");
asm volatile("movdqa %xmm3,%xmm6");
for ( V_12 = V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
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
F_5 () ;
}
static void F_8 ( int V_5 , int V_14 , int V_15 ,
T_1 V_6 , void * * V_7 )
{
T_2 * * V_8 = ( T_2 * * ) V_7 ;
T_2 * V_9 , * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = V_15 ;
V_9 = V_8 [ V_5 - 2 ] ;
V_10 = V_8 [ V_5 - 1 ] ;
F_4 () ;
asm volatile("movdqa %0,%%xmm0" : : "m" (raid6_sse_constants.x1d[0]));
for ( V_11 = 0 ; V_11 < V_6 ; V_11 += 32 ) {
asm volatile("movdqa %0,%%xmm4" :: "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm6" :: "m" (dptr[z0][d+16]));
asm volatile("movdqa %0,%%xmm2" : : "m" (p[d]));
asm volatile("movdqa %0,%%xmm3" : : "m" (p[d+16]));
asm volatile("pxor %xmm4,%xmm2");
asm volatile("pxor %xmm6,%xmm3");
for ( V_12 = V_13 - 1 ; V_12 >= V_14 ; V_12 -- ) {
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm7,%xmm7");
asm volatile("pcmpgtb %xmm4,%xmm5");
asm volatile("pcmpgtb %xmm6,%xmm7");
asm volatile("paddb %xmm4,%xmm4");
asm volatile("paddb %xmm6,%xmm6");
asm volatile("pand %xmm0,%xmm5");
asm volatile("pand %xmm0,%xmm7");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm7,%xmm6");
asm volatile("movdqa %0,%%xmm5" :: "m" (dptr[z][d]));
asm volatile("movdqa %0,%%xmm7" :: "m" (dptr[z][d+16]));
asm volatile("pxor %xmm5,%xmm2");
asm volatile("pxor %xmm7,%xmm3");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm7,%xmm6");
}
for ( V_12 = V_14 - 1 ; V_12 >= 0 ; V_12 -- ) {
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm7,%xmm7");
asm volatile("pcmpgtb %xmm4,%xmm5");
asm volatile("pcmpgtb %xmm6,%xmm7");
asm volatile("paddb %xmm4,%xmm4");
asm volatile("paddb %xmm6,%xmm6");
asm volatile("pand %xmm0,%xmm5");
asm volatile("pand %xmm0,%xmm7");
asm volatile("pxor %xmm5,%xmm4");
asm volatile("pxor %xmm7,%xmm6");
}
asm volatile("pxor %0,%%xmm4" : : "m" (q[d]));
asm volatile("pxor %0,%%xmm6" : : "m" (q[d+16]));
asm volatile("movdqa %%xmm4,%0" : "=m" (q[d]));
asm volatile("movdqa %%xmm6,%0" : "=m" (q[d+16]));
asm volatile("movdqa %%xmm2,%0" : "=m" (p[d]));
asm volatile("movdqa %%xmm3,%0" : "=m" (p[d+16]));
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
static void F_9 ( int V_5 , T_1 V_6 , void * * V_7 )
{
T_2 * * V_8 = ( T_2 * * ) V_7 ;
T_2 * V_9 , * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = V_5 - 3 ;
V_9 = V_8 [ V_13 + 1 ] ;
V_10 = V_8 [ V_13 + 2 ] ;
F_4 () ;
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
for ( V_11 = 0 ; V_11 < V_6 ; V_11 += 64 ) {
for ( V_12 = V_13 ; V_12 >= 0 ; V_12 -- ) {
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
F_5 () ;
}
static void F_10 ( int V_5 , int V_14 , int V_15 ,
T_1 V_6 , void * * V_7 )
{
T_2 * * V_8 = ( T_2 * * ) V_7 ;
T_2 * V_9 , * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = V_15 ;
V_9 = V_8 [ V_5 - 2 ] ;
V_10 = V_8 [ V_5 - 1 ] ;
F_4 () ;
asm volatile("movdqa %0,%%xmm0" :: "m" (raid6_sse_constants.x1d[0]));
for ( V_11 = 0 ; V_11 < V_6 ; V_11 += 64 ) {
asm volatile("movdqa %0,%%xmm4" :: "m" (dptr[z0][d]));
asm volatile("movdqa %0,%%xmm6" :: "m" (dptr[z0][d+16]));
asm volatile("movdqa %0,%%xmm12" :: "m" (dptr[z0][d+32]));
asm volatile("movdqa %0,%%xmm14" :: "m" (dptr[z0][d+48]));
asm volatile("movdqa %0,%%xmm2" : : "m" (p[d]));
asm volatile("movdqa %0,%%xmm3" : : "m" (p[d+16]));
asm volatile("movdqa %0,%%xmm10" : : "m" (p[d+32]));
asm volatile("movdqa %0,%%xmm11" : : "m" (p[d+48]));
asm volatile("pxor %xmm4,%xmm2");
asm volatile("pxor %xmm6,%xmm3");
asm volatile("pxor %xmm12,%xmm10");
asm volatile("pxor %xmm14,%xmm11");
for ( V_12 = V_13 - 1 ; V_12 >= V_14 ; V_12 -- ) {
asm volatile("prefetchnta %0" :: "m" (dptr[z][d]));
asm volatile("prefetchnta %0" :: "m" (dptr[z][d+32]));
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm7,%xmm7");
asm volatile("pxor %xmm13,%xmm13");
asm volatile("pxor %xmm15,%xmm15");
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
}
asm volatile("prefetchnta %0" :: "m" (q[d]));
asm volatile("prefetchnta %0" :: "m" (q[d+32]));
for ( V_12 = V_14 - 1 ; V_12 >= 0 ; V_12 -- ) {
asm volatile("pxor %xmm5,%xmm5");
asm volatile("pxor %xmm7,%xmm7");
asm volatile("pxor %xmm13,%xmm13");
asm volatile("pxor %xmm15,%xmm15");
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
}
asm volatile("movntdq %%xmm2,%0" : "=m" (p[d]));
asm volatile("movntdq %%xmm3,%0" : "=m" (p[d+16]));
asm volatile("movntdq %%xmm10,%0" : "=m" (p[d+32]));
asm volatile("movntdq %%xmm11,%0" : "=m" (p[d+48]));
asm volatile("pxor %0,%%xmm4" : : "m" (q[d]));
asm volatile("pxor %0,%%xmm6" : : "m" (q[d+16]));
asm volatile("pxor %0,%%xmm12" : : "m" (q[d+32]));
asm volatile("pxor %0,%%xmm14" : : "m" (q[d+48]));
asm volatile("movntdq %%xmm4,%0" : "=m" (q[d]));
asm volatile("movntdq %%xmm6,%0" : "=m" (q[d+16]));
asm volatile("movntdq %%xmm12,%0" : "=m" (q[d+32]));
asm volatile("movntdq %%xmm14,%0" : "=m" (q[d+48]));
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
