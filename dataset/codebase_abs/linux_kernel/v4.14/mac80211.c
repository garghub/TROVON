void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( ! F_2 ( V_2 ) )
return;
F_3 ( V_2 , L_1 , V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_2 -> V_6 [ V_4 ] ++ ;
F_5 ( & V_2 -> V_5 ) ;
F_6 ( V_2 -> V_7 ) ;
}
void F_7 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( ! F_2 ( V_2 ) )
return;
F_3 ( V_2 , L_2 , V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
if ( F_8 ( ! V_2 -> V_6 [ V_4 ] ) ) {
F_5 ( & V_2 -> V_5 ) ;
return;
}
V_2 -> V_6 [ V_4 ] -- ;
F_5 ( & V_2 -> V_5 ) ;
F_9 ( V_2 -> V_7 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
int V_9 , V_10 ;
if ( ! F_2 ( V_2 ) )
return;
F_4 ( & V_2 -> V_5 ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
if ( V_8 == V_9 || ! V_2 -> V_6 [ V_9 ] )
continue;
F_3 ( V_2 , L_3 ,
V_9 , V_2 -> V_6 [ V_9 ] ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_6 [ V_9 ] ; V_10 ++ )
F_9 ( V_2 -> V_7 ) ;
V_2 -> V_6 [ V_9 ] = 0 ;
}
F_5 ( & V_2 -> V_5 ) ;
}
bool F_11 ( struct V_1 * V_2 )
{
int V_9 ;
bool V_12 = false ;
if ( ! F_2 ( V_2 ) )
return true ;
F_4 ( & V_2 -> V_5 ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
if ( V_2 -> V_6 [ V_9 ] ) {
V_12 = true ;
break;
}
}
F_5 ( & V_2 -> V_5 ) ;
return V_12 ;
}
int F_12 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( ! F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 , & V_2 -> V_15 ) ,
V_16 ) ) {
F_15 ( 1 ) ;
F_7 ( V_2 , V_4 ) ;
return - V_17 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_9 ;
memset ( V_2 -> V_18 , 0 , sizeof( V_2 -> V_18 ) ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_2 -> V_18 [ V_9 ] . V_20 = V_9 ;
V_2 -> V_18 [ V_9 ] . V_21 = 0 ;
}
}
struct V_22 * F_17 ( struct V_23 * V_23 ,
const char * V_24 ,
enum V_25 V_26 ,
bool * V_27 )
{
struct V_22 * V_28 = NULL ;
struct V_29 * V_30 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_31 * V_32 ;
F_20 ( V_2 , L_4 , V_24 ) ;
F_21 ( & V_2 -> V_33 ) ;
V_32 = F_22 ( V_2 , V_24 , V_26 ) ;
if ( F_23 ( V_32 ) ) {
F_20 ( V_2 , L_5 ,
F_24 ( V_32 ) ) ;
goto V_34;
}
if ( V_27 )
* V_27 = ( V_32 -> V_15 == V_35 ) ;
V_28 = F_25 ( V_2 -> V_7 -> V_36 , V_2 -> V_37 ,
F_26 ( V_32 -> V_38 ) ,
V_32 -> V_39 ,
F_27 ( V_32 -> V_40 ) ) ;
V_26 = V_32 -> V_41 ;
F_28 ( V_32 ) ;
if ( F_23 ( V_28 ) ) {
F_20 ( V_2 , L_6 ,
F_24 ( V_28 ) ) ;
goto V_34;
}
F_20 ( V_2 , L_7 ,
V_28 -> V_24 , V_28 -> V_24 [ 0 ] , V_28 -> V_24 [ 1 ] , V_26 ) ;
V_2 -> V_42 = true ;
V_2 -> V_43 = V_26 ;
V_34:
return V_28 ;
}
void F_29 ( struct V_1 * V_2 )
{
bool V_27 ;
struct V_22 * V_28 ;
if ( ! F_30 ( V_2 ) )
return;
V_28 = F_31 ( V_2 , & V_27 ) ;
if ( ! F_23 ( V_28 ) ) {
if ( V_27 )
F_32 ( V_2 -> V_30 -> V_23 , V_28 ) ;
F_28 ( V_28 ) ;
}
}
struct V_22 * F_31 ( struct V_1 * V_2 ,
bool * V_27 )
{
return F_17 ( V_2 -> V_30 -> V_23 , L_8 ,
F_33 ( V_2 ) ?
V_44 :
V_45 , V_27 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
enum V_25 V_46 ;
struct V_22 * V_28 ;
int V_47 ;
bool V_27 ;
const struct V_22 * V_48 =
F_35 ( V_2 -> V_30 -> V_23 -> V_28 ) ;
if ( ! V_48 )
return - V_49 ;
V_46 = V_2 -> V_43 ;
if ( F_33 ( V_2 ) ) {
V_28 = F_31 ( V_2 , NULL ) ;
if ( ! F_23 ( V_28 ) )
F_28 ( V_28 ) ;
}
V_28 = F_17 ( V_2 -> V_30 -> V_23 , V_48 -> V_24 , V_46 ,
& V_27 ) ;
if ( F_23 ( V_28 ) )
return - V_17 ;
if ( V_27 )
V_47 = F_36 ( V_2 -> V_30 -> V_23 , V_28 ) ;
else
V_47 = 0 ;
F_28 ( V_28 ) ;
return V_47 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_50 , V_47 , V_9 ;
static const T_1 V_51 [] = {
V_52 ,
V_53 ,
V_54 ,
V_55 ,
} ;
F_38 ( V_30 , V_56 ) ;
F_38 ( V_30 , V_57 ) ;
F_38 ( V_30 , V_58 ) ;
F_38 ( V_30 , V_59 ) ;
F_38 ( V_30 , V_60 ) ;
F_38 ( V_30 , V_61 ) ;
F_38 ( V_30 , V_62 ) ;
F_38 ( V_30 , V_63 ) ;
F_38 ( V_30 , V_64 ) ;
F_38 ( V_30 , V_65 ) ;
F_38 ( V_30 , V_66 ) ;
F_38 ( V_30 , V_67 ) ;
F_38 ( V_30 , V_68 ) ;
F_38 ( V_30 , V_69 ) ;
F_38 ( V_30 , V_70 ) ;
if ( F_39 ( V_2 ) )
F_38 ( V_30 , V_71 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_74 ) ) {
F_38 ( V_30 , V_75 ) ;
} else if ( F_8 ( F_41 ( V_2 ) ) ) {
return - V_76 ;
}
if ( V_2 -> V_7 -> V_77 > 1 )
F_38 ( V_30 , V_78 ) ;
if ( V_2 -> V_7 -> V_79 )
V_30 -> V_80 = V_81 | V_82 ;
V_30 -> V_83 = V_84 ;
V_30 -> V_85 = V_86 ;
V_30 -> V_87 |= V_88 |
V_89 ;
V_30 -> V_90 |= V_91 |
V_92 ;
V_30 -> V_93 . V_94 =
V_95 |
V_96 ;
V_30 -> V_93 . V_97 = 22 ;
V_30 -> V_98 = L_9 ;
V_30 -> V_99 = V_100 ;
V_30 -> V_101 = V_102 ;
F_42 ( F_43 ( V_2 -> V_103 ) < F_43 ( V_51 ) + 6 ) ;
memcpy ( V_2 -> V_103 , V_51 , sizeof( V_51 ) ) ;
V_30 -> V_23 -> V_104 = F_43 ( V_51 ) ;
V_30 -> V_23 -> V_105 = V_2 -> V_103 ;
if ( F_39 ( V_2 ) ) {
V_2 -> V_103 [ V_30 -> V_23 -> V_104 ] =
V_106 ;
V_30 -> V_23 -> V_104 ++ ;
V_2 -> V_103 [ V_30 -> V_23 -> V_104 ] =
V_107 ;
V_30 -> V_23 -> V_104 ++ ;
}
if ( ! V_108 . V_109 ) {
F_38 ( V_30 , V_110 ) ;
V_2 -> V_103 [ V_30 -> V_23 -> V_104 ] =
V_111 ;
V_30 -> V_23 -> V_104 ++ ;
if ( F_39 ( V_2 ) ) {
V_2 -> V_103 [ V_30 -> V_23 -> V_104 ] =
V_112 ;
V_30 -> V_23 -> V_104 ++ ;
V_2 -> V_103 [ V_30 -> V_23 -> V_104 ] =
V_113 ;
V_30 -> V_23 -> V_104 ++ ;
}
}
if ( V_2 -> V_72 -> V_114 [ 0 ] . V_115 ) {
const struct V_116 * V_117 = & V_2 -> V_72 -> V_114 [ 0 ] ;
struct V_118 * V_114 = & V_2 -> V_114 [ 0 ] ;
V_2 -> V_30 -> V_119 = 1 ;
V_114 -> V_115 = F_44 ( V_117 -> V_115 ) ;
V_114 -> V_120 = F_45 ( V_121 ) ;
V_114 -> V_122 = V_117 -> V_122 ;
V_114 -> V_123 = V_117 -> V_123 ;
V_114 -> V_124 = V_117 -> V_124 ;
V_114 -> V_125 = V_117 -> V_125 ;
V_114 -> V_126 = V_117 -> V_126 ;
V_114 -> V_127 = V_117 -> V_127 ;
V_114 -> V_128 = V_117 -> V_128 ;
V_2 -> V_30 -> V_129 = V_2 -> V_114 ;
V_2 -> V_103 [ V_30 -> V_23 -> V_104 ] = V_114 -> V_115 ;
V_30 -> V_23 -> V_104 ++ ;
}
F_38 ( V_30 , V_130 ) ;
V_30 -> V_23 -> V_131 |=
V_132 |
V_133 |
V_134 ;
V_30 -> V_135 = sizeof( struct V_136 ) ;
V_30 -> V_137 = sizeof( struct V_138 ) ;
V_30 -> V_139 = sizeof( V_140 ) ;
V_30 -> V_23 -> V_141 = F_45 ( V_121 ) |
F_45 ( V_142 ) |
F_45 ( V_143 ) |
F_45 ( V_144 ) |
F_45 ( V_145 ) |
F_45 ( V_146 ) ;
V_30 -> V_23 -> V_147 |= V_148 ;
V_30 -> V_23 -> V_149 |= V_150 ;
if ( F_30 ( V_2 ) )
V_30 -> V_23 -> V_149 |= V_151 ;
else
V_30 -> V_23 -> V_149 |= V_152 |
V_153 ;
V_30 -> V_23 -> V_147 |= V_154 ;
V_30 -> V_23 -> V_147 |= V_155 ;
V_30 -> V_23 -> V_156 = V_157 ;
V_30 -> V_23 -> V_158 =
F_43 ( V_157 ) ;
V_30 -> V_23 -> V_159 = 10000 ;
V_30 -> V_160 = V_161 ;
V_30 -> V_23 -> V_162 = 3 * 5 ;
memcpy ( V_2 -> V_163 [ 0 ] . V_164 , V_2 -> V_165 -> V_166 , V_167 ) ;
V_30 -> V_23 -> V_163 = V_2 -> V_163 ;
V_30 -> V_23 -> V_168 = 1 ;
V_50 = ( V_2 -> V_165 -> V_169 > 1 ) ?
F_46 ( V_170 , V_2 -> V_165 -> V_169 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_50 ; V_9 ++ ) {
memcpy ( V_2 -> V_163 [ V_9 ] . V_164 , V_2 -> V_163 [ V_9 - 1 ] . V_164 ,
V_167 ) ;
V_2 -> V_163 [ V_9 ] . V_164 [ 5 ] ++ ;
V_30 -> V_23 -> V_168 ++ ;
}
F_16 ( V_2 ) ;
V_30 -> V_23 -> V_171 = F_47 ( V_2 ) ;
V_30 -> V_23 -> V_172 = V_173 ;
F_42 ( V_174 & V_175 ) ;
F_42 ( V_176 > F_48 ( V_175 ) ||
V_177 > F_48 ( V_175 ) ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 , V_178 ) )
V_2 -> V_179 = V_176 ;
else
V_2 -> V_179 = V_177 ;
if ( V_2 -> V_165 -> V_180 [ V_181 ] . V_38 )
V_30 -> V_23 -> V_180 [ V_181 ] =
& V_2 -> V_165 -> V_180 [ V_181 ] ;
if ( V_2 -> V_165 -> V_180 [ V_182 ] . V_38 ) {
V_30 -> V_23 -> V_180 [ V_182 ] =
& V_2 -> V_165 -> V_180 [ V_182 ] ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_183 ) &&
F_49 ( & V_2 -> V_72 -> V_73 ,
V_184 ) )
V_30 -> V_23 -> V_180 [ V_182 ] -> V_185 . V_186 |=
V_187 ;
}
V_30 -> V_23 -> V_188 = V_2 -> V_7 -> V_189 ;
if ( V_190 . V_191 != V_192 )
V_30 -> V_23 -> V_147 |= V_193 ;
else
V_30 -> V_23 -> V_147 &= ~ V_193 ;
V_30 -> V_23 -> V_194 = 1 ;
V_30 -> V_23 -> V_195 = V_173 ;
V_30 -> V_23 -> V_196 = V_197 ;
V_30 -> V_23 -> V_198 =
V_199 - 24 - 2 ;
V_30 -> V_23 -> V_200 = V_201 ;
V_30 -> V_23 -> V_202 = V_203 ;
V_30 -> V_23 -> V_204 = 254 ;
V_30 -> V_23 -> V_131 |= V_205 |
V_206 |
V_207 |
V_208 |
V_209 |
V_210 |
V_211 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_212 ) )
V_30 -> V_23 -> V_131 |= V_213 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_214 ) )
V_30 -> V_23 -> V_131 |= V_215 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_216 ) )
V_30 -> V_23 -> V_131 |=
V_217 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_218 ) )
V_30 -> V_23 -> V_131 |= V_219 ;
if ( F_49 ( & V_2 -> V_72 -> V_73 ,
V_220 ) ) {
F_50 ( V_30 -> V_23 ,
V_221 ) ;
F_50 ( V_30 -> V_23 ,
V_222 ) ;
F_50 ( V_30 -> V_23 ,
V_223 ) ;
}
V_2 -> V_224 = V_225 ;
#ifdef F_51
if ( F_2 ( V_2 ) &&
F_52 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_226 . V_147 = V_227 ;
V_30 -> V_23 -> V_226 = & V_2 -> V_226 ;
}
if ( V_2 -> V_72 -> V_228 [ V_229 ] . V_230 &&
V_2 -> V_7 -> V_231 -> V_232 &&
V_2 -> V_7 -> V_231 -> V_233 &&
F_52 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_226 . V_147 |= V_234 |
V_235 |
V_236 |
V_237 |
V_238 ;
if ( ! V_108 . V_109 )
V_2 -> V_226 . V_147 |= V_239 |
V_240 |
V_241 ;
V_2 -> V_226 . V_242 = V_243 ;
V_2 -> V_226 . V_244 = V_245 ;
V_2 -> V_226 . V_246 = V_247 ;
V_2 -> V_226 . V_248 = V_197 ;
V_2 -> V_226 . V_249 = & V_250 ;
V_30 -> V_23 -> V_226 = & V_2 -> V_226 ;
}
#endif
#ifdef F_53
V_2 -> V_251 = V_252 ;
#endif
V_47 = F_54 ( V_2 ) ;
if ( V_47 )
return V_47 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_253 ) ) {
F_55 ( V_2 , L_10 ) ;
V_30 -> V_23 -> V_147 |= V_254 ;
F_38 ( V_30 , V_255 ) ;
}
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_256 ) ) {
F_55 ( V_2 , L_11 ) ;
V_30 -> V_23 -> V_131 |= V_257 ;
}
V_30 -> V_80 |= V_2 -> V_37 -> V_131 ;
if ( ! F_56 ( V_2 ) ) {
V_30 -> V_80 &= ~ ( V_258 |
V_259 ) ;
if ( V_260 )
V_30 -> V_80 |= V_258 ;
}
V_47 = F_57 ( V_2 -> V_30 ) ;
if ( V_47 )
F_58 ( V_2 ) ;
V_2 -> V_261 |= V_262 ;
if ( V_2 -> V_37 -> V_263 )
F_50 ( V_30 -> V_23 ,
V_264 ) ;
return V_47 ;
}
static bool F_59 ( struct V_1 * V_2 ,
struct V_265 * V_266 ,
struct V_267 * V_268 )
{
struct V_136 * V_269 ;
bool V_270 = false ;
if ( F_60 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_61 ( & V_2 -> V_271 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_34;
V_269 = F_62 ( V_266 ) ;
if ( V_269 -> V_272 == V_273 ||
V_269 -> V_272 != V_2 -> V_274 )
goto V_34;
F_63 ( & V_2 -> V_275 , V_268 ) ;
F_64 ( V_2 -> V_30 ) ;
F_1 ( V_2 , V_276 ) ;
F_7 ( V_2 , V_276 ) ;
V_270 = true ;
V_34:
F_65 ( & V_2 -> V_271 ) ;
return V_270 ;
}
static void F_66 ( struct V_29 * V_30 ,
struct V_277 * V_278 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_265 * V_266 = V_278 -> V_266 ;
struct V_279 * V_280 = F_67 ( V_268 ) ;
struct V_281 * V_282 = ( void * ) V_268 -> V_283 ;
if ( F_68 ( V_2 ) ) {
F_69 ( V_2 , L_12 ) ;
goto V_284;
}
if ( V_280 -> V_285 == V_86 &&
! F_14 ( V_286 , & V_2 -> V_15 ) &&
! F_14 ( V_287 , & V_2 -> V_15 ) )
goto V_284;
if ( ( V_280 -> V_278 . V_288 -> type == V_143 ||
V_280 -> V_278 . V_288 -> type == V_146 ) &&
F_70 ( V_282 -> V_289 ) &&
! F_71 ( V_282 -> V_289 ) )
V_266 = NULL ;
if ( V_266 ) {
if ( F_59 ( V_2 , V_266 , V_268 ) )
return;
if ( F_72 ( V_2 , V_268 , V_266 ) )
goto V_284;
return;
}
if ( F_73 ( V_2 , V_268 ) )
goto V_284;
return;
V_284:
F_74 ( V_30 , V_268 ) ;
}
static inline bool F_75 ( const struct V_290 * V_37 )
{
if ( V_108 . V_291 & V_292 )
return false ;
return true ;
}
static inline bool F_76 ( const struct V_290 * V_37 )
{
if ( V_108 . V_291 & V_293 )
return false ;
if ( V_108 . V_291 & V_294 )
return true ;
return true ;
}
static void
F_77 ( struct V_1 * V_2 , struct V_295 * V_288 ,
struct V_265 * V_266 , V_140 V_296 , V_140 V_297 ,
enum V_298 V_299 )
{
struct V_300 * V_301 ;
struct V_302 * V_303 ;
if ( ! F_78 ( V_2 -> V_72 , V_304 ) )
return;
V_301 = F_79 ( V_2 -> V_72 , V_304 ) ;
V_303 = ( void * ) V_301 -> V_283 ;
if ( ! F_80 ( & V_2 -> V_305 ,
F_81 ( V_288 ) , V_301 ) )
return;
switch ( V_299 ) {
case V_306 : {
struct V_136 * V_269 = F_62 ( V_266 ) ;
struct V_307 * V_308 = & V_269 -> V_308 [ V_296 ] ;
F_82 ( V_2 , V_301 , V_303 -> V_309 , V_296 ,
L_13 ,
V_266 -> V_164 , V_296 , V_308 -> V_310 ) ;
break;
}
case V_311 :
F_82 ( V_2 , V_301 , V_303 -> V_312 , V_296 ,
L_14 ,
V_266 -> V_164 , V_296 ) ;
break;
case V_313 :
F_82 ( V_2 , V_301 , V_303 -> V_314 , V_296 ,
L_15 ,
V_266 -> V_164 , V_296 , V_297 ) ;
break;
case V_315 :
F_82 ( V_2 , V_301 , V_303 -> V_316 , V_296 ,
L_16 ,
V_266 -> V_164 , V_296 ) ;
break;
default:
break;
}
}
static int F_83 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_317 * V_318 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_319 = false ;
struct V_265 * V_266 = V_318 -> V_266 ;
enum V_298 V_299 = V_318 -> V_299 ;
V_140 V_296 = V_318 -> V_296 ;
V_140 * V_310 = & V_318 -> V_310 ;
T_2 V_320 = V_318 -> V_320 ;
bool V_321 = V_318 -> V_321 ;
V_140 V_322 = V_318 -> V_322 ;
F_84 ( V_2 , L_17 ,
V_266 -> V_164 , V_296 , V_299 ) ;
if ( ! ( V_2 -> V_165 -> V_323 ) )
return - V_324 ;
switch ( V_299 ) {
case V_325 :
case V_311 :
case V_326 :
case V_327 :
case V_306 :
V_47 = F_12 ( V_2 , V_328 ) ;
if ( V_47 )
return V_47 ;
V_319 = true ;
break;
default:
break;
}
F_85 ( & V_2 -> V_33 ) ;
switch ( V_299 ) {
case V_313 :
if ( ! F_75 ( V_2 -> V_37 ) ) {
V_47 = - V_76 ;
break;
}
V_47 = F_86 ( V_2 , V_266 , V_296 , * V_310 , true , V_320 ,
V_322 ) ;
break;
case V_315 :
V_47 = F_86 ( V_2 , V_266 , V_296 , 0 , false , V_320 ,
V_322 ) ;
break;
case V_325 :
if ( ! F_76 ( V_2 -> V_37 ) ) {
V_47 = - V_76 ;
break;
}
V_47 = F_87 ( V_2 , V_288 , V_266 , V_296 , V_310 ) ;
break;
case V_311 :
V_47 = F_88 ( V_2 , V_288 , V_266 , V_296 ) ;
break;
case V_326 :
case V_327 :
V_47 = F_89 ( V_2 , V_288 , V_266 , V_296 ) ;
break;
case V_306 :
V_47 = F_90 ( V_2 , V_288 , V_266 , V_296 ,
V_320 , V_321 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_76 ;
break;
}
if ( ! V_47 ) {
V_140 V_297 = 0 ;
if ( V_299 == V_313 )
V_297 = * V_310 ;
F_77 ( V_2 , V_288 , V_266 , V_296 ,
V_297 , V_299 ) ;
}
F_91 ( & V_2 -> V_33 ) ;
if ( V_319 )
F_7 ( V_2 , V_328 ) ;
return V_47 ;
}
static void F_92 ( void * V_283 , T_2 * V_329 ,
struct V_295 * V_288 )
{
struct V_1 * V_2 = V_283 ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
V_330 -> V_331 = false ;
V_330 -> V_332 = V_273 ;
F_4 ( & V_2 -> V_333 ) ;
F_94 ( V_2 , & V_330 -> V_334 ) ;
F_5 ( & V_2 -> V_333 ) ;
V_330 -> V_335 = NULL ;
memset ( & V_330 -> V_336 , 0 , sizeof( V_330 -> V_336 ) ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( ! F_96 ( V_337 , & V_2 -> V_15 ) ) {
V_2 -> V_305 . V_338 . V_339 = & V_340 ;
F_97 ( & V_2 -> V_305 ) ;
}
F_10 ( V_2 , V_341 ) ;
F_98 ( V_2 ) ;
V_2 -> V_342 = 0 ;
V_2 -> V_343 = false ;
V_2 -> V_344 = false ;
F_99 ( V_2 ) ;
F_100 ( V_2 -> V_30 ) ;
F_101 ( V_2 -> V_30 , 0 , F_92 , V_2 ) ;
V_2 -> V_345 = NULL ;
V_2 -> V_274 = V_273 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_346 , 0 , sizeof( V_2 -> V_346 ) ) ;
memset ( V_2 -> V_347 , 0 , sizeof( V_2 -> V_347 ) ) ;
memset ( & V_2 -> V_348 , 0 , sizeof( V_2 -> V_348 ) ) ;
memset ( & V_2 -> V_349 , 0 , sizeof( V_2 -> V_349 ) ) ;
F_102 ( V_2 -> V_30 ) ;
F_103 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_350 = 0 ;
V_2 -> V_351 = 0 ;
V_2 -> V_305 . V_338 . V_352 = V_353 ;
V_2 -> V_354 = false ;
F_104 ( V_2 ) ;
}
int F_105 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_355 , & V_2 -> V_15 ) ) {
F_106 ( V_356 , & V_2 -> V_15 ) ;
F_103 ( V_355 , & V_2 -> V_15 ) ;
F_95 ( V_2 ) ;
} else {
F_1 ( V_2 , V_341 ) ;
}
V_47 = F_107 ( V_2 ) ;
if ( V_47 && F_14 ( V_356 , & V_2 -> V_15 ) ) {
F_103 ( V_356 , & V_2 -> V_15 ) ;
F_108 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_109 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_356 , & V_2 -> V_15 ) ) {
F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ;
}
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_105 ( V_2 ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_110 ( struct V_1 * V_2 )
{
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
F_103 ( V_356 , & V_2 -> V_15 ) ;
F_108 ( V_2 , NULL ) ;
V_47 = F_111 ( V_2 , true , NULL ) ;
if ( V_47 )
F_112 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_341 ) ;
F_113 ( V_2 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) &&
F_115 ( V_2 ) )
F_116 ( ! F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ,
L_19 ) ;
}
static void
F_117 ( struct V_29 * V_30 ,
enum V_357 V_358 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_358 ) {
case V_359 :
F_110 ( V_2 ) ;
break;
case V_360 :
F_114 ( V_2 ) ;
break;
}
}
void F_118 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_361 , 0 , sizeof( V_2 -> V_361 ) ) ;
F_119 ( & V_2 -> V_362 ) ;
F_98 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
if ( F_96 ( V_356 , & V_2 -> V_15 ) )
F_101 ( V_2 -> V_30 , 0 ,
F_92 , V_2 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 , V_178 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_179 ; V_9 ++ ) {
if ( F_116 ( V_2 -> V_363 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_363 [ V_9 ] = 0 ;
}
}
}
static void F_122 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_119 ( & V_2 -> V_364 ) ;
F_119 ( & V_2 -> V_365 ) ;
F_119 ( & V_2 -> V_366 ) ;
F_103 ( V_367 , & V_2 -> V_15 ) ;
F_123 ( & V_2 -> V_305 ) ;
F_124 ( & V_2 -> V_368 ) ;
F_124 ( & V_2 -> V_369 ) ;
F_125 ( & V_2 -> V_305 ) ;
F_85 ( & V_2 -> V_33 ) ;
F_118 ( V_2 ) ;
F_91 ( & V_2 -> V_33 ) ;
F_126 ( & V_2 -> V_365 ) ;
}
static struct V_370 * F_127 ( struct V_1 * V_2 )
{
V_140 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_112 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_128 ( struct V_1 * V_2 , struct V_295 * V_288 ,
T_3 V_371 )
{
struct V_372 V_373 = {
. V_374 . V_375 = F_129 ( V_376 ) ,
. V_374 . V_377 =
F_129 ( F_93 ( V_288 ) -> V_20 ) ,
. V_374 . V_378 = F_130 ( 8 * V_371 ) ,
} ;
int V_379 = sizeof( V_373 ) ;
if ( V_371 == V_380 )
V_373 . V_374 . V_378 = F_130 ( V_381 ) ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 , V_382 ) )
V_379 = sizeof( V_373 . V_374 ) ;
return F_131 ( V_2 , V_383 , 0 , V_379 , & V_373 ) ;
}
static int F_132 ( struct V_29 * V_30 ,
struct V_295 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
int V_47 ;
V_330 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_384 ) ;
if ( V_47 )
return V_47 ;
F_85 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_356 , & V_2 -> V_15 ) )
V_330 -> V_385 . V_386 +=
V_330 -> V_385 . V_387 ;
V_47 = F_133 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_388;
if ( V_288 -> type != V_145 )
V_2 -> V_350 ++ ;
if ( V_288 -> type == V_143 ||
V_288 -> type == V_146 ) {
V_47 = F_134 ( V_2 , V_288 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_22 ) ;
goto V_389;
}
V_47 = F_135 ( V_2 , & V_330 -> V_390 ,
0 , V_288 -> type ,
V_391 ) ;
if ( V_47 )
goto V_389;
F_136 ( V_2 , V_288 ) ;
goto V_388;
}
V_330 -> V_131 |= V_30 -> V_80 ;
V_47 = F_137 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_389;
V_47 = F_138 ( V_2 ) ;
if ( V_47 )
goto V_392;
V_47 = F_139 ( V_2 , V_288 , 0 ) ;
if ( V_47 )
goto V_392;
if ( ! V_2 -> V_393 &&
V_288 -> type == V_121 && ! V_288 -> V_394 ) {
V_2 -> V_393 = V_330 ;
V_288 -> V_395 |= V_396 |
V_397 ;
}
if ( V_288 -> type == V_145 ) {
V_330 -> V_335 = F_127 ( V_2 ) ;
if ( ! V_330 -> V_335 ) {
V_47 = - V_398 ;
goto V_399;
}
F_140 ( V_2 , V_330 -> V_335 ) ;
V_47 = F_141 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_400;
V_47 = F_142 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_401;
V_2 -> V_345 = V_288 ;
}
if ( V_288 -> type == V_402 )
V_2 -> V_354 = true ;
F_136 ( V_2 , V_288 ) ;
goto V_388;
V_401:
F_143 ( V_2 , V_288 ) ;
V_400:
F_144 ( V_2 , V_330 -> V_335 ) ;
V_399:
if ( V_2 -> V_393 == V_330 ) {
V_2 -> V_393 = NULL ;
V_288 -> V_395 &= ~ ( V_396 |
V_397 ) ;
}
V_392:
V_330 -> V_335 = NULL ;
F_145 ( V_2 , V_288 ) ;
V_389:
if ( V_288 -> type != V_145 )
V_2 -> V_350 -- ;
V_388:
F_91 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_384 ) ;
return V_47 ;
}
static void F_146 ( struct V_1 * V_2 ,
struct V_295 * V_288 )
{
if ( V_288 -> type == V_145 ) {
F_119 ( & V_2 -> V_362 ) ;
}
}
static void F_147 ( struct V_29 * V_30 ,
struct V_295 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
F_146 ( V_2 , V_288 ) ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_393 == V_330 ) {
V_2 -> V_393 = NULL ;
V_288 -> V_395 &= ~ ( V_396 |
V_397 ) ;
}
F_148 ( V_2 , V_288 ) ;
if ( V_288 -> type == V_143 ||
V_288 -> type == V_146 ) {
#ifdef F_149
if ( V_288 == V_2 -> V_403 ) {
V_2 -> V_403 = NULL ;
V_2 -> V_404 = 0 ;
}
#endif
F_150 ( V_2 , & V_330 -> V_390 ) ;
F_151 ( V_2 , V_288 ) ;
goto V_389;
}
if ( V_288 -> type == V_145 ) {
V_2 -> V_345 = NULL ;
F_152 ( V_2 , V_288 ) ;
F_143 ( V_2 , V_288 ) ;
F_144 ( V_2 , V_330 -> V_335 ) ;
V_330 -> V_335 = NULL ;
}
if ( V_2 -> V_350 && V_288 -> type != V_145 )
V_2 -> V_350 -- ;
F_138 ( V_2 ) ;
F_145 ( V_2 , V_288 ) ;
if ( V_288 -> type == V_402 )
V_2 -> V_354 = false ;
V_389:
F_91 ( & V_2 -> V_33 ) ;
}
static int F_153 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_154 ( void * V_405 , T_2 * V_329 ,
struct V_295 * V_288 )
{
struct V_406 * V_283 = V_405 ;
struct V_1 * V_2 = V_283 -> V_2 ;
struct V_407 * V_373 = V_2 -> V_408 ;
struct V_409 V_410 = {
. V_20 = V_411 ,
. V_147 = V_412 ,
. V_413 [ 0 ] = V_414 ,
} ;
int V_47 , V_379 ;
if ( F_15 ( V_283 -> V_415 >= V_416 ) )
return;
if ( V_288 -> type != V_121 ||
! V_288 -> V_417 . V_418 )
return;
V_373 -> V_415 = V_283 -> V_415 ++ ;
memcpy ( V_373 -> V_419 , V_288 -> V_417 . V_419 , V_167 ) ;
V_379 = F_155 ( sizeof( * V_373 ) + V_373 -> V_420 * V_167 , 4 ) ;
V_410 . V_379 [ 0 ] = V_379 ;
V_410 . V_283 [ 0 ] = V_373 ;
V_47 = F_156 ( V_2 , & V_410 ) ;
if ( V_47 )
F_112 ( V_2 , L_23 , V_47 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_406 V_421 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_408 ) )
return;
F_158 (
V_2 -> V_30 , V_422 ,
F_154 , & V_421 ) ;
}
static T_4 F_159 ( struct V_29 * V_30 ,
struct V_423 * V_424 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_407 * V_373 ;
struct V_425 * V_164 ;
int V_426 ;
bool V_427 ;
int V_379 ;
V_426 = F_160 ( V_424 ) ;
V_427 = V_426 > V_428 ||
V_429 ;
if ( V_427 )
V_426 = 0 ;
V_379 = F_155 ( sizeof( * V_373 ) + V_426 * V_167 , 4 ) ;
V_373 = F_161 ( V_379 , V_430 ) ;
if ( ! V_373 )
return 0 ;
if ( V_427 ) {
V_373 -> V_427 = 1 ;
return ( T_4 ) ( unsigned long ) V_373 ;
}
F_162 (addr, mc_list) {
F_163 ( V_2 , L_24 ,
V_373 -> V_420 , V_164 -> V_164 ) ;
memcpy ( & V_373 -> V_431 [ V_373 -> V_420 * V_167 ] ,
V_164 -> V_164 , V_167 ) ;
V_373 -> V_420 ++ ;
}
return ( T_4 ) ( unsigned long ) V_373 ;
}
static void F_164 ( struct V_29 * V_30 ,
unsigned int V_432 ,
unsigned int * V_433 ,
T_4 V_434 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_407 * V_373 = ( void * ) ( unsigned long ) V_434 ;
F_85 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_408 ) ;
V_2 -> V_408 = V_373 ;
if ( ! V_373 )
goto V_34;
if ( V_432 & V_435 )
V_373 -> V_427 = ! ! ( * V_433 & V_435 ) ;
if ( V_373 -> V_427 )
V_373 -> V_420 = 0 ;
F_157 ( V_2 ) ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
* V_433 = 0 ;
}
static void F_165 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
unsigned int V_436 ,
unsigned int V_432 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_432 & V_437 ) )
return;
if ( V_288 -> type != V_121 || ! V_288 -> V_417 . V_418 ||
! V_288 -> V_394 )
return;
F_85 ( & V_2 -> V_33 ) ;
F_166 ( V_2 , V_288 , false , NULL ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void
F_167 ( struct V_295 * V_288 ,
const struct V_438 * V_439 ,
struct V_438 * V_440 )
{
struct V_441 * V_442 ;
int V_9 ;
memcpy ( V_440 , V_439 , sizeof( * V_440 ) ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_440 -> V_443 ) ; V_9 ++ ) {
V_442 = & V_440 -> V_443 [ V_9 ] ;
if ( ! V_442 -> V_444 )
break;
switch ( V_442 -> V_445 ) {
case F_130 ( V_446 ) :
if ( V_288 -> V_417 . V_447 != 1 ) {
V_442 -> V_444 = 0 ;
continue;
}
V_442 -> V_448 = V_288 -> V_417 . V_449 [ 0 ] ;
break;
case F_130 ( V_450 ) :
V_442 -> V_448 = * ( V_451 * ) & V_288 -> V_164 [ 2 ] ;
break;
default:
break;
}
V_442 -> V_445 = 0 ;
V_440 -> V_452 ++ ;
}
}
static void F_168 ( void * V_405 , T_2 * V_329 ,
struct V_295 * V_288 )
{
struct V_453 * V_283 = V_405 ;
struct V_1 * V_2 = V_283 -> V_2 ;
struct V_454 * V_373 = V_283 -> V_373 ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
struct V_455 * V_456 ;
int V_9 ;
if ( F_8 ( V_330 -> V_20 >= F_43 ( V_373 -> V_457 ) ) )
return;
V_456 = & V_373 -> V_457 [ V_330 -> V_20 ] ;
if ( V_288 -> type != V_121 || V_288 -> V_394 ||
! V_288 -> V_417 . V_418 )
return;
V_456 -> V_458 = 1 ;
for ( V_9 = 0 ; V_2 -> V_251 [ V_9 ] . V_443 [ 0 ] . V_444 ; V_9 ++ ) {
if ( F_15 ( V_283 -> V_459 >=
F_43 ( V_373 -> V_460 ) ) ) {
V_456 -> V_458 = 0 ;
V_456 -> V_461 = 0 ;
break;
}
F_167 ( V_288 ,
& V_2 -> V_251 [ V_9 ] ,
& V_373 -> V_460 [ V_283 -> V_459 ] ) ;
if ( ! V_373 -> V_460 [ V_283 -> V_459 ] . V_452 )
continue;
V_456 -> V_461 |=
F_130 ( F_45 ( V_283 -> V_459 ) ) ;
V_283 -> V_459 ++ ;
}
}
bool F_169 ( struct V_1 * V_2 ,
struct V_454 * V_373 )
{
struct V_453 V_421 = {
. V_2 = V_2 ,
. V_373 = V_373 ,
} ;
if ( V_462 )
return false ;
memset ( V_373 , 0 , sizeof( * V_373 ) ) ;
V_373 -> V_463 = F_43 ( V_373 -> V_460 ) ;
V_373 -> V_464 = F_43 ( V_373 -> V_457 ) ;
#ifdef F_170
if ( V_2 -> V_465 . V_466 ) {
memcpy ( V_373 -> V_460 , & V_2 -> V_465 . V_373 . V_460 ,
sizeof( V_373 -> V_460 ) ) ;
memcpy ( V_373 -> V_457 , & V_2 -> V_465 . V_373 . V_457 ,
sizeof( V_373 -> V_457 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_251 )
return false ;
F_171 (
V_2 -> V_30 , V_422 ,
F_168 , & V_421 ) ;
return true ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_454 V_373 ;
if ( ! ( V_2 -> V_72 -> V_73 . V_147 & V_467 ) )
return 0 ;
if ( ! F_169 ( V_2 , & V_373 ) )
return 0 ;
return F_131 ( V_2 , V_468 , 0 ,
sizeof( V_373 ) , & V_373 ) ;
}
static inline int F_172 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_173 ( struct V_1 * V_2 ,
struct V_295 * V_288 )
{
struct V_469 V_373 = {} ;
memcpy ( V_373 . V_470 , V_288 -> V_417 . V_471 . V_472 ,
V_473 ) ;
memcpy ( V_373 . V_474 , V_288 -> V_417 . V_471 . V_475 ,
V_476 ) ;
return F_131 ( V_2 ,
F_174 ( V_477 ,
V_478 ) ,
0 , sizeof( V_373 ) , & V_373 ) ;
}
static void F_175 ( void * V_405 , T_2 * V_329 ,
struct V_295 * V_288 )
{
if ( V_288 -> V_479 ) {
struct V_480 * V_481 = V_405 ;
F_176 ( V_288 ,
( T_2 * ) & V_481 -> V_470 ,
( T_2 * ) & V_481 -> V_474 ) ;
}
}
void F_177 ( struct V_1 * V_2 ,
struct V_482 * V_483 )
{
struct V_484 * V_485 = F_178 ( V_483 ) ;
struct V_480 * V_481 = ( void * ) V_485 -> V_283 ;
F_158 (
V_2 -> V_30 , V_422 ,
F_175 , V_481 ) ;
}
static void F_179 ( struct V_1 * V_2 ,
struct V_295 * V_288 ,
struct V_486 * V_417 ,
T_1 V_487 )
{
struct V_138 * V_330 = F_93 ( V_288 ) ;
int V_47 ;
if ( V_487 & V_488 && V_417 -> V_418 )
F_180 ( V_2 , V_288 ) ;
if ( V_487 & V_488 && ! V_417 -> V_418 &&
V_330 -> V_489 )
F_181 ( V_288 , V_490 ,
0 , 0 ) ;
if ( V_487 & V_491 && ! V_330 -> V_492 )
memcpy ( V_330 -> V_419 , V_417 -> V_419 , V_167 ) ;
V_47 = F_166 ( V_2 , V_288 , false , V_330 -> V_419 ) ;
if ( V_47 )
F_112 ( V_2 , L_25 , V_288 -> V_164 ) ;
memcpy ( V_330 -> V_419 , V_417 -> V_419 , V_167 ) ;
V_330 -> V_492 = V_417 -> V_418 ;
if ( V_487 & V_488 ) {
if ( V_417 -> V_418 ) {
F_182 ( V_2 , true ) ;
memset ( & V_330 -> V_385 , 0 ,
sizeof( V_330 -> V_385 ) ) ;
V_47 = F_111 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_112 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_356 ,
& V_2 -> V_15 ) ) {
T_1 V_493 = ( 11 * V_288 -> V_417 . V_494 ) / 10 ;
F_183 ( V_2 , V_288 , V_493 , V_493 ,
5 * V_493 , false ) ;
}
F_184 ( V_2 , V_288 , false ) ;
F_185 ( V_2 , V_288 ) ;
if ( V_288 -> V_394 ) {
F_1 ( V_2 , V_495 ) ;
F_186 ( V_2 , V_288 ,
V_496 ,
V_497 ) ;
}
} else if ( V_330 -> V_332 != V_273 ) {
F_116 ( F_184 ( V_2 , V_288 , false ) ,
L_27 ) ;
if ( ! F_14 ( V_356 ,
& V_2 -> V_15 ) ) {
V_47 = F_187 ( V_2 , V_288 ,
V_330 -> V_332 ) ;
if ( V_47 )
F_112 ( V_2 ,
L_28 ) ;
if ( V_2 -> V_274 == V_330 -> V_332 )
V_2 -> V_274 =
V_273 ;
V_330 -> V_332 = V_273 ;
}
V_47 = F_111 ( V_2 , false , NULL ) ;
if ( V_47 )
F_112 ( V_2 , L_26 ) ;
if ( V_288 -> V_394 )
F_7 ( V_2 , V_495 ) ;
V_47 = F_166 ( V_2 , V_288 , false , NULL ) ;
if ( V_47 )
F_112 ( V_2 ,
L_29 ,
V_288 -> V_164 ) ;
}
if ( F_14 ( V_356 , & V_2 -> V_15 ) &&
( V_487 & V_498 ) && V_288 -> V_479 ) {
V_47 = F_173 ( V_2 , V_288 ) ;
if ( V_47 )
F_112 ( V_2 ,
L_30 ) ;
}
F_157 ( V_2 ) ;
F_172 ( V_2 ) ;
V_330 -> V_336 . V_499 = 0 ;
F_188 ( V_2 ) ;
F_186 ( V_2 , V_288 , V_500 ,
V_501 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_178 ) )
F_189 ( V_2 ) ;
}
if ( V_487 & V_502 ) {
F_190 ( V_2 , V_288 ) ;
F_184 ( V_2 , V_288 , false ) ;
F_8 ( F_191 ( V_2 , V_288 , 0 ) ) ;
}
if ( V_487 & ( V_503 | V_504 | V_505 |
V_502 ) ) {
V_47 = F_138 ( V_2 ) ;
if ( V_47 )
F_112 ( V_2 , L_31 ) ;
}
if ( V_487 & V_506 ) {
F_192 ( V_2 , L_32 ,
V_417 -> V_507 ) ;
F_128 ( V_2 , V_288 , V_417 -> V_507 ) ;
}
if ( V_487 & V_508 ) {
F_163 ( V_2 , L_33 ) ;
V_330 -> V_336 . V_509 = 0 ;
if ( V_330 -> V_336 . V_510 ) {
V_47 = F_191 ( V_2 , V_288 , 0 ) ;
if ( V_47 )
F_112 ( V_2 ,
L_34 ) ;
}
}
if ( V_487 & V_511 ) {
F_163 ( V_2 , L_35 ) ;
F_172 ( V_2 ) ;
}
}
static int F_193 ( struct V_29 * V_30 ,
struct V_295 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_512 ) ;
if ( V_47 )
return V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_194 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_388;
if ( V_288 -> type == V_143 )
F_180 ( V_2 , V_288 ) ;
V_330 -> V_513 = 0 ;
V_47 = F_137 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_388;
V_47 = F_141 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_514;
V_47 = F_195 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_401;
V_47 = F_196 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_515;
V_330 -> V_516 = true ;
F_138 ( V_2 ) ;
V_47 = F_111 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_517;
if ( V_288 -> V_394 && V_2 -> V_345 )
F_166 ( V_2 , V_2 -> V_345 , false , NULL ) ;
F_1 ( V_2 , V_518 ) ;
F_188 ( V_2 ) ;
if ( F_197 ( V_2 ) > 1 )
F_113 ( V_2 ) ;
goto V_388;
V_517:
F_138 ( V_2 ) ;
V_330 -> V_516 = false ;
F_198 ( V_2 , V_288 ) ;
V_515:
F_199 ( V_2 , V_288 ) ;
V_401:
F_143 ( V_2 , V_288 ) ;
V_514:
F_145 ( V_2 , V_288 ) ;
V_388:
F_91 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_512 ) ;
return V_47 ;
}
static void F_200 ( struct V_29 * V_30 ,
struct V_295 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
F_146 ( V_2 , V_288 ) ;
F_85 ( & V_2 -> V_33 ) ;
if ( F_201 ( V_2 -> V_519 ) == V_288 ) {
F_202 ( V_2 , V_330 ,
& V_330 -> V_334 ) ;
F_203 ( V_2 -> V_519 , NULL ) ;
V_330 -> V_520 = false ;
}
if ( F_201 ( V_2 -> V_521 ) == V_288 ) {
F_203 ( V_2 -> V_521 , NULL ) ;
V_2 -> V_522 = 0 ;
}
V_330 -> V_516 = false ;
V_2 -> V_523 = 0 ;
F_188 ( V_2 ) ;
F_7 ( V_2 , V_518 ) ;
if ( V_288 -> V_394 && V_2 -> V_345 )
F_166 ( V_2 , V_2 -> V_345 , false , NULL ) ;
F_111 ( V_2 , false , NULL ) ;
if ( ! F_49 ( & V_2 -> V_72 -> V_73 , V_524 ) )
F_199 ( V_2 , V_288 ) ;
F_198 ( V_2 , V_288 ) ;
if ( F_49 ( & V_2 -> V_72 -> V_73 , V_524 ) )
F_199 ( V_2 , V_288 ) ;
F_143 ( V_2 , V_288 ) ;
F_138 ( V_2 ) ;
F_145 ( V_2 , V_288 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void
F_204 ( struct V_1 * V_2 ,
struct V_295 * V_288 ,
struct V_486 * V_417 ,
T_1 V_487 )
{
struct V_138 * V_330 = F_93 ( V_288 ) ;
if ( ! V_330 -> V_516 )
return;
if ( V_487 & ( V_525 | V_526 |
V_527 | V_505 ) &&
F_166 ( V_2 , V_288 , false , NULL ) )
F_112 ( V_2 , L_25 , V_288 -> V_164 ) ;
if ( V_487 & V_528 &&
F_194 ( V_2 , V_288 ) )
F_205 ( V_2 , L_36 ) ;
if ( V_487 & V_506 ) {
F_192 ( V_2 , L_32 ,
V_417 -> V_507 ) ;
F_128 ( V_2 , V_288 , V_417 -> V_507 ) ;
}
}
static void F_206 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_486 * V_417 ,
T_1 V_487 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_529 ) )
return;
F_85 ( & V_2 -> V_33 ) ;
if ( V_487 & V_530 && ! V_417 -> V_531 )
F_207 ( V_2 , V_532 , true ) ;
switch ( V_288 -> type ) {
case V_121 :
F_179 ( V_2 , V_288 , V_417 , V_487 ) ;
break;
case V_143 :
case V_146 :
F_204 ( V_2 , V_288 , V_417 , V_487 ) ;
break;
case V_402 :
if ( V_487 & V_498 )
F_173 ( V_2 , V_288 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_91 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_529 ) ;
}
static int F_208 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_533 * V_534 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_534 -> V_535 . V_38 == 0 ||
V_534 -> V_535 . V_38 > V_2 -> V_72 -> V_73 . V_536 )
return - V_76 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_209 ( V_2 , V_288 , & V_534 -> V_535 , & V_534 -> V_537 ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_210 ( struct V_29 * V_30 ,
struct V_295 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_342 & V_538 )
F_207 ( V_2 , V_538 , true ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void
F_211 ( struct V_29 * V_30 ,
struct V_265 * V_266 , V_140 V_539 ,
int V_540 ,
enum V_541 V_542 ,
bool V_543 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_212 ( V_2 , V_266 , V_542 , V_540 ,
V_539 , V_543 , false ) ;
}
static void
F_213 ( struct V_29 * V_30 ,
struct V_265 * V_266 , V_140 V_539 ,
int V_540 ,
enum V_541 V_542 ,
bool V_543 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_212 ( V_2 , V_266 , V_542 , V_540 ,
V_539 , V_543 , true ) ;
}
static void F_214 ( struct V_29 * V_30 ,
enum V_544 V_373 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_269 = F_62 ( V_266 ) ;
unsigned long V_545 = 0 , V_539 = 0 ;
int V_296 ;
if ( F_8 ( F_41 ( V_2 ) ) )
return;
F_4 ( & V_269 -> V_546 ) ;
for ( V_296 = 0 ; V_296 < V_547 ; V_296 ++ ) {
struct V_307 * V_308 = & V_269 -> V_308 [ V_296 ] ;
if ( V_308 -> V_548 == V_549 )
continue;
F_215 ( V_308 -> V_548 , & V_545 ) ;
if ( F_216 ( V_2 , V_308 ) == 0 )
continue;
F_215 ( V_296 , & V_539 ) ;
}
switch ( V_373 ) {
case V_550 :
F_217 (tid, &tids, IWL_MAX_TID_COUNT)
F_218 ( V_266 , V_296 , true ) ;
if ( V_545 )
F_219 ( V_2 -> V_7 , V_545 , true ) ;
break;
case V_551 :
if ( F_8 ( V_269 -> V_272 == V_273 ) )
break;
if ( V_545 )
F_219 ( V_2 -> V_7 , V_545 , false ) ;
F_220 ( V_2 , V_266 ) ;
break;
default:
break;
}
F_5 ( & V_269 -> V_546 ) ;
}
static void F_221 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
enum V_544 V_373 ,
struct V_265 * V_266 )
{
F_214 ( V_30 , V_373 , V_266 ) ;
}
void F_222 ( struct V_1 * V_2 , struct V_482 * V_483 )
{
struct V_484 * V_485 = F_178 ( V_483 ) ;
struct V_552 * V_481 = ( void * ) V_485 -> V_283 ;
struct V_265 * V_266 ;
struct V_136 * V_269 ;
bool V_553 = ( V_481 -> type != V_554 ) ;
if ( F_8 ( V_481 -> V_272 >= F_43 ( V_2 -> V_555 ) ) )
return;
F_223 () ;
V_266 = F_224 ( V_2 -> V_555 [ V_481 -> V_272 ] ) ;
if ( F_8 ( F_23 ( V_266 ) ) ) {
F_225 () ;
return;
}
V_269 = F_62 ( V_266 ) ;
if ( ! V_269 -> V_288 ||
V_269 -> V_288 -> type != V_143 ) {
F_225 () ;
return;
}
if ( V_269 -> V_553 != V_553 ) {
V_269 -> V_553 = V_553 ;
F_214 ( V_2 -> V_30 ,
V_553 ? V_550 : V_551 ,
V_266 ) ;
F_226 ( V_266 , V_553 ) ;
}
if ( V_553 ) {
switch ( V_481 -> type ) {
case V_554 :
case V_556 :
break;
case V_557 :
F_227 ( V_266 , V_558 ) ;
break;
case V_559 :
F_228 ( V_266 ) ;
break;
default:
break;
}
}
F_225 () ;
}
static void F_229 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_560 = F_62 ( V_266 ) ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_266 == F_201 ( V_2 -> V_555 [ V_560 -> V_272 ] ) )
F_230 ( V_2 -> V_555 [ V_560 -> V_272 ] ,
F_231 ( - V_49 ) ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void F_232 ( struct V_1 * V_2 , struct V_295 * V_288 ,
const T_2 * V_419 )
{
if ( ! ( V_2 -> V_72 -> V_73 . V_147 & V_561 ) )
return;
if ( V_288 -> V_394 && ! F_233 ( V_2 ) ) {
V_288 -> V_395 &= ~ V_562 ;
return;
}
if ( ! V_288 -> V_394 &&
( V_108 . V_563 & V_564 ) ) {
V_288 -> V_395 &= ~ V_562 ;
return;
}
V_288 -> V_395 |= V_562 ;
}
static void
F_234 ( struct V_1 * V_2 ,
struct V_295 * V_288 , T_2 * V_565 ,
enum V_566 V_299 )
{
struct V_300 * V_301 ;
struct V_567 * V_568 ;
if ( ! F_78 ( V_2 -> V_72 , V_569 ) )
return;
V_301 = F_79 ( V_2 -> V_72 , V_569 ) ;
V_568 = ( void * ) V_301 -> V_283 ;
if ( ! F_80 ( & V_2 -> V_305 ,
F_81 ( V_288 ) , V_301 ) )
return;
if ( ! ( V_568 -> V_570 & F_45 ( V_299 ) ) )
return;
if ( V_568 -> V_571 &&
memcmp ( V_568 -> V_572 , V_565 , V_167 ) != 0 )
return;
F_235 ( & V_2 -> V_305 , V_301 ,
L_37 ,
V_565 , V_299 ) ;
}
static void F_236 ( struct V_1 * V_2 ,
struct V_136 * V_560 )
{
struct V_307 * V_308 ;
struct V_267 * V_268 ;
int V_9 ;
F_4 ( & V_560 -> V_546 ) ;
for ( V_9 = 0 ; V_9 <= V_547 ; V_9 ++ ) {
V_308 = & V_560 -> V_308 [ V_9 ] ;
while ( ( V_268 = F_237 ( & V_308 -> V_573 ) ) ) {
struct V_279 * V_280 = F_67 ( V_268 ) ;
F_238 ( V_2 , F_45 ( V_280 -> V_285 ) ) ;
F_74 ( V_2 -> V_30 , V_268 ) ;
}
}
F_5 ( & V_560 -> V_546 ) ;
}
static int F_239 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_265 * V_266 ,
enum V_574 V_575 ,
enum V_574 V_576 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
struct V_136 * V_560 = F_62 ( V_266 ) ;
int V_47 ;
F_163 ( V_2 , L_38 ,
V_266 -> V_164 , V_575 , V_576 ) ;
if ( F_15 ( ! V_330 -> V_335 ) )
return - V_76 ;
if ( V_575 == V_577 &&
V_576 == V_578 ) {
F_236 ( V_2 , V_560 ) ;
F_119 ( & V_2 -> V_366 ) ;
}
F_85 ( & V_2 -> V_33 ) ;
V_560 -> V_492 = V_576 >= V_579 ;
if ( V_575 == V_578 &&
V_576 == V_577 ) {
if ( V_288 -> type == V_121 &&
V_288 -> V_417 . V_494 < 16 ) {
F_112 ( V_2 ,
L_39 ,
V_266 -> V_164 , V_288 -> V_417 . V_494 ) ;
V_47 = - V_76 ;
goto V_388;
}
if ( V_266 -> V_580 &&
( V_288 -> V_394 ||
F_240 ( V_2 , NULL ) ==
V_581 ||
F_197 ( V_2 ) > 1 ) ) {
F_163 ( V_2 , L_40 ) ;
V_47 = - V_582 ;
goto V_388;
}
V_47 = F_241 ( V_2 , V_288 , V_266 ) ;
if ( V_266 -> V_580 && V_47 == 0 ) {
F_242 ( V_2 , V_288 , true ) ;
F_234 ( V_2 , V_288 , V_266 -> V_164 ,
V_583 ) ;
}
} else if ( V_575 == V_577 &&
V_576 == V_584 ) {
V_2 -> V_585 = true ;
F_232 ( V_2 , V_288 , V_266 -> V_164 ) ;
V_47 = 0 ;
} else if ( V_575 == V_584 &&
V_576 == V_579 ) {
if ( V_288 -> type == V_143 ) {
V_330 -> V_513 ++ ;
F_166 ( V_2 , V_288 , false , NULL ) ;
}
F_243 ( V_2 , V_266 , V_330 -> V_335 -> V_586 -> V_587 ,
true ) ;
V_47 = F_244 ( V_2 , V_288 , V_266 ) ;
} else if ( V_575 == V_579 &&
V_576 == V_588 ) {
if ( F_197 ( V_2 ) > 1 )
F_113 ( V_2 ) ;
if ( V_266 -> V_580 )
F_234 ( V_2 , V_288 , V_266 -> V_164 ,
V_589 ) ;
F_8 ( F_191 ( V_2 , V_288 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_575 == V_588 &&
V_576 == V_579 ) {
F_8 ( F_139 ( V_2 , V_288 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_575 == V_579 &&
V_576 == V_584 ) {
if ( V_288 -> type == V_143 ) {
V_330 -> V_513 -- ;
F_166 ( V_2 , V_288 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_575 == V_584 &&
V_576 == V_577 ) {
V_47 = 0 ;
} else if ( V_575 == V_577 &&
V_576 == V_578 ) {
V_47 = F_245 ( V_2 , V_288 , V_266 ) ;
if ( V_266 -> V_580 ) {
F_242 ( V_2 , V_288 , false ) ;
F_234 ( V_2 , V_288 , V_266 -> V_164 ,
V_590 ) ;
}
} else {
V_47 = - V_17 ;
}
V_388:
F_91 ( & V_2 -> V_33 ) ;
if ( V_266 -> V_580 && V_47 == 0 ) {
if ( V_575 == V_578 &&
V_576 == V_577 )
F_246 ( V_266 , V_591 ) ;
else if ( V_575 == V_577 &&
V_576 == V_578 )
F_247 ( V_266 , V_591 ) ;
}
return V_47 ;
}
static int F_248 ( struct V_29 * V_30 , T_1 V_592 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_224 = V_592 ;
return 0 ;
}
static void F_249 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_265 * V_266 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_288 -> type == V_121 &&
V_27 & V_593 )
F_184 ( V_2 , V_288 , false ) ;
}
static int F_250 ( struct V_29 * V_30 ,
struct V_295 * V_288 , V_140 V_594 ,
const struct V_595 * V_318 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
V_330 -> V_596 [ V_594 ] = * V_318 ;
if ( V_288 -> type == V_145 ) {
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_166 ( V_2 , V_288 , false , NULL ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_251 ( struct V_29 * V_30 ,
struct V_295 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_597 = V_598 ;
T_1 V_599 = V_600 ;
if ( F_15 ( V_288 -> V_417 . V_418 ) )
return;
if ( F_12 ( V_2 , V_601 ) )
return;
F_85 ( & V_2 -> V_33 ) ;
F_183 ( V_2 , V_288 , V_597 , V_599 , 500 , false ) ;
F_91 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_601 ) ;
}
static int F_252 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_602 * V_535 ,
struct V_603 * V_537 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
if ( ! V_288 -> V_417 . V_531 ) {
V_47 = - V_582 ;
goto V_34;
}
V_47 = F_253 ( V_2 , V_288 , V_535 , V_537 , V_532 ) ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_254 ( struct V_29 * V_30 ,
struct V_295 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_342 & V_532 ) ) {
F_91 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_207 ( V_2 , V_532 , false ) ;
F_91 ( & V_2 -> V_33 ) ;
F_255 ( V_2 ) ;
return V_47 ;
}
static int F_256 ( struct V_29 * V_30 ,
enum V_604 V_373 ,
struct V_295 * V_288 ,
struct V_265 * V_266 ,
struct V_605 * V_606 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_269 ;
struct V_607 * V_608 ;
int V_609 = V_606 -> V_609 ;
int V_47 ;
T_2 V_610 ;
if ( V_108 . V_109 ) {
F_163 ( V_2 , L_41 ) ;
return - V_611 ;
}
switch ( V_606 -> V_115 ) {
case V_54 :
V_606 -> V_147 |= V_612 ;
V_606 -> V_147 |= V_613 ;
break;
case V_55 :
case V_106 :
case V_107 :
if ( ! F_41 ( V_2 ) )
V_606 -> V_147 |= V_613 ;
break;
case V_111 :
case V_112 :
case V_113 :
F_15 ( ! F_257 ( V_30 , V_110 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_288 -> type != V_121 )
return 0 ;
break;
default:
if ( V_30 -> V_119 &&
V_30 -> V_129 -> V_115 == V_606 -> V_115 )
V_606 -> V_147 |= V_613 ;
else
return - V_611 ;
}
F_85 ( & V_2 -> V_33 ) ;
switch ( V_373 ) {
case V_614 :
if ( ( V_288 -> type == V_146 ||
V_288 -> type == V_143 ) && ! V_266 ) {
if ( V_606 -> V_115 == V_111 ||
V_606 -> V_115 == V_112 ||
V_606 -> V_115 == V_113 )
V_47 = - V_611 ;
else
V_47 = 0 ;
if ( V_606 -> V_115 != V_106 &&
V_606 -> V_115 != V_107 &&
! F_41 ( V_2 ) ) {
V_606 -> V_615 = V_616 ;
break;
}
}
if ( F_14 ( V_356 , & V_2 -> V_15 ) &&
V_606 -> V_615 == V_616 ) {
F_163 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_356 , & V_2 -> V_15 ) &&
V_266 && F_39 ( V_2 ) &&
V_606 -> V_147 & V_617 &&
( V_606 -> V_115 == V_55 ||
V_606 -> V_115 == V_106 ||
V_606 -> V_115 == V_107 ) ) {
struct V_618 V_619 ;
int V_296 , V_620 ;
V_269 = F_62 ( V_266 ) ;
F_8 ( F_201 ( V_269 -> V_608 [ V_609 ] ) ) ;
V_608 = F_161 ( sizeof( * V_608 ) +
V_2 -> V_7 -> V_77 *
sizeof( V_608 -> V_620 [ 0 ] ) ,
V_621 ) ;
if ( ! V_608 ) {
V_47 = - V_622 ;
break;
}
for ( V_296 = 0 ; V_296 < V_547 ; V_296 ++ ) {
F_258 ( V_606 , V_296 , & V_619 ) ;
for ( V_620 = 0 ; V_620 < V_2 -> V_7 -> V_77 ; V_620 ++ )
memcpy ( V_608 -> V_620 [ V_620 ] . V_623 [ V_296 ] ,
V_619 . V_624 . V_623 ,
V_625 ) ;
}
F_230 ( V_269 -> V_608 [ V_609 ] , V_608 ) ;
}
if ( F_14 ( V_356 , & V_2 -> V_15 ) )
V_610 = V_606 -> V_615 ;
else
V_610 = V_616 ;
F_163 ( V_2 , L_43 ) ;
V_47 = F_259 ( V_2 , V_288 , V_266 , V_606 , V_610 ) ;
if ( V_47 ) {
F_205 ( V_2 , L_44 ) ;
V_606 -> V_615 = V_616 ;
V_47 = 0 ;
}
break;
case V_626 :
if ( V_606 -> V_615 == V_616 ) {
V_47 = 0 ;
break;
}
if ( V_266 && F_39 ( V_2 ) &&
V_606 -> V_147 & V_617 &&
( V_606 -> V_115 == V_55 ||
V_606 -> V_115 == V_106 ||
V_606 -> V_115 == V_107 ) ) {
V_269 = F_62 ( V_266 ) ;
V_608 = F_260 (
V_269 -> V_608 [ V_609 ] ,
F_261 ( & V_2 -> V_33 ) ) ;
F_203 ( V_269 -> V_608 [ V_609 ] , NULL ) ;
if ( V_608 )
F_262 ( V_608 , V_627 ) ;
}
F_163 ( V_2 , L_45 ) ;
V_47 = F_263 ( V_2 , V_288 , V_266 , V_606 ) ;
break;
default:
V_47 = - V_76 ;
}
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_264 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_605 * V_628 ,
struct V_265 * V_266 ,
T_1 V_629 , V_140 * V_630 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_628 -> V_615 == V_616 )
return;
F_265 ( V_2 , V_288 , V_628 , V_266 , V_629 , V_630 ) ;
}
static bool F_266 ( struct V_631 * V_632 ,
struct V_484 * V_485 , void * V_283 )
{
struct V_1 * V_2 =
F_267 ( V_632 , struct V_1 , V_632 ) ;
struct V_633 * V_32 ;
int V_634 = F_268 ( V_485 ) ;
struct V_635 * V_636 = V_283 ;
if ( F_8 ( V_485 -> V_282 . V_373 != V_637 ) )
return true ;
if ( F_15 ( V_634 != sizeof( * V_32 ) ) ) {
F_112 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_485 -> V_283 ;
F_269 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_638 ) ;
V_636 -> V_639 = F_44 ( V_32 -> V_638 ) ;
F_269 ( V_2 , L_48 ,
V_636 -> V_639 ) ;
F_4 ( & V_2 -> V_333 ) ;
F_270 ( & V_636 -> V_640 , & V_2 -> V_641 ) ;
F_5 ( & V_2 -> V_333 ) ;
return true ;
}
static int F_271 ( struct V_1 * V_2 ,
struct V_642 * V_586 ,
struct V_295 * V_288 ,
int V_597 )
{
int V_643 , V_644 = V_645 ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
struct V_635 * V_636 = & V_330 -> V_646 ;
static const V_140 V_647 [] = { V_637 } ;
struct V_648 V_649 ;
T_1 V_650 = V_288 -> V_417 . V_651 *
V_288 -> V_417 . V_494 ;
T_1 V_652 , V_653 ;
struct V_654 V_655 = {
. V_299 = F_129 ( V_656 ) ,
. V_657 =
F_129 ( F_272 ( V_658 , 0 ) ) ,
. V_659 = F_129 ( V_2 -> V_660 . V_272 ) ,
. V_661 . V_587 = ( V_586 -> V_587 == V_181 ) ?
V_662 : V_663 ,
. V_661 . V_586 = V_586 -> V_664 ,
. V_661 . V_665 = V_666 ,
. V_667 = F_129 ( F_273 ( V_2 -> V_7 , V_644 ) ) ,
} ;
V_653 = V_668 ;
V_652 = F_274 ( V_597 ) ;
if ( V_288 -> V_417 . V_418 ) {
V_653 = F_275 ( T_1 , V_650 * 3 , V_669 ) ;
if ( V_650 <= V_652 ) {
V_652 = V_650 - V_670 ;
if ( V_652 <= V_671 )
V_652 = V_650 -
V_672 ;
}
}
V_655 . V_597 = F_129 ( V_652 ) ;
V_655 . V_673 = F_129 ( V_653 ) ;
F_269 ( V_2 ,
L_49 ,
V_586 -> V_664 , V_652 , V_597 , V_653 ,
V_650 ) ;
memcpy ( V_655 . V_674 , V_288 -> V_164 , V_167 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_333 ) ;
if ( F_8 ( V_636 -> V_20 == V_637 ) ) {
F_5 ( & V_2 -> V_333 ) ;
return - V_17 ;
}
V_636 -> V_288 = V_288 ;
V_636 -> V_597 = V_597 ;
V_636 -> V_20 = V_637 ;
F_5 ( & V_2 -> V_333 ) ;
F_276 ( & V_2 -> V_632 , & V_649 ,
V_647 ,
F_43 ( V_647 ) ,
F_266 , V_636 ) ;
V_643 = F_131 ( V_2 , V_637 , 0 , sizeof( V_655 ) ,
& V_655 ) ;
if ( V_643 ) {
F_112 ( V_2 , L_50 , V_643 ) ;
F_277 ( & V_2 -> V_632 , & V_649 ) ;
goto V_675;
}
V_643 = F_278 ( & V_2 -> V_632 , & V_649 , 1 ) ;
F_15 ( V_643 ) ;
if ( V_643 ) {
V_675:
F_4 ( & V_2 -> V_333 ) ;
F_94 ( V_2 , V_636 ) ;
F_5 ( & V_2 -> V_333 ) ;
}
return V_643 ;
}
static int F_279 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_642 * V_586 ,
int V_597 ,
enum V_676 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
struct V_677 V_678 ;
struct V_370 * V_335 ;
int V_47 , V_9 ;
F_163 ( V_2 , L_51 , V_586 -> V_664 ,
V_597 , type ) ;
F_119 ( & V_2 -> V_362 ) ;
F_85 ( & V_2 -> V_33 ) ;
switch ( V_288 -> type ) {
case V_121 :
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_679 ) ) {
V_47 = F_271 ( V_2 , V_586 ,
V_288 , V_597 ) ;
goto V_388;
}
F_112 ( V_2 , L_52 ) ;
V_47 = - V_76 ;
goto V_388;
case V_145 :
break;
default:
F_112 ( V_2 , L_53 , V_288 -> type ) ;
V_47 = - V_76 ;
goto V_388;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_335 = & V_2 -> V_18 [ V_9 ] ;
if ( V_335 -> V_21 == 0 || V_330 -> V_335 == V_335 )
continue;
if ( V_335 -> V_21 && V_586 == V_335 -> V_586 ) {
V_47 = F_143 ( V_2 , V_288 ) ;
if ( F_280 ( V_47 , L_54 ) )
goto V_388;
F_144 ( V_2 , V_330 -> V_335 ) ;
V_330 -> V_335 = V_335 ;
V_47 = F_141 ( V_2 , V_288 ) ;
if ( F_280 ( V_47 , L_55 ) )
goto V_388;
F_140 ( V_2 , V_330 -> V_335 ) ;
goto V_680;
}
}
if ( V_586 == V_330 -> V_335 -> V_586 )
goto V_680;
F_281 ( & V_678 , V_586 , V_681 ) ;
if ( V_330 -> V_335 -> V_21 == 1 ) {
V_47 = F_282 ( V_2 , V_330 -> V_335 ,
& V_678 , 1 , 1 ) ;
if ( V_47 )
goto V_388;
} else {
V_335 = F_127 ( V_2 ) ;
if ( ! V_335 ) {
V_47 = - V_398 ;
goto V_388;
}
V_47 = F_282 ( V_2 , V_335 , & V_678 ,
1 , 1 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_56 ) ;
goto V_388;
}
V_47 = F_143 ( V_2 , V_288 ) ;
if ( F_280 ( V_47 , L_54 ) )
goto V_388;
F_144 ( V_2 , V_330 -> V_335 ) ;
V_330 -> V_335 = V_335 ;
V_47 = F_141 ( V_2 , V_288 ) ;
if ( F_280 ( V_47 , L_55 ) )
goto V_388;
F_140 ( V_2 , V_330 -> V_335 ) ;
}
V_680:
V_47 = F_283 ( V_2 , V_288 , V_597 , type ) ;
V_388:
F_91 ( & V_2 -> V_33 ) ;
F_163 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_284 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_163 ( V_2 , L_58 ) ;
F_85 ( & V_2 -> V_33 ) ;
F_285 ( V_2 ) ;
F_91 ( & V_2 -> V_33 ) ;
F_163 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_286 ( struct V_1 * V_2 ,
struct V_682 * V_683 )
{
V_140 * V_684 = ( V_140 * ) V_683 -> V_685 ;
struct V_370 * V_335 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_163 ( V_2 , L_59 ) ;
V_335 = F_127 ( V_2 ) ;
if ( ! V_335 ) {
V_47 = - V_398 ;
goto V_34;
}
V_47 = F_282 ( V_2 , V_335 , & V_683 -> V_686 ,
V_683 -> V_687 ,
V_683 -> V_688 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_60 ) ;
goto V_34;
}
F_140 ( V_2 , V_335 ) ;
* V_684 = V_335 -> V_20 ;
V_34:
return V_47 ;
}
static int F_287 ( struct V_29 * V_30 ,
struct V_682 * V_683 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_286 ( V_2 , V_683 ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_288 ( struct V_1 * V_2 ,
struct V_682 * V_683 )
{
V_140 * V_684 = ( V_140 * ) V_683 -> V_685 ;
struct V_370 * V_335 = & V_2 -> V_18 [ * V_684 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_144 ( V_2 , V_335 ) ;
}
static void F_289 ( struct V_29 * V_30 ,
struct V_682 * V_683 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_85 ( & V_2 -> V_33 ) ;
F_288 ( V_2 , V_683 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void F_290 ( struct V_29 * V_30 ,
struct V_682 * V_683 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_140 * V_684 = ( V_140 * ) V_683 -> V_685 ;
struct V_370 * V_335 = & V_2 -> V_18 [ * V_684 ] ;
if ( F_116 ( ( V_335 -> V_21 > 1 ) &&
( V_27 & ~ ( V_689 |
V_690 |
V_691 |
V_692 ) ) ,
L_61 ,
V_335 -> V_21 , V_27 ) )
return;
F_85 ( & V_2 -> V_33 ) ;
F_188 ( V_2 ) ;
F_282 ( V_2 , V_335 , & V_683 -> V_686 ,
V_683 -> V_687 ,
V_683 -> V_688 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static int F_291 ( struct V_1 * V_2 ,
struct V_295 * V_288 ,
struct V_682 * V_683 ,
bool V_693 )
{
V_140 * V_684 = ( V_140 * ) V_683 -> V_685 ;
struct V_370 * V_335 = & V_2 -> V_18 [ * V_684 ] ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_330 -> V_335 = V_335 ;
switch ( V_288 -> type ) {
case V_143 :
if ( V_693 ) {
V_330 -> V_516 = true ;
break;
}
case V_146 :
V_47 = 0 ;
goto V_34;
case V_121 :
break;
case V_402 :
V_330 -> V_343 = true ;
break;
default:
V_47 = - V_76 ;
goto V_34;
}
V_47 = F_141 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_34;
F_138 ( V_2 ) ;
if ( V_288 -> type == V_402 ) {
V_330 -> V_694 = true ;
V_47 = F_111 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_695;
V_47 = F_292 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_695;
}
if ( V_288 -> type == V_143 ) {
F_111 ( V_2 , false , NULL ) ;
F_166 ( V_2 , V_288 , false , NULL ) ;
}
if ( V_693 && V_288 -> type == V_121 ) {
T_1 V_597 = 2 * V_288 -> V_417 . V_494 ;
V_47 = F_12 ( V_2 , V_696 ) ;
if ( V_47 )
goto V_695;
F_183 ( V_2 , V_288 , V_597 , V_597 ,
V_288 -> V_417 . V_494 / 2 ,
true ) ;
F_7 ( V_2 , V_696 ) ;
F_111 ( V_2 , false , NULL ) ;
}
goto V_34;
V_695:
F_143 ( V_2 , V_288 ) ;
F_138 ( V_2 ) ;
V_34:
if ( V_47 )
V_330 -> V_335 = NULL ;
return V_47 ;
}
static int F_293 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_682 * V_683 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_291 ( V_2 , V_288 , V_683 , false ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_294 ( struct V_1 * V_2 ,
struct V_295 * V_288 ,
struct V_682 * V_683 ,
bool V_693 )
{
struct V_138 * V_330 = F_93 ( V_288 ) ;
struct V_295 * V_697 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_202 ( V_2 , V_330 , & V_330 -> V_334 ) ;
switch ( V_288 -> type ) {
case V_146 :
goto V_34;
case V_402 :
V_330 -> V_694 = false ;
V_330 -> V_343 = false ;
F_295 ( V_2 , V_288 ) ;
break;
case V_143 :
if ( ! V_693 || ! V_330 -> V_516 )
goto V_34;
V_330 -> V_520 = false ;
F_296 ( V_2 , V_330 , true ) ;
F_230 ( V_2 -> V_521 , V_288 ) ;
V_330 -> V_516 = false ;
break;
case V_121 :
if ( ! V_693 )
break;
V_697 = V_288 ;
F_166 ( V_2 , V_288 , true , NULL ) ;
break;
default:
break;
}
F_111 ( V_2 , false , V_697 ) ;
F_143 ( V_2 , V_288 ) ;
V_34:
V_330 -> V_335 = NULL ;
F_138 ( V_2 ) ;
}
static void F_297 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_682 * V_683 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_85 ( & V_2 -> V_33 ) ;
F_294 ( V_2 , V_288 , V_683 , false ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static int
F_298 ( struct V_1 * V_2 ,
struct V_698 * V_699 )
{
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
F_294 ( V_2 , V_699 [ 0 ] . V_288 , V_699 [ 0 ] . V_700 , true ) ;
F_288 ( V_2 , V_699 [ 0 ] . V_700 ) ;
V_47 = F_286 ( V_2 , V_699 [ 0 ] . V_701 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_62 ) ;
goto V_702;
}
V_47 = F_291 ( V_2 , V_699 [ 0 ] . V_288 , V_699 [ 0 ] . V_701 ,
true ) ;
if ( V_47 ) {
F_112 ( V_2 ,
L_63 ) ;
goto V_514;
}
if ( F_197 ( V_2 ) > 1 )
F_113 ( V_2 ) ;
goto V_34;
V_514:
F_288 ( V_2 , V_699 [ 0 ] . V_701 ) ;
V_702:
if ( F_286 ( V_2 , V_699 [ 0 ] . V_700 ) ) {
F_112 ( V_2 , L_64 ) ;
goto V_703;
}
if ( F_291 ( V_2 , V_699 [ 0 ] . V_288 , V_699 [ 0 ] . V_700 ,
true ) ) {
F_112 ( V_2 , L_65 ) ;
goto V_703;
}
goto V_34;
V_703:
F_299 ( V_2 , false ) ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_300 ( struct V_1 * V_2 ,
struct V_698 * V_699 )
{
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
F_294 ( V_2 , V_699 [ 0 ] . V_288 , V_699 [ 0 ] . V_700 , true ) ;
V_47 = F_291 ( V_2 , V_699 [ 0 ] . V_288 , V_699 [ 0 ] . V_701 ,
true ) ;
if ( V_47 ) {
F_112 ( V_2 ,
L_63 ) ;
goto V_702;
}
goto V_34;
V_702:
if ( F_291 ( V_2 , V_699 [ 0 ] . V_288 , V_699 [ 0 ] . V_700 ,
true ) ) {
F_112 ( V_2 , L_65 ) ;
goto V_703;
}
goto V_34;
V_703:
F_299 ( V_2 , false ) ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_301 ( struct V_29 * V_30 ,
struct V_698 * V_699 ,
int V_704 ,
enum V_705 V_706 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_704 > 1 )
return - V_611 ;
switch ( V_706 ) {
case V_707 :
V_47 = F_298 ( V_2 , V_699 ) ;
break;
case V_708 :
V_47 = F_300 ( V_2 , V_699 ) ;
break;
default:
V_47 = - V_611 ;
break;
}
return V_47 ;
}
static int F_302 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
return V_2 -> V_709 ;
}
static int F_303 ( struct V_29 * V_30 ,
struct V_265 * V_266 ,
bool V_710 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_560 = F_62 ( V_266 ) ;
if ( ! V_560 || ! V_560 -> V_288 ) {
F_112 ( V_2 , L_66 ) ;
return - V_76 ;
}
return F_194 ( V_2 , V_560 -> V_288 ) ;
}
static int F_304 ( struct V_1 * V_2 ,
struct V_295 * V_288 ,
void * V_283 , int V_379 )
{
struct V_711 * V_712 [ V_713 + 1 ] ;
int V_714 ;
T_1 V_404 ;
V_714 = F_305 ( V_712 , V_713 , V_283 , V_379 , V_715 ,
NULL ) ;
if ( V_714 )
return V_714 ;
if ( ! V_712 [ V_716 ] )
return - V_76 ;
switch ( F_306 ( V_712 [ V_716 ] ) ) {
case V_717 :
if ( ! V_288 || V_288 -> type != V_143 || ! V_288 -> V_394 ||
! V_288 -> V_417 . V_718 ||
! V_712 [ V_719 ] )
return - V_76 ;
V_404 = F_306 ( V_712 [ V_719 ] ) ;
if ( V_404 >= V_288 -> V_417 . V_494 )
return - V_76 ;
V_2 -> V_404 = V_404 ;
V_2 -> V_403 = V_288 ;
return F_111 ( V_2 , false , NULL ) ;
case V_720 :
if ( ! V_288 || V_288 -> type != V_121 ||
! V_288 -> V_417 . V_418 || ! V_288 -> V_417 . V_651 ||
! V_712 [ V_721 ] )
return - V_76 ;
if ( F_306 ( V_712 [ V_721 ] ) )
return F_191 ( V_2 , V_288 , 0 ) ;
return F_139 ( V_2 , V_288 , 0 ) ;
}
return - V_611 ;
}
static int F_307 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
void * V_283 , int V_379 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_714 ;
F_85 ( & V_2 -> V_33 ) ;
V_714 = F_304 ( V_2 , V_288 , V_283 , V_379 ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_714 ;
}
static void F_308 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_722 * V_723 )
{
F_163 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_309 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_722 * V_723 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_295 * V_519 ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
T_1 V_667 ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_330 -> V_724 = false ;
F_163 ( V_2 , L_68 ,
V_723 -> V_678 . V_725 ) ;
F_310 ( & V_2 -> V_305 ,
F_81 ( V_288 ) ,
V_726 ) ;
switch ( V_288 -> type ) {
case V_143 :
V_519 =
F_260 ( V_2 -> V_519 ,
F_261 ( & V_2 -> V_33 ) ) ;
if ( F_116 ( V_519 && V_519 -> V_727 ,
L_69 ) ) {
V_47 = - V_582 ;
goto V_388;
}
if ( F_260 ( V_2 -> V_521 ,
F_261 ( & V_2 -> V_33 ) ) ) {
V_47 = - V_582 ;
goto V_388;
}
F_230 ( V_2 -> V_519 , V_288 ) ;
if ( F_116 ( V_330 -> V_520 ,
L_70 ) ) {
V_47 = - V_582 ;
goto V_388;
}
V_330 -> V_728 = V_723 -> V_678 . V_729 -> V_730 ;
break;
case V_121 :
if ( V_330 -> V_489 )
F_181 ( V_288 ,
V_490 ,
0 , 0 ) ;
if ( V_723 -> V_420 <= 1 )
V_667 = 0 ;
else
V_667 = V_723 -> V_731 +
( ( V_288 -> V_417 . V_494 * ( V_723 -> V_420 - 1 ) -
V_732 ) * 1024 ) ;
if ( V_723 -> V_733 )
F_311 ( V_2 , V_288 ) ;
F_312 ( V_2 , V_288 , V_288 -> V_417 . V_494 ,
V_667 ) ;
if ( V_330 -> V_336 . V_510 ) {
V_47 = F_139 ( V_2 , V_288 , 0 ) ;
if ( V_47 )
goto V_388;
}
break;
default:
break;
}
V_330 -> V_343 = true ;
V_47 = F_313 ( V_2 ) ;
if ( V_47 )
goto V_388;
F_113 ( V_2 ) ;
V_388:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_314 ( struct V_29 * V_30 ,
struct V_295 * V_288 )
{
struct V_138 * V_330 = F_93 ( V_288 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_330 -> V_724 ) {
V_330 -> V_724 = false ;
V_47 = - V_17 ;
goto V_388;
}
if ( V_288 -> type == V_121 ) {
struct V_136 * V_269 ;
V_269 = F_315 ( V_2 ,
V_330 -> V_332 ) ;
if ( F_8 ( ! V_269 ) ) {
V_47 = - V_17 ;
goto V_388;
}
F_316 ( V_2 , V_269 , false ) ;
F_166 ( V_2 , V_288 , false , NULL ) ;
V_47 = F_191 ( V_2 , V_288 , 0 ) ;
if ( V_47 )
goto V_388;
F_190 ( V_2 , V_288 ) ;
}
V_330 -> V_343 = false ;
V_47 = F_313 ( V_2 ) ;
V_388:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_317 ( struct V_1 * V_2 , T_1 V_83 , bool V_284 )
{
if ( V_284 ) {
if ( F_41 ( V_2 ) )
F_116 ( 1 ,
L_71 ) ;
else
F_318 ( V_2 ,
F_319 ( V_2 ) & V_83 ,
0 ) ;
} else {
if ( F_41 ( V_2 ) ) {
struct V_265 * V_266 ;
int V_9 ;
F_85 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_2 -> V_555 ) ; V_9 ++ ) {
V_266 = F_260 (
V_2 -> V_555 [ V_9 ] ,
F_261 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_266 ) )
continue;
F_320 ( V_2 ,
F_62 ( V_266 ) ) ;
}
F_91 ( & V_2 -> V_33 ) ;
} else {
F_321 ( V_2 -> V_7 ,
V_83 ) ;
}
}
}
static void F_322 ( struct V_29 * V_30 ,
struct V_295 * V_288 , T_1 V_83 , bool V_284 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 ;
struct V_136 * V_269 ;
struct V_265 * V_266 ;
int V_9 ;
T_1 V_734 = 0 ;
if ( ! V_288 ) {
F_317 ( V_2 , V_83 , V_284 ) ;
return;
}
if ( V_288 -> type != V_121 )
return;
F_119 ( & V_2 -> V_366 ) ;
F_85 ( & V_2 -> V_33 ) ;
V_330 = F_93 ( V_288 ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_2 -> V_555 ) ; V_9 ++ ) {
V_266 = F_260 ( V_2 -> V_555 [ V_9 ] ,
F_261 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_266 ) )
continue;
V_269 = F_62 ( V_266 ) ;
if ( V_269 -> V_288 != V_288 )
continue;
F_8 ( V_9 != V_330 -> V_332 && ! V_266 -> V_580 ) ;
if ( V_284 ) {
if ( F_323 ( V_2 , V_269 , false , 0 ) )
F_112 ( V_2 , L_72 ) ;
} else {
V_734 |= V_269 -> V_735 ;
if ( F_41 ( V_2 ) )
F_320 ( V_2 , V_269 ) ;
}
}
F_91 ( & V_2 -> V_33 ) ;
if ( ! V_284 && ! F_41 ( V_2 ) )
F_321 ( V_2 -> V_7 , V_734 ) ;
}
static int F_324 ( struct V_29 * V_30 , int V_736 ,
struct V_737 * V_738 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_738 , 0 , sizeof( * V_738 ) ) ;
if ( V_736 != 0 )
return - V_49 ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_739 ) )
return - V_49 ;
F_85 ( & V_2 -> V_33 ) ;
if ( F_325 ( V_2 ) ) {
V_47 = F_182 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_738 -> V_740 = V_741 |
V_742 |
V_743 |
V_744 ;
V_738 -> time = V_2 -> V_361 . V_745 +
V_2 -> V_746 . V_745 ;
F_326 ( V_738 -> time , V_747 ) ;
V_738 -> V_748 = V_2 -> V_361 . V_749 +
V_2 -> V_746 . V_749 ;
F_326 ( V_738 -> V_748 , V_747 ) ;
V_738 -> V_750 = V_2 -> V_361 . V_751 +
V_2 -> V_746 . V_751 ;
F_326 ( V_738 -> V_750 , V_747 ) ;
V_738 -> V_752 = V_2 -> V_361 . V_753 +
V_2 -> V_746 . V_753 ;
F_326 ( V_738 -> V_752 , V_747 ) ;
V_47 = 0 ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_327 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
struct V_265 * V_266 ,
struct V_754 * V_755 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_330 = F_93 ( V_288 ) ;
struct V_136 * V_269 = F_62 ( V_266 ) ;
if ( V_269 -> V_756 ) {
V_755 -> V_757 = V_269 -> V_756 ;
V_755 -> V_740 |= F_45 ( V_758 ) ;
}
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_739 ) )
return;
if ( ! ( V_288 -> V_395 & V_396 ) )
return;
if ( ! V_288 -> V_417 . V_418 )
return;
F_85 ( & V_2 -> V_33 ) ;
if ( V_330 -> V_332 != V_269 -> V_272 )
goto V_759;
if ( F_182 ( V_2 , false ) )
goto V_759;
V_755 -> V_760 = V_330 -> V_385 . V_387 +
V_330 -> V_385 . V_386 ;
V_755 -> V_740 |= F_45 ( V_761 ) ;
if ( V_330 -> V_385 . V_762 ) {
V_755 -> V_763 = V_330 -> V_385 . V_762 ;
V_755 -> V_740 |= F_45 ( V_764 ) ;
}
V_759:
F_91 ( & V_2 -> V_33 ) ;
}
static void F_328 ( struct V_1 * V_2 ,
struct V_295 * V_288 ,
const struct V_765 * V_766 )
{
#define F_329 ( T_5 , T_6 ... ) \
do { \
if ((trig_mlme->_cnt) && --(trig_mlme->_cnt)) \
break; \
iwl_fw_dbg_collect_trig(&(mvm)->fwrt, trig, _fmt); \
} while (0)
struct V_300 * V_301 ;
struct V_767 * V_768 ;
if ( ! F_78 ( V_2 -> V_72 , V_769 ) )
return;
V_301 = F_79 ( V_2 -> V_72 , V_769 ) ;
V_768 = ( void * ) V_301 -> V_283 ;
if ( ! F_80 ( & V_2 -> V_305 ,
F_81 ( V_288 ) , V_301 ) )
return;
if ( V_766 -> V_770 . V_771 . V_283 == V_772 ) {
if ( V_766 -> V_770 . V_771 . V_15 == V_773 )
F_329 ( V_774 ,
L_73 ,
V_766 -> V_770 . V_771 . V_542 ) ;
else if ( V_766 -> V_770 . V_771 . V_15 == V_775 )
F_329 ( V_776 ,
L_74 ) ;
} else if ( V_766 -> V_770 . V_771 . V_283 == V_777 ) {
if ( V_766 -> V_770 . V_771 . V_15 == V_773 )
F_329 ( V_778 ,
L_75 ,
V_766 -> V_770 . V_771 . V_542 ) ;
else if ( V_766 -> V_770 . V_771 . V_15 == V_775 )
F_329 ( V_779 ,
L_76 ) ;
} else if ( V_766 -> V_770 . V_771 . V_283 == V_780 ) {
F_329 ( V_781 ,
L_77 , V_766 -> V_770 . V_771 . V_542 ) ;
} else if ( V_766 -> V_770 . V_771 . V_283 == V_782 ) {
F_329 ( V_783 ,
L_78 , V_766 -> V_770 . V_771 . V_542 ) ;
}
#undef F_329
}
static void F_330 ( struct V_1 * V_2 ,
struct V_295 * V_288 ,
const struct V_765 * V_766 )
{
struct V_300 * V_301 ;
struct V_302 * V_303 ;
if ( ! F_78 ( V_2 -> V_72 , V_304 ) )
return;
V_301 = F_79 ( V_2 -> V_72 , V_304 ) ;
V_303 = ( void * ) V_301 -> V_283 ;
if ( ! F_80 ( & V_2 -> V_305 ,
F_81 ( V_288 ) , V_301 ) )
return;
if ( ! ( F_331 ( V_303 -> V_784 ) & F_45 ( V_766 -> V_770 . V_785 . V_296 ) ) )
return;
F_235 ( & V_2 -> V_305 , V_301 ,
L_79 ,
V_766 -> V_770 . V_785 . V_266 -> V_164 , V_766 -> V_770 . V_785 . V_296 ,
V_766 -> V_770 . V_785 . V_310 ) ;
}
static void
F_332 ( struct V_1 * V_2 ,
struct V_295 * V_288 ,
const struct V_765 * V_766 )
{
struct V_300 * V_301 ;
struct V_302 * V_303 ;
if ( ! F_78 ( V_2 -> V_72 , V_304 ) )
return;
V_301 = F_79 ( V_2 -> V_72 , V_304 ) ;
V_303 = ( void * ) V_301 -> V_283 ;
if ( ! F_80 ( & V_2 -> V_305 ,
F_81 ( V_288 ) , V_301 ) )
return;
if ( ! ( F_331 ( V_303 -> V_786 ) & F_45 ( V_766 -> V_770 . V_785 . V_296 ) ) )
return;
F_235 ( & V_2 -> V_305 , V_301 ,
L_80 ,
V_766 -> V_770 . V_785 . V_266 -> V_164 , V_766 -> V_770 . V_785 . V_296 ) ;
}
static void F_333 ( struct V_29 * V_30 ,
struct V_295 * V_288 ,
const struct V_765 * V_766 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_766 -> type ) {
case V_787 :
F_328 ( V_2 , V_288 , V_766 ) ;
break;
case V_788 :
F_330 ( V_2 , V_288 , V_766 ) ;
break;
case V_789 :
F_332 ( V_2 , V_288 , V_766 ) ;
break;
default:
break;
}
}
void F_334 ( struct V_1 * V_2 ,
struct V_790 * V_481 ,
T_1 V_791 )
{
T_1 V_792 = F_45 ( V_2 -> V_7 -> V_77 ) - 1 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! F_39 ( V_2 ) ||
V_2 -> V_7 -> V_37 -> V_793 == V_794 )
return;
V_481 -> V_795 = V_2 -> V_796 ;
if ( V_481 -> V_797 )
F_335 ( & V_2 -> V_798 ,
V_2 -> V_7 -> V_77 ) ;
V_47 = F_336 ( V_2 , V_792 , ( T_2 * ) V_481 , V_791 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_81 , V_47 ) ;
goto V_34;
}
if ( V_481 -> V_797 ) {
V_47 = F_13 ( V_2 -> V_799 ,
F_337 ( & V_2 -> V_798 ) == 0 ||
F_68 ( V_2 ) ,
V_16 ) ;
F_15 ( ! V_47 && ! F_68 ( V_2 ) ) ;
}
V_34:
F_335 ( & V_2 -> V_798 , 0 ) ;
V_2 -> V_796 ++ ;
}
static void F_338 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_790 V_283 = {
. type = V_800 ,
. V_797 = 1 ,
} ;
F_85 ( & V_2 -> V_33 ) ;
F_334 ( V_2 , & V_283 , sizeof( V_283 ) ) ;
F_91 ( & V_2 -> V_33 ) ;
}
