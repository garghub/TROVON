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
F_14 ( V_10 , V_17 ) ;
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
exit:
F_3 ( V_16 -> V_2 , V_6 -> V_19 + V_20 ) ;
return V_33 ;
}
static int F_25 ( struct V_23 * V_14 ,
T_4 V_34 )
{
T_4 V_35 = V_34 ^ V_14 -> V_34 ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
if ( ! ( V_35 & ( V_36 | V_37 ) ) )
return 0 ;
if ( ! F_26 ( V_14 ) )
return 0 ;
V_14 -> V_34 = V_34 ;
return F_4 ( V_6 ) ;
}
static void F_27 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
struct V_38 * V_39 ;
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 (ha, netdev)
F_31 ( V_6 , V_39 -> V_1 ) ;
}
static int F_32 ( struct V_23 * V_14 , int V_40 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_33 ( V_6 , V_41 , V_6 -> V_14 ,
L_3 , V_14 -> V_42 ,
V_40 ) ;
V_14 -> V_42 = V_40 ;
if ( F_26 ( V_14 ) )
return F_4 ( V_6 ) ;
return 0 ;
}
static int F_34 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
struct V_15 * V_16 = & V_6 -> V_16 ;
int V_7 ;
V_7 = F_35 ( V_16 -> V_16 , F_17 , 0 , L_4 , V_16 ) ;
if ( V_7 ) {
F_36 ( V_6 -> V_14 , L_5 ) ;
return V_7 ;
}
V_7 = F_37 ( V_6 ) ;
if ( V_7 ) {
F_36 ( V_6 -> V_14 , L_6 ) ;
F_38 ( V_16 -> V_16 , V_16 ) ;
return V_7 ;
}
V_7 = F_8 ( V_6 ) ;
if ( V_7 ) {
F_39 ( V_6 ) ;
F_38 ( V_16 -> V_16 , V_16 ) ;
return V_7 ;
}
V_7 = V_6 -> V_43 . V_44 ( V_6 ) ;
if ( V_7 ) {
F_6 ( V_6 ) ;
F_39 ( V_6 ) ;
F_38 ( V_16 -> V_16 , V_16 ) ;
return V_7 ;
}
return 0 ;
}
static int F_40 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_5 ( & V_6 -> V_8 ) ;
V_6 -> V_43 . V_45 ( V_6 ) ;
F_6 ( V_6 ) ;
F_39 ( V_6 ) ;
F_38 ( V_6 -> V_16 . V_16 , & V_6 -> V_16 ) ;
F_9 ( & V_6 -> V_8 ) ;
return 0 ;
}
static void F_41 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_20 ( & V_6 -> V_30 ) ;
}
static int F_42 ( struct V_23 * V_14 , struct V_46 * V_47 , int V_48 )
{
if ( ! F_26 ( V_14 ) )
return - V_49 ;
if ( ! V_14 -> V_50 )
return - V_51 ;
return F_43 ( V_14 -> V_50 , V_47 , V_48 ) ;
}
void F_44 ( struct V_5 * V_6 )
{
struct V_52 * V_53 = & V_6 -> V_53 ;
T_5 * V_54 = & V_6 -> V_53 . V_55 ;
void T_1 * V_19 = V_6 -> V_19 ;
unsigned int V_1 ;
V_1 = V_56 ;
while ( V_1 <= V_57 ) {
* V_54 += F_18 ( V_19 + V_1 ) ;
V_54 ++ ;
V_1 += sizeof( T_2 ) ;
}
V_53 -> V_58 += F_18 ( V_19 + V_59 ) ;
V_53 -> V_60 += F_18 ( V_19 + V_61 ) ;
V_1 = V_62 ;
V_54 = & V_53 -> V_63 ;
while ( V_1 <= V_64 ) {
* V_54 += F_18 ( V_19 + V_1 ) ;
V_54 ++ ;
V_1 += sizeof( T_2 ) ;
}
V_53 -> V_65 += F_18 ( V_19 + V_66 ) ;
}
static void F_45 ( struct V_23 * V_14 ,
struct V_67 * V_68 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
struct V_52 * V_53 = & V_6 -> V_53 ;
F_46 ( & V_53 -> V_69 ) ;
F_44 ( V_6 ) ;
V_68 -> V_70 = V_53 -> V_55 ;
V_68 -> V_71 = V_53 -> V_63 ;
V_68 -> V_72 = V_53 -> V_73 ;
V_68 -> V_74 = V_53 -> V_75 ;
V_68 -> V_76 = V_53 -> V_77 ;
V_68 -> V_78 = V_53 -> V_79 + V_53 -> V_80 * 2 +
V_53 -> V_81 + V_53 -> V_82 ;
V_68 -> V_83 = V_53 -> V_84 + V_53 -> V_85 +
V_53 -> V_86 + V_53 -> V_87 +
V_53 -> V_88 ;
V_68 -> V_89 = V_53 -> V_90 ;
V_68 -> V_91 = V_53 -> V_86 ;
V_68 -> V_92 = V_53 -> V_85 ;
V_68 -> V_93 = V_53 -> V_88 ;
V_68 -> V_94 = V_53 -> V_90 ;
V_68 -> V_95 = V_53 -> V_90 ;
V_68 -> V_96 = V_53 -> V_81 + V_53 -> V_82 +
V_53 -> V_97 + V_53 -> V_98 ;
V_68 -> V_99 = V_53 -> V_97 ;
V_68 -> V_100 = V_53 -> V_82 ;
V_68 -> V_101 = V_53 -> V_81 ;
F_47 ( & V_53 -> V_69 ) ;
}
static void F_48 ( struct V_102 * V_103 )
{
struct V_5 * V_6 =
F_11 ( V_103 , struct V_5 , V_30 ) ;
F_4 ( V_6 ) ;
}
static void F_49 ( struct V_5 * V_6 )
{
T_2 V_104 ;
V_6 -> V_105 = V_106 ;
V_6 -> V_107 = V_108 ;
V_6 -> V_109 = V_110 ;
V_6 -> V_111 = V_112 ;
V_6 -> V_113 = V_114 ;
V_6 -> V_115 = V_116 ;
V_6 -> V_117 = V_118 ;
V_6 -> V_119 = V_120 ;
V_6 -> V_121 = V_122 ;
V_6 -> V_123 = V_124 ;
V_6 -> V_125 = V_126 ;
V_6 -> V_127 = V_128 ;
V_104 = ( ( V_129 >> 1 ) << V_130 ) |
( ( V_131 >> 1 ) << V_132 ) ;
V_6 -> V_133 = V_104 ;
V_6 -> V_134 = V_135 ;
V_6 -> V_136 = true ;
V_6 -> V_137 = false ;
}
static int F_50 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
unsigned int V_140 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
struct V_142 * V_142 = F_51 ( & V_139 -> V_143 , V_144 [ V_140 ] ) ;
if ( F_52 ( V_142 ) ) {
F_53 ( & V_139 -> V_143 ,
L_7 ,
V_144 [ V_140 ] , F_54 ( V_142 ) ) ;
return F_54 ( V_142 ) ;
}
V_6 -> V_142 [ V_140 ] = V_142 ;
}
return 0 ;
}
static int F_55 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( F_56 ( & V_139 -> V_143 ) )
return 0 ;
V_7 = F_50 ( V_139 , V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_57 ( V_6 -> V_142 [ V_145 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_57 ( V_6 -> V_142 [ V_146 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_58 ( V_6 -> V_142 [ V_147 ] , 19200000 ) ;
if ( V_7 )
return V_7 ;
return F_57 ( V_6 -> V_142 [ V_147 ] ) ;
}
static int F_59 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( F_56 ( & V_139 -> V_143 ) )
return 0 ;
V_7 = F_58 ( V_6 -> V_142 [ V_148 ] , 125000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_57 ( V_6 -> V_142 [ V_148 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_58 ( V_6 -> V_142 [ V_147 ] , 125000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_58 ( V_6 -> V_142 [ V_149 ] , 25000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_57 ( V_6 -> V_142 [ V_149 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_57 ( V_6 -> V_142 [ V_150 ] ) ;
if ( V_7 )
return V_7 ;
return F_57 ( V_6 -> V_142 [ V_151 ] ) ;
}
static void F_60 ( struct V_5 * V_6 )
{
unsigned int V_140 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ )
F_61 ( V_6 -> V_142 [ V_140 ] ) ;
}
static int F_62 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
struct V_23 * V_14 = V_6 -> V_14 ;
struct V_152 * V_153 ;
char V_154 [ V_155 ] ;
int V_7 = 0 ;
if ( F_63 ( & V_139 -> V_143 , V_154 , V_155 ) )
F_64 ( V_14 -> V_156 , V_154 ) ;
else
F_65 ( V_14 ) ;
V_7 = F_66 ( V_139 , 0 ) ;
if ( V_7 < 0 ) {
F_53 ( & V_139 -> V_143 ,
L_8 , V_7 ) ;
return V_7 ;
}
V_6 -> V_16 . V_16 = V_7 ;
V_153 = F_67 ( V_139 , V_157 , 0 ) ;
V_6 -> V_19 = F_68 ( & V_139 -> V_143 , V_153 ) ;
if ( F_52 ( V_6 -> V_19 ) )
return F_54 ( V_6 -> V_19 ) ;
V_153 = F_67 ( V_139 , V_157 , 1 ) ;
V_6 -> V_158 = F_68 ( & V_139 -> V_143 , V_153 ) ;
if ( F_52 ( V_6 -> V_158 ) )
return F_54 ( V_6 -> V_158 ) ;
V_14 -> V_159 = ( unsigned long ) V_6 -> V_19 ;
return 0 ;
}
static int F_69 ( struct V_138 * V_139 )
{
struct V_23 * V_14 ;
struct V_5 * V_6 ;
struct V_160 * V_43 ;
T_6 V_161 , V_162 ;
T_2 V_104 ;
int V_7 ;
V_7 = F_70 ( & V_139 -> V_143 , F_71 ( 64 ) ) ;
if ( V_7 ) {
V_7 = F_70 ( & V_139 -> V_143 , F_71 ( 32 ) ) ;
if ( V_7 ) {
F_53 ( & V_139 -> V_143 , L_9 ) ;
return V_7 ;
}
}
V_14 = F_72 ( sizeof( struct V_5 ) ) ;
if ( ! V_14 )
return - V_163 ;
F_73 ( & V_139 -> V_143 , V_14 ) ;
F_74 ( V_14 , & V_139 -> V_143 ) ;
F_75 ( V_14 ) ;
V_6 = F_12 ( V_14 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_164 = V_165 ;
V_43 = & V_6 -> V_43 ;
F_76 ( & V_43 -> V_166 , 0 ) ;
F_77 ( & V_6 -> V_8 ) ;
F_78 ( & V_6 -> V_53 . V_69 ) ;
V_6 -> V_16 . V_2 = V_167 | V_168 ;
V_7 = F_62 ( V_139 , V_6 ) ;
if ( V_7 )
goto V_169;
V_7 = F_55 ( V_139 , V_6 ) ;
if ( V_7 ) {
F_53 ( & V_139 -> V_143 , L_10 ) ;
goto V_169;
}
V_14 -> V_170 = V_171 ;
V_14 -> V_16 = V_6 -> V_16 . V_16 ;
V_14 -> V_172 = & V_173 ;
F_49 ( V_6 ) ;
V_7 = F_79 ( V_139 , V_6 ) ;
if ( V_7 )
goto V_174;
V_7 = F_80 ( V_139 , V_6 ) ;
if ( V_7 )
goto V_175;
V_7 = F_59 ( V_139 , V_6 ) ;
if ( V_7 ) {
F_53 ( & V_139 -> V_143 , L_10 ) ;
goto V_175;
}
V_14 -> V_34 = V_176 | V_177 | V_178 |
V_179 | V_180 | V_37 |
V_36 ;
V_14 -> V_181 = V_14 -> V_34 ;
V_14 -> V_182 |= V_176 | V_177 |
V_179 | V_180 ;
V_14 -> V_183 = V_184 -
( V_185 + V_186 + V_187 ) ;
V_14 -> V_188 = V_189 -
( V_185 + V_186 + V_187 ) ;
F_81 ( & V_6 -> V_30 , F_48 ) ;
F_82 ( V_139 , V_6 ) ;
F_83 ( V_14 , & V_6 -> V_13 . V_10 , F_10 ,
V_190 ) ;
V_7 = F_84 ( V_14 ) ;
if ( V_7 ) {
F_53 ( & V_139 -> V_143 , L_11 ) ;
goto V_191;
}
V_104 = F_18 ( V_6 -> V_19 + V_192 ) ;
V_161 = ( V_104 & V_193 ) >> V_194 ;
V_162 = ( V_104 & V_195 ) >> V_196 ;
V_104 = F_18 ( V_6 -> V_19 + V_197 ) ;
F_33 ( V_6 , V_198 , V_14 ,
L_12 ,
V_161 , V_162 ,
( V_104 & V_199 ) >> V_200 ,
( V_104 & V_201 ) >> V_202 ,
( V_104 & V_203 ) >> V_204 ) ;
return 0 ;
V_191:
F_85 ( & V_6 -> V_13 . V_10 ) ;
V_175:
F_86 ( & V_6 -> V_50 -> V_205 . V_143 ) ;
F_87 ( V_6 -> V_206 ) ;
V_174:
F_60 ( V_6 ) ;
V_169:
F_88 ( V_14 ) ;
return V_7 ;
}
static int F_89 ( struct V_138 * V_139 )
{
struct V_23 * V_14 = F_90 ( & V_139 -> V_143 ) ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_91 ( V_14 ) ;
F_85 ( & V_6 -> V_13 . V_10 ) ;
F_60 ( V_6 ) ;
F_86 ( & V_6 -> V_50 -> V_205 . V_143 ) ;
F_87 ( V_6 -> V_206 ) ;
F_88 ( V_14 ) ;
if ( V_6 -> V_43 . V_207 )
F_92 ( V_6 -> V_43 . V_207 ) ;
F_92 ( V_6 -> V_43 . V_19 ) ;
return 0 ;
}
static void F_93 ( struct V_138 * V_139 )
{
struct V_23 * V_14 = F_90 ( & V_139 -> V_143 ) ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
struct V_160 * V_208 = & V_6 -> V_43 ;
if ( V_14 -> V_209 & V_210 ) {
V_208 -> V_45 ( V_6 ) ;
F_94 ( V_6 ) ;
}
}
