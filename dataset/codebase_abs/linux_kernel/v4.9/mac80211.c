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
if ( V_2 -> V_7 -> V_72 > 1 )
F_38 ( V_30 , V_73 ) ;
if ( V_2 -> V_7 -> V_74 )
V_30 -> V_75 = V_76 | V_77 ;
if ( ! F_40 ( V_2 ) )
V_30 -> V_78 = V_2 -> V_79 ;
else
V_30 -> V_78 = V_80 ;
V_30 -> V_81 = V_82 ;
V_30 -> V_83 |= V_84 |
V_85 ;
V_30 -> V_86 |= V_87 |
V_88 ;
V_30 -> V_89 = L_9 ;
V_30 -> V_90 = V_91 ;
V_30 -> V_92 = V_93 ;
F_41 ( F_42 ( V_2 -> V_94 ) < F_42 ( V_51 ) + 6 ) ;
memcpy ( V_2 -> V_94 , V_51 , sizeof( V_51 ) ) ;
V_30 -> V_23 -> V_95 = F_42 ( V_51 ) ;
V_30 -> V_23 -> V_96 = V_2 -> V_94 ;
if ( F_39 ( V_2 ) ) {
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] =
V_97 ;
V_30 -> V_23 -> V_95 ++ ;
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] =
V_98 ;
V_30 -> V_23 -> V_95 ++ ;
}
if ( ! V_99 . V_100 ) {
F_38 ( V_30 , V_101 ) ;
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] =
V_102 ;
V_30 -> V_23 -> V_95 ++ ;
if ( F_39 ( V_2 ) ) {
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] =
V_103 ;
V_30 -> V_23 -> V_95 ++ ;
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] =
V_104 ;
V_30 -> V_23 -> V_95 ++ ;
}
}
if ( V_2 -> V_105 -> V_106 [ 0 ] . V_107 ) {
const struct V_108 * V_109 = & V_2 -> V_105 -> V_106 [ 0 ] ;
struct V_110 * V_106 = & V_2 -> V_106 [ 0 ] ;
V_2 -> V_30 -> V_111 = 1 ;
V_106 -> V_107 = F_43 ( V_109 -> V_107 ) ;
V_106 -> V_112 = F_44 ( V_113 ) ;
V_106 -> V_114 = V_109 -> V_114 ;
V_106 -> V_115 = V_109 -> V_115 ;
V_106 -> V_116 = V_109 -> V_116 ;
V_106 -> V_117 = V_109 -> V_117 ;
V_106 -> V_118 = V_109 -> V_118 ;
V_106 -> V_119 = V_109 -> V_119 ;
V_106 -> V_120 = V_109 -> V_120 ;
V_2 -> V_30 -> V_121 = V_2 -> V_106 ;
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] = V_106 -> V_107 ;
V_30 -> V_23 -> V_95 ++ ;
}
F_38 ( V_30 , V_122 ) ;
V_30 -> V_23 -> V_123 |=
V_124 |
V_125 |
V_126 ;
V_30 -> V_127 = sizeof( struct V_128 ) ;
V_30 -> V_129 = sizeof( struct V_130 ) ;
V_30 -> V_131 = sizeof( V_132 ) ;
V_30 -> V_23 -> V_133 = F_44 ( V_113 ) |
F_44 ( V_134 ) |
F_44 ( V_135 ) |
F_44 ( V_136 ) |
F_44 ( V_137 ) |
F_44 ( V_138 ) ;
V_30 -> V_23 -> V_139 |= V_140 ;
V_30 -> V_23 -> V_141 |= V_142 ;
if ( F_30 ( V_2 ) )
V_30 -> V_23 -> V_141 |= V_143 ;
else
V_30 -> V_23 -> V_141 |= V_144 |
V_145 ;
V_30 -> V_23 -> V_139 |= V_146 ;
V_30 -> V_23 -> V_139 |= V_147 ;
V_30 -> V_23 -> V_148 = V_149 ;
V_30 -> V_23 -> V_150 =
F_42 ( V_149 ) ;
V_30 -> V_23 -> V_151 = 10000 ;
V_30 -> V_152 = V_153 ;
V_30 -> V_23 -> V_154 = 3 * 5 ;
memcpy ( V_2 -> V_155 [ 0 ] . V_156 , V_2 -> V_157 -> V_158 , V_159 ) ;
V_30 -> V_23 -> V_155 = V_2 -> V_155 ;
V_30 -> V_23 -> V_160 = 1 ;
V_50 = ( V_2 -> V_157 -> V_161 > 1 ) ?
F_45 ( V_162 , V_2 -> V_157 -> V_161 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_50 ; V_9 ++ ) {
memcpy ( V_2 -> V_155 [ V_9 ] . V_156 , V_2 -> V_155 [ V_9 - 1 ] . V_156 ,
V_159 ) ;
V_2 -> V_155 [ V_9 ] . V_156 [ 5 ] ++ ;
V_30 -> V_23 -> V_160 ++ ;
}
F_16 ( V_2 ) ;
V_30 -> V_23 -> V_163 = F_46 ( V_2 ) ;
V_30 -> V_23 -> V_164 = V_165 ;
F_41 ( V_166 & V_167 ) ;
F_41 ( V_168 > F_47 ( V_167 ) ||
V_169 > F_47 ( V_167 ) ) ;
if ( F_48 ( & V_2 -> V_105 -> V_170 , V_171 ) )
V_2 -> V_172 = V_168 ;
else
V_2 -> V_172 = V_169 ;
if ( V_2 -> V_157 -> V_173 [ V_174 ] . V_38 )
V_30 -> V_23 -> V_173 [ V_174 ] =
& V_2 -> V_157 -> V_173 [ V_174 ] ;
if ( V_2 -> V_157 -> V_173 [ V_175 ] . V_38 ) {
V_30 -> V_23 -> V_173 [ V_175 ] =
& V_2 -> V_157 -> V_173 [ V_175 ] ;
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_176 ) &&
F_49 ( & V_2 -> V_105 -> V_170 ,
V_177 ) )
V_30 -> V_23 -> V_173 [ V_175 ] -> V_178 . V_179 |=
V_180 ;
}
V_30 -> V_23 -> V_181 = V_2 -> V_7 -> V_182 ;
if ( V_183 . V_184 != V_185 )
V_30 -> V_23 -> V_139 |= V_186 ;
else
V_30 -> V_23 -> V_139 &= ~ V_186 ;
V_30 -> V_23 -> V_139 |= V_187 ;
V_30 -> V_23 -> V_188 = V_165 ;
V_30 -> V_23 -> V_189 = V_190 ;
V_30 -> V_23 -> V_191 =
V_192 - 24 - 2 ;
V_30 -> V_23 -> V_193 = V_194 ;
V_30 -> V_23 -> V_195 = V_196 ;
V_30 -> V_23 -> V_197 = 254 ;
V_30 -> V_23 -> V_123 |= V_198 |
V_199 |
V_200 |
V_201 |
V_202 |
V_203 |
V_204 ;
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_205 ) )
V_30 -> V_23 -> V_123 |= V_206 ;
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_207 ) )
V_30 -> V_23 -> V_123 |= V_208 ;
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_209 ) )
V_30 -> V_23 -> V_123 |=
V_210 ;
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_211 ) )
V_30 -> V_23 -> V_123 |= V_212 ;
if ( F_49 ( & V_2 -> V_105 -> V_170 ,
V_213 ) ) {
F_50 ( V_30 -> V_23 ,
V_214 ) ;
F_50 ( V_30 -> V_23 ,
V_215 ) ;
F_50 ( V_30 -> V_23 ,
V_216 ) ;
}
V_2 -> V_217 = V_218 ;
#ifdef F_51
if ( F_2 ( V_2 ) &&
F_52 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_219 . V_139 = V_220 ;
V_30 -> V_23 -> V_219 = & V_2 -> V_219 ;
}
if ( V_2 -> V_105 -> V_221 [ V_222 ] . V_223 [ 0 ] . V_224 &&
V_2 -> V_7 -> V_225 -> V_226 &&
V_2 -> V_7 -> V_225 -> V_227 &&
F_52 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_219 . V_139 |= V_228 |
V_229 |
V_230 |
V_231 |
V_232 ;
if ( ! V_99 . V_100 )
V_2 -> V_219 . V_139 |= V_233 |
V_234 |
V_235 ;
V_2 -> V_219 . V_236 = V_237 ;
V_2 -> V_219 . V_238 = V_239 ;
V_2 -> V_219 . V_240 = V_241 ;
V_2 -> V_219 . V_242 = V_190 ;
V_2 -> V_219 . V_243 = & V_244 ;
V_30 -> V_23 -> V_219 = & V_2 -> V_219 ;
}
#endif
#ifdef F_53
V_2 -> V_245 = V_246 ;
#endif
V_47 = F_54 ( V_2 ) ;
if ( V_47 )
return V_47 ;
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_247 ) ) {
F_55 ( V_2 , L_10 ) ;
V_30 -> V_23 -> V_139 |= V_248 ;
F_38 ( V_30 , V_249 ) ;
}
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_250 ) ) {
F_55 ( V_2 , L_11 ) ;
V_30 -> V_23 -> V_123 |= V_251 ;
}
V_30 -> V_75 |= V_2 -> V_37 -> V_123 ;
if ( ! F_56 ( V_2 ) ) {
V_30 -> V_75 &= ~ ( V_252 |
V_253 ) ;
if ( V_254 )
V_30 -> V_75 |= V_252 ;
}
V_47 = F_57 ( V_2 -> V_30 ) ;
if ( V_47 )
F_58 ( V_2 ) ;
if ( V_2 -> V_37 -> V_255 )
F_50 ( V_30 -> V_23 ,
V_256 ) ;
return V_47 ;
}
static bool F_59 ( struct V_1 * V_2 ,
struct V_257 * V_258 ,
struct V_259 * V_260 )
{
struct V_128 * V_261 ;
bool V_262 = false ;
if ( F_60 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_61 ( & V_2 -> V_263 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_34;
V_261 = F_62 ( V_258 ) ;
if ( V_261 -> V_264 == V_265 ||
V_261 -> V_264 != V_2 -> V_266 )
goto V_34;
F_63 ( & V_2 -> V_267 , V_260 ) ;
F_64 ( V_2 -> V_30 ) ;
F_1 ( V_2 , V_268 ) ;
F_7 ( V_2 , V_268 ) ;
V_262 = true ;
V_34:
F_65 ( & V_2 -> V_263 ) ;
return V_262 ;
}
static void F_66 ( struct V_29 * V_30 ,
struct V_269 * V_270 ,
struct V_259 * V_260 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_257 * V_258 = V_270 -> V_258 ;
struct V_271 * V_272 = F_67 ( V_260 ) ;
struct V_273 * V_274 = ( void * ) V_260 -> V_275 ;
if ( F_68 ( V_2 ) ) {
F_69 ( V_2 , L_12 ) ;
goto V_276;
}
if ( F_67 ( V_260 ) -> V_277 == V_82 &&
! F_14 ( V_278 , & V_2 -> V_15 ) &&
! F_14 ( V_279 , & V_2 -> V_15 ) )
goto V_276;
if ( F_70 ( V_272 -> V_139 & V_280 &&
F_71 ( V_274 -> V_281 ) &&
! F_72 ( V_274 -> V_281 ) &&
! F_73 ( V_274 -> V_281 ) &&
! F_74 ( V_274 -> V_281 ) ) )
V_258 = NULL ;
if ( V_258 ) {
if ( F_59 ( V_2 , V_258 , V_260 ) )
return;
if ( F_75 ( V_2 , V_260 , V_258 ) )
goto V_276;
return;
}
if ( F_76 ( V_2 , V_260 ) )
goto V_276;
return;
V_276:
F_77 ( V_30 , V_260 ) ;
}
static inline bool F_78 ( const struct V_282 * V_37 )
{
if ( V_99 . V_283 & V_284 )
return false ;
return true ;
}
static inline bool F_79 ( const struct V_282 * V_37 )
{
if ( V_99 . V_283 & V_285 )
return false ;
if ( V_99 . V_283 & V_286 )
return true ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 , struct V_287 * V_288 ,
struct V_257 * V_258 , V_132 V_289 , V_132 V_290 ,
enum V_291 V_292 )
{
struct V_293 * V_294 ;
struct V_295 * V_296 ;
if ( ! F_81 ( V_2 -> V_105 , V_297 ) )
return;
V_294 = F_82 ( V_2 -> V_105 , V_297 ) ;
V_296 = ( void * ) V_294 -> V_275 ;
if ( ! F_83 ( V_2 , V_288 , V_294 ) )
return;
switch ( V_292 ) {
case V_298 : {
struct V_128 * V_261 = F_62 ( V_258 ) ;
struct V_299 * V_300 = & V_261 -> V_300 [ V_289 ] ;
F_84 ( V_2 , V_294 , V_296 -> V_301 , V_289 ,
L_13 ,
V_258 -> V_156 , V_289 , V_300 -> V_302 ) ;
break;
}
case V_303 :
F_84 ( V_2 , V_294 , V_296 -> V_304 , V_289 ,
L_14 ,
V_258 -> V_156 , V_289 ) ;
break;
case V_305 :
F_84 ( V_2 , V_294 , V_296 -> V_306 , V_289 ,
L_15 ,
V_258 -> V_156 , V_289 , V_290 ) ;
break;
case V_307 :
F_84 ( V_2 , V_294 , V_296 -> V_308 , V_289 ,
L_16 ,
V_258 -> V_156 , V_289 ) ;
break;
default:
break;
}
}
static int F_85 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_309 * V_310 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_311 = false ;
struct V_257 * V_258 = V_310 -> V_258 ;
enum V_291 V_292 = V_310 -> V_292 ;
V_132 V_289 = V_310 -> V_289 ;
V_132 * V_302 = & V_310 -> V_302 ;
T_2 V_312 = V_310 -> V_312 ;
bool V_313 = V_310 -> V_313 ;
V_132 V_314 = V_310 -> V_314 ;
F_86 ( V_2 , L_17 ,
V_258 -> V_156 , V_289 , V_292 ) ;
if ( ! ( V_2 -> V_157 -> V_315 ) )
return - V_316 ;
switch ( V_292 ) {
case V_317 :
case V_303 :
case V_318 :
case V_319 :
case V_298 :
V_47 = F_12 ( V_2 , V_320 ) ;
if ( V_47 )
return V_47 ;
V_311 = true ;
break;
default:
break;
}
F_87 ( & V_2 -> V_33 ) ;
switch ( V_292 ) {
case V_305 :
if ( ! F_78 ( V_2 -> V_37 ) ) {
V_47 = - V_321 ;
break;
}
V_47 = F_88 ( V_2 , V_258 , V_289 , * V_302 , true , V_312 ,
V_314 ) ;
break;
case V_307 :
V_47 = F_88 ( V_2 , V_258 , V_289 , 0 , false , V_312 ,
V_314 ) ;
break;
case V_317 :
if ( ! F_79 ( V_2 -> V_37 ) ) {
V_47 = - V_321 ;
break;
}
V_47 = F_89 ( V_2 , V_288 , V_258 , V_289 , V_302 ) ;
break;
case V_303 :
V_47 = F_90 ( V_2 , V_288 , V_258 , V_289 ) ;
break;
case V_318 :
case V_319 :
V_47 = F_91 ( V_2 , V_288 , V_258 , V_289 ) ;
break;
case V_298 :
V_47 = F_92 ( V_2 , V_288 , V_258 , V_289 ,
V_312 , V_313 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_321 ;
break;
}
if ( ! V_47 ) {
V_132 V_290 = 0 ;
if ( V_292 == V_305 )
V_290 = * V_302 ;
F_80 ( V_2 , V_288 , V_258 , V_289 ,
V_290 , V_292 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
if ( V_311 )
F_7 ( V_2 , V_320 ) ;
return V_47 ;
}
static void F_94 ( void * V_275 , T_2 * V_322 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = V_275 ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
V_323 -> V_324 = false ;
V_323 -> V_325 = V_265 ;
F_4 ( & V_2 -> V_326 ) ;
F_96 ( V_2 , & V_323 -> V_327 ) ;
F_5 ( & V_2 -> V_326 ) ;
V_323 -> V_328 = NULL ;
memset ( & V_323 -> V_329 , 0 , sizeof( V_323 -> V_329 ) ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
if ( ! F_98 ( V_330 , & V_2 -> V_15 ) ) {
V_2 -> V_331 = & V_332 ;
F_99 ( V_2 ) ;
}
F_10 ( V_2 , V_333 ) ;
F_100 ( V_2 ) ;
V_2 -> V_334 = 0 ;
V_2 -> V_335 = false ;
V_2 -> V_336 = false ;
F_101 ( V_2 ) ;
F_102 ( V_2 -> V_30 ) ;
F_103 ( V_2 -> V_30 , 0 , F_94 , V_2 ) ;
V_2 -> V_337 = NULL ;
V_2 -> V_266 = V_265 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_338 , 0 , sizeof( V_2 -> V_338 ) ) ;
memset ( V_2 -> V_339 , 0 , sizeof( V_2 -> V_339 ) ) ;
memset ( V_2 -> V_340 , 0 , sizeof( V_2 -> V_340 ) ) ;
memset ( V_2 -> V_341 , 0 , sizeof( V_2 -> V_341 ) ) ;
memset ( & V_2 -> V_342 , 0 , sizeof( V_2 -> V_342 ) ) ;
memset ( & V_2 -> V_343 , 0 , sizeof( V_2 -> V_343 ) ) ;
F_104 ( V_2 -> V_30 ) ;
F_105 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_344 = 0 ;
V_2 -> V_345 = 0 ;
V_2 -> V_346 = V_347 ;
F_106 ( V_2 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_348 , & V_2 -> V_15 ) ) {
F_97 ( V_2 ) ;
} else {
F_1 ( V_2 , V_333 ) ;
}
V_47 = F_108 ( V_2 ) ;
if ( V_47 && F_14 ( V_348 , & V_2 -> V_15 ) ) {
F_105 ( V_348 , & V_2 -> V_15 ) ;
F_109 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_110 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_348 , & V_2 -> V_15 ) ) {
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
F_105 ( V_348 , & V_2 -> V_15 ) ;
F_109 ( V_2 , NULL ) ;
V_47 = F_112 ( V_2 , true , NULL ) ;
if ( V_47 )
F_113 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_333 ) ;
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
enum V_349 V_350 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_350 ) {
case V_351 :
F_111 ( V_2 ) ;
break;
case V_352 :
F_115 ( V_2 ) ;
break;
}
}
void F_119 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_353 , 0 , sizeof( V_2 -> V_353 ) ) ;
F_120 ( & V_2 -> V_354 ) ;
F_100 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
if ( F_98 ( V_348 , & V_2 -> V_15 ) )
F_103 ( V_2 -> V_30 , 0 ,
F_94 , V_2 ) ;
if ( F_48 ( & V_2 -> V_105 -> V_170 , V_171 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_172 ; V_9 ++ ) {
if ( F_117 ( V_2 -> V_355 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_355 [ V_9 ] = 0 ;
}
}
}
static void F_124 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_120 ( & V_2 -> V_356 ) ;
F_120 ( & V_2 -> V_357 ) ;
F_120 ( & V_2 -> V_358 ) ;
F_125 ( & V_2 -> V_359 ) ;
F_125 ( & V_2 -> V_360 ) ;
F_125 ( & V_2 -> V_361 ) ;
F_126 ( V_2 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_119 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_127 ( & V_2 -> V_357 ) ;
}
static struct V_362 * F_128 ( struct V_1 * V_2 )
{
V_132 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_113 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_129 ( struct V_1 * V_2 , struct V_287 * V_288 ,
T_3 V_363 )
{
struct V_364 V_365 = {
. V_366 . V_367 = F_130 ( V_368 ) ,
. V_366 . V_369 =
F_130 ( F_95 ( V_288 ) -> V_20 ) ,
. V_366 . V_370 = F_131 ( 8 * V_363 ) ,
} ;
int V_224 = sizeof( V_365 ) ;
if ( V_363 == V_371 )
V_365 . V_366 . V_370 = F_131 ( V_372 ) ;
if ( ! F_48 ( & V_2 -> V_105 -> V_170 , V_373 ) )
V_224 = sizeof( V_365 . V_366 ) ;
return F_132 ( V_2 , V_374 , 0 , V_224 , & V_365 ) ;
}
static int F_133 ( struct V_29 * V_30 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
int V_47 ;
V_323 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_375 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_348 , & V_2 -> V_15 ) )
V_323 -> V_376 . V_377 +=
V_323 -> V_376 . V_378 ;
V_47 = F_134 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_379;
if ( V_288 -> type != V_137 )
V_2 -> V_344 ++ ;
if ( V_288 -> type == V_135 ||
V_288 -> type == V_138 ) {
V_47 = F_135 ( V_2 , V_288 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_22 ) ;
goto V_380;
}
F_136 ( V_2 , V_288 ) ;
goto V_379;
}
V_323 -> V_123 |= V_30 -> V_75 ;
V_47 = F_137 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_380;
V_47 = F_138 ( V_2 ) ;
if ( V_47 )
goto V_381;
V_47 = F_139 ( V_2 , V_288 , 0 ) ;
if ( V_47 )
goto V_381;
if ( ! V_2 -> V_382 &&
V_288 -> type == V_113 && ! V_288 -> V_383 ) {
V_2 -> V_382 = V_323 ;
V_288 -> V_384 |= V_385 |
V_386 ;
}
if ( V_288 -> type == V_137 ) {
V_323 -> V_328 = F_128 ( V_2 ) ;
if ( ! V_323 -> V_328 ) {
V_47 = - V_387 ;
goto V_388;
}
F_140 ( V_2 , V_323 -> V_328 ) ;
V_47 = F_141 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_389;
V_47 = F_142 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_390;
V_2 -> V_337 = V_288 ;
}
F_136 ( V_2 , V_288 ) ;
goto V_379;
V_390:
F_143 ( V_2 , V_288 ) ;
V_389:
F_144 ( V_2 , V_323 -> V_328 ) ;
V_388:
if ( V_2 -> V_382 == V_323 ) {
V_2 -> V_382 = NULL ;
V_288 -> V_384 &= ~ ( V_385 |
V_386 ) ;
}
V_381:
V_323 -> V_328 = NULL ;
F_145 ( V_2 , V_288 ) ;
V_380:
if ( V_288 -> type != V_137 )
V_2 -> V_344 -- ;
F_146 ( V_2 , V_288 ) ;
V_379:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_375 ) ;
return V_47 ;
}
static void F_147 ( struct V_1 * V_2 ,
struct V_287 * V_288 )
{
T_1 V_391 = F_148 ( V_288 ) ;
if ( V_391 ) {
F_87 ( & V_2 -> V_33 ) ;
F_149 ( V_2 , V_391 , 0 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_150 ( V_2 -> V_7 , V_391 ) ;
}
if ( V_288 -> type == V_137 ) {
F_120 ( & V_2 -> V_354 ) ;
} else {
F_120 ( & V_2 -> V_392 ) ;
}
}
static void F_151 ( struct V_29 * V_30 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
F_147 ( V_2 , V_288 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_382 == V_323 ) {
V_2 -> V_382 = NULL ;
V_288 -> V_384 &= ~ ( V_385 |
V_386 ) ;
}
F_152 ( V_2 , V_288 ) ;
if ( V_288 -> type == V_135 ||
V_288 -> type == V_138 ) {
#ifdef F_153
if ( V_288 == V_2 -> V_393 ) {
V_2 -> V_393 = NULL ;
V_2 -> V_394 = 0 ;
}
#endif
F_154 ( V_2 , V_288 ) ;
goto V_380;
}
if ( V_288 -> type == V_137 ) {
V_2 -> V_337 = NULL ;
F_155 ( V_2 , V_288 ) ;
F_143 ( V_2 , V_288 ) ;
F_144 ( V_2 , V_323 -> V_328 ) ;
V_323 -> V_328 = NULL ;
}
if ( V_2 -> V_344 && V_288 -> type != V_137 )
V_2 -> V_344 -- ;
F_138 ( V_2 ) ;
F_145 ( V_2 , V_288 ) ;
V_380:
F_146 ( V_2 , V_288 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_156 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_157 ( void * V_395 , T_2 * V_322 ,
struct V_287 * V_288 )
{
struct V_396 * V_275 = V_395 ;
struct V_1 * V_2 = V_275 -> V_2 ;
struct V_397 * V_365 = V_2 -> V_398 ;
int V_47 , V_224 ;
if ( F_15 ( V_275 -> V_399 >= V_400 ) )
return;
if ( V_288 -> type != V_113 ||
! V_288 -> V_401 . V_402 )
return;
V_365 -> V_399 = V_275 -> V_399 ++ ;
memcpy ( V_365 -> V_403 , V_288 -> V_401 . V_403 , V_159 ) ;
V_224 = F_158 ( sizeof( * V_365 ) + V_365 -> V_404 * V_159 , 4 ) ;
V_47 = F_132 ( V_2 , V_405 , V_406 , V_224 , V_365 ) ;
if ( V_47 )
F_113 ( V_2 , L_23 , V_47 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_396 V_407 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_398 ) )
return;
F_160 (
V_2 -> V_30 , V_408 ,
F_157 , & V_407 ) ;
}
static T_4 F_161 ( struct V_29 * V_30 ,
struct V_409 * V_410 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_397 * V_365 ;
struct V_411 * V_156 ;
int V_412 ;
bool V_413 ;
int V_224 ;
V_412 = F_162 ( V_410 ) ;
V_413 = V_412 > V_414 ||
V_415 ;
if ( V_413 )
V_412 = 0 ;
V_224 = F_158 ( sizeof( * V_365 ) + V_412 * V_159 , 4 ) ;
V_365 = F_163 ( V_224 , V_416 ) ;
if ( ! V_365 )
return 0 ;
if ( V_413 ) {
V_365 -> V_413 = 1 ;
return ( T_4 ) ( unsigned long ) V_365 ;
}
F_164 (addr, mc_list) {
F_165 ( V_2 , L_24 ,
V_365 -> V_404 , V_156 -> V_156 ) ;
memcpy ( & V_365 -> V_417 [ V_365 -> V_404 * V_159 ] ,
V_156 -> V_156 , V_159 ) ;
V_365 -> V_404 ++ ;
}
return ( T_4 ) ( unsigned long ) V_365 ;
}
static void F_166 ( struct V_29 * V_30 ,
unsigned int V_418 ,
unsigned int * V_419 ,
T_4 V_420 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_397 * V_365 = ( void * ) ( unsigned long ) V_420 ;
F_87 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_398 ) ;
V_2 -> V_398 = V_365 ;
if ( ! V_365 )
goto V_34;
F_159 ( V_2 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
* V_419 = 0 ;
}
static void F_167 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
unsigned int V_421 ,
unsigned int V_418 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_418 & V_422 ) )
return;
if ( V_288 -> type != V_113 || ! V_288 -> V_401 . V_402 ||
! V_288 -> V_383 )
return;
F_87 ( & V_2 -> V_33 ) ;
F_168 ( V_2 , V_288 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_169 ( struct V_287 * V_288 ,
const struct V_423 * V_424 ,
struct V_423 * V_425 )
{
struct V_426 * V_427 ;
int V_9 ;
memcpy ( V_425 , V_424 , sizeof( * V_425 ) ) ;
for ( V_9 = 0 ; V_9 < F_42 ( V_425 -> V_428 ) ; V_9 ++ ) {
V_427 = & V_425 -> V_428 [ V_9 ] ;
if ( ! V_427 -> V_429 )
break;
switch ( V_427 -> V_430 ) {
case F_131 ( V_431 ) :
if ( V_288 -> V_401 . V_432 != 1 ) {
V_427 -> V_429 = 0 ;
continue;
}
V_427 -> V_433 = V_288 -> V_401 . V_434 [ 0 ] ;
break;
case F_131 ( V_435 ) :
V_427 -> V_433 = * ( V_436 * ) & V_288 -> V_156 [ 2 ] ;
break;
default:
break;
}
V_427 -> V_430 = 0 ;
V_425 -> V_437 ++ ;
}
}
static void F_170 ( void * V_395 , T_2 * V_322 ,
struct V_287 * V_288 )
{
struct V_438 * V_275 = V_395 ;
struct V_1 * V_2 = V_275 -> V_2 ;
struct V_439 * V_365 = V_275 -> V_365 ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
struct V_440 * V_441 ;
int V_9 ;
if ( F_8 ( V_323 -> V_20 >= F_42 ( V_365 -> V_442 ) ) )
return;
V_441 = & V_365 -> V_442 [ V_323 -> V_20 ] ;
if ( V_288 -> type != V_113 || V_288 -> V_383 ||
! V_288 -> V_401 . V_402 )
return;
V_441 -> V_443 = 1 ;
for ( V_9 = 0 ; V_2 -> V_245 [ V_9 ] . V_428 [ 0 ] . V_429 ; V_9 ++ ) {
if ( F_15 ( V_275 -> V_444 >=
F_42 ( V_365 -> V_445 ) ) ) {
V_441 -> V_443 = 0 ;
V_441 -> V_446 = 0 ;
break;
}
F_169 ( V_288 ,
& V_2 -> V_245 [ V_9 ] ,
& V_365 -> V_445 [ V_275 -> V_444 ] ) ;
if ( ! V_365 -> V_445 [ V_275 -> V_444 ] . V_437 )
continue;
V_441 -> V_446 |=
F_131 ( F_44 ( V_275 -> V_444 ) ) ;
V_275 -> V_444 ++ ;
}
}
bool F_171 ( struct V_1 * V_2 ,
struct V_439 * V_365 )
{
struct V_438 V_407 = {
. V_2 = V_2 ,
. V_365 = V_365 ,
} ;
if ( V_447 )
return false ;
memset ( V_365 , 0 , sizeof( * V_365 ) ) ;
V_365 -> V_448 = F_42 ( V_365 -> V_445 ) ;
V_365 -> V_449 = F_42 ( V_365 -> V_442 ) ;
#ifdef F_172
if ( V_2 -> V_450 . V_451 ) {
memcpy ( V_365 -> V_445 , & V_2 -> V_450 . V_365 . V_445 ,
sizeof( V_365 -> V_445 ) ) ;
memcpy ( V_365 -> V_442 , & V_2 -> V_450 . V_365 . V_442 ,
sizeof( V_365 -> V_442 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_245 )
return false ;
F_173 (
V_2 -> V_30 , V_408 ,
F_170 , & V_407 ) ;
return true ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_439 V_365 ;
if ( ! ( V_2 -> V_105 -> V_170 . V_139 & V_452 ) )
return 0 ;
if ( ! F_171 ( V_2 , & V_365 ) )
return 0 ;
return F_132 ( V_2 , V_453 , 0 ,
sizeof( V_365 ) , & V_365 ) ;
}
static inline int F_174 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_175 ( struct V_1 * V_2 ,
struct V_287 * V_288 )
{
struct V_454 V_365 = {} ;
memcpy ( V_365 . V_455 , V_288 -> V_401 . V_456 . V_457 ,
V_458 ) ;
memcpy ( V_365 . V_459 , V_288 -> V_401 . V_456 . V_460 ,
V_461 ) ;
return F_132 ( V_2 ,
F_176 ( V_462 ,
V_463 ) ,
0 , sizeof( V_365 ) , & V_365 ) ;
}
static void F_177 ( void * V_395 , T_2 * V_322 ,
struct V_287 * V_288 )
{
if ( V_288 -> V_464 ) {
struct V_465 * V_466 = V_395 ;
F_178 ( V_288 ,
( T_2 * ) & V_466 -> V_455 ,
( T_2 * ) & V_466 -> V_459 ) ;
}
}
void F_179 ( struct V_1 * V_2 ,
struct V_467 * V_468 )
{
struct V_469 * V_470 = F_180 ( V_468 ) ;
struct V_465 * V_466 = ( void * ) V_470 -> V_275 ;
F_160 (
V_2 -> V_30 , V_408 ,
F_177 , V_466 ) ;
}
static void F_181 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
struct V_471 * V_401 ,
T_1 V_472 )
{
struct V_130 * V_323 = F_95 ( V_288 ) ;
int V_47 ;
if ( V_472 & V_473 && V_401 -> V_402 )
F_182 ( V_2 , V_288 ) ;
if ( V_472 & V_473 && ! V_401 -> V_402 &&
V_323 -> V_474 )
F_183 ( V_288 , V_475 ,
0 , 0 ) ;
if ( V_472 & V_476 && ! V_323 -> V_477 )
memcpy ( V_323 -> V_403 , V_401 -> V_403 , V_159 ) ;
V_47 = F_168 ( V_2 , V_288 , false , V_323 -> V_403 ) ;
if ( V_47 )
F_113 ( V_2 , L_25 , V_288 -> V_156 ) ;
memcpy ( V_323 -> V_403 , V_401 -> V_403 , V_159 ) ;
V_323 -> V_477 = V_401 -> V_402 ;
if ( V_472 & V_473 ) {
if ( V_401 -> V_402 ) {
F_184 ( V_2 , true ) ;
memset ( & V_323 -> V_376 , 0 ,
sizeof( V_323 -> V_376 ) ) ;
V_47 = F_112 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_113 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_348 ,
& V_2 -> V_15 ) ) {
T_1 V_478 = ( 11 * V_288 -> V_401 . V_479 ) / 10 ;
F_185 ( V_2 , V_288 , V_478 , V_478 ,
5 * V_478 , false ) ;
}
F_186 ( V_2 , V_288 , false ) ;
F_187 ( V_2 , V_288 ) ;
if ( V_288 -> V_383 ) {
F_1 ( V_2 , V_480 ) ;
F_188 ( V_2 , V_288 ,
V_481 ,
V_482 ) ;
}
} else if ( V_323 -> V_325 != V_265 ) {
F_117 ( F_186 ( V_2 , V_288 , false ) ,
L_27 ) ;
V_47 = F_189 ( V_2 , V_288 , V_323 -> V_325 ) ;
if ( V_47 )
F_113 ( V_2 , L_28 ) ;
if ( V_2 -> V_266 == V_323 -> V_325 )
V_2 -> V_266 = V_265 ;
V_323 -> V_325 = V_265 ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
F_113 ( V_2 , L_26 ) ;
if ( V_288 -> V_383 )
F_7 ( V_2 , V_480 ) ;
V_47 = F_168 ( V_2 , V_288 , false , NULL ) ;
if ( V_47 )
F_113 ( V_2 ,
L_29 ,
V_288 -> V_156 ) ;
}
if ( F_14 ( V_348 , & V_2 -> V_15 ) &&
( V_472 & V_483 ) && V_288 -> V_464 ) {
V_47 = F_175 ( V_2 , V_288 ) ;
if ( V_47 )
F_113 ( V_2 ,
L_30 ) ;
}
F_159 ( V_2 ) ;
F_174 ( V_2 ) ;
V_323 -> V_329 . V_484 = 0 ;
F_190 ( V_2 ) ;
F_188 ( V_2 , V_288 , V_485 ,
V_486 ) ;
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_171 ) )
F_191 ( V_2 ) ;
} else if ( V_472 & V_487 ) {
F_192 ( V_2 , V_323 ,
& V_323 -> V_327 ) ;
}
if ( V_472 & V_487 ) {
F_186 ( V_2 , V_288 , false ) ;
F_8 ( F_193 ( V_2 , V_288 , 0 ) ) ;
}
if ( V_472 & ( V_488 | V_489 | V_490 |
V_487 ) ) {
V_47 = F_138 ( V_2 ) ;
if ( V_47 )
F_113 ( V_2 , L_31 ) ;
}
if ( V_472 & V_491 ) {
F_194 ( V_2 , L_32 ,
V_401 -> V_492 ) ;
F_129 ( V_2 , V_288 , V_401 -> V_492 ) ;
}
if ( V_472 & V_493 ) {
F_165 ( V_2 , L_33 ) ;
V_323 -> V_329 . V_494 = 0 ;
if ( V_323 -> V_329 . V_495 ) {
V_47 = F_193 ( V_2 , V_288 , 0 ) ;
if ( V_47 )
F_113 ( V_2 ,
L_34 ) ;
}
}
if ( V_472 & V_496 ) {
F_165 ( V_2 , L_35 ) ;
F_174 ( V_2 ) ;
}
}
static int F_195 ( struct V_29 * V_30 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_497 ) ;
if ( V_47 )
return V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_196 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_379;
if ( V_288 -> type == V_135 )
F_182 ( V_2 , V_288 ) ;
V_323 -> V_498 = 0 ;
V_47 = F_137 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_379;
V_47 = F_141 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_499;
V_47 = F_197 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_390;
V_323 -> V_500 = true ;
F_138 ( V_2 ) ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_501;
if ( V_288 -> V_383 && V_2 -> V_337 )
F_168 ( V_2 , V_2 -> V_337 , false , NULL ) ;
F_1 ( V_2 , V_502 ) ;
F_190 ( V_2 ) ;
if ( F_198 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
goto V_379;
V_501:
F_138 ( V_2 ) ;
V_323 -> V_500 = false ;
F_199 ( V_2 , V_288 ) ;
V_390:
F_143 ( V_2 , V_288 ) ;
V_499:
F_145 ( V_2 , V_288 ) ;
V_379:
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_497 ) ;
return V_47 ;
}
static void F_200 ( struct V_29 * V_30 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
F_147 ( V_2 , V_288 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( F_201 ( V_2 -> V_503 ) == V_288 ) {
F_192 ( V_2 , V_323 ,
& V_323 -> V_327 ) ;
F_202 ( V_2 -> V_503 , NULL ) ;
V_323 -> V_504 = false ;
}
if ( F_201 ( V_2 -> V_505 ) == V_288 ) {
F_202 ( V_2 -> V_505 , NULL ) ;
V_2 -> V_506 = 0 ;
}
V_323 -> V_500 = false ;
V_2 -> V_507 = 0 ;
F_190 ( V_2 ) ;
F_7 ( V_2 , V_502 ) ;
if ( V_288 -> V_383 && V_2 -> V_337 )
F_168 ( V_2 , V_2 -> V_337 , false , NULL ) ;
F_112 ( V_2 , false , NULL ) ;
F_199 ( V_2 , V_288 ) ;
F_143 ( V_2 , V_288 ) ;
F_138 ( V_2 ) ;
F_145 ( V_2 , V_288 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_203 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
struct V_471 * V_401 ,
T_1 V_472 )
{
struct V_130 * V_323 = F_95 ( V_288 ) ;
if ( ! V_323 -> V_500 )
return;
if ( V_472 & ( V_508 | V_509 |
V_510 | V_490 ) &&
F_168 ( V_2 , V_288 , false , NULL ) )
F_113 ( V_2 , L_25 , V_288 -> V_156 ) ;
if ( V_472 & V_511 &&
F_196 ( V_2 , V_288 ) )
F_204 ( V_2 , L_36 ) ;
if ( V_472 & V_491 ) {
F_194 ( V_2 , L_32 ,
V_401 -> V_492 ) ;
F_129 ( V_2 , V_288 , V_401 -> V_492 ) ;
}
}
static void F_205 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_471 * V_401 ,
T_1 V_472 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_512 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_472 & V_513 && ! V_401 -> V_514 )
F_206 ( V_2 , V_515 , true ) ;
switch ( V_288 -> type ) {
case V_113 :
F_181 ( V_2 , V_288 , V_401 , V_472 ) ;
break;
case V_135 :
case V_138 :
F_203 ( V_2 , V_288 , V_401 , V_472 ) ;
break;
case V_516 :
if ( V_472 & V_483 )
F_175 ( V_2 , V_288 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_512 ) ;
}
static int F_207 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_517 * V_518 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_518 -> V_519 . V_38 == 0 ||
V_518 -> V_519 . V_38 > V_2 -> V_105 -> V_170 . V_520 )
return - V_321 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_208 ( V_2 , V_288 , & V_518 -> V_519 , & V_518 -> V_521 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_209 ( struct V_29 * V_30 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_334 & V_522 )
F_206 ( V_2 , V_522 , true ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void
F_210 ( struct V_29 * V_30 ,
struct V_257 * V_258 , V_132 V_523 ,
int V_524 ,
enum V_525 V_526 ,
bool V_527 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_211 ( V_2 , V_258 , V_526 , V_524 ,
V_523 , V_527 , false ) ;
}
static void
F_212 ( struct V_29 * V_30 ,
struct V_257 * V_258 , V_132 V_523 ,
int V_524 ,
enum V_525 V_526 ,
bool V_527 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_211 ( V_2 , V_258 , V_526 , V_524 ,
V_523 , V_527 , true ) ;
}
static void F_213 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
enum V_528 V_365 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_128 * V_261 = F_62 ( V_258 ) ;
unsigned long V_529 = 0 , V_523 = 0 ;
int V_289 ;
F_4 ( & V_261 -> V_530 ) ;
for ( V_289 = 0 ; V_289 < V_531 ; V_289 ++ ) {
struct V_299 * V_300 = & V_261 -> V_300 [ V_289 ] ;
if ( V_300 -> V_532 != V_533 &&
V_300 -> V_532 != V_534 )
continue;
F_214 ( V_300 -> V_535 , & V_529 ) ;
if ( F_215 ( V_300 ) == 0 )
continue;
F_214 ( V_289 , & V_523 ) ;
}
switch ( V_365 ) {
case V_536 :
if ( F_216 ( & V_2 -> V_537 [ V_261 -> V_264 ] ) > 0 )
F_217 ( V_30 , V_258 , true ) ;
F_218 (tid, &tids, IWL_MAX_TID_COUNT)
F_219 ( V_258 , V_289 , true ) ;
if ( V_529 )
F_220 ( V_2 -> V_7 , V_529 , true ) ;
break;
case V_538 :
if ( F_8 ( V_261 -> V_264 == V_265 ) )
break;
if ( V_529 )
F_220 ( V_2 -> V_7 , V_529 , false ) ;
F_221 ( V_2 , V_258 ) ;
break;
default:
break;
}
F_5 ( & V_261 -> V_530 ) ;
}
static void F_222 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_128 * V_539 = F_62 ( V_258 ) ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_258 == F_201 ( V_2 -> V_540 [ V_539 -> V_264 ] ) )
F_223 ( V_2 -> V_540 [ V_539 -> V_264 ] ,
F_224 ( - V_49 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_225 ( struct V_1 * V_2 , struct V_287 * V_288 ,
const T_2 * V_403 )
{
if ( ! ( V_2 -> V_105 -> V_170 . V_139 & V_541 ) )
return;
if ( V_288 -> V_383 && ! F_226 ( V_2 ) ) {
V_288 -> V_384 &= ~ V_542 ;
return;
}
if ( ! V_288 -> V_383 &&
( V_99 . V_543 & V_544 ) ) {
V_288 -> V_384 &= ~ V_542 ;
return;
}
V_288 -> V_384 |= V_542 ;
}
static void
F_227 ( struct V_1 * V_2 ,
struct V_287 * V_288 , T_2 * V_545 ,
enum V_546 V_292 )
{
struct V_293 * V_294 ;
struct V_547 * V_548 ;
if ( ! F_81 ( V_2 -> V_105 , V_549 ) )
return;
V_294 = F_82 ( V_2 -> V_105 , V_549 ) ;
V_548 = ( void * ) V_294 -> V_275 ;
if ( ! F_83 ( V_2 , V_288 , V_294 ) )
return;
if ( ! ( V_548 -> V_550 & F_44 ( V_292 ) ) )
return;
if ( V_548 -> V_551 &&
memcmp ( V_548 -> V_552 , V_545 , V_159 ) != 0 )
return;
F_228 ( V_2 , V_294 ,
L_37 ,
V_545 , V_292 ) ;
}
static void F_229 ( struct V_1 * V_2 ,
struct V_128 * V_539 )
{
struct V_299 * V_300 ;
struct V_259 * V_260 ;
int V_9 ;
F_4 ( & V_539 -> V_530 ) ;
for ( V_9 = 0 ; V_9 <= V_531 ; V_9 ++ ) {
V_300 = & V_539 -> V_300 [ V_9 ] ;
while ( ( V_260 = F_230 ( & V_300 -> V_553 ) ) )
F_77 ( V_2 -> V_30 , V_260 ) ;
}
F_5 ( & V_539 -> V_530 ) ;
}
static int F_231 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_257 * V_258 ,
enum V_554 V_555 ,
enum V_554 V_556 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
int V_47 ;
F_165 ( V_2 , L_38 ,
V_258 -> V_156 , V_555 , V_556 ) ;
if ( F_15 ( ! V_323 -> V_328 ) )
return - V_321 ;
F_120 ( & V_2 -> V_392 ) ;
if ( V_555 == V_557 &&
V_556 == V_558 &&
F_40 ( V_2 ) ) {
struct V_128 * V_539 = F_62 ( V_258 ) ;
F_229 ( V_2 , V_539 ) ;
F_120 ( & V_2 -> V_358 ) ;
}
F_87 ( & V_2 -> V_33 ) ;
if ( V_555 == V_558 &&
V_556 == V_557 ) {
if ( V_288 -> type == V_113 &&
V_288 -> V_401 . V_479 < 16 ) {
F_113 ( V_2 ,
L_39 ,
V_258 -> V_156 , V_288 -> V_401 . V_479 ) ;
V_47 = - V_321 ;
goto V_379;
}
if ( V_258 -> V_559 &&
( V_288 -> V_383 ||
F_232 ( V_2 , NULL ) ==
V_560 ||
F_198 ( V_2 ) > 1 ) ) {
F_165 ( V_2 , L_40 ) ;
V_47 = - V_561 ;
goto V_379;
}
V_47 = F_233 ( V_2 , V_288 , V_258 ) ;
if ( V_258 -> V_559 && V_47 == 0 ) {
F_234 ( V_2 , V_288 , true ) ;
F_227 ( V_2 , V_288 , V_258 -> V_156 ,
V_562 ) ;
}
} else if ( V_555 == V_557 &&
V_556 == V_563 ) {
V_2 -> V_564 = true ;
F_225 ( V_2 , V_288 , V_258 -> V_156 ) ;
V_47 = 0 ;
} else if ( V_555 == V_563 &&
V_556 == V_565 ) {
if ( V_288 -> type == V_135 ) {
V_323 -> V_498 ++ ;
F_168 ( V_2 , V_288 , false , NULL ) ;
}
V_47 = F_235 ( V_2 , V_288 , V_258 ) ;
if ( V_47 == 0 )
F_236 ( V_2 , V_258 ,
V_323 -> V_328 -> V_566 -> V_567 ,
true ) ;
} else if ( V_555 == V_565 &&
V_556 == V_568 ) {
if ( F_198 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
if ( V_258 -> V_559 )
F_227 ( V_2 , V_288 , V_258 -> V_156 ,
V_569 ) ;
F_8 ( F_193 ( V_2 , V_288 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_555 == V_568 &&
V_556 == V_565 ) {
F_8 ( F_139 ( V_2 , V_288 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_555 == V_565 &&
V_556 == V_563 ) {
if ( V_288 -> type == V_135 ) {
V_323 -> V_498 -- ;
F_168 ( V_2 , V_288 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_555 == V_563 &&
V_556 == V_557 ) {
V_47 = 0 ;
} else if ( V_555 == V_557 &&
V_556 == V_558 ) {
V_47 = F_237 ( V_2 , V_288 , V_258 ) ;
if ( V_258 -> V_559 ) {
F_234 ( V_2 , V_288 , false ) ;
F_227 ( V_2 , V_288 , V_258 -> V_156 ,
V_570 ) ;
}
} else {
V_47 = - V_17 ;
}
V_379:
F_93 ( & V_2 -> V_33 ) ;
if ( V_258 -> V_559 && V_47 == 0 ) {
if ( V_555 == V_558 &&
V_556 == V_557 )
F_238 ( V_258 , V_571 ) ;
else if ( V_555 == V_557 &&
V_556 == V_558 )
F_239 ( V_258 , V_571 ) ;
}
return V_47 ;
}
static int F_240 ( struct V_29 * V_30 , T_1 V_572 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_217 = V_572 ;
return 0 ;
}
static void F_241 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_257 * V_258 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_288 -> type == V_113 &&
V_27 & V_573 )
F_186 ( V_2 , V_288 , false ) ;
}
static int F_242 ( struct V_29 * V_30 ,
struct V_287 * V_288 , V_132 V_574 ,
const struct V_575 * V_310 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
V_323 -> V_576 [ V_574 ] = * V_310 ;
if ( V_288 -> type == V_137 ) {
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_168 ( V_2 , V_288 , false , NULL ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_243 ( struct V_29 * V_30 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_577 = V_578 ;
T_1 V_579 = V_580 ;
if ( F_15 ( V_288 -> V_401 . V_402 ) )
return;
if ( F_12 ( V_2 , V_581 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_185 ( V_2 , V_288 , V_577 , V_579 , 500 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_581 ) ;
}
static int F_244 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_582 * V_519 ,
struct V_583 * V_521 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! V_288 -> V_401 . V_514 ) {
V_47 = - V_561 ;
goto V_34;
}
V_47 = F_245 ( V_2 , V_288 , V_519 , V_521 , V_515 ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_246 ( struct V_29 * V_30 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_334 & V_515 ) ) {
F_93 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_206 ( V_2 , V_515 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
F_247 ( V_2 ) ;
return V_47 ;
}
static int F_248 ( struct V_29 * V_30 ,
enum V_584 V_365 ,
struct V_287 * V_288 ,
struct V_257 * V_258 ,
struct V_585 * V_586 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_128 * V_261 ;
struct V_587 * V_588 ;
int V_589 = V_586 -> V_589 ;
int V_47 ;
T_2 V_590 ;
if ( V_99 . V_100 ) {
F_165 ( V_2 , L_41 ) ;
return - V_591 ;
}
switch ( V_586 -> V_107 ) {
case V_54 :
V_586 -> V_139 |= V_592 ;
V_586 -> V_139 |= V_593 ;
break;
case V_55 :
case V_97 :
case V_98 :
V_586 -> V_139 |= V_593 ;
break;
case V_102 :
case V_103 :
case V_104 :
F_15 ( ! F_249 ( V_30 , V_101 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_288 -> type != V_113 )
return 0 ;
break;
default:
if ( V_30 -> V_111 &&
V_30 -> V_121 -> V_107 == V_586 -> V_107 )
V_586 -> V_139 |= V_593 ;
else
return - V_591 ;
}
F_87 ( & V_2 -> V_33 ) ;
switch ( V_365 ) {
case V_594 :
if ( ( V_288 -> type == V_138 ||
V_288 -> type == V_135 ) && ! V_258 ) {
if ( V_586 -> V_107 == V_102 ||
V_586 -> V_107 == V_103 ||
V_586 -> V_107 == V_104 )
V_47 = - V_591 ;
else
V_47 = 0 ;
V_586 -> V_595 = V_596 ;
break;
}
if ( F_14 ( V_348 , & V_2 -> V_15 ) &&
V_586 -> V_595 == V_596 ) {
F_165 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_348 , & V_2 -> V_15 ) &&
V_258 && F_39 ( V_2 ) &&
V_586 -> V_139 & V_597 &&
( V_586 -> V_107 == V_55 ||
V_586 -> V_107 == V_97 ||
V_586 -> V_107 == V_98 ) ) {
struct V_598 V_599 ;
int V_289 , V_600 ;
V_261 = F_62 ( V_258 ) ;
F_8 ( F_201 ( V_261 -> V_588 [ V_589 ] ) ) ;
V_588 = F_163 ( sizeof( * V_588 ) +
V_2 -> V_7 -> V_72 *
sizeof( V_588 -> V_600 [ 0 ] ) ,
V_601 ) ;
if ( ! V_588 ) {
V_47 = - V_602 ;
break;
}
for ( V_289 = 0 ; V_289 < V_531 ; V_289 ++ ) {
F_250 ( V_586 , V_289 , & V_599 ) ;
for ( V_600 = 0 ; V_600 < V_2 -> V_7 -> V_72 ; V_600 ++ )
memcpy ( V_588 -> V_600 [ V_600 ] . V_603 [ V_289 ] ,
V_599 . V_604 . V_603 ,
V_605 ) ;
}
F_223 ( V_261 -> V_588 [ V_589 ] , V_588 ) ;
}
if ( F_14 ( V_348 , & V_2 -> V_15 ) )
V_590 = V_586 -> V_595 ;
else
V_590 = V_596 ;
F_165 ( V_2 , L_43 ) ;
V_47 = F_251 ( V_2 , V_288 , V_258 , V_586 , V_590 ) ;
if ( V_47 ) {
F_204 ( V_2 , L_44 ) ;
V_586 -> V_595 = V_596 ;
V_47 = 0 ;
}
break;
case V_606 :
if ( V_586 -> V_595 == V_596 ) {
V_47 = 0 ;
break;
}
if ( V_258 && F_39 ( V_2 ) &&
V_586 -> V_139 & V_597 &&
( V_586 -> V_107 == V_55 ||
V_586 -> V_107 == V_97 ||
V_586 -> V_107 == V_98 ) ) {
V_261 = F_62 ( V_258 ) ;
V_588 = F_252 (
V_261 -> V_588 [ V_589 ] ,
F_253 ( & V_2 -> V_33 ) ) ;
F_202 ( V_261 -> V_588 [ V_589 ] , NULL ) ;
if ( V_588 )
F_254 ( V_588 , V_607 ) ;
}
F_165 ( V_2 , L_45 ) ;
V_47 = F_255 ( V_2 , V_288 , V_258 , V_586 ) ;
break;
default:
V_47 = - V_321 ;
}
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_256 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_585 * V_608 ,
struct V_257 * V_258 ,
T_1 V_609 , V_132 * V_610 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_608 -> V_595 == V_596 )
return;
F_257 ( V_2 , V_288 , V_608 , V_258 , V_609 , V_610 ) ;
}
static bool F_258 ( struct V_611 * V_612 ,
struct V_469 * V_470 , void * V_275 )
{
struct V_1 * V_2 =
F_259 ( V_612 , struct V_1 , V_612 ) ;
struct V_613 * V_32 ;
int V_614 = F_260 ( V_470 ) ;
struct V_615 * V_616 = V_275 ;
if ( F_8 ( V_470 -> V_274 . V_365 != V_617 ) )
return true ;
if ( F_15 ( V_614 != sizeof( * V_32 ) ) ) {
F_113 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_470 -> V_275 ;
F_261 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_618 ) ;
V_616 -> V_619 = F_43 ( V_32 -> V_618 ) ;
F_261 ( V_2 , L_48 ,
V_616 -> V_619 ) ;
F_4 ( & V_2 -> V_326 ) ;
F_262 ( & V_616 -> V_620 , & V_2 -> V_621 ) ;
F_5 ( & V_2 -> V_326 ) ;
return true ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_622 * V_566 ,
struct V_287 * V_288 ,
int V_577 )
{
int V_623 , V_624 = V_625 ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
struct V_615 * V_616 = & V_323 -> V_626 ;
static const V_132 V_627 [] = { V_617 } ;
struct V_628 V_629 ;
T_1 V_630 = V_288 -> V_401 . V_631 *
V_288 -> V_401 . V_479 ;
T_1 V_632 , V_633 ;
struct V_634 V_635 = {
. V_292 = F_130 ( V_636 ) ,
. V_637 =
F_130 ( F_264 ( V_638 , 0 ) ) ,
. V_639 = F_130 ( V_2 -> V_640 . V_264 ) ,
. V_641 . V_567 = ( V_566 -> V_567 == V_174 ) ?
V_642 : V_643 ,
. V_641 . V_566 = V_566 -> V_644 ,
. V_641 . V_645 = V_646 ,
. V_647 = F_130 ( F_265 ( V_2 -> V_7 , V_624 ) ) ,
} ;
V_633 = V_648 ;
V_632 = F_266 ( V_577 ) ;
if ( V_288 -> V_401 . V_402 ) {
V_633 = F_267 ( T_1 , V_630 * 3 , V_649 ) ;
if ( V_630 <= V_632 ) {
V_632 = V_630 - V_650 ;
if ( V_632 <= V_651 )
V_632 = V_630 -
V_652 ;
}
}
V_635 . V_577 = F_130 ( V_632 ) ;
V_635 . V_653 = F_130 ( V_633 ) ;
F_261 ( V_2 ,
L_49 ,
V_566 -> V_644 , V_632 , V_577 , V_633 ,
V_630 ) ;
memcpy ( V_635 . V_654 , V_288 -> V_156 , V_159 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_326 ) ;
if ( F_8 ( V_616 -> V_20 == V_617 ) ) {
F_5 ( & V_2 -> V_326 ) ;
return - V_17 ;
}
V_616 -> V_288 = V_288 ;
V_616 -> V_577 = V_577 ;
V_616 -> V_20 = V_617 ;
F_5 ( & V_2 -> V_326 ) ;
F_268 ( & V_2 -> V_612 , & V_629 ,
V_627 ,
F_42 ( V_627 ) ,
F_258 , V_616 ) ;
V_623 = F_132 ( V_2 , V_617 , 0 , sizeof( V_635 ) ,
& V_635 ) ;
if ( V_623 ) {
F_113 ( V_2 , L_50 , V_623 ) ;
F_269 ( & V_2 -> V_612 , & V_629 ) ;
goto V_655;
}
V_623 = F_270 ( & V_2 -> V_612 , & V_629 , 1 ) ;
F_15 ( V_623 ) ;
if ( V_623 ) {
V_655:
F_4 ( & V_2 -> V_326 ) ;
F_96 ( V_2 , V_616 ) ;
F_5 ( & V_2 -> V_326 ) ;
}
return V_623 ;
}
static int F_271 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_622 * V_566 ,
int V_577 ,
enum V_656 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
struct V_657 V_658 ;
struct V_362 * V_328 ;
int V_47 , V_9 ;
F_165 ( V_2 , L_51 , V_566 -> V_644 ,
V_577 , type ) ;
F_120 ( & V_2 -> V_354 ) ;
F_87 ( & V_2 -> V_33 ) ;
switch ( V_288 -> type ) {
case V_113 :
if ( F_48 ( & V_2 -> V_105 -> V_170 ,
V_659 ) ) {
V_47 = F_263 ( V_2 , V_566 ,
V_288 , V_577 ) ;
goto V_379;
}
F_113 ( V_2 , L_52 ) ;
V_47 = - V_321 ;
goto V_379;
case V_137 :
break;
default:
F_113 ( V_2 , L_53 , V_288 -> type ) ;
V_47 = - V_321 ;
goto V_379;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_328 = & V_2 -> V_18 [ V_9 ] ;
if ( V_328 -> V_21 == 0 || V_323 -> V_328 == V_328 )
continue;
if ( V_328 -> V_21 && V_566 == V_328 -> V_566 ) {
V_47 = F_143 ( V_2 , V_288 ) ;
if ( F_272 ( V_47 , L_54 ) )
goto V_379;
F_144 ( V_2 , V_323 -> V_328 ) ;
V_323 -> V_328 = V_328 ;
V_47 = F_141 ( V_2 , V_288 ) ;
if ( F_272 ( V_47 , L_55 ) )
goto V_379;
F_140 ( V_2 , V_323 -> V_328 ) ;
goto V_660;
}
}
if ( V_566 == V_323 -> V_328 -> V_566 )
goto V_660;
F_273 ( & V_658 , V_566 , V_661 ) ;
if ( V_323 -> V_328 -> V_21 == 1 ) {
V_47 = F_274 ( V_2 , V_323 -> V_328 ,
& V_658 , 1 , 1 ) ;
if ( V_47 )
goto V_379;
} else {
V_328 = F_128 ( V_2 ) ;
if ( ! V_328 ) {
V_47 = - V_387 ;
goto V_379;
}
V_47 = F_274 ( V_2 , V_328 , & V_658 ,
1 , 1 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_56 ) ;
goto V_379;
}
V_47 = F_143 ( V_2 , V_288 ) ;
if ( F_272 ( V_47 , L_54 ) )
goto V_379;
F_144 ( V_2 , V_323 -> V_328 ) ;
V_323 -> V_328 = V_328 ;
V_47 = F_141 ( V_2 , V_288 ) ;
if ( F_272 ( V_47 , L_55 ) )
goto V_379;
F_140 ( V_2 , V_323 -> V_328 ) ;
}
V_660:
V_47 = F_275 ( V_2 , V_288 , V_577 , type ) ;
V_379:
F_93 ( & V_2 -> V_33 ) ;
F_165 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_276 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_165 ( V_2 , L_58 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_277 ( V_2 ) ;
F_93 ( & V_2 -> V_33 ) ;
F_165 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_278 ( struct V_1 * V_2 ,
struct V_662 * V_663 )
{
V_132 * V_664 = ( V_132 * ) V_663 -> V_665 ;
struct V_362 * V_328 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_165 ( V_2 , L_59 ) ;
V_328 = F_128 ( V_2 ) ;
if ( ! V_328 ) {
V_47 = - V_387 ;
goto V_34;
}
V_47 = F_274 ( V_2 , V_328 , & V_663 -> V_666 ,
V_663 -> V_667 ,
V_663 -> V_668 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_60 ) ;
goto V_34;
}
F_140 ( V_2 , V_328 ) ;
* V_664 = V_328 -> V_20 ;
V_34:
return V_47 ;
}
static int F_279 ( struct V_29 * V_30 ,
struct V_662 * V_663 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_278 ( V_2 , V_663 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_280 ( struct V_1 * V_2 ,
struct V_662 * V_663 )
{
V_132 * V_664 = ( V_132 * ) V_663 -> V_665 ;
struct V_362 * V_328 = & V_2 -> V_18 [ * V_664 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_144 ( V_2 , V_328 ) ;
}
static void F_281 ( struct V_29 * V_30 ,
struct V_662 * V_663 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_280 ( V_2 , V_663 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static void F_282 ( struct V_29 * V_30 ,
struct V_662 * V_663 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_132 * V_664 = ( V_132 * ) V_663 -> V_665 ;
struct V_362 * V_328 = & V_2 -> V_18 [ * V_664 ] ;
if ( F_117 ( ( V_328 -> V_21 > 1 ) &&
( V_27 & ~ ( V_669 |
V_670 |
V_671 |
V_672 ) ) ,
L_61 ,
V_328 -> V_21 , V_27 ) )
return;
F_87 ( & V_2 -> V_33 ) ;
F_190 ( V_2 ) ;
F_274 ( V_2 , V_328 , & V_663 -> V_666 ,
V_663 -> V_667 ,
V_663 -> V_668 ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int F_283 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
struct V_662 * V_663 ,
bool V_673 )
{
V_132 * V_664 = ( V_132 * ) V_663 -> V_665 ;
struct V_362 * V_328 = & V_2 -> V_18 [ * V_664 ] ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_323 -> V_328 = V_328 ;
switch ( V_288 -> type ) {
case V_135 :
if ( V_673 ) {
V_323 -> V_500 = true ;
break;
}
case V_138 :
V_47 = 0 ;
goto V_34;
case V_113 :
break;
case V_516 :
V_323 -> V_335 = true ;
break;
default:
V_47 = - V_321 ;
goto V_34;
}
V_47 = F_141 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_34;
F_138 ( V_2 ) ;
if ( V_288 -> type == V_516 ) {
V_323 -> V_674 = true ;
V_47 = F_112 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_675;
V_47 = F_284 ( V_2 , V_288 ) ;
if ( V_47 )
goto V_675;
}
if ( V_288 -> type == V_135 ) {
F_112 ( V_2 , false , NULL ) ;
F_168 ( V_2 , V_288 , false , NULL ) ;
}
if ( V_673 && V_288 -> type == V_113 ) {
T_1 V_577 = 2 * V_288 -> V_401 . V_479 ;
V_47 = F_12 ( V_2 , V_676 ) ;
if ( V_47 )
goto V_675;
F_185 ( V_2 , V_288 , V_577 , V_577 ,
V_288 -> V_401 . V_479 / 2 ,
true ) ;
F_7 ( V_2 , V_676 ) ;
F_112 ( V_2 , false , NULL ) ;
}
goto V_34;
V_675:
F_143 ( V_2 , V_288 ) ;
F_138 ( V_2 ) ;
V_34:
if ( V_47 )
V_323 -> V_328 = NULL ;
return V_47 ;
}
static int F_285 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_662 * V_663 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_47 = F_283 ( V_2 , V_288 , V_663 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_286 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
struct V_662 * V_663 ,
bool V_673 )
{
struct V_130 * V_323 = F_95 ( V_288 ) ;
struct V_287 * V_677 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_192 ( V_2 , V_323 , & V_323 -> V_327 ) ;
switch ( V_288 -> type ) {
case V_138 :
goto V_34;
case V_516 :
V_323 -> V_674 = false ;
V_323 -> V_335 = false ;
F_287 ( V_2 , V_288 ) ;
break;
case V_135 :
if ( ! V_673 || ! V_323 -> V_500 )
goto V_34;
V_323 -> V_504 = false ;
F_288 ( V_2 , V_323 , true ) ;
F_223 ( V_2 -> V_505 , V_288 ) ;
V_323 -> V_500 = false ;
break;
case V_113 :
if ( ! V_673 )
break;
V_677 = V_288 ;
F_168 ( V_2 , V_288 , true , NULL ) ;
break;
default:
break;
}
F_112 ( V_2 , false , V_677 ) ;
F_143 ( V_2 , V_288 ) ;
V_34:
V_323 -> V_328 = NULL ;
F_138 ( V_2 ) ;
}
static void F_289 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_662 * V_663 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_87 ( & V_2 -> V_33 ) ;
F_286 ( V_2 , V_288 , V_663 , false ) ;
F_93 ( & V_2 -> V_33 ) ;
}
static int
F_290 ( struct V_1 * V_2 ,
struct V_678 * V_679 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_286 ( V_2 , V_679 [ 0 ] . V_288 , V_679 [ 0 ] . V_680 , true ) ;
F_280 ( V_2 , V_679 [ 0 ] . V_680 ) ;
V_47 = F_278 ( V_2 , V_679 [ 0 ] . V_681 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_62 ) ;
goto V_682;
}
V_47 = F_283 ( V_2 , V_679 [ 0 ] . V_288 , V_679 [ 0 ] . V_681 ,
true ) ;
if ( V_47 ) {
F_113 ( V_2 ,
L_63 ) ;
goto V_499;
}
if ( F_198 ( V_2 ) > 1 )
F_114 ( V_2 ) ;
goto V_34;
V_499:
F_280 ( V_2 , V_679 [ 0 ] . V_681 ) ;
V_682:
if ( F_278 ( V_2 , V_679 [ 0 ] . V_680 ) ) {
F_113 ( V_2 , L_64 ) ;
goto V_683;
}
if ( F_283 ( V_2 , V_679 [ 0 ] . V_288 , V_679 [ 0 ] . V_680 ,
true ) ) {
F_113 ( V_2 , L_65 ) ;
goto V_683;
}
goto V_34;
V_683:
F_291 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_292 ( struct V_1 * V_2 ,
struct V_678 * V_679 )
{
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
F_286 ( V_2 , V_679 [ 0 ] . V_288 , V_679 [ 0 ] . V_680 , true ) ;
V_47 = F_283 ( V_2 , V_679 [ 0 ] . V_288 , V_679 [ 0 ] . V_681 ,
true ) ;
if ( V_47 ) {
F_113 ( V_2 ,
L_63 ) ;
goto V_682;
}
goto V_34;
V_682:
if ( F_283 ( V_2 , V_679 [ 0 ] . V_288 , V_679 [ 0 ] . V_680 ,
true ) ) {
F_113 ( V_2 , L_65 ) ;
goto V_683;
}
goto V_34;
V_683:
F_291 ( V_2 , false ) ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_293 ( struct V_29 * V_30 ,
struct V_678 * V_679 ,
int V_684 ,
enum V_685 V_686 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_684 > 1 )
return - V_591 ;
switch ( V_686 ) {
case V_687 :
V_47 = F_290 ( V_2 , V_679 ) ;
break;
case V_688 :
V_47 = F_292 ( V_2 , V_679 ) ;
break;
default:
V_47 = - V_591 ;
break;
}
return V_47 ;
}
static int F_294 ( struct V_29 * V_30 ,
struct V_257 * V_258 ,
bool V_689 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_128 * V_539 = F_62 ( V_258 ) ;
if ( ! V_539 || ! V_539 -> V_288 ) {
F_113 ( V_2 , L_66 ) ;
return - V_321 ;
}
return F_196 ( V_2 , V_539 -> V_288 ) ;
}
static int F_295 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
void * V_275 , int V_224 )
{
struct V_690 * V_691 [ V_692 + 1 ] ;
int V_693 ;
T_1 V_394 ;
V_693 = F_296 ( V_691 , V_692 , V_275 , V_224 , V_694 ) ;
if ( V_693 )
return V_693 ;
if ( ! V_691 [ V_695 ] )
return - V_321 ;
switch ( F_297 ( V_691 [ V_695 ] ) ) {
case V_696 :
if ( ! V_288 || V_288 -> type != V_135 || ! V_288 -> V_383 ||
! V_288 -> V_401 . V_697 ||
! V_691 [ V_698 ] )
return - V_321 ;
V_394 = F_297 ( V_691 [ V_698 ] ) ;
if ( V_394 >= V_288 -> V_401 . V_479 )
return - V_321 ;
V_2 -> V_394 = V_394 ;
V_2 -> V_393 = V_288 ;
return F_112 ( V_2 , false , NULL ) ;
case V_699 :
if ( ! V_288 || V_288 -> type != V_113 ||
! V_288 -> V_401 . V_402 || ! V_288 -> V_401 . V_631 ||
! V_691 [ V_700 ] )
return - V_321 ;
if ( F_297 ( V_691 [ V_700 ] ) )
return F_193 ( V_2 , V_288 , 0 ) ;
return F_139 ( V_2 , V_288 , 0 ) ;
}
return - V_591 ;
}
static int F_298 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
void * V_275 , int V_224 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_693 ;
F_87 ( & V_2 -> V_33 ) ;
V_693 = F_295 ( V_2 , V_288 , V_275 , V_224 ) ;
F_93 ( & V_2 -> V_33 ) ;
return V_693 ;
}
static void F_299 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_701 * V_702 )
{
F_165 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_300 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_701 * V_702 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_287 * V_503 ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
T_1 V_647 ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
V_323 -> V_703 = false ;
F_165 ( V_2 , L_68 ,
V_702 -> V_658 . V_704 ) ;
F_301 ( V_2 , V_288 , V_705 ) ;
switch ( V_288 -> type ) {
case V_135 :
V_503 =
F_252 ( V_2 -> V_503 ,
F_253 ( & V_2 -> V_33 ) ) ;
if ( F_117 ( V_503 && V_503 -> V_706 ,
L_69 ) ) {
V_47 = - V_561 ;
goto V_379;
}
if ( F_252 ( V_2 -> V_505 ,
F_253 ( & V_2 -> V_33 ) ) ) {
V_47 = - V_561 ;
goto V_379;
}
F_223 ( V_2 -> V_503 , V_288 ) ;
if ( F_117 ( V_323 -> V_504 ,
L_70 ) ) {
V_47 = - V_561 ;
goto V_379;
}
V_323 -> V_707 = V_702 -> V_658 . V_708 -> V_709 ;
break;
case V_113 :
if ( V_323 -> V_474 )
F_183 ( V_288 ,
V_475 ,
0 , 0 ) ;
V_647 = V_702 -> V_710 +
( ( V_288 -> V_401 . V_479 * ( V_702 -> V_404 - 1 ) -
V_711 ) * 1024 ) ;
if ( V_702 -> V_712 )
F_302 ( V_2 , V_288 ) ;
F_303 ( V_2 , V_288 , V_288 -> V_401 . V_479 ,
V_647 ) ;
if ( V_323 -> V_329 . V_495 ) {
V_47 = F_139 ( V_2 , V_288 , 0 ) ;
if ( V_47 )
goto V_379;
}
break;
default:
break;
}
V_323 -> V_335 = true ;
V_47 = F_304 ( V_2 ) ;
if ( V_47 )
goto V_379;
F_114 ( V_2 ) ;
V_379:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_305 ( struct V_29 * V_30 ,
struct V_287 * V_288 )
{
struct V_130 * V_323 = F_95 ( V_288 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_323 -> V_703 ) {
V_323 -> V_703 = false ;
V_47 = - V_17 ;
goto V_379;
}
if ( V_288 -> type == V_113 ) {
struct V_128 * V_261 ;
V_261 = F_306 ( V_2 ,
V_323 -> V_325 ) ;
if ( F_8 ( ! V_261 ) ) {
V_47 = - V_17 ;
goto V_379;
}
F_307 ( V_2 , V_261 , false ) ;
F_168 ( V_2 , V_288 , false , NULL ) ;
V_47 = F_193 ( V_2 , V_288 , 0 ) ;
if ( V_47 )
goto V_379;
F_308 ( V_2 , V_288 ) ;
}
V_323 -> V_335 = false ;
V_47 = F_304 ( V_2 ) ;
V_379:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_309 ( struct V_29 * V_30 ,
struct V_287 * V_288 , T_1 V_78 , bool V_276 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 ;
struct V_128 * V_261 ;
struct V_257 * V_258 ;
int V_9 ;
T_1 V_713 = 0 ;
if ( ! V_288 || V_288 -> type != V_113 )
return;
if ( F_40 ( V_2 ) )
F_120 ( & V_2 -> V_358 ) ;
F_87 ( & V_2 -> V_33 ) ;
V_323 = F_95 ( V_288 ) ;
for ( V_9 = 0 ; V_9 < V_265 ; V_9 ++ ) {
V_258 = F_252 ( V_2 -> V_540 [ V_9 ] ,
F_253 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_258 ) )
continue;
V_261 = F_62 ( V_258 ) ;
if ( V_261 -> V_288 != V_288 )
continue;
F_8 ( V_9 != V_323 -> V_325 && ! V_258 -> V_559 ) ;
V_713 |= V_261 -> V_714 ;
}
if ( V_276 ) {
if ( F_149 ( V_2 , V_713 , 0 ) )
F_113 ( V_2 , L_71 ) ;
F_93 ( & V_2 -> V_33 ) ;
} else {
F_93 ( & V_2 -> V_33 ) ;
F_150 ( V_2 -> V_7 , V_713 ) ;
}
}
static int F_310 ( struct V_29 * V_30 , int V_715 ,
struct V_716 * V_717 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_717 , 0 , sizeof( * V_717 ) ) ;
if ( V_715 != 0 )
return - V_49 ;
if ( ! F_48 ( & V_2 -> V_105 -> V_170 ,
V_718 ) )
return - V_49 ;
F_87 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_719 ) {
V_47 = F_184 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_717 -> V_720 = V_721 |
V_722 |
V_723 |
V_724 ;
V_717 -> time = V_2 -> V_353 . V_725 +
V_2 -> V_726 . V_725 ;
F_311 ( V_717 -> time , V_727 ) ;
V_717 -> V_728 = V_2 -> V_353 . V_729 +
V_2 -> V_726 . V_729 ;
F_311 ( V_717 -> V_728 , V_727 ) ;
V_717 -> V_730 = V_2 -> V_353 . V_731 +
V_2 -> V_726 . V_731 ;
F_311 ( V_717 -> V_730 , V_727 ) ;
V_717 -> V_732 = V_2 -> V_353 . V_733 +
V_2 -> V_726 . V_733 ;
F_311 ( V_717 -> V_732 , V_727 ) ;
V_47 = 0 ;
V_34:
F_93 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_312 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
struct V_257 * V_258 ,
struct V_734 * V_735 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_130 * V_323 = F_95 ( V_288 ) ;
struct V_128 * V_261 = F_62 ( V_258 ) ;
if ( V_261 -> V_736 ) {
V_735 -> V_737 = V_261 -> V_736 ;
V_735 -> V_720 |= F_44 ( V_738 ) ;
}
if ( ! F_48 ( & V_2 -> V_105 -> V_170 ,
V_718 ) )
return;
if ( ! ( V_288 -> V_384 & V_385 ) )
return;
if ( ! V_288 -> V_401 . V_402 )
return;
F_87 ( & V_2 -> V_33 ) ;
if ( V_323 -> V_325 != V_261 -> V_264 )
goto V_739;
if ( F_184 ( V_2 , false ) )
goto V_739;
V_735 -> V_740 = V_323 -> V_376 . V_378 +
V_323 -> V_376 . V_377 ;
V_735 -> V_720 |= F_44 ( V_741 ) ;
if ( V_323 -> V_376 . V_742 ) {
V_735 -> V_743 = V_323 -> V_376 . V_742 ;
V_735 -> V_720 |= F_44 ( V_744 ) ;
}
V_739:
F_93 ( & V_2 -> V_33 ) ;
}
static void F_313 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
const struct V_745 * V_746 )
{
#define F_314 ( T_5 , T_6 , T_7 , T_8 , T_9 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_293 * V_294 ;
struct V_747 * V_748 ;
if ( ! F_81 ( V_2 -> V_105 , V_749 ) )
return;
V_294 = F_82 ( V_2 -> V_105 , V_749 ) ;
V_748 = ( void * ) V_294 -> V_275 ;
if ( ! F_83 ( V_2 , V_288 , V_294 ) )
return;
if ( V_746 -> V_750 . V_751 . V_275 == V_752 ) {
if ( V_746 -> V_750 . V_751 . V_15 == V_753 )
F_314 ( V_2 , V_294 , V_754 ,
V_748 -> V_755 ,
L_72 ,
V_746 -> V_750 . V_751 . V_526 ) ;
else if ( V_746 -> V_750 . V_751 . V_15 == V_756 )
F_314 ( V_2 , V_294 , V_754 ,
V_748 -> V_757 ,
L_73 ) ;
} else if ( V_746 -> V_750 . V_751 . V_275 == V_758 ) {
if ( V_746 -> V_750 . V_751 . V_15 == V_753 )
F_314 ( V_2 , V_294 , V_754 ,
V_748 -> V_759 ,
L_74 ,
V_746 -> V_750 . V_751 . V_526 ) ;
else if ( V_746 -> V_750 . V_751 . V_15 == V_756 )
F_314 ( V_2 , V_294 , V_754 ,
V_748 -> V_760 ,
L_75 ) ;
} else if ( V_746 -> V_750 . V_751 . V_275 == V_761 ) {
F_314 ( V_2 , V_294 , V_754 ,
V_748 -> V_762 ,
L_76 , V_746 -> V_750 . V_751 . V_526 ) ;
} else if ( V_746 -> V_750 . V_751 . V_275 == V_763 ) {
F_314 ( V_2 , V_294 , V_754 ,
V_748 -> V_764 ,
L_77 , V_746 -> V_750 . V_751 . V_526 ) ;
}
#undef F_314
}
static void F_315 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
const struct V_745 * V_746 )
{
struct V_293 * V_294 ;
struct V_295 * V_296 ;
if ( ! F_81 ( V_2 -> V_105 , V_297 ) )
return;
V_294 = F_82 ( V_2 -> V_105 , V_297 ) ;
V_296 = ( void * ) V_294 -> V_275 ;
if ( ! F_83 ( V_2 , V_288 , V_294 ) )
return;
if ( ! ( F_316 ( V_296 -> V_765 ) & F_44 ( V_746 -> V_750 . V_766 . V_289 ) ) )
return;
F_228 ( V_2 , V_294 ,
L_78 ,
V_746 -> V_750 . V_766 . V_258 -> V_156 , V_746 -> V_750 . V_766 . V_289 ,
V_746 -> V_750 . V_766 . V_302 ) ;
}
static void
F_317 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
const struct V_745 * V_746 )
{
struct V_293 * V_294 ;
struct V_295 * V_296 ;
if ( ! F_81 ( V_2 -> V_105 , V_297 ) )
return;
V_294 = F_82 ( V_2 -> V_105 , V_297 ) ;
V_296 = ( void * ) V_294 -> V_275 ;
if ( ! F_83 ( V_2 , V_288 , V_294 ) )
return;
if ( ! ( F_316 ( V_296 -> V_767 ) & F_44 ( V_746 -> V_750 . V_766 . V_289 ) ) )
return;
F_228 ( V_2 , V_294 ,
L_79 ,
V_746 -> V_750 . V_766 . V_258 -> V_156 , V_746 -> V_750 . V_766 . V_289 ) ;
}
static void F_318 ( struct V_29 * V_30 ,
struct V_287 * V_288 ,
const struct V_745 * V_746 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_746 -> type ) {
case V_768 :
F_313 ( V_2 , V_288 , V_746 ) ;
break;
case V_769 :
F_315 ( V_2 , V_288 , V_746 ) ;
break;
case V_770 :
F_317 ( V_2 , V_288 , V_746 ) ;
break;
default:
break;
}
}
void F_319 ( struct V_1 * V_2 ,
struct V_771 * V_466 ,
T_1 V_772 )
{
T_1 V_773 = F_44 ( V_2 -> V_7 -> V_72 ) - 1 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! F_39 ( V_2 ) )
return;
V_466 -> V_774 = V_2 -> V_775 ;
if ( V_466 -> V_776 )
F_320 ( & V_2 -> V_777 ,
V_2 -> V_7 -> V_72 ) ;
V_47 = F_321 ( V_2 , V_773 , ( T_2 * ) V_466 , V_772 ) ;
if ( V_47 ) {
F_113 ( V_2 , L_80 , V_47 ) ;
goto V_34;
}
if ( V_466 -> V_776 )
V_47 = F_13 ( V_2 -> V_778 ,
F_216 ( & V_2 -> V_777 ) == 0 ,
V_16 ) ;
F_15 ( ! V_47 ) ;
V_34:
F_320 ( & V_2 -> V_777 , 0 ) ;
V_2 -> V_775 ++ ;
}
static void F_322 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_771 V_275 = {
. type = V_779 ,
. V_776 = 1 ,
} ;
F_87 ( & V_2 -> V_33 ) ;
F_319 ( V_2 , & V_275 , sizeof( V_275 ) ) ;
F_93 ( & V_2 -> V_33 ) ;
}
