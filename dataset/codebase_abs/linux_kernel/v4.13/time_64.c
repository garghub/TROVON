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
static unsigned long F_10 ( T_1 V_13 , int V_14 )
{
bool V_15 = false ;
unsigned long V_16 = 0 ;
char type [ 128 ] ;
if ( ! V_13 )
return V_16 ;
if ( F_11 ( V_13 , L_1 , type , sizeof( type ) ) != - 1 )
V_15 = ( strcmp ( type , L_2 ) == 0 ) ;
if ( V_15 && ( F_12 ( V_13 , L_3 ) == V_14 ||
F_12 ( V_13 , L_4 ) == V_14 ) )
V_16 = F_13 ( V_13 , L_5 , 0 ) ;
if ( ! V_16 )
V_16 = F_10 ( F_14 ( V_13 ) , V_14 ) ;
if ( ! V_16 )
V_16 = F_10 ( F_15 ( V_13 ) , V_14 ) ;
return V_16 ;
}
static unsigned long F_16 ( void )
{
return F_10 ( V_17 , F_17 () ) ;
}
static void F_18 ( void )
{
__asm__ __volatile__(
"wr %0, 0x0, %%asr25"
:
: "r" (TICKCMP_IRQ_BIT));
}
static void F_19 ( void )
{
if ( V_18 != V_19 ) {
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
F_18 () ;
}
static unsigned long long F_20 ( void )
{
unsigned long V_6 ;
__asm__ __volatile__("rd %%asr24, %0"
: "=r" (ret));
return V_6 & ~ V_7 ;
}
static unsigned long F_21 ( unsigned long V_8 )
{
unsigned long V_10 ;
__asm__ __volatile__("rd %%asr24, %0\n\t"
"add %0, %1, %0\n\t"
"wr %0, 0, %%asr24\n\t"
: "=&r" (new_tick)
: "r" (adj));
return V_10 ;
}
static int F_22 ( unsigned long V_8 )
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
static unsigned long F_23 ( void )
{
return F_13 ( V_17 , L_6 , 0 ) ;
}
static unsigned long F_24 ( void )
{
unsigned long V_6 , V_20 , V_21 , V_22 ;
unsigned long V_23 = V_24 + 8 ;
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
static void F_25 ( unsigned long V_25 )
{
unsigned long V_26 = ( V_25 & 0xffffffffUL ) ;
unsigned long V_27 = ( V_25 >> 32UL ) ;
unsigned long V_23 = V_24 ;
__asm__ __volatile__("stxa %%g0, [%0] %4\n\t"
"add %0, 0x8, %0\n\t"
"stxa %3, [%0] %4\n\t"
"sub %0, 0x8, %0\n\t"
"stxa %2, [%0] %4"
: "=&r" (addr)
: "0" (addr), "r" (low), "r" (high),
"i" (ASI_PHYS_BYPASS_EC_E));
}
static void F_26 ( unsigned long V_25 )
{
unsigned long V_26 = ( V_25 & 0xffffffffUL ) ;
unsigned long V_27 = ( V_25 >> 32UL ) ;
unsigned long V_23 = V_28 + 0x8UL ;
__asm__ __volatile__("stxa %3, [%0] %4\n\t"
"sub %0, 0x8, %0\n\t"
"stxa %2, [%0] %4"
: "=&r" (addr)
: "0" (addr), "r" (low), "r" (high),
"i" (ASI_PHYS_BYPASS_EC_E));
}
static void F_27 ( void )
{
F_26 ( V_12 ) ;
}
static void F_28 ( void )
{
F_4 () ;
F_25 ( F_24 () ) ;
F_27 () ;
}
static unsigned long long F_29 ( void )
{
return F_24 () & ~ V_7 ;
}
static unsigned long F_30 ( unsigned long V_8 )
{
unsigned long V_25 ;
V_25 = F_24 () + V_8 ;
F_25 ( V_25 ) ;
return V_25 ;
}
static int F_31 ( unsigned long V_8 )
{
unsigned long V_25 = F_24 () ;
unsigned long V_29 ;
V_25 &= ~ V_12 ;
V_25 += V_8 ;
F_26 ( V_25 ) ;
V_29 = F_24 () & ~ V_12 ;
return ( ( long ) ( V_29 - V_25 ) ) > 0L ;
}
static unsigned long F_32 ( void )
{
return F_13 ( V_17 , L_6 , 0 ) ;
}
static int F_33 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
F_34 ( V_34 L_7 ,
V_31 -> V_35 . V_36 -> V_37 , V_31 -> V_32 [ 0 ] . V_38 ) ;
V_33 = & V_39 ;
V_33 -> V_40 = V_41 ;
V_33 -> V_42 = V_31 -> V_32 [ 0 ] . V_42 ;
V_33 -> V_38 = V_31 -> V_32 [ 0 ] . V_38 ;
V_33 -> V_43 = V_31 -> V_32 [ 0 ] . V_43 ;
V_44 = V_31 -> V_32 [ 0 ] . V_38 ;
return F_35 ( & V_45 ) ;
}
static int F_36 ( struct V_30 * V_31 )
{
F_34 ( V_34 L_8 ,
V_31 -> V_35 . V_36 -> V_37 , V_31 -> V_32 [ 0 ] . V_38 ) ;
V_46 . V_32 = & V_31 -> V_32 [ 0 ] ;
return F_35 ( & V_46 ) ;
}
static unsigned char F_37 ( struct V_47 * V_35 , T_2 V_48 )
{
struct V_30 * V_49 = F_38 ( V_35 ) ;
void T_3 * V_2 = ( void T_3 * ) V_49 -> V_32 [ 0 ] . V_38 ;
return F_39 ( V_2 + V_48 ) ;
}
static void F_40 ( struct V_47 * V_35 , T_2 V_48 , T_4 V_25 )
{
struct V_30 * V_49 = F_38 ( V_35 ) ;
void T_3 * V_2 = ( void T_3 * ) V_49 -> V_32 [ 0 ] . V_38 ;
F_41 ( V_25 , V_2 + V_48 ) ;
}
static int F_42 ( struct V_30 * V_31 )
{
struct V_50 * V_51 = V_31 -> V_35 . V_36 ;
if ( ! strcmp ( V_51 -> V_52 -> V_42 , L_9 ) &&
strcmp ( V_51 -> V_52 -> V_52 -> V_42 , L_10 ) != 0 )
return - V_53 ;
F_34 ( V_34 L_11 ,
V_51 -> V_37 , V_31 -> V_32 [ 0 ] . V_38 ) ;
V_54 . V_32 = & V_31 -> V_32 [ 0 ] ;
return F_35 ( & V_54 ) ;
}
static int T_5 F_43 ( void )
{
if ( V_55 )
return F_35 ( & V_56 ) ;
if ( V_18 == V_19 )
return F_35 ( & V_57 ) ;
( void ) F_44 ( & V_58 ) ;
( void ) F_44 ( & V_59 ) ;
( void ) F_44 ( & V_60 ) ;
return 0 ;
}
static bool F_45 ( void )
{
unsigned long V_61 , V_62 , V_63 ;
__asm__ __volatile__ ("rdpr %%ver, %0"
: "=&r" (ver));
V_62 = ( ( V_61 >> 48 ) & 0xffff ) ;
V_63 = ( ( V_61 >> 32 ) & 0xffff ) ;
return ( V_62 == 0x17 && V_63 == 0x13 ) ;
}
unsigned long F_46 ( unsigned int V_64 )
{
struct V_65 * V_66 = & F_47 ( V_67 , V_64 ) ;
if ( V_66 -> V_68 )
return V_66 -> V_68 ;
return F_48 ( V_64 ) . V_69 ;
}
static int F_49 ( struct V_70 * V_71 , unsigned long V_25 ,
void * V_72 )
{
struct V_73 * V_16 = V_72 ;
unsigned int V_64 = V_16 -> V_64 ;
struct V_65 * V_66 = & F_47 ( V_67 , V_64 ) ;
if ( ! V_66 -> V_74 ) {
V_66 -> V_74 = V_16 -> V_75 ;
V_66 -> V_68 = F_48 ( V_64 ) . V_69 ;
}
if ( ( V_25 == V_76 && V_16 -> V_75 < V_16 -> V_77 ) ||
( V_25 == V_78 && V_16 -> V_75 > V_16 -> V_77 ) ) {
F_48 ( V_64 ) . V_69 =
F_50 ( V_66 -> V_68 ,
V_66 -> V_74 ,
V_16 -> V_77 ) ;
}
return 0 ;
}
static int T_5 F_51 ( void )
{
F_52 ( & V_79 ,
V_80 ) ;
return 0 ;
}
static int F_53 ( unsigned long V_81 ,
struct V_82 * V_83 )
{
return V_84 . V_85 ( V_81 ) ? - V_86 : 0 ;
}
static int F_54 ( struct V_82 * V_83 )
{
V_84 . V_87 () ;
return 0 ;
}
void T_6 F_55 ( int V_88 , struct V_1 * V_2 )
{
struct V_1 * V_89 = F_56 ( V_2 ) ;
unsigned long V_90 = V_84 . V_91 ;
int V_64 = F_57 () ;
struct V_82 * V_83 = & F_47 ( V_92 , V_64 ) ;
F_58 ( V_90 ) ;
F_59 () ;
F_60 () . V_93 ++ ;
F_61 ( 0 ) ;
if ( F_62 ( ! V_83 -> V_94 ) ) {
F_34 ( V_95
L_12 , V_64 ) ;
} else
V_83 -> V_94 ( V_83 ) ;
F_63 () ;
F_56 ( V_89 ) ;
}
void F_64 ( void )
{
struct V_82 * V_96 ;
unsigned long V_97 ;
__asm__ __volatile__("rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
V_84 . V_98 () ;
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
:
: "r" (pstate));
V_96 = F_65 ( & V_92 ) ;
memcpy ( V_96 , & V_99 , sizeof( * V_96 ) ) ;
V_96 -> V_100 = F_66 ( F_57 () ) ;
F_67 ( V_96 ) ;
}
void F_68 ( unsigned long V_101 )
{
unsigned long V_102 = F_69 () ;
while ( ( F_69 () - V_102 ) < V_101 )
;
}
void F_70 ( unsigned long V_103 )
{
F_68 ( V_104 * V_103 ) ;
}
static T_7 F_71 ( struct V_105 * V_106 )
{
return F_69 () ;
}
static void T_5 F_72 ( void )
{
unsigned int * V_23 , * V_107 , V_108 ;
struct F_72 * V_109 ;
if ( V_18 == V_110 && F_45 () )
return;
for ( V_109 = & V_111 ; V_109 < & V_112 ; V_109 ++ ) {
V_107 = ( V_18 == V_110 ) ? V_109 -> V_113 : V_109 -> V_114 ;
V_23 = ( unsigned int * ) ( unsigned long ) V_109 -> V_23 ;
for ( V_108 = 0 ; V_108 < V_115 ; V_108 ++ ) {
V_23 [ V_108 ] = V_107 [ V_108 ] ;
F_73 () ;
F_74 ( & V_23 [ V_108 ] ) ;
}
}
}
static void F_75 ( struct V_116 * V_117 )
{
unsigned long V_16 , V_118 , V_113 ;
V_16 = V_117 -> V_119 () ;
V_118 = F_76 ( V_16 , V_120 ) ;
V_113 = V_117 -> F_69 () ;
V_117 -> V_121 = ( V_113 * V_118 ) >> V_120 ;
V_117 -> V_122 = V_118 ;
V_117 -> V_123 = V_16 ;
V_84 = * V_117 ;
F_72 () ;
}
void T_5 F_77 ( void )
{
if ( V_18 == V_110 ) {
if ( F_45 () )
F_75 ( & V_124 ) ;
else
F_75 ( & V_84 ) ;
} else {
F_75 ( & V_125 ) ;
}
}
void T_5 F_78 ( void )
{
unsigned long V_16 ;
V_16 = V_84 . V_123 ;
V_104 = V_16 / V_126 ;
V_127 . V_42 = V_84 . V_42 ;
V_127 . V_128 = F_71 ;
F_79 ( & V_127 , V_16 ) ;
F_34 ( L_13 ,
V_127 . V_129 , V_127 . V_130 ) ;
V_99 . V_42 = V_84 . V_42 ;
F_80 ( & V_99 , V_16 , 4 ) ;
V_99 . V_131 =
F_81 ( 0x7fffffffffffffffUL , & V_99 ) ;
V_99 . V_132 = 0x7fffffffffffffffUL ;
V_99 . V_133 =
F_81 ( 0xF , & V_99 ) ;
V_99 . V_134 = 0xF ;
F_34 ( L_14 ,
V_99 . V_129 , V_99 . V_130 ) ;
F_64 () ;
}
unsigned long long F_82 ( void )
{
unsigned long V_118 = V_84 . V_122 ;
unsigned long V_121 = V_84 . V_121 ;
F_83 () ;
return ( ( F_69 () * V_118 ) >> V_120 ) - V_121 ;
}
int F_84 ( unsigned long * V_135 )
{
* V_135 = F_69 () ;
return 0 ;
}
