static inline unsigned long F_1 ( unsigned long * V_1 , unsigned long V_2 )
{
__asm__ __volatile__("swap [%2], %0" : "=&r" (value) : "0" (value), "r" (addr));
return V_2 ;
}
static inline void F_2 ( T_1 * V_3 , T_1 V_4 )
{
F_1 ( ( unsigned long * ) V_3 , F_3 ( V_4 ) ) ;
}
static inline int F_4 ( unsigned long V_5 )
{
return ( ( V_5 & 0xF0000000 ) != 0 ) ;
}
static unsigned long F_5 ( T_1 V_6 )
{
if ( F_4 ( F_3 ( V_6 ) ) ) {
return ~ 0UL ;
}
return ( F_3 ( V_6 ) & V_7 ) >> ( V_8 - 4 ) ;
}
static struct V_9 * F_6 ( T_2 V_10 )
{
if ( F_4 ( F_7 ( V_10 ) ) )
F_8 () ;
return F_9 ( ( F_7 ( V_10 ) & V_11 ) >> ( V_8 - 4 ) ) ;
}
static inline unsigned long F_10 ( T_3 V_12 )
{ return F_4 ( F_11 ( V_12 ) ) ? ~ 0 : ( unsigned long ) F_12 ( ( F_11 ( V_12 ) & V_11 ) << 4 ) ; }
static inline int F_13 ( T_1 V_6 )
{ return ! ( F_3 ( V_6 ) & 0xFFFFFFF ) ; }
static inline int F_14 ( T_1 V_6 )
{ return ( ( F_3 ( V_6 ) & V_13 ) == V_14 ) ; }
static inline void F_15 ( T_1 * V_3 )
{ F_2 ( V_3 , F_16 ( 0 ) ) ; }
static inline int F_17 ( T_2 V_10 )
{ return ! ( F_7 ( V_10 ) & 0xFFFFFFF ) ; }
static inline int F_18 ( T_2 V_10 )
{ return ( F_7 ( V_10 ) & V_13 ) != V_15 ; }
static inline int F_19 ( T_2 V_10 )
{ return ( ( F_7 ( V_10 ) & V_13 ) == V_15 ) ; }
static inline void F_20 ( T_2 * V_16 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 / V_19 ; V_17 ++ )
F_2 ( ( T_1 * ) & V_16 -> V_20 [ V_17 ] , F_16 ( 0 ) ) ;
}
static inline int F_21 ( T_3 V_12 )
{ return ! ( F_11 ( V_12 ) & 0xFFFFFFF ) ; }
static inline int F_22 ( T_3 V_12 )
{ return ( F_11 ( V_12 ) & V_13 ) != V_15 ; }
static inline int F_23 ( T_3 V_12 )
{ return ( ( F_11 ( V_12 ) & V_13 ) == V_15 ) ; }
static inline void F_24 ( T_3 * V_21 )
{ F_2 ( ( T_1 * ) V_21 , F_16 ( 0 ) ) ; }
static inline T_1 F_25 ( T_1 V_6 )
{ return F_16 ( F_3 ( V_6 ) & ~ V_22 ) ; }
static inline T_1 F_26 ( T_1 V_6 )
{ return F_16 ( F_3 ( V_6 ) & ~ V_23 ) ; }
static inline T_1 F_27 ( T_1 V_6 )
{ return F_16 ( F_3 ( V_6 ) & ~ V_24 ) ; }
static inline T_1 F_28 ( T_1 V_6 )
{ return F_16 ( F_3 ( V_6 ) | V_22 ) ; }
static inline T_1 F_29 ( T_1 V_6 )
{ return F_16 ( F_3 ( V_6 ) | V_23 ) ; }
static inline T_1 F_30 ( T_1 V_6 )
{ return F_16 ( F_3 ( V_6 ) | V_24 ) ; }
static T_1 F_31 ( struct V_9 * V_9 , T_4 V_25 )
{ return F_16 ( ( F_32 ( V_9 ) << ( V_8 - 4 ) ) | F_33 ( V_25 ) ) ; }
static T_1 F_34 ( unsigned long V_9 , T_4 V_25 )
{ return F_16 ( ( ( V_9 ) >> 4 ) | F_33 ( V_25 ) ) ; }
static T_1 F_35 ( unsigned long V_9 , T_4 V_25 , int V_26 )
{ return F_16 ( ( ( V_9 ) >> 4 ) | ( V_26 << 28 ) | F_33 ( V_25 ) ) ; }
static inline void F_36 ( T_5 * V_27 , T_3 * V_21 )
{ F_2 ( ( T_1 * ) V_27 , ( V_15 | ( F_37 ( ( unsigned long ) V_21 ) >> 4 ) ) ) ; }
static inline void F_38 ( T_3 * V_21 , T_2 * V_16 )
{ F_2 ( ( T_1 * ) V_21 , ( V_15 | ( F_37 ( ( unsigned long ) V_16 ) >> 4 ) ) ) ; }
static void F_39 ( T_2 * V_16 , T_1 * V_3 )
{
unsigned long V_28 ;
int V_17 ;
V_28 = F_37 ( ( unsigned long ) V_3 ) >> 4 ;
for ( V_17 = 0 ; V_17 < V_18 / V_19 ; V_17 ++ ) {
F_2 ( ( T_1 * ) & V_16 -> V_20 [ V_17 ] , V_15 | V_28 ) ;
V_28 += ( V_19 * sizeof( T_1 ) >> 4 ) ;
}
}
static void F_40 ( T_2 * V_16 , struct V_9 * V_3 )
{
unsigned long V_28 ;
int V_17 ;
V_28 = F_32 ( V_3 ) << ( V_8 - 4 ) ;
for ( V_17 = 0 ; V_17 < V_18 / V_19 ; V_17 ++ ) {
F_2 ( ( T_1 * ) & V_16 -> V_20 [ V_17 ] , V_15 | V_28 ) ;
V_28 += ( V_19 * sizeof( T_1 ) >> 4 ) ;
}
}
static inline T_1 F_41 ( T_1 V_6 , T_4 V_29 )
{ return F_16 ( ( F_3 ( V_6 ) & V_30 ) | F_33 ( V_29 ) ) ; }
static inline T_3 * F_42 ( struct V_31 * V_32 , unsigned long V_33 )
{ return V_32 -> V_12 + ( V_33 >> V_34 ) ; }
static inline T_2 * F_43 ( T_3 * V_35 , unsigned long V_33 )
{
return ( T_2 * ) F_10 ( * V_35 ) +
( ( V_33 >> V_36 ) & ( V_37 - 1 ) ) ;
}
static inline T_1 * F_44 ( T_2 * V_35 , unsigned long V_33 )
{
void * V_6 ;
V_6 = F_12 ( ( V_35 -> V_20 [ 0 ] & V_11 ) << 4 ) ;
return ( T_1 * ) V_6 +
( ( V_33 >> V_8 ) & ( V_18 - 1 ) ) ;
}
static unsigned long F_45 ( T_6 V_38 )
{
return ( V_38 . V_39 >> V_40 ) & V_41 ;
}
static unsigned long F_46 ( T_6 V_38 )
{
return ( V_38 . V_39 >> V_42 ) & V_43 ;
}
static T_6 F_47 ( unsigned long type , unsigned long V_44 )
{
return ( T_6 ) {
( type & V_41 ) << V_40
| ( V_44 & V_43 ) << V_42 } ;
}
static unsigned long F_48 ( int V_45 , int V_46 )
{
int V_44 ;
if ( V_45 < V_47 ) {
F_49 ( L_1 , V_45 ) ;
V_45 = V_47 ;
}
if ( V_45 & ( V_47 - 1 ) ) {
F_49 ( L_2 , V_45 ) ;
V_45 += V_47 - 1 ;
}
F_50 ( V_46 > V_48 ) ;
V_44 = F_51 ( & V_49 ,
V_45 >> V_47 ,
V_46 >> V_47 ) ;
if ( V_44 == - 1 ) {
F_49 ( L_3 ,
V_45 , ( int ) V_50 ,
V_49 . V_51 << V_47 ) ;
return 0 ;
}
return ( V_52 + ( V_44 << V_47 ) ) ;
}
static unsigned long F_52 ( int V_45 , int V_46 )
{
unsigned long V_53 ;
V_53 = F_48 ( V_45 , V_46 ) ;
if ( V_53 )
memset ( ( void * ) V_53 , 0 , V_45 ) ;
return V_53 ;
}
static void F_53 ( unsigned long V_54 , int V_45 )
{
int V_44 ;
if ( V_54 < V_52 ) {
F_49 ( L_4 ,
V_54 , ( unsigned long ) V_52 ) ;
F_8 () ;
}
if ( V_54 + V_45 > V_55 ) {
F_49 ( L_5 ,
V_54 , V_55 ) ;
F_8 () ;
}
if ( ! F_54 ( V_45 ) ) {
F_49 ( L_6 , V_45 ) ;
F_8 () ;
}
if ( V_45 < V_47 ) {
F_49 ( L_7 , V_45 ) ;
F_8 () ;
}
if ( V_54 & ( V_45 - 1 ) ) {
F_49 ( L_8 , V_54 , V_45 ) ;
F_8 () ;
}
V_44 = ( V_54 - V_52 ) >> V_47 ;
V_45 = V_45 >> V_47 ;
F_55 ( & V_49 , V_44 , V_45 ) ;
}
static void F_56 ( void )
{
unsigned long V_56 = F_57 () / 1024 ;
int V_57 ;
V_57 =
V_56 / V_58 / 1024 * 256 ;
if ( V_57 < V_59 )
V_57 = V_59 ;
if ( V_57 > V_60 )
V_57 = V_60 ;
V_50 = V_57 * V_61 ;
V_55 = V_52 + V_50 ;
}
static void T_7 F_58 ( void )
{
unsigned int V_62 ;
T_3 * V_12 ;
T_2 * V_10 ;
T_1 * V_6 ;
unsigned long V_63 , V_54 ;
unsigned long V_4 ;
V_62 = V_50 >> V_47 ;
V_64 = F_59 ( V_50 ,
V_48 , 0UL ) ;
memset ( V_64 , 0 , V_50 ) ;
V_65 = F_59 ( V_62 >> 3 , V_66 , 0UL ) ;
F_60 ( & V_49 , V_65 , V_62 ) ;
V_67 = ( T_3 * ) F_48 ( V_68 , V_68 ) ;
memset ( F_61 ( V_67 ) , 0 , V_68 ) ;
V_69 . V_12 = V_67 ;
F_62 ( V_52 , V_55 ) ;
V_63 = F_63 ( ( unsigned long ) V_64 ) ;
V_54 = V_52 ;
while ( V_54 < V_55 ) {
V_12 = F_64 ( V_54 ) ;
V_10 = F_43 ( F_61 ( V_12 ) , V_54 ) ;
V_6 = F_44 ( F_61 ( V_10 ) , V_54 ) ;
V_4 = ( ( V_63 >> 4 ) | V_14 | V_70 ) ;
if ( V_71 )
V_4 |= V_72 ;
F_2 ( F_61 ( V_6 ) , F_16 ( V_4 ) ) ;
V_54 += V_61 ;
V_63 += V_61 ;
}
F_65 () ;
F_66 () ;
}
static inline T_3 * F_67 ( void )
{
T_3 * V_12 = NULL ;
V_12 = ( T_3 * ) F_48 ( V_68 , V_68 ) ;
if ( V_12 ) {
T_3 * V_73 = F_64 ( 0 ) ;
memset ( V_12 , 0 , V_74 * sizeof( T_3 ) ) ;
memcpy ( V_12 + V_74 , V_73 + V_74 ,
( V_75 - V_74 ) * sizeof( T_3 ) ) ;
}
return V_12 ;
}
static void F_68 ( T_3 * V_12 )
{
F_53 ( ( unsigned long ) V_12 , V_68 ) ;
}
static T_2 * F_69 ( struct V_31 * V_32 , unsigned long V_33 )
{
return ( T_2 * ) F_52 ( V_76 , V_76 ) ;
}
static void F_70 ( T_2 * V_10 )
{
F_53 ( ( unsigned long ) V_10 , V_76 ) ;
}
static T_1 *
F_71 ( struct V_31 * V_32 , unsigned long V_33 )
{
return ( T_1 * ) F_52 ( V_77 , V_77 ) ;
}
static T_8
F_72 ( struct V_31 * V_32 , unsigned long V_33 )
{
unsigned long V_6 ;
struct V_9 * V_9 ;
if ( ( V_6 = ( unsigned long ) F_71 ( V_32 , V_33 ) ) == 0 )
return NULL ;
V_9 = F_9 ( F_37 ( V_6 ) >> V_8 ) ;
F_73 ( V_9 ) ;
return V_9 ;
}
static void F_74 ( T_1 * V_6 )
{
F_53 ( ( unsigned long ) V_6 , V_77 ) ;
}
static void F_75 ( T_8 V_6 )
{
unsigned long V_78 ;
F_76 ( V_6 ) ;
V_78 = ( unsigned long ) F_77 ( V_6 ) ;
if ( V_78 == 0 )
F_8 () ;
V_78 = F_32 ( V_6 ) << V_8 ;
V_78 = ( unsigned long ) F_12 ( V_78 ) ;
F_53 ( V_78 , V_77 ) ;
}
static inline void F_78 ( struct V_31 * V_79 , struct V_31 * V_32 )
{
struct V_80 * V_27 ;
V_27 = V_81 . V_82 ;
if( V_27 != & V_81 ) {
F_79 ( V_27 ) ;
F_80 ( V_27 ) ;
V_32 -> V_83 = V_27 -> V_84 ;
V_27 -> V_85 = V_32 ;
return;
}
V_27 = V_86 . V_82 ;
if( V_27 -> V_85 == V_79 )
V_27 = V_27 -> V_82 ;
if( V_27 == & V_86 )
F_81 ( L_9 ) ;
F_82 ( V_27 -> V_85 ) ;
F_83 ( V_27 -> V_85 ) ;
F_79 ( V_27 ) ;
F_80 ( V_27 ) ;
V_27 -> V_85 -> V_83 = V_87 ;
V_27 -> V_85 = V_32 ;
V_32 -> V_83 = V_27 -> V_84 ;
}
static inline void F_84 ( int V_83 )
{
struct V_80 * V_88 ;
V_88 = V_89 + V_83 ;
F_79 ( V_88 ) ;
F_85 ( V_88 ) ;
}
static void F_86 ( struct V_31 * V_79 , struct V_31 * V_32 ,
struct V_90 * V_91 , int V_92 )
{
if( V_32 -> V_83 == V_87 ) {
F_87 ( & V_93 ) ;
F_78 ( V_79 , V_32 ) ;
F_88 ( & V_93 ) ;
F_36 ( & V_94 [ V_32 -> V_83 ] , V_32 -> V_12 ) ;
}
if ( V_95 == V_96 )
F_89 () ;
if ( V_97 )
F_90 () ;
F_91 ( V_32 -> V_83 ) ;
}
static inline void F_92 ( unsigned long V_98 ,
unsigned long V_99 , int V_100 )
{
T_3 * V_21 ;
T_2 * V_16 ;
T_1 * V_3 ;
unsigned long V_53 ;
V_98 &= V_101 ;
V_21 = F_64 ( V_99 ) ;
V_16 = F_43 ( V_21 , V_99 ) ;
V_3 = F_44 ( V_16 , V_99 ) ;
V_53 = ( V_98 >> 4 ) | V_14 ;
V_53 |= ( V_100 << 28 ) ;
V_53 |= V_70 ;
F_93 ( V_99 ) ;
F_2 ( V_3 , F_16 ( V_53 ) ) ;
}
static void F_94 ( unsigned int V_102 , unsigned long V_103 ,
unsigned long V_104 , unsigned int V_105 )
{
while ( V_105 != 0 ) {
V_105 -= V_61 ;
F_92 ( V_103 , V_104 , V_102 ) ;
V_104 += V_61 ;
V_103 += V_61 ;
}
F_66 () ;
}
static inline void F_95 ( unsigned long V_99 )
{
T_3 * V_21 ;
T_2 * V_16 ;
T_1 * V_3 ;
V_21 = F_64 ( V_99 ) ;
V_16 = F_43 ( V_21 , V_99 ) ;
V_3 = F_44 ( V_16 , V_99 ) ;
F_15 ( V_3 ) ;
}
static void F_96 ( unsigned long V_99 , unsigned int V_105 )
{
while ( V_105 != 0 ) {
V_105 -= V_61 ;
F_95 ( V_99 ) ;
V_99 += V_61 ;
}
F_66 () ;
}
static struct V_106 * F_97 ( int V_107 )
{
struct V_106 * V_108 ;
V_108 = (struct V_106 * ) F_98 ( V_109 ,
V_110 ) ;
#ifdef F_99
if ( V_108 )
memset ( V_108 , 0 , V_61 << V_110 ) ;
#endif
return V_108 ;
}
static void F_100 ( struct V_106 * V_111 )
{
F_101 ( ( unsigned long ) V_111 , V_110 ) ;
}
static void F_102 ( struct V_112 * V_113 , unsigned long V_33 , T_1 * V_3 )
{
#if 0
static unsigned long last;
unsigned int val;
if (address == last) {
val = srmmu_hwprobe(address);
if (val != 0 && pte_val(*ptep) != val) {
printk("swift_update_mmu_cache: "
"addr %lx put %08x probed %08x from %p\n",
address, pte_val(*ptep), val,
__builtin_return_address(0));
srmmu_flush_whole_tlb();
}
}
last = address;
#endif
}
static void F_103 ( void )
{
volatile unsigned long V_114 ;
unsigned long V_115 , V_116 ;
F_104 () ;
for( V_115 = 0 ; V_115 < 0x10000 ; V_115 += 0x20 ) {
__asm__ __volatile__("lda [%1 + %2] %3, %0\n\t" :
"=r" (tagval) :
"r" (faddr), "r" (0x40000),
"i" (ASI_M_DATAC_TAG));
if( ( V_116 & 0x60 ) == 0x60 )
V_114 = * ( unsigned long * ) ( 0xf0020000 + V_115 ) ;
}
}
static void F_105 ( struct V_31 * V_32 )
{
register unsigned long V_117 , V_118 , V_119 , V_120 , V_121 , V_122 , V_123 ;
unsigned long V_124 , V_115 ;
int V_125 ;
F_106 (mm)
F_104 () ;
F_107 ( V_124 ) ;
V_125 = F_108 () ;
F_91 ( V_32 -> V_83 ) ;
V_117 = 0x20 ; V_118 = 0x40 ; V_119 = 0x60 ;
V_120 = 0x80 ; V_121 = 0xa0 ; V_122 = 0xc0 ; V_123 = 0xe0 ;
V_115 = ( 0x10000 - 0x100 ) ;
goto V_126;
do {
V_115 -= 0x100 ;
V_126:
__asm__ __volatile__("sta %%g0, [%0] %1\n\t"
"sta %%g0, [%0 + %2] %1\n\t"
"sta %%g0, [%0 + %3] %1\n\t"
"sta %%g0, [%0 + %4] %1\n\t"
"sta %%g0, [%0 + %5] %1\n\t"
"sta %%g0, [%0 + %6] %1\n\t"
"sta %%g0, [%0 + %7] %1\n\t"
"sta %%g0, [%0 + %8] %1\n\t" : :
"r" (faddr), "i" (ASI_M_FLUSH_CTX),
"r" (a), "r" (b), "r" (c), "r" (d),
"r" (e), "r" (f), "r" (g));
} while( V_115 );
F_91 ( V_125 ) ;
F_109 ( V_124 ) ;
V_127
}
static void F_110 ( struct V_112 * V_113 , unsigned long V_128 , unsigned long V_129 )
{
struct V_31 * V_32 = V_113 -> V_130 ;
register unsigned long V_117 , V_118 , V_119 , V_120 , V_121 , V_122 , V_123 ;
unsigned long V_124 , V_115 ;
int V_125 ;
F_106 (mm)
F_104 () ;
F_107 ( V_124 ) ;
V_125 = F_108 () ;
F_91 ( V_32 -> V_83 ) ;
V_117 = 0x20 ; V_118 = 0x40 ; V_119 = 0x60 ;
V_120 = 0x80 ; V_121 = 0xa0 ; V_122 = 0xc0 ; V_123 = 0xe0 ;
V_128 &= V_131 ;
while( V_128 < V_129 ) {
V_115 = ( V_128 + ( 0x10000 - 0x100 ) ) ;
goto V_126;
do {
V_115 -= 0x100 ;
V_126:
__asm__ __volatile__("sta %%g0, [%0] %1\n\t"
"sta %%g0, [%0 + %2] %1\n\t"
"sta %%g0, [%0 + %3] %1\n\t"
"sta %%g0, [%0 + %4] %1\n\t"
"sta %%g0, [%0 + %5] %1\n\t"
"sta %%g0, [%0 + %6] %1\n\t"
"sta %%g0, [%0 + %7] %1\n\t"
"sta %%g0, [%0 + %8] %1\n\t" : :
"r" (faddr),
"i" (ASI_M_FLUSH_SEG),
"r" (a), "r" (b), "r" (c), "r" (d),
"r" (e), "r" (f), "r" (g));
} while ( V_115 != V_128 );
V_128 += V_132 ;
}
F_91 ( V_125 ) ;
F_109 ( V_124 ) ;
V_127
}
static void F_111 ( struct V_112 * V_113 , unsigned long V_9 )
{
register unsigned long V_117 , V_118 , V_119 , V_120 , V_121 , V_122 , V_123 ;
struct V_31 * V_32 = V_113 -> V_130 ;
unsigned long V_124 , line ;
int V_125 ;
F_106 (mm)
F_104 () ;
F_107 ( V_124 ) ;
V_125 = F_108 () ;
F_91 ( V_32 -> V_83 ) ;
V_117 = 0x20 ; V_118 = 0x40 ; V_119 = 0x60 ;
V_120 = 0x80 ; V_121 = 0xa0 ; V_122 = 0xc0 ; V_123 = 0xe0 ;
V_9 &= V_101 ;
line = ( V_9 + V_61 ) - 0x100 ;
goto V_126;
do {
line -= 0x100 ;
V_126:
__asm__ __volatile__("sta %%g0, [%0] %1\n\t"
"sta %%g0, [%0 + %2] %1\n\t"
"sta %%g0, [%0 + %3] %1\n\t"
"sta %%g0, [%0 + %4] %1\n\t"
"sta %%g0, [%0 + %5] %1\n\t"
"sta %%g0, [%0 + %6] %1\n\t"
"sta %%g0, [%0 + %7] %1\n\t"
"sta %%g0, [%0 + %8] %1\n\t" : :
"r" (line),
"i" (ASI_M_FLUSH_PAGE),
"r" (a), "r" (b), "r" (c), "r" (d),
"r" (e), "r" (f), "r" (g));
} while( line != V_9 );
F_91 ( V_125 ) ;
F_109 ( V_124 ) ;
V_127
}
static void F_112 ( unsigned long V_9 )
{
register unsigned long V_117 , V_118 , V_119 , V_120 , V_121 , V_122 , V_123 ;
unsigned long line ;
V_117 = 0x20 ; V_118 = 0x40 ; V_119 = 0x60 ; V_120 = 0x80 ; V_121 = 0xa0 ; V_122 = 0xc0 ; V_123 = 0xe0 ;
V_9 &= V_101 ;
line = ( V_9 + V_61 ) - 0x100 ;
goto V_126;
do {
line -= 0x100 ;
V_126:
__asm__ __volatile__("sta %%g0, [%0] %1\n\t"
"sta %%g0, [%0 + %2] %1\n\t"
"sta %%g0, [%0 + %3] %1\n\t"
"sta %%g0, [%0 + %4] %1\n\t"
"sta %%g0, [%0 + %5] %1\n\t"
"sta %%g0, [%0 + %6] %1\n\t"
"sta %%g0, [%0 + %7] %1\n\t"
"sta %%g0, [%0 + %8] %1\n\t" : :
"r" (line),
"i" (ASI_M_FLUSH_PAGE),
"r" (a), "r" (b), "r" (c), "r" (d),
"r" (e), "r" (f), "r" (g));
} while( line != V_9 );
}
static void F_113 ( unsigned long V_9 )
{
}
static void F_114 ( struct V_31 * V_32 , unsigned long V_133 )
{
}
static void F_115 ( void )
{
F_116 () ;
}
static void F_117 ( struct V_31 * V_32 )
{
F_106 (mm)
__asm__ __volatile__(
"lda [%0] %3, %%g5\n\t"
"sta %2, [%0] %3\n\t"
"sta %%g0, [%1] %4\n\t"
"sta %%g5, [%0] %3\n"
:
: "r" (SRMMU_CTX_REG), "r" (0x300), "r" (mm->context),
"i" (ASI_M_MMUREGS), "i" (ASI_M_FLUSH_PROBE)
: "g5");
V_127
}
static void F_118 ( struct V_112 * V_113 , unsigned long V_128 , unsigned long V_129 )
{
struct V_31 * V_32 = V_113 -> V_130 ;
unsigned long V_45 ;
F_106 (mm)
V_128 &= V_134 ;
V_45 = F_119 ( V_129 ) - V_128 ;
__asm__ __volatile__(
"lda [%0] %5, %%g5\n\t"
"sta %1, [%0] %5\n"
"1:\n\t"
"subcc %3, %4, %3\n\t"
"bne 1b\n\t"
" sta %%g0, [%2 + %3] %6\n\t"
"sta %%g5, [%0] %5\n"
:
: "r" (SRMMU_CTX_REG), "r" (mm->context), "r" (start | 0x200),
"r" (size), "r" (SRMMU_PGDIR_SIZE), "i" (ASI_M_MMUREGS),
"i" (ASI_M_FLUSH_PROBE)
: "g5", "cc");
V_127
}
static void F_120 ( struct V_112 * V_113 , unsigned long V_9 )
{
struct V_31 * V_32 = V_113 -> V_130 ;
F_106 (mm)
__asm__ __volatile__(
"lda [%0] %3, %%g5\n\t"
"sta %1, [%0] %3\n\t"
"sta %%g0, [%2] %4\n\t"
"sta %%g5, [%0] %3\n"
:
: "r" (SRMMU_CTX_REG), "r" (mm->context), "r" (page & PAGE_MASK),
"i" (ASI_M_MMUREGS), "i" (ASI_M_FLUSH_PROBE)
: "g5");
V_127
}
static void T_7 F_121 ( char * type )
{
F_122 ( L_10 , type ) ;
F_123 () ;
}
static void T_7 F_62 ( unsigned long V_128 ,
unsigned long V_129 )
{
T_3 * V_21 ;
T_2 * V_16 ;
T_1 * V_3 ;
while( V_128 < V_129 ) {
V_21 = F_64 ( V_128 ) ;
if( F_21 ( * ( T_3 * ) F_61 ( V_21 ) ) ) {
V_16 = ( T_2 * ) F_48 (
V_76 , V_76 ) ;
if ( V_16 == NULL )
F_121 ( L_11 ) ;
memset ( F_61 ( V_16 ) , 0 , V_76 ) ;
F_38 ( F_61 ( V_21 ) , V_16 ) ;
}
V_16 = F_43 ( F_61 ( V_21 ) , V_128 ) ;
if( F_17 ( * ( T_2 * ) F_61 ( V_16 ) ) ) {
V_3 = ( T_1 * ) F_48 ( V_77 , V_77 ) ;
if ( V_3 == NULL )
F_121 ( L_12 ) ;
memset ( F_61 ( V_3 ) , 0 , V_77 ) ;
F_39 ( F_61 ( V_16 ) , V_3 ) ;
}
if ( V_128 > ( 0xffffffffUL - V_135 ) )
break;
V_128 = ( V_128 + V_135 ) & V_136 ;
}
}
static void T_7 F_124 ( unsigned long V_128 ,
unsigned long V_129 )
{
T_3 * V_21 ;
T_2 * V_16 ;
T_1 * V_3 ;
while( V_128 < V_129 ) {
V_21 = F_64 ( V_128 ) ;
if( F_21 ( * V_21 ) ) {
V_16 = ( T_2 * ) F_48 ( V_76 , V_76 ) ;
if ( V_16 == NULL )
F_121 ( L_11 ) ;
memset ( V_16 , 0 , V_76 ) ;
F_38 ( V_21 , V_16 ) ;
}
V_16 = F_43 ( V_21 , V_128 ) ;
if( F_17 ( * V_16 ) ) {
V_3 = ( T_1 * ) F_48 ( V_77 ,
V_77 ) ;
if ( V_3 == NULL )
F_121 ( L_12 ) ;
memset ( V_3 , 0 , V_77 ) ;
F_39 ( V_16 , V_3 ) ;
}
if ( V_128 > ( 0xffffffffUL - V_135 ) )
break;
V_128 = ( V_128 + V_135 ) & V_136 ;
}
}
static void T_7 F_125 ( unsigned long V_128 ,
unsigned long V_129 )
{
T_3 * V_21 ;
T_2 * V_16 ;
T_1 * V_3 ;
int V_137 = 0 ;
unsigned long V_138 ;
while( V_128 <= V_129 ) {
if ( V_128 == 0 )
break;
if( V_128 == 0xfef00000 )
V_128 = V_139 ;
if( ! ( V_138 = F_126 ( V_128 ) ) ) {
V_128 += V_61 ;
continue;
}
V_137 = 0 ;
if( ! ( V_128 & ~ ( V_131 ) ) ) {
if( F_126 ( ( V_128 - V_61 ) + V_132 ) == V_138 )
V_137 = 1 ;
}
if( ! ( V_128 & ~ ( V_134 ) ) ) {
if( F_126 ( ( V_128 - V_61 ) + V_140 ) ==
V_138 )
V_137 = 2 ;
}
V_21 = F_64 ( V_128 ) ;
if( V_137 == 2 ) {
* ( T_3 * ) F_61 ( V_21 ) = F_127 ( V_138 ) ;
V_128 += V_140 ;
continue;
}
if( F_21 ( * ( T_3 * ) F_61 ( V_21 ) ) ) {
V_16 = ( T_2 * ) F_48 ( V_76 , V_76 ) ;
if ( V_16 == NULL )
F_121 ( L_11 ) ;
memset ( F_61 ( V_16 ) , 0 , V_76 ) ;
F_38 ( F_61 ( V_21 ) , V_16 ) ;
}
V_16 = F_43 ( F_61 ( V_21 ) , V_128 ) ;
if( F_17 ( * ( T_2 * ) F_61 ( V_16 ) ) ) {
V_3 = ( T_1 * ) F_48 ( V_77 ,
V_77 ) ;
if ( V_3 == NULL )
F_121 ( L_12 ) ;
memset ( F_61 ( V_3 ) , 0 , V_77 ) ;
F_39 ( F_61 ( V_16 ) , V_3 ) ;
}
if( V_137 == 1 ) {
unsigned int V_5 ;
V_5 = ( V_128 >> V_36 ) & 15 ;
* ( unsigned long * ) F_61 ( & V_16 -> V_20 [ V_5 ] ) = V_138 ;
V_128 += V_132 ;
continue;
}
V_3 = F_44 ( F_61 ( V_16 ) , V_128 ) ;
* ( T_1 * ) F_61 ( V_3 ) = F_16 ( V_138 ) ;
V_128 += V_61 ;
}
}
static void T_7 F_128 ( unsigned long V_54 , unsigned long V_141 )
{
T_3 * V_21 = F_64 ( V_54 ) ;
unsigned long V_142 ;
V_142 = F_129 ( V_141 >> 4 ) ;
* ( T_3 * ) F_61 ( V_21 ) = F_127 ( V_142 ) ;
}
static unsigned long T_7 F_130 ( unsigned long V_143 , int V_144 )
{
unsigned long V_145 = ( V_146 [ V_144 ] . V_147 & V_134 ) ;
unsigned long V_148 = ( V_143 & V_134 ) ;
unsigned long V_149 = F_119 ( V_143 + V_146 [ V_144 ] . V_150 ) ;
const unsigned long V_151 = V_152 ;
const unsigned long V_153 = V_152 + V_154 ;
if ( V_148 < V_151 || V_148 >= V_153 )
return V_148 ;
if ( V_149 > V_153 || V_149 < V_151 )
V_149 = V_153 ;
while( V_148 < V_149 ) {
F_128 ( V_148 , V_145 ) ;
V_148 += V_140 ; V_145 += V_140 ;
}
return V_148 ;
}
static inline void F_131 ( char * V_155 )
{
F_122 ( V_155 ) ;
F_122 ( L_13 ) ;
F_123 () ;
}
static inline void F_132 ( void )
{
int V_17 ;
if ( V_141 > 0 ) {
F_128 ( V_152 , V_141 ) ;
}
for ( V_17 = 0 ; V_146 [ V_17 ] . V_150 != 0 ; V_17 ++ ) {
F_130 ( ( unsigned long ) F_133 ( V_146 [ V_17 ] . V_147 ) , V_17 ) ;
}
F_134 ( V_156 , V_152 / V_140 ) ;
}
void T_7 F_135 ( void )
{
int V_17 ;
T_9 V_157 ;
char V_158 [ 128 ] ;
T_3 * V_12 ;
T_2 * V_10 ;
T_1 * V_6 ;
unsigned long V_159 ;
V_160 . V_128 = V_161 ;
if ( V_95 == V_162 )
V_163 = 65536 ;
else {
V_157 = F_136 ( V_164 ) ;
V_163 = 0 ;
while( V_157 != 0 ) {
F_137 ( V_157 , L_14 , V_158 , sizeof( V_158 ) ) ;
if( ! strcmp ( V_158 , L_15 ) ) {
V_163 = F_138 ( V_157 , L_16 , 0x8 ) ;
break;
}
V_157 = F_139 ( V_157 ) ;
}
}
if( ! V_163 ) {
F_122 ( L_17 ) ;
F_123 () ;
}
V_159 = 0 ;
V_165 = F_140 ( & V_159 ) ;
F_56 () ;
F_58 () ;
F_125 ( 0xfe400000 , ( V_166 - V_61 ) ) ;
F_132 () ;
V_94 = ( T_5 * ) F_48 ( V_163 * sizeof( T_5 ) , V_163 * sizeof( T_5 ) ) ;
V_167 = ( T_5 * ) F_37 ( ( unsigned long ) V_94 ) ;
for( V_17 = 0 ; V_17 < V_163 ; V_17 ++ )
F_36 ( ( T_5 * ) F_61 ( & V_94 [ V_17 ] ) , V_67 ) ;
F_65 () ;
F_141 ( ( unsigned long ) V_167 ) ;
#ifdef F_142
F_143 () ;
#else
F_66 () ;
#endif
F_144 () ;
F_124 ( V_160 . V_128 , V_168 ) ;
F_124 ( V_169 , V_170 ) ;
F_124 (
F_145 ( V_171 - 1 ) , V_172 ) ;
F_124 ( V_173 , V_174 ) ;
V_12 = F_64 ( V_173 ) ;
V_10 = F_43 ( V_12 , V_173 ) ;
V_6 = F_44 ( V_10 , V_173 ) ;
V_175 = V_6 ;
F_65 () ;
F_66 () ;
F_146 ( V_163 ) ;
F_147 () ;
{
unsigned long V_176 [ V_177 ] ;
unsigned long V_178 [ V_177 ] ;
unsigned long V_179 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_177 ; V_180 ++ )
V_176 [ V_180 ] = V_178 [ V_180 ] = 0 ;
V_179 = V_181 - V_182 ;
V_176 [ V_183 ] = V_179 ;
V_178 [ V_183 ] = V_179 - V_159 ;
V_179 = V_184 - V_181 ;
V_176 [ V_185 ] = V_179 ;
V_178 [ V_185 ] = V_179 - F_148 () ;
F_149 ( 0 , V_176 , V_182 , V_178 ) ;
}
}
static void F_150 ( struct V_186 * V_187 )
{
F_151 ( V_187 ,
L_18
L_19
L_20
L_21 ,
V_188 ,
V_163 ,
V_50 ,
V_49 . V_51 << V_47 ) ;
}
static void F_152 ( struct V_112 * V_113 , unsigned long V_33 , T_1 V_6 )
{
}
static void F_153 ( struct V_31 * V_32 )
{
if( V_32 -> V_83 != V_87 ) {
F_82 ( V_32 ) ;
F_36 ( & V_94 [ V_32 -> V_83 ] , V_67 ) ;
F_83 ( V_32 ) ;
F_87 ( & V_93 ) ;
F_84 ( V_32 -> V_83 ) ;
F_88 ( & V_93 ) ;
V_32 -> V_83 = V_87 ;
}
}
static void T_7 F_154 ( void )
{
F_122 ( L_22 ) ;
F_123 () ;
}
static void T_7 F_155 ( void )
{
T_9 V_189 ;
int V_190 ;
char V_158 [ 128 ] ;
#ifdef F_142
int V_92 = 0 ;
unsigned long V_191 = 0 ;
unsigned long V_192 = 0x10000000 ;
#endif
V_189 = F_136 ( V_164 ) ;
while( ( V_189 = F_139 ( V_189 ) ) != 0 ) {
F_137 ( V_189 , L_14 , V_158 , sizeof( V_158 ) ) ;
if( ! strcmp ( V_158 , L_15 ) ) {
V_193 = F_156 ( V_189 , L_23 ) ;
if ( V_193 == - 1 ) {
F_122 ( L_24
L_25 ) ;
F_123 () ;
}
V_190 = F_156 ( V_189 , L_26 ) ;
if ( V_190 == - 1 ) {
F_122 ( L_27 ) ;
F_123 () ;
}
V_194 = V_190 * V_193 ;
#ifdef F_142
if( V_194 > V_191 )
V_191 = V_194 ;
if( V_193 < V_192 )
V_192 = V_193 ;
V_92 ++ ;
if ( V_92 >= V_195 || ! F_157 ( V_92 ) )
break;
#else
break;
#endif
}
}
if( V_189 == 0 ) {
F_122 ( L_28 ) ;
F_123 () ;
}
#ifdef F_142
V_194 = V_191 ;
V_193 = V_192 ;
#endif
F_49 ( L_29 ,
( int ) V_194 , ( int ) V_193 ) ;
}
static void T_10 F_158 ( void )
{
volatile unsigned long V_196 ;
unsigned long V_197 = F_159 () ;
F_160 () ;
V_197 &= ~ ( V_198 ) ;
V_197 |= ( V_199 | V_200 ) ;
V_197 |= ( V_201 ) ;
F_161 ( V_197 ) ;
#if 0
hyper_clear_all_tags();
#endif
F_162 ( V_202 | V_203 ) ;
F_90 () ;
V_196 = F_163 () ;
V_196 = F_164 () ;
}
static void T_7 F_165 ( void )
{
V_188 = L_30 ;
V_204 = V_205 ;
F_155 () ;
V_97 = 1 ;
F_166 ( V_206 , F_15 , V_207 ) ;
F_166 ( V_208 , F_20 , V_207 ) ;
F_166 ( V_209 , F_24 , V_207 ) ;
F_166 ( F_65 , V_210 , V_207 ) ;
F_166 ( F_82 , V_211 , V_207 ) ;
F_166 ( V_212 , V_213 , V_207 ) ;
F_166 ( V_214 , V_215 , V_207 ) ;
F_166 ( F_66 , V_216 , V_207 ) ;
F_166 ( F_83 , V_217 , V_207 ) ;
F_166 ( V_218 , V_219 , V_207 ) ;
F_166 ( V_220 , V_221 , V_207 ) ;
F_166 ( F_93 , V_222 , V_207 ) ;
F_166 ( V_223 , V_224 , V_207 ) ;
F_166 ( V_225 , V_226 , V_227 ) ;
F_144 = F_158 ;
F_167 () ;
}
static void T_10 F_168 ( void )
{
unsigned long V_197 = F_159 () ;
unsigned long V_115 , V_116 ;
volatile unsigned long V_114 ;
volatile unsigned long V_196 ;
V_196 = F_163 () ;
V_196 = F_164 () ;
if ( ! ( V_197 & V_228 ) ) {
for( V_115 = 0x0 ; V_115 < 0x10000 ; V_115 += 20 ) {
__asm__ __volatile__("sta %%g0, [%0 + %1] %2\n\t"
"sta %%g0, [%0] %2\n\t" : :
"r" (faddr), "r" (0x40000),
"i" (ASI_M_DATAC_TAG));
}
} else {
for( V_115 = 0 ; V_115 < 0x10000 ; V_115 += 0x20 ) {
__asm__ __volatile__("lda [%1 + %2] %3, %0\n\t" :
"=r" (tagval) :
"r" (faddr), "r" (0x40000),
"i" (ASI_M_DATAC_TAG));
if( ( V_116 & 0x60 ) == 0x60 )
V_114 = * ( unsigned long * )
( 0xf0020000 + V_115 ) ;
}
}
V_196 = F_163 () ;
V_196 = F_164 () ;
V_197 |= ( V_228 | V_229 ) ;
F_161 ( V_197 ) ;
}
static void T_7 F_169 ( void )
{
F_155 () ;
F_166 ( V_206 , F_15 , V_207 ) ;
F_166 ( V_208 , F_20 , V_207 ) ;
F_166 ( V_209 , F_24 , V_207 ) ;
F_166 ( F_65 , F_103 , V_207 ) ;
F_166 ( F_82 , F_105 , V_207 ) ;
F_166 ( V_212 , F_110 , V_207 ) ;
F_166 ( V_214 , F_111 , V_207 ) ;
F_166 ( F_66 , F_115 , V_207 ) ;
F_166 ( F_83 , F_117 , V_207 ) ;
F_166 ( V_220 , F_120 , V_207 ) ;
F_166 ( V_218 , F_118 , V_207 ) ;
F_166 ( F_93 , F_112 , V_207 ) ;
F_166 ( V_223 , F_114 , V_227 ) ;
F_166 ( V_225 , F_113 , V_227 ) ;
F_144 = F_168 ;
}
static void T_7 F_170 ( void )
{
V_188 = L_31 ;
V_204 = V_230 ;
F_169 () ;
}
static void T_7 F_171 ( unsigned long V_231 )
{
V_188 = L_32 ;
if( V_231 == 0xe ) {
V_204 = V_232 ;
V_233 |= V_234 ;
} else {
if( V_231 == 0xd ) {
V_204 = V_235 ;
V_233 |= V_236 ;
} else {
V_204 = V_230 ;
}
}
F_169 () ;
}
static void T_10 F_172 ( void )
{
unsigned long V_197 ;
F_173 () ;
V_197 = F_159 () ;
V_197 |= ( V_237 | V_238 ) ;
V_197 &= ~ ( V_239 ) ;
F_161 ( V_197 ) ;
}
static void T_7 F_174 ( void )
{
unsigned long V_240 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t"
"srl %0, 0x18, %0\n\t" :
"=r" (swift_rev) :
"r" (SWIFT_MASKID_ADDR), "i" (ASI_M_BYPASS));
V_188 = L_33 ;
switch( V_240 ) {
case 0x11 :
case 0x20 :
case 0x23 :
case 0x30 :
V_204 = V_241 ;
V_233 |= ( V_242 | V_243 ) ;
break;
case 0x25 :
case 0x31 :
V_204 = V_244 ;
V_233 |= V_243 ;
break;
default:
V_204 = V_245 ;
break;
}
F_166 ( F_65 , F_173 , V_207 ) ;
F_166 ( F_82 , V_246 , V_207 ) ;
F_166 ( V_214 , V_247 , V_207 ) ;
F_166 ( V_212 , V_248 , V_207 ) ;
F_166 ( F_66 , V_249 , V_207 ) ;
F_166 ( F_83 , V_250 , V_207 ) ;
F_166 ( V_220 , V_251 , V_207 ) ;
F_166 ( V_218 , V_252 , V_207 ) ;
F_166 ( F_93 , V_253 , V_207 ) ;
F_166 ( V_223 , V_254 , V_207 ) ;
F_166 ( V_225 , V_255 , V_207 ) ;
F_166 ( V_256 , F_102 , V_207 ) ;
V_257 = 0 ;
F_144 = F_172 ;
}
static void F_175 ( void )
{
F_104 () ;
F_176 () ;
}
static void F_177 ( struct V_31 * V_32 )
{
F_106 (mm)
F_104 () ;
F_176 () ;
V_127
}
static void F_178 ( struct V_112 * V_113 , unsigned long V_128 , unsigned long V_129 )
{
F_106 (vma->vm_mm)
F_104 () ;
F_176 () ;
V_127
}
static void F_179 ( struct V_112 * V_113 , unsigned long V_9 )
{
F_106 (vma->vm_mm)
F_104 () ;
if ( V_113 -> V_258 & V_259 )
F_180 () ;
F_181 () ;
V_127
}
static void F_182 ( unsigned long V_9 )
{
#ifdef F_183
volatile unsigned long V_196 ;
if ( F_126 ( V_9 ) )
F_184 ( V_9 ) ;
V_196 = F_164 () ;
#endif
}
static void F_185 ( struct V_31 * V_32 , unsigned long V_133 )
{
}
static void F_186 ( unsigned long V_9 )
{
F_181 () ;
}
static void F_187 ( void )
{
F_116 () ;
}
static void F_188 ( struct V_31 * V_32 )
{
F_106 (mm)
F_116 () ;
V_127
}
static void F_189 ( struct V_112 * V_113 , unsigned long V_128 , unsigned long V_129 )
{
F_106 (vma->vm_mm)
F_116 () ;
V_127
}
static void F_190 ( struct V_112 * V_113 , unsigned long V_9 )
{
F_106 (vma->vm_mm)
F_116 () ;
V_127
}
static void T_10 F_191 ( void )
{
unsigned long V_197 = F_159 () ;
unsigned long V_260 ;
F_175 () ;
V_197 &= ~ ( V_261 | V_262 ) ;
V_197 &= ~ ( V_263 ) ;
F_161 ( V_197 ) ;
V_260 = F_192 () ;
#ifdef F_183
V_260 |= ( V_264 ) ;
V_260 &= ~ ( V_265 | V_266 ) ;
#else
V_260 |= ( V_264 | V_266 ) ;
V_260 &= ~ ( V_265 ) ;
#endif
switch ( V_260 & 7 ) {
case 0 :
case 7 :
break;
default:
V_260 |= ( V_267 ) ;
}
F_193 ( V_260 ) ;
V_197 |= ( V_261 | V_262 ) ;
V_197 |= ( V_268 ) ;
F_161 ( V_197 ) ;
}
static void T_7 F_194 ( void )
{
V_188 = L_34 ;
V_204 = V_269 ;
F_166 ( F_65 , F_175 , V_207 ) ;
F_166 ( F_82 , F_177 , V_207 ) ;
F_166 ( V_214 , F_179 , V_207 ) ;
F_166 ( V_212 , F_178 , V_207 ) ;
F_166 ( F_66 , F_187 , V_207 ) ;
F_166 ( F_83 , F_188 , V_207 ) ;
F_166 ( V_220 , F_190 , V_207 ) ;
F_166 ( V_218 , F_189 , V_207 ) ;
F_166 ( F_93 , F_182 , V_207 ) ;
F_166 ( V_223 , F_185 , V_227 ) ;
F_166 ( V_225 , F_186 , V_207 ) ;
F_144 = F_191 ;
}
static void T_10 F_195 ( void )
{
unsigned long V_197 = F_159 () ;
F_196 () ;
F_197 () ;
V_197 &= ~ V_270 ;
V_197 |= ( V_271 | V_272 ) ;
F_161 ( V_197 ) ;
}
static void T_7 F_198 ( void )
{
V_188 = L_35 ;
V_204 = V_273 ;
F_166 ( F_65 , V_274 , V_207 ) ;
F_166 ( F_82 , V_275 , V_207 ) ;
F_166 ( V_214 , V_276 , V_207 ) ;
F_166 ( V_212 , V_277 , V_207 ) ;
F_166 ( F_66 , V_278 , V_207 ) ;
F_166 ( F_83 , V_279 , V_207 ) ;
F_166 ( V_220 , V_280 , V_207 ) ;
F_166 ( V_218 , V_281 , V_207 ) ;
F_166 ( F_93 , V_282 , V_227 ) ;
F_166 ( V_223 , V_283 , V_207 ) ;
F_166 ( V_225 , V_284 , V_207 ) ;
F_144 = F_195 ;
F_199 () ;
}
static void T_10 F_200 ( void )
{
unsigned long V_197 = F_159 () ;
static int V_285 ;
if( V_286 ) {
unsigned long V_287 = F_201 () ;
V_287 |= ( V_288 | V_289 | V_290 ) ;
V_287 &= ~ ( V_291 ) ;
F_202 ( V_287 ) ;
V_197 |= V_292 ;
} else {
unsigned long V_293 ;
V_197 &= ~ ( V_292 ) ;
if( V_285 ++ ) {
V_293 = F_203 () ;
V_293 &= ~ ( V_294 ) ;
F_204 ( V_293 ) ;
F_205 () ;
}
}
V_197 |= V_295 ;
V_197 |= ( V_296 | V_297 ) ;
V_197 |= V_298 ;
V_197 &= ~ ( V_299 ) ;
F_161 ( V_197 ) ;
}
static void T_7 F_206 ( void )
{
unsigned long V_197 = F_159 () ;
if( V_197 & V_300 ) {
V_188 = L_36 ;
V_286 = 0 ;
F_205 () ;
F_166 ( V_206 , F_15 , V_207 ) ;
F_166 ( V_208 , F_20 , V_207 ) ;
F_166 ( V_209 , F_24 , V_207 ) ;
F_166 ( V_225 , V_301 , V_207 ) ;
V_257 = 0 ;
} else {
V_188 = L_37 ;
V_286 = 1 ;
V_71 = 1 ;
F_166 ( V_225 , V_302 , V_227 ) ;
}
F_166 ( F_65 , V_303 , V_207 ) ;
F_166 ( F_82 , V_304 , V_207 ) ;
F_166 ( V_214 , V_305 , V_207 ) ;
F_166 ( V_212 , V_306 , V_207 ) ;
#ifdef F_142
if ( V_95 == V_162 ) {
F_166 ( F_66 , V_307 , V_207 ) ;
F_166 ( F_83 , V_308 , V_207 ) ;
F_166 ( V_220 , V_309 , V_207 ) ;
F_166 ( V_218 , V_310 , V_207 ) ;
} else
#endif
{
F_166 ( F_66 , V_311 , V_207 ) ;
F_166 ( F_83 , V_312 , V_207 ) ;
F_166 ( V_220 , V_313 , V_207 ) ;
F_166 ( V_218 , V_314 , V_207 ) ;
}
F_166 ( F_93 , V_315 , V_227 ) ;
F_166 ( V_223 , V_316 , V_227 ) ;
F_144 = F_200 ;
}
void T_7 F_207 ( void )
{
}
void T_7 F_208 ( void )
{
V_188 = L_38 ;
F_166 ( F_65 , V_317 ,
V_207 ) ;
F_166 ( F_82 , V_317 ,
V_207 ) ;
F_166 ( V_214 , V_318 ,
V_207 ) ;
F_166 ( V_212 , V_317 ,
V_207 ) ;
F_166 ( V_225 , V_319 ,
V_207 ) ;
F_166 ( F_66 , V_320 , V_207 ) ;
F_166 ( F_83 , V_320 , V_207 ) ;
F_166 ( V_220 , V_320 , V_207 ) ;
F_166 ( V_218 , V_320 , V_207 ) ;
F_166 ( F_93 , V_317 ,
V_227 ) ;
F_166 ( V_223 , V_317 , V_227 ) ;
F_144 = F_207 ;
V_71 = 0 ;
V_321 = F_209 () ;
}
static void T_7 F_210 ( void )
{
unsigned long V_197 , V_322 ;
unsigned long V_323 , V_324 , V_325 , V_326 ;
V_204 = V_327 ;
V_233 = 0 ;
V_197 = F_159 () ; V_322 = F_211 () ;
V_323 = ( V_197 & 0xf0000000 ) >> 28 ;
V_324 = ( V_197 & 0x0f000000 ) >> 24 ;
V_325 = ( V_322 >> 28 ) & 0xf ;
V_326 = ( V_322 >> 24 ) & 0xf ;
if ( V_95 == V_96 ) {
F_208 () ;
return;
}
if( V_323 == 1 ) {
switch( V_324 ) {
case 7 :
F_165 () ;
break;
case 0 :
case 2 :
F_170 () ;
break;
case 10 :
case 11 :
case 12 :
case 13 :
case 14 :
case 15 :
F_171 ( V_324 ) ;
break;
default:
F_171 ( V_324 ) ;
break;
}
return;
}
if ( V_325 == 0 && V_326 == 5 ) {
F_194 () ;
return;
}
if( V_325 == 0 && V_326 == 4 ) {
T_9 V_157 ;
char V_158 [ 128 ] ;
V_157 = F_136 ( V_164 ) ;
while( ( V_157 = F_139 ( V_157 ) ) != 0 ) {
F_137 ( V_157 , L_14 , V_158 , sizeof( V_158 ) ) ;
if( ! strcmp ( V_158 , L_15 ) ) {
if ( ! F_138 ( V_157 , L_39 , 1 ) &&
F_138 ( V_157 , L_40 , 1 ) == 5 ) {
F_194 () ;
return;
}
break;
}
}
F_174 () ;
return;
}
if( V_325 == 4 &&
( ( V_326 == 0 ) ||
( ( V_326 == 1 ) && ( V_323 == 0 ) && ( V_324 == 0 ) ) ) ) {
F_206 () ;
return;
}
if( V_325 == 4 && V_326 == 1 && ( V_323 || V_324 ) ) {
F_198 () ;
return;
}
F_154 () ;
}
static void F_212 ( int V_328 , int V_329 )
{
}
static void T_7 F_213 ( void )
{
unsigned long * V_330 , * V_331 ;
F_214 ( V_332 , V_333 ) ;
F_214 ( V_334 , V_335 ) ;
F_214 ( V_336 , V_337 ) ;
F_214 ( V_338 , V_339 ) ;
F_214 ( V_340 [ V_341 ] . V_342 , V_343 ) ;
F_214 ( V_340 [ V_344 ] . V_342 , V_343 ) ;
F_214 ( V_340 [ V_345 ] . V_342 , V_343 ) ;
}
static void F_215 ( unsigned long V_9 )
{
F_216 ( ( V_346 ) F_217 ( V_347 ) , V_9 ) ;
V_347 ( V_9 ) ;
}
static T_1 F_218 ( unsigned long V_348 )
{
return F_16 ( ( V_348 << V_349 ) | V_350 ) ;
}
static unsigned long F_219 ( T_1 V_6 )
{
return F_3 ( V_6 ) >> V_349 ;
}
static T_4 F_220 ( T_4 V_351 )
{
V_351 &= ~ F_221 ( V_72 ) ;
return V_351 ;
}
void T_7 F_222 ( void )
{
extern void V_352 ( void ) ;
extern void V_353 ( void ) ;
extern void V_354 ( void ) ;
F_134 ( V_355 , V_34 ) ;
F_223 ( V_356 , V_140 ) ;
F_223 ( V_357 , V_134 ) ;
F_134 ( V_358 , V_359 ) ;
F_134 ( V_360 , V_361 ) ;
F_224 ( V_362 , F_33 ( V_363 ) ) ;
V_364 = F_33 ( V_365 ) ;
F_224 ( V_366 , F_33 ( V_367 ) ) ;
F_224 ( V_368 , F_33 ( V_369 ) ) ;
F_224 ( V_370 , F_33 ( V_371 ) ) ;
V_370 = F_33 ( V_371 ) ;
F_166 ( V_372 , F_220 , V_207 ) ;
#ifndef F_142
F_166 ( V_373 , V_354 , V_374 ) ;
#endif
F_166 ( V_375 , F_212 , V_227 ) ;
F_166 ( V_376 , F_2 , V_377 ) ;
F_166 ( V_378 , F_86 , V_207 ) ;
F_166 ( V_379 , F_5 , V_207 ) ;
F_166 ( V_380 , F_6 , V_207 ) ;
F_166 ( V_381 , F_10 , V_207 ) ;
F_166 ( V_382 , F_14 , V_207 ) ;
F_166 ( V_206 , F_15 , V_383 ) ;
F_166 ( V_384 , F_18 , V_207 ) ;
F_166 ( V_385 , F_19 , V_207 ) ;
F_166 ( V_208 , F_20 , V_383 ) ;
F_166 ( V_386 , F_21 , V_207 ) ;
F_166 ( V_387 , F_22 , V_207 ) ;
F_166 ( V_388 , F_23 , V_207 ) ;
F_166 ( V_209 , F_24 , V_383 ) ;
F_166 ( V_389 , F_31 , V_207 ) ;
F_166 ( V_390 , F_34 , V_207 ) ;
F_166 ( V_391 , F_35 , V_207 ) ;
F_166 ( V_392 , F_38 , V_207 ) ;
F_166 ( V_393 , F_39 , V_207 ) ;
F_166 ( V_394 , F_40 , V_207 ) ;
F_224 ( V_395 , V_30 ) ;
F_166 ( V_396 , F_43 , V_207 ) ;
F_166 ( V_397 , F_44 , V_207 ) ;
F_166 ( V_398 , F_74 , V_207 ) ;
F_166 ( V_399 , F_75 , V_207 ) ;
F_166 ( V_400 , F_71 , V_207 ) ;
F_166 ( V_401 , F_72 , V_207 ) ;
F_166 ( V_402 , F_70 , V_207 ) ;
F_166 ( V_403 , F_69 , V_207 ) ;
F_166 ( V_404 , F_68 , V_207 ) ;
F_166 ( V_405 , F_67 , V_207 ) ;
F_225 ( V_406 , V_22 ) ;
F_225 ( V_407 , V_23 ) ;
F_225 ( V_408 , V_24 ) ;
F_225 ( V_409 , V_350 ) ;
F_225 ( V_410 , V_22 ) ;
F_225 ( V_411 , V_23 ) ;
F_225 ( V_412 , V_24 ) ;
F_166 ( V_413 , F_28 , F_226 ( V_22 ) ) ;
F_166 ( V_414 , F_29 , F_226 ( V_23 ) ) ;
F_166 ( V_415 , F_30 , F_226 ( V_24 ) ) ;
F_166 ( V_256 , F_152 , V_227 ) ;
F_166 ( V_416 , F_153 , V_207 ) ;
F_166 ( V_417 , F_94 , V_207 ) ;
F_166 ( V_418 , F_96 , V_207 ) ;
F_166 ( V_419 , F_45 , V_207 ) ;
F_166 ( V_420 , F_46 , V_207 ) ;
F_166 ( V_421 , F_47 , V_207 ) ;
F_166 ( V_422 , F_150 , V_207 ) ;
F_166 ( V_423 , F_97 , V_207 ) ;
F_166 ( V_424 , F_100 , V_207 ) ;
F_166 ( V_425 , F_219 , V_207 ) ;
F_166 ( V_426 , F_218 , V_207 ) ;
F_210 () ;
F_213 () ;
#ifdef F_142
F_227 ( V_427 , F_65 ) ;
F_227 ( V_428 , F_82 ) ;
F_227 ( V_429 , V_212 ) ;
F_227 ( V_430 , V_214 ) ;
F_227 ( F_143 , F_66 ) ;
F_227 ( V_431 , F_83 ) ;
F_227 ( V_432 , V_218 ) ;
F_227 ( V_433 , V_220 ) ;
F_227 ( V_434 , F_93 ) ;
F_227 ( V_435 , V_223 ) ;
F_227 ( V_347 , V_225 ) ;
F_166 ( F_65 , V_436 , V_207 ) ;
F_166 ( F_82 , V_437 , V_207 ) ;
F_166 ( V_212 , V_438 , V_207 ) ;
F_166 ( V_214 , V_439 , V_207 ) ;
if ( V_95 != V_162 &&
V_95 != V_96 ) {
F_166 ( F_66 , V_440 , V_207 ) ;
F_166 ( F_83 , V_441 , V_207 ) ;
F_166 ( V_218 , V_442 , V_207 ) ;
F_166 ( V_220 , V_443 , V_207 ) ;
}
F_166 ( F_93 , V_444 , V_207 ) ;
F_166 ( V_223 , V_445 , V_207 ) ;
F_166 ( V_225 , F_215 , V_207 ) ;
if ( F_144 == F_200 ) {
F_227 ( F_65 , V_427 ) ;
F_227 ( F_82 , V_428 ) ;
F_227 ( V_212 , V_429 ) ;
F_227 ( V_214 , V_430 ) ;
F_227 ( F_93 , V_434 ) ;
F_227 ( V_223 , V_435 ) ;
F_227 ( V_225 , V_347 ) ;
}
#endif
if ( V_95 == V_162 )
V_353 () ;
else
V_352 () ;
#ifdef F_142
if ( V_95 == V_162 )
F_228 () ;
else if ( V_95 == V_96 )
F_229 () ;
else
F_230 () ;
#endif
}
