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
V_30 -> V_51 = V_52 |
V_53 |
V_54 |
V_55 |
V_56 |
V_57 |
V_58 |
V_59 |
V_60 |
V_61 |
V_62 |
V_63 ;
V_30 -> V_64 = V_2 -> V_65 ;
V_30 -> V_66 = V_67 ;
V_30 -> V_68 |= V_69 |
V_70 ;
V_30 -> V_71 |= V_72 |
V_73 ;
V_30 -> V_74 = L_9 ;
V_30 -> V_75 = V_76 ;
V_30 -> V_77 = V_78 ;
if ( V_2 -> V_79 -> V_80 . V_51 & V_81 &&
! V_82 . V_83 )
V_30 -> V_51 |= V_84 ;
V_30 -> V_51 |= V_85 ;
V_30 -> V_23 -> V_86 |=
V_87 |
V_88 ;
V_30 -> V_89 = sizeof( struct V_90 ) ;
V_30 -> V_91 = sizeof( struct V_92 ) ;
V_30 -> V_93 = sizeof( V_94 ) ;
V_30 -> V_23 -> V_95 = F_38 ( V_96 ) |
F_38 ( V_97 ) |
F_38 ( V_98 ) |
F_38 ( V_99 ) |
F_38 ( V_100 ) |
F_38 ( V_101 ) ;
V_30 -> V_23 -> V_51 |= V_102 ;
V_30 -> V_23 -> V_103 |= V_104 ;
if ( F_30 ( V_2 ) )
V_30 -> V_23 -> V_103 |= V_105 ;
else
V_30 -> V_23 -> V_103 |= V_106 |
V_107 ;
if ( V_2 -> V_79 -> V_80 . V_51 & V_108 )
V_30 -> V_23 -> V_51 |= V_109 ;
V_30 -> V_23 -> V_51 |= V_110 ;
V_30 -> V_23 -> V_111 = V_112 ;
V_30 -> V_23 -> V_113 =
F_39 ( V_112 ) ;
V_30 -> V_23 -> V_114 = 10000 ;
V_30 -> V_115 = V_116 ;
V_30 -> V_23 -> V_117 = 3 * 5 ;
memcpy ( V_2 -> V_118 [ 0 ] . V_119 , V_2 -> V_120 -> V_121 , V_122 ) ;
V_30 -> V_23 -> V_118 = V_2 -> V_118 ;
V_30 -> V_23 -> V_123 = 1 ;
V_50 = ( V_2 -> V_120 -> V_124 > 1 ) ?
F_40 ( V_125 , V_2 -> V_120 -> V_124 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_50 ; V_9 ++ ) {
memcpy ( V_2 -> V_118 [ V_9 ] . V_119 , V_2 -> V_118 [ V_9 - 1 ] . V_119 ,
V_122 ) ;
V_2 -> V_118 [ V_9 ] . V_119 [ 5 ] ++ ;
V_30 -> V_23 -> V_123 ++ ;
}
F_16 ( V_2 ) ;
V_30 -> V_23 -> V_126 = F_41 ( V_2 , false ) ;
V_30 -> V_23 -> V_127 = V_128 ;
if ( V_2 -> V_120 -> V_129 [ V_130 ] . V_38 )
V_30 -> V_23 -> V_129 [ V_130 ] =
& V_2 -> V_120 -> V_129 [ V_130 ] ;
if ( V_2 -> V_120 -> V_129 [ V_131 ] . V_38 ) {
V_30 -> V_23 -> V_129 [ V_131 ] =
& V_2 -> V_120 -> V_129 [ V_131 ] ;
if ( ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_133 ) &&
( V_2 -> V_79 -> V_80 . V_134 [ 0 ] &
V_135 ) )
V_30 -> V_23 -> V_129 [ V_131 ] -> V_136 . V_137 |=
V_138 ;
}
V_30 -> V_23 -> V_139 = V_2 -> V_7 -> V_140 ;
if ( V_141 . V_142 != V_143 )
V_30 -> V_23 -> V_51 |= V_144 ;
else
V_30 -> V_23 -> V_51 &= ~ V_144 ;
if ( F_42 ( V_2 -> V_79 -> V_145 ) >= 10 ) {
V_30 -> V_23 -> V_51 |= V_146 ;
V_30 -> V_23 -> V_147 = V_128 ;
V_30 -> V_23 -> V_148 = V_149 ;
V_30 -> V_23 -> V_150 =
V_151 - 24 - 2 ;
}
V_30 -> V_23 -> V_86 |= V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 ;
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_158 )
V_30 -> V_23 -> V_86 |= V_159 ;
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_160 )
V_30 -> V_23 -> V_86 |= V_161 ;
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_162 )
V_30 -> V_23 -> V_86 |=
V_163 ;
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_164 )
V_30 -> V_23 -> V_86 |= V_165 ;
V_2 -> V_166 = V_167 ;
if ( V_2 -> V_79 -> V_168 [ 0 ] . V_169 ) {
V_2 -> V_30 -> V_170 = 1 ;
V_2 -> V_30 -> V_171 = & V_2 -> V_79 -> V_168 [ 0 ] ;
}
#ifdef F_43
if ( F_2 ( V_2 ) &&
F_44 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_172 . V_51 = V_173 ;
V_30 -> V_23 -> V_172 = & V_2 -> V_172 ;
}
if ( V_2 -> V_79 -> V_174 [ V_175 ] . V_176 [ 0 ] . V_177 &&
V_2 -> V_7 -> V_178 -> V_179 &&
V_2 -> V_7 -> V_178 -> V_180 &&
F_44 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_172 . V_51 |= V_181 |
V_182 |
V_183 |
V_184 |
V_185 ;
if ( ! V_82 . V_83 )
V_2 -> V_172 . V_51 |= V_186 |
V_187 |
V_188 ;
V_2 -> V_172 . V_189 = V_190 ;
V_2 -> V_172 . V_191 = V_192 ;
V_2 -> V_172 . V_193 = V_194 ;
V_2 -> V_172 . V_195 = V_149 ;
V_2 -> V_172 . V_196 = & V_197 ;
V_30 -> V_23 -> V_172 = & V_2 -> V_172 ;
}
#endif
#ifdef F_45
V_2 -> V_198 = V_199 ;
#endif
V_47 = F_46 ( V_2 ) ;
if ( V_47 )
return V_47 ;
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] & V_200 ) {
F_47 ( V_2 , L_10 ) ;
V_30 -> V_23 -> V_51 |= V_201 ;
}
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_202 ) {
F_47 ( V_2 , L_11 ) ;
V_30 -> V_23 -> V_86 |= V_203 ;
}
V_47 = F_48 ( V_2 -> V_30 ) ;
if ( V_47 )
F_49 ( V_2 ) ;
return V_47 ;
}
static bool F_50 ( struct V_1 * V_2 ,
struct V_204 * V_205 ,
struct V_206 * V_207 )
{
struct V_90 * V_208 ;
bool V_209 = false ;
if ( F_51 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_52 ( & V_2 -> V_210 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_34;
V_208 = F_53 ( V_205 ) ;
if ( V_208 -> V_211 == V_212 ||
V_208 -> V_211 != V_2 -> V_213 )
goto V_34;
F_54 ( & V_2 -> V_214 , V_207 ) ;
F_55 ( V_2 -> V_30 ) ;
F_1 ( V_2 , V_215 ) ;
F_7 ( V_2 , V_215 ) ;
V_209 = true ;
V_34:
F_56 ( & V_2 -> V_210 ) ;
return V_209 ;
}
static void F_57 ( struct V_29 * V_30 ,
struct V_216 * V_217 ,
struct V_206 * V_207 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_204 * V_205 = V_217 -> V_205 ;
struct V_218 * V_219 = F_58 ( V_207 ) ;
struct V_220 * V_221 = ( void * ) V_207 -> V_222 ;
if ( F_59 ( V_2 ) ) {
F_60 ( V_2 , L_12 ) ;
goto V_223;
}
if ( F_58 ( V_207 ) -> V_224 == V_67 &&
! F_14 ( V_225 , & V_2 -> V_15 ) &&
! F_14 ( V_226 , & V_2 -> V_15 ) )
goto V_223;
if ( F_61 ( V_219 -> V_51 & V_227 &&
F_62 ( V_221 -> V_228 ) &&
! F_63 ( V_221 -> V_228 ) &&
! F_64 ( V_221 -> V_228 ) &&
! F_65 ( V_221 -> V_228 ) ) )
V_205 = NULL ;
if ( V_205 ) {
if ( F_50 ( V_2 , V_205 , V_207 ) )
return;
if ( F_66 ( V_2 , V_207 , V_205 ) )
goto V_223;
return;
}
if ( F_67 ( V_2 , V_207 ) )
goto V_223;
return;
V_223:
F_68 ( V_30 , V_207 ) ;
}
static inline bool F_69 ( const struct V_229 * V_37 )
{
if ( V_82 . V_230 & V_231 )
return false ;
return true ;
}
static inline bool F_70 ( const struct V_229 * V_37 )
{
if ( V_82 . V_230 & V_232 )
return false ;
if ( V_82 . V_230 & V_233 )
return true ;
return true ;
}
static int F_71 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
enum V_236 V_237 ,
struct V_204 * V_205 , V_94 V_238 ,
V_94 * V_239 , T_1 V_240 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_241 = false ;
F_72 ( V_2 , L_13 ,
V_205 -> V_119 , V_238 , V_237 ) ;
if ( ! ( V_2 -> V_120 -> V_242 ) )
return - V_243 ;
switch ( V_237 ) {
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_47 = F_12 ( V_2 , V_249 ) ;
if ( V_47 )
return V_47 ;
V_241 = true ;
break;
default:
break;
}
F_73 ( & V_2 -> V_33 ) ;
switch ( V_237 ) {
case V_250 :
if ( ! F_69 ( V_2 -> V_37 ) ) {
V_47 = - V_251 ;
break;
}
V_47 = F_74 ( V_2 , V_205 , V_238 , * V_239 , true ) ;
break;
case V_252 :
V_47 = F_74 ( V_2 , V_205 , V_238 , 0 , false ) ;
break;
case V_244 :
if ( ! F_70 ( V_2 -> V_37 ) ) {
V_47 = - V_251 ;
break;
}
V_47 = F_75 ( V_2 , V_235 , V_205 , V_238 , V_239 ) ;
break;
case V_245 :
V_47 = F_76 ( V_2 , V_235 , V_205 , V_238 ) ;
break;
case V_246 :
case V_247 :
V_47 = F_77 ( V_2 , V_235 , V_205 , V_238 ) ;
break;
case V_248 :
V_47 = F_78 ( V_2 , V_235 , V_205 , V_238 , V_240 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_251 ;
break;
}
F_79 ( & V_2 -> V_33 ) ;
if ( V_241 )
F_7 ( V_2 , V_249 ) ;
return V_47 ;
}
static void F_80 ( void * V_222 , T_1 * V_253 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = V_222 ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
V_254 -> V_255 = false ;
V_254 -> V_256 = V_212 ;
F_4 ( & V_2 -> V_257 ) ;
F_82 ( V_2 , & V_254 -> V_258 ) ;
F_5 ( & V_2 -> V_257 ) ;
V_254 -> V_259 = NULL ;
memset ( & V_254 -> V_260 , 0 , sizeof( V_254 -> V_260 ) ) ;
}
static T_2 F_83 ( char * V_261 , T_3 V_262 , T_4 V_263 ,
const void * V_222 , T_4 V_264 )
{
const struct V_265 * V_266 = V_222 ;
T_2 V_267 ;
T_2 V_268 ;
if ( V_262 < V_266 -> V_269 ) {
V_267 = F_84 ( T_2 , V_263 ,
V_266 -> V_269 - V_262 ) ;
memcpy ( V_261 , ( T_1 * ) V_266 -> V_270 + V_262 ,
V_267 ) ;
V_262 += V_267 ;
V_263 -= V_267 ;
if ( V_263 == 0 )
return V_267 ;
} else {
V_267 = 0 ;
}
if ( ! V_266 -> V_271 )
return V_267 ;
V_262 -= V_266 -> V_269 ;
V_268 = F_84 ( T_2 , V_263 ,
V_266 -> V_271 -> V_177 - V_262 ) ;
memcpy ( V_261 + V_267 ,
( T_1 * ) V_266 -> V_271 -> V_222 + V_262 ,
V_268 ) ;
return V_267 + V_268 ;
}
static void F_85 ( const void * V_222 )
{
const struct V_265 * V_272 = V_222 ;
F_86 ( V_272 -> V_270 ) ;
F_86 ( V_272 -> V_271 ) ;
F_28 ( V_272 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_273 * * V_274 )
{
struct V_275 * V_276 ;
T_5 * V_277 ;
T_5 V_278 ;
unsigned long V_51 ;
int V_9 , V_10 ;
if ( ! F_88 ( V_2 -> V_7 , false , & V_51 ) )
return;
for ( V_9 = 0 ; V_9 < F_39 ( V_2 -> V_279 . V_280 ) ; V_9 ++ ) {
T_5 V_281 = V_282 * V_9 ;
V_276 = ( void * ) ( * V_274 ) -> V_222 ;
V_277 = ( void * ) V_276 -> V_222 ;
V_278 = V_2 -> V_279 . V_280 [ V_9 ] ;
if ( V_278 == 0 )
continue;
( * V_274 ) -> type = F_89 ( V_283 ) ;
( * V_274 ) -> V_177 = F_89 ( V_278 + sizeof( * V_276 ) ) ;
V_276 -> V_284 = F_89 ( V_9 ) ;
V_276 -> V_285 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_286 +
V_281 ) ) ;
V_276 -> V_287 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_288 +
V_281 ) ) ;
V_276 -> V_289 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_290 +
V_281 ) ) ;
V_276 -> V_291 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_292 +
V_281 ) ) ;
V_276 -> V_293 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_294 +
V_281 ) ) ;
F_91 ( V_2 -> V_7 ,
V_294 + V_281 , 0x1 ) ;
F_91 ( V_2 -> V_7 ,
V_295 + V_281 , 0x1 ) ;
F_91 ( V_2 -> V_7 ,
V_296 + V_281 ,
0x0 ) ;
V_278 /= sizeof( T_5 ) ;
for ( V_10 = 0 ; V_10 < V_278 ; V_10 ++ )
V_277 [ V_10 ] = F_90 ( V_2 -> V_7 ,
V_297 +
V_281 ) ;
* V_274 = F_92 ( * V_274 ) ;
}
for ( V_9 = 0 ; V_9 < F_39 ( V_2 -> V_279 . V_298 ) ; V_9 ++ ) {
F_91 ( V_2 -> V_7 , V_299 , V_9 ) ;
V_276 = ( void * ) ( * V_274 ) -> V_222 ;
V_277 = ( void * ) V_276 -> V_222 ;
V_278 = V_2 -> V_279 . V_298 [ V_9 ] ;
if ( V_278 == 0 )
continue;
( * V_274 ) -> type = F_89 ( V_300 ) ;
( * V_274 ) -> V_177 = F_89 ( V_278 + sizeof( * V_276 ) ) ;
V_276 -> V_284 = F_89 ( V_9 ) ;
V_276 -> V_285 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_301 ) ) ;
V_276 -> V_287 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_302 ) ) ;
V_276 -> V_289 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_303 ) ) ;
V_276 -> V_291 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_304 ) ) ;
V_276 -> V_293 =
F_89 ( F_90 ( V_2 -> V_7 ,
V_305 ) ) ;
F_91 ( V_2 -> V_7 , V_306 ,
V_302 ) ;
F_90 ( V_2 -> V_7 , V_307 ) ;
V_278 /= sizeof( T_5 ) ;
for ( V_10 = 0 ; V_10 < V_278 ; V_10 ++ )
V_277 [ V_10 ] = F_90 ( V_2 -> V_7 ,
V_307 ) ;
* V_274 = F_92 ( * V_274 ) ;
}
F_93 ( V_2 -> V_7 , & V_51 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
if ( V_2 -> V_308 == & V_309 ||
! V_2 -> V_308 )
return;
F_28 ( V_2 -> V_308 ) ;
V_2 -> V_308 = NULL ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_310 * V_311 ;
struct V_273 * V_274 ;
struct V_312 * V_313 ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
struct V_265 * V_272 ;
T_5 V_318 , V_319 ;
T_5 V_320 , V_321 = 0 ;
T_5 V_322 = V_2 -> V_37 -> V_322 ;
T_5 V_323 = V_2 -> V_37 -> V_324 ;
F_21 ( & V_2 -> V_33 ) ;
V_272 = F_96 ( sizeof( * V_272 ) , V_325 ) ;
if ( ! V_272 )
return;
if ( ! V_2 -> V_37 -> V_326 || ! V_2 -> V_37 -> V_327 ) {
const struct V_328 * V_174 ;
V_174 = & V_2 -> V_79 -> V_174 [ V_2 -> V_329 ] ;
V_319 = V_174 -> V_176 [ V_330 ] . V_262 ;
V_318 = V_174 -> V_176 [ V_330 ] . V_177 ;
} else {
V_319 = V_2 -> V_37 -> V_326 ;
V_318 = V_2 -> V_37 -> V_327 ;
}
if ( F_14 ( V_331 , & V_2 -> V_7 -> V_15 ) ) {
struct V_332 * V_333 = & V_2 -> V_279 ;
int V_9 ;
V_321 = 0 ;
for ( V_9 = 0 ; V_9 < F_39 ( V_333 -> V_280 ) ; V_9 ++ ) {
if ( ! V_333 -> V_280 [ V_9 ] )
continue;
V_321 += V_333 -> V_280 [ V_9 ] +
sizeof( * V_274 ) +
sizeof( struct V_275 ) ;
}
for ( V_9 = 0 ; V_9 < F_39 ( V_333 -> V_298 ) ; V_9 ++ ) {
if ( ! V_333 -> V_298 [ V_9 ] )
continue;
V_321 += V_333 -> V_298 [ V_9 ] +
sizeof( * V_274 ) +
sizeof( struct V_275 ) ;
}
}
V_320 = sizeof( * V_311 ) +
sizeof( * V_274 ) * 2 +
V_318 + sizeof( * V_315 ) +
V_321 +
sizeof( * V_313 ) ;
if ( V_2 -> V_37 -> V_334 == V_335 &&
F_97 ( V_2 -> V_7 -> V_336 ) == V_337 )
V_320 += sizeof( * V_274 ) + sizeof( * V_315 ) +
V_338 ;
if ( V_2 -> V_308 )
V_320 += sizeof( * V_274 ) + sizeof( * V_317 ) +
V_2 -> V_308 -> V_177 ;
if ( V_322 )
V_320 += sizeof( * V_274 ) + sizeof( * V_315 ) + V_322 ;
if ( V_323 )
V_320 += sizeof( * V_274 ) + sizeof( * V_315 ) + V_323 ;
V_311 = F_98 ( V_320 ) ;
if ( ! V_311 ) {
F_28 ( V_272 ) ;
F_94 ( V_2 ) ;
return;
}
V_272 -> V_270 = V_311 ;
V_311 -> V_339 = F_89 ( V_340 ) ;
V_274 = ( void * ) V_311 -> V_222 ;
V_274 -> type = F_89 ( V_341 ) ;
V_274 -> V_177 = F_89 ( sizeof( * V_313 ) ) ;
V_313 = ( void * ) V_274 -> V_222 ;
V_313 -> V_334 =
V_2 -> V_37 -> V_334 == V_342 ?
F_89 ( V_343 ) :
F_89 ( V_344 ) ;
V_313 -> V_345 = F_89 ( F_97 ( V_2 -> V_7 -> V_336 ) ) ;
memcpy ( V_313 -> V_346 , V_2 -> V_79 -> V_347 ,
sizeof( V_313 -> V_346 ) ) ;
strncpy ( V_313 -> V_348 , V_2 -> V_37 -> V_349 ,
sizeof( V_313 -> V_348 ) ) ;
strncpy ( V_313 -> V_350 , V_2 -> V_36 -> V_351 -> V_349 ,
sizeof( V_313 -> V_350 ) ) ;
V_274 = F_92 ( V_274 ) ;
if ( F_14 ( V_331 , & V_2 -> V_7 -> V_15 ) )
F_87 ( V_2 , & V_274 ) ;
if ( V_2 -> V_308 ) {
V_274 -> type = F_89 ( V_352 ) ;
V_274 -> V_177 = F_89 ( sizeof( * V_317 ) +
V_2 -> V_308 -> V_177 ) ;
V_317 = ( void * ) V_274 -> V_222 ;
memcpy ( V_317 , & V_2 -> V_308 -> V_353 ,
sizeof( * V_317 ) + V_2 -> V_308 -> V_177 ) ;
F_94 ( V_2 ) ;
V_274 = F_92 ( V_274 ) ;
}
V_274 -> type = F_89 ( V_354 ) ;
V_274 -> V_177 = F_89 ( V_318 + sizeof( * V_315 ) ) ;
V_315 = ( void * ) V_274 -> V_222 ;
V_315 -> type = F_89 ( V_355 ) ;
V_315 -> V_262 = F_89 ( V_319 ) ;
F_99 ( V_2 -> V_7 , V_319 , V_315 -> V_222 ,
V_318 ) ;
if ( V_322 ) {
V_274 = F_92 ( V_274 ) ;
V_274 -> type = F_89 ( V_354 ) ;
V_274 -> V_177 = F_89 ( V_322 + sizeof( * V_315 ) ) ;
V_315 = ( void * ) V_274 -> V_222 ;
V_315 -> type = F_89 ( V_356 ) ;
V_315 -> V_262 = F_89 ( V_2 -> V_37 -> V_357 ) ;
F_99 ( V_2 -> V_7 , V_2 -> V_37 -> V_357 ,
V_315 -> V_222 , V_322 ) ;
}
if ( V_323 ) {
V_274 = F_92 ( V_274 ) ;
V_274 -> type = F_89 ( V_354 ) ;
V_274 -> V_177 = F_89 ( V_323 + sizeof( * V_315 ) ) ;
V_315 = ( void * ) V_274 -> V_222 ;
V_315 -> type = F_89 ( V_355 ) ;
V_315 -> V_262 = F_89 ( V_2 -> V_37 -> V_358 ) ;
F_99 ( V_2 -> V_7 , V_2 -> V_37 -> V_358 ,
V_315 -> V_222 , V_323 ) ;
}
if ( V_2 -> V_37 -> V_334 == V_335 &&
F_97 ( V_2 -> V_7 -> V_336 ) == V_337 ) {
V_274 = F_92 ( V_274 ) ;
V_274 -> type = F_89 ( V_354 ) ;
V_274 -> V_177 = F_89 ( V_338 +
sizeof( * V_315 ) ) ;
V_315 = ( void * ) V_274 -> V_222 ;
V_315 -> type = F_89 ( V_355 ) ;
V_315 -> V_262 = F_89 ( V_359 ) ;
F_99 ( V_2 -> V_7 , V_359 ,
V_315 -> V_222 , V_338 ) ;
}
V_272 -> V_271 = F_100 ( V_2 -> V_7 ) ;
V_272 -> V_269 = V_320 ;
if ( V_272 -> V_271 )
V_320 += V_272 -> V_271 -> V_177 ;
V_311 -> V_320 = F_89 ( V_320 ) ;
F_101 ( V_2 -> V_7 -> V_36 , V_360 , V_272 , 0 ,
V_325 , F_83 , F_85 ) ;
F_102 ( V_361 , & V_2 -> V_15 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
if ( ! F_104 ( V_362 , & V_2 -> V_15 ) ) {
V_2 -> V_308 = & V_309 ;
F_95 ( V_2 ) ;
}
F_10 ( V_2 , V_363 ) ;
F_105 ( V_2 -> V_7 ) ;
V_2 -> V_364 = V_365 ;
V_2 -> V_366 = false ;
V_2 -> V_367 = false ;
F_106 ( V_2 -> V_30 ) ;
F_107 (
V_2 -> V_30 , V_368 ,
F_80 , V_2 ) ;
V_2 -> V_369 = NULL ;
V_2 -> V_213 = V_212 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_370 , 0 , sizeof( V_2 -> V_370 ) ) ;
memset ( V_2 -> V_371 , 0 , sizeof( V_2 -> V_371 ) ) ;
memset ( V_2 -> V_372 , 0 , sizeof( V_2 -> V_372 ) ) ;
memset ( & V_2 -> V_373 , 0 , sizeof( V_2 -> V_373 ) ) ;
memset ( & V_2 -> V_374 , 0 , sizeof( V_2 -> V_374 ) ) ;
memset ( & V_2 -> V_375 , 0 , sizeof( V_2 -> V_375 ) ) ;
memset ( & V_2 -> V_376 , 0 , sizeof( V_2 -> V_376 ) ) ;
memset ( & V_2 -> V_377 , 0 , sizeof( V_2 -> V_377 ) ) ;
memset ( & V_2 -> V_378 , 0 , sizeof( V_2 -> V_378 ) ) ;
F_108 ( V_2 -> V_30 ) ;
F_102 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_379 = 0 ;
V_2 -> V_380 = 0 ;
V_2 -> V_381 = V_382 ;
F_109 ( V_2 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_383 , & V_2 -> V_15 ) )
F_103 ( V_2 ) ;
V_47 = F_111 ( V_2 ) ;
if ( V_47 && F_14 ( V_383 , & V_2 -> V_15 ) ) {
F_102 ( V_383 , & V_2 -> V_15 ) ;
F_112 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_113 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_383 , & V_2 -> V_15 ) ) {
F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ;
}
F_73 ( & V_2 -> V_33 ) ;
V_47 = F_110 ( V_2 ) ;
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_114 ( struct V_1 * V_2 )
{
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
F_102 ( V_383 , & V_2 -> V_15 ) ;
F_112 ( V_2 , NULL ) ;
V_47 = F_115 ( V_2 , true , NULL ) ;
if ( V_47 )
F_116 ( V_2 , L_14 ,
V_47 ) ;
F_7 ( V_2 , V_363 ) ;
F_117 ( V_2 ) ;
F_79 ( & V_2 -> V_33 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
bool V_384 ;
if ( ! F_2 ( V_2 ) )
return;
F_73 ( & V_2 -> V_385 ) ;
F_119 ( V_386 , & V_2 -> V_387 ) ;
V_384 = F_120 ( V_388 ,
& V_2 -> V_387 ) ;
F_79 ( & V_2 -> V_385 ) ;
if ( V_384 ) {
F_3 ( V_2 , L_15 ) ;
F_121 ( V_2 ) ;
}
if ( V_2 -> V_7 -> V_389 == V_390 )
if ( ! F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) )
F_122 ( 1 , L_16 ) ;
}
static void
F_123 ( struct V_29 * V_30 ,
enum V_391 V_392 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_392 ) {
case V_393 :
F_114 ( V_2 ) ;
break;
case V_394 :
F_118 ( V_2 ) ;
break;
}
}
void F_124 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_395 , 0 , sizeof( V_2 -> V_395 ) ) ;
if ( ! F_14 ( V_383 , & V_2 -> V_15 ) )
F_1 ( V_2 , V_363 ) ;
F_125 ( & V_2 -> V_396 ) ;
F_105 ( V_2 -> V_7 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
F_102 ( V_383 , & V_2 -> V_15 ) ;
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] & V_397 ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_398 ; V_9 ++ ) {
if ( F_122 ( V_2 -> V_399 [ V_9 ] ,
L_17 ,
V_2 -> V_399 [ V_9 ] ) )
V_2 -> V_399 [ V_9 ] = 0 ;
}
}
V_2 -> V_400 = false ;
}
static void F_128 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_129 ( & V_2 -> V_401 ) ;
F_129 ( & V_2 -> V_402 ) ;
F_130 ( & V_2 -> V_403 ) ;
F_94 ( V_2 ) ;
F_73 ( & V_2 -> V_33 ) ;
F_124 ( V_2 ) ;
F_79 ( & V_2 -> V_33 ) ;
F_125 ( & V_2 -> V_402 ) ;
}
static struct V_404 * F_131 ( struct V_1 * V_2 )
{
V_94 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_116 ( V_2 , L_18 ) ;
return NULL ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_234 * V_235 , T_6 V_405 )
{
struct V_406 V_407 = {
. V_408 = F_81 ( V_235 ) -> V_20 ,
. V_409 = F_133 ( V_405 ) ,
} ;
return F_134 ( V_2 , V_410 , 0 ,
sizeof( V_407 ) ,
& V_407 ) ;
}
static int F_135 ( struct V_1 * V_2 , struct V_234 * V_235 ,
T_7 V_405 )
{
struct V_411 V_412 = {
. V_413 = 0 ,
. V_408 =
F_89 ( F_81 ( V_235 ) -> V_20 ) ,
. V_409 = F_133 ( 8 * V_405 ) ,
} ;
if ( ! ( V_2 -> V_79 -> V_80 . V_134 [ 0 ] & V_414 ) )
return F_132 ( V_2 , V_235 , V_405 ) ;
if ( V_405 == V_415 )
V_412 . V_409 = F_133 ( V_416 ) ;
return F_134 ( V_2 , V_410 , 0 ,
sizeof( V_412 ) , & V_412 ) ;
}
static int F_136 ( struct V_29 * V_30 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
int V_47 ;
V_254 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_417 ) ;
if ( V_47 )
return V_47 ;
F_73 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_383 , & V_2 -> V_15 ) )
V_254 -> V_418 . V_419 +=
V_254 -> V_418 . V_420 ;
V_47 = F_137 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_421;
if ( V_235 -> type != V_100 )
V_2 -> V_379 ++ ;
if ( V_235 -> type == V_98 ||
V_235 -> type == V_101 ) {
V_47 = F_138 ( V_2 , V_235 ) ;
if ( V_47 ) {
F_116 ( V_2 , L_19 ) ;
goto V_422;
}
F_139 ( V_2 , V_235 ) ;
goto V_421;
}
V_47 = F_140 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_422;
V_47 = F_141 ( V_2 ) ;
if ( V_47 )
goto V_423;
V_47 = F_142 ( V_2 , V_235 , 0 ) ;
if ( V_47 )
goto V_423;
if ( ! V_2 -> V_424 &&
V_235 -> type == V_96 && ! V_235 -> V_425 ) {
V_2 -> V_424 = V_254 ;
V_235 -> V_426 |= V_427 |
V_428 ;
}
if ( V_235 -> type == V_100 ) {
V_254 -> V_259 = F_131 ( V_2 ) ;
if ( ! V_254 -> V_259 ) {
V_47 = - V_429 ;
goto V_430;
}
F_143 ( V_2 , V_254 -> V_259 ) ;
V_47 = F_144 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_431;
V_47 = F_145 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_432;
V_2 -> V_369 = V_235 ;
}
F_139 ( V_2 , V_235 ) ;
goto V_421;
V_432:
F_146 ( V_2 , V_235 ) ;
V_431:
F_147 ( V_2 , V_254 -> V_259 ) ;
V_430:
if ( V_2 -> V_424 == V_254 ) {
V_2 -> V_424 = NULL ;
V_235 -> V_426 &= ~ ( V_427 |
V_428 ) ;
}
V_423:
V_254 -> V_259 = NULL ;
F_148 ( V_2 , V_235 ) ;
V_422:
if ( V_235 -> type != V_100 )
V_2 -> V_379 -- ;
F_149 ( V_2 , V_235 ) ;
V_421:
F_79 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_417 ) ;
return V_47 ;
}
static void F_150 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
T_5 V_433 = F_151 ( V_235 ) ;
if ( V_433 ) {
F_73 ( & V_2 -> V_33 ) ;
F_152 ( V_2 , V_433 , true ) ;
F_79 ( & V_2 -> V_33 ) ;
F_153 ( V_2 -> V_7 , V_433 ) ;
}
if ( V_235 -> type == V_100 ) {
F_129 ( & V_2 -> V_396 ) ;
} else {
F_129 ( & V_2 -> V_434 ) ;
}
}
static void F_154 ( struct V_29 * V_30 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
F_150 ( V_2 , V_235 ) ;
F_73 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_424 == V_254 ) {
V_2 -> V_424 = NULL ;
V_235 -> V_426 &= ~ ( V_427 |
V_428 ) ;
}
F_155 ( V_2 , V_235 ) ;
if ( V_235 -> type == V_98 ||
V_235 -> type == V_101 ) {
#ifdef F_156
if ( V_235 == V_2 -> V_435 ) {
V_2 -> V_435 = NULL ;
V_2 -> V_436 = 0 ;
}
#endif
F_157 ( V_2 , V_235 ) ;
goto V_422;
}
if ( V_235 -> type == V_100 ) {
V_2 -> V_369 = NULL ;
F_158 ( V_2 , V_235 ) ;
F_146 ( V_2 , V_235 ) ;
F_147 ( V_2 , V_254 -> V_259 ) ;
V_254 -> V_259 = NULL ;
}
if ( V_2 -> V_379 && V_235 -> type != V_100 )
V_2 -> V_379 -- ;
F_141 ( V_2 ) ;
F_148 ( V_2 , V_235 ) ;
V_422:
F_149 ( V_2 , V_235 ) ;
F_79 ( & V_2 -> V_33 ) ;
}
static int F_159 ( struct V_29 * V_30 , T_5 V_27 )
{
return 0 ;
}
static void F_160 ( void * V_437 , T_1 * V_253 ,
struct V_234 * V_235 )
{
struct V_438 * V_222 = V_437 ;
struct V_1 * V_2 = V_222 -> V_2 ;
struct V_439 * V_412 = V_2 -> V_440 ;
int V_47 , V_177 ;
if ( F_15 ( V_222 -> V_441 >= V_442 ) )
return;
if ( V_235 -> type != V_96 ||
! V_235 -> V_443 . V_444 )
return;
V_412 -> V_441 = V_222 -> V_441 ++ ;
memcpy ( V_412 -> V_445 , V_235 -> V_443 . V_445 , V_122 ) ;
V_177 = F_161 ( sizeof( * V_412 ) + V_412 -> V_263 * V_122 , 4 ) ;
V_47 = F_134 ( V_2 , V_446 , V_447 , V_177 , V_412 ) ;
if ( V_47 )
F_116 ( V_2 , L_20 , V_47 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_438 V_448 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_440 ) )
return;
F_107 (
V_2 -> V_30 , V_449 ,
F_160 , & V_448 ) ;
}
static T_8 F_163 ( struct V_29 * V_30 ,
struct V_450 * V_451 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_439 * V_412 ;
struct V_452 * V_119 ;
int V_453 ;
bool V_454 ;
int V_177 ;
V_453 = F_164 ( V_451 ) ;
V_454 = V_453 > V_455 ||
V_456 ;
if ( V_454 )
V_453 = 0 ;
V_177 = F_161 ( sizeof( * V_412 ) + V_453 * V_122 , 4 ) ;
V_412 = F_96 ( V_177 , V_457 ) ;
if ( ! V_412 )
return 0 ;
if ( V_454 ) {
V_412 -> V_454 = 1 ;
return ( T_8 ) ( unsigned long ) V_412 ;
}
F_165 (addr, mc_list) {
F_166 ( V_2 , L_21 ,
V_412 -> V_263 , V_119 -> V_119 ) ;
memcpy ( & V_412 -> V_458 [ V_412 -> V_263 * V_122 ] ,
V_119 -> V_119 , V_122 ) ;
V_412 -> V_263 ++ ;
}
return ( T_8 ) ( unsigned long ) V_412 ;
}
static void F_167 ( struct V_29 * V_30 ,
unsigned int V_459 ,
unsigned int * V_460 ,
T_8 V_461 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_439 * V_412 = ( void * ) ( unsigned long ) V_461 ;
F_73 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_440 ) ;
V_2 -> V_440 = V_412 ;
if ( ! V_412 )
goto V_34;
F_162 ( V_2 ) ;
V_34:
F_79 ( & V_2 -> V_33 ) ;
* V_460 = 0 ;
}
static void
F_168 ( struct V_234 * V_235 ,
const struct V_462 * V_463 ,
struct V_462 * V_464 )
{
struct V_465 * V_466 ;
int V_9 ;
memcpy ( V_464 , V_463 , sizeof( * V_464 ) ) ;
for ( V_9 = 0 ; V_9 < F_39 ( V_464 -> V_467 ) ; V_9 ++ ) {
V_466 = & V_464 -> V_467 [ V_9 ] ;
if ( ! V_466 -> V_468 )
break;
switch ( V_466 -> V_469 ) {
case F_133 ( V_470 ) :
if ( V_235 -> V_443 . V_471 != 1 ) {
V_466 -> V_468 = 0 ;
continue;
}
V_466 -> V_472 = V_235 -> V_443 . V_473 [ 0 ] ;
break;
case F_133 ( V_474 ) :
V_466 -> V_472 = * ( V_475 * ) & V_235 -> V_119 [ 2 ] ;
break;
default:
break;
}
V_466 -> V_469 = 0 ;
V_464 -> V_476 ++ ;
}
}
static void F_169 ( void * V_437 , T_1 * V_253 ,
struct V_234 * V_235 )
{
struct V_477 * V_222 = V_437 ;
struct V_1 * V_2 = V_222 -> V_2 ;
struct V_478 * V_412 = V_222 -> V_412 ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
struct V_479 * V_480 ;
int V_9 ;
if ( F_8 ( V_254 -> V_20 >= F_39 ( V_412 -> V_481 ) ) )
return;
V_480 = & V_412 -> V_481 [ V_254 -> V_20 ] ;
if ( V_235 -> type != V_96 || V_235 -> V_425 ||
! V_235 -> V_443 . V_444 )
return;
V_480 -> V_482 = 1 ;
for ( V_9 = 0 ; V_2 -> V_198 [ V_9 ] . V_467 [ 0 ] . V_468 ; V_9 ++ ) {
if ( F_15 ( V_222 -> V_483 >=
F_39 ( V_412 -> V_484 ) ) ) {
V_480 -> V_482 = 0 ;
V_480 -> V_485 = 0 ;
break;
}
F_168 ( V_235 ,
& V_2 -> V_198 [ V_9 ] ,
& V_412 -> V_484 [ V_222 -> V_483 ] ) ;
if ( ! V_412 -> V_484 [ V_222 -> V_483 ] . V_476 )
continue;
V_480 -> V_485 |=
F_133 ( F_38 ( V_222 -> V_483 ) ) ;
V_222 -> V_483 ++ ;
}
}
bool F_170 ( struct V_1 * V_2 ,
struct V_478 * V_412 )
{
struct V_477 V_448 = {
. V_2 = V_2 ,
. V_412 = V_412 ,
} ;
if ( V_486 )
return false ;
memset ( V_412 , 0 , sizeof( * V_412 ) ) ;
V_412 -> V_487 = F_39 ( V_412 -> V_484 ) ;
V_412 -> V_488 = F_39 ( V_412 -> V_481 ) ;
#ifdef F_171
if ( V_2 -> V_489 . V_490 ) {
memcpy ( V_412 -> V_484 , & V_2 -> V_489 . V_412 . V_484 ,
sizeof( V_412 -> V_484 ) ) ;
memcpy ( V_412 -> V_481 , & V_2 -> V_489 . V_412 . V_481 ,
sizeof( V_412 -> V_481 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_198 )
return false ;
F_172 (
V_2 -> V_30 , V_449 ,
F_169 , & V_448 ) ;
return true ;
}
static int F_173 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
struct V_478 V_412 ;
if ( ! ( V_2 -> V_79 -> V_80 . V_51 & V_491 ) )
return 0 ;
if ( ! F_170 ( V_2 , & V_412 ) )
return 0 ;
return F_134 ( V_2 , V_492 , 0 ,
sizeof( V_412 ) , & V_412 ) ;
}
static inline int F_173 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
return 0 ;
}
static void F_174 ( struct V_1 * V_2 ,
struct V_234 * V_235 ,
struct V_493 * V_443 ,
T_5 V_494 )
{
struct V_92 * V_254 = F_81 ( V_235 ) ;
int V_47 ;
if ( V_494 & V_495 && V_443 -> V_444 )
F_175 ( V_2 , V_235 ) ;
if ( V_494 & V_496 && ! V_254 -> V_497 )
memcpy ( V_254 -> V_445 , V_443 -> V_445 , V_122 ) ;
V_47 = F_176 ( V_2 , V_235 , false , V_254 -> V_445 ) ;
if ( V_47 )
F_116 ( V_2 , L_22 , V_235 -> V_119 ) ;
memcpy ( V_254 -> V_445 , V_443 -> V_445 , V_122 ) ;
V_254 -> V_497 = V_443 -> V_444 ;
if ( V_494 & V_495 ) {
if ( V_443 -> V_444 ) {
F_177 ( V_2 , true ) ;
memset ( & V_254 -> V_418 , 0 ,
sizeof( V_254 -> V_418 ) ) ;
V_47 = F_115 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_116 ( V_2 , L_23 ) ;
return;
}
if ( F_14 ( V_383 ,
& V_2 -> V_15 ) ) {
T_5 V_498 = ( 11 * V_235 -> V_443 . V_499 ) / 10 ;
F_178 ( V_2 , V_235 , V_498 , V_498 ,
5 * V_498 , false ) ;
}
F_179 ( V_2 , V_235 , false ) ;
F_180 ( V_2 , V_235 ) ;
if ( V_235 -> V_425 ) {
F_1 ( V_2 , V_500 ) ;
F_181 ( V_2 , V_235 ,
V_501 ,
V_502 ) ;
}
} else if ( V_254 -> V_256 != V_212 ) {
F_122 ( F_179 ( V_2 , V_235 , false ) ,
L_24 ) ;
V_47 = F_182 ( V_2 , V_235 , V_254 -> V_256 ) ;
if ( V_47 )
F_116 ( V_2 , L_25 ) ;
if ( V_2 -> V_213 == V_254 -> V_256 )
V_2 -> V_213 = V_212 ;
V_254 -> V_256 = V_212 ;
V_47 = F_115 ( V_2 , false , NULL ) ;
if ( V_47 )
F_116 ( V_2 , L_23 ) ;
if ( V_235 -> V_425 )
F_7 ( V_2 , V_500 ) ;
V_47 = F_176 ( V_2 , V_235 , false , NULL ) ;
if ( V_47 )
F_116 ( V_2 ,
L_26 ,
V_235 -> V_119 ) ;
}
F_162 ( V_2 ) ;
F_173 ( V_2 , V_235 ) ;
V_254 -> V_260 . V_503 = 0 ;
F_183 ( V_2 ) ;
F_181 ( V_2 , V_235 , V_504 ,
V_505 ) ;
} else if ( V_494 & V_506 ) {
F_184 ( V_2 , V_254 ,
& V_254 -> V_258 ) ;
}
if ( V_494 & V_506 ) {
F_179 ( V_2 , V_235 , false ) ;
F_8 ( F_185 ( V_2 , V_235 , 0 ) ) ;
}
if ( V_494 & ( V_507 | V_508 | V_509 ) ) {
V_47 = F_141 ( V_2 ) ;
if ( V_47 )
F_116 ( V_2 , L_27 ) ;
}
if ( V_494 & V_510 ) {
F_186 ( V_2 , L_28 ,
V_443 -> V_511 ) ;
F_135 ( V_2 , V_235 , V_443 -> V_511 ) ;
}
if ( V_494 & V_512 ) {
F_166 ( V_2 , L_29 ) ;
V_254 -> V_260 . V_513 = 0 ;
if ( V_254 -> V_260 . V_514 ) {
V_47 = F_185 ( V_2 , V_235 , 0 ) ;
if ( V_47 )
F_116 ( V_2 ,
L_30 ) ;
}
}
if ( V_494 & V_515 ) {
F_166 ( V_2 , L_31 ) ;
F_173 ( V_2 , V_235 ) ;
}
}
static int F_187 ( struct V_29 * V_30 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_516 ) ;
if ( V_47 )
return V_47 ;
F_73 ( & V_2 -> V_33 ) ;
V_47 = F_188 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_421;
if ( V_235 -> type == V_98 )
F_175 ( V_2 , V_235 ) ;
V_47 = F_140 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_421;
V_47 = F_144 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_517;
V_47 = F_189 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_432;
V_254 -> V_518 = true ;
F_141 ( V_2 ) ;
V_47 = F_115 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_519;
if ( V_235 -> V_425 && V_2 -> V_369 )
F_176 ( V_2 , V_2 -> V_369 , false , NULL ) ;
F_1 ( V_2 , V_520 ) ;
F_183 ( V_2 ) ;
if ( F_190 ( V_2 ) > 1 )
F_117 ( V_2 ) ;
goto V_421;
V_519:
F_141 ( V_2 ) ;
V_254 -> V_518 = false ;
F_191 ( V_2 , V_235 ) ;
V_432:
F_146 ( V_2 , V_235 ) ;
V_517:
F_148 ( V_2 , V_235 ) ;
V_421:
F_79 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_516 ) ;
return V_47 ;
}
static void F_192 ( struct V_29 * V_30 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
F_150 ( V_2 , V_235 ) ;
F_73 ( & V_2 -> V_33 ) ;
if ( F_193 ( V_2 -> V_521 ) == V_235 ) {
F_184 ( V_2 , V_254 ,
& V_254 -> V_258 ) ;
F_194 ( V_2 -> V_521 , NULL ) ;
}
if ( F_193 ( V_2 -> V_522 ) == V_235 ) {
F_194 ( V_2 -> V_522 , NULL ) ;
V_2 -> V_523 = 0 ;
}
V_254 -> V_518 = false ;
V_2 -> V_524 = 0 ;
F_183 ( V_2 ) ;
F_7 ( V_2 , V_520 ) ;
if ( V_235 -> V_425 && V_2 -> V_369 )
F_176 ( V_2 , V_2 -> V_369 , false , NULL ) ;
F_115 ( V_2 , false , NULL ) ;
F_191 ( V_2 , V_235 ) ;
F_146 ( V_2 , V_235 ) ;
F_141 ( V_2 ) ;
F_148 ( V_2 , V_235 ) ;
F_79 ( & V_2 -> V_33 ) ;
}
static void
F_195 ( struct V_1 * V_2 ,
struct V_234 * V_235 ,
struct V_493 * V_443 ,
T_5 V_494 )
{
struct V_92 * V_254 = F_81 ( V_235 ) ;
if ( ! V_254 -> V_518 )
return;
if ( V_494 & ( V_525 | V_526 |
V_527 | V_509 ) &&
F_176 ( V_2 , V_235 , false , NULL ) )
F_116 ( V_2 , L_22 , V_235 -> V_119 ) ;
if ( V_494 & V_528 &&
F_188 ( V_2 , V_235 ) )
F_196 ( V_2 , L_32 ) ;
if ( V_494 & V_510 ) {
F_186 ( V_2 , L_28 ,
V_443 -> V_511 ) ;
F_135 ( V_2 , V_235 , V_443 -> V_511 ) ;
}
}
static void F_197 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_493 * V_443 ,
T_5 V_494 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_529 ) )
return;
F_73 ( & V_2 -> V_33 ) ;
if ( V_494 & V_530 && ! V_443 -> V_531 )
F_198 ( V_2 , true ) ;
switch ( V_235 -> type ) {
case V_96 :
F_174 ( V_2 , V_235 , V_443 , V_494 ) ;
break;
case V_98 :
case V_101 :
F_195 ( V_2 , V_235 , V_443 , V_494 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_79 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_529 ) ;
}
static int F_199 ( struct V_1 * V_2 ,
enum V_532 V_533 )
{
int V_47 ;
bool V_534 = false ;
F_73 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_364 != V_533 ) {
V_47 = 0 ;
V_534 = true ;
goto V_34;
}
switch ( V_533 ) {
case V_535 :
V_47 = F_198 ( V_2 , true ) ;
break;
case V_536 :
V_47 = F_200 ( V_2 ) ;
break;
case V_365 :
default:
F_15 ( 1 ) ;
V_47 = - V_251 ;
break;
}
if ( V_47 )
goto V_34;
V_534 = true ;
V_34:
F_79 ( & V_2 -> V_33 ) ;
if ( V_534 )
F_201 ( V_2 ) ;
return V_47 ;
}
static int F_202 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_537 * V_538 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_539 * V_540 = & V_538 -> V_540 ;
int V_47 ;
if ( V_540 -> V_38 == 0 ||
V_540 -> V_38 > V_2 -> V_79 -> V_80 . V_541 )
return - V_251 ;
if ( ! ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] & V_397 ) ) {
V_47 = F_199 ( V_2 , V_535 ) ;
if ( V_47 )
return V_47 ;
}
F_73 ( & V_2 -> V_33 ) ;
if ( F_30 ( V_2 ) && ! V_2 -> V_42 ) {
F_116 ( V_2 , L_33 ) ;
V_47 = - V_542 ;
goto V_34;
}
if ( V_2 -> V_364 != V_365 ) {
V_47 = - V_542 ;
goto V_34;
}
F_1 ( V_2 , V_543 ) ;
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] & V_397 )
V_47 = F_203 ( V_2 , V_235 , V_538 ) ;
else
V_47 = F_204 ( V_2 , V_235 , V_538 ) ;
if ( V_47 )
F_7 ( V_2 , V_543 ) ;
V_34:
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_205 ( struct V_29 * V_30 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_73 ( & V_2 -> V_33 ) ;
if ( ( V_2 -> V_364 == V_536 ) ||
( V_2 -> V_79 -> V_80 . V_132 [ 0 ] & V_397 ) )
F_200 ( V_2 ) ;
F_79 ( & V_2 -> V_33 ) ;
}
static void
F_206 ( struct V_29 * V_30 ,
struct V_204 * V_205 , V_94 V_544 ,
int V_545 ,
enum V_546 V_547 ,
bool V_548 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_207 ( V_2 , V_205 , V_547 , V_545 ,
V_544 , V_548 , false ) ;
}
static void
F_208 ( struct V_29 * V_30 ,
struct V_204 * V_205 , V_94 V_544 ,
int V_545 ,
enum V_546 V_547 ,
bool V_548 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_207 ( V_2 , V_205 , V_547 , V_545 ,
V_544 , V_548 , true ) ;
}
static void F_209 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
enum V_549 V_412 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_90 * V_208 = F_53 ( V_205 ) ;
unsigned long V_550 = 0 , V_544 = 0 ;
int V_238 ;
F_4 ( & V_208 -> V_551 ) ;
for ( V_238 = 0 ; V_238 < V_552 ; V_238 ++ ) {
struct V_553 * V_554 = & V_208 -> V_554 [ V_238 ] ;
if ( V_554 -> V_555 != V_556 &&
V_554 -> V_555 != V_557 )
continue;
F_210 ( V_554 -> V_558 , & V_550 ) ;
if ( F_211 ( V_554 ) == 0 )
continue;
F_210 ( V_238 , & V_544 ) ;
}
switch ( V_412 ) {
case V_559 :
if ( F_212 ( & V_2 -> V_560 [ V_208 -> V_211 ] ) > 0 )
F_213 ( V_30 , V_205 , true ) ;
F_214 (tid, &tids, IWL_MAX_TID_COUNT)
F_215 ( V_205 , V_238 , true ) ;
if ( V_550 )
F_216 ( V_2 -> V_7 , V_550 , true ) ;
break;
case V_561 :
if ( F_8 ( V_208 -> V_211 == V_212 ) )
break;
if ( V_550 )
F_216 ( V_2 -> V_7 , V_550 , false ) ;
F_217 ( V_2 , V_205 ) ;
break;
default:
break;
}
F_5 ( & V_208 -> V_551 ) ;
}
static void F_218 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_90 * V_562 = F_53 ( V_205 ) ;
F_73 ( & V_2 -> V_33 ) ;
if ( V_205 == F_193 ( V_2 -> V_563 [ V_562 -> V_211 ] ) )
F_219 ( V_2 -> V_563 [ V_562 -> V_211 ] ,
F_220 ( - V_49 ) ) ;
F_79 ( & V_2 -> V_33 ) ;
}
static void F_221 ( struct V_1 * V_2 , struct V_234 * V_235 ,
const T_1 * V_445 )
{
if ( ! ( V_2 -> V_79 -> V_80 . V_51 & V_564 ) )
return;
if ( V_82 . V_565 ) {
V_235 -> V_426 &= ~ V_566 ;
return;
}
V_235 -> V_426 |= V_566 ;
}
static int F_222 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_204 * V_205 ,
enum V_567 V_568 ,
enum V_567 V_569 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
int V_47 ;
F_166 ( V_2 , L_34 ,
V_205 -> V_119 , V_568 , V_569 ) ;
if ( F_15 ( ! V_254 -> V_259 ) )
return - V_251 ;
F_129 ( & V_2 -> V_434 ) ;
F_73 ( & V_2 -> V_33 ) ;
if ( V_568 == V_570 &&
V_569 == V_571 ) {
if ( V_235 -> type == V_96 &&
V_235 -> V_443 . V_499 < 16 ) {
F_116 ( V_2 ,
L_35 ,
V_205 -> V_119 , V_235 -> V_443 . V_499 ) ;
V_47 = - V_251 ;
goto V_421;
}
if ( V_205 -> V_572 &&
( V_235 -> V_425 ||
F_223 ( V_2 , NULL ) ==
V_573 ||
F_190 ( V_2 ) > 1 ) ) {
F_166 ( V_2 , L_36 ) ;
V_47 = - V_542 ;
goto V_421;
}
V_47 = F_224 ( V_2 , V_235 , V_205 ) ;
if ( V_205 -> V_572 && V_47 == 0 )
F_225 ( V_2 , V_235 , true ) ;
} else if ( V_568 == V_571 &&
V_569 == V_574 ) {
V_2 -> V_575 = true ;
F_221 ( V_2 , V_235 , V_205 -> V_119 ) ;
V_47 = 0 ;
} else if ( V_568 == V_574 &&
V_569 == V_576 ) {
V_47 = F_226 ( V_2 , V_235 , V_205 ) ;
if ( V_47 == 0 )
F_227 ( V_2 , V_205 ,
V_254 -> V_259 -> V_577 -> V_578 ,
true ) ;
} else if ( V_568 == V_576 &&
V_569 == V_579 ) {
if ( F_190 ( V_2 ) > 1 )
F_117 ( V_2 ) ;
F_8 ( F_185 ( V_2 , V_235 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_568 == V_579 &&
V_569 == V_576 ) {
F_8 ( F_142 ( V_2 , V_235 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_568 == V_576 &&
V_569 == V_574 ) {
V_47 = 0 ;
} else if ( V_568 == V_574 &&
V_569 == V_571 ) {
V_47 = 0 ;
} else if ( V_568 == V_571 &&
V_569 == V_570 ) {
V_47 = F_228 ( V_2 , V_235 , V_205 ) ;
if ( V_205 -> V_572 )
F_225 ( V_2 , V_235 , false ) ;
} else {
V_47 = - V_17 ;
}
V_421:
F_79 ( & V_2 -> V_33 ) ;
if ( V_205 -> V_572 && V_47 == 0 ) {
if ( V_568 == V_570 &&
V_569 == V_571 )
F_229 ( V_205 , V_580 ) ;
else if ( V_568 == V_571 &&
V_569 == V_570 )
F_230 ( V_205 , V_580 ) ;
}
return V_47 ;
}
static int F_231 ( struct V_29 * V_30 , T_5 V_581 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_166 = V_581 ;
return 0 ;
}
static void F_232 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_204 * V_205 , T_5 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_235 -> type == V_96 &&
V_27 & V_582 )
F_179 ( V_2 , V_235 , false ) ;
}
static int F_233 ( struct V_29 * V_30 ,
struct V_234 * V_235 , V_94 V_583 ,
const struct V_584 * V_585 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
V_254 -> V_586 [ V_583 ] = * V_585 ;
if ( V_235 -> type == V_100 ) {
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
V_47 = F_176 ( V_2 , V_235 , false , NULL ) ;
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_234 ( struct V_29 * V_30 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_5 V_587 = F_40 ( V_588 ,
200 + V_235 -> V_443 . V_499 ) ;
T_5 V_589 = F_40 ( V_590 ,
100 + V_235 -> V_443 . V_499 ) ;
if ( F_15 ( V_235 -> V_443 . V_444 ) )
return;
if ( F_12 ( V_2 , V_591 ) )
return;
F_73 ( & V_2 -> V_33 ) ;
F_178 ( V_2 , V_235 , V_587 , V_589 , 500 , false ) ;
F_79 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_591 ) ;
}
static int F_235 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_592 * V_540 ,
struct V_593 * V_594 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( ! ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] & V_397 ) ) {
V_47 = F_199 ( V_2 , V_536 ) ;
if ( V_47 )
return V_47 ;
}
F_73 ( & V_2 -> V_33 ) ;
if ( F_30 ( V_2 ) && ! V_2 -> V_42 ) {
F_116 ( V_2 , L_37 ) ;
V_47 = - V_542 ;
goto V_34;
}
if ( ! V_235 -> V_443 . V_531 ) {
V_47 = - V_542 ;
goto V_34;
}
if ( V_2 -> V_364 != V_365 ) {
V_47 = - V_542 ;
goto V_34;
}
V_47 = F_236 ( V_2 , V_235 , V_540 , V_594 ) ;
if ( V_47 )
V_2 -> V_364 = V_365 ;
V_34:
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_237 ( struct V_29 * V_30 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_364 != V_535 &&
! ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] & V_397 ) ) {
F_79 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_198 ( V_2 , false ) ;
F_79 ( & V_2 -> V_33 ) ;
F_201 ( V_2 ) ;
return V_47 ;
}
static int F_238 ( struct V_29 * V_30 ,
enum V_595 V_412 ,
struct V_234 * V_235 ,
struct V_204 * V_205 ,
struct V_596 * V_597 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_82 . V_83 ) {
F_166 ( V_2 , L_38 ) ;
return - V_598 ;
}
switch ( V_597 -> V_169 ) {
case V_599 :
V_597 -> V_51 |= V_600 ;
case V_601 :
V_597 -> V_51 |= V_602 ;
break;
case V_603 :
F_15 ( ! ( V_30 -> V_51 & V_84 ) ) ;
break;
case V_604 :
case V_605 :
if ( V_235 -> type != V_96 )
return 0 ;
break;
default:
if ( V_30 -> V_170 &&
V_30 -> V_171 -> V_169 == V_597 -> V_169 )
V_597 -> V_51 |= V_606 ;
else
return - V_598 ;
}
F_73 ( & V_2 -> V_33 ) ;
switch ( V_412 ) {
case V_607 :
if ( ( V_235 -> type == V_101 ||
V_235 -> type == V_98 ) && ! V_205 ) {
V_47 = 0 ;
V_597 -> V_608 = V_609 ;
break;
}
F_166 ( V_2 , L_39 ) ;
V_47 = F_239 ( V_2 , V_235 , V_205 , V_597 , false ) ;
if ( V_47 ) {
F_196 ( V_2 , L_40 ) ;
V_597 -> V_608 = V_609 ;
V_47 = 0 ;
}
break;
case V_610 :
if ( V_597 -> V_608 == V_609 ) {
V_47 = 0 ;
break;
}
F_166 ( V_2 , L_41 ) ;
V_47 = F_240 ( V_2 , V_235 , V_205 , V_597 ) ;
break;
default:
V_47 = - V_251 ;
}
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_241 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_596 * V_611 ,
struct V_204 * V_205 ,
T_5 V_612 , V_94 * V_613 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_611 -> V_608 == V_609 )
return;
F_242 ( V_2 , V_235 , V_611 , V_205 , V_612 , V_613 ) ;
}
static bool F_243 ( struct V_614 * V_615 ,
struct V_616 * V_617 , void * V_222 )
{
struct V_1 * V_2 =
F_244 ( V_615 , struct V_1 , V_615 ) ;
struct V_618 * V_32 ;
int V_619 = F_245 ( V_617 ) ;
struct V_620 * V_621 = V_222 ;
if ( F_8 ( V_617 -> V_221 . V_412 != V_622 ) )
return true ;
if ( F_15 ( V_619 != sizeof( * V_32 ) ) ) {
F_116 ( V_2 , L_42 ) ;
return true ;
}
V_32 = ( void * ) V_617 -> V_222 ;
F_246 ( V_2 ,
L_43 ,
V_32 -> V_15 , V_32 -> V_623 ) ;
V_621 -> V_624 = F_247 ( V_32 -> V_623 ) ;
F_246 ( V_2 , L_44 ,
V_621 -> V_624 ) ;
F_4 ( & V_2 -> V_257 ) ;
F_248 ( & V_621 -> V_625 , & V_2 -> V_626 ) ;
F_5 ( & V_2 -> V_257 ) ;
return true ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_627 * V_577 ,
struct V_234 * V_235 ,
int V_587 )
{
int V_628 , V_629 = V_630 ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
struct V_620 * V_621 = & V_254 -> V_631 ;
static const T_1 V_632 [] = { V_622 } ;
struct V_633 V_634 ;
struct V_635 V_636 = {
. V_237 = F_89 ( V_637 ) ,
. V_638 =
F_89 ( F_250 ( V_639 , 0 ) ) ,
. V_640 = F_89 ( V_2 -> V_641 . V_211 ) ,
. V_642 . V_578 = ( V_577 -> V_578 == V_130 ) ?
V_643 : V_644 ,
. V_642 . V_577 = V_577 -> V_645 ,
. V_642 . V_646 = V_647 ,
. V_648 = F_89 ( F_251 ( V_2 -> V_7 , V_629 ) ) ,
. V_649 =
F_89 ( F_252 ( V_650 ) ) ,
. V_587 = F_89 ( F_252 ( V_587 ) ) ,
} ;
memcpy ( V_636 . V_651 , V_235 -> V_119 , V_122 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_257 ) ;
if ( F_8 ( V_621 -> V_20 == V_622 ) ) {
F_5 ( & V_2 -> V_257 ) ;
return - V_17 ;
}
V_621 -> V_235 = V_235 ;
V_621 -> V_587 = V_587 ;
V_621 -> V_20 = V_622 ;
F_5 ( & V_2 -> V_257 ) ;
F_253 ( & V_2 -> V_615 , & V_634 ,
V_632 ,
F_39 ( V_632 ) ,
F_243 , V_621 ) ;
V_628 = F_134 ( V_2 , V_622 , 0 , sizeof( V_636 ) ,
& V_636 ) ;
if ( V_628 ) {
F_116 ( V_2 , L_45 , V_628 ) ;
F_254 ( & V_2 -> V_615 , & V_634 ) ;
goto V_652;
}
V_628 = F_255 ( & V_2 -> V_615 , & V_634 , 1 ) ;
F_15 ( V_628 ) ;
if ( V_628 ) {
V_652:
F_4 ( & V_2 -> V_257 ) ;
F_82 ( V_2 , V_621 ) ;
F_5 ( & V_2 -> V_257 ) ;
}
return V_628 ;
}
static int F_256 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_627 * V_577 ,
int V_587 ,
enum V_653 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
struct V_654 V_655 ;
struct V_404 * V_259 ;
int V_47 , V_9 ;
F_166 ( V_2 , L_46 , V_577 -> V_645 ,
V_587 , type ) ;
F_129 ( & V_2 -> V_396 ) ;
F_73 ( & V_2 -> V_33 ) ;
switch ( V_235 -> type ) {
case V_96 :
if ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_656 ) {
V_47 = F_249 ( V_2 , V_577 ,
V_235 , V_587 ) ;
goto V_421;
}
F_116 ( V_2 , L_47 ) ;
V_47 = - V_251 ;
goto V_421;
case V_100 :
break;
default:
F_116 ( V_2 , L_48 , V_235 -> type ) ;
V_47 = - V_251 ;
goto V_421;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_259 = & V_2 -> V_18 [ V_9 ] ;
if ( V_259 -> V_21 == 0 || V_254 -> V_259 == V_259 )
continue;
if ( V_259 -> V_21 && V_577 == V_259 -> V_577 ) {
V_47 = F_146 ( V_2 , V_235 ) ;
if ( F_257 ( V_47 , L_49 ) )
goto V_421;
F_147 ( V_2 , V_254 -> V_259 ) ;
V_254 -> V_259 = V_259 ;
V_47 = F_144 ( V_2 , V_235 ) ;
if ( F_257 ( V_47 , L_50 ) )
goto V_421;
F_143 ( V_2 , V_254 -> V_259 ) ;
goto V_657;
}
}
if ( V_577 == V_254 -> V_259 -> V_577 )
goto V_657;
F_258 ( & V_655 , V_577 , V_658 ) ;
if ( V_254 -> V_259 -> V_21 == 1 ) {
V_47 = F_259 ( V_2 , V_254 -> V_259 ,
& V_655 , 1 , 1 ) ;
if ( V_47 )
goto V_421;
} else {
V_259 = F_131 ( V_2 ) ;
if ( ! V_259 ) {
V_47 = - V_429 ;
goto V_421;
}
V_47 = F_259 ( V_2 , V_259 , & V_655 ,
1 , 1 ) ;
if ( V_47 ) {
F_116 ( V_2 , L_51 ) ;
goto V_421;
}
V_47 = F_146 ( V_2 , V_235 ) ;
if ( F_257 ( V_47 , L_49 ) )
goto V_421;
F_147 ( V_2 , V_254 -> V_259 ) ;
V_254 -> V_259 = V_259 ;
V_47 = F_144 ( V_2 , V_235 ) ;
if ( F_257 ( V_47 , L_50 ) )
goto V_421;
F_143 ( V_2 , V_254 -> V_259 ) ;
}
V_657:
V_47 = F_260 ( V_2 , V_235 , V_587 , type ) ;
V_421:
F_79 ( & V_2 -> V_33 ) ;
F_166 ( V_2 , L_52 ) ;
return V_47 ;
}
static int F_261 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_166 ( V_2 , L_53 ) ;
F_73 ( & V_2 -> V_33 ) ;
F_262 ( V_2 ) ;
F_79 ( & V_2 -> V_33 ) ;
F_166 ( V_2 , L_52 ) ;
return 0 ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_659 * V_660 )
{
V_94 * V_661 = ( V_94 * ) V_660 -> V_662 ;
struct V_404 * V_259 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_166 ( V_2 , L_54 ) ;
V_259 = F_131 ( V_2 ) ;
if ( ! V_259 ) {
V_47 = - V_429 ;
goto V_34;
}
V_47 = F_259 ( V_2 , V_259 , & V_660 -> V_663 ,
V_660 -> V_664 ,
V_660 -> V_665 ) ;
if ( V_47 ) {
F_116 ( V_2 , L_55 ) ;
goto V_34;
}
F_143 ( V_2 , V_259 ) ;
* V_661 = V_259 -> V_20 ;
V_34:
return V_47 ;
}
static int F_264 ( struct V_29 * V_30 ,
struct V_659 * V_660 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
V_47 = F_263 ( V_2 , V_660 ) ;
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_265 ( struct V_1 * V_2 ,
struct V_659 * V_660 )
{
V_94 * V_661 = ( V_94 * ) V_660 -> V_662 ;
struct V_404 * V_259 = & V_2 -> V_18 [ * V_661 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_147 ( V_2 , V_259 ) ;
}
static void F_266 ( struct V_29 * V_30 ,
struct V_659 * V_660 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_73 ( & V_2 -> V_33 ) ;
F_265 ( V_2 , V_660 ) ;
F_79 ( & V_2 -> V_33 ) ;
}
static void F_267 ( struct V_29 * V_30 ,
struct V_659 * V_660 ,
T_5 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_94 * V_661 = ( V_94 * ) V_660 -> V_662 ;
struct V_404 * V_259 = & V_2 -> V_18 [ * V_661 ] ;
if ( F_122 ( ( V_259 -> V_21 > 1 ) &&
( V_27 & ~ ( V_666 |
V_667 |
V_668 |
V_669 ) ) ,
L_56 ,
V_259 -> V_21 , V_27 ) )
return;
F_73 ( & V_2 -> V_33 ) ;
F_183 ( V_2 ) ;
F_259 ( V_2 , V_259 , & V_660 -> V_663 ,
V_660 -> V_664 ,
V_660 -> V_665 ) ;
F_79 ( & V_2 -> V_33 ) ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_234 * V_235 ,
struct V_659 * V_660 ,
bool V_670 )
{
V_94 * V_661 = ( V_94 * ) V_660 -> V_662 ;
struct V_404 * V_259 = & V_2 -> V_18 [ * V_661 ] ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_254 -> V_259 = V_259 ;
switch ( V_235 -> type ) {
case V_98 :
if ( V_670 ) {
V_254 -> V_518 = true ;
break;
}
case V_101 :
V_47 = 0 ;
goto V_34;
case V_96 :
break;
case V_671 :
V_254 -> V_366 = true ;
break;
default:
V_47 = - V_251 ;
goto V_34;
}
V_47 = F_144 ( V_2 , V_235 ) ;
if ( V_47 )
goto V_34;
F_141 ( V_2 ) ;
if ( V_235 -> type == V_671 ) {
V_254 -> V_672 = true ;
V_47 = F_115 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_673;
}
if ( V_235 -> type == V_98 ) {
F_115 ( V_2 , false , NULL ) ;
F_176 ( V_2 , V_235 , false , NULL ) ;
}
if ( V_670 && V_235 -> type == V_96 ) {
T_5 V_587 = 2 * V_235 -> V_443 . V_499 ;
V_47 = F_12 ( V_2 , V_674 ) ;
if ( V_47 )
goto V_673;
F_178 ( V_2 , V_235 , V_587 , V_587 ,
V_235 -> V_443 . V_499 / 2 ,
true ) ;
F_7 ( V_2 , V_674 ) ;
F_115 ( V_2 , false , NULL ) ;
}
goto V_34;
V_673:
F_146 ( V_2 , V_235 ) ;
F_141 ( V_2 ) ;
V_34:
if ( V_47 )
V_254 -> V_259 = NULL ;
return V_47 ;
}
static int F_269 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_659 * V_660 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
V_47 = F_268 ( V_2 , V_235 , V_660 , false ) ;
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_270 ( struct V_1 * V_2 ,
struct V_234 * V_235 ,
struct V_659 * V_660 ,
bool V_670 )
{
struct V_92 * V_254 = F_81 ( V_235 ) ;
struct V_234 * V_675 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_184 ( V_2 , V_254 , & V_254 -> V_258 ) ;
switch ( V_235 -> type ) {
case V_101 :
goto V_34;
case V_671 :
V_254 -> V_672 = false ;
V_254 -> V_366 = false ;
break;
case V_98 :
if ( ! V_670 || ! V_254 -> V_518 )
goto V_34;
V_254 -> V_676 = false ;
F_271 ( V_2 , V_254 , true ) ;
F_219 ( V_2 -> V_522 , V_235 ) ;
V_254 -> V_518 = false ;
break;
case V_96 :
if ( ! V_670 )
break;
V_675 = V_235 ;
F_176 ( V_2 , V_235 , true , NULL ) ;
break;
default:
break;
}
F_115 ( V_2 , false , V_675 ) ;
F_146 ( V_2 , V_235 ) ;
V_34:
V_254 -> V_259 = NULL ;
F_141 ( V_2 ) ;
}
static void F_272 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_659 * V_660 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_73 ( & V_2 -> V_33 ) ;
F_270 ( V_2 , V_235 , V_660 , false ) ;
F_79 ( & V_2 -> V_33 ) ;
}
static int
F_273 ( struct V_1 * V_2 ,
struct V_677 * V_678 )
{
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
F_270 ( V_2 , V_678 [ 0 ] . V_235 , V_678 [ 0 ] . V_679 , true ) ;
F_265 ( V_2 , V_678 [ 0 ] . V_679 ) ;
V_47 = F_263 ( V_2 , V_678 [ 0 ] . V_680 ) ;
if ( V_47 ) {
F_116 ( V_2 , L_57 ) ;
goto V_681;
}
V_47 = F_268 ( V_2 , V_678 [ 0 ] . V_235 , V_678 [ 0 ] . V_680 ,
true ) ;
if ( V_47 ) {
F_116 ( V_2 ,
L_58 ) ;
goto V_517;
}
if ( F_190 ( V_2 ) > 1 )
F_117 ( V_2 ) ;
goto V_34;
V_517:
F_265 ( V_2 , V_678 [ 0 ] . V_680 ) ;
V_681:
if ( F_263 ( V_2 , V_678 [ 0 ] . V_679 ) ) {
F_116 ( V_2 , L_59 ) ;
goto V_682;
}
if ( F_268 ( V_2 , V_678 [ 0 ] . V_235 , V_678 [ 0 ] . V_679 ,
true ) ) {
F_116 ( V_2 , L_60 ) ;
goto V_682;
}
goto V_34;
V_682:
F_274 ( V_2 , false ) ;
V_34:
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_275 ( struct V_1 * V_2 ,
struct V_677 * V_678 )
{
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
F_270 ( V_2 , V_678 [ 0 ] . V_235 , V_678 [ 0 ] . V_679 , true ) ;
V_47 = F_268 ( V_2 , V_678 [ 0 ] . V_235 , V_678 [ 0 ] . V_680 ,
true ) ;
if ( V_47 ) {
F_116 ( V_2 ,
L_58 ) ;
goto V_681;
}
goto V_34;
V_681:
if ( F_268 ( V_2 , V_678 [ 0 ] . V_235 , V_678 [ 0 ] . V_679 ,
true ) ) {
F_116 ( V_2 , L_60 ) ;
goto V_682;
}
goto V_34;
V_682:
F_274 ( V_2 , false ) ;
V_34:
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_276 ( struct V_29 * V_30 ,
struct V_677 * V_678 ,
int V_683 ,
enum V_684 V_685 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_683 > 1 )
return - V_598 ;
switch ( V_685 ) {
case V_686 :
V_47 = F_273 ( V_2 , V_678 ) ;
break;
case V_687 :
V_47 = F_275 ( V_2 , V_678 ) ;
break;
default:
V_47 = - V_598 ;
break;
}
return V_47 ;
}
static int F_277 ( struct V_29 * V_30 ,
struct V_204 * V_205 ,
bool V_688 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_90 * V_562 = F_53 ( V_205 ) ;
if ( ! V_562 || ! V_562 -> V_235 ) {
F_116 ( V_2 , L_61 ) ;
return - V_251 ;
}
return F_188 ( V_2 , V_562 -> V_235 ) ;
}
static int F_278 ( struct V_1 * V_2 ,
struct V_234 * V_235 ,
void * V_222 , int V_177 )
{
struct V_689 * V_690 [ V_691 + 1 ] ;
int V_692 ;
T_5 V_436 ;
V_692 = F_279 ( V_690 , V_691 , V_222 , V_177 , V_693 ) ;
if ( V_692 )
return V_692 ;
if ( ! V_690 [ V_694 ] )
return - V_251 ;
switch ( F_280 ( V_690 [ V_694 ] ) ) {
case V_695 :
if ( ! V_235 || V_235 -> type != V_98 || ! V_235 -> V_425 ||
! V_235 -> V_443 . V_696 ||
! V_690 [ V_697 ] )
return - V_251 ;
V_436 = F_280 ( V_690 [ V_697 ] ) ;
if ( V_436 >= V_235 -> V_443 . V_499 )
return - V_251 ;
V_2 -> V_436 = V_436 ;
V_2 -> V_435 = V_235 ;
return F_115 ( V_2 , false , NULL ) ;
case V_698 :
if ( ! V_235 || V_235 -> type != V_96 ||
! V_235 -> V_443 . V_444 || ! V_235 -> V_443 . V_699 ||
! V_690 [ V_700 ] )
return - V_251 ;
if ( F_280 ( V_690 [ V_700 ] ) )
return F_185 ( V_2 , V_235 , 0 ) ;
return F_142 ( V_2 , V_235 , 0 ) ;
}
return - V_598 ;
}
static int F_281 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
void * V_222 , int V_177 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_692 ;
F_73 ( & V_2 -> V_33 ) ;
V_692 = F_278 ( V_2 , V_235 , V_222 , V_177 ) ;
F_79 ( & V_2 -> V_33 ) ;
return V_692 ;
}
static void F_282 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_701 * V_702 )
{
F_166 ( F_19 ( V_30 ) ,
L_62 ) ;
}
static int F_283 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_701 * V_702 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_234 * V_521 ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
T_5 V_648 ;
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
V_254 -> V_703 = false ;
F_166 ( V_2 , L_63 ,
V_702 -> V_655 . V_704 ) ;
F_284 ( V_2 , V_235 , V_705 ) ;
switch ( V_235 -> type ) {
case V_98 :
V_521 =
F_285 ( V_2 -> V_521 ,
F_286 ( & V_2 -> V_33 ) ) ;
if ( F_122 ( V_521 && V_521 -> V_706 ,
L_64 ) ) {
V_47 = - V_542 ;
goto V_421;
}
F_219 ( V_2 -> V_521 , V_235 ) ;
if ( F_122 ( V_254 -> V_676 ,
L_65 ) ) {
V_47 = - V_542 ;
goto V_421;
}
break;
case V_96 :
V_648 = V_702 -> V_707 +
( ( V_235 -> V_443 . V_499 * ( V_702 -> V_263 - 1 ) -
V_708 ) * 1024 ) ;
if ( V_702 -> V_709 )
F_287 ( V_2 , V_235 ) ;
F_288 ( V_2 , V_235 , V_235 -> V_443 . V_499 ,
V_648 ) ;
if ( V_254 -> V_260 . V_514 ) {
V_47 = F_142 ( V_2 , V_235 , 0 ) ;
if ( V_47 )
goto V_421;
}
break;
default:
break;
}
V_254 -> V_366 = true ;
V_47 = F_289 ( V_2 ) ;
if ( V_47 )
goto V_421;
F_117 ( V_2 ) ;
V_421:
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_290 ( struct V_29 * V_30 ,
struct V_234 * V_235 )
{
struct V_92 * V_254 = F_81 ( V_235 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_73 ( & V_2 -> V_33 ) ;
if ( V_254 -> V_703 ) {
V_254 -> V_703 = false ;
V_47 = - V_17 ;
goto V_421;
}
if ( V_235 -> type == V_96 ) {
struct V_90 * V_208 ;
V_208 = F_291 ( V_2 ,
V_254 -> V_256 ) ;
if ( F_8 ( ! V_208 ) ) {
V_47 = - V_17 ;
goto V_421;
}
F_292 ( V_2 , V_208 , false ) ;
F_176 ( V_2 , V_235 , false , NULL ) ;
V_47 = F_185 ( V_2 , V_235 , 0 ) ;
if ( V_47 )
goto V_421;
F_293 ( V_2 , V_235 ) ;
}
V_254 -> V_366 = false ;
V_47 = F_289 ( V_2 ) ;
V_421:
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_294 ( struct V_29 * V_30 ,
struct V_234 * V_235 , T_5 V_64 , bool V_223 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 ;
struct V_90 * V_208 ;
struct V_204 * V_205 ;
int V_9 ;
T_5 V_710 = 0 ;
if ( ! V_235 || V_235 -> type != V_96 )
return;
F_73 ( & V_2 -> V_33 ) ;
V_254 = F_81 ( V_235 ) ;
for ( V_9 = 0 ; V_9 < V_212 ; V_9 ++ ) {
V_205 = F_285 ( V_2 -> V_563 [ V_9 ] ,
F_286 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_205 ) )
continue;
V_208 = F_53 ( V_205 ) ;
if ( V_208 -> V_235 != V_235 )
continue;
F_8 ( V_9 != V_254 -> V_256 && ! V_205 -> V_572 ) ;
V_710 |= V_208 -> V_711 ;
}
if ( V_223 ) {
if ( F_152 ( V_2 , V_710 , true ) )
F_116 ( V_2 , L_66 ) ;
F_79 ( & V_2 -> V_33 ) ;
} else {
F_79 ( & V_2 -> V_33 ) ;
F_153 ( V_2 -> V_7 , V_710 ) ;
}
}
static int F_295 ( struct V_29 * V_30 , int V_712 ,
struct V_713 * V_714 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_714 , 0 , sizeof( * V_714 ) ) ;
if ( V_712 != 0 )
return - V_49 ;
if ( ! ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_715 ) )
return - V_49 ;
F_73 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_400 ) {
V_47 = F_177 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_714 -> V_716 = V_717 |
V_718 |
V_719 |
V_720 ;
V_714 -> time = V_2 -> V_395 . V_721 +
V_2 -> V_722 . V_721 ;
F_296 ( V_714 -> time , V_723 ) ;
V_714 -> V_724 = V_2 -> V_395 . V_725 +
V_2 -> V_722 . V_725 ;
F_296 ( V_714 -> V_724 , V_723 ) ;
V_714 -> V_726 = V_2 -> V_395 . V_727 +
V_2 -> V_722 . V_727 ;
F_296 ( V_714 -> V_726 , V_723 ) ;
V_714 -> V_728 = V_2 -> V_395 . V_729 +
V_2 -> V_722 . V_729 ;
F_296 ( V_714 -> V_728 , V_723 ) ;
V_47 = 0 ;
V_34:
F_79 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_297 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
struct V_204 * V_205 ,
struct V_730 * V_731 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_92 * V_254 = F_81 ( V_235 ) ;
struct V_90 * V_208 = F_53 ( V_205 ) ;
if ( ! ( V_2 -> V_79 -> V_80 . V_132 [ 0 ] &
V_715 ) )
return;
if ( ! ( V_235 -> V_426 & V_427 ) )
return;
if ( ! V_235 -> V_443 . V_444 )
return;
F_73 ( & V_2 -> V_33 ) ;
if ( V_254 -> V_256 != V_208 -> V_211 )
goto V_732;
if ( F_177 ( V_2 , false ) )
goto V_732;
V_731 -> V_733 = V_254 -> V_418 . V_420 +
V_254 -> V_418 . V_419 ;
V_731 -> V_716 |= F_38 ( V_734 ) ;
if ( V_254 -> V_418 . V_735 ) {
V_731 -> V_736 = V_254 -> V_418 . V_735 ;
V_731 -> V_716 |= F_38 ( V_737 ) ;
}
V_732:
F_79 ( & V_2 -> V_33 ) ;
}
static void F_298 ( struct V_29 * V_30 ,
struct V_234 * V_235 ,
const struct V_738 * V_739 )
{
#define F_299 ( T_9 , T_10 , T_11 , T_12 , T_13 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_740 * V_741 ;
struct V_742 * V_743 ;
if ( ! F_300 ( V_2 -> V_79 , V_744 ) )
return;
V_741 = F_301 ( V_2 -> V_79 , V_744 ) ;
V_743 = ( void * ) V_741 -> V_222 ;
if ( ! F_302 ( V_2 , V_235 , V_741 ) )
return;
if ( V_739 -> V_745 . V_746 . V_222 == V_747 ) {
if ( V_739 -> V_745 . V_746 . V_15 == V_748 )
F_299 ( V_2 , V_741 , V_749 ,
V_743 -> V_750 ,
L_67 ,
V_739 -> V_745 . V_746 . V_547 ) ;
else if ( V_739 -> V_745 . V_746 . V_15 == V_751 )
F_299 ( V_2 , V_741 , V_749 ,
V_743 -> V_752 ,
L_68 ) ;
} else if ( V_739 -> V_745 . V_746 . V_222 == V_753 ) {
if ( V_739 -> V_745 . V_746 . V_15 == V_748 )
F_299 ( V_2 , V_741 , V_749 ,
V_743 -> V_754 ,
L_69 ,
V_739 -> V_745 . V_746 . V_547 ) ;
else if ( V_739 -> V_745 . V_746 . V_15 == V_751 )
F_299 ( V_2 , V_741 , V_749 ,
V_743 -> V_755 ,
L_70 ) ;
} else if ( V_739 -> V_745 . V_746 . V_222 == V_756 ) {
F_299 ( V_2 , V_741 , V_749 ,
V_743 -> V_757 ,
L_71 , V_739 -> V_745 . V_746 . V_547 ) ;
} else if ( V_739 -> V_745 . V_746 . V_222 == V_758 ) {
F_299 ( V_2 , V_741 , V_749 ,
V_743 -> V_759 ,
L_72 , V_739 -> V_745 . V_746 . V_547 ) ;
}
#undef F_299
}
