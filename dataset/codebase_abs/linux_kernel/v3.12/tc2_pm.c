static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
if ( V_2 >= V_4 || V_1 >= V_5 [ V_2 ] )
return - V_6 ;
F_3 () ;
F_4 ( & V_7 ) ;
if ( F_5 ( V_2 ) )
F_6 ( V_2 , false ) ;
V_8 [ V_1 ] [ V_2 ] ++ ;
if ( V_8 [ V_1 ] [ V_2 ] == 1 ) {
F_7 ( V_2 , V_1 ,
F_8 ( V_9 ) ) ;
F_9 ( V_2 , V_1 , true ) ;
} else if ( V_8 [ V_1 ] [ V_2 ] != 2 ) {
F_10 () ;
}
F_11 ( & V_7 ) ;
F_12 () ;
return 0 ;
}
static void F_13 ( T_1 V_10 )
{
unsigned int V_11 , V_1 , V_2 ;
bool V_12 = false , V_13 = false ;
V_11 = F_14 () ;
V_1 = F_15 ( V_11 , 0 ) ;
V_2 = F_15 ( V_11 , 1 ) ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
F_16 ( V_2 >= V_4 || V_1 >= V_14 ) ;
F_17 ( V_1 , V_2 ) ;
F_4 ( & V_7 ) ;
F_16 ( F_18 ( V_2 ) != V_15 ) ;
V_8 [ V_1 ] [ V_2 ] -- ;
if ( V_8 [ V_1 ] [ V_2 ] == 0 ) {
F_9 ( V_2 , V_1 , true ) ;
if ( F_5 ( V_2 ) ) {
F_6 ( V_2 , true ) ;
F_19 ( true ) ;
V_12 = true ;
}
} else if ( V_8 [ V_1 ] [ V_2 ] == 1 ) {
V_13 = true ;
} else
F_10 () ;
if ( ! V_13 )
F_20 () ;
if ( V_12 && F_21 ( V_1 , V_2 ) ) {
F_11 ( & V_7 ) ;
if ( F_22 () == V_16 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
}
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
F_23 ( V_11 ) ;
F_24 ( V_2 , V_17 ) ;
} else {
if ( V_12 ) {
F_6 ( V_2 , false ) ;
F_19 ( false ) ;
}
F_11 ( & V_7 ) ;
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
F_25 ( V_1 , V_2 ) ;
if ( ! V_13 )
F_26 () ;
}
static void F_27 ( void )
{
F_13 ( 0 ) ;
}
static void F_28 ( T_1 V_10 )
{
unsigned int V_11 , V_1 , V_2 ;
V_11 = F_14 () ;
V_1 = F_15 ( V_11 , 0 ) ;
V_2 = F_15 ( V_11 , 1 ) ;
F_7 ( V_2 , V_1 , F_8 ( V_9 ) ) ;
F_13 ( V_10 ) ;
}
static void F_29 ( void )
{
unsigned int V_11 , V_1 , V_2 ;
unsigned long V_18 ;
V_11 = F_14 () ;
V_1 = F_15 ( V_11 , 0 ) ;
V_2 = F_15 ( V_11 , 1 ) ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
F_16 ( V_2 >= V_4 || V_1 >= V_14 ) ;
F_30 ( V_18 ) ;
F_4 ( & V_7 ) ;
if ( F_5 ( V_2 ) ) {
F_6 ( V_2 , false ) ;
F_19 ( false ) ;
}
if ( ! V_8 [ V_1 ] [ V_2 ] )
V_8 [ V_1 ] [ V_2 ] = 1 ;
F_9 ( V_2 , V_1 , false ) ;
F_7 ( V_2 , V_1 , 0 ) ;
F_11 ( & V_7 ) ;
F_31 ( V_18 ) ;
}
static bool T_2 F_32 ( void )
{
unsigned int V_11 , V_1 , V_2 ;
V_11 = F_14 () ;
V_1 = F_15 ( V_11 , 0 ) ;
V_2 = F_15 ( V_11 , 1 ) ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
if ( V_2 >= V_4 || V_1 >= V_5 [ V_2 ] ) {
F_33 ( L_2 , V_3 ) ;
return false ;
}
V_8 [ V_1 ] [ V_2 ] = 1 ;
return true ;
}
static void T_3 F_34 ( unsigned int V_19 )
{
asm volatile (" \n"
" cmp r0, #1 \n"
" bxne lr \n"
" b cci_enable_port_for_self ");
}
static int T_2 F_35 ( void )
{
int V_20 ;
void T_4 * V_21 ;
T_5 V_22 , V_23 , V_24 ;
struct V_25 * V_26 ;
V_26 = F_36 ( NULL , NULL ,
L_3 ) ;
V_21 = F_37 ( V_26 , 0 ) ;
if ( ! V_21 )
return - V_27 ;
V_22 = F_38 ( V_21 + V_28 ) & 0xf ;
V_23 = F_38 ( V_21 + V_29 ) & 0xf ;
if ( V_22 >= V_4 || V_23 >= V_4 )
return - V_6 ;
V_24 = F_38 ( V_21 + V_30 ) ;
V_5 [ V_22 ] = ( V_24 >> 16 ) & 0xf ;
V_5 [ V_23 ] = ( V_24 >> 20 ) & 0xf ;
V_20 = F_39 ( V_21 + V_31 , V_22 ) ;
if ( V_20 )
return V_20 ;
if ( ! F_40 () )
return - V_27 ;
if ( ! F_32 () )
return - V_6 ;
V_20 = F_41 ( & V_32 ) ;
if ( ! V_20 ) {
F_42 ( F_34 ) ;
F_43 ( L_4 ) ;
}
return V_20 ;
}
