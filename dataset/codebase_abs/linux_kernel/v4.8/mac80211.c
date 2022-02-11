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
F_41 ( F_42 ( V_2 -> V_94 ) < F_42 ( V_51 ) + 4 ) ;
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
if ( V_2 -> V_99 -> V_100 . V_101 & V_102 &&
! V_103 . V_104 ) {
F_38 ( V_30 , V_105 ) ;
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] =
V_106 ;
V_30 -> V_23 -> V_95 ++ ;
}
if ( V_2 -> V_99 -> V_107 [ 0 ] . V_108 ) {
const struct V_109 * V_110 = & V_2 -> V_99 -> V_107 [ 0 ] ;
struct V_111 * V_107 = & V_2 -> V_107 [ 0 ] ;
V_2 -> V_30 -> V_112 = 1 ;
V_107 -> V_108 = F_43 ( V_110 -> V_108 ) ;
V_107 -> V_113 = F_44 ( V_114 ) ;
V_107 -> V_115 = V_110 -> V_115 ;
V_107 -> V_116 = V_110 -> V_116 ;
V_107 -> V_117 = V_110 -> V_117 ;
V_107 -> V_118 = V_110 -> V_118 ;
V_107 -> V_119 = V_110 -> V_119 ;
V_107 -> V_120 = V_110 -> V_120 ;
V_107 -> V_121 = V_110 -> V_121 ;
V_2 -> V_30 -> V_122 = V_2 -> V_107 ;
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] = V_107 -> V_108 ;
V_30 -> V_23 -> V_95 ++ ;
}
F_38 ( V_30 , V_123 ) ;
V_30 -> V_23 -> V_124 |=
V_125 |
V_126 |
V_127 ;
V_30 -> V_128 = sizeof( struct V_129 ) ;
V_30 -> V_130 = sizeof( struct V_131 ) ;
V_30 -> V_132 = sizeof( V_133 ) ;
V_30 -> V_23 -> V_134 = F_44 ( V_114 ) |
F_44 ( V_135 ) |
F_44 ( V_136 ) |
F_44 ( V_137 ) |
F_44 ( V_138 ) |
F_44 ( V_139 ) ;
V_30 -> V_23 -> V_101 |= V_140 ;
V_30 -> V_23 -> V_141 |= V_142 ;
if ( F_30 ( V_2 ) )
V_30 -> V_23 -> V_141 |= V_143 ;
else
V_30 -> V_23 -> V_141 |= V_144 |
V_145 ;
if ( V_2 -> V_99 -> V_100 . V_101 & V_146 )
V_30 -> V_23 -> V_101 |= V_147 ;
V_30 -> V_23 -> V_101 |= V_148 ;
V_30 -> V_23 -> V_149 = V_150 ;
V_30 -> V_23 -> V_151 =
F_42 ( V_150 ) ;
V_30 -> V_23 -> V_152 = 10000 ;
V_30 -> V_153 = V_154 ;
V_30 -> V_23 -> V_155 = 3 * 5 ;
memcpy ( V_2 -> V_156 [ 0 ] . V_157 , V_2 -> V_158 -> V_159 , V_160 ) ;
V_30 -> V_23 -> V_156 = V_2 -> V_156 ;
V_30 -> V_23 -> V_161 = 1 ;
V_50 = ( V_2 -> V_158 -> V_162 > 1 ) ?
F_45 ( V_163 , V_2 -> V_158 -> V_162 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_50 ; V_9 ++ ) {
memcpy ( V_2 -> V_156 [ V_9 ] . V_157 , V_2 -> V_156 [ V_9 - 1 ] . V_157 ,
V_160 ) ;
V_2 -> V_156 [ V_9 ] . V_157 [ 5 ] ++ ;
V_30 -> V_23 -> V_161 ++ ;
}
F_16 ( V_2 ) ;
V_30 -> V_23 -> V_164 = F_46 ( V_2 ) ;
V_30 -> V_23 -> V_165 = V_166 ;
F_41 ( V_167 & V_168 ) ;
F_41 ( V_169 > F_47 ( V_168 ) ||
V_170 > F_47 ( V_168 ) ) ;
if ( F_48 ( & V_2 -> V_99 -> V_100 , V_171 ) )
V_2 -> V_172 = V_169 ;
else
V_2 -> V_172 = V_170 ;
if ( V_2 -> V_158 -> V_173 [ V_174 ] . V_38 )
V_30 -> V_23 -> V_173 [ V_174 ] =
& V_2 -> V_158 -> V_173 [ V_174 ] ;
if ( V_2 -> V_158 -> V_173 [ V_175 ] . V_38 ) {
V_30 -> V_23 -> V_173 [ V_175 ] =
& V_2 -> V_158 -> V_173 [ V_175 ] ;
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_176 ) &&
F_49 ( & V_2 -> V_99 -> V_100 ,
V_177 ) )
V_30 -> V_23 -> V_173 [ V_175 ] -> V_178 . V_179 |=
V_180 ;
}
V_30 -> V_23 -> V_181 = V_2 -> V_7 -> V_182 ;
if ( V_183 . V_184 != V_185 )
V_30 -> V_23 -> V_101 |= V_186 ;
else
V_30 -> V_23 -> V_101 &= ~ V_186 ;
V_30 -> V_23 -> V_101 |= V_187 ;
V_30 -> V_23 -> V_188 = V_166 ;
V_30 -> V_23 -> V_189 = V_190 ;
V_30 -> V_23 -> V_191 =
V_192 - 24 - 2 ;
V_30 -> V_23 -> V_193 = V_194 ;
V_30 -> V_23 -> V_195 = V_196 ;
V_30 -> V_23 -> V_197 = 254 ;
V_30 -> V_23 -> V_124 |= V_198 |
V_199 |
V_200 |
V_201 |
V_202 |
V_203 |
V_204 ;
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_205 ) )
V_30 -> V_23 -> V_124 |= V_206 ;
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_207 ) )
V_30 -> V_23 -> V_124 |= V_208 ;
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_209 ) )
V_30 -> V_23 -> V_124 |=
V_210 ;
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_211 ) )
V_30 -> V_23 -> V_124 |= V_212 ;
V_2 -> V_213 = V_214 ;
#ifdef F_50
if ( F_2 ( V_2 ) &&
F_51 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_215 . V_101 = V_216 ;
V_30 -> V_23 -> V_215 = & V_2 -> V_215 ;
}
if ( V_2 -> V_99 -> V_217 [ V_218 ] . V_219 [ 0 ] . V_220 &&
V_2 -> V_7 -> V_221 -> V_222 &&
V_2 -> V_7 -> V_221 -> V_223 &&
F_51 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_215 . V_101 |= V_224 |
V_225 |
V_226 |
V_227 |
V_228 ;
if ( ! V_103 . V_104 )
V_2 -> V_215 . V_101 |= V_229 |
V_230 |
V_231 ;
V_2 -> V_215 . V_232 = V_233 ;
V_2 -> V_215 . V_234 = V_235 ;
V_2 -> V_215 . V_236 = V_237 ;
V_2 -> V_215 . V_238 = V_190 ;
V_2 -> V_215 . V_239 = & V_240 ;
V_30 -> V_23 -> V_215 = & V_2 -> V_215 ;
}
#endif
#ifdef F_52
V_2 -> V_241 = V_242 ;
#endif
V_47 = F_53 ( V_2 ) ;
if ( V_47 )
return V_47 ;
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_243 ) ) {
F_54 ( V_2 , L_10 ) ;
V_30 -> V_23 -> V_101 |= V_244 ;
F_38 ( V_30 , V_245 ) ;
}
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_246 ) ) {
F_54 ( V_2 , L_11 ) ;
V_30 -> V_23 -> V_124 |= V_247 ;
}
V_30 -> V_75 |= V_2 -> V_37 -> V_124 ;
if ( ! F_55 ( V_2 ) ) {
V_30 -> V_75 &= ~ ( V_248 |
V_249 ) ;
if ( V_250 )
V_30 -> V_75 |= V_248 ;
}
V_47 = F_56 ( V_2 -> V_30 ) ;
if ( V_47 )
F_57 ( V_2 ) ;
return V_47 ;
}
static bool F_58 ( struct V_1 * V_2 ,
struct V_251 * V_252 ,
struct V_253 * V_254 )
{
struct V_129 * V_255 ;
bool V_256 = false ;
if ( F_59 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_60 ( & V_2 -> V_257 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_34;
V_255 = F_61 ( V_252 ) ;
if ( V_255 -> V_258 == V_259 ||
V_255 -> V_258 != V_2 -> V_260 )
goto V_34;
F_62 ( & V_2 -> V_261 , V_254 ) ;
F_63 ( V_2 -> V_30 ) ;
F_1 ( V_2 , V_262 ) ;
F_7 ( V_2 , V_262 ) ;
V_256 = true ;
V_34:
F_64 ( & V_2 -> V_257 ) ;
return V_256 ;
}
static void F_65 ( struct V_29 * V_30 ,
struct V_263 * V_264 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_251 * V_252 = V_264 -> V_252 ;
struct V_265 * V_266 = F_66 ( V_254 ) ;
struct V_267 * V_268 = ( void * ) V_254 -> V_269 ;
if ( F_67 ( V_2 ) ) {
F_68 ( V_2 , L_12 ) ;
goto V_270;
}
if ( F_66 ( V_254 ) -> V_271 == V_82 &&
! F_14 ( V_272 , & V_2 -> V_15 ) &&
! F_14 ( V_273 , & V_2 -> V_15 ) )
goto V_270;
if ( F_69 ( V_266 -> V_101 & V_274 &&
F_70 ( V_268 -> V_275 ) &&
! F_71 ( V_268 -> V_275 ) &&
! F_72 ( V_268 -> V_275 ) &&
! F_73 ( V_268 -> V_275 ) ) )
V_252 = NULL ;
if ( V_252 ) {
if ( F_58 ( V_2 , V_252 , V_254 ) )
return;
if ( F_74 ( V_2 , V_254 , V_252 ) )
goto V_270;
return;
}
if ( F_75 ( V_2 , V_254 ) )
goto V_270;
return;
V_270:
F_76 ( V_30 , V_254 ) ;
}
static inline bool F_77 ( const struct V_276 * V_37 )
{
if ( V_103 . V_277 & V_278 )
return false ;
return true ;
}
static inline bool F_78 ( const struct V_276 * V_37 )
{
if ( V_103 . V_277 & V_279 )
return false ;
if ( V_103 . V_277 & V_280 )
return true ;
return true ;
}
static void
F_79 ( struct V_1 * V_2 , struct V_281 * V_282 ,
struct V_251 * V_252 , V_133 V_283 , V_133 V_284 ,
enum V_285 V_286 )
{
struct V_287 * V_288 ;
struct V_289 * V_290 ;
if ( ! F_80 ( V_2 -> V_99 , V_291 ) )
return;
V_288 = F_81 ( V_2 -> V_99 , V_291 ) ;
V_290 = ( void * ) V_288 -> V_269 ;
if ( ! F_82 ( V_2 , V_282 , V_288 ) )
return;
switch ( V_286 ) {
case V_292 : {
struct V_129 * V_255 = F_61 ( V_252 ) ;
struct V_293 * V_294 = & V_255 -> V_294 [ V_283 ] ;
F_83 ( V_2 , V_288 , V_290 -> V_295 , V_283 ,
L_13 ,
V_252 -> V_157 , V_283 , V_294 -> V_296 ) ;
break;
}
case V_297 :
F_83 ( V_2 , V_288 , V_290 -> V_298 , V_283 ,
L_14 ,
V_252 -> V_157 , V_283 ) ;
break;
case V_299 :
F_83 ( V_2 , V_288 , V_290 -> V_300 , V_283 ,
L_15 ,
V_252 -> V_157 , V_283 , V_284 ) ;
break;
case V_301 :
F_83 ( V_2 , V_288 , V_290 -> V_302 , V_283 ,
L_16 ,
V_252 -> V_157 , V_283 ) ;
break;
default:
break;
}
}
static int F_84 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_303 * V_304 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_305 = false ;
struct V_251 * V_252 = V_304 -> V_252 ;
enum V_285 V_286 = V_304 -> V_286 ;
V_133 V_283 = V_304 -> V_283 ;
V_133 * V_296 = & V_304 -> V_296 ;
T_2 V_306 = V_304 -> V_306 ;
bool V_307 = V_304 -> V_307 ;
V_133 V_308 = V_304 -> V_308 ;
F_85 ( V_2 , L_17 ,
V_252 -> V_157 , V_283 , V_286 ) ;
if ( ! ( V_2 -> V_158 -> V_309 ) )
return - V_310 ;
switch ( V_286 ) {
case V_311 :
case V_297 :
case V_312 :
case V_313 :
case V_292 :
V_47 = F_12 ( V_2 , V_314 ) ;
if ( V_47 )
return V_47 ;
V_305 = true ;
break;
default:
break;
}
F_86 ( & V_2 -> V_33 ) ;
switch ( V_286 ) {
case V_299 :
if ( ! F_77 ( V_2 -> V_37 ) ) {
V_47 = - V_315 ;
break;
}
V_47 = F_87 ( V_2 , V_252 , V_283 , * V_296 , true , V_306 ,
V_308 ) ;
break;
case V_301 :
V_47 = F_87 ( V_2 , V_252 , V_283 , 0 , false , V_306 ,
V_308 ) ;
break;
case V_311 :
if ( ! F_78 ( V_2 -> V_37 ) ) {
V_47 = - V_315 ;
break;
}
V_47 = F_88 ( V_2 , V_282 , V_252 , V_283 , V_296 ) ;
break;
case V_297 :
V_47 = F_89 ( V_2 , V_282 , V_252 , V_283 ) ;
break;
case V_312 :
case V_313 :
V_47 = F_90 ( V_2 , V_282 , V_252 , V_283 ) ;
break;
case V_292 :
V_47 = F_91 ( V_2 , V_282 , V_252 , V_283 ,
V_306 , V_307 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_315 ;
break;
}
if ( ! V_47 ) {
V_133 V_284 = 0 ;
if ( V_286 == V_299 )
V_284 = * V_296 ;
F_79 ( V_2 , V_282 , V_252 , V_283 ,
V_284 , V_286 ) ;
}
F_92 ( & V_2 -> V_33 ) ;
if ( V_305 )
F_7 ( V_2 , V_314 ) ;
return V_47 ;
}
static void F_93 ( void * V_269 , T_2 * V_316 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = V_269 ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
V_317 -> V_318 = false ;
V_317 -> V_319 = V_259 ;
F_4 ( & V_2 -> V_320 ) ;
F_95 ( V_2 , & V_317 -> V_321 ) ;
F_5 ( & V_2 -> V_320 ) ;
V_317 -> V_322 = NULL ;
memset ( & V_317 -> V_323 , 0 , sizeof( V_317 -> V_323 ) ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( ! F_97 ( V_324 , & V_2 -> V_15 ) ) {
V_2 -> V_325 = & V_326 ;
F_98 ( V_2 ) ;
}
F_10 ( V_2 , V_327 ) ;
F_99 ( V_2 ) ;
V_2 -> V_328 = 0 ;
V_2 -> V_329 = false ;
V_2 -> V_330 = false ;
F_100 ( V_2 ) ;
F_101 ( V_2 -> V_30 ) ;
F_102 ( V_2 -> V_30 , 0 , F_93 , V_2 ) ;
V_2 -> V_331 = NULL ;
V_2 -> V_260 = V_259 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_332 , 0 , sizeof( V_2 -> V_332 ) ) ;
memset ( V_2 -> V_333 , 0 , sizeof( V_2 -> V_333 ) ) ;
memset ( V_2 -> V_334 , 0 , sizeof( V_2 -> V_334 ) ) ;
memset ( V_2 -> V_335 , 0 , sizeof( V_2 -> V_335 ) ) ;
memset ( & V_2 -> V_336 , 0 , sizeof( V_2 -> V_336 ) ) ;
memset ( & V_2 -> V_337 , 0 , sizeof( V_2 -> V_337 ) ) ;
F_103 ( V_2 -> V_30 ) ;
F_104 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_338 = 0 ;
V_2 -> V_339 = 0 ;
V_2 -> V_340 = V_341 ;
F_105 ( V_2 ) ;
}
int F_106 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_342 , & V_2 -> V_15 ) ) {
F_96 ( V_2 ) ;
} else {
F_1 ( V_2 , V_327 ) ;
}
V_47 = F_107 ( V_2 ) ;
if ( V_47 && F_14 ( V_342 , & V_2 -> V_15 ) ) {
F_104 ( V_342 , & V_2 -> V_15 ) ;
F_108 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_109 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_342 , & V_2 -> V_15 ) ) {
F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ;
}
F_86 ( & V_2 -> V_33 ) ;
V_47 = F_106 ( V_2 ) ;
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_110 ( struct V_1 * V_2 )
{
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
F_104 ( V_342 , & V_2 -> V_15 ) ;
F_108 ( V_2 , NULL ) ;
V_47 = F_111 ( V_2 , true , NULL ) ;
if ( V_47 )
F_112 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_327 ) ;
F_113 ( V_2 ) ;
F_92 ( & V_2 -> V_33 ) ;
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
enum V_343 V_344 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_344 ) {
case V_345 :
F_110 ( V_2 ) ;
break;
case V_346 :
F_114 ( V_2 ) ;
break;
}
}
void F_118 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_347 , 0 , sizeof( V_2 -> V_347 ) ) ;
F_119 ( & V_2 -> V_348 ) ;
F_99 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
if ( F_97 ( V_342 , & V_2 -> V_15 ) )
F_102 ( V_2 -> V_30 , 0 ,
F_93 , V_2 ) ;
if ( F_48 ( & V_2 -> V_99 -> V_100 , V_171 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_172 ; V_9 ++ ) {
if ( F_116 ( V_2 -> V_349 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_349 [ V_9 ] = 0 ;
}
}
}
static void F_123 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_119 ( & V_2 -> V_350 ) ;
F_119 ( & V_2 -> V_351 ) ;
F_119 ( & V_2 -> V_352 ) ;
F_124 ( & V_2 -> V_353 ) ;
F_124 ( & V_2 -> V_354 ) ;
F_124 ( & V_2 -> V_355 ) ;
F_125 ( V_2 ) ;
F_86 ( & V_2 -> V_33 ) ;
F_118 ( V_2 ) ;
F_92 ( & V_2 -> V_33 ) ;
F_126 ( & V_2 -> V_351 ) ;
}
static struct V_356 * F_127 ( struct V_1 * V_2 )
{
V_133 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_112 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_128 ( struct V_1 * V_2 , struct V_281 * V_282 ,
T_3 V_357 )
{
struct V_358 V_359 = {
. V_360 . V_361 . V_362 = F_129 ( V_363 ) ,
. V_360 . V_361 . V_364 =
F_129 ( F_94 ( V_282 ) -> V_20 ) ,
. V_360 . V_361 . V_365 = F_130 ( 8 * V_357 ) ,
} ;
int V_220 = sizeof( V_359 ) ;
if ( V_357 == V_366 )
V_359 . V_360 . V_361 . V_365 = F_130 ( V_367 ) ;
if ( ! F_48 ( & V_2 -> V_99 -> V_100 , V_368 ) )
V_220 = sizeof( V_359 . V_360 ) ;
if ( ! F_49 ( & V_2 -> V_99 -> V_100 , V_369 ) )
V_220 = sizeof( V_359 . V_360 . V_361 ) ;
return F_131 ( V_2 , V_370 , 0 , V_220 , & V_359 ) ;
}
static int F_132 ( struct V_29 * V_30 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
int V_47 ;
V_317 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_371 ) ;
if ( V_47 )
return V_47 ;
F_86 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_342 , & V_2 -> V_15 ) )
V_317 -> V_372 . V_373 +=
V_317 -> V_372 . V_374 ;
V_47 = F_133 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_375;
if ( V_282 -> type != V_138 )
V_2 -> V_338 ++ ;
if ( V_282 -> type == V_136 ||
V_282 -> type == V_139 ) {
V_47 = F_134 ( V_2 , V_282 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_22 ) ;
goto V_376;
}
F_135 ( V_2 , V_282 ) ;
goto V_375;
}
V_317 -> V_124 |= V_30 -> V_75 ;
V_47 = F_136 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_376;
V_47 = F_137 ( V_2 ) ;
if ( V_47 )
goto V_377;
V_47 = F_138 ( V_2 , V_282 , 0 ) ;
if ( V_47 )
goto V_377;
if ( ! V_2 -> V_378 &&
V_282 -> type == V_114 && ! V_282 -> V_379 ) {
V_2 -> V_378 = V_317 ;
V_282 -> V_380 |= V_381 |
V_382 ;
}
if ( V_282 -> type == V_138 ) {
V_317 -> V_322 = F_127 ( V_2 ) ;
if ( ! V_317 -> V_322 ) {
V_47 = - V_383 ;
goto V_384;
}
F_139 ( V_2 , V_317 -> V_322 ) ;
V_47 = F_140 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_385;
V_47 = F_141 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_386;
V_2 -> V_331 = V_282 ;
}
F_135 ( V_2 , V_282 ) ;
goto V_375;
V_386:
F_142 ( V_2 , V_282 ) ;
V_385:
F_143 ( V_2 , V_317 -> V_322 ) ;
V_384:
if ( V_2 -> V_378 == V_317 ) {
V_2 -> V_378 = NULL ;
V_282 -> V_380 &= ~ ( V_381 |
V_382 ) ;
}
V_377:
V_317 -> V_322 = NULL ;
F_144 ( V_2 , V_282 ) ;
V_376:
if ( V_282 -> type != V_138 )
V_2 -> V_338 -- ;
F_145 ( V_2 , V_282 ) ;
V_375:
F_92 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_371 ) ;
return V_47 ;
}
static void F_146 ( struct V_1 * V_2 ,
struct V_281 * V_282 )
{
T_1 V_387 = F_147 ( V_282 ) ;
if ( V_387 ) {
F_86 ( & V_2 -> V_33 ) ;
F_148 ( V_2 , V_387 , 0 ) ;
F_92 ( & V_2 -> V_33 ) ;
F_149 ( V_2 -> V_7 , V_387 ) ;
}
if ( V_282 -> type == V_138 ) {
F_119 ( & V_2 -> V_348 ) ;
} else {
F_119 ( & V_2 -> V_388 ) ;
}
}
static void F_150 ( struct V_29 * V_30 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
F_146 ( V_2 , V_282 ) ;
F_86 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_378 == V_317 ) {
V_2 -> V_378 = NULL ;
V_282 -> V_380 &= ~ ( V_381 |
V_382 ) ;
}
F_151 ( V_2 , V_282 ) ;
if ( V_282 -> type == V_136 ||
V_282 -> type == V_139 ) {
#ifdef F_152
if ( V_282 == V_2 -> V_389 ) {
V_2 -> V_389 = NULL ;
V_2 -> V_390 = 0 ;
}
#endif
F_153 ( V_2 , V_282 ) ;
goto V_376;
}
if ( V_282 -> type == V_138 ) {
V_2 -> V_331 = NULL ;
F_154 ( V_2 , V_282 ) ;
F_142 ( V_2 , V_282 ) ;
F_143 ( V_2 , V_317 -> V_322 ) ;
V_317 -> V_322 = NULL ;
}
if ( V_2 -> V_338 && V_282 -> type != V_138 )
V_2 -> V_338 -- ;
F_137 ( V_2 ) ;
F_144 ( V_2 , V_282 ) ;
V_376:
F_145 ( V_2 , V_282 ) ;
F_92 ( & V_2 -> V_33 ) ;
}
static int F_155 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_156 ( void * V_391 , T_2 * V_316 ,
struct V_281 * V_282 )
{
struct V_392 * V_269 = V_391 ;
struct V_1 * V_2 = V_269 -> V_2 ;
struct V_393 * V_359 = V_2 -> V_394 ;
int V_47 , V_220 ;
if ( F_15 ( V_269 -> V_395 >= V_396 ) )
return;
if ( V_282 -> type != V_114 ||
! V_282 -> V_397 . V_398 )
return;
V_359 -> V_395 = V_269 -> V_395 ++ ;
memcpy ( V_359 -> V_399 , V_282 -> V_397 . V_399 , V_160 ) ;
V_220 = F_157 ( sizeof( * V_359 ) + V_359 -> V_400 * V_160 , 4 ) ;
V_47 = F_131 ( V_2 , V_401 , V_402 , V_220 , V_359 ) ;
if ( V_47 )
F_112 ( V_2 , L_23 , V_47 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_392 V_403 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_394 ) )
return;
F_159 (
V_2 -> V_30 , V_404 ,
F_156 , & V_403 ) ;
}
static T_4 F_160 ( struct V_29 * V_30 ,
struct V_405 * V_406 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_393 * V_359 ;
struct V_407 * V_157 ;
int V_408 ;
bool V_409 ;
int V_220 ;
V_408 = F_161 ( V_406 ) ;
V_409 = V_408 > V_410 ||
V_411 ;
if ( V_409 )
V_408 = 0 ;
V_220 = F_157 ( sizeof( * V_359 ) + V_408 * V_160 , 4 ) ;
V_359 = F_162 ( V_220 , V_412 ) ;
if ( ! V_359 )
return 0 ;
if ( V_409 ) {
V_359 -> V_409 = 1 ;
return ( T_4 ) ( unsigned long ) V_359 ;
}
F_163 (addr, mc_list) {
F_164 ( V_2 , L_24 ,
V_359 -> V_400 , V_157 -> V_157 ) ;
memcpy ( & V_359 -> V_413 [ V_359 -> V_400 * V_160 ] ,
V_157 -> V_157 , V_160 ) ;
V_359 -> V_400 ++ ;
}
return ( T_4 ) ( unsigned long ) V_359 ;
}
static void F_165 ( struct V_29 * V_30 ,
unsigned int V_414 ,
unsigned int * V_415 ,
T_4 V_416 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_393 * V_359 = ( void * ) ( unsigned long ) V_416 ;
F_86 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_394 ) ;
V_2 -> V_394 = V_359 ;
if ( ! V_359 )
goto V_34;
F_158 ( V_2 ) ;
V_34:
F_92 ( & V_2 -> V_33 ) ;
* V_415 = 0 ;
}
static void F_166 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
unsigned int V_417 ,
unsigned int V_414 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_414 & V_418 ) )
return;
if ( V_282 -> type != V_114 || ! V_282 -> V_397 . V_398 ||
! V_282 -> V_379 )
return;
F_86 ( & V_2 -> V_33 ) ;
F_167 ( V_2 , V_282 , false , NULL ) ;
F_92 ( & V_2 -> V_33 ) ;
}
static void
F_168 ( struct V_281 * V_282 ,
const struct V_419 * V_420 ,
struct V_419 * V_421 )
{
struct V_422 * V_423 ;
int V_9 ;
memcpy ( V_421 , V_420 , sizeof( * V_421 ) ) ;
for ( V_9 = 0 ; V_9 < F_42 ( V_421 -> V_424 ) ; V_9 ++ ) {
V_423 = & V_421 -> V_424 [ V_9 ] ;
if ( ! V_423 -> V_425 )
break;
switch ( V_423 -> V_426 ) {
case F_130 ( V_427 ) :
if ( V_282 -> V_397 . V_428 != 1 ) {
V_423 -> V_425 = 0 ;
continue;
}
V_423 -> V_429 = V_282 -> V_397 . V_430 [ 0 ] ;
break;
case F_130 ( V_431 ) :
V_423 -> V_429 = * ( V_432 * ) & V_282 -> V_157 [ 2 ] ;
break;
default:
break;
}
V_423 -> V_426 = 0 ;
V_421 -> V_433 ++ ;
}
}
static void F_169 ( void * V_391 , T_2 * V_316 ,
struct V_281 * V_282 )
{
struct V_434 * V_269 = V_391 ;
struct V_1 * V_2 = V_269 -> V_2 ;
struct V_435 * V_359 = V_269 -> V_359 ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
struct V_436 * V_437 ;
int V_9 ;
if ( F_8 ( V_317 -> V_20 >= F_42 ( V_359 -> V_438 ) ) )
return;
V_437 = & V_359 -> V_438 [ V_317 -> V_20 ] ;
if ( V_282 -> type != V_114 || V_282 -> V_379 ||
! V_282 -> V_397 . V_398 )
return;
V_437 -> V_439 = 1 ;
for ( V_9 = 0 ; V_2 -> V_241 [ V_9 ] . V_424 [ 0 ] . V_425 ; V_9 ++ ) {
if ( F_15 ( V_269 -> V_440 >=
F_42 ( V_359 -> V_441 ) ) ) {
V_437 -> V_439 = 0 ;
V_437 -> V_442 = 0 ;
break;
}
F_168 ( V_282 ,
& V_2 -> V_241 [ V_9 ] ,
& V_359 -> V_441 [ V_269 -> V_440 ] ) ;
if ( ! V_359 -> V_441 [ V_269 -> V_440 ] . V_433 )
continue;
V_437 -> V_442 |=
F_130 ( F_44 ( V_269 -> V_440 ) ) ;
V_269 -> V_440 ++ ;
}
}
bool F_170 ( struct V_1 * V_2 ,
struct V_435 * V_359 )
{
struct V_434 V_403 = {
. V_2 = V_2 ,
. V_359 = V_359 ,
} ;
if ( V_443 )
return false ;
memset ( V_359 , 0 , sizeof( * V_359 ) ) ;
V_359 -> V_444 = F_42 ( V_359 -> V_441 ) ;
V_359 -> V_445 = F_42 ( V_359 -> V_438 ) ;
#ifdef F_171
if ( V_2 -> V_446 . V_447 ) {
memcpy ( V_359 -> V_441 , & V_2 -> V_446 . V_359 . V_441 ,
sizeof( V_359 -> V_441 ) ) ;
memcpy ( V_359 -> V_438 , & V_2 -> V_446 . V_359 . V_438 ,
sizeof( V_359 -> V_438 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_241 )
return false ;
F_172 (
V_2 -> V_30 , V_404 ,
F_169 , & V_403 ) ;
return true ;
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_435 V_359 ;
if ( ! ( V_2 -> V_99 -> V_100 . V_101 & V_448 ) )
return 0 ;
if ( ! F_170 ( V_2 , & V_359 ) )
return 0 ;
return F_131 ( V_2 , V_449 , 0 ,
sizeof( V_359 ) , & V_359 ) ;
}
static inline int F_173 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_174 ( struct V_1 * V_2 ,
struct V_281 * V_282 )
{
struct V_450 V_359 = {} ;
memcpy ( V_359 . V_451 , V_282 -> V_397 . V_452 . V_453 ,
V_454 ) ;
memcpy ( V_359 . V_455 , V_282 -> V_397 . V_452 . V_456 ,
V_457 ) ;
return F_131 ( V_2 ,
F_175 ( V_458 ,
V_459 ) ,
0 , sizeof( V_359 ) , & V_359 ) ;
}
static void F_176 ( void * V_391 , T_2 * V_316 ,
struct V_281 * V_282 )
{
if ( V_282 -> V_460 ) {
struct V_461 * V_462 = V_391 ;
F_177 ( V_282 ,
( T_2 * ) & V_462 -> V_451 ,
( T_2 * ) & V_462 -> V_455 ) ;
}
}
void F_178 ( struct V_1 * V_2 ,
struct V_463 * V_464 )
{
struct V_465 * V_466 = F_179 ( V_464 ) ;
struct V_461 * V_462 = ( void * ) V_466 -> V_269 ;
F_159 (
V_2 -> V_30 , V_404 ,
F_176 , V_462 ) ;
}
static void F_180 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
struct V_467 * V_397 ,
T_1 V_468 )
{
struct V_131 * V_317 = F_94 ( V_282 ) ;
int V_47 ;
if ( V_468 & V_469 && V_397 -> V_398 )
F_181 ( V_2 , V_282 ) ;
if ( V_468 & V_469 && ! V_397 -> V_398 &&
V_317 -> V_470 )
F_182 ( V_282 , V_471 ,
0 , 0 ) ;
if ( V_468 & V_472 && ! V_317 -> V_473 )
memcpy ( V_317 -> V_399 , V_397 -> V_399 , V_160 ) ;
V_47 = F_167 ( V_2 , V_282 , false , V_317 -> V_399 ) ;
if ( V_47 )
F_112 ( V_2 , L_25 , V_282 -> V_157 ) ;
memcpy ( V_317 -> V_399 , V_397 -> V_399 , V_160 ) ;
V_317 -> V_473 = V_397 -> V_398 ;
if ( V_468 & V_469 ) {
if ( V_397 -> V_398 ) {
F_183 ( V_2 , true ) ;
memset ( & V_317 -> V_372 , 0 ,
sizeof( V_317 -> V_372 ) ) ;
V_47 = F_111 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_112 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_342 ,
& V_2 -> V_15 ) ) {
T_1 V_474 = ( 11 * V_282 -> V_397 . V_475 ) / 10 ;
F_184 ( V_2 , V_282 , V_474 , V_474 ,
5 * V_474 , false ) ;
}
F_185 ( V_2 , V_282 , false ) ;
F_186 ( V_2 , V_282 ) ;
if ( V_282 -> V_379 ) {
F_1 ( V_2 , V_476 ) ;
F_187 ( V_2 , V_282 ,
V_477 ,
V_478 ) ;
}
} else if ( V_317 -> V_319 != V_259 ) {
F_116 ( F_185 ( V_2 , V_282 , false ) ,
L_27 ) ;
V_47 = F_188 ( V_2 , V_282 , V_317 -> V_319 ) ;
if ( V_47 )
F_112 ( V_2 , L_28 ) ;
if ( V_2 -> V_260 == V_317 -> V_319 )
V_2 -> V_260 = V_259 ;
V_317 -> V_319 = V_259 ;
V_47 = F_111 ( V_2 , false , NULL ) ;
if ( V_47 )
F_112 ( V_2 , L_26 ) ;
if ( V_282 -> V_379 )
F_7 ( V_2 , V_476 ) ;
V_47 = F_167 ( V_2 , V_282 , false , NULL ) ;
if ( V_47 )
F_112 ( V_2 ,
L_29 ,
V_282 -> V_157 ) ;
}
if ( F_14 ( V_342 , & V_2 -> V_15 ) &&
( V_468 & V_479 ) && V_282 -> V_460 ) {
V_47 = F_174 ( V_2 , V_282 ) ;
if ( V_47 )
F_112 ( V_2 ,
L_30 ) ;
}
F_158 ( V_2 ) ;
F_173 ( V_2 ) ;
V_317 -> V_323 . V_480 = 0 ;
F_189 ( V_2 ) ;
F_187 ( V_2 , V_282 , V_481 ,
V_482 ) ;
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_171 ) )
F_190 ( V_2 ) ;
} else if ( V_468 & V_483 ) {
F_191 ( V_2 , V_317 ,
& V_317 -> V_321 ) ;
}
if ( V_468 & V_483 ) {
F_185 ( V_2 , V_282 , false ) ;
F_8 ( F_192 ( V_2 , V_282 , 0 ) ) ;
}
if ( V_468 & ( V_484 | V_485 | V_486 |
V_483 ) ) {
V_47 = F_137 ( V_2 ) ;
if ( V_47 )
F_112 ( V_2 , L_31 ) ;
}
if ( V_468 & V_487 ) {
F_193 ( V_2 , L_32 ,
V_397 -> V_488 ) ;
F_128 ( V_2 , V_282 , V_397 -> V_488 ) ;
}
if ( V_468 & V_489 ) {
F_164 ( V_2 , L_33 ) ;
V_317 -> V_323 . V_490 = 0 ;
if ( V_317 -> V_323 . V_491 ) {
V_47 = F_192 ( V_2 , V_282 , 0 ) ;
if ( V_47 )
F_112 ( V_2 ,
L_34 ) ;
}
}
if ( V_468 & V_492 ) {
F_164 ( V_2 , L_35 ) ;
F_173 ( V_2 ) ;
}
}
static int F_194 ( struct V_29 * V_30 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_493 ) ;
if ( V_47 )
return V_47 ;
F_86 ( & V_2 -> V_33 ) ;
V_47 = F_195 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_375;
if ( V_282 -> type == V_136 )
F_181 ( V_2 , V_282 ) ;
V_317 -> V_494 = 0 ;
V_47 = F_136 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_375;
V_47 = F_140 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_495;
V_47 = F_196 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_386;
V_317 -> V_496 = true ;
F_137 ( V_2 ) ;
V_47 = F_111 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_497;
if ( V_282 -> V_379 && V_2 -> V_331 )
F_167 ( V_2 , V_2 -> V_331 , false , NULL ) ;
F_1 ( V_2 , V_498 ) ;
F_189 ( V_2 ) ;
if ( F_197 ( V_2 ) > 1 )
F_113 ( V_2 ) ;
goto V_375;
V_497:
F_137 ( V_2 ) ;
V_317 -> V_496 = false ;
F_198 ( V_2 , V_282 ) ;
V_386:
F_142 ( V_2 , V_282 ) ;
V_495:
F_144 ( V_2 , V_282 ) ;
V_375:
F_92 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_493 ) ;
return V_47 ;
}
static void F_199 ( struct V_29 * V_30 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
F_146 ( V_2 , V_282 ) ;
F_86 ( & V_2 -> V_33 ) ;
if ( F_200 ( V_2 -> V_499 ) == V_282 ) {
F_191 ( V_2 , V_317 ,
& V_317 -> V_321 ) ;
F_201 ( V_2 -> V_499 , NULL ) ;
V_317 -> V_500 = false ;
}
if ( F_200 ( V_2 -> V_501 ) == V_282 ) {
F_201 ( V_2 -> V_501 , NULL ) ;
V_2 -> V_502 = 0 ;
}
V_317 -> V_496 = false ;
V_2 -> V_503 = 0 ;
F_189 ( V_2 ) ;
F_7 ( V_2 , V_498 ) ;
if ( V_282 -> V_379 && V_2 -> V_331 )
F_167 ( V_2 , V_2 -> V_331 , false , NULL ) ;
F_111 ( V_2 , false , NULL ) ;
F_198 ( V_2 , V_282 ) ;
F_142 ( V_2 , V_282 ) ;
F_137 ( V_2 ) ;
F_144 ( V_2 , V_282 ) ;
F_92 ( & V_2 -> V_33 ) ;
}
static void
F_202 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
struct V_467 * V_397 ,
T_1 V_468 )
{
struct V_131 * V_317 = F_94 ( V_282 ) ;
if ( ! V_317 -> V_496 )
return;
if ( V_468 & ( V_504 | V_505 |
V_506 | V_486 ) &&
F_167 ( V_2 , V_282 , false , NULL ) )
F_112 ( V_2 , L_25 , V_282 -> V_157 ) ;
if ( V_468 & V_507 &&
F_195 ( V_2 , V_282 ) )
F_203 ( V_2 , L_36 ) ;
if ( V_468 & V_487 ) {
F_193 ( V_2 , L_32 ,
V_397 -> V_488 ) ;
F_128 ( V_2 , V_282 , V_397 -> V_488 ) ;
}
}
static void F_204 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_467 * V_397 ,
T_1 V_468 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_508 ) )
return;
F_86 ( & V_2 -> V_33 ) ;
if ( V_468 & V_509 && ! V_397 -> V_510 )
F_205 ( V_2 , V_511 , true ) ;
switch ( V_282 -> type ) {
case V_114 :
F_180 ( V_2 , V_282 , V_397 , V_468 ) ;
break;
case V_136 :
case V_139 :
F_202 ( V_2 , V_282 , V_397 , V_468 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_92 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_508 ) ;
}
static int F_206 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_512 * V_513 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_513 -> V_514 . V_38 == 0 ||
V_513 -> V_514 . V_38 > V_2 -> V_99 -> V_100 . V_515 )
return - V_315 ;
F_86 ( & V_2 -> V_33 ) ;
V_47 = F_207 ( V_2 , V_282 , & V_513 -> V_514 , & V_513 -> V_516 ) ;
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_208 ( struct V_29 * V_30 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_86 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_328 & V_517 )
F_205 ( V_2 , V_517 , true ) ;
F_92 ( & V_2 -> V_33 ) ;
}
static void
F_209 ( struct V_29 * V_30 ,
struct V_251 * V_252 , V_133 V_518 ,
int V_519 ,
enum V_520 V_521 ,
bool V_522 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_210 ( V_2 , V_252 , V_521 , V_519 ,
V_518 , V_522 , false ) ;
}
static void
F_211 ( struct V_29 * V_30 ,
struct V_251 * V_252 , V_133 V_518 ,
int V_519 ,
enum V_520 V_521 ,
bool V_522 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_210 ( V_2 , V_252 , V_521 , V_519 ,
V_518 , V_522 , true ) ;
}
static void F_212 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
enum V_523 V_359 ,
struct V_251 * V_252 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_129 * V_255 = F_61 ( V_252 ) ;
unsigned long V_524 = 0 , V_518 = 0 ;
int V_283 ;
F_4 ( & V_255 -> V_525 ) ;
for ( V_283 = 0 ; V_283 < V_526 ; V_283 ++ ) {
struct V_293 * V_294 = & V_255 -> V_294 [ V_283 ] ;
if ( V_294 -> V_527 != V_528 &&
V_294 -> V_527 != V_529 )
continue;
F_213 ( V_294 -> V_530 , & V_524 ) ;
if ( F_214 ( V_294 ) == 0 )
continue;
F_213 ( V_283 , & V_518 ) ;
}
switch ( V_359 ) {
case V_531 :
if ( F_215 ( & V_2 -> V_532 [ V_255 -> V_258 ] ) > 0 )
F_216 ( V_30 , V_252 , true ) ;
F_217 (tid, &tids, IWL_MAX_TID_COUNT)
F_218 ( V_252 , V_283 , true ) ;
if ( V_524 )
F_219 ( V_2 -> V_7 , V_524 , true ) ;
break;
case V_533 :
if ( F_8 ( V_255 -> V_258 == V_259 ) )
break;
if ( V_524 )
F_219 ( V_2 -> V_7 , V_524 , false ) ;
F_220 ( V_2 , V_252 ) ;
break;
default:
break;
}
F_5 ( & V_255 -> V_525 ) ;
}
static void F_221 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_251 * V_252 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_129 * V_534 = F_61 ( V_252 ) ;
F_86 ( & V_2 -> V_33 ) ;
if ( V_252 == F_200 ( V_2 -> V_535 [ V_534 -> V_258 ] ) )
F_222 ( V_2 -> V_535 [ V_534 -> V_258 ] ,
F_223 ( - V_49 ) ) ;
F_92 ( & V_2 -> V_33 ) ;
}
static void F_224 ( struct V_1 * V_2 , struct V_281 * V_282 ,
const T_2 * V_399 )
{
if ( ! ( V_2 -> V_99 -> V_100 . V_101 & V_536 ) )
return;
if ( V_282 -> V_379 && ! F_225 ( V_2 ) ) {
V_282 -> V_380 &= ~ V_537 ;
return;
}
if ( ! V_282 -> V_379 &&
( V_103 . V_538 & V_539 ) ) {
V_282 -> V_380 &= ~ V_537 ;
return;
}
V_282 -> V_380 |= V_537 ;
}
static void
F_226 ( struct V_1 * V_2 ,
struct V_281 * V_282 , T_2 * V_540 ,
enum V_541 V_286 )
{
struct V_287 * V_288 ;
struct V_542 * V_543 ;
if ( ! F_80 ( V_2 -> V_99 , V_544 ) )
return;
V_288 = F_81 ( V_2 -> V_99 , V_544 ) ;
V_543 = ( void * ) V_288 -> V_269 ;
if ( ! F_82 ( V_2 , V_282 , V_288 ) )
return;
if ( ! ( V_543 -> V_545 & F_44 ( V_286 ) ) )
return;
if ( V_543 -> V_546 &&
memcmp ( V_543 -> V_547 , V_540 , V_160 ) != 0 )
return;
F_227 ( V_2 , V_288 ,
L_37 ,
V_540 , V_286 ) ;
}
static void F_228 ( struct V_1 * V_2 ,
struct V_129 * V_534 )
{
struct V_293 * V_294 ;
struct V_253 * V_254 ;
int V_9 ;
F_4 ( & V_534 -> V_525 ) ;
for ( V_9 = 0 ; V_9 <= V_526 ; V_9 ++ ) {
V_294 = & V_534 -> V_294 [ V_9 ] ;
while ( ( V_254 = F_229 ( & V_294 -> V_548 ) ) )
F_76 ( V_2 -> V_30 , V_254 ) ;
}
F_5 ( & V_534 -> V_525 ) ;
}
static int F_230 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_251 * V_252 ,
enum V_549 V_550 ,
enum V_549 V_551 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
int V_47 ;
F_164 ( V_2 , L_38 ,
V_252 -> V_157 , V_550 , V_551 ) ;
if ( F_15 ( ! V_317 -> V_322 ) )
return - V_315 ;
F_119 ( & V_2 -> V_388 ) ;
if ( V_550 == V_552 &&
V_551 == V_553 &&
F_40 ( V_2 ) ) {
struct V_129 * V_534 = F_61 ( V_252 ) ;
F_228 ( V_2 , V_534 ) ;
F_119 ( & V_2 -> V_352 ) ;
}
F_86 ( & V_2 -> V_33 ) ;
if ( V_550 == V_553 &&
V_551 == V_552 ) {
if ( V_282 -> type == V_114 &&
V_282 -> V_397 . V_475 < 16 ) {
F_112 ( V_2 ,
L_39 ,
V_252 -> V_157 , V_282 -> V_397 . V_475 ) ;
V_47 = - V_315 ;
goto V_375;
}
if ( V_252 -> V_554 &&
( V_282 -> V_379 ||
F_231 ( V_2 , NULL ) ==
V_555 ||
F_197 ( V_2 ) > 1 ) ) {
F_164 ( V_2 , L_40 ) ;
V_47 = - V_556 ;
goto V_375;
}
V_47 = F_232 ( V_2 , V_282 , V_252 ) ;
if ( V_252 -> V_554 && V_47 == 0 ) {
F_233 ( V_2 , V_282 , true ) ;
F_226 ( V_2 , V_282 , V_252 -> V_157 ,
V_557 ) ;
}
} else if ( V_550 == V_552 &&
V_551 == V_558 ) {
V_2 -> V_559 = true ;
F_224 ( V_2 , V_282 , V_252 -> V_157 ) ;
V_47 = 0 ;
} else if ( V_550 == V_558 &&
V_551 == V_560 ) {
if ( V_282 -> type == V_136 ) {
V_317 -> V_494 ++ ;
F_167 ( V_2 , V_282 , false , NULL ) ;
}
V_47 = F_234 ( V_2 , V_282 , V_252 ) ;
if ( V_47 == 0 )
F_235 ( V_2 , V_252 ,
V_317 -> V_322 -> V_561 -> V_562 ,
true ) ;
} else if ( V_550 == V_560 &&
V_551 == V_563 ) {
if ( F_197 ( V_2 ) > 1 )
F_113 ( V_2 ) ;
if ( V_252 -> V_554 )
F_226 ( V_2 , V_282 , V_252 -> V_157 ,
V_564 ) ;
F_8 ( F_192 ( V_2 , V_282 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_550 == V_563 &&
V_551 == V_560 ) {
F_8 ( F_138 ( V_2 , V_282 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_550 == V_560 &&
V_551 == V_558 ) {
if ( V_282 -> type == V_136 ) {
V_317 -> V_494 -- ;
F_167 ( V_2 , V_282 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_550 == V_558 &&
V_551 == V_552 ) {
V_47 = 0 ;
} else if ( V_550 == V_552 &&
V_551 == V_553 ) {
V_47 = F_236 ( V_2 , V_282 , V_252 ) ;
if ( V_252 -> V_554 ) {
F_233 ( V_2 , V_282 , false ) ;
F_226 ( V_2 , V_282 , V_252 -> V_157 ,
V_565 ) ;
}
} else {
V_47 = - V_17 ;
}
V_375:
F_92 ( & V_2 -> V_33 ) ;
if ( V_252 -> V_554 && V_47 == 0 ) {
if ( V_550 == V_553 &&
V_551 == V_552 )
F_237 ( V_252 , V_566 ) ;
else if ( V_550 == V_552 &&
V_551 == V_553 )
F_238 ( V_252 , V_566 ) ;
}
return V_47 ;
}
static int F_239 ( struct V_29 * V_30 , T_1 V_567 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_213 = V_567 ;
return 0 ;
}
static void F_240 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_251 * V_252 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_282 -> type == V_114 &&
V_27 & V_568 )
F_185 ( V_2 , V_282 , false ) ;
}
static int F_241 ( struct V_29 * V_30 ,
struct V_281 * V_282 , V_133 V_569 ,
const struct V_570 * V_304 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
V_317 -> V_571 [ V_569 ] = * V_304 ;
if ( V_282 -> type == V_138 ) {
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
V_47 = F_167 ( V_2 , V_282 , false , NULL ) ;
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_242 ( struct V_29 * V_30 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_572 = V_573 ;
T_1 V_574 = V_575 ;
if ( F_15 ( V_282 -> V_397 . V_398 ) )
return;
if ( F_12 ( V_2 , V_576 ) )
return;
F_86 ( & V_2 -> V_33 ) ;
F_184 ( V_2 , V_282 , V_572 , V_574 , 500 , false ) ;
F_92 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_576 ) ;
}
static int F_243 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_577 * V_514 ,
struct V_578 * V_516 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
if ( ! V_282 -> V_397 . V_510 ) {
V_47 = - V_556 ;
goto V_34;
}
V_47 = F_244 ( V_2 , V_282 , V_514 , V_516 , V_511 ) ;
V_34:
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_245 ( struct V_29 * V_30 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_328 & V_511 ) ) {
F_92 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_205 ( V_2 , V_511 , false ) ;
F_92 ( & V_2 -> V_33 ) ;
F_246 ( V_2 ) ;
return V_47 ;
}
static int F_247 ( struct V_29 * V_30 ,
enum V_579 V_359 ,
struct V_281 * V_282 ,
struct V_251 * V_252 ,
struct V_580 * V_581 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_129 * V_255 ;
struct V_582 * V_583 ;
int V_584 = V_581 -> V_584 ;
int V_47 ;
T_2 V_585 ;
if ( V_103 . V_104 ) {
F_164 ( V_2 , L_41 ) ;
return - V_586 ;
}
switch ( V_581 -> V_108 ) {
case V_54 :
V_581 -> V_101 |= V_587 ;
V_581 -> V_101 |= V_588 ;
break;
case V_55 :
case V_97 :
case V_98 :
V_581 -> V_101 |= V_588 ;
break;
case V_106 :
F_15 ( ! F_248 ( V_30 , V_105 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_282 -> type != V_114 )
return 0 ;
break;
default:
if ( V_30 -> V_112 &&
V_30 -> V_122 -> V_108 == V_581 -> V_108 )
V_581 -> V_101 |= V_588 ;
else
return - V_586 ;
}
F_86 ( & V_2 -> V_33 ) ;
switch ( V_359 ) {
case V_589 :
if ( ( V_282 -> type == V_139 ||
V_282 -> type == V_136 ) && ! V_252 ) {
if ( V_581 -> V_108 == V_106 )
V_47 = - V_586 ;
else
V_47 = 0 ;
V_581 -> V_590 = V_591 ;
break;
}
if ( F_14 ( V_342 , & V_2 -> V_15 ) &&
V_581 -> V_590 == V_591 ) {
F_164 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_342 , & V_2 -> V_15 ) &&
V_252 && F_39 ( V_2 ) &&
V_581 -> V_101 & V_592 &&
( V_581 -> V_108 == V_55 ||
V_581 -> V_108 == V_97 ||
V_581 -> V_108 == V_98 ) ) {
struct V_593 V_594 ;
int V_283 , V_595 ;
V_255 = F_61 ( V_252 ) ;
F_8 ( F_200 ( V_255 -> V_583 [ V_584 ] ) ) ;
V_583 = F_162 ( sizeof( * V_583 ) +
V_2 -> V_7 -> V_72 *
sizeof( V_583 -> V_595 [ 0 ] ) ,
V_596 ) ;
if ( ! V_583 ) {
V_47 = - V_597 ;
break;
}
for ( V_283 = 0 ; V_283 < V_526 ; V_283 ++ ) {
F_249 ( V_581 , V_283 , & V_594 ) ;
for ( V_595 = 0 ; V_595 < V_2 -> V_7 -> V_72 ; V_595 ++ )
memcpy ( V_583 -> V_595 [ V_595 ] . V_598 [ V_283 ] ,
V_594 . V_599 . V_598 ,
V_600 ) ;
}
F_222 ( V_255 -> V_583 [ V_584 ] , V_583 ) ;
}
if ( F_14 ( V_342 , & V_2 -> V_15 ) )
V_585 = V_581 -> V_590 ;
else
V_585 = V_591 ;
F_164 ( V_2 , L_43 ) ;
V_47 = F_250 ( V_2 , V_282 , V_252 , V_581 , V_585 ) ;
if ( V_47 ) {
F_203 ( V_2 , L_44 ) ;
V_581 -> V_590 = V_591 ;
V_47 = 0 ;
}
break;
case V_601 :
if ( V_581 -> V_590 == V_591 ) {
V_47 = 0 ;
break;
}
if ( V_252 && F_39 ( V_2 ) &&
V_581 -> V_101 & V_592 &&
( V_581 -> V_108 == V_55 ||
V_581 -> V_108 == V_97 ||
V_581 -> V_108 == V_98 ) ) {
V_255 = F_61 ( V_252 ) ;
V_583 = F_251 (
V_255 -> V_583 [ V_584 ] ,
F_252 ( & V_2 -> V_33 ) ) ;
F_201 ( V_255 -> V_583 [ V_584 ] , NULL ) ;
if ( V_583 )
F_253 ( V_583 , V_602 ) ;
}
F_164 ( V_2 , L_45 ) ;
V_47 = F_254 ( V_2 , V_282 , V_252 , V_581 ) ;
break;
default:
V_47 = - V_315 ;
}
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_255 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_580 * V_603 ,
struct V_251 * V_252 ,
T_1 V_604 , V_133 * V_605 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_603 -> V_590 == V_591 )
return;
F_256 ( V_2 , V_282 , V_603 , V_252 , V_604 , V_605 ) ;
}
static bool F_257 ( struct V_606 * V_607 ,
struct V_465 * V_466 , void * V_269 )
{
struct V_1 * V_2 =
F_258 ( V_607 , struct V_1 , V_607 ) ;
struct V_608 * V_32 ;
int V_609 = F_259 ( V_466 ) ;
struct V_610 * V_611 = V_269 ;
if ( F_8 ( V_466 -> V_268 . V_359 != V_612 ) )
return true ;
if ( F_15 ( V_609 != sizeof( * V_32 ) ) ) {
F_112 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_466 -> V_269 ;
F_260 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_613 ) ;
V_611 -> V_614 = F_43 ( V_32 -> V_613 ) ;
F_260 ( V_2 , L_48 ,
V_611 -> V_614 ) ;
F_4 ( & V_2 -> V_320 ) ;
F_261 ( & V_611 -> V_615 , & V_2 -> V_616 ) ;
F_5 ( & V_2 -> V_320 ) ;
return true ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_617 * V_561 ,
struct V_281 * V_282 ,
int V_572 )
{
int V_618 , V_619 = V_620 ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
struct V_610 * V_611 = & V_317 -> V_621 ;
static const V_133 V_622 [] = { V_612 } ;
struct V_623 V_624 ;
T_1 V_625 = V_282 -> V_397 . V_626 *
V_282 -> V_397 . V_475 ;
T_1 V_627 , V_628 ;
struct V_629 V_630 = {
. V_286 = F_129 ( V_631 ) ,
. V_632 =
F_129 ( F_263 ( V_633 , 0 ) ) ,
. V_634 = F_129 ( V_2 -> V_635 . V_258 ) ,
. V_636 . V_562 = ( V_561 -> V_562 == V_174 ) ?
V_637 : V_638 ,
. V_636 . V_561 = V_561 -> V_639 ,
. V_636 . V_640 = V_641 ,
. V_642 = F_129 ( F_264 ( V_2 -> V_7 , V_619 ) ) ,
} ;
V_628 = V_643 ;
V_627 = F_265 ( V_572 ) ;
if ( V_282 -> V_397 . V_398 ) {
V_628 = F_266 ( T_1 , V_625 * 3 , V_644 ) ;
if ( V_625 <= V_627 ) {
V_627 = V_625 - V_645 ;
if ( V_627 <= V_646 )
V_627 = V_625 -
V_647 ;
}
}
V_630 . V_572 = F_129 ( V_627 ) ;
V_630 . V_648 = F_129 ( V_628 ) ;
F_260 ( V_2 ,
L_49 ,
V_561 -> V_639 , V_627 , V_572 , V_628 ,
V_625 ) ;
memcpy ( V_630 . V_649 , V_282 -> V_157 , V_160 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_320 ) ;
if ( F_8 ( V_611 -> V_20 == V_612 ) ) {
F_5 ( & V_2 -> V_320 ) ;
return - V_17 ;
}
V_611 -> V_282 = V_282 ;
V_611 -> V_572 = V_572 ;
V_611 -> V_20 = V_612 ;
F_5 ( & V_2 -> V_320 ) ;
F_267 ( & V_2 -> V_607 , & V_624 ,
V_622 ,
F_42 ( V_622 ) ,
F_257 , V_611 ) ;
V_618 = F_131 ( V_2 , V_612 , 0 , sizeof( V_630 ) ,
& V_630 ) ;
if ( V_618 ) {
F_112 ( V_2 , L_50 , V_618 ) ;
F_268 ( & V_2 -> V_607 , & V_624 ) ;
goto V_650;
}
V_618 = F_269 ( & V_2 -> V_607 , & V_624 , 1 ) ;
F_15 ( V_618 ) ;
if ( V_618 ) {
V_650:
F_4 ( & V_2 -> V_320 ) ;
F_95 ( V_2 , V_611 ) ;
F_5 ( & V_2 -> V_320 ) ;
}
return V_618 ;
}
static int F_270 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_617 * V_561 ,
int V_572 ,
enum V_651 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
struct V_652 V_653 ;
struct V_356 * V_322 ;
int V_47 , V_9 ;
F_164 ( V_2 , L_51 , V_561 -> V_639 ,
V_572 , type ) ;
F_119 ( & V_2 -> V_348 ) ;
F_86 ( & V_2 -> V_33 ) ;
switch ( V_282 -> type ) {
case V_114 :
if ( F_48 ( & V_2 -> V_99 -> V_100 ,
V_654 ) ) {
V_47 = F_262 ( V_2 , V_561 ,
V_282 , V_572 ) ;
goto V_375;
}
F_112 ( V_2 , L_52 ) ;
V_47 = - V_315 ;
goto V_375;
case V_138 :
break;
default:
F_112 ( V_2 , L_53 , V_282 -> type ) ;
V_47 = - V_315 ;
goto V_375;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_322 = & V_2 -> V_18 [ V_9 ] ;
if ( V_322 -> V_21 == 0 || V_317 -> V_322 == V_322 )
continue;
if ( V_322 -> V_21 && V_561 == V_322 -> V_561 ) {
V_47 = F_142 ( V_2 , V_282 ) ;
if ( F_271 ( V_47 , L_54 ) )
goto V_375;
F_143 ( V_2 , V_317 -> V_322 ) ;
V_317 -> V_322 = V_322 ;
V_47 = F_140 ( V_2 , V_282 ) ;
if ( F_271 ( V_47 , L_55 ) )
goto V_375;
F_139 ( V_2 , V_317 -> V_322 ) ;
goto V_655;
}
}
if ( V_561 == V_317 -> V_322 -> V_561 )
goto V_655;
F_272 ( & V_653 , V_561 , V_656 ) ;
if ( V_317 -> V_322 -> V_21 == 1 ) {
V_47 = F_273 ( V_2 , V_317 -> V_322 ,
& V_653 , 1 , 1 ) ;
if ( V_47 )
goto V_375;
} else {
V_322 = F_127 ( V_2 ) ;
if ( ! V_322 ) {
V_47 = - V_383 ;
goto V_375;
}
V_47 = F_273 ( V_2 , V_322 , & V_653 ,
1 , 1 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_56 ) ;
goto V_375;
}
V_47 = F_142 ( V_2 , V_282 ) ;
if ( F_271 ( V_47 , L_54 ) )
goto V_375;
F_143 ( V_2 , V_317 -> V_322 ) ;
V_317 -> V_322 = V_322 ;
V_47 = F_140 ( V_2 , V_282 ) ;
if ( F_271 ( V_47 , L_55 ) )
goto V_375;
F_139 ( V_2 , V_317 -> V_322 ) ;
}
V_655:
V_47 = F_274 ( V_2 , V_282 , V_572 , type ) ;
V_375:
F_92 ( & V_2 -> V_33 ) ;
F_164 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_275 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_164 ( V_2 , L_58 ) ;
F_86 ( & V_2 -> V_33 ) ;
F_276 ( V_2 ) ;
F_92 ( & V_2 -> V_33 ) ;
F_164 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_277 ( struct V_1 * V_2 ,
struct V_657 * V_658 )
{
V_133 * V_659 = ( V_133 * ) V_658 -> V_660 ;
struct V_356 * V_322 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_164 ( V_2 , L_59 ) ;
V_322 = F_127 ( V_2 ) ;
if ( ! V_322 ) {
V_47 = - V_383 ;
goto V_34;
}
V_47 = F_273 ( V_2 , V_322 , & V_658 -> V_661 ,
V_658 -> V_662 ,
V_658 -> V_663 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_60 ) ;
goto V_34;
}
F_139 ( V_2 , V_322 ) ;
* V_659 = V_322 -> V_20 ;
V_34:
return V_47 ;
}
static int F_278 ( struct V_29 * V_30 ,
struct V_657 * V_658 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
V_47 = F_277 ( V_2 , V_658 ) ;
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_279 ( struct V_1 * V_2 ,
struct V_657 * V_658 )
{
V_133 * V_659 = ( V_133 * ) V_658 -> V_660 ;
struct V_356 * V_322 = & V_2 -> V_18 [ * V_659 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_143 ( V_2 , V_322 ) ;
}
static void F_280 ( struct V_29 * V_30 ,
struct V_657 * V_658 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_86 ( & V_2 -> V_33 ) ;
F_279 ( V_2 , V_658 ) ;
F_92 ( & V_2 -> V_33 ) ;
}
static void F_281 ( struct V_29 * V_30 ,
struct V_657 * V_658 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_133 * V_659 = ( V_133 * ) V_658 -> V_660 ;
struct V_356 * V_322 = & V_2 -> V_18 [ * V_659 ] ;
if ( F_116 ( ( V_322 -> V_21 > 1 ) &&
( V_27 & ~ ( V_664 |
V_665 |
V_666 |
V_667 ) ) ,
L_61 ,
V_322 -> V_21 , V_27 ) )
return;
F_86 ( & V_2 -> V_33 ) ;
F_189 ( V_2 ) ;
F_273 ( V_2 , V_322 , & V_658 -> V_661 ,
V_658 -> V_662 ,
V_658 -> V_663 ) ;
F_92 ( & V_2 -> V_33 ) ;
}
static int F_282 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
struct V_657 * V_658 ,
bool V_668 )
{
V_133 * V_659 = ( V_133 * ) V_658 -> V_660 ;
struct V_356 * V_322 = & V_2 -> V_18 [ * V_659 ] ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_317 -> V_322 = V_322 ;
switch ( V_282 -> type ) {
case V_136 :
if ( V_668 ) {
V_317 -> V_496 = true ;
break;
}
case V_139 :
V_47 = 0 ;
goto V_34;
case V_114 :
break;
case V_669 :
V_317 -> V_329 = true ;
break;
default:
V_47 = - V_315 ;
goto V_34;
}
V_47 = F_140 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_34;
F_137 ( V_2 ) ;
if ( V_282 -> type == V_669 ) {
V_317 -> V_670 = true ;
V_47 = F_111 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_671;
V_47 = F_283 ( V_2 , V_282 ) ;
if ( V_47 )
goto V_671;
}
if ( V_282 -> type == V_136 ) {
F_111 ( V_2 , false , NULL ) ;
F_167 ( V_2 , V_282 , false , NULL ) ;
}
if ( V_668 && V_282 -> type == V_114 ) {
T_1 V_572 = 2 * V_282 -> V_397 . V_475 ;
V_47 = F_12 ( V_2 , V_672 ) ;
if ( V_47 )
goto V_671;
F_184 ( V_2 , V_282 , V_572 , V_572 ,
V_282 -> V_397 . V_475 / 2 ,
true ) ;
F_7 ( V_2 , V_672 ) ;
F_111 ( V_2 , false , NULL ) ;
}
goto V_34;
V_671:
F_142 ( V_2 , V_282 ) ;
F_137 ( V_2 ) ;
V_34:
if ( V_47 )
V_317 -> V_322 = NULL ;
return V_47 ;
}
static int F_284 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_657 * V_658 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
V_47 = F_282 ( V_2 , V_282 , V_658 , false ) ;
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_285 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
struct V_657 * V_658 ,
bool V_668 )
{
struct V_131 * V_317 = F_94 ( V_282 ) ;
struct V_281 * V_673 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_191 ( V_2 , V_317 , & V_317 -> V_321 ) ;
switch ( V_282 -> type ) {
case V_139 :
goto V_34;
case V_669 :
V_317 -> V_670 = false ;
V_317 -> V_329 = false ;
F_286 ( V_2 , V_282 ) ;
break;
case V_136 :
if ( ! V_668 || ! V_317 -> V_496 )
goto V_34;
V_317 -> V_500 = false ;
F_287 ( V_2 , V_317 , true ) ;
F_222 ( V_2 -> V_501 , V_282 ) ;
V_317 -> V_496 = false ;
break;
case V_114 :
if ( ! V_668 )
break;
V_673 = V_282 ;
F_167 ( V_2 , V_282 , true , NULL ) ;
break;
default:
break;
}
F_111 ( V_2 , false , V_673 ) ;
F_142 ( V_2 , V_282 ) ;
V_34:
V_317 -> V_322 = NULL ;
F_137 ( V_2 ) ;
}
static void F_288 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_657 * V_658 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_86 ( & V_2 -> V_33 ) ;
F_285 ( V_2 , V_282 , V_658 , false ) ;
F_92 ( & V_2 -> V_33 ) ;
}
static int
F_289 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
F_285 ( V_2 , V_675 [ 0 ] . V_282 , V_675 [ 0 ] . V_676 , true ) ;
F_279 ( V_2 , V_675 [ 0 ] . V_676 ) ;
V_47 = F_277 ( V_2 , V_675 [ 0 ] . V_677 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_62 ) ;
goto V_678;
}
V_47 = F_282 ( V_2 , V_675 [ 0 ] . V_282 , V_675 [ 0 ] . V_677 ,
true ) ;
if ( V_47 ) {
F_112 ( V_2 ,
L_63 ) ;
goto V_495;
}
if ( F_197 ( V_2 ) > 1 )
F_113 ( V_2 ) ;
goto V_34;
V_495:
F_279 ( V_2 , V_675 [ 0 ] . V_677 ) ;
V_678:
if ( F_277 ( V_2 , V_675 [ 0 ] . V_676 ) ) {
F_112 ( V_2 , L_64 ) ;
goto V_679;
}
if ( F_282 ( V_2 , V_675 [ 0 ] . V_282 , V_675 [ 0 ] . V_676 ,
true ) ) {
F_112 ( V_2 , L_65 ) ;
goto V_679;
}
goto V_34;
V_679:
F_290 ( V_2 , false ) ;
V_34:
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_291 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
F_285 ( V_2 , V_675 [ 0 ] . V_282 , V_675 [ 0 ] . V_676 , true ) ;
V_47 = F_282 ( V_2 , V_675 [ 0 ] . V_282 , V_675 [ 0 ] . V_677 ,
true ) ;
if ( V_47 ) {
F_112 ( V_2 ,
L_63 ) ;
goto V_678;
}
goto V_34;
V_678:
if ( F_282 ( V_2 , V_675 [ 0 ] . V_282 , V_675 [ 0 ] . V_676 ,
true ) ) {
F_112 ( V_2 , L_65 ) ;
goto V_679;
}
goto V_34;
V_679:
F_290 ( V_2 , false ) ;
V_34:
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_292 ( struct V_29 * V_30 ,
struct V_674 * V_675 ,
int V_680 ,
enum V_681 V_682 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_680 > 1 )
return - V_586 ;
switch ( V_682 ) {
case V_683 :
V_47 = F_289 ( V_2 , V_675 ) ;
break;
case V_684 :
V_47 = F_291 ( V_2 , V_675 ) ;
break;
default:
V_47 = - V_586 ;
break;
}
return V_47 ;
}
static int F_293 ( struct V_29 * V_30 ,
struct V_251 * V_252 ,
bool V_685 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_129 * V_534 = F_61 ( V_252 ) ;
if ( ! V_534 || ! V_534 -> V_282 ) {
F_112 ( V_2 , L_66 ) ;
return - V_315 ;
}
return F_195 ( V_2 , V_534 -> V_282 ) ;
}
static int F_294 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
void * V_269 , int V_220 )
{
struct V_686 * V_687 [ V_688 + 1 ] ;
int V_689 ;
T_1 V_390 ;
V_689 = F_295 ( V_687 , V_688 , V_269 , V_220 , V_690 ) ;
if ( V_689 )
return V_689 ;
if ( ! V_687 [ V_691 ] )
return - V_315 ;
switch ( F_296 ( V_687 [ V_691 ] ) ) {
case V_692 :
if ( ! V_282 || V_282 -> type != V_136 || ! V_282 -> V_379 ||
! V_282 -> V_397 . V_693 ||
! V_687 [ V_694 ] )
return - V_315 ;
V_390 = F_296 ( V_687 [ V_694 ] ) ;
if ( V_390 >= V_282 -> V_397 . V_475 )
return - V_315 ;
V_2 -> V_390 = V_390 ;
V_2 -> V_389 = V_282 ;
return F_111 ( V_2 , false , NULL ) ;
case V_695 :
if ( ! V_282 || V_282 -> type != V_114 ||
! V_282 -> V_397 . V_398 || ! V_282 -> V_397 . V_626 ||
! V_687 [ V_696 ] )
return - V_315 ;
if ( F_296 ( V_687 [ V_696 ] ) )
return F_192 ( V_2 , V_282 , 0 ) ;
return F_138 ( V_2 , V_282 , 0 ) ;
}
return - V_586 ;
}
static int F_297 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
void * V_269 , int V_220 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_689 ;
F_86 ( & V_2 -> V_33 ) ;
V_689 = F_294 ( V_2 , V_282 , V_269 , V_220 ) ;
F_92 ( & V_2 -> V_33 ) ;
return V_689 ;
}
static void F_298 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_697 * V_698 )
{
F_164 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_299 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_697 * V_698 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_281 * V_499 ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
T_1 V_642 ;
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
V_317 -> V_699 = false ;
F_164 ( V_2 , L_68 ,
V_698 -> V_653 . V_700 ) ;
F_300 ( V_2 , V_282 , V_701 ) ;
switch ( V_282 -> type ) {
case V_136 :
V_499 =
F_251 ( V_2 -> V_499 ,
F_252 ( & V_2 -> V_33 ) ) ;
if ( F_116 ( V_499 && V_499 -> V_702 ,
L_69 ) ) {
V_47 = - V_556 ;
goto V_375;
}
if ( F_251 ( V_2 -> V_501 ,
F_252 ( & V_2 -> V_33 ) ) ) {
V_47 = - V_556 ;
goto V_375;
}
F_222 ( V_2 -> V_499 , V_282 ) ;
if ( F_116 ( V_317 -> V_500 ,
L_70 ) ) {
V_47 = - V_556 ;
goto V_375;
}
V_317 -> V_703 = V_698 -> V_653 . V_704 -> V_705 ;
break;
case V_114 :
if ( V_317 -> V_470 )
F_182 ( V_282 ,
V_471 ,
0 , 0 ) ;
V_642 = V_698 -> V_706 +
( ( V_282 -> V_397 . V_475 * ( V_698 -> V_400 - 1 ) -
V_707 ) * 1024 ) ;
if ( V_698 -> V_708 )
F_301 ( V_2 , V_282 ) ;
F_302 ( V_2 , V_282 , V_282 -> V_397 . V_475 ,
V_642 ) ;
if ( V_317 -> V_323 . V_491 ) {
V_47 = F_138 ( V_2 , V_282 , 0 ) ;
if ( V_47 )
goto V_375;
}
break;
default:
break;
}
V_317 -> V_329 = true ;
V_47 = F_303 ( V_2 ) ;
if ( V_47 )
goto V_375;
F_113 ( V_2 ) ;
V_375:
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_304 ( struct V_29 * V_30 ,
struct V_281 * V_282 )
{
struct V_131 * V_317 = F_94 ( V_282 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_86 ( & V_2 -> V_33 ) ;
if ( V_317 -> V_699 ) {
V_317 -> V_699 = false ;
V_47 = - V_17 ;
goto V_375;
}
if ( V_282 -> type == V_114 ) {
struct V_129 * V_255 ;
V_255 = F_305 ( V_2 ,
V_317 -> V_319 ) ;
if ( F_8 ( ! V_255 ) ) {
V_47 = - V_17 ;
goto V_375;
}
F_306 ( V_2 , V_255 , false ) ;
F_167 ( V_2 , V_282 , false , NULL ) ;
V_47 = F_192 ( V_2 , V_282 , 0 ) ;
if ( V_47 )
goto V_375;
F_307 ( V_2 , V_282 ) ;
}
V_317 -> V_329 = false ;
V_47 = F_303 ( V_2 ) ;
V_375:
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_308 ( struct V_29 * V_30 ,
struct V_281 * V_282 , T_1 V_78 , bool V_270 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 ;
struct V_129 * V_255 ;
struct V_251 * V_252 ;
int V_9 ;
T_1 V_709 = 0 ;
if ( ! V_282 || V_282 -> type != V_114 )
return;
if ( F_40 ( V_2 ) )
F_119 ( & V_2 -> V_352 ) ;
F_86 ( & V_2 -> V_33 ) ;
V_317 = F_94 ( V_282 ) ;
for ( V_9 = 0 ; V_9 < V_259 ; V_9 ++ ) {
V_252 = F_251 ( V_2 -> V_535 [ V_9 ] ,
F_252 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_252 ) )
continue;
V_255 = F_61 ( V_252 ) ;
if ( V_255 -> V_282 != V_282 )
continue;
F_8 ( V_9 != V_317 -> V_319 && ! V_252 -> V_554 ) ;
V_709 |= V_255 -> V_710 ;
}
if ( V_270 ) {
if ( F_148 ( V_2 , V_709 , 0 ) )
F_112 ( V_2 , L_71 ) ;
F_92 ( & V_2 -> V_33 ) ;
} else {
F_92 ( & V_2 -> V_33 ) ;
F_149 ( V_2 -> V_7 , V_709 ) ;
}
}
static int F_309 ( struct V_29 * V_30 , int V_711 ,
struct V_712 * V_713 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_713 , 0 , sizeof( * V_713 ) ) ;
if ( V_711 != 0 )
return - V_49 ;
if ( ! F_48 ( & V_2 -> V_99 -> V_100 ,
V_714 ) )
return - V_49 ;
F_86 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_715 ) {
V_47 = F_183 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_713 -> V_716 = V_717 |
V_718 |
V_719 |
V_720 ;
V_713 -> time = V_2 -> V_347 . V_721 +
V_2 -> V_722 . V_721 ;
F_310 ( V_713 -> time , V_723 ) ;
V_713 -> V_724 = V_2 -> V_347 . V_725 +
V_2 -> V_722 . V_725 ;
F_310 ( V_713 -> V_724 , V_723 ) ;
V_713 -> V_726 = V_2 -> V_347 . V_727 +
V_2 -> V_722 . V_727 ;
F_310 ( V_713 -> V_726 , V_723 ) ;
V_713 -> V_728 = V_2 -> V_347 . V_729 +
V_2 -> V_722 . V_729 ;
F_310 ( V_713 -> V_728 , V_723 ) ;
V_47 = 0 ;
V_34:
F_92 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_311 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
struct V_251 * V_252 ,
struct V_730 * V_731 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_131 * V_317 = F_94 ( V_282 ) ;
struct V_129 * V_255 = F_61 ( V_252 ) ;
if ( V_255 -> V_732 ) {
V_731 -> V_733 = V_255 -> V_732 ;
V_731 -> V_716 |= F_44 ( V_734 ) ;
}
if ( ! F_48 ( & V_2 -> V_99 -> V_100 ,
V_714 ) )
return;
if ( ! ( V_282 -> V_380 & V_381 ) )
return;
if ( ! V_282 -> V_397 . V_398 )
return;
F_86 ( & V_2 -> V_33 ) ;
if ( V_317 -> V_319 != V_255 -> V_258 )
goto V_735;
if ( F_183 ( V_2 , false ) )
goto V_735;
V_731 -> V_736 = V_317 -> V_372 . V_374 +
V_317 -> V_372 . V_373 ;
V_731 -> V_716 |= F_44 ( V_737 ) ;
if ( V_317 -> V_372 . V_738 ) {
V_731 -> V_739 = V_317 -> V_372 . V_738 ;
V_731 -> V_716 |= F_44 ( V_740 ) ;
}
V_735:
F_92 ( & V_2 -> V_33 ) ;
}
static void F_312 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
const struct V_741 * V_742 )
{
#define F_313 ( T_5 , T_6 , T_7 , T_8 , T_9 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_287 * V_288 ;
struct V_743 * V_744 ;
if ( ! F_80 ( V_2 -> V_99 , V_745 ) )
return;
V_288 = F_81 ( V_2 -> V_99 , V_745 ) ;
V_744 = ( void * ) V_288 -> V_269 ;
if ( ! F_82 ( V_2 , V_282 , V_288 ) )
return;
if ( V_742 -> V_746 . V_747 . V_269 == V_748 ) {
if ( V_742 -> V_746 . V_747 . V_15 == V_749 )
F_313 ( V_2 , V_288 , V_750 ,
V_744 -> V_751 ,
L_72 ,
V_742 -> V_746 . V_747 . V_521 ) ;
else if ( V_742 -> V_746 . V_747 . V_15 == V_752 )
F_313 ( V_2 , V_288 , V_750 ,
V_744 -> V_753 ,
L_73 ) ;
} else if ( V_742 -> V_746 . V_747 . V_269 == V_754 ) {
if ( V_742 -> V_746 . V_747 . V_15 == V_749 )
F_313 ( V_2 , V_288 , V_750 ,
V_744 -> V_755 ,
L_74 ,
V_742 -> V_746 . V_747 . V_521 ) ;
else if ( V_742 -> V_746 . V_747 . V_15 == V_752 )
F_313 ( V_2 , V_288 , V_750 ,
V_744 -> V_756 ,
L_75 ) ;
} else if ( V_742 -> V_746 . V_747 . V_269 == V_757 ) {
F_313 ( V_2 , V_288 , V_750 ,
V_744 -> V_758 ,
L_76 , V_742 -> V_746 . V_747 . V_521 ) ;
} else if ( V_742 -> V_746 . V_747 . V_269 == V_759 ) {
F_313 ( V_2 , V_288 , V_750 ,
V_744 -> V_760 ,
L_77 , V_742 -> V_746 . V_747 . V_521 ) ;
}
#undef F_313
}
static void F_314 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
const struct V_741 * V_742 )
{
struct V_287 * V_288 ;
struct V_289 * V_290 ;
if ( ! F_80 ( V_2 -> V_99 , V_291 ) )
return;
V_288 = F_81 ( V_2 -> V_99 , V_291 ) ;
V_290 = ( void * ) V_288 -> V_269 ;
if ( ! F_82 ( V_2 , V_282 , V_288 ) )
return;
if ( ! ( F_315 ( V_290 -> V_761 ) & F_44 ( V_742 -> V_746 . V_762 . V_283 ) ) )
return;
F_227 ( V_2 , V_288 ,
L_78 ,
V_742 -> V_746 . V_762 . V_252 -> V_157 , V_742 -> V_746 . V_762 . V_283 ,
V_742 -> V_746 . V_762 . V_296 ) ;
}
static void
F_316 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
const struct V_741 * V_742 )
{
struct V_287 * V_288 ;
struct V_289 * V_290 ;
if ( ! F_80 ( V_2 -> V_99 , V_291 ) )
return;
V_288 = F_81 ( V_2 -> V_99 , V_291 ) ;
V_290 = ( void * ) V_288 -> V_269 ;
if ( ! F_82 ( V_2 , V_282 , V_288 ) )
return;
if ( ! ( F_315 ( V_290 -> V_763 ) & F_44 ( V_742 -> V_746 . V_762 . V_283 ) ) )
return;
F_227 ( V_2 , V_288 ,
L_79 ,
V_742 -> V_746 . V_762 . V_252 -> V_157 , V_742 -> V_746 . V_762 . V_283 ) ;
}
static void F_317 ( struct V_29 * V_30 ,
struct V_281 * V_282 ,
const struct V_741 * V_742 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_742 -> type ) {
case V_764 :
F_312 ( V_2 , V_282 , V_742 ) ;
break;
case V_765 :
F_314 ( V_2 , V_282 , V_742 ) ;
break;
case V_766 :
F_316 ( V_2 , V_282 , V_742 ) ;
break;
default:
break;
}
}
void F_318 ( struct V_1 * V_2 ,
struct V_767 * V_462 ,
T_1 V_768 )
{
F_319 ( V_769 ) ;
T_1 V_770 = F_44 ( V_2 -> V_7 -> V_72 ) - 1 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! F_39 ( V_2 ) )
return;
V_462 -> V_771 = V_2 -> V_772 ;
if ( V_462 -> V_773 )
F_320 ( & V_2 -> V_774 ,
V_2 -> V_7 -> V_72 ) ;
V_47 = F_321 ( V_2 , V_770 , ( T_2 * ) V_462 , V_768 ) ;
if ( V_47 ) {
F_112 ( V_2 , L_80 , V_47 ) ;
goto V_34;
}
if ( V_462 -> V_773 )
V_47 = F_13 ( V_769 ,
F_215 ( & V_2 -> V_774 ) == 0 ,
V_16 ) ;
F_15 ( ! V_47 ) ;
V_34:
F_320 ( & V_2 -> V_774 , 0 ) ;
V_2 -> V_772 ++ ;
}
static void F_322 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_767 V_269 = {
. type = V_775 ,
. V_773 = 1 ,
} ;
F_86 ( & V_2 -> V_33 ) ;
F_318 ( V_2 , & V_269 , sizeof( V_269 ) ) ;
F_92 ( & V_2 -> V_33 ) ;
}
