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
static int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 -> V_22 . V_23 & V_24 )
return V_2 -> V_21 -> V_22 . V_25 - 24 - 2 ;
return V_2 -> V_21 -> V_22 . V_25 - 24 - 34 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_28 , V_29 , V_9 ;
V_27 -> V_23 = V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 ;
V_27 -> V_43 = V_2 -> V_44 ;
V_27 -> V_45 = V_46 ;
V_27 -> V_47 |= V_48 |
V_49 ;
V_27 -> V_50 |= V_51 ;
V_27 -> V_52 = L_4 ;
if ( V_2 -> V_21 -> V_22 . V_23 & V_53 &&
! V_54 . V_55 )
V_27 -> V_23 |= V_56 ;
if ( V_2 -> V_21 -> V_22 . V_23 & V_57 &&
F_18 ( V_2 -> V_21 -> V_58 ) >= 9 &&
! V_54 . V_59 ) {
V_27 -> V_23 |= V_60 ;
V_27 -> V_61 = V_62 ;
V_27 -> V_63 = V_64 ;
}
if ( V_2 -> V_21 -> V_22 . V_65 [ 0 ] & V_66 )
V_27 -> V_23 |= V_67 ;
V_27 -> V_68 = sizeof( struct V_69 ) ;
V_27 -> V_70 = sizeof( struct V_71 ) ;
V_27 -> V_72 = sizeof( V_73 ) ;
V_27 -> V_74 -> V_75 = F_19 ( V_76 ) |
F_19 ( V_77 ) |
F_19 ( V_78 ) |
F_19 ( V_79 ) |
F_19 ( V_80 ) |
F_19 ( V_81 ) ;
V_27 -> V_74 -> V_23 |= V_82 ;
V_27 -> V_74 -> V_83 |= V_84 |
V_85 ;
if ( V_2 -> V_21 -> V_22 . V_23 & V_86 )
V_27 -> V_74 -> V_23 |= V_87 ;
if ( V_2 -> V_21 -> V_22 . V_65 [ 0 ] & V_88 )
V_27 -> V_74 -> V_23 |= V_89 ;
V_27 -> V_74 -> V_90 = V_91 ;
V_27 -> V_74 -> V_92 =
F_20 ( V_91 ) ;
V_27 -> V_74 -> V_93 = 10000 ;
V_27 -> V_94 = V_95 ;
memcpy ( V_2 -> V_96 [ 0 ] . V_97 , V_2 -> V_98 -> V_99 , V_100 ) ;
V_27 -> V_74 -> V_96 = V_2 -> V_96 ;
V_27 -> V_74 -> V_101 = 1 ;
V_28 = ( V_2 -> V_98 -> V_102 > 1 ) ?
F_21 ( V_103 , V_2 -> V_98 -> V_102 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_28 ; V_9 ++ ) {
memcpy ( V_2 -> V_96 [ V_9 ] . V_97 , V_2 -> V_96 [ V_9 - 1 ] . V_97 ,
V_100 ) ;
V_2 -> V_96 [ V_9 ] . V_97 [ 5 ] ++ ;
V_27 -> V_74 -> V_101 ++ ;
}
F_15 ( V_2 ) ;
V_27 -> V_74 -> V_104 = F_16 ( V_2 ) ;
V_27 -> V_74 -> V_105 = V_106 ;
if ( V_2 -> V_98 -> V_107 [ V_108 ] . V_109 )
V_27 -> V_74 -> V_107 [ V_108 ] =
& V_2 -> V_98 -> V_107 [ V_108 ] ;
if ( V_2 -> V_98 -> V_107 [ V_110 ] . V_109 )
V_27 -> V_74 -> V_107 [ V_110 ] =
& V_2 -> V_98 -> V_107 [ V_110 ] ;
V_27 -> V_74 -> V_111 = V_2 -> V_7 -> V_112 ;
if ( V_113 . V_114 != V_115 )
V_27 -> V_74 -> V_23 |= V_116 ;
else
V_27 -> V_74 -> V_23 &= ~ V_116 ;
if ( F_18 ( V_2 -> V_21 -> V_58 ) >= 10 ) {
V_27 -> V_74 -> V_23 |= V_117 ;
V_27 -> V_74 -> V_118 = V_106 ;
V_27 -> V_74 -> V_119 = V_120 ;
V_27 -> V_74 -> V_121 =
V_122 - 24 - 2 ;
}
V_27 -> V_74 -> V_123 |= V_124 |
V_125 |
V_126 ;
V_2 -> V_127 = V_128 ;
if ( V_2 -> V_21 -> V_129 [ 0 ] . V_130 ) {
V_2 -> V_27 -> V_131 = 1 ;
V_2 -> V_27 -> V_132 = & V_2 -> V_21 -> V_129 [ 0 ] ;
}
#ifdef F_22
if ( F_2 ( V_2 ) &&
F_23 ( V_2 -> V_7 -> V_133 ) ) {
V_2 -> V_134 . V_23 = V_135 ;
V_27 -> V_74 -> V_134 = & V_2 -> V_134 ;
} else if ( V_2 -> V_21 -> V_136 [ V_137 ] . V_138 [ 0 ] . V_139 &&
V_2 -> V_7 -> V_140 -> V_141 &&
V_2 -> V_7 -> V_140 -> V_142 &&
F_23 ( V_2 -> V_7 -> V_133 ) ) {
V_2 -> V_134 . V_23 = V_143 |
V_144 |
V_145 |
V_146 ;
if ( ! V_54 . V_55 )
V_2 -> V_134 . V_23 |= V_147 |
V_148 |
V_149 ;
V_2 -> V_134 . V_150 = V_151 ;
V_2 -> V_134 . V_152 = V_153 ;
V_2 -> V_134 . V_154 = V_155 ;
V_2 -> V_134 . V_156 = & V_157 ;
V_27 -> V_74 -> V_134 = & V_2 -> V_134 ;
}
#endif
#ifdef F_24
V_2 -> V_158 = V_159 ;
#endif
V_29 = F_25 ( V_2 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_26 ( V_2 -> V_27 ) ;
if ( V_29 )
F_27 ( V_2 ) ;
return V_29 ;
}
static bool F_28 ( struct V_1 * V_2 ,
struct V_160 * V_161 ,
struct V_162 * V_163 )
{
struct V_69 * V_164 ;
bool V_165 = false ;
if ( F_29 ( ! F_13 ( V_13 , & V_2 -> V_14 ) ) )
return false ;
F_30 ( & V_2 -> V_166 ) ;
if ( ! F_13 ( V_13 , & V_2 -> V_14 ) )
goto V_167;
V_164 = F_31 ( V_161 ) ;
if ( V_164 -> V_168 == V_169 ||
V_164 -> V_168 != V_2 -> V_170 )
goto V_167;
F_32 ( & V_2 -> V_171 , V_163 ) ;
F_33 ( V_2 -> V_27 ) ;
F_1 ( V_2 , V_172 ) ;
F_7 ( V_2 , V_172 ) ;
V_165 = true ;
V_167:
F_34 ( & V_2 -> V_166 ) ;
return V_165 ;
}
static void F_35 ( struct V_26 * V_27 ,
struct V_173 * V_174 ,
struct V_162 * V_163 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_160 * V_161 = V_174 -> V_161 ;
struct V_175 * V_176 = F_37 ( V_163 ) ;
struct V_177 * V_178 = ( void * ) V_163 -> V_179 ;
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 , L_5 ) ;
goto V_180;
}
if ( F_37 ( V_163 ) -> V_181 == V_46 &&
! F_13 ( V_182 , & V_2 -> V_14 ) )
goto V_180;
if ( F_40 ( V_176 -> V_23 & V_183 &&
F_41 ( V_178 -> V_184 ) &&
! F_42 ( V_178 -> V_184 ) &&
! F_43 ( V_178 -> V_184 ) &&
! F_44 ( V_178 -> V_184 ) ) )
V_161 = NULL ;
if ( V_161 ) {
if ( F_28 ( V_2 , V_161 , V_163 ) )
return;
if ( F_45 ( V_2 , V_163 , V_161 ) )
goto V_180;
return;
}
if ( F_46 ( V_2 , V_163 ) )
goto V_180;
return;
V_180:
F_47 ( V_27 , V_163 ) ;
}
static inline bool F_48 ( const struct V_185 * V_186 )
{
if ( V_54 . V_187 & V_188 )
return false ;
return true ;
}
static inline bool F_49 ( const struct V_185 * V_186 )
{
if ( V_54 . V_187 & V_189 )
return false ;
if ( V_54 . V_187 & V_190 )
return true ;
return true ;
}
static int F_50 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
enum V_193 V_194 ,
struct V_160 * V_161 , V_73 V_195 ,
V_73 * V_196 , T_1 V_197 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
bool V_198 = false ;
F_51 ( V_2 , L_6 ,
V_161 -> V_97 , V_195 , V_194 ) ;
if ( ! ( V_2 -> V_98 -> V_199 ) )
return - V_200 ;
switch ( V_194 ) {
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
V_29 = F_11 ( V_2 , V_206 ) ;
if ( V_29 )
return V_29 ;
V_198 = true ;
break;
default:
break;
}
F_52 ( & V_2 -> V_207 ) ;
switch ( V_194 ) {
case V_208 :
if ( ! F_48 ( V_2 -> V_186 ) ) {
V_29 = - V_209 ;
break;
}
V_29 = F_53 ( V_2 , V_161 , V_195 , * V_196 , true ) ;
break;
case V_210 :
V_29 = F_53 ( V_2 , V_161 , V_195 , 0 , false ) ;
break;
case V_201 :
if ( ! F_49 ( V_2 -> V_186 ) ) {
V_29 = - V_209 ;
break;
}
V_29 = F_54 ( V_2 , V_192 , V_161 , V_195 , V_196 ) ;
break;
case V_202 :
V_29 = F_55 ( V_2 , V_192 , V_161 , V_195 ) ;
break;
case V_203 :
case V_204 :
V_29 = F_56 ( V_2 , V_192 , V_161 , V_195 ) ;
break;
case V_205 :
V_29 = F_57 ( V_2 , V_192 , V_161 , V_195 , V_197 ) ;
break;
default:
F_14 ( 1 ) ;
V_29 = - V_209 ;
break;
}
F_58 ( & V_2 -> V_207 ) ;
if ( V_198 )
F_7 ( V_2 , V_206 ) ;
return V_29 ;
}
static void F_59 ( void * V_179 , T_1 * V_211 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = V_179 ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
V_212 -> V_213 = false ;
V_212 -> V_214 = V_169 ;
V_212 -> V_215 ++ ;
F_4 ( & V_2 -> V_216 ) ;
F_61 ( V_2 , & V_212 -> V_217 ) ;
F_5 ( & V_2 -> V_216 ) ;
V_212 -> V_218 = NULL ;
memset ( & V_212 -> V_219 , 0 , sizeof( V_212 -> V_219 ) ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_220 * V_221 ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
struct V_226 * V_227 ;
const struct V_228 * V_136 ;
T_2 V_229 , V_230 ;
T_2 V_231 , V_232 ;
unsigned long V_23 ;
int V_233 ;
F_63 ( & V_2 -> V_207 ) ;
if ( V_2 -> V_227 )
return;
V_227 = F_64 ( sizeof( * V_2 -> V_227 ) , V_234 ) ;
if ( ! V_227 )
return;
V_136 = & V_2 -> V_21 -> V_136 [ V_2 -> V_235 ] ;
V_230 = V_136 -> V_138 [ V_236 ] . V_237 ;
V_229 = V_136 -> V_138 [ V_236 ] . V_139 ;
V_233 = F_65 ( V_2 -> V_7 , V_238 ) ;
V_232 = ( V_233 & V_239 ) >> V_240 ;
V_232 = V_232 << 7 ;
V_231 = sizeof( * V_221 ) +
sizeof( * V_223 ) * 3 +
V_229 +
V_232 +
sizeof( * V_225 ) ;
V_221 = F_66 ( V_231 ) ;
if ( ! V_221 ) {
F_67 ( V_227 ) ;
return;
}
V_227 -> V_241 = V_221 ;
V_221 -> V_242 = F_68 ( V_243 ) ;
V_223 = ( void * ) V_221 -> V_179 ;
V_223 -> type = F_68 ( V_244 ) ;
V_223 -> V_139 = F_68 ( sizeof( * V_225 ) ) ;
V_225 = ( void * ) V_223 -> V_179 ;
V_225 -> V_245 =
V_2 -> V_186 -> V_245 == V_246 ?
F_68 ( V_247 ) :
F_68 ( V_248 ) ;
memcpy ( V_225 -> V_249 , V_2 -> V_21 -> V_250 ,
sizeof( V_225 -> V_249 ) ) ;
strncpy ( V_225 -> V_251 , V_2 -> V_186 -> V_252 ,
sizeof( V_225 -> V_251 ) ) ;
strncpy ( V_225 -> V_253 , V_2 -> V_133 -> V_254 -> V_252 ,
sizeof( V_225 -> V_253 ) ) ;
V_223 = F_69 ( V_223 ) ;
V_223 -> type = F_68 ( V_255 ) ;
V_223 -> V_139 = F_68 ( V_232 ) ;
if ( F_70 ( V_2 -> V_7 , false , & V_23 ) ) {
T_2 * V_256 = ( void * ) V_223 -> V_179 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < ( V_232 / sizeof( T_2 ) ) ; V_9 ++ ) {
F_71 ( V_2 -> V_7 ,
V_257 ,
V_9 * sizeof( T_2 ) ) ;
V_256 [ V_9 ] = F_65 ( V_2 -> V_7 ,
V_258 ) ;
}
F_72 ( V_2 -> V_7 , & V_23 ) ;
}
V_223 = F_69 ( V_223 ) ;
V_223 -> type = F_68 ( V_259 ) ;
V_223 -> V_139 = F_68 ( V_229 ) ;
F_73 ( V_2 -> V_7 , V_230 , V_223 -> V_179 ,
V_229 ) ;
V_227 -> V_260 = F_74 ( V_2 -> V_7 ) ;
V_227 -> V_261 = V_231 ;
if ( V_227 -> V_260 )
V_231 += V_227 -> V_260 -> V_139 ;
V_221 -> V_231 = F_68 ( V_231 ) ;
V_2 -> V_227 = V_227 ;
}
static void F_75 ( struct V_1 * V_2 )
{
#ifdef F_76
static char * V_262 [] = { L_7 , L_8 , NULL } ;
F_62 ( V_2 ) ;
F_77 ( & V_2 -> V_27 -> V_74 -> V_133 . V_263 , V_264 , V_262 ) ;
#endif
F_78 ( V_2 -> V_7 ) ;
V_2 -> V_265 = V_266 ;
F_79 ( V_2 -> V_27 ) ;
F_80 (
V_2 -> V_27 , V_267 ,
F_59 , V_2 ) ;
V_2 -> V_268 = NULL ;
V_2 -> V_170 = V_169 ;
F_15 ( V_2 ) ;
memset ( V_2 -> V_269 , 0 , sizeof( V_2 -> V_269 ) ) ;
memset ( V_2 -> V_270 , 0 , sizeof( V_2 -> V_270 ) ) ;
memset ( & V_2 -> V_271 , 0 , sizeof( V_2 -> V_271 ) ) ;
memset ( & V_2 -> V_272 , 0 , sizeof( V_2 -> V_272 ) ) ;
memset ( & V_2 -> V_273 , 0 , sizeof( V_2 -> V_273 ) ) ;
memset ( & V_2 -> V_274 , 0 , sizeof( V_2 -> V_274 ) ) ;
memset ( & V_2 -> V_275 , 0 , sizeof( V_2 -> V_275 ) ) ;
memset ( & V_2 -> V_276 , 0 , sizeof( V_2 -> V_276 ) ) ;
F_81 ( V_2 -> V_27 ) ;
F_10 ( V_2 , V_277 ) ;
V_2 -> V_278 = 0 ;
V_2 -> V_279 = 0 ;
}
static int F_82 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
F_52 ( & V_2 -> V_207 ) ;
if ( F_13 ( V_280 , & V_2 -> V_14 ) )
F_75 ( V_2 ) ;
V_29 = F_83 ( V_2 ) ;
if ( V_29 && F_13 ( V_280 , & V_2 -> V_14 ) ) {
F_84 ( V_280 , & V_2 -> V_14 ) ;
F_85 ( V_2 , NULL ) ;
}
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
static void F_86 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
F_52 ( & V_2 -> V_207 ) ;
F_84 ( V_280 , & V_2 -> V_14 ) ;
F_85 ( V_2 , NULL ) ;
V_29 = F_87 ( V_2 , NULL ) ;
if ( V_29 )
F_88 ( V_2 , L_9 ,
V_29 ) ;
F_7 ( V_2 , V_277 ) ;
F_58 ( & V_2 -> V_207 ) ;
}
static void F_89 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
F_90 ( & V_2 -> V_281 ) ;
F_90 ( & V_2 -> V_282 ) ;
F_52 ( & V_2 -> V_207 ) ;
F_1 ( V_2 , V_277 ) ;
F_91 ( & V_2 -> V_283 ) ;
F_78 ( V_2 -> V_7 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 , & V_2 -> V_284 ) ;
F_58 ( & V_2 -> V_207 ) ;
F_91 ( & V_2 -> V_282 ) ;
}
static struct V_285 * F_94 ( struct V_1 * V_2 )
{
V_73 V_9 ;
F_63 ( & V_2 -> V_207 ) ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ )
if ( ! V_2 -> V_17 [ V_9 ] . V_20 )
return & V_2 -> V_17 [ V_9 ] ;
F_88 ( V_2 , L_10 ) ;
return NULL ;
}
static int F_95 ( struct V_1 * V_2 , struct V_191 * V_192 ,
T_3 V_286 )
{
struct V_287 V_288 = {
. V_289 = F_60 ( V_192 ) -> V_19 ,
. V_290 = F_96 ( V_286 ) ,
} ;
return F_97 ( V_2 , V_291 , 0 ,
sizeof( V_288 ) ,
& V_288 ) ;
}
static int F_98 ( struct V_26 * V_27 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
int V_29 ;
V_29 = F_11 ( V_2 , V_292 ) ;
if ( V_29 )
return V_29 ;
F_52 ( & V_2 -> V_207 ) ;
V_29 = F_99 ( V_2 , V_192 ) ;
if ( V_29 )
goto V_293;
if ( V_192 -> type != V_80 )
V_2 -> V_278 ++ ;
if ( V_192 -> type == V_78 ||
V_192 -> type == V_81 ) {
T_2 V_294 = F_100 ( V_2 , V_192 ) ;
V_29 = F_101 ( V_2 , & V_212 -> V_295 ,
V_294 ,
F_102 ( V_192 ) ) ;
if ( V_29 ) {
F_88 ( V_2 , L_11 ) ;
goto V_296;
}
F_103 ( V_2 , V_192 ) ;
goto V_293;
}
V_29 = F_104 ( V_2 , V_192 ) ;
if ( V_29 )
goto V_296;
V_29 = F_105 ( V_2 ) ;
if ( V_29 )
goto V_296;
V_29 = F_106 ( V_2 , V_192 , 0 ) ;
if ( V_29 )
goto V_297;
if ( ! V_2 -> V_298 &&
V_192 -> type == V_76 && ! V_192 -> V_299 ) {
V_2 -> V_298 = V_212 ;
V_192 -> V_300 |= V_301 |
V_302 ;
}
if ( V_192 -> type == V_80 ) {
V_212 -> V_218 = F_94 ( V_2 ) ;
if ( ! V_212 -> V_218 ) {
V_29 = - V_303 ;
goto V_304;
}
F_107 ( V_2 , V_212 -> V_218 ) ;
V_29 = F_108 ( V_2 , V_192 ) ;
if ( V_29 )
goto V_305;
V_29 = F_109 ( V_2 , V_192 , & V_212 -> V_295 ) ;
if ( V_29 )
goto V_306;
V_2 -> V_268 = V_192 ;
}
F_103 ( V_2 , V_192 ) ;
goto V_293;
V_306:
F_110 ( V_2 , V_192 ) ;
V_305:
F_111 ( V_2 , V_212 -> V_218 ) ;
V_304:
if ( V_2 -> V_298 == V_212 ) {
V_2 -> V_298 = NULL ;
V_192 -> V_300 &= ~ ( V_301 |
V_302 ) ;
}
V_297:
V_212 -> V_218 = NULL ;
F_112 ( V_2 , V_192 ) ;
V_296:
if ( V_192 -> type != V_80 )
V_2 -> V_278 -- ;
F_113 ( V_2 , V_192 ) ;
V_293:
F_58 ( & V_2 -> V_207 ) ;
F_7 ( V_2 , V_292 ) ;
return V_29 ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_191 * V_192 )
{
T_2 V_307 = 0 , V_308 ;
for ( V_308 = 0 ; V_308 < V_309 ; V_308 ++ )
if ( V_192 -> V_181 [ V_308 ] != V_310 )
V_307 |= F_19 ( V_192 -> V_181 [ V_308 ] ) ;
if ( V_192 -> V_311 != V_310 )
V_307 |= F_19 ( V_192 -> V_311 ) ;
if ( V_307 ) {
F_52 ( & V_2 -> V_207 ) ;
F_115 ( V_2 , V_307 , true ) ;
F_58 ( & V_2 -> V_207 ) ;
}
if ( V_192 -> type == V_80 ) {
F_90 ( & V_2 -> V_283 ) ;
} else {
F_90 ( & V_2 -> V_312 ) ;
}
}
static void F_116 ( struct V_26 * V_27 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
F_114 ( V_2 , V_192 ) ;
F_52 ( & V_2 -> V_207 ) ;
if ( V_2 -> V_298 == V_212 ) {
V_2 -> V_298 = NULL ;
V_192 -> V_300 &= ~ ( V_301 |
V_302 ) ;
}
F_117 ( V_2 , V_192 ) ;
if ( V_192 -> type == V_78 ||
V_192 -> type == V_81 ) {
#ifdef F_118
if ( V_192 == V_2 -> V_313 ) {
V_2 -> V_313 = NULL ;
V_2 -> V_314 = 0 ;
}
#endif
F_93 ( V_2 , & V_212 -> V_295 ) ;
goto V_296;
}
if ( V_192 -> type == V_80 ) {
V_2 -> V_268 = NULL ;
F_119 ( V_2 , & V_212 -> V_295 ) ;
F_110 ( V_2 , V_192 ) ;
F_111 ( V_2 , V_212 -> V_218 ) ;
V_212 -> V_218 = NULL ;
}
if ( V_2 -> V_278 && V_192 -> type != V_80 )
V_2 -> V_278 -- ;
F_105 ( V_2 ) ;
F_112 ( V_2 , V_192 ) ;
V_296:
F_113 ( V_2 , V_192 ) ;
F_58 ( & V_2 -> V_207 ) ;
}
static int F_120 ( struct V_26 * V_27 , T_2 V_315 )
{
return 0 ;
}
static void F_121 ( void * V_316 , T_1 * V_211 ,
struct V_191 * V_192 )
{
struct V_317 * V_179 = V_316 ;
struct V_1 * V_2 = V_179 -> V_2 ;
struct V_318 * V_319 = V_2 -> V_320 ;
int V_29 , V_139 ;
if ( F_14 ( V_179 -> V_321 >= V_322 ) )
return;
if ( V_192 -> type != V_76 ||
! V_192 -> V_323 . V_324 )
return;
V_319 -> V_321 = V_179 -> V_321 ++ ;
memcpy ( V_319 -> V_325 , V_192 -> V_323 . V_325 , V_100 ) ;
V_139 = F_122 ( sizeof( * V_319 ) + V_319 -> V_326 * V_100 , 4 ) ;
V_29 = F_97 ( V_2 , V_327 , V_328 , V_139 , V_319 ) ;
if ( V_29 )
F_88 ( V_2 , L_12 , V_29 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_317 V_329 = {
. V_2 = V_2 ,
} ;
F_63 ( & V_2 -> V_207 ) ;
if ( F_14 ( ! V_2 -> V_320 ) )
return;
F_80 (
V_2 -> V_27 , V_330 ,
F_121 , & V_329 ) ;
}
static T_4 F_124 ( struct V_26 * V_27 ,
struct V_331 * V_332 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_318 * V_319 ;
struct V_333 * V_97 ;
int V_334 = F_125 ( V_332 ) ;
bool V_335 = false ;
int V_139 ;
if ( V_334 > V_336 ) {
V_335 = true ;
V_334 = 0 ;
}
V_139 = F_122 ( sizeof( * V_319 ) + V_334 * V_100 , 4 ) ;
V_319 = F_64 ( V_139 , V_337 ) ;
if ( ! V_319 )
return 0 ;
if ( V_335 ) {
V_319 -> V_335 = 1 ;
return ( T_4 ) ( unsigned long ) V_319 ;
}
F_126 (addr, mc_list) {
F_127 ( V_2 , L_13 ,
V_319 -> V_326 , V_97 -> V_97 ) ;
memcpy ( & V_319 -> V_338 [ V_319 -> V_326 * V_100 ] ,
V_97 -> V_97 , V_100 ) ;
V_319 -> V_326 ++ ;
}
return ( T_4 ) ( unsigned long ) V_319 ;
}
static void F_128 ( struct V_26 * V_27 ,
unsigned int V_339 ,
unsigned int * V_340 ,
T_4 V_341 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_318 * V_319 = ( void * ) ( unsigned long ) V_341 ;
F_52 ( & V_2 -> V_207 ) ;
F_67 ( V_2 -> V_320 ) ;
V_2 -> V_320 = V_319 ;
if ( ! V_319 )
goto V_167;
F_123 ( V_2 ) ;
V_167:
F_58 ( & V_2 -> V_207 ) ;
* V_340 = 0 ;
}
static void
F_129 ( struct V_191 * V_192 ,
const struct V_342 * V_343 ,
struct V_342 * V_344 )
{
struct V_345 * V_346 ;
int V_9 ;
memcpy ( V_344 , V_343 , sizeof( * V_344 ) ) ;
for ( V_9 = 0 ; V_9 < F_20 ( V_344 -> V_347 ) ; V_9 ++ ) {
V_346 = & V_344 -> V_347 [ V_9 ] ;
if ( ! V_346 -> V_348 )
break;
switch ( V_346 -> V_349 ) {
case F_96 ( V_350 ) :
if ( V_192 -> V_323 . V_351 != 1 ) {
V_346 -> V_348 = 0 ;
continue;
}
V_346 -> V_352 = V_192 -> V_323 . V_353 [ 0 ] ;
break;
case F_96 ( V_354 ) :
V_346 -> V_352 = * ( V_355 * ) & V_192 -> V_97 [ 2 ] ;
break;
default:
break;
}
V_346 -> V_349 = 0 ;
V_344 -> V_356 ++ ;
}
}
static void F_130 ( void * V_316 , T_1 * V_211 ,
struct V_191 * V_192 )
{
struct V_357 * V_179 = V_316 ;
struct V_1 * V_2 = V_179 -> V_2 ;
struct V_358 * V_319 = V_179 -> V_319 ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
struct V_359 * V_360 ;
int V_9 ;
if ( F_8 ( V_212 -> V_19 >= F_20 ( V_319 -> V_361 ) ) )
return;
V_360 = & V_319 -> V_361 [ V_212 -> V_19 ] ;
if ( V_192 -> type != V_76 || V_192 -> V_299 ||
! V_192 -> V_323 . V_324 )
return;
V_360 -> V_362 = 1 ;
for ( V_9 = 0 ; V_2 -> V_158 [ V_9 ] . V_347 [ 0 ] . V_348 ; V_9 ++ ) {
if ( F_14 ( V_179 -> V_363 >=
F_20 ( V_319 -> V_364 ) ) ) {
V_360 -> V_362 = 0 ;
V_360 -> V_365 = 0 ;
break;
}
F_129 ( V_192 ,
& V_2 -> V_158 [ V_9 ] ,
& V_319 -> V_364 [ V_179 -> V_363 ] ) ;
if ( ! V_319 -> V_364 [ V_179 -> V_363 ] . V_356 )
continue;
V_360 -> V_365 |=
F_96 ( F_19 ( V_179 -> V_363 ) ) ;
V_179 -> V_363 ++ ;
}
}
bool F_131 ( struct V_1 * V_2 ,
struct V_358 * V_319 )
{
struct V_357 V_329 = {
. V_2 = V_2 ,
. V_319 = V_319 ,
} ;
memset ( V_319 , 0 , sizeof( * V_319 ) ) ;
V_319 -> V_366 = F_20 ( V_319 -> V_364 ) ;
V_319 -> V_367 = F_20 ( V_319 -> V_361 ) ;
#ifdef F_76
if ( V_2 -> V_368 . V_369 ) {
memcpy ( V_319 -> V_364 , & V_2 -> V_368 . V_319 . V_364 ,
sizeof( V_319 -> V_364 ) ) ;
memcpy ( V_319 -> V_361 , & V_2 -> V_368 . V_319 . V_361 ,
sizeof( V_319 -> V_361 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_158 )
return false ;
F_132 (
V_2 -> V_27 , V_330 ,
F_130 , & V_329 ) ;
return true ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_191 * V_192 )
{
struct V_358 V_319 ;
if ( ! ( V_2 -> V_21 -> V_22 . V_23 & V_370 ) )
return 0 ;
if ( ! F_131 ( V_2 , & V_319 ) )
return 0 ;
return F_97 ( V_2 , V_371 , 0 ,
sizeof( V_319 ) , & V_319 ) ;
}
static inline int F_133 ( struct V_1 * V_2 ,
struct V_191 * V_192 )
{
return 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_160 * V_161 ;
struct V_69 * V_164 ;
int V_9 ;
F_63 ( & V_2 -> V_207 ) ;
for ( V_9 = 0 ; V_9 < V_169 ; V_9 ++ ) {
V_161 = F_135 ( V_2 -> V_372 [ V_9 ] ,
F_136 ( & V_2 -> V_207 ) ) ;
if ( ! V_161 || F_137 ( V_161 ) || ! V_161 -> V_373 )
continue;
V_164 = F_31 ( V_161 ) ;
F_138 ( V_164 -> V_192 , V_161 -> V_97 ,
V_374 ,
V_375 ,
V_234 ) ;
}
}
static void F_139 ( struct V_1 * V_2 ,
struct V_191 * V_192 ,
struct V_376 * V_323 ,
T_2 V_377 )
{
struct V_71 * V_212 = F_60 ( V_192 ) ;
int V_29 ;
if ( V_377 & V_378 && V_323 -> V_324 )
F_140 ( V_2 , V_192 ) ;
V_29 = F_141 ( V_2 , V_192 , false ) ;
if ( V_29 )
F_88 ( V_2 , L_14 , V_192 -> V_97 ) ;
if ( V_377 & V_378 ) {
if ( V_323 -> V_324 ) {
V_29 = F_87 ( V_2 , NULL ) ;
if ( V_29 ) {
F_88 ( V_2 , L_15 ) ;
return;
}
if ( F_13 ( V_280 ,
& V_2 -> V_14 ) ) {
T_2 V_379 = ( 11 * V_192 -> V_323 . V_380 ) / 10 ;
F_142 ( V_2 , V_192 , V_379 , V_379 ,
5 * V_379 ) ;
}
F_143 ( V_2 , V_192 , false ) ;
F_144 ( V_2 , V_192 ) ;
if ( V_192 -> V_299 )
F_1 ( V_2 , V_381 ) ;
} else if ( V_212 -> V_214 != V_169 ) {
F_145 ( F_143 ( V_2 , V_192 , false ) ,
L_16 ) ;
V_29 = F_146 ( V_2 , V_192 , V_212 -> V_214 ) ;
if ( V_29 )
F_88 ( V_2 , L_17 ) ;
if ( V_2 -> V_170 == V_212 -> V_214 )
V_2 -> V_170 = V_169 ;
V_212 -> V_214 = V_169 ;
V_29 = F_87 ( V_2 , NULL ) ;
if ( V_29 )
F_88 ( V_2 , L_15 ) ;
if ( V_192 -> V_299 )
F_7 ( V_2 , V_381 ) ;
}
F_123 ( V_2 ) ;
F_133 ( V_2 , V_192 ) ;
V_212 -> V_219 . V_382 = 0 ;
F_147 ( V_2 ) ;
F_148 ( V_2 , V_192 , V_383 ,
V_384 ) ;
} else if ( V_377 & V_385 ) {
F_149 ( V_2 , V_212 ,
& V_212 -> V_217 ) ;
}
if ( V_377 & V_385 ) {
F_143 ( V_2 , V_192 , false ) ;
F_8 ( F_150 ( V_2 , V_192 , 0 ) ) ;
}
if ( V_377 & ( V_386 | V_387 | V_388 ) ) {
V_29 = F_105 ( V_2 ) ;
if ( V_29 )
F_88 ( V_2 , L_18 ) ;
}
if ( V_377 & V_389 ) {
F_151 ( V_2 , L_19 ,
V_323 -> V_390 ) ;
F_95 ( V_2 , V_192 , V_323 -> V_390 ) ;
}
if ( V_377 & V_391 ) {
F_127 ( V_2 , L_20 ) ;
V_212 -> V_219 . V_392 = 0 ;
if ( V_212 -> V_219 . V_393 ) {
V_29 = F_150 ( V_2 , V_192 , 0 ) ;
if ( V_29 )
F_88 ( V_2 ,
L_21 ) ;
}
}
if ( V_377 & V_394 ) {
F_127 ( V_2 , L_22 ) ;
F_133 ( V_2 , V_192 ) ;
}
}
static int F_152 ( struct V_26 * V_27 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
int V_29 ;
V_29 = F_11 ( V_2 , V_395 ) ;
if ( V_29 )
return V_29 ;
F_52 ( & V_2 -> V_207 ) ;
V_29 = F_153 ( V_2 , V_192 ) ;
if ( V_29 )
goto V_293;
if ( V_192 -> type == V_78 )
F_140 ( V_2 , V_192 ) ;
V_29 = F_104 ( V_2 , V_192 ) ;
if ( V_29 )
goto V_293;
V_29 = F_108 ( V_2 , V_192 ) ;
if ( V_29 )
goto V_396;
V_29 = F_154 ( V_2 , V_192 , & V_212 -> V_295 ) ;
if ( V_29 )
goto V_306;
V_212 -> V_397 = true ;
F_105 ( V_2 ) ;
V_29 = F_87 ( V_2 , NULL ) ;
if ( V_29 )
goto V_398;
if ( V_192 -> V_299 && V_2 -> V_268 )
F_141 ( V_2 , V_2 -> V_268 , false ) ;
F_1 ( V_2 , V_399 ) ;
F_147 ( V_2 ) ;
if ( F_155 ( V_2 ) > 1 )
F_134 ( V_2 ) ;
F_58 ( & V_2 -> V_207 ) ;
return 0 ;
V_398:
F_105 ( V_2 ) ;
V_212 -> V_397 = false ;
F_156 ( V_2 , & V_212 -> V_295 ) ;
V_306:
F_110 ( V_2 , V_192 ) ;
V_396:
F_112 ( V_2 , V_192 ) ;
V_293:
F_58 ( & V_2 -> V_207 ) ;
F_7 ( V_2 , V_395 ) ;
return V_29 ;
}
static void F_157 ( struct V_26 * V_27 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
F_114 ( V_2 , V_192 ) ;
F_52 ( & V_2 -> V_207 ) ;
if ( F_158 ( V_2 -> V_400 ) == V_192 ) {
F_149 ( V_2 , V_212 ,
& V_212 -> V_217 ) ;
F_159 ( V_2 -> V_400 , NULL ) ;
}
if ( F_158 ( V_2 -> V_401 ) == V_192 ) {
F_159 ( V_2 -> V_401 , NULL ) ;
V_2 -> V_402 = 0 ;
}
V_212 -> V_397 = false ;
V_2 -> V_403 = 0 ;
F_147 ( V_2 ) ;
F_7 ( V_2 , V_399 ) ;
if ( V_192 -> V_299 && V_2 -> V_268 )
F_141 ( V_2 , V_2 -> V_268 , false ) ;
F_87 ( V_2 , NULL ) ;
F_156 ( V_2 , & V_212 -> V_295 ) ;
F_110 ( V_2 , V_192 ) ;
F_105 ( V_2 ) ;
F_112 ( V_2 , V_192 ) ;
F_58 ( & V_2 -> V_207 ) ;
}
static void
F_160 ( struct V_1 * V_2 ,
struct V_191 * V_192 ,
struct V_376 * V_323 ,
T_2 V_377 )
{
struct V_71 * V_212 = F_60 ( V_192 ) ;
if ( ! V_212 -> V_397 )
return;
if ( V_377 & ( V_404 | V_405 |
V_406 ) &&
F_141 ( V_2 , V_192 , false ) )
F_88 ( V_2 , L_14 , V_192 -> V_97 ) ;
if ( V_377 & V_407 &&
F_153 ( V_2 , V_192 ) )
F_161 ( V_2 , L_23 ) ;
}
static void F_162 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_376 * V_323 ,
T_2 V_377 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
if ( F_11 ( V_2 , V_408 ) )
return;
F_52 ( & V_2 -> V_207 ) ;
if ( V_377 & V_409 && ! V_323 -> V_410 )
F_163 ( V_2 , true ) ;
switch ( V_192 -> type ) {
case V_76 :
F_139 ( V_2 , V_192 , V_323 , V_377 ) ;
break;
case V_78 :
case V_81 :
F_160 ( V_2 , V_192 , V_323 , V_377 ) ;
break;
default:
F_14 ( 1 ) ;
}
F_58 ( & V_2 -> V_207 ) ;
F_7 ( V_2 , V_408 ) ;
}
static int F_164 ( struct V_1 * V_2 ,
enum V_411 V_412 )
{
int V_29 ;
bool V_413 = false ;
F_52 ( & V_2 -> V_207 ) ;
if ( V_2 -> V_265 != V_412 ) {
V_29 = 0 ;
V_413 = true ;
goto V_167;
}
switch ( V_412 ) {
case V_414 :
V_29 = F_163 ( V_2 , true ) ;
break;
case V_415 :
V_29 = F_165 ( V_2 ) ;
break;
case V_266 :
default:
F_14 ( 1 ) ;
V_29 = - V_209 ;
break;
}
if ( V_29 )
goto V_167;
V_413 = true ;
V_167:
F_58 ( & V_2 -> V_207 ) ;
if ( V_413 )
F_166 ( V_2 ) ;
return V_29 ;
}
static int F_167 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_418 * V_419 = & V_417 -> V_419 ;
int V_29 ;
if ( V_419 -> V_109 == 0 ||
V_419 -> V_109 > V_2 -> V_21 -> V_22 . V_420 )
return - V_209 ;
V_29 = F_164 ( V_2 , V_414 ) ;
if ( V_29 )
return V_29 ;
F_52 ( & V_2 -> V_207 ) ;
if ( V_2 -> V_265 != V_266 ) {
V_29 = - V_421 ;
goto V_167;
}
F_1 ( V_2 , V_422 ) ;
if ( V_2 -> V_21 -> V_22 . V_65 [ 0 ] & V_66 )
V_29 = F_168 ( V_2 , V_192 , V_417 ) ;
else
V_29 = F_169 ( V_2 , V_192 , V_419 ) ;
if ( V_29 )
F_7 ( V_2 , V_422 ) ;
V_167:
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
static void F_170 ( struct V_26 * V_27 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
F_52 ( & V_2 -> V_207 ) ;
F_165 ( V_2 ) ;
F_58 ( & V_2 -> V_207 ) ;
}
static void
F_171 ( struct V_26 * V_27 ,
struct V_160 * V_161 , V_73 V_423 ,
int V_424 ,
enum V_425 V_426 ,
bool V_427 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
F_172 ( V_2 , V_161 , V_426 , V_424 ,
V_423 , V_427 , false ) ;
}
static void
F_173 ( struct V_26 * V_27 ,
struct V_160 * V_161 , V_73 V_423 ,
int V_424 ,
enum V_425 V_426 ,
bool V_427 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
F_172 ( V_2 , V_161 , V_426 , V_424 ,
V_423 , V_427 , true ) ;
}
static void F_174 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
enum V_428 V_319 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_69 * V_164 = F_31 ( V_161 ) ;
int V_195 ;
switch ( V_319 ) {
case V_429 :
if ( F_175 ( & V_2 -> V_430 [ V_164 -> V_168 ] ) > 0 )
F_176 ( V_27 , V_161 , true ) ;
F_4 ( & V_164 -> V_431 ) ;
for ( V_195 = 0 ; V_195 < V_432 ; V_195 ++ ) {
struct V_433 * V_434 ;
V_434 = & V_164 -> V_434 [ V_195 ] ;
if ( V_434 -> V_435 != V_436 &&
V_434 -> V_435 != V_437 )
continue;
if ( F_177 ( V_434 ) == 0 )
continue;
F_178 ( V_161 , V_195 , true ) ;
}
F_5 ( & V_164 -> V_431 ) ;
break;
case V_438 :
if ( F_8 ( V_164 -> V_168 == V_169 ) )
break;
F_179 ( V_2 , V_161 ) ;
break;
default:
break;
}
}
static void F_180 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_69 * V_439 = ( void * ) V_161 -> V_440 ;
F_52 ( & V_2 -> V_207 ) ;
if ( V_161 == F_158 ( V_2 -> V_372 [ V_439 -> V_168 ] ) )
F_181 ( V_2 -> V_372 [ V_439 -> V_168 ] ,
F_182 ( - V_441 ) ) ;
F_58 ( & V_2 -> V_207 ) ;
}
int F_183 ( struct V_1 * V_2 , struct V_191 * V_192 )
{
struct V_160 * V_161 ;
struct V_69 * V_164 ;
int V_326 = 0 ;
int V_9 ;
F_63 ( & V_2 -> V_207 ) ;
for ( V_9 = 0 ; V_9 < V_169 ; V_9 ++ ) {
V_161 = F_135 ( V_2 -> V_372 [ V_9 ] ,
F_136 ( & V_2 -> V_207 ) ) ;
if ( ! V_161 || F_137 ( V_161 ) || ! V_161 -> V_373 )
continue;
if ( V_192 ) {
V_164 = F_31 ( V_161 ) ;
if ( V_164 -> V_192 != V_192 )
continue;
}
V_326 ++ ;
}
return V_326 ;
}
static void F_184 ( struct V_1 * V_2 ,
struct V_191 * V_192 ,
bool V_442 )
{
int V_443 = F_183 ( V_2 , V_192 ) ;
if ( ( V_443 == 1 && V_442 ) ||
( V_443 == 0 && ! V_442 ) )
F_105 ( V_2 ) ;
}
static int F_185 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_160 * V_161 ,
enum V_444 V_445 ,
enum V_444 V_446 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
int V_29 ;
F_127 ( V_2 , L_24 ,
V_161 -> V_97 , V_445 , V_446 ) ;
if ( F_14 ( ! V_212 -> V_218 ) )
return - V_209 ;
F_90 ( & V_2 -> V_312 ) ;
F_52 ( & V_2 -> V_207 ) ;
if ( V_445 == V_447 &&
V_446 == V_448 ) {
if ( V_192 -> type == V_76 &&
V_192 -> V_323 . V_380 < 16 ) {
F_88 ( V_2 ,
L_25 ,
V_161 -> V_97 , V_192 -> V_323 . V_380 ) ;
V_29 = - V_209 ;
goto V_293;
}
if ( V_161 -> V_373 &&
( V_192 -> V_299 ||
F_183 ( V_2 , NULL ) ==
V_449 ||
F_155 ( V_2 ) > 1 ) ) {
F_127 ( V_2 , L_26 ) ;
V_29 = - V_421 ;
goto V_293;
}
V_29 = F_186 ( V_2 , V_192 , V_161 ) ;
if ( V_161 -> V_373 && V_29 == 0 )
F_184 ( V_2 , V_192 , true ) ;
} else if ( V_445 == V_448 &&
V_446 == V_450 ) {
V_2 -> V_451 = true ;
V_29 = 0 ;
} else if ( V_445 == V_450 &&
V_446 == V_452 ) {
V_29 = F_187 ( V_2 , V_192 , V_161 ) ;
if ( V_29 == 0 )
F_188 ( V_2 , V_161 ,
V_212 -> V_218 -> V_453 -> V_454 ,
true ) ;
} else if ( V_445 == V_452 &&
V_446 == V_455 ) {
if ( F_155 ( V_2 ) > 1 )
F_134 ( V_2 ) ;
F_8 ( F_150 ( V_2 , V_192 , 0 ) ) ;
V_29 = 0 ;
} else if ( V_445 == V_455 &&
V_446 == V_452 ) {
F_8 ( F_106 ( V_2 , V_192 , 0 ) ) ;
V_29 = 0 ;
} else if ( V_445 == V_452 &&
V_446 == V_450 ) {
V_29 = 0 ;
} else if ( V_445 == V_450 &&
V_446 == V_448 ) {
V_29 = 0 ;
} else if ( V_445 == V_448 &&
V_446 == V_447 ) {
V_29 = F_189 ( V_2 , V_192 , V_161 ) ;
if ( V_161 -> V_373 )
F_184 ( V_2 , V_192 , false ) ;
} else {
V_29 = - V_16 ;
}
V_293:
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
static int F_190 ( struct V_26 * V_27 , T_2 V_456 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
V_2 -> V_127 = V_456 ;
return 0 ;
}
static void F_191 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_160 * V_161 , T_2 V_315 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
if ( V_192 -> type == V_76 &&
V_315 & V_457 )
F_143 ( V_2 , V_192 , false ) ;
}
static int F_192 ( struct V_26 * V_27 ,
struct V_191 * V_192 , V_73 V_308 ,
const struct V_458 * V_459 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
V_212 -> V_460 [ V_308 ] = * V_459 ;
if ( V_192 -> type == V_80 ) {
int V_29 ;
F_52 ( & V_2 -> V_207 ) ;
V_29 = F_141 ( V_2 , V_192 , false ) ;
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
return 0 ;
}
static void F_193 ( struct V_26 * V_27 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
T_2 V_461 = F_21 ( V_462 ,
200 + V_192 -> V_323 . V_380 ) ;
T_2 V_463 = F_21 ( V_464 ,
100 + V_192 -> V_323 . V_380 ) ;
if ( F_14 ( V_192 -> V_323 . V_324 ) )
return;
if ( F_11 ( V_2 , V_465 ) )
return;
F_52 ( & V_2 -> V_207 ) ;
F_142 ( V_2 , V_192 , V_461 , V_463 , 500 ) ;
F_58 ( & V_2 -> V_207 ) ;
F_7 ( V_2 , V_465 ) ;
}
static void F_194 ( struct V_26 * V_27 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
T_2 V_461 = 2 * V_192 -> V_323 . V_466 * V_192 -> V_323 . V_380 ;
if ( F_11 ( V_2 , V_467 ) )
return;
F_52 ( & V_2 -> V_207 ) ;
F_142 ( V_2 , V_192 , V_461 , V_461 , 100 ) ;
F_58 ( & V_2 -> V_207 ) ;
F_7 ( V_2 , V_467 ) ;
}
static int F_195 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_468 * V_419 ,
struct V_469 * V_470 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
V_29 = F_164 ( V_2 , V_415 ) ;
if ( V_29 )
return V_29 ;
F_52 ( & V_2 -> V_207 ) ;
if ( ! F_196 ( V_2 ) ) {
V_29 = - V_421 ;
goto V_167;
}
if ( V_2 -> V_265 != V_266 ) {
V_29 = - V_421 ;
goto V_167;
}
V_2 -> V_265 = V_414 ;
if ( ! ( V_2 -> V_21 -> V_22 . V_65 [ 0 ] & V_66 ) ) {
V_29 = F_197 ( V_2 , V_192 , V_419 , V_470 ) ;
if ( V_29 )
goto V_471;
}
V_29 = F_198 ( V_2 , V_419 ) ;
if ( V_29 )
goto V_471;
if ( V_2 -> V_21 -> V_22 . V_65 [ 0 ] & V_66 )
V_29 = F_199 ( V_2 , V_192 , V_419 , V_470 ) ;
else
V_29 = F_200 ( V_2 , V_419 ) ;
if ( ! V_29 )
goto V_167;
V_471:
V_2 -> V_265 = V_266 ;
V_167:
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
static int F_201 ( struct V_26 * V_27 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
F_52 ( & V_2 -> V_207 ) ;
V_29 = F_163 ( V_2 , false ) ;
F_58 ( & V_2 -> V_207 ) ;
F_166 ( V_2 ) ;
return V_29 ;
}
static int F_202 ( struct V_26 * V_27 ,
enum V_472 V_319 ,
struct V_191 * V_192 ,
struct V_160 * V_161 ,
struct V_473 * V_474 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
if ( V_54 . V_55 ) {
F_127 ( V_2 , L_27 ) ;
return - V_475 ;
}
switch ( V_474 -> V_130 ) {
case V_476 :
V_474 -> V_23 |= V_477 ;
case V_478 :
V_474 -> V_23 |= V_479 ;
break;
case V_480 :
F_14 ( ! ( V_27 -> V_23 & V_56 ) ) ;
break;
case V_481 :
case V_482 :
return 0 ;
default:
if ( V_27 -> V_131 &&
V_27 -> V_132 -> V_130 == V_474 -> V_130 )
V_474 -> V_23 |= V_483 ;
else
return - V_475 ;
}
F_52 ( & V_2 -> V_207 ) ;
switch ( V_319 ) {
case V_484 :
if ( ( V_192 -> type == V_81 ||
V_192 -> type == V_78 ) && ! V_161 ) {
V_29 = 0 ;
V_474 -> V_485 = V_486 ;
break;
}
F_127 ( V_2 , L_28 ) ;
V_29 = F_203 ( V_2 , V_192 , V_161 , V_474 , false ) ;
if ( V_29 ) {
F_161 ( V_2 , L_29 ) ;
V_474 -> V_485 = V_486 ;
V_29 = 0 ;
}
break;
case V_487 :
if ( V_474 -> V_485 == V_486 ) {
V_29 = 0 ;
break;
}
F_127 ( V_2 , L_30 ) ;
V_29 = F_204 ( V_2 , V_192 , V_161 , V_474 ) ;
break;
default:
V_29 = - V_209 ;
}
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
static void F_205 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_473 * V_488 ,
struct V_160 * V_161 ,
T_2 V_489 , V_73 * V_490 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
if ( V_488 -> V_485 == V_486 )
return;
F_206 ( V_2 , V_192 , V_488 , V_161 , V_489 , V_490 ) ;
}
static bool F_207 ( struct V_491 * V_492 ,
struct V_493 * V_494 , void * V_179 )
{
struct V_1 * V_2 =
F_208 ( V_492 , struct V_1 , V_492 ) ;
struct V_495 * V_496 ;
int V_497 = F_209 ( V_494 ) ;
struct V_498 * V_499 = V_179 ;
if ( F_8 ( V_494 -> V_178 . V_319 != V_500 ) )
return true ;
if ( F_14 ( V_497 != sizeof( * V_496 ) ) ) {
F_88 ( V_2 , L_31 ) ;
return true ;
}
V_496 = ( void * ) V_494 -> V_179 ;
F_210 ( V_2 ,
L_32 ,
V_496 -> V_14 , V_496 -> V_501 ) ;
V_499 -> V_502 = F_211 ( V_496 -> V_501 ) ;
F_210 ( V_2 , L_33 ,
V_499 -> V_502 ) ;
F_4 ( & V_2 -> V_216 ) ;
F_212 ( & V_499 -> V_503 , & V_2 -> V_504 ) ;
F_5 ( & V_2 -> V_216 ) ;
return true ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_505 * V_453 ,
struct V_191 * V_192 ,
int V_461 )
{
int V_506 , V_507 = V_508 ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
struct V_498 * V_499 = & V_212 -> V_509 ;
static const T_1 V_510 [] = { V_500 } ;
struct V_511 V_512 ;
struct V_513 V_514 = {
. V_194 = F_68 ( V_515 ) ,
. V_516 =
F_68 ( F_214 ( V_517 , 0 ) ) ,
. V_518 = F_68 ( V_2 -> V_284 . V_168 ) ,
. V_519 . V_454 = ( V_453 -> V_454 == V_108 ) ?
V_520 : V_521 ,
. V_519 . V_453 = V_453 -> V_522 ,
. V_519 . V_523 = V_524 ,
. V_525 = F_68 ( F_215 ( V_2 -> V_7 , V_507 ) ) ,
. V_526 =
F_68 ( F_216 ( V_527 ) ) ,
. V_461 = F_68 ( F_216 ( V_461 ) ) ,
} ;
memcpy ( V_514 . V_528 , V_192 -> V_97 , V_100 ) ;
V_499 -> V_192 = V_192 ;
V_499 -> V_461 = V_461 ;
V_499 -> V_19 = V_500 ;
F_63 ( & V_2 -> V_207 ) ;
F_4 ( & V_2 -> V_216 ) ;
F_212 ( & V_499 -> V_503 , & V_2 -> V_529 ) ;
F_5 ( & V_2 -> V_216 ) ;
F_217 ( & V_2 -> V_492 , & V_512 ,
V_510 ,
F_20 ( V_510 ) ,
F_207 , V_499 ) ;
V_506 = F_97 ( V_2 , V_500 , 0 , sizeof( V_514 ) ,
& V_514 ) ;
if ( V_506 ) {
F_88 ( V_2 , L_34 , V_506 ) ;
F_218 ( & V_2 -> V_492 , & V_512 ) ;
goto V_530;
}
V_506 = F_219 ( & V_2 -> V_492 , & V_512 , 1 ) ;
F_14 ( V_506 ) ;
if ( V_506 ) {
V_530:
F_4 ( & V_2 -> V_216 ) ;
F_61 ( V_2 , V_499 ) ;
F_5 ( & V_2 -> V_216 ) ;
}
return V_506 ;
}
static int F_220 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_505 * V_453 ,
int V_461 ,
enum V_531 type )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
struct V_532 V_533 ;
struct V_285 * V_218 ;
int V_29 , V_9 ;
F_127 ( V_2 , L_35 , V_453 -> V_522 ,
V_461 , type ) ;
switch ( V_192 -> type ) {
case V_76 :
V_29 = F_213 ( V_2 , V_453 ,
V_192 , V_461 ) ;
return V_29 ;
case V_80 :
break;
default:
F_88 ( V_2 , L_36 , V_192 -> type ) ;
return - V_209 ;
}
F_52 ( & V_2 -> V_207 ) ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
V_218 = & V_2 -> V_17 [ V_9 ] ;
if ( V_218 -> V_20 == 0 || V_212 -> V_218 == V_218 )
continue;
if ( V_218 -> V_20 && V_453 == V_218 -> V_453 ) {
V_29 = F_110 ( V_2 , V_192 ) ;
if ( F_221 ( V_29 , L_37 ) )
goto V_293;
F_111 ( V_2 , V_212 -> V_218 ) ;
V_212 -> V_218 = V_218 ;
V_29 = F_108 ( V_2 , V_192 ) ;
if ( F_221 ( V_29 , L_38 ) )
goto V_293;
F_107 ( V_2 , V_212 -> V_218 ) ;
goto V_534;
}
}
if ( V_453 == V_212 -> V_218 -> V_453 )
goto V_534;
F_222 ( & V_533 , V_453 , V_535 ) ;
if ( V_212 -> V_218 -> V_20 == 1 ) {
V_29 = F_223 ( V_2 , V_212 -> V_218 ,
& V_533 , 1 , 1 ) ;
if ( V_29 )
goto V_293;
} else {
V_218 = F_94 ( V_2 ) ;
if ( ! V_218 ) {
V_29 = - V_303 ;
goto V_293;
}
V_29 = F_223 ( V_2 , V_218 , & V_533 ,
1 , 1 ) ;
if ( V_29 ) {
F_88 ( V_2 , L_39 ) ;
goto V_293;
}
V_29 = F_110 ( V_2 , V_192 ) ;
if ( F_221 ( V_29 , L_37 ) )
goto V_293;
F_111 ( V_2 , V_212 -> V_218 ) ;
V_212 -> V_218 = V_218 ;
V_29 = F_108 ( V_2 , V_192 ) ;
if ( F_221 ( V_29 , L_38 ) )
goto V_293;
F_107 ( V_2 , V_212 -> V_218 ) ;
}
V_534:
V_29 = F_224 ( V_2 , V_192 , V_461 , type ) ;
V_293:
F_58 ( & V_2 -> V_207 ) ;
F_127 ( V_2 , L_40 ) ;
return V_29 ;
}
static int F_225 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
F_127 ( V_2 , L_41 ) ;
F_52 ( & V_2 -> V_207 ) ;
F_226 ( V_2 ) ;
F_58 ( & V_2 -> V_207 ) ;
F_127 ( V_2 , L_40 ) ;
return 0 ;
}
static int F_227 ( struct V_1 * V_2 ,
struct V_536 * V_537 )
{
V_73 * V_538 = ( V_73 * ) V_537 -> V_440 ;
struct V_285 * V_218 ;
int V_29 ;
F_63 ( & V_2 -> V_207 ) ;
F_127 ( V_2 , L_42 ) ;
V_218 = F_94 ( V_2 ) ;
if ( ! V_218 ) {
V_29 = - V_303 ;
goto V_167;
}
V_29 = F_223 ( V_2 , V_218 , & V_537 -> V_539 ,
V_537 -> V_540 ,
V_537 -> V_541 ) ;
if ( V_29 ) {
F_88 ( V_2 , L_43 ) ;
goto V_167;
}
F_107 ( V_2 , V_218 ) ;
* V_538 = V_218 -> V_19 ;
V_167:
return V_29 ;
}
static int F_228 ( struct V_26 * V_27 ,
struct V_536 * V_537 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
F_52 ( & V_2 -> V_207 ) ;
V_29 = F_227 ( V_2 , V_537 ) ;
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
static void F_229 ( struct V_1 * V_2 ,
struct V_536 * V_537 )
{
V_73 * V_538 = ( V_73 * ) V_537 -> V_440 ;
struct V_285 * V_218 = & V_2 -> V_17 [ * V_538 ] ;
F_63 ( & V_2 -> V_207 ) ;
F_111 ( V_2 , V_218 ) ;
}
static void F_230 ( struct V_26 * V_27 ,
struct V_536 * V_537 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
F_52 ( & V_2 -> V_207 ) ;
F_229 ( V_2 , V_537 ) ;
F_58 ( & V_2 -> V_207 ) ;
}
static void F_231 ( struct V_26 * V_27 ,
struct V_536 * V_537 ,
T_2 V_315 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
V_73 * V_538 = ( V_73 * ) V_537 -> V_440 ;
struct V_285 * V_218 = & V_2 -> V_17 [ * V_538 ] ;
if ( F_145 ( ( V_218 -> V_20 > 1 ) &&
( V_315 & ~ ( V_542 |
V_543 |
V_544 |
V_545 ) ) ,
L_44 ,
V_218 -> V_20 , V_315 ) )
return;
F_52 ( & V_2 -> V_207 ) ;
F_147 ( V_2 ) ;
F_223 ( V_2 , V_218 , & V_537 -> V_539 ,
V_537 -> V_540 ,
V_537 -> V_541 ) ;
F_58 ( & V_2 -> V_207 ) ;
}
static int F_232 ( struct V_1 * V_2 ,
struct V_191 * V_192 ,
struct V_536 * V_537 ,
bool V_546 )
{
V_73 * V_538 = ( V_73 * ) V_537 -> V_440 ;
struct V_285 * V_218 = & V_2 -> V_17 [ * V_538 ] ;
struct V_71 * V_212 = F_60 ( V_192 ) ;
int V_29 ;
F_63 ( & V_2 -> V_207 ) ;
V_212 -> V_218 = V_218 ;
switch ( V_192 -> type ) {
case V_78 :
if ( V_192 -> V_547 ) {
V_212 -> V_397 = true ;
break;
}
case V_81 :
V_29 = 0 ;
goto V_167;
case V_76 :
case V_548 :
break;
default:
V_29 = - V_209 ;
goto V_167;
}
V_29 = F_108 ( V_2 , V_192 ) ;
if ( V_29 )
goto V_167;
F_105 ( V_2 ) ;
if ( V_192 -> type == V_548 ) {
V_212 -> V_549 = true ;
V_29 = F_87 ( V_2 , NULL ) ;
if ( V_29 )
goto V_550;
}
if ( ( V_192 -> type == V_78 ) ||
( V_546 && ( V_192 -> type == V_76 ) ) ) {
F_87 ( V_2 , NULL ) ;
F_141 ( V_2 , V_192 , false ) ;
}
goto V_167;
V_550:
F_110 ( V_2 , V_192 ) ;
F_105 ( V_2 ) ;
V_167:
if ( V_29 )
V_212 -> V_218 = NULL ;
return V_29 ;
}
static int F_233 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_536 * V_537 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
F_52 ( & V_2 -> V_207 ) ;
V_29 = F_232 ( V_2 , V_192 , V_537 , false ) ;
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
static void F_234 ( struct V_1 * V_2 ,
struct V_191 * V_192 ,
struct V_536 * V_537 ,
bool V_546 )
{
struct V_71 * V_212 = F_60 ( V_192 ) ;
struct V_191 * V_551 = NULL ;
F_63 ( & V_2 -> V_207 ) ;
F_149 ( V_2 , V_212 , & V_212 -> V_217 ) ;
switch ( V_192 -> type ) {
case V_81 :
goto V_167;
case V_548 :
V_212 -> V_549 = false ;
break;
case V_78 :
if ( ! V_192 -> V_547 || ! V_212 -> V_397 )
goto V_167;
F_235 ( V_2 , V_212 , true ) ;
F_181 ( V_2 -> V_401 , V_192 ) ;
V_212 -> V_397 = false ;
break;
case V_76 :
if ( ! V_546 )
break;
V_551 = V_192 ;
F_141 ( V_2 , V_192 , true ) ;
break;
default:
break;
}
F_87 ( V_2 , V_551 ) ;
F_110 ( V_2 , V_192 ) ;
V_167:
V_212 -> V_218 = NULL ;
F_105 ( V_2 ) ;
}
static void F_236 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_536 * V_537 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
F_52 ( & V_2 -> V_207 ) ;
F_234 ( V_2 , V_192 , V_537 , false ) ;
F_58 ( & V_2 -> V_207 ) ;
}
static int F_237 ( struct V_26 * V_27 ,
struct V_552 * V_553 ,
int V_554 ,
enum V_555 V_556 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_29 ;
if ( V_556 != V_557 || V_554 > 1 )
return - V_475 ;
F_52 ( & V_2 -> V_207 ) ;
F_234 ( V_2 , V_553 [ 0 ] . V_192 , V_553 [ 0 ] . V_558 , true ) ;
F_229 ( V_2 , V_553 [ 0 ] . V_558 ) ;
V_29 = F_227 ( V_2 , V_553 [ 0 ] . V_559 ) ;
if ( V_29 ) {
F_88 ( V_2 , L_45 ) ;
goto V_560;
}
V_29 = F_232 ( V_2 , V_553 [ 0 ] . V_192 , V_553 [ 0 ] . V_559 ,
true ) ;
if ( V_29 ) {
F_88 ( V_2 ,
L_46 ) ;
goto V_396;
}
if ( F_155 ( V_2 ) > 1 )
F_134 ( V_2 ) ;
goto V_167;
V_396:
F_229 ( V_2 , V_553 [ 0 ] . V_559 ) ;
V_560:
V_29 = F_227 ( V_2 , V_553 [ 0 ] . V_558 ) ;
if ( V_29 ) {
F_88 ( V_2 , L_47 ) ;
goto V_561;
}
V_29 = F_232 ( V_2 , V_553 [ 0 ] . V_192 , V_553 [ 0 ] . V_558 ,
true ) ;
if ( V_29 ) {
F_88 ( V_2 , L_48 ) ;
goto V_561;
}
goto V_167;
V_561:
F_238 ( V_2 , false ) ;
V_167:
F_58 ( & V_2 -> V_207 ) ;
return V_29 ;
}
static int F_239 ( struct V_26 * V_27 ,
struct V_160 * V_161 ,
bool V_562 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_69 * V_439 = ( void * ) V_161 -> V_440 ;
if ( ! V_439 || ! V_439 -> V_192 ) {
F_88 ( V_2 , L_49 ) ;
return - V_209 ;
}
return F_153 ( V_2 , V_439 -> V_192 ) ;
}
static int F_240 ( struct V_1 * V_2 ,
struct V_191 * V_192 ,
void * V_179 , int V_139 )
{
struct V_563 * V_564 [ V_565 + 1 ] ;
int V_471 ;
T_2 V_314 ;
V_471 = F_241 ( V_564 , V_565 , V_179 , V_139 , V_566 ) ;
if ( V_471 )
return V_471 ;
if ( ! V_564 [ V_567 ] )
return - V_209 ;
switch ( F_242 ( V_564 [ V_567 ] ) ) {
case V_568 :
if ( ! V_192 || V_192 -> type != V_78 || ! V_192 -> V_299 ||
! V_192 -> V_323 . V_569 ||
! V_564 [ V_570 ] )
return - V_209 ;
V_314 = F_242 ( V_564 [ V_570 ] ) ;
if ( V_314 >= V_192 -> V_323 . V_380 )
return - V_209 ;
V_2 -> V_314 = V_314 ;
V_2 -> V_313 = V_192 ;
return F_87 ( V_2 , NULL ) ;
case V_571 :
if ( ! V_192 || V_192 -> type != V_76 ||
! V_192 -> V_323 . V_324 || ! V_192 -> V_323 . V_466 ||
! V_564 [ V_572 ] )
return - V_209 ;
if ( F_242 ( V_564 [ V_572 ] ) )
return F_150 ( V_2 , V_192 , 0 ) ;
return F_106 ( V_2 , V_192 , 0 ) ;
}
return - V_475 ;
}
static int F_243 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
void * V_179 , int V_139 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
int V_471 ;
F_52 ( & V_2 -> V_207 ) ;
V_471 = F_240 ( V_2 , V_192 , V_179 , V_139 ) ;
F_58 ( & V_2 -> V_207 ) ;
return V_471 ;
}
static void F_244 ( struct V_26 * V_27 ,
struct V_191 * V_192 ,
struct V_532 * V_533 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_191 * V_400 ;
F_52 ( & V_2 -> V_207 ) ;
V_400 = F_135 ( V_2 -> V_400 ,
F_136 ( & V_2 -> V_207 ) ) ;
if ( F_221 ( V_400 && V_400 -> V_547 ,
L_50 ) )
goto V_293;
F_127 ( V_2 , L_51 ,
V_533 -> V_573 ) ;
F_181 ( V_2 -> V_400 , V_192 ) ;
V_293:
F_58 ( & V_2 -> V_207 ) ;
}
static void F_245 ( struct V_26 * V_27 ,
struct V_191 * V_192 , T_2 V_43 , bool V_180 )
{
struct V_1 * V_2 = F_36 ( V_27 ) ;
struct V_71 * V_212 ;
struct V_69 * V_164 ;
if ( ! V_192 || V_192 -> type != V_76 )
return;
F_52 ( & V_2 -> V_207 ) ;
V_212 = F_60 ( V_192 ) ;
V_164 = F_246 ( V_2 , V_212 -> V_214 ) ;
if ( F_14 ( ! V_164 ) )
goto V_574;
if ( V_180 ) {
if ( F_115 ( V_2 , V_164 -> V_575 , true ) )
F_88 ( V_2 , L_52 ) ;
} else {
F_247 ( V_2 -> V_7 ,
V_164 -> V_575 ) ;
}
V_574:
F_58 ( & V_2 -> V_207 ) ;
}
