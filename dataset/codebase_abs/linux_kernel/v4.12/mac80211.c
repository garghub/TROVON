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
if ( F_41 ( V_2 ) ) {
V_47 = F_135 ( V_2 , & V_329 -> V_388 ,
0 , V_294 -> type ,
V_389 ) ;
if ( V_47 )
goto V_387;
}
F_136 ( V_2 , V_294 ) ;
goto V_386;
}
V_329 -> V_131 |= V_30 -> V_79 ;
V_47 = F_137 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_387;
V_47 = F_138 ( V_2 ) ;
if ( V_47 )
goto V_390;
V_47 = F_139 ( V_2 , V_294 , 0 ) ;
if ( V_47 )
goto V_390;
if ( ! V_2 -> V_391 &&
V_294 -> type == V_121 && ! V_294 -> V_392 ) {
V_2 -> V_391 = V_329 ;
V_294 -> V_393 |= V_394 |
V_395 ;
}
if ( V_294 -> type == V_145 ) {
V_329 -> V_334 = F_127 ( V_2 ) ;
if ( ! V_329 -> V_334 ) {
V_47 = - V_396 ;
goto V_397;
}
F_140 ( V_2 , V_329 -> V_334 ) ;
V_47 = F_141 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_398;
V_47 = F_142 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_399;
V_2 -> V_343 = V_294 ;
}
F_136 ( V_2 , V_294 ) ;
goto V_386;
V_399:
F_143 ( V_2 , V_294 ) ;
V_398:
F_144 ( V_2 , V_329 -> V_334 ) ;
V_397:
if ( V_2 -> V_391 == V_329 ) {
V_2 -> V_391 = NULL ;
V_294 -> V_393 &= ~ ( V_394 |
V_395 ) ;
}
V_390:
V_329 -> V_334 = NULL ;
F_145 ( V_2 , V_294 ) ;
V_387:
if ( V_294 -> type != V_145 )
V_2 -> V_350 -- ;
F_146 ( V_2 , V_294 ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_382 ) ;
return V_47 ;
}
static void F_147 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
T_1 V_400 = F_148 ( V_294 ) ;
if ( V_400 ) {
F_87 ( & V_2 -> V_33 ) ;
F_149 ( V_2 , V_400 , 0 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_150 ( V_2 -> V_7 , V_400 ) ;
}
if ( V_294 -> type == V_145 ) {
F_120 ( & V_2 -> V_360 ) ;
} else {
F_120 ( & V_2 -> V_401 ) ;
}
}
static void F_151 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
F_147 ( V_2 , V_294 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_391 == V_329 ) {
V_2 -> V_391 = NULL ;
V_294 -> V_393 &= ~ ( V_394 |
V_395 ) ;
}
F_152 ( V_2 , V_294 ) ;
if ( V_294 -> type == V_143 ||
V_294 -> type == V_146 ) {
#ifdef F_153
if ( V_294 == V_2 -> V_402 ) {
V_2 -> V_402 = NULL ;
V_2 -> V_403 = 0 ;
}
#endif
F_154 ( V_2 , & V_329 -> V_388 ) ;
F_155 ( V_2 , V_294 ) ;
goto V_387;
}
if ( V_294 -> type == V_145 ) {
V_2 -> V_343 = NULL ;
F_156 ( V_2 , V_294 ) ;
F_143 ( V_2 , V_294 ) ;
F_144 ( V_2 , V_329 -> V_334 ) ;
V_329 -> V_334 = NULL ;
}
if ( V_2 -> V_350 && V_294 -> type != V_145 )
V_2 -> V_350 -- ;
F_138 ( V_2 ) ;
F_145 ( V_2 , V_294 ) ;
V_387:
F_146 ( V_2 , V_294 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_157 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_158 ( void * V_404 , T_2 * V_328 ,
struct V_293 * V_294 )
{
struct V_405 * V_281 = V_404 ;
struct V_1 * V_2 = V_281 -> V_2 ;
struct V_406 * V_371 = V_2 -> V_407 ;
int V_47 , V_377 ;
if ( F_15 ( V_281 -> V_408 >= V_409 ) )
return;
if ( V_294 -> type != V_121 ||
! V_294 -> V_410 . V_411 )
return;
V_371 -> V_408 = V_281 -> V_408 ++ ;
memcpy ( V_371 -> V_412 , V_294 -> V_410 . V_412 , V_167 ) ;
V_377 = F_159 ( sizeof( * V_371 ) + V_371 -> V_413 * V_167 , 4 ) ;
V_47 = F_131 ( V_2 , V_414 , V_415 , V_377 , V_371 ) ;
if ( V_47 )
F_113 ( V_2 , L_23 , V_47 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_405 V_416 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_407 ) )
return;
F_161 (
V_2 -> V_30 , V_417 ,
F_158 , & V_416 ) ;
}
static T_4 F_162 ( struct V_29 * V_30 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_406 * V_371 ;
struct V_420 * V_164 ;
int V_421 ;
bool V_422 ;
int V_377 ;
V_421 = F_163 ( V_419 ) ;
V_422 = V_421 > V_423 ||
V_424 ;
if ( V_422 )
V_421 = 0 ;
V_377 = F_159 ( sizeof( * V_371 ) + V_421 * V_167 , 4 ) ;
V_371 = F_164 ( V_377 , V_425 ) ;
if ( ! V_371 )
return 0 ;
if ( V_422 ) {
V_371 -> V_422 = 1 ;
return ( T_4 ) ( unsigned long ) V_371 ;
}
F_165 (addr, mc_list) {
F_166 ( V_2 , L_24 ,
V_371 -> V_413 , V_164 -> V_164 ) ;
memcpy ( & V_371 -> V_426 [ V_371 -> V_413 * V_167 ] ,
V_164 -> V_164 , V_167 ) ;
V_371 -> V_413 ++ ;
}
return ( T_4 ) ( unsigned long ) V_371 ;
}
static void F_167 ( struct V_29 * V_30 ,
unsigned int V_427 ,
unsigned int * V_428 ,
T_4 V_429 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_406 * V_371 = ( void * ) ( unsigned long ) V_429 ;
F_87 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_407 ) ;
V_2 -> V_407 = V_371 ;
if ( ! V_371 )
goto V_34;
F_160 ( V_2 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
* V_428 = 0 ;
}
static void F_168 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
unsigned int V_430 ,
unsigned int V_427 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_427 & V_431 ) )
return;
if ( V_294 -> type != V_121 || ! V_294 -> V_410 . V_411 ||
! V_294 -> V_392 )
return;
F_87 ( & V_2 -> V_33 ) ;
F_169 ( V_2 , V_294 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_170 ( struct V_293 * V_294 ,
const struct V_432 * V_433 ,
struct V_432 * V_434 )
{
struct V_435 * V_436 ;
int V_9 ;
memcpy ( V_434 , V_433 , sizeof( * V_434 ) ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_434 -> V_437 ) ; V_9 ++ ) {
V_436 = & V_434 -> V_437 [ V_9 ] ;
if ( ! V_436 -> V_438 )
break;
switch ( V_436 -> V_439 ) {
case F_130 ( V_440 ) :
if ( V_294 -> V_410 . V_441 != 1 ) {
V_436 -> V_438 = 0 ;
continue;
}
V_436 -> V_442 = V_294 -> V_410 . V_443 [ 0 ] ;
break;
case F_130 ( V_444 ) :
V_436 -> V_442 = * ( V_445 * ) & V_294 -> V_164 [ 2 ] ;
break;
default:
break;
}
V_436 -> V_439 = 0 ;
V_434 -> V_446 ++ ;
}
}
static void F_171 ( void * V_404 , T_2 * V_328 ,
struct V_293 * V_294 )
{
struct V_447 * V_281 = V_404 ;
struct V_1 * V_2 = V_281 -> V_2 ;
struct V_448 * V_371 = V_281 -> V_371 ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_449 * V_450 ;
int V_9 ;
if ( F_8 ( V_329 -> V_20 >= F_43 ( V_371 -> V_451 ) ) )
return;
V_450 = & V_371 -> V_451 [ V_329 -> V_20 ] ;
if ( V_294 -> type != V_121 || V_294 -> V_392 ||
! V_294 -> V_410 . V_411 )
return;
V_450 -> V_452 = 1 ;
for ( V_9 = 0 ; V_2 -> V_251 [ V_9 ] . V_437 [ 0 ] . V_438 ; V_9 ++ ) {
if ( F_15 ( V_281 -> V_453 >=
F_43 ( V_371 -> V_454 ) ) ) {
V_450 -> V_452 = 0 ;
V_450 -> V_455 = 0 ;
break;
}
F_170 ( V_294 ,
& V_2 -> V_251 [ V_9 ] ,
& V_371 -> V_454 [ V_281 -> V_453 ] ) ;
if ( ! V_371 -> V_454 [ V_281 -> V_453 ] . V_446 )
continue;
V_450 -> V_455 |=
F_130 ( F_45 ( V_281 -> V_453 ) ) ;
V_281 -> V_453 ++ ;
}
}
bool F_172 ( struct V_1 * V_2 ,
struct V_448 * V_371 )
{
struct V_447 V_416 = {
. V_2 = V_2 ,
. V_371 = V_371 ,
} ;
if ( V_456 )
return false ;
memset ( V_371 , 0 , sizeof( * V_371 ) ) ;
V_371 -> V_457 = F_43 ( V_371 -> V_454 ) ;
V_371 -> V_458 = F_43 ( V_371 -> V_451 ) ;
#ifdef F_173
if ( V_2 -> V_459 . V_460 ) {
memcpy ( V_371 -> V_454 , & V_2 -> V_459 . V_371 . V_454 ,
sizeof( V_371 -> V_454 ) ) ;
memcpy ( V_371 -> V_451 , & V_2 -> V_459 . V_371 . V_451 ,
sizeof( V_371 -> V_451 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_251 )
return false ;
F_174 (
V_2 -> V_30 , V_417 ,
F_171 , & V_416 ) ;
return true ;
}
static int F_175 ( struct V_1 * V_2 )
{
struct V_448 V_371 ;
if ( ! ( V_2 -> V_72 -> V_73 . V_147 & V_461 ) )
return 0 ;
if ( ! F_172 ( V_2 , & V_371 ) )
return 0 ;
return F_131 ( V_2 , V_462 , 0 ,
sizeof( V_371 ) , & V_371 ) ;
}
static inline int F_175 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_176 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
struct V_463 V_371 = {} ;
memcpy ( V_371 . V_464 , V_294 -> V_410 . V_465 . V_466 ,
V_467 ) ;
memcpy ( V_371 . V_468 , V_294 -> V_410 . V_465 . V_469 ,
V_470 ) ;
return F_131 ( V_2 ,
F_177 ( V_471 ,
V_472 ) ,
0 , sizeof( V_371 ) , & V_371 ) ;
}
static void F_178 ( void * V_404 , T_2 * V_328 ,
struct V_293 * V_294 )
{
if ( V_294 -> V_473 ) {
struct V_474 * V_475 = V_404 ;
F_179 ( V_294 ,
( T_2 * ) & V_475 -> V_464 ,
( T_2 * ) & V_475 -> V_468 ) ;
}
}
void F_180 ( struct V_1 * V_2 ,
struct V_476 * V_477 )
{
struct V_478 * V_479 = F_181 ( V_477 ) ;
struct V_474 * V_475 = ( void * ) V_479 -> V_281 ;
F_161 (
V_2 -> V_30 , V_417 ,
F_178 , V_475 ) ;
}
static void F_182 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
struct V_480 * V_410 ,
T_1 V_481 )
{
struct V_138 * V_329 = F_95 ( V_294 ) ;
int V_47 ;
if ( V_481 & V_482 && V_410 -> V_411 )
F_183 ( V_2 , V_294 ) ;
if ( V_481 & V_482 && ! V_410 -> V_411 &&
V_329 -> V_483 )
F_184 ( V_294 , V_484 ,
0 , 0 ) ;
if ( V_481 & V_485 && ! V_329 -> V_486 )
memcpy ( V_329 -> V_412 , V_410 -> V_412 , V_167 ) ;
V_47 = F_169 ( V_2 , V_294 , false , V_329 -> V_412 ) ;
if ( V_47 )
F_113 ( V_2 , L_25 , V_294 -> V_164 ) ;
memcpy ( V_329 -> V_412 , V_410 -> V_412 , V_167 ) ;
V_329 -> V_486 = V_410 -> V_411 ;
if ( V_481 & V_482 ) {
if ( V_410 -> V_411 ) {
F_185 ( V_2 , true ) ;
memset ( & V_329 -> V_383 , 0 ,
sizeof( V_329 -> V_383 ) ) ;
V_47 = F_112 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_113 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_354 ,
& V_2 -> V_15 ) ) {
T_1 V_487 = ( 11 * V_294 -> V_410 . V_488 ) / 10 ;
F_186 ( V_2 , V_294 , V_487 , V_487 ,
5 * V_487 , false ) ;
}
F_187 ( V_2 , V_294 , false ) ;
F_188 ( V_2 , V_294 ) ;
if ( V_294 -> V_392 ) {
F_1 ( V_2 , V_489 ) ;
F_189 ( V_2 , V_294 ,
V_490 ,
V_491 ) ;
}
} else if ( V_329 -> V_331 != V_271 ) {
F_117 ( F_187 ( V_2 , V_294 , false ) ,
L_27 ) ;
V_47 = F_190 ( V_2 , V_294 , V_329 -> V_331 ) ;
if ( V_47 )
F_113 ( V_2 , L_28 ) ;
if ( V_2 -> V_272 == V_329 -> V_331 )
V_2 -> V_272 = V_271 ;
V_329 -> V_331 = V_271 ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
F_113 ( V_2 , L_26 ) ;
if ( V_294 -> V_392 )
F_7 ( V_2 , V_489 ) ;
V_47 = F_169 ( V_2 , V_294 , false , NULL ) ;
if ( V_47 )
F_113 ( V_2 ,
L_29 ,
V_294 -> V_164 ) ;
}
if ( F_14 ( V_354 , & V_2 -> V_15 ) &&
( V_481 & V_492 ) && V_294 -> V_473 ) {
V_47 = F_176 ( V_2 , V_294 ) ;
if ( V_47 )
F_113 ( V_2 ,
L_30 ) ;
}
F_160 ( V_2 ) ;
F_175 ( V_2 ) ;
V_329 -> V_335 . V_493 = 0 ;
F_191 ( V_2 ) ;
F_189 ( V_2 , V_294 , V_494 ,
V_495 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_178 ) )
F_192 ( V_2 ) ;
}
if ( V_481 & V_496 ) {
F_193 ( V_2 , V_329 ,
& V_329 -> V_333 ) ;
F_187 ( V_2 , V_294 , false ) ;
F_8 ( F_194 ( V_2 , V_294 , 0 ) ) ;
}
if ( V_481 & ( V_497 | V_498 | V_499 |
V_496 ) ) {
V_47 = F_138 ( V_2 ) ;
if ( V_47 )
F_113 ( V_2 , L_31 ) ;
}
if ( V_481 & V_500 ) {
F_195 ( V_2 , L_32 ,
V_410 -> V_501 ) ;
F_128 ( V_2 , V_294 , V_410 -> V_501 ) ;
}
if ( V_481 & V_502 ) {
F_166 ( V_2 , L_33 ) ;
V_329 -> V_335 . V_503 = 0 ;
if ( V_329 -> V_335 . V_504 ) {
V_47 = F_194 ( V_2 , V_294 , 0 ) ;
if ( V_47 )
F_113 ( V_2 ,
L_34 ) ;
}
}
if ( V_481 & V_505 ) {
F_166 ( V_2 , L_35 ) ;
F_175 ( V_2 ) ;
}
}
static int F_196 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_506 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_197 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_386;
if ( V_294 -> type == V_143 )
F_183 ( V_2 , V_294 ) ;
V_329 -> V_507 = 0 ;
V_47 = F_137 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_386;
V_47 = F_141 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_508;
V_47 = F_198 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_399;
V_47 = F_199 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_509;
V_329 -> V_510 = true ;
F_138 ( V_2 ) ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_511;
if ( V_294 -> V_392 && V_2 -> V_343 )
F_169 ( V_2 , V_2 -> V_343 , false , NULL ) ;
F_1 ( V_2 , V_512 ) ;
F_191 ( V_2 ) ;
if ( F_200 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
goto V_386;
V_511:
F_138 ( V_2 ) ;
V_329 -> V_510 = false ;
F_201 ( V_2 , V_294 ) ;
V_509:
F_202 ( V_2 , V_294 ) ;
V_399:
F_143 ( V_2 , V_294 ) ;
V_508:
F_145 ( V_2 , V_294 ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_506 ) ;
return V_47 ;
}
static void F_203 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
F_147 ( V_2 , V_294 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_204 ( V_2 -> V_513 ) == V_294 ) {
F_193 ( V_2 , V_329 ,
& V_329 -> V_333 ) ;
F_205 ( V_2 -> V_513 , NULL ) ;
V_329 -> V_514 = false ;
}
if ( F_204 ( V_2 -> V_515 ) == V_294 ) {
F_205 ( V_2 -> V_515 , NULL ) ;
V_2 -> V_516 = 0 ;
}
V_329 -> V_510 = false ;
V_2 -> V_517 = 0 ;
F_191 ( V_2 ) ;
F_7 ( V_2 , V_512 ) ;
if ( V_294 -> V_392 && V_2 -> V_343 )
F_169 ( V_2 , V_2 -> V_343 , false , NULL ) ;
F_112 ( V_2 , false , NULL ) ;
if ( ! F_49 ( & V_2 -> V_72 -> V_73 , V_518 ) )
F_202 ( V_2 , V_294 ) ;
F_201 ( V_2 , V_294 ) ;
if ( F_49 ( & V_2 -> V_72 -> V_73 , V_518 ) )
F_202 ( V_2 , V_294 ) ;
F_143 ( V_2 , V_294 ) ;
F_138 ( V_2 ) ;
F_145 ( V_2 , V_294 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_206 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
struct V_480 * V_410 ,
T_1 V_481 )
{
struct V_138 * V_329 = F_95 ( V_294 ) ;
if ( ! V_329 -> V_510 )
return;
if ( V_481 & ( V_519 | V_520 |
V_521 | V_499 ) &&
F_169 ( V_2 , V_294 , false , NULL ) )
F_113 ( V_2 , L_25 , V_294 -> V_164 ) ;
if ( V_481 & V_522 &&
F_197 ( V_2 , V_294 ) )
F_207 ( V_2 , L_36 ) ;
if ( V_481 & V_500 ) {
F_195 ( V_2 , L_32 ,
V_410 -> V_501 ) ;
F_128 ( V_2 , V_294 , V_410 -> V_501 ) ;
}
}
static void F_208 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_480 * V_410 ,
T_1 V_481 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_523 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_481 & V_524 && ! V_410 -> V_525 )
F_209 ( V_2 , V_526 , true ) ;
switch ( V_294 -> type ) {
case V_121 :
F_182 ( V_2 , V_294 , V_410 , V_481 ) ;
break;
case V_143 :
case V_146 :
F_206 ( V_2 , V_294 , V_410 , V_481 ) ;
break;
case V_527 :
if ( V_481 & V_492 )
F_176 ( V_2 , V_294 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_523 ) ;
}
static int F_210 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_528 * V_529 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_529 -> V_530 . V_38 == 0 ||
V_529 -> V_530 . V_38 > V_2 -> V_72 -> V_73 . V_531 )
return - V_327 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_211 ( V_2 , V_294 , & V_529 -> V_530 , & V_529 -> V_532 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_212 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_340 & V_533 )
F_209 ( V_2 , V_533 , true ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_213 ( struct V_29 * V_30 ,
struct V_263 * V_264 , V_140 V_534 ,
int V_535 ,
enum V_536 V_537 ,
bool V_538 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_214 ( V_2 , V_264 , V_537 , V_535 ,
V_534 , V_538 , false ) ;
}
static void
F_215 ( struct V_29 * V_30 ,
struct V_263 * V_264 , V_140 V_534 ,
int V_535 ,
enum V_536 V_537 ,
bool V_538 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_214 ( V_2 , V_264 , V_537 , V_535 ,
V_534 , V_538 , true ) ;
}
static void F_216 ( struct V_29 * V_30 ,
enum V_539 V_371 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_267 = F_62 ( V_264 ) ;
unsigned long V_540 = 0 , V_534 = 0 ;
int V_295 ;
F_4 ( & V_267 -> V_541 ) ;
for ( V_295 = 0 ; V_295 < V_542 ; V_295 ++ ) {
struct V_305 * V_306 = & V_267 -> V_306 [ V_295 ] ;
if ( ! F_41 ( V_2 ) &&
V_306 -> V_543 != V_544 &&
V_306 -> V_543 != V_545 )
continue;
if ( V_306 -> V_546 == V_547 )
continue;
F_217 ( V_306 -> V_546 , & V_540 ) ;
if ( F_218 ( V_306 ) == 0 )
continue;
F_217 ( V_295 , & V_534 ) ;
}
switch ( V_371 ) {
case V_548 :
if ( F_219 ( & V_2 -> V_549 [ V_267 -> V_270 ] ) > 0 )
F_220 ( V_30 , V_264 , true ) ;
F_221 (tid, &tids, IWL_MAX_TID_COUNT)
F_222 ( V_264 , V_295 , true ) ;
if ( V_540 )
F_223 ( V_2 -> V_7 , V_540 , true ) ;
break;
case V_550 :
if ( F_8 ( V_267 -> V_270 == V_271 ) )
break;
if ( V_540 )
F_223 ( V_2 -> V_7 , V_540 , false ) ;
F_224 ( V_2 , V_264 ) ;
break;
default:
break;
}
F_5 ( & V_267 -> V_541 ) ;
}
static void F_225 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
enum V_539 V_371 ,
struct V_263 * V_264 )
{
F_216 ( V_30 , V_371 , V_264 ) ;
}
void F_226 ( struct V_1 * V_2 , struct V_476 * V_477 )
{
struct V_478 * V_479 = F_181 ( V_477 ) ;
struct V_551 * V_475 = ( void * ) V_479 -> V_281 ;
struct V_263 * V_264 ;
struct V_136 * V_267 ;
bool V_552 = ( V_475 -> type != V_553 ) ;
if ( F_8 ( V_475 -> V_270 >= F_43 ( V_2 -> V_554 ) ) )
return;
F_227 () ;
V_264 = F_228 ( V_2 -> V_554 [ V_475 -> V_270 ] ) ;
if ( F_8 ( F_23 ( V_264 ) ) ) {
F_229 () ;
return;
}
V_267 = F_62 ( V_264 ) ;
if ( ! V_267 -> V_294 ||
V_267 -> V_294 -> type != V_143 ) {
F_229 () ;
return;
}
if ( V_267 -> V_552 != V_552 ) {
V_267 -> V_552 = V_552 ;
F_216 ( V_2 -> V_30 ,
V_552 ? V_548 : V_550 ,
V_264 ) ;
F_230 ( V_264 , V_552 ) ;
}
if ( V_552 ) {
switch ( V_475 -> type ) {
case V_553 :
case V_555 :
break;
case V_556 :
F_231 ( V_264 , V_557 ) ;
break;
case V_558 :
F_232 ( V_264 ) ;
break;
default:
break;
}
}
F_229 () ;
}
static void F_233 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_559 = F_62 ( V_264 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_264 == F_204 ( V_2 -> V_554 [ V_559 -> V_270 ] ) )
F_234 ( V_2 -> V_554 [ V_559 -> V_270 ] ,
F_235 ( - V_49 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_236 ( struct V_1 * V_2 , struct V_293 * V_294 ,
const T_2 * V_412 )
{
if ( ! ( V_2 -> V_72 -> V_73 . V_147 & V_560 ) )
return;
if ( V_294 -> V_392 && ! F_237 ( V_2 ) ) {
V_294 -> V_393 &= ~ V_561 ;
return;
}
if ( ! V_294 -> V_392 &&
( V_108 . V_562 & V_563 ) ) {
V_294 -> V_393 &= ~ V_561 ;
return;
}
V_294 -> V_393 |= V_561 ;
}
static void
F_238 ( struct V_1 * V_2 ,
struct V_293 * V_294 , T_2 * V_564 ,
enum V_565 V_298 )
{
struct V_299 * V_300 ;
struct V_566 * V_567 ;
if ( ! F_81 ( V_2 -> V_72 , V_568 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_568 ) ;
V_567 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
if ( ! ( V_567 -> V_569 & F_45 ( V_298 ) ) )
return;
if ( V_567 -> V_570 &&
memcmp ( V_567 -> V_571 , V_564 , V_167 ) != 0 )
return;
F_239 ( V_2 , V_300 ,
L_37 ,
V_564 , V_298 ) ;
}
static void F_240 ( struct V_1 * V_2 ,
struct V_136 * V_559 )
{
struct V_305 * V_306 ;
struct V_265 * V_266 ;
int V_9 ;
F_4 ( & V_559 -> V_541 ) ;
for ( V_9 = 0 ; V_9 <= V_542 ; V_9 ++ ) {
V_306 = & V_559 -> V_306 [ V_9 ] ;
while ( ( V_266 = F_241 ( & V_306 -> V_572 ) ) )
F_77 ( V_2 -> V_30 , V_266 ) ;
}
F_5 ( & V_559 -> V_541 ) ;
}
static int F_242 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_263 * V_264 ,
enum V_573 V_574 ,
enum V_573 V_575 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_136 * V_559 = F_62 ( V_264 ) ;
int V_47 ;
F_166 ( V_2 , L_38 ,
V_264 -> V_164 , V_574 , V_575 ) ;
if ( F_15 ( ! V_329 -> V_334 ) )
return - V_327 ;
F_120 ( & V_2 -> V_401 ) ;
if ( V_574 == V_576 &&
V_575 == V_577 &&
F_41 ( V_2 ) ) {
F_240 ( V_2 , V_559 ) ;
F_120 ( & V_2 -> V_364 ) ;
}
F_87 ( & V_2 -> V_33 ) ;
V_559 -> V_486 = V_575 >= V_578 ;
if ( V_574 == V_577 &&
V_575 == V_576 ) {
if ( V_294 -> type == V_121 &&
V_294 -> V_410 . V_488 < 16 ) {
F_113 ( V_2 ,
L_39 ,
V_264 -> V_164 , V_294 -> V_410 . V_488 ) ;
V_47 = - V_327 ;
goto V_386;
}
if ( V_264 -> V_579 &&
( V_294 -> V_392 ||
F_243 ( V_2 , NULL ) ==
V_580 ||
F_200 ( V_2 ) > 1 ) ) {
F_166 ( V_2 , L_40 ) ;
V_47 = - V_581 ;
goto V_386;
}
V_47 = F_244 ( V_2 , V_294 , V_264 ) ;
if ( V_264 -> V_579 && V_47 == 0 ) {
F_245 ( V_2 , V_294 , true ) ;
F_238 ( V_2 , V_294 , V_264 -> V_164 ,
V_582 ) ;
}
} else if ( V_574 == V_576 &&
V_575 == V_583 ) {
V_2 -> V_584 = true ;
F_236 ( V_2 , V_294 , V_264 -> V_164 ) ;
V_47 = 0 ;
} else if ( V_574 == V_583 &&
V_575 == V_578 ) {
if ( V_294 -> type == V_143 ) {
V_329 -> V_507 ++ ;
F_169 ( V_2 , V_294 , false , NULL ) ;
}
F_246 ( V_2 , V_264 , V_329 -> V_334 -> V_585 -> V_586 ,
true ) ;
V_47 = F_247 ( V_2 , V_294 , V_264 ) ;
} else if ( V_574 == V_578 &&
V_575 == V_587 ) {
if ( F_200 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
if ( V_264 -> V_579 )
F_238 ( V_2 , V_294 , V_264 -> V_164 ,
V_588 ) ;
F_8 ( F_194 ( V_2 , V_294 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_574 == V_587 &&
V_575 == V_578 ) {
F_8 ( F_139 ( V_2 , V_294 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_574 == V_578 &&
V_575 == V_583 ) {
if ( V_294 -> type == V_143 ) {
V_329 -> V_507 -- ;
F_169 ( V_2 , V_294 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_574 == V_583 &&
V_575 == V_576 ) {
V_47 = 0 ;
} else if ( V_574 == V_576 &&
V_575 == V_577 ) {
V_47 = F_248 ( V_2 , V_294 , V_264 ) ;
if ( V_264 -> V_579 ) {
F_245 ( V_2 , V_294 , false ) ;
F_238 ( V_2 , V_294 , V_264 -> V_164 ,
V_589 ) ;
}
} else {
V_47 = - V_17 ;
}
V_386:
F_93 ( & V_2 -> V_33 ) ;
if ( V_264 -> V_579 && V_47 == 0 ) {
if ( V_574 == V_577 &&
V_575 == V_576 )
F_249 ( V_264 , V_590 ) ;
else if ( V_574 == V_576 &&
V_575 == V_577 )
F_250 ( V_264 , V_590 ) ;
}
return V_47 ;
}
static int F_251 ( struct V_29 * V_30 , T_1 V_591 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_224 = V_591 ;
return 0 ;
}
static void F_252 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_263 * V_264 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_294 -> type == V_121 &&
V_27 & V_592 )
F_187 ( V_2 , V_294 , false ) ;
}
static int F_253 ( struct V_29 * V_30 ,
struct V_293 * V_294 , V_140 V_593 ,
const struct V_594 * V_316 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
V_329 -> V_595 [ V_593 ] = * V_316 ;
if ( V_294 -> type == V_145 ) {
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_169 ( V_2 , V_294 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_254 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_596 = V_597 ;
T_1 V_598 = V_599 ;
if ( F_15 ( V_294 -> V_410 . V_411 ) )
return;
if ( F_12 ( V_2 , V_600 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_186 ( V_2 , V_294 , V_596 , V_598 , 500 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_600 ) ;
}
static int F_255 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_601 * V_530 ,
struct V_602 * V_532 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! V_294 -> V_410 . V_525 ) {
V_47 = - V_581 ;
goto V_34;
}
V_47 = F_256 ( V_2 , V_294 , V_530 , V_532 , V_526 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_257 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_340 & V_526 ) ) {
F_93 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_209 ( V_2 , V_526 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_258 ( V_2 ) ;
return V_47 ;
}
static int F_259 ( struct V_29 * V_30 ,
enum V_603 V_371 ,
struct V_293 * V_294 ,
struct V_263 * V_264 ,
struct V_604 * V_605 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_267 ;
struct V_606 * V_607 ;
int V_608 = V_605 -> V_608 ;
int V_47 ;
T_2 V_609 ;
if ( V_108 . V_109 ) {
F_166 ( V_2 , L_41 ) ;
return - V_610 ;
}
switch ( V_605 -> V_115 ) {
case V_54 :
V_605 -> V_147 |= V_611 ;
V_605 -> V_147 |= V_612 ;
break;
case V_55 :
case V_106 :
case V_107 :
V_605 -> V_147 |= V_612 ;
break;
case V_111 :
case V_112 :
case V_113 :
F_15 ( ! F_260 ( V_30 , V_110 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_294 -> type != V_121 )
return 0 ;
break;
default:
if ( V_30 -> V_119 &&
V_30 -> V_129 -> V_115 == V_605 -> V_115 )
V_605 -> V_147 |= V_612 ;
else
return - V_610 ;
}
F_87 ( & V_2 -> V_33 ) ;
switch ( V_371 ) {
case V_613 :
if ( ( V_294 -> type == V_146 ||
V_294 -> type == V_143 ) && ! V_264 ) {
if ( V_605 -> V_115 == V_111 ||
V_605 -> V_115 == V_112 ||
V_605 -> V_115 == V_113 )
V_47 = - V_610 ;
else
V_47 = 0 ;
V_605 -> V_614 = V_615 ;
break;
}
if ( F_14 ( V_354 , & V_2 -> V_15 ) &&
V_605 -> V_614 == V_615 ) {
F_166 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_354 , & V_2 -> V_15 ) &&
V_264 && F_39 ( V_2 ) &&
V_605 -> V_147 & V_616 &&
( V_605 -> V_115 == V_55 ||
V_605 -> V_115 == V_106 ||
V_605 -> V_115 == V_107 ) ) {
struct V_617 V_618 ;
int V_295 , V_619 ;
V_267 = F_62 ( V_264 ) ;
F_8 ( F_204 ( V_267 -> V_607 [ V_608 ] ) ) ;
V_607 = F_164 ( sizeof( * V_607 ) +
V_2 -> V_7 -> V_76 *
sizeof( V_607 -> V_619 [ 0 ] ) ,
V_620 ) ;
if ( ! V_607 ) {
V_47 = - V_621 ;
break;
}
for ( V_295 = 0 ; V_295 < V_542 ; V_295 ++ ) {
F_261 ( V_605 , V_295 , & V_618 ) ;
for ( V_619 = 0 ; V_619 < V_2 -> V_7 -> V_76 ; V_619 ++ )
memcpy ( V_607 -> V_619 [ V_619 ] . V_622 [ V_295 ] ,
V_618 . V_623 . V_622 ,
V_624 ) ;
}
F_234 ( V_267 -> V_607 [ V_608 ] , V_607 ) ;
}
if ( F_14 ( V_354 , & V_2 -> V_15 ) )
V_609 = V_605 -> V_614 ;
else
V_609 = V_615 ;
F_166 ( V_2 , L_43 ) ;
V_47 = F_262 ( V_2 , V_294 , V_264 , V_605 , V_609 ) ;
if ( V_47 ) {
F_207 ( V_2 , L_44 ) ;
V_605 -> V_614 = V_615 ;
V_47 = 0 ;
}
break;
case V_625 :
if ( V_605 -> V_614 == V_615 ) {
V_47 = 0 ;
break;
}
if ( V_264 && F_39 ( V_2 ) &&
V_605 -> V_147 & V_616 &&
( V_605 -> V_115 == V_55 ||
V_605 -> V_115 == V_106 ||
V_605 -> V_115 == V_107 ) ) {
V_267 = F_62 ( V_264 ) ;
V_607 = F_263 (
V_267 -> V_607 [ V_608 ] ,
F_264 ( & V_2 -> V_33 ) ) ;
F_205 ( V_267 -> V_607 [ V_608 ] , NULL ) ;
if ( V_607 )
F_265 ( V_607 , V_626 ) ;
}
F_166 ( V_2 , L_45 ) ;
V_47 = F_266 ( V_2 , V_294 , V_264 , V_605 ) ;
break;
default:
V_47 = - V_327 ;
}
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_267 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_604 * V_627 ,
struct V_263 * V_264 ,
T_1 V_628 , V_140 * V_629 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_627 -> V_614 == V_615 )
return;
F_268 ( V_2 , V_294 , V_627 , V_264 , V_628 , V_629 ) ;
}
static bool F_269 ( struct V_630 * V_631 ,
struct V_478 * V_479 , void * V_281 )
{
struct V_1 * V_2 =
F_270 ( V_631 , struct V_1 , V_631 ) ;
struct V_632 * V_32 ;
int V_633 = F_271 ( V_479 ) ;
struct V_634 * V_635 = V_281 ;
if ( F_8 ( V_479 -> V_280 . V_371 != V_636 ) )
return true ;
if ( F_15 ( V_633 != sizeof( * V_32 ) ) ) {
F_113 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_479 -> V_281 ;
F_272 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_637 ) ;
V_635 -> V_638 = F_44 ( V_32 -> V_637 ) ;
F_272 ( V_2 , L_48 ,
V_635 -> V_638 ) ;
F_4 ( & V_2 -> V_332 ) ;
F_273 ( & V_635 -> V_639 , & V_2 -> V_640 ) ;
F_5 ( & V_2 -> V_332 ) ;
return true ;
}
static int F_274 ( struct V_1 * V_2 ,
struct V_641 * V_585 ,
struct V_293 * V_294 ,
int V_596 )
{
int V_642 , V_643 = V_644 ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_634 * V_635 = & V_329 -> V_645 ;
static const V_140 V_646 [] = { V_636 } ;
struct V_647 V_648 ;
T_1 V_649 = V_294 -> V_410 . V_650 *
V_294 -> V_410 . V_488 ;
T_1 V_651 , V_652 ;
struct V_653 V_654 = {
. V_298 = F_129 ( V_655 ) ,
. V_656 =
F_129 ( F_275 ( V_657 , 0 ) ) ,
. V_658 = F_129 ( V_2 -> V_659 . V_270 ) ,
. V_660 . V_586 = ( V_585 -> V_586 == V_181 ) ?
V_661 : V_662 ,
. V_660 . V_585 = V_585 -> V_663 ,
. V_660 . V_664 = V_665 ,
. V_666 = F_129 ( F_276 ( V_2 -> V_7 , V_643 ) ) ,
} ;
V_652 = V_667 ;
V_651 = F_277 ( V_596 ) ;
if ( V_294 -> V_410 . V_411 ) {
V_652 = F_278 ( T_1 , V_649 * 3 , V_668 ) ;
if ( V_649 <= V_651 ) {
V_651 = V_649 - V_669 ;
if ( V_651 <= V_670 )
V_651 = V_649 -
V_671 ;
}
}
V_654 . V_596 = F_129 ( V_651 ) ;
V_654 . V_672 = F_129 ( V_652 ) ;
F_272 ( V_2 ,
L_49 ,
V_585 -> V_663 , V_651 , V_596 , V_652 ,
V_649 ) ;
memcpy ( V_654 . V_673 , V_294 -> V_164 , V_167 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_332 ) ;
if ( F_8 ( V_635 -> V_20 == V_636 ) ) {
F_5 ( & V_2 -> V_332 ) ;
return - V_17 ;
}
V_635 -> V_294 = V_294 ;
V_635 -> V_596 = V_596 ;
V_635 -> V_20 = V_636 ;
F_5 ( & V_2 -> V_332 ) ;
F_279 ( & V_2 -> V_631 , & V_648 ,
V_646 ,
F_43 ( V_646 ) ,
F_269 , V_635 ) ;
V_642 = F_131 ( V_2 , V_636 , 0 , sizeof( V_654 ) ,
& V_654 ) ;
if ( V_642 ) {
F_113 ( V_2 , L_50 , V_642 ) ;
F_280 ( & V_2 -> V_631 , & V_648 ) ;
goto V_674;
}
V_642 = F_281 ( & V_2 -> V_631 , & V_648 , 1 ) ;
F_15 ( V_642 ) ;
if ( V_642 ) {
V_674:
F_4 ( & V_2 -> V_332 ) ;
F_96 ( V_2 , V_635 ) ;
F_5 ( & V_2 -> V_332 ) ;
}
return V_642 ;
}
static int F_282 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_641 * V_585 ,
int V_596 ,
enum V_675 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_676 V_677 ;
struct V_368 * V_334 ;
int V_47 , V_9 ;
F_166 ( V_2 , L_51 , V_585 -> V_663 ,
V_596 , type ) ;
F_120 ( & V_2 -> V_360 ) ;
F_87 ( & V_2 -> V_33 ) ;
switch ( V_294 -> type ) {
case V_121 :
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_678 ) ) {
V_47 = F_274 ( V_2 , V_585 ,
V_294 , V_596 ) ;
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
if ( V_334 -> V_21 && V_585 == V_334 -> V_585 ) {
V_47 = F_143 ( V_2 , V_294 ) ;
if ( F_283 ( V_47 , L_54 ) )
goto V_386;
F_144 ( V_2 , V_329 -> V_334 ) ;
V_329 -> V_334 = V_334 ;
V_47 = F_141 ( V_2 , V_294 ) ;
if ( F_283 ( V_47 , L_55 ) )
goto V_386;
F_140 ( V_2 , V_329 -> V_334 ) ;
goto V_679;
}
}
if ( V_585 == V_329 -> V_334 -> V_585 )
goto V_679;
F_284 ( & V_677 , V_585 , V_680 ) ;
if ( V_329 -> V_334 -> V_21 == 1 ) {
V_47 = F_285 ( V_2 , V_329 -> V_334 ,
& V_677 , 1 , 1 ) ;
if ( V_47 )
goto V_386;
} else {
V_334 = F_127 ( V_2 ) ;
if ( ! V_334 ) {
V_47 = - V_396 ;
goto V_386;
}
V_47 = F_285 ( V_2 , V_334 , & V_677 ,
1 , 1 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_56 ) ;
goto V_386;
}
V_47 = F_143 ( V_2 , V_294 ) ;
if ( F_283 ( V_47 , L_54 ) )
goto V_386;
F_144 ( V_2 , V_329 -> V_334 ) ;
V_329 -> V_334 = V_334 ;
V_47 = F_141 ( V_2 , V_294 ) ;
if ( F_283 ( V_47 , L_55 ) )
goto V_386;
F_140 ( V_2 , V_329 -> V_334 ) ;
}
V_679:
V_47 = F_286 ( V_2 , V_294 , V_596 , type ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
F_166 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_287 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_166 ( V_2 , L_58 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_288 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_166 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_289 ( struct V_1 * V_2 ,
struct V_681 * V_682 )
{
V_140 * V_683 = ( V_140 * ) V_682 -> V_684 ;
struct V_368 * V_334 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_166 ( V_2 , L_59 ) ;
V_334 = F_127 ( V_2 ) ;
if ( ! V_334 ) {
V_47 = - V_396 ;
goto V_34;
}
V_47 = F_285 ( V_2 , V_334 , & V_682 -> V_685 ,
V_682 -> V_686 ,
V_682 -> V_687 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_60 ) ;
goto V_34;
}
F_140 ( V_2 , V_334 ) ;
* V_683 = V_334 -> V_20 ;
V_34:
return V_47 ;
}
static int F_290 ( struct V_29 * V_30 ,
struct V_681 * V_682 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_289 ( V_2 , V_682 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_291 ( struct V_1 * V_2 ,
struct V_681 * V_682 )
{
V_140 * V_683 = ( V_140 * ) V_682 -> V_684 ;
struct V_368 * V_334 = & V_2 -> V_18 [ * V_683 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_144 ( V_2 , V_334 ) ;
}
static void F_292 ( struct V_29 * V_30 ,
struct V_681 * V_682 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_291 ( V_2 , V_682 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_293 ( struct V_29 * V_30 ,
struct V_681 * V_682 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_140 * V_683 = ( V_140 * ) V_682 -> V_684 ;
struct V_368 * V_334 = & V_2 -> V_18 [ * V_683 ] ;
if ( F_117 ( ( V_334 -> V_21 > 1 ) &&
( V_27 & ~ ( V_688 |
V_689 |
V_690 |
V_691 ) ) ,
L_61 ,
V_334 -> V_21 , V_27 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_191 ( V_2 ) ;
F_285 ( V_2 , V_334 , & V_682 -> V_685 ,
V_682 -> V_686 ,
V_682 -> V_687 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_294 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
struct V_681 * V_682 ,
bool V_692 )
{
V_140 * V_683 = ( V_140 * ) V_682 -> V_684 ;
struct V_368 * V_334 = & V_2 -> V_18 [ * V_683 ] ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_329 -> V_334 = V_334 ;
switch ( V_294 -> type ) {
case V_143 :
if ( V_692 ) {
V_329 -> V_510 = true ;
break;
}
case V_146 :
V_47 = 0 ;
goto V_34;
case V_121 :
break;
case V_527 :
V_329 -> V_341 = true ;
break;
default:
V_47 = - V_327 ;
goto V_34;
}
V_47 = F_141 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_34;
F_138 ( V_2 ) ;
if ( V_294 -> type == V_527 ) {
V_329 -> V_693 = true ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_694;
V_47 = F_295 ( V_2 , V_294 ) ;
if ( V_47 )
goto V_694;
}
if ( V_294 -> type == V_143 ) {
F_112 ( V_2 , false , NULL ) ;
F_169 ( V_2 , V_294 , false , NULL ) ;
}
if ( V_692 && V_294 -> type == V_121 ) {
T_1 V_596 = 2 * V_294 -> V_410 . V_488 ;
V_47 = F_12 ( V_2 , V_695 ) ;
if ( V_47 )
goto V_694;
F_186 ( V_2 , V_294 , V_596 , V_596 ,
V_294 -> V_410 . V_488 / 2 ,
true ) ;
F_7 ( V_2 , V_695 ) ;
F_112 ( V_2 , false , NULL ) ;
}
goto V_34;
V_694:
F_143 ( V_2 , V_294 ) ;
F_138 ( V_2 ) ;
V_34:
if ( V_47 )
V_329 -> V_334 = NULL ;
return V_47 ;
}
static int F_296 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_681 * V_682 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_294 ( V_2 , V_294 , V_682 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_297 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
struct V_681 * V_682 ,
bool V_692 )
{
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_293 * V_696 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_193 ( V_2 , V_329 , & V_329 -> V_333 ) ;
switch ( V_294 -> type ) {
case V_146 :
goto V_34;
case V_527 :
V_329 -> V_693 = false ;
V_329 -> V_341 = false ;
F_298 ( V_2 , V_294 ) ;
break;
case V_143 :
if ( ! V_692 || ! V_329 -> V_510 )
goto V_34;
V_329 -> V_514 = false ;
F_299 ( V_2 , V_329 , true ) ;
F_234 ( V_2 -> V_515 , V_294 ) ;
V_329 -> V_510 = false ;
break;
case V_121 :
if ( ! V_692 )
break;
V_696 = V_294 ;
F_169 ( V_2 , V_294 , true , NULL ) ;
break;
default:
break;
}
F_112 ( V_2 , false , V_696 ) ;
F_143 ( V_2 , V_294 ) ;
V_34:
V_329 -> V_334 = NULL ;
F_138 ( V_2 ) ;
}
static void F_300 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_681 * V_682 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_297 ( V_2 , V_294 , V_682 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int
F_301 ( struct V_1 * V_2 ,
struct V_697 * V_698 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_297 ( V_2 , V_698 [ 0 ] . V_294 , V_698 [ 0 ] . V_699 , true ) ;
F_291 ( V_2 , V_698 [ 0 ] . V_699 ) ;
V_47 = F_289 ( V_2 , V_698 [ 0 ] . V_700 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_62 ) ;
goto V_701;
}
V_47 = F_294 ( V_2 , V_698 [ 0 ] . V_294 , V_698 [ 0 ] . V_700 ,
true ) ;
if ( V_47 ) {
F_113 ( V_2 ,
L_63 ) ;
goto V_508;
}
if ( F_200 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
goto V_34;
V_508:
F_291 ( V_2 , V_698 [ 0 ] . V_700 ) ;
V_701:
if ( F_289 ( V_2 , V_698 [ 0 ] . V_699 ) ) {
F_113 ( V_2 , L_64 ) ;
goto V_702;
}
if ( F_294 ( V_2 , V_698 [ 0 ] . V_294 , V_698 [ 0 ] . V_699 ,
true ) ) {
F_113 ( V_2 , L_65 ) ;
goto V_702;
}
goto V_34;
V_702:
F_302 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_303 ( struct V_1 * V_2 ,
struct V_697 * V_698 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_297 ( V_2 , V_698 [ 0 ] . V_294 , V_698 [ 0 ] . V_699 , true ) ;
V_47 = F_294 ( V_2 , V_698 [ 0 ] . V_294 , V_698 [ 0 ] . V_700 ,
true ) ;
if ( V_47 ) {
F_113 ( V_2 ,
L_63 ) ;
goto V_701;
}
goto V_34;
V_701:
if ( F_294 ( V_2 , V_698 [ 0 ] . V_294 , V_698 [ 0 ] . V_699 ,
true ) ) {
F_113 ( V_2 , L_65 ) ;
goto V_702;
}
goto V_34;
V_702:
F_302 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_304 ( struct V_29 * V_30 ,
struct V_697 * V_698 ,
int V_703 ,
enum V_704 V_705 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_703 > 1 )
return - V_610 ;
switch ( V_705 ) {
case V_706 :
V_47 = F_301 ( V_2 , V_698 ) ;
break;
case V_707 :
V_47 = F_303 ( V_2 , V_698 ) ;
break;
default:
V_47 = - V_610 ;
break;
}
return V_47 ;
}
static int F_305 ( struct V_29 * V_30 ,
struct V_263 * V_264 ,
bool V_708 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_559 = F_62 ( V_264 ) ;
if ( ! V_559 || ! V_559 -> V_294 ) {
F_113 ( V_2 , L_66 ) ;
return - V_327 ;
}
return F_197 ( V_2 , V_559 -> V_294 ) ;
}
static int F_306 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
void * V_281 , int V_377 )
{
struct V_709 * V_710 [ V_711 + 1 ] ;
int V_712 ;
T_1 V_403 ;
V_712 = F_307 ( V_710 , V_711 , V_281 , V_377 , V_713 ,
NULL ) ;
if ( V_712 )
return V_712 ;
if ( ! V_710 [ V_714 ] )
return - V_327 ;
switch ( F_308 ( V_710 [ V_714 ] ) ) {
case V_715 :
if ( ! V_294 || V_294 -> type != V_143 || ! V_294 -> V_392 ||
! V_294 -> V_410 . V_716 ||
! V_710 [ V_717 ] )
return - V_327 ;
V_403 = F_308 ( V_710 [ V_717 ] ) ;
if ( V_403 >= V_294 -> V_410 . V_488 )
return - V_327 ;
V_2 -> V_403 = V_403 ;
V_2 -> V_402 = V_294 ;
return F_112 ( V_2 , false , NULL ) ;
case V_718 :
if ( ! V_294 || V_294 -> type != V_121 ||
! V_294 -> V_410 . V_411 || ! V_294 -> V_410 . V_650 ||
! V_710 [ V_719 ] )
return - V_327 ;
if ( F_308 ( V_710 [ V_719 ] ) )
return F_194 ( V_2 , V_294 , 0 ) ;
return F_139 ( V_2 , V_294 , 0 ) ;
}
return - V_610 ;
}
static int F_309 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
void * V_281 , int V_377 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_712 ;
F_87 ( & V_2 -> V_33 ) ;
V_712 = F_306 ( V_2 , V_294 , V_281 , V_377 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_712 ;
}
static void F_310 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_720 * V_721 )
{
F_166 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_311 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_720 * V_721 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_293 * V_513 ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
T_1 V_666 ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_329 -> V_722 = false ;
F_166 ( V_2 , L_68 ,
V_721 -> V_677 . V_723 ) ;
F_312 ( V_2 , V_294 , V_724 ) ;
switch ( V_294 -> type ) {
case V_143 :
V_513 =
F_263 ( V_2 -> V_513 ,
F_264 ( & V_2 -> V_33 ) ) ;
if ( F_117 ( V_513 && V_513 -> V_725 ,
L_69 ) ) {
V_47 = - V_581 ;
goto V_386;
}
if ( F_263 ( V_2 -> V_515 ,
F_264 ( & V_2 -> V_33 ) ) ) {
V_47 = - V_581 ;
goto V_386;
}
F_234 ( V_2 -> V_513 , V_294 ) ;
if ( F_117 ( V_329 -> V_514 ,
L_70 ) ) {
V_47 = - V_581 ;
goto V_386;
}
V_329 -> V_726 = V_721 -> V_677 . V_727 -> V_728 ;
break;
case V_121 :
if ( V_329 -> V_483 )
F_184 ( V_294 ,
V_484 ,
0 , 0 ) ;
V_666 = V_721 -> V_729 +
( ( V_294 -> V_410 . V_488 * ( V_721 -> V_413 - 1 ) -
V_730 ) * 1024 ) ;
if ( V_721 -> V_731 )
F_313 ( V_2 , V_294 ) ;
F_314 ( V_2 , V_294 , V_294 -> V_410 . V_488 ,
V_666 ) ;
if ( V_329 -> V_335 . V_504 ) {
V_47 = F_139 ( V_2 , V_294 , 0 ) ;
if ( V_47 )
goto V_386;
}
break;
default:
break;
}
V_329 -> V_341 = true ;
V_47 = F_315 ( V_2 ) ;
if ( V_47 )
goto V_386;
F_114 ( V_2 ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_316 ( struct V_29 * V_30 ,
struct V_293 * V_294 )
{
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_329 -> V_722 ) {
V_329 -> V_722 = false ;
V_47 = - V_17 ;
goto V_386;
}
if ( V_294 -> type == V_121 ) {
struct V_136 * V_267 ;
V_267 = F_317 ( V_2 ,
V_329 -> V_331 ) ;
if ( F_8 ( ! V_267 ) ) {
V_47 = - V_17 ;
goto V_386;
}
F_318 ( V_2 , V_267 , false ) ;
F_169 ( V_2 , V_294 , false , NULL ) ;
V_47 = F_194 ( V_2 , V_294 , 0 ) ;
if ( V_47 )
goto V_386;
F_319 ( V_2 , V_294 ) ;
}
V_329 -> V_341 = false ;
V_47 = F_315 ( V_2 ) ;
V_386:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_320 ( struct V_29 * V_30 ,
struct V_293 * V_294 , T_1 V_82 , bool V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 ;
struct V_136 * V_267 ;
struct V_263 * V_264 ;
int V_9 ;
T_1 V_732 = 0 ;
if ( ! V_294 || V_294 -> type != V_121 )
return;
if ( F_41 ( V_2 ) )
F_120 ( & V_2 -> V_364 ) ;
F_87 ( & V_2 -> V_33 ) ;
V_329 = F_95 ( V_294 ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_2 -> V_554 ) ; V_9 ++ ) {
V_264 = F_263 ( V_2 -> V_554 [ V_9 ] ,
F_264 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_264 ) )
continue;
V_267 = F_62 ( V_264 ) ;
if ( V_267 -> V_294 != V_294 )
continue;
F_8 ( V_9 != V_329 -> V_331 && ! V_264 -> V_579 ) ;
V_732 |= V_267 -> V_733 ;
}
if ( V_282 ) {
if ( F_149 ( V_2 , V_732 , 0 ) )
F_113 ( V_2 , L_71 ) ;
F_93 ( & V_2 -> V_33 ) ;
} else {
F_93 ( & V_2 -> V_33 ) ;
F_150 ( V_2 -> V_7 , V_732 ) ;
}
}
static int F_321 ( struct V_29 * V_30 , int V_734 ,
struct V_735 * V_736 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_736 , 0 , sizeof( * V_736 ) ) ;
if ( V_734 != 0 )
return - V_49 ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_737 ) )
return - V_49 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_738 ) {
V_47 = F_185 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_736 -> V_739 = V_740 |
V_741 |
V_742 |
V_743 ;
V_736 -> time = V_2 -> V_359 . V_744 +
V_2 -> V_745 . V_744 ;
F_322 ( V_736 -> time , V_746 ) ;
V_736 -> V_747 = V_2 -> V_359 . V_748 +
V_2 -> V_745 . V_748 ;
F_322 ( V_736 -> V_747 , V_746 ) ;
V_736 -> V_749 = V_2 -> V_359 . V_750 +
V_2 -> V_745 . V_750 ;
F_322 ( V_736 -> V_749 , V_746 ) ;
V_736 -> V_751 = V_2 -> V_359 . V_752 +
V_2 -> V_745 . V_752 ;
F_322 ( V_736 -> V_751 , V_746 ) ;
V_47 = 0 ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_323 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
struct V_263 * V_264 ,
struct V_753 * V_754 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_329 = F_95 ( V_294 ) ;
struct V_136 * V_267 = F_62 ( V_264 ) ;
if ( V_267 -> V_755 ) {
V_754 -> V_756 = V_267 -> V_755 ;
V_754 -> V_739 |= F_45 ( V_757 ) ;
}
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_737 ) )
return;
if ( ! ( V_294 -> V_393 & V_394 ) )
return;
if ( ! V_294 -> V_410 . V_411 )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_329 -> V_331 != V_267 -> V_270 )
goto V_758;
if ( F_185 ( V_2 , false ) )
goto V_758;
V_754 -> V_759 = V_329 -> V_383 . V_385 +
V_329 -> V_383 . V_384 ;
V_754 -> V_739 |= F_45 ( V_760 ) ;
if ( V_329 -> V_383 . V_761 ) {
V_754 -> V_762 = V_329 -> V_383 . V_761 ;
V_754 -> V_739 |= F_45 ( V_763 ) ;
}
V_758:
F_93 ( & V_2 -> V_33 ) ;
}
static void F_324 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
const struct V_764 * V_765 )
{
#define F_325 ( T_5 , T_6 , T_7 , T_8 , T_9 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_299 * V_300 ;
struct V_766 * V_767 ;
if ( ! F_81 ( V_2 -> V_72 , V_768 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_768 ) ;
V_767 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
if ( V_765 -> V_769 . V_770 . V_281 == V_771 ) {
if ( V_765 -> V_769 . V_770 . V_15 == V_772 )
F_325 ( V_2 , V_300 , V_773 ,
V_767 -> V_774 ,
L_72 ,
V_765 -> V_769 . V_770 . V_537 ) ;
else if ( V_765 -> V_769 . V_770 . V_15 == V_775 )
F_325 ( V_2 , V_300 , V_773 ,
V_767 -> V_776 ,
L_73 ) ;
} else if ( V_765 -> V_769 . V_770 . V_281 == V_777 ) {
if ( V_765 -> V_769 . V_770 . V_15 == V_772 )
F_325 ( V_2 , V_300 , V_773 ,
V_767 -> V_778 ,
L_74 ,
V_765 -> V_769 . V_770 . V_537 ) ;
else if ( V_765 -> V_769 . V_770 . V_15 == V_775 )
F_325 ( V_2 , V_300 , V_773 ,
V_767 -> V_779 ,
L_75 ) ;
} else if ( V_765 -> V_769 . V_770 . V_281 == V_780 ) {
F_325 ( V_2 , V_300 , V_773 ,
V_767 -> V_781 ,
L_76 , V_765 -> V_769 . V_770 . V_537 ) ;
} else if ( V_765 -> V_769 . V_770 . V_281 == V_782 ) {
F_325 ( V_2 , V_300 , V_773 ,
V_767 -> V_783 ,
L_77 , V_765 -> V_769 . V_770 . V_537 ) ;
}
#undef F_325
}
static void F_326 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
const struct V_764 * V_765 )
{
struct V_299 * V_300 ;
struct V_301 * V_302 ;
if ( ! F_81 ( V_2 -> V_72 , V_303 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_303 ) ;
V_302 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
if ( ! ( F_327 ( V_302 -> V_784 ) & F_45 ( V_765 -> V_769 . V_785 . V_295 ) ) )
return;
F_239 ( V_2 , V_300 ,
L_78 ,
V_765 -> V_769 . V_785 . V_264 -> V_164 , V_765 -> V_769 . V_785 . V_295 ,
V_765 -> V_769 . V_785 . V_308 ) ;
}
static void
F_328 ( struct V_1 * V_2 ,
struct V_293 * V_294 ,
const struct V_764 * V_765 )
{
struct V_299 * V_300 ;
struct V_301 * V_302 ;
if ( ! F_81 ( V_2 -> V_72 , V_303 ) )
return;
V_300 = F_82 ( V_2 -> V_72 , V_303 ) ;
V_302 = ( void * ) V_300 -> V_281 ;
if ( ! F_83 ( V_2 , V_294 , V_300 ) )
return;
if ( ! ( F_327 ( V_302 -> V_786 ) & F_45 ( V_765 -> V_769 . V_785 . V_295 ) ) )
return;
F_239 ( V_2 , V_300 ,
L_79 ,
V_765 -> V_769 . V_785 . V_264 -> V_164 , V_765 -> V_769 . V_785 . V_295 ) ;
}
static void F_329 ( struct V_29 * V_30 ,
struct V_293 * V_294 ,
const struct V_764 * V_765 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_765 -> type ) {
case V_787 :
F_324 ( V_2 , V_294 , V_765 ) ;
break;
case V_788 :
F_326 ( V_2 , V_294 , V_765 ) ;
break;
case V_789 :
F_328 ( V_2 , V_294 , V_765 ) ;
break;
default:
break;
}
}
void F_330 ( struct V_1 * V_2 ,
struct V_790 * V_475 ,
T_1 V_791 )
{
T_1 V_792 = F_45 ( V_2 -> V_7 -> V_76 ) - 1 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! F_39 ( V_2 ) || F_331 ( V_2 ) )
return;
V_475 -> V_793 = V_2 -> V_794 ;
if ( V_475 -> V_795 )
F_332 ( & V_2 -> V_796 ,
V_2 -> V_7 -> V_76 ) ;
V_47 = F_333 ( V_2 , V_792 , ( T_2 * ) V_475 , V_791 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_80 , V_47 ) ;
goto V_34;
}
if ( V_475 -> V_795 )
V_47 = F_13 ( V_2 -> V_797 ,
F_219 ( & V_2 -> V_796 ) == 0 ,
V_16 ) ;
F_15 ( ! V_47 ) ;
V_34:
F_332 ( & V_2 -> V_796 , 0 ) ;
V_2 -> V_794 ++ ;
}
static void F_334 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_790 V_281 = {
. type = V_798 ,
. V_795 = 1 ,
} ;
F_87 ( & V_2 -> V_33 ) ;
F_330 ( V_2 , & V_281 , sizeof( V_281 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
