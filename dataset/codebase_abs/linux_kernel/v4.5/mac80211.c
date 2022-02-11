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
F_8 ( ! V_2 -> V_6 [ V_4 ] -- ) ;
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
if ( V_2 -> V_7 -> V_71 )
V_30 -> V_72 = V_73 | V_74 ;
V_30 -> V_75 = V_2 -> V_76 ;
V_30 -> V_77 = V_78 ;
V_30 -> V_79 |= V_80 |
V_81 ;
V_30 -> V_82 |= V_83 |
V_84 ;
V_30 -> V_85 = L_9 ;
V_30 -> V_86 = V_87 ;
V_30 -> V_88 = V_89 ;
F_39 ( F_40 ( V_2 -> V_90 ) < F_40 ( V_51 ) + 2 ) ;
memcpy ( V_2 -> V_90 , V_51 , sizeof( V_51 ) ) ;
V_30 -> V_23 -> V_91 = F_40 ( V_51 ) ;
V_30 -> V_23 -> V_92 = V_2 -> V_90 ;
if ( V_2 -> V_93 -> V_94 . V_95 & V_96 &&
! V_97 . V_98 ) {
F_38 ( V_30 , V_99 ) ;
V_2 -> V_90 [ V_30 -> V_23 -> V_91 ] =
V_100 ;
V_30 -> V_23 -> V_91 ++ ;
}
if ( V_2 -> V_93 -> V_101 [ 0 ] . V_102 ) {
V_2 -> V_30 -> V_103 = 1 ;
V_2 -> V_30 -> V_104 = & V_2 -> V_93 -> V_101 [ 0 ] ;
V_2 -> V_90 [ V_30 -> V_23 -> V_91 ] =
V_2 -> V_93 -> V_101 [ 0 ] . V_102 ;
V_30 -> V_23 -> V_91 ++ ;
}
F_38 ( V_30 , V_105 ) ;
V_30 -> V_23 -> V_106 |=
V_107 |
V_108 |
V_109 ;
V_30 -> V_110 = sizeof( struct V_111 ) ;
V_30 -> V_112 = sizeof( struct V_113 ) ;
V_30 -> V_114 = sizeof( V_115 ) ;
V_30 -> V_23 -> V_116 = F_41 ( V_117 ) |
F_41 ( V_118 ) |
F_41 ( V_119 ) |
F_41 ( V_120 ) |
F_41 ( V_121 ) |
F_41 ( V_122 ) ;
V_30 -> V_23 -> V_95 |= V_123 ;
V_30 -> V_23 -> V_124 |= V_125 ;
if ( F_30 ( V_2 ) )
V_30 -> V_23 -> V_124 |= V_126 ;
else
V_30 -> V_23 -> V_124 |= V_127 |
V_128 ;
if ( V_2 -> V_93 -> V_94 . V_95 & V_129 )
V_30 -> V_23 -> V_95 |= V_130 ;
V_30 -> V_23 -> V_95 |= V_131 ;
V_30 -> V_23 -> V_132 = V_133 ;
V_30 -> V_23 -> V_134 =
F_40 ( V_133 ) ;
V_30 -> V_23 -> V_135 = 10000 ;
V_30 -> V_136 = V_137 ;
V_30 -> V_23 -> V_138 = 3 * 5 ;
memcpy ( V_2 -> V_139 [ 0 ] . V_140 , V_2 -> V_141 -> V_142 , V_143 ) ;
V_30 -> V_23 -> V_139 = V_2 -> V_139 ;
V_30 -> V_23 -> V_144 = 1 ;
V_50 = ( V_2 -> V_141 -> V_145 > 1 ) ?
F_42 ( V_146 , V_2 -> V_141 -> V_145 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_50 ; V_9 ++ ) {
memcpy ( V_2 -> V_139 [ V_9 ] . V_140 , V_2 -> V_139 [ V_9 - 1 ] . V_140 ,
V_143 ) ;
V_2 -> V_139 [ V_9 ] . V_140 [ 5 ] ++ ;
V_30 -> V_23 -> V_144 ++ ;
}
F_16 ( V_2 ) ;
V_30 -> V_23 -> V_147 = F_43 ( V_2 ) ;
V_30 -> V_23 -> V_148 = V_149 ;
F_39 ( V_150 & V_151 ) ;
F_39 ( V_152 > F_44 ( V_151 ) ||
V_153 > F_44 ( V_151 ) ) ;
if ( F_45 ( & V_2 -> V_93 -> V_94 , V_154 ) )
V_2 -> V_155 = V_152 ;
else
V_2 -> V_155 = V_153 ;
if ( V_2 -> V_141 -> V_156 [ V_157 ] . V_38 )
V_30 -> V_23 -> V_156 [ V_157 ] =
& V_2 -> V_141 -> V_156 [ V_157 ] ;
if ( V_2 -> V_141 -> V_156 [ V_158 ] . V_38 ) {
V_30 -> V_23 -> V_156 [ V_158 ] =
& V_2 -> V_141 -> V_156 [ V_158 ] ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_159 ) &&
F_46 ( & V_2 -> V_93 -> V_94 ,
V_160 ) )
V_30 -> V_23 -> V_156 [ V_158 ] -> V_161 . V_162 |=
V_163 ;
}
V_30 -> V_23 -> V_164 = V_2 -> V_7 -> V_165 ;
if ( V_166 . V_167 != V_168 )
V_30 -> V_23 -> V_95 |= V_169 ;
else
V_30 -> V_23 -> V_95 &= ~ V_169 ;
V_30 -> V_23 -> V_95 |= V_170 ;
V_30 -> V_23 -> V_171 = V_149 ;
V_30 -> V_23 -> V_172 = V_173 ;
V_30 -> V_23 -> V_174 =
V_175 - 24 - 2 ;
V_30 -> V_23 -> V_176 = V_177 ;
V_30 -> V_23 -> V_178 = V_179 ;
V_30 -> V_23 -> V_180 = 254 ;
V_30 -> V_23 -> V_106 |= V_181 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_187 ) )
V_30 -> V_23 -> V_106 |= V_188 ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_189 ) )
V_30 -> V_23 -> V_106 |= V_190 ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_191 ) )
V_30 -> V_23 -> V_106 |=
V_192 ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_193 ) )
V_30 -> V_23 -> V_106 |= V_194 ;
V_2 -> V_195 = V_196 ;
#ifdef F_47
if ( F_2 ( V_2 ) &&
F_48 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_197 . V_95 = V_198 ;
V_30 -> V_23 -> V_197 = & V_2 -> V_197 ;
}
if ( V_2 -> V_93 -> V_199 [ V_200 ] . V_201 [ 0 ] . V_202 &&
V_2 -> V_7 -> V_203 -> V_204 &&
V_2 -> V_7 -> V_203 -> V_205 &&
F_48 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_197 . V_95 |= V_206 |
V_207 |
V_208 |
V_209 |
V_210 ;
if ( ! V_97 . V_98 )
V_2 -> V_197 . V_95 |= V_211 |
V_212 |
V_213 ;
V_2 -> V_197 . V_214 = V_215 ;
V_2 -> V_197 . V_216 = V_217 ;
V_2 -> V_197 . V_218 = V_219 ;
V_2 -> V_197 . V_220 = V_173 ;
V_2 -> V_197 . V_221 = & V_222 ;
V_30 -> V_23 -> V_197 = & V_2 -> V_197 ;
}
#endif
#ifdef F_49
V_2 -> V_223 = V_224 ;
#endif
V_47 = F_50 ( V_2 ) ;
if ( V_47 )
return V_47 ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_225 ) ) {
F_51 ( V_2 , L_10 ) ;
V_30 -> V_23 -> V_95 |= V_226 ;
F_38 ( V_30 , V_227 ) ;
}
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_228 ) ) {
F_51 ( V_2 , L_11 ) ;
V_30 -> V_23 -> V_106 |= V_229 ;
}
V_30 -> V_72 |= V_2 -> V_37 -> V_106 ;
if ( ! F_52 ( V_2 ) )
V_30 -> V_72 &= ~ V_230 ;
if ( V_231 )
V_30 -> V_72 |= V_232 | V_233 |
V_234 | V_235 ;
V_47 = F_53 ( V_2 -> V_30 ) ;
if ( V_47 )
F_54 ( V_2 ) ;
return V_47 ;
}
static bool F_55 ( struct V_1 * V_2 ,
struct V_236 * V_237 ,
struct V_238 * V_239 )
{
struct V_111 * V_240 ;
bool V_241 = false ;
if ( F_56 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_57 ( & V_2 -> V_242 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_34;
V_240 = F_58 ( V_237 ) ;
if ( V_240 -> V_243 == V_244 ||
V_240 -> V_243 != V_2 -> V_245 )
goto V_34;
F_59 ( & V_2 -> V_246 , V_239 ) ;
F_60 ( V_2 -> V_30 ) ;
F_1 ( V_2 , V_247 ) ;
F_7 ( V_2 , V_247 ) ;
V_241 = true ;
V_34:
F_61 ( & V_2 -> V_242 ) ;
return V_241 ;
}
static void F_62 ( struct V_29 * V_30 ,
struct V_248 * V_249 ,
struct V_238 * V_239 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_236 * V_237 = V_249 -> V_237 ;
struct V_250 * V_251 = F_63 ( V_239 ) ;
struct V_252 * V_253 = ( void * ) V_239 -> V_254 ;
if ( F_64 ( V_2 ) ) {
F_65 ( V_2 , L_12 ) ;
goto V_255;
}
if ( F_63 ( V_239 ) -> V_256 == V_78 &&
! F_14 ( V_257 , & V_2 -> V_15 ) &&
! F_14 ( V_258 , & V_2 -> V_15 ) )
goto V_255;
if ( F_66 ( V_251 -> V_95 & V_259 &&
F_67 ( V_253 -> V_260 ) &&
! F_68 ( V_253 -> V_260 ) &&
! F_69 ( V_253 -> V_260 ) &&
! F_70 ( V_253 -> V_260 ) ) )
V_237 = NULL ;
if ( V_237 ) {
if ( F_55 ( V_2 , V_237 , V_239 ) )
return;
if ( F_71 ( V_2 , V_239 , V_237 ) )
goto V_255;
return;
}
if ( F_72 ( V_2 , V_239 ) )
goto V_255;
return;
V_255:
F_73 ( V_30 , V_239 ) ;
}
static inline bool F_74 ( const struct V_261 * V_37 )
{
if ( V_97 . V_262 & V_263 )
return false ;
return true ;
}
static inline bool F_75 ( const struct V_261 * V_37 )
{
if ( V_97 . V_262 & V_264 )
return false ;
if ( V_97 . V_262 & V_265 )
return true ;
return true ;
}
static void
F_76 ( struct V_1 * V_2 , struct V_266 * V_267 ,
struct V_236 * V_237 , V_115 V_268 , V_115 V_269 ,
enum V_270 V_271 )
{
struct V_272 * V_273 ;
struct V_274 * V_275 ;
if ( ! F_77 ( V_2 -> V_93 , V_276 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_276 ) ;
V_275 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
switch ( V_271 ) {
case V_277 : {
struct V_111 * V_240 = F_58 ( V_237 ) ;
struct V_278 * V_279 = & V_240 -> V_279 [ V_268 ] ;
F_80 ( V_2 , V_273 , V_275 -> V_280 , V_268 ,
L_13 ,
V_237 -> V_140 , V_268 , V_279 -> V_281 ) ;
break;
}
case V_282 :
F_80 ( V_2 , V_273 , V_275 -> V_283 , V_268 ,
L_14 ,
V_237 -> V_140 , V_268 ) ;
break;
case V_284 :
F_80 ( V_2 , V_273 , V_275 -> V_285 , V_268 ,
L_15 ,
V_237 -> V_140 , V_268 , V_269 ) ;
break;
case V_286 :
F_80 ( V_2 , V_273 , V_275 -> V_287 , V_268 ,
L_16 ,
V_237 -> V_140 , V_268 ) ;
break;
default:
break;
}
}
static int F_81 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
enum V_270 V_271 ,
struct V_236 * V_237 , V_115 V_268 ,
V_115 * V_281 , T_2 V_288 , bool V_289 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_290 = false ;
F_82 ( V_2 , L_17 ,
V_237 -> V_140 , V_268 , V_271 ) ;
if ( ! ( V_2 -> V_141 -> V_291 ) )
return - V_292 ;
switch ( V_271 ) {
case V_293 :
case V_282 :
case V_294 :
case V_295 :
case V_277 :
V_47 = F_12 ( V_2 , V_296 ) ;
if ( V_47 )
return V_47 ;
V_290 = true ;
break;
default:
break;
}
F_83 ( & V_2 -> V_33 ) ;
switch ( V_271 ) {
case V_284 :
if ( ! F_74 ( V_2 -> V_37 ) ) {
V_47 = - V_297 ;
break;
}
V_47 = F_84 ( V_2 , V_237 , V_268 , * V_281 , true ) ;
break;
case V_286 :
V_47 = F_84 ( V_2 , V_237 , V_268 , 0 , false ) ;
break;
case V_293 :
if ( ! F_75 ( V_2 -> V_37 ) ) {
V_47 = - V_297 ;
break;
}
V_47 = F_85 ( V_2 , V_267 , V_237 , V_268 , V_281 ) ;
break;
case V_282 :
V_47 = F_86 ( V_2 , V_267 , V_237 , V_268 ) ;
break;
case V_294 :
case V_295 :
V_47 = F_87 ( V_2 , V_267 , V_237 , V_268 ) ;
break;
case V_277 :
V_47 = F_88 ( V_2 , V_267 , V_237 , V_268 , V_288 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_297 ;
break;
}
if ( ! V_47 ) {
V_115 V_269 = 0 ;
if ( V_271 == V_284 )
V_269 = * V_281 ;
F_76 ( V_2 , V_267 , V_237 , V_268 ,
V_269 , V_271 ) ;
}
F_89 ( & V_2 -> V_33 ) ;
if ( V_290 )
F_7 ( V_2 , V_296 ) ;
return V_47 ;
}
static void F_90 ( void * V_254 , T_2 * V_298 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = V_254 ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
V_299 -> V_300 = false ;
V_299 -> V_301 = V_244 ;
F_4 ( & V_2 -> V_302 ) ;
F_92 ( V_2 , & V_299 -> V_303 ) ;
F_5 ( & V_2 -> V_302 ) ;
V_299 -> V_304 = NULL ;
memset ( & V_299 -> V_305 , 0 , sizeof( V_299 -> V_305 ) ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
if ( ! F_94 ( V_306 , & V_2 -> V_15 ) ) {
V_2 -> V_307 = & V_308 ;
F_95 ( V_2 ) ;
}
F_10 ( V_2 , V_309 ) ;
F_96 ( V_2 -> V_7 ) ;
V_2 -> V_310 = 0 ;
V_2 -> V_311 = false ;
V_2 -> V_312 = false ;
F_97 ( V_2 ) ;
F_98 ( V_2 -> V_30 ) ;
F_99 ( V_2 -> V_30 , 0 , F_90 , V_2 ) ;
V_2 -> V_313 = NULL ;
V_2 -> V_245 = V_244 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_314 , 0 , sizeof( V_2 -> V_314 ) ) ;
memset ( V_2 -> V_315 , 0 , sizeof( V_2 -> V_315 ) ) ;
memset ( V_2 -> V_316 , 0 , sizeof( V_2 -> V_316 ) ) ;
memset ( & V_2 -> V_317 , 0 , sizeof( V_2 -> V_317 ) ) ;
memset ( & V_2 -> V_318 , 0 , sizeof( V_2 -> V_318 ) ) ;
memset ( & V_2 -> V_319 , 0 , sizeof( V_2 -> V_319 ) ) ;
memset ( & V_2 -> V_320 , 0 , sizeof( V_2 -> V_320 ) ) ;
memset ( & V_2 -> V_321 , 0 , sizeof( V_2 -> V_321 ) ) ;
memset ( & V_2 -> V_322 , 0 , sizeof( V_2 -> V_322 ) ) ;
F_100 ( V_2 -> V_30 ) ;
F_101 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_323 = 0 ;
V_2 -> V_324 = 0 ;
V_2 -> V_325 = V_326 ;
F_102 ( V_2 ) ;
}
int F_103 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_327 , & V_2 -> V_15 ) ) {
F_93 ( V_2 ) ;
} else {
F_1 ( V_2 , V_309 ) ;
}
V_47 = F_104 ( V_2 ) ;
if ( V_47 && F_14 ( V_327 , & V_2 -> V_15 ) ) {
F_101 ( V_327 , & V_2 -> V_15 ) ;
F_105 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_106 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_327 , & V_2 -> V_15 ) ) {
F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ;
}
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_103 ( V_2 ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_107 ( struct V_1 * V_2 )
{
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
F_101 ( V_327 , & V_2 -> V_15 ) ;
F_105 ( V_2 , NULL ) ;
V_47 = F_108 ( V_2 , true , NULL ) ;
if ( V_47 )
F_109 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_309 ) ;
F_110 ( V_2 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) &&
F_112 ( V_2 ) )
F_113 ( ! F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ,
L_19 ) ;
}
static void
F_114 ( struct V_29 * V_30 ,
enum V_328 V_329 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_329 ) {
case V_330 :
F_107 ( V_2 ) ;
break;
case V_331 :
F_111 ( V_2 ) ;
break;
}
}
void F_115 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_332 , 0 , sizeof( V_2 -> V_332 ) ) ;
F_116 ( & V_2 -> V_333 ) ;
F_96 ( V_2 -> V_7 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
if ( F_94 ( V_327 , & V_2 -> V_15 ) )
F_99 ( V_2 -> V_30 , 0 ,
F_90 , V_2 ) ;
if ( F_45 ( & V_2 -> V_93 -> V_94 , V_154 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_155 ; V_9 ++ ) {
if ( F_113 ( V_2 -> V_334 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_334 [ V_9 ] = 0 ;
}
}
V_2 -> V_335 = false ;
}
static void F_119 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_116 ( & V_2 -> V_336 ) ;
F_116 ( & V_2 -> V_337 ) ;
F_120 ( & V_2 -> V_338 ) ;
F_121 ( V_2 ) ;
F_83 ( & V_2 -> V_33 ) ;
F_115 ( V_2 ) ;
F_89 ( & V_2 -> V_33 ) ;
F_122 ( & V_2 -> V_337 ) ;
}
static struct V_339 * F_123 ( struct V_1 * V_2 )
{
V_115 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_109 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_124 ( struct V_1 * V_2 , struct V_266 * V_267 ,
T_3 V_340 )
{
struct V_341 V_342 = {
. V_343 . V_344 = F_125 ( V_345 ) ,
. V_343 . V_346 =
F_125 ( F_91 ( V_267 ) -> V_20 ) ,
. V_343 . V_347 = F_126 ( 8 * V_340 ) ,
} ;
int V_202 = sizeof( V_342 ) ;
if ( V_340 == V_348 )
V_342 . V_343 . V_347 = F_126 ( V_349 ) ;
if ( ! F_46 ( & V_2 -> V_93 -> V_94 , V_350 ) )
V_202 = sizeof( V_342 . V_343 ) ;
return F_127 ( V_2 , V_351 , 0 , V_202 , & V_342 ) ;
}
static int F_128 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
int V_47 ;
V_299 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_352 ) ;
if ( V_47 )
return V_47 ;
F_83 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_327 , & V_2 -> V_15 ) )
V_299 -> V_353 . V_354 +=
V_299 -> V_353 . V_355 ;
V_47 = F_129 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_356;
if ( V_267 -> type != V_121 )
V_2 -> V_323 ++ ;
if ( V_267 -> type == V_119 ||
V_267 -> type == V_122 ) {
V_47 = F_130 ( V_2 , V_267 ) ;
if ( V_47 ) {
F_109 ( V_2 , L_22 ) ;
goto V_357;
}
F_131 ( V_2 , V_267 ) ;
goto V_356;
}
V_299 -> V_106 |= V_30 -> V_72 ;
V_47 = F_132 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_357;
V_47 = F_133 ( V_2 ) ;
if ( V_47 )
goto V_358;
V_47 = F_134 ( V_2 , V_267 , 0 ) ;
if ( V_47 )
goto V_358;
if ( ! V_2 -> V_359 &&
V_267 -> type == V_117 && ! V_267 -> V_360 ) {
V_2 -> V_359 = V_299 ;
V_267 -> V_361 |= V_362 |
V_363 ;
}
if ( V_267 -> type == V_121 ) {
V_299 -> V_304 = F_123 ( V_2 ) ;
if ( ! V_299 -> V_304 ) {
V_47 = - V_364 ;
goto V_365;
}
F_135 ( V_2 , V_299 -> V_304 ) ;
V_47 = F_136 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_366;
V_47 = F_137 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_367;
V_2 -> V_313 = V_267 ;
}
F_131 ( V_2 , V_267 ) ;
goto V_356;
V_367:
F_138 ( V_2 , V_267 ) ;
V_366:
F_139 ( V_2 , V_299 -> V_304 ) ;
V_365:
if ( V_2 -> V_359 == V_299 ) {
V_2 -> V_359 = NULL ;
V_267 -> V_361 &= ~ ( V_362 |
V_363 ) ;
}
V_358:
V_299 -> V_304 = NULL ;
F_140 ( V_2 , V_267 ) ;
V_357:
if ( V_267 -> type != V_121 )
V_2 -> V_323 -- ;
F_141 ( V_2 , V_267 ) ;
V_356:
F_89 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_352 ) ;
return V_47 ;
}
static void F_142 ( struct V_1 * V_2 ,
struct V_266 * V_267 )
{
T_1 V_368 = F_143 ( V_267 ) ;
if ( V_368 ) {
F_83 ( & V_2 -> V_33 ) ;
F_144 ( V_2 , V_368 , 0 ) ;
F_89 ( & V_2 -> V_33 ) ;
F_145 ( V_2 -> V_7 , V_368 ) ;
}
if ( V_267 -> type == V_121 ) {
F_116 ( & V_2 -> V_333 ) ;
} else {
F_116 ( & V_2 -> V_369 ) ;
}
}
static void F_146 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
F_142 ( V_2 , V_267 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_359 == V_299 ) {
V_2 -> V_359 = NULL ;
V_267 -> V_361 &= ~ ( V_362 |
V_363 ) ;
}
F_147 ( V_2 , V_267 ) ;
if ( V_267 -> type == V_119 ||
V_267 -> type == V_122 ) {
#ifdef F_148
if ( V_267 == V_2 -> V_370 ) {
V_2 -> V_370 = NULL ;
V_2 -> V_371 = 0 ;
}
#endif
F_149 ( V_2 , V_267 ) ;
goto V_357;
}
if ( V_267 -> type == V_121 ) {
V_2 -> V_313 = NULL ;
F_150 ( V_2 , V_267 ) ;
F_138 ( V_2 , V_267 ) ;
F_139 ( V_2 , V_299 -> V_304 ) ;
V_299 -> V_304 = NULL ;
}
if ( V_2 -> V_323 && V_267 -> type != V_121 )
V_2 -> V_323 -- ;
F_133 ( V_2 ) ;
F_140 ( V_2 , V_267 ) ;
V_357:
F_141 ( V_2 , V_267 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static int F_151 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_152 ( void * V_372 , T_2 * V_298 ,
struct V_266 * V_267 )
{
struct V_373 * V_254 = V_372 ;
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_374 * V_342 = V_2 -> V_375 ;
int V_47 , V_202 ;
if ( F_15 ( V_254 -> V_376 >= V_377 ) )
return;
if ( V_267 -> type != V_117 ||
! V_267 -> V_378 . V_379 )
return;
V_342 -> V_376 = V_254 -> V_376 ++ ;
memcpy ( V_342 -> V_380 , V_267 -> V_378 . V_380 , V_143 ) ;
V_202 = F_153 ( sizeof( * V_342 ) + V_342 -> V_381 * V_143 , 4 ) ;
V_47 = F_127 ( V_2 , V_382 , V_383 , V_202 , V_342 ) ;
if ( V_47 )
F_109 ( V_2 , L_23 , V_47 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_373 V_384 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_375 ) )
return;
F_155 (
V_2 -> V_30 , V_385 ,
F_152 , & V_384 ) ;
}
static T_4 F_156 ( struct V_29 * V_30 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_374 * V_342 ;
struct V_388 * V_140 ;
int V_389 ;
bool V_390 ;
int V_202 ;
V_389 = F_157 ( V_387 ) ;
V_390 = V_389 > V_391 ||
V_392 ;
if ( V_390 )
V_389 = 0 ;
V_202 = F_153 ( sizeof( * V_342 ) + V_389 * V_143 , 4 ) ;
V_342 = F_158 ( V_202 , V_393 ) ;
if ( ! V_342 )
return 0 ;
if ( V_390 ) {
V_342 -> V_390 = 1 ;
return ( T_4 ) ( unsigned long ) V_342 ;
}
F_159 (addr, mc_list) {
F_160 ( V_2 , L_24 ,
V_342 -> V_381 , V_140 -> V_140 ) ;
memcpy ( & V_342 -> V_394 [ V_342 -> V_381 * V_143 ] ,
V_140 -> V_140 , V_143 ) ;
V_342 -> V_381 ++ ;
}
return ( T_4 ) ( unsigned long ) V_342 ;
}
static void F_161 ( struct V_29 * V_30 ,
unsigned int V_395 ,
unsigned int * V_396 ,
T_4 V_397 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_374 * V_342 = ( void * ) ( unsigned long ) V_397 ;
F_83 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_375 ) ;
V_2 -> V_375 = V_342 ;
if ( ! V_342 )
goto V_34;
F_154 ( V_2 ) ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
* V_396 = 0 ;
}
static void F_162 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
unsigned int V_398 ,
unsigned int V_395 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_395 & V_399 ) )
return;
if ( V_267 -> type != V_117 || ! V_267 -> V_378 . V_379 ||
! V_267 -> V_360 )
return;
F_83 ( & V_2 -> V_33 ) ;
F_163 ( V_2 , V_267 , false , NULL ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void
F_164 ( struct V_266 * V_267 ,
const struct V_400 * V_401 ,
struct V_400 * V_402 )
{
struct V_403 * V_404 ;
int V_9 ;
memcpy ( V_402 , V_401 , sizeof( * V_402 ) ) ;
for ( V_9 = 0 ; V_9 < F_40 ( V_402 -> V_405 ) ; V_9 ++ ) {
V_404 = & V_402 -> V_405 [ V_9 ] ;
if ( ! V_404 -> V_406 )
break;
switch ( V_404 -> V_407 ) {
case F_126 ( V_408 ) :
if ( V_267 -> V_378 . V_409 != 1 ) {
V_404 -> V_406 = 0 ;
continue;
}
V_404 -> V_410 = V_267 -> V_378 . V_411 [ 0 ] ;
break;
case F_126 ( V_412 ) :
V_404 -> V_410 = * ( V_413 * ) & V_267 -> V_140 [ 2 ] ;
break;
default:
break;
}
V_404 -> V_407 = 0 ;
V_402 -> V_414 ++ ;
}
}
static void F_165 ( void * V_372 , T_2 * V_298 ,
struct V_266 * V_267 )
{
struct V_415 * V_254 = V_372 ;
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_416 * V_342 = V_254 -> V_342 ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
struct V_417 * V_418 ;
int V_9 ;
if ( F_8 ( V_299 -> V_20 >= F_40 ( V_342 -> V_419 ) ) )
return;
V_418 = & V_342 -> V_419 [ V_299 -> V_20 ] ;
if ( V_267 -> type != V_117 || V_267 -> V_360 ||
! V_267 -> V_378 . V_379 )
return;
V_418 -> V_420 = 1 ;
for ( V_9 = 0 ; V_2 -> V_223 [ V_9 ] . V_405 [ 0 ] . V_406 ; V_9 ++ ) {
if ( F_15 ( V_254 -> V_421 >=
F_40 ( V_342 -> V_422 ) ) ) {
V_418 -> V_420 = 0 ;
V_418 -> V_423 = 0 ;
break;
}
F_164 ( V_267 ,
& V_2 -> V_223 [ V_9 ] ,
& V_342 -> V_422 [ V_254 -> V_421 ] ) ;
if ( ! V_342 -> V_422 [ V_254 -> V_421 ] . V_414 )
continue;
V_418 -> V_423 |=
F_126 ( F_41 ( V_254 -> V_421 ) ) ;
V_254 -> V_421 ++ ;
}
}
bool F_166 ( struct V_1 * V_2 ,
struct V_416 * V_342 )
{
struct V_415 V_384 = {
. V_2 = V_2 ,
. V_342 = V_342 ,
} ;
if ( V_424 )
return false ;
memset ( V_342 , 0 , sizeof( * V_342 ) ) ;
V_342 -> V_425 = F_40 ( V_342 -> V_422 ) ;
V_342 -> V_426 = F_40 ( V_342 -> V_419 ) ;
#ifdef F_167
if ( V_2 -> V_427 . V_428 ) {
memcpy ( V_342 -> V_422 , & V_2 -> V_427 . V_342 . V_422 ,
sizeof( V_342 -> V_422 ) ) ;
memcpy ( V_342 -> V_419 , & V_2 -> V_427 . V_342 . V_419 ,
sizeof( V_342 -> V_419 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_223 )
return false ;
F_168 (
V_2 -> V_30 , V_385 ,
F_165 , & V_384 ) ;
return true ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_416 V_342 ;
if ( ! ( V_2 -> V_93 -> V_94 . V_95 & V_429 ) )
return 0 ;
if ( ! F_166 ( V_2 , & V_342 ) )
return 0 ;
return F_127 ( V_2 , V_430 , 0 ,
sizeof( V_342 ) , & V_342 ) ;
}
static inline int F_169 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_170 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
struct V_431 * V_378 ,
T_1 V_432 )
{
struct V_113 * V_299 = F_91 ( V_267 ) ;
int V_47 ;
if ( V_432 & V_433 && V_378 -> V_379 )
F_171 ( V_2 , V_267 ) ;
if ( V_432 & V_434 && ! V_299 -> V_435 )
memcpy ( V_299 -> V_380 , V_378 -> V_380 , V_143 ) ;
V_47 = F_163 ( V_2 , V_267 , false , V_299 -> V_380 ) ;
if ( V_47 )
F_109 ( V_2 , L_25 , V_267 -> V_140 ) ;
memcpy ( V_299 -> V_380 , V_378 -> V_380 , V_143 ) ;
V_299 -> V_435 = V_378 -> V_379 ;
if ( V_432 & V_433 ) {
if ( V_378 -> V_379 ) {
F_172 ( V_2 , true ) ;
memset ( & V_299 -> V_353 , 0 ,
sizeof( V_299 -> V_353 ) ) ;
V_47 = F_108 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_109 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_327 ,
& V_2 -> V_15 ) ) {
T_1 V_436 = ( 11 * V_267 -> V_378 . V_437 ) / 10 ;
F_173 ( V_2 , V_267 , V_436 , V_436 ,
5 * V_436 , false ) ;
}
F_174 ( V_2 , V_267 , false ) ;
F_175 ( V_2 , V_267 ) ;
if ( V_267 -> V_360 ) {
F_1 ( V_2 , V_438 ) ;
F_176 ( V_2 , V_267 ,
V_439 ,
V_440 ) ;
}
} else if ( V_299 -> V_301 != V_244 ) {
F_113 ( F_174 ( V_2 , V_267 , false ) ,
L_27 ) ;
V_47 = F_177 ( V_2 , V_267 , V_299 -> V_301 ) ;
if ( V_47 )
F_109 ( V_2 , L_28 ) ;
if ( V_2 -> V_245 == V_299 -> V_301 )
V_2 -> V_245 = V_244 ;
V_299 -> V_301 = V_244 ;
V_47 = F_108 ( V_2 , false , NULL ) ;
if ( V_47 )
F_109 ( V_2 , L_26 ) ;
if ( V_267 -> V_360 )
F_7 ( V_2 , V_438 ) ;
V_47 = F_163 ( V_2 , V_267 , false , NULL ) ;
if ( V_47 )
F_109 ( V_2 ,
L_29 ,
V_267 -> V_140 ) ;
}
F_154 ( V_2 ) ;
F_169 ( V_2 ) ;
V_299 -> V_305 . V_441 = 0 ;
F_178 ( V_2 ) ;
F_176 ( V_2 , V_267 , V_442 ,
V_443 ) ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_154 ) )
F_179 ( V_2 ) ;
} else if ( V_432 & V_444 ) {
F_180 ( V_2 , V_299 ,
& V_299 -> V_303 ) ;
}
if ( V_432 & V_444 ) {
F_174 ( V_2 , V_267 , false ) ;
F_8 ( F_181 ( V_2 , V_267 , 0 ) ) ;
}
if ( V_432 & ( V_445 | V_446 | V_447 ) ) {
V_47 = F_133 ( V_2 ) ;
if ( V_47 )
F_109 ( V_2 , L_30 ) ;
}
if ( V_432 & V_448 ) {
F_182 ( V_2 , L_31 ,
V_378 -> V_449 ) ;
F_124 ( V_2 , V_267 , V_378 -> V_449 ) ;
}
if ( V_432 & V_450 ) {
F_160 ( V_2 , L_32 ) ;
V_299 -> V_305 . V_451 = 0 ;
if ( V_299 -> V_305 . V_452 ) {
V_47 = F_181 ( V_2 , V_267 , 0 ) ;
if ( V_47 )
F_109 ( V_2 ,
L_33 ) ;
}
}
if ( V_432 & V_453 ) {
F_160 ( V_2 , L_34 ) ;
F_169 ( V_2 ) ;
}
}
static int F_183 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_454 ) ;
if ( V_47 )
return V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_184 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_356;
if ( V_267 -> type == V_119 )
F_171 ( V_2 , V_267 ) ;
V_299 -> V_455 = 0 ;
V_47 = F_132 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_356;
V_47 = F_136 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_456;
V_47 = F_185 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_367;
V_299 -> V_457 = true ;
F_133 ( V_2 ) ;
V_47 = F_108 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_458;
if ( V_267 -> V_360 && V_2 -> V_313 )
F_163 ( V_2 , V_2 -> V_313 , false , NULL ) ;
F_1 ( V_2 , V_459 ) ;
F_178 ( V_2 ) ;
if ( F_186 ( V_2 ) > 1 )
F_110 ( V_2 ) ;
goto V_356;
V_458:
F_133 ( V_2 ) ;
V_299 -> V_457 = false ;
F_187 ( V_2 , V_267 ) ;
V_367:
F_138 ( V_2 , V_267 ) ;
V_456:
F_140 ( V_2 , V_267 ) ;
V_356:
F_89 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_454 ) ;
return V_47 ;
}
static void F_188 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
F_142 ( V_2 , V_267 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( F_189 ( V_2 -> V_460 ) == V_267 ) {
F_180 ( V_2 , V_299 ,
& V_299 -> V_303 ) ;
F_190 ( V_2 -> V_460 , NULL ) ;
V_299 -> V_461 = false ;
}
if ( F_189 ( V_2 -> V_462 ) == V_267 ) {
F_190 ( V_2 -> V_462 , NULL ) ;
V_2 -> V_463 = 0 ;
}
V_299 -> V_457 = false ;
V_2 -> V_464 = 0 ;
F_178 ( V_2 ) ;
F_7 ( V_2 , V_459 ) ;
if ( V_267 -> V_360 && V_2 -> V_313 )
F_163 ( V_2 , V_2 -> V_313 , false , NULL ) ;
F_108 ( V_2 , false , NULL ) ;
F_187 ( V_2 , V_267 ) ;
F_138 ( V_2 , V_267 ) ;
F_133 ( V_2 ) ;
F_140 ( V_2 , V_267 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void
F_191 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
struct V_431 * V_378 ,
T_1 V_432 )
{
struct V_113 * V_299 = F_91 ( V_267 ) ;
if ( ! V_299 -> V_457 )
return;
if ( V_432 & ( V_465 | V_466 |
V_467 | V_447 ) &&
F_163 ( V_2 , V_267 , false , NULL ) )
F_109 ( V_2 , L_25 , V_267 -> V_140 ) ;
if ( V_432 & V_468 &&
F_184 ( V_2 , V_267 ) )
F_192 ( V_2 , L_35 ) ;
if ( V_432 & V_448 ) {
F_182 ( V_2 , L_31 ,
V_378 -> V_449 ) ;
F_124 ( V_2 , V_267 , V_378 -> V_449 ) ;
}
}
static void F_193 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_431 * V_378 ,
T_1 V_432 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_469 ) )
return;
F_83 ( & V_2 -> V_33 ) ;
if ( V_432 & V_470 && ! V_378 -> V_471 )
F_194 ( V_2 , V_472 , true ) ;
switch ( V_267 -> type ) {
case V_117 :
F_170 ( V_2 , V_267 , V_378 , V_432 ) ;
break;
case V_119 :
case V_122 :
F_191 ( V_2 , V_267 , V_378 , V_432 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_89 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_469 ) ;
}
static int F_195 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_473 * V_474 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_474 -> V_475 . V_38 == 0 ||
V_474 -> V_475 . V_38 > V_2 -> V_93 -> V_94 . V_476 )
return - V_297 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_196 ( V_2 , V_267 , & V_474 -> V_475 , & V_474 -> V_477 ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_197 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_310 & V_478 )
F_194 ( V_2 , V_478 , true ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void
F_198 ( struct V_29 * V_30 ,
struct V_236 * V_237 , V_115 V_479 ,
int V_480 ,
enum V_481 V_482 ,
bool V_483 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_199 ( V_2 , V_237 , V_482 , V_480 ,
V_479 , V_483 , false ) ;
}
static void
F_200 ( struct V_29 * V_30 ,
struct V_236 * V_237 , V_115 V_479 ,
int V_480 ,
enum V_481 V_482 ,
bool V_483 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_199 ( V_2 , V_237 , V_482 , V_480 ,
V_479 , V_483 , true ) ;
}
static void F_201 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
enum V_484 V_342 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_111 * V_240 = F_58 ( V_237 ) ;
unsigned long V_485 = 0 , V_479 = 0 ;
int V_268 ;
F_4 ( & V_240 -> V_486 ) ;
for ( V_268 = 0 ; V_268 < V_487 ; V_268 ++ ) {
struct V_278 * V_279 = & V_240 -> V_279 [ V_268 ] ;
if ( V_279 -> V_488 != V_489 &&
V_279 -> V_488 != V_490 )
continue;
F_202 ( V_279 -> V_491 , & V_485 ) ;
if ( F_203 ( V_279 ) == 0 )
continue;
F_202 ( V_268 , & V_479 ) ;
}
switch ( V_342 ) {
case V_492 :
if ( F_204 ( & V_2 -> V_493 [ V_240 -> V_243 ] ) > 0 )
F_205 ( V_30 , V_237 , true ) ;
F_206 (tid, &tids, IWL_MAX_TID_COUNT)
F_207 ( V_237 , V_268 , true ) ;
if ( V_485 )
F_208 ( V_2 -> V_7 , V_485 , true ) ;
break;
case V_494 :
if ( F_8 ( V_240 -> V_243 == V_244 ) )
break;
if ( V_485 )
F_208 ( V_2 -> V_7 , V_485 , false ) ;
F_209 ( V_2 , V_237 ) ;
break;
default:
break;
}
F_5 ( & V_240 -> V_486 ) ;
}
static void F_210 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_111 * V_495 = F_58 ( V_237 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_237 == F_189 ( V_2 -> V_496 [ V_495 -> V_243 ] ) )
F_211 ( V_2 -> V_496 [ V_495 -> V_243 ] ,
F_212 ( - V_49 ) ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void F_213 ( struct V_1 * V_2 , struct V_266 * V_267 ,
const T_2 * V_380 )
{
if ( ! ( V_2 -> V_93 -> V_94 . V_95 & V_497 ) )
return;
if ( V_97 . V_498 ) {
V_267 -> V_361 &= ~ V_499 ;
return;
}
V_267 -> V_361 |= V_499 ;
}
static void
F_214 ( struct V_1 * V_2 ,
struct V_266 * V_267 , T_2 * V_500 ,
enum V_501 V_271 )
{
struct V_272 * V_273 ;
struct V_502 * V_503 ;
if ( ! F_77 ( V_2 -> V_93 , V_504 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_504 ) ;
V_503 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
if ( ! ( V_503 -> V_505 & F_41 ( V_271 ) ) )
return;
if ( V_503 -> V_506 &&
memcmp ( V_503 -> V_507 , V_500 , V_143 ) != 0 )
return;
F_215 ( V_2 , V_273 ,
L_36 ,
V_500 , V_271 ) ;
}
static int F_216 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_236 * V_237 ,
enum V_508 V_509 ,
enum V_508 V_510 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
int V_47 ;
F_160 ( V_2 , L_37 ,
V_237 -> V_140 , V_509 , V_510 ) ;
if ( F_15 ( ! V_299 -> V_304 ) )
return - V_297 ;
F_116 ( & V_2 -> V_369 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_509 == V_511 &&
V_510 == V_512 ) {
if ( V_267 -> type == V_117 &&
V_267 -> V_378 . V_437 < 16 ) {
F_109 ( V_2 ,
L_38 ,
V_237 -> V_140 , V_267 -> V_378 . V_437 ) ;
V_47 = - V_297 ;
goto V_356;
}
if ( V_237 -> V_513 &&
( V_267 -> V_360 ||
F_217 ( V_2 , NULL ) ==
V_514 ||
F_186 ( V_2 ) > 1 ) ) {
F_160 ( V_2 , L_39 ) ;
V_47 = - V_515 ;
goto V_356;
}
V_47 = F_218 ( V_2 , V_267 , V_237 ) ;
if ( V_237 -> V_513 && V_47 == 0 ) {
F_219 ( V_2 , V_267 , true ) ;
F_214 ( V_2 , V_267 , V_237 -> V_140 ,
V_516 ) ;
}
} else if ( V_509 == V_512 &&
V_510 == V_517 ) {
V_2 -> V_518 = true ;
F_213 ( V_2 , V_267 , V_237 -> V_140 ) ;
V_47 = 0 ;
} else if ( V_509 == V_517 &&
V_510 == V_519 ) {
if ( V_267 -> type == V_119 ) {
V_299 -> V_455 ++ ;
F_163 ( V_2 , V_267 , false , NULL ) ;
}
V_47 = F_220 ( V_2 , V_267 , V_237 ) ;
if ( V_47 == 0 )
F_221 ( V_2 , V_237 ,
V_299 -> V_304 -> V_520 -> V_521 ,
true ) ;
} else if ( V_509 == V_519 &&
V_510 == V_522 ) {
if ( F_186 ( V_2 ) > 1 )
F_110 ( V_2 ) ;
if ( V_237 -> V_513 )
F_214 ( V_2 , V_267 , V_237 -> V_140 ,
V_523 ) ;
F_8 ( F_181 ( V_2 , V_267 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_509 == V_522 &&
V_510 == V_519 ) {
F_8 ( F_134 ( V_2 , V_267 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_509 == V_519 &&
V_510 == V_517 ) {
if ( V_267 -> type == V_119 ) {
V_299 -> V_455 -- ;
F_163 ( V_2 , V_267 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_509 == V_517 &&
V_510 == V_512 ) {
V_47 = 0 ;
} else if ( V_509 == V_512 &&
V_510 == V_511 ) {
V_47 = F_222 ( V_2 , V_267 , V_237 ) ;
if ( V_237 -> V_513 ) {
F_219 ( V_2 , V_267 , false ) ;
F_214 ( V_2 , V_267 , V_237 -> V_140 ,
V_524 ) ;
}
} else {
V_47 = - V_17 ;
}
V_356:
F_89 ( & V_2 -> V_33 ) ;
if ( V_237 -> V_513 && V_47 == 0 ) {
if ( V_509 == V_511 &&
V_510 == V_512 )
F_223 ( V_237 , V_525 ) ;
else if ( V_509 == V_512 &&
V_510 == V_511 )
F_224 ( V_237 , V_525 ) ;
}
return V_47 ;
}
static int F_225 ( struct V_29 * V_30 , T_1 V_526 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_195 = V_526 ;
return 0 ;
}
static void F_226 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_236 * V_237 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_267 -> type == V_117 &&
V_27 & V_527 )
F_174 ( V_2 , V_267 , false ) ;
}
static int F_227 ( struct V_29 * V_30 ,
struct V_266 * V_267 , V_115 V_528 ,
const struct V_529 * V_530 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
V_299 -> V_531 [ V_528 ] = * V_530 ;
if ( V_267 -> type == V_121 ) {
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_163 ( V_2 , V_267 , false , NULL ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_228 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_532 = F_42 ( V_533 ,
200 + V_267 -> V_378 . V_437 ) ;
T_1 V_534 = F_42 ( V_535 ,
100 + V_267 -> V_378 . V_437 ) ;
if ( F_15 ( V_267 -> V_378 . V_379 ) )
return;
if ( F_12 ( V_2 , V_536 ) )
return;
F_83 ( & V_2 -> V_33 ) ;
F_173 ( V_2 , V_267 , V_532 , V_534 , 500 , false ) ;
F_89 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_536 ) ;
}
static int F_229 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_537 * V_475 ,
struct V_538 * V_477 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
if ( ! V_267 -> V_378 . V_471 ) {
V_47 = - V_515 ;
goto V_34;
}
V_47 = F_230 ( V_2 , V_267 , V_475 , V_477 , V_472 ) ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_231 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_310 & V_472 ) ) {
F_89 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_194 ( V_2 , V_472 , false ) ;
F_89 ( & V_2 -> V_33 ) ;
F_232 ( V_2 ) ;
return V_47 ;
}
static int F_233 ( struct V_29 * V_30 ,
enum V_539 V_342 ,
struct V_266 * V_267 ,
struct V_236 * V_237 ,
struct V_540 * V_541 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_111 * V_240 ;
struct V_542 * V_543 ;
int V_544 = V_541 -> V_544 ;
int V_47 ;
T_2 V_545 ;
if ( V_97 . V_98 ) {
F_160 ( V_2 , L_40 ) ;
return - V_546 ;
}
switch ( V_541 -> V_102 ) {
case V_54 :
V_541 -> V_95 |= V_547 ;
V_541 -> V_95 |= V_548 ;
break;
case V_55 :
V_541 -> V_95 |= V_549 ;
break;
case V_100 :
F_15 ( ! F_234 ( V_30 , V_99 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_267 -> type != V_117 )
return 0 ;
break;
default:
if ( V_30 -> V_103 &&
V_30 -> V_104 -> V_102 == V_541 -> V_102 )
V_541 -> V_95 |= V_549 ;
else
return - V_546 ;
}
F_83 ( & V_2 -> V_33 ) ;
switch ( V_342 ) {
case V_550 :
if ( ( V_267 -> type == V_122 ||
V_267 -> type == V_119 ) && ! V_237 ) {
V_47 = 0 ;
V_541 -> V_551 = V_552 ;
break;
}
if ( F_14 ( V_327 , & V_2 -> V_15 ) &&
V_541 -> V_551 == V_552 ) {
F_160 ( V_2 ,
L_41 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_327 , & V_2 -> V_15 ) &&
V_237 && F_235 ( V_2 ) &&
V_541 -> V_95 & V_553 &&
( V_541 -> V_102 == V_55 ||
V_541 -> V_102 == V_554 ) ) {
struct V_555 V_556 ;
int V_268 , V_557 ;
V_240 = F_58 ( V_237 ) ;
F_8 ( F_189 ( V_240 -> V_543 [ V_544 ] ) ) ;
V_543 = F_158 ( sizeof( * V_543 ) +
V_2 -> V_7 -> V_558 *
sizeof( V_543 -> V_557 [ 0 ] ) ,
V_559 ) ;
if ( ! V_543 ) {
V_47 = - V_560 ;
break;
}
for ( V_268 = 0 ; V_268 < V_487 ; V_268 ++ ) {
F_236 ( V_541 , V_268 , & V_556 ) ;
for ( V_557 = 0 ; V_557 < V_2 -> V_7 -> V_558 ; V_557 ++ )
memcpy ( V_543 -> V_557 [ V_557 ] . V_561 [ V_268 ] ,
V_556 . V_562 . V_561 ,
V_563 ) ;
}
F_211 ( V_240 -> V_543 [ V_544 ] , V_543 ) ;
}
if ( F_14 ( V_327 , & V_2 -> V_15 ) )
V_545 = V_541 -> V_551 ;
else
V_545 = V_552 ;
F_160 ( V_2 , L_42 ) ;
V_47 = F_237 ( V_2 , V_267 , V_237 , V_541 , V_545 ) ;
if ( V_47 ) {
F_192 ( V_2 , L_43 ) ;
V_541 -> V_551 = V_552 ;
V_47 = 0 ;
}
break;
case V_564 :
if ( V_541 -> V_551 == V_552 ) {
V_47 = 0 ;
break;
}
if ( V_237 && F_235 ( V_2 ) &&
V_541 -> V_95 & V_553 &&
( V_541 -> V_102 == V_55 ||
V_541 -> V_102 == V_554 ) ) {
V_240 = F_58 ( V_237 ) ;
V_543 = F_238 (
V_240 -> V_543 [ V_544 ] ,
F_239 ( & V_2 -> V_33 ) ) ;
F_190 ( V_240 -> V_543 [ V_544 ] , NULL ) ;
if ( V_543 )
F_240 ( V_543 , V_565 ) ;
}
F_160 ( V_2 , L_44 ) ;
V_47 = F_241 ( V_2 , V_267 , V_237 , V_541 ) ;
break;
default:
V_47 = - V_297 ;
}
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_242 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_540 * V_566 ,
struct V_236 * V_237 ,
T_1 V_567 , V_115 * V_568 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_566 -> V_551 == V_552 )
return;
F_243 ( V_2 , V_267 , V_566 , V_237 , V_567 , V_568 ) ;
}
static bool F_244 ( struct V_569 * V_570 ,
struct V_571 * V_572 , void * V_254 )
{
struct V_1 * V_2 =
F_245 ( V_570 , struct V_1 , V_570 ) ;
struct V_573 * V_32 ;
int V_574 = F_246 ( V_572 ) ;
struct V_575 * V_576 = V_254 ;
if ( F_8 ( V_572 -> V_253 . V_342 != V_577 ) )
return true ;
if ( F_15 ( V_574 != sizeof( * V_32 ) ) ) {
F_109 ( V_2 , L_45 ) ;
return true ;
}
V_32 = ( void * ) V_572 -> V_254 ;
F_247 ( V_2 ,
L_46 ,
V_32 -> V_15 , V_32 -> V_578 ) ;
V_576 -> V_579 = F_248 ( V_32 -> V_578 ) ;
F_247 ( V_2 , L_47 ,
V_576 -> V_579 ) ;
F_4 ( & V_2 -> V_302 ) ;
F_249 ( & V_576 -> V_580 , & V_2 -> V_581 ) ;
F_5 ( & V_2 -> V_302 ) ;
return true ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_582 * V_520 ,
struct V_266 * V_267 ,
int V_532 )
{
int V_583 , V_584 = V_585 ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
struct V_575 * V_576 = & V_299 -> V_586 ;
static const V_115 V_587 [] = { V_577 } ;
struct V_588 V_589 ;
T_1 V_590 = V_267 -> V_378 . V_591 *
V_267 -> V_378 . V_437 ;
T_1 V_592 , V_593 ;
struct V_594 V_595 = {
. V_271 = F_125 ( V_596 ) ,
. V_597 =
F_125 ( F_251 ( V_598 , 0 ) ) ,
. V_599 = F_125 ( V_2 -> V_600 . V_243 ) ,
. V_601 . V_521 = ( V_520 -> V_521 == V_157 ) ?
V_602 : V_603 ,
. V_601 . V_520 = V_520 -> V_604 ,
. V_601 . V_605 = V_606 ,
. V_607 = F_125 ( F_252 ( V_2 -> V_7 , V_584 ) ) ,
} ;
V_593 = V_608 ;
V_592 = F_253 ( V_532 ) ;
if ( V_267 -> V_378 . V_379 ) {
V_593 = F_254 ( T_1 , V_590 * 3 , V_609 ) ;
if ( V_590 <= V_592 ) {
V_592 = V_590 - V_610 ;
if ( V_592 <= V_611 )
V_592 = V_590 -
V_612 ;
}
}
V_595 . V_532 = F_125 ( V_592 ) ;
V_595 . V_613 = F_125 ( V_593 ) ;
F_247 ( V_2 ,
L_48 ,
V_520 -> V_604 , V_592 , V_532 , V_593 ,
V_590 ) ;
memcpy ( V_595 . V_614 , V_267 -> V_140 , V_143 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_302 ) ;
if ( F_8 ( V_576 -> V_20 == V_577 ) ) {
F_5 ( & V_2 -> V_302 ) ;
return - V_17 ;
}
V_576 -> V_267 = V_267 ;
V_576 -> V_532 = V_532 ;
V_576 -> V_20 = V_577 ;
F_5 ( & V_2 -> V_302 ) ;
F_255 ( & V_2 -> V_570 , & V_589 ,
V_587 ,
F_40 ( V_587 ) ,
F_244 , V_576 ) ;
V_583 = F_127 ( V_2 , V_577 , 0 , sizeof( V_595 ) ,
& V_595 ) ;
if ( V_583 ) {
F_109 ( V_2 , L_49 , V_583 ) ;
F_256 ( & V_2 -> V_570 , & V_589 ) ;
goto V_615;
}
V_583 = F_257 ( & V_2 -> V_570 , & V_589 , 1 ) ;
F_15 ( V_583 ) ;
if ( V_583 ) {
V_615:
F_4 ( & V_2 -> V_302 ) ;
F_92 ( V_2 , V_576 ) ;
F_5 ( & V_2 -> V_302 ) ;
}
return V_583 ;
}
static int F_258 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_582 * V_520 ,
int V_532 ,
enum V_616 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
struct V_617 V_618 ;
struct V_339 * V_304 ;
int V_47 , V_9 ;
F_160 ( V_2 , L_50 , V_520 -> V_604 ,
V_532 , type ) ;
F_116 ( & V_2 -> V_333 ) ;
F_83 ( & V_2 -> V_33 ) ;
switch ( V_267 -> type ) {
case V_117 :
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_619 ) ) {
V_47 = F_250 ( V_2 , V_520 ,
V_267 , V_532 ) ;
goto V_356;
}
F_109 ( V_2 , L_51 ) ;
V_47 = - V_297 ;
goto V_356;
case V_121 :
break;
default:
F_109 ( V_2 , L_52 , V_267 -> type ) ;
V_47 = - V_297 ;
goto V_356;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_304 = & V_2 -> V_18 [ V_9 ] ;
if ( V_304 -> V_21 == 0 || V_299 -> V_304 == V_304 )
continue;
if ( V_304 -> V_21 && V_520 == V_304 -> V_520 ) {
V_47 = F_138 ( V_2 , V_267 ) ;
if ( F_259 ( V_47 , L_53 ) )
goto V_356;
F_139 ( V_2 , V_299 -> V_304 ) ;
V_299 -> V_304 = V_304 ;
V_47 = F_136 ( V_2 , V_267 ) ;
if ( F_259 ( V_47 , L_54 ) )
goto V_356;
F_135 ( V_2 , V_299 -> V_304 ) ;
goto V_620;
}
}
if ( V_520 == V_299 -> V_304 -> V_520 )
goto V_620;
F_260 ( & V_618 , V_520 , V_621 ) ;
if ( V_299 -> V_304 -> V_21 == 1 ) {
V_47 = F_261 ( V_2 , V_299 -> V_304 ,
& V_618 , 1 , 1 ) ;
if ( V_47 )
goto V_356;
} else {
V_304 = F_123 ( V_2 ) ;
if ( ! V_304 ) {
V_47 = - V_364 ;
goto V_356;
}
V_47 = F_261 ( V_2 , V_304 , & V_618 ,
1 , 1 ) ;
if ( V_47 ) {
F_109 ( V_2 , L_55 ) ;
goto V_356;
}
V_47 = F_138 ( V_2 , V_267 ) ;
if ( F_259 ( V_47 , L_53 ) )
goto V_356;
F_139 ( V_2 , V_299 -> V_304 ) ;
V_299 -> V_304 = V_304 ;
V_47 = F_136 ( V_2 , V_267 ) ;
if ( F_259 ( V_47 , L_54 ) )
goto V_356;
F_135 ( V_2 , V_299 -> V_304 ) ;
}
V_620:
V_47 = F_262 ( V_2 , V_267 , V_532 , type ) ;
V_356:
F_89 ( & V_2 -> V_33 ) ;
F_160 ( V_2 , L_56 ) ;
return V_47 ;
}
static int F_263 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_160 ( V_2 , L_57 ) ;
F_83 ( & V_2 -> V_33 ) ;
F_264 ( V_2 ) ;
F_89 ( & V_2 -> V_33 ) ;
F_160 ( V_2 , L_56 ) ;
return 0 ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
V_115 * V_624 = ( V_115 * ) V_623 -> V_625 ;
struct V_339 * V_304 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_160 ( V_2 , L_58 ) ;
V_304 = F_123 ( V_2 ) ;
if ( ! V_304 ) {
V_47 = - V_364 ;
goto V_34;
}
V_47 = F_261 ( V_2 , V_304 , & V_623 -> V_626 ,
V_623 -> V_627 ,
V_623 -> V_628 ) ;
if ( V_47 ) {
F_109 ( V_2 , L_59 ) ;
goto V_34;
}
F_135 ( V_2 , V_304 ) ;
* V_624 = V_304 -> V_20 ;
V_34:
return V_47 ;
}
static int F_266 ( struct V_29 * V_30 ,
struct V_622 * V_623 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_265 ( V_2 , V_623 ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_267 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
V_115 * V_624 = ( V_115 * ) V_623 -> V_625 ;
struct V_339 * V_304 = & V_2 -> V_18 [ * V_624 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_139 ( V_2 , V_304 ) ;
}
static void F_268 ( struct V_29 * V_30 ,
struct V_622 * V_623 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_83 ( & V_2 -> V_33 ) ;
F_267 ( V_2 , V_623 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void F_269 ( struct V_29 * V_30 ,
struct V_622 * V_623 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_115 * V_624 = ( V_115 * ) V_623 -> V_625 ;
struct V_339 * V_304 = & V_2 -> V_18 [ * V_624 ] ;
if ( F_113 ( ( V_304 -> V_21 > 1 ) &&
( V_27 & ~ ( V_629 |
V_630 |
V_631 |
V_632 ) ) ,
L_60 ,
V_304 -> V_21 , V_27 ) )
return;
F_83 ( & V_2 -> V_33 ) ;
F_178 ( V_2 ) ;
F_261 ( V_2 , V_304 , & V_623 -> V_626 ,
V_623 -> V_627 ,
V_623 -> V_628 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
struct V_622 * V_623 ,
bool V_633 )
{
V_115 * V_624 = ( V_115 * ) V_623 -> V_625 ;
struct V_339 * V_304 = & V_2 -> V_18 [ * V_624 ] ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_299 -> V_304 = V_304 ;
switch ( V_267 -> type ) {
case V_119 :
if ( V_633 ) {
V_299 -> V_457 = true ;
break;
}
case V_122 :
V_47 = 0 ;
goto V_34;
case V_117 :
break;
case V_634 :
V_299 -> V_311 = true ;
break;
default:
V_47 = - V_297 ;
goto V_34;
}
V_47 = F_136 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_34;
F_133 ( V_2 ) ;
if ( V_267 -> type == V_634 ) {
V_299 -> V_635 = true ;
V_47 = F_108 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_636;
V_47 = F_271 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_636;
}
if ( V_267 -> type == V_119 ) {
F_108 ( V_2 , false , NULL ) ;
F_163 ( V_2 , V_267 , false , NULL ) ;
}
if ( V_633 && V_267 -> type == V_117 ) {
T_1 V_532 = 2 * V_267 -> V_378 . V_437 ;
V_47 = F_12 ( V_2 , V_637 ) ;
if ( V_47 )
goto V_636;
F_173 ( V_2 , V_267 , V_532 , V_532 ,
V_267 -> V_378 . V_437 / 2 ,
true ) ;
F_7 ( V_2 , V_637 ) ;
F_108 ( V_2 , false , NULL ) ;
}
goto V_34;
V_636:
F_138 ( V_2 , V_267 ) ;
F_133 ( V_2 ) ;
V_34:
if ( V_47 )
V_299 -> V_304 = NULL ;
return V_47 ;
}
static int F_272 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_622 * V_623 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_270 ( V_2 , V_267 , V_623 , false ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_273 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
struct V_622 * V_623 ,
bool V_633 )
{
struct V_113 * V_299 = F_91 ( V_267 ) ;
struct V_266 * V_638 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_180 ( V_2 , V_299 , & V_299 -> V_303 ) ;
switch ( V_267 -> type ) {
case V_122 :
goto V_34;
case V_634 :
V_299 -> V_635 = false ;
V_299 -> V_311 = false ;
F_274 ( V_2 , V_267 ) ;
break;
case V_119 :
if ( ! V_633 || ! V_299 -> V_457 )
goto V_34;
V_299 -> V_461 = false ;
F_275 ( V_2 , V_299 , true ) ;
F_211 ( V_2 -> V_462 , V_267 ) ;
V_299 -> V_457 = false ;
break;
case V_117 :
if ( ! V_633 )
break;
V_638 = V_267 ;
F_163 ( V_2 , V_267 , true , NULL ) ;
break;
default:
break;
}
F_108 ( V_2 , false , V_638 ) ;
F_138 ( V_2 , V_267 ) ;
V_34:
V_299 -> V_304 = NULL ;
F_133 ( V_2 ) ;
}
static void F_276 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_622 * V_623 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_83 ( & V_2 -> V_33 ) ;
F_273 ( V_2 , V_267 , V_623 , false ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static int
F_277 ( struct V_1 * V_2 ,
struct V_639 * V_640 )
{
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
F_273 ( V_2 , V_640 [ 0 ] . V_267 , V_640 [ 0 ] . V_641 , true ) ;
F_267 ( V_2 , V_640 [ 0 ] . V_641 ) ;
V_47 = F_265 ( V_2 , V_640 [ 0 ] . V_642 ) ;
if ( V_47 ) {
F_109 ( V_2 , L_61 ) ;
goto V_643;
}
V_47 = F_270 ( V_2 , V_640 [ 0 ] . V_267 , V_640 [ 0 ] . V_642 ,
true ) ;
if ( V_47 ) {
F_109 ( V_2 ,
L_62 ) ;
goto V_456;
}
if ( F_186 ( V_2 ) > 1 )
F_110 ( V_2 ) ;
goto V_34;
V_456:
F_267 ( V_2 , V_640 [ 0 ] . V_642 ) ;
V_643:
if ( F_265 ( V_2 , V_640 [ 0 ] . V_641 ) ) {
F_109 ( V_2 , L_63 ) ;
goto V_644;
}
if ( F_270 ( V_2 , V_640 [ 0 ] . V_267 , V_640 [ 0 ] . V_641 ,
true ) ) {
F_109 ( V_2 , L_64 ) ;
goto V_644;
}
goto V_34;
V_644:
F_278 ( V_2 , false ) ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_279 ( struct V_1 * V_2 ,
struct V_639 * V_640 )
{
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
F_273 ( V_2 , V_640 [ 0 ] . V_267 , V_640 [ 0 ] . V_641 , true ) ;
V_47 = F_270 ( V_2 , V_640 [ 0 ] . V_267 , V_640 [ 0 ] . V_642 ,
true ) ;
if ( V_47 ) {
F_109 ( V_2 ,
L_62 ) ;
goto V_643;
}
goto V_34;
V_643:
if ( F_270 ( V_2 , V_640 [ 0 ] . V_267 , V_640 [ 0 ] . V_641 ,
true ) ) {
F_109 ( V_2 , L_64 ) ;
goto V_644;
}
goto V_34;
V_644:
F_278 ( V_2 , false ) ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_280 ( struct V_29 * V_30 ,
struct V_639 * V_640 ,
int V_645 ,
enum V_646 V_647 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_645 > 1 )
return - V_546 ;
switch ( V_647 ) {
case V_648 :
V_47 = F_277 ( V_2 , V_640 ) ;
break;
case V_649 :
V_47 = F_279 ( V_2 , V_640 ) ;
break;
default:
V_47 = - V_546 ;
break;
}
return V_47 ;
}
static int F_281 ( struct V_29 * V_30 ,
struct V_236 * V_237 ,
bool V_650 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_111 * V_495 = F_58 ( V_237 ) ;
if ( ! V_495 || ! V_495 -> V_267 ) {
F_109 ( V_2 , L_65 ) ;
return - V_297 ;
}
return F_184 ( V_2 , V_495 -> V_267 ) ;
}
static int F_282 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
void * V_254 , int V_202 )
{
struct V_651 * V_652 [ V_653 + 1 ] ;
int V_654 ;
T_1 V_371 ;
V_654 = F_283 ( V_652 , V_653 , V_254 , V_202 , V_655 ) ;
if ( V_654 )
return V_654 ;
if ( ! V_652 [ V_656 ] )
return - V_297 ;
switch ( F_284 ( V_652 [ V_656 ] ) ) {
case V_657 :
if ( ! V_267 || V_267 -> type != V_119 || ! V_267 -> V_360 ||
! V_267 -> V_378 . V_658 ||
! V_652 [ V_659 ] )
return - V_297 ;
V_371 = F_284 ( V_652 [ V_659 ] ) ;
if ( V_371 >= V_267 -> V_378 . V_437 )
return - V_297 ;
V_2 -> V_371 = V_371 ;
V_2 -> V_370 = V_267 ;
return F_108 ( V_2 , false , NULL ) ;
case V_660 :
if ( ! V_267 || V_267 -> type != V_117 ||
! V_267 -> V_378 . V_379 || ! V_267 -> V_378 . V_591 ||
! V_652 [ V_661 ] )
return - V_297 ;
if ( F_284 ( V_652 [ V_661 ] ) )
return F_181 ( V_2 , V_267 , 0 ) ;
return F_134 ( V_2 , V_267 , 0 ) ;
}
return - V_546 ;
}
static int F_285 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
void * V_254 , int V_202 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_654 ;
F_83 ( & V_2 -> V_33 ) ;
V_654 = F_282 ( V_2 , V_267 , V_254 , V_202 ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_654 ;
}
static void F_286 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_662 * V_663 )
{
F_160 ( F_19 ( V_30 ) ,
L_66 ) ;
}
static int F_287 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_662 * V_663 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_266 * V_460 ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
T_1 V_607 ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_299 -> V_664 = false ;
F_160 ( V_2 , L_67 ,
V_663 -> V_618 . V_665 ) ;
F_288 ( V_2 , V_267 , V_666 ) ;
switch ( V_267 -> type ) {
case V_119 :
V_460 =
F_238 ( V_2 -> V_460 ,
F_239 ( & V_2 -> V_33 ) ) ;
if ( F_113 ( V_460 && V_460 -> V_667 ,
L_68 ) ) {
V_47 = - V_515 ;
goto V_356;
}
F_211 ( V_2 -> V_460 , V_267 ) ;
if ( F_113 ( V_299 -> V_461 ,
L_69 ) ) {
V_47 = - V_515 ;
goto V_356;
}
break;
case V_117 :
V_607 = V_663 -> V_668 +
( ( V_267 -> V_378 . V_437 * ( V_663 -> V_381 - 1 ) -
V_669 ) * 1024 ) ;
if ( V_663 -> V_670 )
F_289 ( V_2 , V_267 ) ;
F_290 ( V_2 , V_267 , V_267 -> V_378 . V_437 ,
V_607 ) ;
if ( V_299 -> V_305 . V_452 ) {
V_47 = F_134 ( V_2 , V_267 , 0 ) ;
if ( V_47 )
goto V_356;
}
break;
default:
break;
}
V_299 -> V_311 = true ;
V_47 = F_291 ( V_2 ) ;
if ( V_47 )
goto V_356;
F_110 ( V_2 ) ;
V_356:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_292 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_113 * V_299 = F_91 ( V_267 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_299 -> V_664 ) {
V_299 -> V_664 = false ;
V_47 = - V_17 ;
goto V_356;
}
if ( V_267 -> type == V_117 ) {
struct V_111 * V_240 ;
V_240 = F_293 ( V_2 ,
V_299 -> V_301 ) ;
if ( F_8 ( ! V_240 ) ) {
V_47 = - V_17 ;
goto V_356;
}
F_294 ( V_2 , V_240 , false ) ;
F_163 ( V_2 , V_267 , false , NULL ) ;
V_47 = F_181 ( V_2 , V_267 , 0 ) ;
if ( V_47 )
goto V_356;
F_295 ( V_2 , V_267 ) ;
}
V_299 -> V_311 = false ;
V_47 = F_291 ( V_2 ) ;
V_356:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_296 ( struct V_29 * V_30 ,
struct V_266 * V_267 , T_1 V_75 , bool V_255 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 ;
struct V_111 * V_240 ;
struct V_236 * V_237 ;
int V_9 ;
T_1 V_671 = 0 ;
if ( ! V_267 || V_267 -> type != V_117 )
return;
F_83 ( & V_2 -> V_33 ) ;
V_299 = F_91 ( V_267 ) ;
for ( V_9 = 0 ; V_9 < V_244 ; V_9 ++ ) {
V_237 = F_238 ( V_2 -> V_496 [ V_9 ] ,
F_239 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_237 ) )
continue;
V_240 = F_58 ( V_237 ) ;
if ( V_240 -> V_267 != V_267 )
continue;
F_8 ( V_9 != V_299 -> V_301 && ! V_237 -> V_513 ) ;
V_671 |= V_240 -> V_672 ;
}
if ( V_255 ) {
if ( F_144 ( V_2 , V_671 , 0 ) )
F_109 ( V_2 , L_70 ) ;
F_89 ( & V_2 -> V_33 ) ;
} else {
F_89 ( & V_2 -> V_33 ) ;
F_145 ( V_2 -> V_7 , V_671 ) ;
}
}
static int F_297 ( struct V_29 * V_30 , int V_673 ,
struct V_674 * V_675 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_675 , 0 , sizeof( * V_675 ) ) ;
if ( V_673 != 0 )
return - V_49 ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_676 ) )
return - V_49 ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_335 ) {
V_47 = F_172 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_675 -> V_677 = V_678 |
V_679 |
V_680 |
V_681 ;
V_675 -> time = V_2 -> V_332 . V_682 +
V_2 -> V_683 . V_682 ;
F_298 ( V_675 -> time , V_684 ) ;
V_675 -> V_685 = V_2 -> V_332 . V_686 +
V_2 -> V_683 . V_686 ;
F_298 ( V_675 -> V_685 , V_684 ) ;
V_675 -> V_687 = V_2 -> V_332 . V_688 +
V_2 -> V_683 . V_688 ;
F_298 ( V_675 -> V_687 , V_684 ) ;
V_675 -> V_689 = V_2 -> V_332 . V_690 +
V_2 -> V_683 . V_690 ;
F_298 ( V_675 -> V_689 , V_684 ) ;
V_47 = 0 ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_299 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_236 * V_237 ,
struct V_691 * V_692 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_299 = F_91 ( V_267 ) ;
struct V_111 * V_240 = F_58 ( V_237 ) ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_676 ) )
return;
if ( ! ( V_267 -> V_361 & V_362 ) )
return;
if ( ! V_267 -> V_378 . V_379 )
return;
F_83 ( & V_2 -> V_33 ) ;
if ( V_299 -> V_301 != V_240 -> V_243 )
goto V_693;
if ( F_172 ( V_2 , false ) )
goto V_693;
V_692 -> V_694 = V_299 -> V_353 . V_355 +
V_299 -> V_353 . V_354 ;
V_692 -> V_677 |= F_41 ( V_695 ) ;
if ( V_299 -> V_353 . V_696 ) {
V_692 -> V_697 = V_299 -> V_353 . V_696 ;
V_692 -> V_677 |= F_41 ( V_698 ) ;
}
V_693:
F_89 ( & V_2 -> V_33 ) ;
}
static void F_300 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
const struct V_699 * V_700 )
{
#define F_301 ( T_5 , T_6 , T_7 , T_8 , T_9 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_272 * V_273 ;
struct V_701 * V_702 ;
if ( ! F_77 ( V_2 -> V_93 , V_703 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_703 ) ;
V_702 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
if ( V_700 -> V_704 . V_705 . V_254 == V_706 ) {
if ( V_700 -> V_704 . V_705 . V_15 == V_707 )
F_301 ( V_2 , V_273 , V_708 ,
V_702 -> V_709 ,
L_71 ,
V_700 -> V_704 . V_705 . V_482 ) ;
else if ( V_700 -> V_704 . V_705 . V_15 == V_710 )
F_301 ( V_2 , V_273 , V_708 ,
V_702 -> V_711 ,
L_72 ) ;
} else if ( V_700 -> V_704 . V_705 . V_254 == V_712 ) {
if ( V_700 -> V_704 . V_705 . V_15 == V_707 )
F_301 ( V_2 , V_273 , V_708 ,
V_702 -> V_713 ,
L_73 ,
V_700 -> V_704 . V_705 . V_482 ) ;
else if ( V_700 -> V_704 . V_705 . V_15 == V_710 )
F_301 ( V_2 , V_273 , V_708 ,
V_702 -> V_714 ,
L_74 ) ;
} else if ( V_700 -> V_704 . V_705 . V_254 == V_715 ) {
F_301 ( V_2 , V_273 , V_708 ,
V_702 -> V_716 ,
L_75 , V_700 -> V_704 . V_705 . V_482 ) ;
} else if ( V_700 -> V_704 . V_705 . V_254 == V_717 ) {
F_301 ( V_2 , V_273 , V_708 ,
V_702 -> V_718 ,
L_76 , V_700 -> V_704 . V_705 . V_482 ) ;
}
#undef F_301
}
static void F_302 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
const struct V_699 * V_700 )
{
struct V_272 * V_273 ;
struct V_274 * V_275 ;
if ( ! F_77 ( V_2 -> V_93 , V_276 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_276 ) ;
V_275 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
if ( ! ( F_303 ( V_275 -> V_719 ) & F_41 ( V_700 -> V_704 . V_720 . V_268 ) ) )
return;
F_215 ( V_2 , V_273 ,
L_77 ,
V_700 -> V_704 . V_720 . V_237 -> V_140 , V_700 -> V_704 . V_720 . V_268 ,
V_700 -> V_704 . V_720 . V_281 ) ;
}
static void
F_304 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
const struct V_699 * V_700 )
{
struct V_272 * V_273 ;
struct V_274 * V_275 ;
if ( ! F_77 ( V_2 -> V_93 , V_276 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_276 ) ;
V_275 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
if ( ! ( F_303 ( V_275 -> V_721 ) & F_41 ( V_700 -> V_704 . V_720 . V_268 ) ) )
return;
F_215 ( V_2 , V_273 ,
L_78 ,
V_700 -> V_704 . V_720 . V_237 -> V_140 , V_700 -> V_704 . V_720 . V_268 ) ;
}
static void F_305 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
const struct V_699 * V_700 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_700 -> type ) {
case V_722 :
F_300 ( V_2 , V_267 , V_700 ) ;
break;
case V_723 :
F_302 ( V_2 , V_267 , V_700 ) ;
break;
case V_724 :
F_304 ( V_2 , V_267 , V_700 ) ;
break;
default:
break;
}
}
