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
static void * F_21 ( void )
{
return F_20 ( sizeof( struct V_17 ) , V_145 ) ;
}
static void F_22 ( struct V_8 * V_9 , struct V_157 * V_3 )
{
F_23 ( & V_9 -> V_117 . V_158 -> V_9 , V_3 -> V_159 , V_3 -> V_4 , V_3 -> V_160 ) ;
}
static int F_24 ( struct V_8 * V_9 ,
struct V_157 * V_3 , T_3 V_161 , T_3 V_162 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_161 = V_161 ;
V_3 -> V_162 = V_162 ;
V_3 -> V_159 = V_161 * V_162 ;
V_3 -> V_4 = F_25 ( & V_9 -> V_117 . V_158 -> V_9 , V_3 -> V_159 ,
& V_3 -> V_160 , V_145 ) ;
if ( ! V_3 -> V_4 )
return - V_163 ;
memset ( V_3 -> V_4 , 0 , V_3 -> V_159 ) ;
return 0 ;
}
static void F_26 ( struct V_164 * V_165 , int V_166 ,
T_4 V_167 , int V_168 )
{
int V_169 ;
for ( V_169 = 0 ; V_169 < V_166 ; V_169 ++ ) {
V_165 [ V_169 ] . V_170 = ( T_1 ) ( V_167 & 0xffffffff ) ;
V_165 [ V_169 ] . V_171 = ( T_1 ) F_27 ( V_167 ) ;
V_167 += V_168 ;
}
}
static int F_28 ( struct V_8 * V_9 ,
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
F_29 () ;
}
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
F_18 ( & V_174 -> V_182 , V_138 , V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_120 = V_3 -> V_120 ;
V_41 = F_30 ( V_9 -> V_117 . V_184 ,
V_174 , sizeof( * V_174 ) , NULL , NULL ) ;
if ( ! V_41 )
V_3 -> V_185 = false ;
return V_41 ;
}
static int F_31 ( struct V_8 * V_9 , struct V_1 * V_2 )
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
F_26 ( & V_174 -> V_195 [ 0 ] , V_174 -> V_191 , V_2 -> V_3 . V_160 ,
V_196 ) ;
V_41 = F_30 ( V_9 -> V_117 . V_184 , V_174 , sizeof( * V_174 ) , NULL ,
NULL ) ;
if ( ! V_41 ) {
V_2 -> V_3 . V_120 = V_188 -> V_197 & 0xffff ;
V_2 -> V_198 = ( V_188 -> V_197 >> 16 ) & 0xffff ;
V_2 -> V_3 . V_185 = true ;
}
return V_41 ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_3 V_199 )
{
int V_41 ;
V_41 = F_24 ( V_9 , & V_2 -> V_3 , V_7 ,
sizeof( struct V_6 ) ) ;
if ( V_41 )
return V_41 ;
V_41 = F_31 ( V_9 , V_2 ) ;
if ( V_41 )
goto V_200;
V_2 -> V_9 = V_9 ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , true , true , 0 ) ;
return 0 ;
V_200:
F_22 ( V_9 , & V_2 -> V_3 ) ;
return V_41 ;
}
int F_33 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_201 ;
if ( V_9 -> V_117 . V_202 == V_203 )
V_201 = V_9 -> V_117 . V_158 -> V_201 ;
else
V_201 = V_9 -> V_117 . V_204 . V_205 [ V_2 -> V_198 ] ;
return V_201 ;
}
static void F_34 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_185 ) {
F_28 ( V_9 , & V_2 -> V_3 , V_180 ) ;
F_22 ( V_9 , & V_2 -> V_3 ) ;
}
}
static void F_35 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_201 ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , false , false , 0 ) ;
V_201 = F_33 ( V_9 , V_2 ) ;
F_36 ( V_201 , V_2 ) ;
F_34 ( V_9 , V_2 ) ;
}
static void F_37 ( struct V_8 * V_9 )
{
int V_169 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ )
F_35 ( V_9 , & V_9 -> V_207 [ V_169 ] ) ;
}
static int F_38 ( struct V_8 * V_9 ,
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
V_174 -> V_212 |= F_39 ( V_13 -> V_4 , V_13 -> V_159 ) ;
V_174 -> V_215 = V_216 ;
V_174 -> V_217 = V_2 -> V_120 ;
V_174 -> V_218 = V_13 -> V_159 / sizeof( struct V_10 ) ;
F_26 ( & V_174 -> V_195 [ 0 ] , V_13 -> V_159 / V_213 ,
V_13 -> V_160 , V_196 ) ;
V_41 = F_30 ( V_9 -> V_117 . V_184 ,
V_174 , sizeof( * V_174 ) , NULL , NULL ) ;
if ( ! V_41 ) {
V_13 -> V_120 = ( T_3 ) ( V_188 -> V_106 & V_219 ) ;
V_13 -> V_185 = true ;
}
return V_41 ;
}
static T_1 F_40 ( int V_199 )
{
T_1 V_220 = F_41 ( V_199 ) ;
if ( V_220 == 16 )
V_220 = 0 ;
return V_220 ;
}
static int F_42 ( struct V_8 * V_9 ,
struct V_157 * V_12 ,
struct V_157 * V_13 )
{
int V_191 , V_41 ;
struct V_221 * V_174 = V_9 -> V_175 ;
struct V_222 * V_188 = V_9 -> V_175 ;
struct V_164 * V_195 ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
V_191 = F_39 ( V_12 -> V_4 , V_12 -> V_159 ) ;
F_18 ( & V_174 -> V_182 , V_223 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_182 . V_190 = 1 ;
V_174 -> V_224 = V_191 ;
V_174 -> V_224 |= ( V_13 -> V_120 << V_225 ) ;
V_174 -> V_226 = V_227 ;
V_174 -> V_228 = F_43 ( V_229 ) ;
V_174 -> V_228 |= F_43 ( V_230 ) ;
V_174 -> V_231 = V_13 -> V_120 ;
V_174 -> V_231 |= ( F_40 ( V_12 -> V_161 ) <<
V_232 ) ;
V_174 -> V_192 = V_233 ;
V_195 = & V_174 -> V_195 [ 0 ] ;
F_26 ( V_195 , V_191 , V_12 -> V_160 , V_196 ) ;
V_41 = F_30 ( V_9 -> V_117 . V_184 ,
V_174 , sizeof( * V_174 ) , NULL , NULL ) ;
if ( ! V_41 ) {
V_12 -> V_120 = V_188 -> V_120 ;
V_12 -> V_185 = true ;
}
return V_41 ;
}
static int F_44 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_24 ( V_9 , & V_9 -> V_12 . V_13 , V_16 ,
sizeof( struct V_10 ) ) ;
if ( V_41 )
goto V_234;
V_9 -> V_207 [ 0 ] . V_235 ++ ;
V_41 = F_38 ( V_9 , & V_9 -> V_12 . V_13 , & V_9 -> V_207 [ 0 ] . V_3 ) ;
if ( V_41 )
goto V_236;
memset ( & V_9 -> V_21 , 0 , sizeof( V_9 -> V_21 ) ) ;
F_45 ( & V_9 -> V_21 . V_237 ) ;
F_46 ( & V_9 -> V_21 . V_238 ) ;
V_41 = F_24 ( V_9 , & V_9 -> V_12 . V_18 , V_20 ,
sizeof( struct V_17 ) ) ;
if ( V_41 )
goto V_239;
V_41 = F_42 ( V_9 , & V_9 -> V_12 . V_18 , & V_9 -> V_12 . V_13 ) ;
if ( V_41 )
goto V_240;
F_14 ( V_9 , V_9 -> V_12 . V_13 . V_120 , true , false , 0 ) ;
return 0 ;
V_240:
F_22 ( V_9 , & V_9 -> V_12 . V_18 ) ;
V_239:
F_28 ( V_9 , & V_9 -> V_12 . V_13 , V_178 ) ;
V_236:
F_22 ( V_9 , & V_9 -> V_12 . V_13 ) ;
V_234:
return V_41 ;
}
static void F_47 ( struct V_8 * V_9 )
{
struct V_157 * V_241 , * V_13 ;
F_48 ( & V_9 -> V_21 . V_238 ) ;
V_241 = & V_9 -> V_12 . V_18 ;
if ( V_241 -> V_185 ) {
F_28 ( V_9 , V_241 , V_176 ) ;
F_22 ( V_9 , V_241 ) ;
}
F_49 ( & V_9 -> V_21 . V_238 ) ;
V_13 = & V_9 -> V_12 . V_13 ;
if ( V_13 -> V_185 ) {
F_28 ( V_9 , V_13 , V_178 ) ;
F_22 ( V_9 , V_13 ) ;
}
}
static void F_50 ( struct V_8 * V_9 ,
struct V_242 * V_243 )
{
enum V_23 V_244 = V_40 ;
enum V_23 V_245 ;
if ( V_243 == NULL )
F_29 () ;
F_51 ( V_243 , V_244 , & V_245 ) ;
}
static void F_52 ( struct V_8 * V_9 ,
struct V_246 * V_11 )
{
struct V_242 * V_243 = NULL ;
struct V_247 * V_13 = NULL ;
struct V_248 V_249 = { 0 } ;
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
F_50 ( V_9 , V_243 ) ;
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
F_53 ( L_5 , V_293 , type ) ;
break;
}
if ( V_251 ) {
if ( V_243 -> V_274 . V_294 )
V_243 -> V_274 . V_294 ( & V_249 , V_243 -> V_274 . V_295 ) ;
} else if ( V_250 ) {
if ( V_13 -> V_269 . V_294 )
V_13 -> V_269 . V_294 ( & V_249 , V_13 -> V_269 . V_296 ) ;
} else if ( V_252 ) {
if ( V_243 -> V_286 -> V_287 . V_294 )
V_243 -> V_286 -> V_287 . V_294 ( & V_249 ,
V_243 -> V_286 -> V_287 .
V_297 ) ;
} else if ( V_253 ) {
F_53 ( L_6 , V_9 -> V_266 . V_298 ) ;
F_54 ( & V_249 ) ;
}
}
static void F_55 ( struct V_8 * V_9 ,
struct V_246 * V_11 )
{
struct V_299 * V_300 ;
int type = ( V_11 -> V_254 & V_255 ) >>
V_256 ;
switch ( type ) {
case V_301 :
V_300 = (struct V_299 * ) V_11 ;
if ( ( V_300 -> V_302 & V_303 ) >>
V_304 )
V_9 -> V_305 = ( ( V_300 -> V_302 &
V_306 ) >>
V_307 ) ;
break;
default:
break;
}
}
static void F_56 ( struct V_8 * V_9 , void * V_308 )
{
struct V_246 * V_11 = V_308 ;
T_1 V_309 = ( V_11 -> V_254 & V_310 ) >>
V_311 ;
if ( V_309 == V_230 )
F_52 ( V_9 , V_11 ) ;
else if ( V_309 == V_229 )
F_55 ( V_9 , V_11 ) ;
else
F_53 ( L_7 , V_293 ,
V_9 -> V_120 , V_309 ) ;
}
static void F_57 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
if ( V_9 -> V_21 . V_22 == V_11 -> V_312 && V_9 -> V_21 . V_313 == false ) {
V_9 -> V_21 . V_99 = ( V_11 -> V_41 &
V_314 ) >> V_315 ;
V_9 -> V_21 . V_316 =
( V_11 -> V_41 & V_317 )
>> V_318 ;
V_9 -> V_21 . V_313 = true ;
F_58 ( & V_9 -> V_21 . V_237 ) ;
} else
F_53 ( L_8 ,
V_293 , V_11 -> V_312 , V_9 -> V_21 . V_22 ) ;
}
static int F_59 ( struct V_8 * V_9 , T_3 V_106 )
{
T_3 V_109 = 0 ;
struct V_10 * V_11 ;
while ( 1 ) {
V_11 = F_3 ( V_9 ) ;
if ( V_11 == NULL )
break;
F_60 ( V_11 , sizeof( * V_11 ) ) ;
V_109 += 1 ;
if ( V_11 -> V_14 & V_319 )
F_56 ( V_9 , V_11 ) ;
else if ( V_11 -> V_14 & V_320 )
F_57 ( V_9 , V_11 ) ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
F_5 ( V_9 ) ;
}
F_14 ( V_9 , V_9 -> V_12 . V_13 . V_120 , true , false , V_109 ) ;
return 0 ;
}
static void F_61 ( struct V_8 * V_9 ,
struct V_247 * V_13 )
{
unsigned long V_321 ;
struct V_242 * V_243 ;
bool V_322 = false ;
F_62 ( & V_9 -> V_323 , V_321 ) ;
F_63 (qp, &cq->sq_head, sq_entry) {
if ( V_243 -> V_286 )
continue;
if ( V_243 -> V_324 == V_243 -> V_325 )
continue;
if ( V_243 -> V_324 == V_13 )
V_13 = V_243 -> V_325 ;
else
V_13 = V_243 -> V_324 ;
V_322 = true ;
break;
}
F_64 ( & V_9 -> V_323 , V_321 ) ;
if ( V_322 == false )
return;
if ( V_13 -> V_269 . V_326 ) {
F_62 ( & V_13 -> V_327 , V_321 ) ;
(* V_13 -> V_269 . V_326 ) ( & V_13 -> V_269 , V_13 -> V_269 . V_296 ) ;
F_64 ( & V_13 -> V_327 , V_321 ) ;
}
}
static void F_65 ( struct V_8 * V_9 , T_3 V_328 )
{
unsigned long V_321 ;
struct V_247 * V_13 ;
if ( V_328 >= V_329 )
F_29 () ;
V_13 = V_9 -> V_263 [ V_328 ] ;
if ( V_13 == NULL )
return;
if ( V_13 -> V_269 . V_326 ) {
F_62 ( & V_13 -> V_327 , V_321 ) ;
(* V_13 -> V_269 . V_326 ) ( & V_13 -> V_269 , V_13 -> V_269 . V_296 ) ;
F_64 ( & V_13 -> V_327 , V_321 ) ;
}
F_61 ( V_9 , V_13 ) ;
}
static void F_66 ( struct V_8 * V_9 , T_3 V_106 )
{
if ( V_106 == V_9 -> V_12 . V_13 . V_120 )
F_59 ( V_9 , V_106 ) ;
else
F_65 ( V_9 , V_106 ) ;
}
static T_5 F_67 ( int V_201 , void * V_330 )
{
struct V_1 * V_2 = V_330 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 V_331 ;
struct V_6 * V_332 ;
T_3 V_106 ;
int V_333 = V_2 -> V_235 ;
do {
V_332 = F_1 ( V_2 ) ;
V_331 = * V_332 ;
F_60 ( & V_331 , sizeof( V_331 ) ) ;
if ( ( V_331 . V_334 & V_335 ) == 0 )
break;
V_332 -> V_334 = 0 ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , false , true , 1 ) ;
if ( ( V_331 . V_334 & V_336 ) == 0 ) {
V_106 = V_331 . V_334 >> V_337 ;
F_66 ( V_9 , V_106 ) ;
}
F_2 ( V_2 ) ;
if ( V_333 )
V_333 -- ;
} while ( V_333 );
F_17 ( V_9 , V_2 -> V_3 . V_120 , true , true , 0 ) ;
return V_338 ;
}
static void F_68 ( struct V_8 * V_9 , struct V_17 * V_174 )
{
struct V_17 * V_144 ;
V_9 -> V_21 . V_22 = V_9 -> V_12 . V_18 . V_19 ;
V_9 -> V_21 . V_313 = false ;
V_144 = F_6 ( V_9 ) ;
V_174 -> V_146 . V_312 = V_9 -> V_12 . V_18 . V_19 ;
F_69 ( V_144 , V_174 , sizeof( * V_144 ) ) ;
F_70 () ;
F_7 ( V_9 ) ;
F_16 ( V_9 ) ;
}
static int F_71 ( struct V_8 * V_9 )
{
long V_41 ;
V_41 = F_72 ( V_9 -> V_21 . V_237 ,
( V_9 -> V_21 . V_313 != false ) ,
F_73 ( 30000 ) ) ;
if ( V_41 )
return 0 ;
else
return - 1 ;
}
static int F_74 ( struct V_8 * V_9 , struct V_17 * V_144 )
{
int V_41 = 0 ;
T_3 V_99 , V_316 ;
struct V_17 * V_339 ;
struct V_340 * V_188 = NULL ;
F_48 ( & V_9 -> V_21 . V_238 ) ;
F_68 ( V_9 , V_144 ) ;
V_41 = F_71 ( V_9 ) ;
if ( V_41 )
goto V_200;
V_99 = V_9 -> V_21 . V_99 ;
V_316 = V_9 -> V_21 . V_316 ;
V_339 = F_8 ( V_9 ) ;
F_75 ( V_144 , V_339 , ( sizeof( * V_144 ) ) ) ;
if ( ( V_144 -> V_146 . V_147 & V_150 ) >>
V_149 )
V_188 = & V_144 -> V_153 . V_188 ;
if ( V_99 || V_316 ) {
F_53 ( L_9 ,
V_293 , V_99 , V_316 ) ;
if ( V_188 ) {
F_53 ( L_10 ,
( V_188 -> V_141 & V_341 ) >>
V_342 ,
( V_188 -> V_141 & V_343 ) >>
V_344 ) ;
}
V_41 = F_13 ( V_99 ) ;
goto V_200;
}
if ( V_188 && ( V_144 -> V_153 . V_188 . V_41 & V_44 ) )
V_41 = F_11 ( V_144 -> V_153 . V_188 . V_41 ) ;
V_200:
F_49 ( & V_9 -> V_21 . V_238 ) ;
return V_41 ;
}
static int F_76 ( struct V_8 * V_9 , struct V_17 * V_144 ,
void * V_345 )
{
int V_41 = 0 ;
struct V_340 * V_188 = V_345 ;
if ( ( V_144 -> V_146 . V_147 & V_150 ) >>
V_149 )
F_29 () ;
V_41 = F_74 ( V_9 , V_144 ) ;
if ( ! V_41 )
if ( V_188 -> V_41 & V_44 )
V_41 = F_11 ( V_188 -> V_41 ) ;
if ( V_41 )
F_53 ( L_10 ,
( V_188 -> V_141 & V_341 ) >>
V_342 ,
( V_188 -> V_141 & V_343 ) >>
V_344 ) ;
return V_41 ;
}
static void F_77 ( struct V_8 * V_9 ,
struct V_346 * V_347 ,
struct V_348 * V_188 )
{
V_347 -> V_349 =
( V_188 -> V_350 & V_351 ) >>
V_352 ;
V_347 -> V_353 =
( V_188 -> V_354 & V_355 ) >>
V_356 ;
V_347 -> V_357 =
( V_188 -> V_358 & V_359 ) >>
V_360 ;
V_347 -> V_361 = ( ( V_188 -> V_362 &
V_363 ) >>
V_364 ) ;
V_347 -> V_365 = ( V_188 -> V_362 &
V_363 ) >>
V_364 ;
V_347 -> V_366 = ( V_188 -> V_367 &
V_368 ) >>
V_369 ;
V_347 -> V_370 = ( V_188 -> V_362 &
V_371 ) >>
V_372 ;
V_347 -> V_373 = ( V_188 -> V_374 &
V_375 ) >>
V_376 ;
V_347 -> V_377 = ( V_188 -> V_374 &
V_378 ) >>
V_379 ;
V_347 -> V_380 = ( V_188 -> V_354 &
V_381 ) >>
V_382 ;
V_347 -> V_383 = ( V_188 -> V_354 &
V_384 ) >>
V_385 ;
V_347 -> V_386 = ( V_188 -> V_350 &
V_387 ) >>
V_388 ;
V_347 -> V_389 = V_188 -> V_389 ;
V_347 -> V_390 = V_188 -> V_390 ;
V_347 -> V_391 = ~ 0ull ;
V_347 -> V_392 = 0 ;
V_347 -> V_393 = V_188 -> V_393 ;
V_347 -> V_394 = V_188 -> V_394 ;
V_347 -> V_395 = V_188 -> V_396 &
V_397 ;
V_347 -> V_398 = ( V_188 -> V_396 &
V_399 ) >>
V_400 ;
V_347 -> V_401 = ( ( V_188 -> V_402 &
V_403 ) >>
V_404 ) *
V_405 ;
V_347 -> V_406 = ( ( V_188 -> V_402 &
V_407 ) >>
V_408 ) *
V_405 ;
V_347 -> V_409 =
V_347 -> V_401 - ( sizeof( struct V_410 ) +
sizeof( struct V_411 ) ) ;
if ( F_78 ( V_9 ) == V_412 ) {
V_347 -> V_413 = 1 ;
V_347 -> V_414 = V_213 ;
V_347 -> V_415 = V_416 ;
}
V_9 -> V_347 . V_417 = V_188 -> V_418 >>
V_419 ;
V_9 -> V_347 . V_420 = V_188 -> V_418 &
V_421 ;
}
static int F_79 ( struct V_8 * V_9 ,
struct V_422 * V_423 )
{
T_1 V_424 ;
V_424 = V_423 -> V_424 & V_425 ;
if ( V_424 != V_425 )
return - V_72 ;
V_9 -> V_426 = V_423 -> V_426 ;
V_9 -> V_427 = V_423 -> V_427 ;
return 0 ;
}
static int F_80 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_428 * V_188 ;
V_174 = F_19 ( V_429 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_429 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_428 * ) V_174 ;
memset ( & V_9 -> V_347 . V_430 [ 0 ] , 0 , sizeof( V_9 -> V_347 . V_430 ) ) ;
memcpy ( & V_9 -> V_347 . V_430 [ 0 ] , & V_188 -> V_431 [ 0 ] ,
sizeof( V_188 -> V_431 ) ) ;
F_60 ( V_9 -> V_347 . V_430 , sizeof( V_188 -> V_431 ) ) ;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
static int F_82 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_422 * V_188 ;
V_174 = F_19 ( V_432 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_432 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_422 * ) V_174 ;
V_41 = F_79 ( V_9 , V_188 ) ;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_83 ( struct V_8 * V_9 , bool V_433 )
{
struct V_434 * V_182 = V_9 -> V_435 . V_4 ;
struct V_17 * V_144 = & V_9 -> V_435 . V_144 ;
struct V_436 * V_437 = NULL ;
int V_41 ;
V_437 = F_20 ( sizeof( * V_437 ) , V_145 ) ;
if ( V_437 == NULL )
return - V_163 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> V_146 . V_151 = V_9 -> V_435 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_438 ) &
V_439 ;
V_144 -> V_153 . V_440 . V_441 [ 0 ] . V_442 = ( T_1 ) ( V_9 -> V_435 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_440 . V_441 [ 0 ] . V_443 = ( T_1 ) F_27 ( V_9 -> V_435 . V_195 ) ;
V_144 -> V_153 . V_440 . V_441 [ 0 ] . V_161 = V_9 -> V_435 . V_159 ;
memcpy ( V_437 , V_182 , sizeof( struct V_436 ) ) ;
memset ( V_182 , 0 , V_9 -> V_435 . V_159 ) ;
F_18 ( (struct V_136 * ) V_182 ,
V_444 ,
V_156 ,
V_9 -> V_435 . V_159 ) ;
if ( V_433 )
V_182 -> V_445 = V_433 ;
V_41 = F_76 ( V_9 , V_144 , V_9 -> V_435 . V_4 ) ;
if ( V_41 )
memcpy ( V_182 , V_437 , sizeof( struct V_436 ) ) ;
else
F_60 ( V_182 , V_9 -> V_435 . V_159 ) ;
F_81 ( V_437 ) ;
return V_41 ;
}
static int F_84 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_446 V_160 ;
struct V_17 * V_144 ;
struct V_447 * V_448 ;
struct V_449 * V_450 ;
V_144 = F_21 () ;
if ( ! V_144 )
return V_41 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_160 . V_159 = sizeof( struct V_447 ) ;
V_160 . V_4 = F_25 ( & V_9 -> V_117 . V_158 -> V_9 ,
V_160 . V_159 , & V_160 . V_195 , V_145 ) ;
if ( ! V_160 . V_4 )
goto V_451;
V_144 -> V_146 . V_151 = V_160 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_438 ) &
V_439 ;
V_144 -> V_153 . V_440 . V_441 [ 0 ] . V_442 = ( T_1 ) ( V_160 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_440 . V_441 [ 0 ] . V_443 = ( T_1 ) F_27 ( V_160 . V_195 ) ;
V_144 -> V_153 . V_440 . V_441 [ 0 ] . V_161 = V_160 . V_159 ;
memset ( V_160 . V_4 , 0 , V_160 . V_159 ) ;
F_18 ( (struct V_136 * ) V_160 . V_4 ,
V_452 ,
V_183 ,
V_160 . V_159 ) ;
V_41 = F_76 ( V_9 , V_144 , V_160 . V_4 ) ;
if ( ! V_41 ) {
V_448 = (struct V_447 * ) V_160 . V_4 ;
V_450 = & V_448 -> V_453 . V_450 ;
V_9 -> V_454 = V_450 -> V_455 ;
strncpy ( V_9 -> V_456 ,
V_450 -> V_457 , 31 ) ;
}
F_23 ( & V_9 -> V_117 . V_158 -> V_9 , V_160 . V_159 , V_160 . V_4 , V_160 . V_195 ) ;
V_451:
F_81 ( V_144 ) ;
return V_41 ;
}
static int F_85 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_348 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_458 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_348 * ) V_174 ;
F_77 ( V_9 , & V_9 -> V_347 , V_188 ) ;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_86 ( struct V_8 * V_9 , T_2 * V_459 )
{
int V_41 = - V_163 ;
struct V_460 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_461 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_461 ,
V_183 , sizeof( * V_174 ) ) ;
( (struct V_136 * ) V_174 -> V_153 . V_174 ) -> V_190 = 0x1 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_460 * ) V_174 ;
* V_459 = V_188 -> V_462 ;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
static int F_87 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_463 * V_188 ;
V_174 = F_19 ( V_464 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_464 , V_183 ,
sizeof( * V_174 ) ) ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_463 * ) V_174 ;
V_9 -> V_93 . V_465 = F_88 ( V_188 -> V_465 ) ;
V_9 -> V_93 . V_95 =
F_88 ( V_188 -> V_95 ) ;
V_9 -> V_93 . V_94 =
F_88 ( V_188 -> V_94 ) ;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_89 ( struct V_8 * V_9 , struct V_466 * V_467 )
{
int V_41 = - V_163 ;
struct V_468 * V_174 ;
struct V_469 * V_188 ;
V_174 = F_19 ( V_470 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
if ( V_467 -> V_471 )
V_174 -> V_472 |= V_473 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_469 * ) V_174 ;
V_467 -> V_120 = V_188 -> V_474 & V_475 ;
if ( V_188 -> V_474 & V_476 ) {
V_467 -> V_471 = true ;
V_467 -> V_477 = V_188 -> V_474 >>
V_478 ;
} else {
V_467 -> V_471 = false ;
V_467 -> V_479 = 0 ;
}
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_90 ( struct V_8 * V_9 , struct V_466 * V_467 )
{
int V_41 = - V_163 ;
struct V_480 * V_174 ;
V_174 = F_19 ( V_481 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_467 -> V_120 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
F_81 ( V_174 ) ;
return V_41 ;
}
static int F_91 ( T_1 * V_482 , int V_162 ,
int * V_191 , int * V_483 )
{
int V_169 ;
int V_484 ;
* V_482 = F_92 ( * V_482 ) ;
V_484 = * V_482 * V_162 ;
for ( V_169 = 0 ; V_169 < V_485 ; V_169 ++ ) {
if ( V_484 <= ( V_486 << V_169 ) )
break;
}
if ( V_169 >= V_485 )
return - V_72 ;
V_484 = F_93 ( V_484 ,
( ( V_486 << V_169 ) / V_487 ) ) ;
* V_191 =
V_484 / ( ( V_486 << V_169 ) / V_487 ) ;
* V_483 = ( ( V_486 << V_169 ) / V_487 ) ;
* V_482 = V_484 / V_162 ;
return 0 ;
}
static int F_94 ( struct V_8 * V_9 )
{
int V_169 ;
int V_41 = 0 ;
int V_488 ;
struct V_489 * V_174 ;
struct V_490 * V_188 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 ;
struct V_492 * V_493 ;
V_174 = F_19 ( V_494 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_488 = V_495 ;
V_9 -> V_496 . V_159 = sizeof( struct V_497 ) * V_488 ;
V_174 -> V_498 = ( V_499 <<
V_500 ) &
V_501 ;
for ( V_169 = 0 ; V_169 < V_485 ; V_169 ++ ) {
if ( V_502 == ( V_213 << V_169 ) )
break;
}
V_174 -> V_498 |= ( V_169 << V_503 ) &
V_504 ;
V_174 -> V_498 |= ( sizeof( struct V_497 ) <<
V_505 ) &
V_506 ;
V_9 -> V_496 . V_507 . V_4 = F_25 ( & V_158 -> V_9 , V_502 ,
& V_9 -> V_496 . V_507 . V_195 ,
V_145 ) ;
if ( V_9 -> V_496 . V_507 . V_4 == NULL )
goto V_508;
V_9 -> V_496 . V_4 = F_25 ( & V_158 -> V_9 , V_9 -> V_496 . V_159 ,
& V_195 , V_145 ) ;
if ( V_9 -> V_496 . V_4 == NULL )
goto V_509;
V_9 -> V_496 . V_195 = V_195 ;
V_9 -> V_496 . V_510 = V_488 ;
memset ( V_9 -> V_496 . V_4 , 0 , V_9 -> V_496 . V_159 ) ;
V_493 = (struct V_492 * ) V_9 -> V_496 . V_507 . V_4 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_496 . V_159 / V_213 ; V_169 ++ ) {
V_493 [ V_169 ] . V_442 = ( T_1 ) ( V_195 & 0xffffffff ) ;
V_493 [ V_169 ] . V_443 = ( T_1 ) F_27 ( V_195 ) ;
V_195 += V_502 ;
}
V_174 -> V_511 [ 0 ] . V_170 = ( T_1 ) ( V_9 -> V_496 . V_507 . V_195 & 0xFFFFFFFF ) ;
V_174 -> V_511 [ 0 ] . V_171 = ( T_1 ) F_27 ( V_9 -> V_496 . V_507 . V_195 ) ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_490 * ) V_174 ;
V_9 -> V_496 . V_512 = V_188 -> V_512 & 0xFFFF ;
F_81 ( V_174 ) ;
return 0 ;
V_200:
F_23 ( & V_158 -> V_9 , V_9 -> V_496 . V_159 , V_9 -> V_496 . V_4 ,
V_9 -> V_496 . V_195 ) ;
V_9 -> V_496 . V_4 = NULL ;
V_509:
F_23 ( & V_158 -> V_9 , V_502 , V_9 -> V_496 . V_507 . V_4 ,
V_9 -> V_496 . V_507 . V_195 ) ;
V_9 -> V_496 . V_507 . V_4 = NULL ;
V_9 -> V_496 . V_159 = 0 ;
V_508:
F_81 ( V_174 ) ;
return V_41 ;
}
static void F_95 ( struct V_8 * V_9 )
{
struct V_513 * V_174 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
if ( V_9 -> V_496 . V_4 == NULL )
return;
V_174 = F_19 ( V_514 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return;
V_174 -> V_512 = V_9 -> V_496 . V_512 ;
F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
F_23 ( & V_158 -> V_9 , V_9 -> V_496 . V_159 , V_9 -> V_496 . V_4 ,
V_9 -> V_496 . V_195 ) ;
F_23 ( & V_158 -> V_9 , V_502 , V_9 -> V_496 . V_507 . V_4 ,
V_9 -> V_496 . V_507 . V_195 ) ;
F_81 ( V_174 ) ;
}
static T_3 F_96 ( struct V_8 * V_9 )
{
int V_169 , V_515 = 0 , V_235 = 0 ;
T_3 V_124 ;
F_48 ( & V_9 -> V_516 ) ;
V_235 = V_9 -> V_207 [ 0 ] . V_235 ;
V_124 = V_9 -> V_207 [ 0 ] . V_3 . V_120 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
if ( V_9 -> V_207 [ V_169 ] . V_235 < V_235 ) {
V_235 = V_9 -> V_207 [ V_169 ] . V_235 ;
V_124 = V_9 -> V_207 [ V_169 ] . V_3 . V_120 ;
V_515 = V_169 ;
}
}
V_9 -> V_207 [ V_515 ] . V_235 += 1 ;
F_49 ( & V_9 -> V_516 ) ;
return V_124 ;
}
static void F_97 ( struct V_8 * V_9 , T_3 V_124 )
{
int V_169 ;
F_48 ( & V_9 -> V_516 ) ;
V_169 = F_98 ( V_9 , V_124 ) ;
if ( V_169 == - V_72 )
F_29 () ;
V_9 -> V_207 [ V_169 ] . V_235 -= 1 ;
F_49 ( & V_9 -> V_516 ) ;
}
int F_99 ( struct V_8 * V_9 , struct V_247 * V_13 ,
int V_517 , int V_518 , T_3 V_519 )
{
int V_41 = - V_163 ; int V_520 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
struct V_521 * V_174 ;
struct V_522 * V_188 ;
T_1 V_523 , V_524 , V_483 , V_218 ;
if ( V_517 > V_9 -> V_347 . V_395 ) {
F_53 ( L_11 ,
V_293 , V_9 -> V_120 , V_9 -> V_347 . V_395 , V_517 ) ;
return - V_72 ;
}
if ( V_518 && ( F_78 ( V_9 ) != V_412 ) )
return - V_72 ;
if ( V_518 ) {
V_13 -> V_520 = 1 ;
V_520 = 1 ;
V_524 = V_525 ;
V_523 = 1 ;
} else {
V_13 -> V_520 = V_9 -> V_347 . V_395 ;
V_520 = V_9 -> V_347 . V_395 ;
V_524 = sizeof( struct V_526 ) ;
V_523 = V_527 ;
}
V_13 -> V_161 = F_93 ( V_520 * V_524 , V_213 ) ;
V_174 = F_19 ( V_210 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( & V_174 -> V_174 . V_182 , V_210 ,
V_183 , sizeof( * V_174 ) ) ;
V_13 -> V_4 = F_25 ( & V_158 -> V_9 , V_13 -> V_161 , & V_13 -> V_195 , V_145 ) ;
if ( ! V_13 -> V_4 ) {
V_41 = - V_163 ;
goto V_508;
}
memset ( V_13 -> V_4 , 0 , V_13 -> V_161 ) ;
V_483 = V_13 -> V_161 / V_523 ;
V_174 -> V_174 . V_212 = ( V_483 / V_213 ) <<
V_214 ;
V_174 -> V_174 . V_212 |= V_523 ;
V_174 -> V_174 . V_215 = V_216 ;
V_13 -> V_217 = F_96 ( V_9 ) ;
V_174 -> V_174 . V_182 . V_190 = V_528 ;
V_218 = V_13 -> V_161 / V_524 ;
V_13 -> V_529 = V_218 ;
if ( V_218 > 1024 ) {
V_174 -> V_174 . V_215 |= ( 0x3 << V_530 ) ;
} else {
T_2 V_531 = 0 ;
switch ( V_218 ) {
case 256 :
V_531 = 0 ;
break;
case 512 :
V_531 = 1 ;
break;
case 1024 :
V_531 = 2 ;
break;
default:
goto V_200;
}
V_174 -> V_174 . V_215 |= ( V_531 << V_530 ) ;
}
V_174 -> V_174 . V_217 = V_13 -> V_217 ;
if ( F_78 ( V_9 ) == V_412 ) {
if ( V_518 )
V_174 -> V_174 . V_212 |= V_532 <<
V_533 ;
V_13 -> V_534 = false ;
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_524 ) ;
} else {
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_524 ) - 1 ;
V_174 -> V_174 . V_215 |= V_535 ;
V_13 -> V_534 = true ;
}
V_174 -> V_174 . V_519 = V_519 ;
F_26 ( & V_174 -> V_174 . V_195 [ 0 ] , V_523 , V_13 -> V_195 , V_483 ) ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_522 * ) V_174 ;
V_13 -> V_120 = ( T_3 ) ( V_188 -> V_188 . V_106 & V_219 ) ;
F_81 ( V_174 ) ;
return 0 ;
V_200:
F_97 ( V_9 , V_13 -> V_217 ) ;
F_23 ( & V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
V_508:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_100 ( struct V_8 * V_9 , struct V_247 * V_13 )
{
int V_41 = - V_163 ;
struct V_536 * V_174 ;
V_174 = F_19 ( V_179 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_182 , V_179 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_537 |=
( V_13 -> V_120 << V_538 ) &
V_539 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
F_97 ( V_9 , V_13 -> V_217 ) ;
F_23 ( & V_9 -> V_117 . V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
F_81 ( V_174 ) ;
return V_41 ;
}
int F_101 ( struct V_8 * V_9 , struct V_540 * V_541 ,
T_1 V_542 , int V_543 )
{
int V_41 = - V_163 ;
struct V_544 * V_174 ;
struct V_545 * V_188 ;
V_174 = F_19 ( V_546 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_542 = V_542 ;
V_174 -> V_547 |= V_543 ;
V_174 -> V_547 |= ( V_541 -> V_548 << V_549 ) ;
V_174 -> V_547 |=
( V_541 -> V_550 << V_551 ) ;
V_174 -> V_547 |=
( V_541 -> V_552 << V_553 ) ;
V_174 -> V_547 |=
( V_541 -> V_554 << V_555 ) ;
V_174 -> V_547 |=
( V_541 -> V_556 << V_557 ) ;
V_174 -> V_547 |=
( V_541 -> V_558 << V_559 ) ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_545 * ) V_174 ;
V_541 -> V_560 = V_188 -> V_561 ;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_102 ( struct V_8 * V_9 , int V_548 , T_1 V_560 )
{
int V_41 = - V_163 ;
struct V_562 * V_174 ;
V_174 = F_19 ( V_563 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_560 = V_560 ;
V_174 -> V_564 = V_548 ? 1 : 0 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
static int F_103 ( struct V_8 * V_9 , struct V_540 * V_541 ,
T_1 V_542 , T_1 V_565 , T_1 V_566 , T_1 V_567 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_568 * V_174 ;
struct V_569 * V_188 ;
V_174 = F_19 ( V_570 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_571 =
V_542 | ( V_541 -> V_558 << V_572 ) ;
V_174 -> V_548 = V_541 -> V_548 ;
V_174 -> V_573 |= ( V_541 -> V_550 <<
V_574 ) ;
V_174 -> V_573 |= ( V_541 -> V_552 <<
V_575 ) ;
V_174 -> V_573 |= ( V_541 -> V_554 <<
V_576 ) ;
V_174 -> V_573 |= ( V_541 -> V_556 <<
V_577 ) ;
V_174 -> V_573 |= ( V_541 -> V_578 <<
V_579 ) ;
V_174 -> V_573 |= ( V_567 << V_580 ) ;
V_174 -> V_573 |= ( V_541 -> V_566 / V_581 ) ;
V_174 -> V_573 |= ( V_541 -> V_582 / V_581 ) <<
V_583 ;
V_174 -> V_584 = V_541 -> V_161 ;
V_174 -> V_585 = F_27 ( V_541 -> V_161 ) ;
V_174 -> V_586 = ( T_1 ) ( V_541 -> V_587 & 0xffffffff ) ;
V_174 -> V_588 = ( T_1 ) F_27 ( V_541 -> V_587 ) ;
V_174 -> V_589 = ( T_1 ) V_541 -> V_4 ;
V_174 -> V_590 = ( T_1 ) F_27 ( V_541 -> V_4 ) ;
for ( V_169 = 0 ; V_169 < V_565 ; V_169 ++ ) {
V_174 -> V_507 [ V_169 ] . V_170 = ( T_1 ) ( V_541 -> V_591 [ V_169 ] . V_195 & 0xffffffff ) ;
V_174 -> V_507 [ V_169 ] . V_171 = F_27 ( V_541 -> V_591 [ V_169 ] . V_195 ) ;
}
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_569 * ) V_174 ;
V_541 -> V_560 = V_188 -> V_561 ;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
static int F_104 ( struct V_8 * V_9 ,
struct V_540 * V_541 , T_1 V_565 ,
T_1 V_592 , T_1 V_567 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_593 * V_174 ;
V_174 = F_19 ( V_594 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_561 = V_541 -> V_560 ;
V_174 -> V_595 = ( V_565 << V_596 ) |
( V_592 & V_597 ) ;
V_174 -> V_567 = V_567 << V_598 ;
for ( V_169 = 0 ; V_169 < V_565 ; V_169 ++ ) {
V_174 -> V_507 [ V_169 ] . V_170 =
( T_1 ) ( V_541 -> V_591 [ V_169 + V_592 ] . V_195 & 0xffffffff ) ;
V_174 -> V_507 [ V_169 ] . V_171 =
F_27 ( V_541 -> V_591 [ V_169 + V_592 ] . V_195 ) ;
}
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_105 ( struct V_8 * V_9 ,
struct V_540 * V_541 , T_1 V_542 , int V_599 )
{
int V_41 ;
T_1 V_567 = 0 ;
T_1 V_600 , V_592 ;
T_1 V_601 = V_541 -> V_558 ;
V_592 = 0 ;
V_600 = F_106 ( V_601 , V_602 ) ;
if ( V_600 == V_601 )
V_567 = 1 ;
V_41 = F_103 ( V_9 , V_541 , V_542 ,
V_600 , V_541 -> V_566 , V_567 ) ;
if ( V_41 ) {
F_53 ( L_12 , V_293 , V_41 ) ;
return V_41 ;
}
if ( V_567 )
return 0 ;
while ( ! V_567 ) {
V_592 += V_600 ;
V_601 -= V_600 ;
V_600 = F_106 ( V_601 , V_602 ) ;
if ( V_600 == V_601 )
V_567 = 1 ;
V_41 = F_104 ( V_9 , V_541 , V_600 ,
V_592 , V_567 ) ;
if ( V_41 )
break;
}
if ( V_41 )
F_53 ( L_13 , V_293 , V_41 ) ;
return V_41 ;
}
bool F_107 ( struct V_247 * V_13 , struct V_242 * V_243 )
{
struct V_242 * V_603 ;
bool V_604 = false ;
F_63 (tmp, &cq->sq_head, sq_entry) {
if ( V_243 == V_603 ) {
V_604 = true ;
break;
}
}
return V_604 ;
}
bool F_108 ( struct V_247 * V_13 , struct V_242 * V_243 )
{
struct V_242 * V_603 ;
bool V_604 = false ;
F_63 (tmp, &cq->rq_head, rq_entry) {
if ( V_243 == V_603 ) {
V_604 = true ;
break;
}
}
return V_604 ;
}
void F_109 ( struct V_242 * V_243 )
{
bool V_604 ;
unsigned long V_321 ;
F_62 ( & V_243 -> V_9 -> V_323 , V_321 ) ;
V_604 = F_107 ( V_243 -> V_324 , V_243 ) ;
if ( ! V_604 )
F_110 ( & V_243 -> V_605 , & V_243 -> V_324 -> V_606 ) ;
if ( ! V_243 -> V_286 ) {
V_604 = F_108 ( V_243 -> V_325 , V_243 ) ;
if ( ! V_604 )
F_110 ( & V_243 -> V_607 , & V_243 -> V_325 -> V_608 ) ;
}
F_64 ( & V_243 -> V_9 -> V_323 , V_321 ) ;
}
static void F_111 ( struct V_242 * V_243 )
{
V_243 -> V_18 . V_19 = 0 ;
V_243 -> V_18 . V_5 = 0 ;
V_243 -> V_609 . V_19 = 0 ;
V_243 -> V_609 . V_5 = 0 ;
}
int F_51 ( struct V_242 * V_243 , enum V_23 V_610 ,
enum V_23 * V_611 )
{
unsigned long V_321 ;
int V_41 = 0 ;
enum V_24 V_612 ;
V_612 = F_10 ( V_610 ) ;
F_62 ( & V_243 -> V_613 , V_321 ) ;
if ( V_611 )
* V_611 = F_9 ( V_243 -> V_614 ) ;
if ( V_612 == V_243 -> V_614 ) {
F_64 ( & V_243 -> V_613 , V_321 ) ;
return 1 ;
}
if ( V_612 == V_28 ) {
F_111 ( V_243 ) ;
F_112 ( V_243 ) ;
} else if ( V_612 == V_39 ) {
F_109 ( V_243 ) ;
}
V_243 -> V_614 = V_612 ;
F_64 ( & V_243 -> V_613 , V_321 ) ;
return V_41 ;
}
static T_1 F_113 ( struct V_242 * V_243 )
{
T_1 V_321 = 0 ;
if ( V_243 -> V_615 & V_616 )
V_321 |= V_617 ;
if ( V_243 -> V_615 & V_618 )
V_321 |= V_619 ;
if ( V_243 -> V_615 & V_620 )
V_321 |= V_621 ;
if ( V_243 -> V_615 & V_622 )
V_321 |= V_623 ;
if ( V_243 -> V_615 & V_624 )
V_321 |= V_625 ;
return V_321 ;
}
static int F_114 ( struct V_626 * V_174 ,
struct V_627 * V_628 ,
struct V_242 * V_243 )
{
int V_41 ;
T_1 V_161 , V_523 , V_168 ;
T_4 V_195 ;
struct V_8 * V_9 = V_243 -> V_9 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_629 ;
T_1 V_630 = V_628 -> V_631 . V_361 ;
V_629 = F_115 ( T_1 , V_628 -> V_631 . V_632 + 1 ,
V_9 -> V_347 . V_417 ) ;
V_41 = F_91 ( & V_629 ,
V_9 -> V_347 . V_401 , & V_523 , & V_168 ) ;
if ( V_41 ) {
F_53 ( L_14 , V_293 ,
V_629 ) ;
return - V_72 ;
}
V_243 -> V_18 . V_633 = V_629 ;
V_161 = ( V_523 * V_168 ) ;
V_243 -> V_18 . V_4 = F_25 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_243 -> V_18 . V_4 )
return - V_72 ;
memset ( V_243 -> V_18 . V_4 , 0 , V_161 ) ;
V_243 -> V_18 . V_161 = V_161 ;
V_243 -> V_18 . V_195 = V_195 ;
V_243 -> V_18 . V_162 = V_9 -> V_347 . V_401 ;
F_26 ( & V_174 -> V_634 [ 0 ] , V_523 , V_195 , V_168 ) ;
V_174 -> V_635 |= ( F_116 ( V_168 / V_213 )
<< V_636 ) ;
V_174 -> V_637 |= ( V_523 <<
V_638 ) &
V_639 ;
V_174 -> V_640 |= ( V_630 <<
V_641 ) &
V_642 ;
V_174 -> V_640 |= ( V_630 <<
V_643 ) &
V_644 ;
V_174 -> V_645 |= ( F_116 ( V_243 -> V_18 . V_633 ) <<
V_646 ) &
V_647 ;
V_174 -> V_648 |= ( V_9 -> V_347 . V_401 <<
V_649 ) &
V_650 ;
return 0 ;
}
static int F_117 ( struct V_626 * V_174 ,
struct V_627 * V_628 ,
struct V_242 * V_243 )
{
int V_41 ;
T_1 V_161 , V_523 , V_168 ;
T_4 V_195 = 0 ;
struct V_8 * V_9 = V_243 -> V_9 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_651 = V_628 -> V_631 . V_652 + 1 ;
V_41 = F_91 ( & V_651 , V_9 -> V_347 . V_406 ,
& V_523 , & V_168 ) ;
if ( V_41 ) {
F_53 ( L_15 , V_293 ,
V_628 -> V_631 . V_652 + 1 ) ;
return V_41 ;
}
V_243 -> V_609 . V_633 = V_651 ;
V_161 = ( V_523 * V_168 ) ;
V_243 -> V_609 . V_4 = F_25 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_243 -> V_609 . V_4 )
return - V_163 ;
memset ( V_243 -> V_609 . V_4 , 0 , V_161 ) ;
V_243 -> V_609 . V_195 = V_195 ;
V_243 -> V_609 . V_161 = V_161 ;
V_243 -> V_609 . V_162 = V_9 -> V_347 . V_406 ;
F_26 ( & V_174 -> V_653 [ 0 ] , V_523 , V_195 , V_168 ) ;
V_174 -> V_635 |= ( F_116 ( V_168 / V_213 ) <<
V_654 ) ;
V_174 -> V_637 |=
( V_523 << V_655 ) &
V_656 ;
V_174 -> V_657 |= ( V_628 -> V_631 . V_365 <<
V_658 ) &
V_659 ;
V_174 -> V_645 |= ( F_116 ( V_243 -> V_609 . V_633 ) <<
V_660 ) &
V_661 ;
V_174 -> V_648 |= ( V_9 -> V_347 . V_406 <<
V_662 ) &
V_663 ;
return 0 ;
}
static void F_118 ( struct V_626 * V_174 ,
struct V_466 * V_467 ,
struct V_242 * V_243 ,
T_2 V_664 , T_3 V_665 )
{
V_467 -> V_479 -- ;
V_243 -> V_471 = true ;
V_174 -> V_657 |= V_666 ;
if ( ! V_664 )
return;
V_174 -> V_657 |= V_666 ;
V_174 -> V_667 = V_665 ;
V_174 -> V_667 |= V_668 <<
V_669 ;
}
static int F_119 ( struct V_626 * V_174 ,
struct V_242 * V_243 )
{
struct V_8 * V_9 = V_243 -> V_9 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 = 0 ;
int V_414 = V_9 -> V_347 . V_414 ;
int V_670 = V_9 -> V_347 . V_415 * V_414 ;
struct V_410 * V_671 ;
int V_169 = 0 ;
if ( V_9 -> V_347 . V_413 == 0 )
return 0 ;
V_243 -> V_672 = F_25 ( & V_158 -> V_9 , V_670 ,
& V_195 , V_145 ) ;
if ( ! V_243 -> V_672 )
return - V_163 ;
memset ( V_243 -> V_672 , 0 , V_670 ) ;
F_26 ( & V_174 -> V_673 [ 0 ] , V_9 -> V_347 . V_415 ,
V_195 , V_414 ) ;
for (; V_169 < V_670 / V_9 -> V_347 . V_406 ; V_169 ++ ) {
V_671 = (struct V_410 * ) ( V_243 -> V_672 +
( V_169 * V_9 -> V_347 . V_406 ) ) ;
V_671 -> V_674 = 0 ;
V_671 -> V_674 |= 2 ;
V_671 -> V_674 |= ( V_675 << V_676 ) ;
V_671 -> V_674 |= ( 8 << V_677 ) ;
V_671 -> V_674 |= ( 8 << V_678 ) ;
}
return 0 ;
}
static void F_120 ( struct V_679 * V_188 ,
struct V_242 * V_243 ,
struct V_627 * V_628 ,
T_3 * V_680 , T_3 * V_681 )
{
T_1 V_629 , V_651 ;
V_243 -> V_120 = V_188 -> V_682 & V_683 ;
V_243 -> V_609 . V_684 = V_188 -> V_685 & V_686 ;
V_243 -> V_18 . V_684 = V_188 -> V_685 >> V_687 ;
V_243 -> V_688 = V_188 -> V_689 & V_690 ;
V_243 -> V_691 = ( V_188 -> V_689 >> V_692 ) ;
V_243 -> V_471 = false ;
if ( V_188 -> V_693 & V_694 ) {
V_243 -> V_471 = true ;
* V_681 = ( V_188 -> V_693 &
V_695 ) >>
V_696 ;
* V_680 = ( V_188 -> V_693 &
V_697 ) >>
V_698 ;
}
V_629 =
V_188 -> V_645 >> V_699 ;
V_629 = 1 << V_629 ;
V_651 = 1 << ( ( T_3 ) V_188 -> V_645 ) ;
V_243 -> V_18 . V_633 = V_629 ;
V_243 -> V_18 . V_700 = V_629 - 1 ;
if ( ! V_628 -> V_286 ) {
V_243 -> V_609 . V_633 = V_651 ;
V_243 -> V_609 . V_700 = V_651 - 1 ;
}
}
int F_121 ( struct V_242 * V_243 , struct V_627 * V_628 ,
T_2 V_664 , T_3 V_665 , T_3 * V_680 ,
T_3 * V_681 )
{
int V_41 = - V_163 ;
T_1 V_321 = 0 ;
struct V_8 * V_9 = V_243 -> V_9 ;
struct V_466 * V_467 = V_243 -> V_467 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
struct V_247 * V_13 ;
struct V_626 * V_174 ;
struct V_679 * V_188 ;
int V_701 ;
switch ( V_628 -> V_702 ) {
case V_703 :
V_701 = V_704 ;
break;
case V_705 :
V_701 = V_706 ;
break;
case V_707 :
V_701 = V_708 ;
break;
default:
return - V_72 ;
}
V_174 = F_19 ( V_709 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_635 |= ( V_701 << V_710 ) &
V_711 ;
V_41 = F_114 ( V_174 , V_628 , V_243 ) ;
if ( V_41 )
goto V_712;
if ( V_628 -> V_286 ) {
struct V_713 * V_286 = F_122 ( V_628 -> V_286 ) ;
V_174 -> V_657 |= V_714 ;
V_174 -> V_653 [ 0 ] . V_170 = V_286 -> V_120 ;
V_243 -> V_286 = V_286 ;
} else {
V_41 = F_117 ( V_174 , V_628 , V_243 ) ;
if ( V_41 )
goto V_715;
}
V_41 = F_119 ( V_174 , V_243 ) ;
if ( V_41 )
goto V_200;
V_174 -> V_635 |= ( V_467 -> V_120 << V_716 ) &
V_717 ;
V_321 = F_113 ( V_243 ) ;
V_174 -> V_657 |= V_321 ;
V_174 -> V_689 |= ( V_9 -> V_347 . V_373 <<
V_718 ) &
V_719 ;
V_174 -> V_689 |= ( V_9 -> V_347 . V_377 <<
V_720 ) &
V_721 ;
V_13 = F_123 ( V_628 -> V_722 ) ;
V_174 -> V_723 |= ( V_13 -> V_120 << V_724 ) &
V_725 ;
V_243 -> V_324 = V_13 ;
V_13 = F_123 ( V_628 -> V_726 ) ;
V_174 -> V_723 |= ( V_13 -> V_120 << V_727 ) &
V_728 ;
V_243 -> V_325 = V_13 ;
if ( V_467 -> V_471 && V_467 -> V_479 ) {
F_118 ( V_174 , V_467 , V_243 , V_664 ,
V_665 ) ;
}
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_679 * ) V_174 ;
F_120 ( V_188 , V_243 , V_628 , V_680 , V_681 ) ;
V_243 -> V_614 = V_26 ;
F_81 ( V_174 ) ;
return 0 ;
V_200:
if ( V_243 -> V_609 . V_4 )
F_23 ( & V_158 -> V_9 , V_243 -> V_609 . V_161 , V_243 -> V_609 . V_4 , V_243 -> V_609 . V_195 ) ;
V_715:
F_53 ( L_16 , V_293 , V_9 -> V_120 ) ;
F_23 ( & V_158 -> V_9 , V_243 -> V_18 . V_161 , V_243 -> V_18 . V_4 , V_243 -> V_18 . V_195 ) ;
V_712:
F_53 ( L_17 , V_293 , V_9 -> V_120 ) ;
F_81 ( V_174 ) ;
return V_41 ;
}
int F_124 ( struct V_8 * V_9 , struct V_242 * V_243 ,
struct V_729 * V_730 )
{
int V_41 = - V_163 ;
struct V_731 * V_174 ;
struct V_732 * V_188 ;
V_174 = F_19 ( V_733 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_682 = V_243 -> V_120 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_732 * ) V_174 ;
memcpy ( V_730 , & V_188 -> V_734 , sizeof( struct V_729 ) ) ;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
static int F_125 ( struct V_242 * V_243 ,
struct V_735 * V_174 ,
struct V_736 * V_628 )
{
int V_41 ;
struct V_737 * V_738 = & V_628 -> V_738 ;
union V_739 V_740 , V_741 ;
T_1 V_742 ;
T_2 V_743 [ 6 ] ;
if ( ( V_738 -> V_744 & V_745 ) == 0 )
return - V_72 ;
V_174 -> V_734 . V_746 |=
( V_738 -> V_747 . V_748 << V_749 ) ;
V_174 -> V_734 . V_750 |=
( V_738 -> V_747 . V_751 & V_752 ) ;
V_174 -> V_734 . V_750 |= ( V_738 -> V_753 << V_754 ) ;
V_174 -> V_734 . V_755 |=
( V_738 -> V_747 . V_756 << V_757 ) ;
V_174 -> V_321 |= V_758 ;
memcpy ( & V_174 -> V_734 . V_759 [ 0 ] , & V_738 -> V_747 . V_759 . V_760 [ 0 ] ,
sizeof( V_174 -> V_734 . V_759 ) ) ;
V_41 = F_126 ( & V_243 -> V_9 -> V_266 , 1 ,
V_738 -> V_747 . V_761 , & V_740 ) ;
if ( V_41 )
return V_41 ;
memset ( & V_741 , 0 , sizeof( V_741 ) ) ;
if ( ! memcmp ( & V_740 , & V_741 , sizeof( V_741 ) ) )
return - V_72 ;
V_243 -> V_762 = V_738 -> V_747 . V_761 ;
memcpy ( & V_174 -> V_734 . V_740 [ 0 ] , & V_740 . V_760 [ 0 ] , sizeof( V_174 -> V_734 . V_740 ) ) ;
F_127 ( V_243 -> V_9 , V_738 , & V_743 [ 0 ] ) ;
V_174 -> V_734 . V_763 = V_743 [ 0 ] | ( V_743 [ 1 ] << 8 ) |
( V_743 [ 2 ] << 16 ) | ( V_743 [ 3 ] << 24 ) ;
F_128 ( & V_174 -> V_734 . V_759 [ 0 ] , sizeof( V_174 -> V_734 . V_759 ) ) ;
F_128 ( & V_174 -> V_734 . V_740 [ 0 ] , sizeof( V_174 -> V_734 . V_740 ) ) ;
V_174 -> V_734 . V_764 = V_743 [ 4 ] | ( V_743 [ 5 ] << 8 ) ;
V_742 = V_738 -> V_742 ;
if ( V_742 && ( V_742 < 0x1000 ) ) {
V_174 -> V_734 . V_764 |=
V_742 << V_765 ;
V_174 -> V_321 |= V_766 ;
}
return 0 ;
}
static int F_129 ( struct V_242 * V_243 ,
struct V_735 * V_174 ,
struct V_736 * V_628 , int V_767 )
{
int V_41 = 0 ;
if ( V_767 & V_768 ) {
V_174 -> V_734 . V_769 |= ( V_628 -> V_770 &
V_771 ) ;
V_174 -> V_321 |= V_772 ;
}
if ( V_767 & V_773 ) {
V_243 -> V_774 = V_628 -> V_774 ;
V_174 -> V_734 . V_774 = V_628 -> V_774 ;
V_174 -> V_321 |= V_775 ;
}
if ( V_767 & V_776 ) {
V_41 = F_125 ( V_243 , V_174 , V_628 ) ;
if ( V_41 )
return V_41 ;
} else if ( V_243 -> V_702 == V_703 || V_243 -> V_702 == V_707 ) {
V_174 -> V_734 . V_763 = V_243 -> V_9 -> V_117 . V_743 [ 0 ] |
( V_243 -> V_9 -> V_117 . V_743 [ 1 ] << 8 ) |
( V_243 -> V_9 -> V_117 . V_743 [ 2 ] << 16 ) |
( V_243 -> V_9 -> V_117 . V_743 [ 3 ] << 24 ) ;
V_174 -> V_734 . V_764 = V_243 -> V_9 -> V_117 . V_743 [ 4 ] |
( V_243 -> V_9 -> V_117 . V_743 [ 5 ] << 8 ) ;
}
if ( ( V_767 & V_777 ) &&
V_628 -> V_778 ) {
V_174 -> V_734 . V_657 |=
V_779 ;
V_174 -> V_321 |= V_780 ;
}
if ( V_767 & V_781 ) {
V_174 -> V_734 . V_782 |= ( V_628 -> V_783 &
V_784 ) ;
V_174 -> V_321 |= V_780 ;
}
if ( V_767 & V_785 ) {
if ( V_628 -> V_786 < V_787 ||
V_628 -> V_786 > V_788 ) {
V_41 = - V_72 ;
goto V_789;
}
V_174 -> V_734 . V_769 |=
( F_130 ( V_628 -> V_786 ) <<
V_790 ) &
V_791 ;
V_174 -> V_321 |= V_792 ;
}
if ( V_767 & V_793 ) {
V_174 -> V_734 . V_782 |= V_628 -> V_143 <<
V_794 ;
V_174 -> V_321 |= V_795 ;
}
if ( V_767 & V_796 ) {
V_174 -> V_734 . V_750 |= ( V_628 -> V_797 <<
V_798 ) &
V_799 ;
V_174 -> V_321 |= V_800 ;
}
if ( V_767 & V_801 ) {
V_174 -> V_734 . V_750 |= ( V_628 -> V_802 <<
V_803 ) &
V_804 ;
V_174 -> V_321 |= V_805 ;
}
if ( V_767 & V_806 ) {
V_174 -> V_734 . V_782 |= ( V_628 -> V_807 <<
V_808 )
& V_809 ;
V_174 -> V_321 |= V_810 ;
}
if ( V_767 & V_811 ) {
V_174 -> V_734 . V_746 |= ( V_628 -> V_812 & 0x00ffffff ) ;
V_174 -> V_321 |= V_813 ;
}
if ( V_767 & V_814 ) {
V_174 -> V_734 . V_755 |= ( V_628 -> V_815 & 0x00ffffff ) ;
V_174 -> V_321 |= V_816 ;
}
if ( V_767 & V_817 ) {
if ( V_628 -> V_818 > V_243 -> V_9 -> V_347 . V_373 ) {
V_41 = - V_72 ;
goto V_789;
}
V_243 -> V_691 = V_628 -> V_818 ;
V_174 -> V_321 |= V_819 ;
}
if ( V_767 & V_820 ) {
if ( V_628 -> V_821 > V_243 -> V_9 -> V_347 . V_377 ) {
V_41 = - V_72 ;
goto V_789;
}
V_243 -> V_688 = V_628 -> V_821 ;
V_174 -> V_321 |= V_822 ;
}
V_174 -> V_734 . V_689 = ( V_243 -> V_691 <<
V_823 ) |
( V_243 -> V_688 & V_824 ) ;
V_789:
return V_41 ;
}
int F_131 ( struct V_8 * V_9 , struct V_242 * V_243 ,
struct V_736 * V_628 , int V_767 )
{
int V_41 = - V_163 ;
struct V_735 * V_174 ;
V_174 = F_19 ( V_825 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_734 . V_120 = V_243 -> V_120 ;
V_174 -> V_321 = 0 ;
if ( V_767 & V_826 ) {
V_174 -> V_734 . V_657 |=
( F_10 ( V_628 -> V_827 ) <<
V_828 ) &
V_829 ;
V_174 -> V_321 |= V_830 ;
} else {
V_174 -> V_734 . V_657 |=
( V_243 -> V_614 << V_828 ) &
V_829 ;
}
V_41 = F_129 ( V_243 , V_174 , V_628 , V_767 ) ;
if ( V_41 )
goto V_200;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_132 ( struct V_8 * V_9 , struct V_242 * V_243 )
{
int V_41 = - V_163 ;
struct V_831 * V_174 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_832 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_682 = V_243 -> V_120 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_81 ( V_174 ) ;
if ( V_243 -> V_18 . V_4 )
F_23 ( & V_158 -> V_9 , V_243 -> V_18 . V_161 , V_243 -> V_18 . V_4 , V_243 -> V_18 . V_195 ) ;
if ( ! V_243 -> V_286 && V_243 -> V_609 . V_4 )
F_23 ( & V_158 -> V_9 , V_243 -> V_609 . V_161 , V_243 -> V_609 . V_4 , V_243 -> V_609 . V_195 ) ;
if ( V_243 -> V_471 )
V_243 -> V_467 -> V_479 ++ ;
return V_41 ;
}
int F_133 ( struct V_8 * V_9 , struct V_713 * V_286 ,
struct V_833 * V_834 ,
struct V_466 * V_467 )
{
int V_41 = - V_163 ;
int V_523 , V_168 ;
int V_161 ;
struct V_835 * V_188 ;
struct V_836 * V_174 ;
T_4 V_195 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_651 ;
V_174 = F_19 ( V_837 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_838 = V_467 -> V_120 & V_839 ;
V_651 = V_834 -> V_347 . V_840 + 1 ;
V_41 = F_91 ( & V_651 ,
V_9 -> V_347 . V_406 ,
& V_523 , & V_168 ) ;
if ( V_41 ) {
F_53 ( L_18 , V_293 ,
V_834 -> V_347 . V_840 ) ;
V_41 = - V_72 ;
goto V_841;
}
V_161 = V_523 * V_168 ;
V_286 -> V_609 . V_4 = F_25 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_286 -> V_609 . V_4 ) {
V_41 = - V_163 ;
goto V_841;
}
F_26 ( & V_174 -> V_653 [ 0 ] , V_523 , V_195 , V_168 ) ;
V_286 -> V_609 . V_162 = V_9 -> V_347 . V_406 ;
V_286 -> V_609 . V_195 = V_195 ;
V_286 -> V_609 . V_161 = V_161 ;
V_286 -> V_609 . V_633 = V_651 ;
V_174 -> V_842 = F_116 ( V_651 ) ;
V_174 -> V_842 |= V_834 -> V_347 . V_843 <<
V_844 ;
V_174 -> V_838 |= ( F_116 ( V_168 / V_213 )
<< V_845 ) ;
V_174 -> V_846 |= ( V_9 -> V_347 . V_406
<< V_847 )
& V_848 ;
V_174 -> V_846 |= V_523 << V_849 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_835 * ) V_174 ;
V_286 -> V_120 = V_188 -> V_120 ;
V_286 -> V_609 . V_684 = V_188 -> V_120 ;
V_651 = ( ( V_188 -> V_850 &
V_851 ) >>
V_852 ) ;
V_651 = ( 1 << V_651 ) ;
V_286 -> V_609 . V_633 = V_651 ;
V_286 -> V_609 . V_700 = V_651 - 1 ;
V_286 -> V_609 . V_630 = ( V_188 -> V_850 &
V_853 ) >>
V_854 ;
goto V_841;
V_200:
F_23 ( & V_158 -> V_9 , V_286 -> V_609 . V_161 , V_286 -> V_609 . V_4 , V_195 ) ;
V_841:
F_81 ( V_174 ) ;
return V_41 ;
}
int F_134 ( struct V_713 * V_286 , struct V_855 * V_834 )
{
int V_41 = - V_163 ;
struct V_856 * V_174 ;
struct V_466 * V_467 = V_286 -> V_467 ;
struct V_8 * V_9 = F_135 ( V_467 -> V_857 . V_265 ) ;
V_174 = F_19 ( V_858 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_120 ;
V_174 -> V_859 |= V_834 -> V_860 <<
V_861 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
F_81 ( V_174 ) ;
return V_41 ;
}
int F_136 ( struct V_713 * V_286 , struct V_855 * V_834 )
{
int V_41 = - V_163 ;
struct V_862 * V_174 ;
struct V_8 * V_9 = F_135 ( V_286 -> V_287 . V_265 ) ;
V_174 = F_19 ( V_863 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_609 . V_684 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 == 0 ) {
struct V_864 * V_188 =
(struct V_864 * ) V_174 ;
V_834 -> V_843 =
V_188 -> V_865 &
V_866 ;
V_834 -> V_840 =
V_188 -> V_867 >> V_868 ;
V_834 -> V_860 = V_188 -> V_865 >>
V_869 ;
}
F_81 ( V_174 ) ;
return V_41 ;
}
int F_137 ( struct V_8 * V_9 , struct V_713 * V_286 )
{
int V_41 = - V_163 ;
struct V_870 * V_174 ;
struct V_491 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_871 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_286 -> V_120 ;
V_41 = F_74 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_286 -> V_609 . V_4 )
F_23 ( & V_158 -> V_9 , V_286 -> V_609 . V_161 ,
V_286 -> V_609 . V_4 , V_286 -> V_609 . V_195 ) ;
F_81 ( V_174 ) ;
return V_41 ;
}
int F_138 ( struct V_8 * V_9 , struct V_872 * V_873 )
{
int V_169 ;
int V_41 = - V_72 ;
struct V_497 * V_874 ;
unsigned long V_321 ;
V_874 = V_9 -> V_496 . V_4 ;
F_62 ( & V_9 -> V_496 . V_238 , V_321 ) ;
for ( V_169 = 0 ; V_169 < V_9 -> V_496 . V_510 ; V_169 ++ ) {
if ( V_874 -> V_192 == 0 ) {
V_874 -> V_192 = V_875 ;
V_873 -> V_874 = V_874 ;
V_873 -> V_120 = V_169 ;
V_41 = 0 ;
break;
}
V_874 ++ ;
}
if ( V_169 == V_9 -> V_496 . V_510 )
V_41 = - V_51 ;
F_64 ( & V_9 -> V_496 . V_238 , V_321 ) ;
return V_41 ;
}
int F_139 ( struct V_8 * V_9 , struct V_872 * V_873 )
{
unsigned long V_321 ;
F_62 ( & V_9 -> V_496 . V_238 , V_321 ) ;
V_873 -> V_874 -> V_192 = 0 ;
F_64 ( & V_9 -> V_496 . V_238 , V_321 ) ;
return 0 ;
}
static int F_140 ( struct V_8 * V_9 )
{
int V_876 , V_169 , V_41 = 0 ;
int V_201 ;
unsigned long V_321 = 0 ;
V_876 = V_9 -> V_117 . V_204 . V_877 -
V_9 -> V_117 . V_204 . V_878 ;
if ( V_9 -> V_117 . V_202 == V_203 ) {
V_876 = 1 ;
V_321 = V_879 ;
} else {
V_876 = F_115 ( T_1 , V_876 , F_141 () ) ;
}
if ( ! V_876 )
return - V_72 ;
V_9 -> V_207 = F_20 ( sizeof( struct V_1 ) * V_876 , V_145 ) ;
if ( ! V_9 -> V_207 )
return - V_163 ;
for ( V_169 = 0 ; V_169 < V_876 ; V_169 ++ ) {
V_41 = F_32 ( V_9 , & V_9 -> V_207 [ V_169 ] ,
V_7 ) ;
if ( V_41 ) {
V_41 = - V_72 ;
break;
}
sprintf ( V_9 -> V_207 [ V_169 ] . V_880 , L_19 ,
V_9 -> V_120 , V_169 ) ;
V_201 = F_33 ( V_9 , & V_9 -> V_207 [ V_169 ] ) ;
V_41 = F_142 ( V_201 , F_67 , V_321 ,
V_9 -> V_207 [ V_169 ] . V_880 ,
& V_9 -> V_207 [ V_169 ] ) ;
if ( V_41 )
goto V_881;
V_9 -> V_206 += 1 ;
}
return 0 ;
V_881:
F_37 ( V_9 ) ;
return V_41 ;
}
int F_143 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_140 ( V_9 ) ;
if ( V_41 )
goto V_882;
V_41 = F_44 ( V_9 ) ;
if ( V_41 )
goto V_883;
V_41 = F_82 ( V_9 ) ;
if ( V_41 )
goto V_884;
V_41 = F_85 ( V_9 ) ;
if ( V_41 )
goto V_884;
V_41 = F_80 ( V_9 ) ;
if ( V_41 )
goto V_884;
V_41 = F_94 ( V_9 ) ;
if ( V_41 )
goto V_884;
V_41 = F_87 ( V_9 ) ;
if ( V_41 )
goto V_884;
V_41 = F_84 ( V_9 ) ;
if ( V_41 )
goto V_884;
return 0 ;
V_884:
F_47 ( V_9 ) ;
V_883:
F_37 ( V_9 ) ;
V_882:
F_53 ( L_12 , V_293 , V_41 ) ;
return V_41 ;
}
void F_144 ( struct V_8 * V_9 )
{
F_95 ( V_9 ) ;
F_37 ( V_9 ) ;
F_47 ( V_9 ) ;
}
