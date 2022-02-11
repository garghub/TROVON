unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = F_2 ( V_2 ) ;
if ( F_3 ( V_3 ) )
return V_2 -> V_4 [ V_5 ] ;
return V_3 ;
}
static void F_4 ( void )
{
__asm__ __volatile__(
" ba,pt %%xcc, 1f\n"
" nop\n"
" .align 64\n"
"1: rd %%tick, %%g2\n"
" add %%g2, 6, %%g2\n"
" andn %%g2, %0, %%g2\n"
" wrpr %%g2, 0, %%tick\n"
" rdpr %%tick, %%g0"
:
: "r" (TICK_PRIV_BIT)
: "g2");
}
static void F_5 ( void )
{
__asm__ __volatile__(
" ba,pt %%xcc, 1f\n"
" nop\n"
" .align 64\n"
"1: wr %0, 0x0, %%tick_cmpr\n"
" rd %%tick_cmpr, %%g0"
:
: "r" (TICKCMP_IRQ_BIT));
}
static void F_6 ( void )
{
F_4 () ;
F_5 () ;
}
static unsigned long long F_7 ( void )
{
unsigned long V_6 ;
__asm__ __volatile__("rd %%tick, %0\n\t"
"mov %0, %0"
: "=r" (ret));
return V_6 & ~ V_7 ;
}
static int F_8 ( unsigned long V_8 )
{
unsigned long V_9 , V_10 , V_11 ;
__asm__ __volatile__("rd %%tick, %0"
: "=r" (orig_tick));
V_9 &= ~ V_12 ;
__asm__ __volatile__("ba,pt %%xcc, 1f\n\t"
" add %1, %2, %0\n\t"
".align 64\n"
"1:\n\t"
"wr %0, 0, %%tick_cmpr\n\t"
"rd %%tick_cmpr, %%g0\n\t"
: "=r" (new_compare)
: "r" (orig_tick), "r" (adj));
__asm__ __volatile__("rd %%tick, %0"
: "=r" (new_tick));
V_10 &= ~ V_12 ;
return ( ( long ) ( V_10 - ( V_9 + V_8 ) ) ) > 0L ;
}
static unsigned long F_9 ( unsigned long V_8 )
{
unsigned long V_10 ;
__asm__ __volatile__("rd %%tick, %0\n\t"
"add %0, %1, %0\n\t"
"wrpr %0, 0, %%tick\n\t"
: "=&r" (new_tick)
: "r" (adj));
return V_10 ;
}
static void F_10 ( void )
{
__asm__ __volatile__(
"wr %0, 0x0, %%asr25"
:
: "r" (TICKCMP_IRQ_BIT));
}
static void F_11 ( void )
{
if ( V_13 != V_14 ) {
F_4 () ;
F_5 () ;
__asm__ __volatile__(
" rd %%asr24, %%g2\n"
" andn %%g2, %0, %%g2\n"
" wr %%g2, 0, %%asr24"
:
: "r" (TICK_PRIV_BIT)
: "g1", "g2");
}
F_10 () ;
}
static unsigned long long F_12 ( void )
{
unsigned long V_6 ;
__asm__ __volatile__("rd %%asr24, %0"
: "=r" (ret));
return V_6 & ~ V_7 ;
}
static unsigned long F_13 ( unsigned long V_8 )
{
unsigned long V_10 ;
__asm__ __volatile__("rd %%asr24, %0\n\t"
"add %0, %1, %0\n\t"
"wr %0, 0, %%asr24\n\t"
: "=&r" (new_tick)
: "r" (adj));
return V_10 ;
}
static int F_14 ( unsigned long V_8 )
{
unsigned long V_9 , V_10 ;
__asm__ __volatile__("rd %%asr24, %0"
: "=r" (orig_tick));
V_9 &= ~ V_12 ;
__asm__ __volatile__("wr %0, 0, %%asr25"
:
: "r" (orig_tick + adj));
__asm__ __volatile__("rd %%asr24, %0"
: "=r" (new_tick));
V_10 &= ~ V_12 ;
return ( ( long ) ( V_10 - ( V_9 + V_8 ) ) ) > 0L ;
}
static unsigned long F_15 ( void )
{
unsigned long V_6 , V_15 , V_16 , V_17 ;
unsigned long V_18 = V_19 + 8 ;
__asm__ __volatile__("ldxa [%1] %5, %2\n"
"1:\n\t"
"sub %1, 0x8, %1\n\t"
"ldxa [%1] %5, %3\n\t"
"add %1, 0x8, %1\n\t"
"ldxa [%1] %5, %4\n\t"
"cmp %4, %2\n\t"
"bne,a,pn %%xcc, 1b\n\t"
" mov %4, %2\n\t"
"sllx %4, 32, %4\n\t"
"or %3, %4, %0\n\t"
: "=&r" (ret), "=&r" (addr),
"=&r" (tmp1), "=&r" (tmp2), "=&r" (tmp3)
: "i" (ASI_PHYS_BYPASS_EC_E), "1" (addr));
return V_6 ;
}
static void F_16 ( unsigned long V_20 )
{
unsigned long V_21 = ( V_20 & 0xffffffffUL ) ;
unsigned long V_22 = ( V_20 >> 32UL ) ;
unsigned long V_18 = V_19 ;
__asm__ __volatile__("stxa %%g0, [%0] %4\n\t"
"add %0, 0x8, %0\n\t"
"stxa %3, [%0] %4\n\t"
"sub %0, 0x8, %0\n\t"
"stxa %2, [%0] %4"
: "=&r" (addr)
: "0" (addr), "r" (low), "r" (high),
"i" (ASI_PHYS_BYPASS_EC_E));
}
static void F_17 ( unsigned long V_20 )
{
unsigned long V_21 = ( V_20 & 0xffffffffUL ) ;
unsigned long V_22 = ( V_20 >> 32UL ) ;
unsigned long V_18 = V_23 + 0x8UL ;
__asm__ __volatile__("stxa %3, [%0] %4\n\t"
"sub %0, 0x8, %0\n\t"
"stxa %2, [%0] %4"
: "=&r" (addr)
: "0" (addr), "r" (low), "r" (high),
"i" (ASI_PHYS_BYPASS_EC_E));
}
static void F_18 ( void )
{
F_17 ( V_12 ) ;
}
static void F_19 ( void )
{
F_4 () ;
F_16 ( F_15 () ) ;
F_18 () ;
}
static unsigned long long F_20 ( void )
{
return F_15 () & ~ V_7 ;
}
static unsigned long F_21 ( unsigned long V_8 )
{
unsigned long V_20 ;
V_20 = F_15 () + V_8 ;
F_16 ( V_20 ) ;
return V_20 ;
}
static int F_22 ( unsigned long V_8 )
{
unsigned long V_20 = F_15 () ;
unsigned long V_24 ;
V_20 &= ~ V_12 ;
V_20 += V_8 ;
F_17 ( V_20 ) ;
V_24 = F_15 () & ~ V_12 ;
return ( ( long ) ( V_24 - V_20 ) ) > 0L ;
}
int F_23 ( struct V_25 V_26 )
{
struct V_27 * V_28 = F_24 ( L_1 ) ;
int V_29 = - 1 ;
if ( V_28 ) {
V_29 = F_25 ( V_28 , V_26 . V_30 ) ;
F_26 ( V_28 ) ;
}
return V_29 ;
}
static int T_1 F_27 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
F_28 ( V_35 L_2 ,
V_32 -> V_36 . V_37 -> V_38 , V_32 -> V_33 [ 0 ] . V_39 ) ;
V_34 = & V_40 ;
V_34 -> V_41 = V_42 ;
V_34 -> V_43 = V_32 -> V_33 [ 0 ] . V_43 ;
V_34 -> V_39 = V_32 -> V_33 [ 0 ] . V_39 ;
V_34 -> V_44 = V_32 -> V_33 [ 0 ] . V_44 ;
V_45 = V_32 -> V_33 [ 0 ] . V_39 ;
return F_29 ( & V_46 ) ;
}
static int T_1 F_30 ( struct V_31 * V_32 )
{
F_28 ( V_35 L_3 ,
V_32 -> V_36 . V_37 -> V_38 , V_32 -> V_33 [ 0 ] . V_39 ) ;
V_47 . V_33 = & V_32 -> V_33 [ 0 ] ;
return F_29 ( & V_47 ) ;
}
static unsigned char F_31 ( struct V_48 * V_36 , T_2 V_49 )
{
struct V_31 * V_50 = F_32 ( V_36 ) ;
void T_3 * V_2 = ( void T_3 * ) V_50 -> V_33 [ 0 ] . V_39 ;
return F_33 ( V_2 + V_49 ) ;
}
static void F_34 ( struct V_48 * V_36 , T_2 V_49 , T_4 V_20 )
{
struct V_31 * V_50 = F_32 ( V_36 ) ;
void T_3 * V_2 = ( void T_3 * ) V_50 -> V_33 [ 0 ] . V_39 ;
F_35 ( V_20 , V_2 + V_49 ) ;
}
static int T_1 F_36 ( struct V_31 * V_32 )
{
struct V_51 * V_52 = V_32 -> V_36 . V_37 ;
if ( ! strcmp ( V_52 -> V_53 -> V_43 , L_4 ) &&
strcmp ( V_52 -> V_53 -> V_53 -> V_43 , L_5 ) != 0 )
return - V_54 ;
F_28 ( V_35 L_6 ,
V_52 -> V_38 , V_32 -> V_33 [ 0 ] . V_39 ) ;
V_55 . V_33 = & V_32 -> V_33 [ 0 ] ;
return F_29 ( & V_55 ) ;
}
static int T_5 F_37 ( void )
{
if ( V_56 )
return F_29 ( & V_57 ) ;
if ( V_13 == V_14 )
return F_29 ( & V_58 ) ;
( void ) F_38 ( & V_59 ) ;
( void ) F_38 ( & V_60 ) ;
( void ) F_38 ( & V_61 ) ;
return 0 ;
}
static unsigned long F_39 ( void )
{
struct V_51 * V_52 ;
unsigned long V_62 ;
V_52 = F_40 ( L_7 ) ;
if ( V_13 == V_63 ) {
unsigned long V_64 , V_65 , V_66 ;
__asm__ __volatile__ ("rdpr %%ver, %0"
: "=&r" (ver));
V_65 = ( ( V_64 >> 48 ) & 0xffff ) ;
V_66 = ( ( V_64 >> 32 ) & 0xffff ) ;
if ( V_65 == 0x17 && V_66 == 0x13 ) {
V_67 = & V_68 ;
V_62 = F_41 ( V_52 , L_8 , 0 ) ;
} else {
V_67 = & V_69 ;
V_62 = F_42 () . V_70 ;
}
} else {
V_67 = & V_71 ;
V_62 = F_41 ( V_52 , L_8 , 0 ) ;
}
return V_62 ;
}
unsigned long F_43 ( unsigned int V_72 )
{
struct V_73 * V_74 = & F_44 ( V_75 , V_72 ) ;
if ( V_74 -> V_76 )
return V_74 -> V_76 ;
return F_45 ( V_72 ) . V_70 ;
}
static int F_46 ( struct V_77 * V_78 , unsigned long V_20 ,
void * V_79 )
{
struct V_80 * V_62 = V_79 ;
unsigned int V_72 = V_62 -> V_72 ;
struct V_73 * V_74 = & F_44 ( V_75 , V_72 ) ;
if ( ! V_74 -> V_81 ) {
V_74 -> V_81 = V_62 -> V_82 ;
V_74 -> V_76 = F_45 ( V_72 ) . V_70 ;
}
if ( ( V_20 == V_83 && V_62 -> V_82 < V_62 -> V_84 ) ||
( V_20 == V_85 && V_62 -> V_82 > V_62 -> V_84 ) ||
( V_20 == V_86 ) ) {
F_45 ( V_72 ) . V_70 =
F_47 ( V_74 -> V_76 ,
V_74 -> V_81 ,
V_62 -> V_84 ) ;
}
return 0 ;
}
static int T_5 F_48 ( void )
{
F_49 ( & V_87 ,
V_88 ) ;
return 0 ;
}
static int F_50 ( unsigned long V_89 ,
struct V_90 * V_91 )
{
return V_67 -> V_92 ( V_89 ) ? - V_93 : 0 ;
}
static void F_51 ( enum V_94 V_95 ,
struct V_90 * V_91 )
{
switch ( V_95 ) {
case V_96 :
case V_97 :
break;
case V_98 :
V_67 -> V_99 () ;
break;
case V_100 :
case V_101 :
F_52 ( 1 ) ;
break;
}
}
void T_6 F_53 ( int V_102 , struct V_1 * V_2 )
{
struct V_1 * V_103 = F_54 ( V_2 ) ;
unsigned long V_104 = V_67 -> V_105 ;
int V_72 = F_55 () ;
struct V_90 * V_91 = & F_44 ( V_106 , V_72 ) ;
F_56 ( V_104 ) ;
F_57 () ;
F_42 () . V_107 ++ ;
F_58 ( 0 , F_59 ( 0 ) ) ;
if ( F_60 ( ! V_91 -> V_108 ) ) {
F_28 ( V_109
L_9 , V_72 ) ;
} else
V_91 -> V_108 ( V_91 ) ;
F_61 () ;
F_54 ( V_103 ) ;
}
void T_1 F_62 ( void )
{
struct V_90 * V_110 ;
unsigned long V_111 ;
__asm__ __volatile__("rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
V_67 -> V_112 () ;
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
:
: "r" (pstate));
V_110 = & F_63 ( V_106 ) ;
memcpy ( V_110 , & V_113 , sizeof( * V_110 ) ) ;
V_110 -> V_114 = F_64 ( F_55 () ) ;
F_65 ( V_110 ) ;
}
void F_66 ( unsigned long V_115 )
{
unsigned long V_116 , V_26 ;
V_116 = V_67 -> V_117 () ;
do {
V_26 = V_67 -> V_117 () ;
} while ( ( V_26 - V_116 ) < V_115 );
}
void F_67 ( unsigned long V_118 )
{
F_66 ( V_119 * V_118 ) ;
}
static T_7 F_68 ( struct V_120 * V_121 )
{
return V_67 -> V_117 () ;
}
void T_5 F_69 ( void )
{
unsigned long V_62 = F_39 () ;
V_119 = V_62 / V_122 ;
V_123 =
F_70 ( V_62 , V_124 ) ;
V_125 . V_43 = V_67 -> V_43 ;
V_125 . V_126 = F_68 ;
F_71 ( & V_125 , V_62 ) ;
F_28 ( L_10 ,
V_125 . V_127 , V_125 . V_128 ) ;
V_113 . V_43 = V_67 -> V_43 ;
F_72 ( & V_113 , V_62 , 4 ) ;
V_113 . V_129 =
F_73 ( 0x7fffffffffffffffUL , & V_113 ) ;
V_113 . V_130 =
F_73 ( 0xF , & V_113 ) ;
F_28 ( L_11 ,
V_113 . V_127 , V_113 . V_128 ) ;
F_62 () ;
}
unsigned long long F_74 ( void )
{
unsigned long V_131 = V_67 -> V_117 () ;
return ( V_131 * V_123 )
>> V_124 ;
}
int T_1 F_75 ( unsigned long * V_132 )
{
* V_132 = V_67 -> V_117 () ;
return 0 ;
}
