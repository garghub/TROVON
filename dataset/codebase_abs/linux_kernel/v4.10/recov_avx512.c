static int F_1 ( void )
{
return F_2 ( V_1 ) &&
F_2 ( V_2 ) &&
F_2 ( V_3 ) &&
F_2 ( V_4 ) &&
F_2 ( V_5 ) &&
F_2 ( V_6 ) ;
}
static void F_3 ( int V_7 , T_1 V_8 , int V_9 ,
int V_10 , void * * V_11 )
{
T_2 * V_12 , * V_13 , * V_14 , * V_15 ;
const T_2 * V_16 ;
const T_2 * V_17 ;
const T_2 V_18 = 0x0f ;
V_12 = ( T_2 * ) V_11 [ V_7 - 2 ] ;
V_13 = ( T_2 * ) V_11 [ V_7 - 1 ] ;
V_14 = ( T_2 * ) V_11 [ V_9 ] ;
V_11 [ V_9 ] = ( void * ) V_19 ;
V_11 [ V_7 - 2 ] = V_14 ;
V_15 = ( T_2 * ) V_11 [ V_10 ] ;
V_11 [ V_10 ] = ( void * ) V_19 ;
V_11 [ V_7 - 1 ] = V_15 ;
V_20 . V_21 ( V_7 , V_8 , V_11 ) ;
V_11 [ V_9 ] = V_14 ;
V_11 [ V_10 ] = V_15 ;
V_11 [ V_7 - 2 ] = V_12 ;
V_11 [ V_7 - 1 ] = V_13 ;
V_16 = V_22 [ V_23 [ V_10 - V_9 ] ] ;
V_17 = V_22 [ V_24 [ V_25 [ V_9 ] ^
V_25 [ V_10 ] ] ] ;
F_4 () ;
asm volatile("vpbroadcastb %0, %%zmm7" : : "m" (x0f));
while ( V_8 ) {
#ifdef F_5
asm volatile("vmovdqa64 %0, %%zmm1\n\t"
"vmovdqa64 %1, %%zmm9\n\t"
"vmovdqa64 %2, %%zmm0\n\t"
"vmovdqa64 %3, %%zmm8\n\t"
"vpxorq %4, %%zmm1, %%zmm1\n\t"
"vpxorq %5, %%zmm9, %%zmm9\n\t"
"vpxorq %6, %%zmm0, %%zmm0\n\t"
"vpxorq %7, %%zmm8, %%zmm8"
:
: "m" (q[0]), "m" (q[64]), "m" (p[0]),
"m" (p[64]), "m" (dq[0]), "m" (dq[64]),
"m" (dp[0]), "m" (dp[64]));
asm volatile("vbroadcasti64x2 %0, %%zmm4\n\t"
"vbroadcasti64x2 %1, %%zmm5"
:
: "m" (qmul[0]), "m" (qmul[16]));
asm volatile("vpsraw $4, %%zmm1, %%zmm3\n\t"
"vpsraw $4, %%zmm9, %%zmm12\n\t"
"vpandq %%zmm7, %%zmm1, %%zmm1\n\t"
"vpandq %%zmm7, %%zmm9, %%zmm9\n\t"
"vpandq %%zmm7, %%zmm3, %%zmm3\n\t"
"vpandq %%zmm7, %%zmm12, %%zmm12\n\t"
"vpshufb %%zmm9, %%zmm4, %%zmm14\n\t"
"vpshufb %%zmm1, %%zmm4, %%zmm4\n\t"
"vpshufb %%zmm12, %%zmm5, %%zmm15\n\t"
"vpshufb %%zmm3, %%zmm5, %%zmm5\n\t"
"vpxorq %%zmm14, %%zmm15, %%zmm15\n\t"
"vpxorq %%zmm4, %%zmm5, %%zmm5"
:
: );
asm volatile("vbroadcasti64x2 %0, %%zmm4\n\t"
"vbroadcasti64x2 %1, %%zmm1\n\t"
"vpsraw $4, %%zmm0, %%zmm2\n\t"
"vpsraw $4, %%zmm8, %%zmm6\n\t"
"vpandq %%zmm7, %%zmm0, %%zmm3\n\t"
"vpandq %%zmm7, %%zmm8, %%zmm14\n\t"
"vpandq %%zmm7, %%zmm2, %%zmm2\n\t"
"vpandq %%zmm7, %%zmm6, %%zmm6\n\t"
"vpshufb %%zmm14, %%zmm4, %%zmm12\n\t"
"vpshufb %%zmm3, %%zmm4, %%zmm4\n\t"
"vpshufb %%zmm6, %%zmm1, %%zmm13\n\t"
"vpshufb %%zmm2, %%zmm1, %%zmm1\n\t"
"vpxorq %%zmm4, %%zmm1, %%zmm1\n\t"
"vpxorq %%zmm12, %%zmm13, %%zmm13"
:
: "m" (pbmul[0]), "m" (pbmul[16]));
asm volatile("vpxorq %%zmm5, %%zmm1, %%zmm1\n\t"
"vpxorq %%zmm15, %%zmm13, %%zmm13"
:
: );
asm volatile("vmovdqa64 %%zmm1, %0\n\t"
"vmovdqa64 %%zmm13,%1\n\t"
"vpxorq %%zmm1, %%zmm0, %%zmm0\n\t"
"vpxorq %%zmm13, %%zmm8, %%zmm8"
:
: "m" (dq[0]), "m" (dq[64]));
asm volatile("vmovdqa64 %%zmm0, %0\n\t"
"vmovdqa64 %%zmm8, %1"
:
: "m" (dp[0]), "m" (dp[64]));
V_8 -= 128 ;
V_12 += 128 ;
V_13 += 128 ;
V_14 += 128 ;
V_15 += 128 ;
#else
asm volatile("vmovdqa64 %0, %%zmm1\n\t"
"vmovdqa64 %1, %%zmm0\n\t"
"vpxorq %2, %%zmm1, %%zmm1\n\t"
"vpxorq %3, %%zmm0, %%zmm0"
:
: "m" (*q), "m" (*p), "m"(*dq), "m" (*dp));
asm volatile("vbroadcasti64x2 %0, %%zmm4\n\t"
"vbroadcasti64x2 %1, %%zmm5"
:
: "m" (qmul[0]), "m" (qmul[16]));
asm volatile("vpsraw $4, %%zmm1, %%zmm3\n\t"
"vpandq %%zmm7, %%zmm1, %%zmm1\n\t"
"vpandq %%zmm7, %%zmm3, %%zmm3\n\t"
"vpshufb %%zmm1, %%zmm4, %%zmm4\n\t"
"vpshufb %%zmm3, %%zmm5, %%zmm5\n\t"
"vpxorq %%zmm4, %%zmm5, %%zmm5"
:
: );
asm volatile("vbroadcasti64x2 %0, %%zmm4\n\t"
"vbroadcasti64x2 %1, %%zmm1"
:
: "m" (pbmul[0]), "m" (pbmul[16]));
asm volatile("vpsraw $4, %%zmm0, %%zmm2\n\t"
"vpandq %%zmm7, %%zmm0, %%zmm3\n\t"
"vpandq %%zmm7, %%zmm2, %%zmm2\n\t"
"vpshufb %%zmm3, %%zmm4, %%zmm4\n\t"
"vpshufb %%zmm2, %%zmm1, %%zmm1\n\t"
"vpxorq %%zmm4, %%zmm1, %%zmm1"
:
: );
asm volatile("vpxorq %%zmm5, %%zmm1, %%zmm1\n\t"
"vmovdqa64 %%zmm1, %0\n\t"
:
: "m" (dq[0]));
asm volatile("vpxorq %%zmm1, %%zmm0, %%zmm0\n\t"
"vmovdqa64 %%zmm0, %0"
:
: "m" (dp[0]));
V_8 -= 64 ;
V_12 += 64 ;
V_13 += 64 ;
V_14 += 64 ;
V_15 += 64 ;
#endif
}
F_6 () ;
}
static void F_7 ( int V_7 , T_1 V_8 , int V_9 ,
void * * V_11 )
{
T_2 * V_12 , * V_13 , * V_15 ;
const T_2 * V_17 ;
const T_2 V_18 = 0x0f ;
V_12 = ( T_2 * ) V_11 [ V_7 - 2 ] ;
V_13 = ( T_2 * ) V_11 [ V_7 - 1 ] ;
V_15 = ( T_2 * ) V_11 [ V_9 ] ;
V_11 [ V_9 ] = ( void * ) V_19 ;
V_11 [ V_7 - 1 ] = V_15 ;
V_20 . V_21 ( V_7 , V_8 , V_11 ) ;
V_11 [ V_9 ] = V_15 ;
V_11 [ V_7 - 1 ] = V_13 ;
V_17 = V_22 [ V_24 [ V_25 [ V_9 ] ] ] ;
F_4 () ;
asm volatile("vpbroadcastb %0, %%zmm7" : : "m" (x0f));
while ( V_8 ) {
#ifdef F_5
asm volatile("vmovdqa64 %0, %%zmm3\n\t"
"vmovdqa64 %1, %%zmm8\n\t"
"vpxorq %2, %%zmm3, %%zmm3\n\t"
"vpxorq %3, %%zmm8, %%zmm8"
:
: "m" (dq[0]), "m" (dq[64]), "m" (q[0]),
"m" (q[64]));
asm volatile("vbroadcasti64x2 %0, %%zmm0\n\t"
"vmovapd %%zmm0, %%zmm13\n\t"
"vbroadcasti64x2 %1, %%zmm1\n\t"
"vmovapd %%zmm1, %%zmm14"
:
: "m" (qmul[0]), "m" (qmul[16]));
asm volatile("vpsraw $4, %%zmm3, %%zmm6\n\t"
"vpsraw $4, %%zmm8, %%zmm12\n\t"
"vpandq %%zmm7, %%zmm3, %%zmm3\n\t"
"vpandq %%zmm7, %%zmm8, %%zmm8\n\t"
"vpandq %%zmm7, %%zmm6, %%zmm6\n\t"
"vpandq %%zmm7, %%zmm12, %%zmm12\n\t"
"vpshufb %%zmm3, %%zmm0, %%zmm0\n\t"
"vpshufb %%zmm8, %%zmm13, %%zmm13\n\t"
"vpshufb %%zmm6, %%zmm1, %%zmm1\n\t"
"vpshufb %%zmm12, %%zmm14, %%zmm14\n\t"
"vpxorq %%zmm0, %%zmm1, %%zmm1\n\t"
"vpxorq %%zmm13, %%zmm14, %%zmm14"
:
: );
asm volatile("vmovdqa64 %0, %%zmm2\n\t"
"vmovdqa64 %1, %%zmm12\n\t"
"vpxorq %%zmm1, %%zmm2, %%zmm2\n\t"
"vpxorq %%zmm14, %%zmm12, %%zmm12"
:
: "m" (p[0]), "m" (p[64]));
asm volatile("vmovdqa64 %%zmm1, %0\n\t"
"vmovdqa64 %%zmm14, %1\n\t"
"vmovdqa64 %%zmm2, %2\n\t"
"vmovdqa64 %%zmm12,%3"
:
: "m" (dq[0]), "m" (dq[64]), "m" (p[0]),
"m" (p[64]));
V_8 -= 128 ;
V_12 += 128 ;
V_13 += 128 ;
V_15 += 128 ;
#else
asm volatile("vmovdqa64 %0, %%zmm3\n\t"
"vpxorq %1, %%zmm3, %%zmm3"
:
: "m" (dq[0]), "m" (q[0]));
asm volatile("vbroadcasti64x2 %0, %%zmm0\n\t"
"vbroadcasti64x2 %1, %%zmm1"
:
: "m" (qmul[0]), "m" (qmul[16]));
asm volatile("vpsraw $4, %%zmm3, %%zmm6\n\t"
"vpandq %%zmm7, %%zmm3, %%zmm3\n\t"
"vpandq %%zmm7, %%zmm6, %%zmm6\n\t"
"vpshufb %%zmm3, %%zmm0, %%zmm0\n\t"
"vpshufb %%zmm6, %%zmm1, %%zmm1\n\t"
"vpxorq %%zmm0, %%zmm1, %%zmm1"
:
: );
asm volatile("vmovdqa64 %0, %%zmm2\n\t"
"vpxorq %%zmm1, %%zmm2, %%zmm2"
:
: "m" (p[0]));
asm volatile("vmovdqa64 %%zmm1, %0\n\t"
"vmovdqa64 %%zmm2, %1"
:
: "m" (dq[0]), "m" (p[0]));
V_8 -= 64 ;
V_12 += 64 ;
V_13 += 64 ;
V_15 += 64 ;
#endif
}
F_6 () ;
}
