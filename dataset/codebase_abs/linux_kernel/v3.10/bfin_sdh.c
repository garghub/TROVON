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
if ( V_14 -> V_10 & V_26 )
V_16 |= V_27 ;
if ( V_14 -> V_22 & ( V_14 -> V_22 - 1 ) )
return - V_28 ;
#ifndef F_15
V_16 |= ( ( F_16 ( V_14 -> V_22 ) - 1 ) << 4 ) ;
#else
F_17 ( V_14 -> V_22 ) ;
#endif
F_18 ( V_16 ) ;
V_18 = 1000000000 / ( V_7 -> V_29 / ( 2 * ( V_7 -> V_30 + 1 ) ) ) ;
V_19 = V_14 -> V_31 / V_18 ;
V_19 += V_14 -> V_32 ;
F_19 ( V_19 ) ;
F_5 () ;
if ( V_14 -> V_10 & V_26 ) {
V_7 -> V_33 = V_34 ;
V_17 |= V_35 ;
} else
V_7 -> V_33 = V_36 ;
F_6 ( V_7 , ( V_37 | V_38 | V_39 ) ) ;
V_7 -> V_40 = F_20 ( F_13 ( V_7 -> V_20 ) , V_14 -> V_41 , V_14 -> V_42 , V_7 -> V_33 ) ;
#if F_21 ( V_43 ) || F_21 ( V_44 )
V_17 |= V_45 | V_46 | V_47 | V_48 ;
# ifdef F_15
V_17 |= V_49 | V_50 ;
# else
V_17 |= V_51 ;
# endif
{
struct V_52 * V_41 ;
int V_53 ;
F_22 (data->sg, sg, host->dma_len, i) {
V_7 -> V_54 [ V_53 ] . V_55 = F_23 ( V_41 ) ;
V_7 -> V_54 [ V_53 ] . V_56 = V_17 ;
V_7 -> V_54 [ V_53 ] . V_57 = F_24 ( V_41 ) / 4 ;
V_7 -> V_54 [ V_53 ] . V_58 = 4 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_2
L_3 ,
V_53 , V_7 -> V_54 [ V_53 ] . V_55 ,
V_7 -> V_54 [ V_53 ] . V_56 , V_7 -> V_54 [ V_53 ] . V_57 ,
V_7 -> V_54 [ V_53 ] . V_58 ) ;
}
}
F_25 ( ( unsigned int ) V_7 -> V_54 ,
( unsigned int ) V_7 -> V_54 +
V_7 -> V_40 * sizeof( struct V_59 ) ) ;
V_7 -> V_54 [ V_7 -> V_40 - 1 ] . V_56 &= ~ ( V_60 | V_61 ) ;
V_7 -> V_54 [ V_7 -> V_40 - 1 ] . V_56 |= V_62 ;
F_26 ( V_7 -> V_63 , ( unsigned long * ) V_7 -> V_64 ) ;
F_27 ( V_7 -> V_63 , 0 ) ;
F_28 ( V_7 -> V_63 , 0 ) ;
F_5 () ;
F_29 ( V_7 -> V_63 , V_17 ) ;
#elif F_21 ( V_65 )
V_17 |= V_47 | V_48 ;
F_30 ( V_7 -> V_63 , F_23 ( & V_14 -> V_41 [ 0 ] ) ) ;
F_27 ( V_7 -> V_63 , V_15 / 4 ) ;
F_28 ( V_7 -> V_63 , 4 ) ;
F_5 () ;
F_29 ( V_7 -> V_63 , V_17 ) ;
#endif
F_18 ( F_31 () | V_66 | V_67 ) ;
F_5 () ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_4 , V_21 ) ;
return 0 ;
}
static void F_32 ( struct V_6 * V_7 , struct V_68 * V_69 )
{
unsigned int V_70 ;
unsigned int V_71 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_5 , V_21 , V_69 ) ;
F_33 ( V_7 -> V_69 != NULL ) ;
V_7 -> V_69 = V_69 ;
V_70 = 0 ;
V_71 = 0 ;
V_70 |= V_69 -> V_72 ;
if ( V_69 -> V_10 & V_73 ) {
V_70 |= V_74 ;
V_71 |= V_75 ;
} else {
V_71 |= V_76 ;
}
if ( V_69 -> V_10 & V_77 )
V_70 |= V_78 ;
V_71 |= V_79 | V_80 ;
F_6 ( V_7 , V_71 ) ;
F_34 ( V_69 -> V_81 ) ;
F_35 ( V_70 | V_82 ) ;
F_3 ( F_4 () | V_8 ) ;
F_5 () ;
}
static void F_36 ( struct V_6 * V_7 , struct V_83 * V_84 )
{
F_12 ( F_13 ( V_7 -> V_20 ) , L_6 , V_21 ) ;
V_7 -> V_84 = NULL ;
V_7 -> V_69 = NULL ;
V_7 -> V_14 = NULL ;
F_37 ( V_7 -> V_20 , V_84 ) ;
}
static int F_38 ( struct V_6 * V_7 , unsigned int V_85 )
{
struct V_68 * V_69 = V_7 -> V_69 ;
int V_86 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_7 , V_21 , V_69 ) ;
if ( ! V_69 )
return 0 ;
V_7 -> V_69 = NULL ;
if ( V_69 -> V_10 & V_73 ) {
V_69 -> V_87 [ 0 ] = F_39 () ;
if ( V_69 -> V_10 & V_77 ) {
V_69 -> V_87 [ 1 ] = F_40 () ;
V_69 -> V_87 [ 2 ] = F_41 () ;
V_69 -> V_87 [ 3 ] = F_42 () ;
}
}
if ( V_85 & V_80 )
V_69 -> error = - V_88 ;
else if ( V_85 & V_79 && V_69 -> V_10 & V_89 )
V_69 -> error = - V_90 ;
F_10 ( V_7 , ( V_76 | V_75 | V_80 | V_79 ) ) ;
if ( V_7 -> V_14 && ! V_69 -> error ) {
if ( V_7 -> V_14 -> V_10 & V_91 ) {
V_86 = F_11 ( V_7 , V_7 -> V_14 ) ;
if ( V_86 )
return 0 ;
}
F_6 ( V_7 , V_39 | V_92 | V_93 | V_38 ) ;
} else
F_36 ( V_7 , V_7 -> V_84 ) ;
return 1 ;
}
static int F_43 ( struct V_6 * V_7 , unsigned int V_85 )
{
struct V_13 * V_14 = V_7 -> V_14 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_8 , V_21 , V_85 ) ;
if ( ! V_14 )
return 0 ;
F_44 ( V_7 -> V_63 ) ;
F_45 ( F_13 ( V_7 -> V_20 ) , V_14 -> V_41 , V_14 -> V_42 ,
V_7 -> V_33 ) ;
if ( V_85 & V_38 )
V_14 -> error = - V_88 ;
else if ( V_85 & V_37 )
V_14 -> error = - V_90 ;
else if ( V_85 & ( V_92 | V_93 ) )
V_14 -> error = - V_94 ;
if ( ! V_14 -> error )
V_14 -> V_95 = V_14 -> V_23 * V_14 -> V_22 ;
else
V_14 -> V_95 = 0 ;
F_46 ( V_96 | V_97 | \
V_98 | V_99 | V_92 | V_93 ) ;
F_18 ( 0 ) ;
F_5 () ;
V_7 -> V_14 = NULL ;
if ( V_7 -> V_84 -> V_100 ) {
F_2 ( V_7 ) ;
F_32 ( V_7 , V_7 -> V_84 -> V_100 ) ;
} else {
F_36 ( V_7 , V_7 -> V_84 ) ;
}
return 1 ;
}
static void F_47 ( struct V_101 * V_20 , struct V_83 * V_84 )
{
struct V_6 * V_7 = F_48 ( V_20 ) ;
int V_86 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_9 , V_21 , V_84 , V_84 -> V_69 ) ;
F_33 ( V_7 -> V_84 != NULL ) ;
F_49 ( & V_7 -> V_11 ) ;
V_7 -> V_84 = V_84 ;
V_7 -> V_14 = V_84 -> V_14 ;
if ( V_84 -> V_14 && V_84 -> V_14 -> V_10 & V_26 ) {
V_86 = F_11 ( V_7 , V_84 -> V_14 ) ;
if ( V_86 )
goto V_102;
}
F_32 ( V_7 , V_84 -> V_69 ) ;
V_102:
F_50 ( & V_7 -> V_11 ) ;
}
static void F_51 ( struct V_101 * V_20 , struct V_103 * V_104 )
{
struct V_6 * V_7 ;
T_1 V_105 = 0 ;
#ifndef F_15
T_1 V_106 = 0 ;
#endif
T_1 V_56 ;
V_7 = F_48 ( V_20 ) ;
F_49 ( & V_7 -> V_11 ) ;
V_56 = F_52 () ;
V_56 |= V_107 ;
switch ( V_104 -> V_108 ) {
case V_109 :
#ifndef F_15
V_56 &= ~ V_110 ;
#endif
V_56 |= V_111 ;
V_56 |= V_112 ;
V_105 |= V_113 ;
break;
case V_114 :
#ifndef F_15
V_56 &= ~ V_110 ;
#endif
V_56 |= V_111 ;
V_56 &= ~ V_112 ;
V_105 |= V_115 ;
break;
default:
V_56 &= ~ V_111 ;
V_56 &= ~ V_112 ;
}
V_7 -> V_116 = V_104 -> V_116 ;
#ifndef F_15
if ( V_104 -> V_117 == V_118 ) {
V_106 |= V_119 ;
# ifndef F_53
V_106 |= V_120 ;
# endif
}
if ( V_104 -> V_116 != V_121 )
V_106 |= V_122 ;
else
V_106 &= ~ V_122 ;
F_54 ( V_106 ) ;
#else
# ifndef F_53
if ( V_104 -> V_117 == V_118 )
V_56 |= V_120 ;
else
V_56 &= ~ V_120 ;
# endif
if ( V_104 -> V_116 != V_121 )
V_56 |= V_122 ;
else
V_56 &= ~ V_122 ;
F_55 ( V_56 ) ;
#endif
F_5 () ;
if ( V_104 -> V_116 == V_123 && V_104 -> clock ) {
unsigned char V_30 ;
V_30 = ( F_56 () / V_104 -> clock - 1 ) / 2 ;
V_30 = F_57 (unsigned char, clk_div, 0xFF ) ;
V_105 |= V_30 ;
V_105 |= V_8 ;
V_7 -> V_30 = V_30 ;
F_3 ( V_105 ) ;
} else
F_2 ( V_7 ) ;
if ( V_104 -> V_116 == V_123 )
F_8 ( V_39 | V_38 | V_37 |
V_92 | V_93 | V_76 | V_75 |
V_80 | V_79 ) ;
else
F_8 ( 0 ) ;
F_5 () ;
F_50 ( & V_7 -> V_11 ) ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_10 ,
V_7 -> V_30 ,
V_7 -> V_30 ? F_56 () / ( 2 * ( V_7 -> V_30 + 1 ) ) : 0 ,
V_104 -> clock ) ;
}
static T_2 F_58 ( int V_124 , void * V_125 )
{
struct V_6 * V_7 = V_125 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_11 , V_21 ,
F_59 ( V_7 -> V_63 ) ) ;
F_60 ( V_7 -> V_63 ) ;
F_5 () ;
return V_126 ;
}
static T_2 F_61 ( int V_124 , void * V_125 )
{
struct V_6 * V_7 = V_125 ;
unsigned int V_127 ;
int V_128 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_6 , V_21 ) ;
F_49 ( & V_7 -> V_11 ) ;
V_127 = F_62 () ;
if ( V_127 & V_129 ) {
F_63 ( V_7 -> V_20 , 0 ) ;
F_64 ( V_129 ) ;
}
V_127 = F_65 () ;
if ( V_127 & ( V_76 | V_75 | V_80 | V_79 ) ) {
V_128 |= F_38 ( V_7 , V_127 ) ;
F_46 ( V_130 | V_131 | \
V_132 | V_133 ) ;
F_5 () ;
}
V_127 = F_65 () ;
if ( V_127 & ( V_39 | V_38 | V_37 | V_92 | V_93 ) )
V_128 |= F_43 ( V_7 , V_127 ) ;
F_50 ( & V_7 -> V_11 ) ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_12 , V_21 ) ;
return F_66 ( V_128 ) ;
}
static void F_67 ( void )
{
#if F_21 ( V_43 )
F_68 ( F_69 () | 0x1 ) ;
#endif
F_55 ( F_52 () | V_134 ) ;
F_5 () ;
F_55 ( ( F_52 () & 0x1F ) | ( V_135 | V_111 ) ) ;
F_5 () ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_101 * V_20 ;
struct V_6 * V_7 ;
struct V_1 * V_136 = F_1 ( V_3 ) ;
int V_86 ;
if ( ! V_136 ) {
F_71 ( & V_3 -> V_4 , L_13 ) ;
V_86 = - V_28 ;
goto V_137;
}
V_20 = F_72 ( sizeof( struct V_6 ) , & V_3 -> V_4 ) ;
if ( ! V_20 ) {
V_86 = - V_138 ;
goto V_137;
}
V_20 -> V_139 = & V_140 ;
#if F_21 ( V_65 )
V_20 -> V_141 = 1 ;
#else
V_20 -> V_141 = V_142 / sizeof( struct V_59 ) ;
#endif
#ifdef F_15
V_20 -> V_143 = - 1 ;
#else
V_20 -> V_143 = 1 << 16 ;
#endif
V_20 -> V_144 = 1 << 11 ;
V_20 -> V_145 = 1 << 11 ;
V_20 -> V_146 = V_142 ;
V_20 -> V_147 = V_148 | V_149 ;
V_20 -> V_150 = F_56 () ;
V_20 -> V_151 = V_20 -> V_150 >> 9 ;
V_20 -> V_152 = V_153 | V_154 ;
V_7 = F_48 ( V_20 ) ;
V_7 -> V_20 = V_20 ;
V_7 -> V_29 = F_56 () ;
F_73 ( & V_7 -> V_11 ) ;
V_7 -> V_124 = V_136 -> V_155 ;
V_7 -> V_63 = V_136 -> V_156 ;
V_86 = F_74 ( V_7 -> V_63 , V_157 L_14 ) ;
if ( V_86 ) {
F_71 ( & V_3 -> V_4 , L_15 ) ;
goto V_158;
}
V_86 = F_75 ( V_7 -> V_63 , F_58 , V_7 ) ;
if ( V_86 ) {
F_71 ( & V_3 -> V_4 , L_16 ) ;
goto V_159;
}
V_7 -> V_54 = F_76 ( & V_3 -> V_4 , V_142 , & V_7 -> V_64 , V_160 ) ;
if ( V_7 -> V_54 == NULL ) {
V_86 = - V_138 ;
goto V_159;
}
F_77 ( V_3 , V_20 ) ;
V_86 = F_78 ( V_7 -> V_124 , F_61 , 0 , L_17 , V_7 ) ;
if ( V_86 ) {
F_71 ( & V_3 -> V_4 , L_18 ) ;
goto V_161;
}
V_86 = F_79 ( V_136 -> V_162 , V_157 ) ;
if ( V_86 ) {
F_71 ( & V_3 -> V_4 , L_19 ) ;
goto V_163;
}
F_67 () ;
F_80 ( V_20 ) ;
return 0 ;
V_163:
F_81 ( V_7 -> V_124 , V_7 ) ;
V_161:
F_82 ( V_20 ) ;
F_83 ( & V_3 -> V_4 , V_142 , V_7 -> V_54 , V_7 -> V_64 ) ;
V_159:
F_84 ( V_7 -> V_63 ) ;
V_158:
F_85 ( V_20 ) ;
V_137:
return V_86 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_101 * V_20 = F_87 ( V_3 ) ;
F_77 ( V_3 , NULL ) ;
if ( V_20 ) {
struct V_6 * V_7 = F_48 ( V_20 ) ;
F_82 ( V_20 ) ;
F_2 ( V_7 ) ;
F_81 ( V_7 -> V_124 , V_7 ) ;
F_84 ( V_7 -> V_63 ) ;
F_83 ( & V_3 -> V_4 , V_142 , V_7 -> V_54 , V_7 -> V_64 ) ;
F_85 ( V_20 ) ;
}
return 0 ;
}
static int F_88 ( struct V_2 * V_4 , T_3 V_164 )
{
struct V_101 * V_20 = F_87 ( V_4 ) ;
struct V_1 * V_136 = F_1 ( V_4 ) ;
int V_86 = 0 ;
if ( V_20 )
V_86 = F_89 ( V_20 ) ;
F_90 ( V_136 -> V_162 ) ;
return V_86 ;
}
static int F_91 ( struct V_2 * V_4 )
{
struct V_101 * V_20 = F_87 ( V_4 ) ;
struct V_1 * V_136 = F_1 ( V_4 ) ;
int V_86 = 0 ;
V_86 = F_79 ( V_136 -> V_162 , V_157 ) ;
if ( V_86 ) {
F_71 ( & V_4 -> V_4 , L_19 ) ;
return V_86 ;
}
F_67 () ;
if ( V_20 )
V_86 = F_92 ( V_20 ) ;
return V_86 ;
}
