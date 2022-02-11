static void F_1 ( char * V_1 )
{
F_2 () ;
F_3 ( ( unsigned long ) F_4 ( 0 ) ) ;
while ( 1 ) ;
}
void F_5 ( void )
{
unsigned long V_2 ;
struct V_3 V_4 ;
F_6 ( V_2 ) ;
F_7 () ;
V_4 = F_8 ( V_5 ) ;
memset ( & F_8 ( V_5 ) , 0 , sizeof( struct V_3 ) ) ;
F_9 ( V_6 ) ;
F_10 () ;
F_11 ( V_2 ) ;
if ( V_4 . V_7 )
F_12 () ;
if ( V_4 . V_8 ) {
static int V_9 = 0 ;
F_13 ( 14 , 24 ) ;
if ( F_14 ( & V_9 , 1 ) == 0 )
F_15 ( V_10 , 1 ) ;
}
if ( V_4 . V_11 ) {
F_16 () ;
F_17 ( V_12 L_1
L_2 , V_4 . V_13 ) ;
F_17 ( V_12 L_3 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
F_18 ( V_17 ) ;
}
}
static int T_1 F_19 ( struct V_18 * V_18 )
{
int V_11 ;
T_2 V_19 ;
void * V_20 , * V_21 ;
V_11 = 0 ;
V_19 = 0 ;
if ( ! V_18 -> V_22 ) {
V_11 = 1 ;
}
if ( ! V_18 -> V_23 ) {
V_11 = 1 ;
}
#ifndef F_20
asm volatile(
" ld 0,0(%0)\n"
" ld 2,8(%0)\n"
" ld 4,16(%0)\n"
" ld 6,24(%0)"
: : "a" (&S390_lowcore.floating_pt_save_area));
#endif
if ( V_24 ) {
#ifdef F_20
V_20 = & V_25 . V_26 ;
V_21 = & V_25 . V_21 ;
#else
V_20 = ( void * ) V_25 . V_27 ;
V_21 = V_20 + 128 ;
#endif
if ( ! V_18 -> V_28 ) {
asm volatile("lfpc 0(%0)" : : "a" (&zero), "m" (zero));
V_11 = 1 ;
} else
asm volatile("lfpc 0(%0)" : : "a" (fpt_creg_save_area));
asm volatile(
" ld 0,0(%0)\n"
" ld 1,8(%0)\n"
" ld 2,16(%0)\n"
" ld 3,24(%0)\n"
" ld 4,32(%0)\n"
" ld 5,40(%0)\n"
" ld 6,48(%0)\n"
" ld 7,56(%0)\n"
" ld 8,64(%0)\n"
" ld 9,72(%0)\n"
" ld 10,80(%0)\n"
" ld 11,88(%0)\n"
" ld 12,96(%0)\n"
" ld 13,104(%0)\n"
" ld 14,112(%0)\n"
" ld 15,120(%0)\n"
: : "a" (fpt_save_area));
}
asm volatile(
" lam 0,15,0(%0)"
: : "a" (&S390_lowcore.access_regs_save_area));
if ( ! V_18 -> V_29 ) {
V_11 = 1 ;
}
if ( ! V_18 -> V_30 ) {
F_1 ( L_4 ) ;
} else {
#ifdef F_20
asm volatile(
" lctlg 0,15,0(%0)"
: : "a" (&S390_lowcore.cregs_save_area));
#else
asm volatile(
" lctl 0,15,0(%0)"
: : "a" (&S390_lowcore.cregs_save_area));
#endif
}
#ifdef F_20
if ( ! V_18 -> V_31 )
asm volatile(
" sr 0,0\n"
" sckpf"
: : : "0", "cc");
else
asm volatile(
" l 0,0(%0)\n"
" sckpf"
: : "a" (&S390_lowcore.tod_progreg_save_area)
: "0", "cc");
#endif
if ( V_25 . V_32 == - 1 )
F_21 ( V_25 . V_33 ) ;
else
F_21 ( V_25 . V_32 ) ;
if ( ! V_18 -> V_34 )
F_1 ( L_5 ) ;
if ( ! V_18 -> V_35 || ! V_18 -> V_36 || ! V_18 -> V_37 )
V_11 = 1 ;
return V_11 ;
}
void T_1 F_22 ( struct V_38 * V_39 )
{
static int V_40 ;
static F_23 ( V_41 ) ;
static unsigned long long V_42 ;
struct V_3 * V_4 ;
unsigned long long V_43 ;
struct V_18 * V_18 ;
int V_44 ;
F_24 () ;
F_25 ( F_26 () ) . V_45 [ V_46 ] ++ ;
V_18 = (struct V_18 * ) & V_25 . V_47 ;
V_4 = & F_8 ( V_5 ) ;
V_44 = F_27 ( V_39 ) ;
if ( V_18 -> V_48 ) {
F_1 ( L_6 ) ;
}
if ( V_18 -> V_49 ) {
if ( V_18 -> V_50 ) {
T_2 V_51 , V_52 , V_53 ;
#ifdef F_20
V_51 = ( 1ULL << 63 | 1ULL << 59 | 1ULL << 29 ) ;
V_52 = ( 1ULL << 43 | 1ULL << 42 | 1ULL << 41 | 1ULL << 40 |
1ULL << 36 | 1ULL << 35 | 1ULL << 34 | 1ULL << 32 |
1ULL << 30 | 1ULL << 21 | 1ULL << 20 | 1ULL << 17 |
1ULL << 16 ) ;
#else
V_51 = ( 1ULL << 63 | 1ULL << 59 | 1ULL << 57 | 1ULL << 50 |
1ULL << 29 ) ;
V_52 = ( 1ULL << 43 | 1ULL << 42 | 1ULL << 41 | 1ULL << 40 |
1ULL << 36 | 1ULL << 35 | 1ULL << 34 | 1ULL << 32 |
1ULL << 30 | 1ULL << 20 | 1ULL << 17 | 1ULL << 16 ) ;
#endif
V_53 = * ( T_2 * ) V_18 ;
if ( ( ( V_53 & V_51 ) != 0 ) ||
( ( V_53 & V_52 ) != V_52 ) ) {
F_1 ( L_7
L_8 ) ;
}
F_28 ( & V_41 ) ;
V_43 = F_29 () ;
if ( ( ( V_43 - V_42 ) >> 12 ) < V_54 )
V_40 ++ ;
else
V_40 = 1 ;
V_42 = V_43 ;
if ( V_40 == V_55 )
F_1 ( L_9 ) ;
F_30 ( & V_41 ) ;
} else {
F_1 ( L_10
L_11 ) ;
}
}
if ( F_19 ( V_18 ) ) {
if ( V_44 ) {
V_4 -> V_11 = 1 ;
V_4 -> V_13 = * ( unsigned long long * ) V_18 ;
F_31 ( V_6 ) ;
} else {
F_1 ( L_12 ) ;
}
}
if ( V_18 -> V_56 ) {
F_1 ( L_13 ) ;
}
if ( V_18 -> V_57 && V_18 -> V_58 ) {
if ( V_25 . V_59 & ( 1U << V_60 ) )
F_32 () ;
if ( V_25 . V_59 & ( 1U << V_61 ) )
F_33 () ;
if ( V_25 . V_59 & ( 1U << V_62 ) )
F_34 () ;
if ( V_25 . V_59 & ( 1U << V_63 ) )
F_35 () ;
}
if ( V_18 -> V_64 )
F_1 ( L_14
L_15 ) ;
if ( V_18 -> V_65 )
F_1 ( L_16
L_15 ) ;
if ( V_18 -> V_66 && V_18 -> V_67 )
F_1 ( L_17
L_18 ) ;
if ( V_18 -> V_68 ) {
V_4 -> V_7 = 1 ;
F_31 ( V_6 ) ;
}
if ( V_18 -> V_69 ) {
V_4 -> V_8 = 1 ;
F_31 ( V_6 ) ;
}
F_36 () ;
}
static int T_3 F_37 ( void )
{
F_38 ( 14 , 25 ) ;
F_38 ( 14 , 27 ) ;
F_38 ( 14 , 24 ) ;
return 0 ;
}
