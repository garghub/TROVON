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
struct V_115 * V_116 = V_111 -> V_116 ;
struct V_117 * V_118 = F_5 ( V_116 ) ;
int V_119 = - V_120 ;
V_119 = F_6 ( V_118 -> V_121 ) ;
if ( V_119 < 0 )
F_7 ( V_116 -> V_2 , L_1 ) ;
else
F_8 ( V_116 , V_64 , V_122 ,
V_119 << V_123 ) ;
return V_119 ;
}
static int F_9 ( struct V_110 * V_124 ,
struct V_110 * V_125 )
{
unsigned int V_126 ;
V_126 = F_10 ( V_124 -> V_116 , V_68 ) ;
V_126 &= V_127 ;
if ( V_126 == V_128 )
return 1 ;
else
return 0 ;
}
static int F_11 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = V_111 -> V_116 ;
struct V_117 * V_118 = F_5 ( V_116 ) ;
switch ( V_114 ) {
case V_129 :
F_12 ( V_118 -> V_130 , V_131 +
V_132 , 0x0700 , 0x0200 ) ;
F_12 ( V_118 -> V_130 , V_79 ,
V_133 , V_134 ) ;
F_12 ( V_118 -> V_130 , V_78 ,
V_135 | V_136 |
V_137 , V_138 |
V_139 | V_140 ) ;
F_13 ( V_118 -> V_130 , V_131 +
V_141 , 0x9f00 ) ;
F_12 ( V_118 -> V_130 , V_55 ,
V_142 | V_143 , 0 ) ;
F_12 ( V_118 -> V_130 , V_55 ,
V_144 ,
V_144 ) ;
F_14 ( 10000 , 15000 ) ;
F_12 ( V_118 -> V_130 , V_55 ,
V_142 | V_143 ,
V_142 | V_143 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_15 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = V_111 -> V_116 ;
struct V_117 * V_118 = F_5 ( V_116 ) ;
switch ( V_114 ) {
case V_129 :
F_12 ( V_118 -> V_130 , V_79 ,
V_133 | V_145 ,
V_146 | V_147 ) ;
F_12 ( V_118 -> V_130 , V_81 ,
V_148 , V_149 ) ;
F_12 ( V_118 -> V_130 , V_80 ,
V_150 | V_151 |
V_152 ,
( V_153 << V_154 ) |
( V_155 << V_156 ) |
( V_153 << V_157 ) ) ;
F_13 ( V_118 -> V_130 , V_131 +
V_158 , 0x1c00 ) ;
F_12 ( V_118 -> V_130 , V_78 ,
V_135 | V_136 ,
V_159 | V_160 ) ;
F_12 ( V_118 -> V_130 , V_131 +
V_132 , 0x0700 , 0x0400 ) ;
V_118 -> V_161 = 0 ;
break;
case V_162 :
V_118 -> V_161 = 1 ;
F_14 ( 70000 , 75000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_16 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = V_111 -> V_116 ;
struct V_117 * V_118 = F_5 ( V_116 ) ;
switch ( V_114 ) {
case V_129 :
if ( ! V_118 -> V_161 )
F_14 ( 80000 , 85000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_17 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = V_111 -> V_116 ;
switch ( V_114 ) {
case V_129 :
F_8 ( V_116 , V_56 ,
V_163 , V_163 ) ;
break;
case V_162 :
F_8 ( V_116 , V_56 ,
V_163 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_18 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = V_111 -> V_116 ;
switch ( V_114 ) {
case V_129 :
F_8 ( V_116 , V_56 ,
V_164 , V_164 ) ;
break;
case V_162 :
F_8 ( V_116 , V_56 ,
V_164 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_19 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = V_111 -> V_116 ;
switch ( V_114 ) {
case V_129 :
F_8 ( V_116 , V_56 ,
V_165 , V_165 ) ;
break;
case V_162 :
F_8 ( V_116 , V_56 ,
V_165 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_166 * V_167 ,
struct V_168 * V_169 , struct V_170 * V_171 )
{
struct V_115 * V_116 = V_171 -> V_116 ;
struct V_117 * V_118 = F_5 ( V_116 ) ;
unsigned int V_172 = 0 , V_173 , V_174 ;
int V_175 , V_176 , V_177 ;
V_118 -> V_178 [ V_171 -> V_179 ] = F_21 ( V_169 ) ;
V_175 = F_22 ( V_118 -> V_121 , V_118 -> V_178 [ V_171 -> V_179 ] ) ;
if ( V_175 < 0 ) {
F_7 ( V_116 -> V_2 , L_2 ) ;
return - V_120 ;
}
V_177 = F_23 ( V_169 ) ;
if ( V_177 < 0 ) {
F_7 ( V_116 -> V_2 , L_3 , V_177 ) ;
return - V_120 ;
}
V_176 = V_177 > 32 ? 1 : 0 ;
V_118 -> V_180 [ V_171 -> V_179 ] = V_118 -> V_178 [ V_171 -> V_179 ] * ( 32 << V_176 ) ;
F_24 ( V_171 -> V_2 , L_4 ,
V_118 -> V_180 [ V_171 -> V_179 ] , V_118 -> V_178 [ V_171 -> V_179 ] ) ;
F_24 ( V_171 -> V_2 , L_5 ,
V_176 , V_175 , V_171 -> V_179 ) ;
switch ( F_25 ( V_169 ) ) {
case 16 :
break;
case 20 :
V_172 |= V_181 ;
break;
case 24 :
V_172 |= V_182 ;
break;
case 8 :
V_172 |= V_183 ;
break;
default:
return - V_120 ;
}
switch ( V_171 -> V_179 ) {
case V_184 :
V_174 = V_185 ;
V_173 = V_175 << V_186 ;
F_8 ( V_116 , V_60 ,
V_187 , V_172 ) ;
F_8 ( V_116 , V_62 , V_174 , V_173 ) ;
break;
case V_188 :
V_174 = V_189 | V_190 ;
V_173 = V_175 << V_191 ;
F_8 ( V_116 , V_61 ,
V_187 , V_172 ) ;
F_8 ( V_116 , V_62 , V_174 , V_173 ) ;
break;
default:
F_7 ( V_116 -> V_2 , L_6 , V_171 -> V_179 ) ;
return - V_120 ;
}
return 0 ;
}
static int F_26 ( struct V_170 * V_171 , unsigned int V_192 )
{
struct V_115 * V_116 = V_171 -> V_116 ;
struct V_117 * V_118 = F_5 ( V_116 ) ;
unsigned int V_193 = 0 ;
switch ( V_192 & V_194 ) {
case V_195 :
V_118 -> V_196 [ V_171 -> V_179 ] = 1 ;
break;
case V_197 :
V_193 |= V_198 ;
V_118 -> V_196 [ V_171 -> V_179 ] = 0 ;
break;
default:
return - V_120 ;
}
switch ( V_192 & V_199 ) {
case V_200 :
break;
case V_201 :
V_193 |= V_202 ;
break;
default:
return - V_120 ;
}
switch ( V_192 & V_203 ) {
case V_204 :
break;
case V_205 :
V_193 |= V_206 ;
break;
case V_207 :
V_193 |= V_208 ;
break;
case V_209 :
V_193 |= V_210 ;
break;
default:
return - V_120 ;
}
switch ( V_171 -> V_179 ) {
case V_184 :
F_8 ( V_116 , V_60 ,
V_211 | V_212 |
V_213 , V_193 ) ;
break;
case V_188 :
F_8 ( V_116 , V_61 ,
V_211 | V_212 |
V_213 , V_193 ) ;
break;
default:
F_7 ( V_116 -> V_2 , L_6 , V_171 -> V_179 ) ;
return - V_120 ;
}
return 0 ;
}
static int F_27 ( struct V_170 * V_171 ,
int V_214 , unsigned int V_215 , int V_216 )
{
struct V_115 * V_116 = V_171 -> V_116 ;
struct V_117 * V_118 = F_5 ( V_116 ) ;
unsigned int V_193 = 0 ;
if ( V_215 == V_118 -> V_121 && V_214 == V_118 -> V_217 )
return 0 ;
switch ( V_214 ) {
case V_218 :
V_193 |= V_219 ;
break;
case V_220 :
V_193 |= V_128 ;
break;
case V_221 :
V_193 |= V_222 ;
break;
default:
F_7 ( V_116 -> V_2 , L_7 , V_214 ) ;
return - V_120 ;
}
F_8 ( V_116 , V_68 ,
V_127 , V_193 ) ;
V_118 -> V_121 = V_215 ;
V_118 -> V_217 = V_214 ;
F_24 ( V_171 -> V_2 , L_8 , V_215 , V_214 ) ;
return 0 ;
}
static int F_28 ( struct V_170 * V_171 , int V_223 , int V_124 ,
unsigned int V_224 , unsigned int V_225 )
{
struct V_115 * V_116 = V_171 -> V_116 ;
struct V_117 * V_118 = F_5 ( V_116 ) ;
struct V_226 V_227 ;
int V_228 ;
if ( V_124 == V_118 -> V_229 && V_224 == V_118 -> V_230 &&
V_225 == V_118 -> V_231 )
return 0 ;
if ( ! V_224 || ! V_225 ) {
F_24 ( V_116 -> V_2 , L_9 ) ;
V_118 -> V_230 = 0 ;
V_118 -> V_231 = 0 ;
F_8 ( V_116 , V_68 ,
V_127 , V_219 ) ;
return 0 ;
}
switch ( V_124 ) {
case V_232 :
F_8 ( V_116 , V_68 ,
V_233 , V_234 ) ;
break;
case V_235 :
F_8 ( V_116 , V_68 ,
V_233 , V_236 ) ;
break;
case V_237 :
F_8 ( V_116 , V_68 ,
V_233 , V_238 ) ;
break;
default:
F_7 ( V_116 -> V_2 , L_10 , V_124 ) ;
return - V_120 ;
}
V_228 = F_29 ( V_224 , V_225 , & V_227 ) ;
if ( V_228 < 0 ) {
F_7 ( V_116 -> V_2 , L_11 , V_224 ) ;
return V_228 ;
}
F_24 ( V_116 -> V_2 , L_12 ,
V_227 . V_239 , ( V_227 . V_239 ? 0 : V_227 . V_240 ) ,
V_227 . V_241 , V_227 . V_242 ) ;
F_30 ( V_116 , V_69 ,
V_227 . V_241 << V_243 | V_227 . V_242 ) ;
F_30 ( V_116 , V_70 ,
( V_227 . V_239 ? 0 : V_227 . V_240 ) << V_244 |
V_227 . V_239 << V_245 ) ;
V_118 -> V_230 = V_224 ;
V_118 -> V_231 = V_225 ;
V_118 -> V_229 = V_124 ;
return 0 ;
}
static int F_31 ( struct V_115 * V_116 ,
enum V_246 V_247 )
{
switch ( V_247 ) {
case V_248 :
if ( V_249 == V_116 -> V_250 . V_251 ) {
F_8 ( V_116 , V_55 ,
V_252 | V_253 |
V_254 | V_255 ,
V_252 | V_253 |
V_254 | V_255 ) ;
F_14 ( 10000 , 15000 ) ;
F_8 ( V_116 , V_55 ,
V_142 | V_143 ,
V_142 | V_143 ) ;
F_8 ( V_116 , V_55 ,
V_256 ,
V_257 ) ;
F_8 ( V_116 , V_107 , 0x1 , 0x1 ) ;
if ( F_10 ( V_116 , V_71 ) & 0x9200 )
F_8 ( V_116 , V_107 ,
0xc00 , 0xc00 ) ;
}
break;
case V_249 :
F_30 ( V_116 , V_107 , 0x0010 ) ;
F_30 ( V_116 , V_53 , 0x0000 ) ;
F_30 ( V_116 , V_54 , 0x0000 ) ;
F_30 ( V_116 , V_58 , 0x0000 ) ;
F_30 ( V_116 , V_57 , 0x0000 ) ;
F_30 ( V_116 , V_55 , 0x0000 ) ;
F_30 ( V_116 , V_56 , 0x0000 ) ;
break;
default:
break;
}
V_116 -> V_250 . V_251 = V_247 ;
return 0 ;
}
static int F_32 ( struct V_115 * V_116 )
{
struct V_117 * V_118 = F_5 ( V_116 ) ;
V_118 -> V_116 = V_116 ;
F_8 ( V_116 , V_55 ,
V_252 | V_253 |
V_254 | V_255 ,
V_252 | V_253 |
V_254 | V_255 ) ;
F_14 ( 10000 , 15000 ) ;
F_8 ( V_116 , V_55 ,
V_142 | V_143 ,
V_142 | V_143 ) ;
F_31 ( V_116 , V_258 ) ;
return 0 ;
}
static int F_33 ( struct V_115 * V_116 )
{
struct V_117 * V_118 = F_5 ( V_116 ) ;
F_34 ( V_118 -> V_130 , true ) ;
F_35 ( V_118 -> V_130 ) ;
return 0 ;
}
static int F_36 ( struct V_115 * V_116 )
{
struct V_117 * V_118 = F_5 ( V_116 ) ;
F_34 ( V_118 -> V_130 , false ) ;
F_37 ( V_116 ) ;
return 0 ;
}
static int F_38 ( struct V_259 * V_260 ,
const struct V_261 * V_179 )
{
struct V_262 * V_263 = F_39 ( & V_260 -> V_2 ) ;
struct V_117 * V_118 ;
int V_228 ;
V_118 = F_40 ( & V_260 -> V_2 , sizeof( * V_118 ) ,
V_264 ) ;
if ( NULL == V_118 )
return - V_265 ;
F_41 ( V_260 , V_118 ) ;
if ( V_263 )
V_118 -> V_263 = * V_263 ;
V_118 -> V_130 = F_42 ( V_260 , & V_266 ) ;
if ( F_43 ( V_118 -> V_130 ) ) {
V_228 = F_44 ( V_118 -> V_130 ) ;
F_7 ( & V_260 -> V_2 , L_13 ,
V_228 ) ;
return V_228 ;
}
F_45 ( V_118 -> V_130 , V_19 , & V_228 ) ;
if ( V_228 != V_267 ) {
F_7 ( & V_260 -> V_2 ,
L_14 , V_228 ) ;
return - V_268 ;
}
F_13 ( V_118 -> V_130 , V_10 , 0 ) ;
V_228 = F_46 ( V_118 -> V_130 , V_269 ,
F_2 ( V_269 ) ) ;
if ( V_228 != 0 )
F_47 ( & V_260 -> V_2 , L_15 , V_228 ) ;
if ( V_118 -> V_263 . V_270 )
F_12 ( V_118 -> V_130 , V_24 ,
V_271 , V_271 ) ;
if ( V_118 -> V_263 . V_272 )
F_12 ( V_118 -> V_130 , V_90 ,
V_273 , V_274 ) ;
V_118 -> V_161 = 1 ;
V_228 = F_48 ( & V_260 -> V_2 , & V_275 ,
V_276 , F_2 ( V_276 ) ) ;
return V_228 ;
}
static int F_49 ( struct V_259 * V_260 )
{
F_50 ( & V_260 -> V_2 ) ;
return 0 ;
}
