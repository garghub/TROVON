static inline void * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 + ( V_2 -> V_3 . V_5 * sizeof( struct V_6 ) ) ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_5 = ( V_2 -> V_3 . V_5 + 1 ) & ( V_7 - 1 ) ;
}
static inline void * F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = (struct V_10 * )
( V_9 -> V_12 . V_13 . V_4 + ( V_9 -> V_12 . V_13 . V_5 * sizeof( struct V_10 ) ) ) ;
if ( ! ( F_4 ( V_11 -> V_14 ) & V_15 ) )
return NULL ;
return V_11 ;
}
static inline void F_5 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_13 . V_5 = ( V_9 -> V_12 . V_13 . V_5 + 1 ) & ( V_16 - 1 ) ;
}
static inline struct V_17 * F_6 ( struct V_8 * V_9 )
{
return V_9 -> V_12 . V_18 . V_4 + ( V_9 -> V_12 . V_18 . V_19 * sizeof( struct V_17 ) ) ;
}
static inline void F_7 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_18 . V_19 = ( V_9 -> V_12 . V_18 . V_19 + 1 ) & ( V_20 - 1 ) ;
}
static inline void * F_8 ( struct V_8 * V_9 )
{
return V_9 -> V_12 . V_18 . V_4 + ( V_9 -> V_21 . V_22 * sizeof( struct V_17 ) ) ;
}
enum V_23 F_9 ( enum V_24 V_25 )
{
switch ( V_25 ) {
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
case V_35 :
return V_36 ;
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
}
return V_40 ;
}
static enum V_24 F_10 ( enum V_23 V_25 )
{
switch ( V_25 ) {
case V_27 :
return V_26 ;
case V_29 :
return V_28 ;
case V_31 :
return V_30 ;
case V_33 :
return V_32 ;
case V_36 :
return V_34 ;
case V_38 :
return V_37 ;
case V_40 :
return V_39 ;
}
return V_39 ;
}
static int F_11 ( T_1 V_41 )
{
int V_42 ;
T_2 V_43 = ( V_41 & V_44 ) >>
V_45 ;
T_2 V_46 = ( V_41 & V_47 ) >>
V_48 ;
switch ( V_43 ) {
case V_49 :
case V_50 :
V_42 = - V_51 ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_42 = - V_72 ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
V_42 = - V_77 ;
break;
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_42 = - V_87 ;
break;
case V_88 :
switch ( V_46 ) {
case V_89 :
V_42 = - V_51 ;
break;
}
default:
V_42 = - V_90 ;
}
return V_42 ;
}
char * F_12 ( struct V_8 * V_9 )
{
char * V_91 = L_1 ;
T_3 V_92 ;
V_92 = V_9 -> V_93 . V_94 |
V_9 -> V_93 . V_95 ;
if ( V_92 & V_96 )
V_91 = L_2 ;
else if ( V_92 & V_97 )
V_91 = L_3 ;
else if ( V_92 & V_98 )
V_91 = L_4 ;
return V_91 ;
}
static int F_13 ( T_3 V_99 )
{
int V_42 = - V_72 ;
switch ( V_99 ) {
case V_100 :
V_42 = - V_101 ;
break;
case V_102 :
V_42 = - V_72 ;
break;
case V_103 :
case V_104 :
V_42 = - V_72 ;
break;
case V_105 :
default:
V_42 = - V_72 ;
break;
}
return V_42 ;
}
void F_14 ( struct V_8 * V_9 , T_3 V_106 , bool V_107 ,
bool V_108 , T_3 V_109 )
{
T_1 V_110 = V_106 & V_111 ;
V_110 |= ( ( V_106 & V_112 ) <<
V_113 ) ;
if ( V_107 )
V_110 |= ( 1 << V_114 ) ;
if ( V_108 )
V_110 |= ( 1 << V_115 ) ;
V_110 |= ( V_109 << V_116 ) ;
F_15 ( V_110 , V_9 -> V_117 . V_118 + V_119 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
T_1 V_110 = 0 ;
V_110 |= V_9 -> V_12 . V_18 . V_120 & V_121 ;
V_110 |= 1 << V_122 ;
F_15 ( V_110 , V_9 -> V_117 . V_118 + V_123 ) ;
}
static void F_17 ( struct V_8 * V_9 , T_3 V_124 ,
bool V_125 , bool V_126 , T_3 V_127 )
{
T_1 V_110 = 0 ;
V_110 |= V_124 & V_128 ;
V_110 |= ( ( V_124 & V_129 ) << V_130 ) ;
if ( V_125 )
V_110 |= ( 1 << V_131 ) ;
if ( V_126 )
V_110 |= ( 1 << V_132 ) ;
V_110 |= ( 1 << V_133 ) ;
V_110 |= ( V_127 << V_134 ) ;
F_15 ( V_110 , V_9 -> V_117 . V_118 + V_135 ) ;
}
static void F_18 ( struct V_136 * V_137 ,
T_2 V_138 , T_2 V_139 , T_1 V_140 )
{
V_137 -> V_141 = ( V_138 | ( V_139 << V_142 ) ) ;
V_137 -> V_143 = 20 ;
V_137 -> V_140 = V_140 - sizeof( struct V_136 ) ;
}
static void * F_19 ( T_2 V_138 , T_1 V_140 )
{
struct V_17 * V_144 ;
V_144 = F_20 ( sizeof( struct V_17 ) , V_145 ) ;
if ( ! V_144 )
return NULL ;
V_144 -> V_146 . V_147 |=
( V_148 << V_149 ) &
V_150 ;
V_144 -> V_146 . V_151 = V_140 - sizeof( struct V_152 ) ;
F_18 ( & V_144 -> V_153 . V_154 . V_155 , V_138 , V_156 ,
V_144 -> V_146 . V_151 ) ;
return V_144 ;
}
static void F_21 ( struct V_8 * V_9 , struct V_157 * V_3 )
{
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_3 -> V_159 , V_3 -> V_4 , V_3 -> V_160 ) ;
}
static int F_23 ( struct V_8 * V_9 ,
struct V_157 * V_3 , T_3 V_161 , T_3 V_162 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_161 = V_161 ;
V_3 -> V_162 = V_162 ;
V_3 -> V_159 = V_161 * V_162 ;
V_3 -> V_4 = F_24 ( & V_9 -> V_117 . V_158 -> V_9 , V_3 -> V_159 ,
& V_3 -> V_160 , V_145 ) ;
if ( ! V_3 -> V_4 )
return - V_163 ;
memset ( V_3 -> V_4 , 0 , V_3 -> V_159 ) ;
return 0 ;
}
static void F_25 ( struct V_164 * V_165 , int V_166 ,
T_4 V_167 , int V_168 )
{
int V_169 ;
for ( V_169 = 0 ; V_169 < V_166 ; V_169 ++ ) {
V_165 [ V_169 ] . V_170 = ( T_1 ) ( V_167 & 0xffffffff ) ;
V_165 [ V_169 ] . V_171 = ( T_1 ) F_26 ( V_167 ) ;
V_167 += V_168 ;
}
}
static int F_27 ( struct V_8 * V_9 ,
struct V_157 * V_3 , int V_172 )
{
T_2 V_138 = 0 ;
int V_41 ;
struct V_173 * V_174 = V_9 -> V_175 ;
switch ( V_172 ) {
case V_176 :
V_138 = V_177 ;
break;
case V_178 :
V_138 = V_179 ;
break;
case V_180 :
V_138 = V_181 ;
break;
default:
F_28 () ;
}
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
F_18 ( & V_174 -> V_182 , V_138 , V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_120 = V_3 -> V_120 ;
V_41 = F_29 ( V_9 -> V_117 . V_184 ,
V_174 , sizeof( * V_174 ) , NULL , NULL ) ;
if ( ! V_41 )
V_3 -> V_185 = false ;
return V_41 ;
}
static int F_30 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_41 ;
struct V_186 * V_174 = V_9 -> V_175 ;
struct V_187 * V_188 = V_9 -> V_175 ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
F_18 ( & V_174 -> V_182 , V_189 , V_183 ,
sizeof( * V_174 ) ) ;
V_174 -> V_182 . V_190 = 2 ;
V_174 -> V_191 = 4 ;
V_174 -> V_192 = V_193 ;
V_174 -> V_166 = 4 << V_194 ;
F_25 ( & V_174 -> V_195 [ 0 ] , V_174 -> V_191 , V_2 -> V_3 . V_160 ,
V_196 ) ;
V_41 = F_29 ( V_9 -> V_117 . V_184 , V_174 , sizeof( * V_174 ) , NULL ,
NULL ) ;
if ( ! V_41 ) {
V_2 -> V_3 . V_120 = V_188 -> V_197 & 0xffff ;
V_2 -> V_198 = ( V_188 -> V_197 >> 16 ) & 0xffff ;
V_2 -> V_3 . V_185 = true ;
}
return V_41 ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_3 V_199 )
{
int V_41 ;
V_41 = F_23 ( V_9 , & V_2 -> V_3 , V_7 ,
sizeof( struct V_6 ) ) ;
if ( V_41 )
return V_41 ;
V_41 = F_30 ( V_9 , V_2 ) ;
if ( V_41 )
goto V_200;
V_2 -> V_9 = V_9 ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , true , true , 0 ) ;
return 0 ;
V_200:
F_21 ( V_9 , & V_2 -> V_3 ) ;
return V_41 ;
}
int F_32 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_201 ;
if ( V_9 -> V_117 . V_202 == V_203 )
V_201 = V_9 -> V_117 . V_158 -> V_201 ;
else
V_201 = V_9 -> V_117 . V_204 . V_205 [ V_2 -> V_198 ] ;
return V_201 ;
}
static void F_33 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_185 ) {
F_27 ( V_9 , & V_2 -> V_3 , V_180 ) ;
F_21 ( V_9 , & V_2 -> V_3 ) ;
}
}
static void F_34 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_201 ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , false , false , 0 ) ;
V_201 = F_32 ( V_9 , V_2 ) ;
F_35 ( V_201 , V_2 ) ;
F_33 ( V_9 , V_2 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
int V_169 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ )
F_34 ( V_9 , & V_9 -> V_207 [ V_169 ] ) ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_157 * V_13 ,
struct V_157 * V_2 )
{
struct V_208 * V_174 = V_9 -> V_175 ;
struct V_209 * V_188 = V_9 -> V_175 ;
int V_41 ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
F_18 ( & V_174 -> V_182 , V_210 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_182 . V_190 = V_211 ;
V_174 -> V_212 = ( V_13 -> V_159 / V_213 ) <<
V_214 ;
V_174 -> V_212 |= F_38 ( V_13 -> V_4 , V_13 -> V_159 ) ;
V_174 -> V_215 = V_216 ;
V_174 -> V_217 = V_2 -> V_120 ;
V_174 -> V_218 = V_13 -> V_159 / sizeof( struct V_10 ) ;
F_25 ( & V_174 -> V_195 [ 0 ] , V_13 -> V_159 / V_213 ,
V_13 -> V_160 , V_196 ) ;
V_41 = F_29 ( V_9 -> V_117 . V_184 ,
V_174 , sizeof( * V_174 ) , NULL , NULL ) ;
if ( ! V_41 ) {
V_13 -> V_120 = ( T_3 ) ( V_188 -> V_106 & V_219 ) ;
V_13 -> V_185 = true ;
}
return V_41 ;
}
static T_1 F_39 ( int V_199 )
{
T_1 V_220 = F_40 ( V_199 ) ;
if ( V_220 == 16 )
V_220 = 0 ;
return V_220 ;
}
static int F_41 ( struct V_8 * V_9 ,
struct V_157 * V_12 ,
struct V_157 * V_13 )
{
int V_191 , V_41 ;
struct V_221 * V_174 = V_9 -> V_175 ;
struct V_222 * V_188 = V_9 -> V_175 ;
struct V_164 * V_195 ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
V_191 = F_38 ( V_12 -> V_4 , V_12 -> V_159 ) ;
F_18 ( & V_174 -> V_182 , V_223 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_182 . V_190 = 1 ;
V_174 -> V_224 = V_191 ;
V_174 -> V_224 |= ( V_13 -> V_120 << V_225 ) ;
V_174 -> V_226 = V_227 ;
V_174 -> V_228 = F_42 ( V_229 ) ;
V_174 -> V_228 |= F_42 ( V_230 ) ;
V_174 -> V_231 = V_13 -> V_120 ;
V_174 -> V_231 |= ( F_39 ( V_12 -> V_161 ) <<
V_232 ) ;
V_174 -> V_192 = V_233 ;
V_195 = & V_174 -> V_195 [ 0 ] ;
F_25 ( V_195 , V_191 , V_12 -> V_160 , V_196 ) ;
V_41 = F_29 ( V_9 -> V_117 . V_184 ,
V_174 , sizeof( * V_174 ) , NULL , NULL ) ;
if ( ! V_41 ) {
V_12 -> V_120 = V_188 -> V_120 ;
V_12 -> V_185 = true ;
}
return V_41 ;
}
static int F_43 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_23 ( V_9 , & V_9 -> V_12 . V_13 , V_16 ,
sizeof( struct V_10 ) ) ;
if ( V_41 )
goto V_234;
V_9 -> V_207 [ 0 ] . V_235 ++ ;
V_41 = F_37 ( V_9 , & V_9 -> V_12 . V_13 , & V_9 -> V_207 [ 0 ] . V_3 ) ;
if ( V_41 )
goto V_236;
memset ( & V_9 -> V_21 , 0 , sizeof( V_9 -> V_21 ) ) ;
F_44 ( & V_9 -> V_21 . V_237 ) ;
F_45 ( & V_9 -> V_21 . V_238 ) ;
V_41 = F_23 ( V_9 , & V_9 -> V_12 . V_18 , V_20 ,
sizeof( struct V_17 ) ) ;
if ( V_41 )
goto V_239;
V_41 = F_41 ( V_9 , & V_9 -> V_12 . V_18 , & V_9 -> V_12 . V_13 ) ;
if ( V_41 )
goto V_240;
F_14 ( V_9 , V_9 -> V_12 . V_13 . V_120 , true , false , 0 ) ;
return 0 ;
V_240:
F_21 ( V_9 , & V_9 -> V_12 . V_18 ) ;
V_239:
F_27 ( V_9 , & V_9 -> V_12 . V_13 , V_178 ) ;
V_236:
F_21 ( V_9 , & V_9 -> V_12 . V_13 ) ;
V_234:
return V_41 ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_157 * V_241 , * V_13 ;
F_47 ( & V_9 -> V_21 . V_238 ) ;
V_241 = & V_9 -> V_12 . V_18 ;
if ( V_241 -> V_185 ) {
F_27 ( V_9 , V_241 , V_176 ) ;
F_21 ( V_9 , V_241 ) ;
}
F_48 ( & V_9 -> V_21 . V_238 ) ;
V_13 = & V_9 -> V_12 . V_13 ;
if ( V_13 -> V_185 ) {
F_27 ( V_9 , V_13 , V_178 ) ;
F_21 ( V_9 , V_13 ) ;
}
}
static void F_49 ( struct V_8 * V_9 ,
struct V_242 * V_243 )
{
enum V_23 V_244 = V_40 ;
enum V_23 V_245 ;
if ( V_243 == NULL )
F_28 () ;
F_50 ( V_243 , V_244 , & V_245 ) ;
}
static void F_51 ( struct V_8 * V_9 ,
struct V_246 * V_11 )
{
struct V_242 * V_243 = NULL ;
struct V_247 * V_13 = NULL ;
struct V_248 V_249 ;
int V_250 = 0 ;
int V_251 = 1 ;
int V_252 = 0 ;
int V_253 = 0 ;
int type = ( V_11 -> V_254 & V_255 ) >>
V_256 ;
if ( V_11 -> V_257 & V_258 )
V_243 = V_9 -> V_259 [ V_11 -> V_257 & V_260 ] ;
if ( V_11 -> V_261 & V_262 )
V_13 = V_9 -> V_263 [ V_11 -> V_261 & V_264 ] ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
V_249 . V_265 = & V_9 -> V_266 ;
switch ( type ) {
case V_267 :
V_249 . V_268 . V_13 = & V_13 -> V_269 ;
V_249 . V_270 = V_271 ;
V_250 = 1 ;
V_251 = 0 ;
break;
case V_272 :
V_249 . V_268 . V_13 = & V_13 -> V_269 ;
V_249 . V_270 = V_271 ;
V_250 = 1 ;
V_251 = 0 ;
break;
case V_273 :
V_249 . V_268 . V_243 = & V_243 -> V_274 ;
V_249 . V_270 = V_275 ;
F_49 ( V_9 , V_243 ) ;
break;
case V_276 :
V_249 . V_268 . V_243 = & V_243 -> V_274 ;
V_249 . V_270 = V_277 ;
break;
case V_278 :
V_249 . V_268 . V_243 = & V_243 -> V_274 ;
V_249 . V_270 = V_279 ;
break;
case V_280 :
V_249 . V_268 . V_243 = & V_243 -> V_274 ;
V_249 . V_270 = V_281 ;
break;
case V_282 :
V_249 . V_268 . V_283 = 1 ;
V_249 . V_270 = V_284 ;
V_251 = 0 ;
V_253 = 1 ;
break;
case V_285 :
V_249 . V_268 . V_286 = & V_243 -> V_286 -> V_287 ;
V_249 . V_270 = V_288 ;
V_252 = 1 ;
V_251 = 0 ;
break;
case V_289 :
V_249 . V_268 . V_286 = & V_243 -> V_286 -> V_287 ;
V_249 . V_270 = V_290 ;
V_252 = 1 ;
V_251 = 0 ;
break;
case V_291 :
V_249 . V_268 . V_243 = & V_243 -> V_274 ;
V_249 . V_270 = V_292 ;
break;
default:
V_250 = 0 ;
V_251 = 0 ;
V_252 = 0 ;
V_253 = 0 ;
F_52 ( L_5 , V_293 , type ) ;
break;
}
if ( type < V_294 )
F_53 ( & V_9 -> V_295 [ type ] ) ;
if ( V_251 ) {
if ( V_243 -> V_274 . V_296 )
V_243 -> V_274 . V_296 ( & V_249 , V_243 -> V_274 . V_297 ) ;
} else if ( V_250 ) {
if ( V_13 -> V_269 . V_296 )
V_13 -> V_269 . V_296 ( & V_249 , V_13 -> V_269 . V_298 ) ;
} else if ( V_252 ) {
if ( V_243 -> V_286 -> V_287 . V_296 )
V_243 -> V_286 -> V_287 . V_296 ( & V_249 ,
V_243 -> V_286 -> V_287 .
V_299 ) ;
} else if ( V_253 ) {
F_52 ( L_6 , V_9 -> V_266 . V_300 ) ;
F_54 ( & V_249 ) ;
}
}
static void F_55 ( struct V_8 * V_9 ,
struct V_246 * V_11 )
{
struct V_301 * V_302 ;
int type = ( V_11 -> V_254 & V_255 ) >>
V_256 ;
switch ( type ) {
case V_303 :
V_302 = (struct V_301 * ) V_11 ;
if ( ( V_302 -> V_304 & V_305 ) >>
V_306 )
V_9 -> V_307 = ( ( V_302 -> V_304 &
V_308 ) >>
V_309 ) ;
break;
case V_310 :
F_56 ( & V_9 -> V_311 , 1 ) ;
break;
default:
break;
}
}
static void F_57 ( struct V_8 * V_9 , void * V_312 )
{
struct V_246 * V_11 = V_312 ;
T_1 V_313 = ( V_11 -> V_254 & V_314 ) >>
V_315 ;
if ( V_313 == V_230 )
F_51 ( V_9 , V_11 ) ;
else if ( V_313 == V_229 )
F_55 ( V_9 , V_11 ) ;
else
F_52 ( L_7 , V_293 ,
V_9 -> V_120 , V_313 ) ;
}
static void F_58 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
if ( V_9 -> V_21 . V_22 == V_11 -> V_316 && V_9 -> V_21 . V_317 == false ) {
V_9 -> V_21 . V_99 = ( V_11 -> V_41 &
V_318 ) >> V_319 ;
V_9 -> V_21 . V_320 =
( V_11 -> V_41 & V_321 )
>> V_322 ;
V_9 -> V_21 . V_317 = true ;
F_59 ( & V_9 -> V_21 . V_237 ) ;
} else
F_52 ( L_8 ,
V_293 , V_11 -> V_316 , V_9 -> V_21 . V_22 ) ;
}
static int F_60 ( struct V_8 * V_9 , T_3 V_106 )
{
T_3 V_109 = 0 ;
struct V_10 * V_11 ;
while ( 1 ) {
V_11 = F_3 ( V_9 ) ;
if ( V_11 == NULL )
break;
F_61 ( V_11 , sizeof( * V_11 ) ) ;
V_109 += 1 ;
if ( V_11 -> V_14 & V_323 )
F_57 ( V_9 , V_11 ) ;
else if ( V_11 -> V_14 & V_324 )
F_58 ( V_9 , V_11 ) ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
F_5 ( V_9 ) ;
}
F_14 ( V_9 , V_9 -> V_12 . V_13 . V_120 , true , false , V_109 ) ;
return 0 ;
}
static struct V_247 * F_62 ( struct V_8 * V_9 ,
struct V_247 * V_13 , bool V_18 )
{
struct V_242 * V_243 ;
struct V_325 * V_326 ;
struct V_247 * V_327 = NULL ;
struct V_325 * V_19 = V_18 ? ( & V_13 -> V_328 ) : ( & V_13 -> V_329 ) ;
F_63 (cur, head) {
if ( V_18 )
V_243 = F_64 ( V_326 , struct V_242 , V_330 ) ;
else
V_243 = F_64 ( V_326 , struct V_242 , V_331 ) ;
if ( V_243 -> V_286 )
continue;
if ( V_243 -> V_332 == V_243 -> V_333 )
continue;
if ( V_243 -> V_332 == V_13 )
V_327 = V_243 -> V_333 ;
else
V_327 = V_243 -> V_332 ;
return V_327 ;
}
return NULL ;
}
static void F_65 ( struct V_8 * V_9 ,
struct V_247 * V_13 )
{
unsigned long V_334 ;
struct V_247 * V_327 = NULL ;
F_66 ( & V_9 -> V_335 , V_334 ) ;
V_327 = F_62 ( V_9 , V_13 , true ) ;
if ( V_327 == NULL )
V_327 = F_62 ( V_9 , V_13 , false ) ;
F_67 ( & V_9 -> V_335 , V_334 ) ;
if ( V_327 && V_327 -> V_269 . V_336 ) {
F_66 ( & V_327 -> V_337 , V_334 ) ;
(* V_327 -> V_269 . V_336 ) ( & V_327 -> V_269 , V_327 -> V_269 . V_298 ) ;
F_67 ( & V_327 -> V_337 , V_334 ) ;
}
}
static void F_68 ( struct V_8 * V_9 , T_3 V_338 )
{
unsigned long V_334 ;
struct V_247 * V_13 ;
if ( V_338 >= V_339 )
F_28 () ;
V_13 = V_9 -> V_263 [ V_338 ] ;
if ( V_13 == NULL )
return;
if ( V_13 -> V_269 . V_336 ) {
F_66 ( & V_13 -> V_337 , V_334 ) ;
(* V_13 -> V_269 . V_336 ) ( & V_13 -> V_269 , V_13 -> V_269 . V_298 ) ;
F_67 ( & V_13 -> V_337 , V_334 ) ;
}
F_65 ( V_9 , V_13 ) ;
}
static void F_69 ( struct V_8 * V_9 , T_3 V_106 )
{
if ( V_106 == V_9 -> V_12 . V_13 . V_120 )
F_60 ( V_9 , V_106 ) ;
else
F_68 ( V_9 , V_106 ) ;
}
static T_5 F_70 ( int V_201 , void * V_340 )
{
struct V_1 * V_2 = V_340 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 V_341 ;
struct V_6 * V_342 ;
T_3 V_106 ;
int V_343 = V_2 -> V_235 ;
do {
V_342 = F_1 ( V_2 ) ;
V_341 = * V_342 ;
F_61 ( & V_341 , sizeof( V_341 ) ) ;
if ( ( V_341 . V_344 & V_345 ) == 0 )
break;
V_342 -> V_344 = 0 ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , false , true , 1 ) ;
if ( ( V_341 . V_344 & V_346 ) == 0 ) {
V_106 = V_341 . V_344 >> V_347 ;
F_69 ( V_9 , V_106 ) ;
}
F_2 ( V_2 ) ;
if ( V_343 )
V_343 -- ;
} while ( V_343 );
V_2 -> V_348 . V_349 ++ ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , true , true , 0 ) ;
return V_350 ;
}
static void F_71 ( struct V_8 * V_9 , struct V_17 * V_174 )
{
struct V_17 * V_144 ;
V_9 -> V_21 . V_22 = V_9 -> V_12 . V_18 . V_19 ;
V_9 -> V_21 . V_317 = false ;
V_144 = F_6 ( V_9 ) ;
V_174 -> V_146 . V_316 = V_9 -> V_12 . V_18 . V_19 ;
F_72 ( V_144 , V_174 , sizeof( * V_144 ) ) ;
F_73 () ;
F_7 ( V_9 ) ;
F_16 ( V_9 ) ;
}
static int F_74 ( struct V_8 * V_9 )
{
long V_41 ;
V_41 = F_75 ( V_9 -> V_21 . V_237 ,
( V_9 -> V_21 . V_317 != false ) ,
F_76 ( 30000 ) ) ;
if ( V_41 )
return 0 ;
else {
V_9 -> V_21 . V_351 = true ;
F_52 ( L_9 ,
V_293 , V_9 -> V_120 ) ;
return - 1 ;
}
}
static int F_77 ( struct V_8 * V_9 , struct V_17 * V_144 )
{
int V_41 = 0 ;
T_3 V_99 , V_320 ;
struct V_17 * V_352 ;
struct V_353 * V_188 = NULL ;
F_47 ( & V_9 -> V_21 . V_238 ) ;
if ( V_9 -> V_21 . V_351 )
goto V_200;
F_71 ( V_9 , V_144 ) ;
V_41 = F_74 ( V_9 ) ;
if ( V_41 )
goto V_200;
V_99 = V_9 -> V_21 . V_99 ;
V_320 = V_9 -> V_21 . V_320 ;
V_352 = F_8 ( V_9 ) ;
F_78 ( V_144 , V_352 , ( sizeof( * V_144 ) ) ) ;
if ( ( V_144 -> V_146 . V_147 & V_150 ) >>
V_149 )
V_188 = & V_144 -> V_153 . V_188 ;
if ( V_99 || V_320 ) {
F_52 ( L_10 ,
V_293 , V_99 , V_320 ) ;
if ( V_188 ) {
F_52 ( L_11 ,
( V_188 -> V_141 & V_354 ) >>
V_355 ,
( V_188 -> V_141 & V_356 ) >>
V_357 ) ;
}
V_41 = F_13 ( V_99 ) ;
goto V_200;
}
if ( V_188 && ( V_144 -> V_153 . V_188 . V_41 & V_44 ) )
V_41 = F_11 ( V_144 -> V_153 . V_188 . V_41 ) ;
V_200:
F_48 ( & V_9 -> V_21 . V_238 ) ;
return V_41 ;
}
static int F_79 ( struct V_8 * V_9 , struct V_17 * V_144 ,
void * V_358 )
{
int V_41 = 0 ;
struct V_353 * V_188 = V_358 ;
if ( ( V_144 -> V_146 . V_147 & V_150 ) >>
V_149 )
F_28 () ;
V_41 = F_77 ( V_9 , V_144 ) ;
if ( ! V_41 )
if ( V_188 -> V_41 & V_44 )
V_41 = F_11 ( V_188 -> V_41 ) ;
if ( V_41 )
F_52 ( L_11 ,
( V_188 -> V_141 & V_354 ) >>
V_355 ,
( V_188 -> V_141 & V_356 ) >>
V_357 ) ;
return V_41 ;
}
static void F_80 ( struct V_8 * V_9 ,
struct V_359 * V_360 ,
struct V_361 * V_188 )
{
V_360 -> V_362 =
( V_188 -> V_363 & V_364 ) >>
V_365 ;
V_360 -> V_366 =
( V_188 -> V_367 & V_368 ) >>
V_369 ;
V_360 -> V_370 =
( V_188 -> V_371 & V_372 ) >>
V_373 ;
V_360 -> V_374 =
( V_188 -> V_375 & V_376 ) >>
V_377 ;
V_360 -> V_378 = ( ( V_188 -> V_379 &
V_380 ) >>
V_381 ) ;
V_360 -> V_382 = ( V_188 -> V_379 &
V_380 ) >>
V_381 ;
V_360 -> V_383 = ( V_188 -> V_384 &
V_385 ) >>
V_386 ;
V_360 -> V_387 = ( V_188 -> V_379 &
V_388 ) >>
V_389 ;
V_360 -> V_390 = ( V_188 -> V_391 &
V_392 ) >>
V_393 ;
V_360 -> V_394 = ( V_188 -> V_391 &
V_395 ) >>
V_396 ;
V_360 -> V_397 = ( V_188 -> V_371 &
V_398 ) >>
V_399 ;
V_360 -> V_400 = ( V_188 -> V_371 &
V_401 ) >>
V_402 ;
V_360 -> V_403 = ( V_188 -> V_363 &
V_404 ) >>
V_405 ;
V_360 -> V_406 = V_188 -> V_406 ;
V_360 -> V_407 = V_188 -> V_407 ;
V_360 -> V_408 = ( ( V_409 ) V_188 -> V_410 << 32 ) |
V_188 -> V_411 ;
V_360 -> V_412 = 0 ;
V_360 -> V_413 = V_188 -> V_413 ;
V_360 -> V_414 = V_188 -> V_414 ;
V_360 -> V_415 = V_188 -> V_416 &
V_417 ;
V_360 -> V_418 = ( V_188 -> V_416 &
V_419 ) >>
V_420 ;
V_360 -> V_421 = ( ( V_188 -> V_422 &
V_423 ) >>
V_424 ) *
V_425 ;
V_360 -> V_426 = ( ( V_188 -> V_422 &
V_427 ) >>
V_428 ) *
V_425 ;
V_360 -> V_429 =
V_360 -> V_421 - ( sizeof( struct V_430 ) +
sizeof( struct V_431 ) ) ;
if ( F_81 ( V_9 ) == V_432 ) {
V_360 -> V_433 = 1 ;
V_360 -> V_434 = V_213 ;
V_360 -> V_435 = V_436 ;
}
V_9 -> V_360 . V_437 = V_188 -> V_438 >>
V_439 ;
V_9 -> V_360 . V_440 = V_188 -> V_438 &
V_441 ;
}
static int F_82 ( struct V_8 * V_9 ,
struct V_442 * V_443 )
{
T_1 V_444 ;
V_444 = V_443 -> V_444 & V_445 ;
if ( V_444 != V_445 )
return - V_72 ;
V_9 -> V_446 = V_443 -> V_446 ;
V_9 -> V_447 = V_443 -> V_447 ;
return 0 ;
}
static int F_83 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_448 * V_188 ;
V_174 = F_19 ( V_449 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_449 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_448 * ) V_174 ;
memset ( & V_9 -> V_360 . V_450 [ 0 ] , 0 , sizeof( V_9 -> V_360 . V_450 ) ) ;
memcpy ( & V_9 -> V_360 . V_450 [ 0 ] , & V_188 -> V_451 [ 0 ] ,
sizeof( V_188 -> V_451 ) ) ;
F_61 ( V_9 -> V_360 . V_450 , sizeof( V_188 -> V_451 ) ) ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_85 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_442 * V_188 ;
V_174 = F_19 ( V_452 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_452 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_442 * ) V_174 ;
V_41 = F_82 ( V_9 , V_188 ) ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_86 ( struct V_8 * V_9 , bool V_453 )
{
struct V_454 * V_182 = V_9 -> V_455 . V_4 ;
struct V_17 * V_144 = & V_9 -> V_455 . V_144 ;
struct V_456 * V_457 ;
int V_41 ;
V_457 = F_87 ( sizeof( * V_457 ) , V_145 ) ;
if ( V_457 == NULL )
return - V_163 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> V_146 . V_151 = V_9 -> V_455 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_458 ) &
V_459 ;
V_144 -> V_153 . V_460 . V_461 [ 0 ] . V_462 = ( T_1 ) ( V_9 -> V_455 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_460 . V_461 [ 0 ] . V_463 = ( T_1 ) F_26 ( V_9 -> V_455 . V_195 ) ;
V_144 -> V_153 . V_460 . V_461 [ 0 ] . V_161 = V_9 -> V_455 . V_159 ;
memcpy ( V_457 , V_182 , sizeof( struct V_456 ) ) ;
memset ( V_182 , 0 , V_9 -> V_455 . V_159 ) ;
F_18 ( (struct V_136 * ) V_182 ,
V_464 ,
V_156 ,
V_9 -> V_455 . V_159 ) ;
if ( V_453 )
V_182 -> V_465 = V_453 ;
V_41 = F_79 ( V_9 , V_144 , V_9 -> V_455 . V_4 ) ;
if ( V_41 )
memcpy ( V_182 , V_457 , sizeof( struct V_456 ) ) ;
else
F_61 ( V_182 , V_9 -> V_455 . V_159 ) ;
F_84 ( V_457 ) ;
return V_41 ;
}
static int F_88 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_466 V_160 ;
struct V_17 * V_144 ;
struct V_467 * V_468 ;
struct V_469 * V_470 ;
V_144 = F_20 ( sizeof( struct V_17 ) , V_145 ) ;
if ( ! V_144 )
return V_41 ;
V_160 . V_159 = sizeof( struct V_467 ) ;
V_160 . V_4 = F_24 ( & V_9 -> V_117 . V_158 -> V_9 ,
V_160 . V_159 , & V_160 . V_195 , V_145 ) ;
if ( ! V_160 . V_4 )
goto V_471;
V_144 -> V_146 . V_151 = V_160 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_458 ) &
V_459 ;
V_144 -> V_153 . V_460 . V_461 [ 0 ] . V_462 = ( T_1 ) ( V_160 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_460 . V_461 [ 0 ] . V_463 = ( T_1 ) F_26 ( V_160 . V_195 ) ;
V_144 -> V_153 . V_460 . V_461 [ 0 ] . V_161 = V_160 . V_159 ;
memset ( V_160 . V_4 , 0 , V_160 . V_159 ) ;
F_18 ( (struct V_136 * ) V_160 . V_4 ,
V_472 ,
V_183 ,
V_160 . V_159 ) ;
V_41 = F_79 ( V_9 , V_144 , V_160 . V_4 ) ;
if ( ! V_41 ) {
V_468 = (struct V_467 * ) V_160 . V_4 ;
V_470 = & V_468 -> V_473 . V_470 ;
V_9 -> V_474 = ( V_470 -> V_475 &
V_476 )
>> V_477 ;
strncpy ( V_9 -> V_478 ,
V_470 -> V_479 , 31 ) ;
}
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_160 . V_159 , V_160 . V_4 , V_160 . V_195 ) ;
V_471:
F_84 ( V_144 ) ;
return V_41 ;
}
static int F_89 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_361 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_480 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_361 * ) V_174 ;
F_80 ( V_9 , & V_9 -> V_360 , V_188 ) ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_90 ( struct V_8 * V_9 , T_2 * V_481 )
{
int V_41 = - V_163 ;
struct V_482 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_483 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_483 ,
V_183 , sizeof( * V_174 ) ) ;
( (struct V_136 * ) V_174 -> V_153 . V_174 ) -> V_190 = 0x1 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_482 * ) V_174 ;
* V_481 = ( V_188 -> V_484 & V_485 )
>> V_486 ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_91 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_487 * V_188 ;
V_174 = F_19 ( V_488 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_488 , V_183 ,
sizeof( * V_174 ) ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_487 * ) V_174 ;
V_9 -> V_93 . V_489 =
( V_188 -> V_490 & V_491 ) ;
V_9 -> V_93 . V_492 =
( V_188 -> V_490 & V_493 )
>> V_494 ;
V_9 -> V_93 . V_95 =
( V_188 -> V_495 & V_496 ) ;
V_9 -> V_93 . V_94 =
( V_188 -> V_495 & V_497 )
>> V_498 ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_92 ( struct V_8 * V_9 , struct V_499 * V_500 )
{
int V_41 = - V_163 ;
struct V_501 * V_174 ;
struct V_502 * V_188 ;
V_174 = F_19 ( V_503 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
if ( V_500 -> V_504 )
V_174 -> V_505 |= V_506 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_502 * ) V_174 ;
V_500 -> V_120 = V_188 -> V_507 & V_508 ;
if ( V_188 -> V_507 & V_509 ) {
V_500 -> V_504 = true ;
V_500 -> V_510 = V_188 -> V_507 >>
V_511 ;
} else {
V_500 -> V_504 = false ;
V_500 -> V_512 = 0 ;
}
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_93 ( struct V_8 * V_9 , struct V_499 * V_500 )
{
int V_41 = - V_163 ;
struct V_513 * V_174 ;
V_174 = F_19 ( V_514 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_500 -> V_120 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_94 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
T_6 V_515 ;
struct V_516 * V_174 ;
struct V_517 * V_188 ;
V_174 = F_19 ( V_518 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_519 = V_9 -> V_360 . V_366 ;
V_174 -> V_505 |= V_506 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_517 * ) V_174 ;
if ( ( V_188 -> V_507 & V_509 ) && V_188 -> V_519 ) {
V_9 -> V_520 -> V_521 = V_188 -> V_507 >>
V_511 ;
V_9 -> V_520 -> V_522 = V_188 -> V_507 &
V_523 ;
V_9 -> V_520 -> V_524 = V_188 -> V_519 ;
V_515 = F_95 ( V_188 -> V_519 ) * sizeof( long ) ;
V_9 -> V_520 -> V_525 = F_20 ( V_515 ,
V_145 ) ;
}
F_84 ( V_174 ) ;
V_174 = F_19 ( V_518 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_519 = V_9 -> V_360 . V_362 - V_9 -> V_360 . V_366 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_517 * ) V_174 ;
if ( V_188 -> V_519 ) {
V_9 -> V_520 -> V_526 = V_188 -> V_507 &
V_523 ;
V_9 -> V_520 -> V_527 = V_188 -> V_519 ;
V_515 = F_95 ( V_188 -> V_519 ) * sizeof( long ) ;
V_9 -> V_520 -> V_528 = F_20 ( V_515 ,
V_145 ) ;
}
if ( V_9 -> V_520 -> V_528 || V_9 -> V_520 -> V_525 ) {
V_9 -> V_520 -> V_529 = true ;
} else {
return - V_163 ;
}
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static void F_96 ( struct V_8 * V_9 )
{
struct V_530 * V_174 ;
V_174 = F_19 ( V_531 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
if ( V_9 -> V_520 -> V_527 ) {
V_174 -> V_532 = V_9 -> V_520 -> V_526 ;
V_174 -> V_519 = V_9 -> V_520 -> V_527 ;
F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
}
if ( V_9 -> V_520 -> V_524 ) {
F_84 ( V_174 ) ;
V_174 = F_19 ( V_531 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
V_174 -> V_532 = V_9 -> V_520 -> V_522 ;
V_174 -> V_519 = V_9 -> V_520 -> V_524 ;
F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
}
V_200:
F_84 ( V_174 ) ;
}
void F_97 ( struct V_8 * V_9 )
{
int V_41 ;
V_9 -> V_520 = F_20 ( sizeof( struct V_533 ) ,
V_145 ) ;
if ( ! V_9 -> V_520 ) {
F_52 ( L_12 , V_293 , V_9 -> V_120 ) ;
return;
}
V_41 = F_94 ( V_9 ) ;
if ( V_41 ) {
F_52 ( L_13 ,
V_293 , V_9 -> V_120 ) ;
}
}
static void F_98 ( struct V_8 * V_9 )
{
F_96 ( V_9 ) ;
F_84 ( V_9 -> V_520 -> V_528 ) ;
F_84 ( V_9 -> V_520 -> V_525 ) ;
F_84 ( V_9 -> V_520 ) ;
}
static int F_99 ( T_1 * V_534 , int V_162 ,
int * V_191 , int * V_535 )
{
int V_169 ;
int V_536 ;
* V_534 = F_100 ( * V_534 ) ;
V_536 = * V_534 * V_162 ;
for ( V_169 = 0 ; V_169 < V_537 ; V_169 ++ ) {
if ( V_536 <= ( V_538 << V_169 ) )
break;
}
if ( V_169 >= V_537 )
return - V_72 ;
V_536 = F_101 ( V_536 ,
( ( V_538 << V_169 ) / V_539 ) ) ;
* V_191 =
V_536 / ( ( V_538 << V_169 ) / V_539 ) ;
* V_535 = ( ( V_538 << V_169 ) / V_539 ) ;
* V_534 = V_536 / V_162 ;
return 0 ;
}
static int F_102 ( struct V_8 * V_9 )
{
int V_169 ;
int V_41 = 0 ;
int V_540 ;
struct V_541 * V_174 ;
struct V_542 * V_188 ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 ;
struct V_544 * V_545 ;
V_174 = F_19 ( V_546 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_540 = V_547 ;
V_9 -> V_548 . V_159 = sizeof( struct V_549 ) * V_540 ;
V_174 -> V_550 = ( V_551 <<
V_552 ) &
V_553 ;
for ( V_169 = 0 ; V_169 < V_537 ; V_169 ++ ) {
if ( V_554 == ( V_213 << V_169 ) )
break;
}
V_174 -> V_550 |= ( V_169 << V_555 ) &
V_556 ;
V_174 -> V_550 |= ( sizeof( struct V_549 ) <<
V_557 ) &
V_558 ;
V_9 -> V_548 . V_559 . V_4 = F_24 ( & V_158 -> V_9 , V_554 ,
& V_9 -> V_548 . V_559 . V_195 ,
V_145 ) ;
if ( V_9 -> V_548 . V_559 . V_4 == NULL )
goto V_560;
V_9 -> V_548 . V_4 = F_24 ( & V_158 -> V_9 , V_9 -> V_548 . V_159 ,
& V_195 , V_145 ) ;
if ( V_9 -> V_548 . V_4 == NULL )
goto V_561;
V_9 -> V_548 . V_195 = V_195 ;
V_9 -> V_548 . V_562 = V_540 ;
memset ( V_9 -> V_548 . V_4 , 0 , V_9 -> V_548 . V_159 ) ;
V_545 = (struct V_544 * ) V_9 -> V_548 . V_559 . V_4 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_548 . V_159 / V_213 ; V_169 ++ ) {
V_545 [ V_169 ] . V_462 = ( T_1 ) F_103 ( V_195 & 0xffffffff ) ;
V_545 [ V_169 ] . V_463 = ( T_1 ) F_103 ( F_26 ( V_195 ) ) ;
V_195 += V_554 ;
}
V_174 -> V_563 [ 0 ] . V_170 = ( T_1 ) ( V_9 -> V_548 . V_559 . V_195 & 0xFFFFFFFF ) ;
V_174 -> V_563 [ 0 ] . V_171 = ( T_1 ) F_26 ( V_9 -> V_548 . V_559 . V_195 ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_542 * ) V_174 ;
V_9 -> V_548 . V_564 = V_188 -> V_564 & 0xFFFF ;
F_84 ( V_174 ) ;
return 0 ;
V_200:
F_22 ( & V_158 -> V_9 , V_9 -> V_548 . V_159 , V_9 -> V_548 . V_4 ,
V_9 -> V_548 . V_195 ) ;
V_9 -> V_548 . V_4 = NULL ;
V_561:
F_22 ( & V_158 -> V_9 , V_554 , V_9 -> V_548 . V_559 . V_4 ,
V_9 -> V_548 . V_559 . V_195 ) ;
V_9 -> V_548 . V_559 . V_4 = NULL ;
V_9 -> V_548 . V_159 = 0 ;
V_560:
F_84 ( V_174 ) ;
return V_41 ;
}
static void F_104 ( struct V_8 * V_9 )
{
struct V_565 * V_174 ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
if ( V_9 -> V_548 . V_4 == NULL )
return;
V_174 = F_19 ( V_566 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return;
V_174 -> V_564 = V_9 -> V_548 . V_564 ;
F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
F_22 ( & V_158 -> V_9 , V_9 -> V_548 . V_159 , V_9 -> V_548 . V_4 ,
V_9 -> V_548 . V_195 ) ;
V_9 -> V_548 . V_4 = NULL ;
F_22 ( & V_158 -> V_9 , V_554 , V_9 -> V_548 . V_559 . V_4 ,
V_9 -> V_548 . V_559 . V_195 ) ;
F_84 ( V_174 ) ;
}
static T_3 F_105 ( struct V_8 * V_9 )
{
int V_169 , V_567 = 0 , V_235 = 0 ;
T_3 V_124 ;
F_47 ( & V_9 -> V_568 ) ;
V_235 = V_9 -> V_207 [ 0 ] . V_235 ;
V_124 = V_9 -> V_207 [ 0 ] . V_3 . V_120 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
if ( V_9 -> V_207 [ V_169 ] . V_235 < V_235 ) {
V_235 = V_9 -> V_207 [ V_169 ] . V_235 ;
V_124 = V_9 -> V_207 [ V_169 ] . V_3 . V_120 ;
V_567 = V_169 ;
}
}
V_9 -> V_207 [ V_567 ] . V_235 += 1 ;
F_48 ( & V_9 -> V_568 ) ;
return V_124 ;
}
static void F_106 ( struct V_8 * V_9 , T_3 V_124 )
{
int V_169 ;
F_47 ( & V_9 -> V_568 ) ;
V_169 = F_107 ( V_9 , V_124 ) ;
if ( V_169 == - V_72 )
F_28 () ;
V_9 -> V_207 [ V_169 ] . V_235 -= 1 ;
F_48 ( & V_9 -> V_568 ) ;
}
int F_108 ( struct V_8 * V_9 , struct V_247 * V_13 ,
int V_569 , int V_570 , T_3 V_571 )
{
int V_41 = - V_163 ; int V_572 ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
struct V_573 * V_174 ;
struct V_574 * V_188 ;
T_1 V_575 , V_576 , V_535 , V_577 ;
if ( V_569 > V_9 -> V_360 . V_415 ) {
F_52 ( L_14 ,
V_293 , V_9 -> V_120 , V_9 -> V_360 . V_415 , V_569 ) ;
return - V_72 ;
}
if ( V_570 && ( F_81 ( V_9 ) != V_432 ) )
return - V_72 ;
if ( V_570 ) {
V_13 -> V_572 = 1 ;
V_572 = 1 ;
V_576 = V_578 ;
V_575 = 1 ;
} else {
V_13 -> V_572 = V_9 -> V_360 . V_415 ;
V_572 = V_9 -> V_360 . V_415 ;
V_576 = sizeof( struct V_579 ) ;
V_575 = V_580 ;
}
V_13 -> V_161 = F_101 ( V_572 * V_576 , V_213 ) ;
V_174 = F_19 ( V_210 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( & V_174 -> V_174 . V_182 , V_210 ,
V_183 , sizeof( * V_174 ) ) ;
V_13 -> V_4 = F_24 ( & V_158 -> V_9 , V_13 -> V_161 , & V_13 -> V_195 , V_145 ) ;
if ( ! V_13 -> V_4 ) {
V_41 = - V_163 ;
goto V_560;
}
memset ( V_13 -> V_4 , 0 , V_13 -> V_161 ) ;
V_535 = V_13 -> V_161 / V_575 ;
V_174 -> V_174 . V_212 = ( V_535 / V_213 ) <<
V_214 ;
V_174 -> V_174 . V_212 |= V_575 ;
V_174 -> V_174 . V_215 = V_216 ;
V_13 -> V_217 = F_105 ( V_9 ) ;
V_174 -> V_174 . V_182 . V_190 = V_581 ;
V_577 = V_13 -> V_161 / V_576 ;
V_13 -> V_582 = V_577 ;
if ( V_577 > 1024 ) {
V_174 -> V_174 . V_215 |= ( 0x3 << V_583 ) ;
} else {
T_2 V_584 = 0 ;
switch ( V_577 ) {
case 256 :
V_584 = 0 ;
break;
case 512 :
V_584 = 1 ;
break;
case 1024 :
V_584 = 2 ;
break;
default:
goto V_200;
}
V_174 -> V_174 . V_215 |= ( V_584 << V_583 ) ;
}
V_174 -> V_174 . V_217 = V_13 -> V_217 ;
if ( F_81 ( V_9 ) == V_432 ) {
if ( V_570 )
V_174 -> V_174 . V_212 |= V_585 <<
V_586 ;
V_13 -> V_587 = false ;
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_576 ) ;
} else {
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_576 ) - 1 ;
V_174 -> V_174 . V_215 |= V_588 ;
V_13 -> V_587 = true ;
}
V_174 -> V_174 . V_218 |= ( V_571 <<
V_589 ) ;
F_25 ( & V_174 -> V_174 . V_195 [ 0 ] , V_575 , V_13 -> V_195 , V_535 ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_574 * ) V_174 ;
V_13 -> V_120 = ( T_3 ) ( V_188 -> V_188 . V_106 & V_219 ) ;
F_84 ( V_174 ) ;
return 0 ;
V_200:
F_106 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
V_560:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_109 ( struct V_8 * V_9 , struct V_247 * V_13 )
{
int V_41 = - V_163 ;
struct V_590 * V_174 ;
V_174 = F_19 ( V_179 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_182 , V_179 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_591 |=
( V_13 -> V_120 << V_592 ) &
V_593 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
F_106 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
int F_110 ( struct V_8 * V_9 , struct V_594 * V_595 ,
T_1 V_596 , int V_597 )
{
int V_41 = - V_163 ;
struct V_598 * V_174 ;
struct V_599 * V_188 ;
V_174 = F_19 ( V_600 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_596 = V_596 ;
V_174 -> V_601 |= V_597 ;
V_174 -> V_601 |= ( V_595 -> V_602 << V_603 ) ;
V_174 -> V_601 |=
( V_595 -> V_604 << V_605 ) ;
V_174 -> V_601 |=
( V_595 -> V_606 << V_607 ) ;
V_174 -> V_601 |=
( V_595 -> V_608 << V_609 ) ;
V_174 -> V_601 |=
( V_595 -> V_610 << V_611 ) ;
V_174 -> V_601 |=
( V_595 -> V_612 << V_613 ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_599 * ) V_174 ;
V_595 -> V_614 = V_188 -> V_615 ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_111 ( struct V_8 * V_9 , int V_602 , T_1 V_614 )
{
int V_41 = - V_163 ;
struct V_616 * V_174 ;
V_174 = F_19 ( V_617 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_614 = V_614 ;
V_174 -> V_618 = V_602 ? 1 : 0 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_112 ( struct V_8 * V_9 , struct V_594 * V_595 ,
T_1 V_596 , T_1 V_619 , T_1 V_620 , T_1 V_621 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_622 * V_174 ;
struct V_623 * V_188 ;
V_174 = F_19 ( V_624 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_625 =
V_596 | ( V_595 -> V_612 << V_626 ) ;
V_174 -> V_602 = V_595 -> V_602 ;
V_174 -> V_627 |= ( V_595 -> V_604 <<
V_628 ) ;
V_174 -> V_627 |= ( V_595 -> V_606 <<
V_629 ) ;
V_174 -> V_627 |= ( V_595 -> V_608 <<
V_630 ) ;
V_174 -> V_627 |= ( V_595 -> V_610 <<
V_631 ) ;
V_174 -> V_627 |= ( V_595 -> V_632 <<
V_633 ) ;
V_174 -> V_627 |= ( V_621 << V_634 ) ;
V_174 -> V_627 |= ( V_595 -> V_620 / V_635 ) ;
V_174 -> V_627 |= ( V_595 -> V_636 / V_635 ) <<
V_637 ;
V_174 -> V_638 = V_595 -> V_161 ;
V_174 -> V_639 = F_26 ( V_595 -> V_161 ) ;
V_174 -> V_640 = ( T_1 ) ( V_595 -> V_641 & 0xffffffff ) ;
V_174 -> V_642 = ( T_1 ) F_26 ( V_595 -> V_641 ) ;
V_174 -> V_643 = ( T_1 ) V_595 -> V_4 ;
V_174 -> V_644 = ( T_1 ) F_26 ( V_595 -> V_4 ) ;
for ( V_169 = 0 ; V_169 < V_619 ; V_169 ++ ) {
V_174 -> V_559 [ V_169 ] . V_170 = ( T_1 ) ( V_595 -> V_645 [ V_169 ] . V_195 & 0xffffffff ) ;
V_174 -> V_559 [ V_169 ] . V_171 = F_26 ( V_595 -> V_645 [ V_169 ] . V_195 ) ;
}
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_623 * ) V_174 ;
V_595 -> V_614 = V_188 -> V_615 ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_113 ( struct V_8 * V_9 ,
struct V_594 * V_595 , T_1 V_619 ,
T_1 V_646 , T_1 V_621 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_647 * V_174 ;
V_174 = F_19 ( V_648 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_615 = V_595 -> V_614 ;
V_174 -> V_649 = ( V_619 << V_650 ) |
( V_646 & V_651 ) ;
V_174 -> V_621 = V_621 << V_652 ;
for ( V_169 = 0 ; V_169 < V_619 ; V_169 ++ ) {
V_174 -> V_559 [ V_169 ] . V_170 =
( T_1 ) ( V_595 -> V_645 [ V_169 + V_646 ] . V_195 & 0xffffffff ) ;
V_174 -> V_559 [ V_169 ] . V_171 =
F_26 ( V_595 -> V_645 [ V_169 + V_646 ] . V_195 ) ;
}
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_114 ( struct V_8 * V_9 ,
struct V_594 * V_595 , T_1 V_596 , int V_653 )
{
int V_41 ;
T_1 V_621 = 0 ;
T_1 V_654 , V_646 ;
T_1 V_655 = V_595 -> V_612 ;
V_646 = 0 ;
V_654 = F_115 ( V_655 , V_656 ) ;
if ( V_654 == V_655 )
V_621 = 1 ;
V_41 = F_112 ( V_9 , V_595 , V_596 ,
V_654 , V_595 -> V_620 , V_621 ) ;
if ( V_41 ) {
F_52 ( L_15 , V_293 , V_41 ) ;
return V_41 ;
}
if ( V_621 )
return 0 ;
while ( ! V_621 ) {
V_646 += V_654 ;
V_655 -= V_654 ;
V_654 = F_115 ( V_655 , V_656 ) ;
if ( V_654 == V_655 )
V_621 = 1 ;
V_41 = F_113 ( V_9 , V_595 , V_654 ,
V_646 , V_621 ) ;
if ( V_41 )
break;
}
if ( V_41 )
F_52 ( L_16 , V_293 , V_41 ) ;
return V_41 ;
}
bool F_116 ( struct V_247 * V_13 , struct V_242 * V_243 )
{
struct V_242 * V_657 ;
bool V_658 = false ;
F_117 (tmp, &cq->sq_head, sq_entry) {
if ( V_243 == V_657 ) {
V_658 = true ;
break;
}
}
return V_658 ;
}
bool F_118 ( struct V_247 * V_13 , struct V_242 * V_243 )
{
struct V_242 * V_657 ;
bool V_658 = false ;
F_117 (tmp, &cq->rq_head, rq_entry) {
if ( V_243 == V_657 ) {
V_658 = true ;
break;
}
}
return V_658 ;
}
void F_119 ( struct V_242 * V_243 )
{
bool V_658 ;
unsigned long V_334 ;
struct V_8 * V_9 = F_120 ( V_243 -> V_274 . V_265 ) ;
F_66 ( & V_9 -> V_335 , V_334 ) ;
V_658 = F_116 ( V_243 -> V_332 , V_243 ) ;
if ( ! V_658 )
F_121 ( & V_243 -> V_330 , & V_243 -> V_332 -> V_328 ) ;
if ( ! V_243 -> V_286 ) {
V_658 = F_118 ( V_243 -> V_333 , V_243 ) ;
if ( ! V_658 )
F_121 ( & V_243 -> V_331 , & V_243 -> V_333 -> V_329 ) ;
}
F_67 ( & V_9 -> V_335 , V_334 ) ;
}
static void F_122 ( struct V_242 * V_243 )
{
V_243 -> V_18 . V_19 = 0 ;
V_243 -> V_18 . V_5 = 0 ;
V_243 -> V_659 . V_19 = 0 ;
V_243 -> V_659 . V_5 = 0 ;
}
int F_50 ( struct V_242 * V_243 , enum V_23 V_660 ,
enum V_23 * V_661 )
{
unsigned long V_334 ;
int V_41 = 0 ;
enum V_24 V_662 ;
V_662 = F_10 ( V_660 ) ;
F_66 ( & V_243 -> V_663 , V_334 ) ;
if ( V_661 )
* V_661 = F_9 ( V_243 -> V_664 ) ;
if ( V_662 == V_243 -> V_664 ) {
F_67 ( & V_243 -> V_663 , V_334 ) ;
return 1 ;
}
if ( V_662 == V_28 ) {
F_122 ( V_243 ) ;
F_123 ( V_243 ) ;
} else if ( V_662 == V_39 ) {
F_119 ( V_243 ) ;
}
V_243 -> V_664 = V_662 ;
F_67 ( & V_243 -> V_663 , V_334 ) ;
return V_41 ;
}
static T_1 F_124 ( struct V_242 * V_243 )
{
T_1 V_334 = 0 ;
if ( V_243 -> V_665 & V_666 )
V_334 |= V_667 ;
if ( V_243 -> V_665 & V_668 )
V_334 |= V_669 ;
if ( V_243 -> V_665 & V_670 )
V_334 |= V_671 ;
if ( V_243 -> V_665 & V_672 )
V_334 |= V_673 ;
if ( V_243 -> V_665 & V_674 )
V_334 |= V_675 ;
return V_334 ;
}
static int F_125 ( struct V_676 * V_174 ,
struct V_677 * V_678 ,
struct V_242 * V_243 )
{
int V_41 ;
T_1 V_161 , V_575 , V_168 ;
T_4 V_195 ;
struct V_499 * V_500 = V_243 -> V_500 ;
struct V_8 * V_9 = F_120 ( V_500 -> V_679 . V_265 ) ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_680 ;
T_1 V_681 = V_678 -> V_682 . V_378 ;
V_680 = F_126 ( T_1 , V_678 -> V_682 . V_683 + 1 ,
V_9 -> V_360 . V_437 ) ;
V_41 = F_99 ( & V_680 ,
V_9 -> V_360 . V_421 , & V_575 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_17 , V_293 ,
V_680 ) ;
return - V_72 ;
}
V_243 -> V_18 . V_684 = V_680 ;
V_161 = ( V_575 * V_168 ) ;
V_243 -> V_18 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_243 -> V_18 . V_4 )
return - V_72 ;
memset ( V_243 -> V_18 . V_4 , 0 , V_161 ) ;
V_243 -> V_18 . V_161 = V_161 ;
V_243 -> V_18 . V_195 = V_195 ;
V_243 -> V_18 . V_162 = V_9 -> V_360 . V_421 ;
F_25 ( & V_174 -> V_685 [ 0 ] , V_575 , V_195 , V_168 ) ;
V_174 -> V_686 |= ( F_127 ( V_168 / V_213 )
<< V_687 ) ;
V_174 -> V_688 |= ( V_575 <<
V_689 ) &
V_690 ;
V_174 -> V_691 |= ( V_681 <<
V_692 ) &
V_693 ;
V_174 -> V_691 |= ( V_681 <<
V_694 ) &
V_695 ;
V_174 -> V_696 |= ( F_127 ( V_243 -> V_18 . V_684 ) <<
V_697 ) &
V_698 ;
V_174 -> V_699 |= ( V_9 -> V_360 . V_421 <<
V_700 ) &
V_701 ;
return 0 ;
}
static int F_128 ( struct V_676 * V_174 ,
struct V_677 * V_678 ,
struct V_242 * V_243 )
{
int V_41 ;
T_1 V_161 , V_575 , V_168 ;
T_4 V_195 = 0 ;
struct V_499 * V_500 = V_243 -> V_500 ;
struct V_8 * V_9 = F_120 ( V_500 -> V_679 . V_265 ) ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_702 = V_678 -> V_682 . V_703 + 1 ;
V_41 = F_99 ( & V_702 , V_9 -> V_360 . V_426 ,
& V_575 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_18 , V_293 ,
V_678 -> V_682 . V_703 + 1 ) ;
return V_41 ;
}
V_243 -> V_659 . V_684 = V_702 ;
V_161 = ( V_575 * V_168 ) ;
V_243 -> V_659 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_243 -> V_659 . V_4 )
return - V_163 ;
memset ( V_243 -> V_659 . V_4 , 0 , V_161 ) ;
V_243 -> V_659 . V_195 = V_195 ;
V_243 -> V_659 . V_161 = V_161 ;
V_243 -> V_659 . V_162 = V_9 -> V_360 . V_426 ;
F_25 ( & V_174 -> V_704 [ 0 ] , V_575 , V_195 , V_168 ) ;
V_174 -> V_686 |= ( F_127 ( V_168 / V_213 ) <<
V_705 ) ;
V_174 -> V_688 |=
( V_575 << V_706 ) &
V_707 ;
V_174 -> V_708 |= ( V_678 -> V_682 . V_382 <<
V_709 ) &
V_710 ;
V_174 -> V_696 |= ( F_127 ( V_243 -> V_659 . V_684 ) <<
V_711 ) &
V_712 ;
V_174 -> V_699 |= ( V_9 -> V_360 . V_426 <<
V_713 ) &
V_714 ;
return 0 ;
}
static void F_129 ( struct V_676 * V_174 ,
struct V_499 * V_500 ,
struct V_242 * V_243 ,
T_2 V_715 , T_3 V_716 )
{
V_500 -> V_512 -- ;
V_243 -> V_504 = true ;
V_174 -> V_708 |= V_717 ;
if ( ! V_715 )
return;
V_174 -> V_708 |= V_717 ;
V_174 -> V_718 = V_716 ;
V_174 -> V_718 |= V_719 <<
V_720 ;
}
static int F_130 ( struct V_676 * V_174 ,
struct V_242 * V_243 )
{
struct V_499 * V_500 = V_243 -> V_500 ;
struct V_8 * V_9 = F_120 ( V_500 -> V_679 . V_265 ) ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 = 0 ;
int V_434 = V_9 -> V_360 . V_434 ;
int V_721 = V_9 -> V_360 . V_435 * V_434 ;
struct V_430 * V_722 ;
int V_169 = 0 ;
if ( V_9 -> V_360 . V_433 == 0 )
return 0 ;
V_243 -> V_723 = F_24 ( & V_158 -> V_9 , V_721 ,
& V_195 , V_145 ) ;
if ( ! V_243 -> V_723 )
return - V_163 ;
memset ( V_243 -> V_723 , 0 , V_721 ) ;
F_25 ( & V_174 -> V_724 [ 0 ] , V_9 -> V_360 . V_435 ,
V_195 , V_434 ) ;
for (; V_169 < V_721 / V_9 -> V_360 . V_426 ; V_169 ++ ) {
V_722 = (struct V_430 * ) ( V_243 -> V_723 +
( V_169 * V_9 -> V_360 . V_426 ) ) ;
V_722 -> V_725 = 0 ;
V_722 -> V_725 |= 2 ;
V_722 -> V_725 |= ( V_726 << V_727 ) ;
V_722 -> V_725 |= ( 8 << V_728 ) ;
V_722 -> V_725 |= ( 8 << V_729 ) ;
}
return 0 ;
}
static void F_131 ( struct V_730 * V_188 ,
struct V_242 * V_243 ,
struct V_677 * V_678 ,
T_3 * V_731 , T_3 * V_732 )
{
T_1 V_680 , V_702 ;
V_243 -> V_120 = V_188 -> V_733 & V_734 ;
V_243 -> V_659 . V_735 = V_188 -> V_736 & V_737 ;
V_243 -> V_18 . V_735 = V_188 -> V_736 >> V_738 ;
V_243 -> V_739 = V_188 -> V_740 & V_741 ;
V_243 -> V_742 = ( V_188 -> V_740 >> V_743 ) ;
V_243 -> V_504 = false ;
if ( V_188 -> V_744 & V_745 ) {
V_243 -> V_504 = true ;
* V_732 = ( V_188 -> V_744 &
V_746 ) >>
V_747 ;
* V_731 = ( V_188 -> V_744 &
V_748 ) >>
V_749 ;
}
V_680 =
V_188 -> V_696 >> V_750 ;
V_680 = 1 << V_680 ;
V_702 = 1 << ( ( T_3 ) V_188 -> V_696 ) ;
V_243 -> V_18 . V_684 = V_680 ;
V_243 -> V_18 . V_751 = V_680 - 1 ;
if ( ! V_678 -> V_286 ) {
V_243 -> V_659 . V_684 = V_702 ;
V_243 -> V_659 . V_751 = V_702 - 1 ;
}
}
int F_132 ( struct V_242 * V_243 , struct V_677 * V_678 ,
T_2 V_715 , T_3 V_716 , T_3 * V_731 ,
T_3 * V_732 )
{
int V_41 = - V_163 ;
T_1 V_334 = 0 ;
struct V_499 * V_500 = V_243 -> V_500 ;
struct V_8 * V_9 = F_120 ( V_500 -> V_679 . V_265 ) ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
struct V_247 * V_13 ;
struct V_676 * V_174 ;
struct V_730 * V_188 ;
int V_752 ;
switch ( V_678 -> V_753 ) {
case V_754 :
V_752 = V_755 ;
break;
case V_756 :
V_752 = V_757 ;
break;
case V_758 :
V_752 = V_759 ;
break;
default:
return - V_72 ;
}
V_174 = F_19 ( V_760 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_686 |= ( V_752 << V_761 ) &
V_762 ;
V_41 = F_125 ( V_174 , V_678 , V_243 ) ;
if ( V_41 )
goto V_763;
if ( V_678 -> V_286 ) {
struct V_764 * V_286 = F_133 ( V_678 -> V_286 ) ;
V_174 -> V_708 |= V_765 ;
V_174 -> V_704 [ 0 ] . V_170 = V_286 -> V_120 ;
V_243 -> V_286 = V_286 ;
} else {
V_41 = F_128 ( V_174 , V_678 , V_243 ) ;
if ( V_41 )
goto V_766;
}
V_41 = F_130 ( V_174 , V_243 ) ;
if ( V_41 )
goto V_200;
V_174 -> V_686 |= ( V_500 -> V_120 << V_767 ) &
V_768 ;
V_334 = F_124 ( V_243 ) ;
V_174 -> V_708 |= V_334 ;
V_174 -> V_740 |= ( V_9 -> V_360 . V_390 <<
V_769 ) &
V_770 ;
V_174 -> V_740 |= ( V_9 -> V_360 . V_394 <<
V_771 ) &
V_772 ;
V_13 = F_134 ( V_678 -> V_773 ) ;
V_174 -> V_774 |= ( V_13 -> V_120 << V_775 ) &
V_776 ;
V_243 -> V_332 = V_13 ;
V_13 = F_134 ( V_678 -> V_777 ) ;
V_174 -> V_774 |= ( V_13 -> V_120 << V_778 ) &
V_779 ;
V_243 -> V_333 = V_13 ;
if ( V_500 -> V_504 && V_678 -> V_682 . V_429 && V_500 -> V_512 &&
( V_678 -> V_682 . V_429 <= V_9 -> V_360 . V_429 ) ) {
F_129 ( V_174 , V_500 , V_243 , V_715 ,
V_716 ) ;
}
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_730 * ) V_174 ;
F_131 ( V_188 , V_243 , V_678 , V_731 , V_732 ) ;
V_243 -> V_664 = V_26 ;
F_84 ( V_174 ) ;
return 0 ;
V_200:
if ( V_243 -> V_659 . V_4 )
F_22 ( & V_158 -> V_9 , V_243 -> V_659 . V_161 , V_243 -> V_659 . V_4 , V_243 -> V_659 . V_195 ) ;
V_766:
F_52 ( L_19 , V_293 , V_9 -> V_120 ) ;
F_22 ( & V_158 -> V_9 , V_243 -> V_18 . V_161 , V_243 -> V_18 . V_4 , V_243 -> V_18 . V_195 ) ;
V_763:
F_52 ( L_20 , V_293 , V_9 -> V_120 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
int F_135 ( struct V_8 * V_9 , struct V_242 * V_243 ,
struct V_780 * V_781 )
{
int V_41 = - V_163 ;
struct V_782 * V_174 ;
struct V_783 * V_188 ;
V_174 = F_19 ( V_784 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_733 = V_243 -> V_120 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_783 * ) V_174 ;
memcpy ( V_781 , & V_188 -> V_785 , sizeof( struct V_780 ) ) ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_136 ( struct V_242 * V_243 ,
struct V_786 * V_174 ,
struct V_787 * V_678 ,
int V_788 )
{
int V_41 ;
struct V_789 * V_790 = & V_678 -> V_790 ;
union V_791 V_792 , V_793 ;
T_1 V_794 ;
T_2 V_795 [ 6 ] ;
struct V_8 * V_9 = F_120 ( V_243 -> V_274 . V_265 ) ;
if ( ( V_790 -> V_796 & V_797 ) == 0 )
return - V_72 ;
if ( F_137 ( & V_9 -> V_311 , 1 , 0 ) )
F_138 ( V_9 ) ;
V_174 -> V_785 . V_798 |=
( V_790 -> V_799 . V_800 << V_801 ) ;
V_174 -> V_785 . V_802 |=
( V_790 -> V_799 . V_803 & V_804 ) ;
V_174 -> V_785 . V_802 |= ( V_790 -> V_805 << V_806 ) ;
V_174 -> V_785 . V_807 |=
( V_790 -> V_799 . V_808 << V_809 ) ;
V_174 -> V_334 |= V_810 ;
memcpy ( & V_174 -> V_785 . V_811 [ 0 ] , & V_790 -> V_799 . V_811 . V_812 [ 0 ] ,
sizeof( V_174 -> V_785 . V_811 ) ) ;
V_41 = F_139 ( & V_9 -> V_266 , 1 ,
V_790 -> V_799 . V_813 , & V_792 ) ;
if ( V_41 )
return V_41 ;
memset ( & V_793 , 0 , sizeof( V_793 ) ) ;
if ( ! memcmp ( & V_792 , & V_793 , sizeof( V_793 ) ) )
return - V_72 ;
V_243 -> V_814 = V_790 -> V_799 . V_813 ;
memcpy ( & V_174 -> V_785 . V_792 [ 0 ] , & V_792 . V_812 [ 0 ] , sizeof( V_174 -> V_785 . V_792 ) ) ;
V_41 = F_140 ( V_9 , V_790 , & V_795 [ 0 ] ) ;
if ( V_41 )
return V_41 ;
V_174 -> V_785 . V_815 = V_795 [ 0 ] | ( V_795 [ 1 ] << 8 ) |
( V_795 [ 2 ] << 16 ) | ( V_795 [ 3 ] << 24 ) ;
F_141 ( & V_174 -> V_785 . V_811 [ 0 ] , sizeof( V_174 -> V_785 . V_811 ) ) ;
F_141 ( & V_174 -> V_785 . V_792 [ 0 ] , sizeof( V_174 -> V_785 . V_792 ) ) ;
V_174 -> V_785 . V_816 = V_795 [ 4 ] | ( V_795 [ 5 ] << 8 ) ;
if ( V_788 & V_817 ) {
V_794 = V_678 -> V_794 ;
V_174 -> V_785 . V_816 |=
V_794 << V_818 ;
V_174 -> V_334 |= V_819 ;
V_174 -> V_785 . V_802 |=
( V_9 -> V_805 & 0x07 ) << V_806 ;
}
return 0 ;
}
static int F_142 ( struct V_242 * V_243 ,
struct V_786 * V_174 ,
struct V_787 * V_678 , int V_788 )
{
int V_41 = 0 ;
struct V_8 * V_9 = F_120 ( V_243 -> V_274 . V_265 ) ;
if ( V_788 & V_820 ) {
V_174 -> V_785 . V_821 |= ( V_678 -> V_822 &
V_823 ) ;
V_174 -> V_334 |= V_824 ;
}
if ( V_788 & V_825 ) {
V_243 -> V_826 = V_678 -> V_826 ;
V_174 -> V_785 . V_826 = V_678 -> V_826 ;
V_174 -> V_334 |= V_827 ;
}
if ( V_788 & V_828 ) {
V_41 = F_136 ( V_243 , V_174 , V_678 , V_788 ) ;
if ( V_41 )
return V_41 ;
} else if ( V_243 -> V_753 == V_754 || V_243 -> V_753 == V_758 ) {
V_174 -> V_785 . V_815 = V_9 -> V_117 . V_795 [ 0 ] |
( V_9 -> V_117 . V_795 [ 1 ] << 8 ) |
( V_9 -> V_117 . V_795 [ 2 ] << 16 ) |
( V_9 -> V_117 . V_795 [ 3 ] << 24 ) ;
V_174 -> V_785 . V_816 = V_9 -> V_117 . V_795 [ 4 ] |
( V_9 -> V_117 . V_795 [ 5 ] << 8 ) ;
}
if ( ( V_788 & V_829 ) &&
V_678 -> V_830 ) {
V_174 -> V_785 . V_708 |=
V_831 ;
V_174 -> V_334 |= V_832 ;
}
if ( V_788 & V_833 ) {
V_174 -> V_785 . V_834 |= ( V_678 -> V_835 &
V_836 ) ;
V_174 -> V_334 |= V_832 ;
}
if ( V_788 & V_837 ) {
if ( V_678 -> V_838 < V_839 ||
V_678 -> V_838 > V_840 ) {
V_41 = - V_72 ;
goto V_841;
}
V_174 -> V_785 . V_821 |=
( F_143 ( V_678 -> V_838 ) <<
V_842 ) &
V_843 ;
V_174 -> V_334 |= V_844 ;
}
if ( V_788 & V_845 ) {
V_174 -> V_785 . V_834 |= V_678 -> V_143 <<
V_846 ;
V_174 -> V_334 |= V_847 ;
}
if ( V_788 & V_848 ) {
V_174 -> V_785 . V_802 |= ( V_678 -> V_849 <<
V_850 ) &
V_851 ;
V_174 -> V_334 |= V_852 ;
}
if ( V_788 & V_853 ) {
V_174 -> V_785 . V_802 |= ( V_678 -> V_854 <<
V_855 ) &
V_856 ;
V_174 -> V_334 |= V_857 ;
}
if ( V_788 & V_858 ) {
V_174 -> V_785 . V_834 |= ( V_678 -> V_859 <<
V_860 )
& V_861 ;
V_174 -> V_334 |= V_862 ;
}
if ( V_788 & V_863 ) {
V_174 -> V_785 . V_798 |= ( V_678 -> V_864 & 0x00ffffff ) ;
V_174 -> V_334 |= V_865 ;
}
if ( V_788 & V_866 ) {
V_174 -> V_785 . V_807 |= ( V_678 -> V_867 & 0x00ffffff ) ;
V_174 -> V_334 |= V_868 ;
}
if ( V_788 & V_869 ) {
if ( V_678 -> V_870 > V_9 -> V_360 . V_390 ) {
V_41 = - V_72 ;
goto V_841;
}
V_243 -> V_742 = V_678 -> V_870 ;
V_174 -> V_334 |= V_871 ;
}
if ( V_788 & V_872 ) {
if ( V_678 -> V_873 > V_9 -> V_360 . V_394 ) {
V_41 = - V_72 ;
goto V_841;
}
V_243 -> V_739 = V_678 -> V_873 ;
V_174 -> V_334 |= V_874 ;
}
V_174 -> V_785 . V_740 = ( V_243 -> V_742 <<
V_875 ) |
( V_243 -> V_739 & V_876 ) ;
V_841:
return V_41 ;
}
int F_144 ( struct V_8 * V_9 , struct V_242 * V_243 ,
struct V_787 * V_678 , int V_788 )
{
int V_41 = - V_163 ;
struct V_786 * V_174 ;
V_174 = F_19 ( V_877 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_785 . V_120 = V_243 -> V_120 ;
V_174 -> V_334 = 0 ;
if ( V_788 & V_878 ) {
V_174 -> V_785 . V_708 |=
( F_10 ( V_678 -> V_879 ) <<
V_880 ) &
V_881 ;
V_174 -> V_334 |= V_882 ;
} else {
V_174 -> V_785 . V_708 |=
( V_243 -> V_664 << V_880 ) &
V_881 ;
}
V_41 = F_142 ( V_243 , V_174 , V_678 , V_788 ) ;
if ( V_41 )
goto V_200;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_145 ( struct V_8 * V_9 , struct V_242 * V_243 )
{
int V_41 = - V_163 ;
struct V_883 * V_174 ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_884 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_733 = V_243 -> V_120 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
if ( V_243 -> V_18 . V_4 )
F_22 ( & V_158 -> V_9 , V_243 -> V_18 . V_161 , V_243 -> V_18 . V_4 , V_243 -> V_18 . V_195 ) ;
if ( ! V_243 -> V_286 && V_243 -> V_659 . V_4 )
F_22 ( & V_158 -> V_9 , V_243 -> V_659 . V_161 , V_243 -> V_659 . V_4 , V_243 -> V_659 . V_195 ) ;
if ( V_243 -> V_504 )
V_243 -> V_500 -> V_512 ++ ;
return V_41 ;
}
int F_146 ( struct V_8 * V_9 , struct V_764 * V_286 ,
struct V_885 * V_886 ,
struct V_499 * V_500 )
{
int V_41 = - V_163 ;
int V_575 , V_168 ;
int V_161 ;
struct V_887 * V_188 ;
struct V_888 * V_174 ;
T_4 V_195 ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_702 ;
V_174 = F_19 ( V_889 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_890 = V_500 -> V_120 & V_891 ;
V_702 = V_886 -> V_360 . V_892 + 1 ;
V_41 = F_99 ( & V_702 ,
V_9 -> V_360 . V_426 ,
& V_575 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_21 , V_293 ,
V_886 -> V_360 . V_892 ) ;
V_41 = - V_72 ;
goto V_893;
}
V_161 = V_575 * V_168 ;
V_286 -> V_659 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_286 -> V_659 . V_4 ) {
V_41 = - V_163 ;
goto V_893;
}
F_25 ( & V_174 -> V_704 [ 0 ] , V_575 , V_195 , V_168 ) ;
V_286 -> V_659 . V_162 = V_9 -> V_360 . V_426 ;
V_286 -> V_659 . V_195 = V_195 ;
V_286 -> V_659 . V_161 = V_161 ;
V_286 -> V_659 . V_684 = V_702 ;
V_174 -> V_894 = F_127 ( V_702 ) ;
V_174 -> V_894 |= V_886 -> V_360 . V_895 <<
V_896 ;
V_174 -> V_890 |= ( F_127 ( V_168 / V_213 )
<< V_897 ) ;
V_174 -> V_898 |= ( V_9 -> V_360 . V_426
<< V_899 )
& V_900 ;
V_174 -> V_898 |= V_575 << V_901 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_887 * ) V_174 ;
V_286 -> V_120 = V_188 -> V_120 ;
V_286 -> V_659 . V_735 = V_188 -> V_120 ;
V_702 = ( ( V_188 -> V_902 &
V_903 ) >>
V_904 ) ;
V_702 = ( 1 << V_702 ) ;
V_286 -> V_659 . V_684 = V_702 ;
V_286 -> V_659 . V_751 = V_702 - 1 ;
V_286 -> V_659 . V_681 = ( V_188 -> V_902 &
V_905 ) >>
V_906 ;
goto V_893;
V_200:
F_22 ( & V_158 -> V_9 , V_286 -> V_659 . V_161 , V_286 -> V_659 . V_4 , V_195 ) ;
V_893:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_147 ( struct V_764 * V_286 , struct V_907 * V_886 )
{
int V_41 = - V_163 ;
struct V_908 * V_174 ;
struct V_499 * V_500 = V_286 -> V_500 ;
struct V_8 * V_9 = F_120 ( V_500 -> V_679 . V_265 ) ;
V_174 = F_19 ( V_909 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_120 ;
V_174 -> V_910 |= V_886 -> V_911 <<
V_912 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
int F_148 ( struct V_764 * V_286 , struct V_907 * V_886 )
{
int V_41 = - V_163 ;
struct V_913 * V_174 ;
struct V_8 * V_9 = F_120 ( V_286 -> V_287 . V_265 ) ;
V_174 = F_19 ( V_914 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_659 . V_735 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 == 0 ) {
struct V_915 * V_188 =
(struct V_915 * ) V_174 ;
V_886 -> V_895 =
V_188 -> V_916 &
V_917 ;
V_886 -> V_892 =
V_188 -> V_918 >> V_919 ;
V_886 -> V_911 = V_188 -> V_916 >>
V_920 ;
}
F_84 ( V_174 ) ;
return V_41 ;
}
int F_149 ( struct V_8 * V_9 , struct V_764 * V_286 )
{
int V_41 = - V_163 ;
struct V_921 * V_174 ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_922 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_120 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_286 -> V_659 . V_4 )
F_22 ( & V_158 -> V_9 , V_286 -> V_659 . V_161 ,
V_286 -> V_659 . V_4 , V_286 -> V_659 . V_195 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_150 ( struct V_8 * V_9 , T_1 V_923 ,
struct V_924 * V_925 )
{
int V_41 = 0 ;
T_4 V_195 ;
struct V_17 V_174 ;
struct V_926 * V_182 = NULL ;
struct V_927 * V_188 = NULL ;
struct V_543 * V_158 = V_9 -> V_117 . V_158 ;
struct V_928 * V_929 = V_174 . V_153 . V_460 . V_461 ;
memset ( & V_174 , 0 , sizeof( struct V_17 ) ) ;
V_174 . V_146 . V_151 = F_151 ( T_1 , sizeof( struct V_927 ) ,
sizeof( struct V_926 ) ) ;
V_182 = F_24 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , & V_195 , V_145 ) ;
if ( ! V_182 ) {
V_41 = - V_163 ;
goto V_560;
}
V_174 . V_146 . V_147 |= ( 1 << V_458 ) &
V_459 ;
V_929 -> V_462 = ( T_1 ) ( V_195 & 0xFFFFFFFFUL ) ;
V_929 -> V_463 = ( T_1 ) F_26 ( V_195 ) ;
V_929 -> V_161 = V_174 . V_146 . V_151 ;
memset ( V_182 , 0 , sizeof( struct V_926 ) ) ;
F_18 ( & V_182 -> V_146 , V_930 ,
V_931 , V_174 . V_146 . V_151 ) ;
V_182 -> V_932 = V_923 ;
V_41 = F_77 ( V_9 , & V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_927 * ) V_182 ;
F_61 ( V_188 , sizeof( struct V_927 ) ) ;
memcpy ( V_925 , & V_188 -> V_933 , sizeof( struct V_924 ) ) ;
V_200:
F_22 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , V_182 , V_195 ) ;
V_560:
return V_41 ;
}
static int F_152 ( struct V_8 * V_9 , int V_923 ,
struct V_924 * V_925 ,
T_2 * V_934 )
{
int V_41 = - V_72 , V_935 , V_936 ;
int V_937 ;
struct V_938 * V_939 ;
T_2 V_192 , V_940 ;
T_2 V_941 , V_942 ;
T_3 V_943 ;
if ( ! ( V_925 -> V_944 & V_945 ) ) {
F_153 ( L_22 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
goto V_946;
}
if ( ! F_155 ( V_925 -> V_947 ) ) {
F_153 ( L_23 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
( V_923 > 0 ? L_24 : L_25 ) ,
( V_925 -> V_947 & V_948 ) ?
L_26 : L_27 ,
( V_925 -> V_947 & V_949 ) ?
L_1 : L_28 ) ;
goto V_946;
} else {
F_153 ( L_29 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
}
V_937 = ( V_925 -> V_944 >>
V_950 )
& V_945 ;
for ( V_935 = 0 ; V_935 < V_937 ; V_935 ++ ) {
V_939 = & V_925 -> V_939 [ V_935 ] ;
V_192 = ( V_939 -> V_951 >>
V_952 )
& V_953 ;
V_940 = ( V_939 -> V_951
>> V_954 )
& V_955 ;
V_943 = V_939 -> V_951 &
V_956 ;
if (
V_192 && V_943 == V_957 &&
V_940 == V_958 ) {
for ( V_936 = 0 ; V_936 <
V_959 ; V_936 ++ ) {
V_941 = F_156 (
( T_2 * ) V_939 -> V_941 ,
V_936 ) ;
V_942 = F_157 (
( T_2 * ) V_925 -> V_942 ,
V_936 ) ;
if ( V_941 && V_942 ) {
* V_934 = V_936 ;
V_41 = 0 ;
goto V_946;
}
}
if ( V_936 == V_959 ) {
F_153 ( L_30 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) ,
V_9 -> V_120 , V_943 ) ;
}
}
}
V_946:
return V_41 ;
}
void F_138 ( struct V_8 * V_9 )
{
int V_41 = 0 , V_935 ;
struct V_924 V_925 ;
T_2 V_934 = V_960 ;
int V_923 = V_961 ;
for ( V_935 = 0 ; V_935 < 2 ; V_935 ++ ) {
V_41 = F_150 ( V_9 , V_923 , & V_925 ) ;
if ( V_41 ) {
F_52 ( L_31 , V_293 , V_41 ) ;
V_923 = V_962 ;
continue;
}
V_41 = F_152 ( V_9 , V_923 ,
& V_925 , & V_934 ) ;
if ( V_41 ) {
V_923 = V_962 ;
continue;
}
break;
}
if ( V_41 )
F_153 ( L_32 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
else
F_153 ( L_33 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
V_934 ) ;
V_9 -> V_947 = F_155 ( V_925 . V_947 ) ;
V_9 -> V_805 = V_934 ;
}
int F_158 ( struct V_8 * V_9 , struct V_963 * V_964 )
{
int V_169 ;
int V_41 = - V_72 ;
struct V_549 * V_965 ;
unsigned long V_334 ;
V_965 = V_9 -> V_548 . V_4 ;
F_66 ( & V_9 -> V_548 . V_238 , V_334 ) ;
for ( V_169 = 0 ; V_169 < V_9 -> V_548 . V_562 ; V_169 ++ ) {
if ( V_965 -> V_192 == 0 ) {
V_965 -> V_192 = V_966 ;
V_964 -> V_965 = V_965 ;
V_964 -> V_120 = V_169 ;
V_41 = 0 ;
break;
}
V_965 ++ ;
}
if ( V_169 == V_9 -> V_548 . V_562 )
V_41 = - V_51 ;
F_67 ( & V_9 -> V_548 . V_238 , V_334 ) ;
return V_41 ;
}
int F_159 ( struct V_8 * V_9 , struct V_963 * V_964 )
{
unsigned long V_334 ;
F_66 ( & V_9 -> V_548 . V_238 , V_334 ) ;
V_964 -> V_965 -> V_192 = 0 ;
F_67 ( & V_9 -> V_548 . V_238 , V_334 ) ;
return 0 ;
}
static int F_160 ( struct V_8 * V_9 )
{
int V_967 , V_169 , V_41 = 0 ;
int V_201 ;
unsigned long V_334 = 0 ;
V_967 = V_9 -> V_117 . V_204 . V_968 -
V_9 -> V_117 . V_204 . V_969 ;
if ( V_9 -> V_117 . V_202 == V_203 ) {
V_967 = 1 ;
V_334 = V_970 ;
} else {
V_967 = F_126 ( T_1 , V_967 , F_161 () ) ;
}
if ( ! V_967 )
return - V_72 ;
V_9 -> V_207 = F_20 ( sizeof( struct V_1 ) * V_967 , V_145 ) ;
if ( ! V_9 -> V_207 )
return - V_163 ;
for ( V_169 = 0 ; V_169 < V_967 ; V_169 ++ ) {
V_41 = F_31 ( V_9 , & V_9 -> V_207 [ V_169 ] ,
V_7 ) ;
if ( V_41 ) {
V_41 = - V_72 ;
break;
}
sprintf ( V_9 -> V_207 [ V_169 ] . V_971 , L_34 ,
V_9 -> V_120 , V_169 ) ;
V_201 = F_32 ( V_9 , & V_9 -> V_207 [ V_169 ] ) ;
V_41 = F_162 ( V_201 , F_70 , V_334 ,
V_9 -> V_207 [ V_169 ] . V_971 ,
& V_9 -> V_207 [ V_169 ] ) ;
if ( V_41 )
goto V_972;
V_9 -> V_206 += 1 ;
}
return 0 ;
V_972:
F_36 ( V_9 ) ;
return V_41 ;
}
static int F_163 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_973 )
{
int V_169 , V_41 = - V_163 ;
struct V_974 * V_174 ;
V_174 = F_19 ( V_975 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_174 . V_182 , V_975 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_174 . V_967 = V_973 ;
for ( V_169 = 0 ; V_169 < V_973 ; V_169 ++ ) {
V_174 -> V_174 . V_976 [ V_169 ] . V_124 = V_2 [ V_169 ] . V_3 . V_120 ;
V_174 -> V_174 . V_976 [ V_169 ] . V_977 = 0 ;
V_174 -> V_174 . V_976 [ V_169 ] . V_978 =
( V_2 [ V_169 ] . V_348 . V_979 * 65 ) / 100 ;
}
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_164 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_973 )
{
int V_980 , V_169 = 0 ;
if ( V_973 > 8 ) {
while ( V_973 ) {
V_980 = F_115 ( V_973 , 8 ) ;
F_163 ( V_9 , & V_2 [ V_169 ] , V_980 ) ;
V_169 += V_980 ;
V_973 -= V_980 ;
}
} else {
F_163 ( V_9 , V_2 , V_973 ) ;
}
return 0 ;
}
void F_165 ( struct V_981 * V_982 )
{
struct V_8 * V_9 =
F_166 ( V_982 , struct V_8 , V_983 . V_982 ) ;
struct V_1 * V_2 = 0 ;
int V_169 , V_973 = 0 , V_41 = - V_72 ;
V_409 V_984 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
V_2 = & V_9 -> V_207 [ V_169 ] ;
if ( V_2 -> V_348 . V_349 > V_2 -> V_348 . V_985 ) {
V_984 = V_2 -> V_348 . V_349 -
V_2 -> V_348 . V_985 ;
if ( ( V_984 > V_986 ) &&
( V_2 -> V_348 . V_979 == V_987 ) ) {
V_2 -> V_348 . V_979 = V_988 ;
V_973 ++ ;
} else if ( ( V_984 < V_989 ) &&
( V_2 -> V_348 . V_979 == V_988 ) ) {
V_2 -> V_348 . V_979 = V_987 ;
V_973 ++ ;
}
}
V_2 -> V_348 . V_985 = V_2 -> V_348 . V_349 ;
}
if ( V_973 )
V_41 = F_164 ( V_9 , & V_9 -> V_207 [ 0 ] , V_973 ) ;
F_167 ( & V_9 -> V_983 , F_76 ( 1000 ) ) ;
}
int F_168 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_160 ( V_9 ) ;
if ( V_41 )
goto V_990;
V_41 = F_43 ( V_9 ) ;
if ( V_41 )
goto V_991;
V_41 = F_85 ( V_9 ) ;
if ( V_41 )
goto V_992;
V_41 = F_89 ( V_9 ) ;
if ( V_41 )
goto V_992;
V_41 = F_83 ( V_9 ) ;
if ( V_41 )
goto V_992;
V_41 = F_102 ( V_9 ) ;
if ( V_41 )
goto V_992;
V_41 = F_91 ( V_9 ) ;
if ( V_41 )
goto V_993;
V_41 = F_88 ( V_9 ) ;
if ( V_41 )
goto V_993;
return 0 ;
V_993:
F_104 ( V_9 ) ;
V_992:
F_46 ( V_9 ) ;
V_991:
F_36 ( V_9 ) ;
V_990:
F_52 ( L_15 , V_293 , V_41 ) ;
return V_41 ;
}
void F_169 ( struct V_8 * V_9 )
{
F_98 ( V_9 ) ;
F_104 ( V_9 ) ;
F_36 ( V_9 ) ;
F_46 ( V_9 ) ;
}
