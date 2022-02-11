static inline void * F_1 ( struct V_1 * V_2 )
{
return ( V_3 * ) V_2 -> V_4 . V_5 + ( V_2 -> V_4 . V_6 * sizeof( struct V_7 ) ) ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_4 . V_6 = ( V_2 -> V_4 . V_6 + 1 ) & ( V_8 - 1 ) ;
}
static inline void * F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = (struct V_11 * )
( ( V_3 * ) V_10 -> V_13 . V_14 . V_5 +
( V_10 -> V_13 . V_14 . V_6 * sizeof( struct V_11 ) ) ) ;
if ( ! ( F_4 ( V_12 -> V_15 ) & V_16 ) )
return NULL ;
return V_12 ;
}
static inline void F_5 ( struct V_9 * V_10 )
{
V_10 -> V_13 . V_14 . V_6 = ( V_10 -> V_13 . V_14 . V_6 + 1 ) & ( V_17 - 1 ) ;
}
static inline struct V_18 * F_6 ( struct V_9 * V_10 )
{
return (struct V_18 * ) ( ( V_3 * ) V_10 -> V_13 . V_19 . V_5 +
( V_10 -> V_13 . V_19 . V_20 *
sizeof( struct V_18 ) ) ) ;
}
static inline void F_7 ( struct V_9 * V_10 )
{
V_10 -> V_13 . V_19 . V_20 = ( V_10 -> V_13 . V_19 . V_20 + 1 ) & ( V_21 - 1 ) ;
F_8 ( & V_10 -> V_13 . V_19 . V_22 ) ;
}
static inline void * F_9 ( struct V_9 * V_10 )
{
return ( void * ) ( ( V_3 * ) V_10 -> V_13 . V_19 . V_5 +
( V_10 -> V_23 . V_24 * sizeof( struct V_18 ) ) ) ;
}
enum V_25 F_10 ( enum V_26 V_27 )
{
switch ( V_27 ) {
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
} ;
return V_42 ;
}
static enum V_26 F_11 ( enum V_25 V_27 )
{
switch ( V_27 ) {
case V_29 :
return V_28 ;
case V_31 :
return V_30 ;
case V_33 :
return V_32 ;
case V_35 :
return V_34 ;
case V_38 :
return V_36 ;
case V_40 :
return V_39 ;
case V_42 :
return V_41 ;
} ;
return V_41 ;
}
static int F_12 ( T_1 V_43 )
{
int V_44 = - V_45 ;
V_3 V_46 = ( V_43 & V_47 ) >>
V_48 ;
V_3 V_49 = ( V_43 & V_50 ) >>
V_51 ;
switch ( V_46 ) {
case V_52 :
case V_53 :
V_44 = - V_54 ;
break;
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
case V_72 :
case V_73 :
case V_74 :
V_44 = - V_75 ;
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_44 = - V_80 ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_44 = - V_90 ;
break;
case V_91 :
switch ( V_49 ) {
case V_92 :
V_44 = - V_54 ;
break;
}
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_13 ( T_2 V_93 )
{
int V_44 = - V_75 ;
switch ( V_93 ) {
case V_94 :
V_44 = - V_95 ;
break;
case V_96 :
V_44 = - V_75 ;
break;
case V_97 :
case V_98 :
V_44 = - V_54 ;
break;
case V_99 :
V_44 = - V_100 ;
break;
}
return V_44 ;
}
void F_14 ( struct V_9 * V_10 , T_2 V_101 , bool V_102 ,
bool V_103 , T_2 V_104 )
{
T_1 V_105 = V_101 & V_106 ;
V_105 |= ( ( V_101 & V_107 ) <<
V_108 ) ;
if ( V_102 )
V_105 |= ( 1 << V_109 ) ;
if ( V_103 )
V_105 |= ( 1 << V_110 ) ;
V_105 |= ( V_104 << V_111 ) ;
F_15 ( V_105 , V_10 -> V_112 . V_113 + V_114 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
T_1 V_105 = 0 ;
V_105 |= V_10 -> V_13 . V_19 . V_115 & V_116 ;
V_105 |= 1 << V_117 ;
F_15 ( V_105 , V_10 -> V_112 . V_113 + V_118 ) ;
}
static void F_17 ( struct V_9 * V_10 , T_2 V_119 ,
bool V_120 , bool V_121 , T_2 V_122 )
{
T_1 V_105 = 0 ;
V_105 |= V_119 & V_123 ;
V_105 |= ( ( V_119 & V_124 ) << V_125 ) ;
if ( V_120 )
V_105 |= ( 1 << V_126 ) ;
if ( V_121 )
V_105 |= ( 1 << V_127 ) ;
V_105 |= ( 1 << V_128 ) ;
V_105 |= ( V_122 << V_129 ) ;
F_15 ( V_105 , V_10 -> V_112 . V_113 + V_130 ) ;
}
static void F_18 ( struct V_131 * V_132 ,
V_3 V_133 , V_3 V_134 , T_1 V_135 )
{
V_132 -> V_136 = ( V_133 | ( V_134 << V_137 ) ) ;
V_132 -> V_138 = 20 ;
V_132 -> V_135 = V_135 - sizeof( struct V_131 ) ;
}
static void * F_19 ( V_3 V_133 , T_1 V_135 )
{
struct V_18 * V_139 ;
V_139 = F_20 ( sizeof( struct V_18 ) , V_140 ) ;
if ( ! V_139 )
return NULL ;
V_139 -> V_141 . V_142 |=
( V_143 << V_144 ) &
V_145 ;
V_139 -> V_141 . V_146 = V_135 - sizeof( struct V_147 ) ;
F_18 ( & V_139 -> V_148 . V_149 . V_150 , V_133 , V_151 ,
V_139 -> V_141 . V_146 ) ;
return V_139 ;
}
static void F_21 ( struct V_9 * V_10 , struct V_152 * V_4 )
{
F_22 ( & V_10 -> V_112 . V_153 -> V_10 , V_4 -> V_154 , V_4 -> V_5 , V_4 -> V_155 ) ;
}
static int F_23 ( struct V_9 * V_10 ,
struct V_152 * V_4 , T_2 V_156 , T_2 V_157 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_156 = V_156 ;
V_4 -> V_157 = V_157 ;
V_4 -> V_154 = V_156 * V_157 ;
V_4 -> V_5 = F_24 ( & V_10 -> V_112 . V_153 -> V_10 , V_4 -> V_154 ,
& V_4 -> V_155 , V_140 ) ;
if ( ! V_4 -> V_5 )
return - V_158 ;
memset ( V_4 -> V_5 , 0 , V_4 -> V_154 ) ;
return 0 ;
}
static void F_25 ( struct V_159 * V_160 , int V_161 ,
T_3 V_162 , int V_163 )
{
int V_164 ;
for ( V_164 = 0 ; V_164 < V_161 ; V_164 ++ ) {
V_160 [ V_164 ] . V_165 = ( T_1 ) ( V_162 & 0xffffffff ) ;
V_160 [ V_164 ] . V_166 = ( T_1 ) F_26 ( V_162 ) ;
V_162 += V_163 ;
}
}
static void F_27 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
V_2 -> V_167 = V_10 -> V_112 . V_168 . V_169 ;
V_10 -> V_112 . V_168 . V_169 += 1 ;
}
static void F_28 ( struct V_9 * V_10 )
{
V_10 -> V_112 . V_168 . V_169 -= 1 ;
}
static int F_29 ( struct V_9 * V_10 , struct V_152 * V_4 ,
int V_170 )
{
V_3 V_133 = 0 ;
int V_43 ;
struct V_171 * V_172 = V_10 -> V_173 ;
switch ( V_170 ) {
case V_174 :
V_133 = V_175 ;
break;
case V_176 :
V_133 = V_177 ;
break;
case V_178 :
V_133 = V_179 ;
break;
default:
F_30 () ;
}
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
F_18 ( & V_172 -> V_180 , V_133 , V_181 , sizeof( * V_172 ) ) ;
V_172 -> V_115 = V_4 -> V_115 ;
V_43 = F_31 ( V_10 -> V_112 . V_182 ,
V_172 , sizeof( * V_172 ) , NULL , NULL ) ;
if ( ! V_43 )
V_4 -> V_183 = false ;
return V_43 ;
}
static int F_32 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
int V_43 ;
struct V_184 * V_172 = V_10 -> V_173 ;
struct V_185 * V_186 = V_10 -> V_173 ;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
F_18 ( & V_172 -> V_180 , V_187 , V_181 ,
sizeof( * V_172 ) ) ;
if ( V_10 -> V_112 . V_188 == V_189 )
V_172 -> V_180 . V_190 = 0 ;
else
V_172 -> V_180 . V_190 = 2 ;
V_172 -> V_191 = 4 ;
V_172 -> V_192 = V_193 ;
V_172 -> V_161 = 4 << V_194 ;
F_25 ( & V_172 -> V_195 [ 0 ] , V_172 -> V_191 , V_2 -> V_4 . V_155 ,
V_196 ) ;
V_43 = F_31 ( V_10 -> V_112 . V_182 , V_172 , sizeof( * V_172 ) , NULL ,
NULL ) ;
if ( ! V_43 ) {
V_2 -> V_4 . V_115 = V_186 -> V_197 & 0xffff ;
if ( V_10 -> V_112 . V_188 == V_189 )
F_27 ( V_10 , V_2 ) ;
else {
V_2 -> V_167 = ( V_186 -> V_197 >> 16 ) & 0xffff ;
V_10 -> V_112 . V_168 . V_169 += 1 ;
}
V_2 -> V_4 . V_183 = true ;
}
return V_43 ;
}
static int F_33 ( struct V_9 * V_10 ,
struct V_1 * V_2 , T_2 V_198 )
{
int V_43 ;
V_43 = F_23 ( V_10 , & V_2 -> V_4 , V_8 ,
sizeof( struct V_7 ) ) ;
if ( V_43 )
return V_43 ;
V_43 = F_32 ( V_10 , V_2 ) ;
if ( V_43 )
goto V_199;
V_2 -> V_10 = V_10 ;
F_17 ( V_10 , V_2 -> V_4 . V_115 , true , true , 0 ) ;
return 0 ;
V_199:
F_21 ( V_10 , & V_2 -> V_4 ) ;
return V_43 ;
}
static int F_34 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
int V_200 ;
if ( V_10 -> V_112 . V_201 == V_202 )
V_200 = V_10 -> V_112 . V_153 -> V_200 ;
else
V_200 = V_10 -> V_112 . V_168 . V_203 [ V_2 -> V_167 ] ;
return V_200 ;
}
static void F_35 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_183 ) {
F_29 ( V_10 , & V_2 -> V_4 , V_178 ) ;
if ( V_10 -> V_112 . V_188 == V_189 )
F_28 ( V_10 ) ;
F_21 ( V_10 , & V_2 -> V_4 ) ;
}
}
static void F_36 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
int V_200 ;
F_17 ( V_10 , V_2 -> V_4 . V_115 , false , false , 0 ) ;
V_200 = F_34 ( V_10 , V_2 ) ;
F_37 ( V_200 , V_2 ) ;
F_35 ( V_10 , V_2 ) ;
}
static void F_38 ( struct V_9 * V_10 )
{
int V_164 ;
for ( V_164 = 0 ; V_164 < V_10 -> V_204 ; V_164 ++ )
F_36 ( V_10 , & V_10 -> V_205 [ V_164 ] ) ;
}
static int F_39 ( struct V_9 * V_10 ,
struct V_152 * V_14 ,
struct V_152 * V_2 )
{
struct V_206 * V_172 = V_10 -> V_173 ;
struct V_207 * V_186 = V_10 -> V_173 ;
int V_43 ;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
F_18 ( & V_172 -> V_180 , V_208 ,
V_181 , sizeof( * V_172 ) ) ;
V_172 -> V_209 = F_40 ( V_14 -> V_5 , V_14 -> V_154 ) ;
V_172 -> V_210 = V_211 ;
V_172 -> V_212 = ( V_2 -> V_115 << V_213 ) ;
F_25 ( & V_172 -> V_195 [ 0 ] , V_172 -> V_209 ,
V_14 -> V_155 , V_196 ) ;
V_43 = F_31 ( V_10 -> V_112 . V_182 ,
V_172 , sizeof( * V_172 ) , NULL , NULL ) ;
if ( ! V_43 ) {
V_14 -> V_115 = ( V_186 -> V_101 & V_214 ) ;
V_14 -> V_183 = true ;
}
return V_43 ;
}
static T_1 F_41 ( int V_198 )
{
T_1 V_215 = F_42 ( V_198 ) ;
if ( V_215 == 16 )
V_215 = 0 ;
return V_215 ;
}
static int F_43 ( struct V_9 * V_10 ,
struct V_152 * V_13 ,
struct V_152 * V_14 )
{
int V_191 , V_43 ;
struct V_216 * V_172 = V_10 -> V_173 ;
struct V_217 * V_186 = V_10 -> V_173 ;
struct V_159 * V_195 ;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
V_191 = F_40 ( V_13 -> V_5 , V_13 -> V_154 ) ;
if ( V_10 -> V_112 . V_188 == V_189 ) {
F_18 ( & V_172 -> V_180 , V_218 ,
V_181 , sizeof( * V_172 ) ) ;
V_172 -> V_219 . V_220 = V_191 ;
V_172 -> V_219 . V_221 = V_222 ;
V_172 -> V_219 . V_221 = ( V_14 -> V_115 << 1 ) ;
V_172 -> V_219 . V_223 |= ( F_41 ( V_13 -> V_156 ) <<
V_224 ) ;
V_172 -> V_219 . V_223 |=
( V_14 -> V_115 << V_225 ) ;
V_172 -> V_219 . V_192 = V_226 ;
V_195 = & V_172 -> V_219 . V_195 [ 0 ] ;
} else {
F_18 ( & V_172 -> V_180 , V_227 ,
V_181 , sizeof( * V_172 ) ) ;
V_172 -> V_180 . V_190 = 1 ;
V_172 -> V_228 . V_229 = V_191 ;
V_172 -> V_228 . V_229 |= ( V_14 -> V_115 << V_230 ) ;
V_172 -> V_228 . V_221 = V_222 ;
V_172 -> V_228 . V_231 = F_44 ( 20 ) ;
V_172 -> V_228 . V_232 = V_14 -> V_115 ;
V_172 -> V_228 . V_232 |= ( F_41 ( V_13 -> V_156 ) <<
V_224 ) ;
V_172 -> V_228 . V_192 = V_226 ;
V_195 = & V_172 -> V_228 . V_195 [ 0 ] ;
}
F_25 ( V_195 , V_191 , V_13 -> V_155 , V_196 ) ;
V_43 = F_31 ( V_10 -> V_112 . V_182 ,
V_172 , sizeof( * V_172 ) , NULL , NULL ) ;
if ( ! V_43 ) {
V_13 -> V_115 = V_186 -> V_115 ;
V_13 -> V_183 = true ;
}
return V_43 ;
}
static int F_45 ( struct V_9 * V_10 )
{
int V_43 ;
V_43 = F_23 ( V_10 , & V_10 -> V_13 . V_14 , V_17 ,
sizeof( struct V_11 ) ) ;
if ( V_43 )
goto V_233;
V_43 = F_39 ( V_10 , & V_10 -> V_13 . V_14 , & V_10 -> V_234 . V_4 ) ;
if ( V_43 )
goto V_235;
memset ( & V_10 -> V_23 , 0 , sizeof( V_10 -> V_23 ) ) ;
F_46 ( & V_10 -> V_23 . V_236 ) ;
F_47 ( & V_10 -> V_23 . V_237 ) ;
V_43 = F_23 ( V_10 , & V_10 -> V_13 . V_19 , V_21 ,
sizeof( struct V_18 ) ) ;
if ( V_43 )
goto V_238;
V_43 = F_43 ( V_10 , & V_10 -> V_13 . V_19 , & V_10 -> V_13 . V_14 ) ;
if ( V_43 )
goto V_239;
F_14 ( V_10 , V_10 -> V_13 . V_14 . V_115 , true , false , 0 ) ;
return 0 ;
V_239:
F_21 ( V_10 , & V_10 -> V_13 . V_19 ) ;
V_238:
F_29 ( V_10 , & V_10 -> V_13 . V_14 , V_176 ) ;
V_235:
F_21 ( V_10 , & V_10 -> V_13 . V_14 ) ;
V_233:
return V_43 ;
}
static void F_48 ( struct V_9 * V_10 )
{
struct V_152 * V_240 , * V_14 ;
F_49 ( & V_10 -> V_23 . V_237 ) ;
V_240 = & V_10 -> V_13 . V_19 ;
if ( V_240 -> V_183 ) {
F_29 ( V_10 , V_240 , V_174 ) ;
F_21 ( V_10 , V_240 ) ;
}
F_50 ( & V_10 -> V_23 . V_237 ) ;
V_14 = & V_10 -> V_13 . V_14 ;
if ( V_14 -> V_183 ) {
F_29 ( V_10 , V_14 , V_176 ) ;
F_21 ( V_10 , V_14 ) ;
}
}
static void F_51 ( struct V_9 * V_10 ,
struct V_241 * V_242 )
{
enum V_25 V_243 = V_42 ;
enum V_25 V_244 ;
if ( V_242 == NULL )
F_30 () ;
F_52 ( V_242 , V_243 , & V_244 ) ;
}
static void F_53 ( struct V_9 * V_10 ,
struct V_245 * V_12 )
{
struct V_241 * V_242 = NULL ;
struct V_246 * V_14 = NULL ;
struct V_247 V_248 ;
int V_249 = 0 ;
int V_250 = 1 ;
int V_251 = 0 ;
int V_252 = 0 ;
int type = ( V_12 -> V_253 & V_254 ) >>
V_255 ;
if ( V_12 -> V_256 & V_257 )
V_242 = V_10 -> V_258 [ V_12 -> V_256 & V_259 ] ;
if ( V_12 -> V_260 & V_261 )
V_14 = V_10 -> V_262 [ V_12 -> V_260 & V_263 ] ;
V_248 . V_264 = & V_10 -> V_265 ;
switch ( type ) {
case V_266 :
V_248 . V_267 . V_14 = & V_14 -> V_268 ;
V_248 . V_269 = V_270 ;
V_249 = 1 ;
V_250 = 0 ;
break;
case V_271 :
V_248 . V_267 . V_14 = & V_14 -> V_268 ;
V_248 . V_269 = V_270 ;
break;
case V_272 :
V_248 . V_267 . V_242 = & V_242 -> V_273 ;
V_248 . V_269 = V_274 ;
F_51 ( V_10 , V_242 ) ;
break;
case V_275 :
V_248 . V_267 . V_242 = & V_242 -> V_273 ;
V_248 . V_269 = V_276 ;
break;
case V_277 :
V_248 . V_267 . V_242 = & V_242 -> V_273 ;
V_248 . V_269 = V_278 ;
break;
case V_279 :
V_248 . V_267 . V_242 = & V_242 -> V_273 ;
V_248 . V_269 = V_280 ;
break;
case V_281 :
V_248 . V_267 . V_282 = 1 ;
V_248 . V_269 = V_283 ;
V_250 = 0 ;
V_252 = 1 ;
break;
case V_284 :
V_248 . V_267 . V_285 = & V_242 -> V_285 -> V_286 ;
V_248 . V_269 = V_287 ;
V_251 = 1 ;
V_250 = 0 ;
break;
case V_288 :
V_248 . V_267 . V_285 = & V_242 -> V_285 -> V_286 ;
V_248 . V_269 = V_289 ;
V_251 = 1 ;
V_250 = 0 ;
break;
case V_290 :
V_248 . V_267 . V_242 = & V_242 -> V_273 ;
V_248 . V_269 = V_291 ;
break;
default:
V_249 = 0 ;
V_250 = 0 ;
V_251 = 0 ;
V_252 = 0 ;
F_54 ( L_1 , V_292 , type ) ;
break;
}
if ( V_250 ) {
if ( V_242 -> V_273 . V_293 )
V_242 -> V_273 . V_293 ( & V_248 , V_242 -> V_273 . V_294 ) ;
} else if ( V_249 ) {
if ( V_14 -> V_268 . V_293 )
V_14 -> V_268 . V_293 ( & V_248 , V_14 -> V_268 . V_295 ) ;
} else if ( V_251 ) {
if ( V_242 -> V_285 -> V_286 . V_293 )
V_242 -> V_285 -> V_286 . V_293 ( & V_248 ,
V_242 -> V_285 -> V_286 .
V_296 ) ;
} else if ( V_252 )
F_55 ( & V_248 ) ;
}
static void F_56 ( struct V_9 * V_10 , void * V_297 )
{
struct V_245 * V_12 = V_297 ;
T_1 V_298 = ( V_12 -> V_253 & V_299 ) >>
V_300 ;
if ( V_298 == V_301 )
F_53 ( V_10 , V_12 ) ;
else
F_54 ( L_2 ,
V_292 , V_10 -> V_115 , V_298 ) ;
}
static void F_57 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
if ( V_10 -> V_23 . V_24 == V_12 -> V_302 && V_10 -> V_23 . V_303 == false ) {
V_10 -> V_23 . V_93 = ( V_12 -> V_43 &
V_304 ) >> V_305 ;
V_10 -> V_23 . V_306 =
( V_12 -> V_43 & V_307 )
>> V_308 ;
V_10 -> V_23 . V_303 = true ;
F_58 ( & V_10 -> V_23 . V_236 ) ;
} else
F_54 ( L_3 ,
V_292 , V_12 -> V_302 , V_10 -> V_23 . V_24 ) ;
}
static int F_59 ( struct V_9 * V_10 , T_2 V_101 )
{
T_2 V_104 = 0 ;
struct V_11 * V_12 ;
while ( 1 ) {
V_12 = F_3 ( V_10 ) ;
if ( V_12 == NULL )
break;
F_60 ( V_12 , sizeof( * V_12 ) ) ;
V_104 += 1 ;
if ( V_12 -> V_15 & V_309 )
F_56 ( V_10 , V_12 ) ;
else if ( V_12 -> V_15 & V_310 )
F_57 ( V_10 , V_12 ) ;
else
F_54 ( L_4 , V_292 ) ;
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
F_5 ( V_10 ) ;
}
F_14 ( V_10 , V_10 -> V_13 . V_14 . V_115 , true , false , V_104 ) ;
return 0 ;
}
static void F_61 ( struct V_9 * V_10 ,
struct V_246 * V_14 )
{
unsigned long V_311 ;
struct V_241 * V_242 ;
bool V_312 = false ;
F_62 ( & V_10 -> V_313 , V_311 ) ;
F_63 (qp, &cq->sq_head, sq_entry) {
if ( V_242 -> V_285 )
continue;
if ( V_242 -> V_314 == V_242 -> V_315 )
continue;
if ( V_242 -> V_314 == V_14 )
V_14 = V_242 -> V_315 ;
else
V_14 = V_242 -> V_314 ;
V_312 = true ;
break;
}
F_64 ( & V_10 -> V_313 , V_311 ) ;
if ( V_312 == false )
return;
if ( V_14 -> V_268 . V_316 ) {
F_62 ( & V_14 -> V_317 , V_311 ) ;
(* V_14 -> V_268 . V_316 ) ( & V_14 -> V_268 , V_14 -> V_268 . V_295 ) ;
F_64 ( & V_14 -> V_317 , V_311 ) ;
}
}
static void F_65 ( struct V_9 * V_10 , T_2 V_318 )
{
unsigned long V_311 ;
struct V_246 * V_14 ;
if ( V_318 >= V_319 )
F_30 () ;
V_14 = V_10 -> V_262 [ V_318 ] ;
if ( V_14 == NULL ) {
F_54 ( L_5 , V_292 , V_10 -> V_115 , V_318 ) ;
return;
}
F_62 ( & V_14 -> V_320 , V_311 ) ;
V_14 -> V_102 = false ;
V_14 -> V_103 = false ;
F_64 ( & V_14 -> V_320 , V_311 ) ;
F_14 ( V_10 , V_14 -> V_115 , false , false , 0 ) ;
if ( V_14 -> V_268 . V_316 ) {
F_62 ( & V_14 -> V_317 , V_311 ) ;
(* V_14 -> V_268 . V_316 ) ( & V_14 -> V_268 , V_14 -> V_268 . V_295 ) ;
F_64 ( & V_14 -> V_317 , V_311 ) ;
}
F_61 ( V_10 , V_14 ) ;
}
static void F_66 ( struct V_9 * V_10 , T_2 V_101 )
{
if ( V_101 == V_10 -> V_13 . V_14 . V_115 )
F_59 ( V_10 , V_101 ) ;
else
F_65 ( V_10 , V_101 ) ;
}
static T_4 F_67 ( int V_200 , void * V_321 )
{
struct V_1 * V_2 = V_321 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_7 V_322 ;
struct V_7 * V_323 ;
T_2 V_324 = 0 ;
T_2 V_101 ;
while ( 1 ) {
V_323 = F_1 ( V_2 ) ;
V_322 = * V_323 ;
F_60 ( & V_322 , sizeof( V_322 ) ) ;
if ( ( V_322 . V_325 & V_326 ) == 0 )
break;
V_324 += 1 ;
V_323 -> V_325 = 0 ;
if ( ( V_322 . V_325 & V_327 ) == 0 ) {
V_101 = V_322 . V_325 >> V_328 ;
F_66 ( V_10 , V_101 ) ;
}
F_2 ( V_2 ) ;
}
F_17 ( V_10 , V_2 -> V_4 . V_115 , true , true , V_324 ) ;
if ( V_10 -> V_112 . V_201 == V_202 )
F_17 ( V_10 , V_2 -> V_4 . V_115 , true , true , 0 ) ;
return V_329 ;
}
static void F_68 ( struct V_9 * V_10 , struct V_18 * V_172 )
{
struct V_18 * V_139 ;
V_10 -> V_23 . V_24 = V_10 -> V_13 . V_19 . V_20 ;
V_10 -> V_23 . V_303 = false ;
V_139 = F_6 ( V_10 ) ;
V_172 -> V_141 . V_302 = V_10 -> V_13 . V_19 . V_20 ;
F_69 ( V_139 , V_172 , sizeof( * V_139 ) ) ;
F_70 () ;
F_7 ( V_10 ) ;
F_16 ( V_10 ) ;
}
static int F_71 ( struct V_9 * V_10 )
{
long V_43 ;
V_43 = F_72 ( V_10 -> V_23 . V_236 ,
( V_10 -> V_23 . V_303 != false ) ,
F_73 ( 30000 ) ) ;
if ( V_43 )
return 0 ;
else
return - 1 ;
}
static int F_74 ( struct V_9 * V_10 , struct V_18 * V_139 )
{
int V_43 = 0 ;
T_2 V_93 , V_306 ;
struct V_18 * V_186 ;
F_49 ( & V_10 -> V_23 . V_237 ) ;
F_68 ( V_10 , V_139 ) ;
V_43 = F_71 ( V_10 ) ;
if ( V_43 )
goto V_199;
V_93 = V_10 -> V_23 . V_93 ;
V_306 = V_10 -> V_23 . V_306 ;
V_186 = F_9 ( V_10 ) ;
F_75 ( V_139 , V_186 , ( sizeof( * V_139 ) ) ) ;
if ( V_93 || V_306 ) {
F_54
( L_6 ,
V_292 ,
( V_186 -> V_148 . V_186 . V_136 & V_330 ) >>
V_331 , V_93 , V_306 ) ;
V_43 = F_13 ( V_93 ) ;
goto V_199;
}
if ( V_139 -> V_148 . V_186 . V_43 & V_47 )
V_43 = F_12 ( V_139 -> V_148 . V_186 . V_43 ) ;
V_199:
F_50 ( & V_10 -> V_23 . V_237 ) ;
return V_43 ;
}
static void F_76 ( struct V_9 * V_10 ,
struct V_332 * V_333 ,
struct V_334 * V_186 )
{
V_333 -> V_335 =
( V_186 -> V_336 & V_337 ) >>
V_338 ;
V_333 -> V_339 =
( V_186 -> V_340 & V_341 ) >>
V_342 ;
V_333 -> V_343 = ( ( V_186 -> V_344 &
V_345 ) >>
V_346 ) ;
V_333 -> V_347 = ( V_186 -> V_344 &
V_345 ) >>
V_346 ;
V_333 -> V_348 = ( V_186 -> V_349 &
V_350 ) >>
V_351 ;
V_333 -> V_352 = ( V_186 -> V_353 &
V_354 ) >>
V_355 ;
V_333 -> V_356 = ( V_186 -> V_353 &
V_357 ) >>
V_358 ;
V_333 -> V_359 = ( V_186 -> V_340 &
V_360 ) >>
V_361 ;
V_333 -> V_362 = ( V_186 -> V_340 &
V_363 ) >>
V_364 ;
V_333 -> V_365 = ( V_186 -> V_336 &
V_366 ) >>
V_367 ;
V_333 -> V_368 = V_186 -> V_368 ;
V_333 -> V_369 = ~ 0ull ;
V_333 -> V_370 = 0 ;
V_333 -> V_371 = V_186 -> V_371 ;
V_333 -> V_372 = V_186 -> V_372 ;
V_333 -> V_373 = V_186 -> V_374 &
V_375 ;
V_333 -> V_376 = ( ( V_186 -> V_377 &
V_378 ) >>
V_379 ) *
V_380 ;
V_333 -> V_381 = ( ( V_186 -> V_377 &
V_382 ) >>
V_383 ) *
V_380 ;
V_333 -> V_384 =
V_333 -> V_376 - ( sizeof( struct V_385 ) +
sizeof( struct V_386 ) ) ;
if ( V_10 -> V_112 . V_188 == V_189 ) {
V_333 -> V_387 = 1 ;
V_333 -> V_388 = V_389 ;
V_333 -> V_390 = V_391 ;
}
V_10 -> V_333 . V_392 = V_186 -> V_393 >>
V_394 ;
V_10 -> V_333 . V_395 = V_186 -> V_393 &
V_396 ;
}
static int F_77 ( struct V_9 * V_10 ,
struct V_397 * V_398 )
{
T_1 V_399 ;
V_399 = V_398 -> V_399 & V_400 ;
if ( V_399 != V_400 )
return - V_75 ;
V_10 -> V_401 = V_398 -> V_401 ;
V_10 -> V_402 = V_398 -> V_402 ;
V_10 -> V_333 . V_403 = V_319 - 1 ;
return 0 ;
}
static int F_78 ( struct V_9 * V_10 )
{
int V_43 = - V_158 ;
struct V_18 * V_172 ;
struct V_404 * V_186 ;
V_172 = F_19 ( V_405 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return - V_158 ;
F_18 ( (struct V_131 * ) & V_172 -> V_148 . V_172 [ 0 ] ,
V_405 ,
V_181 , sizeof( * V_172 ) ) ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_404 * ) V_172 ;
memset ( & V_10 -> V_333 . V_406 [ 0 ] , 0 , sizeof( V_10 -> V_333 . V_406 ) ) ;
memcpy ( & V_10 -> V_333 . V_406 [ 0 ] , & V_186 -> V_407 [ 0 ] ,
sizeof( V_186 -> V_407 ) ) ;
F_60 ( V_10 -> V_333 . V_406 , sizeof( V_186 -> V_407 ) ) ;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
static int F_80 ( struct V_9 * V_10 )
{
int V_43 = - V_158 ;
struct V_18 * V_172 ;
struct V_397 * V_186 ;
V_172 = F_19 ( V_408 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return - V_158 ;
F_18 ( (struct V_131 * ) & V_172 -> V_148 . V_172 [ 0 ] ,
V_408 ,
V_181 , sizeof( * V_172 ) ) ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_397 * ) V_172 ;
V_43 = F_77 ( V_10 , V_186 ) ;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
static int F_81 ( struct V_9 * V_10 )
{
int V_43 = - V_158 ;
struct V_334 * V_186 ;
struct V_18 * V_172 ;
V_172 = F_19 ( V_409 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_334 * ) V_172 ;
F_76 ( V_10 , & V_10 -> V_333 , V_186 ) ;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_82 ( struct V_9 * V_10 , struct V_410 * V_411 )
{
int V_43 = - V_158 ;
struct V_412 * V_172 ;
struct V_413 * V_186 ;
V_172 = F_19 ( V_414 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
if ( V_411 -> V_415 )
V_172 -> V_416 |= V_417 ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_413 * ) V_172 ;
V_411 -> V_115 = V_186 -> V_418 & V_419 ;
if ( V_186 -> V_418 & V_420 ) {
V_411 -> V_415 = true ;
V_411 -> V_421 = V_186 -> V_418 >>
V_422 ;
} else {
V_411 -> V_415 = false ;
V_411 -> V_423 = 0 ;
}
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_83 ( struct V_9 * V_10 , struct V_410 * V_411 )
{
int V_43 = - V_158 ;
struct V_424 * V_172 ;
V_172 = F_19 ( V_425 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_115 = V_411 -> V_115 ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
F_79 ( V_172 ) ;
return V_43 ;
}
static int F_84 ( T_1 * V_426 , int V_157 ,
int * V_191 , int * V_427 )
{
int V_164 ;
int V_428 ;
* V_426 = F_85 ( * V_426 ) ;
V_428 = * V_426 * V_157 ;
for ( V_164 = 0 ; V_164 < V_429 ; V_164 ++ ) {
if ( V_428 <= ( V_430 << V_164 ) )
break;
}
if ( V_164 >= V_429 )
return - V_75 ;
V_428 = F_86 ( V_428 ,
( ( V_430 << V_164 ) / V_431 ) ) ;
* V_191 =
V_428 / ( ( V_430 << V_164 ) / V_431 ) ;
* V_427 = ( ( V_430 << V_164 ) / V_431 ) ;
* V_426 = V_428 / V_157 ;
return 0 ;
}
static int F_87 ( struct V_9 * V_10 )
{
int V_164 ;
int V_43 = 0 ;
int V_432 ;
struct V_433 * V_172 ;
struct V_434 * V_186 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
T_3 V_195 ;
struct V_436 * V_437 ;
V_172 = F_19 ( V_438 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_432 = V_439 ;
V_10 -> V_440 . V_154 = sizeof( struct V_441 ) * V_432 ;
V_172 -> V_442 = ( V_443 <<
V_444 ) &
V_445 ;
for ( V_164 = 0 ; V_164 < V_429 ; V_164 ++ ) {
if ( V_446 == ( V_389 << V_164 ) )
break;
}
V_172 -> V_442 |= ( V_164 << V_447 ) &
V_448 ;
V_172 -> V_442 |= ( sizeof( struct V_441 ) <<
V_449 ) &
V_450 ;
V_10 -> V_440 . V_451 . V_5 = F_24 ( & V_153 -> V_10 , V_446 ,
& V_10 -> V_440 . V_451 . V_195 ,
V_140 ) ;
if ( V_10 -> V_440 . V_451 . V_5 == NULL )
goto V_452;
V_10 -> V_440 . V_5 = F_24 ( & V_153 -> V_10 , V_10 -> V_440 . V_154 ,
& V_195 , V_140 ) ;
if ( V_10 -> V_440 . V_5 == NULL )
goto V_453;
V_10 -> V_440 . V_195 = V_195 ;
V_10 -> V_440 . V_454 = V_432 ;
memset ( V_10 -> V_440 . V_5 , 0 , V_10 -> V_440 . V_154 ) ;
V_437 = (struct V_436 * ) V_10 -> V_440 . V_451 . V_5 ;
for ( V_164 = 0 ; V_164 < V_10 -> V_440 . V_154 / V_389 ; V_164 ++ ) {
V_437 [ V_164 ] . V_455 = ( T_1 ) ( V_195 & 0xffffffff ) ;
V_437 [ V_164 ] . V_456 = ( T_1 ) F_26 ( V_195 ) ;
V_195 += V_446 ;
}
V_172 -> V_457 [ 0 ] . V_165 = ( T_1 ) ( V_10 -> V_440 . V_451 . V_195 & 0xFFFFFFFF ) ;
V_172 -> V_457 [ 0 ] . V_166 = ( T_1 ) F_26 ( V_10 -> V_440 . V_451 . V_195 ) ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_434 * ) V_172 ;
V_10 -> V_440 . V_458 = V_186 -> V_458 & 0xFFFF ;
F_79 ( V_172 ) ;
return 0 ;
V_199:
F_22 ( & V_153 -> V_10 , V_10 -> V_440 . V_154 , V_10 -> V_440 . V_5 ,
V_10 -> V_440 . V_195 ) ;
V_10 -> V_440 . V_5 = NULL ;
V_453:
F_22 ( & V_153 -> V_10 , V_446 , V_10 -> V_440 . V_451 . V_5 ,
V_10 -> V_440 . V_451 . V_195 ) ;
V_10 -> V_440 . V_451 . V_5 = NULL ;
V_10 -> V_440 . V_154 = 0 ;
V_452:
F_79 ( V_172 ) ;
return V_43 ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_459 * V_172 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
if ( V_10 -> V_440 . V_5 == NULL )
return;
V_172 = F_19 ( V_460 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return;
V_172 -> V_458 = V_10 -> V_440 . V_458 ;
F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
F_22 ( & V_153 -> V_10 , V_10 -> V_440 . V_154 , V_10 -> V_440 . V_5 ,
V_10 -> V_440 . V_195 ) ;
F_22 ( & V_153 -> V_10 , V_446 , V_10 -> V_440 . V_451 . V_5 ,
V_10 -> V_440 . V_451 . V_195 ) ;
F_79 ( V_172 ) ;
}
static T_2 F_89 ( struct V_9 * V_10 )
{
int V_164 , V_461 = 0 , V_462 = 0 ;
T_2 V_119 ;
F_49 ( & V_10 -> V_463 ) ;
V_462 = V_10 -> V_205 [ 0 ] . V_462 ;
V_119 = V_10 -> V_205 [ 0 ] . V_4 . V_115 ;
for ( V_164 = 0 ; V_164 < V_10 -> V_204 ; V_164 ++ ) {
if ( V_10 -> V_205 [ V_164 ] . V_462 < V_462 ) {
V_462 = V_10 -> V_205 [ V_164 ] . V_462 ;
V_119 = V_10 -> V_205 [ V_164 ] . V_4 . V_115 ;
V_461 = V_164 ;
}
}
V_10 -> V_205 [ V_461 ] . V_462 += 1 ;
F_50 ( & V_10 -> V_463 ) ;
return V_119 ;
}
static void F_90 ( struct V_9 * V_10 , T_2 V_119 )
{
int V_164 ;
F_49 ( & V_10 -> V_463 ) ;
for ( V_164 = 0 ; V_164 < V_10 -> V_204 ; V_164 ++ ) {
if ( V_10 -> V_205 [ V_164 ] . V_4 . V_115 != V_119 )
continue;
V_10 -> V_205 [ V_164 ] . V_462 -= 1 ;
break;
}
F_50 ( & V_10 -> V_463 ) ;
}
int F_91 ( struct V_9 * V_10 , struct V_246 * V_14 ,
int V_464 , int V_465 )
{
int V_43 = - V_158 ; int V_466 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
struct V_467 * V_172 ;
struct V_468 * V_186 ;
T_1 V_469 , V_470 , V_427 , V_471 ;
if ( V_465 )
return - V_75 ;
if ( V_464 > V_10 -> V_333 . V_373 ) {
F_54 ( L_7 ,
V_292 , V_10 -> V_115 , V_10 -> V_333 . V_373 , V_464 ) ;
return - V_75 ;
}
if ( V_465 && ( V_10 -> V_112 . V_188 != V_189 ) )
return - V_75 ;
if ( V_465 ) {
V_14 -> V_466 = 1 ;
V_466 = 1 ;
V_470 = V_472 ;
V_469 = 1 ;
} else {
V_14 -> V_466 = V_10 -> V_333 . V_373 ;
V_466 = V_10 -> V_333 . V_373 ;
V_470 = sizeof( struct V_473 ) ;
V_469 = V_474 ;
}
V_14 -> V_156 = F_86 ( V_466 * V_470 , V_389 ) ;
V_172 = F_19 ( V_208 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return - V_158 ;
F_18 ( & V_172 -> V_172 . V_180 , V_208 ,
V_181 , sizeof( * V_172 ) ) ;
V_14 -> V_5 = F_24 ( & V_153 -> V_10 , V_14 -> V_156 , & V_14 -> V_195 , V_140 ) ;
if ( ! V_14 -> V_5 ) {
V_43 = - V_158 ;
goto V_452;
}
memset ( V_14 -> V_5 , 0 , V_14 -> V_156 ) ;
V_427 = V_14 -> V_156 / V_469 ;
V_172 -> V_172 . V_209 = ( V_427 / V_389 ) <<
V_475 ;
V_172 -> V_172 . V_209 |= V_469 ;
V_172 -> V_172 . V_210 = V_211 ;
if ( V_10 -> V_204 < 0 )
goto V_476;
V_14 -> V_212 = F_89 ( V_10 ) ;
V_172 -> V_172 . V_180 . V_190 = V_477 ;
V_471 = V_14 -> V_156 / V_470 ;
if ( V_471 > 1024 )
V_172 -> V_172 . V_210 |= ( 0x3 << V_478 ) ;
else {
V_3 V_479 = 0 ;
switch ( V_471 ) {
case 256 :
V_479 = 0 ;
break;
case 512 :
V_479 = 1 ;
break;
case 1024 :
V_479 = 2 ;
break;
default:
goto V_199;
}
V_172 -> V_172 . V_210 |= ( V_479 << V_478 ) ;
}
V_172 -> V_172 . V_212 = V_14 -> V_212 ;
if ( V_10 -> V_112 . V_188 == V_189 ) {
if ( V_465 )
V_172 -> V_172 . V_209 |= V_480 <<
V_481 ;
V_14 -> V_482 = false ;
V_172 -> V_172 . V_471 = ( V_14 -> V_156 / V_470 ) ;
} else {
V_172 -> V_172 . V_471 = ( V_14 -> V_156 / V_470 ) - 1 ;
V_172 -> V_172 . V_210 |= V_483 ;
V_14 -> V_482 = true ;
}
F_25 ( & V_172 -> V_172 . V_195 [ 0 ] , V_469 , V_14 -> V_195 , V_427 ) ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_468 * ) V_172 ;
V_14 -> V_115 = ( T_2 ) ( V_186 -> V_186 . V_101 & V_214 ) ;
F_79 ( V_172 ) ;
return 0 ;
V_199:
F_90 ( V_10 , V_14 -> V_212 ) ;
V_476:
F_22 ( & V_153 -> V_10 , V_14 -> V_156 , V_14 -> V_5 , V_14 -> V_195 ) ;
V_452:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_92 ( struct V_9 * V_10 , struct V_246 * V_14 )
{
int V_43 = - V_158 ;
struct V_484 * V_172 ;
V_172 = F_19 ( V_177 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
F_18 ( & V_172 -> V_180 , V_177 ,
V_181 , sizeof( * V_172 ) ) ;
V_172 -> V_485 |=
( V_14 -> V_115 << V_486 ) &
V_487 ;
F_90 ( V_10 , V_14 -> V_212 ) ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
F_22 ( & V_10 -> V_112 . V_153 -> V_10 , V_14 -> V_156 , V_14 -> V_5 , V_14 -> V_195 ) ;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_93 ( struct V_9 * V_10 , struct V_488 * V_489 ,
T_1 V_490 , int V_491 )
{
int V_43 = - V_158 ;
struct V_492 * V_172 ;
struct V_493 * V_186 ;
V_172 = F_19 ( V_494 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_490 = V_490 ;
V_172 -> V_495 |= V_491 ;
V_172 -> V_495 |= ( V_489 -> V_496 << V_497 ) ;
V_172 -> V_495 |=
( V_489 -> V_498 << V_499 ) ;
V_172 -> V_495 |=
( V_489 -> V_500 << V_501 ) ;
V_172 -> V_495 |=
( V_489 -> V_502 << V_503 ) ;
V_172 -> V_495 |=
( V_489 -> V_504 << V_505 ) ;
V_172 -> V_495 |=
( V_489 -> V_506 << V_507 ) ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_493 * ) V_172 ;
V_489 -> V_508 = V_186 -> V_509 ;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_94 ( struct V_9 * V_10 , int V_496 , T_1 V_508 )
{
int V_43 = - V_158 ;
struct V_510 * V_172 ;
V_172 = F_19 ( V_511 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return - V_158 ;
V_172 -> V_508 = V_508 ;
V_172 -> V_512 = V_496 ? 1 : 0 ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
static int F_95 ( struct V_9 * V_10 , struct V_488 * V_489 ,
T_1 V_490 , T_1 V_513 , T_1 V_514 , T_1 V_515 )
{
int V_43 = - V_158 ;
int V_164 ;
struct V_516 * V_172 ;
struct V_517 * V_186 ;
V_172 = F_19 ( V_518 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return - V_158 ;
V_172 -> V_519 =
V_490 | ( V_489 -> V_506 << V_520 ) ;
V_172 -> V_521 |= ( V_489 -> V_498 <<
V_522 ) ;
V_172 -> V_521 |= ( V_489 -> V_500 <<
V_523 ) ;
V_172 -> V_521 |= ( V_489 -> V_502 <<
V_524 ) ;
V_172 -> V_521 |= ( V_489 -> V_504 <<
V_525 ) ;
V_172 -> V_521 |= ( V_489 -> V_526 <<
V_527 ) ;
V_172 -> V_521 |= ( V_515 << V_528 ) ;
V_172 -> V_521 |= ( V_489 -> V_514 / V_529 ) ;
V_172 -> V_521 |= ( V_489 -> V_530 / V_529 ) <<
V_531 ;
V_172 -> V_532 = V_489 -> V_156 ;
V_172 -> V_533 = F_26 ( V_489 -> V_156 ) ;
V_172 -> V_534 = ( T_1 ) ( V_489 -> V_535 & 0xffffffff ) ;
V_172 -> V_536 = ( T_1 ) F_26 ( V_489 -> V_535 ) ;
V_172 -> V_537 = ( T_1 ) V_489 -> V_5 ;
V_172 -> V_538 = ( T_1 ) F_26 ( V_489 -> V_5 ) ;
for ( V_164 = 0 ; V_164 < V_513 ; V_164 ++ ) {
V_172 -> V_451 [ V_164 ] . V_165 = ( T_1 ) ( V_489 -> V_539 [ V_164 ] . V_195 & 0xffffffff ) ;
V_172 -> V_451 [ V_164 ] . V_166 = F_26 ( V_489 -> V_539 [ V_164 ] . V_195 ) ;
}
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_517 * ) V_172 ;
V_489 -> V_508 = V_186 -> V_509 ;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
static int F_96 ( struct V_9 * V_10 ,
struct V_488 * V_489 , T_1 V_513 ,
T_1 V_540 , T_1 V_515 )
{
int V_43 = - V_158 ;
int V_164 ;
struct V_541 * V_172 ;
V_172 = F_19 ( V_542 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return - V_158 ;
V_172 -> V_509 = V_489 -> V_508 ;
V_172 -> V_543 = ( V_513 << V_544 ) |
( V_540 & V_545 ) ;
V_172 -> V_515 = V_515 << V_546 ;
for ( V_164 = 0 ; V_164 < V_513 ; V_164 ++ ) {
V_172 -> V_451 [ V_164 ] . V_165 =
( T_1 ) ( V_489 -> V_539 [ V_164 + V_540 ] . V_195 & 0xffffffff ) ;
V_172 -> V_451 [ V_164 ] . V_166 =
F_26 ( V_489 -> V_539 [ V_164 + V_540 ] . V_195 ) ;
}
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_97 ( struct V_9 * V_10 ,
struct V_488 * V_489 , T_1 V_490 , int V_547 )
{
int V_43 ;
T_1 V_515 = 0 ;
T_1 V_548 , V_540 ;
T_1 V_549 = V_489 -> V_506 ;
V_540 = 0 ;
V_548 = F_98 ( V_549 , V_550 ) ;
if ( V_548 == V_549 )
V_515 = 1 ;
V_43 = F_95 ( V_10 , V_489 , V_490 ,
V_548 , V_489 -> V_514 , V_515 ) ;
if ( V_43 ) {
F_54 ( L_8 , V_292 , V_43 ) ;
return V_43 ;
}
if ( V_515 )
return 0 ;
while ( ! V_515 ) {
V_540 += V_548 ;
V_549 -= V_548 ;
V_548 = F_98 ( V_549 , V_550 ) ;
if ( V_548 == V_549 )
V_515 = 1 ;
V_43 = F_96 ( V_10 , V_489 , V_548 ,
V_540 , V_515 ) ;
if ( V_43 )
break;
}
if ( V_43 )
F_54 ( L_9 , V_292 , V_43 ) ;
return V_43 ;
}
bool F_99 ( struct V_246 * V_14 , struct V_241 * V_242 )
{
struct V_241 * V_551 ;
bool V_552 = false ;
F_63 (tmp, &cq->sq_head, sq_entry) {
if ( V_242 == V_551 ) {
V_552 = true ;
break;
}
}
return V_552 ;
}
bool F_100 ( struct V_246 * V_14 , struct V_241 * V_242 )
{
struct V_241 * V_551 ;
bool V_552 = false ;
F_63 (tmp, &cq->rq_head, rq_entry) {
if ( V_242 == V_551 ) {
V_552 = true ;
break;
}
}
return V_552 ;
}
void F_101 ( struct V_241 * V_242 )
{
bool V_552 ;
unsigned long V_311 ;
F_62 ( & V_242 -> V_10 -> V_313 , V_311 ) ;
V_552 = F_99 ( V_242 -> V_314 , V_242 ) ;
if ( ! V_552 )
F_102 ( & V_242 -> V_553 , & V_242 -> V_314 -> V_554 ) ;
if ( ! V_242 -> V_285 ) {
V_552 = F_100 ( V_242 -> V_315 , V_242 ) ;
if ( ! V_552 )
F_102 ( & V_242 -> V_555 , & V_242 -> V_315 -> V_556 ) ;
}
F_64 ( & V_242 -> V_10 -> V_313 , V_311 ) ;
}
int F_52 ( struct V_241 * V_242 , enum V_25 V_557 ,
enum V_25 * V_558 )
{
unsigned long V_311 ;
int V_43 = 0 ;
enum V_26 V_559 ;
V_559 = F_11 ( V_557 ) ;
F_62 ( & V_242 -> V_560 , V_311 ) ;
if ( V_558 )
* V_558 = F_10 ( V_242 -> V_561 ) ;
if ( V_559 == V_242 -> V_561 ) {
F_64 ( & V_242 -> V_560 , V_311 ) ;
return 1 ;
}
switch ( V_242 -> V_561 ) {
case V_28 :
switch ( V_559 ) {
case V_28 :
case V_30 :
break;
default:
V_43 = - V_75 ;
break;
} ;
break;
case V_30 :
switch ( V_559 ) {
case V_30 :
case V_32 :
break;
case V_41 :
F_101 ( V_242 ) ;
break;
default:
V_43 = - V_75 ;
break;
} ;
break;
case V_32 :
switch ( V_559 ) {
case V_34 :
break;
case V_41 :
F_101 ( V_242 ) ;
break;
default:
V_43 = - V_75 ;
break;
} ;
break;
case V_34 :
switch ( V_559 ) {
case V_36 :
case V_39 :
break;
case V_41 :
F_101 ( V_242 ) ;
break;
default:
V_43 = - V_75 ;
break;
} ;
break;
case V_36 :
switch ( V_559 ) {
case V_34 :
case V_39 :
case V_41 :
break;
default:
V_43 = - V_75 ;
break;
} ;
break;
case V_39 :
switch ( V_559 ) {
case V_34 :
case V_41 :
break;
default:
V_43 = - V_75 ;
break;
} ;
break;
case V_41 :
switch ( V_559 ) {
case V_28 :
break;
default:
V_43 = - V_75 ;
break;
} ;
break;
default:
V_43 = - V_75 ;
break;
} ;
if ( ! V_43 )
V_242 -> V_561 = V_559 ;
F_64 ( & V_242 -> V_560 , V_311 ) ;
return V_43 ;
}
static T_1 F_103 ( struct V_241 * V_242 )
{
T_1 V_311 = 0 ;
if ( V_242 -> V_562 & V_563 )
V_311 |= V_564 ;
if ( V_242 -> V_562 & V_565 )
V_311 |= V_566 ;
if ( V_242 -> V_562 & V_567 )
V_311 |= V_568 ;
if ( V_242 -> V_562 & V_569 )
V_311 |= V_570 ;
if ( V_242 -> V_562 & V_571 )
V_311 |= V_572 ;
return V_311 ;
}
static int F_104 ( struct V_573 * V_172 ,
struct V_574 * V_575 ,
struct V_241 * V_242 )
{
int V_43 ;
T_1 V_156 , V_469 , V_163 ;
T_3 V_195 ;
struct V_9 * V_10 = V_242 -> V_10 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
T_1 V_576 ;
T_1 V_577 = V_575 -> V_578 . V_343 ;
V_576 = V_575 -> V_578 . V_579 ;
if ( V_10 -> V_112 . V_188 != V_189 )
V_576 += 1 ;
V_43 = F_84 ( & V_576 ,
V_10 -> V_333 . V_376 , & V_469 , & V_163 ) ;
if ( V_43 ) {
F_54 ( L_10 , V_292 ,
V_576 ) ;
return - V_75 ;
}
V_242 -> V_19 . V_580 = V_576 ;
V_156 = ( V_469 * V_163 ) ;
V_242 -> V_19 . V_5 = F_24 ( & V_153 -> V_10 , V_156 , & V_195 , V_140 ) ;
if ( ! V_242 -> V_19 . V_5 )
return - V_75 ;
memset ( V_242 -> V_19 . V_5 , 0 , V_156 ) ;
V_242 -> V_19 . V_156 = V_156 ;
V_242 -> V_19 . V_195 = V_195 ;
V_242 -> V_19 . V_157 = V_10 -> V_333 . V_376 ;
F_25 ( & V_172 -> V_581 [ 0 ] , V_469 , V_195 , V_163 ) ;
V_172 -> V_582 |= ( F_105 ( V_163 / V_389 )
<< V_583 ) ;
V_172 -> V_584 |= ( V_469 <<
V_585 ) &
V_586 ;
V_172 -> V_587 |= ( V_577 <<
V_588 ) &
V_589 ;
V_172 -> V_587 |= ( V_577 <<
V_590 ) &
V_591 ;
V_172 -> V_592 |= ( F_105 ( V_242 -> V_19 . V_580 ) <<
V_593 ) &
V_594 ;
V_172 -> V_595 |= ( V_10 -> V_333 . V_376 <<
V_596 ) &
V_597 ;
return 0 ;
}
static int F_106 ( struct V_573 * V_172 ,
struct V_574 * V_575 ,
struct V_241 * V_242 )
{
int V_43 ;
T_1 V_156 , V_469 , V_163 ;
T_3 V_195 = 0 ;
struct V_9 * V_10 = V_242 -> V_10 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
T_1 V_598 = V_575 -> V_578 . V_599 + 1 ;
V_43 = F_84 ( & V_598 , V_10 -> V_333 . V_381 ,
& V_469 , & V_163 ) ;
if ( V_43 ) {
F_54 ( L_11 , V_292 ,
V_575 -> V_578 . V_599 + 1 ) ;
return V_43 ;
}
V_242 -> V_600 . V_580 = V_598 ;
V_156 = ( V_469 * V_163 ) ;
V_242 -> V_600 . V_5 = F_24 ( & V_153 -> V_10 , V_156 , & V_195 , V_140 ) ;
if ( ! V_242 -> V_600 . V_5 )
return V_43 ;
memset ( V_242 -> V_600 . V_5 , 0 , V_156 ) ;
V_242 -> V_600 . V_195 = V_195 ;
V_242 -> V_600 . V_156 = V_156 ;
V_242 -> V_600 . V_157 = V_10 -> V_333 . V_381 ;
F_25 ( & V_172 -> V_601 [ 0 ] , V_469 , V_195 , V_163 ) ;
V_172 -> V_582 |= ( F_105 ( V_163 / V_389 ) <<
V_602 ) ;
V_172 -> V_584 |=
( V_469 << V_603 ) &
V_604 ;
V_172 -> V_605 |= ( V_575 -> V_578 . V_347 <<
V_606 ) &
V_607 ;
V_172 -> V_592 |= ( F_105 ( V_242 -> V_600 . V_580 ) <<
V_608 ) &
V_609 ;
V_172 -> V_595 |= ( V_10 -> V_333 . V_381 <<
V_610 ) &
V_611 ;
return 0 ;
}
static void F_107 ( struct V_573 * V_172 ,
struct V_410 * V_411 ,
struct V_241 * V_242 ,
V_3 V_612 , T_2 V_613 )
{
V_411 -> V_423 -- ;
V_242 -> V_415 = true ;
V_172 -> V_605 |= V_614 ;
if ( ! V_612 )
return;
V_172 -> V_605 |= V_614 ;
V_172 -> V_615 = V_613 ;
V_172 -> V_615 |= V_616 <<
V_617 ;
}
static int F_108 ( struct V_573 * V_172 ,
struct V_241 * V_242 )
{
struct V_9 * V_10 = V_242 -> V_10 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
T_3 V_195 = 0 ;
int V_388 = V_10 -> V_333 . V_388 ;
int V_618 = V_10 -> V_333 . V_390 * V_388 ;
if ( V_10 -> V_333 . V_387 == 0 )
return 0 ;
V_242 -> V_619 = F_24 ( & V_153 -> V_10 , V_618 ,
& V_195 , V_140 ) ;
if ( ! V_242 -> V_619 )
return - V_158 ;
memset ( V_242 -> V_619 , 0 , V_618 ) ;
F_25 ( & V_172 -> V_620 [ 0 ] , V_10 -> V_333 . V_390 ,
V_195 , V_388 ) ;
return 0 ;
}
static void F_109 ( struct V_621 * V_186 ,
struct V_241 * V_242 ,
struct V_574 * V_575 ,
T_2 * V_622 , T_2 * V_623 )
{
T_1 V_576 , V_598 ;
V_242 -> V_115 = V_186 -> V_624 & V_625 ;
V_242 -> V_600 . V_626 = V_186 -> V_627 & V_628 ;
V_242 -> V_19 . V_626 = V_186 -> V_627 >> V_629 ;
V_242 -> V_630 = V_186 -> V_631 & V_632 ;
V_242 -> V_633 = ( V_186 -> V_631 >> V_634 ) ;
V_242 -> V_415 = false ;
if ( V_186 -> V_635 & V_636 ) {
V_242 -> V_415 = true ;
* V_623 = ( V_186 -> V_635 &
V_637 ) >>
V_638 ;
* V_622 = ( V_186 -> V_635 &
V_639 ) >>
V_640 ;
}
V_576 =
V_186 -> V_592 >> V_641 ;
V_576 = 1 << V_576 ;
V_598 = 1 << ( ( T_2 ) V_186 -> V_592 ) ;
V_242 -> V_19 . V_580 = V_576 ;
V_242 -> V_19 . V_642 = V_576 - 1 ;
if ( ! V_575 -> V_285 ) {
V_242 -> V_600 . V_580 = V_598 ;
V_242 -> V_600 . V_642 = V_598 - 1 ;
}
}
int F_110 ( struct V_241 * V_242 , struct V_574 * V_575 ,
V_3 V_612 , T_2 V_613 , T_2 * V_622 ,
T_2 * V_623 )
{
int V_43 = - V_158 ;
T_1 V_311 = 0 ;
struct V_9 * V_10 = V_242 -> V_10 ;
struct V_410 * V_411 = V_242 -> V_411 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
struct V_246 * V_14 ;
struct V_573 * V_172 ;
struct V_621 * V_186 ;
int V_643 ;
switch ( V_575 -> V_644 ) {
case V_645 :
V_643 = V_646 ;
break;
case V_647 :
V_643 = V_648 ;
break;
case V_649 :
V_643 = V_650 ;
break;
default:
return - V_75 ;
} ;
V_172 = F_19 ( V_651 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_582 |= ( V_643 << V_652 ) &
V_653 ;
V_43 = F_104 ( V_172 , V_575 , V_242 ) ;
if ( V_43 )
goto V_654;
if ( V_575 -> V_285 ) {
struct V_655 * V_285 = F_111 ( V_575 -> V_285 ) ;
V_172 -> V_605 |= V_656 ;
V_172 -> V_601 [ 0 ] . V_165 = V_285 -> V_115 ;
V_242 -> V_285 = V_285 ;
} else {
V_43 = F_106 ( V_172 , V_575 , V_242 ) ;
if ( V_43 )
goto V_657;
}
V_43 = F_108 ( V_172 , V_242 ) ;
if ( V_43 )
goto V_199;
V_172 -> V_582 |= ( V_411 -> V_115 << V_658 ) &
V_659 ;
V_311 = F_103 ( V_242 ) ;
V_172 -> V_605 |= V_311 ;
V_172 -> V_631 |= ( V_10 -> V_333 . V_352 <<
V_660 ) &
V_661 ;
V_172 -> V_631 |= ( V_10 -> V_333 . V_356 <<
V_662 ) &
V_663 ;
V_14 = F_112 ( V_575 -> V_664 ) ;
V_172 -> V_665 |= ( V_14 -> V_115 << V_666 ) &
V_667 ;
V_242 -> V_314 = V_14 ;
V_14 = F_112 ( V_575 -> V_668 ) ;
V_172 -> V_665 |= ( V_14 -> V_115 << V_669 ) &
V_670 ;
V_242 -> V_315 = V_14 ;
if ( V_411 -> V_415 && V_575 -> V_578 . V_384 && V_411 -> V_423 &&
( V_575 -> V_578 . V_384 <= V_10 -> V_333 . V_384 ) )
F_107 ( V_172 , V_411 , V_242 , V_612 ,
V_613 ) ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_621 * ) V_172 ;
F_109 ( V_186 , V_242 , V_575 , V_622 , V_623 ) ;
V_242 -> V_561 = V_28 ;
F_79 ( V_172 ) ;
return 0 ;
V_199:
if ( V_242 -> V_600 . V_5 )
F_22 ( & V_153 -> V_10 , V_242 -> V_600 . V_156 , V_242 -> V_600 . V_5 , V_242 -> V_600 . V_195 ) ;
V_657:
F_54 ( L_12 , V_292 , V_10 -> V_115 ) ;
F_22 ( & V_153 -> V_10 , V_242 -> V_19 . V_156 , V_242 -> V_19 . V_5 , V_242 -> V_19 . V_195 ) ;
V_654:
F_54 ( L_13 , V_292 , V_10 -> V_115 ) ;
F_79 ( V_172 ) ;
return V_43 ;
}
int F_113 ( struct V_9 * V_10 , struct V_241 * V_242 ,
struct V_671 * V_672 )
{
int V_43 = - V_158 ;
struct V_673 * V_172 ;
struct V_674 * V_186 ;
V_172 = F_19 ( V_675 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_624 = V_242 -> V_115 ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_674 * ) V_172 ;
memcpy ( V_672 , & V_186 -> V_676 , sizeof( struct V_671 ) ) ;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_114 ( struct V_9 * V_10 , union V_677 * V_678 ,
V_3 * V_679 )
{
struct V_680 V_681 ;
memcpy ( & V_681 , V_678 , sizeof V_681 ) ;
if ( F_115 ( & V_681 ) )
F_116 ( & V_681 , V_679 ) ;
else if ( F_117 ( & V_681 ) )
F_118 ( & V_681 , V_679 ) ;
else {
F_54 ( L_14 , V_292 ) ;
return - V_75 ;
}
return 0 ;
}
static void F_119 ( struct V_241 * V_242 ,
struct V_682 * V_172 ,
struct V_683 * V_575 )
{
struct V_684 * V_685 = & V_575 -> V_685 ;
union V_677 V_686 ;
T_1 V_687 ;
V_3 V_679 [ 6 ] ;
if ( ( V_685 -> V_688 & V_689 ) == 0 )
return;
V_172 -> V_676 . V_690 |=
( V_685 -> V_691 . V_692 << V_693 ) ;
V_172 -> V_676 . V_694 |=
( V_685 -> V_691 . V_695 & V_696 ) ;
V_172 -> V_676 . V_697 |=
( V_685 -> V_691 . V_698 << V_699 ) ;
V_172 -> V_311 |= V_700 ;
memcpy ( & V_172 -> V_676 . V_678 [ 0 ] , & V_685 -> V_691 . V_678 . V_701 [ 0 ] ,
sizeof( V_172 -> V_676 . V_678 ) ) ;
F_120 ( & V_242 -> V_10 -> V_265 , 1 ,
V_685 -> V_691 . V_702 , & V_686 ) ;
V_242 -> V_703 = V_685 -> V_691 . V_702 ;
memcpy ( & V_172 -> V_676 . V_686 [ 0 ] , & V_686 . V_701 [ 0 ] , sizeof( V_172 -> V_676 . V_686 ) ) ;
F_114 ( V_242 -> V_10 , & V_685 -> V_691 . V_678 , & V_679 [ 0 ] ) ;
V_172 -> V_676 . V_704 = V_679 [ 0 ] | ( V_679 [ 1 ] << 8 ) |
( V_679 [ 2 ] << 16 ) | ( V_679 [ 3 ] << 24 ) ;
F_121 ( & V_172 -> V_676 . V_678 [ 0 ] , sizeof( V_172 -> V_676 . V_678 ) ) ;
F_121 ( & V_172 -> V_676 . V_686 [ 0 ] , sizeof( V_172 -> V_676 . V_686 ) ) ;
V_172 -> V_676 . V_705 = V_679 [ 4 ] | ( V_679 [ 5 ] << 8 ) ;
V_687 = F_122 ( & V_686 ) ;
if ( V_687 && ( V_687 < 0x1000 ) ) {
V_172 -> V_676 . V_705 |=
V_687 << V_706 ;
V_172 -> V_311 |= V_707 ;
}
}
static int F_123 ( struct V_241 * V_242 ,
struct V_682 * V_172 ,
struct V_683 * V_575 , int V_708 ,
enum V_25 V_709 )
{
int V_43 = 0 ;
struct V_710 * V_182 = V_242 -> V_10 -> V_112 . V_182 ;
int V_711 = F_124 ( V_182 -> V_712 ) ;
if ( V_708 & V_713 ) {
V_172 -> V_676 . V_714 |= ( V_575 -> V_715 &
V_716 ) ;
V_172 -> V_311 |= V_717 ;
}
if ( V_708 & V_718 ) {
V_242 -> V_719 = V_575 -> V_719 ;
V_172 -> V_676 . V_719 = V_575 -> V_719 ;
V_172 -> V_311 |= V_720 ;
}
if ( V_708 & V_721 )
F_119 ( V_242 , V_172 , V_575 ) ;
else if ( V_242 -> V_644 == V_645 || V_242 -> V_644 == V_649 ) {
V_172 -> V_676 . V_704 = V_242 -> V_10 -> V_112 . V_679 [ 0 ] |
( V_242 -> V_10 -> V_112 . V_679 [ 1 ] << 8 ) |
( V_242 -> V_10 -> V_112 . V_679 [ 2 ] << 16 ) |
( V_242 -> V_10 -> V_112 . V_679 [ 3 ] << 24 ) ;
V_172 -> V_676 . V_705 = V_242 -> V_10 -> V_112 . V_679 [ 4 ] |
( V_242 -> V_10 -> V_112 . V_679 [ 5 ] << 8 ) ;
}
if ( ( V_708 & V_722 ) &&
V_575 -> V_723 ) {
V_172 -> V_676 . V_605 |=
V_724 ;
V_172 -> V_311 |= V_725 ;
}
if ( V_708 & V_726 ) {
V_172 -> V_676 . V_727 |= ( V_575 -> V_728 &
V_729 ) ;
V_172 -> V_311 |= V_725 ;
}
if ( V_708 & V_730 ) {
if ( F_125 ( V_711 ) <
F_125 ( V_575 -> V_731 ) ) {
V_43 = - V_75 ;
goto V_732;
}
V_172 -> V_676 . V_714 |=
( F_125 ( V_575 -> V_731 ) <<
V_733 ) &
V_734 ;
V_172 -> V_311 |= V_735 ;
}
if ( V_708 & V_736 ) {
V_172 -> V_676 . V_727 |= V_575 -> V_138 <<
V_737 ;
V_172 -> V_311 |= V_738 ;
}
if ( V_708 & V_739 ) {
V_172 -> V_676 . V_694 |= ( V_575 -> V_740 <<
V_741 ) &
V_742 ;
V_172 -> V_311 |= V_743 ;
}
if ( V_708 & V_744 ) {
V_172 -> V_676 . V_694 |= ( V_575 -> V_745 <<
V_746 ) &
V_747 ;
V_172 -> V_311 |= V_748 ;
}
if ( V_708 & V_749 ) {
V_172 -> V_676 . V_727 |= ( V_575 -> V_750 <<
V_751 )
& V_752 ;
V_172 -> V_311 |= V_753 ;
}
if ( V_708 & V_754 ) {
V_172 -> V_676 . V_690 |= ( V_575 -> V_755 & 0x00ffffff ) ;
V_172 -> V_311 |= V_756 ;
}
if ( V_708 & V_757 ) {
V_172 -> V_676 . V_697 |= ( V_575 -> V_758 & 0x00ffffff ) ;
V_172 -> V_311 |= V_759 ;
}
if ( V_708 & V_760 ) {
if ( V_575 -> V_761 > V_242 -> V_10 -> V_333 . V_352 ) {
V_43 = - V_75 ;
goto V_732;
}
V_242 -> V_633 = V_575 -> V_761 ;
V_172 -> V_311 |= V_762 ;
}
if ( V_708 & V_763 ) {
if ( V_575 -> V_764 > V_242 -> V_10 -> V_333 . V_356 ) {
V_43 = - V_75 ;
goto V_732;
}
V_242 -> V_630 = V_575 -> V_764 ;
V_172 -> V_311 |= V_765 ;
}
V_172 -> V_676 . V_631 = ( V_242 -> V_633 <<
V_766 ) |
( V_242 -> V_630 & V_767 ) ;
V_732:
return V_43 ;
}
int F_126 ( struct V_9 * V_10 , struct V_241 * V_242 ,
struct V_683 * V_575 , int V_708 ,
enum V_25 V_709 )
{
int V_43 = - V_158 ;
struct V_682 * V_172 ;
V_172 = F_19 ( V_768 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_676 . V_115 = V_242 -> V_115 ;
V_172 -> V_311 = 0 ;
if ( V_708 & V_769 ) {
V_172 -> V_676 . V_605 |=
( F_11 ( V_575 -> V_770 ) <<
V_771 ) &
V_772 ;
V_172 -> V_311 |= V_773 ;
} else
V_172 -> V_676 . V_605 |=
( V_242 -> V_561 << V_771 ) &
V_772 ;
V_43 = F_123 ( V_242 , V_172 , V_575 , V_708 , V_709 ) ;
if ( V_43 )
goto V_199;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_199:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_127 ( struct V_9 * V_10 , struct V_241 * V_242 )
{
int V_43 = - V_158 ;
struct V_774 * V_172 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
V_172 = F_19 ( V_775 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_624 = V_242 -> V_115 ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_199:
F_79 ( V_172 ) ;
if ( V_242 -> V_19 . V_5 )
F_22 ( & V_153 -> V_10 , V_242 -> V_19 . V_156 , V_242 -> V_19 . V_5 , V_242 -> V_19 . V_195 ) ;
if ( ! V_242 -> V_285 && V_242 -> V_600 . V_5 )
F_22 ( & V_153 -> V_10 , V_242 -> V_600 . V_156 , V_242 -> V_600 . V_5 , V_242 -> V_600 . V_195 ) ;
if ( V_242 -> V_415 )
V_242 -> V_411 -> V_423 ++ ;
return V_43 ;
}
int F_128 ( struct V_655 * V_285 ,
struct V_776 * V_777 ,
struct V_410 * V_411 )
{
int V_43 = - V_158 ;
int V_469 , V_163 ;
int V_156 ;
struct V_778 * V_186 ;
struct V_779 * V_172 ;
T_3 V_195 ;
struct V_9 * V_10 = V_285 -> V_10 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
T_1 V_598 ;
V_172 = F_19 ( V_780 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_781 = V_411 -> V_115 & V_782 ;
V_598 = V_777 -> V_333 . V_783 + 1 ;
V_43 = F_84 ( & V_598 ,
V_10 -> V_333 . V_381 ,
& V_469 , & V_163 ) ;
if ( V_43 ) {
F_54 ( L_15 , V_292 ,
V_777 -> V_333 . V_783 ) ;
V_43 = - V_75 ;
goto V_784;
}
V_156 = V_469 * V_163 ;
V_285 -> V_600 . V_5 = F_24 ( & V_153 -> V_10 , V_156 , & V_195 , V_140 ) ;
if ( ! V_285 -> V_600 . V_5 ) {
V_43 = - V_158 ;
goto V_784;
}
F_25 ( & V_172 -> V_601 [ 0 ] , V_469 , V_195 , V_163 ) ;
V_285 -> V_600 . V_157 = V_10 -> V_333 . V_381 ;
V_285 -> V_600 . V_195 = V_195 ;
V_285 -> V_600 . V_156 = V_156 ;
V_285 -> V_600 . V_580 = V_598 ;
V_172 -> V_785 = F_105 ( V_598 ) ;
V_172 -> V_785 |= V_777 -> V_333 . V_786 <<
V_787 ;
V_172 -> V_781 |= ( F_105 ( V_163 / V_389 )
<< V_788 ) ;
V_172 -> V_789 |= ( V_10 -> V_333 . V_381
<< V_790 )
& V_791 ;
V_172 -> V_789 |= V_469 << V_792 ;
V_43 = F_74 ( V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 )
goto V_199;
V_186 = (struct V_778 * ) V_172 ;
V_285 -> V_115 = V_186 -> V_115 ;
V_285 -> V_600 . V_626 = V_186 -> V_115 ;
V_598 = ( ( V_186 -> V_793 &
V_794 ) >>
V_795 ) ;
V_598 = ( 1 << V_598 ) ;
V_285 -> V_600 . V_580 = V_598 ;
V_285 -> V_600 . V_642 = V_598 - 1 ;
V_285 -> V_600 . V_577 = ( V_186 -> V_793 &
V_796 ) >>
V_797 ;
goto V_784;
V_199:
F_22 ( & V_153 -> V_10 , V_285 -> V_600 . V_156 , V_285 -> V_600 . V_5 , V_195 ) ;
V_784:
F_79 ( V_172 ) ;
return V_43 ;
}
int F_129 ( struct V_655 * V_285 , struct V_798 * V_777 )
{
int V_43 = - V_158 ;
struct V_799 * V_172 ;
V_172 = F_19 ( V_780 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_115 = V_285 -> V_115 ;
V_172 -> V_800 |= V_777 -> V_801 <<
V_802 ;
V_43 = F_74 ( V_285 -> V_10 , (struct V_18 * ) V_172 ) ;
F_79 ( V_172 ) ;
return V_43 ;
}
int F_130 ( struct V_655 * V_285 , struct V_798 * V_777 )
{
int V_43 = - V_158 ;
struct V_803 * V_172 ;
V_172 = F_19 ( V_780 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_115 = V_285 -> V_600 . V_626 ;
V_43 = F_74 ( V_285 -> V_10 , (struct V_18 * ) V_172 ) ;
if ( V_43 == 0 ) {
struct V_804 * V_186 =
(struct V_804 * ) V_172 ;
V_777 -> V_786 =
V_186 -> V_805 &
V_806 ;
V_777 -> V_783 =
V_186 -> V_807 >> V_808 ;
V_777 -> V_801 = V_186 -> V_805 >>
V_809 ;
}
F_79 ( V_172 ) ;
return V_43 ;
}
int F_131 ( struct V_9 * V_10 , struct V_655 * V_285 )
{
int V_43 = - V_158 ;
struct V_810 * V_172 ;
struct V_435 * V_153 = V_10 -> V_112 . V_153 ;
V_172 = F_19 ( V_811 , sizeof( * V_172 ) ) ;
if ( ! V_172 )
return V_43 ;
V_172 -> V_115 = V_285 -> V_115 ;
V_43 = F_74 ( V_285 -> V_10 , (struct V_18 * ) V_172 ) ;
if ( V_285 -> V_600 . V_5 )
F_22 ( & V_153 -> V_10 , V_285 -> V_600 . V_156 ,
V_285 -> V_600 . V_5 , V_285 -> V_600 . V_195 ) ;
F_79 ( V_172 ) ;
return V_43 ;
}
int F_132 ( struct V_9 * V_10 , struct V_812 * V_813 )
{
int V_164 ;
int V_43 = - V_75 ;
struct V_441 * V_814 ;
unsigned long V_311 ;
V_814 = V_10 -> V_440 . V_5 ;
F_62 ( & V_10 -> V_440 . V_237 , V_311 ) ;
for ( V_164 = 0 ; V_164 < V_10 -> V_440 . V_454 ; V_164 ++ ) {
if ( V_814 -> V_192 == 0 ) {
V_814 -> V_192 = V_815 ;
V_813 -> V_814 = V_814 ;
V_813 -> V_115 = V_164 ;
V_43 = 0 ;
break;
}
V_814 ++ ;
}
if ( V_164 == V_10 -> V_440 . V_454 )
V_43 = - V_54 ;
F_64 ( & V_10 -> V_440 . V_237 , V_311 ) ;
return V_43 ;
}
int F_133 ( struct V_9 * V_10 , struct V_812 * V_813 )
{
unsigned long V_311 ;
F_62 ( & V_10 -> V_440 . V_237 , V_311 ) ;
V_813 -> V_814 -> V_192 = 0 ;
F_64 ( & V_10 -> V_440 . V_237 , V_311 ) ;
return 0 ;
}
static int F_134 ( struct V_9 * V_10 )
{
int V_43 ;
int V_200 ;
unsigned long V_311 = 0 ;
int V_816 = 0 ;
if ( V_10 -> V_112 . V_201 == V_202 )
V_311 = V_817 ;
else {
V_816 = V_10 -> V_112 . V_168 . V_818 -
V_10 -> V_112 . V_168 . V_169 ;
if ( V_816 < 2 )
return - V_80 ;
}
V_43 = F_33 ( V_10 , & V_10 -> V_234 , V_8 ) ;
if ( V_43 )
return V_43 ;
sprintf ( V_10 -> V_234 . V_819 , L_16 , V_10 -> V_115 ) ;
V_200 = F_34 ( V_10 , & V_10 -> V_234 ) ;
V_43 = F_135 ( V_200 , F_67 , V_311 , V_10 -> V_234 . V_819 ,
& V_10 -> V_234 ) ;
if ( V_43 )
F_35 ( V_10 , & V_10 -> V_234 ) ;
return V_43 ;
}
static int F_136 ( struct V_9 * V_10 )
{
int V_816 , V_164 , V_43 = 0 ;
int V_200 ;
unsigned long V_311 = 0 ;
V_816 = V_10 -> V_112 . V_168 . V_818 -
V_10 -> V_112 . V_168 . V_169 ;
if ( V_10 -> V_112 . V_201 == V_202 ) {
V_816 = 1 ;
V_311 = V_817 ;
} else
V_816 = F_137 ( T_1 , V_816 , F_138 () ) ;
V_10 -> V_205 = F_20 ( sizeof( struct V_1 ) * V_816 , V_140 ) ;
if ( ! V_10 -> V_205 )
return - V_158 ;
for ( V_164 = 0 ; V_164 < V_816 ; V_164 ++ ) {
V_43 = F_33 ( V_10 , & V_10 -> V_205 [ V_164 ] ,
V_8 ) ;
if ( V_43 ) {
V_43 = - V_75 ;
break;
}
sprintf ( V_10 -> V_205 [ V_164 ] . V_819 , L_17 ,
V_10 -> V_115 , V_164 ) ;
V_200 = F_34 ( V_10 , & V_10 -> V_205 [ V_164 ] ) ;
V_43 = F_135 ( V_200 , F_67 , V_311 ,
V_10 -> V_205 [ V_164 ] . V_819 ,
& V_10 -> V_205 [ V_164 ] ) ;
if ( V_43 ) {
F_35 ( V_10 , & V_10 -> V_205 [ V_164 ] ) ;
V_43 = - V_75 ;
break;
}
V_10 -> V_204 += 1 ;
}
if ( V_10 -> V_204 >= 1 )
return 0 ;
if ( V_43 )
F_38 ( V_10 ) ;
return V_43 ;
}
int F_139 ( struct V_9 * V_10 )
{
int V_43 ;
V_43 = F_134 ( V_10 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_136 ( V_10 ) ;
if ( V_43 )
goto V_820;
V_43 = F_45 ( V_10 ) ;
if ( V_43 )
goto V_821;
V_43 = F_80 ( V_10 ) ;
if ( V_43 )
goto V_822;
V_43 = F_81 ( V_10 ) ;
if ( V_43 )
goto V_822;
V_43 = F_78 ( V_10 ) ;
if ( V_43 )
goto V_822;
V_43 = F_87 ( V_10 ) ;
if ( V_43 )
goto V_822;
return 0 ;
V_822:
F_48 ( V_10 ) ;
V_821:
F_38 ( V_10 ) ;
V_820:
F_36 ( V_10 , & V_10 -> V_234 ) ;
F_54 ( L_8 , V_292 , V_43 ) ;
return V_43 ;
}
void F_140 ( struct V_9 * V_10 )
{
F_88 ( V_10 ) ;
F_38 ( V_10 ) ;
F_48 ( V_10 ) ;
F_36 ( V_10 , & V_10 -> V_234 ) ;
}
