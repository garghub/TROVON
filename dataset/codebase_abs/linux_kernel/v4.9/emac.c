void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 = F_2 ( V_1 ) ;
F_3 ( ( ( V_4 & ~ V_2 ) | V_3 ) , V_1 ) ;
}
int F_4 ( struct V_5 * V_6 )
{
int V_7 ;
F_5 ( & V_6 -> V_8 ) ;
F_6 ( V_6 ) ;
F_7 ( V_6 ) ;
V_7 = F_8 ( V_6 ) ;
F_9 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_10 ( struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 =
F_11 ( V_10 , struct V_12 , V_10 ) ;
struct V_5 * V_6 = F_12 ( V_13 -> V_14 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
int V_17 = 0 ;
F_13 ( V_6 , V_13 , & V_17 , V_11 ) ;
if ( V_17 < V_11 ) {
F_14 ( V_10 ) ;
V_16 -> V_2 |= V_13 -> V_18 ;
F_3 ( V_16 -> V_2 , V_6 -> V_19 + V_20 ) ;
}
return V_17 ;
}
static int F_15 ( struct V_21 * V_22 , struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
return F_16 ( V_6 , & V_6 -> V_24 , V_22 ) ;
}
T_3 F_17 ( int V_25 , void * V_4 )
{
struct V_15 * V_16 = V_4 ;
struct V_5 * V_6 =
F_11 ( V_16 , struct V_5 , V_16 ) ;
struct V_12 * V_13 = & V_6 -> V_13 ;
T_2 V_26 , V_27 ;
F_3 ( 0 , V_6 -> V_19 + V_20 ) ;
V_26 = F_18 ( V_6 -> V_19 + V_28 ) ;
V_27 = V_26 & V_16 -> V_2 ;
if ( V_27 == 0 )
goto exit;
if ( V_27 & V_29 ) {
F_19 ( V_6 , V_18 , V_6 -> V_14 ,
L_1 ,
V_27 & V_29 ) ;
F_20 ( & V_6 -> V_30 ) ;
}
if ( V_27 & V_13 -> V_18 ) {
if ( F_21 ( & V_13 -> V_10 ) ) {
V_16 -> V_2 &= ~ V_13 -> V_18 ;
F_22 ( & V_13 -> V_10 ) ;
}
}
if ( V_27 & V_31 )
F_23 ( V_6 , & V_6 -> V_24 ) ;
if ( V_27 & V_32 )
F_24 ( L_2 ) ;
if ( V_27 & V_33 )
F_25 ( V_6 -> V_34 , ! ! ( V_27 & V_35 ) ) ;
exit:
F_3 ( V_16 -> V_2 , V_6 -> V_19 + V_20 ) ;
return V_36 ;
}
static int F_26 ( struct V_23 * V_14 ,
T_4 V_37 )
{
T_4 V_38 = V_37 ^ V_14 -> V_37 ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
if ( ! ( V_38 & ( V_39 | V_40 ) ) )
return 0 ;
if ( ! F_27 ( V_14 ) )
return 0 ;
V_14 -> V_37 = V_37 ;
return F_4 ( V_6 ) ;
}
static void F_28 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
struct V_41 * V_42 ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 (ha, netdev)
F_32 ( V_6 , V_42 -> V_1 ) ;
}
static int F_33 ( struct V_23 * V_14 , int V_43 )
{
unsigned int V_44 = V_43 + V_45 + V_46 + V_47 ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
if ( ( V_44 < V_48 ) ||
( V_44 > V_49 ) ) {
F_34 ( V_6 -> V_14 , L_3 ) ;
return - V_50 ;
}
F_35 ( V_6 , V_51 , V_6 -> V_14 ,
L_4 , V_14 -> V_52 ,
V_43 ) ;
V_14 -> V_52 = V_43 ;
if ( F_27 ( V_14 ) )
return F_4 ( V_6 ) ;
return 0 ;
}
static int F_36 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
int V_7 ;
V_7 = F_37 ( V_6 ) ;
if ( V_7 ) {
F_34 ( V_6 -> V_14 , L_5 ) ;
return V_7 ;
}
V_7 = F_8 ( V_6 ) ;
if ( V_7 ) {
F_38 ( V_6 ) ;
return V_7 ;
}
F_39 ( V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_5 ( & V_6 -> V_8 ) ;
F_6 ( V_6 ) ;
F_38 ( V_6 ) ;
F_9 ( & V_6 -> V_8 ) ;
return 0 ;
}
static void F_41 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_20 ( & V_6 -> V_30 ) ;
}
static int F_42 ( struct V_23 * V_14 , struct V_53 * V_54 , int V_55 )
{
if ( ! F_27 ( V_14 ) )
return - V_50 ;
if ( ! V_14 -> V_34 )
return - V_56 ;
return F_43 ( V_14 -> V_34 , V_54 , V_55 ) ;
}
static struct V_57 * F_44 ( struct V_23 * V_14 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
unsigned int V_1 = V_59 ;
struct V_60 * V_61 = & V_6 -> V_61 ;
T_5 * V_62 = & V_6 -> V_61 . V_63 ;
T_2 V_3 ;
F_45 ( & V_61 -> V_64 ) ;
while ( V_1 <= V_65 ) {
V_3 = F_18 ( V_6 -> V_19 + V_1 ) ;
* V_62 += V_3 ;
V_62 ++ ;
V_1 += sizeof( T_2 ) ;
}
V_3 = F_18 ( V_6 -> V_19 + V_66 ) ;
V_6 -> V_61 . V_67 += V_3 ;
V_3 = F_18 ( V_6 -> V_19 + V_68 ) ;
V_6 -> V_61 . V_69 += V_3 ;
V_1 = V_70 ;
V_62 = & V_6 -> V_61 . V_71 ;
while ( V_1 <= V_72 ) {
V_3 = F_18 ( V_6 -> V_19 + V_1 ) ;
* V_62 += V_3 ;
++ V_62 ;
V_1 += sizeof( T_2 ) ;
}
V_3 = F_18 ( V_6 -> V_19 + V_73 ) ;
V_6 -> V_61 . V_74 += V_3 ;
V_58 -> V_75 = V_61 -> V_63 ;
V_58 -> V_76 = V_61 -> V_71 ;
V_58 -> V_77 = V_61 -> V_78 ;
V_58 -> V_79 = V_61 -> V_80 ;
V_58 -> V_81 = V_61 -> V_82 ;
V_58 -> V_83 = V_61 -> V_84 + V_61 -> V_85 * 2 +
V_61 -> V_86 + V_61 -> V_87 ;
V_58 -> V_88 = V_61 -> V_89 + V_61 -> V_90 +
V_61 -> V_91 + V_61 -> V_92 +
V_61 -> V_93 ;
V_58 -> V_94 = V_61 -> V_95 ;
V_58 -> V_96 = V_61 -> V_91 ;
V_58 -> V_97 = V_61 -> V_90 ;
V_58 -> V_98 = V_61 -> V_93 ;
V_58 -> V_99 = V_61 -> V_95 ;
V_58 -> V_100 = V_61 -> V_95 ;
V_58 -> V_101 = V_61 -> V_86 + V_61 -> V_87 +
V_61 -> V_102 + V_61 -> V_103 ;
V_58 -> V_104 = V_61 -> V_102 ;
V_58 -> V_105 = V_61 -> V_87 ;
V_58 -> V_106 = V_61 -> V_86 ;
F_46 ( & V_61 -> V_64 ) ;
return V_58 ;
}
static void F_47 ( struct V_107 * V_108 )
{
struct V_5 * V_6 =
F_11 ( V_108 , struct V_5 , V_30 ) ;
F_4 ( V_6 ) ;
}
static void F_48 ( struct V_5 * V_6 )
{
T_2 V_109 ;
V_6 -> V_110 = V_111 ;
V_6 -> V_112 = V_113 ;
V_6 -> V_114 = V_115 ;
V_6 -> V_116 = V_117 ;
V_6 -> V_118 = V_119 ;
V_6 -> V_120 = V_121 ;
V_6 -> V_122 = V_123 ;
V_6 -> V_124 = V_125 ;
V_6 -> V_126 = V_127 ;
V_109 = ( ( V_128 >> 1 ) << V_129 ) |
( ( V_130 >> 1 ) << V_131 ) ;
V_6 -> V_132 = V_109 ;
V_6 -> V_133 = V_134 ;
}
static int F_49 ( struct V_135 * V_136 ,
struct V_5 * V_6 )
{
unsigned int V_137 ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ ) {
struct V_139 * V_139 = F_50 ( & V_136 -> V_140 , V_141 [ V_137 ] ) ;
if ( F_51 ( V_139 ) ) {
F_52 ( & V_136 -> V_140 ,
L_6 ,
V_141 [ V_137 ] , F_53 ( V_139 ) ) ;
return F_53 ( V_139 ) ;
}
V_6 -> V_139 [ V_137 ] = V_139 ;
}
return 0 ;
}
static int F_54 ( struct V_135 * V_136 ,
struct V_5 * V_6 )
{
int V_7 ;
V_7 = F_49 ( V_136 , V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_55 ( V_6 -> V_139 [ V_142 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_55 ( V_6 -> V_139 [ V_143 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_6 -> V_139 [ V_144 ] , 19200000 ) ;
if ( V_7 )
return V_7 ;
return F_55 ( V_6 -> V_139 [ V_144 ] ) ;
}
static int F_57 ( struct V_135 * V_136 ,
struct V_5 * V_6 )
{
int V_7 ;
V_7 = F_56 ( V_6 -> V_139 [ V_145 ] , 125000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_55 ( V_6 -> V_139 [ V_145 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_6 -> V_139 [ V_144 ] , 125000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_6 -> V_139 [ V_146 ] , 25000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_55 ( V_6 -> V_139 [ V_146 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_55 ( V_6 -> V_139 [ V_147 ] ) ;
if ( V_7 )
return V_7 ;
return F_55 ( V_6 -> V_139 [ V_148 ] ) ;
}
static void F_58 ( struct V_5 * V_6 )
{
unsigned int V_137 ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
F_59 ( V_6 -> V_139 [ V_137 ] ) ;
}
static int F_60 ( struct V_135 * V_136 ,
struct V_5 * V_6 )
{
struct V_23 * V_14 = V_6 -> V_14 ;
struct V_149 * V_150 ;
char V_151 [ V_152 ] ;
int V_7 = 0 ;
if ( F_61 ( & V_136 -> V_140 , V_151 , V_152 ) )
F_62 ( V_14 -> V_153 , V_151 ) ;
else
F_63 ( V_14 ) ;
V_7 = F_64 ( V_136 , 0 ) ;
if ( V_7 < 0 ) {
F_52 ( & V_136 -> V_140 ,
L_7 , V_7 ) ;
return V_7 ;
}
V_6 -> V_16 . V_16 = V_7 ;
V_150 = F_65 ( V_136 , V_154 , 0 ) ;
V_6 -> V_19 = F_66 ( & V_136 -> V_140 , V_150 ) ;
if ( F_51 ( V_6 -> V_19 ) )
return F_53 ( V_6 -> V_19 ) ;
V_150 = F_65 ( V_136 , V_154 , 1 ) ;
V_6 -> V_155 = F_66 ( & V_136 -> V_140 , V_150 ) ;
if ( F_51 ( V_6 -> V_155 ) )
return F_53 ( V_6 -> V_155 ) ;
V_14 -> V_156 = ( unsigned long ) V_6 -> V_19 ;
return 0 ;
}
static int F_67 ( struct V_135 * V_136 )
{
struct V_23 * V_14 ;
struct V_5 * V_6 ;
struct V_157 * V_158 ;
T_6 V_159 , V_160 ;
T_2 V_109 ;
int V_7 ;
V_7 = F_68 ( & V_136 -> V_140 , F_69 ( 64 ) ) ;
if ( V_7 ) {
V_7 = F_68 ( & V_136 -> V_140 , F_69 ( 32 ) ) ;
if ( V_7 ) {
F_52 ( & V_136 -> V_140 , L_8 ) ;
return V_7 ;
}
}
V_14 = F_70 ( sizeof( struct V_5 ) ) ;
if ( ! V_14 )
return - V_161 ;
F_71 ( & V_136 -> V_140 , V_14 ) ;
F_72 ( V_14 , & V_136 -> V_140 ) ;
V_6 = F_12 ( V_14 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_162 = V_163 ;
V_158 = & V_6 -> V_158 ;
F_73 ( & V_6 -> V_8 ) ;
F_74 ( & V_6 -> V_61 . V_64 ) ;
V_6 -> V_16 . V_2 = V_164 | V_165 ;
V_7 = F_60 ( V_136 , V_6 ) ;
if ( V_7 )
goto V_166;
V_7 = F_54 ( V_136 , V_6 ) ;
if ( V_7 ) {
F_52 ( & V_136 -> V_140 , L_9 ) ;
goto V_166;
}
V_14 -> V_167 = V_168 ;
V_14 -> V_16 = V_6 -> V_16 . V_16 ;
V_6 -> V_169 = V_170 ;
V_6 -> V_171 = V_172 ;
V_6 -> V_173 = V_174 ;
V_14 -> V_175 = & V_176 ;
F_48 ( V_6 ) ;
V_7 = F_75 ( V_136 , V_6 ) ;
if ( V_7 )
goto V_177;
V_7 = F_76 ( V_136 , V_6 ) ;
if ( V_7 )
goto V_178;
V_7 = F_57 ( V_136 , V_6 ) ;
if ( V_7 ) {
F_52 ( & V_136 -> V_140 , L_9 ) ;
goto V_178;
}
F_77 ( V_6 ) ;
V_14 -> V_37 = V_179 | V_180 | V_181 |
V_182 | V_183 | V_40 |
V_39 ;
V_14 -> V_184 = V_14 -> V_37 ;
V_14 -> V_185 |= V_179 | V_180 |
V_182 | V_183 ;
F_78 ( & V_6 -> V_30 , F_47 ) ;
F_79 ( V_136 , V_6 ) ;
F_80 ( V_14 , & V_6 -> V_13 . V_10 , F_10 ,
V_186 ) ;
V_7 = F_81 ( V_14 ) ;
if ( V_7 ) {
F_52 ( & V_136 -> V_140 , L_10 ) ;
goto V_187;
}
V_109 = F_18 ( V_6 -> V_19 + V_188 ) ;
V_159 = ( V_109 & V_189 ) >> V_190 ;
V_160 = ( V_109 & V_191 ) >> V_192 ;
V_109 = F_18 ( V_6 -> V_19 + V_193 ) ;
F_35 ( V_6 , V_194 , V_14 ,
L_11 ,
V_159 , V_160 ,
( V_109 & V_195 ) >> V_196 ,
( V_109 & V_197 ) >> V_198 ,
( V_109 & V_199 ) >> V_200 ) ;
return 0 ;
V_187:
F_82 ( & V_6 -> V_13 . V_10 ) ;
V_178:
if ( ! F_83 ( & V_136 -> V_140 ) )
F_84 ( & V_6 -> V_34 -> V_201 . V_140 ) ;
F_85 ( V_6 -> V_202 ) ;
V_177:
F_58 ( V_6 ) ;
V_166:
F_86 ( V_14 ) ;
return V_7 ;
}
static int F_87 ( struct V_135 * V_136 )
{
struct V_23 * V_14 = F_88 ( & V_136 -> V_140 ) ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_89 ( V_14 ) ;
F_82 ( & V_6 -> V_13 . V_10 ) ;
F_58 ( V_6 ) ;
if ( ! F_83 ( & V_136 -> V_140 ) )
F_84 ( & V_6 -> V_34 -> V_201 . V_140 ) ;
F_85 ( V_6 -> V_202 ) ;
F_86 ( V_14 ) ;
if ( V_6 -> V_158 . V_203 )
F_90 ( V_6 -> V_158 . V_203 ) ;
F_90 ( V_6 -> V_158 . V_19 ) ;
return 0 ;
}
