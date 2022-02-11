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
int V_41 = 0 ;
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
V_265 -> V_381 =
( V_188 -> V_382 & V_383 ) >>
V_384 ;
V_265 -> V_266 =
( V_188 -> V_385 & V_386 ) >>
V_387 ;
V_265 -> V_388 =
( V_188 -> V_389 & V_390 ) >>
V_391 ;
V_265 -> V_392 = ( ( V_188 -> V_393 &
V_394 ) >>
V_395 ) ;
V_265 -> V_396 = ( V_188 -> V_393 &
V_394 ) >>
V_395 ;
V_265 -> V_397 = ( V_188 -> V_398 &
V_399 ) >>
V_400 ;
V_265 -> V_401 = ( V_188 -> V_393 &
V_402 ) >>
V_403 ;
V_265 -> V_404 = ( V_188 -> V_405 &
V_406 ) >>
V_407 ;
V_265 -> V_408 = ( V_188 -> V_405 &
V_409 ) >>
V_410 ;
V_265 -> V_411 = ( V_188 -> V_385 &
V_412 ) >>
V_413 ;
V_265 -> V_414 = ( V_188 -> V_385 &
V_415 ) >>
V_416 ;
V_265 -> V_417 = ( V_188 -> V_378 &
V_418 ) >>
V_419 ;
V_265 -> V_420 = V_188 -> V_420 ;
V_265 -> V_421 = V_188 -> V_421 ;
V_265 -> V_422 = ( ( V_423 ) V_188 -> V_424 << 32 ) |
V_188 -> V_425 ;
V_265 -> V_426 = 0 ;
V_265 -> V_427 = V_188 -> V_427 ;
V_265 -> V_428 = V_188 -> V_428 ;
V_265 -> V_429 = V_188 -> V_430 &
V_431 ;
V_265 -> V_269 = ( V_188 -> V_430 &
V_432 ) >>
V_433 ;
V_265 -> V_434 = ( ( V_188 -> V_435 &
V_436 ) >>
V_437 ) *
V_438 ;
V_265 -> V_439 = ( ( V_188 -> V_435 &
V_440 ) >>
V_441 ) *
V_438 ;
V_265 -> V_442 =
V_265 -> V_434 - ( sizeof( struct V_443 ) +
sizeof( struct V_444 ) ) ;
if ( F_84 ( V_9 ) == V_445 ) {
V_265 -> V_446 = 1 ;
V_265 -> V_447 = V_213 ;
V_265 -> V_448 = V_449 ;
}
V_9 -> V_265 . V_450 = V_188 -> V_451 >>
V_452 ;
V_9 -> V_265 . V_453 = V_188 -> V_451 &
V_454 ;
}
static int F_85 ( struct V_8 * V_9 ,
struct V_455 * V_456 )
{
T_1 V_457 ;
V_457 = V_456 -> V_457 & V_458 ;
if ( V_457 != V_458 )
return - V_72 ;
V_9 -> V_459 = V_456 -> V_459 ;
V_9 -> V_460 = V_456 -> V_460 ;
return 0 ;
}
static int F_86 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_461 * V_188 ;
V_174 = F_19 ( V_462 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_462 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_461 * ) V_174 ;
memset ( & V_9 -> V_265 . V_463 [ 0 ] , 0 , sizeof( V_9 -> V_265 . V_463 ) ) ;
memcpy ( & V_9 -> V_265 . V_463 [ 0 ] , & V_188 -> V_464 [ 0 ] ,
sizeof( V_188 -> V_464 ) ) ;
F_64 ( V_9 -> V_265 . V_463 , sizeof( V_188 -> V_464 ) ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_88 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_455 * V_188 ;
V_174 = F_19 ( V_465 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_465 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_455 * ) V_174 ;
V_41 = F_85 ( V_9 , V_188 ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_89 ( struct V_8 * V_9 , bool V_466 )
{
struct V_467 * V_182 = V_9 -> V_468 . V_4 ;
struct V_17 * V_144 = & V_9 -> V_468 . V_144 ;
struct V_469 * V_470 ;
int V_41 ;
V_470 = F_90 ( sizeof( * V_470 ) , V_145 ) ;
if ( V_470 == NULL )
return - V_163 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> V_146 . V_151 = V_9 -> V_468 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_471 ) &
V_472 ;
V_144 -> V_153 . V_473 . V_474 [ 0 ] . V_475 = ( T_1 ) ( V_9 -> V_468 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_473 . V_474 [ 0 ] . V_476 = ( T_1 ) F_26 ( V_9 -> V_468 . V_195 ) ;
V_144 -> V_153 . V_473 . V_474 [ 0 ] . V_161 = V_9 -> V_468 . V_159 ;
memcpy ( V_470 , V_182 , sizeof( struct V_469 ) ) ;
memset ( V_182 , 0 , V_9 -> V_468 . V_159 ) ;
F_18 ( (struct V_136 * ) V_182 ,
V_477 ,
V_156 ,
V_9 -> V_468 . V_159 ) ;
if ( V_466 )
V_182 -> V_478 = V_466 ;
V_41 = F_82 ( V_9 , V_144 , V_9 -> V_468 . V_4 ) ;
if ( V_41 )
memcpy ( V_182 , V_470 , sizeof( struct V_469 ) ) ;
else
F_64 ( V_182 , V_9 -> V_468 . V_159 ) ;
F_87 ( V_470 ) ;
return V_41 ;
}
static int F_91 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_479 V_160 ;
struct V_17 * V_144 ;
struct V_480 * V_481 ;
struct V_482 * V_483 ;
V_144 = F_20 ( sizeof( struct V_17 ) , V_145 ) ;
if ( ! V_144 )
return V_41 ;
V_160 . V_159 = sizeof( struct V_480 ) ;
V_160 . V_4 = F_24 ( & V_9 -> V_117 . V_158 -> V_9 ,
V_160 . V_159 , & V_160 . V_195 , V_145 ) ;
if ( ! V_160 . V_4 )
goto V_484;
V_144 -> V_146 . V_151 = V_160 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_471 ) &
V_472 ;
V_144 -> V_153 . V_473 . V_474 [ 0 ] . V_475 = ( T_1 ) ( V_160 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_473 . V_474 [ 0 ] . V_476 = ( T_1 ) F_26 ( V_160 . V_195 ) ;
V_144 -> V_153 . V_473 . V_474 [ 0 ] . V_161 = V_160 . V_159 ;
memset ( V_160 . V_4 , 0 , V_160 . V_159 ) ;
F_18 ( (struct V_136 * ) V_160 . V_4 ,
V_485 ,
V_183 ,
V_160 . V_159 ) ;
V_41 = F_82 ( V_9 , V_144 , V_160 . V_4 ) ;
if ( ! V_41 ) {
V_481 = (struct V_480 * ) V_160 . V_4 ;
V_483 = & V_481 -> V_486 . V_483 ;
V_9 -> V_487 = ( V_483 -> V_488 &
V_489 )
>> V_490 ;
strncpy ( V_9 -> V_491 ,
V_483 -> V_492 , 31 ) ;
}
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_160 . V_159 , V_160 . V_4 , V_160 . V_195 ) ;
V_484:
F_87 ( V_144 ) ;
return V_41 ;
}
static int F_92 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_376 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_493 , sizeof( * V_174 ) ) ;
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
int F_93 ( struct V_8 * V_9 , T_2 * V_494 ,
T_2 * V_495 )
{
int V_41 = - V_163 ;
struct V_496 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_497 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_497 ,
V_183 , sizeof( * V_174 ) ) ;
( (struct V_136 * ) V_174 -> V_153 . V_174 ) -> V_190 = 0x1 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_496 * ) V_174 ;
if ( V_494 )
* V_494 = ( V_188 -> V_498 & V_499 )
>> V_500 ;
if ( V_495 )
* V_495 = ( V_188 -> V_501 & V_324 ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_94 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_502 * V_188 ;
V_174 = F_19 ( V_503 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_503 , V_183 ,
sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_502 * ) V_174 ;
V_9 -> V_93 . V_504 =
( V_188 -> V_505 & V_506 ) ;
V_9 -> V_93 . V_507 =
( V_188 -> V_505 & V_508 )
>> V_509 ;
V_9 -> V_93 . V_95 =
( V_188 -> V_510 & V_511 ) ;
V_9 -> V_93 . V_94 =
( V_188 -> V_510 & V_512 )
>> V_513 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_95 ( struct V_8 * V_9 , struct V_514 * V_515 )
{
int V_41 = - V_163 ;
struct V_516 * V_174 ;
struct V_517 * V_188 ;
V_174 = F_19 ( V_518 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
if ( V_515 -> V_519 )
V_174 -> V_520 |= V_521 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_517 * ) V_174 ;
V_515 -> V_120 = V_188 -> V_522 & V_523 ;
if ( V_188 -> V_522 & V_524 ) {
V_515 -> V_519 = true ;
V_515 -> V_525 = V_188 -> V_522 >>
V_526 ;
} else {
V_515 -> V_519 = false ;
V_515 -> V_527 = 0 ;
}
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_96 ( struct V_8 * V_9 , struct V_514 * V_515 )
{
int V_41 = - V_163 ;
struct V_528 * V_174 ;
V_174 = F_19 ( V_529 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_515 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_97 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
T_6 V_530 ;
struct V_531 * V_174 ;
struct V_532 * V_188 ;
if ( V_9 -> V_265 . V_381 ) {
V_174 = F_19 ( V_533 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_534 = V_9 -> V_265 . V_381 ;
V_174 -> V_520 |= V_521 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
V_188 = (struct V_532 * ) V_174 ;
if ( ! V_41 && ( V_188 -> V_522 & V_524 ) &&
V_188 -> V_534 ) {
V_9 -> V_535 -> V_536 = V_188 -> V_522 >>
V_526 ;
V_9 -> V_535 -> V_537 = V_188 -> V_522 &
V_538 ;
V_9 -> V_535 -> V_539 = V_188 -> V_534 ;
V_530 =
F_98 ( V_188 -> V_534 ) * sizeof( long ) ;
V_9 -> V_535 -> V_540 = F_20 ( V_530 ,
V_145 ) ;
}
F_87 ( V_174 ) ;
}
V_174 = F_19 ( V_533 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_534 = V_9 -> V_265 . V_377 - V_9 -> V_265 . V_381 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
V_188 = (struct V_532 * ) V_174 ;
if ( ! V_41 && V_188 -> V_534 ) {
V_9 -> V_535 -> V_541 = V_188 -> V_522 &
V_538 ;
V_9 -> V_535 -> V_542 = V_188 -> V_534 ;
V_530 = F_98 ( V_188 -> V_534 ) * sizeof( long ) ;
V_9 -> V_535 -> V_543 = F_20 ( V_530 ,
V_145 ) ;
}
F_87 ( V_174 ) ;
if ( V_9 -> V_535 -> V_543 || V_9 -> V_535 -> V_540 ) {
V_9 -> V_535 -> V_544 = true ;
return 0 ;
}
return V_41 ;
}
static void F_99 ( struct V_8 * V_9 )
{
struct V_545 * V_174 ;
V_174 = F_19 ( V_546 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
if ( V_9 -> V_535 -> V_542 ) {
V_174 -> V_547 = V_9 -> V_535 -> V_541 ;
V_174 -> V_534 = V_9 -> V_535 -> V_542 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
}
if ( V_9 -> V_535 -> V_539 ) {
F_87 ( V_174 ) ;
V_174 = F_19 ( V_546 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
V_174 -> V_547 = V_9 -> V_535 -> V_537 ;
V_174 -> V_534 = V_9 -> V_535 -> V_539 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
}
V_200:
F_87 ( V_174 ) ;
}
void F_100 ( struct V_8 * V_9 )
{
int V_41 ;
V_9 -> V_535 = F_20 ( sizeof( struct V_548 ) ,
V_145 ) ;
if ( ! V_9 -> V_535 ) {
F_52 ( L_15 , V_299 , V_9 -> V_120 ) ;
return;
}
V_41 = F_97 ( V_9 ) ;
if ( V_41 ) {
F_52 ( L_16 ,
V_299 , V_9 -> V_120 ) ;
}
}
static void F_101 ( struct V_8 * V_9 )
{
F_99 ( V_9 ) ;
F_87 ( V_9 -> V_535 -> V_543 ) ;
F_87 ( V_9 -> V_535 -> V_540 ) ;
F_87 ( V_9 -> V_535 ) ;
}
static int F_102 ( T_1 * V_549 , int V_162 ,
int * V_191 , int * V_550 )
{
int V_169 ;
int V_551 ;
* V_549 = F_103 ( * V_549 ) ;
V_551 = * V_549 * V_162 ;
for ( V_169 = 0 ; V_169 < V_552 ; V_169 ++ ) {
if ( V_551 <= ( V_553 << V_169 ) )
break;
}
if ( V_169 >= V_552 )
return - V_72 ;
V_551 = F_104 ( V_551 ,
( ( V_553 << V_169 ) / V_554 ) ) ;
* V_191 =
V_551 / ( ( V_553 << V_169 ) / V_554 ) ;
* V_550 = ( ( V_553 << V_169 ) / V_554 ) ;
* V_549 = V_551 / V_162 ;
return 0 ;
}
static int F_105 ( struct V_8 * V_9 )
{
int V_169 ;
int V_41 = 0 ;
int V_555 ;
struct V_556 * V_174 ;
struct V_557 * V_188 ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 ;
struct V_559 * V_560 ;
V_174 = F_19 ( V_561 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_555 = V_562 ;
V_9 -> V_563 . V_159 = sizeof( struct V_564 ) * V_555 ;
V_174 -> V_565 = ( V_566 <<
V_567 ) &
V_568 ;
for ( V_169 = 0 ; V_169 < V_552 ; V_169 ++ ) {
if ( V_569 == ( V_213 << V_169 ) )
break;
}
V_174 -> V_565 |= ( V_169 << V_570 ) &
V_571 ;
V_174 -> V_565 |= ( sizeof( struct V_564 ) <<
V_572 ) &
V_573 ;
V_9 -> V_563 . V_574 . V_4 = F_24 ( & V_158 -> V_9 , V_569 ,
& V_9 -> V_563 . V_574 . V_195 ,
V_145 ) ;
if ( V_9 -> V_563 . V_574 . V_4 == NULL )
goto V_575;
V_9 -> V_563 . V_4 = F_24 ( & V_158 -> V_9 , V_9 -> V_563 . V_159 ,
& V_195 , V_145 ) ;
if ( V_9 -> V_563 . V_4 == NULL )
goto V_576;
V_9 -> V_563 . V_195 = V_195 ;
V_9 -> V_563 . V_577 = V_555 ;
memset ( V_9 -> V_563 . V_4 , 0 , V_9 -> V_563 . V_159 ) ;
V_560 = (struct V_559 * ) V_9 -> V_563 . V_574 . V_4 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_563 . V_159 / V_213 ; V_169 ++ ) {
V_560 [ V_169 ] . V_475 = ( T_1 ) F_106 ( V_195 & 0xffffffff ) ;
V_560 [ V_169 ] . V_476 = ( T_1 ) F_106 ( F_26 ( V_195 ) ) ;
V_195 += V_569 ;
}
V_174 -> V_578 [ 0 ] . V_170 = ( T_1 ) ( V_9 -> V_563 . V_574 . V_195 & 0xFFFFFFFF ) ;
V_174 -> V_578 [ 0 ] . V_171 = ( T_1 ) F_26 ( V_9 -> V_563 . V_574 . V_195 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_557 * ) V_174 ;
V_9 -> V_563 . V_579 = V_188 -> V_579 & 0xFFFF ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
F_22 ( & V_158 -> V_9 , V_9 -> V_563 . V_159 , V_9 -> V_563 . V_4 ,
V_9 -> V_563 . V_195 ) ;
V_9 -> V_563 . V_4 = NULL ;
V_576:
F_22 ( & V_158 -> V_9 , V_569 , V_9 -> V_563 . V_574 . V_4 ,
V_9 -> V_563 . V_574 . V_195 ) ;
V_9 -> V_563 . V_574 . V_4 = NULL ;
V_9 -> V_563 . V_159 = 0 ;
V_575:
F_87 ( V_174 ) ;
return V_41 ;
}
static void F_107 ( struct V_8 * V_9 )
{
struct V_580 * V_174 ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
if ( V_9 -> V_563 . V_4 == NULL )
return;
V_174 = F_19 ( V_581 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return;
V_174 -> V_579 = V_9 -> V_563 . V_579 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_22 ( & V_158 -> V_9 , V_9 -> V_563 . V_159 , V_9 -> V_563 . V_4 ,
V_9 -> V_563 . V_195 ) ;
V_9 -> V_563 . V_4 = NULL ;
F_22 ( & V_158 -> V_9 , V_569 , V_9 -> V_563 . V_574 . V_4 ,
V_9 -> V_563 . V_574 . V_195 ) ;
F_87 ( V_174 ) ;
}
static T_3 F_108 ( struct V_8 * V_9 )
{
int V_169 , V_582 = 0 , V_236 = 0 ;
T_3 V_124 ;
F_47 ( & V_9 -> V_583 ) ;
V_236 = V_9 -> V_207 [ 0 ] . V_236 ;
V_124 = V_9 -> V_207 [ 0 ] . V_3 . V_120 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
if ( V_9 -> V_207 [ V_169 ] . V_236 < V_236 ) {
V_236 = V_9 -> V_207 [ V_169 ] . V_236 ;
V_124 = V_9 -> V_207 [ V_169 ] . V_3 . V_120 ;
V_582 = V_169 ;
}
}
V_9 -> V_207 [ V_582 ] . V_236 += 1 ;
F_48 ( & V_9 -> V_583 ) ;
return V_124 ;
}
static void F_109 ( struct V_8 * V_9 , T_3 V_124 )
{
int V_169 ;
F_47 ( & V_9 -> V_583 ) ;
V_169 = F_110 ( V_9 , V_124 ) ;
if ( V_169 == - V_72 )
F_28 () ;
V_9 -> V_207 [ V_169 ] . V_236 -= 1 ;
F_48 ( & V_9 -> V_583 ) ;
}
int F_111 ( struct V_8 * V_9 , struct V_248 * V_13 ,
int V_584 , int V_585 , T_3 V_586 )
{
int V_41 = - V_163 ; int V_587 ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
struct V_588 * V_174 ;
struct V_589 * V_188 ;
T_1 V_590 , V_591 , V_550 , V_592 ;
if ( V_584 > V_9 -> V_265 . V_429 ) {
F_52 ( L_17 ,
V_299 , V_9 -> V_120 , V_9 -> V_265 . V_429 , V_584 ) ;
return - V_72 ;
}
if ( V_585 && ( F_84 ( V_9 ) != V_445 ) )
return - V_72 ;
if ( V_585 ) {
V_13 -> V_587 = 1 ;
V_587 = 1 ;
V_591 = V_593 ;
V_590 = 1 ;
} else {
V_13 -> V_587 = V_9 -> V_265 . V_429 ;
V_587 = V_9 -> V_265 . V_429 ;
V_591 = sizeof( struct V_594 ) ;
V_590 = V_595 ;
}
V_13 -> V_161 = F_104 ( V_587 * V_591 , V_213 ) ;
V_174 = F_19 ( V_210 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( & V_174 -> V_174 . V_182 , V_210 ,
V_183 , sizeof( * V_174 ) ) ;
V_13 -> V_4 = F_24 ( & V_158 -> V_9 , V_13 -> V_161 , & V_13 -> V_195 , V_145 ) ;
if ( ! V_13 -> V_4 ) {
V_41 = - V_163 ;
goto V_575;
}
memset ( V_13 -> V_4 , 0 , V_13 -> V_161 ) ;
V_550 = V_13 -> V_161 / V_590 ;
V_174 -> V_174 . V_212 = ( V_550 / V_213 ) <<
V_214 ;
V_174 -> V_174 . V_212 |= V_590 ;
V_174 -> V_174 . V_215 = V_216 ;
V_13 -> V_217 = F_108 ( V_9 ) ;
V_174 -> V_174 . V_182 . V_190 = V_596 ;
V_592 = V_13 -> V_161 / V_591 ;
V_13 -> V_597 = V_592 ;
if ( V_592 > 1024 ) {
V_174 -> V_174 . V_215 |= ( 0x3 << V_598 ) ;
} else {
T_2 V_599 = 0 ;
switch ( V_592 ) {
case 256 :
V_599 = 0 ;
break;
case 512 :
V_599 = 1 ;
break;
case 1024 :
V_599 = 2 ;
break;
default:
goto V_200;
}
V_174 -> V_174 . V_215 |= ( V_599 << V_598 ) ;
}
V_174 -> V_174 . V_217 = V_13 -> V_217 ;
if ( F_84 ( V_9 ) == V_445 ) {
if ( V_585 )
V_174 -> V_174 . V_212 |= V_600 <<
V_601 ;
V_13 -> V_602 = false ;
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_591 ) ;
} else {
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_591 ) - 1 ;
V_174 -> V_174 . V_215 |= V_603 ;
V_13 -> V_602 = true ;
}
V_174 -> V_174 . V_218 |= ( V_586 <<
V_604 ) ;
F_25 ( & V_174 -> V_174 . V_195 [ 0 ] , V_590 , V_13 -> V_195 , V_550 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_589 * ) V_174 ;
V_13 -> V_120 = ( T_3 ) ( V_188 -> V_188 . V_106 & V_219 ) ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
F_109 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
V_575:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_112 ( struct V_8 * V_9 , struct V_248 * V_13 )
{
int V_41 = - V_163 ;
struct V_605 * V_174 ;
V_174 = F_19 ( V_179 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_182 , V_179 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_606 |=
( V_13 -> V_120 << V_607 ) &
V_608 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_109 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_113 ( struct V_8 * V_9 , struct V_609 * V_610 ,
T_1 V_611 , int V_612 )
{
int V_41 = - V_163 ;
struct V_613 * V_174 ;
struct V_614 * V_188 ;
V_174 = F_19 ( V_615 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_611 = V_611 ;
V_174 -> V_616 |= V_612 ;
V_174 -> V_616 |= ( V_610 -> V_617 << V_618 ) ;
V_174 -> V_616 |=
( V_610 -> V_619 << V_620 ) ;
V_174 -> V_616 |=
( V_610 -> V_621 << V_622 ) ;
V_174 -> V_616 |=
( V_610 -> V_623 << V_624 ) ;
V_174 -> V_616 |=
( V_610 -> V_625 << V_626 ) ;
V_174 -> V_616 |=
( V_610 -> V_627 << V_628 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_614 * ) V_174 ;
V_610 -> V_629 = V_188 -> V_630 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_114 ( struct V_8 * V_9 , int V_617 , T_1 V_629 )
{
int V_41 = - V_163 ;
struct V_631 * V_174 ;
V_174 = F_19 ( V_632 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_629 = V_629 ;
V_174 -> V_633 = V_617 ? 1 : 0 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_115 ( struct V_8 * V_9 , struct V_609 * V_610 ,
T_1 V_611 , T_1 V_634 , T_1 V_635 , T_1 V_636 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_637 * V_174 ;
struct V_638 * V_188 ;
V_174 = F_19 ( V_639 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_640 =
V_611 | ( V_610 -> V_627 << V_641 ) ;
V_174 -> V_617 = V_610 -> V_617 ;
V_174 -> V_642 |= ( V_610 -> V_619 <<
V_643 ) ;
V_174 -> V_642 |= ( V_610 -> V_621 <<
V_644 ) ;
V_174 -> V_642 |= ( V_610 -> V_623 <<
V_645 ) ;
V_174 -> V_642 |= ( V_610 -> V_625 <<
V_646 ) ;
V_174 -> V_642 |= ( V_610 -> V_647 <<
V_648 ) ;
V_174 -> V_642 |= ( V_636 << V_649 ) ;
V_174 -> V_642 |= ( V_610 -> V_635 / V_650 ) ;
V_174 -> V_642 |= ( V_610 -> V_651 / V_650 ) <<
V_652 ;
V_174 -> V_653 = V_610 -> V_161 ;
V_174 -> V_654 = F_26 ( V_610 -> V_161 ) ;
V_174 -> V_655 = ( T_1 ) ( V_610 -> V_656 & 0xffffffff ) ;
V_174 -> V_657 = ( T_1 ) F_26 ( V_610 -> V_656 ) ;
V_174 -> V_658 = ( T_1 ) V_610 -> V_4 ;
V_174 -> V_659 = ( T_1 ) F_26 ( V_610 -> V_4 ) ;
for ( V_169 = 0 ; V_169 < V_634 ; V_169 ++ ) {
V_174 -> V_574 [ V_169 ] . V_170 = ( T_1 ) ( V_610 -> V_660 [ V_169 ] . V_195 & 0xffffffff ) ;
V_174 -> V_574 [ V_169 ] . V_171 = F_26 ( V_610 -> V_660 [ V_169 ] . V_195 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_638 * ) V_174 ;
V_610 -> V_629 = V_188 -> V_630 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_116 ( struct V_8 * V_9 ,
struct V_609 * V_610 , T_1 V_634 ,
T_1 V_661 , T_1 V_636 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_662 * V_174 ;
V_174 = F_19 ( V_663 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_630 = V_610 -> V_629 ;
V_174 -> V_664 = ( V_634 << V_665 ) |
( V_661 & V_666 ) ;
V_174 -> V_636 = V_636 << V_667 ;
for ( V_169 = 0 ; V_169 < V_634 ; V_169 ++ ) {
V_174 -> V_574 [ V_169 ] . V_170 =
( T_1 ) ( V_610 -> V_660 [ V_169 + V_661 ] . V_195 & 0xffffffff ) ;
V_174 -> V_574 [ V_169 ] . V_171 =
F_26 ( V_610 -> V_660 [ V_169 + V_661 ] . V_195 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_117 ( struct V_8 * V_9 ,
struct V_609 * V_610 , T_1 V_611 , int V_668 )
{
int V_41 ;
T_1 V_636 = 0 ;
T_1 V_669 , V_661 ;
T_1 V_670 = V_610 -> V_627 ;
V_661 = 0 ;
V_669 = F_118 ( V_670 , V_671 ) ;
if ( V_669 == V_670 )
V_636 = 1 ;
V_41 = F_115 ( V_9 , V_610 , V_611 ,
V_669 , V_610 -> V_635 , V_636 ) ;
if ( V_41 ) {
F_52 ( L_18 , V_299 , V_41 ) ;
return V_41 ;
}
if ( V_636 )
return 0 ;
while ( ! V_636 ) {
V_661 += V_669 ;
V_670 -= V_669 ;
V_669 = F_118 ( V_670 , V_671 ) ;
if ( V_669 == V_670 )
V_636 = 1 ;
V_41 = F_116 ( V_9 , V_610 , V_669 ,
V_661 , V_636 ) ;
if ( V_41 )
break;
}
if ( V_41 )
F_52 ( L_19 , V_299 , V_41 ) ;
return V_41 ;
}
bool F_119 ( struct V_248 * V_13 , struct V_243 * V_244 )
{
struct V_243 * V_672 ;
bool V_673 = false ;
F_120 (tmp, &cq->sq_head, sq_entry) {
if ( V_244 == V_672 ) {
V_673 = true ;
break;
}
}
return V_673 ;
}
bool F_121 ( struct V_248 * V_13 , struct V_243 * V_244 )
{
struct V_243 * V_672 ;
bool V_673 = false ;
F_120 (tmp, &cq->rq_head, rq_entry) {
if ( V_244 == V_672 ) {
V_673 = true ;
break;
}
}
return V_673 ;
}
void F_122 ( struct V_243 * V_244 )
{
bool V_673 ;
unsigned long V_322 ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
F_69 ( & V_9 -> V_347 , V_322 ) ;
V_673 = F_119 ( V_244 -> V_345 , V_244 ) ;
if ( ! V_673 )
F_124 ( & V_244 -> V_343 , & V_244 -> V_345 -> V_341 ) ;
if ( ! V_244 -> V_292 ) {
V_673 = F_121 ( V_244 -> V_346 , V_244 ) ;
if ( ! V_673 )
F_124 ( & V_244 -> V_344 , & V_244 -> V_346 -> V_342 ) ;
}
F_70 ( & V_9 -> V_347 , V_322 ) ;
}
static void F_125 ( struct V_243 * V_244 )
{
V_244 -> V_18 . V_19 = 0 ;
V_244 -> V_18 . V_5 = 0 ;
V_244 -> V_674 . V_19 = 0 ;
V_244 -> V_674 . V_5 = 0 ;
}
int F_50 ( struct V_243 * V_244 , enum V_23 V_675 ,
enum V_23 * V_676 )
{
unsigned long V_322 ;
int V_41 = 0 ;
enum V_24 V_677 ;
V_677 = F_10 ( V_675 ) ;
F_69 ( & V_244 -> V_678 , V_322 ) ;
if ( V_676 )
* V_676 = F_9 ( V_244 -> V_679 ) ;
if ( V_677 == V_244 -> V_679 ) {
F_70 ( & V_244 -> V_678 , V_322 ) ;
return 1 ;
}
if ( V_677 == V_28 ) {
F_125 ( V_244 ) ;
F_126 ( V_244 ) ;
} else if ( V_677 == V_39 ) {
F_122 ( V_244 ) ;
}
V_244 -> V_679 = V_677 ;
F_70 ( & V_244 -> V_678 , V_322 ) ;
return V_41 ;
}
static T_1 F_127 ( struct V_243 * V_244 )
{
T_1 V_322 = 0 ;
if ( V_244 -> V_680 & V_681 )
V_322 |= V_682 ;
if ( V_244 -> V_680 & V_683 )
V_322 |= V_684 ;
if ( V_244 -> V_680 & V_685 )
V_322 |= V_686 ;
if ( V_244 -> V_680 & V_687 )
V_322 |= V_688 ;
if ( V_244 -> V_680 & V_689 )
V_322 |= V_690 ;
return V_322 ;
}
static int F_128 ( struct V_691 * V_174 ,
struct V_692 * V_693 ,
struct V_243 * V_244 )
{
int V_41 ;
T_1 V_161 , V_590 , V_168 ;
T_4 V_195 ;
struct V_514 * V_515 = V_244 -> V_515 ;
struct V_8 * V_9 = F_123 ( V_515 -> V_694 . V_271 ) ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_695 ;
T_1 V_696 = V_693 -> V_697 . V_392 ;
V_695 = F_129 ( T_1 , V_693 -> V_697 . V_698 + 1 ,
V_9 -> V_265 . V_450 ) ;
V_41 = F_102 ( & V_695 ,
V_9 -> V_265 . V_434 , & V_590 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_20 , V_299 ,
V_695 ) ;
return - V_72 ;
}
V_244 -> V_18 . V_699 = V_695 ;
V_161 = ( V_590 * V_168 ) ;
V_244 -> V_18 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_244 -> V_18 . V_4 )
return - V_72 ;
memset ( V_244 -> V_18 . V_4 , 0 , V_161 ) ;
V_244 -> V_18 . V_161 = V_161 ;
V_244 -> V_18 . V_195 = V_195 ;
V_244 -> V_18 . V_162 = V_9 -> V_265 . V_434 ;
F_25 ( & V_174 -> V_700 [ 0 ] , V_590 , V_195 , V_168 ) ;
V_174 -> V_701 |= ( F_130 ( V_168 / V_213 )
<< V_702 ) ;
V_174 -> V_703 |= ( V_590 <<
V_704 ) &
V_705 ;
V_174 -> V_706 |= ( V_696 <<
V_707 ) &
V_708 ;
V_174 -> V_706 |= ( V_696 <<
V_709 ) &
V_710 ;
V_174 -> V_711 |= ( F_130 ( V_244 -> V_18 . V_699 ) <<
V_712 ) &
V_713 ;
V_174 -> V_714 |= ( V_9 -> V_265 . V_434 <<
V_715 ) &
V_716 ;
return 0 ;
}
static int F_131 ( struct V_691 * V_174 ,
struct V_692 * V_693 ,
struct V_243 * V_244 )
{
int V_41 ;
T_1 V_161 , V_590 , V_168 ;
T_4 V_195 = 0 ;
struct V_514 * V_515 = V_244 -> V_515 ;
struct V_8 * V_9 = F_123 ( V_515 -> V_694 . V_271 ) ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_717 = V_693 -> V_697 . V_718 + 1 ;
V_41 = F_102 ( & V_717 , V_9 -> V_265 . V_439 ,
& V_590 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_21 , V_299 ,
V_693 -> V_697 . V_718 + 1 ) ;
return V_41 ;
}
V_244 -> V_674 . V_699 = V_717 ;
V_161 = ( V_590 * V_168 ) ;
V_244 -> V_674 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_244 -> V_674 . V_4 )
return - V_163 ;
memset ( V_244 -> V_674 . V_4 , 0 , V_161 ) ;
V_244 -> V_674 . V_195 = V_195 ;
V_244 -> V_674 . V_161 = V_161 ;
V_244 -> V_674 . V_162 = V_9 -> V_265 . V_439 ;
F_25 ( & V_174 -> V_719 [ 0 ] , V_590 , V_195 , V_168 ) ;
V_174 -> V_701 |= ( F_130 ( V_168 / V_213 ) <<
V_720 ) ;
V_174 -> V_703 |=
( V_590 << V_721 ) &
V_722 ;
V_174 -> V_723 |= ( V_693 -> V_697 . V_396 <<
V_724 ) &
V_725 ;
V_174 -> V_711 |= ( F_130 ( V_244 -> V_674 . V_699 ) <<
V_726 ) &
V_727 ;
V_174 -> V_714 |= ( V_9 -> V_265 . V_439 <<
V_728 ) &
V_729 ;
return 0 ;
}
static void F_132 ( struct V_691 * V_174 ,
struct V_514 * V_515 ,
struct V_243 * V_244 ,
T_2 V_730 , T_3 V_731 )
{
V_515 -> V_527 -- ;
V_244 -> V_519 = true ;
V_174 -> V_723 |= V_732 ;
if ( ! V_730 )
return;
V_174 -> V_723 |= V_732 ;
V_174 -> V_733 = V_731 ;
V_174 -> V_733 |= V_734 <<
V_735 ;
}
static int F_133 ( struct V_691 * V_174 ,
struct V_243 * V_244 )
{
struct V_514 * V_515 = V_244 -> V_515 ;
struct V_8 * V_9 = F_123 ( V_515 -> V_694 . V_271 ) ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 = 0 ;
int V_447 = V_9 -> V_265 . V_447 ;
int V_736 = V_9 -> V_265 . V_448 * V_447 ;
struct V_443 * V_737 ;
int V_169 = 0 ;
if ( V_9 -> V_265 . V_446 == 0 )
return 0 ;
V_244 -> V_738 = F_24 ( & V_158 -> V_9 , V_736 ,
& V_195 , V_145 ) ;
if ( ! V_244 -> V_738 )
return - V_163 ;
memset ( V_244 -> V_738 , 0 , V_736 ) ;
F_25 ( & V_174 -> V_739 [ 0 ] , V_9 -> V_265 . V_448 ,
V_195 , V_447 ) ;
for (; V_169 < V_736 / V_9 -> V_265 . V_439 ; V_169 ++ ) {
V_737 = (struct V_443 * ) ( V_244 -> V_738 +
( V_169 * V_9 -> V_265 . V_439 ) ) ;
V_737 -> V_740 = 0 ;
V_737 -> V_740 |= 2 ;
V_737 -> V_740 |= ( V_741 << V_742 ) ;
V_737 -> V_740 |= ( 8 << V_743 ) ;
V_737 -> V_740 |= ( 8 << V_744 ) ;
}
return 0 ;
}
static void F_134 ( struct V_745 * V_188 ,
struct V_243 * V_244 ,
struct V_692 * V_693 ,
T_3 * V_746 , T_3 * V_747 )
{
T_1 V_695 , V_717 ;
V_244 -> V_120 = V_188 -> V_748 & V_749 ;
V_244 -> V_674 . V_750 = V_188 -> V_751 & V_752 ;
V_244 -> V_18 . V_750 = V_188 -> V_751 >> V_753 ;
V_244 -> V_754 = V_188 -> V_755 & V_756 ;
V_244 -> V_757 = ( V_188 -> V_755 >> V_758 ) ;
V_244 -> V_519 = false ;
if ( V_188 -> V_759 & V_760 ) {
V_244 -> V_519 = true ;
* V_747 = ( V_188 -> V_759 &
V_761 ) >>
V_762 ;
* V_746 = ( V_188 -> V_759 &
V_763 ) >>
V_764 ;
}
V_695 =
V_188 -> V_711 >> V_765 ;
V_695 = 1 << V_695 ;
V_717 = 1 << ( ( T_3 ) V_188 -> V_711 ) ;
V_244 -> V_18 . V_699 = V_695 ;
V_244 -> V_18 . V_766 = V_695 - 1 ;
if ( ! V_693 -> V_292 ) {
V_244 -> V_674 . V_699 = V_717 ;
V_244 -> V_674 . V_766 = V_717 - 1 ;
}
}
int F_135 ( struct V_243 * V_244 , struct V_692 * V_693 ,
T_2 V_730 , T_3 V_731 , T_3 * V_746 ,
T_3 * V_747 )
{
int V_41 = - V_163 ;
T_1 V_322 = 0 ;
struct V_514 * V_515 = V_244 -> V_515 ;
struct V_8 * V_9 = F_123 ( V_515 -> V_694 . V_271 ) ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
struct V_248 * V_13 ;
struct V_691 * V_174 ;
struct V_745 * V_188 ;
int V_767 ;
switch ( V_693 -> V_768 ) {
case V_769 :
V_767 = V_770 ;
break;
case V_771 :
V_767 = V_772 ;
break;
case V_773 :
V_767 = V_774 ;
break;
default:
return - V_72 ;
}
V_174 = F_19 ( V_775 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_701 |= ( V_767 << V_776 ) &
V_777 ;
V_41 = F_128 ( V_174 , V_693 , V_244 ) ;
if ( V_41 )
goto V_778;
if ( V_693 -> V_292 ) {
struct V_779 * V_292 = F_136 ( V_693 -> V_292 ) ;
V_174 -> V_723 |= V_780 ;
V_174 -> V_719 [ 0 ] . V_170 = V_292 -> V_120 ;
V_244 -> V_292 = V_292 ;
} else {
V_41 = F_131 ( V_174 , V_693 , V_244 ) ;
if ( V_41 )
goto V_781;
}
V_41 = F_133 ( V_174 , V_244 ) ;
if ( V_41 )
goto V_200;
V_174 -> V_701 |= ( V_515 -> V_120 << V_782 ) &
V_783 ;
V_322 = F_127 ( V_244 ) ;
V_174 -> V_723 |= V_322 ;
V_174 -> V_755 |= ( V_9 -> V_265 . V_404 <<
V_784 ) &
V_785 ;
V_174 -> V_755 |= ( V_9 -> V_265 . V_408 <<
V_786 ) &
V_787 ;
V_13 = F_137 ( V_693 -> V_788 ) ;
V_174 -> V_789 |= ( V_13 -> V_120 << V_790 ) &
V_791 ;
V_244 -> V_345 = V_13 ;
V_13 = F_137 ( V_693 -> V_792 ) ;
V_174 -> V_789 |= ( V_13 -> V_120 << V_793 ) &
V_794 ;
V_244 -> V_346 = V_13 ;
if ( V_515 -> V_519 && V_693 -> V_697 . V_442 && V_515 -> V_527 &&
( V_693 -> V_697 . V_442 <= V_9 -> V_265 . V_442 ) ) {
F_132 ( V_174 , V_515 , V_244 , V_730 ,
V_731 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_745 * ) V_174 ;
F_134 ( V_188 , V_244 , V_693 , V_746 , V_747 ) ;
V_244 -> V_679 = V_26 ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
if ( V_244 -> V_674 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_674 . V_161 , V_244 -> V_674 . V_4 , V_244 -> V_674 . V_195 ) ;
V_781:
F_52 ( L_22 , V_299 , V_9 -> V_120 ) ;
F_22 ( & V_158 -> V_9 , V_244 -> V_18 . V_161 , V_244 -> V_18 . V_4 , V_244 -> V_18 . V_195 ) ;
V_778:
F_52 ( L_23 , V_299 , V_9 -> V_120 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_138 ( struct V_8 * V_9 , struct V_243 * V_244 ,
struct V_795 * V_796 )
{
int V_41 = - V_163 ;
struct V_797 * V_174 ;
struct V_798 * V_188 ;
V_174 = F_19 ( V_799 , sizeof( * V_188 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_748 = V_244 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_798 * ) V_174 ;
memcpy ( V_796 , & V_188 -> V_800 , sizeof( struct V_795 ) ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_139 ( struct V_243 * V_244 ,
struct V_801 * V_174 ,
struct V_802 * V_693 ,
int V_803 )
{
int V_41 ;
struct V_804 * V_805 = & V_693 -> V_805 ;
union V_806 V_807 , V_808 ;
struct V_809 V_810 ;
T_1 V_811 = 0xFFFF ;
T_2 V_812 [ 6 ] ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
if ( ( V_805 -> V_813 & V_814 ) == 0 )
return - V_72 ;
if ( F_140 ( & V_9 -> V_317 , 1 , 0 ) )
F_141 ( V_9 ) ;
V_174 -> V_800 . V_815 |=
( V_805 -> V_816 . V_817 << V_818 ) ;
V_174 -> V_800 . V_819 |=
( V_805 -> V_816 . V_820 & V_821 ) ;
V_174 -> V_800 . V_819 |= ( V_805 -> V_822 << V_823 ) ;
V_174 -> V_800 . V_824 |=
( V_805 -> V_816 . V_825 << V_826 ) ;
V_174 -> V_322 |= V_827 ;
memcpy ( & V_174 -> V_800 . V_828 [ 0 ] , & V_805 -> V_816 . V_828 . V_829 [ 0 ] ,
sizeof( V_174 -> V_800 . V_828 ) ) ;
V_41 = F_142 ( & V_9 -> V_272 , 1 , V_805 -> V_816 . V_830 ,
& V_807 , & V_810 ) ;
if ( ! V_41 && V_810 . V_831 ) {
V_811 = F_143 ( V_810 . V_831 ) ;
memcpy ( V_812 , V_810 . V_831 -> V_832 , V_833 ) ;
F_144 ( V_810 . V_831 ) ;
}
memset ( & V_808 , 0 , sizeof( V_808 ) ) ;
if ( ! memcmp ( & V_807 , & V_808 , sizeof( V_808 ) ) )
return - V_72 ;
V_244 -> V_834 = V_805 -> V_816 . V_830 ;
memcpy ( & V_174 -> V_800 . V_807 [ 0 ] , & V_807 . V_829 [ 0 ] , sizeof( V_174 -> V_800 . V_807 ) ) ;
V_41 = F_145 ( V_9 , V_805 , & V_812 [ 0 ] ) ;
if ( V_41 )
return V_41 ;
V_174 -> V_800 . V_835 = V_812 [ 0 ] | ( V_812 [ 1 ] << 8 ) |
( V_812 [ 2 ] << 16 ) | ( V_812 [ 3 ] << 24 ) ;
F_146 ( & V_174 -> V_800 . V_828 [ 0 ] , sizeof( V_174 -> V_800 . V_828 ) ) ;
F_146 ( & V_174 -> V_800 . V_807 [ 0 ] , sizeof( V_174 -> V_800 . V_807 ) ) ;
V_174 -> V_800 . V_836 = V_812 [ 4 ] | ( V_812 [ 5 ] << 8 ) ;
if ( V_811 == 0xFFFF )
V_811 = 0 ;
if ( V_811 || V_9 -> V_837 ) {
if ( ! V_811 ) {
F_52 ( L_24 ,
V_9 -> V_120 ) ;
F_52 ( L_25 ,
V_9 -> V_120 ) ;
}
V_174 -> V_800 . V_836 |=
V_811 << V_838 ;
V_174 -> V_322 |= V_839 ;
V_174 -> V_800 . V_819 |=
( V_9 -> V_822 & 0x07 ) << V_823 ;
}
return 0 ;
}
static int F_147 ( struct V_243 * V_244 ,
struct V_801 * V_174 ,
struct V_802 * V_693 , int V_803 )
{
int V_41 = 0 ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
if ( V_803 & V_840 ) {
V_174 -> V_800 . V_841 |= ( V_693 -> V_842 &
V_843 ) ;
V_174 -> V_322 |= V_844 ;
}
if ( V_803 & V_845 ) {
V_244 -> V_846 = V_693 -> V_846 ;
V_174 -> V_800 . V_846 = V_693 -> V_846 ;
V_174 -> V_322 |= V_847 ;
}
if ( V_803 & V_848 ) {
V_41 = F_139 ( V_244 , V_174 , V_693 , V_803 ) ;
if ( V_41 )
return V_41 ;
} else if ( V_244 -> V_768 == V_769 || V_244 -> V_768 == V_773 ) {
V_174 -> V_800 . V_835 = V_9 -> V_117 . V_812 [ 0 ] |
( V_9 -> V_117 . V_812 [ 1 ] << 8 ) |
( V_9 -> V_117 . V_812 [ 2 ] << 16 ) |
( V_9 -> V_117 . V_812 [ 3 ] << 24 ) ;
V_174 -> V_800 . V_836 = V_9 -> V_117 . V_812 [ 4 ] |
( V_9 -> V_117 . V_812 [ 5 ] << 8 ) ;
}
if ( ( V_803 & V_849 ) &&
V_693 -> V_850 ) {
V_174 -> V_800 . V_723 |=
V_851 ;
V_174 -> V_322 |= V_852 ;
}
if ( V_803 & V_853 ) {
V_174 -> V_800 . V_854 |= ( V_693 -> V_855 &
V_856 ) ;
V_174 -> V_322 |= V_852 ;
}
if ( V_803 & V_857 ) {
if ( V_693 -> V_858 < V_859 ||
V_693 -> V_858 > V_860 ) {
F_52 ( L_26 ,
V_9 -> V_120 , F_148 ( V_693 -> V_858 ) ) ;
V_41 = - V_72 ;
goto V_861;
}
V_174 -> V_800 . V_841 |=
( F_148 ( V_693 -> V_858 ) <<
V_862 ) &
V_863 ;
V_174 -> V_322 |= V_864 ;
}
if ( V_803 & V_865 ) {
V_174 -> V_800 . V_854 |= V_693 -> V_143 <<
V_866 ;
V_174 -> V_322 |= V_867 ;
}
if ( V_803 & V_868 ) {
V_174 -> V_800 . V_819 |= ( V_693 -> V_869 <<
V_870 ) &
V_871 ;
V_174 -> V_322 |= V_872 ;
}
if ( V_803 & V_873 ) {
V_174 -> V_800 . V_819 |= ( V_693 -> V_874 <<
V_875 ) &
V_876 ;
V_174 -> V_322 |= V_877 ;
}
if ( V_803 & V_878 ) {
V_174 -> V_800 . V_854 |= ( V_693 -> V_879 <<
V_880 )
& V_881 ;
V_174 -> V_322 |= V_882 ;
}
if ( V_803 & V_883 ) {
V_174 -> V_800 . V_815 |= ( V_693 -> V_884 & 0x00ffffff ) ;
V_174 -> V_322 |= V_885 ;
}
if ( V_803 & V_886 ) {
V_174 -> V_800 . V_824 |= ( V_693 -> V_887 & 0x00ffffff ) ;
V_174 -> V_322 |= V_888 ;
}
if ( V_803 & V_889 ) {
if ( V_693 -> V_890 > V_9 -> V_265 . V_404 ) {
V_41 = - V_72 ;
goto V_861;
}
V_244 -> V_757 = V_693 -> V_890 ;
V_174 -> V_322 |= V_891 ;
}
if ( V_803 & V_892 ) {
if ( V_693 -> V_893 > V_9 -> V_265 . V_408 ) {
V_41 = - V_72 ;
goto V_861;
}
V_244 -> V_754 = V_693 -> V_893 ;
V_174 -> V_322 |= V_894 ;
}
V_174 -> V_800 . V_755 = ( V_244 -> V_757 <<
V_895 ) |
( V_244 -> V_754 & V_896 ) ;
V_861:
return V_41 ;
}
int F_149 ( struct V_8 * V_9 , struct V_243 * V_244 ,
struct V_802 * V_693 , int V_803 )
{
int V_41 = - V_163 ;
struct V_801 * V_174 ;
V_174 = F_19 ( V_897 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_800 . V_120 = V_244 -> V_120 ;
V_174 -> V_322 = 0 ;
if ( V_803 & V_898 ) {
V_174 -> V_800 . V_723 |=
( F_10 ( V_693 -> V_899 ) <<
V_900 ) &
V_901 ;
V_174 -> V_322 |= V_902 ;
} else {
V_174 -> V_800 . V_723 |=
( V_244 -> V_679 << V_900 ) &
V_901 ;
}
V_41 = F_147 ( V_244 , V_174 , V_693 , V_803 ) ;
if ( V_41 )
goto V_200;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_150 ( struct V_8 * V_9 , struct V_243 * V_244 )
{
int V_41 = - V_163 ;
struct V_903 * V_174 ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_904 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_748 = V_244 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
if ( V_244 -> V_18 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_18 . V_161 , V_244 -> V_18 . V_4 , V_244 -> V_18 . V_195 ) ;
if ( ! V_244 -> V_292 && V_244 -> V_674 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_674 . V_161 , V_244 -> V_674 . V_4 , V_244 -> V_674 . V_195 ) ;
if ( V_244 -> V_519 )
V_244 -> V_515 -> V_527 ++ ;
return V_41 ;
}
int F_151 ( struct V_8 * V_9 , struct V_779 * V_292 ,
struct V_905 * V_906 ,
struct V_514 * V_515 )
{
int V_41 = - V_163 ;
int V_590 , V_168 ;
int V_161 ;
struct V_907 * V_188 ;
struct V_908 * V_174 ;
T_4 V_195 ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_717 ;
V_174 = F_19 ( V_909 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_910 = V_515 -> V_120 & V_911 ;
V_717 = V_906 -> V_265 . V_912 + 1 ;
V_41 = F_102 ( & V_717 ,
V_9 -> V_265 . V_439 ,
& V_590 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_27 , V_299 ,
V_906 -> V_265 . V_912 ) ;
V_41 = - V_72 ;
goto V_913;
}
V_161 = V_590 * V_168 ;
V_292 -> V_674 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_292 -> V_674 . V_4 ) {
V_41 = - V_163 ;
goto V_913;
}
F_25 ( & V_174 -> V_719 [ 0 ] , V_590 , V_195 , V_168 ) ;
V_292 -> V_674 . V_162 = V_9 -> V_265 . V_439 ;
V_292 -> V_674 . V_195 = V_195 ;
V_292 -> V_674 . V_161 = V_161 ;
V_292 -> V_674 . V_699 = V_717 ;
V_174 -> V_914 = F_130 ( V_717 ) ;
V_174 -> V_914 |= V_906 -> V_265 . V_915 <<
V_916 ;
V_174 -> V_910 |= ( F_130 ( V_168 / V_213 )
<< V_917 ) ;
V_174 -> V_918 |= ( V_9 -> V_265 . V_439
<< V_919 )
& V_920 ;
V_174 -> V_918 |= V_590 << V_921 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_907 * ) V_174 ;
V_292 -> V_120 = V_188 -> V_120 ;
V_292 -> V_674 . V_750 = V_188 -> V_120 ;
V_717 = ( ( V_188 -> V_922 &
V_923 ) >>
V_924 ) ;
V_717 = ( 1 << V_717 ) ;
V_292 -> V_674 . V_699 = V_717 ;
V_292 -> V_674 . V_766 = V_717 - 1 ;
V_292 -> V_674 . V_696 = ( V_188 -> V_922 &
V_925 ) >>
V_926 ;
goto V_913;
V_200:
F_22 ( & V_158 -> V_9 , V_292 -> V_674 . V_161 , V_292 -> V_674 . V_4 , V_195 ) ;
V_913:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_152 ( struct V_779 * V_292 , struct V_927 * V_906 )
{
int V_41 = - V_163 ;
struct V_928 * V_174 ;
struct V_514 * V_515 = V_292 -> V_515 ;
struct V_8 * V_9 = F_123 ( V_515 -> V_694 . V_271 ) ;
V_174 = F_19 ( V_929 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_120 ;
V_174 -> V_930 |= V_906 -> V_931 <<
V_932 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_153 ( struct V_779 * V_292 , struct V_927 * V_906 )
{
int V_41 = - V_163 ;
struct V_933 * V_174 ;
struct V_8 * V_9 = F_123 ( V_292 -> V_293 . V_271 ) ;
V_174 = F_19 ( V_934 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_674 . V_750 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 == 0 ) {
struct V_935 * V_188 =
(struct V_935 * ) V_174 ;
V_906 -> V_915 =
V_188 -> V_936 &
V_937 ;
V_906 -> V_912 =
V_188 -> V_938 >> V_939 ;
V_906 -> V_931 = V_188 -> V_936 >>
V_940 ;
}
F_87 ( V_174 ) ;
return V_41 ;
}
int F_154 ( struct V_8 * V_9 , struct V_779 * V_292 )
{
int V_41 = - V_163 ;
struct V_941 * V_174 ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_942 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_292 -> V_674 . V_4 )
F_22 ( & V_158 -> V_9 , V_292 -> V_674 . V_161 ,
V_292 -> V_674 . V_4 , V_292 -> V_674 . V_195 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_155 ( struct V_8 * V_9 , T_1 V_943 ,
struct V_944 * V_945 )
{
int V_41 = 0 ;
T_4 V_195 ;
struct V_17 V_174 ;
struct V_946 * V_182 = NULL ;
struct V_947 * V_188 = NULL ;
struct V_558 * V_158 = V_9 -> V_117 . V_158 ;
struct V_948 * V_949 = V_174 . V_153 . V_473 . V_474 ;
memset ( & V_174 , 0 , sizeof( struct V_17 ) ) ;
V_174 . V_146 . V_151 = F_156 ( T_1 , sizeof( struct V_947 ) ,
sizeof( struct V_946 ) ) ;
V_182 = F_24 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , & V_195 , V_145 ) ;
if ( ! V_182 ) {
V_41 = - V_163 ;
goto V_575;
}
V_174 . V_146 . V_147 |= ( 1 << V_471 ) &
V_472 ;
V_949 -> V_475 = ( T_1 ) ( V_195 & 0xFFFFFFFFUL ) ;
V_949 -> V_476 = ( T_1 ) F_26 ( V_195 ) ;
V_949 -> V_161 = V_174 . V_146 . V_151 ;
memset ( V_182 , 0 , sizeof( struct V_946 ) ) ;
F_18 ( & V_182 -> V_146 , V_950 ,
V_951 , V_174 . V_146 . V_151 ) ;
V_182 -> V_952 = V_943 ;
V_41 = F_80 ( V_9 , & V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_947 * ) V_182 ;
F_64 ( V_188 , sizeof( struct V_947 ) ) ;
memcpy ( V_945 , & V_188 -> V_953 , sizeof( struct V_944 ) ) ;
V_200:
F_22 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , V_182 , V_195 ) ;
V_575:
return V_41 ;
}
static int F_157 ( struct V_8 * V_9 , int V_943 ,
struct V_944 * V_945 ,
T_2 * V_954 )
{
int V_41 = - V_72 , V_955 , V_956 ;
int V_957 ;
struct V_958 * V_959 ;
T_2 V_192 , V_960 ;
T_2 V_961 , V_962 ;
T_3 V_963 ;
if ( ! ( V_945 -> V_964 & V_965 ) ) {
F_158 ( L_28 ,
F_159 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
goto V_966;
}
if ( ! F_160 ( V_945 -> V_837 ) ) {
F_158 ( L_29 ,
F_159 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
( V_943 > 0 ? L_30 : L_31 ) ,
( V_945 -> V_837 & V_967 ) ?
L_32 : L_33 ,
( V_945 -> V_837 & V_968 ) ?
L_1 : L_34 ) ;
goto V_966;
} else {
F_158 ( L_35 ,
F_159 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
}
V_957 = ( V_945 -> V_964 >>
V_969 )
& V_965 ;
for ( V_955 = 0 ; V_955 < V_957 ; V_955 ++ ) {
V_959 = & V_945 -> V_959 [ V_955 ] ;
V_192 = ( V_959 -> V_970 >>
V_971 )
& V_972 ;
V_960 = ( V_959 -> V_970
>> V_973 )
& V_974 ;
V_963 = V_959 -> V_970 &
V_975 ;
if (
V_192 && V_963 == V_976 &&
V_960 == V_977 ) {
for ( V_956 = 0 ; V_956 <
V_978 ; V_956 ++ ) {
V_961 = F_161 (
( T_2 * ) V_959 -> V_961 ,
V_956 ) ;
V_962 = F_162 (
( T_2 * ) V_945 -> V_962 ,
V_956 ) ;
if ( V_961 && V_962 ) {
* V_954 = V_956 ;
V_41 = 0 ;
goto V_966;
}
}
if ( V_956 == V_978 ) {
F_158 ( L_36 ,
F_159 ( & V_9 -> V_117 . V_158 -> V_9 ) ,
V_9 -> V_120 , V_963 ) ;
}
}
}
V_966:
return V_41 ;
}
void F_141 ( struct V_8 * V_9 )
{
int V_41 = 0 , V_955 ;
struct V_944 V_945 ;
T_2 V_954 = V_979 ;
int V_943 = V_980 ;
for ( V_955 = 0 ; V_955 < 2 ; V_955 ++ ) {
V_41 = F_155 ( V_9 , V_943 , & V_945 ) ;
if ( V_41 ) {
F_52 ( L_37 , V_299 , V_41 ) ;
V_943 = V_981 ;
continue;
}
V_41 = F_157 ( V_9 , V_943 ,
& V_945 , & V_954 ) ;
if ( V_41 ) {
V_943 = V_981 ;
continue;
}
break;
}
if ( V_41 )
F_158 ( L_38 ,
F_159 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
else
F_158 ( L_39 ,
F_159 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
V_954 ) ;
V_9 -> V_837 = F_160 ( V_945 . V_837 ) ;
V_9 -> V_822 = V_954 ;
}
int F_163 ( struct V_8 * V_9 , struct V_982 * V_983 )
{
int V_169 ;
int V_41 = - V_72 ;
struct V_564 * V_984 ;
unsigned long V_322 ;
V_984 = V_9 -> V_563 . V_4 ;
F_69 ( & V_9 -> V_563 . V_239 , V_322 ) ;
for ( V_169 = 0 ; V_169 < V_9 -> V_563 . V_577 ; V_169 ++ ) {
if ( V_984 -> V_192 == 0 ) {
V_984 -> V_192 = V_985 ;
V_983 -> V_984 = V_984 ;
V_983 -> V_120 = V_169 ;
V_41 = 0 ;
break;
}
V_984 ++ ;
}
if ( V_169 == V_9 -> V_563 . V_577 )
V_41 = - V_51 ;
F_70 ( & V_9 -> V_563 . V_239 , V_322 ) ;
return V_41 ;
}
int F_164 ( struct V_8 * V_9 , struct V_982 * V_983 )
{
unsigned long V_322 ;
F_69 ( & V_9 -> V_563 . V_239 , V_322 ) ;
V_983 -> V_984 -> V_192 = 0 ;
F_70 ( & V_9 -> V_563 . V_239 , V_322 ) ;
return 0 ;
}
static int F_165 ( struct V_8 * V_9 )
{
int V_986 , V_169 , V_41 = 0 ;
int V_201 ;
unsigned long V_322 = 0 ;
V_986 = V_9 -> V_117 . V_204 . V_987 -
V_9 -> V_117 . V_204 . V_988 ;
if ( V_9 -> V_117 . V_202 == V_203 ) {
V_986 = 1 ;
V_322 = V_989 ;
} else {
V_986 = F_129 ( T_1 , V_986 , F_166 () ) ;
}
if ( ! V_986 )
return - V_72 ;
V_9 -> V_207 = F_20 ( sizeof( struct V_1 ) * V_986 , V_145 ) ;
if ( ! V_9 -> V_207 )
return - V_163 ;
for ( V_169 = 0 ; V_169 < V_986 ; V_169 ++ ) {
V_41 = F_31 ( V_9 , & V_9 -> V_207 [ V_169 ] ,
V_7 ) ;
if ( V_41 ) {
V_41 = - V_72 ;
break;
}
sprintf ( V_9 -> V_207 [ V_169 ] . V_990 , L_40 ,
V_9 -> V_120 , V_169 ) ;
V_201 = F_32 ( V_9 , & V_9 -> V_207 [ V_169 ] ) ;
V_41 = F_167 ( V_201 , F_73 , V_322 ,
V_9 -> V_207 [ V_169 ] . V_990 ,
& V_9 -> V_207 [ V_169 ] ) ;
if ( V_41 )
goto V_991;
V_9 -> V_206 += 1 ;
}
return 0 ;
V_991:
F_36 ( V_9 ) ;
return V_41 ;
}
static int F_168 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_992 )
{
int V_169 , V_41 = - V_163 ;
struct V_993 * V_174 ;
V_174 = F_19 ( V_994 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_174 . V_182 , V_994 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_174 . V_986 = V_992 ;
for ( V_169 = 0 ; V_169 < V_992 ; V_169 ++ ) {
V_174 -> V_174 . V_995 [ V_169 ] . V_124 = V_2 [ V_169 ] . V_3 . V_120 ;
V_174 -> V_174 . V_995 [ V_169 ] . V_996 = 0 ;
V_174 -> V_174 . V_995 [ V_169 ] . V_997 =
( V_2 [ V_169 ] . V_364 . V_998 * 65 ) / 100 ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_169 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_992 )
{
int V_999 , V_169 = 0 ;
if ( V_992 > 8 ) {
while ( V_992 ) {
V_999 = F_118 ( V_992 , 8 ) ;
F_168 ( V_9 , & V_2 [ V_169 ] , V_999 ) ;
V_169 += V_999 ;
V_992 -= V_999 ;
}
} else {
F_168 ( V_9 , V_2 , V_992 ) ;
}
return 0 ;
}
void F_170 ( struct V_1000 * V_1001 )
{
struct V_8 * V_9 =
F_171 ( V_1001 , struct V_8 , V_1002 . V_1001 ) ;
struct V_1 * V_2 = 0 ;
int V_169 , V_992 = 0 , V_41 = - V_72 ;
V_423 V_1003 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
V_2 = & V_9 -> V_207 [ V_169 ] ;
if ( V_2 -> V_364 . V_365 > V_2 -> V_364 . V_1004 ) {
V_1003 = V_2 -> V_364 . V_365 -
V_2 -> V_364 . V_1004 ;
if ( ( V_1003 > V_1005 ) &&
( V_2 -> V_364 . V_998 == V_1006 ) ) {
V_2 -> V_364 . V_998 = V_1007 ;
V_992 ++ ;
} else if ( ( V_1003 < V_1008 ) &&
( V_2 -> V_364 . V_998 == V_1007 ) ) {
V_2 -> V_364 . V_998 = V_1006 ;
V_992 ++ ;
}
}
V_2 -> V_364 . V_1004 = V_2 -> V_364 . V_365 ;
}
if ( V_992 )
V_41 = F_169 ( V_9 , & V_9 -> V_207 [ 0 ] , V_992 ) ;
F_172 ( & V_9 -> V_1002 , F_79 ( 1000 ) ) ;
}
int F_173 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_165 ( V_9 ) ;
if ( V_41 )
goto V_1009;
V_41 = F_43 ( V_9 ) ;
if ( V_41 )
goto V_1010;
V_41 = F_88 ( V_9 ) ;
if ( V_41 )
goto V_1011;
V_41 = F_92 ( V_9 ) ;
if ( V_41 )
goto V_1011;
V_41 = F_86 ( V_9 ) ;
if ( V_41 )
goto V_1011;
V_41 = F_105 ( V_9 ) ;
if ( V_41 )
goto V_1011;
V_41 = F_94 ( V_9 ) ;
if ( V_41 )
goto V_1012;
V_41 = F_91 ( V_9 ) ;
if ( V_41 )
goto V_1012;
return 0 ;
V_1012:
F_107 ( V_9 ) ;
V_1011:
F_46 ( V_9 ) ;
V_1010:
F_36 ( V_9 ) ;
V_1009:
F_52 ( L_18 , V_299 , V_41 ) ;
return V_41 ;
}
void F_174 ( struct V_8 * V_9 )
{
F_101 ( V_9 ) ;
F_107 ( V_9 ) ;
F_46 ( V_9 ) ;
F_36 ( V_9 ) ;
}
