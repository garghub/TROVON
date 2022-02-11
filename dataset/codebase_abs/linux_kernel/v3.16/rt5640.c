static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static bool F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ )
if ( ( V_6 >= V_8 [ V_7 ] . V_9 &&
V_6 <= V_8 [ V_7 ] . V_9 +
V_8 [ V_7 ] . V_10 ) ||
( V_6 >= V_8 [ V_7 ] . V_11 &&
V_6 <= V_8 [ V_7 ] . V_12 ) )
return true ;
switch ( V_6 ) {
case V_3 :
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
return true ;
default:
return false ;
}
}
static bool F_5 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ )
if ( ( V_6 >= V_8 [ V_7 ] . V_9 &&
V_6 <= V_8 [ V_7 ] . V_9 +
V_8 [ V_7 ] . V_10 ) ||
( V_6 >= V_8 [ V_7 ] . V_11 &&
V_6 <= V_8 [ V_7 ] . V_12 ) )
return true ;
switch ( V_6 ) {
case V_3 :
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
case V_21 :
case V_22 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_13 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_14 :
case V_95 :
case V_96 :
case V_15 :
case V_97 :
case V_98 :
case V_99 :
case V_16 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_17 :
case V_18 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_19 :
case V_20 :
case V_109 :
case V_23 :
case V_110 :
case V_24 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_25 :
case V_26 :
case V_27 :
return true ;
default:
return false ;
}
}
static int F_6 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
int V_134 = - V_135 ;
V_134 = F_8 ( V_133 -> V_136 ) ;
if ( V_134 < 0 )
F_9 ( V_2 -> V_5 , L_1 ) ;
else
F_10 ( V_2 , V_78 , V_137 ,
V_134 << V_138 ) ;
return V_134 ;
}
static int F_11 ( struct V_127 * V_139 ,
struct V_127 * V_140 )
{
unsigned int V_141 ;
V_141 = F_12 ( V_139 -> V_2 , V_79 ) ;
V_141 &= V_142 ;
if ( V_141 == V_143 )
return 1 ;
else
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
F_14 ( V_133 -> V_144 , V_145 +
V_146 , 0x0700 , 0x0200 ) ;
F_14 ( V_133 -> V_144 , V_90 ,
V_147 , V_148 ) ;
F_14 ( V_133 -> V_144 , V_89 ,
V_149 | V_150 | V_151 ,
V_152 | V_153 | V_154 ) ;
F_15 ( V_133 -> V_144 , V_145 + V_155 ,
0x9f00 ) ;
F_14 ( V_133 -> V_144 , V_70 ,
V_156 | V_157 , 0 ) ;
F_14 ( V_133 -> V_144 , V_70 ,
V_158 ,
V_158 ) ;
F_16 ( 10000 , 15000 ) ;
F_14 ( V_133 -> V_144 , V_70 ,
V_156 | V_157 ,
V_156 | V_157 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
F_14 ( V_133 -> V_144 , V_90 ,
V_147 | V_159 ,
V_160 | V_161 ) ;
F_14 ( V_133 -> V_144 , V_92 ,
V_162 , V_163 ) ;
F_14 ( V_133 -> V_144 , V_91 ,
V_164 | V_165 | V_166 ,
( V_167 << V_168 ) |
( V_169 << V_170 ) |
( V_167 << V_171 ) ) ;
F_15 ( V_133 -> V_144 , V_145 +
V_172 , 0x1c00 ) ;
F_14 ( V_133 -> V_144 , V_89 ,
V_149 | V_150 ,
V_173 | V_174 ) ;
F_14 ( V_133 -> V_144 , V_145 +
V_146 , 0x0700 , 0x0400 ) ;
}
static int F_18 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
switch ( V_131 ) {
case V_175 :
F_17 ( V_2 ) ;
V_133 -> V_176 = 0 ;
break;
case V_177 :
V_133 -> V_176 = 1 ;
F_16 ( 70000 , 75000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_19 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
switch ( V_131 ) {
case V_175 :
F_13 ( V_2 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
switch ( V_131 ) {
case V_175 :
if ( ! V_133 -> V_176 )
F_16 ( 80000 , 85000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_178 )
{
int V_179 = 0 , V_141 ;
if ( V_2 == NULL )
return - V_135 ;
V_141 = F_12 ( V_2 , V_74 ) ;
V_141 = ( V_141 & V_180 ) >> V_181 ;
switch ( V_178 ) {
case V_182 :
switch ( V_141 ) {
case V_183 :
case V_184 :
V_179 |= V_185 ;
break;
case V_186 :
V_179 |= V_185 ;
case V_187 :
case V_188 :
V_179 |= V_189 ;
break;
}
break;
case V_190 :
switch ( V_141 ) {
case V_191 :
case V_188 :
V_179 |= V_185 ;
break;
case V_192 :
V_179 |= V_185 ;
case V_183 :
case V_193 :
V_179 |= V_189 ;
break;
}
break;
default:
V_179 = - V_135 ;
break;
}
return V_179 ;
}
static int F_22 ( struct V_194 * V_195 ,
struct V_196 * V_197 , struct V_198 * V_199 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_200 = 0 , V_201 , V_202 ;
int V_203 , V_204 , V_205 , V_206 ;
V_133 -> V_207 [ V_199 -> V_208 ] = F_23 ( V_197 ) ;
V_204 = F_24 ( V_133 -> V_136 , V_133 -> V_207 [ V_199 -> V_208 ] ) ;
if ( V_204 < 0 ) {
F_9 ( V_2 -> V_5 , L_2 ,
V_133 -> V_207 [ V_199 -> V_208 ] , V_199 -> V_208 ) ;
return - V_135 ;
}
V_206 = F_25 ( V_197 ) ;
if ( V_206 < 0 ) {
F_9 ( V_2 -> V_5 , L_3 , V_206 ) ;
return V_206 ;
}
if ( V_206 > 32 )
V_205 = 1 ;
else
V_205 = 0 ;
V_133 -> V_209 [ V_199 -> V_208 ] = V_133 -> V_207 [ V_199 -> V_208 ] * ( 32 << V_205 ) ;
F_26 ( V_199 -> V_5 , L_4 ,
V_133 -> V_209 [ V_199 -> V_208 ] , V_133 -> V_207 [ V_199 -> V_208 ] ) ;
F_26 ( V_199 -> V_5 , L_5 ,
V_205 , V_204 , V_199 -> V_208 ) ;
switch ( F_27 ( V_197 ) ) {
case 16 :
break;
case 20 :
V_200 |= V_210 ;
break;
case 24 :
V_200 |= V_211 ;
break;
case 8 :
V_200 |= V_212 ;
break;
default:
return - V_135 ;
}
V_203 = F_21 ( V_2 , V_199 -> V_208 ) ;
if ( V_203 < 0 ) {
F_9 ( V_2 -> V_5 , L_6 , V_203 ) ;
return - V_135 ;
}
if ( V_203 & V_185 ) {
V_202 = V_213 | V_214 ;
V_201 = V_205 << V_215 |
V_204 << V_216 ;
F_10 ( V_2 , V_74 ,
V_217 , V_200 ) ;
F_10 ( V_2 , V_76 , V_202 , V_201 ) ;
}
if ( V_203 & V_189 ) {
V_202 = V_218 | V_219 ;
V_201 = V_205 << V_220 |
V_204 << V_221 ;
F_10 ( V_2 , V_75 ,
V_217 , V_200 ) ;
F_10 ( V_2 , V_76 , V_202 , V_201 ) ;
}
return 0 ;
}
static int F_28 ( struct V_198 * V_199 , unsigned int V_222 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_223 = 0 ;
int V_203 ;
switch ( V_222 & V_224 ) {
case V_225 :
V_133 -> V_226 [ V_199 -> V_208 ] = 1 ;
break;
case V_227 :
V_223 |= V_228 ;
V_133 -> V_226 [ V_199 -> V_208 ] = 0 ;
break;
default:
return - V_135 ;
}
switch ( V_222 & V_229 ) {
case V_230 :
break;
case V_231 :
V_223 |= V_232 ;
break;
default:
return - V_135 ;
}
switch ( V_222 & V_233 ) {
case V_234 :
break;
case V_235 :
V_223 |= V_236 ;
break;
case V_237 :
V_223 |= V_238 ;
break;
case V_239 :
V_223 |= V_240 ;
break;
default:
return - V_135 ;
}
V_203 = F_21 ( V_2 , V_199 -> V_208 ) ;
if ( V_203 < 0 ) {
F_9 ( V_2 -> V_5 , L_6 , V_203 ) ;
return - V_135 ;
}
if ( V_203 & V_185 ) {
F_10 ( V_2 , V_74 ,
V_241 | V_242 |
V_243 , V_223 ) ;
}
if ( V_203 & V_189 ) {
F_10 ( V_2 , V_75 ,
V_241 | V_242 |
V_243 , V_223 ) ;
}
return 0 ;
}
static int F_29 ( struct V_198 * V_199 ,
int V_244 , unsigned int V_245 , int V_246 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_223 = 0 ;
if ( V_245 == V_133 -> V_136 && V_244 == V_133 -> V_247 )
return 0 ;
switch ( V_244 ) {
case V_248 :
V_223 |= V_249 ;
break;
case V_250 :
V_223 |= V_143 ;
break;
default:
F_9 ( V_2 -> V_5 , L_7 , V_244 ) ;
return - V_135 ;
}
F_10 ( V_2 , V_79 ,
V_142 , V_223 ) ;
V_133 -> V_136 = V_245 ;
V_133 -> V_247 = V_244 ;
F_26 ( V_199 -> V_5 , L_8 , V_245 , V_244 ) ;
return 0 ;
}
static int F_30 ( struct V_198 * V_199 , int V_251 , int V_139 ,
unsigned int V_252 , unsigned int V_253 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
struct V_254 V_255 ;
int V_179 , V_203 ;
if ( V_139 == V_133 -> V_256 && V_252 == V_133 -> V_257 &&
V_253 == V_133 -> V_258 )
return 0 ;
if ( ! V_252 || ! V_253 ) {
F_26 ( V_2 -> V_5 , L_9 ) ;
V_133 -> V_257 = 0 ;
V_133 -> V_258 = 0 ;
F_10 ( V_2 , V_79 ,
V_142 , V_249 ) ;
return 0 ;
}
switch ( V_139 ) {
case V_259 :
F_10 ( V_2 , V_79 ,
V_260 , V_261 ) ;
break;
case V_262 :
case V_263 :
V_203 = F_21 ( V_2 , V_199 -> V_208 ) ;
if ( V_203 < 0 ) {
F_9 ( V_2 -> V_5 ,
L_6 , V_203 ) ;
return - V_135 ;
}
if ( V_203 & V_185 ) {
F_10 ( V_2 , V_79 ,
V_260 , V_264 ) ;
}
if ( V_203 & V_189 ) {
F_10 ( V_2 , V_79 ,
V_260 , V_265 ) ;
}
break;
default:
F_9 ( V_2 -> V_5 , L_10 , V_139 ) ;
return - V_135 ;
}
V_179 = F_31 ( V_252 , V_253 , & V_255 ) ;
if ( V_179 < 0 ) {
F_9 ( V_2 -> V_5 , L_11 , V_252 ) ;
return V_179 ;
}
F_26 ( V_2 -> V_5 , L_12 ,
V_255 . V_266 , ( V_255 . V_266 ? 0 : V_255 . V_267 ) ,
V_255 . V_268 , V_255 . V_269 ) ;
F_2 ( V_2 , V_80 ,
V_255 . V_268 << V_270 | V_255 . V_269 ) ;
F_2 ( V_2 , V_81 ,
( V_255 . V_266 ? 0 : V_255 . V_267 ) << V_271 |
V_255 . V_266 << V_272 ) ;
V_133 -> V_257 = V_252 ;
V_133 -> V_258 = V_253 ;
V_133 -> V_256 = V_139 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
enum V_273 V_274 )
{
switch ( V_274 ) {
case V_275 :
if ( V_276 == V_2 -> V_277 . V_278 ) {
F_10 ( V_2 , V_70 ,
V_279 | V_280 |
V_281 | V_282 ,
V_279 | V_280 |
V_281 | V_282 ) ;
F_16 ( 10000 , 15000 ) ;
F_10 ( V_2 , V_70 ,
V_156 | V_157 ,
V_156 | V_157 ) ;
F_10 ( V_2 , V_124 ,
0x0301 , 0x0301 ) ;
F_10 ( V_2 , V_94 ,
0x0030 , 0x0030 ) ;
}
break;
case V_276 :
F_2 ( V_2 , V_89 , 0x0004 ) ;
F_2 ( V_2 , V_90 , 0x1100 ) ;
F_10 ( V_2 , V_124 , 0x1 , 0 ) ;
F_2 ( V_2 , V_68 , 0x0000 ) ;
F_2 ( V_2 , V_69 , 0x0000 ) ;
F_2 ( V_2 , V_73 , 0x0000 ) ;
F_2 ( V_2 , V_72 , 0x0000 ) ;
F_2 ( V_2 , V_70 , 0x0000 ) ;
F_2 ( V_2 , V_71 , 0x0000 ) ;
break;
default:
break;
}
V_2 -> V_277 . V_278 = V_274 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
V_133 -> V_2 = V_2 ;
F_32 ( V_2 , V_276 ) ;
F_10 ( V_2 , V_124 , 0x0301 , 0x0301 ) ;
F_10 ( V_2 , V_94 , 0x0030 , 0x0030 ) ;
F_10 ( V_2 , V_48 , 0xfc00 , 0x0c00 ) ;
switch ( F_12 ( V_2 , V_3 ) & V_283 ) {
case V_284 :
case V_285 :
F_34 ( V_2 ,
V_286 ,
F_4 ( V_286 ) ) ;
F_35 ( & V_2 -> V_277 ,
V_287 ,
F_4 ( V_287 ) ) ;
F_36 ( & V_2 -> V_277 ,
V_288 ,
F_4 ( V_288 ) ) ;
break;
case V_289 :
F_35 ( & V_2 -> V_277 ,
V_290 ,
F_4 ( V_290 ) ) ;
F_36 ( & V_2 -> V_277 ,
V_291 ,
F_4 ( V_291 ) ) ;
break;
default:
F_9 ( V_2 -> V_5 ,
L_13 ) ;
return - V_292 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
F_32 ( V_2 , V_276 ) ;
F_1 ( V_2 ) ;
F_39 ( V_133 -> V_144 , true ) ;
F_40 ( V_133 -> V_144 ) ;
if ( F_41 ( V_133 -> V_293 . V_294 ) )
F_42 ( V_133 -> V_293 . V_294 , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
if ( F_41 ( V_133 -> V_293 . V_294 ) ) {
F_42 ( V_133 -> V_293 . V_294 , 1 ) ;
F_44 ( 400 ) ;
}
F_39 ( V_133 -> V_144 , false ) ;
F_45 ( V_133 -> V_144 ) ;
return 0 ;
}
static int F_46 ( struct V_132 * V_133 , struct V_295 * V_296 )
{
V_133 -> V_293 . V_297 = F_47 ( V_296 ,
L_14 ) ;
V_133 -> V_293 . V_298 = F_47 ( V_296 ,
L_15 ) ;
V_133 -> V_293 . V_294 = F_48 ( V_296 ,
L_16 , 0 ) ;
if ( ! F_41 ( V_133 -> V_293 . V_294 ) &&
( V_133 -> V_293 . V_294 != - V_299 ) )
return V_133 -> V_293 . V_294 ;
return 0 ;
}
static int F_49 ( struct V_300 * V_301 ,
const struct V_302 * V_208 )
{
struct V_303 * V_293 = F_50 ( & V_301 -> V_5 ) ;
struct V_132 * V_133 ;
int V_179 ;
unsigned int V_141 ;
V_133 = F_51 ( & V_301 -> V_5 ,
sizeof( struct V_132 ) ,
V_304 ) ;
if ( NULL == V_133 )
return - V_305 ;
F_52 ( V_301 , V_133 ) ;
if ( V_293 ) {
V_133 -> V_293 = * V_293 ;
if ( ! V_133 -> V_293 . V_294 )
V_133 -> V_293 . V_294 = - V_135 ;
} else if ( V_301 -> V_5 . V_306 ) {
V_179 = F_46 ( V_133 , V_301 -> V_5 . V_306 ) ;
if ( V_179 )
return V_179 ;
} else
V_133 -> V_293 . V_294 = - V_135 ;
V_133 -> V_144 = F_53 ( V_301 , & V_307 ) ;
if ( F_54 ( V_133 -> V_144 ) ) {
V_179 = F_55 ( V_133 -> V_144 ) ;
F_9 ( & V_301 -> V_5 , L_17 ,
V_179 ) ;
return V_179 ;
}
if ( F_41 ( V_133 -> V_293 . V_294 ) ) {
V_179 = F_56 ( & V_301 -> V_5 , V_133 -> V_293 . V_294 ,
V_308 ,
L_18 ) ;
if ( V_179 < 0 ) {
F_9 ( & V_301 -> V_5 , L_19 ,
V_133 -> V_293 . V_294 , V_179 ) ;
return V_179 ;
}
F_44 ( 400 ) ;
}
F_57 ( V_133 -> V_144 , V_27 , & V_141 ) ;
if ( V_141 != V_309 ) {
F_9 ( & V_301 -> V_5 ,
L_20 , V_141 ) ;
return - V_292 ;
}
F_15 ( V_133 -> V_144 , V_3 , 0 ) ;
V_179 = F_58 ( V_133 -> V_144 , V_310 ,
F_4 ( V_310 ) ) ;
if ( V_179 != 0 )
F_59 ( & V_301 -> V_5 , L_21 , V_179 ) ;
if ( V_133 -> V_293 . V_297 )
F_14 ( V_133 -> V_144 , V_32 ,
V_311 , V_311 ) ;
if ( V_133 -> V_293 . V_298 )
F_14 ( V_133 -> V_144 , V_33 ,
V_312 , V_312 ) ;
if ( V_133 -> V_293 . V_313 ) {
F_14 ( V_133 -> V_144 , V_105 ,
V_314 , V_315 ) ;
if ( V_133 -> V_293 . V_316 ) {
F_14 ( V_133 -> V_144 , V_78 ,
V_317 , V_318 ) ;
F_14 ( V_133 -> V_144 , V_105 ,
V_319 , V_320 ) ;
}
if ( V_133 -> V_293 . V_321 ) {
F_14 ( V_133 -> V_144 , V_78 ,
V_322 , V_323 ) ;
F_14 ( V_133 -> V_144 , V_105 ,
V_324 , V_325 ) ;
}
}
V_133 -> V_176 = 1 ;
V_179 = F_60 ( & V_301 -> V_5 , & V_326 ,
V_327 , F_4 ( V_327 ) ) ;
if ( V_179 < 0 )
goto V_328;
return 0 ;
V_328:
return V_179 ;
}
static int F_61 ( struct V_300 * V_301 )
{
F_62 ( & V_301 -> V_5 ) ;
return 0 ;
}
