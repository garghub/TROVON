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
static int T_3 F_19 ( void )
{
int V_23 ;
V_23 = F_20 ( & V_22 ) ;
if ( V_23 < 0 )
return V_23 ;
V_24 . V_25 = ( char * ) V_22 . V_26 ;
return F_21 ( & V_24 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_24 ) ;
F_24 ( & V_22 ) ;
}
static inline unsigned F_25 ( struct V_15 * V_16 )
{
return F_14 ( V_16 ) -> V_27 * V_12 ;
}
static enum V_28 F_26 ( enum V_29 V_2 )
{
enum V_28 V_30 ;
switch ( V_2 ) {
case V_31 :
V_30 = V_32 ;
break;
case V_33 :
V_30 = V_34 ;
break;
case V_35 :
V_30 = V_36 ;
break;
case V_37 :
V_30 = V_38 ;
break;
case V_39 :
V_30 = V_40 ;
break;
case V_41 :
V_30 = V_42 ;
break;
case V_43 :
V_30 = V_44 ;
break;
case V_45 :
V_30 = V_46 ;
break;
case V_47 :
V_30 = V_48 ;
break;
case V_49 :
V_30 = V_50 ;
break;
case V_51 :
V_30 = V_52 ;
break;
case V_53 :
V_30 = V_54 ;
break;
case V_55 :
V_30 = V_56 ;
break;
case V_57 :
V_30 = V_58 ;
break;
case V_59 :
V_30 = V_60 ;
break;
case V_61 :
V_30 = V_62 ;
break;
case V_63 :
V_30 = V_64 ;
break;
case V_65 :
V_30 = V_66 ;
break;
case V_67 :
V_30 = V_68 ;
break;
case V_69 :
V_30 = V_70 ;
break;
case V_71 :
V_30 = V_72 ;
break;
case V_73 :
V_30 = V_74 ;
break;
case V_75 :
V_30 = V_76 ;
break;
case V_77 :
V_30 = V_78 ;
break;
case V_79 :
V_30 = V_80 ;
break;
case V_81 :
V_30 = V_82 ;
break;
case V_83 :
V_30 = V_84 ;
break;
case V_85 :
V_30 = V_86 ;
break;
case V_87 :
V_30 = V_88 ;
break;
case V_89 :
V_30 = V_90 ;
break;
case V_91 :
V_30 = V_92 ;
break;
case V_93 :
V_30 = V_94 ;
break;
case V_95 :
V_30 = V_96 ;
break;
case V_97 :
V_30 = V_98 ;
break;
case V_99 :
V_30 = V_100 ;
break;
case V_101 :
V_30 = V_102 ;
break;
case V_103 :
V_30 = V_104 ;
break;
case V_105 :
V_30 = V_106 ;
break;
case V_107 :
V_30 = V_108 ;
break;
case V_109 :
V_30 = V_110 ;
break;
case V_111 :
V_30 = V_112 ;
break;
case V_113 :
V_30 = V_114 ;
break;
case V_115 :
V_30 = V_116 ;
break;
case V_117 :
V_30 = V_118 ;
break;
case V_119 :
V_30 = V_120 ;
break;
case V_121 :
V_30 = V_122 ;
break;
case V_123 :
V_30 = V_124 ;
break;
case V_125 :
V_30 = V_126 ;
break;
case V_127 :
V_30 = V_128 ;
break;
case V_129 :
V_30 = V_130 ;
break;
case V_131 :
V_30 = V_132 ;
break;
case V_133 :
V_30 = V_134 ;
break;
case V_135 :
V_30 = V_136 ;
break;
case V_137 :
V_30 = V_138 ;
break;
case V_139 :
V_30 = V_140 ;
break;
case V_141 :
V_30 = V_142 ;
break;
case V_143 :
V_30 = V_144 ;
break;
case V_145 :
V_30 = V_146 ;
break;
case V_147 :
V_30 = V_148 ;
break;
case V_149 :
V_30 = V_150 ;
break;
case V_151 :
V_30 = V_152 ;
break;
case V_153 :
V_30 = V_154 ;
break;
case V_155 :
V_30 = V_156 ;
break;
case V_157 :
V_30 = V_158 ;
break;
case V_159 :
V_30 = V_160 ;
break;
case V_161 :
V_30 = V_162 ;
break;
case V_163 :
V_30 = V_164 ;
break;
case V_165 :
V_30 = V_166 ;
break;
default:
F_27 ( V_167 L_1 ,
V_168 , V_2 ) ;
F_28 () ;
return 0 ;
break;
}
return V_30 ;
}
static inline void F_29 ( struct V_15 * V_16 ,
unsigned V_169 , unsigned V_170 ,
enum V_28 V_2 )
{
void T_5 * V_171 =
F_13 ( V_16 ) -> V_172 -> V_173 + V_174 [ V_169 ] +
V_175 [ V_2 ] . V_176 ;
switch ( V_175 [ V_2 ] . V_177 ) {
case V_178 :
F_30 ( V_170 , V_171 ) ;
break;
case V_179 :
F_31 ( V_170 , V_171 ) ;
break;
default:
F_27 ( V_167 L_2 ,
__FILE__ , V_168 , V_2 ) ;
F_28 () ;
break;
}
}
static inline unsigned F_32 ( struct V_15 * V_16 ,
unsigned V_169 ,
enum V_28 V_2 )
{
void T_5 * V_180 =
F_13 ( V_16 ) -> V_172 -> V_173 + V_174 [ V_169 ] +
V_175 [ V_2 ] . V_176 ;
switch ( V_175 [ V_2 ] . V_177 ) {
case V_178 :
return F_33 ( V_180 ) ;
break;
case V_179 :
return F_34 ( V_180 ) ;
break;
default:
F_27 ( V_167 L_2 ,
__FILE__ , V_168 , V_2 ) ;
F_28 () ;
break;
}
return 0 ;
}
static void F_35 ( struct V_181 * V_182 , unsigned V_170 ,
enum V_29 V_2 )
{
struct V_15 * V_16 = V_182 -> V_183 -> V_16 ;
enum V_28 V_30 = F_26 ( V_2 ) ;
F_29 ( V_16 , V_182 -> V_169 , V_170 ,
V_30 ) ;
}
static unsigned F_36 ( struct V_181 * V_182 ,
enum V_29 V_2 )
{
struct V_15 * V_16 = V_182 -> V_183 -> V_16 ;
enum V_28 V_30 = F_26 ( V_2 ) ;
return F_32 ( V_16 , V_182 -> V_169 ,
V_30 ) ;
}
static inline struct V_184 * F_37 ( struct V_14
* V_185 ,
struct V_181
* V_182 )
{
return V_185 -> V_186 [ V_182 -> V_169 ] [ V_182 -> V_11 ] ;
}
static inline void F_38 ( struct V_15 * V_16 ,
unsigned V_187 ,
struct V_181 * V_182 )
{
unsigned long V_188 ;
F_39 ( & F_13 ( V_16 ) -> V_189 , V_188 ) ;
F_13 ( V_16 ) -> V_190 [ V_182 -> V_169 ] &=
~ F_9 ( V_187 ) ;
F_13 ( V_16 ) -> V_190 [ V_182 -> V_169 ] |=
F_11 ( V_187 ,
F_10 ( V_182 -> V_11 ) ) ;
F_29 ( V_16 , V_182 -> V_169 ,
F_13 ( V_16 ) ->
V_190
[ V_182 -> V_169 ] |
F_12 ( V_187 ) , V_191 ) ;
F_40 () ;
F_41 ( & F_13 ( V_16 ) -> V_189 , V_188 ) ;
}
static inline void F_42 ( struct V_15 * V_16 ,
unsigned V_187 ,
struct V_181 * V_182 )
{
unsigned long V_188 ;
F_39 ( & F_13 ( V_16 ) -> V_189 , V_188 ) ;
F_13 ( V_16 ) -> V_190 [ V_182 -> V_169 ] &=
~ F_9 ( V_187 ) ;
F_13 ( V_16 ) -> V_190 [ V_182 -> V_169 ] |=
F_11 ( V_187 , V_192 ) ;
F_29 ( V_16 , V_182 -> V_169 ,
F_13 ( V_16 ) ->
V_190
[ V_182 -> V_169 ] , V_191 ) ;
F_40 () ;
F_41 ( & F_13 ( V_16 ) -> V_189 , V_188 ) ;
}
static int F_43 ( struct V_15 * V_16 ,
struct V_181 * V_182 ,
enum V_193 V_194 )
{
unsigned long V_188 ;
struct V_187 * V_195 ;
F_39 ( & F_13 ( V_16 ) -> V_196 , V_188 ) ;
F_2 ( V_182 -> V_195 ) ;
V_195 =
F_44 ( F_13 ( V_16 ) -> V_172 , F_37 ( F_13 ( V_16 ) ,
V_182 ) ) ;
if ( V_195 == NULL ) {
F_41 ( & F_13 ( V_16 ) -> V_196 , V_188 ) ;
F_45 ( V_16 ,
L_3 ) ;
return - V_197 ;
}
V_195 -> V_198 = V_194 ;
F_46 ( V_182 , V_195 ) ;
F_38 ( V_16 , V_195 -> V_199 , V_182 ) ;
F_41 ( & F_13 ( V_16 ) -> V_196 , V_188 ) ;
return 0 ;
}
void F_47 ( struct V_15 * V_16 ,
struct V_181 * V_182 )
{
unsigned long V_188 ;
F_39 ( & F_13 ( V_16 ) -> V_196 , V_188 ) ;
if ( V_182 -> V_195 ) {
struct V_187 * V_195 = V_182 -> V_195 ;
F_42 ( V_16 , V_195 -> V_199 , V_182 ) ;
F_46 ( V_182 , NULL ) ;
F_48 ( V_195 ) ;
}
F_41 ( & F_13 ( V_16 ) -> V_196 , V_188 ) ;
}
static int F_49 ( struct V_15 * V_16 , struct V_200 * V_201 )
{
int V_23 ;
struct V_181 * V_182 = F_50 ( V_201 ) ;
V_23 = F_43 ( V_16 , V_182 , V_202 ) ;
if ( V_23 ) {
F_45 ( V_16 ,
L_4 ) ;
return V_23 ;
}
F_51 ( V_182 , NULL , NULL , NULL , NULL ) ;
V_23 = F_52 ( V_182 , V_201 -> V_203 ) ;
return V_23 ;
}
static int F_53 ( struct V_15 * V_16 ,
struct V_200 * V_201 , struct V_204 * V_205 )
{
struct V_181 * V_182 = F_50 ( V_201 ) ;
return F_54 ( V_182 , V_205 ) ;
}
static int F_55 ( struct V_15 * V_16 , struct V_200 * V_201 )
{
struct V_181 * V_182 = F_50 ( V_201 ) ;
int V_23 ;
V_23 = F_56 ( V_182 ) ;
F_47 ( V_16 , V_182 ) ;
return V_23 ;
}
static void F_57 ( struct V_15 * V_16 , int V_206 )
{
if ( V_206 )
F_29 ( V_16 , V_206 , V_207 ,
V_208 ) ;
else
F_29 ( V_16 , V_206 , 0 , V_208 ) ;
}
static void F_58 ( struct V_15 * V_16 ,
struct V_200 * V_201 )
{
F_59 ( F_50 ( V_201 ) , V_201 ) ;
if ( V_201 -> V_203 -> V_209 ) {
if ( V_201 -> V_203 -> V_209 & ( V_210 | V_211 |
V_212 ) ) {
F_55 ( V_16 , V_201 ) ;
}
F_60 ( V_16 , V_201 ) ;
}
}
static T_6 F_61 ( int V_213 , void * V_214 )
{
struct V_15 * V_16 = V_214 ;
struct V_200 * V_201 ;
unsigned V_215 ;
unsigned long V_188 ;
if ( V_16 -> V_216 == 0 )
return V_217 ;
F_39 ( & F_13 ( V_16 ) -> V_218 , V_188 ) ;
F_62 () ;
for ( V_215 = 0 ; V_215 < F_25 ( V_16 ) ; ++ V_215 ) {
V_201 = V_16 -> V_219 + F_3 ( V_215 ) ;
F_58 ( V_16 , V_201 ) ;
}
F_41 ( & F_13 ( V_16 ) -> V_218 , V_188 ) ;
return V_220 ;
}
static int F_63 ( struct V_15 * V_16 ,
struct V_200 * V_201 )
{
unsigned long V_188 ;
F_39 ( & F_13 ( V_16 ) -> V_218 , V_188 ) ;
F_64 ( F_50 ( V_201 ) -> V_195 , V_201 -> V_203 ) ;
F_41 ( & F_13 ( V_16 ) -> V_218 , V_188 ) ;
return F_65 ( V_201 -> V_203 ) ;
}
static int F_66 ( struct V_15 * V_16 ,
struct V_200 * V_201 ,
unsigned long V_221 )
{
int V_222 ;
V_222 = F_67 ( F_37 ( F_13 ( V_16 ) , F_50 ( V_201 ) ) ,
V_201 -> V_203 ) ;
if ( V_222 < 0 )
return V_222 ;
return 0 ;
}
static int F_68 ( struct V_15 * V_16 )
{
int V_23 ;
unsigned V_215 ;
V_23 = F_69 ( V_16 , sizeof( struct V_14 ) ) ;
if ( V_23 < 0 )
return V_23 ;
F_70 ( & F_13 ( V_16 ) -> V_196 ) ;
F_70 ( & F_13 ( V_16 ) -> V_218 ) ;
F_70 ( & F_13 ( V_16 ) -> V_189 ) ;
for ( V_215 = 0 ; V_215 < V_223 ; ++ V_215 )
F_13 ( V_16 ) -> V_224 [ V_215 ] = V_225 ;
return 0 ;
}
static int F_71 ( struct V_15 * V_16 )
{
unsigned V_215 ;
unsigned V_226 ;
for ( V_215 = 0 ; V_215 < F_14 ( V_16 ) -> V_27 ; ++ V_215 ) {
for ( V_226 = 0 ; V_226 < V_12 ; ++ V_226 ) {
F_13 ( V_16 ) -> V_186 [ V_215 ] [ V_226 ] =
F_72 ( F_13 ( V_16 ) -> V_172 ) ;
if ( F_13 ( V_16 ) -> V_186 [ V_215 ] [ V_226 ] == NULL )
return - V_227 ;
}
}
return 0 ;
}
static void F_73 ( struct V_15 * V_16 )
{
unsigned V_215 ;
unsigned V_226 ;
for ( V_215 = 0 ; V_215 < F_14 ( V_16 ) -> V_27 ; ++ V_215 ) {
for ( V_226 = 0 ; V_226 < V_12 ; ++ V_226 )
F_74 ( F_13 ( V_16 ) -> V_186 [ V_215 ] [ V_226 ] ) ;
}
}
static int F_75 ( struct V_15 * V_16 ,
struct V_228 * V_229 )
{
struct V_200 * V_201 ;
int V_222 ;
unsigned V_215 ;
unsigned V_230 ;
F_27 ( V_231 L_5 , V_16 -> V_232 ) ;
V_222 = F_68 ( V_16 ) ;
if ( V_222 < 0 )
return V_222 ;
V_222 = F_76 ( V_16 , V_229 -> V_233 [ 0 ] , V_229 -> V_233 [ 1 ] ) ;
if ( V_222 < 0 )
return V_222 ;
V_16 -> V_234 = F_14 ( V_16 ) -> V_25 ;
V_222 = F_77 ( F_13 ( V_16 ) -> V_172 , 1 ) ;
if ( V_222 < 0 ) {
F_27 ( V_167 L_6 ) ;
return V_222 ;
}
F_78 ( V_16 , & F_13 ( V_16 ) -> V_172 -> V_235 -> V_16 ) ;
V_222 = F_71 ( V_16 ) ;
if ( V_222 < 0 )
return V_222 ;
F_27 ( V_231 L_7 , V_16 -> V_234 ) ;
V_16 -> V_236 = 2 + V_237 ;
if ( F_79 ( V_16 , V_16 -> V_236 ) < 0 )
return - V_227 ;
V_201 = V_16 -> V_219 + 0 ;
V_201 -> type = V_238 ;
V_201 = V_16 -> V_219 + V_239 ;
V_201 -> type = V_240 ;
V_201 -> V_241 = V_242 | V_243 ;
V_201 -> V_244 = V_223 ;
V_201 -> V_245 = 1 ;
V_201 -> V_246 = & V_247 ;
V_201 -> V_248 = V_249 ;
V_201 -> V_250 = V_251 ;
V_201 -> V_252 = 0 ;
F_29 ( V_16 , 0 , 0 , V_253 ) ;
F_13 ( V_16 ) -> V_183 = F_80 ( V_16 ,
& F_35 ,
& F_36 ,
V_254 ,
F_25
( V_16 ) ) ;
if ( F_13 ( V_16 ) -> V_183 == NULL )
return - V_227 ;
for ( V_215 = 0 ; V_215 < V_237 ; ++ V_215 ) {
V_201 = V_16 -> V_219 + F_3 ( V_215 ) ;
if ( V_215 < F_25 ( V_16 ) ) {
V_201 -> type = V_255 ;
V_201 -> V_241 =
V_242 | V_243 | V_256 |
V_257 ;
V_201 -> V_244 = 3 ;
V_201 -> V_245 = 0xffffffff ;
V_201 -> V_258 = V_259 ;
V_201 -> V_260 = V_261 ;
V_201 -> V_250 = V_262 ;
V_201 -> V_263 = & F_49 ;
V_201 -> V_264 = 1 ;
V_201 -> V_265 = & F_53 ;
V_201 -> V_266 = & F_55 ;
V_201 -> V_267 = & F_63 ;
V_201 -> V_268 = V_269 ;
V_201 -> V_270 = & F_66 ;
V_201 -> F_13 = & F_13 ( V_16 ) -> V_183 -> V_271 [ V_215 ] ;
F_13 ( V_16 ) -> V_183 -> V_271 [ V_215 ] . V_169 =
V_215 / V_12 ;
F_13 ( V_16 ) -> V_183 -> V_271 [ V_215 ] . V_11 =
V_215 % V_12 ;
} else {
V_201 -> type = V_238 ;
}
}
for ( V_215 = 0 ; V_215 < F_14 ( V_16 ) -> V_27 ; ++ V_215 )
F_81 ( V_16 , V_215 ) ;
for ( V_215 = 0 ; V_215 < F_25 ( V_16 ) ; ++ V_215 )
F_82 ( & F_13 ( V_16 ) -> V_183 -> V_271 [ V_215 ] ) ;
for ( V_215 = 0 ; V_215 < V_223 ; ++ V_215 ) {
if ( V_215 < V_272 )
F_83 ( V_16 , V_215 , V_273 ) ;
else
F_83 ( V_16 , V_215 ,
V_225 ) ;
F_84 ( V_16 , V_215 , V_274 ) ;
}
for ( V_215 = 0 ; V_215 < F_14 ( V_16 ) -> V_27 ; ++ V_215 )
F_57 ( V_16 , V_215 ) ;
V_222 = F_85 ( F_86 ( F_13 ( V_16 ) -> V_172 ) , F_61 ,
V_275 , L_8 , V_16 ) ;
if ( V_222 < 0 ) {
F_27 ( V_167 L_9 ) ;
return V_222 ;
}
V_16 -> V_213 = F_86 ( F_13 ( V_16 ) -> V_172 ) ;
V_230 = V_276 ;
if ( F_14 ( V_16 ) -> V_27 > 1 )
V_230 |= V_277 ;
F_29 ( V_16 , 0 , V_230 ,
V_278 ) ;
F_27 ( V_231 L_10 ) ;
return 0 ;
}
static void F_87 ( struct V_15 * V_16 )
{
if ( V_16 -> V_213 )
F_88 ( V_16 -> V_213 , V_16 ) ;
if ( V_16 -> F_13 ) {
if ( F_13 ( V_16 ) -> V_183 )
F_89 ( F_13 ( V_16 ) -> V_183 ) ;
if ( F_13 ( V_16 ) -> V_172 ) {
F_73 ( V_16 ) ;
F_90 ( F_13 ( V_16 ) -> V_172 ) ;
}
}
}
static int
V_259 ( struct V_15 * V_16 , struct V_200 * V_201 ,
struct V_279 * V_280 , unsigned int * V_281 )
{
return F_91 ( F_50 ( V_201 ) , V_280 , V_281 ) ;
}
static void F_81 ( struct V_15 * V_16 , int V_206 )
{
unsigned V_215 ;
F_13 ( V_16 ) -> V_190 [ V_206 ] = 0 ;
for ( V_215 = 0 ; V_215 < V_10 ; ++ V_215 ) {
F_13 ( V_16 ) -> V_190 [ V_206 ] |=
F_11 ( V_215 , V_192 ) & F_9 ( V_215 ) ;
}
F_29 ( V_16 , V_206 ,
F_13 ( V_16 ) ->
V_190 [ V_206 ] ,
V_191 ) ;
for ( V_215 = 0 ; V_215 < V_223 ; ++ V_215 )
F_29 ( V_16 , V_206 , 0 , F_1 ( V_215 ) ) ;
}
static int
V_262 ( struct V_15 * V_16 , struct V_200 * V_201 ,
struct V_279 * V_280 , unsigned int * V_281 )
{
return F_92 ( F_50 ( V_201 ) , V_280 , V_281 ) ;
}
static int V_261 ( struct V_15 * V_16 ,
struct V_200 * V_201 ,
struct V_279 * V_280 , unsigned int * V_281 )
{
return F_93 ( F_50 ( V_201 ) , V_280 , V_281 ) ;
}
static int F_76 ( struct V_15 * V_16 , int V_282 , int V_283 )
{
struct V_284 * V_172 ;
int V_215 ;
for ( V_172 = V_285 ; V_172 ; V_172 = V_172 -> V_286 ) {
if ( V_172 -> V_287 )
continue;
if ( V_282 || V_283 ) {
if ( V_282 != V_172 -> V_235 -> V_282 -> V_288 ||
V_283 != F_94 ( V_172 -> V_235 -> V_289 ) )
continue;
}
for ( V_215 = 0 ; V_215 < V_290 ; V_215 ++ ) {
if ( F_95 ( V_172 ) == V_291 [ V_215 ] . V_292 ) {
V_16 -> V_18 = V_291 + V_215 ;
F_13 ( V_16 ) -> V_172 = V_172 ;
return 0 ;
}
}
}
F_27 ( V_167 L_11 ) ;
F_96 () ;
return - V_293 ;
}
static int V_249 ( struct V_15 * V_16 ,
struct V_200 * V_201 ,
struct V_279 * V_280 , unsigned int * V_281 )
{
unsigned V_294 = F_97 ( V_280 -> V_295 ) ;
if ( V_281 [ 0 ] ) {
V_201 -> V_296 &= ~ ( V_281 [ 0 ] << V_294 ) ;
V_201 -> V_296 |= ( V_281 [ 0 ] & V_281 [ 1 ] ) << V_294 ;
F_29 ( V_16 , 0 , V_201 -> V_296 , V_297 ) ;
}
V_281 [ 1 ] =
( F_32 ( V_16 , 0 ,
V_298 ) >> V_294 ) ;
return 2 ;
}
static void F_84 ( struct V_15 * V_16 ,
unsigned V_1 ,
unsigned V_7 )
{
static const unsigned V_299 = 8 ;
static const unsigned V_300 = 23 ;
unsigned V_301 = 0 ;
unsigned V_302 = 0 ;
unsigned V_303 ;
unsigned V_304 ;
if ( F_14 ( V_16 ) -> V_27 > 1 ) {
if ( V_7 == V_225 &&
V_1 >= V_299 &&
V_1 <= V_300 ) {
V_301 = 1 ;
V_302 = 0 ;
} else {
V_301 = 0 ;
V_302 = 1 ;
}
}
if ( V_302 != V_301 ) {
V_304 =
F_32 ( V_16 , V_302 ,
F_1 ( V_1 ) ) ;
V_304 &= ~ F_5 ( V_1 ) ;
V_304 |=
F_6 ( V_1 ,
V_274 ) ;
F_29 ( V_16 , V_302 , V_304 ,
F_1 ( V_1 ) ) ;
}
V_303 =
F_32 ( V_16 , V_301 ,
F_1 ( V_1 ) ) ;
V_303 &= ~ F_5 ( V_1 ) ;
V_303 |= F_6 ( V_1 , V_7 ) ;
F_29 ( V_16 , V_301 , V_303 ,
F_1 ( V_1 ) ) ;
}
static int F_83 ( struct V_15 * V_16 , unsigned V_305 ,
unsigned V_306 )
{
if ( V_306 > V_307 )
return - V_308 ;
if ( V_306 == V_274 )
return - V_308 ;
if ( V_305 < V_272 ) {
if ( V_306 == V_225 )
return - V_308 ;
} else if ( V_305 > V_309 ) {
if ( V_306 == V_273 )
return - V_308 ;
}
F_2 ( V_305 >= V_223 ) ;
F_13 ( V_16 ) -> V_224 [ V_305 ] = V_306 ;
if ( F_13 ( V_16 ) -> V_310 & ( ( ( V_311 ) 1 ) << V_305 ) )
F_84 ( V_16 , V_305 ,
F_13 ( V_16 ) ->
V_224 [ V_305 ] ) ;
return 0 ;
}
static unsigned F_98 ( struct V_15 * V_16 ,
unsigned V_305 )
{
F_2 ( V_305 >= V_223 ) ;
return F_13 ( V_16 ) -> V_224 [ V_305 ] ;
}
static void F_99 ( struct V_15 * V_16 ,
unsigned V_1 ,
enum V_312 V_313 )
{
unsigned V_170 = F_32 ( V_16 , 0 , F_1 ( V_1 ) ) ;
V_170 &= ~ F_7 ( V_1 ) ;
V_170 |= F_8 ( V_1 , V_313 ) ;
F_29 ( V_16 , 0 , V_170 , F_1 ( V_1 ) ) ;
}
static int V_251 ( struct V_15 * V_16 ,
struct V_200 * V_201 ,
struct V_279 * V_280 , unsigned int * V_281 )
{
int V_305 = F_97 ( V_280 -> V_295 ) ;
switch ( V_281 [ 0 ] ) {
case V_314 :
F_13 ( V_16 ) -> V_310 |= ( ( V_311 ) 1 ) << V_305 ;
F_84 ( V_16 , V_305 ,
F_13 ( V_16 ) ->
V_224 [ V_305 ] ) ;
break;
case V_315 :
F_13 ( V_16 ) -> V_310 &= ~ ( ( ( V_311 ) 1 ) << V_305 ) ;
F_84 ( V_16 , V_305 , V_274 ) ;
break;
case V_316 :
V_281 [ 1 ] =
( F_13 ( V_16 ) -> V_310 &
( ( ( V_311 ) 1 ) << V_305 ) ) ? V_317 : V_202 ;
return 0 ;
case V_318 :
return F_83 ( V_16 , V_305 , V_281 [ 1 ] ) ;
break;
case V_319 :
V_281 [ 1 ] = F_98 ( V_16 , V_305 ) ;
break;
case V_320 :
F_99 ( V_16 , V_305 , V_281 [ 1 ] ) ;
break;
default:
return - V_308 ;
break;
}
return 0 ;
}
