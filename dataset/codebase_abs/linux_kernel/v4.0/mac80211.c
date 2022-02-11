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
V_23 -> V_50 = V_51 ;
V_23 -> V_52 = V_53 ;
if ( V_2 -> V_54 -> V_55 . V_26 & V_56 &&
! V_57 . V_58 )
V_23 -> V_26 |= V_59 ;
if ( V_2 -> V_54 -> V_55 . V_60 [ 0 ] & V_61 ||
V_2 -> V_54 -> V_55 . V_62 [ 0 ] & V_63 ) {
V_23 -> V_26 |= V_64 ;
V_23 -> V_65 -> V_66 |=
V_67 |
V_68 ;
}
V_23 -> V_69 = sizeof( struct V_70 ) ;
V_23 -> V_71 = sizeof( struct V_72 ) ;
V_23 -> V_73 = sizeof( V_74 ) ;
V_23 -> V_65 -> V_75 = F_18 ( V_76 ) |
F_18 ( V_77 ) |
F_18 ( V_78 ) |
F_18 ( V_79 ) |
F_18 ( V_80 ) |
F_18 ( V_81 ) ;
V_23 -> V_65 -> V_26 |= V_82 ;
V_23 -> V_65 -> V_83 |= V_84 |
V_85 ;
if ( V_2 -> V_54 -> V_55 . V_26 & V_86 )
V_23 -> V_65 -> V_26 |= V_87 ;
V_23 -> V_65 -> V_26 |= V_88 ;
V_23 -> V_65 -> V_89 = V_90 ;
V_23 -> V_65 -> V_91 =
F_19 ( V_90 ) ;
V_23 -> V_65 -> V_92 = 10000 ;
V_23 -> V_93 = V_94 ;
V_23 -> V_65 -> V_95 = 3 * 5 ;
memcpy ( V_2 -> V_96 [ 0 ] . V_97 , V_2 -> V_98 -> V_99 , V_100 ) ;
V_23 -> V_65 -> V_96 = V_2 -> V_96 ;
V_23 -> V_65 -> V_101 = 1 ;
V_24 = ( V_2 -> V_98 -> V_102 > 1 ) ?
F_20 ( V_103 , V_2 -> V_98 -> V_102 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_24 ; V_9 ++ ) {
memcpy ( V_2 -> V_96 [ V_9 ] . V_97 , V_2 -> V_96 [ V_9 - 1 ] . V_97 ,
V_100 ) ;
V_2 -> V_96 [ V_9 ] . V_97 [ 5 ] ++ ;
V_23 -> V_65 -> V_101 ++ ;
}
F_16 ( V_2 ) ;
V_23 -> V_65 -> V_104 = F_21 ( V_2 , false ) ;
V_23 -> V_65 -> V_105 = V_106 ;
if ( V_2 -> V_98 -> V_107 [ V_108 ] . V_109 )
V_23 -> V_65 -> V_107 [ V_108 ] =
& V_2 -> V_98 -> V_107 [ V_108 ] ;
if ( V_2 -> V_98 -> V_107 [ V_110 ] . V_109 ) {
V_23 -> V_65 -> V_107 [ V_110 ] =
& V_2 -> V_98 -> V_107 [ V_110 ] ;
if ( ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] &
V_111 ) &&
( V_2 -> V_54 -> V_55 . V_60 [ 0 ] &
V_112 ) )
V_23 -> V_65 -> V_107 [ V_110 ] -> V_113 . V_114 |=
V_115 ;
}
V_23 -> V_65 -> V_116 = V_2 -> V_7 -> V_117 ;
if ( V_118 . V_119 != V_120 )
V_23 -> V_65 -> V_26 |= V_121 ;
else
V_23 -> V_65 -> V_26 &= ~ V_121 ;
if ( F_22 ( V_2 -> V_54 -> V_122 ) >= 10 ) {
V_23 -> V_65 -> V_26 |= V_123 ;
V_23 -> V_65 -> V_124 = V_106 ;
V_23 -> V_65 -> V_125 = V_126 ;
V_23 -> V_65 -> V_127 =
V_128 - 24 - 2 ;
}
V_23 -> V_65 -> V_66 |= V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 ;
if ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] &
V_135 )
V_23 -> V_65 -> V_66 |= V_136 ;
if ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] &
V_137 )
V_23 -> V_65 -> V_66 |= V_138 ;
if ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] &
V_139 )
V_23 -> V_65 -> V_66 |=
V_140 ;
if ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] &
V_141 )
V_23 -> V_65 -> V_66 |= V_142 ;
V_2 -> V_143 = V_144 ;
if ( V_2 -> V_54 -> V_145 [ 0 ] . V_146 ) {
V_2 -> V_23 -> V_147 = 1 ;
V_2 -> V_23 -> V_148 = & V_2 -> V_54 -> V_145 [ 0 ] ;
}
#ifdef F_23
if ( F_2 ( V_2 ) &&
F_24 ( V_2 -> V_7 -> V_149 ) ) {
V_2 -> V_150 . V_26 = V_151 ;
V_23 -> V_65 -> V_150 = & V_2 -> V_150 ;
}
if ( V_2 -> V_54 -> V_152 [ V_153 ] . V_154 [ 0 ] . V_155 &&
V_2 -> V_7 -> V_156 -> V_157 &&
V_2 -> V_7 -> V_156 -> V_158 &&
F_24 ( V_2 -> V_7 -> V_149 ) ) {
V_2 -> V_150 . V_26 |= V_159 |
V_160 |
V_161 |
V_162 |
V_163 ;
if ( ! V_57 . V_58 )
V_2 -> V_150 . V_26 |= V_164 |
V_165 |
V_166 ;
V_2 -> V_150 . V_167 = V_168 ;
V_2 -> V_150 . V_169 = V_170 ;
V_2 -> V_150 . V_171 = V_172 ;
V_2 -> V_150 . V_173 = V_126 ;
V_2 -> V_150 . V_174 = & V_175 ;
V_23 -> V_65 -> V_150 = & V_2 -> V_150 ;
}
#endif
#ifdef F_25
V_2 -> V_176 = V_177 ;
#endif
V_25 = F_26 ( V_2 ) ;
if ( V_25 )
return V_25 ;
if ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] & V_178 ) {
F_27 ( V_2 , L_5 ) ;
V_23 -> V_65 -> V_26 |= V_179 ;
}
if ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] &
V_180 ) {
F_27 ( V_2 , L_6 ) ;
V_23 -> V_65 -> V_66 |= V_181 ;
}
V_25 = F_28 ( V_2 -> V_23 ) ;
if ( V_25 )
F_29 ( V_2 ) ;
return V_25 ;
}
static bool F_30 ( struct V_1 * V_2 ,
struct V_182 * V_183 ,
struct V_184 * V_185 )
{
struct V_70 * V_186 ;
bool V_187 = false ;
if ( F_31 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_32 ( & V_2 -> V_188 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_189;
V_186 = F_33 ( V_183 ) ;
if ( V_186 -> V_190 == V_191 ||
V_186 -> V_190 != V_2 -> V_192 )
goto V_189;
F_34 ( & V_2 -> V_193 , V_185 ) ;
F_35 ( V_2 -> V_23 ) ;
F_1 ( V_2 , V_194 ) ;
F_7 ( V_2 , V_194 ) ;
V_187 = true ;
V_189:
F_36 ( & V_2 -> V_188 ) ;
return V_187 ;
}
static void F_37 ( struct V_22 * V_23 ,
struct V_195 * V_196 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_182 * V_183 = V_196 -> V_183 ;
struct V_197 * V_198 = F_39 ( V_185 ) ;
struct V_199 * V_200 = ( void * ) V_185 -> V_201 ;
if ( F_40 ( V_2 ) ) {
F_41 ( V_2 , L_7 ) ;
goto V_202;
}
if ( F_39 ( V_185 ) -> V_203 == V_42 &&
! F_14 ( V_204 , & V_2 -> V_15 ) &&
! F_14 ( V_205 , & V_2 -> V_15 ) )
goto V_202;
if ( F_42 ( V_198 -> V_26 & V_206 &&
F_43 ( V_200 -> V_207 ) &&
! F_44 ( V_200 -> V_207 ) &&
! F_45 ( V_200 -> V_207 ) &&
! F_46 ( V_200 -> V_207 ) ) )
V_183 = NULL ;
if ( V_183 ) {
if ( F_30 ( V_2 , V_183 , V_185 ) )
return;
if ( F_47 ( V_2 , V_185 , V_183 ) )
goto V_202;
return;
}
if ( F_48 ( V_2 , V_185 ) )
goto V_202;
return;
V_202:
F_49 ( V_23 , V_185 ) ;
}
static inline bool F_50 ( const struct V_208 * V_209 )
{
if ( V_57 . V_210 & V_211 )
return false ;
return true ;
}
static inline bool F_51 ( const struct V_208 * V_209 )
{
if ( V_57 . V_210 & V_212 )
return false ;
if ( V_57 . V_210 & V_213 )
return true ;
return true ;
}
static int F_52 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
enum V_216 V_217 ,
struct V_182 * V_183 , V_74 V_218 ,
V_74 * V_219 , T_1 V_220 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
bool V_221 = false ;
F_53 ( V_2 , L_8 ,
V_183 -> V_97 , V_218 , V_217 ) ;
if ( ! ( V_2 -> V_98 -> V_222 ) )
return - V_223 ;
switch ( V_217 ) {
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
V_25 = F_12 ( V_2 , V_229 ) ;
if ( V_25 )
return V_25 ;
V_221 = true ;
break;
default:
break;
}
F_54 ( & V_2 -> V_230 ) ;
switch ( V_217 ) {
case V_231 :
if ( ! F_50 ( V_2 -> V_209 ) ) {
V_25 = - V_232 ;
break;
}
V_25 = F_55 ( V_2 , V_183 , V_218 , * V_219 , true ) ;
break;
case V_233 :
V_25 = F_55 ( V_2 , V_183 , V_218 , 0 , false ) ;
break;
case V_224 :
if ( ! F_51 ( V_2 -> V_209 ) ) {
V_25 = - V_232 ;
break;
}
V_25 = F_56 ( V_2 , V_215 , V_183 , V_218 , V_219 ) ;
break;
case V_225 :
V_25 = F_57 ( V_2 , V_215 , V_183 , V_218 ) ;
break;
case V_226 :
case V_227 :
V_25 = F_58 ( V_2 , V_215 , V_183 , V_218 ) ;
break;
case V_228 :
V_25 = F_59 ( V_2 , V_215 , V_183 , V_218 , V_220 ) ;
break;
default:
F_15 ( 1 ) ;
V_25 = - V_232 ;
break;
}
F_60 ( & V_2 -> V_230 ) ;
if ( V_221 )
F_7 ( V_2 , V_229 ) ;
return V_25 ;
}
static void F_61 ( void * V_201 , T_1 * V_234 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = V_201 ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
V_235 -> V_236 = false ;
V_235 -> V_237 = V_191 ;
F_4 ( & V_2 -> V_238 ) ;
F_63 ( V_2 , & V_235 -> V_239 ) ;
F_5 ( & V_2 -> V_238 ) ;
V_235 -> V_240 = NULL ;
memset ( & V_235 -> V_241 , 0 , sizeof( V_235 -> V_241 ) ) ;
}
static T_2 F_64 ( char * V_242 , T_3 V_243 , T_4 V_244 ,
const void * V_201 , T_4 V_245 )
{
const struct V_246 * V_247 = V_201 ;
T_2 V_248 ;
T_2 V_249 ;
if ( V_243 < V_247 -> V_250 ) {
V_248 = F_65 ( T_2 , V_244 ,
V_247 -> V_250 - V_243 ) ;
memcpy ( V_242 , ( T_1 * ) V_247 -> V_251 + V_243 ,
V_248 ) ;
V_243 += V_248 ;
V_244 -= V_248 ;
if ( V_244 == 0 )
return V_248 ;
} else {
V_248 = 0 ;
}
if ( ! V_247 -> V_252 )
return V_248 ;
V_243 -= V_247 -> V_250 ;
V_249 = F_65 ( T_2 , V_244 ,
V_247 -> V_252 -> V_155 - V_243 ) ;
memcpy ( V_242 + V_248 ,
( T_1 * ) V_247 -> V_252 -> V_201 + V_243 ,
V_249 ) ;
return V_248 + V_249 ;
}
static void F_66 ( const void * V_201 )
{
const struct V_246 * V_253 = V_201 ;
F_67 ( V_253 -> V_251 ) ;
F_67 ( V_253 -> V_252 ) ;
F_68 ( V_253 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_254 * * V_255 )
{
struct V_256 * V_257 ;
T_5 * V_258 ;
T_5 V_259 ;
unsigned long V_26 ;
int V_9 , V_10 ;
if ( ! F_70 ( V_2 -> V_7 , false , & V_26 ) )
return;
for ( V_9 = 0 ; V_9 < F_19 ( V_2 -> V_260 . V_261 ) ; V_9 ++ ) {
T_5 V_262 = V_263 * V_9 ;
V_257 = ( void * ) ( * V_255 ) -> V_201 ;
V_258 = ( void * ) V_257 -> V_201 ;
V_259 = V_2 -> V_260 . V_261 [ V_9 ] ;
if ( V_259 == 0 )
continue;
( * V_255 ) -> type = F_71 ( V_264 ) ;
( * V_255 ) -> V_155 = F_71 ( V_259 + sizeof( * V_257 ) ) ;
V_257 -> V_265 = F_71 ( V_9 ) ;
V_257 -> V_266 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_267 +
V_262 ) ) ;
V_257 -> V_268 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_269 +
V_262 ) ) ;
V_257 -> V_270 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_271 +
V_262 ) ) ;
V_257 -> V_272 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_273 +
V_262 ) ) ;
V_257 -> V_274 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_275 +
V_262 ) ) ;
F_73 ( V_2 -> V_7 ,
V_275 + V_262 , 0x1 ) ;
F_73 ( V_2 -> V_7 ,
V_276 + V_262 , 0x1 ) ;
F_73 ( V_2 -> V_7 ,
V_277 + V_262 ,
0x0 ) ;
V_259 /= sizeof( T_5 ) ;
for ( V_10 = 0 ; V_10 < V_259 ; V_10 ++ )
V_258 [ V_10 ] = F_72 ( V_2 -> V_7 ,
V_278 +
V_262 ) ;
* V_255 = F_74 ( * V_255 ) ;
}
for ( V_9 = 0 ; V_9 < F_19 ( V_2 -> V_260 . V_279 ) ; V_9 ++ ) {
F_73 ( V_2 -> V_7 , V_280 , V_9 ) ;
V_257 = ( void * ) ( * V_255 ) -> V_201 ;
V_258 = ( void * ) V_257 -> V_201 ;
V_259 = V_2 -> V_260 . V_279 [ V_9 ] ;
if ( V_259 == 0 )
continue;
( * V_255 ) -> type = F_71 ( V_281 ) ;
( * V_255 ) -> V_155 = F_71 ( V_259 + sizeof( * V_257 ) ) ;
V_257 -> V_265 = F_71 ( V_9 ) ;
V_257 -> V_266 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_282 ) ) ;
V_257 -> V_268 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_283 ) ) ;
V_257 -> V_270 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_284 ) ) ;
V_257 -> V_272 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_285 ) ) ;
V_257 -> V_274 =
F_71 ( F_72 ( V_2 -> V_7 ,
V_286 ) ) ;
F_73 ( V_2 -> V_7 , V_287 ,
V_283 ) ;
F_72 ( V_2 -> V_7 , V_288 ) ;
V_259 /= sizeof( T_5 ) ;
for ( V_10 = 0 ; V_10 < V_259 ; V_10 ++ )
V_258 [ V_10 ] = F_72 ( V_2 -> V_7 ,
V_288 ) ;
* V_255 = F_74 ( * V_255 ) ;
}
F_75 ( V_2 -> V_7 , & V_26 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_289 * V_290 ;
struct V_254 * V_255 ;
struct V_291 * V_292 ;
struct V_293 * V_294 ;
struct V_246 * V_253 ;
T_5 V_295 , V_296 ;
T_5 V_297 , V_298 = 0 ;
T_5 V_299 = V_2 -> V_209 -> V_299 ;
T_5 V_300 = V_2 -> V_209 -> V_301 ;
F_77 ( & V_2 -> V_230 ) ;
if ( V_2 -> V_209 -> V_302 == V_303 &&
F_78 ( V_2 -> V_7 -> V_304 ) == V_305 ) {
if ( V_299 )
V_299 = 0x38000 ;
if ( V_300 )
V_300 = 0x10000 ;
}
V_253 = F_79 ( sizeof( * V_253 ) , V_306 ) ;
if ( ! V_253 )
return;
if ( ! V_2 -> V_209 -> V_307 || ! V_2 -> V_209 -> V_308 ) {
const struct V_309 * V_152 ;
V_152 = & V_2 -> V_54 -> V_152 [ V_2 -> V_310 ] ;
V_296 = V_152 -> V_154 [ V_311 ] . V_243 ;
V_295 = V_152 -> V_154 [ V_311 ] . V_155 ;
} else {
V_296 = V_2 -> V_209 -> V_307 ;
V_295 = V_2 -> V_209 -> V_308 ;
}
if ( F_14 ( V_312 , & V_2 -> V_7 -> V_15 ) ) {
struct V_313 * V_314 = & V_2 -> V_260 ;
int V_9 ;
V_298 = 0 ;
for ( V_9 = 0 ; V_9 < F_19 ( V_314 -> V_261 ) ; V_9 ++ ) {
if ( ! V_314 -> V_261 [ V_9 ] )
continue;
V_298 += V_314 -> V_261 [ V_9 ] +
sizeof( * V_255 ) +
sizeof( struct V_256 ) ;
}
for ( V_9 = 0 ; V_9 < F_19 ( V_314 -> V_279 ) ; V_9 ++ ) {
if ( ! V_314 -> V_279 [ V_9 ] )
continue;
V_298 += V_314 -> V_279 [ V_9 ] +
sizeof( * V_255 ) +
sizeof( struct V_256 ) ;
}
}
V_297 = sizeof( * V_290 ) +
sizeof( * V_255 ) * 2 +
V_295 + sizeof( * V_294 ) +
V_298 +
sizeof( * V_292 ) ;
if ( V_299 )
V_297 += sizeof( * V_255 ) + sizeof( * V_294 ) + V_299 ;
if ( V_300 )
V_297 += sizeof( * V_255 ) + sizeof( * V_294 ) + V_300 ;
V_290 = F_80 ( V_297 ) ;
if ( ! V_290 ) {
F_68 ( V_253 ) ;
return;
}
V_253 -> V_251 = V_290 ;
V_290 -> V_315 = F_71 ( V_316 ) ;
V_255 = ( void * ) V_290 -> V_201 ;
V_255 -> type = F_71 ( V_317 ) ;
V_255 -> V_155 = F_71 ( sizeof( * V_292 ) ) ;
V_292 = ( void * ) V_255 -> V_201 ;
V_292 -> V_302 =
V_2 -> V_209 -> V_302 == V_318 ?
F_71 ( V_319 ) :
F_71 ( V_320 ) ;
V_292 -> V_321 = F_71 ( F_78 ( V_2 -> V_7 -> V_304 ) ) ;
memcpy ( V_292 -> V_322 , V_2 -> V_54 -> V_323 ,
sizeof( V_292 -> V_322 ) ) ;
strncpy ( V_292 -> V_324 , V_2 -> V_209 -> V_325 ,
sizeof( V_292 -> V_324 ) ) ;
strncpy ( V_292 -> V_326 , V_2 -> V_149 -> V_327 -> V_325 ,
sizeof( V_292 -> V_326 ) ) ;
V_255 = F_74 ( V_255 ) ;
if ( F_14 ( V_312 , & V_2 -> V_7 -> V_15 ) )
F_69 ( V_2 , & V_255 ) ;
V_255 -> type = F_71 ( V_328 ) ;
V_255 -> V_155 = F_71 ( V_295 + sizeof( * V_294 ) ) ;
V_294 = ( void * ) V_255 -> V_201 ;
V_294 -> type = F_71 ( V_329 ) ;
V_294 -> V_243 = F_71 ( V_296 ) ;
F_81 ( V_2 -> V_7 , V_296 , V_294 -> V_201 ,
V_295 ) ;
if ( V_299 ) {
V_255 = F_74 ( V_255 ) ;
V_255 -> type = F_71 ( V_328 ) ;
V_255 -> V_155 = F_71 ( V_299 + sizeof( * V_294 ) ) ;
V_294 = ( void * ) V_255 -> V_201 ;
V_294 -> type = F_71 ( V_330 ) ;
V_294 -> V_243 = F_71 ( V_2 -> V_209 -> V_331 ) ;
F_81 ( V_2 -> V_7 , V_2 -> V_209 -> V_331 ,
V_294 -> V_201 , V_299 ) ;
}
if ( V_300 ) {
V_255 = F_74 ( V_255 ) ;
V_255 -> type = F_71 ( V_328 ) ;
V_255 -> V_155 = F_71 ( V_300 + sizeof( * V_294 ) ) ;
V_294 = ( void * ) V_255 -> V_201 ;
V_294 -> type = F_71 ( V_329 ) ;
V_294 -> V_243 = F_71 ( V_2 -> V_209 -> V_332 ) ;
F_81 ( V_2 -> V_7 , V_2 -> V_209 -> V_332 ,
V_294 -> V_201 , V_300 ) ;
}
V_253 -> V_252 = F_82 ( V_2 -> V_7 ) ;
V_253 -> V_250 = V_297 ;
if ( V_253 -> V_252 )
V_297 += V_253 -> V_252 -> V_155 ;
V_290 -> V_297 = F_71 ( V_297 ) ;
F_83 ( V_2 -> V_7 -> V_149 , V_333 , V_253 , 0 ,
V_306 , F_64 , F_66 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( ! F_85 ( V_334 , & V_2 -> V_15 ) )
F_76 ( V_2 ) ;
F_10 ( V_2 , V_335 ) ;
F_86 ( V_2 -> V_7 ) ;
V_2 -> V_336 = V_337 ;
V_2 -> V_338 = false ;
V_2 -> V_339 = false ;
F_87 ( V_2 -> V_23 ) ;
F_88 (
V_2 -> V_23 , V_340 ,
F_61 , V_2 ) ;
V_2 -> V_341 = NULL ;
V_2 -> V_192 = V_191 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_342 , 0 , sizeof( V_2 -> V_342 ) ) ;
memset ( V_2 -> V_343 , 0 , sizeof( V_2 -> V_343 ) ) ;
memset ( V_2 -> V_344 , 0 , sizeof( V_2 -> V_344 ) ) ;
memset ( & V_2 -> V_345 , 0 , sizeof( V_2 -> V_345 ) ) ;
memset ( & V_2 -> V_346 , 0 , sizeof( V_2 -> V_346 ) ) ;
memset ( & V_2 -> V_347 , 0 , sizeof( V_2 -> V_347 ) ) ;
memset ( & V_2 -> V_348 , 0 , sizeof( V_2 -> V_348 ) ) ;
memset ( & V_2 -> V_349 , 0 , sizeof( V_2 -> V_349 ) ) ;
memset ( & V_2 -> V_350 , 0 , sizeof( V_2 -> V_350 ) ) ;
F_89 ( V_2 -> V_23 ) ;
F_90 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_351 = 0 ;
V_2 -> V_352 = 0 ;
}
int F_91 ( struct V_1 * V_2 )
{
int V_25 ;
F_77 ( & V_2 -> V_230 ) ;
if ( F_14 ( V_353 , & V_2 -> V_15 ) )
F_84 ( V_2 ) ;
V_25 = F_92 ( V_2 ) ;
if ( V_25 && F_14 ( V_353 , & V_2 -> V_15 ) ) {
F_90 ( V_353 , & V_2 -> V_15 ) ;
F_93 ( V_2 , NULL ) ;
}
return V_25 ;
}
static int F_94 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
if ( F_14 ( V_353 , & V_2 -> V_15 ) ) {
F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ;
}
F_54 ( & V_2 -> V_230 ) ;
V_25 = F_91 ( V_2 ) ;
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static void F_95 ( struct V_1 * V_2 )
{
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
F_90 ( V_353 , & V_2 -> V_15 ) ;
F_93 ( V_2 , NULL ) ;
V_25 = F_96 ( V_2 , NULL ) ;
if ( V_25 )
F_97 ( V_2 , L_9 ,
V_25 ) ;
F_7 ( V_2 , V_335 ) ;
F_98 ( V_2 ) ;
F_60 ( & V_2 -> V_230 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
bool V_354 ;
if ( ! F_2 ( V_2 ) )
return;
F_54 ( & V_2 -> V_355 ) ;
F_100 ( V_356 , & V_2 -> V_357 ) ;
V_354 = F_101 ( V_358 ,
& V_2 -> V_357 ) ;
F_60 ( & V_2 -> V_355 ) ;
if ( V_354 ) {
F_3 ( V_2 , L_10 ) ;
F_102 ( V_2 ) ;
}
if ( V_2 -> V_7 -> V_359 == V_360 )
if ( ! F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) )
F_103 ( 1 , L_11 ) ;
}
static void
F_104 ( struct V_22 * V_23 ,
enum V_361 V_362 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
switch ( V_362 ) {
case V_363 :
F_95 ( V_2 ) ;
break;
case V_364 :
F_99 ( V_2 ) ;
break;
}
}
void F_105 ( struct V_1 * V_2 )
{
F_77 ( & V_2 -> V_230 ) ;
if ( ! F_14 ( V_353 , & V_2 -> V_15 ) )
F_1 ( V_2 , V_335 ) ;
F_106 ( & V_2 -> V_365 ) ;
F_86 ( V_2 -> V_7 ) ;
F_107 ( V_2 ) ;
F_108 ( V_2 ) ;
F_90 ( V_353 , & V_2 -> V_15 ) ;
V_2 -> V_366 = false ;
}
static void F_109 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_110 ( & V_2 -> V_367 ) ;
F_110 ( & V_2 -> V_368 ) ;
F_110 ( & V_2 -> V_369 ) ;
F_54 ( & V_2 -> V_230 ) ;
F_105 ( V_2 ) ;
F_60 ( & V_2 -> V_230 ) ;
F_106 ( & V_2 -> V_368 ) ;
}
static struct V_370 * F_111 ( struct V_1 * V_2 )
{
V_74 V_9 ;
F_77 ( & V_2 -> V_230 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_97 ( V_2 , L_12 ) ;
return NULL ;
}
static int F_112 ( struct V_1 * V_2 , struct V_214 * V_215 ,
T_6 V_371 )
{
struct V_372 V_373 = {
. V_374 = F_62 ( V_215 ) -> V_20 ,
. V_375 = F_113 ( V_371 ) ,
} ;
return F_114 ( V_2 , V_376 , 0 ,
sizeof( V_373 ) ,
& V_373 ) ;
}
static int F_115 ( struct V_22 * V_23 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
int V_25 ;
V_25 = F_12 ( V_2 , V_377 ) ;
if ( V_25 )
return V_25 ;
F_54 ( & V_2 -> V_230 ) ;
V_25 = F_116 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_378;
if ( V_215 -> type != V_80 )
V_2 -> V_351 ++ ;
if ( V_215 -> type == V_78 ||
V_215 -> type == V_81 ) {
V_25 = F_117 ( V_2 , V_215 ) ;
if ( V_25 ) {
F_97 ( V_2 , L_13 ) ;
goto V_379;
}
F_118 ( V_2 , V_215 ) ;
goto V_378;
}
V_25 = F_119 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_379;
V_25 = F_120 ( V_2 ) ;
if ( V_25 )
goto V_380;
V_25 = F_121 ( V_2 , V_215 , 0 ) ;
if ( V_25 )
goto V_380;
if ( ! V_2 -> V_381 &&
V_215 -> type == V_76 && ! V_215 -> V_382 ) {
V_2 -> V_381 = V_235 ;
V_215 -> V_383 |= V_384 |
V_385 ;
}
if ( V_215 -> type == V_80 ) {
V_235 -> V_240 = F_111 ( V_2 ) ;
if ( ! V_235 -> V_240 ) {
V_25 = - V_386 ;
goto V_387;
}
F_122 ( V_2 , V_235 -> V_240 ) ;
V_25 = F_123 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_388;
V_25 = F_124 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_389;
V_2 -> V_341 = V_215 ;
}
F_118 ( V_2 , V_215 ) ;
goto V_378;
V_389:
F_125 ( V_2 , V_215 ) ;
V_388:
F_126 ( V_2 , V_235 -> V_240 ) ;
V_387:
if ( V_2 -> V_381 == V_235 ) {
V_2 -> V_381 = NULL ;
V_215 -> V_383 &= ~ ( V_384 |
V_385 ) ;
}
V_380:
V_235 -> V_240 = NULL ;
F_127 ( V_2 , V_215 ) ;
V_379:
if ( V_215 -> type != V_80 )
V_2 -> V_351 -- ;
F_128 ( V_2 , V_215 ) ;
V_378:
F_60 ( & V_2 -> V_230 ) ;
F_7 ( V_2 , V_377 ) ;
return V_25 ;
}
static void F_129 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
T_5 V_390 = F_130 ( V_215 ) ;
if ( V_390 ) {
F_54 ( & V_2 -> V_230 ) ;
F_131 ( V_2 , V_390 , true ) ;
F_60 ( & V_2 -> V_230 ) ;
}
if ( V_215 -> type == V_80 ) {
F_110 ( & V_2 -> V_365 ) ;
} else {
F_110 ( & V_2 -> V_391 ) ;
}
}
static void F_132 ( struct V_22 * V_23 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
F_129 ( V_2 , V_215 ) ;
F_54 ( & V_2 -> V_230 ) ;
if ( V_2 -> V_381 == V_235 ) {
V_2 -> V_381 = NULL ;
V_215 -> V_383 &= ~ ( V_384 |
V_385 ) ;
}
F_133 ( V_2 , V_215 ) ;
if ( V_215 -> type == V_78 ||
V_215 -> type == V_81 ) {
#ifdef F_134
if ( V_215 == V_2 -> V_392 ) {
V_2 -> V_392 = NULL ;
V_2 -> V_393 = 0 ;
}
#endif
F_135 ( V_2 , V_215 ) ;
goto V_379;
}
if ( V_215 -> type == V_80 ) {
V_2 -> V_341 = NULL ;
F_136 ( V_2 , V_215 ) ;
F_125 ( V_2 , V_215 ) ;
F_126 ( V_2 , V_235 -> V_240 ) ;
V_235 -> V_240 = NULL ;
}
if ( V_2 -> V_351 && V_215 -> type != V_80 )
V_2 -> V_351 -- ;
F_120 ( V_2 ) ;
F_127 ( V_2 , V_215 ) ;
V_379:
F_128 ( V_2 , V_215 ) ;
F_60 ( & V_2 -> V_230 ) ;
}
static int F_137 ( struct V_22 * V_23 , T_5 V_394 )
{
return 0 ;
}
static void F_138 ( void * V_395 , T_1 * V_234 ,
struct V_214 * V_215 )
{
struct V_396 * V_201 = V_395 ;
struct V_1 * V_2 = V_201 -> V_2 ;
struct V_397 * V_398 = V_2 -> V_399 ;
int V_25 , V_155 ;
if ( F_15 ( V_201 -> V_400 >= V_401 ) )
return;
if ( V_215 -> type != V_76 ||
! V_215 -> V_402 . V_403 )
return;
V_398 -> V_400 = V_201 -> V_400 ++ ;
memcpy ( V_398 -> V_404 , V_215 -> V_402 . V_404 , V_100 ) ;
V_155 = F_139 ( sizeof( * V_398 ) + V_398 -> V_244 * V_100 , 4 ) ;
V_25 = F_114 ( V_2 , V_405 , V_406 , V_155 , V_398 ) ;
if ( V_25 )
F_97 ( V_2 , L_14 , V_25 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_396 V_407 = {
. V_2 = V_2 ,
} ;
F_77 ( & V_2 -> V_230 ) ;
if ( F_15 ( ! V_2 -> V_399 ) )
return;
F_88 (
V_2 -> V_23 , V_408 ,
F_138 , & V_407 ) ;
}
static T_7 F_141 ( struct V_22 * V_23 ,
struct V_409 * V_410 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_397 * V_398 ;
struct V_411 * V_97 ;
int V_412 ;
bool V_413 ;
int V_155 ;
V_412 = F_142 ( V_410 ) ;
V_413 = V_412 > V_414 ||
V_415 ;
if ( V_413 )
V_412 = 0 ;
V_155 = F_139 ( sizeof( * V_398 ) + V_412 * V_100 , 4 ) ;
V_398 = F_79 ( V_155 , V_416 ) ;
if ( ! V_398 )
return 0 ;
if ( V_413 ) {
V_398 -> V_413 = 1 ;
return ( T_7 ) ( unsigned long ) V_398 ;
}
F_143 (addr, mc_list) {
F_144 ( V_2 , L_15 ,
V_398 -> V_244 , V_97 -> V_97 ) ;
memcpy ( & V_398 -> V_417 [ V_398 -> V_244 * V_100 ] ,
V_97 -> V_97 , V_100 ) ;
V_398 -> V_244 ++ ;
}
return ( T_7 ) ( unsigned long ) V_398 ;
}
static void F_145 ( struct V_22 * V_23 ,
unsigned int V_418 ,
unsigned int * V_419 ,
T_7 V_420 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_397 * V_398 = ( void * ) ( unsigned long ) V_420 ;
F_54 ( & V_2 -> V_230 ) ;
F_68 ( V_2 -> V_399 ) ;
V_2 -> V_399 = V_398 ;
if ( ! V_398 )
goto V_189;
F_140 ( V_2 ) ;
V_189:
F_60 ( & V_2 -> V_230 ) ;
* V_419 = 0 ;
}
static void
F_146 ( struct V_214 * V_215 ,
const struct V_421 * V_422 ,
struct V_421 * V_423 )
{
struct V_424 * V_425 ;
int V_9 ;
memcpy ( V_423 , V_422 , sizeof( * V_423 ) ) ;
for ( V_9 = 0 ; V_9 < F_19 ( V_423 -> V_426 ) ; V_9 ++ ) {
V_425 = & V_423 -> V_426 [ V_9 ] ;
if ( ! V_425 -> V_427 )
break;
switch ( V_425 -> V_428 ) {
case F_113 ( V_429 ) :
if ( V_215 -> V_402 . V_430 != 1 ) {
V_425 -> V_427 = 0 ;
continue;
}
V_425 -> V_431 = V_215 -> V_402 . V_432 [ 0 ] ;
break;
case F_113 ( V_433 ) :
V_425 -> V_431 = * ( V_434 * ) & V_215 -> V_97 [ 2 ] ;
break;
default:
break;
}
V_425 -> V_428 = 0 ;
V_423 -> V_435 ++ ;
}
}
static void F_147 ( void * V_395 , T_1 * V_234 ,
struct V_214 * V_215 )
{
struct V_436 * V_201 = V_395 ;
struct V_1 * V_2 = V_201 -> V_2 ;
struct V_437 * V_398 = V_201 -> V_398 ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
struct V_438 * V_439 ;
int V_9 ;
if ( F_8 ( V_235 -> V_20 >= F_19 ( V_398 -> V_440 ) ) )
return;
V_439 = & V_398 -> V_440 [ V_235 -> V_20 ] ;
if ( V_215 -> type != V_76 || V_215 -> V_382 ||
! V_215 -> V_402 . V_403 )
return;
V_439 -> V_441 = 1 ;
for ( V_9 = 0 ; V_2 -> V_176 [ V_9 ] . V_426 [ 0 ] . V_427 ; V_9 ++ ) {
if ( F_15 ( V_201 -> V_442 >=
F_19 ( V_398 -> V_443 ) ) ) {
V_439 -> V_441 = 0 ;
V_439 -> V_444 = 0 ;
break;
}
F_146 ( V_215 ,
& V_2 -> V_176 [ V_9 ] ,
& V_398 -> V_443 [ V_201 -> V_442 ] ) ;
if ( ! V_398 -> V_443 [ V_201 -> V_442 ] . V_435 )
continue;
V_439 -> V_444 |=
F_113 ( F_18 ( V_201 -> V_442 ) ) ;
V_201 -> V_442 ++ ;
}
}
bool F_148 ( struct V_1 * V_2 ,
struct V_437 * V_398 )
{
struct V_436 V_407 = {
. V_2 = V_2 ,
. V_398 = V_398 ,
} ;
if ( V_445 )
return false ;
memset ( V_398 , 0 , sizeof( * V_398 ) ) ;
V_398 -> V_446 = F_19 ( V_398 -> V_443 ) ;
V_398 -> V_447 = F_19 ( V_398 -> V_440 ) ;
#ifdef F_149
if ( V_2 -> V_448 . V_449 ) {
memcpy ( V_398 -> V_443 , & V_2 -> V_448 . V_398 . V_443 ,
sizeof( V_398 -> V_443 ) ) ;
memcpy ( V_398 -> V_440 , & V_2 -> V_448 . V_398 . V_440 ,
sizeof( V_398 -> V_440 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_176 )
return false ;
F_150 (
V_2 -> V_23 , V_408 ,
F_147 , & V_407 ) ;
return true ;
}
static int F_151 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
struct V_437 V_398 ;
if ( ! ( V_2 -> V_54 -> V_55 . V_26 & V_450 ) )
return 0 ;
if ( ! F_148 ( V_2 , & V_398 ) )
return 0 ;
return F_114 ( V_2 , V_451 , 0 ,
sizeof( V_398 ) , & V_398 ) ;
}
static inline int F_151 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
return 0 ;
}
static void F_152 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
struct V_452 * V_402 ,
T_5 V_453 )
{
struct V_72 * V_235 = F_62 ( V_215 ) ;
int V_25 ;
if ( V_453 & V_454 && V_402 -> V_403 )
F_153 ( V_2 , V_215 ) ;
if ( V_453 & V_455 && ! V_235 -> V_456 )
memcpy ( V_235 -> V_404 , V_402 -> V_404 , V_100 ) ;
V_25 = F_154 ( V_2 , V_215 , false , V_235 -> V_404 ) ;
if ( V_25 )
F_97 ( V_2 , L_16 , V_215 -> V_97 ) ;
memcpy ( V_235 -> V_404 , V_402 -> V_404 , V_100 ) ;
V_235 -> V_456 = V_402 -> V_403 ;
if ( V_453 & V_454 ) {
if ( V_402 -> V_403 ) {
V_25 = F_96 ( V_2 , NULL ) ;
if ( V_25 ) {
F_97 ( V_2 , L_17 ) ;
return;
}
if ( F_14 ( V_353 ,
& V_2 -> V_15 ) ) {
T_5 V_457 = ( 11 * V_215 -> V_402 . V_458 ) / 10 ;
F_155 ( V_2 , V_215 , V_457 , V_457 ,
5 * V_457 , false ) ;
}
F_156 ( V_2 , V_215 , false ) ;
F_157 ( V_2 , V_215 ) ;
if ( V_215 -> V_382 ) {
F_1 ( V_2 , V_459 ) ;
F_158 ( V_2 , V_215 ,
V_460 ,
V_461 ) ;
}
} else if ( V_235 -> V_237 != V_191 ) {
F_103 ( F_156 ( V_2 , V_215 , false ) ,
L_18 ) ;
V_25 = F_159 ( V_2 , V_215 , V_235 -> V_237 ) ;
if ( V_25 )
F_97 ( V_2 , L_19 ) ;
if ( V_2 -> V_192 == V_235 -> V_237 )
V_2 -> V_192 = V_191 ;
V_235 -> V_237 = V_191 ;
V_25 = F_96 ( V_2 , NULL ) ;
if ( V_25 )
F_97 ( V_2 , L_17 ) ;
if ( V_215 -> V_382 )
F_7 ( V_2 , V_459 ) ;
V_25 = F_154 ( V_2 , V_215 , false , NULL ) ;
if ( V_25 )
F_97 ( V_2 ,
L_20 ,
V_215 -> V_97 ) ;
}
F_140 ( V_2 ) ;
F_151 ( V_2 , V_215 ) ;
V_235 -> V_241 . V_462 = 0 ;
F_160 ( V_2 ) ;
F_158 ( V_2 , V_215 , V_463 ,
V_464 ) ;
} else if ( V_453 & V_465 ) {
F_161 ( V_2 , V_235 ,
& V_235 -> V_239 ) ;
}
if ( V_453 & V_465 ) {
F_156 ( V_2 , V_215 , false ) ;
F_8 ( F_162 ( V_2 , V_215 , 0 ) ) ;
}
if ( V_453 & ( V_466 | V_467 | V_468 ) ) {
V_25 = F_120 ( V_2 ) ;
if ( V_25 )
F_97 ( V_2 , L_21 ) ;
}
if ( V_453 & V_469 ) {
F_163 ( V_2 , L_22 ,
V_402 -> V_470 ) ;
F_112 ( V_2 , V_215 , V_402 -> V_470 ) ;
}
if ( V_453 & V_471 ) {
F_144 ( V_2 , L_23 ) ;
V_235 -> V_241 . V_472 = 0 ;
if ( V_235 -> V_241 . V_473 ) {
V_25 = F_162 ( V_2 , V_215 , 0 ) ;
if ( V_25 )
F_97 ( V_2 ,
L_24 ) ;
}
}
if ( V_453 & V_474 ) {
F_144 ( V_2 , L_25 ) ;
F_151 ( V_2 , V_215 ) ;
}
}
static int F_164 ( struct V_22 * V_23 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
int V_25 ;
V_25 = F_12 ( V_2 , V_475 ) ;
if ( V_25 )
return V_25 ;
F_54 ( & V_2 -> V_230 ) ;
V_25 = F_165 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_378;
if ( V_215 -> type == V_78 )
F_153 ( V_2 , V_215 ) ;
V_25 = F_119 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_378;
V_25 = F_123 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_476;
V_25 = F_166 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_389;
V_235 -> V_477 = true ;
F_120 ( V_2 ) ;
V_25 = F_96 ( V_2 , NULL ) ;
if ( V_25 )
goto V_478;
if ( V_215 -> V_382 && V_2 -> V_341 )
F_154 ( V_2 , V_2 -> V_341 , false , NULL ) ;
F_1 ( V_2 , V_479 ) ;
F_160 ( V_2 ) ;
if ( F_167 ( V_2 ) > 1 )
F_98 ( V_2 ) ;
F_60 ( & V_2 -> V_230 ) ;
return 0 ;
V_478:
F_120 ( V_2 ) ;
V_235 -> V_477 = false ;
F_168 ( V_2 , V_215 ) ;
V_389:
F_125 ( V_2 , V_215 ) ;
V_476:
F_127 ( V_2 , V_215 ) ;
V_378:
F_60 ( & V_2 -> V_230 ) ;
F_7 ( V_2 , V_475 ) ;
return V_25 ;
}
static void F_169 ( struct V_22 * V_23 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
F_129 ( V_2 , V_215 ) ;
F_54 ( & V_2 -> V_230 ) ;
if ( F_170 ( V_2 -> V_480 ) == V_215 ) {
F_161 ( V_2 , V_235 ,
& V_235 -> V_239 ) ;
F_171 ( V_2 -> V_480 , NULL ) ;
}
if ( F_170 ( V_2 -> V_481 ) == V_215 ) {
F_171 ( V_2 -> V_481 , NULL ) ;
V_2 -> V_482 = 0 ;
}
V_235 -> V_477 = false ;
V_2 -> V_483 = 0 ;
F_160 ( V_2 ) ;
F_7 ( V_2 , V_479 ) ;
if ( V_215 -> V_382 && V_2 -> V_341 )
F_154 ( V_2 , V_2 -> V_341 , false , NULL ) ;
F_96 ( V_2 , NULL ) ;
F_168 ( V_2 , V_215 ) ;
F_125 ( V_2 , V_215 ) ;
F_120 ( V_2 ) ;
F_127 ( V_2 , V_215 ) ;
F_60 ( & V_2 -> V_230 ) ;
}
static void
F_172 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
struct V_452 * V_402 ,
T_5 V_453 )
{
struct V_72 * V_235 = F_62 ( V_215 ) ;
if ( ! V_235 -> V_477 )
return;
if ( V_453 & ( V_484 | V_485 |
V_486 | V_468 ) &&
F_154 ( V_2 , V_215 , false , NULL ) )
F_97 ( V_2 , L_16 , V_215 -> V_97 ) ;
if ( V_453 & V_487 &&
F_165 ( V_2 , V_215 ) )
F_173 ( V_2 , L_26 ) ;
if ( V_453 & V_469 ) {
F_163 ( V_2 , L_22 ,
V_402 -> V_470 ) ;
F_112 ( V_2 , V_215 , V_402 -> V_470 ) ;
}
}
static void F_174 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_452 * V_402 ,
T_5 V_453 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
if ( F_12 ( V_2 , V_488 ) )
return;
F_54 ( & V_2 -> V_230 ) ;
if ( V_453 & V_489 && ! V_402 -> V_490 )
F_175 ( V_2 , true ) ;
switch ( V_215 -> type ) {
case V_76 :
F_152 ( V_2 , V_215 , V_402 , V_453 ) ;
break;
case V_78 :
case V_81 :
F_172 ( V_2 , V_215 , V_402 , V_453 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_60 ( & V_2 -> V_230 ) ;
F_7 ( V_2 , V_488 ) ;
}
static int F_176 ( struct V_1 * V_2 ,
enum V_491 V_492 )
{
int V_25 ;
bool V_493 = false ;
F_54 ( & V_2 -> V_230 ) ;
if ( V_2 -> V_336 != V_492 ) {
V_25 = 0 ;
V_493 = true ;
goto V_189;
}
switch ( V_492 ) {
case V_494 :
V_25 = F_175 ( V_2 , true ) ;
break;
case V_495 :
V_25 = F_177 ( V_2 ) ;
break;
case V_337 :
default:
F_15 ( 1 ) ;
V_25 = - V_232 ;
break;
}
if ( V_25 )
goto V_189;
V_493 = true ;
V_189:
F_60 ( & V_2 -> V_230 ) ;
if ( V_493 )
F_178 ( V_2 ) ;
return V_25 ;
}
static int F_179 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_496 * V_497 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_498 * V_499 = & V_497 -> V_499 ;
int V_25 ;
if ( V_499 -> V_109 == 0 ||
V_499 -> V_109 > V_2 -> V_54 -> V_55 . V_500 )
return - V_232 ;
if ( ! ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] & V_63 ) ) {
V_25 = F_176 ( V_2 , V_494 ) ;
if ( V_25 )
return V_25 ;
}
F_54 ( & V_2 -> V_230 ) ;
if ( V_2 -> V_336 != V_337 ) {
V_25 = - V_501 ;
goto V_189;
}
F_1 ( V_2 , V_502 ) ;
if ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] & V_63 )
V_25 = F_180 ( V_2 , V_215 , V_497 ) ;
else if ( V_2 -> V_54 -> V_55 . V_60 [ 0 ] & V_61 )
V_25 = F_181 ( V_2 , V_215 , V_497 ) ;
else
V_25 = F_182 ( V_2 , V_215 , V_499 ) ;
if ( V_25 )
F_7 ( V_2 , V_502 ) ;
V_189:
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static void F_183 ( struct V_22 * V_23 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_54 ( & V_2 -> V_230 ) ;
if ( ( V_2 -> V_336 == V_495 ) ||
( V_2 -> V_54 -> V_55 . V_62 [ 0 ] & V_63 ) )
F_177 ( V_2 ) ;
F_60 ( & V_2 -> V_230 ) ;
}
static void
F_184 ( struct V_22 * V_23 ,
struct V_182 * V_183 , V_74 V_503 ,
int V_504 ,
enum V_505 V_506 ,
bool V_507 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_185 ( V_2 , V_183 , V_506 , V_504 ,
V_503 , V_507 , false ) ;
}
static void
F_186 ( struct V_22 * V_23 ,
struct V_182 * V_183 , V_74 V_503 ,
int V_504 ,
enum V_505 V_506 ,
bool V_507 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_185 ( V_2 , V_183 , V_506 , V_504 ,
V_503 , V_507 , true ) ;
}
static void F_187 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
enum V_508 V_398 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_70 * V_186 = F_33 ( V_183 ) ;
int V_218 ;
switch ( V_398 ) {
case V_509 :
if ( F_188 ( & V_2 -> V_510 [ V_186 -> V_190 ] ) > 0 )
F_189 ( V_23 , V_183 , true ) ;
F_4 ( & V_186 -> V_511 ) ;
for ( V_218 = 0 ; V_218 < V_512 ; V_218 ++ ) {
struct V_513 * V_514 ;
V_514 = & V_186 -> V_514 [ V_218 ] ;
if ( V_514 -> V_515 != V_516 &&
V_514 -> V_515 != V_517 )
continue;
if ( F_190 ( V_514 ) == 0 )
continue;
F_191 ( V_183 , V_218 , true ) ;
}
F_5 ( & V_186 -> V_511 ) ;
break;
case V_518 :
if ( F_8 ( V_186 -> V_190 == V_191 ) )
break;
F_192 ( V_2 , V_183 ) ;
break;
default:
break;
}
}
static void F_193 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_70 * V_519 = F_33 ( V_183 ) ;
F_54 ( & V_2 -> V_230 ) ;
if ( V_183 == F_170 ( V_2 -> V_520 [ V_519 -> V_190 ] ) )
F_194 ( V_2 -> V_520 [ V_519 -> V_190 ] ,
F_195 ( - V_521 ) ) ;
F_60 ( & V_2 -> V_230 ) ;
}
static void F_196 ( struct V_1 * V_2 , struct V_214 * V_215 ,
const T_1 * V_404 )
{
if ( ! ( V_2 -> V_54 -> V_55 . V_26 & V_522 ) )
return;
if ( V_57 . V_523 ) {
V_215 -> V_383 &= ~ V_524 ;
return;
}
V_215 -> V_383 |= V_524 ;
}
static int F_197 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_182 * V_183 ,
enum V_525 V_526 ,
enum V_525 V_527 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
int V_25 ;
F_144 ( V_2 , L_27 ,
V_183 -> V_97 , V_526 , V_527 ) ;
if ( F_15 ( ! V_235 -> V_240 ) )
return - V_232 ;
F_110 ( & V_2 -> V_391 ) ;
F_54 ( & V_2 -> V_230 ) ;
if ( V_526 == V_528 &&
V_527 == V_529 ) {
if ( V_215 -> type == V_76 &&
V_215 -> V_402 . V_458 < 16 ) {
F_97 ( V_2 ,
L_28 ,
V_183 -> V_97 , V_215 -> V_402 . V_458 ) ;
V_25 = - V_232 ;
goto V_378;
}
if ( V_183 -> V_530 &&
( V_215 -> V_382 ||
F_198 ( V_2 , NULL ) ==
V_531 ||
F_167 ( V_2 ) > 1 ) ) {
F_144 ( V_2 , L_29 ) ;
V_25 = - V_501 ;
goto V_378;
}
V_25 = F_199 ( V_2 , V_215 , V_183 ) ;
if ( V_183 -> V_530 && V_25 == 0 )
F_200 ( V_2 , V_215 , true ) ;
} else if ( V_526 == V_529 &&
V_527 == V_532 ) {
V_2 -> V_533 = true ;
F_196 ( V_2 , V_215 , V_183 -> V_97 ) ;
V_25 = 0 ;
} else if ( V_526 == V_532 &&
V_527 == V_534 ) {
V_25 = F_201 ( V_2 , V_215 , V_183 ) ;
if ( V_25 == 0 )
F_202 ( V_2 , V_183 ,
V_235 -> V_240 -> V_535 -> V_536 ,
true ) ;
} else if ( V_526 == V_534 &&
V_527 == V_537 ) {
if ( F_167 ( V_2 ) > 1 )
F_98 ( V_2 ) ;
F_8 ( F_162 ( V_2 , V_215 , 0 ) ) ;
V_25 = 0 ;
} else if ( V_526 == V_537 &&
V_527 == V_534 ) {
F_8 ( F_121 ( V_2 , V_215 , 0 ) ) ;
V_25 = 0 ;
} else if ( V_526 == V_534 &&
V_527 == V_532 ) {
V_25 = 0 ;
} else if ( V_526 == V_532 &&
V_527 == V_529 ) {
V_25 = 0 ;
} else if ( V_526 == V_529 &&
V_527 == V_528 ) {
V_25 = F_203 ( V_2 , V_215 , V_183 ) ;
if ( V_183 -> V_530 )
F_200 ( V_2 , V_215 , false ) ;
} else {
V_25 = - V_17 ;
}
V_378:
F_60 ( & V_2 -> V_230 ) ;
if ( V_183 -> V_530 && V_25 == 0 ) {
if ( V_526 == V_528 &&
V_527 == V_529 )
F_204 ( V_183 , V_538 ) ;
else if ( V_526 == V_529 &&
V_527 == V_528 )
F_205 ( V_183 , V_538 ) ;
}
return V_25 ;
}
static int F_206 ( struct V_22 * V_23 , T_5 V_539 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
V_2 -> V_143 = V_539 ;
return 0 ;
}
static void F_207 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_182 * V_183 , T_5 V_394 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
if ( V_215 -> type == V_76 &&
V_394 & V_540 )
F_156 ( V_2 , V_215 , false ) ;
}
static int F_208 ( struct V_22 * V_23 ,
struct V_214 * V_215 , V_74 V_541 ,
const struct V_542 * V_543 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
V_235 -> V_544 [ V_541 ] = * V_543 ;
if ( V_215 -> type == V_80 ) {
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
V_25 = F_154 ( V_2 , V_215 , false , NULL ) ;
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
return 0 ;
}
static void F_209 ( struct V_22 * V_23 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
T_5 V_545 = F_20 ( V_546 ,
200 + V_215 -> V_402 . V_458 ) ;
T_5 V_547 = F_20 ( V_548 ,
100 + V_215 -> V_402 . V_458 ) ;
if ( F_15 ( V_215 -> V_402 . V_403 ) )
return;
if ( F_12 ( V_2 , V_549 ) )
return;
F_54 ( & V_2 -> V_230 ) ;
F_155 ( V_2 , V_215 , V_545 , V_547 , 500 , false ) ;
F_60 ( & V_2 -> V_230 ) ;
F_7 ( V_2 , V_549 ) ;
}
static int F_210 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_550 * V_499 ,
struct V_551 * V_552 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
if ( ! ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] & V_63 ) ) {
V_25 = F_176 ( V_2 , V_495 ) ;
if ( V_25 )
return V_25 ;
}
F_54 ( & V_2 -> V_230 ) ;
if ( V_2 -> V_54 -> V_55 . V_60 [ 0 ] & V_61 ) {
if ( ! V_215 -> V_402 . V_490 ) {
V_25 = - V_501 ;
goto V_189;
}
} else if ( ! F_211 ( V_2 ) ) {
V_25 = - V_501 ;
goto V_189;
}
if ( V_2 -> V_336 != V_337 ) {
V_25 = - V_501 ;
goto V_189;
}
V_25 = F_212 ( V_2 , V_215 , V_499 , V_552 ) ;
if ( V_25 )
V_2 -> V_336 = V_337 ;
V_189:
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static int F_213 ( struct V_22 * V_23 ,
struct V_214 * V_215 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
if ( V_2 -> V_336 != V_494 &&
! ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] & V_63 ) ) {
F_60 ( & V_2 -> V_230 ) ;
return 0 ;
}
V_25 = F_175 ( V_2 , false ) ;
F_60 ( & V_2 -> V_230 ) ;
F_178 ( V_2 ) ;
return V_25 ;
}
static int F_214 ( struct V_22 * V_23 ,
enum V_553 V_398 ,
struct V_214 * V_215 ,
struct V_182 * V_183 ,
struct V_554 * V_555 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
if ( V_57 . V_58 ) {
F_144 ( V_2 , L_30 ) ;
return - V_556 ;
}
switch ( V_555 -> V_146 ) {
case V_557 :
V_555 -> V_26 |= V_558 ;
case V_559 :
V_555 -> V_26 |= V_560 ;
break;
case V_561 :
F_15 ( ! ( V_23 -> V_26 & V_59 ) ) ;
break;
case V_562 :
case V_563 :
if ( V_215 -> type != V_76 )
return 0 ;
break;
default:
if ( V_23 -> V_147 &&
V_23 -> V_148 -> V_146 == V_555 -> V_146 )
V_555 -> V_26 |= V_564 ;
else
return - V_556 ;
}
F_54 ( & V_2 -> V_230 ) ;
switch ( V_398 ) {
case V_565 :
if ( ( V_215 -> type == V_81 ||
V_215 -> type == V_78 ) && ! V_183 ) {
V_25 = 0 ;
V_555 -> V_566 = V_567 ;
break;
}
F_144 ( V_2 , L_31 ) ;
V_25 = F_215 ( V_2 , V_215 , V_183 , V_555 , false ) ;
if ( V_25 ) {
F_173 ( V_2 , L_32 ) ;
V_555 -> V_566 = V_567 ;
V_25 = 0 ;
}
break;
case V_568 :
if ( V_555 -> V_566 == V_567 ) {
V_25 = 0 ;
break;
}
F_144 ( V_2 , L_33 ) ;
V_25 = F_216 ( V_2 , V_215 , V_183 , V_555 ) ;
break;
default:
V_25 = - V_232 ;
}
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static void F_217 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_554 * V_569 ,
struct V_182 * V_183 ,
T_5 V_570 , V_74 * V_571 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
if ( V_569 -> V_566 == V_567 )
return;
F_218 ( V_2 , V_215 , V_569 , V_183 , V_570 , V_571 ) ;
}
static bool F_219 ( struct V_572 * V_573 ,
struct V_574 * V_575 , void * V_201 )
{
struct V_1 * V_2 =
F_220 ( V_573 , struct V_1 , V_573 ) ;
struct V_576 * V_577 ;
int V_578 = F_221 ( V_575 ) ;
struct V_579 * V_580 = V_201 ;
if ( F_8 ( V_575 -> V_200 . V_398 != V_581 ) )
return true ;
if ( F_15 ( V_578 != sizeof( * V_577 ) ) ) {
F_97 ( V_2 , L_34 ) ;
return true ;
}
V_577 = ( void * ) V_575 -> V_201 ;
F_222 ( V_2 ,
L_35 ,
V_577 -> V_15 , V_577 -> V_582 ) ;
V_580 -> V_583 = F_223 ( V_577 -> V_582 ) ;
F_222 ( V_2 , L_36 ,
V_580 -> V_583 ) ;
F_4 ( & V_2 -> V_238 ) ;
F_224 ( & V_580 -> V_584 , & V_2 -> V_585 ) ;
F_5 ( & V_2 -> V_238 ) ;
return true ;
}
static int F_225 ( struct V_1 * V_2 ,
struct V_586 * V_535 ,
struct V_214 * V_215 ,
int V_545 )
{
int V_587 , V_588 = V_589 ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
struct V_579 * V_580 = & V_235 -> V_590 ;
static const T_1 V_591 [] = { V_581 } ;
struct V_592 V_593 ;
struct V_594 V_595 = {
. V_217 = F_71 ( V_596 ) ,
. V_597 =
F_71 ( F_226 ( V_598 , 0 ) ) ,
. V_599 = F_71 ( V_2 -> V_600 . V_190 ) ,
. V_601 . V_536 = ( V_535 -> V_536 == V_108 ) ?
V_602 : V_603 ,
. V_601 . V_535 = V_535 -> V_604 ,
. V_601 . V_605 = V_606 ,
. V_607 = F_71 ( F_227 ( V_2 -> V_7 , V_588 ) ) ,
. V_608 =
F_71 ( F_228 ( V_609 ) ) ,
. V_545 = F_71 ( F_228 ( V_545 ) ) ,
} ;
memcpy ( V_595 . V_610 , V_215 -> V_97 , V_100 ) ;
F_77 ( & V_2 -> V_230 ) ;
F_4 ( & V_2 -> V_238 ) ;
if ( F_8 ( V_580 -> V_20 == V_581 ) ) {
F_5 ( & V_2 -> V_238 ) ;
return - V_17 ;
}
V_580 -> V_215 = V_215 ;
V_580 -> V_545 = V_545 ;
V_580 -> V_20 = V_581 ;
F_5 ( & V_2 -> V_238 ) ;
F_229 ( & V_2 -> V_573 , & V_593 ,
V_591 ,
F_19 ( V_591 ) ,
F_219 , V_580 ) ;
V_587 = F_114 ( V_2 , V_581 , 0 , sizeof( V_595 ) ,
& V_595 ) ;
if ( V_587 ) {
F_97 ( V_2 , L_37 , V_587 ) ;
F_230 ( & V_2 -> V_573 , & V_593 ) ;
goto V_611;
}
V_587 = F_231 ( & V_2 -> V_573 , & V_593 , 1 ) ;
F_15 ( V_587 ) ;
if ( V_587 ) {
V_611:
F_4 ( & V_2 -> V_238 ) ;
F_63 ( V_2 , V_580 ) ;
F_5 ( & V_2 -> V_238 ) ;
}
return V_587 ;
}
static int F_232 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_586 * V_535 ,
int V_545 ,
enum V_612 type )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
struct V_613 V_614 ;
struct V_370 * V_240 ;
int V_25 , V_9 ;
F_144 ( V_2 , L_38 , V_535 -> V_604 ,
V_545 , type ) ;
F_54 ( & V_2 -> V_230 ) ;
switch ( V_215 -> type ) {
case V_76 :
if ( V_2 -> V_54 -> V_55 . V_62 [ 0 ] &
V_615 ) {
V_25 = F_225 ( V_2 , V_535 ,
V_215 , V_545 ) ;
goto V_378;
}
F_97 ( V_2 , L_39 ) ;
V_25 = - V_232 ;
goto V_378;
case V_80 :
break;
default:
F_97 ( V_2 , L_40 , V_215 -> type ) ;
V_25 = - V_232 ;
goto V_378;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_240 = & V_2 -> V_18 [ V_9 ] ;
if ( V_240 -> V_21 == 0 || V_235 -> V_240 == V_240 )
continue;
if ( V_240 -> V_21 && V_535 == V_240 -> V_535 ) {
V_25 = F_125 ( V_2 , V_215 ) ;
if ( F_233 ( V_25 , L_41 ) )
goto V_378;
F_126 ( V_2 , V_235 -> V_240 ) ;
V_235 -> V_240 = V_240 ;
V_25 = F_123 ( V_2 , V_215 ) ;
if ( F_233 ( V_25 , L_42 ) )
goto V_378;
F_122 ( V_2 , V_235 -> V_240 ) ;
goto V_616;
}
}
if ( V_535 == V_235 -> V_240 -> V_535 )
goto V_616;
F_234 ( & V_614 , V_535 , V_617 ) ;
if ( V_235 -> V_240 -> V_21 == 1 ) {
V_25 = F_235 ( V_2 , V_235 -> V_240 ,
& V_614 , 1 , 1 ) ;
if ( V_25 )
goto V_378;
} else {
V_240 = F_111 ( V_2 ) ;
if ( ! V_240 ) {
V_25 = - V_386 ;
goto V_378;
}
V_25 = F_235 ( V_2 , V_240 , & V_614 ,
1 , 1 ) ;
if ( V_25 ) {
F_97 ( V_2 , L_43 ) ;
goto V_378;
}
V_25 = F_125 ( V_2 , V_215 ) ;
if ( F_233 ( V_25 , L_41 ) )
goto V_378;
F_126 ( V_2 , V_235 -> V_240 ) ;
V_235 -> V_240 = V_240 ;
V_25 = F_123 ( V_2 , V_215 ) ;
if ( F_233 ( V_25 , L_42 ) )
goto V_378;
F_122 ( V_2 , V_235 -> V_240 ) ;
}
V_616:
V_25 = F_236 ( V_2 , V_215 , V_545 , type ) ;
V_378:
F_60 ( & V_2 -> V_230 ) ;
F_144 ( V_2 , L_44 ) ;
return V_25 ;
}
static int F_237 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_144 ( V_2 , L_45 ) ;
F_54 ( & V_2 -> V_230 ) ;
F_238 ( V_2 ) ;
F_60 ( & V_2 -> V_230 ) ;
F_144 ( V_2 , L_44 ) ;
return 0 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
V_74 * V_620 = ( V_74 * ) V_619 -> V_621 ;
struct V_370 * V_240 ;
int V_25 ;
F_77 ( & V_2 -> V_230 ) ;
F_144 ( V_2 , L_46 ) ;
V_240 = F_111 ( V_2 ) ;
if ( ! V_240 ) {
V_25 = - V_386 ;
goto V_189;
}
V_25 = F_235 ( V_2 , V_240 , & V_619 -> V_622 ,
V_619 -> V_623 ,
V_619 -> V_624 ) ;
if ( V_25 ) {
F_97 ( V_2 , L_47 ) ;
goto V_189;
}
F_122 ( V_2 , V_240 ) ;
* V_620 = V_240 -> V_20 ;
V_189:
return V_25 ;
}
static int F_240 ( struct V_22 * V_23 ,
struct V_618 * V_619 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
V_25 = F_239 ( V_2 , V_619 ) ;
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static void F_241 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
V_74 * V_620 = ( V_74 * ) V_619 -> V_621 ;
struct V_370 * V_240 = & V_2 -> V_18 [ * V_620 ] ;
F_77 ( & V_2 -> V_230 ) ;
F_126 ( V_2 , V_240 ) ;
}
static void F_242 ( struct V_22 * V_23 ,
struct V_618 * V_619 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_54 ( & V_2 -> V_230 ) ;
F_241 ( V_2 , V_619 ) ;
F_60 ( & V_2 -> V_230 ) ;
}
static void F_243 ( struct V_22 * V_23 ,
struct V_618 * V_619 ,
T_5 V_394 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
V_74 * V_620 = ( V_74 * ) V_619 -> V_621 ;
struct V_370 * V_240 = & V_2 -> V_18 [ * V_620 ] ;
if ( F_103 ( ( V_240 -> V_21 > 1 ) &&
( V_394 & ~ ( V_625 |
V_626 |
V_627 |
V_628 ) ) ,
L_48 ,
V_240 -> V_21 , V_394 ) )
return;
F_54 ( & V_2 -> V_230 ) ;
F_160 ( V_2 ) ;
F_235 ( V_2 , V_240 , & V_619 -> V_622 ,
V_619 -> V_623 ,
V_619 -> V_624 ) ;
F_60 ( & V_2 -> V_230 ) ;
}
static int F_244 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
struct V_618 * V_619 ,
bool V_629 )
{
V_74 * V_620 = ( V_74 * ) V_619 -> V_621 ;
struct V_370 * V_240 = & V_2 -> V_18 [ * V_620 ] ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
int V_25 ;
F_77 ( & V_2 -> V_230 ) ;
V_235 -> V_240 = V_240 ;
switch ( V_215 -> type ) {
case V_78 :
if ( V_629 ) {
V_235 -> V_477 = true ;
break;
}
case V_81 :
V_25 = 0 ;
goto V_189;
case V_76 :
break;
case V_630 :
V_235 -> V_338 = true ;
break;
default:
V_25 = - V_232 ;
goto V_189;
}
V_25 = F_123 ( V_2 , V_215 ) ;
if ( V_25 )
goto V_189;
F_120 ( V_2 ) ;
if ( V_215 -> type == V_630 ) {
V_235 -> V_631 = true ;
V_25 = F_96 ( V_2 , NULL ) ;
if ( V_25 )
goto V_632;
}
if ( V_215 -> type == V_78 ) {
F_96 ( V_2 , NULL ) ;
F_154 ( V_2 , V_215 , false , NULL ) ;
}
if ( V_629 && V_215 -> type == V_76 ) {
T_5 V_545 = 2 * V_215 -> V_402 . V_458 ;
V_25 = F_12 ( V_2 , V_633 ) ;
if ( V_25 )
goto V_632;
F_155 ( V_2 , V_215 , V_545 , V_545 ,
V_215 -> V_402 . V_458 / 2 ,
true ) ;
F_7 ( V_2 , V_633 ) ;
F_96 ( V_2 , NULL ) ;
}
goto V_189;
V_632:
F_125 ( V_2 , V_215 ) ;
F_120 ( V_2 ) ;
V_189:
if ( V_25 )
V_235 -> V_240 = NULL ;
return V_25 ;
}
static int F_245 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_618 * V_619 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
V_25 = F_244 ( V_2 , V_215 , V_619 , false ) ;
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static void F_246 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
struct V_618 * V_619 ,
bool V_629 )
{
struct V_72 * V_235 = F_62 ( V_215 ) ;
struct V_214 * V_634 = NULL ;
F_77 ( & V_2 -> V_230 ) ;
F_161 ( V_2 , V_235 , & V_235 -> V_239 ) ;
switch ( V_215 -> type ) {
case V_81 :
goto V_189;
case V_630 :
V_235 -> V_631 = false ;
V_235 -> V_338 = false ;
break;
case V_78 :
if ( ! V_629 || ! V_235 -> V_477 )
goto V_189;
V_235 -> V_635 = false ;
F_247 ( V_2 , V_235 , true ) ;
F_194 ( V_2 -> V_481 , V_215 ) ;
V_235 -> V_477 = false ;
break;
case V_76 :
if ( ! V_629 )
break;
V_634 = V_215 ;
F_154 ( V_2 , V_215 , true , NULL ) ;
break;
default:
break;
}
F_96 ( V_2 , V_634 ) ;
F_125 ( V_2 , V_215 ) ;
V_189:
V_235 -> V_240 = NULL ;
F_120 ( V_2 ) ;
}
static void F_248 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_618 * V_619 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_54 ( & V_2 -> V_230 ) ;
F_246 ( V_2 , V_215 , V_619 , false ) ;
F_60 ( & V_2 -> V_230 ) ;
}
static int
F_249 ( struct V_1 * V_2 ,
struct V_636 * V_637 )
{
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
F_246 ( V_2 , V_637 [ 0 ] . V_215 , V_637 [ 0 ] . V_638 , true ) ;
F_241 ( V_2 , V_637 [ 0 ] . V_638 ) ;
V_25 = F_239 ( V_2 , V_637 [ 0 ] . V_639 ) ;
if ( V_25 ) {
F_97 ( V_2 , L_49 ) ;
goto V_640;
}
V_25 = F_244 ( V_2 , V_637 [ 0 ] . V_215 , V_637 [ 0 ] . V_639 ,
true ) ;
if ( V_25 ) {
F_97 ( V_2 ,
L_50 ) ;
goto V_476;
}
if ( F_167 ( V_2 ) > 1 )
F_98 ( V_2 ) ;
goto V_189;
V_476:
F_241 ( V_2 , V_637 [ 0 ] . V_639 ) ;
V_640:
if ( F_239 ( V_2 , V_637 [ 0 ] . V_638 ) ) {
F_97 ( V_2 , L_51 ) ;
goto V_641;
}
if ( F_244 ( V_2 , V_637 [ 0 ] . V_215 , V_637 [ 0 ] . V_638 ,
true ) ) {
F_97 ( V_2 , L_52 ) ;
goto V_641;
}
goto V_189;
V_641:
F_250 ( V_2 , false ) ;
V_189:
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static int
F_251 ( struct V_1 * V_2 ,
struct V_636 * V_637 )
{
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
F_246 ( V_2 , V_637 [ 0 ] . V_215 , V_637 [ 0 ] . V_638 , true ) ;
V_25 = F_244 ( V_2 , V_637 [ 0 ] . V_215 , V_637 [ 0 ] . V_639 ,
true ) ;
if ( V_25 ) {
F_97 ( V_2 ,
L_50 ) ;
goto V_640;
}
goto V_189;
V_640:
if ( F_244 ( V_2 , V_637 [ 0 ] . V_215 , V_637 [ 0 ] . V_638 ,
true ) ) {
F_97 ( V_2 , L_52 ) ;
goto V_641;
}
goto V_189;
V_641:
F_250 ( V_2 , false ) ;
V_189:
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static int F_252 ( struct V_22 * V_23 ,
struct V_636 * V_637 ,
int V_642 ,
enum V_643 V_644 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
if ( V_642 > 1 )
return - V_556 ;
switch ( V_644 ) {
case V_645 :
V_25 = F_249 ( V_2 , V_637 ) ;
break;
case V_646 :
V_25 = F_251 ( V_2 , V_637 ) ;
break;
default:
V_25 = - V_556 ;
break;
}
return V_25 ;
}
static int F_253 ( struct V_22 * V_23 ,
struct V_182 * V_183 ,
bool V_647 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_70 * V_519 = F_33 ( V_183 ) ;
if ( ! V_519 || ! V_519 -> V_215 ) {
F_97 ( V_2 , L_53 ) ;
return - V_232 ;
}
return F_165 ( V_2 , V_519 -> V_215 ) ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
void * V_201 , int V_155 )
{
struct V_648 * V_649 [ V_650 + 1 ] ;
int V_651 ;
T_5 V_393 ;
V_651 = F_255 ( V_649 , V_650 , V_201 , V_155 , V_652 ) ;
if ( V_651 )
return V_651 ;
if ( ! V_649 [ V_653 ] )
return - V_232 ;
switch ( F_256 ( V_649 [ V_653 ] ) ) {
case V_654 :
if ( ! V_215 || V_215 -> type != V_78 || ! V_215 -> V_382 ||
! V_215 -> V_402 . V_655 ||
! V_649 [ V_656 ] )
return - V_232 ;
V_393 = F_256 ( V_649 [ V_656 ] ) ;
if ( V_393 >= V_215 -> V_402 . V_458 )
return - V_232 ;
V_2 -> V_393 = V_393 ;
V_2 -> V_392 = V_215 ;
return F_96 ( V_2 , NULL ) ;
case V_657 :
if ( ! V_215 || V_215 -> type != V_76 ||
! V_215 -> V_402 . V_403 || ! V_215 -> V_402 . V_658 ||
! V_649 [ V_659 ] )
return - V_232 ;
if ( F_256 ( V_649 [ V_659 ] ) )
return F_162 ( V_2 , V_215 , 0 ) ;
return F_121 ( V_2 , V_215 , 0 ) ;
}
return - V_556 ;
}
static int F_257 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
void * V_201 , int V_155 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_651 ;
F_54 ( & V_2 -> V_230 ) ;
V_651 = F_254 ( V_2 , V_215 , V_201 , V_155 ) ;
F_60 ( & V_2 -> V_230 ) ;
return V_651 ;
}
static void F_258 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_660 * V_661 )
{
F_144 ( F_38 ( V_23 ) ,
L_54 ) ;
}
static int F_259 ( struct V_22 * V_23 ,
struct V_214 * V_215 ,
struct V_660 * V_661 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_214 * V_480 ;
struct V_72 * V_235 = F_62 ( V_215 ) ;
T_5 V_607 ;
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
F_144 ( V_2 , L_55 ,
V_661 -> V_614 . V_662 ) ;
switch ( V_215 -> type ) {
case V_78 :
V_480 =
F_260 ( V_2 -> V_480 ,
F_261 ( & V_2 -> V_230 ) ) ;
if ( F_103 ( V_480 && V_480 -> V_663 ,
L_56 ) ) {
V_25 = - V_501 ;
goto V_378;
}
F_194 ( V_2 -> V_480 , V_215 ) ;
if ( F_103 ( V_235 -> V_635 ,
L_57 ) ) {
V_25 = - V_501 ;
goto V_378;
}
break;
case V_76 :
V_607 = V_661 -> V_664 +
( ( V_215 -> V_402 . V_458 * ( V_661 -> V_244 - 1 ) -
V_665 ) * 1024 ) ;
if ( V_661 -> V_666 )
F_262 ( V_2 , V_215 ) ;
F_263 ( V_2 , V_215 , V_215 -> V_402 . V_458 ,
V_607 ) ;
if ( V_235 -> V_241 . V_473 ) {
V_25 = F_121 ( V_2 , V_215 , 0 ) ;
if ( V_25 )
goto V_378;
}
break;
default:
break;
}
V_235 -> V_338 = true ;
V_25 = F_264 ( V_2 ) ;
if ( V_25 )
goto V_378;
F_98 ( V_2 ) ;
V_378:
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static int F_265 ( struct V_22 * V_23 ,
struct V_214 * V_215 )
{
struct V_72 * V_235 = F_62 ( V_215 ) ;
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_25 ;
F_54 ( & V_2 -> V_230 ) ;
if ( V_215 -> type == V_76 ) {
struct V_70 * V_186 ;
V_186 = F_266 ( V_2 ,
V_235 -> V_237 ) ;
if ( F_8 ( ! V_186 ) ) {
V_25 = - V_17 ;
goto V_378;
}
F_267 ( V_2 , V_186 , false ) ;
F_154 ( V_2 , V_215 , false , NULL ) ;
V_25 = F_162 ( V_2 , V_215 , 0 ) ;
if ( V_25 )
goto V_378;
F_268 ( V_2 , V_215 ) ;
}
V_235 -> V_338 = false ;
V_25 = F_264 ( V_2 ) ;
V_378:
F_60 ( & V_2 -> V_230 ) ;
return V_25 ;
}
static void F_269 ( struct V_22 * V_23 ,
struct V_214 * V_215 , T_5 V_39 , bool V_202 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_72 * V_235 ;
struct V_70 * V_186 ;
struct V_182 * V_183 ;
int V_9 ;
T_5 V_667 = 0 ;
if ( ! V_215 || V_215 -> type != V_76 )
return;
F_54 ( & V_2 -> V_230 ) ;
V_235 = F_62 ( V_215 ) ;
for ( V_9 = 0 ; V_9 < V_191 ; V_9 ++ ) {
V_183 = F_260 ( V_2 -> V_520 [ V_9 ] ,
F_261 ( & V_2 -> V_230 ) ) ;
if ( F_270 ( V_183 ) )
continue;
V_186 = F_33 ( V_183 ) ;
if ( V_186 -> V_215 != V_215 )
continue;
F_8 ( V_9 != V_235 -> V_237 && ! V_183 -> V_530 ) ;
V_667 |= V_186 -> V_668 ;
}
if ( V_202 ) {
if ( F_131 ( V_2 , V_667 , true ) )
F_97 ( V_2 , L_58 ) ;
F_60 ( & V_2 -> V_230 ) ;
} else {
F_60 ( & V_2 -> V_230 ) ;
F_271 ( V_2 -> V_7 , V_667 ) ;
}
}
