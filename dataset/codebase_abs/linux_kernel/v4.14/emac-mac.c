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
V_14 |= V_2 -> V_183 ? V_182 : 0 ;
F_23 ( V_148 , V_2 -> V_151 + V_152 ) ;
F_23 ( V_14 , V_2 -> V_9 + V_15 ) ;
F_23 ( V_2 -> V_184 , V_2 -> V_9 + V_185 ) ;
F_23 ( V_145 | V_186 | V_187 |
V_188 , V_2 -> V_9 + V_143 ) ;
F_7 ( V_2 ) ;
F_12 ( V_2 -> V_9 + V_189 ,
( V_190 | V_191 ) , 0 ) ;
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
struct V_192 * V_40 = & V_2 -> V_40 ;
unsigned int V_193 ;
T_3 V_194 ;
if ( ! V_40 -> V_41 . V_195 )
return;
for ( V_193 = 0 ; V_193 < V_40 -> V_41 . V_44 ; V_193 ++ ) {
struct V_196 * V_197 = F_25 ( V_40 , V_193 ) ;
if ( V_197 -> V_42 ) {
F_26 ( V_2 -> V_13 -> V_198 . V_199 ,
V_197 -> V_42 , V_197 -> V_200 ,
V_201 ) ;
V_197 -> V_42 = 0 ;
}
if ( V_197 -> V_202 ) {
F_27 ( V_197 -> V_202 ) ;
V_197 -> V_202 = NULL ;
}
}
V_194 = sizeof( struct V_196 ) * V_40 -> V_41 . V_44 ;
memset ( V_40 -> V_41 . V_195 , 0 , V_194 ) ;
memset ( V_40 -> V_41 . V_203 , 0 , V_40 -> V_41 . V_194 ) ;
V_40 -> V_41 . V_204 = 0 ;
V_40 -> V_41 . V_205 = 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_206 * V_198 = V_2 -> V_13 -> V_198 . V_199 ;
struct V_207 * V_47 = & V_2 -> V_47 ;
unsigned int V_193 ;
T_3 V_194 ;
if ( ! V_47 -> V_48 . V_208 )
return;
for ( V_193 = 0 ; V_193 < V_47 -> V_48 . V_44 ; V_193 ++ ) {
struct V_196 * V_209 = F_29 ( V_47 , V_193 ) ;
if ( V_209 -> V_42 ) {
F_26 ( V_198 , V_209 -> V_42 , V_209 -> V_200 ,
V_210 ) ;
V_209 -> V_42 = 0 ;
}
if ( V_209 -> V_202 ) {
F_30 ( V_209 -> V_202 ) ;
V_209 -> V_202 = NULL ;
}
}
V_194 = sizeof( struct V_196 ) * V_47 -> V_48 . V_44 ;
memset ( V_47 -> V_48 . V_208 , 0 , V_194 ) ;
memset ( V_47 -> V_50 . V_203 , 0 , V_47 -> V_50 . V_194 ) ;
V_47 -> V_50 . V_205 = 0 ;
V_47 -> V_50 . V_204 = 0 ;
memset ( V_47 -> V_48 . V_203 , 0 , V_47 -> V_48 . V_194 ) ;
V_47 -> V_48 . V_205 = 0 ;
V_47 -> V_48 . V_204 = 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_192 * V_40 = & V_2 -> V_40 ;
F_24 ( V_2 ) ;
F_32 ( V_40 -> V_41 . V_195 ) ;
V_40 -> V_41 . V_195 = NULL ;
V_40 -> V_41 . V_203 = NULL ;
V_40 -> V_41 . V_42 = 0 ;
V_40 -> V_41 . V_194 = 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_192 * V_40 )
{
struct V_211 * V_212 = & V_2 -> V_212 ;
T_3 V_194 ;
V_194 = sizeof( struct V_196 ) * V_40 -> V_41 . V_44 ;
V_40 -> V_41 . V_195 = F_34 ( V_194 , V_213 ) ;
if ( ! V_40 -> V_41 . V_195 )
return - V_214 ;
V_40 -> V_41 . V_194 = V_40 -> V_41 . V_44 * ( V_2 -> V_215 * 4 ) ;
V_40 -> V_41 . V_42 = V_212 -> V_42 + V_212 -> V_216 ;
V_40 -> V_41 . V_203 = V_212 -> V_203 + V_212 -> V_216 ;
V_212 -> V_216 += F_17 ( V_40 -> V_41 . V_194 , 8 ) ;
V_40 -> V_41 . V_205 = 0 ;
V_40 -> V_41 . V_204 = 0 ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_207 * V_47 = & V_2 -> V_47 ;
F_28 ( V_2 ) ;
F_32 ( V_47 -> V_48 . V_208 ) ;
V_47 -> V_48 . V_208 = NULL ;
V_47 -> V_48 . V_203 = NULL ;
V_47 -> V_48 . V_42 = 0 ;
V_47 -> V_48 . V_194 = 0 ;
V_47 -> V_50 . V_203 = NULL ;
V_47 -> V_50 . V_42 = 0 ;
V_47 -> V_50 . V_194 = 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_211 * V_212 = & V_2 -> V_212 ;
struct V_207 * V_47 = & V_2 -> V_47 ;
T_3 V_194 ;
V_194 = sizeof( struct V_196 ) * V_47 -> V_48 . V_44 ;
V_47 -> V_48 . V_208 = F_34 ( V_194 , V_213 ) ;
if ( ! V_47 -> V_48 . V_208 )
return - V_214 ;
V_47 -> V_50 . V_194 = V_47 -> V_50 . V_44 * ( V_2 -> V_217 * 4 ) ;
V_47 -> V_48 . V_194 = V_47 -> V_48 . V_44 * ( V_2 -> V_218 * 4 ) ;
V_47 -> V_50 . V_42 = V_212 -> V_42 + V_212 -> V_216 ;
V_47 -> V_50 . V_203 = V_212 -> V_203 + V_212 -> V_216 ;
V_212 -> V_216 += F_17 ( V_47 -> V_50 . V_194 , 8 ) ;
V_47 -> V_48 . V_42 = V_212 -> V_42 + V_212 -> V_216 ;
V_47 -> V_48 . V_203 = V_212 -> V_203 + V_212 -> V_216 ;
V_212 -> V_216 += F_17 ( V_47 -> V_48 . V_194 , 8 ) ;
V_47 -> V_50 . V_205 = 0 ;
V_47 -> V_50 . V_204 = 0 ;
V_47 -> V_48 . V_205 = 0 ;
V_47 -> V_48 . V_204 = 0 ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_211 * V_212 = & V_2 -> V_212 ;
struct V_206 * V_198 = V_2 -> V_13 -> V_198 . V_199 ;
unsigned int V_219 = V_2 -> V_220 ;
unsigned int V_221 = V_2 -> V_222 ;
int V_223 ;
V_2 -> V_40 . V_41 . V_44 = V_2 -> V_220 ;
V_2 -> V_47 . V_50 . V_44 = V_2 -> V_222 ;
V_2 -> V_47 . V_48 . V_44 = V_2 -> V_222 ;
V_212 -> V_194 = V_219 * ( V_2 -> V_215 * 4 ) +
V_221 * ( V_2 -> V_218 * 4 ) +
V_221 * ( V_2 -> V_217 * 4 ) +
8 + 2 * 8 ;
V_212 -> V_216 = 0 ;
V_212 -> V_203 = F_38 ( V_198 , V_212 -> V_194 ,
& V_212 -> V_42 ,
V_213 ) ;
if ( ! V_212 -> V_203 )
return - V_214 ;
V_212 -> V_216 = F_17 ( V_212 -> V_42 , 8 ) -
V_212 -> V_42 ;
V_223 = F_33 ( V_2 , & V_2 -> V_40 ) ;
if ( V_223 ) {
F_39 ( V_2 -> V_13 , L_1 ) ;
goto V_224;
}
V_223 = F_36 ( V_2 ) ;
if ( V_223 ) {
F_39 ( V_2 -> V_13 , L_2 ) ;
goto V_225;
}
return 0 ;
V_225:
F_31 ( V_2 ) ;
V_224:
F_40 ( V_198 , V_212 -> V_194 ,
V_212 -> V_203 , V_212 -> V_42 ) ;
V_212 -> V_203 = NULL ;
V_212 -> V_42 = 0 ;
V_212 -> V_194 = 0 ;
V_212 -> V_216 = 0 ;
return V_223 ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_211 * V_212 = & V_2 -> V_212 ;
struct V_206 * V_198 = V_2 -> V_13 -> V_198 . V_199 ;
F_31 ( V_2 ) ;
F_35 ( V_2 ) ;
F_40 ( V_198 , V_212 -> V_194 ,
V_212 -> V_203 , V_212 -> V_42 ) ;
V_212 -> V_203 = NULL ;
V_212 -> V_42 = 0 ;
V_212 -> V_194 = 0 ;
V_212 -> V_216 = 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned int V_193 ;
V_2 -> V_40 . V_41 . V_205 = 0 ;
V_2 -> V_40 . V_41 . V_204 = 0 ;
for ( V_193 = 0 ; V_193 < V_2 -> V_40 . V_41 . V_44 ; V_193 ++ )
V_2 -> V_40 . V_41 . V_195 [ V_193 ] . V_42 = 0 ;
V_2 -> V_47 . V_50 . V_205 = 0 ;
V_2 -> V_47 . V_50 . V_204 = 0 ;
V_2 -> V_47 . V_48 . V_205 = 0 ;
V_2 -> V_47 . V_48 . V_204 = 0 ;
for ( V_193 = 0 ; V_193 < V_2 -> V_47 . V_48 . V_44 ; V_193 ++ )
V_2 -> V_47 . V_48 . V_208 [ V_193 ] . V_42 = 0 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_207 * V_47 ,
T_4 V_3 )
{
T_2 * V_226 = F_44 ( V_47 , V_2 -> V_218 , V_47 -> V_48 . V_205 ) ;
* ( V_226 ++ ) = F_10 ( V_3 ) ;
* V_226 = F_9 ( V_3 ) ;
if ( ++ V_47 -> V_48 . V_205 == V_47 -> V_48 . V_44 )
V_47 -> V_48 . V_205 = 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_207 * V_47 )
{
struct V_196 * V_227 ;
struct V_196 * V_228 ;
unsigned int V_44 = 0 ;
T_2 V_229 ;
V_229 = V_47 -> V_48 . V_205 + 1 ;
if ( V_229 == V_47 -> V_48 . V_44 )
V_229 = 0 ;
V_227 = F_29 ( V_47 , V_47 -> V_48 . V_205 ) ;
V_228 = F_29 ( V_47 , V_229 ) ;
while ( ! V_228 -> V_42 ) {
struct V_230 * V_202 ;
int V_223 ;
V_202 = F_46 ( V_2 -> V_13 , V_2 -> V_55 ) ;
if ( ! V_202 )
break;
V_227 -> V_42 =
F_47 ( V_2 -> V_13 -> V_198 . V_199 , V_202 -> V_231 ,
V_2 -> V_55 , V_210 ) ;
V_223 = F_48 ( V_2 -> V_13 -> V_198 . V_199 ,
V_227 -> V_42 ) ;
if ( V_223 ) {
F_30 ( V_202 ) ;
break;
}
V_227 -> V_202 = V_202 ;
V_227 -> V_200 = V_2 -> V_55 ;
F_43 ( V_2 , V_47 , V_227 -> V_42 ) ;
V_229 = V_47 -> V_48 . V_205 + 1 ;
if ( V_229 == V_47 -> V_48 . V_44 )
V_229 = 0 ;
V_227 = F_29 ( V_47 , V_47 -> V_48 . V_205 ) ;
V_228 = F_29 ( V_47 , V_229 ) ;
V_44 ++ ;
}
if ( V_44 ) {
T_2 V_232 = ( V_47 -> V_48 . V_205 << V_47 -> V_233 ) &
V_47 -> V_234 ;
F_12 ( V_2 -> V_9 + V_47 -> V_235 ,
V_47 -> V_234 , V_232 ) ;
}
}
static void F_49 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_50 ( V_13 ) ;
struct V_236 * V_237 = & V_2 -> V_238 ;
struct V_146 * V_147 = V_13 -> V_147 ;
if ( V_147 -> V_239 ) {
F_21 ( V_2 ) ;
V_237 -> V_240 ( V_2 ) ;
} else {
V_237 -> V_241 ( V_2 ) ;
F_19 ( V_2 ) ;
}
F_51 ( V_147 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_223 ;
F_42 ( V_2 ) ;
F_16 ( V_2 ) ;
F_45 ( V_2 , & V_2 -> V_47 ) ;
V_2 -> V_147 -> V_242 = V_243 ;
V_223 = F_53 ( V_13 , V_2 -> V_147 , F_49 ,
V_244 ) ;
if ( V_223 ) {
F_39 ( V_2 -> V_13 , L_3 ) ;
return V_223 ;
}
F_54 ( V_2 -> V_147 , NULL ) ;
F_5 ( ( T_2 ) ~ V_245 , V_2 -> V_9 + V_246 ) ;
F_5 ( V_2 -> V_242 . V_247 , V_2 -> V_9 + V_248 ) ;
F_55 ( V_2 -> V_147 ) ;
F_56 ( & V_2 -> V_47 . V_249 ) ;
F_57 ( V_13 ) ;
return 0 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_59 ( V_13 ) ;
F_60 ( & V_2 -> V_47 . V_249 ) ;
F_61 ( V_2 -> V_147 ) ;
F_5 ( V_245 , V_2 -> V_9 + V_246 ) ;
F_5 ( 0 , V_2 -> V_9 + V_248 ) ;
F_62 ( V_2 -> V_242 . V_242 ) ;
F_63 ( V_2 -> V_147 ) ;
F_18 ( V_2 ) ;
F_24 ( V_2 ) ;
F_64 ( V_2 -> V_13 ) ;
F_28 ( V_2 ) ;
}
static bool F_65 ( struct V_1 * V_2 ,
struct V_207 * V_47 ,
struct V_250 * V_50 )
{
T_2 * V_251 = F_66 ( V_47 , V_2 -> V_217 , V_47 -> V_50 . V_204 ) ;
V_50 -> V_252 [ 3 ] = * ( V_251 + 3 ) ;
if ( ! F_67 ( V_50 ) )
return false ;
V_50 -> V_252 [ 4 ] = 0 ;
V_50 -> V_252 [ 5 ] = 0 ;
V_50 -> V_252 [ 0 ] = * ( V_251 ++ ) ;
V_50 -> V_252 [ 1 ] = * ( V_251 ++ ) ;
V_50 -> V_252 [ 2 ] = * ( V_251 ++ ) ;
if ( F_68 ( F_69 ( V_50 ) != 1 ) ) {
F_39 ( V_2 -> V_13 ,
L_4 ,
F_69 ( V_50 ) ) ;
}
F_70 ( V_50 , 0 ) ;
* V_251 = V_50 -> V_252 [ 3 ] ;
if ( ++ V_47 -> V_50 . V_204 == V_47 -> V_50 . V_44 )
V_47 -> V_50 . V_204 = 0 ;
return true ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_192 * V_40 , struct V_253 * V_41 )
{
T_2 * V_254 ;
V_40 -> V_41 . V_255 = V_40 -> V_41 . V_205 ;
V_254 = F_72 ( V_40 , V_2 -> V_215 , V_40 -> V_41 . V_205 ) ;
if ( ++ V_40 -> V_41 . V_205 == V_40 -> V_41 . V_44 )
V_40 -> V_41 . V_205 = 0 ;
* ( V_254 ++ ) = V_41 -> V_252 [ 0 ] ;
* ( V_254 ++ ) = V_41 -> V_252 [ 1 ] ;
* ( V_254 ++ ) = V_41 -> V_252 [ 2 ] ;
* V_254 = V_41 -> V_252 [ 3 ] ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_192 * V_40 )
{
T_2 * V_254 =
F_72 ( V_40 , V_2 -> V_215 , V_40 -> V_41 . V_255 ) ;
T_2 V_256 ;
V_256 = * ( V_254 + 1 ) ;
V_256 |= V_257 ;
* ( V_254 + 1 ) = V_256 ;
}
static void F_74 ( struct V_207 * V_47 , struct V_250 * V_50 )
{
struct V_196 * V_209 = V_47 -> V_48 . V_208 ;
T_2 V_204 = F_75 ( V_50 ) ;
unsigned int V_193 ;
for ( V_193 = 0 ; V_193 < F_69 ( V_50 ) ; V_193 ++ ) {
V_209 [ V_204 ] . V_202 = NULL ;
if ( ++ V_204 == V_47 -> V_48 . V_44 )
V_204 = 0 ;
}
V_47 -> V_48 . V_204 = V_204 ;
V_47 -> V_48 . V_258 = V_204 ;
}
static void F_76 ( struct V_207 * V_47 ,
struct V_230 * V_202 ,
T_5 V_259 , bool V_260 )
{
if ( V_260 ) {
T_5 V_261 ;
F_77 ( V_259 , V_261 ) ;
F_78 ( V_202 , F_79 ( V_262 ) , V_261 ) ;
}
F_80 ( & V_47 -> V_249 , V_202 ) ;
}
void F_81 ( struct V_1 * V_2 , struct V_207 * V_47 ,
int * V_263 , int V_264 )
{
T_2 V_265 , V_266 , V_267 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_196 * V_209 ;
unsigned int V_44 = 0 ;
struct V_250 V_50 ;
struct V_230 * V_202 ;
T_2 V_6 ;
V_6 = F_82 ( V_2 -> V_9 + V_47 -> V_268 ) ;
V_266 = ( V_6 & V_47 -> V_269 ) >> V_47 -> V_270 ;
V_267 = ( V_266 >= V_47 -> V_50 . V_204 ) ?
( V_266 - V_47 -> V_50 . V_204 ) :
( V_266 + V_47 -> V_50 . V_44 - V_47 -> V_50 . V_204 ) ;
do {
if ( ! V_267 )
break;
if ( ! F_65 ( V_2 , V_47 , & V_50 ) )
break;
if ( F_83 ( F_69 ( & V_50 ) == 1 ) ) {
V_209 = F_29 ( V_47 , F_75 ( & V_50 ) ) ;
F_26 ( V_2 -> V_13 -> V_198 . V_199 ,
V_209 -> V_42 , V_209 -> V_200 ,
V_210 ) ;
V_209 -> V_42 = 0 ;
V_202 = V_209 -> V_202 ;
} else {
F_39 ( V_2 -> V_13 ,
L_5 ) ;
break;
}
F_74 ( V_47 , & V_50 ) ;
V_267 -- ;
V_44 ++ ;
if ( V_50 . V_252 [ V_271 ] & V_272 ) {
F_84 ( V_2 , V_273 , V_2 -> V_13 ,
L_6 ,
V_50 . V_252 [ 0 ] , V_50 . V_252 [ 1 ] ,
V_50 . V_252 [ 2 ] , V_50 . V_252 [ 3 ] ) ;
F_30 ( V_202 ) ;
continue;
}
F_85 ( V_202 , F_86 ( & V_50 ) - V_132 ) ;
V_202 -> V_198 = V_13 ;
V_202 -> V_274 = F_87 ( V_202 , V_202 -> V_198 ) ;
if ( V_13 -> V_20 & V_275 )
V_202 -> V_276 = F_88 ( & V_50 ) ?
V_277 : V_278 ;
else
F_89 ( V_202 ) ;
F_76 ( V_47 , V_202 , ( T_5 ) F_90 ( & V_50 ) ,
( bool ) F_91 ( & V_50 ) ) ;
( * V_263 ) ++ ;
} while ( * V_263 < V_264 );
if ( V_44 ) {
V_265 = ( V_47 -> V_48 . V_258 << V_47 -> V_279 ) &
V_47 -> V_280 ;
F_12 ( V_2 -> V_9 + V_47 -> V_281 ,
V_47 -> V_280 , V_265 ) ;
F_45 ( V_2 , V_47 ) ;
}
}
static unsigned int F_92 ( struct V_192 * V_40 )
{
T_2 V_205 = V_40 -> V_41 . V_205 ;
T_2 V_204 = V_40 -> V_41 . V_204 ;
return ( V_204 > V_205 ) ?
( V_204 - V_205 - 1 ) :
( V_40 -> V_41 . V_44 + V_204 - V_205 - 1 ) ;
}
void F_93 ( struct V_1 * V_2 , struct V_192 * V_40 )
{
T_2 V_6 = F_82 ( V_2 -> V_9 + V_40 -> V_268 ) ;
T_2 V_266 , V_282 = 0 , V_283 = 0 ;
struct V_196 * V_197 ;
V_266 = ( V_6 & V_40 -> V_269 ) >> V_40 -> V_270 ;
while ( V_40 -> V_41 . V_204 != V_266 ) {
V_197 = F_25 ( V_40 , V_40 -> V_41 . V_204 ) ;
if ( V_197 -> V_42 ) {
F_26 ( V_2 -> V_13 -> V_198 . V_199 ,
V_197 -> V_42 , V_197 -> V_200 ,
V_201 ) ;
V_197 -> V_42 = 0 ;
}
if ( V_197 -> V_202 ) {
V_282 ++ ;
V_283 += V_197 -> V_202 -> V_284 ;
F_94 ( V_197 -> V_202 ) ;
V_197 -> V_202 = NULL ;
}
if ( ++ V_40 -> V_41 . V_204 == V_40 -> V_41 . V_44 )
V_40 -> V_41 . V_204 = 0 ;
}
F_95 ( V_2 -> V_13 , V_282 , V_283 ) ;
if ( F_96 ( V_2 -> V_13 ) )
if ( F_92 ( V_40 ) > ( V_285 + 1 ) )
F_97 ( V_2 -> V_13 ) ;
}
void F_98 ( struct V_286 * V_287 ,
struct V_1 * V_2 )
{
V_2 -> V_47 . V_13 = V_2 -> V_13 ;
V_2 -> V_47 . V_235 = V_288 ;
V_2 -> V_47 . V_234 = V_289 ;
V_2 -> V_47 . V_233 = V_290 ;
V_2 -> V_47 . V_281 = V_288 ;
V_2 -> V_47 . V_280 = V_291 ;
V_2 -> V_47 . V_279 = V_292 ;
V_2 -> V_47 . V_268 = V_293 ;
V_2 -> V_47 . V_269 = V_294 ;
V_2 -> V_47 . V_270 = V_295 ;
V_2 -> V_47 . V_242 = & V_2 -> V_242 ;
V_2 -> V_47 . V_296 = V_2 -> V_242 . V_247 & V_297 ;
V_2 -> V_40 . V_235 = V_298 ;
V_2 -> V_40 . V_234 = V_299 ;
V_2 -> V_40 . V_233 = V_300 ;
V_2 -> V_40 . V_268 = V_301 ;
V_2 -> V_40 . V_269 = V_302 ;
V_2 -> V_40 . V_270 = V_303 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_192 * V_40 ,
struct V_230 * V_202 ,
struct V_253 * V_41 )
{
unsigned int V_304 ;
int V_223 ;
if ( F_100 ( V_202 ) ) {
if ( F_101 ( V_202 ) ) {
V_223 = F_102 ( V_202 , 0 , 0 , V_305 ) ;
if ( F_68 ( V_223 ) )
return V_223 ;
}
if ( V_202 -> V_274 == F_79 ( V_306 ) ) {
T_2 V_307 = ( ( unsigned char * ) F_103 ( V_202 ) - V_202 -> V_231 )
+ F_104 ( F_103 ( V_202 ) -> V_308 ) ;
if ( V_202 -> V_284 > V_307 )
F_105 ( V_202 , V_307 ) ;
}
V_304 = F_106 ( V_202 ) + F_107 ( V_202 ) ;
if ( F_68 ( V_202 -> V_284 == V_304 ) ) {
F_108 ( V_2 , V_309 , V_2 -> V_13 ,
L_7 ) ;
goto V_310;
}
if ( F_109 ( V_202 ) -> V_311 & V_312 ) {
F_103 ( V_202 ) -> V_313 = 0 ;
F_110 ( V_202 ) -> V_313 =
~ F_111 ( F_103 ( V_202 ) -> V_314 ,
F_103 ( V_202 ) -> V_315 ,
0 , V_316 , 0 ) ;
F_112 ( V_41 , 1 ) ;
}
if ( F_109 ( V_202 ) -> V_311 & V_317 ) {
struct V_253 V_318 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
memset ( & V_318 , 0 , sizeof( V_318 ) ) ;
F_113 ( V_202 ) -> V_319 = 0 ;
F_110 ( V_202 ) -> V_313 =
~ F_114 ( & F_113 ( V_202 ) -> V_314 ,
& F_113 ( V_202 ) -> V_315 ,
0 , V_316 , 0 ) ;
F_115 ( & V_318 , V_202 -> V_284 ) ;
F_116 ( & V_318 , 1 ) ;
F_117 ( & V_318 , 1 ) ;
F_71 ( V_2 , V_40 , & V_318 ) ;
F_117 ( V_41 , 1 ) ;
}
F_116 ( V_41 , 1 ) ;
F_118 ( V_41 , F_106 ( V_202 ) ) ;
F_119 ( V_41 , F_109 ( V_202 ) -> V_320 ) ;
return 0 ;
}
V_310:
if ( F_83 ( V_202 -> V_276 == V_321 ) ) {
unsigned int V_322 , V_323 ;
V_323 = F_106 ( V_202 ) ;
if ( F_68 ( V_323 & 0x1 ) ) {
F_39 ( V_2 -> V_13 ,
L_8 ) ;
return - V_324 ;
}
V_322 = V_323 + V_202 -> V_325 ;
F_120 ( V_41 , V_323 >> 1 ) ;
F_121 ( V_41 , V_322 >> 1 ) ;
F_122 ( V_41 , 1 ) ;
}
return 0 ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_192 * V_40 , struct V_230 * V_202 ,
struct V_253 * V_41 )
{
unsigned int V_326 = F_109 ( V_202 ) -> V_326 ;
unsigned int V_327 = V_40 -> V_41 . V_205 ;
unsigned int V_284 = F_124 ( V_202 ) ;
struct V_196 * V_197 = NULL ;
unsigned int V_328 = 0 ;
unsigned int V_193 ;
int V_44 = 0 ;
int V_223 ;
if ( F_125 ( V_41 ) ) {
V_328 = F_106 ( V_202 ) + F_107 ( V_202 ) ;
V_197 = F_25 ( V_40 , V_40 -> V_41 . V_205 ) ;
V_197 -> V_200 = V_328 ;
V_197 -> V_42 = F_47 ( V_2 -> V_13 -> V_198 . V_199 ,
V_202 -> V_231 , V_197 -> V_200 ,
V_201 ) ;
V_223 = F_48 ( V_2 -> V_13 -> V_198 . V_199 ,
V_197 -> V_42 ) ;
if ( V_223 )
goto error;
F_126 ( V_41 , F_10 ( V_197 -> V_42 ) ) ;
F_127 ( V_41 , F_9 ( V_197 -> V_42 ) ) ;
F_128 ( V_41 , V_197 -> V_200 ) ;
F_71 ( V_2 , V_40 , V_41 ) ;
V_44 ++ ;
}
if ( V_328 < V_284 ) {
V_197 = F_25 ( V_40 , V_40 -> V_41 . V_205 ) ;
V_197 -> V_200 = V_284 - V_328 ;
V_197 -> V_42 = F_47 ( V_2 -> V_13 -> V_198 . V_199 ,
V_202 -> V_231 + V_328 ,
V_197 -> V_200 , V_201 ) ;
V_223 = F_48 ( V_2 -> V_13 -> V_198 . V_199 ,
V_197 -> V_42 ) ;
if ( V_223 )
goto error;
F_126 ( V_41 , F_10 ( V_197 -> V_42 ) ) ;
F_127 ( V_41 , F_9 ( V_197 -> V_42 ) ) ;
F_128 ( V_41 , V_197 -> V_200 ) ;
F_71 ( V_2 , V_40 , V_41 ) ;
V_44 ++ ;
}
for ( V_193 = 0 ; V_193 < V_326 ; V_193 ++ ) {
struct V_329 * V_330 ;
V_330 = & F_109 ( V_202 ) -> V_331 [ V_193 ] ;
V_197 = F_25 ( V_40 , V_40 -> V_41 . V_205 ) ;
V_197 -> V_200 = V_330 -> V_194 ;
V_197 -> V_42 = F_129 ( V_2 -> V_13 -> V_198 . V_199 ,
V_330 -> V_332 . V_333 , V_330 -> V_334 ,
V_197 -> V_200 , V_201 ) ;
V_223 = F_48 ( V_2 -> V_13 -> V_198 . V_199 ,
V_197 -> V_42 ) ;
if ( V_223 )
goto error;
F_126 ( V_41 , F_10 ( V_197 -> V_42 ) ) ;
F_127 ( V_41 , F_9 ( V_197 -> V_42 ) ) ;
F_128 ( V_41 , V_197 -> V_200 ) ;
F_71 ( V_2 , V_40 , V_41 ) ;
V_44 ++ ;
}
F_130 () ;
F_73 ( V_2 , V_40 ) ;
V_197 -> V_202 = V_202 ;
return;
error:
V_40 -> V_41 . V_205 = V_327 ;
while ( V_44 -- ) {
V_197 = F_25 ( V_40 , V_327 ) ;
F_131 ( V_2 -> V_13 -> V_198 . V_199 , V_197 -> V_42 ,
V_197 -> V_200 , V_201 ) ;
V_197 -> V_42 = 0 ;
V_197 -> V_200 = 0 ;
if ( ++ V_327 == V_40 -> V_41 . V_44 )
V_327 = 0 ;
}
F_30 ( V_202 ) ;
}
int F_132 ( struct V_1 * V_2 , struct V_192 * V_40 ,
struct V_230 * V_202 )
{
struct V_253 V_41 ;
T_2 V_232 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
if ( F_99 ( V_2 , V_40 , V_202 , & V_41 ) != 0 ) {
F_27 ( V_202 ) ;
return V_335 ;
}
if ( F_133 ( V_202 ) ) {
T_5 V_336 ;
F_134 ( F_135 ( V_202 ) , V_336 ) ;
F_136 ( & V_41 , V_336 ) ;
F_137 ( & V_41 , 1 ) ;
}
if ( F_138 ( V_202 ) != V_131 )
F_139 ( & V_41 , 1 ) ;
F_123 ( V_2 , V_40 , V_202 , & V_41 ) ;
F_140 ( V_2 -> V_13 , V_202 -> V_284 ) ;
if ( F_92 ( V_40 ) < ( V_285 + 3 ) )
F_59 ( V_2 -> V_13 ) ;
V_232 = ( V_40 -> V_41 . V_205 << V_40 -> V_233 ) &
V_40 -> V_234 ;
F_12 ( V_2 -> V_9 + V_40 -> V_235 ,
V_40 -> V_234 , V_232 ) ;
return V_335 ;
}
