static int F_1 ( void )
{
return F_2 ( V_1 ) &&
F_2 ( V_2 ) ;
}
static void F_3 ( int V_3 , T_1 V_4 , int V_5 ,
int V_6 , void * * V_7 )
{
T_2 * V_8 , * V_9 , * V_10 , * V_11 ;
const T_2 * V_12 ;
const T_2 * V_13 ;
const T_2 V_14 = 0x0f ;
V_8 = ( T_2 * ) V_7 [ V_3 - 2 ] ;
V_9 = ( T_2 * ) V_7 [ V_3 - 1 ] ;
V_10 = ( T_2 * ) V_7 [ V_5 ] ;
V_7 [ V_5 ] = ( void * ) V_15 ;
V_7 [ V_3 - 2 ] = V_10 ;
V_11 = ( T_2 * ) V_7 [ V_6 ] ;
V_7 [ V_6 ] = ( void * ) V_15 ;
V_7 [ V_3 - 1 ] = V_11 ;
V_16 . V_17 ( V_3 , V_4 , V_7 ) ;
V_7 [ V_5 ] = V_10 ;
V_7 [ V_6 ] = V_11 ;
V_7 [ V_3 - 2 ] = V_8 ;
V_7 [ V_3 - 1 ] = V_9 ;
V_12 = V_18 [ V_19 [ V_6 - V_5 ] ] ;
V_13 = V_18 [ V_20 [ V_21 [ V_5 ] ^
V_21 [ V_6 ] ] ] ;
F_4 () ;
asm volatile("vpbroadcastb %0, %%ymm7" : : "m" (x0f));
while ( V_4 ) {
#ifdef F_5
asm volatile("vmovdqa %0, %%ymm1" : : "m" (q[0]));
asm volatile("vmovdqa %0, %%ymm9" : : "m" (q[32]));
asm volatile("vmovdqa %0, %%ymm0" : : "m" (p[0]));
asm volatile("vmovdqa %0, %%ymm8" : : "m" (p[32]));
asm volatile("vpxor %0, %%ymm1, %%ymm1" : : "m" (dq[0]));
asm volatile("vpxor %0, %%ymm9, %%ymm9" : : "m" (dq[32]));
asm volatile("vpxor %0, %%ymm0, %%ymm0" : : "m" (dp[0]));
asm volatile("vpxor %0, %%ymm8, %%ymm8" : : "m" (dp[32]));
asm volatile("vbroadcasti128 %0, %%ymm4" : : "m" (qmul[0]));
asm volatile("vbroadcasti128 %0, %%ymm5" : : "m" (qmul[16]));
asm volatile("vpsraw $4, %ymm1, %ymm3");
asm volatile("vpsraw $4, %ymm9, %ymm12");
asm volatile("vpand %ymm7, %ymm1, %ymm1");
asm volatile("vpand %ymm7, %ymm9, %ymm9");
asm volatile("vpand %ymm7, %ymm3, %ymm3");
asm volatile("vpand %ymm7, %ymm12, %ymm12");
asm volatile("vpshufb %ymm9, %ymm4, %ymm14");
asm volatile("vpshufb %ymm1, %ymm4, %ymm4");
asm volatile("vpshufb %ymm12, %ymm5, %ymm15");
asm volatile("vpshufb %ymm3, %ymm5, %ymm5");
asm volatile("vpxor %ymm14, %ymm15, %ymm15");
asm volatile("vpxor %ymm4, %ymm5, %ymm5");
asm volatile("vbroadcasti128 %0, %%ymm4" : : "m" (pbmul[0]));
asm volatile("vbroadcasti128 %0, %%ymm1" : : "m" (pbmul[16]));
asm volatile("vpsraw $4, %ymm0, %ymm2");
asm volatile("vpsraw $4, %ymm8, %ymm6");
asm volatile("vpand %ymm7, %ymm0, %ymm3");
asm volatile("vpand %ymm7, %ymm8, %ymm14");
asm volatile("vpand %ymm7, %ymm2, %ymm2");
asm volatile("vpand %ymm7, %ymm6, %ymm6");
asm volatile("vpshufb %ymm14, %ymm4, %ymm12");
asm volatile("vpshufb %ymm3, %ymm4, %ymm4");
asm volatile("vpshufb %ymm6, %ymm1, %ymm13");
asm volatile("vpshufb %ymm2, %ymm1, %ymm1");
asm volatile("vpxor %ymm4, %ymm1, %ymm1");
asm volatile("vpxor %ymm12, %ymm13, %ymm13");
asm volatile("vpxor %ymm5, %ymm1, %ymm1");
asm volatile("vpxor %ymm15, %ymm13, %ymm13");
asm volatile("vmovdqa %%ymm1, %0" : "=m" (dq[0]));
asm volatile("vmovdqa %%ymm13,%0" : "=m" (dq[32]));
asm volatile("vpxor %ymm1, %ymm0, %ymm0");
asm volatile("vpxor %ymm13, %ymm8, %ymm8");
asm volatile("vmovdqa %%ymm0, %0" : "=m" (dp[0]));
asm volatile("vmovdqa %%ymm8, %0" : "=m" (dp[32]));
V_4 -= 64 ;
V_8 += 64 ;
V_9 += 64 ;
V_10 += 64 ;
V_11 += 64 ;
#else
asm volatile("vmovdqa %0, %%ymm1" : : "m" (*q));
asm volatile("vmovdqa %0, %%ymm0" : : "m" (*p));
asm volatile("vpxor %0, %%ymm1, %%ymm1" : : "m" (*dq));
asm volatile("vpxor %0, %%ymm0, %%ymm0" : : "m" (*dp));
asm volatile("vbroadcasti128 %0, %%ymm4" : : "m" (qmul[0]));
asm volatile("vbroadcasti128 %0, %%ymm5" : : "m" (qmul[16]));
asm volatile("vpsraw $4, %ymm1, %ymm3");
asm volatile("vpand %ymm7, %ymm1, %ymm1");
asm volatile("vpand %ymm7, %ymm3, %ymm3");
asm volatile("vpshufb %ymm1, %ymm4, %ymm4");
asm volatile("vpshufb %ymm3, %ymm5, %ymm5");
asm volatile("vpxor %ymm4, %ymm5, %ymm5");
asm volatile("vbroadcasti128 %0, %%ymm4" : : "m" (pbmul[0]));
asm volatile("vbroadcasti128 %0, %%ymm1" : : "m" (pbmul[16]));
asm volatile("vpsraw $4, %ymm0, %ymm2");
asm volatile("vpand %ymm7, %ymm0, %ymm3");
asm volatile("vpand %ymm7, %ymm2, %ymm2");
asm volatile("vpshufb %ymm3, %ymm4, %ymm4");
asm volatile("vpshufb %ymm2, %ymm1, %ymm1");
asm volatile("vpxor %ymm4, %ymm1, %ymm1");
asm volatile("vpxor %ymm5, %ymm1, %ymm1");
asm volatile("vmovdqa %%ymm1, %0" : "=m" (dq[0]));
asm volatile("vpxor %ymm1, %ymm0, %ymm0");
asm volatile("vmovdqa %%ymm0, %0" : "=m" (dp[0]));
V_4 -= 32 ;
V_8 += 32 ;
V_9 += 32 ;
V_10 += 32 ;
V_11 += 32 ;
#endif
}
F_6 () ;
}
static void F_7 ( int V_3 , T_1 V_4 , int V_5 ,
void * * V_7 )
{
T_2 * V_8 , * V_9 , * V_11 ;
const T_2 * V_13 ;
const T_2 V_14 = 0x0f ;
V_8 = ( T_2 * ) V_7 [ V_3 - 2 ] ;
V_9 = ( T_2 * ) V_7 [ V_3 - 1 ] ;
V_11 = ( T_2 * ) V_7 [ V_5 ] ;
V_7 [ V_5 ] = ( void * ) V_15 ;
V_7 [ V_3 - 1 ] = V_11 ;
V_16 . V_17 ( V_3 , V_4 , V_7 ) ;
V_7 [ V_5 ] = V_11 ;
V_7 [ V_3 - 1 ] = V_9 ;
V_13 = V_18 [ V_20 [ V_21 [ V_5 ] ] ] ;
F_4 () ;
asm volatile("vpbroadcastb %0, %%ymm7" : : "m" (x0f));
while ( V_4 ) {
#ifdef F_5
asm volatile("vmovdqa %0, %%ymm3" : : "m" (dq[0]));
asm volatile("vmovdqa %0, %%ymm8" : : "m" (dq[32]));
asm volatile("vpxor %0, %%ymm3, %%ymm3" : : "m" (q[0]));
asm volatile("vpxor %0, %%ymm8, %%ymm8" : : "m" (q[32]));
asm volatile("vbroadcasti128 %0, %%ymm0" : : "m" (qmul[0]));
asm volatile("vmovapd %ymm0, %ymm13");
asm volatile("vbroadcasti128 %0, %%ymm1" : : "m" (qmul[16]));
asm volatile("vmovapd %ymm1, %ymm14");
asm volatile("vpsraw $4, %ymm3, %ymm6");
asm volatile("vpsraw $4, %ymm8, %ymm12");
asm volatile("vpand %ymm7, %ymm3, %ymm3");
asm volatile("vpand %ymm7, %ymm8, %ymm8");
asm volatile("vpand %ymm7, %ymm6, %ymm6");
asm volatile("vpand %ymm7, %ymm12, %ymm12");
asm volatile("vpshufb %ymm3, %ymm0, %ymm0");
asm volatile("vpshufb %ymm8, %ymm13, %ymm13");
asm volatile("vpshufb %ymm6, %ymm1, %ymm1");
asm volatile("vpshufb %ymm12, %ymm14, %ymm14");
asm volatile("vpxor %ymm0, %ymm1, %ymm1");
asm volatile("vpxor %ymm13, %ymm14, %ymm14");
asm volatile("vmovdqa %0, %%ymm2" : : "m" (p[0]));
asm volatile("vmovdqa %0, %%ymm12" : : "m" (p[32]));
asm volatile("vpxor %ymm1, %ymm2, %ymm2");
asm volatile("vpxor %ymm14, %ymm12, %ymm12");
asm volatile("vmovdqa %%ymm1, %0" : "=m" (dq[0]));
asm volatile("vmovdqa %%ymm14, %0" : "=m" (dq[32]));
asm volatile("vmovdqa %%ymm2, %0" : "=m" (p[0]));
asm volatile("vmovdqa %%ymm12,%0" : "=m" (p[32]));
V_4 -= 64 ;
V_8 += 64 ;
V_9 += 64 ;
V_11 += 64 ;
#else
asm volatile("vmovdqa %0, %%ymm3" : : "m" (dq[0]));
asm volatile("vpxor %0, %%ymm3, %%ymm3" : : "m" (q[0]));
asm volatile("vbroadcasti128 %0, %%ymm0" : : "m" (qmul[0]));
asm volatile("vbroadcasti128 %0, %%ymm1" : : "m" (qmul[16]));
asm volatile("vpsraw $4, %ymm3, %ymm6");
asm volatile("vpand %ymm7, %ymm3, %ymm3");
asm volatile("vpand %ymm7, %ymm6, %ymm6");
asm volatile("vpshufb %ymm3, %ymm0, %ymm0");
asm volatile("vpshufb %ymm6, %ymm1, %ymm1");
asm volatile("vpxor %ymm0, %ymm1, %ymm1");
asm volatile("vmovdqa %0, %%ymm2" : : "m" (p[0]));
asm volatile("vpxor %ymm1, %ymm2, %ymm2");
asm volatile("vmovdqa %%ymm1, %0" : "=m" (dq[0]));
asm volatile("vmovdqa %%ymm2, %0" : "=m" (p[0]));
V_4 -= 32 ;
V_8 += 32 ;
V_9 += 32 ;
V_11 += 32 ;
#endif
}
F_6 () ;
}
