int F_1 ( T_1 V_1 )
{
return ( V_1 >= V_2 ) &&
( V_1 < V_3 ) ;
}
int F_2 ( struct V_4 * V_5 )
{
struct V_6 V_7 ;
T_2 V_8 ;
if ( F_3 ( F_4 ( V_9 , & V_5 -> V_10 -> V_11 ) ,
L_1 ) )
return - V_12 ;
V_7 . V_13 = ( V_14 ) ( 2 * V_5 -> V_15 ) ;
if ( V_5 -> V_16 &&
V_5 -> V_16 < V_7 . V_13 ) {
V_7 . V_13 = V_5 -> V_16 ;
}
V_7 . V_17 = V_18 ;
V_7 . V_19 = V_20 ;
if ( F_5 ( V_5 -> V_21 ) == 1 )
V_8 = V_22 ;
else
V_8 = V_23 ;
return F_6 ( F_7 ( V_5 ) , V_8 , V_24 ,
sizeof( V_7 ) , & V_7 ) ;
}
void F_8 ( struct V_4 * V_5 )
{
V_5 -> V_25 = F_9 ( V_5 -> V_26 . V_27 . V_25 ) ;
F_10 ( V_5 ) ;
}
T_3 F_11 ( struct V_28 * V_10 )
{
struct V_29 * V_30 ;
V_30 = (struct V_29 * ) F_12 ( V_10 ,
V_31 ) ;
return V_30 -> V_32 ;
}
static T_1 F_13 ( const struct V_28 * V_10 , T_1 V_33 )
{
T_3 V_34 = 0 ;
if ( ( V_33 & V_35 ) == 0 )
return V_33 ;
switch ( V_33 & V_36 ) {
case V_37 :
V_34 = F_14 ( V_10 , V_38 ) ;
break;
case V_39 :
V_34 = F_14 ( V_10 , V_40 ) ;
break;
case V_41 :
V_34 = F_14 ( V_10 , V_42 ) ;
break;
case V_43 :
V_34 = F_14 ( V_10 , V_44 ) ;
break;
case V_45 :
V_34 = F_14 ( V_10 , V_46 ) ;
break;
case V_47 :
V_34 = F_14 ( V_10 , V_48 ) ;
break;
case V_49 :
V_34 = F_14 ( V_10 , V_50 ) ;
break;
case V_51 :
V_34 = F_14 ( V_10 , V_52 ) ;
break;
default:
F_15 ( V_10 -> F_7 , L_2 ,
V_33 & V_36 ) ;
break;
}
return ( V_33 & V_53 ) + ( V_34 << 1 ) ;
}
const T_2 * F_12 ( const struct V_28 * V_10 , T_4 V_34 )
{
T_1 V_33 = F_13 ( V_10 , V_34 ) ;
F_16 ( V_33 >= V_10 -> V_54 -> V_55 -> V_56 ) ;
return & V_10 -> V_57 [ V_33 ] ;
}
int F_17 ( T_1 V_58 , enum V_59 V_60 )
{
int V_61 = 0 ;
int V_62 = 0 ;
if ( V_58 & V_63 ) {
V_61 = ( V_58 & 0xff ) ;
return V_61 ;
} else {
if ( V_60 == V_64 )
V_62 = V_65 ;
for ( V_61 = V_62 ; V_61 < V_66 ; V_61 ++ )
if ( V_67 [ V_61 ] . V_68 == ( V_58 & 0xFF ) )
return V_61 - V_62 ;
}
return - 1 ;
}
int F_18 ( struct V_4 * V_5 ,
struct V_69 * V_70 , bool V_71 )
{
struct V_72 * V_73 = ( void * ) V_70 -> V_74 ;
if ( V_71 )
return F_19 ( V_5 , V_73 -> V_75 ,
V_70 -> V_76 . V_77 ,
& V_73 -> V_78 ) ;
return F_20 ( V_5 , V_73 -> V_78 ,
V_70 -> V_76 . V_77 ) ;
}
int F_21 ( struct V_4 * V_5 , T_3 V_79 )
{
struct V_80 V_81 ;
struct V_82 V_83 = {
. V_84 = V_85 ,
. V_86 = { sizeof( struct V_80 ) , } ,
. V_17 = V_24 ,
. V_87 = { & V_81 , } ,
} ;
F_22 () ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
if ( V_79 & F_23 ( V_88 ) )
V_81 . V_89 = V_90 | V_91 |
V_92 | V_93 |
V_94 ;
if ( ( V_79 & F_23 ( V_95 ) ) &&
( V_5 -> V_10 -> V_96 != F_23 ( V_88 ) ) )
V_81 . V_89 |= V_97 |
V_98 | V_99 |
V_100 | V_101 |
V_102 ;
if ( V_54 ( V_5 ) -> V_103 & V_104 )
V_81 . V_89 |= V_105 ;
F_24 ( V_5 , L_3 ,
V_81 . V_89 ) ;
V_81 . V_79 = F_25 ( V_79 ) ;
return F_26 ( F_7 ( V_5 ) , & V_83 ) ;
}
void F_27 ( struct V_4 * V_5 , T_3 V_79 )
{
F_28 ( & V_5 -> V_10 -> V_106 ) ;
F_29 ( V_5 -> V_107 ) ;
if ( F_21 ( V_5 , V_108 ) ) {
F_15 ( V_5 , L_4 ) ;
goto V_109;
}
F_24 ( V_5 , L_5 ) ;
F_30 ( F_7 ( V_5 ) ) ;
V_109:
F_31 ( V_5 -> V_107 ) ;
F_32 ( & V_5 -> V_10 -> V_106 ) ;
}
void F_33 ( struct V_4 * V_5 )
{
struct V_110 V_111 = {
. V_112 = V_113 ,
. V_114 = V_115 ,
. V_116 = V_117 ,
. V_118 = V_119 ,
} ;
struct V_120 V_121 ;
struct V_122 V_123 ;
int V_124 ;
F_34 ( sizeof( V_125 ) !=
sizeof( V_111 . V_126 ) ) ;
if ( V_54 ( V_5 ) -> V_127 ) {
if ( V_54 ( V_5 ) -> V_127 -> V_128 ) {
V_123 . V_129 = F_35 (
V_54 ( V_5 ) -> V_127 -> V_130 ) ;
V_123 . V_131 = 0 ;
V_123 . V_132 = 0 ;
} else {
V_121 . V_129 =
V_54 ( V_5 ) -> V_127 -> V_130 ;
V_121 . V_131 = 0 ;
V_121 . V_132 = 0 ;
}
} else {
F_15 ( V_5 , L_6 ) ;
return;
}
V_111 . V_133 = V_5 -> V_133 ;
V_111 . V_134 = V_5 -> V_134 ;
V_111 . V_135 = V_5 -> V_136 ;
if ( ! V_137 . V_138 ||
V_5 -> V_139 == V_140 ) {
V_111 . V_17 = V_141 ;
} else {
V_111 . V_17 = V_142 <<
V_143 ;
if ( ! V_5 -> V_144 )
V_111 . V_17 |= V_145 ;
else
V_111 . V_17 &= ~ V_145 ;
if ( V_5 -> V_146 )
V_111 . V_17 |= V_147 ;
F_36 ( V_5 , L_7 , V_111 . V_17 ) ;
}
V_5 -> V_148 = V_111 . V_17 ;
if ( V_5 -> V_149 )
memcpy ( V_111 . V_126 , V_150 ,
sizeof( V_150 ) ) ;
else
memcpy ( V_111 . V_126 , V_125 ,
sizeof( V_125 ) ) ;
F_36 ( V_5 , L_8 ,
V_111 . V_17 ? L_9 : L_10 ,
V_5 -> V_149 ?
L_11 : L_12 ) ;
if ( V_54 ( V_5 ) -> V_127 -> V_128 ) {
memcpy ( & V_123 . V_111 , & V_111 ,
sizeof( V_111 ) ) ;
V_124 = F_6 ( F_7 ( V_5 ) , V_151 ,
V_24 , sizeof( V_123 ) , & V_123 ) ;
} else {
memcpy ( & V_121 . V_111 , & V_111 ,
sizeof( V_111 ) ) ;
V_124 = F_6 ( F_7 ( V_5 ) , V_151 ,
V_24 , sizeof( V_121 ) , & V_121 ) ;
}
if ( V_124 )
F_15 ( V_5 , L_13 ) ;
}
void F_37 ( struct V_4 * V_5 , bool V_152 )
{
struct V_153 * V_75 , * V_154 = NULL ;
bool V_155 = false ;
F_38 ( & V_5 -> V_10 -> V_106 ) ;
if ( V_152 ) {
F_39 (priv, ctx) {
if ( V_75 -> V_70 && V_75 -> V_70 -> type == V_156 &&
F_40 ( V_75 ) ) {
V_155 = true ;
break;
}
}
}
if ( ! V_152 || V_155 ) {
if ( V_5 -> V_157 ) {
V_75 = V_5 -> V_157 ;
F_41 ( V_75 -> V_70 ) ;
V_5 -> V_157 = NULL ;
}
return;
}
F_39 (priv, ctx) {
if ( V_75 -> V_70 && V_75 -> V_70 -> type == V_158 &&
F_40 ( V_75 ) ) {
V_154 = V_75 ;
break;
}
}
if ( V_154 == V_5 -> V_157 )
return;
if ( V_5 -> V_157 ) {
V_75 = V_5 -> V_157 ;
if ( V_75 -> V_70 )
F_41 ( V_75 -> V_70 ) ;
}
V_5 -> V_157 = V_154 ;
if ( ! V_154 )
return;
F_42 ( V_154 -> V_70 ,
V_159 ,
V_160 ) ;
}
static bool F_43 ( struct V_161 * V_162 )
{
return V_163 & V_162 -> V_164 >>
V_165 ;
}
static void F_44 ( struct V_166 * V_167 )
{
struct V_4 * V_5 =
F_45 ( V_167 , struct V_4 , V_168 ) ;
struct V_153 * V_75 ;
int V_169 = - 1 ;
if ( V_5 -> V_148 == V_141 ) {
return;
}
F_36 ( V_5 , L_14 ,
V_5 -> V_170 ) ;
switch ( V_5 -> V_170 ) {
case V_171 :
if ( V_5 -> V_172 )
V_169 = V_173 ;
else
V_169 = V_174 ;
break;
case V_175 :
V_169 = V_173 ;
break;
case V_176 :
case V_177 :
V_169 = V_178 ;
break;
default:
F_15 ( V_5 , L_15 ,
V_5 -> V_170 ) ;
break;
}
F_28 ( & V_5 -> V_10 -> V_106 ) ;
if ( F_4 ( V_9 , & V_5 -> V_10 -> V_11 ) )
goto V_179;
F_46 ( V_5 ) ;
if ( V_169 != - 1 ) {
V_5 -> V_180 . V_181 = V_169 ;
F_39 (priv, ctx) {
if ( V_75 -> V_70 && V_75 -> V_70 -> type == V_158 )
F_47 ( V_75 -> V_70 , V_169 ) ;
}
}
F_48 ( V_5 ) ;
V_179:
F_32 ( & V_5 -> V_10 -> V_106 ) ;
}
void F_48 ( struct V_4 * V_5 )
{
if ( V_5 -> V_182 &&
V_5 -> V_170 == V_177 )
F_37 ( V_5 , true ) ;
else
F_37 ( V_5 , false ) ;
}
static void F_49 ( struct V_4 * V_5 ,
struct V_161 * V_162 )
{
F_36 ( V_5 , L_16
L_17 ,
( V_183 & V_162 -> V_184 ) >>
V_185 ,
( V_186 & V_162 -> V_184 ) >>
V_187 ,
( V_188 & V_162 -> V_184 ) >>
V_189 ) ;
F_36 ( V_5 , L_18
L_19 ,
( V_190 & V_162 -> V_191 ) >>
V_192 ,
( V_193 & V_162 -> V_191 ) >>
V_194 ,
( V_195 & V_162 -> V_191 ) >>
V_196 ,
( V_197 & V_162 -> V_191 ) >>
V_198 ) ;
F_36 ( V_5 , L_20
L_21 ,
( V_163 & V_162 -> V_164 ) >>
V_165 ,
( V_199 & V_162 -> V_164 ) >>
V_200 ,
( V_201 & V_162 -> V_164 ) >>
V_202 ,
( V_203 & V_162 -> V_164 ) >>
V_204 ,
( V_205 & V_162 -> V_164 ) >>
V_206 ,
( V_207 & V_162 -> V_164 ) >>
V_208 ) ;
F_36 ( V_5 , L_22 ,
( V_209 & V_162 -> V_210 ) >>
V_211 ) ;
F_36 ( V_5 , L_23
L_24 ,
( V_212 & V_162 -> V_213 ) >>
V_214 ,
( V_215 & V_162 -> V_213 ) >>
V_216 ,
( V_217 & V_162 -> V_213 ) >>
V_218 ) ;
F_36 ( V_5 , L_25 ,
( V_219 & V_162 -> V_220 ) >>
V_221 ,
( V_222 & V_162 -> V_220 ) >>
V_223 ) ;
F_36 ( V_5 , L_26
L_27 ,
( V_224 & V_162 -> V_225 ) >>
V_226 ,
( V_227 & V_162 -> V_225 ) >>
V_228 ,
( V_229 & V_162 -> V_225 ) >>
V_230 ,
( V_231 & V_162 -> V_225 ) >>
V_232 ) ;
}
static void F_50 ( struct V_4 * V_5 ,
struct V_161 * V_162 )
{
T_2 V_233 ;
static const T_5 V_234 [ 2 ] = {
V_235 ,
V_236 } ;
static const T_5 V_237 [ 2 ] = {
V_238 ,
V_236 } ;
V_233 = ( V_163 & V_162 -> V_164 )
? 1 : 0 ;
if ( V_5 -> V_133 != V_234 [ V_233 ] ||
V_5 -> V_134 != V_237 [ V_233 ] ) {
V_5 -> V_136 |= V_239 ;
V_5 -> V_133 = V_234 [ V_233 ] ;
V_5 -> V_136 |= V_240 ;
V_5 -> V_134 = V_237 [ V_233 ] ;
F_51 ( V_5 -> V_10 -> V_241 , & V_5 -> V_242 ) ;
}
}
int F_52 ( struct V_4 * V_5 ,
struct V_243 * V_244 ,
struct V_245 * V_83 )
{
unsigned long V_17 ;
struct V_246 * V_247 = F_53 ( V_244 ) ;
struct V_248 * V_249 = & V_247 -> V_250 . V_251 ;
struct V_161 * V_162 = & V_249 -> V_252 ;
if ( V_5 -> V_148 == V_141 ) {
return 0 ;
}
F_36 ( V_5 , L_28 ) ;
F_36 ( V_5 , L_29 , V_249 -> V_172 ) ;
F_36 ( V_5 , L_30 , V_249 -> V_170 ) ;
F_36 ( V_5 , L_31 ,
V_249 -> V_253 ) ;
F_49 ( V_5 , V_162 ) ;
V_5 -> V_254 = V_5 -> V_170 ;
V_5 -> V_182 = F_43 ( V_162 ) ;
if ( V_5 -> V_139 != V_140 ) {
if ( V_5 -> V_172 != V_249 -> V_172 ||
V_5 -> V_254 != V_249 -> V_170 ) {
if ( V_249 -> V_172 ) {
if ( ! V_5 -> V_146 )
V_5 -> V_170 =
V_176 ;
else
V_5 -> V_170 =
V_249 -> V_170 ;
} else {
V_5 -> V_170 =
V_171 ;
}
V_5 -> V_172 = V_249 -> V_172 ;
F_51 ( V_5 -> V_10 -> V_241 ,
& V_5 -> V_168 ) ;
}
}
F_50 ( V_5 , V_162 ) ;
F_54 ( & V_5 -> V_10 -> V_255 , V_17 ) ;
V_5 -> V_253 = V_249 -> V_253 ;
F_55 ( & V_5 -> V_10 -> V_255 , V_17 ) ;
return 0 ;
}
void F_56 ( struct V_4 * V_5 )
{
V_5 -> V_256 [ V_257 ] =
F_52 ;
}
void F_57 ( struct V_4 * V_5 )
{
F_58 ( & V_5 -> V_168 ,
F_44 ) ;
}
void F_59 ( struct V_4 * V_5 )
{
F_60 ( & V_5 -> V_168 ) ;
}
static bool F_61 ( struct V_4 * V_5 )
{
return V_5 -> V_180 . V_181 == V_178 ||
V_5 -> V_180 . V_258 ;
}
static int F_62 ( struct V_4 * V_5 )
{
if ( V_54 ( V_5 ) -> V_127 &&
V_54 ( V_5 ) -> V_127 -> V_259 &&
( V_5 -> V_149 ||
V_5 -> V_170 >= V_176 ) ) {
return V_260 ;
}
if ( F_61 ( V_5 ) )
return V_260 ;
else
return V_261 ;
}
static int F_63 ( struct V_4 * V_5 , int V_262 )
{
switch ( V_5 -> V_180 . V_181 ) {
case V_178 :
case V_173 :
return V_263 ;
case V_174 :
case V_264 :
return V_262 ;
default:
F_64 ( 1 , L_32 ,
V_5 -> V_180 . V_181 ) ;
return V_262 ;
}
}
static T_2 F_65 ( T_1 V_265 )
{
T_2 V_266 ;
V_266 = ( V_265 & F_23 ( 0 ) ) >> 0 ;
V_266 += ( V_265 & F_23 ( 1 ) ) >> 1 ;
V_266 += ( V_265 & F_23 ( 2 ) ) >> 2 ;
V_266 += ( V_265 & F_23 ( 3 ) ) >> 3 ;
return V_266 ;
}
void F_66 ( struct V_4 * V_5 , struct V_153 * V_75 )
{
bool V_267 = F_61 ( V_5 ) ;
bool V_268 = ! F_4 ( V_269 , & V_5 -> V_10 -> V_11 ) ;
T_2 V_270 , V_271 , V_272 ;
T_1 V_273 ;
T_3 V_274 ;
if ( V_5 -> V_275 . V_273 )
V_273 = V_5 -> V_275 . V_273 ;
else
V_273 = F_67 ( V_5 ) . V_276 ;
if ( V_54 ( V_5 ) -> V_127 &&
V_54 ( V_5 ) -> V_127 -> V_259 &&
( V_5 -> V_149 ||
V_5 -> V_170 >= V_176 ) ) {
V_273 = F_68 ( V_273 ) ;
}
V_274 = V_273 << V_277 ;
V_271 = F_62 ( V_5 ) ;
V_270 = F_63 ( V_5 , V_271 ) ;
V_272 = F_65 ( V_273 ) ;
if ( V_272 < V_271 )
V_271 = V_272 ;
if ( V_272 < V_270 )
V_270 = V_272 ;
V_274 |= V_271 << V_278 ;
V_274 |= V_270 << V_279 ;
V_75 -> V_280 . V_274 = F_25 ( V_274 ) ;
if ( ! V_267 && ( V_271 >= V_260 ) && V_268 )
V_75 -> V_280 . V_274 |= V_281 ;
else
V_75 -> V_280 . V_274 &= ~ V_281 ;
F_69 ( V_5 , L_33 ,
V_75 -> V_280 . V_274 ,
V_271 , V_270 ) ;
F_70 ( V_271 == 0 || V_270 == 0 ||
V_271 < V_270 ) ;
}
T_2 F_71 ( struct V_4 * V_5 , T_2 V_282 , T_2 V_135 )
{
int V_283 ;
T_2 V_284 = V_282 ;
if ( V_5 -> V_60 == V_285 &&
V_5 -> V_170 >= V_176 )
return 0 ;
for ( V_283 = 0 ; V_283 < V_286 - 1 ; V_283 ++ ) {
V_284 = ( V_284 + 1 ) < V_286 ? V_284 + 1 : 0 ;
if ( V_135 & F_23 ( V_284 ) )
return V_284 ;
}
return V_282 ;
}
static void F_72 ( T_3 * V_287 , T_6 * V_179 )
{
int V_283 ;
for ( V_283 = 0 ; V_283 < V_288 ; V_283 ++ )
V_179 [ V_283 ] = F_25 ( V_287 [ V_283 ] ) ;
}
static void F_73 ( struct V_289 * V_107 ,
struct V_69 * V_70 ,
struct V_290 * V_291 ,
struct V_292 * V_293 ,
void * V_294 )
{
struct V_4 * V_5 = V_107 -> V_5 ;
struct V_295 * V_87 = V_294 ;
struct V_153 * V_75 = V_87 -> V_75 ;
struct V_296 * V_296 , * V_297 = NULL ;
struct V_298 * V_298 , * V_299 = NULL ;
struct V_300 * V_301 ;
T_2 * V_302 ;
struct V_303 V_304 ;
T_1 V_305 = 0 ;
T_3 V_287 [ V_288 ] ;
int V_124 , V_283 ;
F_28 ( & V_5 -> V_10 -> V_106 ) ;
if ( ( V_293 -> V_306 == V_307 ||
V_293 -> V_306 == V_308 ) &&
! V_291 && ! V_75 -> V_309 )
V_124 = F_74 ( V_5 , V_75 , V_293 ) ;
else
V_124 = F_75 ( V_5 , V_75 , V_293 , V_291 ) ;
if ( V_124 ) {
F_15 ( V_5 , L_34 ) ;
V_87 -> error = true ;
}
switch ( V_293 -> V_306 ) {
case V_310 :
if ( V_291 ) {
V_298 = V_87 -> V_311 -> V_312 . V_313 . V_314 ;
V_299 = & V_87 -> V_311 -> V_312 . V_313 . V_315 ;
V_301 = V_87 -> V_313 -> V_316 ;
F_76 ( V_293 , & V_304 ) ;
V_299 -> V_317 = F_25 ( V_304 . V_313 . V_317 ) ;
V_299 -> V_318 = F_35 ( V_304 . V_313 . V_318 ) ;
F_77 ( V_293 , V_304 . V_313 . V_318 , V_287 ) ;
F_72 ( V_287 , V_87 -> V_313 -> V_319 . V_287 ) ;
memcpy ( V_87 -> V_313 -> V_320 . V_319 ,
& V_293 -> V_293 [ V_321 ] ,
V_322 ) ;
V_302 = V_87 -> V_313 -> V_320 . V_323 ;
} else {
V_298 =
V_87 -> V_311 -> V_312 . V_313 . V_324 ;
V_301 = V_87 -> V_313 -> V_325 ;
V_302 = V_87 -> V_313 -> V_320 . V_326 ;
}
for ( V_283 = 0 ; V_283 < V_327 ; V_283 ++ ) {
F_78 ( V_293 , V_283 , & V_304 ) ;
V_298 [ V_283 ] . V_317 = F_25 ( V_304 . V_313 . V_317 ) ;
V_298 [ V_283 ] . V_318 = F_35 ( V_304 . V_313 . V_318 ) ;
if ( V_304 . V_313 . V_318 > V_305 )
V_305 = V_304 . V_313 . V_318 ;
}
F_79 ( V_293 , V_87 -> V_77 , V_305 , V_287 ) ;
F_72 ( V_287 , V_301 [ 0 ] . V_287 ) ;
F_79 ( V_293 , V_87 -> V_77 ,
V_305 + 1 , V_287 ) ;
F_72 ( V_287 , V_301 [ 1 ] . V_287 ) ;
memcpy ( V_302 ,
& V_293 -> V_293 [ V_328 ] ,
V_322 ) ;
V_87 -> V_329 = true ;
V_87 -> V_330 = true ;
break;
case V_331 :
if ( V_291 ) {
T_2 * V_332 = V_304 . V_333 . V_332 ;
V_296 = V_87 -> V_311 -> V_312 . V_334 . V_314 ;
V_297 = & V_87 -> V_311 -> V_312 . V_334 . V_315 ;
F_76 ( V_293 , & V_304 ) ;
V_297 -> V_332 = F_80 (
( V_335 ) V_332 [ 5 ] |
( ( V_335 ) V_332 [ 4 ] << 8 ) |
( ( V_335 ) V_332 [ 3 ] << 16 ) |
( ( V_335 ) V_332 [ 2 ] << 24 ) |
( ( V_335 ) V_332 [ 1 ] << 32 ) |
( ( V_335 ) V_332 [ 0 ] << 40 ) ) ;
} else
V_296 = V_87 -> V_311 -> V_312 . V_334 . V_324 ;
for ( V_283 = 0 ; V_283 < V_327 ; V_283 ++ ) {
T_2 * V_332 = V_304 . V_333 . V_332 ;
F_78 ( V_293 , V_283 , & V_304 ) ;
V_296 -> V_332 = F_80 (
( V_335 ) V_332 [ 5 ] |
( ( V_335 ) V_332 [ 4 ] << 8 ) |
( ( V_335 ) V_332 [ 3 ] << 16 ) |
( ( V_335 ) V_332 [ 2 ] << 24 ) |
( ( V_335 ) V_332 [ 1 ] << 32 ) |
( ( V_335 ) V_332 [ 0 ] << 40 ) ) ;
}
V_87 -> V_330 = true ;
break;
}
F_32 ( & V_5 -> V_10 -> V_106 ) ;
}
int F_81 ( struct V_4 * V_5 ,
struct V_336 * V_337 )
{
struct V_338 * V_339 ;
struct V_82 V_83 = {
. V_84 = V_340 ,
. V_341 [ 0 ] = V_342 ,
. V_17 = V_24 ,
} ;
int V_283 , V_343 ;
if ( ! V_337 -> V_344 )
return 0 ;
V_83 . V_86 [ 0 ] = sizeof( * V_339 ) +
V_337 -> V_344 * sizeof( struct V_345 ) ;
V_339 = F_82 ( V_83 . V_86 [ 0 ] , V_346 ) ;
if ( ! V_339 )
return - V_347 ;
V_339 -> V_344 = F_35 ( V_337 -> V_344 ) ;
for ( V_283 = 0 ; V_283 < V_337 -> V_344 ; V_283 ++ ) {
int V_348 = F_83 ( V_337 -> V_349 [ V_283 ] . V_350 , 8 ) ;
memcpy ( & V_339 -> V_349 [ V_283 ] . V_351 ,
V_337 -> V_349 [ V_283 ] . V_351 , V_348 ) ;
memcpy ( & V_339 -> V_349 [ V_283 ] . V_352 ,
V_337 -> V_349 [ V_283 ] . V_352 ,
V_337 -> V_349 [ V_283 ] . V_350 ) ;
V_339 -> V_349 [ V_283 ] . V_353 = V_348 ;
V_339 -> V_349 [ V_283 ] . V_354 =
V_337 -> V_349 [ V_283 ] . V_350 ;
}
V_83 . V_87 [ 0 ] = V_339 ;
V_343 = F_26 ( F_7 ( V_5 ) , & V_83 ) ;
F_84 ( V_339 ) ;
return V_343 ;
}
int F_85 ( struct V_4 * V_5 ,
struct V_289 * V_107 , struct V_336 * V_337 )
{
struct V_355 V_356 ;
struct V_357 V_358 ;
struct V_153 * V_75 = & V_5 -> V_359 [ V_88 ] ;
struct V_360 V_361 ;
struct V_362 V_363 = {} ;
struct V_364 V_365 = {} ;
struct V_295 V_366 = {
. V_75 = V_75 ,
. V_77 = V_75 -> V_367 . V_368 ,
. V_330 = false ,
. V_313 = & V_363 ,
. V_329 = false ,
} ;
int V_124 , V_283 ;
T_3 V_304 ;
V_366 . V_311 = F_86 ( sizeof( * V_366 . V_311 ) , V_346 ) ;
if ( ! V_366 . V_311 )
return - V_347 ;
memset ( & V_356 , 0 , sizeof( V_356 ) ) ;
V_304 = F_87 ( V_5 -> V_369 ) & V_370 ;
V_356 . V_371 = F_25 ( V_304 ) ;
for ( V_283 = 0 ; V_283 < V_372 ; V_283 ++ ) {
V_304 = V_5 -> V_373 [ V_374 ] [ V_283 ] . V_375 ;
V_304 -= 0x10 ;
V_356 . V_376 [ V_283 ] = F_25 ( V_304 ) ;
}
if ( V_337 -> V_377 )
V_356 . V_378 |=
F_35 ( V_379 |
V_380 ) ;
if ( V_337 -> V_381 )
V_356 . V_378 |=
F_35 ( V_382 ) ;
if ( V_337 -> V_383 )
V_356 . V_378 |=
F_35 ( V_384 ) ;
if ( V_337 -> V_385 )
V_356 . V_378 |=
F_35 ( V_386 ) ;
if ( V_337 -> V_387 )
V_356 . V_378 |=
F_35 ( V_388 ) ;
if ( V_337 -> V_344 )
V_356 . V_378 |=
F_35 ( V_389 ) ;
if ( V_337 -> V_390 )
V_365 . V_391 |=
F_35 ( V_392 ) ;
F_88 ( V_5 , 200 ) ;
memcpy ( & V_358 , & V_75 -> V_367 , sizeof( V_358 ) ) ;
F_89 ( F_7 ( V_5 ) ) ;
V_5 -> V_10 -> V_337 = true ;
V_124 = F_90 ( F_7 ( V_5 ) , V_393 ) ;
if ( V_124 )
goto V_179;
V_124 = F_91 ( V_5 ) ;
if ( V_124 )
goto V_179;
memcpy ( & V_75 -> V_280 , & V_358 , sizeof( V_358 ) ) ;
V_124 = F_92 ( V_5 , V_75 ) ;
if ( V_124 )
goto V_179;
V_124 = F_93 ( V_5 , true ) ;
if ( V_124 )
goto V_179;
if ( ! V_137 . V_394 ) {
V_5 -> V_395 = 0 ;
V_75 -> V_309 = 0 ;
F_32 ( & V_5 -> V_10 -> V_106 ) ;
F_94 ( V_5 -> V_107 , V_75 -> V_70 ,
F_73 ,
& V_366 ) ;
F_28 ( & V_5 -> V_10 -> V_106 ) ;
if ( V_366 . error ) {
V_124 = - V_396 ;
goto V_179;
}
if ( V_366 . V_330 ) {
struct V_82 V_397 = {
. V_84 = V_398 ,
. V_17 = V_24 ,
. V_87 [ 0 ] = V_366 . V_311 ,
. V_341 [ 0 ] = V_342 ,
. V_86 [ 0 ] = sizeof( * V_366 . V_311 ) ,
} ;
V_124 = F_26 ( F_7 ( V_5 ) , & V_397 ) ;
if ( V_124 )
goto V_179;
}
if ( V_366 . V_329 ) {
V_124 = F_6 ( F_7 ( V_5 ) ,
V_399 ,
V_24 , sizeof( V_363 ) ,
& V_363 ) ;
if ( V_124 )
goto V_179;
}
if ( V_5 -> V_400 ) {
memset ( & V_361 , 0 , sizeof( V_361 ) ) ;
memcpy ( V_361 . V_401 , V_5 -> V_401 , V_402 ) ;
V_361 . V_403 = F_25 ( V_402 ) ;
memcpy ( V_361 . V_404 , V_5 -> V_404 , V_405 ) ;
V_361 . V_406 = F_25 ( V_405 ) ;
V_361 . V_407 = V_5 -> V_407 ;
V_124 = F_6 ( F_7 ( V_5 ) ,
V_408 ,
V_24 , sizeof( V_361 ) ,
& V_361 ) ;
if ( V_124 )
goto V_179;
}
}
V_124 = F_6 ( F_7 ( V_5 ) , V_409 , V_24 ,
sizeof( V_365 ) , & V_365 ) ;
if ( V_124 )
goto V_179;
V_124 = F_6 ( F_7 ( V_5 ) , V_410 ,
V_24 , sizeof( V_356 ) ,
& V_356 ) ;
if ( V_124 )
goto V_179;
V_124 = F_81 ( V_5 , V_337 ) ;
V_179:
F_84 ( V_366 . V_311 ) ;
return V_124 ;
}
