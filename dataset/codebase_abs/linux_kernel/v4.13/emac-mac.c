void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 , V_5 , V_6 , V_7 ;
V_4 = F_2 ( V_8 , V_3 ) ;
V_6 = ( V_4 >> 31 ) & 0x1 ;
V_5 = ( V_4 >> 26 ) & 0x1F ;
V_7 = F_3 ( V_2 -> V_9 + V_10 + ( V_6 << 2 ) ) ;
V_7 |= F_4 ( V_5 ) ;
F_5 ( V_7 , V_2 -> V_9 + V_10 + ( V_6 << 2 ) ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_5 ( 0 , V_2 -> V_9 + V_10 ) ;
F_5 ( 0 , V_2 -> V_9 + V_11 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_2 V_14 ;
V_14 = F_3 ( V_2 -> V_9 + V_15 ) ;
V_14 &= ~ ( V_16 | V_17 | V_18 | V_19 ) ;
if ( V_13 -> V_20 & V_21 )
V_14 |= V_16 ;
if ( V_13 -> V_22 & V_23 )
V_14 |= V_17 ;
if ( V_13 -> V_22 & V_24 )
V_14 |= V_18 ;
F_5 ( V_14 , V_2 -> V_9 + V_15 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
static const unsigned short V_25 [] = {
V_26 , V_27 ,
V_28 , V_29 } ;
static const unsigned short V_30 [] = {
V_31 , V_32 ,
V_33 , V_34 } ;
static const unsigned short V_35 [] = {
V_36 , V_37 ,
V_38 , V_39 } ;
F_5 ( F_9 ( V_2 -> V_40 . V_41 . V_42 ) ,
V_2 -> V_9 + V_43 ) ;
F_5 ( F_10 ( V_2 -> V_40 . V_41 . V_42 ) ,
V_2 -> V_9 + V_25 [ 0 ] ) ;
F_5 ( V_2 -> V_40 . V_41 . V_44 & V_45 ,
V_2 -> V_9 + V_46 ) ;
F_5 ( F_9 ( V_2 -> V_47 . V_48 . V_42 ) ,
V_2 -> V_9 + V_49 ) ;
F_5 ( F_10 ( V_2 -> V_47 . V_48 . V_42 ) ,
V_2 -> V_9 + V_30 [ 0 ] ) ;
F_5 ( F_10 ( V_2 -> V_47 . V_50 . V_42 ) ,
V_2 -> V_9 + V_35 [ 0 ] ) ;
F_5 ( V_2 -> V_47 . V_48 . V_44 & V_51 ,
V_2 -> V_9 + V_52 ) ;
F_5 ( V_2 -> V_47 . V_50 . V_44 & V_53 ,
V_2 -> V_9 + V_54 ) ;
F_5 ( V_2 -> V_55 & V_56 ,
V_2 -> V_9 + V_57 ) ;
F_5 ( 0 , V_2 -> V_9 + V_58 ) ;
F_5 ( 1 , V_2 -> V_9 + V_59 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_2 V_60 ;
F_5 ( ( V_61 >> 3 ) &
V_62 , V_2 -> V_9 + V_63 ) ;
V_60 = ( V_2 -> V_64 << V_65 ) &
V_66 ;
V_60 |= V_67 | V_68 ;
V_60 |= ( 0x0100 << V_69 ) &
V_70 ;
F_5 ( V_60 , V_2 -> V_9 + V_71 ) ;
F_12 ( V_2 -> V_9 + V_72 ,
( V_73 | V_74 ) , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_60 ;
V_60 = ( V_2 -> V_75 << V_76 ) &
V_77 ;
V_60 |= ( V_78 | V_79 ) ;
F_5 ( V_60 , V_2 -> V_9 + V_80 ) ;
V_60 = F_3 ( V_2 -> V_9 + V_81 ) ;
V_60 &= ~ ( V_82 | V_83 |
V_84 ) ;
V_60 |= ( V_85 << V_86 ) |
( V_87 << V_88 ) |
( V_89 << V_90 ) ;
F_5 ( V_60 , V_2 -> V_9 + V_81 ) ;
V_60 = F_3 ( V_2 -> V_9 + V_91 ) ;
V_60 &= ~ ( V_92 | V_93 ) ;
V_60 |= ( V_94 << V_95 ) |
( V_96 << V_97 ) ;
F_5 ( V_60 , V_2 -> V_9 + V_91 ) ;
V_60 = F_3 ( V_2 -> V_9 + V_98 ) ;
V_60 &= ~ ( V_99 | V_100 ) ;
V_60 |= V_101 << V_102 ;
F_5 ( V_60 , V_2 -> V_9 + V_98 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_2 V_103 = V_104 ;
switch ( V_2 -> V_105 ) {
case V_106 :
V_103 |= V_107 ;
break;
case V_108 :
V_103 |= V_109 ;
break;
case V_110 :
V_103 |= V_111 ;
break;
default:
break;
}
V_103 |= ( ( ( T_2 ) V_2 -> V_112 ) << V_113 ) &
V_114 ;
V_103 |= ( ( ( T_2 ) V_2 -> V_115 ) << V_116 ) &
V_117 ;
V_103 |= ( ( ( T_2 ) V_2 -> V_118 ) << V_119 ) &
V_120 ;
V_103 |= ( ( ( T_2 ) V_2 -> V_121 ) << V_122 ) &
V_123 ;
F_5 ( V_103 , V_2 -> V_9 + V_124 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_125 ;
V_125 = ( ( ( T_2 ) V_3 [ 2 ] ) << 24 ) | ( ( ( T_2 ) V_3 [ 3 ] ) << 16 ) |
( ( ( T_2 ) V_3 [ 4 ] ) << 8 ) | ( ( ( T_2 ) V_3 [ 5 ] ) ) ;
F_5 ( V_125 , V_2 -> V_9 + V_126 ) ;
V_125 = ( ( ( T_2 ) V_3 [ 0 ] ) << 8 ) | ( T_2 ) V_3 [ 1 ] ;
F_5 ( V_125 , V_2 -> V_9 + V_127 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_128 ;
T_2 V_60 ;
F_15 ( V_2 , V_13 -> V_129 ) ;
V_128 = V_13 -> V_130 + V_131 + V_132 + V_133 ;
V_2 -> V_55 = V_13 -> V_130 > V_134 ?
F_17 ( V_128 , 8 ) : V_134 ;
F_8 ( V_2 ) ;
F_5 ( V_13 -> V_130 + V_131 + V_133 + V_132 ,
V_2 -> V_9 + V_135 ) ;
F_11 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_60 = F_3 ( V_2 -> V_9 + V_136 ) ;
V_60 &= ~ ( V_137 | V_138 ) ;
V_60 |= V_139 ;
F_5 ( V_60 , V_2 -> V_9 + V_136 ) ;
F_5 ( 0 , V_2 -> V_9 + V_140 ) ;
F_5 ( V_141 , V_2 -> V_9 + V_142 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_12 ( V_2 -> V_9 + V_143 , 0 , V_144 ) ;
F_20 ( 100 , 150 ) ;
F_12 ( V_2 -> V_9 + V_143 , 0 , V_145 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_146 * V_147 = V_2 -> V_147 ;
T_2 V_14 , V_148 ;
F_12 ( V_2 -> V_9 + V_71 , 0 , V_149 ) ;
F_12 ( V_2 -> V_9 + V_80 , 0 , V_150 ) ;
V_14 = F_3 ( V_2 -> V_9 + V_15 ) ;
V_148 = F_3 ( V_2 -> V_151 + V_152 ) ;
V_14 |= V_153 | V_154 ;
V_14 &= ~ ( V_155 | V_156 ) ;
if ( V_2 -> V_157 ) {
V_2 -> V_158 = V_147 -> V_159 ;
V_2 -> V_160 = V_147 -> V_159 != V_147 -> V_161 ;
}
V_14 |= V_2 -> V_158 ? V_155 : 0 ;
V_14 |= V_2 -> V_160 ? V_156 : 0 ;
V_14 &= ~ V_162 ;
if ( V_147 -> V_163 == V_164 ) {
V_14 |= F_22 ( 2 ) ;
V_148 |= V_165 ;
} else {
V_14 |= F_22 ( 1 ) ;
V_148 &= ~ V_165 ;
}
if ( V_147 -> V_166 == V_167 )
V_14 |= V_168 ;
else
V_14 &= ~ V_168 ;
V_14 |= ( V_169 | V_170 ) ;
V_14 |= ( ( V_2 -> V_171 << V_172 ) & V_173 ) ;
V_14 |= V_174 ;
V_14 |= V_175 ;
V_14 &= ~ V_176 ;
V_14 &= ~ ( V_177 | V_16 | V_178 | V_179 | V_180 | V_18 |
V_181 | V_182 ) ;
F_23 ( V_148 , V_2 -> V_151 + V_152 ) ;
F_23 ( V_14 , V_2 -> V_9 + V_15 ) ;
F_23 ( V_2 -> V_183 , V_2 -> V_9 + V_184 ) ;
F_23 ( V_145 | V_185 | V_186 |
V_187 , V_2 -> V_9 + V_143 ) ;
F_7 ( V_2 ) ;
F_12 ( V_2 -> V_9 + V_188 ,
( V_189 | V_190 ) , 0 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_9 + V_80 , V_150 , 0 ) ;
F_12 ( V_2 -> V_9 + V_71 , V_149 , 0 ) ;
F_12 ( V_2 -> V_9 + V_15 , V_153 | V_154 , 0 ) ;
F_20 ( 1000 , 1050 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_191 * V_40 = & V_2 -> V_40 ;
unsigned int V_192 ;
T_3 V_193 ;
if ( ! V_40 -> V_41 . V_194 )
return;
for ( V_192 = 0 ; V_192 < V_40 -> V_41 . V_44 ; V_192 ++ ) {
struct V_195 * V_196 = F_25 ( V_40 , V_192 ) ;
if ( V_196 -> V_42 ) {
F_26 ( V_2 -> V_13 -> V_197 . V_198 ,
V_196 -> V_42 , V_196 -> V_199 ,
V_200 ) ;
V_196 -> V_42 = 0 ;
}
if ( V_196 -> V_201 ) {
F_27 ( V_196 -> V_201 ) ;
V_196 -> V_201 = NULL ;
}
}
V_193 = sizeof( struct V_195 ) * V_40 -> V_41 . V_44 ;
memset ( V_40 -> V_41 . V_194 , 0 , V_193 ) ;
memset ( V_40 -> V_41 . V_202 , 0 , V_40 -> V_41 . V_193 ) ;
V_40 -> V_41 . V_203 = 0 ;
V_40 -> V_41 . V_204 = 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_205 * V_197 = V_2 -> V_13 -> V_197 . V_198 ;
struct V_206 * V_47 = & V_2 -> V_47 ;
unsigned int V_192 ;
T_3 V_193 ;
if ( ! V_47 -> V_48 . V_207 )
return;
for ( V_192 = 0 ; V_192 < V_47 -> V_48 . V_44 ; V_192 ++ ) {
struct V_195 * V_208 = F_29 ( V_47 , V_192 ) ;
if ( V_208 -> V_42 ) {
F_26 ( V_197 , V_208 -> V_42 , V_208 -> V_199 ,
V_209 ) ;
V_208 -> V_42 = 0 ;
}
if ( V_208 -> V_201 ) {
F_30 ( V_208 -> V_201 ) ;
V_208 -> V_201 = NULL ;
}
}
V_193 = sizeof( struct V_195 ) * V_47 -> V_48 . V_44 ;
memset ( V_47 -> V_48 . V_207 , 0 , V_193 ) ;
memset ( V_47 -> V_50 . V_202 , 0 , V_47 -> V_50 . V_193 ) ;
V_47 -> V_50 . V_204 = 0 ;
V_47 -> V_50 . V_203 = 0 ;
memset ( V_47 -> V_48 . V_202 , 0 , V_47 -> V_48 . V_193 ) ;
V_47 -> V_48 . V_204 = 0 ;
V_47 -> V_48 . V_203 = 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_191 * V_40 = & V_2 -> V_40 ;
F_24 ( V_2 ) ;
F_32 ( V_40 -> V_41 . V_194 ) ;
V_40 -> V_41 . V_194 = NULL ;
V_40 -> V_41 . V_202 = NULL ;
V_40 -> V_41 . V_42 = 0 ;
V_40 -> V_41 . V_193 = 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_191 * V_40 )
{
struct V_210 * V_211 = & V_2 -> V_211 ;
T_3 V_193 ;
V_193 = sizeof( struct V_195 ) * V_40 -> V_41 . V_44 ;
V_40 -> V_41 . V_194 = F_34 ( V_193 , V_212 ) ;
if ( ! V_40 -> V_41 . V_194 )
return - V_213 ;
V_40 -> V_41 . V_193 = V_40 -> V_41 . V_44 * ( V_2 -> V_214 * 4 ) ;
V_40 -> V_41 . V_42 = V_211 -> V_42 + V_211 -> V_215 ;
V_40 -> V_41 . V_202 = V_211 -> V_202 + V_211 -> V_215 ;
V_211 -> V_215 += F_17 ( V_40 -> V_41 . V_193 , 8 ) ;
V_40 -> V_41 . V_204 = 0 ;
V_40 -> V_41 . V_203 = 0 ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_206 * V_47 = & V_2 -> V_47 ;
F_28 ( V_2 ) ;
F_32 ( V_47 -> V_48 . V_207 ) ;
V_47 -> V_48 . V_207 = NULL ;
V_47 -> V_48 . V_202 = NULL ;
V_47 -> V_48 . V_42 = 0 ;
V_47 -> V_48 . V_193 = 0 ;
V_47 -> V_50 . V_202 = NULL ;
V_47 -> V_50 . V_42 = 0 ;
V_47 -> V_50 . V_193 = 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_210 * V_211 = & V_2 -> V_211 ;
struct V_206 * V_47 = & V_2 -> V_47 ;
T_3 V_193 ;
V_193 = sizeof( struct V_195 ) * V_47 -> V_48 . V_44 ;
V_47 -> V_48 . V_207 = F_34 ( V_193 , V_212 ) ;
if ( ! V_47 -> V_48 . V_207 )
return - V_213 ;
V_47 -> V_50 . V_193 = V_47 -> V_50 . V_44 * ( V_2 -> V_216 * 4 ) ;
V_47 -> V_48 . V_193 = V_47 -> V_48 . V_44 * ( V_2 -> V_217 * 4 ) ;
V_47 -> V_50 . V_42 = V_211 -> V_42 + V_211 -> V_215 ;
V_47 -> V_50 . V_202 = V_211 -> V_202 + V_211 -> V_215 ;
V_211 -> V_215 += F_17 ( V_47 -> V_50 . V_193 , 8 ) ;
V_47 -> V_48 . V_42 = V_211 -> V_42 + V_211 -> V_215 ;
V_47 -> V_48 . V_202 = V_211 -> V_202 + V_211 -> V_215 ;
V_211 -> V_215 += F_17 ( V_47 -> V_48 . V_193 , 8 ) ;
V_47 -> V_50 . V_204 = 0 ;
V_47 -> V_50 . V_203 = 0 ;
V_47 -> V_48 . V_204 = 0 ;
V_47 -> V_48 . V_203 = 0 ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_210 * V_211 = & V_2 -> V_211 ;
struct V_205 * V_197 = V_2 -> V_13 -> V_197 . V_198 ;
unsigned int V_218 = V_2 -> V_219 ;
unsigned int V_220 = V_2 -> V_221 ;
int V_222 ;
V_2 -> V_40 . V_41 . V_44 = V_2 -> V_219 ;
V_2 -> V_47 . V_50 . V_44 = V_2 -> V_221 ;
V_2 -> V_47 . V_48 . V_44 = V_2 -> V_221 ;
V_211 -> V_193 = V_218 * ( V_2 -> V_214 * 4 ) +
V_220 * ( V_2 -> V_217 * 4 ) +
V_220 * ( V_2 -> V_216 * 4 ) +
8 + 2 * 8 ;
V_211 -> V_215 = 0 ;
V_211 -> V_202 = F_38 ( V_197 , V_211 -> V_193 ,
& V_211 -> V_42 ,
V_212 ) ;
if ( ! V_211 -> V_202 )
return - V_213 ;
V_211 -> V_215 = F_17 ( V_211 -> V_42 , 8 ) -
V_211 -> V_42 ;
V_222 = F_33 ( V_2 , & V_2 -> V_40 ) ;
if ( V_222 ) {
F_39 ( V_2 -> V_13 , L_1 ) ;
goto V_223;
}
V_222 = F_36 ( V_2 ) ;
if ( V_222 ) {
F_39 ( V_2 -> V_13 , L_2 ) ;
goto V_224;
}
return 0 ;
V_224:
F_31 ( V_2 ) ;
V_223:
F_40 ( V_197 , V_211 -> V_193 ,
V_211 -> V_202 , V_211 -> V_42 ) ;
V_211 -> V_202 = NULL ;
V_211 -> V_42 = 0 ;
V_211 -> V_193 = 0 ;
V_211 -> V_215 = 0 ;
return V_222 ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_210 * V_211 = & V_2 -> V_211 ;
struct V_205 * V_197 = V_2 -> V_13 -> V_197 . V_198 ;
F_31 ( V_2 ) ;
F_35 ( V_2 ) ;
F_40 ( V_197 , V_211 -> V_193 ,
V_211 -> V_202 , V_211 -> V_42 ) ;
V_211 -> V_202 = NULL ;
V_211 -> V_42 = 0 ;
V_211 -> V_193 = 0 ;
V_211 -> V_215 = 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned int V_192 ;
V_2 -> V_40 . V_41 . V_204 = 0 ;
V_2 -> V_40 . V_41 . V_203 = 0 ;
for ( V_192 = 0 ; V_192 < V_2 -> V_40 . V_41 . V_44 ; V_192 ++ )
V_2 -> V_40 . V_41 . V_194 [ V_192 ] . V_42 = 0 ;
V_2 -> V_47 . V_50 . V_204 = 0 ;
V_2 -> V_47 . V_50 . V_203 = 0 ;
V_2 -> V_47 . V_48 . V_204 = 0 ;
V_2 -> V_47 . V_48 . V_203 = 0 ;
for ( V_192 = 0 ; V_192 < V_2 -> V_47 . V_48 . V_44 ; V_192 ++ )
V_2 -> V_47 . V_48 . V_207 [ V_192 ] . V_42 = 0 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_206 * V_47 ,
T_4 V_3 )
{
T_2 * V_225 = F_44 ( V_47 , V_2 -> V_217 , V_47 -> V_48 . V_204 ) ;
* ( V_225 ++ ) = F_10 ( V_3 ) ;
* V_225 = F_9 ( V_3 ) ;
if ( ++ V_47 -> V_48 . V_204 == V_47 -> V_48 . V_44 )
V_47 -> V_48 . V_204 = 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_206 * V_47 )
{
struct V_195 * V_226 ;
struct V_195 * V_227 ;
unsigned int V_44 = 0 ;
T_2 V_228 ;
V_228 = V_47 -> V_48 . V_204 + 1 ;
if ( V_228 == V_47 -> V_48 . V_44 )
V_228 = 0 ;
V_226 = F_29 ( V_47 , V_47 -> V_48 . V_204 ) ;
V_227 = F_29 ( V_47 , V_228 ) ;
while ( ! V_227 -> V_42 ) {
struct V_229 * V_201 ;
int V_222 ;
V_201 = F_46 ( V_2 -> V_13 , V_2 -> V_55 ) ;
if ( ! V_201 )
break;
V_226 -> V_42 =
F_47 ( V_2 -> V_13 -> V_197 . V_198 , V_201 -> V_230 ,
V_226 -> V_199 , V_209 ) ;
V_222 = F_48 ( V_2 -> V_13 -> V_197 . V_198 ,
V_226 -> V_42 ) ;
if ( V_222 ) {
F_30 ( V_201 ) ;
break;
}
V_226 -> V_201 = V_201 ;
V_226 -> V_199 = V_2 -> V_55 ;
F_43 ( V_2 , V_47 , V_226 -> V_42 ) ;
V_228 = V_47 -> V_48 . V_204 + 1 ;
if ( V_228 == V_47 -> V_48 . V_44 )
V_228 = 0 ;
V_226 = F_29 ( V_47 , V_47 -> V_48 . V_204 ) ;
V_227 = F_29 ( V_47 , V_228 ) ;
V_44 ++ ;
}
if ( V_44 ) {
T_2 V_231 = ( V_47 -> V_48 . V_204 << V_47 -> V_232 ) &
V_47 -> V_233 ;
F_12 ( V_2 -> V_9 + V_47 -> V_234 ,
V_47 -> V_233 , V_231 ) ;
}
}
static void F_49 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_50 ( V_13 ) ;
struct V_235 * V_236 = & V_2 -> V_237 ;
struct V_146 * V_147 = V_13 -> V_147 ;
if ( V_147 -> V_238 ) {
F_21 ( V_2 ) ;
V_236 -> V_239 ( V_2 ) ;
} else {
V_236 -> V_240 ( V_2 ) ;
F_19 ( V_2 ) ;
}
F_51 ( V_147 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_222 ;
F_42 ( V_2 ) ;
F_16 ( V_2 ) ;
F_45 ( V_2 , & V_2 -> V_47 ) ;
V_2 -> V_147 -> V_241 = V_242 ;
V_222 = F_53 ( V_13 , V_2 -> V_147 , F_49 ,
V_243 ) ;
if ( V_222 ) {
F_39 ( V_2 -> V_13 , L_3 ) ;
return V_222 ;
}
F_54 ( V_2 -> V_147 , NULL ) ;
F_5 ( ( T_2 ) ~ V_244 , V_2 -> V_9 + V_245 ) ;
F_5 ( V_2 -> V_241 . V_246 , V_2 -> V_9 + V_247 ) ;
F_55 ( V_2 -> V_147 ) ;
F_56 ( & V_2 -> V_47 . V_248 ) ;
F_57 ( V_13 ) ;
return 0 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_59 ( V_13 ) ;
F_60 ( & V_2 -> V_47 . V_248 ) ;
F_61 ( V_2 -> V_147 ) ;
F_5 ( V_244 , V_2 -> V_9 + V_245 ) ;
F_5 ( 0 , V_2 -> V_9 + V_247 ) ;
F_62 ( V_2 -> V_241 . V_241 ) ;
F_63 ( V_2 -> V_147 ) ;
F_18 ( V_2 ) ;
F_24 ( V_2 ) ;
F_64 ( V_2 -> V_13 ) ;
F_28 ( V_2 ) ;
}
static bool F_65 ( struct V_1 * V_2 ,
struct V_206 * V_47 ,
struct V_249 * V_50 )
{
T_2 * V_250 = F_66 ( V_47 , V_2 -> V_216 , V_47 -> V_50 . V_203 ) ;
V_50 -> V_251 [ 3 ] = * ( V_250 + 3 ) ;
if ( ! F_67 ( V_50 ) )
return false ;
V_50 -> V_251 [ 4 ] = 0 ;
V_50 -> V_251 [ 5 ] = 0 ;
V_50 -> V_251 [ 0 ] = * ( V_250 ++ ) ;
V_50 -> V_251 [ 1 ] = * ( V_250 ++ ) ;
V_50 -> V_251 [ 2 ] = * ( V_250 ++ ) ;
if ( F_68 ( F_69 ( V_50 ) != 1 ) ) {
F_39 ( V_2 -> V_13 ,
L_4 ,
F_69 ( V_50 ) ) ;
}
F_70 ( V_50 , 0 ) ;
* V_250 = V_50 -> V_251 [ 3 ] ;
if ( ++ V_47 -> V_50 . V_203 == V_47 -> V_50 . V_44 )
V_47 -> V_50 . V_203 = 0 ;
return true ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_191 * V_40 , struct V_252 * V_41 )
{
T_2 * V_253 ;
V_40 -> V_41 . V_254 = V_40 -> V_41 . V_204 ;
V_253 = F_72 ( V_40 , V_2 -> V_214 , V_40 -> V_41 . V_204 ) ;
if ( ++ V_40 -> V_41 . V_204 == V_40 -> V_41 . V_44 )
V_40 -> V_41 . V_204 = 0 ;
* ( V_253 ++ ) = V_41 -> V_251 [ 0 ] ;
* ( V_253 ++ ) = V_41 -> V_251 [ 1 ] ;
* ( V_253 ++ ) = V_41 -> V_251 [ 2 ] ;
* V_253 = V_41 -> V_251 [ 3 ] ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_191 * V_40 )
{
T_2 * V_253 =
F_72 ( V_40 , V_2 -> V_214 , V_40 -> V_41 . V_254 ) ;
T_2 V_255 ;
V_255 = * ( V_253 + 1 ) ;
V_255 |= V_256 ;
* ( V_253 + 1 ) = V_255 ;
}
static void F_74 ( struct V_206 * V_47 , struct V_249 * V_50 )
{
struct V_195 * V_208 = V_47 -> V_48 . V_207 ;
T_2 V_203 = F_75 ( V_50 ) ;
unsigned int V_192 ;
for ( V_192 = 0 ; V_192 < F_69 ( V_50 ) ; V_192 ++ ) {
V_208 [ V_203 ] . V_201 = NULL ;
if ( ++ V_203 == V_47 -> V_48 . V_44 )
V_203 = 0 ;
}
V_47 -> V_48 . V_203 = V_203 ;
V_47 -> V_48 . V_257 = V_203 ;
}
static void F_76 ( struct V_206 * V_47 ,
struct V_229 * V_201 ,
T_5 V_258 , bool V_259 )
{
if ( V_259 ) {
T_5 V_260 ;
F_77 ( V_258 , V_260 ) ;
F_78 ( V_201 , F_79 ( V_261 ) , V_260 ) ;
}
F_80 ( & V_47 -> V_248 , V_201 ) ;
}
void F_81 ( struct V_1 * V_2 , struct V_206 * V_47 ,
int * V_262 , int V_263 )
{
T_2 V_264 , V_265 , V_266 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_195 * V_208 ;
unsigned int V_44 = 0 ;
struct V_249 V_50 ;
struct V_229 * V_201 ;
T_2 V_6 ;
V_6 = F_82 ( V_2 -> V_9 + V_47 -> V_267 ) ;
V_265 = ( V_6 & V_47 -> V_268 ) >> V_47 -> V_269 ;
V_266 = ( V_265 >= V_47 -> V_50 . V_203 ) ?
( V_265 - V_47 -> V_50 . V_203 ) :
( V_265 + V_47 -> V_50 . V_44 - V_47 -> V_50 . V_203 ) ;
do {
if ( ! V_266 )
break;
if ( ! F_65 ( V_2 , V_47 , & V_50 ) )
break;
if ( F_83 ( F_69 ( & V_50 ) == 1 ) ) {
V_208 = F_29 ( V_47 , F_75 ( & V_50 ) ) ;
F_26 ( V_2 -> V_13 -> V_197 . V_198 ,
V_208 -> V_42 , V_208 -> V_199 ,
V_209 ) ;
V_208 -> V_42 = 0 ;
V_201 = V_208 -> V_201 ;
} else {
F_39 ( V_2 -> V_13 ,
L_5 ) ;
break;
}
F_74 ( V_47 , & V_50 ) ;
V_266 -- ;
V_44 ++ ;
if ( V_50 . V_251 [ V_270 ] & V_271 ) {
F_84 ( V_2 , V_272 , V_2 -> V_13 ,
L_6 ,
V_50 . V_251 [ 0 ] , V_50 . V_251 [ 1 ] ,
V_50 . V_251 [ 2 ] , V_50 . V_251 [ 3 ] ) ;
F_30 ( V_201 ) ;
continue;
}
F_85 ( V_201 , F_86 ( & V_50 ) - V_132 ) ;
V_201 -> V_197 = V_13 ;
V_201 -> V_273 = F_87 ( V_201 , V_201 -> V_197 ) ;
if ( V_13 -> V_20 & V_274 )
V_201 -> V_275 = F_88 ( & V_50 ) ?
V_276 : V_277 ;
else
F_89 ( V_201 ) ;
F_76 ( V_47 , V_201 , ( T_5 ) F_90 ( & V_50 ) ,
( bool ) F_91 ( & V_50 ) ) ;
( * V_262 ) ++ ;
} while ( * V_262 < V_263 );
if ( V_44 ) {
V_264 = ( V_47 -> V_48 . V_257 << V_47 -> V_278 ) &
V_47 -> V_279 ;
F_12 ( V_2 -> V_9 + V_47 -> V_280 ,
V_47 -> V_279 , V_264 ) ;
F_45 ( V_2 , V_47 ) ;
}
}
static unsigned int F_92 ( struct V_191 * V_40 )
{
T_2 V_204 = V_40 -> V_41 . V_204 ;
T_2 V_203 = V_40 -> V_41 . V_203 ;
return ( V_203 > V_204 ) ?
( V_203 - V_204 - 1 ) :
( V_40 -> V_41 . V_44 + V_203 - V_204 - 1 ) ;
}
void F_93 ( struct V_1 * V_2 , struct V_191 * V_40 )
{
T_2 V_6 = F_82 ( V_2 -> V_9 + V_40 -> V_267 ) ;
T_2 V_265 , V_281 = 0 , V_282 = 0 ;
struct V_195 * V_196 ;
V_265 = ( V_6 & V_40 -> V_268 ) >> V_40 -> V_269 ;
while ( V_40 -> V_41 . V_203 != V_265 ) {
V_196 = F_25 ( V_40 , V_40 -> V_41 . V_203 ) ;
if ( V_196 -> V_42 ) {
F_26 ( V_2 -> V_13 -> V_197 . V_198 ,
V_196 -> V_42 , V_196 -> V_199 ,
V_200 ) ;
V_196 -> V_42 = 0 ;
}
if ( V_196 -> V_201 ) {
V_281 ++ ;
V_282 += V_196 -> V_201 -> V_283 ;
F_94 ( V_196 -> V_201 ) ;
V_196 -> V_201 = NULL ;
}
if ( ++ V_40 -> V_41 . V_203 == V_40 -> V_41 . V_44 )
V_40 -> V_41 . V_203 = 0 ;
}
F_95 ( V_2 -> V_13 , V_281 , V_282 ) ;
if ( F_96 ( V_2 -> V_13 ) )
if ( F_92 ( V_40 ) > ( V_284 + 1 ) )
F_97 ( V_2 -> V_13 ) ;
}
void F_98 ( struct V_285 * V_286 ,
struct V_1 * V_2 )
{
V_2 -> V_47 . V_13 = V_2 -> V_13 ;
V_2 -> V_47 . V_234 = V_287 ;
V_2 -> V_47 . V_233 = V_288 ;
V_2 -> V_47 . V_232 = V_289 ;
V_2 -> V_47 . V_280 = V_287 ;
V_2 -> V_47 . V_279 = V_290 ;
V_2 -> V_47 . V_278 = V_291 ;
V_2 -> V_47 . V_267 = V_292 ;
V_2 -> V_47 . V_268 = V_293 ;
V_2 -> V_47 . V_269 = V_294 ;
V_2 -> V_47 . V_241 = & V_2 -> V_241 ;
V_2 -> V_47 . V_295 = V_2 -> V_241 . V_246 & V_296 ;
V_2 -> V_40 . V_234 = V_297 ;
V_2 -> V_40 . V_233 = V_298 ;
V_2 -> V_40 . V_232 = V_299 ;
V_2 -> V_40 . V_267 = V_300 ;
V_2 -> V_40 . V_268 = V_301 ;
V_2 -> V_40 . V_269 = V_302 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_191 * V_40 ,
struct V_229 * V_201 ,
struct V_252 * V_41 )
{
unsigned int V_303 ;
int V_222 ;
if ( F_100 ( V_201 ) ) {
if ( F_101 ( V_201 ) ) {
V_222 = F_102 ( V_201 , 0 , 0 , V_304 ) ;
if ( F_68 ( V_222 ) )
return V_222 ;
}
if ( V_201 -> V_273 == F_79 ( V_305 ) ) {
T_2 V_306 = ( ( unsigned char * ) F_103 ( V_201 ) - V_201 -> V_230 )
+ F_104 ( F_103 ( V_201 ) -> V_307 ) ;
if ( V_201 -> V_283 > V_306 )
F_105 ( V_201 , V_306 ) ;
}
V_303 = F_106 ( V_201 ) + F_107 ( V_201 ) ;
if ( F_68 ( V_201 -> V_283 == V_303 ) ) {
F_108 ( V_2 , V_308 , V_2 -> V_13 ,
L_7 ) ;
goto V_309;
}
if ( F_109 ( V_201 ) -> V_310 & V_311 ) {
F_103 ( V_201 ) -> V_312 = 0 ;
F_110 ( V_201 ) -> V_312 =
~ F_111 ( F_103 ( V_201 ) -> V_313 ,
F_103 ( V_201 ) -> V_314 ,
0 , V_315 , 0 ) ;
F_112 ( V_41 , 1 ) ;
}
if ( F_109 ( V_201 ) -> V_310 & V_316 ) {
struct V_252 V_317 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
F_113 ( V_201 ) -> V_318 = 0 ;
F_110 ( V_201 ) -> V_312 =
~ F_114 ( & F_113 ( V_201 ) -> V_313 ,
& F_113 ( V_201 ) -> V_314 ,
0 , V_315 , 0 ) ;
F_115 ( & V_317 , V_201 -> V_283 ) ;
F_116 ( & V_317 , 1 ) ;
F_117 ( & V_317 , 1 ) ;
F_71 ( V_2 , V_40 , & V_317 ) ;
F_117 ( V_41 , 1 ) ;
}
F_116 ( V_41 , 1 ) ;
F_118 ( V_41 , F_106 ( V_201 ) ) ;
F_119 ( V_41 , F_109 ( V_201 ) -> V_319 ) ;
return 0 ;
}
V_309:
if ( F_83 ( V_201 -> V_275 == V_320 ) ) {
unsigned int V_321 , V_322 ;
V_322 = F_106 ( V_201 ) ;
if ( F_68 ( V_322 & 0x1 ) ) {
F_39 ( V_2 -> V_13 ,
L_8 ) ;
return - V_323 ;
}
V_321 = V_322 + V_201 -> V_324 ;
F_120 ( V_41 , V_322 >> 1 ) ;
F_121 ( V_41 , V_321 >> 1 ) ;
F_122 ( V_41 , 1 ) ;
}
return 0 ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_191 * V_40 , struct V_229 * V_201 ,
struct V_252 * V_41 )
{
unsigned int V_325 = F_109 ( V_201 ) -> V_325 ;
unsigned int V_326 = V_40 -> V_41 . V_204 ;
unsigned int V_283 = F_124 ( V_201 ) ;
struct V_195 * V_196 = NULL ;
unsigned int V_327 = 0 ;
unsigned int V_192 ;
int V_44 = 0 ;
int V_222 ;
if ( F_125 ( V_41 ) ) {
V_327 = F_106 ( V_201 ) + F_107 ( V_201 ) ;
V_196 = F_25 ( V_40 , V_40 -> V_41 . V_204 ) ;
V_196 -> V_199 = V_327 ;
V_196 -> V_42 = F_47 ( V_2 -> V_13 -> V_197 . V_198 ,
V_201 -> V_230 , V_196 -> V_199 ,
V_200 ) ;
V_222 = F_48 ( V_2 -> V_13 -> V_197 . V_198 ,
V_196 -> V_42 ) ;
if ( V_222 )
goto error;
F_126 ( V_41 , F_10 ( V_196 -> V_42 ) ) ;
F_127 ( V_41 , F_9 ( V_196 -> V_42 ) ) ;
F_128 ( V_41 , V_196 -> V_199 ) ;
F_71 ( V_2 , V_40 , V_41 ) ;
V_44 ++ ;
}
if ( V_327 < V_283 ) {
V_196 = F_25 ( V_40 , V_40 -> V_41 . V_204 ) ;
V_196 -> V_199 = V_283 - V_327 ;
V_196 -> V_42 = F_47 ( V_2 -> V_13 -> V_197 . V_198 ,
V_201 -> V_230 + V_327 ,
V_196 -> V_199 , V_200 ) ;
V_222 = F_48 ( V_2 -> V_13 -> V_197 . V_198 ,
V_196 -> V_42 ) ;
if ( V_222 )
goto error;
F_126 ( V_41 , F_10 ( V_196 -> V_42 ) ) ;
F_127 ( V_41 , F_9 ( V_196 -> V_42 ) ) ;
F_128 ( V_41 , V_196 -> V_199 ) ;
F_71 ( V_2 , V_40 , V_41 ) ;
V_44 ++ ;
}
for ( V_192 = 0 ; V_192 < V_325 ; V_192 ++ ) {
struct V_328 * V_329 ;
V_329 = & F_109 ( V_201 ) -> V_330 [ V_192 ] ;
V_196 = F_25 ( V_40 , V_40 -> V_41 . V_204 ) ;
V_196 -> V_199 = V_329 -> V_193 ;
V_196 -> V_42 = F_129 ( V_2 -> V_13 -> V_197 . V_198 ,
V_329 -> V_331 . V_332 , V_329 -> V_333 ,
V_196 -> V_199 , V_200 ) ;
V_222 = F_48 ( V_2 -> V_13 -> V_197 . V_198 ,
V_196 -> V_42 ) ;
if ( V_222 )
goto error;
F_126 ( V_41 , F_10 ( V_196 -> V_42 ) ) ;
F_127 ( V_41 , F_9 ( V_196 -> V_42 ) ) ;
F_128 ( V_41 , V_196 -> V_199 ) ;
F_71 ( V_2 , V_40 , V_41 ) ;
V_44 ++ ;
}
F_130 () ;
F_73 ( V_2 , V_40 ) ;
V_196 -> V_201 = V_201 ;
return;
error:
V_40 -> V_41 . V_204 = V_326 ;
while ( V_44 -- ) {
V_196 = F_25 ( V_40 , V_326 ) ;
F_131 ( V_2 -> V_13 -> V_197 . V_198 , V_196 -> V_42 ,
V_196 -> V_199 , V_200 ) ;
V_196 -> V_42 = 0 ;
V_196 -> V_199 = 0 ;
if ( ++ V_326 == V_40 -> V_41 . V_44 )
V_326 = 0 ;
}
F_30 ( V_201 ) ;
}
int F_132 ( struct V_1 * V_2 , struct V_191 * V_40 ,
struct V_229 * V_201 )
{
struct V_252 V_41 ;
T_2 V_231 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
if ( F_99 ( V_2 , V_40 , V_201 , & V_41 ) != 0 ) {
F_27 ( V_201 ) ;
return V_334 ;
}
if ( F_133 ( V_201 ) ) {
T_5 V_335 ;
F_134 ( F_135 ( V_201 ) , V_335 ) ;
F_136 ( & V_41 , V_335 ) ;
F_137 ( & V_41 , 1 ) ;
}
if ( F_138 ( V_201 ) != V_131 )
F_139 ( & V_41 , 1 ) ;
F_123 ( V_2 , V_40 , V_201 , & V_41 ) ;
F_140 ( V_2 -> V_13 , V_201 -> V_283 ) ;
if ( F_92 ( V_40 ) < ( V_284 + 3 ) )
F_59 ( V_2 -> V_13 ) ;
V_231 = ( V_40 -> V_41 . V_204 << V_40 -> V_232 ) &
V_40 -> V_233 ;
F_12 ( V_2 -> V_9 + V_40 -> V_234 ,
V_40 -> V_233 , V_231 ) ;
return V_334 ;
}
