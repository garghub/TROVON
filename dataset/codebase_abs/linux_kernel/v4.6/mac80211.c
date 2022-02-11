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
struct V_288 * V_289 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_290 = false ;
struct V_236 * V_237 = V_289 -> V_237 ;
enum V_270 V_271 = V_289 -> V_271 ;
V_115 V_268 = V_289 -> V_268 ;
V_115 * V_281 = & V_289 -> V_281 ;
T_2 V_291 = V_289 -> V_291 ;
bool V_292 = V_289 -> V_292 ;
F_82 ( V_2 , L_17 ,
V_237 -> V_140 , V_268 , V_271 ) ;
if ( ! ( V_2 -> V_141 -> V_293 ) )
return - V_294 ;
switch ( V_271 ) {
case V_295 :
case V_282 :
case V_296 :
case V_297 :
case V_277 :
V_47 = F_12 ( V_2 , V_298 ) ;
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
V_47 = - V_299 ;
break;
}
V_47 = F_84 ( V_2 , V_237 , V_268 , * V_281 , true , V_291 ) ;
break;
case V_286 :
V_47 = F_84 ( V_2 , V_237 , V_268 , 0 , false , V_291 ) ;
break;
case V_295 :
if ( ! F_75 ( V_2 -> V_37 ) ) {
V_47 = - V_299 ;
break;
}
V_47 = F_85 ( V_2 , V_267 , V_237 , V_268 , V_281 ) ;
break;
case V_282 :
V_47 = F_86 ( V_2 , V_267 , V_237 , V_268 ) ;
break;
case V_296 :
case V_297 :
V_47 = F_87 ( V_2 , V_267 , V_237 , V_268 ) ;
break;
case V_277 :
V_47 = F_88 ( V_2 , V_267 , V_237 , V_268 ,
V_291 , V_292 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_299 ;
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
F_7 ( V_2 , V_298 ) ;
return V_47 ;
}
static void F_90 ( void * V_254 , T_2 * V_300 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = V_254 ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
V_301 -> V_302 = false ;
V_301 -> V_303 = V_244 ;
F_4 ( & V_2 -> V_304 ) ;
F_92 ( V_2 , & V_301 -> V_305 ) ;
F_5 ( & V_2 -> V_304 ) ;
V_301 -> V_306 = NULL ;
memset ( & V_301 -> V_307 , 0 , sizeof( V_301 -> V_307 ) ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
if ( ! F_94 ( V_308 , & V_2 -> V_15 ) ) {
V_2 -> V_309 = & V_310 ;
F_95 ( V_2 ) ;
}
F_10 ( V_2 , V_311 ) ;
F_96 ( V_2 ) ;
V_2 -> V_312 = 0 ;
V_2 -> V_313 = false ;
V_2 -> V_314 = false ;
F_97 ( V_2 ) ;
F_98 ( V_2 -> V_30 ) ;
F_99 ( V_2 -> V_30 , 0 , F_90 , V_2 ) ;
V_2 -> V_315 = NULL ;
V_2 -> V_245 = V_244 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_316 , 0 , sizeof( V_2 -> V_316 ) ) ;
memset ( V_2 -> V_317 , 0 , sizeof( V_2 -> V_317 ) ) ;
memset ( V_2 -> V_318 , 0 , sizeof( V_2 -> V_318 ) ) ;
memset ( & V_2 -> V_319 , 0 , sizeof( V_2 -> V_319 ) ) ;
memset ( & V_2 -> V_320 , 0 , sizeof( V_2 -> V_320 ) ) ;
memset ( & V_2 -> V_321 , 0 , sizeof( V_2 -> V_321 ) ) ;
memset ( & V_2 -> V_322 , 0 , sizeof( V_2 -> V_322 ) ) ;
memset ( & V_2 -> V_323 , 0 , sizeof( V_2 -> V_323 ) ) ;
memset ( & V_2 -> V_324 , 0 , sizeof( V_2 -> V_324 ) ) ;
F_100 ( V_2 -> V_30 ) ;
F_101 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_325 = 0 ;
V_2 -> V_326 = 0 ;
V_2 -> V_327 = V_328 ;
F_102 ( V_2 ) ;
}
int F_103 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_329 , & V_2 -> V_15 ) ) {
F_93 ( V_2 ) ;
} else {
F_1 ( V_2 , V_311 ) ;
}
V_47 = F_104 ( V_2 ) ;
if ( V_47 && F_14 ( V_329 , & V_2 -> V_15 ) ) {
F_101 ( V_329 , & V_2 -> V_15 ) ;
F_105 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_106 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_329 , & V_2 -> V_15 ) ) {
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
F_101 ( V_329 , & V_2 -> V_15 ) ;
F_105 ( V_2 , NULL ) ;
V_47 = F_108 ( V_2 , true , NULL ) ;
if ( V_47 )
F_109 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_311 ) ;
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
enum V_330 V_331 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_331 ) {
case V_332 :
F_107 ( V_2 ) ;
break;
case V_333 :
F_111 ( V_2 ) ;
break;
}
}
void F_115 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_334 , 0 , sizeof( V_2 -> V_334 ) ) ;
F_116 ( & V_2 -> V_335 ) ;
F_96 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
if ( F_94 ( V_329 , & V_2 -> V_15 ) )
F_99 ( V_2 -> V_30 , 0 ,
F_90 , V_2 ) ;
if ( F_45 ( & V_2 -> V_93 -> V_94 , V_154 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_155 ; V_9 ++ ) {
if ( F_113 ( V_2 -> V_336 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_336 [ V_9 ] = 0 ;
}
}
}
static void F_120 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_116 ( & V_2 -> V_337 ) ;
F_116 ( & V_2 -> V_338 ) ;
F_121 ( & V_2 -> V_339 ) ;
F_122 ( V_2 ) ;
F_83 ( & V_2 -> V_33 ) ;
F_115 ( V_2 ) ;
F_89 ( & V_2 -> V_33 ) ;
F_123 ( & V_2 -> V_338 ) ;
}
static struct V_340 * F_124 ( struct V_1 * V_2 )
{
V_115 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_109 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_125 ( struct V_1 * V_2 , struct V_266 * V_267 ,
T_3 V_341 )
{
struct V_342 V_343 = {
. V_344 . V_345 = F_126 ( V_346 ) ,
. V_344 . V_347 =
F_126 ( F_91 ( V_267 ) -> V_20 ) ,
. V_344 . V_348 = F_127 ( 8 * V_341 ) ,
} ;
int V_202 = sizeof( V_343 ) ;
if ( V_341 == V_349 )
V_343 . V_344 . V_348 = F_127 ( V_350 ) ;
if ( ! F_46 ( & V_2 -> V_93 -> V_94 , V_351 ) )
V_202 = sizeof( V_343 . V_344 ) ;
return F_128 ( V_2 , V_352 , 0 , V_202 , & V_343 ) ;
}
static int F_129 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
int V_47 ;
V_301 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_353 ) ;
if ( V_47 )
return V_47 ;
F_83 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_329 , & V_2 -> V_15 ) )
V_301 -> V_354 . V_355 +=
V_301 -> V_354 . V_356 ;
V_47 = F_130 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_357;
if ( V_267 -> type != V_121 )
V_2 -> V_325 ++ ;
if ( V_267 -> type == V_119 ||
V_267 -> type == V_122 ) {
V_47 = F_131 ( V_2 , V_267 ) ;
if ( V_47 ) {
F_109 ( V_2 , L_22 ) ;
goto V_358;
}
F_132 ( V_2 , V_267 ) ;
goto V_357;
}
V_301 -> V_106 |= V_30 -> V_72 ;
V_47 = F_133 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_358;
V_47 = F_134 ( V_2 ) ;
if ( V_47 )
goto V_359;
V_47 = F_135 ( V_2 , V_267 , 0 ) ;
if ( V_47 )
goto V_359;
if ( ! V_2 -> V_360 &&
V_267 -> type == V_117 && ! V_267 -> V_361 ) {
V_2 -> V_360 = V_301 ;
V_267 -> V_362 |= V_363 |
V_364 ;
}
if ( V_267 -> type == V_121 ) {
V_301 -> V_306 = F_124 ( V_2 ) ;
if ( ! V_301 -> V_306 ) {
V_47 = - V_365 ;
goto V_366;
}
F_136 ( V_2 , V_301 -> V_306 ) ;
V_47 = F_137 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_367;
V_47 = F_138 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_368;
V_2 -> V_315 = V_267 ;
}
F_132 ( V_2 , V_267 ) ;
goto V_357;
V_368:
F_139 ( V_2 , V_267 ) ;
V_367:
F_140 ( V_2 , V_301 -> V_306 ) ;
V_366:
if ( V_2 -> V_360 == V_301 ) {
V_2 -> V_360 = NULL ;
V_267 -> V_362 &= ~ ( V_363 |
V_364 ) ;
}
V_359:
V_301 -> V_306 = NULL ;
F_141 ( V_2 , V_267 ) ;
V_358:
if ( V_267 -> type != V_121 )
V_2 -> V_325 -- ;
F_142 ( V_2 , V_267 ) ;
V_357:
F_89 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_353 ) ;
return V_47 ;
}
static void F_143 ( struct V_1 * V_2 ,
struct V_266 * V_267 )
{
T_1 V_369 = F_144 ( V_267 ) ;
if ( V_369 ) {
F_83 ( & V_2 -> V_33 ) ;
F_145 ( V_2 , V_369 , 0 ) ;
F_89 ( & V_2 -> V_33 ) ;
F_146 ( V_2 -> V_7 , V_369 ) ;
}
if ( V_267 -> type == V_121 ) {
F_116 ( & V_2 -> V_335 ) ;
} else {
F_116 ( & V_2 -> V_370 ) ;
}
}
static void F_147 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
F_143 ( V_2 , V_267 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_360 == V_301 ) {
V_2 -> V_360 = NULL ;
V_267 -> V_362 &= ~ ( V_363 |
V_364 ) ;
}
F_148 ( V_2 , V_267 ) ;
if ( V_267 -> type == V_119 ||
V_267 -> type == V_122 ) {
#ifdef F_149
if ( V_267 == V_2 -> V_371 ) {
V_2 -> V_371 = NULL ;
V_2 -> V_372 = 0 ;
}
#endif
F_150 ( V_2 , V_267 ) ;
goto V_358;
}
if ( V_267 -> type == V_121 ) {
V_2 -> V_315 = NULL ;
F_151 ( V_2 , V_267 ) ;
F_139 ( V_2 , V_267 ) ;
F_140 ( V_2 , V_301 -> V_306 ) ;
V_301 -> V_306 = NULL ;
}
if ( V_2 -> V_325 && V_267 -> type != V_121 )
V_2 -> V_325 -- ;
F_134 ( V_2 ) ;
F_141 ( V_2 , V_267 ) ;
V_358:
F_142 ( V_2 , V_267 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static int F_152 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_153 ( void * V_373 , T_2 * V_300 ,
struct V_266 * V_267 )
{
struct V_374 * V_254 = V_373 ;
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_375 * V_343 = V_2 -> V_376 ;
int V_47 , V_202 ;
if ( F_15 ( V_254 -> V_377 >= V_378 ) )
return;
if ( V_267 -> type != V_117 ||
! V_267 -> V_379 . V_380 )
return;
V_343 -> V_377 = V_254 -> V_377 ++ ;
memcpy ( V_343 -> V_381 , V_267 -> V_379 . V_381 , V_143 ) ;
V_202 = F_154 ( sizeof( * V_343 ) + V_343 -> V_382 * V_143 , 4 ) ;
V_47 = F_128 ( V_2 , V_383 , V_384 , V_202 , V_343 ) ;
if ( V_47 )
F_109 ( V_2 , L_23 , V_47 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_374 V_385 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_376 ) )
return;
F_156 (
V_2 -> V_30 , V_386 ,
F_153 , & V_385 ) ;
}
static T_4 F_157 ( struct V_29 * V_30 ,
struct V_387 * V_388 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_375 * V_343 ;
struct V_389 * V_140 ;
int V_390 ;
bool V_391 ;
int V_202 ;
V_390 = F_158 ( V_388 ) ;
V_391 = V_390 > V_392 ||
V_393 ;
if ( V_391 )
V_390 = 0 ;
V_202 = F_154 ( sizeof( * V_343 ) + V_390 * V_143 , 4 ) ;
V_343 = F_159 ( V_202 , V_394 ) ;
if ( ! V_343 )
return 0 ;
if ( V_391 ) {
V_343 -> V_391 = 1 ;
return ( T_4 ) ( unsigned long ) V_343 ;
}
F_160 (addr, mc_list) {
F_161 ( V_2 , L_24 ,
V_343 -> V_382 , V_140 -> V_140 ) ;
memcpy ( & V_343 -> V_395 [ V_343 -> V_382 * V_143 ] ,
V_140 -> V_140 , V_143 ) ;
V_343 -> V_382 ++ ;
}
return ( T_4 ) ( unsigned long ) V_343 ;
}
static void F_162 ( struct V_29 * V_30 ,
unsigned int V_396 ,
unsigned int * V_397 ,
T_4 V_398 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_375 * V_343 = ( void * ) ( unsigned long ) V_398 ;
F_83 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_376 ) ;
V_2 -> V_376 = V_343 ;
if ( ! V_343 )
goto V_34;
F_155 ( V_2 ) ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
* V_397 = 0 ;
}
static void F_163 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
unsigned int V_399 ,
unsigned int V_396 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_396 & V_400 ) )
return;
if ( V_267 -> type != V_117 || ! V_267 -> V_379 . V_380 ||
! V_267 -> V_361 )
return;
F_83 ( & V_2 -> V_33 ) ;
F_164 ( V_2 , V_267 , false , NULL ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void
F_165 ( struct V_266 * V_267 ,
const struct V_401 * V_402 ,
struct V_401 * V_403 )
{
struct V_404 * V_405 ;
int V_9 ;
memcpy ( V_403 , V_402 , sizeof( * V_403 ) ) ;
for ( V_9 = 0 ; V_9 < F_40 ( V_403 -> V_406 ) ; V_9 ++ ) {
V_405 = & V_403 -> V_406 [ V_9 ] ;
if ( ! V_405 -> V_407 )
break;
switch ( V_405 -> V_408 ) {
case F_127 ( V_409 ) :
if ( V_267 -> V_379 . V_410 != 1 ) {
V_405 -> V_407 = 0 ;
continue;
}
V_405 -> V_411 = V_267 -> V_379 . V_412 [ 0 ] ;
break;
case F_127 ( V_413 ) :
V_405 -> V_411 = * ( V_414 * ) & V_267 -> V_140 [ 2 ] ;
break;
default:
break;
}
V_405 -> V_408 = 0 ;
V_403 -> V_415 ++ ;
}
}
static void F_166 ( void * V_373 , T_2 * V_300 ,
struct V_266 * V_267 )
{
struct V_416 * V_254 = V_373 ;
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_417 * V_343 = V_254 -> V_343 ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
struct V_418 * V_419 ;
int V_9 ;
if ( F_8 ( V_301 -> V_20 >= F_40 ( V_343 -> V_420 ) ) )
return;
V_419 = & V_343 -> V_420 [ V_301 -> V_20 ] ;
if ( V_267 -> type != V_117 || V_267 -> V_361 ||
! V_267 -> V_379 . V_380 )
return;
V_419 -> V_421 = 1 ;
for ( V_9 = 0 ; V_2 -> V_223 [ V_9 ] . V_406 [ 0 ] . V_407 ; V_9 ++ ) {
if ( F_15 ( V_254 -> V_422 >=
F_40 ( V_343 -> V_423 ) ) ) {
V_419 -> V_421 = 0 ;
V_419 -> V_424 = 0 ;
break;
}
F_165 ( V_267 ,
& V_2 -> V_223 [ V_9 ] ,
& V_343 -> V_423 [ V_254 -> V_422 ] ) ;
if ( ! V_343 -> V_423 [ V_254 -> V_422 ] . V_415 )
continue;
V_419 -> V_424 |=
F_127 ( F_41 ( V_254 -> V_422 ) ) ;
V_254 -> V_422 ++ ;
}
}
bool F_167 ( struct V_1 * V_2 ,
struct V_417 * V_343 )
{
struct V_416 V_385 = {
. V_2 = V_2 ,
. V_343 = V_343 ,
} ;
if ( V_425 )
return false ;
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
V_343 -> V_426 = F_40 ( V_343 -> V_423 ) ;
V_343 -> V_427 = F_40 ( V_343 -> V_420 ) ;
#ifdef F_168
if ( V_2 -> V_428 . V_429 ) {
memcpy ( V_343 -> V_423 , & V_2 -> V_428 . V_343 . V_423 ,
sizeof( V_343 -> V_423 ) ) ;
memcpy ( V_343 -> V_420 , & V_2 -> V_428 . V_343 . V_420 ,
sizeof( V_343 -> V_420 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_223 )
return false ;
F_169 (
V_2 -> V_30 , V_386 ,
F_166 , & V_385 ) ;
return true ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_417 V_343 ;
if ( ! ( V_2 -> V_93 -> V_94 . V_95 & V_430 ) )
return 0 ;
if ( ! F_167 ( V_2 , & V_343 ) )
return 0 ;
return F_128 ( V_2 , V_431 , 0 ,
sizeof( V_343 ) , & V_343 ) ;
}
static inline int F_170 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_266 * V_267 )
{
struct V_432 V_343 = {} ;
memcpy ( V_343 . V_433 , V_267 -> V_379 . V_434 . V_435 ,
V_436 ) ;
memcpy ( V_343 . V_437 , V_267 -> V_379 . V_434 . V_438 ,
V_439 ) ;
return F_128 ( V_2 ,
F_172 ( V_440 ,
V_441 ) ,
0 , sizeof( V_343 ) , & V_343 ) ;
}
static void F_173 ( void * V_373 , T_2 * V_300 ,
struct V_266 * V_267 )
{
if ( V_267 -> V_442 ) {
struct V_443 * V_444 = V_373 ;
F_174 ( V_267 ,
( T_2 * ) & V_444 -> V_433 ,
( T_2 * ) & V_444 -> V_437 ) ;
}
}
void F_175 ( struct V_1 * V_2 ,
struct V_445 * V_446 )
{
struct V_447 * V_448 = F_176 ( V_446 ) ;
struct V_443 * V_444 = ( void * ) V_448 -> V_254 ;
F_156 (
V_2 -> V_30 , V_386 ,
F_173 , V_444 ) ;
}
static void F_177 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
struct V_449 * V_379 ,
T_1 V_450 )
{
struct V_113 * V_301 = F_91 ( V_267 ) ;
int V_47 ;
if ( V_450 & V_451 && V_379 -> V_380 )
F_178 ( V_2 , V_267 ) ;
if ( V_450 & V_452 && ! V_301 -> V_453 )
memcpy ( V_301 -> V_381 , V_379 -> V_381 , V_143 ) ;
V_47 = F_164 ( V_2 , V_267 , false , V_301 -> V_381 ) ;
if ( V_47 )
F_109 ( V_2 , L_25 , V_267 -> V_140 ) ;
memcpy ( V_301 -> V_381 , V_379 -> V_381 , V_143 ) ;
V_301 -> V_453 = V_379 -> V_380 ;
if ( V_450 & V_451 ) {
if ( V_379 -> V_380 ) {
F_179 ( V_2 , true ) ;
memset ( & V_301 -> V_354 , 0 ,
sizeof( V_301 -> V_354 ) ) ;
V_47 = F_108 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_109 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_329 ,
& V_2 -> V_15 ) ) {
T_1 V_454 = ( 11 * V_267 -> V_379 . V_455 ) / 10 ;
F_180 ( V_2 , V_267 , V_454 , V_454 ,
5 * V_454 , false ) ;
}
F_181 ( V_2 , V_267 , false ) ;
F_182 ( V_2 , V_267 ) ;
if ( V_267 -> V_361 ) {
F_1 ( V_2 , V_456 ) ;
F_183 ( V_2 , V_267 ,
V_457 ,
V_458 ) ;
}
} else if ( V_301 -> V_303 != V_244 ) {
F_113 ( F_181 ( V_2 , V_267 , false ) ,
L_27 ) ;
V_47 = F_184 ( V_2 , V_267 , V_301 -> V_303 ) ;
if ( V_47 )
F_109 ( V_2 , L_28 ) ;
if ( V_2 -> V_245 == V_301 -> V_303 )
V_2 -> V_245 = V_244 ;
V_301 -> V_303 = V_244 ;
V_47 = F_108 ( V_2 , false , NULL ) ;
if ( V_47 )
F_109 ( V_2 , L_26 ) ;
if ( V_267 -> V_361 )
F_7 ( V_2 , V_456 ) ;
V_47 = F_164 ( V_2 , V_267 , false , NULL ) ;
if ( V_47 )
F_109 ( V_2 ,
L_29 ,
V_267 -> V_140 ) ;
}
if ( F_14 ( V_329 , & V_2 -> V_15 ) &&
( V_450 & V_459 ) && V_267 -> V_442 ) {
V_47 = F_171 ( V_2 , V_267 ) ;
if ( V_47 )
F_109 ( V_2 ,
L_30 ) ;
}
F_155 ( V_2 ) ;
F_170 ( V_2 ) ;
V_301 -> V_307 . V_460 = 0 ;
F_185 ( V_2 ) ;
F_183 ( V_2 , V_267 , V_461 ,
V_462 ) ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_154 ) )
F_186 ( V_2 ) ;
} else if ( V_450 & V_463 ) {
F_187 ( V_2 , V_301 ,
& V_301 -> V_305 ) ;
}
if ( V_450 & V_463 ) {
F_181 ( V_2 , V_267 , false ) ;
F_8 ( F_188 ( V_2 , V_267 , 0 ) ) ;
}
if ( V_450 & ( V_464 | V_465 | V_466 |
V_463 ) ) {
V_47 = F_134 ( V_2 ) ;
if ( V_47 )
F_109 ( V_2 , L_31 ) ;
}
if ( V_450 & V_467 ) {
F_189 ( V_2 , L_32 ,
V_379 -> V_468 ) ;
F_125 ( V_2 , V_267 , V_379 -> V_468 ) ;
}
if ( V_450 & V_469 ) {
F_161 ( V_2 , L_33 ) ;
V_301 -> V_307 . V_470 = 0 ;
if ( V_301 -> V_307 . V_471 ) {
V_47 = F_188 ( V_2 , V_267 , 0 ) ;
if ( V_47 )
F_109 ( V_2 ,
L_34 ) ;
}
}
if ( V_450 & V_472 ) {
F_161 ( V_2 , L_35 ) ;
F_170 ( V_2 ) ;
}
}
static int F_190 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_473 ) ;
if ( V_47 )
return V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_191 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_357;
if ( V_267 -> type == V_119 )
F_178 ( V_2 , V_267 ) ;
V_301 -> V_474 = 0 ;
V_47 = F_133 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_357;
V_47 = F_137 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_475;
V_47 = F_192 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_368;
V_301 -> V_476 = true ;
F_134 ( V_2 ) ;
V_47 = F_108 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_477;
if ( V_267 -> V_361 && V_2 -> V_315 )
F_164 ( V_2 , V_2 -> V_315 , false , NULL ) ;
F_1 ( V_2 , V_478 ) ;
F_185 ( V_2 ) ;
if ( F_193 ( V_2 ) > 1 )
F_110 ( V_2 ) ;
goto V_357;
V_477:
F_134 ( V_2 ) ;
V_301 -> V_476 = false ;
F_194 ( V_2 , V_267 ) ;
V_368:
F_139 ( V_2 , V_267 ) ;
V_475:
F_141 ( V_2 , V_267 ) ;
V_357:
F_89 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_473 ) ;
return V_47 ;
}
static void F_195 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
F_143 ( V_2 , V_267 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( F_196 ( V_2 -> V_479 ) == V_267 ) {
F_187 ( V_2 , V_301 ,
& V_301 -> V_305 ) ;
F_197 ( V_2 -> V_479 , NULL ) ;
V_301 -> V_480 = false ;
}
if ( F_196 ( V_2 -> V_481 ) == V_267 ) {
F_197 ( V_2 -> V_481 , NULL ) ;
V_2 -> V_482 = 0 ;
}
V_301 -> V_476 = false ;
V_2 -> V_483 = 0 ;
F_185 ( V_2 ) ;
F_7 ( V_2 , V_478 ) ;
if ( V_267 -> V_361 && V_2 -> V_315 )
F_164 ( V_2 , V_2 -> V_315 , false , NULL ) ;
F_108 ( V_2 , false , NULL ) ;
F_194 ( V_2 , V_267 ) ;
F_139 ( V_2 , V_267 ) ;
F_134 ( V_2 ) ;
F_141 ( V_2 , V_267 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void
F_198 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
struct V_449 * V_379 ,
T_1 V_450 )
{
struct V_113 * V_301 = F_91 ( V_267 ) ;
if ( ! V_301 -> V_476 )
return;
if ( V_450 & ( V_484 | V_485 |
V_486 | V_466 ) &&
F_164 ( V_2 , V_267 , false , NULL ) )
F_109 ( V_2 , L_25 , V_267 -> V_140 ) ;
if ( V_450 & V_487 &&
F_191 ( V_2 , V_267 ) )
F_199 ( V_2 , L_36 ) ;
if ( V_450 & V_467 ) {
F_189 ( V_2 , L_32 ,
V_379 -> V_468 ) ;
F_125 ( V_2 , V_267 , V_379 -> V_468 ) ;
}
}
static void F_200 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_449 * V_379 ,
T_1 V_450 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_488 ) )
return;
F_83 ( & V_2 -> V_33 ) ;
if ( V_450 & V_489 && ! V_379 -> V_490 )
F_201 ( V_2 , V_491 , true ) ;
switch ( V_267 -> type ) {
case V_117 :
F_177 ( V_2 , V_267 , V_379 , V_450 ) ;
break;
case V_119 :
case V_122 :
F_198 ( V_2 , V_267 , V_379 , V_450 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_89 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_488 ) ;
}
static int F_202 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_492 * V_493 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_493 -> V_494 . V_38 == 0 ||
V_493 -> V_494 . V_38 > V_2 -> V_93 -> V_94 . V_495 )
return - V_299 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_203 ( V_2 , V_267 , & V_493 -> V_494 , & V_493 -> V_496 ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_204 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_312 & V_497 )
F_201 ( V_2 , V_497 , true ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void
F_205 ( struct V_29 * V_30 ,
struct V_236 * V_237 , V_115 V_498 ,
int V_499 ,
enum V_500 V_501 ,
bool V_502 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_206 ( V_2 , V_237 , V_501 , V_499 ,
V_498 , V_502 , false ) ;
}
static void
F_207 ( struct V_29 * V_30 ,
struct V_236 * V_237 , V_115 V_498 ,
int V_499 ,
enum V_500 V_501 ,
bool V_502 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_206 ( V_2 , V_237 , V_501 , V_499 ,
V_498 , V_502 , true ) ;
}
static void F_208 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
enum V_503 V_343 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_111 * V_240 = F_58 ( V_237 ) ;
unsigned long V_504 = 0 , V_498 = 0 ;
int V_268 ;
F_4 ( & V_240 -> V_505 ) ;
for ( V_268 = 0 ; V_268 < V_506 ; V_268 ++ ) {
struct V_278 * V_279 = & V_240 -> V_279 [ V_268 ] ;
if ( V_279 -> V_507 != V_508 &&
V_279 -> V_507 != V_509 )
continue;
F_209 ( V_279 -> V_510 , & V_504 ) ;
if ( F_210 ( V_279 ) == 0 )
continue;
F_209 ( V_268 , & V_498 ) ;
}
switch ( V_343 ) {
case V_511 :
if ( F_211 ( & V_2 -> V_512 [ V_240 -> V_243 ] ) > 0 )
F_212 ( V_30 , V_237 , true ) ;
F_213 (tid, &tids, IWL_MAX_TID_COUNT)
F_214 ( V_237 , V_268 , true ) ;
if ( V_504 )
F_215 ( V_2 -> V_7 , V_504 , true ) ;
break;
case V_513 :
if ( F_8 ( V_240 -> V_243 == V_244 ) )
break;
if ( V_504 )
F_215 ( V_2 -> V_7 , V_504 , false ) ;
F_216 ( V_2 , V_237 ) ;
break;
default:
break;
}
F_5 ( & V_240 -> V_505 ) ;
}
static void F_217 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_111 * V_514 = F_58 ( V_237 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_237 == F_196 ( V_2 -> V_515 [ V_514 -> V_243 ] ) )
F_218 ( V_2 -> V_515 [ V_514 -> V_243 ] ,
F_219 ( - V_49 ) ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void F_220 ( struct V_1 * V_2 , struct V_266 * V_267 ,
const T_2 * V_381 )
{
if ( ! ( V_2 -> V_93 -> V_94 . V_95 & V_516 ) )
return;
if ( V_267 -> V_361 && ! F_221 ( V_2 ) ) {
V_267 -> V_362 &= ~ V_517 ;
return;
}
if ( V_97 . V_518 ) {
V_267 -> V_362 &= ~ V_517 ;
return;
}
V_267 -> V_362 |= V_517 ;
}
static void
F_222 ( struct V_1 * V_2 ,
struct V_266 * V_267 , T_2 * V_519 ,
enum V_520 V_271 )
{
struct V_272 * V_273 ;
struct V_521 * V_522 ;
if ( ! F_77 ( V_2 -> V_93 , V_523 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_523 ) ;
V_522 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
if ( ! ( V_522 -> V_524 & F_41 ( V_271 ) ) )
return;
if ( V_522 -> V_525 &&
memcmp ( V_522 -> V_526 , V_519 , V_143 ) != 0 )
return;
F_223 ( V_2 , V_273 ,
L_37 ,
V_519 , V_271 ) ;
}
static int F_224 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_236 * V_237 ,
enum V_527 V_528 ,
enum V_527 V_529 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
int V_47 ;
F_161 ( V_2 , L_38 ,
V_237 -> V_140 , V_528 , V_529 ) ;
if ( F_15 ( ! V_301 -> V_306 ) )
return - V_299 ;
F_116 ( & V_2 -> V_370 ) ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_528 == V_530 &&
V_529 == V_531 ) {
if ( V_267 -> type == V_117 &&
V_267 -> V_379 . V_455 < 16 ) {
F_109 ( V_2 ,
L_39 ,
V_237 -> V_140 , V_267 -> V_379 . V_455 ) ;
V_47 = - V_299 ;
goto V_357;
}
if ( V_237 -> V_532 &&
( V_267 -> V_361 ||
F_225 ( V_2 , NULL ) ==
V_533 ||
F_193 ( V_2 ) > 1 ) ) {
F_161 ( V_2 , L_40 ) ;
V_47 = - V_534 ;
goto V_357;
}
V_47 = F_226 ( V_2 , V_267 , V_237 ) ;
if ( V_237 -> V_532 && V_47 == 0 ) {
F_227 ( V_2 , V_267 , true ) ;
F_222 ( V_2 , V_267 , V_237 -> V_140 ,
V_535 ) ;
}
} else if ( V_528 == V_531 &&
V_529 == V_536 ) {
V_2 -> V_537 = true ;
F_220 ( V_2 , V_267 , V_237 -> V_140 ) ;
V_47 = 0 ;
} else if ( V_528 == V_536 &&
V_529 == V_538 ) {
if ( V_267 -> type == V_119 ) {
V_301 -> V_474 ++ ;
F_164 ( V_2 , V_267 , false , NULL ) ;
}
V_47 = F_228 ( V_2 , V_267 , V_237 ) ;
if ( V_47 == 0 )
F_229 ( V_2 , V_237 ,
V_301 -> V_306 -> V_539 -> V_540 ,
true ) ;
} else if ( V_528 == V_538 &&
V_529 == V_541 ) {
if ( F_193 ( V_2 ) > 1 )
F_110 ( V_2 ) ;
if ( V_237 -> V_532 )
F_222 ( V_2 , V_267 , V_237 -> V_140 ,
V_542 ) ;
F_8 ( F_188 ( V_2 , V_267 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_528 == V_541 &&
V_529 == V_538 ) {
F_8 ( F_135 ( V_2 , V_267 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_528 == V_538 &&
V_529 == V_536 ) {
if ( V_267 -> type == V_119 ) {
V_301 -> V_474 -- ;
F_164 ( V_2 , V_267 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_528 == V_536 &&
V_529 == V_531 ) {
V_47 = 0 ;
} else if ( V_528 == V_531 &&
V_529 == V_530 ) {
V_47 = F_230 ( V_2 , V_267 , V_237 ) ;
if ( V_237 -> V_532 ) {
F_227 ( V_2 , V_267 , false ) ;
F_222 ( V_2 , V_267 , V_237 -> V_140 ,
V_543 ) ;
}
} else {
V_47 = - V_17 ;
}
V_357:
F_89 ( & V_2 -> V_33 ) ;
if ( V_237 -> V_532 && V_47 == 0 ) {
if ( V_528 == V_530 &&
V_529 == V_531 )
F_231 ( V_237 , V_544 ) ;
else if ( V_528 == V_531 &&
V_529 == V_530 )
F_232 ( V_237 , V_544 ) ;
}
return V_47 ;
}
static int F_233 ( struct V_29 * V_30 , T_1 V_545 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_195 = V_545 ;
return 0 ;
}
static void F_234 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_236 * V_237 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_267 -> type == V_117 &&
V_27 & V_546 )
F_181 ( V_2 , V_267 , false ) ;
}
static int F_235 ( struct V_29 * V_30 ,
struct V_266 * V_267 , V_115 V_547 ,
const struct V_548 * V_289 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
V_301 -> V_549 [ V_547 ] = * V_289 ;
if ( V_267 -> type == V_121 ) {
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_164 ( V_2 , V_267 , false , NULL ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_236 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_550 = V_551 ;
T_1 V_552 = V_553 ;
if ( F_15 ( V_267 -> V_379 . V_380 ) )
return;
if ( F_12 ( V_2 , V_554 ) )
return;
F_83 ( & V_2 -> V_33 ) ;
F_180 ( V_2 , V_267 , V_550 , V_552 , 500 , false ) ;
F_89 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_554 ) ;
}
static int F_237 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_555 * V_494 ,
struct V_556 * V_496 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
if ( ! V_267 -> V_379 . V_490 ) {
V_47 = - V_534 ;
goto V_34;
}
V_47 = F_238 ( V_2 , V_267 , V_494 , V_496 , V_491 ) ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_239 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_312 & V_491 ) ) {
F_89 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_201 ( V_2 , V_491 , false ) ;
F_89 ( & V_2 -> V_33 ) ;
F_240 ( V_2 ) ;
return V_47 ;
}
static int F_241 ( struct V_29 * V_30 ,
enum V_557 V_343 ,
struct V_266 * V_267 ,
struct V_236 * V_237 ,
struct V_558 * V_559 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_111 * V_240 ;
struct V_560 * V_561 ;
int V_562 = V_559 -> V_562 ;
int V_47 ;
T_2 V_563 ;
if ( V_97 . V_98 ) {
F_161 ( V_2 , L_41 ) ;
return - V_564 ;
}
switch ( V_559 -> V_102 ) {
case V_54 :
V_559 -> V_95 |= V_565 ;
V_559 -> V_95 |= V_566 ;
break;
case V_55 :
V_559 -> V_95 |= V_566 ;
break;
case V_100 :
F_15 ( ! F_242 ( V_30 , V_99 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_267 -> type != V_117 )
return 0 ;
break;
default:
if ( V_30 -> V_103 &&
V_30 -> V_104 -> V_102 == V_559 -> V_102 )
V_559 -> V_95 |= V_566 ;
else
return - V_564 ;
}
F_83 ( & V_2 -> V_33 ) ;
switch ( V_343 ) {
case V_567 :
if ( ( V_267 -> type == V_122 ||
V_267 -> type == V_119 ) && ! V_237 ) {
if ( V_559 -> V_102 == V_100 )
V_47 = - V_564 ;
else
V_47 = 0 ;
V_559 -> V_568 = V_569 ;
break;
}
if ( F_14 ( V_329 , & V_2 -> V_15 ) &&
V_559 -> V_568 == V_569 ) {
F_161 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_329 , & V_2 -> V_15 ) &&
V_237 && F_243 ( V_2 ) &&
V_559 -> V_95 & V_570 &&
( V_559 -> V_102 == V_55 ||
V_559 -> V_102 == V_571 ) ) {
struct V_572 V_573 ;
int V_268 , V_574 ;
V_240 = F_58 ( V_237 ) ;
F_8 ( F_196 ( V_240 -> V_561 [ V_562 ] ) ) ;
V_561 = F_159 ( sizeof( * V_561 ) +
V_2 -> V_7 -> V_575 *
sizeof( V_561 -> V_574 [ 0 ] ) ,
V_576 ) ;
if ( ! V_561 ) {
V_47 = - V_577 ;
break;
}
for ( V_268 = 0 ; V_268 < V_506 ; V_268 ++ ) {
F_244 ( V_559 , V_268 , & V_573 ) ;
for ( V_574 = 0 ; V_574 < V_2 -> V_7 -> V_575 ; V_574 ++ )
memcpy ( V_561 -> V_574 [ V_574 ] . V_578 [ V_268 ] ,
V_573 . V_579 . V_578 ,
V_580 ) ;
}
F_218 ( V_240 -> V_561 [ V_562 ] , V_561 ) ;
}
if ( F_14 ( V_329 , & V_2 -> V_15 ) )
V_563 = V_559 -> V_568 ;
else
V_563 = V_569 ;
F_161 ( V_2 , L_43 ) ;
V_47 = F_245 ( V_2 , V_267 , V_237 , V_559 , V_563 ) ;
if ( V_47 ) {
F_199 ( V_2 , L_44 ) ;
V_559 -> V_568 = V_569 ;
V_47 = 0 ;
}
break;
case V_581 :
if ( V_559 -> V_568 == V_569 ) {
V_47 = 0 ;
break;
}
if ( V_237 && F_243 ( V_2 ) &&
V_559 -> V_95 & V_570 &&
( V_559 -> V_102 == V_55 ||
V_559 -> V_102 == V_571 ) ) {
V_240 = F_58 ( V_237 ) ;
V_561 = F_246 (
V_240 -> V_561 [ V_562 ] ,
F_247 ( & V_2 -> V_33 ) ) ;
F_197 ( V_240 -> V_561 [ V_562 ] , NULL ) ;
if ( V_561 )
F_248 ( V_561 , V_582 ) ;
}
F_161 ( V_2 , L_45 ) ;
V_47 = F_249 ( V_2 , V_267 , V_237 , V_559 ) ;
break;
default:
V_47 = - V_299 ;
}
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_250 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_558 * V_583 ,
struct V_236 * V_237 ,
T_1 V_584 , V_115 * V_585 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_583 -> V_568 == V_569 )
return;
F_251 ( V_2 , V_267 , V_583 , V_237 , V_584 , V_585 ) ;
}
static bool F_252 ( struct V_586 * V_587 ,
struct V_447 * V_448 , void * V_254 )
{
struct V_1 * V_2 =
F_253 ( V_587 , struct V_1 , V_587 ) ;
struct V_588 * V_32 ;
int V_589 = F_254 ( V_448 ) ;
struct V_590 * V_591 = V_254 ;
if ( F_8 ( V_448 -> V_253 . V_343 != V_592 ) )
return true ;
if ( F_15 ( V_589 != sizeof( * V_32 ) ) ) {
F_109 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_448 -> V_254 ;
F_255 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_593 ) ;
V_591 -> V_594 = F_256 ( V_32 -> V_593 ) ;
F_255 ( V_2 , L_48 ,
V_591 -> V_594 ) ;
F_4 ( & V_2 -> V_304 ) ;
F_257 ( & V_591 -> V_595 , & V_2 -> V_596 ) ;
F_5 ( & V_2 -> V_304 ) ;
return true ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_597 * V_539 ,
struct V_266 * V_267 ,
int V_550 )
{
int V_598 , V_599 = V_600 ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
struct V_590 * V_591 = & V_301 -> V_601 ;
static const V_115 V_602 [] = { V_592 } ;
struct V_603 V_604 ;
T_1 V_605 = V_267 -> V_379 . V_606 *
V_267 -> V_379 . V_455 ;
T_1 V_607 , V_608 ;
struct V_609 V_610 = {
. V_271 = F_126 ( V_611 ) ,
. V_612 =
F_126 ( F_259 ( V_613 , 0 ) ) ,
. V_614 = F_126 ( V_2 -> V_615 . V_243 ) ,
. V_616 . V_540 = ( V_539 -> V_540 == V_157 ) ?
V_617 : V_618 ,
. V_616 . V_539 = V_539 -> V_619 ,
. V_616 . V_620 = V_621 ,
. V_622 = F_126 ( F_260 ( V_2 -> V_7 , V_599 ) ) ,
} ;
V_608 = V_623 ;
V_607 = F_261 ( V_550 ) ;
if ( V_267 -> V_379 . V_380 ) {
V_608 = F_262 ( T_1 , V_605 * 3 , V_624 ) ;
if ( V_605 <= V_607 ) {
V_607 = V_605 - V_625 ;
if ( V_607 <= V_626 )
V_607 = V_605 -
V_627 ;
}
}
V_610 . V_550 = F_126 ( V_607 ) ;
V_610 . V_628 = F_126 ( V_608 ) ;
F_255 ( V_2 ,
L_49 ,
V_539 -> V_619 , V_607 , V_550 , V_608 ,
V_605 ) ;
memcpy ( V_610 . V_629 , V_267 -> V_140 , V_143 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_304 ) ;
if ( F_8 ( V_591 -> V_20 == V_592 ) ) {
F_5 ( & V_2 -> V_304 ) ;
return - V_17 ;
}
V_591 -> V_267 = V_267 ;
V_591 -> V_550 = V_550 ;
V_591 -> V_20 = V_592 ;
F_5 ( & V_2 -> V_304 ) ;
F_263 ( & V_2 -> V_587 , & V_604 ,
V_602 ,
F_40 ( V_602 ) ,
F_252 , V_591 ) ;
V_598 = F_128 ( V_2 , V_592 , 0 , sizeof( V_610 ) ,
& V_610 ) ;
if ( V_598 ) {
F_109 ( V_2 , L_50 , V_598 ) ;
F_264 ( & V_2 -> V_587 , & V_604 ) ;
goto V_630;
}
V_598 = F_265 ( & V_2 -> V_587 , & V_604 , 1 ) ;
F_15 ( V_598 ) ;
if ( V_598 ) {
V_630:
F_4 ( & V_2 -> V_304 ) ;
F_92 ( V_2 , V_591 ) ;
F_5 ( & V_2 -> V_304 ) ;
}
return V_598 ;
}
static int F_266 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_597 * V_539 ,
int V_550 ,
enum V_631 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
struct V_632 V_633 ;
struct V_340 * V_306 ;
int V_47 , V_9 ;
F_161 ( V_2 , L_51 , V_539 -> V_619 ,
V_550 , type ) ;
F_116 ( & V_2 -> V_335 ) ;
F_83 ( & V_2 -> V_33 ) ;
switch ( V_267 -> type ) {
case V_117 :
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_634 ) ) {
V_47 = F_258 ( V_2 , V_539 ,
V_267 , V_550 ) ;
goto V_357;
}
F_109 ( V_2 , L_52 ) ;
V_47 = - V_299 ;
goto V_357;
case V_121 :
break;
default:
F_109 ( V_2 , L_53 , V_267 -> type ) ;
V_47 = - V_299 ;
goto V_357;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_306 = & V_2 -> V_18 [ V_9 ] ;
if ( V_306 -> V_21 == 0 || V_301 -> V_306 == V_306 )
continue;
if ( V_306 -> V_21 && V_539 == V_306 -> V_539 ) {
V_47 = F_139 ( V_2 , V_267 ) ;
if ( F_267 ( V_47 , L_54 ) )
goto V_357;
F_140 ( V_2 , V_301 -> V_306 ) ;
V_301 -> V_306 = V_306 ;
V_47 = F_137 ( V_2 , V_267 ) ;
if ( F_267 ( V_47 , L_55 ) )
goto V_357;
F_136 ( V_2 , V_301 -> V_306 ) ;
goto V_635;
}
}
if ( V_539 == V_301 -> V_306 -> V_539 )
goto V_635;
F_268 ( & V_633 , V_539 , V_636 ) ;
if ( V_301 -> V_306 -> V_21 == 1 ) {
V_47 = F_269 ( V_2 , V_301 -> V_306 ,
& V_633 , 1 , 1 ) ;
if ( V_47 )
goto V_357;
} else {
V_306 = F_124 ( V_2 ) ;
if ( ! V_306 ) {
V_47 = - V_365 ;
goto V_357;
}
V_47 = F_269 ( V_2 , V_306 , & V_633 ,
1 , 1 ) ;
if ( V_47 ) {
F_109 ( V_2 , L_56 ) ;
goto V_357;
}
V_47 = F_139 ( V_2 , V_267 ) ;
if ( F_267 ( V_47 , L_54 ) )
goto V_357;
F_140 ( V_2 , V_301 -> V_306 ) ;
V_301 -> V_306 = V_306 ;
V_47 = F_137 ( V_2 , V_267 ) ;
if ( F_267 ( V_47 , L_55 ) )
goto V_357;
F_136 ( V_2 , V_301 -> V_306 ) ;
}
V_635:
V_47 = F_270 ( V_2 , V_267 , V_550 , type ) ;
V_357:
F_89 ( & V_2 -> V_33 ) ;
F_161 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_271 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_161 ( V_2 , L_58 ) ;
F_83 ( & V_2 -> V_33 ) ;
F_272 ( V_2 ) ;
F_89 ( & V_2 -> V_33 ) ;
F_161 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_273 ( struct V_1 * V_2 ,
struct V_637 * V_638 )
{
V_115 * V_639 = ( V_115 * ) V_638 -> V_640 ;
struct V_340 * V_306 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_161 ( V_2 , L_59 ) ;
V_306 = F_124 ( V_2 ) ;
if ( ! V_306 ) {
V_47 = - V_365 ;
goto V_34;
}
V_47 = F_269 ( V_2 , V_306 , & V_638 -> V_641 ,
V_638 -> V_642 ,
V_638 -> V_643 ) ;
if ( V_47 ) {
F_109 ( V_2 , L_60 ) ;
goto V_34;
}
F_136 ( V_2 , V_306 ) ;
* V_639 = V_306 -> V_20 ;
V_34:
return V_47 ;
}
static int F_274 ( struct V_29 * V_30 ,
struct V_637 * V_638 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_273 ( V_2 , V_638 ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_275 ( struct V_1 * V_2 ,
struct V_637 * V_638 )
{
V_115 * V_639 = ( V_115 * ) V_638 -> V_640 ;
struct V_340 * V_306 = & V_2 -> V_18 [ * V_639 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_140 ( V_2 , V_306 ) ;
}
static void F_276 ( struct V_29 * V_30 ,
struct V_637 * V_638 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_83 ( & V_2 -> V_33 ) ;
F_275 ( V_2 , V_638 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static void F_277 ( struct V_29 * V_30 ,
struct V_637 * V_638 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_115 * V_639 = ( V_115 * ) V_638 -> V_640 ;
struct V_340 * V_306 = & V_2 -> V_18 [ * V_639 ] ;
if ( F_113 ( ( V_306 -> V_21 > 1 ) &&
( V_27 & ~ ( V_644 |
V_645 |
V_646 |
V_647 ) ) ,
L_61 ,
V_306 -> V_21 , V_27 ) )
return;
F_83 ( & V_2 -> V_33 ) ;
F_185 ( V_2 ) ;
F_269 ( V_2 , V_306 , & V_638 -> V_641 ,
V_638 -> V_642 ,
V_638 -> V_643 ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static int F_278 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
struct V_637 * V_638 ,
bool V_648 )
{
V_115 * V_639 = ( V_115 * ) V_638 -> V_640 ;
struct V_340 * V_306 = & V_2 -> V_18 [ * V_639 ] ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_301 -> V_306 = V_306 ;
switch ( V_267 -> type ) {
case V_119 :
if ( V_648 ) {
V_301 -> V_476 = true ;
break;
}
case V_122 :
V_47 = 0 ;
goto V_34;
case V_117 :
break;
case V_649 :
V_301 -> V_313 = true ;
break;
default:
V_47 = - V_299 ;
goto V_34;
}
V_47 = F_137 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_34;
F_134 ( V_2 ) ;
if ( V_267 -> type == V_649 ) {
V_301 -> V_650 = true ;
V_47 = F_108 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_651;
V_47 = F_279 ( V_2 , V_267 ) ;
if ( V_47 )
goto V_651;
}
if ( V_267 -> type == V_119 ) {
F_108 ( V_2 , false , NULL ) ;
F_164 ( V_2 , V_267 , false , NULL ) ;
}
if ( V_648 && V_267 -> type == V_117 ) {
T_1 V_550 = 2 * V_267 -> V_379 . V_455 ;
V_47 = F_12 ( V_2 , V_652 ) ;
if ( V_47 )
goto V_651;
F_180 ( V_2 , V_267 , V_550 , V_550 ,
V_267 -> V_379 . V_455 / 2 ,
true ) ;
F_7 ( V_2 , V_652 ) ;
F_108 ( V_2 , false , NULL ) ;
}
goto V_34;
V_651:
F_139 ( V_2 , V_267 ) ;
F_134 ( V_2 ) ;
V_34:
if ( V_47 )
V_301 -> V_306 = NULL ;
return V_47 ;
}
static int F_280 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_637 * V_638 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_47 = F_278 ( V_2 , V_267 , V_638 , false ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_281 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
struct V_637 * V_638 ,
bool V_648 )
{
struct V_113 * V_301 = F_91 ( V_267 ) ;
struct V_266 * V_653 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_187 ( V_2 , V_301 , & V_301 -> V_305 ) ;
switch ( V_267 -> type ) {
case V_122 :
goto V_34;
case V_649 :
V_301 -> V_650 = false ;
V_301 -> V_313 = false ;
F_282 ( V_2 , V_267 ) ;
break;
case V_119 :
if ( ! V_648 || ! V_301 -> V_476 )
goto V_34;
V_301 -> V_480 = false ;
F_283 ( V_2 , V_301 , true ) ;
F_218 ( V_2 -> V_481 , V_267 ) ;
V_301 -> V_476 = false ;
break;
case V_117 :
if ( ! V_648 )
break;
V_653 = V_267 ;
F_164 ( V_2 , V_267 , true , NULL ) ;
break;
default:
break;
}
F_108 ( V_2 , false , V_653 ) ;
F_139 ( V_2 , V_267 ) ;
V_34:
V_301 -> V_306 = NULL ;
F_134 ( V_2 ) ;
}
static void F_284 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_637 * V_638 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_83 ( & V_2 -> V_33 ) ;
F_281 ( V_2 , V_267 , V_638 , false ) ;
F_89 ( & V_2 -> V_33 ) ;
}
static int
F_285 ( struct V_1 * V_2 ,
struct V_654 * V_655 )
{
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
F_281 ( V_2 , V_655 [ 0 ] . V_267 , V_655 [ 0 ] . V_656 , true ) ;
F_275 ( V_2 , V_655 [ 0 ] . V_656 ) ;
V_47 = F_273 ( V_2 , V_655 [ 0 ] . V_657 ) ;
if ( V_47 ) {
F_109 ( V_2 , L_62 ) ;
goto V_658;
}
V_47 = F_278 ( V_2 , V_655 [ 0 ] . V_267 , V_655 [ 0 ] . V_657 ,
true ) ;
if ( V_47 ) {
F_109 ( V_2 ,
L_63 ) ;
goto V_475;
}
if ( F_193 ( V_2 ) > 1 )
F_110 ( V_2 ) ;
goto V_34;
V_475:
F_275 ( V_2 , V_655 [ 0 ] . V_657 ) ;
V_658:
if ( F_273 ( V_2 , V_655 [ 0 ] . V_656 ) ) {
F_109 ( V_2 , L_64 ) ;
goto V_659;
}
if ( F_278 ( V_2 , V_655 [ 0 ] . V_267 , V_655 [ 0 ] . V_656 ,
true ) ) {
F_109 ( V_2 , L_65 ) ;
goto V_659;
}
goto V_34;
V_659:
F_286 ( V_2 , false ) ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_287 ( struct V_1 * V_2 ,
struct V_654 * V_655 )
{
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
F_281 ( V_2 , V_655 [ 0 ] . V_267 , V_655 [ 0 ] . V_656 , true ) ;
V_47 = F_278 ( V_2 , V_655 [ 0 ] . V_267 , V_655 [ 0 ] . V_657 ,
true ) ;
if ( V_47 ) {
F_109 ( V_2 ,
L_63 ) ;
goto V_658;
}
goto V_34;
V_658:
if ( F_278 ( V_2 , V_655 [ 0 ] . V_267 , V_655 [ 0 ] . V_656 ,
true ) ) {
F_109 ( V_2 , L_65 ) ;
goto V_659;
}
goto V_34;
V_659:
F_286 ( V_2 , false ) ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_288 ( struct V_29 * V_30 ,
struct V_654 * V_655 ,
int V_660 ,
enum V_661 V_662 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_660 > 1 )
return - V_564 ;
switch ( V_662 ) {
case V_663 :
V_47 = F_285 ( V_2 , V_655 ) ;
break;
case V_664 :
V_47 = F_287 ( V_2 , V_655 ) ;
break;
default:
V_47 = - V_564 ;
break;
}
return V_47 ;
}
static int F_289 ( struct V_29 * V_30 ,
struct V_236 * V_237 ,
bool V_665 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_111 * V_514 = F_58 ( V_237 ) ;
if ( ! V_514 || ! V_514 -> V_267 ) {
F_109 ( V_2 , L_66 ) ;
return - V_299 ;
}
return F_191 ( V_2 , V_514 -> V_267 ) ;
}
static int F_290 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
void * V_254 , int V_202 )
{
struct V_666 * V_667 [ V_668 + 1 ] ;
int V_669 ;
T_1 V_372 ;
V_669 = F_291 ( V_667 , V_668 , V_254 , V_202 , V_670 ) ;
if ( V_669 )
return V_669 ;
if ( ! V_667 [ V_671 ] )
return - V_299 ;
switch ( F_292 ( V_667 [ V_671 ] ) ) {
case V_672 :
if ( ! V_267 || V_267 -> type != V_119 || ! V_267 -> V_361 ||
! V_267 -> V_379 . V_673 ||
! V_667 [ V_674 ] )
return - V_299 ;
V_372 = F_292 ( V_667 [ V_674 ] ) ;
if ( V_372 >= V_267 -> V_379 . V_455 )
return - V_299 ;
V_2 -> V_372 = V_372 ;
V_2 -> V_371 = V_267 ;
return F_108 ( V_2 , false , NULL ) ;
case V_675 :
if ( ! V_267 || V_267 -> type != V_117 ||
! V_267 -> V_379 . V_380 || ! V_267 -> V_379 . V_606 ||
! V_667 [ V_676 ] )
return - V_299 ;
if ( F_292 ( V_667 [ V_676 ] ) )
return F_188 ( V_2 , V_267 , 0 ) ;
return F_135 ( V_2 , V_267 , 0 ) ;
}
return - V_564 ;
}
static int F_293 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
void * V_254 , int V_202 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_669 ;
F_83 ( & V_2 -> V_33 ) ;
V_669 = F_290 ( V_2 , V_267 , V_254 , V_202 ) ;
F_89 ( & V_2 -> V_33 ) ;
return V_669 ;
}
static void F_294 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_677 * V_678 )
{
F_161 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_295 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_677 * V_678 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_266 * V_479 ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
T_1 V_622 ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
V_301 -> V_679 = false ;
F_161 ( V_2 , L_68 ,
V_678 -> V_633 . V_680 ) ;
F_296 ( V_2 , V_267 , V_681 ) ;
switch ( V_267 -> type ) {
case V_119 :
V_479 =
F_246 ( V_2 -> V_479 ,
F_247 ( & V_2 -> V_33 ) ) ;
if ( F_113 ( V_479 && V_479 -> V_682 ,
L_69 ) ) {
V_47 = - V_534 ;
goto V_357;
}
F_218 ( V_2 -> V_479 , V_267 ) ;
if ( F_113 ( V_301 -> V_480 ,
L_70 ) ) {
V_47 = - V_534 ;
goto V_357;
}
break;
case V_117 :
V_622 = V_678 -> V_683 +
( ( V_267 -> V_379 . V_455 * ( V_678 -> V_382 - 1 ) -
V_684 ) * 1024 ) ;
if ( V_678 -> V_685 )
F_297 ( V_2 , V_267 ) ;
F_298 ( V_2 , V_267 , V_267 -> V_379 . V_455 ,
V_622 ) ;
if ( V_301 -> V_307 . V_471 ) {
V_47 = F_135 ( V_2 , V_267 , 0 ) ;
if ( V_47 )
goto V_357;
}
break;
default:
break;
}
V_301 -> V_313 = true ;
V_47 = F_299 ( V_2 ) ;
if ( V_47 )
goto V_357;
F_110 ( V_2 ) ;
V_357:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_300 ( struct V_29 * V_30 ,
struct V_266 * V_267 )
{
struct V_113 * V_301 = F_91 ( V_267 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_301 -> V_679 ) {
V_301 -> V_679 = false ;
V_47 = - V_17 ;
goto V_357;
}
if ( V_267 -> type == V_117 ) {
struct V_111 * V_240 ;
V_240 = F_301 ( V_2 ,
V_301 -> V_303 ) ;
if ( F_8 ( ! V_240 ) ) {
V_47 = - V_17 ;
goto V_357;
}
F_302 ( V_2 , V_240 , false ) ;
F_164 ( V_2 , V_267 , false , NULL ) ;
V_47 = F_188 ( V_2 , V_267 , 0 ) ;
if ( V_47 )
goto V_357;
F_303 ( V_2 , V_267 ) ;
}
V_301 -> V_313 = false ;
V_47 = F_299 ( V_2 ) ;
V_357:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_304 ( struct V_29 * V_30 ,
struct V_266 * V_267 , T_1 V_75 , bool V_255 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 ;
struct V_111 * V_240 ;
struct V_236 * V_237 ;
int V_9 ;
T_1 V_686 = 0 ;
if ( ! V_267 || V_267 -> type != V_117 )
return;
F_83 ( & V_2 -> V_33 ) ;
V_301 = F_91 ( V_267 ) ;
for ( V_9 = 0 ; V_9 < V_244 ; V_9 ++ ) {
V_237 = F_246 ( V_2 -> V_515 [ V_9 ] ,
F_247 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_237 ) )
continue;
V_240 = F_58 ( V_237 ) ;
if ( V_240 -> V_267 != V_267 )
continue;
F_8 ( V_9 != V_301 -> V_303 && ! V_237 -> V_532 ) ;
V_686 |= V_240 -> V_687 ;
}
if ( V_255 ) {
if ( F_145 ( V_2 , V_686 , 0 ) )
F_109 ( V_2 , L_71 ) ;
F_89 ( & V_2 -> V_33 ) ;
} else {
F_89 ( & V_2 -> V_33 ) ;
F_146 ( V_2 -> V_7 , V_686 ) ;
}
}
static int F_305 ( struct V_29 * V_30 , int V_688 ,
struct V_689 * V_690 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_690 , 0 , sizeof( * V_690 ) ) ;
if ( V_688 != 0 )
return - V_49 ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_691 ) )
return - V_49 ;
F_83 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_692 ) {
V_47 = F_179 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_690 -> V_693 = V_694 |
V_695 |
V_696 |
V_697 ;
V_690 -> time = V_2 -> V_334 . V_698 +
V_2 -> V_699 . V_698 ;
F_306 ( V_690 -> time , V_700 ) ;
V_690 -> V_701 = V_2 -> V_334 . V_702 +
V_2 -> V_699 . V_702 ;
F_306 ( V_690 -> V_701 , V_700 ) ;
V_690 -> V_703 = V_2 -> V_334 . V_704 +
V_2 -> V_699 . V_704 ;
F_306 ( V_690 -> V_703 , V_700 ) ;
V_690 -> V_705 = V_2 -> V_334 . V_706 +
V_2 -> V_699 . V_706 ;
F_306 ( V_690 -> V_705 , V_700 ) ;
V_47 = 0 ;
V_34:
F_89 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_307 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
struct V_236 * V_237 ,
struct V_707 * V_708 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_113 * V_301 = F_91 ( V_267 ) ;
struct V_111 * V_240 = F_58 ( V_237 ) ;
if ( F_45 ( & V_2 -> V_93 -> V_94 ,
V_691 ) )
return;
if ( ! ( V_267 -> V_362 & V_363 ) )
return;
if ( ! V_267 -> V_379 . V_380 )
return;
F_83 ( & V_2 -> V_33 ) ;
if ( V_301 -> V_303 != V_240 -> V_243 )
goto V_709;
if ( F_179 ( V_2 , false ) )
goto V_709;
V_708 -> V_710 = V_301 -> V_354 . V_356 +
V_301 -> V_354 . V_355 ;
V_708 -> V_693 |= F_41 ( V_711 ) ;
if ( V_301 -> V_354 . V_712 ) {
V_708 -> V_713 = V_301 -> V_354 . V_712 ;
V_708 -> V_693 |= F_41 ( V_714 ) ;
}
V_709:
F_89 ( & V_2 -> V_33 ) ;
}
static void F_308 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
const struct V_715 * V_716 )
{
#define F_309 ( T_5 , T_6 , T_7 , T_8 , T_9 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_272 * V_273 ;
struct V_717 * V_718 ;
if ( ! F_77 ( V_2 -> V_93 , V_719 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_719 ) ;
V_718 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
if ( V_716 -> V_720 . V_721 . V_254 == V_722 ) {
if ( V_716 -> V_720 . V_721 . V_15 == V_723 )
F_309 ( V_2 , V_273 , V_724 ,
V_718 -> V_725 ,
L_72 ,
V_716 -> V_720 . V_721 . V_501 ) ;
else if ( V_716 -> V_720 . V_721 . V_15 == V_726 )
F_309 ( V_2 , V_273 , V_724 ,
V_718 -> V_727 ,
L_73 ) ;
} else if ( V_716 -> V_720 . V_721 . V_254 == V_728 ) {
if ( V_716 -> V_720 . V_721 . V_15 == V_723 )
F_309 ( V_2 , V_273 , V_724 ,
V_718 -> V_729 ,
L_74 ,
V_716 -> V_720 . V_721 . V_501 ) ;
else if ( V_716 -> V_720 . V_721 . V_15 == V_726 )
F_309 ( V_2 , V_273 , V_724 ,
V_718 -> V_730 ,
L_75 ) ;
} else if ( V_716 -> V_720 . V_721 . V_254 == V_731 ) {
F_309 ( V_2 , V_273 , V_724 ,
V_718 -> V_732 ,
L_76 , V_716 -> V_720 . V_721 . V_501 ) ;
} else if ( V_716 -> V_720 . V_721 . V_254 == V_733 ) {
F_309 ( V_2 , V_273 , V_724 ,
V_718 -> V_734 ,
L_77 , V_716 -> V_720 . V_721 . V_501 ) ;
}
#undef F_309
}
static void F_310 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
const struct V_715 * V_716 )
{
struct V_272 * V_273 ;
struct V_274 * V_275 ;
if ( ! F_77 ( V_2 -> V_93 , V_276 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_276 ) ;
V_275 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
if ( ! ( F_311 ( V_275 -> V_735 ) & F_41 ( V_716 -> V_720 . V_736 . V_268 ) ) )
return;
F_223 ( V_2 , V_273 ,
L_78 ,
V_716 -> V_720 . V_736 . V_237 -> V_140 , V_716 -> V_720 . V_736 . V_268 ,
V_716 -> V_720 . V_736 . V_281 ) ;
}
static void
F_312 ( struct V_1 * V_2 ,
struct V_266 * V_267 ,
const struct V_715 * V_716 )
{
struct V_272 * V_273 ;
struct V_274 * V_275 ;
if ( ! F_77 ( V_2 -> V_93 , V_276 ) )
return;
V_273 = F_78 ( V_2 -> V_93 , V_276 ) ;
V_275 = ( void * ) V_273 -> V_254 ;
if ( ! F_79 ( V_2 , V_267 , V_273 ) )
return;
if ( ! ( F_311 ( V_275 -> V_737 ) & F_41 ( V_716 -> V_720 . V_736 . V_268 ) ) )
return;
F_223 ( V_2 , V_273 ,
L_79 ,
V_716 -> V_720 . V_736 . V_237 -> V_140 , V_716 -> V_720 . V_736 . V_268 ) ;
}
static void F_313 ( struct V_29 * V_30 ,
struct V_266 * V_267 ,
const struct V_715 * V_716 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_716 -> type ) {
case V_738 :
F_308 ( V_2 , V_267 , V_716 ) ;
break;
case V_739 :
F_310 ( V_2 , V_267 , V_716 ) ;
break;
case V_740 :
F_312 ( V_2 , V_267 , V_716 ) ;
break;
default:
break;
}
}
