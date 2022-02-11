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
T_1 V_10 = V_9 -> V_11 . V_12 -> V_13 . V_14 ;
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
unsigned char V_32 = V_33 [ V_9 -> line ] . V_34 ;
#ifdef F_7
F_5 ( L_2 , V_9 -> line , V_31 , V_32 ) ;
F_5 ( L_3 ,
V_9 -> line , * V_33 [ V_9 -> line ] . V_35 ,
F_8 ( V_9 ) ) ;
#endif
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
* V_33 [ V_9 -> line ] . V_35 &= ~ V_32 ;
* V_33 [ V_9 -> line ] . V_35 |= ( V_31 ? 0 : V_32 ) ;
* V_33 [ V_9 -> line ] . V_37 = * V_33 [ V_9 -> line ] . V_35 ;
F_10 ( V_36 ) ;
}
#ifdef F_7
F_5 ( L_4 ,
V_9 -> line , * V_33 [ V_9 -> line ] . V_35 ,
F_8 ( V_9 ) ) ;
#endif
}
static inline void
F_11 ( struct V_8 * V_9 , int V_31 )
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
V_9 -> V_38 &= ~ V_39 ;
V_9 -> V_38 |= ( V_31 ? 0 : V_39 ) ;
V_9 -> V_40 [ V_41 ] = V_9 -> V_38 ;
F_10 ( V_36 ) ;
#ifdef F_7
F_5 ( L_5 , V_9 -> line , V_31 ) ;
#endif
}
static inline void
F_12 ( struct V_8 * V_9 , int V_31 )
{
{
unsigned char V_32 = V_33 [ V_9 -> line ] . V_42 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
* V_33 [ V_9 -> line ] . V_43 &= ~ V_32 ;
* V_33 [ V_9 -> line ] . V_43 |= ( V_31 ? 0 : V_32 ) ;
* V_33 [ V_9 -> line ] . V_44 = * V_33 [ V_9 -> line ] . V_43 ;
F_10 ( V_36 ) ;
}
}
static inline void
F_13 ( struct V_8 * V_9 , int V_31 )
{
{
unsigned char V_32 = V_33 [ V_9 -> line ] . V_45 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
* V_33 [ V_9 -> line ] . V_46 &= ~ V_32 ;
* V_33 [ V_9 -> line ] . V_46 |= ( V_31 ? 0 : V_32 ) ;
* V_33 [ V_9 -> line ] . V_47 = * V_33 [ V_9 -> line ] . V_46 ;
F_10 ( V_36 ) ;
}
}
static inline void
F_14 ( struct V_8 * V_9 )
{
V_9 -> V_40 [ V_41 ] =
( V_9 -> V_38 &= ~ F_15 ( V_48 , V_49 ) ) ;
}
static inline void
F_16 ( struct V_8 * V_9 )
{
V_9 -> V_40 [ V_41 ] =
( V_9 -> V_38 |= F_15 ( V_48 , V_49 ) ) ;
}
static inline void
F_17 ( struct V_8 * V_9 )
{
#ifdef F_18
F_5 ( L_6 , V_9 -> line ) ;
#endif
F_19 ( F_20 ( V_9 -> line , L_7 , V_9 -> line ) ) ;
* V_50 = ( V_9 -> V_51 << 2 ) | ( V_9 -> V_51 << 3 ) ;
}
static inline void
F_21 ( struct V_8 * V_9 )
{
#ifdef F_18
F_5 ( L_8 , V_9 -> line ) ;
#endif
F_19 ( F_20 ( V_9 -> line , L_9 , V_9 -> line ) ) ;
* V_52 = ( V_9 -> V_51 << 2 ) | ( V_9 -> V_51 << 3 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
#ifdef F_18
F_5 ( L_10 , V_9 -> line ) ;
#endif
F_19 ( F_20 ( V_9 -> line , L_11 , V_9 -> line ) ) ;
* V_50 = V_9 -> V_51 ;
}
static void F_23 ( struct V_8 * V_9 )
{
#ifdef F_18
F_5 ( L_12 , V_9 -> line ) ;
#endif
F_19 ( F_20 ( V_9 -> line , L_13 , V_9 -> line ) ) ;
* V_52 = V_9 -> V_51 ;
}
static void F_24 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_14 , V_9 -> line ) ) ;
if ( V_9 -> line == 0 ) {
if ( ( V_53 & F_15 ( V_54 , V_55 ) ) ==
F_26 ( V_54 , V_55 , V_56 ) ) {
V_53 &= ~ F_15 ( V_54 , V_55 ) ;
V_53 |= F_26 ( V_54 , V_55 , V_57 ) ;
}
} else if ( V_9 -> line == 1 ) {
if ( ( V_53 & F_15 ( V_54 , V_58 ) ) ==
F_26 ( V_54 , V_58 , V_59 ) ) {
V_53 &= ~ F_15 ( V_54 , V_58 ) ;
V_53 |= F_26 ( V_54 , V_58 , V_60 ) ;
}
} else if ( V_9 -> line == 2 ) {
if ( ( V_53 & F_15 ( V_54 , V_61 ) ) ==
F_26 ( V_54 , V_61 , V_62 ) ) {
V_53 &= ~ F_15 ( V_54 , V_61 ) ;
V_53 |= F_26 ( V_54 , V_61 , V_63 ) ;
}
} else if ( V_9 -> line == 3 ) {
if ( ( V_53 & F_15 ( V_54 , V_64 ) ) ==
F_26 ( V_54 , V_64 , V_65 ) ) {
V_53 &= ~ F_15 ( V_54 , V_64 ) ;
V_53 |= F_26 ( V_54 , V_64 , V_66 ) ;
}
}
* V_54 = V_53 ;
F_10 ( V_36 ) ;
}
static void F_27 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_15 , V_9 -> line ) ) ;
if ( V_9 -> line == 0 ) {
V_53 &= ~ F_15 ( V_54 , V_55 ) ;
V_53 |= F_26 ( V_54 , V_55 , V_56 ) ;
} else if ( V_9 -> line == 1 ) {
V_53 &= ~ F_15 ( V_54 , V_58 ) ;
V_53 |= F_26 ( V_54 , V_58 , V_59 ) ;
} else if ( V_9 -> line == 2 ) {
V_53 &= ~ F_15 ( V_54 , V_61 ) ;
V_53 |= F_26 ( V_54 , V_61 , V_62 ) ;
} else if ( V_9 -> line == 3 ) {
V_53 &= ~ F_15 ( V_54 , V_64 ) ;
V_53 |= F_26 ( V_54 , V_64 , V_65 ) ;
}
* V_54 = V_53 ;
F_10 ( V_36 ) ;
}
static void F_28 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( V_9 -> line == 0 ) {
if ( ( V_53 & F_15 ( V_54 , V_67 ) ) ==
F_26 ( V_54 , V_67 , V_56 ) ) {
V_53 &= ~ F_15 ( V_54 , V_67 ) ;
V_53 |= F_26 ( V_54 , V_67 , V_57 ) ;
}
} else if ( V_9 -> line == 1 ) {
if ( ( V_53 & F_15 ( V_54 , V_68 ) ) ==
F_26 ( V_54 , V_68 , V_59 ) ) {
V_53 &= ~ F_15 ( V_54 , V_68 ) ;
V_53 |= F_26 ( V_54 , V_68 , V_60 ) ;
}
} else if ( V_9 -> line == 2 ) {
if ( ( V_53 & F_15 ( V_54 , V_69 ) ) ==
F_26 ( V_54 , V_69 , V_62 ) ) {
V_53 &= ~ F_15 ( V_54 , V_69 ) ;
V_53 |= F_26 ( V_54 , V_69 , V_63 ) ;
}
} else if ( V_9 -> line == 3 ) {
if ( ( V_53 & F_15 ( V_54 , V_70 ) ) ==
F_26 ( V_54 , V_70 , V_65 ) ) {
V_53 &= ~ F_15 ( V_54 , V_70 ) ;
V_53 |= F_26 ( V_54 , V_70 , V_66 ) ;
}
}
* V_54 = V_53 ;
F_10 ( V_36 ) ;
}
static void F_29 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( V_9 -> line == 0 ) {
V_53 &= ~ F_15 ( V_54 , V_67 ) ;
V_53 |= F_26 ( V_54 , V_67 , V_56 ) ;
} else if ( V_9 -> line == 1 ) {
V_53 &= ~ F_15 ( V_54 , V_68 ) ;
V_53 |= F_26 ( V_54 , V_68 , V_59 ) ;
} else if ( V_9 -> line == 2 ) {
V_53 &= ~ F_15 ( V_54 , V_69 ) ;
V_53 |= F_26 ( V_54 , V_69 , V_62 ) ;
} else if ( V_9 -> line == 3 ) {
V_53 &= ~ F_15 ( V_54 , V_70 ) ;
V_53 |= F_26 ( V_54 , V_70 , V_65 ) ;
}
* V_54 = V_53 ;
F_10 ( V_36 ) ;
}
static inline void
F_30 ( struct V_8 * V_9 )
{
#ifdef F_18
F_5 ( L_16 , V_9 -> line ) ;
#endif
F_19 ( F_20 ( V_9 -> line , L_17 , V_9 -> line ) ) ;
* V_71 = ( 1U << ( 8 + 2 * V_9 -> line ) ) ;
}
static inline void
F_31 ( struct V_8 * V_9 )
{
#ifdef F_18
F_5 ( L_18 , V_9 -> line ) ;
F_5 ( L_19 ,
( 8 + 2 * V_9 -> line ) ,
( 1U << ( 8 + 2 * V_9 -> line ) ) ) ;
#endif
F_19 ( F_20 ( V_9 -> line , L_20 , V_9 -> line ) ) ;
* V_72 = ( 1U << ( 8 + 2 * V_9 -> line ) ) ;
}
static inline void
F_32 ( struct V_8 * V_9 )
{
#ifdef F_18
F_5 ( L_21 , V_9 -> line ) ;
#endif
F_19 ( F_20 ( V_9 -> line , L_22 , V_9 -> line ) ) ;
* V_71 = ( 1U << ( 8 + 1 + 2 * V_9 -> line ) ) ;
}
static inline void
F_33 ( struct V_8 * V_9 )
{
#ifdef F_18
F_5 ( L_23 , V_9 -> line ) ;
F_5 ( L_19 ,
( 8 + 1 + 2 * V_9 -> line ) ,
( 1U << ( 8 + 1 + 2 * V_9 -> line ) ) ) ;
#endif
F_34 ( F_20 ( V_9 -> line , L_24 , V_9 -> line ) ) ;
* V_72 = ( 1U << ( 8 + 1 + 2 * V_9 -> line ) ) ;
}
static inline void F_35 ( struct V_8 * V_9 )
{
if ( V_9 -> V_73 )
F_21 ( V_9 ) ;
else
F_31 ( V_9 ) ;
}
static inline void F_36 ( struct V_8 * V_9 )
{
if ( V_9 -> V_73 )
F_17 ( V_9 ) ;
else
F_30 ( V_9 ) ;
}
static int
F_37 ( struct V_74 * V_12 , struct V_75 * V_76 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#if F_38 ( V_78 )
* V_79 = V_80 |= ( 1 << V_81 ) ;
#endif
#if F_38 ( V_82 )
F_39 ( V_83 , V_84 ,
V_85 , 1 ) ;
#endif
#if F_38 ( V_86 )
F_39 ( V_83 , V_84 ,
V_87 , 1 ) ;
F_39 ( V_83 , V_84 ,
V_88 , 1 ) ;
#endif
V_9 -> V_89 = * V_76 ;
if ( V_9 -> V_89 . V_90 >= 1000 )
V_9 -> V_89 . V_90 = 1000 ;
return 0 ;
}
static int
F_40 ( struct V_74 * V_12 ,
const unsigned char * V_91 , int V_92 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
int V_93 = ( V_9 -> V_89 . V_36 ) & V_94 ;
V_9 -> V_89 . V_36 |= V_94 ;
V_92 = F_41 ( V_12 , V_91 , V_92 ) ;
if ( ! V_93 )
V_9 -> V_89 . V_36 &= ~ ( V_94 ) ;
return V_92 ;
}
static void F_42 ( unsigned long V_95 )
{
struct V_8 * V_9 = (struct V_8 * ) V_95 ;
V_96 [ V_9 -> line ] . V_97 = NULL ;
F_11 ( V_9 , ( V_9 -> V_89 . V_36 & V_98 ) ) ;
#if F_38 ( V_99 )
F_16 ( V_9 ) ;
F_35 ( V_9 ) ;
#endif
}
static void
F_43 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 ) {
unsigned long V_36 ;
unsigned long V_100 ;
F_9 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_25 ,
F_44 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 , V_104 ) ) ) ;
V_100 = F_45 ( V_105 , V_106 ,
F_46 ( V_9 -> V_11 . V_12 ) ) ;
V_100 |= F_26 ( V_105 , V_107 , V_108 ) ;
if ( V_12 -> V_13 . V_109 & V_110 ) {
V_100 |= F_26 ( V_105 , V_111 , V_112 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_113 ] ) = V_100 ;
F_10 ( V_36 ) ;
}
}
static void
F_47 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 ) {
unsigned long V_36 ;
unsigned long V_100 ;
F_9 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_26 ,
F_44 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 , V_104 ) ) ) ;
V_100 = F_45 ( V_105 , V_106 , F_46 ( V_12 ) ) ;
V_100 |= F_26 ( V_105 , V_107 , V_112 ) ;
if ( V_12 -> V_13 . V_109 & V_110 ) {
V_100 |= F_26 ( V_105 , V_111 , V_112 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_113 ] ) = V_100 ;
if ( ! V_9 -> V_114 &&
V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 && V_9 -> V_101 . V_91 )
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
}
}
static void F_48 ( struct V_8 * V_9 , int V_115 )
{
if ( V_9 -> V_115 & ( 1 << V_115 ) )
return;
V_9 -> V_115 |= 1 << V_115 ;
F_49 ( & V_9 -> V_116 ) ;
}
static void
F_50 ( struct V_8 * V_9 )
{
unsigned int V_117 , V_118 ;
struct V_119 * V_120 ;
* V_9 -> V_121 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
#ifdef F_18
if ( V_9 -> line == V_122 )
F_5 ( L_27 ) ;
#endif
if ( ! V_9 -> V_123 ) {
F_5 ( V_30 L_28 ) ;
return;
}
V_120 = & V_9 -> V_124 ;
if ( ! ( V_120 -> V_125 & V_126 ) ) {
V_118 = V_120 -> V_127 ;
} else
V_118 = V_120 -> V_128 ;
F_25 ( F_20 ( V_9 -> line , L_29 , V_118 ) ) ;
V_9 -> V_129 . V_130 += V_118 ;
V_9 -> V_101 . V_103 = ( V_9 -> V_101 . V_103 + V_118 ) & ( V_104 - 1 ) ;
if ( F_44 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 ,
V_104 ) < V_131 )
F_48 ( V_9 , V_132 ) ;
V_117 = F_51 ( V_9 -> V_101 . V_102 , V_9 -> V_101 . V_103 , V_104 ) ;
if ( V_117 >= 4 * V_131 )
V_117 = V_117 / 2 ;
if ( V_117 <= 0 ) {
V_9 -> V_123 = 0 ;
#if F_38 ( V_133 ) && F_38 ( V_134 )
if ( V_9 -> V_89 . V_36 & V_94 ) {
F_52 ( & V_96 [ V_9 -> line ] ,
F_42 ,
( unsigned long ) V_9 ,
V_9 -> V_20 * 2 ,
L_30 ) ;
}
#endif
return;
}
F_25 ( F_20 ( V_9 -> line , L_31 , V_117 ) ) ;
V_120 -> V_135 = V_136 | V_137 | V_138 ;
V_120 -> V_127 = V_117 ;
V_120 -> V_91 = F_53 ( V_9 -> V_101 . V_91 + V_9 -> V_101 . V_103 ) ;
V_120 -> V_125 = 0 ;
* V_9 -> V_139 = F_53 ( V_120 ) ;
* V_9 -> V_140 = F_26 ( V_141 , V_142 , V_143 ) ;
}
static void
F_54 ( struct V_8 * V_9 )
{
#if 0
if (info->line == SERIAL_DEBUG_LINE)
printk("x\n");
#endif
V_9 -> V_124 . V_127 = 0 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_123 = 1 ;
if ( V_9 -> V_114 )
F_50 ( V_9 ) ;
else
F_33 ( V_9 ) ;
}
static struct V_144 *
F_55 ( unsigned int V_145 )
{
struct V_144 * V_146 ;
if ( ! ( V_146 = F_56 ( sizeof *V_146 + V_145 , V_147 ) ) )
return NULL ;
V_146 -> V_148 = NULL ;
V_146 -> V_149 = 0 ;
V_146 -> error = V_150 ;
return V_146 ;
}
static void
F_57 ( struct V_8 * V_9 , struct V_144 * V_146 )
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( ! V_9 -> V_151 )
V_9 -> V_151 = V_146 ;
else
V_9 -> V_152 -> V_148 = V_146 ;
V_9 -> V_152 = V_146 ;
V_9 -> V_153 += V_146 -> V_149 ;
if ( V_9 -> V_153 > V_9 -> V_154 )
V_9 -> V_154 = V_9 -> V_153 ;
F_10 ( V_36 ) ;
}
static int
F_58 ( struct V_8 * V_9 , unsigned char V_95 , unsigned char V_155 )
{
struct V_144 * V_146 ;
if ( V_9 -> V_73 ) {
if ( ! ( V_146 = F_55 ( 4 ) ) )
return 0 ;
V_146 -> V_149 = 1 ;
V_146 -> error = V_155 ;
V_146 -> V_146 [ 0 ] = V_95 ;
F_57 ( V_9 , V_146 ) ;
V_9 -> V_129 . V_156 ++ ;
} else {
F_59 ( & V_9 -> V_11 , V_95 , V_155 ) ;
V_9 -> V_129 . V_156 ++ ;
}
return 1 ;
}
static unsigned int F_60 ( struct V_8 * V_9 ,
struct V_119 * V_120 ,
unsigned int V_157 )
{
struct V_144 * V_146 = F_61 ( V_120 -> V_91 ) - sizeof *V_146 ;
if ( V_9 -> V_153 + V_157 > 65536 ) {
F_5 ( V_30
L_32 , V_158 , V_157 ) ;
return 0 ;
}
V_146 -> V_149 = V_157 ;
if ( V_9 -> V_159 == V_160 )
V_146 -> error = V_161 ;
V_9 -> V_159 = 0 ;
F_57 ( V_9 , V_146 ) ;
if ( ! ( V_146 = F_55 ( V_162 ) ) )
F_62 ( L_33 , V_158 ) ;
V_120 -> V_91 = F_53 ( V_146 -> V_146 ) ;
return V_157 ;
}
static unsigned int F_63 ( struct V_8 * V_9 )
{
struct V_119 * V_120 ;
unsigned int V_157 ;
unsigned int V_163 = 0 ;
while ( 1 )
{
V_120 = & V_9 -> V_164 [ V_9 -> V_165 ] ;
if ( V_120 == F_61 ( * V_9 -> V_166 ) )
break;
if ( ++ V_9 -> V_165 == V_167 )
V_9 -> V_165 = 0 ;
if ( ! ( V_120 -> V_125 & V_168 ) ) {
V_157 = V_120 -> V_127 ;
} else {
V_157 = V_120 -> V_128 ;
}
V_120 -> V_125 = 0 ;
F_25 ( DEBUG_LOG(info->line, L_34, recvl);
if (info->port.tty->stopped) {
unsigned char *buf = phys_to_virt(descr->buf);
DEBUG_LOG(info->line, L_35, buf[0]);
DEBUG_LOG(info->line, L_35, buf[1]);
DEBUG_LOG(info->line, L_35, buf[2]);
}
) ;
V_9 -> V_129 . V_156 += V_157 ;
V_163 += F_60 ( V_9 , V_120 , V_157 ) ;
}
return V_163 ;
}
static void F_64 ( struct V_8 * V_9 )
{
struct V_74 * V_12 ;
unsigned char V_169 ;
* V_9 -> V_170 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 )
return;
#ifdef F_65
if ( V_9 -> V_73 )
F_31 ( V_9 ) ;
#endif
if ( V_9 -> V_159 == V_171 )
F_58 ( V_9 , '\0' , V_161 ) ;
F_63 ( V_9 ) ;
V_169 = V_9 -> V_40 [ V_172 ] ;
if ( V_169 & F_15 ( V_173 , V_174 ) ) {
F_25 ( F_20 ( V_9 -> line , L_36 , V_169 ) ) ;
}
if ( V_169 & V_175 ) {
unsigned char V_95 = V_9 -> V_40 [ V_176 ] ;
F_66 ( V_177 [ V_9 -> line ] . V_178 ++ ) ;
F_20 ( V_9 -> line , L_37 ,
( ( V_169 & V_175 ) << 8 ) | V_95 ) ;
if ( V_169 & V_179 )
F_58 ( V_9 , V_95 , V_180 ) ;
else if ( V_169 & V_181 )
F_58 ( V_9 , V_95 , V_182 ) ;
else if ( V_169 & V_183 )
F_58 ( V_9 , V_95 , V_184 ) ;
}
F_67 ( V_9 , L_38 ) ;
* V_9 -> V_185 = F_26 ( V_141 , V_142 , V_186 ) ;
}
static int F_68 ( struct V_8 * V_9 )
{
struct V_119 * V_120 = V_9 -> V_164 ;
struct V_144 * V_146 ;
int V_187 ;
for ( V_187 = 0 ; V_187 < V_167 ; V_187 ++ ) {
if ( ! ( V_146 = F_55 ( V_162 ) ) )
F_62 ( L_33 , V_158 ) ;
V_120 [ V_187 ] . V_135 = V_136 ;
V_120 [ V_187 ] . V_91 = F_53 ( V_146 -> V_146 ) ;
V_120 [ V_187 ] . V_127 = V_162 ;
V_120 [ V_187 ] . V_128 = 0 ;
V_120 [ V_187 ] . V_125 = 0 ;
V_120 [ V_187 ] . V_148 = F_53 ( & V_120 [ V_187 + 1 ] ) ;
}
V_120 [ V_187 - 1 ] . V_148 = F_53 ( & V_120 [ 0 ] ) ;
V_9 -> V_165 = 0 ;
* V_9 -> V_188 = F_53 ( & V_120 [ V_9 -> V_165 ] ) ;
* V_9 -> V_185 = F_26 ( V_141 , V_142 , V_143 ) ;
return 1 ;
}
static void
F_69 ( struct V_8 * V_9 )
{
if ( V_9 -> V_73 ) {
* V_9 -> V_185 = F_26 ( V_141 , V_142 , V_189 ) ;
while ( F_70 ( V_141 , V_142 , * V_9 -> V_185 ) ==
F_71 ( V_141 , V_142 , V_189 ) ) ;
F_68 ( V_9 ) ;
}
}
static T_2
F_72 ( int V_51 , void * V_190 )
{
struct V_8 * V_9 ;
unsigned long V_191 ;
int V_187 ;
int V_192 = 0 ;
V_191 = * V_193 ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ ) {
V_9 = V_195 + V_187 ;
if ( ! V_9 -> V_196 || ! V_9 -> V_114 )
continue;
if ( V_191 & V_9 -> V_51 ) {
V_192 = 1 ;
F_34 ( F_20 ( V_9 -> line , L_39 , V_187 ) ) ;
F_66 ( V_177 [ V_9 -> line ] . V_197 ++ ) ;
V_9 -> V_198 = F_73 () ;
V_9 -> V_199 = V_5 ;
F_50 ( V_9 ) ;
}
}
return F_74 ( V_192 ) ;
}
static T_2
F_75 ( int V_51 , void * V_190 )
{
struct V_8 * V_9 ;
unsigned long V_191 ;
int V_187 ;
int V_192 = 0 ;
V_191 = * V_193 ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ ) {
V_9 = V_195 + V_187 ;
if ( ! V_9 -> V_196 || ! V_9 -> V_73 )
continue;
if ( V_191 & ( ( V_9 -> V_51 << 2 ) | ( V_9 -> V_51 << 3 ) ) ) {
V_192 = 1 ;
F_64 ( V_9 ) ;
}
}
return F_74 ( V_192 ) ;
}
static int F_76 ( struct V_8 * V_9 )
{
unsigned char V_169 = V_9 -> V_40 [ V_172 ] ;
if ( V_169 & V_175 ) {
F_20 ( V_9 -> line , L_40 ,
V_169 | ( V_9 -> line << 8 ) ) ;
return 0 ;
}
if ( V_169 & V_200 ) {
F_77 ( F_20 ( V_9 -> line , L_41 ,
V_169 | ( V_9 -> line << 8 ) ) ) ;
( void ) V_9 -> V_40 [ V_176 ] ;
V_9 -> V_201 = 0 ;
F_67 ( V_9 , L_42 ) ;
return 0 ;
}
if ( ! V_9 -> V_201 ) {
V_9 -> V_201 = 1 ;
F_66 ( V_177 [ V_9 -> line ] . V_202 ++ ) ;
F_77 ( F_20 ( V_9 -> line , L_43 , V_9 -> line ) ) ;
F_78 ( V_9 ) ;
}
return 1 ;
}
static void F_79 ( struct V_8 * V_9 )
{
struct V_144 * V_146 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
while ( ( V_146 = V_9 -> V_151 ) != NULL ) {
unsigned int V_92 = V_146 -> V_149 ;
F_80 ( & V_9 -> V_11 , V_146 -> V_146 , V_92 ) ;
V_9 -> V_153 -= V_92 ;
if ( V_92 == V_146 -> V_149 ) {
V_9 -> V_151 = V_146 -> V_148 ;
F_81 ( V_146 ) ;
} else {
V_146 -> V_149 -= V_92 ;
memmove ( V_146 -> V_146 , V_146 -> V_146 + V_92 , V_146 -> V_149 ) ;
V_146 -> error = V_150 ;
}
}
if ( ! V_9 -> V_151 )
V_9 -> V_152 = NULL ;
F_10 ( V_36 ) ;
F_82 ( & V_9 -> V_11 ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
F_79 ( V_9 ) ;
if ( V_9 -> V_151 )
F_84 ( V_9 , L_44 , 2000 ) ;
F_76 ( V_9 ) ;
}
static void F_85 ( unsigned long V_95 )
{
struct V_8 * V_9 = (struct V_8 * ) V_95 ;
V_203 [ V_9 -> line ] . V_97 = NULL ;
V_204 ++ ;
F_77 ( F_20 ( V_9 -> line , L_45 , V_9 -> line ) ) ;
F_77 ( F_20 ( V_9 -> line , L_46 , V_204 ) ) ;
F_83 ( V_9 ) ;
}
static void
F_86 ( unsigned long V_205 )
{
struct V_8 * V_9 ;
int V_187 ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ ) {
V_9 = V_195 + V_187 ;
if ( V_9 -> V_73 )
F_83 ( V_9 ) ;
}
F_87 ( & V_206 , V_5 + V_207 ) ;
}
static void F_88 ( struct V_8 * V_9 )
{
unsigned long V_208 ;
V_208 = * ( ( unsigned long * ) & V_9 -> V_40 [ V_209 ] ) ;
V_210:
if ( V_208 & F_15 ( V_211 , V_174 ) ) {
F_25 ( F_20 ( V_9 -> line , L_47 , 0 ) ) ;
}
F_34 ( F_20 ( V_9 -> line , L_48 , F_70 ( V_211 , V_212 , V_208 ) ) ) ;
if ( V_208 & ( F_15 ( V_211 , V_213 ) |
F_15 ( V_211 , V_214 ) |
F_15 ( V_211 , V_215 ) ) ) {
V_9 -> V_216 = F_73 () ;
V_9 -> V_217 = V_5 ;
F_19 ( F_20 ( V_9 -> line , L_49 , V_208 ) ) ;
F_89 (
if (!log_int_trig1_pos) {
log_int_trig1_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
) ;
if ( ( ( V_208 & F_15 ( V_211 , V_212 ) ) == 0 ) &&
( V_208 & F_15 ( V_211 , V_213 ) ) ) {
if ( ! V_9 -> V_218 ) {
F_20 ( V_9 -> line , L_50 , 0 ) ;
}
if ( V_208 & F_15 ( V_211 , V_219 ) ) {
F_20 ( V_9 -> line , L_51 , 0 ) ;
V_9 -> V_159 = V_171 ;
}
V_9 -> V_218 ++ ;
} else {
if ( V_9 -> V_218 ) {
F_20 ( V_9 -> line , L_52 , V_9 -> V_218 ) ;
V_9 -> V_159 = V_171 ;
} else {
unsigned char V_95 = F_70 ( V_211 ,
V_212 , V_208 ) ;
char V_155 = V_150 ;
if ( V_9 -> V_159 == V_171 ) {
F_59 ( & V_9 -> V_11 , 0 , V_155 ) ;
V_9 -> V_129 . V_156 ++ ;
}
if ( V_208 & F_15 ( V_211 , V_214 ) ) {
V_9 -> V_129 . V_220 ++ ;
V_155 = V_180 ;
} else if ( V_208 & F_15 ( V_211 , V_215 ) ) {
V_9 -> V_129 . V_215 ++ ;
V_155 = V_182 ;
} else if ( V_208 & F_15 ( V_211 , V_213 ) ) {
V_9 -> V_129 . V_221 ++ ;
V_155 = V_184 ;
}
F_59 ( & V_9 -> V_11 , V_95 , V_155 ) ;
V_9 -> V_159 = 0 ;
}
V_9 -> V_218 = 0 ;
}
} else if ( V_208 & F_15 ( V_211 , V_222 ) ) {
F_89 (
if (!log_int_trig1_pos) {
if (log_int_pos >= log_int_size) {
log_int_pos = 0;
}
log_int_trig0_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
) ;
F_59 ( & V_9 -> V_11 ,
F_70 ( V_211 , V_212 , V_208 ) ,
V_150 ) ;
} else {
F_20 ( V_9 -> line , L_53 , V_208 ) ;
}
V_9 -> V_129 . V_156 ++ ;
V_208 = * ( ( unsigned long * ) & V_9 -> V_40 [ V_209 ] ) ;
if ( V_208 & F_15 ( V_211 , V_222 ) ) {
F_20 ( V_9 -> line , L_54 , F_70 ( V_211 , V_212 , V_208 ) ) ;
goto V_210;
}
F_82 ( & V_9 -> V_11 ) ;
}
static void F_90 ( struct V_8 * V_9 )
{
unsigned char V_169 ;
#ifdef F_18
F_5 ( L_55 , V_187 ) ;
#endif
if ( ! V_9 -> V_73 ) {
F_88 ( V_9 ) ;
return;
}
V_169 = V_9 -> V_40 [ V_172 ] ;
if ( V_169 & F_15 ( V_173 , V_174 ) ) {
F_25 ( F_20 ( V_9 -> line , L_47 , 0 ) ) ;
}
if ( V_169 & V_175 ) {
unsigned char V_95 ;
V_9 -> V_216 = F_73 () ;
V_9 -> V_217 = V_5 ;
V_95 = V_9 -> V_40 [ V_176 ] ;
F_19 ( F_20 ( V_9 -> line , L_56 , V_95 ) ) ;
F_19 ( F_20 ( V_9 -> line , L_57 , V_169 ) ) ;
if ( ! V_95 && ( V_169 & V_183 ) ) {
if ( ! V_9 -> V_218 ) {
F_20 ( V_9 -> line , L_50 , 0 ) ;
}
if ( V_169 & V_223 ) {
F_20 ( V_9 -> line , L_51 , 0 ) ;
V_9 -> V_159 = V_171 ;
}
V_9 -> V_218 ++ ;
} else {
if ( V_9 -> V_218 ) {
F_20 ( V_9 -> line , L_52 , V_9 -> V_218 ) ;
V_9 -> V_159 = V_171 ;
} else {
if ( V_9 -> V_159 == V_171 ) {
V_9 -> V_129 . V_224 ++ ;
F_58 ( V_9 , '\0' , V_161 ) ;
}
if ( V_169 & V_179 ) {
V_9 -> V_129 . V_220 ++ ;
F_58 ( V_9 , V_95 , V_180 ) ;
} else if ( V_169 & V_181 ) {
V_9 -> V_129 . V_215 ++ ;
F_58 ( V_9 , V_95 , V_182 ) ;
} else if ( V_169 & V_183 ) {
V_9 -> V_129 . V_221 ++ ;
F_58 ( V_9 , V_95 , V_184 ) ;
}
V_9 -> V_159 = 0 ;
}
V_9 -> V_218 = 0 ;
F_20 ( V_9 -> line , L_58 ,
( ( V_169 & V_175 ) << 8 ) | V_95 ) ;
}
F_66 ( V_177 [ V_9 -> line ] . V_225 ++ ) ;
} else {
unsigned long V_226 = F_73 () ;
unsigned long V_227 = V_5 ;
if ( V_9 -> V_218 ) {
long V_228 =
( V_227 - V_9 -> V_217 ) * ( 1000000 / V_229 ) +
V_226 - V_9 -> V_216 ;
if ( V_228 < 2 * V_9 -> V_20 ) {
F_20 ( V_9 -> line , L_59 , V_9 -> line ) ;
V_9 -> V_159 = V_160 ;
} else {
F_20 ( V_9 -> line , L_60 , V_9 -> line ) ;
}
F_20 ( V_9 -> line , L_61 , V_9 -> V_218 ) ;
}
#ifdef F_18
F_5 ( L_62 ) ;
#endif
F_30 ( V_9 ) ;
F_34 ( F_20 ( V_9 -> line , L_63 , V_9 -> line ) ) ;
V_9 -> V_218 = 0 ;
F_66 ( V_177 [ V_9 -> line ] . V_230 ++ ) ;
}
* V_9 -> V_185 = F_26 ( V_141 , V_142 , V_186 ) ;
F_67 ( V_9 , L_64 ) ;
}
static void F_91 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
if ( V_9 -> V_231 ) {
unsigned char V_169 ;
F_25 ( F_20 ( V_9 -> line , L_65 , V_9 -> V_231 ) ) ;
F_9 ( V_36 ) ;
V_169 = V_9 -> V_40 [ V_172 ] ;
F_25 ( F_20 ( V_9 -> line , L_66 , V_169 ) ) ;
V_9 -> V_40 [ V_232 ] = V_9 -> V_231 ;
V_9 -> V_129 . V_130 ++ ;
V_9 -> V_231 = 0 ;
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
return;
}
if ( V_9 -> V_114 ) {
unsigned char V_169 ;
int V_187 ;
F_25 ( F_20 ( V_9 -> line , L_67 , 0 ) ) ;
F_9 ( V_36 ) ;
V_169 = V_9 -> V_40 [ V_172 ] ;
F_25 ( F_20 ( V_9 -> line , L_66 , V_169 ) ) ;
F_32 ( V_9 ) ;
if ( V_9 -> V_11 . V_12 -> V_233 )
F_43 ( V_9 -> V_11 . V_12 ) ;
F_27 ( V_9 ) ;
for( V_187 = 6 ; V_187 > 0 ; V_187 -- )
F_92 () ;
* V_9 -> V_140 = F_26 (R_DMA_CH6_CMD, cmd, continue) ;
F_10 ( V_36 ) ;
return;
}
if ( V_9 -> V_101 . V_102 == V_9 -> V_101 . V_103
|| V_9 -> V_11 . V_12 -> V_233 ) {
F_25 ( F_20 ( V_9 -> line , L_68 ,
V_9 -> V_11 . V_12 -> V_233 ) ) ;
F_32 ( V_9 ) ;
V_9 -> V_123 = 0 ;
return;
}
F_34 ( F_20 ( V_9 -> line , L_69 , V_9 -> V_101 . V_91 [ V_9 -> V_101 . V_103 ] ) ) ;
F_9 ( V_36 ) ;
V_9 -> V_40 [ V_232 ] = V_9 -> V_101 . V_91 [ V_9 -> V_101 . V_103 ] ;
V_9 -> V_101 . V_103 = ( V_9 -> V_101 . V_103 + 1 ) & ( V_104 - 1 ) ;
V_9 -> V_129 . V_130 ++ ;
if ( V_9 -> V_101 . V_102 == V_9 -> V_101 . V_103 ) {
#if F_38 ( V_133 ) && F_38 ( V_134 )
if ( V_9 -> V_89 . V_36 & V_94 ) {
F_52 ( & V_96 [ V_9 -> line ] ,
F_42 ,
( unsigned long ) V_9 ,
V_9 -> V_20 * 2 ,
L_30 ) ;
}
#endif
V_9 -> V_198 = F_73 () ;
V_9 -> V_199 = V_5 ;
F_32 ( V_9 ) ;
V_9 -> V_123 = 0 ;
F_25 ( F_20 ( V_9 -> line , L_70 , 0 ) ) ;
} else {
F_33 ( V_9 ) ;
}
F_10 ( V_36 ) ;
if ( F_44 ( V_9 -> V_101 . V_102 ,
V_9 -> V_101 . V_103 ,
V_104 ) < V_131 )
F_48 ( V_9 , V_132 ) ;
}
static T_2
F_93 ( int V_51 , void * V_190 )
{
static volatile int V_234 = 0 ;
struct V_8 * V_9 ;
int V_187 ;
unsigned long V_36 ;
unsigned long V_235 ;
unsigned long V_236 = ( 1 << ( 8 + 2 * 0 ) ) ;
int V_192 = 0 ;
static volatile unsigned long V_237 = 0 ;
F_9 ( V_36 ) ;
V_235 = * V_238 ;
V_9 = V_195 ;
V_235 &= V_239 ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ ) {
if ( V_235 & V_236 ) {
V_192 = 1 ;
F_90 ( V_9 ) ;
}
V_9 += 1 ;
V_236 <<= 2 ;
}
if ( ! V_234 ) {
unsigned long V_240 ;
unsigned long
V_234 = 1 ;
V_235 &= ( F_15 ( V_238 , V_241 ) |
F_15 ( V_238 , V_242 ) |
F_15 ( V_238 , V_243 ) |
F_15 ( V_238 , V_244 ) ) ;
while ( V_235 ) {
* V_71 = V_235 ;
* V_245 = F_26 ( V_245 , V_246 , V_31 ) ;
F_94 () ;
V_240 = ( 1 << ( 8 + 1 + 2 * 0 ) ) ;
V_9 = V_195 ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ ) {
if ( V_235 & V_240 ) {
V_192 = 1 ;
F_91 ( V_9 ) ;
}
V_9 += 1 ;
V_240 <<= 2 ;
}
F_95 () ;
V_235 = V_237 ;
}
F_95 () ;
V_234 = 0 ;
} else {
unsigned long V_240 ;
V_240 = V_235 & ( F_15 ( V_238 , V_241 ) |
F_15 ( V_238 , V_242 ) |
F_15 ( V_238 , V_243 ) |
F_15 ( V_238 , V_244 ) ) ;
if ( V_240 ) {
V_237 |= V_240 ;
* V_71 = V_240 ;
F_25 ( F_20 ( V_122 , L_71 , V_240 ) ) ;
}
}
F_10 ( V_36 ) ;
return F_74 ( V_192 ) ;
}
static void
F_96 ( struct V_247 * V_116 )
{
struct V_8 * V_9 ;
struct V_74 * V_12 ;
V_9 = F_97 ( V_116 , struct V_8 , V_116 ) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 )
return;
if ( F_98 ( V_132 , & V_9 -> V_115 ) )
F_99 ( V_12 ) ;
}
static int
F_100 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
unsigned long V_248 ;
int V_187 ;
V_248 = F_101 ( V_249 ) ;
if ( ! V_248 )
return - V_250 ;
F_9 ( V_36 ) ;
if ( V_9 -> V_11 . V_36 & V_251 ) {
F_10 ( V_36 ) ;
F_102 ( V_248 ) ;
return 0 ;
}
if ( V_9 -> V_101 . V_91 )
F_102 ( V_248 ) ;
else
V_9 -> V_101 . V_91 = ( unsigned char * ) V_248 ;
#ifdef F_103
F_5 ( L_72 , V_9 -> line , V_9 -> V_101 . V_91 ) ;
#endif
if ( V_9 -> V_252 ) {
V_9 -> V_73 = 1 ;
F_29 ( V_9 ) ;
* V_9 -> V_185 = F_26 ( V_141 , V_142 , V_189 ) ;
while ( F_70 ( V_141 , V_142 , * V_9 -> V_185 ) ==
F_71 ( V_141 , V_142 , V_189 ) ) ;
* V_9 -> V_170 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
} else {
F_28 ( V_9 ) ;
}
if ( V_9 -> V_253 ) {
V_9 -> V_114 = 1 ;
F_27 ( V_9 ) ;
* V_9 -> V_140 = F_26 ( V_141 , V_142 , V_189 ) ;
while ( F_70 ( V_141 , V_142 , * V_9 -> V_140 ) ==
F_71 ( V_141 , V_142 , V_189 ) ) ;
* V_9 -> V_121 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
} else {
F_24 ( V_9 ) ;
}
if ( V_9 -> V_11 . V_12 )
F_104 ( V_254 , & V_9 -> V_11 . V_12 -> V_36 ) ;
V_9 -> V_101 . V_102 = V_9 -> V_101 . V_103 = 0 ;
V_9 -> V_151 = V_9 -> V_152 = NULL ;
V_9 -> V_153 = V_9 -> V_154 = 0 ;
for ( V_187 = 0 ; V_187 < V_167 ; V_187 ++ )
V_9 -> V_164 [ V_187 ] . V_91 = 0 ;
#ifdef F_65
F_31 ( V_9 ) ;
#endif
F_105 ( V_9 ) ;
( void ) V_9 -> V_40 [ V_176 ] ;
if ( V_9 -> V_114 )
F_23 ( V_9 ) ;
F_35 ( V_9 ) ;
V_9 -> V_123 = 0 ;
F_69 ( V_9 ) ;
V_9 -> V_124 . V_127 = 0 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = 0 ;
F_11 ( V_9 , 1 ) ;
F_6 ( V_9 , 1 ) ;
V_9 -> V_11 . V_36 |= V_251 ;
F_10 ( V_36 ) ;
return 0 ;
}
static void
F_106 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
struct V_119 * V_120 = V_9 -> V_164 ;
struct V_144 * V_146 ;
int V_187 ;
F_25 ( F_20 ( V_9 -> line , L_73 , V_9 -> line ) ) ;
F_14 ( V_9 ) ;
V_9 -> V_40 [ V_255 ] = ( V_9 -> V_256 &= ~ 0x40 ) ;
if ( V_9 -> V_73 ) {
F_17 ( V_9 ) ;
* V_9 -> V_185 = F_26 ( V_141 , V_142 , V_189 ) ;
V_9 -> V_73 = 0 ;
} else {
F_30 ( V_9 ) ;
}
if ( V_9 -> V_114 ) {
F_22 ( V_9 ) ;
V_9 -> V_123 = 0 ;
* V_9 -> V_140 = F_26 ( V_141 , V_142 , V_189 ) ;
V_9 -> V_114 = 0 ;
} else {
F_32 ( V_9 ) ;
V_9 -> V_123 = 0 ;
}
if ( ! ( V_9 -> V_11 . V_36 & V_251 ) )
return;
#ifdef F_103
F_5 ( L_74 , V_9 -> line ,
V_9 -> V_51 ) ;
#endif
F_9 ( V_36 ) ;
if ( V_9 -> V_101 . V_91 ) {
F_102 ( ( unsigned long ) V_9 -> V_101 . V_91 ) ;
V_9 -> V_101 . V_91 = NULL ;
}
for ( V_187 = 0 ; V_187 < V_167 ; V_187 ++ )
if ( V_120 [ V_187 ] . V_91 ) {
V_146 = F_61 ( V_120 [ V_187 ] . V_91 ) - sizeof *V_146 ;
F_81 ( V_146 ) ;
V_120 [ V_187 ] . V_91 = 0 ;
}
if ( ! V_9 -> V_11 . V_12 || ( V_9 -> V_11 . V_12 -> V_13 . V_14 & V_257 ) ) {
F_6 ( V_9 , 0 ) ;
F_11 ( V_9 , 0 ) ;
}
if ( V_9 -> V_11 . V_12 )
F_107 ( V_254 , & V_9 -> V_11 . V_12 -> V_36 ) ;
V_9 -> V_11 . V_36 &= ~ V_251 ;
F_10 ( V_36 ) ;
}
static void
F_105 ( struct V_8 * V_9 )
{
unsigned int V_24 ;
unsigned long V_100 ;
unsigned long V_36 ;
if ( ! V_9 -> V_11 . V_12 )
return;
if ( ! V_9 -> V_40 )
return;
V_24 = V_9 -> V_11 . V_12 -> V_13 . V_14 ;
if ( ( V_9 -> V_11 . V_36 & V_258 ) == V_259 ) {
T_3 V_32 = 0xFF << ( V_9 -> line * 8 ) ;
unsigned long V_260 =
F_26 ( V_261 , V_262 , V_263 ) |
F_26 ( V_261 , V_264 , V_263 ) ;
F_108 ( F_5 ( L_75 ,
( unsigned long ) V_9 -> V_265 , V_9 -> V_266 ) ) ;
if ( V_9 -> V_265 == V_267 ) {
T_4 V_268 = V_9 -> V_266 ;
V_260 =
F_26 ( V_261 , V_262 , V_269 ) |
F_26 ( V_261 , V_264 , V_269 ) ;
V_260 = 0x11 ;
F_108 ( F_5 ( L_76 , V_268 ) ) ;
* V_270 = V_268 ;
V_9 -> V_21 = V_267 / V_268 ;
}
#ifdef F_109
else if ( ( V_9 -> V_265 == V_271 / 8 &&
V_9 -> V_266 == 1 ) ||
( V_9 -> V_265 == V_271 &&
V_9 -> V_266 == 8 ) ) {
V_260 =
F_26 ( V_261 , V_262 , extern ) |
F_26 ( V_261 , V_264 , extern ) ;
F_108 ( F_5 ( L_77 , V_271 / 8 ) ) ;
V_9 -> V_21 = V_271 / 8 ;
}
#endif
else
{
F_5 ( V_30 L_78 ,
( unsigned long ) V_9 -> V_265 , V_9 -> V_266 ) ;
}
V_272 &= ~ V_32 ;
V_272 |= ( V_260 << ( V_9 -> line * 8 ) ) ;
* V_261 = V_272 ;
} else {
T_3 V_32 = 0xFF << ( V_9 -> line * 8 ) ;
unsigned long V_260 =
F_26 ( V_261 , V_262 , V_263 ) |
F_26 ( V_261 , V_264 , V_263 ) ;
V_272 &= ~ V_32 ;
V_272 |= ( V_260 << ( V_9 -> line * 8 ) ) ;
* V_261 = V_272 ;
V_9 -> V_21 = F_3 ( V_24 ) ;
V_9 -> V_40 [ V_273 ] = F_4 ( V_24 ) ;
}
F_9 ( V_36 ) ;
V_9 -> V_38 &= ~ ( F_15 ( V_48 , V_274 ) |
F_15 ( V_48 , V_275 ) |
F_15 ( V_48 , V_276 ) ) ;
V_9 -> V_256 &= ~ ( F_15 ( V_277 , V_278 ) |
F_15 ( V_277 , V_279 ) |
F_15 ( V_277 , V_280 ) |
F_15 ( V_277 , V_281 ) |
F_15 ( V_277 , V_282 ) ) ;
if ( ( V_24 & V_16 ) == V_17 ) {
V_9 -> V_256 |= F_26 ( V_277 , V_278 , V_283 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_274 , V_284 ) ;
}
if ( V_24 & V_18 ) {
V_9 -> V_256 |= F_26 ( V_277 , V_281 , V_285 ) ;
}
if ( V_24 & V_19 ) {
V_9 -> V_256 |= F_26 ( V_277 , V_279 , V_112 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_275 , V_112 ) ;
}
if ( V_24 & V_286 ) {
V_9 -> V_256 |= F_26 ( V_277 , V_287 , V_288 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_289 , V_288 ) ;
}
if ( V_24 & V_290 ) {
V_9 -> V_256 |= F_26 ( V_277 , V_280 , V_291 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_276 , V_291 ) ;
}
if ( V_24 & V_292 ) {
F_25 ( F_20 ( V_9 -> line , L_79 , 0 ) ) ;
V_9 -> V_256 |= F_26 ( V_277 , V_282 , V_293 ) ;
}
V_9 -> V_256 |= F_26 ( V_277 , V_294 , V_112 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_49 , V_112 ) ;
V_9 -> V_40 [ V_255 ] = V_9 -> V_256 ;
V_9 -> V_40 [ V_41 ] = V_9 -> V_38 ;
V_100 = F_45 ( V_105 , V_106 , F_46 ( V_9 -> V_11 . V_12 ) ) ;
V_100 |= F_26 ( V_105 , V_107 , V_112 ) ;
if ( V_9 -> V_11 . V_12 -> V_13 . V_109 & V_110 ) {
F_25 ( F_20 ( V_9 -> line , L_80 ,
F_46 ( V_9 -> V_11 . V_12 ) ) ) ;
V_100 |= F_26 ( V_105 , V_111 , V_112 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_113 ] ) = V_100 ;
F_10 ( V_36 ) ;
F_2 ( V_9 ) ;
}
static void
F_110 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( V_9 -> V_123 ||
V_9 -> V_101 . V_102 == V_9 -> V_101 . V_103 ||
V_12 -> V_233 ||
! V_9 -> V_101 . V_91 )
return;
#ifdef F_111
F_5 ( L_81 ) ;
#endif
F_9 ( V_36 ) ;
F_54 ( V_9 ) ;
F_10 ( V_36 ) ;
}
static int F_112 ( struct V_74 * V_12 ,
const unsigned char * V_91 , int V_92 )
{
int V_117 , V_163 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 -> V_101 . V_91 )
return 0 ;
#ifdef F_113
if ( V_9 -> line == V_122 )
F_5 ( L_82 ,
V_92 , V_9 -> V_40 [ V_172 ] ) ;
#endif
F_114 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_83 , V_92 ) ) ;
F_25 ( F_20 ( V_9 -> line , L_84 , V_12 -> V_295 . V_296 ( V_12 ) ) ) ;
F_95 () ;
while ( V_92 ) {
V_117 = F_115 ( V_9 -> V_101 . V_102 ,
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
V_163 += V_117 ;
}
F_10 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_85 , V_163 ) ) ;
if ( V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 &&
! V_12 -> V_233 &&
! V_9 -> V_123 ) {
F_54 ( V_9 ) ;
}
return V_163 ;
}
static int
F_41 ( struct V_74 * V_12 ,
const unsigned char * V_91 , int V_92 )
{
#if F_38 ( V_133 )
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 -> V_89 . V_36 & V_94 )
{
#ifdef V_134
V_96 [ V_9 -> line ] . V_97 = NULL ;
F_116 ( & V_96 [ V_9 -> line ] ) ;
#endif
F_11 ( V_9 , ( V_9 -> V_89 . V_36 & V_297 ) ) ;
#if F_38 ( V_99 )
F_14 ( V_9 ) ;
F_35 ( V_9 ) ;
#endif
if ( V_9 -> V_89 . V_90 > 0 )
F_117 ( V_9 -> V_89 . V_90 ) ;
}
#endif
V_92 = F_112 ( V_12 , V_91 , V_92 ) ;
#if F_38 ( V_133 )
if ( V_9 -> V_89 . V_36 & V_94 )
{
unsigned int V_298 ;
F_118 ( V_12 , 0 ) ;
#ifdef V_134
F_119 ( V_9 -> V_20 * 2 ) ;
#endif
do{
F_120 ( V_9 , & V_298 ) ;
}while ( ! ( V_298 & V_299 ) );
F_11 ( V_9 , ( V_9 -> V_89 . V_36 & V_98 ) ) ;
#if F_38 ( V_99 )
F_16 ( V_9 ) ;
F_21 ( V_9 ) ;
#endif
}
#endif
return V_92 ;
}
static int
F_121 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
return F_122 ( V_9 -> V_101 . V_102 , V_9 -> V_101 . V_103 , V_104 ) ;
}
static int
F_123 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
return F_44 ( V_9 -> V_101 . V_102 , V_9 -> V_101 . V_103 , V_104 ) ;
}
static void
F_124 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
V_9 -> V_101 . V_102 = V_9 -> V_101 . V_103 = 0 ;
F_10 ( V_36 ) ;
F_99 ( V_12 ) ;
}
static void F_125 ( struct V_74 * V_12 , char V_300 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( V_9 -> V_114 ) {
* V_9 -> V_140 = F_26 ( V_141 , V_142 , V_301 ) ;
while ( F_70 ( V_141 , V_142 , * V_9 -> V_140 ) !=
F_71 ( V_141 , V_142 , V_301 ) ) ;
F_24 ( V_9 ) ;
}
if ( V_12 -> V_233 )
F_47 ( V_12 ) ;
F_25 ( F_20 ( V_9 -> line , L_86 , V_300 ) ) ;
V_9 -> V_231 = V_300 ;
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
}
static void
F_126 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#ifdef F_127
char V_91 [ 64 ] ;
F_5 ( L_87 , F_128 ( V_12 , V_91 ) ,
( unsigned long ) V_12 -> V_295 . V_296 ( V_12 ) ) ;
#endif
F_25 ( F_20 ( V_9 -> line , L_88 , V_12 -> V_295 . V_296 ( V_12 ) ) ) ;
if ( V_12 -> V_13 . V_14 & V_292 ) {
F_11 ( V_9 , 0 ) ;
}
if ( F_129 ( V_12 ) )
F_125 ( V_12 , F_46 ( V_12 ) ) ;
}
static void
F_130 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#ifdef F_127
char V_91 [ 64 ] ;
F_5 ( L_89 , F_128 ( V_12 , V_91 ) ,
( unsigned long ) V_12 -> V_295 . V_296 ( V_12 ) ) ;
#endif
F_25 ( F_20 ( V_9 -> line , L_90 , V_12 -> V_295 . V_296 ( V_12 ) ) ) ;
F_25 ( F_20 ( V_9 -> line , L_91 , V_12 -> V_302 . V_92 ) ) ;
if ( V_12 -> V_13 . V_14 & V_292 ) {
F_11 ( V_9 , 1 ) ;
}
if ( F_129 ( V_12 ) ) {
if ( V_9 -> V_231 )
V_9 -> V_231 = 0 ;
else
F_125 ( V_12 , F_131 ( V_12 ) ) ;
}
}
static int
F_132 ( struct V_8 * V_9 ,
struct V_303 * V_304 )
{
struct V_303 V_305 ;
if ( ! V_304 )
return - V_306 ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
V_305 . type = V_9 -> type ;
V_305 . line = V_9 -> line ;
V_305 . V_11 = ( int ) V_9 -> V_40 ;
V_305 . V_51 = V_9 -> V_51 ;
V_305 . V_36 = V_9 -> V_11 . V_36 ;
V_305 . V_265 = V_9 -> V_265 ;
V_305 . V_307 = V_9 -> V_11 . V_307 ;
V_305 . V_308 = V_9 -> V_11 . V_308 ;
V_305 . V_266 = V_9 -> V_266 ;
if ( F_133 ( V_304 , & V_305 , sizeof( * V_304 ) ) )
return - V_306 ;
return 0 ;
}
static int
F_134 ( struct V_8 * V_9 ,
struct V_303 * V_309 )
{
struct V_303 V_310 ;
struct V_8 V_311 ;
int V_29 = 0 ;
if ( F_135 ( & V_310 , V_309 , sizeof( V_310 ) ) )
return - V_306 ;
V_311 = * V_9 ;
if ( ! F_136 ( V_312 ) ) {
if ( ( V_310 . type != V_9 -> type ) ||
( V_310 . V_307 != V_9 -> V_11 . V_307 ) ||
( ( V_310 . V_36 & ~ V_313 ) !=
( V_9 -> V_11 . V_36 & ~ V_313 ) ) )
return - V_314 ;
V_9 -> V_11 . V_36 = ( ( V_9 -> V_11 . V_36 & ~ V_313 ) |
( V_310 . V_36 & V_313 ) ) ;
goto V_315;
}
if ( V_9 -> V_11 . V_92 > 1 )
return - V_316 ;
V_9 -> V_265 = V_310 . V_265 ;
V_9 -> V_11 . V_36 = ( ( V_9 -> V_11 . V_36 & ~ V_317 ) |
( V_310 . V_36 & V_317 ) ) ;
V_9 -> V_266 = V_310 . V_266 ;
V_9 -> type = V_310 . type ;
V_9 -> V_11 . V_307 = V_310 . V_307 ;
V_9 -> V_11 . V_308 = V_310 . V_308 ;
V_9 -> V_11 . V_318 = ( V_9 -> V_11 . V_36 & V_319 ) ? 1 : 0 ;
V_315:
if ( V_9 -> V_11 . V_36 & V_251 ) {
F_105 ( V_9 ) ;
} else
V_29 = F_100 ( V_9 ) ;
return V_29 ;
}
static int
F_120 ( struct V_8 * V_9 , unsigned int * V_1 )
{
unsigned int V_320 = V_299 ;
unsigned long V_227 = V_5 ;
unsigned long V_321 = F_73 () ;
unsigned long V_228 =
( V_227 - V_9 -> V_199 ) * 1000000 / V_229 +
V_321 - V_9 -> V_198 ;
if ( V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 ||
V_228 < 2 * V_9 -> V_20 ) {
V_320 = 0 ;
}
if ( F_133 ( V_1 , & V_320 , sizeof( int ) ) )
return - V_306 ;
return 0 ;
}
char * F_137 ( int V_322 , char * V_323 )
{
int V_187 = 0 ;
V_323 [ 0 ] = '\0' ;
while ( V_324 [ V_187 ] . V_325 != NULL ) {
if ( V_322 & V_324 [ V_187 ] . V_326 ) {
if ( V_323 [ 0 ] != '\0' ) {
strcat ( V_323 , L_92 ) ;
}
strcat ( V_323 , V_324 [ V_187 ] . V_325 ) ;
}
V_187 ++ ;
}
return V_323 ;
}
static int
F_138 ( struct V_74 * V_12 , int V_327 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 -> V_40 )
return - V_328 ;
F_9 ( V_36 ) ;
if ( V_327 == - 1 ) {
V_9 -> V_256 &= 0x3F ;
} else {
V_9 -> V_256 |= ( 0x80 | 0x40 ) ;
}
V_9 -> V_40 [ V_255 ] = V_9 -> V_256 ;
F_10 ( V_36 ) ;
return 0 ;
}
static int
F_139 ( struct V_74 * V_12 , unsigned int V_31 , unsigned int V_329 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( V_329 & V_330 )
F_11 ( V_9 , 0 ) ;
if ( V_329 & V_331 )
F_6 ( V_9 , 0 ) ;
if ( V_329 & V_332 )
F_12 ( V_9 , 0 ) ;
if ( V_329 & V_333 )
F_13 ( V_9 , 0 ) ;
if ( V_31 & V_330 )
F_11 ( V_9 , 1 ) ;
if ( V_31 & V_331 )
F_6 ( V_9 , 1 ) ;
if ( V_31 & V_332 )
F_12 ( V_9 , 1 ) ;
if ( V_31 & V_333 )
F_13 ( V_9 , 1 ) ;
F_10 ( V_36 ) ;
return 0 ;
}
static int
F_140 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned int V_320 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
V_320 =
( ! F_141 ( V_9 ) ? V_330 : 0 )
| ( ! F_8 ( V_9 ) ? V_331 : 0 )
| ( ! F_142 ( V_9 ) ? V_334 : 0 )
| ( ! F_143 ( V_9 ) ? V_335 : 0 )
| ( ! F_144 ( V_9 ) ? V_336 : 0 )
| ( ! F_145 ( V_9 ) ? V_337 : 0 ) ;
F_10 ( V_36 ) ;
#ifdef F_7
F_5 ( V_338 L_93 ,
V_9 -> line , V_320 , V_320 ) ;
{
char V_323 [ 100 ] ;
F_137 ( V_320 , V_323 ) ;
F_5 ( V_338 L_94 , V_323 ) ;
}
#endif
return V_320 ;
}
static int
F_146 ( struct V_74 * V_12 ,
unsigned int V_142 , unsigned long V_339 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( ( V_142 != V_340 ) && ( V_142 != V_341 ) &&
( V_142 != V_342 ) && ( V_142 != V_343 ) &&
( V_142 != V_344 ) && ( V_142 != V_345 ) ) {
if ( V_12 -> V_36 & ( 1 << V_254 ) )
return - V_328 ;
}
switch ( V_142 ) {
case V_340 :
return F_132 ( V_9 ,
(struct V_303 * ) V_339 ) ;
case V_341 :
return F_134 ( V_9 ,
(struct V_303 * ) V_339 ) ;
case V_346 :
return F_120 ( V_9 , ( unsigned int * ) V_339 ) ;
case V_345 :
if ( F_133 ( (struct V_8 * ) V_339 ,
V_9 , sizeof( struct V_8 ) ) )
return - V_306 ;
return 0 ;
#if F_38 ( V_133 )
case V_347 :
{
struct V_348 V_349 ;
struct V_75 V_350 ;
F_5 ( V_338 L_95 ) ;
if ( F_135 ( & V_349 , (struct V_348 * ) V_339 ,
sizeof( V_349 ) ) )
return - V_306 ;
V_350 . V_90 = V_349 . V_90 ;
V_350 . V_36 = 0 ;
if ( V_349 . V_196 )
V_350 . V_36 |= V_94 ;
else
V_350 . V_36 &= ~ ( V_94 ) ;
if ( V_349 . V_351 )
V_350 . V_36 |= V_297 ;
else
V_350 . V_36 &= ~ ( V_297 ) ;
if ( V_349 . V_352 )
V_350 . V_36 |= V_98 ;
else
V_350 . V_36 &= ~ ( V_98 ) ;
return F_37 ( V_12 , & V_350 ) ;
}
case V_353 :
{
struct V_75 V_350 ;
if ( F_135 ( & V_350 , (struct V_348 * ) V_339 ,
sizeof( V_350 ) ) )
return - V_306 ;
return F_37 ( V_12 , & V_350 ) ;
}
case V_354 :
{
struct V_75 * V_350 =
& ( ( (struct V_8 * ) V_12 -> V_77 ) -> V_89 ) ;
if ( F_133 ( (struct V_75 * ) V_339 ,
V_350 ,
sizeof( struct V_75 ) ) )
return - V_306 ;
break;
}
case V_355 :
{
struct V_356 V_357 ;
if ( F_135 ( & V_357 , (struct V_356 * ) V_339 ,
sizeof( V_357 ) ) )
return - V_306 ;
return F_40 ( V_12 , V_357 . V_358 , V_357 . V_359 ) ;
}
#endif
default:
return - V_360 ;
}
return 0 ;
}
static void
F_147 ( struct V_74 * V_12 , struct V_361 * V_362 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
F_105 ( V_9 ) ;
if ( ( V_362 -> V_14 & V_292 ) &&
! ( V_12 -> V_13 . V_14 & V_292 ) )
F_47 ( V_12 ) ;
}
static void
F_148 ( struct V_74 * V_12 , struct V_363 * V_364 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 )
return;
F_9 ( V_36 ) ;
if ( F_149 ( V_364 ) ) {
F_10 ( V_36 ) ;
return;
}
#ifdef F_103
F_5 ( L_96 , V_365 -> V_366 ,
V_9 -> line , V_9 -> V_92 ) ;
#endif
if ( ( V_12 -> V_92 == 1 ) && ( V_9 -> V_11 . V_92 != 1 ) ) {
F_5 ( V_367
L_97
L_98 , V_9 -> V_11 . V_92 ) ;
V_9 -> V_11 . V_92 = 1 ;
}
if ( -- V_9 -> V_11 . V_92 < 0 ) {
F_5 ( V_367 L_99 ,
V_9 -> line , V_9 -> V_11 . V_92 ) ;
V_9 -> V_11 . V_92 = 0 ;
}
if ( V_9 -> V_11 . V_92 ) {
F_10 ( V_36 ) ;
return;
}
V_9 -> V_11 . V_36 |= V_368 ;
if ( V_9 -> V_11 . V_36 & V_369 )
V_9 -> V_370 = V_12 -> V_13 ;
V_12 -> V_371 = 1 ;
if ( V_9 -> V_11 . V_308 != V_372 )
F_118 ( V_12 , V_9 -> V_11 . V_308 ) ;
#ifdef F_65
F_30 ( V_9 ) ;
#endif
F_14 ( V_9 ) ;
F_36 ( V_9 ) ;
if ( V_9 -> V_11 . V_36 & V_251 ) {
F_150 ( V_12 , V_229 ) ;
}
F_106 ( V_9 ) ;
F_124 ( V_12 ) ;
F_151 ( V_12 ) ;
V_12 -> V_371 = 0 ;
V_9 -> V_115 = 0 ;
V_9 -> V_11 . V_12 = NULL ;
if ( V_9 -> V_11 . V_373 ) {
if ( V_9 -> V_11 . V_307 )
F_152 ( V_9 -> V_11 . V_307 ) ;
F_153 ( & V_9 -> V_11 . V_374 ) ;
}
V_9 -> V_11 . V_36 &= ~ ( V_369 | V_368 ) ;
F_153 ( & V_9 -> V_11 . V_375 ) ;
F_10 ( V_36 ) ;
#if F_38 ( V_133 )
if ( V_9 -> V_89 . V_36 & V_94 ) {
V_9 -> V_89 . V_36 &= ~ ( V_94 ) ;
#if F_38 ( V_78 )
* V_79 = V_80 &= ~ ( 1 << V_81 ) ;
#endif
#if F_38 ( V_82 )
F_39 ( V_83 , V_84 ,
V_85 , 0 ) ;
#endif
#if F_38 ( V_86 )
F_39 ( V_83 , V_84 ,
V_87 , 0 ) ;
F_39 ( V_83 , V_84 ,
V_88 , 0 ) ;
#endif
}
#endif
if ( V_9 -> V_252 ) {
F_154 ( V_9 -> V_376 , V_9 ) ;
F_155 ( V_9 -> V_377 , V_9 -> V_378 ) ;
V_9 -> V_73 = 0 ;
#ifdef F_103
F_5 ( V_338 L_100 ,
V_9 -> V_378 ) ;
#endif
}
if ( V_9 -> V_253 ) {
F_154 ( V_9 -> V_379 , V_9 ) ;
F_155 ( V_9 -> V_380 , V_9 -> V_381 ) ;
V_9 -> V_114 = 0 ;
#ifdef F_103
F_5 ( V_338 L_100 ,
V_9 -> V_381 ) ;
#endif
}
}
static void F_150 ( struct V_74 * V_12 , int V_382 )
{
unsigned long V_383 ;
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_227 = V_5 ;
unsigned long V_321 = F_73 () ;
long V_228 =
( V_227 - V_9 -> V_199 ) * ( 1000000 / V_229 ) +
V_321 - V_9 -> V_198 ;
V_383 = V_5 ;
while ( V_9 -> V_101 . V_102 != V_9 -> V_101 . V_103 ||
( * V_9 -> V_384 & 0x007f ) ||
( V_228 < 2 * V_9 -> V_20 ) ) {
F_152 ( 1 ) ;
if ( F_156 ( V_365 ) )
break;
if ( V_382 && F_157 ( V_5 , V_383 + V_382 ) )
break;
V_227 = V_5 ;
V_321 = F_73 () ;
V_228 =
( V_227 - V_9 -> V_199 ) * ( 1000000 / V_229 ) +
V_321 - V_9 -> V_198 ;
}
F_158 ( V_385 ) ;
}
void
F_159 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
F_124 ( V_12 ) ;
F_106 ( V_9 ) ;
V_9 -> V_115 = 0 ;
V_9 -> V_11 . V_92 = 0 ;
V_9 -> V_11 . V_36 &= ~ V_369 ;
V_9 -> V_11 . V_12 = NULL ;
F_153 ( & V_9 -> V_11 . V_374 ) ;
}
static int
F_160 ( struct V_74 * V_12 , struct V_363 * V_364 ,
struct V_8 * V_9 )
{
F_161 ( V_386 , V_365 ) ;
unsigned long V_36 ;
int V_29 ;
int V_387 = 0 , V_388 = 0 ;
if ( F_149 ( V_364 ) ||
( V_9 -> V_11 . V_36 & V_368 ) ) {
F_162 ( V_12 , V_9 -> V_11 . V_375 ,
! ( V_9 -> V_11 . V_36 & V_368 ) ) ;
#ifdef F_163
if ( V_9 -> V_11 . V_36 & V_389 )
return - V_390 ;
else
return - V_391 ;
#else
return - V_390 ;
#endif
}
if ( ( V_364 -> V_392 & V_393 ) ||
( V_12 -> V_36 & ( 1 << V_254 ) ) ) {
V_9 -> V_11 . V_36 |= V_369 ;
return 0 ;
}
if ( V_12 -> V_13 . V_14 & V_394 ) {
V_387 = 1 ;
}
V_29 = 0 ;
F_164 ( & V_9 -> V_11 . V_374 , & V_386 ) ;
#ifdef F_103
F_5 ( L_101 ,
V_9 -> line , V_9 -> V_11 . V_92 ) ;
#endif
F_9 ( V_36 ) ;
if ( ! F_149 ( V_364 ) ) {
V_388 ++ ;
V_9 -> V_11 . V_92 -- ;
}
F_10 ( V_36 ) ;
V_9 -> V_11 . V_373 ++ ;
while ( 1 ) {
F_9 ( V_36 ) ;
F_11 ( V_9 , 1 ) ;
F_6 ( V_9 , 1 ) ;
F_10 ( V_36 ) ;
F_158 ( V_395 ) ;
if ( F_149 ( V_364 ) ||
! ( V_9 -> V_11 . V_36 & V_251 ) ) {
#ifdef F_163
if ( V_9 -> V_11 . V_36 & V_389 )
V_29 = - V_390 ;
else
V_29 = - V_391 ;
#else
V_29 = - V_390 ;
#endif
break;
}
if ( ! ( V_9 -> V_11 . V_36 & V_368 ) && V_387 )
break;
if ( F_156 ( V_365 ) ) {
V_29 = - V_391 ;
break;
}
#ifdef F_103
F_5 ( L_102 ,
V_9 -> line , V_9 -> V_11 . V_92 ) ;
#endif
F_165 ( V_12 ) ;
F_166 () ;
F_167 ( V_12 ) ;
}
F_158 ( V_385 ) ;
F_168 ( & V_9 -> V_11 . V_374 , & V_386 ) ;
if ( V_388 )
V_9 -> V_11 . V_92 ++ ;
V_9 -> V_11 . V_373 -- ;
#ifdef F_103
F_5 ( L_103 ,
V_9 -> line , V_9 -> V_11 . V_92 ) ;
#endif
if ( V_29 )
return V_29 ;
V_9 -> V_11 . V_36 |= V_369 ;
return 0 ;
}
static void
F_169 ( struct V_8 * V_9 )
{
if ( V_9 -> V_253 ) {
F_155 ( V_9 -> V_380 , V_9 -> V_381 ) ;
F_154 ( V_9 -> V_379 , V_9 ) ;
}
if ( V_9 -> V_252 ) {
F_155 ( V_9 -> V_377 , V_9 -> V_378 ) ;
F_154 ( V_9 -> V_376 , V_9 ) ;
}
}
static int
F_170 ( struct V_74 * V_12 , struct V_363 * V_364 )
{
struct V_8 * V_9 ;
int V_29 ;
int V_396 = 0 ;
V_9 = V_195 + V_12 -> V_397 ;
if ( ! V_9 -> V_196 )
return - V_398 ;
#ifdef F_103
F_5 ( L_104 , V_365 -> V_366 , V_12 -> V_399 ,
V_9 -> V_11 . V_92 ) ;
#endif
V_9 -> V_11 . V_92 ++ ;
V_12 -> V_77 = V_9 ;
V_9 -> V_11 . V_12 = V_12 ;
V_9 -> V_11 . V_318 = ! ! ( V_9 -> V_11 . V_36 & V_319 ) ;
if ( F_149 ( V_364 ) ||
( V_9 -> V_11 . V_36 & V_368 ) ) {
F_162 ( V_12 , V_9 -> V_11 . V_375 ,
! ( V_9 -> V_11 . V_36 & V_368 ) ) ;
#ifdef F_163
return ( ( V_9 -> V_11 . V_36 & V_389 ) ?
- V_390 : - V_391 ) ;
#else
return - V_390 ;
#endif
}
if ( V_9 -> V_11 . V_92 == 1 ) {
V_396 = 1 ;
if ( V_9 -> V_252 ) {
if ( F_171 ( V_9 -> V_376 ,
F_75 ,
V_9 -> V_400 ,
V_9 -> V_378 ,
V_9 ) ) {
F_5 ( V_30 L_105
L_106 ,
V_9 -> V_378 ) ;
V_9 -> V_252 = 0 ;
} else if ( F_172 ( V_9 -> V_377 ,
V_9 -> V_378 ,
V_401 ,
V_9 -> V_402 ) ) {
F_154 ( V_9 -> V_376 , V_9 ) ;
F_5 ( V_30 L_107
L_106 ,
V_9 -> V_378 ) ;
V_9 -> V_252 = 0 ;
}
#ifdef F_103
else
F_5 ( V_338 L_108 ,
V_9 -> V_378 ) ;
#endif
}
if ( V_9 -> V_253 ) {
if ( F_171 ( V_9 -> V_379 ,
F_72 ,
V_9 -> V_403 ,
V_9 -> V_381 ,
V_9 ) ) {
F_5 ( V_30 L_105
L_106 ,
V_9 -> V_381 ) ;
V_9 -> V_253 = 0 ;
} else if ( F_172 ( V_9 -> V_380 ,
V_9 -> V_381 ,
V_401 ,
V_9 -> V_402 ) ) {
F_154 ( V_9 -> V_379 , V_9 ) ;
F_5 ( V_30 L_107
L_106 ,
V_9 -> V_381 ) ;
V_9 -> V_253 = 0 ;
}
#ifdef F_103
else
F_5 ( V_338 L_108 ,
V_9 -> V_381 ) ;
#endif
}
}
V_29 = F_100 ( V_9 ) ;
if ( V_29 ) {
if ( V_396 )
F_169 ( V_9 ) ;
return V_29 ;
}
V_29 = F_160 ( V_12 , V_364 , V_9 ) ;
if ( V_29 ) {
#ifdef F_103
F_5 ( L_109 ,
V_29 ) ;
#endif
if ( V_396 )
F_169 ( V_9 ) ;
return V_29 ;
}
if ( ( V_9 -> V_11 . V_92 == 1 ) && ( V_9 -> V_11 . V_36 & V_404 ) ) {
V_12 -> V_13 = V_9 -> V_370 ;
F_105 ( V_9 ) ;
}
#ifdef F_103
F_5 ( L_110 , V_9 -> line ) ;
#endif
F_89 ( V_405 = 0 ) ;
F_173 ( if (info->line == SERIAL_DEBUG_LINE) {
info->icount.rx = 0;
} ) ;
return 0 ;
}
static void F_174 ( struct V_406 * V_407 , struct V_8 * V_9 )
{
unsigned long V_305 ;
F_175 ( V_407 , L_111 ,
V_9 -> line , ( unsigned long ) V_9 -> V_40 , V_9 -> V_51 ) ;
if ( ! V_9 -> V_40 || ( V_9 -> type == V_408 ) ) {
F_175 ( V_407 , L_112 ) ;
return;
}
F_175 ( V_407 , L_113 , V_9 -> V_21 ) ;
F_175 ( V_407 , L_114 ,
( unsigned long ) V_9 -> V_129 . V_130 ,
( unsigned long ) V_9 -> V_129 . V_156 ) ;
V_305 = F_44 ( V_9 -> V_101 . V_102 , V_9 -> V_101 . V_103 , V_104 ) ;
if ( V_305 )
F_175 ( V_407 , L_115 ,
( unsigned long ) V_305 ,
( unsigned long ) V_104 ) ;
F_175 ( V_407 , L_116 ,
( unsigned long ) V_9 -> V_153 ,
( unsigned long ) V_9 -> V_154 ) ;
#if 1
if ( V_9 -> V_11 . V_12 ) {
if ( V_9 -> V_11 . V_12 -> V_233 )
F_175 ( V_407 , L_117 ,
( int ) V_9 -> V_11 . V_12 -> V_233 ) ;
}
{
unsigned char V_169 = V_9 -> V_40 [ V_172 ] ;
if ( V_169 & F_15 ( V_173 , V_174 ) )
F_175 ( V_407 , L_118 ) ;
}
#endif
if ( V_9 -> V_129 . V_221 )
F_175 ( V_407 , L_119 , ( unsigned long ) V_9 -> V_129 . V_221 ) ;
if ( V_9 -> V_129 . V_220 )
F_175 ( V_407 , L_120 , ( unsigned long ) V_9 -> V_129 . V_220 ) ;
if ( V_9 -> V_129 . V_224 )
F_175 ( V_407 , L_121 , ( unsigned long ) V_9 -> V_129 . V_224 ) ;
if ( V_9 -> V_129 . V_215 )
F_175 ( V_407 , L_122 , ( unsigned long ) V_9 -> V_129 . V_215 ) ;
if ( ! F_141 ( V_9 ) )
F_176 ( V_407 , L_123 ) ;
if ( ! F_145 ( V_9 ) )
F_176 ( V_407 , L_124 ) ;
if ( ! F_8 ( V_9 ) )
F_176 ( V_407 , L_125 ) ;
if ( ! F_143 ( V_9 ) )
F_176 ( V_407 , L_126 ) ;
if ( ! F_144 ( V_9 ) )
F_176 ( V_407 , L_127 ) ;
if ( ! F_142 ( V_9 ) )
F_176 ( V_407 , L_128 ) ;
F_176 ( V_407 , L_112 ) ;
}
static int F_177 ( struct V_406 * V_407 , void * V_409 )
{
int V_187 ;
F_175 ( V_407 , L_129 , V_410 ) ;
for ( V_187 = 0 ; V_187 < V_194 ; V_187 ++ ) {
if ( ! V_195 [ V_187 ] . V_196 )
continue;
F_174 ( V_407 , & V_195 [ V_187 ] ) ;
}
#ifdef F_178
for ( V_187 = 0 ; V_187 < V_2 ; V_187 ++ ) {
F_175 ( V_407 , L_130 ,
V_187 , V_4 [ V_187 ] . time ,
F_179 ( V_4 [ V_187 ] . V_6 ) ) ;
F_175 ( V_407 , V_4 [ V_187 ] . string , V_4 [ V_187 ] . V_1 ) ;
}
F_175 ( V_407 , L_131 , V_187 , V_3 ) ;
V_2 = 0 ;
#endif
return 0 ;
}
static int F_180 ( struct V_411 * V_411 , struct V_363 * V_363 )
{
return F_181 ( V_363 , F_177 , NULL ) ;
}
static void F_182 ( void )
{
F_5 ( V_412
L_132
L_133 ,
& V_410 [ 11 ] ) ;
}
static int T_5 F_183 ( void )
{
int V_187 ;
struct V_8 * V_9 ;
struct V_413 * V_414 = F_184 ( V_194 ) ;
if ( ! V_414 )
return - V_250 ;
F_182 () ;
#if ! F_38 ( V_415 )
F_185 ( & V_206 , F_86 , 0 ) ;
F_87 ( & V_206 , V_5 + 5 ) ;
#endif
#if F_38 ( V_133 )
#if F_38 ( V_78 )
if ( F_186 ( V_416 , 'a' , V_81 ,
V_81 ) ) {
F_5 ( V_367 L_134
L_135 ) ;
F_187 ( V_414 ) ;
return - V_316 ;
}
#endif
#if F_38 ( V_82 )
if ( F_186 ( V_416 , 'g' , V_81 ,
V_85 ) ) {
F_5 ( V_367 L_134
L_135 ) ;
F_187 ( V_414 ) ;
return - V_316 ;
}
#endif
#endif
V_414 -> V_417 = L_136 ;
V_414 -> V_399 = L_137 ;
V_414 -> V_418 = V_419 ;
V_414 -> V_420 = 64 ;
V_414 -> type = V_421 ;
V_414 -> V_422 = V_423 ;
V_414 -> V_424 = V_425 ;
V_414 -> V_424 . V_14 =
V_426 | V_427 | V_428 | V_257 | V_394 ;
V_414 -> V_424 . V_429 = 115200 ;
V_414 -> V_424 . V_430 = 115200 ;
V_414 -> V_36 = V_431 ;
F_188 ( V_414 , & V_432 ) ;
V_433 = V_414 ;
for ( V_187 = 0 , V_9 = V_195 ; V_187 < V_194 ; V_187 ++ , V_9 ++ ) {
if ( V_9 -> V_196 ) {
if ( F_189 ( V_9 -> V_434 ,
V_9 -> V_435 ) ) {
F_5 ( V_367 L_138
L_139
L_140 ,
V_9 -> V_435 , V_187 ) ;
V_9 -> V_196 = 0 ;
}
}
F_190 ( & V_9 -> V_11 ) ;
V_9 -> V_73 = 0 ;
V_9 -> V_114 = 0 ;
V_9 -> line = V_187 ;
V_9 -> V_11 . V_12 = NULL ;
V_9 -> type = V_436 ;
V_9 -> V_123 = 0 ;
V_9 -> V_201 = 0 ;
V_9 -> V_265 = V_437 ;
V_9 -> V_266 = 0 ;
V_9 -> V_231 = 0 ;
V_9 -> V_115 = 0 ;
V_9 -> V_370 = V_414 -> V_424 ;
V_9 -> V_101 . V_91 = NULL ;
V_9 -> V_101 . V_103 = V_9 -> V_101 . V_102 = 0 ;
V_9 -> V_151 = V_9 -> V_152 = NULL ;
V_9 -> V_153 = V_9 -> V_154 = 0 ;
V_9 -> V_198 = 0 ;
V_9 -> V_199 = 0 ;
#if F_38 ( V_133 )
V_9 -> V_89 . V_36 &= ~ ( V_297 ) ;
V_9 -> V_89 . V_36 |= V_98 ;
V_9 -> V_89 . V_90 = 0 ;
V_9 -> V_89 . V_36 &= ~ ( V_94 ) ;
#endif
F_191 ( & V_9 -> V_116 , F_96 ) ;
if ( V_9 -> V_196 ) {
F_5 ( V_412 L_141 ,
V_433 -> V_399 , V_9 -> line , V_9 -> V_40 ) ;
}
F_192 ( & V_9 -> V_11 , V_414 , V_187 ) ;
}
if ( F_193 ( V_414 ) )
F_62 ( L_142 ) ;
#ifdef V_134
#ifdef V_415
memset ( V_203 , 0 , sizeof( V_203 ) ) ;
#endif
#ifdef V_133
memset ( V_96 , 0 , sizeof( V_96 ) ) ;
#endif
F_194 () ;
#endif
#ifndef F_195
if ( F_171 ( V_438 , F_93 ,
V_439 , L_143 , V_414 ) )
F_62 ( L_144 , V_158 ) ;
#endif
return 0 ;
}
