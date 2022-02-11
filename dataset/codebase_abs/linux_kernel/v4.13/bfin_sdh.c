static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 . V_5 ;
}
static void F_2 ( struct V_6 * V_7 )
{
F_3 ( F_4 () & ~ V_8 ) ;
F_5 () ;
}
static void F_6 ( struct V_6 * V_7 , unsigned int V_9 )
{
unsigned long V_10 ;
F_7 ( & V_7 -> V_11 , V_10 ) ;
V_7 -> V_12 |= V_9 ;
F_8 ( V_9 ) ;
F_5 () ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static void F_10 ( struct V_6 * V_7 , unsigned int V_9 )
{
unsigned long V_10 ;
F_7 ( & V_7 -> V_11 , V_10 ) ;
V_7 -> V_12 &= ~ V_9 ;
F_8 ( V_7 -> V_12 ) ;
F_5 () ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static int F_11 ( struct V_6 * V_7 , struct V_13 * V_14 )
{
unsigned int V_15 ;
unsigned int V_16 ;
unsigned int V_17 ;
unsigned int V_18 , V_19 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_1 , V_21 , V_14 -> V_10 ) ;
V_7 -> V_14 = V_14 ;
V_16 = 0 ;
V_17 = 0 ;
V_15 = V_14 -> V_22 * V_14 -> V_23 ;
F_14 ( V_15 ) ;
if ( V_14 -> V_10 & V_24 )
V_16 |= V_25 ;
if ( V_14 -> V_22 & ( V_14 -> V_22 - 1 ) )
return - V_26 ;
#ifndef F_15
V_16 |= ( ( F_16 ( V_14 -> V_22 ) - 1 ) << 4 ) ;
#else
F_17 ( V_14 -> V_22 ) ;
#endif
F_18 ( V_16 ) ;
V_18 = 1000000000 / ( V_7 -> V_27 / ( 2 * ( V_7 -> V_28 + 1 ) ) ) ;
V_19 = V_14 -> V_29 / V_18 ;
V_19 += V_14 -> V_30 ;
F_19 ( V_19 ) ;
F_5 () ;
if ( V_14 -> V_10 & V_24 ) {
V_7 -> V_31 = V_32 ;
V_17 |= V_33 ;
} else
V_7 -> V_31 = V_34 ;
F_6 ( V_7 , ( V_35 | V_36 | V_37 ) ) ;
V_7 -> V_38 = F_20 ( F_13 ( V_7 -> V_20 ) , V_14 -> V_39 , V_14 -> V_40 , V_7 -> V_31 ) ;
#if F_21 ( V_41 ) || F_21 ( V_42 )
V_17 |= V_43 | V_44 | V_45 | V_46 ;
# ifdef F_15
V_17 |= V_47 | V_48 ;
# else
V_17 |= V_49 ;
# endif
{
struct V_50 * V_39 ;
int V_51 ;
F_22 (data->sg, sg, host->dma_len, i) {
V_7 -> V_52 [ V_51 ] . V_53 = F_23 ( V_39 ) ;
V_7 -> V_52 [ V_51 ] . V_54 = V_17 ;
V_7 -> V_52 [ V_51 ] . V_55 = F_24 ( V_39 ) / 4 ;
V_7 -> V_52 [ V_51 ] . V_56 = 4 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_2
L_3 ,
V_51 , V_7 -> V_52 [ V_51 ] . V_53 ,
V_7 -> V_52 [ V_51 ] . V_54 , V_7 -> V_52 [ V_51 ] . V_55 ,
V_7 -> V_52 [ V_51 ] . V_56 ) ;
}
}
F_25 ( ( unsigned int ) V_7 -> V_52 ,
( unsigned int ) V_7 -> V_52 +
V_7 -> V_38 * sizeof( struct V_57 ) ) ;
V_7 -> V_52 [ V_7 -> V_38 - 1 ] . V_54 &= ~ ( V_58 | V_59 ) ;
V_7 -> V_52 [ V_7 -> V_38 - 1 ] . V_54 |= V_60 ;
F_26 ( V_7 -> V_61 , ( unsigned long * ) V_7 -> V_62 ) ;
F_27 ( V_7 -> V_61 , 0 ) ;
F_28 ( V_7 -> V_61 , 0 ) ;
F_5 () ;
F_29 ( V_7 -> V_61 , V_17 ) ;
#elif F_21 ( V_63 )
V_17 |= V_45 | V_46 ;
F_30 ( V_7 -> V_61 , F_23 ( & V_14 -> V_39 [ 0 ] ) ) ;
F_27 ( V_7 -> V_61 , V_15 / 4 ) ;
F_28 ( V_7 -> V_61 , 4 ) ;
F_5 () ;
F_29 ( V_7 -> V_61 , V_17 ) ;
#endif
F_18 ( F_31 () | V_64 | V_65 ) ;
F_5 () ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_4 , V_21 ) ;
return 0 ;
}
static void F_32 ( struct V_6 * V_7 , struct V_66 * V_67 )
{
unsigned int V_68 ;
unsigned int V_69 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_5 , V_21 , V_67 ) ;
F_33 ( V_7 -> V_67 != NULL ) ;
V_7 -> V_67 = V_67 ;
V_68 = 0 ;
V_69 = 0 ;
V_68 |= V_67 -> V_70 ;
if ( V_67 -> V_10 & V_71 ) {
V_68 |= V_72 ;
V_69 |= V_73 ;
} else {
V_69 |= V_74 ;
}
if ( V_67 -> V_10 & V_75 )
V_68 |= V_76 ;
V_69 |= V_77 | V_78 ;
F_6 ( V_7 , V_69 ) ;
F_34 ( V_67 -> V_79 ) ;
F_35 ( V_68 | V_80 ) ;
F_3 ( F_4 () | V_8 ) ;
F_5 () ;
}
static void F_36 ( struct V_6 * V_7 , struct V_81 * V_82 )
{
F_12 ( F_13 ( V_7 -> V_20 ) , L_6 , V_21 ) ;
V_7 -> V_82 = NULL ;
V_7 -> V_67 = NULL ;
V_7 -> V_14 = NULL ;
F_37 ( V_7 -> V_20 , V_82 ) ;
}
static int F_38 ( struct V_6 * V_7 , unsigned int V_83 )
{
struct V_66 * V_67 = V_7 -> V_67 ;
int V_84 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_7 , V_21 , V_67 ) ;
if ( ! V_67 )
return 0 ;
V_7 -> V_67 = NULL ;
if ( V_67 -> V_10 & V_71 ) {
V_67 -> V_85 [ 0 ] = F_39 () ;
if ( V_67 -> V_10 & V_75 ) {
V_67 -> V_85 [ 1 ] = F_40 () ;
V_67 -> V_85 [ 2 ] = F_41 () ;
V_67 -> V_85 [ 3 ] = F_42 () ;
}
}
if ( V_83 & V_78 )
V_67 -> error = - V_86 ;
else if ( V_83 & V_77 && V_67 -> V_10 & V_87 )
V_67 -> error = - V_88 ;
F_10 ( V_7 , ( V_74 | V_73 | V_78 | V_77 ) ) ;
if ( V_7 -> V_14 && ! V_67 -> error ) {
if ( V_7 -> V_14 -> V_10 & V_89 ) {
V_84 = F_11 ( V_7 , V_7 -> V_14 ) ;
if ( V_84 )
return 0 ;
}
F_6 ( V_7 , V_37 | V_90 | V_91 | V_36 ) ;
} else
F_36 ( V_7 , V_7 -> V_82 ) ;
return 1 ;
}
static int F_43 ( struct V_6 * V_7 , unsigned int V_83 )
{
struct V_13 * V_14 = V_7 -> V_14 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_8 , V_21 , V_83 ) ;
if ( ! V_14 )
return 0 ;
F_44 ( V_7 -> V_61 ) ;
F_45 ( F_13 ( V_7 -> V_20 ) , V_14 -> V_39 , V_14 -> V_40 ,
V_7 -> V_31 ) ;
if ( V_83 & V_36 )
V_14 -> error = - V_86 ;
else if ( V_83 & V_35 )
V_14 -> error = - V_88 ;
else if ( V_83 & ( V_90 | V_91 ) )
V_14 -> error = - V_92 ;
if ( ! V_14 -> error )
V_14 -> V_93 = V_14 -> V_23 * V_14 -> V_22 ;
else
V_14 -> V_93 = 0 ;
F_46 ( V_94 | V_95 | \
V_96 | V_97 | V_90 | V_91 ) ;
F_18 ( 0 ) ;
F_5 () ;
V_7 -> V_14 = NULL ;
if ( V_7 -> V_82 -> V_98 ) {
F_2 ( V_7 ) ;
F_32 ( V_7 , V_7 -> V_82 -> V_98 ) ;
} else {
F_36 ( V_7 , V_7 -> V_82 ) ;
}
return 1 ;
}
static void F_47 ( struct V_99 * V_20 , struct V_81 * V_82 )
{
struct V_6 * V_7 = F_48 ( V_20 ) ;
int V_84 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_9 , V_21 , V_82 , V_82 -> V_67 ) ;
F_33 ( V_7 -> V_82 != NULL ) ;
F_49 ( & V_7 -> V_11 ) ;
V_7 -> V_82 = V_82 ;
V_7 -> V_14 = V_82 -> V_14 ;
if ( V_82 -> V_14 && V_82 -> V_14 -> V_10 & V_24 ) {
V_84 = F_11 ( V_7 , V_82 -> V_14 ) ;
if ( V_84 )
goto V_100;
}
F_32 ( V_7 , V_82 -> V_67 ) ;
V_100:
F_50 ( & V_7 -> V_11 ) ;
}
static void F_51 ( struct V_99 * V_20 , struct V_101 * V_102 )
{
struct V_6 * V_7 ;
T_1 V_103 = 0 ;
#ifndef F_15
T_1 V_104 = 0 ;
#endif
T_1 V_54 ;
V_7 = F_48 ( V_20 ) ;
F_49 ( & V_7 -> V_11 ) ;
V_54 = F_52 () ;
V_54 |= V_105 ;
switch ( V_102 -> V_106 ) {
case V_107 :
#ifndef F_15
V_54 &= ~ V_108 ;
#endif
V_54 |= V_109 ;
V_54 |= V_110 ;
V_103 |= V_111 ;
break;
case V_112 :
#ifndef F_15
V_54 &= ~ V_108 ;
#endif
V_54 |= V_109 ;
V_54 &= ~ V_110 ;
V_103 |= V_113 ;
break;
default:
V_54 &= ~ V_109 ;
V_54 &= ~ V_110 ;
}
F_53 ( V_54 ) ;
V_7 -> V_114 = V_102 -> V_114 ;
#ifndef F_15
if ( V_102 -> V_115 == V_116 ) {
V_104 |= V_117 ;
# ifndef F_54
V_104 |= V_118 ;
# endif
}
if ( V_102 -> V_114 != V_119 )
V_104 |= V_120 ;
else
V_104 &= ~ V_120 ;
F_55 ( V_104 ) ;
#else
# ifndef F_54
if ( V_102 -> V_115 == V_116 )
V_54 |= V_118 ;
else
V_54 &= ~ V_118 ;
# endif
if ( V_102 -> V_114 != V_119 )
V_54 |= V_120 ;
else
V_54 &= ~ V_120 ;
F_53 ( V_54 ) ;
#endif
F_5 () ;
if ( V_102 -> V_114 == V_121 && V_102 -> clock ) {
unsigned char V_28 ;
V_28 = ( F_56 () / V_102 -> clock - 1 ) / 2 ;
V_28 = F_57 (unsigned char, clk_div, 0xFF ) ;
V_103 |= V_28 ;
V_103 |= V_8 ;
V_7 -> V_28 = V_28 ;
F_3 ( V_103 ) ;
} else
F_2 ( V_7 ) ;
if ( V_102 -> V_114 == V_121 )
F_8 ( V_37 | V_36 | V_35 |
V_90 | V_91 | V_74 | V_73 |
V_78 | V_77 ) ;
else
F_8 ( 0 ) ;
F_5 () ;
F_50 ( & V_7 -> V_11 ) ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_10 ,
V_7 -> V_28 ,
V_7 -> V_28 ? F_56 () / ( 2 * ( V_7 -> V_28 + 1 ) ) : 0 ,
V_102 -> clock ) ;
}
static T_2 F_58 ( int V_122 , void * V_123 )
{
struct V_6 * V_7 = V_123 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_11 , V_21 ,
F_59 ( V_7 -> V_61 ) ) ;
F_60 ( V_7 -> V_61 ) ;
F_5 () ;
return V_124 ;
}
static T_2 F_61 ( int V_122 , void * V_123 )
{
struct V_6 * V_7 = V_123 ;
unsigned int V_125 ;
int V_126 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_6 , V_21 ) ;
F_49 ( & V_7 -> V_11 ) ;
V_125 = F_62 () ;
if ( V_125 & V_127 ) {
F_63 ( V_7 -> V_20 , 0 ) ;
F_64 ( V_127 ) ;
}
V_125 = F_65 () ;
if ( V_125 & ( V_74 | V_73 | V_78 | V_77 ) ) {
V_126 |= F_38 ( V_7 , V_125 ) ;
F_46 ( V_128 | V_129 | \
V_130 | V_131 ) ;
F_5 () ;
}
V_125 = F_65 () ;
if ( V_125 & ( V_37 | V_36 | V_35 | V_90 | V_91 ) )
V_126 |= F_43 ( V_7 , V_125 ) ;
F_50 ( & V_7 -> V_11 ) ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_12 , V_21 ) ;
return F_66 ( V_126 ) ;
}
static void F_67 ( void )
{
#if F_21 ( V_41 )
F_68 ( F_69 () | 0x1 ) ;
#endif
F_53 ( F_52 () | V_132 ) ;
F_5 () ;
F_53 ( ( F_52 () & 0x1F ) | ( V_133 | V_109 ) ) ;
F_5 () ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_99 * V_20 ;
struct V_6 * V_7 ;
struct V_1 * V_134 = F_1 ( V_3 ) ;
int V_84 ;
if ( ! V_134 ) {
F_71 ( & V_3 -> V_4 , L_13 ) ;
V_84 = - V_26 ;
goto V_135;
}
V_20 = F_72 ( sizeof( struct V_6 ) , & V_3 -> V_4 ) ;
if ( ! V_20 ) {
V_84 = - V_136 ;
goto V_135;
}
V_20 -> V_137 = & V_138 ;
#if F_21 ( V_63 )
V_20 -> V_139 = 1 ;
#else
V_20 -> V_139 = V_140 / sizeof( struct V_57 ) ;
#endif
#ifdef F_15
V_20 -> V_141 = - 1 ;
#else
V_20 -> V_141 = 1 << 16 ;
#endif
V_20 -> V_142 = 1 << 11 ;
V_20 -> V_143 = 1 << 11 ;
V_20 -> V_144 = V_140 ;
V_20 -> V_145 = V_146 | V_147 ;
V_20 -> V_148 = F_56 () ;
V_20 -> V_149 = V_20 -> V_148 >> 9 ;
V_20 -> V_150 = V_151 | V_152 ;
V_7 = F_48 ( V_20 ) ;
V_7 -> V_20 = V_20 ;
V_7 -> V_27 = F_56 () ;
F_73 ( & V_7 -> V_11 ) ;
V_7 -> V_122 = V_134 -> V_153 ;
V_7 -> V_61 = V_134 -> V_154 ;
V_84 = F_74 ( V_7 -> V_61 , V_155 L_14 ) ;
if ( V_84 ) {
F_71 ( & V_3 -> V_4 , L_15 ) ;
goto V_156;
}
V_84 = F_75 ( V_7 -> V_61 , F_58 , V_7 ) ;
if ( V_84 ) {
F_71 ( & V_3 -> V_4 , L_16 ) ;
goto V_157;
}
V_7 -> V_52 = F_76 ( & V_3 -> V_4 , V_140 , & V_7 -> V_62 , V_158 ) ;
if ( V_7 -> V_52 == NULL ) {
V_84 = - V_136 ;
goto V_157;
}
F_77 ( V_3 , V_20 ) ;
V_84 = F_78 ( V_7 -> V_122 , F_61 , 0 , L_17 , V_7 ) ;
if ( V_84 ) {
F_71 ( & V_3 -> V_4 , L_18 ) ;
goto V_159;
}
V_84 = F_79 ( V_134 -> V_160 , V_155 ) ;
if ( V_84 ) {
F_71 ( & V_3 -> V_4 , L_19 ) ;
goto V_161;
}
F_67 () ;
F_80 ( V_20 ) ;
return 0 ;
V_161:
F_81 ( V_7 -> V_122 , V_7 ) ;
V_159:
F_82 ( V_20 ) ;
F_83 ( & V_3 -> V_4 , V_140 , V_7 -> V_52 , V_7 -> V_62 ) ;
V_157:
F_84 ( V_7 -> V_61 ) ;
V_156:
F_85 ( V_20 ) ;
V_135:
return V_84 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_99 * V_20 = F_87 ( V_3 ) ;
if ( V_20 ) {
struct V_6 * V_7 = F_48 ( V_20 ) ;
F_82 ( V_20 ) ;
F_2 ( V_7 ) ;
F_81 ( V_7 -> V_122 , V_7 ) ;
F_84 ( V_7 -> V_61 ) ;
F_83 ( & V_3 -> V_4 , V_140 , V_7 -> V_52 , V_7 -> V_62 ) ;
F_85 ( V_20 ) ;
}
return 0 ;
}
static int F_88 ( struct V_2 * V_4 , T_3 V_162 )
{
struct V_1 * V_134 = F_1 ( V_4 ) ;
F_89 ( V_134 -> V_160 ) ;
return 0 ;
}
static int F_90 ( struct V_2 * V_4 )
{
struct V_1 * V_134 = F_1 ( V_4 ) ;
int V_84 = 0 ;
V_84 = F_79 ( V_134 -> V_160 , V_155 ) ;
if ( V_84 ) {
F_71 ( & V_4 -> V_4 , L_19 ) ;
return V_84 ;
}
F_67 () ;
return V_84 ;
}
