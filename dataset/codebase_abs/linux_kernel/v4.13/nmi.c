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
struct V_22 * V_22 ;
V_11 = 0 ;
V_20 = 0 ;
if ( ! V_18 . V_23 ) {
if ( ! V_19 )
F_1 () ;
V_11 = 1 ;
}
if ( ! V_18 . V_24 ) {
F_1 () ;
} else {
asm volatile(
" lctlg 0,15,0(%0)\n"
" ptlb\n"
: : "a" (&S390_lowcore.cregs_save_area) : "memory");
}
if ( ! V_18 . V_25 ) {
if ( V_26 . V_27 & V_28 )
F_1 () ;
if ( ! F_21 ( V_29 ) )
V_11 = 1 ;
}
V_21 = & V_26 . V_30 ;
if ( ! V_18 . V_31 ) {
if ( V_26 . V_27 & V_32 )
F_1 () ;
asm volatile("lfpc %0" : : "Q" (zero));
if ( ! F_21 ( V_29 ) )
V_11 = 1 ;
} else {
asm volatile("lfpc %0"
: : "Q" (S390_lowcore.fpt_creg_save_area));
}
V_22 = (struct V_22 * ) ( V_26 . V_33 & V_34 ) ;
if ( ! V_35 ) {
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
union V_36 V_37 ;
if ( ! V_18 . V_38 ) {
if ( V_26 . V_27 & V_39 )
F_1 () ;
if ( ! F_21 ( V_29 ) )
V_11 = 1 ;
}
V_37 . V_40 = V_26 . V_41 [ 0 ] ;
V_37 . V_42 = V_37 . V_43 = 1 ;
F_22 ( V_37 . V_40 , 0 , 0 ) ;
asm volatile(
" la 1,%0\n"
" .word 0xe70f,0x1000,0x0036\n"
" .word 0xe70f,0x1100,0x0c36\n"
: : "Q" (*(struct vx_array *) mcesa->vector_save_area)
: "1");
F_22 ( V_26 . V_41 [ 0 ] , 0 , 0 ) ;
}
asm volatile(
" lam 0,15,0(%0)"
: : "a" (&S390_lowcore.access_regs_save_area));
if ( ! V_18 . V_44 ) {
V_11 = 1 ;
}
if ( V_45 && ( V_26 . V_41 [ 2 ] & ( 1UL << 4 ) ) ) {
if ( ! V_18 . V_46 )
V_11 = 1 ;
else
F_23 ( (struct V_47 * )
V_22 -> V_48 ) ;
}
if ( ! V_18 . V_49 )
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
F_24 ( V_26 . V_50 ) ;
if ( ! V_18 . V_51 )
F_1 () ;
if ( ! V_18 . V_52 || ! V_18 . V_53 || ! V_18 . V_54 )
V_11 = 1 ;
return V_11 ;
}
static void T_1 F_25 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_59 * V_59 ;
struct V_60 * V_61 =
(struct V_60 * ) V_56 -> V_62 [ 14 ] ;
if ( V_61 == NULL )
F_1 () ;
V_59 = F_26 ( V_61 , struct V_59 , V_61 ) ;
V_58 = & V_59 -> V_63 ;
V_58 -> V_64 = V_26 . V_65 &
~ ( V_66 | V_67 ) ;
V_58 -> V_68 = V_26 . V_69 ;
V_58 -> V_70
= V_26 . V_70 ;
}
void T_1 F_27 ( struct V_55 * V_56 )
{
static int V_71 ;
static F_28 ( V_72 ) ;
static unsigned long long V_73 ;
struct V_2 * V_3 ;
unsigned long long V_74 ;
union V_18 V_18 ;
unsigned long V_75 ;
F_29 () ;
F_30 ( V_76 ) ;
V_18 . V_40 = V_26 . V_65 ;
V_3 = F_8 ( & V_4 ) ;
if ( V_18 . V_77 ) {
F_1 () ;
}
if ( V_18 . V_78 && ! F_21 ( V_79 ) ) {
if ( V_18 . V_80 ) {
T_2 V_81 , V_82 , V_83 ;
V_81 = ( 1ULL << 63 | 1ULL << 59 | 1ULL << 29 ) ;
V_82 = ( 1ULL << 43 | 1ULL << 42 | 1ULL << 41 | 1ULL << 40 |
1ULL << 36 | 1ULL << 35 | 1ULL << 34 | 1ULL << 32 |
1ULL << 30 | 1ULL << 21 | 1ULL << 20 | 1ULL << 17 |
1ULL << 16 ) ;
V_83 = V_18 . V_40 ;
if ( ( ( V_83 & V_81 ) != 0 ) ||
( ( V_83 & V_82 ) != V_82 ) ) {
F_1 () ;
}
F_31 ( & V_72 ) ;
V_74 = F_32 () ;
if ( ( ( V_74 - V_73 ) >> 12 ) < V_84 )
V_71 ++ ;
else
V_71 = 1 ;
V_73 = V_74 ;
if ( V_71 == V_85 )
F_1 () ;
F_33 ( & V_72 ) ;
} else {
F_1 () ;
}
}
if ( F_20 ( V_18 , F_34 ( V_56 ) ) ) {
V_3 -> V_11 = 1 ;
V_3 -> V_13 = V_18 . V_40 ;
F_35 ( V_5 ) ;
}
if ( F_21 ( V_79 ) )
F_25 ( V_56 ) ;
if ( V_18 . V_86 ) {
F_1 () ;
}
if ( V_18 . V_87 && V_18 . V_88 ) {
if ( V_26 . V_69 & ( 1U << V_89 ) )
V_3 -> V_10 |= F_36 () ;
if ( V_26 . V_69 & ( 1U << V_90 ) )
V_3 -> V_10 |= F_37 () ;
if ( V_3 -> V_10 )
F_35 ( V_5 ) ;
}
if ( ! F_21 ( V_79 ) ) {
if ( V_18 . V_91 )
F_1 () ;
if ( V_18 . V_92 )
F_1 () ;
if ( V_18 . V_93 && V_18 . V_94 )
F_1 () ;
}
if ( V_18 . V_95 ) {
V_3 -> V_6 = 1 ;
F_35 ( V_5 ) ;
}
if ( V_18 . V_96 ) {
V_3 -> V_7 = 1 ;
F_35 ( V_5 ) ;
}
V_75 = ( V_18 . V_40 & V_97 ) ;
if ( F_21 ( V_79 ) &&
( V_75 & V_98 ) != V_75 ) {
* ( ( long * ) ( V_56 -> V_62 [ 15 ] + V_99 ) ) = - V_100 ;
}
F_9 ( V_79 ) ;
F_38 () ;
}
static int T_3 F_39 ( void )
{
F_40 ( 14 , 25 ) ;
F_40 ( 14 , 27 ) ;
F_40 ( 14 , 24 ) ;
return 0 ;
}
