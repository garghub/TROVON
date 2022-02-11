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
if ( F_40 ( & V_2 -> V_72 -> V_73 , V_74 ) )
F_38 ( V_30 , V_75 ) ;
if ( V_2 -> V_7 -> V_76 > 1 )
F_38 ( V_30 , V_77 ) ;
if ( V_2 -> V_7 -> V_78 )
V_30 -> V_79 = V_80 | V_81 ;
if ( ! F_41 ( V_2 ) )
V_30 -> V_82 = V_2 -> V_83 ;
else
V_30 -> V_82 = V_84 ;
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
V_30 -> V_23 -> V_147 |= V_194 ;
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
V_30 -> V_79 |= V_2 -> V_37 -> V_131 ;
if ( ! F_56 ( V_2 ) ) {
V_30 -> V_79 &= ~ ( V_258 |
V_259 ) ;
if ( V_260 )
V_30 -> V_79 |= V_258 ;
}
V_47 = F_57 ( V_2 -> V_30 ) ;
if ( V_47 )
F_58 ( V_2 ) ;
if ( V_2 -> V_37 -> V_261 )
F_50 ( V_30 -> V_23 ,
V_262 ) ;
return V_47 ;
}
static bool F_59 ( struct V_1 * V_2 ,
struct V_263 * V_264 ,
struct V_265 * V_266 )
{
struct V_136 * V_267 ;
bool V_268 = false ;
if ( F_60 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_61 ( & V_2 -> V_269 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_34;
V_267 = F_62 ( V_264 ) ;
if ( V_267 -> V_270 == V_271 ||
V_267 -> V_270 != V_2 -> V_272 )
goto V_34;
F_63 ( & V_2 -> V_273 , V_266 ) ;
F_64 ( V_2 -> V_30 ) ;
F_1 ( V_2 , V_274 ) ;
F_7 ( V_2 , V_274 ) ;
V_268 = true ;
V_34:
F_65 ( & V_2 -> V_269 ) ;
return V_268 ;
}
static void F_66 ( struct V_29 * V_30 ,
struct V_275 * V_276 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_263 * V_264 = V_276 -> V_264 ;
struct V_277 * V_278 = F_67 ( V_266 ) ;
struct V_279 * V_280 = ( void * ) V_266 -> V_281 ;
if ( F_68 ( V_2 ) ) {
F_69 ( V_2 , L_12 ) ;
goto V_282;
}
if ( F_67 ( V_266 ) -> V_283 == V_86 &&
! F_14 ( V_284 , & V_2 -> V_15 ) &&
! F_14 ( V_285 , & V_2 -> V_15 ) )
goto V_282;
if ( F_70 ( V_278 -> V_147 & V_286 &&
F_71 ( V_280 -> V_287 ) &&
! F_72 ( V_280 -> V_287 ) &&
! F_73 ( V_280 -> V_287 ) &&
! F_74 ( V_280 -> V_287 ) ) )
V_264 = NULL ;
if ( V_264 ) {
if ( F_59 ( V_2 , V_264 , V_266 ) )
return;
if ( F_75 ( V_2 , V_266 , V_264 ) )
goto V_282;
return;
}
if ( F_76 ( V_2 , V_266 ) )
goto V_282;
return;
V_282:
F_77 ( V_30 , V_266 ) ;
}
static inline bool F_78 ( const struct V_288 * V_37 )
{
if ( V_108 . V_289 & V_290 )
return false ;
return true ;
}
static inline bool F_79 ( const struct V_288 * V_37 )
{
if ( V_108 . V_289 & V_291 )
return false ;
if ( V_108 . V_289 & V_292 )
return true ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 , struct V_293 * V_294 ,
struct V_263 * V_264 , V_140 V_295 , V_140 V_296 ,
enum V_297 V_298 )
{
struct V_299 * V_300 ;
struct V_301 * V_302 ;
if ( ! F_81 ( V_2 -> V_72 , V_303 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_303 ) ;
V_302 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
switch ( V_298 ) {
case V_304 : {
struct V_136 * V_267 = F_62 ( V_264 ) ;
struct V_305 * V_306 = & V_267 -> V_306 [ V_295 ] ;
F_84 ( V_2 , V_300 , V_302 -> V_307 , V_295 ,
L_13 ,
V_264 -> V_164 , V_295 , V_306 -> V_308 ) ;
break;
}
case V_309 :
F_84 ( V_2 , V_300 , V_302 -> V_310 , V_295 ,
L_14 ,
V_264 -> V_164 , V_295 ) ;
break;
case V_311 :
F_84 ( V_2 , V_300 , V_302 -> V_312 , V_295 ,
L_15 ,
V_264 -> V_164 , V_295 , V_296 ) ;
break;
case V_313 :
F_84 ( V_2 , V_300 , V_302 -> V_314 , V_295 ,
L_16 ,
V_264 -> V_164 , V_295 ) ;
break;
default:
break;
}
}
static int F_85 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_315 * V_316 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_317 = false ;
struct V_263 * V_264 = V_316 -> V_264 ;
enum V_297 V_298 = V_316 -> V_298 ;
V_140 V_295 = V_316 -> V_295 ;
V_140 * V_308 = & V_316 -> V_308 ;
T_2 V_318 = V_316 -> V_318 ;
bool V_319 = V_316 -> V_319 ;
V_140 V_320 = V_316 -> V_320 ;
F_86 ( V_2 , L_17 ,
V_264 -> V_164 , V_295 , V_298 ) ;
if ( ! ( V_2 -> V_165 -> V_321 ) )
return - V_322 ;
switch ( V_298 ) {
case V_323 :
case V_309 :
case V_324 :
case V_325 :
case V_304 :
V_47 = F_12 ( V_2 , V_326 ) ;
if ( V_47 )
return V_47 ;
V_317 = true ;
break;
default:
break;
}
F_87 ( & V_2 -> V_33 ) ;
switch ( V_298 ) {
case V_311 :
if ( ! F_78 ( V_2 -> V_37 ) ) {
V_47 = - V_327 ;
break;
}
V_47 = F_88 ( V_2 , V_264 , V_295 , * V_308 , true , V_318 ,
V_320 ) ;
break;
case V_313 :
V_47 = F_88 ( V_2 , V_264 , V_295 , 0 , false , V_318 ,
V_320 ) ;
break;
case V_323 :
if ( ! F_79 ( V_2 -> V_37 ) ) {
V_47 = - V_327 ;
break;
}
V_47 = F_89 ( V_2 , V_294 , V_264 , V_295 , V_308 ) ;
break;
case V_309 :
V_47 = F_90 ( V_2 , V_294 , V_264 , V_295 ) ;
break;
case V_324 :
case V_325 :
V_47 = F_91 ( V_2 , V_294 , V_264 , V_295 ) ;
break;
case V_304 :
V_47 = F_92 ( V_2 , V_294 , V_264 , V_295 ,
V_318 , V_319 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_327 ;
break;
}
if ( ! V_47 ) {
V_140 V_296 = 0 ;
if ( V_298 == V_311 )
V_296 = * V_308 ;
F_80 ( V_2 , V_294 , V_264 , V_295 ,
V_296 , V_298 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
if ( V_317 )
F_7 ( V_2 , V_326 ) ;
return V_47 ;
}
static void F_94 ( void * V_281 , T_2 * V_328 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = V_281 ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
V_329 -> V_330 = false ;
V_329 -> V_331 = V_271 ;
F_4 ( & V_2 -> V_332 ) ;
F_96 ( V_2 , & V_329 -> V_333 ) ;
F_5 ( & V_2 -> V_332 ) ;
V_329 -> V_334 = NULL ;
memset ( & V_329 -> V_335 , 0 , sizeof( V_329 -> V_335 ) ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
if ( ! F_98 ( V_336 , & V_2 -> V_15 ) ) {
V_2 -> V_337 = & V_338 ;
F_99 ( V_2 ) ;
}
F_10 ( V_2 , V_339 ) ;
F_100 ( V_2 ) ;
V_2 -> V_340 = 0 ;
V_2 -> V_341 = false ;
V_2 -> V_342 = false ;
F_101 ( V_2 ) ;
F_102 ( V_2 -> V_30 ) ;
F_103 ( V_2 -> V_30 , 0 , F_94 , V_2 ) ;
V_2 -> V_343 = NULL ;
V_2 -> V_272 = V_271 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_344 , 0 , sizeof( V_2 -> V_344 ) ) ;
memset ( V_2 -> V_345 , 0 , sizeof( V_2 -> V_345 ) ) ;
memset ( V_2 -> V_346 , 0 , sizeof( V_2 -> V_346 ) ) ;
memset ( V_2 -> V_347 , 0 , sizeof( V_2 -> V_347 ) ) ;
memset ( & V_2 -> V_348 , 0 , sizeof( V_2 -> V_348 ) ) ;
memset ( & V_2 -> V_349 , 0 , sizeof( V_2 -> V_349 ) ) ;
F_104 ( V_2 -> V_30 ) ;
F_105 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_350 = 0 ;
V_2 -> V_351 = 0 ;
V_2 -> V_352 = V_353 ;
F_106 ( V_2 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_354 , & V_2 -> V_15 ) ) {
F_97 ( V_2 ) ;
} else {
F_1 ( V_2 , V_339 ) ;
}
V_47 = F_108 ( V_2 ) ;
if ( V_47 && F_14 ( V_354 , & V_2 -> V_15 ) ) {
F_105 ( V_354 , & V_2 -> V_15 ) ;
F_109 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_110 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_354 , & V_2 -> V_15 ) ) {
F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ;
}
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_107 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_111 ( struct V_1 * V_2 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_105 ( V_354 , & V_2 -> V_15 ) ;
F_109 ( V_2 , NULL ) ;
V_47 = F_112 ( V_2 , true , NULL ) ;
if ( V_47 )
F_113 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_339 ) ;
F_114 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) &&
F_116 ( V_2 ) )
F_117 ( ! F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ,
L_19 ) ;
}
static void
F_118 ( struct V_29 * V_30 ,
enum V_355 V_356 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_356 ) {
case V_357 :
F_111 ( V_2 ) ;
break;
case V_358 :
F_115 ( V_2 ) ;
break;
}
}
void F_119 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_359 , 0 , sizeof( V_2 -> V_359 ) ) ;
F_120 ( & V_2 -> V_360 ) ;
F_100 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
if ( F_98 ( V_354 , & V_2 -> V_15 ) )
F_103 ( V_2 -> V_30 , 0 ,
F_94 , V_2 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 , V_178 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_179 ; V_9 ++ ) {
if ( F_117 ( V_2 -> V_361 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_361 [ V_9 ] = 0 ;
}
}
}
static void F_123 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_120 ( & V_2 -> V_362 ) ;
F_120 ( & V_2 -> V_363 ) ;
F_120 ( & V_2 -> V_364 ) ;
F_124 ( & V_2 -> V_365 ) ;
F_124 ( & V_2 -> V_366 ) ;
F_124 ( & V_2 -> V_367 ) ;
F_125 ( V_2 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_119 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_126 ( & V_2 -> V_363 ) ;
}
static struct V_368 * F_127 ( struct V_1 * V_2 )
{
V_140 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_113 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_128 ( struct V_1 * V_2 , struct V_293 * V_294 ,
T_3 V_369 )
{
struct V_370 V_371 = {
. V_372 . V_373 = F_129 ( V_374 ) ,
. V_372 . V_375 =
F_129 ( F_95 ( V_294 ) -> V_20 ) ,
. V_372 . V_376 = F_130 ( 8 * V_369 ) ,
} ;
int V_377 = sizeof( V_371 ) ;
if ( V_369 == V_378 )
V_371 . V_372 . V_376 = F_130 ( V_379 ) ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 , V_380 ) )
V_377 = sizeof( V_371 . V_372 ) ;
return F_131 ( V_2 , V_381 , 0 , V_377 , & V_371 ) ;
}
static int F_132 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
int V_47 ;
V_329 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_382 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_354 , & V_2 -> V_15 ) )
V_329 -> V_383 . V_384 +=
V_329 -> V_383 . V_385 ;
V_47 = F_133 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_386;
if ( V_294 -> type != V_145 )
V_2 -> V_350 ++ ;
if ( V_294 -> type == V_143 ||
V_294 -> type == V_146 ) {
V_47 = F_134 ( V_2 , V_294 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_22 ) ;
goto V_387;
}
F_135 ( V_2 , V_294 ) ;
goto V_386;
}
V_329 -> V_131 |= V_30 -> V_79 ;
V_47 = F_136 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_387;
V_47 = F_137 ( V_2 ) ;
if ( V_47 )
goto V_388;
V_47 = F_138 ( V_2 , V_294 , 0 ) ;
if ( V_47 )
goto V_388;
if ( ! V_2 -> V_389 &&
V_294 -> type == V_121 && ! V_294 -> V_390 ) {
V_2 -> V_389 = V_329 ;
V_294 -> V_391 |= V_392 |
V_393 ;
}
if ( V_294 -> type == V_145 ) {
V_329 -> V_334 = F_127 ( V_2 ) ;
if ( ! V_329 -> V_334 ) {
V_47 = - V_394 ;
goto V_395;
}
F_139 ( V_2 , V_329 -> V_334 ) ;
V_47 = F_140 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_396;
V_47 = F_141 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_397;
V_2 -> V_343 = V_294 ;
}
F_135 ( V_2 , V_294 ) ;
goto V_386;
V_397:
F_142 ( V_2 , V_294 ) ;
V_396:
F_143 ( V_2 , V_329 -> V_334 ) ;
V_395:
if ( V_2 -> V_389 == V_329 ) {
V_2 -> V_389 = NULL ;
V_294 -> V_391 &= ~ ( V_392 |
V_393 ) ;
}
V_388:
V_329 -> V_334 = NULL ;
F_144 ( V_2 , V_294 ) ;
V_387:
if ( V_294 -> type != V_145 )
V_2 -> V_350 -- ;
F_145 ( V_2 , V_294 ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_382 ) ;
return V_47 ;
}
static void F_146 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
T_1 V_398 = F_147 ( V_294 ) ;
if ( V_398 ) {
F_87 ( & V_2 -> V_33 ) ;
F_148 ( V_2 , V_398 , 0 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_149 ( V_2 -> V_7 , V_398 ) ;
}
if ( V_294 -> type == V_145 ) {
F_120 ( & V_2 -> V_360 ) ;
} else {
F_120 ( & V_2 -> V_399 ) ;
}
}
static void F_150 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
F_146 ( V_2 , V_294 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_389 == V_329 ) {
V_2 -> V_389 = NULL ;
V_294 -> V_391 &= ~ ( V_392 |
V_393 ) ;
}
F_151 ( V_2 , V_294 ) ;
if ( V_294 -> type == V_143 ||
V_294 -> type == V_146 ) {
#ifdef F_152
if ( V_294 == V_2 -> V_400 ) {
V_2 -> V_400 = NULL ;
V_2 -> V_401 = 0 ;
}
#endif
F_153 ( V_2 , V_294 ) ;
goto V_387;
}
if ( V_294 -> type == V_145 ) {
V_2 -> V_343 = NULL ;
F_154 ( V_2 , V_294 ) ;
F_142 ( V_2 , V_294 ) ;
F_143 ( V_2 , V_329 -> V_334 ) ;
V_329 -> V_334 = NULL ;
}
if ( V_2 -> V_350 && V_294 -> type != V_145 )
V_2 -> V_350 -- ;
F_137 ( V_2 ) ;
F_144 ( V_2 , V_294 ) ;
V_387:
F_145 ( V_2 , V_294 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_155 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_156 ( void * V_402 , T_2 * V_328 ,
struct V_293 * V_294 )
{
struct V_403 * V_281 = V_402 ;
struct V_1 * V_2 = V_281 -> V_2 ;
struct V_404 * V_371 = V_2 -> V_405 ;
int V_47 , V_377 ;
if ( F_15 ( V_281 -> V_406 >= V_407 ) )
return;
if ( V_294 -> type != V_121 ||
! V_294 -> V_408 . V_409 )
return;
V_371 -> V_406 = V_281 -> V_406 ++ ;
memcpy ( V_371 -> V_410 , V_294 -> V_408 . V_410 , V_167 ) ;
V_377 = F_157 ( sizeof( * V_371 ) + V_371 -> V_411 * V_167 , 4 ) ;
V_47 = F_131 ( V_2 , V_412 , V_413 , V_377 , V_371 ) ;
if ( V_47 )
F_113 ( V_2 , L_23 , V_47 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_403 V_414 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_405 ) )
return;
F_159 (
V_2 -> V_30 , V_415 ,
F_156 , & V_414 ) ;
}
static T_4 F_160 ( struct V_29 * V_30 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_404 * V_371 ;
struct V_418 * V_164 ;
int V_419 ;
bool V_420 ;
int V_377 ;
V_419 = F_161 ( V_417 ) ;
V_420 = V_419 > V_421 ||
V_422 ;
if ( V_420 )
V_419 = 0 ;
V_377 = F_157 ( sizeof( * V_371 ) + V_419 * V_167 , 4 ) ;
V_371 = F_162 ( V_377 , V_423 ) ;
if ( ! V_371 )
return 0 ;
if ( V_420 ) {
V_371 -> V_420 = 1 ;
return ( T_4 ) ( unsigned long ) V_371 ;
}
F_163 (addr, mc_list) {
F_164 ( V_2 , L_24 ,
V_371 -> V_411 , V_164 -> V_164 ) ;
memcpy ( & V_371 -> V_424 [ V_371 -> V_411 * V_167 ] ,
V_164 -> V_164 , V_167 ) ;
V_371 -> V_411 ++ ;
}
return ( T_4 ) ( unsigned long ) V_371 ;
}
static void F_165 ( struct V_29 * V_30 ,
unsigned int V_425 ,
unsigned int * V_426 ,
T_4 V_427 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_404 * V_371 = ( void * ) ( unsigned long ) V_427 ;
F_87 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_405 ) ;
V_2 -> V_405 = V_371 ;
if ( ! V_371 )
goto V_34;
F_158 ( V_2 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
* V_426 = 0 ;
}
static void F_166 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
unsigned int V_428 ,
unsigned int V_425 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_425 & V_429 ) )
return;
if ( V_294 -> type != V_121 || ! V_294 -> V_408 . V_409 ||
! V_294 -> V_390 )
return;
F_87 ( & V_2 -> V_33 ) ;
F_167 ( V_2 , V_294 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_168 ( struct V_293 * V_294 ,
const struct V_430 * V_431 ,
struct V_430 * V_432 )
{
struct V_433 * V_434 ;
int V_9 ;
memcpy ( V_432 , V_431 , sizeof( * V_432 ) ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_432 -> V_435 ) ; V_9 ++ ) {
V_434 = & V_432 -> V_435 [ V_9 ] ;
if ( ! V_434 -> V_436 )
break;
switch ( V_434 -> V_437 ) {
case F_130 ( V_438 ) :
if ( V_294 -> V_408 . V_439 != 1 ) {
V_434 -> V_436 = 0 ;
continue;
}
V_434 -> V_440 = V_294 -> V_408 . V_441 [ 0 ] ;
break;
case F_130 ( V_442 ) :
V_434 -> V_440 = * ( V_443 * ) & V_294 -> V_164 [ 2 ] ;
break;
default:
break;
}
V_434 -> V_437 = 0 ;
V_432 -> V_444 ++ ;
}
}
static void F_169 ( void * V_402 , T_2 * V_328 ,
struct V_293 * V_294 )
{
struct V_445 * V_281 = V_402 ;
struct V_1 * V_2 = V_281 -> V_2 ;
struct V_446 * V_371 = V_281 -> V_371 ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_447 * V_448 ;
int V_9 ;
if ( F_8 ( V_329 -> V_20 >= F_43 ( V_371 -> V_449 ) ) )
return;
V_448 = & V_371 -> V_449 [ V_329 -> V_20 ] ;
if ( V_294 -> type != V_121 || V_294 -> V_390 ||
! V_294 -> V_408 . V_409 )
return;
V_448 -> V_450 = 1 ;
for ( V_9 = 0 ; V_2 -> V_251 [ V_9 ] . V_435 [ 0 ] . V_436 ; V_9 ++ ) {
if ( F_15 ( V_281 -> V_451 >=
F_43 ( V_371 -> V_452 ) ) ) {
V_448 -> V_450 = 0 ;
V_448 -> V_453 = 0 ;
break;
}
F_168 ( V_294 ,
& V_2 -> V_251 [ V_9 ] ,
& V_371 -> V_452 [ V_281 -> V_451 ] ) ;
if ( ! V_371 -> V_452 [ V_281 -> V_451 ] . V_444 )
continue;
V_448 -> V_453 |=
F_130 ( F_45 ( V_281 -> V_451 ) ) ;
V_281 -> V_451 ++ ;
}
}
bool F_170 ( struct V_1 * V_2 ,
struct V_446 * V_371 )
{
struct V_445 V_414 = {
. V_2 = V_2 ,
. V_371 = V_371 ,
} ;
if ( V_454 )
return false ;
memset ( V_371 , 0 , sizeof( * V_371 ) ) ;
V_371 -> V_455 = F_43 ( V_371 -> V_452 ) ;
V_371 -> V_456 = F_43 ( V_371 -> V_449 ) ;
#ifdef F_171
if ( V_2 -> V_457 . V_458 ) {
memcpy ( V_371 -> V_452 , & V_2 -> V_457 . V_371 . V_452 ,
sizeof( V_371 -> V_452 ) ) ;
memcpy ( V_371 -> V_449 , & V_2 -> V_457 . V_371 . V_449 ,
sizeof( V_371 -> V_449 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_251 )
return false ;
F_172 (
V_2 -> V_30 , V_415 ,
F_169 , & V_414 ) ;
return true ;
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_446 V_371 ;
if ( ! ( V_2 -> V_72 -> V_73 . V_147 & V_459 ) )
return 0 ;
if ( ! F_170 ( V_2 , & V_371 ) )
return 0 ;
return F_131 ( V_2 , V_460 , 0 ,
sizeof( V_371 ) , & V_371 ) ;
}
static inline int F_173 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_174 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
struct V_461 V_371 = {} ;
memcpy ( V_371 . V_462 , V_294 -> V_408 . V_463 . V_464 ,
V_465 ) ;
memcpy ( V_371 . V_466 , V_294 -> V_408 . V_463 . V_467 ,
V_468 ) ;
return F_131 ( V_2 ,
F_175 ( V_469 ,
V_470 ) ,
0 , sizeof( V_371 ) , & V_371 ) ;
}
static void F_176 ( void * V_402 , T_2 * V_328 ,
struct V_293 * V_294 )
{
if ( V_294 -> V_471 ) {
struct V_472 * V_473 = V_402 ;
F_177 ( V_294 ,
( T_2 * ) & V_473 -> V_462 ,
( T_2 * ) & V_473 -> V_466 ) ;
}
}
void F_178 ( struct V_1 * V_2 ,
struct V_474 * V_475 )
{
struct V_476 * V_477 = F_179 ( V_475 ) ;
struct V_472 * V_473 = ( void * ) V_477 -> V_281 ;
F_159 (
V_2 -> V_30 , V_415 ,
F_176 , V_473 ) ;
}
static void F_180 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
struct V_478 * V_408 ,
T_1 V_479 )
{
struct V_138 * V_329 = F_95 ( V_294 ) ;
int V_47 ;
if ( V_479 & V_480 && V_408 -> V_409 )
F_181 ( V_2 , V_294 ) ;
if ( V_479 & V_480 && ! V_408 -> V_409 &&
V_329 -> V_481 )
F_182 ( V_294 , V_482 ,
0 , 0 ) ;
if ( V_479 & V_483 && ! V_329 -> V_484 )
memcpy ( V_329 -> V_410 , V_408 -> V_410 , V_167 ) ;
V_47 = F_167 ( V_2 , V_294 , false , V_329 -> V_410 ) ;
if ( V_47 )
F_113 ( V_2 , L_25 , V_294 -> V_164 ) ;
memcpy ( V_329 -> V_410 , V_408 -> V_410 , V_167 ) ;
V_329 -> V_484 = V_408 -> V_409 ;
if ( V_479 & V_480 ) {
if ( V_408 -> V_409 ) {
F_183 ( V_2 , true ) ;
memset ( & V_329 -> V_383 , 0 ,
sizeof( V_329 -> V_383 ) ) ;
V_47 = F_112 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_113 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_354 ,
& V_2 -> V_15 ) ) {
T_1 V_485 = ( 11 * V_294 -> V_408 . V_486 ) / 10 ;
F_184 ( V_2 , V_294 , V_485 , V_485 ,
5 * V_485 , false ) ;
}
F_185 ( V_2 , V_294 , false ) ;
F_186 ( V_2 , V_294 ) ;
if ( V_294 -> V_390 ) {
F_1 ( V_2 , V_487 ) ;
F_187 ( V_2 , V_294 ,
V_488 ,
V_489 ) ;
}
} else if ( V_329 -> V_331 != V_271 ) {
F_117 ( F_185 ( V_2 , V_294 , false ) ,
L_27 ) ;
V_47 = F_188 ( V_2 , V_294 , V_329 -> V_331 ) ;
if ( V_47 )
F_113 ( V_2 , L_28 ) ;
if ( V_2 -> V_272 == V_329 -> V_331 )
V_2 -> V_272 = V_271 ;
V_329 -> V_331 = V_271 ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
F_113 ( V_2 , L_26 ) ;
if ( V_294 -> V_390 )
F_7 ( V_2 , V_487 ) ;
V_47 = F_167 ( V_2 , V_294 , false , NULL ) ;
if ( V_47 )
F_113 ( V_2 ,
L_29 ,
V_294 -> V_164 ) ;
}
if ( F_14 ( V_354 , & V_2 -> V_15 ) &&
( V_479 & V_490 ) && V_294 -> V_471 ) {
V_47 = F_174 ( V_2 , V_294 ) ;
if ( V_47 )
F_113 ( V_2 ,
L_30 ) ;
}
F_158 ( V_2 ) ;
F_173 ( V_2 ) ;
V_329 -> V_335 . V_491 = 0 ;
F_189 ( V_2 ) ;
F_187 ( V_2 , V_294 , V_492 ,
V_493 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_178 ) )
F_190 ( V_2 ) ;
}
if ( V_479 & V_494 ) {
F_191 ( V_2 , V_329 ,
& V_329 -> V_333 ) ;
F_185 ( V_2 , V_294 , false ) ;
F_8 ( F_192 ( V_2 , V_294 , 0 ) ) ;
}
if ( V_479 & ( V_495 | V_496 | V_497 |
V_494 ) ) {
V_47 = F_137 ( V_2 ) ;
if ( V_47 )
F_113 ( V_2 , L_31 ) ;
}
if ( V_479 & V_498 ) {
F_193 ( V_2 , L_32 ,
V_408 -> V_499 ) ;
F_128 ( V_2 , V_294 , V_408 -> V_499 ) ;
}
if ( V_479 & V_500 ) {
F_164 ( V_2 , L_33 ) ;
V_329 -> V_335 . V_501 = 0 ;
if ( V_329 -> V_335 . V_502 ) {
V_47 = F_192 ( V_2 , V_294 , 0 ) ;
if ( V_47 )
F_113 ( V_2 ,
L_34 ) ;
}
}
if ( V_479 & V_503 ) {
F_164 ( V_2 , L_35 ) ;
F_173 ( V_2 ) ;
}
}
static int F_194 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_504 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_195 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_386;
if ( V_294 -> type == V_143 )
F_181 ( V_2 , V_294 ) ;
V_329 -> V_505 = 0 ;
V_47 = F_136 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_386;
V_47 = F_140 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_506;
V_47 = F_196 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_397;
V_329 -> V_507 = true ;
F_137 ( V_2 ) ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_508;
if ( V_294 -> V_390 && V_2 -> V_343 )
F_167 ( V_2 , V_2 -> V_343 , false , NULL ) ;
F_1 ( V_2 , V_509 ) ;
F_189 ( V_2 ) ;
if ( F_197 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
goto V_386;
V_508:
F_137 ( V_2 ) ;
V_329 -> V_507 = false ;
F_198 ( V_2 , V_294 ) ;
V_397:
F_142 ( V_2 , V_294 ) ;
V_506:
F_144 ( V_2 , V_294 ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_504 ) ;
return V_47 ;
}
static void F_199 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
F_146 ( V_2 , V_294 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_200 ( V_2 -> V_510 ) == V_294 ) {
F_191 ( V_2 , V_329 ,
& V_329 -> V_333 ) ;
F_201 ( V_2 -> V_510 , NULL ) ;
V_329 -> V_511 = false ;
}
if ( F_200 ( V_2 -> V_512 ) == V_294 ) {
F_201 ( V_2 -> V_512 , NULL ) ;
V_2 -> V_513 = 0 ;
}
V_329 -> V_507 = false ;
V_2 -> V_514 = 0 ;
F_189 ( V_2 ) ;
F_7 ( V_2 , V_509 ) ;
if ( V_294 -> V_390 && V_2 -> V_343 )
F_167 ( V_2 , V_2 -> V_343 , false , NULL ) ;
F_112 ( V_2 , false , NULL ) ;
F_198 ( V_2 , V_294 ) ;
F_142 ( V_2 , V_294 ) ;
F_137 ( V_2 ) ;
F_144 ( V_2 , V_294 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_202 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
struct V_478 * V_408 ,
T_1 V_479 )
{
struct V_138 * V_329 = F_95 ( V_294 ) ;
if ( ! V_329 -> V_507 )
return;
if ( V_479 & ( V_515 | V_516 |
V_517 | V_497 ) &&
F_167 ( V_2 , V_294 , false , NULL ) )
F_113 ( V_2 , L_25 , V_294 -> V_164 ) ;
if ( V_479 & V_518 &&
F_195 ( V_2 , V_294 ) )
F_203 ( V_2 , L_36 ) ;
if ( V_479 & V_498 ) {
F_193 ( V_2 , L_32 ,
V_408 -> V_499 ) ;
F_128 ( V_2 , V_294 , V_408 -> V_499 ) ;
}
}
static void F_204 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_478 * V_408 ,
T_1 V_479 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_519 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_479 & V_520 && ! V_408 -> V_521 )
F_205 ( V_2 , V_522 , true ) ;
switch ( V_294 -> type ) {
case V_121 :
F_180 ( V_2 , V_294 , V_408 , V_479 ) ;
break;
case V_143 :
case V_146 :
F_202 ( V_2 , V_294 , V_408 , V_479 ) ;
break;
case V_523 :
if ( V_479 & V_490 )
F_174 ( V_2 , V_294 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_519 ) ;
}
static int F_206 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_524 * V_525 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_525 -> V_526 . V_38 == 0 ||
V_525 -> V_526 . V_38 > V_2 -> V_72 -> V_73 . V_527 )
return - V_327 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_207 ( V_2 , V_294 , & V_525 -> V_526 , & V_525 -> V_528 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_208 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_340 & V_529 )
F_205 ( V_2 , V_529 , true ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_209 ( struct V_29 * V_30 ,
struct V_263 * V_264 , V_140 V_530 ,
int V_531 ,
enum V_532 V_533 ,
bool V_534 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_210 ( V_2 , V_264 , V_533 , V_531 ,
V_530 , V_534 , false ) ;
}
static void
F_211 ( struct V_29 * V_30 ,
struct V_263 * V_264 , V_140 V_530 ,
int V_531 ,
enum V_532 V_533 ,
bool V_534 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_210 ( V_2 , V_264 , V_533 , V_531 ,
V_530 , V_534 , true ) ;
}
static void F_212 ( struct V_29 * V_30 ,
enum V_535 V_371 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_267 = F_62 ( V_264 ) ;
unsigned long V_536 = 0 , V_530 = 0 ;
int V_295 ;
F_4 ( & V_267 -> V_537 ) ;
for ( V_295 = 0 ; V_295 < V_538 ; V_295 ++ ) {
struct V_305 * V_306 = & V_267 -> V_306 [ V_295 ] ;
if ( ! F_41 ( V_2 ) &&
V_306 -> V_539 != V_540 &&
V_306 -> V_539 != V_541 )
continue;
F_213 ( V_306 -> V_542 , & V_536 ) ;
if ( F_214 ( V_306 ) == 0 )
continue;
F_213 ( V_295 , & V_530 ) ;
}
switch ( V_371 ) {
case V_543 :
if ( F_215 ( & V_2 -> V_544 [ V_267 -> V_270 ] ) > 0 )
F_216 ( V_30 , V_264 , true ) ;
F_217 (tid, &tids, IWL_MAX_TID_COUNT)
F_218 ( V_264 , V_295 , true ) ;
if ( V_536 )
F_219 ( V_2 -> V_7 , V_536 , true ) ;
break;
case V_545 :
if ( F_8 ( V_267 -> V_270 == V_271 ) )
break;
if ( V_536 )
F_219 ( V_2 -> V_7 , V_536 , false ) ;
F_220 ( V_2 , V_264 ) ;
break;
default:
break;
}
F_5 ( & V_267 -> V_537 ) ;
}
static void F_221 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
enum V_535 V_371 ,
struct V_263 * V_264 )
{
F_212 ( V_30 , V_371 , V_264 ) ;
}
void F_222 ( struct V_1 * V_2 , struct V_474 * V_475 )
{
struct V_476 * V_477 = F_179 ( V_475 ) ;
struct V_546 * V_473 = ( void * ) V_477 -> V_281 ;
struct V_263 * V_264 ;
struct V_136 * V_267 ;
bool V_547 = ( V_473 -> type != V_548 ) ;
if ( F_8 ( V_473 -> V_270 >= F_43 ( V_2 -> V_549 ) ) )
return;
F_223 () ;
V_264 = F_224 ( V_2 -> V_549 [ V_473 -> V_270 ] ) ;
if ( F_8 ( F_23 ( V_264 ) ) ) {
F_225 () ;
return;
}
V_267 = F_62 ( V_264 ) ;
if ( ! V_267 -> V_294 ||
V_267 -> V_294 -> type != V_143 ) {
F_225 () ;
return;
}
if ( V_267 -> V_547 != V_547 ) {
V_267 -> V_547 = V_547 ;
F_212 ( V_2 -> V_30 ,
V_547 ? V_543 : V_545 ,
V_264 ) ;
F_226 ( V_264 , V_547 ) ;
}
if ( V_547 ) {
switch ( V_473 -> type ) {
case V_548 :
case V_550 :
break;
case V_551 :
F_227 ( V_264 , V_552 ) ;
break;
case V_553 :
F_228 ( V_264 ) ;
break;
default:
break;
}
}
F_225 () ;
}
static void F_229 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_554 = F_62 ( V_264 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_264 == F_200 ( V_2 -> V_549 [ V_554 -> V_270 ] ) )
F_230 ( V_2 -> V_549 [ V_554 -> V_270 ] ,
F_231 ( - V_49 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_232 ( struct V_1 * V_2 , struct V_293 * V_294 ,
const T_2 * V_410 )
{
if ( ! ( V_2 -> V_72 -> V_73 . V_147 & V_555 ) )
return;
if ( V_294 -> V_390 && ! F_233 ( V_2 ) ) {
V_294 -> V_391 &= ~ V_556 ;
return;
}
if ( ! V_294 -> V_390 &&
( V_108 . V_557 & V_558 ) ) {
V_294 -> V_391 &= ~ V_556 ;
return;
}
V_294 -> V_391 |= V_556 ;
}
static void
F_234 ( struct V_1 * V_2 ,
struct V_293 * V_294 , T_2 * V_559 ,
enum V_560 V_298 )
{
struct V_299 * V_300 ;
struct V_561 * V_562 ;
if ( ! F_81 ( V_2 -> V_72 , V_563 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_563 ) ;
V_562 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
if ( ! ( V_562 -> V_564 & F_45 ( V_298 ) ) )
return;
if ( V_562 -> V_565 &&
memcmp ( V_562 -> V_566 , V_559 , V_167 ) != 0 )
return;
F_235 ( V_2 , V_300 ,
L_37 ,
V_559 , V_298 ) ;
}
static void F_236 ( struct V_1 * V_2 ,
struct V_136 * V_554 )
{
struct V_305 * V_306 ;
struct V_265 * V_266 ;
int V_9 ;
F_4 ( & V_554 -> V_537 ) ;
for ( V_9 = 0 ; V_9 <= V_538 ; V_9 ++ ) {
V_306 = & V_554 -> V_306 [ V_9 ] ;
while ( ( V_266 = F_237 ( & V_306 -> V_567 ) ) )
F_77 ( V_2 -> V_30 , V_266 ) ;
}
F_5 ( & V_554 -> V_537 ) ;
}
static int F_238 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_263 * V_264 ,
enum V_568 V_569 ,
enum V_568 V_570 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_136 * V_554 = F_62 ( V_264 ) ;
int V_47 ;
F_164 ( V_2 , L_38 ,
V_264 -> V_164 , V_569 , V_570 ) ;
if ( F_15 ( ! V_329 -> V_334 ) )
return - V_327 ;
F_120 ( & V_2 -> V_399 ) ;
if ( V_569 == V_571 &&
V_570 == V_572 &&
F_41 ( V_2 ) ) {
F_236 ( V_2 , V_554 ) ;
F_120 ( & V_2 -> V_364 ) ;
}
F_87 ( & V_2 -> V_33 ) ;
V_554 -> V_484 = V_570 >= V_573 ;
if ( V_569 == V_572 &&
V_570 == V_571 ) {
if ( V_294 -> type == V_121 &&
V_294 -> V_408 . V_486 < 16 ) {
F_113 ( V_2 ,
L_39 ,
V_264 -> V_164 , V_294 -> V_408 . V_486 ) ;
V_47 = - V_327 ;
goto V_386;
}
if ( V_264 -> V_574 &&
( V_294 -> V_390 ||
F_239 ( V_2 , NULL ) ==
V_575 ||
F_197 ( V_2 ) > 1 ) ) {
F_164 ( V_2 , L_40 ) ;
V_47 = - V_576 ;
goto V_386;
}
V_47 = F_240 ( V_2 , V_294 , V_264 ) ;
if ( V_264 -> V_574 && V_47 == 0 ) {
F_241 ( V_2 , V_294 , true ) ;
F_234 ( V_2 , V_294 , V_264 -> V_164 ,
V_577 ) ;
}
} else if ( V_569 == V_571 &&
V_570 == V_578 ) {
V_2 -> V_579 = true ;
F_232 ( V_2 , V_294 , V_264 -> V_164 ) ;
V_47 = 0 ;
} else if ( V_569 == V_578 &&
V_570 == V_573 ) {
if ( V_294 -> type == V_143 ) {
V_329 -> V_505 ++ ;
F_167 ( V_2 , V_294 , false , NULL ) ;
}
F_242 ( V_2 , V_264 , V_329 -> V_334 -> V_580 -> V_581 ,
true ) ;
V_47 = F_243 ( V_2 , V_294 , V_264 ) ;
} else if ( V_569 == V_573 &&
V_570 == V_582 ) {
if ( F_197 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
if ( V_264 -> V_574 )
F_234 ( V_2 , V_294 , V_264 -> V_164 ,
V_583 ) ;
F_8 ( F_192 ( V_2 , V_294 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_569 == V_582 &&
V_570 == V_573 ) {
F_8 ( F_138 ( V_2 , V_294 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_569 == V_573 &&
V_570 == V_578 ) {
if ( V_294 -> type == V_143 ) {
V_329 -> V_505 -- ;
F_167 ( V_2 , V_294 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_569 == V_578 &&
V_570 == V_571 ) {
V_47 = 0 ;
} else if ( V_569 == V_571 &&
V_570 == V_572 ) {
V_47 = F_244 ( V_2 , V_294 , V_264 ) ;
if ( V_264 -> V_574 ) {
F_241 ( V_2 , V_294 , false ) ;
F_234 ( V_2 , V_294 , V_264 -> V_164 ,
V_584 ) ;
}
} else {
V_47 = - V_17 ;
}
V_386:
F_93 ( & V_2 -> V_33 ) ;
if ( V_264 -> V_574 && V_47 == 0 ) {
if ( V_569 == V_572 &&
V_570 == V_571 )
F_245 ( V_264 , V_585 ) ;
else if ( V_569 == V_571 &&
V_570 == V_572 )
F_246 ( V_264 , V_585 ) ;
}
return V_47 ;
}
static int F_247 ( struct V_29 * V_30 , T_1 V_586 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_224 = V_586 ;
return 0 ;
}
static void F_248 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_263 * V_264 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_294 -> type == V_121 &&
V_27 & V_587 )
F_185 ( V_2 , V_294 , false ) ;
}
static int F_249 ( struct V_29 * V_30 ,
struct V_293 * V_294 , V_140 V_588 ,
const struct V_589 * V_316 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
V_329 -> V_590 [ V_588 ] = * V_316 ;
if ( V_294 -> type == V_145 ) {
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_167 ( V_2 , V_294 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_250 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_591 = V_592 ;
T_1 V_593 = V_594 ;
if ( F_15 ( V_294 -> V_408 . V_409 ) )
return;
if ( F_12 ( V_2 , V_595 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_184 ( V_2 , V_294 , V_591 , V_593 , 500 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_595 ) ;
}
static int F_251 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_596 * V_526 ,
struct V_597 * V_528 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! V_294 -> V_408 . V_521 ) {
V_47 = - V_576 ;
goto V_34;
}
V_47 = F_252 ( V_2 , V_294 , V_526 , V_528 , V_522 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_253 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_340 & V_522 ) ) {
F_93 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_205 ( V_2 , V_522 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_254 ( V_2 ) ;
return V_47 ;
}
static int F_255 ( struct V_29 * V_30 ,
enum V_598 V_371 ,
struct V_293 * V_294 ,
struct V_263 * V_264 ,
struct V_599 * V_600 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_267 ;
struct V_601 * V_602 ;
int V_603 = V_600 -> V_603 ;
int V_47 ;
T_2 V_604 ;
if ( V_108 . V_109 ) {
F_164 ( V_2 , L_41 ) ;
return - V_605 ;
}
switch ( V_600 -> V_115 ) {
case V_54 :
V_600 -> V_147 |= V_606 ;
V_600 -> V_147 |= V_607 ;
break;
case V_55 :
case V_106 :
case V_107 :
V_600 -> V_147 |= V_607 ;
break;
case V_111 :
case V_112 :
case V_113 :
F_15 ( ! F_256 ( V_30 , V_110 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_294 -> type != V_121 )
return 0 ;
break;
default:
if ( V_30 -> V_119 &&
V_30 -> V_129 -> V_115 == V_600 -> V_115 )
V_600 -> V_147 |= V_607 ;
else
return - V_605 ;
}
F_87 ( & V_2 -> V_33 ) ;
switch ( V_371 ) {
case V_608 :
if ( ( V_294 -> type == V_146 ||
V_294 -> type == V_143 ) && ! V_264 ) {
if ( V_600 -> V_115 == V_111 ||
V_600 -> V_115 == V_112 ||
V_600 -> V_115 == V_113 )
V_47 = - V_605 ;
else
V_47 = 0 ;
V_600 -> V_609 = V_610 ;
break;
}
if ( F_14 ( V_354 , & V_2 -> V_15 ) &&
V_600 -> V_609 == V_610 ) {
F_164 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_354 , & V_2 -> V_15 ) &&
V_264 && F_39 ( V_2 ) &&
V_600 -> V_147 & V_611 &&
( V_600 -> V_115 == V_55 ||
V_600 -> V_115 == V_106 ||
V_600 -> V_115 == V_107 ) ) {
struct V_612 V_613 ;
int V_295 , V_614 ;
V_267 = F_62 ( V_264 ) ;
F_8 ( F_200 ( V_267 -> V_602 [ V_603 ] ) ) ;
V_602 = F_162 ( sizeof( * V_602 ) +
V_2 -> V_7 -> V_76 *
sizeof( V_602 -> V_614 [ 0 ] ) ,
V_615 ) ;
if ( ! V_602 ) {
V_47 = - V_616 ;
break;
}
for ( V_295 = 0 ; V_295 < V_538 ; V_295 ++ ) {
F_257 ( V_600 , V_295 , & V_613 ) ;
for ( V_614 = 0 ; V_614 < V_2 -> V_7 -> V_76 ; V_614 ++ )
memcpy ( V_602 -> V_614 [ V_614 ] . V_617 [ V_295 ] ,
V_613 . V_618 . V_617 ,
V_619 ) ;
}
F_230 ( V_267 -> V_602 [ V_603 ] , V_602 ) ;
}
if ( F_14 ( V_354 , & V_2 -> V_15 ) )
V_604 = V_600 -> V_609 ;
else
V_604 = V_610 ;
F_164 ( V_2 , L_43 ) ;
V_47 = F_258 ( V_2 , V_294 , V_264 , V_600 , V_604 ) ;
if ( V_47 ) {
F_203 ( V_2 , L_44 ) ;
V_600 -> V_609 = V_610 ;
V_47 = 0 ;
}
break;
case V_620 :
if ( V_600 -> V_609 == V_610 ) {
V_47 = 0 ;
break;
}
if ( V_264 && F_39 ( V_2 ) &&
V_600 -> V_147 & V_611 &&
( V_600 -> V_115 == V_55 ||
V_600 -> V_115 == V_106 ||
V_600 -> V_115 == V_107 ) ) {
V_267 = F_62 ( V_264 ) ;
V_602 = F_259 (
V_267 -> V_602 [ V_603 ] ,
F_260 ( & V_2 -> V_33 ) ) ;
F_201 ( V_267 -> V_602 [ V_603 ] , NULL ) ;
if ( V_602 )
F_261 ( V_602 , V_621 ) ;
}
F_164 ( V_2 , L_45 ) ;
V_47 = F_262 ( V_2 , V_294 , V_264 , V_600 ) ;
break;
default:
V_47 = - V_327 ;
}
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_263 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_599 * V_622 ,
struct V_263 * V_264 ,
T_1 V_623 , V_140 * V_624 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_622 -> V_609 == V_610 )
return;
F_264 ( V_2 , V_294 , V_622 , V_264 , V_623 , V_624 ) ;
}
static bool F_265 ( struct V_625 * V_626 ,
struct V_476 * V_477 , void * V_281 )
{
struct V_1 * V_2 =
F_266 ( V_626 , struct V_1 , V_626 ) ;
struct V_627 * V_32 ;
int V_628 = F_267 ( V_477 ) ;
struct V_629 * V_630 = V_281 ;
if ( F_8 ( V_477 -> V_280 . V_371 != V_631 ) )
return true ;
if ( F_15 ( V_628 != sizeof( * V_32 ) ) ) {
F_113 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_477 -> V_281 ;
F_268 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_632 ) ;
V_630 -> V_633 = F_44 ( V_32 -> V_632 ) ;
F_268 ( V_2 , L_48 ,
V_630 -> V_633 ) ;
F_4 ( & V_2 -> V_332 ) ;
F_269 ( & V_630 -> V_634 , & V_2 -> V_635 ) ;
F_5 ( & V_2 -> V_332 ) ;
return true ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_636 * V_580 ,
struct V_293 * V_294 ,
int V_591 )
{
int V_637 , V_638 = V_639 ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_629 * V_630 = & V_329 -> V_640 ;
static const V_140 V_641 [] = { V_631 } ;
struct V_642 V_643 ;
T_1 V_644 = V_294 -> V_408 . V_645 *
V_294 -> V_408 . V_486 ;
T_1 V_646 , V_647 ;
struct V_648 V_649 = {
. V_298 = F_129 ( V_650 ) ,
. V_651 =
F_129 ( F_271 ( V_652 , 0 ) ) ,
. V_653 = F_129 ( V_2 -> V_654 . V_270 ) ,
. V_655 . V_581 = ( V_580 -> V_581 == V_181 ) ?
V_656 : V_657 ,
. V_655 . V_580 = V_580 -> V_658 ,
. V_655 . V_659 = V_660 ,
. V_661 = F_129 ( F_272 ( V_2 -> V_7 , V_638 ) ) ,
} ;
V_647 = V_662 ;
V_646 = F_273 ( V_591 ) ;
if ( V_294 -> V_408 . V_409 ) {
V_647 = F_274 ( T_1 , V_644 * 3 , V_663 ) ;
if ( V_644 <= V_646 ) {
V_646 = V_644 - V_664 ;
if ( V_646 <= V_665 )
V_646 = V_644 -
V_666 ;
}
}
V_649 . V_591 = F_129 ( V_646 ) ;
V_649 . V_667 = F_129 ( V_647 ) ;
F_268 ( V_2 ,
L_49 ,
V_580 -> V_658 , V_646 , V_591 , V_647 ,
V_644 ) ;
memcpy ( V_649 . V_668 , V_294 -> V_164 , V_167 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_332 ) ;
if ( F_8 ( V_630 -> V_20 == V_631 ) ) {
F_5 ( & V_2 -> V_332 ) ;
return - V_17 ;
}
V_630 -> V_294 = V_294 ;
V_630 -> V_591 = V_591 ;
V_630 -> V_20 = V_631 ;
F_5 ( & V_2 -> V_332 ) ;
F_275 ( & V_2 -> V_626 , & V_643 ,
V_641 ,
F_43 ( V_641 ) ,
F_265 , V_630 ) ;
V_637 = F_131 ( V_2 , V_631 , 0 , sizeof( V_649 ) ,
& V_649 ) ;
if ( V_637 ) {
F_113 ( V_2 , L_50 , V_637 ) ;
F_276 ( & V_2 -> V_626 , & V_643 ) ;
goto V_669;
}
V_637 = F_277 ( & V_2 -> V_626 , & V_643 , 1 ) ;
F_15 ( V_637 ) ;
if ( V_637 ) {
V_669:
F_4 ( & V_2 -> V_332 ) ;
F_96 ( V_2 , V_630 ) ;
F_5 ( & V_2 -> V_332 ) ;
}
return V_637 ;
}
static int F_278 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_636 * V_580 ,
int V_591 ,
enum V_670 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_671 V_672 ;
struct V_368 * V_334 ;
int V_47 , V_9 ;
F_164 ( V_2 , L_51 , V_580 -> V_658 ,
V_591 , type ) ;
F_120 ( & V_2 -> V_360 ) ;
F_87 ( & V_2 -> V_33 ) ;
switch ( V_294 -> type ) {
case V_121 :
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_673 ) ) {
V_47 = F_270 ( V_2 , V_580 ,
V_294 , V_591 ) ;
goto V_386;
}
F_113 ( V_2 , L_52 ) ;
V_47 = - V_327 ;
goto V_386;
case V_145 :
break;
default:
F_113 ( V_2 , L_53 , V_294 -> type ) ;
V_47 = - V_327 ;
goto V_386;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_334 = & V_2 -> V_18 [ V_9 ] ;
if ( V_334 -> V_21 == 0 || V_329 -> V_334 == V_334 )
continue;
if ( V_334 -> V_21 && V_580 == V_334 -> V_580 ) {
V_47 = F_142 ( V_2 , V_294 ) ;
if ( F_279 ( V_47 , L_54 ) )
goto V_386;
F_143 ( V_2 , V_329 -> V_334 ) ;
V_329 -> V_334 = V_334 ;
V_47 = F_140 ( V_2 , V_294 ) ;
if ( F_279 ( V_47 , L_55 ) )
goto V_386;
F_139 ( V_2 , V_329 -> V_334 ) ;
goto V_674;
}
}
if ( V_580 == V_329 -> V_334 -> V_580 )
goto V_674;
F_280 ( & V_672 , V_580 , V_675 ) ;
if ( V_329 -> V_334 -> V_21 == 1 ) {
V_47 = F_281 ( V_2 , V_329 -> V_334 ,
& V_672 , 1 , 1 ) ;
if ( V_47 )
goto V_386;
} else {
V_334 = F_127 ( V_2 ) ;
if ( ! V_334 ) {
V_47 = - V_394 ;
goto V_386;
}
V_47 = F_281 ( V_2 , V_334 , & V_672 ,
1 , 1 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_56 ) ;
goto V_386;
}
V_47 = F_142 ( V_2 , V_294 ) ;
if ( F_279 ( V_47 , L_54 ) )
goto V_386;
F_143 ( V_2 , V_329 -> V_334 ) ;
V_329 -> V_334 = V_334 ;
V_47 = F_140 ( V_2 , V_294 ) ;
if ( F_279 ( V_47 , L_55 ) )
goto V_386;
F_139 ( V_2 , V_329 -> V_334 ) ;
}
V_674:
V_47 = F_282 ( V_2 , V_294 , V_591 , type ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
F_164 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_283 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_164 ( V_2 , L_58 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_284 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_164 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_676 * V_677 )
{
V_140 * V_678 = ( V_140 * ) V_677 -> V_679 ;
struct V_368 * V_334 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_164 ( V_2 , L_59 ) ;
V_334 = F_127 ( V_2 ) ;
if ( ! V_334 ) {
V_47 = - V_394 ;
goto V_34;
}
V_47 = F_281 ( V_2 , V_334 , & V_677 -> V_680 ,
V_677 -> V_681 ,
V_677 -> V_682 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_60 ) ;
goto V_34;
}
F_139 ( V_2 , V_334 ) ;
* V_678 = V_334 -> V_20 ;
V_34:
return V_47 ;
}
static int F_286 ( struct V_29 * V_30 ,
struct V_676 * V_677 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_285 ( V_2 , V_677 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_287 ( struct V_1 * V_2 ,
struct V_676 * V_677 )
{
V_140 * V_678 = ( V_140 * ) V_677 -> V_679 ;
struct V_368 * V_334 = & V_2 -> V_18 [ * V_678 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_143 ( V_2 , V_334 ) ;
}
static void F_288 ( struct V_29 * V_30 ,
struct V_676 * V_677 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_287 ( V_2 , V_677 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_289 ( struct V_29 * V_30 ,
struct V_676 * V_677 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_140 * V_678 = ( V_140 * ) V_677 -> V_679 ;
struct V_368 * V_334 = & V_2 -> V_18 [ * V_678 ] ;
if ( F_117 ( ( V_334 -> V_21 > 1 ) &&
( V_27 & ~ ( V_683 |
V_684 |
V_685 |
V_686 ) ) ,
L_61 ,
V_334 -> V_21 , V_27 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_189 ( V_2 ) ;
F_281 ( V_2 , V_334 , & V_677 -> V_680 ,
V_677 -> V_681 ,
V_677 -> V_682 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_290 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
struct V_676 * V_677 ,
bool V_687 )
{
V_140 * V_678 = ( V_140 * ) V_677 -> V_679 ;
struct V_368 * V_334 = & V_2 -> V_18 [ * V_678 ] ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_329 -> V_334 = V_334 ;
switch ( V_294 -> type ) {
case V_143 :
if ( V_687 ) {
V_329 -> V_507 = true ;
break;
}
case V_146 :
V_47 = 0 ;
goto V_34;
case V_121 :
break;
case V_523 :
V_329 -> V_341 = true ;
break;
default:
V_47 = - V_327 ;
goto V_34;
}
V_47 = F_140 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_34;
F_137 ( V_2 ) ;
if ( V_294 -> type == V_523 ) {
V_329 -> V_688 = true ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_689;
V_47 = F_291 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_689;
}
if ( V_294 -> type == V_143 ) {
F_112 ( V_2 , false , NULL ) ;
F_167 ( V_2 , V_294 , false , NULL ) ;
}
if ( V_687 && V_294 -> type == V_121 ) {
T_1 V_591 = 2 * V_294 -> V_408 . V_486 ;
V_47 = F_12 ( V_2 , V_690 ) ;
if ( V_47 )
goto V_689;
F_184 ( V_2 , V_294 , V_591 , V_591 ,
V_294 -> V_408 . V_486 / 2 ,
true ) ;
F_7 ( V_2 , V_690 ) ;
F_112 ( V_2 , false , NULL ) ;
}
goto V_34;
V_689:
F_142 ( V_2 , V_294 ) ;
F_137 ( V_2 ) ;
V_34:
if ( V_47 )
V_329 -> V_334 = NULL ;
return V_47 ;
}
static int F_292 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_676 * V_677 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_290 ( V_2 , V_294 , V_677 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_293 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
struct V_676 * V_677 ,
bool V_687 )
{
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_293 * V_691 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_191 ( V_2 , V_329 , & V_329 -> V_333 ) ;
switch ( V_294 -> type ) {
case V_146 :
goto V_34;
case V_523 :
V_329 -> V_688 = false ;
V_329 -> V_341 = false ;
F_294 ( V_2 , V_294 ) ;
break;
case V_143 :
if ( ! V_687 || ! V_329 -> V_507 )
goto V_34;
V_329 -> V_511 = false ;
F_295 ( V_2 , V_329 , true ) ;
F_230 ( V_2 -> V_512 , V_294 ) ;
V_329 -> V_507 = false ;
break;
case V_121 :
if ( ! V_687 )
break;
V_691 = V_294 ;
F_167 ( V_2 , V_294 , true , NULL ) ;
break;
default:
break;
}
F_112 ( V_2 , false , V_691 ) ;
F_142 ( V_2 , V_294 ) ;
V_34:
V_329 -> V_334 = NULL ;
F_137 ( V_2 ) ;
}
static void F_296 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_676 * V_677 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_293 ( V_2 , V_294 , V_677 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int
F_297 ( struct V_1 * V_2 ,
struct V_692 * V_693 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_293 ( V_2 , V_693 [ 0 ] . V_294 , V_693 [ 0 ] . V_694 , true ) ;
F_287 ( V_2 , V_693 [ 0 ] . V_694 ) ;
V_47 = F_285 ( V_2 , V_693 [ 0 ] . V_695 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_62 ) ;
goto V_696;
}
V_47 = F_290 ( V_2 , V_693 [ 0 ] . V_294 , V_693 [ 0 ] . V_695 ,
true ) ;
if ( V_47 ) {
F_113 ( V_2 ,
L_63 ) ;
goto V_506;
}
if ( F_197 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
goto V_34;
V_506:
F_287 ( V_2 , V_693 [ 0 ] . V_695 ) ;
V_696:
if ( F_285 ( V_2 , V_693 [ 0 ] . V_694 ) ) {
F_113 ( V_2 , L_64 ) ;
goto V_697;
}
if ( F_290 ( V_2 , V_693 [ 0 ] . V_294 , V_693 [ 0 ] . V_694 ,
true ) ) {
F_113 ( V_2 , L_65 ) ;
goto V_697;
}
goto V_34;
V_697:
F_298 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_299 ( struct V_1 * V_2 ,
struct V_692 * V_693 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_293 ( V_2 , V_693 [ 0 ] . V_294 , V_693 [ 0 ] . V_694 , true ) ;
V_47 = F_290 ( V_2 , V_693 [ 0 ] . V_294 , V_693 [ 0 ] . V_695 ,
true ) ;
if ( V_47 ) {
F_113 ( V_2 ,
L_63 ) ;
goto V_696;
}
goto V_34;
V_696:
if ( F_290 ( V_2 , V_693 [ 0 ] . V_294 , V_693 [ 0 ] . V_694 ,
true ) ) {
F_113 ( V_2 , L_65 ) ;
goto V_697;
}
goto V_34;
V_697:
F_298 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_300 ( struct V_29 * V_30 ,
struct V_692 * V_693 ,
int V_698 ,
enum V_699 V_700 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_698 > 1 )
return - V_605 ;
switch ( V_700 ) {
case V_701 :
V_47 = F_297 ( V_2 , V_693 ) ;
break;
case V_702 :
V_47 = F_299 ( V_2 , V_693 ) ;
break;
default:
V_47 = - V_605 ;
break;
}
return V_47 ;
}
static int F_301 ( struct V_29 * V_30 ,
struct V_263 * V_264 ,
bool V_703 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_554 = F_62 ( V_264 ) ;
if ( ! V_554 || ! V_554 -> V_294 ) {
F_113 ( V_2 , L_66 ) ;
return - V_327 ;
}
return F_195 ( V_2 , V_554 -> V_294 ) ;
}
static int F_302 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
void * V_281 , int V_377 )
{
struct V_704 * V_705 [ V_706 + 1 ] ;
int V_707 ;
T_1 V_401 ;
V_707 = F_303 ( V_705 , V_706 , V_281 , V_377 , V_708 ) ;
if ( V_707 )
return V_707 ;
if ( ! V_705 [ V_709 ] )
return - V_327 ;
switch ( F_304 ( V_705 [ V_709 ] ) ) {
case V_710 :
if ( ! V_294 || V_294 -> type != V_143 || ! V_294 -> V_390 ||
! V_294 -> V_408 . V_711 ||
! V_705 [ V_712 ] )
return - V_327 ;
V_401 = F_304 ( V_705 [ V_712 ] ) ;
if ( V_401 >= V_294 -> V_408 . V_486 )
return - V_327 ;
V_2 -> V_401 = V_401 ;
V_2 -> V_400 = V_294 ;
return F_112 ( V_2 , false , NULL ) ;
case V_713 :
if ( ! V_294 || V_294 -> type != V_121 ||
! V_294 -> V_408 . V_409 || ! V_294 -> V_408 . V_645 ||
! V_705 [ V_714 ] )
return - V_327 ;
if ( F_304 ( V_705 [ V_714 ] ) )
return F_192 ( V_2 , V_294 , 0 ) ;
return F_138 ( V_2 , V_294 , 0 ) ;
}
return - V_605 ;
}
static int F_305 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
void * V_281 , int V_377 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_707 ;
F_87 ( & V_2 -> V_33 ) ;
V_707 = F_302 ( V_2 , V_294 , V_281 , V_377 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_707 ;
}
static void F_306 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_715 * V_716 )
{
F_164 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_307 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_715 * V_716 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_293 * V_510 ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
T_1 V_661 ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_329 -> V_717 = false ;
F_164 ( V_2 , L_68 ,
V_716 -> V_672 . V_718 ) ;
F_308 ( V_2 , V_294 , V_719 ) ;
switch ( V_294 -> type ) {
case V_143 :
V_510 =
F_259 ( V_2 -> V_510 ,
F_260 ( & V_2 -> V_33 ) ) ;
if ( F_117 ( V_510 && V_510 -> V_720 ,
L_69 ) ) {
V_47 = - V_576 ;
goto V_386;
}
if ( F_259 ( V_2 -> V_512 ,
F_260 ( & V_2 -> V_33 ) ) ) {
V_47 = - V_576 ;
goto V_386;
}
F_230 ( V_2 -> V_510 , V_294 ) ;
if ( F_117 ( V_329 -> V_511 ,
L_70 ) ) {
V_47 = - V_576 ;
goto V_386;
}
V_329 -> V_721 = V_716 -> V_672 . V_722 -> V_723 ;
break;
case V_121 :
if ( V_329 -> V_481 )
F_182 ( V_294 ,
V_482 ,
0 , 0 ) ;
V_661 = V_716 -> V_724 +
( ( V_294 -> V_408 . V_486 * ( V_716 -> V_411 - 1 ) -
V_725 ) * 1024 ) ;
if ( V_716 -> V_726 )
F_309 ( V_2 , V_294 ) ;
F_310 ( V_2 , V_294 , V_294 -> V_408 . V_486 ,
V_661 ) ;
if ( V_329 -> V_335 . V_502 ) {
V_47 = F_138 ( V_2 , V_294 , 0 ) ;
if ( V_47 )
goto V_386;
}
break;
default:
break;
}
V_329 -> V_341 = true ;
V_47 = F_311 ( V_2 ) ;
if ( V_47 )
goto V_386;
F_114 ( V_2 ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_312 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_329 -> V_717 ) {
V_329 -> V_717 = false ;
V_47 = - V_17 ;
goto V_386;
}
if ( V_294 -> type == V_121 ) {
struct V_136 * V_267 ;
V_267 = F_313 ( V_2 ,
V_329 -> V_331 ) ;
if ( F_8 ( ! V_267 ) ) {
V_47 = - V_17 ;
goto V_386;
}
F_314 ( V_2 , V_267 , false ) ;
F_167 ( V_2 , V_294 , false , NULL ) ;
V_47 = F_192 ( V_2 , V_294 , 0 ) ;
if ( V_47 )
goto V_386;
F_315 ( V_2 , V_294 ) ;
}
V_329 -> V_341 = false ;
V_47 = F_311 ( V_2 ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_316 ( struct V_29 * V_30 ,
struct V_293 * V_294 , T_1 V_82 , bool V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 ;
struct V_136 * V_267 ;
struct V_263 * V_264 ;
int V_9 ;
T_1 V_727 = 0 ;
if ( ! V_294 || V_294 -> type != V_121 )
return;
if ( F_41 ( V_2 ) )
F_120 ( & V_2 -> V_364 ) ;
F_87 ( & V_2 -> V_33 ) ;
V_329 = F_95 ( V_294 ) ;
for ( V_9 = 0 ; V_9 < V_271 ; V_9 ++ ) {
V_264 = F_259 ( V_2 -> V_549 [ V_9 ] ,
F_260 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_264 ) )
continue;
V_267 = F_62 ( V_264 ) ;
if ( V_267 -> V_294 != V_294 )
continue;
F_8 ( V_9 != V_329 -> V_331 && ! V_264 -> V_574 ) ;
V_727 |= V_267 -> V_728 ;
}
if ( V_282 ) {
if ( F_148 ( V_2 , V_727 , 0 ) )
F_113 ( V_2 , L_71 ) ;
F_93 ( & V_2 -> V_33 ) ;
} else {
F_93 ( & V_2 -> V_33 ) ;
F_149 ( V_2 -> V_7 , V_727 ) ;
}
}
static int F_317 ( struct V_29 * V_30 , int V_729 ,
struct V_730 * V_731 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_731 , 0 , sizeof( * V_731 ) ) ;
if ( V_729 != 0 )
return - V_49 ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_732 ) )
return - V_49 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_733 ) {
V_47 = F_183 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_731 -> V_734 = V_735 |
V_736 |
V_737 |
V_738 ;
V_731 -> time = V_2 -> V_359 . V_739 +
V_2 -> V_740 . V_739 ;
F_318 ( V_731 -> time , V_741 ) ;
V_731 -> V_742 = V_2 -> V_359 . V_743 +
V_2 -> V_740 . V_743 ;
F_318 ( V_731 -> V_742 , V_741 ) ;
V_731 -> V_744 = V_2 -> V_359 . V_745 +
V_2 -> V_740 . V_745 ;
F_318 ( V_731 -> V_744 , V_741 ) ;
V_731 -> V_746 = V_2 -> V_359 . V_747 +
V_2 -> V_740 . V_747 ;
F_318 ( V_731 -> V_746 , V_741 ) ;
V_47 = 0 ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_319 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_263 * V_264 ,
struct V_748 * V_749 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_136 * V_267 = F_62 ( V_264 ) ;
if ( V_267 -> V_750 ) {
V_749 -> V_751 = V_267 -> V_750 ;
V_749 -> V_734 |= F_45 ( V_752 ) ;
}
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_732 ) )
return;
if ( ! ( V_294 -> V_391 & V_392 ) )
return;
if ( ! V_294 -> V_408 . V_409 )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_329 -> V_331 != V_267 -> V_270 )
goto V_753;
if ( F_183 ( V_2 , false ) )
goto V_753;
V_749 -> V_754 = V_329 -> V_383 . V_385 +
V_329 -> V_383 . V_384 ;
V_749 -> V_734 |= F_45 ( V_755 ) ;
if ( V_329 -> V_383 . V_756 ) {
V_749 -> V_757 = V_329 -> V_383 . V_756 ;
V_749 -> V_734 |= F_45 ( V_758 ) ;
}
V_753:
F_93 ( & V_2 -> V_33 ) ;
}
static void F_320 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
const struct V_759 * V_760 )
{
#define F_321 ( T_5 , T_6 , T_7 , T_8 , T_9 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_299 * V_300 ;
struct V_761 * V_762 ;
if ( ! F_81 ( V_2 -> V_72 , V_763 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_763 ) ;
V_762 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
if ( V_760 -> V_764 . V_765 . V_281 == V_766 ) {
if ( V_760 -> V_764 . V_765 . V_15 == V_767 )
F_321 ( V_2 , V_300 , V_768 ,
V_762 -> V_769 ,
L_72 ,
V_760 -> V_764 . V_765 . V_533 ) ;
else if ( V_760 -> V_764 . V_765 . V_15 == V_770 )
F_321 ( V_2 , V_300 , V_768 ,
V_762 -> V_771 ,
L_73 ) ;
} else if ( V_760 -> V_764 . V_765 . V_281 == V_772 ) {
if ( V_760 -> V_764 . V_765 . V_15 == V_767 )
F_321 ( V_2 , V_300 , V_768 ,
V_762 -> V_773 ,
L_74 ,
V_760 -> V_764 . V_765 . V_533 ) ;
else if ( V_760 -> V_764 . V_765 . V_15 == V_770 )
F_321 ( V_2 , V_300 , V_768 ,
V_762 -> V_774 ,
L_75 ) ;
} else if ( V_760 -> V_764 . V_765 . V_281 == V_775 ) {
F_321 ( V_2 , V_300 , V_768 ,
V_762 -> V_776 ,
L_76 , V_760 -> V_764 . V_765 . V_533 ) ;
} else if ( V_760 -> V_764 . V_765 . V_281 == V_777 ) {
F_321 ( V_2 , V_300 , V_768 ,
V_762 -> V_778 ,
L_77 , V_760 -> V_764 . V_765 . V_533 ) ;
}
#undef F_321
}
static void F_322 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
const struct V_759 * V_760 )
{
struct V_299 * V_300 ;
struct V_301 * V_302 ;
if ( ! F_81 ( V_2 -> V_72 , V_303 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_303 ) ;
V_302 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
if ( ! ( F_323 ( V_302 -> V_779 ) & F_45 ( V_760 -> V_764 . V_780 . V_295 ) ) )
return;
F_235 ( V_2 , V_300 ,
L_78 ,
V_760 -> V_764 . V_780 . V_264 -> V_164 , V_760 -> V_764 . V_780 . V_295 ,
V_760 -> V_764 . V_780 . V_308 ) ;
}
static void
F_324 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
const struct V_759 * V_760 )
{
struct V_299 * V_300 ;
struct V_301 * V_302 ;
if ( ! F_81 ( V_2 -> V_72 , V_303 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_303 ) ;
V_302 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
if ( ! ( F_323 ( V_302 -> V_781 ) & F_45 ( V_760 -> V_764 . V_780 . V_295 ) ) )
return;
F_235 ( V_2 , V_300 ,
L_79 ,
V_760 -> V_764 . V_780 . V_264 -> V_164 , V_760 -> V_764 . V_780 . V_295 ) ;
}
static void F_325 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
const struct V_759 * V_760 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_760 -> type ) {
case V_782 :
F_320 ( V_2 , V_294 , V_760 ) ;
break;
case V_783 :
F_322 ( V_2 , V_294 , V_760 ) ;
break;
case V_784 :
F_324 ( V_2 , V_294 , V_760 ) ;
break;
default:
break;
}
}
void F_326 ( struct V_1 * V_2 ,
struct V_785 * V_473 ,
T_1 V_786 )
{
T_1 V_787 = F_45 ( V_2 -> V_7 -> V_76 ) - 1 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! F_39 ( V_2 ) )
return;
V_473 -> V_788 = V_2 -> V_789 ;
if ( V_473 -> V_790 )
F_327 ( & V_2 -> V_791 ,
V_2 -> V_7 -> V_76 ) ;
V_47 = F_328 ( V_2 , V_787 , ( T_2 * ) V_473 , V_786 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_80 , V_47 ) ;
goto V_34;
}
if ( V_473 -> V_790 )
V_47 = F_13 ( V_2 -> V_792 ,
F_215 ( & V_2 -> V_791 ) == 0 ,
V_16 ) ;
F_15 ( ! V_47 ) ;
V_34:
F_327 ( & V_2 -> V_791 , 0 ) ;
V_2 -> V_789 ++ ;
}
static void F_329 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_785 V_281 = {
. type = V_793 ,
. V_790 = 1 ,
} ;
F_87 ( & V_2 -> V_33 ) ;
F_326 ( V_2 , & V_281 , sizeof( V_281 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
