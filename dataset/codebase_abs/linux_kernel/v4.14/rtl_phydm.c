static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
struct V_14 * V_15 = V_14 ( V_2 ) ;
struct V_16 * V_17 = F_3 ( V_2 ) ;
struct V_18 * V_19 = V_18 ( V_2 ) ;
T_1 V_20 = V_21 ;
T_2 V_22 ;
int V_23 ;
V_8 -> V_24 = ( void * ) V_2 ;
F_4 ( V_8 , V_25 , V_26 ) ;
F_4 ( V_8 , V_27 , V_4 ) ;
F_4 ( V_8 , V_28 , V_29 ) ;
F_4 ( V_8 , V_30 , V_6 -> V_31 ) ;
F_4 ( V_8 , V_32 , V_10 -> V_33 ) ;
F_4 ( V_8 , V_34 , 1 ) ;
if ( V_12 -> V_35 == V_36 )
F_4 ( V_8 , V_37 , V_38 ) ;
else if ( V_12 -> V_35 == V_39 )
F_4 ( V_8 , V_37 , V_40 ) ;
else if ( V_12 -> V_35 == V_41 )
F_4 ( V_8 , V_37 , V_42 ) ;
else if ( V_12 -> V_35 == V_43 )
F_4 ( V_8 , V_37 , V_44 ) ;
else if ( V_12 -> V_35 == V_45 )
F_4 ( V_8 , V_37 , V_46 ) ;
else if ( V_12 -> V_35 == V_47 )
F_4 ( V_8 , V_37 , V_48 ) ;
else if ( V_12 -> V_35 == V_49 )
F_4 ( V_8 , V_37 , V_50 ) ;
else if ( V_12 -> V_35 == V_51 )
F_4 ( V_8 , V_37 , V_52 ) ;
else if ( V_12 -> V_35 == V_53 )
F_4 ( V_8 , V_37 , V_54 ) ;
else
F_4 ( V_8 , V_37 , V_55 ) ;
if ( V_10 -> V_56 != 0 ) {
V_20 |= V_57 ;
F_4 ( V_8 , V_58 , 1 ) ;
}
if ( V_10 -> V_59 != 0 ) {
V_20 |= V_60 ;
F_4 ( V_8 , V_61 , 1 ) ;
}
if ( V_10 -> V_62 != 0 ) {
V_20 |= V_63 ;
F_4 ( V_8 , V_64 , 1 ) ;
}
if ( V_10 -> V_65 != 0 ) {
V_20 |= V_66 ;
F_4 ( V_8 , V_67 , 1 ) ;
}
if ( V_2 -> V_68 -> V_69 -> V_70 () )
V_20 |= V_71 ;
F_4 ( V_8 , V_72 , V_20 ) ;
F_4 ( V_8 , V_73 , V_10 -> V_74 ) ;
F_4 ( V_8 , V_75 , V_10 -> V_76 ) ;
F_4 ( V_8 , V_77 , V_10 -> V_78 ) ;
F_4 ( V_8 , V_79 , V_10 -> V_80 ) ;
F_4 ( V_8 , V_81 , V_10 -> V_82 ) ;
F_4 ( V_8 , V_83 , 0 ) ;
F_4 ( V_8 , V_84 , 2 ) ;
F_4 ( V_8 , V_85 , 0 ) ;
F_5 ( V_8 , V_86 ,
& V_19 -> V_87 ) ;
F_4 ( V_8 , V_88 ,
V_19 -> V_89 ) ;
F_4 ( V_8 , V_90 , 0 ) ;
F_4 ( V_8 , V_91 , 0 ) ;
F_4 ( V_8 , V_92 , V_6 -> V_93 ) ;
F_4 ( V_8 , V_94 , V_6 -> V_95 ) ;
F_5 ( V_8 , V_96 ,
& V_2 -> V_97 . V_98 ) ;
F_6 ( V_8 , V_99 ,
false ) ;
F_6 ( V_8 , V_100 , 0 ) ;
F_6 ( V_8 , V_101 ,
false ) ;
F_6 ( V_8 , V_102 , 0 ) ;
F_6 ( V_8 , V_103 , 0 ) ;
F_4 ( V_8 , V_104 , 0 ) ;
F_5 ( V_8 , V_105 ,
& V_2 -> V_106 . V_107 ) ;
F_5 ( V_8 , V_108 ,
& V_2 -> V_106 . V_109 ) ;
F_5 ( V_8 , V_110 , & V_10 -> V_111 ) ;
F_5 ( V_8 , V_112 ,
& V_2 -> V_97 . V_113 ) ;
F_5 ( V_8 , V_114 ,
& V_2 -> V_97 . V_115 ) ;
F_5 ( V_8 , V_116 ,
& V_15 -> V_117 ) ;
F_5 ( V_8 , V_118 , & V_12 -> V_119 ) ;
F_5 ( V_8 , V_120 , & V_12 -> V_121 ) ;
F_5 ( V_8 , V_122 , & V_15 -> V_123 ) ;
F_5 ( V_8 , V_124 ,
& V_17 -> V_125 ) ;
F_5 ( V_8 , V_126 ,
& V_2 -> V_106 . V_127 ) ;
F_5 ( V_8 , V_128 ,
& V_2 -> V_106 . V_129 ) ;
F_5 ( V_8 , V_130 ,
& V_2 -> V_97 . V_131 ) ;
for ( V_23 = 0 ; V_23 < V_132 ; V_23 ++ )
F_7 ( V_8 , V_133 , V_23 ,
NULL ) ;
F_8 ( V_8 ) ;
F_4 ( V_8 , V_134 , V_6 -> V_135 ) ;
F_4 ( V_8 , V_136 , V_6 -> V_137 ) ;
V_22 = V_138 | V_139 ;
F_9 ( V_8 , V_140 , V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_3 V_141 ;
if ( F_11 ( V_2 ) )
V_141 = V_142 ;
else
return 0 ;
V_2 -> V_97 . V_143 =
F_12 ( sizeof( struct V_7 ) , V_144 ) ;
F_1 ( V_2 , V_141 , V_6 ) ;
F_13 ( V_8 ) ;
return 1 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_15 ( V_8 ) ;
F_16 ( V_2 -> V_97 . V_143 ) ;
V_2 -> V_97 . V_143 = NULL ;
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_145 V_146 ;
V_146 = F_18 ( V_8 , V_147 ) ;
if ( V_146 != V_148 )
return false ;
return true ;
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_145 V_146 ;
if ( F_11 ( V_2 ) ) {
F_20 ( V_8 ) ;
} else {
V_146 = F_21 ( V_8 , V_149 ,
0 ) ;
if ( V_146 != V_148 )
return false ;
}
return true ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_2 V_22 = 0 ;
V_22 = 0
| V_150
| V_151
| V_152
| V_153
| V_154
| V_155
| V_156
| V_157
| V_139
| V_138
| V_158
;
F_9 ( V_8 , V_140 , V_22 ) ;
F_23 ( V_8 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_26 ( V_8 ) ;
return 0 ;
}
static bool F_27 ( struct V_1 * V_2 , bool V_159 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_11 ( V_2 ) )
return F_28 ( V_8 , V_159 ? V_160 :
V_161 ) ;
return false ;
}
static bool F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_145 V_146 ;
V_146 = F_18 ( V_8 , V_162 ) ;
if ( V_146 != V_148 )
return false ;
V_146 = F_18 ( V_8 , V_163 ) ;
if ( V_146 != V_148 )
return false ;
return true ;
}
static bool F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
enum V_145 V_146 ;
enum V_164 V_165 ;
for ( V_165 = 0 ; V_165 < V_12 -> V_166 ; V_165 ++ ) {
V_146 = F_21 ( V_8 , V_167 ,
V_165 ) ;
if ( V_146 != V_148 )
return false ;
}
V_146 = F_31 ( V_8 ) ;
if ( V_146 != V_148 )
return false ;
return true ;
}
static bool F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_145 V_146 ;
V_146 = F_33 ( V_8 ) ;
if ( V_146 != V_148 )
return false ;
return true ;
}
static bool F_34 ( struct V_1 * V_2 ,
enum V_168 V_169 , enum V_168 V_170 ,
bool V_171 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_11 ( V_2 ) )
return F_35 ( V_8 ,
(enum V_172 ) V_169 ,
(enum V_172 ) V_170 ,
V_171 ) ;
return false ;
}
static bool F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_14 ( V_2 ) ;
struct V_16 * V_17 = F_3 ( V_2 ) ;
bool V_173 = false ;
bool V_174 = true ;
T_1 V_175 = false ;
T_1 V_176 = false ;
T_1 V_177 = false ;
V_2 -> V_68 -> V_69 -> V_178 ( V_2 -> V_179 , V_180 ,
( T_1 * ) ( & V_173 ) ) ;
V_2 -> V_68 -> V_69 -> V_178 ( V_2 -> V_179 , V_181 ,
( T_1 * ) ( & V_174 ) ) ;
if ( V_17 -> V_182 . V_183 )
V_174 = false ;
if ( ( V_17 -> V_184 == V_185 ) &&
( ( ! V_173 ) && V_174 ) &&
( ! V_17 -> V_186 ) )
;
else
return false ;
if ( V_15 -> V_187 >= V_188 ) {
V_175 = true ;
if ( V_15 -> V_189 && V_15 -> V_189 -> type == V_190 )
V_176 = true ;
}
if ( V_2 -> V_68 -> V_69 -> V_70 () )
V_177 = ! V_2 -> V_191 . V_192 -> V_193 (
V_2 ) ;
F_9 ( V_8 , V_194 , V_175 ) ;
F_9 ( V_8 , V_195 , V_176 ) ;
F_9 ( V_8 , V_196 , V_177 ) ;
F_37 ( V_8 ) ;
return true ;
}
static bool F_38 ( struct V_1 * V_2 , T_1 V_197 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_11 ( V_2 ) )
return F_39 ( V_8 , V_197 ) ;
return false ;
}
static bool F_40 ( struct V_1 * V_2 , T_1 V_197 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_11 ( V_2 ) )
return F_41 ( V_8 , V_197 ) ;
return false ;
}
static bool F_42 ( struct V_1 * V_2 ,
T_1 V_198 ,
enum V_199 V_200 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_201 V_201 = (enum V_201 ) V_200 ;
if ( F_11 ( V_2 ) )
return F_43 ( V_8 , V_198 ,
V_201 ) ;
return false ;
}
static bool F_44 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_11 ( V_2 ) )
F_45 ( V_8 , false ) ;
else
return false ;
return true ;
}
static bool F_46 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_47 ( V_8 ) ;
return true ;
}
static bool F_48 ( struct V_1 * V_2 , bool V_202 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_202 )
F_49 ( V_8 , V_203 , V_204 , 0x1e ) ;
else
F_49 ( V_8 , V_205 , V_204 , 0xff ) ;
return true ;
}
static T_2 F_50 ( struct V_1 * V_2 ,
enum V_206 V_165 , T_2 V_207 , T_2 V_208 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_164 V_209 = (enum V_164 ) V_165 ;
if ( F_11 ( V_2 ) )
return F_51 ( V_8 , V_209 , V_207 ,
V_208 ) ;
return - 1 ;
}
static bool F_52 ( struct V_1 * V_2 ,
enum V_206 V_165 , T_2 V_207 , T_2 V_208 ,
T_2 V_210 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_164 V_209 = (enum V_164 ) V_165 ;
if ( F_11 ( V_2 ) )
return F_53 ( V_8 , V_209 , V_207 ,
V_208 , V_210 ) ;
return false ;
}
static T_1 F_54 ( struct V_1 * V_2 , enum V_206 V_165 ,
T_1 V_211 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_164 V_209 = (enum V_164 ) V_165 ;
if ( F_11 ( V_2 ) )
return F_55 ( V_8 , V_209 , V_211 ) ;
return - 1 ;
}
static bool F_56 ( struct V_1 * V_2 , T_2 V_212 ,
enum V_206 V_165 , T_1 V_211 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_164 V_209 = (enum V_164 ) V_165 ;
if ( F_11 ( V_2 ) )
return F_57 ( V_8 , V_212 ,
V_209 , V_211 ) ;
return false ;
}
static bool F_58 ( struct V_1 * V_2 , T_1 V_213 ,
T_1 V_214 , T_1 * V_215 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_59 ( V_8 , V_213 , V_214 , V_215 ) )
return true ;
return false ;
}
static bool F_60 ( struct V_1 * V_2 , T_1 * V_216 ,
struct V_217 * V_218 ,
struct V_219 * V_220 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_18 ( V_2 ) ;
struct V_14 * V_15 = V_14 ( V_2 ) ;
struct V_221 V_222 ;
struct V_223 V_224 ;
T_3 V_225 = V_218 -> V_226 ;
F_61 ( V_220 -> V_227 , F_62 ( V_218 ) ) ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_222 . V_228 = V_220 -> V_229 ;
if ( V_2 -> V_230 . V_231 == V_190 ) {
V_222 . V_232 = 0 ;
} else {
V_222 . V_232 = 0xFF ;
}
V_222 . V_233 =
( ! F_63 ( V_225 ) &&
( F_64 ( V_15 -> V_234 ,
F_65 ( V_225 ) ?
V_218 -> V_235 :
F_66 ( V_225 ) ?
V_218 -> V_236 :
V_218 -> V_237 ) ) &&
( ! V_220 -> V_238 ) && ( ! V_220 -> V_239 ) && ( ! V_220 -> V_240 ) ) ;
V_222 . V_241 =
V_222 . V_233 &&
( F_64 ( V_218 -> V_235 , V_19 -> V_242 ) ) ;
V_222 . V_243 = ( ! V_220 -> V_240 ) && ( ! V_220 -> V_239 ) &&
( F_64 ( V_218 -> V_235 , V_19 -> V_242 ) ) ;
V_222 . V_244 = ( F_67 ( V_225 ) ? true : false ) ;
if ( V_216 )
F_68 ( V_8 , & V_224 , V_216 , & V_222 ) ;
else
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
V_220 -> V_245 = V_224 . V_245 ;
V_220 -> V_246 = V_224 . V_246 ;
V_220 -> V_247 = V_224 . V_248 ;
V_220 -> V_249 = V_224 . V_250 ;
V_220 -> V_251 [ 0 ] = V_224 . V_252 [ 0 ] ;
V_220 -> V_251 [ 1 ] = V_224 . V_252 [ 1 ] ;
V_220 -> V_253 =
V_224 . V_254 ;
V_220 -> V_255 = V_222 . V_233 ;
V_220 -> V_256 = V_222 . V_241 ;
V_220 -> V_257 = V_222 . V_244 ;
return true ;
}
static T_1 F_69 ( struct V_1 * V_2 ,
enum V_258 V_258 ,
enum V_35 V_35 ,
enum V_199 V_259 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_70 ( V_8 , V_258 , V_35 , V_259 ) ;
}
static bool F_71 ( struct V_1 * V_2 ,
enum V_258 V_258 ,
enum V_35 V_35 ,
enum V_199 V_259 ,
T_1 V_260 ,
T_2 * V_261 ,
T_2 * V_262 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
const T_1 V_263 = 0 ;
const T_1 V_264 = 0 ;
F_72 ( V_8 , V_258 , V_35 , V_259 , V_263 ,
V_264 , V_261 , V_262 ,
V_260 ) ;
return true ;
}
static T_1 F_73 ( struct V_1 * V_2 ,
struct V_265 * V_266 )
{
struct V_14 * V_15 = V_14 ( V_2 ) ;
if ( V_15 -> V_231 == V_190 ||
V_15 -> V_231 == V_267 ) {
return 0 ;
} else if ( V_15 -> V_231 == V_268 ||
V_15 -> V_231 == V_269 )
return V_266 -> V_270 + 1 ;
return 0 ;
}
static bool F_74 ( struct V_1 * V_2 ,
struct V_265 * V_266 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_271 * V_272 = (struct V_271 * ) V_266 -> V_273 ;
T_1 V_274 = F_73 ( V_2 , V_266 ) ;
F_7 ( V_8 , V_133 , V_274 ,
V_272 ) ;
return true ;
}
static bool F_75 ( struct V_1 * V_2 ,
struct V_265 * V_266 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_274 = F_73 ( V_2 , V_266 ) ;
F_7 ( V_8 , V_133 , V_274 , NULL ) ;
return true ;
}
static T_2 F_76 ( struct V_1 * V_2 )
{
T_2 V_275 = 0 ;
if ( F_11 ( V_2 ) )
V_275 = V_276 ;
return V_275 ;
}
static bool F_77 ( struct V_1 * V_2 ,
T_1 V_277 ,
T_1 V_278 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_78 ( V_8 , V_277 ,
V_278 ) ;
return true ;
}
static T_2 F_79 ( struct V_1 * V_2 ,
const char * V_279 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
static const struct V_280 {
const char * V_281 ;
enum V_282 V_283 ;
} V_284 [] = {
#define F_80 ( T_4 ) {#name, name}
F_80 ( V_285 ) ,
F_80 ( V_286 ) ,
F_80 ( V_287 ) ,
F_80 ( V_288 ) ,
F_80 ( V_289 ) ,
F_80 ( V_290 ) ,
F_80 ( V_291 ) ,
F_80 ( V_292 ) ,
F_80 ( V_293 ) ,
F_80 ( V_294 ) ,
F_80 ( V_295 ) ,
F_80 ( V_296 ) ,
} ;
#define F_81 ARRAY_SIZE(query_table)
int V_23 ;
const struct V_280 * V_297 ;
if ( ! strcmp ( V_279 , L_1 ) )
return V_8 -> V_298 ;
if ( ! strcmp ( V_279 , L_2 ) )
return V_8 -> V_299 ;
if ( ! strcmp ( V_279 , L_3 ) )
return V_8 -> V_300 ;
for ( V_23 = 0 ; V_23 < F_81 ; V_23 ++ ) {
V_297 = & V_284 [ V_23 ] ;
if ( ! strcmp ( V_279 , V_297 -> V_281 ) )
return F_82 ( V_8 , V_297 -> V_283 ) ;
}
F_83 ( L_4 , V_279 ) ;
return 0xDEADDEAD ;
}
static bool F_84 ( struct V_1 * V_2 , char * V_301 , T_2 V_302 ,
char * V_303 , T_2 V_304 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_85 ( V_8 , V_301 , V_302 , 1 , V_303 , V_304 ) ;
return true ;
}
struct V_305 * F_86 ( void )
{
return & V_306 ;
}
T_1 F_87 ( void * V_24 , T_1 V_307 , T_1 V_229 ,
enum V_199 V_200 , T_1 V_308 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
return V_2 -> V_68 -> V_69 -> V_309 ( V_2 -> V_179 , V_307 , V_229 ,
V_200 , V_308 ) ;
}
void F_88 ( void * V_24 , T_1 V_310 , T_1 V_311 , T_1 V_312 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
return V_2 -> V_68 -> V_69 -> V_313 ( V_2 -> V_179 , V_310 ,
V_311 , V_312 ) ;
}
void F_89 ( void * V_24 , T_2 V_314 , T_2 V_165 , T_2 V_315 ,
T_2 V_316 , T_2 V_317 , T_2 V_210 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
V_2 -> V_68 -> V_69 -> V_318 (
V_2 -> V_179 , V_314 , V_165 , V_315 , V_316 , V_317 , V_210 ) ;
}
void F_90 ( void * V_8 , T_1 * V_319 , T_1 * V_314 , T_1 * V_200 ,
T_1 * V_320 , T_1 * V_307 , T_1 * V_308 ,
T_1 * V_321 )
{
struct V_1 * V_2 =
(struct V_1 * ) ( (struct V_7 * ) V_8 ) -> V_24 ;
V_2 -> V_68 -> V_69 -> V_322 ( V_2 -> V_179 , V_319 , V_314 ,
V_200 , V_320 ,
V_307 , V_308 , V_321 ) ;
}
void F_91 ( void * V_24 , struct V_271 * V_323 ,
T_1 V_324 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
struct V_265 * V_266 =
F_92 ( ( void * ) V_323 , struct V_265 , V_273 ) ;
V_2 -> V_68 -> V_69 -> V_325 ( V_2 -> V_179 , V_266 , V_324 , false ) ;
}
