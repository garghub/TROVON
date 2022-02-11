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
V_397 ) >>
V_398 ;
V_265 -> V_400 = ( V_188 -> V_401 &
V_402 ) >>
V_403 ;
V_265 -> V_404 = ( V_188 -> V_396 &
V_405 ) >>
V_406 ;
V_265 -> V_407 = ( V_188 -> V_408 &
V_409 ) >>
V_410 ;
V_265 -> V_411 = ( V_188 -> V_408 &
V_412 ) >>
V_413 ;
V_265 -> V_414 = ( V_188 -> V_388 &
V_415 ) >>
V_416 ;
V_265 -> V_417 = ( V_188 -> V_388 &
V_418 ) >>
V_419 ;
V_265 -> V_420 = ( V_188 -> V_378 &
V_421 ) >>
V_422 ;
V_265 -> V_423 = V_188 -> V_423 ;
V_265 -> V_424 = V_188 -> V_424 ;
V_265 -> V_425 = ( ( V_426 ) V_188 -> V_427 << 32 ) |
V_188 -> V_428 ;
V_265 -> V_429 = 0 ;
V_265 -> V_430 = V_188 -> V_430 ;
V_265 -> V_431 = V_188 -> V_431 ;
V_265 -> V_432 = V_188 -> V_433 &
V_434 ;
V_265 -> V_269 = ( V_188 -> V_433 &
V_435 ) >>
V_436 ;
V_265 -> V_437 = ( ( V_188 -> V_438 &
V_439 ) >>
V_440 ) *
V_441 ;
V_265 -> V_442 = ( ( V_188 -> V_438 &
V_443 ) >>
V_444 ) *
V_441 ;
V_265 -> V_445 =
V_265 -> V_437 - ( sizeof( struct V_446 ) +
sizeof( struct V_447 ) ) ;
if ( F_84 ( V_9 ) == V_448 ) {
V_265 -> V_449 = 1 ;
V_265 -> V_450 = V_213 ;
V_265 -> V_451 = V_452 ;
}
V_9 -> V_265 . V_453 = V_188 -> V_454 >>
V_455 ;
V_9 -> V_265 . V_456 = V_188 -> V_454 &
V_457 ;
}
static int F_85 ( struct V_8 * V_9 ,
struct V_458 * V_459 )
{
T_1 V_460 ;
V_460 = V_459 -> V_460 & V_461 ;
if ( V_460 != V_461 )
return - V_72 ;
V_9 -> V_462 = V_459 -> V_462 ;
V_9 -> V_463 = V_459 -> V_463 ;
return 0 ;
}
static int F_86 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_464 * V_188 ;
V_174 = F_19 ( V_465 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_465 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_464 * ) V_174 ;
memset ( & V_9 -> V_265 . V_466 [ 0 ] , 0 , sizeof( V_9 -> V_265 . V_466 ) ) ;
memcpy ( & V_9 -> V_265 . V_466 [ 0 ] , & V_188 -> V_467 [ 0 ] ,
sizeof( V_188 -> V_467 ) ) ;
F_64 ( V_9 -> V_265 . V_466 , sizeof( V_188 -> V_467 ) ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_88 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_458 * V_188 ;
V_174 = F_19 ( V_468 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_468 ,
V_183 , sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_458 * ) V_174 ;
V_41 = F_85 ( V_9 , V_188 ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_89 ( struct V_8 * V_9 , bool V_469 )
{
struct V_470 * V_182 = V_9 -> V_471 . V_4 ;
struct V_17 * V_144 = & V_9 -> V_471 . V_144 ;
struct V_472 * V_473 ;
int V_41 ;
V_473 = F_90 ( sizeof( * V_473 ) , V_145 ) ;
if ( V_473 == NULL )
return - V_163 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> V_146 . V_151 = V_9 -> V_471 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_474 ) &
V_475 ;
V_144 -> V_153 . V_476 . V_477 [ 0 ] . V_478 = ( T_1 ) ( V_9 -> V_471 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_476 . V_477 [ 0 ] . V_479 = ( T_1 ) F_26 ( V_9 -> V_471 . V_195 ) ;
V_144 -> V_153 . V_476 . V_477 [ 0 ] . V_161 = V_9 -> V_471 . V_159 ;
memcpy ( V_473 , V_182 , sizeof( struct V_472 ) ) ;
memset ( V_182 , 0 , V_9 -> V_471 . V_159 ) ;
F_18 ( (struct V_136 * ) V_182 ,
V_480 ,
V_156 ,
V_9 -> V_471 . V_159 ) ;
if ( V_469 )
V_182 -> V_481 = V_469 ;
V_41 = F_82 ( V_9 , V_144 , V_9 -> V_471 . V_4 ) ;
if ( V_41 )
memcpy ( V_182 , V_473 , sizeof( struct V_472 ) ) ;
else
F_64 ( V_182 , V_9 -> V_471 . V_159 ) ;
F_87 ( V_473 ) ;
return V_41 ;
}
static int F_91 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_482 V_160 ;
struct V_17 * V_144 ;
struct V_483 * V_484 ;
struct V_485 * V_486 ;
V_144 = F_20 ( sizeof( struct V_17 ) , V_145 ) ;
if ( ! V_144 )
return V_41 ;
V_160 . V_159 = sizeof( struct V_483 ) ;
V_160 . V_4 = F_24 ( & V_9 -> V_117 . V_158 -> V_9 ,
V_160 . V_159 , & V_160 . V_195 , V_145 ) ;
if ( ! V_160 . V_4 )
goto V_487;
V_144 -> V_146 . V_151 = V_160 . V_159 ;
V_144 -> V_146 . V_147 |=
( 1 << V_474 ) &
V_475 ;
V_144 -> V_153 . V_476 . V_477 [ 0 ] . V_478 = ( T_1 ) ( V_160 . V_195 & 0xffffffff ) ;
V_144 -> V_153 . V_476 . V_477 [ 0 ] . V_479 = ( T_1 ) F_26 ( V_160 . V_195 ) ;
V_144 -> V_153 . V_476 . V_477 [ 0 ] . V_161 = V_160 . V_159 ;
memset ( V_160 . V_4 , 0 , V_160 . V_159 ) ;
F_18 ( (struct V_136 * ) V_160 . V_4 ,
V_488 ,
V_183 ,
V_160 . V_159 ) ;
V_41 = F_82 ( V_9 , V_144 , V_160 . V_4 ) ;
if ( ! V_41 ) {
V_484 = (struct V_483 * ) V_160 . V_4 ;
V_486 = & V_484 -> V_489 . V_486 ;
V_9 -> V_490 = ( V_486 -> V_491 &
V_492 )
>> V_493 ;
strncpy ( V_9 -> V_494 ,
V_486 -> V_495 , 31 ) ;
}
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_160 . V_159 , V_160 . V_4 , V_160 . V_195 ) ;
V_487:
F_87 ( V_144 ) ;
return V_41 ;
}
static int F_92 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_376 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_496 , sizeof( * V_174 ) ) ;
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
int F_93 ( struct V_8 * V_9 , T_2 * V_497 ,
T_2 * V_498 )
{
int V_41 = - V_163 ;
struct V_499 * V_188 ;
struct V_17 * V_174 ;
V_174 = F_19 ( V_500 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_500 ,
V_183 , sizeof( * V_174 ) ) ;
( (struct V_136 * ) V_174 -> V_153 . V_174 ) -> V_190 = 0x1 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_499 * ) V_174 ;
if ( V_497 )
* V_497 = ( V_188 -> V_501 & V_502 )
>> V_503 ;
if ( V_498 )
* V_498 = ( V_188 -> V_504 & V_324 ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_94 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
struct V_17 * V_174 ;
struct V_505 * V_188 ;
V_174 = F_19 ( V_506 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( (struct V_136 * ) & V_174 -> V_153 . V_174 [ 0 ] ,
V_506 , V_183 ,
sizeof( * V_174 ) ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_505 * ) V_174 ;
V_9 -> V_93 . V_507 =
( V_188 -> V_508 & V_509 ) ;
V_9 -> V_93 . V_510 =
( V_188 -> V_508 & V_511 )
>> V_512 ;
V_9 -> V_93 . V_95 =
( V_188 -> V_513 & V_514 ) ;
V_9 -> V_93 . V_94 =
( V_188 -> V_513 & V_515 )
>> V_516 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_95 ( struct V_8 * V_9 , struct V_517 * V_518 )
{
int V_41 = - V_163 ;
struct V_519 * V_174 ;
struct V_520 * V_188 ;
V_174 = F_19 ( V_521 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
if ( V_518 -> V_522 )
V_174 -> V_523 |= V_524 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_520 * ) V_174 ;
V_518 -> V_120 = V_188 -> V_525 & V_526 ;
if ( V_188 -> V_525 & V_527 ) {
V_518 -> V_522 = true ;
V_518 -> V_528 = V_188 -> V_525 >>
V_529 ;
} else {
V_518 -> V_522 = false ;
V_518 -> V_530 = 0 ;
}
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_96 ( struct V_8 * V_9 , struct V_517 * V_518 )
{
int V_41 = - V_163 ;
struct V_531 * V_174 ;
V_174 = F_19 ( V_532 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_518 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_97 ( struct V_8 * V_9 )
{
int V_41 = - V_163 ;
T_6 V_533 ;
struct V_534 * V_174 ;
struct V_535 * V_188 ;
if ( V_9 -> V_265 . V_384 ) {
V_174 = F_19 ( V_536 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_537 = V_9 -> V_265 . V_384 ;
V_174 -> V_523 |= V_524 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
V_188 = (struct V_535 * ) V_174 ;
if ( ! V_41 && ( V_188 -> V_525 & V_527 ) &&
V_188 -> V_537 ) {
V_9 -> V_538 -> V_539 = V_188 -> V_525 >>
V_529 ;
V_9 -> V_538 -> V_540 = V_188 -> V_525 &
V_541 ;
V_9 -> V_538 -> V_542 = V_188 -> V_537 ;
V_533 =
F_98 ( V_188 -> V_537 ) * sizeof( long ) ;
V_9 -> V_538 -> V_543 = F_20 ( V_533 ,
V_145 ) ;
}
F_87 ( V_174 ) ;
}
V_174 = F_19 ( V_536 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_537 = V_9 -> V_265 . V_377 - V_9 -> V_265 . V_384 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
V_188 = (struct V_535 * ) V_174 ;
if ( ! V_41 && V_188 -> V_537 ) {
V_9 -> V_538 -> V_544 = V_188 -> V_525 &
V_541 ;
V_9 -> V_538 -> V_545 = V_188 -> V_537 ;
V_533 = F_98 ( V_188 -> V_537 ) * sizeof( long ) ;
V_9 -> V_538 -> V_546 = F_20 ( V_533 ,
V_145 ) ;
}
F_87 ( V_174 ) ;
if ( V_9 -> V_538 -> V_546 || V_9 -> V_538 -> V_543 ) {
V_9 -> V_538 -> V_547 = true ;
return 0 ;
}
return V_41 ;
}
static void F_99 ( struct V_8 * V_9 )
{
struct V_548 * V_174 ;
V_174 = F_19 ( V_549 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
if ( V_9 -> V_538 -> V_545 ) {
V_174 -> V_550 = V_9 -> V_538 -> V_544 ;
V_174 -> V_537 = V_9 -> V_538 -> V_545 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
}
if ( V_9 -> V_538 -> V_542 ) {
F_87 ( V_174 ) ;
V_174 = F_19 ( V_549 ,
sizeof( * V_174 ) ) ;
if ( ! V_174 )
goto V_200;
V_174 -> V_550 = V_9 -> V_538 -> V_540 ;
V_174 -> V_537 = V_9 -> V_538 -> V_542 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
}
V_200:
F_87 ( V_174 ) ;
}
void F_100 ( struct V_8 * V_9 )
{
int V_41 ;
V_9 -> V_538 = F_20 ( sizeof( struct V_551 ) ,
V_145 ) ;
if ( ! V_9 -> V_538 ) {
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
F_87 ( V_9 -> V_538 -> V_546 ) ;
F_87 ( V_9 -> V_538 -> V_543 ) ;
F_87 ( V_9 -> V_538 ) ;
}
static int F_102 ( T_1 * V_552 , int V_162 ,
int * V_191 , int * V_553 )
{
int V_169 ;
int V_554 ;
* V_552 = F_103 ( * V_552 ) ;
V_554 = * V_552 * V_162 ;
for ( V_169 = 0 ; V_169 < V_555 ; V_169 ++ ) {
if ( V_554 <= ( V_556 << V_169 ) )
break;
}
if ( V_169 >= V_555 )
return - V_72 ;
V_554 = F_104 ( V_554 ,
( ( V_556 << V_169 ) / V_557 ) ) ;
* V_191 =
V_554 / ( ( V_556 << V_169 ) / V_557 ) ;
* V_553 = ( ( V_556 << V_169 ) / V_557 ) ;
* V_552 = V_554 / V_162 ;
return 0 ;
}
static int F_105 ( struct V_8 * V_9 )
{
int V_169 ;
int V_41 = 0 ;
int V_558 ;
struct V_559 * V_174 ;
struct V_560 * V_188 ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 ;
struct V_562 * V_563 ;
V_174 = F_19 ( V_564 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_558 = V_565 ;
V_9 -> V_566 . V_159 = sizeof( struct V_567 ) * V_558 ;
V_174 -> V_568 = ( V_569 <<
V_570 ) &
V_571 ;
for ( V_169 = 0 ; V_169 < V_555 ; V_169 ++ ) {
if ( V_572 == ( V_213 << V_169 ) )
break;
}
V_174 -> V_568 |= ( V_169 << V_573 ) &
V_574 ;
V_174 -> V_568 |= ( sizeof( struct V_567 ) <<
V_575 ) &
V_576 ;
V_9 -> V_566 . V_577 . V_4 = F_24 ( & V_158 -> V_9 , V_572 ,
& V_9 -> V_566 . V_577 . V_195 ,
V_145 ) ;
if ( V_9 -> V_566 . V_577 . V_4 == NULL )
goto V_578;
V_9 -> V_566 . V_4 = F_24 ( & V_158 -> V_9 , V_9 -> V_566 . V_159 ,
& V_195 , V_145 ) ;
if ( V_9 -> V_566 . V_4 == NULL )
goto V_579;
V_9 -> V_566 . V_195 = V_195 ;
V_9 -> V_566 . V_580 = V_558 ;
memset ( V_9 -> V_566 . V_4 , 0 , V_9 -> V_566 . V_159 ) ;
V_563 = (struct V_562 * ) V_9 -> V_566 . V_577 . V_4 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_566 . V_159 / V_213 ; V_169 ++ ) {
V_563 [ V_169 ] . V_478 = ( T_1 ) F_106 ( V_195 & 0xffffffff ) ;
V_563 [ V_169 ] . V_479 = ( T_1 ) F_106 ( F_26 ( V_195 ) ) ;
V_195 += V_572 ;
}
V_174 -> V_581 [ 0 ] . V_170 = ( T_1 ) ( V_9 -> V_566 . V_577 . V_195 & 0xFFFFFFFF ) ;
V_174 -> V_581 [ 0 ] . V_171 = ( T_1 ) F_26 ( V_9 -> V_566 . V_577 . V_195 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_560 * ) V_174 ;
V_9 -> V_566 . V_582 = V_188 -> V_582 & 0xFFFF ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
F_22 ( & V_158 -> V_9 , V_9 -> V_566 . V_159 , V_9 -> V_566 . V_4 ,
V_9 -> V_566 . V_195 ) ;
V_9 -> V_566 . V_4 = NULL ;
V_579:
F_22 ( & V_158 -> V_9 , V_572 , V_9 -> V_566 . V_577 . V_4 ,
V_9 -> V_566 . V_577 . V_195 ) ;
V_9 -> V_566 . V_577 . V_4 = NULL ;
V_9 -> V_566 . V_159 = 0 ;
V_578:
F_87 ( V_174 ) ;
return V_41 ;
}
static void F_107 ( struct V_8 * V_9 )
{
struct V_583 * V_174 ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
if ( V_9 -> V_566 . V_4 == NULL )
return;
V_174 = F_19 ( V_584 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return;
V_174 -> V_582 = V_9 -> V_566 . V_582 ;
F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_22 ( & V_158 -> V_9 , V_9 -> V_566 . V_159 , V_9 -> V_566 . V_4 ,
V_9 -> V_566 . V_195 ) ;
V_9 -> V_566 . V_4 = NULL ;
F_22 ( & V_158 -> V_9 , V_572 , V_9 -> V_566 . V_577 . V_4 ,
V_9 -> V_566 . V_577 . V_195 ) ;
F_87 ( V_174 ) ;
}
static T_3 F_108 ( struct V_8 * V_9 )
{
int V_169 , V_585 = 0 , V_236 = 0 ;
T_3 V_124 ;
F_47 ( & V_9 -> V_586 ) ;
V_236 = V_9 -> V_207 [ 0 ] . V_236 ;
V_124 = V_9 -> V_207 [ 0 ] . V_3 . V_120 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
if ( V_9 -> V_207 [ V_169 ] . V_236 < V_236 ) {
V_236 = V_9 -> V_207 [ V_169 ] . V_236 ;
V_124 = V_9 -> V_207 [ V_169 ] . V_3 . V_120 ;
V_585 = V_169 ;
}
}
V_9 -> V_207 [ V_585 ] . V_236 += 1 ;
F_48 ( & V_9 -> V_586 ) ;
return V_124 ;
}
static void F_109 ( struct V_8 * V_9 , T_3 V_124 )
{
int V_169 ;
F_47 ( & V_9 -> V_586 ) ;
V_169 = F_110 ( V_9 , V_124 ) ;
if ( V_169 == - V_72 )
F_28 () ;
V_9 -> V_207 [ V_169 ] . V_236 -= 1 ;
F_48 ( & V_9 -> V_586 ) ;
}
int F_111 ( struct V_8 * V_9 , struct V_248 * V_13 ,
int V_587 , int V_588 , T_3 V_589 )
{
int V_41 = - V_163 ; int V_590 ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
struct V_591 * V_174 ;
struct V_592 * V_188 ;
T_1 V_593 , V_594 , V_553 , V_595 ;
if ( V_587 > V_9 -> V_265 . V_432 ) {
F_52 ( L_17 ,
V_299 , V_9 -> V_120 , V_9 -> V_265 . V_432 , V_587 ) ;
return - V_72 ;
}
if ( V_588 && ( F_84 ( V_9 ) != V_448 ) )
return - V_72 ;
if ( V_588 ) {
V_13 -> V_590 = 1 ;
V_590 = 1 ;
V_594 = V_596 ;
V_593 = 1 ;
} else {
V_13 -> V_590 = V_9 -> V_265 . V_432 ;
V_590 = V_9 -> V_265 . V_432 ;
V_594 = sizeof( struct V_597 ) ;
V_593 = V_598 ;
}
V_13 -> V_161 = F_104 ( V_590 * V_594 , V_213 ) ;
V_174 = F_19 ( V_210 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
F_18 ( & V_174 -> V_174 . V_182 , V_210 ,
V_183 , sizeof( * V_174 ) ) ;
V_13 -> V_4 = F_24 ( & V_158 -> V_9 , V_13 -> V_161 , & V_13 -> V_195 , V_145 ) ;
if ( ! V_13 -> V_4 ) {
V_41 = - V_163 ;
goto V_578;
}
memset ( V_13 -> V_4 , 0 , V_13 -> V_161 ) ;
V_553 = V_13 -> V_161 / V_593 ;
V_174 -> V_174 . V_212 = ( V_553 / V_213 ) <<
V_214 ;
V_174 -> V_174 . V_212 |= V_593 ;
V_174 -> V_174 . V_215 = V_216 ;
V_13 -> V_217 = F_108 ( V_9 ) ;
V_174 -> V_174 . V_182 . V_190 = V_599 ;
V_595 = V_13 -> V_161 / V_594 ;
V_13 -> V_600 = V_595 ;
if ( V_595 > 1024 ) {
V_174 -> V_174 . V_215 |= ( 0x3 << V_601 ) ;
} else {
T_2 V_602 = 0 ;
switch ( V_595 ) {
case 256 :
V_602 = 0 ;
break;
case 512 :
V_602 = 1 ;
break;
case 1024 :
V_602 = 2 ;
break;
default:
goto V_200;
}
V_174 -> V_174 . V_215 |= ( V_602 << V_601 ) ;
}
V_174 -> V_174 . V_217 = V_13 -> V_217 ;
if ( F_84 ( V_9 ) == V_448 ) {
if ( V_588 )
V_174 -> V_174 . V_212 |= V_603 <<
V_604 ;
V_13 -> V_605 = false ;
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_594 ) ;
} else {
V_174 -> V_174 . V_218 = ( V_13 -> V_161 / V_594 ) - 1 ;
V_174 -> V_174 . V_215 |= V_606 ;
V_13 -> V_605 = true ;
}
V_174 -> V_174 . V_218 |= ( V_589 <<
V_607 ) ;
F_25 ( & V_174 -> V_174 . V_195 [ 0 ] , V_593 , V_13 -> V_195 , V_553 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_592 * ) V_174 ;
V_13 -> V_120 = ( T_3 ) ( V_188 -> V_188 . V_106 & V_219 ) ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
F_109 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
V_578:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_112 ( struct V_8 * V_9 , struct V_248 * V_13 )
{
int V_41 = - V_163 ;
struct V_608 * V_174 ;
V_174 = F_19 ( V_179 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_182 , V_179 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_609 |=
( V_13 -> V_120 << V_610 ) &
V_611 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_109 ( V_9 , V_13 -> V_217 ) ;
F_22 ( & V_9 -> V_117 . V_158 -> V_9 , V_13 -> V_161 , V_13 -> V_4 , V_13 -> V_195 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_113 ( struct V_8 * V_9 , struct V_612 * V_613 ,
T_1 V_614 , int V_615 )
{
int V_41 = - V_163 ;
struct V_616 * V_174 ;
struct V_617 * V_188 ;
V_174 = F_19 ( V_618 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_614 = V_614 ;
V_174 -> V_619 |= V_615 ;
V_174 -> V_619 |= ( V_613 -> V_620 << V_621 ) ;
V_174 -> V_619 |=
( V_613 -> V_622 << V_623 ) ;
V_174 -> V_619 |=
( V_613 -> V_624 << V_625 ) ;
V_174 -> V_619 |=
( V_613 -> V_626 << V_627 ) ;
V_174 -> V_619 |=
( V_613 -> V_628 << V_629 ) ;
V_174 -> V_619 |=
( V_613 -> V_630 << V_631 ) ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_617 * ) V_174 ;
V_613 -> V_632 = V_188 -> V_633 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_114 ( struct V_8 * V_9 , int V_620 , T_1 V_632 )
{
int V_41 = - V_163 ;
struct V_634 * V_174 ;
V_174 = F_19 ( V_635 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_632 = V_632 ;
V_174 -> V_636 = V_620 ? 1 : 0 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_115 ( struct V_8 * V_9 , struct V_612 * V_613 ,
T_1 V_614 , T_1 V_637 , T_1 V_638 , T_1 V_639 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_640 * V_174 ;
struct V_641 * V_188 ;
V_174 = F_19 ( V_642 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_643 =
V_614 | ( V_613 -> V_630 << V_644 ) ;
V_174 -> V_620 = V_613 -> V_620 ;
V_174 -> V_645 |= ( V_613 -> V_622 <<
V_646 ) ;
V_174 -> V_645 |= ( V_613 -> V_624 <<
V_647 ) ;
V_174 -> V_645 |= ( V_613 -> V_626 <<
V_648 ) ;
V_174 -> V_645 |= ( V_613 -> V_628 <<
V_649 ) ;
V_174 -> V_645 |= ( V_613 -> V_650 <<
V_651 ) ;
V_174 -> V_645 |= ( V_639 << V_652 ) ;
V_174 -> V_645 |= ( V_613 -> V_638 / V_653 ) ;
V_174 -> V_645 |= ( V_613 -> V_654 / V_653 ) <<
V_655 ;
V_174 -> V_656 = V_613 -> V_161 ;
V_174 -> V_657 = F_26 ( V_613 -> V_161 ) ;
V_174 -> V_658 = ( T_1 ) ( V_613 -> V_659 & 0xffffffff ) ;
V_174 -> V_660 = ( T_1 ) F_26 ( V_613 -> V_659 ) ;
V_174 -> V_661 = ( T_1 ) V_613 -> V_4 ;
V_174 -> V_662 = ( T_1 ) F_26 ( V_613 -> V_4 ) ;
for ( V_169 = 0 ; V_169 < V_637 ; V_169 ++ ) {
V_174 -> V_577 [ V_169 ] . V_170 = ( T_1 ) ( V_613 -> V_663 [ V_169 ] . V_195 & 0xffffffff ) ;
V_174 -> V_577 [ V_169 ] . V_171 = F_26 ( V_613 -> V_663 [ V_169 ] . V_195 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_641 * ) V_174 ;
V_613 -> V_632 = V_188 -> V_633 ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_116 ( struct V_8 * V_9 ,
struct V_612 * V_613 , T_1 V_637 ,
T_1 V_664 , T_1 V_639 )
{
int V_41 = - V_163 ;
int V_169 ;
struct V_665 * V_174 ;
V_174 = F_19 ( V_666 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return - V_163 ;
V_174 -> V_633 = V_613 -> V_632 ;
V_174 -> V_667 = ( V_637 << V_668 ) |
( V_664 & V_669 ) ;
V_174 -> V_639 = V_639 << V_670 ;
for ( V_169 = 0 ; V_169 < V_637 ; V_169 ++ ) {
V_174 -> V_577 [ V_169 ] . V_170 =
( T_1 ) ( V_613 -> V_663 [ V_169 + V_664 ] . V_195 & 0xffffffff ) ;
V_174 -> V_577 [ V_169 ] . V_171 =
F_26 ( V_613 -> V_663 [ V_169 + V_664 ] . V_195 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_117 ( struct V_8 * V_9 ,
struct V_612 * V_613 , T_1 V_614 , int V_671 )
{
int V_41 ;
T_1 V_639 = 0 ;
T_1 V_672 , V_664 ;
T_1 V_673 = V_613 -> V_630 ;
V_664 = 0 ;
V_672 = F_118 ( V_673 , V_674 ) ;
if ( V_672 == V_673 )
V_639 = 1 ;
V_41 = F_115 ( V_9 , V_613 , V_614 ,
V_672 , V_613 -> V_638 , V_639 ) ;
if ( V_41 ) {
F_52 ( L_18 , V_299 , V_41 ) ;
return V_41 ;
}
if ( V_639 )
return 0 ;
while ( ! V_639 ) {
V_664 += V_672 ;
V_673 -= V_672 ;
V_672 = F_118 ( V_673 , V_674 ) ;
if ( V_672 == V_673 )
V_639 = 1 ;
V_41 = F_116 ( V_9 , V_613 , V_672 ,
V_664 , V_639 ) ;
if ( V_41 )
break;
}
if ( V_41 )
F_52 ( L_19 , V_299 , V_41 ) ;
return V_41 ;
}
bool F_119 ( struct V_248 * V_13 , struct V_243 * V_244 )
{
struct V_243 * V_675 ;
bool V_676 = false ;
F_120 (tmp, &cq->sq_head, sq_entry) {
if ( V_244 == V_675 ) {
V_676 = true ;
break;
}
}
return V_676 ;
}
bool F_121 ( struct V_248 * V_13 , struct V_243 * V_244 )
{
struct V_243 * V_675 ;
bool V_676 = false ;
F_120 (tmp, &cq->rq_head, rq_entry) {
if ( V_244 == V_675 ) {
V_676 = true ;
break;
}
}
return V_676 ;
}
void F_122 ( struct V_243 * V_244 )
{
bool V_676 ;
unsigned long V_322 ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
F_69 ( & V_9 -> V_347 , V_322 ) ;
V_676 = F_119 ( V_244 -> V_345 , V_244 ) ;
if ( ! V_676 )
F_124 ( & V_244 -> V_343 , & V_244 -> V_345 -> V_341 ) ;
if ( ! V_244 -> V_292 ) {
V_676 = F_121 ( V_244 -> V_346 , V_244 ) ;
if ( ! V_676 )
F_124 ( & V_244 -> V_344 , & V_244 -> V_346 -> V_342 ) ;
}
F_70 ( & V_9 -> V_347 , V_322 ) ;
}
static void F_125 ( struct V_243 * V_244 )
{
V_244 -> V_18 . V_19 = 0 ;
V_244 -> V_18 . V_5 = 0 ;
V_244 -> V_677 . V_19 = 0 ;
V_244 -> V_677 . V_5 = 0 ;
}
int F_50 ( struct V_243 * V_244 , enum V_23 V_678 ,
enum V_23 * V_679 )
{
unsigned long V_322 ;
enum V_24 V_680 ;
V_680 = F_10 ( V_678 ) ;
F_69 ( & V_244 -> V_681 , V_322 ) ;
if ( V_679 )
* V_679 = F_9 ( V_244 -> V_682 ) ;
if ( V_680 == V_244 -> V_682 ) {
F_70 ( & V_244 -> V_681 , V_322 ) ;
return 1 ;
}
if ( V_680 == V_28 ) {
F_125 ( V_244 ) ;
F_126 ( V_244 ) ;
} else if ( V_680 == V_39 ) {
F_122 ( V_244 ) ;
}
V_244 -> V_682 = V_680 ;
F_70 ( & V_244 -> V_681 , V_322 ) ;
return 0 ;
}
static T_1 F_127 ( struct V_243 * V_244 )
{
T_1 V_322 = 0 ;
if ( V_244 -> V_683 & V_684 )
V_322 |= V_685 ;
if ( V_244 -> V_683 & V_686 )
V_322 |= V_687 ;
if ( V_244 -> V_683 & V_688 )
V_322 |= V_689 ;
if ( V_244 -> V_683 & V_690 )
V_322 |= V_691 ;
if ( V_244 -> V_683 & V_692 )
V_322 |= V_693 ;
return V_322 ;
}
static int F_128 ( struct V_694 * V_174 ,
struct V_695 * V_696 ,
struct V_243 * V_244 )
{
int V_41 ;
T_1 V_161 , V_593 , V_168 ;
T_4 V_195 ;
struct V_517 * V_518 = V_244 -> V_518 ;
struct V_8 * V_9 = F_123 ( V_518 -> V_697 . V_271 ) ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_698 ;
T_1 V_699 = V_696 -> V_700 . V_395 ;
V_698 = F_129 ( T_1 , V_696 -> V_700 . V_701 + 1 ,
V_9 -> V_265 . V_453 ) ;
V_41 = F_102 ( & V_698 ,
V_9 -> V_265 . V_437 , & V_593 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_20 , V_299 ,
V_698 ) ;
return - V_72 ;
}
V_244 -> V_18 . V_702 = V_698 ;
V_161 = ( V_593 * V_168 ) ;
V_244 -> V_18 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_244 -> V_18 . V_4 )
return - V_72 ;
memset ( V_244 -> V_18 . V_4 , 0 , V_161 ) ;
V_244 -> V_18 . V_161 = V_161 ;
V_244 -> V_18 . V_195 = V_195 ;
V_244 -> V_18 . V_162 = V_9 -> V_265 . V_437 ;
F_25 ( & V_174 -> V_703 [ 0 ] , V_593 , V_195 , V_168 ) ;
V_174 -> V_704 |= ( F_130 ( V_168 / V_213 )
<< V_705 ) ;
V_174 -> V_706 |= ( V_593 <<
V_707 ) &
V_708 ;
V_174 -> V_709 |= ( V_699 <<
V_710 ) &
V_711 ;
V_174 -> V_709 |= ( V_699 <<
V_712 ) &
V_713 ;
V_174 -> V_714 |= ( F_130 ( V_244 -> V_18 . V_702 ) <<
V_715 ) &
V_716 ;
V_174 -> V_717 |= ( V_9 -> V_265 . V_437 <<
V_718 ) &
V_719 ;
return 0 ;
}
static int F_131 ( struct V_694 * V_174 ,
struct V_695 * V_696 ,
struct V_243 * V_244 )
{
int V_41 ;
T_1 V_161 , V_593 , V_168 ;
T_4 V_195 = 0 ;
struct V_517 * V_518 = V_244 -> V_518 ;
struct V_8 * V_9 = F_123 ( V_518 -> V_697 . V_271 ) ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_720 = V_696 -> V_700 . V_721 + 1 ;
V_41 = F_102 ( & V_720 , V_9 -> V_265 . V_442 ,
& V_593 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_21 , V_299 ,
V_696 -> V_700 . V_721 + 1 ) ;
return V_41 ;
}
V_244 -> V_677 . V_702 = V_720 ;
V_161 = ( V_593 * V_168 ) ;
V_244 -> V_677 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_244 -> V_677 . V_4 )
return - V_163 ;
memset ( V_244 -> V_677 . V_4 , 0 , V_161 ) ;
V_244 -> V_677 . V_195 = V_195 ;
V_244 -> V_677 . V_161 = V_161 ;
V_244 -> V_677 . V_162 = V_9 -> V_265 . V_442 ;
F_25 ( & V_174 -> V_722 [ 0 ] , V_593 , V_195 , V_168 ) ;
V_174 -> V_704 |= ( F_130 ( V_168 / V_213 ) <<
V_723 ) ;
V_174 -> V_706 |=
( V_593 << V_724 ) &
V_725 ;
V_174 -> V_726 |= ( V_696 -> V_700 . V_399 <<
V_727 ) &
V_728 ;
V_174 -> V_714 |= ( F_130 ( V_244 -> V_677 . V_702 ) <<
V_729 ) &
V_730 ;
V_174 -> V_717 |= ( V_9 -> V_265 . V_442 <<
V_731 ) &
V_732 ;
return 0 ;
}
static void F_132 ( struct V_694 * V_174 ,
struct V_517 * V_518 ,
struct V_243 * V_244 ,
T_2 V_733 , T_3 V_734 )
{
V_518 -> V_530 -- ;
V_244 -> V_522 = true ;
V_174 -> V_726 |= V_735 ;
if ( ! V_733 )
return;
V_174 -> V_726 |= V_735 ;
V_174 -> V_736 = V_734 ;
V_174 -> V_736 |= V_737 <<
V_738 ;
}
static int F_133 ( struct V_694 * V_174 ,
struct V_243 * V_244 )
{
struct V_517 * V_518 = V_244 -> V_518 ;
struct V_8 * V_9 = F_123 ( V_518 -> V_697 . V_271 ) ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
T_4 V_195 = 0 ;
int V_450 = V_9 -> V_265 . V_450 ;
int V_739 = V_9 -> V_265 . V_451 * V_450 ;
struct V_446 * V_740 ;
int V_169 = 0 ;
if ( V_9 -> V_265 . V_449 == 0 )
return 0 ;
V_244 -> V_741 = F_24 ( & V_158 -> V_9 , V_739 ,
& V_195 , V_145 ) ;
if ( ! V_244 -> V_741 )
return - V_163 ;
memset ( V_244 -> V_741 , 0 , V_739 ) ;
F_25 ( & V_174 -> V_742 [ 0 ] , V_9 -> V_265 . V_451 ,
V_195 , V_450 ) ;
for (; V_169 < V_739 / V_9 -> V_265 . V_442 ; V_169 ++ ) {
V_740 = (struct V_446 * ) ( V_244 -> V_741 +
( V_169 * V_9 -> V_265 . V_442 ) ) ;
V_740 -> V_743 = 0 ;
V_740 -> V_743 |= 2 ;
V_740 -> V_743 |= ( V_744 << V_745 ) ;
V_740 -> V_743 |= ( 8 << V_746 ) ;
V_740 -> V_743 |= ( 8 << V_747 ) ;
}
return 0 ;
}
static void F_134 ( struct V_748 * V_188 ,
struct V_243 * V_244 ,
struct V_695 * V_696 ,
T_3 * V_749 , T_3 * V_750 )
{
T_1 V_698 , V_720 ;
V_244 -> V_120 = V_188 -> V_751 & V_752 ;
V_244 -> V_677 . V_753 = V_188 -> V_754 & V_755 ;
V_244 -> V_18 . V_753 = V_188 -> V_754 >> V_756 ;
V_244 -> V_757 = V_188 -> V_758 & V_759 ;
V_244 -> V_760 = ( V_188 -> V_758 >> V_761 ) ;
V_244 -> V_522 = false ;
if ( V_188 -> V_762 & V_763 ) {
V_244 -> V_522 = true ;
* V_750 = ( V_188 -> V_762 &
V_764 ) >>
V_765 ;
* V_749 = ( V_188 -> V_762 &
V_766 ) >>
V_767 ;
}
V_698 =
V_188 -> V_714 >> V_768 ;
V_698 = 1 << V_698 ;
V_720 = 1 << ( ( T_3 ) V_188 -> V_714 ) ;
V_244 -> V_18 . V_702 = V_698 ;
V_244 -> V_18 . V_769 = V_698 - 1 ;
if ( ! V_696 -> V_292 ) {
V_244 -> V_677 . V_702 = V_720 ;
V_244 -> V_677 . V_769 = V_720 - 1 ;
}
}
int F_135 ( struct V_243 * V_244 , struct V_695 * V_696 ,
T_2 V_733 , T_3 V_734 , T_3 * V_749 ,
T_3 * V_750 )
{
int V_41 = - V_163 ;
T_1 V_322 = 0 ;
struct V_517 * V_518 = V_244 -> V_518 ;
struct V_8 * V_9 = F_123 ( V_518 -> V_697 . V_271 ) ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
struct V_248 * V_13 ;
struct V_694 * V_174 ;
struct V_748 * V_188 ;
int V_770 ;
switch ( V_696 -> V_771 ) {
case V_772 :
V_770 = V_773 ;
break;
case V_774 :
V_770 = V_775 ;
break;
case V_776 :
V_770 = V_777 ;
break;
default:
return - V_72 ;
}
V_174 = F_19 ( V_778 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_704 |= ( V_770 << V_779 ) &
V_780 ;
V_41 = F_128 ( V_174 , V_696 , V_244 ) ;
if ( V_41 )
goto V_781;
if ( V_696 -> V_292 ) {
struct V_782 * V_292 = F_136 ( V_696 -> V_292 ) ;
V_174 -> V_726 |= V_783 ;
V_174 -> V_722 [ 0 ] . V_170 = V_292 -> V_120 ;
V_244 -> V_292 = V_292 ;
} else {
V_41 = F_131 ( V_174 , V_696 , V_244 ) ;
if ( V_41 )
goto V_784;
}
V_41 = F_133 ( V_174 , V_244 ) ;
if ( V_41 )
goto V_200;
V_174 -> V_704 |= ( V_518 -> V_120 << V_785 ) &
V_786 ;
V_322 = F_127 ( V_244 ) ;
V_174 -> V_726 |= V_322 ;
V_174 -> V_758 |= ( V_9 -> V_265 . V_407 <<
V_787 ) &
V_788 ;
V_174 -> V_758 |= ( V_9 -> V_265 . V_411 <<
V_789 ) &
V_790 ;
V_13 = F_137 ( V_696 -> V_791 ) ;
V_174 -> V_792 |= ( V_13 -> V_120 << V_793 ) &
V_794 ;
V_244 -> V_345 = V_13 ;
V_13 = F_137 ( V_696 -> V_795 ) ;
V_174 -> V_792 |= ( V_13 -> V_120 << V_796 ) &
V_797 ;
V_244 -> V_346 = V_13 ;
if ( V_518 -> V_522 && V_696 -> V_700 . V_445 && V_518 -> V_530 &&
( V_696 -> V_700 . V_445 <= V_9 -> V_265 . V_445 ) ) {
F_132 ( V_174 , V_518 , V_244 , V_733 ,
V_734 ) ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_748 * ) V_174 ;
F_134 ( V_188 , V_244 , V_696 , V_749 , V_750 ) ;
V_244 -> V_682 = V_26 ;
F_87 ( V_174 ) ;
return 0 ;
V_200:
if ( V_244 -> V_677 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_677 . V_161 , V_244 -> V_677 . V_4 , V_244 -> V_677 . V_195 ) ;
V_784:
F_52 ( L_22 , V_299 , V_9 -> V_120 ) ;
F_22 ( & V_158 -> V_9 , V_244 -> V_18 . V_161 , V_244 -> V_18 . V_4 , V_244 -> V_18 . V_195 ) ;
V_781:
F_52 ( L_23 , V_299 , V_9 -> V_120 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_138 ( struct V_8 * V_9 , struct V_243 * V_244 ,
struct V_798 * V_799 )
{
int V_41 = - V_163 ;
struct V_800 * V_174 ;
struct V_801 * V_188 ;
V_174 = F_19 ( V_802 , sizeof( * V_188 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_751 = V_244 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_801 * ) V_174 ;
memcpy ( V_799 , & V_188 -> V_803 , sizeof( struct V_798 ) ) ;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_139 ( struct V_243 * V_244 ,
struct V_804 * V_174 ,
struct V_805 * V_696 ,
int V_806 )
{
int V_41 ;
struct V_807 * V_808 = & V_696 -> V_808 ;
union V_809 V_810 , V_811 ;
struct V_812 V_813 ;
T_1 V_814 = 0xFFFF ;
T_2 V_815 [ 6 ] , V_816 ;
union {
struct V_817 V_818 ;
struct V_819 V_820 ;
struct V_821 V_822 ;
} V_823 , V_824 ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
if ( ( V_808 -> V_825 & V_826 ) == 0 )
return - V_72 ;
if ( F_140 ( & V_9 -> V_317 , 1 , 0 ) )
F_141 ( V_9 ) ;
V_174 -> V_803 . V_827 |=
( V_808 -> V_828 . V_829 << V_830 ) ;
V_174 -> V_803 . V_831 |=
( V_808 -> V_828 . V_832 & V_833 ) ;
V_174 -> V_803 . V_831 |= ( V_808 -> V_834 << V_835 ) ;
V_174 -> V_803 . V_836 |=
( V_808 -> V_828 . V_837 << V_838 ) ;
V_174 -> V_322 |= V_839 ;
memcpy ( & V_174 -> V_803 . V_840 [ 0 ] , & V_808 -> V_828 . V_840 . V_841 [ 0 ] ,
sizeof( V_174 -> V_803 . V_840 ) ) ;
V_41 = F_142 ( & V_9 -> V_272 , 1 , V_808 -> V_828 . V_842 ,
& V_810 , & V_813 ) ;
if ( ! V_41 && V_813 . V_843 ) {
V_814 = F_143 ( V_813 . V_843 ) ;
memcpy ( V_815 , V_813 . V_843 -> V_844 , V_845 ) ;
F_144 ( V_813 . V_843 ) ;
}
memset ( & V_811 , 0 , sizeof( V_811 ) ) ;
if ( ! memcmp ( & V_810 , & V_811 , sizeof( V_811 ) ) )
return - V_72 ;
V_244 -> V_846 = V_808 -> V_828 . V_842 ;
memcpy ( & V_174 -> V_803 . V_810 [ 0 ] , & V_810 . V_841 [ 0 ] , sizeof( V_174 -> V_803 . V_810 ) ) ;
V_41 = F_145 ( V_9 , V_808 , & V_815 [ 0 ] ) ;
if ( V_41 )
return V_41 ;
V_174 -> V_803 . V_847 = V_815 [ 0 ] | ( V_815 [ 1 ] << 8 ) |
( V_815 [ 2 ] << 16 ) | ( V_815 [ 3 ] << 24 ) ;
V_816 = F_146 ( V_813 . V_848 , & V_810 ) ;
if ( V_816 == V_849 ) {
F_147 ( & V_823 . V_818 , & V_810 ) ;
F_147 ( & V_824 . V_818 , & V_808 -> V_828 . V_840 ) ;
memcpy ( & V_174 -> V_803 . V_840 [ 0 ] ,
& V_824 . V_820 . V_850 . V_851 , 4 ) ;
memcpy ( & V_174 -> V_803 . V_810 [ 0 ] ,
& V_823 . V_820 . V_850 . V_851 , 4 ) ;
}
F_148 ( & V_174 -> V_803 . V_840 [ 0 ] , sizeof( V_174 -> V_803 . V_840 ) ) ;
F_148 ( & V_174 -> V_803 . V_810 [ 0 ] , sizeof( V_174 -> V_803 . V_810 ) ) ;
V_174 -> V_803 . V_852 = V_815 [ 4 ] | ( V_815 [ 5 ] << 8 ) ;
if ( V_814 == 0xFFFF )
V_814 = 0 ;
if ( V_814 || V_9 -> V_853 ) {
if ( ! V_814 ) {
F_52 ( L_24 ,
V_9 -> V_120 ) ;
F_52 ( L_25 ,
V_9 -> V_120 ) ;
}
V_174 -> V_803 . V_852 |=
V_814 << V_854 ;
V_174 -> V_322 |= V_855 ;
V_174 -> V_803 . V_831 |=
( V_9 -> V_834 & 0x07 ) << V_835 ;
}
V_174 -> V_803 . V_726 |= ( ( V_816 <<
V_856 ) &
V_857 ) ;
return 0 ;
}
static int F_149 ( struct V_243 * V_244 ,
struct V_804 * V_174 ,
struct V_805 * V_696 , int V_806 )
{
int V_41 = 0 ;
struct V_8 * V_9 = F_123 ( V_244 -> V_280 . V_271 ) ;
if ( V_806 & V_858 ) {
V_174 -> V_803 . V_859 |= ( V_696 -> V_860 &
V_861 ) ;
V_174 -> V_322 |= V_862 ;
}
if ( V_806 & V_863 ) {
V_244 -> V_864 = V_696 -> V_864 ;
V_174 -> V_803 . V_864 = V_696 -> V_864 ;
V_174 -> V_322 |= V_865 ;
}
if ( V_806 & V_866 ) {
V_41 = F_139 ( V_244 , V_174 , V_696 , V_806 ) ;
if ( V_41 )
return V_41 ;
} else if ( V_244 -> V_771 == V_772 || V_244 -> V_771 == V_776 ) {
V_174 -> V_803 . V_847 = V_9 -> V_117 . V_815 [ 0 ] |
( V_9 -> V_117 . V_815 [ 1 ] << 8 ) |
( V_9 -> V_117 . V_815 [ 2 ] << 16 ) |
( V_9 -> V_117 . V_815 [ 3 ] << 24 ) ;
V_174 -> V_803 . V_852 = V_9 -> V_117 . V_815 [ 4 ] |
( V_9 -> V_117 . V_815 [ 5 ] << 8 ) ;
}
if ( ( V_806 & V_867 ) &&
V_696 -> V_868 ) {
V_174 -> V_803 . V_726 |=
V_869 ;
V_174 -> V_322 |= V_870 ;
}
if ( V_806 & V_871 ) {
V_174 -> V_803 . V_872 |= ( V_696 -> V_873 &
V_874 ) ;
V_174 -> V_322 |= V_870 ;
}
if ( V_806 & V_875 ) {
if ( V_696 -> V_876 < V_877 ||
V_696 -> V_876 > V_878 ) {
F_52 ( L_26 ,
V_9 -> V_120 , F_150 ( V_696 -> V_876 ) ) ;
V_41 = - V_72 ;
goto V_879;
}
V_174 -> V_803 . V_859 |=
( F_150 ( V_696 -> V_876 ) <<
V_880 ) &
V_881 ;
V_174 -> V_322 |= V_882 ;
}
if ( V_806 & V_883 ) {
V_174 -> V_803 . V_872 |= V_696 -> V_143 <<
V_884 ;
V_174 -> V_322 |= V_885 ;
}
if ( V_806 & V_886 ) {
V_174 -> V_803 . V_831 |= ( V_696 -> V_887 <<
V_888 ) &
V_889 ;
V_174 -> V_322 |= V_890 ;
}
if ( V_806 & V_891 ) {
V_174 -> V_803 . V_831 |= ( V_696 -> V_892 <<
V_893 ) &
V_894 ;
V_174 -> V_322 |= V_895 ;
}
if ( V_806 & V_896 ) {
V_174 -> V_803 . V_872 |= ( V_696 -> V_897 <<
V_898 )
& V_899 ;
V_174 -> V_322 |= V_900 ;
}
if ( V_806 & V_901 ) {
V_174 -> V_803 . V_827 |= ( V_696 -> V_902 & 0x00ffffff ) ;
V_174 -> V_322 |= V_903 ;
}
if ( V_806 & V_904 ) {
V_174 -> V_803 . V_836 |= ( V_696 -> V_905 & 0x00ffffff ) ;
V_174 -> V_322 |= V_906 ;
}
if ( V_806 & V_907 ) {
if ( V_696 -> V_908 > V_9 -> V_265 . V_407 ) {
V_41 = - V_72 ;
goto V_879;
}
V_244 -> V_760 = V_696 -> V_908 ;
V_174 -> V_322 |= V_909 ;
}
if ( V_806 & V_910 ) {
if ( V_696 -> V_911 > V_9 -> V_265 . V_411 ) {
V_41 = - V_72 ;
goto V_879;
}
V_244 -> V_757 = V_696 -> V_911 ;
V_174 -> V_322 |= V_912 ;
}
V_174 -> V_803 . V_758 = ( V_244 -> V_760 <<
V_913 ) |
( V_244 -> V_757 & V_914 ) ;
V_879:
return V_41 ;
}
int F_151 ( struct V_8 * V_9 , struct V_243 * V_244 ,
struct V_805 * V_696 , int V_806 )
{
int V_41 = - V_163 ;
struct V_804 * V_174 ;
V_174 = F_19 ( V_915 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_803 . V_120 = V_244 -> V_120 ;
V_174 -> V_322 = 0 ;
if ( V_806 & V_916 ) {
V_174 -> V_803 . V_726 |=
( F_10 ( V_696 -> V_917 ) <<
V_918 ) &
V_919 ;
V_174 -> V_322 |= V_920 ;
} else {
V_174 -> V_803 . V_726 |=
( V_244 -> V_682 << V_918 ) &
V_919 ;
}
V_41 = F_149 ( V_244 , V_174 , V_696 , V_806 ) ;
if ( V_41 )
goto V_200;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_152 ( struct V_8 * V_9 , struct V_243 * V_244 )
{
int V_41 = - V_163 ;
struct V_921 * V_174 ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_922 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_751 = V_244 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
if ( V_244 -> V_18 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_18 . V_161 , V_244 -> V_18 . V_4 , V_244 -> V_18 . V_195 ) ;
if ( ! V_244 -> V_292 && V_244 -> V_677 . V_4 )
F_22 ( & V_158 -> V_9 , V_244 -> V_677 . V_161 , V_244 -> V_677 . V_4 , V_244 -> V_677 . V_195 ) ;
if ( V_244 -> V_522 )
V_244 -> V_518 -> V_530 ++ ;
return V_41 ;
}
int F_153 ( struct V_8 * V_9 , struct V_782 * V_292 ,
struct V_923 * V_924 ,
struct V_517 * V_518 )
{
int V_41 = - V_163 ;
int V_593 , V_168 ;
int V_161 ;
struct V_925 * V_188 ;
struct V_926 * V_174 ;
T_4 V_195 ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
T_1 V_720 ;
V_174 = F_19 ( V_927 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_928 = V_518 -> V_120 & V_929 ;
V_720 = V_924 -> V_265 . V_930 + 1 ;
V_41 = F_102 ( & V_720 ,
V_9 -> V_265 . V_442 ,
& V_593 , & V_168 ) ;
if ( V_41 ) {
F_52 ( L_27 , V_299 ,
V_924 -> V_265 . V_930 ) ;
V_41 = - V_72 ;
goto V_931;
}
V_161 = V_593 * V_168 ;
V_292 -> V_677 . V_4 = F_24 ( & V_158 -> V_9 , V_161 , & V_195 , V_145 ) ;
if ( ! V_292 -> V_677 . V_4 ) {
V_41 = - V_163 ;
goto V_931;
}
F_25 ( & V_174 -> V_722 [ 0 ] , V_593 , V_195 , V_168 ) ;
V_292 -> V_677 . V_162 = V_9 -> V_265 . V_442 ;
V_292 -> V_677 . V_195 = V_195 ;
V_292 -> V_677 . V_161 = V_161 ;
V_292 -> V_677 . V_702 = V_720 ;
V_174 -> V_932 = F_130 ( V_720 ) ;
V_174 -> V_932 |= V_924 -> V_265 . V_933 <<
V_934 ;
V_174 -> V_928 |= ( F_130 ( V_168 / V_213 )
<< V_935 ) ;
V_174 -> V_936 |= ( V_9 -> V_265 . V_442
<< V_937 )
& V_938 ;
V_174 -> V_936 |= V_593 << V_939 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_925 * ) V_174 ;
V_292 -> V_120 = V_188 -> V_120 ;
V_292 -> V_677 . V_753 = V_188 -> V_120 ;
V_720 = ( ( V_188 -> V_940 &
V_941 ) >>
V_942 ) ;
V_720 = ( 1 << V_720 ) ;
V_292 -> V_677 . V_702 = V_720 ;
V_292 -> V_677 . V_769 = V_720 - 1 ;
V_292 -> V_677 . V_699 = ( V_188 -> V_940 &
V_943 ) >>
V_944 ;
goto V_931;
V_200:
F_22 ( & V_158 -> V_9 , V_292 -> V_677 . V_161 , V_292 -> V_677 . V_4 , V_195 ) ;
V_931:
F_87 ( V_174 ) ;
return V_41 ;
}
int F_154 ( struct V_782 * V_292 , struct V_945 * V_924 )
{
int V_41 = - V_163 ;
struct V_946 * V_174 ;
struct V_517 * V_518 = V_292 -> V_518 ;
struct V_8 * V_9 = F_123 ( V_518 -> V_697 . V_271 ) ;
V_174 = F_19 ( V_947 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_120 ;
V_174 -> V_948 |= V_924 -> V_949 <<
V_950 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
int F_155 ( struct V_782 * V_292 , struct V_945 * V_924 )
{
int V_41 = - V_163 ;
struct V_951 * V_174 ;
struct V_8 * V_9 = F_123 ( V_292 -> V_293 . V_271 ) ;
V_174 = F_19 ( V_952 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_677 . V_753 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 == 0 ) {
struct V_953 * V_188 =
(struct V_953 * ) V_174 ;
V_924 -> V_933 =
V_188 -> V_954 &
V_955 ;
V_924 -> V_930 =
V_188 -> V_956 >> V_957 ;
V_924 -> V_949 = V_188 -> V_954 >>
V_958 ;
}
F_87 ( V_174 ) ;
return V_41 ;
}
int F_156 ( struct V_8 * V_9 , struct V_782 * V_292 )
{
int V_41 = - V_163 ;
struct V_959 * V_174 ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
V_174 = F_19 ( V_960 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
V_174 -> V_120 = V_292 -> V_120 ;
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_292 -> V_677 . V_4 )
F_22 ( & V_158 -> V_9 , V_292 -> V_677 . V_161 ,
V_292 -> V_677 . V_4 , V_292 -> V_677 . V_195 ) ;
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_157 ( struct V_8 * V_9 , T_1 V_961 ,
struct V_962 * V_963 )
{
int V_41 ;
T_4 V_195 ;
struct V_17 V_174 ;
struct V_964 * V_182 = NULL ;
struct V_965 * V_188 = NULL ;
struct V_561 * V_158 = V_9 -> V_117 . V_158 ;
struct V_966 * V_967 = V_174 . V_153 . V_476 . V_477 ;
memset ( & V_174 , 0 , sizeof( struct V_17 ) ) ;
V_174 . V_146 . V_151 = F_158 ( T_1 , sizeof( struct V_965 ) ,
sizeof( struct V_964 ) ) ;
V_182 = F_24 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , & V_195 , V_145 ) ;
if ( ! V_182 ) {
V_41 = - V_163 ;
goto V_578;
}
V_174 . V_146 . V_147 |= ( 1 << V_474 ) &
V_475 ;
V_967 -> V_478 = ( T_1 ) ( V_195 & 0xFFFFFFFFUL ) ;
V_967 -> V_479 = ( T_1 ) F_26 ( V_195 ) ;
V_967 -> V_161 = V_174 . V_146 . V_151 ;
memset ( V_182 , 0 , sizeof( struct V_964 ) ) ;
F_18 ( & V_182 -> V_146 , V_968 ,
V_969 , V_174 . V_146 . V_151 ) ;
V_182 -> V_970 = V_961 ;
V_41 = F_80 ( V_9 , & V_174 ) ;
if ( V_41 )
goto V_200;
V_188 = (struct V_965 * ) V_182 ;
F_64 ( V_188 , sizeof( struct V_965 ) ) ;
memcpy ( V_963 , & V_188 -> V_971 , sizeof( struct V_962 ) ) ;
V_200:
F_22 ( & V_158 -> V_9 , V_174 . V_146 . V_151 , V_182 , V_195 ) ;
V_578:
return V_41 ;
}
static int F_159 ( struct V_8 * V_9 , int V_961 ,
struct V_962 * V_963 ,
T_2 * V_972 )
{
int V_41 = - V_72 , V_973 , V_974 ;
int V_975 ;
struct V_976 * V_977 ;
T_2 V_192 , V_978 ;
T_2 V_979 , V_980 ;
T_3 V_981 ;
if ( ! ( V_963 -> V_982 & V_983 ) ) {
F_160 ( L_28 ,
F_161 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
goto V_984;
}
if ( ! F_162 ( V_963 -> V_853 ) ) {
F_160 ( L_29 ,
F_161 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
( V_961 > 0 ? L_30 : L_31 ) ,
( V_963 -> V_853 & V_985 ) ?
L_32 : L_33 ,
( V_963 -> V_853 & V_986 ) ?
L_1 : L_34 ) ;
goto V_984;
} else {
F_160 ( L_35 ,
F_161 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
}
V_975 = ( V_963 -> V_982 >>
V_987 )
& V_983 ;
for ( V_973 = 0 ; V_973 < V_975 ; V_973 ++ ) {
V_977 = & V_963 -> V_977 [ V_973 ] ;
V_192 = ( V_977 -> V_988 >>
V_989 )
& V_990 ;
V_978 = ( V_977 -> V_988
>> V_991 )
& V_992 ;
V_981 = V_977 -> V_988 &
V_993 ;
if (
V_192 && V_981 == V_994 &&
V_978 == V_995 ) {
for ( V_974 = 0 ; V_974 <
V_996 ; V_974 ++ ) {
V_979 = F_163 (
( T_2 * ) V_977 -> V_979 ,
V_974 ) ;
V_980 = F_164 (
( T_2 * ) V_963 -> V_980 ,
V_974 ) ;
if ( V_979 && V_980 ) {
* V_972 = V_974 ;
V_41 = 0 ;
goto V_984;
}
}
if ( V_974 == V_996 ) {
F_160 ( L_36 ,
F_161 ( & V_9 -> V_117 . V_158 -> V_9 ) ,
V_9 -> V_120 , V_981 ) ;
}
}
}
V_984:
return V_41 ;
}
void F_141 ( struct V_8 * V_9 )
{
int V_41 = 0 , V_973 ;
struct V_962 V_963 ;
T_2 V_972 = V_997 ;
int V_961 = V_998 ;
for ( V_973 = 0 ; V_973 < 2 ; V_973 ++ ) {
V_41 = F_157 ( V_9 , V_961 , & V_963 ) ;
if ( V_41 ) {
F_52 ( L_37 , V_299 , V_41 ) ;
V_961 = V_999 ;
continue;
}
V_41 = F_159 ( V_9 , V_961 ,
& V_963 , & V_972 ) ;
if ( V_41 ) {
V_961 = V_999 ;
continue;
}
break;
}
if ( V_41 )
F_160 ( L_38 ,
F_161 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ) ;
else
F_160 ( L_39 ,
F_161 ( & V_9 -> V_117 . V_158 -> V_9 ) , V_9 -> V_120 ,
V_972 ) ;
V_9 -> V_853 = F_162 ( V_963 . V_853 ) ;
V_9 -> V_834 = V_972 ;
}
int F_165 ( struct V_8 * V_9 , struct V_1000 * V_1001 )
{
int V_169 ;
int V_41 = - V_72 ;
struct V_567 * V_1002 ;
unsigned long V_322 ;
V_1002 = V_9 -> V_566 . V_4 ;
F_69 ( & V_9 -> V_566 . V_239 , V_322 ) ;
for ( V_169 = 0 ; V_169 < V_9 -> V_566 . V_580 ; V_169 ++ ) {
if ( V_1002 -> V_192 == 0 ) {
V_1002 -> V_192 = V_1003 ;
V_1001 -> V_1002 = V_1002 ;
V_1001 -> V_120 = V_169 ;
V_41 = 0 ;
break;
}
V_1002 ++ ;
}
if ( V_169 == V_9 -> V_566 . V_580 )
V_41 = - V_51 ;
F_70 ( & V_9 -> V_566 . V_239 , V_322 ) ;
return V_41 ;
}
int F_166 ( struct V_8 * V_9 , struct V_1000 * V_1001 )
{
unsigned long V_322 ;
F_69 ( & V_9 -> V_566 . V_239 , V_322 ) ;
V_1001 -> V_1002 -> V_192 = 0 ;
F_70 ( & V_9 -> V_566 . V_239 , V_322 ) ;
return 0 ;
}
static int F_167 ( struct V_8 * V_9 )
{
int V_1004 , V_169 , V_41 = 0 ;
int V_201 ;
unsigned long V_322 = 0 ;
V_1004 = V_9 -> V_117 . V_204 . V_1005 -
V_9 -> V_117 . V_204 . V_1006 ;
if ( V_9 -> V_117 . V_202 == V_203 ) {
V_1004 = 1 ;
V_322 = V_1007 ;
} else {
V_1004 = F_129 ( T_1 , V_1004 , F_168 () ) ;
}
if ( ! V_1004 )
return - V_72 ;
V_9 -> V_207 = F_20 ( sizeof( struct V_1 ) * V_1004 , V_145 ) ;
if ( ! V_9 -> V_207 )
return - V_163 ;
for ( V_169 = 0 ; V_169 < V_1004 ; V_169 ++ ) {
V_41 = F_31 ( V_9 , & V_9 -> V_207 [ V_169 ] ,
V_7 ) ;
if ( V_41 ) {
V_41 = - V_72 ;
break;
}
sprintf ( V_9 -> V_207 [ V_169 ] . V_1008 , L_40 ,
V_9 -> V_120 , V_169 ) ;
V_201 = F_32 ( V_9 , & V_9 -> V_207 [ V_169 ] ) ;
V_41 = F_169 ( V_201 , F_73 , V_322 ,
V_9 -> V_207 [ V_169 ] . V_1008 ,
& V_9 -> V_207 [ V_169 ] ) ;
if ( V_41 )
goto V_1009;
V_9 -> V_206 += 1 ;
}
return 0 ;
V_1009:
F_36 ( V_9 ) ;
return V_41 ;
}
static int F_170 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_1010 )
{
int V_169 , V_41 = - V_163 ;
struct V_1011 * V_174 ;
V_174 = F_19 ( V_1012 , sizeof( * V_174 ) ) ;
if ( ! V_174 )
return V_41 ;
F_18 ( & V_174 -> V_174 . V_182 , V_1012 ,
V_183 , sizeof( * V_174 ) ) ;
V_174 -> V_174 . V_1004 = V_1010 ;
for ( V_169 = 0 ; V_169 < V_1010 ; V_169 ++ ) {
V_174 -> V_174 . V_1013 [ V_169 ] . V_124 = V_2 [ V_169 ] . V_3 . V_120 ;
V_174 -> V_174 . V_1013 [ V_169 ] . V_1014 = 0 ;
V_174 -> V_174 . V_1013 [ V_169 ] . V_1015 =
( V_2 [ V_169 ] . V_364 . V_1016 * 65 ) / 100 ;
}
V_41 = F_80 ( V_9 , (struct V_17 * ) V_174 ) ;
if ( V_41 )
goto V_200;
V_200:
F_87 ( V_174 ) ;
return V_41 ;
}
static int F_171 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_1010 )
{
int V_1017 , V_169 = 0 ;
if ( V_1010 > 8 ) {
while ( V_1010 ) {
V_1017 = F_118 ( V_1010 , 8 ) ;
F_170 ( V_9 , & V_2 [ V_169 ] , V_1017 ) ;
V_169 += V_1017 ;
V_1010 -= V_1017 ;
}
} else {
F_170 ( V_9 , V_2 , V_1010 ) ;
}
return 0 ;
}
void F_172 ( struct V_1018 * V_1019 )
{
struct V_8 * V_9 =
F_173 ( V_1019 , struct V_8 , V_1020 . V_1019 ) ;
struct V_1 * V_2 = 0 ;
int V_169 , V_1010 = 0 , V_41 = - V_72 ;
V_426 V_1021 ;
for ( V_169 = 0 ; V_169 < V_9 -> V_206 ; V_169 ++ ) {
V_2 = & V_9 -> V_207 [ V_169 ] ;
if ( V_2 -> V_364 . V_365 > V_2 -> V_364 . V_1022 ) {
V_1021 = V_2 -> V_364 . V_365 -
V_2 -> V_364 . V_1022 ;
if ( ( V_1021 > V_1023 ) &&
( V_2 -> V_364 . V_1016 == V_1024 ) ) {
V_2 -> V_364 . V_1016 = V_1025 ;
V_1010 ++ ;
} else if ( ( V_1021 < V_1026 ) &&
( V_2 -> V_364 . V_1016 == V_1025 ) ) {
V_2 -> V_364 . V_1016 = V_1024 ;
V_1010 ++ ;
}
}
V_2 -> V_364 . V_1022 = V_2 -> V_364 . V_365 ;
}
if ( V_1010 )
V_41 = F_171 ( V_9 , & V_9 -> V_207 [ 0 ] , V_1010 ) ;
F_174 ( & V_9 -> V_1020 , F_79 ( 1000 ) ) ;
}
int F_175 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_167 ( V_9 ) ;
if ( V_41 )
goto V_1027;
V_41 = F_43 ( V_9 ) ;
if ( V_41 )
goto V_1028;
V_41 = F_88 ( V_9 ) ;
if ( V_41 )
goto V_1029;
V_41 = F_92 ( V_9 ) ;
if ( V_41 )
goto V_1029;
V_41 = F_86 ( V_9 ) ;
if ( V_41 )
goto V_1029;
V_41 = F_105 ( V_9 ) ;
if ( V_41 )
goto V_1029;
V_41 = F_94 ( V_9 ) ;
if ( V_41 )
goto V_1030;
V_41 = F_91 ( V_9 ) ;
if ( V_41 )
goto V_1030;
return 0 ;
V_1030:
F_107 ( V_9 ) ;
V_1029:
F_46 ( V_9 ) ;
V_1028:
F_36 ( V_9 ) ;
V_1027:
F_52 ( L_18 , V_299 , V_41 ) ;
return V_41 ;
}
void F_176 ( struct V_8 * V_9 )
{
F_101 ( V_9 ) ;
F_107 ( V_9 ) ;
F_46 ( V_9 ) ;
F_36 ( V_9 ) ;
}
