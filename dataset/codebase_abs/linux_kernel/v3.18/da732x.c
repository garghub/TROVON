static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
int V_5 ;
if ( V_3 < V_6 ) {
V_4 = V_7 ;
V_5 = V_8 ;
} else if ( ( V_3 >= V_6 ) &&
( V_3 < V_9 ) ) {
V_4 = V_10 ;
V_5 = V_11 ;
} else if ( ( V_3 >= V_9 ) &&
( V_3 < V_12 ) ) {
V_4 = V_13 ;
V_5 = V_14 ;
} else if ( ( V_3 >= V_12 ) &&
( V_3 <= V_15 ) ) {
V_4 = V_16 ;
V_5 = V_17 ;
} else {
return - V_18 ;
}
F_2 ( V_2 , V_19 , V_4 ) ;
return V_5 ;
}
static void F_3 ( struct V_1 * V_2 , int V_20 )
{
switch ( V_20 ) {
case V_21 :
F_2 ( V_2 , V_22 , V_23 ) ;
F_2 ( V_2 , V_24 , V_25 |
V_26 | V_27 ) ;
F_2 ( V_2 , V_28 , V_29 |
V_30 ) ;
F_2 ( V_2 , V_31 ,
V_32 | V_33 ) ;
F_2 ( V_2 , V_34 , V_35 ) ;
break;
case V_36 :
F_2 ( V_2 , V_22 , V_37 ) ;
F_2 ( V_2 , V_24 , V_38 ) ;
F_2 ( V_2 , V_28 , V_39 ) ;
break;
default:
F_4 ( L_1 ) ;
break;
}
}
static int F_5 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_6 ( V_41 ) ;
struct V_44 * V_45 = (struct V_44 * ) V_41 -> V_46 ;
unsigned int V_47 = V_45 -> V_47 ;
unsigned int V_48 = V_43 -> V_49 . integer . V_49 [ 0 ] ;
unsigned int V_50 ;
switch ( V_48 ) {
case V_51 :
V_50 = V_52 ;
break;
case V_53 :
V_50 = V_54 ;
break;
case V_55 :
V_50 = V_56 ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_47 , V_57 , V_50 ) ;
return 0 ;
}
static int F_8 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_6 ( V_41 ) ;
struct V_44 * V_45 = (struct V_44 * ) V_41 -> V_46 ;
unsigned int V_47 = V_45 -> V_47 ;
int V_4 ;
V_4 = F_9 ( V_2 , V_47 ) & V_57 ;
switch ( V_4 ) {
case V_54 :
V_43 -> V_49 . integer . V_49 [ 0 ] = V_53 ;
break;
case V_56 :
V_43 -> V_49 . integer . V_49 [ 0 ] = V_55 ;
break;
default:
V_43 -> V_49 . integer . V_49 [ 0 ] = V_51 ;
break;
}
return 0 ;
}
static int F_10 ( struct V_58 * V_59 ,
struct V_40 * V_41 , int V_60 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
switch ( V_60 ) {
case V_61 :
switch ( V_59 -> V_47 ) {
case V_62 :
F_7 ( V_2 , V_63 ,
V_64 ,
V_64 ) ;
break;
case V_65 :
F_7 ( V_2 , V_63 ,
V_66 ,
V_66 ) ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_59 -> V_47 , V_67 ,
V_68 ) ;
F_7 ( V_2 , V_59 -> V_47 , V_69 ,
V_70 ) ;
break;
case V_71 :
F_7 ( V_2 , V_59 -> V_47 , V_69 ,
V_72 ) ;
F_7 ( V_2 , V_59 -> V_47 , V_67 ,
V_73 ) ;
switch ( V_59 -> V_47 ) {
case V_62 :
F_7 ( V_2 , V_63 ,
V_64 , 0 ) ;
break;
case V_65 :
F_7 ( V_2 , V_63 ,
V_66 , 0 ) ;
break;
default:
return - V_18 ;
}
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_58 * V_59 ,
struct V_40 * V_41 , int V_60 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
switch ( V_60 ) {
case V_61 :
F_7 ( V_2 , V_59 -> V_47 ,
( 1 << V_59 -> V_74 ) | V_75 ,
( 1 << V_59 -> V_74 ) | V_75 ) ;
break;
case V_71 :
F_7 ( V_2 , V_59 -> V_47 ,
( 1 << V_59 -> V_74 ) | V_75 ,
( 1 << V_59 -> V_74 ) | V_76 ) ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_12 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
T_1 V_83 = 0 ;
T_1 V_84 ;
T_1 V_85 ;
V_84 = V_82 -> V_86 -> V_87 ;
switch ( F_13 ( V_80 ) ) {
case 16 :
V_83 |= V_88 ;
break;
case 20 :
V_83 |= V_89 ;
break;
case 24 :
V_83 |= V_90 ;
break;
case 32 :
V_83 |= V_91 ;
break;
default:
return - V_18 ;
}
switch ( F_14 ( V_80 ) ) {
case 8000 :
V_85 = V_92 ;
break;
case 11025 :
V_85 = V_93 ;
break;
case 12000 :
V_85 = V_94 ;
break;
case 16000 :
V_85 = V_95 ;
break;
case 22050 :
V_85 = V_96 ;
break;
case 24000 :
V_85 = V_97 ;
break;
case 32000 :
V_85 = V_98 ;
break;
case 44100 :
V_85 = V_99 ;
break;
case 48000 :
V_85 = V_100 ;
break;
case 88100 :
V_85 = V_101 ;
break;
case 96000 :
V_85 = V_102 ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_84 , V_103 , V_83 ) ;
F_7 ( V_2 , V_104 , V_105 , V_85 ) ;
return 0 ;
}
static int F_15 ( struct V_81 * V_82 , T_1 V_106 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
T_1 V_107 , V_108 ;
T_1 V_109 , V_110 ;
T_1 V_111 , V_112 ;
switch ( V_82 -> V_113 ) {
case V_114 :
V_109 = V_115 ;
V_111 = V_116 ;
V_108 = V_117 | V_118 |
V_119 ;
break;
case V_120 :
V_109 = V_121 ;
V_111 = V_122 ;
V_108 = V_123 | V_118 |
V_119 ;
break;
default:
return - V_18 ;
}
switch ( V_106 & V_124 ) {
case V_125 :
V_110 = V_126 ;
V_107 = V_127 | V_128 ;
break;
case V_129 :
V_110 = V_130 ;
V_107 = V_131 ;
break;
default:
return - V_18 ;
}
switch ( V_106 & V_132 ) {
case V_133 :
V_112 = V_134 ;
break;
case V_135 :
V_112 = V_136 ;
break;
case V_137 :
V_112 = V_138 ;
break;
case V_139 :
V_112 = V_140 ;
break;
default:
return - V_18 ;
}
switch ( V_106 & V_132 ) {
case V_139 :
switch ( V_106 & V_141 ) {
case V_142 :
break;
case V_143 :
V_112 |= V_144 ;
break;
default:
return - V_18 ;
}
break;
case V_133 :
case V_135 :
case V_137 :
switch ( V_106 & V_141 ) {
case V_142 :
break;
case V_145 :
V_112 |= V_144 | V_146 ;
break;
case V_143 :
V_112 |= V_144 ;
break;
case V_147 :
V_112 |= V_146 ;
break;
default:
return - V_18 ;
}
break;
default:
return - V_18 ;
}
F_2 ( V_2 , V_148 , V_107 ) ;
F_7 ( V_2 , V_109 , V_149 , V_110 ) ;
F_7 ( V_2 , V_111 , V_144 |
V_146 | V_150 , V_112 ) ;
F_2 ( V_2 , V_151 , V_108 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_152 ,
int V_153 , unsigned int V_154 ,
unsigned int V_155 )
{
struct V_156 * V_157 = F_17 ( V_2 ) ;
int V_158 , V_159 ;
T_2 V_160 , V_161 , V_162 ;
T_3 V_163 ;
if ( V_155 == 0 ) {
F_7 ( V_2 , V_19 ,
V_164 , 0 ) ;
V_157 -> V_165 = false ;
return 0 ;
}
if ( V_157 -> V_165 )
return - V_166 ;
if ( V_153 == V_167 ) {
switch ( V_157 -> V_3 ) {
case 11290000 :
case 12288000 :
case 22580000 :
case 24576000 :
case 45160000 :
case 49152000 :
F_2 ( V_2 , V_19 ,
V_168 ) ;
return 0 ;
default:
F_18 ( V_2 -> V_169 ,
L_2 ) ;
return - V_18 ;
}
}
V_159 = F_1 ( V_2 , V_157 -> V_3 ) ;
if ( V_159 < 0 )
return V_159 ;
V_158 = ( V_157 -> V_3 / V_159 ) ;
V_162 = V_155 / V_158 ;
V_163 = ( T_3 ) ( V_155 % V_158 ) * 8192ULL ;
F_19 ( V_163 , V_158 ) ;
V_161 = ( V_163 >> V_170 ) & V_171 ;
V_160 = ( V_163 ) & V_171 ;
F_2 ( V_2 , V_172 , V_160 ) ;
F_2 ( V_2 , V_173 , V_161 ) ;
F_2 ( V_2 , V_174 , V_162 ) ;
F_7 ( V_2 , V_19 , V_164 ,
V_164 ) ;
V_157 -> V_165 = true ;
return 0 ;
}
static int F_20 ( struct V_81 * V_82 , int V_175 ,
unsigned int V_176 , int V_177 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_156 * V_157 = F_17 ( V_2 ) ;
V_157 -> V_3 = V_176 ;
return 0 ;
}
static bool F_21 ( struct V_178 * V_169 , unsigned int V_47 )
{
switch ( V_47 ) {
case V_179 :
case V_180 :
return true ;
default:
return false ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
T_2 V_181 [ V_182 ] ;
T_2 V_183 [ V_182 ] ;
T_2 V_184 = V_185 ;
F_2 ( V_2 , V_186 ,
V_187 ) ;
F_2 ( V_2 , V_188 ,
V_187 ) ;
F_2 ( V_2 , V_179 ,
V_189 |
V_190 ) ;
F_2 ( V_2 , V_180 ,
V_189 |
V_190 ) ;
F_23 ( V_191 ) ;
V_183 [ V_192 ] = ( F_9 ( V_2 , V_179 ) &
V_193 ) ;
V_183 [ V_194 ] = ( F_9 ( V_2 , V_180 ) &
V_193 ) ;
V_181 [ V_192 ] = V_183 [ V_192 ] << V_195 ;
V_181 [ V_194 ] = V_183 [ V_194 ] << V_195 ;
do {
V_181 [ V_192 ] |= V_184 ;
V_181 [ V_194 ] |= V_184 ;
F_2 ( V_2 , V_186 ,
~ V_181 [ V_192 ] & V_196 ) ;
F_2 ( V_2 , V_188 ,
~ V_181 [ V_194 ] & V_196 ) ;
F_23 ( V_191 ) ;
if ( ( F_9 ( V_2 , V_179 ) &
V_193 ) ^ V_183 [ V_192 ] )
V_181 [ V_192 ] &= ~ V_184 ;
if ( ( F_9 ( V_2 , V_180 ) &
V_193 ) ^ V_183 [ V_194 ] )
V_181 [ V_194 ] &= ~ V_184 ;
V_184 >>= 1 ;
} while ( V_184 );
F_2 ( V_2 , V_186 ,
~ V_181 [ V_192 ] & V_196 ) ;
F_2 ( V_2 , V_188 ,
~ V_181 [ V_194 ] & V_196 ) ;
F_2 ( V_2 , V_179 ,
V_190 ) ;
F_2 ( V_2 , V_180 ,
V_190 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_181 [ V_197 ] ;
T_2 V_183 [ V_197 ] ;
T_2 V_184 = V_198 ;
V_181 [ V_199 ] = V_200 ;
V_181 [ V_201 ] = V_200 ;
F_2 ( V_2 , V_202 , V_200 ) ;
F_2 ( V_2 , V_203 , V_200 ) ;
F_2 ( V_2 , V_204 ,
V_205 | V_206 ) ;
F_2 ( V_2 , V_207 ,
V_205 | V_206 ) ;
F_23 ( V_191 ) ;
V_183 [ V_199 ] = F_9 ( V_2 , V_204 ) &
V_208 ;
V_183 [ V_201 ] = F_9 ( V_2 , V_207 ) &
V_208 ;
F_2 ( V_2 , V_204 , V_205 |
( V_183 [ V_199 ] >> V_209 ) |
V_206 ) ;
F_2 ( V_2 , V_207 , V_205 |
( V_183 [ V_201 ] >> V_209 ) |
V_206 ) ;
do {
V_181 [ V_199 ] |= V_184 ;
V_181 [ V_201 ] |= V_184 ;
F_2 ( V_2 , V_202 ,
V_181 [ V_199 ] ) ;
F_2 ( V_2 , V_203 ,
V_181 [ V_201 ] ) ;
F_23 ( V_191 ) ;
if ( ( F_9 ( V_2 , V_204 ) &
V_208 ) ^ V_183 [ V_199 ] )
V_181 [ V_199 ] &= ~ V_184 ;
if ( ( F_9 ( V_2 , V_207 ) &
V_208 ) ^ V_183 [ V_201 ] )
V_181 [ V_201 ] &= ~ V_184 ;
V_184 >>= 1 ;
} while ( V_184 );
F_2 ( V_2 , V_202 , V_181 [ V_199 ] ) ;
F_2 ( V_2 , V_203 , V_181 [ V_201 ] ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_210 , V_211 |
V_212 | V_213 ) ;
F_2 ( V_2 , V_214 , V_215 |
V_216 | V_217 | V_218 |
V_219 | V_220 ) ;
F_2 ( V_2 , V_204 , V_221 |
V_222 | V_206 ) ;
F_2 ( V_2 , V_207 , V_206 |
V_222 | V_221 ) ;
F_22 ( V_2 ) ;
F_24 ( V_2 ) ;
F_2 ( V_2 , V_214 , V_223 ) ;
F_2 ( V_2 , V_204 , V_224 ) ;
F_2 ( V_2 , V_207 , V_224 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_225 V_226 )
{
struct V_156 * V_157 = F_17 ( V_2 ) ;
switch ( V_226 ) {
case V_227 :
F_7 ( V_2 , V_228 ,
V_229 ,
V_230 ) ;
break;
case V_231 :
break;
case V_232 :
if ( V_2 -> V_233 . V_234 == V_235 ) {
F_2 ( V_2 , V_236 ,
V_237 ) ;
F_2 ( V_2 , V_228 ,
V_238 ) ;
F_27 ( V_239 ) ;
F_2 ( V_2 , V_236 ,
V_240 ) ;
F_2 ( V_2 , V_241 ,
V_242 ) ;
F_2 ( V_2 , V_243 ,
V_244 ) ;
F_2 ( V_2 , V_245 ,
V_246 |
V_247 |
V_248 ) ;
F_2 ( V_2 , V_249 ,
V_250 ) ;
F_3 ( V_2 , V_21 ) ;
F_2 ( V_2 , V_251 ,
V_252 | V_253 ) ;
F_2 ( V_2 , V_254 ,
V_255 |
V_256 |
V_257 |
V_258 |
V_259 |
V_260 |
V_261 |
V_262 ) ;
F_2 ( V_2 , V_263 ,
V_264 | V_265 |
V_266 | V_267 |
V_268 ) ;
F_25 ( V_2 ) ;
F_28 ( V_157 -> V_269 , false ) ;
F_29 ( V_157 -> V_269 ) ;
} else {
F_7 ( V_2 , V_228 ,
V_229 ,
V_270 ) ;
F_7 ( V_2 , V_19 ,
V_164 , 0 ) ;
V_157 -> V_165 = false ;
}
break;
case V_235 :
F_28 ( V_157 -> V_269 , true ) ;
F_3 ( V_2 , V_36 ) ;
F_7 ( V_2 , V_228 , V_238 ,
V_271 ) ;
V_157 -> V_165 = false ;
break;
}
V_2 -> V_233 . V_234 = V_226 ;
return 0 ;
}
static int F_30 ( struct V_272 * V_273 ,
const struct V_274 * V_113 )
{
struct V_156 * V_157 ;
unsigned int V_47 ;
int V_5 ;
V_157 = F_31 ( & V_273 -> V_169 , sizeof( struct V_156 ) ,
V_275 ) ;
if ( ! V_157 )
return - V_276 ;
F_32 ( V_273 , V_157 ) ;
V_157 -> V_269 = F_33 ( V_273 , & V_277 ) ;
if ( F_34 ( V_157 -> V_269 ) ) {
V_5 = F_35 ( V_157 -> V_269 ) ;
F_18 ( & V_273 -> V_169 , L_3 ) ;
goto V_278;
}
V_5 = F_36 ( V_157 -> V_269 , V_279 , & V_47 ) ;
if ( V_5 < 0 ) {
F_18 ( & V_273 -> V_169 , L_4 , V_5 ) ;
goto V_278;
}
F_37 ( & V_273 -> V_169 , L_5 ,
( V_47 & V_280 ) >> 4 ,
( V_47 & V_281 ) ) ;
V_5 = F_38 ( & V_273 -> V_169 , & V_282 ,
V_283 , F_39 ( V_283 ) ) ;
if ( V_5 != 0 )
F_18 ( & V_273 -> V_169 , L_6 ) ;
V_278:
return V_5 ;
}
static int F_40 ( struct V_272 * V_284 )
{
F_41 ( & V_284 -> V_169 ) ;
return 0 ;
}
