static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 , V_4 = ( 1 << V_1 ) ;
unsigned int V_5 = V_6 [ V_2 ] ;
F_2 ( L_1 , V_7 , V_1 , V_2 ) ;
if ( V_1 >= 4 || V_2 >= 2 )
return - V_8 ;
F_3 () ;
F_4 ( & V_9 ) ;
V_10 [ V_1 ] [ V_2 ] ++ ;
if ( V_10 [ V_1 ] [ V_2 ] == 1 ) {
V_3 = F_5 ( V_11 + V_12 + V_2 * 4 ) ;
if ( V_3 & ( 1 << 8 ) ) {
V_3 &= ~ ( 1 << 8 ) ;
V_3 |= V_5 ;
}
V_3 &= ~ ( V_4 | ( V_4 << 4 ) ) ;
F_6 ( V_3 , V_11 + V_12 + V_2 * 4 ) ;
} else if ( V_10 [ V_1 ] [ V_2 ] != 2 ) {
F_7 () ;
}
F_8 ( & V_9 ) ;
F_9 () ;
return 0 ;
}
static void F_10 ( void )
{
unsigned int V_13 , V_1 , V_2 , V_3 , V_4 , V_5 ;
bool V_14 = false , V_15 = false ;
V_13 = F_11 () ;
V_1 = F_12 ( V_13 , 0 ) ;
V_2 = F_12 ( V_13 , 1 ) ;
V_4 = ( 1 << V_1 ) ;
V_5 = V_6 [ V_2 ] ;
F_2 ( L_1 , V_7 , V_1 , V_2 ) ;
F_13 ( V_1 >= 4 || V_2 >= 2 ) ;
F_14 ( V_1 , V_2 ) ;
F_4 ( & V_9 ) ;
F_13 ( F_15 ( V_2 ) != V_16 ) ;
V_10 [ V_1 ] [ V_2 ] -- ;
if ( V_10 [ V_1 ] [ V_2 ] == 0 ) {
V_3 = F_5 ( V_11 + V_12 + V_2 * 4 ) ;
V_3 |= V_4 ;
if ( ( ( V_3 | ( V_3 >> 4 ) ) & V_5 ) == V_5 ) {
V_3 |= ( 1 << 8 ) ;
V_14 = true ;
}
F_6 ( V_3 , V_11 + V_12 + V_2 * 4 ) ;
} else if ( V_10 [ V_1 ] [ V_2 ] == 1 ) {
V_15 = true ;
} else
F_7 () ;
if ( V_14 && F_16 ( V_1 , V_2 ) ) {
F_8 ( & V_9 ) ;
asm volatile(
"str fp, [sp, #-4]! \n\t"
"mrc p15, 0, r0, c1, c0, 0 @ get CR \n\t"
"bic r0, r0, #"__stringify(CR_C)" \n\t"
"mcr p15, 0, r0, c1, c0, 0 @ set CR \n\t"
"isb \n\t"
"bl v7_flush_dcache_all \n\t"
"clrex \n\t"
"mrc p15, 0, r0, c1, c0, 1 @ get AUXCR \n\t"
"bic r0, r0, #(1 << 6) @ disable local coherency \n\t"
"mcr p15, 0, r0, c1, c0, 1 @ set AUXCR \n\t"
"isb \n\t"
"dsb \n\t"
"ldr fp, [sp], #4"
: : : "r0","r1","r2","r3","r4","r5","r6","r7",
"r9","r10","lr","memory");
F_17 () ;
F_18 ( V_13 ) ;
F_19 ( V_2 , V_17 ) ;
} else {
F_8 ( & V_9 ) ;
asm volatile(
"str fp, [sp, #-4]! \n\t"
"mrc p15, 0, r0, c1, c0, 0 @ get CR \n\t"
"bic r0, r0, #"__stringify(CR_C)" \n\t"
"mcr p15, 0, r0, c1, c0, 0 @ set CR \n\t"
"isb \n\t"
"bl v7_flush_dcache_louis \n\t"
"clrex \n\t"
"mrc p15, 0, r0, c1, c0, 1 @ get AUXCR \n\t"
"bic r0, r0, #(1 << 6) @ disable local coherency \n\t"
"mcr p15, 0, r0, c1, c0, 1 @ set AUXCR \n\t"
"isb \n\t"
"dsb \n\t"
"ldr fp, [sp], #4"
: : : "r0","r1","r2","r3","r4","r5","r6","r7",
"r9","r10","lr","memory");
}
F_20 ( V_1 , V_2 ) ;
F_21 () ;
if ( ! V_15 )
F_22 () ;
}
static void T_1 F_23 ( void )
{
unsigned int V_13 , V_1 , V_2 ;
V_13 = F_11 () ;
V_1 = F_12 ( V_13 , 0 ) ;
V_2 = F_12 ( V_13 , 1 ) ;
F_2 ( L_1 , V_7 , V_1 , V_2 ) ;
F_13 ( V_1 >= 4 || V_2 >= 2 ) ;
V_10 [ V_1 ] [ V_2 ] = 1 ;
}
static int T_1 F_24 ( void )
{
struct V_18 * V_19 ;
unsigned int V_20 ;
int V_21 ;
if ( ! F_25 () )
return - V_22 ;
V_19 = F_26 ( NULL , NULL , L_2 ) ;
if ( ! V_19 )
return - V_22 ;
V_11 = F_27 ( V_19 , 0 ) ;
if ( ! V_11 )
return - V_23 ;
V_20 = F_5 ( V_11 + V_24 ) ;
V_6 [ 0 ] = ( 1 << ( ( ( V_20 >> 16 ) >> ( 0 << 2 ) ) & 0xf ) ) - 1 ;
V_6 [ 1 ] = ( 1 << ( ( ( V_20 >> 16 ) >> ( 1 << 2 ) ) & 0xf ) ) - 1 ;
F_23 () ;
V_21 = F_28 ( & V_25 ) ;
if ( ! V_21 )
V_21 = F_29 ( V_26 ) ;
if ( V_21 ) {
F_30 ( V_11 ) ;
return V_21 ;
}
F_31 ( L_3 ) ;
F_32 ( F_33 ( V_27 ) ) ;
return 0 ;
}
