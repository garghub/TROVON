static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_2 , & V_4 -> V_7 ) ;
else
F_3 ( V_2 -> V_2 , L_1 ) ;
if ( V_4 -> V_8 )
F_4 ( V_2 , & V_4 -> V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_12 = V_10 -> V_13 . V_14 ;
T_1 V_15 ;
T_1 V_16 ;
if ( V_12 < 1 )
V_12 = 1 ;
if ( F_7 ( V_2 , 0 ) ) {
V_16 = F_8 ( V_17 ) >> 16 ;
V_15 = V_12 * V_16 / 100 ;
V_15 = V_15 * V_4 -> V_18 ;
V_15 = V_15 / 100 ;
V_15 = V_15 * V_4 -> V_19 ;
V_15 = V_15 / 100 ;
F_9 ( V_20 , ( 0x80000000 | F_8 ( V_20 ) ) ) ;
F_9 ( V_17 , ( V_16 << 16 ) | V_15 ) ;
F_10 ( V_2 ) ;
}
V_21 = V_12 ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 )
{
return V_21 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_22 ;
T_2 V_23 ;
T_3 V_24 ;
T_3 V_25 ;
V_4 -> V_18 = V_26 ;
V_4 -> V_19 = V_26 ;
V_23 = 256 ;
V_25 = V_27 ;
V_22 = V_4 -> V_28 ;
V_24 = ( V_22 * V_29 ) / V_30 ;
V_24 *= V_25 ;
V_24 /= V_23 ;
V_24 /= V_25 ;
if ( V_24 > ( unsigned long long ) V_31 )
return - V_32 ;
if ( F_7 ( V_2 , false ) ) {
F_9 ( V_20 , ( 0x80000000 | F_8 ( V_20 ) ) ) ;
F_9 ( V_17 , V_24 | ( V_24 << 16 ) ) ;
F_10 ( V_2 ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_33 ;
struct V_34 V_13 ;
memset ( & V_13 , 0 , sizeof( struct V_34 ) ) ;
V_13 . V_35 = 100 ;
V_13 . type = V_36 ;
V_11 = F_14 ( L_2 ,
NULL , ( void * ) V_2 , & V_37 , & V_13 ) ;
if ( F_15 ( V_11 ) )
return F_16 ( V_11 ) ;
V_33 = F_12 ( V_2 ) ;
if ( V_33 < 0 ) {
F_17 ( V_11 ) ;
return V_33 ;
}
V_11 -> V_13 . V_14 = 100 ;
V_11 -> V_13 . V_35 = 100 ;
F_18 ( V_11 ) ;
V_4 -> V_9 = V_11 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_38 ;
T_1 V_39 ;
V_4 -> V_40 = F_21 ( V_41 ) ;
V_4 -> V_42 = F_21 ( V_43 ) ;
V_4 -> V_44 = F_21 ( V_45 ) ;
V_4 -> V_46 = F_21 ( V_47 ) ;
V_4 -> V_48 = F_21 ( V_49 ) ;
V_4 -> V_50 = F_21 ( V_51 ) ;
V_4 -> V_52 = F_21 ( V_53 ) ;
V_4 -> V_54 = F_21 ( V_55 ) ;
V_4 -> V_56 = F_21 ( V_57 ) ;
V_4 -> V_58 = F_21 ( V_59 ) ;
V_4 -> V_60 = F_21 ( V_61 ) ;
V_4 -> V_62 = F_21 ( V_63 ) ;
V_4 -> V_64 = F_21 ( V_65 ) ;
V_4 -> V_66 = F_21 ( V_67 ) ;
V_4 -> V_68 = F_21 ( V_69 ) ;
V_4 -> V_70 = F_21 ( V_71 ) ;
V_4 -> V_72 = F_21 ( V_73 ) ;
V_4 -> V_74 = F_21 ( V_75 ) ;
V_4 -> V_76 = F_21 ( V_77 ) ;
V_4 -> V_78 = F_21 ( V_79 ) ;
V_4 -> V_80 = F_21 ( V_81 ) ;
V_4 -> V_82 = F_21 ( V_83 ) ;
V_4 -> V_84 = F_21 ( V_85 ) ;
V_4 -> V_86 = F_21 ( V_87 ) ;
V_4 -> V_88 = F_21 ( V_89 ) ;
V_4 -> V_90 = F_21 ( V_91 ) ;
V_4 -> V_92 = F_21 ( V_93 ) ;
V_4 -> V_94 = F_21 ( V_95 ) ;
V_4 -> V_96 = F_21 ( V_97 ) ;
for ( V_38 = 0 ; V_38 < 256 ; V_38 ++ )
V_4 -> V_98 [ V_38 ] = F_21 ( V_99 + ( V_38 << 2 ) ) ;
if ( V_4 -> V_8 )
F_22 ( V_2 ) ;
V_4 -> V_100 = F_21 ( V_101 ) ;
V_4 -> V_102 = F_21 ( V_103 ) ;
V_4 -> V_104 = F_21 ( V_105 ) ;
V_4 -> V_106 = F_21 ( V_107 ) ;
V_4 -> V_108 = F_21 ( V_17 ) ;
V_4 -> V_109 = F_21 ( V_20 ) ;
V_4 -> V_110 = F_21 ( V_111 ) ;
V_4 -> V_112 = F_21 ( V_113 ) ;
V_4 -> V_114 = F_21 ( V_115 ) ;
V_4 -> V_116 = F_21 ( V_117 ) ;
V_4 -> V_118 = F_21 ( V_119 ) ;
V_4 -> V_120 = F_21 ( V_121 ) ;
V_4 -> V_122 = F_21 ( V_123 ) ;
V_4 -> V_124 = F_21 ( V_125 ) ;
V_4 -> V_126 = F_21 ( V_127 ) ;
V_4 -> V_128 = F_21 ( V_129 ) ;
V_4 -> V_130 = F_21 ( V_131 ) ;
V_4 -> V_132 = F_21 ( V_133 ) ;
V_4 -> V_134 =
F_21 ( V_135 ) ;
V_4 -> V_136 =
F_21 ( V_137 ) ;
V_4 -> V_138 = F_21 ( V_139 ) ;
if ( V_4 -> V_6 ) {
F_23 ( 0 , V_103 ) ;
do {
V_39 = F_21 ( V_140 ) ;
} while ( V_39 & 0x80000000 );
F_23 ( 0x58000000 , V_81 ) ;
F_23 ( 0 , V_87 ) ;
F_24 ( 4 ) ;
F_23 ( 0x0 , V_57 ) ;
F_24 ( 8 ) ;
F_23 ( 0 , V_65 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_39 ;
int V_38 ;
F_23 ( V_4 -> V_40 , V_41 ) ;
F_23 ( V_4 -> V_42 , V_43 ) ;
F_23 ( V_4 -> V_44 , V_45 ) ;
F_23 ( V_4 -> V_46 , V_47 ) ;
F_23 ( V_4 -> V_48 , V_49 ) ;
F_23 ( V_4 -> V_50 , V_51 ) ;
F_23 ( V_4 -> V_52 , V_53 ) ;
F_23 ( V_4 -> V_54 , V_55 ) ;
F_23 ( 0x80000000 , V_141 ) ;
F_23 ( V_4 -> V_60 , V_61 ) ;
F_23 ( V_4 -> V_62 , V_63 ) ;
F_23 ( V_4 -> V_64 , V_65 ) ;
F_26 ( 150 ) ;
F_23 ( V_4 -> V_66 , V_67 ) ;
F_23 ( V_4 -> V_68 , V_69 ) ;
F_23 ( V_4 -> V_70 , V_71 ) ;
F_23 ( V_4 -> V_72 , V_73 ) ;
F_23 ( V_4 -> V_74 , V_75 ) ;
F_23 ( V_4 -> V_76 , V_77 ) ;
F_23 ( V_4 -> V_58 , V_59 ) ;
F_23 ( V_4 -> V_78 , V_79 ) ;
F_23 ( V_4 -> V_100 , V_101 ) ;
if ( V_4 -> V_6 )
F_23 ( V_4 -> V_56 , V_57 ) ;
F_23 ( V_4 -> V_88 , V_89 ) ;
F_23 ( V_4 -> V_82 , V_83 ) ;
F_23 ( V_4 -> V_90 , V_91 ) ;
F_23 ( V_4 -> V_80 , V_81 ) ;
F_23 ( V_4 -> V_86 , V_87 ) ;
F_23 ( V_4 -> V_92 , V_93 ) ;
F_23 ( V_4 -> V_96 , V_97 ) ;
F_23 ( V_4 -> V_94 , V_95 ) ;
for ( V_38 = 0 ; V_38 < 256 ; V_38 ++ )
F_23 ( V_4 -> V_98 [ V_38 ] , V_99 + ( V_38 << 2 ) ) ;
if ( V_4 -> V_8 )
F_27 ( V_2 ) ;
if ( V_4 -> V_6 ) {
F_23 ( V_4 -> V_109 , V_20 ) ;
F_23 ( V_4 -> V_110 , V_111 ) ;
F_23 ( V_4 -> V_112 , V_113 ) ;
F_23 ( V_4 -> V_104 , V_105 ) ;
F_23 ( V_4 -> V_106 , V_107 ) ;
F_23 ( V_4 -> V_108 , V_17 ) ;
F_23 ( V_4 -> V_114 , V_115 ) ;
F_23 ( V_4 -> V_116 , V_117 ) ;
F_23 ( V_4 -> V_118 , V_119 ) ;
F_23 ( V_4 -> V_102 , V_103 ) ;
}
do {
V_39 = F_21 ( V_140 ) ;
} while ( V_39 & 0x08000000 );
do {
V_39 = F_21 ( V_140 ) ;
} while ( V_39 & 0x10000000 );
F_23 ( V_4 -> V_120 , V_121 ) ;
F_23 ( V_4 -> V_122 , V_123 ) ;
F_23 ( V_4 -> V_124 , V_125 ) ;
F_23 ( V_4 -> V_126 , V_127 ) ;
F_23 ( V_4 -> V_128 , V_129 ) ;
F_23 ( V_4 -> V_130 , V_131 ) ;
F_23 ( V_4 -> V_132 , V_133 ) ;
F_23 ( V_4 -> V_134 ,
V_135 ) ;
F_23 ( V_4 -> V_136 ,
V_137 ) ;
F_23 ( V_4 -> V_138 , V_139 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_142 ;
T_1 V_143 ;
V_142 = V_144 ;
F_29 ( V_142 , V_4 -> V_145 + V_146 ) ;
while ( true ) {
V_143 = F_30 ( V_4 -> V_145 + V_147 ) ;
if ( ( V_143 & V_142 ) == V_142 )
break;
else
F_31 ( 10 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_142 = V_144 ;
T_1 V_143 , V_148 ;
V_148 = F_30 ( V_4 -> V_145 + V_146 ) ;
V_148 &= ~ V_142 ;
F_29 ( V_148 , ( V_4 -> V_145 + V_146 ) ) ;
while ( true ) {
V_143 = F_30 ( V_4 -> V_145 + V_147 ) ;
if ( ( V_143 & V_142 ) == 0 )
break;
else
F_31 ( 10 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_149 * V_150 = & V_4 -> V_151 ;
int V_33 ;
V_33 = F_34 ( V_2 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_150 -> V_152 == 0 ) {
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_149 * V_150 = & V_4 -> V_151 ;
F_38 ( V_2 ) ;
if ( V_150 -> V_152 == 0 )
F_39 ( V_2 ) ;
}
