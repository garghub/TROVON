static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_75 :
case V_68 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return 1 ;
default:
return 0 ;
}
}
static int F_3 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
F_4 ( V_85 != V_86 ) ;
F_5 ( 4 ) ;
return 0 ;
}
static int F_6 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
struct V_87 * V_88 = V_82 -> V_88 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
switch ( V_85 ) {
case V_86 :
V_90 -> V_91 |= 1 << V_82 -> V_92 ;
break;
case V_93 :
F_8 ( V_88 , V_54 ,
1 << V_82 -> V_92 , 0 ) ;
break;
}
return 0 ;
}
static void F_9 ( struct V_94 * V_95 ,
enum V_96 V_85 , int V_97 )
{
struct V_87 * V_88 = F_10 ( V_95 ,
struct V_87 , V_95 ) ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_98 = V_99 ;
int V_100 , V_101 ;
if ( V_90 -> V_91 ) {
F_11 ( V_88 -> V_2 , L_1 ,
V_90 -> V_91 ) ;
for ( V_100 = 0 ; V_100 < F_12 ( V_90 -> V_102 ) ; V_100 ++ ) {
if ( ! ( V_90 -> V_91 & ( 1 << V_100 ) ) )
continue;
if ( V_90 -> V_102 [ V_100 ] ) {
F_11 ( V_88 -> V_2 ,
L_2 ,
3 - V_100 , V_90 -> V_102 [ V_100 ] ) ;
F_13 ( V_88 , V_103 + V_100 ,
V_90 -> V_102 [ V_100 ] & 0xff ) ;
} else {
F_11 ( V_88 -> V_2 ,
L_3 , 3 - V_100 ) ;
V_98 = V_104 ;
}
}
if ( V_90 -> V_105 )
V_98 = V_104 ;
F_8 ( V_88 , V_55 ,
V_106 , V_98 ) ;
F_8 ( V_88 , V_54 ,
V_107 , V_90 -> V_91 ) ;
switch ( V_98 ) {
case V_99 :
break;
case V_104 :
F_14 ( 270 ) ;
if ( V_90 -> V_105 )
break;
for ( V_100 = 0 ; V_100 < F_12 ( V_90 -> V_102 ) ; V_100 ++ ) {
if ( ! ( V_90 -> V_91 & ( 1 << V_100 ) ) )
continue;
V_101 = F_15 ( V_88 ,
V_56 + V_100 ) ;
F_11 ( V_88 -> V_2 , L_4 ,
3 - V_100 , V_101 ) ;
V_90 -> V_102 [ V_100 ] = V_101 ;
}
break;
default:
F_16 ( L_5 , V_98 ) ;
break;
}
V_90 -> V_91 = 0 ;
}
}
static int F_17 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_110 * V_111 = F_18 ( V_84 ) ;
struct V_81 * V_112 = V_111 -> V_113 [ 0 ] ;
struct V_87 * V_88 = V_112 -> V_88 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
T_1 V_3 ;
int V_114 ;
V_3 = F_15 ( V_88 , V_63 ) ;
if ( V_109 -> V_115 . integer . V_115 [ 0 ] ) {
if ( V_90 -> V_105 == 0 ) {
F_11 ( V_88 -> V_2 , L_6 ) ;
F_13 ( V_88 , V_63 , V_3 &
~ ( V_116 | V_117 ) ) ;
}
V_90 -> V_105 ++ ;
}
V_114 = F_19 ( V_84 , V_109 ) ;
if ( ! V_109 -> V_115 . integer . V_115 [ 0 ] ) {
if ( V_90 -> V_105 == 1 ) {
F_11 ( V_88 -> V_2 , L_7 ) ;
F_13 ( V_88 , V_63 , V_3 |
V_116 | V_117 ) ;
}
V_90 -> V_105 -- ;
}
F_11 ( V_88 -> V_2 , L_8 ,
V_90 -> V_105 ) ;
return V_114 ;
}
static int F_20 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_101 , V_100 , V_118 ;
if ( V_90 -> V_119 ) {
V_118 = 1 ;
for ( V_100 = 2 ; V_100 < F_12 ( V_120 ) ; V_100 ++ ) {
if ( abs ( V_120 [ V_100 ] - V_90 -> V_121 ) <
abs ( V_120 [ V_118 ] - V_90 -> V_121 ) )
V_118 = V_100 ;
}
V_101 = V_118 << V_122 ;
} else {
V_118 = 0 ;
V_101 = 0 ;
}
F_11 ( V_88 -> V_2 , L_9 ,
V_118 , V_120 [ V_118 ] ) ;
return F_8 ( V_88 , V_28 ,
V_123 , V_101 ) ;
}
static int F_21 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_87 * V_88 = F_18 ( V_84 ) ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
V_109 -> V_115 . V_124 . V_125 [ 0 ] = V_90 -> V_119 ;
return 0 ;
}
static int F_22 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_87 * V_88 = F_18 ( V_84 ) ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_119 = V_109 -> V_115 . V_124 . V_125 [ 0 ] ;
int V_114 = 0 ;
if ( V_119 > 1 )
return - V_126 ;
F_23 ( & V_88 -> V_127 ) ;
if ( V_90 -> V_119 != V_119 ) {
V_90 -> V_119 = V_119 ;
F_20 ( V_88 ) ;
V_114 = 1 ;
}
F_24 ( & V_88 -> V_127 ) ;
return V_114 ;
}
static int F_25 ( struct V_87 * V_88 ,
enum V_128 V_129 )
{
switch ( V_129 ) {
case V_130 :
break;
case V_131 :
F_8 ( V_88 , V_7 ,
V_132 ,
V_133 ) ;
break;
case V_134 :
if ( V_88 -> V_95 . V_135 == V_136 ) {
F_8 ( V_88 , V_6 ,
V_137 | V_138 |
V_139 |
V_140 ,
V_137 |
( 2 << V_141 ) |
V_139 ) ;
F_8 ( V_88 ,
V_53 ,
V_142 ,
V_142 ) ;
F_14 ( 33 ) ;
F_8 ( V_88 , V_16 ,
V_143 | V_144 ,
V_143 | V_144 ) ;
F_8 ( V_88 ,
V_53 ,
V_142 , 0 ) ;
F_8 ( V_88 , V_7 ,
V_145 |
V_146 |
V_147 |
V_148 |
V_132 |
V_149 ,
V_145 |
V_146 |
V_147 |
( 2 << V_150 ) |
V_151 |
V_149 ) ;
F_14 ( 129 ) ;
F_8 ( V_88 , V_16 ,
V_143 | V_144 ,
0 ) ;
F_8 ( V_88 , V_7 ,
V_148 , 0 ) ;
F_8 ( V_88 , V_7 ,
V_132 ,
V_133 ) ;
F_8 ( V_88 , V_6 ,
V_140 | V_137 ,
V_140 ) ;
F_11 ( V_88 -> V_2 , L_7 ) ;
F_8 ( V_88 , V_63 ,
V_116 |
V_117 ,
V_116 |
V_117 ) ;
}
F_8 ( V_88 , V_7 ,
V_132 ,
V_151 ) ;
break;
case V_136 :
F_8 ( V_88 , V_6 ,
V_140 , 0 ) ;
F_8 ( V_88 , V_7 ,
V_148 ,
2 << V_150 ) ;
F_8 ( V_88 , V_7 ,
V_149 , 0 ) ;
F_14 ( 290 ) ;
F_8 ( V_88 , V_7 ,
V_145 | V_146 |
V_147 | V_132 |
V_148 |
V_149 , 0 ) ;
F_8 ( V_88 , V_6 ,
V_139 , 0 ) ;
break;
}
V_88 -> V_95 . V_135 = V_129 ;
return 0 ;
}
static int F_26 ( struct V_152 * V_153 ,
int V_154 , unsigned int V_155 , int V_156 )
{
struct V_87 * V_88 = V_153 -> V_88 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
V_90 -> V_157 = V_155 ;
return 0 ;
}
static int F_27 ( struct V_152 * V_153 ,
unsigned int V_158 )
{
struct V_87 * V_88 = V_153 -> V_88 ;
T_1 V_159 = F_15 ( V_88 , V_22 ) ;
V_159 &= ~ ( V_160 | V_161 | V_162 |
V_163 | V_164 ) ;
switch ( V_158 & V_165 ) {
case V_166 :
break;
case V_167 :
V_159 |= V_160 ;
break;
case V_168 :
V_159 |= V_160 | V_161 ;
break;
case V_169 :
V_159 |= V_161 ;
break;
default:
return - V_126 ;
}
switch ( V_158 & V_170 ) {
case V_171 :
V_159 |= 0x3 ;
break;
case V_172 :
V_159 |= 0x3 | V_163 ;
break;
case V_173 :
V_159 |= 0x2 ;
break;
case V_174 :
V_159 |= 0x1 ;
break;
case V_175 :
break;
default:
return - V_126 ;
}
switch ( V_158 & V_170 ) {
case V_171 :
case V_172 :
switch ( V_158 & V_176 ) {
case V_177 :
break;
case V_178 :
V_159 |= V_164 ;
break;
default:
return - V_126 ;
}
break;
case V_173 :
case V_174 :
case V_175 :
switch ( V_158 & V_176 ) {
case V_177 :
break;
case V_179 :
V_159 |= V_164 | V_163 ;
break;
case V_178 :
V_159 |= V_164 ;
break;
case V_180 :
V_159 |= V_163 ;
break;
default:
return - V_126 ;
}
break;
default:
return - V_126 ;
}
F_13 ( V_88 , V_22 , V_159 ) ;
return 0 ;
}
static int F_28 ( struct V_152 * V_153 , int V_181 )
{
struct V_87 * V_88 = V_153 -> V_88 ;
T_1 V_3 ;
V_3 = F_15 ( V_88 , V_28 ) ;
if ( V_181 )
V_3 |= V_182 ;
else
V_3 &= ~ V_182 ;
F_13 ( V_88 , V_28 , V_3 ) ;
return 0 ;
}
static int F_29 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
struct V_152 * V_187 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_87 * V_88 = V_189 -> V_88 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_121 = F_30 ( V_186 ) ;
int V_191 ;
int V_192 ;
int V_100 ;
int V_193 ;
int V_194 ;
int V_195 ;
int V_196 ;
int V_197 ;
T_1 V_159 = F_15 ( V_88 , V_22 ) ;
T_1 V_198 = F_15 ( V_88 , V_23 ) ;
T_1 V_199 = F_15 ( V_88 , V_24 ) ;
T_1 V_200 = F_15 ( V_88 , V_18 ) ;
T_1 V_201 = F_15 ( V_88 , V_19 ) ;
T_1 V_202 = F_15 ( V_88 , V_28 ) ;
if ( V_121 <= 24000 )
V_202 |= V_203 ;
else
V_202 &= ~ V_203 ;
V_193 = 0 ;
V_195 = abs ( V_204 [ V_193 ] . V_205 - V_121 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_204 ) ; V_100 ++ ) {
V_196 = abs ( V_204 [ V_100 ] . V_205 - V_121 ) ;
if ( V_196 <= V_195 ) {
V_193 = V_100 ;
V_195 = V_196 ;
}
}
F_11 ( V_88 -> V_2 , L_10 , V_204 [ V_193 ] . V_205 ) ;
V_201 &= ~ V_206 ;
V_201 |= V_204 [ V_193 ] . V_115 ;
V_159 &= ~ V_207 ;
V_191 = 2 * V_121 ;
switch ( F_31 ( V_186 ) ) {
case V_208 :
V_191 *= 16 ;
break;
case V_209 :
V_191 *= 20 ;
V_159 |= 0x4 ;
break;
case V_210 :
V_191 *= 24 ;
V_159 |= 0x8 ;
break;
case V_211 :
V_191 *= 32 ;
V_159 |= 0xc ;
break;
default:
return - V_126 ;
}
F_11 ( V_88 -> V_2 , L_11 ,
V_90 -> V_157 , V_121 ) ;
V_194 = 0 ;
V_195 = abs ( ( V_90 -> V_157 /
( V_212 [ 0 ] . V_213 *
V_212 [ 0 ] . div ) ) - V_121 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_212 ) ; V_100 ++ ) {
V_196 = abs ( ( V_90 -> V_157 /
( V_212 [ V_100 ] . V_213 *
V_212 [ V_100 ] . div ) ) - V_121 ) ;
if ( V_196 <= V_195 ) {
V_194 = V_100 ;
V_195 = V_196 ;
}
}
if ( V_212 [ V_194 ] . V_213 == 2 ) {
V_200 |= V_214 ;
V_197 = V_90 -> V_157 / 2 ;
} else {
V_200 &= ~ V_214 ;
V_197 = V_90 -> V_157 ;
}
V_201 &= ~ ( V_215 |
V_216 ) ;
V_201 |= V_212 [ V_194 ] . V_205 << V_217 ;
V_201 |= V_212 [ V_194 ] . V_218 << V_219 ;
F_11 ( V_88 -> V_2 , L_12 ,
V_212 [ V_194 ] . V_205 ,
V_212 [ V_194 ] . V_218 ,
V_212 [ V_194 ] . div ) ;
F_11 ( V_88 -> V_2 , L_13 , V_197 ) ;
V_192 = 0 ;
V_195 = ( ( V_197 * 10 ) / V_220 [ 0 ] . V_221 ) - V_191 ;
V_100 = 1 ;
while ( V_100 < F_12 ( V_220 ) ) {
V_196 = ( ( V_197 * 10 ) / V_220 [ V_100 ] . V_221 ) - V_191 ;
if ( V_196 < 0 )
break;
V_192 = V_100 ;
V_195 = V_196 ;
V_100 ++ ;
}
V_198 &= ~ V_222 ;
V_199 &= ~ V_223 ;
F_11 ( V_88 -> V_2 , L_14 ,
V_220 [ V_192 ] . V_221 / 10 , V_191 ,
( V_197 * 10 ) / V_220 [ V_192 ] . V_221 ) ;
V_198 |= V_220 [ V_192 ] . div ;
V_199 |= V_191 / V_121 ;
V_90 -> V_121 = F_30 ( V_186 ) ;
F_20 ( V_88 ) ;
F_13 ( V_88 , V_18 , V_200 ) ;
F_13 ( V_88 , V_19 , V_201 ) ;
F_13 ( V_88 , V_22 , V_159 ) ;
F_13 ( V_88 , V_23 , V_198 ) ;
F_13 ( V_88 , V_24 , V_199 ) ;
F_13 ( V_88 , V_28 , V_202 ) ;
return 0 ;
}
int F_32 ( struct V_87 * V_88 , struct V_224 * V_225 ,
int V_226 , int V_227 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_228 = V_229 | V_230 ;
F_11 ( V_88 -> V_2 , L_15 ,
V_226 , V_227 ) ;
V_90 -> V_231 = V_225 ;
V_90 -> V_232 = V_226 ;
V_90 -> V_233 = V_227 ;
if ( V_226 )
V_228 &= ~ V_229 ;
if ( V_227 )
V_228 &= ~ V_230 ;
F_8 ( V_88 , V_76 ,
V_229 | V_230 ,
V_228 ) ;
if ( V_226 || V_227 ) {
F_8 ( V_88 , V_64 ,
V_234 , V_234 ) ;
F_8 ( V_88 , V_8 ,
V_235 , V_235 ) ;
} else {
F_8 ( V_88 , V_8 ,
V_235 , 0 ) ;
}
return 0 ;
}
static T_2 F_33 ( int V_236 , void * V_237 )
{
struct V_87 * V_88 = V_237 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_238 ;
int V_239 ;
int V_240 = 0 ;
int V_241 = ~ F_15 ( V_88 , V_76 ) ;
V_240 = F_15 ( V_88 , V_75 ) & V_241 ;
if ( V_240 & V_242 ) {
F_34 ( V_88 -> V_2 , L_16 ) ;
}
V_238 = V_90 -> V_243 ;
V_239 = F_15 ( V_88 , V_77 ) ;
#ifndef F_35
if ( V_240 & ( V_230 | V_229 ) )
F_36 ( F_37 ( V_88 -> V_2 ) ) ;
#endif
if ( V_240 & V_230 ) {
F_11 ( V_88 -> V_2 , L_17 , V_239 ) ;
V_238 ^= V_90 -> V_233 ;
V_239 ^= V_244 ;
}
if ( V_240 & V_229 ) {
F_11 ( V_88 -> V_2 , L_18 , V_239 ) ;
V_238 ^= V_90 -> V_232 ;
V_239 ^= V_245 ;
F_14 ( V_90 -> V_246 ) ;
}
F_8 ( V_88 , V_77 ,
V_244 | V_245 , V_239 ) ;
F_38 ( V_90 -> V_231 , V_238 ,
V_90 -> V_233 | V_90 -> V_232 ) ;
V_90 -> V_243 = V_238 ;
return V_247 ;
}
static int F_39 ( struct V_87 * V_88 )
{
F_25 ( V_88 , V_136 ) ;
return 0 ;
}
static int F_40 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
F_41 ( V_90 -> V_248 ) ;
F_25 ( V_88 , V_134 ) ;
return 0 ;
}
static inline struct V_89 * F_42 ( struct V_249 * V_250 )
{
return F_10 ( V_250 , struct V_89 , V_249 ) ;
}
static int F_43 ( struct V_249 * V_250 , unsigned V_251 )
{
if ( V_251 >= V_252 )
return - V_126 ;
return 0 ;
}
static int F_44 ( struct V_249 * V_250 , unsigned V_251 )
{
struct V_89 * V_90 = F_42 ( V_250 ) ;
struct V_87 * V_88 = V_90 -> V_88 ;
unsigned int V_241 , V_101 ;
int V_114 ;
V_241 = V_253 | V_254 ;
V_101 = ( V_255 << V_256 ) |
V_257 ;
V_114 = F_8 ( V_88 , V_70 + V_251 ,
V_241 , V_101 ) ;
if ( V_114 < 0 )
return V_114 ;
return 0 ;
}
static int F_45 ( struct V_249 * V_250 , unsigned V_251 )
{
struct V_89 * V_90 = F_42 ( V_250 ) ;
struct V_87 * V_88 = V_90 -> V_88 ;
int V_3 ;
V_3 = F_15 ( V_88 , V_70 + V_251 ) ;
return ( V_3 & V_258 ) >> V_259 ;
}
static int F_46 ( struct V_249 * V_250 ,
unsigned V_251 , int V_115 )
{
struct V_89 * V_90 = F_42 ( V_250 ) ;
struct V_87 * V_88 = V_90 -> V_88 ;
unsigned int V_241 , V_101 ;
int V_114 ;
V_241 = V_253 | V_254 | V_258 ;
V_101 = ( V_260 << V_256 ) |
( V_115 << V_261 ) ;
V_114 = F_8 ( V_88 , V_70 + V_251 ,
V_241 , V_101 ) ;
if ( V_114 < 0 )
return V_114 ;
return 0 ;
}
static void F_47 ( struct V_249 * V_250 , unsigned V_251 , int V_115 )
{
struct V_89 * V_90 = F_42 ( V_250 ) ;
struct V_87 * V_88 = V_90 -> V_88 ;
F_8 ( V_88 , V_70 + V_251 ,
V_258 ,
! ! V_115 << V_259 ) ;
}
static void F_48 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
struct V_262 * V_263 = V_90 -> V_263 ;
int V_114 ;
V_90 -> V_249 = V_264 ;
V_90 -> V_249 . V_265 = V_252 ;
V_90 -> V_249 . V_2 = V_88 -> V_2 ;
if ( V_263 -> V_266 )
V_90 -> V_249 . V_267 = V_263 -> V_266 ;
else
V_90 -> V_249 . V_267 = - 1 ;
V_114 = F_49 ( & V_90 -> V_249 ) ;
if ( V_114 != 0 )
F_50 ( V_88 -> V_2 , L_19 , V_114 ) ;
}
static void F_51 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_114 ;
V_114 = F_52 ( & V_90 -> V_249 ) ;
if ( V_114 != 0 )
F_50 ( V_88 -> V_2 , L_20 , V_114 ) ;
}
static void F_48 ( struct V_87 * V_88 )
{
}
static void F_51 ( struct V_87 * V_88 )
{
}
static int F_53 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
struct V_262 * V_263 = V_90 -> V_263 ;
int V_114 , V_100 ;
int V_268 , V_269 ;
T_1 V_101 ;
bool V_270 = false ;
V_90 -> V_88 = V_88 ;
V_88 -> V_271 = V_90 -> V_248 ;
V_114 = F_54 ( V_88 , 8 , 16 , V_272 ) ;
if ( V_114 != 0 ) {
F_50 ( V_88 -> V_2 , L_21 , V_114 ) ;
return V_114 ;
}
for ( V_100 = 0 ; V_100 < F_12 ( V_263 -> V_273 ) ; V_100 ++ ) {
if ( ( ! V_263 -> V_273 [ V_100 ] ) ||
( V_263 -> V_273 [ V_100 ] > V_274 ) )
continue;
F_13 ( V_88 , V_70 + V_100 ,
V_263 -> V_273 [ V_100 ] & 0x7fff ) ;
V_101 = ( V_263 -> V_273 [ V_100 ] & V_253 )
>> V_256 ;
switch ( V_101 ) {
case V_275 :
case V_276 :
V_270 = true ;
break;
default:
break;
}
}
F_13 ( V_88 , V_8 ,
V_263 -> V_277 ) ;
if ( V_263 -> V_277 )
F_8 ( V_88 , V_64 ,
V_234 , V_234 ) ;
F_4 ( ! V_270 && ( V_263 -> V_277 & V_235 ) ) ;
V_90 -> V_246 = V_263 -> V_278 ;
if ( V_90 -> V_236 ) {
if ( V_263 -> V_279 ) {
V_268 = V_280 ;
V_269 = V_281 ;
} else {
V_268 = V_282 ;
V_269 = 0 ;
}
F_8 ( V_88 , V_78 ,
V_281 , V_269 ) ;
V_114 = F_55 ( V_90 -> V_236 , NULL , F_33 ,
V_268 | V_283 ,
L_22 , V_88 ) ;
if ( V_114 != 0 ) {
F_50 ( V_88 -> V_2 , L_23 ,
V_114 ) ;
return V_114 ;
}
F_8 ( V_88 , V_76 ,
V_284 , 0 ) ;
}
F_25 ( V_88 , V_134 ) ;
V_101 = F_15 ( V_88 , V_29 ) ;
V_101 |= V_285 ;
F_13 ( V_88 , V_29 , V_101 ) ;
F_13 ( V_88 , V_30 , V_101 ) ;
V_101 = F_15 ( V_88 , V_25 ) ;
V_101 |= V_286 ;
F_13 ( V_88 , V_25 , V_101 ) ;
F_13 ( V_88 , V_26 , V_101 ) ;
V_101 = F_15 ( V_88 , V_47 ) ;
V_101 |= V_287 ;
F_13 ( V_88 , V_47 , V_101 ) ;
F_13 ( V_88 , V_48 , V_101 ) ;
V_101 = F_15 ( V_88 , V_49 ) ;
V_101 |= V_288 ;
F_13 ( V_88 , V_49 , V_101 ) ;
F_13 ( V_88 , V_50 , V_101 ) ;
V_101 = F_15 ( V_88 , V_51 ) ;
V_101 |= V_289 ;
F_13 ( V_88 , V_51 , V_101 ) ;
F_13 ( V_88 , V_52 , V_101 ) ;
F_8 ( V_88 , V_28 ,
V_290 | V_182 ,
V_290 | V_182 ) ;
F_48 ( V_88 ) ;
return V_114 ;
}
static int F_56 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
F_51 ( V_88 ) ;
F_25 ( V_88 , V_136 ) ;
if ( V_90 -> V_236 )
F_57 ( V_90 -> V_236 , V_88 ) ;
return 0 ;
}
static int F_58 ( struct V_291 * V_292 ,
struct V_262 * V_263 )
{
struct V_293 * V_293 = F_59 ( V_292 -> V_236 ) ;
if ( ! V_293 ) {
F_50 ( & V_292 -> V_2 , L_24 ,
V_292 -> V_236 ) ;
return - V_126 ;
}
switch ( F_60 ( V_293 ) ) {
case V_294 :
default:
case V_295 :
V_263 -> V_279 = false ;
break;
case V_296 :
V_263 -> V_279 = true ;
break;
}
return 0 ;
}
static int F_61 ( struct V_291 * V_292 ,
struct V_262 * V_263 )
{
const struct V_297 * V_298 = V_292 -> V_2 . V_299 ;
T_3 V_300 ;
int V_100 ;
if ( F_62 ( V_298 , L_25 , & V_300 ) >= 0 )
V_263 -> V_277 = V_300 ;
if ( F_62 ( V_298 , L_26 , & V_300 ) >= 0 )
V_263 -> V_278 = V_300 ;
if ( F_63 ( V_298 , L_27 , V_263 -> V_273 ,
F_12 ( V_263 -> V_273 ) ) >= 0 ) {
for ( V_100 = 0 ; V_100 < F_12 ( V_263 -> V_273 ) ; V_100 ++ ) {
if ( V_263 -> V_273 [ V_100 ] == 0 ) {
V_263 -> V_273 [ V_100 ] = V_274 ;
} else if ( V_263 -> V_273 [ V_100 ] == 0xffffffff ) {
V_263 -> V_273 [ V_100 ] = 0 ;
} else if ( V_263 -> V_273 [ V_100 ] > 0x7fff ) {
F_50 ( & V_292 -> V_2 , L_28 ,
V_100 , V_263 -> V_273 [ V_100 ] ) ;
return - V_126 ;
}
}
}
return 0 ;
}
static T_4 int F_64 ( struct V_291 * V_292 ,
const struct V_301 * V_302 )
{
struct V_262 * V_263 = F_65 ( & V_292 -> V_2 ) ;
struct V_89 * V_90 ;
unsigned int V_101 ;
int V_114 ;
V_90 = F_66 ( & V_292 -> V_2 , sizeof( struct V_89 ) ,
V_303 ) ;
if ( V_90 == NULL )
return - V_304 ;
V_90 -> V_248 = F_67 ( V_292 , & V_305 ) ;
if ( F_68 ( V_90 -> V_248 ) ) {
V_114 = F_69 ( V_90 -> V_248 ) ;
F_50 ( & V_292 -> V_2 , L_29 ,
V_114 ) ;
return V_114 ;
}
F_70 ( V_292 , V_90 ) ;
V_90 -> V_236 = V_292 -> V_236 ;
if ( V_263 ) {
V_90 -> V_263 = V_263 ;
} else {
V_90 -> V_263 = F_66 ( & V_292 -> V_2 ,
sizeof( struct V_262 ) ,
V_303 ) ;
if ( V_90 -> V_263 == NULL ) {
F_50 ( & V_292 -> V_2 , L_30 ) ;
return - V_304 ;
}
if ( V_292 -> V_236 ) {
V_114 = F_58 ( V_292 , V_90 -> V_263 ) ;
if ( V_114 != 0 )
return V_114 ;
}
if ( V_292 -> V_2 . V_299 ) {
V_114 = F_61 ( V_292 , V_90 -> V_263 ) ;
if ( V_114 != 0 )
return V_114 ;
}
}
V_114 = F_71 ( V_90 -> V_248 , V_4 , & V_101 ) ;
if ( V_114 != 0 ) {
F_50 ( & V_292 -> V_2 , L_31 , V_114 ) ;
goto V_306;
}
if ( V_101 != 0x8903 ) {
F_50 ( & V_292 -> V_2 , L_32 , V_101 ) ;
V_114 = - V_307 ;
goto V_306;
}
V_114 = F_71 ( V_90 -> V_248 , V_5 , & V_101 ) ;
if ( V_114 != 0 ) {
F_50 ( & V_292 -> V_2 , L_33 , V_114 ) ;
goto V_306;
}
F_72 ( & V_292 -> V_2 , L_34 ,
( V_101 & V_308 ) + 'A' ) ;
F_73 ( V_90 -> V_248 , V_4 , 0x8903 ) ;
V_114 = F_74 ( & V_292 -> V_2 ,
& V_309 , & V_310 , 1 ) ;
if ( V_114 != 0 )
goto V_306;
return 0 ;
V_306:
F_75 ( V_90 -> V_248 ) ;
return V_114 ;
}
static T_5 int F_76 ( struct V_291 * V_311 )
{
struct V_89 * V_90 = F_77 ( V_311 ) ;
F_75 ( V_90 -> V_248 ) ;
F_78 ( & V_311 -> V_2 ) ;
return 0 ;
}
static int T_6 F_79 ( void )
{
int V_114 = 0 ;
V_114 = F_80 ( & V_312 ) ;
if ( V_114 != 0 ) {
F_81 ( V_313 L_35 ,
V_114 ) ;
}
return V_114 ;
}
static void T_7 F_82 ( void )
{
F_83 ( & V_312 ) ;
}
