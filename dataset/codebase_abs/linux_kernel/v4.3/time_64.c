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
static int F_23 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
F_24 ( V_29 L_1 ,
V_26 -> V_30 . V_31 -> V_32 , V_26 -> V_27 [ 0 ] . V_33 ) ;
V_28 = & V_34 ;
V_28 -> V_35 = V_36 ;
V_28 -> V_37 = V_26 -> V_27 [ 0 ] . V_37 ;
V_28 -> V_33 = V_26 -> V_27 [ 0 ] . V_33 ;
V_28 -> V_38 = V_26 -> V_27 [ 0 ] . V_38 ;
V_39 = V_26 -> V_27 [ 0 ] . V_33 ;
return F_25 ( & V_40 ) ;
}
static int F_26 ( struct V_25 * V_26 )
{
F_24 ( V_29 L_2 ,
V_26 -> V_30 . V_31 -> V_32 , V_26 -> V_27 [ 0 ] . V_33 ) ;
V_41 . V_27 = & V_26 -> V_27 [ 0 ] ;
return F_25 ( & V_41 ) ;
}
static unsigned char F_27 ( struct V_42 * V_30 , T_1 V_43 )
{
struct V_25 * V_44 = F_28 ( V_30 ) ;
void T_2 * V_2 = ( void T_2 * ) V_44 -> V_27 [ 0 ] . V_33 ;
return F_29 ( V_2 + V_43 ) ;
}
static void F_30 ( struct V_42 * V_30 , T_1 V_43 , T_3 V_20 )
{
struct V_25 * V_44 = F_28 ( V_30 ) ;
void T_2 * V_2 = ( void T_2 * ) V_44 -> V_27 [ 0 ] . V_33 ;
F_31 ( V_20 , V_2 + V_43 ) ;
}
static int F_32 ( struct V_25 * V_26 )
{
struct V_45 * V_46 = V_26 -> V_30 . V_31 ;
if ( ! strcmp ( V_46 -> V_47 -> V_37 , L_3 ) &&
strcmp ( V_46 -> V_47 -> V_47 -> V_37 , L_4 ) != 0 )
return - V_48 ;
F_24 ( V_29 L_5 ,
V_46 -> V_32 , V_26 -> V_27 [ 0 ] . V_33 ) ;
V_49 . V_27 = & V_26 -> V_27 [ 0 ] ;
return F_25 ( & V_49 ) ;
}
static int T_4 F_33 ( void )
{
if ( V_50 )
return F_25 ( & V_51 ) ;
if ( V_13 == V_14 )
return F_25 ( & V_52 ) ;
( void ) F_34 ( & V_53 ) ;
( void ) F_34 ( & V_54 ) ;
( void ) F_34 ( & V_55 ) ;
return 0 ;
}
static unsigned long F_35 ( void )
{
struct V_45 * V_46 ;
unsigned long V_56 ;
V_46 = F_36 ( L_6 ) ;
if ( V_13 == V_57 ) {
unsigned long V_58 , V_59 , V_60 ;
__asm__ __volatile__ ("rdpr %%ver, %0"
: "=&r" (ver));
V_59 = ( ( V_58 >> 48 ) & 0xffff ) ;
V_60 = ( ( V_58 >> 32 ) & 0xffff ) ;
if ( V_59 == 0x17 && V_60 == 0x13 ) {
V_61 = & V_62 ;
V_56 = F_37 ( V_46 , L_7 , 0 ) ;
} else {
V_61 = & V_63 ;
V_56 = F_38 () . V_64 ;
}
} else {
V_61 = & V_65 ;
V_56 = F_37 ( V_46 , L_7 , 0 ) ;
}
return V_56 ;
}
unsigned long F_39 ( unsigned int V_66 )
{
struct V_67 * V_68 = & F_40 ( V_69 , V_66 ) ;
if ( V_68 -> V_70 )
return V_68 -> V_70 ;
return F_41 ( V_66 ) . V_64 ;
}
static int F_42 ( struct V_71 * V_72 , unsigned long V_20 ,
void * V_73 )
{
struct V_74 * V_56 = V_73 ;
unsigned int V_66 = V_56 -> V_66 ;
struct V_67 * V_68 = & F_40 ( V_69 , V_66 ) ;
if ( ! V_68 -> V_75 ) {
V_68 -> V_75 = V_56 -> V_76 ;
V_68 -> V_70 = F_41 ( V_66 ) . V_64 ;
}
if ( ( V_20 == V_77 && V_56 -> V_76 < V_56 -> V_78 ) ||
( V_20 == V_79 && V_56 -> V_76 > V_56 -> V_78 ) ) {
F_41 ( V_66 ) . V_64 =
F_43 ( V_68 -> V_70 ,
V_68 -> V_75 ,
V_56 -> V_78 ) ;
}
return 0 ;
}
static int T_4 F_44 ( void )
{
F_45 ( & V_80 ,
V_81 ) ;
return 0 ;
}
static int F_46 ( unsigned long V_82 ,
struct V_83 * V_84 )
{
return V_61 -> V_85 ( V_82 ) ? - V_86 : 0 ;
}
static int F_47 ( struct V_83 * V_84 )
{
V_61 -> V_87 () ;
return 0 ;
}
void T_5 F_48 ( int V_88 , struct V_1 * V_2 )
{
struct V_1 * V_89 = F_49 ( V_2 ) ;
unsigned long V_90 = V_61 -> V_91 ;
int V_66 = F_50 () ;
struct V_83 * V_84 = & F_40 ( V_92 , V_66 ) ;
F_51 ( V_90 ) ;
F_52 () ;
F_38 () . V_93 ++ ;
F_53 ( 0 ) ;
if ( F_54 ( ! V_84 -> V_94 ) ) {
F_24 ( V_95
L_8 , V_66 ) ;
} else
V_84 -> V_94 ( V_84 ) ;
F_55 () ;
F_49 ( V_89 ) ;
}
void F_56 ( void )
{
struct V_83 * V_96 ;
unsigned long V_97 ;
__asm__ __volatile__("rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
V_61 -> V_98 () ;
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
:
: "r" (pstate));
V_96 = F_57 ( & V_92 ) ;
memcpy ( V_96 , & V_99 , sizeof( * V_96 ) ) ;
V_96 -> V_100 = F_58 ( F_50 () ) ;
F_59 ( V_96 ) ;
}
void F_60 ( unsigned long V_101 )
{
unsigned long V_102 , V_103 ;
V_102 = V_61 -> V_104 () ;
do {
V_103 = V_61 -> V_104 () ;
} while ( ( V_103 - V_102 ) < V_101 );
}
void F_61 ( unsigned long V_105 )
{
F_60 ( V_106 * V_105 ) ;
}
static T_6 F_62 ( struct V_107 * V_108 )
{
return V_61 -> V_104 () ;
}
void T_4 F_63 ( void )
{
unsigned long V_56 = F_35 () ;
V_106 = V_56 / V_109 ;
V_110 =
F_64 ( V_56 , V_111 ) ;
V_112 . V_37 = V_61 -> V_37 ;
V_112 . V_113 = F_62 ;
F_65 ( & V_112 , V_56 ) ;
F_24 ( L_9 ,
V_112 . V_114 , V_112 . V_115 ) ;
V_99 . V_37 = V_61 -> V_37 ;
F_66 ( & V_99 , V_56 , 4 ) ;
V_99 . V_116 =
F_67 ( 0x7fffffffffffffffUL , & V_99 ) ;
V_99 . V_117 =
F_67 ( 0xF , & V_99 ) ;
F_24 ( L_10 ,
V_99 . V_114 , V_99 . V_115 ) ;
F_56 () ;
}
unsigned long long F_68 ( void )
{
unsigned long V_118 = V_61 -> V_104 () ;
return ( V_118 * V_110 )
>> V_111 ;
}
int F_69 ( unsigned long * V_119 )
{
* V_119 = V_61 -> V_104 () ;
return 0 ;
}
