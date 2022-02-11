static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_6 +
V_5 [ V_4 ] . V_7 ) ||
( V_3 >= V_5 [ V_4 ] . V_8 &&
V_3 <= V_5 [ V_4 ] . V_9 ) ) {
return true ;
}
}
switch ( V_3 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_6 +
V_5 [ V_4 ] . V_7 ) ||
( V_3 >= V_5 [ V_4 ] . V_8 &&
V_3 <= V_5 [ V_4 ] . V_9 ) ) {
return true ;
}
}
switch ( V_3 ) {
case V_10 :
case V_20 :
case V_18 :
case V_19 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_11 :
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
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_12 :
case V_84 :
case V_13 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_14 :
case V_15 :
case V_90 :
case V_91 :
case V_92 :
case V_16 :
case V_93 :
case V_17 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
int V_120 , V_121 ;
V_121 = V_119 -> V_122 / F_7 ( V_119 -> V_123 ,
V_62 , V_124 ) ;
V_120 = F_8 ( V_121 ) ;
if ( V_120 < 0 )
F_9 ( V_116 -> V_2 , L_1 ) ;
else
F_10 ( V_116 , V_64 , V_125 ,
V_120 << V_126 ) ;
return V_120 ;
}
static int F_11 ( struct V_110 * V_127 ,
struct V_110 * V_128 )
{
struct V_115 * V_116 = F_5 ( V_127 -> V_117 ) ;
unsigned int V_129 ;
V_129 = F_12 ( V_116 , V_68 ) ;
V_129 &= V_130 ;
if ( V_129 == V_131 )
return 1 ;
else
return 0 ;
}
static int F_13 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
switch ( V_114 ) {
case V_132 :
F_14 ( V_119 -> V_123 , V_133 +
V_134 , 0x0700 , 0x0200 ) ;
F_14 ( V_119 -> V_123 , V_79 ,
V_135 , V_136 ) ;
F_14 ( V_119 -> V_123 , V_78 ,
V_137 | V_138 |
V_139 , V_140 |
V_141 | V_142 ) ;
F_15 ( V_119 -> V_123 , V_133 +
V_143 , 0x9f00 ) ;
F_14 ( V_119 -> V_123 , V_55 ,
V_144 | V_145 , 0 ) ;
F_14 ( V_119 -> V_123 , V_55 ,
V_146 ,
V_146 ) ;
F_16 ( 10000 , 15000 ) ;
F_14 ( V_119 -> V_123 , V_55 ,
V_144 | V_145 ,
V_144 | V_145 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_17 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
switch ( V_114 ) {
case V_132 :
F_14 ( V_119 -> V_123 , V_79 ,
V_135 | V_147 ,
V_148 | V_149 ) ;
F_14 ( V_119 -> V_123 , V_81 ,
V_150 , V_151 ) ;
F_14 ( V_119 -> V_123 , V_80 ,
V_152 | V_153 |
V_154 ,
( V_155 << V_156 ) |
( V_157 << V_158 ) |
( V_155 << V_159 ) ) ;
F_15 ( V_119 -> V_123 , V_133 +
V_160 , 0x1c00 ) ;
F_14 ( V_119 -> V_123 , V_78 ,
V_137 | V_138 ,
V_161 | V_162 ) ;
F_14 ( V_119 -> V_123 , V_133 +
V_134 , 0x0700 , 0x0400 ) ;
V_119 -> V_163 = 0 ;
break;
case V_164 :
V_119 -> V_163 = 1 ;
F_16 ( 70000 , 75000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_18 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
switch ( V_114 ) {
case V_132 :
if ( ! V_119 -> V_163 )
F_16 ( 80000 , 85000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_19 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
switch ( V_114 ) {
case V_132 :
F_10 ( V_116 , V_56 ,
V_165 , V_165 ) ;
break;
case V_164 :
F_10 ( V_116 , V_56 ,
V_165 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
switch ( V_114 ) {
case V_132 :
F_10 ( V_116 , V_56 ,
V_166 , V_166 ) ;
break;
case V_164 :
F_10 ( V_116 , V_56 ,
V_166 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_21 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
switch ( V_114 ) {
case V_132 :
F_10 ( V_116 , V_56 ,
V_167 , V_167 ) ;
break;
case V_164 :
F_10 ( V_116 , V_56 ,
V_167 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_168 * V_169 ,
struct V_170 * V_171 , struct V_172 * V_173 )
{
struct V_115 * V_116 = V_173 -> V_116 ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
unsigned int V_174 = 0 , V_175 , V_176 ;
int V_177 , V_178 , V_179 ;
V_119 -> V_180 [ V_173 -> V_181 ] = F_23 ( V_171 ) ;
V_177 = F_24 ( V_119 -> V_122 , V_119 -> V_180 [ V_173 -> V_181 ] ) ;
if ( V_177 < 0 ) {
F_9 ( V_116 -> V_2 , L_2 ) ;
return - V_182 ;
}
V_179 = F_25 ( V_171 ) ;
if ( V_179 < 0 ) {
F_9 ( V_116 -> V_2 , L_3 , V_179 ) ;
return - V_182 ;
}
V_178 = V_179 > 32 ? 1 : 0 ;
V_119 -> V_183 [ V_173 -> V_181 ] = V_119 -> V_180 [ V_173 -> V_181 ] * ( 32 << V_178 ) ;
F_26 ( V_173 -> V_2 , L_4 ,
V_119 -> V_183 [ V_173 -> V_181 ] , V_119 -> V_180 [ V_173 -> V_181 ] ) ;
F_26 ( V_173 -> V_2 , L_5 ,
V_178 , V_177 , V_173 -> V_181 ) ;
switch ( F_27 ( V_171 ) ) {
case 16 :
break;
case 20 :
V_174 |= V_184 ;
break;
case 24 :
V_174 |= V_185 ;
break;
case 8 :
V_174 |= V_186 ;
break;
default:
return - V_182 ;
}
switch ( V_173 -> V_181 ) {
case V_187 :
V_176 = V_188 ;
V_175 = V_177 << V_124 ;
F_10 ( V_116 , V_60 ,
V_189 , V_174 ) ;
F_10 ( V_116 , V_62 , V_176 , V_175 ) ;
break;
case V_190 :
V_176 = V_191 | V_192 ;
V_175 = V_177 << V_193 ;
F_10 ( V_116 , V_61 ,
V_189 , V_174 ) ;
F_10 ( V_116 , V_62 , V_176 , V_175 ) ;
break;
default:
F_9 ( V_116 -> V_2 , L_6 , V_173 -> V_181 ) ;
return - V_182 ;
}
return 0 ;
}
static int F_28 ( struct V_172 * V_173 , unsigned int V_194 )
{
struct V_115 * V_116 = V_173 -> V_116 ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
unsigned int V_195 = 0 ;
switch ( V_194 & V_196 ) {
case V_197 :
V_119 -> V_198 [ V_173 -> V_181 ] = 1 ;
break;
case V_199 :
V_195 |= V_200 ;
V_119 -> V_198 [ V_173 -> V_181 ] = 0 ;
break;
default:
return - V_182 ;
}
switch ( V_194 & V_201 ) {
case V_202 :
break;
case V_203 :
V_195 |= V_204 ;
break;
default:
return - V_182 ;
}
switch ( V_194 & V_205 ) {
case V_206 :
break;
case V_207 :
V_195 |= V_208 ;
break;
case V_209 :
V_195 |= V_210 ;
break;
case V_211 :
V_195 |= V_212 ;
break;
default:
return - V_182 ;
}
switch ( V_173 -> V_181 ) {
case V_187 :
F_10 ( V_116 , V_60 ,
V_213 | V_214 |
V_215 , V_195 ) ;
break;
case V_190 :
F_10 ( V_116 , V_61 ,
V_213 | V_214 |
V_215 , V_195 ) ;
break;
default:
F_9 ( V_116 -> V_2 , L_6 , V_173 -> V_181 ) ;
return - V_182 ;
}
return 0 ;
}
static int F_29 ( struct V_172 * V_173 ,
int V_216 , unsigned int V_217 , int V_218 )
{
struct V_115 * V_116 = V_173 -> V_116 ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
unsigned int V_195 = 0 ;
if ( V_217 == V_119 -> V_122 && V_216 == V_119 -> V_219 )
return 0 ;
switch ( V_216 ) {
case V_220 :
V_195 |= V_221 ;
break;
case V_222 :
V_195 |= V_131 ;
break;
case V_223 :
V_195 |= V_224 ;
break;
default:
F_9 ( V_116 -> V_2 , L_7 , V_216 ) ;
return - V_182 ;
}
F_10 ( V_116 , V_68 ,
V_130 , V_195 ) ;
V_119 -> V_122 = V_217 ;
V_119 -> V_219 = V_216 ;
F_26 ( V_173 -> V_2 , L_8 , V_217 , V_216 ) ;
return 0 ;
}
static int F_30 ( struct V_172 * V_173 , int V_225 , int V_127 ,
unsigned int V_226 , unsigned int V_227 )
{
struct V_115 * V_116 = V_173 -> V_116 ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
struct V_228 V_229 ;
int V_230 ;
if ( V_127 == V_119 -> V_231 && V_226 == V_119 -> V_232 &&
V_227 == V_119 -> V_233 )
return 0 ;
if ( ! V_226 || ! V_227 ) {
F_26 ( V_116 -> V_2 , L_9 ) ;
V_119 -> V_232 = 0 ;
V_119 -> V_233 = 0 ;
F_10 ( V_116 , V_68 ,
V_130 , V_221 ) ;
return 0 ;
}
switch ( V_127 ) {
case V_234 :
F_10 ( V_116 , V_68 ,
V_235 , V_236 ) ;
break;
case V_237 :
F_10 ( V_116 , V_68 ,
V_235 , V_238 ) ;
break;
case V_239 :
F_10 ( V_116 , V_68 ,
V_235 , V_240 ) ;
break;
default:
F_9 ( V_116 -> V_2 , L_10 , V_127 ) ;
return - V_182 ;
}
V_230 = F_31 ( V_226 , V_227 , & V_229 ) ;
if ( V_230 < 0 ) {
F_9 ( V_116 -> V_2 , L_11 , V_226 ) ;
return V_230 ;
}
F_26 ( V_116 -> V_2 , L_12 ,
V_229 . V_241 , ( V_229 . V_241 ? 0 : V_229 . V_242 ) ,
V_229 . V_243 , V_229 . V_244 ) ;
F_32 ( V_116 , V_69 ,
V_229 . V_243 << V_245 | V_229 . V_244 ) ;
F_32 ( V_116 , V_70 ,
( V_229 . V_241 ? 0 : V_229 . V_242 ) << V_246 |
V_229 . V_241 << V_247 ) ;
V_119 -> V_232 = V_226 ;
V_119 -> V_233 = V_227 ;
V_119 -> V_231 = V_127 ;
return 0 ;
}
static int F_33 ( struct V_115 * V_116 ,
enum V_248 V_249 )
{
switch ( V_249 ) {
case V_250 :
if ( V_251 == F_34 ( V_116 ) ) {
F_10 ( V_116 , V_55 ,
V_252 | V_253 |
V_254 | V_255 ,
V_252 | V_253 |
V_254 | V_255 ) ;
F_16 ( 10000 , 15000 ) ;
F_10 ( V_116 , V_55 ,
V_144 | V_145 ,
V_144 | V_145 ) ;
F_10 ( V_116 , V_55 ,
V_256 ,
V_257 ) ;
F_10 ( V_116 , V_107 , 0x1 , 0x1 ) ;
if ( F_12 ( V_116 , V_71 ) & 0x9200 )
F_10 ( V_116 , V_107 ,
0xc00 , 0xc00 ) ;
}
break;
case V_251 :
F_32 ( V_116 , V_107 , 0x0010 ) ;
F_32 ( V_116 , V_53 , 0x0000 ) ;
F_32 ( V_116 , V_54 , 0x0000 ) ;
F_32 ( V_116 , V_58 , 0x0000 ) ;
F_32 ( V_116 , V_57 , 0x0000 ) ;
F_32 ( V_116 , V_55 , 0x0000 ) ;
F_32 ( V_116 , V_56 , 0x0000 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_35 ( struct V_115 * V_116 )
{
struct V_118 * V_119 = F_6 ( V_116 ) ;
V_119 -> V_116 = V_116 ;
F_10 ( V_116 , V_55 ,
V_252 | V_253 |
V_254 | V_255 ,
V_252 | V_253 |
V_254 | V_255 ) ;
F_16 ( 10000 , 15000 ) ;
F_10 ( V_116 , V_55 ,
V_144 | V_145 ,
V_144 | V_145 ) ;
F_36 ( V_116 , V_258 ) ;
return 0 ;
}
static int F_37 ( struct V_115 * V_116 )
{
struct V_118 * V_119 = F_6 ( V_116 ) ;
F_38 ( V_119 -> V_123 , true ) ;
F_39 ( V_119 -> V_123 ) ;
return 0 ;
}
static int F_40 ( struct V_115 * V_116 )
{
struct V_118 * V_119 = F_6 ( V_116 ) ;
F_38 ( V_119 -> V_123 , false ) ;
F_41 ( V_116 ) ;
return 0 ;
}
static int F_42 ( struct V_259 * V_260 ,
const struct V_261 * V_181 )
{
struct V_262 * V_263 = F_43 ( & V_260 -> V_2 ) ;
struct V_118 * V_119 ;
int V_230 ;
V_119 = F_44 ( & V_260 -> V_2 , sizeof( * V_119 ) ,
V_264 ) ;
if ( NULL == V_119 )
return - V_265 ;
F_45 ( V_260 , V_119 ) ;
if ( V_263 )
V_119 -> V_263 = * V_263 ;
V_119 -> V_123 = F_46 ( V_260 , & V_266 ) ;
if ( F_47 ( V_119 -> V_123 ) ) {
V_230 = F_48 ( V_119 -> V_123 ) ;
F_9 ( & V_260 -> V_2 , L_13 ,
V_230 ) ;
return V_230 ;
}
F_49 ( V_119 -> V_123 , V_19 , & V_230 ) ;
if ( V_230 != V_267 ) {
F_9 ( & V_260 -> V_2 ,
L_14 , V_230 ) ;
return - V_268 ;
}
F_15 ( V_119 -> V_123 , V_10 , 0 ) ;
V_230 = F_50 ( V_119 -> V_123 , V_269 ,
F_2 ( V_269 ) ) ;
if ( V_230 != 0 )
F_51 ( & V_260 -> V_2 , L_15 , V_230 ) ;
if ( V_119 -> V_263 . V_270 )
F_14 ( V_119 -> V_123 , V_24 ,
V_271 , V_271 ) ;
if ( V_119 -> V_263 . V_272 )
F_14 ( V_119 -> V_123 , V_90 ,
V_273 , V_274 ) ;
V_119 -> V_163 = 1 ;
V_230 = F_52 ( & V_260 -> V_2 , & V_275 ,
V_276 , F_2 ( V_276 ) ) ;
return V_230 ;
}
static int F_53 ( struct V_259 * V_260 )
{
F_54 ( & V_260 -> V_2 ) ;
return 0 ;
}
