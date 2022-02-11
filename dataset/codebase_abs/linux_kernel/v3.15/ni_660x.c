static inline unsigned F_1 ( unsigned V_1 )
{
unsigned V_2 = V_3 + V_1 / 2 ;
F_2 ( V_2 > V_4 ) ;
return V_2 ;
}
static inline unsigned F_3 ( unsigned V_5 )
{
return V_6 + V_5 ;
}
static inline unsigned F_4 ( unsigned V_1 )
{
if ( V_1 % 2 )
return 0 ;
else
return 8 ;
}
static inline unsigned F_5 ( unsigned V_1 )
{
return 0x3 << F_4 ( V_1 ) ;
}
static inline unsigned F_6 ( unsigned V_1 ,
unsigned V_7 )
{
return ( V_7 & 0x3 ) << F_4 ( V_1 ) ;
}
static inline unsigned F_7 ( unsigned V_1 )
{
return 0x7 << ( 4 + F_4 ( V_1 ) ) ;
}
static inline unsigned F_8 ( unsigned V_1 ,
unsigned V_8 )
{
return ( V_8 & 0x7 ) << ( 4 + F_4 ( V_1 ) ) ;
}
static inline unsigned F_9 ( unsigned V_9 )
{
F_2 ( V_9 >= V_10 ) ;
return 0x1f << ( 8 * V_9 ) ;
}
static inline unsigned F_10 ( unsigned V_9 , unsigned V_11 )
{
F_2 ( V_9 >= V_10 ) ;
return ( V_11 << ( 8 * V_9 ) ) & F_9 ( V_9 ) ;
}
static inline unsigned F_11 ( unsigned V_9 )
{
F_2 ( V_9 >= V_10 ) ;
return 0x80 << ( 8 * V_9 ) ;
}
static inline unsigned F_12 ( struct V_12 * V_13 )
{
const struct V_14 * V_15 = F_13 ( V_13 ) ;
return V_15 -> V_16 * V_17 ;
}
static enum V_18 F_14 ( enum V_19 V_2 )
{
switch ( V_2 ) {
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
case V_44 :
return V_45 ;
case V_46 :
return V_47 ;
case V_48 :
return V_49 ;
case V_50 :
return V_51 ;
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
case V_56 :
return V_57 ;
case V_58 :
return V_59 ;
case V_60 :
return V_61 ;
case V_62 :
return V_63 ;
case V_64 :
return V_65 ;
case V_66 :
return V_67 ;
case V_68 :
return V_69 ;
case V_70 :
return V_71 ;
case V_72 :
return V_73 ;
case V_74 :
return V_75 ;
case V_76 :
return V_77 ;
case V_78 :
return V_79 ;
case V_80 :
return V_81 ;
case V_82 :
return V_83 ;
case V_84 :
return V_85 ;
case V_86 :
return V_87 ;
case V_88 :
return V_89 ;
case V_90 :
return V_91 ;
case V_92 :
return V_93 ;
case V_94 :
return V_95 ;
case V_96 :
return V_97 ;
case V_98 :
return V_99 ;
case V_100 :
return V_101 ;
case V_102 :
return V_103 ;
case V_104 :
return V_105 ;
case V_106 :
return V_107 ;
case V_108 :
return V_109 ;
case V_110 :
return V_111 ;
case V_112 :
return V_113 ;
case V_114 :
return V_115 ;
case V_116 :
return V_117 ;
case V_118 :
return V_119 ;
case V_120 :
return V_121 ;
case V_122 :
return V_123 ;
case V_124 :
return V_125 ;
case V_126 :
return V_127 ;
case V_128 :
return V_129 ;
case V_130 :
return V_131 ;
case V_132 :
return V_133 ;
case V_134 :
return V_135 ;
case V_136 :
return V_137 ;
case V_138 :
return V_139 ;
case V_140 :
return V_141 ;
case V_142 :
return V_143 ;
case V_144 :
return V_145 ;
case V_146 :
return V_147 ;
case V_148 :
return V_149 ;
case V_150 :
return V_151 ;
case V_152 :
return V_153 ;
case V_154 :
return V_155 ;
default:
F_15 () ;
return 0 ;
}
}
static inline void F_16 ( struct V_12 * V_13 ,
unsigned V_156 , unsigned V_157 ,
enum V_18 V_2 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
void T_1 * V_161 =
V_159 -> V_162 -> V_163 + V_164 [ V_156 ] +
V_165 [ V_2 ] . V_166 ;
switch ( V_165 [ V_2 ] . V_167 ) {
case V_168 :
F_17 ( V_157 , V_161 ) ;
break;
case V_169 :
F_18 ( V_157 , V_161 ) ;
break;
default:
F_15 () ;
break;
}
}
static inline unsigned F_19 ( struct V_12 * V_13 ,
unsigned V_156 ,
enum V_18 V_2 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
void T_1 * V_170 =
V_159 -> V_162 -> V_163 + V_164 [ V_156 ] +
V_165 [ V_2 ] . V_166 ;
switch ( V_165 [ V_2 ] . V_167 ) {
case V_168 :
return F_20 ( V_170 ) ;
break;
case V_169 :
return F_21 ( V_170 ) ;
break;
default:
F_15 () ;
break;
}
return 0 ;
}
static void F_22 ( struct V_171 * V_172 , unsigned V_157 ,
enum V_19 V_2 )
{
struct V_12 * V_13 = V_172 -> V_173 -> V_13 ;
enum V_18 V_18 = F_14 ( V_2 ) ;
unsigned V_156 = V_172 -> V_174 ;
F_16 ( V_13 , V_156 , V_157 , V_18 ) ;
}
static unsigned F_23 ( struct V_171 * V_172 ,
enum V_19 V_2 )
{
struct V_12 * V_13 = V_172 -> V_173 -> V_13 ;
enum V_18 V_18 = F_14 ( V_2 ) ;
unsigned V_156 = V_172 -> V_174 ;
return F_19 ( V_13 , V_156 , V_18 ) ;
}
static inline struct V_175 * F_24 ( struct V_158
* V_176 ,
struct V_171
* V_172 )
{
unsigned V_156 = V_172 -> V_174 ;
return V_176 -> V_177 [ V_156 ] [ V_172 -> V_178 ] ;
}
static inline void F_25 ( struct V_12 * V_13 ,
unsigned V_179 ,
struct V_171 * V_172 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
unsigned V_156 = V_172 -> V_174 ;
unsigned long V_180 ;
F_26 ( & V_159 -> V_181 , V_180 ) ;
V_159 -> V_182 [ V_156 ] &=
~ F_9 ( V_179 ) ;
V_159 -> V_182 [ V_156 ] |=
F_10 ( V_179 , V_172 -> V_178 ) ;
F_16 ( V_13 , V_156 ,
V_159 -> V_182 [ V_156 ] |
F_11 ( V_179 ) , V_183 ) ;
F_27 () ;
F_28 ( & V_159 -> V_181 , V_180 ) ;
}
static inline void F_29 ( struct V_12 * V_13 ,
unsigned V_179 ,
struct V_171 * V_172 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
unsigned V_156 = V_172 -> V_174 ;
unsigned long V_180 ;
F_26 ( & V_159 -> V_181 , V_180 ) ;
V_159 -> V_182 [ V_156 ] &=
~ F_9 ( V_179 ) ;
V_159 -> V_182 [ V_156 ] |=
F_10 ( V_179 , V_184 ) ;
F_16 ( V_13 , V_156 ,
V_159 -> V_182 [ V_156 ] ,
V_183 ) ;
F_27 () ;
F_28 ( & V_159 -> V_181 , V_180 ) ;
}
static int F_30 ( struct V_12 * V_13 ,
struct V_171 * V_172 ,
enum V_185 V_186 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
unsigned long V_180 ;
struct V_179 * V_187 ;
F_26 ( & V_159 -> V_188 , V_180 ) ;
F_2 ( V_172 -> V_187 ) ;
V_187 = F_31 ( V_159 -> V_162 ,
F_24 ( V_159 , V_172 ) ) ;
if ( V_187 == NULL ) {
F_28 ( & V_159 -> V_188 , V_180 ) ;
F_32 ( V_13 ,
L_1 ) ;
return - V_189 ;
}
V_187 -> V_190 = V_186 ;
F_33 ( V_172 , V_187 ) ;
F_25 ( V_13 , V_187 -> V_191 , V_172 ) ;
F_28 ( & V_159 -> V_188 , V_180 ) ;
return 0 ;
}
static void F_34 ( struct V_12 * V_13 ,
struct V_171 * V_172 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
unsigned long V_180 ;
F_26 ( & V_159 -> V_188 , V_180 ) ;
if ( V_172 -> V_187 ) {
struct V_179 * V_187 = V_172 -> V_187 ;
F_29 ( V_13 , V_187 -> V_191 , V_172 ) ;
F_33 ( V_172 , NULL ) ;
F_35 ( V_187 ) ;
}
F_28 ( & V_159 -> V_188 , V_180 ) ;
}
static int F_36 ( struct V_12 * V_13 , struct V_192 * V_193 )
{
struct V_171 * V_172 = V_193 -> V_160 ;
int V_194 ;
V_194 = F_30 ( V_13 , V_172 , V_195 ) ;
if ( V_194 ) {
F_32 ( V_13 ,
L_2 ) ;
return V_194 ;
}
F_37 ( V_172 , NULL , NULL , NULL , NULL ) ;
return F_38 ( V_13 , V_193 ) ;
}
static int F_39 ( struct V_12 * V_13 , struct V_192 * V_193 )
{
struct V_171 * V_172 = V_193 -> V_160 ;
int V_194 ;
V_194 = F_40 ( V_172 ) ;
F_34 ( V_13 , V_172 ) ;
return V_194 ;
}
static void F_41 ( struct V_12 * V_13 , int V_156 )
{
unsigned V_157 = 0 ;
if ( V_156 )
V_157 = V_196 ;
F_16 ( V_13 , V_156 , V_157 , V_197 ) ;
}
static void F_42 ( struct V_12 * V_13 ,
struct V_192 * V_193 )
{
struct V_171 * V_172 = V_193 -> V_160 ;
F_43 ( V_172 , V_193 ) ;
F_44 ( V_13 , V_193 ) ;
}
static T_2 F_45 ( int V_198 , void * V_199 )
{
struct V_12 * V_13 = V_199 ;
struct V_158 * V_159 = V_13 -> V_160 ;
struct V_192 * V_193 ;
unsigned V_200 ;
unsigned long V_180 ;
if ( ! V_13 -> V_201 )
return V_202 ;
F_26 ( & V_159 -> V_203 , V_180 ) ;
F_46 () ;
for ( V_200 = 0 ; V_200 < F_12 ( V_13 ) ; ++ V_200 ) {
V_193 = & V_13 -> V_204 [ F_3 ( V_200 ) ] ;
F_42 ( V_13 , V_193 ) ;
}
F_28 ( & V_159 -> V_203 , V_180 ) ;
return V_205 ;
}
static int F_47 ( struct V_12 * V_13 ,
struct V_192 * V_193 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
struct V_171 * V_172 = V_193 -> V_160 ;
unsigned long V_180 ;
F_26 ( & V_159 -> V_203 , V_180 ) ;
F_48 ( V_172 -> V_187 , V_193 -> V_206 ) ;
F_28 ( & V_159 -> V_203 , V_180 ) ;
return F_49 ( V_193 -> V_206 ) ;
}
static int F_50 ( struct V_12 * V_13 ,
struct V_192 * V_193 ,
unsigned long V_207 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
struct V_171 * V_172 = V_193 -> V_160 ;
int V_208 ;
V_208 = F_51 ( F_24 ( V_159 , V_172 ) , V_193 -> V_206 ) ;
if ( V_208 < 0 )
return V_208 ;
return 0 ;
}
static int F_52 ( struct V_12 * V_13 )
{
struct V_158 * V_159 ;
unsigned V_200 ;
V_159 = F_53 ( V_13 , sizeof( * V_159 ) ) ;
if ( ! V_159 )
return - V_209 ;
F_54 ( & V_159 -> V_188 ) ;
F_54 ( & V_159 -> V_203 ) ;
F_54 ( & V_159 -> V_181 ) ;
for ( V_200 = 0 ; V_200 < V_210 ; ++ V_200 )
V_159 -> V_211 [ V_200 ] = V_212 ;
return 0 ;
}
static int F_55 ( struct V_12 * V_13 )
{
const struct V_14 * V_15 = F_13 ( V_13 ) ;
struct V_158 * V_159 = V_13 -> V_160 ;
unsigned V_200 ;
unsigned V_213 ;
for ( V_200 = 0 ; V_200 < V_15 -> V_16 ; ++ V_200 ) {
for ( V_213 = 0 ; V_213 < V_17 ; ++ V_213 ) {
V_159 -> V_177 [ V_200 ] [ V_213 ] =
F_56 ( V_159 -> V_162 ) ;
if ( V_159 -> V_177 [ V_200 ] [ V_213 ] == NULL )
return - V_209 ;
}
}
return 0 ;
}
static void F_57 ( struct V_12 * V_13 )
{
const struct V_14 * V_15 = F_13 ( V_13 ) ;
struct V_158 * V_159 = V_13 -> V_160 ;
unsigned V_200 ;
unsigned V_213 ;
for ( V_200 = 0 ; V_200 < V_15 -> V_16 ; ++ V_200 ) {
for ( V_213 = 0 ; V_213 < V_17 ; ++ V_213 )
F_58 ( V_159 -> V_177 [ V_200 ] [ V_213 ] ) ;
}
}
static void F_59 ( struct V_12 * V_13 , int V_214 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
unsigned V_200 ;
V_159 -> V_182 [ V_214 ] = 0 ;
for ( V_200 = 0 ; V_200 < V_10 ; ++ V_200 ) {
V_159 -> V_182 [ V_214 ] |=
F_10 ( V_200 , V_184 ) & F_9 ( V_200 ) ;
}
F_16 ( V_13 , V_214 ,
V_159 -> V_182 [ V_214 ] ,
V_183 ) ;
for ( V_200 = 0 ; V_200 < V_210 ; ++ V_200 )
F_16 ( V_13 , V_214 , 0 , F_1 ( V_200 ) ) ;
}
static int F_60 ( struct V_12 * V_13 ,
struct V_192 * V_193 ,
struct V_215 * V_216 , unsigned int * V_217 )
{
unsigned V_218 = F_61 ( V_216 -> V_219 ) ;
if ( V_217 [ 0 ] ) {
V_193 -> V_220 &= ~ ( V_217 [ 0 ] << V_218 ) ;
V_193 -> V_220 |= ( V_217 [ 0 ] & V_217 [ 1 ] ) << V_218 ;
F_16 ( V_13 , 0 , V_193 -> V_220 , V_221 ) ;
}
V_217 [ 1 ] = ( F_19 ( V_13 , 0 , V_222 ) >>
V_218 ) ;
return V_216 -> V_223 ;
}
static void F_62 ( struct V_12 * V_13 ,
unsigned V_1 ,
unsigned V_7 )
{
const struct V_14 * V_15 = F_13 ( V_13 ) ;
static const unsigned V_224 = 8 ;
static const unsigned V_225 = 23 ;
unsigned V_226 = 0 ;
unsigned V_227 = 0 ;
unsigned V_228 ;
unsigned V_229 ;
if ( V_15 -> V_16 > 1 ) {
if ( V_7 == V_212 &&
V_1 >= V_224 &&
V_1 <= V_225 ) {
V_226 = 1 ;
V_227 = 0 ;
} else {
V_226 = 0 ;
V_227 = 1 ;
}
}
if ( V_227 != V_226 ) {
V_229 =
F_19 ( V_13 , V_227 ,
F_1 ( V_1 ) ) ;
V_229 &= ~ F_5 ( V_1 ) ;
V_229 |=
F_6 ( V_1 ,
V_230 ) ;
F_16 ( V_13 , V_227 , V_229 ,
F_1 ( V_1 ) ) ;
}
V_228 =
F_19 ( V_13 , V_226 ,
F_1 ( V_1 ) ) ;
V_228 &= ~ F_5 ( V_1 ) ;
V_228 |= F_6 ( V_1 , V_7 ) ;
F_16 ( V_13 , V_226 , V_228 ,
F_1 ( V_1 ) ) ;
}
static int F_63 ( struct V_12 * V_13 , unsigned V_231 ,
unsigned V_232 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
if ( V_232 > V_233 )
return - V_234 ;
if ( V_232 == V_230 )
return - V_234 ;
if ( V_231 < V_235 ) {
if ( V_232 == V_212 )
return - V_234 ;
} else if ( V_231 > V_236 ) {
if ( V_232 == V_237 )
return - V_234 ;
}
V_159 -> V_211 [ V_231 ] = V_232 ;
if ( V_159 -> V_238 & ( ( ( V_239 ) 1 ) << V_231 ) )
F_62 ( V_13 , V_231 ,
V_159 -> V_211 [ V_231 ] ) ;
return 0 ;
}
static int F_64 ( struct V_12 * V_13 ,
struct V_192 * V_193 ,
struct V_215 * V_216 ,
unsigned int * V_217 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
unsigned int V_231 = F_61 ( V_216 -> V_219 ) ;
V_239 V_240 = 1ULL << V_231 ;
unsigned int V_241 ;
int V_208 ;
switch ( V_217 [ 0 ] ) {
case V_242 :
V_159 -> V_238 |= V_240 ;
F_62 ( V_13 , V_231 ,
V_159 -> V_211 [ V_231 ] ) ;
break;
case V_243 :
V_159 -> V_238 &= ~ V_240 ;
F_62 ( V_13 , V_231 , V_230 ) ;
break;
case V_244 :
V_217 [ 1 ] = ( V_159 -> V_238 & V_240 ) ? V_245
: V_195 ;
break;
case V_246 :
V_208 = F_63 ( V_13 , V_231 , V_217 [ 1 ] ) ;
if ( V_208 )
return V_208 ;
break;
case V_247 :
V_217 [ 1 ] = V_159 -> V_211 [ V_231 ] ;
break;
case V_248 :
V_241 = F_19 ( V_13 , 0 , F_1 ( V_231 ) ) ;
V_241 &= ~ F_7 ( V_231 ) ;
V_241 |= F_8 ( V_231 , V_217 [ 1 ] ) ;
F_16 ( V_13 , 0 , V_241 , F_1 ( V_231 ) ) ;
break;
default:
return - V_234 ;
}
return V_216 -> V_223 ;
}
static int F_65 ( struct V_12 * V_13 ,
unsigned long V_249 )
{
struct V_250 * V_251 = F_66 ( V_13 ) ;
const struct V_14 * V_15 = NULL ;
struct V_158 * V_159 ;
struct V_192 * V_193 ;
int V_208 ;
unsigned V_200 ;
unsigned V_252 ;
if ( V_249 < F_67 ( V_253 ) )
V_15 = & V_253 [ V_249 ] ;
if ( ! V_15 )
return - V_254 ;
V_13 -> V_255 = V_15 ;
V_13 -> V_256 = V_15 -> V_257 ;
V_208 = F_68 ( V_13 ) ;
if ( V_208 )
return V_208 ;
V_208 = F_52 ( V_13 ) ;
if ( V_208 < 0 )
return V_208 ;
V_159 = V_13 -> V_160 ;
V_159 -> V_162 = F_69 ( V_251 ) ;
if ( ! V_159 -> V_162 )
return - V_209 ;
V_208 = F_70 ( V_159 -> V_162 , 1 ) ;
if ( V_208 < 0 ) {
F_71 ( V_13 -> V_258 , L_3 ) ;
return V_208 ;
}
V_208 = F_55 ( V_13 ) ;
if ( V_208 < 0 )
return V_208 ;
V_208 = F_72 ( V_13 , 2 + V_259 ) ;
if ( V_208 )
return V_208 ;
V_193 = & V_13 -> V_204 [ 0 ] ;
V_193 -> type = V_260 ;
V_193 = & V_13 -> V_204 [ V_261 ] ;
V_193 -> type = V_262 ;
V_193 -> V_263 = V_264 | V_265 ;
V_193 -> V_266 = V_210 ;
V_193 -> V_267 = 1 ;
V_193 -> V_268 = & V_269 ;
V_193 -> V_270 = F_60 ;
V_193 -> V_271 = F_64 ;
F_16 ( V_13 , 0 , 0 , V_272 ) ;
V_159 -> V_173 = F_73 ( V_13 ,
& F_22 ,
& F_23 ,
V_273 ,
F_12
( V_13 ) ) ;
if ( V_159 -> V_173 == NULL )
return - V_209 ;
for ( V_200 = 0 ; V_200 < V_259 ; ++ V_200 ) {
V_193 = & V_13 -> V_204 [ F_3 ( V_200 ) ] ;
if ( V_200 < F_12 ( V_13 ) ) {
V_193 -> type = V_274 ;
V_193 -> V_263 =
V_264 | V_265 | V_275 |
V_276 ;
V_193 -> V_266 = 3 ;
V_193 -> V_267 = 0xffffffff ;
V_193 -> V_277 = V_278 ;
V_193 -> V_279 = V_280 ;
V_193 -> V_271 = V_281 ;
V_193 -> V_282 = & F_36 ;
V_193 -> V_283 = 1 ;
V_193 -> V_284 = V_285 ;
V_193 -> V_286 = & F_39 ;
V_193 -> V_287 = & F_47 ;
V_193 -> V_288 = V_289 ;
V_193 -> V_290 = & F_50 ;
V_193 -> V_160 = & V_159 -> V_173 -> V_291 [ V_200 ] ;
V_159 -> V_173 -> V_291 [ V_200 ] . V_174 =
V_200 / V_17 ;
V_159 -> V_173 -> V_291 [ V_200 ] . V_178 =
V_200 % V_17 ;
} else {
V_193 -> type = V_260 ;
}
}
for ( V_200 = 0 ; V_200 < V_15 -> V_16 ; ++ V_200 )
F_59 ( V_13 , V_200 ) ;
for ( V_200 = 0 ; V_200 < F_12 ( V_13 ) ; ++ V_200 )
F_74 ( & V_159 -> V_173 -> V_291 [ V_200 ] ) ;
for ( V_200 = 0 ; V_200 < V_210 ; ++ V_200 ) {
if ( V_200 < V_235 )
F_63 ( V_13 , V_200 , V_237 ) ;
else
F_63 ( V_13 , V_200 ,
V_212 ) ;
F_62 ( V_13 , V_200 , V_230 ) ;
}
for ( V_200 = 0 ; V_200 < V_15 -> V_16 ; ++ V_200 )
F_41 ( V_13 , V_200 ) ;
V_208 = F_75 ( F_76 ( V_159 -> V_162 ) , F_45 ,
V_292 , L_4 , V_13 ) ;
if ( V_208 < 0 ) {
F_71 ( V_13 -> V_258 , L_5 ) ;
return V_208 ;
}
V_13 -> V_198 = F_76 ( V_159 -> V_162 ) ;
V_252 = V_293 ;
if ( V_15 -> V_16 > 1 )
V_252 |= V_294 ;
F_16 ( V_13 , 0 , V_252 ,
V_295 ) ;
return 0 ;
}
static void F_77 ( struct V_12 * V_13 )
{
struct V_158 * V_159 = V_13 -> V_160 ;
if ( V_13 -> V_198 )
F_78 ( V_13 -> V_198 , V_13 ) ;
if ( V_159 ) {
if ( V_159 -> V_173 )
F_79 ( V_159 -> V_173 ) ;
if ( V_159 -> V_162 ) {
F_57 ( V_13 ) ;
F_80 ( V_159 -> V_162 ) ;
F_81 ( V_159 -> V_162 ) ;
}
}
F_82 ( V_13 ) ;
}
static int F_83 ( struct V_250 * V_13 ,
const struct V_296 * V_297 )
{
return F_84 ( V_13 , & V_298 , V_297 -> V_299 ) ;
}
