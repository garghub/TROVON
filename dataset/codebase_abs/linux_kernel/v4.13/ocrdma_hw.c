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
V_174 -> V_228 |= F_42 ( V_231 ) ;
V_174 -> V_232 = V_13 -> V_120 ;
V_174 -> V_232 |= ( F_39 ( V_12 -> V_161 ) <<
V_233 ) ;
V_174 -> V_192 = V_234 ;
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
goto V_235;
V_9 -> V_207 [ 0 ] . V_236 ++ ;
V_41 = F_37 ( V_9 , & V_9 -> V_12 . V_13 , & V_9 -> V_207 [ 0 ] . V_3 ) ;
if ( V_41 )
goto V_237;
memset ( & V_9 -> V_21 , 0 , sizeof( V_9 -> V_21 ) ) ;
F_44 ( & V_9 -> V_21 . V_238 ) ;
F_45 ( & V_9 -> V_21 . V_239 ) ;
V_41 = F_23 ( V_9 , & V_9 -> V_12 . V_18 , V_20 ,
sizeof( struct V_17 ) ) ;
if ( V_41 )
goto V_240;
V_41 = F_41 ( V_9 , & V_9 -> V_12 . V_18 , & V_9 -> V_12 . V_13 ) ;
if ( V_41 )
goto V_241;
F_14 ( V_9 , V_9 -> V_12 . V_13 . V_120 , true , false , 0 ) ;
return 0 ;
V_241:
F_21 ( V_9 , & V_9 -> V_12 . V_18 ) ;
V_240:
F_27 ( V_9 , & V_9 -> V_12 . V_13 , V_178 ) ;
V_237:
F_21 ( V_9 , & V_9 -> V_12 . V_13 ) ;
V_235:
return V_41 ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_157 * V_242 , * V_13 ;
F_47 ( & V_9 -> V_21 . V_239 ) ;
V_242 = & V_9 -> V_12 . V_18 ;
if ( V_242 -> V_185 ) {
F_27 ( V_9 , V_242 , V_176 ) ;
F_21 ( V_9 , V_242 ) ;
}
F_48 ( & V_9 -> V_21 . V_239 ) ;
V_13 = & V_9 -> V_12 . V_13 ;
if ( V_13 -> V_185 ) {
F_27 ( V_9 , V_13 , V_178 ) ;
F_21 ( V_9 , V_13 ) ;
}
}
static void F_49 ( struct V_8 * V_9 ,
struct V_243 * V_244 )
{
enum V_23 V_245 = V_40 ;
enum V_23 V_246 ;
if ( V_244 == NULL )
F_28 () ;
F_50 ( V_244 , V_245 , & V_246 ) ;
}
static void F_51 ( struct V_8 * V_9 ,
struct V_247 * V_11 )
{
struct V_243 * V_244 = NULL ;
struct V_248 * V_13 = NULL ;
struct V_249 V_250 ;
int V_251 = 0 ;
int V_252 = 1 ;
int V_253 = 0 ;
int V_254 = 0 ;
int type = ( V_11 -> V_255 & V_256 ) >>
V_257 ;
T_3 V_258 = V_11 -> V_259 & V_260 ;
T_3 V_261 = V_11 -> V_262 & V_263 ;
if ( V_11 -> V_259 & V_264 ) {
if ( V_258 < V_9 -> V_265 . V_266 )
V_244 = V_9 -> V_267 [ V_258 ] ;
if ( V_244 == NULL ) {
F_52 ( L_5 ,
V_9 -> V_120 , V_258 ) ;
return;
}
}
if ( V_11 -> V_262 & V_268 ) {
if ( V_261 < V_9 -> V_265 . V_269 )
V_13 = V_9 -> V_270 [ V_261 ] ;
if ( V_13 == NULL ) {
F_52 ( L_6 ,
V_9 -> V_120 , V_261 ) ;
return;
}
}
memset ( & V_250 , 0 , sizeof( V_250 ) ) ;
V_250 . V_271 = & V_9 -> V_272 ;
switch ( type ) {
case V_273 :
V_250 . V_274 . V_13 = & V_13 -> V_275 ;
V_250 . V_276 = V_277 ;
V_251 = 1 ;
V_252 = 0 ;
break;
case V_278 :
V_250 . V_274 . V_13 = & V_13 -> V_275 ;
V_250 . V_276 = V_277 ;
V_251 = 1 ;
V_252 = 0 ;
break;
case V_279 :
V_250 . V_274 . V_244 = & V_244 -> V_280 ;
V_250 . V_276 = V_281 ;
F_49 ( V_9 , V_244 ) ;
break;
case V_282 :
V_250 . V_274 . V_244 = & V_244 -> V_280 ;
V_250 . V_276 = V_283 ;
break;
case V_284 :
V_250 . V_274 . V_244 = & V_244 -> V_280 ;
V_250 . V_276 = V_285 ;
break;
case V_286 :
V_250 . V_274 . V_244 = & V_244 -> V_280 ;
V_250 . V_276 = V_287 ;
break;
case V_288 :
V_250 . V_274 . V_289 = 1 ;
V_250 . V_276 = V_290 ;
V_252 = 0 ;
V_254 = 1 ;
break;
case V_291 :
V_250 . V_274 . V_292 = & V_244 -> V_292 -> V_293 ;
V_250 . V_276 = V_294 ;
V_253 = 1 ;
V_252 = 0 ;
break;
case V_295 :
V_250 . V_274 . V_292 = & V_244 -> V_292 -> V_293 ;
V_250 . V_276 = V_296 ;
V_253 = 1 ;
V_252 = 0 ;
break;
case V_297 :
V_250 . V_274 . V_244 = & V_244 -> V_280 ;
V_250 . V_276 = V_298 ;
break;
default:
V_251 = 0 ;
V_252 = 0 ;
V_253 = 0 ;
V_254 = 0 ;
F_52 ( L_7 , V_299 , type ) ;
break;
}
if ( type < V_300 )
F_53 ( & V_9 -> V_301 [ type ] ) ;
if ( V_252 ) {
if ( V_244 -> V_280 . V_302 )
V_244 -> V_280 . V_302 ( & V_250 , V_244 -> V_280 . V_303 ) ;
} else if ( V_251 ) {
if ( V_13 -> V_275 . V_302 )
V_13 -> V_275 . V_302 ( & V_250 , V_13 -> V_275 . V_304 ) ;
} else if ( V_253 ) {
if ( V_244 -> V_292 -> V_293 . V_302 )
V_244 -> V_292 -> V_293 . V_302 ( & V_250 ,
V_244 -> V_292 -> V_293 .
V_305 ) ;
} else if ( V_254 ) {
F_52 ( L_8 , V_9 -> V_272 . V_306 ) ;
F_54 ( & V_250 ) ;
}
}
static void F_55 ( struct V_8 * V_9 ,
struct V_247 * V_11 )
{
struct V_307 * V_308 ;
int type = ( V_11 -> V_255 & V_256 ) >>
V_257 ;
switch ( type ) {
case V_309 :
V_308 = (struct V_307 * ) V_11 ;
if ( ( V_308 -> V_310 & V_311 ) >>
V_312 )
V_9 -> V_313 = ( ( V_308 -> V_310 &
V_314 ) >>
V_315 ) ;
break;
case V_316 :
F_56 ( & V_9 -> V_317 , 1 ) ;
break;
default:
break;
}
}
static void F_57 ( struct V_8 * V_9 ,
struct V_247 * V_11 )
{
struct V_318 * V_308 ;
T_2 V_319 ;
V_308 = (struct V_318 * ) V_11 ;
V_319 = F_58 ( V_308 -> V_320 ) ;
if ( ! ( V_319 & V_321 ) )
return;
if ( V_9 -> V_322 & V_323 )
F_59 ( V_9 , ( V_319 & V_324 ) ) ;
}
static void F_60 ( struct V_8 * V_9 , void * V_325 )
{
struct V_247 * V_11 = V_325 ;
T_1 V_326 = ( V_11 -> V_255 & V_327 ) >>
V_328 ;
switch ( V_326 ) {
case V_231 :
F_57 ( V_9 , V_11 ) ;
break;
case V_230 :
F_51 ( V_9 , V_11 ) ;
break;
case V_229 :
F_55 ( V_9 , V_11 ) ;
break;
default:
F_52 ( L_9 , V_299 ,
V_9 -> V_120 , V_326 ) ;
}
}
static void F_61 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
if ( V_9 -> V_21 . V_22 == V_11 -> V_329 && V_9 -> V_21 . V_330 == false ) {
V_9 -> V_21 . V_99 = ( V_11 -> V_41 &
V_331 ) >> V_332 ;
V_9 -> V_21 . V_333 =
( V_11 -> V_41 & V_334 )
>> V_335 ;
V_9 -> V_21 . V_330 = true ;
F_62 ( & V_9 -> V_21 . V_238 ) ;
} else
F_52 ( L_10 ,
V_299 , V_11 -> V_329 , V_9 -> V_21 . V_22 ) ;
}
static int F_63 ( struct V_8 * V_9 , T_3 V_106 )
{
T_3 V_109 = 0 ;
struct V_10 * V_11 ;
while ( 1 ) {
V_11 = F_3 ( V_9 ) ;
if ( V_11 == NULL )
break;
F_64 ( V_11 , sizeof( * V_11 ) ) ;
V_109 += 1 ;
if ( V_11 -> V_14 & V_336 )
F_60 ( V_9 , V_11 ) ;
else if ( V_11 -> V_14 & V_337 )
F_61 ( V_9 , V_11 ) ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
F_5 ( V_9 ) ;
}
F_14 ( V_9 , V_9 -> V_12 . V_13 . V_120 , true , false , V_109 ) ;
return 0 ;
}
static struct V_248 * F_65 ( struct V_8 * V_9 ,
struct V_248 * V_13 , bool V_18 )
{
struct V_243 * V_244 ;
struct V_338 * V_339 ;
struct V_248 * V_340 = NULL ;
struct V_338 * V_19 = V_18 ? ( & V_13 -> V_341 ) : ( & V_13 -> V_342 ) ;
F_66 (cur, head) {
if ( V_18 )
V_244 = F_67 ( V_339 , struct V_243 , V_343 ) ;
else
V_244 = F_67 ( V_339 , struct V_243 , V_344 ) ;
if ( V_244 -> V_292 )
continue;
if ( V_244 -> V_345 == V_244 -> V_346 )
continue;
if ( V_244 -> V_345 == V_13 )
V_340 = V_244 -> V_346 ;
else
V_340 = V_244 -> V_345 ;
return V_340 ;
}
return NULL ;
}
static void F_68 ( struct V_8 * V_9 ,
struct V_248 * V_13 )
{
unsigned long V_322 ;
struct V_248 * V_340 = NULL ;
F_69 ( & V_9 -> V_347 , V_322 ) ;
V_340 = F_65 ( V_9 , V_13 , true ) ;
if ( V_340 == NULL )
V_340 = F_65 ( V_9 , V_13 , false ) ;
F_70 ( & V_9 -> V_347 , V_322 ) ;
if ( V_340 && V_340 -> V_275 . V_348 ) {
F_69 ( & V_340 -> V_349 , V_322 ) ;
(* V_340 -> V_275 . V_348 ) ( & V_340 -> V_275 , V_340 -> V_275 . V_304 ) ;
F_70 ( & V_340 -> V_349 , V_322 ) ;
}
}
static void F_71 ( struct V_8 * V_9 , T_3 V_350 )
{
unsigned long V_322 ;
struct V_248 * V_13 ;
if ( V_350 >= V_351 )
F_28 () ;
V_13 = V_9 -> V_270 [ V_350 ] ;
if ( V_13 == NULL )
return;
if ( V_13 -> V_275 . V_348 ) {
F_69 ( & V_13 -> V_349 , V_322 ) ;
(* V_13 -> V_275 . V_348 ) ( & V_13 -> V_275 , V_13 -> V_275 . V_304 ) ;
F_70 ( & V_13 -> V_349 , V_322 ) ;
}
F_68 ( V_9 , V_13 ) ;
}
static void F_72 ( struct V_8 * V_9 , T_3 V_106 )
{
if ( V_106 == V_9 -> V_12 . V_13 . V_120 )
F_63 ( V_9 , V_106 ) ;
else
F_71 ( V_9 , V_106 ) ;
}
static T_5 F_73 ( int V_201 , void * V_352 )
{
struct V_1 * V_2 = V_352 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 V_353 ;
struct V_6 * V_354 ;
T_3 V_106 ;
T_2 V_355 ;
int V_356 = V_2 -> V_236 ;
do {
V_354 = F_1 ( V_2 ) ;
V_353 = * V_354 ;
F_64 ( & V_353 , sizeof( V_353 ) ) ;
V_355 = ( V_353 . V_357 & V_358 )
>> V_359 ;
if ( V_355 == V_360 )
F_52 ( L_11 ,
V_2 -> V_3 . V_120 , V_353 . V_357 ) ;
if ( ( V_353 . V_357 & V_361 ) == 0 )
break;
V_354 -> V_357 = 0 ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , false , true , 1 ) ;
if ( ( V_353 . V_357 & V_362 ) == 0 ) {
V_106 = V_353 . V_357 >> V_363 ;
F_72 ( V_9 , V_106 ) ;
}
F_2 ( V_2 ) ;
if ( V_356 )
V_356 -- ;
} while ( V_356 );
V_2 -> V_364 . V_365 ++ ;
F_17 ( V_9 , V_2 -> V_3 . V_120 , true , true , 0 ) ;
return V_366 ;
}
static void F_74 ( struct V_8 * V_9 , struct V_17 * V_174 )
{
struct V_17 * V_144 ;
V_9 -> V_21 . V_22 = V_9 -> V_12 . V_18 . V_19 ;
V_9 -> V_21 . V_330 = false ;
V_144 = F_6 ( V_9 ) ;
V_174 -> V_146 . V_329 = V_9 -> V_12 . V_18 . V_19 ;
F_75 ( V_144 , V_174 , sizeof( * V_144 ) ) ;
F_76 () ;
F_7 ( V_9 ) ;
F_16 ( V_9 ) ;
}
static int F_77 ( struct V_8 * V_9 )
{
long V_41 ;
V_41 = F_78 ( V_9 -> V_21 . V_238 ,
( V_9 -> V_21 . V_330 != false ) ,
F_79 ( 30000 ) ) ;
if ( V_41 )
return 0 ;
else {
V_9 -> V_21 . V_367 = true ;
F_52 ( L_12 ,
V_299 , V_9 -> V_120 ) ;
return - 1 ;
}
}
static int F_80 ( struct V_8 * V_9 , struct V_17 * V_144 )
{
int V_41 = 0 ;
T_3 V_99 , V_333 ;
struct V_17 * V_368 ;
struct V_369 * V_188 = NULL ;
F_47 ( & V_9 -> V_21 . V_239 ) ;
if ( V_9 -> V_21 . V_367 )
goto V_200;
F_74 ( V_9 , V_144 ) ;
V_41 = F_77 ( V_9 ) ;
if ( V_41 )
goto V_200;
V_99 = V_9 -> V_21 . V_99 ;
V_333 = V_9 -> V_21 . V_333 ;
V_368 = F_8 ( V_9 ) ;
F_81 ( V_144 , V_368 , ( sizeof( * V_144 ) ) ) ;
if ( ( V_144 -> V_146 . V_147 & V_150 ) >>
V_149 )
V_188 = & V_144 -> V_153 . V_188 ;
if ( V_99 || V_333 ) {
F_52 ( L_13 ,
V_299 , V_99 , V_333 ) ;
if ( V_188 ) {
F_52 ( L_14 ,
( V_188 -> V_141 & V_370 ) >>
V_371 ,
( V_188 -> V_141 & V_372 ) >>
V_373 ) ;
}
V_41 = F_13 ( V_99 ) ;
goto V_200;
}
if ( V_188 && ( V_144 -> V_153 . V_188 . V_41 & V_44 ) )
V_41 = F_11 ( V_144 -> V_153 . V_188 . V_41 ) ;
V_200:
F_48 ( & V_9 -> V_21 . V_239 ) ;
return V_41 ;
}
static int F_82 ( struct V_8 * V_9 , struct V_17 * V_144 ,
void * V_374 )
{
int V_41 ;
struct V_369 * V_188 = V_374 ;
if ( ( V_144 -> V_146 . V_147 & V_150 ) >>
V_149 )
F_28 () ;
V_41 = F_80 ( V_9 , V_144 ) ;
if ( ! V_41 )
if ( V_188 -> V_41 & V_44 )
V_41 = F_11 ( V_188 -> V_41 ) ;
if ( V_41 )
F_52 ( L_14 ,
( V_188 -> V_141 & V_370 ) >>
V_371 ,
( V_188 -> V_141 & V_372 ) >>
V_373 ) ;
return V_41 ;
}
static void F_83 ( struct V_8 * V_9 ,
struct V_375 * V_265 ,
struct V_376 * V_188 )
{
V_265 -> V_377 =
( V_188 -> V_378 & V_379 ) >>
V_380 ;
V_265 -> V_381 = ( V_188 -> V_378 &
V_382 ) >>
V_383 ;
V_265 -> V_384 =
( V_188 -> V_385 & V_386 ) >>
V_387 ;
V_265 -> V_266 =
( V_188 -> V_388 & V_389 ) >>
V_390 ;
V_265 -> V_391 =
( V_188 -> V_392 & V_393 ) >>
V_394 ;
V_265 -> V_395 = ( ( V_188 -> V_396 &
V_397 ) >>
V_398 ) ;
V_265 -> V_399 = ( V_188 -> V_396 &
V_400 ) >>
V_401 ;
V_265 -> V_402 = ( V_188 -> V_403 &
V_404 ) >>
V_405 ;
V_265 -> V_406 = ( V_188 -> V_407 &
V_408 ) >>
V_409 ;
V_265 -> V_410 = ( V_188 -> V_411 &
V_412 ) >>
V_413 ;
V_265 -> V_414 = ( V_188 -> V_411 &
V_415 ) >>
V_416 ;
V_265 -> V_417 = ( V_188 -> V_388 &
V_418 ) >>
V_419 ;
V_265 -> V_420 = ( V_188 -> V_388 &
V_421 ) >>
V_422 ;
V_265 -> V_423 = ( V_188 -> V_378 &
V_424 ) >>
V_425 ;
V_265 -> V_426 = V_188 -> V_426 ;
V_265 -> V_427 = V_188 -> V_427 ;
V_265 -> V_428 = ( ( V_429 ) V_188 -> V_430 << 32 ) |
V_188 -> V_431 ;
V_265 -> V_432 = 0 ;
V_265 -> V_433 = V_188 -> V_433 ;
V_265 -> V_434 = V_188 -> V_434 ;
V_265 -> V_435 = V_188 -> V_436 &
V_437 ;
V_265 -> V_269 = ( V_188 -> V_436 &
V_438 ) >>
V_439 ;
V_265 -> V_440 = ( ( V_188 -> V_441 &
V_442 ) >>
V_443 ) *
V_444 ;
V_265 -> V_445 = ( ( V_188 -> V_441 &
V_446 ) >>
V_447 ) *
V_444 ;
V_265 -> V_448 =
V_265 -> V_440 - ( sizeof( struct V_449 ) +
sizeof( struct V_450 ) ) ;
if ( F_84 ( V_9 ) == V_451 ) {
V_265 -> V_452 = 1 ;
V_265 -> V_453 = V_213 ;
V_265 -> V_454 = V_455 ;
}
V_9 -> V_265 . V_456 = V_188 -> V_457 >>
V_458 ;
V_9 -> V_265 . V_459 = V_188 -> V_457 &
V_460 ;
}
static int F_85 ( struct V_8 * V_9 ,
struct V_461 * V_462 )
{
T_1 V_463 ;
V_463 = V_462 -> V_463 & V_464 ;
if ( V_463 != V_464 )
return - V_72 ;
V_9 -> V_465 = V_462 -> V_465 ;
V_9 -> V_466 = V_462 -> V_466 ;
return 0 ;
}
static int F_86 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_467 * V_188 ;
V_174 = F_19 ( V_468 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_468 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_467 * ) V_174 ;
memset ( & V_9 -> V_265 . V_469 [ 0 ] , 0 , sizeof( V_9 -> V_265 . V_469 ) ) ;
memcpy ( & V_9 -> V_265 . V_469 [ 0 ] , & V_188 -> V_470 [ 0 ] ,
sizeof( V_188 -> V_470 ) ) ;
F_64 ( V_9 -> V_265 . V_469 , sizeof( V_188 -> V_470 ) ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_88 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_461 * V_188 ;
V_174 = F_19 ( V_471 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_471 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_461 * ) V_174 ;
V_41 = F_85 ( V_9 , V_188 ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_89 ( struct V_8 * V_9 , bool V_472 )
{
struct V_473 * V_182 = V_9 -> V_474 . V_4 ;
struct V_17 * V_144 = & V_9 -> V_474 . V_144 ;
struct V_475 * V_476 ;
int V_41 ;
V_476 = F_90 ( sizeof( * V_476 ) , V_145 ) ;
if ( V_476 == NULL )
return - V_163 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> V_146 . V_151 = V_9 -> V_474 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_477 ) &
V_478 ;
V_144 -> V_153 . V_479 . V_480 [ 0 ] . V_481 = ( T_1 ) ( V_9 -> V_474 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_479 . V_480 [ 0 ] . V_482 = ( T_1 ) F_26 ( V_9 -> V_474 . V_195 ) ;
V_144 -> V_153 . V_479 . V_480 [ 0 ] . V_161 = V_9 -> V_474 . V_159 ;
memcpy ( V_476 , V_182 , sizeof( struct V_475 ) ) ;
memset ( V_182 , 0 , V_9 -> V_474 . V_159 ) ;
F_18 ( (struct V_136 * ) V_182 ,
V_483 ,
V_156 ,
V_9 -> V_474 . V_159 ) ;
if ( V_472 )
V_182 -> V_484 = V_472 ;
V_41 = F_82 ( V_9 , V_144 , V_9 -> V_474 . V_4 ) ;
if ( V_41 )
memcpy ( V_182 , V_476 , sizeof( struct V_475 ) ) ;
else
F_64 ( V_182 , V_9 -> V_474 . V_159 ) ;
F_87 ( V_476 ) ;
return V_41 ;
}
static int F_91 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_485 V_160 ;
struct V_17 * V_144 ;
struct V_486 * V_487 ;
struct V_488 * V_489 ;
V_144 = F_20 ( sizeof( struct V_17 ) , V_145 ) ;
if ( ! V_144 )
return V_41 ;
V_160 . V_159 = sizeof( struct V_486 ) ;
V_160 . V_4 = F_24 ( & V_9 -> V_117 . V_158 -> V_9 ,
V_160 . V_159 , & V_160 . V_195 , V_145 ) ;
if ( ! V_160 . V_4 )
goto V_490;
V_144 -> V_146 . V_151 = V_160 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_477 ) &
V_478 ;
V_144 -> V_153 . V_479 . V_480 [ 0 ] . V_481 = ( T_1 ) ( V_160 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_479 . V_480 [ 0 ] . V_482 = ( T_1 ) F_26 ( V_160 . V_195 ) ;
V_144 -> V_153 . V_479 . V_480 [ 0 ] . V_161 = V_160 . V_159 ;
memset ( V_160 . V_4 , 0 , V_160 . V_159 ) ;
F_18 ( (struct V_136 * ) V_160 . V_4 ,
V_491 ,
V_183 ,
V_160 . V_159 ) ;
V_41 = F_82 ( V_9 , V_144 , V_160 . V_4 ) ;
if ( ! V_41 ) {
V_487 = (struct V_486 * ) V_160 . V_4 ;
V_489 = & V_487 -> V_492 . V_489 ;
V_9 -> V_493 = ( V_489 -> V_494 &
V_495 )
>> V_496 ;
strncpy ( V_9 -> V_497 ,
V_489 -> V_498 , 31 ) ;
}
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_160 . V_159 , V_160 . V_4 , V_160 . V_195 ) ;
V_490:
F_87 ( V_144 ) ;
return V_41 ;
}
static int F_92 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_376 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_499 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_376 * ) V_174 ;
F_83 ( V_9 , & V_9 -> V_265 , V_188 ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_93 ( struct V_8 * V_9 , T_2 * V_500 ,
T_2 * V_501 )
{
int V_41 = - V_163 ;
struct V_502 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_503 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_503 ,
V_183 , sizeof( * V_174 ) ) ;
( (struct V_136 * ) V_174 -> V_153 . V_174 ) -> V_190 = 0x1 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_502 * ) V_174 ;
if ( V_500 )
* V_500 = ( V_188 -> V_504 & V_505 )
>> V_506 ;
if ( V_501 )
* V_501 = ( V_188 -> V_507 & V_324 ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_94 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_508 * V_188 ;
V_174 = F_19 ( V_509 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_509 , V_183 ,
sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_508 * ) V_174 ;
V_9 -> V_93 . V_510 =
( V_188 -> V_511 & V_512 ) ;
V_9 -> V_93 . V_513 =
( V_188 -> V_511 & V_514 )
>> V_515 ;
V_9 -> V_93 . V_95 =
( V_188 -> V_516 & V_517 ) ;
V_9 -> V_93 . V_94 =
( V_188 -> V_516 & V_518 )
>> V_519 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_95 ( struct V_8 * V_9 , struct V_520 * V_521 )
{
int V_41 = - V_163 ;
struct V_522 * V_174 ;
struct V_523 * V_188 ;
V_174 = F_19 ( V_524 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
if ( V_521 -> V_525 )
V_174 -> V_526 |= V_527 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_523 * ) V_174 ;
V_521 -> V_120 = V_188 -> V_528 & V_529 ;
if ( V_188 -> V_528 & V_530 ) {
V_521 -> V_525 = true ;
V_521 -> V_531 = V_188 -> V_528 >>
V_532 ;
} else {
V_521 -> V_525 = false ;
V_521 -> V_533 = 0 ;
}
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_96 ( struct V_8 * V_9 , struct V_520 * V_521 )
{
int V_41 = - V_163 ;
struct V_534 * V_174 ;
V_174 = F_19 ( V_535 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_521 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_97 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
T_6 V_536 ;
struct V_537 * V_174 ;
struct V_538 * V_188 ;
if ( V_9 -> V_265 . V_384 ) {
V_174 = F_19 ( V_539 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_540 = V_9 -> V_265 . V_384 ;
V_174 -> V_526 |= V_527 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
V_188 = (struct V_538 * ) V_174 ;
if ( ! V_41 && ( V_188 -> V_528 & V_530 ) &&
V_188 -> V_540 ) {
V_9 -> V_541 -> V_542 = V_188 -> V_528 >>
V_532 ;
V_9 -> V_541 -> V_543 = V_188 -> V_528 &
V_544 ;
V_9 -> V_541 -> V_545 = V_188 -> V_540 ;
V_536 =
F_98 ( V_188 -> V_540 ) * sizeof( long ) ;
V_9 -> V_541 -> V_546 = F_20 ( V_536 ,
V_145 ) ;
}
F_87 ( V_174 ) ;
}
V_174 = F_19 ( V_539 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_540 = V_9 -> V_265 . V_377 - V_9 -> V_265 . V_384 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
V_188 = (struct V_538 * ) V_174 ;
if ( ! V_41 && V_188 -> V_540 ) {
V_9 -> V_541 -> V_547 = V_188 -> V_528 &
V_544 ;
V_9 -> V_541 -> V_548 = V_188 -> V_540 ;
V_536 = F_98 ( V_188 -> V_540 ) * sizeof( long ) ;
V_9 -> V_541 -> V_549 = F_20 ( V_536 ,
V_145 ) ;
}
F_87 ( V_174 ) ;
if ( V_9 -> V_541 -> V_549 || V_9 -> V_541 -> V_546 ) {
V_9 -> V_541 -> V_550 = true ;
return 0 ;
}
return V_41 ;
}
static void F_99 ( struct V_8 * V_9 )
{
struct V_551 * V_174 ;
V_174 = F_19 ( V_552 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
if ( V_9 -> V_541 -> V_548 ) {
V_174 -> V_553 = V_9 -> V_541 -> V_547 ;
V_174 -> V_540 = V_9 -> V_541 -> V_548 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
}
if ( V_9 -> V_541 -> V_545 ) {
F_87 ( V_174 ) ;
V_174 = F_19 ( V_552 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
V_174 -> V_553 = V_9 -> V_541 -> V_543 ;
V_174 -> V_540 = V_9 -> V_541 -> V_545 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
}
V_200:
F_87 ( V_174 ) ;
}
void F_100 ( struct V_8 * V_9 )
{
int V_41 ;
V_9 -> V_541 = F_20 ( sizeof( struct V_554 ) ,
V_145 ) ;
if ( ! V_9 -> V_541 )
return;
V_41 = F_97 ( V_9 ) ;
if ( V_41 ) {
F_52 ( L_15 ,
V_299 , V_9 -> V_120 ) ;
}
}
static void F_101 ( struct V_8 * V_9 )
{
F_99 ( V_9 ) ;
F_87 ( V_9 -> V_541 -> V_549 ) ;
F_87 ( V_9 -> V_541 -> V_546 ) ;
F_87 ( V_9 -> V_541 ) ;
}
static int F_102 ( T_1 * V_555 , int V_162 ,
int * V_191 , int * V_556 )
{
int V_169 ;
int V_557 ;
* V_555 = F_103 ( * V_555 ) ;
V_557 = * V_555 * V_162 ;
for ( V_169 = 0 ; V_169 < V_558 ; V_169 ++ ) {
if ( V_557 <= ( V_559 << V_169 ) )
break;
}
if ( V_169 >= V_558 )
return - V_72 ;
V_557 = F_104 ( V_557 ,
( ( V_559 << V_169 ) / V_560 ) ) ;
* V_191 =
V_557 / ( ( V_559 << V_169 ) / V_560 ) ;
* V_556 = ( ( V_559 << V_169 ) / V_560 ) ;
* V_555 = V_557 / V_162 ;
return 0 ;
}
static int F_105 ( struct V_8 * V_9 )
{
int V_169 ;
int V_41 = - V_163 ;
int V_561 ;
struct V_562 * V_174 ;
struct V_563 * V_188 ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 ;
struct V_565 * V_566 ;
V_174 = F_19 ( V_567 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_561 = V_568 ;
V_9 -> V_569 . V_159 = sizeof( struct V_570 ) * V_561 ;
V_174 -> V_571 = ( V_572 <<
V_573 ) &
V_574 ;
for ( V_169 = 0 ; V_169 < V_558 ; V_169 ++ ) {
if ( V_575 == ( V_213 << V_169 ) )
break;
}
V_174 -> V_571 |= ( V_169 << V_576 ) &
V_577 ;
V_174 -> V_571 |= ( sizeof( struct V_570 ) <<
V_578 ) &
V_579 ;
V_9 -> V_569 . V_580 . V_4 = F_24 ( & V_158 -> V_9 , V_575 ,
& V_9 -> V_569 . V_580 . V_195 ,
V_145 ) ;
if ( V_9 -> V_569 . V_580 . V_4 == NULL )
goto V_581;
V_9 -> V_569 . V_4 = F_24 ( & V_158 -> V_9 , V_9 -> V_569 . V_159 ,
& V_195 , V_145 ) ;
if ( V_9 -> V_569 . V_4 == NULL )
goto V_582;
V_9 -> V_569 . V_195 = V_195 ;
V_9 -> V_569 . V_583 = V_561 ;
memset ( V_9 -> V_569 . V_4 , 0 , V_9 -> V_569 . V_159 ) ;
V_566 = (struct V_565 * ) V_9 -> V_569 . V_580 . V_4 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_569 . V_159 / V_213 ; V_169 ++ ) {
V_566 [ V_169 ] . V_481 = ( T_1 ) F_106 ( V_195 & 0xffffffff ) ;
V_566 [ V_169 ] . V_482 = ( T_1 ) F_106 ( F_26 ( V_195 ) ) ;
V_195 += V_575 ;
}
V_174 -> V_584 [ 0 ] . V_170 = ( T_1 ) ( V_9 -> V_569 . V_580 . V_195 & 0xFFFFFFFF ) ;
V_174 -> V_584 [ 0 ] . V_171 = ( T_1 ) F_26 ( V_9 -> V_569 . V_580 . V_195 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_563 * ) V_174 ;
V_9 -> V_569 . V_585 = V_188 -> V_585 & 0xFFFF ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
F_22 ( & V_158 -> V_9 , V_9 -> V_569 . V_159 , V_9 -> V_569 . V_4 ,
V_9 -> V_569 . V_195 ) ;
V_9 -> V_569 . V_4 = NULL ;
V_582:
F_22 ( & V_158 -> V_9 , V_575 , V_9 -> V_569 . V_580 . V_4 ,
V_9 -> V_569 . V_580 . V_195 ) ;
V_9 -> V_569 . V_580 . V_4 = NULL ;
V_9 -> V_569 . V_159 = 0 ;
V_581:
F_87 ( V_174 ) ;
return V_41 ;
}
static void F_107 ( struct V_8 * V_9 )
{
struct V_586 * V_174 ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
if ( V_9 -> V_569 . V_4 == NULL )
return;
V_174 = F_19 ( V_587 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return;
V_174 -> V_585 = V_9 -> V_569 . V_585 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_22 ( & V_158 -> V_9 , V_9 -> V_569 . V_159 , V_9 -> V_569 . V_4 ,
V_9 -> V_569 . V_195 ) ;
V_9 -> V_569 . V_4 = NULL ;
F_22 ( & V_158 -> V_9 , V_575 , V_9 -> V_569 . V_580 . V_4 ,
V_9 -> V_569 . V_580 . V_195 ) ;
F_87 ( V_174 ) ;
}
static T_3 F_108 ( struct V_8 * V_9 )
{
int V_169 , V_588 = 0 , V_236 = 0 ;
T_3 V_124 ;
F_47 ( & V_9 -> V_589 ) ;
V_236 = V_9 -> V_207 [ 0 ] . V_236 ;
V_124 = V_9 -> V_207 [ 0 ] . V_3 . V_120 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
if ( V_9 -> V_207 [ V_169 ] . V_236 < V_236 ) {
V_236 = V_9 -> V_207 [ V_169 ] . V_236 ;
V_124 = V_9 -> V_207 [ V_169 ] . V_3 . V_120 ;
V_588 = V_169 ;
}
}
V_9 -> V_207 [ V_588 ] . V_236 += 1 ;
F_48 ( & V_9 -> V_589 ) ;
return V_124 ;
}
static void F_109 ( struct V_8 * V_9 , T_3 V_124 )
{
int V_169 ;
F_47 ( & V_9 -> V_589 ) ;
V_169 = F_110 ( V_9 , V_124 ) ;
if ( V_169 == - V_72 )
F_28 () ;
V_9 -> V_207 [ V_169 ] . V_236 -= 1 ;
F_48 ( & V_9 -> V_589 ) ;
}
int F_111 ( struct V_8 * V_9 , struct V_248 * V_13 ,
int V_590 , int V_591 , T_3 V_592 )
{
int V_41 = - V_163 ; int V_593 ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
struct V_594 * V_174 ;
struct V_595 * V_188 ;
T_1 V_596 , V_597 , V_556 , V_598 ;
if ( V_590 > V_9 -> V_265 . V_435 ) {
F_52 ( L_16 ,
V_299 , V_9 -> V_120 , V_9 -> V_265 . V_435 , V_590 ) ;
return - V_72 ;
}
if ( V_591 && ( F_84 ( V_9 ) != V_451 ) )
return - V_72 ;
if ( V_591 ) {
V_13 -> V_593 = 1 ;
V_593 = 1 ;
V_597 = V_599 ;
V_596 = 1 ;
} else {
V_13 -> V_593 = V_9 -> V_265 . V_435 ;
V_593 = V_9 -> V_265 . V_435 ;
V_597 = sizeof( struct V_600 ) ;
V_596 = V_601 ;
}
V_13 -> V_161 = F_104 ( V_593 * V_597 , V_213 ) ;
V_174 = F_19 ( V_210 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( & V_174 -> V_174 . V_182 , V_210 ,
V_183 , sizeof( * V_174 ) ) ;
V_13 -> V_4 = F_24 ( & V_158 -> V_9 , V_13 -> V_161 , & V_13 -> V_195 , V_145 ) ;
if ( ! V_13 -> V_4 ) {
V_41 = - V_163 ;
goto V_581;
}
memset ( V_13 -> V_4 , 0 , V_13 -> V_161 ) ;
V_556 = V_13 -> V_161 / V_596 ;
V_174 -> V_174 . V_212 = ( V_556 / V_213 ) <<
V_214 ;
V_174 -> V_174 . V_212 |= V_596 ;
V_174 -> V_174 . V_215 = V_216 ;
V_13 -> V_217 = F_108 ( V_9 ) ;
V_174 -> V_174 . V_182 . V_190 = V_602 ;
V_598 = V_13 -> V_161 / V_597 ;
V_13 -> V_603 = V_598 ;
if ( V_598 > 1024 ) {
V_174 -> V_174 . V_215 |= ( 0x3 << V_604 ) ;
} else {
T_2 V_605 = 0 ;
switch ( V_598 ) {
case 256 :
V_605 = 0 ;
break;
case 512 :
V_605 = 1 ;
break;
case 1024 :
V_605 = 2 ;
break;
default:
goto V_200;
}
V_174 -> V_174 . V_215 |= ( V_605 << V_604 ) ;
}
V_174 -> V_174 . V_217 = V_13 -> V_217 ;
if ( F_84 ( V_9 ) == V_451 ) {
if ( V_591 )
V_174 -> V_174 . V_212 |= V_606 <<
V_607 ;
V_13 -> V_608 = false ;
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_597 ) ;
} else {
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_597 ) - 1 ;
V_174 -> V_174 . V_215 |= V_609 ;
V_13 -> V_608 = true ;
}
V_174 -> V_174 . V_218 |= ( V_592 <<
V_610 ) ;
F_25 ( & V_174 -> V_174 . V_195 [ 0 ] , V_596 , V_13 -> V_195 , V_556 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_595 * ) V_174 ;
V_13 -> V_120 = ( T_3 ) ( V_188 -> V_188 . V_106 & V_219 ) ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
F_109 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
V_581:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_112 ( struct V_8 * V_9 , struct V_248 * V_13 )
{
int V_41 = - V_163 ;
struct V_611 * V_174 ;
V_174 = F_19 ( V_179 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_182 , V_179 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_612 |=
( V_13 -> V_120 << V_613 ) &
V_614 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_109 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_113 ( struct V_8 * V_9 , struct V_615 * V_616 ,
T_1 V_617 , int V_618 )
{
int V_41 = - V_163 ;
struct V_619 * V_174 ;
struct V_620 * V_188 ;
V_174 = F_19 ( V_621 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_617 = V_617 ;
V_174 -> V_622 |= V_618 ;
V_174 -> V_622 |= ( V_616 -> V_623 << V_624 ) ;
V_174 -> V_622 |=
( V_616 -> V_625 << V_626 ) ;
V_174 -> V_622 |=
( V_616 -> V_627 << V_628 ) ;
V_174 -> V_622 |=
( V_616 -> V_629 << V_630 ) ;
V_174 -> V_622 |=
( V_616 -> V_631 << V_632 ) ;
V_174 -> V_622 |=
( V_616 -> V_633 << V_634 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_620 * ) V_174 ;
V_616 -> V_635 = V_188 -> V_636 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_114 ( struct V_8 * V_9 , int V_623 , T_1 V_635 )
{
int V_41 = - V_163 ;
struct V_637 * V_174 ;
V_174 = F_19 ( V_638 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_635 = V_635 ;
V_174 -> V_639 = V_623 ? 1 : 0 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_115 ( struct V_8 * V_9 , struct V_615 * V_616 ,
T_1 V_617 , T_1 V_640 , T_1 V_641 , T_1 V_642 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_643 * V_174 ;
struct V_644 * V_188 ;
V_174 = F_19 ( V_645 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_646 =
V_617 | ( V_616 -> V_633 << V_647 ) ;
V_174 -> V_623 = V_616 -> V_623 ;
V_174 -> V_648 |= ( V_616 -> V_625 <<
V_649 ) ;
V_174 -> V_648 |= ( V_616 -> V_627 <<
V_650 ) ;
V_174 -> V_648 |= ( V_616 -> V_629 <<
V_651 ) ;
V_174 -> V_648 |= ( V_616 -> V_631 <<
V_652 ) ;
V_174 -> V_648 |= ( V_616 -> V_653 <<
V_654 ) ;
V_174 -> V_648 |= ( V_642 << V_655 ) ;
V_174 -> V_648 |= ( V_616 -> V_641 / V_656 ) ;
V_174 -> V_648 |= ( V_616 -> V_657 / V_656 ) <<
V_658 ;
V_174 -> V_659 = V_616 -> V_161 ;
V_174 -> V_660 = F_26 ( V_616 -> V_161 ) ;
V_174 -> V_661 = ( T_1 ) ( V_616 -> V_662 & 0xffffffff ) ;
V_174 -> V_663 = ( T_1 ) F_26 ( V_616 -> V_662 ) ;
V_174 -> V_664 = ( T_1 ) V_616 -> V_4 ;
V_174 -> V_665 = ( T_1 ) F_26 ( V_616 -> V_4 ) ;
for ( V_169 = 0 ; V_169 < V_640 ; V_169 ++ ) {
V_174 -> V_580 [ V_169 ] . V_170 = ( T_1 ) ( V_616 -> V_666 [ V_169 ] . V_195 & 0xffffffff ) ;
V_174 -> V_580 [ V_169 ] . V_171 = F_26 ( V_616 -> V_666 [ V_169 ] . V_195 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_644 * ) V_174 ;
V_616 -> V_635 = V_188 -> V_636 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_116 ( struct V_8 * V_9 ,
struct V_615 * V_616 , T_1 V_640 ,
T_1 V_667 , T_1 V_642 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_668 * V_174 ;
V_174 = F_19 ( V_669 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_636 = V_616 -> V_635 ;
V_174 -> V_670 = ( V_640 << V_671 ) |
( V_667 & V_672 ) ;
V_174 -> V_642 = V_642 << V_673 ;
for ( V_169 = 0 ; V_169 < V_640 ; V_169 ++ ) {
V_174 -> V_580 [ V_169 ] . V_170 =
( T_1 ) ( V_616 -> V_666 [ V_169 + V_667 ] . V_195 & 0xffffffff ) ;
V_174 -> V_580 [ V_169 ] . V_171 =
F_26 ( V_616 -> V_666 [ V_169 + V_667 ] . V_195 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_117 ( struct V_8 * V_9 ,
struct V_615 * V_616 , T_1 V_617 , int V_674 )
{
int V_41 ;
T_1 V_642 = 0 ;
T_1 V_675 , V_667 ;
T_1 V_676 = V_616 -> V_633 ;
V_667 = 0 ;
V_675 = F_118 ( V_676 , V_677 ) ;
if ( V_675 == V_676 )
V_642 = 1 ;
V_41 = F_115 ( V_9 , V_616 , V_617 ,
V_675 , V_616 -> V_641 , V_642 ) ;
if ( V_41 ) {
F_52 ( L_17 , V_299 , V_41 ) ;
return V_41 ;
}
if ( V_642 )
return 0 ;
while ( ! V_642 ) {
V_667 += V_675 ;
V_676 -= V_675 ;
V_675 = F_118 ( V_676 , V_677 ) ;
if ( V_675 == V_676 )
V_642 = 1 ;
V_41 = F_116 ( V_9 , V_616 , V_675 ,
V_667 , V_642 ) ;
if ( V_41 )
break;
}
if ( V_41 )
F_52 ( L_18 , V_299 , V_41 ) ;
return V_41 ;
}
bool F_119 ( struct V_248 * V_13 , struct V_243 * V_244 )
{
struct V_243 * V_678 ;
bool V_679 = false ;
F_120 (tmp, &cq->sq_head, sq_entry) {
if ( V_244 == V_678 ) {
V_679 = true ;
break;
}
}
return V_679 ;
}
bool F_121 ( struct V_248 * V_13 , struct V_243 * V_244 )
{
struct V_243 * V_678 ;
bool V_679 = false ;
F_120 (tmp, &cq->rq_head, rq_entry) {
if ( V_244 == V_678 ) {
V_679 = true ;
break;
}
}
return V_679 ;
}
void F_122 ( struct V_243 * V_244 )
{
bool V_679 ;
unsigned long V_322 ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
F_69 ( & V_9 -> V_347 , V_322 ) ;
V_679 = F_119 ( V_244 -> V_345 , V_244 ) ;
if ( ! V_679 )
F_124 ( & V_244 -> V_343 , & V_244 -> V_345 -> V_341 ) ;
if ( ! V_244 -> V_292 ) {
V_679 = F_121 ( V_244 -> V_346 , V_244 ) ;
if ( ! V_679 )
F_124 ( & V_244 -> V_344 , & V_244 -> V_346 -> V_342 ) ;
}
F_70 ( & V_9 -> V_347 , V_322 ) ;
}
static void F_125 ( struct V_243 * V_244 )
{
V_244 -> V_18 . V_19 = 0 ;
V_244 -> V_18 . V_5 = 0 ;
V_244 -> V_680 . V_19 = 0 ;
V_244 -> V_680 . V_5 = 0 ;
}
int F_50 ( struct V_243 * V_244 , enum V_23 V_681 ,
enum V_23 * V_682 )
{
unsigned long V_322 ;
enum V_24 V_683 ;
V_683 = F_10 ( V_681 ) ;
F_69 ( & V_244 -> V_684 , V_322 ) ;
if ( V_682 )
* V_682 = F_9 ( V_244 -> V_685 ) ;
if ( V_683 == V_244 -> V_685 ) {
F_70 ( & V_244 -> V_684 , V_322 ) ;
return 1 ;
}
if ( V_683 == V_28 ) {
F_125 ( V_244 ) ;
F_126 ( V_244 ) ;
} else if ( V_683 == V_39 ) {
F_122 ( V_244 ) ;
}
V_244 -> V_685 = V_683 ;
F_70 ( & V_244 -> V_684 , V_322 ) ;
return 0 ;
}
static T_1 F_127 ( struct V_243 * V_244 )
{
T_1 V_322 = 0 ;
if ( V_244 -> V_686 & V_687 )
V_322 |= V_688 ;
if ( V_244 -> V_686 & V_689 )
V_322 |= V_690 ;
if ( V_244 -> V_686 & V_691 )
V_322 |= V_692 ;
if ( V_244 -> V_686 & V_693 )
V_322 |= V_694 ;
if ( V_244 -> V_686 & V_695 )
V_322 |= V_696 ;
return V_322 ;
}
static int F_128 ( struct V_697 * V_174 ,
struct V_698 * V_699 ,
struct V_243 * V_244 )
{
int V_41 ;
T_1 V_161 , V_596 , V_168 ;
T_4 V_195 ;
struct V_520 * V_521 = V_244 -> V_521 ;
struct V_8 * V_9 = F_123 ( V_521 -> V_700 . V_271 ) ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_701 ;
T_1 V_702 = V_699 -> V_703 . V_395 ;
V_701 = F_129 ( T_1 , V_699 -> V_703 . V_704 + 1 ,
V_9 -> V_265 . V_456 ) ;
V_41 = F_102 ( & V_701 ,
V_9 -> V_265 . V_440 , & V_596 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_19 , V_299 ,
V_701 ) ;
return - V_72 ;
}
V_244 -> V_18 . V_705 = V_701 ;
V_161 = ( V_596 * V_168 ) ;
V_244 -> V_18 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_244 -> V_18 . V_4 )
return - V_72 ;
memset ( V_244 -> V_18 . V_4 , 0 , V_161 ) ;
V_244 -> V_18 . V_161 = V_161 ;
V_244 -> V_18 . V_195 = V_195 ;
V_244 -> V_18 . V_162 = V_9 -> V_265 . V_440 ;
F_25 ( & V_174 -> V_706 [ 0 ] , V_596 , V_195 , V_168 ) ;
V_174 -> V_707 |= ( F_130 ( V_168 / V_213 )
<< V_708 ) ;
V_174 -> V_709 |= ( V_596 <<
V_710 ) &
V_711 ;
V_174 -> V_712 |= ( V_702 <<
V_713 ) &
V_714 ;
V_174 -> V_712 |= ( V_702 <<
V_715 ) &
V_716 ;
V_174 -> V_717 |= ( F_130 ( V_244 -> V_18 . V_705 ) <<
V_718 ) &
V_719 ;
V_174 -> V_720 |= ( V_9 -> V_265 . V_440 <<
V_721 ) &
V_722 ;
return 0 ;
}
static int F_131 ( struct V_697 * V_174 ,
struct V_698 * V_699 ,
struct V_243 * V_244 )
{
int V_41 ;
T_1 V_161 , V_596 , V_168 ;
T_4 V_195 = 0 ;
struct V_520 * V_521 = V_244 -> V_521 ;
struct V_8 * V_9 = F_123 ( V_521 -> V_700 . V_271 ) ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_723 = V_699 -> V_703 . V_724 + 1 ;
V_41 = F_102 ( & V_723 , V_9 -> V_265 . V_445 ,
& V_596 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_20 , V_299 ,
V_699 -> V_703 . V_724 + 1 ) ;
return V_41 ;
}
V_244 -> V_680 . V_705 = V_723 ;
V_161 = ( V_596 * V_168 ) ;
V_244 -> V_680 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_244 -> V_680 . V_4 )
return - V_163 ;
memset ( V_244 -> V_680 . V_4 , 0 , V_161 ) ;
V_244 -> V_680 . V_195 = V_195 ;
V_244 -> V_680 . V_161 = V_161 ;
V_244 -> V_680 . V_162 = V_9 -> V_265 . V_445 ;
F_25 ( & V_174 -> V_725 [ 0 ] , V_596 , V_195 , V_168 ) ;
V_174 -> V_707 |= ( F_130 ( V_168 / V_213 ) <<
V_726 ) ;
V_174 -> V_709 |=
( V_596 << V_727 ) &
V_728 ;
V_174 -> V_729 |= ( V_699 -> V_703 . V_399 <<
V_730 ) &
V_731 ;
V_174 -> V_717 |= ( F_130 ( V_244 -> V_680 . V_705 ) <<
V_732 ) &
V_733 ;
V_174 -> V_720 |= ( V_9 -> V_265 . V_445 <<
V_734 ) &
V_735 ;
return 0 ;
}
static void F_132 ( struct V_697 * V_174 ,
struct V_520 * V_521 ,
struct V_243 * V_244 ,
T_2 V_736 , T_3 V_737 )
{
V_521 -> V_533 -- ;
V_244 -> V_525 = true ;
V_174 -> V_729 |= V_738 ;
if ( ! V_736 )
return;
V_174 -> V_729 |= V_738 ;
V_174 -> V_739 = V_737 ;
V_174 -> V_739 |= V_740 <<
V_741 ;
}
static int F_133 ( struct V_697 * V_174 ,
struct V_243 * V_244 )
{
struct V_520 * V_521 = V_244 -> V_521 ;
struct V_8 * V_9 = F_123 ( V_521 -> V_700 . V_271 ) ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 = 0 ;
int V_453 = V_9 -> V_265 . V_453 ;
int V_742 = V_9 -> V_265 . V_454 * V_453 ;
struct V_449 * V_743 ;
int V_169 = 0 ;
if ( V_9 -> V_265 . V_452 == 0 )
return 0 ;
V_244 -> V_744 = F_24 ( & V_158 -> V_9 , V_742 ,
& V_195 , V_145 ) ;
if ( ! V_244 -> V_744 )
return - V_163 ;
memset ( V_244 -> V_744 , 0 , V_742 ) ;
F_25 ( & V_174 -> V_745 [ 0 ] , V_9 -> V_265 . V_454 ,
V_195 , V_453 ) ;
for (; V_169 < V_742 / V_9 -> V_265 . V_445 ; V_169 ++ ) {
V_743 = (struct V_449 * ) ( V_244 -> V_744 +
( V_169 * V_9 -> V_265 . V_445 ) ) ;
V_743 -> V_746 = 0 ;
V_743 -> V_746 |= 2 ;
V_743 -> V_746 |= ( V_747 << V_748 ) ;
V_743 -> V_746 |= ( 8 << V_749 ) ;
V_743 -> V_746 |= ( 8 << V_750 ) ;
}
return 0 ;
}
static void F_134 ( struct V_751 * V_188 ,
struct V_243 * V_244 ,
struct V_698 * V_699 ,
T_3 * V_752 , T_3 * V_753 )
{
T_1 V_701 , V_723 ;
V_244 -> V_120 = V_188 -> V_754 & V_755 ;
V_244 -> V_680 . V_756 = V_188 -> V_757 & V_758 ;
V_244 -> V_18 . V_756 = V_188 -> V_757 >> V_759 ;
V_244 -> V_760 = V_188 -> V_761 & V_762 ;
V_244 -> V_763 = ( V_188 -> V_761 >> V_764 ) ;
V_244 -> V_525 = false ;
if ( V_188 -> V_765 & V_766 ) {
V_244 -> V_525 = true ;
* V_753 = ( V_188 -> V_765 &
V_767 ) >>
V_768 ;
* V_752 = ( V_188 -> V_765 &
V_769 ) >>
V_770 ;
}
V_701 =
V_188 -> V_717 >> V_771 ;
V_701 = 1 << V_701 ;
V_723 = 1 << ( ( T_3 ) V_188 -> V_717 ) ;
V_244 -> V_18 . V_705 = V_701 ;
V_244 -> V_18 . V_772 = V_701 - 1 ;
if ( ! V_699 -> V_292 ) {
V_244 -> V_680 . V_705 = V_723 ;
V_244 -> V_680 . V_772 = V_723 - 1 ;
}
}
int F_135 ( struct V_243 * V_244 , struct V_698 * V_699 ,
T_2 V_736 , T_3 V_737 , T_3 * V_752 ,
T_3 * V_753 )
{
int V_41 = - V_163 ;
T_1 V_322 = 0 ;
struct V_520 * V_521 = V_244 -> V_521 ;
struct V_8 * V_9 = F_123 ( V_521 -> V_700 . V_271 ) ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
struct V_248 * V_13 ;
struct V_697 * V_174 ;
struct V_751 * V_188 ;
int V_773 ;
switch ( V_699 -> V_774 ) {
case V_775 :
V_773 = V_776 ;
break;
case V_777 :
V_773 = V_778 ;
break;
case V_779 :
V_773 = V_780 ;
break;
default:
return - V_72 ;
}
V_174 = F_19 ( V_781 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_707 |= ( V_773 << V_782 ) &
V_783 ;
V_41 = F_128 ( V_174 , V_699 , V_244 ) ;
if ( V_41 )
goto V_784;
if ( V_699 -> V_292 ) {
struct V_785 * V_292 = F_136 ( V_699 -> V_292 ) ;
V_174 -> V_729 |= V_786 ;
V_174 -> V_725 [ 0 ] . V_170 = V_292 -> V_120 ;
V_244 -> V_292 = V_292 ;
} else {
V_41 = F_131 ( V_174 , V_699 , V_244 ) ;
if ( V_41 )
goto V_787;
}
V_41 = F_133 ( V_174 , V_244 ) ;
if ( V_41 )
goto V_200;
V_174 -> V_707 |= ( V_521 -> V_120 << V_788 ) &
V_789 ;
V_322 = F_127 ( V_244 ) ;
V_174 -> V_729 |= V_322 ;
V_174 -> V_761 |= ( V_9 -> V_265 . V_410 <<
V_790 ) &
V_791 ;
V_174 -> V_761 |= ( V_9 -> V_265 . V_414 <<
V_792 ) &
V_793 ;
V_13 = F_137 ( V_699 -> V_794 ) ;
V_174 -> V_795 |= ( V_13 -> V_120 << V_796 ) &
V_797 ;
V_244 -> V_345 = V_13 ;
V_13 = F_137 ( V_699 -> V_798 ) ;
V_174 -> V_795 |= ( V_13 -> V_120 << V_799 ) &
V_800 ;
V_244 -> V_346 = V_13 ;
if ( V_521 -> V_525 && V_699 -> V_703 . V_448 && V_521 -> V_533 &&
( V_699 -> V_703 . V_448 <= V_9 -> V_265 . V_448 ) ) {
F_132 ( V_174 , V_521 , V_244 , V_736 ,
V_737 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_751 * ) V_174 ;
F_134 ( V_188 , V_244 , V_699 , V_752 , V_753 ) ;
V_244 -> V_685 = V_26 ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
if ( V_244 -> V_680 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_680 . V_161 , V_244 -> V_680 . V_4 , V_244 -> V_680 . V_195 ) ;
V_787:
F_52 ( L_21 , V_299 , V_9 -> V_120 ) ;
F_22 ( & V_158 -> V_9 , V_244 -> V_18 . V_161 , V_244 -> V_18 . V_4 , V_244 -> V_18 . V_195 ) ;
V_784:
F_52 ( L_22 , V_299 , V_9 -> V_120 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_138 ( struct V_8 * V_9 , struct V_243 * V_244 ,
struct V_801 * V_802 )
{
int V_41 = - V_163 ;
struct V_803 * V_174 ;
struct V_804 * V_188 ;
V_174 = F_19 ( V_805 , sizeof( * V_188 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_754 = V_244 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_804 * ) V_174 ;
memcpy ( V_802 , & V_188 -> V_806 , sizeof( struct V_801 ) ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_139 ( struct V_243 * V_244 ,
struct V_807 * V_174 ,
struct V_808 * V_699 ,
int V_809 )
{
int V_41 ;
struct V_810 * V_811 = & V_699 -> V_811 ;
union V_812 V_813 , V_814 ;
struct V_815 V_816 ;
T_1 V_817 = 0xFFFF ;
T_2 V_818 [ 6 ] , V_819 ;
union {
struct V_820 V_821 ;
struct V_822 V_823 ;
struct V_824 V_825 ;
} V_826 , V_827 ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
const struct V_828 * V_829 ;
if ( ( F_140 ( V_811 ) & V_830 ) == 0 )
return - V_72 ;
V_829 = F_141 ( V_811 ) ;
if ( F_142 ( & V_9 -> V_317 , 1 , 0 ) )
F_143 ( V_9 ) ;
V_174 -> V_806 . V_831 |=
( V_829 -> V_832 << V_833 ) ;
V_174 -> V_806 . V_834 |=
( V_829 -> V_835 & V_836 ) ;
V_174 -> V_806 . V_834 |= ( F_144 ( V_811 ) <<
V_837 ) ;
V_174 -> V_806 . V_838 |=
( V_829 -> V_839 << V_840 ) ;
V_174 -> V_322 |= V_841 ;
memcpy ( & V_174 -> V_806 . V_842 [ 0 ] , & V_829 -> V_842 . V_843 [ 0 ] ,
sizeof( V_174 -> V_806 . V_842 ) ) ;
V_41 = F_145 ( & V_9 -> V_272 , 1 , V_829 -> V_844 ,
& V_813 , & V_816 ) ;
if ( ! V_41 && V_816 . V_845 ) {
V_817 = F_146 ( V_816 . V_845 ) ;
memcpy ( V_818 , V_816 . V_845 -> V_846 , V_847 ) ;
F_147 ( V_816 . V_845 ) ;
}
memset ( & V_814 , 0 , sizeof( V_814 ) ) ;
if ( ! memcmp ( & V_813 , & V_814 , sizeof( V_814 ) ) )
return - V_72 ;
V_244 -> V_848 = V_829 -> V_844 ;
memcpy ( & V_174 -> V_806 . V_813 [ 0 ] , & V_813 . V_843 [ 0 ] , sizeof( V_174 -> V_806 . V_813 ) ) ;
V_41 = F_148 ( V_9 , V_811 , & V_818 [ 0 ] ) ;
if ( V_41 )
return V_41 ;
V_174 -> V_806 . V_849 = V_818 [ 0 ] | ( V_818 [ 1 ] << 8 ) |
( V_818 [ 2 ] << 16 ) | ( V_818 [ 3 ] << 24 ) ;
V_819 = F_149 ( V_816 . V_850 , & V_813 ) ;
if ( V_819 == V_851 ) {
F_150 ( & V_826 . V_821 , & V_813 ) ;
F_150 ( & V_827 . V_821 , & V_829 -> V_842 ) ;
memcpy ( & V_174 -> V_806 . V_842 [ 0 ] ,
& V_827 . V_823 . V_852 . V_853 , 4 ) ;
memcpy ( & V_174 -> V_806 . V_813 [ 0 ] ,
& V_826 . V_823 . V_852 . V_853 , 4 ) ;
}
F_151 ( & V_174 -> V_806 . V_842 [ 0 ] , sizeof( V_174 -> V_806 . V_842 ) ) ;
F_151 ( & V_174 -> V_806 . V_813 [ 0 ] , sizeof( V_174 -> V_806 . V_813 ) ) ;
V_174 -> V_806 . V_854 = V_818 [ 4 ] | ( V_818 [ 5 ] << 8 ) ;
if ( V_817 == 0xFFFF )
V_817 = 0 ;
if ( V_817 || V_9 -> V_855 ) {
if ( ! V_817 ) {
F_52 ( L_23 ,
V_9 -> V_120 ) ;
F_52 ( L_24 ,
V_9 -> V_120 ) ;
}
V_174 -> V_806 . V_854 |=
V_817 << V_856 ;
V_174 -> V_322 |= V_857 ;
V_174 -> V_806 . V_834 |=
( V_9 -> V_858 & 0x07 ) << V_837 ;
}
V_174 -> V_806 . V_729 |= ( ( V_819 <<
V_859 ) &
V_860 ) ;
return 0 ;
}
static int F_152 ( struct V_243 * V_244 ,
struct V_807 * V_174 ,
struct V_808 * V_699 , int V_809 )
{
int V_41 = 0 ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
if ( V_809 & V_861 ) {
V_174 -> V_806 . V_862 |= ( V_699 -> V_863 &
V_864 ) ;
V_174 -> V_322 |= V_865 ;
}
if ( V_809 & V_866 ) {
V_244 -> V_867 = V_699 -> V_867 ;
V_174 -> V_806 . V_867 = V_699 -> V_867 ;
V_174 -> V_322 |= V_868 ;
}
if ( V_809 & V_869 ) {
V_41 = F_139 ( V_244 , V_174 , V_699 , V_809 ) ;
if ( V_41 )
return V_41 ;
} else if ( V_244 -> V_774 == V_775 || V_244 -> V_774 == V_779 ) {
V_174 -> V_806 . V_849 = V_9 -> V_117 . V_818 [ 0 ] |
( V_9 -> V_117 . V_818 [ 1 ] << 8 ) |
( V_9 -> V_117 . V_818 [ 2 ] << 16 ) |
( V_9 -> V_117 . V_818 [ 3 ] << 24 ) ;
V_174 -> V_806 . V_854 = V_9 -> V_117 . V_818 [ 4 ] |
( V_9 -> V_117 . V_818 [ 5 ] << 8 ) ;
}
if ( ( V_809 & V_870 ) &&
V_699 -> V_871 ) {
V_174 -> V_806 . V_729 |=
V_872 ;
V_174 -> V_322 |= V_873 ;
}
if ( V_809 & V_874 ) {
V_174 -> V_806 . V_875 |= ( V_699 -> V_876 &
V_877 ) ;
V_174 -> V_322 |= V_873 ;
}
if ( V_809 & V_878 ) {
if ( V_699 -> V_879 < V_880 ||
V_699 -> V_879 > V_881 ) {
F_52 ( L_25 ,
V_9 -> V_120 , F_153 ( V_699 -> V_879 ) ) ;
V_41 = - V_72 ;
goto V_882;
}
V_174 -> V_806 . V_862 |=
( F_153 ( V_699 -> V_879 ) <<
V_883 ) &
V_884 ;
V_174 -> V_322 |= V_885 ;
}
if ( V_809 & V_886 ) {
V_174 -> V_806 . V_875 |= V_699 -> V_143 <<
V_887 ;
V_174 -> V_322 |= V_888 ;
}
if ( V_809 & V_889 ) {
V_174 -> V_806 . V_834 |= ( V_699 -> V_890 <<
V_891 ) &
V_892 ;
V_174 -> V_322 |= V_893 ;
}
if ( V_809 & V_894 ) {
V_174 -> V_806 . V_834 |= ( V_699 -> V_895 <<
V_896 ) &
V_897 ;
V_174 -> V_322 |= V_898 ;
}
if ( V_809 & V_899 ) {
V_174 -> V_806 . V_875 |= ( V_699 -> V_900 <<
V_901 )
& V_902 ;
V_174 -> V_322 |= V_903 ;
}
if ( V_809 & V_904 ) {
V_174 -> V_806 . V_831 |= ( V_699 -> V_905 & 0x00ffffff ) ;
V_174 -> V_322 |= V_906 ;
}
if ( V_809 & V_907 ) {
V_174 -> V_806 . V_838 |= ( V_699 -> V_908 & 0x00ffffff ) ;
V_174 -> V_322 |= V_909 ;
}
if ( V_809 & V_910 ) {
if ( V_699 -> V_911 > V_9 -> V_265 . V_410 ) {
V_41 = - V_72 ;
goto V_882;
}
V_244 -> V_763 = V_699 -> V_911 ;
V_174 -> V_322 |= V_912 ;
}
if ( V_809 & V_913 ) {
if ( V_699 -> V_914 > V_9 -> V_265 . V_414 ) {
V_41 = - V_72 ;
goto V_882;
}
V_244 -> V_760 = V_699 -> V_914 ;
V_174 -> V_322 |= V_915 ;
}
V_174 -> V_806 . V_761 = ( V_244 -> V_763 <<
V_916 ) |
( V_244 -> V_760 & V_917 ) ;
V_882:
return V_41 ;
}
int F_154 ( struct V_8 * V_9 , struct V_243 * V_244 ,
struct V_808 * V_699 , int V_809 )
{
int V_41 = - V_163 ;
struct V_807 * V_174 ;
V_174 = F_19 ( V_918 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_806 . V_120 = V_244 -> V_120 ;
V_174 -> V_322 = 0 ;
if ( V_809 & V_919 ) {
V_174 -> V_806 . V_729 |=
( F_10 ( V_699 -> V_920 ) <<
V_921 ) &
V_922 ;
V_174 -> V_322 |= V_923 ;
} else {
V_174 -> V_806 . V_729 |=
( V_244 -> V_685 << V_921 ) &
V_922 ;
}
V_41 = F_152 ( V_244 , V_174 , V_699 , V_809 ) ;
if ( V_41 )
goto V_200;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_155 ( struct V_8 * V_9 , struct V_243 * V_244 )
{
int V_41 = - V_163 ;
struct V_924 * V_174 ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_925 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_754 = V_244 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
if ( V_244 -> V_18 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_18 . V_161 , V_244 -> V_18 . V_4 , V_244 -> V_18 . V_195 ) ;
if ( ! V_244 -> V_292 && V_244 -> V_680 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_680 . V_161 , V_244 -> V_680 . V_4 , V_244 -> V_680 . V_195 ) ;
if ( V_244 -> V_525 )
V_244 -> V_521 -> V_533 ++ ;
return V_41 ;
}
int F_156 ( struct V_8 * V_9 , struct V_785 * V_292 ,
struct V_926 * V_927 ,
struct V_520 * V_521 )
{
int V_41 = - V_163 ;
int V_596 , V_168 ;
int V_161 ;
struct V_928 * V_188 ;
struct V_929 * V_174 ;
T_4 V_195 ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_723 ;
V_174 = F_19 ( V_930 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_931 = V_521 -> V_120 & V_932 ;
V_723 = V_927 -> V_265 . V_933 + 1 ;
V_41 = F_102 ( & V_723 ,
V_9 -> V_265 . V_445 ,
& V_596 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_26 , V_299 ,
V_927 -> V_265 . V_933 ) ;
V_41 = - V_72 ;
goto V_934;
}
V_161 = V_596 * V_168 ;
V_292 -> V_680 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_292 -> V_680 . V_4 ) {
V_41 = - V_163 ;
goto V_934;
}
F_25 ( & V_174 -> V_725 [ 0 ] , V_596 , V_195 , V_168 ) ;
V_292 -> V_680 . V_162 = V_9 -> V_265 . V_445 ;
V_292 -> V_680 . V_195 = V_195 ;
V_292 -> V_680 . V_161 = V_161 ;
V_292 -> V_680 . V_705 = V_723 ;
V_174 -> V_935 = F_130 ( V_723 ) ;
V_174 -> V_935 |= V_927 -> V_265 . V_936 <<
V_937 ;
V_174 -> V_931 |= ( F_130 ( V_168 / V_213 )
<< V_938 ) ;
V_174 -> V_939 |= ( V_9 -> V_265 . V_445
<< V_940 )
& V_941 ;
V_174 -> V_939 |= V_596 << V_942 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_928 * ) V_174 ;
V_292 -> V_120 = V_188 -> V_120 ;
V_292 -> V_680 . V_756 = V_188 -> V_120 ;
V_723 = ( ( V_188 -> V_943 &
V_944 ) >>
V_945 ) ;
V_723 = ( 1 << V_723 ) ;
V_292 -> V_680 . V_705 = V_723 ;
V_292 -> V_680 . V_772 = V_723 - 1 ;
V_292 -> V_680 . V_702 = ( V_188 -> V_943 &
V_946 ) >>
V_947 ;
goto V_934;
V_200:
F_22 ( & V_158 -> V_9 , V_292 -> V_680 . V_161 , V_292 -> V_680 . V_4 , V_195 ) ;
V_934:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_157 ( struct V_785 * V_292 , struct V_948 * V_927 )
{
int V_41 = - V_163 ;
struct V_949 * V_174 ;
struct V_520 * V_521 = V_292 -> V_521 ;
struct V_8 * V_9 = F_123 ( V_521 -> V_700 . V_271 ) ;
V_174 = F_19 ( V_950 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_120 ;
V_174 -> V_951 |= V_927 -> V_952 <<
V_953 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_158 ( struct V_785 * V_292 , struct V_948 * V_927 )
{
int V_41 = - V_163 ;
struct V_954 * V_174 ;
struct V_8 * V_9 = F_123 ( V_292 -> V_293 . V_271 ) ;
V_174 = F_19 ( V_955 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_680 . V_756 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 == 0 ) {
struct V_956 * V_188 =
(struct V_956 * ) V_174 ;
V_927 -> V_936 =
V_188 -> V_957 &
V_958 ;
V_927 -> V_933 =
V_188 -> V_959 >> V_960 ;
V_927 -> V_952 = V_188 -> V_957 >>
V_961 ;
}
F_87 ( V_174 ) ;
return V_41 ;
}
int F_159 ( struct V_8 * V_9 , struct V_785 * V_292 )
{
int V_41 = - V_163 ;
struct V_962 * V_174 ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_963 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_292 -> V_680 . V_4 )
F_22 ( & V_158 -> V_9 , V_292 -> V_680 . V_161 ,
V_292 -> V_680 . V_4 , V_292 -> V_680 . V_195 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_160 ( struct V_8 * V_9 , T_1 V_964 ,
struct V_965 * V_966 )
{
int V_41 ;
T_4 V_195 ;
struct V_17 V_174 ;
struct V_967 * V_182 = NULL ;
struct V_968 * V_188 = NULL ;
struct V_564 * V_158 = V_9 -> V_117 . V_158 ;
struct V_969 * V_970 = V_174 . V_153 . V_479 . V_480 ;
memset ( & V_174 , 0 , sizeof( struct V_17 ) ) ;
V_174 . V_146 . V_151 = F_161 ( T_1 , sizeof( struct V_968 ) ,
sizeof( struct V_967 ) ) ;
V_182 = F_24 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , & V_195 , V_145 ) ;
if ( ! V_182 ) {
V_41 = - V_163 ;
goto V_581;
}
V_174 . V_146 . V_147 |= ( 1 << V_477 ) &
V_478 ;
V_970 -> V_481 = ( T_1 ) ( V_195 & 0xFFFFFFFFUL ) ;
V_970 -> V_482 = ( T_1 ) F_26 ( V_195 ) ;
V_970 -> V_161 = V_174 . V_146 . V_151 ;
memset ( V_182 , 0 , sizeof( struct V_967 ) ) ;
F_18 ( & V_182 -> V_146 , V_971 ,
V_972 , V_174 . V_146 . V_151 ) ;
V_182 -> V_973 = V_964 ;
V_41 = F_80 ( V_9 , & V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_968 * ) V_182 ;
F_64 ( V_188 , sizeof( struct V_968 ) ) ;
memcpy ( V_966 , & V_188 -> V_974 , sizeof( struct V_965 ) ) ;
V_200:
F_22 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , V_182 , V_195 ) ;
V_581:
return V_41 ;
}
static int F_162 ( struct V_8 * V_9 , int V_964 ,
struct V_965 * V_966 ,
T_2 * V_975 )
{
int V_41 = - V_72 , V_976 , V_977 ;
int V_978 ;
struct V_979 * V_980 ;
T_2 V_192 , V_981 ;
T_2 V_982 , V_983 ;
T_3 V_984 ;
if ( ! ( V_966 -> V_985 & V_986 ) ) {
F_163 ( L_27 ,
F_164 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
goto V_987;
}
if ( ! F_165 ( V_966 -> V_855 ) ) {
F_163 ( L_28 ,
F_164 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
( V_964 > 0 ? L_29 : L_30 ) ,
( V_966 -> V_855 & V_988 ) ?
L_31 : L_32 ,
( V_966 -> V_855 & V_989 ) ?
L_1 : L_33 ) ;
goto V_987;
} else {
F_163 ( L_34 ,
F_164 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
}
V_978 = ( V_966 -> V_985 >>
V_990 )
& V_986 ;
for ( V_976 = 0 ; V_976 < V_978 ; V_976 ++ ) {
V_980 = & V_966 -> V_980 [ V_976 ] ;
V_192 = ( V_980 -> V_991 >>
V_992 )
& V_993 ;
V_981 = ( V_980 -> V_991
>> V_994 )
& V_995 ;
V_984 = V_980 -> V_991 &
V_996 ;
if (
V_192 && V_984 == V_997 &&
V_981 == V_998 ) {
for ( V_977 = 0 ; V_977 <
V_999 ; V_977 ++ ) {
V_982 = F_166 (
( T_2 * ) V_980 -> V_982 ,
V_977 ) ;
V_983 = F_167 (
( T_2 * ) V_966 -> V_983 ,
V_977 ) ;
if ( V_982 && V_983 ) {
* V_975 = V_977 ;
V_41 = 0 ;
goto V_987;
}
}
if ( V_977 == V_999 ) {
F_163 ( L_35 ,
F_164 ( & V_9 -> V_117 . V_158 -> V_9 ) ,
V_9 -> V_120 , V_984 ) ;
}
}
}
V_987:
return V_41 ;
}
void F_143 ( struct V_8 * V_9 )
{
int V_41 = 0 , V_976 ;
struct V_965 V_966 ;
T_2 V_975 = V_1000 ;
int V_964 = V_1001 ;
for ( V_976 = 0 ; V_976 < 2 ; V_976 ++ ) {
V_41 = F_160 ( V_9 , V_964 , & V_966 ) ;
if ( V_41 ) {
F_52 ( L_36 , V_299 , V_41 ) ;
V_964 = V_1002 ;
continue;
}
V_41 = F_162 ( V_9 , V_964 ,
& V_966 , & V_975 ) ;
if ( V_41 ) {
V_964 = V_1002 ;
continue;
}
break;
}
if ( V_41 )
F_163 ( L_37 ,
F_164 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
else
F_163 ( L_38 ,
F_164 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
V_975 ) ;
V_9 -> V_855 = F_165 ( V_966 . V_855 ) ;
V_9 -> V_858 = V_975 ;
}
int F_168 ( struct V_8 * V_9 , struct V_1003 * V_1004 )
{
int V_169 ;
int V_41 = - V_72 ;
struct V_570 * V_1005 ;
unsigned long V_322 ;
V_1005 = V_9 -> V_569 . V_4 ;
F_69 ( & V_9 -> V_569 . V_239 , V_322 ) ;
for ( V_169 = 0 ; V_169 < V_9 -> V_569 . V_583 ; V_169 ++ ) {
if ( V_1005 -> V_192 == 0 ) {
V_1005 -> V_192 = V_1006 ;
V_1004 -> V_1005 = V_1005 ;
V_1004 -> V_120 = V_169 ;
V_41 = 0 ;
break;
}
V_1005 ++ ;
}
if ( V_169 == V_9 -> V_569 . V_583 )
V_41 = - V_51 ;
F_70 ( & V_9 -> V_569 . V_239 , V_322 ) ;
return V_41 ;
}
int F_169 ( struct V_8 * V_9 , struct V_1003 * V_1004 )
{
unsigned long V_322 ;
F_69 ( & V_9 -> V_569 . V_239 , V_322 ) ;
V_1004 -> V_1005 -> V_192 = 0 ;
F_70 ( & V_9 -> V_569 . V_239 , V_322 ) ;
return 0 ;
}
static int F_170 ( struct V_8 * V_9 )
{
int V_1007 , V_169 , V_41 = 0 ;
int V_201 ;
unsigned long V_322 = 0 ;
V_1007 = V_9 -> V_117 . V_204 . V_1008 -
V_9 -> V_117 . V_204 . V_1009 ;
if ( V_9 -> V_117 . V_202 == V_203 ) {
V_1007 = 1 ;
V_322 = V_1010 ;
} else {
V_1007 = F_129 ( T_1 , V_1007 , F_171 () ) ;
}
if ( ! V_1007 )
return - V_72 ;
V_9 -> V_207 = F_20 ( sizeof( struct V_1 ) * V_1007 , V_145 ) ;
if ( ! V_9 -> V_207 )
return - V_163 ;
for ( V_169 = 0 ; V_169 < V_1007 ; V_169 ++ ) {
V_41 = F_31 ( V_9 , & V_9 -> V_207 [ V_169 ] ,
V_7 ) ;
if ( V_41 ) {
V_41 = - V_72 ;
break;
}
sprintf ( V_9 -> V_207 [ V_169 ] . V_1011 , L_39 ,
V_9 -> V_120 , V_169 ) ;
V_201 = F_32 ( V_9 , & V_9 -> V_207 [ V_169 ] ) ;
V_41 = F_172 ( V_201 , F_73 , V_322 ,
V_9 -> V_207 [ V_169 ] . V_1011 ,
& V_9 -> V_207 [ V_169 ] ) ;
if ( V_41 )
goto V_1012;
V_9 -> V_206 += 1 ;
}
return 0 ;
V_1012:
F_36 ( V_9 ) ;
return V_41 ;
}
static int F_173 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_1013 )
{
int V_169 , V_41 = - V_163 ;
struct V_1014 * V_174 ;
V_174 = F_19 ( V_1015 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_174 . V_182 , V_1015 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_174 . V_1007 = V_1013 ;
for ( V_169 = 0 ; V_169 < V_1013 ; V_169 ++ ) {
V_174 -> V_174 . V_1016 [ V_169 ] . V_124 = V_2 [ V_169 ] . V_3 . V_120 ;
V_174 -> V_174 . V_1016 [ V_169 ] . V_1017 = 0 ;
V_174 -> V_174 . V_1016 [ V_169 ] . V_1018 =
( V_2 [ V_169 ] . V_364 . V_1019 * 65 ) / 100 ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_174 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_1013 )
{
int V_1020 , V_169 = 0 ;
if ( V_1013 > 8 ) {
while ( V_1013 ) {
V_1020 = F_118 ( V_1013 , 8 ) ;
F_173 ( V_9 , & V_2 [ V_169 ] , V_1020 ) ;
V_169 += V_1020 ;
V_1013 -= V_1020 ;
}
} else {
F_173 ( V_9 , V_2 , V_1013 ) ;
}
return 0 ;
}
void F_175 ( struct V_1021 * V_1022 )
{
struct V_8 * V_9 =
F_176 ( V_1022 , struct V_8 , V_1023 . V_1022 ) ;
struct V_1 * V_2 = 0 ;
int V_169 , V_1013 = 0 , V_41 = - V_72 ;
V_429 V_1024 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
V_2 = & V_9 -> V_207 [ V_169 ] ;
if ( V_2 -> V_364 . V_365 > V_2 -> V_364 . V_1025 ) {
V_1024 = V_2 -> V_364 . V_365 -
V_2 -> V_364 . V_1025 ;
if ( ( V_1024 > V_1026 ) &&
( V_2 -> V_364 . V_1019 == V_1027 ) ) {
V_2 -> V_364 . V_1019 = V_1028 ;
V_1013 ++ ;
} else if ( ( V_1024 < V_1029 ) &&
( V_2 -> V_364 . V_1019 == V_1028 ) ) {
V_2 -> V_364 . V_1019 = V_1027 ;
V_1013 ++ ;
}
}
V_2 -> V_364 . V_1025 = V_2 -> V_364 . V_365 ;
}
if ( V_1013 )
V_41 = F_174 ( V_9 , & V_9 -> V_207 [ 0 ] , V_1013 ) ;
F_177 ( & V_9 -> V_1023 , F_79 ( 1000 ) ) ;
}
int F_178 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_170 ( V_9 ) ;
if ( V_41 )
goto V_1030;
V_41 = F_43 ( V_9 ) ;
if ( V_41 )
goto V_1031;
V_41 = F_88 ( V_9 ) ;
if ( V_41 )
goto V_1032;
V_41 = F_92 ( V_9 ) ;
if ( V_41 )
goto V_1032;
V_41 = F_86 ( V_9 ) ;
if ( V_41 )
goto V_1032;
V_41 = F_105 ( V_9 ) ;
if ( V_41 )
goto V_1032;
V_41 = F_94 ( V_9 ) ;
if ( V_41 )
goto V_1033;
V_41 = F_91 ( V_9 ) ;
if ( V_41 )
goto V_1033;
return 0 ;
V_1033:
F_107 ( V_9 ) ;
V_1032:
F_46 ( V_9 ) ;
V_1031:
F_36 ( V_9 ) ;
V_1030:
F_52 ( L_17 , V_299 , V_41 ) ;
return V_41 ;
}
void F_179 ( struct V_8 * V_9 )
{
F_101 ( V_9 ) ;
F_107 ( V_9 ) ;
F_46 ( V_9 ) ;
F_36 ( V_9 ) ;
}
