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
}
static inline void * F_8 ( struct V_9 * V_10 )
{
return ( void * ) ( ( V_3 * ) V_10 -> V_13 . V_19 . V_5 +
( V_10 -> V_22 . V_23 * sizeof( struct V_18 ) ) ) ;
}
enum V_24 F_9 ( enum V_25 V_26 )
{
switch ( V_26 ) {
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
case V_40 :
return V_41 ;
} ;
return V_41 ;
}
static enum V_25 F_10 ( enum V_24 V_26 )
{
switch ( V_26 ) {
case V_28 :
return V_27 ;
case V_30 :
return V_29 ;
case V_32 :
return V_31 ;
case V_34 :
return V_33 ;
case V_37 :
return V_35 ;
case V_39 :
return V_38 ;
case V_41 :
return V_40 ;
} ;
return V_40 ;
}
static int F_11 ( T_1 V_42 )
{
int V_43 = - V_44 ;
V_3 V_45 = ( V_42 & V_46 ) >>
V_47 ;
V_3 V_48 = ( V_42 & V_49 ) >>
V_50 ;
switch ( V_45 ) {
case V_51 :
case V_52 :
V_43 = - V_53 ;
break;
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
case V_72 :
case V_73 :
V_43 = - V_74 ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
V_43 = - V_79 ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_43 = - V_89 ;
break;
case V_90 :
switch ( V_48 ) {
case V_91 :
V_43 = - V_53 ;
break;
}
default:
V_43 = - V_44 ;
}
return V_43 ;
}
static int F_12 ( T_2 V_92 )
{
int V_43 = - V_74 ;
switch ( V_92 ) {
case V_93 :
V_43 = - V_94 ;
break;
case V_95 :
V_43 = - V_74 ;
break;
case V_96 :
case V_97 :
V_43 = - V_53 ;
break;
case V_98 :
V_43 = - V_99 ;
break;
}
return V_43 ;
}
void F_13 ( struct V_9 * V_10 , T_2 V_100 , bool V_101 ,
bool V_102 , T_2 V_103 )
{
T_1 V_104 = V_100 & V_105 ;
V_104 |= ( ( V_100 & V_106 ) <<
V_107 ) ;
if ( V_101 )
V_104 |= ( 1 << V_108 ) ;
if ( V_102 )
V_104 |= ( 1 << V_109 ) ;
V_104 |= ( V_103 << V_110 ) ;
F_14 ( V_104 , V_10 -> V_111 . V_112 + V_113 ) ;
}
static void F_15 ( struct V_9 * V_10 )
{
T_1 V_104 = 0 ;
V_104 |= V_10 -> V_13 . V_19 . V_114 & V_115 ;
V_104 |= 1 << V_116 ;
F_14 ( V_104 , V_10 -> V_111 . V_112 + V_117 ) ;
}
static void F_16 ( struct V_9 * V_10 , T_2 V_118 ,
bool V_119 , bool V_120 , T_2 V_121 )
{
T_1 V_104 = 0 ;
V_104 |= V_118 & V_122 ;
V_104 |= ( ( V_118 & V_123 ) << V_124 ) ;
if ( V_119 )
V_104 |= ( 1 << V_125 ) ;
if ( V_120 )
V_104 |= ( 1 << V_126 ) ;
V_104 |= ( 1 << V_127 ) ;
V_104 |= ( V_121 << V_128 ) ;
F_14 ( V_104 , V_10 -> V_111 . V_112 + V_129 ) ;
}
static void F_17 ( struct V_130 * V_131 ,
V_3 V_132 , V_3 V_133 , T_1 V_134 )
{
V_131 -> V_135 = ( V_132 | ( V_133 << V_136 ) ) ;
V_131 -> V_137 = 20 ;
V_131 -> V_134 = V_134 - sizeof( struct V_130 ) ;
}
static void * F_18 ( V_3 V_132 , T_1 V_134 )
{
struct V_18 * V_138 ;
V_138 = F_19 ( sizeof( struct V_18 ) , V_139 ) ;
if ( ! V_138 )
return NULL ;
V_138 -> V_140 . V_141 |=
( V_142 << V_143 ) &
V_144 ;
V_138 -> V_140 . V_145 = V_134 - sizeof( struct V_146 ) ;
F_17 ( & V_138 -> V_147 . V_148 . V_149 , V_132 , V_150 ,
V_138 -> V_140 . V_145 ) ;
return V_138 ;
}
static void F_20 ( struct V_9 * V_10 , struct V_151 * V_4 )
{
F_21 ( & V_10 -> V_111 . V_152 -> V_10 , V_4 -> V_153 , V_4 -> V_5 , V_4 -> V_154 ) ;
}
static int F_22 ( struct V_9 * V_10 ,
struct V_151 * V_4 , T_2 V_155 , T_2 V_156 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_155 = V_155 ;
V_4 -> V_156 = V_156 ;
V_4 -> V_153 = V_155 * V_156 ;
V_4 -> V_5 = F_23 ( & V_10 -> V_111 . V_152 -> V_10 , V_4 -> V_153 ,
& V_4 -> V_154 , V_139 ) ;
if ( ! V_4 -> V_5 )
return - V_157 ;
memset ( V_4 -> V_5 , 0 , V_4 -> V_153 ) ;
return 0 ;
}
static void F_24 ( struct V_158 * V_159 , int V_160 ,
T_3 V_161 , int V_162 )
{
int V_163 ;
for ( V_163 = 0 ; V_163 < V_160 ; V_163 ++ ) {
V_159 [ V_163 ] . V_164 = ( T_1 ) ( V_161 & 0xffffffff ) ;
V_159 [ V_163 ] . V_165 = ( T_1 ) F_25 ( V_161 ) ;
V_161 += V_162 ;
}
}
static void F_26 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
V_2 -> V_166 = V_10 -> V_111 . V_167 . V_168 ;
V_10 -> V_111 . V_167 . V_168 += 1 ;
}
static void F_27 ( struct V_9 * V_10 )
{
V_10 -> V_111 . V_167 . V_168 -= 1 ;
}
static int F_28 ( struct V_9 * V_10 , struct V_151 * V_4 ,
int V_169 )
{
V_3 V_132 = 0 ;
int V_42 ;
struct V_170 * V_171 = V_10 -> V_172 ;
switch ( V_169 ) {
case V_173 :
V_132 = V_174 ;
break;
case V_175 :
V_132 = V_176 ;
break;
case V_177 :
V_132 = V_178 ;
break;
default:
F_29 () ;
}
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
F_17 ( & V_171 -> V_179 , V_132 , V_180 , sizeof( * V_171 ) ) ;
V_171 -> V_114 = V_4 -> V_114 ;
V_42 = F_30 ( V_10 -> V_111 . V_181 ,
V_171 , sizeof( * V_171 ) , NULL , NULL ) ;
if ( ! V_42 )
V_4 -> V_182 = false ;
return V_42 ;
}
static int F_31 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
int V_42 ;
struct V_183 * V_171 = V_10 -> V_172 ;
struct V_184 * V_185 = V_10 -> V_172 ;
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
F_17 ( & V_171 -> V_179 , V_186 , V_180 ,
sizeof( * V_171 ) ) ;
if ( V_10 -> V_111 . V_187 == V_188 )
V_171 -> V_179 . V_189 = 0 ;
else
V_171 -> V_179 . V_189 = 2 ;
V_171 -> V_190 = 4 ;
V_171 -> V_191 = V_192 ;
V_171 -> V_160 = 4 << V_193 ;
F_24 ( & V_171 -> V_194 [ 0 ] , V_171 -> V_190 , V_2 -> V_4 . V_154 ,
V_195 ) ;
V_42 = F_30 ( V_10 -> V_111 . V_181 , V_171 , sizeof( * V_171 ) , NULL ,
NULL ) ;
if ( ! V_42 ) {
V_2 -> V_4 . V_114 = V_185 -> V_196 & 0xffff ;
if ( V_10 -> V_111 . V_187 == V_188 )
F_26 ( V_10 , V_2 ) ;
else {
V_2 -> V_166 = ( V_185 -> V_196 >> 16 ) & 0xffff ;
V_10 -> V_111 . V_167 . V_168 += 1 ;
}
V_2 -> V_4 . V_182 = true ;
}
return V_42 ;
}
static int F_32 ( struct V_9 * V_10 ,
struct V_1 * V_2 , T_2 V_197 )
{
int V_42 ;
V_42 = F_22 ( V_10 , & V_2 -> V_4 , V_8 ,
sizeof( struct V_7 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_31 ( V_10 , V_2 ) ;
if ( V_42 )
goto V_198;
V_2 -> V_10 = V_10 ;
F_16 ( V_10 , V_2 -> V_4 . V_114 , true , true , 0 ) ;
return 0 ;
V_198:
F_20 ( V_10 , & V_2 -> V_4 ) ;
return V_42 ;
}
static int F_33 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
int V_199 ;
if ( V_10 -> V_111 . V_200 == V_201 )
V_199 = V_10 -> V_111 . V_152 -> V_199 ;
else
V_199 = V_10 -> V_111 . V_167 . V_202 [ V_2 -> V_166 ] ;
return V_199 ;
}
static void F_34 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_182 ) {
F_28 ( V_10 , & V_2 -> V_4 , V_177 ) ;
if ( V_10 -> V_111 . V_187 == V_188 )
F_27 ( V_10 ) ;
F_20 ( V_10 , & V_2 -> V_4 ) ;
}
}
static void F_35 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
int V_199 ;
F_16 ( V_10 , V_2 -> V_4 . V_114 , false , false , 0 ) ;
V_199 = F_33 ( V_10 , V_2 ) ;
F_36 ( V_199 , V_2 ) ;
F_34 ( V_10 , V_2 ) ;
}
static void F_37 ( struct V_9 * V_10 )
{
int V_163 ;
for ( V_163 = 0 ; V_163 < V_10 -> V_203 ; V_163 ++ )
F_35 ( V_10 , & V_10 -> V_204 [ V_163 ] ) ;
}
static int F_38 ( struct V_9 * V_10 ,
struct V_151 * V_14 ,
struct V_151 * V_2 )
{
struct V_205 * V_171 = V_10 -> V_172 ;
struct V_206 * V_185 = V_10 -> V_172 ;
int V_42 ;
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
F_17 ( & V_171 -> V_179 , V_207 ,
V_180 , sizeof( * V_171 ) ) ;
V_171 -> V_208 = F_39 ( V_14 -> V_5 , V_14 -> V_153 ) ;
V_171 -> V_209 = V_210 ;
V_171 -> V_211 = ( V_2 -> V_114 << V_212 ) ;
F_24 ( & V_171 -> V_194 [ 0 ] , V_171 -> V_208 ,
V_14 -> V_154 , V_195 ) ;
V_42 = F_30 ( V_10 -> V_111 . V_181 ,
V_171 , sizeof( * V_171 ) , NULL , NULL ) ;
if ( ! V_42 ) {
V_14 -> V_114 = ( V_185 -> V_100 & V_213 ) ;
V_14 -> V_182 = true ;
}
return V_42 ;
}
static T_1 F_40 ( int V_197 )
{
T_1 V_214 = F_41 ( V_197 ) ;
if ( V_214 == 16 )
V_214 = 0 ;
return V_214 ;
}
static int F_42 ( struct V_9 * V_10 ,
struct V_151 * V_13 ,
struct V_151 * V_14 )
{
int V_190 , V_42 ;
struct V_215 * V_171 = V_10 -> V_172 ;
struct V_216 * V_185 = V_10 -> V_172 ;
struct V_158 * V_194 ;
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
V_190 = F_39 ( V_13 -> V_5 , V_13 -> V_153 ) ;
F_17 ( & V_171 -> V_179 , V_217 ,
V_180 , sizeof( * V_171 ) ) ;
V_171 -> V_179 . V_189 = 1 ;
V_171 -> V_218 = V_190 ;
V_171 -> V_218 |= ( V_14 -> V_114 << V_219 ) ;
V_171 -> V_220 = V_221 ;
V_171 -> V_222 = F_43 ( 20 ) ;
V_171 -> V_223 = V_14 -> V_114 ;
V_171 -> V_223 |= ( F_40 ( V_13 -> V_155 ) <<
V_224 ) ;
V_171 -> V_191 = V_225 ;
V_194 = & V_171 -> V_194 [ 0 ] ;
F_24 ( V_194 , V_190 , V_13 -> V_154 , V_195 ) ;
V_42 = F_30 ( V_10 -> V_111 . V_181 ,
V_171 , sizeof( * V_171 ) , NULL , NULL ) ;
if ( ! V_42 ) {
V_13 -> V_114 = V_185 -> V_114 ;
V_13 -> V_182 = true ;
}
return V_42 ;
}
static int F_44 ( struct V_9 * V_10 )
{
int V_42 ;
V_42 = F_22 ( V_10 , & V_10 -> V_13 . V_14 , V_17 ,
sizeof( struct V_11 ) ) ;
if ( V_42 )
goto V_226;
V_42 = F_38 ( V_10 , & V_10 -> V_13 . V_14 , & V_10 -> V_227 . V_4 ) ;
if ( V_42 )
goto V_228;
memset ( & V_10 -> V_22 , 0 , sizeof( V_10 -> V_22 ) ) ;
F_45 ( & V_10 -> V_22 . V_229 ) ;
F_46 ( & V_10 -> V_22 . V_230 ) ;
V_42 = F_22 ( V_10 , & V_10 -> V_13 . V_19 , V_21 ,
sizeof( struct V_18 ) ) ;
if ( V_42 )
goto V_231;
V_42 = F_42 ( V_10 , & V_10 -> V_13 . V_19 , & V_10 -> V_13 . V_14 ) ;
if ( V_42 )
goto V_232;
F_13 ( V_10 , V_10 -> V_13 . V_14 . V_114 , true , false , 0 ) ;
return 0 ;
V_232:
F_20 ( V_10 , & V_10 -> V_13 . V_19 ) ;
V_231:
F_28 ( V_10 , & V_10 -> V_13 . V_14 , V_175 ) ;
V_228:
F_20 ( V_10 , & V_10 -> V_13 . V_14 ) ;
V_226:
return V_42 ;
}
static void F_47 ( struct V_9 * V_10 )
{
struct V_151 * V_233 , * V_14 ;
F_48 ( & V_10 -> V_22 . V_230 ) ;
V_233 = & V_10 -> V_13 . V_19 ;
if ( V_233 -> V_182 ) {
F_28 ( V_10 , V_233 , V_173 ) ;
F_20 ( V_10 , V_233 ) ;
}
F_49 ( & V_10 -> V_22 . V_230 ) ;
V_14 = & V_10 -> V_13 . V_14 ;
if ( V_14 -> V_182 ) {
F_28 ( V_10 , V_14 , V_175 ) ;
F_20 ( V_10 , V_14 ) ;
}
}
static void F_50 ( struct V_9 * V_10 ,
struct V_234 * V_235 )
{
enum V_24 V_236 = V_41 ;
enum V_24 V_237 ;
if ( V_235 == NULL )
F_29 () ;
F_51 ( V_235 , V_236 , & V_237 ) ;
}
static void F_52 ( struct V_9 * V_10 ,
struct V_238 * V_12 )
{
struct V_234 * V_235 = NULL ;
struct V_239 * V_14 = NULL ;
struct V_240 V_241 ;
int V_242 = 0 ;
int V_243 = 1 ;
int V_244 = 0 ;
int V_245 = 0 ;
int type = ( V_12 -> V_246 & V_247 ) >>
V_248 ;
if ( V_12 -> V_249 & V_250 )
V_235 = V_10 -> V_251 [ V_12 -> V_249 & V_252 ] ;
if ( V_12 -> V_253 & V_254 )
V_14 = V_10 -> V_255 [ V_12 -> V_253 & V_256 ] ;
V_241 . V_257 = & V_10 -> V_258 ;
switch ( type ) {
case V_259 :
V_241 . V_260 . V_14 = & V_14 -> V_261 ;
V_241 . V_262 = V_263 ;
V_242 = 1 ;
V_243 = 0 ;
break;
case V_264 :
V_241 . V_260 . V_14 = & V_14 -> V_261 ;
V_241 . V_262 = V_263 ;
break;
case V_265 :
V_241 . V_260 . V_235 = & V_235 -> V_266 ;
V_241 . V_262 = V_267 ;
F_50 ( V_10 , V_235 ) ;
break;
case V_268 :
V_241 . V_260 . V_235 = & V_235 -> V_266 ;
V_241 . V_262 = V_269 ;
break;
case V_270 :
V_241 . V_260 . V_235 = & V_235 -> V_266 ;
V_241 . V_262 = V_271 ;
break;
case V_272 :
V_241 . V_260 . V_235 = & V_235 -> V_266 ;
V_241 . V_262 = V_273 ;
break;
case V_274 :
V_241 . V_260 . V_275 = 1 ;
V_241 . V_262 = V_276 ;
V_243 = 0 ;
V_245 = 1 ;
break;
case V_277 :
V_241 . V_260 . V_278 = & V_235 -> V_278 -> V_279 ;
V_241 . V_262 = V_280 ;
V_244 = 1 ;
V_243 = 0 ;
break;
case V_281 :
V_241 . V_260 . V_278 = & V_235 -> V_278 -> V_279 ;
V_241 . V_262 = V_282 ;
V_244 = 1 ;
V_243 = 0 ;
break;
case V_283 :
V_241 . V_260 . V_235 = & V_235 -> V_266 ;
V_241 . V_262 = V_284 ;
break;
default:
V_242 = 0 ;
V_243 = 0 ;
V_244 = 0 ;
V_245 = 0 ;
F_53 ( L_1 , V_285 , type ) ;
break;
}
if ( V_243 ) {
if ( V_235 -> V_266 . V_286 )
V_235 -> V_266 . V_286 ( & V_241 , V_235 -> V_266 . V_287 ) ;
} else if ( V_242 ) {
if ( V_14 -> V_261 . V_286 )
V_14 -> V_261 . V_286 ( & V_241 , V_14 -> V_261 . V_288 ) ;
} else if ( V_244 ) {
if ( V_235 -> V_278 -> V_279 . V_286 )
V_235 -> V_278 -> V_279 . V_286 ( & V_241 ,
V_235 -> V_278 -> V_279 .
V_289 ) ;
} else if ( V_245 )
F_54 ( & V_241 ) ;
}
static void F_55 ( struct V_9 * V_10 , void * V_290 )
{
struct V_238 * V_12 = V_290 ;
T_1 V_291 = ( V_12 -> V_246 & V_292 ) >>
V_293 ;
if ( V_291 == V_294 )
F_52 ( V_10 , V_12 ) ;
else
F_53 ( L_2 , V_285 ,
V_10 -> V_114 , V_291 ) ;
}
static void F_56 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
if ( V_10 -> V_22 . V_23 == V_12 -> V_295 && V_10 -> V_22 . V_296 == false ) {
V_10 -> V_22 . V_92 = ( V_12 -> V_42 &
V_297 ) >> V_298 ;
V_10 -> V_22 . V_299 =
( V_12 -> V_42 & V_300 )
>> V_301 ;
V_10 -> V_22 . V_296 = true ;
F_57 ( & V_10 -> V_22 . V_229 ) ;
} else
F_53 ( L_3 ,
V_285 , V_12 -> V_295 , V_10 -> V_22 . V_23 ) ;
}
static int F_58 ( struct V_9 * V_10 , T_2 V_100 )
{
T_2 V_103 = 0 ;
struct V_11 * V_12 ;
while ( 1 ) {
V_12 = F_3 ( V_10 ) ;
if ( V_12 == NULL )
break;
F_59 ( V_12 , sizeof( * V_12 ) ) ;
V_103 += 1 ;
if ( V_12 -> V_15 & V_302 )
F_55 ( V_10 , V_12 ) ;
else if ( V_12 -> V_15 & V_303 )
F_56 ( V_10 , V_12 ) ;
else
F_53 ( L_4 , V_285 ) ;
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
F_5 ( V_10 ) ;
}
F_13 ( V_10 , V_10 -> V_13 . V_14 . V_114 , true , false , V_103 ) ;
return 0 ;
}
static void F_60 ( struct V_9 * V_10 ,
struct V_239 * V_14 )
{
unsigned long V_304 ;
struct V_234 * V_235 ;
bool V_305 = false ;
F_61 ( & V_10 -> V_306 , V_304 ) ;
F_62 (qp, &cq->sq_head, sq_entry) {
if ( V_235 -> V_278 )
continue;
if ( V_235 -> V_307 == V_235 -> V_308 )
continue;
if ( V_235 -> V_307 == V_14 )
V_14 = V_235 -> V_308 ;
else
V_14 = V_235 -> V_307 ;
V_305 = true ;
break;
}
F_63 ( & V_10 -> V_306 , V_304 ) ;
if ( V_305 == false )
return;
if ( V_14 -> V_261 . V_309 ) {
F_61 ( & V_14 -> V_310 , V_304 ) ;
(* V_14 -> V_261 . V_309 ) ( & V_14 -> V_261 , V_14 -> V_261 . V_288 ) ;
F_63 ( & V_14 -> V_310 , V_304 ) ;
}
}
static void F_64 ( struct V_9 * V_10 , T_2 V_311 )
{
unsigned long V_304 ;
struct V_239 * V_14 ;
if ( V_311 >= V_312 )
F_29 () ;
V_14 = V_10 -> V_255 [ V_311 ] ;
if ( V_14 == NULL ) {
F_53 ( L_5 , V_285 , V_10 -> V_114 , V_311 ) ;
return;
}
F_61 ( & V_14 -> V_313 , V_304 ) ;
V_14 -> V_101 = false ;
V_14 -> V_102 = false ;
F_63 ( & V_14 -> V_313 , V_304 ) ;
F_13 ( V_10 , V_14 -> V_114 , false , false , 0 ) ;
if ( V_14 -> V_261 . V_309 ) {
F_61 ( & V_14 -> V_310 , V_304 ) ;
(* V_14 -> V_261 . V_309 ) ( & V_14 -> V_261 , V_14 -> V_261 . V_288 ) ;
F_63 ( & V_14 -> V_310 , V_304 ) ;
}
F_60 ( V_10 , V_14 ) ;
}
static void F_65 ( struct V_9 * V_10 , T_2 V_100 )
{
if ( V_100 == V_10 -> V_13 . V_14 . V_114 )
F_58 ( V_10 , V_100 ) ;
else
F_64 ( V_10 , V_100 ) ;
}
static T_4 F_66 ( int V_199 , void * V_314 )
{
struct V_1 * V_2 = V_314 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_7 V_315 ;
struct V_7 * V_316 ;
T_2 V_317 = 0 ;
T_2 V_100 ;
while ( 1 ) {
V_316 = F_1 ( V_2 ) ;
V_315 = * V_316 ;
F_59 ( & V_315 , sizeof( V_315 ) ) ;
if ( ( V_315 . V_318 & V_319 ) == 0 )
break;
V_317 += 1 ;
V_316 -> V_318 = 0 ;
if ( ( V_315 . V_318 & V_320 ) == 0 ) {
V_100 = V_315 . V_318 >> V_321 ;
F_65 ( V_10 , V_100 ) ;
}
F_2 ( V_2 ) ;
}
F_16 ( V_10 , V_2 -> V_4 . V_114 , true , true , V_317 ) ;
if ( V_10 -> V_111 . V_200 == V_201 )
F_16 ( V_10 , V_2 -> V_4 . V_114 , true , true , 0 ) ;
return V_322 ;
}
static void F_67 ( struct V_9 * V_10 , struct V_18 * V_171 )
{
struct V_18 * V_138 ;
V_10 -> V_22 . V_23 = V_10 -> V_13 . V_19 . V_20 ;
V_10 -> V_22 . V_296 = false ;
V_138 = F_6 ( V_10 ) ;
V_171 -> V_140 . V_295 = V_10 -> V_13 . V_19 . V_20 ;
F_68 ( V_138 , V_171 , sizeof( * V_138 ) ) ;
F_69 () ;
F_7 ( V_10 ) ;
F_15 ( V_10 ) ;
}
static int F_70 ( struct V_9 * V_10 )
{
long V_42 ;
V_42 = F_71 ( V_10 -> V_22 . V_229 ,
( V_10 -> V_22 . V_296 != false ) ,
F_72 ( 30000 ) ) ;
if ( V_42 )
return 0 ;
else
return - 1 ;
}
static int F_73 ( struct V_9 * V_10 , struct V_18 * V_138 )
{
int V_42 = 0 ;
T_2 V_92 , V_299 ;
struct V_18 * V_185 ;
F_48 ( & V_10 -> V_22 . V_230 ) ;
F_67 ( V_10 , V_138 ) ;
V_42 = F_70 ( V_10 ) ;
if ( V_42 )
goto V_198;
V_92 = V_10 -> V_22 . V_92 ;
V_299 = V_10 -> V_22 . V_299 ;
V_185 = F_8 ( V_10 ) ;
F_74 ( V_138 , V_185 , ( sizeof( * V_138 ) ) ) ;
if ( V_92 || V_299 ) {
F_53
( L_6 ,
V_285 ,
( V_185 -> V_147 . V_185 . V_135 & V_323 ) >>
V_324 , V_92 , V_299 ) ;
V_42 = F_12 ( V_92 ) ;
goto V_198;
}
if ( V_138 -> V_147 . V_185 . V_42 & V_46 )
V_42 = F_11 ( V_138 -> V_147 . V_185 . V_42 ) ;
V_198:
F_49 ( & V_10 -> V_22 . V_230 ) ;
return V_42 ;
}
static void F_75 ( struct V_9 * V_10 ,
struct V_325 * V_326 ,
struct V_327 * V_185 )
{
V_326 -> V_328 =
( V_185 -> V_329 & V_330 ) >>
V_331 ;
V_326 -> V_332 =
( V_185 -> V_333 & V_334 ) >>
V_335 ;
V_326 -> V_336 = ( ( V_185 -> V_337 &
V_338 ) >>
V_339 ) ;
V_326 -> V_340 = ( V_185 -> V_337 &
V_338 ) >>
V_339 ;
V_326 -> V_341 = ( V_185 -> V_342 &
V_343 ) >>
V_344 ;
V_326 -> V_345 = ( V_185 -> V_346 &
V_347 ) >>
V_348 ;
V_326 -> V_349 = ( V_185 -> V_346 &
V_350 ) >>
V_351 ;
V_326 -> V_352 = ( V_185 -> V_333 &
V_353 ) >>
V_354 ;
V_326 -> V_355 = ( V_185 -> V_333 &
V_356 ) >>
V_357 ;
V_326 -> V_358 = ( V_185 -> V_329 &
V_359 ) >>
V_360 ;
V_326 -> V_361 = V_185 -> V_361 ;
V_326 -> V_362 = ~ 0ull ;
V_326 -> V_363 = 0 ;
V_326 -> V_364 = V_185 -> V_364 ;
V_326 -> V_365 = V_185 -> V_365 ;
V_326 -> V_366 = V_185 -> V_367 &
V_368 ;
V_326 -> V_369 = ( ( V_185 -> V_370 &
V_371 ) >>
V_372 ) *
V_373 ;
V_326 -> V_374 = ( ( V_185 -> V_370 &
V_375 ) >>
V_376 ) *
V_373 ;
V_326 -> V_377 =
V_326 -> V_369 - ( sizeof( struct V_378 ) +
sizeof( struct V_379 ) ) ;
if ( V_10 -> V_111 . V_187 == V_188 ) {
V_326 -> V_380 = 1 ;
V_326 -> V_381 = V_382 ;
V_326 -> V_383 = V_384 ;
}
V_10 -> V_326 . V_385 = V_185 -> V_386 >>
V_387 ;
V_10 -> V_326 . V_388 = V_185 -> V_386 &
V_389 ;
}
static int F_76 ( struct V_9 * V_10 ,
struct V_390 * V_391 )
{
T_1 V_392 ;
V_392 = V_391 -> V_392 & V_393 ;
if ( V_392 != V_393 )
return - V_74 ;
V_10 -> V_394 = V_391 -> V_394 ;
V_10 -> V_395 = V_391 -> V_395 ;
V_10 -> V_326 . V_396 = V_312 - 1 ;
return 0 ;
}
static int F_77 ( struct V_9 * V_10 )
{
int V_42 = - V_157 ;
struct V_18 * V_171 ;
struct V_397 * V_185 ;
V_171 = F_18 ( V_398 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return - V_157 ;
F_17 ( (struct V_130 * ) & V_171 -> V_147 . V_171 [ 0 ] ,
V_398 ,
V_180 , sizeof( * V_171 ) ) ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_397 * ) V_171 ;
memset ( & V_10 -> V_326 . V_399 [ 0 ] , 0 , sizeof( V_10 -> V_326 . V_399 ) ) ;
memcpy ( & V_10 -> V_326 . V_399 [ 0 ] , & V_185 -> V_400 [ 0 ] ,
sizeof( V_185 -> V_400 ) ) ;
F_59 ( V_10 -> V_326 . V_399 , sizeof( V_185 -> V_400 ) ) ;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
static int F_79 ( struct V_9 * V_10 )
{
int V_42 = - V_157 ;
struct V_18 * V_171 ;
struct V_390 * V_185 ;
V_171 = F_18 ( V_401 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return - V_157 ;
F_17 ( (struct V_130 * ) & V_171 -> V_147 . V_171 [ 0 ] ,
V_401 ,
V_180 , sizeof( * V_171 ) ) ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_390 * ) V_171 ;
V_42 = F_76 ( V_10 , V_185 ) ;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
static int F_80 ( struct V_9 * V_10 )
{
int V_42 = - V_157 ;
struct V_327 * V_185 ;
struct V_18 * V_171 ;
V_171 = F_18 ( V_402 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_327 * ) V_171 ;
F_75 ( V_10 , & V_10 -> V_326 , V_185 ) ;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_81 ( struct V_9 * V_10 , struct V_403 * V_404 )
{
int V_42 = - V_157 ;
struct V_405 * V_171 ;
struct V_406 * V_185 ;
V_171 = F_18 ( V_407 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
if ( V_404 -> V_408 )
V_171 -> V_409 |= V_410 ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_406 * ) V_171 ;
V_404 -> V_114 = V_185 -> V_411 & V_412 ;
if ( V_185 -> V_411 & V_413 ) {
V_404 -> V_408 = true ;
V_404 -> V_414 = V_185 -> V_411 >>
V_415 ;
} else {
V_404 -> V_408 = false ;
V_404 -> V_416 = 0 ;
}
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_82 ( struct V_9 * V_10 , struct V_403 * V_404 )
{
int V_42 = - V_157 ;
struct V_417 * V_171 ;
V_171 = F_18 ( V_418 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_114 = V_404 -> V_114 ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
F_78 ( V_171 ) ;
return V_42 ;
}
static int F_83 ( T_1 * V_419 , int V_156 ,
int * V_190 , int * V_420 )
{
int V_163 ;
int V_421 ;
* V_419 = F_84 ( * V_419 ) ;
V_421 = * V_419 * V_156 ;
for ( V_163 = 0 ; V_163 < V_422 ; V_163 ++ ) {
if ( V_421 <= ( V_423 << V_163 ) )
break;
}
if ( V_163 >= V_422 )
return - V_74 ;
V_421 = F_85 ( V_421 ,
( ( V_423 << V_163 ) / V_424 ) ) ;
* V_190 =
V_421 / ( ( V_423 << V_163 ) / V_424 ) ;
* V_420 = ( ( V_423 << V_163 ) / V_424 ) ;
* V_419 = V_421 / V_156 ;
return 0 ;
}
static int F_86 ( struct V_9 * V_10 )
{
int V_163 ;
int V_42 = 0 ;
int V_425 ;
struct V_426 * V_171 ;
struct V_427 * V_185 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
T_3 V_194 ;
struct V_429 * V_430 ;
V_171 = F_18 ( V_431 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_425 = V_432 ;
V_10 -> V_433 . V_153 = sizeof( struct V_434 ) * V_425 ;
V_171 -> V_435 = ( V_436 <<
V_437 ) &
V_438 ;
for ( V_163 = 0 ; V_163 < V_422 ; V_163 ++ ) {
if ( V_439 == ( V_382 << V_163 ) )
break;
}
V_171 -> V_435 |= ( V_163 << V_440 ) &
V_441 ;
V_171 -> V_435 |= ( sizeof( struct V_434 ) <<
V_442 ) &
V_443 ;
V_10 -> V_433 . V_444 . V_5 = F_23 ( & V_152 -> V_10 , V_439 ,
& V_10 -> V_433 . V_444 . V_194 ,
V_139 ) ;
if ( V_10 -> V_433 . V_444 . V_5 == NULL )
goto V_445;
V_10 -> V_433 . V_5 = F_23 ( & V_152 -> V_10 , V_10 -> V_433 . V_153 ,
& V_194 , V_139 ) ;
if ( V_10 -> V_433 . V_5 == NULL )
goto V_446;
V_10 -> V_433 . V_194 = V_194 ;
V_10 -> V_433 . V_447 = V_425 ;
memset ( V_10 -> V_433 . V_5 , 0 , V_10 -> V_433 . V_153 ) ;
V_430 = (struct V_429 * ) V_10 -> V_433 . V_444 . V_5 ;
for ( V_163 = 0 ; V_163 < V_10 -> V_433 . V_153 / V_382 ; V_163 ++ ) {
V_430 [ V_163 ] . V_448 = ( T_1 ) ( V_194 & 0xffffffff ) ;
V_430 [ V_163 ] . V_449 = ( T_1 ) F_25 ( V_194 ) ;
V_194 += V_439 ;
}
V_171 -> V_450 [ 0 ] . V_164 = ( T_1 ) ( V_10 -> V_433 . V_444 . V_194 & 0xFFFFFFFF ) ;
V_171 -> V_450 [ 0 ] . V_165 = ( T_1 ) F_25 ( V_10 -> V_433 . V_444 . V_194 ) ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_427 * ) V_171 ;
V_10 -> V_433 . V_451 = V_185 -> V_451 & 0xFFFF ;
F_78 ( V_171 ) ;
return 0 ;
V_198:
F_21 ( & V_152 -> V_10 , V_10 -> V_433 . V_153 , V_10 -> V_433 . V_5 ,
V_10 -> V_433 . V_194 ) ;
V_10 -> V_433 . V_5 = NULL ;
V_446:
F_21 ( & V_152 -> V_10 , V_439 , V_10 -> V_433 . V_444 . V_5 ,
V_10 -> V_433 . V_444 . V_194 ) ;
V_10 -> V_433 . V_444 . V_5 = NULL ;
V_10 -> V_433 . V_153 = 0 ;
V_445:
F_78 ( V_171 ) ;
return V_42 ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_452 * V_171 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
if ( V_10 -> V_433 . V_5 == NULL )
return;
V_171 = F_18 ( V_453 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return;
V_171 -> V_451 = V_10 -> V_433 . V_451 ;
F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
F_21 ( & V_152 -> V_10 , V_10 -> V_433 . V_153 , V_10 -> V_433 . V_5 ,
V_10 -> V_433 . V_194 ) ;
F_21 ( & V_152 -> V_10 , V_439 , V_10 -> V_433 . V_444 . V_5 ,
V_10 -> V_433 . V_444 . V_194 ) ;
F_78 ( V_171 ) ;
}
static T_2 F_88 ( struct V_9 * V_10 )
{
int V_163 , V_454 = 0 , V_455 = 0 ;
T_2 V_118 ;
F_48 ( & V_10 -> V_456 ) ;
V_455 = V_10 -> V_204 [ 0 ] . V_455 ;
V_118 = V_10 -> V_204 [ 0 ] . V_4 . V_114 ;
for ( V_163 = 0 ; V_163 < V_10 -> V_203 ; V_163 ++ ) {
if ( V_10 -> V_204 [ V_163 ] . V_455 < V_455 ) {
V_455 = V_10 -> V_204 [ V_163 ] . V_455 ;
V_118 = V_10 -> V_204 [ V_163 ] . V_4 . V_114 ;
V_454 = V_163 ;
}
}
V_10 -> V_204 [ V_454 ] . V_455 += 1 ;
F_49 ( & V_10 -> V_456 ) ;
return V_118 ;
}
static void F_89 ( struct V_9 * V_10 , T_2 V_118 )
{
int V_163 ;
F_48 ( & V_10 -> V_456 ) ;
for ( V_163 = 0 ; V_163 < V_10 -> V_203 ; V_163 ++ ) {
if ( V_10 -> V_204 [ V_163 ] . V_4 . V_114 != V_118 )
continue;
V_10 -> V_204 [ V_163 ] . V_455 -= 1 ;
break;
}
F_49 ( & V_10 -> V_456 ) ;
}
int F_90 ( struct V_9 * V_10 , struct V_239 * V_14 ,
int V_457 , int V_458 )
{
int V_42 = - V_157 ; int V_459 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
struct V_460 * V_171 ;
struct V_461 * V_185 ;
T_1 V_462 , V_463 , V_420 , V_464 ;
if ( V_458 )
return - V_74 ;
if ( V_457 > V_10 -> V_326 . V_366 ) {
F_53 ( L_7 ,
V_285 , V_10 -> V_114 , V_10 -> V_326 . V_366 , V_457 ) ;
return - V_74 ;
}
if ( V_458 && ( V_10 -> V_111 . V_187 != V_188 ) )
return - V_74 ;
if ( V_458 ) {
V_14 -> V_459 = 1 ;
V_459 = 1 ;
V_463 = V_465 ;
V_462 = 1 ;
} else {
V_14 -> V_459 = V_10 -> V_326 . V_366 ;
V_459 = V_10 -> V_326 . V_366 ;
V_463 = sizeof( struct V_466 ) ;
V_462 = V_467 ;
}
V_14 -> V_155 = F_85 ( V_459 * V_463 , V_382 ) ;
V_171 = F_18 ( V_207 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return - V_157 ;
F_17 ( & V_171 -> V_171 . V_179 , V_207 ,
V_180 , sizeof( * V_171 ) ) ;
V_14 -> V_5 = F_23 ( & V_152 -> V_10 , V_14 -> V_155 , & V_14 -> V_194 , V_139 ) ;
if ( ! V_14 -> V_5 ) {
V_42 = - V_157 ;
goto V_445;
}
memset ( V_14 -> V_5 , 0 , V_14 -> V_155 ) ;
V_420 = V_14 -> V_155 / V_462 ;
V_171 -> V_171 . V_208 = ( V_420 / V_382 ) <<
V_468 ;
V_171 -> V_171 . V_208 |= V_462 ;
V_171 -> V_171 . V_209 = V_210 ;
if ( V_10 -> V_203 < 0 )
goto V_469;
V_14 -> V_211 = F_88 ( V_10 ) ;
V_171 -> V_171 . V_179 . V_189 = V_470 ;
V_464 = V_14 -> V_155 / V_463 ;
if ( V_464 > 1024 )
V_171 -> V_171 . V_209 |= ( 0x3 << V_471 ) ;
else {
V_3 V_472 = 0 ;
switch ( V_464 ) {
case 256 :
V_472 = 0 ;
break;
case 512 :
V_472 = 1 ;
break;
case 1024 :
V_472 = 2 ;
break;
default:
goto V_198;
}
V_171 -> V_171 . V_209 |= ( V_472 << V_471 ) ;
}
V_171 -> V_171 . V_211 = V_14 -> V_211 ;
if ( V_10 -> V_111 . V_187 == V_188 ) {
if ( V_458 )
V_171 -> V_171 . V_208 |= V_473 <<
V_474 ;
V_14 -> V_475 = false ;
V_171 -> V_171 . V_464 = ( V_14 -> V_155 / V_463 ) ;
} else {
V_171 -> V_171 . V_464 = ( V_14 -> V_155 / V_463 ) - 1 ;
V_171 -> V_171 . V_209 |= V_476 ;
V_14 -> V_475 = true ;
}
F_24 ( & V_171 -> V_171 . V_194 [ 0 ] , V_462 , V_14 -> V_194 , V_420 ) ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_461 * ) V_171 ;
V_14 -> V_114 = ( T_2 ) ( V_185 -> V_185 . V_100 & V_213 ) ;
F_78 ( V_171 ) ;
return 0 ;
V_198:
F_89 ( V_10 , V_14 -> V_211 ) ;
V_469:
F_21 ( & V_152 -> V_10 , V_14 -> V_155 , V_14 -> V_5 , V_14 -> V_194 ) ;
V_445:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_91 ( struct V_9 * V_10 , struct V_239 * V_14 )
{
int V_42 = - V_157 ;
struct V_477 * V_171 ;
V_171 = F_18 ( V_176 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
F_17 ( & V_171 -> V_179 , V_176 ,
V_180 , sizeof( * V_171 ) ) ;
V_171 -> V_478 |=
( V_14 -> V_114 << V_479 ) &
V_480 ;
F_89 ( V_10 , V_14 -> V_211 ) ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
F_21 ( & V_10 -> V_111 . V_152 -> V_10 , V_14 -> V_155 , V_14 -> V_5 , V_14 -> V_194 ) ;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_92 ( struct V_9 * V_10 , struct V_481 * V_482 ,
T_1 V_483 , int V_484 )
{
int V_42 = - V_157 ;
struct V_485 * V_171 ;
struct V_486 * V_185 ;
V_171 = F_18 ( V_487 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_483 = V_483 ;
V_171 -> V_488 |= V_484 ;
V_171 -> V_488 |= ( V_482 -> V_489 << V_490 ) ;
V_171 -> V_488 |=
( V_482 -> V_491 << V_492 ) ;
V_171 -> V_488 |=
( V_482 -> V_493 << V_494 ) ;
V_171 -> V_488 |=
( V_482 -> V_495 << V_496 ) ;
V_171 -> V_488 |=
( V_482 -> V_497 << V_498 ) ;
V_171 -> V_488 |=
( V_482 -> V_499 << V_500 ) ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_486 * ) V_171 ;
V_482 -> V_501 = V_185 -> V_502 ;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_93 ( struct V_9 * V_10 , int V_489 , T_1 V_501 )
{
int V_42 = - V_157 ;
struct V_503 * V_171 ;
V_171 = F_18 ( V_504 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return - V_157 ;
V_171 -> V_501 = V_501 ;
V_171 -> V_505 = V_489 ? 1 : 0 ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
static int F_94 ( struct V_9 * V_10 , struct V_481 * V_482 ,
T_1 V_483 , T_1 V_506 , T_1 V_507 , T_1 V_508 )
{
int V_42 = - V_157 ;
int V_163 ;
struct V_509 * V_171 ;
struct V_510 * V_185 ;
V_171 = F_18 ( V_511 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return - V_157 ;
V_171 -> V_512 =
V_483 | ( V_482 -> V_499 << V_513 ) ;
V_171 -> V_514 |= ( V_482 -> V_491 <<
V_515 ) ;
V_171 -> V_514 |= ( V_482 -> V_493 <<
V_516 ) ;
V_171 -> V_514 |= ( V_482 -> V_495 <<
V_517 ) ;
V_171 -> V_514 |= ( V_482 -> V_497 <<
V_518 ) ;
V_171 -> V_514 |= ( V_482 -> V_519 <<
V_520 ) ;
V_171 -> V_514 |= ( V_508 << V_521 ) ;
V_171 -> V_514 |= ( V_482 -> V_507 / V_522 ) ;
V_171 -> V_514 |= ( V_482 -> V_523 / V_522 ) <<
V_524 ;
V_171 -> V_525 = V_482 -> V_155 ;
V_171 -> V_526 = F_25 ( V_482 -> V_155 ) ;
V_171 -> V_527 = ( T_1 ) ( V_482 -> V_528 & 0xffffffff ) ;
V_171 -> V_529 = ( T_1 ) F_25 ( V_482 -> V_528 ) ;
V_171 -> V_530 = ( T_1 ) V_482 -> V_5 ;
V_171 -> V_531 = ( T_1 ) F_25 ( V_482 -> V_5 ) ;
for ( V_163 = 0 ; V_163 < V_506 ; V_163 ++ ) {
V_171 -> V_444 [ V_163 ] . V_164 = ( T_1 ) ( V_482 -> V_532 [ V_163 ] . V_194 & 0xffffffff ) ;
V_171 -> V_444 [ V_163 ] . V_165 = F_25 ( V_482 -> V_532 [ V_163 ] . V_194 ) ;
}
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_510 * ) V_171 ;
V_482 -> V_501 = V_185 -> V_502 ;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_481 * V_482 , T_1 V_506 ,
T_1 V_533 , T_1 V_508 )
{
int V_42 = - V_157 ;
int V_163 ;
struct V_534 * V_171 ;
V_171 = F_18 ( V_535 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return - V_157 ;
V_171 -> V_502 = V_482 -> V_501 ;
V_171 -> V_536 = ( V_506 << V_537 ) |
( V_533 & V_538 ) ;
V_171 -> V_508 = V_508 << V_539 ;
for ( V_163 = 0 ; V_163 < V_506 ; V_163 ++ ) {
V_171 -> V_444 [ V_163 ] . V_164 =
( T_1 ) ( V_482 -> V_532 [ V_163 + V_533 ] . V_194 & 0xffffffff ) ;
V_171 -> V_444 [ V_163 ] . V_165 =
F_25 ( V_482 -> V_532 [ V_163 + V_533 ] . V_194 ) ;
}
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_96 ( struct V_9 * V_10 ,
struct V_481 * V_482 , T_1 V_483 , int V_540 )
{
int V_42 ;
T_1 V_508 = 0 ;
T_1 V_541 , V_533 ;
T_1 V_542 = V_482 -> V_499 ;
V_533 = 0 ;
V_541 = F_97 ( V_542 , V_543 ) ;
if ( V_541 == V_542 )
V_508 = 1 ;
V_42 = F_94 ( V_10 , V_482 , V_483 ,
V_541 , V_482 -> V_507 , V_508 ) ;
if ( V_42 ) {
F_53 ( L_8 , V_285 , V_42 ) ;
return V_42 ;
}
if ( V_508 )
return 0 ;
while ( ! V_508 ) {
V_533 += V_541 ;
V_542 -= V_541 ;
V_541 = F_97 ( V_542 , V_543 ) ;
if ( V_541 == V_542 )
V_508 = 1 ;
V_42 = F_95 ( V_10 , V_482 , V_541 ,
V_533 , V_508 ) ;
if ( V_42 )
break;
}
if ( V_42 )
F_53 ( L_9 , V_285 , V_42 ) ;
return V_42 ;
}
bool F_98 ( struct V_239 * V_14 , struct V_234 * V_235 )
{
struct V_234 * V_544 ;
bool V_545 = false ;
F_62 (tmp, &cq->sq_head, sq_entry) {
if ( V_235 == V_544 ) {
V_545 = true ;
break;
}
}
return V_545 ;
}
bool F_99 ( struct V_239 * V_14 , struct V_234 * V_235 )
{
struct V_234 * V_544 ;
bool V_545 = false ;
F_62 (tmp, &cq->rq_head, rq_entry) {
if ( V_235 == V_544 ) {
V_545 = true ;
break;
}
}
return V_545 ;
}
void F_100 ( struct V_234 * V_235 )
{
bool V_545 ;
unsigned long V_304 ;
F_61 ( & V_235 -> V_10 -> V_306 , V_304 ) ;
V_545 = F_98 ( V_235 -> V_307 , V_235 ) ;
if ( ! V_545 )
F_101 ( & V_235 -> V_546 , & V_235 -> V_307 -> V_547 ) ;
if ( ! V_235 -> V_278 ) {
V_545 = F_99 ( V_235 -> V_308 , V_235 ) ;
if ( ! V_545 )
F_101 ( & V_235 -> V_548 , & V_235 -> V_308 -> V_549 ) ;
}
F_63 ( & V_235 -> V_10 -> V_306 , V_304 ) ;
}
int F_51 ( struct V_234 * V_235 , enum V_24 V_550 ,
enum V_24 * V_551 )
{
unsigned long V_304 ;
int V_42 = 0 ;
enum V_25 V_552 ;
V_552 = F_10 ( V_550 ) ;
F_61 ( & V_235 -> V_553 , V_304 ) ;
if ( V_551 )
* V_551 = F_9 ( V_235 -> V_554 ) ;
if ( V_552 == V_235 -> V_554 ) {
F_63 ( & V_235 -> V_553 , V_304 ) ;
return 1 ;
}
switch ( V_235 -> V_554 ) {
case V_27 :
switch ( V_552 ) {
case V_27 :
case V_29 :
break;
default:
V_42 = - V_74 ;
break;
} ;
break;
case V_29 :
switch ( V_552 ) {
case V_29 :
case V_31 :
break;
case V_40 :
F_100 ( V_235 ) ;
break;
default:
V_42 = - V_74 ;
break;
} ;
break;
case V_31 :
switch ( V_552 ) {
case V_33 :
break;
case V_40 :
F_100 ( V_235 ) ;
break;
default:
V_42 = - V_74 ;
break;
} ;
break;
case V_33 :
switch ( V_552 ) {
case V_35 :
case V_38 :
break;
case V_40 :
F_100 ( V_235 ) ;
break;
default:
V_42 = - V_74 ;
break;
} ;
break;
case V_35 :
switch ( V_552 ) {
case V_33 :
case V_38 :
case V_40 :
break;
default:
V_42 = - V_74 ;
break;
} ;
break;
case V_38 :
switch ( V_552 ) {
case V_33 :
case V_40 :
break;
default:
V_42 = - V_74 ;
break;
} ;
break;
case V_40 :
switch ( V_552 ) {
case V_27 :
break;
default:
V_42 = - V_74 ;
break;
} ;
break;
default:
V_42 = - V_74 ;
break;
} ;
if ( ! V_42 )
V_235 -> V_554 = V_552 ;
F_63 ( & V_235 -> V_553 , V_304 ) ;
return V_42 ;
}
static T_1 F_102 ( struct V_234 * V_235 )
{
T_1 V_304 = 0 ;
if ( V_235 -> V_555 & V_556 )
V_304 |= V_557 ;
if ( V_235 -> V_555 & V_558 )
V_304 |= V_559 ;
if ( V_235 -> V_555 & V_560 )
V_304 |= V_561 ;
if ( V_235 -> V_555 & V_562 )
V_304 |= V_563 ;
if ( V_235 -> V_555 & V_564 )
V_304 |= V_565 ;
return V_304 ;
}
static int F_103 ( struct V_566 * V_171 ,
struct V_567 * V_568 ,
struct V_234 * V_235 )
{
int V_42 ;
T_1 V_155 , V_462 , V_162 ;
T_3 V_194 ;
struct V_9 * V_10 = V_235 -> V_10 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
T_1 V_569 ;
T_1 V_570 = V_568 -> V_571 . V_336 ;
V_569 = V_568 -> V_571 . V_572 ;
if ( V_10 -> V_111 . V_187 != V_188 )
V_569 += 1 ;
V_42 = F_83 ( & V_569 ,
V_10 -> V_326 . V_369 , & V_462 , & V_162 ) ;
if ( V_42 ) {
F_53 ( L_10 , V_285 ,
V_569 ) ;
return - V_74 ;
}
V_235 -> V_19 . V_573 = V_569 ;
V_155 = ( V_462 * V_162 ) ;
V_235 -> V_19 . V_5 = F_23 ( & V_152 -> V_10 , V_155 , & V_194 , V_139 ) ;
if ( ! V_235 -> V_19 . V_5 )
return - V_74 ;
memset ( V_235 -> V_19 . V_5 , 0 , V_155 ) ;
V_235 -> V_19 . V_155 = V_155 ;
V_235 -> V_19 . V_194 = V_194 ;
V_235 -> V_19 . V_156 = V_10 -> V_326 . V_369 ;
F_24 ( & V_171 -> V_574 [ 0 ] , V_462 , V_194 , V_162 ) ;
V_171 -> V_575 |= ( F_104 ( V_162 / V_382 )
<< V_576 ) ;
V_171 -> V_577 |= ( V_462 <<
V_578 ) &
V_579 ;
V_171 -> V_580 |= ( V_570 <<
V_581 ) &
V_582 ;
V_171 -> V_580 |= ( V_570 <<
V_583 ) &
V_584 ;
V_171 -> V_585 |= ( F_104 ( V_235 -> V_19 . V_573 ) <<
V_586 ) &
V_587 ;
V_171 -> V_588 |= ( V_10 -> V_326 . V_369 <<
V_589 ) &
V_590 ;
return 0 ;
}
static int F_105 ( struct V_566 * V_171 ,
struct V_567 * V_568 ,
struct V_234 * V_235 )
{
int V_42 ;
T_1 V_155 , V_462 , V_162 ;
T_3 V_194 = 0 ;
struct V_9 * V_10 = V_235 -> V_10 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
T_1 V_591 = V_568 -> V_571 . V_592 + 1 ;
V_42 = F_83 ( & V_591 , V_10 -> V_326 . V_374 ,
& V_462 , & V_162 ) ;
if ( V_42 ) {
F_53 ( L_11 , V_285 ,
V_568 -> V_571 . V_592 + 1 ) ;
return V_42 ;
}
V_235 -> V_593 . V_573 = V_591 ;
V_155 = ( V_462 * V_162 ) ;
V_235 -> V_593 . V_5 = F_23 ( & V_152 -> V_10 , V_155 , & V_194 , V_139 ) ;
if ( ! V_235 -> V_593 . V_5 )
return - V_157 ;
memset ( V_235 -> V_593 . V_5 , 0 , V_155 ) ;
V_235 -> V_593 . V_194 = V_194 ;
V_235 -> V_593 . V_155 = V_155 ;
V_235 -> V_593 . V_156 = V_10 -> V_326 . V_374 ;
F_24 ( & V_171 -> V_594 [ 0 ] , V_462 , V_194 , V_162 ) ;
V_171 -> V_575 |= ( F_104 ( V_162 / V_382 ) <<
V_595 ) ;
V_171 -> V_577 |=
( V_462 << V_596 ) &
V_597 ;
V_171 -> V_598 |= ( V_568 -> V_571 . V_340 <<
V_599 ) &
V_600 ;
V_171 -> V_585 |= ( F_104 ( V_235 -> V_593 . V_573 ) <<
V_601 ) &
V_602 ;
V_171 -> V_588 |= ( V_10 -> V_326 . V_374 <<
V_603 ) &
V_604 ;
return 0 ;
}
static void F_106 ( struct V_566 * V_171 ,
struct V_403 * V_404 ,
struct V_234 * V_235 ,
V_3 V_605 , T_2 V_606 )
{
V_404 -> V_416 -- ;
V_235 -> V_408 = true ;
V_171 -> V_598 |= V_607 ;
if ( ! V_605 )
return;
V_171 -> V_598 |= V_607 ;
V_171 -> V_608 = V_606 ;
V_171 -> V_608 |= V_609 <<
V_610 ;
}
static int F_107 ( struct V_566 * V_171 ,
struct V_234 * V_235 )
{
struct V_9 * V_10 = V_235 -> V_10 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
T_3 V_194 = 0 ;
int V_381 = V_10 -> V_326 . V_381 ;
int V_611 = V_10 -> V_326 . V_383 * V_381 ;
if ( V_10 -> V_326 . V_380 == 0 )
return 0 ;
V_235 -> V_612 = F_23 ( & V_152 -> V_10 , V_611 ,
& V_194 , V_139 ) ;
if ( ! V_235 -> V_612 )
return - V_157 ;
memset ( V_235 -> V_612 , 0 , V_611 ) ;
F_24 ( & V_171 -> V_613 [ 0 ] , V_10 -> V_326 . V_383 ,
V_194 , V_381 ) ;
return 0 ;
}
static void F_108 ( struct V_614 * V_185 ,
struct V_234 * V_235 ,
struct V_567 * V_568 ,
T_2 * V_615 , T_2 * V_616 )
{
T_1 V_569 , V_591 ;
V_235 -> V_114 = V_185 -> V_617 & V_618 ;
V_235 -> V_593 . V_619 = V_185 -> V_620 & V_621 ;
V_235 -> V_19 . V_619 = V_185 -> V_620 >> V_622 ;
V_235 -> V_623 = V_185 -> V_624 & V_625 ;
V_235 -> V_626 = ( V_185 -> V_624 >> V_627 ) ;
V_235 -> V_408 = false ;
if ( V_185 -> V_628 & V_629 ) {
V_235 -> V_408 = true ;
* V_616 = ( V_185 -> V_628 &
V_630 ) >>
V_631 ;
* V_615 = ( V_185 -> V_628 &
V_632 ) >>
V_633 ;
}
V_569 =
V_185 -> V_585 >> V_634 ;
V_569 = 1 << V_569 ;
V_591 = 1 << ( ( T_2 ) V_185 -> V_585 ) ;
V_235 -> V_19 . V_573 = V_569 ;
V_235 -> V_19 . V_635 = V_569 - 1 ;
if ( ! V_568 -> V_278 ) {
V_235 -> V_593 . V_573 = V_591 ;
V_235 -> V_593 . V_635 = V_591 - 1 ;
}
}
int F_109 ( struct V_234 * V_235 , struct V_567 * V_568 ,
V_3 V_605 , T_2 V_606 , T_2 * V_615 ,
T_2 * V_616 )
{
int V_42 = - V_157 ;
T_1 V_304 = 0 ;
struct V_9 * V_10 = V_235 -> V_10 ;
struct V_403 * V_404 = V_235 -> V_404 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
struct V_239 * V_14 ;
struct V_566 * V_171 ;
struct V_614 * V_185 ;
int V_636 ;
switch ( V_568 -> V_637 ) {
case V_638 :
V_636 = V_639 ;
break;
case V_640 :
V_636 = V_641 ;
break;
case V_642 :
V_636 = V_643 ;
break;
default:
return - V_74 ;
} ;
V_171 = F_18 ( V_644 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_575 |= ( V_636 << V_645 ) &
V_646 ;
V_42 = F_103 ( V_171 , V_568 , V_235 ) ;
if ( V_42 )
goto V_647;
if ( V_568 -> V_278 ) {
struct V_648 * V_278 = F_110 ( V_568 -> V_278 ) ;
V_171 -> V_598 |= V_649 ;
V_171 -> V_594 [ 0 ] . V_164 = V_278 -> V_114 ;
V_235 -> V_278 = V_278 ;
} else {
V_42 = F_105 ( V_171 , V_568 , V_235 ) ;
if ( V_42 )
goto V_650;
}
V_42 = F_107 ( V_171 , V_235 ) ;
if ( V_42 )
goto V_198;
V_171 -> V_575 |= ( V_404 -> V_114 << V_651 ) &
V_652 ;
V_304 = F_102 ( V_235 ) ;
V_171 -> V_598 |= V_304 ;
V_171 -> V_624 |= ( V_10 -> V_326 . V_345 <<
V_653 ) &
V_654 ;
V_171 -> V_624 |= ( V_10 -> V_326 . V_349 <<
V_655 ) &
V_656 ;
V_14 = F_111 ( V_568 -> V_657 ) ;
V_171 -> V_658 |= ( V_14 -> V_114 << V_659 ) &
V_660 ;
V_235 -> V_307 = V_14 ;
V_14 = F_111 ( V_568 -> V_661 ) ;
V_171 -> V_658 |= ( V_14 -> V_114 << V_662 ) &
V_663 ;
V_235 -> V_308 = V_14 ;
if ( V_404 -> V_408 && V_568 -> V_571 . V_377 && V_404 -> V_416 &&
( V_568 -> V_571 . V_377 <= V_10 -> V_326 . V_377 ) )
F_106 ( V_171 , V_404 , V_235 , V_605 ,
V_606 ) ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_614 * ) V_171 ;
F_108 ( V_185 , V_235 , V_568 , V_615 , V_616 ) ;
V_235 -> V_554 = V_27 ;
F_78 ( V_171 ) ;
return 0 ;
V_198:
if ( V_235 -> V_593 . V_5 )
F_21 ( & V_152 -> V_10 , V_235 -> V_593 . V_155 , V_235 -> V_593 . V_5 , V_235 -> V_593 . V_194 ) ;
V_650:
F_53 ( L_12 , V_285 , V_10 -> V_114 ) ;
F_21 ( & V_152 -> V_10 , V_235 -> V_19 . V_155 , V_235 -> V_19 . V_5 , V_235 -> V_19 . V_194 ) ;
V_647:
F_53 ( L_13 , V_285 , V_10 -> V_114 ) ;
F_78 ( V_171 ) ;
return V_42 ;
}
int F_112 ( struct V_9 * V_10 , struct V_234 * V_235 ,
struct V_664 * V_665 )
{
int V_42 = - V_157 ;
struct V_666 * V_171 ;
struct V_667 * V_185 ;
V_171 = F_18 ( V_668 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_617 = V_235 -> V_114 ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_667 * ) V_171 ;
memcpy ( V_665 , & V_185 -> V_669 , sizeof( struct V_664 ) ) ;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_113 ( struct V_9 * V_10 , union V_670 * V_671 ,
V_3 * V_672 )
{
struct V_673 V_674 ;
memcpy ( & V_674 , V_671 , sizeof V_674 ) ;
if ( F_114 ( & V_674 ) )
F_115 ( & V_674 , V_672 ) ;
else if ( F_116 ( & V_674 ) )
F_117 ( & V_674 , V_672 ) ;
else {
F_53 ( L_14 , V_285 ) ;
return - V_74 ;
}
return 0 ;
}
static void F_118 ( struct V_234 * V_235 ,
struct V_675 * V_171 ,
struct V_676 * V_568 )
{
struct V_677 * V_678 = & V_568 -> V_678 ;
union V_670 V_679 ;
T_1 V_680 ;
V_3 V_672 [ 6 ] ;
if ( ( V_678 -> V_681 & V_682 ) == 0 )
return;
V_171 -> V_669 . V_683 |=
( V_678 -> V_684 . V_685 << V_686 ) ;
V_171 -> V_669 . V_687 |=
( V_678 -> V_684 . V_688 & V_689 ) ;
V_171 -> V_669 . V_690 |=
( V_678 -> V_684 . V_691 << V_692 ) ;
V_171 -> V_304 |= V_693 ;
memcpy ( & V_171 -> V_669 . V_671 [ 0 ] , & V_678 -> V_684 . V_671 . V_694 [ 0 ] ,
sizeof( V_171 -> V_669 . V_671 ) ) ;
F_119 ( & V_235 -> V_10 -> V_258 , 1 ,
V_678 -> V_684 . V_695 , & V_679 ) ;
V_235 -> V_696 = V_678 -> V_684 . V_695 ;
memcpy ( & V_171 -> V_669 . V_679 [ 0 ] , & V_679 . V_694 [ 0 ] , sizeof( V_171 -> V_669 . V_679 ) ) ;
F_113 ( V_235 -> V_10 , & V_678 -> V_684 . V_671 , & V_672 [ 0 ] ) ;
V_171 -> V_669 . V_697 = V_672 [ 0 ] | ( V_672 [ 1 ] << 8 ) |
( V_672 [ 2 ] << 16 ) | ( V_672 [ 3 ] << 24 ) ;
F_120 ( & V_171 -> V_669 . V_671 [ 0 ] , sizeof( V_171 -> V_669 . V_671 ) ) ;
F_120 ( & V_171 -> V_669 . V_679 [ 0 ] , sizeof( V_171 -> V_669 . V_679 ) ) ;
V_171 -> V_669 . V_698 = V_672 [ 4 ] | ( V_672 [ 5 ] << 8 ) ;
V_680 = F_121 ( & V_679 ) ;
if ( V_680 && ( V_680 < 0x1000 ) ) {
V_171 -> V_669 . V_698 |=
V_680 << V_699 ;
V_171 -> V_304 |= V_700 ;
}
}
static int F_122 ( struct V_234 * V_235 ,
struct V_675 * V_171 ,
struct V_676 * V_568 , int V_701 ,
enum V_24 V_702 )
{
int V_42 = 0 ;
struct V_703 * V_181 = V_235 -> V_10 -> V_111 . V_181 ;
int V_704 = F_123 ( V_181 -> V_705 ) ;
if ( V_701 & V_706 ) {
V_171 -> V_669 . V_707 |= ( V_568 -> V_708 &
V_709 ) ;
V_171 -> V_304 |= V_710 ;
}
if ( V_701 & V_711 ) {
V_235 -> V_712 = V_568 -> V_712 ;
V_171 -> V_669 . V_712 = V_568 -> V_712 ;
V_171 -> V_304 |= V_713 ;
}
if ( V_701 & V_714 )
F_118 ( V_235 , V_171 , V_568 ) ;
else if ( V_235 -> V_637 == V_638 || V_235 -> V_637 == V_642 ) {
V_171 -> V_669 . V_697 = V_235 -> V_10 -> V_111 . V_672 [ 0 ] |
( V_235 -> V_10 -> V_111 . V_672 [ 1 ] << 8 ) |
( V_235 -> V_10 -> V_111 . V_672 [ 2 ] << 16 ) |
( V_235 -> V_10 -> V_111 . V_672 [ 3 ] << 24 ) ;
V_171 -> V_669 . V_698 = V_235 -> V_10 -> V_111 . V_672 [ 4 ] |
( V_235 -> V_10 -> V_111 . V_672 [ 5 ] << 8 ) ;
}
if ( ( V_701 & V_715 ) &&
V_568 -> V_716 ) {
V_171 -> V_669 . V_598 |=
V_717 ;
V_171 -> V_304 |= V_718 ;
}
if ( V_701 & V_719 ) {
V_171 -> V_669 . V_720 |= ( V_568 -> V_721 &
V_722 ) ;
V_171 -> V_304 |= V_718 ;
}
if ( V_701 & V_723 ) {
if ( F_124 ( V_704 ) <
F_124 ( V_568 -> V_724 ) ) {
V_42 = - V_74 ;
goto V_725;
}
V_171 -> V_669 . V_707 |=
( F_124 ( V_568 -> V_724 ) <<
V_726 ) &
V_727 ;
V_171 -> V_304 |= V_728 ;
}
if ( V_701 & V_729 ) {
V_171 -> V_669 . V_720 |= V_568 -> V_137 <<
V_730 ;
V_171 -> V_304 |= V_731 ;
}
if ( V_701 & V_732 ) {
V_171 -> V_669 . V_687 |= ( V_568 -> V_733 <<
V_734 ) &
V_735 ;
V_171 -> V_304 |= V_736 ;
}
if ( V_701 & V_737 ) {
V_171 -> V_669 . V_687 |= ( V_568 -> V_738 <<
V_739 ) &
V_740 ;
V_171 -> V_304 |= V_741 ;
}
if ( V_701 & V_742 ) {
V_171 -> V_669 . V_720 |= ( V_568 -> V_743 <<
V_744 )
& V_745 ;
V_171 -> V_304 |= V_746 ;
}
if ( V_701 & V_747 ) {
V_171 -> V_669 . V_683 |= ( V_568 -> V_748 & 0x00ffffff ) ;
V_171 -> V_304 |= V_749 ;
}
if ( V_701 & V_750 ) {
V_171 -> V_669 . V_690 |= ( V_568 -> V_751 & 0x00ffffff ) ;
V_171 -> V_304 |= V_752 ;
}
if ( V_701 & V_753 ) {
if ( V_568 -> V_754 > V_235 -> V_10 -> V_326 . V_345 ) {
V_42 = - V_74 ;
goto V_725;
}
V_235 -> V_626 = V_568 -> V_754 ;
V_171 -> V_304 |= V_755 ;
}
if ( V_701 & V_756 ) {
if ( V_568 -> V_757 > V_235 -> V_10 -> V_326 . V_349 ) {
V_42 = - V_74 ;
goto V_725;
}
V_235 -> V_623 = V_568 -> V_757 ;
V_171 -> V_304 |= V_758 ;
}
V_171 -> V_669 . V_624 = ( V_235 -> V_626 <<
V_759 ) |
( V_235 -> V_623 & V_760 ) ;
V_725:
return V_42 ;
}
int F_125 ( struct V_9 * V_10 , struct V_234 * V_235 ,
struct V_676 * V_568 , int V_701 ,
enum V_24 V_702 )
{
int V_42 = - V_157 ;
struct V_675 * V_171 ;
V_171 = F_18 ( V_761 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_669 . V_114 = V_235 -> V_114 ;
V_171 -> V_304 = 0 ;
if ( V_701 & V_762 ) {
V_171 -> V_669 . V_598 |=
( F_10 ( V_568 -> V_763 ) <<
V_764 ) &
V_765 ;
V_171 -> V_304 |= V_766 ;
} else
V_171 -> V_669 . V_598 |=
( V_235 -> V_554 << V_764 ) &
V_765 ;
V_42 = F_122 ( V_235 , V_171 , V_568 , V_701 , V_702 ) ;
if ( V_42 )
goto V_198;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_198:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_126 ( struct V_9 * V_10 , struct V_234 * V_235 )
{
int V_42 = - V_157 ;
struct V_767 * V_171 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
V_171 = F_18 ( V_768 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_617 = V_235 -> V_114 ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_198:
F_78 ( V_171 ) ;
if ( V_235 -> V_19 . V_5 )
F_21 ( & V_152 -> V_10 , V_235 -> V_19 . V_155 , V_235 -> V_19 . V_5 , V_235 -> V_19 . V_194 ) ;
if ( ! V_235 -> V_278 && V_235 -> V_593 . V_5 )
F_21 ( & V_152 -> V_10 , V_235 -> V_593 . V_155 , V_235 -> V_593 . V_5 , V_235 -> V_593 . V_194 ) ;
if ( V_235 -> V_408 )
V_235 -> V_404 -> V_416 ++ ;
return V_42 ;
}
int F_127 ( struct V_648 * V_278 ,
struct V_769 * V_770 ,
struct V_403 * V_404 )
{
int V_42 = - V_157 ;
int V_462 , V_162 ;
int V_155 ;
struct V_771 * V_185 ;
struct V_772 * V_171 ;
T_3 V_194 ;
struct V_9 * V_10 = V_278 -> V_10 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
T_1 V_591 ;
V_171 = F_18 ( V_773 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_774 = V_404 -> V_114 & V_775 ;
V_591 = V_770 -> V_326 . V_776 + 1 ;
V_42 = F_83 ( & V_591 ,
V_10 -> V_326 . V_374 ,
& V_462 , & V_162 ) ;
if ( V_42 ) {
F_53 ( L_15 , V_285 ,
V_770 -> V_326 . V_776 ) ;
V_42 = - V_74 ;
goto V_777;
}
V_155 = V_462 * V_162 ;
V_278 -> V_593 . V_5 = F_23 ( & V_152 -> V_10 , V_155 , & V_194 , V_139 ) ;
if ( ! V_278 -> V_593 . V_5 ) {
V_42 = - V_157 ;
goto V_777;
}
F_24 ( & V_171 -> V_594 [ 0 ] , V_462 , V_194 , V_162 ) ;
V_278 -> V_593 . V_156 = V_10 -> V_326 . V_374 ;
V_278 -> V_593 . V_194 = V_194 ;
V_278 -> V_593 . V_155 = V_155 ;
V_278 -> V_593 . V_573 = V_591 ;
V_171 -> V_778 = F_104 ( V_591 ) ;
V_171 -> V_778 |= V_770 -> V_326 . V_779 <<
V_780 ;
V_171 -> V_774 |= ( F_104 ( V_162 / V_382 )
<< V_781 ) ;
V_171 -> V_782 |= ( V_10 -> V_326 . V_374
<< V_783 )
& V_784 ;
V_171 -> V_782 |= V_462 << V_785 ;
V_42 = F_73 ( V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 )
goto V_198;
V_185 = (struct V_771 * ) V_171 ;
V_278 -> V_114 = V_185 -> V_114 ;
V_278 -> V_593 . V_619 = V_185 -> V_114 ;
V_591 = ( ( V_185 -> V_786 &
V_787 ) >>
V_788 ) ;
V_591 = ( 1 << V_591 ) ;
V_278 -> V_593 . V_573 = V_591 ;
V_278 -> V_593 . V_635 = V_591 - 1 ;
V_278 -> V_593 . V_570 = ( V_185 -> V_786 &
V_789 ) >>
V_790 ;
goto V_777;
V_198:
F_21 ( & V_152 -> V_10 , V_278 -> V_593 . V_155 , V_278 -> V_593 . V_5 , V_194 ) ;
V_777:
F_78 ( V_171 ) ;
return V_42 ;
}
int F_128 ( struct V_648 * V_278 , struct V_791 * V_770 )
{
int V_42 = - V_157 ;
struct V_792 * V_171 ;
V_171 = F_18 ( V_773 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_114 = V_278 -> V_114 ;
V_171 -> V_793 |= V_770 -> V_794 <<
V_795 ;
V_42 = F_73 ( V_278 -> V_10 , (struct V_18 * ) V_171 ) ;
F_78 ( V_171 ) ;
return V_42 ;
}
int F_129 ( struct V_648 * V_278 , struct V_791 * V_770 )
{
int V_42 = - V_157 ;
struct V_796 * V_171 ;
V_171 = F_18 ( V_773 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_114 = V_278 -> V_593 . V_619 ;
V_42 = F_73 ( V_278 -> V_10 , (struct V_18 * ) V_171 ) ;
if ( V_42 == 0 ) {
struct V_797 * V_185 =
(struct V_797 * ) V_171 ;
V_770 -> V_779 =
V_185 -> V_798 &
V_799 ;
V_770 -> V_776 =
V_185 -> V_800 >> V_801 ;
V_770 -> V_794 = V_185 -> V_798 >>
V_802 ;
}
F_78 ( V_171 ) ;
return V_42 ;
}
int F_130 ( struct V_9 * V_10 , struct V_648 * V_278 )
{
int V_42 = - V_157 ;
struct V_803 * V_171 ;
struct V_428 * V_152 = V_10 -> V_111 . V_152 ;
V_171 = F_18 ( V_804 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
return V_42 ;
V_171 -> V_114 = V_278 -> V_114 ;
V_42 = F_73 ( V_278 -> V_10 , (struct V_18 * ) V_171 ) ;
if ( V_278 -> V_593 . V_5 )
F_21 ( & V_152 -> V_10 , V_278 -> V_593 . V_155 ,
V_278 -> V_593 . V_5 , V_278 -> V_593 . V_194 ) ;
F_78 ( V_171 ) ;
return V_42 ;
}
int F_131 ( struct V_9 * V_10 , struct V_805 * V_806 )
{
int V_163 ;
int V_42 = - V_74 ;
struct V_434 * V_807 ;
unsigned long V_304 ;
V_807 = V_10 -> V_433 . V_5 ;
F_61 ( & V_10 -> V_433 . V_230 , V_304 ) ;
for ( V_163 = 0 ; V_163 < V_10 -> V_433 . V_447 ; V_163 ++ ) {
if ( V_807 -> V_191 == 0 ) {
V_807 -> V_191 = V_808 ;
V_806 -> V_807 = V_807 ;
V_806 -> V_114 = V_163 ;
V_42 = 0 ;
break;
}
V_807 ++ ;
}
if ( V_163 == V_10 -> V_433 . V_447 )
V_42 = - V_53 ;
F_63 ( & V_10 -> V_433 . V_230 , V_304 ) ;
return V_42 ;
}
int F_132 ( struct V_9 * V_10 , struct V_805 * V_806 )
{
unsigned long V_304 ;
F_61 ( & V_10 -> V_433 . V_230 , V_304 ) ;
V_806 -> V_807 -> V_191 = 0 ;
F_63 ( & V_10 -> V_433 . V_230 , V_304 ) ;
return 0 ;
}
static int F_133 ( struct V_9 * V_10 )
{
int V_42 ;
int V_199 ;
unsigned long V_304 = 0 ;
int V_809 = 0 ;
if ( V_10 -> V_111 . V_200 == V_201 )
V_304 = V_810 ;
else {
V_809 = V_10 -> V_111 . V_167 . V_811 -
V_10 -> V_111 . V_167 . V_168 ;
if ( V_809 < 2 )
return - V_79 ;
}
V_42 = F_32 ( V_10 , & V_10 -> V_227 , V_8 ) ;
if ( V_42 )
return V_42 ;
sprintf ( V_10 -> V_227 . V_812 , L_16 , V_10 -> V_114 ) ;
V_199 = F_33 ( V_10 , & V_10 -> V_227 ) ;
V_42 = F_134 ( V_199 , F_66 , V_304 , V_10 -> V_227 . V_812 ,
& V_10 -> V_227 ) ;
if ( V_42 )
F_34 ( V_10 , & V_10 -> V_227 ) ;
return V_42 ;
}
static int F_135 ( struct V_9 * V_10 )
{
int V_809 , V_163 , V_42 = 0 ;
int V_199 ;
unsigned long V_304 = 0 ;
V_809 = V_10 -> V_111 . V_167 . V_811 -
V_10 -> V_111 . V_167 . V_168 ;
if ( V_10 -> V_111 . V_200 == V_201 ) {
V_809 = 1 ;
V_304 = V_810 ;
} else
V_809 = F_136 ( T_1 , V_809 , F_137 () ) ;
V_10 -> V_204 = F_19 ( sizeof( struct V_1 ) * V_809 , V_139 ) ;
if ( ! V_10 -> V_204 )
return - V_157 ;
for ( V_163 = 0 ; V_163 < V_809 ; V_163 ++ ) {
V_42 = F_32 ( V_10 , & V_10 -> V_204 [ V_163 ] ,
V_8 ) ;
if ( V_42 ) {
V_42 = - V_74 ;
break;
}
sprintf ( V_10 -> V_204 [ V_163 ] . V_812 , L_17 ,
V_10 -> V_114 , V_163 ) ;
V_199 = F_33 ( V_10 , & V_10 -> V_204 [ V_163 ] ) ;
V_42 = F_134 ( V_199 , F_66 , V_304 ,
V_10 -> V_204 [ V_163 ] . V_812 ,
& V_10 -> V_204 [ V_163 ] ) ;
if ( V_42 ) {
F_34 ( V_10 , & V_10 -> V_204 [ V_163 ] ) ;
V_42 = - V_74 ;
break;
}
V_10 -> V_203 += 1 ;
}
if ( V_10 -> V_203 >= 1 )
return 0 ;
if ( V_42 )
F_37 ( V_10 ) ;
return V_42 ;
}
int F_138 ( struct V_9 * V_10 )
{
int V_42 ;
V_42 = F_133 ( V_10 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_135 ( V_10 ) ;
if ( V_42 )
goto V_813;
V_42 = F_44 ( V_10 ) ;
if ( V_42 )
goto V_814;
V_42 = F_79 ( V_10 ) ;
if ( V_42 )
goto V_815;
V_42 = F_80 ( V_10 ) ;
if ( V_42 )
goto V_815;
V_42 = F_77 ( V_10 ) ;
if ( V_42 )
goto V_815;
V_42 = F_86 ( V_10 ) ;
if ( V_42 )
goto V_815;
return 0 ;
V_815:
F_47 ( V_10 ) ;
V_814:
F_37 ( V_10 ) ;
V_813:
F_35 ( V_10 , & V_10 -> V_227 ) ;
F_53 ( L_8 , V_285 , V_42 ) ;
return V_42 ;
}
void F_139 ( struct V_9 * V_10 )
{
F_87 ( V_10 ) ;
F_37 ( V_10 ) ;
F_47 ( V_10 ) ;
F_35 ( V_10 , & V_10 -> V_227 ) ;
}
