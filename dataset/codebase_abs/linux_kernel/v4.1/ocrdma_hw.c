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
T_2 V_343 ;
int V_344 = V_2 -> V_235 ;
do {
V_342 = F_1 ( V_2 ) ;
V_341 = * V_342 ;
F_61 ( & V_341 , sizeof( V_341 ) ) ;
V_343 = ( V_341 . V_345 & V_346 )
>> V_347 ;
if ( V_343 == V_348 )
F_52 ( L_9 ,
V_2 -> V_3 . V_120 , V_341 . V_345 ) ;
if ( ( V_341 . V_345 & V_349 ) == 0 )
break;
V_342 -> V_345 = 0 ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , false , true , 1 ) ;
if ( ( V_341 . V_345 & V_350 ) == 0 ) {
V_106 = V_341 . V_345 >> V_351 ;
F_69 ( V_9 , V_106 ) ;
}
F_2 ( V_2 ) ;
if ( V_344 )
V_344 -- ;
} while ( V_344 );
V_2 -> V_352 . V_353 ++ ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , true , true , 0 ) ;
return V_354 ;
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
V_9 -> V_21 . V_355 = true ;
F_52 ( L_10 ,
V_293 , V_9 -> V_120 ) ;
return - 1 ;
}
}
static int F_77 ( struct V_8 * V_9 , struct V_17 * V_144 )
{
int V_41 = 0 ;
T_3 V_99 , V_320 ;
struct V_17 * V_356 ;
struct V_357 * V_188 = NULL ;
F_47 ( & V_9 -> V_21 . V_238 ) ;
if ( V_9 -> V_21 . V_355 )
goto V_200;
F_71 ( V_9 , V_144 ) ;
V_41 = F_74 ( V_9 ) ;
if ( V_41 )
goto V_200;
V_99 = V_9 -> V_21 . V_99 ;
V_320 = V_9 -> V_21 . V_320 ;
V_356 = F_8 ( V_9 ) ;
F_78 ( V_144 , V_356 , ( sizeof( * V_144 ) ) ) ;
if ( ( V_144 -> V_146 . V_147 & V_150 ) >>
V_149 )
V_188 = & V_144 -> V_153 . V_188 ;
if ( V_99 || V_320 ) {
F_52 ( L_11 ,
V_293 , V_99 , V_320 ) ;
if ( V_188 ) {
F_52 ( L_12 ,
( V_188 -> V_141 & V_358 ) >>
V_359 ,
( V_188 -> V_141 & V_360 ) >>
V_361 ) ;
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
void * V_362 )
{
int V_41 = 0 ;
struct V_357 * V_188 = V_362 ;
if ( ( V_144 -> V_146 . V_147 & V_150 ) >>
V_149 )
F_28 () ;
V_41 = F_77 ( V_9 , V_144 ) ;
if ( ! V_41 )
if ( V_188 -> V_41 & V_44 )
V_41 = F_11 ( V_188 -> V_41 ) ;
if ( V_41 )
F_52 ( L_12 ,
( V_188 -> V_141 & V_358 ) >>
V_359 ,
( V_188 -> V_141 & V_360 ) >>
V_361 ) ;
return V_41 ;
}
static void F_80 ( struct V_8 * V_9 ,
struct V_363 * V_364 ,
struct V_365 * V_188 )
{
V_364 -> V_366 =
( V_188 -> V_367 & V_368 ) >>
V_369 ;
V_364 -> V_370 =
( V_188 -> V_371 & V_372 ) >>
V_373 ;
V_364 -> V_374 =
( V_188 -> V_375 & V_376 ) >>
V_377 ;
V_364 -> V_378 =
( V_188 -> V_379 & V_380 ) >>
V_381 ;
V_364 -> V_382 = ( ( V_188 -> V_383 &
V_384 ) >>
V_385 ) ;
V_364 -> V_386 = ( V_188 -> V_383 &
V_384 ) >>
V_385 ;
V_364 -> V_387 = ( V_188 -> V_388 &
V_389 ) >>
V_390 ;
V_364 -> V_391 = ( V_188 -> V_383 &
V_392 ) >>
V_393 ;
V_364 -> V_394 = ( V_188 -> V_395 &
V_396 ) >>
V_397 ;
V_364 -> V_398 = ( V_188 -> V_395 &
V_399 ) >>
V_400 ;
V_364 -> V_401 = ( V_188 -> V_375 &
V_402 ) >>
V_403 ;
V_364 -> V_404 = ( V_188 -> V_375 &
V_405 ) >>
V_406 ;
V_364 -> V_407 = ( V_188 -> V_367 &
V_408 ) >>
V_409 ;
V_364 -> V_410 = V_188 -> V_410 ;
V_364 -> V_411 = V_188 -> V_411 ;
V_364 -> V_412 = ( ( V_413 ) V_188 -> V_414 << 32 ) |
V_188 -> V_415 ;
V_364 -> V_416 = 0 ;
V_364 -> V_417 = V_188 -> V_417 ;
V_364 -> V_418 = V_188 -> V_418 ;
V_364 -> V_419 = V_188 -> V_420 &
V_421 ;
V_364 -> V_422 = ( V_188 -> V_420 &
V_423 ) >>
V_424 ;
V_364 -> V_425 = ( ( V_188 -> V_426 &
V_427 ) >>
V_428 ) *
V_429 ;
V_364 -> V_430 = ( ( V_188 -> V_426 &
V_431 ) >>
V_432 ) *
V_429 ;
V_364 -> V_433 =
V_364 -> V_425 - ( sizeof( struct V_434 ) +
sizeof( struct V_435 ) ) ;
if ( F_81 ( V_9 ) == V_436 ) {
V_364 -> V_437 = 1 ;
V_364 -> V_438 = V_213 ;
V_364 -> V_439 = V_440 ;
}
V_9 -> V_364 . V_441 = V_188 -> V_442 >>
V_443 ;
V_9 -> V_364 . V_444 = V_188 -> V_442 &
V_445 ;
}
static int F_82 ( struct V_8 * V_9 ,
struct V_446 * V_447 )
{
T_1 V_448 ;
V_448 = V_447 -> V_448 & V_449 ;
if ( V_448 != V_449 )
return - V_72 ;
V_9 -> V_450 = V_447 -> V_450 ;
V_9 -> V_451 = V_447 -> V_451 ;
return 0 ;
}
static int F_83 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_452 * V_188 ;
V_174 = F_19 ( V_453 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_453 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_452 * ) V_174 ;
memset ( & V_9 -> V_364 . V_454 [ 0 ] , 0 , sizeof( V_9 -> V_364 . V_454 ) ) ;
memcpy ( & V_9 -> V_364 . V_454 [ 0 ] , & V_188 -> V_455 [ 0 ] ,
sizeof( V_188 -> V_455 ) ) ;
F_61 ( V_9 -> V_364 . V_454 , sizeof( V_188 -> V_455 ) ) ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_85 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_446 * V_188 ;
V_174 = F_19 ( V_456 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_456 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_446 * ) V_174 ;
V_41 = F_82 ( V_9 , V_188 ) ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_86 ( struct V_8 * V_9 , bool V_457 )
{
struct V_458 * V_182 = V_9 -> V_459 . V_4 ;
struct V_17 * V_144 = & V_9 -> V_459 . V_144 ;
struct V_460 * V_461 ;
int V_41 ;
V_461 = F_87 ( sizeof( * V_461 ) , V_145 ) ;
if ( V_461 == NULL )
return - V_163 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> V_146 . V_151 = V_9 -> V_459 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_462 ) &
V_463 ;
V_144 -> V_153 . V_464 . V_465 [ 0 ] . V_466 = ( T_1 ) ( V_9 -> V_459 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_464 . V_465 [ 0 ] . V_467 = ( T_1 ) F_26 ( V_9 -> V_459 . V_195 ) ;
V_144 -> V_153 . V_464 . V_465 [ 0 ] . V_161 = V_9 -> V_459 . V_159 ;
memcpy ( V_461 , V_182 , sizeof( struct V_460 ) ) ;
memset ( V_182 , 0 , V_9 -> V_459 . V_159 ) ;
F_18 ( (struct V_136 * ) V_182 ,
V_468 ,
V_156 ,
V_9 -> V_459 . V_159 ) ;
if ( V_457 )
V_182 -> V_469 = V_457 ;
V_41 = F_79 ( V_9 , V_144 , V_9 -> V_459 . V_4 ) ;
if ( V_41 )
memcpy ( V_182 , V_461 , sizeof( struct V_460 ) ) ;
else
F_61 ( V_182 , V_9 -> V_459 . V_159 ) ;
F_84 ( V_461 ) ;
return V_41 ;
}
static int F_88 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_470 V_160 ;
struct V_17 * V_144 ;
struct V_471 * V_472 ;
struct V_473 * V_474 ;
V_144 = F_20 ( sizeof( struct V_17 ) , V_145 ) ;
if ( ! V_144 )
return V_41 ;
V_160 . V_159 = sizeof( struct V_471 ) ;
V_160 . V_4 = F_24 ( & V_9 -> V_117 . V_158 -> V_9 ,
V_160 . V_159 , & V_160 . V_195 , V_145 ) ;
if ( ! V_160 . V_4 )
goto V_475;
V_144 -> V_146 . V_151 = V_160 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_462 ) &
V_463 ;
V_144 -> V_153 . V_464 . V_465 [ 0 ] . V_466 = ( T_1 ) ( V_160 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_464 . V_465 [ 0 ] . V_467 = ( T_1 ) F_26 ( V_160 . V_195 ) ;
V_144 -> V_153 . V_464 . V_465 [ 0 ] . V_161 = V_160 . V_159 ;
memset ( V_160 . V_4 , 0 , V_160 . V_159 ) ;
F_18 ( (struct V_136 * ) V_160 . V_4 ,
V_476 ,
V_183 ,
V_160 . V_159 ) ;
V_41 = F_79 ( V_9 , V_144 , V_160 . V_4 ) ;
if ( ! V_41 ) {
V_472 = (struct V_471 * ) V_160 . V_4 ;
V_474 = & V_472 -> V_477 . V_474 ;
V_9 -> V_478 = ( V_474 -> V_479 &
V_480 )
>> V_481 ;
strncpy ( V_9 -> V_482 ,
V_474 -> V_483 , 31 ) ;
}
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_160 . V_159 , V_160 . V_4 , V_160 . V_195 ) ;
V_475:
F_84 ( V_144 ) ;
return V_41 ;
}
static int F_89 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_365 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_484 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_365 * ) V_174 ;
F_80 ( V_9 , & V_9 -> V_364 , V_188 ) ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_90 ( struct V_8 * V_9 , T_2 * V_485 )
{
int V_41 = - V_163 ;
struct V_486 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_487 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_487 ,
V_183 , sizeof( * V_174 ) ) ;
( (struct V_136 * ) V_174 -> V_153 . V_174 ) -> V_190 = 0x1 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_486 * ) V_174 ;
* V_485 = ( V_188 -> V_488 & V_489 )
>> V_490 ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_91 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_491 * V_188 ;
V_174 = F_19 ( V_492 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_492 , V_183 ,
sizeof( * V_174 ) ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_491 * ) V_174 ;
V_9 -> V_93 . V_493 =
( V_188 -> V_494 & V_495 ) ;
V_9 -> V_93 . V_496 =
( V_188 -> V_494 & V_497 )
>> V_498 ;
V_9 -> V_93 . V_95 =
( V_188 -> V_499 & V_500 ) ;
V_9 -> V_93 . V_94 =
( V_188 -> V_499 & V_501 )
>> V_502 ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_92 ( struct V_8 * V_9 , struct V_503 * V_504 )
{
int V_41 = - V_163 ;
struct V_505 * V_174 ;
struct V_506 * V_188 ;
V_174 = F_19 ( V_507 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
if ( V_504 -> V_508 )
V_174 -> V_509 |= V_510 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_506 * ) V_174 ;
V_504 -> V_120 = V_188 -> V_511 & V_512 ;
if ( V_188 -> V_511 & V_513 ) {
V_504 -> V_508 = true ;
V_504 -> V_514 = V_188 -> V_511 >>
V_515 ;
} else {
V_504 -> V_508 = false ;
V_504 -> V_516 = 0 ;
}
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_93 ( struct V_8 * V_9 , struct V_503 * V_504 )
{
int V_41 = - V_163 ;
struct V_517 * V_174 ;
V_174 = F_19 ( V_518 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_504 -> V_120 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_94 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
T_6 V_519 ;
struct V_520 * V_174 ;
struct V_521 * V_188 ;
if ( V_9 -> V_364 . V_370 ) {
V_174 = F_19 ( V_522 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_523 = V_9 -> V_364 . V_370 ;
V_174 -> V_509 |= V_510 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
V_188 = (struct V_521 * ) V_174 ;
if ( ! V_41 && ( V_188 -> V_511 & V_513 ) &&
V_188 -> V_523 ) {
V_9 -> V_524 -> V_525 = V_188 -> V_511 >>
V_515 ;
V_9 -> V_524 -> V_526 = V_188 -> V_511 &
V_527 ;
V_9 -> V_524 -> V_528 = V_188 -> V_523 ;
V_519 =
F_95 ( V_188 -> V_523 ) * sizeof( long ) ;
V_9 -> V_524 -> V_529 = F_20 ( V_519 ,
V_145 ) ;
}
F_84 ( V_174 ) ;
}
V_174 = F_19 ( V_522 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_523 = V_9 -> V_364 . V_366 - V_9 -> V_364 . V_370 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
V_188 = (struct V_521 * ) V_174 ;
if ( ! V_41 && V_188 -> V_523 ) {
V_9 -> V_524 -> V_530 = V_188 -> V_511 &
V_527 ;
V_9 -> V_524 -> V_531 = V_188 -> V_523 ;
V_519 = F_95 ( V_188 -> V_523 ) * sizeof( long ) ;
V_9 -> V_524 -> V_532 = F_20 ( V_519 ,
V_145 ) ;
}
F_84 ( V_174 ) ;
if ( V_9 -> V_524 -> V_532 || V_9 -> V_524 -> V_529 ) {
V_9 -> V_524 -> V_533 = true ;
return 0 ;
}
return V_41 ;
}
static void F_96 ( struct V_8 * V_9 )
{
struct V_534 * V_174 ;
V_174 = F_19 ( V_535 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
if ( V_9 -> V_524 -> V_531 ) {
V_174 -> V_536 = V_9 -> V_524 -> V_530 ;
V_174 -> V_523 = V_9 -> V_524 -> V_531 ;
F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
}
if ( V_9 -> V_524 -> V_528 ) {
F_84 ( V_174 ) ;
V_174 = F_19 ( V_535 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
V_174 -> V_536 = V_9 -> V_524 -> V_526 ;
V_174 -> V_523 = V_9 -> V_524 -> V_528 ;
F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
}
V_200:
F_84 ( V_174 ) ;
}
void F_97 ( struct V_8 * V_9 )
{
int V_41 ;
V_9 -> V_524 = F_20 ( sizeof( struct V_537 ) ,
V_145 ) ;
if ( ! V_9 -> V_524 ) {
F_52 ( L_13 , V_293 , V_9 -> V_120 ) ;
return;
}
V_41 = F_94 ( V_9 ) ;
if ( V_41 ) {
F_52 ( L_14 ,
V_293 , V_9 -> V_120 ) ;
}
}
static void F_98 ( struct V_8 * V_9 )
{
F_96 ( V_9 ) ;
F_84 ( V_9 -> V_524 -> V_532 ) ;
F_84 ( V_9 -> V_524 -> V_529 ) ;
F_84 ( V_9 -> V_524 ) ;
}
static int F_99 ( T_1 * V_538 , int V_162 ,
int * V_191 , int * V_539 )
{
int V_169 ;
int V_540 ;
* V_538 = F_100 ( * V_538 ) ;
V_540 = * V_538 * V_162 ;
for ( V_169 = 0 ; V_169 < V_541 ; V_169 ++ ) {
if ( V_540 <= ( V_542 << V_169 ) )
break;
}
if ( V_169 >= V_541 )
return - V_72 ;
V_540 = F_101 ( V_540 ,
( ( V_542 << V_169 ) / V_543 ) ) ;
* V_191 =
V_540 / ( ( V_542 << V_169 ) / V_543 ) ;
* V_539 = ( ( V_542 << V_169 ) / V_543 ) ;
* V_538 = V_540 / V_162 ;
return 0 ;
}
static int F_102 ( struct V_8 * V_9 )
{
int V_169 ;
int V_41 = 0 ;
int V_544 ;
struct V_545 * V_174 ;
struct V_546 * V_188 ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 ;
struct V_548 * V_549 ;
V_174 = F_19 ( V_550 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_544 = V_551 ;
V_9 -> V_552 . V_159 = sizeof( struct V_553 ) * V_544 ;
V_174 -> V_554 = ( V_555 <<
V_556 ) &
V_557 ;
for ( V_169 = 0 ; V_169 < V_541 ; V_169 ++ ) {
if ( V_558 == ( V_213 << V_169 ) )
break;
}
V_174 -> V_554 |= ( V_169 << V_559 ) &
V_560 ;
V_174 -> V_554 |= ( sizeof( struct V_553 ) <<
V_561 ) &
V_562 ;
V_9 -> V_552 . V_563 . V_4 = F_24 ( & V_158 -> V_9 , V_558 ,
& V_9 -> V_552 . V_563 . V_195 ,
V_145 ) ;
if ( V_9 -> V_552 . V_563 . V_4 == NULL )
goto V_564;
V_9 -> V_552 . V_4 = F_24 ( & V_158 -> V_9 , V_9 -> V_552 . V_159 ,
& V_195 , V_145 ) ;
if ( V_9 -> V_552 . V_4 == NULL )
goto V_565;
V_9 -> V_552 . V_195 = V_195 ;
V_9 -> V_552 . V_566 = V_544 ;
memset ( V_9 -> V_552 . V_4 , 0 , V_9 -> V_552 . V_159 ) ;
V_549 = (struct V_548 * ) V_9 -> V_552 . V_563 . V_4 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_552 . V_159 / V_213 ; V_169 ++ ) {
V_549 [ V_169 ] . V_466 = ( T_1 ) F_103 ( V_195 & 0xffffffff ) ;
V_549 [ V_169 ] . V_467 = ( T_1 ) F_103 ( F_26 ( V_195 ) ) ;
V_195 += V_558 ;
}
V_174 -> V_567 [ 0 ] . V_170 = ( T_1 ) ( V_9 -> V_552 . V_563 . V_195 & 0xFFFFFFFF ) ;
V_174 -> V_567 [ 0 ] . V_171 = ( T_1 ) F_26 ( V_9 -> V_552 . V_563 . V_195 ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_546 * ) V_174 ;
V_9 -> V_552 . V_568 = V_188 -> V_568 & 0xFFFF ;
F_84 ( V_174 ) ;
return 0 ;
V_200:
F_22 ( & V_158 -> V_9 , V_9 -> V_552 . V_159 , V_9 -> V_552 . V_4 ,
V_9 -> V_552 . V_195 ) ;
V_9 -> V_552 . V_4 = NULL ;
V_565:
F_22 ( & V_158 -> V_9 , V_558 , V_9 -> V_552 . V_563 . V_4 ,
V_9 -> V_552 . V_563 . V_195 ) ;
V_9 -> V_552 . V_563 . V_4 = NULL ;
V_9 -> V_552 . V_159 = 0 ;
V_564:
F_84 ( V_174 ) ;
return V_41 ;
}
static void F_104 ( struct V_8 * V_9 )
{
struct V_569 * V_174 ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
if ( V_9 -> V_552 . V_4 == NULL )
return;
V_174 = F_19 ( V_570 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return;
V_174 -> V_568 = V_9 -> V_552 . V_568 ;
F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
F_22 ( & V_158 -> V_9 , V_9 -> V_552 . V_159 , V_9 -> V_552 . V_4 ,
V_9 -> V_552 . V_195 ) ;
V_9 -> V_552 . V_4 = NULL ;
F_22 ( & V_158 -> V_9 , V_558 , V_9 -> V_552 . V_563 . V_4 ,
V_9 -> V_552 . V_563 . V_195 ) ;
F_84 ( V_174 ) ;
}
static T_3 F_105 ( struct V_8 * V_9 )
{
int V_169 , V_571 = 0 , V_235 = 0 ;
T_3 V_124 ;
F_47 ( & V_9 -> V_572 ) ;
V_235 = V_9 -> V_207 [ 0 ] . V_235 ;
V_124 = V_9 -> V_207 [ 0 ] . V_3 . V_120 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
if ( V_9 -> V_207 [ V_169 ] . V_235 < V_235 ) {
V_235 = V_9 -> V_207 [ V_169 ] . V_235 ;
V_124 = V_9 -> V_207 [ V_169 ] . V_3 . V_120 ;
V_571 = V_169 ;
}
}
V_9 -> V_207 [ V_571 ] . V_235 += 1 ;
F_48 ( & V_9 -> V_572 ) ;
return V_124 ;
}
static void F_106 ( struct V_8 * V_9 , T_3 V_124 )
{
int V_169 ;
F_47 ( & V_9 -> V_572 ) ;
V_169 = F_107 ( V_9 , V_124 ) ;
if ( V_169 == - V_72 )
F_28 () ;
V_9 -> V_207 [ V_169 ] . V_235 -= 1 ;
F_48 ( & V_9 -> V_572 ) ;
}
int F_108 ( struct V_8 * V_9 , struct V_247 * V_13 ,
int V_573 , int V_574 , T_3 V_575 )
{
int V_41 = - V_163 ; int V_576 ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
struct V_577 * V_174 ;
struct V_578 * V_188 ;
T_1 V_579 , V_580 , V_539 , V_581 ;
if ( V_573 > V_9 -> V_364 . V_419 ) {
F_52 ( L_15 ,
V_293 , V_9 -> V_120 , V_9 -> V_364 . V_419 , V_573 ) ;
return - V_72 ;
}
if ( V_574 && ( F_81 ( V_9 ) != V_436 ) )
return - V_72 ;
if ( V_574 ) {
V_13 -> V_576 = 1 ;
V_576 = 1 ;
V_580 = V_582 ;
V_579 = 1 ;
} else {
V_13 -> V_576 = V_9 -> V_364 . V_419 ;
V_576 = V_9 -> V_364 . V_419 ;
V_580 = sizeof( struct V_583 ) ;
V_579 = V_584 ;
}
V_13 -> V_161 = F_101 ( V_576 * V_580 , V_213 ) ;
V_174 = F_19 ( V_210 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( & V_174 -> V_174 . V_182 , V_210 ,
V_183 , sizeof( * V_174 ) ) ;
V_13 -> V_4 = F_24 ( & V_158 -> V_9 , V_13 -> V_161 , & V_13 -> V_195 , V_145 ) ;
if ( ! V_13 -> V_4 ) {
V_41 = - V_163 ;
goto V_564;
}
memset ( V_13 -> V_4 , 0 , V_13 -> V_161 ) ;
V_539 = V_13 -> V_161 / V_579 ;
V_174 -> V_174 . V_212 = ( V_539 / V_213 ) <<
V_214 ;
V_174 -> V_174 . V_212 |= V_579 ;
V_174 -> V_174 . V_215 = V_216 ;
V_13 -> V_217 = F_105 ( V_9 ) ;
V_174 -> V_174 . V_182 . V_190 = V_585 ;
V_581 = V_13 -> V_161 / V_580 ;
V_13 -> V_586 = V_581 ;
if ( V_581 > 1024 ) {
V_174 -> V_174 . V_215 |= ( 0x3 << V_587 ) ;
} else {
T_2 V_588 = 0 ;
switch ( V_581 ) {
case 256 :
V_588 = 0 ;
break;
case 512 :
V_588 = 1 ;
break;
case 1024 :
V_588 = 2 ;
break;
default:
goto V_200;
}
V_174 -> V_174 . V_215 |= ( V_588 << V_587 ) ;
}
V_174 -> V_174 . V_217 = V_13 -> V_217 ;
if ( F_81 ( V_9 ) == V_436 ) {
if ( V_574 )
V_174 -> V_174 . V_212 |= V_589 <<
V_590 ;
V_13 -> V_591 = false ;
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_580 ) ;
} else {
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_580 ) - 1 ;
V_174 -> V_174 . V_215 |= V_592 ;
V_13 -> V_591 = true ;
}
V_174 -> V_174 . V_218 |= ( V_575 <<
V_593 ) ;
F_25 ( & V_174 -> V_174 . V_195 [ 0 ] , V_579 , V_13 -> V_195 , V_539 ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_578 * ) V_174 ;
V_13 -> V_120 = ( T_3 ) ( V_188 -> V_188 . V_106 & V_219 ) ;
F_84 ( V_174 ) ;
return 0 ;
V_200:
F_106 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
V_564:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_109 ( struct V_8 * V_9 , struct V_247 * V_13 )
{
int V_41 = - V_163 ;
struct V_594 * V_174 ;
V_174 = F_19 ( V_179 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_182 , V_179 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_595 |=
( V_13 -> V_120 << V_596 ) &
V_597 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
F_106 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
int F_110 ( struct V_8 * V_9 , struct V_598 * V_599 ,
T_1 V_600 , int V_601 )
{
int V_41 = - V_163 ;
struct V_602 * V_174 ;
struct V_603 * V_188 ;
V_174 = F_19 ( V_604 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_600 = V_600 ;
V_174 -> V_605 |= V_601 ;
V_174 -> V_605 |= ( V_599 -> V_606 << V_607 ) ;
V_174 -> V_605 |=
( V_599 -> V_608 << V_609 ) ;
V_174 -> V_605 |=
( V_599 -> V_610 << V_611 ) ;
V_174 -> V_605 |=
( V_599 -> V_612 << V_613 ) ;
V_174 -> V_605 |=
( V_599 -> V_614 << V_615 ) ;
V_174 -> V_605 |=
( V_599 -> V_616 << V_617 ) ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_603 * ) V_174 ;
V_599 -> V_618 = V_188 -> V_619 ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_111 ( struct V_8 * V_9 , int V_606 , T_1 V_618 )
{
int V_41 = - V_163 ;
struct V_620 * V_174 ;
V_174 = F_19 ( V_621 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_618 = V_618 ;
V_174 -> V_622 = V_606 ? 1 : 0 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_112 ( struct V_8 * V_9 , struct V_598 * V_599 ,
T_1 V_600 , T_1 V_623 , T_1 V_624 , T_1 V_625 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_626 * V_174 ;
struct V_627 * V_188 ;
V_174 = F_19 ( V_628 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_629 =
V_600 | ( V_599 -> V_616 << V_630 ) ;
V_174 -> V_606 = V_599 -> V_606 ;
V_174 -> V_631 |= ( V_599 -> V_608 <<
V_632 ) ;
V_174 -> V_631 |= ( V_599 -> V_610 <<
V_633 ) ;
V_174 -> V_631 |= ( V_599 -> V_612 <<
V_634 ) ;
V_174 -> V_631 |= ( V_599 -> V_614 <<
V_635 ) ;
V_174 -> V_631 |= ( V_599 -> V_636 <<
V_637 ) ;
V_174 -> V_631 |= ( V_625 << V_638 ) ;
V_174 -> V_631 |= ( V_599 -> V_624 / V_639 ) ;
V_174 -> V_631 |= ( V_599 -> V_640 / V_639 ) <<
V_641 ;
V_174 -> V_642 = V_599 -> V_161 ;
V_174 -> V_643 = F_26 ( V_599 -> V_161 ) ;
V_174 -> V_644 = ( T_1 ) ( V_599 -> V_645 & 0xffffffff ) ;
V_174 -> V_646 = ( T_1 ) F_26 ( V_599 -> V_645 ) ;
V_174 -> V_647 = ( T_1 ) V_599 -> V_4 ;
V_174 -> V_648 = ( T_1 ) F_26 ( V_599 -> V_4 ) ;
for ( V_169 = 0 ; V_169 < V_623 ; V_169 ++ ) {
V_174 -> V_563 [ V_169 ] . V_170 = ( T_1 ) ( V_599 -> V_649 [ V_169 ] . V_195 & 0xffffffff ) ;
V_174 -> V_563 [ V_169 ] . V_171 = F_26 ( V_599 -> V_649 [ V_169 ] . V_195 ) ;
}
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_627 * ) V_174 ;
V_599 -> V_618 = V_188 -> V_619 ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_113 ( struct V_8 * V_9 ,
struct V_598 * V_599 , T_1 V_623 ,
T_1 V_650 , T_1 V_625 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_651 * V_174 ;
V_174 = F_19 ( V_652 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_619 = V_599 -> V_618 ;
V_174 -> V_653 = ( V_623 << V_654 ) |
( V_650 & V_655 ) ;
V_174 -> V_625 = V_625 << V_656 ;
for ( V_169 = 0 ; V_169 < V_623 ; V_169 ++ ) {
V_174 -> V_563 [ V_169 ] . V_170 =
( T_1 ) ( V_599 -> V_649 [ V_169 + V_650 ] . V_195 & 0xffffffff ) ;
V_174 -> V_563 [ V_169 ] . V_171 =
F_26 ( V_599 -> V_649 [ V_169 + V_650 ] . V_195 ) ;
}
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_114 ( struct V_8 * V_9 ,
struct V_598 * V_599 , T_1 V_600 , int V_657 )
{
int V_41 ;
T_1 V_625 = 0 ;
T_1 V_658 , V_650 ;
T_1 V_659 = V_599 -> V_616 ;
V_650 = 0 ;
V_658 = F_115 ( V_659 , V_660 ) ;
if ( V_658 == V_659 )
V_625 = 1 ;
V_41 = F_112 ( V_9 , V_599 , V_600 ,
V_658 , V_599 -> V_624 , V_625 ) ;
if ( V_41 ) {
F_52 ( L_16 , V_293 , V_41 ) ;
return V_41 ;
}
if ( V_625 )
return 0 ;
while ( ! V_625 ) {
V_650 += V_658 ;
V_659 -= V_658 ;
V_658 = F_115 ( V_659 , V_660 ) ;
if ( V_658 == V_659 )
V_625 = 1 ;
V_41 = F_113 ( V_9 , V_599 , V_658 ,
V_650 , V_625 ) ;
if ( V_41 )
break;
}
if ( V_41 )
F_52 ( L_17 , V_293 , V_41 ) ;
return V_41 ;
}
bool F_116 ( struct V_247 * V_13 , struct V_242 * V_243 )
{
struct V_242 * V_661 ;
bool V_662 = false ;
F_117 (tmp, &cq->sq_head, sq_entry) {
if ( V_243 == V_661 ) {
V_662 = true ;
break;
}
}
return V_662 ;
}
bool F_118 ( struct V_247 * V_13 , struct V_242 * V_243 )
{
struct V_242 * V_661 ;
bool V_662 = false ;
F_117 (tmp, &cq->rq_head, rq_entry) {
if ( V_243 == V_661 ) {
V_662 = true ;
break;
}
}
return V_662 ;
}
void F_119 ( struct V_242 * V_243 )
{
bool V_662 ;
unsigned long V_334 ;
struct V_8 * V_9 = F_120 ( V_243 -> V_274 . V_265 ) ;
F_66 ( & V_9 -> V_335 , V_334 ) ;
V_662 = F_116 ( V_243 -> V_332 , V_243 ) ;
if ( ! V_662 )
F_121 ( & V_243 -> V_330 , & V_243 -> V_332 -> V_328 ) ;
if ( ! V_243 -> V_286 ) {
V_662 = F_118 ( V_243 -> V_333 , V_243 ) ;
if ( ! V_662 )
F_121 ( & V_243 -> V_331 , & V_243 -> V_333 -> V_329 ) ;
}
F_67 ( & V_9 -> V_335 , V_334 ) ;
}
static void F_122 ( struct V_242 * V_243 )
{
V_243 -> V_18 . V_19 = 0 ;
V_243 -> V_18 . V_5 = 0 ;
V_243 -> V_663 . V_19 = 0 ;
V_243 -> V_663 . V_5 = 0 ;
}
int F_50 ( struct V_242 * V_243 , enum V_23 V_664 ,
enum V_23 * V_665 )
{
unsigned long V_334 ;
int V_41 = 0 ;
enum V_24 V_666 ;
V_666 = F_10 ( V_664 ) ;
F_66 ( & V_243 -> V_667 , V_334 ) ;
if ( V_665 )
* V_665 = F_9 ( V_243 -> V_668 ) ;
if ( V_666 == V_243 -> V_668 ) {
F_67 ( & V_243 -> V_667 , V_334 ) ;
return 1 ;
}
if ( V_666 == V_28 ) {
F_122 ( V_243 ) ;
F_123 ( V_243 ) ;
} else if ( V_666 == V_39 ) {
F_119 ( V_243 ) ;
}
V_243 -> V_668 = V_666 ;
F_67 ( & V_243 -> V_667 , V_334 ) ;
return V_41 ;
}
static T_1 F_124 ( struct V_242 * V_243 )
{
T_1 V_334 = 0 ;
if ( V_243 -> V_669 & V_670 )
V_334 |= V_671 ;
if ( V_243 -> V_669 & V_672 )
V_334 |= V_673 ;
if ( V_243 -> V_669 & V_674 )
V_334 |= V_675 ;
if ( V_243 -> V_669 & V_676 )
V_334 |= V_677 ;
if ( V_243 -> V_669 & V_678 )
V_334 |= V_679 ;
return V_334 ;
}
static int F_125 ( struct V_680 * V_174 ,
struct V_681 * V_682 ,
struct V_242 * V_243 )
{
int V_41 ;
T_1 V_161 , V_579 , V_168 ;
T_4 V_195 ;
struct V_503 * V_504 = V_243 -> V_504 ;
struct V_8 * V_9 = F_120 ( V_504 -> V_683 . V_265 ) ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_684 ;
T_1 V_685 = V_682 -> V_686 . V_382 ;
V_684 = F_126 ( T_1 , V_682 -> V_686 . V_687 + 1 ,
V_9 -> V_364 . V_441 ) ;
V_41 = F_99 ( & V_684 ,
V_9 -> V_364 . V_425 , & V_579 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_18 , V_293 ,
V_684 ) ;
return - V_72 ;
}
V_243 -> V_18 . V_688 = V_684 ;
V_161 = ( V_579 * V_168 ) ;
V_243 -> V_18 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_243 -> V_18 . V_4 )
return - V_72 ;
memset ( V_243 -> V_18 . V_4 , 0 , V_161 ) ;
V_243 -> V_18 . V_161 = V_161 ;
V_243 -> V_18 . V_195 = V_195 ;
V_243 -> V_18 . V_162 = V_9 -> V_364 . V_425 ;
F_25 ( & V_174 -> V_689 [ 0 ] , V_579 , V_195 , V_168 ) ;
V_174 -> V_690 |= ( F_127 ( V_168 / V_213 )
<< V_691 ) ;
V_174 -> V_692 |= ( V_579 <<
V_693 ) &
V_694 ;
V_174 -> V_695 |= ( V_685 <<
V_696 ) &
V_697 ;
V_174 -> V_695 |= ( V_685 <<
V_698 ) &
V_699 ;
V_174 -> V_700 |= ( F_127 ( V_243 -> V_18 . V_688 ) <<
V_701 ) &
V_702 ;
V_174 -> V_703 |= ( V_9 -> V_364 . V_425 <<
V_704 ) &
V_705 ;
return 0 ;
}
static int F_128 ( struct V_680 * V_174 ,
struct V_681 * V_682 ,
struct V_242 * V_243 )
{
int V_41 ;
T_1 V_161 , V_579 , V_168 ;
T_4 V_195 = 0 ;
struct V_503 * V_504 = V_243 -> V_504 ;
struct V_8 * V_9 = F_120 ( V_504 -> V_683 . V_265 ) ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_706 = V_682 -> V_686 . V_707 + 1 ;
V_41 = F_99 ( & V_706 , V_9 -> V_364 . V_430 ,
& V_579 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_19 , V_293 ,
V_682 -> V_686 . V_707 + 1 ) ;
return V_41 ;
}
V_243 -> V_663 . V_688 = V_706 ;
V_161 = ( V_579 * V_168 ) ;
V_243 -> V_663 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_243 -> V_663 . V_4 )
return - V_163 ;
memset ( V_243 -> V_663 . V_4 , 0 , V_161 ) ;
V_243 -> V_663 . V_195 = V_195 ;
V_243 -> V_663 . V_161 = V_161 ;
V_243 -> V_663 . V_162 = V_9 -> V_364 . V_430 ;
F_25 ( & V_174 -> V_708 [ 0 ] , V_579 , V_195 , V_168 ) ;
V_174 -> V_690 |= ( F_127 ( V_168 / V_213 ) <<
V_709 ) ;
V_174 -> V_692 |=
( V_579 << V_710 ) &
V_711 ;
V_174 -> V_712 |= ( V_682 -> V_686 . V_386 <<
V_713 ) &
V_714 ;
V_174 -> V_700 |= ( F_127 ( V_243 -> V_663 . V_688 ) <<
V_715 ) &
V_716 ;
V_174 -> V_703 |= ( V_9 -> V_364 . V_430 <<
V_717 ) &
V_718 ;
return 0 ;
}
static void F_129 ( struct V_680 * V_174 ,
struct V_503 * V_504 ,
struct V_242 * V_243 ,
T_2 V_719 , T_3 V_720 )
{
V_504 -> V_516 -- ;
V_243 -> V_508 = true ;
V_174 -> V_712 |= V_721 ;
if ( ! V_719 )
return;
V_174 -> V_712 |= V_721 ;
V_174 -> V_722 = V_720 ;
V_174 -> V_722 |= V_723 <<
V_724 ;
}
static int F_130 ( struct V_680 * V_174 ,
struct V_242 * V_243 )
{
struct V_503 * V_504 = V_243 -> V_504 ;
struct V_8 * V_9 = F_120 ( V_504 -> V_683 . V_265 ) ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 = 0 ;
int V_438 = V_9 -> V_364 . V_438 ;
int V_725 = V_9 -> V_364 . V_439 * V_438 ;
struct V_434 * V_726 ;
int V_169 = 0 ;
if ( V_9 -> V_364 . V_437 == 0 )
return 0 ;
V_243 -> V_727 = F_24 ( & V_158 -> V_9 , V_725 ,
& V_195 , V_145 ) ;
if ( ! V_243 -> V_727 )
return - V_163 ;
memset ( V_243 -> V_727 , 0 , V_725 ) ;
F_25 ( & V_174 -> V_728 [ 0 ] , V_9 -> V_364 . V_439 ,
V_195 , V_438 ) ;
for (; V_169 < V_725 / V_9 -> V_364 . V_430 ; V_169 ++ ) {
V_726 = (struct V_434 * ) ( V_243 -> V_727 +
( V_169 * V_9 -> V_364 . V_430 ) ) ;
V_726 -> V_729 = 0 ;
V_726 -> V_729 |= 2 ;
V_726 -> V_729 |= ( V_730 << V_731 ) ;
V_726 -> V_729 |= ( 8 << V_732 ) ;
V_726 -> V_729 |= ( 8 << V_733 ) ;
}
return 0 ;
}
static void F_131 ( struct V_734 * V_188 ,
struct V_242 * V_243 ,
struct V_681 * V_682 ,
T_3 * V_735 , T_3 * V_736 )
{
T_1 V_684 , V_706 ;
V_243 -> V_120 = V_188 -> V_737 & V_738 ;
V_243 -> V_663 . V_739 = V_188 -> V_740 & V_741 ;
V_243 -> V_18 . V_739 = V_188 -> V_740 >> V_742 ;
V_243 -> V_743 = V_188 -> V_744 & V_745 ;
V_243 -> V_746 = ( V_188 -> V_744 >> V_747 ) ;
V_243 -> V_508 = false ;
if ( V_188 -> V_748 & V_749 ) {
V_243 -> V_508 = true ;
* V_736 = ( V_188 -> V_748 &
V_750 ) >>
V_751 ;
* V_735 = ( V_188 -> V_748 &
V_752 ) >>
V_753 ;
}
V_684 =
V_188 -> V_700 >> V_754 ;
V_684 = 1 << V_684 ;
V_706 = 1 << ( ( T_3 ) V_188 -> V_700 ) ;
V_243 -> V_18 . V_688 = V_684 ;
V_243 -> V_18 . V_755 = V_684 - 1 ;
if ( ! V_682 -> V_286 ) {
V_243 -> V_663 . V_688 = V_706 ;
V_243 -> V_663 . V_755 = V_706 - 1 ;
}
}
int F_132 ( struct V_242 * V_243 , struct V_681 * V_682 ,
T_2 V_719 , T_3 V_720 , T_3 * V_735 ,
T_3 * V_736 )
{
int V_41 = - V_163 ;
T_1 V_334 = 0 ;
struct V_503 * V_504 = V_243 -> V_504 ;
struct V_8 * V_9 = F_120 ( V_504 -> V_683 . V_265 ) ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
struct V_247 * V_13 ;
struct V_680 * V_174 ;
struct V_734 * V_188 ;
int V_756 ;
switch ( V_682 -> V_757 ) {
case V_758 :
V_756 = V_759 ;
break;
case V_760 :
V_756 = V_761 ;
break;
case V_762 :
V_756 = V_763 ;
break;
default:
return - V_72 ;
}
V_174 = F_19 ( V_764 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_690 |= ( V_756 << V_765 ) &
V_766 ;
V_41 = F_125 ( V_174 , V_682 , V_243 ) ;
if ( V_41 )
goto V_767;
if ( V_682 -> V_286 ) {
struct V_768 * V_286 = F_133 ( V_682 -> V_286 ) ;
V_174 -> V_712 |= V_769 ;
V_174 -> V_708 [ 0 ] . V_170 = V_286 -> V_120 ;
V_243 -> V_286 = V_286 ;
} else {
V_41 = F_128 ( V_174 , V_682 , V_243 ) ;
if ( V_41 )
goto V_770;
}
V_41 = F_130 ( V_174 , V_243 ) ;
if ( V_41 )
goto V_200;
V_174 -> V_690 |= ( V_504 -> V_120 << V_771 ) &
V_772 ;
V_334 = F_124 ( V_243 ) ;
V_174 -> V_712 |= V_334 ;
V_174 -> V_744 |= ( V_9 -> V_364 . V_394 <<
V_773 ) &
V_774 ;
V_174 -> V_744 |= ( V_9 -> V_364 . V_398 <<
V_775 ) &
V_776 ;
V_13 = F_134 ( V_682 -> V_777 ) ;
V_174 -> V_778 |= ( V_13 -> V_120 << V_779 ) &
V_780 ;
V_243 -> V_332 = V_13 ;
V_13 = F_134 ( V_682 -> V_781 ) ;
V_174 -> V_778 |= ( V_13 -> V_120 << V_782 ) &
V_783 ;
V_243 -> V_333 = V_13 ;
if ( V_504 -> V_508 && V_682 -> V_686 . V_433 && V_504 -> V_516 &&
( V_682 -> V_686 . V_433 <= V_9 -> V_364 . V_433 ) ) {
F_129 ( V_174 , V_504 , V_243 , V_719 ,
V_720 ) ;
}
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_734 * ) V_174 ;
F_131 ( V_188 , V_243 , V_682 , V_735 , V_736 ) ;
V_243 -> V_668 = V_26 ;
F_84 ( V_174 ) ;
return 0 ;
V_200:
if ( V_243 -> V_663 . V_4 )
F_22 ( & V_158 -> V_9 , V_243 -> V_663 . V_161 , V_243 -> V_663 . V_4 , V_243 -> V_663 . V_195 ) ;
V_770:
F_52 ( L_20 , V_293 , V_9 -> V_120 ) ;
F_22 ( & V_158 -> V_9 , V_243 -> V_18 . V_161 , V_243 -> V_18 . V_4 , V_243 -> V_18 . V_195 ) ;
V_767:
F_52 ( L_21 , V_293 , V_9 -> V_120 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
int F_135 ( struct V_8 * V_9 , struct V_242 * V_243 ,
struct V_784 * V_785 )
{
int V_41 = - V_163 ;
struct V_786 * V_174 ;
struct V_787 * V_188 ;
V_174 = F_19 ( V_788 , sizeof( * V_188 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_737 = V_243 -> V_120 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_787 * ) V_174 ;
memcpy ( V_785 , & V_188 -> V_789 , sizeof( struct V_784 ) ) ;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_136 ( struct V_242 * V_243 ,
struct V_790 * V_174 ,
struct V_791 * V_682 ,
int V_792 )
{
int V_41 ;
struct V_793 * V_794 = & V_682 -> V_794 ;
union V_795 V_796 , V_797 ;
T_1 V_798 = 0xFFFF ;
T_2 V_799 [ 6 ] ;
struct V_8 * V_9 = F_120 ( V_243 -> V_274 . V_265 ) ;
if ( ( V_794 -> V_800 & V_801 ) == 0 )
return - V_72 ;
if ( F_137 ( & V_9 -> V_311 , 1 , 0 ) )
F_138 ( V_9 ) ;
V_174 -> V_789 . V_802 |=
( V_794 -> V_803 . V_804 << V_805 ) ;
V_174 -> V_789 . V_806 |=
( V_794 -> V_803 . V_807 & V_808 ) ;
V_174 -> V_789 . V_806 |= ( V_794 -> V_809 << V_810 ) ;
V_174 -> V_789 . V_811 |=
( V_794 -> V_803 . V_812 << V_813 ) ;
V_174 -> V_334 |= V_814 ;
memcpy ( & V_174 -> V_789 . V_815 [ 0 ] , & V_794 -> V_803 . V_815 . V_816 [ 0 ] ,
sizeof( V_174 -> V_789 . V_815 ) ) ;
V_41 = F_139 ( & V_9 -> V_266 , 1 ,
V_794 -> V_803 . V_817 , & V_796 ) ;
if ( V_41 )
return V_41 ;
memset ( & V_797 , 0 , sizeof( V_797 ) ) ;
if ( ! memcmp ( & V_796 , & V_797 , sizeof( V_797 ) ) )
return - V_72 ;
V_243 -> V_818 = V_794 -> V_803 . V_817 ;
memcpy ( & V_174 -> V_789 . V_796 [ 0 ] , & V_796 . V_816 [ 0 ] , sizeof( V_174 -> V_789 . V_796 ) ) ;
V_41 = F_140 ( V_9 , V_794 , & V_799 [ 0 ] ) ;
if ( V_41 )
return V_41 ;
V_174 -> V_789 . V_819 = V_799 [ 0 ] | ( V_799 [ 1 ] << 8 ) |
( V_799 [ 2 ] << 16 ) | ( V_799 [ 3 ] << 24 ) ;
F_141 ( & V_174 -> V_789 . V_815 [ 0 ] , sizeof( V_174 -> V_789 . V_815 ) ) ;
F_141 ( & V_174 -> V_789 . V_796 [ 0 ] , sizeof( V_174 -> V_789 . V_796 ) ) ;
V_174 -> V_789 . V_820 = V_799 [ 4 ] | ( V_799 [ 5 ] << 8 ) ;
if ( V_792 & V_821 ) {
V_798 = V_682 -> V_798 ;
} else if ( V_9 -> V_822 ) {
V_798 = 0 ;
F_52 ( L_22 ,
V_9 -> V_120 ) ;
F_52 ( L_23 ,
V_9 -> V_120 ) ;
}
if ( V_798 < 0x1000 ) {
V_174 -> V_789 . V_820 |=
V_798 << V_823 ;
V_174 -> V_334 |= V_824 ;
V_174 -> V_789 . V_806 |=
( V_9 -> V_809 & 0x07 ) << V_810 ;
}
return 0 ;
}
static int F_142 ( struct V_242 * V_243 ,
struct V_790 * V_174 ,
struct V_791 * V_682 , int V_792 )
{
int V_41 = 0 ;
struct V_8 * V_9 = F_120 ( V_243 -> V_274 . V_265 ) ;
if ( V_792 & V_825 ) {
V_174 -> V_789 . V_826 |= ( V_682 -> V_827 &
V_828 ) ;
V_174 -> V_334 |= V_829 ;
}
if ( V_792 & V_830 ) {
V_243 -> V_831 = V_682 -> V_831 ;
V_174 -> V_789 . V_831 = V_682 -> V_831 ;
V_174 -> V_334 |= V_832 ;
}
if ( V_792 & V_833 ) {
V_41 = F_136 ( V_243 , V_174 , V_682 , V_792 ) ;
if ( V_41 )
return V_41 ;
} else if ( V_243 -> V_757 == V_758 || V_243 -> V_757 == V_762 ) {
V_174 -> V_789 . V_819 = V_9 -> V_117 . V_799 [ 0 ] |
( V_9 -> V_117 . V_799 [ 1 ] << 8 ) |
( V_9 -> V_117 . V_799 [ 2 ] << 16 ) |
( V_9 -> V_117 . V_799 [ 3 ] << 24 ) ;
V_174 -> V_789 . V_820 = V_9 -> V_117 . V_799 [ 4 ] |
( V_9 -> V_117 . V_799 [ 5 ] << 8 ) ;
}
if ( ( V_792 & V_834 ) &&
V_682 -> V_835 ) {
V_174 -> V_789 . V_712 |=
V_836 ;
V_174 -> V_334 |= V_837 ;
}
if ( V_792 & V_838 ) {
V_174 -> V_789 . V_839 |= ( V_682 -> V_840 &
V_841 ) ;
V_174 -> V_334 |= V_837 ;
}
if ( V_792 & V_842 ) {
if ( V_682 -> V_843 < V_844 ||
V_682 -> V_843 > V_845 ) {
F_52 ( L_24 ,
V_9 -> V_120 , F_143 ( V_682 -> V_843 ) ) ;
V_41 = - V_72 ;
goto V_846;
}
V_174 -> V_789 . V_826 |=
( F_143 ( V_682 -> V_843 ) <<
V_847 ) &
V_848 ;
V_174 -> V_334 |= V_849 ;
}
if ( V_792 & V_850 ) {
V_174 -> V_789 . V_839 |= V_682 -> V_143 <<
V_851 ;
V_174 -> V_334 |= V_852 ;
}
if ( V_792 & V_853 ) {
V_174 -> V_789 . V_806 |= ( V_682 -> V_854 <<
V_855 ) &
V_856 ;
V_174 -> V_334 |= V_857 ;
}
if ( V_792 & V_858 ) {
V_174 -> V_789 . V_806 |= ( V_682 -> V_859 <<
V_860 ) &
V_861 ;
V_174 -> V_334 |= V_862 ;
}
if ( V_792 & V_863 ) {
V_174 -> V_789 . V_839 |= ( V_682 -> V_864 <<
V_865 )
& V_866 ;
V_174 -> V_334 |= V_867 ;
}
if ( V_792 & V_868 ) {
V_174 -> V_789 . V_802 |= ( V_682 -> V_869 & 0x00ffffff ) ;
V_174 -> V_334 |= V_870 ;
}
if ( V_792 & V_871 ) {
V_174 -> V_789 . V_811 |= ( V_682 -> V_872 & 0x00ffffff ) ;
V_174 -> V_334 |= V_873 ;
}
if ( V_792 & V_874 ) {
if ( V_682 -> V_875 > V_9 -> V_364 . V_394 ) {
V_41 = - V_72 ;
goto V_846;
}
V_243 -> V_746 = V_682 -> V_875 ;
V_174 -> V_334 |= V_876 ;
}
if ( V_792 & V_877 ) {
if ( V_682 -> V_878 > V_9 -> V_364 . V_398 ) {
V_41 = - V_72 ;
goto V_846;
}
V_243 -> V_743 = V_682 -> V_878 ;
V_174 -> V_334 |= V_879 ;
}
V_174 -> V_789 . V_744 = ( V_243 -> V_746 <<
V_880 ) |
( V_243 -> V_743 & V_881 ) ;
V_846:
return V_41 ;
}
int F_144 ( struct V_8 * V_9 , struct V_242 * V_243 ,
struct V_791 * V_682 , int V_792 )
{
int V_41 = - V_163 ;
struct V_790 * V_174 ;
V_174 = F_19 ( V_882 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_789 . V_120 = V_243 -> V_120 ;
V_174 -> V_334 = 0 ;
if ( V_792 & V_883 ) {
V_174 -> V_789 . V_712 |=
( F_10 ( V_682 -> V_884 ) <<
V_885 ) &
V_886 ;
V_174 -> V_334 |= V_887 ;
} else {
V_174 -> V_789 . V_712 |=
( V_243 -> V_668 << V_885 ) &
V_886 ;
}
V_41 = F_142 ( V_243 , V_174 , V_682 , V_792 ) ;
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
struct V_888 * V_174 ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_889 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_737 = V_243 -> V_120 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
if ( V_243 -> V_18 . V_4 )
F_22 ( & V_158 -> V_9 , V_243 -> V_18 . V_161 , V_243 -> V_18 . V_4 , V_243 -> V_18 . V_195 ) ;
if ( ! V_243 -> V_286 && V_243 -> V_663 . V_4 )
F_22 ( & V_158 -> V_9 , V_243 -> V_663 . V_161 , V_243 -> V_663 . V_4 , V_243 -> V_663 . V_195 ) ;
if ( V_243 -> V_508 )
V_243 -> V_504 -> V_516 ++ ;
return V_41 ;
}
int F_146 ( struct V_8 * V_9 , struct V_768 * V_286 ,
struct V_890 * V_891 ,
struct V_503 * V_504 )
{
int V_41 = - V_163 ;
int V_579 , V_168 ;
int V_161 ;
struct V_892 * V_188 ;
struct V_893 * V_174 ;
T_4 V_195 ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_706 ;
V_174 = F_19 ( V_894 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_895 = V_504 -> V_120 & V_896 ;
V_706 = V_891 -> V_364 . V_897 + 1 ;
V_41 = F_99 ( & V_706 ,
V_9 -> V_364 . V_430 ,
& V_579 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_25 , V_293 ,
V_891 -> V_364 . V_897 ) ;
V_41 = - V_72 ;
goto V_898;
}
V_161 = V_579 * V_168 ;
V_286 -> V_663 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_286 -> V_663 . V_4 ) {
V_41 = - V_163 ;
goto V_898;
}
F_25 ( & V_174 -> V_708 [ 0 ] , V_579 , V_195 , V_168 ) ;
V_286 -> V_663 . V_162 = V_9 -> V_364 . V_430 ;
V_286 -> V_663 . V_195 = V_195 ;
V_286 -> V_663 . V_161 = V_161 ;
V_286 -> V_663 . V_688 = V_706 ;
V_174 -> V_899 = F_127 ( V_706 ) ;
V_174 -> V_899 |= V_891 -> V_364 . V_900 <<
V_901 ;
V_174 -> V_895 |= ( F_127 ( V_168 / V_213 )
<< V_902 ) ;
V_174 -> V_903 |= ( V_9 -> V_364 . V_430
<< V_904 )
& V_905 ;
V_174 -> V_903 |= V_579 << V_906 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_892 * ) V_174 ;
V_286 -> V_120 = V_188 -> V_120 ;
V_286 -> V_663 . V_739 = V_188 -> V_120 ;
V_706 = ( ( V_188 -> V_907 &
V_908 ) >>
V_909 ) ;
V_706 = ( 1 << V_706 ) ;
V_286 -> V_663 . V_688 = V_706 ;
V_286 -> V_663 . V_755 = V_706 - 1 ;
V_286 -> V_663 . V_685 = ( V_188 -> V_907 &
V_910 ) >>
V_911 ;
goto V_898;
V_200:
F_22 ( & V_158 -> V_9 , V_286 -> V_663 . V_161 , V_286 -> V_663 . V_4 , V_195 ) ;
V_898:
F_84 ( V_174 ) ;
return V_41 ;
}
int F_147 ( struct V_768 * V_286 , struct V_912 * V_891 )
{
int V_41 = - V_163 ;
struct V_913 * V_174 ;
struct V_503 * V_504 = V_286 -> V_504 ;
struct V_8 * V_9 = F_120 ( V_504 -> V_683 . V_265 ) ;
V_174 = F_19 ( V_914 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_120 ;
V_174 -> V_915 |= V_891 -> V_916 <<
V_917 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
int F_148 ( struct V_768 * V_286 , struct V_912 * V_891 )
{
int V_41 = - V_163 ;
struct V_918 * V_174 ;
struct V_8 * V_9 = F_120 ( V_286 -> V_287 . V_265 ) ;
V_174 = F_19 ( V_919 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_663 . V_739 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 == 0 ) {
struct V_920 * V_188 =
(struct V_920 * ) V_174 ;
V_891 -> V_900 =
V_188 -> V_921 &
V_922 ;
V_891 -> V_897 =
V_188 -> V_923 >> V_924 ;
V_891 -> V_916 = V_188 -> V_921 >>
V_925 ;
}
F_84 ( V_174 ) ;
return V_41 ;
}
int F_149 ( struct V_8 * V_9 , struct V_768 * V_286 )
{
int V_41 = - V_163 ;
struct V_926 * V_174 ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_927 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_120 ;
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_286 -> V_663 . V_4 )
F_22 ( & V_158 -> V_9 , V_286 -> V_663 . V_161 ,
V_286 -> V_663 . V_4 , V_286 -> V_663 . V_195 ) ;
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_150 ( struct V_8 * V_9 , T_1 V_928 ,
struct V_929 * V_930 )
{
int V_41 = 0 ;
T_4 V_195 ;
struct V_17 V_174 ;
struct V_931 * V_182 = NULL ;
struct V_932 * V_188 = NULL ;
struct V_547 * V_158 = V_9 -> V_117 . V_158 ;
struct V_933 * V_934 = V_174 . V_153 . V_464 . V_465 ;
memset ( & V_174 , 0 , sizeof( struct V_17 ) ) ;
V_174 . V_146 . V_151 = F_151 ( T_1 , sizeof( struct V_932 ) ,
sizeof( struct V_931 ) ) ;
V_182 = F_24 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , & V_195 , V_145 ) ;
if ( ! V_182 ) {
V_41 = - V_163 ;
goto V_564;
}
V_174 . V_146 . V_147 |= ( 1 << V_462 ) &
V_463 ;
V_934 -> V_466 = ( T_1 ) ( V_195 & 0xFFFFFFFFUL ) ;
V_934 -> V_467 = ( T_1 ) F_26 ( V_195 ) ;
V_934 -> V_161 = V_174 . V_146 . V_151 ;
memset ( V_182 , 0 , sizeof( struct V_931 ) ) ;
F_18 ( & V_182 -> V_146 , V_935 ,
V_936 , V_174 . V_146 . V_151 ) ;
V_182 -> V_937 = V_928 ;
V_41 = F_77 ( V_9 , & V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_932 * ) V_182 ;
F_61 ( V_188 , sizeof( struct V_932 ) ) ;
memcpy ( V_930 , & V_188 -> V_938 , sizeof( struct V_929 ) ) ;
V_200:
F_22 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , V_182 , V_195 ) ;
V_564:
return V_41 ;
}
static int F_152 ( struct V_8 * V_9 , int V_928 ,
struct V_929 * V_930 ,
T_2 * V_939 )
{
int V_41 = - V_72 , V_940 , V_941 ;
int V_942 ;
struct V_943 * V_944 ;
T_2 V_192 , V_945 ;
T_2 V_946 , V_947 ;
T_3 V_948 ;
if ( ! ( V_930 -> V_949 & V_950 ) ) {
F_153 ( L_26 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
goto V_951;
}
if ( ! F_155 ( V_930 -> V_822 ) ) {
F_153 ( L_27 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
( V_928 > 0 ? L_28 : L_29 ) ,
( V_930 -> V_822 & V_952 ) ?
L_30 : L_31 ,
( V_930 -> V_822 & V_953 ) ?
L_1 : L_32 ) ;
goto V_951;
} else {
F_153 ( L_33 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
}
V_942 = ( V_930 -> V_949 >>
V_954 )
& V_950 ;
for ( V_940 = 0 ; V_940 < V_942 ; V_940 ++ ) {
V_944 = & V_930 -> V_944 [ V_940 ] ;
V_192 = ( V_944 -> V_955 >>
V_956 )
& V_957 ;
V_945 = ( V_944 -> V_955
>> V_958 )
& V_959 ;
V_948 = V_944 -> V_955 &
V_960 ;
if (
V_192 && V_948 == V_961 &&
V_945 == V_962 ) {
for ( V_941 = 0 ; V_941 <
V_963 ; V_941 ++ ) {
V_946 = F_156 (
( T_2 * ) V_944 -> V_946 ,
V_941 ) ;
V_947 = F_157 (
( T_2 * ) V_930 -> V_947 ,
V_941 ) ;
if ( V_946 && V_947 ) {
* V_939 = V_941 ;
V_41 = 0 ;
goto V_951;
}
}
if ( V_941 == V_963 ) {
F_153 ( L_34 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) ,
V_9 -> V_120 , V_948 ) ;
}
}
}
V_951:
return V_41 ;
}
void F_138 ( struct V_8 * V_9 )
{
int V_41 = 0 , V_940 ;
struct V_929 V_930 ;
T_2 V_939 = V_964 ;
int V_928 = V_965 ;
for ( V_940 = 0 ; V_940 < 2 ; V_940 ++ ) {
V_41 = F_150 ( V_9 , V_928 , & V_930 ) ;
if ( V_41 ) {
F_52 ( L_35 , V_293 , V_41 ) ;
V_928 = V_966 ;
continue;
}
V_41 = F_152 ( V_9 , V_928 ,
& V_930 , & V_939 ) ;
if ( V_41 ) {
V_928 = V_966 ;
continue;
}
break;
}
if ( V_41 )
F_153 ( L_36 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
else
F_153 ( L_37 ,
F_154 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
V_939 ) ;
V_9 -> V_822 = F_155 ( V_930 . V_822 ) ;
V_9 -> V_809 = V_939 ;
}
int F_158 ( struct V_8 * V_9 , struct V_967 * V_968 )
{
int V_169 ;
int V_41 = - V_72 ;
struct V_553 * V_969 ;
unsigned long V_334 ;
V_969 = V_9 -> V_552 . V_4 ;
F_66 ( & V_9 -> V_552 . V_238 , V_334 ) ;
for ( V_169 = 0 ; V_169 < V_9 -> V_552 . V_566 ; V_169 ++ ) {
if ( V_969 -> V_192 == 0 ) {
V_969 -> V_192 = V_970 ;
V_968 -> V_969 = V_969 ;
V_968 -> V_120 = V_169 ;
V_41 = 0 ;
break;
}
V_969 ++ ;
}
if ( V_169 == V_9 -> V_552 . V_566 )
V_41 = - V_51 ;
F_67 ( & V_9 -> V_552 . V_238 , V_334 ) ;
return V_41 ;
}
int F_159 ( struct V_8 * V_9 , struct V_967 * V_968 )
{
unsigned long V_334 ;
F_66 ( & V_9 -> V_552 . V_238 , V_334 ) ;
V_968 -> V_969 -> V_192 = 0 ;
F_67 ( & V_9 -> V_552 . V_238 , V_334 ) ;
return 0 ;
}
static int F_160 ( struct V_8 * V_9 )
{
int V_971 , V_169 , V_41 = 0 ;
int V_201 ;
unsigned long V_334 = 0 ;
V_971 = V_9 -> V_117 . V_204 . V_972 -
V_9 -> V_117 . V_204 . V_973 ;
if ( V_9 -> V_117 . V_202 == V_203 ) {
V_971 = 1 ;
V_334 = V_974 ;
} else {
V_971 = F_126 ( T_1 , V_971 , F_161 () ) ;
}
if ( ! V_971 )
return - V_72 ;
V_9 -> V_207 = F_20 ( sizeof( struct V_1 ) * V_971 , V_145 ) ;
if ( ! V_9 -> V_207 )
return - V_163 ;
for ( V_169 = 0 ; V_169 < V_971 ; V_169 ++ ) {
V_41 = F_31 ( V_9 , & V_9 -> V_207 [ V_169 ] ,
V_7 ) ;
if ( V_41 ) {
V_41 = - V_72 ;
break;
}
sprintf ( V_9 -> V_207 [ V_169 ] . V_975 , L_38 ,
V_9 -> V_120 , V_169 ) ;
V_201 = F_32 ( V_9 , & V_9 -> V_207 [ V_169 ] ) ;
V_41 = F_162 ( V_201 , F_70 , V_334 ,
V_9 -> V_207 [ V_169 ] . V_975 ,
& V_9 -> V_207 [ V_169 ] ) ;
if ( V_41 )
goto V_976;
V_9 -> V_206 += 1 ;
}
return 0 ;
V_976:
F_36 ( V_9 ) ;
return V_41 ;
}
static int F_163 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_977 )
{
int V_169 , V_41 = - V_163 ;
struct V_978 * V_174 ;
V_174 = F_19 ( V_979 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_174 . V_182 , V_979 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_174 . V_971 = V_977 ;
for ( V_169 = 0 ; V_169 < V_977 ; V_169 ++ ) {
V_174 -> V_174 . V_980 [ V_169 ] . V_124 = V_2 [ V_169 ] . V_3 . V_120 ;
V_174 -> V_174 . V_980 [ V_169 ] . V_981 = 0 ;
V_174 -> V_174 . V_980 [ V_169 ] . V_982 =
( V_2 [ V_169 ] . V_352 . V_983 * 65 ) / 100 ;
}
V_41 = F_77 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_84 ( V_174 ) ;
return V_41 ;
}
static int F_164 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_977 )
{
int V_984 , V_169 = 0 ;
if ( V_977 > 8 ) {
while ( V_977 ) {
V_984 = F_115 ( V_977 , 8 ) ;
F_163 ( V_9 , & V_2 [ V_169 ] , V_984 ) ;
V_169 += V_984 ;
V_977 -= V_984 ;
}
} else {
F_163 ( V_9 , V_2 , V_977 ) ;
}
return 0 ;
}
void F_165 ( struct V_985 * V_986 )
{
struct V_8 * V_9 =
F_166 ( V_986 , struct V_8 , V_987 . V_986 ) ;
struct V_1 * V_2 = 0 ;
int V_169 , V_977 = 0 , V_41 = - V_72 ;
V_413 V_988 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
V_2 = & V_9 -> V_207 [ V_169 ] ;
if ( V_2 -> V_352 . V_353 > V_2 -> V_352 . V_989 ) {
V_988 = V_2 -> V_352 . V_353 -
V_2 -> V_352 . V_989 ;
if ( ( V_988 > V_990 ) &&
( V_2 -> V_352 . V_983 == V_991 ) ) {
V_2 -> V_352 . V_983 = V_992 ;
V_977 ++ ;
} else if ( ( V_988 < V_993 ) &&
( V_2 -> V_352 . V_983 == V_992 ) ) {
V_2 -> V_352 . V_983 = V_991 ;
V_977 ++ ;
}
}
V_2 -> V_352 . V_989 = V_2 -> V_352 . V_353 ;
}
if ( V_977 )
V_41 = F_164 ( V_9 , & V_9 -> V_207 [ 0 ] , V_977 ) ;
F_167 ( & V_9 -> V_987 , F_76 ( 1000 ) ) ;
}
int F_168 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_160 ( V_9 ) ;
if ( V_41 )
goto V_994;
V_41 = F_43 ( V_9 ) ;
if ( V_41 )
goto V_995;
V_41 = F_85 ( V_9 ) ;
if ( V_41 )
goto V_996;
V_41 = F_89 ( V_9 ) ;
if ( V_41 )
goto V_996;
V_41 = F_83 ( V_9 ) ;
if ( V_41 )
goto V_996;
V_41 = F_102 ( V_9 ) ;
if ( V_41 )
goto V_996;
V_41 = F_91 ( V_9 ) ;
if ( V_41 )
goto V_997;
V_41 = F_88 ( V_9 ) ;
if ( V_41 )
goto V_997;
return 0 ;
V_997:
F_104 ( V_9 ) ;
V_996:
F_46 ( V_9 ) ;
V_995:
F_36 ( V_9 ) ;
V_994:
F_52 ( L_16 , V_293 , V_41 ) ;
return V_41 ;
}
void F_169 ( struct V_8 * V_9 )
{
F_98 ( V_9 ) ;
F_104 ( V_9 ) ;
F_46 ( V_9 ) ;
F_36 ( V_9 ) ;
}
