static int F_1 ( void )
{
return F_2 ( V_1 ) &&
F_2 ( V_2 ) &&
F_2 ( V_3 ) ;
}
static void F_3 ( int V_4 , T_1 V_5 , int V_6 ,
int V_7 , void * * V_8 )
{
T_2 * V_9 , * V_10 , * V_11 , * V_12 ;
const T_2 * V_13 ;
const T_2 * V_14 ;
static const T_2 V_15 ( 16 ) V_16 [ 16 ] = {
0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f ,
0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f } ;
V_9 = ( T_2 * ) V_8 [ V_4 - 2 ] ;
V_10 = ( T_2 * ) V_8 [ V_4 - 1 ] ;
V_11 = ( T_2 * ) V_8 [ V_6 ] ;
V_8 [ V_6 ] = ( void * ) V_17 ;
V_8 [ V_4 - 2 ] = V_11 ;
V_12 = ( T_2 * ) V_8 [ V_7 ] ;
V_8 [ V_7 ] = ( void * ) V_17 ;
V_8 [ V_4 - 1 ] = V_12 ;
V_18 . V_19 ( V_4 , V_5 , V_8 ) ;
V_8 [ V_6 ] = V_11 ;
V_8 [ V_7 ] = V_12 ;
V_8 [ V_4 - 2 ] = V_9 ;
V_8 [ V_4 - 1 ] = V_10 ;
V_13 = V_20 [ V_21 [ V_7 - V_6 ] ] ;
V_14 = V_20 [ V_22 [ V_23 [ V_6 ] ^
V_23 [ V_7 ] ] ] ;
F_4 () ;
asm volatile("movdqa %0,%%xmm7" : : "m" (x0f[0]));
#ifdef F_5
asm volatile("movdqa %0,%%xmm6" : : "m" (qmul[0]));
asm volatile("movdqa %0,%%xmm14" : : "m" (pbmul[0]));
asm volatile("movdqa %0,%%xmm15" : : "m" (pbmul[16]));
#endif
while ( V_5 ) {
#ifdef F_5
asm volatile("movdqa %0,%%xmm1" : : "m" (q[0]));
asm volatile("movdqa %0,%%xmm9" : : "m" (q[16]));
asm volatile("movdqa %0,%%xmm0" : : "m" (p[0]));
asm volatile("movdqa %0,%%xmm8" : : "m" (p[16]));
asm volatile("pxor %0,%%xmm1" : : "m" (dq[0]));
asm volatile("pxor %0,%%xmm9" : : "m" (dq[16]));
asm volatile("pxor %0,%%xmm0" : : "m" (dp[0]));
asm volatile("pxor %0,%%xmm8" : : "m" (dp[16]));
asm volatile("movdqa %xmm6,%xmm4");
asm volatile("movdqa %0,%%xmm5" : : "m" (qmul[16]));
asm volatile("movdqa %xmm6,%xmm12");
asm volatile("movdqa %xmm5,%xmm13");
asm volatile("movdqa %xmm1,%xmm3");
asm volatile("movdqa %xmm9,%xmm11");
asm volatile("movdqa %xmm0,%xmm2");
asm volatile("movdqa %xmm8,%xmm10");
asm volatile("psraw $4,%xmm1");
asm volatile("psraw $4,%xmm9");
asm volatile("pand %xmm7,%xmm3");
asm volatile("pand %xmm7,%xmm11");
asm volatile("pand %xmm7,%xmm1");
asm volatile("pand %xmm7,%xmm9");
asm volatile("pshufb %xmm3,%xmm4");
asm volatile("pshufb %xmm11,%xmm12");
asm volatile("pshufb %xmm1,%xmm5");
asm volatile("pshufb %xmm9,%xmm13");
asm volatile("pxor %xmm4,%xmm5");
asm volatile("pxor %xmm12,%xmm13");
asm volatile("movdqa %xmm14,%xmm4");
asm volatile("movdqa %xmm15,%xmm1");
asm volatile("movdqa %xmm14,%xmm12");
asm volatile("movdqa %xmm15,%xmm9");
asm volatile("movdqa %xmm2,%xmm3");
asm volatile("movdqa %xmm10,%xmm11");
asm volatile("psraw $4,%xmm2");
asm volatile("psraw $4,%xmm10");
asm volatile("pand %xmm7,%xmm3");
asm volatile("pand %xmm7,%xmm11");
asm volatile("pand %xmm7,%xmm2");
asm volatile("pand %xmm7,%xmm10");
asm volatile("pshufb %xmm3,%xmm4");
asm volatile("pshufb %xmm11,%xmm12");
asm volatile("pshufb %xmm2,%xmm1");
asm volatile("pshufb %xmm10,%xmm9");
asm volatile("pxor %xmm4,%xmm1");
asm volatile("pxor %xmm12,%xmm9");
asm volatile("pxor %xmm5,%xmm1");
asm volatile("pxor %xmm13,%xmm9");
asm volatile("movdqa %%xmm1,%0" : "=m" (dq[0]));
asm volatile("movdqa %%xmm9,%0" : "=m" (dq[16]));
asm volatile("pxor %xmm1,%xmm0");
asm volatile("pxor %xmm9,%xmm8");
asm volatile("movdqa %%xmm0,%0" : "=m" (dp[0]));
asm volatile("movdqa %%xmm8,%0" : "=m" (dp[16]));
V_5 -= 32 ;
V_9 += 32 ;
V_10 += 32 ;
V_11 += 32 ;
V_12 += 32 ;
#else
asm volatile("movdqa %0,%%xmm1" : : "m" (*q));
asm volatile("movdqa %0,%%xmm0" : : "m" (*p));
asm volatile("pxor %0,%%xmm1" : : "m" (*dq));
asm volatile("pxor %0,%%xmm0" : : "m" (*dp));
asm volatile("movdqa %0,%%xmm4" : : "m" (qmul[0]));
asm volatile("movdqa %0,%%xmm5" : : "m" (qmul[16]));
asm volatile("movdqa %xmm1,%xmm3");
asm volatile("psraw $4,%xmm1");
asm volatile("pand %xmm7,%xmm3");
asm volatile("pand %xmm7,%xmm1");
asm volatile("pshufb %xmm3,%xmm4");
asm volatile("pshufb %xmm1,%xmm5");
asm volatile("pxor %xmm4,%xmm5");
asm volatile("movdqa %xmm0,%xmm2");
asm volatile("movdqa %0,%%xmm4" : : "m" (pbmul[0]));
asm volatile("movdqa %0,%%xmm1" : : "m" (pbmul[16]));
asm volatile("movdqa %xmm2,%xmm3");
asm volatile("psraw $4,%xmm2");
asm volatile("pand %xmm7,%xmm3");
asm volatile("pand %xmm7,%xmm2");
asm volatile("pshufb %xmm3,%xmm4");
asm volatile("pshufb %xmm2,%xmm1");
asm volatile("pxor %xmm4,%xmm1");
asm volatile("pxor %xmm5,%xmm1");
asm volatile("movdqa %%xmm1,%0" : "=m" (*dq));
asm volatile("pxor %xmm1,%xmm0");
asm volatile("movdqa %%xmm0,%0" : "=m" (*dp));
V_5 -= 16 ;
V_9 += 16 ;
V_10 += 16 ;
V_11 += 16 ;
V_12 += 16 ;
#endif
}
F_6 () ;
}
static void F_7 ( int V_4 , T_1 V_5 , int V_6 ,
void * * V_8 )
{
T_2 * V_9 , * V_10 , * V_12 ;
const T_2 * V_14 ;
static const T_2 V_15 ( 16 ) V_16 [ 16 ] = {
0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f ,
0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f , 0x0f } ;
V_9 = ( T_2 * ) V_8 [ V_4 - 2 ] ;
V_10 = ( T_2 * ) V_8 [ V_4 - 1 ] ;
V_12 = ( T_2 * ) V_8 [ V_6 ] ;
V_8 [ V_6 ] = ( void * ) V_17 ;
V_8 [ V_4 - 1 ] = V_12 ;
V_18 . V_19 ( V_4 , V_5 , V_8 ) ;
V_8 [ V_6 ] = V_12 ;
V_8 [ V_4 - 1 ] = V_10 ;
V_14 = V_20 [ V_22 [ V_23 [ V_6 ] ] ] ;
F_4 () ;
asm volatile("movdqa %0, %%xmm7" : : "m" (x0f[0]));
while ( V_5 ) {
#ifdef F_5
asm volatile("movdqa %0, %%xmm3" : : "m" (dq[0]));
asm volatile("movdqa %0, %%xmm4" : : "m" (dq[16]));
asm volatile("pxor %0, %%xmm3" : : "m" (q[0]));
asm volatile("movdqa %0, %%xmm0" : : "m" (qmul[0]));
asm volatile("pxor %0, %%xmm4" : : "m" (q[16]));
asm volatile("movdqa %0, %%xmm1" : : "m" (qmul[16]));
asm volatile("movdqa %xmm3, %xmm6");
asm volatile("movdqa %xmm4, %xmm8");
asm volatile("psraw $4, %xmm3");
asm volatile("pand %xmm7, %xmm6");
asm volatile("pand %xmm7, %xmm3");
asm volatile("pshufb %xmm6, %xmm0");
asm volatile("pshufb %xmm3, %xmm1");
asm volatile("movdqa %0, %%xmm10" : : "m" (qmul[0]));
asm volatile("pxor %xmm0, %xmm1");
asm volatile("movdqa %0, %%xmm11" : : "m" (qmul[16]));
asm volatile("psraw $4, %xmm4");
asm volatile("pand %xmm7, %xmm8");
asm volatile("pand %xmm7, %xmm4");
asm volatile("pshufb %xmm8, %xmm10");
asm volatile("pshufb %xmm4, %xmm11");
asm volatile("movdqa %0, %%xmm2" : : "m" (p[0]));
asm volatile("pxor %xmm10, %xmm11");
asm volatile("movdqa %0, %%xmm12" : : "m" (p[16]));
asm volatile("pxor %xmm1, %xmm2");
asm volatile("pxor %xmm11, %xmm12");
asm volatile("movdqa %%xmm1, %0" : "=m" (dq[0]));
asm volatile("movdqa %%xmm11, %0" : "=m" (dq[16]));
asm volatile("movdqa %%xmm2, %0" : "=m" (p[0]));
asm volatile("movdqa %%xmm12, %0" : "=m" (p[16]));
V_5 -= 32 ;
V_9 += 32 ;
V_10 += 32 ;
V_12 += 32 ;
#else
asm volatile("movdqa %0, %%xmm3" : : "m" (dq[0]));
asm volatile("movdqa %0, %%xmm0" : : "m" (qmul[0]));
asm volatile("pxor %0, %%xmm3" : : "m" (q[0]));
asm volatile("movdqa %0, %%xmm1" : : "m" (qmul[16]));
asm volatile("movdqa %xmm3, %xmm6");
asm volatile("movdqa %0, %%xmm2" : : "m" (p[0]));
asm volatile("psraw $4, %xmm3");
asm volatile("pand %xmm7, %xmm6");
asm volatile("pand %xmm7, %xmm3");
asm volatile("pshufb %xmm6, %xmm0");
asm volatile("pshufb %xmm3, %xmm1");
asm volatile("pxor %xmm0, %xmm1");
asm volatile("pxor %xmm1, %xmm2");
asm volatile("movdqa %%xmm1, %0" : "=m" (dq[0]));
asm volatile("movdqa %%xmm2, %0" : "=m" (p[0]));
V_5 -= 16 ;
V_9 += 16 ;
V_10 += 16 ;
V_12 += 16 ;
#endif
}
F_6 () ;
}
