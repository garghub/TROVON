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
static int F_12 ( T_3 V_91 )
{
int V_42 = - V_72 ;
switch ( V_91 ) {
case V_92 :
V_42 = - V_93 ;
break;
case V_94 :
V_42 = - V_72 ;
break;
case V_95 :
case V_96 :
V_42 = - V_72 ;
break;
case V_97 :
default:
V_42 = - V_72 ;
break;
}
return V_42 ;
}
void F_13 ( struct V_8 * V_9 , T_3 V_98 , bool V_99 ,
bool V_100 , T_3 V_101 )
{
T_1 V_102 = V_98 & V_103 ;
V_102 |= ( ( V_98 & V_104 ) <<
V_105 ) ;
if ( V_99 )
V_102 |= ( 1 << V_106 ) ;
if ( V_100 )
V_102 |= ( 1 << V_107 ) ;
V_102 |= ( V_101 << V_108 ) ;
F_14 ( V_102 , V_9 -> V_109 . V_110 + V_111 ) ;
}
static void F_15 ( struct V_8 * V_9 )
{
T_1 V_102 = 0 ;
V_102 |= V_9 -> V_12 . V_18 . V_112 & V_113 ;
V_102 |= 1 << V_114 ;
F_14 ( V_102 , V_9 -> V_109 . V_110 + V_115 ) ;
}
static void F_16 ( struct V_8 * V_9 , T_3 V_116 ,
bool V_117 , bool V_118 , T_3 V_119 )
{
T_1 V_102 = 0 ;
V_102 |= V_116 & V_120 ;
V_102 |= ( ( V_116 & V_121 ) << V_122 ) ;
if ( V_117 )
V_102 |= ( 1 << V_123 ) ;
if ( V_118 )
V_102 |= ( 1 << V_124 ) ;
V_102 |= ( 1 << V_125 ) ;
V_102 |= ( V_119 << V_126 ) ;
F_14 ( V_102 , V_9 -> V_109 . V_110 + V_127 ) ;
}
static void F_17 ( struct V_128 * V_129 ,
T_2 V_130 , T_2 V_131 , T_1 V_132 )
{
V_129 -> V_133 = ( V_130 | ( V_131 << V_134 ) ) ;
V_129 -> V_135 = 20 ;
V_129 -> V_132 = V_132 - sizeof( struct V_128 ) ;
}
static void * F_18 ( T_2 V_130 , T_1 V_132 )
{
struct V_17 * V_136 ;
V_136 = F_19 ( sizeof( struct V_17 ) , V_137 ) ;
if ( ! V_136 )
return NULL ;
V_136 -> V_138 . V_139 |=
( V_140 << V_141 ) &
V_142 ;
V_136 -> V_138 . V_143 = V_132 - sizeof( struct V_144 ) ;
F_17 ( & V_136 -> V_145 . V_146 . V_147 , V_130 , V_148 ,
V_136 -> V_138 . V_143 ) ;
return V_136 ;
}
static void F_20 ( struct V_8 * V_9 , struct V_149 * V_3 )
{
F_21 ( & V_9 -> V_109 . V_150 -> V_9 , V_3 -> V_151 , V_3 -> V_4 , V_3 -> V_152 ) ;
}
static int F_22 ( struct V_8 * V_9 ,
struct V_149 * V_3 , T_3 V_153 , T_3 V_154 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_153 = V_153 ;
V_3 -> V_154 = V_154 ;
V_3 -> V_151 = V_153 * V_154 ;
V_3 -> V_4 = F_23 ( & V_9 -> V_109 . V_150 -> V_9 , V_3 -> V_151 ,
& V_3 -> V_152 , V_137 ) ;
if ( ! V_3 -> V_4 )
return - V_155 ;
memset ( V_3 -> V_4 , 0 , V_3 -> V_151 ) ;
return 0 ;
}
static void F_24 ( struct V_156 * V_157 , int V_158 ,
T_4 V_159 , int V_160 )
{
int V_161 ;
for ( V_161 = 0 ; V_161 < V_158 ; V_161 ++ ) {
V_157 [ V_161 ] . V_162 = ( T_1 ) ( V_159 & 0xffffffff ) ;
V_157 [ V_161 ] . V_163 = ( T_1 ) F_25 ( V_159 ) ;
V_159 += V_160 ;
}
}
static int F_26 ( struct V_8 * V_9 , struct V_149 * V_3 ,
int V_164 )
{
T_2 V_130 = 0 ;
int V_41 ;
struct V_165 * V_166 = V_9 -> V_167 ;
switch ( V_164 ) {
case V_168 :
V_130 = V_169 ;
break;
case V_170 :
V_130 = V_171 ;
break;
case V_172 :
V_130 = V_173 ;
break;
default:
F_27 () ;
}
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
F_17 ( & V_166 -> V_174 , V_130 , V_175 , sizeof( * V_166 ) ) ;
V_166 -> V_112 = V_3 -> V_112 ;
V_41 = F_28 ( V_9 -> V_109 . V_176 ,
V_166 , sizeof( * V_166 ) , NULL , NULL ) ;
if ( ! V_41 )
V_3 -> V_177 = false ;
return V_41 ;
}
static int F_29 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_41 ;
struct V_178 * V_166 = V_9 -> V_167 ;
struct V_179 * V_180 = V_9 -> V_167 ;
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
F_17 ( & V_166 -> V_174 , V_181 , V_175 ,
sizeof( * V_166 ) ) ;
V_166 -> V_174 . V_182 = 2 ;
V_166 -> V_183 = 4 ;
V_166 -> V_184 = V_185 ;
V_166 -> V_158 = 4 << V_186 ;
F_24 ( & V_166 -> V_187 [ 0 ] , V_166 -> V_183 , V_2 -> V_3 . V_152 ,
V_188 ) ;
V_41 = F_28 ( V_9 -> V_109 . V_176 , V_166 , sizeof( * V_166 ) , NULL ,
NULL ) ;
if ( ! V_41 ) {
V_2 -> V_3 . V_112 = V_180 -> V_189 & 0xffff ;
V_2 -> V_190 = ( V_180 -> V_189 >> 16 ) & 0xffff ;
V_2 -> V_3 . V_177 = true ;
}
return V_41 ;
}
static int F_30 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_3 V_191 )
{
int V_41 ;
V_41 = F_22 ( V_9 , & V_2 -> V_3 , V_7 ,
sizeof( struct V_6 ) ) ;
if ( V_41 )
return V_41 ;
V_41 = F_29 ( V_9 , V_2 ) ;
if ( V_41 )
goto V_192;
V_2 -> V_9 = V_9 ;
F_16 ( V_9 , V_2 -> V_3 . V_112 , true , true , 0 ) ;
return 0 ;
V_192:
F_20 ( V_9 , & V_2 -> V_3 ) ;
return V_41 ;
}
static int F_31 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_193 ;
if ( V_9 -> V_109 . V_194 == V_195 )
V_193 = V_9 -> V_109 . V_150 -> V_193 ;
else
V_193 = V_9 -> V_109 . V_196 . V_197 [ V_2 -> V_190 ] ;
return V_193 ;
}
static void F_32 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_177 ) {
F_26 ( V_9 , & V_2 -> V_3 , V_172 ) ;
F_20 ( V_9 , & V_2 -> V_3 ) ;
}
}
static void F_33 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_193 ;
F_16 ( V_9 , V_2 -> V_3 . V_112 , false , false , 0 ) ;
V_193 = F_31 ( V_9 , V_2 ) ;
F_34 ( V_193 , V_2 ) ;
F_32 ( V_9 , V_2 ) ;
}
static void F_35 ( struct V_8 * V_9 )
{
int V_161 ;
for ( V_161 = 0 ; V_161 < V_9 -> V_198 ; V_161 ++ )
F_33 ( V_9 , & V_9 -> V_199 [ V_161 ] ) ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_149 * V_13 ,
struct V_149 * V_2 )
{
struct V_200 * V_166 = V_9 -> V_167 ;
struct V_201 * V_180 = V_9 -> V_167 ;
int V_41 ;
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
F_17 ( & V_166 -> V_174 , V_202 ,
V_175 , sizeof( * V_166 ) ) ;
V_166 -> V_174 . V_182 = V_203 ;
V_166 -> V_204 = ( V_13 -> V_151 / V_205 ) <<
V_206 ;
V_166 -> V_204 |= F_37 ( V_13 -> V_4 , V_13 -> V_151 ) ;
V_166 -> V_207 = V_208 ;
V_166 -> V_209 = V_2 -> V_112 ;
V_166 -> V_210 = V_13 -> V_151 / sizeof( struct V_10 ) ;
F_24 ( & V_166 -> V_187 [ 0 ] , V_13 -> V_151 / V_205 ,
V_13 -> V_152 , V_188 ) ;
V_41 = F_28 ( V_9 -> V_109 . V_176 ,
V_166 , sizeof( * V_166 ) , NULL , NULL ) ;
if ( ! V_41 ) {
V_13 -> V_112 = ( T_3 ) ( V_180 -> V_98 & V_211 ) ;
V_13 -> V_177 = true ;
}
return V_41 ;
}
static T_1 F_38 ( int V_191 )
{
T_1 V_212 = F_39 ( V_191 ) ;
if ( V_212 == 16 )
V_212 = 0 ;
return V_212 ;
}
static int F_40 ( struct V_8 * V_9 ,
struct V_149 * V_12 ,
struct V_149 * V_13 )
{
int V_183 , V_41 ;
struct V_213 * V_166 = V_9 -> V_167 ;
struct V_214 * V_180 = V_9 -> V_167 ;
struct V_156 * V_187 ;
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
V_183 = F_37 ( V_12 -> V_4 , V_12 -> V_151 ) ;
F_17 ( & V_166 -> V_174 , V_215 ,
V_175 , sizeof( * V_166 ) ) ;
V_166 -> V_174 . V_182 = 1 ;
V_166 -> V_216 = V_183 ;
V_166 -> V_216 |= ( V_13 -> V_112 << V_217 ) ;
V_166 -> V_218 = V_219 ;
V_166 -> V_220 = F_41 ( V_221 ) ;
V_166 -> V_220 |= F_41 ( V_222 ) ;
V_166 -> V_223 = V_13 -> V_112 ;
V_166 -> V_223 |= ( F_38 ( V_12 -> V_153 ) <<
V_224 ) ;
V_166 -> V_184 = V_225 ;
V_187 = & V_166 -> V_187 [ 0 ] ;
F_24 ( V_187 , V_183 , V_12 -> V_152 , V_188 ) ;
V_41 = F_28 ( V_9 -> V_109 . V_176 ,
V_166 , sizeof( * V_166 ) , NULL , NULL ) ;
if ( ! V_41 ) {
V_12 -> V_112 = V_180 -> V_112 ;
V_12 -> V_177 = true ;
}
return V_41 ;
}
static int F_42 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_22 ( V_9 , & V_9 -> V_12 . V_13 , V_16 ,
sizeof( struct V_10 ) ) ;
if ( V_41 )
goto V_226;
V_41 = F_36 ( V_9 , & V_9 -> V_12 . V_13 , & V_9 -> V_199 [ 0 ] . V_3 ) ;
if ( V_41 )
goto V_227;
memset ( & V_9 -> V_21 , 0 , sizeof( V_9 -> V_21 ) ) ;
F_43 ( & V_9 -> V_21 . V_228 ) ;
F_44 ( & V_9 -> V_21 . V_229 ) ;
V_41 = F_22 ( V_9 , & V_9 -> V_12 . V_18 , V_20 ,
sizeof( struct V_17 ) ) ;
if ( V_41 )
goto V_230;
V_41 = F_40 ( V_9 , & V_9 -> V_12 . V_18 , & V_9 -> V_12 . V_13 ) ;
if ( V_41 )
goto V_231;
F_13 ( V_9 , V_9 -> V_12 . V_13 . V_112 , true , false , 0 ) ;
return 0 ;
V_231:
F_20 ( V_9 , & V_9 -> V_12 . V_18 ) ;
V_230:
F_26 ( V_9 , & V_9 -> V_12 . V_13 , V_170 ) ;
V_227:
F_20 ( V_9 , & V_9 -> V_12 . V_13 ) ;
V_226:
return V_41 ;
}
static void F_45 ( struct V_8 * V_9 )
{
struct V_149 * V_232 , * V_13 ;
F_46 ( & V_9 -> V_21 . V_229 ) ;
V_232 = & V_9 -> V_12 . V_18 ;
if ( V_232 -> V_177 ) {
F_26 ( V_9 , V_232 , V_168 ) ;
F_20 ( V_9 , V_232 ) ;
}
F_47 ( & V_9 -> V_21 . V_229 ) ;
V_13 = & V_9 -> V_12 . V_13 ;
if ( V_13 -> V_177 ) {
F_26 ( V_9 , V_13 , V_170 ) ;
F_20 ( V_9 , V_13 ) ;
}
}
static void F_48 ( struct V_8 * V_9 ,
struct V_233 * V_234 )
{
enum V_23 V_235 = V_40 ;
enum V_23 V_236 ;
if ( V_234 == NULL )
F_27 () ;
F_49 ( V_234 , V_235 , & V_236 ) ;
}
static void F_50 ( struct V_8 * V_9 ,
struct V_237 * V_11 )
{
struct V_233 * V_234 = NULL ;
struct V_238 * V_13 = NULL ;
struct V_239 V_240 ;
int V_241 = 0 ;
int V_242 = 1 ;
int V_243 = 0 ;
int V_244 = 0 ;
int type = ( V_11 -> V_245 & V_246 ) >>
V_247 ;
if ( V_11 -> V_248 & V_249 )
V_234 = V_9 -> V_250 [ V_11 -> V_248 & V_251 ] ;
if ( V_11 -> V_252 & V_253 )
V_13 = V_9 -> V_254 [ V_11 -> V_252 & V_255 ] ;
V_240 . V_256 = & V_9 -> V_257 ;
switch ( type ) {
case V_258 :
V_240 . V_259 . V_13 = & V_13 -> V_260 ;
V_240 . V_261 = V_262 ;
V_241 = 1 ;
V_242 = 0 ;
break;
case V_263 :
V_240 . V_259 . V_13 = & V_13 -> V_260 ;
V_240 . V_261 = V_262 ;
break;
case V_264 :
V_240 . V_259 . V_234 = & V_234 -> V_265 ;
V_240 . V_261 = V_266 ;
F_48 ( V_9 , V_234 ) ;
break;
case V_267 :
V_240 . V_259 . V_234 = & V_234 -> V_265 ;
V_240 . V_261 = V_268 ;
break;
case V_269 :
V_240 . V_259 . V_234 = & V_234 -> V_265 ;
V_240 . V_261 = V_270 ;
break;
case V_271 :
V_240 . V_259 . V_234 = & V_234 -> V_265 ;
V_240 . V_261 = V_272 ;
break;
case V_273 :
V_240 . V_259 . V_274 = 1 ;
V_240 . V_261 = V_275 ;
V_242 = 0 ;
V_244 = 1 ;
break;
case V_276 :
V_240 . V_259 . V_277 = & V_234 -> V_277 -> V_278 ;
V_240 . V_261 = V_279 ;
V_243 = 1 ;
V_242 = 0 ;
break;
case V_280 :
V_240 . V_259 . V_277 = & V_234 -> V_277 -> V_278 ;
V_240 . V_261 = V_281 ;
V_243 = 1 ;
V_242 = 0 ;
break;
case V_282 :
V_240 . V_259 . V_234 = & V_234 -> V_265 ;
V_240 . V_261 = V_283 ;
break;
default:
V_241 = 0 ;
V_242 = 0 ;
V_243 = 0 ;
V_244 = 0 ;
F_51 ( L_1 , V_284 , type ) ;
break;
}
if ( V_242 ) {
if ( V_234 -> V_265 . V_285 )
V_234 -> V_265 . V_285 ( & V_240 , V_234 -> V_265 . V_286 ) ;
} else if ( V_241 ) {
if ( V_13 -> V_260 . V_285 )
V_13 -> V_260 . V_285 ( & V_240 , V_13 -> V_260 . V_287 ) ;
} else if ( V_243 ) {
if ( V_234 -> V_277 -> V_278 . V_285 )
V_234 -> V_277 -> V_278 . V_285 ( & V_240 ,
V_234 -> V_277 -> V_278 .
V_288 ) ;
} else if ( V_244 ) {
F_52 ( & V_240 ) ;
}
}
static void F_53 ( struct V_8 * V_9 ,
struct V_237 * V_11 )
{
struct V_289 * V_290 ;
int type = ( V_11 -> V_245 & V_246 ) >>
V_247 ;
switch ( type ) {
case V_291 :
V_290 = (struct V_289 * ) V_11 ;
if ( ( V_290 -> V_292 & V_293 ) >>
V_294 )
V_9 -> V_295 = ( ( V_290 -> V_292 &
V_296 ) >>
V_297 ) ;
break;
default:
break;
}
}
static void F_54 ( struct V_8 * V_9 , void * V_298 )
{
struct V_237 * V_11 = V_298 ;
T_1 V_299 = ( V_11 -> V_245 & V_300 ) >>
V_301 ;
if ( V_299 == V_222 )
F_50 ( V_9 , V_11 ) ;
else if ( V_299 == V_221 )
F_53 ( V_9 , V_11 ) ;
else
F_51 ( L_2 , V_284 ,
V_9 -> V_112 , V_299 ) ;
}
static void F_55 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
if ( V_9 -> V_21 . V_22 == V_11 -> V_302 && V_9 -> V_21 . V_303 == false ) {
V_9 -> V_21 . V_91 = ( V_11 -> V_41 &
V_304 ) >> V_305 ;
V_9 -> V_21 . V_306 =
( V_11 -> V_41 & V_307 )
>> V_308 ;
V_9 -> V_21 . V_303 = true ;
F_56 ( & V_9 -> V_21 . V_228 ) ;
} else
F_51 ( L_3 ,
V_284 , V_11 -> V_302 , V_9 -> V_21 . V_22 ) ;
}
static int F_57 ( struct V_8 * V_9 , T_3 V_98 )
{
T_3 V_101 = 0 ;
struct V_10 * V_11 ;
while ( 1 ) {
V_11 = F_3 ( V_9 ) ;
if ( V_11 == NULL )
break;
F_58 ( V_11 , sizeof( * V_11 ) ) ;
V_101 += 1 ;
if ( V_11 -> V_14 & V_309 )
F_54 ( V_9 , V_11 ) ;
else if ( V_11 -> V_14 & V_310 )
F_55 ( V_9 , V_11 ) ;
else
F_51 ( L_4 , V_284 ) ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
F_5 ( V_9 ) ;
}
F_13 ( V_9 , V_9 -> V_12 . V_13 . V_112 , true , false , V_101 ) ;
return 0 ;
}
static void F_59 ( struct V_8 * V_9 ,
struct V_238 * V_13 )
{
unsigned long V_311 ;
struct V_233 * V_234 ;
bool V_312 = false ;
F_60 ( & V_9 -> V_313 , V_311 ) ;
F_61 (qp, &cq->sq_head, sq_entry) {
if ( V_234 -> V_277 )
continue;
if ( V_234 -> V_314 == V_234 -> V_315 )
continue;
if ( V_234 -> V_314 == V_13 )
V_13 = V_234 -> V_315 ;
else
V_13 = V_234 -> V_314 ;
V_312 = true ;
break;
}
F_62 ( & V_9 -> V_313 , V_311 ) ;
if ( V_312 == false )
return;
if ( V_13 -> V_260 . V_316 ) {
F_60 ( & V_13 -> V_317 , V_311 ) ;
(* V_13 -> V_260 . V_316 ) ( & V_13 -> V_260 , V_13 -> V_260 . V_287 ) ;
F_62 ( & V_13 -> V_317 , V_311 ) ;
}
}
static void F_63 ( struct V_8 * V_9 , T_3 V_318 )
{
unsigned long V_311 ;
struct V_238 * V_13 ;
if ( V_318 >= V_319 )
F_27 () ;
V_13 = V_9 -> V_254 [ V_318 ] ;
if ( V_13 == NULL ) {
F_51 ( L_5 , V_284 , V_9 -> V_112 , V_318 ) ;
return;
}
F_60 ( & V_13 -> V_320 , V_311 ) ;
V_13 -> V_99 = false ;
V_13 -> V_100 = false ;
F_62 ( & V_13 -> V_320 , V_311 ) ;
F_13 ( V_9 , V_13 -> V_112 , false , false , 0 ) ;
if ( V_13 -> V_260 . V_316 ) {
F_60 ( & V_13 -> V_317 , V_311 ) ;
(* V_13 -> V_260 . V_316 ) ( & V_13 -> V_260 , V_13 -> V_260 . V_287 ) ;
F_62 ( & V_13 -> V_317 , V_311 ) ;
}
F_59 ( V_9 , V_13 ) ;
}
static void F_64 ( struct V_8 * V_9 , T_3 V_98 )
{
if ( V_98 == V_9 -> V_12 . V_13 . V_112 )
F_57 ( V_9 , V_98 ) ;
else
F_63 ( V_9 , V_98 ) ;
}
static T_5 F_65 ( int V_193 , void * V_321 )
{
struct V_1 * V_2 = V_321 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 V_322 ;
struct V_6 * V_323 ;
T_3 V_324 = 0 ;
T_3 V_98 ;
while ( 1 ) {
V_323 = F_1 ( V_2 ) ;
V_322 = * V_323 ;
F_58 ( & V_322 , sizeof( V_322 ) ) ;
if ( ( V_322 . V_325 & V_326 ) == 0 )
break;
V_324 += 1 ;
V_323 -> V_325 = 0 ;
if ( ( V_322 . V_325 & V_327 ) == 0 ) {
V_98 = V_322 . V_325 >> V_328 ;
F_64 ( V_9 , V_98 ) ;
}
F_2 ( V_2 ) ;
}
F_16 ( V_9 , V_2 -> V_3 . V_112 , true , true , V_324 ) ;
if ( V_9 -> V_109 . V_194 == V_195 )
F_16 ( V_9 , V_2 -> V_3 . V_112 , true , true , 0 ) ;
return V_329 ;
}
static void F_66 ( struct V_8 * V_9 , struct V_17 * V_166 )
{
struct V_17 * V_136 ;
V_9 -> V_21 . V_22 = V_9 -> V_12 . V_18 . V_19 ;
V_9 -> V_21 . V_303 = false ;
V_136 = F_6 ( V_9 ) ;
V_166 -> V_138 . V_302 = V_9 -> V_12 . V_18 . V_19 ;
F_67 ( V_136 , V_166 , sizeof( * V_136 ) ) ;
F_68 () ;
F_7 ( V_9 ) ;
F_15 ( V_9 ) ;
}
static int F_69 ( struct V_8 * V_9 )
{
long V_41 ;
V_41 = F_70 ( V_9 -> V_21 . V_228 ,
( V_9 -> V_21 . V_303 != false ) ,
F_71 ( 30000 ) ) ;
if ( V_41 )
return 0 ;
else
return - 1 ;
}
static int F_72 ( struct V_8 * V_9 , struct V_17 * V_136 )
{
int V_41 = 0 ;
T_3 V_91 , V_306 ;
struct V_17 * V_180 ;
F_46 ( & V_9 -> V_21 . V_229 ) ;
F_66 ( V_9 , V_136 ) ;
V_41 = F_69 ( V_9 ) ;
if ( V_41 )
goto V_192;
V_91 = V_9 -> V_21 . V_91 ;
V_306 = V_9 -> V_21 . V_306 ;
V_180 = F_8 ( V_9 ) ;
F_73 ( V_136 , V_180 , ( sizeof( * V_136 ) ) ) ;
if ( V_91 || V_306 ) {
F_51 ( L_6 ,
V_284 ,
( V_180 -> V_145 . V_180 . V_133 & V_330 ) >>
V_331 , V_91 , V_306 ) ;
V_41 = F_12 ( V_91 ) ;
goto V_192;
}
if ( V_136 -> V_145 . V_180 . V_41 & V_44 )
V_41 = F_11 ( V_136 -> V_145 . V_180 . V_41 ) ;
V_192:
F_47 ( & V_9 -> V_21 . V_229 ) ;
return V_41 ;
}
static void F_74 ( struct V_8 * V_9 ,
struct V_332 * V_333 ,
struct V_334 * V_180 )
{
V_333 -> V_335 =
( V_180 -> V_336 & V_337 ) >>
V_338 ;
V_333 -> V_339 =
( V_180 -> V_340 & V_341 ) >>
V_342 ;
V_333 -> V_343 = ( ( V_180 -> V_344 &
V_345 ) >>
V_346 ) ;
V_333 -> V_347 = ( V_180 -> V_344 &
V_345 ) >>
V_346 ;
V_333 -> V_348 = ( V_180 -> V_349 &
V_350 ) >>
V_351 ;
V_333 -> V_352 = ( V_180 -> V_344 &
V_353 ) >>
V_354 ;
V_333 -> V_355 = ( V_180 -> V_356 &
V_357 ) >>
V_358 ;
V_333 -> V_359 =
( V_180 -> V_360 & V_361 ) >>
V_362 ;
V_333 -> V_363 = ( V_180 -> V_356 &
V_364 ) >>
V_365 ;
V_333 -> V_366 = ( V_180 -> V_340 &
V_367 ) >>
V_368 ;
V_333 -> V_369 = ( V_180 -> V_340 &
V_370 ) >>
V_371 ;
V_333 -> V_372 = ( V_180 -> V_336 &
V_373 ) >>
V_374 ;
V_333 -> V_375 = V_180 -> V_375 ;
V_333 -> V_376 = ~ 0ull ;
V_333 -> V_377 = 0 ;
V_333 -> V_378 = V_180 -> V_378 ;
V_333 -> V_379 = V_180 -> V_379 ;
V_333 -> V_380 = V_180 -> V_381 &
V_382 ;
V_333 -> V_383 = ( V_180 -> V_381 &
V_384 ) >>
V_385 ;
V_333 -> V_386 = ( ( V_180 -> V_387 &
V_388 ) >>
V_389 ) *
V_390 ;
V_333 -> V_391 = ( ( V_180 -> V_387 &
V_392 ) >>
V_393 ) *
V_390 ;
V_333 -> V_394 =
V_333 -> V_386 - ( sizeof( struct V_395 ) +
sizeof( struct V_396 ) ) ;
if ( V_9 -> V_109 . V_397 == V_398 ) {
V_333 -> V_399 = 1 ;
V_333 -> V_400 = V_205 ;
V_333 -> V_401 = V_402 ;
}
V_9 -> V_333 . V_403 = V_180 -> V_404 >>
V_405 ;
V_9 -> V_333 . V_406 = V_180 -> V_404 &
V_407 ;
}
static int F_75 ( struct V_8 * V_9 ,
struct V_408 * V_409 )
{
T_1 V_410 ;
V_410 = V_409 -> V_410 & V_411 ;
if ( V_410 != V_411 )
return - V_72 ;
V_9 -> V_412 = V_409 -> V_412 ;
V_9 -> V_413 = V_409 -> V_413 ;
return 0 ;
}
static int F_76 ( struct V_8 * V_9 )
{
int V_41 = - V_155 ;
struct V_17 * V_166 ;
struct V_414 * V_180 ;
V_166 = F_18 ( V_415 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return - V_155 ;
F_17 ( (struct V_128 * ) & V_166 -> V_145 . V_166 [ 0 ] ,
V_415 ,
V_175 , sizeof( * V_166 ) ) ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_414 * ) V_166 ;
memset ( & V_9 -> V_333 . V_416 [ 0 ] , 0 , sizeof( V_9 -> V_333 . V_416 ) ) ;
memcpy ( & V_9 -> V_333 . V_416 [ 0 ] , & V_180 -> V_417 [ 0 ] ,
sizeof( V_180 -> V_417 ) ) ;
F_58 ( V_9 -> V_333 . V_416 , sizeof( V_180 -> V_417 ) ) ;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
static int F_78 ( struct V_8 * V_9 )
{
int V_41 = - V_155 ;
struct V_17 * V_166 ;
struct V_408 * V_180 ;
V_166 = F_18 ( V_418 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return - V_155 ;
F_17 ( (struct V_128 * ) & V_166 -> V_145 . V_166 [ 0 ] ,
V_418 ,
V_175 , sizeof( * V_166 ) ) ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_408 * ) V_166 ;
V_41 = F_75 ( V_9 , V_180 ) ;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
static int F_79 ( struct V_8 * V_9 )
{
int V_41 = - V_155 ;
struct V_334 * V_180 ;
struct V_17 * V_166 ;
V_166 = F_18 ( V_419 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_334 * ) V_166 ;
F_74 ( V_9 , & V_9 -> V_333 , V_180 ) ;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_80 ( struct V_8 * V_9 , T_2 * V_420 )
{
int V_41 = - V_155 ;
struct V_421 * V_180 ;
struct V_17 * V_166 ;
V_166 = F_18 ( V_422 ,
sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
F_17 ( (struct V_128 * ) & V_166 -> V_145 . V_166 [ 0 ] ,
V_422 ,
V_175 , sizeof( * V_166 ) ) ;
( (struct V_128 * ) V_166 -> V_145 . V_166 ) -> V_182 = 0x1 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_421 * ) V_166 ;
* V_420 = V_180 -> V_423 ;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_81 ( struct V_8 * V_9 , struct V_424 * V_425 )
{
int V_41 = - V_155 ;
struct V_426 * V_166 ;
struct V_427 * V_180 ;
V_166 = F_18 ( V_428 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
if ( V_425 -> V_429 )
V_166 -> V_430 |= V_431 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_427 * ) V_166 ;
V_425 -> V_112 = V_180 -> V_432 & V_433 ;
if ( V_180 -> V_432 & V_434 ) {
V_425 -> V_429 = true ;
V_425 -> V_435 = V_180 -> V_432 >>
V_436 ;
} else {
V_425 -> V_429 = false ;
V_425 -> V_437 = 0 ;
}
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_82 ( struct V_8 * V_9 , struct V_424 * V_425 )
{
int V_41 = - V_155 ;
struct V_438 * V_166 ;
V_166 = F_18 ( V_439 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_112 = V_425 -> V_112 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
F_77 ( V_166 ) ;
return V_41 ;
}
static int F_83 ( T_1 * V_440 , int V_154 ,
int * V_183 , int * V_441 )
{
int V_161 ;
int V_442 ;
* V_440 = F_84 ( * V_440 ) ;
V_442 = * V_440 * V_154 ;
for ( V_161 = 0 ; V_161 < V_443 ; V_161 ++ ) {
if ( V_442 <= ( V_444 << V_161 ) )
break;
}
if ( V_161 >= V_443 )
return - V_72 ;
V_442 = F_85 ( V_442 ,
( ( V_444 << V_161 ) / V_445 ) ) ;
* V_183 =
V_442 / ( ( V_444 << V_161 ) / V_445 ) ;
* V_441 = ( ( V_444 << V_161 ) / V_445 ) ;
* V_440 = V_442 / V_154 ;
return 0 ;
}
static int F_86 ( struct V_8 * V_9 )
{
int V_161 ;
int V_41 = 0 ;
int V_446 ;
struct V_447 * V_166 ;
struct V_448 * V_180 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
T_4 V_187 ;
struct V_450 * V_451 ;
V_166 = F_18 ( V_452 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_446 = V_453 ;
V_9 -> V_454 . V_151 = sizeof( struct V_455 ) * V_446 ;
V_166 -> V_456 = ( V_457 <<
V_458 ) &
V_459 ;
for ( V_161 = 0 ; V_161 < V_443 ; V_161 ++ ) {
if ( V_460 == ( V_205 << V_161 ) )
break;
}
V_166 -> V_456 |= ( V_161 << V_461 ) &
V_462 ;
V_166 -> V_456 |= ( sizeof( struct V_455 ) <<
V_463 ) &
V_464 ;
V_9 -> V_454 . V_465 . V_4 = F_23 ( & V_150 -> V_9 , V_460 ,
& V_9 -> V_454 . V_465 . V_187 ,
V_137 ) ;
if ( V_9 -> V_454 . V_465 . V_4 == NULL )
goto V_466;
V_9 -> V_454 . V_4 = F_23 ( & V_150 -> V_9 , V_9 -> V_454 . V_151 ,
& V_187 , V_137 ) ;
if ( V_9 -> V_454 . V_4 == NULL )
goto V_467;
V_9 -> V_454 . V_187 = V_187 ;
V_9 -> V_454 . V_468 = V_446 ;
memset ( V_9 -> V_454 . V_4 , 0 , V_9 -> V_454 . V_151 ) ;
V_451 = (struct V_450 * ) V_9 -> V_454 . V_465 . V_4 ;
for ( V_161 = 0 ; V_161 < V_9 -> V_454 . V_151 / V_205 ; V_161 ++ ) {
V_451 [ V_161 ] . V_469 = ( T_1 ) ( V_187 & 0xffffffff ) ;
V_451 [ V_161 ] . V_470 = ( T_1 ) F_25 ( V_187 ) ;
V_187 += V_460 ;
}
V_166 -> V_471 [ 0 ] . V_162 = ( T_1 ) ( V_9 -> V_454 . V_465 . V_187 & 0xFFFFFFFF ) ;
V_166 -> V_471 [ 0 ] . V_163 = ( T_1 ) F_25 ( V_9 -> V_454 . V_465 . V_187 ) ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_448 * ) V_166 ;
V_9 -> V_454 . V_472 = V_180 -> V_472 & 0xFFFF ;
F_77 ( V_166 ) ;
return 0 ;
V_192:
F_21 ( & V_150 -> V_9 , V_9 -> V_454 . V_151 , V_9 -> V_454 . V_4 ,
V_9 -> V_454 . V_187 ) ;
V_9 -> V_454 . V_4 = NULL ;
V_467:
F_21 ( & V_150 -> V_9 , V_460 , V_9 -> V_454 . V_465 . V_4 ,
V_9 -> V_454 . V_465 . V_187 ) ;
V_9 -> V_454 . V_465 . V_4 = NULL ;
V_9 -> V_454 . V_151 = 0 ;
V_466:
F_77 ( V_166 ) ;
return V_41 ;
}
static void F_87 ( struct V_8 * V_9 )
{
struct V_473 * V_166 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
if ( V_9 -> V_454 . V_4 == NULL )
return;
V_166 = F_18 ( V_474 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return;
V_166 -> V_472 = V_9 -> V_454 . V_472 ;
F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
F_21 ( & V_150 -> V_9 , V_9 -> V_454 . V_151 , V_9 -> V_454 . V_4 ,
V_9 -> V_454 . V_187 ) ;
F_21 ( & V_150 -> V_9 , V_460 , V_9 -> V_454 . V_465 . V_4 ,
V_9 -> V_454 . V_465 . V_187 ) ;
F_77 ( V_166 ) ;
}
static T_3 F_88 ( struct V_8 * V_9 )
{
int V_161 , V_475 = 0 , V_476 = 0 ;
T_3 V_116 ;
F_46 ( & V_9 -> V_477 ) ;
V_476 = V_9 -> V_199 [ 0 ] . V_476 ;
V_116 = V_9 -> V_199 [ 0 ] . V_3 . V_112 ;
for ( V_161 = 0 ; V_161 < V_9 -> V_198 ; V_161 ++ ) {
if ( V_9 -> V_199 [ V_161 ] . V_476 < V_476 ) {
V_476 = V_9 -> V_199 [ V_161 ] . V_476 ;
V_116 = V_9 -> V_199 [ V_161 ] . V_3 . V_112 ;
V_475 = V_161 ;
}
}
V_9 -> V_199 [ V_475 ] . V_476 += 1 ;
F_47 ( & V_9 -> V_477 ) ;
return V_116 ;
}
static void F_89 ( struct V_8 * V_9 , T_3 V_116 )
{
int V_161 ;
F_46 ( & V_9 -> V_477 ) ;
for ( V_161 = 0 ; V_161 < V_9 -> V_198 ; V_161 ++ ) {
if ( V_9 -> V_199 [ V_161 ] . V_3 . V_112 != V_116 )
continue;
V_9 -> V_199 [ V_161 ] . V_476 -= 1 ;
break;
}
F_47 ( & V_9 -> V_477 ) ;
}
int F_90 ( struct V_8 * V_9 , struct V_238 * V_13 ,
int V_478 , int V_479 , T_3 V_480 )
{
int V_41 = - V_155 ; int V_481 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
struct V_482 * V_166 ;
struct V_483 * V_180 ;
T_1 V_484 , V_485 , V_441 , V_210 ;
if ( V_478 > V_9 -> V_333 . V_380 ) {
F_51 ( L_7 ,
V_284 , V_9 -> V_112 , V_9 -> V_333 . V_380 , V_478 ) ;
return - V_72 ;
}
if ( V_479 && ( V_9 -> V_109 . V_397 != V_398 ) )
return - V_72 ;
if ( V_479 ) {
V_13 -> V_481 = 1 ;
V_481 = 1 ;
V_485 = V_486 ;
V_484 = 1 ;
} else {
V_13 -> V_481 = V_9 -> V_333 . V_380 ;
V_481 = V_9 -> V_333 . V_380 ;
V_485 = sizeof( struct V_487 ) ;
V_484 = V_488 ;
}
V_13 -> V_153 = F_85 ( V_481 * V_485 , V_205 ) ;
V_166 = F_18 ( V_202 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return - V_155 ;
F_17 ( & V_166 -> V_166 . V_174 , V_202 ,
V_175 , sizeof( * V_166 ) ) ;
V_13 -> V_4 = F_23 ( & V_150 -> V_9 , V_13 -> V_153 , & V_13 -> V_187 , V_137 ) ;
if ( ! V_13 -> V_4 ) {
V_41 = - V_155 ;
goto V_466;
}
memset ( V_13 -> V_4 , 0 , V_13 -> V_153 ) ;
V_441 = V_13 -> V_153 / V_484 ;
V_166 -> V_166 . V_204 = ( V_441 / V_205 ) <<
V_206 ;
V_166 -> V_166 . V_204 |= V_484 ;
V_166 -> V_166 . V_207 = V_208 ;
V_13 -> V_209 = F_88 ( V_9 ) ;
V_166 -> V_166 . V_174 . V_182 = V_489 ;
V_210 = V_13 -> V_153 / V_485 ;
if ( V_210 > 1024 ) {
V_166 -> V_166 . V_207 |= ( 0x3 << V_490 ) ;
} else {
T_2 V_491 = 0 ;
switch ( V_210 ) {
case 256 :
V_491 = 0 ;
break;
case 512 :
V_491 = 1 ;
break;
case 1024 :
V_491 = 2 ;
break;
default:
goto V_192;
}
V_166 -> V_166 . V_207 |= ( V_491 << V_490 ) ;
}
V_166 -> V_166 . V_209 = V_13 -> V_209 ;
if ( V_9 -> V_109 . V_397 == V_398 ) {
if ( V_479 )
V_166 -> V_166 . V_204 |= V_492 <<
V_493 ;
V_13 -> V_494 = false ;
V_166 -> V_166 . V_210 = ( V_13 -> V_153 / V_485 ) ;
} else {
V_166 -> V_166 . V_210 = ( V_13 -> V_153 / V_485 ) - 1 ;
V_166 -> V_166 . V_207 |= V_495 ;
V_13 -> V_494 = true ;
}
V_166 -> V_166 . V_480 = V_480 ;
F_24 ( & V_166 -> V_166 . V_187 [ 0 ] , V_484 , V_13 -> V_187 , V_441 ) ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_483 * ) V_166 ;
V_13 -> V_112 = ( T_3 ) ( V_180 -> V_180 . V_98 & V_211 ) ;
F_77 ( V_166 ) ;
return 0 ;
V_192:
F_89 ( V_9 , V_13 -> V_209 ) ;
F_21 ( & V_150 -> V_9 , V_13 -> V_153 , V_13 -> V_4 , V_13 -> V_187 ) ;
V_466:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_91 ( struct V_8 * V_9 , struct V_238 * V_13 )
{
int V_41 = - V_155 ;
struct V_496 * V_166 ;
V_166 = F_18 ( V_171 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
F_17 ( & V_166 -> V_174 , V_171 ,
V_175 , sizeof( * V_166 ) ) ;
V_166 -> V_497 |=
( V_13 -> V_112 << V_498 ) &
V_499 ;
F_89 ( V_9 , V_13 -> V_209 ) ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
F_21 ( & V_9 -> V_109 . V_150 -> V_9 , V_13 -> V_153 , V_13 -> V_4 , V_13 -> V_187 ) ;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_92 ( struct V_8 * V_9 , struct V_500 * V_501 ,
T_1 V_502 , int V_503 )
{
int V_41 = - V_155 ;
struct V_504 * V_166 ;
struct V_505 * V_180 ;
V_166 = F_18 ( V_506 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_502 = V_502 ;
V_166 -> V_507 |= V_503 ;
V_166 -> V_507 |= ( V_501 -> V_508 << V_509 ) ;
V_166 -> V_507 |=
( V_501 -> V_510 << V_511 ) ;
V_166 -> V_507 |=
( V_501 -> V_512 << V_513 ) ;
V_166 -> V_507 |=
( V_501 -> V_514 << V_515 ) ;
V_166 -> V_507 |=
( V_501 -> V_516 << V_517 ) ;
V_166 -> V_507 |=
( V_501 -> V_518 << V_519 ) ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_505 * ) V_166 ;
V_501 -> V_520 = V_180 -> V_521 ;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_93 ( struct V_8 * V_9 , int V_508 , T_1 V_520 )
{
int V_41 = - V_155 ;
struct V_522 * V_166 ;
V_166 = F_18 ( V_523 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return - V_155 ;
V_166 -> V_520 = V_520 ;
V_166 -> V_524 = V_508 ? 1 : 0 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
static int F_94 ( struct V_8 * V_9 , struct V_500 * V_501 ,
T_1 V_502 , T_1 V_525 , T_1 V_526 , T_1 V_527 )
{
int V_41 = - V_155 ;
int V_161 ;
struct V_528 * V_166 ;
struct V_529 * V_180 ;
V_166 = F_18 ( V_530 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return - V_155 ;
V_166 -> V_531 =
V_502 | ( V_501 -> V_518 << V_532 ) ;
V_166 -> V_508 = V_501 -> V_508 ;
V_166 -> V_533 |= ( V_501 -> V_510 <<
V_534 ) ;
V_166 -> V_533 |= ( V_501 -> V_512 <<
V_535 ) ;
V_166 -> V_533 |= ( V_501 -> V_514 <<
V_536 ) ;
V_166 -> V_533 |= ( V_501 -> V_516 <<
V_537 ) ;
V_166 -> V_533 |= ( V_501 -> V_538 <<
V_539 ) ;
V_166 -> V_533 |= ( V_527 << V_540 ) ;
V_166 -> V_533 |= ( V_501 -> V_526 / V_541 ) ;
V_166 -> V_533 |= ( V_501 -> V_542 / V_541 ) <<
V_543 ;
V_166 -> V_544 = V_501 -> V_153 ;
V_166 -> V_545 = F_25 ( V_501 -> V_153 ) ;
V_166 -> V_546 = ( T_1 ) ( V_501 -> V_547 & 0xffffffff ) ;
V_166 -> V_548 = ( T_1 ) F_25 ( V_501 -> V_547 ) ;
V_166 -> V_549 = ( T_1 ) V_501 -> V_4 ;
V_166 -> V_550 = ( T_1 ) F_25 ( V_501 -> V_4 ) ;
for ( V_161 = 0 ; V_161 < V_525 ; V_161 ++ ) {
V_166 -> V_465 [ V_161 ] . V_162 = ( T_1 ) ( V_501 -> V_551 [ V_161 ] . V_187 & 0xffffffff ) ;
V_166 -> V_465 [ V_161 ] . V_163 = F_25 ( V_501 -> V_551 [ V_161 ] . V_187 ) ;
}
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_529 * ) V_166 ;
V_501 -> V_520 = V_180 -> V_521 ;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
static int F_95 ( struct V_8 * V_9 ,
struct V_500 * V_501 , T_1 V_525 ,
T_1 V_552 , T_1 V_527 )
{
int V_41 = - V_155 ;
int V_161 ;
struct V_553 * V_166 ;
V_166 = F_18 ( V_554 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return - V_155 ;
V_166 -> V_521 = V_501 -> V_520 ;
V_166 -> V_555 = ( V_525 << V_556 ) |
( V_552 & V_557 ) ;
V_166 -> V_527 = V_527 << V_558 ;
for ( V_161 = 0 ; V_161 < V_525 ; V_161 ++ ) {
V_166 -> V_465 [ V_161 ] . V_162 =
( T_1 ) ( V_501 -> V_551 [ V_161 + V_552 ] . V_187 & 0xffffffff ) ;
V_166 -> V_465 [ V_161 ] . V_163 =
F_25 ( V_501 -> V_551 [ V_161 + V_552 ] . V_187 ) ;
}
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_96 ( struct V_8 * V_9 ,
struct V_500 * V_501 , T_1 V_502 , int V_559 )
{
int V_41 ;
T_1 V_527 = 0 ;
T_1 V_560 , V_552 ;
T_1 V_561 = V_501 -> V_518 ;
V_552 = 0 ;
V_560 = F_97 ( V_561 , V_562 ) ;
if ( V_560 == V_561 )
V_527 = 1 ;
V_41 = F_94 ( V_9 , V_501 , V_502 ,
V_560 , V_501 -> V_526 , V_527 ) ;
if ( V_41 ) {
F_51 ( L_8 , V_284 , V_41 ) ;
return V_41 ;
}
if ( V_527 )
return 0 ;
while ( ! V_527 ) {
V_552 += V_560 ;
V_561 -= V_560 ;
V_560 = F_97 ( V_561 , V_562 ) ;
if ( V_560 == V_561 )
V_527 = 1 ;
V_41 = F_95 ( V_9 , V_501 , V_560 ,
V_552 , V_527 ) ;
if ( V_41 )
break;
}
if ( V_41 )
F_51 ( L_9 , V_284 , V_41 ) ;
return V_41 ;
}
bool F_98 ( struct V_238 * V_13 , struct V_233 * V_234 )
{
struct V_233 * V_563 ;
bool V_564 = false ;
F_61 (tmp, &cq->sq_head, sq_entry) {
if ( V_234 == V_563 ) {
V_564 = true ;
break;
}
}
return V_564 ;
}
bool F_99 ( struct V_238 * V_13 , struct V_233 * V_234 )
{
struct V_233 * V_563 ;
bool V_564 = false ;
F_61 (tmp, &cq->rq_head, rq_entry) {
if ( V_234 == V_563 ) {
V_564 = true ;
break;
}
}
return V_564 ;
}
void F_100 ( struct V_233 * V_234 )
{
bool V_564 ;
unsigned long V_311 ;
F_60 ( & V_234 -> V_9 -> V_313 , V_311 ) ;
V_564 = F_98 ( V_234 -> V_314 , V_234 ) ;
if ( ! V_564 )
F_101 ( & V_234 -> V_565 , & V_234 -> V_314 -> V_566 ) ;
if ( ! V_234 -> V_277 ) {
V_564 = F_99 ( V_234 -> V_315 , V_234 ) ;
if ( ! V_564 )
F_101 ( & V_234 -> V_567 , & V_234 -> V_315 -> V_568 ) ;
}
F_62 ( & V_234 -> V_9 -> V_313 , V_311 ) ;
}
static void F_102 ( struct V_233 * V_234 )
{
V_234 -> V_18 . V_19 = 0 ;
V_234 -> V_18 . V_5 = 0 ;
V_234 -> V_569 . V_19 = 0 ;
V_234 -> V_569 . V_5 = 0 ;
}
int F_49 ( struct V_233 * V_234 , enum V_23 V_570 ,
enum V_23 * V_571 )
{
unsigned long V_311 ;
int V_41 = 0 ;
enum V_24 V_572 ;
V_572 = F_10 ( V_570 ) ;
F_60 ( & V_234 -> V_573 , V_311 ) ;
if ( V_571 )
* V_571 = F_9 ( V_234 -> V_574 ) ;
if ( V_572 == V_234 -> V_574 ) {
F_62 ( & V_234 -> V_573 , V_311 ) ;
return 1 ;
}
if ( V_572 == V_28 ) {
F_102 ( V_234 ) ;
F_103 ( V_234 ) ;
} else if ( V_572 == V_39 ) {
F_100 ( V_234 ) ;
}
V_234 -> V_574 = V_572 ;
F_62 ( & V_234 -> V_573 , V_311 ) ;
return V_41 ;
}
static T_1 F_104 ( struct V_233 * V_234 )
{
T_1 V_311 = 0 ;
if ( V_234 -> V_575 & V_576 )
V_311 |= V_577 ;
if ( V_234 -> V_575 & V_578 )
V_311 |= V_579 ;
if ( V_234 -> V_575 & V_580 )
V_311 |= V_581 ;
if ( V_234 -> V_575 & V_582 )
V_311 |= V_583 ;
if ( V_234 -> V_575 & V_584 )
V_311 |= V_585 ;
return V_311 ;
}
static int F_105 ( struct V_586 * V_166 ,
struct V_587 * V_588 ,
struct V_233 * V_234 )
{
int V_41 ;
T_1 V_153 , V_484 , V_160 ;
T_4 V_187 ;
struct V_8 * V_9 = V_234 -> V_9 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
T_1 V_589 ;
T_1 V_590 = V_588 -> V_591 . V_343 ;
V_589 = F_106 ( int , V_588 -> V_591 . V_592 + 1 ,
V_9 -> V_333 . V_403 ) ;
V_41 = F_83 ( & V_589 ,
V_9 -> V_333 . V_386 , & V_484 , & V_160 ) ;
if ( V_41 ) {
F_51 ( L_10 , V_284 ,
V_589 ) ;
return - V_72 ;
}
V_234 -> V_18 . V_593 = V_589 ;
V_153 = ( V_484 * V_160 ) ;
V_234 -> V_18 . V_4 = F_23 ( & V_150 -> V_9 , V_153 , & V_187 , V_137 ) ;
if ( ! V_234 -> V_18 . V_4 )
return - V_72 ;
memset ( V_234 -> V_18 . V_4 , 0 , V_153 ) ;
V_234 -> V_18 . V_153 = V_153 ;
V_234 -> V_18 . V_187 = V_187 ;
V_234 -> V_18 . V_154 = V_9 -> V_333 . V_386 ;
F_24 ( & V_166 -> V_594 [ 0 ] , V_484 , V_187 , V_160 ) ;
V_166 -> V_595 |= ( F_107 ( V_160 / V_205 )
<< V_596 ) ;
V_166 -> V_597 |= ( V_484 <<
V_598 ) &
V_599 ;
V_166 -> V_600 |= ( V_590 <<
V_601 ) &
V_602 ;
V_166 -> V_600 |= ( V_590 <<
V_603 ) &
V_604 ;
V_166 -> V_605 |= ( F_107 ( V_234 -> V_18 . V_593 ) <<
V_606 ) &
V_607 ;
V_166 -> V_608 |= ( V_9 -> V_333 . V_386 <<
V_609 ) &
V_610 ;
return 0 ;
}
static int F_108 ( struct V_586 * V_166 ,
struct V_587 * V_588 ,
struct V_233 * V_234 )
{
int V_41 ;
T_1 V_153 , V_484 , V_160 ;
T_4 V_187 = 0 ;
struct V_8 * V_9 = V_234 -> V_9 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
T_1 V_611 = V_588 -> V_591 . V_612 + 1 ;
V_41 = F_83 ( & V_611 , V_9 -> V_333 . V_391 ,
& V_484 , & V_160 ) ;
if ( V_41 ) {
F_51 ( L_11 , V_284 ,
V_588 -> V_591 . V_612 + 1 ) ;
return V_41 ;
}
V_234 -> V_569 . V_593 = V_611 ;
V_153 = ( V_484 * V_160 ) ;
V_234 -> V_569 . V_4 = F_23 ( & V_150 -> V_9 , V_153 , & V_187 , V_137 ) ;
if ( ! V_234 -> V_569 . V_4 )
return - V_155 ;
memset ( V_234 -> V_569 . V_4 , 0 , V_153 ) ;
V_234 -> V_569 . V_187 = V_187 ;
V_234 -> V_569 . V_153 = V_153 ;
V_234 -> V_569 . V_154 = V_9 -> V_333 . V_391 ;
F_24 ( & V_166 -> V_613 [ 0 ] , V_484 , V_187 , V_160 ) ;
V_166 -> V_595 |= ( F_107 ( V_160 / V_205 ) <<
V_614 ) ;
V_166 -> V_597 |=
( V_484 << V_615 ) &
V_616 ;
V_166 -> V_617 |= ( V_588 -> V_591 . V_347 <<
V_618 ) &
V_619 ;
V_166 -> V_605 |= ( F_107 ( V_234 -> V_569 . V_593 ) <<
V_620 ) &
V_621 ;
V_166 -> V_608 |= ( V_9 -> V_333 . V_391 <<
V_622 ) &
V_623 ;
return 0 ;
}
static void F_109 ( struct V_586 * V_166 ,
struct V_424 * V_425 ,
struct V_233 * V_234 ,
T_2 V_624 , T_3 V_625 )
{
V_425 -> V_437 -- ;
V_234 -> V_429 = true ;
V_166 -> V_617 |= V_626 ;
if ( ! V_624 )
return;
V_166 -> V_617 |= V_626 ;
V_166 -> V_627 = V_625 ;
V_166 -> V_627 |= V_628 <<
V_629 ;
}
static int F_110 ( struct V_586 * V_166 ,
struct V_233 * V_234 )
{
struct V_8 * V_9 = V_234 -> V_9 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
T_4 V_187 = 0 ;
int V_400 = V_9 -> V_333 . V_400 ;
int V_630 = V_9 -> V_333 . V_401 * V_400 ;
struct V_395 * V_631 ;
int V_161 = 0 ;
if ( V_9 -> V_333 . V_399 == 0 )
return 0 ;
V_234 -> V_632 = F_23 ( & V_150 -> V_9 , V_630 ,
& V_187 , V_137 ) ;
if ( ! V_234 -> V_632 )
return - V_155 ;
memset ( V_234 -> V_632 , 0 , V_630 ) ;
F_24 ( & V_166 -> V_633 [ 0 ] , V_9 -> V_333 . V_401 ,
V_187 , V_400 ) ;
for (; V_161 < V_630 / V_9 -> V_333 . V_391 ; V_161 ++ ) {
V_631 = (struct V_395 * ) ( V_234 -> V_632 +
( V_161 * V_9 -> V_333 . V_391 ) ) ;
V_631 -> V_634 = 0 ;
V_631 -> V_634 |= 2 ;
V_631 -> V_634 |= ( V_635 << V_636 ) ;
V_631 -> V_634 |= ( 8 << V_637 ) ;
V_631 -> V_634 |= ( 8 << V_638 ) ;
}
return 0 ;
}
static void F_111 ( struct V_639 * V_180 ,
struct V_233 * V_234 ,
struct V_587 * V_588 ,
T_3 * V_640 , T_3 * V_641 )
{
T_1 V_589 , V_611 ;
V_234 -> V_112 = V_180 -> V_642 & V_643 ;
V_234 -> V_569 . V_644 = V_180 -> V_645 & V_646 ;
V_234 -> V_18 . V_644 = V_180 -> V_645 >> V_647 ;
V_234 -> V_648 = V_180 -> V_649 & V_650 ;
V_234 -> V_651 = ( V_180 -> V_649 >> V_652 ) ;
V_234 -> V_429 = false ;
if ( V_180 -> V_653 & V_654 ) {
V_234 -> V_429 = true ;
* V_641 = ( V_180 -> V_653 &
V_655 ) >>
V_656 ;
* V_640 = ( V_180 -> V_653 &
V_657 ) >>
V_658 ;
}
V_589 =
V_180 -> V_605 >> V_659 ;
V_589 = 1 << V_589 ;
V_611 = 1 << ( ( T_3 ) V_180 -> V_605 ) ;
V_234 -> V_18 . V_593 = V_589 ;
V_234 -> V_18 . V_660 = V_589 - 1 ;
if ( ! V_588 -> V_277 ) {
V_234 -> V_569 . V_593 = V_611 ;
V_234 -> V_569 . V_660 = V_611 - 1 ;
}
}
int F_112 ( struct V_233 * V_234 , struct V_587 * V_588 ,
T_2 V_624 , T_3 V_625 , T_3 * V_640 ,
T_3 * V_641 )
{
int V_41 = - V_155 ;
T_1 V_311 = 0 ;
struct V_8 * V_9 = V_234 -> V_9 ;
struct V_424 * V_425 = V_234 -> V_425 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
struct V_238 * V_13 ;
struct V_586 * V_166 ;
struct V_639 * V_180 ;
int V_661 ;
switch ( V_588 -> V_662 ) {
case V_663 :
V_661 = V_664 ;
break;
case V_665 :
V_661 = V_666 ;
break;
case V_667 :
V_661 = V_668 ;
break;
default:
return - V_72 ;
}
V_166 = F_18 ( V_669 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_595 |= ( V_661 << V_670 ) &
V_671 ;
V_41 = F_105 ( V_166 , V_588 , V_234 ) ;
if ( V_41 )
goto V_672;
if ( V_588 -> V_277 ) {
struct V_673 * V_277 = F_113 ( V_588 -> V_277 ) ;
V_166 -> V_617 |= V_674 ;
V_166 -> V_613 [ 0 ] . V_162 = V_277 -> V_112 ;
V_234 -> V_277 = V_277 ;
} else {
V_41 = F_108 ( V_166 , V_588 , V_234 ) ;
if ( V_41 )
goto V_675;
}
V_41 = F_110 ( V_166 , V_234 ) ;
if ( V_41 )
goto V_192;
V_166 -> V_595 |= ( V_425 -> V_112 << V_676 ) &
V_677 ;
V_311 = F_104 ( V_234 ) ;
V_166 -> V_617 |= V_311 ;
V_166 -> V_649 |= ( V_9 -> V_333 . V_355 <<
V_678 ) &
V_679 ;
V_166 -> V_649 |= ( V_9 -> V_333 . V_363 <<
V_680 ) &
V_681 ;
V_13 = F_114 ( V_588 -> V_682 ) ;
V_166 -> V_683 |= ( V_13 -> V_112 << V_684 ) &
V_685 ;
V_234 -> V_314 = V_13 ;
V_13 = F_114 ( V_588 -> V_686 ) ;
V_166 -> V_683 |= ( V_13 -> V_112 << V_687 ) &
V_688 ;
V_234 -> V_315 = V_13 ;
if ( V_425 -> V_429 && V_588 -> V_591 . V_394 && V_425 -> V_437 &&
( V_588 -> V_591 . V_394 <= V_9 -> V_333 . V_394 ) ) {
F_109 ( V_166 , V_425 , V_234 , V_624 ,
V_625 ) ;
}
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_639 * ) V_166 ;
F_111 ( V_180 , V_234 , V_588 , V_640 , V_641 ) ;
V_234 -> V_574 = V_26 ;
F_77 ( V_166 ) ;
return 0 ;
V_192:
if ( V_234 -> V_569 . V_4 )
F_21 ( & V_150 -> V_9 , V_234 -> V_569 . V_153 , V_234 -> V_569 . V_4 , V_234 -> V_569 . V_187 ) ;
V_675:
F_51 ( L_12 , V_284 , V_9 -> V_112 ) ;
F_21 ( & V_150 -> V_9 , V_234 -> V_18 . V_153 , V_234 -> V_18 . V_4 , V_234 -> V_18 . V_187 ) ;
V_672:
F_51 ( L_13 , V_284 , V_9 -> V_112 ) ;
F_77 ( V_166 ) ;
return V_41 ;
}
int F_115 ( struct V_8 * V_9 , struct V_233 * V_234 ,
struct V_689 * V_690 )
{
int V_41 = - V_155 ;
struct V_691 * V_166 ;
struct V_692 * V_180 ;
V_166 = F_18 ( V_693 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_642 = V_234 -> V_112 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_692 * ) V_166 ;
memcpy ( V_690 , & V_180 -> V_694 , sizeof( struct V_689 ) ) ;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_116 ( struct V_8 * V_9 , union V_695 * V_696 ,
T_2 * V_697 )
{
struct V_698 V_699 ;
memcpy ( & V_699 , V_696 , sizeof V_699 ) ;
if ( F_117 ( & V_699 ) ) {
F_118 ( & V_699 , V_697 ) ;
} else if ( F_119 ( & V_699 ) ) {
F_120 ( & V_699 , V_697 ) ;
} else {
F_51 ( L_14 , V_284 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_121 ( struct V_233 * V_234 ,
struct V_700 * V_166 ,
struct V_701 * V_588 )
{
int V_41 ;
struct V_702 * V_703 = & V_588 -> V_703 ;
union V_695 V_704 , V_705 ;
T_1 V_706 ;
T_2 V_697 [ 6 ] ;
if ( ( V_703 -> V_707 & V_708 ) == 0 )
return - V_72 ;
V_166 -> V_694 . V_709 |=
( V_703 -> V_710 . V_711 << V_712 ) ;
V_166 -> V_694 . V_713 |=
( V_703 -> V_710 . V_714 & V_715 ) ;
V_166 -> V_694 . V_713 |= ( V_703 -> V_716 << V_717 ) ;
V_166 -> V_694 . V_718 |=
( V_703 -> V_710 . V_719 << V_720 ) ;
V_166 -> V_311 |= V_721 ;
memcpy ( & V_166 -> V_694 . V_696 [ 0 ] , & V_703 -> V_710 . V_696 . V_722 [ 0 ] ,
sizeof( V_166 -> V_694 . V_696 ) ) ;
V_41 = F_122 ( & V_234 -> V_9 -> V_257 , 1 ,
V_703 -> V_710 . V_723 , & V_704 ) ;
if ( V_41 )
return V_41 ;
memset ( & V_705 , 0 , sizeof( V_705 ) ) ;
if ( ! memcmp ( & V_704 , & V_705 , sizeof( V_705 ) ) )
return - V_72 ;
V_234 -> V_724 = V_703 -> V_710 . V_723 ;
memcpy ( & V_166 -> V_694 . V_704 [ 0 ] , & V_704 . V_722 [ 0 ] , sizeof( V_166 -> V_694 . V_704 ) ) ;
F_116 ( V_234 -> V_9 , & V_703 -> V_710 . V_696 , & V_697 [ 0 ] ) ;
V_166 -> V_694 . V_725 = V_697 [ 0 ] | ( V_697 [ 1 ] << 8 ) |
( V_697 [ 2 ] << 16 ) | ( V_697 [ 3 ] << 24 ) ;
F_123 ( & V_166 -> V_694 . V_696 [ 0 ] , sizeof( V_166 -> V_694 . V_696 ) ) ;
F_123 ( & V_166 -> V_694 . V_704 [ 0 ] , sizeof( V_166 -> V_694 . V_704 ) ) ;
V_166 -> V_694 . V_726 = V_697 [ 4 ] | ( V_697 [ 5 ] << 8 ) ;
V_706 = F_124 ( & V_704 ) ;
if ( V_706 && ( V_706 < 0x1000 ) ) {
V_166 -> V_694 . V_726 |=
V_706 << V_727 ;
V_166 -> V_311 |= V_728 ;
}
return 0 ;
}
static int F_125 ( struct V_233 * V_234 ,
struct V_700 * V_166 ,
struct V_701 * V_588 , int V_729 ,
enum V_23 V_730 )
{
int V_41 = 0 ;
if ( V_729 & V_731 ) {
V_166 -> V_694 . V_732 |= ( V_588 -> V_733 &
V_734 ) ;
V_166 -> V_311 |= V_735 ;
}
if ( V_729 & V_736 ) {
V_234 -> V_737 = V_588 -> V_737 ;
V_166 -> V_694 . V_737 = V_588 -> V_737 ;
V_166 -> V_311 |= V_738 ;
}
if ( V_729 & V_739 ) {
V_41 = F_121 ( V_234 , V_166 , V_588 ) ;
if ( V_41 )
return V_41 ;
} else if ( V_234 -> V_662 == V_663 || V_234 -> V_662 == V_667 ) {
V_166 -> V_694 . V_725 = V_234 -> V_9 -> V_109 . V_697 [ 0 ] |
( V_234 -> V_9 -> V_109 . V_697 [ 1 ] << 8 ) |
( V_234 -> V_9 -> V_109 . V_697 [ 2 ] << 16 ) |
( V_234 -> V_9 -> V_109 . V_697 [ 3 ] << 24 ) ;
V_166 -> V_694 . V_726 = V_234 -> V_9 -> V_109 . V_697 [ 4 ] |
( V_234 -> V_9 -> V_109 . V_697 [ 5 ] << 8 ) ;
}
if ( ( V_729 & V_740 ) &&
V_588 -> V_741 ) {
V_166 -> V_694 . V_617 |=
V_742 ;
V_166 -> V_311 |= V_743 ;
}
if ( V_729 & V_744 ) {
V_166 -> V_694 . V_745 |= ( V_588 -> V_746 &
V_747 ) ;
V_166 -> V_311 |= V_743 ;
}
if ( V_729 & V_748 ) {
if ( V_588 -> V_749 < V_750 ||
V_588 -> V_749 > V_751 ) {
V_41 = - V_72 ;
goto V_752;
}
V_166 -> V_694 . V_732 |=
( F_126 ( V_588 -> V_749 ) <<
V_753 ) &
V_754 ;
V_166 -> V_311 |= V_755 ;
}
if ( V_729 & V_756 ) {
V_166 -> V_694 . V_745 |= V_588 -> V_135 <<
V_757 ;
V_166 -> V_311 |= V_758 ;
}
if ( V_729 & V_759 ) {
V_166 -> V_694 . V_713 |= ( V_588 -> V_760 <<
V_761 ) &
V_762 ;
V_166 -> V_311 |= V_763 ;
}
if ( V_729 & V_764 ) {
V_166 -> V_694 . V_713 |= ( V_588 -> V_765 <<
V_766 ) &
V_767 ;
V_166 -> V_311 |= V_768 ;
}
if ( V_729 & V_769 ) {
V_166 -> V_694 . V_745 |= ( V_588 -> V_770 <<
V_771 )
& V_772 ;
V_166 -> V_311 |= V_773 ;
}
if ( V_729 & V_774 ) {
V_166 -> V_694 . V_709 |= ( V_588 -> V_775 & 0x00ffffff ) ;
V_166 -> V_311 |= V_776 ;
}
if ( V_729 & V_777 ) {
V_166 -> V_694 . V_718 |= ( V_588 -> V_778 & 0x00ffffff ) ;
V_166 -> V_311 |= V_779 ;
}
if ( V_729 & V_780 ) {
if ( V_588 -> V_781 > V_234 -> V_9 -> V_333 . V_355 ) {
V_41 = - V_72 ;
goto V_752;
}
V_234 -> V_651 = V_588 -> V_781 ;
V_166 -> V_311 |= V_782 ;
}
if ( V_729 & V_783 ) {
if ( V_588 -> V_784 > V_234 -> V_9 -> V_333 . V_363 ) {
V_41 = - V_72 ;
goto V_752;
}
V_234 -> V_648 = V_588 -> V_784 ;
V_166 -> V_311 |= V_785 ;
}
V_166 -> V_694 . V_649 = ( V_234 -> V_651 <<
V_786 ) |
( V_234 -> V_648 & V_787 ) ;
V_752:
return V_41 ;
}
int F_127 ( struct V_8 * V_9 , struct V_233 * V_234 ,
struct V_701 * V_588 , int V_729 ,
enum V_23 V_730 )
{
int V_41 = - V_155 ;
struct V_700 * V_166 ;
V_166 = F_18 ( V_788 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_694 . V_112 = V_234 -> V_112 ;
V_166 -> V_311 = 0 ;
if ( V_729 & V_789 ) {
V_166 -> V_694 . V_617 |=
( F_10 ( V_588 -> V_790 ) <<
V_791 ) &
V_792 ;
V_166 -> V_311 |= V_793 ;
} else {
V_166 -> V_694 . V_617 |=
( V_234 -> V_574 << V_791 ) &
V_792 ;
}
V_41 = F_125 ( V_234 , V_166 , V_588 , V_729 , V_730 ) ;
if ( V_41 )
goto V_192;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_192:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_128 ( struct V_8 * V_9 , struct V_233 * V_234 )
{
int V_41 = - V_155 ;
struct V_794 * V_166 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
V_166 = F_18 ( V_795 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_642 = V_234 -> V_112 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_192:
F_77 ( V_166 ) ;
if ( V_234 -> V_18 . V_4 )
F_21 ( & V_150 -> V_9 , V_234 -> V_18 . V_153 , V_234 -> V_18 . V_4 , V_234 -> V_18 . V_187 ) ;
if ( ! V_234 -> V_277 && V_234 -> V_569 . V_4 )
F_21 ( & V_150 -> V_9 , V_234 -> V_569 . V_153 , V_234 -> V_569 . V_4 , V_234 -> V_569 . V_187 ) ;
if ( V_234 -> V_429 )
V_234 -> V_425 -> V_437 ++ ;
return V_41 ;
}
int F_129 ( struct V_8 * V_9 , struct V_673 * V_277 ,
struct V_796 * V_797 ,
struct V_424 * V_425 )
{
int V_41 = - V_155 ;
int V_484 , V_160 ;
int V_153 ;
struct V_798 * V_180 ;
struct V_799 * V_166 ;
T_4 V_187 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
T_1 V_611 ;
V_166 = F_18 ( V_800 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_801 = V_425 -> V_112 & V_802 ;
V_611 = V_797 -> V_333 . V_803 + 1 ;
V_41 = F_83 ( & V_611 ,
V_9 -> V_333 . V_391 ,
& V_484 , & V_160 ) ;
if ( V_41 ) {
F_51 ( L_15 , V_284 ,
V_797 -> V_333 . V_803 ) ;
V_41 = - V_72 ;
goto V_804;
}
V_153 = V_484 * V_160 ;
V_277 -> V_569 . V_4 = F_23 ( & V_150 -> V_9 , V_153 , & V_187 , V_137 ) ;
if ( ! V_277 -> V_569 . V_4 ) {
V_41 = - V_155 ;
goto V_804;
}
F_24 ( & V_166 -> V_613 [ 0 ] , V_484 , V_187 , V_160 ) ;
V_277 -> V_569 . V_154 = V_9 -> V_333 . V_391 ;
V_277 -> V_569 . V_187 = V_187 ;
V_277 -> V_569 . V_153 = V_153 ;
V_277 -> V_569 . V_593 = V_611 ;
V_166 -> V_805 = F_107 ( V_611 ) ;
V_166 -> V_805 |= V_797 -> V_333 . V_806 <<
V_807 ;
V_166 -> V_801 |= ( F_107 ( V_160 / V_205 )
<< V_808 ) ;
V_166 -> V_809 |= ( V_9 -> V_333 . V_391
<< V_810 )
& V_811 ;
V_166 -> V_809 |= V_484 << V_812 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 )
goto V_192;
V_180 = (struct V_798 * ) V_166 ;
V_277 -> V_112 = V_180 -> V_112 ;
V_277 -> V_569 . V_644 = V_180 -> V_112 ;
V_611 = ( ( V_180 -> V_813 &
V_814 ) >>
V_815 ) ;
V_611 = ( 1 << V_611 ) ;
V_277 -> V_569 . V_593 = V_611 ;
V_277 -> V_569 . V_660 = V_611 - 1 ;
V_277 -> V_569 . V_590 = ( V_180 -> V_813 &
V_816 ) >>
V_817 ;
goto V_804;
V_192:
F_21 ( & V_150 -> V_9 , V_277 -> V_569 . V_153 , V_277 -> V_569 . V_4 , V_187 ) ;
V_804:
F_77 ( V_166 ) ;
return V_41 ;
}
int F_130 ( struct V_673 * V_277 , struct V_818 * V_797 )
{
int V_41 = - V_155 ;
struct V_819 * V_166 ;
struct V_424 * V_425 = V_277 -> V_425 ;
struct V_8 * V_9 = F_131 ( V_425 -> V_820 . V_256 ) ;
V_166 = F_18 ( V_821 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_112 = V_277 -> V_112 ;
V_166 -> V_822 |= V_797 -> V_823 <<
V_824 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
F_77 ( V_166 ) ;
return V_41 ;
}
int F_132 ( struct V_673 * V_277 , struct V_818 * V_797 )
{
int V_41 = - V_155 ;
struct V_825 * V_166 ;
struct V_8 * V_9 = F_131 ( V_277 -> V_278 . V_256 ) ;
V_166 = F_18 ( V_826 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_112 = V_277 -> V_569 . V_644 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_41 == 0 ) {
struct V_827 * V_180 =
(struct V_827 * ) V_166 ;
V_797 -> V_806 =
V_180 -> V_828 &
V_829 ;
V_797 -> V_803 =
V_180 -> V_830 >> V_831 ;
V_797 -> V_823 = V_180 -> V_828 >>
V_832 ;
}
F_77 ( V_166 ) ;
return V_41 ;
}
int F_133 ( struct V_8 * V_9 , struct V_673 * V_277 )
{
int V_41 = - V_155 ;
struct V_833 * V_166 ;
struct V_449 * V_150 = V_9 -> V_109 . V_150 ;
V_166 = F_18 ( V_834 , sizeof( * V_166 ) ) ;
if ( ! V_166 )
return V_41 ;
V_166 -> V_112 = V_277 -> V_112 ;
V_41 = F_72 ( V_9 , (struct V_17 * ) V_166 ) ;
if ( V_277 -> V_569 . V_4 )
F_21 ( & V_150 -> V_9 , V_277 -> V_569 . V_153 ,
V_277 -> V_569 . V_4 , V_277 -> V_569 . V_187 ) ;
F_77 ( V_166 ) ;
return V_41 ;
}
int F_134 ( struct V_8 * V_9 , struct V_835 * V_836 )
{
int V_161 ;
int V_41 = - V_72 ;
struct V_455 * V_837 ;
unsigned long V_311 ;
V_837 = V_9 -> V_454 . V_4 ;
F_60 ( & V_9 -> V_454 . V_229 , V_311 ) ;
for ( V_161 = 0 ; V_161 < V_9 -> V_454 . V_468 ; V_161 ++ ) {
if ( V_837 -> V_184 == 0 ) {
V_837 -> V_184 = V_838 ;
V_836 -> V_837 = V_837 ;
V_836 -> V_112 = V_161 ;
V_41 = 0 ;
break;
}
V_837 ++ ;
}
if ( V_161 == V_9 -> V_454 . V_468 )
V_41 = - V_51 ;
F_62 ( & V_9 -> V_454 . V_229 , V_311 ) ;
return V_41 ;
}
int F_135 ( struct V_8 * V_9 , struct V_835 * V_836 )
{
unsigned long V_311 ;
F_60 ( & V_9 -> V_454 . V_229 , V_311 ) ;
V_836 -> V_837 -> V_184 = 0 ;
F_62 ( & V_9 -> V_454 . V_229 , V_311 ) ;
return 0 ;
}
static int F_136 ( struct V_8 * V_9 )
{
int V_839 , V_161 , V_41 = 0 ;
int V_193 ;
unsigned long V_311 = 0 ;
V_839 = V_9 -> V_109 . V_196 . V_840 -
V_9 -> V_109 . V_196 . V_841 ;
if ( V_9 -> V_109 . V_194 == V_195 ) {
V_839 = 1 ;
V_311 = V_842 ;
} else {
V_839 = F_106 ( T_1 , V_839 , F_137 () ) ;
}
if ( ! V_839 )
return - V_72 ;
V_9 -> V_199 = F_19 ( sizeof( struct V_1 ) * V_839 , V_137 ) ;
if ( ! V_9 -> V_199 )
return - V_155 ;
for ( V_161 = 0 ; V_161 < V_839 ; V_161 ++ ) {
V_41 = F_30 ( V_9 , & V_9 -> V_199 [ V_161 ] ,
V_7 ) ;
if ( V_41 ) {
V_41 = - V_72 ;
break;
}
sprintf ( V_9 -> V_199 [ V_161 ] . V_843 , L_16 ,
V_9 -> V_112 , V_161 ) ;
V_193 = F_31 ( V_9 , & V_9 -> V_199 [ V_161 ] ) ;
V_41 = F_138 ( V_193 , F_65 , V_311 ,
V_9 -> V_199 [ V_161 ] . V_843 ,
& V_9 -> V_199 [ V_161 ] ) ;
if ( V_41 )
goto V_844;
V_9 -> V_198 += 1 ;
}
return 0 ;
V_844:
F_35 ( V_9 ) ;
return V_41 ;
}
int F_139 ( struct V_8 * V_9 )
{
int V_41 ;
V_41 = F_136 ( V_9 ) ;
if ( V_41 )
goto V_845;
V_41 = F_42 ( V_9 ) ;
if ( V_41 )
goto V_846;
V_41 = F_78 ( V_9 ) ;
if ( V_41 )
goto V_847;
V_41 = F_79 ( V_9 ) ;
if ( V_41 )
goto V_847;
V_41 = F_76 ( V_9 ) ;
if ( V_41 )
goto V_847;
V_41 = F_86 ( V_9 ) ;
if ( V_41 )
goto V_847;
return 0 ;
V_847:
F_45 ( V_9 ) ;
V_846:
F_35 ( V_9 ) ;
V_845:
F_51 ( L_8 , V_284 , V_41 ) ;
return V_41 ;
}
void F_140 ( struct V_8 * V_9 )
{
F_87 ( V_9 ) ;
F_35 ( V_9 ) ;
F_45 ( V_9 ) ;
}
