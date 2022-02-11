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
V_30 -> V_93 = L_9 ;
V_30 -> V_94 = V_95 ;
V_30 -> V_96 = V_97 ;
F_42 ( F_43 ( V_2 -> V_98 ) < F_43 ( V_51 ) + 6 ) ;
memcpy ( V_2 -> V_98 , V_51 , sizeof( V_51 ) ) ;
V_30 -> V_23 -> V_99 = F_43 ( V_51 ) ;
V_30 -> V_23 -> V_100 = V_2 -> V_98 ;
if ( F_39 ( V_2 ) ) {
V_2 -> V_98 [ V_30 -> V_23 -> V_99 ] =
V_101 ;
V_30 -> V_23 -> V_99 ++ ;
V_2 -> V_98 [ V_30 -> V_23 -> V_99 ] =
V_102 ;
V_30 -> V_23 -> V_99 ++ ;
}
if ( ! V_103 . V_104 ) {
F_38 ( V_30 , V_105 ) ;
V_2 -> V_98 [ V_30 -> V_23 -> V_99 ] =
V_106 ;
V_30 -> V_23 -> V_99 ++ ;
if ( F_39 ( V_2 ) ) {
V_2 -> V_98 [ V_30 -> V_23 -> V_99 ] =
V_107 ;
V_30 -> V_23 -> V_99 ++ ;
V_2 -> V_98 [ V_30 -> V_23 -> V_99 ] =
V_108 ;
V_30 -> V_23 -> V_99 ++ ;
}
}
if ( V_2 -> V_72 -> V_109 [ 0 ] . V_110 ) {
const struct V_111 * V_112 = & V_2 -> V_72 -> V_109 [ 0 ] ;
struct V_113 * V_109 = & V_2 -> V_109 [ 0 ] ;
V_2 -> V_30 -> V_114 = 1 ;
V_109 -> V_110 = F_44 ( V_112 -> V_110 ) ;
V_109 -> V_115 = F_45 ( V_116 ) ;
V_109 -> V_117 = V_112 -> V_117 ;
V_109 -> V_118 = V_112 -> V_118 ;
V_109 -> V_119 = V_112 -> V_119 ;
V_109 -> V_120 = V_112 -> V_120 ;
V_109 -> V_121 = V_112 -> V_121 ;
V_109 -> V_122 = V_112 -> V_122 ;
V_109 -> V_123 = V_112 -> V_123 ;
V_2 -> V_30 -> V_124 = V_2 -> V_109 ;
V_2 -> V_98 [ V_30 -> V_23 -> V_99 ] = V_109 -> V_110 ;
V_30 -> V_23 -> V_99 ++ ;
}
F_38 ( V_30 , V_125 ) ;
V_30 -> V_23 -> V_126 |=
V_127 |
V_128 |
V_129 ;
V_30 -> V_130 = sizeof( struct V_131 ) ;
V_30 -> V_132 = sizeof( struct V_133 ) ;
V_30 -> V_134 = sizeof( V_135 ) ;
V_30 -> V_23 -> V_136 = F_45 ( V_116 ) |
F_45 ( V_137 ) |
F_45 ( V_138 ) |
F_45 ( V_139 ) |
F_45 ( V_140 ) |
F_45 ( V_141 ) ;
V_30 -> V_23 -> V_142 |= V_143 ;
V_30 -> V_23 -> V_144 |= V_145 ;
if ( F_30 ( V_2 ) )
V_30 -> V_23 -> V_144 |= V_146 ;
else
V_30 -> V_23 -> V_144 |= V_147 |
V_148 ;
V_30 -> V_23 -> V_142 |= V_149 ;
V_30 -> V_23 -> V_142 |= V_150 ;
V_30 -> V_23 -> V_151 = V_152 ;
V_30 -> V_23 -> V_153 =
F_43 ( V_152 ) ;
V_30 -> V_23 -> V_154 = 10000 ;
V_30 -> V_155 = V_156 ;
V_30 -> V_23 -> V_157 = 3 * 5 ;
memcpy ( V_2 -> V_158 [ 0 ] . V_159 , V_2 -> V_160 -> V_161 , V_162 ) ;
V_30 -> V_23 -> V_158 = V_2 -> V_158 ;
V_30 -> V_23 -> V_163 = 1 ;
V_50 = ( V_2 -> V_160 -> V_164 > 1 ) ?
F_46 ( V_165 , V_2 -> V_160 -> V_164 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_50 ; V_9 ++ ) {
memcpy ( V_2 -> V_158 [ V_9 ] . V_159 , V_2 -> V_158 [ V_9 - 1 ] . V_159 ,
V_162 ) ;
V_2 -> V_158 [ V_9 ] . V_159 [ 5 ] ++ ;
V_30 -> V_23 -> V_163 ++ ;
}
F_16 ( V_2 ) ;
V_30 -> V_23 -> V_166 = F_47 ( V_2 ) ;
V_30 -> V_23 -> V_167 = V_168 ;
F_42 ( V_169 & V_170 ) ;
F_42 ( V_171 > F_48 ( V_170 ) ||
V_172 > F_48 ( V_170 ) ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 , V_173 ) )
V_2 -> V_174 = V_171 ;
else
V_2 -> V_174 = V_172 ;
if ( V_2 -> V_160 -> V_175 [ V_176 ] . V_38 )
V_30 -> V_23 -> V_175 [ V_176 ] =
& V_2 -> V_160 -> V_175 [ V_176 ] ;
if ( V_2 -> V_160 -> V_175 [ V_177 ] . V_38 ) {
V_30 -> V_23 -> V_175 [ V_177 ] =
& V_2 -> V_160 -> V_175 [ V_177 ] ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_178 ) &&
F_49 ( & V_2 -> V_72 -> V_73 ,
V_179 ) )
V_30 -> V_23 -> V_175 [ V_177 ] -> V_180 . V_181 |=
V_182 ;
}
V_30 -> V_23 -> V_183 = V_2 -> V_7 -> V_184 ;
if ( V_185 . V_186 != V_187 )
V_30 -> V_23 -> V_142 |= V_188 ;
else
V_30 -> V_23 -> V_142 &= ~ V_188 ;
V_30 -> V_23 -> V_142 |= V_189 ;
V_30 -> V_23 -> V_190 = V_168 ;
V_30 -> V_23 -> V_191 = V_192 ;
V_30 -> V_23 -> V_193 =
V_194 - 24 - 2 ;
V_30 -> V_23 -> V_195 = V_196 ;
V_30 -> V_23 -> V_197 = V_198 ;
V_30 -> V_23 -> V_199 = 254 ;
V_30 -> V_23 -> V_126 |= V_200 |
V_201 |
V_202 |
V_203 |
V_204 |
V_205 |
V_206 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_207 ) )
V_30 -> V_23 -> V_126 |= V_208 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_209 ) )
V_30 -> V_23 -> V_126 |= V_210 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_211 ) )
V_30 -> V_23 -> V_126 |=
V_212 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_213 ) )
V_30 -> V_23 -> V_126 |= V_214 ;
if ( F_49 ( & V_2 -> V_72 -> V_73 ,
V_215 ) ) {
F_50 ( V_30 -> V_23 ,
V_216 ) ;
F_50 ( V_30 -> V_23 ,
V_217 ) ;
F_50 ( V_30 -> V_23 ,
V_218 ) ;
}
V_2 -> V_219 = V_220 ;
#ifdef F_51
if ( F_2 ( V_2 ) &&
F_52 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_221 . V_142 = V_222 ;
V_30 -> V_23 -> V_221 = & V_2 -> V_221 ;
}
if ( V_2 -> V_72 -> V_223 [ V_224 ] . V_225 [ 0 ] . V_226 &&
V_2 -> V_7 -> V_227 -> V_228 &&
V_2 -> V_7 -> V_227 -> V_229 &&
F_52 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_221 . V_142 |= V_230 |
V_231 |
V_232 |
V_233 |
V_234 ;
if ( ! V_103 . V_104 )
V_2 -> V_221 . V_142 |= V_235 |
V_236 |
V_237 ;
V_2 -> V_221 . V_238 = V_239 ;
V_2 -> V_221 . V_240 = V_241 ;
V_2 -> V_221 . V_242 = V_243 ;
V_2 -> V_221 . V_244 = V_192 ;
V_2 -> V_221 . V_245 = & V_246 ;
V_30 -> V_23 -> V_221 = & V_2 -> V_221 ;
}
#endif
#ifdef F_53
V_2 -> V_247 = V_248 ;
#endif
V_47 = F_54 ( V_2 ) ;
if ( V_47 )
return V_47 ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_249 ) ) {
F_55 ( V_2 , L_10 ) ;
V_30 -> V_23 -> V_142 |= V_250 ;
F_38 ( V_30 , V_251 ) ;
}
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_252 ) ) {
F_55 ( V_2 , L_11 ) ;
V_30 -> V_23 -> V_126 |= V_253 ;
}
V_30 -> V_79 |= V_2 -> V_37 -> V_126 ;
if ( ! F_56 ( V_2 ) ) {
V_30 -> V_79 &= ~ ( V_254 |
V_255 ) ;
if ( V_256 )
V_30 -> V_79 |= V_254 ;
}
V_47 = F_57 ( V_2 -> V_30 ) ;
if ( V_47 )
F_58 ( V_2 ) ;
if ( V_2 -> V_37 -> V_257 )
F_50 ( V_30 -> V_23 ,
V_258 ) ;
return V_47 ;
}
static bool F_59 ( struct V_1 * V_2 ,
struct V_259 * V_260 ,
struct V_261 * V_262 )
{
struct V_131 * V_263 ;
bool V_264 = false ;
if ( F_60 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_61 ( & V_2 -> V_265 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_34;
V_263 = F_62 ( V_260 ) ;
if ( V_263 -> V_266 == V_267 ||
V_263 -> V_266 != V_2 -> V_268 )
goto V_34;
F_63 ( & V_2 -> V_269 , V_262 ) ;
F_64 ( V_2 -> V_30 ) ;
F_1 ( V_2 , V_270 ) ;
F_7 ( V_2 , V_270 ) ;
V_264 = true ;
V_34:
F_65 ( & V_2 -> V_265 ) ;
return V_264 ;
}
static void F_66 ( struct V_29 * V_30 ,
struct V_271 * V_272 ,
struct V_261 * V_262 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_259 * V_260 = V_272 -> V_260 ;
struct V_273 * V_274 = F_67 ( V_262 ) ;
struct V_275 * V_276 = ( void * ) V_262 -> V_277 ;
if ( F_68 ( V_2 ) ) {
F_69 ( V_2 , L_12 ) ;
goto V_278;
}
if ( F_67 ( V_262 ) -> V_279 == V_86 &&
! F_14 ( V_280 , & V_2 -> V_15 ) &&
! F_14 ( V_281 , & V_2 -> V_15 ) )
goto V_278;
if ( F_70 ( V_274 -> V_142 & V_282 &&
F_71 ( V_276 -> V_283 ) &&
! F_72 ( V_276 -> V_283 ) &&
! F_73 ( V_276 -> V_283 ) &&
! F_74 ( V_276 -> V_283 ) ) )
V_260 = NULL ;
if ( V_260 ) {
if ( F_59 ( V_2 , V_260 , V_262 ) )
return;
if ( F_75 ( V_2 , V_262 , V_260 ) )
goto V_278;
return;
}
if ( F_76 ( V_2 , V_262 ) )
goto V_278;
return;
V_278:
F_77 ( V_30 , V_262 ) ;
}
static inline bool F_78 ( const struct V_284 * V_37 )
{
if ( V_103 . V_285 & V_286 )
return false ;
return true ;
}
static inline bool F_79 ( const struct V_284 * V_37 )
{
if ( V_103 . V_285 & V_287 )
return false ;
if ( V_103 . V_285 & V_288 )
return true ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 , struct V_289 * V_290 ,
struct V_259 * V_260 , V_135 V_291 , V_135 V_292 ,
enum V_293 V_294 )
{
struct V_295 * V_296 ;
struct V_297 * V_298 ;
if ( ! F_81 ( V_2 -> V_72 , V_299 ) )
return;
V_296 = F_82 ( V_2 -> V_72 , V_299 ) ;
V_298 = ( void * ) V_296 -> V_277 ;
if ( ! F_83 ( V_2 , V_290 , V_296 ) )
return;
switch ( V_294 ) {
case V_300 : {
struct V_131 * V_263 = F_62 ( V_260 ) ;
struct V_301 * V_302 = & V_263 -> V_302 [ V_291 ] ;
F_84 ( V_2 , V_296 , V_298 -> V_303 , V_291 ,
L_13 ,
V_260 -> V_159 , V_291 , V_302 -> V_304 ) ;
break;
}
case V_305 :
F_84 ( V_2 , V_296 , V_298 -> V_306 , V_291 ,
L_14 ,
V_260 -> V_159 , V_291 ) ;
break;
case V_307 :
F_84 ( V_2 , V_296 , V_298 -> V_308 , V_291 ,
L_15 ,
V_260 -> V_159 , V_291 , V_292 ) ;
break;
case V_309 :
F_84 ( V_2 , V_296 , V_298 -> V_310 , V_291 ,
L_16 ,
V_260 -> V_159 , V_291 ) ;
break;
default:
break;
}
}
static int F_85 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_311 * V_312 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_313 = false ;
struct V_259 * V_260 = V_312 -> V_260 ;
enum V_293 V_294 = V_312 -> V_294 ;
V_135 V_291 = V_312 -> V_291 ;
V_135 * V_304 = & V_312 -> V_304 ;
T_2 V_314 = V_312 -> V_314 ;
bool V_315 = V_312 -> V_315 ;
V_135 V_316 = V_312 -> V_316 ;
F_86 ( V_2 , L_17 ,
V_260 -> V_159 , V_291 , V_294 ) ;
if ( ! ( V_2 -> V_160 -> V_317 ) )
return - V_318 ;
switch ( V_294 ) {
case V_319 :
case V_305 :
case V_320 :
case V_321 :
case V_300 :
V_47 = F_12 ( V_2 , V_322 ) ;
if ( V_47 )
return V_47 ;
V_313 = true ;
break;
default:
break;
}
F_87 ( & V_2 -> V_33 ) ;
switch ( V_294 ) {
case V_307 :
if ( ! F_78 ( V_2 -> V_37 ) ) {
V_47 = - V_323 ;
break;
}
V_47 = F_88 ( V_2 , V_260 , V_291 , * V_304 , true , V_314 ,
V_316 ) ;
break;
case V_309 :
V_47 = F_88 ( V_2 , V_260 , V_291 , 0 , false , V_314 ,
V_316 ) ;
break;
case V_319 :
if ( ! F_79 ( V_2 -> V_37 ) ) {
V_47 = - V_323 ;
break;
}
V_47 = F_89 ( V_2 , V_290 , V_260 , V_291 , V_304 ) ;
break;
case V_305 :
V_47 = F_90 ( V_2 , V_290 , V_260 , V_291 ) ;
break;
case V_320 :
case V_321 :
V_47 = F_91 ( V_2 , V_290 , V_260 , V_291 ) ;
break;
case V_300 :
V_47 = F_92 ( V_2 , V_290 , V_260 , V_291 ,
V_314 , V_315 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_323 ;
break;
}
if ( ! V_47 ) {
V_135 V_292 = 0 ;
if ( V_294 == V_307 )
V_292 = * V_304 ;
F_80 ( V_2 , V_290 , V_260 , V_291 ,
V_292 , V_294 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
if ( V_313 )
F_7 ( V_2 , V_322 ) ;
return V_47 ;
}
static void F_94 ( void * V_277 , T_2 * V_324 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = V_277 ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
V_325 -> V_326 = false ;
V_325 -> V_327 = V_267 ;
F_4 ( & V_2 -> V_328 ) ;
F_96 ( V_2 , & V_325 -> V_329 ) ;
F_5 ( & V_2 -> V_328 ) ;
V_325 -> V_330 = NULL ;
memset ( & V_325 -> V_331 , 0 , sizeof( V_325 -> V_331 ) ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
if ( ! F_98 ( V_332 , & V_2 -> V_15 ) ) {
V_2 -> V_333 = & V_334 ;
F_99 ( V_2 ) ;
}
F_10 ( V_2 , V_335 ) ;
F_100 ( V_2 ) ;
V_2 -> V_336 = 0 ;
V_2 -> V_337 = false ;
V_2 -> V_338 = false ;
F_101 ( V_2 ) ;
F_102 ( V_2 -> V_30 ) ;
F_103 ( V_2 -> V_30 , 0 , F_94 , V_2 ) ;
V_2 -> V_339 = NULL ;
V_2 -> V_268 = V_267 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_340 , 0 , sizeof( V_2 -> V_340 ) ) ;
memset ( V_2 -> V_341 , 0 , sizeof( V_2 -> V_341 ) ) ;
memset ( V_2 -> V_342 , 0 , sizeof( V_2 -> V_342 ) ) ;
memset ( V_2 -> V_343 , 0 , sizeof( V_2 -> V_343 ) ) ;
memset ( & V_2 -> V_344 , 0 , sizeof( V_2 -> V_344 ) ) ;
memset ( & V_2 -> V_345 , 0 , sizeof( V_2 -> V_345 ) ) ;
F_104 ( V_2 -> V_30 ) ;
F_105 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_346 = 0 ;
V_2 -> V_347 = 0 ;
V_2 -> V_348 = V_349 ;
F_106 ( V_2 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_350 , & V_2 -> V_15 ) ) {
F_97 ( V_2 ) ;
} else {
F_1 ( V_2 , V_335 ) ;
}
V_47 = F_108 ( V_2 ) ;
if ( V_47 && F_14 ( V_350 , & V_2 -> V_15 ) ) {
F_105 ( V_350 , & V_2 -> V_15 ) ;
F_109 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_110 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_350 , & V_2 -> V_15 ) ) {
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
F_105 ( V_350 , & V_2 -> V_15 ) ;
F_109 ( V_2 , NULL ) ;
V_47 = F_112 ( V_2 , true , NULL ) ;
if ( V_47 )
F_113 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_335 ) ;
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
enum V_351 V_352 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_352 ) {
case V_353 :
F_111 ( V_2 ) ;
break;
case V_354 :
F_115 ( V_2 ) ;
break;
}
}
void F_119 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_355 , 0 , sizeof( V_2 -> V_355 ) ) ;
F_120 ( & V_2 -> V_356 ) ;
F_100 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
if ( F_98 ( V_350 , & V_2 -> V_15 ) )
F_103 ( V_2 -> V_30 , 0 ,
F_94 , V_2 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 , V_173 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_174 ; V_9 ++ ) {
if ( F_117 ( V_2 -> V_357 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_357 [ V_9 ] = 0 ;
}
}
}
static void F_124 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_120 ( & V_2 -> V_358 ) ;
F_120 ( & V_2 -> V_359 ) ;
F_120 ( & V_2 -> V_360 ) ;
F_125 ( & V_2 -> V_361 ) ;
F_125 ( & V_2 -> V_362 ) ;
F_125 ( & V_2 -> V_363 ) ;
F_126 ( V_2 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_119 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_127 ( & V_2 -> V_359 ) ;
}
static struct V_364 * F_128 ( struct V_1 * V_2 )
{
V_135 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_113 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_129 ( struct V_1 * V_2 , struct V_289 * V_290 ,
T_3 V_365 )
{
struct V_366 V_367 = {
. V_368 . V_369 = F_130 ( V_370 ) ,
. V_368 . V_371 =
F_130 ( F_95 ( V_290 ) -> V_20 ) ,
. V_368 . V_372 = F_131 ( 8 * V_365 ) ,
} ;
int V_226 = sizeof( V_367 ) ;
if ( V_365 == V_373 )
V_367 . V_368 . V_372 = F_131 ( V_374 ) ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 , V_375 ) )
V_226 = sizeof( V_367 . V_368 ) ;
return F_132 ( V_2 , V_376 , 0 , V_226 , & V_367 ) ;
}
static int F_133 ( struct V_29 * V_30 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
int V_47 ;
V_325 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_377 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_350 , & V_2 -> V_15 ) )
V_325 -> V_378 . V_379 +=
V_325 -> V_378 . V_380 ;
V_47 = F_134 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_381;
if ( V_290 -> type != V_140 )
V_2 -> V_346 ++ ;
if ( V_290 -> type == V_138 ||
V_290 -> type == V_141 ) {
V_47 = F_135 ( V_2 , V_290 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_22 ) ;
goto V_382;
}
F_136 ( V_2 , V_290 ) ;
goto V_381;
}
V_325 -> V_126 |= V_30 -> V_79 ;
V_47 = F_137 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_382;
V_47 = F_138 ( V_2 ) ;
if ( V_47 )
goto V_383;
V_47 = F_139 ( V_2 , V_290 , 0 ) ;
if ( V_47 )
goto V_383;
if ( ! V_2 -> V_384 &&
V_290 -> type == V_116 && ! V_290 -> V_385 ) {
V_2 -> V_384 = V_325 ;
V_290 -> V_386 |= V_387 |
V_388 ;
}
if ( V_290 -> type == V_140 ) {
V_325 -> V_330 = F_128 ( V_2 ) ;
if ( ! V_325 -> V_330 ) {
V_47 = - V_389 ;
goto V_390;
}
F_140 ( V_2 , V_325 -> V_330 ) ;
V_47 = F_141 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_391;
V_47 = F_142 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_392;
V_2 -> V_339 = V_290 ;
}
F_136 ( V_2 , V_290 ) ;
goto V_381;
V_392:
F_143 ( V_2 , V_290 ) ;
V_391:
F_144 ( V_2 , V_325 -> V_330 ) ;
V_390:
if ( V_2 -> V_384 == V_325 ) {
V_2 -> V_384 = NULL ;
V_290 -> V_386 &= ~ ( V_387 |
V_388 ) ;
}
V_383:
V_325 -> V_330 = NULL ;
F_145 ( V_2 , V_290 ) ;
V_382:
if ( V_290 -> type != V_140 )
V_2 -> V_346 -- ;
F_146 ( V_2 , V_290 ) ;
V_381:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_377 ) ;
return V_47 ;
}
static void F_147 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
T_1 V_393 = F_148 ( V_290 ) ;
if ( V_393 ) {
F_87 ( & V_2 -> V_33 ) ;
F_149 ( V_2 , V_393 , 0 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_150 ( V_2 -> V_7 , V_393 ) ;
}
if ( V_290 -> type == V_140 ) {
F_120 ( & V_2 -> V_356 ) ;
} else {
F_120 ( & V_2 -> V_394 ) ;
}
}
static void F_151 ( struct V_29 * V_30 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
F_147 ( V_2 , V_290 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_384 == V_325 ) {
V_2 -> V_384 = NULL ;
V_290 -> V_386 &= ~ ( V_387 |
V_388 ) ;
}
F_152 ( V_2 , V_290 ) ;
if ( V_290 -> type == V_138 ||
V_290 -> type == V_141 ) {
#ifdef F_153
if ( V_290 == V_2 -> V_395 ) {
V_2 -> V_395 = NULL ;
V_2 -> V_396 = 0 ;
}
#endif
F_154 ( V_2 , V_290 ) ;
goto V_382;
}
if ( V_290 -> type == V_140 ) {
V_2 -> V_339 = NULL ;
F_155 ( V_2 , V_290 ) ;
F_143 ( V_2 , V_290 ) ;
F_144 ( V_2 , V_325 -> V_330 ) ;
V_325 -> V_330 = NULL ;
}
if ( V_2 -> V_346 && V_290 -> type != V_140 )
V_2 -> V_346 -- ;
F_138 ( V_2 ) ;
F_145 ( V_2 , V_290 ) ;
V_382:
F_146 ( V_2 , V_290 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_156 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_157 ( void * V_397 , T_2 * V_324 ,
struct V_289 * V_290 )
{
struct V_398 * V_277 = V_397 ;
struct V_1 * V_2 = V_277 -> V_2 ;
struct V_399 * V_367 = V_2 -> V_400 ;
int V_47 , V_226 ;
if ( F_15 ( V_277 -> V_401 >= V_402 ) )
return;
if ( V_290 -> type != V_116 ||
! V_290 -> V_403 . V_404 )
return;
V_367 -> V_401 = V_277 -> V_401 ++ ;
memcpy ( V_367 -> V_405 , V_290 -> V_403 . V_405 , V_162 ) ;
V_226 = F_158 ( sizeof( * V_367 ) + V_367 -> V_406 * V_162 , 4 ) ;
V_47 = F_132 ( V_2 , V_407 , V_408 , V_226 , V_367 ) ;
if ( V_47 )
F_113 ( V_2 , L_23 , V_47 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_398 V_409 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_400 ) )
return;
F_160 (
V_2 -> V_30 , V_410 ,
F_157 , & V_409 ) ;
}
static T_4 F_161 ( struct V_29 * V_30 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_399 * V_367 ;
struct V_413 * V_159 ;
int V_414 ;
bool V_415 ;
int V_226 ;
V_414 = F_162 ( V_412 ) ;
V_415 = V_414 > V_416 ||
V_417 ;
if ( V_415 )
V_414 = 0 ;
V_226 = F_158 ( sizeof( * V_367 ) + V_414 * V_162 , 4 ) ;
V_367 = F_163 ( V_226 , V_418 ) ;
if ( ! V_367 )
return 0 ;
if ( V_415 ) {
V_367 -> V_415 = 1 ;
return ( T_4 ) ( unsigned long ) V_367 ;
}
F_164 (addr, mc_list) {
F_165 ( V_2 , L_24 ,
V_367 -> V_406 , V_159 -> V_159 ) ;
memcpy ( & V_367 -> V_419 [ V_367 -> V_406 * V_162 ] ,
V_159 -> V_159 , V_162 ) ;
V_367 -> V_406 ++ ;
}
return ( T_4 ) ( unsigned long ) V_367 ;
}
static void F_166 ( struct V_29 * V_30 ,
unsigned int V_420 ,
unsigned int * V_421 ,
T_4 V_422 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_399 * V_367 = ( void * ) ( unsigned long ) V_422 ;
F_87 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_400 ) ;
V_2 -> V_400 = V_367 ;
if ( ! V_367 )
goto V_34;
F_159 ( V_2 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
* V_421 = 0 ;
}
static void F_167 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
unsigned int V_423 ,
unsigned int V_420 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_420 & V_424 ) )
return;
if ( V_290 -> type != V_116 || ! V_290 -> V_403 . V_404 ||
! V_290 -> V_385 )
return;
F_87 ( & V_2 -> V_33 ) ;
F_168 ( V_2 , V_290 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_169 ( struct V_289 * V_290 ,
const struct V_425 * V_426 ,
struct V_425 * V_427 )
{
struct V_428 * V_429 ;
int V_9 ;
memcpy ( V_427 , V_426 , sizeof( * V_427 ) ) ;
for ( V_9 = 0 ; V_9 < F_43 ( V_427 -> V_430 ) ; V_9 ++ ) {
V_429 = & V_427 -> V_430 [ V_9 ] ;
if ( ! V_429 -> V_431 )
break;
switch ( V_429 -> V_432 ) {
case F_131 ( V_433 ) :
if ( V_290 -> V_403 . V_434 != 1 ) {
V_429 -> V_431 = 0 ;
continue;
}
V_429 -> V_435 = V_290 -> V_403 . V_436 [ 0 ] ;
break;
case F_131 ( V_437 ) :
V_429 -> V_435 = * ( V_438 * ) & V_290 -> V_159 [ 2 ] ;
break;
default:
break;
}
V_429 -> V_432 = 0 ;
V_427 -> V_439 ++ ;
}
}
static void F_170 ( void * V_397 , T_2 * V_324 ,
struct V_289 * V_290 )
{
struct V_440 * V_277 = V_397 ;
struct V_1 * V_2 = V_277 -> V_2 ;
struct V_441 * V_367 = V_277 -> V_367 ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
struct V_442 * V_443 ;
int V_9 ;
if ( F_8 ( V_325 -> V_20 >= F_43 ( V_367 -> V_444 ) ) )
return;
V_443 = & V_367 -> V_444 [ V_325 -> V_20 ] ;
if ( V_290 -> type != V_116 || V_290 -> V_385 ||
! V_290 -> V_403 . V_404 )
return;
V_443 -> V_445 = 1 ;
for ( V_9 = 0 ; V_2 -> V_247 [ V_9 ] . V_430 [ 0 ] . V_431 ; V_9 ++ ) {
if ( F_15 ( V_277 -> V_446 >=
F_43 ( V_367 -> V_447 ) ) ) {
V_443 -> V_445 = 0 ;
V_443 -> V_448 = 0 ;
break;
}
F_169 ( V_290 ,
& V_2 -> V_247 [ V_9 ] ,
& V_367 -> V_447 [ V_277 -> V_446 ] ) ;
if ( ! V_367 -> V_447 [ V_277 -> V_446 ] . V_439 )
continue;
V_443 -> V_448 |=
F_131 ( F_45 ( V_277 -> V_446 ) ) ;
V_277 -> V_446 ++ ;
}
}
bool F_171 ( struct V_1 * V_2 ,
struct V_441 * V_367 )
{
struct V_440 V_409 = {
. V_2 = V_2 ,
. V_367 = V_367 ,
} ;
if ( V_449 )
return false ;
memset ( V_367 , 0 , sizeof( * V_367 ) ) ;
V_367 -> V_450 = F_43 ( V_367 -> V_447 ) ;
V_367 -> V_451 = F_43 ( V_367 -> V_444 ) ;
#ifdef F_172
if ( V_2 -> V_452 . V_453 ) {
memcpy ( V_367 -> V_447 , & V_2 -> V_452 . V_367 . V_447 ,
sizeof( V_367 -> V_447 ) ) ;
memcpy ( V_367 -> V_444 , & V_2 -> V_452 . V_367 . V_444 ,
sizeof( V_367 -> V_444 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_247 )
return false ;
F_173 (
V_2 -> V_30 , V_410 ,
F_170 , & V_409 ) ;
return true ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_441 V_367 ;
if ( ! ( V_2 -> V_72 -> V_73 . V_142 & V_454 ) )
return 0 ;
if ( ! F_171 ( V_2 , & V_367 ) )
return 0 ;
return F_132 ( V_2 , V_455 , 0 ,
sizeof( V_367 ) , & V_367 ) ;
}
static inline int F_174 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_175 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_456 V_367 = {} ;
memcpy ( V_367 . V_457 , V_290 -> V_403 . V_458 . V_459 ,
V_460 ) ;
memcpy ( V_367 . V_461 , V_290 -> V_403 . V_458 . V_462 ,
V_463 ) ;
return F_132 ( V_2 ,
F_176 ( V_464 ,
V_465 ) ,
0 , sizeof( V_367 ) , & V_367 ) ;
}
static void F_177 ( void * V_397 , T_2 * V_324 ,
struct V_289 * V_290 )
{
if ( V_290 -> V_466 ) {
struct V_467 * V_468 = V_397 ;
F_178 ( V_290 ,
( T_2 * ) & V_468 -> V_457 ,
( T_2 * ) & V_468 -> V_461 ) ;
}
}
void F_179 ( struct V_1 * V_2 ,
struct V_469 * V_470 )
{
struct V_471 * V_472 = F_180 ( V_470 ) ;
struct V_467 * V_468 = ( void * ) V_472 -> V_277 ;
F_160 (
V_2 -> V_30 , V_410 ,
F_177 , V_468 ) ;
}
static void F_181 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
struct V_473 * V_403 ,
T_1 V_474 )
{
struct V_133 * V_325 = F_95 ( V_290 ) ;
int V_47 ;
if ( V_474 & V_475 && V_403 -> V_404 )
F_182 ( V_2 , V_290 ) ;
if ( V_474 & V_475 && ! V_403 -> V_404 &&
V_325 -> V_476 )
F_183 ( V_290 , V_477 ,
0 , 0 ) ;
if ( V_474 & V_478 && ! V_325 -> V_479 )
memcpy ( V_325 -> V_405 , V_403 -> V_405 , V_162 ) ;
V_47 = F_168 ( V_2 , V_290 , false , V_325 -> V_405 ) ;
if ( V_47 )
F_113 ( V_2 , L_25 , V_290 -> V_159 ) ;
memcpy ( V_325 -> V_405 , V_403 -> V_405 , V_162 ) ;
V_325 -> V_479 = V_403 -> V_404 ;
if ( V_474 & V_475 ) {
if ( V_403 -> V_404 ) {
F_184 ( V_2 , true ) ;
memset ( & V_325 -> V_378 , 0 ,
sizeof( V_325 -> V_378 ) ) ;
V_47 = F_112 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_113 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_350 ,
& V_2 -> V_15 ) ) {
T_1 V_480 = ( 11 * V_290 -> V_403 . V_481 ) / 10 ;
F_185 ( V_2 , V_290 , V_480 , V_480 ,
5 * V_480 , false ) ;
}
F_186 ( V_2 , V_290 , false ) ;
F_187 ( V_2 , V_290 ) ;
if ( V_290 -> V_385 ) {
F_1 ( V_2 , V_482 ) ;
F_188 ( V_2 , V_290 ,
V_483 ,
V_484 ) ;
}
} else if ( V_325 -> V_327 != V_267 ) {
F_117 ( F_186 ( V_2 , V_290 , false ) ,
L_27 ) ;
V_47 = F_189 ( V_2 , V_290 , V_325 -> V_327 ) ;
if ( V_47 )
F_113 ( V_2 , L_28 ) ;
if ( V_2 -> V_268 == V_325 -> V_327 )
V_2 -> V_268 = V_267 ;
V_325 -> V_327 = V_267 ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
F_113 ( V_2 , L_26 ) ;
if ( V_290 -> V_385 )
F_7 ( V_2 , V_482 ) ;
V_47 = F_168 ( V_2 , V_290 , false , NULL ) ;
if ( V_47 )
F_113 ( V_2 ,
L_29 ,
V_290 -> V_159 ) ;
}
if ( F_14 ( V_350 , & V_2 -> V_15 ) &&
( V_474 & V_485 ) && V_290 -> V_466 ) {
V_47 = F_175 ( V_2 , V_290 ) ;
if ( V_47 )
F_113 ( V_2 ,
L_30 ) ;
}
F_159 ( V_2 ) ;
F_174 ( V_2 ) ;
V_325 -> V_331 . V_486 = 0 ;
F_190 ( V_2 ) ;
F_188 ( V_2 , V_290 , V_487 ,
V_488 ) ;
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_173 ) )
F_191 ( V_2 ) ;
} else if ( V_474 & V_489 ) {
F_192 ( V_2 , V_325 ,
& V_325 -> V_329 ) ;
}
if ( V_474 & V_489 ) {
F_186 ( V_2 , V_290 , false ) ;
F_8 ( F_193 ( V_2 , V_290 , 0 ) ) ;
}
if ( V_474 & ( V_490 | V_491 | V_492 |
V_489 ) ) {
V_47 = F_138 ( V_2 ) ;
if ( V_47 )
F_113 ( V_2 , L_31 ) ;
}
if ( V_474 & V_493 ) {
F_194 ( V_2 , L_32 ,
V_403 -> V_494 ) ;
F_129 ( V_2 , V_290 , V_403 -> V_494 ) ;
}
if ( V_474 & V_495 ) {
F_165 ( V_2 , L_33 ) ;
V_325 -> V_331 . V_496 = 0 ;
if ( V_325 -> V_331 . V_497 ) {
V_47 = F_193 ( V_2 , V_290 , 0 ) ;
if ( V_47 )
F_113 ( V_2 ,
L_34 ) ;
}
}
if ( V_474 & V_498 ) {
F_165 ( V_2 , L_35 ) ;
F_174 ( V_2 ) ;
}
}
static int F_195 ( struct V_29 * V_30 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_499 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_196 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_381;
if ( V_290 -> type == V_138 )
F_182 ( V_2 , V_290 ) ;
V_325 -> V_500 = 0 ;
V_47 = F_137 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_381;
V_47 = F_141 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_501;
V_47 = F_197 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_392;
if ( F_41 ( V_2 ) ) {
unsigned int V_502 =
F_198 ( V_2 , V_290 , false , false ) ;
struct V_503 V_37 = {
. V_504 = V_505 ,
. V_266 = V_325 -> V_506 . V_266 ,
. V_291 = V_507 ,
. V_508 = false ,
. V_509 = V_510 ,
} ;
F_199 ( V_2 , V_290 -> V_511 , V_290 -> V_511 , 0 ,
& V_37 , V_502 ) ;
}
V_325 -> V_512 = true ;
F_138 ( V_2 ) ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_513;
if ( V_290 -> V_385 && V_2 -> V_339 )
F_168 ( V_2 , V_2 -> V_339 , false , NULL ) ;
F_1 ( V_2 , V_514 ) ;
F_190 ( V_2 ) ;
if ( F_200 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
goto V_381;
V_513:
F_138 ( V_2 ) ;
V_325 -> V_512 = false ;
F_201 ( V_2 , V_290 ) ;
V_392:
F_143 ( V_2 , V_290 ) ;
V_501:
F_145 ( V_2 , V_290 ) ;
V_381:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_499 ) ;
return V_47 ;
}
static void F_202 ( struct V_29 * V_30 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
F_147 ( V_2 , V_290 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_203 ( V_2 -> V_515 ) == V_290 ) {
F_192 ( V_2 , V_325 ,
& V_325 -> V_329 ) ;
F_204 ( V_2 -> V_515 , NULL ) ;
V_325 -> V_516 = false ;
}
if ( F_203 ( V_2 -> V_517 ) == V_290 ) {
F_204 ( V_2 -> V_517 , NULL ) ;
V_2 -> V_518 = 0 ;
}
V_325 -> V_512 = false ;
V_2 -> V_519 = 0 ;
F_190 ( V_2 ) ;
F_7 ( V_2 , V_514 ) ;
if ( V_290 -> V_385 && V_2 -> V_339 )
F_168 ( V_2 , V_2 -> V_339 , false , NULL ) ;
F_112 ( V_2 , false , NULL ) ;
F_201 ( V_2 , V_290 ) ;
F_143 ( V_2 , V_290 ) ;
F_138 ( V_2 ) ;
F_145 ( V_2 , V_290 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_205 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
struct V_473 * V_403 ,
T_1 V_474 )
{
struct V_133 * V_325 = F_95 ( V_290 ) ;
if ( ! V_325 -> V_512 )
return;
if ( V_474 & ( V_520 | V_521 |
V_522 | V_492 ) &&
F_168 ( V_2 , V_290 , false , NULL ) )
F_113 ( V_2 , L_25 , V_290 -> V_159 ) ;
if ( V_474 & V_523 &&
F_196 ( V_2 , V_290 ) )
F_206 ( V_2 , L_36 ) ;
if ( V_474 & V_493 ) {
F_194 ( V_2 , L_32 ,
V_403 -> V_494 ) ;
F_129 ( V_2 , V_290 , V_403 -> V_494 ) ;
}
}
static void F_207 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_473 * V_403 ,
T_1 V_474 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_524 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_474 & V_525 && ! V_403 -> V_526 )
F_208 ( V_2 , V_527 , true ) ;
switch ( V_290 -> type ) {
case V_116 :
F_181 ( V_2 , V_290 , V_403 , V_474 ) ;
break;
case V_138 :
case V_141 :
F_205 ( V_2 , V_290 , V_403 , V_474 ) ;
break;
case V_528 :
if ( V_474 & V_485 )
F_175 ( V_2 , V_290 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_524 ) ;
}
static int F_209 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_529 * V_530 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_530 -> V_531 . V_38 == 0 ||
V_530 -> V_531 . V_38 > V_2 -> V_72 -> V_73 . V_532 )
return - V_323 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_210 ( V_2 , V_290 , & V_530 -> V_531 , & V_530 -> V_533 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_211 ( struct V_29 * V_30 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_336 & V_534 )
F_208 ( V_2 , V_534 , true ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_212 ( struct V_29 * V_30 ,
struct V_259 * V_260 , V_135 V_535 ,
int V_536 ,
enum V_537 V_538 ,
bool V_539 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_213 ( V_2 , V_260 , V_538 , V_536 ,
V_535 , V_539 , false ) ;
}
static void
F_214 ( struct V_29 * V_30 ,
struct V_259 * V_260 , V_135 V_535 ,
int V_536 ,
enum V_537 V_538 ,
bool V_539 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_213 ( V_2 , V_260 , V_538 , V_536 ,
V_535 , V_539 , true ) ;
}
static void F_215 ( struct V_29 * V_30 ,
enum V_540 V_367 ,
struct V_259 * V_260 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_263 = F_62 ( V_260 ) ;
unsigned long V_541 = 0 , V_535 = 0 ;
int V_291 ;
F_4 ( & V_263 -> V_542 ) ;
for ( V_291 = 0 ; V_291 < V_507 ; V_291 ++ ) {
struct V_301 * V_302 = & V_263 -> V_302 [ V_291 ] ;
if ( V_302 -> V_543 != V_544 &&
V_302 -> V_543 != V_545 )
continue;
F_216 ( V_302 -> V_546 , & V_541 ) ;
if ( F_217 ( V_302 ) == 0 )
continue;
F_216 ( V_291 , & V_535 ) ;
}
switch ( V_367 ) {
case V_547 :
if ( F_218 ( & V_2 -> V_548 [ V_263 -> V_266 ] ) > 0 )
F_219 ( V_30 , V_260 , true ) ;
F_220 (tid, &tids, IWL_MAX_TID_COUNT)
F_221 ( V_260 , V_291 , true ) ;
if ( V_541 )
F_222 ( V_2 -> V_7 , V_541 , true ) ;
break;
case V_549 :
if ( F_8 ( V_263 -> V_266 == V_267 ) )
break;
if ( V_541 )
F_222 ( V_2 -> V_7 , V_541 , false ) ;
F_223 ( V_2 , V_260 ) ;
break;
default:
break;
}
F_5 ( & V_263 -> V_542 ) ;
}
static void F_224 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
enum V_540 V_367 ,
struct V_259 * V_260 )
{
F_215 ( V_30 , V_367 , V_260 ) ;
}
void F_225 ( struct V_1 * V_2 , struct V_469 * V_470 )
{
struct V_471 * V_472 = F_180 ( V_470 ) ;
struct V_550 * V_468 = ( void * ) V_472 -> V_277 ;
struct V_259 * V_260 ;
struct V_131 * V_263 ;
bool V_551 = ( V_468 -> type != V_552 ) ;
if ( F_8 ( V_468 -> V_266 >= F_43 ( V_2 -> V_553 ) ) )
return;
F_226 () ;
V_260 = V_2 -> V_553 [ V_468 -> V_266 ] ;
if ( F_8 ( F_23 ( V_260 ) ) ) {
F_227 () ;
return;
}
V_263 = F_62 ( V_260 ) ;
if ( ! V_263 -> V_290 ||
V_263 -> V_290 -> type != V_138 ) {
F_227 () ;
return;
}
if ( V_263 -> V_551 != V_551 ) {
V_263 -> V_551 = V_551 ;
F_215 ( V_2 -> V_30 ,
V_551 ? V_547 : V_549 ,
V_260 ) ;
F_228 ( V_260 , V_551 ) ;
}
if ( V_551 ) {
switch ( V_468 -> type ) {
case V_552 :
case V_554 :
break;
case V_555 :
F_229 ( V_260 , V_556 ) ;
break;
case V_557 :
F_230 ( V_260 ) ;
break;
default:
break;
}
}
F_227 () ;
}
static void F_231 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_259 * V_260 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_558 = F_62 ( V_260 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_260 == F_203 ( V_2 -> V_553 [ V_558 -> V_266 ] ) )
F_232 ( V_2 -> V_553 [ V_558 -> V_266 ] ,
F_233 ( - V_49 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_234 ( struct V_1 * V_2 , struct V_289 * V_290 ,
const T_2 * V_405 )
{
if ( ! ( V_2 -> V_72 -> V_73 . V_142 & V_559 ) )
return;
if ( V_290 -> V_385 && ! F_235 ( V_2 ) ) {
V_290 -> V_386 &= ~ V_560 ;
return;
}
if ( ! V_290 -> V_385 &&
( V_103 . V_561 & V_562 ) ) {
V_290 -> V_386 &= ~ V_560 ;
return;
}
V_290 -> V_386 |= V_560 ;
}
static void
F_236 ( struct V_1 * V_2 ,
struct V_289 * V_290 , T_2 * V_563 ,
enum V_564 V_294 )
{
struct V_295 * V_296 ;
struct V_565 * V_566 ;
if ( ! F_81 ( V_2 -> V_72 , V_567 ) )
return;
V_296 = F_82 ( V_2 -> V_72 , V_567 ) ;
V_566 = ( void * ) V_296 -> V_277 ;
if ( ! F_83 ( V_2 , V_290 , V_296 ) )
return;
if ( ! ( V_566 -> V_568 & F_45 ( V_294 ) ) )
return;
if ( V_566 -> V_569 &&
memcmp ( V_566 -> V_570 , V_563 , V_162 ) != 0 )
return;
F_237 ( V_2 , V_296 ,
L_37 ,
V_563 , V_294 ) ;
}
static void F_238 ( struct V_1 * V_2 ,
struct V_131 * V_558 )
{
struct V_301 * V_302 ;
struct V_261 * V_262 ;
int V_9 ;
F_4 ( & V_558 -> V_542 ) ;
for ( V_9 = 0 ; V_9 <= V_507 ; V_9 ++ ) {
V_302 = & V_558 -> V_302 [ V_9 ] ;
while ( ( V_262 = F_239 ( & V_302 -> V_571 ) ) )
F_77 ( V_2 -> V_30 , V_262 ) ;
}
F_5 ( & V_558 -> V_542 ) ;
}
static int F_240 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_259 * V_260 ,
enum V_572 V_573 ,
enum V_572 V_574 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
int V_47 ;
F_165 ( V_2 , L_38 ,
V_260 -> V_159 , V_573 , V_574 ) ;
if ( F_15 ( ! V_325 -> V_330 ) )
return - V_323 ;
F_120 ( & V_2 -> V_394 ) ;
if ( V_573 == V_575 &&
V_574 == V_576 &&
F_41 ( V_2 ) ) {
struct V_131 * V_558 = F_62 ( V_260 ) ;
F_238 ( V_2 , V_558 ) ;
F_120 ( & V_2 -> V_360 ) ;
}
F_87 ( & V_2 -> V_33 ) ;
if ( V_573 == V_576 &&
V_574 == V_575 ) {
if ( V_290 -> type == V_116 &&
V_290 -> V_403 . V_481 < 16 ) {
F_113 ( V_2 ,
L_39 ,
V_260 -> V_159 , V_290 -> V_403 . V_481 ) ;
V_47 = - V_323 ;
goto V_381;
}
if ( V_260 -> V_577 &&
( V_290 -> V_385 ||
F_241 ( V_2 , NULL ) ==
V_578 ||
F_200 ( V_2 ) > 1 ) ) {
F_165 ( V_2 , L_40 ) ;
V_47 = - V_579 ;
goto V_381;
}
V_47 = F_242 ( V_2 , V_290 , V_260 ) ;
if ( V_260 -> V_577 && V_47 == 0 ) {
F_243 ( V_2 , V_290 , true ) ;
F_236 ( V_2 , V_290 , V_260 -> V_159 ,
V_580 ) ;
}
} else if ( V_573 == V_575 &&
V_574 == V_581 ) {
V_2 -> V_582 = true ;
F_234 ( V_2 , V_290 , V_260 -> V_159 ) ;
V_47 = 0 ;
} else if ( V_573 == V_581 &&
V_574 == V_583 ) {
if ( V_290 -> type == V_138 ) {
V_325 -> V_500 ++ ;
F_168 ( V_2 , V_290 , false , NULL ) ;
}
V_47 = F_244 ( V_2 , V_290 , V_260 ) ;
if ( V_47 == 0 )
F_245 ( V_2 , V_260 ,
V_325 -> V_330 -> V_584 -> V_585 ,
true ) ;
} else if ( V_573 == V_583 &&
V_574 == V_586 ) {
if ( F_200 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
if ( V_260 -> V_577 )
F_236 ( V_2 , V_290 , V_260 -> V_159 ,
V_587 ) ;
F_8 ( F_193 ( V_2 , V_290 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_573 == V_586 &&
V_574 == V_583 ) {
F_8 ( F_139 ( V_2 , V_290 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_573 == V_583 &&
V_574 == V_581 ) {
if ( V_290 -> type == V_138 ) {
V_325 -> V_500 -- ;
F_168 ( V_2 , V_290 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_573 == V_581 &&
V_574 == V_575 ) {
V_47 = 0 ;
} else if ( V_573 == V_575 &&
V_574 == V_576 ) {
V_47 = F_246 ( V_2 , V_290 , V_260 ) ;
if ( V_260 -> V_577 ) {
F_243 ( V_2 , V_290 , false ) ;
F_236 ( V_2 , V_290 , V_260 -> V_159 ,
V_588 ) ;
}
} else {
V_47 = - V_17 ;
}
V_381:
F_93 ( & V_2 -> V_33 ) ;
if ( V_260 -> V_577 && V_47 == 0 ) {
if ( V_573 == V_576 &&
V_574 == V_575 )
F_247 ( V_260 , V_589 ) ;
else if ( V_573 == V_575 &&
V_574 == V_576 )
F_248 ( V_260 , V_589 ) ;
}
return V_47 ;
}
static int F_249 ( struct V_29 * V_30 , T_1 V_590 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_219 = V_590 ;
return 0 ;
}
static void F_250 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_259 * V_260 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_290 -> type == V_116 &&
V_27 & V_591 )
F_186 ( V_2 , V_290 , false ) ;
}
static int F_251 ( struct V_29 * V_30 ,
struct V_289 * V_290 , V_135 V_592 ,
const struct V_593 * V_312 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
V_325 -> V_594 [ V_592 ] = * V_312 ;
if ( V_290 -> type == V_140 ) {
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_168 ( V_2 , V_290 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_252 ( struct V_29 * V_30 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_595 = V_596 ;
T_1 V_597 = V_598 ;
if ( F_15 ( V_290 -> V_403 . V_404 ) )
return;
if ( F_12 ( V_2 , V_599 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_185 ( V_2 , V_290 , V_595 , V_597 , 500 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_599 ) ;
}
static int F_253 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_600 * V_531 ,
struct V_601 * V_533 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! V_290 -> V_403 . V_526 ) {
V_47 = - V_579 ;
goto V_34;
}
V_47 = F_254 ( V_2 , V_290 , V_531 , V_533 , V_527 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_255 ( struct V_29 * V_30 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_336 & V_527 ) ) {
F_93 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_208 ( V_2 , V_527 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_256 ( V_2 ) ;
return V_47 ;
}
static int F_257 ( struct V_29 * V_30 ,
enum V_602 V_367 ,
struct V_289 * V_290 ,
struct V_259 * V_260 ,
struct V_603 * V_604 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_263 ;
struct V_605 * V_606 ;
int V_607 = V_604 -> V_607 ;
int V_47 ;
T_2 V_608 ;
if ( V_103 . V_104 ) {
F_165 ( V_2 , L_41 ) ;
return - V_609 ;
}
switch ( V_604 -> V_110 ) {
case V_54 :
V_604 -> V_142 |= V_610 ;
V_604 -> V_142 |= V_611 ;
break;
case V_55 :
case V_101 :
case V_102 :
V_604 -> V_142 |= V_611 ;
break;
case V_106 :
case V_107 :
case V_108 :
F_15 ( ! F_258 ( V_30 , V_105 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_290 -> type != V_116 )
return 0 ;
break;
default:
if ( V_30 -> V_114 &&
V_30 -> V_124 -> V_110 == V_604 -> V_110 )
V_604 -> V_142 |= V_611 ;
else
return - V_609 ;
}
F_87 ( & V_2 -> V_33 ) ;
switch ( V_367 ) {
case V_612 :
if ( ( V_290 -> type == V_141 ||
V_290 -> type == V_138 ) && ! V_260 ) {
if ( V_604 -> V_110 == V_106 ||
V_604 -> V_110 == V_107 ||
V_604 -> V_110 == V_108 )
V_47 = - V_609 ;
else
V_47 = 0 ;
V_604 -> V_613 = V_614 ;
break;
}
if ( F_14 ( V_350 , & V_2 -> V_15 ) &&
V_604 -> V_613 == V_614 ) {
F_165 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_350 , & V_2 -> V_15 ) &&
V_260 && F_39 ( V_2 ) &&
V_604 -> V_142 & V_615 &&
( V_604 -> V_110 == V_55 ||
V_604 -> V_110 == V_101 ||
V_604 -> V_110 == V_102 ) ) {
struct V_616 V_617 ;
int V_291 , V_618 ;
V_263 = F_62 ( V_260 ) ;
F_8 ( F_203 ( V_263 -> V_606 [ V_607 ] ) ) ;
V_606 = F_163 ( sizeof( * V_606 ) +
V_2 -> V_7 -> V_76 *
sizeof( V_606 -> V_618 [ 0 ] ) ,
V_619 ) ;
if ( ! V_606 ) {
V_47 = - V_620 ;
break;
}
for ( V_291 = 0 ; V_291 < V_507 ; V_291 ++ ) {
F_259 ( V_604 , V_291 , & V_617 ) ;
for ( V_618 = 0 ; V_618 < V_2 -> V_7 -> V_76 ; V_618 ++ )
memcpy ( V_606 -> V_618 [ V_618 ] . V_621 [ V_291 ] ,
V_617 . V_622 . V_621 ,
V_623 ) ;
}
F_232 ( V_263 -> V_606 [ V_607 ] , V_606 ) ;
}
if ( F_14 ( V_350 , & V_2 -> V_15 ) )
V_608 = V_604 -> V_613 ;
else
V_608 = V_614 ;
F_165 ( V_2 , L_43 ) ;
V_47 = F_260 ( V_2 , V_290 , V_260 , V_604 , V_608 ) ;
if ( V_47 ) {
F_206 ( V_2 , L_44 ) ;
V_604 -> V_613 = V_614 ;
V_47 = 0 ;
}
break;
case V_624 :
if ( V_604 -> V_613 == V_614 ) {
V_47 = 0 ;
break;
}
if ( V_260 && F_39 ( V_2 ) &&
V_604 -> V_142 & V_615 &&
( V_604 -> V_110 == V_55 ||
V_604 -> V_110 == V_101 ||
V_604 -> V_110 == V_102 ) ) {
V_263 = F_62 ( V_260 ) ;
V_606 = F_261 (
V_263 -> V_606 [ V_607 ] ,
F_262 ( & V_2 -> V_33 ) ) ;
F_204 ( V_263 -> V_606 [ V_607 ] , NULL ) ;
if ( V_606 )
F_263 ( V_606 , V_625 ) ;
}
F_165 ( V_2 , L_45 ) ;
V_47 = F_264 ( V_2 , V_290 , V_260 , V_604 ) ;
break;
default:
V_47 = - V_323 ;
}
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_265 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_603 * V_626 ,
struct V_259 * V_260 ,
T_1 V_627 , V_135 * V_628 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_626 -> V_613 == V_614 )
return;
F_266 ( V_2 , V_290 , V_626 , V_260 , V_627 , V_628 ) ;
}
static bool F_267 ( struct V_629 * V_630 ,
struct V_471 * V_472 , void * V_277 )
{
struct V_1 * V_2 =
F_268 ( V_630 , struct V_1 , V_630 ) ;
struct V_631 * V_32 ;
int V_632 = F_269 ( V_472 ) ;
struct V_633 * V_634 = V_277 ;
if ( F_8 ( V_472 -> V_276 . V_367 != V_635 ) )
return true ;
if ( F_15 ( V_632 != sizeof( * V_32 ) ) ) {
F_113 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_472 -> V_277 ;
F_270 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_636 ) ;
V_634 -> V_637 = F_44 ( V_32 -> V_636 ) ;
F_270 ( V_2 , L_48 ,
V_634 -> V_637 ) ;
F_4 ( & V_2 -> V_328 ) ;
F_271 ( & V_634 -> V_638 , & V_2 -> V_639 ) ;
F_5 ( & V_2 -> V_328 ) ;
return true ;
}
static int F_272 ( struct V_1 * V_2 ,
struct V_640 * V_584 ,
struct V_289 * V_290 ,
int V_595 )
{
int V_641 , V_642 = V_643 ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
struct V_633 * V_634 = & V_325 -> V_644 ;
static const V_135 V_645 [] = { V_635 } ;
struct V_646 V_647 ;
T_1 V_648 = V_290 -> V_403 . V_649 *
V_290 -> V_403 . V_481 ;
T_1 V_650 , V_651 ;
struct V_652 V_653 = {
. V_294 = F_130 ( V_654 ) ,
. V_655 =
F_130 ( F_273 ( V_656 , 0 ) ) ,
. V_657 = F_130 ( V_2 -> V_658 . V_266 ) ,
. V_659 . V_585 = ( V_584 -> V_585 == V_176 ) ?
V_660 : V_661 ,
. V_659 . V_584 = V_584 -> V_662 ,
. V_659 . V_663 = V_664 ,
. V_665 = F_130 ( F_274 ( V_2 -> V_7 , V_642 ) ) ,
} ;
V_651 = V_666 ;
V_650 = F_275 ( V_595 ) ;
if ( V_290 -> V_403 . V_404 ) {
V_651 = F_276 ( T_1 , V_648 * 3 , V_667 ) ;
if ( V_648 <= V_650 ) {
V_650 = V_648 - V_668 ;
if ( V_650 <= V_669 )
V_650 = V_648 -
V_670 ;
}
}
V_653 . V_595 = F_130 ( V_650 ) ;
V_653 . V_671 = F_130 ( V_651 ) ;
F_270 ( V_2 ,
L_49 ,
V_584 -> V_662 , V_650 , V_595 , V_651 ,
V_648 ) ;
memcpy ( V_653 . V_672 , V_290 -> V_159 , V_162 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_328 ) ;
if ( F_8 ( V_634 -> V_20 == V_635 ) ) {
F_5 ( & V_2 -> V_328 ) ;
return - V_17 ;
}
V_634 -> V_290 = V_290 ;
V_634 -> V_595 = V_595 ;
V_634 -> V_20 = V_635 ;
F_5 ( & V_2 -> V_328 ) ;
F_277 ( & V_2 -> V_630 , & V_647 ,
V_645 ,
F_43 ( V_645 ) ,
F_267 , V_634 ) ;
V_641 = F_132 ( V_2 , V_635 , 0 , sizeof( V_653 ) ,
& V_653 ) ;
if ( V_641 ) {
F_113 ( V_2 , L_50 , V_641 ) ;
F_278 ( & V_2 -> V_630 , & V_647 ) ;
goto V_673;
}
V_641 = F_279 ( & V_2 -> V_630 , & V_647 , 1 ) ;
F_15 ( V_641 ) ;
if ( V_641 ) {
V_673:
F_4 ( & V_2 -> V_328 ) ;
F_96 ( V_2 , V_634 ) ;
F_5 ( & V_2 -> V_328 ) ;
}
return V_641 ;
}
static int F_280 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_640 * V_584 ,
int V_595 ,
enum V_674 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
struct V_675 V_676 ;
struct V_364 * V_330 ;
int V_47 , V_9 ;
F_165 ( V_2 , L_51 , V_584 -> V_662 ,
V_595 , type ) ;
F_120 ( & V_2 -> V_356 ) ;
F_87 ( & V_2 -> V_33 ) ;
switch ( V_290 -> type ) {
case V_116 :
if ( F_40 ( & V_2 -> V_72 -> V_73 ,
V_677 ) ) {
V_47 = F_272 ( V_2 , V_584 ,
V_290 , V_595 ) ;
goto V_381;
}
F_113 ( V_2 , L_52 ) ;
V_47 = - V_323 ;
goto V_381;
case V_140 :
break;
default:
F_113 ( V_2 , L_53 , V_290 -> type ) ;
V_47 = - V_323 ;
goto V_381;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_330 = & V_2 -> V_18 [ V_9 ] ;
if ( V_330 -> V_21 == 0 || V_325 -> V_330 == V_330 )
continue;
if ( V_330 -> V_21 && V_584 == V_330 -> V_584 ) {
V_47 = F_143 ( V_2 , V_290 ) ;
if ( F_281 ( V_47 , L_54 ) )
goto V_381;
F_144 ( V_2 , V_325 -> V_330 ) ;
V_325 -> V_330 = V_330 ;
V_47 = F_141 ( V_2 , V_290 ) ;
if ( F_281 ( V_47 , L_55 ) )
goto V_381;
F_140 ( V_2 , V_325 -> V_330 ) ;
goto V_678;
}
}
if ( V_584 == V_325 -> V_330 -> V_584 )
goto V_678;
F_282 ( & V_676 , V_584 , V_679 ) ;
if ( V_325 -> V_330 -> V_21 == 1 ) {
V_47 = F_283 ( V_2 , V_325 -> V_330 ,
& V_676 , 1 , 1 ) ;
if ( V_47 )
goto V_381;
} else {
V_330 = F_128 ( V_2 ) ;
if ( ! V_330 ) {
V_47 = - V_389 ;
goto V_381;
}
V_47 = F_283 ( V_2 , V_330 , & V_676 ,
1 , 1 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_56 ) ;
goto V_381;
}
V_47 = F_143 ( V_2 , V_290 ) ;
if ( F_281 ( V_47 , L_54 ) )
goto V_381;
F_144 ( V_2 , V_325 -> V_330 ) ;
V_325 -> V_330 = V_330 ;
V_47 = F_141 ( V_2 , V_290 ) ;
if ( F_281 ( V_47 , L_55 ) )
goto V_381;
F_140 ( V_2 , V_325 -> V_330 ) ;
}
V_678:
V_47 = F_284 ( V_2 , V_290 , V_595 , type ) ;
V_381:
F_93 ( & V_2 -> V_33 ) ;
F_165 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_285 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_165 ( V_2 , L_58 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_286 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_165 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_287 ( struct V_1 * V_2 ,
struct V_680 * V_681 )
{
V_135 * V_682 = ( V_135 * ) V_681 -> V_683 ;
struct V_364 * V_330 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_165 ( V_2 , L_59 ) ;
V_330 = F_128 ( V_2 ) ;
if ( ! V_330 ) {
V_47 = - V_389 ;
goto V_34;
}
V_47 = F_283 ( V_2 , V_330 , & V_681 -> V_684 ,
V_681 -> V_685 ,
V_681 -> V_686 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_60 ) ;
goto V_34;
}
F_140 ( V_2 , V_330 ) ;
* V_682 = V_330 -> V_20 ;
V_34:
return V_47 ;
}
static int F_288 ( struct V_29 * V_30 ,
struct V_680 * V_681 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_287 ( V_2 , V_681 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_289 ( struct V_1 * V_2 ,
struct V_680 * V_681 )
{
V_135 * V_682 = ( V_135 * ) V_681 -> V_683 ;
struct V_364 * V_330 = & V_2 -> V_18 [ * V_682 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_144 ( V_2 , V_330 ) ;
}
static void F_290 ( struct V_29 * V_30 ,
struct V_680 * V_681 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_289 ( V_2 , V_681 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_291 ( struct V_29 * V_30 ,
struct V_680 * V_681 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_135 * V_682 = ( V_135 * ) V_681 -> V_683 ;
struct V_364 * V_330 = & V_2 -> V_18 [ * V_682 ] ;
if ( F_117 ( ( V_330 -> V_21 > 1 ) &&
( V_27 & ~ ( V_687 |
V_688 |
V_689 |
V_690 ) ) ,
L_61 ,
V_330 -> V_21 , V_27 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_190 ( V_2 ) ;
F_283 ( V_2 , V_330 , & V_681 -> V_684 ,
V_681 -> V_685 ,
V_681 -> V_686 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_292 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
struct V_680 * V_681 ,
bool V_691 )
{
V_135 * V_682 = ( V_135 * ) V_681 -> V_683 ;
struct V_364 * V_330 = & V_2 -> V_18 [ * V_682 ] ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_325 -> V_330 = V_330 ;
switch ( V_290 -> type ) {
case V_138 :
if ( V_691 ) {
V_325 -> V_512 = true ;
break;
}
case V_141 :
V_47 = 0 ;
goto V_34;
case V_116 :
break;
case V_528 :
V_325 -> V_337 = true ;
break;
default:
V_47 = - V_323 ;
goto V_34;
}
V_47 = F_141 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_34;
F_138 ( V_2 ) ;
if ( V_290 -> type == V_528 ) {
V_325 -> V_692 = true ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_693;
V_47 = F_293 ( V_2 , V_290 ) ;
if ( V_47 )
goto V_693;
}
if ( V_290 -> type == V_138 ) {
F_112 ( V_2 , false , NULL ) ;
F_168 ( V_2 , V_290 , false , NULL ) ;
}
if ( V_691 && V_290 -> type == V_116 ) {
T_1 V_595 = 2 * V_290 -> V_403 . V_481 ;
V_47 = F_12 ( V_2 , V_694 ) ;
if ( V_47 )
goto V_693;
F_185 ( V_2 , V_290 , V_595 , V_595 ,
V_290 -> V_403 . V_481 / 2 ,
true ) ;
F_7 ( V_2 , V_694 ) ;
F_112 ( V_2 , false , NULL ) ;
}
goto V_34;
V_693:
F_143 ( V_2 , V_290 ) ;
F_138 ( V_2 ) ;
V_34:
if ( V_47 )
V_325 -> V_330 = NULL ;
return V_47 ;
}
static int F_294 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_680 * V_681 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_292 ( V_2 , V_290 , V_681 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_295 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
struct V_680 * V_681 ,
bool V_691 )
{
struct V_133 * V_325 = F_95 ( V_290 ) ;
struct V_289 * V_695 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_192 ( V_2 , V_325 , & V_325 -> V_329 ) ;
switch ( V_290 -> type ) {
case V_141 :
goto V_34;
case V_528 :
V_325 -> V_692 = false ;
V_325 -> V_337 = false ;
F_296 ( V_2 , V_290 ) ;
break;
case V_138 :
if ( ! V_691 || ! V_325 -> V_512 )
goto V_34;
V_325 -> V_516 = false ;
F_297 ( V_2 , V_325 , true ) ;
F_232 ( V_2 -> V_517 , V_290 ) ;
V_325 -> V_512 = false ;
break;
case V_116 :
if ( ! V_691 )
break;
V_695 = V_290 ;
F_168 ( V_2 , V_290 , true , NULL ) ;
break;
default:
break;
}
F_112 ( V_2 , false , V_695 ) ;
F_143 ( V_2 , V_290 ) ;
V_34:
V_325 -> V_330 = NULL ;
F_138 ( V_2 ) ;
}
static void F_298 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_680 * V_681 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_295 ( V_2 , V_290 , V_681 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int
F_299 ( struct V_1 * V_2 ,
struct V_696 * V_697 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_295 ( V_2 , V_697 [ 0 ] . V_290 , V_697 [ 0 ] . V_698 , true ) ;
F_289 ( V_2 , V_697 [ 0 ] . V_698 ) ;
V_47 = F_287 ( V_2 , V_697 [ 0 ] . V_699 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_62 ) ;
goto V_700;
}
V_47 = F_292 ( V_2 , V_697 [ 0 ] . V_290 , V_697 [ 0 ] . V_699 ,
true ) ;
if ( V_47 ) {
F_113 ( V_2 ,
L_63 ) ;
goto V_501;
}
if ( F_200 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
goto V_34;
V_501:
F_289 ( V_2 , V_697 [ 0 ] . V_699 ) ;
V_700:
if ( F_287 ( V_2 , V_697 [ 0 ] . V_698 ) ) {
F_113 ( V_2 , L_64 ) ;
goto V_701;
}
if ( F_292 ( V_2 , V_697 [ 0 ] . V_290 , V_697 [ 0 ] . V_698 ,
true ) ) {
F_113 ( V_2 , L_65 ) ;
goto V_701;
}
goto V_34;
V_701:
F_300 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_301 ( struct V_1 * V_2 ,
struct V_696 * V_697 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_295 ( V_2 , V_697 [ 0 ] . V_290 , V_697 [ 0 ] . V_698 , true ) ;
V_47 = F_292 ( V_2 , V_697 [ 0 ] . V_290 , V_697 [ 0 ] . V_699 ,
true ) ;
if ( V_47 ) {
F_113 ( V_2 ,
L_63 ) ;
goto V_700;
}
goto V_34;
V_700:
if ( F_292 ( V_2 , V_697 [ 0 ] . V_290 , V_697 [ 0 ] . V_698 ,
true ) ) {
F_113 ( V_2 , L_65 ) ;
goto V_701;
}
goto V_34;
V_701:
F_300 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_302 ( struct V_29 * V_30 ,
struct V_696 * V_697 ,
int V_702 ,
enum V_703 V_704 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_702 > 1 )
return - V_609 ;
switch ( V_704 ) {
case V_705 :
V_47 = F_299 ( V_2 , V_697 ) ;
break;
case V_706 :
V_47 = F_301 ( V_2 , V_697 ) ;
break;
default:
V_47 = - V_609 ;
break;
}
return V_47 ;
}
static int F_303 ( struct V_29 * V_30 ,
struct V_259 * V_260 ,
bool V_707 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_558 = F_62 ( V_260 ) ;
if ( ! V_558 || ! V_558 -> V_290 ) {
F_113 ( V_2 , L_66 ) ;
return - V_323 ;
}
return F_196 ( V_2 , V_558 -> V_290 ) ;
}
static int F_304 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
void * V_277 , int V_226 )
{
struct V_708 * V_709 [ V_710 + 1 ] ;
int V_711 ;
T_1 V_396 ;
V_711 = F_305 ( V_709 , V_710 , V_277 , V_226 , V_712 ) ;
if ( V_711 )
return V_711 ;
if ( ! V_709 [ V_713 ] )
return - V_323 ;
switch ( F_306 ( V_709 [ V_713 ] ) ) {
case V_714 :
if ( ! V_290 || V_290 -> type != V_138 || ! V_290 -> V_385 ||
! V_290 -> V_403 . V_715 ||
! V_709 [ V_716 ] )
return - V_323 ;
V_396 = F_306 ( V_709 [ V_716 ] ) ;
if ( V_396 >= V_290 -> V_403 . V_481 )
return - V_323 ;
V_2 -> V_396 = V_396 ;
V_2 -> V_395 = V_290 ;
return F_112 ( V_2 , false , NULL ) ;
case V_717 :
if ( ! V_290 || V_290 -> type != V_116 ||
! V_290 -> V_403 . V_404 || ! V_290 -> V_403 . V_649 ||
! V_709 [ V_718 ] )
return - V_323 ;
if ( F_306 ( V_709 [ V_718 ] ) )
return F_193 ( V_2 , V_290 , 0 ) ;
return F_139 ( V_2 , V_290 , 0 ) ;
}
return - V_609 ;
}
static int F_307 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
void * V_277 , int V_226 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_711 ;
F_87 ( & V_2 -> V_33 ) ;
V_711 = F_304 ( V_2 , V_290 , V_277 , V_226 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_711 ;
}
static void F_308 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_719 * V_720 )
{
F_165 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_309 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_719 * V_720 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_289 * V_515 ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
T_1 V_665 ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_325 -> V_721 = false ;
F_165 ( V_2 , L_68 ,
V_720 -> V_676 . V_722 ) ;
F_310 ( V_2 , V_290 , V_723 ) ;
switch ( V_290 -> type ) {
case V_138 :
V_515 =
F_261 ( V_2 -> V_515 ,
F_262 ( & V_2 -> V_33 ) ) ;
if ( F_117 ( V_515 && V_515 -> V_724 ,
L_69 ) ) {
V_47 = - V_579 ;
goto V_381;
}
if ( F_261 ( V_2 -> V_517 ,
F_262 ( & V_2 -> V_33 ) ) ) {
V_47 = - V_579 ;
goto V_381;
}
F_232 ( V_2 -> V_515 , V_290 ) ;
if ( F_117 ( V_325 -> V_516 ,
L_70 ) ) {
V_47 = - V_579 ;
goto V_381;
}
V_325 -> V_725 = V_720 -> V_676 . V_726 -> V_727 ;
break;
case V_116 :
if ( V_325 -> V_476 )
F_183 ( V_290 ,
V_477 ,
0 , 0 ) ;
V_665 = V_720 -> V_728 +
( ( V_290 -> V_403 . V_481 * ( V_720 -> V_406 - 1 ) -
V_729 ) * 1024 ) ;
if ( V_720 -> V_730 )
F_311 ( V_2 , V_290 ) ;
F_312 ( V_2 , V_290 , V_290 -> V_403 . V_481 ,
V_665 ) ;
if ( V_325 -> V_331 . V_497 ) {
V_47 = F_139 ( V_2 , V_290 , 0 ) ;
if ( V_47 )
goto V_381;
}
break;
default:
break;
}
V_325 -> V_337 = true ;
V_47 = F_313 ( V_2 ) ;
if ( V_47 )
goto V_381;
F_114 ( V_2 ) ;
V_381:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_314 ( struct V_29 * V_30 ,
struct V_289 * V_290 )
{
struct V_133 * V_325 = F_95 ( V_290 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_325 -> V_721 ) {
V_325 -> V_721 = false ;
V_47 = - V_17 ;
goto V_381;
}
if ( V_290 -> type == V_116 ) {
struct V_131 * V_263 ;
V_263 = F_315 ( V_2 ,
V_325 -> V_327 ) ;
if ( F_8 ( ! V_263 ) ) {
V_47 = - V_17 ;
goto V_381;
}
F_316 ( V_2 , V_263 , false ) ;
F_168 ( V_2 , V_290 , false , NULL ) ;
V_47 = F_193 ( V_2 , V_290 , 0 ) ;
if ( V_47 )
goto V_381;
F_317 ( V_2 , V_290 ) ;
}
V_325 -> V_337 = false ;
V_47 = F_313 ( V_2 ) ;
V_381:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_318 ( struct V_29 * V_30 ,
struct V_289 * V_290 , T_1 V_82 , bool V_278 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 ;
struct V_131 * V_263 ;
struct V_259 * V_260 ;
int V_9 ;
T_1 V_731 = 0 ;
if ( ! V_290 || V_290 -> type != V_116 )
return;
if ( F_41 ( V_2 ) )
F_120 ( & V_2 -> V_360 ) ;
F_87 ( & V_2 -> V_33 ) ;
V_325 = F_95 ( V_290 ) ;
for ( V_9 = 0 ; V_9 < V_267 ; V_9 ++ ) {
V_260 = F_261 ( V_2 -> V_553 [ V_9 ] ,
F_262 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_260 ) )
continue;
V_263 = F_62 ( V_260 ) ;
if ( V_263 -> V_290 != V_290 )
continue;
F_8 ( V_9 != V_325 -> V_327 && ! V_260 -> V_577 ) ;
V_731 |= V_263 -> V_732 ;
}
if ( V_278 ) {
if ( F_149 ( V_2 , V_731 , 0 ) )
F_113 ( V_2 , L_71 ) ;
F_93 ( & V_2 -> V_33 ) ;
} else {
F_93 ( & V_2 -> V_33 ) ;
F_150 ( V_2 -> V_7 , V_731 ) ;
}
}
static int F_319 ( struct V_29 * V_30 , int V_733 ,
struct V_734 * V_735 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_735 , 0 , sizeof( * V_735 ) ) ;
if ( V_733 != 0 )
return - V_49 ;
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_736 ) )
return - V_49 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_737 ) {
V_47 = F_184 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_735 -> V_738 = V_739 |
V_740 |
V_741 |
V_742 ;
V_735 -> time = V_2 -> V_355 . V_743 +
V_2 -> V_744 . V_743 ;
F_320 ( V_735 -> time , V_745 ) ;
V_735 -> V_746 = V_2 -> V_355 . V_747 +
V_2 -> V_744 . V_747 ;
F_320 ( V_735 -> V_746 , V_745 ) ;
V_735 -> V_748 = V_2 -> V_355 . V_749 +
V_2 -> V_744 . V_749 ;
F_320 ( V_735 -> V_748 , V_745 ) ;
V_735 -> V_750 = V_2 -> V_355 . V_751 +
V_2 -> V_744 . V_751 ;
F_320 ( V_735 -> V_750 , V_745 ) ;
V_47 = 0 ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_321 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
struct V_259 * V_260 ,
struct V_752 * V_753 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_133 * V_325 = F_95 ( V_290 ) ;
struct V_131 * V_263 = F_62 ( V_260 ) ;
if ( V_263 -> V_754 ) {
V_753 -> V_755 = V_263 -> V_754 ;
V_753 -> V_738 |= F_45 ( V_756 ) ;
}
if ( ! F_40 ( & V_2 -> V_72 -> V_73 ,
V_736 ) )
return;
if ( ! ( V_290 -> V_386 & V_387 ) )
return;
if ( ! V_290 -> V_403 . V_404 )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_325 -> V_327 != V_263 -> V_266 )
goto V_757;
if ( F_184 ( V_2 , false ) )
goto V_757;
V_753 -> V_758 = V_325 -> V_378 . V_380 +
V_325 -> V_378 . V_379 ;
V_753 -> V_738 |= F_45 ( V_759 ) ;
if ( V_325 -> V_378 . V_760 ) {
V_753 -> V_761 = V_325 -> V_378 . V_760 ;
V_753 -> V_738 |= F_45 ( V_762 ) ;
}
V_757:
F_93 ( & V_2 -> V_33 ) ;
}
static void F_322 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
const struct V_763 * V_764 )
{
#define F_323 ( T_5 , T_6 , T_7 , T_8 , T_9 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_295 * V_296 ;
struct V_765 * V_766 ;
if ( ! F_81 ( V_2 -> V_72 , V_767 ) )
return;
V_296 = F_82 ( V_2 -> V_72 , V_767 ) ;
V_766 = ( void * ) V_296 -> V_277 ;
if ( ! F_83 ( V_2 , V_290 , V_296 ) )
return;
if ( V_764 -> V_768 . V_769 . V_277 == V_770 ) {
if ( V_764 -> V_768 . V_769 . V_15 == V_771 )
F_323 ( V_2 , V_296 , V_772 ,
V_766 -> V_773 ,
L_72 ,
V_764 -> V_768 . V_769 . V_538 ) ;
else if ( V_764 -> V_768 . V_769 . V_15 == V_774 )
F_323 ( V_2 , V_296 , V_772 ,
V_766 -> V_775 ,
L_73 ) ;
} else if ( V_764 -> V_768 . V_769 . V_277 == V_776 ) {
if ( V_764 -> V_768 . V_769 . V_15 == V_771 )
F_323 ( V_2 , V_296 , V_772 ,
V_766 -> V_777 ,
L_74 ,
V_764 -> V_768 . V_769 . V_538 ) ;
else if ( V_764 -> V_768 . V_769 . V_15 == V_774 )
F_323 ( V_2 , V_296 , V_772 ,
V_766 -> V_778 ,
L_75 ) ;
} else if ( V_764 -> V_768 . V_769 . V_277 == V_779 ) {
F_323 ( V_2 , V_296 , V_772 ,
V_766 -> V_780 ,
L_76 , V_764 -> V_768 . V_769 . V_538 ) ;
} else if ( V_764 -> V_768 . V_769 . V_277 == V_781 ) {
F_323 ( V_2 , V_296 , V_772 ,
V_766 -> V_782 ,
L_77 , V_764 -> V_768 . V_769 . V_538 ) ;
}
#undef F_323
}
static void F_324 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
const struct V_763 * V_764 )
{
struct V_295 * V_296 ;
struct V_297 * V_298 ;
if ( ! F_81 ( V_2 -> V_72 , V_299 ) )
return;
V_296 = F_82 ( V_2 -> V_72 , V_299 ) ;
V_298 = ( void * ) V_296 -> V_277 ;
if ( ! F_83 ( V_2 , V_290 , V_296 ) )
return;
if ( ! ( F_325 ( V_298 -> V_783 ) & F_45 ( V_764 -> V_768 . V_784 . V_291 ) ) )
return;
F_237 ( V_2 , V_296 ,
L_78 ,
V_764 -> V_768 . V_784 . V_260 -> V_159 , V_764 -> V_768 . V_784 . V_291 ,
V_764 -> V_768 . V_784 . V_304 ) ;
}
static void
F_326 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
const struct V_763 * V_764 )
{
struct V_295 * V_296 ;
struct V_297 * V_298 ;
if ( ! F_81 ( V_2 -> V_72 , V_299 ) )
return;
V_296 = F_82 ( V_2 -> V_72 , V_299 ) ;
V_298 = ( void * ) V_296 -> V_277 ;
if ( ! F_83 ( V_2 , V_290 , V_296 ) )
return;
if ( ! ( F_325 ( V_298 -> V_785 ) & F_45 ( V_764 -> V_768 . V_784 . V_291 ) ) )
return;
F_237 ( V_2 , V_296 ,
L_79 ,
V_764 -> V_768 . V_784 . V_260 -> V_159 , V_764 -> V_768 . V_784 . V_291 ) ;
}
static void F_327 ( struct V_29 * V_30 ,
struct V_289 * V_290 ,
const struct V_763 * V_764 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_764 -> type ) {
case V_786 :
F_322 ( V_2 , V_290 , V_764 ) ;
break;
case V_787 :
F_324 ( V_2 , V_290 , V_764 ) ;
break;
case V_788 :
F_326 ( V_2 , V_290 , V_764 ) ;
break;
default:
break;
}
}
void F_328 ( struct V_1 * V_2 ,
struct V_789 * V_468 ,
T_1 V_790 )
{
T_1 V_791 = F_45 ( V_2 -> V_7 -> V_76 ) - 1 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! F_39 ( V_2 ) )
return;
V_468 -> V_792 = V_2 -> V_793 ;
if ( V_468 -> V_794 )
F_329 ( & V_2 -> V_795 ,
V_2 -> V_7 -> V_76 ) ;
V_47 = F_330 ( V_2 , V_791 , ( T_2 * ) V_468 , V_790 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_80 , V_47 ) ;
goto V_34;
}
if ( V_468 -> V_794 )
V_47 = F_13 ( V_2 -> V_796 ,
F_218 ( & V_2 -> V_795 ) == 0 ,
V_16 ) ;
F_15 ( ! V_47 ) ;
V_34:
F_329 ( & V_2 -> V_795 , 0 ) ;
V_2 -> V_793 ++ ;
}
static void F_331 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_789 V_277 = {
. type = V_797 ,
. V_794 = 1 ,
} ;
F_87 ( & V_2 -> V_33 ) ;
F_328 ( V_2 , & V_277 , sizeof( V_277 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
