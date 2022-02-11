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
if ( F_46 ( V_12 ) )
V_93 |= F_26 ( V_98 , V_102 , V_103 ) ;
* ( ( unsigned long * ) & V_9 -> V_40 [ V_104 ] ) = V_93 ;
F_10 ( V_36 ) ;
}
}
static void
F_47 ( struct V_74 * V_12 )
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
V_93 |= F_26 ( V_98 , V_100 , V_103 ) ;
if ( F_46 ( V_12 ) )
V_93 |= F_26 ( V_98 , V_102 , V_103 ) ;
* ( ( unsigned long * ) & V_9 -> V_40 [ V_104 ] ) = V_93 ;
if ( ! V_9 -> V_105 &&
V_9 -> V_94 . V_95 != V_9 -> V_94 . V_96 && V_9 -> V_94 . V_84 )
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
}
}
static void F_48 ( struct V_8 * V_9 , int V_106 )
{
if ( V_9 -> V_106 & ( 1 << V_106 ) )
return;
V_9 -> V_106 |= 1 << V_106 ;
F_49 ( & V_9 -> V_107 ) ;
}
static void
F_50 ( struct V_8 * V_9 )
{
unsigned int V_108 , V_109 ;
struct V_110 * V_111 ;
* V_9 -> V_112 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
#ifdef F_18
if ( V_9 -> line == V_113 )
F_5 ( L_27 ) ;
#endif
if ( ! V_9 -> V_114 ) {
F_5 ( V_30 L_28 ) ;
return;
}
V_111 = & V_9 -> V_115 ;
if ( ! ( V_111 -> V_116 & V_117 ) ) {
V_109 = V_111 -> V_118 ;
} else
V_109 = V_111 -> V_119 ;
F_25 ( F_20 ( V_9 -> line , L_29 , V_109 ) ) ;
V_9 -> V_120 . V_121 += V_109 ;
V_9 -> V_94 . V_96 = ( V_9 -> V_94 . V_96 + V_109 ) & ( V_97 - 1 ) ;
if ( F_43 ( V_9 -> V_94 . V_95 ,
V_9 -> V_94 . V_96 ,
V_97 ) < V_122 )
F_48 ( V_9 , V_123 ) ;
V_108 = F_51 ( V_9 -> V_94 . V_95 , V_9 -> V_94 . V_96 , V_97 ) ;
if ( V_108 >= 4 * V_122 )
V_108 = V_108 / 2 ;
if ( V_108 <= 0 ) {
V_9 -> V_114 = 0 ;
#if F_38 ( V_124 ) && F_38 ( V_125 )
if ( V_9 -> V_82 . V_36 & V_87 ) {
F_52 ( & V_89 [ V_9 -> line ] ,
F_41 ,
( unsigned long ) V_9 ,
V_9 -> V_20 * 2 ,
L_30 ) ;
}
#endif
return;
}
F_25 ( F_20 ( V_9 -> line , L_31 , V_108 ) ) ;
V_111 -> V_126 = V_127 | V_128 | V_129 ;
V_111 -> V_118 = V_108 ;
V_111 -> V_84 = F_53 ( V_9 -> V_94 . V_84 + V_9 -> V_94 . V_96 ) ;
V_111 -> V_116 = 0 ;
* V_9 -> V_130 = F_53 ( V_111 ) ;
* V_9 -> V_131 = F_26 ( V_132 , V_133 , V_134 ) ;
}
static void
F_54 ( struct V_8 * V_9 )
{
#if 0
if (info->line == SERIAL_DEBUG_LINE)
printk("x\n");
#endif
V_9 -> V_115 . V_118 = 0 ;
V_9 -> V_115 . V_119 = 0 ;
V_9 -> V_115 . V_116 = 0 ;
V_9 -> V_114 = 1 ;
if ( V_9 -> V_105 )
F_50 ( V_9 ) ;
else
F_33 ( V_9 ) ;
}
static struct V_135 *
F_55 ( unsigned int V_136 )
{
struct V_135 * V_137 ;
V_137 = F_56 ( sizeof *V_137 + V_136 , V_138 ) ;
if ( ! V_137 )
return NULL ;
V_137 -> V_139 = NULL ;
V_137 -> V_140 = 0 ;
V_137 -> error = V_141 ;
return V_137 ;
}
static void
F_57 ( struct V_8 * V_9 , struct V_135 * V_137 )
{
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( ! V_9 -> V_142 )
V_9 -> V_142 = V_137 ;
else
V_9 -> V_143 -> V_139 = V_137 ;
V_9 -> V_143 = V_137 ;
V_9 -> V_144 += V_137 -> V_140 ;
if ( V_9 -> V_144 > V_9 -> V_145 )
V_9 -> V_145 = V_9 -> V_144 ;
F_10 ( V_36 ) ;
}
static int
F_58 ( struct V_8 * V_9 , unsigned char V_88 , unsigned char V_146 )
{
struct V_135 * V_137 ;
if ( V_9 -> V_73 ) {
V_137 = F_55 ( 4 ) ;
if ( ! V_137 )
return 0 ;
V_137 -> V_140 = 1 ;
V_137 -> error = V_146 ;
V_137 -> V_137 [ 0 ] = V_88 ;
F_57 ( V_9 , V_137 ) ;
V_9 -> V_120 . V_147 ++ ;
} else {
F_59 ( & V_9 -> V_11 , V_88 , V_146 ) ;
V_9 -> V_120 . V_147 ++ ;
}
return 1 ;
}
static unsigned int F_60 ( struct V_8 * V_9 ,
struct V_110 * V_111 ,
unsigned int V_148 )
{
struct V_135 * V_137 = F_61 ( V_111 -> V_84 ) - sizeof *V_137 ;
if ( V_9 -> V_144 + V_148 > 65536 ) {
F_5 ( V_30
L_32 , V_149 , V_148 ) ;
return 0 ;
}
V_137 -> V_140 = V_148 ;
if ( V_9 -> V_150 == V_151 )
V_137 -> error = V_152 ;
V_9 -> V_150 = 0 ;
F_57 ( V_9 , V_137 ) ;
V_137 = F_55 ( V_153 ) ;
if ( ! V_137 )
F_62 ( L_33 , V_149 ) ;
V_111 -> V_84 = F_53 ( V_137 -> V_137 ) ;
return V_148 ;
}
static unsigned int F_63 ( struct V_8 * V_9 )
{
struct V_110 * V_111 ;
unsigned int V_148 ;
unsigned int V_154 = 0 ;
while ( 1 )
{
V_111 = & V_9 -> V_155 [ V_9 -> V_156 ] ;
if ( V_111 == F_61 ( * V_9 -> V_157 ) )
break;
if ( ++ V_9 -> V_156 == V_158 )
V_9 -> V_156 = 0 ;
if ( ! ( V_111 -> V_116 & V_159 ) ) {
V_148 = V_111 -> V_118 ;
} else {
V_148 = V_111 -> V_119 ;
}
V_111 -> V_116 = 0 ;
F_25 ( DEBUG_LOG(info->line, L_34, recvl);
if (info->port.tty->stopped) {
unsigned char *buf = phys_to_virt(descr->buf);
DEBUG_LOG(info->line, L_35, buf[0]);
DEBUG_LOG(info->line, L_35, buf[1]);
DEBUG_LOG(info->line, L_35, buf[2]);
}
) ;
V_9 -> V_120 . V_147 += V_148 ;
V_154 += F_60 ( V_9 , V_111 , V_148 ) ;
}
return V_154 ;
}
static void F_64 ( struct V_8 * V_9 )
{
struct V_74 * V_12 ;
unsigned char V_160 ;
* V_9 -> V_161 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 )
return;
#ifdef F_65
if ( V_9 -> V_73 )
F_31 ( V_9 ) ;
#endif
if ( V_9 -> V_150 == V_162 )
F_58 ( V_9 , '\0' , V_152 ) ;
F_63 ( V_9 ) ;
V_160 = V_9 -> V_40 [ V_163 ] ;
if ( V_160 & F_15 ( V_164 , V_165 ) ) {
F_25 ( F_20 ( V_9 -> line , L_36 , V_160 ) ) ;
}
if ( V_160 & V_166 ) {
unsigned char V_88 = V_9 -> V_40 [ V_167 ] ;
F_20 ( V_9 -> line , L_37 ,
( ( V_160 & V_166 ) << 8 ) | V_88 ) ;
if ( V_160 & V_168 )
F_58 ( V_9 , V_88 , V_169 ) ;
else if ( V_160 & V_170 )
F_58 ( V_9 , V_88 , V_171 ) ;
else if ( V_160 & V_172 )
F_58 ( V_9 , V_88 , V_173 ) ;
}
F_66 ( V_9 , L_38 ) ;
* V_9 -> V_174 = F_26 ( V_132 , V_133 , V_175 ) ;
}
static int F_67 ( struct V_8 * V_9 )
{
struct V_110 * V_111 = V_9 -> V_155 ;
struct V_135 * V_137 ;
int V_176 ;
for ( V_176 = 0 ; V_176 < V_158 ; V_176 ++ ) {
V_137 = F_55 ( V_153 ) ;
if ( ! V_137 )
F_62 ( L_33 , V_149 ) ;
V_111 [ V_176 ] . V_126 = V_127 ;
V_111 [ V_176 ] . V_84 = F_53 ( V_137 -> V_137 ) ;
V_111 [ V_176 ] . V_118 = V_153 ;
V_111 [ V_176 ] . V_119 = 0 ;
V_111 [ V_176 ] . V_116 = 0 ;
V_111 [ V_176 ] . V_139 = F_53 ( & V_111 [ V_176 + 1 ] ) ;
}
V_111 [ V_176 - 1 ] . V_139 = F_53 ( & V_111 [ 0 ] ) ;
V_9 -> V_156 = 0 ;
* V_9 -> V_177 = F_53 ( & V_111 [ V_9 -> V_156 ] ) ;
* V_9 -> V_174 = F_26 ( V_132 , V_133 , V_134 ) ;
return 1 ;
}
static void
F_68 ( struct V_8 * V_9 )
{
if ( V_9 -> V_73 ) {
* V_9 -> V_174 = F_26 ( V_132 , V_133 , V_178 ) ;
while ( F_69 ( V_132 , V_133 , * V_9 -> V_174 ) ==
F_70 ( V_132 , V_133 , V_178 ) ) ;
F_67 ( V_9 ) ;
}
}
static T_2
F_71 ( int V_51 , void * V_179 )
{
struct V_8 * V_9 ;
unsigned long V_180 ;
int V_176 ;
int V_181 = 0 ;
V_180 = * V_182 ;
for ( V_176 = 0 ; V_176 < V_183 ; V_176 ++ ) {
V_9 = V_184 + V_176 ;
if ( ! V_9 -> V_185 || ! V_9 -> V_105 )
continue;
if ( V_180 & V_9 -> V_51 ) {
V_181 = 1 ;
F_34 ( F_20 ( V_9 -> line , L_39 , V_176 ) ) ;
V_9 -> V_186 = F_72 () ;
V_9 -> V_187 = V_5 ;
F_50 ( V_9 ) ;
}
}
return F_73 ( V_181 ) ;
}
static T_2
F_74 ( int V_51 , void * V_179 )
{
struct V_8 * V_9 ;
unsigned long V_180 ;
int V_176 ;
int V_181 = 0 ;
V_180 = * V_182 ;
for ( V_176 = 0 ; V_176 < V_183 ; V_176 ++ ) {
V_9 = V_184 + V_176 ;
if ( ! V_9 -> V_185 || ! V_9 -> V_73 )
continue;
if ( V_180 & ( ( V_9 -> V_51 << 2 ) | ( V_9 -> V_51 << 3 ) ) ) {
V_181 = 1 ;
F_64 ( V_9 ) ;
}
}
return F_73 ( V_181 ) ;
}
static int F_75 ( struct V_8 * V_9 )
{
unsigned char V_160 = V_9 -> V_40 [ V_163 ] ;
if ( V_160 & V_166 ) {
F_20 ( V_9 -> line , L_40 ,
V_160 | ( V_9 -> line << 8 ) ) ;
return 0 ;
}
if ( V_160 & V_188 ) {
F_76 ( F_20 ( V_9 -> line , L_41 ,
V_160 | ( V_9 -> line << 8 ) ) ) ;
( void ) V_9 -> V_40 [ V_167 ] ;
V_9 -> V_189 = 0 ;
F_66 ( V_9 , L_42 ) ;
return 0 ;
}
if ( ! V_9 -> V_189 ) {
V_9 -> V_189 = 1 ;
F_76 ( F_20 ( V_9 -> line , L_43 , V_9 -> line ) ) ;
F_77 ( V_9 ) ;
}
return 1 ;
}
static void F_78 ( struct V_8 * V_9 )
{
struct V_135 * V_137 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
while ( ( V_137 = V_9 -> V_142 ) != NULL ) {
unsigned int V_85 = V_137 -> V_140 ;
F_79 ( & V_9 -> V_11 , V_137 -> V_137 , V_85 ) ;
V_9 -> V_144 -= V_85 ;
if ( V_85 == V_137 -> V_140 ) {
V_9 -> V_142 = V_137 -> V_139 ;
F_80 ( V_137 ) ;
} else {
V_137 -> V_140 -= V_85 ;
memmove ( V_137 -> V_137 , V_137 -> V_137 + V_85 , V_137 -> V_140 ) ;
V_137 -> error = V_141 ;
}
}
if ( ! V_9 -> V_142 )
V_9 -> V_143 = NULL ;
F_10 ( V_36 ) ;
F_81 ( & V_9 -> V_11 ) ;
}
static void F_82 ( struct V_8 * V_9 )
{
F_78 ( V_9 ) ;
if ( V_9 -> V_142 )
F_83 ( V_9 , L_44 , 2000 ) ;
F_75 ( V_9 ) ;
}
static void F_84 ( unsigned long V_88 )
{
struct V_8 * V_9 = (struct V_8 * ) V_88 ;
V_190 [ V_9 -> line ] . V_90 = NULL ;
V_191 ++ ;
F_76 ( F_20 ( V_9 -> line , L_45 , V_9 -> line ) ) ;
F_76 ( F_20 ( V_9 -> line , L_46 , V_191 ) ) ;
F_82 ( V_9 ) ;
}
static void
F_85 ( unsigned long V_192 )
{
struct V_8 * V_9 ;
int V_176 ;
for ( V_176 = 0 ; V_176 < V_183 ; V_176 ++ ) {
V_9 = V_184 + V_176 ;
if ( V_9 -> V_73 )
F_82 ( V_9 ) ;
}
F_86 ( & V_193 , V_5 + V_194 ) ;
}
static void F_87 ( struct V_8 * V_9 )
{
unsigned long V_195 ;
V_195 = * ( ( unsigned long * ) & V_9 -> V_40 [ V_196 ] ) ;
V_197:
if ( V_195 & F_15 ( V_198 , V_165 ) ) {
F_25 ( F_20 ( V_9 -> line , L_47 , 0 ) ) ;
}
F_34 ( F_20 ( V_9 -> line , L_48 , F_69 ( V_198 , V_199 , V_195 ) ) ) ;
if ( V_195 & ( F_15 ( V_198 , V_200 ) |
F_15 ( V_198 , V_201 ) |
F_15 ( V_198 , V_202 ) ) ) {
V_9 -> V_203 = F_72 () ;
V_9 -> V_204 = V_5 ;
F_19 ( F_20 ( V_9 -> line , L_49 , V_195 ) ) ;
F_88 (
if (!log_int_trig1_pos) {
log_int_trig1_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
) ;
if ( ( ( V_195 & F_15 ( V_198 , V_199 ) ) == 0 ) &&
( V_195 & F_15 ( V_198 , V_200 ) ) ) {
if ( ! V_9 -> V_205 ) {
F_20 ( V_9 -> line , L_50 , 0 ) ;
}
if ( V_195 & F_15 ( V_198 , V_206 ) ) {
F_20 ( V_9 -> line , L_51 , 0 ) ;
V_9 -> V_150 = V_162 ;
}
V_9 -> V_205 ++ ;
} else {
if ( V_9 -> V_205 ) {
F_20 ( V_9 -> line , L_52 , V_9 -> V_205 ) ;
V_9 -> V_150 = V_162 ;
} else {
unsigned char V_88 = F_69 ( V_198 ,
V_199 , V_195 ) ;
char V_146 = V_141 ;
if ( V_9 -> V_150 == V_162 ) {
F_59 ( & V_9 -> V_11 , 0 , V_146 ) ;
V_9 -> V_120 . V_147 ++ ;
}
if ( V_195 & F_15 ( V_198 , V_201 ) ) {
V_9 -> V_120 . V_207 ++ ;
V_146 = V_169 ;
} else if ( V_195 & F_15 ( V_198 , V_202 ) ) {
V_9 -> V_120 . V_202 ++ ;
V_146 = V_171 ;
} else if ( V_195 & F_15 ( V_198 , V_200 ) ) {
V_9 -> V_120 . V_208 ++ ;
V_146 = V_173 ;
}
F_59 ( & V_9 -> V_11 , V_88 , V_146 ) ;
V_9 -> V_150 = 0 ;
}
V_9 -> V_205 = 0 ;
}
} else if ( V_195 & F_15 ( V_198 , V_209 ) ) {
F_88 (
if (!log_int_trig1_pos) {
if (log_int_pos >= log_int_size) {
log_int_pos = 0;
}
log_int_trig0_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
) ;
F_59 ( & V_9 -> V_11 ,
F_69 ( V_198 , V_199 , V_195 ) ,
V_141 ) ;
} else {
F_20 ( V_9 -> line , L_53 , V_195 ) ;
}
V_9 -> V_120 . V_147 ++ ;
V_195 = * ( ( unsigned long * ) & V_9 -> V_40 [ V_196 ] ) ;
if ( V_195 & F_15 ( V_198 , V_209 ) ) {
F_20 ( V_9 -> line , L_54 , F_69 ( V_198 , V_199 , V_195 ) ) ;
goto V_197;
}
F_81 ( & V_9 -> V_11 ) ;
}
static void F_89 ( struct V_8 * V_9 )
{
unsigned char V_160 ;
#ifdef F_18
F_5 ( L_55 , V_176 ) ;
#endif
if ( ! V_9 -> V_73 ) {
F_87 ( V_9 ) ;
return;
}
V_160 = V_9 -> V_40 [ V_163 ] ;
if ( V_160 & F_15 ( V_164 , V_165 ) ) {
F_25 ( F_20 ( V_9 -> line , L_47 , 0 ) ) ;
}
if ( V_160 & V_166 ) {
unsigned char V_88 ;
V_9 -> V_203 = F_72 () ;
V_9 -> V_204 = V_5 ;
V_88 = V_9 -> V_40 [ V_167 ] ;
F_19 ( F_20 ( V_9 -> line , L_56 , V_88 ) ) ;
F_19 ( F_20 ( V_9 -> line , L_57 , V_160 ) ) ;
if ( ! V_88 && ( V_160 & V_172 ) ) {
if ( ! V_9 -> V_205 ) {
F_20 ( V_9 -> line , L_50 , 0 ) ;
}
if ( V_160 & V_210 ) {
F_20 ( V_9 -> line , L_51 , 0 ) ;
V_9 -> V_150 = V_162 ;
}
V_9 -> V_205 ++ ;
} else {
if ( V_9 -> V_205 ) {
F_20 ( V_9 -> line , L_52 , V_9 -> V_205 ) ;
V_9 -> V_150 = V_162 ;
} else {
if ( V_9 -> V_150 == V_162 ) {
V_9 -> V_120 . V_211 ++ ;
F_58 ( V_9 , '\0' , V_152 ) ;
}
if ( V_160 & V_168 ) {
V_9 -> V_120 . V_207 ++ ;
F_58 ( V_9 , V_88 , V_169 ) ;
} else if ( V_160 & V_170 ) {
V_9 -> V_120 . V_202 ++ ;
F_58 ( V_9 , V_88 , V_171 ) ;
} else if ( V_160 & V_172 ) {
V_9 -> V_120 . V_208 ++ ;
F_58 ( V_9 , V_88 , V_173 ) ;
}
V_9 -> V_150 = 0 ;
}
V_9 -> V_205 = 0 ;
F_20 ( V_9 -> line , L_58 ,
( ( V_160 & V_166 ) << 8 ) | V_88 ) ;
}
} else {
unsigned long V_212 = F_72 () ;
unsigned long V_213 = V_5 ;
if ( V_9 -> V_205 ) {
long V_214 =
( V_213 - V_9 -> V_204 ) * ( 1000000 / V_215 ) +
V_212 - V_9 -> V_203 ;
if ( V_214 < 2 * V_9 -> V_20 ) {
F_20 ( V_9 -> line , L_59 , V_9 -> line ) ;
V_9 -> V_150 = V_151 ;
} else {
F_20 ( V_9 -> line , L_60 , V_9 -> line ) ;
}
F_20 ( V_9 -> line , L_61 , V_9 -> V_205 ) ;
}
#ifdef F_18
F_5 ( L_62 ) ;
#endif
F_30 ( V_9 ) ;
F_34 ( F_20 ( V_9 -> line , L_63 , V_9 -> line ) ) ;
V_9 -> V_205 = 0 ;
}
* V_9 -> V_174 = F_26 ( V_132 , V_133 , V_175 ) ;
F_66 ( V_9 , L_64 ) ;
}
static void F_90 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
if ( V_9 -> V_216 ) {
unsigned char V_160 ;
F_25 ( F_20 ( V_9 -> line , L_65 , V_9 -> V_216 ) ) ;
F_9 ( V_36 ) ;
V_160 = V_9 -> V_40 [ V_163 ] ;
F_25 ( F_20 ( V_9 -> line , L_66 , V_160 ) ) ;
V_9 -> V_40 [ V_217 ] = V_9 -> V_216 ;
V_9 -> V_120 . V_121 ++ ;
V_9 -> V_216 = 0 ;
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
return;
}
if ( V_9 -> V_105 ) {
unsigned char V_160 ;
int V_176 ;
F_25 ( F_20 ( V_9 -> line , L_67 , 0 ) ) ;
F_9 ( V_36 ) ;
V_160 = V_9 -> V_40 [ V_163 ] ;
F_25 ( F_20 ( V_9 -> line , L_66 , V_160 ) ) ;
F_32 ( V_9 ) ;
if ( V_9 -> V_11 . V_12 -> V_218 )
F_42 ( V_9 -> V_11 . V_12 ) ;
F_27 ( V_9 ) ;
for( V_176 = 6 ; V_176 > 0 ; V_176 -- )
F_91 () ;
* V_9 -> V_131 = F_26 (R_DMA_CH6_CMD, cmd, continue) ;
F_10 ( V_36 ) ;
return;
}
if ( V_9 -> V_94 . V_95 == V_9 -> V_94 . V_96
|| V_9 -> V_11 . V_12 -> V_218 ) {
F_25 ( F_20 ( V_9 -> line , L_68 ,
V_9 -> V_11 . V_12 -> V_218 ) ) ;
F_32 ( V_9 ) ;
V_9 -> V_114 = 0 ;
return;
}
F_34 ( F_20 ( V_9 -> line , L_69 , V_9 -> V_94 . V_84 [ V_9 -> V_94 . V_96 ] ) ) ;
F_9 ( V_36 ) ;
V_9 -> V_40 [ V_217 ] = V_9 -> V_94 . V_84 [ V_9 -> V_94 . V_96 ] ;
V_9 -> V_94 . V_96 = ( V_9 -> V_94 . V_96 + 1 ) & ( V_97 - 1 ) ;
V_9 -> V_120 . V_121 ++ ;
if ( V_9 -> V_94 . V_95 == V_9 -> V_94 . V_96 ) {
#if F_38 ( V_124 ) && F_38 ( V_125 )
if ( V_9 -> V_82 . V_36 & V_87 ) {
F_52 ( & V_89 [ V_9 -> line ] ,
F_41 ,
( unsigned long ) V_9 ,
V_9 -> V_20 * 2 ,
L_30 ) ;
}
#endif
V_9 -> V_186 = F_72 () ;
V_9 -> V_187 = V_5 ;
F_32 ( V_9 ) ;
V_9 -> V_114 = 0 ;
F_25 ( F_20 ( V_9 -> line , L_70 , 0 ) ) ;
} else {
F_33 ( V_9 ) ;
}
F_10 ( V_36 ) ;
if ( F_43 ( V_9 -> V_94 . V_95 ,
V_9 -> V_94 . V_96 ,
V_97 ) < V_122 )
F_48 ( V_9 , V_123 ) ;
}
static T_2
F_92 ( int V_51 , void * V_179 )
{
static volatile int V_219 = 0 ;
struct V_8 * V_9 ;
int V_176 ;
unsigned long V_36 ;
unsigned long V_220 ;
unsigned long V_221 = ( 1 << ( 8 + 2 * 0 ) ) ;
int V_181 = 0 ;
static volatile unsigned long V_222 = 0 ;
F_9 ( V_36 ) ;
V_220 = * V_223 ;
V_9 = V_184 ;
V_220 &= V_224 ;
for ( V_176 = 0 ; V_176 < V_183 ; V_176 ++ ) {
if ( V_220 & V_221 ) {
V_181 = 1 ;
F_89 ( V_9 ) ;
}
V_9 += 1 ;
V_221 <<= 2 ;
}
if ( ! V_219 ) {
unsigned long V_225 ;
unsigned long
V_219 = 1 ;
V_220 &= ( F_15 ( V_223 , V_226 ) |
F_15 ( V_223 , V_227 ) |
F_15 ( V_223 , V_228 ) |
F_15 ( V_223 , V_229 ) ) ;
while ( V_220 ) {
* V_71 = V_220 ;
* V_230 = F_26 ( V_230 , V_231 , V_31 ) ;
F_93 () ;
V_225 = ( 1 << ( 8 + 1 + 2 * 0 ) ) ;
V_9 = V_184 ;
for ( V_176 = 0 ; V_176 < V_183 ; V_176 ++ ) {
if ( V_220 & V_225 ) {
V_181 = 1 ;
F_90 ( V_9 ) ;
}
V_9 += 1 ;
V_225 <<= 2 ;
}
F_94 () ;
V_220 = V_222 ;
}
F_94 () ;
V_219 = 0 ;
} else {
unsigned long V_225 ;
V_225 = V_220 & ( F_15 ( V_223 , V_226 ) |
F_15 ( V_223 , V_227 ) |
F_15 ( V_223 , V_228 ) |
F_15 ( V_223 , V_229 ) ) ;
if ( V_225 ) {
V_222 |= V_225 ;
* V_71 = V_225 ;
F_25 ( F_20 ( V_113 , L_71 , V_225 ) ) ;
}
}
F_10 ( V_36 ) ;
return F_73 ( V_181 ) ;
}
static void
F_95 ( struct V_232 * V_107 )
{
struct V_8 * V_9 ;
struct V_74 * V_12 ;
V_9 = F_96 ( V_107 , struct V_8 , V_107 ) ;
V_12 = V_9 -> V_11 . V_12 ;
if ( ! V_12 )
return;
if ( F_97 ( V_123 , & V_9 -> V_106 ) )
F_98 ( V_12 ) ;
}
static int
F_99 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
unsigned long V_233 ;
int V_176 ;
V_233 = F_100 ( V_234 ) ;
if ( ! V_233 )
return - V_235 ;
F_9 ( V_36 ) ;
if ( F_101 ( & V_9 -> V_11 ) ) {
F_10 ( V_36 ) ;
F_102 ( V_233 ) ;
return 0 ;
}
if ( V_9 -> V_94 . V_84 )
F_102 ( V_233 ) ;
else
V_9 -> V_94 . V_84 = ( unsigned char * ) V_233 ;
#ifdef F_103
F_5 ( L_72 , V_9 -> line , V_9 -> V_94 . V_84 ) ;
#endif
if ( V_9 -> V_236 ) {
V_9 -> V_73 = 1 ;
F_29 ( V_9 ) ;
* V_9 -> V_174 = F_26 ( V_132 , V_133 , V_178 ) ;
while ( F_69 ( V_132 , V_133 , * V_9 -> V_174 ) ==
F_70 ( V_132 , V_133 , V_178 ) ) ;
* V_9 -> V_161 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
} else {
F_28 ( V_9 ) ;
}
if ( V_9 -> V_237 ) {
V_9 -> V_105 = 1 ;
F_27 ( V_9 ) ;
* V_9 -> V_131 = F_26 ( V_132 , V_133 , V_178 ) ;
while ( F_69 ( V_132 , V_133 , * V_9 -> V_131 ) ==
F_70 ( V_132 , V_133 , V_178 ) ) ;
* V_9 -> V_112 =
F_26 (R_DMA_CH6_CLR_INTR, clr_descr, do) |
F_26 (R_DMA_CH6_CLR_INTR, clr_eop, do) ;
} else {
F_24 ( V_9 ) ;
}
if ( V_9 -> V_11 . V_12 )
F_104 ( V_238 , & V_9 -> V_11 . V_12 -> V_36 ) ;
V_9 -> V_94 . V_95 = V_9 -> V_94 . V_96 = 0 ;
V_9 -> V_142 = V_9 -> V_143 = NULL ;
V_9 -> V_144 = V_9 -> V_145 = 0 ;
for ( V_176 = 0 ; V_176 < V_158 ; V_176 ++ )
V_9 -> V_155 [ V_176 ] . V_84 = 0 ;
#ifdef F_65
F_31 ( V_9 ) ;
#endif
F_105 ( V_9 ) ;
( void ) V_9 -> V_40 [ V_167 ] ;
if ( V_9 -> V_105 )
F_23 ( V_9 ) ;
F_35 ( V_9 ) ;
V_9 -> V_114 = 0 ;
F_68 ( V_9 ) ;
V_9 -> V_115 . V_118 = 0 ;
V_9 -> V_115 . V_119 = 0 ;
V_9 -> V_115 . V_116 = 0 ;
F_11 ( V_9 , 1 ) ;
F_6 ( V_9 , 1 ) ;
F_106 ( & V_9 -> V_11 , 1 ) ;
F_10 ( V_36 ) ;
return 0 ;
}
static void
F_107 ( struct V_8 * V_9 )
{
unsigned long V_36 ;
struct V_110 * V_111 = V_9 -> V_155 ;
struct V_135 * V_137 ;
int V_176 ;
F_25 ( F_20 ( V_9 -> line , L_73 , V_9 -> line ) ) ;
F_14 ( V_9 ) ;
V_9 -> V_40 [ V_239 ] = ( V_9 -> V_240 &= ~ 0x40 ) ;
if ( V_9 -> V_73 ) {
F_17 ( V_9 ) ;
* V_9 -> V_174 = F_26 ( V_132 , V_133 , V_178 ) ;
V_9 -> V_73 = 0 ;
} else {
F_30 ( V_9 ) ;
}
if ( V_9 -> V_105 ) {
F_22 ( V_9 ) ;
V_9 -> V_114 = 0 ;
* V_9 -> V_131 = F_26 ( V_132 , V_133 , V_178 ) ;
V_9 -> V_105 = 0 ;
} else {
F_32 ( V_9 ) ;
V_9 -> V_114 = 0 ;
}
if ( ! F_101 ( & V_9 -> V_11 ) )
return;
#ifdef F_103
F_5 ( L_74 , V_9 -> line ,
V_9 -> V_51 ) ;
#endif
F_9 ( V_36 ) ;
if ( V_9 -> V_94 . V_84 ) {
F_102 ( ( unsigned long ) V_9 -> V_94 . V_84 ) ;
V_9 -> V_94 . V_84 = NULL ;
}
for ( V_176 = 0 ; V_176 < V_158 ; V_176 ++ )
if ( V_111 [ V_176 ] . V_84 ) {
V_137 = F_61 ( V_111 [ V_176 ] . V_84 ) - sizeof *V_137 ;
F_80 ( V_137 ) ;
V_111 [ V_176 ] . V_84 = 0 ;
}
if ( ! V_9 -> V_11 . V_12 || ( V_9 -> V_11 . V_12 -> V_13 . V_14 & V_241 ) ) {
F_6 ( V_9 , 0 ) ;
F_11 ( V_9 , 0 ) ;
}
if ( V_9 -> V_11 . V_12 )
F_108 ( V_238 , & V_9 -> V_11 . V_12 -> V_36 ) ;
F_106 ( & V_9 -> V_11 , 0 ) ;
F_10 ( V_36 ) ;
}
static void
F_105 ( struct V_8 * V_9 )
{
unsigned int V_24 ;
unsigned long V_93 ;
unsigned long V_36 ;
if ( ! V_9 -> V_11 . V_12 )
return;
if ( ! V_9 -> V_40 )
return;
V_24 = V_9 -> V_11 . V_12 -> V_13 . V_14 ;
if ( ( V_9 -> V_11 . V_36 & V_242 ) == V_243 ) {
T_3 V_32 = 0xFF << ( V_9 -> line * 8 ) ;
unsigned long V_244 =
F_26 ( V_245 , V_246 , V_247 ) |
F_26 ( V_245 , V_248 , V_247 ) ;
F_109 ( F_5 ( L_75 ,
( unsigned long ) V_9 -> V_249 , V_9 -> V_250 ) ) ;
if ( V_9 -> V_249 == V_251 ) {
T_4 V_252 = V_9 -> V_250 ;
V_244 =
F_26 ( V_245 , V_246 , V_253 ) |
F_26 ( V_245 , V_248 , V_253 ) ;
V_244 = 0x11 ;
F_109 ( F_5 ( L_76 , V_252 ) ) ;
* V_254 = V_252 ;
V_9 -> V_21 = V_251 / V_252 ;
}
else
{
F_5 ( V_30 L_77 ,
( unsigned long ) V_9 -> V_249 , V_9 -> V_250 ) ;
}
V_255 &= ~ V_32 ;
V_255 |= ( V_244 << ( V_9 -> line * 8 ) ) ;
* V_245 = V_255 ;
} else {
T_3 V_32 = 0xFF << ( V_9 -> line * 8 ) ;
unsigned long V_244 =
F_26 ( V_245 , V_246 , V_247 ) |
F_26 ( V_245 , V_248 , V_247 ) ;
V_255 &= ~ V_32 ;
V_255 |= ( V_244 << ( V_9 -> line * 8 ) ) ;
* V_245 = V_255 ;
V_9 -> V_21 = F_3 ( V_24 ) ;
V_9 -> V_40 [ V_256 ] = F_4 ( V_24 ) ;
}
F_9 ( V_36 ) ;
V_9 -> V_38 &= ~ ( F_15 ( V_48 , V_257 ) |
F_15 ( V_48 , V_258 ) |
F_15 ( V_48 , V_259 ) ) ;
V_9 -> V_240 &= ~ ( F_15 ( V_260 , V_261 ) |
F_15 ( V_260 , V_262 ) |
F_15 ( V_260 , V_263 ) |
F_15 ( V_260 , V_264 ) |
F_15 ( V_260 , V_265 ) ) ;
if ( ( V_24 & V_16 ) == V_17 ) {
V_9 -> V_240 |= F_26 ( V_260 , V_261 , V_266 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_257 , V_267 ) ;
}
if ( V_24 & V_18 ) {
V_9 -> V_240 |= F_26 ( V_260 , V_264 , V_268 ) ;
}
if ( V_24 & V_19 ) {
V_9 -> V_240 |= F_26 ( V_260 , V_262 , V_103 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_258 , V_103 ) ;
}
if ( V_24 & V_269 ) {
V_9 -> V_240 |= F_26 ( V_260 , V_270 , V_271 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_272 , V_271 ) ;
}
if ( V_24 & V_273 ) {
V_9 -> V_240 |= F_26 ( V_260 , V_263 , V_274 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_259 , V_274 ) ;
}
if ( V_24 & V_275 ) {
F_25 ( F_20 ( V_9 -> line , L_78 , 0 ) ) ;
V_9 -> V_240 |= F_26 ( V_260 , V_265 , V_276 ) ;
}
V_9 -> V_240 |= F_26 ( V_260 , V_277 , V_103 ) ;
V_9 -> V_38 |= F_26 ( V_48 , V_49 , V_103 ) ;
V_9 -> V_40 [ V_239 ] = V_9 -> V_240 ;
V_9 -> V_40 [ V_41 ] = V_9 -> V_38 ;
V_93 = F_44 ( V_98 , V_99 , F_45 ( V_9 -> V_11 . V_12 ) ) ;
V_93 |= F_26 ( V_98 , V_100 , V_103 ) ;
if ( V_9 -> V_11 . V_12 -> V_13 . V_278 & V_279 ) {
F_25 ( F_20 ( V_9 -> line , L_79 ,
F_45 ( V_9 -> V_11 . V_12 ) ) ) ;
V_93 |= F_26 ( V_98 , V_102 , V_103 ) ;
}
* ( ( unsigned long * ) & V_9 -> V_40 [ V_104 ] ) = V_93 ;
F_10 ( V_36 ) ;
F_2 ( V_9 ) ;
}
static void
F_110 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( V_9 -> V_114 ||
V_9 -> V_94 . V_95 == V_9 -> V_94 . V_96 ||
V_12 -> V_218 ||
! V_9 -> V_94 . V_84 )
return;
#ifdef F_111
F_5 ( L_80 ) ;
#endif
F_9 ( V_36 ) ;
F_54 ( V_9 ) ;
F_10 ( V_36 ) ;
}
static int F_112 ( struct V_74 * V_12 ,
const unsigned char * V_84 , int V_85 )
{
int V_108 , V_154 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 -> V_94 . V_84 )
return 0 ;
#ifdef F_113
if ( V_9 -> line == V_113 )
F_5 ( L_81 ,
V_85 , V_9 -> V_40 [ V_163 ] ) ;
#endif
F_114 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_82 , V_85 ) ) ;
F_25 ( F_20 ( V_9 -> line , L_83 ) ) ;
F_94 () ;
while ( V_85 ) {
V_108 = F_115 ( V_9 -> V_94 . V_95 ,
V_9 -> V_94 . V_96 ,
V_97 ) ;
if ( V_85 < V_108 )
V_108 = V_85 ;
if ( V_108 <= 0 )
break;
memcpy ( V_9 -> V_94 . V_84 + V_9 -> V_94 . V_95 , V_84 , V_108 ) ;
V_9 -> V_94 . V_95 = ( V_9 -> V_94 . V_95 + V_108 ) &
( V_97 - 1 ) ;
V_84 += V_108 ;
V_85 -= V_108 ;
V_154 += V_108 ;
}
F_10 ( V_36 ) ;
F_25 ( F_20 ( V_9 -> line , L_84 , V_154 ) ) ;
if ( V_9 -> V_94 . V_95 != V_9 -> V_94 . V_96 &&
! V_12 -> V_218 &&
! V_9 -> V_114 ) {
F_54 ( V_9 ) ;
}
return V_154 ;
}
static int
F_40 ( struct V_74 * V_12 ,
const unsigned char * V_84 , int V_85 )
{
#if F_38 ( V_124 )
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( V_9 -> V_82 . V_36 & V_87 )
{
#ifdef V_125
V_89 [ V_9 -> line ] . V_90 = NULL ;
F_116 ( & V_89 [ V_9 -> line ] ) ;
#endif
F_11 ( V_9 , ( V_9 -> V_82 . V_36 & V_280 ) ) ;
#if F_38 ( V_92 )
F_14 ( V_9 ) ;
F_35 ( V_9 ) ;
#endif
if ( V_9 -> V_82 . V_83 > 0 )
F_117 ( V_9 -> V_82 . V_83 ) ;
}
#endif
V_85 = F_112 ( V_12 , V_84 , V_85 ) ;
#if F_38 ( V_124 )
if ( V_9 -> V_82 . V_36 & V_87 )
{
unsigned int V_281 ;
F_118 ( V_12 , 0 ) ;
#ifdef V_125
F_119 ( V_9 -> V_20 * 2 ) ;
#endif
do{
F_120 ( V_9 , & V_281 ) ;
}while ( ! ( V_281 & V_282 ) );
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
F_121 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
return F_122 ( V_9 -> V_94 . V_95 , V_9 -> V_94 . V_96 , V_97 ) ;
}
static int
F_123 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
return F_43 ( V_9 -> V_94 . V_95 , V_9 -> V_94 . V_96 , V_97 ) ;
}
static void
F_124 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
V_9 -> V_94 . V_95 = V_9 -> V_94 . V_96 = 0 ;
F_10 ( V_36 ) ;
F_98 ( V_12 ) ;
}
static void F_125 ( struct V_74 * V_12 , char V_283 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( V_9 -> V_105 ) {
* V_9 -> V_131 = F_26 ( V_132 , V_133 , V_284 ) ;
while ( F_69 ( V_132 , V_133 , * V_9 -> V_131 ) !=
F_70 ( V_132 , V_133 , V_284 ) ) ;
F_24 ( V_9 ) ;
}
if ( V_12 -> V_218 )
F_47 ( V_12 ) ;
F_25 ( F_20 ( V_9 -> line , L_85 , V_283 ) ) ;
V_9 -> V_216 = V_283 ;
F_33 ( V_9 ) ;
F_10 ( V_36 ) ;
}
static void
F_126 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#ifdef F_127
F_5 ( L_86 , F_128 ( V_12 ) ) ;
#endif
F_25 ( F_20 ( V_9 -> line , L_87 ) ) ;
if ( F_129 ( V_12 ) ) {
F_11 ( V_9 , 0 ) ;
}
if ( F_130 ( V_12 ) )
F_125 ( V_12 , F_45 ( V_12 ) ) ;
}
static void
F_131 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
#ifdef F_127
F_5 ( L_88 , F_128 ( V_12 ) ) ;
#endif
F_25 ( F_20 ( V_9 -> line , L_89 ) ) ;
F_25 ( F_20 ( V_9 -> line , L_90 , V_12 -> V_285 . V_85 ) ) ;
if ( F_129 ( V_12 ) ) {
F_11 ( V_9 , 1 ) ;
}
if ( F_130 ( V_12 ) ) {
if ( V_9 -> V_216 )
V_9 -> V_216 = 0 ;
else
F_125 ( V_12 , F_132 ( V_12 ) ) ;
}
}
static int
F_133 ( struct V_8 * V_9 ,
struct V_286 * V_287 )
{
struct V_286 V_288 ;
if ( ! V_287 )
return - V_289 ;
memset ( & V_288 , 0 , sizeof( V_288 ) ) ;
V_288 . type = V_9 -> type ;
V_288 . line = V_9 -> line ;
V_288 . V_11 = ( int ) V_9 -> V_40 ;
V_288 . V_51 = V_9 -> V_51 ;
V_288 . V_36 = V_9 -> V_11 . V_36 ;
V_288 . V_249 = V_9 -> V_249 ;
V_288 . V_290 = V_9 -> V_11 . V_290 ;
V_288 . V_291 = V_9 -> V_11 . V_291 ;
V_288 . V_250 = V_9 -> V_250 ;
if ( F_134 ( V_287 , & V_288 , sizeof( * V_287 ) ) )
return - V_289 ;
return 0 ;
}
static int
F_135 ( struct V_8 * V_9 ,
struct V_286 * V_292 )
{
struct V_286 V_293 ;
struct V_8 V_294 ;
int V_29 = 0 ;
if ( F_136 ( & V_293 , V_292 , sizeof( V_293 ) ) )
return - V_289 ;
V_294 = * V_9 ;
if ( ! F_137 ( V_295 ) ) {
if ( ( V_293 . type != V_9 -> type ) ||
( V_293 . V_290 != V_9 -> V_11 . V_290 ) ||
( ( V_293 . V_36 & ~ V_296 ) !=
( V_9 -> V_11 . V_36 & ~ V_296 ) ) )
return - V_297 ;
V_9 -> V_11 . V_36 = ( ( V_9 -> V_11 . V_36 & ~ V_296 ) |
( V_293 . V_36 & V_296 ) ) ;
goto V_298;
}
if ( V_9 -> V_11 . V_85 > 1 )
return - V_299 ;
V_9 -> V_249 = V_293 . V_249 ;
V_9 -> V_11 . V_36 = ( ( V_9 -> V_11 . V_36 & ~ V_300 ) |
( V_293 . V_36 & V_300 ) ) ;
V_9 -> V_250 = V_293 . V_250 ;
V_9 -> type = V_293 . type ;
V_9 -> V_11 . V_290 = V_293 . V_290 ;
V_9 -> V_11 . V_291 = V_293 . V_291 ;
V_9 -> V_11 . V_301 = ( V_9 -> V_11 . V_36 & V_302 ) ? 1 : 0 ;
V_298:
if ( F_101 ( & V_9 -> V_11 ) )
F_105 ( V_9 ) ;
else
V_29 = F_99 ( V_9 ) ;
return V_29 ;
}
static int
F_120 ( struct V_8 * V_9 , unsigned int * V_1 )
{
unsigned int V_303 = V_282 ;
unsigned long V_213 = V_5 ;
unsigned long V_304 = F_72 () ;
unsigned long V_214 =
( V_213 - V_9 -> V_187 ) * 1000000 / V_215 +
V_304 - V_9 -> V_186 ;
if ( V_9 -> V_94 . V_95 != V_9 -> V_94 . V_96 ||
V_214 < 2 * V_9 -> V_20 ) {
V_303 = 0 ;
}
if ( F_134 ( V_1 , & V_303 , sizeof( int ) ) )
return - V_289 ;
return 0 ;
}
char * F_138 ( int V_305 , char * V_306 )
{
int V_176 = 0 ;
V_306 [ 0 ] = '\0' ;
while ( V_307 [ V_176 ] . V_308 != NULL ) {
if ( V_305 & V_307 [ V_176 ] . V_309 ) {
if ( V_306 [ 0 ] != '\0' ) {
strcat ( V_306 , L_91 ) ;
}
strcat ( V_306 , V_307 [ V_176 ] . V_308 ) ;
}
V_176 ++ ;
}
return V_306 ;
}
static int
F_139 ( struct V_74 * V_12 , int V_310 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 -> V_40 )
return - V_311 ;
F_9 ( V_36 ) ;
if ( V_310 == - 1 ) {
V_9 -> V_240 &= 0x3F ;
} else {
V_9 -> V_240 |= ( 0x80 | 0x40 ) ;
}
V_9 -> V_40 [ V_239 ] = V_9 -> V_240 ;
F_10 ( V_36 ) ;
return 0 ;
}
static int
F_140 ( struct V_74 * V_12 , unsigned int V_31 , unsigned int V_312 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
if ( V_312 & V_313 )
F_11 ( V_9 , 0 ) ;
if ( V_312 & V_314 )
F_6 ( V_9 , 0 ) ;
if ( V_312 & V_315 )
F_12 ( V_9 , 0 ) ;
if ( V_312 & V_316 )
F_13 ( V_9 , 0 ) ;
if ( V_31 & V_313 )
F_11 ( V_9 , 1 ) ;
if ( V_31 & V_314 )
F_6 ( V_9 , 1 ) ;
if ( V_31 & V_315 )
F_12 ( V_9 , 1 ) ;
if ( V_31 & V_316 )
F_13 ( V_9 , 1 ) ;
F_10 ( V_36 ) ;
return 0 ;
}
static int
F_141 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned int V_303 ;
unsigned long V_36 ;
F_9 ( V_36 ) ;
V_303 =
( ! F_142 ( V_9 ) ? V_313 : 0 )
| ( ! F_8 ( V_9 ) ? V_314 : 0 )
| ( ! F_143 ( V_9 ) ? V_317 : 0 )
| ( ! F_144 ( V_9 ) ? V_318 : 0 )
| ( ! F_145 ( V_9 ) ? V_319 : 0 )
| ( ! F_146 ( V_9 ) ? V_320 : 0 ) ;
F_10 ( V_36 ) ;
#ifdef F_7
F_5 ( V_321 L_92 ,
V_9 -> line , V_303 , V_303 ) ;
{
char V_306 [ 100 ] ;
F_138 ( V_303 , V_306 ) ;
F_5 ( V_321 L_93 , V_306 ) ;
}
#endif
return V_303 ;
}
static int
F_147 ( struct V_74 * V_12 ,
unsigned int V_133 , unsigned long V_322 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
if ( ( V_133 != V_323 ) && ( V_133 != V_324 ) &&
( V_133 != V_325 ) && ( V_133 != V_326 ) &&
( V_133 != V_327 ) && ( V_133 != V_328 ) ) {
if ( F_148 ( V_12 ) )
return - V_311 ;
}
switch ( V_133 ) {
case V_323 :
return F_133 ( V_9 ,
(struct V_286 * ) V_322 ) ;
case V_324 :
return F_135 ( V_9 ,
(struct V_286 * ) V_322 ) ;
case V_329 :
return F_120 ( V_9 , ( unsigned int * ) V_322 ) ;
case V_328 :
if ( F_134 ( (struct V_8 * ) V_322 ,
V_9 , sizeof( struct V_8 ) ) )
return - V_289 ;
return 0 ;
#if F_38 ( V_124 )
case V_330 :
{
struct V_331 V_332 ;
struct V_75 V_333 ;
F_5 ( V_321 L_94 ) ;
if ( F_136 ( & V_332 , (struct V_331 * ) V_322 ,
sizeof( V_332 ) ) )
return - V_289 ;
V_333 . V_83 = V_332 . V_83 ;
V_333 . V_36 = 0 ;
if ( V_332 . V_185 )
V_333 . V_36 |= V_87 ;
else
V_333 . V_36 &= ~ ( V_87 ) ;
if ( V_332 . V_334 )
V_333 . V_36 |= V_280 ;
else
V_333 . V_36 &= ~ ( V_280 ) ;
if ( V_332 . V_335 )
V_333 . V_36 |= V_91 ;
else
V_333 . V_36 &= ~ ( V_91 ) ;
return F_37 ( V_12 , & V_333 ) ;
}
case V_336 :
{
struct V_75 V_333 ;
if ( F_136 ( & V_333 , (struct V_331 * ) V_322 ,
sizeof( V_333 ) ) )
return - V_289 ;
return F_37 ( V_12 , & V_333 ) ;
}
case V_337 :
{
struct V_75 * V_333 =
& ( ( (struct V_8 * ) V_12 -> V_77 ) -> V_82 ) ;
if ( F_134 ( (struct V_75 * ) V_322 ,
V_333 ,
sizeof( struct V_75 ) ) )
return - V_289 ;
break;
}
case V_338 :
{
struct V_339 V_340 ;
if ( F_136 ( & V_340 , (struct V_339 * ) V_322 ,
sizeof( V_340 ) ) )
return - V_289 ;
return F_39 ( V_12 , V_340 . V_341 , V_340 . V_342 ) ;
}
#endif
default:
return - V_343 ;
}
return 0 ;
}
static void
F_149 ( struct V_74 * V_12 , struct V_344 * V_345 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
F_105 ( V_9 ) ;
if ( ( V_345 -> V_14 & V_275 ) && ! F_129 ( V_12 ) )
F_47 ( V_12 ) ;
}
static void
F_150 ( struct V_74 * V_12 , struct V_346 * V_347 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_36 ;
if ( ! V_9 )
return;
F_9 ( V_36 ) ;
if ( F_151 ( V_347 ) ) {
F_10 ( V_36 ) ;
return;
}
#ifdef F_103
F_5 ( L_95 , V_348 -> V_349 ,
V_9 -> line , V_9 -> V_85 ) ;
#endif
if ( ( V_12 -> V_85 == 1 ) && ( V_9 -> V_11 . V_85 != 1 ) ) {
F_5 ( V_350
L_96
L_97 , V_9 -> V_11 . V_85 ) ;
V_9 -> V_11 . V_85 = 1 ;
}
if ( -- V_9 -> V_11 . V_85 < 0 ) {
F_5 ( V_350 L_98 ,
V_9 -> line , V_9 -> V_11 . V_85 ) ;
V_9 -> V_11 . V_85 = 0 ;
}
if ( V_9 -> V_11 . V_85 ) {
F_10 ( V_36 ) ;
return;
}
V_12 -> V_351 = 1 ;
if ( V_9 -> V_11 . V_291 != V_352 )
F_118 ( V_12 , V_9 -> V_11 . V_291 ) ;
#ifdef F_65
F_30 ( V_9 ) ;
#endif
F_14 ( V_9 ) ;
F_36 ( V_9 ) ;
if ( F_101 ( & V_9 -> V_11 ) ) {
F_152 ( V_12 , V_215 ) ;
}
F_107 ( V_9 ) ;
F_124 ( V_12 ) ;
F_153 ( V_12 ) ;
V_12 -> V_351 = 0 ;
V_9 -> V_106 = 0 ;
V_9 -> V_11 . V_12 = NULL ;
if ( V_9 -> V_11 . V_353 ) {
if ( V_9 -> V_11 . V_290 )
F_154 ( V_9 -> V_11 . V_290 ) ;
F_155 ( & V_9 -> V_11 . V_354 ) ;
}
F_10 ( V_36 ) ;
F_156 ( & V_9 -> V_11 , 0 ) ;
#if F_38 ( V_124 )
if ( V_9 -> V_82 . V_36 & V_87 ) {
V_9 -> V_82 . V_36 &= ~ ( V_87 ) ;
#if F_38 ( V_78 )
* V_79 = V_80 &= ~ ( 1 << V_81 ) ;
#endif
}
#endif
if ( V_9 -> V_236 ) {
F_157 ( V_9 -> V_355 , V_9 ) ;
F_158 ( V_9 -> V_356 , V_9 -> V_357 ) ;
V_9 -> V_73 = 0 ;
#ifdef F_103
F_5 ( V_321 L_99 ,
V_9 -> V_357 ) ;
#endif
}
if ( V_9 -> V_237 ) {
F_157 ( V_9 -> V_358 , V_9 ) ;
F_158 ( V_9 -> V_359 , V_9 -> V_360 ) ;
V_9 -> V_105 = 0 ;
#ifdef F_103
F_5 ( V_321 L_99 ,
V_9 -> V_360 ) ;
#endif
}
}
static void F_152 ( struct V_74 * V_12 , int V_361 )
{
unsigned long V_362 ;
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
unsigned long V_213 = V_5 ;
unsigned long V_304 = F_72 () ;
long V_214 =
( V_213 - V_9 -> V_187 ) * ( 1000000 / V_215 ) +
V_304 - V_9 -> V_186 ;
V_362 = V_5 ;
while ( V_9 -> V_94 . V_95 != V_9 -> V_94 . V_96 ||
( * V_9 -> V_363 & 0x007f ) ||
( V_214 < 2 * V_9 -> V_20 ) ) {
F_154 ( 1 ) ;
if ( F_159 ( V_348 ) )
break;
if ( V_361 && F_160 ( V_5 , V_362 + V_361 ) )
break;
V_213 = V_5 ;
V_304 = F_72 () ;
V_214 =
( V_213 - V_9 -> V_187 ) * ( 1000000 / V_215 ) +
V_304 - V_9 -> V_186 ;
}
F_161 ( V_364 ) ;
}
void
F_162 ( struct V_74 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_77 ;
F_124 ( V_12 ) ;
F_107 ( V_9 ) ;
V_9 -> V_106 = 0 ;
V_9 -> V_11 . V_85 = 0 ;
F_156 ( & V_9 -> V_11 , 0 ) ;
V_9 -> V_11 . V_12 = NULL ;
F_155 ( & V_9 -> V_11 . V_354 ) ;
}
static int
F_163 ( struct V_74 * V_12 , struct V_346 * V_347 ,
struct V_8 * V_9 )
{
F_164 ( V_365 , V_348 ) ;
unsigned long V_36 ;
int V_29 ;
int V_366 = 0 ;
if ( ( V_347 -> V_367 & V_368 ) || F_148 ( V_12 ) ) {
F_156 ( & V_9 -> V_11 , 1 ) ;
return 0 ;
}
if ( F_165 ( V_12 ) )
V_366 = 1 ;
V_29 = 0 ;
F_166 ( & V_9 -> V_11 . V_354 , & V_365 ) ;
#ifdef F_103
F_5 ( L_100 ,
V_9 -> line , V_9 -> V_11 . V_85 ) ;
#endif
F_9 ( V_36 ) ;
V_9 -> V_11 . V_85 -- ;
F_10 ( V_36 ) ;
V_9 -> V_11 . V_353 ++ ;
while ( 1 ) {
F_9 ( V_36 ) ;
F_11 ( V_9 , 1 ) ;
F_6 ( V_9 , 1 ) ;
F_10 ( V_36 ) ;
F_161 ( V_369 ) ;
if ( F_151 ( V_347 ) || ! F_101 ( & V_9 -> V_11 ) ) {
#ifdef F_167
if ( V_9 -> V_11 . V_36 & V_370 )
V_29 = - V_371 ;
else
V_29 = - V_372 ;
#else
V_29 = - V_371 ;
#endif
break;
}
if ( V_366 )
break;
if ( F_159 ( V_348 ) ) {
V_29 = - V_372 ;
break;
}
#ifdef F_103
F_5 ( L_101 ,
V_9 -> line , V_9 -> V_11 . V_85 ) ;
#endif
F_168 ( V_12 ) ;
F_169 () ;
F_170 ( V_12 ) ;
}
F_161 ( V_364 ) ;
F_171 ( & V_9 -> V_11 . V_354 , & V_365 ) ;
if ( ! F_151 ( V_347 ) )
V_9 -> V_11 . V_85 ++ ;
V_9 -> V_11 . V_353 -- ;
#ifdef F_103
F_5 ( L_102 ,
V_9 -> line , V_9 -> V_11 . V_85 ) ;
#endif
if ( V_29 )
return V_29 ;
F_156 ( & V_9 -> V_11 , 1 ) ;
return 0 ;
}
static void
F_172 ( struct V_8 * V_9 )
{
if ( V_9 -> V_237 ) {
F_158 ( V_9 -> V_359 , V_9 -> V_360 ) ;
F_157 ( V_9 -> V_358 , V_9 ) ;
}
if ( V_9 -> V_236 ) {
F_158 ( V_9 -> V_356 , V_9 -> V_357 ) ;
F_157 ( V_9 -> V_355 , V_9 ) ;
}
}
static int
F_173 ( struct V_74 * V_12 , struct V_346 * V_347 )
{
struct V_8 * V_9 ;
int V_29 ;
int V_373 = 0 ;
V_9 = V_184 + V_12 -> V_374 ;
if ( ! V_9 -> V_185 )
return - V_375 ;
#ifdef F_103
F_5 ( L_103 , V_348 -> V_349 , V_12 -> V_376 ,
V_9 -> V_11 . V_85 ) ;
#endif
V_9 -> V_11 . V_85 ++ ;
V_12 -> V_77 = V_9 ;
V_9 -> V_11 . V_12 = V_12 ;
V_9 -> V_11 . V_301 = ! ! ( V_9 -> V_11 . V_36 & V_302 ) ;
if ( V_9 -> V_11 . V_85 == 1 ) {
V_373 = 1 ;
if ( V_9 -> V_236 ) {
if ( F_174 ( V_9 -> V_355 ,
F_74 ,
V_9 -> V_377 ,
V_9 -> V_357 ,
V_9 ) ) {
F_5 ( V_30 L_104
L_105 ,
V_9 -> V_357 ) ;
V_9 -> V_236 = 0 ;
} else if ( F_175 ( V_9 -> V_356 ,
V_9 -> V_357 ,
V_378 ,
V_9 -> V_379 ) ) {
F_157 ( V_9 -> V_355 , V_9 ) ;
F_5 ( V_30 L_106
L_105 ,
V_9 -> V_357 ) ;
V_9 -> V_236 = 0 ;
}
#ifdef F_103
else
F_5 ( V_321 L_107 ,
V_9 -> V_357 ) ;
#endif
}
if ( V_9 -> V_237 ) {
if ( F_174 ( V_9 -> V_358 ,
F_71 ,
V_9 -> V_380 ,
V_9 -> V_360 ,
V_9 ) ) {
F_5 ( V_30 L_104
L_105 ,
V_9 -> V_360 ) ;
V_9 -> V_237 = 0 ;
} else if ( F_175 ( V_9 -> V_359 ,
V_9 -> V_360 ,
V_378 ,
V_9 -> V_379 ) ) {
F_157 ( V_9 -> V_358 , V_9 ) ;
F_5 ( V_30 L_106
L_105 ,
V_9 -> V_360 ) ;
V_9 -> V_237 = 0 ;
}
#ifdef F_103
else
F_5 ( V_321 L_107 ,
V_9 -> V_360 ) ;
#endif
}
}
V_29 = F_99 ( V_9 ) ;
if ( V_29 ) {
if ( V_373 )
F_172 ( V_9 ) ;
return V_29 ;
}
V_29 = F_163 ( V_12 , V_347 , V_9 ) ;
if ( V_29 ) {
#ifdef F_103
F_5 ( L_108 ,
V_29 ) ;
#endif
if ( V_373 )
F_172 ( V_9 ) ;
return V_29 ;
}
#ifdef F_103
F_5 ( L_109 , V_9 -> line ) ;
#endif
F_88 ( V_381 = 0 ) ;
F_176 ( if (info->line == SERIAL_DEBUG_LINE) {
info->icount.rx = 0;
} ) ;
return 0 ;
}
static void F_177 ( struct V_382 * V_383 , struct V_8 * V_9 )
{
unsigned long V_288 ;
F_178 ( V_383 , L_110 ,
V_9 -> line , ( unsigned long ) V_9 -> V_40 , V_9 -> V_51 ) ;
if ( ! V_9 -> V_40 || ( V_9 -> type == V_384 ) ) {
F_178 ( V_383 , L_111 ) ;
return;
}
F_178 ( V_383 , L_112 , V_9 -> V_21 ) ;
F_178 ( V_383 , L_113 ,
( unsigned long ) V_9 -> V_120 . V_121 ,
( unsigned long ) V_9 -> V_120 . V_147 ) ;
V_288 = F_43 ( V_9 -> V_94 . V_95 , V_9 -> V_94 . V_96 , V_97 ) ;
if ( V_288 )
F_178 ( V_383 , L_114 ,
( unsigned long ) V_288 ,
( unsigned long ) V_97 ) ;
F_178 ( V_383 , L_115 ,
( unsigned long ) V_9 -> V_144 ,
( unsigned long ) V_9 -> V_145 ) ;
#if 1
if ( V_9 -> V_11 . V_12 ) {
if ( V_9 -> V_11 . V_12 -> V_218 )
F_178 ( V_383 , L_116 ,
( int ) V_9 -> V_11 . V_12 -> V_218 ) ;
}
{
unsigned char V_160 = V_9 -> V_40 [ V_163 ] ;
if ( V_160 & F_15 ( V_164 , V_165 ) )
F_178 ( V_383 , L_117 ) ;
}
#endif
if ( V_9 -> V_120 . V_208 )
F_178 ( V_383 , L_118 , ( unsigned long ) V_9 -> V_120 . V_208 ) ;
if ( V_9 -> V_120 . V_207 )
F_178 ( V_383 , L_119 , ( unsigned long ) V_9 -> V_120 . V_207 ) ;
if ( V_9 -> V_120 . V_211 )
F_178 ( V_383 , L_120 , ( unsigned long ) V_9 -> V_120 . V_211 ) ;
if ( V_9 -> V_120 . V_202 )
F_178 ( V_383 , L_121 , ( unsigned long ) V_9 -> V_120 . V_202 ) ;
if ( ! F_142 ( V_9 ) )
F_179 ( V_383 , L_122 ) ;
if ( ! F_146 ( V_9 ) )
F_179 ( V_383 , L_123 ) ;
if ( ! F_8 ( V_9 ) )
F_179 ( V_383 , L_124 ) ;
if ( ! F_144 ( V_9 ) )
F_179 ( V_383 , L_125 ) ;
if ( ! F_145 ( V_9 ) )
F_179 ( V_383 , L_126 ) ;
if ( ! F_143 ( V_9 ) )
F_179 ( V_383 , L_127 ) ;
F_179 ( V_383 , L_111 ) ;
}
static int F_180 ( struct V_382 * V_383 , void * V_385 )
{
int V_176 ;
F_178 ( V_383 , L_128 , V_386 ) ;
for ( V_176 = 0 ; V_176 < V_183 ; V_176 ++ ) {
if ( ! V_184 [ V_176 ] . V_185 )
continue;
F_177 ( V_383 , & V_184 [ V_176 ] ) ;
}
#ifdef F_181
for ( V_176 = 0 ; V_176 < V_2 ; V_176 ++ ) {
F_178 ( V_383 , L_129 ,
V_176 , V_4 [ V_176 ] . time ,
F_182 ( V_4 [ V_176 ] . V_6 ) ) ;
F_178 ( V_383 , V_4 [ V_176 ] . string , V_4 [ V_176 ] . V_1 ) ;
}
F_178 ( V_383 , L_130 , V_176 , V_3 ) ;
V_2 = 0 ;
#endif
return 0 ;
}
static int F_183 ( struct V_387 * V_387 , struct V_346 * V_346 )
{
return F_184 ( V_346 , F_180 , NULL ) ;
}
static void F_185 ( void )
{
F_5 ( V_388
L_131
L_132 ,
& V_386 [ 11 ] ) ;
}
static int T_5 F_186 ( void )
{
int V_176 ;
struct V_8 * V_9 ;
struct V_389 * V_390 = F_187 ( V_183 ) ;
if ( ! V_390 )
return - V_235 ;
F_185 () ;
#if ! F_38 ( V_391 )
F_188 ( & V_193 , F_85 , 0 ) ;
F_86 ( & V_193 , V_5 + 5 ) ;
#endif
#if F_38 ( V_124 )
#if F_38 ( V_78 )
if ( F_189 ( V_392 , 'a' , V_81 ,
V_81 ) ) {
F_5 ( V_350 L_133
L_134 ) ;
F_190 ( V_390 ) ;
return - V_299 ;
}
#endif
#endif
V_390 -> V_393 = L_135 ;
V_390 -> V_376 = L_136 ;
V_390 -> V_394 = V_395 ;
V_390 -> V_396 = 64 ;
V_390 -> type = V_397 ;
V_390 -> V_398 = V_399 ;
V_390 -> V_400 = V_401 ;
V_390 -> V_400 . V_14 =
V_402 | V_403 | V_404 | V_241 | V_405 ;
V_390 -> V_400 . V_406 = 115200 ;
V_390 -> V_400 . V_407 = 115200 ;
V_390 -> V_36 = V_408 ;
F_191 ( V_390 , & V_409 ) ;
V_410 = V_390 ;
for ( V_176 = 0 , V_9 = V_184 ; V_176 < V_183 ; V_176 ++ , V_9 ++ ) {
if ( V_9 -> V_185 ) {
if ( F_192 ( V_9 -> V_411 ,
V_9 -> V_412 ) ) {
F_5 ( V_350 L_137
L_138
L_139 ,
V_9 -> V_412 , V_176 ) ;
V_9 -> V_185 = 0 ;
}
}
F_193 ( & V_9 -> V_11 ) ;
V_9 -> V_73 = 0 ;
V_9 -> V_105 = 0 ;
V_9 -> line = V_176 ;
V_9 -> V_11 . V_12 = NULL ;
V_9 -> type = V_413 ;
V_9 -> V_114 = 0 ;
V_9 -> V_189 = 0 ;
V_9 -> V_249 = V_414 ;
V_9 -> V_250 = 0 ;
V_9 -> V_216 = 0 ;
V_9 -> V_106 = 0 ;
V_9 -> V_94 . V_84 = NULL ;
V_9 -> V_94 . V_96 = V_9 -> V_94 . V_95 = 0 ;
V_9 -> V_142 = V_9 -> V_143 = NULL ;
V_9 -> V_144 = V_9 -> V_145 = 0 ;
V_9 -> V_186 = 0 ;
V_9 -> V_187 = 0 ;
#if F_38 ( V_124 )
V_9 -> V_82 . V_36 &= ~ ( V_280 ) ;
V_9 -> V_82 . V_36 |= V_91 ;
V_9 -> V_82 . V_83 = 0 ;
V_9 -> V_82 . V_36 &= ~ ( V_87 ) ;
#endif
F_194 ( & V_9 -> V_107 , F_95 ) ;
if ( V_9 -> V_185 ) {
F_5 ( V_388 L_140 ,
V_410 -> V_376 , V_9 -> line , V_9 -> V_40 ) ;
}
F_195 ( & V_9 -> V_11 , V_390 , V_176 ) ;
}
if ( F_196 ( V_390 ) )
F_62 ( L_141 ) ;
#ifdef V_125
#ifdef V_391
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
#endif
#ifdef V_124
memset ( V_89 , 0 , sizeof( V_89 ) ) ;
#endif
F_197 () ;
#endif
#ifndef F_198
if ( F_174 ( V_415 , F_92 ,
V_416 , L_142 , V_390 ) )
F_62 ( L_143 , V_149 ) ;
#endif
return 0 ;
}
