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
if ( F_67 ( V_268 ) -> V_285 == V_86 &&
! F_14 ( V_286 , & V_2 -> V_15 ) &&
! F_14 ( V_287 , & V_2 -> V_15 ) )
goto V_284;
if ( F_70 ( V_280 -> V_147 & V_288 &&
F_71 ( V_282 -> V_289 ) &&
! F_72 ( V_282 -> V_289 ) &&
! F_73 ( V_282 -> V_289 ) &&
! F_74 ( V_282 -> V_289 ) ) )
V_266 = NULL ;
if ( V_266 ) {
if ( F_59 ( V_2 , V_266 , V_268 ) )
return;
if ( F_75 ( V_2 , V_268 , V_266 ) )
goto V_284;
return;
}
if ( F_76 ( V_2 , V_268 ) )
goto V_284;
return;
V_284:
F_77 ( V_30 , V_268 ) ;
}
static inline bool F_78 ( const struct V_290 * V_37 )
{
if ( V_108 . V_291 & V_292 )
return false ;
return true ;
}
static inline bool F_79 ( const struct V_290 * V_37 )
{
if ( V_108 . V_291 & V_293 )
return false ;
if ( V_108 . V_291 & V_294 )
return true ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 , struct V_295 * V_296 ,
struct V_265 * V_266 , V_140 V_297 , V_140 V_298 ,
enum V_299 V_300 )
{
struct V_301 * V_302 ;
struct V_303 * V_304 ;
if ( ! F_81 ( V_2 -> V_72 , V_305 ) )
return;
V_302 = F_82 ( V_2 -> V_72 , V_305 ) ;
V_304 = ( void * ) V_302 -> V_283 ;
if ( ! F_83 ( V_2 , V_296 , V_302 ) )
return;
switch ( V_300 ) {
case V_306 : {
struct V_136 * V_269 = F_62 ( V_266 ) ;
struct V_307 * V_308 = & V_269 -> V_308 [ V_297 ] ;
F_84 ( V_2 , V_302 , V_304 -> V_309 , V_297 ,
L_13 ,
V_266 -> V_164 , V_297 , V_308 -> V_310 ) ;
break;
}
case V_311 :
F_84 ( V_2 , V_302 , V_304 -> V_312 , V_297 ,
L_14 ,
V_266 -> V_164 , V_297 ) ;
break;
case V_313 :
F_84 ( V_2 , V_302 , V_304 -> V_314 , V_297 ,
L_15 ,
V_266 -> V_164 , V_297 , V_298 ) ;
break;
case V_315 :
F_84 ( V_2 , V_302 , V_304 -> V_316 , V_297 ,
L_16 ,
V_266 -> V_164 , V_297 ) ;
break;
default:
break;
}
}
static int F_85 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_317 * V_318 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_319 = false ;
struct V_265 * V_266 = V_318 -> V_266 ;
enum V_299 V_300 = V_318 -> V_300 ;
V_140 V_297 = V_318 -> V_297 ;
V_140 * V_310 = & V_318 -> V_310 ;
T_2 V_320 = V_318 -> V_320 ;
bool V_321 = V_318 -> V_321 ;
V_140 V_322 = V_318 -> V_322 ;
F_86 ( V_2 , L_17 ,
V_266 -> V_164 , V_297 , V_300 ) ;
if ( ! ( V_2 -> V_165 -> V_323 ) )
return - V_324 ;
switch ( V_300 ) {
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
F_87 ( & V_2 -> V_33 ) ;
switch ( V_300 ) {
case V_313 :
if ( ! F_78 ( V_2 -> V_37 ) ) {
V_47 = - V_329 ;
break;
}
V_47 = F_88 ( V_2 , V_266 , V_297 , * V_310 , true , V_320 ,
V_322 ) ;
break;
case V_315 :
V_47 = F_88 ( V_2 , V_266 , V_297 , 0 , false , V_320 ,
V_322 ) ;
break;
case V_325 :
if ( ! F_79 ( V_2 -> V_37 ) ) {
V_47 = - V_329 ;
break;
}
V_47 = F_89 ( V_2 , V_296 , V_266 , V_297 , V_310 ) ;
break;
case V_311 :
V_47 = F_90 ( V_2 , V_296 , V_266 , V_297 ) ;
break;
case V_326 :
case V_327 :
V_47 = F_91 ( V_2 , V_296 , V_266 , V_297 ) ;
break;
case V_306 :
V_47 = F_92 ( V_2 , V_296 , V_266 , V_297 ,
V_320 , V_321 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_329 ;
break;
}
if ( ! V_47 ) {
V_140 V_298 = 0 ;
if ( V_300 == V_313 )
V_298 = * V_310 ;
F_80 ( V_2 , V_296 , V_266 , V_297 ,
V_298 , V_300 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
if ( V_319 )
F_7 ( V_2 , V_328 ) ;
return V_47 ;
}
static void F_94 ( void * V_283 , T_2 * V_330 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = V_283 ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
V_331 -> V_332 = false ;
V_331 -> V_333 = V_273 ;
F_4 ( & V_2 -> V_334 ) ;
F_96 ( V_2 , & V_331 -> V_335 ) ;
F_5 ( & V_2 -> V_334 ) ;
V_331 -> V_336 = NULL ;
memset ( & V_331 -> V_337 , 0 , sizeof( V_331 -> V_337 ) ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
if ( ! F_98 ( V_338 , & V_2 -> V_15 ) ) {
V_2 -> V_339 = & V_340 ;
F_99 ( V_2 ) ;
}
F_10 ( V_2 , V_341 ) ;
F_100 ( V_2 ) ;
V_2 -> V_342 = 0 ;
V_2 -> V_343 = false ;
V_2 -> V_344 = false ;
F_101 ( V_2 ) ;
F_102 ( V_2 -> V_30 ) ;
F_103 ( V_2 -> V_30 , 0 , F_94 , V_2 ) ;
V_2 -> V_345 = NULL ;
V_2 -> V_274 = V_273 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_346 , 0 , sizeof( V_2 -> V_346 ) ) ;
memset ( V_2 -> V_347 , 0 , sizeof( V_2 -> V_347 ) ) ;
memset ( V_2 -> V_348 , 0 , sizeof( V_2 -> V_348 ) ) ;
memset ( V_2 -> V_349 , 0 , sizeof( V_2 -> V_349 ) ) ;
memset ( & V_2 -> V_350 , 0 , sizeof( V_2 -> V_350 ) ) ;
memset ( & V_2 -> V_351 , 0 , sizeof( V_2 -> V_351 ) ) ;
F_104 ( V_2 -> V_30 ) ;
F_105 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_352 = 0 ;
V_2 -> V_353 = 0 ;
V_2 -> V_354 = V_355 ;
F_106 ( V_2 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_356 , & V_2 -> V_15 ) ) {
F_108 ( V_357 , & V_2 -> V_15 ) ;
F_105 ( V_356 , & V_2 -> V_15 ) ;
F_97 ( V_2 ) ;
} else {
F_1 ( V_2 , V_341 ) ;
}
V_47 = F_109 ( V_2 ) ;
if ( V_47 && F_14 ( V_357 , & V_2 -> V_15 ) ) {
F_105 ( V_357 , & V_2 -> V_15 ) ;
F_110 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_111 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_357 , & V_2 -> V_15 ) ) {
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
static void F_112 ( struct V_1 * V_2 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_105 ( V_357 , & V_2 -> V_15 ) ;
F_110 ( V_2 , NULL ) ;
V_47 = F_113 ( V_2 , true , NULL ) ;
if ( V_47 )
F_114 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_341 ) ;
F_115 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) &&
F_117 ( V_2 ) )
F_118 ( ! F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ,
L_19 ) ;
}
static void
F_119 ( struct V_29 * V_30 ,
enum V_358 V_359 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_359 ) {
case V_360 :
F_112 ( V_2 ) ;
break;
case V_361 :
F_116 ( V_2 ) ;
break;
}
}
void F_120 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_362 , 0 , sizeof( V_2 -> V_362 ) ) ;
F_121 ( & V_2 -> V_363 ) ;
F_100 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
if ( F_98 ( V_357 , & V_2 -> V_15 ) )
F_103 ( V_2 -> V_30 , 0 ,
F_94 , V_2 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 , V_178 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_179 ; V_9 ++ ) {
if ( F_118 ( V_2 -> V_364 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_364 [ V_9 ] = 0 ;
}
}
}
static void F_124 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_121 ( & V_2 -> V_365 ) ;
F_121 ( & V_2 -> V_366 ) ;
F_121 ( & V_2 -> V_367 ) ;
F_105 ( V_368 , & V_2 -> V_15 ) ;
F_125 ( & V_2 -> V_369 ) ;
F_125 ( & V_2 -> V_370 ) ;
F_125 ( & V_2 -> V_371 ) ;
F_126 ( V_2 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_120 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_127 ( & V_2 -> V_366 ) ;
}
static struct V_372 * F_128 ( struct V_1 * V_2 )
{
V_140 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_114 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_129 ( struct V_1 * V_2 , struct V_295 * V_296 ,
T_3 V_373 )
{
struct V_374 V_375 = {
. V_376 . V_377 = F_130 ( V_378 ) ,
. V_376 . V_379 =
F_130 ( F_95 ( V_296 ) -> V_20 ) ,
. V_376 . V_380 = F_131 ( 8 * V_373 ) ,
} ;
int V_381 = sizeof( V_375 ) ;
if ( V_373 == V_382 )
V_375 . V_376 . V_380 = F_131 ( V_383 ) ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 , V_384 ) )
V_381 = sizeof( V_375 . V_376 ) ;
return F_132 ( V_2 , V_385 , 0 , V_381 , & V_375 ) ;
}
static int F_133 ( struct V_29 * V_30 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
int V_47 ;
V_331 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_386 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_357 , & V_2 -> V_15 ) )
V_331 -> V_387 . V_388 +=
V_331 -> V_387 . V_389 ;
V_47 = F_134 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_390;
if ( V_296 -> type != V_145 )
V_2 -> V_352 ++ ;
if ( V_296 -> type == V_143 ||
V_296 -> type == V_146 ) {
V_47 = F_135 ( V_2 , V_296 ) ;
if ( V_47 ) {
F_114 ( V_2 , L_22 ) ;
goto V_391;
}
if ( F_41 ( V_2 ) ) {
V_47 = F_136 ( V_2 , & V_331 -> V_392 ,
0 , V_296 -> type ,
V_393 ) ;
if ( V_47 )
goto V_391;
}
F_137 ( V_2 , V_296 ) ;
goto V_390;
}
V_331 -> V_131 |= V_30 -> V_79 ;
V_47 = F_138 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_391;
V_47 = F_139 ( V_2 ) ;
if ( V_47 )
goto V_394;
V_47 = F_140 ( V_2 , V_296 , 0 ) ;
if ( V_47 )
goto V_394;
if ( ! V_2 -> V_395 &&
V_296 -> type == V_121 && ! V_296 -> V_396 ) {
V_2 -> V_395 = V_331 ;
V_296 -> V_397 |= V_398 |
V_399 ;
}
if ( V_296 -> type == V_145 ) {
V_331 -> V_336 = F_128 ( V_2 ) ;
if ( ! V_331 -> V_336 ) {
V_47 = - V_400 ;
goto V_401;
}
F_141 ( V_2 , V_331 -> V_336 ) ;
V_47 = F_142 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_402;
V_47 = F_143 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_403;
V_2 -> V_345 = V_296 ;
}
F_137 ( V_2 , V_296 ) ;
goto V_390;
V_403:
F_144 ( V_2 , V_296 ) ;
V_402:
F_145 ( V_2 , V_331 -> V_336 ) ;
V_401:
if ( V_2 -> V_395 == V_331 ) {
V_2 -> V_395 = NULL ;
V_296 -> V_397 &= ~ ( V_398 |
V_399 ) ;
}
V_394:
V_331 -> V_336 = NULL ;
F_146 ( V_2 , V_296 ) ;
V_391:
if ( V_296 -> type != V_145 )
V_2 -> V_352 -- ;
F_147 ( V_2 , V_296 ) ;
V_390:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_386 ) ;
return V_47 ;
}
static void F_148 ( struct V_1 * V_2 ,
struct V_295 * V_296 )
{
T_1 V_404 = F_149 ( V_296 ) ;
if ( V_404 && ! F_41 ( V_2 ) ) {
F_87 ( & V_2 -> V_33 ) ;
F_150 ( V_2 , V_404 , 0 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_151 ( V_2 -> V_7 , V_404 ) ;
}
if ( V_296 -> type == V_145 ) {
F_121 ( & V_2 -> V_363 ) ;
} else {
F_121 ( & V_2 -> V_405 ) ;
}
}
static void F_152 ( struct V_29 * V_30 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
F_148 ( V_2 , V_296 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_395 == V_331 ) {
V_2 -> V_395 = NULL ;
V_296 -> V_397 &= ~ ( V_398 |
V_399 ) ;
}
F_153 ( V_2 , V_296 ) ;
if ( V_296 -> type == V_143 ||
V_296 -> type == V_146 ) {
#ifdef F_154
if ( V_296 == V_2 -> V_406 ) {
V_2 -> V_406 = NULL ;
V_2 -> V_407 = 0 ;
}
#endif
F_155 ( V_2 , & V_331 -> V_392 ) ;
F_156 ( V_2 , V_296 ) ;
goto V_391;
}
if ( V_296 -> type == V_145 ) {
V_2 -> V_345 = NULL ;
F_157 ( V_2 , V_296 ) ;
F_144 ( V_2 , V_296 ) ;
F_145 ( V_2 , V_331 -> V_336 ) ;
V_331 -> V_336 = NULL ;
}
if ( V_2 -> V_352 && V_296 -> type != V_145 )
V_2 -> V_352 -- ;
F_139 ( V_2 ) ;
F_146 ( V_2 , V_296 ) ;
V_391:
F_147 ( V_2 , V_296 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_158 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_159 ( void * V_408 , T_2 * V_330 ,
struct V_295 * V_296 )
{
struct V_409 * V_283 = V_408 ;
struct V_1 * V_2 = V_283 -> V_2 ;
struct V_410 * V_375 = V_2 -> V_411 ;
int V_47 , V_381 ;
if ( F_15 ( V_283 -> V_412 >= V_413 ) )
return;
if ( V_296 -> type != V_121 ||
! V_296 -> V_414 . V_415 )
return;
V_375 -> V_412 = V_283 -> V_412 ++ ;
memcpy ( V_375 -> V_416 , V_296 -> V_414 . V_416 , V_167 ) ;
V_381 = F_160 ( sizeof( * V_375 ) + V_375 -> V_417 * V_167 , 4 ) ;
V_47 = F_132 ( V_2 , V_418 , V_419 , V_381 , V_375 ) ;
if ( V_47 )
F_114 ( V_2 , L_23 , V_47 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_409 V_420 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_411 ) )
return;
F_162 (
V_2 -> V_30 , V_421 ,
F_159 , & V_420 ) ;
}
static T_4 F_163 ( struct V_29 * V_30 ,
struct V_422 * V_423 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_410 * V_375 ;
struct V_424 * V_164 ;
int V_425 ;
bool V_426 ;
int V_381 ;
V_425 = F_164 ( V_423 ) ;
V_426 = V_425 > V_427 ||
V_428 ;
if ( V_426 )
V_425 = 0 ;
V_381 = F_160 ( sizeof( * V_375 ) + V_425 * V_167 , 4 ) ;
V_375 = F_165 ( V_381 , V_429 ) ;
if ( ! V_375 )
return 0 ;
if ( V_426 ) {
V_375 -> V_426 = 1 ;
return ( T_4 ) ( unsigned long ) V_375 ;
}
F_166 (addr, mc_list) {
F_167 ( V_2 , L_24 ,
V_375 -> V_417 , V_164 -> V_164 ) ;
memcpy ( & V_375 -> V_430 [ V_375 -> V_417 * V_167 ] ,
V_164 -> V_164 , V_167 ) ;
V_375 -> V_417 ++ ;
}
return ( T_4 ) ( unsigned long ) V_375 ;
}
static void F_168 ( struct V_29 * V_30 ,
unsigned int V_431 ,
unsigned int * V_432 ,
T_4 V_433 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_410 * V_375 = ( void * ) ( unsigned long ) V_433 ;
F_87 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_411 ) ;
V_2 -> V_411 = V_375 ;
if ( ! V_375 )
goto V_34;
F_161 ( V_2 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
* V_432 = 0 ;
}
static void F_169 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
unsigned int V_434 ,
unsigned int V_431 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_431 & V_435 ) )
return;
if ( V_296 -> type != V_121 || ! V_296 -> V_414 . V_415 ||
! V_296 -> V_396 )
return;
F_87 ( & V_2 -> V_33 ) ;
F_170 ( V_2 , V_296 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_171 ( struct V_295 * V_296 ,
const struct V_436 * V_437 ,
struct V_436 * V_438 )
{
struct V_439 * V_440 ;
int V_9 ;
memcpy ( V_438 , V_437 , sizeof( * V_438 ) ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_438 -> V_441 ) ; V_9 ++ ) {
V_440 = & V_438 -> V_441 [ V_9 ] ;
if ( ! V_440 -> V_442 )
break;
switch ( V_440 -> V_443 ) {
case F_131 ( V_444 ) :
if ( V_296 -> V_414 . V_445 != 1 ) {
V_440 -> V_442 = 0 ;
continue;
}
V_440 -> V_446 = V_296 -> V_414 . V_447 [ 0 ] ;
break;
case F_131 ( V_448 ) :
V_440 -> V_446 = * ( V_449 * ) & V_296 -> V_164 [ 2 ] ;
break;
default:
break;
}
V_440 -> V_443 = 0 ;
V_438 -> V_450 ++ ;
}
}
static void F_172 ( void * V_408 , T_2 * V_330 ,
struct V_295 * V_296 )
{
struct V_451 * V_283 = V_408 ;
struct V_1 * V_2 = V_283 -> V_2 ;
struct V_452 * V_375 = V_283 -> V_375 ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
struct V_453 * V_454 ;
int V_9 ;
if ( F_8 ( V_331 -> V_20 >= F_43 ( V_375 -> V_455 ) ) )
return;
V_454 = & V_375 -> V_455 [ V_331 -> V_20 ] ;
if ( V_296 -> type != V_121 || V_296 -> V_396 ||
! V_296 -> V_414 . V_415 )
return;
V_454 -> V_456 = 1 ;
for ( V_9 = 0 ; V_2 -> V_251 [ V_9 ] . V_441 [ 0 ] . V_442 ; V_9 ++ ) {
if ( F_15 ( V_283 -> V_457 >=
F_43 ( V_375 -> V_458 ) ) ) {
V_454 -> V_456 = 0 ;
V_454 -> V_459 = 0 ;
break;
}
F_171 ( V_296 ,
& V_2 -> V_251 [ V_9 ] ,
& V_375 -> V_458 [ V_283 -> V_457 ] ) ;
if ( ! V_375 -> V_458 [ V_283 -> V_457 ] . V_450 )
continue;
V_454 -> V_459 |=
F_131 ( F_45 ( V_283 -> V_457 ) ) ;
V_283 -> V_457 ++ ;
}
}
bool F_173 ( struct V_1 * V_2 ,
struct V_452 * V_375 )
{
struct V_451 V_420 = {
. V_2 = V_2 ,
. V_375 = V_375 ,
} ;
if ( V_460 )
return false ;
memset ( V_375 , 0 , sizeof( * V_375 ) ) ;
V_375 -> V_461 = F_43 ( V_375 -> V_458 ) ;
V_375 -> V_462 = F_43 ( V_375 -> V_455 ) ;
#ifdef F_174
if ( V_2 -> V_463 . V_464 ) {
memcpy ( V_375 -> V_458 , & V_2 -> V_463 . V_375 . V_458 ,
sizeof( V_375 -> V_458 ) ) ;
memcpy ( V_375 -> V_455 , & V_2 -> V_463 . V_375 . V_455 ,
sizeof( V_375 -> V_455 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_251 )
return false ;
F_175 (
V_2 -> V_30 , V_421 ,
F_172 , & V_420 ) ;
return true ;
}
static int F_176 ( struct V_1 * V_2 )
{
struct V_452 V_375 ;
if ( ! ( V_2 -> V_72 -> V_73 . V_147 & V_465 ) )
return 0 ;
if ( ! F_173 ( V_2 , & V_375 ) )
return 0 ;
return F_132 ( V_2 , V_466 , 0 ,
sizeof( V_375 ) , & V_375 ) ;
}
static inline int F_176 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_177 ( struct V_1 * V_2 ,
struct V_295 * V_296 )
{
struct V_467 V_375 = {} ;
memcpy ( V_375 . V_468 , V_296 -> V_414 . V_469 . V_470 ,
V_471 ) ;
memcpy ( V_375 . V_472 , V_296 -> V_414 . V_469 . V_473 ,
V_474 ) ;
return F_132 ( V_2 ,
F_178 ( V_475 ,
V_476 ) ,
0 , sizeof( V_375 ) , & V_375 ) ;
}
static void F_179 ( void * V_408 , T_2 * V_330 ,
struct V_295 * V_296 )
{
if ( V_296 -> V_477 ) {
struct V_478 * V_479 = V_408 ;
F_180 ( V_296 ,
( T_2 * ) & V_479 -> V_468 ,
( T_2 * ) & V_479 -> V_472 ) ;
}
}
void F_181 ( struct V_1 * V_2 ,
struct V_480 * V_481 )
{
struct V_482 * V_483 = F_182 ( V_481 ) ;
struct V_478 * V_479 = ( void * ) V_483 -> V_283 ;
F_162 (
V_2 -> V_30 , V_421 ,
F_179 , V_479 ) ;
}
static void F_183 ( struct V_1 * V_2 ,
struct V_295 * V_296 ,
struct V_484 * V_414 ,
T_1 V_485 )
{
struct V_138 * V_331 = F_95 ( V_296 ) ;
int V_47 ;
if ( V_485 & V_486 && V_414 -> V_415 )
F_184 ( V_2 , V_296 ) ;
if ( V_485 & V_486 && ! V_414 -> V_415 &&
V_331 -> V_487 )
F_185 ( V_296 , V_488 ,
0 , 0 ) ;
if ( V_485 & V_489 && ! V_331 -> V_490 )
memcpy ( V_331 -> V_416 , V_414 -> V_416 , V_167 ) ;
V_47 = F_170 ( V_2 , V_296 , false , V_331 -> V_416 ) ;
if ( V_47 )
F_114 ( V_2 , L_25 , V_296 -> V_164 ) ;
memcpy ( V_331 -> V_416 , V_414 -> V_416 , V_167 ) ;
V_331 -> V_490 = V_414 -> V_415 ;
if ( V_485 & V_486 ) {
if ( V_414 -> V_415 ) {
F_186 ( V_2 , true ) ;
memset ( & V_331 -> V_387 , 0 ,
sizeof( V_331 -> V_387 ) ) ;
V_47 = F_113 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_114 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_357 ,
& V_2 -> V_15 ) ) {
T_1 V_491 = ( 11 * V_296 -> V_414 . V_492 ) / 10 ;
F_187 ( V_2 , V_296 , V_491 , V_491 ,
5 * V_491 , false ) ;
}
F_188 ( V_2 , V_296 , false ) ;
F_189 ( V_2 , V_296 ) ;
if ( V_296 -> V_396 ) {
F_1 ( V_2 , V_493 ) ;
F_190 ( V_2 , V_296 ,
V_494 ,
V_495 ) ;
}
} else if ( V_331 -> V_333 != V_273 ) {
F_118 ( F_188 ( V_2 , V_296 , false ) ,
L_27 ) ;
if ( ! F_14 ( V_357 ,
& V_2 -> V_15 ) ) {
V_47 = F_191 ( V_2 , V_296 ,
V_331 -> V_333 ) ;
if ( V_47 )
F_114 ( V_2 ,
L_28 ) ;
if ( V_2 -> V_274 == V_331 -> V_333 )
V_2 -> V_274 =
V_273 ;
V_331 -> V_333 = V_273 ;
}
V_47 = F_113 ( V_2 , false , NULL ) ;
if ( V_47 )
F_114 ( V_2 , L_26 ) ;
if ( V_296 -> V_396 )
F_7 ( V_2 , V_493 ) ;
V_47 = F_170 ( V_2 , V_296 , false , NULL ) ;
if ( V_47 )
F_114 ( V_2 ,
L_29 ,
V_296 -> V_164 ) ;
}
if ( F_14 ( V_357 , & V_2 -> V_15 ) &&
( V_485 & V_496 ) && V_296 -> V_477 ) {
V_47 = F_177 ( V_2 , V_296 ) ;
if ( V_47 )
F_114 ( V_2 ,
L_30 ) ;
}
F_161 ( V_2 ) ;
F_176 ( V_2 ) ;
V_331 -> V_337 . V_497 = 0 ;
F_192 ( V_2 ) ;
F_190 ( V_2 , V_296 , V_498 ,
V_499 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_178 ) )
F_193 ( V_2 ) ;
}
if ( V_485 & V_500 ) {
F_194 ( V_2 , V_331 ,
& V_331 -> V_335 ) ;
F_188 ( V_2 , V_296 , false ) ;
F_8 ( F_195 ( V_2 , V_296 , 0 ) ) ;
}
if ( V_485 & ( V_501 | V_502 | V_503 |
V_500 ) ) {
V_47 = F_139 ( V_2 ) ;
if ( V_47 )
F_114 ( V_2 , L_31 ) ;
}
if ( V_485 & V_504 ) {
F_196 ( V_2 , L_32 ,
V_414 -> V_505 ) ;
F_129 ( V_2 , V_296 , V_414 -> V_505 ) ;
}
if ( V_485 & V_506 ) {
F_167 ( V_2 , L_33 ) ;
V_331 -> V_337 . V_507 = 0 ;
if ( V_331 -> V_337 . V_508 ) {
V_47 = F_195 ( V_2 , V_296 , 0 ) ;
if ( V_47 )
F_114 ( V_2 ,
L_34 ) ;
}
}
if ( V_485 & V_509 ) {
F_167 ( V_2 , L_35 ) ;
F_176 ( V_2 ) ;
}
}
static int F_197 ( struct V_29 * V_30 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_510 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_198 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_390;
if ( V_296 -> type == V_143 )
F_184 ( V_2 , V_296 ) ;
V_331 -> V_511 = 0 ;
V_47 = F_138 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_390;
V_47 = F_142 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_512;
V_47 = F_199 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_403;
V_47 = F_200 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_513;
V_331 -> V_514 = true ;
F_139 ( V_2 ) ;
V_47 = F_113 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_515;
if ( V_296 -> V_396 && V_2 -> V_345 )
F_170 ( V_2 , V_2 -> V_345 , false , NULL ) ;
F_1 ( V_2 , V_516 ) ;
F_192 ( V_2 ) ;
if ( F_201 ( V_2 ) > 1 )
F_115 ( V_2 ) ;
goto V_390;
V_515:
F_139 ( V_2 ) ;
V_331 -> V_514 = false ;
F_202 ( V_2 , V_296 ) ;
V_513:
F_203 ( V_2 , V_296 ) ;
V_403:
F_144 ( V_2 , V_296 ) ;
V_512:
F_146 ( V_2 , V_296 ) ;
V_390:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_510 ) ;
return V_47 ;
}
static void F_204 ( struct V_29 * V_30 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
F_148 ( V_2 , V_296 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_205 ( V_2 -> V_517 ) == V_296 ) {
F_194 ( V_2 , V_331 ,
& V_331 -> V_335 ) ;
F_206 ( V_2 -> V_517 , NULL ) ;
V_331 -> V_518 = false ;
}
if ( F_205 ( V_2 -> V_519 ) == V_296 ) {
F_206 ( V_2 -> V_519 , NULL ) ;
V_2 -> V_520 = 0 ;
}
V_331 -> V_514 = false ;
V_2 -> V_521 = 0 ;
F_192 ( V_2 ) ;
F_7 ( V_2 , V_516 ) ;
if ( V_296 -> V_396 && V_2 -> V_345 )
F_170 ( V_2 , V_2 -> V_345 , false , NULL ) ;
F_113 ( V_2 , false , NULL ) ;
if ( ! F_49 ( & V_2 -> V_72 -> V_73 , V_522 ) )
F_203 ( V_2 , V_296 ) ;
F_202 ( V_2 , V_296 ) ;
if ( F_49 ( & V_2 -> V_72 -> V_73 , V_522 ) )
F_203 ( V_2 , V_296 ) ;
F_144 ( V_2 , V_296 ) ;
F_139 ( V_2 ) ;
F_146 ( V_2 , V_296 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_207 ( struct V_1 * V_2 ,
struct V_295 * V_296 ,
struct V_484 * V_414 ,
T_1 V_485 )
{
struct V_138 * V_331 = F_95 ( V_296 ) ;
if ( ! V_331 -> V_514 )
return;
if ( V_485 & ( V_523 | V_524 |
V_525 | V_503 ) &&
F_170 ( V_2 , V_296 , false , NULL ) )
F_114 ( V_2 , L_25 , V_296 -> V_164 ) ;
if ( V_485 & V_526 &&
F_198 ( V_2 , V_296 ) )
F_208 ( V_2 , L_36 ) ;
if ( V_485 & V_504 ) {
F_196 ( V_2 , L_32 ,
V_414 -> V_505 ) ;
F_129 ( V_2 , V_296 , V_414 -> V_505 ) ;
}
}
static void F_209 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_484 * V_414 ,
T_1 V_485 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_527 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_485 & V_528 && ! V_414 -> V_529 )
F_210 ( V_2 , V_530 , true ) ;
switch ( V_296 -> type ) {
case V_121 :
F_183 ( V_2 , V_296 , V_414 , V_485 ) ;
break;
case V_143 :
case V_146 :
F_207 ( V_2 , V_296 , V_414 , V_485 ) ;
break;
case V_531 :
if ( V_485 & V_496 )
F_177 ( V_2 , V_296 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_527 ) ;
}
static int F_211 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_532 * V_533 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_533 -> V_534 . V_38 == 0 ||
V_533 -> V_534 . V_38 > V_2 -> V_72 -> V_73 . V_535 )
return - V_329 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_212 ( V_2 , V_296 , & V_533 -> V_534 , & V_533 -> V_536 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_213 ( struct V_29 * V_30 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_342 & V_537 )
F_210 ( V_2 , V_537 , true ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_214 ( struct V_29 * V_30 ,
struct V_265 * V_266 , V_140 V_538 ,
int V_539 ,
enum V_540 V_541 ,
bool V_542 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_215 ( V_2 , V_266 , V_541 , V_539 ,
V_538 , V_542 , false ) ;
}
static void
F_216 ( struct V_29 * V_30 ,
struct V_265 * V_266 , V_140 V_538 ,
int V_539 ,
enum V_540 V_541 ,
bool V_542 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_215 ( V_2 , V_266 , V_541 , V_539 ,
V_538 , V_542 , true ) ;
}
static void F_217 ( struct V_29 * V_30 ,
enum V_543 V_375 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_269 = F_62 ( V_266 ) ;
unsigned long V_544 = 0 , V_538 = 0 ;
int V_297 ;
F_4 ( & V_269 -> V_545 ) ;
for ( V_297 = 0 ; V_297 < V_546 ; V_297 ++ ) {
struct V_307 * V_308 = & V_269 -> V_308 [ V_297 ] ;
if ( ! F_41 ( V_2 ) &&
V_308 -> V_547 != V_548 &&
V_308 -> V_547 != V_549 )
continue;
if ( V_308 -> V_550 == V_551 )
continue;
F_218 ( V_308 -> V_550 , & V_544 ) ;
if ( F_219 ( V_2 , V_308 ) == 0 )
continue;
F_218 ( V_297 , & V_538 ) ;
}
switch ( V_375 ) {
case V_552 :
if ( F_220 ( & V_2 -> V_553 [ V_269 -> V_272 ] ) > 0 )
F_221 ( V_30 , V_266 , true ) ;
F_222 (tid, &tids, IWL_MAX_TID_COUNT)
F_223 ( V_266 , V_297 , true ) ;
if ( V_544 )
F_224 ( V_2 -> V_7 , V_544 , true ) ;
break;
case V_554 :
if ( F_8 ( V_269 -> V_272 == V_273 ) )
break;
if ( V_544 )
F_224 ( V_2 -> V_7 , V_544 , false ) ;
F_225 ( V_2 , V_266 ) ;
break;
default:
break;
}
F_5 ( & V_269 -> V_545 ) ;
}
static void F_226 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
enum V_543 V_375 ,
struct V_265 * V_266 )
{
F_217 ( V_30 , V_375 , V_266 ) ;
}
void F_227 ( struct V_1 * V_2 , struct V_480 * V_481 )
{
struct V_482 * V_483 = F_182 ( V_481 ) ;
struct V_555 * V_479 = ( void * ) V_483 -> V_283 ;
struct V_265 * V_266 ;
struct V_136 * V_269 ;
bool V_556 = ( V_479 -> type != V_557 ) ;
if ( F_8 ( V_479 -> V_272 >= F_43 ( V_2 -> V_558 ) ) )
return;
F_228 () ;
V_266 = F_229 ( V_2 -> V_558 [ V_479 -> V_272 ] ) ;
if ( F_8 ( F_23 ( V_266 ) ) ) {
F_230 () ;
return;
}
V_269 = F_62 ( V_266 ) ;
if ( ! V_269 -> V_296 ||
V_269 -> V_296 -> type != V_143 ) {
F_230 () ;
return;
}
if ( V_269 -> V_556 != V_556 ) {
V_269 -> V_556 = V_556 ;
F_217 ( V_2 -> V_30 ,
V_556 ? V_552 : V_554 ,
V_266 ) ;
F_231 ( V_266 , V_556 ) ;
}
if ( V_556 ) {
switch ( V_479 -> type ) {
case V_557 :
case V_559 :
break;
case V_560 :
F_232 ( V_266 , V_561 ) ;
break;
case V_562 :
F_233 ( V_266 ) ;
break;
default:
break;
}
}
F_230 () ;
}
static void F_234 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_563 = F_62 ( V_266 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_266 == F_205 ( V_2 -> V_558 [ V_563 -> V_272 ] ) )
F_235 ( V_2 -> V_558 [ V_563 -> V_272 ] ,
F_236 ( - V_49 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_237 ( struct V_1 * V_2 , struct V_295 * V_296 ,
const T_2 * V_416 )
{
if ( ! ( V_2 -> V_72 -> V_73 . V_147 & V_564 ) )
return;
if ( V_296 -> V_396 && ! F_238 ( V_2 ) ) {
V_296 -> V_397 &= ~ V_565 ;
return;
}
if ( ! V_296 -> V_396 &&
( V_108 . V_566 & V_567 ) ) {
V_296 -> V_397 &= ~ V_565 ;
return;
}
V_296 -> V_397 |= V_565 ;
}
static void
F_239 ( struct V_1 * V_2 ,
struct V_295 * V_296 , T_2 * V_568 ,
enum V_569 V_300 )
{
struct V_301 * V_302 ;
struct V_570 * V_571 ;
if ( ! F_81 ( V_2 -> V_72 , V_572 ) )
return;
V_302 = F_82 ( V_2 -> V_72 , V_572 ) ;
V_571 = ( void * ) V_302 -> V_283 ;
if ( ! F_83 ( V_2 , V_296 , V_302 ) )
return;
if ( ! ( V_571 -> V_573 & F_45 ( V_300 ) ) )
return;
if ( V_571 -> V_574 &&
memcmp ( V_571 -> V_575 , V_568 , V_167 ) != 0 )
return;
F_240 ( V_2 , V_302 ,
L_37 ,
V_568 , V_300 ) ;
}
static void F_241 ( struct V_1 * V_2 ,
struct V_136 * V_563 )
{
struct V_307 * V_308 ;
struct V_267 * V_268 ;
int V_9 ;
F_4 ( & V_563 -> V_545 ) ;
for ( V_9 = 0 ; V_9 <= V_546 ; V_9 ++ ) {
V_308 = & V_563 -> V_308 [ V_9 ] ;
while ( ( V_268 = F_242 ( & V_308 -> V_576 ) ) ) {
struct V_279 * V_280 = F_67 ( V_268 ) ;
F_243 ( V_2 , V_280 -> V_285 ) ;
F_77 ( V_2 -> V_30 , V_268 ) ;
}
}
F_5 ( & V_563 -> V_545 ) ;
}
static int F_244 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_265 * V_266 ,
enum V_577 V_578 ,
enum V_577 V_579 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
struct V_136 * V_563 = F_62 ( V_266 ) ;
int V_47 ;
F_167 ( V_2 , L_38 ,
V_266 -> V_164 , V_578 , V_579 ) ;
if ( F_15 ( ! V_331 -> V_336 ) )
return - V_329 ;
F_121 ( & V_2 -> V_405 ) ;
if ( V_578 == V_580 &&
V_579 == V_581 &&
F_41 ( V_2 ) ) {
F_241 ( V_2 , V_563 ) ;
F_121 ( & V_2 -> V_367 ) ;
}
F_87 ( & V_2 -> V_33 ) ;
V_563 -> V_490 = V_579 >= V_582 ;
if ( V_578 == V_581 &&
V_579 == V_580 ) {
if ( V_296 -> type == V_121 &&
V_296 -> V_414 . V_492 < 16 ) {
F_114 ( V_2 ,
L_39 ,
V_266 -> V_164 , V_296 -> V_414 . V_492 ) ;
V_47 = - V_329 ;
goto V_390;
}
if ( V_266 -> V_583 &&
( V_296 -> V_396 ||
F_245 ( V_2 , NULL ) ==
V_584 ||
F_201 ( V_2 ) > 1 ) ) {
F_167 ( V_2 , L_40 ) ;
V_47 = - V_585 ;
goto V_390;
}
V_47 = F_246 ( V_2 , V_296 , V_266 ) ;
if ( V_266 -> V_583 && V_47 == 0 ) {
F_247 ( V_2 , V_296 , true ) ;
F_239 ( V_2 , V_296 , V_266 -> V_164 ,
V_586 ) ;
}
} else if ( V_578 == V_580 &&
V_579 == V_587 ) {
V_2 -> V_588 = true ;
F_237 ( V_2 , V_296 , V_266 -> V_164 ) ;
V_47 = 0 ;
} else if ( V_578 == V_587 &&
V_579 == V_582 ) {
if ( V_296 -> type == V_143 ) {
V_331 -> V_511 ++ ;
F_170 ( V_2 , V_296 , false , NULL ) ;
}
F_248 ( V_2 , V_266 , V_331 -> V_336 -> V_589 -> V_590 ,
true ) ;
V_47 = F_249 ( V_2 , V_296 , V_266 ) ;
} else if ( V_578 == V_582 &&
V_579 == V_591 ) {
if ( F_201 ( V_2 ) > 1 )
F_115 ( V_2 ) ;
if ( V_266 -> V_583 )
F_239 ( V_2 , V_296 , V_266 -> V_164 ,
V_592 ) ;
F_8 ( F_195 ( V_2 , V_296 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_578 == V_591 &&
V_579 == V_582 ) {
F_8 ( F_140 ( V_2 , V_296 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_578 == V_582 &&
V_579 == V_587 ) {
if ( V_296 -> type == V_143 ) {
V_331 -> V_511 -- ;
F_170 ( V_2 , V_296 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_578 == V_587 &&
V_579 == V_580 ) {
V_47 = 0 ;
} else if ( V_578 == V_580 &&
V_579 == V_581 ) {
V_47 = F_250 ( V_2 , V_296 , V_266 ) ;
if ( V_266 -> V_583 ) {
F_247 ( V_2 , V_296 , false ) ;
F_239 ( V_2 , V_296 , V_266 -> V_164 ,
V_593 ) ;
}
} else {
V_47 = - V_17 ;
}
V_390:
F_93 ( & V_2 -> V_33 ) ;
if ( V_266 -> V_583 && V_47 == 0 ) {
if ( V_578 == V_581 &&
V_579 == V_580 )
F_251 ( V_266 , V_594 ) ;
else if ( V_578 == V_580 &&
V_579 == V_581 )
F_252 ( V_266 , V_594 ) ;
}
return V_47 ;
}
static int F_253 ( struct V_29 * V_30 , T_1 V_595 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_224 = V_595 ;
return 0 ;
}
static void F_254 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_265 * V_266 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_296 -> type == V_121 &&
V_27 & V_596 )
F_188 ( V_2 , V_296 , false ) ;
}
static int F_255 ( struct V_29 * V_30 ,
struct V_295 * V_296 , V_140 V_597 ,
const struct V_598 * V_318 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
V_331 -> V_599 [ V_597 ] = * V_318 ;
if ( V_296 -> type == V_145 ) {
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_170 ( V_2 , V_296 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_256 ( struct V_29 * V_30 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_600 = V_601 ;
T_1 V_602 = V_603 ;
if ( F_15 ( V_296 -> V_414 . V_415 ) )
return;
if ( F_12 ( V_2 , V_604 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_187 ( V_2 , V_296 , V_600 , V_602 , 500 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_604 ) ;
}
static int F_257 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_605 * V_534 ,
struct V_606 * V_536 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! V_296 -> V_414 . V_529 ) {
V_47 = - V_585 ;
goto V_34;
}
V_47 = F_258 ( V_2 , V_296 , V_534 , V_536 , V_530 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_259 ( struct V_29 * V_30 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_342 & V_530 ) ) {
F_93 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_210 ( V_2 , V_530 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_260 ( V_2 ) ;
return V_47 ;
}
static int F_261 ( struct V_29 * V_30 ,
enum V_607 V_375 ,
struct V_295 * V_296 ,
struct V_265 * V_266 ,
struct V_608 * V_609 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_269 ;
struct V_610 * V_611 ;
int V_612 = V_609 -> V_612 ;
int V_47 ;
T_2 V_613 ;
if ( V_108 . V_109 ) {
F_167 ( V_2 , L_41 ) ;
return - V_614 ;
}
switch ( V_609 -> V_115 ) {
case V_54 :
V_609 -> V_147 |= V_615 ;
V_609 -> V_147 |= V_616 ;
break;
case V_55 :
case V_106 :
case V_107 :
if ( ! F_262 ( V_2 ) )
V_609 -> V_147 |= V_616 ;
break;
case V_111 :
case V_112 :
case V_113 :
F_15 ( ! F_263 ( V_30 , V_110 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_296 -> type != V_121 )
return 0 ;
break;
default:
if ( V_30 -> V_119 &&
V_30 -> V_129 -> V_115 == V_609 -> V_115 )
V_609 -> V_147 |= V_616 ;
else
return - V_614 ;
}
F_87 ( & V_2 -> V_33 ) ;
switch ( V_375 ) {
case V_617 :
if ( ( V_296 -> type == V_146 ||
V_296 -> type == V_143 ) && ! V_266 ) {
if ( V_609 -> V_115 == V_111 ||
V_609 -> V_115 == V_112 ||
V_609 -> V_115 == V_113 )
V_47 = - V_614 ;
else
V_47 = 0 ;
if ( V_609 -> V_115 != V_106 &&
V_609 -> V_115 != V_107 &&
! F_262 ( V_2 ) ) {
V_609 -> V_618 = V_619 ;
break;
}
}
if ( F_14 ( V_357 , & V_2 -> V_15 ) &&
V_609 -> V_618 == V_619 ) {
F_167 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_357 , & V_2 -> V_15 ) &&
V_266 && F_39 ( V_2 ) &&
V_609 -> V_147 & V_620 &&
( V_609 -> V_115 == V_55 ||
V_609 -> V_115 == V_106 ||
V_609 -> V_115 == V_107 ) ) {
struct V_621 V_622 ;
int V_297 , V_623 ;
V_269 = F_62 ( V_266 ) ;
F_8 ( F_205 ( V_269 -> V_611 [ V_612 ] ) ) ;
V_611 = F_165 ( sizeof( * V_611 ) +
V_2 -> V_7 -> V_76 *
sizeof( V_611 -> V_623 [ 0 ] ) ,
V_624 ) ;
if ( ! V_611 ) {
V_47 = - V_625 ;
break;
}
for ( V_297 = 0 ; V_297 < V_546 ; V_297 ++ ) {
F_264 ( V_609 , V_297 , & V_622 ) ;
for ( V_623 = 0 ; V_623 < V_2 -> V_7 -> V_76 ; V_623 ++ )
memcpy ( V_611 -> V_623 [ V_623 ] . V_626 [ V_297 ] ,
V_622 . V_627 . V_626 ,
V_628 ) ;
}
F_235 ( V_269 -> V_611 [ V_612 ] , V_611 ) ;
}
if ( F_14 ( V_357 , & V_2 -> V_15 ) )
V_613 = V_609 -> V_618 ;
else
V_613 = V_619 ;
F_167 ( V_2 , L_43 ) ;
V_47 = F_265 ( V_2 , V_296 , V_266 , V_609 , V_613 ) ;
if ( V_47 ) {
F_208 ( V_2 , L_44 ) ;
V_609 -> V_618 = V_619 ;
V_47 = 0 ;
}
break;
case V_629 :
if ( V_609 -> V_618 == V_619 ) {
V_47 = 0 ;
break;
}
if ( V_266 && F_39 ( V_2 ) &&
V_609 -> V_147 & V_620 &&
( V_609 -> V_115 == V_55 ||
V_609 -> V_115 == V_106 ||
V_609 -> V_115 == V_107 ) ) {
V_269 = F_62 ( V_266 ) ;
V_611 = F_266 (
V_269 -> V_611 [ V_612 ] ,
F_267 ( & V_2 -> V_33 ) ) ;
F_206 ( V_269 -> V_611 [ V_612 ] , NULL ) ;
if ( V_611 )
F_268 ( V_611 , V_630 ) ;
}
F_167 ( V_2 , L_45 ) ;
V_47 = F_269 ( V_2 , V_296 , V_266 , V_609 ) ;
break;
default:
V_47 = - V_329 ;
}
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_270 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_608 * V_631 ,
struct V_265 * V_266 ,
T_1 V_632 , V_140 * V_633 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_631 -> V_618 == V_619 )
return;
F_271 ( V_2 , V_296 , V_631 , V_266 , V_632 , V_633 ) ;
}
static bool F_272 ( struct V_634 * V_635 ,
struct V_482 * V_483 , void * V_283 )
{
struct V_1 * V_2 =
F_273 ( V_635 , struct V_1 , V_635 ) ;
struct V_636 * V_32 ;
int V_637 = F_274 ( V_483 ) ;
struct V_638 * V_639 = V_283 ;
if ( F_8 ( V_483 -> V_282 . V_375 != V_640 ) )
return true ;
if ( F_15 ( V_637 != sizeof( * V_32 ) ) ) {
F_114 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_483 -> V_283 ;
F_275 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_641 ) ;
V_639 -> V_642 = F_44 ( V_32 -> V_641 ) ;
F_275 ( V_2 , L_48 ,
V_639 -> V_642 ) ;
F_4 ( & V_2 -> V_334 ) ;
F_276 ( & V_639 -> V_643 , & V_2 -> V_644 ) ;
F_5 ( & V_2 -> V_334 ) ;
return true ;
}
static int F_277 ( struct V_1 * V_2 ,
struct V_645 * V_589 ,
struct V_295 * V_296 ,
int V_600 )
{
int V_646 , V_647 = V_648 ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
struct V_638 * V_639 = & V_331 -> V_649 ;
static const V_140 V_650 [] = { V_640 } ;
struct V_651 V_652 ;
T_1 V_653 = V_296 -> V_414 . V_654 *
V_296 -> V_414 . V_492 ;
T_1 V_655 , V_656 ;
struct V_657 V_658 = {
. V_300 = F_130 ( V_659 ) ,
. V_660 =
F_130 ( F_278 ( V_661 , 0 ) ) ,
. V_662 = F_130 ( V_2 -> V_663 . V_272 ) ,
. V_664 . V_590 = ( V_589 -> V_590 == V_181 ) ?
V_665 : V_666 ,
. V_664 . V_589 = V_589 -> V_667 ,
. V_664 . V_668 = V_669 ,
. V_670 = F_130 ( F_279 ( V_2 -> V_7 , V_647 ) ) ,
} ;
V_656 = V_671 ;
V_655 = F_280 ( V_600 ) ;
if ( V_296 -> V_414 . V_415 ) {
V_656 = F_281 ( T_1 , V_653 * 3 , V_672 ) ;
if ( V_653 <= V_655 ) {
V_655 = V_653 - V_673 ;
if ( V_655 <= V_674 )
V_655 = V_653 -
V_675 ;
}
}
V_658 . V_600 = F_130 ( V_655 ) ;
V_658 . V_676 = F_130 ( V_656 ) ;
F_275 ( V_2 ,
L_49 ,
V_589 -> V_667 , V_655 , V_600 , V_656 ,
V_653 ) ;
memcpy ( V_658 . V_677 , V_296 -> V_164 , V_167 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_334 ) ;
if ( F_8 ( V_639 -> V_20 == V_640 ) ) {
F_5 ( & V_2 -> V_334 ) ;
return - V_17 ;
}
V_639 -> V_296 = V_296 ;
V_639 -> V_600 = V_600 ;
V_639 -> V_20 = V_640 ;
F_5 ( & V_2 -> V_334 ) ;
F_282 ( & V_2 -> V_635 , & V_652 ,
V_650 ,
F_43 ( V_650 ) ,
F_272 , V_639 ) ;
V_646 = F_132 ( V_2 , V_640 , 0 , sizeof( V_658 ) ,
& V_658 ) ;
if ( V_646 ) {
F_114 ( V_2 , L_50 , V_646 ) ;
F_283 ( & V_2 -> V_635 , & V_652 ) ;
goto V_678;
}
V_646 = F_284 ( & V_2 -> V_635 , & V_652 , 1 ) ;
F_15 ( V_646 ) ;
if ( V_646 ) {
V_678:
F_4 ( & V_2 -> V_334 ) ;
F_96 ( V_2 , V_639 ) ;
F_5 ( & V_2 -> V_334 ) ;
}
return V_646 ;
}
static int F_285 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_645 * V_589 ,
int V_600 ,
enum V_679 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
struct V_680 V_681 ;
struct V_372 * V_336 ;
int V_47 , V_9 ;
F_167 ( V_2 , L_51 , V_589 -> V_667 ,
V_600 , type ) ;
F_121 ( & V_2 -> V_363 ) ;
F_87 ( & V_2 -> V_33 ) ;
switch ( V_296 -> type ) {
case V_121 :
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_682 ) ) {
V_47 = F_277 ( V_2 , V_589 ,
V_296 , V_600 ) ;
goto V_390;
}
F_114 ( V_2 , L_52 ) ;
V_47 = - V_329 ;
goto V_390;
case V_145 :
break;
default:
F_114 ( V_2 , L_53 , V_296 -> type ) ;
V_47 = - V_329 ;
goto V_390;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_336 = & V_2 -> V_18 [ V_9 ] ;
if ( V_336 -> V_21 == 0 || V_331 -> V_336 == V_336 )
continue;
if ( V_336 -> V_21 && V_589 == V_336 -> V_589 ) {
V_47 = F_144 ( V_2 , V_296 ) ;
if ( F_286 ( V_47 , L_54 ) )
goto V_390;
F_145 ( V_2 , V_331 -> V_336 ) ;
V_331 -> V_336 = V_336 ;
V_47 = F_142 ( V_2 , V_296 ) ;
if ( F_286 ( V_47 , L_55 ) )
goto V_390;
F_141 ( V_2 , V_331 -> V_336 ) ;
goto V_683;
}
}
if ( V_589 == V_331 -> V_336 -> V_589 )
goto V_683;
F_287 ( & V_681 , V_589 , V_684 ) ;
if ( V_331 -> V_336 -> V_21 == 1 ) {
V_47 = F_288 ( V_2 , V_331 -> V_336 ,
& V_681 , 1 , 1 ) ;
if ( V_47 )
goto V_390;
} else {
V_336 = F_128 ( V_2 ) ;
if ( ! V_336 ) {
V_47 = - V_400 ;
goto V_390;
}
V_47 = F_288 ( V_2 , V_336 , & V_681 ,
1 , 1 ) ;
if ( V_47 ) {
F_114 ( V_2 , L_56 ) ;
goto V_390;
}
V_47 = F_144 ( V_2 , V_296 ) ;
if ( F_286 ( V_47 , L_54 ) )
goto V_390;
F_145 ( V_2 , V_331 -> V_336 ) ;
V_331 -> V_336 = V_336 ;
V_47 = F_142 ( V_2 , V_296 ) ;
if ( F_286 ( V_47 , L_55 ) )
goto V_390;
F_141 ( V_2 , V_331 -> V_336 ) ;
}
V_683:
V_47 = F_289 ( V_2 , V_296 , V_600 , type ) ;
V_390:
F_93 ( & V_2 -> V_33 ) ;
F_167 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_290 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_167 ( V_2 , L_58 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_291 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_167 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_292 ( struct V_1 * V_2 ,
struct V_685 * V_686 )
{
V_140 * V_687 = ( V_140 * ) V_686 -> V_688 ;
struct V_372 * V_336 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_167 ( V_2 , L_59 ) ;
V_336 = F_128 ( V_2 ) ;
if ( ! V_336 ) {
V_47 = - V_400 ;
goto V_34;
}
V_47 = F_288 ( V_2 , V_336 , & V_686 -> V_689 ,
V_686 -> V_690 ,
V_686 -> V_691 ) ;
if ( V_47 ) {
F_114 ( V_2 , L_60 ) ;
goto V_34;
}
F_141 ( V_2 , V_336 ) ;
* V_687 = V_336 -> V_20 ;
V_34:
return V_47 ;
}
static int F_293 ( struct V_29 * V_30 ,
struct V_685 * V_686 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_292 ( V_2 , V_686 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_294 ( struct V_1 * V_2 ,
struct V_685 * V_686 )
{
V_140 * V_687 = ( V_140 * ) V_686 -> V_688 ;
struct V_372 * V_336 = & V_2 -> V_18 [ * V_687 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_145 ( V_2 , V_336 ) ;
}
static void F_295 ( struct V_29 * V_30 ,
struct V_685 * V_686 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_294 ( V_2 , V_686 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_296 ( struct V_29 * V_30 ,
struct V_685 * V_686 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_140 * V_687 = ( V_140 * ) V_686 -> V_688 ;
struct V_372 * V_336 = & V_2 -> V_18 [ * V_687 ] ;
if ( F_118 ( ( V_336 -> V_21 > 1 ) &&
( V_27 & ~ ( V_692 |
V_693 |
V_694 |
V_695 ) ) ,
L_61 ,
V_336 -> V_21 , V_27 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_192 ( V_2 ) ;
F_288 ( V_2 , V_336 , & V_686 -> V_689 ,
V_686 -> V_690 ,
V_686 -> V_691 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_297 ( struct V_1 * V_2 ,
struct V_295 * V_296 ,
struct V_685 * V_686 ,
bool V_696 )
{
V_140 * V_687 = ( V_140 * ) V_686 -> V_688 ;
struct V_372 * V_336 = & V_2 -> V_18 [ * V_687 ] ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_331 -> V_336 = V_336 ;
switch ( V_296 -> type ) {
case V_143 :
if ( V_696 ) {
V_331 -> V_514 = true ;
break;
}
case V_146 :
V_47 = 0 ;
goto V_34;
case V_121 :
break;
case V_531 :
V_331 -> V_343 = true ;
break;
default:
V_47 = - V_329 ;
goto V_34;
}
V_47 = F_142 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_34;
F_139 ( V_2 ) ;
if ( V_296 -> type == V_531 ) {
V_331 -> V_697 = true ;
V_47 = F_113 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_698;
V_47 = F_298 ( V_2 , V_296 ) ;
if ( V_47 )
goto V_698;
}
if ( V_296 -> type == V_143 ) {
F_113 ( V_2 , false , NULL ) ;
F_170 ( V_2 , V_296 , false , NULL ) ;
}
if ( V_696 && V_296 -> type == V_121 ) {
T_1 V_600 = 2 * V_296 -> V_414 . V_492 ;
V_47 = F_12 ( V_2 , V_699 ) ;
if ( V_47 )
goto V_698;
F_187 ( V_2 , V_296 , V_600 , V_600 ,
V_296 -> V_414 . V_492 / 2 ,
true ) ;
F_7 ( V_2 , V_699 ) ;
F_113 ( V_2 , false , NULL ) ;
}
goto V_34;
V_698:
F_144 ( V_2 , V_296 ) ;
F_139 ( V_2 ) ;
V_34:
if ( V_47 )
V_331 -> V_336 = NULL ;
return V_47 ;
}
static int F_299 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_685 * V_686 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_297 ( V_2 , V_296 , V_686 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_300 ( struct V_1 * V_2 ,
struct V_295 * V_296 ,
struct V_685 * V_686 ,
bool V_696 )
{
struct V_138 * V_331 = F_95 ( V_296 ) ;
struct V_295 * V_700 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_194 ( V_2 , V_331 , & V_331 -> V_335 ) ;
switch ( V_296 -> type ) {
case V_146 :
goto V_34;
case V_531 :
V_331 -> V_697 = false ;
V_331 -> V_343 = false ;
F_301 ( V_2 , V_296 ) ;
break;
case V_143 :
if ( ! V_696 || ! V_331 -> V_514 )
goto V_34;
V_331 -> V_518 = false ;
F_302 ( V_2 , V_331 , true ) ;
F_235 ( V_2 -> V_519 , V_296 ) ;
V_331 -> V_514 = false ;
break;
case V_121 :
if ( ! V_696 )
break;
V_700 = V_296 ;
F_170 ( V_2 , V_296 , true , NULL ) ;
break;
default:
break;
}
F_113 ( V_2 , false , V_700 ) ;
F_144 ( V_2 , V_296 ) ;
V_34:
V_331 -> V_336 = NULL ;
F_139 ( V_2 ) ;
}
static void F_303 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_685 * V_686 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_300 ( V_2 , V_296 , V_686 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int
F_304 ( struct V_1 * V_2 ,
struct V_701 * V_702 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_300 ( V_2 , V_702 [ 0 ] . V_296 , V_702 [ 0 ] . V_703 , true ) ;
F_294 ( V_2 , V_702 [ 0 ] . V_703 ) ;
V_47 = F_292 ( V_2 , V_702 [ 0 ] . V_704 ) ;
if ( V_47 ) {
F_114 ( V_2 , L_62 ) ;
goto V_705;
}
V_47 = F_297 ( V_2 , V_702 [ 0 ] . V_296 , V_702 [ 0 ] . V_704 ,
true ) ;
if ( V_47 ) {
F_114 ( V_2 ,
L_63 ) ;
goto V_512;
}
if ( F_201 ( V_2 ) > 1 )
F_115 ( V_2 ) ;
goto V_34;
V_512:
F_294 ( V_2 , V_702 [ 0 ] . V_704 ) ;
V_705:
if ( F_292 ( V_2 , V_702 [ 0 ] . V_703 ) ) {
F_114 ( V_2 , L_64 ) ;
goto V_706;
}
if ( F_297 ( V_2 , V_702 [ 0 ] . V_296 , V_702 [ 0 ] . V_703 ,
true ) ) {
F_114 ( V_2 , L_65 ) ;
goto V_706;
}
goto V_34;
V_706:
F_305 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_306 ( struct V_1 * V_2 ,
struct V_701 * V_702 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_300 ( V_2 , V_702 [ 0 ] . V_296 , V_702 [ 0 ] . V_703 , true ) ;
V_47 = F_297 ( V_2 , V_702 [ 0 ] . V_296 , V_702 [ 0 ] . V_704 ,
true ) ;
if ( V_47 ) {
F_114 ( V_2 ,
L_63 ) ;
goto V_705;
}
goto V_34;
V_705:
if ( F_297 ( V_2 , V_702 [ 0 ] . V_296 , V_702 [ 0 ] . V_703 ,
true ) ) {
F_114 ( V_2 , L_65 ) ;
goto V_706;
}
goto V_34;
V_706:
F_305 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_307 ( struct V_29 * V_30 ,
struct V_701 * V_702 ,
int V_707 ,
enum V_708 V_709 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_707 > 1 )
return - V_614 ;
switch ( V_709 ) {
case V_710 :
V_47 = F_304 ( V_2 , V_702 ) ;
break;
case V_711 :
V_47 = F_306 ( V_2 , V_702 ) ;
break;
default:
V_47 = - V_614 ;
break;
}
return V_47 ;
}
static int F_308 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
return V_2 -> V_712 ;
}
static int F_309 ( struct V_29 * V_30 ,
struct V_265 * V_266 ,
bool V_713 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_136 * V_563 = F_62 ( V_266 ) ;
if ( ! V_563 || ! V_563 -> V_296 ) {
F_114 ( V_2 , L_66 ) ;
return - V_329 ;
}
return F_198 ( V_2 , V_563 -> V_296 ) ;
}
static int F_310 ( struct V_1 * V_2 ,
struct V_295 * V_296 ,
void * V_283 , int V_381 )
{
struct V_714 * V_715 [ V_716 + 1 ] ;
int V_717 ;
T_1 V_407 ;
V_717 = F_311 ( V_715 , V_716 , V_283 , V_381 , V_718 ,
NULL ) ;
if ( V_717 )
return V_717 ;
if ( ! V_715 [ V_719 ] )
return - V_329 ;
switch ( F_312 ( V_715 [ V_719 ] ) ) {
case V_720 :
if ( ! V_296 || V_296 -> type != V_143 || ! V_296 -> V_396 ||
! V_296 -> V_414 . V_721 ||
! V_715 [ V_722 ] )
return - V_329 ;
V_407 = F_312 ( V_715 [ V_722 ] ) ;
if ( V_407 >= V_296 -> V_414 . V_492 )
return - V_329 ;
V_2 -> V_407 = V_407 ;
V_2 -> V_406 = V_296 ;
return F_113 ( V_2 , false , NULL ) ;
case V_723 :
if ( ! V_296 || V_296 -> type != V_121 ||
! V_296 -> V_414 . V_415 || ! V_296 -> V_414 . V_654 ||
! V_715 [ V_724 ] )
return - V_329 ;
if ( F_312 ( V_715 [ V_724 ] ) )
return F_195 ( V_2 , V_296 , 0 ) ;
return F_140 ( V_2 , V_296 , 0 ) ;
}
return - V_614 ;
}
static int F_313 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
void * V_283 , int V_381 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_717 ;
F_87 ( & V_2 -> V_33 ) ;
V_717 = F_310 ( V_2 , V_296 , V_283 , V_381 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_717 ;
}
static void F_314 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_725 * V_726 )
{
F_167 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_315 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_725 * V_726 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_295 * V_517 ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
T_1 V_670 ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_331 -> V_727 = false ;
F_167 ( V_2 , L_68 ,
V_726 -> V_681 . V_728 ) ;
F_316 ( V_2 , V_296 , V_729 ) ;
switch ( V_296 -> type ) {
case V_143 :
V_517 =
F_266 ( V_2 -> V_517 ,
F_267 ( & V_2 -> V_33 ) ) ;
if ( F_118 ( V_517 && V_517 -> V_730 ,
L_69 ) ) {
V_47 = - V_585 ;
goto V_390;
}
if ( F_266 ( V_2 -> V_519 ,
F_267 ( & V_2 -> V_33 ) ) ) {
V_47 = - V_585 ;
goto V_390;
}
F_235 ( V_2 -> V_517 , V_296 ) ;
if ( F_118 ( V_331 -> V_518 ,
L_70 ) ) {
V_47 = - V_585 ;
goto V_390;
}
V_331 -> V_731 = V_726 -> V_681 . V_732 -> V_733 ;
break;
case V_121 :
if ( V_331 -> V_487 )
F_185 ( V_296 ,
V_488 ,
0 , 0 ) ;
V_670 = V_726 -> V_734 +
( ( V_296 -> V_414 . V_492 * ( V_726 -> V_417 - 1 ) -
V_735 ) * 1024 ) ;
if ( V_726 -> V_736 )
F_317 ( V_2 , V_296 ) ;
F_318 ( V_2 , V_296 , V_296 -> V_414 . V_492 ,
V_670 ) ;
if ( V_331 -> V_337 . V_508 ) {
V_47 = F_140 ( V_2 , V_296 , 0 ) ;
if ( V_47 )
goto V_390;
}
break;
default:
break;
}
V_331 -> V_343 = true ;
V_47 = F_319 ( V_2 ) ;
if ( V_47 )
goto V_390;
F_115 ( V_2 ) ;
V_390:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_320 ( struct V_29 * V_30 ,
struct V_295 * V_296 )
{
struct V_138 * V_331 = F_95 ( V_296 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_331 -> V_727 ) {
V_331 -> V_727 = false ;
V_47 = - V_17 ;
goto V_390;
}
if ( V_296 -> type == V_121 ) {
struct V_136 * V_269 ;
V_269 = F_321 ( V_2 ,
V_331 -> V_333 ) ;
if ( F_8 ( ! V_269 ) ) {
V_47 = - V_17 ;
goto V_390;
}
F_322 ( V_2 , V_269 , false ) ;
F_170 ( V_2 , V_296 , false , NULL ) ;
V_47 = F_195 ( V_2 , V_296 , 0 ) ;
if ( V_47 )
goto V_390;
F_323 ( V_2 , V_296 ) ;
}
V_331 -> V_343 = false ;
V_47 = F_319 ( V_2 ) ;
V_390:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_324 ( struct V_29 * V_30 ,
struct V_295 * V_296 , T_1 V_82 , bool V_284 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 ;
struct V_136 * V_269 ;
struct V_265 * V_266 ;
int V_9 ;
T_1 V_737 = 0 ;
if ( ! V_296 || V_296 -> type != V_121 )
return;
if ( F_41 ( V_2 ) )
F_121 ( & V_2 -> V_367 ) ;
F_87 ( & V_2 -> V_33 ) ;
V_331 = F_95 ( V_296 ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_2 -> V_558 ) ; V_9 ++ ) {
V_266 = F_266 ( V_2 -> V_558 [ V_9 ] ,
F_267 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_266 ) )
continue;
V_269 = F_62 ( V_266 ) ;
if ( V_269 -> V_296 != V_296 )
continue;
F_8 ( V_9 != V_331 -> V_333 && ! V_266 -> V_583 ) ;
if ( V_284 ) {
if ( F_325 ( V_2 , V_269 , false , 0 ) )
F_114 ( V_2 , L_71 ) ;
} else {
V_737 |= V_269 -> V_738 ;
if ( F_262 ( V_2 ) )
F_326 ( V_2 , V_269 ) ;
}
}
F_93 ( & V_2 -> V_33 ) ;
if ( ! V_284 && ! F_262 ( V_2 ) )
F_151 ( V_2 -> V_7 , V_737 ) ;
}
static int F_327 ( struct V_29 * V_30 , int V_739 ,
struct V_740 * V_741 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_741 , 0 , sizeof( * V_741 ) ) ;
if ( V_739 != 0 )
return - V_49 ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_742 ) )
return - V_49 ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_328 ( V_2 ) ) {
V_47 = F_186 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_741 -> V_743 = V_744 |
V_745 |
V_746 |
V_747 ;
V_741 -> time = V_2 -> V_362 . V_748 +
V_2 -> V_749 . V_748 ;
F_329 ( V_741 -> time , V_750 ) ;
V_741 -> V_751 = V_2 -> V_362 . V_752 +
V_2 -> V_749 . V_752 ;
F_329 ( V_741 -> V_751 , V_750 ) ;
V_741 -> V_753 = V_2 -> V_362 . V_754 +
V_2 -> V_749 . V_754 ;
F_329 ( V_741 -> V_753 , V_750 ) ;
V_741 -> V_755 = V_2 -> V_362 . V_756 +
V_2 -> V_749 . V_756 ;
F_329 ( V_741 -> V_755 , V_750 ) ;
V_47 = 0 ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_330 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
struct V_265 * V_266 ,
struct V_757 * V_758 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_138 * V_331 = F_95 ( V_296 ) ;
struct V_136 * V_269 = F_62 ( V_266 ) ;
if ( V_269 -> V_759 ) {
V_758 -> V_760 = V_269 -> V_759 ;
V_758 -> V_743 |= F_45 ( V_761 ) ;
}
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_742 ) )
return;
if ( ! ( V_296 -> V_397 & V_398 ) )
return;
if ( ! V_296 -> V_414 . V_415 )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_331 -> V_333 != V_269 -> V_272 )
goto V_762;
if ( F_186 ( V_2 , false ) )
goto V_762;
V_758 -> V_763 = V_331 -> V_387 . V_389 +
V_331 -> V_387 . V_388 ;
V_758 -> V_743 |= F_45 ( V_764 ) ;
if ( V_331 -> V_387 . V_765 ) {
V_758 -> V_766 = V_331 -> V_387 . V_765 ;
V_758 -> V_743 |= F_45 ( V_767 ) ;
}
V_762:
F_93 ( & V_2 -> V_33 ) ;
}
static void F_331 ( struct V_1 * V_2 ,
struct V_295 * V_296 ,
const struct V_768 * V_769 )
{
#define F_332 ( T_5 , T_6 ... ) \
do { \
if ((trig_mlme->_cnt) && --(trig_mlme->_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(mvm, trig, _fmt); \
} while (0)
struct V_301 * V_302 ;
struct V_770 * V_771 ;
if ( ! F_81 ( V_2 -> V_72 , V_772 ) )
return;
V_302 = F_82 ( V_2 -> V_72 , V_772 ) ;
V_771 = ( void * ) V_302 -> V_283 ;
if ( ! F_83 ( V_2 , V_296 , V_302 ) )
return;
if ( V_769 -> V_773 . V_774 . V_283 == V_775 ) {
if ( V_769 -> V_773 . V_774 . V_15 == V_776 )
F_332 ( V_777 ,
L_72 ,
V_769 -> V_773 . V_774 . V_541 ) ;
else if ( V_769 -> V_773 . V_774 . V_15 == V_778 )
F_332 ( V_779 ,
L_73 ) ;
} else if ( V_769 -> V_773 . V_774 . V_283 == V_780 ) {
if ( V_769 -> V_773 . V_774 . V_15 == V_776 )
F_332 ( V_781 ,
L_74 ,
V_769 -> V_773 . V_774 . V_541 ) ;
else if ( V_769 -> V_773 . V_774 . V_15 == V_778 )
F_332 ( V_782 ,
L_75 ) ;
} else if ( V_769 -> V_773 . V_774 . V_283 == V_783 ) {
F_332 ( V_784 ,
L_76 , V_769 -> V_773 . V_774 . V_541 ) ;
} else if ( V_769 -> V_773 . V_774 . V_283 == V_785 ) {
F_332 ( V_786 ,
L_77 , V_769 -> V_773 . V_774 . V_541 ) ;
}
#undef F_332
}
static void F_333 ( struct V_1 * V_2 ,
struct V_295 * V_296 ,
const struct V_768 * V_769 )
{
struct V_301 * V_302 ;
struct V_303 * V_304 ;
if ( ! F_81 ( V_2 -> V_72 , V_305 ) )
return;
V_302 = F_82 ( V_2 -> V_72 , V_305 ) ;
V_304 = ( void * ) V_302 -> V_283 ;
if ( ! F_83 ( V_2 , V_296 , V_302 ) )
return;
if ( ! ( F_334 ( V_304 -> V_787 ) & F_45 ( V_769 -> V_773 . V_788 . V_297 ) ) )
return;
F_240 ( V_2 , V_302 ,
L_78 ,
V_769 -> V_773 . V_788 . V_266 -> V_164 , V_769 -> V_773 . V_788 . V_297 ,
V_769 -> V_773 . V_788 . V_310 ) ;
}
static void
F_335 ( struct V_1 * V_2 ,
struct V_295 * V_296 ,
const struct V_768 * V_769 )
{
struct V_301 * V_302 ;
struct V_303 * V_304 ;
if ( ! F_81 ( V_2 -> V_72 , V_305 ) )
return;
V_302 = F_82 ( V_2 -> V_72 , V_305 ) ;
V_304 = ( void * ) V_302 -> V_283 ;
if ( ! F_83 ( V_2 , V_296 , V_302 ) )
return;
if ( ! ( F_334 ( V_304 -> V_789 ) & F_45 ( V_769 -> V_773 . V_788 . V_297 ) ) )
return;
F_240 ( V_2 , V_302 ,
L_79 ,
V_769 -> V_773 . V_788 . V_266 -> V_164 , V_769 -> V_773 . V_788 . V_297 ) ;
}
static void F_336 ( struct V_29 * V_30 ,
struct V_295 * V_296 ,
const struct V_768 * V_769 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_769 -> type ) {
case V_790 :
F_331 ( V_2 , V_296 , V_769 ) ;
break;
case V_791 :
F_333 ( V_2 , V_296 , V_769 ) ;
break;
case V_792 :
F_335 ( V_2 , V_296 , V_769 ) ;
break;
default:
break;
}
}
void F_337 ( struct V_1 * V_2 ,
struct V_793 * V_479 ,
T_1 V_794 )
{
T_1 V_795 = F_45 ( V_2 -> V_7 -> V_76 ) - 1 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! F_39 ( V_2 ) || F_262 ( V_2 ) )
return;
V_479 -> V_796 = V_2 -> V_797 ;
if ( V_479 -> V_798 )
F_338 ( & V_2 -> V_799 ,
V_2 -> V_7 -> V_76 ) ;
V_47 = F_339 ( V_2 , V_795 , ( T_2 * ) V_479 , V_794 ) ;
if ( V_47 ) {
F_114 ( V_2 , L_80 , V_47 ) ;
goto V_34;
}
if ( V_479 -> V_798 ) {
V_47 = F_13 ( V_2 -> V_800 ,
F_220 ( & V_2 -> V_799 ) == 0 ||
F_68 ( V_2 ) ,
V_16 ) ;
F_15 ( ! V_47 && ! F_68 ( V_2 ) ) ;
}
V_34:
F_338 ( & V_2 -> V_799 , 0 ) ;
V_2 -> V_797 ++ ;
}
static void F_340 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_793 V_283 = {
. type = V_801 ,
. V_798 = 1 ,
} ;
F_87 ( & V_2 -> V_33 ) ;
F_337 ( V_2 , & V_283 , sizeof( V_283 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
