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
return ( V_1 % 2 ) ? 0 : 8 ;
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
const struct V_14 * V_15 = V_13 -> V_16 ;
return V_15 -> V_17 * V_18 ;
}
static enum V_19 F_13 ( enum V_20 V_2 )
{
switch ( V_2 ) {
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_36 ;
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
case V_47 :
return V_48 ;
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
case V_57 :
return V_58 ;
case V_59 :
return V_60 ;
case V_61 :
return V_62 ;
case V_63 :
return V_64 ;
case V_65 :
return V_66 ;
case V_67 :
return V_68 ;
case V_69 :
return V_70 ;
case V_71 :
return V_72 ;
case V_73 :
return V_74 ;
case V_75 :
return V_76 ;
case V_77 :
return V_78 ;
case V_79 :
return V_80 ;
case V_81 :
return V_82 ;
case V_83 :
return V_84 ;
case V_85 :
return V_86 ;
case V_87 :
return V_88 ;
case V_89 :
return V_90 ;
case V_91 :
return V_92 ;
case V_93 :
return V_94 ;
case V_95 :
return V_96 ;
case V_97 :
return V_98 ;
case V_99 :
return V_100 ;
case V_101 :
return V_102 ;
case V_103 :
return V_104 ;
case V_105 :
return V_106 ;
case V_107 :
return V_108 ;
case V_109 :
return V_110 ;
case V_111 :
return V_112 ;
case V_113 :
return V_114 ;
case V_115 :
return V_116 ;
case V_117 :
return V_118 ;
case V_119 :
return V_120 ;
case V_121 :
return V_122 ;
case V_123 :
return V_124 ;
case V_125 :
return V_126 ;
case V_127 :
return V_128 ;
case V_129 :
return V_130 ;
case V_131 :
return V_132 ;
case V_133 :
return V_134 ;
case V_135 :
return V_136 ;
case V_137 :
return V_138 ;
case V_139 :
return V_140 ;
case V_141 :
return V_142 ;
case V_143 :
return V_144 ;
case V_145 :
return V_146 ;
case V_147 :
return V_148 ;
case V_149 :
return V_150 ;
case V_151 :
return V_152 ;
case V_153 :
return V_154 ;
case V_155 :
return V_156 ;
default:
F_14 () ;
return 0 ;
}
}
static inline void F_15 ( struct V_12 * V_13 ,
unsigned V_157 , unsigned V_158 ,
enum V_19 V_2 )
{
unsigned int V_159 = V_160 [ V_157 ] + V_161 [ V_2 ] . V_162 ;
switch ( V_161 [ V_2 ] . V_163 ) {
case V_164 :
F_16 ( V_158 , V_13 -> V_165 + V_159 ) ;
break;
case V_166 :
F_17 ( V_158 , V_13 -> V_165 + V_159 ) ;
break;
default:
F_14 () ;
break;
}
}
static inline unsigned F_18 ( struct V_12 * V_13 ,
unsigned V_157 ,
enum V_19 V_2 )
{
unsigned int V_159 = V_160 [ V_157 ] + V_161 [ V_2 ] . V_162 ;
switch ( V_161 [ V_2 ] . V_163 ) {
case V_164 :
return F_19 ( V_13 -> V_165 + V_159 ) ;
case V_166 :
return F_20 ( V_13 -> V_165 + V_159 ) ;
default:
F_14 () ;
break;
}
return 0 ;
}
static void F_21 ( struct V_167 * V_168 , unsigned V_158 ,
enum V_20 V_2 )
{
struct V_12 * V_13 = V_168 -> V_169 -> V_13 ;
enum V_19 V_19 = F_13 ( V_2 ) ;
unsigned V_157 = V_168 -> V_170 ;
F_15 ( V_13 , V_157 , V_158 , V_19 ) ;
}
static unsigned F_22 ( struct V_167 * V_168 ,
enum V_20 V_2 )
{
struct V_12 * V_13 = V_168 -> V_169 -> V_13 ;
enum V_19 V_19 = F_13 ( V_2 ) ;
unsigned V_157 = V_168 -> V_170 ;
return F_18 ( V_13 , V_157 , V_19 ) ;
}
static inline struct V_171 * F_23 ( struct V_172
* V_173 ,
struct V_167
* V_168 )
{
unsigned V_157 = V_168 -> V_170 ;
return V_173 -> V_174 [ V_157 ] [ V_168 -> V_175 ] ;
}
static inline void F_24 ( struct V_12 * V_13 ,
unsigned V_176 ,
struct V_167 * V_168 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
unsigned V_157 = V_168 -> V_170 ;
unsigned long V_179 ;
F_25 ( & V_177 -> V_180 , V_179 ) ;
V_177 -> V_181 [ V_157 ] &=
~ F_9 ( V_176 ) ;
V_177 -> V_181 [ V_157 ] |=
F_10 ( V_176 , V_168 -> V_175 ) ;
F_15 ( V_13 , V_157 ,
V_177 -> V_181 [ V_157 ] |
F_11 ( V_176 ) , V_182 ) ;
F_26 () ;
F_27 ( & V_177 -> V_180 , V_179 ) ;
}
static inline void F_28 ( struct V_12 * V_13 ,
unsigned V_176 ,
struct V_167 * V_168 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
unsigned V_157 = V_168 -> V_170 ;
unsigned long V_179 ;
F_25 ( & V_177 -> V_180 , V_179 ) ;
V_177 -> V_181 [ V_157 ] &=
~ F_9 ( V_176 ) ;
V_177 -> V_181 [ V_157 ] |=
F_10 ( V_176 , V_183 ) ;
F_15 ( V_13 , V_157 ,
V_177 -> V_181 [ V_157 ] ,
V_182 ) ;
F_26 () ;
F_27 ( & V_177 -> V_180 , V_179 ) ;
}
static int F_29 ( struct V_12 * V_13 ,
struct V_167 * V_168 ,
enum V_184 V_185 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
unsigned long V_179 ;
struct V_176 * V_186 ;
F_25 ( & V_177 -> V_187 , V_179 ) ;
F_2 ( V_168 -> V_186 ) ;
V_186 = F_30 ( V_177 -> V_188 ,
F_23 ( V_177 , V_168 ) ) ;
if ( V_186 == NULL ) {
F_27 ( & V_177 -> V_187 , V_179 ) ;
F_31 ( V_13 -> V_189 ,
L_1 ) ;
return - V_190 ;
}
V_186 -> V_191 = V_185 ;
F_32 ( V_168 , V_186 ) ;
F_24 ( V_13 , V_186 -> V_192 , V_168 ) ;
F_27 ( & V_177 -> V_187 , V_179 ) ;
return 0 ;
}
static void F_33 ( struct V_12 * V_13 ,
struct V_167 * V_168 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
unsigned long V_179 ;
F_25 ( & V_177 -> V_187 , V_179 ) ;
if ( V_168 -> V_186 ) {
struct V_176 * V_186 = V_168 -> V_186 ;
F_28 ( V_13 , V_186 -> V_192 , V_168 ) ;
F_32 ( V_168 , NULL ) ;
F_34 ( V_186 ) ;
}
F_27 ( & V_177 -> V_187 , V_179 ) ;
}
static int F_35 ( struct V_12 * V_13 , struct V_193 * V_194 )
{
struct V_167 * V_168 = V_194 -> V_178 ;
int V_195 ;
V_195 = F_29 ( V_13 , V_168 , V_196 ) ;
if ( V_195 ) {
F_31 ( V_13 -> V_189 ,
L_2 ) ;
return V_195 ;
}
F_36 ( V_168 ) ;
return F_37 ( V_13 , V_194 ) ;
}
static int F_38 ( struct V_12 * V_13 , struct V_193 * V_194 )
{
struct V_167 * V_168 = V_194 -> V_178 ;
int V_195 ;
V_195 = F_39 ( V_168 ) ;
F_33 ( V_13 , V_168 ) ;
return V_195 ;
}
static void F_40 ( struct V_12 * V_13 , int V_157 )
{
unsigned V_158 = 0 ;
if ( V_157 )
V_158 = V_197 ;
F_15 ( V_13 , V_157 , V_158 , V_198 ) ;
}
static void F_41 ( struct V_12 * V_13 ,
struct V_193 * V_194 )
{
struct V_167 * V_168 = V_194 -> V_178 ;
F_42 ( V_168 , V_194 ) ;
F_43 ( V_13 , V_194 ) ;
}
static T_1 F_44 ( int V_199 , void * V_200 )
{
struct V_12 * V_13 = V_200 ;
struct V_172 * V_177 = V_13 -> V_178 ;
struct V_193 * V_194 ;
unsigned V_201 ;
unsigned long V_179 ;
if ( ! V_13 -> V_202 )
return V_203 ;
F_25 ( & V_177 -> V_204 , V_179 ) ;
F_45 () ;
for ( V_201 = 0 ; V_201 < F_12 ( V_13 ) ; ++ V_201 ) {
V_194 = & V_13 -> V_205 [ F_3 ( V_201 ) ] ;
F_41 ( V_13 , V_194 ) ;
}
F_27 ( & V_177 -> V_204 , V_179 ) ;
return V_206 ;
}
static int F_46 ( struct V_12 * V_13 ,
struct V_193 * V_194 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
struct V_167 * V_168 = V_194 -> V_178 ;
unsigned long V_179 ;
F_25 ( & V_177 -> V_204 , V_179 ) ;
F_47 ( V_168 -> V_186 , V_194 ) ;
F_27 ( & V_177 -> V_204 , V_179 ) ;
return F_48 ( V_194 ) ;
}
static int F_49 ( struct V_12 * V_13 ,
struct V_193 * V_194 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
struct V_167 * V_168 = V_194 -> V_178 ;
int V_207 ;
V_207 = F_50 ( F_23 ( V_177 , V_168 ) , V_194 ) ;
if ( V_207 < 0 )
return V_207 ;
return 0 ;
}
static int F_51 ( struct V_12 * V_13 )
{
struct V_172 * V_177 ;
unsigned V_201 ;
V_177 = F_52 ( V_13 , sizeof( * V_177 ) ) ;
if ( ! V_177 )
return - V_208 ;
F_53 ( & V_177 -> V_187 ) ;
F_53 ( & V_177 -> V_204 ) ;
F_53 ( & V_177 -> V_180 ) ;
for ( V_201 = 0 ; V_201 < V_209 ; ++ V_201 )
V_177 -> V_210 [ V_201 ] = V_211 ;
return 0 ;
}
static int F_54 ( struct V_12 * V_13 )
{
const struct V_14 * V_15 = V_13 -> V_16 ;
struct V_172 * V_177 = V_13 -> V_178 ;
unsigned V_201 ;
unsigned V_212 ;
for ( V_201 = 0 ; V_201 < V_15 -> V_17 ; ++ V_201 ) {
for ( V_212 = 0 ; V_212 < V_18 ; ++ V_212 ) {
V_177 -> V_174 [ V_201 ] [ V_212 ] =
F_55 ( V_177 -> V_188 ) ;
if ( V_177 -> V_174 [ V_201 ] [ V_212 ] == NULL )
return - V_208 ;
}
}
return 0 ;
}
static void F_56 ( struct V_12 * V_13 )
{
const struct V_14 * V_15 = V_13 -> V_16 ;
struct V_172 * V_177 = V_13 -> V_178 ;
unsigned V_201 ;
unsigned V_212 ;
for ( V_201 = 0 ; V_201 < V_15 -> V_17 ; ++ V_201 ) {
for ( V_212 = 0 ; V_212 < V_18 ; ++ V_212 )
F_57 ( V_177 -> V_174 [ V_201 ] [ V_212 ] ) ;
}
}
static void F_58 ( struct V_12 * V_13 , int V_213 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
unsigned V_201 ;
V_177 -> V_181 [ V_213 ] = 0 ;
for ( V_201 = 0 ; V_201 < V_10 ; ++ V_201 ) {
V_177 -> V_181 [ V_213 ] |=
F_10 ( V_201 , V_183 ) & F_9 ( V_201 ) ;
}
F_15 ( V_13 , V_213 ,
V_177 -> V_181 [ V_213 ] ,
V_182 ) ;
for ( V_201 = 0 ; V_201 < V_209 ; ++ V_201 )
F_15 ( V_13 , V_213 , 0 , F_1 ( V_201 ) ) ;
}
static int F_59 ( struct V_12 * V_13 ,
struct V_193 * V_194 ,
struct V_214 * V_215 , unsigned int * V_216 )
{
unsigned V_217 = F_60 ( V_215 -> V_218 ) ;
if ( V_216 [ 0 ] ) {
V_194 -> V_219 &= ~ ( V_216 [ 0 ] << V_217 ) ;
V_194 -> V_219 |= ( V_216 [ 0 ] & V_216 [ 1 ] ) << V_217 ;
F_15 ( V_13 , 0 , V_194 -> V_219 , V_220 ) ;
}
V_216 [ 1 ] = ( F_18 ( V_13 , 0 , V_221 ) >>
V_217 ) ;
return V_215 -> V_222 ;
}
static void F_61 ( struct V_12 * V_13 ,
unsigned V_1 ,
unsigned V_7 )
{
const struct V_14 * V_15 = V_13 -> V_16 ;
static const unsigned V_223 = 8 ;
static const unsigned V_224 = 23 ;
unsigned V_225 = 0 ;
unsigned V_226 = 0 ;
unsigned V_227 ;
unsigned V_228 ;
if ( V_15 -> V_17 > 1 ) {
if ( V_7 == V_211 &&
V_1 >= V_223 &&
V_1 <= V_224 ) {
V_225 = 1 ;
V_226 = 0 ;
} else {
V_225 = 0 ;
V_226 = 1 ;
}
}
if ( V_226 != V_225 ) {
V_228 =
F_18 ( V_13 , V_226 ,
F_1 ( V_1 ) ) ;
V_228 &= ~ F_5 ( V_1 ) ;
V_228 |=
F_6 ( V_1 ,
V_229 ) ;
F_15 ( V_13 , V_226 , V_228 ,
F_1 ( V_1 ) ) ;
}
V_227 =
F_18 ( V_13 , V_225 ,
F_1 ( V_1 ) ) ;
V_227 &= ~ F_5 ( V_1 ) ;
V_227 |= F_6 ( V_1 , V_7 ) ;
F_15 ( V_13 , V_225 , V_227 ,
F_1 ( V_1 ) ) ;
}
static int F_62 ( struct V_12 * V_13 , unsigned V_230 ,
unsigned V_231 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
if ( V_231 > V_232 )
return - V_233 ;
if ( V_231 == V_229 )
return - V_233 ;
if ( V_230 < V_234 ) {
if ( V_231 == V_211 )
return - V_233 ;
} else if ( V_230 > V_235 ) {
if ( V_231 == V_236 )
return - V_233 ;
}
V_177 -> V_210 [ V_230 ] = V_231 ;
if ( V_177 -> V_237 & ( ( ( V_238 ) 1 ) << V_230 ) )
F_61 ( V_13 , V_230 ,
V_177 -> V_210 [ V_230 ] ) ;
return 0 ;
}
static int F_63 ( struct V_12 * V_13 ,
struct V_193 * V_194 ,
struct V_214 * V_215 ,
unsigned int * V_216 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
unsigned int V_230 = F_60 ( V_215 -> V_218 ) ;
V_238 V_239 = 1ULL << V_230 ;
unsigned int V_240 ;
int V_207 ;
switch ( V_216 [ 0 ] ) {
case V_241 :
V_177 -> V_237 |= V_239 ;
F_61 ( V_13 , V_230 ,
V_177 -> V_210 [ V_230 ] ) ;
break;
case V_242 :
V_177 -> V_237 &= ~ V_239 ;
F_61 ( V_13 , V_230 , V_229 ) ;
break;
case V_243 :
V_216 [ 1 ] = ( V_177 -> V_237 & V_239 ) ? V_244
: V_196 ;
break;
case V_245 :
V_207 = F_62 ( V_13 , V_230 , V_216 [ 1 ] ) ;
if ( V_207 )
return V_207 ;
break;
case V_246 :
V_216 [ 1 ] = V_177 -> V_210 [ V_230 ] ;
break;
case V_247 :
V_240 = F_18 ( V_13 , 0 , F_1 ( V_230 ) ) ;
V_240 &= ~ F_7 ( V_230 ) ;
V_240 |= F_8 ( V_230 , V_216 [ 1 ] ) ;
F_15 ( V_13 , 0 , V_240 , F_1 ( V_230 ) ) ;
break;
default:
return - V_233 ;
}
return V_215 -> V_222 ;
}
static int F_64 ( struct V_12 * V_13 ,
unsigned long V_248 )
{
struct V_249 * V_250 = F_65 ( V_13 ) ;
const struct V_14 * V_15 = NULL ;
struct V_172 * V_177 ;
struct V_193 * V_194 ;
int V_207 ;
unsigned V_201 ;
unsigned V_251 ;
if ( V_248 < F_66 ( V_252 ) )
V_15 = & V_252 [ V_248 ] ;
if ( ! V_15 )
return - V_253 ;
V_13 -> V_16 = V_15 ;
V_13 -> V_254 = V_15 -> V_255 ;
V_207 = F_67 ( V_13 ) ;
if ( V_207 )
return V_207 ;
V_207 = F_51 ( V_13 ) ;
if ( V_207 < 0 )
return V_207 ;
V_177 = V_13 -> V_178 ;
V_177 -> V_188 = F_68 ( V_250 ) ;
if ( ! V_177 -> V_188 )
return - V_208 ;
V_207 = F_69 ( V_13 , V_177 -> V_188 , true ) ;
if ( V_207 < 0 )
return V_207 ;
V_207 = F_54 ( V_13 ) ;
if ( V_207 < 0 )
return V_207 ;
V_207 = F_70 ( V_13 , 2 + V_256 ) ;
if ( V_207 )
return V_207 ;
V_194 = & V_13 -> V_205 [ 0 ] ;
V_194 -> type = V_257 ;
V_194 = & V_13 -> V_205 [ V_258 ] ;
V_194 -> type = V_259 ;
V_194 -> V_260 = V_261 | V_262 ;
V_194 -> V_263 = V_209 ;
V_194 -> V_264 = 1 ;
V_194 -> V_265 = & V_266 ;
V_194 -> V_267 = F_59 ;
V_194 -> V_268 = F_63 ;
F_15 ( V_13 , 0 , 0 , V_269 ) ;
V_177 -> V_169 = F_71 ( V_13 ,
& F_21 ,
& F_22 ,
V_270 ,
F_12
( V_13 ) ) ;
if ( V_177 -> V_169 == NULL )
return - V_208 ;
for ( V_201 = 0 ; V_201 < V_256 ; ++ V_201 ) {
V_194 = & V_13 -> V_205 [ F_3 ( V_201 ) ] ;
if ( V_201 < F_12 ( V_13 ) ) {
V_194 -> type = V_271 ;
V_194 -> V_260 = V_261 | V_262 |
V_272 | V_273 ;
V_194 -> V_263 = 3 ;
V_194 -> V_264 = 0xffffffff ;
V_194 -> V_274 = V_275 ;
V_194 -> V_276 = V_277 ;
V_194 -> V_268 = V_278 ;
V_194 -> V_279 = & F_35 ;
V_194 -> V_280 = 1 ;
V_194 -> V_281 = V_282 ;
V_194 -> V_283 = & F_38 ;
V_194 -> V_284 = & F_46 ;
V_194 -> V_285 = V_286 ;
V_194 -> V_287 = & F_49 ;
V_194 -> V_178 = & V_177 -> V_169 -> V_288 [ V_201 ] ;
V_177 -> V_169 -> V_288 [ V_201 ] . V_170 =
V_201 / V_18 ;
V_177 -> V_169 -> V_288 [ V_201 ] . V_175 =
V_201 % V_18 ;
} else {
V_194 -> type = V_257 ;
}
}
for ( V_201 = 0 ; V_201 < V_15 -> V_17 ; ++ V_201 )
F_58 ( V_13 , V_201 ) ;
for ( V_201 = 0 ; V_201 < F_12 ( V_13 ) ; ++ V_201 )
F_72 ( & V_177 -> V_169 -> V_288 [ V_201 ] ) ;
for ( V_201 = 0 ; V_201 < V_209 ; ++ V_201 ) {
if ( V_201 < V_234 )
F_62 ( V_13 , V_201 , V_236 ) ;
else
F_62 ( V_13 , V_201 ,
V_211 ) ;
F_61 ( V_13 , V_201 , V_229 ) ;
}
for ( V_201 = 0 ; V_201 < V_15 -> V_17 ; ++ V_201 )
F_40 ( V_13 , V_201 ) ;
V_207 = F_73 ( V_250 -> V_199 , F_44 , V_289 ,
V_13 -> V_254 , V_13 ) ;
if ( V_207 < 0 ) {
F_74 ( V_13 -> V_189 , L_3 ) ;
return V_207 ;
}
V_13 -> V_199 = V_250 -> V_199 ;
V_251 = V_290 ;
if ( V_15 -> V_17 > 1 )
V_251 |= V_291 ;
F_15 ( V_13 , 0 , V_251 ,
V_292 ) ;
return 0 ;
}
static void F_75 ( struct V_12 * V_13 )
{
struct V_172 * V_177 = V_13 -> V_178 ;
if ( V_13 -> V_199 )
F_76 ( V_13 -> V_199 , V_13 ) ;
if ( V_177 ) {
if ( V_177 -> V_169 )
F_77 ( V_177 -> V_169 ) ;
F_56 ( V_13 ) ;
F_78 ( V_177 -> V_188 ) ;
}
if ( V_13 -> V_165 )
F_79 ( V_13 -> V_165 ) ;
F_80 ( V_13 ) ;
}
static int F_81 ( struct V_249 * V_13 ,
const struct V_293 * V_294 )
{
return F_82 ( V_13 , & V_295 , V_294 -> V_296 ) ;
}
