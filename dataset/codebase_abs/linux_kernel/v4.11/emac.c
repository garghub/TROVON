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
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_34 ( V_6 , V_44 , V_6 -> V_14 ,
L_3 , V_14 -> V_45 ,
V_43 ) ;
V_14 -> V_45 = V_43 ;
if ( F_27 ( V_14 ) )
return F_4 ( V_6 ) ;
return 0 ;
}
static int F_35 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
struct V_15 * V_16 = & V_6 -> V_16 ;
int V_7 ;
V_7 = F_36 ( V_16 -> V_16 , F_17 , 0 , L_4 , V_16 ) ;
if ( V_7 ) {
F_37 ( V_6 -> V_14 , L_5 ) ;
return V_7 ;
}
V_7 = F_38 ( V_6 ) ;
if ( V_7 ) {
F_37 ( V_6 -> V_14 , L_6 ) ;
F_39 ( V_16 -> V_16 , V_16 ) ;
return V_7 ;
}
V_7 = F_8 ( V_6 ) ;
if ( V_7 ) {
F_40 ( V_6 ) ;
F_39 ( V_16 -> V_16 , V_16 ) ;
return V_7 ;
}
V_7 = V_6 -> V_46 . V_47 ( V_6 ) ;
if ( V_7 ) {
F_6 ( V_6 ) ;
F_40 ( V_6 ) ;
F_39 ( V_16 -> V_16 , V_16 ) ;
return V_7 ;
}
return 0 ;
}
static int F_41 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_5 ( & V_6 -> V_8 ) ;
V_6 -> V_46 . V_48 ( V_6 ) ;
F_6 ( V_6 ) ;
F_40 ( V_6 ) ;
F_39 ( V_6 -> V_16 . V_16 , & V_6 -> V_16 ) ;
F_9 ( & V_6 -> V_8 ) ;
return 0 ;
}
static void F_42 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_20 ( & V_6 -> V_30 ) ;
}
static int F_43 ( struct V_23 * V_14 , struct V_49 * V_50 , int V_51 )
{
if ( ! F_27 ( V_14 ) )
return - V_52 ;
if ( ! V_14 -> V_34 )
return - V_53 ;
return F_44 ( V_14 -> V_34 , V_50 , V_51 ) ;
}
void F_45 ( struct V_5 * V_6 )
{
struct V_54 * V_55 = & V_6 -> V_55 ;
T_5 * V_56 = & V_6 -> V_55 . V_57 ;
void T_1 * V_19 = V_6 -> V_19 ;
unsigned int V_1 ;
V_1 = V_58 ;
while ( V_1 <= V_59 ) {
* V_56 += F_18 ( V_19 + V_1 ) ;
V_56 ++ ;
V_1 += sizeof( T_2 ) ;
}
V_55 -> V_60 += F_18 ( V_19 + V_61 ) ;
V_55 -> V_62 += F_18 ( V_19 + V_63 ) ;
V_1 = V_64 ;
V_56 = & V_55 -> V_65 ;
while ( V_1 <= V_66 ) {
* V_56 += F_18 ( V_19 + V_1 ) ;
V_56 ++ ;
V_1 += sizeof( T_2 ) ;
}
V_55 -> V_67 += F_18 ( V_19 + V_68 ) ;
}
static void F_46 ( struct V_23 * V_14 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
struct V_54 * V_55 = & V_6 -> V_55 ;
F_47 ( & V_55 -> V_71 ) ;
F_45 ( V_6 ) ;
V_70 -> V_72 = V_55 -> V_57 ;
V_70 -> V_73 = V_55 -> V_65 ;
V_70 -> V_74 = V_55 -> V_75 ;
V_70 -> V_76 = V_55 -> V_77 ;
V_70 -> V_78 = V_55 -> V_79 ;
V_70 -> V_80 = V_55 -> V_81 + V_55 -> V_82 * 2 +
V_55 -> V_83 + V_55 -> V_84 ;
V_70 -> V_85 = V_55 -> V_86 + V_55 -> V_87 +
V_55 -> V_88 + V_55 -> V_89 +
V_55 -> V_90 ;
V_70 -> V_91 = V_55 -> V_92 ;
V_70 -> V_93 = V_55 -> V_88 ;
V_70 -> V_94 = V_55 -> V_87 ;
V_70 -> V_95 = V_55 -> V_90 ;
V_70 -> V_96 = V_55 -> V_92 ;
V_70 -> V_97 = V_55 -> V_92 ;
V_70 -> V_98 = V_55 -> V_83 + V_55 -> V_84 +
V_55 -> V_99 + V_55 -> V_100 ;
V_70 -> V_101 = V_55 -> V_99 ;
V_70 -> V_102 = V_55 -> V_84 ;
V_70 -> V_103 = V_55 -> V_83 ;
F_48 ( & V_55 -> V_71 ) ;
}
static void F_49 ( struct V_104 * V_105 )
{
struct V_5 * V_6 =
F_11 ( V_105 , struct V_5 , V_30 ) ;
F_4 ( V_6 ) ;
}
static void F_50 ( struct V_5 * V_6 )
{
T_2 V_106 ;
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
V_6 -> V_129 = V_130 ;
V_106 = ( ( V_131 >> 1 ) << V_132 ) |
( ( V_133 >> 1 ) << V_134 ) ;
V_6 -> V_135 = V_106 ;
V_6 -> V_136 = V_137 ;
V_6 -> V_138 = true ;
}
static int F_51 ( struct V_139 * V_140 ,
struct V_5 * V_6 )
{
unsigned int V_141 ;
for ( V_141 = 0 ; V_141 < V_142 ; V_141 ++ ) {
struct V_143 * V_143 = F_52 ( & V_140 -> V_144 , V_145 [ V_141 ] ) ;
if ( F_53 ( V_143 ) ) {
F_54 ( & V_140 -> V_144 ,
L_7 ,
V_145 [ V_141 ] , F_55 ( V_143 ) ) ;
return F_55 ( V_143 ) ;
}
V_6 -> V_143 [ V_141 ] = V_143 ;
}
return 0 ;
}
static int F_56 ( struct V_139 * V_140 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( F_57 ( & V_140 -> V_144 ) )
return 0 ;
V_7 = F_51 ( V_140 , V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_58 ( V_6 -> V_143 [ V_146 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_58 ( V_6 -> V_143 [ V_147 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_59 ( V_6 -> V_143 [ V_148 ] , 19200000 ) ;
if ( V_7 )
return V_7 ;
return F_58 ( V_6 -> V_143 [ V_148 ] ) ;
}
static int F_60 ( struct V_139 * V_140 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( F_57 ( & V_140 -> V_144 ) )
return 0 ;
V_7 = F_59 ( V_6 -> V_143 [ V_149 ] , 125000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_58 ( V_6 -> V_143 [ V_149 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_59 ( V_6 -> V_143 [ V_148 ] , 125000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_59 ( V_6 -> V_143 [ V_150 ] , 25000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_58 ( V_6 -> V_143 [ V_150 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_58 ( V_6 -> V_143 [ V_151 ] ) ;
if ( V_7 )
return V_7 ;
return F_58 ( V_6 -> V_143 [ V_152 ] ) ;
}
static void F_61 ( struct V_5 * V_6 )
{
unsigned int V_141 ;
for ( V_141 = 0 ; V_141 < V_142 ; V_141 ++ )
F_62 ( V_6 -> V_143 [ V_141 ] ) ;
}
static int F_63 ( struct V_139 * V_140 ,
struct V_5 * V_6 )
{
struct V_23 * V_14 = V_6 -> V_14 ;
struct V_153 * V_154 ;
char V_155 [ V_156 ] ;
int V_7 = 0 ;
if ( F_64 ( & V_140 -> V_144 , V_155 , V_156 ) )
F_65 ( V_14 -> V_157 , V_155 ) ;
else
F_66 ( V_14 ) ;
V_7 = F_67 ( V_140 , 0 ) ;
if ( V_7 < 0 ) {
F_54 ( & V_140 -> V_144 ,
L_8 , V_7 ) ;
return V_7 ;
}
V_6 -> V_16 . V_16 = V_7 ;
V_154 = F_68 ( V_140 , V_158 , 0 ) ;
V_6 -> V_19 = F_69 ( & V_140 -> V_144 , V_154 ) ;
if ( F_53 ( V_6 -> V_19 ) )
return F_55 ( V_6 -> V_19 ) ;
V_154 = F_68 ( V_140 , V_158 , 1 ) ;
V_6 -> V_159 = F_69 ( & V_140 -> V_144 , V_154 ) ;
if ( F_53 ( V_6 -> V_159 ) )
return F_55 ( V_6 -> V_159 ) ;
V_14 -> V_160 = ( unsigned long ) V_6 -> V_19 ;
return 0 ;
}
static int F_70 ( struct V_139 * V_140 )
{
struct V_23 * V_14 ;
struct V_5 * V_6 ;
struct V_161 * V_46 ;
T_6 V_162 , V_163 ;
T_2 V_106 ;
int V_7 ;
V_7 = F_71 ( & V_140 -> V_144 , F_72 ( 64 ) ) ;
if ( V_7 ) {
V_7 = F_71 ( & V_140 -> V_144 , F_72 ( 32 ) ) ;
if ( V_7 ) {
F_54 ( & V_140 -> V_144 , L_9 ) ;
return V_7 ;
}
}
V_14 = F_73 ( sizeof( struct V_5 ) ) ;
if ( ! V_14 )
return - V_164 ;
F_74 ( & V_140 -> V_144 , V_14 ) ;
F_75 ( V_14 , & V_140 -> V_144 ) ;
F_76 ( V_14 ) ;
V_6 = F_12 ( V_14 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_165 = V_166 ;
V_46 = & V_6 -> V_46 ;
F_77 ( & V_46 -> V_167 , 0 ) ;
F_78 ( & V_6 -> V_8 ) ;
F_79 ( & V_6 -> V_55 . V_71 ) ;
V_6 -> V_16 . V_2 = V_168 | V_169 ;
V_7 = F_63 ( V_140 , V_6 ) ;
if ( V_7 )
goto V_170;
V_7 = F_56 ( V_140 , V_6 ) ;
if ( V_7 ) {
F_54 ( & V_140 -> V_144 , L_10 ) ;
goto V_170;
}
V_14 -> V_171 = V_172 ;
V_14 -> V_16 = V_6 -> V_16 . V_16 ;
V_14 -> V_173 = & V_174 ;
F_50 ( V_6 ) ;
V_7 = F_80 ( V_140 , V_6 ) ;
if ( V_7 )
goto V_175;
V_7 = F_81 ( V_140 , V_6 ) ;
if ( V_7 )
goto V_176;
V_7 = F_60 ( V_140 , V_6 ) ;
if ( V_7 ) {
F_54 ( & V_140 -> V_144 , L_10 ) ;
goto V_176;
}
F_82 ( V_6 ) ;
V_14 -> V_37 = V_177 | V_178 | V_179 |
V_180 | V_181 | V_40 |
V_39 ;
V_14 -> V_182 = V_14 -> V_37 ;
V_14 -> V_183 |= V_177 | V_178 |
V_180 | V_181 ;
V_14 -> V_184 = V_185 -
( V_186 + V_187 + V_188 ) ;
V_14 -> V_189 = V_190 -
( V_186 + V_187 + V_188 ) ;
F_83 ( & V_6 -> V_30 , F_49 ) ;
F_84 ( V_140 , V_6 ) ;
F_85 ( V_14 , & V_6 -> V_13 . V_10 , F_10 ,
V_191 ) ;
V_7 = F_86 ( V_14 ) ;
if ( V_7 ) {
F_54 ( & V_140 -> V_144 , L_11 ) ;
goto V_192;
}
V_106 = F_18 ( V_6 -> V_19 + V_193 ) ;
V_162 = ( V_106 & V_194 ) >> V_195 ;
V_163 = ( V_106 & V_196 ) >> V_197 ;
V_106 = F_18 ( V_6 -> V_19 + V_198 ) ;
F_34 ( V_6 , V_199 , V_14 ,
L_12 ,
V_162 , V_163 ,
( V_106 & V_200 ) >> V_201 ,
( V_106 & V_202 ) >> V_203 ,
( V_106 & V_204 ) >> V_205 ) ;
return 0 ;
V_192:
F_87 ( & V_6 -> V_13 . V_10 ) ;
V_176:
F_88 ( & V_6 -> V_34 -> V_206 . V_144 ) ;
F_89 ( V_6 -> V_207 ) ;
V_175:
F_61 ( V_6 ) ;
V_170:
F_90 ( V_14 ) ;
return V_7 ;
}
static int F_91 ( struct V_139 * V_140 )
{
struct V_23 * V_14 = F_92 ( & V_140 -> V_144 ) ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_93 ( V_14 ) ;
F_87 ( & V_6 -> V_13 . V_10 ) ;
F_61 ( V_6 ) ;
F_88 ( & V_6 -> V_34 -> V_206 . V_144 ) ;
F_89 ( V_6 -> V_207 ) ;
F_90 ( V_14 ) ;
if ( V_6 -> V_46 . V_208 )
F_94 ( V_6 -> V_46 . V_208 ) ;
F_94 ( V_6 -> V_46 . V_19 ) ;
return 0 ;
}
