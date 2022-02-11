static void T_1 F_1 ( T_2 V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_6 = ( V_1 >> 16 ) & 0xf ;
int V_7 = V_1 & ( 1 << 20 ) ;
int V_8 = V_1 & ( 1 << 21 ) ;
int V_9 = V_1 & ( 1 << 23 ) ;
int V_10 = V_1 & ( 1 << 24 ) ;
long * V_11 = ( long * ) V_5 -> V_12 [ V_6 ] ;
int V_13 ;
int V_14 ;
V_14 = 0 ;
V_13 = V_1 & 0xffff ;
while ( V_13 ) {
V_13 &= ( V_13 - 1 ) ;
++ V_14 ;
}
if ( ! V_9 )
V_11 -= V_14 ;
V_11 += ( ! V_10 == ! V_9 ) ;
V_13 = V_1 & 0xffff ;
while ( V_13 ) {
int V_15 = F_2 ( V_13 ) ;
V_13 &= ( V_13 - 1 ) ;
if ( V_7 )
V_5 -> V_12 [ V_15 ] = * V_11 ++ ;
else
* V_11 ++ = V_5 -> V_12 [ V_15 ] ;
}
if ( V_8 ) {
if ( ! V_9 )
V_11 -= V_14 ;
V_11 -= ( ! V_10 == ! V_9 ) ;
V_5 -> V_12 [ V_6 ] = ( long ) V_11 ;
}
}
static void T_1 F_3 ( T_2 V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
unsigned long V_11 = V_5 -> V_16 - 4 ;
V_5 -> V_16 = ( long ) V_11 + V_17 ;
F_1 ( V_1 , V_3 , V_5 ) ;
V_5 -> V_16 = ( long ) V_11 + 4 ;
}
static void T_1 F_4 ( T_2 V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_1 ( V_1 , V_3 , V_5 ) ;
F_5 ( V_5 -> V_16 , V_5 ) ;
}
static void T_1
F_6 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
register void * T_3 V_18 ( L_1 ) = V_5 ;
register void * T_4 V_18 ( L_2 ) = V_3 -> V_19 ;
__asm__ __volatile__ (
"stmdb sp!, {%[regs], r11} \n\t"
"ldmia %[regs], {r0-r12} \n\t"
#if V_20 >= 6
"blx %[fn] \n\t"
#else
"str %[fn], [sp, #-4]! \n\t"
"adr lr, 1f \n\t"
"ldr pc, [sp], #4 \n\t"
"1: \n\t"
#endif
"ldr lr, [sp], #4 \n\t"
"stmia lr, {r0-r12} \n\t"
"ldr r11, [sp], #4 \n\t"
: [regs] "=r" (rregs), [fn] "=r" (rfn)
: "0" (rregs), "1" (rfn)
: "r0", "r2", "r3", "r4", "r5", "r6", "r7",
"r8", "r9", "r10", "r12", "memory", "cc"
);
}
static void T_1
F_7 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
F_6 ( V_1 , V_3 ,
(struct V_4 * ) ( V_5 -> V_12 + 2 ) ) ;
}
static void T_1
F_8 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
F_6 ( V_1 , V_3 ,
(struct V_4 * ) ( V_5 -> V_12 + 3 ) ) ;
F_5 ( V_5 -> V_16 , V_5 ) ;
}
enum V_21 T_1
F_9 ( T_2 V_1 , struct V_2 * V_3 ,
const struct V_22 * V_23 )
{
T_5 * V_24 = 0 ;
unsigned V_25 = V_1 & 0xffff ;
int V_26 = V_1 & 0x100000 ;
int V_6 = ( V_1 >> 16 ) & 0xf ;
if ( V_6 <= 12 && ( V_25 & 0xe000 ) == 0 ) {
V_24 = F_6 ;
} else if ( V_6 >= 2 && ( V_25 & 0x8003 ) == 0 ) {
V_6 -= 2 ;
V_25 >>= 2 ;
V_24 = F_7 ;
} else if ( V_6 >= 3 && ( V_25 & 0x0007 ) == 0 ) {
if ( V_26 && ( V_25 & 0x8000 ) ) {
V_6 -= 3 ;
V_25 >>= 3 ;
V_24 = F_8 ;
}
}
if ( V_24 ) {
V_3 -> V_1 [ 0 ] = F_10 ( ( V_1 & 0xfff00000 ) |
( V_6 << 16 ) | V_25 ) ;
V_3 -> V_27 = V_24 ;
return V_28 ;
}
if ( V_25 & 0x8000 )
V_24 = V_26 ? F_4 : F_3 ;
else
V_24 = F_1 ;
V_3 -> V_27 = V_24 ;
return V_29 ;
}
