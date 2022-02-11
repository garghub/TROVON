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
V_16 |= ( ( F_15 ( V_14 -> V_22 ) - 1 ) << 4 ) ;
F_16 ( V_16 ) ;
V_18 = 1000000000 / ( F_17 () / ( 2 * ( V_7 -> V_29 + 1 ) ) ) ;
V_19 = V_14 -> V_30 / V_18 ;
V_19 += V_14 -> V_31 ;
F_18 ( V_19 ) ;
F_5 () ;
if ( V_14 -> V_10 & V_26 ) {
V_7 -> V_32 = V_33 ;
V_17 |= V_34 ;
} else
V_7 -> V_32 = V_35 ;
F_6 ( V_7 , ( V_36 | V_37 | V_38 ) ) ;
V_7 -> V_39 = F_19 ( F_13 ( V_7 -> V_20 ) , V_14 -> V_40 , V_14 -> V_41 , V_7 -> V_32 ) ;
#if F_20 ( V_42 )
V_17 |= V_43 | V_44 | V_45 | V_46 | V_47 ;
{
struct V_48 * V_40 ;
int V_49 ;
F_21 (data->sg, sg, host->dma_len, i) {
V_7 -> V_50 [ V_49 ] . V_51 = F_22 ( V_40 ) ;
V_7 -> V_50 [ V_49 ] . V_52 = V_17 ;
V_7 -> V_50 [ V_49 ] . V_53 = F_23 ( V_40 ) / 4 ;
V_7 -> V_50 [ V_49 ] . V_54 = 4 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_2
L_3 ,
V_49 , V_7 -> V_50 [ V_49 ] . V_51 ,
V_7 -> V_50 [ V_49 ] . V_52 , V_7 -> V_50 [ V_49 ] . V_53 ,
V_7 -> V_50 [ V_49 ] . V_54 ) ;
}
}
F_24 ( ( unsigned int ) V_7 -> V_50 ,
( unsigned int ) V_7 -> V_50 +
V_7 -> V_39 * sizeof( struct V_55 ) ) ;
V_7 -> V_50 [ V_7 -> V_39 - 1 ] . V_52 &= ~ ( V_56 | V_57 ) ;
V_7 -> V_50 [ V_7 -> V_39 - 1 ] . V_52 |= V_58 ;
F_25 ( V_7 -> V_59 , ( unsigned long * ) V_7 -> V_60 ) ;
F_26 ( V_7 -> V_59 , 0 ) ;
F_27 ( V_7 -> V_59 , 0 ) ;
F_28 ( V_7 -> V_59 , V_17 ) ;
#elif F_20 ( V_61 )
V_17 |= V_46 | V_47 ;
F_29 ( V_7 -> V_59 , F_22 ( & V_14 -> V_40 [ 0 ] ) ) ;
F_26 ( V_7 -> V_59 , V_15 / 4 ) ;
F_27 ( V_7 -> V_59 , 4 ) ;
F_28 ( V_7 -> V_59 , V_17 ) ;
#endif
F_16 ( F_30 () | V_62 | V_63 ) ;
F_5 () ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_4 , V_21 ) ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 , struct V_64 * V_65 )
{
unsigned int V_66 ;
unsigned int V_67 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_5 , V_21 , V_65 ) ;
F_32 ( V_7 -> V_65 != NULL ) ;
V_7 -> V_65 = V_65 ;
V_66 = 0 ;
V_67 = 0 ;
V_66 |= V_65 -> V_68 ;
if ( V_65 -> V_10 & V_69 ) {
V_66 |= V_70 ;
V_67 |= V_71 ;
} else {
V_67 |= V_72 ;
}
if ( V_65 -> V_10 & V_73 )
V_66 |= V_74 ;
V_67 |= V_75 | V_76 ;
F_6 ( V_7 , V_67 ) ;
F_33 ( V_65 -> V_77 ) ;
F_34 ( V_66 | V_78 ) ;
F_3 ( F_4 () | V_8 ) ;
F_5 () ;
}
static void F_35 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
F_12 ( F_13 ( V_7 -> V_20 ) , L_6 , V_21 ) ;
V_7 -> V_80 = NULL ;
V_7 -> V_65 = NULL ;
V_7 -> V_14 = NULL ;
F_36 ( V_7 -> V_20 , V_80 ) ;
}
static int F_37 ( struct V_6 * V_7 , unsigned int V_81 )
{
struct V_64 * V_65 = V_7 -> V_65 ;
int V_82 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_7 , V_21 , V_65 ) ;
if ( ! V_65 )
return 0 ;
V_7 -> V_65 = NULL ;
if ( V_65 -> V_10 & V_69 ) {
V_65 -> V_83 [ 0 ] = F_38 () ;
if ( V_65 -> V_10 & V_73 ) {
V_65 -> V_83 [ 1 ] = F_39 () ;
V_65 -> V_83 [ 2 ] = F_40 () ;
V_65 -> V_83 [ 3 ] = F_41 () ;
}
}
if ( V_81 & V_76 )
V_65 -> error = - V_84 ;
else if ( V_81 & V_75 && V_65 -> V_10 & V_85 )
V_65 -> error = - V_86 ;
F_10 ( V_7 , ( V_72 | V_71 | V_76 | V_75 ) ) ;
if ( V_7 -> V_14 && ! V_65 -> error ) {
if ( V_7 -> V_14 -> V_10 & V_87 ) {
V_82 = F_11 ( V_7 , V_7 -> V_14 ) ;
if ( V_82 )
return 0 ;
}
F_6 ( V_7 , V_38 | V_88 | V_89 | V_37 ) ;
} else
F_35 ( V_7 , V_7 -> V_80 ) ;
return 1 ;
}
static int F_42 ( struct V_6 * V_7 , unsigned int V_81 )
{
struct V_13 * V_14 = V_7 -> V_14 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_8 , V_21 , V_81 ) ;
if ( ! V_14 )
return 0 ;
F_43 ( V_7 -> V_59 ) ;
F_44 ( F_13 ( V_7 -> V_20 ) , V_14 -> V_40 , V_14 -> V_41 ,
V_7 -> V_32 ) ;
if ( V_81 & V_37 )
V_14 -> error = - V_84 ;
else if ( V_81 & V_36 )
V_14 -> error = - V_86 ;
else if ( V_81 & ( V_88 | V_89 ) )
V_14 -> error = - V_90 ;
if ( ! V_14 -> error )
V_14 -> V_91 = V_14 -> V_23 * V_14 -> V_22 ;
else
V_14 -> V_91 = 0 ;
F_10 ( V_7 , V_38 | V_37 | V_36 | V_88 | V_89 ) ;
F_45 ( V_92 | V_93 | \
V_94 | V_95 | V_88 | V_89 ) ;
F_16 ( 0 ) ;
F_5 () ;
V_7 -> V_14 = NULL ;
if ( V_7 -> V_80 -> V_96 ) {
F_2 ( V_7 ) ;
F_31 ( V_7 , V_7 -> V_80 -> V_96 ) ;
} else {
F_35 ( V_7 , V_7 -> V_80 ) ;
}
return 1 ;
}
static void F_46 ( struct V_97 * V_20 , struct V_79 * V_80 )
{
struct V_6 * V_7 = F_47 ( V_20 ) ;
int V_82 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_9 , V_21 , V_80 , V_80 -> V_65 ) ;
F_32 ( V_7 -> V_80 != NULL ) ;
V_7 -> V_80 = V_80 ;
V_7 -> V_14 = V_80 -> V_14 ;
if ( V_80 -> V_14 && V_80 -> V_14 -> V_10 & V_26 ) {
V_82 = F_11 ( V_7 , V_80 -> V_14 ) ;
if ( V_82 )
return;
}
F_31 ( V_7 , V_80 -> V_65 ) ;
}
static void F_48 ( struct V_97 * V_20 , struct V_98 * V_99 )
{
struct V_6 * V_7 ;
unsigned long V_10 ;
T_1 V_100 = 0 ;
T_1 V_101 = 0 ;
T_1 V_52 ;
V_7 = F_47 ( V_20 ) ;
F_7 ( & V_7 -> V_11 , V_10 ) ;
if ( V_99 -> clock ) {
unsigned long V_102 , V_103 ;
unsigned char V_29 ;
V_103 = 2 * V_99 -> clock ;
V_102 = F_17 () ;
V_29 = V_102 / V_103 ;
if ( V_102 % V_103 == 0 )
V_29 -= 1 ;
V_29 = F_49 (unsigned char, clk_div, 0xFF ) ;
V_100 |= V_29 ;
V_100 |= V_8 ;
V_7 -> V_29 = V_29 ;
} else
F_2 ( V_7 ) ;
if ( V_99 -> V_104 == V_105 )
#ifdef F_50
V_101 |= V_106 ;
#else
V_101 |= V_107 | V_106 ;
#endif
if ( V_99 -> V_108 == V_109 ) {
V_52 = F_51 () ;
V_52 &= ~ V_110 ;
V_52 |= V_111 ;
V_52 |= ( V_112 | V_113 ) ;
F_52 ( V_52 ) ;
V_100 |= V_114 ;
} else {
V_52 = F_51 () ;
V_52 |= V_113 ;
F_52 ( V_52 ) ;
}
F_3 ( V_100 ) ;
V_7 -> V_115 = V_99 -> V_115 ;
if ( V_99 -> V_115 == V_116 )
V_101 |= V_117 ;
F_53 ( V_101 ) ;
F_5 () ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_10 ,
V_7 -> V_29 ,
V_7 -> V_29 ? F_17 () / ( 2 * ( V_7 -> V_29 + 1 ) ) : 0 ,
V_99 -> clock ) ;
}
static T_2 F_54 ( int V_118 , void * V_119 )
{
struct V_6 * V_7 = V_119 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_11 , V_21 ,
F_55 ( V_7 -> V_59 ) ) ;
F_56 ( V_7 -> V_59 ) ;
F_5 () ;
return V_120 ;
}
static T_2 F_57 ( int V_118 , void * V_119 )
{
struct V_6 * V_7 = V_119 ;
unsigned int V_121 ;
int V_122 = 0 ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_6 , V_21 ) ;
V_121 = F_58 () ;
if ( V_121 & V_123 ) {
F_59 ( V_7 -> V_20 , 0 ) ;
F_60 ( V_123 ) ;
}
V_121 = F_61 () ;
if ( V_121 & ( V_72 | V_71 | V_76 | V_75 ) ) {
V_122 |= F_37 ( V_7 , V_121 ) ;
F_45 ( V_124 | V_125 | \
V_126 | V_127 ) ;
F_5 () ;
}
V_121 = F_61 () ;
if ( V_121 & ( V_38 | V_37 | V_36 | V_88 | V_89 ) )
V_122 |= F_42 ( V_7 , V_121 ) ;
F_12 ( F_13 ( V_7 -> V_20 ) , L_12 , V_21 ) ;
return F_62 ( V_122 ) ;
}
static int T_3 F_63 ( struct V_2 * V_3 )
{
struct V_97 * V_20 ;
struct V_6 * V_7 ;
struct V_1 * V_128 = F_1 ( V_3 ) ;
int V_82 ;
if ( ! V_128 ) {
F_64 ( & V_3 -> V_4 , L_13 ) ;
V_82 = - V_28 ;
goto V_129;
}
V_20 = F_65 ( sizeof( struct V_6 ) , & V_3 -> V_4 ) ;
if ( ! V_20 ) {
V_82 = - V_130 ;
goto V_129;
}
V_20 -> V_131 = & V_132 ;
V_20 -> V_133 = 32 ;
V_20 -> V_134 = 1 << 16 ;
V_20 -> V_135 = 1 << 11 ;
V_20 -> V_136 = 1 << 11 ;
V_20 -> V_137 = V_138 ;
V_20 -> V_139 = V_140 | V_141 ;
V_20 -> V_142 = F_17 () ;
V_20 -> V_143 = V_20 -> V_142 >> 9 ;
V_20 -> V_144 = V_145 | V_146 ;
V_7 = F_47 ( V_20 ) ;
V_7 -> V_20 = V_20 ;
F_66 ( & V_7 -> V_11 ) ;
V_7 -> V_118 = V_128 -> V_147 ;
V_7 -> V_59 = V_128 -> V_148 ;
V_82 = F_67 ( V_7 -> V_59 , V_149 L_14 ) ;
if ( V_82 ) {
F_64 ( & V_3 -> V_4 , L_15 ) ;
goto V_150;
}
V_82 = F_68 ( V_7 -> V_59 , F_54 , V_7 ) ;
if ( V_82 ) {
F_64 ( & V_3 -> V_4 , L_16 ) ;
goto V_151;
}
V_7 -> V_50 = F_69 ( & V_3 -> V_4 , V_138 , & V_7 -> V_60 , V_152 ) ;
if ( V_7 -> V_50 == NULL ) {
V_82 = - V_130 ;
goto V_151;
}
F_70 ( V_3 , V_20 ) ;
F_71 ( V_20 ) ;
V_82 = F_72 ( V_7 -> V_118 , F_57 , 0 , L_17 , V_7 ) ;
if ( V_82 ) {
F_64 ( & V_3 -> V_4 , L_18 ) ;
goto V_153;
}
V_82 = F_73 ( V_128 -> V_154 , V_149 ) ;
if ( V_82 ) {
F_64 ( & V_3 -> V_4 , L_19 ) ;
goto V_155;
}
#if F_20 ( V_42 )
F_74 ( F_75 () | 0x1 ) ;
#endif
F_52 ( F_51 () | V_156 ) ;
F_5 () ;
F_52 ( ( F_51 () & 0x1F ) | ( V_157 | V_111 ) ) ;
F_5 () ;
return 0 ;
V_155:
F_76 ( V_7 -> V_118 , V_7 ) ;
V_153:
F_77 ( V_20 ) ;
F_78 ( & V_3 -> V_4 , V_138 , V_7 -> V_50 , V_7 -> V_60 ) ;
V_151:
F_79 ( V_7 -> V_59 ) ;
V_150:
F_80 ( V_20 ) ;
V_129:
return V_82 ;
}
static int T_4 F_81 ( struct V_2 * V_3 )
{
struct V_97 * V_20 = F_82 ( V_3 ) ;
F_70 ( V_3 , NULL ) ;
if ( V_20 ) {
struct V_6 * V_7 = F_47 ( V_20 ) ;
F_77 ( V_20 ) ;
F_2 ( V_7 ) ;
F_76 ( V_7 -> V_118 , V_7 ) ;
F_79 ( V_7 -> V_59 ) ;
F_78 ( & V_3 -> V_4 , V_138 , V_7 -> V_50 , V_7 -> V_60 ) ;
F_80 ( V_20 ) ;
}
return 0 ;
}
static int F_83 ( struct V_2 * V_4 , T_5 V_158 )
{
struct V_97 * V_20 = F_82 ( V_4 ) ;
struct V_1 * V_128 = F_1 ( V_4 ) ;
int V_82 = 0 ;
if ( V_20 )
V_82 = F_84 ( V_20 ) ;
F_53 ( F_85 () & ~ V_117 ) ;
F_86 ( V_128 -> V_154 ) ;
return V_82 ;
}
static int F_87 ( struct V_2 * V_4 )
{
struct V_97 * V_20 = F_82 ( V_4 ) ;
struct V_1 * V_128 = F_1 ( V_4 ) ;
int V_82 = 0 ;
V_82 = F_73 ( V_128 -> V_154 , V_149 ) ;
if ( V_82 ) {
F_64 ( & V_4 -> V_4 , L_19 ) ;
return V_82 ;
}
F_53 ( F_85 () | V_117 ) ;
#if F_20 ( V_42 )
F_74 ( F_75 () | 0x1 ) ;
#endif
F_52 ( F_51 () | V_156 ) ;
F_5 () ;
F_52 ( ( F_51 () & 0x1F ) | ( V_157 | V_111 ) ) ;
F_5 () ;
if ( V_20 )
V_82 = F_88 ( V_20 ) ;
return V_82 ;
}
static int T_6 F_89 ( void )
{
return F_90 ( & V_159 ) ;
}
static void T_7 F_91 ( void )
{
F_92 ( & V_159 ) ;
}
