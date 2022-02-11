static void F_1 ( void )
{
F_2 () ;
F_3 ( ( unsigned long ) F_4 ( 0 ) ) ;
while ( 1 ) ;
}
void F_5 ( void )
{
unsigned long V_1 ;
struct V_2 V_3 ;
F_6 ( V_1 ) ;
F_7 () ;
V_3 = * F_8 ( & V_4 ) ;
memset ( F_8 ( & V_4 ) , 0 , sizeof( V_3 ) ) ;
F_9 ( V_5 ) ;
F_10 () ;
F_11 ( V_1 ) ;
if ( V_3 . V_6 )
F_12 () ;
if ( V_3 . V_7 ) {
static int V_8 = 0 ;
F_13 ( 14 , 24 ) ;
if ( F_14 ( & V_8 , 1 ) == 0 )
F_15 ( V_9 , 1 ) ;
}
if ( V_3 . V_10 )
F_16 () ;
if ( V_3 . V_11 ) {
F_17 () ;
F_18 ( V_12 L_1
L_2 , V_3 . V_13 ) ;
F_18 ( V_12 L_3 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
F_19 ( V_17 ) ;
}
}
static int T_1 F_20 ( union V_18 V_18 , int V_19 )
{
int V_11 ;
T_2 V_20 ;
void * V_21 ;
V_11 = 0 ;
V_20 = 0 ;
if ( ! V_18 . V_22 ) {
if ( ! V_19 )
F_1 () ;
V_11 = 1 ;
}
if ( ! V_18 . V_23 ) {
F_1 () ;
} else {
asm volatile(
" lctlg 0,15,0(%0)\n"
" ptlb\n"
: : "a" (&S390_lowcore.cregs_save_area) : "memory");
}
if ( ! V_18 . V_24 ) {
if ( V_25 . V_26 & V_27 )
F_1 () ;
if ( ! F_21 ( V_28 ) )
V_11 = 1 ;
}
V_21 = & V_25 . V_29 ;
if ( ! V_18 . V_30 ) {
if ( V_25 . V_26 & V_31 )
F_1 () ;
asm volatile("lfpc %0" : : "Q" (zero));
if ( ! F_21 ( V_28 ) )
V_11 = 1 ;
} else {
asm volatile("lfpc %0"
: : "Q" (S390_lowcore.fpt_creg_save_area));
}
if ( ! V_32 ) {
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
: : "a" (fpt_save_area) : "memory");
} else {
union V_33 V_34 ;
if ( ! V_18 . V_35 ) {
if ( V_25 . V_26 & V_36 )
F_1 () ;
if ( ! F_21 ( V_28 ) )
V_11 = 1 ;
}
V_34 . V_37 = V_25 . V_38 [ 0 ] ;
V_34 . V_39 = V_34 . V_40 = 1 ;
F_22 ( V_34 . V_37 , 0 , 0 ) ;
asm volatile(
" la 1,%0\n"
" .word 0xe70f,0x1000,0x0036\n"
" .word 0xe70f,0x1100,0x0c36\n"
: : "Q" (*(struct vx_array *)
&S390_lowcore.vector_save_area) : "1");
F_22 ( V_25 . V_38 [ 0 ] , 0 , 0 ) ;
}
asm volatile(
" lam 0,15,0(%0)"
: : "a" (&S390_lowcore.access_regs_save_area));
if ( ! V_18 . V_41 ) {
V_11 = 1 ;
}
if ( ! V_18 . V_42 )
asm volatile(
" sr 0,0\n"
" sckpf"
: : : "0", "cc");
else
asm volatile(
" l 0,%0\n"
" sckpf"
: : "Q" (S390_lowcore.tod_progreg_save_area)
: "0", "cc");
F_23 ( V_25 . V_43 ) ;
if ( ! V_18 . V_44 )
F_1 () ;
if ( ! V_18 . V_45 || ! V_18 . V_46 || ! V_18 . V_47 )
V_11 = 1 ;
return V_11 ;
}
void T_1 F_24 ( struct V_48 * V_49 )
{
static int V_50 ;
static F_25 ( V_51 ) ;
static unsigned long long V_52 ;
struct V_2 * V_3 ;
unsigned long long V_53 ;
union V_18 V_18 ;
F_26 () ;
F_27 ( V_54 ) ;
V_18 . V_37 = V_25 . V_55 ;
V_3 = F_8 ( & V_4 ) ;
if ( V_18 . V_56 ) {
F_1 () ;
}
if ( V_18 . V_57 ) {
if ( V_18 . V_58 ) {
T_2 V_59 , V_60 , V_61 ;
V_59 = ( 1ULL << 63 | 1ULL << 59 | 1ULL << 29 ) ;
V_60 = ( 1ULL << 43 | 1ULL << 42 | 1ULL << 41 | 1ULL << 40 |
1ULL << 36 | 1ULL << 35 | 1ULL << 34 | 1ULL << 32 |
1ULL << 30 | 1ULL << 21 | 1ULL << 20 | 1ULL << 17 |
1ULL << 16 ) ;
V_61 = V_18 . V_37 ;
if ( ( ( V_61 & V_59 ) != 0 ) ||
( ( V_61 & V_60 ) != V_60 ) ) {
F_1 () ;
}
F_28 ( & V_51 ) ;
V_53 = F_29 () ;
if ( ( ( V_53 - V_52 ) >> 12 ) < V_62 )
V_50 ++ ;
else
V_50 = 1 ;
V_52 = V_53 ;
if ( V_50 == V_63 )
F_1 () ;
F_30 ( & V_51 ) ;
} else {
F_1 () ;
}
}
if ( F_20 ( V_18 , F_31 ( V_49 ) ) ) {
V_3 -> V_11 = 1 ;
V_3 -> V_13 = V_18 . V_37 ;
F_32 ( V_5 ) ;
}
if ( V_18 . V_64 ) {
F_1 () ;
}
if ( V_18 . V_65 && V_18 . V_66 ) {
if ( V_25 . V_67 & ( 1U << V_68 ) )
V_3 -> V_10 |= F_33 () ;
if ( V_25 . V_67 & ( 1U << V_69 ) )
V_3 -> V_10 |= F_34 () ;
if ( V_3 -> V_10 )
F_32 ( V_5 ) ;
}
if ( V_18 . V_70 )
F_1 () ;
if ( V_18 . V_71 )
F_1 () ;
if ( V_18 . V_72 && V_18 . V_73 )
F_1 () ;
if ( V_18 . V_74 ) {
V_3 -> V_6 = 1 ;
F_32 ( V_5 ) ;
}
if ( V_18 . V_75 ) {
V_3 -> V_7 = 1 ;
F_32 ( V_5 ) ;
}
F_35 () ;
}
static int T_3 F_36 ( void )
{
F_37 ( 14 , 25 ) ;
F_37 ( 14 , 27 ) ;
F_37 ( 14 , 24 ) ;
return 0 ;
}
