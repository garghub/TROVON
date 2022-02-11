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
struct V_87 * V_88 = V_187 -> V_88 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_121 = F_30 ( V_186 ) ;
int V_188 ;
int V_189 ;
int V_100 ;
int V_190 ;
int V_191 ;
int V_192 ;
int V_193 ;
int V_194 ;
T_1 V_159 = F_15 ( V_88 , V_22 ) ;
T_1 V_195 = F_15 ( V_88 , V_23 ) ;
T_1 V_196 = F_15 ( V_88 , V_24 ) ;
T_1 V_197 = F_15 ( V_88 , V_18 ) ;
T_1 V_198 = F_15 ( V_88 , V_19 ) ;
T_1 V_199 = F_15 ( V_88 , V_28 ) ;
if ( V_121 <= 24000 )
V_199 |= V_200 ;
else
V_199 &= ~ V_200 ;
V_190 = 0 ;
V_192 = abs ( V_201 [ V_190 ] . V_202 - V_121 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_201 ) ; V_100 ++ ) {
V_193 = abs ( V_201 [ V_100 ] . V_202 - V_121 ) ;
if ( V_193 <= V_192 ) {
V_190 = V_100 ;
V_192 = V_193 ;
}
}
F_11 ( V_88 -> V_2 , L_10 , V_201 [ V_190 ] . V_202 ) ;
V_198 &= ~ V_203 ;
V_198 |= V_201 [ V_190 ] . V_115 ;
V_159 &= ~ V_204 ;
V_188 = 2 * V_121 ;
switch ( F_31 ( V_186 ) ) {
case V_205 :
V_188 *= 16 ;
break;
case V_206 :
V_188 *= 20 ;
V_159 |= 0x4 ;
break;
case V_207 :
V_188 *= 24 ;
V_159 |= 0x8 ;
break;
case V_208 :
V_188 *= 32 ;
V_159 |= 0xc ;
break;
default:
return - V_126 ;
}
F_11 ( V_88 -> V_2 , L_11 ,
V_90 -> V_157 , V_121 ) ;
V_191 = 0 ;
V_192 = abs ( ( V_90 -> V_157 /
( V_209 [ 0 ] . V_210 *
V_209 [ 0 ] . div ) ) - V_121 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_209 ) ; V_100 ++ ) {
V_193 = abs ( ( V_90 -> V_157 /
( V_209 [ V_100 ] . V_210 *
V_209 [ V_100 ] . div ) ) - V_121 ) ;
if ( V_193 <= V_192 ) {
V_191 = V_100 ;
V_192 = V_193 ;
}
}
if ( V_209 [ V_191 ] . V_210 == 2 ) {
V_197 |= V_211 ;
V_194 = V_90 -> V_157 / 2 ;
} else {
V_197 &= ~ V_211 ;
V_194 = V_90 -> V_157 ;
}
V_198 &= ~ ( V_212 |
V_213 ) ;
V_198 |= V_209 [ V_191 ] . V_202 << V_214 ;
V_198 |= V_209 [ V_191 ] . V_215 << V_216 ;
F_11 ( V_88 -> V_2 , L_12 ,
V_209 [ V_191 ] . V_202 ,
V_209 [ V_191 ] . V_215 ,
V_209 [ V_191 ] . div ) ;
F_11 ( V_88 -> V_2 , L_13 , V_194 ) ;
V_189 = 0 ;
V_192 = ( ( V_194 * 10 ) / V_217 [ 0 ] . V_218 ) - V_188 ;
V_100 = 1 ;
while ( V_100 < F_12 ( V_217 ) ) {
V_193 = ( ( V_194 * 10 ) / V_217 [ V_100 ] . V_218 ) - V_188 ;
if ( V_193 < 0 )
break;
V_189 = V_100 ;
V_192 = V_193 ;
V_100 ++ ;
}
V_195 &= ~ V_219 ;
V_196 &= ~ V_220 ;
F_11 ( V_88 -> V_2 , L_14 ,
V_217 [ V_189 ] . V_218 / 10 , V_188 ,
( V_194 * 10 ) / V_217 [ V_189 ] . V_218 ) ;
V_195 |= V_217 [ V_189 ] . div ;
V_196 |= V_188 / V_121 ;
V_90 -> V_121 = F_30 ( V_186 ) ;
F_20 ( V_88 ) ;
F_13 ( V_88 , V_18 , V_197 ) ;
F_13 ( V_88 , V_19 , V_198 ) ;
F_13 ( V_88 , V_22 , V_159 ) ;
F_13 ( V_88 , V_23 , V_195 ) ;
F_13 ( V_88 , V_24 , V_196 ) ;
F_13 ( V_88 , V_28 , V_199 ) ;
return 0 ;
}
int F_32 ( struct V_87 * V_88 , struct V_221 * V_222 ,
int V_223 , int V_224 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_225 = V_226 | V_227 ;
F_11 ( V_88 -> V_2 , L_15 ,
V_223 , V_224 ) ;
V_90 -> V_228 = V_222 ;
V_90 -> V_229 = V_223 ;
V_90 -> V_230 = V_224 ;
if ( V_223 )
V_225 &= ~ V_226 ;
if ( V_224 )
V_225 &= ~ V_227 ;
F_8 ( V_88 , V_76 ,
V_226 | V_227 ,
V_225 ) ;
if ( V_223 || V_224 ) {
F_8 ( V_88 , V_64 ,
V_231 , V_231 ) ;
F_8 ( V_88 , V_8 ,
V_232 , V_232 ) ;
} else {
F_8 ( V_88 , V_8 ,
V_232 , 0 ) ;
}
return 0 ;
}
static T_2 F_33 ( int V_233 , void * V_234 )
{
struct V_89 * V_90 = V_234 ;
int V_235 , V_114 ;
unsigned int V_236 , V_237 , V_238 ;
V_114 = F_34 ( V_90 -> V_239 , V_76 ,
& V_237 ) ;
if ( V_114 != 0 ) {
F_35 ( V_90 -> V_2 , L_16 , V_114 ) ;
return V_240 ;
}
V_114 = F_34 ( V_90 -> V_239 , V_75 , & V_236 ) ;
if ( V_114 != 0 ) {
F_35 ( V_90 -> V_2 , L_17 , V_114 ) ;
return V_240 ;
}
V_236 &= ~ V_237 ;
if ( V_236 & V_241 ) {
F_36 ( V_90 -> V_2 , L_18 ) ;
}
V_235 = V_90 -> V_242 ;
V_114 = F_34 ( V_90 -> V_239 , V_77 ,
& V_238 ) ;
if ( V_114 != 0 ) {
F_35 ( V_90 -> V_2 , L_19 ,
V_114 ) ;
return V_243 ;
}
#ifndef F_37
if ( V_236 & ( V_227 | V_226 ) )
F_38 ( F_39 ( V_90 -> V_2 ) ) ;
#endif
if ( V_236 & V_227 ) {
F_11 ( V_90 -> V_2 , L_20 , V_238 ) ;
V_235 ^= V_90 -> V_230 ;
V_238 ^= V_244 ;
}
if ( V_236 & V_226 ) {
F_11 ( V_90 -> V_2 , L_21 , V_238 ) ;
V_235 ^= V_90 -> V_229 ;
V_238 ^= V_245 ;
F_14 ( V_90 -> V_246 ) ;
}
F_40 ( V_90 -> V_239 , V_77 ,
V_244 | V_245 , V_238 ) ;
F_41 ( V_90 -> V_228 , V_235 ,
V_90 -> V_230 | V_90 -> V_229 ) ;
V_90 -> V_242 = V_235 ;
return V_243 ;
}
static int F_42 ( struct V_87 * V_88 )
{
F_25 ( V_88 , V_136 ) ;
return 0 ;
}
static int F_43 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
F_44 ( V_90 -> V_239 ) ;
F_25 ( V_88 , V_134 ) ;
return 0 ;
}
static inline struct V_89 * F_45 ( struct V_247 * V_248 )
{
return F_10 ( V_248 , struct V_89 , V_247 ) ;
}
static int F_46 ( struct V_247 * V_248 , unsigned V_249 )
{
if ( V_249 >= V_250 )
return - V_126 ;
return 0 ;
}
static int F_47 ( struct V_247 * V_248 , unsigned V_249 )
{
struct V_89 * V_90 = F_45 ( V_248 ) ;
unsigned int V_237 , V_101 ;
int V_114 ;
V_237 = V_251 | V_252 ;
V_101 = ( V_253 << V_254 ) |
V_255 ;
V_114 = F_40 ( V_90 -> V_239 ,
V_70 + V_249 , V_237 , V_101 ) ;
if ( V_114 < 0 )
return V_114 ;
return 0 ;
}
static int F_48 ( struct V_247 * V_248 , unsigned V_249 )
{
struct V_89 * V_90 = F_45 ( V_248 ) ;
unsigned int V_3 ;
F_34 ( V_90 -> V_239 , V_70 + V_249 , & V_3 ) ;
return ( V_3 & V_256 ) >> V_257 ;
}
static int F_49 ( struct V_247 * V_248 ,
unsigned V_249 , int V_115 )
{
struct V_89 * V_90 = F_45 ( V_248 ) ;
unsigned int V_237 , V_101 ;
int V_114 ;
V_237 = V_251 | V_252 | V_256 ;
V_101 = ( V_258 << V_254 ) |
( V_115 << V_259 ) ;
V_114 = F_40 ( V_90 -> V_239 ,
V_70 + V_249 , V_237 , V_101 ) ;
if ( V_114 < 0 )
return V_114 ;
return 0 ;
}
static void F_50 ( struct V_247 * V_248 , unsigned V_249 , int V_115 )
{
struct V_89 * V_90 = F_45 ( V_248 ) ;
F_40 ( V_90 -> V_239 , V_70 + V_249 ,
V_256 ,
! ! V_115 << V_257 ) ;
}
static void F_51 ( struct V_89 * V_90 )
{
struct V_260 * V_261 = V_90 -> V_261 ;
int V_114 ;
V_90 -> V_247 = V_262 ;
V_90 -> V_247 . V_263 = V_250 ;
V_90 -> V_247 . V_2 = V_90 -> V_2 ;
if ( V_261 -> V_264 )
V_90 -> V_247 . V_265 = V_261 -> V_264 ;
else
V_90 -> V_247 . V_265 = - 1 ;
V_114 = F_52 ( & V_90 -> V_247 ) ;
if ( V_114 != 0 )
F_35 ( V_90 -> V_2 , L_22 , V_114 ) ;
}
static void F_53 ( struct V_89 * V_90 )
{
int V_114 ;
V_114 = F_54 ( & V_90 -> V_247 ) ;
if ( V_114 != 0 )
F_35 ( V_90 -> V_2 , L_23 , V_114 ) ;
}
static void F_51 ( struct V_89 * V_90 )
{
}
static void F_53 ( struct V_89 * V_90 )
{
}
static int F_55 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_114 ;
V_90 -> V_88 = V_88 ;
V_88 -> V_266 = V_90 -> V_239 ;
V_114 = F_56 ( V_88 , 8 , 16 , V_267 ) ;
if ( V_114 != 0 ) {
F_35 ( V_88 -> V_2 , L_24 , V_114 ) ;
return V_114 ;
}
F_25 ( V_88 , V_134 ) ;
return V_114 ;
}
static int F_57 ( struct V_87 * V_88 )
{
F_25 ( V_88 , V_136 ) ;
return 0 ;
}
static int F_58 ( struct V_268 * V_269 ,
struct V_260 * V_261 )
{
struct V_270 * V_270 = F_59 ( V_269 -> V_233 ) ;
if ( ! V_270 ) {
F_35 ( & V_269 -> V_2 , L_25 ,
V_269 -> V_233 ) ;
return - V_126 ;
}
switch ( F_60 ( V_270 ) ) {
case V_271 :
default:
case V_272 :
V_261 -> V_273 = false ;
break;
case V_274 :
V_261 -> V_273 = true ;
break;
}
return 0 ;
}
static int F_61 ( struct V_268 * V_269 ,
struct V_260 * V_261 )
{
const struct V_275 * V_276 = V_269 -> V_2 . V_277 ;
T_3 V_278 ;
int V_100 ;
if ( F_62 ( V_276 , L_26 , & V_278 ) >= 0 )
V_261 -> V_279 = V_278 ;
if ( F_62 ( V_276 , L_27 , & V_278 ) >= 0 )
V_261 -> V_280 = V_278 ;
if ( F_63 ( V_276 , L_28 , V_261 -> V_281 ,
F_12 ( V_261 -> V_281 ) ) >= 0 ) {
for ( V_100 = 0 ; V_100 < F_12 ( V_261 -> V_281 ) ; V_100 ++ ) {
if ( V_261 -> V_281 [ V_100 ] == 0 ) {
V_261 -> V_281 [ V_100 ] = V_282 ;
} else if ( V_261 -> V_281 [ V_100 ] == 0xffffffff ) {
V_261 -> V_281 [ V_100 ] = 0 ;
} else if ( V_261 -> V_281 [ V_100 ] > 0x7fff ) {
F_35 ( & V_269 -> V_2 , L_29 ,
V_100 , V_261 -> V_281 [ V_100 ] ) ;
return - V_126 ;
}
}
}
return 0 ;
}
static int F_64 ( struct V_268 * V_269 ,
const struct V_283 * V_284 )
{
struct V_260 * V_261 = F_65 ( & V_269 -> V_2 ) ;
struct V_89 * V_90 ;
int V_285 ;
bool V_286 = false ;
unsigned int V_101 , V_287 ;
int V_114 , V_100 ;
V_90 = F_66 ( & V_269 -> V_2 , sizeof( struct V_89 ) ,
V_288 ) ;
if ( V_90 == NULL )
return - V_289 ;
V_90 -> V_2 = & V_269 -> V_2 ;
V_90 -> V_239 = F_67 ( V_269 , & V_290 ) ;
if ( F_68 ( V_90 -> V_239 ) ) {
V_114 = F_69 ( V_90 -> V_239 ) ;
F_35 ( & V_269 -> V_2 , L_30 ,
V_114 ) ;
return V_114 ;
}
F_70 ( V_269 , V_90 ) ;
if ( V_261 ) {
V_90 -> V_261 = V_261 ;
} else {
V_90 -> V_261 = F_66 ( & V_269 -> V_2 ,
sizeof( struct V_260 ) ,
V_288 ) ;
if ( V_90 -> V_261 == NULL ) {
F_35 ( & V_269 -> V_2 , L_31 ) ;
return - V_289 ;
}
if ( V_269 -> V_233 ) {
V_114 = F_58 ( V_269 , V_90 -> V_261 ) ;
if ( V_114 != 0 )
return V_114 ;
}
if ( V_269 -> V_2 . V_277 ) {
V_114 = F_61 ( V_269 , V_90 -> V_261 ) ;
if ( V_114 != 0 )
return V_114 ;
}
}
V_261 = V_90 -> V_261 ;
V_114 = F_34 ( V_90 -> V_239 , V_4 , & V_101 ) ;
if ( V_114 != 0 ) {
F_35 ( & V_269 -> V_2 , L_32 , V_114 ) ;
goto V_291;
}
if ( V_101 != 0x8903 ) {
F_35 ( & V_269 -> V_2 , L_33 , V_101 ) ;
V_114 = - V_292 ;
goto V_291;
}
V_114 = F_34 ( V_90 -> V_239 , V_5 , & V_101 ) ;
if ( V_114 != 0 ) {
F_35 ( & V_269 -> V_2 , L_34 , V_114 ) ;
goto V_291;
}
F_71 ( & V_269 -> V_2 , L_35 ,
( V_101 & V_293 ) + 'A' ) ;
F_72 ( V_90 -> V_239 , V_4 , 0x8903 ) ;
F_51 ( V_90 ) ;
for ( V_100 = 0 ; V_100 < F_12 ( V_261 -> V_281 ) ; V_100 ++ ) {
if ( ( ! V_261 -> V_281 [ V_100 ] ) ||
( V_261 -> V_281 [ V_100 ] > V_282 ) )
continue;
F_72 ( V_90 -> V_239 , V_70 + V_100 ,
V_261 -> V_281 [ V_100 ] & 0x7fff ) ;
V_101 = ( V_261 -> V_281 [ V_100 ] & V_251 )
>> V_254 ;
switch ( V_101 ) {
case V_294 :
case V_295 :
V_286 = true ;
break;
default:
break;
}
}
F_72 ( V_90 -> V_239 , V_8 ,
V_261 -> V_279 ) ;
if ( V_261 -> V_279 )
F_40 ( V_90 -> V_239 , V_64 ,
V_231 , V_231 ) ;
F_4 ( ! V_286 && ( V_261 -> V_279 & V_232 ) ) ;
V_90 -> V_246 = V_261 -> V_280 ;
if ( V_269 -> V_233 ) {
if ( V_261 -> V_273 ) {
V_285 = V_296 ;
V_287 = V_297 ;
} else {
V_285 = V_298 ;
V_287 = 0 ;
}
F_40 ( V_90 -> V_239 , V_78 ,
V_297 , V_287 ) ;
V_114 = F_73 ( V_269 -> V_233 , NULL , F_33 ,
V_285 | V_299 ,
L_36 , V_90 ) ;
if ( V_114 != 0 ) {
F_35 ( V_90 -> V_2 , L_37 ,
V_114 ) ;
return V_114 ;
}
F_40 ( V_90 -> V_239 ,
V_76 ,
V_300 , 0 ) ;
}
F_40 ( V_90 -> V_239 , V_29 ,
V_301 , V_301 ) ;
F_40 ( V_90 -> V_239 , V_30 ,
V_301 , V_301 ) ;
F_40 ( V_90 -> V_239 , V_25 ,
V_302 , V_302 ) ;
F_40 ( V_90 -> V_239 , V_26 ,
V_302 , V_302 ) ;
F_40 ( V_90 -> V_239 , V_47 ,
V_303 , V_303 ) ;
F_40 ( V_90 -> V_239 , V_48 ,
V_303 , V_303 ) ;
F_40 ( V_90 -> V_239 , V_49 ,
V_304 , V_304 ) ;
F_40 ( V_90 -> V_239 , V_50 ,
V_304 , V_304 ) ;
F_40 ( V_90 -> V_239 , V_51 ,
V_305 , V_305 ) ;
F_40 ( V_90 -> V_239 , V_52 ,
V_305 , V_305 ) ;
F_40 ( V_90 -> V_239 , V_28 ,
V_306 | V_182 ,
V_306 | V_182 ) ;
V_114 = F_74 ( & V_269 -> V_2 ,
& V_307 , & V_308 , 1 ) ;
if ( V_114 != 0 )
goto V_291;
return 0 ;
V_291:
return V_114 ;
}
static int F_75 ( struct V_268 * V_309 )
{
struct V_89 * V_90 = F_76 ( V_309 ) ;
if ( V_309 -> V_233 )
F_77 ( V_309 -> V_233 , V_90 ) ;
F_53 ( V_90 ) ;
F_78 ( & V_309 -> V_2 ) ;
return 0 ;
}
