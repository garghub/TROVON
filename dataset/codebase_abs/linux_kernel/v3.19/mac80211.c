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
int F_17 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_24 , V_25 , V_9 ;
V_23 -> V_26 = V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 |
V_37 |
V_38 ;
V_23 -> V_39 = V_2 -> V_40 ;
V_23 -> V_41 = V_42 ;
V_23 -> V_43 |= V_44 |
V_45 ;
V_23 -> V_46 |= V_47 |
V_48 ;
V_23 -> V_49 = L_4 ;
if ( V_2 -> V_50 -> V_51 . V_26 & V_52 &&
! V_53 . V_54 )
V_23 -> V_26 |= V_55 ;
if ( V_2 -> V_50 -> V_51 . V_26 & V_56 &&
! V_53 . V_57 ) {
V_23 -> V_26 |= V_58 ;
V_23 -> V_59 = V_60 ;
V_23 -> V_61 = V_62 ;
}
if ( V_2 -> V_50 -> V_51 . V_63 [ 0 ] & V_64 ||
V_2 -> V_50 -> V_51 . V_65 [ 0 ] & V_66 ) {
V_23 -> V_26 |= V_67 ;
V_23 -> V_68 -> V_69 |=
V_70 |
V_71 ;
}
V_23 -> V_72 = sizeof( struct V_73 ) ;
V_23 -> V_74 = sizeof( struct V_75 ) ;
V_23 -> V_76 = sizeof( V_77 ) ;
V_23 -> V_68 -> V_78 = F_18 ( V_79 ) |
F_18 ( V_80 ) |
F_18 ( V_81 ) |
F_18 ( V_82 ) |
F_18 ( V_83 ) |
F_18 ( V_84 ) ;
V_23 -> V_68 -> V_26 |= V_85 ;
V_23 -> V_68 -> V_86 |= V_87 |
V_88 ;
if ( V_2 -> V_50 -> V_51 . V_26 & V_89 )
V_23 -> V_68 -> V_26 |= V_90 ;
V_23 -> V_68 -> V_26 |= V_91 ;
V_23 -> V_68 -> V_92 = V_93 ;
V_23 -> V_68 -> V_94 =
F_19 ( V_93 ) ;
V_23 -> V_68 -> V_95 = 10000 ;
V_23 -> V_96 = V_97 ;
memcpy ( V_2 -> V_98 [ 0 ] . V_99 , V_2 -> V_100 -> V_101 , V_102 ) ;
V_23 -> V_68 -> V_98 = V_2 -> V_98 ;
V_23 -> V_68 -> V_103 = 1 ;
V_24 = ( V_2 -> V_100 -> V_104 > 1 ) ?
F_20 ( V_105 , V_2 -> V_100 -> V_104 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_24 ; V_9 ++ ) {
memcpy ( V_2 -> V_98 [ V_9 ] . V_99 , V_2 -> V_98 [ V_9 - 1 ] . V_99 ,
V_102 ) ;
V_2 -> V_98 [ V_9 ] . V_99 [ 5 ] ++ ;
V_23 -> V_68 -> V_103 ++ ;
}
F_16 ( V_2 ) ;
V_23 -> V_68 -> V_106 = F_21 ( V_2 , false ) ;
V_23 -> V_68 -> V_107 = V_108 ;
if ( V_2 -> V_100 -> V_109 [ V_110 ] . V_111 )
V_23 -> V_68 -> V_109 [ V_110 ] =
& V_2 -> V_100 -> V_109 [ V_110 ] ;
if ( V_2 -> V_100 -> V_109 [ V_112 ] . V_111 )
V_23 -> V_68 -> V_109 [ V_112 ] =
& V_2 -> V_100 -> V_109 [ V_112 ] ;
V_23 -> V_68 -> V_113 = V_2 -> V_7 -> V_114 ;
if ( V_115 . V_116 != V_117 )
V_23 -> V_68 -> V_26 |= V_118 ;
else
V_23 -> V_68 -> V_26 &= ~ V_118 ;
if ( F_22 ( V_2 -> V_50 -> V_119 ) >= 10 ) {
V_23 -> V_68 -> V_26 |= V_120 ;
V_23 -> V_68 -> V_121 = V_108 ;
V_23 -> V_68 -> V_122 = V_123 ;
V_23 -> V_68 -> V_124 =
V_125 - 24 - 2 ;
}
V_23 -> V_68 -> V_69 |= V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 ;
if ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] &
V_132 )
V_23 -> V_68 -> V_69 |= V_133 ;
if ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] &
V_134 )
V_23 -> V_68 -> V_69 |= V_135 ;
if ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] &
V_136 )
V_23 -> V_68 -> V_69 |=
V_137 ;
if ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] &
V_138 )
V_23 -> V_68 -> V_69 |= V_139 ;
V_2 -> V_140 = V_141 ;
if ( V_2 -> V_50 -> V_142 [ 0 ] . V_143 ) {
V_2 -> V_23 -> V_144 = 1 ;
V_2 -> V_23 -> V_145 = & V_2 -> V_50 -> V_142 [ 0 ] ;
}
#ifdef F_23
if ( F_2 ( V_2 ) &&
F_24 ( V_2 -> V_7 -> V_146 ) ) {
V_2 -> V_147 . V_26 = V_148 ;
V_23 -> V_68 -> V_147 = & V_2 -> V_147 ;
} else if ( V_2 -> V_50 -> V_149 [ V_150 ] . V_151 [ 0 ] . V_152 &&
V_2 -> V_7 -> V_153 -> V_154 &&
V_2 -> V_7 -> V_153 -> V_155 &&
F_24 ( V_2 -> V_7 -> V_146 ) ) {
V_2 -> V_147 . V_26 = V_156 |
V_157 |
V_158 |
V_159 |
V_160 ;
if ( ! V_53 . V_54 )
V_2 -> V_147 . V_26 |= V_161 |
V_162 |
V_163 ;
V_2 -> V_147 . V_164 = V_165 ;
V_2 -> V_147 . V_166 = V_167 ;
V_2 -> V_147 . V_168 = V_169 ;
V_2 -> V_147 . V_170 = V_123 ;
V_2 -> V_147 . V_171 = & V_172 ;
V_23 -> V_68 -> V_147 = & V_2 -> V_147 ;
}
#endif
#ifdef F_25
V_2 -> V_173 = V_174 ;
#endif
V_25 = F_26 ( V_2 ) ;
if ( V_25 )
return V_25 ;
if ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] & V_175 ) {
F_27 ( V_2 , L_5 ) ;
V_23 -> V_68 -> V_26 |= V_176 ;
}
if ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] &
V_177 ) {
F_27 ( V_2 , L_6 ) ;
V_23 -> V_68 -> V_69 |= V_178 ;
}
V_25 = F_28 ( V_2 -> V_23 ) ;
if ( V_25 )
F_29 ( V_2 ) ;
return V_25 ;
}
static bool F_30 ( struct V_1 * V_2 ,
struct V_179 * V_180 ,
struct V_181 * V_182 )
{
struct V_73 * V_183 ;
bool V_184 = false ;
if ( F_31 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_32 ( & V_2 -> V_185 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_186;
V_183 = F_33 ( V_180 ) ;
if ( V_183 -> V_187 == V_188 ||
V_183 -> V_187 != V_2 -> V_189 )
goto V_186;
F_34 ( & V_2 -> V_190 , V_182 ) ;
F_35 ( V_2 -> V_23 ) ;
F_1 ( V_2 , V_191 ) ;
F_7 ( V_2 , V_191 ) ;
V_184 = true ;
V_186:
F_36 ( & V_2 -> V_185 ) ;
return V_184 ;
}
static void F_37 ( struct V_22 * V_23 ,
struct V_192 * V_193 ,
struct V_181 * V_182 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_179 * V_180 = V_193 -> V_180 ;
struct V_194 * V_195 = F_39 ( V_182 ) ;
struct V_196 * V_197 = ( void * ) V_182 -> V_198 ;
if ( F_40 ( V_2 ) ) {
F_41 ( V_2 , L_7 ) ;
goto V_199;
}
if ( F_39 ( V_182 ) -> V_200 == V_42 &&
! F_14 ( V_201 , & V_2 -> V_15 ) &&
! F_14 ( V_202 , & V_2 -> V_15 ) )
goto V_199;
if ( F_42 ( V_195 -> V_26 & V_203 &&
F_43 ( V_197 -> V_204 ) &&
! F_44 ( V_197 -> V_204 ) &&
! F_45 ( V_197 -> V_204 ) &&
! F_46 ( V_197 -> V_204 ) ) )
V_180 = NULL ;
if ( V_180 ) {
if ( F_30 ( V_2 , V_180 , V_182 ) )
return;
if ( F_47 ( V_2 , V_182 , V_180 ) )
goto V_199;
return;
}
if ( F_48 ( V_2 , V_182 ) )
goto V_199;
return;
V_199:
F_49 ( V_23 , V_182 ) ;
}
static inline bool F_50 ( const struct V_205 * V_206 )
{
if ( V_53 . V_207 & V_208 )
return false ;
return true ;
}
static inline bool F_51 ( const struct V_205 * V_206 )
{
if ( V_53 . V_207 & V_209 )
return false ;
if ( V_53 . V_207 & V_210 )
return true ;
return true ;
}
static int F_52 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
enum V_213 V_214 ,
struct V_179 * V_180 , V_77 V_215 ,
V_77 * V_216 , T_1 V_217 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
bool V_218 = false ;
F_53 ( V_2 , L_8 ,
V_180 -> V_99 , V_215 , V_214 ) ;
if ( ! ( V_2 -> V_100 -> V_219 ) )
return - V_220 ;
switch ( V_214 ) {
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
V_25 = F_12 ( V_2 , V_226 ) ;
if ( V_25 )
return V_25 ;
V_218 = true ;
break;
default:
break;
}
F_54 ( & V_2 -> V_227 ) ;
switch ( V_214 ) {
case V_228 :
if ( ! F_50 ( V_2 -> V_206 ) ) {
V_25 = - V_229 ;
break;
}
V_25 = F_55 ( V_2 , V_180 , V_215 , * V_216 , true ) ;
break;
case V_230 :
V_25 = F_55 ( V_2 , V_180 , V_215 , 0 , false ) ;
break;
case V_221 :
if ( ! F_51 ( V_2 -> V_206 ) ) {
V_25 = - V_229 ;
break;
}
V_25 = F_56 ( V_2 , V_212 , V_180 , V_215 , V_216 ) ;
break;
case V_222 :
V_25 = F_57 ( V_2 , V_212 , V_180 , V_215 ) ;
break;
case V_223 :
case V_224 :
V_25 = F_58 ( V_2 , V_212 , V_180 , V_215 ) ;
break;
case V_225 :
V_25 = F_59 ( V_2 , V_212 , V_180 , V_215 , V_217 ) ;
break;
default:
F_15 ( 1 ) ;
V_25 = - V_229 ;
break;
}
F_60 ( & V_2 -> V_227 ) ;
if ( V_218 )
F_7 ( V_2 , V_226 ) ;
return V_25 ;
}
static void F_61 ( void * V_198 , T_1 * V_231 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = V_198 ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
V_232 -> V_233 = false ;
V_232 -> V_234 = V_188 ;
V_232 -> V_235 ++ ;
F_4 ( & V_2 -> V_236 ) ;
F_63 ( V_2 , & V_232 -> V_237 ) ;
F_5 ( & V_2 -> V_236 ) ;
V_232 -> V_238 = NULL ;
memset ( & V_232 -> V_239 , 0 , sizeof( V_232 -> V_239 ) ) ;
}
static T_2 F_64 ( char * V_240 , T_3 V_241 , T_4 V_242 ,
const void * V_198 , T_4 V_243 )
{
const struct V_244 * V_245 = V_198 ;
T_2 V_246 ;
T_2 V_247 ;
if ( V_241 < V_245 -> V_248 ) {
V_246 = F_65 ( T_2 , V_242 ,
V_245 -> V_248 - V_241 ) ;
memcpy ( V_240 , ( T_1 * ) V_245 -> V_249 + V_241 ,
V_246 ) ;
V_241 += V_246 ;
V_242 -= V_246 ;
if ( V_242 == 0 )
return V_246 ;
} else {
V_246 = 0 ;
}
if ( ! V_245 -> V_250 )
return V_246 ;
V_241 -= V_245 -> V_248 ;
V_247 = F_65 ( T_2 , V_242 ,
V_245 -> V_250 -> V_152 - V_241 ) ;
memcpy ( V_240 + V_246 ,
( T_1 * ) V_245 -> V_250 -> V_198 + V_241 ,
V_247 ) ;
return V_246 + V_247 ;
}
static void F_66 ( const void * V_198 )
{
const struct V_244 * V_251 = V_198 ;
F_67 ( V_251 -> V_249 ) ;
F_67 ( V_251 -> V_250 ) ;
F_68 ( V_251 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_252 * V_253 ;
struct V_254 * V_255 ;
struct V_256 * V_257 ;
struct V_244 * V_251 ;
const struct V_258 * V_149 ;
T_5 V_259 , V_260 ;
T_5 V_261 , V_262 ;
unsigned long V_26 ;
int V_263 ;
F_70 ( & V_2 -> V_227 ) ;
V_251 = F_71 ( sizeof( * V_251 ) , V_264 ) ;
if ( ! V_251 )
return;
V_149 = & V_2 -> V_50 -> V_149 [ V_2 -> V_265 ] ;
V_260 = V_149 -> V_151 [ V_266 ] . V_241 ;
V_259 = V_149 -> V_151 [ V_266 ] . V_152 ;
V_263 = F_72 ( V_2 -> V_7 , V_267 ) ;
V_262 = ( V_263 & V_268 ) >> V_269 ;
V_262 = V_262 << 7 ;
V_261 = sizeof( * V_253 ) +
sizeof( * V_255 ) * 3 +
V_259 +
V_262 +
sizeof( * V_257 ) ;
V_253 = F_73 ( V_261 ) ;
if ( ! V_253 ) {
F_68 ( V_251 ) ;
return;
}
V_251 -> V_249 = V_253 ;
V_253 -> V_270 = F_74 ( V_271 ) ;
V_255 = ( void * ) V_253 -> V_198 ;
V_255 -> type = F_74 ( V_272 ) ;
V_255 -> V_152 = F_74 ( sizeof( * V_257 ) ) ;
V_257 = ( void * ) V_255 -> V_198 ;
V_257 -> V_273 =
V_2 -> V_206 -> V_273 == V_274 ?
F_74 ( V_275 ) :
F_74 ( V_276 ) ;
memcpy ( V_257 -> V_277 , V_2 -> V_50 -> V_278 ,
sizeof( V_257 -> V_277 ) ) ;
strncpy ( V_257 -> V_279 , V_2 -> V_206 -> V_280 ,
sizeof( V_257 -> V_279 ) ) ;
strncpy ( V_257 -> V_281 , V_2 -> V_146 -> V_282 -> V_280 ,
sizeof( V_257 -> V_281 ) ) ;
V_255 = F_75 ( V_255 ) ;
V_255 -> type = F_74 ( V_283 ) ;
V_255 -> V_152 = F_74 ( V_262 ) ;
if ( F_76 ( V_2 -> V_7 , false , & V_26 ) ) {
T_5 * V_284 = ( void * ) V_255 -> V_198 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < ( V_262 / sizeof( T_5 ) ) ; V_9 ++ ) {
F_77 ( V_2 -> V_7 ,
V_285 ,
V_9 * sizeof( T_5 ) ) ;
V_284 [ V_9 ] = F_72 ( V_2 -> V_7 ,
V_286 ) ;
}
F_78 ( V_2 -> V_7 , & V_26 ) ;
}
V_255 = F_75 ( V_255 ) ;
V_255 -> type = F_74 ( V_287 ) ;
V_255 -> V_152 = F_74 ( V_259 ) ;
F_79 ( V_2 -> V_7 , V_260 , V_255 -> V_198 ,
V_259 ) ;
V_251 -> V_250 = F_80 ( V_2 -> V_7 ) ;
V_251 -> V_248 = V_261 ;
if ( V_251 -> V_250 )
V_261 += V_251 -> V_250 -> V_152 ;
V_253 -> V_261 = F_74 ( V_261 ) ;
F_81 ( V_2 -> V_7 -> V_146 , V_288 , V_251 , 0 ,
V_264 , F_64 , F_66 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( ! F_83 ( V_289 , & V_2 -> V_15 ) )
F_69 ( V_2 ) ;
F_84 ( V_2 -> V_7 ) ;
V_2 -> V_290 = V_291 ;
V_2 -> V_292 = false ;
V_2 -> V_293 = false ;
F_85 ( V_2 -> V_23 ) ;
F_86 (
V_2 -> V_23 , V_294 ,
F_61 , V_2 ) ;
V_2 -> V_295 = NULL ;
V_2 -> V_189 = V_188 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_296 , 0 , sizeof( V_2 -> V_296 ) ) ;
memset ( V_2 -> V_297 , 0 , sizeof( V_2 -> V_297 ) ) ;
memset ( V_2 -> V_298 , 0 , sizeof( V_2 -> V_298 ) ) ;
memset ( & V_2 -> V_299 , 0 , sizeof( V_2 -> V_299 ) ) ;
memset ( & V_2 -> V_300 , 0 , sizeof( V_2 -> V_300 ) ) ;
memset ( & V_2 -> V_301 , 0 , sizeof( V_2 -> V_301 ) ) ;
memset ( & V_2 -> V_302 , 0 , sizeof( V_2 -> V_302 ) ) ;
memset ( & V_2 -> V_303 , 0 , sizeof( V_2 -> V_303 ) ) ;
memset ( & V_2 -> V_304 , 0 , sizeof( V_2 -> V_304 ) ) ;
F_87 ( V_2 -> V_23 ) ;
F_10 ( V_2 , V_305 ) ;
F_88 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_306 = 0 ;
V_2 -> V_307 = 0 ;
}
int F_89 ( struct V_1 * V_2 )
{
int V_25 ;
F_70 ( & V_2 -> V_227 ) ;
if ( F_14 ( V_308 , & V_2 -> V_15 ) )
F_82 ( V_2 ) ;
V_25 = F_90 ( V_2 ) ;
if ( V_25 && F_14 ( V_308 , & V_2 -> V_15 ) ) {
F_88 ( V_308 , & V_2 -> V_15 ) ;
F_91 ( V_2 , NULL ) ;
}
return V_25 ;
}
static int F_92 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
V_25 = F_89 ( V_2 ) ;
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static void F_93 ( struct V_1 * V_2 )
{
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
F_88 ( V_308 , & V_2 -> V_15 ) ;
F_91 ( V_2 , NULL ) ;
V_25 = F_94 ( V_2 , NULL ) ;
if ( V_25 )
F_95 ( V_2 , L_9 ,
V_25 ) ;
F_7 ( V_2 , V_305 ) ;
F_96 ( V_2 ) ;
F_60 ( & V_2 -> V_227 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
bool V_309 ;
if ( ! F_2 ( V_2 ) )
return;
F_54 ( & V_2 -> V_310 ) ;
F_98 ( V_311 , & V_2 -> V_312 ) ;
V_309 = F_99 ( V_313 ,
& V_2 -> V_312 ) ;
F_60 ( & V_2 -> V_310 ) ;
if ( V_309 ) {
F_3 ( V_2 , L_10 ) ;
F_100 ( V_2 ) ;
}
}
static void
F_101 ( struct V_22 * V_23 ,
enum V_314 V_315 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
switch ( V_315 ) {
case V_316 :
F_93 ( V_2 ) ;
break;
case V_317 :
F_97 ( V_2 ) ;
break;
}
}
void F_102 ( struct V_1 * V_2 )
{
F_70 ( & V_2 -> V_227 ) ;
if ( ! F_14 ( V_308 , & V_2 -> V_15 ) )
F_1 ( V_2 , V_305 ) ;
F_103 ( & V_2 -> V_318 ) ;
F_84 ( V_2 -> V_7 ) ;
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
F_88 ( V_308 , & V_2 -> V_15 ) ;
V_2 -> V_319 = false ;
}
static void F_106 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_107 ( & V_2 -> V_320 ) ;
F_107 ( & V_2 -> V_321 ) ;
F_107 ( & V_2 -> V_322 ) ;
F_54 ( & V_2 -> V_227 ) ;
F_102 ( V_2 ) ;
F_60 ( & V_2 -> V_227 ) ;
F_103 ( & V_2 -> V_321 ) ;
}
static struct V_323 * F_108 ( struct V_1 * V_2 )
{
V_77 V_9 ;
F_70 ( & V_2 -> V_227 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_95 ( V_2 , L_11 ) ;
return NULL ;
}
static int F_109 ( struct V_1 * V_2 , struct V_211 * V_212 ,
T_6 V_324 )
{
struct V_325 V_326 = {
. V_327 = F_62 ( V_212 ) -> V_20 ,
. V_328 = F_110 ( V_324 ) ,
} ;
return F_111 ( V_2 , V_329 , 0 ,
sizeof( V_326 ) ,
& V_326 ) ;
}
static int F_112 ( struct V_22 * V_23 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
int V_25 ;
V_25 = F_12 ( V_2 , V_330 ) ;
if ( V_25 )
return V_25 ;
F_54 ( & V_2 -> V_227 ) ;
V_25 = F_113 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_331;
if ( V_212 -> type != V_83 )
V_2 -> V_306 ++ ;
if ( V_212 -> type == V_81 ||
V_212 -> type == V_84 ) {
V_25 = F_114 ( V_2 , V_212 ) ;
if ( V_25 ) {
F_95 ( V_2 , L_12 ) ;
goto V_332;
}
F_115 ( V_2 , V_212 ) ;
goto V_331;
}
V_25 = F_116 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_332;
V_25 = F_117 ( V_2 ) ;
if ( V_25 )
goto V_332;
V_25 = F_118 ( V_2 , V_212 , 0 ) ;
if ( V_25 )
goto V_333;
if ( ! V_2 -> V_334 &&
V_212 -> type == V_79 && ! V_212 -> V_335 ) {
V_2 -> V_334 = V_232 ;
V_212 -> V_336 |= V_337 |
V_338 ;
}
if ( V_212 -> type == V_83 ) {
V_232 -> V_238 = F_108 ( V_2 ) ;
if ( ! V_232 -> V_238 ) {
V_25 = - V_339 ;
goto V_340;
}
F_119 ( V_2 , V_232 -> V_238 ) ;
V_25 = F_120 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_341;
V_25 = F_121 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_342;
V_2 -> V_295 = V_212 ;
}
F_115 ( V_2 , V_212 ) ;
goto V_331;
V_342:
F_122 ( V_2 , V_212 ) ;
V_341:
F_123 ( V_2 , V_232 -> V_238 ) ;
V_340:
if ( V_2 -> V_334 == V_232 ) {
V_2 -> V_334 = NULL ;
V_212 -> V_336 &= ~ ( V_337 |
V_338 ) ;
}
V_333:
V_232 -> V_238 = NULL ;
F_124 ( V_2 , V_212 ) ;
V_332:
if ( V_212 -> type != V_83 )
V_2 -> V_306 -- ;
F_125 ( V_2 , V_212 ) ;
V_331:
F_60 ( & V_2 -> V_227 ) ;
F_7 ( V_2 , V_330 ) ;
return V_25 ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
T_5 V_343 = F_127 ( V_212 ) ;
if ( V_343 ) {
F_54 ( & V_2 -> V_227 ) ;
F_128 ( V_2 , V_343 , true ) ;
F_60 ( & V_2 -> V_227 ) ;
}
if ( V_212 -> type == V_83 ) {
F_107 ( & V_2 -> V_318 ) ;
} else {
F_107 ( & V_2 -> V_344 ) ;
}
}
static void F_129 ( struct V_22 * V_23 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
F_126 ( V_2 , V_212 ) ;
F_54 ( & V_2 -> V_227 ) ;
if ( V_2 -> V_334 == V_232 ) {
V_2 -> V_334 = NULL ;
V_212 -> V_336 &= ~ ( V_337 |
V_338 ) ;
}
F_130 ( V_2 , V_212 ) ;
if ( V_212 -> type == V_81 ||
V_212 -> type == V_84 ) {
#ifdef F_131
if ( V_212 == V_2 -> V_345 ) {
V_2 -> V_345 = NULL ;
V_2 -> V_346 = 0 ;
}
#endif
F_132 ( V_2 , V_212 ) ;
goto V_332;
}
if ( V_212 -> type == V_83 ) {
V_2 -> V_295 = NULL ;
F_133 ( V_2 , V_212 ) ;
F_122 ( V_2 , V_212 ) ;
F_123 ( V_2 , V_232 -> V_238 ) ;
V_232 -> V_238 = NULL ;
}
if ( V_2 -> V_306 && V_212 -> type != V_83 )
V_2 -> V_306 -- ;
F_117 ( V_2 ) ;
F_124 ( V_2 , V_212 ) ;
V_332:
F_125 ( V_2 , V_212 ) ;
F_60 ( & V_2 -> V_227 ) ;
}
static int F_134 ( struct V_22 * V_23 , T_5 V_347 )
{
return 0 ;
}
static void F_135 ( void * V_348 , T_1 * V_231 ,
struct V_211 * V_212 )
{
struct V_349 * V_198 = V_348 ;
struct V_1 * V_2 = V_198 -> V_2 ;
struct V_350 * V_351 = V_2 -> V_352 ;
int V_25 , V_152 ;
if ( F_15 ( V_198 -> V_353 >= V_354 ) )
return;
if ( V_212 -> type != V_79 ||
! V_212 -> V_355 . V_356 )
return;
V_351 -> V_353 = V_198 -> V_353 ++ ;
memcpy ( V_351 -> V_357 , V_212 -> V_355 . V_357 , V_102 ) ;
V_152 = F_136 ( sizeof( * V_351 ) + V_351 -> V_242 * V_102 , 4 ) ;
V_25 = F_111 ( V_2 , V_358 , V_359 , V_152 , V_351 ) ;
if ( V_25 )
F_95 ( V_2 , L_13 , V_25 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_349 V_360 = {
. V_2 = V_2 ,
} ;
F_70 ( & V_2 -> V_227 ) ;
if ( F_15 ( ! V_2 -> V_352 ) )
return;
F_86 (
V_2 -> V_23 , V_361 ,
F_135 , & V_360 ) ;
}
static T_7 F_138 ( struct V_22 * V_23 ,
struct V_362 * V_363 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_350 * V_351 ;
struct V_364 * V_99 ;
int V_365 ;
bool V_366 ;
int V_152 ;
V_365 = F_139 ( V_363 ) ;
V_366 = V_365 > V_367 ||
V_368 ;
if ( V_366 )
V_365 = 0 ;
V_152 = F_136 ( sizeof( * V_351 ) + V_365 * V_102 , 4 ) ;
V_351 = F_71 ( V_152 , V_369 ) ;
if ( ! V_351 )
return 0 ;
if ( V_366 ) {
V_351 -> V_366 = 1 ;
return ( T_7 ) ( unsigned long ) V_351 ;
}
F_140 (addr, mc_list) {
F_141 ( V_2 , L_14 ,
V_351 -> V_242 , V_99 -> V_99 ) ;
memcpy ( & V_351 -> V_370 [ V_351 -> V_242 * V_102 ] ,
V_99 -> V_99 , V_102 ) ;
V_351 -> V_242 ++ ;
}
return ( T_7 ) ( unsigned long ) V_351 ;
}
static void F_142 ( struct V_22 * V_23 ,
unsigned int V_371 ,
unsigned int * V_372 ,
T_7 V_373 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_350 * V_351 = ( void * ) ( unsigned long ) V_373 ;
F_54 ( & V_2 -> V_227 ) ;
F_68 ( V_2 -> V_352 ) ;
V_2 -> V_352 = V_351 ;
if ( ! V_351 )
goto V_186;
F_137 ( V_2 ) ;
V_186:
F_60 ( & V_2 -> V_227 ) ;
* V_372 = 0 ;
}
static void
F_143 ( struct V_211 * V_212 ,
const struct V_374 * V_375 ,
struct V_374 * V_376 )
{
struct V_377 * V_378 ;
int V_9 ;
memcpy ( V_376 , V_375 , sizeof( * V_376 ) ) ;
for ( V_9 = 0 ; V_9 < F_19 ( V_376 -> V_379 ) ; V_9 ++ ) {
V_378 = & V_376 -> V_379 [ V_9 ] ;
if ( ! V_378 -> V_380 )
break;
switch ( V_378 -> V_381 ) {
case F_110 ( V_382 ) :
if ( V_212 -> V_355 . V_383 != 1 ) {
V_378 -> V_380 = 0 ;
continue;
}
V_378 -> V_384 = V_212 -> V_355 . V_385 [ 0 ] ;
break;
case F_110 ( V_386 ) :
V_378 -> V_384 = * ( V_387 * ) & V_212 -> V_99 [ 2 ] ;
break;
default:
break;
}
V_378 -> V_381 = 0 ;
V_376 -> V_388 ++ ;
}
}
static void F_144 ( void * V_348 , T_1 * V_231 ,
struct V_211 * V_212 )
{
struct V_389 * V_198 = V_348 ;
struct V_1 * V_2 = V_198 -> V_2 ;
struct V_390 * V_351 = V_198 -> V_351 ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
struct V_391 * V_392 ;
int V_9 ;
if ( F_8 ( V_232 -> V_20 >= F_19 ( V_351 -> V_393 ) ) )
return;
V_392 = & V_351 -> V_393 [ V_232 -> V_20 ] ;
if ( V_212 -> type != V_79 || V_212 -> V_335 ||
! V_212 -> V_355 . V_356 )
return;
V_392 -> V_394 = 1 ;
for ( V_9 = 0 ; V_2 -> V_173 [ V_9 ] . V_379 [ 0 ] . V_380 ; V_9 ++ ) {
if ( F_15 ( V_198 -> V_395 >=
F_19 ( V_351 -> V_396 ) ) ) {
V_392 -> V_394 = 0 ;
V_392 -> V_397 = 0 ;
break;
}
F_143 ( V_212 ,
& V_2 -> V_173 [ V_9 ] ,
& V_351 -> V_396 [ V_198 -> V_395 ] ) ;
if ( ! V_351 -> V_396 [ V_198 -> V_395 ] . V_388 )
continue;
V_392 -> V_397 |=
F_110 ( F_18 ( V_198 -> V_395 ) ) ;
V_198 -> V_395 ++ ;
}
}
bool F_145 ( struct V_1 * V_2 ,
struct V_390 * V_351 )
{
struct V_389 V_360 = {
. V_2 = V_2 ,
. V_351 = V_351 ,
} ;
if ( V_398 )
return false ;
memset ( V_351 , 0 , sizeof( * V_351 ) ) ;
V_351 -> V_399 = F_19 ( V_351 -> V_396 ) ;
V_351 -> V_400 = F_19 ( V_351 -> V_393 ) ;
#ifdef F_146
if ( V_2 -> V_401 . V_402 ) {
memcpy ( V_351 -> V_396 , & V_2 -> V_401 . V_351 . V_396 ,
sizeof( V_351 -> V_396 ) ) ;
memcpy ( V_351 -> V_393 , & V_2 -> V_401 . V_351 . V_393 ,
sizeof( V_351 -> V_393 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_173 )
return false ;
F_147 (
V_2 -> V_23 , V_361 ,
F_144 , & V_360 ) ;
return true ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
struct V_390 V_351 ;
if ( ! ( V_2 -> V_50 -> V_51 . V_26 & V_403 ) )
return 0 ;
if ( ! F_145 ( V_2 , & V_351 ) )
return 0 ;
return F_111 ( V_2 , V_404 , 0 ,
sizeof( V_351 ) , & V_351 ) ;
}
static inline int F_148 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
return 0 ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_211 * V_212 ,
struct V_405 * V_355 ,
T_5 V_406 )
{
struct V_75 * V_232 = F_62 ( V_212 ) ;
int V_25 ;
if ( V_406 & V_407 && V_355 -> V_356 )
F_150 ( V_2 , V_212 ) ;
if ( V_406 & V_408 && ! V_232 -> V_409 )
memcpy ( V_232 -> V_357 , V_355 -> V_357 , V_102 ) ;
V_25 = F_151 ( V_2 , V_212 , false , V_232 -> V_357 ) ;
if ( V_25 )
F_95 ( V_2 , L_15 , V_212 -> V_99 ) ;
memcpy ( V_232 -> V_357 , V_355 -> V_357 , V_102 ) ;
V_232 -> V_409 = V_355 -> V_356 ;
if ( V_406 & V_407 ) {
if ( V_355 -> V_356 ) {
V_25 = F_94 ( V_2 , NULL ) ;
if ( V_25 ) {
F_95 ( V_2 , L_16 ) ;
return;
}
if ( F_14 ( V_308 ,
& V_2 -> V_15 ) ) {
T_5 V_410 = ( 11 * V_212 -> V_355 . V_411 ) / 10 ;
F_152 ( V_2 , V_212 , V_410 , V_410 ,
5 * V_410 , false ) ;
}
F_153 ( V_2 , V_212 , false ) ;
F_154 ( V_2 , V_212 ) ;
if ( V_212 -> V_335 ) {
F_1 ( V_2 , V_412 ) ;
F_155 ( V_2 , V_212 ,
V_413 ,
V_414 ) ;
}
} else if ( V_232 -> V_234 != V_188 ) {
F_156 ( F_153 ( V_2 , V_212 , false ) ,
L_17 ) ;
V_25 = F_157 ( V_2 , V_212 , V_232 -> V_234 ) ;
if ( V_25 )
F_95 ( V_2 , L_18 ) ;
if ( V_2 -> V_189 == V_232 -> V_234 )
V_2 -> V_189 = V_188 ;
V_232 -> V_234 = V_188 ;
V_25 = F_94 ( V_2 , NULL ) ;
if ( V_25 )
F_95 ( V_2 , L_16 ) ;
if ( V_212 -> V_335 )
F_7 ( V_2 , V_412 ) ;
V_25 = F_151 ( V_2 , V_212 , false , NULL ) ;
if ( V_25 )
F_95 ( V_2 ,
L_19 ,
V_212 -> V_99 ) ;
}
F_137 ( V_2 ) ;
F_148 ( V_2 , V_212 ) ;
V_232 -> V_239 . V_415 = 0 ;
F_158 ( V_2 ) ;
F_155 ( V_2 , V_212 , V_416 ,
V_417 ) ;
} else if ( V_406 & V_418 ) {
F_159 ( V_2 , V_232 ,
& V_232 -> V_237 ) ;
}
if ( V_406 & V_418 ) {
F_153 ( V_2 , V_212 , false ) ;
F_8 ( F_160 ( V_2 , V_212 , 0 ) ) ;
}
if ( V_406 & ( V_419 | V_420 | V_421 ) ) {
V_25 = F_117 ( V_2 ) ;
if ( V_25 )
F_95 ( V_2 , L_20 ) ;
}
if ( V_406 & V_422 ) {
F_161 ( V_2 , L_21 ,
V_355 -> V_423 ) ;
F_109 ( V_2 , V_212 , V_355 -> V_423 ) ;
}
if ( V_406 & V_424 ) {
F_141 ( V_2 , L_22 ) ;
V_232 -> V_239 . V_425 = 0 ;
if ( V_232 -> V_239 . V_426 ) {
V_25 = F_160 ( V_2 , V_212 , 0 ) ;
if ( V_25 )
F_95 ( V_2 ,
L_23 ) ;
}
}
if ( V_406 & V_427 ) {
F_141 ( V_2 , L_24 ) ;
F_148 ( V_2 , V_212 ) ;
}
}
static int F_162 ( struct V_22 * V_23 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
int V_25 ;
V_25 = F_12 ( V_2 , V_428 ) ;
if ( V_25 )
return V_25 ;
F_54 ( & V_2 -> V_227 ) ;
V_25 = F_163 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_331;
if ( V_212 -> type == V_81 )
F_150 ( V_2 , V_212 ) ;
V_25 = F_116 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_331;
V_25 = F_120 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_429;
V_25 = F_164 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_342;
V_232 -> V_430 = true ;
F_117 ( V_2 ) ;
V_25 = F_94 ( V_2 , NULL ) ;
if ( V_25 )
goto V_431;
if ( V_212 -> V_335 && V_2 -> V_295 )
F_151 ( V_2 , V_2 -> V_295 , false , NULL ) ;
F_1 ( V_2 , V_432 ) ;
F_158 ( V_2 ) ;
if ( F_165 ( V_2 ) > 1 )
F_96 ( V_2 ) ;
F_60 ( & V_2 -> V_227 ) ;
return 0 ;
V_431:
F_117 ( V_2 ) ;
V_232 -> V_430 = false ;
F_166 ( V_2 , V_212 ) ;
V_342:
F_122 ( V_2 , V_212 ) ;
V_429:
F_124 ( V_2 , V_212 ) ;
V_331:
F_60 ( & V_2 -> V_227 ) ;
F_7 ( V_2 , V_428 ) ;
return V_25 ;
}
static void F_167 ( struct V_22 * V_23 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
F_126 ( V_2 , V_212 ) ;
F_54 ( & V_2 -> V_227 ) ;
if ( F_168 ( V_2 -> V_433 ) == V_212 ) {
F_159 ( V_2 , V_232 ,
& V_232 -> V_237 ) ;
F_169 ( V_2 -> V_433 , NULL ) ;
}
if ( F_168 ( V_2 -> V_434 ) == V_212 ) {
F_169 ( V_2 -> V_434 , NULL ) ;
V_2 -> V_435 = 0 ;
}
V_232 -> V_430 = false ;
V_2 -> V_436 = 0 ;
F_158 ( V_2 ) ;
F_7 ( V_2 , V_432 ) ;
if ( V_212 -> V_335 && V_2 -> V_295 )
F_151 ( V_2 , V_2 -> V_295 , false , NULL ) ;
F_94 ( V_2 , NULL ) ;
F_166 ( V_2 , V_212 ) ;
F_122 ( V_2 , V_212 ) ;
F_117 ( V_2 ) ;
F_124 ( V_2 , V_212 ) ;
F_60 ( & V_2 -> V_227 ) ;
}
static void
F_170 ( struct V_1 * V_2 ,
struct V_211 * V_212 ,
struct V_405 * V_355 ,
T_5 V_406 )
{
struct V_75 * V_232 = F_62 ( V_212 ) ;
if ( ! V_232 -> V_430 )
return;
if ( V_406 & ( V_437 | V_438 |
V_439 | V_421 ) &&
F_151 ( V_2 , V_212 , false , NULL ) )
F_95 ( V_2 , L_15 , V_212 -> V_99 ) ;
if ( V_406 & V_440 &&
F_163 ( V_2 , V_212 ) )
F_171 ( V_2 , L_25 ) ;
if ( V_406 & V_422 ) {
F_161 ( V_2 , L_21 ,
V_355 -> V_423 ) ;
F_109 ( V_2 , V_212 , V_355 -> V_423 ) ;
}
}
static void F_172 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_405 * V_355 ,
T_5 V_406 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
if ( F_12 ( V_2 , V_441 ) )
return;
F_54 ( & V_2 -> V_227 ) ;
if ( V_406 & V_442 && ! V_355 -> V_443 )
F_173 ( V_2 , true ) ;
switch ( V_212 -> type ) {
case V_79 :
F_149 ( V_2 , V_212 , V_355 , V_406 ) ;
break;
case V_81 :
case V_84 :
F_170 ( V_2 , V_212 , V_355 , V_406 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_60 ( & V_2 -> V_227 ) ;
F_7 ( V_2 , V_441 ) ;
}
static int F_174 ( struct V_1 * V_2 ,
enum V_444 V_445 )
{
int V_25 ;
bool V_446 = false ;
F_54 ( & V_2 -> V_227 ) ;
if ( V_2 -> V_290 != V_445 ) {
V_25 = 0 ;
V_446 = true ;
goto V_186;
}
switch ( V_445 ) {
case V_447 :
V_25 = F_173 ( V_2 , true ) ;
break;
case V_448 :
V_25 = F_175 ( V_2 ) ;
break;
case V_291 :
default:
F_15 ( 1 ) ;
V_25 = - V_229 ;
break;
}
if ( V_25 )
goto V_186;
V_446 = true ;
V_186:
F_60 ( & V_2 -> V_227 ) ;
if ( V_446 )
F_176 ( V_2 ) ;
return V_25 ;
}
static int F_177 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_449 * V_450 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_451 * V_452 = & V_450 -> V_452 ;
int V_25 ;
if ( V_452 -> V_111 == 0 ||
V_452 -> V_111 > V_2 -> V_50 -> V_51 . V_453 )
return - V_229 ;
if ( ! ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] & V_66 ) ) {
V_25 = F_174 ( V_2 , V_447 ) ;
if ( V_25 )
return V_25 ;
}
F_54 ( & V_2 -> V_227 ) ;
if ( V_2 -> V_290 != V_291 ) {
V_25 = - V_454 ;
goto V_186;
}
F_1 ( V_2 , V_455 ) ;
if ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] & V_66 )
V_25 = F_178 ( V_2 , V_212 , V_450 ) ;
else if ( V_2 -> V_50 -> V_51 . V_63 [ 0 ] & V_64 )
V_25 = F_179 ( V_2 , V_212 , V_450 ) ;
else
V_25 = F_180 ( V_2 , V_212 , V_452 ) ;
if ( V_25 )
F_7 ( V_2 , V_455 ) ;
V_186:
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static void F_181 ( struct V_22 * V_23 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_54 ( & V_2 -> V_227 ) ;
F_175 ( V_2 ) ;
F_60 ( & V_2 -> V_227 ) ;
}
static void
F_182 ( struct V_22 * V_23 ,
struct V_179 * V_180 , V_77 V_456 ,
int V_457 ,
enum V_458 V_459 ,
bool V_460 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_183 ( V_2 , V_180 , V_459 , V_457 ,
V_456 , V_460 , false ) ;
}
static void
F_184 ( struct V_22 * V_23 ,
struct V_179 * V_180 , V_77 V_456 ,
int V_457 ,
enum V_458 V_459 ,
bool V_460 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_183 ( V_2 , V_180 , V_459 , V_457 ,
V_456 , V_460 , true ) ;
}
static void F_185 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
enum V_461 V_351 ,
struct V_179 * V_180 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_73 * V_183 = F_33 ( V_180 ) ;
int V_215 ;
switch ( V_351 ) {
case V_462 :
if ( F_186 ( & V_2 -> V_463 [ V_183 -> V_187 ] ) > 0 )
F_187 ( V_23 , V_180 , true ) ;
F_4 ( & V_183 -> V_464 ) ;
for ( V_215 = 0 ; V_215 < V_465 ; V_215 ++ ) {
struct V_466 * V_467 ;
V_467 = & V_183 -> V_467 [ V_215 ] ;
if ( V_467 -> V_468 != V_469 &&
V_467 -> V_468 != V_470 )
continue;
if ( F_188 ( V_467 ) == 0 )
continue;
F_189 ( V_180 , V_215 , true ) ;
}
F_5 ( & V_183 -> V_464 ) ;
break;
case V_471 :
if ( F_8 ( V_183 -> V_187 == V_188 ) )
break;
F_190 ( V_2 , V_180 ) ;
break;
default:
break;
}
}
static void F_191 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_179 * V_180 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_73 * V_472 = ( void * ) V_180 -> V_473 ;
F_54 ( & V_2 -> V_227 ) ;
if ( V_180 == F_168 ( V_2 -> V_474 [ V_472 -> V_187 ] ) )
F_192 ( V_2 -> V_474 [ V_472 -> V_187 ] ,
F_193 ( - V_475 ) ) ;
F_60 ( & V_2 -> V_227 ) ;
}
static int F_194 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_179 * V_180 ,
enum V_476 V_477 ,
enum V_476 V_478 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
int V_25 ;
F_141 ( V_2 , L_26 ,
V_180 -> V_99 , V_477 , V_478 ) ;
if ( F_15 ( ! V_232 -> V_238 ) )
return - V_229 ;
F_107 ( & V_2 -> V_344 ) ;
F_54 ( & V_2 -> V_227 ) ;
if ( V_477 == V_479 &&
V_478 == V_480 ) {
if ( V_212 -> type == V_79 &&
V_212 -> V_355 . V_411 < 16 ) {
F_95 ( V_2 ,
L_27 ,
V_180 -> V_99 , V_212 -> V_355 . V_411 ) ;
V_25 = - V_229 ;
goto V_331;
}
if ( V_180 -> V_481 &&
( V_212 -> V_335 ||
F_195 ( V_2 , NULL ) ==
V_482 ||
F_165 ( V_2 ) > 1 ) ) {
F_141 ( V_2 , L_28 ) ;
V_25 = - V_454 ;
goto V_331;
}
V_25 = F_196 ( V_2 , V_212 , V_180 ) ;
if ( V_180 -> V_481 && V_25 == 0 )
F_197 ( V_2 , V_212 , true ) ;
} else if ( V_477 == V_480 &&
V_478 == V_483 ) {
V_2 -> V_484 = true ;
V_25 = 0 ;
} else if ( V_477 == V_483 &&
V_478 == V_485 ) {
V_25 = F_198 ( V_2 , V_212 , V_180 ) ;
if ( V_25 == 0 )
F_199 ( V_2 , V_180 ,
V_232 -> V_238 -> V_486 -> V_487 ,
true ) ;
} else if ( V_477 == V_485 &&
V_478 == V_488 ) {
if ( F_165 ( V_2 ) > 1 )
F_96 ( V_2 ) ;
F_8 ( F_160 ( V_2 , V_212 , 0 ) ) ;
V_25 = 0 ;
} else if ( V_477 == V_488 &&
V_478 == V_485 ) {
F_8 ( F_118 ( V_2 , V_212 , 0 ) ) ;
V_25 = 0 ;
} else if ( V_477 == V_485 &&
V_478 == V_483 ) {
V_25 = 0 ;
} else if ( V_477 == V_483 &&
V_478 == V_480 ) {
V_25 = 0 ;
} else if ( V_477 == V_480 &&
V_478 == V_479 ) {
V_25 = F_200 ( V_2 , V_212 , V_180 ) ;
if ( V_180 -> V_481 )
F_197 ( V_2 , V_212 , false ) ;
} else {
V_25 = - V_17 ;
}
V_331:
F_60 ( & V_2 -> V_227 ) ;
if ( V_180 -> V_481 && V_25 == 0 ) {
if ( V_477 == V_479 &&
V_478 == V_480 )
F_201 ( V_180 , V_489 ) ;
else if ( V_477 == V_480 &&
V_478 == V_479 )
F_202 ( V_180 , V_489 ) ;
}
return V_25 ;
}
static int F_203 ( struct V_22 * V_23 , T_5 V_490 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
V_2 -> V_140 = V_490 ;
return 0 ;
}
static void F_204 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_179 * V_180 , T_5 V_347 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
if ( V_212 -> type == V_79 &&
V_347 & V_491 )
F_153 ( V_2 , V_212 , false ) ;
}
static int F_205 ( struct V_22 * V_23 ,
struct V_211 * V_212 , V_77 V_492 ,
const struct V_493 * V_494 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
V_232 -> V_495 [ V_492 ] = * V_494 ;
if ( V_212 -> type == V_83 ) {
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
V_25 = F_151 ( V_2 , V_212 , false , NULL ) ;
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
return 0 ;
}
static void F_206 ( struct V_22 * V_23 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
T_5 V_496 = F_20 ( V_497 ,
200 + V_212 -> V_355 . V_411 ) ;
T_5 V_498 = F_20 ( V_499 ,
100 + V_212 -> V_355 . V_411 ) ;
if ( F_15 ( V_212 -> V_355 . V_356 ) )
return;
if ( F_12 ( V_2 , V_500 ) )
return;
F_54 ( & V_2 -> V_227 ) ;
F_152 ( V_2 , V_212 , V_496 , V_498 , 500 , false ) ;
F_60 ( & V_2 -> V_227 ) ;
F_7 ( V_2 , V_500 ) ;
}
static int F_207 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_501 * V_452 ,
struct V_502 * V_503 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
if ( ! ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] & V_66 ) ) {
V_25 = F_174 ( V_2 , V_448 ) ;
if ( V_25 )
return V_25 ;
}
F_54 ( & V_2 -> V_227 ) ;
if ( V_2 -> V_50 -> V_51 . V_63 [ 0 ] & V_64 ) {
if ( ! V_212 -> V_355 . V_443 ) {
V_25 = - V_454 ;
goto V_186;
}
} else if ( ! F_208 ( V_2 ) ) {
V_25 = - V_454 ;
goto V_186;
}
if ( V_2 -> V_290 != V_291 ) {
V_25 = - V_454 ;
goto V_186;
}
V_25 = F_209 ( V_2 , V_212 , V_452 , V_503 ) ;
if ( V_25 )
V_2 -> V_290 = V_291 ;
V_186:
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static int F_210 ( struct V_22 * V_23 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
V_25 = F_173 ( V_2 , false ) ;
F_60 ( & V_2 -> V_227 ) ;
F_176 ( V_2 ) ;
return V_25 ;
}
static int F_211 ( struct V_22 * V_23 ,
enum V_504 V_351 ,
struct V_211 * V_212 ,
struct V_179 * V_180 ,
struct V_505 * V_506 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
if ( V_53 . V_54 ) {
F_141 ( V_2 , L_29 ) ;
return - V_507 ;
}
switch ( V_506 -> V_143 ) {
case V_508 :
V_506 -> V_26 |= V_509 ;
case V_510 :
V_506 -> V_26 |= V_511 ;
break;
case V_512 :
F_15 ( ! ( V_23 -> V_26 & V_55 ) ) ;
break;
case V_513 :
case V_514 :
if ( V_212 -> type != V_79 )
return 0 ;
break;
default:
if ( V_23 -> V_144 &&
V_23 -> V_145 -> V_143 == V_506 -> V_143 )
V_506 -> V_26 |= V_515 ;
else
return - V_507 ;
}
F_54 ( & V_2 -> V_227 ) ;
switch ( V_351 ) {
case V_516 :
if ( ( V_212 -> type == V_84 ||
V_212 -> type == V_81 ) && ! V_180 ) {
V_25 = 0 ;
V_506 -> V_517 = V_518 ;
break;
}
F_141 ( V_2 , L_30 ) ;
V_25 = F_212 ( V_2 , V_212 , V_180 , V_506 , false ) ;
if ( V_25 ) {
F_171 ( V_2 , L_31 ) ;
V_506 -> V_517 = V_518 ;
V_25 = 0 ;
}
break;
case V_519 :
if ( V_506 -> V_517 == V_518 ) {
V_25 = 0 ;
break;
}
F_141 ( V_2 , L_32 ) ;
V_25 = F_213 ( V_2 , V_212 , V_180 , V_506 ) ;
break;
default:
V_25 = - V_229 ;
}
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static void F_214 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_505 * V_520 ,
struct V_179 * V_180 ,
T_5 V_521 , V_77 * V_522 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
if ( V_520 -> V_517 == V_518 )
return;
F_215 ( V_2 , V_212 , V_520 , V_180 , V_521 , V_522 ) ;
}
static bool F_216 ( struct V_523 * V_524 ,
struct V_525 * V_526 , void * V_198 )
{
struct V_1 * V_2 =
F_217 ( V_524 , struct V_1 , V_524 ) ;
struct V_527 * V_528 ;
int V_529 = F_218 ( V_526 ) ;
struct V_530 * V_531 = V_198 ;
if ( F_8 ( V_526 -> V_197 . V_351 != V_532 ) )
return true ;
if ( F_15 ( V_529 != sizeof( * V_528 ) ) ) {
F_95 ( V_2 , L_33 ) ;
return true ;
}
V_528 = ( void * ) V_526 -> V_198 ;
F_219 ( V_2 ,
L_34 ,
V_528 -> V_15 , V_528 -> V_533 ) ;
V_531 -> V_534 = F_220 ( V_528 -> V_533 ) ;
F_219 ( V_2 , L_35 ,
V_531 -> V_534 ) ;
F_4 ( & V_2 -> V_236 ) ;
F_221 ( & V_531 -> V_535 , & V_2 -> V_536 ) ;
F_5 ( & V_2 -> V_236 ) ;
return true ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_537 * V_486 ,
struct V_211 * V_212 ,
int V_496 )
{
int V_538 , V_539 = V_540 ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
struct V_530 * V_531 = & V_232 -> V_541 ;
static const T_1 V_542 [] = { V_532 } ;
struct V_543 V_544 ;
struct V_545 V_546 = {
. V_214 = F_74 ( V_547 ) ,
. V_548 =
F_74 ( F_223 ( V_549 , 0 ) ) ,
. V_550 = F_74 ( V_2 -> V_551 . V_187 ) ,
. V_552 . V_487 = ( V_486 -> V_487 == V_110 ) ?
V_553 : V_554 ,
. V_552 . V_486 = V_486 -> V_555 ,
. V_552 . V_556 = V_557 ,
. V_558 = F_74 ( F_224 ( V_2 -> V_7 , V_539 ) ) ,
. V_559 =
F_74 ( F_225 ( V_560 ) ) ,
. V_496 = F_74 ( F_225 ( V_496 ) ) ,
} ;
memcpy ( V_546 . V_561 , V_212 -> V_99 , V_102 ) ;
F_70 ( & V_2 -> V_227 ) ;
F_4 ( & V_2 -> V_236 ) ;
if ( F_8 ( V_531 -> V_20 == V_532 ) ) {
F_5 ( & V_2 -> V_236 ) ;
return - V_17 ;
}
V_531 -> V_212 = V_212 ;
V_531 -> V_496 = V_496 ;
V_531 -> V_20 = V_532 ;
F_5 ( & V_2 -> V_236 ) ;
F_226 ( & V_2 -> V_524 , & V_544 ,
V_542 ,
F_19 ( V_542 ) ,
F_216 , V_531 ) ;
V_538 = F_111 ( V_2 , V_532 , 0 , sizeof( V_546 ) ,
& V_546 ) ;
if ( V_538 ) {
F_95 ( V_2 , L_36 , V_538 ) ;
F_227 ( & V_2 -> V_524 , & V_544 ) ;
goto V_562;
}
V_538 = F_228 ( & V_2 -> V_524 , & V_544 , 1 ) ;
F_15 ( V_538 ) ;
if ( V_538 ) {
V_562:
F_4 ( & V_2 -> V_236 ) ;
F_63 ( V_2 , V_531 ) ;
F_5 ( & V_2 -> V_236 ) ;
}
return V_538 ;
}
static int F_229 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_537 * V_486 ,
int V_496 ,
enum V_563 type )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
struct V_564 V_565 ;
struct V_323 * V_238 ;
int V_25 , V_9 ;
F_141 ( V_2 , L_37 , V_486 -> V_555 ,
V_496 , type ) ;
F_54 ( & V_2 -> V_227 ) ;
switch ( V_212 -> type ) {
case V_79 :
if ( V_2 -> V_50 -> V_51 . V_65 [ 0 ] &
V_566 ) {
V_25 = F_222 ( V_2 , V_486 ,
V_212 , V_496 ) ;
goto V_331;
}
F_95 ( V_2 , L_38 ) ;
V_25 = - V_229 ;
goto V_331;
case V_83 :
break;
default:
F_95 ( V_2 , L_39 , V_212 -> type ) ;
V_25 = - V_229 ;
goto V_331;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_238 = & V_2 -> V_18 [ V_9 ] ;
if ( V_238 -> V_21 == 0 || V_232 -> V_238 == V_238 )
continue;
if ( V_238 -> V_21 && V_486 == V_238 -> V_486 ) {
V_25 = F_122 ( V_2 , V_212 ) ;
if ( F_230 ( V_25 , L_40 ) )
goto V_331;
F_123 ( V_2 , V_232 -> V_238 ) ;
V_232 -> V_238 = V_238 ;
V_25 = F_120 ( V_2 , V_212 ) ;
if ( F_230 ( V_25 , L_41 ) )
goto V_331;
F_119 ( V_2 , V_232 -> V_238 ) ;
goto V_567;
}
}
if ( V_486 == V_232 -> V_238 -> V_486 )
goto V_567;
F_231 ( & V_565 , V_486 , V_568 ) ;
if ( V_232 -> V_238 -> V_21 == 1 ) {
V_25 = F_232 ( V_2 , V_232 -> V_238 ,
& V_565 , 1 , 1 ) ;
if ( V_25 )
goto V_331;
} else {
V_238 = F_108 ( V_2 ) ;
if ( ! V_238 ) {
V_25 = - V_339 ;
goto V_331;
}
V_25 = F_232 ( V_2 , V_238 , & V_565 ,
1 , 1 ) ;
if ( V_25 ) {
F_95 ( V_2 , L_42 ) ;
goto V_331;
}
V_25 = F_122 ( V_2 , V_212 ) ;
if ( F_230 ( V_25 , L_40 ) )
goto V_331;
F_123 ( V_2 , V_232 -> V_238 ) ;
V_232 -> V_238 = V_238 ;
V_25 = F_120 ( V_2 , V_212 ) ;
if ( F_230 ( V_25 , L_41 ) )
goto V_331;
F_119 ( V_2 , V_232 -> V_238 ) ;
}
V_567:
V_25 = F_233 ( V_2 , V_212 , V_496 , type ) ;
V_331:
F_60 ( & V_2 -> V_227 ) ;
F_141 ( V_2 , L_43 ) ;
return V_25 ;
}
static int F_234 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_141 ( V_2 , L_44 ) ;
F_54 ( & V_2 -> V_227 ) ;
F_235 ( V_2 ) ;
F_60 ( & V_2 -> V_227 ) ;
F_141 ( V_2 , L_43 ) ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 ,
struct V_569 * V_570 )
{
V_77 * V_571 = ( V_77 * ) V_570 -> V_473 ;
struct V_323 * V_238 ;
int V_25 ;
F_70 ( & V_2 -> V_227 ) ;
F_141 ( V_2 , L_45 ) ;
V_238 = F_108 ( V_2 ) ;
if ( ! V_238 ) {
V_25 = - V_339 ;
goto V_186;
}
V_25 = F_232 ( V_2 , V_238 , & V_570 -> V_572 ,
V_570 -> V_573 ,
V_570 -> V_574 ) ;
if ( V_25 ) {
F_95 ( V_2 , L_46 ) ;
goto V_186;
}
F_119 ( V_2 , V_238 ) ;
* V_571 = V_238 -> V_20 ;
V_186:
return V_25 ;
}
static int F_237 ( struct V_22 * V_23 ,
struct V_569 * V_570 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
V_25 = F_236 ( V_2 , V_570 ) ;
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static void F_238 ( struct V_1 * V_2 ,
struct V_569 * V_570 )
{
V_77 * V_571 = ( V_77 * ) V_570 -> V_473 ;
struct V_323 * V_238 = & V_2 -> V_18 [ * V_571 ] ;
F_70 ( & V_2 -> V_227 ) ;
F_123 ( V_2 , V_238 ) ;
}
static void F_239 ( struct V_22 * V_23 ,
struct V_569 * V_570 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_54 ( & V_2 -> V_227 ) ;
F_238 ( V_2 , V_570 ) ;
F_60 ( & V_2 -> V_227 ) ;
}
static void F_240 ( struct V_22 * V_23 ,
struct V_569 * V_570 ,
T_5 V_347 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
V_77 * V_571 = ( V_77 * ) V_570 -> V_473 ;
struct V_323 * V_238 = & V_2 -> V_18 [ * V_571 ] ;
if ( F_156 ( ( V_238 -> V_21 > 1 ) &&
( V_347 & ~ ( V_575 |
V_576 |
V_577 |
V_578 ) ) ,
L_47 ,
V_238 -> V_21 , V_347 ) )
return;
F_54 ( & V_2 -> V_227 ) ;
F_158 ( V_2 ) ;
F_232 ( V_2 , V_238 , & V_570 -> V_572 ,
V_570 -> V_573 ,
V_570 -> V_574 ) ;
F_60 ( & V_2 -> V_227 ) ;
}
static int F_241 ( struct V_1 * V_2 ,
struct V_211 * V_212 ,
struct V_569 * V_570 ,
bool V_579 )
{
V_77 * V_571 = ( V_77 * ) V_570 -> V_473 ;
struct V_323 * V_238 = & V_2 -> V_18 [ * V_571 ] ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
int V_25 ;
F_70 ( & V_2 -> V_227 ) ;
V_232 -> V_238 = V_238 ;
switch ( V_212 -> type ) {
case V_81 :
if ( V_579 ) {
V_232 -> V_430 = true ;
break;
}
case V_84 :
V_25 = 0 ;
goto V_186;
case V_79 :
break;
case V_580 :
V_232 -> V_292 = true ;
break;
default:
V_25 = - V_229 ;
goto V_186;
}
V_25 = F_120 ( V_2 , V_212 ) ;
if ( V_25 )
goto V_186;
F_117 ( V_2 ) ;
if ( V_212 -> type == V_580 ) {
V_232 -> V_581 = true ;
V_25 = F_94 ( V_2 , NULL ) ;
if ( V_25 )
goto V_582;
}
if ( V_212 -> type == V_81 ) {
F_94 ( V_2 , NULL ) ;
F_151 ( V_2 , V_212 , false , NULL ) ;
}
if ( V_579 && V_212 -> type == V_79 ) {
T_5 V_496 = 2 * V_212 -> V_355 . V_411 ;
V_25 = F_12 ( V_2 , V_583 ) ;
if ( V_25 )
goto V_582;
F_152 ( V_2 , V_212 , V_496 , V_496 ,
V_212 -> V_355 . V_411 / 2 ,
true ) ;
F_7 ( V_2 , V_583 ) ;
F_94 ( V_2 , NULL ) ;
}
goto V_186;
V_582:
F_122 ( V_2 , V_212 ) ;
F_117 ( V_2 ) ;
V_186:
if ( V_25 )
V_232 -> V_238 = NULL ;
return V_25 ;
}
static int F_242 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_569 * V_570 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
V_25 = F_241 ( V_2 , V_212 , V_570 , false ) ;
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static void F_243 ( struct V_1 * V_2 ,
struct V_211 * V_212 ,
struct V_569 * V_570 ,
bool V_579 )
{
struct V_75 * V_232 = F_62 ( V_212 ) ;
struct V_211 * V_584 = NULL ;
F_70 ( & V_2 -> V_227 ) ;
F_159 ( V_2 , V_232 , & V_232 -> V_237 ) ;
switch ( V_212 -> type ) {
case V_84 :
goto V_186;
case V_580 :
V_232 -> V_581 = false ;
V_232 -> V_292 = false ;
break;
case V_81 :
if ( ! V_579 || ! V_232 -> V_430 )
goto V_186;
V_232 -> V_585 = false ;
F_244 ( V_2 , V_232 , true ) ;
F_192 ( V_2 -> V_434 , V_212 ) ;
V_232 -> V_430 = false ;
break;
case V_79 :
if ( ! V_579 )
break;
V_584 = V_212 ;
F_151 ( V_2 , V_212 , true , NULL ) ;
break;
default:
break;
}
F_94 ( V_2 , V_584 ) ;
F_122 ( V_2 , V_212 ) ;
V_186:
V_232 -> V_238 = NULL ;
F_117 ( V_2 ) ;
}
static void F_245 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_569 * V_570 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_54 ( & V_2 -> V_227 ) ;
F_243 ( V_2 , V_212 , V_570 , false ) ;
F_60 ( & V_2 -> V_227 ) ;
}
static int
F_246 ( struct V_1 * V_2 ,
struct V_586 * V_587 )
{
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
F_243 ( V_2 , V_587 [ 0 ] . V_212 , V_587 [ 0 ] . V_588 , true ) ;
F_238 ( V_2 , V_587 [ 0 ] . V_588 ) ;
V_25 = F_236 ( V_2 , V_587 [ 0 ] . V_589 ) ;
if ( V_25 ) {
F_95 ( V_2 , L_48 ) ;
goto V_590;
}
V_25 = F_241 ( V_2 , V_587 [ 0 ] . V_212 , V_587 [ 0 ] . V_589 ,
true ) ;
if ( V_25 ) {
F_95 ( V_2 ,
L_49 ) ;
goto V_429;
}
if ( F_165 ( V_2 ) > 1 )
F_96 ( V_2 ) ;
goto V_186;
V_429:
F_238 ( V_2 , V_587 [ 0 ] . V_589 ) ;
V_590:
if ( F_236 ( V_2 , V_587 [ 0 ] . V_588 ) ) {
F_95 ( V_2 , L_50 ) ;
goto V_591;
}
if ( F_241 ( V_2 , V_587 [ 0 ] . V_212 , V_587 [ 0 ] . V_588 ,
true ) ) {
F_95 ( V_2 , L_51 ) ;
goto V_591;
}
goto V_186;
V_591:
F_247 ( V_2 , false ) ;
V_186:
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static int
F_248 ( struct V_1 * V_2 ,
struct V_586 * V_587 )
{
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
F_243 ( V_2 , V_587 [ 0 ] . V_212 , V_587 [ 0 ] . V_588 , true ) ;
V_25 = F_241 ( V_2 , V_587 [ 0 ] . V_212 , V_587 [ 0 ] . V_589 ,
true ) ;
if ( V_25 ) {
F_95 ( V_2 ,
L_49 ) ;
goto V_590;
}
goto V_186;
V_590:
if ( F_241 ( V_2 , V_587 [ 0 ] . V_212 , V_587 [ 0 ] . V_588 ,
true ) ) {
F_95 ( V_2 , L_51 ) ;
goto V_591;
}
goto V_186;
V_591:
F_247 ( V_2 , false ) ;
V_186:
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static int F_249 ( struct V_22 * V_23 ,
struct V_586 * V_587 ,
int V_592 ,
enum V_593 V_594 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
if ( V_592 > 1 )
return - V_507 ;
switch ( V_594 ) {
case V_595 :
V_25 = F_246 ( V_2 , V_587 ) ;
break;
case V_596 :
V_25 = F_248 ( V_2 , V_587 ) ;
break;
default:
V_25 = - V_507 ;
break;
}
return V_25 ;
}
static int F_250 ( struct V_22 * V_23 ,
struct V_179 * V_180 ,
bool V_597 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_73 * V_472 = ( void * ) V_180 -> V_473 ;
if ( ! V_472 || ! V_472 -> V_212 ) {
F_95 ( V_2 , L_52 ) ;
return - V_229 ;
}
return F_163 ( V_2 , V_472 -> V_212 ) ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_211 * V_212 ,
void * V_198 , int V_152 )
{
struct V_598 * V_599 [ V_600 + 1 ] ;
int V_601 ;
T_5 V_346 ;
V_601 = F_252 ( V_599 , V_600 , V_198 , V_152 , V_602 ) ;
if ( V_601 )
return V_601 ;
if ( ! V_599 [ V_603 ] )
return - V_229 ;
switch ( F_253 ( V_599 [ V_603 ] ) ) {
case V_604 :
if ( ! V_212 || V_212 -> type != V_81 || ! V_212 -> V_335 ||
! V_212 -> V_355 . V_605 ||
! V_599 [ V_606 ] )
return - V_229 ;
V_346 = F_253 ( V_599 [ V_606 ] ) ;
if ( V_346 >= V_212 -> V_355 . V_411 )
return - V_229 ;
V_2 -> V_346 = V_346 ;
V_2 -> V_345 = V_212 ;
return F_94 ( V_2 , NULL ) ;
case V_607 :
if ( ! V_212 || V_212 -> type != V_79 ||
! V_212 -> V_355 . V_356 || ! V_212 -> V_355 . V_608 ||
! V_599 [ V_609 ] )
return - V_229 ;
if ( F_253 ( V_599 [ V_609 ] ) )
return F_160 ( V_2 , V_212 , 0 ) ;
return F_118 ( V_2 , V_212 , 0 ) ;
}
return - V_507 ;
}
static int F_254 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
void * V_198 , int V_152 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_601 ;
F_54 ( & V_2 -> V_227 ) ;
V_601 = F_251 ( V_2 , V_212 , V_198 , V_152 ) ;
F_60 ( & V_2 -> V_227 ) ;
return V_601 ;
}
static void F_255 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_610 * V_611 )
{
F_141 ( F_38 ( V_23 ) ,
L_53 ) ;
}
static int F_256 ( struct V_22 * V_23 ,
struct V_211 * V_212 ,
struct V_610 * V_611 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_211 * V_433 ;
struct V_75 * V_232 = F_62 ( V_212 ) ;
T_5 V_558 ;
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
F_141 ( V_2 , L_54 ,
V_611 -> V_565 . V_612 ) ;
switch ( V_212 -> type ) {
case V_81 :
V_433 =
F_257 ( V_2 -> V_433 ,
F_258 ( & V_2 -> V_227 ) ) ;
if ( F_156 ( V_433 && V_433 -> V_613 ,
L_55 ) ) {
V_25 = - V_454 ;
goto V_331;
}
F_192 ( V_2 -> V_433 , V_212 ) ;
if ( F_156 ( V_232 -> V_585 ,
L_56 ) ) {
V_25 = - V_454 ;
goto V_331;
}
break;
case V_79 :
V_558 = V_611 -> V_614 +
( ( V_212 -> V_355 . V_411 * ( V_611 -> V_242 - 1 ) -
V_615 ) * 1024 ) ;
if ( V_611 -> V_616 )
F_259 ( V_2 , V_212 ) ;
F_260 ( V_2 , V_212 , V_212 -> V_355 . V_411 ,
V_558 ) ;
if ( V_232 -> V_239 . V_426 ) {
V_25 = F_118 ( V_2 , V_212 , 0 ) ;
if ( V_25 )
goto V_331;
}
break;
default:
break;
}
V_232 -> V_292 = true ;
V_25 = F_261 ( V_2 ) ;
if ( V_25 )
goto V_331;
F_96 ( V_2 ) ;
V_331:
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static int F_262 ( struct V_22 * V_23 ,
struct V_211 * V_212 )
{
struct V_75 * V_232 = F_62 ( V_212 ) ;
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_227 ) ;
if ( V_212 -> type == V_79 ) {
struct V_73 * V_183 ;
V_183 = F_263 ( V_2 ,
V_232 -> V_234 ) ;
if ( F_8 ( ! V_183 ) ) {
V_25 = - V_17 ;
goto V_331;
}
F_264 ( V_2 , V_183 , false ) ;
F_151 ( V_2 , V_212 , false , NULL ) ;
V_25 = F_160 ( V_2 , V_212 , 0 ) ;
if ( V_25 )
goto V_331;
F_265 ( V_2 , V_212 ) ;
}
V_232 -> V_292 = false ;
V_25 = F_261 ( V_2 ) ;
V_331:
F_60 ( & V_2 -> V_227 ) ;
return V_25 ;
}
static void F_266 ( struct V_22 * V_23 ,
struct V_211 * V_212 , T_5 V_39 , bool V_199 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_75 * V_232 ;
struct V_73 * V_183 ;
struct V_179 * V_180 ;
int V_9 ;
T_5 V_617 = 0 ;
if ( ! V_212 || V_212 -> type != V_79 )
return;
F_54 ( & V_2 -> V_227 ) ;
V_232 = F_62 ( V_212 ) ;
for ( V_9 = 0 ; V_9 < V_188 ; V_9 ++ ) {
V_180 = F_257 ( V_2 -> V_474 [ V_9 ] ,
F_258 ( & V_2 -> V_227 ) ) ;
if ( F_267 ( V_180 ) )
continue;
V_183 = F_33 ( V_180 ) ;
if ( V_183 -> V_212 != V_212 )
continue;
F_8 ( V_9 != V_232 -> V_234 && ! V_180 -> V_481 ) ;
V_617 |= V_183 -> V_618 ;
}
V_617 &= ~ F_18 ( V_212 -> V_200 [ V_619 ] ) ;
if ( F_128 ( V_2 , V_617 , true ) )
F_95 ( V_2 , L_57 ) ;
F_60 ( & V_2 -> V_227 ) ;
F_268 ( V_2 -> V_7 , V_617 ) ;
}
