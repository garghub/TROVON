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
int F_11 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( ! F_12 ( V_2 -> V_12 ,
! F_13 ( V_13 , & V_2 -> V_14 ) ,
V_15 ) ) {
F_14 ( 1 ) ;
F_7 ( V_2 , V_4 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_9 ;
memset ( V_2 -> V_17 , 0 , sizeof( V_2 -> V_17 ) ) ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
V_2 -> V_17 [ V_9 ] . V_19 = V_9 ;
V_2 -> V_17 [ V_9 ] . V_20 = 0 ;
}
}
int F_16 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_23 , V_24 , V_9 ;
V_22 -> V_25 = V_26 |
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 |
V_37 ;
V_22 -> V_38 = V_2 -> V_39 ;
V_22 -> V_40 = V_41 ;
V_22 -> V_42 |= V_43 |
V_44 ;
V_22 -> V_45 |= V_46 ;
V_22 -> V_47 = L_4 ;
if ( V_2 -> V_48 -> V_49 . V_25 & V_50 &&
! V_51 . V_52 )
V_22 -> V_25 |= V_53 ;
if ( V_2 -> V_48 -> V_49 . V_25 & V_54 &&
F_17 ( V_2 -> V_48 -> V_55 ) >= 9 &&
! V_51 . V_56 ) {
V_22 -> V_25 |= V_57 ;
V_22 -> V_58 = V_59 ;
V_22 -> V_60 = V_61 ;
}
if ( V_2 -> V_48 -> V_49 . V_62 [ 0 ] & V_63 )
V_22 -> V_25 |= V_64 ;
V_22 -> V_65 = sizeof( struct V_66 ) ;
V_22 -> V_67 = sizeof( struct V_68 ) ;
V_22 -> V_69 = sizeof( V_70 ) ;
V_22 -> V_71 -> V_72 = F_18 ( V_73 ) |
F_18 ( V_74 ) |
F_18 ( V_75 ) |
F_18 ( V_76 ) |
F_18 ( V_77 ) |
F_18 ( V_78 ) ;
V_22 -> V_71 -> V_25 |= V_79 ;
V_22 -> V_71 -> V_80 |= V_81 |
V_82 ;
if ( V_2 -> V_48 -> V_49 . V_25 & V_83 )
V_22 -> V_71 -> V_25 |= V_84 ;
if ( V_2 -> V_48 -> V_49 . V_62 [ 0 ] & V_85 )
V_22 -> V_71 -> V_25 |= V_86 ;
V_22 -> V_71 -> V_87 = V_88 ;
V_22 -> V_71 -> V_89 =
F_19 ( V_88 ) ;
V_22 -> V_71 -> V_90 = 10000 ;
V_22 -> V_91 = V_92 ;
memcpy ( V_2 -> V_93 [ 0 ] . V_94 , V_2 -> V_95 -> V_96 , V_97 ) ;
V_22 -> V_71 -> V_93 = V_2 -> V_93 ;
V_22 -> V_71 -> V_98 = 1 ;
V_23 = ( V_2 -> V_95 -> V_99 > 1 ) ?
F_20 ( V_100 , V_2 -> V_95 -> V_99 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_23 ; V_9 ++ ) {
memcpy ( V_2 -> V_93 [ V_9 ] . V_94 , V_2 -> V_93 [ V_9 - 1 ] . V_94 ,
V_97 ) ;
V_2 -> V_93 [ V_9 ] . V_94 [ 5 ] ++ ;
V_22 -> V_71 -> V_98 ++ ;
}
F_15 ( V_2 ) ;
V_22 -> V_71 -> V_101 = F_21 ( V_2 , false ) ;
V_22 -> V_71 -> V_102 = V_103 ;
if ( V_2 -> V_95 -> V_104 [ V_105 ] . V_106 )
V_22 -> V_71 -> V_104 [ V_105 ] =
& V_2 -> V_95 -> V_104 [ V_105 ] ;
if ( V_2 -> V_95 -> V_104 [ V_107 ] . V_106 )
V_22 -> V_71 -> V_104 [ V_107 ] =
& V_2 -> V_95 -> V_104 [ V_107 ] ;
V_22 -> V_71 -> V_108 = V_2 -> V_7 -> V_109 ;
if ( V_110 . V_111 != V_112 )
V_22 -> V_71 -> V_25 |= V_113 ;
else
V_22 -> V_71 -> V_25 &= ~ V_113 ;
if ( F_17 ( V_2 -> V_48 -> V_55 ) >= 10 ) {
V_22 -> V_71 -> V_25 |= V_114 ;
V_22 -> V_71 -> V_115 = V_103 ;
V_22 -> V_71 -> V_116 = V_117 ;
V_22 -> V_71 -> V_118 =
V_119 - 24 - 2 ;
}
V_22 -> V_71 -> V_120 |= V_121 |
V_122 |
V_123 |
V_124 |
V_125 ;
if ( V_2 -> V_48 -> V_49 . V_126 [ 0 ] &
V_127 )
V_22 -> V_71 -> V_120 |= V_128 ;
if ( V_2 -> V_48 -> V_49 . V_126 [ 0 ] &
V_129 )
V_22 -> V_71 -> V_120 |= V_130 ;
if ( V_2 -> V_48 -> V_49 . V_126 [ 0 ] &
V_131 )
V_22 -> V_71 -> V_120 |=
V_132 ;
if ( V_2 -> V_48 -> V_49 . V_126 [ 0 ] &
V_133 )
V_22 -> V_71 -> V_120 |= V_134 ;
V_2 -> V_135 = V_136 ;
if ( V_2 -> V_48 -> V_137 [ 0 ] . V_138 ) {
V_2 -> V_22 -> V_139 = 1 ;
V_2 -> V_22 -> V_140 = & V_2 -> V_48 -> V_137 [ 0 ] ;
}
#ifdef F_22
if ( F_2 ( V_2 ) &&
F_23 ( V_2 -> V_7 -> V_141 ) ) {
V_2 -> V_142 . V_25 = V_143 ;
V_22 -> V_71 -> V_142 = & V_2 -> V_142 ;
} else if ( V_2 -> V_48 -> V_144 [ V_145 ] . V_146 [ 0 ] . V_147 &&
V_2 -> V_7 -> V_148 -> V_149 &&
V_2 -> V_7 -> V_148 -> V_150 &&
F_23 ( V_2 -> V_7 -> V_141 ) ) {
V_2 -> V_142 . V_25 = V_151 |
V_152 |
V_153 |
V_154 ;
if ( ! V_51 . V_52 )
V_2 -> V_142 . V_25 |= V_155 |
V_156 |
V_157 ;
V_2 -> V_142 . V_158 = V_159 ;
V_2 -> V_142 . V_160 = V_161 ;
V_2 -> V_142 . V_162 = V_163 ;
V_2 -> V_142 . V_164 = & V_165 ;
V_22 -> V_71 -> V_142 = & V_2 -> V_142 ;
}
#endif
#ifdef F_24
V_2 -> V_166 = V_167 ;
#endif
V_24 = F_25 ( V_2 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_26 ( V_2 -> V_22 ) ;
if ( V_24 )
F_27 ( V_2 ) ;
return V_24 ;
}
static bool F_28 ( struct V_1 * V_2 ,
struct V_168 * V_169 ,
struct V_170 * V_171 )
{
struct V_66 * V_172 ;
bool V_173 = false ;
if ( F_29 ( ! F_13 ( V_13 , & V_2 -> V_14 ) ) )
return false ;
F_30 ( & V_2 -> V_174 ) ;
if ( ! F_13 ( V_13 , & V_2 -> V_14 ) )
goto V_175;
V_172 = F_31 ( V_169 ) ;
if ( V_172 -> V_176 == V_177 ||
V_172 -> V_176 != V_2 -> V_178 )
goto V_175;
F_32 ( & V_2 -> V_179 , V_171 ) ;
F_33 ( V_2 -> V_22 ) ;
F_1 ( V_2 , V_180 ) ;
F_7 ( V_2 , V_180 ) ;
V_173 = true ;
V_175:
F_34 ( & V_2 -> V_174 ) ;
return V_173 ;
}
static void F_35 ( struct V_21 * V_22 ,
struct V_181 * V_182 ,
struct V_170 * V_171 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_168 * V_169 = V_182 -> V_169 ;
struct V_183 * V_184 = F_37 ( V_171 ) ;
struct V_185 * V_186 = ( void * ) V_171 -> V_187 ;
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 , L_5 ) ;
goto V_188;
}
if ( F_37 ( V_171 ) -> V_189 == V_41 &&
! F_13 ( V_190 , & V_2 -> V_14 ) &&
! F_13 ( V_191 , & V_2 -> V_14 ) )
goto V_188;
if ( F_40 ( V_184 -> V_25 & V_192 &&
F_41 ( V_186 -> V_193 ) &&
! F_42 ( V_186 -> V_193 ) &&
! F_43 ( V_186 -> V_193 ) &&
! F_44 ( V_186 -> V_193 ) ) )
V_169 = NULL ;
if ( V_169 ) {
if ( F_28 ( V_2 , V_169 , V_171 ) )
return;
if ( F_45 ( V_2 , V_171 , V_169 ) )
goto V_188;
return;
}
if ( F_46 ( V_2 , V_171 ) )
goto V_188;
return;
V_188:
F_47 ( V_22 , V_171 ) ;
}
static inline bool F_48 ( const struct V_194 * V_195 )
{
if ( V_51 . V_196 & V_197 )
return false ;
return true ;
}
static inline bool F_49 ( const struct V_194 * V_195 )
{
if ( V_51 . V_196 & V_198 )
return false ;
if ( V_51 . V_196 & V_199 )
return true ;
return true ;
}
static int F_50 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
enum V_202 V_203 ,
struct V_168 * V_169 , V_70 V_204 ,
V_70 * V_205 , T_1 V_206 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
bool V_207 = false ;
F_51 ( V_2 , L_6 ,
V_169 -> V_94 , V_204 , V_203 ) ;
if ( ! ( V_2 -> V_95 -> V_208 ) )
return - V_209 ;
switch ( V_203 ) {
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
V_24 = F_11 ( V_2 , V_215 ) ;
if ( V_24 )
return V_24 ;
V_207 = true ;
break;
default:
break;
}
F_52 ( & V_2 -> V_216 ) ;
switch ( V_203 ) {
case V_217 :
if ( ! F_48 ( V_2 -> V_195 ) ) {
V_24 = - V_218 ;
break;
}
V_24 = F_53 ( V_2 , V_169 , V_204 , * V_205 , true ) ;
break;
case V_219 :
V_24 = F_53 ( V_2 , V_169 , V_204 , 0 , false ) ;
break;
case V_210 :
if ( ! F_49 ( V_2 -> V_195 ) ) {
V_24 = - V_218 ;
break;
}
V_24 = F_54 ( V_2 , V_201 , V_169 , V_204 , V_205 ) ;
break;
case V_211 :
V_24 = F_55 ( V_2 , V_201 , V_169 , V_204 ) ;
break;
case V_212 :
case V_213 :
V_24 = F_56 ( V_2 , V_201 , V_169 , V_204 ) ;
break;
case V_214 :
V_24 = F_57 ( V_2 , V_201 , V_169 , V_204 , V_206 ) ;
break;
default:
F_14 ( 1 ) ;
V_24 = - V_218 ;
break;
}
F_58 ( & V_2 -> V_216 ) ;
if ( V_207 )
F_7 ( V_2 , V_215 ) ;
return V_24 ;
}
static void F_59 ( void * V_187 , T_1 * V_220 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = V_187 ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
V_221 -> V_222 = false ;
V_221 -> V_223 = V_177 ;
V_221 -> V_224 ++ ;
F_4 ( & V_2 -> V_225 ) ;
F_61 ( V_2 , & V_221 -> V_226 ) ;
F_5 ( & V_2 -> V_225 ) ;
V_221 -> V_227 = NULL ;
memset ( & V_221 -> V_228 , 0 , sizeof( V_221 -> V_228 ) ) ;
}
void F_62 ( struct V_1 * V_2 )
{
static char * V_229 [] = { L_7 , L_8 , NULL } ;
struct V_230 * V_231 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
struct V_236 * V_237 ;
const struct V_238 * V_144 ;
T_2 V_239 , V_240 ;
T_2 V_241 , V_242 ;
unsigned long V_25 ;
int V_243 ;
F_63 ( & V_2 -> V_216 ) ;
if ( V_2 -> V_237 )
return;
V_237 = F_64 ( sizeof( * V_2 -> V_237 ) , V_244 ) ;
if ( ! V_237 )
return;
V_144 = & V_2 -> V_48 -> V_144 [ V_2 -> V_245 ] ;
V_240 = V_144 -> V_146 [ V_246 ] . V_247 ;
V_239 = V_144 -> V_146 [ V_246 ] . V_147 ;
V_243 = F_65 ( V_2 -> V_7 , V_248 ) ;
V_242 = ( V_243 & V_249 ) >> V_250 ;
V_242 = V_242 << 7 ;
V_241 = sizeof( * V_231 ) +
sizeof( * V_233 ) * 3 +
V_239 +
V_242 +
sizeof( * V_235 ) ;
V_231 = F_66 ( V_241 ) ;
if ( ! V_231 ) {
F_67 ( V_237 ) ;
return;
}
V_237 -> V_251 = V_231 ;
V_231 -> V_252 = F_68 ( V_253 ) ;
V_233 = ( void * ) V_231 -> V_187 ;
V_233 -> type = F_68 ( V_254 ) ;
V_233 -> V_147 = F_68 ( sizeof( * V_235 ) ) ;
V_235 = ( void * ) V_233 -> V_187 ;
V_235 -> V_255 =
V_2 -> V_195 -> V_255 == V_256 ?
F_68 ( V_257 ) :
F_68 ( V_258 ) ;
memcpy ( V_235 -> V_259 , V_2 -> V_48 -> V_260 ,
sizeof( V_235 -> V_259 ) ) ;
strncpy ( V_235 -> V_261 , V_2 -> V_195 -> V_262 ,
sizeof( V_235 -> V_261 ) ) ;
strncpy ( V_235 -> V_263 , V_2 -> V_141 -> V_264 -> V_262 ,
sizeof( V_235 -> V_263 ) ) ;
V_233 = F_69 ( V_233 ) ;
V_233 -> type = F_68 ( V_265 ) ;
V_233 -> V_147 = F_68 ( V_242 ) ;
if ( F_70 ( V_2 -> V_7 , false , & V_25 ) ) {
T_2 * V_266 = ( void * ) V_233 -> V_187 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < ( V_242 / sizeof( T_2 ) ) ; V_9 ++ ) {
F_71 ( V_2 -> V_7 ,
V_267 ,
V_9 * sizeof( T_2 ) ) ;
V_266 [ V_9 ] = F_65 ( V_2 -> V_7 ,
V_268 ) ;
}
F_72 ( V_2 -> V_7 , & V_25 ) ;
}
V_233 = F_69 ( V_233 ) ;
V_233 -> type = F_68 ( V_269 ) ;
V_233 -> V_147 = F_68 ( V_239 ) ;
F_73 ( V_2 -> V_7 , V_240 , V_233 -> V_187 ,
V_239 ) ;
V_237 -> V_270 = F_74 ( V_2 -> V_7 ) ;
V_237 -> V_271 = V_241 ;
if ( V_237 -> V_270 )
V_241 += V_237 -> V_270 -> V_147 ;
V_231 -> V_241 = F_68 ( V_241 ) ;
V_2 -> V_237 = V_237 ;
F_75 ( & V_2 -> V_22 -> V_71 -> V_141 . V_272 , V_273 , V_229 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_62 ( V_2 ) ;
F_77 ( V_2 -> V_7 ) ;
V_2 -> V_274 = V_275 ;
V_2 -> V_276 = false ;
V_2 -> V_277 = false ;
F_78 ( V_2 -> V_22 ) ;
F_79 (
V_2 -> V_22 , V_278 ,
F_59 , V_2 ) ;
V_2 -> V_279 = NULL ;
V_2 -> V_178 = V_177 ;
F_15 ( V_2 ) ;
memset ( V_2 -> V_280 , 0 , sizeof( V_2 -> V_280 ) ) ;
memset ( V_2 -> V_281 , 0 , sizeof( V_2 -> V_281 ) ) ;
memset ( & V_2 -> V_282 , 0 , sizeof( V_2 -> V_282 ) ) ;
memset ( & V_2 -> V_283 , 0 , sizeof( V_2 -> V_283 ) ) ;
memset ( & V_2 -> V_284 , 0 , sizeof( V_2 -> V_284 ) ) ;
memset ( & V_2 -> V_285 , 0 , sizeof( V_2 -> V_285 ) ) ;
memset ( & V_2 -> V_286 , 0 , sizeof( V_2 -> V_286 ) ) ;
memset ( & V_2 -> V_287 , 0 , sizeof( V_2 -> V_287 ) ) ;
F_80 ( V_2 -> V_22 ) ;
F_10 ( V_2 , V_288 ) ;
F_81 ( V_13 , & V_2 -> V_14 ) ;
V_2 -> V_289 = 0 ;
V_2 -> V_290 = 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_24 ;
F_63 ( & V_2 -> V_216 ) ;
if ( F_13 ( V_291 , & V_2 -> V_14 ) )
F_76 ( V_2 ) ;
V_24 = F_83 ( V_2 ) ;
if ( V_24 && F_13 ( V_291 , & V_2 -> V_14 ) ) {
F_81 ( V_291 , & V_2 -> V_14 ) ;
F_84 ( V_2 , NULL ) ;
}
return V_24 ;
}
static int F_85 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
F_52 ( & V_2 -> V_216 ) ;
V_24 = F_82 ( V_2 ) ;
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
static void F_86 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
F_52 ( & V_2 -> V_216 ) ;
F_81 ( V_291 , & V_2 -> V_14 ) ;
F_84 ( V_2 , NULL ) ;
V_24 = F_87 ( V_2 , NULL ) ;
if ( V_24 )
F_88 ( V_2 , L_9 ,
V_24 ) ;
F_7 ( V_2 , V_288 ) ;
F_58 ( & V_2 -> V_216 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
F_63 ( & V_2 -> V_216 ) ;
F_1 ( V_2 , V_288 ) ;
F_90 ( & V_2 -> V_292 ) ;
F_77 ( V_2 -> V_7 ) ;
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
V_2 -> V_293 = false ;
}
static void F_93 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_94 ( & V_2 -> V_294 ) ;
F_94 ( & V_2 -> V_295 ) ;
F_94 ( & V_2 -> V_296 ) ;
F_52 ( & V_2 -> V_216 ) ;
F_89 ( V_2 ) ;
F_58 ( & V_2 -> V_216 ) ;
F_90 ( & V_2 -> V_295 ) ;
}
static struct V_297 * F_95 ( struct V_1 * V_2 )
{
V_70 V_9 ;
F_63 ( & V_2 -> V_216 ) ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ )
if ( ! V_2 -> V_17 [ V_9 ] . V_20 )
return & V_2 -> V_17 [ V_9 ] ;
F_88 ( V_2 , L_10 ) ;
return NULL ;
}
static int F_96 ( struct V_1 * V_2 , struct V_200 * V_201 ,
T_3 V_298 )
{
struct V_299 V_300 = {
. V_301 = F_60 ( V_201 ) -> V_19 ,
. V_302 = F_97 ( V_298 ) ,
} ;
return F_98 ( V_2 , V_303 , 0 ,
sizeof( V_300 ) ,
& V_300 ) ;
}
static int F_99 ( struct V_21 * V_22 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
int V_24 ;
V_24 = F_11 ( V_2 , V_304 ) ;
if ( V_24 )
return V_24 ;
F_52 ( & V_2 -> V_216 ) ;
V_24 = F_100 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_305;
if ( V_201 -> type != V_77 )
V_2 -> V_289 ++ ;
if ( V_201 -> type == V_75 ||
V_201 -> type == V_78 ) {
V_24 = F_101 ( V_2 , V_201 ) ;
if ( V_24 ) {
F_88 ( V_2 , L_11 ) ;
goto V_306;
}
F_102 ( V_2 , V_201 ) ;
goto V_305;
}
V_24 = F_103 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_306;
V_24 = F_104 ( V_2 ) ;
if ( V_24 )
goto V_306;
V_24 = F_105 ( V_2 , V_201 , 0 ) ;
if ( V_24 )
goto V_307;
if ( ! V_2 -> V_308 &&
V_201 -> type == V_73 && ! V_201 -> V_309 ) {
V_2 -> V_308 = V_221 ;
V_201 -> V_310 |= V_311 |
V_312 ;
}
if ( V_201 -> type == V_77 ) {
V_221 -> V_227 = F_95 ( V_2 ) ;
if ( ! V_221 -> V_227 ) {
V_24 = - V_313 ;
goto V_314;
}
F_106 ( V_2 , V_221 -> V_227 ) ;
V_24 = F_107 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_315;
V_24 = F_108 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_316;
V_2 -> V_279 = V_201 ;
}
F_102 ( V_2 , V_201 ) ;
goto V_305;
V_316:
F_109 ( V_2 , V_201 ) ;
V_315:
F_110 ( V_2 , V_221 -> V_227 ) ;
V_314:
if ( V_2 -> V_308 == V_221 ) {
V_2 -> V_308 = NULL ;
V_201 -> V_310 &= ~ ( V_311 |
V_312 ) ;
}
V_307:
V_221 -> V_227 = NULL ;
F_111 ( V_2 , V_201 ) ;
V_306:
if ( V_201 -> type != V_77 )
V_2 -> V_289 -- ;
F_112 ( V_2 , V_201 ) ;
V_305:
F_58 ( & V_2 -> V_216 ) ;
F_7 ( V_2 , V_304 ) ;
return V_24 ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_200 * V_201 )
{
T_2 V_317 = F_114 ( V_2 , V_201 ) ;
if ( V_317 ) {
F_52 ( & V_2 -> V_216 ) ;
F_115 ( V_2 , V_317 , true ) ;
F_58 ( & V_2 -> V_216 ) ;
}
if ( V_201 -> type == V_77 ) {
F_94 ( & V_2 -> V_292 ) ;
} else {
F_94 ( & V_2 -> V_318 ) ;
}
}
static void F_116 ( struct V_21 * V_22 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
F_113 ( V_2 , V_201 ) ;
F_52 ( & V_2 -> V_216 ) ;
if ( V_2 -> V_308 == V_221 ) {
V_2 -> V_308 = NULL ;
V_201 -> V_310 &= ~ ( V_311 |
V_312 ) ;
}
F_117 ( V_2 , V_201 ) ;
if ( V_201 -> type == V_75 ||
V_201 -> type == V_78 ) {
#ifdef F_118
if ( V_201 == V_2 -> V_319 ) {
V_2 -> V_319 = NULL ;
V_2 -> V_320 = 0 ;
}
#endif
F_119 ( V_2 , V_201 ) ;
goto V_306;
}
if ( V_201 -> type == V_77 ) {
V_2 -> V_279 = NULL ;
F_120 ( V_2 , V_201 ) ;
F_109 ( V_2 , V_201 ) ;
F_110 ( V_2 , V_221 -> V_227 ) ;
V_221 -> V_227 = NULL ;
}
if ( V_2 -> V_289 && V_201 -> type != V_77 )
V_2 -> V_289 -- ;
F_104 ( V_2 ) ;
F_111 ( V_2 , V_201 ) ;
V_306:
F_112 ( V_2 , V_201 ) ;
F_58 ( & V_2 -> V_216 ) ;
}
static int F_121 ( struct V_21 * V_22 , T_2 V_321 )
{
return 0 ;
}
static void F_122 ( void * V_322 , T_1 * V_220 ,
struct V_200 * V_201 )
{
struct V_323 * V_187 = V_322 ;
struct V_1 * V_2 = V_187 -> V_2 ;
struct V_324 * V_325 = V_2 -> V_326 ;
int V_24 , V_147 ;
if ( F_14 ( V_187 -> V_327 >= V_328 ) )
return;
if ( V_201 -> type != V_73 ||
! V_201 -> V_329 . V_330 )
return;
V_325 -> V_327 = V_187 -> V_327 ++ ;
memcpy ( V_325 -> V_331 , V_201 -> V_329 . V_331 , V_97 ) ;
V_147 = F_123 ( sizeof( * V_325 ) + V_325 -> V_332 * V_97 , 4 ) ;
V_24 = F_98 ( V_2 , V_333 , V_334 , V_147 , V_325 ) ;
if ( V_24 )
F_88 ( V_2 , L_12 , V_24 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_323 V_335 = {
. V_2 = V_2 ,
} ;
F_63 ( & V_2 -> V_216 ) ;
if ( F_14 ( ! V_2 -> V_326 ) )
return;
F_79 (
V_2 -> V_22 , V_336 ,
F_122 , & V_335 ) ;
}
static T_4 F_125 ( struct V_21 * V_22 ,
struct V_337 * V_338 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_324 * V_325 ;
struct V_339 * V_94 ;
int V_340 ;
bool V_341 ;
int V_147 ;
V_340 = F_126 ( V_338 ) ;
V_341 = V_340 > V_342 ||
V_343 ;
if ( V_341 )
V_340 = 0 ;
V_147 = F_123 ( sizeof( * V_325 ) + V_340 * V_97 , 4 ) ;
V_325 = F_64 ( V_147 , V_344 ) ;
if ( ! V_325 )
return 0 ;
if ( V_341 ) {
V_325 -> V_341 = 1 ;
return ( T_4 ) ( unsigned long ) V_325 ;
}
F_127 (addr, mc_list) {
F_128 ( V_2 , L_13 ,
V_325 -> V_332 , V_94 -> V_94 ) ;
memcpy ( & V_325 -> V_345 [ V_325 -> V_332 * V_97 ] ,
V_94 -> V_94 , V_97 ) ;
V_325 -> V_332 ++ ;
}
return ( T_4 ) ( unsigned long ) V_325 ;
}
static void F_129 ( struct V_21 * V_22 ,
unsigned int V_346 ,
unsigned int * V_347 ,
T_4 V_348 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_324 * V_325 = ( void * ) ( unsigned long ) V_348 ;
F_52 ( & V_2 -> V_216 ) ;
F_67 ( V_2 -> V_326 ) ;
V_2 -> V_326 = V_325 ;
if ( ! V_325 )
goto V_175;
F_124 ( V_2 ) ;
V_175:
F_58 ( & V_2 -> V_216 ) ;
* V_347 = 0 ;
}
static void
F_130 ( struct V_200 * V_201 ,
const struct V_349 * V_350 ,
struct V_349 * V_351 )
{
struct V_352 * V_353 ;
int V_9 ;
memcpy ( V_351 , V_350 , sizeof( * V_351 ) ) ;
for ( V_9 = 0 ; V_9 < F_19 ( V_351 -> V_354 ) ; V_9 ++ ) {
V_353 = & V_351 -> V_354 [ V_9 ] ;
if ( ! V_353 -> V_355 )
break;
switch ( V_353 -> V_356 ) {
case F_97 ( V_357 ) :
if ( V_201 -> V_329 . V_358 != 1 ) {
V_353 -> V_355 = 0 ;
continue;
}
V_353 -> V_359 = V_201 -> V_329 . V_360 [ 0 ] ;
break;
case F_97 ( V_361 ) :
V_353 -> V_359 = * ( V_362 * ) & V_201 -> V_94 [ 2 ] ;
break;
default:
break;
}
V_353 -> V_356 = 0 ;
V_351 -> V_363 ++ ;
}
}
static void F_131 ( void * V_322 , T_1 * V_220 ,
struct V_200 * V_201 )
{
struct V_364 * V_187 = V_322 ;
struct V_1 * V_2 = V_187 -> V_2 ;
struct V_365 * V_325 = V_187 -> V_325 ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
struct V_366 * V_367 ;
int V_9 ;
if ( F_8 ( V_221 -> V_19 >= F_19 ( V_325 -> V_368 ) ) )
return;
V_367 = & V_325 -> V_368 [ V_221 -> V_19 ] ;
if ( V_201 -> type != V_73 || V_201 -> V_309 ||
! V_201 -> V_329 . V_330 )
return;
V_367 -> V_369 = 1 ;
for ( V_9 = 0 ; V_2 -> V_166 [ V_9 ] . V_354 [ 0 ] . V_355 ; V_9 ++ ) {
if ( F_14 ( V_187 -> V_370 >=
F_19 ( V_325 -> V_371 ) ) ) {
V_367 -> V_369 = 0 ;
V_367 -> V_372 = 0 ;
break;
}
F_130 ( V_201 ,
& V_2 -> V_166 [ V_9 ] ,
& V_325 -> V_371 [ V_187 -> V_370 ] ) ;
if ( ! V_325 -> V_371 [ V_187 -> V_370 ] . V_363 )
continue;
V_367 -> V_372 |=
F_97 ( F_18 ( V_187 -> V_370 ) ) ;
V_187 -> V_370 ++ ;
}
}
bool F_132 ( struct V_1 * V_2 ,
struct V_365 * V_325 )
{
struct V_364 V_335 = {
. V_2 = V_2 ,
. V_325 = V_325 ,
} ;
memset ( V_325 , 0 , sizeof( * V_325 ) ) ;
V_325 -> V_373 = F_19 ( V_325 -> V_371 ) ;
V_325 -> V_374 = F_19 ( V_325 -> V_368 ) ;
#ifdef F_133
if ( V_2 -> V_375 . V_376 ) {
memcpy ( V_325 -> V_371 , & V_2 -> V_375 . V_325 . V_371 ,
sizeof( V_325 -> V_371 ) ) ;
memcpy ( V_325 -> V_368 , & V_2 -> V_375 . V_325 . V_368 ,
sizeof( V_325 -> V_368 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_166 )
return false ;
F_134 (
V_2 -> V_22 , V_336 ,
F_131 , & V_335 ) ;
return true ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_365 V_325 ;
if ( ! ( V_2 -> V_48 -> V_49 . V_25 & V_377 ) )
return 0 ;
if ( ! F_132 ( V_2 , & V_325 ) )
return 0 ;
return F_98 ( V_2 , V_378 , 0 ,
sizeof( V_325 ) , & V_325 ) ;
}
static inline int F_135 ( struct V_1 * V_2 ,
struct V_200 * V_201 )
{
return 0 ;
}
static void F_136 ( struct V_1 * V_2 ,
struct V_200 * V_201 ,
struct V_379 * V_329 ,
T_2 V_380 )
{
struct V_68 * V_221 = F_60 ( V_201 ) ;
int V_24 ;
if ( V_380 & V_381 && V_329 -> V_330 )
F_137 ( V_2 , V_201 ) ;
if ( V_380 & V_382 && ! V_221 -> V_383 )
memcpy ( V_221 -> V_331 , V_329 -> V_331 , V_97 ) ;
V_24 = F_138 ( V_2 , V_201 , false , V_221 -> V_331 ) ;
if ( V_24 )
F_88 ( V_2 , L_14 , V_201 -> V_94 ) ;
memcpy ( V_221 -> V_331 , V_329 -> V_331 , V_97 ) ;
V_221 -> V_383 = V_329 -> V_330 ;
if ( V_380 & V_381 ) {
if ( V_329 -> V_330 ) {
V_24 = F_87 ( V_2 , NULL ) ;
if ( V_24 ) {
F_88 ( V_2 , L_15 ) ;
return;
}
if ( F_13 ( V_291 ,
& V_2 -> V_14 ) ) {
T_2 V_384 = ( 11 * V_201 -> V_329 . V_385 ) / 10 ;
F_139 ( V_2 , V_201 , V_384 , V_384 ,
5 * V_384 , false ) ;
}
F_140 ( V_2 , V_201 , false ) ;
F_141 ( V_2 , V_201 ) ;
if ( V_201 -> V_309 ) {
F_1 ( V_2 , V_386 ) ;
F_142 ( V_2 , V_201 ,
V_387 ,
V_388 ) ;
}
} else if ( V_221 -> V_223 != V_177 ) {
F_143 ( F_140 ( V_2 , V_201 , false ) ,
L_16 ) ;
V_24 = F_144 ( V_2 , V_201 , V_221 -> V_223 ) ;
if ( V_24 )
F_88 ( V_2 , L_17 ) ;
if ( V_2 -> V_178 == V_221 -> V_223 )
V_2 -> V_178 = V_177 ;
V_221 -> V_223 = V_177 ;
V_24 = F_87 ( V_2 , NULL ) ;
if ( V_24 )
F_88 ( V_2 , L_15 ) ;
if ( V_201 -> V_309 )
F_7 ( V_2 , V_386 ) ;
V_24 = F_138 ( V_2 , V_201 , false , NULL ) ;
if ( V_24 )
F_88 ( V_2 ,
L_18 ,
V_201 -> V_94 ) ;
}
F_124 ( V_2 ) ;
F_135 ( V_2 , V_201 ) ;
V_221 -> V_228 . V_389 = 0 ;
F_145 ( V_2 ) ;
F_142 ( V_2 , V_201 , V_390 ,
V_391 ) ;
} else if ( V_380 & V_392 ) {
F_146 ( V_2 , V_221 ,
& V_221 -> V_226 ) ;
}
if ( V_380 & V_392 ) {
F_140 ( V_2 , V_201 , false ) ;
F_8 ( F_147 ( V_2 , V_201 , 0 ) ) ;
}
if ( V_380 & ( V_393 | V_394 | V_395 ) ) {
V_24 = F_104 ( V_2 ) ;
if ( V_24 )
F_88 ( V_2 , L_19 ) ;
}
if ( V_380 & V_396 ) {
F_148 ( V_2 , L_20 ,
V_329 -> V_397 ) ;
F_96 ( V_2 , V_201 , V_329 -> V_397 ) ;
}
if ( V_380 & V_398 ) {
F_128 ( V_2 , L_21 ) ;
V_221 -> V_228 . V_399 = 0 ;
if ( V_221 -> V_228 . V_400 ) {
V_24 = F_147 ( V_2 , V_201 , 0 ) ;
if ( V_24 )
F_88 ( V_2 ,
L_22 ) ;
}
}
if ( V_380 & V_401 ) {
F_128 ( V_2 , L_23 ) ;
F_135 ( V_2 , V_201 ) ;
}
}
static int F_149 ( struct V_21 * V_22 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
int V_24 ;
V_24 = F_11 ( V_2 , V_402 ) ;
if ( V_24 )
return V_24 ;
F_52 ( & V_2 -> V_216 ) ;
V_24 = F_150 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_305;
if ( V_201 -> type == V_75 )
F_137 ( V_2 , V_201 ) ;
V_24 = F_103 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_305;
V_24 = F_107 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_403;
V_24 = F_151 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_316;
V_221 -> V_404 = true ;
F_104 ( V_2 ) ;
V_24 = F_87 ( V_2 , NULL ) ;
if ( V_24 )
goto V_405;
if ( V_201 -> V_309 && V_2 -> V_279 )
F_138 ( V_2 , V_2 -> V_279 , false , NULL ) ;
F_1 ( V_2 , V_406 ) ;
F_145 ( V_2 ) ;
if ( F_152 ( V_2 ) > 1 )
F_153 ( V_2 ) ;
F_58 ( & V_2 -> V_216 ) ;
return 0 ;
V_405:
F_104 ( V_2 ) ;
V_221 -> V_404 = false ;
F_154 ( V_2 , V_201 ) ;
V_316:
F_109 ( V_2 , V_201 ) ;
V_403:
F_111 ( V_2 , V_201 ) ;
V_305:
F_58 ( & V_2 -> V_216 ) ;
F_7 ( V_2 , V_402 ) ;
return V_24 ;
}
static void F_155 ( struct V_21 * V_22 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
F_113 ( V_2 , V_201 ) ;
F_52 ( & V_2 -> V_216 ) ;
if ( F_156 ( V_2 -> V_407 ) == V_201 ) {
F_146 ( V_2 , V_221 ,
& V_221 -> V_226 ) ;
F_157 ( V_2 -> V_407 , NULL ) ;
}
if ( F_156 ( V_2 -> V_408 ) == V_201 ) {
F_157 ( V_2 -> V_408 , NULL ) ;
V_2 -> V_409 = 0 ;
}
V_221 -> V_404 = false ;
V_2 -> V_410 = 0 ;
F_145 ( V_2 ) ;
F_7 ( V_2 , V_406 ) ;
if ( V_201 -> V_309 && V_2 -> V_279 )
F_138 ( V_2 , V_2 -> V_279 , false , NULL ) ;
F_87 ( V_2 , NULL ) ;
F_154 ( V_2 , V_201 ) ;
F_109 ( V_2 , V_201 ) ;
F_104 ( V_2 ) ;
F_111 ( V_2 , V_201 ) ;
F_58 ( & V_2 -> V_216 ) ;
}
static void
F_158 ( struct V_1 * V_2 ,
struct V_200 * V_201 ,
struct V_379 * V_329 ,
T_2 V_380 )
{
struct V_68 * V_221 = F_60 ( V_201 ) ;
if ( ! V_221 -> V_404 )
return;
if ( V_380 & ( V_411 | V_412 |
V_413 | V_395 ) &&
F_138 ( V_2 , V_201 , false , NULL ) )
F_88 ( V_2 , L_14 , V_201 -> V_94 ) ;
if ( V_380 & V_414 &&
F_150 ( V_2 , V_201 ) )
F_159 ( V_2 , L_24 ) ;
if ( V_380 & V_396 ) {
F_148 ( V_2 , L_20 ,
V_329 -> V_397 ) ;
F_96 ( V_2 , V_201 , V_329 -> V_397 ) ;
}
}
static void F_160 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_379 * V_329 ,
T_2 V_380 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
if ( F_11 ( V_2 , V_415 ) )
return;
F_52 ( & V_2 -> V_216 ) ;
if ( V_380 & V_416 && ! V_329 -> V_417 )
F_161 ( V_2 , true ) ;
switch ( V_201 -> type ) {
case V_73 :
F_136 ( V_2 , V_201 , V_329 , V_380 ) ;
break;
case V_75 :
case V_78 :
F_158 ( V_2 , V_201 , V_329 , V_380 ) ;
break;
default:
F_14 ( 1 ) ;
}
F_58 ( & V_2 -> V_216 ) ;
F_7 ( V_2 , V_415 ) ;
}
static int F_162 ( struct V_1 * V_2 ,
enum V_418 V_419 )
{
int V_24 ;
bool V_420 = false ;
F_52 ( & V_2 -> V_216 ) ;
if ( V_2 -> V_274 != V_419 ) {
V_24 = 0 ;
V_420 = true ;
goto V_175;
}
switch ( V_419 ) {
case V_421 :
V_24 = F_161 ( V_2 , true ) ;
break;
case V_422 :
V_24 = F_163 ( V_2 ) ;
break;
case V_275 :
default:
F_14 ( 1 ) ;
V_24 = - V_218 ;
break;
}
if ( V_24 )
goto V_175;
V_420 = true ;
V_175:
F_58 ( & V_2 -> V_216 ) ;
if ( V_420 )
F_164 ( V_2 ) ;
return V_24 ;
}
static int F_165 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_423 * V_424 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_425 * V_426 = & V_424 -> V_426 ;
int V_24 ;
if ( V_426 -> V_106 == 0 ||
V_426 -> V_106 > V_2 -> V_48 -> V_49 . V_427 )
return - V_218 ;
V_24 = F_162 ( V_2 , V_421 ) ;
if ( V_24 )
return V_24 ;
F_52 ( & V_2 -> V_216 ) ;
if ( V_2 -> V_274 != V_275 ) {
V_24 = - V_428 ;
goto V_175;
}
F_1 ( V_2 , V_429 ) ;
if ( V_2 -> V_48 -> V_49 . V_62 [ 0 ] & V_63 )
V_24 = F_166 ( V_2 , V_201 , V_424 ) ;
else
V_24 = F_167 ( V_2 , V_201 , V_426 ) ;
if ( V_24 )
F_7 ( V_2 , V_429 ) ;
V_175:
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
static void F_168 ( struct V_21 * V_22 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_52 ( & V_2 -> V_216 ) ;
F_163 ( V_2 ) ;
F_58 ( & V_2 -> V_216 ) ;
}
static void
F_169 ( struct V_21 * V_22 ,
struct V_168 * V_169 , V_70 V_430 ,
int V_431 ,
enum V_432 V_433 ,
bool V_434 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_170 ( V_2 , V_169 , V_433 , V_431 ,
V_430 , V_434 , false ) ;
}
static void
F_171 ( struct V_21 * V_22 ,
struct V_168 * V_169 , V_70 V_430 ,
int V_431 ,
enum V_432 V_433 ,
bool V_434 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_170 ( V_2 , V_169 , V_433 , V_431 ,
V_430 , V_434 , true ) ;
}
static void F_172 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
enum V_435 V_325 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_66 * V_172 = F_31 ( V_169 ) ;
int V_204 ;
switch ( V_325 ) {
case V_436 :
if ( F_173 ( & V_2 -> V_437 [ V_172 -> V_176 ] ) > 0 )
F_174 ( V_22 , V_169 , true ) ;
F_4 ( & V_172 -> V_438 ) ;
for ( V_204 = 0 ; V_204 < V_439 ; V_204 ++ ) {
struct V_440 * V_441 ;
V_441 = & V_172 -> V_441 [ V_204 ] ;
if ( V_441 -> V_442 != V_443 &&
V_441 -> V_442 != V_444 )
continue;
if ( F_175 ( V_441 ) == 0 )
continue;
F_176 ( V_169 , V_204 , true ) ;
}
F_5 ( & V_172 -> V_438 ) ;
break;
case V_445 :
if ( F_8 ( V_172 -> V_176 == V_177 ) )
break;
F_177 ( V_2 , V_169 ) ;
break;
default:
break;
}
}
static void F_178 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_66 * V_446 = ( void * ) V_169 -> V_447 ;
F_52 ( & V_2 -> V_216 ) ;
if ( V_169 == F_156 ( V_2 -> V_448 [ V_446 -> V_176 ] ) )
F_179 ( V_2 -> V_448 [ V_446 -> V_176 ] ,
F_180 ( - V_449 ) ) ;
F_58 ( & V_2 -> V_216 ) ;
}
static int F_181 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_168 * V_169 ,
enum V_450 V_451 ,
enum V_450 V_452 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
int V_24 ;
F_128 ( V_2 , L_25 ,
V_169 -> V_94 , V_451 , V_452 ) ;
if ( F_14 ( ! V_221 -> V_227 ) )
return - V_218 ;
F_94 ( & V_2 -> V_318 ) ;
F_52 ( & V_2 -> V_216 ) ;
if ( V_451 == V_453 &&
V_452 == V_454 ) {
if ( V_201 -> type == V_73 &&
V_201 -> V_329 . V_385 < 16 ) {
F_88 ( V_2 ,
L_26 ,
V_169 -> V_94 , V_201 -> V_329 . V_385 ) ;
V_24 = - V_218 ;
goto V_305;
}
if ( V_169 -> V_455 &&
( V_201 -> V_309 ||
F_182 ( V_2 , NULL ) ==
V_456 ||
F_152 ( V_2 ) > 1 ) ) {
F_128 ( V_2 , L_27 ) ;
V_24 = - V_428 ;
goto V_305;
}
V_24 = F_183 ( V_2 , V_201 , V_169 ) ;
if ( V_169 -> V_455 && V_24 == 0 )
F_184 ( V_2 , V_201 , true ) ;
} else if ( V_451 == V_454 &&
V_452 == V_457 ) {
V_2 -> V_458 = true ;
V_24 = 0 ;
} else if ( V_451 == V_457 &&
V_452 == V_459 ) {
V_24 = F_185 ( V_2 , V_201 , V_169 ) ;
if ( V_24 == 0 )
F_186 ( V_2 , V_169 ,
V_221 -> V_227 -> V_460 -> V_461 ,
true ) ;
} else if ( V_451 == V_459 &&
V_452 == V_462 ) {
if ( F_152 ( V_2 ) > 1 )
F_153 ( V_2 ) ;
F_8 ( F_147 ( V_2 , V_201 , 0 ) ) ;
V_24 = 0 ;
} else if ( V_451 == V_462 &&
V_452 == V_459 ) {
F_8 ( F_105 ( V_2 , V_201 , 0 ) ) ;
V_24 = 0 ;
} else if ( V_451 == V_459 &&
V_452 == V_457 ) {
V_24 = 0 ;
} else if ( V_451 == V_457 &&
V_452 == V_454 ) {
V_24 = 0 ;
} else if ( V_451 == V_454 &&
V_452 == V_453 ) {
V_24 = F_187 ( V_2 , V_201 , V_169 ) ;
if ( V_169 -> V_455 )
F_184 ( V_2 , V_201 , false ) ;
} else {
V_24 = - V_16 ;
}
V_305:
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
static int F_188 ( struct V_21 * V_22 , T_2 V_463 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
V_2 -> V_135 = V_463 ;
return 0 ;
}
static void F_189 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_168 * V_169 , T_2 V_321 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
if ( V_201 -> type == V_73 &&
V_321 & V_464 )
F_140 ( V_2 , V_201 , false ) ;
}
static int F_190 ( struct V_21 * V_22 ,
struct V_200 * V_201 , V_70 V_465 ,
const struct V_466 * V_467 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
V_221 -> V_468 [ V_465 ] = * V_467 ;
if ( V_201 -> type == V_77 ) {
int V_24 ;
F_52 ( & V_2 -> V_216 ) ;
V_24 = F_138 ( V_2 , V_201 , false , NULL ) ;
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
return 0 ;
}
static void F_191 ( struct V_21 * V_22 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
T_2 V_469 = F_20 ( V_470 ,
200 + V_201 -> V_329 . V_385 ) ;
T_2 V_471 = F_20 ( V_472 ,
100 + V_201 -> V_329 . V_385 ) ;
if ( F_14 ( V_201 -> V_329 . V_330 ) )
return;
if ( F_11 ( V_2 , V_473 ) )
return;
F_52 ( & V_2 -> V_216 ) ;
F_139 ( V_2 , V_201 , V_469 , V_471 , 500 , false ) ;
F_58 ( & V_2 -> V_216 ) ;
F_7 ( V_2 , V_473 ) ;
}
static int F_192 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_474 * V_426 ,
struct V_475 * V_476 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
V_24 = F_162 ( V_2 , V_422 ) ;
if ( V_24 )
return V_24 ;
F_52 ( & V_2 -> V_216 ) ;
if ( V_2 -> V_48 -> V_49 . V_62 [ 0 ] & V_63 ) {
if ( ! V_201 -> V_329 . V_417 ) {
V_24 = - V_428 ;
goto V_175;
}
} else if ( ! F_193 ( V_2 ) ) {
V_24 = - V_428 ;
goto V_175;
}
if ( V_2 -> V_274 != V_275 ) {
V_24 = - V_428 ;
goto V_175;
}
V_2 -> V_274 = V_421 ;
if ( ! ( V_2 -> V_48 -> V_49 . V_62 [ 0 ] & V_63 ) ) {
V_24 = F_194 ( V_2 , V_201 , V_426 , V_476 ) ;
if ( V_24 )
goto V_477;
}
V_24 = F_195 ( V_2 , V_426 ) ;
if ( V_24 )
goto V_477;
if ( V_2 -> V_48 -> V_49 . V_62 [ 0 ] & V_63 )
V_24 = F_196 ( V_2 , V_201 , V_426 , V_476 ) ;
else
V_24 = F_197 ( V_2 , V_426 ) ;
if ( ! V_24 )
goto V_175;
V_477:
V_2 -> V_274 = V_275 ;
V_175:
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
static int F_198 ( struct V_21 * V_22 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
F_52 ( & V_2 -> V_216 ) ;
V_24 = F_161 ( V_2 , false ) ;
F_58 ( & V_2 -> V_216 ) ;
F_164 ( V_2 ) ;
return V_24 ;
}
static int F_199 ( struct V_21 * V_22 ,
enum V_478 V_325 ,
struct V_200 * V_201 ,
struct V_168 * V_169 ,
struct V_479 * V_480 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
if ( V_51 . V_52 ) {
F_128 ( V_2 , L_28 ) ;
return - V_481 ;
}
switch ( V_480 -> V_138 ) {
case V_482 :
V_480 -> V_25 |= V_483 ;
case V_484 :
V_480 -> V_25 |= V_485 ;
break;
case V_486 :
F_14 ( ! ( V_22 -> V_25 & V_53 ) ) ;
break;
case V_487 :
case V_488 :
return 0 ;
default:
if ( V_22 -> V_139 &&
V_22 -> V_140 -> V_138 == V_480 -> V_138 )
V_480 -> V_25 |= V_489 ;
else
return - V_481 ;
}
F_52 ( & V_2 -> V_216 ) ;
switch ( V_325 ) {
case V_490 :
if ( ( V_201 -> type == V_78 ||
V_201 -> type == V_75 ) && ! V_169 ) {
V_24 = 0 ;
V_480 -> V_491 = V_492 ;
break;
}
F_128 ( V_2 , L_29 ) ;
V_24 = F_200 ( V_2 , V_201 , V_169 , V_480 , false ) ;
if ( V_24 ) {
F_159 ( V_2 , L_30 ) ;
V_480 -> V_491 = V_492 ;
V_24 = 0 ;
}
break;
case V_493 :
if ( V_480 -> V_491 == V_492 ) {
V_24 = 0 ;
break;
}
F_128 ( V_2 , L_31 ) ;
V_24 = F_201 ( V_2 , V_201 , V_169 , V_480 ) ;
break;
default:
V_24 = - V_218 ;
}
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
static void F_202 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_479 * V_494 ,
struct V_168 * V_169 ,
T_2 V_495 , V_70 * V_496 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
if ( V_494 -> V_491 == V_492 )
return;
F_203 ( V_2 , V_201 , V_494 , V_169 , V_495 , V_496 ) ;
}
static bool F_204 ( struct V_497 * V_498 ,
struct V_499 * V_500 , void * V_187 )
{
struct V_1 * V_2 =
F_205 ( V_498 , struct V_1 , V_498 ) ;
struct V_501 * V_502 ;
int V_503 = F_206 ( V_500 ) ;
struct V_504 * V_505 = V_187 ;
if ( F_8 ( V_500 -> V_186 . V_325 != V_506 ) )
return true ;
if ( F_14 ( V_503 != sizeof( * V_502 ) ) ) {
F_88 ( V_2 , L_32 ) ;
return true ;
}
V_502 = ( void * ) V_500 -> V_187 ;
F_207 ( V_2 ,
L_33 ,
V_502 -> V_14 , V_502 -> V_507 ) ;
V_505 -> V_508 = F_208 ( V_502 -> V_507 ) ;
F_207 ( V_2 , L_34 ,
V_505 -> V_508 ) ;
F_4 ( & V_2 -> V_225 ) ;
F_209 ( & V_505 -> V_509 , & V_2 -> V_510 ) ;
F_5 ( & V_2 -> V_225 ) ;
return true ;
}
static int F_210 ( struct V_1 * V_2 ,
struct V_511 * V_460 ,
struct V_200 * V_201 ,
int V_469 )
{
int V_512 , V_513 = V_514 ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
struct V_504 * V_505 = & V_221 -> V_515 ;
static const T_1 V_516 [] = { V_506 } ;
struct V_517 V_518 ;
struct V_519 V_520 = {
. V_203 = F_68 ( V_521 ) ,
. V_522 =
F_68 ( F_211 ( V_523 , 0 ) ) ,
. V_524 = F_68 ( V_2 -> V_525 . V_176 ) ,
. V_526 . V_461 = ( V_460 -> V_461 == V_105 ) ?
V_527 : V_528 ,
. V_526 . V_460 = V_460 -> V_529 ,
. V_526 . V_530 = V_531 ,
. V_532 = F_68 ( F_212 ( V_2 -> V_7 , V_513 ) ) ,
. V_533 =
F_68 ( F_213 ( V_534 ) ) ,
. V_469 = F_68 ( F_213 ( V_469 ) ) ,
} ;
memcpy ( V_520 . V_535 , V_201 -> V_94 , V_97 ) ;
F_63 ( & V_2 -> V_216 ) ;
F_4 ( & V_2 -> V_225 ) ;
if ( F_8 ( V_505 -> V_19 == V_506 ) ) {
F_5 ( & V_2 -> V_225 ) ;
return - V_16 ;
}
V_505 -> V_201 = V_201 ;
V_505 -> V_469 = V_469 ;
V_505 -> V_19 = V_506 ;
F_5 ( & V_2 -> V_225 ) ;
F_214 ( & V_2 -> V_498 , & V_518 ,
V_516 ,
F_19 ( V_516 ) ,
F_204 , V_505 ) ;
V_512 = F_98 ( V_2 , V_506 , 0 , sizeof( V_520 ) ,
& V_520 ) ;
if ( V_512 ) {
F_88 ( V_2 , L_35 , V_512 ) ;
F_215 ( & V_2 -> V_498 , & V_518 ) ;
goto V_536;
}
V_512 = F_216 ( & V_2 -> V_498 , & V_518 , 1 ) ;
F_14 ( V_512 ) ;
if ( V_512 ) {
V_536:
F_4 ( & V_2 -> V_225 ) ;
F_61 ( V_2 , V_505 ) ;
F_5 ( & V_2 -> V_225 ) ;
}
return V_512 ;
}
static int F_217 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_511 * V_460 ,
int V_469 ,
enum V_537 type )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
struct V_538 V_539 ;
struct V_297 * V_227 ;
int V_24 , V_9 ;
F_128 ( V_2 , L_36 , V_460 -> V_529 ,
V_469 , type ) ;
F_52 ( & V_2 -> V_216 ) ;
switch ( V_201 -> type ) {
case V_73 :
if ( V_2 -> V_48 -> V_49 . V_126 [ 0 ] &
V_540 ) {
V_24 = F_210 ( V_2 , V_460 ,
V_201 , V_469 ) ;
goto V_305;
}
F_88 ( V_2 , L_37 ) ;
V_24 = - V_218 ;
goto V_305;
case V_77 :
break;
default:
F_88 ( V_2 , L_38 , V_201 -> type ) ;
V_24 = - V_218 ;
goto V_305;
}
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
V_227 = & V_2 -> V_17 [ V_9 ] ;
if ( V_227 -> V_20 == 0 || V_221 -> V_227 == V_227 )
continue;
if ( V_227 -> V_20 && V_460 == V_227 -> V_460 ) {
V_24 = F_109 ( V_2 , V_201 ) ;
if ( F_218 ( V_24 , L_39 ) )
goto V_305;
F_110 ( V_2 , V_221 -> V_227 ) ;
V_221 -> V_227 = V_227 ;
V_24 = F_107 ( V_2 , V_201 ) ;
if ( F_218 ( V_24 , L_40 ) )
goto V_305;
F_106 ( V_2 , V_221 -> V_227 ) ;
goto V_541;
}
}
if ( V_460 == V_221 -> V_227 -> V_460 )
goto V_541;
F_219 ( & V_539 , V_460 , V_542 ) ;
if ( V_221 -> V_227 -> V_20 == 1 ) {
V_24 = F_220 ( V_2 , V_221 -> V_227 ,
& V_539 , 1 , 1 ) ;
if ( V_24 )
goto V_305;
} else {
V_227 = F_95 ( V_2 ) ;
if ( ! V_227 ) {
V_24 = - V_313 ;
goto V_305;
}
V_24 = F_220 ( V_2 , V_227 , & V_539 ,
1 , 1 ) ;
if ( V_24 ) {
F_88 ( V_2 , L_41 ) ;
goto V_305;
}
V_24 = F_109 ( V_2 , V_201 ) ;
if ( F_218 ( V_24 , L_39 ) )
goto V_305;
F_110 ( V_2 , V_221 -> V_227 ) ;
V_221 -> V_227 = V_227 ;
V_24 = F_107 ( V_2 , V_201 ) ;
if ( F_218 ( V_24 , L_40 ) )
goto V_305;
F_106 ( V_2 , V_221 -> V_227 ) ;
}
V_541:
V_24 = F_221 ( V_2 , V_201 , V_469 , type ) ;
V_305:
F_58 ( & V_2 -> V_216 ) ;
F_128 ( V_2 , L_42 ) ;
return V_24 ;
}
static int F_222 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_128 ( V_2 , L_43 ) ;
F_52 ( & V_2 -> V_216 ) ;
F_223 ( V_2 ) ;
F_58 ( & V_2 -> V_216 ) ;
F_128 ( V_2 , L_42 ) ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_543 * V_544 )
{
V_70 * V_545 = ( V_70 * ) V_544 -> V_447 ;
struct V_297 * V_227 ;
int V_24 ;
F_63 ( & V_2 -> V_216 ) ;
F_128 ( V_2 , L_44 ) ;
V_227 = F_95 ( V_2 ) ;
if ( ! V_227 ) {
V_24 = - V_313 ;
goto V_175;
}
V_24 = F_220 ( V_2 , V_227 , & V_544 -> V_546 ,
V_544 -> V_547 ,
V_544 -> V_548 ) ;
if ( V_24 ) {
F_88 ( V_2 , L_45 ) ;
goto V_175;
}
F_106 ( V_2 , V_227 ) ;
* V_545 = V_227 -> V_19 ;
V_175:
return V_24 ;
}
static int F_225 ( struct V_21 * V_22 ,
struct V_543 * V_544 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
F_52 ( & V_2 -> V_216 ) ;
V_24 = F_224 ( V_2 , V_544 ) ;
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
static void F_226 ( struct V_1 * V_2 ,
struct V_543 * V_544 )
{
V_70 * V_545 = ( V_70 * ) V_544 -> V_447 ;
struct V_297 * V_227 = & V_2 -> V_17 [ * V_545 ] ;
F_63 ( & V_2 -> V_216 ) ;
F_110 ( V_2 , V_227 ) ;
}
static void F_227 ( struct V_21 * V_22 ,
struct V_543 * V_544 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_52 ( & V_2 -> V_216 ) ;
F_226 ( V_2 , V_544 ) ;
F_58 ( & V_2 -> V_216 ) ;
}
static void F_228 ( struct V_21 * V_22 ,
struct V_543 * V_544 ,
T_2 V_321 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
V_70 * V_545 = ( V_70 * ) V_544 -> V_447 ;
struct V_297 * V_227 = & V_2 -> V_17 [ * V_545 ] ;
if ( F_143 ( ( V_227 -> V_20 > 1 ) &&
( V_321 & ~ ( V_549 |
V_550 |
V_551 |
V_552 ) ) ,
L_46 ,
V_227 -> V_20 , V_321 ) )
return;
F_52 ( & V_2 -> V_216 ) ;
F_145 ( V_2 ) ;
F_220 ( V_2 , V_227 , & V_544 -> V_546 ,
V_544 -> V_547 ,
V_544 -> V_548 ) ;
F_58 ( & V_2 -> V_216 ) ;
}
static int F_229 ( struct V_1 * V_2 ,
struct V_200 * V_201 ,
struct V_543 * V_544 ,
bool V_553 )
{
V_70 * V_545 = ( V_70 * ) V_544 -> V_447 ;
struct V_297 * V_227 = & V_2 -> V_17 [ * V_545 ] ;
struct V_68 * V_221 = F_60 ( V_201 ) ;
int V_24 ;
F_63 ( & V_2 -> V_216 ) ;
V_221 -> V_227 = V_227 ;
switch ( V_201 -> type ) {
case V_75 :
if ( V_201 -> V_554 ) {
V_221 -> V_404 = true ;
break;
}
case V_78 :
V_24 = 0 ;
goto V_175;
case V_73 :
break;
case V_555 :
V_221 -> V_276 = true ;
break;
default:
V_24 = - V_218 ;
goto V_175;
}
V_24 = F_107 ( V_2 , V_201 ) ;
if ( V_24 )
goto V_175;
F_104 ( V_2 ) ;
if ( V_201 -> type == V_555 ) {
V_221 -> V_556 = true ;
V_24 = F_87 ( V_2 , NULL ) ;
if ( V_24 )
goto V_557;
}
if ( ( V_201 -> type == V_75 ) ||
( V_553 && ( V_201 -> type == V_73 ) ) ) {
F_87 ( V_2 , NULL ) ;
F_138 ( V_2 , V_201 , false , NULL ) ;
}
if ( V_201 -> V_554 && V_201 -> type == V_73 ) {
struct V_66 * V_172 ;
V_172 = F_230 ( V_2 ,
V_221 -> V_223 ) ;
if ( F_8 ( ! V_172 ) )
goto V_175;
F_231 ( V_2 , V_172 , false ) ;
}
goto V_175;
V_557:
F_109 ( V_2 , V_201 ) ;
F_104 ( V_2 ) ;
V_175:
if ( V_24 )
V_221 -> V_227 = NULL ;
return V_24 ;
}
static int F_232 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_543 * V_544 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
F_52 ( & V_2 -> V_216 ) ;
V_24 = F_229 ( V_2 , V_201 , V_544 , false ) ;
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
static void F_233 ( struct V_1 * V_2 ,
struct V_200 * V_201 ,
struct V_543 * V_544 ,
bool V_553 )
{
struct V_68 * V_221 = F_60 ( V_201 ) ;
struct V_200 * V_558 = NULL ;
struct V_66 * V_172 ;
F_63 ( & V_2 -> V_216 ) ;
F_146 ( V_2 , V_221 , & V_221 -> V_226 ) ;
switch ( V_201 -> type ) {
case V_78 :
goto V_175;
case V_555 :
V_221 -> V_556 = false ;
V_221 -> V_276 = false ;
break;
case V_75 :
if ( ! V_201 -> V_554 || ! V_221 -> V_404 )
goto V_175;
F_234 ( V_2 , V_221 , true ) ;
F_179 ( V_2 -> V_408 , V_201 ) ;
V_221 -> V_404 = false ;
break;
case V_73 :
if ( ! V_553 )
break;
V_558 = V_201 ;
V_172 = F_230 ( V_2 ,
V_221 -> V_223 ) ;
if ( ! F_8 ( ! V_172 ) )
F_231 ( V_2 , V_172 , true ) ;
F_138 ( V_2 , V_201 , true , NULL ) ;
break;
default:
break;
}
F_87 ( V_2 , V_558 ) ;
F_109 ( V_2 , V_201 ) ;
V_175:
V_221 -> V_227 = NULL ;
F_104 ( V_2 ) ;
}
static void F_235 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_543 * V_544 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_52 ( & V_2 -> V_216 ) ;
F_233 ( V_2 , V_201 , V_544 , false ) ;
F_58 ( & V_2 -> V_216 ) ;
}
static int F_236 ( struct V_21 * V_22 ,
struct V_559 * V_560 ,
int V_561 ,
enum V_562 V_563 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_24 ;
if ( V_563 != V_564 || V_561 > 1 )
return - V_481 ;
F_52 ( & V_2 -> V_216 ) ;
F_233 ( V_2 , V_560 [ 0 ] . V_201 , V_560 [ 0 ] . V_565 , true ) ;
F_226 ( V_2 , V_560 [ 0 ] . V_565 ) ;
V_24 = F_224 ( V_2 , V_560 [ 0 ] . V_566 ) ;
if ( V_24 ) {
F_88 ( V_2 , L_47 ) ;
goto V_567;
}
V_24 = F_229 ( V_2 , V_560 [ 0 ] . V_201 , V_560 [ 0 ] . V_566 ,
true ) ;
if ( V_24 ) {
F_88 ( V_2 ,
L_48 ) ;
goto V_403;
}
if ( F_152 ( V_2 ) > 1 )
F_153 ( V_2 ) ;
goto V_175;
V_403:
F_226 ( V_2 , V_560 [ 0 ] . V_566 ) ;
V_567:
V_24 = F_224 ( V_2 , V_560 [ 0 ] . V_565 ) ;
if ( V_24 ) {
F_88 ( V_2 , L_49 ) ;
goto V_568;
}
V_24 = F_229 ( V_2 , V_560 [ 0 ] . V_201 , V_560 [ 0 ] . V_565 ,
true ) ;
if ( V_24 ) {
F_88 ( V_2 , L_50 ) ;
goto V_568;
}
goto V_175;
V_568:
F_237 ( V_2 , false ) ;
V_175:
F_58 ( & V_2 -> V_216 ) ;
return V_24 ;
}
static int F_238 ( struct V_21 * V_22 ,
struct V_168 * V_169 ,
bool V_569 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_66 * V_446 = ( void * ) V_169 -> V_447 ;
if ( ! V_446 || ! V_446 -> V_201 ) {
F_88 ( V_2 , L_51 ) ;
return - V_218 ;
}
return F_150 ( V_2 , V_446 -> V_201 ) ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_200 * V_201 ,
void * V_187 , int V_147 )
{
struct V_570 * V_571 [ V_572 + 1 ] ;
int V_477 ;
T_2 V_320 ;
V_477 = F_240 ( V_571 , V_572 , V_187 , V_147 , V_573 ) ;
if ( V_477 )
return V_477 ;
if ( ! V_571 [ V_574 ] )
return - V_218 ;
switch ( F_241 ( V_571 [ V_574 ] ) ) {
case V_575 :
if ( ! V_201 || V_201 -> type != V_75 || ! V_201 -> V_309 ||
! V_201 -> V_329 . V_576 ||
! V_571 [ V_577 ] )
return - V_218 ;
V_320 = F_241 ( V_571 [ V_577 ] ) ;
if ( V_320 >= V_201 -> V_329 . V_385 )
return - V_218 ;
V_2 -> V_320 = V_320 ;
V_2 -> V_319 = V_201 ;
return F_87 ( V_2 , NULL ) ;
case V_578 :
if ( ! V_201 || V_201 -> type != V_73 ||
! V_201 -> V_329 . V_330 || ! V_201 -> V_329 . V_579 ||
! V_571 [ V_580 ] )
return - V_218 ;
if ( F_241 ( V_571 [ V_580 ] ) )
return F_147 ( V_2 , V_201 , 0 ) ;
return F_105 ( V_2 , V_201 , 0 ) ;
}
return - V_481 ;
}
static int F_242 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
void * V_187 , int V_147 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
int V_477 ;
F_52 ( & V_2 -> V_216 ) ;
V_477 = F_239 ( V_2 , V_201 , V_187 , V_147 ) ;
F_58 ( & V_2 -> V_216 ) ;
return V_477 ;
}
static void F_243 ( struct V_21 * V_22 ,
struct V_200 * V_201 ,
struct V_538 * V_539 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_200 * V_407 ;
F_52 ( & V_2 -> V_216 ) ;
V_407 = F_244 ( V_2 -> V_407 ,
F_245 ( & V_2 -> V_216 ) ) ;
if ( F_218 ( V_407 && V_407 -> V_554 ,
L_52 ) )
goto V_305;
F_128 ( V_2 , L_53 ,
V_539 -> V_581 ) ;
F_179 ( V_2 -> V_407 , V_201 ) ;
V_305:
F_58 ( & V_2 -> V_216 ) ;
}
static void F_246 ( struct V_21 * V_22 ,
struct V_200 * V_201 , T_2 V_38 , bool V_188 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
struct V_68 * V_221 ;
struct V_66 * V_172 ;
if ( ! V_201 || V_201 -> type != V_73 )
return;
F_52 ( & V_2 -> V_216 ) ;
V_221 = F_60 ( V_201 ) ;
V_172 = F_230 ( V_2 , V_221 -> V_223 ) ;
if ( F_14 ( ! V_172 ) )
goto V_582;
if ( V_188 ) {
if ( F_115 ( V_2 , V_172 -> V_583 , true ) )
F_88 ( V_2 , L_54 ) ;
} else {
F_247 ( V_2 -> V_7 ,
V_172 -> V_583 ) ;
}
V_582:
F_58 ( & V_2 -> V_216 ) ;
}
