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
unsigned int V_48 = V_43 -> V_49 . V_50 . V_51 [ 0 ] ;
unsigned int V_52 ;
switch ( V_48 ) {
case V_53 :
V_52 = V_54 ;
break;
case V_55 :
V_52 = V_56 ;
break;
case V_57 :
V_52 = V_58 ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_47 , V_59 , V_52 ) ;
return 0 ;
}
static int F_8 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_6 ( V_41 ) ;
struct V_44 * V_45 = (struct V_44 * ) V_41 -> V_46 ;
unsigned int V_47 = V_45 -> V_47 ;
int V_4 ;
V_4 = F_9 ( V_2 , V_47 ) & V_59 ;
switch ( V_4 ) {
case V_56 :
V_43 -> V_49 . V_50 . V_51 [ 0 ] = V_55 ;
break;
case V_58 :
V_43 -> V_49 . V_50 . V_51 [ 0 ] = V_57 ;
break;
default:
V_43 -> V_49 . V_50 . V_51 [ 0 ] = V_53 ;
break;
}
return 0 ;
}
static int F_10 ( struct V_60 * V_61 ,
struct V_40 * V_41 , int V_62 )
{
struct V_1 * V_2 = F_11 ( V_61 -> V_63 ) ;
switch ( V_62 ) {
case V_64 :
switch ( V_61 -> V_47 ) {
case V_65 :
F_7 ( V_2 , V_66 ,
V_67 ,
V_67 ) ;
break;
case V_68 :
F_7 ( V_2 , V_66 ,
V_69 ,
V_69 ) ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_61 -> V_47 , V_70 ,
V_71 ) ;
F_7 ( V_2 , V_61 -> V_47 , V_72 ,
V_73 ) ;
break;
case V_74 :
F_7 ( V_2 , V_61 -> V_47 , V_72 ,
V_75 ) ;
F_7 ( V_2 , V_61 -> V_47 , V_70 ,
V_76 ) ;
switch ( V_61 -> V_47 ) {
case V_65 :
F_7 ( V_2 , V_66 ,
V_67 , 0 ) ;
break;
case V_68 :
F_7 ( V_2 , V_66 ,
V_69 , 0 ) ;
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
static int F_12 ( struct V_60 * V_61 ,
struct V_40 * V_41 , int V_62 )
{
struct V_1 * V_2 = F_11 ( V_61 -> V_63 ) ;
switch ( V_62 ) {
case V_64 :
F_7 ( V_2 , V_61 -> V_47 ,
( 1 << V_61 -> V_77 ) | V_78 ,
( 1 << V_61 -> V_77 ) | V_78 ) ;
break;
case V_74 :
F_7 ( V_2 , V_61 -> V_47 ,
( 1 << V_61 -> V_77 ) | V_78 ,
( 1 << V_61 -> V_77 ) | V_79 ) ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_13 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
T_1 V_86 = 0 ;
T_1 V_87 ;
T_1 V_88 ;
V_87 = V_85 -> V_89 -> V_90 ;
switch ( F_14 ( V_83 ) ) {
case 16 :
V_86 |= V_91 ;
break;
case 20 :
V_86 |= V_92 ;
break;
case 24 :
V_86 |= V_93 ;
break;
case 32 :
V_86 |= V_94 ;
break;
default:
return - V_18 ;
}
switch ( F_15 ( V_83 ) ) {
case 8000 :
V_88 = V_95 ;
break;
case 11025 :
V_88 = V_96 ;
break;
case 12000 :
V_88 = V_97 ;
break;
case 16000 :
V_88 = V_98 ;
break;
case 22050 :
V_88 = V_99 ;
break;
case 24000 :
V_88 = V_100 ;
break;
case 32000 :
V_88 = V_101 ;
break;
case 44100 :
V_88 = V_102 ;
break;
case 48000 :
V_88 = V_103 ;
break;
case 88100 :
V_88 = V_104 ;
break;
case 96000 :
V_88 = V_105 ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_87 , V_106 , V_86 ) ;
F_7 ( V_2 , V_107 , V_108 , V_88 ) ;
return 0 ;
}
static int F_16 ( struct V_84 * V_85 , T_1 V_109 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
T_1 V_110 , V_111 ;
T_1 V_112 , V_113 ;
T_1 V_114 , V_115 ;
switch ( V_85 -> V_116 ) {
case V_117 :
V_112 = V_118 ;
V_114 = V_119 ;
V_111 = V_120 | V_121 |
V_122 ;
break;
case V_123 :
V_112 = V_124 ;
V_114 = V_125 ;
V_111 = V_126 | V_121 |
V_122 ;
break;
default:
return - V_18 ;
}
switch ( V_109 & V_127 ) {
case V_128 :
V_113 = V_129 ;
V_110 = V_130 | V_131 ;
break;
case V_132 :
V_113 = V_133 ;
V_110 = V_134 ;
break;
default:
return - V_18 ;
}
switch ( V_109 & V_135 ) {
case V_136 :
V_115 = V_137 ;
break;
case V_138 :
V_115 = V_139 ;
break;
case V_140 :
V_115 = V_141 ;
break;
case V_142 :
V_115 = V_143 ;
break;
default:
return - V_18 ;
}
switch ( V_109 & V_135 ) {
case V_142 :
switch ( V_109 & V_144 ) {
case V_145 :
break;
case V_146 :
V_115 |= V_147 ;
break;
default:
return - V_18 ;
}
break;
case V_136 :
case V_138 :
case V_140 :
switch ( V_109 & V_144 ) {
case V_145 :
break;
case V_148 :
V_115 |= V_147 | V_149 ;
break;
case V_146 :
V_115 |= V_147 ;
break;
case V_150 :
V_115 |= V_149 ;
break;
default:
return - V_18 ;
}
break;
default:
return - V_18 ;
}
F_2 ( V_2 , V_151 , V_110 ) ;
F_7 ( V_2 , V_112 , V_152 , V_113 ) ;
F_7 ( V_2 , V_114 , V_147 |
V_149 | V_153 , V_115 ) ;
F_2 ( V_2 , V_154 , V_111 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_155 ,
int V_156 , unsigned int V_157 ,
unsigned int V_158 )
{
struct V_159 * V_160 = F_18 ( V_2 ) ;
int V_161 , V_162 ;
T_2 V_163 , V_164 , V_165 ;
T_3 V_166 ;
if ( V_158 == 0 ) {
F_7 ( V_2 , V_19 ,
V_167 , 0 ) ;
V_160 -> V_168 = false ;
return 0 ;
}
if ( V_160 -> V_168 )
return - V_169 ;
if ( V_156 == V_170 ) {
switch ( V_160 -> V_3 ) {
case 11290000 :
case 12288000 :
case 22580000 :
case 24576000 :
case 45160000 :
case 49152000 :
F_2 ( V_2 , V_19 ,
V_171 ) ;
return 0 ;
default:
F_19 ( V_2 -> V_172 ,
L_2 ) ;
return - V_18 ;
}
}
V_162 = F_1 ( V_2 , V_160 -> V_3 ) ;
if ( V_162 < 0 )
return V_162 ;
V_161 = ( V_160 -> V_3 / V_162 ) ;
V_165 = V_158 / V_161 ;
V_166 = ( T_3 ) ( V_158 % V_161 ) * 8192ULL ;
F_20 ( V_166 , V_161 ) ;
V_164 = ( V_166 >> V_173 ) & V_174 ;
V_163 = ( V_166 ) & V_174 ;
F_2 ( V_2 , V_175 , V_163 ) ;
F_2 ( V_2 , V_176 , V_164 ) ;
F_2 ( V_2 , V_177 , V_165 ) ;
F_7 ( V_2 , V_19 , V_167 ,
V_167 ) ;
V_160 -> V_168 = true ;
return 0 ;
}
static int F_21 ( struct V_84 * V_85 , int V_178 ,
unsigned int V_179 , int V_180 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_159 * V_160 = F_18 ( V_2 ) ;
V_160 -> V_3 = V_179 ;
return 0 ;
}
static bool F_22 ( struct V_181 * V_172 , unsigned int V_47 )
{
switch ( V_47 ) {
case V_182 :
case V_183 :
return true ;
default:
return false ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
T_2 V_184 [ V_185 ] ;
T_2 V_186 [ V_185 ] ;
T_2 V_187 = V_188 ;
F_2 ( V_2 , V_189 ,
V_190 ) ;
F_2 ( V_2 , V_191 ,
V_190 ) ;
F_2 ( V_2 , V_182 ,
V_192 |
V_193 ) ;
F_2 ( V_2 , V_183 ,
V_192 |
V_193 ) ;
F_24 ( V_194 ) ;
V_186 [ V_195 ] = ( F_9 ( V_2 , V_182 ) &
V_196 ) ;
V_186 [ V_197 ] = ( F_9 ( V_2 , V_183 ) &
V_196 ) ;
V_184 [ V_195 ] = V_186 [ V_195 ] << V_198 ;
V_184 [ V_197 ] = V_186 [ V_197 ] << V_198 ;
do {
V_184 [ V_195 ] |= V_187 ;
V_184 [ V_197 ] |= V_187 ;
F_2 ( V_2 , V_189 ,
~ V_184 [ V_195 ] & V_199 ) ;
F_2 ( V_2 , V_191 ,
~ V_184 [ V_197 ] & V_199 ) ;
F_24 ( V_194 ) ;
if ( ( F_9 ( V_2 , V_182 ) &
V_196 ) ^ V_186 [ V_195 ] )
V_184 [ V_195 ] &= ~ V_187 ;
if ( ( F_9 ( V_2 , V_183 ) &
V_196 ) ^ V_186 [ V_197 ] )
V_184 [ V_197 ] &= ~ V_187 ;
V_187 >>= 1 ;
} while ( V_187 );
F_2 ( V_2 , V_189 ,
~ V_184 [ V_195 ] & V_199 ) ;
F_2 ( V_2 , V_191 ,
~ V_184 [ V_197 ] & V_199 ) ;
F_2 ( V_2 , V_182 ,
V_193 ) ;
F_2 ( V_2 , V_183 ,
V_193 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_2 V_184 [ V_200 ] ;
T_2 V_186 [ V_200 ] ;
T_2 V_187 = V_201 ;
V_184 [ V_202 ] = V_203 ;
V_184 [ V_204 ] = V_203 ;
F_2 ( V_2 , V_205 , V_203 ) ;
F_2 ( V_2 , V_206 , V_203 ) ;
F_2 ( V_2 , V_207 ,
V_208 | V_209 ) ;
F_2 ( V_2 , V_210 ,
V_208 | V_209 ) ;
F_24 ( V_194 ) ;
V_186 [ V_202 ] = F_9 ( V_2 , V_207 ) &
V_211 ;
V_186 [ V_204 ] = F_9 ( V_2 , V_210 ) &
V_211 ;
F_2 ( V_2 , V_207 , V_208 |
( V_186 [ V_202 ] >> V_212 ) |
V_209 ) ;
F_2 ( V_2 , V_210 , V_208 |
( V_186 [ V_204 ] >> V_212 ) |
V_209 ) ;
do {
V_184 [ V_202 ] |= V_187 ;
V_184 [ V_204 ] |= V_187 ;
F_2 ( V_2 , V_205 ,
V_184 [ V_202 ] ) ;
F_2 ( V_2 , V_206 ,
V_184 [ V_204 ] ) ;
F_24 ( V_194 ) ;
if ( ( F_9 ( V_2 , V_207 ) &
V_211 ) ^ V_186 [ V_202 ] )
V_184 [ V_202 ] &= ~ V_187 ;
if ( ( F_9 ( V_2 , V_210 ) &
V_211 ) ^ V_186 [ V_204 ] )
V_184 [ V_204 ] &= ~ V_187 ;
V_187 >>= 1 ;
} while ( V_187 );
F_2 ( V_2 , V_205 , V_184 [ V_202 ] ) ;
F_2 ( V_2 , V_206 , V_184 [ V_204 ] ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_213 , V_214 |
V_215 | V_216 ) ;
F_2 ( V_2 , V_217 , V_218 |
V_219 | V_220 | V_221 |
V_222 | V_223 ) ;
F_2 ( V_2 , V_207 , V_224 |
V_225 | V_209 ) ;
F_2 ( V_2 , V_210 , V_209 |
V_225 | V_224 ) ;
F_23 ( V_2 ) ;
F_25 ( V_2 ) ;
F_2 ( V_2 , V_217 , V_226 ) ;
F_2 ( V_2 , V_207 , V_227 ) ;
F_2 ( V_2 , V_210 , V_227 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
enum V_228 V_229 )
{
struct V_159 * V_160 = F_18 ( V_2 ) ;
switch ( V_229 ) {
case V_230 :
F_7 ( V_2 , V_231 ,
V_232 ,
V_233 ) ;
break;
case V_234 :
break;
case V_235 :
if ( F_28 ( V_2 ) == V_236 ) {
F_2 ( V_2 , V_237 ,
V_238 ) ;
F_2 ( V_2 , V_231 ,
V_239 ) ;
F_29 ( V_240 ) ;
F_2 ( V_2 , V_237 ,
V_241 ) ;
F_2 ( V_2 , V_242 ,
V_243 ) ;
F_2 ( V_2 , V_244 ,
V_245 ) ;
F_2 ( V_2 , V_246 ,
V_247 |
V_248 |
V_249 ) ;
F_2 ( V_2 , V_250 ,
V_251 ) ;
F_3 ( V_2 , V_21 ) ;
F_2 ( V_2 , V_252 ,
V_253 | V_254 ) ;
F_2 ( V_2 , V_255 ,
V_256 |
V_257 |
V_258 |
V_259 |
V_260 |
V_261 |
V_262 |
V_263 ) ;
F_2 ( V_2 , V_264 ,
V_265 | V_266 |
V_267 | V_268 |
V_269 ) ;
F_26 ( V_2 ) ;
F_30 ( V_160 -> V_270 , false ) ;
F_31 ( V_160 -> V_270 ) ;
} else {
F_7 ( V_2 , V_231 ,
V_232 ,
V_271 ) ;
F_7 ( V_2 , V_19 ,
V_167 , 0 ) ;
V_160 -> V_168 = false ;
}
break;
case V_236 :
F_30 ( V_160 -> V_270 , true ) ;
F_3 ( V_2 , V_36 ) ;
F_7 ( V_2 , V_231 , V_239 ,
V_272 ) ;
V_160 -> V_168 = false ;
break;
}
return 0 ;
}
static int F_32 ( struct V_273 * V_274 ,
const struct V_275 * V_116 )
{
struct V_159 * V_160 ;
unsigned int V_47 ;
int V_5 ;
V_160 = F_33 ( & V_274 -> V_172 , sizeof( struct V_159 ) ,
V_276 ) ;
if ( ! V_160 )
return - V_277 ;
F_34 ( V_274 , V_160 ) ;
V_160 -> V_270 = F_35 ( V_274 , & V_278 ) ;
if ( F_36 ( V_160 -> V_270 ) ) {
V_5 = F_37 ( V_160 -> V_270 ) ;
F_19 ( & V_274 -> V_172 , L_3 ) ;
goto V_279;
}
V_5 = F_38 ( V_160 -> V_270 , V_280 , & V_47 ) ;
if ( V_5 < 0 ) {
F_19 ( & V_274 -> V_172 , L_4 , V_5 ) ;
goto V_279;
}
F_39 ( & V_274 -> V_172 , L_5 ,
( V_47 & V_281 ) >> 4 ,
( V_47 & V_282 ) ) ;
V_5 = F_40 ( & V_274 -> V_172 , & V_283 ,
V_284 , F_41 ( V_284 ) ) ;
if ( V_5 != 0 )
F_19 ( & V_274 -> V_172 , L_6 ) ;
V_279:
return V_5 ;
}
static int F_42 ( struct V_273 * V_285 )
{
F_43 ( & V_285 -> V_172 ) ;
return 0 ;
}
