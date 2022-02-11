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
static inline unsigned F_10 ( unsigned V_11 )
{
F_2 ( V_11 >= V_12 ) ;
return V_11 ;
}
static inline unsigned F_11 ( unsigned V_9 , unsigned V_13 )
{
F_2 ( V_9 >= V_10 ) ;
return ( V_13 << ( 8 * V_9 ) ) & F_9 ( V_9 ) ;
}
static inline unsigned F_12 ( unsigned V_9 )
{
F_2 ( V_9 >= V_10 ) ;
return 0x80 << ( 8 * V_9 ) ;
}
static inline struct V_14 * F_13 ( struct V_15 * V_16 )
{
return V_16 -> F_13 ;
}
static inline const struct V_17 * F_14 ( struct V_15 * V_16 )
{
return V_16 -> V_18 ;
}
static int T_1 F_15 ( struct V_19 * V_16 ,
const struct V_20 * V_21 )
{
return F_16 ( V_16 , & V_22 ) ;
}
static void T_2 F_17 ( struct V_19 * V_16 )
{
F_18 ( V_16 ) ;
}
static inline unsigned F_19 ( struct V_15 * V_16 )
{
return F_14 ( V_16 ) -> V_23 * V_12 ;
}
static enum V_24 F_20 ( enum V_25 V_2 )
{
enum V_24 V_26 ;
switch ( V_2 ) {
case V_27 :
V_26 = V_28 ;
break;
case V_29 :
V_26 = V_30 ;
break;
case V_31 :
V_26 = V_32 ;
break;
case V_33 :
V_26 = V_34 ;
break;
case V_35 :
V_26 = V_36 ;
break;
case V_37 :
V_26 = V_38 ;
break;
case V_39 :
V_26 = V_40 ;
break;
case V_41 :
V_26 = V_42 ;
break;
case V_43 :
V_26 = V_44 ;
break;
case V_45 :
V_26 = V_46 ;
break;
case V_47 :
V_26 = V_48 ;
break;
case V_49 :
V_26 = V_50 ;
break;
case V_51 :
V_26 = V_52 ;
break;
case V_53 :
V_26 = V_54 ;
break;
case V_55 :
V_26 = V_56 ;
break;
case V_57 :
V_26 = V_58 ;
break;
case V_59 :
V_26 = V_60 ;
break;
case V_61 :
V_26 = V_62 ;
break;
case V_63 :
V_26 = V_64 ;
break;
case V_65 :
V_26 = V_66 ;
break;
case V_67 :
V_26 = V_68 ;
break;
case V_69 :
V_26 = V_70 ;
break;
case V_71 :
V_26 = V_72 ;
break;
case V_73 :
V_26 = V_74 ;
break;
case V_75 :
V_26 = V_76 ;
break;
case V_77 :
V_26 = V_78 ;
break;
case V_79 :
V_26 = V_80 ;
break;
case V_81 :
V_26 = V_82 ;
break;
case V_83 :
V_26 = V_84 ;
break;
case V_85 :
V_26 = V_86 ;
break;
case V_87 :
V_26 = V_88 ;
break;
case V_89 :
V_26 = V_90 ;
break;
case V_91 :
V_26 = V_92 ;
break;
case V_93 :
V_26 = V_94 ;
break;
case V_95 :
V_26 = V_96 ;
break;
case V_97 :
V_26 = V_98 ;
break;
case V_99 :
V_26 = V_100 ;
break;
case V_101 :
V_26 = V_102 ;
break;
case V_103 :
V_26 = V_104 ;
break;
case V_105 :
V_26 = V_106 ;
break;
case V_107 :
V_26 = V_108 ;
break;
case V_109 :
V_26 = V_110 ;
break;
case V_111 :
V_26 = V_112 ;
break;
case V_113 :
V_26 = V_114 ;
break;
case V_115 :
V_26 = V_116 ;
break;
case V_117 :
V_26 = V_118 ;
break;
case V_119 :
V_26 = V_120 ;
break;
case V_121 :
V_26 = V_122 ;
break;
case V_123 :
V_26 = V_124 ;
break;
case V_125 :
V_26 = V_126 ;
break;
case V_127 :
V_26 = V_128 ;
break;
case V_129 :
V_26 = V_130 ;
break;
case V_131 :
V_26 = V_132 ;
break;
case V_133 :
V_26 = V_134 ;
break;
case V_135 :
V_26 = V_136 ;
break;
case V_137 :
V_26 = V_138 ;
break;
case V_139 :
V_26 = V_140 ;
break;
case V_141 :
V_26 = V_142 ;
break;
case V_143 :
V_26 = V_144 ;
break;
case V_145 :
V_26 = V_146 ;
break;
case V_147 :
V_26 = V_148 ;
break;
case V_149 :
V_26 = V_150 ;
break;
case V_151 :
V_26 = V_152 ;
break;
case V_153 :
V_26 = V_154 ;
break;
case V_155 :
V_26 = V_156 ;
break;
case V_157 :
V_26 = V_158 ;
break;
case V_159 :
V_26 = V_160 ;
break;
case V_161 :
V_26 = V_162 ;
break;
default:
F_21 () ;
return 0 ;
break;
}
return V_26 ;
}
static inline void F_22 ( struct V_15 * V_16 ,
unsigned V_163 , unsigned V_164 ,
enum V_24 V_2 )
{
void T_3 * V_165 =
F_13 ( V_16 ) -> V_166 -> V_167 + V_168 [ V_163 ] +
V_169 [ V_2 ] . V_170 ;
switch ( V_169 [ V_2 ] . V_171 ) {
case V_172 :
F_23 ( V_164 , V_165 ) ;
break;
case V_173 :
F_24 ( V_164 , V_165 ) ;
break;
default:
F_21 () ;
break;
}
}
static inline unsigned F_25 ( struct V_15 * V_16 ,
unsigned V_163 ,
enum V_24 V_2 )
{
void T_3 * V_174 =
F_13 ( V_16 ) -> V_166 -> V_167 + V_168 [ V_163 ] +
V_169 [ V_2 ] . V_170 ;
switch ( V_169 [ V_2 ] . V_171 ) {
case V_172 :
return F_26 ( V_174 ) ;
break;
case V_173 :
return F_27 ( V_174 ) ;
break;
default:
F_21 () ;
break;
}
return 0 ;
}
static void F_28 ( struct V_175 * V_176 , unsigned V_164 ,
enum V_25 V_2 )
{
struct V_15 * V_16 = V_176 -> V_177 -> V_16 ;
enum V_24 V_26 = F_20 ( V_2 ) ;
F_22 ( V_16 , V_176 -> V_163 , V_164 ,
V_26 ) ;
}
static unsigned F_29 ( struct V_175 * V_176 ,
enum V_25 V_2 )
{
struct V_15 * V_16 = V_176 -> V_177 -> V_16 ;
enum V_24 V_26 = F_20 ( V_2 ) ;
return F_25 ( V_16 , V_176 -> V_163 ,
V_26 ) ;
}
static inline struct V_178 * F_30 ( struct V_14
* V_179 ,
struct V_175
* V_176 )
{
return V_179 -> V_180 [ V_176 -> V_163 ] [ V_176 -> V_11 ] ;
}
static inline void F_31 ( struct V_15 * V_16 ,
unsigned V_181 ,
struct V_175 * V_176 )
{
unsigned long V_182 ;
F_32 ( & F_13 ( V_16 ) -> V_183 , V_182 ) ;
F_13 ( V_16 ) -> V_184 [ V_176 -> V_163 ] &=
~ F_9 ( V_181 ) ;
F_13 ( V_16 ) -> V_184 [ V_176 -> V_163 ] |=
F_11 ( V_181 ,
F_10 ( V_176 -> V_11 ) ) ;
F_22 ( V_16 , V_176 -> V_163 ,
F_13 ( V_16 ) ->
V_184
[ V_176 -> V_163 ] |
F_12 ( V_181 ) , V_185 ) ;
F_33 () ;
F_34 ( & F_13 ( V_16 ) -> V_183 , V_182 ) ;
}
static inline void F_35 ( struct V_15 * V_16 ,
unsigned V_181 ,
struct V_175 * V_176 )
{
unsigned long V_182 ;
F_32 ( & F_13 ( V_16 ) -> V_183 , V_182 ) ;
F_13 ( V_16 ) -> V_184 [ V_176 -> V_163 ] &=
~ F_9 ( V_181 ) ;
F_13 ( V_16 ) -> V_184 [ V_176 -> V_163 ] |=
F_11 ( V_181 , V_186 ) ;
F_22 ( V_16 , V_176 -> V_163 ,
F_13 ( V_16 ) ->
V_184
[ V_176 -> V_163 ] , V_185 ) ;
F_33 () ;
F_34 ( & F_13 ( V_16 ) -> V_183 , V_182 ) ;
}
static int F_36 ( struct V_15 * V_16 ,
struct V_175 * V_176 ,
enum V_187 V_188 )
{
unsigned long V_182 ;
struct V_181 * V_189 ;
F_32 ( & F_13 ( V_16 ) -> V_190 , V_182 ) ;
F_2 ( V_176 -> V_189 ) ;
V_189 =
F_37 ( F_13 ( V_16 ) -> V_166 , F_30 ( F_13 ( V_16 ) ,
V_176 ) ) ;
if ( V_189 == NULL ) {
F_34 ( & F_13 ( V_16 ) -> V_190 , V_182 ) ;
F_38 ( V_16 ,
L_1 ) ;
return - V_191 ;
}
V_189 -> V_192 = V_188 ;
F_39 ( V_176 , V_189 ) ;
F_31 ( V_16 , V_189 -> V_193 , V_176 ) ;
F_34 ( & F_13 ( V_16 ) -> V_190 , V_182 ) ;
return 0 ;
}
static void F_40 ( struct V_15 * V_16 ,
struct V_175 * V_176 )
{
unsigned long V_182 ;
F_32 ( & F_13 ( V_16 ) -> V_190 , V_182 ) ;
if ( V_176 -> V_189 ) {
struct V_181 * V_189 = V_176 -> V_189 ;
F_35 ( V_16 , V_189 -> V_193 , V_176 ) ;
F_39 ( V_176 , NULL ) ;
F_41 ( V_189 ) ;
}
F_34 ( & F_13 ( V_16 ) -> V_190 , V_182 ) ;
}
static int F_42 ( struct V_15 * V_16 , struct V_194 * V_195 )
{
int V_196 ;
struct V_175 * V_176 = F_43 ( V_195 ) ;
V_196 = F_36 ( V_16 , V_176 , V_197 ) ;
if ( V_196 ) {
F_38 ( V_16 ,
L_2 ) ;
return V_196 ;
}
F_44 ( V_176 , NULL , NULL , NULL , NULL ) ;
V_196 = F_45 ( V_176 , V_195 -> V_198 ) ;
return V_196 ;
}
static int F_46 ( struct V_15 * V_16 ,
struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_175 * V_176 = F_43 ( V_195 ) ;
return F_47 ( V_176 , V_200 ) ;
}
static int F_48 ( struct V_15 * V_16 , struct V_194 * V_195 )
{
struct V_175 * V_176 = F_43 ( V_195 ) ;
int V_196 ;
V_196 = F_49 ( V_176 ) ;
F_40 ( V_16 , V_176 ) ;
return V_196 ;
}
static void F_50 ( struct V_15 * V_16 , int V_201 )
{
if ( V_201 )
F_22 ( V_16 , V_201 , V_202 ,
V_203 ) ;
else
F_22 ( V_16 , V_201 , 0 , V_203 ) ;
}
static void F_51 ( struct V_15 * V_16 ,
struct V_194 * V_195 )
{
F_52 ( F_43 ( V_195 ) , V_195 ) ;
if ( V_195 -> V_198 -> V_204 ) {
if ( V_195 -> V_198 -> V_204 & ( V_205 | V_206 |
V_207 ) ) {
F_48 ( V_16 , V_195 ) ;
}
F_53 ( V_16 , V_195 ) ;
}
}
static T_4 F_54 ( int V_208 , void * V_209 )
{
struct V_15 * V_16 = V_209 ;
struct V_194 * V_195 ;
unsigned V_210 ;
unsigned long V_182 ;
if ( V_16 -> V_211 == 0 )
return V_212 ;
F_32 ( & F_13 ( V_16 ) -> V_213 , V_182 ) ;
F_55 () ;
for ( V_210 = 0 ; V_210 < F_19 ( V_16 ) ; ++ V_210 ) {
V_195 = & V_16 -> V_214 [ F_3 ( V_210 ) ] ;
F_51 ( V_16 , V_195 ) ;
}
F_34 ( & F_13 ( V_16 ) -> V_213 , V_182 ) ;
return V_215 ;
}
static int F_56 ( struct V_15 * V_16 ,
struct V_194 * V_195 )
{
unsigned long V_182 ;
F_32 ( & F_13 ( V_16 ) -> V_213 , V_182 ) ;
F_57 ( F_43 ( V_195 ) -> V_189 , V_195 -> V_198 ) ;
F_34 ( & F_13 ( V_16 ) -> V_213 , V_182 ) ;
return F_58 ( V_195 -> V_198 ) ;
}
static int F_59 ( struct V_15 * V_16 ,
struct V_194 * V_195 ,
unsigned long V_216 )
{
int V_217 ;
V_217 = F_60 ( F_30 ( F_13 ( V_16 ) , F_43 ( V_195 ) ) ,
V_195 -> V_198 ) ;
if ( V_217 < 0 )
return V_217 ;
return 0 ;
}
static int F_61 ( struct V_15 * V_16 )
{
int V_196 ;
unsigned V_210 ;
V_196 = F_62 ( V_16 , sizeof( struct V_14 ) ) ;
if ( V_196 < 0 )
return V_196 ;
F_63 ( & F_13 ( V_16 ) -> V_190 ) ;
F_63 ( & F_13 ( V_16 ) -> V_213 ) ;
F_63 ( & F_13 ( V_16 ) -> V_183 ) ;
for ( V_210 = 0 ; V_210 < V_218 ; ++ V_210 )
F_13 ( V_16 ) -> V_219 [ V_210 ] = V_220 ;
return 0 ;
}
static int F_64 ( struct V_15 * V_16 )
{
unsigned V_210 ;
unsigned V_221 ;
for ( V_210 = 0 ; V_210 < F_14 ( V_16 ) -> V_23 ; ++ V_210 ) {
for ( V_221 = 0 ; V_221 < V_12 ; ++ V_221 ) {
F_13 ( V_16 ) -> V_180 [ V_210 ] [ V_221 ] =
F_65 ( F_13 ( V_16 ) -> V_166 ) ;
if ( F_13 ( V_16 ) -> V_180 [ V_210 ] [ V_221 ] == NULL )
return - V_222 ;
}
}
return 0 ;
}
static void F_66 ( struct V_15 * V_16 )
{
unsigned V_210 ;
unsigned V_221 ;
for ( V_210 = 0 ; V_210 < F_14 ( V_16 ) -> V_23 ; ++ V_210 ) {
for ( V_221 = 0 ; V_221 < V_12 ; ++ V_221 )
F_67 ( F_13 ( V_16 ) -> V_180 [ V_210 ] [ V_221 ] ) ;
}
}
static const struct V_17 *
F_68 ( struct V_19 * V_223 )
{
unsigned int V_224 = V_223 -> V_225 ;
unsigned int V_226 ;
for ( V_226 = 0 ; V_226 < F_69 ( V_227 ) ; V_226 ++ ) {
const struct V_17 * F_14 = & V_227 [ V_226 ] ;
if ( F_14 -> V_224 == V_224 )
return F_14 ;
}
return NULL ;
}
static int T_1 F_70 ( struct V_15 * V_16 ,
struct V_19 * V_223 )
{
struct V_194 * V_195 ;
int V_217 ;
unsigned V_210 ;
unsigned V_228 ;
V_217 = F_61 ( V_16 ) ;
if ( V_217 < 0 )
return V_217 ;
V_16 -> V_18 = F_68 ( V_223 ) ;
if ( ! V_16 -> V_18 )
return - V_229 ;
F_13 ( V_16 ) -> V_166 = F_71 ( V_223 ) ;
if ( ! F_13 ( V_16 ) -> V_166 )
return - V_222 ;
V_16 -> V_230 = F_14 ( V_16 ) -> V_231 ;
V_217 = F_72 ( F_13 ( V_16 ) -> V_166 , 1 ) ;
if ( V_217 < 0 ) {
F_73 ( V_16 -> V_232 , L_3 ) ;
return V_217 ;
}
F_74 ( V_16 , & F_13 ( V_16 ) -> V_166 -> V_223 -> V_16 ) ;
V_217 = F_64 ( V_16 ) ;
if ( V_217 < 0 )
return V_217 ;
V_217 = F_75 ( V_16 , 2 + V_233 ) ;
if ( V_217 )
return V_217 ;
V_195 = & V_16 -> V_214 [ 0 ] ;
V_195 -> type = V_234 ;
V_195 = & V_16 -> V_214 [ V_235 ] ;
V_195 -> type = V_236 ;
V_195 -> V_237 = V_238 | V_239 ;
V_195 -> V_240 = V_218 ;
V_195 -> V_241 = 1 ;
V_195 -> V_242 = & V_243 ;
V_195 -> V_244 = V_245 ;
V_195 -> V_246 = V_247 ;
V_195 -> V_248 = 0 ;
F_22 ( V_16 , 0 , 0 , V_249 ) ;
F_13 ( V_16 ) -> V_177 = F_76 ( V_16 ,
& F_28 ,
& F_29 ,
V_250 ,
F_19
( V_16 ) ) ;
if ( F_13 ( V_16 ) -> V_177 == NULL )
return - V_222 ;
for ( V_210 = 0 ; V_210 < V_233 ; ++ V_210 ) {
V_195 = & V_16 -> V_214 [ F_3 ( V_210 ) ] ;
if ( V_210 < F_19 ( V_16 ) ) {
V_195 -> type = V_251 ;
V_195 -> V_237 =
V_238 | V_239 | V_252 |
V_253 ;
V_195 -> V_240 = 3 ;
V_195 -> V_241 = 0xffffffff ;
V_195 -> V_254 = V_255 ;
V_195 -> V_256 = V_257 ;
V_195 -> V_246 = V_258 ;
V_195 -> V_259 = & F_42 ;
V_195 -> V_260 = 1 ;
V_195 -> V_261 = & F_46 ;
V_195 -> V_262 = & F_48 ;
V_195 -> V_263 = & F_56 ;
V_195 -> V_264 = V_265 ;
V_195 -> V_266 = & F_59 ;
V_195 -> F_13 = & F_13 ( V_16 ) -> V_177 -> V_267 [ V_210 ] ;
F_13 ( V_16 ) -> V_177 -> V_267 [ V_210 ] . V_163 =
V_210 / V_12 ;
F_13 ( V_16 ) -> V_177 -> V_267 [ V_210 ] . V_11 =
V_210 % V_12 ;
} else {
V_195 -> type = V_234 ;
}
}
for ( V_210 = 0 ; V_210 < F_14 ( V_16 ) -> V_23 ; ++ V_210 )
F_77 ( V_16 , V_210 ) ;
for ( V_210 = 0 ; V_210 < F_19 ( V_16 ) ; ++ V_210 )
F_78 ( & F_13 ( V_16 ) -> V_177 -> V_267 [ V_210 ] ) ;
for ( V_210 = 0 ; V_210 < V_218 ; ++ V_210 ) {
if ( V_210 < V_268 )
F_79 ( V_16 , V_210 , V_269 ) ;
else
F_79 ( V_16 , V_210 ,
V_220 ) ;
F_80 ( V_16 , V_210 , V_270 ) ;
}
for ( V_210 = 0 ; V_210 < F_14 ( V_16 ) -> V_23 ; ++ V_210 )
F_50 ( V_16 , V_210 ) ;
V_217 = F_81 ( F_82 ( F_13 ( V_16 ) -> V_166 ) , F_54 ,
V_271 , L_4 , V_16 ) ;
if ( V_217 < 0 ) {
F_73 ( V_16 -> V_232 , L_5 ) ;
return V_217 ;
}
V_16 -> V_208 = F_82 ( F_13 ( V_16 ) -> V_166 ) ;
V_228 = V_272 ;
if ( F_14 ( V_16 ) -> V_23 > 1 )
V_228 |= V_273 ;
F_22 ( V_16 , 0 , V_228 ,
V_274 ) ;
F_83 ( V_16 -> V_232 , L_6 , V_16 -> V_230 ) ;
return 0 ;
}
static void F_84 ( struct V_15 * V_16 )
{
if ( V_16 -> V_208 )
F_85 ( V_16 -> V_208 , V_16 ) ;
if ( V_16 -> F_13 ) {
if ( F_13 ( V_16 ) -> V_177 )
F_86 ( F_13 ( V_16 ) -> V_177 ) ;
if ( F_13 ( V_16 ) -> V_166 ) {
F_66 ( V_16 ) ;
F_87 ( F_13 ( V_16 ) -> V_166 ) ;
F_88 ( F_13 ( V_16 ) -> V_166 ) ;
}
}
}
static int
V_255 ( struct V_15 * V_16 , struct V_194 * V_195 ,
struct V_275 * V_276 , unsigned int * V_277 )
{
return F_89 ( F_43 ( V_195 ) , V_276 , V_277 ) ;
}
static void F_77 ( struct V_15 * V_16 , int V_201 )
{
unsigned V_210 ;
F_13 ( V_16 ) -> V_184 [ V_201 ] = 0 ;
for ( V_210 = 0 ; V_210 < V_10 ; ++ V_210 ) {
F_13 ( V_16 ) -> V_184 [ V_201 ] |=
F_11 ( V_210 , V_186 ) & F_9 ( V_210 ) ;
}
F_22 ( V_16 , V_201 ,
F_13 ( V_16 ) ->
V_184 [ V_201 ] ,
V_185 ) ;
for ( V_210 = 0 ; V_210 < V_218 ; ++ V_210 )
F_22 ( V_16 , V_201 , 0 , F_1 ( V_210 ) ) ;
}
static int
V_258 ( struct V_15 * V_16 , struct V_194 * V_195 ,
struct V_275 * V_276 , unsigned int * V_277 )
{
return F_90 ( F_43 ( V_195 ) , V_276 , V_277 ) ;
}
static int V_257 ( struct V_15 * V_16 ,
struct V_194 * V_195 ,
struct V_275 * V_276 , unsigned int * V_277 )
{
return F_91 ( F_43 ( V_195 ) , V_276 , V_277 ) ;
}
static int V_245 ( struct V_15 * V_16 ,
struct V_194 * V_195 ,
struct V_275 * V_276 , unsigned int * V_277 )
{
unsigned V_278 = F_92 ( V_276 -> V_279 ) ;
if ( V_277 [ 0 ] ) {
V_195 -> V_280 &= ~ ( V_277 [ 0 ] << V_278 ) ;
V_195 -> V_280 |= ( V_277 [ 0 ] & V_277 [ 1 ] ) << V_278 ;
F_22 ( V_16 , 0 , V_195 -> V_280 , V_281 ) ;
}
V_277 [ 1 ] =
( F_25 ( V_16 , 0 ,
V_282 ) >> V_278 ) ;
return V_276 -> V_226 ;
}
static void F_80 ( struct V_15 * V_16 ,
unsigned V_1 ,
unsigned V_7 )
{
static const unsigned V_283 = 8 ;
static const unsigned V_284 = 23 ;
unsigned V_285 = 0 ;
unsigned V_286 = 0 ;
unsigned V_287 ;
unsigned V_288 ;
if ( F_14 ( V_16 ) -> V_23 > 1 ) {
if ( V_7 == V_220 &&
V_1 >= V_283 &&
V_1 <= V_284 ) {
V_285 = 1 ;
V_286 = 0 ;
} else {
V_285 = 0 ;
V_286 = 1 ;
}
}
if ( V_286 != V_285 ) {
V_288 =
F_25 ( V_16 , V_286 ,
F_1 ( V_1 ) ) ;
V_288 &= ~ F_5 ( V_1 ) ;
V_288 |=
F_6 ( V_1 ,
V_270 ) ;
F_22 ( V_16 , V_286 , V_288 ,
F_1 ( V_1 ) ) ;
}
V_287 =
F_25 ( V_16 , V_285 ,
F_1 ( V_1 ) ) ;
V_287 &= ~ F_5 ( V_1 ) ;
V_287 |= F_6 ( V_1 , V_7 ) ;
F_22 ( V_16 , V_285 , V_287 ,
F_1 ( V_1 ) ) ;
}
static int F_79 ( struct V_15 * V_16 , unsigned V_289 ,
unsigned V_290 )
{
if ( V_290 > V_291 )
return - V_292 ;
if ( V_290 == V_270 )
return - V_292 ;
if ( V_289 < V_268 ) {
if ( V_290 == V_220 )
return - V_292 ;
} else if ( V_289 > V_293 ) {
if ( V_290 == V_269 )
return - V_292 ;
}
F_2 ( V_289 >= V_218 ) ;
F_13 ( V_16 ) -> V_219 [ V_289 ] = V_290 ;
if ( F_13 ( V_16 ) -> V_294 & ( ( ( V_295 ) 1 ) << V_289 ) )
F_80 ( V_16 , V_289 ,
F_13 ( V_16 ) ->
V_219 [ V_289 ] ) ;
return 0 ;
}
static unsigned F_93 ( struct V_15 * V_16 ,
unsigned V_289 )
{
F_2 ( V_289 >= V_218 ) ;
return F_13 ( V_16 ) -> V_219 [ V_289 ] ;
}
static void F_94 ( struct V_15 * V_16 ,
unsigned V_1 ,
enum V_296 V_297 )
{
unsigned V_164 = F_25 ( V_16 , 0 , F_1 ( V_1 ) ) ;
V_164 &= ~ F_7 ( V_1 ) ;
V_164 |= F_8 ( V_1 , V_297 ) ;
F_22 ( V_16 , 0 , V_164 , F_1 ( V_1 ) ) ;
}
static int V_247 ( struct V_15 * V_16 ,
struct V_194 * V_195 ,
struct V_275 * V_276 , unsigned int * V_277 )
{
int V_289 = F_92 ( V_276 -> V_279 ) ;
switch ( V_277 [ 0 ] ) {
case V_298 :
F_13 ( V_16 ) -> V_294 |= ( ( V_295 ) 1 ) << V_289 ;
F_80 ( V_16 , V_289 ,
F_13 ( V_16 ) ->
V_219 [ V_289 ] ) ;
break;
case V_299 :
F_13 ( V_16 ) -> V_294 &= ~ ( ( ( V_295 ) 1 ) << V_289 ) ;
F_80 ( V_16 , V_289 , V_270 ) ;
break;
case V_300 :
V_277 [ 1 ] =
( F_13 ( V_16 ) -> V_294 &
( ( ( V_295 ) 1 ) << V_289 ) ) ? V_301 : V_197 ;
return 0 ;
case V_302 :
return F_79 ( V_16 , V_289 , V_277 [ 1 ] ) ;
break;
case V_303 :
V_277 [ 1 ] = F_93 ( V_16 , V_289 ) ;
break;
case V_304 :
F_94 ( V_16 , V_289 , V_277 [ 1 ] ) ;
break;
default:
return - V_292 ;
break;
}
return 0 ;
}
