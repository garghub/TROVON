void F_1 ( int line , const char * string , int V_1 )
{
if ( V_2 < V_3 ) {
V_4 [ V_2 ] . time = V_5 ;
V_4 [ V_2 ] . V_6 = * V_7 ;
V_4 [ V_2 ] . string = string ;
V_4 [ V_2 ] . V_1 = V_1 ;
V_2 ++ ;
}
}
static void F_2 ( struct V_8 * V_9 )
{
T_1 V_10 = V_9 -> V_11 . V_12 -> V_13 -> V_14 ;
int V_15 ;
if ( ( V_10 & V_16 ) == V_17 )
V_15 = 9 ;
else
V_15 = 10 ;
if ( V_10 & V_18 )
V_15 ++ ;
if ( V_10 & V_19 )
V_15 ++ ;
V_9 -> V_20 = ( ( V_15 * 1000000 ) / V_9 -> V_21 ) + 1 ;
V_9 -> V_22 = 4 * V_9 -> V_20 ;
if ( V_9 -> V_22 < V_23 )
V_9 -> V_22 = V_23 ;
}
static int
F_3 ( unsigned int V_24 )
{
static int V_25 [] = {
0 , 50 , 75 , 110 , 134 , 150 , 200 , 300 , 600 , 1200 , 1800 , 2400 ,
4800 , 9600 , 19200 , 38400 } ;
static int V_26 [] = {
0 , 57600 , 115200 , 230400 , 460800 , 921600 , 1843200 , 6250000 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( V_24 & V_27 )
return V_26 [ ( V_24 & V_28 ) & ~ V_27 ] ;
else
return V_25 [ V_24 & V_28 ] ;
}
static unsigned char
F_4 ( unsigned int V_24 )
{
char V_29 ;
static char V_25 [] = {
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 0 , 1 , 2 , - 1 , 3 , 4 , 5 , 6 , 7 } ;
static char V_26 [] = {
- 1 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 } ;
if ( V_24 & V_27 )
V_29 = V_26 [ ( V_24 & V_28 ) & ~ V_27 ] ;
else
V_29 = V_25 [ V_24 & V_28 ] ;
if ( V_29 < 0 ) {
F_5 ( V_30 L_1 , V_24 ) ;
V_29 = 5 ;
}
return V_29 | ( V_29 << 4 ) ;
}
static inline void
F_6 ( struct V_8 * V_9 , int V_31 )
{
#ifndef F_7
unsigned char V_32 = V_33 [ V_9 -> line ] . V_34 ;
#ifdef F_8
F_5 ( L_2 , V_9 -> line , V_31 , V_32 ) ;
F_5 ( L_3 ,
V_9 -> line , * V_33 [ V_9 -> line ] . V_35 ,
F_9 ( V_9 ) ) ;
#endif
{
unsigned long V_36 ;
F_10 ( V_36 ) ;
* V_33 [ V_9 -> line ] . V_35 &= ~ V_32 ;
* V_33 [ V_9 -> line ] . V_35 |= ( V_31 ? 0 : V_32 ) ;
* V_33 [ V_9 -> line ] . V_37 = * V_33 [ V_9 -> line ] . V_35 ;
F_11 ( V_36 ) ;
}
#ifdef F_8
F_5 ( L_4 ,
V_9 -> line , * V_33 [ V_9 -> line ] . V_35 ,
F_9 ( V_9 ) ) ;
#endif
#endif
}
static inline void
F_12 ( struct V_8 * V_9 , int V_31 )
{
#ifndef F_7
unsigned long V_36 ;
F_10 ( V_36 ) ;
V_9 -> V_38 &= ~ V_39 ;
V_9 -> V_38 |= ( V_31 ? 0 : V_39 ) ;
V_9 -> V_40 [ V_41 ] = V_9 -> V_38 ;
F_11 ( V_36 ) ;
#ifdef F_8
F_5 ( L_5 , V_9 -> line , V_31 ) ;
#endif
#endif
}
static inline void
F_13 ( struct V_8 * V_9 , int V_31 )
{
#ifndef F_7
{
unsigned char V_32 = V_33 [ V_9 -> line ] . V_42 ;
unsigned long V_36 ;
F_10 ( V_36 ) ;
* V_33 [ V_9 -> line ] . V_43 &= ~ V_32 ;
* V_33 [ V_9 -> line ] . V_43 |= ( V_31 ? 0 : V_32 ) ;
* V_33 [ V_9 -> line ] . V_44 = * V_33 [ V_9 -> line ] . V_43 ;
F_11 ( V_36 ) ;
}
#endif
}
static inline void
F_14 ( struct V_8 * V_9 , int V_31 )
{
#ifndef F_7
{
unsigned char V_32 = V_33 [ V_9 -> line ] . V_45 ;
unsigned long V_36 ;
F_10 ( V_36 ) ;
* V_33 [ V_9 -> line ] . V_46 &= ~ V_32 ;
* V_33 [ V_9 -> line ] . V_46 |= ( V_31 ? 0 : V_32 ) ;
* V_33 [ V_9 -> line ] . V_47 = * V_33 [ V_9 -> line ] . V_46 ;
F_11 ( V_36 ) ;
}
#endif
}
static inline void
F_15 ( struct V_8 * V_9 )
{
#ifndef F_7
V_9 -> V_40 [ V_41 ] =
( V_9 -> V_38 &= ~ F_16 ( V_48 , V_49 ) ) ;
#endif
}
static inline void
F_17 ( struct V_8 * V_9 )
{
#ifndef F_7
V_9 -> V_40 [ V_41 ] =
( V_9 -> V_38 |= F_16 ( V_48 , V_49 ) ) ;
#endif
}
static inline void
F_18 ( struct V_8 * V_9 )
{
#ifdef F_19
F_5 ( L_6 , V_9 -> line ) ;
#endif
F_20 ( F_21 ( V_9 -> line , L_7 , V_9 -> line ) ) ;
* V_50 = ( V_9 -> V_51 << 2 ) | ( V_9 -> V_51 << 3 ) ;
}
static inline void
F_22 ( struct V_8 * V_9 )
{
#ifdef F_19
F_5 ( L_8 , V_9 -> line ) ;
#endif
F_20 ( F_21 ( V_9 -> line , L_9 , V_9 -> line ) ) ;
* V_52 = ( V_9 -> V_51 << 2 ) | ( V_9 -> V_51 << 3 ) ;
}
static void F_23 ( struct V_8 * V_9 )
{
#ifdef F_19
F_5 ( L_10 , V_9 -> line ) ;
#endif
F_20 ( F_21 ( V_9 -> line , L_11 , V_9 -> line ) ) ;
* V_50 = V_9 -> V_51 ;
}
static void F_24 ( struct V_8 * V_9 )
{
#ifdef F_19
F_5 ( L_12 , V_9 -> line ) ;
#endif
F_20 ( F_21 ( V_9 -> line , L_13 , V_9 -> line ) ) ;
* V_52 = V_9 -> V_51 ;
}
static void F_25 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
F_10 ( V_36 ) ;
F_26 ( F_21 ( V_9 -> line , L_14 , V_9 -> line ) ) ;
if ( V_9 -> line == 0 ) {
if ( ( V_53 & F_16 ( V_54 , V_55 ) ) ==
F_27 ( V_54 , V_55 , V_56 ) ) {
V_53 &= ~ F_16 ( V_54 , V_55 ) ;
V_53 |= F_27 ( V_54 , V_55 , V_57 ) ;
}
} else if ( V_9 -> line == 1 ) {
if ( ( V_53 & F_16 ( V_54 , V_58 ) ) ==
F_27 ( V_54 , V_58 , V_59 ) ) {
V_53 &= ~ F_16 ( V_54 , V_58 ) ;
V_53 |= F_27 ( V_54 , V_58 , V_60 ) ;
}
} else if ( V_9 -> line == 2 ) {
if ( ( V_53 & F_16 ( V_54 , V_61 ) ) ==
F_27 ( V_54 , V_61 , V_62 ) ) {
V_53 &= ~ F_16 ( V_54 , V_61 ) ;
V_53 |= F_27 ( V_54 , V_61 , V_63 ) ;
}
} else if ( V_9 -> line == 3 ) {
if ( ( V_53 & F_16 ( V_54 , V_64 ) ) ==
F_27 ( V_54 , V_64 , V_65 ) ) {
V_53 &= ~ F_16 ( V_54 , V_64 ) ;
V_53 |= F_27 ( V_54 , V_64 , V_66 ) ;
}
}
* V_54 = V_53 ;
F_11 ( V_36 ) ;
}
static void F_28 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
F_10 ( V_36 ) ;
F_26 ( F_21 ( V_9 -> line , L_15 , V_9 -> line ) ) ;
if ( V_9 -> line == 0 ) {
V_53 &= ~ F_16 ( V_54 , V_55 ) ;
V_53 |= F_27 ( V_54 , V_55 , V_56 ) ;
} else if ( V_9 -> line == 1 ) {
V_53 &= ~ F_16 ( V_54 , V_58 ) ;
V_53 |= F_27 ( V_54 , V_58 , V_59 ) ;
} else if ( V_9 -> line == 2 ) {
V_53 &= ~ F_16 ( V_54 , V_61 ) ;
V_53 |= F_27 ( V_54 , V_61 , V_62 ) ;
} else if ( V_9 -> line == 3 ) {
V_53 &= ~ F_16 ( V_54 , V_64 ) ;
V_53 |= F_27 ( V_54 , V_64 , V_65 ) ;
}
* V_54 = V_53 ;
F_11 ( V_36 ) ;
}
static void F_29 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
F_10 ( V_36 ) ;
if ( V_9 -> line == 0 ) {
if ( ( V_53 & F_16 ( V_54 , V_67 ) ) ==
F_27 ( V_54 , V_67 , V_56 ) ) {
V_53 &= ~ F_16 ( V_54 , V_67 ) ;
V_53 |= F_27 ( V_54 , V_67 , V_57 ) ;
}
} else if ( V_9 -> line == 1 ) {
if ( ( V_53 & F_16 ( V_54 , V_68 ) ) ==
F_27 ( V_54 , V_68 , V_59 ) ) {
V_53 &= ~ F_16 ( V_54 , V_68 ) ;
V_53 |= F_27 ( V_54 , V_68 , V_60 ) ;
}
} else if ( V_9 -> line == 2 ) {
if ( ( V_53 & F_16 ( V_54 , V_69 ) ) ==
F_27 ( V_54 , V_69 , V_62 ) ) {
V_53 &= ~ F_16 ( V_54 , V_69 ) ;
V_53 |= F_27 ( V_54 , V_69 , V_63 ) ;
}
} else if ( V_9 -> line == 3 ) {
if ( ( V_53 & F_16 ( V_54 , V_70 ) ) ==
F_27 ( V_54 , V_70 , V_65 ) ) {
V_53 &= ~ F_16 ( V_54 , V_70 ) ;
V_53 |= F_27 ( V_54 , V_70 , V_66 ) ;
}
}
* V_54 = V_53 ;
F_11 ( V_36 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
F_10 ( V_36 ) ;
if ( V_9 -> line == 0 ) {
V_53 &= ~ F_16 ( V_54 , V_67 ) ;
V_53 |= F_27 ( V_54 , V_67 , V_56 ) ;
} else if ( V_9 -> line == 1 ) {
V_53 &= ~ F_16 ( V_54 , V_68 ) ;
V_53 |= F_27 ( V_54 , V_68 , V_59 ) ;
} else if ( V_9 -> line == 2 ) {
V_53 &= ~ F_16 ( V_54 , V_69 ) ;
V_53 |= F_27 ( V_54 , V_69 , V_62 ) ;
} else if ( V_9 -> line == 3 ) {
V_53 &= ~ F_16 ( V_54 , V_70 ) ;
V_53 |= F_27 ( V_54 , V_70 , V_65 ) ;
}
* V_54 = V_53 ;
F_11 ( V_36 ) ;
}
static inline void
F_31 ( struct V_8 * V_9 )
{
#ifdef F_19
F_5 ( L_16 , V_9 -> line ) ;
#endif
F_20 ( F_21 ( V_9 -> line , L_17 , V_9 -> line ) ) ;
* V_71 = ( 1U << ( 8 + 2 * V_9 -> line ) ) ;
}
static inline void
F_32 ( struct V_8 * V_9 )
{
#ifdef F_19
F_5 ( L_18 , V_9 -> line ) ;
F_5 ( L_19 ,
( 8 + 2 * V_9 -> line ) ,
( 1U << ( 8 + 2 * V_9 -> line ) ) ) ;
#endif
F_20 ( F_21 ( V_9 -> line , L_20 , V_9 -> line ) ) ;
* V_72 = ( 1U << ( 8 + 2 * V_9 -> line ) ) ;
}
static inline void
F_33 ( struct V_8 * V_9 )
{
#ifdef F_19
F_5 ( L_21 , V_9 -> line ) ;
#endif
F_20 ( F_21 ( V_9 -> line , L_22 , V_9 -> line ) ) ;
* V_71 = ( 1U << ( 8 + 1 + 2 * V_9 -> line ) ) ;
}
static inline void
F_34 ( struct V_8 * V_9 )
{
#ifdef F_19
F_5 ( L_23 , V_9 -> line ) ;
F_5 ( L_19 ,
( 8 + 1 + 2 * V_9 -> line ) ,
( 1U << ( 8 + 1 + 2 * V_9 -> line ) ) ) ;
#endif
F_35 ( F_21 ( V_9 -> line , L_24 , V_9 -> line ) ) ;
* V_72 = ( 1U << ( 8 + 1 + 2 * V_9 -> line ) ) ;
}
static inline void F_36 ( struct V_8 * V_9 )
{
if ( V_9 -> V_73 )
F_22 ( V_9 ) ;
else
F_32 ( V_9 ) ;
}
static inline void F_37 ( struct V_8 * V_9 )
{
if ( V_9 -> V_73 )
F_18 ( V_9 ) ;
else
F_31 ( V_9 ) ;
}
static int
F_38 ( struct V_74 * V_12 , struct V_75 * V_76 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#if F_39 ( V_78 )
* V_79 = V_80 |= ( 1 << V_81 ) ;
#endif
#if F_39 ( V_82 )
F_40 ( V_83 , V_84 ,
V_85 , 1 ) ;
#endif
#if F_39 ( V_86 )
F_40 ( V_83 , V_84 ,
V_87 , 1 ) ;
F_40 ( V_83 , V_84 ,
V_88 , 1 ) ;
#endif
V_9 -> V_89 = * V_76 ;
if ( V_9 -> V_89 . V_90 >= 1000 )
V_9 -> V_89 . V_90 = 1000 ;
return 0 ;
}
static int
F_41 ( struct V_74 * V_12 ,
const unsigned char * V_91 , int V_92 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
int V_93 = ( V_9 -> V_89 . V_36 ) & V_94 ;
V_9 -> V_89 . V_36 |= V_94 ;
V_92 = F_42 ( V_12 , V_91 , V_92 ) ;
if ( ! V_93 )
V_9 -> V_89 . V_36 &= ~ ( V_94 ) ;
return V_92 ;
}
static void F_43 ( unsigned long V_95 )
{
struct V_8 * V_9 = (struct V_8 * ) V_95 ;
V_96 [ V_9 -> line ] . V_97 = NULL ;
F_12 ( V_9 , ( V_9 -> V_89 . V_36 & V_98 ) ) ;
#if F_39 ( V_99 )
F_17 ( V_9 ) ;
F_36 ( V_9 ) ;
#endif
}
static void
F_44 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 ) {
unsigned long V_36 ;
unsigned long V_100 ;
F_10 ( V_36 ) ;
F_26 ( F_21 ( V_9 -> line , L_25 ,
F_45 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 , V_104 ) ) ) ;
V_100 = F_46 ( V_105 , V_106 ,
F_47 ( V_9 -> V_11 . V_12 ) ) ;
V_100 |= F_27 ( V_105 , V_107 , V_108 ) ;
if ( V_12 -> V_13 -> V_109 & V_110 ) {
V_100 |= F_27 ( V_105 , V_111 , V_112 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_113 ] ) = V_100 ;
F_11 ( V_36 ) ;
}
}
static void
F_48 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 ) {
unsigned long V_36 ;
unsigned long V_100 ;
F_10 ( V_36 ) ;
F_26 ( F_21 ( V_9 -> line , L_26 ,
F_45 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 , V_104 ) ) ) ;
V_100 = F_46 ( V_105 , V_106 , F_47 ( V_12 ) ) ;
V_100 |= F_27 ( V_105 , V_107 , V_112 ) ;
if ( V_12 -> V_13 -> V_109 & V_110 ) {
V_100 |= F_27 ( V_105 , V_111 , V_112 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_113 ] ) = V_100 ;
if ( ! V_9 -> V_114 &&
V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 && V_9 -> V_101 . V_91 )
F_34 ( V_9 ) ;
F_11 ( V_36 ) ;
}
}
static void F_49 ( struct V_8 * V_9 , int V_115 )
{
if ( V_9 -> V_115 & ( 1 << V_115 ) )
return;
V_9 -> V_115 |= 1 << V_115 ;
F_50 ( & V_9 -> V_116 ) ;
}
static void
F_51 ( struct V_8 * V_9 )
{
unsigned int V_117 , V_118 ;
struct V_119 * V_120 ;
#ifdef F_7
if ( V_9 -> V_101 . V_103 )
F_5 ( L_27 ) ;
if ( V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 ) {
F_52 ( V_9 -> V_101 . V_91 + V_9 -> V_101 . V_103 ,
F_45 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 ,
V_104 ) ) ;
V_9 -> V_101 . V_102 = V_9 -> V_101 . V_103 ;
V_9 -> V_121 = 0 ;
}
return;
#endif
* V_9 -> V_122 =
F_27 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_27 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
#ifdef F_19
if ( V_9 -> line == V_123 )
F_5 ( L_28 ) ;
#endif
if ( ! V_9 -> V_121 ) {
F_5 ( V_30 L_29 ) ;
return;
}
V_120 = & V_9 -> V_124 ;
if ( ! ( V_120 -> V_125 & V_126 ) ) {
V_118 = V_120 -> V_127 ;
} else
V_118 = V_120 -> V_128 ;
F_26 ( F_21 ( V_9 -> line , L_30 , V_118 ) ) ;
V_9 -> V_129 . V_130 += V_118 ;
V_9 -> V_101 . V_103 = ( V_9 -> V_101 . V_103 + V_118 ) & ( V_104 - 1 ) ;
if ( F_45 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 ,
V_104 ) < V_131 )
F_49 ( V_9 , V_132 ) ;
V_117 = F_53 ( V_9 -> V_101 . V_102 , V_9 -> V_101 . V_103 , V_104 ) ;
if ( V_117 >= 4 * V_131 )
V_117 = V_117 / 2 ;
if ( V_117 <= 0 ) {
V_9 -> V_121 = 0 ;
#if F_39 ( V_133 ) && F_39 ( V_134 )
if ( V_9 -> V_89 . V_36 & V_94 ) {
F_54 ( & V_96 [ V_9 -> line ] ,
F_43 ,
( unsigned long ) V_9 ,
V_9 -> V_20 * 2 ,
L_31 ) ;
}
#endif
return;
}
F_26 ( F_21 ( V_9 -> line , L_32 , V_117 ) ) ;
V_120 -> V_135 = V_136 | V_137 | V_138 ;
V_120 -> V_127 = V_117 ;
V_120 -> V_91 = F_55 ( V_9 -> V_101 . V_91 + V_9 -> V_101 . V_103 ) ;
V_120 -> V_125 = 0 ;
* V_9 -> V_139 = F_55 ( V_120 ) ;
* V_9 -> V_140 = F_27 ( V_141 , V_142 , V_143 ) ;
}
static void
F_56 ( struct V_8 * V_9 )
{
#if 0
if (info->line == SERIAL_DEBUG_LINE)
printk("x\n");
#endif
V_9 -> V_124 . V_127 = 0 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_121 = 1 ;
if ( V_9 -> V_114 )
F_51 ( V_9 ) ;
else
F_34 ( V_9 ) ;
}
static struct V_144 *
F_57 ( unsigned int V_145 )
{
struct V_144 * V_146 ;
if ( ! ( V_146 = F_58 ( sizeof *V_146 + V_145 , V_147 ) ) )
return NULL ;
V_146 -> V_148 = NULL ;
V_146 -> V_149 = 0 ;
V_146 -> error = V_150 ;
return V_146 ;
}
static void
F_59 ( struct V_8 * V_9 , struct V_144 * V_146 )
{
unsigned long V_36 ;
F_10 ( V_36 ) ;
if ( ! V_9 -> V_151 )
V_9 -> V_151 = V_146 ;
else
V_9 -> V_152 -> V_148 = V_146 ;
V_9 -> V_152 = V_146 ;
V_9 -> V_153 += V_146 -> V_149 ;
if ( V_9 -> V_153 > V_9 -> V_154 )
V_9 -> V_154 = V_9 -> V_153 ;
F_11 ( V_36 ) ;
}
static int
F_60 ( struct V_8 * V_9 , unsigned char V_95 , unsigned char V_155 )
{
struct V_144 * V_146 ;
if ( V_9 -> V_73 ) {
if ( ! ( V_146 = F_57 ( 4 ) ) )
return 0 ;
V_146 -> V_149 = 1 ;
V_146 -> error = V_155 ;
V_146 -> V_146 [ 0 ] = V_95 ;
F_59 ( V_9 , V_146 ) ;
V_9 -> V_129 . V_156 ++ ;
} else {
struct V_74 * V_12 = V_9 -> V_11 . V_12 ;
F_61 ( V_12 , V_95 , V_155 ) ;
V_9 -> V_129 . V_156 ++ ;
}
return 1 ;
}
static unsigned int F_62 ( struct V_8 * V_9 ,
struct V_119 * V_120 ,
unsigned int V_157 )
{
struct V_144 * V_146 = F_63 ( V_120 -> V_91 ) - sizeof *V_146 ;
if ( V_9 -> V_153 + V_157 > 65536 ) {
F_5 ( V_158
L_33 , V_159 , V_157 ) ;
return 0 ;
}
V_146 -> V_149 = V_157 ;
if ( V_9 -> V_160 == V_161 )
V_146 -> error = V_162 ;
V_9 -> V_160 = 0 ;
F_59 ( V_9 , V_146 ) ;
if ( ! ( V_146 = F_57 ( V_163 ) ) )
F_64 ( L_34 , V_159 ) ;
V_120 -> V_91 = F_55 ( V_146 -> V_146 ) ;
return V_157 ;
}
static unsigned int F_65 ( struct V_8 * V_9 )
{
struct V_119 * V_120 ;
unsigned int V_157 ;
unsigned int V_164 = 0 ;
while ( 1 )
{
V_120 = & V_9 -> V_165 [ V_9 -> V_166 ] ;
if ( V_120 == F_63 ( * V_9 -> V_167 ) )
break;
if ( ++ V_9 -> V_166 == V_168 )
V_9 -> V_166 = 0 ;
if ( ! ( V_120 -> V_125 & V_169 ) ) {
V_157 = V_120 -> V_127 ;
} else {
V_157 = V_120 -> V_128 ;
}
V_120 -> V_125 = 0 ;
F_26 ( DEBUG_LOG(info->line, L_35, recvl);
if (info->port.tty->stopped) {
unsigned char *buf = phys_to_virt(descr->buf);
DEBUG_LOG(info->line, L_36, buf[0]);
DEBUG_LOG(info->line, L_36, buf[1]);
DEBUG_LOG(info->line, L_36, buf[2]);
}
) ;
V_9 -> V_129 . V_156 += V_157 ;
V_164 += F_62 ( V_9 , V_120 , V_157 ) ;
}
return V_164 ;
}
static void F_66 ( struct V_8 * V_9 )
{
struct V_74 * V_12 ;
unsigned char V_170 ;
#ifdef F_7
return;
#endif
* V_9 -> V_171 =
F_27 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_27 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 )
return;
#ifdef F_67
if ( V_9 -> V_73 )
F_32 ( V_9 ) ;
#endif
if ( V_9 -> V_160 == V_172 )
F_60 ( V_9 , '\0' , V_162 ) ;
F_65 ( V_9 ) ;
V_170 = V_9 -> V_40 [ V_173 ] ;
if ( V_170 & F_16 ( V_174 , V_175 ) ) {
F_26 ( F_21 ( V_9 -> line , L_37 , V_170 ) ) ;
}
if ( V_170 & V_176 ) {
unsigned char V_95 = V_9 -> V_40 [ V_177 ] ;
F_68 ( V_178 [ V_9 -> line ] . V_179 ++ ) ;
F_21 ( V_9 -> line , L_38 ,
( ( V_170 & V_176 ) << 8 ) | V_95 ) ;
if ( V_170 & V_180 )
F_60 ( V_9 , V_95 , V_181 ) ;
else if ( V_170 & V_182 )
F_60 ( V_9 , V_95 , V_183 ) ;
else if ( V_170 & V_184 )
F_60 ( V_9 , V_95 , V_185 ) ;
}
F_69 ( V_9 , L_39 ) ;
* V_9 -> V_186 = F_27 ( V_141 , V_142 , V_187 ) ;
}
static int F_70 ( struct V_8 * V_9 )
{
struct V_119 * V_120 = V_9 -> V_165 ;
struct V_144 * V_146 ;
int V_188 ;
for ( V_188 = 0 ; V_188 < V_168 ; V_188 ++ ) {
if ( ! ( V_146 = F_57 ( V_163 ) ) )
F_64 ( L_34 , V_159 ) ;
V_120 [ V_188 ] . V_135 = V_136 ;
V_120 [ V_188 ] . V_91 = F_55 ( V_146 -> V_146 ) ;
V_120 [ V_188 ] . V_127 = V_163 ;
V_120 [ V_188 ] . V_128 = 0 ;
V_120 [ V_188 ] . V_125 = 0 ;
V_120 [ V_188 ] . V_148 = F_55 ( & V_120 [ V_188 + 1 ] ) ;
}
V_120 [ V_188 - 1 ] . V_148 = F_55 ( & V_120 [ 0 ] ) ;
V_9 -> V_166 = 0 ;
* V_9 -> V_189 = F_55 ( & V_120 [ V_9 -> V_166 ] ) ;
* V_9 -> V_186 = F_27 ( V_141 , V_142 , V_143 ) ;
return 1 ;
}
static void
F_71 ( struct V_8 * V_9 )
{
#ifdef F_7
return;
#endif
if ( V_9 -> V_73 ) {
* V_9 -> V_186 = F_27 ( V_141 , V_142 , V_190 ) ;
while ( F_72 ( V_141 , V_142 , * V_9 -> V_186 ) ==
F_73 ( V_141 , V_142 , V_190 ) ) ;
F_70 ( V_9 ) ;
}
}
static T_2
F_74 ( int V_51 , void * V_191 )
{
struct V_8 * V_9 ;
unsigned long V_192 ;
int V_188 ;
int V_193 = 0 ;
#ifdef F_7
{
const char * V_194 = L_40 ;
F_52 ( V_194 , strlen ( V_194 ) ) ;
}
return V_195 ;
#endif
V_192 = * V_196 ;
for ( V_188 = 0 ; V_188 < V_197 ; V_188 ++ ) {
V_9 = V_198 + V_188 ;
if ( ! V_9 -> V_199 || ! V_9 -> V_114 )
continue;
if ( V_192 & V_9 -> V_51 ) {
V_193 = 1 ;
F_35 ( F_21 ( V_9 -> line , L_41 , V_188 ) ) ;
F_68 ( V_178 [ V_9 -> line ] . V_200 ++ ) ;
V_9 -> V_201 = F_75 () ;
V_9 -> V_202 = V_5 ;
F_51 ( V_9 ) ;
}
}
return F_76 ( V_193 ) ;
}
static T_2
F_77 ( int V_51 , void * V_191 )
{
struct V_8 * V_9 ;
unsigned long V_192 ;
int V_188 ;
int V_193 = 0 ;
#ifdef F_7
{
const char * V_194 = L_42 ;
F_52 ( V_194 , strlen ( V_194 ) ) ;
}
return V_195 ;
#endif
V_192 = * V_196 ;
for ( V_188 = 0 ; V_188 < V_197 ; V_188 ++ ) {
V_9 = V_198 + V_188 ;
if ( ! V_9 -> V_199 || ! V_9 -> V_73 )
continue;
if ( V_192 & ( ( V_9 -> V_51 << 2 ) | ( V_9 -> V_51 << 3 ) ) ) {
V_193 = 1 ;
F_66 ( V_9 ) ;
}
}
return F_76 ( V_193 ) ;
}
static int F_78 ( struct V_8 * V_9 )
{
unsigned char V_170 = V_9 -> V_40 [ V_173 ] ;
if ( V_170 & V_176 ) {
F_21 ( V_9 -> line , L_43 ,
V_170 | ( V_9 -> line << 8 ) ) ;
return 0 ;
}
if ( V_170 & V_203 ) {
F_79 ( F_21 ( V_9 -> line , L_44 ,
V_170 | ( V_9 -> line << 8 ) ) ) ;
( void ) V_9 -> V_40 [ V_177 ] ;
V_9 -> V_204 = 0 ;
F_69 ( V_9 , L_45 ) ;
return 0 ;
}
if ( ! V_9 -> V_204 ) {
V_9 -> V_204 = 1 ;
F_68 ( V_178 [ V_9 -> line ] . V_205 ++ ) ;
F_79 ( F_21 ( V_9 -> line , L_46 , V_9 -> line ) ) ;
F_80 ( V_9 ) ;
}
return 1 ;
}
static void F_81 ( struct V_8 * V_9 )
{
struct V_74 * V_12 ;
struct V_144 * V_146 ;
unsigned long V_36 ;
F_10 ( V_36 ) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 ) {
F_11 ( V_36 ) ;
return;
}
while ( ( V_146 = V_9 -> V_151 ) != NULL ) {
unsigned int V_92 = V_146 -> V_149 ;
F_82 ( V_12 , V_146 -> V_146 , V_92 ) ;
V_9 -> V_153 -= V_92 ;
if ( V_92 == V_146 -> V_149 ) {
V_9 -> V_151 = V_146 -> V_148 ;
F_83 ( V_146 ) ;
} else {
V_146 -> V_149 -= V_92 ;
memmove ( V_146 -> V_146 , V_146 -> V_146 + V_92 , V_146 -> V_149 ) ;
V_146 -> error = V_150 ;
}
}
if ( ! V_9 -> V_151 )
V_9 -> V_152 = NULL ;
F_11 ( V_36 ) ;
F_84 ( V_12 ) ;
}
static void F_85 ( struct V_8 * V_9 )
{
F_81 ( V_9 ) ;
if ( V_9 -> V_151 )
F_86 ( V_9 , L_47 , 2000 ) ;
F_78 ( V_9 ) ;
}
static void F_87 ( unsigned long V_95 )
{
struct V_8 * V_9 = (struct V_8 * ) V_95 ;
V_206 [ V_9 -> line ] . V_97 = NULL ;
V_207 ++ ;
F_79 ( F_21 ( V_9 -> line , L_48 , V_9 -> line ) ) ;
F_79 ( F_21 ( V_9 -> line , L_49 , V_207 ) ) ;
F_85 ( V_9 ) ;
}
static void
F_88 ( unsigned long V_208 )
{
struct V_8 * V_9 ;
int V_188 ;
#ifdef F_7
return;
#endif
for ( V_188 = 0 ; V_188 < V_197 ; V_188 ++ ) {
V_9 = V_198 + V_188 ;
if ( V_9 -> V_73 )
F_85 ( V_9 ) ;
}
F_89 ( & V_209 , V_5 + V_210 ) ;
}
static
struct V_8 * F_90 ( struct V_8 * V_9 )
{
unsigned long V_211 ;
struct V_74 * V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 ) {
F_5 ( L_50 ) ;
return V_9 ;
}
V_211 = * ( ( unsigned long * ) & V_9 -> V_40 [ V_212 ] ) ;
V_213:
if ( V_211 & F_16 ( V_214 , V_175 ) ) {
F_26 ( F_21 ( V_9 -> line , L_51 , 0 ) ) ;
}
F_35 ( F_21 ( V_9 -> line , L_52 , F_72 ( V_214 , V_215 , V_211 ) ) ) ;
if ( V_211 & ( F_16 ( V_214 , V_216 ) |
F_16 ( V_214 , V_217 ) |
F_16 ( V_214 , V_218 ) ) ) {
V_9 -> V_219 = F_75 () ;
V_9 -> V_220 = V_5 ;
F_20 ( F_21 ( V_9 -> line , L_53 , V_211 ) ) ;
F_91 (
if (!log_int_trig1_pos) {
log_int_trig1_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
) ;
if ( ( ( V_211 & F_16 ( V_214 , V_215 ) ) == 0 ) &&
( V_211 & F_16 ( V_214 , V_216 ) ) ) {
if ( ! V_9 -> V_221 ) {
F_21 ( V_9 -> line , L_54 , 0 ) ;
}
if ( V_211 & F_16 ( V_214 , V_222 ) ) {
F_21 ( V_9 -> line , L_55 , 0 ) ;
V_9 -> V_160 = V_172 ;
}
V_9 -> V_221 ++ ;
} else {
if ( V_9 -> V_221 ) {
F_21 ( V_9 -> line , L_56 , V_9 -> V_221 ) ;
V_9 -> V_160 = V_172 ;
} else {
unsigned char V_95 = F_72 ( V_214 ,
V_215 , V_211 ) ;
char V_155 = V_150 ;
if ( V_9 -> V_160 == V_172 ) {
struct V_74 * V_12 = V_9 -> V_11 . V_12 ;
F_61 ( V_12 , 0 , V_155 ) ;
V_9 -> V_129 . V_156 ++ ;
}
if ( V_211 & F_16 ( V_214 , V_217 ) ) {
V_9 -> V_129 . V_223 ++ ;
V_155 = V_181 ;
} else if ( V_211 & F_16 ( V_214 , V_218 ) ) {
V_9 -> V_129 . V_218 ++ ;
V_155 = V_183 ;
} else if ( V_211 & F_16 ( V_214 , V_216 ) ) {
V_9 -> V_129 . V_224 ++ ;
V_155 = V_185 ;
}
F_61 ( V_12 , V_95 , V_155 ) ;
V_9 -> V_160 = 0 ;
}
V_9 -> V_221 = 0 ;
}
} else if ( V_211 & F_16 ( V_214 , V_225 ) ) {
F_91 (
if (!log_int_trig1_pos) {
if (log_int_pos >= log_int_size) {
log_int_pos = 0;
}
log_int_trig0_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
) ;
F_61 ( V_12 ,
F_72 ( V_214 , V_215 , V_211 ) ,
V_150 ) ;
} else {
F_21 ( V_9 -> line , L_57 , V_211 ) ;
}
V_9 -> V_129 . V_156 ++ ;
V_211 = * ( ( unsigned long * ) & V_9 -> V_40 [ V_212 ] ) ;
if ( V_211 & F_16 ( V_214 , V_225 ) ) {
F_21 ( V_9 -> line , L_58 , F_72 ( V_214 , V_215 , V_211 ) ) ;
goto V_213;
}
F_84 ( V_9 -> V_11 . V_12 ) ;
return V_9 ;
}
static struct V_8 * F_92 ( struct V_8 * V_9 )
{
unsigned char V_170 ;
#ifdef F_19
F_5 ( L_59 , V_188 ) ;
#endif
if ( ! V_9 -> V_73 ) {
return F_90 ( V_9 ) ;
}
V_170 = V_9 -> V_40 [ V_173 ] ;
if ( V_170 & F_16 ( V_174 , V_175 ) ) {
F_26 ( F_21 ( V_9 -> line , L_51 , 0 ) ) ;
}
if ( V_170 & V_176 ) {
unsigned char V_95 ;
V_9 -> V_219 = F_75 () ;
V_9 -> V_220 = V_5 ;
V_95 = V_9 -> V_40 [ V_177 ] ;
F_20 ( F_21 ( V_9 -> line , L_60 , V_95 ) ) ;
F_20 ( F_21 ( V_9 -> line , L_61 , V_170 ) ) ;
if ( ! V_95 && ( V_170 & V_184 ) ) {
if ( ! V_9 -> V_221 ) {
F_21 ( V_9 -> line , L_54 , 0 ) ;
}
if ( V_170 & V_226 ) {
F_21 ( V_9 -> line , L_55 , 0 ) ;
V_9 -> V_160 = V_172 ;
}
V_9 -> V_221 ++ ;
} else {
if ( V_9 -> V_221 ) {
F_21 ( V_9 -> line , L_56 , V_9 -> V_221 ) ;
V_9 -> V_160 = V_172 ;
} else {
if ( V_9 -> V_160 == V_172 ) {
V_9 -> V_129 . V_227 ++ ;
F_60 ( V_9 , '\0' , V_162 ) ;
}
if ( V_170 & V_180 ) {
V_9 -> V_129 . V_223 ++ ;
F_60 ( V_9 , V_95 , V_181 ) ;
} else if ( V_170 & V_182 ) {
V_9 -> V_129 . V_218 ++ ;
F_60 ( V_9 , V_95 , V_183 ) ;
} else if ( V_170 & V_184 ) {
V_9 -> V_129 . V_224 ++ ;
F_60 ( V_9 , V_95 , V_185 ) ;
}
V_9 -> V_160 = 0 ;
}
V_9 -> V_221 = 0 ;
F_21 ( V_9 -> line , L_62 ,
( ( V_170 & V_176 ) << 8 ) | V_95 ) ;
}
F_68 ( V_178 [ V_9 -> line ] . V_228 ++ ) ;
} else {
unsigned long V_229 = F_75 () ;
unsigned long V_230 = V_5 ;
if ( V_9 -> V_221 ) {
long V_231 =
( V_230 - V_9 -> V_220 ) * ( 1000000 / V_232 ) +
V_229 - V_9 -> V_219 ;
if ( V_231 < 2 * V_9 -> V_20 ) {
F_21 ( V_9 -> line , L_63 , V_9 -> line ) ;
V_9 -> V_160 = V_161 ;
} else {
F_21 ( V_9 -> line , L_64 , V_9 -> line ) ;
}
F_21 ( V_9 -> line , L_65 , V_9 -> V_221 ) ;
}
#ifdef F_19
F_5 ( L_66 ) ;
#endif
F_31 ( V_9 ) ;
F_35 ( F_21 ( V_9 -> line , L_67 , V_9 -> line ) ) ;
V_9 -> V_221 = 0 ;
F_68 ( V_178 [ V_9 -> line ] . V_233 ++ ) ;
}
* V_9 -> V_186 = F_27 ( V_141 , V_142 , V_187 ) ;
F_69 ( V_9 , L_68 ) ;
return V_9 ;
}
static void F_93 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
if ( V_9 -> V_234 ) {
unsigned char V_170 ;
F_26 ( F_21 ( V_9 -> line , L_69 , V_9 -> V_234 ) ) ;
F_10 ( V_36 ) ;
V_170 = V_9 -> V_40 [ V_173 ] ;
F_26 ( F_21 ( V_9 -> line , L_70 , V_170 ) ) ;
V_9 -> V_40 [ V_235 ] = V_9 -> V_234 ;
V_9 -> V_129 . V_130 ++ ;
V_9 -> V_234 = 0 ;
F_34 ( V_9 ) ;
F_11 ( V_36 ) ;
return;
}
if ( V_9 -> V_114 ) {
unsigned char V_170 ;
int V_188 ;
F_26 ( F_21 ( V_9 -> line , L_71 , 0 ) ) ;
F_10 ( V_36 ) ;
V_170 = V_9 -> V_40 [ V_173 ] ;
F_26 ( F_21 ( V_9 -> line , L_70 , V_170 ) ) ;
F_33 ( V_9 ) ;
if ( V_9 -> V_11 . V_12 -> V_236 )
F_44 ( V_9 -> V_11 . V_12 ) ;
F_28 ( V_9 ) ;
for( V_188 = 6 ; V_188 > 0 ; V_188 -- )
F_94 () ;
* V_9 -> V_140 = F_27 (R_DMA_CH6_CMD, cmd, continue) ;
F_11 ( V_36 ) ;
return;
}
if ( V_9 -> V_101 . V_102 == V_9 -> V_101 . V_103
|| V_9 -> V_11 . V_12 -> V_236
|| V_9 -> V_11 . V_12 -> V_237 ) {
F_26 ( F_21 ( V_9 -> line , L_72 ,
V_9 -> V_11 . V_12 -> V_236 ) ) ;
F_33 ( V_9 ) ;
V_9 -> V_121 = 0 ;
return;
}
F_35 ( F_21 ( V_9 -> line , L_73 , V_9 -> V_101 . V_91 [ V_9 -> V_101 . V_103 ] ) ) ;
F_10 ( V_36 ) ;
V_9 -> V_40 [ V_235 ] = V_9 -> V_101 . V_91 [ V_9 -> V_101 . V_103 ] ;
V_9 -> V_101 . V_103 = ( V_9 -> V_101 . V_103 + 1 ) & ( V_104 - 1 ) ;
V_9 -> V_129 . V_130 ++ ;
if ( V_9 -> V_101 . V_102 == V_9 -> V_101 . V_103 ) {
#if F_39 ( V_133 ) && F_39 ( V_134 )
if ( V_9 -> V_89 . V_36 & V_94 ) {
F_54 ( & V_96 [ V_9 -> line ] ,
F_43 ,
( unsigned long ) V_9 ,
V_9 -> V_20 * 2 ,
L_31 ) ;
}
#endif
V_9 -> V_201 = F_75 () ;
V_9 -> V_202 = V_5 ;
F_33 ( V_9 ) ;
V_9 -> V_121 = 0 ;
F_26 ( F_21 ( V_9 -> line , L_74 , 0 ) ) ;
} else {
F_34 ( V_9 ) ;
}
F_11 ( V_36 ) ;
if ( F_45 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 ,
V_104 ) < V_131 )
F_49 ( V_9 , V_132 ) ;
}
static T_2
F_95 ( int V_51 , void * V_191 )
{
static volatile int V_238 = 0 ;
struct V_8 * V_9 ;
int V_188 ;
unsigned long V_36 ;
unsigned long V_239 ;
unsigned long V_240 = ( 1 << ( 8 + 2 * 0 ) ) ;
int V_193 = 0 ;
static volatile unsigned long V_241 = 0 ;
F_10 ( V_36 ) ;
V_239 = * V_242 ;
V_9 = V_198 ;
V_239 &= V_243 ;
for ( V_188 = 0 ; V_188 < V_197 ; V_188 ++ ) {
if ( V_239 & V_240 ) {
V_193 = 1 ;
F_92 ( V_9 ) ;
}
V_9 += 1 ;
V_240 <<= 2 ;
}
if ( ! V_238 ) {
unsigned long V_244 ;
unsigned long
V_238 = 1 ;
V_239 &= ( F_16 ( V_242 , V_245 ) |
F_16 ( V_242 , V_246 ) |
F_16 ( V_242 , V_247 ) |
F_16 ( V_242 , V_248 ) ) ;
while ( V_239 ) {
* V_71 = V_239 ;
* V_249 = F_27 ( V_249 , V_250 , V_31 ) ;
F_96 () ;
V_244 = ( 1 << ( 8 + 1 + 2 * 0 ) ) ;
V_9 = V_198 ;
for ( V_188 = 0 ; V_188 < V_197 ; V_188 ++ ) {
if ( V_239 & V_244 ) {
V_193 = 1 ;
F_93 ( V_9 ) ;
}
V_9 += 1 ;
V_244 <<= 2 ;
}
F_97 () ;
V_239 = V_241 ;
}
F_97 () ;
V_238 = 0 ;
} else {
unsigned long V_244 ;
V_244 = V_239 & ( F_16 ( V_242 , V_245 ) |
F_16 ( V_242 , V_246 ) |
F_16 ( V_242 , V_247 ) |
F_16 ( V_242 , V_248 ) ) ;
if ( V_244 ) {
V_241 |= V_244 ;
* V_71 = V_244 ;
F_26 ( F_21 ( V_123 , L_75 , V_244 ) ) ;
}
}
F_11 ( V_36 ) ;
return F_76 ( V_193 ) ;
}
static void
F_98 ( struct V_251 * V_116 )
{
struct V_8 * V_9 ;
struct V_74 * V_12 ;
V_9 = F_99 ( V_116 , struct V_8 , V_116 ) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 )
return;
if ( F_100 ( V_132 , & V_9 -> V_115 ) )
F_101 ( V_12 ) ;
}
static int
F_102 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
unsigned long V_252 ;
int V_188 ;
V_252 = F_103 ( V_253 ) ;
if ( ! V_252 )
return - V_254 ;
F_10 ( V_36 ) ;
if ( V_9 -> V_36 & V_255 ) {
F_11 ( V_36 ) ;
F_104 ( V_252 ) ;
return 0 ;
}
if ( V_9 -> V_101 . V_91 )
F_104 ( V_252 ) ;
else
V_9 -> V_101 . V_91 = ( unsigned char * ) V_252 ;
#ifdef F_105
F_5 ( L_76 , V_9 -> line , V_9 -> V_101 . V_91 ) ;
#endif
#ifdef F_7
if ( V_9 -> V_11 . V_12 )
F_106 ( V_256 , & V_9 -> V_11 . V_12 -> V_36 ) ;
V_9 -> V_101 . V_102 = V_9 -> V_101 . V_103 = 0 ;
V_9 -> V_151 = V_9 -> V_152 = NULL ;
V_9 -> V_153 = V_9 -> V_154 = 0 ;
for ( V_188 = 0 ; V_188 < V_168 ; V_188 ++ )
V_9 -> V_165 [ V_188 ] . V_91 = NULL ;
F_107 ( V_9 ) ;
#else
if ( V_9 -> V_257 ) {
V_9 -> V_73 = 1 ;
F_30 ( V_9 ) ;
* V_9 -> V_186 = F_27 ( V_141 , V_142 , V_190 ) ;
while ( F_72 ( V_141 , V_142 , * V_9 -> V_186 ) ==
F_73 ( V_141 , V_142 , V_190 ) ) ;
* V_9 -> V_171 =
F_27 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_27 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
} else {
F_29 ( V_9 ) ;
}
if ( V_9 -> V_258 ) {
V_9 -> V_114 = 1 ;
F_28 ( V_9 ) ;
* V_9 -> V_140 = F_27 ( V_141 , V_142 , V_190 ) ;
while ( F_72 ( V_141 , V_142 , * V_9 -> V_140 ) ==
F_73 ( V_141 , V_142 , V_190 ) ) ;
* V_9 -> V_122 =
F_27 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_27 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
} else {
F_25 ( V_9 ) ;
}
if ( V_9 -> V_11 . V_12 )
F_106 ( V_256 , & V_9 -> V_11 . V_12 -> V_36 ) ;
V_9 -> V_101 . V_102 = V_9 -> V_101 . V_103 = 0 ;
V_9 -> V_151 = V_9 -> V_152 = NULL ;
V_9 -> V_153 = V_9 -> V_154 = 0 ;
for ( V_188 = 0 ; V_188 < V_168 ; V_188 ++ )
V_9 -> V_165 [ V_188 ] . V_91 = 0 ;
#ifdef F_67
F_32 ( V_9 ) ;
#endif
F_107 ( V_9 ) ;
( void ) V_9 -> V_40 [ V_177 ] ;
if ( V_9 -> V_114 )
F_24 ( V_9 ) ;
F_36 ( V_9 ) ;
V_9 -> V_121 = 0 ;
F_71 ( V_9 ) ;
V_9 -> V_124 . V_127 = 0 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = 0 ;
F_12 ( V_9 , 1 ) ;
F_6 ( V_9 , 1 ) ;
#endif
V_9 -> V_36 |= V_255 ;
F_11 ( V_36 ) ;
return 0 ;
}
static void
F_108 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
struct V_119 * V_120 = V_9 -> V_165 ;
struct V_144 * V_146 ;
int V_188 ;
#ifndef F_7
F_26 ( F_21 ( V_9 -> line , L_77 , V_9 -> line ) ) ;
F_15 ( V_9 ) ;
V_9 -> V_40 [ V_259 ] = ( V_9 -> V_260 &= ~ 0x40 ) ;
if ( V_9 -> V_73 ) {
F_18 ( V_9 ) ;
* V_9 -> V_186 = F_27 ( V_141 , V_142 , V_190 ) ;
V_9 -> V_73 = 0 ;
} else {
F_31 ( V_9 ) ;
}
if ( V_9 -> V_114 ) {
F_23 ( V_9 ) ;
V_9 -> V_121 = 0 ;
* V_9 -> V_140 = F_27 ( V_141 , V_142 , V_190 ) ;
V_9 -> V_114 = 0 ;
} else {
F_33 ( V_9 ) ;
V_9 -> V_121 = 0 ;
}
#endif
if ( ! ( V_9 -> V_36 & V_255 ) )
return;
#ifdef F_105
F_5 ( L_78 , V_9 -> line ,
V_9 -> V_51 ) ;
#endif
F_10 ( V_36 ) ;
if ( V_9 -> V_101 . V_91 ) {
F_104 ( ( unsigned long ) V_9 -> V_101 . V_91 ) ;
V_9 -> V_101 . V_91 = NULL ;
}
for ( V_188 = 0 ; V_188 < V_168 ; V_188 ++ )
if ( V_120 [ V_188 ] . V_91 ) {
V_146 = F_63 ( V_120 [ V_188 ] . V_91 ) - sizeof *V_146 ;
F_83 ( V_146 ) ;
V_120 [ V_188 ] . V_91 = 0 ;
}
if ( ! V_9 -> V_11 . V_12 || ( V_9 -> V_11 . V_12 -> V_13 -> V_14 & V_261 ) ) {
F_6 ( V_9 , 0 ) ;
F_12 ( V_9 , 0 ) ;
}
if ( V_9 -> V_11 . V_12 )
F_109 ( V_256 , & V_9 -> V_11 . V_12 -> V_36 ) ;
V_9 -> V_36 &= ~ V_255 ;
F_11 ( V_36 ) ;
}
static void
F_107 ( struct V_8 * V_9 )
{
unsigned int V_24 ;
unsigned long V_100 ;
unsigned long V_36 ;
if ( ! V_9 -> V_11 . V_12 || ! V_9 -> V_11 . V_12 -> V_13 )
return;
if ( ! V_9 -> V_40 )
return;
V_24 = V_9 -> V_11 . V_12 -> V_13 -> V_14 ;
if ( ( V_9 -> V_36 & V_262 ) == V_263 ) {
T_3 V_32 = 0xFF << ( V_9 -> line * 8 ) ;
unsigned long V_264 =
F_27 ( V_265 , V_266 , V_267 ) |
F_27 ( V_265 , V_268 , V_267 ) ;
F_110 ( F_5 ( L_79 ,
( unsigned long ) V_9 -> V_269 , V_9 -> V_270 ) ) ;
if ( V_9 -> V_269 == V_271 ) {
T_4 V_272 = V_9 -> V_270 ;
V_264 =
F_27 ( V_265 , V_266 , V_273 ) |
F_27 ( V_265 , V_268 , V_273 ) ;
V_264 = 0x11 ;
F_110 ( F_5 ( L_80 , V_272 ) ) ;
* V_274 = V_272 ;
V_9 -> V_21 = V_271 / V_272 ;
}
#ifdef F_111
else if ( ( V_9 -> V_269 == V_275 / 8 &&
V_9 -> V_270 == 1 ) ||
( V_9 -> V_269 == V_275 &&
V_9 -> V_270 == 8 ) ) {
V_264 =
F_27 ( V_265 , V_266 , extern ) |
F_27 ( V_265 , V_268 , extern ) ;
F_110 ( F_5 ( L_81 , V_275 / 8 ) ) ;
V_9 -> V_21 = V_275 / 8 ;
}
#endif
else
{
F_5 ( V_30 L_82 ,
( unsigned long ) V_9 -> V_269 , V_9 -> V_270 ) ;
}
V_276 &= ~ V_32 ;
V_276 |= ( V_264 << ( V_9 -> line * 8 ) ) ;
* V_265 = V_276 ;
} else {
T_3 V_32 = 0xFF << ( V_9 -> line * 8 ) ;
unsigned long V_264 =
F_27 ( V_265 , V_266 , V_267 ) |
F_27 ( V_265 , V_268 , V_267 ) ;
V_276 &= ~ V_32 ;
V_276 |= ( V_264 << ( V_9 -> line * 8 ) ) ;
#ifndef F_7
* V_265 = V_276 ;
#endif
V_9 -> V_21 = F_3 ( V_24 ) ;
#ifndef F_7
V_9 -> V_40 [ V_277 ] = F_4 ( V_24 ) ;
#endif
}
#ifndef F_7
F_10 ( V_36 ) ;
V_9 -> V_38 &= ~ ( F_16 ( V_48 , V_278 ) |
F_16 ( V_48 , V_279 ) |
F_16 ( V_48 , V_280 ) ) ;
V_9 -> V_260 &= ~ ( F_16 ( V_281 , V_282 ) |
F_16 ( V_281 , V_283 ) |
F_16 ( V_281 , V_284 ) |
F_16 ( V_281 , V_285 ) |
F_16 ( V_281 , V_286 ) ) ;
if ( ( V_24 & V_16 ) == V_17 ) {
V_9 -> V_260 |= F_27 ( V_281 , V_282 , V_287 ) ;
V_9 -> V_38 |= F_27 ( V_48 , V_278 , V_288 ) ;
}
if ( V_24 & V_18 ) {
V_9 -> V_260 |= F_27 ( V_281 , V_285 , V_289 ) ;
}
if ( V_24 & V_19 ) {
V_9 -> V_260 |= F_27 ( V_281 , V_283 , V_112 ) ;
V_9 -> V_38 |= F_27 ( V_48 , V_279 , V_112 ) ;
}
if ( V_24 & V_290 ) {
V_9 -> V_260 |= F_27 ( V_281 , V_291 , V_292 ) ;
V_9 -> V_38 |= F_27 ( V_48 , V_293 , V_292 ) ;
}
if ( V_24 & V_294 ) {
V_9 -> V_260 |= F_27 ( V_281 , V_284 , V_295 ) ;
V_9 -> V_38 |= F_27 ( V_48 , V_280 , V_295 ) ;
}
if ( V_24 & V_296 ) {
F_26 ( F_21 ( V_9 -> line , L_83 , 0 ) ) ;
V_9 -> V_260 |= F_27 ( V_281 , V_286 , V_297 ) ;
}
V_9 -> V_260 |= F_27 ( V_281 , V_298 , V_112 ) ;
V_9 -> V_38 |= F_27 ( V_48 , V_49 , V_112 ) ;
V_9 -> V_40 [ V_259 ] = V_9 -> V_260 ;
V_9 -> V_40 [ V_41 ] = V_9 -> V_38 ;
V_100 = F_46 ( V_105 , V_106 , F_47 ( V_9 -> V_11 . V_12 ) ) ;
V_100 |= F_27 ( V_105 , V_107 , V_112 ) ;
if ( V_9 -> V_11 . V_12 -> V_13 -> V_109 & V_110 ) {
F_26 ( F_21 ( V_9 -> line , L_84 ,
F_47 ( V_9 -> V_11 . V_12 ) ) ) ;
V_100 |= F_27 ( V_105 , V_111 , V_112 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_113 ] ) = V_100 ;
F_11 ( V_36 ) ;
#endif
F_2 ( V_9 ) ;
}
static void
F_112 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( V_9 -> V_121 ||
V_9 -> V_101 . V_102 == V_9 -> V_101 . V_103 ||
V_12 -> V_236 ||
V_12 -> V_237 ||
! V_9 -> V_101 . V_91 )
return;
#ifdef F_113
F_5 ( L_85 ) ;
#endif
F_10 ( V_36 ) ;
F_56 ( V_9 ) ;
F_11 ( V_36 ) ;
}
static int F_114 ( struct V_74 * V_12 ,
const unsigned char * V_91 , int V_92 )
{
int V_117 , V_164 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_12 || ! V_9 -> V_101 . V_91 || ! V_299 )
return 0 ;
#ifdef F_115
if ( V_9 -> line == V_123 )
F_5 ( L_86 ,
V_92 , V_9 -> V_40 [ V_173 ] ) ;
#endif
#ifdef F_7
F_52 ( V_91 , V_92 ) ;
return V_92 ;
#endif
F_116 ( V_36 ) ;
F_26 ( F_21 ( V_9 -> line , L_87 , V_92 ) ) ;
F_26 ( F_21 ( V_9 -> line , L_88 , V_12 -> V_300 . V_301 ( V_12 ) ) ) ;
F_97 () ;
while ( V_92 ) {
V_117 = F_117 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 ,
V_104 ) ;
if ( V_92 < V_117 )
V_117 = V_92 ;
if ( V_117 <= 0 )
break;
memcpy ( V_9 -> V_101 . V_91 + V_9 -> V_101 . V_102 , V_91 , V_117 ) ;
V_9 -> V_101 . V_102 = ( V_9 -> V_101 . V_102 + V_117 ) &
( V_104 - 1 ) ;
V_91 += V_117 ;
V_92 -= V_117 ;
V_164 += V_117 ;
}
F_11 ( V_36 ) ;
F_26 ( F_21 ( V_9 -> line , L_89 , V_164 ) ) ;
if ( V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 &&
! V_12 -> V_236 &&
! V_12 -> V_237 &&
! V_9 -> V_121 ) {
F_56 ( V_9 ) ;
}
return V_164 ;
}
static int
F_42 ( struct V_74 * V_12 ,
const unsigned char * V_91 , int V_92 )
{
#if F_39 ( V_133 )
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 -> V_89 . V_36 & V_94 )
{
#ifdef V_134
V_96 [ V_9 -> line ] . V_97 = NULL ;
F_118 ( & V_96 [ V_9 -> line ] ) ;
#endif
F_12 ( V_9 , ( V_9 -> V_89 . V_36 & V_302 ) ) ;
#if F_39 ( V_99 )
F_15 ( V_9 ) ;
F_36 ( V_9 ) ;
#endif
if ( ( V_9 -> V_89 . V_36 & V_303 ) &&
( V_9 -> V_89 . V_90 > 0 ) )
F_119 ( V_9 -> V_89 . V_90 ) ;
}
#endif
V_92 = F_114 ( V_12 , V_91 , V_92 ) ;
#if F_39 ( V_133 )
if ( V_9 -> V_89 . V_36 & V_94 )
{
unsigned int V_304 ;
F_120 ( V_12 , 0 ) ;
#ifdef V_134
F_121 ( V_9 -> V_20 * 2 ) ;
#endif
do{
F_122 ( V_9 , & V_304 ) ;
}while ( ! ( V_304 & V_305 ) );
F_12 ( V_9 , ( V_9 -> V_89 . V_36 & V_98 ) ) ;
#if F_39 ( V_99 )
F_17 ( V_9 ) ;
F_22 ( V_9 ) ;
#endif
}
#endif
return V_92 ;
}
static int
F_123 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
return F_124 ( V_9 -> V_101 . V_102 , V_9 -> V_101 . V_103 , V_104 ) ;
}
static int
F_125 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
return F_45 ( V_9 -> V_101 . V_102 , V_9 -> V_101 . V_103 , V_104 ) ;
}
static void
F_126 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_10 ( V_36 ) ;
V_9 -> V_101 . V_102 = V_9 -> V_101 . V_103 = 0 ;
F_11 ( V_36 ) ;
F_101 ( V_12 ) ;
}
static void F_127 ( struct V_74 * V_12 , char V_306 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_10 ( V_36 ) ;
if ( V_9 -> V_114 ) {
* V_9 -> V_140 = F_27 ( V_141 , V_142 , V_307 ) ;
while ( F_72 ( V_141 , V_142 , * V_9 -> V_140 ) !=
F_73 ( V_141 , V_142 , V_307 ) ) ;
F_25 ( V_9 ) ;
}
if ( V_12 -> V_236 )
F_48 ( V_12 ) ;
F_26 ( F_21 ( V_9 -> line , L_90 , V_306 ) ) ;
V_9 -> V_234 = V_306 ;
F_34 ( V_9 ) ;
F_11 ( V_36 ) ;
}
static void
F_128 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#ifdef F_129
char V_91 [ 64 ] ;
F_5 ( L_91 , F_130 ( V_12 , V_91 ) ,
( unsigned long ) V_12 -> V_300 . V_301 ( V_12 ) ) ;
#endif
F_26 ( F_21 ( V_9 -> line , L_92 , V_12 -> V_300 . V_301 ( V_12 ) ) ) ;
if ( V_12 -> V_13 -> V_14 & V_296 ) {
F_12 ( V_9 , 0 ) ;
}
if ( F_131 ( V_12 ) )
F_127 ( V_12 , F_47 ( V_12 ) ) ;
}
static void
F_132 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#ifdef F_129
char V_91 [ 64 ] ;
F_5 ( L_93 , F_130 ( V_12 , V_91 ) ,
( unsigned long ) V_12 -> V_300 . V_301 ( V_12 ) ) ;
#endif
F_26 ( F_21 ( V_9 -> line , L_94 , V_12 -> V_300 . V_301 ( V_12 ) ) ) ;
F_26 ( F_21 ( V_9 -> line , L_95 , V_12 -> V_308 . V_92 ) ) ;
if ( V_12 -> V_13 -> V_14 & V_296 ) {
F_12 ( V_9 , 1 ) ;
}
if ( F_131 ( V_12 ) ) {
if ( V_9 -> V_234 )
V_9 -> V_234 = 0 ;
else
F_127 ( V_12 , F_133 ( V_12 ) ) ;
}
}
static int
F_134 ( struct V_8 * V_9 ,
struct V_309 * V_310 )
{
struct V_309 V_311 ;
if ( ! V_310 )
return - V_312 ;
memset ( & V_311 , 0 , sizeof( V_311 ) ) ;
V_311 . type = V_9 -> type ;
V_311 . line = V_9 -> line ;
V_311 . V_11 = ( int ) V_9 -> V_40 ;
V_311 . V_51 = V_9 -> V_51 ;
V_311 . V_36 = V_9 -> V_36 ;
V_311 . V_269 = V_9 -> V_269 ;
V_311 . V_313 = V_9 -> V_313 ;
V_311 . V_314 = V_9 -> V_314 ;
V_311 . V_270 = V_9 -> V_270 ;
if ( F_135 ( V_310 , & V_311 , sizeof( * V_310 ) ) )
return - V_312 ;
return 0 ;
}
static int
F_136 ( struct V_8 * V_9 ,
struct V_309 * V_315 )
{
struct V_309 V_316 ;
struct V_8 V_317 ;
int V_29 = 0 ;
if ( F_137 ( & V_316 , V_315 , sizeof( V_316 ) ) )
return - V_312 ;
V_317 = * V_9 ;
if ( ! F_138 ( V_318 ) ) {
if ( ( V_316 . type != V_9 -> type ) ||
( V_316 . V_313 != V_9 -> V_313 ) ||
( ( V_316 . V_36 & ~ V_319 ) !=
( V_9 -> V_36 & ~ V_319 ) ) )
return - V_320 ;
V_9 -> V_36 = ( ( V_9 -> V_36 & ~ V_319 ) |
( V_316 . V_36 & V_319 ) ) ;
goto V_321;
}
if ( V_9 -> V_92 > 1 )
return - V_322 ;
V_9 -> V_269 = V_316 . V_269 ;
V_9 -> V_36 = ( ( V_9 -> V_36 & ~ V_323 ) |
( V_316 . V_36 & V_323 ) ) ;
V_9 -> V_270 = V_316 . V_270 ;
V_9 -> type = V_316 . type ;
V_9 -> V_313 = V_316 . V_313 ;
V_9 -> V_314 = V_316 . V_314 ;
V_9 -> V_11 . V_12 -> V_324 = ( V_9 -> V_36 & V_325 ) ? 1 : 0 ;
V_321:
if ( V_9 -> V_36 & V_255 ) {
F_107 ( V_9 ) ;
} else
V_29 = F_102 ( V_9 ) ;
return V_29 ;
}
static int
F_122 ( struct V_8 * V_9 , unsigned int * V_1 )
{
unsigned int V_326 = V_305 ;
#ifndef F_7
unsigned long V_230 = V_5 ;
unsigned long V_327 = F_75 () ;
unsigned long V_231 =
( V_230 - V_9 -> V_202 ) * 1000000 / V_232 +
V_327 - V_9 -> V_201 ;
if ( V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 ||
V_231 < 2 * V_9 -> V_20 ) {
V_326 = 0 ;
}
#endif
if ( F_135 ( V_1 , & V_326 , sizeof( int ) ) )
return - V_312 ;
return 0 ;
}
char * F_139 ( int V_328 , char * V_194 )
{
int V_188 = 0 ;
V_194 [ 0 ] = '\0' ;
while ( V_329 [ V_188 ] . V_330 != NULL ) {
if ( V_328 & V_329 [ V_188 ] . V_331 ) {
if ( V_194 [ 0 ] != '\0' ) {
strcat ( V_194 , L_96 ) ;
}
strcat ( V_194 , V_329 [ V_188 ] . V_330 ) ;
}
V_188 ++ ;
}
return V_194 ;
}
static int
F_140 ( struct V_74 * V_12 , int V_332 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 -> V_40 )
return - V_333 ;
F_10 ( V_36 ) ;
if ( V_332 == - 1 ) {
V_9 -> V_260 &= 0x3F ;
} else {
V_9 -> V_260 |= ( 0x80 | 0x40 ) ;
}
V_9 -> V_40 [ V_259 ] = V_9 -> V_260 ;
F_11 ( V_36 ) ;
return 0 ;
}
static int
F_141 ( struct V_74 * V_12 , unsigned int V_31 , unsigned int V_334 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_10 ( V_36 ) ;
if ( V_334 & V_335 )
F_12 ( V_9 , 0 ) ;
if ( V_334 & V_336 )
F_6 ( V_9 , 0 ) ;
if ( V_334 & V_337 )
F_13 ( V_9 , 0 ) ;
if ( V_334 & V_338 )
F_14 ( V_9 , 0 ) ;
if ( V_31 & V_335 )
F_12 ( V_9 , 1 ) ;
if ( V_31 & V_336 )
F_6 ( V_9 , 1 ) ;
if ( V_31 & V_337 )
F_13 ( V_9 , 1 ) ;
if ( V_31 & V_338 )
F_14 ( V_9 , 1 ) ;
F_11 ( V_36 ) ;
return 0 ;
}
static int
F_142 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned int V_326 ;
unsigned long V_36 ;
F_10 ( V_36 ) ;
V_326 =
( ! F_143 ( V_9 ) ? V_335 : 0 )
| ( ! F_9 ( V_9 ) ? V_336 : 0 )
| ( ! F_144 ( V_9 ) ? V_339 : 0 )
| ( ! F_145 ( V_9 ) ? V_340 : 0 )
| ( ! F_146 ( V_9 ) ? V_341 : 0 )
| ( ! F_147 ( V_9 ) ? V_342 : 0 ) ;
F_11 ( V_36 ) ;
#ifdef F_8
F_5 ( V_343 L_97 ,
V_9 -> line , V_326 , V_326 ) ;
{
char V_194 [ 100 ] ;
F_139 ( V_326 , V_194 ) ;
F_5 ( V_343 L_98 , V_194 ) ;
}
#endif
return V_326 ;
}
static int
F_148 ( struct V_74 * V_12 ,
unsigned int V_142 , unsigned long V_344 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( ( V_142 != V_345 ) && ( V_142 != V_346 ) &&
( V_142 != V_347 ) && ( V_142 != V_348 ) &&
( V_142 != V_349 ) && ( V_142 != V_350 ) ) {
if ( V_12 -> V_36 & ( 1 << V_256 ) )
return - V_333 ;
}
switch ( V_142 ) {
case V_345 :
return F_134 ( V_9 ,
(struct V_309 * ) V_344 ) ;
case V_346 :
return F_136 ( V_9 ,
(struct V_309 * ) V_344 ) ;
case V_351 :
return F_122 ( V_9 , ( unsigned int * ) V_344 ) ;
case V_350 :
if ( F_135 ( (struct V_8 * ) V_344 ,
V_9 , sizeof( struct V_8 ) ) )
return - V_312 ;
return 0 ;
#if F_39 ( V_133 )
case V_352 :
{
struct V_353 V_354 ;
struct V_75 V_355 ;
F_5 ( V_343 L_99 ) ;
if ( F_137 ( & V_354 , (struct V_353 * ) V_344 ,
sizeof( V_354 ) ) )
return - V_312 ;
V_355 . V_90 = V_354 . V_90 ;
V_355 . V_36 = 0 ;
if ( V_355 . V_90 != 0 )
V_355 . V_36 |= V_303 ;
else
V_355 . V_36 &= ~ ( V_303 ) ;
if ( V_354 . V_199 )
V_355 . V_36 |= V_94 ;
else
V_355 . V_36 &= ~ ( V_94 ) ;
if ( V_354 . V_356 )
V_355 . V_36 |= V_302 ;
else
V_355 . V_36 &= ~ ( V_302 ) ;
if ( V_354 . V_357 )
V_355 . V_36 |= V_98 ;
else
V_355 . V_36 &= ~ ( V_98 ) ;
return F_38 ( V_12 , & V_355 ) ;
}
case V_358 :
{
struct V_75 V_355 ;
if ( F_137 ( & V_355 , (struct V_353 * ) V_344 ,
sizeof( V_355 ) ) )
return - V_312 ;
return F_38 ( V_12 , & V_355 ) ;
}
case V_359 :
{
struct V_75 * V_355 =
& ( ( (struct V_8 * ) V_12 -> V_77 ) -> V_89 ) ;
if ( F_135 ( (struct V_75 * ) V_344 ,
V_355 ,
sizeof( struct V_75 ) ) )
return - V_312 ;
break;
}
case V_360 :
{
struct V_361 V_362 ;
if ( F_137 ( & V_362 , (struct V_361 * ) V_344 ,
sizeof( V_362 ) ) )
return - V_312 ;
return F_41 ( V_12 , V_362 . V_363 , V_362 . V_364 ) ;
}
#endif
default:
return - V_365 ;
}
return 0 ;
}
static void
F_149 ( struct V_74 * V_12 , struct V_366 * V_367 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
F_107 ( V_9 ) ;
if ( ( V_367 -> V_14 & V_296 ) &&
! ( V_12 -> V_13 -> V_14 & V_296 ) ) {
V_12 -> V_237 = 0 ;
F_48 ( V_12 ) ;
}
}
static void
F_150 ( struct V_74 * V_12 , struct V_368 * V_369 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 )
return;
F_10 ( V_36 ) ;
if ( F_151 ( V_369 ) ) {
F_11 ( V_36 ) ;
return;
}
#ifdef F_105
F_5 ( L_100 , V_370 -> V_371 ,
V_9 -> line , V_9 -> V_92 ) ;
#endif
if ( ( V_12 -> V_92 == 1 ) && ( V_9 -> V_92 != 1 ) ) {
F_5 ( V_158
L_101
L_102 , V_9 -> V_92 ) ;
V_9 -> V_92 = 1 ;
}
if ( -- V_9 -> V_92 < 0 ) {
F_5 ( V_158 L_103 ,
V_9 -> line , V_9 -> V_92 ) ;
V_9 -> V_92 = 0 ;
}
if ( V_9 -> V_92 ) {
F_11 ( V_36 ) ;
return;
}
V_9 -> V_36 |= V_372 ;
if ( V_9 -> V_36 & V_373 )
V_9 -> V_374 = * V_12 -> V_13 ;
V_12 -> V_375 = 1 ;
if ( V_9 -> V_314 != V_376 )
F_120 ( V_12 , V_9 -> V_314 ) ;
#ifdef F_67
F_31 ( V_9 ) ;
#endif
#ifndef F_7
F_15 ( V_9 ) ;
F_37 ( V_9 ) ;
if ( V_9 -> V_36 & V_255 ) {
F_152 ( V_12 , V_232 ) ;
}
#endif
F_108 ( V_9 ) ;
F_126 ( V_12 ) ;
F_153 ( V_12 ) ;
V_12 -> V_375 = 0 ;
V_9 -> V_115 = 0 ;
V_9 -> V_11 . V_12 = NULL ;
if ( V_9 -> V_377 ) {
if ( V_9 -> V_313 )
F_154 ( V_9 -> V_313 ) ;
F_155 ( & V_9 -> V_378 ) ;
}
V_9 -> V_36 &= ~ ( V_373 | V_372 ) ;
F_155 ( & V_9 -> V_379 ) ;
F_11 ( V_36 ) ;
#if F_39 ( V_133 )
if ( V_9 -> V_89 . V_36 & V_94 ) {
V_9 -> V_89 . V_36 &= ~ ( V_94 ) ;
#if F_39 ( V_78 )
* V_79 = V_80 &= ~ ( 1 << V_81 ) ;
#endif
#if F_39 ( V_82 )
F_40 ( V_83 , V_84 ,
V_85 , 0 ) ;
#endif
#if F_39 ( V_86 )
F_40 ( V_83 , V_84 ,
V_87 , 0 ) ;
F_40 ( V_83 , V_84 ,
V_88 , 0 ) ;
#endif
}
#endif
if ( V_9 -> V_257 ) {
F_156 ( V_9 -> V_380 , V_9 ) ;
F_157 ( V_9 -> V_381 , V_9 -> V_382 ) ;
V_9 -> V_73 = 0 ;
#ifdef F_105
F_5 ( V_343 L_104 ,
V_9 -> V_382 ) ;
#endif
}
if ( V_9 -> V_258 ) {
F_156 ( V_9 -> V_383 , V_9 ) ;
F_157 ( V_9 -> V_384 , V_9 -> V_385 ) ;
V_9 -> V_114 = 0 ;
#ifdef F_105
F_5 ( V_343 L_104 ,
V_9 -> V_385 ) ;
#endif
}
}
static void F_152 ( struct V_74 * V_12 , int V_386 )
{
unsigned long V_387 ;
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_230 = V_5 ;
unsigned long V_327 = F_75 () ;
long V_231 =
( V_230 - V_9 -> V_202 ) * ( 1000000 / V_232 ) +
V_327 - V_9 -> V_201 ;
V_387 = V_5 ;
while ( V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 ||
( * V_9 -> V_388 & 0x007f ) ||
( V_231 < 2 * V_9 -> V_20 ) ) {
F_154 ( 1 ) ;
if ( F_158 ( V_370 ) )
break;
if ( V_386 && F_159 ( V_5 , V_387 + V_386 ) )
break;
V_230 = V_5 ;
V_327 = F_75 () ;
V_231 =
( V_230 - V_9 -> V_202 ) * ( 1000000 / V_232 ) +
V_327 - V_9 -> V_201 ;
}
F_160 ( V_389 ) ;
}
void
F_161 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
F_126 ( V_12 ) ;
F_108 ( V_9 ) ;
V_9 -> V_115 = 0 ;
V_9 -> V_92 = 0 ;
V_9 -> V_36 &= ~ V_373 ;
V_9 -> V_11 . V_12 = NULL ;
F_155 ( & V_9 -> V_378 ) ;
}
static int
F_162 ( struct V_74 * V_12 , struct V_368 * V_369 ,
struct V_8 * V_9 )
{
F_163 ( V_390 , V_370 ) ;
unsigned long V_36 ;
int V_29 ;
int V_391 = 0 , V_392 = 0 ;
if ( F_151 ( V_369 ) ||
( V_9 -> V_36 & V_372 ) ) {
F_164 ( V_9 -> V_379 ,
! ( V_9 -> V_36 & V_372 ) ) ;
#ifdef F_165
if ( V_9 -> V_36 & V_393 )
return - V_394 ;
else
return - V_395 ;
#else
return - V_394 ;
#endif
}
if ( ( V_369 -> V_396 & V_397 ) ||
( V_12 -> V_36 & ( 1 << V_256 ) ) ) {
V_9 -> V_36 |= V_373 ;
return 0 ;
}
if ( V_12 -> V_13 -> V_14 & V_398 ) {
V_391 = 1 ;
}
V_29 = 0 ;
F_166 ( & V_9 -> V_378 , & V_390 ) ;
#ifdef F_105
F_5 ( L_105 ,
V_9 -> line , V_9 -> V_92 ) ;
#endif
F_10 ( V_36 ) ;
if ( ! F_151 ( V_369 ) ) {
V_392 ++ ;
V_9 -> V_92 -- ;
}
F_11 ( V_36 ) ;
V_9 -> V_377 ++ ;
while ( 1 ) {
F_10 ( V_36 ) ;
F_12 ( V_9 , 1 ) ;
F_6 ( V_9 , 1 ) ;
F_11 ( V_36 ) ;
F_160 ( V_399 ) ;
if ( F_151 ( V_369 ) ||
! ( V_9 -> V_36 & V_255 ) ) {
#ifdef F_165
if ( V_9 -> V_36 & V_393 )
V_29 = - V_394 ;
else
V_29 = - V_395 ;
#else
V_29 = - V_394 ;
#endif
break;
}
if ( ! ( V_9 -> V_36 & V_372 ) && V_391 )
break;
if ( F_158 ( V_370 ) ) {
V_29 = - V_395 ;
break;
}
#ifdef F_105
F_5 ( L_106 ,
V_9 -> line , V_9 -> V_92 ) ;
#endif
F_167 () ;
F_168 () ;
F_169 () ;
}
F_160 ( V_389 ) ;
F_170 ( & V_9 -> V_378 , & V_390 ) ;
if ( V_392 )
V_9 -> V_92 ++ ;
V_9 -> V_377 -- ;
#ifdef F_105
F_5 ( L_107 ,
V_9 -> line , V_9 -> V_92 ) ;
#endif
if ( V_29 )
return V_29 ;
V_9 -> V_36 |= V_373 ;
return 0 ;
}
static void
F_171 ( struct V_8 * V_9 )
{
if ( V_9 -> V_258 ) {
F_157 ( V_9 -> V_384 , V_9 -> V_385 ) ;
F_156 ( V_9 -> V_383 , V_9 ) ;
}
if ( V_9 -> V_257 ) {
F_157 ( V_9 -> V_381 , V_9 -> V_382 ) ;
F_156 ( V_9 -> V_380 , V_9 ) ;
}
}
static int
F_172 ( struct V_74 * V_12 , struct V_368 * V_369 )
{
struct V_8 * V_9 ;
int V_29 , line ;
unsigned long V_400 ;
int V_401 = 0 ;
line = V_12 -> V_402 ;
if ( line < 0 || line >= V_197 )
return - V_403 ;
V_9 = V_198 + line ;
if ( ! V_9 -> V_199 )
return - V_403 ;
#ifdef F_105
F_5 ( L_108 , V_370 -> V_371 , V_12 -> V_404 ,
V_9 -> V_92 ) ;
#endif
V_9 -> V_92 ++ ;
V_12 -> V_77 = V_9 ;
V_9 -> V_11 . V_12 = V_12 ;
V_9 -> V_11 . V_12 -> V_324 = ( V_9 -> V_36 & V_325 ) ? 1 : 0 ;
if ( ! V_299 ) {
V_400 = F_103 ( V_253 ) ;
if ( ! V_400 ) {
return - V_254 ;
}
if ( V_299 )
F_104 ( V_400 ) ;
else
V_299 = ( unsigned char * ) V_400 ;
}
if ( F_151 ( V_369 ) ||
( V_9 -> V_36 & V_372 ) ) {
F_164 ( V_9 -> V_379 ,
! ( V_9 -> V_36 & V_372 ) ) ;
#ifdef F_165
return ( ( V_9 -> V_36 & V_393 ) ?
- V_394 : - V_395 ) ;
#else
return - V_394 ;
#endif
}
if ( V_9 -> V_92 == 1 ) {
V_401 = 1 ;
if ( V_9 -> V_257 ) {
if ( F_173 ( V_9 -> V_380 ,
F_77 ,
V_9 -> V_405 ,
V_9 -> V_382 ,
V_9 ) ) {
F_5 ( V_30 L_109
L_110 ,
V_9 -> V_382 ) ;
V_9 -> V_257 = 0 ;
} else if ( F_174 ( V_9 -> V_381 ,
V_9 -> V_382 ,
V_406 ,
V_9 -> V_407 ) ) {
F_156 ( V_9 -> V_380 , V_9 ) ;
F_5 ( V_30 L_111
L_110 ,
V_9 -> V_382 ) ;
V_9 -> V_257 = 0 ;
}
#ifdef F_105
else
F_5 ( V_343 L_112 ,
V_9 -> V_382 ) ;
#endif
}
if ( V_9 -> V_258 ) {
if ( F_173 ( V_9 -> V_383 ,
F_74 ,
V_9 -> V_408 ,
V_9 -> V_385 ,
V_9 ) ) {
F_5 ( V_30 L_109
L_110 ,
V_9 -> V_385 ) ;
V_9 -> V_258 = 0 ;
} else if ( F_174 ( V_9 -> V_384 ,
V_9 -> V_385 ,
V_406 ,
V_9 -> V_407 ) ) {
F_156 ( V_9 -> V_383 , V_9 ) ;
F_5 ( V_30 L_111
L_110 ,
V_9 -> V_385 ) ;
V_9 -> V_258 = 0 ;
}
#ifdef F_105
else
F_5 ( V_343 L_112 ,
V_9 -> V_385 ) ;
#endif
}
}
V_29 = F_102 ( V_9 ) ;
if ( V_29 ) {
if ( V_401 )
F_171 ( V_9 ) ;
return V_29 ;
}
V_29 = F_162 ( V_12 , V_369 , V_9 ) ;
if ( V_29 ) {
#ifdef F_105
F_5 ( L_113 ,
V_29 ) ;
#endif
if ( V_401 )
F_171 ( V_9 ) ;
return V_29 ;
}
if ( ( V_9 -> V_92 == 1 ) && ( V_9 -> V_36 & V_409 ) ) {
* V_12 -> V_13 = V_9 -> V_374 ;
F_107 ( V_9 ) ;
}
#ifdef F_105
F_5 ( L_114 , V_9 -> line ) ;
#endif
F_91 ( V_410 = 0 ) ;
F_175 ( if (info->line == SERIAL_DEBUG_LINE) {
info->icount.rx = 0;
} ) ;
return 0 ;
}
static void F_176 ( struct V_411 * V_412 , struct V_8 * V_9 )
{
unsigned long V_311 ;
F_177 ( V_412 , L_115 ,
V_9 -> line , ( unsigned long ) V_9 -> V_40 , V_9 -> V_51 ) ;
if ( ! V_9 -> V_40 || ( V_9 -> type == V_413 ) ) {
F_177 ( V_412 , L_116 ) ;
return;
}
F_177 ( V_412 , L_117 , V_9 -> V_21 ) ;
F_177 ( V_412 , L_118 ,
( unsigned long ) V_9 -> V_129 . V_130 ,
( unsigned long ) V_9 -> V_129 . V_156 ) ;
V_311 = F_45 ( V_9 -> V_101 . V_102 , V_9 -> V_101 . V_103 , V_104 ) ;
if ( V_311 )
F_177 ( V_412 , L_119 ,
( unsigned long ) V_311 ,
( unsigned long ) V_104 ) ;
F_177 ( V_412 , L_120 ,
( unsigned long ) V_9 -> V_153 ,
( unsigned long ) V_9 -> V_154 ) ;
#if 1
if ( V_9 -> V_11 . V_12 ) {
if ( V_9 -> V_11 . V_12 -> V_236 )
F_177 ( V_412 , L_121 ,
( int ) V_9 -> V_11 . V_12 -> V_236 ) ;
if ( V_9 -> V_11 . V_12 -> V_237 )
F_177 ( V_412 , L_122 ,
( int ) V_9 -> V_11 . V_12 -> V_237 ) ;
}
{
unsigned char V_170 = V_9 -> V_40 [ V_173 ] ;
if ( V_170 & F_16 ( V_174 , V_175 ) )
F_177 ( V_412 , L_123 ) ;
}
#endif
if ( V_9 -> V_129 . V_224 )
F_177 ( V_412 , L_124 , ( unsigned long ) V_9 -> V_129 . V_224 ) ;
if ( V_9 -> V_129 . V_223 )
F_177 ( V_412 , L_125 , ( unsigned long ) V_9 -> V_129 . V_223 ) ;
if ( V_9 -> V_129 . V_227 )
F_177 ( V_412 , L_126 , ( unsigned long ) V_9 -> V_129 . V_227 ) ;
if ( V_9 -> V_129 . V_218 )
F_177 ( V_412 , L_127 , ( unsigned long ) V_9 -> V_129 . V_218 ) ;
if ( ! F_143 ( V_9 ) )
F_178 ( V_412 , L_128 ) ;
if ( ! F_147 ( V_9 ) )
F_178 ( V_412 , L_129 ) ;
if ( ! F_9 ( V_9 ) )
F_178 ( V_412 , L_130 ) ;
if ( ! F_145 ( V_9 ) )
F_178 ( V_412 , L_131 ) ;
if ( ! F_146 ( V_9 ) )
F_178 ( V_412 , L_132 ) ;
if ( ! F_144 ( V_9 ) )
F_178 ( V_412 , L_133 ) ;
F_178 ( V_412 , L_116 ) ;
}
static int F_179 ( struct V_411 * V_412 , void * V_414 )
{
int V_188 ;
F_177 ( V_412 , L_134 , V_415 ) ;
for ( V_188 = 0 ; V_188 < V_197 ; V_188 ++ ) {
if ( ! V_198 [ V_188 ] . V_199 )
continue;
F_176 ( V_412 , & V_198 [ V_188 ] ) ;
}
#ifdef F_180
for ( V_188 = 0 ; V_188 < V_2 ; V_188 ++ ) {
F_177 ( V_412 , L_135 ,
V_188 , V_4 [ V_188 ] . time ,
F_181 ( V_4 [ V_188 ] . V_6 ) ) ;
F_177 ( V_412 , V_4 [ V_188 ] . string , V_4 [ V_188 ] . V_1 ) ;
}
F_177 ( V_412 , L_136 , V_188 , V_3 ) ;
V_2 = 0 ;
#endif
return 0 ;
}
static int F_182 ( struct V_416 * V_416 , struct V_368 * V_368 )
{
return F_183 ( V_368 , F_179 , NULL ) ;
}
static void F_184 ( void )
{
F_5 ( V_417
L_137
L_138 ,
& V_415 [ 11 ] ) ;
}
static int T_5 F_185 ( void )
{
int V_188 ;
struct V_8 * V_9 ;
struct V_418 * V_419 = F_186 ( V_197 ) ;
if ( ! V_419 )
return - V_254 ;
F_184 () ;
#if ! F_39 ( V_420 )
F_187 ( & V_209 , F_88 , 0 ) ;
F_89 ( & V_209 , V_5 + 5 ) ;
#endif
#if F_39 ( V_133 )
#if F_39 ( V_78 )
if ( F_188 ( V_421 , 'a' , V_81 ,
V_81 ) ) {
F_5 ( V_158 L_139
L_140 ) ;
F_189 ( V_419 ) ;
return - V_322 ;
}
#endif
#if F_39 ( V_82 )
if ( F_188 ( V_421 , 'g' , V_81 ,
V_85 ) ) {
F_5 ( V_158 L_139
L_140 ) ;
F_189 ( V_419 ) ;
return - V_322 ;
}
#endif
#endif
V_419 -> V_422 = L_141 ;
V_419 -> V_404 = L_142 ;
V_419 -> V_423 = V_424 ;
V_419 -> V_425 = 64 ;
V_419 -> type = V_426 ;
V_419 -> V_427 = V_428 ;
V_419 -> V_429 = V_430 ;
V_419 -> V_429 . V_14 =
V_431 | V_432 | V_433 | V_261 | V_398 ;
V_419 -> V_429 . V_434 = 115200 ;
V_419 -> V_429 . V_435 = 115200 ;
V_419 -> V_36 = V_436 | V_437 ;
F_190 ( V_419 , & V_438 ) ;
V_439 = V_419 ;
if ( F_191 ( V_419 ) )
F_64 ( L_143 ) ;
for ( V_188 = 0 , V_9 = V_198 ; V_188 < V_197 ; V_188 ++ , V_9 ++ ) {
if ( V_9 -> V_199 ) {
if ( F_192 ( V_9 -> V_440 ,
V_9 -> V_441 ) ) {
F_5 ( V_158 L_144
L_145
L_146 ,
V_9 -> V_441 , V_188 ) ;
V_9 -> V_199 = 0 ;
}
}
V_9 -> V_73 = 0 ;
V_9 -> V_114 = 0 ;
V_9 -> line = V_188 ;
V_9 -> V_11 . V_12 = NULL ;
V_9 -> type = V_442 ;
V_9 -> V_121 = 0 ;
V_9 -> V_204 = 0 ;
V_9 -> V_269 = V_443 ;
V_9 -> V_270 = 0 ;
V_9 -> V_36 = 0 ;
V_9 -> V_313 = 5 * V_232 / 10 ;
V_9 -> V_314 = 30 * V_232 ;
V_9 -> V_234 = 0 ;
V_9 -> V_115 = 0 ;
V_9 -> V_92 = 0 ;
V_9 -> V_377 = 0 ;
V_9 -> V_374 = V_419 -> V_429 ;
F_193 ( & V_9 -> V_378 ) ;
F_193 ( & V_9 -> V_379 ) ;
V_9 -> V_101 . V_91 = NULL ;
V_9 -> V_101 . V_103 = V_9 -> V_101 . V_102 = 0 ;
V_9 -> V_151 = V_9 -> V_152 = NULL ;
V_9 -> V_153 = V_9 -> V_154 = 0 ;
V_9 -> V_201 = 0 ;
V_9 -> V_202 = 0 ;
#if F_39 ( V_133 )
V_9 -> V_89 . V_36 &= ~ ( V_302 ) ;
V_9 -> V_89 . V_36 |= V_98 ;
V_9 -> V_89 . V_36 &= ~ ( V_303 ) ;
V_9 -> V_89 . V_90 = 0 ;
V_9 -> V_89 . V_36 &= ~ ( V_94 ) ;
#endif
F_194 ( & V_9 -> V_116 , F_98 ) ;
if ( V_9 -> V_199 ) {
F_5 ( V_417 L_147 ,
V_439 -> V_404 , V_9 -> line , V_9 -> V_40 ) ;
}
}
#ifdef V_134
#ifdef V_420
memset ( V_206 , 0 , sizeof( V_206 ) ) ;
#endif
#ifdef V_133
memset ( V_96 , 0 , sizeof( V_96 ) ) ;
#endif
F_195 () ;
#endif
#ifndef F_7
#ifndef F_196
if ( F_173 ( V_444 , F_95 ,
V_445 | V_446 , L_148 , V_419 ) )
F_64 ( L_149 , V_159 ) ;
#endif
#endif
return 0 ;
}
