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
V_9 -> V_82 = * V_76 ;
if ( V_9 -> V_82 . V_83 >= 1000 )
V_9 -> V_82 . V_83 = 1000 ;
return 0 ;
}
static int
F_39 ( struct V_74 * V_12 ,
const unsigned char * V_84 , int V_85 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
int V_86 = ( V_9 -> V_82 . V_36 ) & V_87 ;
V_9 -> V_82 . V_36 |= V_87 ;
V_85 = F_40 ( V_12 , V_84 , V_85 ) ;
if ( ! V_86 )
V_9 -> V_82 . V_36 &= ~ ( V_87 ) ;
return V_85 ;
}
static void F_41 ( unsigned long V_88 )
{
struct V_8 * V_9 = (struct V_8 * ) V_88 ;
V_89 [ V_9 -> line ] . V_90 = NULL ;
F_11 ( V_9 , ( V_9 -> V_82 . V_36 & V_91 ) ) ;
#if F_38 ( V_92 )
F_16 ( V_9 ) ;
F_35 ( V_9 ) ;
#endif
}
static void
F_42 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 ) {
unsigned long V_36 ;
unsigned long V_93 ;
F_9 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_25 ,
F_43 ( V_9 -> V_94 . V_95 ,
V_9 -> V_94 . V_96 , V_97 ) ) ) ;
V_93 = F_44 ( V_98 , V_99 ,
F_45 ( V_9 -> V_11 . V_12 ) ) ;
V_93 |= F_26 ( V_98 , V_100 , V_101 ) ;
if ( V_12 -> V_13 . V_102 & V_103 ) {
V_93 |= F_26 ( V_98 , V_104 , V_105 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_106 ] ) = V_93 ;
F_10 ( V_36 ) ;
}
}
static void
F_46 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 ) {
unsigned long V_36 ;
unsigned long V_93 ;
F_9 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_26 ,
F_43 ( V_9 -> V_94 . V_95 ,
V_9 -> V_94 . V_96 , V_97 ) ) ) ;
V_93 = F_44 ( V_98 , V_99 , F_45 ( V_12 ) ) ;
V_93 |= F_26 ( V_98 , V_100 , V_105 ) ;
if ( V_12 -> V_13 . V_102 & V_103 ) {
V_93 |= F_26 ( V_98 , V_104 , V_105 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_106 ] ) = V_93 ;
if ( ! V_9 -> V_107 &&
V_9 -> V_94 . V_95 != V_9 -> V_94 . V_96 && V_9 -> V_94 . V_84 )
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
}
}
static void F_47 ( struct V_8 * V_9 , int V_108 )
{
if ( V_9 -> V_108 & ( 1 << V_108 ) )
return;
V_9 -> V_108 |= 1 << V_108 ;
F_48 ( & V_9 -> V_109 ) ;
}
static void
F_49 ( struct V_8 * V_9 )
{
unsigned int V_110 , V_111 ;
struct V_112 * V_113 ;
* V_9 -> V_114 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
#ifdef F_18
if ( V_9 -> line == V_115 )
F_5 ( L_27 ) ;
#endif
if ( ! V_9 -> V_116 ) {
F_5 ( V_30 L_28 ) ;
return;
}
V_113 = & V_9 -> V_117 ;
if ( ! ( V_113 -> V_118 & V_119 ) ) {
V_111 = V_113 -> V_120 ;
} else
V_111 = V_113 -> V_121 ;
F_25 ( F_20 ( V_9 -> line , L_29 , V_111 ) ) ;
V_9 -> V_122 . V_123 += V_111 ;
V_9 -> V_94 . V_96 = ( V_9 -> V_94 . V_96 + V_111 ) & ( V_97 - 1 ) ;
if ( F_43 ( V_9 -> V_94 . V_95 ,
V_9 -> V_94 . V_96 ,
V_97 ) < V_124 )
F_47 ( V_9 , V_125 ) ;
V_110 = F_50 ( V_9 -> V_94 . V_95 , V_9 -> V_94 . V_96 , V_97 ) ;
if ( V_110 >= 4 * V_124 )
V_110 = V_110 / 2 ;
if ( V_110 <= 0 ) {
V_9 -> V_116 = 0 ;
#if F_38 ( V_126 ) && F_38 ( V_127 )
if ( V_9 -> V_82 . V_36 & V_87 ) {
F_51 ( & V_89 [ V_9 -> line ] ,
F_41 ,
( unsigned long ) V_9 ,
V_9 -> V_20 * 2 ,
L_30 ) ;
}
#endif
return;
}
F_25 ( F_20 ( V_9 -> line , L_31 , V_110 ) ) ;
V_113 -> V_128 = V_129 | V_130 | V_131 ;
V_113 -> V_120 = V_110 ;
V_113 -> V_84 = F_52 ( V_9 -> V_94 . V_84 + V_9 -> V_94 . V_96 ) ;
V_113 -> V_118 = 0 ;
* V_9 -> V_132 = F_52 ( V_113 ) ;
* V_9 -> V_133 = F_26 ( V_134 , V_135 , V_136 ) ;
}
static void
F_53 ( struct V_8 * V_9 )
{
#if 0
if (info->line == SERIAL_DEBUG_LINE)
printk("x\n");
#endif
V_9 -> V_117 . V_120 = 0 ;
V_9 -> V_117 . V_121 = 0 ;
V_9 -> V_117 . V_118 = 0 ;
V_9 -> V_116 = 1 ;
if ( V_9 -> V_107 )
F_49 ( V_9 ) ;
else
F_33 ( V_9 ) ;
}
static struct V_137 *
F_54 ( unsigned int V_138 )
{
struct V_137 * V_139 ;
V_139 = F_55 ( sizeof *V_139 + V_138 , V_140 ) ;
if ( ! V_139 )
return NULL ;
V_139 -> V_141 = NULL ;
V_139 -> V_142 = 0 ;
V_139 -> error = V_143 ;
return V_139 ;
}
static void
F_56 ( struct V_8 * V_9 , struct V_137 * V_139 )
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( ! V_9 -> V_144 )
V_9 -> V_144 = V_139 ;
else
V_9 -> V_145 -> V_141 = V_139 ;
V_9 -> V_145 = V_139 ;
V_9 -> V_146 += V_139 -> V_142 ;
if ( V_9 -> V_146 > V_9 -> V_147 )
V_9 -> V_147 = V_9 -> V_146 ;
F_10 ( V_36 ) ;
}
static int
F_57 ( struct V_8 * V_9 , unsigned char V_88 , unsigned char V_148 )
{
struct V_137 * V_139 ;
if ( V_9 -> V_73 ) {
V_139 = F_54 ( 4 ) ;
if ( ! V_139 )
return 0 ;
V_139 -> V_142 = 1 ;
V_139 -> error = V_148 ;
V_139 -> V_139 [ 0 ] = V_88 ;
F_56 ( V_9 , V_139 ) ;
V_9 -> V_122 . V_149 ++ ;
} else {
F_58 ( & V_9 -> V_11 , V_88 , V_148 ) ;
V_9 -> V_122 . V_149 ++ ;
}
return 1 ;
}
static unsigned int F_59 ( struct V_8 * V_9 ,
struct V_112 * V_113 ,
unsigned int V_150 )
{
struct V_137 * V_139 = F_60 ( V_113 -> V_84 ) - sizeof *V_139 ;
if ( V_9 -> V_146 + V_150 > 65536 ) {
F_5 ( V_30
L_32 , V_151 , V_150 ) ;
return 0 ;
}
V_139 -> V_142 = V_150 ;
if ( V_9 -> V_152 == V_153 )
V_139 -> error = V_154 ;
V_9 -> V_152 = 0 ;
F_56 ( V_9 , V_139 ) ;
V_139 = F_54 ( V_155 ) ;
if ( ! V_139 )
F_61 ( L_33 , V_151 ) ;
V_113 -> V_84 = F_52 ( V_139 -> V_139 ) ;
return V_150 ;
}
static unsigned int F_62 ( struct V_8 * V_9 )
{
struct V_112 * V_113 ;
unsigned int V_150 ;
unsigned int V_156 = 0 ;
while ( 1 )
{
V_113 = & V_9 -> V_157 [ V_9 -> V_158 ] ;
if ( V_113 == F_60 ( * V_9 -> V_159 ) )
break;
if ( ++ V_9 -> V_158 == V_160 )
V_9 -> V_158 = 0 ;
if ( ! ( V_113 -> V_118 & V_161 ) ) {
V_150 = V_113 -> V_120 ;
} else {
V_150 = V_113 -> V_121 ;
}
V_113 -> V_118 = 0 ;
F_25 ( DEBUG_LOG(info->line, L_34, recvl);
if (info->port.tty->stopped) {
unsigned char *buf = phys_to_virt(descr->buf);
DEBUG_LOG(info->line, L_35, buf[0]);
DEBUG_LOG(info->line, L_35, buf[1]);
DEBUG_LOG(info->line, L_35, buf[2]);
}
) ;
V_9 -> V_122 . V_149 += V_150 ;
V_156 += F_59 ( V_9 , V_113 , V_150 ) ;
}
return V_156 ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_74 * V_12 ;
unsigned char V_162 ;
* V_9 -> V_163 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 )
return;
#ifdef F_64
if ( V_9 -> V_73 )
F_31 ( V_9 ) ;
#endif
if ( V_9 -> V_152 == V_164 )
F_57 ( V_9 , '\0' , V_154 ) ;
F_62 ( V_9 ) ;
V_162 = V_9 -> V_40 [ V_165 ] ;
if ( V_162 & F_15 ( V_166 , V_167 ) ) {
F_25 ( F_20 ( V_9 -> line , L_36 , V_162 ) ) ;
}
if ( V_162 & V_168 ) {
unsigned char V_88 = V_9 -> V_40 [ V_169 ] ;
F_20 ( V_9 -> line , L_37 ,
( ( V_162 & V_168 ) << 8 ) | V_88 ) ;
if ( V_162 & V_170 )
F_57 ( V_9 , V_88 , V_171 ) ;
else if ( V_162 & V_172 )
F_57 ( V_9 , V_88 , V_173 ) ;
else if ( V_162 & V_174 )
F_57 ( V_9 , V_88 , V_175 ) ;
}
F_65 ( V_9 , L_38 ) ;
* V_9 -> V_176 = F_26 ( V_134 , V_135 , V_177 ) ;
}
static int F_66 ( struct V_8 * V_9 )
{
struct V_112 * V_113 = V_9 -> V_157 ;
struct V_137 * V_139 ;
int V_178 ;
for ( V_178 = 0 ; V_178 < V_160 ; V_178 ++ ) {
V_139 = F_54 ( V_155 ) ;
if ( ! V_139 )
F_61 ( L_33 , V_151 ) ;
V_113 [ V_178 ] . V_128 = V_129 ;
V_113 [ V_178 ] . V_84 = F_52 ( V_139 -> V_139 ) ;
V_113 [ V_178 ] . V_120 = V_155 ;
V_113 [ V_178 ] . V_121 = 0 ;
V_113 [ V_178 ] . V_118 = 0 ;
V_113 [ V_178 ] . V_141 = F_52 ( & V_113 [ V_178 + 1 ] ) ;
}
V_113 [ V_178 - 1 ] . V_141 = F_52 ( & V_113 [ 0 ] ) ;
V_9 -> V_158 = 0 ;
* V_9 -> V_179 = F_52 ( & V_113 [ V_9 -> V_158 ] ) ;
* V_9 -> V_176 = F_26 ( V_134 , V_135 , V_136 ) ;
return 1 ;
}
static void
F_67 ( struct V_8 * V_9 )
{
if ( V_9 -> V_73 ) {
* V_9 -> V_176 = F_26 ( V_134 , V_135 , V_180 ) ;
while ( F_68 ( V_134 , V_135 , * V_9 -> V_176 ) ==
F_69 ( V_134 , V_135 , V_180 ) ) ;
F_66 ( V_9 ) ;
}
}
static T_2
F_70 ( int V_51 , void * V_181 )
{
struct V_8 * V_9 ;
unsigned long V_182 ;
int V_178 ;
int V_183 = 0 ;
V_182 = * V_184 ;
for ( V_178 = 0 ; V_178 < V_185 ; V_178 ++ ) {
V_9 = V_186 + V_178 ;
if ( ! V_9 -> V_187 || ! V_9 -> V_107 )
continue;
if ( V_182 & V_9 -> V_51 ) {
V_183 = 1 ;
F_34 ( F_20 ( V_9 -> line , L_39 , V_178 ) ) ;
V_9 -> V_188 = F_71 () ;
V_9 -> V_189 = V_5 ;
F_49 ( V_9 ) ;
}
}
return F_72 ( V_183 ) ;
}
static T_2
F_73 ( int V_51 , void * V_181 )
{
struct V_8 * V_9 ;
unsigned long V_182 ;
int V_178 ;
int V_183 = 0 ;
V_182 = * V_184 ;
for ( V_178 = 0 ; V_178 < V_185 ; V_178 ++ ) {
V_9 = V_186 + V_178 ;
if ( ! V_9 -> V_187 || ! V_9 -> V_73 )
continue;
if ( V_182 & ( ( V_9 -> V_51 << 2 ) | ( V_9 -> V_51 << 3 ) ) ) {
V_183 = 1 ;
F_63 ( V_9 ) ;
}
}
return F_72 ( V_183 ) ;
}
static int F_74 ( struct V_8 * V_9 )
{
unsigned char V_162 = V_9 -> V_40 [ V_165 ] ;
if ( V_162 & V_168 ) {
F_20 ( V_9 -> line , L_40 ,
V_162 | ( V_9 -> line << 8 ) ) ;
return 0 ;
}
if ( V_162 & V_190 ) {
F_75 ( F_20 ( V_9 -> line , L_41 ,
V_162 | ( V_9 -> line << 8 ) ) ) ;
( void ) V_9 -> V_40 [ V_169 ] ;
V_9 -> V_191 = 0 ;
F_65 ( V_9 , L_42 ) ;
return 0 ;
}
if ( ! V_9 -> V_191 ) {
V_9 -> V_191 = 1 ;
F_75 ( F_20 ( V_9 -> line , L_43 , V_9 -> line ) ) ;
F_76 ( V_9 ) ;
}
return 1 ;
}
static void F_77 ( struct V_8 * V_9 )
{
struct V_137 * V_139 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
while ( ( V_139 = V_9 -> V_144 ) != NULL ) {
unsigned int V_85 = V_139 -> V_142 ;
F_78 ( & V_9 -> V_11 , V_139 -> V_139 , V_85 ) ;
V_9 -> V_146 -= V_85 ;
if ( V_85 == V_139 -> V_142 ) {
V_9 -> V_144 = V_139 -> V_141 ;
F_79 ( V_139 ) ;
} else {
V_139 -> V_142 -= V_85 ;
memmove ( V_139 -> V_139 , V_139 -> V_139 + V_85 , V_139 -> V_142 ) ;
V_139 -> error = V_143 ;
}
}
if ( ! V_9 -> V_144 )
V_9 -> V_145 = NULL ;
F_10 ( V_36 ) ;
F_80 ( & V_9 -> V_11 ) ;
}
static void F_81 ( struct V_8 * V_9 )
{
F_77 ( V_9 ) ;
if ( V_9 -> V_144 )
F_82 ( V_9 , L_44 , 2000 ) ;
F_74 ( V_9 ) ;
}
static void F_83 ( unsigned long V_88 )
{
struct V_8 * V_9 = (struct V_8 * ) V_88 ;
V_192 [ V_9 -> line ] . V_90 = NULL ;
V_193 ++ ;
F_75 ( F_20 ( V_9 -> line , L_45 , V_9 -> line ) ) ;
F_75 ( F_20 ( V_9 -> line , L_46 , V_193 ) ) ;
F_81 ( V_9 ) ;
}
static void
F_84 ( unsigned long V_194 )
{
struct V_8 * V_9 ;
int V_178 ;
for ( V_178 = 0 ; V_178 < V_185 ; V_178 ++ ) {
V_9 = V_186 + V_178 ;
if ( V_9 -> V_73 )
F_81 ( V_9 ) ;
}
F_85 ( & V_195 , V_5 + V_196 ) ;
}
static void F_86 ( struct V_8 * V_9 )
{
unsigned long V_197 ;
V_197 = * ( ( unsigned long * ) & V_9 -> V_40 [ V_198 ] ) ;
V_199:
if ( V_197 & F_15 ( V_200 , V_167 ) ) {
F_25 ( F_20 ( V_9 -> line , L_47 , 0 ) ) ;
}
F_34 ( F_20 ( V_9 -> line , L_48 , F_68 ( V_200 , V_201 , V_197 ) ) ) ;
if ( V_197 & ( F_15 ( V_200 , V_202 ) |
F_15 ( V_200 , V_203 ) |
F_15 ( V_200 , V_204 ) ) ) {
V_9 -> V_205 = F_71 () ;
V_9 -> V_206 = V_5 ;
F_19 ( F_20 ( V_9 -> line , L_49 , V_197 ) ) ;
F_87 (
if (!log_int_trig1_pos) {
log_int_trig1_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
) ;
if ( ( ( V_197 & F_15 ( V_200 , V_201 ) ) == 0 ) &&
( V_197 & F_15 ( V_200 , V_202 ) ) ) {
if ( ! V_9 -> V_207 ) {
F_20 ( V_9 -> line , L_50 , 0 ) ;
}
if ( V_197 & F_15 ( V_200 , V_208 ) ) {
F_20 ( V_9 -> line , L_51 , 0 ) ;
V_9 -> V_152 = V_164 ;
}
V_9 -> V_207 ++ ;
} else {
if ( V_9 -> V_207 ) {
F_20 ( V_9 -> line , L_52 , V_9 -> V_207 ) ;
V_9 -> V_152 = V_164 ;
} else {
unsigned char V_88 = F_68 ( V_200 ,
V_201 , V_197 ) ;
char V_148 = V_143 ;
if ( V_9 -> V_152 == V_164 ) {
F_58 ( & V_9 -> V_11 , 0 , V_148 ) ;
V_9 -> V_122 . V_149 ++ ;
}
if ( V_197 & F_15 ( V_200 , V_203 ) ) {
V_9 -> V_122 . V_209 ++ ;
V_148 = V_171 ;
} else if ( V_197 & F_15 ( V_200 , V_204 ) ) {
V_9 -> V_122 . V_204 ++ ;
V_148 = V_173 ;
} else if ( V_197 & F_15 ( V_200 , V_202 ) ) {
V_9 -> V_122 . V_210 ++ ;
V_148 = V_175 ;
}
F_58 ( & V_9 -> V_11 , V_88 , V_148 ) ;
V_9 -> V_152 = 0 ;
}
V_9 -> V_207 = 0 ;
}
} else if ( V_197 & F_15 ( V_200 , V_211 ) ) {
F_87 (
if (!log_int_trig1_pos) {
if (log_int_pos >= log_int_size) {
log_int_pos = 0;
}
log_int_trig0_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
) ;
F_58 ( & V_9 -> V_11 ,
F_68 ( V_200 , V_201 , V_197 ) ,
V_143 ) ;
} else {
F_20 ( V_9 -> line , L_53 , V_197 ) ;
}
V_9 -> V_122 . V_149 ++ ;
V_197 = * ( ( unsigned long * ) & V_9 -> V_40 [ V_198 ] ) ;
if ( V_197 & F_15 ( V_200 , V_211 ) ) {
F_20 ( V_9 -> line , L_54 , F_68 ( V_200 , V_201 , V_197 ) ) ;
goto V_199;
}
F_80 ( & V_9 -> V_11 ) ;
}
static void F_88 ( struct V_8 * V_9 )
{
unsigned char V_162 ;
#ifdef F_18
F_5 ( L_55 , V_178 ) ;
#endif
if ( ! V_9 -> V_73 ) {
F_86 ( V_9 ) ;
return;
}
V_162 = V_9 -> V_40 [ V_165 ] ;
if ( V_162 & F_15 ( V_166 , V_167 ) ) {
F_25 ( F_20 ( V_9 -> line , L_47 , 0 ) ) ;
}
if ( V_162 & V_168 ) {
unsigned char V_88 ;
V_9 -> V_205 = F_71 () ;
V_9 -> V_206 = V_5 ;
V_88 = V_9 -> V_40 [ V_169 ] ;
F_19 ( F_20 ( V_9 -> line , L_56 , V_88 ) ) ;
F_19 ( F_20 ( V_9 -> line , L_57 , V_162 ) ) ;
if ( ! V_88 && ( V_162 & V_174 ) ) {
if ( ! V_9 -> V_207 ) {
F_20 ( V_9 -> line , L_50 , 0 ) ;
}
if ( V_162 & V_212 ) {
F_20 ( V_9 -> line , L_51 , 0 ) ;
V_9 -> V_152 = V_164 ;
}
V_9 -> V_207 ++ ;
} else {
if ( V_9 -> V_207 ) {
F_20 ( V_9 -> line , L_52 , V_9 -> V_207 ) ;
V_9 -> V_152 = V_164 ;
} else {
if ( V_9 -> V_152 == V_164 ) {
V_9 -> V_122 . V_213 ++ ;
F_57 ( V_9 , '\0' , V_154 ) ;
}
if ( V_162 & V_170 ) {
V_9 -> V_122 . V_209 ++ ;
F_57 ( V_9 , V_88 , V_171 ) ;
} else if ( V_162 & V_172 ) {
V_9 -> V_122 . V_204 ++ ;
F_57 ( V_9 , V_88 , V_173 ) ;
} else if ( V_162 & V_174 ) {
V_9 -> V_122 . V_210 ++ ;
F_57 ( V_9 , V_88 , V_175 ) ;
}
V_9 -> V_152 = 0 ;
}
V_9 -> V_207 = 0 ;
F_20 ( V_9 -> line , L_58 ,
( ( V_162 & V_168 ) << 8 ) | V_88 ) ;
}
} else {
unsigned long V_214 = F_71 () ;
unsigned long V_215 = V_5 ;
if ( V_9 -> V_207 ) {
long V_216 =
( V_215 - V_9 -> V_206 ) * ( 1000000 / V_217 ) +
V_214 - V_9 -> V_205 ;
if ( V_216 < 2 * V_9 -> V_20 ) {
F_20 ( V_9 -> line , L_59 , V_9 -> line ) ;
V_9 -> V_152 = V_153 ;
} else {
F_20 ( V_9 -> line , L_60 , V_9 -> line ) ;
}
F_20 ( V_9 -> line , L_61 , V_9 -> V_207 ) ;
}
#ifdef F_18
F_5 ( L_62 ) ;
#endif
F_30 ( V_9 ) ;
F_34 ( F_20 ( V_9 -> line , L_63 , V_9 -> line ) ) ;
V_9 -> V_207 = 0 ;
}
* V_9 -> V_176 = F_26 ( V_134 , V_135 , V_177 ) ;
F_65 ( V_9 , L_64 ) ;
}
static void F_89 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
if ( V_9 -> V_218 ) {
unsigned char V_162 ;
F_25 ( F_20 ( V_9 -> line , L_65 , V_9 -> V_218 ) ) ;
F_9 ( V_36 ) ;
V_162 = V_9 -> V_40 [ V_165 ] ;
F_25 ( F_20 ( V_9 -> line , L_66 , V_162 ) ) ;
V_9 -> V_40 [ V_219 ] = V_9 -> V_218 ;
V_9 -> V_122 . V_123 ++ ;
V_9 -> V_218 = 0 ;
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
return;
}
if ( V_9 -> V_107 ) {
unsigned char V_162 ;
int V_178 ;
F_25 ( F_20 ( V_9 -> line , L_67 , 0 ) ) ;
F_9 ( V_36 ) ;
V_162 = V_9 -> V_40 [ V_165 ] ;
F_25 ( F_20 ( V_9 -> line , L_66 , V_162 ) ) ;
F_32 ( V_9 ) ;
if ( V_9 -> V_11 . V_12 -> V_220 )
F_42 ( V_9 -> V_11 . V_12 ) ;
F_27 ( V_9 ) ;
for( V_178 = 6 ; V_178 > 0 ; V_178 -- )
F_90 () ;
* V_9 -> V_133 = F_26 (R_DMA_CH6_CMD, cmd, continue) ;
F_10 ( V_36 ) ;
return;
}
if ( V_9 -> V_94 . V_95 == V_9 -> V_94 . V_96
|| V_9 -> V_11 . V_12 -> V_220 ) {
F_25 ( F_20 ( V_9 -> line , L_68 ,
V_9 -> V_11 . V_12 -> V_220 ) ) ;
F_32 ( V_9 ) ;
V_9 -> V_116 = 0 ;
return;
}
F_34 ( F_20 ( V_9 -> line , L_69 , V_9 -> V_94 . V_84 [ V_9 -> V_94 . V_96 ] ) ) ;
F_9 ( V_36 ) ;
V_9 -> V_40 [ V_219 ] = V_9 -> V_94 . V_84 [ V_9 -> V_94 . V_96 ] ;
V_9 -> V_94 . V_96 = ( V_9 -> V_94 . V_96 + 1 ) & ( V_97 - 1 ) ;
V_9 -> V_122 . V_123 ++ ;
if ( V_9 -> V_94 . V_95 == V_9 -> V_94 . V_96 ) {
#if F_38 ( V_126 ) && F_38 ( V_127 )
if ( V_9 -> V_82 . V_36 & V_87 ) {
F_51 ( & V_89 [ V_9 -> line ] ,
F_41 ,
( unsigned long ) V_9 ,
V_9 -> V_20 * 2 ,
L_30 ) ;
}
#endif
V_9 -> V_188 = F_71 () ;
V_9 -> V_189 = V_5 ;
F_32 ( V_9 ) ;
V_9 -> V_116 = 0 ;
F_25 ( F_20 ( V_9 -> line , L_70 , 0 ) ) ;
} else {
F_33 ( V_9 ) ;
}
F_10 ( V_36 ) ;
if ( F_43 ( V_9 -> V_94 . V_95 ,
V_9 -> V_94 . V_96 ,
V_97 ) < V_124 )
F_47 ( V_9 , V_125 ) ;
}
static T_2
F_91 ( int V_51 , void * V_181 )
{
static volatile int V_221 = 0 ;
struct V_8 * V_9 ;
int V_178 ;
unsigned long V_36 ;
unsigned long V_222 ;
unsigned long V_223 = ( 1 << ( 8 + 2 * 0 ) ) ;
int V_183 = 0 ;
static volatile unsigned long V_224 = 0 ;
F_9 ( V_36 ) ;
V_222 = * V_225 ;
V_9 = V_186 ;
V_222 &= V_226 ;
for ( V_178 = 0 ; V_178 < V_185 ; V_178 ++ ) {
if ( V_222 & V_223 ) {
V_183 = 1 ;
F_88 ( V_9 ) ;
}
V_9 += 1 ;
V_223 <<= 2 ;
}
if ( ! V_221 ) {
unsigned long V_227 ;
unsigned long
V_221 = 1 ;
V_222 &= ( F_15 ( V_225 , V_228 ) |
F_15 ( V_225 , V_229 ) |
F_15 ( V_225 , V_230 ) |
F_15 ( V_225 , V_231 ) ) ;
while ( V_222 ) {
* V_71 = V_222 ;
* V_232 = F_26 ( V_232 , V_233 , V_31 ) ;
F_92 () ;
V_227 = ( 1 << ( 8 + 1 + 2 * 0 ) ) ;
V_9 = V_186 ;
for ( V_178 = 0 ; V_178 < V_185 ; V_178 ++ ) {
if ( V_222 & V_227 ) {
V_183 = 1 ;
F_89 ( V_9 ) ;
}
V_9 += 1 ;
V_227 <<= 2 ;
}
F_93 () ;
V_222 = V_224 ;
}
F_93 () ;
V_221 = 0 ;
} else {
unsigned long V_227 ;
V_227 = V_222 & ( F_15 ( V_225 , V_228 ) |
F_15 ( V_225 , V_229 ) |
F_15 ( V_225 , V_230 ) |
F_15 ( V_225 , V_231 ) ) ;
if ( V_227 ) {
V_224 |= V_227 ;
* V_71 = V_227 ;
F_25 ( F_20 ( V_115 , L_71 , V_227 ) ) ;
}
}
F_10 ( V_36 ) ;
return F_72 ( V_183 ) ;
}
static void
F_94 ( struct V_234 * V_109 )
{
struct V_8 * V_9 ;
struct V_74 * V_12 ;
V_9 = F_95 ( V_109 , struct V_8 , V_109 ) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 )
return;
if ( F_96 ( V_125 , & V_9 -> V_108 ) )
F_97 ( V_12 ) ;
}
static int
F_98 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
unsigned long V_235 ;
int V_178 ;
V_235 = F_99 ( V_236 ) ;
if ( ! V_235 )
return - V_237 ;
F_9 ( V_36 ) ;
if ( V_9 -> V_11 . V_36 & V_238 ) {
F_10 ( V_36 ) ;
F_100 ( V_235 ) ;
return 0 ;
}
if ( V_9 -> V_94 . V_84 )
F_100 ( V_235 ) ;
else
V_9 -> V_94 . V_84 = ( unsigned char * ) V_235 ;
#ifdef F_101
F_5 ( L_72 , V_9 -> line , V_9 -> V_94 . V_84 ) ;
#endif
if ( V_9 -> V_239 ) {
V_9 -> V_73 = 1 ;
F_29 ( V_9 ) ;
* V_9 -> V_176 = F_26 ( V_134 , V_135 , V_180 ) ;
while ( F_68 ( V_134 , V_135 , * V_9 -> V_176 ) ==
F_69 ( V_134 , V_135 , V_180 ) ) ;
* V_9 -> V_163 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
} else {
F_28 ( V_9 ) ;
}
if ( V_9 -> V_240 ) {
V_9 -> V_107 = 1 ;
F_27 ( V_9 ) ;
* V_9 -> V_133 = F_26 ( V_134 , V_135 , V_180 ) ;
while ( F_68 ( V_134 , V_135 , * V_9 -> V_133 ) ==
F_69 ( V_134 , V_135 , V_180 ) ) ;
* V_9 -> V_114 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
} else {
F_24 ( V_9 ) ;
}
if ( V_9 -> V_11 . V_12 )
F_102 ( V_241 , & V_9 -> V_11 . V_12 -> V_36 ) ;
V_9 -> V_94 . V_95 = V_9 -> V_94 . V_96 = 0 ;
V_9 -> V_144 = V_9 -> V_145 = NULL ;
V_9 -> V_146 = V_9 -> V_147 = 0 ;
for ( V_178 = 0 ; V_178 < V_160 ; V_178 ++ )
V_9 -> V_157 [ V_178 ] . V_84 = 0 ;
#ifdef F_64
F_31 ( V_9 ) ;
#endif
F_103 ( V_9 ) ;
( void ) V_9 -> V_40 [ V_169 ] ;
if ( V_9 -> V_107 )
F_23 ( V_9 ) ;
F_35 ( V_9 ) ;
V_9 -> V_116 = 0 ;
F_67 ( V_9 ) ;
V_9 -> V_117 . V_120 = 0 ;
V_9 -> V_117 . V_121 = 0 ;
V_9 -> V_117 . V_118 = 0 ;
F_11 ( V_9 , 1 ) ;
F_6 ( V_9 , 1 ) ;
V_9 -> V_11 . V_36 |= V_238 ;
F_10 ( V_36 ) ;
return 0 ;
}
static void
F_104 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
struct V_112 * V_113 = V_9 -> V_157 ;
struct V_137 * V_139 ;
int V_178 ;
F_25 ( F_20 ( V_9 -> line , L_73 , V_9 -> line ) ) ;
F_14 ( V_9 ) ;
V_9 -> V_40 [ V_242 ] = ( V_9 -> V_243 &= ~ 0x40 ) ;
if ( V_9 -> V_73 ) {
F_17 ( V_9 ) ;
* V_9 -> V_176 = F_26 ( V_134 , V_135 , V_180 ) ;
V_9 -> V_73 = 0 ;
} else {
F_30 ( V_9 ) ;
}
if ( V_9 -> V_107 ) {
F_22 ( V_9 ) ;
V_9 -> V_116 = 0 ;
* V_9 -> V_133 = F_26 ( V_134 , V_135 , V_180 ) ;
V_9 -> V_107 = 0 ;
} else {
F_32 ( V_9 ) ;
V_9 -> V_116 = 0 ;
}
if ( ! ( V_9 -> V_11 . V_36 & V_238 ) )
return;
#ifdef F_101
F_5 ( L_74 , V_9 -> line ,
V_9 -> V_51 ) ;
#endif
F_9 ( V_36 ) ;
if ( V_9 -> V_94 . V_84 ) {
F_100 ( ( unsigned long ) V_9 -> V_94 . V_84 ) ;
V_9 -> V_94 . V_84 = NULL ;
}
for ( V_178 = 0 ; V_178 < V_160 ; V_178 ++ )
if ( V_113 [ V_178 ] . V_84 ) {
V_139 = F_60 ( V_113 [ V_178 ] . V_84 ) - sizeof *V_139 ;
F_79 ( V_139 ) ;
V_113 [ V_178 ] . V_84 = 0 ;
}
if ( ! V_9 -> V_11 . V_12 || ( V_9 -> V_11 . V_12 -> V_13 . V_14 & V_244 ) ) {
F_6 ( V_9 , 0 ) ;
F_11 ( V_9 , 0 ) ;
}
if ( V_9 -> V_11 . V_12 )
F_105 ( V_241 , & V_9 -> V_11 . V_12 -> V_36 ) ;
V_9 -> V_11 . V_36 &= ~ V_238 ;
F_10 ( V_36 ) ;
}
static void
F_103 ( struct V_8 * V_9 )
{
unsigned int V_24 ;
unsigned long V_93 ;
unsigned long V_36 ;
if ( ! V_9 -> V_11 . V_12 )
return;
if ( ! V_9 -> V_40 )
return;
V_24 = V_9 -> V_11 . V_12 -> V_13 . V_14 ;
if ( ( V_9 -> V_11 . V_36 & V_245 ) == V_246 ) {
T_3 V_32 = 0xFF << ( V_9 -> line * 8 ) ;
unsigned long V_247 =
F_26 ( V_248 , V_249 , V_250 ) |
F_26 ( V_248 , V_251 , V_250 ) ;
F_106 ( F_5 ( L_75 ,
( unsigned long ) V_9 -> V_252 , V_9 -> V_253 ) ) ;
if ( V_9 -> V_252 == V_254 ) {
T_4 V_255 = V_9 -> V_253 ;
V_247 =
F_26 ( V_248 , V_249 , V_256 ) |
F_26 ( V_248 , V_251 , V_256 ) ;
V_247 = 0x11 ;
F_106 ( F_5 ( L_76 , V_255 ) ) ;
* V_257 = V_255 ;
V_9 -> V_21 = V_254 / V_255 ;
}
else
{
F_5 ( V_30 L_77 ,
( unsigned long ) V_9 -> V_252 , V_9 -> V_253 ) ;
}
V_258 &= ~ V_32 ;
V_258 |= ( V_247 << ( V_9 -> line * 8 ) ) ;
* V_248 = V_258 ;
} else {
T_3 V_32 = 0xFF << ( V_9 -> line * 8 ) ;
unsigned long V_247 =
F_26 ( V_248 , V_249 , V_250 ) |
F_26 ( V_248 , V_251 , V_250 ) ;
V_258 &= ~ V_32 ;
V_258 |= ( V_247 << ( V_9 -> line * 8 ) ) ;
* V_248 = V_258 ;
V_9 -> V_21 = F_3 ( V_24 ) ;
V_9 -> V_40 [ V_259 ] = F_4 ( V_24 ) ;
}
F_9 ( V_36 ) ;
V_9 -> V_38 &= ~ ( F_15 ( V_48 , V_260 ) |
F_15 ( V_48 , V_261 ) |
F_15 ( V_48 , V_262 ) ) ;
V_9 -> V_243 &= ~ ( F_15 ( V_263 , V_264 ) |
F_15 ( V_263 , V_265 ) |
F_15 ( V_263 , V_266 ) |
F_15 ( V_263 , V_267 ) |
F_15 ( V_263 , V_268 ) ) ;
if ( ( V_24 & V_16 ) == V_17 ) {
V_9 -> V_243 |= F_26 ( V_263 , V_264 , V_269 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_260 , V_270 ) ;
}
if ( V_24 & V_18 ) {
V_9 -> V_243 |= F_26 ( V_263 , V_267 , V_271 ) ;
}
if ( V_24 & V_19 ) {
V_9 -> V_243 |= F_26 ( V_263 , V_265 , V_105 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_261 , V_105 ) ;
}
if ( V_24 & V_272 ) {
V_9 -> V_243 |= F_26 ( V_263 , V_273 , V_274 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_275 , V_274 ) ;
}
if ( V_24 & V_276 ) {
V_9 -> V_243 |= F_26 ( V_263 , V_266 , V_277 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_262 , V_277 ) ;
}
if ( V_24 & V_278 ) {
F_25 ( F_20 ( V_9 -> line , L_78 , 0 ) ) ;
V_9 -> V_243 |= F_26 ( V_263 , V_268 , V_279 ) ;
}
V_9 -> V_243 |= F_26 ( V_263 , V_280 , V_105 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_49 , V_105 ) ;
V_9 -> V_40 [ V_242 ] = V_9 -> V_243 ;
V_9 -> V_40 [ V_41 ] = V_9 -> V_38 ;
V_93 = F_44 ( V_98 , V_99 , F_45 ( V_9 -> V_11 . V_12 ) ) ;
V_93 |= F_26 ( V_98 , V_100 , V_105 ) ;
if ( V_9 -> V_11 . V_12 -> V_13 . V_102 & V_103 ) {
F_25 ( F_20 ( V_9 -> line , L_79 ,
F_45 ( V_9 -> V_11 . V_12 ) ) ) ;
V_93 |= F_26 ( V_98 , V_104 , V_105 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_106 ] ) = V_93 ;
F_10 ( V_36 ) ;
F_2 ( V_9 ) ;
}
static void
F_107 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( V_9 -> V_116 ||
V_9 -> V_94 . V_95 == V_9 -> V_94 . V_96 ||
V_12 -> V_220 ||
! V_9 -> V_94 . V_84 )
return;
#ifdef F_108
F_5 ( L_80 ) ;
#endif
F_9 ( V_36 ) ;
F_53 ( V_9 ) ;
F_10 ( V_36 ) ;
}
static int F_109 ( struct V_74 * V_12 ,
const unsigned char * V_84 , int V_85 )
{
int V_110 , V_156 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 -> V_94 . V_84 )
return 0 ;
#ifdef F_110
if ( V_9 -> line == V_115 )
F_5 ( L_81 ,
V_85 , V_9 -> V_40 [ V_165 ] ) ;
#endif
F_111 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_82 , V_85 ) ) ;
F_25 ( F_20 ( V_9 -> line , L_83 , V_12 -> V_281 . V_282 ( V_12 ) ) ) ;
F_93 () ;
while ( V_85 ) {
V_110 = F_112 ( V_9 -> V_94 . V_95 ,
V_9 -> V_94 . V_96 ,
V_97 ) ;
if ( V_85 < V_110 )
V_110 = V_85 ;
if ( V_110 <= 0 )
break;
memcpy ( V_9 -> V_94 . V_84 + V_9 -> V_94 . V_95 , V_84 , V_110 ) ;
V_9 -> V_94 . V_95 = ( V_9 -> V_94 . V_95 + V_110 ) &
( V_97 - 1 ) ;
V_84 += V_110 ;
V_85 -= V_110 ;
V_156 += V_110 ;
}
F_10 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_84 , V_156 ) ) ;
if ( V_9 -> V_94 . V_95 != V_9 -> V_94 . V_96 &&
! V_12 -> V_220 &&
! V_9 -> V_116 ) {
F_53 ( V_9 ) ;
}
return V_156 ;
}
static int
F_40 ( struct V_74 * V_12 ,
const unsigned char * V_84 , int V_85 )
{
#if F_38 ( V_126 )
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 -> V_82 . V_36 & V_87 )
{
#ifdef V_127
V_89 [ V_9 -> line ] . V_90 = NULL ;
F_113 ( & V_89 [ V_9 -> line ] ) ;
#endif
F_11 ( V_9 , ( V_9 -> V_82 . V_36 & V_283 ) ) ;
#if F_38 ( V_92 )
F_14 ( V_9 ) ;
F_35 ( V_9 ) ;
#endif
if ( V_9 -> V_82 . V_83 > 0 )
F_114 ( V_9 -> V_82 . V_83 ) ;
}
#endif
V_85 = F_109 ( V_12 , V_84 , V_85 ) ;
#if F_38 ( V_126 )
if ( V_9 -> V_82 . V_36 & V_87 )
{
unsigned int V_284 ;
F_115 ( V_12 , 0 ) ;
#ifdef V_127
F_116 ( V_9 -> V_20 * 2 ) ;
#endif
do{
F_117 ( V_9 , & V_284 ) ;
}while ( ! ( V_284 & V_285 ) );
F_11 ( V_9 , ( V_9 -> V_82 . V_36 & V_91 ) ) ;
#if F_38 ( V_92 )
F_16 ( V_9 ) ;
F_21 ( V_9 ) ;
#endif
}
#endif
return V_85 ;
}
static int
F_118 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
return F_119 ( V_9 -> V_94 . V_95 , V_9 -> V_94 . V_96 , V_97 ) ;
}
static int
F_120 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
return F_43 ( V_9 -> V_94 . V_95 , V_9 -> V_94 . V_96 , V_97 ) ;
}
static void
F_121 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
V_9 -> V_94 . V_95 = V_9 -> V_94 . V_96 = 0 ;
F_10 ( V_36 ) ;
F_97 ( V_12 ) ;
}
static void F_122 ( struct V_74 * V_12 , char V_286 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( V_9 -> V_107 ) {
* V_9 -> V_133 = F_26 ( V_134 , V_135 , V_287 ) ;
while ( F_68 ( V_134 , V_135 , * V_9 -> V_133 ) !=
F_69 ( V_134 , V_135 , V_287 ) ) ;
F_24 ( V_9 ) ;
}
if ( V_12 -> V_220 )
F_46 ( V_12 ) ;
F_25 ( F_20 ( V_9 -> line , L_85 , V_286 ) ) ;
V_9 -> V_218 = V_286 ;
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
}
static void
F_123 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#ifdef F_124
F_5 ( L_86 , F_125 ( V_12 ) ,
( unsigned long ) V_12 -> V_281 . V_282 ( V_12 ) ) ;
#endif
F_25 ( F_20 ( V_9 -> line , L_87 , V_12 -> V_281 . V_282 ( V_12 ) ) ) ;
if ( V_12 -> V_13 . V_14 & V_278 ) {
F_11 ( V_9 , 0 ) ;
}
if ( F_126 ( V_12 ) )
F_122 ( V_12 , F_45 ( V_12 ) ) ;
}
static void
F_127 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#ifdef F_124
F_5 ( L_88 , F_125 ( V_12 ) ,
( unsigned long ) V_12 -> V_281 . V_282 ( V_12 ) ) ;
#endif
F_25 ( F_20 ( V_9 -> line , L_89 , V_12 -> V_281 . V_282 ( V_12 ) ) ) ;
F_25 ( F_20 ( V_9 -> line , L_90 , V_12 -> V_288 . V_85 ) ) ;
if ( V_12 -> V_13 . V_14 & V_278 ) {
F_11 ( V_9 , 1 ) ;
}
if ( F_126 ( V_12 ) ) {
if ( V_9 -> V_218 )
V_9 -> V_218 = 0 ;
else
F_122 ( V_12 , F_128 ( V_12 ) ) ;
}
}
static int
F_129 ( struct V_8 * V_9 ,
struct V_289 * V_290 )
{
struct V_289 V_291 ;
if ( ! V_290 )
return - V_292 ;
memset ( & V_291 , 0 , sizeof( V_291 ) ) ;
V_291 . type = V_9 -> type ;
V_291 . line = V_9 -> line ;
V_291 . V_11 = ( int ) V_9 -> V_40 ;
V_291 . V_51 = V_9 -> V_51 ;
V_291 . V_36 = V_9 -> V_11 . V_36 ;
V_291 . V_252 = V_9 -> V_252 ;
V_291 . V_293 = V_9 -> V_11 . V_293 ;
V_291 . V_294 = V_9 -> V_11 . V_294 ;
V_291 . V_253 = V_9 -> V_253 ;
if ( F_130 ( V_290 , & V_291 , sizeof( * V_290 ) ) )
return - V_292 ;
return 0 ;
}
static int
F_131 ( struct V_8 * V_9 ,
struct V_289 * V_295 )
{
struct V_289 V_296 ;
struct V_8 V_297 ;
int V_29 = 0 ;
if ( F_132 ( & V_296 , V_295 , sizeof( V_296 ) ) )
return - V_292 ;
V_297 = * V_9 ;
if ( ! F_133 ( V_298 ) ) {
if ( ( V_296 . type != V_9 -> type ) ||
( V_296 . V_293 != V_9 -> V_11 . V_293 ) ||
( ( V_296 . V_36 & ~ V_299 ) !=
( V_9 -> V_11 . V_36 & ~ V_299 ) ) )
return - V_300 ;
V_9 -> V_11 . V_36 = ( ( V_9 -> V_11 . V_36 & ~ V_299 ) |
( V_296 . V_36 & V_299 ) ) ;
goto V_301;
}
if ( V_9 -> V_11 . V_85 > 1 )
return - V_302 ;
V_9 -> V_252 = V_296 . V_252 ;
V_9 -> V_11 . V_36 = ( ( V_9 -> V_11 . V_36 & ~ V_303 ) |
( V_296 . V_36 & V_303 ) ) ;
V_9 -> V_253 = V_296 . V_253 ;
V_9 -> type = V_296 . type ;
V_9 -> V_11 . V_293 = V_296 . V_293 ;
V_9 -> V_11 . V_294 = V_296 . V_294 ;
V_9 -> V_11 . V_304 = ( V_9 -> V_11 . V_36 & V_305 ) ? 1 : 0 ;
V_301:
if ( V_9 -> V_11 . V_36 & V_238 ) {
F_103 ( V_9 ) ;
} else
V_29 = F_98 ( V_9 ) ;
return V_29 ;
}
static int
F_117 ( struct V_8 * V_9 , unsigned int * V_1 )
{
unsigned int V_306 = V_285 ;
unsigned long V_215 = V_5 ;
unsigned long V_307 = F_71 () ;
unsigned long V_216 =
( V_215 - V_9 -> V_189 ) * 1000000 / V_217 +
V_307 - V_9 -> V_188 ;
if ( V_9 -> V_94 . V_95 != V_9 -> V_94 . V_96 ||
V_216 < 2 * V_9 -> V_20 ) {
V_306 = 0 ;
}
if ( F_130 ( V_1 , & V_306 , sizeof( int ) ) )
return - V_292 ;
return 0 ;
}
char * F_134 ( int V_308 , char * V_309 )
{
int V_178 = 0 ;
V_309 [ 0 ] = '\0' ;
while ( V_310 [ V_178 ] . V_311 != NULL ) {
if ( V_308 & V_310 [ V_178 ] . V_312 ) {
if ( V_309 [ 0 ] != '\0' ) {
strcat ( V_309 , L_91 ) ;
}
strcat ( V_309 , V_310 [ V_178 ] . V_311 ) ;
}
V_178 ++ ;
}
return V_309 ;
}
static int
F_135 ( struct V_74 * V_12 , int V_313 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 -> V_40 )
return - V_314 ;
F_9 ( V_36 ) ;
if ( V_313 == - 1 ) {
V_9 -> V_243 &= 0x3F ;
} else {
V_9 -> V_243 |= ( 0x80 | 0x40 ) ;
}
V_9 -> V_40 [ V_242 ] = V_9 -> V_243 ;
F_10 ( V_36 ) ;
return 0 ;
}
static int
F_136 ( struct V_74 * V_12 , unsigned int V_31 , unsigned int V_315 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( V_315 & V_316 )
F_11 ( V_9 , 0 ) ;
if ( V_315 & V_317 )
F_6 ( V_9 , 0 ) ;
if ( V_315 & V_318 )
F_12 ( V_9 , 0 ) ;
if ( V_315 & V_319 )
F_13 ( V_9 , 0 ) ;
if ( V_31 & V_316 )
F_11 ( V_9 , 1 ) ;
if ( V_31 & V_317 )
F_6 ( V_9 , 1 ) ;
if ( V_31 & V_318 )
F_12 ( V_9 , 1 ) ;
if ( V_31 & V_319 )
F_13 ( V_9 , 1 ) ;
F_10 ( V_36 ) ;
return 0 ;
}
static int
F_137 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned int V_306 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
V_306 =
( ! F_138 ( V_9 ) ? V_316 : 0 )
| ( ! F_8 ( V_9 ) ? V_317 : 0 )
| ( ! F_139 ( V_9 ) ? V_320 : 0 )
| ( ! F_140 ( V_9 ) ? V_321 : 0 )
| ( ! F_141 ( V_9 ) ? V_322 : 0 )
| ( ! F_142 ( V_9 ) ? V_323 : 0 ) ;
F_10 ( V_36 ) ;
#ifdef F_7
F_5 ( V_324 L_92 ,
V_9 -> line , V_306 , V_306 ) ;
{
char V_309 [ 100 ] ;
F_134 ( V_306 , V_309 ) ;
F_5 ( V_324 L_93 , V_309 ) ;
}
#endif
return V_306 ;
}
static int
F_143 ( struct V_74 * V_12 ,
unsigned int V_135 , unsigned long V_325 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( ( V_135 != V_326 ) && ( V_135 != V_327 ) &&
( V_135 != V_328 ) && ( V_135 != V_329 ) &&
( V_135 != V_330 ) && ( V_135 != V_331 ) ) {
if ( V_12 -> V_36 & ( 1 << V_241 ) )
return - V_314 ;
}
switch ( V_135 ) {
case V_326 :
return F_129 ( V_9 ,
(struct V_289 * ) V_325 ) ;
case V_327 :
return F_131 ( V_9 ,
(struct V_289 * ) V_325 ) ;
case V_332 :
return F_117 ( V_9 , ( unsigned int * ) V_325 ) ;
case V_331 :
if ( F_130 ( (struct V_8 * ) V_325 ,
V_9 , sizeof( struct V_8 ) ) )
return - V_292 ;
return 0 ;
#if F_38 ( V_126 )
case V_333 :
{
struct V_334 V_335 ;
struct V_75 V_336 ;
F_5 ( V_324 L_94 ) ;
if ( F_132 ( & V_335 , (struct V_334 * ) V_325 ,
sizeof( V_335 ) ) )
return - V_292 ;
V_336 . V_83 = V_335 . V_83 ;
V_336 . V_36 = 0 ;
if ( V_335 . V_187 )
V_336 . V_36 |= V_87 ;
else
V_336 . V_36 &= ~ ( V_87 ) ;
if ( V_335 . V_337 )
V_336 . V_36 |= V_283 ;
else
V_336 . V_36 &= ~ ( V_283 ) ;
if ( V_335 . V_338 )
V_336 . V_36 |= V_91 ;
else
V_336 . V_36 &= ~ ( V_91 ) ;
return F_37 ( V_12 , & V_336 ) ;
}
case V_339 :
{
struct V_75 V_336 ;
if ( F_132 ( & V_336 , (struct V_334 * ) V_325 ,
sizeof( V_336 ) ) )
return - V_292 ;
return F_37 ( V_12 , & V_336 ) ;
}
case V_340 :
{
struct V_75 * V_336 =
& ( ( (struct V_8 * ) V_12 -> V_77 ) -> V_82 ) ;
if ( F_130 ( (struct V_75 * ) V_325 ,
V_336 ,
sizeof( struct V_75 ) ) )
return - V_292 ;
break;
}
case V_341 :
{
struct V_342 V_343 ;
if ( F_132 ( & V_343 , (struct V_342 * ) V_325 ,
sizeof( V_343 ) ) )
return - V_292 ;
return F_39 ( V_12 , V_343 . V_344 , V_343 . V_345 ) ;
}
#endif
default:
return - V_346 ;
}
return 0 ;
}
static void
F_144 ( struct V_74 * V_12 , struct V_347 * V_348 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
F_103 ( V_9 ) ;
if ( ( V_348 -> V_14 & V_278 ) &&
! ( V_12 -> V_13 . V_14 & V_278 ) )
F_46 ( V_12 ) ;
}
static void
F_145 ( struct V_74 * V_12 , struct V_349 * V_350 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 )
return;
F_9 ( V_36 ) ;
if ( F_146 ( V_350 ) ) {
F_10 ( V_36 ) ;
return;
}
#ifdef F_101
F_5 ( L_95 , V_351 -> V_352 ,
V_9 -> line , V_9 -> V_85 ) ;
#endif
if ( ( V_12 -> V_85 == 1 ) && ( V_9 -> V_11 . V_85 != 1 ) ) {
F_5 ( V_353
L_96
L_97 , V_9 -> V_11 . V_85 ) ;
V_9 -> V_11 . V_85 = 1 ;
}
if ( -- V_9 -> V_11 . V_85 < 0 ) {
F_5 ( V_353 L_98 ,
V_9 -> line , V_9 -> V_11 . V_85 ) ;
V_9 -> V_11 . V_85 = 0 ;
}
if ( V_9 -> V_11 . V_85 ) {
F_10 ( V_36 ) ;
return;
}
V_9 -> V_11 . V_36 |= V_354 ;
V_12 -> V_355 = 1 ;
if ( V_9 -> V_11 . V_294 != V_356 )
F_115 ( V_12 , V_9 -> V_11 . V_294 ) ;
#ifdef F_64
F_30 ( V_9 ) ;
#endif
F_14 ( V_9 ) ;
F_36 ( V_9 ) ;
if ( V_9 -> V_11 . V_36 & V_238 ) {
F_147 ( V_12 , V_217 ) ;
}
F_104 ( V_9 ) ;
F_121 ( V_12 ) ;
F_148 ( V_12 ) ;
V_12 -> V_355 = 0 ;
V_9 -> V_108 = 0 ;
V_9 -> V_11 . V_12 = NULL ;
if ( V_9 -> V_11 . V_357 ) {
if ( V_9 -> V_11 . V_293 )
F_149 ( V_9 -> V_11 . V_293 ) ;
F_150 ( & V_9 -> V_11 . V_358 ) ;
}
V_9 -> V_11 . V_36 &= ~ ( V_359 | V_354 ) ;
F_10 ( V_36 ) ;
#if F_38 ( V_126 )
if ( V_9 -> V_82 . V_36 & V_87 ) {
V_9 -> V_82 . V_36 &= ~ ( V_87 ) ;
#if F_38 ( V_78 )
* V_79 = V_80 &= ~ ( 1 << V_81 ) ;
#endif
}
#endif
if ( V_9 -> V_239 ) {
F_151 ( V_9 -> V_360 , V_9 ) ;
F_152 ( V_9 -> V_361 , V_9 -> V_362 ) ;
V_9 -> V_73 = 0 ;
#ifdef F_101
F_5 ( V_324 L_99 ,
V_9 -> V_362 ) ;
#endif
}
if ( V_9 -> V_240 ) {
F_151 ( V_9 -> V_363 , V_9 ) ;
F_152 ( V_9 -> V_364 , V_9 -> V_365 ) ;
V_9 -> V_107 = 0 ;
#ifdef F_101
F_5 ( V_324 L_99 ,
V_9 -> V_365 ) ;
#endif
}
}
static void F_147 ( struct V_74 * V_12 , int V_366 )
{
unsigned long V_367 ;
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_215 = V_5 ;
unsigned long V_307 = F_71 () ;
long V_216 =
( V_215 - V_9 -> V_189 ) * ( 1000000 / V_217 ) +
V_307 - V_9 -> V_188 ;
V_367 = V_5 ;
while ( V_9 -> V_94 . V_95 != V_9 -> V_94 . V_96 ||
( * V_9 -> V_368 & 0x007f ) ||
( V_216 < 2 * V_9 -> V_20 ) ) {
F_149 ( 1 ) ;
if ( F_153 ( V_351 ) )
break;
if ( V_366 && F_154 ( V_5 , V_367 + V_366 ) )
break;
V_215 = V_5 ;
V_307 = F_71 () ;
V_216 =
( V_215 - V_9 -> V_189 ) * ( 1000000 / V_217 ) +
V_307 - V_9 -> V_188 ;
}
F_155 ( V_369 ) ;
}
void
F_156 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
F_121 ( V_12 ) ;
F_104 ( V_9 ) ;
V_9 -> V_108 = 0 ;
V_9 -> V_11 . V_85 = 0 ;
V_9 -> V_11 . V_36 &= ~ V_359 ;
V_9 -> V_11 . V_12 = NULL ;
F_150 ( & V_9 -> V_11 . V_358 ) ;
}
static int
F_157 ( struct V_74 * V_12 , struct V_349 * V_350 ,
struct V_8 * V_9 )
{
F_158 ( V_370 , V_351 ) ;
unsigned long V_36 ;
int V_29 ;
int V_371 = 0 ;
if ( ( V_350 -> V_372 & V_373 ) ||
( V_12 -> V_36 & ( 1 << V_241 ) ) ) {
V_9 -> V_11 . V_36 |= V_359 ;
return 0 ;
}
if ( V_12 -> V_13 . V_14 & V_374 ) {
V_371 = 1 ;
}
V_29 = 0 ;
F_159 ( & V_9 -> V_11 . V_358 , & V_370 ) ;
#ifdef F_101
F_5 ( L_100 ,
V_9 -> line , V_9 -> V_11 . V_85 ) ;
#endif
F_9 ( V_36 ) ;
V_9 -> V_11 . V_85 -- ;
F_10 ( V_36 ) ;
V_9 -> V_11 . V_357 ++ ;
while ( 1 ) {
F_9 ( V_36 ) ;
F_11 ( V_9 , 1 ) ;
F_6 ( V_9 , 1 ) ;
F_10 ( V_36 ) ;
F_155 ( V_375 ) ;
if ( F_146 ( V_350 ) ||
! ( V_9 -> V_11 . V_36 & V_238 ) ) {
#ifdef F_160
if ( V_9 -> V_11 . V_36 & V_376 )
V_29 = - V_377 ;
else
V_29 = - V_378 ;
#else
V_29 = - V_377 ;
#endif
break;
}
if ( V_371 )
break;
if ( F_153 ( V_351 ) ) {
V_29 = - V_378 ;
break;
}
#ifdef F_101
F_5 ( L_101 ,
V_9 -> line , V_9 -> V_11 . V_85 ) ;
#endif
F_161 ( V_12 ) ;
F_162 () ;
F_163 ( V_12 ) ;
}
F_155 ( V_369 ) ;
F_164 ( & V_9 -> V_11 . V_358 , & V_370 ) ;
if ( ! F_146 ( V_350 ) )
V_9 -> V_11 . V_85 ++ ;
V_9 -> V_11 . V_357 -- ;
#ifdef F_101
F_5 ( L_102 ,
V_9 -> line , V_9 -> V_11 . V_85 ) ;
#endif
if ( V_29 )
return V_29 ;
V_9 -> V_11 . V_36 |= V_359 ;
return 0 ;
}
static void
F_165 ( struct V_8 * V_9 )
{
if ( V_9 -> V_240 ) {
F_152 ( V_9 -> V_364 , V_9 -> V_365 ) ;
F_151 ( V_9 -> V_363 , V_9 ) ;
}
if ( V_9 -> V_239 ) {
F_152 ( V_9 -> V_361 , V_9 -> V_362 ) ;
F_151 ( V_9 -> V_360 , V_9 ) ;
}
}
static int
F_166 ( struct V_74 * V_12 , struct V_349 * V_350 )
{
struct V_8 * V_9 ;
int V_29 ;
int V_379 = 0 ;
V_9 = V_186 + V_12 -> V_380 ;
if ( ! V_9 -> V_187 )
return - V_381 ;
#ifdef F_101
F_5 ( L_103 , V_351 -> V_352 , V_12 -> V_382 ,
V_9 -> V_11 . V_85 ) ;
#endif
V_9 -> V_11 . V_85 ++ ;
V_12 -> V_77 = V_9 ;
V_9 -> V_11 . V_12 = V_12 ;
V_9 -> V_11 . V_304 = ! ! ( V_9 -> V_11 . V_36 & V_305 ) ;
if ( V_9 -> V_11 . V_85 == 1 ) {
V_379 = 1 ;
if ( V_9 -> V_239 ) {
if ( F_167 ( V_9 -> V_360 ,
F_73 ,
V_9 -> V_383 ,
V_9 -> V_362 ,
V_9 ) ) {
F_5 ( V_30 L_104
L_105 ,
V_9 -> V_362 ) ;
V_9 -> V_239 = 0 ;
} else if ( F_168 ( V_9 -> V_361 ,
V_9 -> V_362 ,
V_384 ,
V_9 -> V_385 ) ) {
F_151 ( V_9 -> V_360 , V_9 ) ;
F_5 ( V_30 L_106
L_105 ,
V_9 -> V_362 ) ;
V_9 -> V_239 = 0 ;
}
#ifdef F_101
else
F_5 ( V_324 L_107 ,
V_9 -> V_362 ) ;
#endif
}
if ( V_9 -> V_240 ) {
if ( F_167 ( V_9 -> V_363 ,
F_70 ,
V_9 -> V_386 ,
V_9 -> V_365 ,
V_9 ) ) {
F_5 ( V_30 L_104
L_105 ,
V_9 -> V_365 ) ;
V_9 -> V_240 = 0 ;
} else if ( F_168 ( V_9 -> V_364 ,
V_9 -> V_365 ,
V_384 ,
V_9 -> V_385 ) ) {
F_151 ( V_9 -> V_363 , V_9 ) ;
F_5 ( V_30 L_106
L_105 ,
V_9 -> V_365 ) ;
V_9 -> V_240 = 0 ;
}
#ifdef F_101
else
F_5 ( V_324 L_107 ,
V_9 -> V_365 ) ;
#endif
}
}
V_29 = F_98 ( V_9 ) ;
if ( V_29 ) {
if ( V_379 )
F_165 ( V_9 ) ;
return V_29 ;
}
V_29 = F_157 ( V_12 , V_350 , V_9 ) ;
if ( V_29 ) {
#ifdef F_101
F_5 ( L_108 ,
V_29 ) ;
#endif
if ( V_379 )
F_165 ( V_9 ) ;
return V_29 ;
}
#ifdef F_101
F_5 ( L_109 , V_9 -> line ) ;
#endif
F_87 ( V_387 = 0 ) ;
F_169 ( if (info->line == SERIAL_DEBUG_LINE) {
info->icount.rx = 0;
} ) ;
return 0 ;
}
static void F_170 ( struct V_388 * V_389 , struct V_8 * V_9 )
{
unsigned long V_291 ;
F_171 ( V_389 , L_110 ,
V_9 -> line , ( unsigned long ) V_9 -> V_40 , V_9 -> V_51 ) ;
if ( ! V_9 -> V_40 || ( V_9 -> type == V_390 ) ) {
F_171 ( V_389 , L_111 ) ;
return;
}
F_171 ( V_389 , L_112 , V_9 -> V_21 ) ;
F_171 ( V_389 , L_113 ,
( unsigned long ) V_9 -> V_122 . V_123 ,
( unsigned long ) V_9 -> V_122 . V_149 ) ;
V_291 = F_43 ( V_9 -> V_94 . V_95 , V_9 -> V_94 . V_96 , V_97 ) ;
if ( V_291 )
F_171 ( V_389 , L_114 ,
( unsigned long ) V_291 ,
( unsigned long ) V_97 ) ;
F_171 ( V_389 , L_115 ,
( unsigned long ) V_9 -> V_146 ,
( unsigned long ) V_9 -> V_147 ) ;
#if 1
if ( V_9 -> V_11 . V_12 ) {
if ( V_9 -> V_11 . V_12 -> V_220 )
F_171 ( V_389 , L_116 ,
( int ) V_9 -> V_11 . V_12 -> V_220 ) ;
}
{
unsigned char V_162 = V_9 -> V_40 [ V_165 ] ;
if ( V_162 & F_15 ( V_166 , V_167 ) )
F_171 ( V_389 , L_117 ) ;
}
#endif
if ( V_9 -> V_122 . V_210 )
F_171 ( V_389 , L_118 , ( unsigned long ) V_9 -> V_122 . V_210 ) ;
if ( V_9 -> V_122 . V_209 )
F_171 ( V_389 , L_119 , ( unsigned long ) V_9 -> V_122 . V_209 ) ;
if ( V_9 -> V_122 . V_213 )
F_171 ( V_389 , L_120 , ( unsigned long ) V_9 -> V_122 . V_213 ) ;
if ( V_9 -> V_122 . V_204 )
F_171 ( V_389 , L_121 , ( unsigned long ) V_9 -> V_122 . V_204 ) ;
if ( ! F_138 ( V_9 ) )
F_172 ( V_389 , L_122 ) ;
if ( ! F_142 ( V_9 ) )
F_172 ( V_389 , L_123 ) ;
if ( ! F_8 ( V_9 ) )
F_172 ( V_389 , L_124 ) ;
if ( ! F_140 ( V_9 ) )
F_172 ( V_389 , L_125 ) ;
if ( ! F_141 ( V_9 ) )
F_172 ( V_389 , L_126 ) ;
if ( ! F_139 ( V_9 ) )
F_172 ( V_389 , L_127 ) ;
F_172 ( V_389 , L_111 ) ;
}
static int F_173 ( struct V_388 * V_389 , void * V_391 )
{
int V_178 ;
F_171 ( V_389 , L_128 , V_392 ) ;
for ( V_178 = 0 ; V_178 < V_185 ; V_178 ++ ) {
if ( ! V_186 [ V_178 ] . V_187 )
continue;
F_170 ( V_389 , & V_186 [ V_178 ] ) ;
}
#ifdef F_174
for ( V_178 = 0 ; V_178 < V_2 ; V_178 ++ ) {
F_171 ( V_389 , L_129 ,
V_178 , V_4 [ V_178 ] . time ,
F_175 ( V_4 [ V_178 ] . V_6 ) ) ;
F_171 ( V_389 , V_4 [ V_178 ] . string , V_4 [ V_178 ] . V_1 ) ;
}
F_171 ( V_389 , L_130 , V_178 , V_3 ) ;
V_2 = 0 ;
#endif
return 0 ;
}
static int F_176 ( struct V_393 * V_393 , struct V_349 * V_349 )
{
return F_177 ( V_349 , F_173 , NULL ) ;
}
static void F_178 ( void )
{
F_5 ( V_394
L_131
L_132 ,
& V_392 [ 11 ] ) ;
}
static int T_5 F_179 ( void )
{
int V_178 ;
struct V_8 * V_9 ;
struct V_395 * V_396 = F_180 ( V_185 ) ;
if ( ! V_396 )
return - V_237 ;
F_178 () ;
#if ! F_38 ( V_397 )
F_181 ( & V_195 , F_84 , 0 ) ;
F_85 ( & V_195 , V_5 + 5 ) ;
#endif
#if F_38 ( V_126 )
#if F_38 ( V_78 )
if ( F_182 ( V_398 , 'a' , V_81 ,
V_81 ) ) {
F_5 ( V_353 L_133
L_134 ) ;
F_183 ( V_396 ) ;
return - V_302 ;
}
#endif
#endif
V_396 -> V_399 = L_135 ;
V_396 -> V_382 = L_136 ;
V_396 -> V_400 = V_401 ;
V_396 -> V_402 = 64 ;
V_396 -> type = V_403 ;
V_396 -> V_404 = V_405 ;
V_396 -> V_406 = V_407 ;
V_396 -> V_406 . V_14 =
V_408 | V_409 | V_410 | V_244 | V_374 ;
V_396 -> V_406 . V_411 = 115200 ;
V_396 -> V_406 . V_412 = 115200 ;
V_396 -> V_36 = V_413 ;
F_184 ( V_396 , & V_414 ) ;
V_415 = V_396 ;
for ( V_178 = 0 , V_9 = V_186 ; V_178 < V_185 ; V_178 ++ , V_9 ++ ) {
if ( V_9 -> V_187 ) {
if ( F_185 ( V_9 -> V_416 ,
V_9 -> V_417 ) ) {
F_5 ( V_353 L_137
L_138
L_139 ,
V_9 -> V_417 , V_178 ) ;
V_9 -> V_187 = 0 ;
}
}
F_186 ( & V_9 -> V_11 ) ;
V_9 -> V_73 = 0 ;
V_9 -> V_107 = 0 ;
V_9 -> line = V_178 ;
V_9 -> V_11 . V_12 = NULL ;
V_9 -> type = V_418 ;
V_9 -> V_116 = 0 ;
V_9 -> V_191 = 0 ;
V_9 -> V_252 = V_419 ;
V_9 -> V_253 = 0 ;
V_9 -> V_218 = 0 ;
V_9 -> V_108 = 0 ;
V_9 -> V_94 . V_84 = NULL ;
V_9 -> V_94 . V_96 = V_9 -> V_94 . V_95 = 0 ;
V_9 -> V_144 = V_9 -> V_145 = NULL ;
V_9 -> V_146 = V_9 -> V_147 = 0 ;
V_9 -> V_188 = 0 ;
V_9 -> V_189 = 0 ;
#if F_38 ( V_126 )
V_9 -> V_82 . V_36 &= ~ ( V_283 ) ;
V_9 -> V_82 . V_36 |= V_91 ;
V_9 -> V_82 . V_83 = 0 ;
V_9 -> V_82 . V_36 &= ~ ( V_87 ) ;
#endif
F_187 ( & V_9 -> V_109 , F_94 ) ;
if ( V_9 -> V_187 ) {
F_5 ( V_394 L_140 ,
V_415 -> V_382 , V_9 -> line , V_9 -> V_40 ) ;
}
F_188 ( & V_9 -> V_11 , V_396 , V_178 ) ;
}
if ( F_189 ( V_396 ) )
F_61 ( L_141 ) ;
#ifdef V_127
#ifdef V_397
memset ( V_192 , 0 , sizeof( V_192 ) ) ;
#endif
#ifdef V_126
memset ( V_89 , 0 , sizeof( V_89 ) ) ;
#endif
F_190 () ;
#endif
#ifndef F_191
if ( F_167 ( V_420 , F_91 ,
V_421 , L_142 , V_396 ) )
F_61 ( L_143 , V_151 ) ;
#endif
return 0 ;
}
