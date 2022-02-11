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
F_41 ( F_42 ( V_2 -> V_94 ) < F_42 ( V_51 ) + 2 ) ;
memcpy ( V_2 -> V_94 , V_51 , sizeof( V_51 ) ) ;
V_30 -> V_23 -> V_95 = F_42 ( V_51 ) ;
V_30 -> V_23 -> V_96 = V_2 -> V_94 ;
if ( V_2 -> V_97 -> V_98 . V_99 & V_100 &&
! V_101 . V_102 ) {
F_38 ( V_30 , V_103 ) ;
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] =
V_104 ;
V_30 -> V_23 -> V_95 ++ ;
}
if ( V_2 -> V_97 -> V_105 [ 0 ] . V_106 ) {
V_2 -> V_30 -> V_107 = 1 ;
V_2 -> V_30 -> V_108 = & V_2 -> V_97 -> V_105 [ 0 ] ;
V_2 -> V_94 [ V_30 -> V_23 -> V_95 ] =
V_2 -> V_97 -> V_105 [ 0 ] . V_106 ;
V_30 -> V_23 -> V_95 ++ ;
}
F_38 ( V_30 , V_109 ) ;
V_30 -> V_23 -> V_110 |=
V_111 |
V_112 |
V_113 ;
V_30 -> V_114 = sizeof( struct V_115 ) ;
V_30 -> V_116 = sizeof( struct V_117 ) ;
V_30 -> V_118 = sizeof( V_119 ) ;
V_30 -> V_23 -> V_120 = F_43 ( V_121 ) |
F_43 ( V_122 ) |
F_43 ( V_123 ) |
F_43 ( V_124 ) |
F_43 ( V_125 ) |
F_43 ( V_126 ) ;
V_30 -> V_23 -> V_99 |= V_127 ;
V_30 -> V_23 -> V_128 |= V_129 ;
if ( F_30 ( V_2 ) )
V_30 -> V_23 -> V_128 |= V_130 ;
else
V_30 -> V_23 -> V_128 |= V_131 |
V_132 ;
if ( V_2 -> V_97 -> V_98 . V_99 & V_133 )
V_30 -> V_23 -> V_99 |= V_134 ;
V_30 -> V_23 -> V_99 |= V_135 ;
V_30 -> V_23 -> V_136 = V_137 ;
V_30 -> V_23 -> V_138 =
F_42 ( V_137 ) ;
V_30 -> V_23 -> V_139 = 10000 ;
V_30 -> V_140 = V_141 ;
V_30 -> V_23 -> V_142 = 3 * 5 ;
memcpy ( V_2 -> V_143 [ 0 ] . V_144 , V_2 -> V_145 -> V_146 , V_147 ) ;
V_30 -> V_23 -> V_143 = V_2 -> V_143 ;
V_30 -> V_23 -> V_148 = 1 ;
V_50 = ( V_2 -> V_145 -> V_149 > 1 ) ?
F_44 ( V_150 , V_2 -> V_145 -> V_149 ) : 1 ;
for ( V_9 = 1 ; V_9 < V_50 ; V_9 ++ ) {
memcpy ( V_2 -> V_143 [ V_9 ] . V_144 , V_2 -> V_143 [ V_9 - 1 ] . V_144 ,
V_147 ) ;
V_2 -> V_143 [ V_9 ] . V_144 [ 5 ] ++ ;
V_30 -> V_23 -> V_148 ++ ;
}
F_16 ( V_2 ) ;
V_30 -> V_23 -> V_151 = F_45 ( V_2 ) ;
V_30 -> V_23 -> V_152 = V_153 ;
F_41 ( V_154 & V_155 ) ;
F_41 ( V_156 > F_46 ( V_155 ) ||
V_157 > F_46 ( V_155 ) ) ;
if ( F_47 ( & V_2 -> V_97 -> V_98 , V_158 ) )
V_2 -> V_159 = V_156 ;
else
V_2 -> V_159 = V_157 ;
if ( V_2 -> V_145 -> V_160 [ V_161 ] . V_38 )
V_30 -> V_23 -> V_160 [ V_161 ] =
& V_2 -> V_145 -> V_160 [ V_161 ] ;
if ( V_2 -> V_145 -> V_160 [ V_162 ] . V_38 ) {
V_30 -> V_23 -> V_160 [ V_162 ] =
& V_2 -> V_145 -> V_160 [ V_162 ] ;
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_163 ) &&
F_48 ( & V_2 -> V_97 -> V_98 ,
V_164 ) )
V_30 -> V_23 -> V_160 [ V_162 ] -> V_165 . V_166 |=
V_167 ;
}
V_30 -> V_23 -> V_168 = V_2 -> V_7 -> V_169 ;
if ( V_170 . V_171 != V_172 )
V_30 -> V_23 -> V_99 |= V_173 ;
else
V_30 -> V_23 -> V_99 &= ~ V_173 ;
V_30 -> V_23 -> V_99 |= V_174 ;
V_30 -> V_23 -> V_175 = V_153 ;
V_30 -> V_23 -> V_176 = V_177 ;
V_30 -> V_23 -> V_178 =
V_179 - 24 - 2 ;
V_30 -> V_23 -> V_180 = V_181 ;
V_30 -> V_23 -> V_182 = V_183 ;
V_30 -> V_23 -> V_184 = 254 ;
V_30 -> V_23 -> V_110 |= V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 ;
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_191 ) )
V_30 -> V_23 -> V_110 |= V_192 ;
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_193 ) )
V_30 -> V_23 -> V_110 |= V_194 ;
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_195 ) )
V_30 -> V_23 -> V_110 |=
V_196 ;
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_197 ) )
V_30 -> V_23 -> V_110 |= V_198 ;
V_2 -> V_199 = V_200 ;
#ifdef F_49
if ( F_2 ( V_2 ) &&
F_50 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_201 . V_99 = V_202 ;
V_30 -> V_23 -> V_201 = & V_2 -> V_201 ;
}
if ( V_2 -> V_97 -> V_203 [ V_204 ] . V_205 [ 0 ] . V_206 &&
V_2 -> V_7 -> V_207 -> V_208 &&
V_2 -> V_7 -> V_207 -> V_209 &&
F_50 ( V_2 -> V_7 -> V_36 ) ) {
V_2 -> V_201 . V_99 |= V_210 |
V_211 |
V_212 |
V_213 |
V_214 ;
if ( ! V_101 . V_102 )
V_2 -> V_201 . V_99 |= V_215 |
V_216 |
V_217 ;
V_2 -> V_201 . V_218 = V_219 ;
V_2 -> V_201 . V_220 = V_221 ;
V_2 -> V_201 . V_222 = V_223 ;
V_2 -> V_201 . V_224 = V_177 ;
V_2 -> V_201 . V_225 = & V_226 ;
V_30 -> V_23 -> V_201 = & V_2 -> V_201 ;
}
#endif
#ifdef F_51
V_2 -> V_227 = V_228 ;
#endif
V_47 = F_52 ( V_2 ) ;
if ( V_47 )
return V_47 ;
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_229 ) ) {
F_53 ( V_2 , L_10 ) ;
V_30 -> V_23 -> V_99 |= V_230 ;
F_38 ( V_30 , V_231 ) ;
}
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_232 ) ) {
F_53 ( V_2 , L_11 ) ;
V_30 -> V_23 -> V_110 |= V_233 ;
}
V_30 -> V_75 |= V_2 -> V_37 -> V_110 ;
if ( ! F_54 ( V_2 ) ) {
V_30 -> V_75 &= ~ ( V_234 |
V_235 ) ;
if ( V_236 )
V_30 -> V_75 |= V_234 ;
}
V_47 = F_55 ( V_2 -> V_30 ) ;
if ( V_47 )
F_56 ( V_2 ) ;
return V_47 ;
}
static bool F_57 ( struct V_1 * V_2 ,
struct V_237 * V_238 ,
struct V_239 * V_240 )
{
struct V_115 * V_241 ;
bool V_242 = false ;
if ( F_58 ( ! F_14 ( V_14 , & V_2 -> V_15 ) ) )
return false ;
F_59 ( & V_2 -> V_243 ) ;
if ( ! F_14 ( V_14 , & V_2 -> V_15 ) )
goto V_34;
V_241 = F_60 ( V_238 ) ;
if ( V_241 -> V_244 == V_245 ||
V_241 -> V_244 != V_2 -> V_246 )
goto V_34;
F_61 ( & V_2 -> V_247 , V_240 ) ;
F_62 ( V_2 -> V_30 ) ;
F_1 ( V_2 , V_248 ) ;
F_7 ( V_2 , V_248 ) ;
V_242 = true ;
V_34:
F_63 ( & V_2 -> V_243 ) ;
return V_242 ;
}
static void F_64 ( struct V_29 * V_30 ,
struct V_249 * V_250 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_237 * V_238 = V_250 -> V_238 ;
struct V_251 * V_252 = F_65 ( V_240 ) ;
struct V_253 * V_254 = ( void * ) V_240 -> V_255 ;
if ( F_66 ( V_2 ) ) {
F_67 ( V_2 , L_12 ) ;
goto V_256;
}
if ( F_65 ( V_240 ) -> V_257 == V_82 &&
! F_14 ( V_258 , & V_2 -> V_15 ) &&
! F_14 ( V_259 , & V_2 -> V_15 ) )
goto V_256;
if ( F_68 ( V_252 -> V_99 & V_260 &&
F_69 ( V_254 -> V_261 ) &&
! F_70 ( V_254 -> V_261 ) &&
! F_71 ( V_254 -> V_261 ) &&
! F_72 ( V_254 -> V_261 ) ) )
V_238 = NULL ;
if ( V_238 ) {
if ( F_57 ( V_2 , V_238 , V_240 ) )
return;
if ( F_73 ( V_2 , V_240 , V_238 ) )
goto V_256;
return;
}
if ( F_74 ( V_2 , V_240 ) )
goto V_256;
return;
V_256:
F_75 ( V_30 , V_240 ) ;
}
static inline bool F_76 ( const struct V_262 * V_37 )
{
if ( V_101 . V_263 & V_264 )
return false ;
return true ;
}
static inline bool F_77 ( const struct V_262 * V_37 )
{
if ( V_101 . V_263 & V_265 )
return false ;
if ( V_101 . V_263 & V_266 )
return true ;
return true ;
}
static void
F_78 ( struct V_1 * V_2 , struct V_267 * V_268 ,
struct V_237 * V_238 , V_119 V_269 , V_119 V_270 ,
enum V_271 V_272 )
{
struct V_273 * V_274 ;
struct V_275 * V_276 ;
if ( ! F_79 ( V_2 -> V_97 , V_277 ) )
return;
V_274 = F_80 ( V_2 -> V_97 , V_277 ) ;
V_276 = ( void * ) V_274 -> V_255 ;
if ( ! F_81 ( V_2 , V_268 , V_274 ) )
return;
switch ( V_272 ) {
case V_278 : {
struct V_115 * V_241 = F_60 ( V_238 ) ;
struct V_279 * V_280 = & V_241 -> V_280 [ V_269 ] ;
F_82 ( V_2 , V_274 , V_276 -> V_281 , V_269 ,
L_13 ,
V_238 -> V_144 , V_269 , V_280 -> V_282 ) ;
break;
}
case V_283 :
F_82 ( V_2 , V_274 , V_276 -> V_284 , V_269 ,
L_14 ,
V_238 -> V_144 , V_269 ) ;
break;
case V_285 :
F_82 ( V_2 , V_274 , V_276 -> V_286 , V_269 ,
L_15 ,
V_238 -> V_144 , V_269 , V_270 ) ;
break;
case V_287 :
F_82 ( V_2 , V_274 , V_276 -> V_288 , V_269 ,
L_16 ,
V_238 -> V_144 , V_269 ) ;
break;
default:
break;
}
}
static int F_83 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
bool V_291 = false ;
struct V_237 * V_238 = V_290 -> V_238 ;
enum V_271 V_272 = V_290 -> V_272 ;
V_119 V_269 = V_290 -> V_269 ;
V_119 * V_282 = & V_290 -> V_282 ;
T_2 V_292 = V_290 -> V_292 ;
bool V_293 = V_290 -> V_293 ;
V_119 V_294 = V_290 -> V_294 ;
F_84 ( V_2 , L_17 ,
V_238 -> V_144 , V_269 , V_272 ) ;
if ( ! ( V_2 -> V_145 -> V_295 ) )
return - V_296 ;
switch ( V_272 ) {
case V_297 :
case V_283 :
case V_298 :
case V_299 :
case V_278 :
V_47 = F_12 ( V_2 , V_300 ) ;
if ( V_47 )
return V_47 ;
V_291 = true ;
break;
default:
break;
}
F_85 ( & V_2 -> V_33 ) ;
switch ( V_272 ) {
case V_285 :
if ( ! F_76 ( V_2 -> V_37 ) ) {
V_47 = - V_301 ;
break;
}
V_47 = F_86 ( V_2 , V_238 , V_269 , * V_282 , true , V_292 ,
V_294 ) ;
break;
case V_287 :
V_47 = F_86 ( V_2 , V_238 , V_269 , 0 , false , V_292 ,
V_294 ) ;
break;
case V_297 :
if ( ! F_77 ( V_2 -> V_37 ) ) {
V_47 = - V_301 ;
break;
}
V_47 = F_87 ( V_2 , V_268 , V_238 , V_269 , V_282 ) ;
break;
case V_283 :
V_47 = F_88 ( V_2 , V_268 , V_238 , V_269 ) ;
break;
case V_298 :
case V_299 :
V_47 = F_89 ( V_2 , V_268 , V_238 , V_269 ) ;
break;
case V_278 :
V_47 = F_90 ( V_2 , V_268 , V_238 , V_269 ,
V_292 , V_293 ) ;
break;
default:
F_15 ( 1 ) ;
V_47 = - V_301 ;
break;
}
if ( ! V_47 ) {
V_119 V_270 = 0 ;
if ( V_272 == V_285 )
V_270 = * V_282 ;
F_78 ( V_2 , V_268 , V_238 , V_269 ,
V_270 , V_272 ) ;
}
F_91 ( & V_2 -> V_33 ) ;
if ( V_291 )
F_7 ( V_2 , V_300 ) ;
return V_47 ;
}
static void F_92 ( void * V_255 , T_2 * V_302 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = V_255 ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
V_303 -> V_304 = false ;
V_303 -> V_305 = V_245 ;
F_4 ( & V_2 -> V_306 ) ;
F_94 ( V_2 , & V_303 -> V_307 ) ;
F_5 ( & V_2 -> V_306 ) ;
V_303 -> V_308 = NULL ;
memset ( & V_303 -> V_309 , 0 , sizeof( V_303 -> V_309 ) ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( ! F_96 ( V_310 , & V_2 -> V_15 ) ) {
V_2 -> V_311 = & V_312 ;
F_97 ( V_2 ) ;
}
F_10 ( V_2 , V_313 ) ;
F_98 ( V_2 ) ;
V_2 -> V_314 = 0 ;
V_2 -> V_315 = false ;
V_2 -> V_316 = false ;
F_99 ( V_2 ) ;
F_100 ( V_2 -> V_30 ) ;
F_101 ( V_2 -> V_30 , 0 , F_92 , V_2 ) ;
V_2 -> V_317 = NULL ;
V_2 -> V_246 = V_245 ;
F_16 ( V_2 ) ;
memset ( V_2 -> V_318 , 0 , sizeof( V_2 -> V_318 ) ) ;
memset ( V_2 -> V_319 , 0 , sizeof( V_2 -> V_319 ) ) ;
memset ( V_2 -> V_320 , 0 , sizeof( V_2 -> V_320 ) ) ;
memset ( V_2 -> V_321 , 0 , sizeof( V_2 -> V_321 ) ) ;
memset ( & V_2 -> V_322 , 0 , sizeof( V_2 -> V_322 ) ) ;
memset ( & V_2 -> V_323 , 0 , sizeof( V_2 -> V_323 ) ) ;
memset ( & V_2 -> V_324 , 0 , sizeof( V_2 -> V_324 ) ) ;
memset ( & V_2 -> V_325 , 0 , sizeof( V_2 -> V_325 ) ) ;
memset ( & V_2 -> V_326 , 0 , sizeof( V_2 -> V_326 ) ) ;
memset ( & V_2 -> V_327 , 0 , sizeof( V_2 -> V_327 ) ) ;
F_102 ( V_2 -> V_30 ) ;
F_103 ( V_14 , & V_2 -> V_15 ) ;
V_2 -> V_328 = 0 ;
V_2 -> V_329 = 0 ;
V_2 -> V_330 = V_331 ;
F_104 ( V_2 ) ;
}
int F_105 ( struct V_1 * V_2 )
{
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_332 , & V_2 -> V_15 ) ) {
F_95 ( V_2 ) ;
} else {
F_1 ( V_2 , V_313 ) ;
}
V_47 = F_106 ( V_2 ) ;
if ( V_47 && F_14 ( V_332 , & V_2 -> V_15 ) ) {
F_103 ( V_332 , & V_2 -> V_15 ) ;
F_107 ( V_2 , NULL ) ;
}
return V_47 ;
}
static int F_108 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( F_14 ( V_332 , & V_2 -> V_15 ) ) {
F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ;
}
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_105 ( V_2 ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_109 ( struct V_1 * V_2 )
{
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
F_103 ( V_332 , & V_2 -> V_15 ) ;
F_107 ( V_2 , NULL ) ;
V_47 = F_110 ( V_2 , true , NULL ) ;
if ( V_47 )
F_111 ( V_2 , L_18 ,
V_47 ) ;
F_7 ( V_2 , V_313 ) ;
F_112 ( V_2 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) &&
F_114 ( V_2 ) )
F_115 ( ! F_13 ( V_2 -> V_13 ,
! F_14 ( V_14 ,
& V_2 -> V_15 ) ,
V_16 ) ,
L_19 ) ;
}
static void
F_116 ( struct V_29 * V_30 ,
enum V_333 V_334 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_334 ) {
case V_335 :
F_109 ( V_2 ) ;
break;
case V_336 :
F_113 ( V_2 ) ;
break;
}
}
void F_117 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_33 ) ;
memset ( & V_2 -> V_337 , 0 , sizeof( V_2 -> V_337 ) ) ;
F_118 ( & V_2 -> V_338 ) ;
F_98 ( V_2 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
if ( F_96 ( V_332 , & V_2 -> V_15 ) )
F_101 ( V_2 -> V_30 , 0 ,
F_92 , V_2 ) ;
if ( F_47 ( & V_2 -> V_97 -> V_98 , V_158 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_159 ; V_9 ++ ) {
if ( F_115 ( V_2 -> V_339 [ V_9 ] ,
L_20 ,
V_9 ) )
V_2 -> V_339 [ V_9 ] = 0 ;
}
}
}
static void F_122 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_118 ( & V_2 -> V_340 ) ;
F_118 ( & V_2 -> V_341 ) ;
F_118 ( & V_2 -> V_342 ) ;
F_123 ( & V_2 -> V_343 ) ;
F_124 ( V_2 ) ;
F_85 ( & V_2 -> V_33 ) ;
F_117 ( V_2 ) ;
F_91 ( & V_2 -> V_33 ) ;
F_125 ( & V_2 -> V_341 ) ;
}
static struct V_344 * F_126 ( struct V_1 * V_2 )
{
V_119 V_9 ;
F_21 ( & V_2 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_21 )
return & V_2 -> V_18 [ V_9 ] ;
F_111 ( V_2 , L_21 ) ;
return NULL ;
}
static int F_127 ( struct V_1 * V_2 , struct V_267 * V_268 ,
T_3 V_345 )
{
struct V_346 V_347 = {
. V_348 . V_349 = F_128 ( V_350 ) ,
. V_348 . V_351 =
F_128 ( F_93 ( V_268 ) -> V_20 ) ,
. V_348 . V_352 = F_129 ( 8 * V_345 ) ,
} ;
int V_206 = sizeof( V_347 ) ;
if ( V_345 == V_353 )
V_347 . V_348 . V_352 = F_129 ( V_354 ) ;
if ( ! F_48 ( & V_2 -> V_97 -> V_98 , V_355 ) )
V_206 = sizeof( V_347 . V_348 ) ;
return F_130 ( V_2 , V_356 , 0 , V_206 , & V_347 ) ;
}
static int F_131 ( struct V_29 * V_30 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
int V_47 ;
V_303 -> V_2 = V_2 ;
V_47 = F_12 ( V_2 , V_357 ) ;
if ( V_47 )
return V_47 ;
F_85 ( & V_2 -> V_33 ) ;
if ( F_14 ( V_332 , & V_2 -> V_15 ) )
V_303 -> V_358 . V_359 +=
V_303 -> V_358 . V_360 ;
V_47 = F_132 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_361;
if ( V_268 -> type != V_125 )
V_2 -> V_328 ++ ;
if ( V_268 -> type == V_123 ||
V_268 -> type == V_126 ) {
V_47 = F_133 ( V_2 , V_268 ) ;
if ( V_47 ) {
F_111 ( V_2 , L_22 ) ;
goto V_362;
}
F_134 ( V_2 , V_268 ) ;
goto V_361;
}
V_303 -> V_110 |= V_30 -> V_75 ;
V_47 = F_135 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_362;
V_47 = F_136 ( V_2 ) ;
if ( V_47 )
goto V_363;
V_47 = F_137 ( V_2 , V_268 , 0 ) ;
if ( V_47 )
goto V_363;
if ( ! V_2 -> V_364 &&
V_268 -> type == V_121 && ! V_268 -> V_365 ) {
V_2 -> V_364 = V_303 ;
V_268 -> V_366 |= V_367 |
V_368 ;
}
if ( V_268 -> type == V_125 ) {
V_303 -> V_308 = F_126 ( V_2 ) ;
if ( ! V_303 -> V_308 ) {
V_47 = - V_369 ;
goto V_370;
}
F_138 ( V_2 , V_303 -> V_308 ) ;
V_47 = F_139 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_371;
V_47 = F_140 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_372;
V_2 -> V_317 = V_268 ;
}
F_134 ( V_2 , V_268 ) ;
goto V_361;
V_372:
F_141 ( V_2 , V_268 ) ;
V_371:
F_142 ( V_2 , V_303 -> V_308 ) ;
V_370:
if ( V_2 -> V_364 == V_303 ) {
V_2 -> V_364 = NULL ;
V_268 -> V_366 &= ~ ( V_367 |
V_368 ) ;
}
V_363:
V_303 -> V_308 = NULL ;
F_143 ( V_2 , V_268 ) ;
V_362:
if ( V_268 -> type != V_125 )
V_2 -> V_328 -- ;
F_144 ( V_2 , V_268 ) ;
V_361:
F_91 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_357 ) ;
return V_47 ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
T_1 V_373 = F_146 ( V_268 ) ;
if ( V_373 ) {
F_85 ( & V_2 -> V_33 ) ;
F_147 ( V_2 , V_373 , 0 ) ;
F_91 ( & V_2 -> V_33 ) ;
F_148 ( V_2 -> V_7 , V_373 ) ;
}
if ( V_268 -> type == V_125 ) {
F_118 ( & V_2 -> V_338 ) ;
} else {
F_118 ( & V_2 -> V_374 ) ;
}
}
static void F_149 ( struct V_29 * V_30 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
F_145 ( V_2 , V_268 ) ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_364 == V_303 ) {
V_2 -> V_364 = NULL ;
V_268 -> V_366 &= ~ ( V_367 |
V_368 ) ;
}
F_150 ( V_2 , V_268 ) ;
if ( V_268 -> type == V_123 ||
V_268 -> type == V_126 ) {
#ifdef F_151
if ( V_268 == V_2 -> V_375 ) {
V_2 -> V_375 = NULL ;
V_2 -> V_376 = 0 ;
}
#endif
F_152 ( V_2 , V_268 ) ;
goto V_362;
}
if ( V_268 -> type == V_125 ) {
V_2 -> V_317 = NULL ;
F_153 ( V_2 , V_268 ) ;
F_141 ( V_2 , V_268 ) ;
F_142 ( V_2 , V_303 -> V_308 ) ;
V_303 -> V_308 = NULL ;
}
if ( V_2 -> V_328 && V_268 -> type != V_125 )
V_2 -> V_328 -- ;
F_136 ( V_2 ) ;
F_143 ( V_2 , V_268 ) ;
V_362:
F_144 ( V_2 , V_268 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static int F_154 ( struct V_29 * V_30 , T_1 V_27 )
{
return 0 ;
}
static void F_155 ( void * V_377 , T_2 * V_302 ,
struct V_267 * V_268 )
{
struct V_378 * V_255 = V_377 ;
struct V_1 * V_2 = V_255 -> V_2 ;
struct V_379 * V_347 = V_2 -> V_380 ;
int V_47 , V_206 ;
if ( F_15 ( V_255 -> V_381 >= V_382 ) )
return;
if ( V_268 -> type != V_121 ||
! V_268 -> V_383 . V_384 )
return;
V_347 -> V_381 = V_255 -> V_381 ++ ;
memcpy ( V_347 -> V_385 , V_268 -> V_383 . V_385 , V_147 ) ;
V_206 = F_156 ( sizeof( * V_347 ) + V_347 -> V_386 * V_147 , 4 ) ;
V_47 = F_130 ( V_2 , V_387 , V_388 , V_206 , V_347 ) ;
if ( V_47 )
F_111 ( V_2 , L_23 , V_47 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_378 V_389 = {
. V_2 = V_2 ,
} ;
F_21 ( & V_2 -> V_33 ) ;
if ( F_15 ( ! V_2 -> V_380 ) )
return;
F_158 (
V_2 -> V_30 , V_390 ,
F_155 , & V_389 ) ;
}
static T_4 F_159 ( struct V_29 * V_30 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_379 * V_347 ;
struct V_393 * V_144 ;
int V_394 ;
bool V_395 ;
int V_206 ;
V_394 = F_160 ( V_392 ) ;
V_395 = V_394 > V_396 ||
V_397 ;
if ( V_395 )
V_394 = 0 ;
V_206 = F_156 ( sizeof( * V_347 ) + V_394 * V_147 , 4 ) ;
V_347 = F_161 ( V_206 , V_398 ) ;
if ( ! V_347 )
return 0 ;
if ( V_395 ) {
V_347 -> V_395 = 1 ;
return ( T_4 ) ( unsigned long ) V_347 ;
}
F_162 (addr, mc_list) {
F_163 ( V_2 , L_24 ,
V_347 -> V_386 , V_144 -> V_144 ) ;
memcpy ( & V_347 -> V_399 [ V_347 -> V_386 * V_147 ] ,
V_144 -> V_144 , V_147 ) ;
V_347 -> V_386 ++ ;
}
return ( T_4 ) ( unsigned long ) V_347 ;
}
static void F_164 ( struct V_29 * V_30 ,
unsigned int V_400 ,
unsigned int * V_401 ,
T_4 V_402 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_379 * V_347 = ( void * ) ( unsigned long ) V_402 ;
F_85 ( & V_2 -> V_33 ) ;
F_28 ( V_2 -> V_380 ) ;
V_2 -> V_380 = V_347 ;
if ( ! V_347 )
goto V_34;
F_157 ( V_2 ) ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
* V_401 = 0 ;
}
static void F_165 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
unsigned int V_403 ,
unsigned int V_400 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( ! ( V_400 & V_404 ) )
return;
if ( V_268 -> type != V_121 || ! V_268 -> V_383 . V_384 ||
! V_268 -> V_365 )
return;
F_85 ( & V_2 -> V_33 ) ;
F_166 ( V_2 , V_268 , false , NULL ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void
F_167 ( struct V_267 * V_268 ,
const struct V_405 * V_406 ,
struct V_405 * V_407 )
{
struct V_408 * V_409 ;
int V_9 ;
memcpy ( V_407 , V_406 , sizeof( * V_407 ) ) ;
for ( V_9 = 0 ; V_9 < F_42 ( V_407 -> V_410 ) ; V_9 ++ ) {
V_409 = & V_407 -> V_410 [ V_9 ] ;
if ( ! V_409 -> V_411 )
break;
switch ( V_409 -> V_412 ) {
case F_129 ( V_413 ) :
if ( V_268 -> V_383 . V_414 != 1 ) {
V_409 -> V_411 = 0 ;
continue;
}
V_409 -> V_415 = V_268 -> V_383 . V_416 [ 0 ] ;
break;
case F_129 ( V_417 ) :
V_409 -> V_415 = * ( V_418 * ) & V_268 -> V_144 [ 2 ] ;
break;
default:
break;
}
V_409 -> V_412 = 0 ;
V_407 -> V_419 ++ ;
}
}
static void F_168 ( void * V_377 , T_2 * V_302 ,
struct V_267 * V_268 )
{
struct V_420 * V_255 = V_377 ;
struct V_1 * V_2 = V_255 -> V_2 ;
struct V_421 * V_347 = V_255 -> V_347 ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
struct V_422 * V_423 ;
int V_9 ;
if ( F_8 ( V_303 -> V_20 >= F_42 ( V_347 -> V_424 ) ) )
return;
V_423 = & V_347 -> V_424 [ V_303 -> V_20 ] ;
if ( V_268 -> type != V_121 || V_268 -> V_365 ||
! V_268 -> V_383 . V_384 )
return;
V_423 -> V_425 = 1 ;
for ( V_9 = 0 ; V_2 -> V_227 [ V_9 ] . V_410 [ 0 ] . V_411 ; V_9 ++ ) {
if ( F_15 ( V_255 -> V_426 >=
F_42 ( V_347 -> V_427 ) ) ) {
V_423 -> V_425 = 0 ;
V_423 -> V_428 = 0 ;
break;
}
F_167 ( V_268 ,
& V_2 -> V_227 [ V_9 ] ,
& V_347 -> V_427 [ V_255 -> V_426 ] ) ;
if ( ! V_347 -> V_427 [ V_255 -> V_426 ] . V_419 )
continue;
V_423 -> V_428 |=
F_129 ( F_43 ( V_255 -> V_426 ) ) ;
V_255 -> V_426 ++ ;
}
}
bool F_169 ( struct V_1 * V_2 ,
struct V_421 * V_347 )
{
struct V_420 V_389 = {
. V_2 = V_2 ,
. V_347 = V_347 ,
} ;
if ( V_429 )
return false ;
memset ( V_347 , 0 , sizeof( * V_347 ) ) ;
V_347 -> V_430 = F_42 ( V_347 -> V_427 ) ;
V_347 -> V_431 = F_42 ( V_347 -> V_424 ) ;
#ifdef F_170
if ( V_2 -> V_432 . V_433 ) {
memcpy ( V_347 -> V_427 , & V_2 -> V_432 . V_347 . V_427 ,
sizeof( V_347 -> V_427 ) ) ;
memcpy ( V_347 -> V_424 , & V_2 -> V_432 . V_347 . V_424 ,
sizeof( V_347 -> V_424 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_227 )
return false ;
F_171 (
V_2 -> V_30 , V_390 ,
F_168 , & V_389 ) ;
return true ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_421 V_347 ;
if ( ! ( V_2 -> V_97 -> V_98 . V_99 & V_434 ) )
return 0 ;
if ( ! F_169 ( V_2 , & V_347 ) )
return 0 ;
return F_130 ( V_2 , V_435 , 0 ,
sizeof( V_347 ) , & V_347 ) ;
}
static inline int F_172 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_173 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
struct V_436 V_347 = {} ;
memcpy ( V_347 . V_437 , V_268 -> V_383 . V_438 . V_439 ,
V_440 ) ;
memcpy ( V_347 . V_441 , V_268 -> V_383 . V_438 . V_442 ,
V_443 ) ;
return F_130 ( V_2 ,
F_174 ( V_444 ,
V_445 ) ,
0 , sizeof( V_347 ) , & V_347 ) ;
}
static void F_175 ( void * V_377 , T_2 * V_302 ,
struct V_267 * V_268 )
{
if ( V_268 -> V_446 ) {
struct V_447 * V_448 = V_377 ;
F_176 ( V_268 ,
( T_2 * ) & V_448 -> V_437 ,
( T_2 * ) & V_448 -> V_441 ) ;
}
}
void F_177 ( struct V_1 * V_2 ,
struct V_449 * V_450 )
{
struct V_451 * V_452 = F_178 ( V_450 ) ;
struct V_447 * V_448 = ( void * ) V_452 -> V_255 ;
F_158 (
V_2 -> V_30 , V_390 ,
F_175 , V_448 ) ;
}
static void F_179 ( struct V_1 * V_2 ,
struct V_267 * V_268 ,
struct V_453 * V_383 ,
T_1 V_454 )
{
struct V_117 * V_303 = F_93 ( V_268 ) ;
int V_47 ;
if ( V_454 & V_455 && V_383 -> V_384 )
F_180 ( V_2 , V_268 ) ;
if ( V_454 & V_455 && ! V_383 -> V_384 &&
V_303 -> V_456 )
F_181 ( V_268 , V_457 ,
0 , 0 ) ;
if ( V_454 & V_458 && ! V_303 -> V_459 )
memcpy ( V_303 -> V_385 , V_383 -> V_385 , V_147 ) ;
V_47 = F_166 ( V_2 , V_268 , false , V_303 -> V_385 ) ;
if ( V_47 )
F_111 ( V_2 , L_25 , V_268 -> V_144 ) ;
memcpy ( V_303 -> V_385 , V_383 -> V_385 , V_147 ) ;
V_303 -> V_459 = V_383 -> V_384 ;
if ( V_454 & V_455 ) {
if ( V_383 -> V_384 ) {
F_182 ( V_2 , true ) ;
memset ( & V_303 -> V_358 , 0 ,
sizeof( V_303 -> V_358 ) ) ;
V_47 = F_110 ( V_2 , true , NULL ) ;
if ( V_47 ) {
F_111 ( V_2 , L_26 ) ;
return;
}
if ( F_14 ( V_332 ,
& V_2 -> V_15 ) ) {
T_1 V_460 = ( 11 * V_268 -> V_383 . V_461 ) / 10 ;
F_183 ( V_2 , V_268 , V_460 , V_460 ,
5 * V_460 , false ) ;
}
F_184 ( V_2 , V_268 , false ) ;
F_185 ( V_2 , V_268 ) ;
if ( V_268 -> V_365 ) {
F_1 ( V_2 , V_462 ) ;
F_186 ( V_2 , V_268 ,
V_463 ,
V_464 ) ;
}
} else if ( V_303 -> V_305 != V_245 ) {
F_115 ( F_184 ( V_2 , V_268 , false ) ,
L_27 ) ;
V_47 = F_187 ( V_2 , V_268 , V_303 -> V_305 ) ;
if ( V_47 )
F_111 ( V_2 , L_28 ) ;
if ( V_2 -> V_246 == V_303 -> V_305 )
V_2 -> V_246 = V_245 ;
V_303 -> V_305 = V_245 ;
V_47 = F_110 ( V_2 , false , NULL ) ;
if ( V_47 )
F_111 ( V_2 , L_26 ) ;
if ( V_268 -> V_365 )
F_7 ( V_2 , V_462 ) ;
V_47 = F_166 ( V_2 , V_268 , false , NULL ) ;
if ( V_47 )
F_111 ( V_2 ,
L_29 ,
V_268 -> V_144 ) ;
}
if ( F_14 ( V_332 , & V_2 -> V_15 ) &&
( V_454 & V_465 ) && V_268 -> V_446 ) {
V_47 = F_173 ( V_2 , V_268 ) ;
if ( V_47 )
F_111 ( V_2 ,
L_30 ) ;
}
F_157 ( V_2 ) ;
F_172 ( V_2 ) ;
V_303 -> V_309 . V_466 = 0 ;
F_188 ( V_2 ) ;
F_186 ( V_2 , V_268 , V_467 ,
V_468 ) ;
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_158 ) )
F_189 ( V_2 ) ;
} else if ( V_454 & V_469 ) {
F_190 ( V_2 , V_303 ,
& V_303 -> V_307 ) ;
}
if ( V_454 & V_469 ) {
F_184 ( V_2 , V_268 , false ) ;
F_8 ( F_191 ( V_2 , V_268 , 0 ) ) ;
}
if ( V_454 & ( V_470 | V_471 | V_472 |
V_469 ) ) {
V_47 = F_136 ( V_2 ) ;
if ( V_47 )
F_111 ( V_2 , L_31 ) ;
}
if ( V_454 & V_473 ) {
F_192 ( V_2 , L_32 ,
V_383 -> V_474 ) ;
F_127 ( V_2 , V_268 , V_383 -> V_474 ) ;
}
if ( V_454 & V_475 ) {
F_163 ( V_2 , L_33 ) ;
V_303 -> V_309 . V_476 = 0 ;
if ( V_303 -> V_309 . V_477 ) {
V_47 = F_191 ( V_2 , V_268 , 0 ) ;
if ( V_47 )
F_111 ( V_2 ,
L_34 ) ;
}
}
if ( V_454 & V_478 ) {
F_163 ( V_2 , L_35 ) ;
F_172 ( V_2 ) ;
}
}
static int F_193 ( struct V_29 * V_30 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
int V_47 ;
V_47 = F_12 ( V_2 , V_479 ) ;
if ( V_47 )
return V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_194 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_361;
if ( V_268 -> type == V_123 )
F_180 ( V_2 , V_268 ) ;
V_303 -> V_480 = 0 ;
V_47 = F_135 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_361;
V_47 = F_139 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_481;
V_47 = F_195 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_372;
V_303 -> V_482 = true ;
F_136 ( V_2 ) ;
V_47 = F_110 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_483;
if ( V_268 -> V_365 && V_2 -> V_317 )
F_166 ( V_2 , V_2 -> V_317 , false , NULL ) ;
F_1 ( V_2 , V_484 ) ;
F_188 ( V_2 ) ;
if ( F_196 ( V_2 ) > 1 )
F_112 ( V_2 ) ;
goto V_361;
V_483:
F_136 ( V_2 ) ;
V_303 -> V_482 = false ;
F_197 ( V_2 , V_268 ) ;
V_372:
F_141 ( V_2 , V_268 ) ;
V_481:
F_143 ( V_2 , V_268 ) ;
V_361:
F_91 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_479 ) ;
return V_47 ;
}
static void F_198 ( struct V_29 * V_30 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
F_145 ( V_2 , V_268 ) ;
F_85 ( & V_2 -> V_33 ) ;
if ( F_199 ( V_2 -> V_485 ) == V_268 ) {
F_190 ( V_2 , V_303 ,
& V_303 -> V_307 ) ;
F_200 ( V_2 -> V_485 , NULL ) ;
V_303 -> V_486 = false ;
}
if ( F_199 ( V_2 -> V_487 ) == V_268 ) {
F_200 ( V_2 -> V_487 , NULL ) ;
V_2 -> V_488 = 0 ;
}
V_303 -> V_482 = false ;
V_2 -> V_489 = 0 ;
F_188 ( V_2 ) ;
F_7 ( V_2 , V_484 ) ;
if ( V_268 -> V_365 && V_2 -> V_317 )
F_166 ( V_2 , V_2 -> V_317 , false , NULL ) ;
F_110 ( V_2 , false , NULL ) ;
F_197 ( V_2 , V_268 ) ;
F_141 ( V_2 , V_268 ) ;
F_136 ( V_2 ) ;
F_143 ( V_2 , V_268 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void
F_201 ( struct V_1 * V_2 ,
struct V_267 * V_268 ,
struct V_453 * V_383 ,
T_1 V_454 )
{
struct V_117 * V_303 = F_93 ( V_268 ) ;
if ( ! V_303 -> V_482 )
return;
if ( V_454 & ( V_490 | V_491 |
V_492 | V_472 ) &&
F_166 ( V_2 , V_268 , false , NULL ) )
F_111 ( V_2 , L_25 , V_268 -> V_144 ) ;
if ( V_454 & V_493 &&
F_194 ( V_2 , V_268 ) )
F_202 ( V_2 , L_36 ) ;
if ( V_454 & V_473 ) {
F_192 ( V_2 , L_32 ,
V_383 -> V_474 ) ;
F_127 ( V_2 , V_268 , V_383 -> V_474 ) ;
}
}
static void F_203 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_453 * V_383 ,
T_1 V_454 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( F_12 ( V_2 , V_494 ) )
return;
F_85 ( & V_2 -> V_33 ) ;
if ( V_454 & V_495 && ! V_383 -> V_496 )
F_204 ( V_2 , V_497 , true ) ;
switch ( V_268 -> type ) {
case V_121 :
F_179 ( V_2 , V_268 , V_383 , V_454 ) ;
break;
case V_123 :
case V_126 :
F_201 ( V_2 , V_268 , V_383 , V_454 ) ;
break;
default:
F_15 ( 1 ) ;
}
F_91 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_494 ) ;
}
static int F_205 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_498 * V_499 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_499 -> V_500 . V_38 == 0 ||
V_499 -> V_500 . V_38 > V_2 -> V_97 -> V_98 . V_501 )
return - V_301 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_206 ( V_2 , V_268 , & V_499 -> V_500 , & V_499 -> V_502 ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_207 ( struct V_29 * V_30 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_314 & V_503 )
F_204 ( V_2 , V_503 , true ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void
F_208 ( struct V_29 * V_30 ,
struct V_237 * V_238 , V_119 V_504 ,
int V_505 ,
enum V_506 V_507 ,
bool V_508 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_209 ( V_2 , V_238 , V_507 , V_505 ,
V_504 , V_508 , false ) ;
}
static void
F_210 ( struct V_29 * V_30 ,
struct V_237 * V_238 , V_119 V_504 ,
int V_505 ,
enum V_506 V_507 ,
bool V_508 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_209 ( V_2 , V_238 , V_507 , V_505 ,
V_504 , V_508 , true ) ;
}
static void F_211 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
enum V_509 V_347 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_115 * V_241 = F_60 ( V_238 ) ;
unsigned long V_510 = 0 , V_504 = 0 ;
int V_269 ;
F_4 ( & V_241 -> V_511 ) ;
for ( V_269 = 0 ; V_269 < V_512 ; V_269 ++ ) {
struct V_279 * V_280 = & V_241 -> V_280 [ V_269 ] ;
if ( V_280 -> V_513 != V_514 &&
V_280 -> V_513 != V_515 )
continue;
F_212 ( V_280 -> V_516 , & V_510 ) ;
if ( F_213 ( V_280 ) == 0 )
continue;
F_212 ( V_269 , & V_504 ) ;
}
switch ( V_347 ) {
case V_517 :
if ( F_214 ( & V_2 -> V_518 [ V_241 -> V_244 ] ) > 0 )
F_215 ( V_30 , V_238 , true ) ;
F_216 (tid, &tids, IWL_MAX_TID_COUNT)
F_217 ( V_238 , V_269 , true ) ;
if ( V_510 )
F_218 ( V_2 -> V_7 , V_510 , true ) ;
break;
case V_519 :
if ( F_8 ( V_241 -> V_244 == V_245 ) )
break;
if ( V_510 )
F_218 ( V_2 -> V_7 , V_510 , false ) ;
F_219 ( V_2 , V_238 ) ;
break;
default:
break;
}
F_5 ( & V_241 -> V_511 ) ;
}
static void F_220 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_115 * V_520 = F_60 ( V_238 ) ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_238 == F_199 ( V_2 -> V_521 [ V_520 -> V_244 ] ) )
F_221 ( V_2 -> V_521 [ V_520 -> V_244 ] ,
F_222 ( - V_49 ) ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void F_223 ( struct V_1 * V_2 , struct V_267 * V_268 ,
const T_2 * V_385 )
{
if ( ! ( V_2 -> V_97 -> V_98 . V_99 & V_522 ) )
return;
if ( V_268 -> V_365 && ! F_224 ( V_2 ) ) {
V_268 -> V_366 &= ~ V_523 ;
return;
}
if ( ! V_268 -> V_365 &&
( V_101 . V_524 & V_525 ) ) {
V_268 -> V_366 &= ~ V_523 ;
return;
}
V_268 -> V_366 |= V_523 ;
}
static void
F_225 ( struct V_1 * V_2 ,
struct V_267 * V_268 , T_2 * V_526 ,
enum V_527 V_272 )
{
struct V_273 * V_274 ;
struct V_528 * V_529 ;
if ( ! F_79 ( V_2 -> V_97 , V_530 ) )
return;
V_274 = F_80 ( V_2 -> V_97 , V_530 ) ;
V_529 = ( void * ) V_274 -> V_255 ;
if ( ! F_81 ( V_2 , V_268 , V_274 ) )
return;
if ( ! ( V_529 -> V_531 & F_43 ( V_272 ) ) )
return;
if ( V_529 -> V_532 &&
memcmp ( V_529 -> V_533 , V_526 , V_147 ) != 0 )
return;
F_226 ( V_2 , V_274 ,
L_37 ,
V_526 , V_272 ) ;
}
static void F_227 ( struct V_1 * V_2 ,
struct V_115 * V_520 )
{
struct V_279 * V_280 ;
struct V_239 * V_240 ;
int V_9 ;
F_4 ( & V_520 -> V_511 ) ;
for ( V_9 = 0 ; V_9 <= V_512 ; V_9 ++ ) {
V_280 = & V_520 -> V_280 [ V_9 ] ;
while ( ( V_240 = F_228 ( & V_280 -> V_534 ) ) )
F_75 ( V_2 -> V_30 , V_240 ) ;
}
F_5 ( & V_520 -> V_511 ) ;
}
static int F_229 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_237 * V_238 ,
enum V_535 V_536 ,
enum V_535 V_537 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
int V_47 ;
F_163 ( V_2 , L_38 ,
V_238 -> V_144 , V_536 , V_537 ) ;
if ( F_15 ( ! V_303 -> V_308 ) )
return - V_301 ;
F_118 ( & V_2 -> V_374 ) ;
if ( V_536 == V_538 &&
V_537 == V_539 &&
F_40 ( V_2 ) ) {
struct V_115 * V_520 = F_60 ( V_238 ) ;
F_227 ( V_2 , V_520 ) ;
F_118 ( & V_2 -> V_342 ) ;
}
F_85 ( & V_2 -> V_33 ) ;
if ( V_536 == V_539 &&
V_537 == V_538 ) {
if ( V_268 -> type == V_121 &&
V_268 -> V_383 . V_461 < 16 ) {
F_111 ( V_2 ,
L_39 ,
V_238 -> V_144 , V_268 -> V_383 . V_461 ) ;
V_47 = - V_301 ;
goto V_361;
}
if ( V_238 -> V_540 &&
( V_268 -> V_365 ||
F_230 ( V_2 , NULL ) ==
V_541 ||
F_196 ( V_2 ) > 1 ) ) {
F_163 ( V_2 , L_40 ) ;
V_47 = - V_542 ;
goto V_361;
}
V_47 = F_231 ( V_2 , V_268 , V_238 ) ;
if ( V_238 -> V_540 && V_47 == 0 ) {
F_232 ( V_2 , V_268 , true ) ;
F_225 ( V_2 , V_268 , V_238 -> V_144 ,
V_543 ) ;
}
} else if ( V_536 == V_538 &&
V_537 == V_544 ) {
V_2 -> V_545 = true ;
F_223 ( V_2 , V_268 , V_238 -> V_144 ) ;
V_47 = 0 ;
} else if ( V_536 == V_544 &&
V_537 == V_546 ) {
if ( V_268 -> type == V_123 ) {
V_303 -> V_480 ++ ;
F_166 ( V_2 , V_268 , false , NULL ) ;
}
V_47 = F_233 ( V_2 , V_268 , V_238 ) ;
if ( V_47 == 0 )
F_234 ( V_2 , V_238 ,
V_303 -> V_308 -> V_547 -> V_548 ,
true ) ;
} else if ( V_536 == V_546 &&
V_537 == V_549 ) {
if ( F_196 ( V_2 ) > 1 )
F_112 ( V_2 ) ;
if ( V_238 -> V_540 )
F_225 ( V_2 , V_268 , V_238 -> V_144 ,
V_550 ) ;
F_8 ( F_191 ( V_2 , V_268 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_536 == V_549 &&
V_537 == V_546 ) {
F_8 ( F_137 ( V_2 , V_268 , 0 ) ) ;
V_47 = 0 ;
} else if ( V_536 == V_546 &&
V_537 == V_544 ) {
if ( V_268 -> type == V_123 ) {
V_303 -> V_480 -- ;
F_166 ( V_2 , V_268 , false , NULL ) ;
}
V_47 = 0 ;
} else if ( V_536 == V_544 &&
V_537 == V_538 ) {
V_47 = 0 ;
} else if ( V_536 == V_538 &&
V_537 == V_539 ) {
V_47 = F_235 ( V_2 , V_268 , V_238 ) ;
if ( V_238 -> V_540 ) {
F_232 ( V_2 , V_268 , false ) ;
F_225 ( V_2 , V_268 , V_238 -> V_144 ,
V_551 ) ;
}
} else {
V_47 = - V_17 ;
}
V_361:
F_91 ( & V_2 -> V_33 ) ;
if ( V_238 -> V_540 && V_47 == 0 ) {
if ( V_536 == V_539 &&
V_537 == V_538 )
F_236 ( V_238 , V_552 ) ;
else if ( V_536 == V_538 &&
V_537 == V_539 )
F_237 ( V_238 , V_552 ) ;
}
return V_47 ;
}
static int F_238 ( struct V_29 * V_30 , T_1 V_553 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_2 -> V_199 = V_553 ;
return 0 ;
}
static void F_239 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_237 * V_238 , T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_268 -> type == V_121 &&
V_27 & V_554 )
F_184 ( V_2 , V_268 , false ) ;
}
static int F_240 ( struct V_29 * V_30 ,
struct V_267 * V_268 , V_119 V_555 ,
const struct V_556 * V_290 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
V_303 -> V_557 [ V_555 ] = * V_290 ;
if ( V_268 -> type == V_125 ) {
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_166 ( V_2 , V_268 , false , NULL ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
return 0 ;
}
static void F_241 ( struct V_29 * V_30 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
T_1 V_558 = V_559 ;
T_1 V_560 = V_561 ;
if ( F_15 ( V_268 -> V_383 . V_384 ) )
return;
if ( F_12 ( V_2 , V_562 ) )
return;
F_85 ( & V_2 -> V_33 ) ;
F_183 ( V_2 , V_268 , V_558 , V_560 , 500 , false ) ;
F_91 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_562 ) ;
}
static int F_242 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_563 * V_500 ,
struct V_564 * V_502 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
if ( ! V_268 -> V_383 . V_496 ) {
V_47 = - V_542 ;
goto V_34;
}
V_47 = F_243 ( V_2 , V_268 , V_500 , V_502 , V_497 ) ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_244 ( struct V_29 * V_30 ,
struct V_267 * V_268 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
if ( ! ( V_2 -> V_314 & V_497 ) ) {
F_91 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_47 = F_204 ( V_2 , V_497 , false ) ;
F_91 ( & V_2 -> V_33 ) ;
F_245 ( V_2 ) ;
return V_47 ;
}
static int F_246 ( struct V_29 * V_30 ,
enum V_565 V_347 ,
struct V_267 * V_268 ,
struct V_237 * V_238 ,
struct V_566 * V_567 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_115 * V_241 ;
struct V_568 * V_569 ;
int V_570 = V_567 -> V_570 ;
int V_47 ;
T_2 V_571 ;
if ( V_101 . V_102 ) {
F_163 ( V_2 , L_41 ) ;
return - V_572 ;
}
switch ( V_567 -> V_106 ) {
case V_54 :
V_567 -> V_99 |= V_573 ;
V_567 -> V_99 |= V_574 ;
break;
case V_55 :
V_567 -> V_99 |= V_574 ;
break;
case V_104 :
F_15 ( ! F_247 ( V_30 , V_103 ) ) ;
break;
case V_52 :
case V_53 :
if ( V_268 -> type != V_121 )
return 0 ;
break;
default:
if ( V_30 -> V_107 &&
V_30 -> V_108 -> V_106 == V_567 -> V_106 )
V_567 -> V_99 |= V_574 ;
else
return - V_572 ;
}
F_85 ( & V_2 -> V_33 ) ;
switch ( V_347 ) {
case V_575 :
if ( ( V_268 -> type == V_126 ||
V_268 -> type == V_123 ) && ! V_238 ) {
if ( V_567 -> V_106 == V_104 )
V_47 = - V_572 ;
else
V_47 = 0 ;
V_567 -> V_576 = V_577 ;
break;
}
if ( F_14 ( V_332 , & V_2 -> V_15 ) &&
V_567 -> V_576 == V_577 ) {
F_163 ( V_2 ,
L_42 ) ;
V_47 = 0 ;
break;
}
if ( ! F_14 ( V_332 , & V_2 -> V_15 ) &&
V_238 && F_39 ( V_2 ) &&
V_567 -> V_99 & V_578 &&
( V_567 -> V_106 == V_55 ||
V_567 -> V_106 == V_579 ) ) {
struct V_580 V_581 ;
int V_269 , V_582 ;
V_241 = F_60 ( V_238 ) ;
F_8 ( F_199 ( V_241 -> V_569 [ V_570 ] ) ) ;
V_569 = F_161 ( sizeof( * V_569 ) +
V_2 -> V_7 -> V_72 *
sizeof( V_569 -> V_582 [ 0 ] ) ,
V_583 ) ;
if ( ! V_569 ) {
V_47 = - V_584 ;
break;
}
for ( V_269 = 0 ; V_269 < V_512 ; V_269 ++ ) {
F_248 ( V_567 , V_269 , & V_581 ) ;
for ( V_582 = 0 ; V_582 < V_2 -> V_7 -> V_72 ; V_582 ++ )
memcpy ( V_569 -> V_582 [ V_582 ] . V_585 [ V_269 ] ,
V_581 . V_586 . V_585 ,
V_587 ) ;
}
F_221 ( V_241 -> V_569 [ V_570 ] , V_569 ) ;
}
if ( F_14 ( V_332 , & V_2 -> V_15 ) )
V_571 = V_567 -> V_576 ;
else
V_571 = V_577 ;
F_163 ( V_2 , L_43 ) ;
V_47 = F_249 ( V_2 , V_268 , V_238 , V_567 , V_571 ) ;
if ( V_47 ) {
F_202 ( V_2 , L_44 ) ;
V_567 -> V_576 = V_577 ;
V_47 = 0 ;
}
break;
case V_588 :
if ( V_567 -> V_576 == V_577 ) {
V_47 = 0 ;
break;
}
if ( V_238 && F_39 ( V_2 ) &&
V_567 -> V_99 & V_578 &&
( V_567 -> V_106 == V_55 ||
V_567 -> V_106 == V_579 ) ) {
V_241 = F_60 ( V_238 ) ;
V_569 = F_250 (
V_241 -> V_569 [ V_570 ] ,
F_251 ( & V_2 -> V_33 ) ) ;
F_200 ( V_241 -> V_569 [ V_570 ] , NULL ) ;
if ( V_569 )
F_252 ( V_569 , V_589 ) ;
}
F_163 ( V_2 , L_45 ) ;
V_47 = F_253 ( V_2 , V_268 , V_238 , V_567 ) ;
break;
default:
V_47 = - V_301 ;
}
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_254 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_566 * V_590 ,
struct V_237 * V_238 ,
T_1 V_591 , V_119 * V_592 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
if ( V_590 -> V_576 == V_577 )
return;
F_255 ( V_2 , V_268 , V_590 , V_238 , V_591 , V_592 ) ;
}
static bool F_256 ( struct V_593 * V_594 ,
struct V_451 * V_452 , void * V_255 )
{
struct V_1 * V_2 =
F_257 ( V_594 , struct V_1 , V_594 ) ;
struct V_595 * V_32 ;
int V_596 = F_258 ( V_452 ) ;
struct V_597 * V_598 = V_255 ;
if ( F_8 ( V_452 -> V_254 . V_347 != V_599 ) )
return true ;
if ( F_15 ( V_596 != sizeof( * V_32 ) ) ) {
F_111 ( V_2 , L_46 ) ;
return true ;
}
V_32 = ( void * ) V_452 -> V_255 ;
F_259 ( V_2 ,
L_47 ,
V_32 -> V_15 , V_32 -> V_600 ) ;
V_598 -> V_601 = F_260 ( V_32 -> V_600 ) ;
F_259 ( V_2 , L_48 ,
V_598 -> V_601 ) ;
F_4 ( & V_2 -> V_306 ) ;
F_261 ( & V_598 -> V_602 , & V_2 -> V_603 ) ;
F_5 ( & V_2 -> V_306 ) ;
return true ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_604 * V_547 ,
struct V_267 * V_268 ,
int V_558 )
{
int V_605 , V_606 = V_607 ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
struct V_597 * V_598 = & V_303 -> V_608 ;
static const V_119 V_609 [] = { V_599 } ;
struct V_610 V_611 ;
T_1 V_612 = V_268 -> V_383 . V_613 *
V_268 -> V_383 . V_461 ;
T_1 V_614 , V_615 ;
struct V_616 V_617 = {
. V_272 = F_128 ( V_618 ) ,
. V_619 =
F_128 ( F_263 ( V_620 , 0 ) ) ,
. V_621 = F_128 ( V_2 -> V_622 . V_244 ) ,
. V_623 . V_548 = ( V_547 -> V_548 == V_161 ) ?
V_624 : V_625 ,
. V_623 . V_547 = V_547 -> V_626 ,
. V_623 . V_627 = V_628 ,
. V_629 = F_128 ( F_264 ( V_2 -> V_7 , V_606 ) ) ,
} ;
V_615 = V_630 ;
V_614 = F_265 ( V_558 ) ;
if ( V_268 -> V_383 . V_384 ) {
V_615 = F_266 ( T_1 , V_612 * 3 , V_631 ) ;
if ( V_612 <= V_614 ) {
V_614 = V_612 - V_632 ;
if ( V_614 <= V_633 )
V_614 = V_612 -
V_634 ;
}
}
V_617 . V_558 = F_128 ( V_614 ) ;
V_617 . V_635 = F_128 ( V_615 ) ;
F_259 ( V_2 ,
L_49 ,
V_547 -> V_626 , V_614 , V_558 , V_615 ,
V_612 ) ;
memcpy ( V_617 . V_636 , V_268 -> V_144 , V_147 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_4 ( & V_2 -> V_306 ) ;
if ( F_8 ( V_598 -> V_20 == V_599 ) ) {
F_5 ( & V_2 -> V_306 ) ;
return - V_17 ;
}
V_598 -> V_268 = V_268 ;
V_598 -> V_558 = V_558 ;
V_598 -> V_20 = V_599 ;
F_5 ( & V_2 -> V_306 ) ;
F_267 ( & V_2 -> V_594 , & V_611 ,
V_609 ,
F_42 ( V_609 ) ,
F_256 , V_598 ) ;
V_605 = F_130 ( V_2 , V_599 , 0 , sizeof( V_617 ) ,
& V_617 ) ;
if ( V_605 ) {
F_111 ( V_2 , L_50 , V_605 ) ;
F_268 ( & V_2 -> V_594 , & V_611 ) ;
goto V_637;
}
V_605 = F_269 ( & V_2 -> V_594 , & V_611 , 1 ) ;
F_15 ( V_605 ) ;
if ( V_605 ) {
V_637:
F_4 ( & V_2 -> V_306 ) ;
F_94 ( V_2 , V_598 ) ;
F_5 ( & V_2 -> V_306 ) ;
}
return V_605 ;
}
static int F_270 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_604 * V_547 ,
int V_558 ,
enum V_638 type )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
struct V_639 V_640 ;
struct V_344 * V_308 ;
int V_47 , V_9 ;
F_163 ( V_2 , L_51 , V_547 -> V_626 ,
V_558 , type ) ;
F_118 ( & V_2 -> V_338 ) ;
F_85 ( & V_2 -> V_33 ) ;
switch ( V_268 -> type ) {
case V_121 :
if ( F_47 ( & V_2 -> V_97 -> V_98 ,
V_641 ) ) {
V_47 = F_262 ( V_2 , V_547 ,
V_268 , V_558 ) ;
goto V_361;
}
F_111 ( V_2 , L_52 ) ;
V_47 = - V_301 ;
goto V_361;
case V_125 :
break;
default:
F_111 ( V_2 , L_53 , V_268 -> type ) ;
V_47 = - V_301 ;
goto V_361;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_308 = & V_2 -> V_18 [ V_9 ] ;
if ( V_308 -> V_21 == 0 || V_303 -> V_308 == V_308 )
continue;
if ( V_308 -> V_21 && V_547 == V_308 -> V_547 ) {
V_47 = F_141 ( V_2 , V_268 ) ;
if ( F_271 ( V_47 , L_54 ) )
goto V_361;
F_142 ( V_2 , V_303 -> V_308 ) ;
V_303 -> V_308 = V_308 ;
V_47 = F_139 ( V_2 , V_268 ) ;
if ( F_271 ( V_47 , L_55 ) )
goto V_361;
F_138 ( V_2 , V_303 -> V_308 ) ;
goto V_642;
}
}
if ( V_547 == V_303 -> V_308 -> V_547 )
goto V_642;
F_272 ( & V_640 , V_547 , V_643 ) ;
if ( V_303 -> V_308 -> V_21 == 1 ) {
V_47 = F_273 ( V_2 , V_303 -> V_308 ,
& V_640 , 1 , 1 ) ;
if ( V_47 )
goto V_361;
} else {
V_308 = F_126 ( V_2 ) ;
if ( ! V_308 ) {
V_47 = - V_369 ;
goto V_361;
}
V_47 = F_273 ( V_2 , V_308 , & V_640 ,
1 , 1 ) ;
if ( V_47 ) {
F_111 ( V_2 , L_56 ) ;
goto V_361;
}
V_47 = F_141 ( V_2 , V_268 ) ;
if ( F_271 ( V_47 , L_54 ) )
goto V_361;
F_142 ( V_2 , V_303 -> V_308 ) ;
V_303 -> V_308 = V_308 ;
V_47 = F_139 ( V_2 , V_268 ) ;
if ( F_271 ( V_47 , L_55 ) )
goto V_361;
F_138 ( V_2 , V_303 -> V_308 ) ;
}
V_642:
V_47 = F_274 ( V_2 , V_268 , V_558 , type ) ;
V_361:
F_91 ( & V_2 -> V_33 ) ;
F_163 ( V_2 , L_57 ) ;
return V_47 ;
}
static int F_275 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_163 ( V_2 , L_58 ) ;
F_85 ( & V_2 -> V_33 ) ;
F_276 ( V_2 ) ;
F_91 ( & V_2 -> V_33 ) ;
F_163 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_277 ( struct V_1 * V_2 ,
struct V_644 * V_645 )
{
V_119 * V_646 = ( V_119 * ) V_645 -> V_647 ;
struct V_344 * V_308 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
F_163 ( V_2 , L_59 ) ;
V_308 = F_126 ( V_2 ) ;
if ( ! V_308 ) {
V_47 = - V_369 ;
goto V_34;
}
V_47 = F_273 ( V_2 , V_308 , & V_645 -> V_648 ,
V_645 -> V_649 ,
V_645 -> V_650 ) ;
if ( V_47 ) {
F_111 ( V_2 , L_60 ) ;
goto V_34;
}
F_138 ( V_2 , V_308 ) ;
* V_646 = V_308 -> V_20 ;
V_34:
return V_47 ;
}
static int F_278 ( struct V_29 * V_30 ,
struct V_644 * V_645 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_277 ( V_2 , V_645 ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_279 ( struct V_1 * V_2 ,
struct V_644 * V_645 )
{
V_119 * V_646 = ( V_119 * ) V_645 -> V_647 ;
struct V_344 * V_308 = & V_2 -> V_18 [ * V_646 ] ;
F_21 ( & V_2 -> V_33 ) ;
F_142 ( V_2 , V_308 ) ;
}
static void F_280 ( struct V_29 * V_30 ,
struct V_644 * V_645 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_85 ( & V_2 -> V_33 ) ;
F_279 ( V_2 , V_645 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static void F_281 ( struct V_29 * V_30 ,
struct V_644 * V_645 ,
T_1 V_27 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
V_119 * V_646 = ( V_119 * ) V_645 -> V_647 ;
struct V_344 * V_308 = & V_2 -> V_18 [ * V_646 ] ;
if ( F_115 ( ( V_308 -> V_21 > 1 ) &&
( V_27 & ~ ( V_651 |
V_652 |
V_653 |
V_654 ) ) ,
L_61 ,
V_308 -> V_21 , V_27 ) )
return;
F_85 ( & V_2 -> V_33 ) ;
F_188 ( V_2 ) ;
F_273 ( V_2 , V_308 , & V_645 -> V_648 ,
V_645 -> V_649 ,
V_645 -> V_650 ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static int F_282 ( struct V_1 * V_2 ,
struct V_267 * V_268 ,
struct V_644 * V_645 ,
bool V_655 )
{
V_119 * V_646 = ( V_119 * ) V_645 -> V_647 ;
struct V_344 * V_308 = & V_2 -> V_18 [ * V_646 ] ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
V_303 -> V_308 = V_308 ;
switch ( V_268 -> type ) {
case V_123 :
if ( V_655 ) {
V_303 -> V_482 = true ;
break;
}
case V_126 :
V_47 = 0 ;
goto V_34;
case V_121 :
break;
case V_656 :
V_303 -> V_315 = true ;
break;
default:
V_47 = - V_301 ;
goto V_34;
}
V_47 = F_139 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_34;
F_136 ( V_2 ) ;
if ( V_268 -> type == V_656 ) {
V_303 -> V_657 = true ;
V_47 = F_110 ( V_2 , false , NULL ) ;
if ( V_47 )
goto V_658;
V_47 = F_283 ( V_2 , V_268 ) ;
if ( V_47 )
goto V_658;
}
if ( V_268 -> type == V_123 ) {
F_110 ( V_2 , false , NULL ) ;
F_166 ( V_2 , V_268 , false , NULL ) ;
}
if ( V_655 && V_268 -> type == V_121 ) {
T_1 V_558 = 2 * V_268 -> V_383 . V_461 ;
V_47 = F_12 ( V_2 , V_659 ) ;
if ( V_47 )
goto V_658;
F_183 ( V_2 , V_268 , V_558 , V_558 ,
V_268 -> V_383 . V_461 / 2 ,
true ) ;
F_7 ( V_2 , V_659 ) ;
F_110 ( V_2 , false , NULL ) ;
}
goto V_34;
V_658:
F_141 ( V_2 , V_268 ) ;
F_136 ( V_2 ) ;
V_34:
if ( V_47 )
V_303 -> V_308 = NULL ;
return V_47 ;
}
static int F_284 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_644 * V_645 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_47 = F_282 ( V_2 , V_268 , V_645 , false ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_285 ( struct V_1 * V_2 ,
struct V_267 * V_268 ,
struct V_644 * V_645 ,
bool V_655 )
{
struct V_117 * V_303 = F_93 ( V_268 ) ;
struct V_267 * V_660 = NULL ;
F_21 ( & V_2 -> V_33 ) ;
F_190 ( V_2 , V_303 , & V_303 -> V_307 ) ;
switch ( V_268 -> type ) {
case V_126 :
goto V_34;
case V_656 :
V_303 -> V_657 = false ;
V_303 -> V_315 = false ;
F_286 ( V_2 , V_268 ) ;
break;
case V_123 :
if ( ! V_655 || ! V_303 -> V_482 )
goto V_34;
V_303 -> V_486 = false ;
F_287 ( V_2 , V_303 , true ) ;
F_221 ( V_2 -> V_487 , V_268 ) ;
V_303 -> V_482 = false ;
break;
case V_121 :
if ( ! V_655 )
break;
V_660 = V_268 ;
F_166 ( V_2 , V_268 , true , NULL ) ;
break;
default:
break;
}
F_110 ( V_2 , false , V_660 ) ;
F_141 ( V_2 , V_268 ) ;
V_34:
V_303 -> V_308 = NULL ;
F_136 ( V_2 ) ;
}
static void F_288 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_644 * V_645 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
F_85 ( & V_2 -> V_33 ) ;
F_285 ( V_2 , V_268 , V_645 , false ) ;
F_91 ( & V_2 -> V_33 ) ;
}
static int
F_289 ( struct V_1 * V_2 ,
struct V_661 * V_662 )
{
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
F_285 ( V_2 , V_662 [ 0 ] . V_268 , V_662 [ 0 ] . V_663 , true ) ;
F_279 ( V_2 , V_662 [ 0 ] . V_663 ) ;
V_47 = F_277 ( V_2 , V_662 [ 0 ] . V_664 ) ;
if ( V_47 ) {
F_111 ( V_2 , L_62 ) ;
goto V_665;
}
V_47 = F_282 ( V_2 , V_662 [ 0 ] . V_268 , V_662 [ 0 ] . V_664 ,
true ) ;
if ( V_47 ) {
F_111 ( V_2 ,
L_63 ) ;
goto V_481;
}
if ( F_196 ( V_2 ) > 1 )
F_112 ( V_2 ) ;
goto V_34;
V_481:
F_279 ( V_2 , V_662 [ 0 ] . V_664 ) ;
V_665:
if ( F_277 ( V_2 , V_662 [ 0 ] . V_663 ) ) {
F_111 ( V_2 , L_64 ) ;
goto V_666;
}
if ( F_282 ( V_2 , V_662 [ 0 ] . V_268 , V_662 [ 0 ] . V_663 ,
true ) ) {
F_111 ( V_2 , L_65 ) ;
goto V_666;
}
goto V_34;
V_666:
F_290 ( V_2 , false ) ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int
F_291 ( struct V_1 * V_2 ,
struct V_661 * V_662 )
{
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
F_285 ( V_2 , V_662 [ 0 ] . V_268 , V_662 [ 0 ] . V_663 , true ) ;
V_47 = F_282 ( V_2 , V_662 [ 0 ] . V_268 , V_662 [ 0 ] . V_664 ,
true ) ;
if ( V_47 ) {
F_111 ( V_2 ,
L_63 ) ;
goto V_665;
}
goto V_34;
V_665:
if ( F_282 ( V_2 , V_662 [ 0 ] . V_268 , V_662 [ 0 ] . V_663 ,
true ) ) {
F_111 ( V_2 , L_65 ) ;
goto V_666;
}
goto V_34;
V_666:
F_290 ( V_2 , false ) ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_292 ( struct V_29 * V_30 ,
struct V_661 * V_662 ,
int V_667 ,
enum V_668 V_669 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
if ( V_667 > 1 )
return - V_572 ;
switch ( V_669 ) {
case V_670 :
V_47 = F_289 ( V_2 , V_662 ) ;
break;
case V_671 :
V_47 = F_291 ( V_2 , V_662 ) ;
break;
default:
V_47 = - V_572 ;
break;
}
return V_47 ;
}
static int F_293 ( struct V_29 * V_30 ,
struct V_237 * V_238 ,
bool V_672 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_115 * V_520 = F_60 ( V_238 ) ;
if ( ! V_520 || ! V_520 -> V_268 ) {
F_111 ( V_2 , L_66 ) ;
return - V_301 ;
}
return F_194 ( V_2 , V_520 -> V_268 ) ;
}
static int F_294 ( struct V_1 * V_2 ,
struct V_267 * V_268 ,
void * V_255 , int V_206 )
{
struct V_673 * V_674 [ V_675 + 1 ] ;
int V_676 ;
T_1 V_376 ;
V_676 = F_295 ( V_674 , V_675 , V_255 , V_206 , V_677 ) ;
if ( V_676 )
return V_676 ;
if ( ! V_674 [ V_678 ] )
return - V_301 ;
switch ( F_296 ( V_674 [ V_678 ] ) ) {
case V_679 :
if ( ! V_268 || V_268 -> type != V_123 || ! V_268 -> V_365 ||
! V_268 -> V_383 . V_680 ||
! V_674 [ V_681 ] )
return - V_301 ;
V_376 = F_296 ( V_674 [ V_681 ] ) ;
if ( V_376 >= V_268 -> V_383 . V_461 )
return - V_301 ;
V_2 -> V_376 = V_376 ;
V_2 -> V_375 = V_268 ;
return F_110 ( V_2 , false , NULL ) ;
case V_682 :
if ( ! V_268 || V_268 -> type != V_121 ||
! V_268 -> V_383 . V_384 || ! V_268 -> V_383 . V_613 ||
! V_674 [ V_683 ] )
return - V_301 ;
if ( F_296 ( V_674 [ V_683 ] ) )
return F_191 ( V_2 , V_268 , 0 ) ;
return F_137 ( V_2 , V_268 , 0 ) ;
}
return - V_572 ;
}
static int F_297 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
void * V_255 , int V_206 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_676 ;
F_85 ( & V_2 -> V_33 ) ;
V_676 = F_294 ( V_2 , V_268 , V_255 , V_206 ) ;
F_91 ( & V_2 -> V_33 ) ;
return V_676 ;
}
static void F_298 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_684 * V_685 )
{
F_163 ( F_19 ( V_30 ) ,
L_67 ) ;
}
static int F_299 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_684 * V_685 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_267 * V_485 ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
T_1 V_629 ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
V_303 -> V_686 = false ;
F_163 ( V_2 , L_68 ,
V_685 -> V_640 . V_687 ) ;
F_300 ( V_2 , V_268 , V_688 ) ;
switch ( V_268 -> type ) {
case V_123 :
V_485 =
F_250 ( V_2 -> V_485 ,
F_251 ( & V_2 -> V_33 ) ) ;
if ( F_115 ( V_485 && V_485 -> V_689 ,
L_69 ) ) {
V_47 = - V_542 ;
goto V_361;
}
F_221 ( V_2 -> V_485 , V_268 ) ;
if ( F_115 ( V_303 -> V_486 ,
L_70 ) ) {
V_47 = - V_542 ;
goto V_361;
}
break;
case V_121 :
if ( V_303 -> V_456 )
F_181 ( V_268 ,
V_457 ,
0 , 0 ) ;
V_629 = V_685 -> V_690 +
( ( V_268 -> V_383 . V_461 * ( V_685 -> V_386 - 1 ) -
V_691 ) * 1024 ) ;
if ( V_685 -> V_692 )
F_301 ( V_2 , V_268 ) ;
F_302 ( V_2 , V_268 , V_268 -> V_383 . V_461 ,
V_629 ) ;
if ( V_303 -> V_309 . V_477 ) {
V_47 = F_137 ( V_2 , V_268 , 0 ) ;
if ( V_47 )
goto V_361;
}
break;
default:
break;
}
V_303 -> V_315 = true ;
V_47 = F_303 ( V_2 ) ;
if ( V_47 )
goto V_361;
F_112 ( V_2 ) ;
V_361:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static int F_304 ( struct V_29 * V_30 ,
struct V_267 * V_268 )
{
struct V_117 * V_303 = F_93 ( V_268 ) ;
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_303 -> V_686 ) {
V_303 -> V_686 = false ;
V_47 = - V_17 ;
goto V_361;
}
if ( V_268 -> type == V_121 ) {
struct V_115 * V_241 ;
V_241 = F_305 ( V_2 ,
V_303 -> V_305 ) ;
if ( F_8 ( ! V_241 ) ) {
V_47 = - V_17 ;
goto V_361;
}
F_306 ( V_2 , V_241 , false ) ;
F_166 ( V_2 , V_268 , false , NULL ) ;
V_47 = F_191 ( V_2 , V_268 , 0 ) ;
if ( V_47 )
goto V_361;
F_307 ( V_2 , V_268 ) ;
}
V_303 -> V_315 = false ;
V_47 = F_303 ( V_2 ) ;
V_361:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_308 ( struct V_29 * V_30 ,
struct V_267 * V_268 , T_1 V_78 , bool V_256 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 ;
struct V_115 * V_241 ;
struct V_237 * V_238 ;
int V_9 ;
T_1 V_693 = 0 ;
if ( ! V_268 || V_268 -> type != V_121 )
return;
if ( F_40 ( V_2 ) )
F_118 ( & V_2 -> V_342 ) ;
F_85 ( & V_2 -> V_33 ) ;
V_303 = F_93 ( V_268 ) ;
for ( V_9 = 0 ; V_9 < V_245 ; V_9 ++ ) {
V_238 = F_250 ( V_2 -> V_521 [ V_9 ] ,
F_251 ( & V_2 -> V_33 ) ) ;
if ( F_23 ( V_238 ) )
continue;
V_241 = F_60 ( V_238 ) ;
if ( V_241 -> V_268 != V_268 )
continue;
F_8 ( V_9 != V_303 -> V_305 && ! V_238 -> V_540 ) ;
V_693 |= V_241 -> V_694 ;
}
if ( V_256 ) {
if ( F_147 ( V_2 , V_693 , 0 ) )
F_111 ( V_2 , L_71 ) ;
F_91 ( & V_2 -> V_33 ) ;
} else {
F_91 ( & V_2 -> V_33 ) ;
F_148 ( V_2 -> V_7 , V_693 ) ;
}
}
static int F_309 ( struct V_29 * V_30 , int V_695 ,
struct V_696 * V_697 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_47 ;
memset ( V_697 , 0 , sizeof( * V_697 ) ) ;
if ( V_695 != 0 )
return - V_49 ;
if ( ! F_47 ( & V_2 -> V_97 -> V_98 ,
V_698 ) )
return - V_49 ;
F_85 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_699 ) {
V_47 = F_182 ( V_2 , false ) ;
if ( V_47 )
goto V_34;
}
V_697 -> V_700 = V_701 |
V_702 |
V_703 |
V_704 ;
V_697 -> time = V_2 -> V_337 . V_705 +
V_2 -> V_706 . V_705 ;
F_310 ( V_697 -> time , V_707 ) ;
V_697 -> V_708 = V_2 -> V_337 . V_709 +
V_2 -> V_706 . V_709 ;
F_310 ( V_697 -> V_708 , V_707 ) ;
V_697 -> V_710 = V_2 -> V_337 . V_711 +
V_2 -> V_706 . V_711 ;
F_310 ( V_697 -> V_710 , V_707 ) ;
V_697 -> V_712 = V_2 -> V_337 . V_713 +
V_2 -> V_706 . V_713 ;
F_310 ( V_697 -> V_712 , V_707 ) ;
V_47 = 0 ;
V_34:
F_91 ( & V_2 -> V_33 ) ;
return V_47 ;
}
static void F_311 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
struct V_237 * V_238 ,
struct V_714 * V_715 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_117 * V_303 = F_93 ( V_268 ) ;
struct V_115 * V_241 = F_60 ( V_238 ) ;
if ( ! F_47 ( & V_2 -> V_97 -> V_98 ,
V_698 ) )
return;
if ( ! ( V_268 -> V_366 & V_367 ) )
return;
if ( ! V_268 -> V_383 . V_384 )
return;
F_85 ( & V_2 -> V_33 ) ;
if ( V_303 -> V_305 != V_241 -> V_244 )
goto V_716;
if ( F_182 ( V_2 , false ) )
goto V_716;
V_715 -> V_717 = V_303 -> V_358 . V_360 +
V_303 -> V_358 . V_359 ;
V_715 -> V_700 |= F_43 ( V_718 ) ;
if ( V_303 -> V_358 . V_719 ) {
V_715 -> V_720 = V_303 -> V_358 . V_719 ;
V_715 -> V_700 |= F_43 ( V_721 ) ;
}
V_716:
F_91 ( & V_2 -> V_33 ) ;
}
static void F_312 ( struct V_1 * V_2 ,
struct V_267 * V_268 ,
const struct V_722 * V_723 )
{
#define F_313 ( T_5 , T_6 , T_7 , T_8 , T_9 ... ) \
do { \
if ((_cnt) && --(_cnt)) \
break; \
iwl_mvm_fw_dbg_collect_trig(_mvm, _trig, _fmt);\
} while (0)
struct V_273 * V_274 ;
struct V_724 * V_725 ;
if ( ! F_79 ( V_2 -> V_97 , V_726 ) )
return;
V_274 = F_80 ( V_2 -> V_97 , V_726 ) ;
V_725 = ( void * ) V_274 -> V_255 ;
if ( ! F_81 ( V_2 , V_268 , V_274 ) )
return;
if ( V_723 -> V_727 . V_728 . V_255 == V_729 ) {
if ( V_723 -> V_727 . V_728 . V_15 == V_730 )
F_313 ( V_2 , V_274 , V_731 ,
V_725 -> V_732 ,
L_72 ,
V_723 -> V_727 . V_728 . V_507 ) ;
else if ( V_723 -> V_727 . V_728 . V_15 == V_733 )
F_313 ( V_2 , V_274 , V_731 ,
V_725 -> V_734 ,
L_73 ) ;
} else if ( V_723 -> V_727 . V_728 . V_255 == V_735 ) {
if ( V_723 -> V_727 . V_728 . V_15 == V_730 )
F_313 ( V_2 , V_274 , V_731 ,
V_725 -> V_736 ,
L_74 ,
V_723 -> V_727 . V_728 . V_507 ) ;
else if ( V_723 -> V_727 . V_728 . V_15 == V_733 )
F_313 ( V_2 , V_274 , V_731 ,
V_725 -> V_737 ,
L_75 ) ;
} else if ( V_723 -> V_727 . V_728 . V_255 == V_738 ) {
F_313 ( V_2 , V_274 , V_731 ,
V_725 -> V_739 ,
L_76 , V_723 -> V_727 . V_728 . V_507 ) ;
} else if ( V_723 -> V_727 . V_728 . V_255 == V_740 ) {
F_313 ( V_2 , V_274 , V_731 ,
V_725 -> V_741 ,
L_77 , V_723 -> V_727 . V_728 . V_507 ) ;
}
#undef F_313
}
static void F_314 ( struct V_1 * V_2 ,
struct V_267 * V_268 ,
const struct V_722 * V_723 )
{
struct V_273 * V_274 ;
struct V_275 * V_276 ;
if ( ! F_79 ( V_2 -> V_97 , V_277 ) )
return;
V_274 = F_80 ( V_2 -> V_97 , V_277 ) ;
V_276 = ( void * ) V_274 -> V_255 ;
if ( ! F_81 ( V_2 , V_268 , V_274 ) )
return;
if ( ! ( F_315 ( V_276 -> V_742 ) & F_43 ( V_723 -> V_727 . V_743 . V_269 ) ) )
return;
F_226 ( V_2 , V_274 ,
L_78 ,
V_723 -> V_727 . V_743 . V_238 -> V_144 , V_723 -> V_727 . V_743 . V_269 ,
V_723 -> V_727 . V_743 . V_282 ) ;
}
static void
F_316 ( struct V_1 * V_2 ,
struct V_267 * V_268 ,
const struct V_722 * V_723 )
{
struct V_273 * V_274 ;
struct V_275 * V_276 ;
if ( ! F_79 ( V_2 -> V_97 , V_277 ) )
return;
V_274 = F_80 ( V_2 -> V_97 , V_277 ) ;
V_276 = ( void * ) V_274 -> V_255 ;
if ( ! F_81 ( V_2 , V_268 , V_274 ) )
return;
if ( ! ( F_315 ( V_276 -> V_744 ) & F_43 ( V_723 -> V_727 . V_743 . V_269 ) ) )
return;
F_226 ( V_2 , V_274 ,
L_79 ,
V_723 -> V_727 . V_743 . V_238 -> V_144 , V_723 -> V_727 . V_743 . V_269 ) ;
}
static void F_317 ( struct V_29 * V_30 ,
struct V_267 * V_268 ,
const struct V_722 * V_723 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
switch ( V_723 -> type ) {
case V_745 :
F_312 ( V_2 , V_268 , V_723 ) ;
break;
case V_746 :
F_314 ( V_2 , V_268 , V_723 ) ;
break;
case V_747 :
F_316 ( V_2 , V_268 , V_723 ) ;
break;
default:
break;
}
}
void F_318 ( struct V_1 * V_2 ,
struct V_748 * V_448 ,
T_1 V_749 )
{
F_319 ( V_750 ) ;
T_1 V_751 = F_43 ( V_2 -> V_7 -> V_72 ) - 1 ;
int V_47 ;
F_21 ( & V_2 -> V_33 ) ;
if ( ! F_39 ( V_2 ) )
return;
V_448 -> V_752 = V_2 -> V_753 ;
if ( V_448 -> V_754 )
F_320 ( & V_2 -> V_755 ,
V_2 -> V_7 -> V_72 ) ;
V_47 = F_321 ( V_2 , V_751 , ( T_2 * ) V_448 , V_749 ) ;
if ( V_47 ) {
F_111 ( V_2 , L_80 , V_47 ) ;
goto V_34;
}
if ( V_448 -> V_754 )
V_47 = F_13 ( V_750 ,
F_214 ( & V_2 -> V_755 ) == 0 ,
V_16 ) ;
F_15 ( ! V_47 ) ;
V_34:
F_320 ( & V_2 -> V_755 , 0 ) ;
V_2 -> V_753 ++ ;
}
static void F_322 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
struct V_748 V_255 = {
. type = V_756 ,
. V_754 = 1 ,
} ;
F_85 ( & V_2 -> V_33 ) ;
F_318 ( V_2 , & V_255 , sizeof( V_255 ) ) ;
F_91 ( & V_2 -> V_33 ) ;
}
