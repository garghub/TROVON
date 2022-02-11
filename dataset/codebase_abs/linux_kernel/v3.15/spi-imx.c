static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_5 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_6 ;
}
static inline unsigned F_3 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 -> V_4 == V_7 ) ? 64 : 8 ;
}
static unsigned int F_4 ( unsigned int V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
int V_11 ;
for ( V_11 = 2 ; V_11 < V_10 ; V_11 ++ )
if ( V_9 * V_12 [ V_11 ] >= V_8 )
return V_11 ;
return V_10 ;
}
static unsigned int F_5 ( unsigned int V_8 ,
unsigned int V_9 )
{
int V_11 , div = 4 ;
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ ) {
if ( V_9 * div >= V_8 )
return V_11 ;
div <<= 1 ;
}
return 7 ;
}
static unsigned int F_6 ( unsigned int V_8 , unsigned int V_9 ,
unsigned int * V_13 )
{
unsigned int V_14 , V_15 ;
if ( F_7 ( V_9 > V_8 ) )
return 0 ;
V_15 = F_8 ( V_8 ) - F_8 ( V_9 ) ;
if ( V_8 > V_9 << V_15 )
V_15 ++ ;
V_15 = V_10 ( 4U , V_15 ) - 4 ;
if ( F_7 ( V_15 > 0xf ) ) {
F_9 ( L_1 ,
V_16 , V_9 , V_8 ) ;
return 0xff ;
}
V_14 = F_10 ( V_8 , V_9 << V_15 ) - 1 ;
F_11 ( L_2 ,
V_16 , V_8 , V_9 , V_15 , V_14 ) ;
* V_13 = ( V_8 / ( V_14 + 1 ) ) >> V_15 ;
return ( V_14 << V_17 ) |
( V_15 << V_18 ) ;
}
static void T_1 F_12 ( struct V_1 * V_19 , int V_20 )
{
unsigned V_21 = 0 ;
if ( V_20 & V_22 )
V_21 |= V_23 ;
if ( V_20 & V_24 )
V_21 |= V_25 ;
F_13 ( V_21 , V_19 -> V_26 + V_27 ) ;
}
static void T_1 F_14 ( struct V_1 * V_19 )
{
T_2 V_28 ;
V_28 = F_15 ( V_19 -> V_26 + V_29 ) ;
V_28 |= V_30 ;
F_13 ( V_28 , V_19 -> V_26 + V_29 ) ;
}
static int T_1 F_16 ( struct V_1 * V_19 ,
struct V_31 * V_32 )
{
T_2 V_33 = V_34 , V_35 = 0 ;
T_2 V_36 = V_32 -> V_37 , V_38 ;
V_33 |= V_39 ;
V_33 |= F_6 ( V_19 -> V_40 , V_32 -> V_37 , & V_36 ) ;
V_33 |= F_17 ( V_32 -> V_41 ) ;
V_33 |= ( V_32 -> V_42 - 1 ) << V_43 ;
V_35 |= F_18 ( V_32 -> V_41 ) ;
if ( V_32 -> V_44 & V_45 )
V_35 |= F_19 ( V_32 -> V_41 ) ;
if ( V_32 -> V_44 & V_46 ) {
V_35 |= F_20 ( V_32 -> V_41 ) ;
V_35 |= F_21 ( V_32 -> V_41 ) ;
}
if ( V_32 -> V_44 & V_47 )
V_35 |= F_22 ( V_32 -> V_41 ) ;
F_13 ( V_33 , V_19 -> V_26 + V_29 ) ;
F_13 ( V_35 , V_19 -> V_26 + V_48 ) ;
V_38 = ( 2 * 1000000 ) / V_36 ;
if ( F_23 ( V_38 < 10 ) )
F_24 ( V_38 ) ;
else
F_25 ( V_38 , V_38 + 10 ) ;
return 0 ;
}
static int T_1 F_26 ( struct V_1 * V_19 )
{
return F_15 ( V_19 -> V_26 + V_49 ) & V_50 ;
}
static void T_1 F_27 ( struct V_1 * V_19 )
{
while ( F_26 ( V_19 ) )
F_15 ( V_19 -> V_26 + V_51 ) ;
}
static void T_1 F_28 ( struct V_1 * V_19 , int V_20 )
{
unsigned int V_21 = 0 ;
if ( V_20 & V_22 )
V_21 |= V_52 ;
if ( V_20 & V_24 )
V_21 |= V_53 ;
F_13 ( V_21 , V_19 -> V_26 + V_54 ) ;
}
static void T_1 F_29 ( struct V_1 * V_19 )
{
unsigned int V_28 ;
V_28 = F_15 ( V_19 -> V_26 + V_55 ) ;
V_28 |= V_56 ;
F_13 ( V_28 , V_19 -> V_26 + V_55 ) ;
}
static int T_1 F_30 ( struct V_1 * V_19 ,
struct V_31 * V_32 )
{
unsigned int V_28 = V_57 | V_58 ;
int V_41 = V_19 -> V_59 [ V_32 -> V_41 ] ;
V_28 |= F_5 ( V_19 -> V_40 , V_32 -> V_37 ) <<
V_60 ;
if ( F_2 ( V_19 ) ) {
V_28 |= ( V_32 -> V_42 - 1 ) << V_61 ;
V_28 |= V_62 ;
} else {
V_28 |= ( V_32 -> V_42 - 1 ) << V_63 ;
}
if ( V_32 -> V_44 & V_45 )
V_28 |= V_64 ;
if ( V_32 -> V_44 & V_46 )
V_28 |= V_65 ;
if ( V_32 -> V_44 & V_47 )
V_28 |= V_66 ;
if ( V_41 < 0 )
V_28 |= ( V_41 + 32 ) <<
( F_2 ( V_19 ) ? V_67 :
V_68 ) ;
F_13 ( V_28 , V_19 -> V_26 + V_55 ) ;
return 0 ;
}
static int T_1 F_31 ( struct V_1 * V_19 )
{
return F_15 ( V_19 -> V_26 + V_69 ) & V_70 ;
}
static void T_1 F_32 ( struct V_1 * V_19 )
{
while ( F_15 ( V_19 -> V_26 + V_69 ) & V_70 )
F_15 ( V_19 -> V_26 + V_51 ) ;
}
static void T_1 F_33 ( struct V_1 * V_19 , int V_20 )
{
unsigned int V_21 = 0 ;
if ( V_20 & V_22 )
V_21 |= V_71 ;
if ( V_20 & V_24 )
V_21 |= V_72 ;
F_13 ( V_21 , V_19 -> V_26 + V_54 ) ;
}
static void T_1 F_34 ( struct V_1 * V_19 )
{
unsigned int V_28 ;
V_28 = F_15 ( V_19 -> V_26 + V_55 ) ;
V_28 |= V_73 ;
F_13 ( V_28 , V_19 -> V_26 + V_55 ) ;
}
static int T_1 F_35 ( struct V_1 * V_19 ,
struct V_31 * V_32 )
{
unsigned int V_28 = V_74 | V_75 ;
int V_41 = V_19 -> V_59 [ V_32 -> V_41 ] ;
unsigned int V_10 = F_1 ( V_19 ) ? 16 : 18 ;
V_28 |= F_4 ( V_19 -> V_40 , V_32 -> V_37 , V_10 ) <<
V_76 ;
V_28 |= V_32 -> V_42 - 1 ;
if ( V_32 -> V_44 & V_45 )
V_28 |= V_77 ;
if ( V_32 -> V_44 & V_46 )
V_28 |= V_78 ;
if ( V_32 -> V_44 & V_47 )
V_28 |= V_79 ;
if ( V_41 < 0 )
V_28 |= ( V_41 + 32 ) << V_80 ;
F_13 ( V_28 , V_19 -> V_26 + V_55 ) ;
return 0 ;
}
static int T_1 F_36 ( struct V_1 * V_19 )
{
return F_15 ( V_19 -> V_26 + V_54 ) & V_81 ;
}
static void T_1 F_37 ( struct V_1 * V_19 )
{
F_13 ( 1 , V_19 -> V_26 + V_82 ) ;
}
static void T_1 F_38 ( struct V_1 * V_19 , int V_20 )
{
unsigned int V_21 = 0 ;
if ( V_20 & V_22 )
V_21 |= V_83 ;
if ( V_20 & V_24 )
V_21 |= V_84 ;
F_13 ( V_21 , V_19 -> V_26 + V_54 ) ;
}
static void T_1 F_39 ( struct V_1 * V_19 )
{
unsigned int V_28 ;
V_28 = F_15 ( V_19 -> V_26 + V_55 ) ;
V_28 |= V_85 ;
F_13 ( V_28 , V_19 -> V_26 + V_55 ) ;
}
static int T_1 F_40 ( struct V_1 * V_19 ,
struct V_31 * V_32 )
{
unsigned int V_28 = V_86 | V_87 ;
V_28 |= F_5 ( V_19 -> V_40 , V_32 -> V_37 ) <<
V_88 ;
V_28 |= V_32 -> V_42 - 1 ;
if ( V_32 -> V_44 & V_45 )
V_28 |= V_89 ;
if ( V_32 -> V_44 & V_46 )
V_28 |= V_90 ;
F_13 ( V_28 , V_19 -> V_26 + V_55 ) ;
return 0 ;
}
static int T_1 F_41 ( struct V_1 * V_19 )
{
return F_15 ( V_19 -> V_26 + V_54 ) & V_91 ;
}
static void T_1 F_42 ( struct V_1 * V_19 )
{
F_13 ( 1 , V_19 -> V_26 + V_82 ) ;
}
static void F_43 ( struct V_92 * V_93 , int V_94 )
{
struct V_1 * V_19 = F_44 ( V_93 -> V_95 ) ;
int V_96 = V_19 -> V_59 [ V_93 -> V_97 ] ;
int V_98 = V_94 != V_99 ;
int V_100 = ! ( V_93 -> V_44 & V_47 ) ;
if ( ! F_45 ( V_96 ) )
return;
F_46 ( V_96 , V_100 ^ V_98 ) ;
}
static void F_47 ( struct V_1 * V_19 )
{
while ( V_19 -> V_101 < F_3 ( V_19 ) ) {
if ( ! V_19 -> V_102 )
break;
V_19 -> V_103 ( V_19 ) ;
V_19 -> V_101 ++ ;
}
V_19 -> V_3 -> V_104 ( V_19 ) ;
}
static T_3 F_48 ( int V_105 , void * V_106 )
{
struct V_1 * V_19 = V_106 ;
while ( V_19 -> V_3 -> V_107 ( V_19 ) ) {
V_19 -> V_108 ( V_19 ) ;
V_19 -> V_101 -- ;
}
if ( V_19 -> V_102 ) {
F_47 ( V_19 ) ;
return V_109 ;
}
if ( V_19 -> V_101 ) {
V_19 -> V_3 -> V_110 (
V_19 , V_24 ) ;
return V_109 ;
}
V_19 -> V_3 -> V_110 ( V_19 , 0 ) ;
F_49 ( & V_19 -> V_111 ) ;
return V_109 ;
}
static int F_50 ( struct V_92 * V_93 ,
struct V_112 * V_113 )
{
struct V_1 * V_19 = F_44 ( V_93 -> V_95 ) ;
struct V_31 V_32 ;
V_32 . V_42 = V_113 ? V_113 -> V_114 : V_93 -> V_114 ;
V_32 . V_37 = V_113 ? V_113 -> V_37 : V_93 -> V_115 ;
V_32 . V_44 = V_93 -> V_44 ;
V_32 . V_41 = V_93 -> V_97 ;
if ( ! V_32 . V_37 )
V_32 . V_37 = V_93 -> V_115 ;
if ( ! V_32 . V_42 )
V_32 . V_42 = V_93 -> V_114 ;
if ( V_32 . V_42 <= 8 ) {
V_19 -> V_108 = V_116 ;
V_19 -> V_103 = V_117 ;
} else if ( V_32 . V_42 <= 16 ) {
V_19 -> V_108 = V_118 ;
V_19 -> V_103 = V_119 ;
} else {
V_19 -> V_108 = V_120 ;
V_19 -> V_103 = V_121 ;
}
V_19 -> V_3 -> V_32 ( V_19 , & V_32 ) ;
return 0 ;
}
static int F_51 ( struct V_92 * V_93 ,
struct V_112 * V_122 )
{
struct V_1 * V_19 = F_44 ( V_93 -> V_95 ) ;
V_19 -> V_123 = V_122 -> V_123 ;
V_19 -> V_124 = V_122 -> V_124 ;
V_19 -> V_102 = V_122 -> V_125 ;
V_19 -> V_101 = 0 ;
F_52 ( & V_19 -> V_111 ) ;
F_47 ( V_19 ) ;
V_19 -> V_3 -> V_110 ( V_19 , V_22 ) ;
F_53 ( & V_19 -> V_111 ) ;
return V_122 -> V_125 ;
}
static int F_54 ( struct V_92 * V_93 )
{
struct V_1 * V_19 = F_44 ( V_93 -> V_95 ) ;
int V_96 = V_19 -> V_59 [ V_93 -> V_97 ] ;
F_55 ( & V_93 -> V_126 , L_3 , V_16 ,
V_93 -> V_44 , V_93 -> V_114 , V_93 -> V_115 ) ;
if ( F_45 ( V_96 ) )
F_56 ( V_96 , V_93 -> V_44 & V_47 ? 0 : 1 ) ;
F_43 ( V_93 , V_99 ) ;
return 0 ;
}
static void F_57 ( struct V_92 * V_93 )
{
}
static int
F_58 ( struct V_127 * V_95 , struct V_128 * V_129 )
{
struct V_1 * V_19 = F_44 ( V_95 ) ;
int V_130 ;
V_130 = F_59 ( V_19 -> V_131 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_59 ( V_19 -> V_132 ) ;
if ( V_130 ) {
F_60 ( V_19 -> V_131 ) ;
return V_130 ;
}
return 0 ;
}
static int
F_61 ( struct V_127 * V_95 , struct V_128 * V_129 )
{
struct V_1 * V_19 = F_44 ( V_95 ) ;
F_60 ( V_19 -> V_132 ) ;
F_60 ( V_19 -> V_131 ) ;
return 0 ;
}
static int F_62 ( struct V_133 * V_134 )
{
struct V_135 * V_136 = V_134 -> V_126 . V_137 ;
const struct V_138 * V_139 =
F_63 ( V_140 , & V_134 -> V_126 ) ;
struct V_141 * V_142 =
F_64 ( & V_134 -> V_126 ) ;
struct V_127 * V_95 ;
struct V_1 * V_19 ;
struct V_143 * V_144 ;
int V_11 , V_130 , V_145 ;
if ( ! V_136 && ! V_142 ) {
F_65 ( & V_134 -> V_126 , L_4 ) ;
return - V_146 ;
}
V_130 = F_66 ( V_136 , L_5 , & V_145 ) ;
if ( V_130 < 0 ) {
if ( V_142 )
V_145 = V_142 -> V_147 ;
else
return V_130 ;
}
V_95 = F_67 ( & V_134 -> V_126 ,
sizeof( struct V_1 ) + sizeof( int ) * V_145 ) ;
if ( ! V_95 )
return - V_148 ;
F_68 ( V_134 , V_95 ) ;
V_95 -> V_149 = F_69 ( 1 , 32 ) ;
V_95 -> V_150 = V_134 -> V_151 ;
V_95 -> V_147 = V_145 ;
V_19 = F_44 ( V_95 ) ;
V_19 -> V_152 . V_95 = V_95 ;
for ( V_11 = 0 ; V_11 < V_95 -> V_147 ; V_11 ++ ) {
int V_153 = F_70 ( V_136 , L_6 , V_11 ) ;
if ( ! F_45 ( V_153 ) && V_142 )
V_153 = V_142 -> V_59 [ V_11 ] ;
V_19 -> V_59 [ V_11 ] = V_153 ;
if ( ! F_45 ( V_153 ) )
continue;
V_130 = F_71 ( & V_134 -> V_126 , V_19 -> V_59 [ V_11 ] ,
V_154 ) ;
if ( V_130 ) {
F_65 ( & V_134 -> V_126 , L_7 ) ;
goto V_155;
}
}
V_19 -> V_152 . V_59 = F_43 ;
V_19 -> V_152 . V_156 = F_50 ;
V_19 -> V_152 . V_157 = F_51 ;
V_19 -> V_152 . V_95 -> V_158 = F_54 ;
V_19 -> V_152 . V_95 -> V_159 = F_57 ;
V_19 -> V_152 . V_95 -> V_160 = F_58 ;
V_19 -> V_152 . V_95 -> V_161 = F_61 ;
V_19 -> V_152 . V_95 -> V_162 = V_46 | V_45 | V_47 ;
F_72 ( & V_19 -> V_111 ) ;
V_19 -> V_3 = V_139 ? V_139 -> V_163 :
(struct V_164 * ) V_134 -> V_165 -> V_166 ;
V_144 = F_73 ( V_134 , V_167 , 0 ) ;
V_19 -> V_26 = F_74 ( & V_134 -> V_126 , V_144 ) ;
if ( F_75 ( V_19 -> V_26 ) ) {
V_130 = F_76 ( V_19 -> V_26 ) ;
goto V_155;
}
V_19 -> V_105 = F_77 ( V_134 , 0 ) ;
if ( V_19 -> V_105 < 0 ) {
V_130 = V_19 -> V_105 ;
goto V_155;
}
V_130 = F_78 ( & V_134 -> V_126 , V_19 -> V_105 , F_48 , 0 ,
F_79 ( & V_134 -> V_126 ) , V_19 ) ;
if ( V_130 ) {
F_65 ( & V_134 -> V_126 , L_8 , V_19 -> V_105 , V_130 ) ;
goto V_155;
}
V_19 -> V_132 = F_80 ( & V_134 -> V_126 , L_9 ) ;
if ( F_75 ( V_19 -> V_132 ) ) {
V_130 = F_76 ( V_19 -> V_132 ) ;
goto V_155;
}
V_19 -> V_131 = F_80 ( & V_134 -> V_126 , L_10 ) ;
if ( F_75 ( V_19 -> V_131 ) ) {
V_130 = F_76 ( V_19 -> V_131 ) ;
goto V_155;
}
V_130 = F_81 ( V_19 -> V_131 ) ;
if ( V_130 )
goto V_155;
V_130 = F_81 ( V_19 -> V_132 ) ;
if ( V_130 )
goto V_168;
V_19 -> V_40 = F_82 ( V_19 -> V_131 ) ;
V_19 -> V_3 -> V_169 ( V_19 ) ;
V_19 -> V_3 -> V_110 ( V_19 , 0 ) ;
V_95 -> V_126 . V_137 = V_134 -> V_126 . V_137 ;
V_130 = F_83 ( & V_19 -> V_152 ) ;
if ( V_130 ) {
F_65 ( & V_134 -> V_126 , L_11 , V_130 ) ;
goto V_170;
}
F_84 ( & V_134 -> V_126 , L_12 ) ;
F_60 ( V_19 -> V_132 ) ;
F_60 ( V_19 -> V_131 ) ;
return V_130 ;
V_170:
F_85 ( V_19 -> V_132 ) ;
V_168:
F_85 ( V_19 -> V_131 ) ;
V_155:
F_86 ( V_95 ) ;
return V_130 ;
}
static int F_87 ( struct V_133 * V_134 )
{
struct V_127 * V_95 = F_88 ( V_134 ) ;
struct V_1 * V_19 = F_44 ( V_95 ) ;
F_89 ( & V_19 -> V_152 ) ;
F_13 ( 0 , V_19 -> V_26 + V_55 ) ;
F_90 ( V_19 -> V_132 ) ;
F_90 ( V_19 -> V_131 ) ;
F_86 ( V_95 ) ;
return 0 ;
}
