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
int V_120 = - V_121 ;
V_120 = F_7 ( V_119 -> V_122 ) ;
if ( V_120 < 0 )
F_8 ( V_116 -> V_2 , L_1 ) ;
else
F_9 ( V_116 , V_64 , V_123 ,
V_120 << V_124 ) ;
return V_120 ;
}
static int F_10 ( struct V_110 * V_125 ,
struct V_110 * V_126 )
{
struct V_115 * V_116 = F_5 ( V_125 -> V_117 ) ;
unsigned int V_127 ;
V_127 = F_11 ( V_116 , V_68 ) ;
V_127 &= V_128 ;
if ( V_127 == V_129 )
return 1 ;
else
return 0 ;
}
static int F_12 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
switch ( V_114 ) {
case V_130 :
F_13 ( V_119 -> V_131 , V_132 +
V_133 , 0x0700 , 0x0200 ) ;
F_13 ( V_119 -> V_131 , V_79 ,
V_134 , V_135 ) ;
F_13 ( V_119 -> V_131 , V_78 ,
V_136 | V_137 |
V_138 , V_139 |
V_140 | V_141 ) ;
F_14 ( V_119 -> V_131 , V_132 +
V_142 , 0x9f00 ) ;
F_13 ( V_119 -> V_131 , V_55 ,
V_143 | V_144 , 0 ) ;
F_13 ( V_119 -> V_131 , V_55 ,
V_145 ,
V_145 ) ;
F_15 ( 10000 , 15000 ) ;
F_13 ( V_119 -> V_131 , V_55 ,
V_143 | V_144 ,
V_143 | V_144 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_16 ( struct V_110 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
switch ( V_114 ) {
case V_130 :
F_13 ( V_119 -> V_131 , V_79 ,
V_134 | V_146 ,
V_147 | V_148 ) ;
F_13 ( V_119 -> V_131 , V_81 ,
V_149 , V_150 ) ;
F_13 ( V_119 -> V_131 , V_80 ,
V_151 | V_152 |
V_153 ,
( V_154 << V_155 ) |
( V_156 << V_157 ) |
( V_154 << V_158 ) ) ;
F_14 ( V_119 -> V_131 , V_132 +
V_159 , 0x1c00 ) ;
F_13 ( V_119 -> V_131 , V_78 ,
V_136 | V_137 ,
V_160 | V_161 ) ;
F_13 ( V_119 -> V_131 , V_132 +
V_133 , 0x0700 , 0x0400 ) ;
V_119 -> V_162 = 0 ;
break;
case V_163 :
V_119 -> V_162 = 1 ;
F_15 ( 70000 , 75000 ) ;
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
case V_130 :
if ( ! V_119 -> V_162 )
F_15 ( 80000 , 85000 ) ;
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
switch ( V_114 ) {
case V_130 :
F_9 ( V_116 , V_56 ,
V_164 , V_164 ) ;
break;
case V_163 :
F_9 ( V_116 , V_56 ,
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
struct V_115 * V_116 = F_5 ( V_111 -> V_117 ) ;
switch ( V_114 ) {
case V_130 :
F_9 ( V_116 , V_56 ,
V_165 , V_165 ) ;
break;
case V_163 :
F_9 ( V_116 , V_56 ,
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
case V_130 :
F_9 ( V_116 , V_56 ,
V_166 , V_166 ) ;
break;
case V_163 :
F_9 ( V_116 , V_56 ,
V_166 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_21 ( struct V_167 * V_168 ,
struct V_169 * V_170 , struct V_171 * V_172 )
{
struct V_115 * V_116 = V_172 -> V_116 ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
unsigned int V_173 = 0 , V_174 , V_175 ;
int V_176 , V_177 , V_178 ;
V_119 -> V_179 [ V_172 -> V_180 ] = F_22 ( V_170 ) ;
V_176 = F_23 ( V_119 -> V_122 , V_119 -> V_179 [ V_172 -> V_180 ] ) ;
if ( V_176 < 0 ) {
F_8 ( V_116 -> V_2 , L_2 ) ;
return - V_121 ;
}
V_178 = F_24 ( V_170 ) ;
if ( V_178 < 0 ) {
F_8 ( V_116 -> V_2 , L_3 , V_178 ) ;
return - V_121 ;
}
V_177 = V_178 > 32 ? 1 : 0 ;
V_119 -> V_181 [ V_172 -> V_180 ] = V_119 -> V_179 [ V_172 -> V_180 ] * ( 32 << V_177 ) ;
F_25 ( V_172 -> V_2 , L_4 ,
V_119 -> V_181 [ V_172 -> V_180 ] , V_119 -> V_179 [ V_172 -> V_180 ] ) ;
F_25 ( V_172 -> V_2 , L_5 ,
V_177 , V_176 , V_172 -> V_180 ) ;
switch ( F_26 ( V_170 ) ) {
case 16 :
break;
case 20 :
V_173 |= V_182 ;
break;
case 24 :
V_173 |= V_183 ;
break;
case 8 :
V_173 |= V_184 ;
break;
default:
return - V_121 ;
}
switch ( V_172 -> V_180 ) {
case V_185 :
V_175 = V_186 ;
V_174 = V_176 << V_187 ;
F_9 ( V_116 , V_60 ,
V_188 , V_173 ) ;
F_9 ( V_116 , V_62 , V_175 , V_174 ) ;
break;
case V_189 :
V_175 = V_190 | V_191 ;
V_174 = V_176 << V_192 ;
F_9 ( V_116 , V_61 ,
V_188 , V_173 ) ;
F_9 ( V_116 , V_62 , V_175 , V_174 ) ;
break;
default:
F_8 ( V_116 -> V_2 , L_6 , V_172 -> V_180 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_27 ( struct V_171 * V_172 , unsigned int V_193 )
{
struct V_115 * V_116 = V_172 -> V_116 ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
unsigned int V_194 = 0 ;
switch ( V_193 & V_195 ) {
case V_196 :
V_119 -> V_197 [ V_172 -> V_180 ] = 1 ;
break;
case V_198 :
V_194 |= V_199 ;
V_119 -> V_197 [ V_172 -> V_180 ] = 0 ;
break;
default:
return - V_121 ;
}
switch ( V_193 & V_200 ) {
case V_201 :
break;
case V_202 :
V_194 |= V_203 ;
break;
default:
return - V_121 ;
}
switch ( V_193 & V_204 ) {
case V_205 :
break;
case V_206 :
V_194 |= V_207 ;
break;
case V_208 :
V_194 |= V_209 ;
break;
case V_210 :
V_194 |= V_211 ;
break;
default:
return - V_121 ;
}
switch ( V_172 -> V_180 ) {
case V_185 :
F_9 ( V_116 , V_60 ,
V_212 | V_213 |
V_214 , V_194 ) ;
break;
case V_189 :
F_9 ( V_116 , V_61 ,
V_212 | V_213 |
V_214 , V_194 ) ;
break;
default:
F_8 ( V_116 -> V_2 , L_6 , V_172 -> V_180 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_28 ( struct V_171 * V_172 ,
int V_215 , unsigned int V_216 , int V_217 )
{
struct V_115 * V_116 = V_172 -> V_116 ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
unsigned int V_194 = 0 ;
if ( V_216 == V_119 -> V_122 && V_215 == V_119 -> V_218 )
return 0 ;
switch ( V_215 ) {
case V_219 :
V_194 |= V_220 ;
break;
case V_221 :
V_194 |= V_129 ;
break;
case V_222 :
V_194 |= V_223 ;
break;
default:
F_8 ( V_116 -> V_2 , L_7 , V_215 ) ;
return - V_121 ;
}
F_9 ( V_116 , V_68 ,
V_128 , V_194 ) ;
V_119 -> V_122 = V_216 ;
V_119 -> V_218 = V_215 ;
F_25 ( V_172 -> V_2 , L_8 , V_216 , V_215 ) ;
return 0 ;
}
static int F_29 ( struct V_171 * V_172 , int V_224 , int V_125 ,
unsigned int V_225 , unsigned int V_226 )
{
struct V_115 * V_116 = V_172 -> V_116 ;
struct V_118 * V_119 = F_6 ( V_116 ) ;
struct V_227 V_228 ;
int V_229 ;
if ( V_125 == V_119 -> V_230 && V_225 == V_119 -> V_231 &&
V_226 == V_119 -> V_232 )
return 0 ;
if ( ! V_225 || ! V_226 ) {
F_25 ( V_116 -> V_2 , L_9 ) ;
V_119 -> V_231 = 0 ;
V_119 -> V_232 = 0 ;
F_9 ( V_116 , V_68 ,
V_128 , V_220 ) ;
return 0 ;
}
switch ( V_125 ) {
case V_233 :
F_9 ( V_116 , V_68 ,
V_234 , V_235 ) ;
break;
case V_236 :
F_9 ( V_116 , V_68 ,
V_234 , V_237 ) ;
break;
case V_238 :
F_9 ( V_116 , V_68 ,
V_234 , V_239 ) ;
break;
default:
F_8 ( V_116 -> V_2 , L_10 , V_125 ) ;
return - V_121 ;
}
V_229 = F_30 ( V_225 , V_226 , & V_228 ) ;
if ( V_229 < 0 ) {
F_8 ( V_116 -> V_2 , L_11 , V_225 ) ;
return V_229 ;
}
F_25 ( V_116 -> V_2 , L_12 ,
V_228 . V_240 , ( V_228 . V_240 ? 0 : V_228 . V_241 ) ,
V_228 . V_242 , V_228 . V_243 ) ;
F_31 ( V_116 , V_69 ,
V_228 . V_242 << V_244 | V_228 . V_243 ) ;
F_31 ( V_116 , V_70 ,
( V_228 . V_240 ? 0 : V_228 . V_241 ) << V_245 |
V_228 . V_240 << V_246 ) ;
V_119 -> V_231 = V_225 ;
V_119 -> V_232 = V_226 ;
V_119 -> V_230 = V_125 ;
return 0 ;
}
static int F_32 ( struct V_115 * V_116 ,
enum V_247 V_248 )
{
switch ( V_248 ) {
case V_249 :
if ( V_250 == F_33 ( V_116 ) ) {
F_9 ( V_116 , V_55 ,
V_251 | V_252 |
V_253 | V_254 ,
V_251 | V_252 |
V_253 | V_254 ) ;
F_15 ( 10000 , 15000 ) ;
F_9 ( V_116 , V_55 ,
V_143 | V_144 ,
V_143 | V_144 ) ;
F_9 ( V_116 , V_55 ,
V_255 ,
V_256 ) ;
F_9 ( V_116 , V_107 , 0x1 , 0x1 ) ;
if ( F_11 ( V_116 , V_71 ) & 0x9200 )
F_9 ( V_116 , V_107 ,
0xc00 , 0xc00 ) ;
}
break;
case V_250 :
F_31 ( V_116 , V_107 , 0x0010 ) ;
F_31 ( V_116 , V_53 , 0x0000 ) ;
F_31 ( V_116 , V_54 , 0x0000 ) ;
F_31 ( V_116 , V_58 , 0x0000 ) ;
F_31 ( V_116 , V_57 , 0x0000 ) ;
F_31 ( V_116 , V_55 , 0x0000 ) ;
F_31 ( V_116 , V_56 , 0x0000 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_34 ( struct V_115 * V_116 )
{
struct V_118 * V_119 = F_6 ( V_116 ) ;
V_119 -> V_116 = V_116 ;
F_9 ( V_116 , V_55 ,
V_251 | V_252 |
V_253 | V_254 ,
V_251 | V_252 |
V_253 | V_254 ) ;
F_15 ( 10000 , 15000 ) ;
F_9 ( V_116 , V_55 ,
V_143 | V_144 ,
V_143 | V_144 ) ;
F_35 ( V_116 , V_257 ) ;
return 0 ;
}
static int F_36 ( struct V_115 * V_116 )
{
struct V_118 * V_119 = F_6 ( V_116 ) ;
F_37 ( V_119 -> V_131 , true ) ;
F_38 ( V_119 -> V_131 ) ;
return 0 ;
}
static int F_39 ( struct V_115 * V_116 )
{
struct V_118 * V_119 = F_6 ( V_116 ) ;
F_37 ( V_119 -> V_131 , false ) ;
F_40 ( V_116 ) ;
return 0 ;
}
static int F_41 ( struct V_258 * V_259 ,
const struct V_260 * V_180 )
{
struct V_261 * V_262 = F_42 ( & V_259 -> V_2 ) ;
struct V_118 * V_119 ;
int V_229 ;
V_119 = F_43 ( & V_259 -> V_2 , sizeof( * V_119 ) ,
V_263 ) ;
if ( NULL == V_119 )
return - V_264 ;
F_44 ( V_259 , V_119 ) ;
if ( V_262 )
V_119 -> V_262 = * V_262 ;
V_119 -> V_131 = F_45 ( V_259 , & V_265 ) ;
if ( F_46 ( V_119 -> V_131 ) ) {
V_229 = F_47 ( V_119 -> V_131 ) ;
F_8 ( & V_259 -> V_2 , L_13 ,
V_229 ) ;
return V_229 ;
}
F_48 ( V_119 -> V_131 , V_19 , & V_229 ) ;
if ( V_229 != V_266 ) {
F_8 ( & V_259 -> V_2 ,
L_14 , V_229 ) ;
return - V_267 ;
}
F_14 ( V_119 -> V_131 , V_10 , 0 ) ;
V_229 = F_49 ( V_119 -> V_131 , V_268 ,
F_2 ( V_268 ) ) ;
if ( V_229 != 0 )
F_50 ( & V_259 -> V_2 , L_15 , V_229 ) ;
if ( V_119 -> V_262 . V_269 )
F_13 ( V_119 -> V_131 , V_24 ,
V_270 , V_270 ) ;
if ( V_119 -> V_262 . V_271 )
F_13 ( V_119 -> V_131 , V_90 ,
V_272 , V_273 ) ;
V_119 -> V_162 = 1 ;
V_229 = F_51 ( & V_259 -> V_2 , & V_274 ,
V_275 , F_2 ( V_275 ) ) ;
return V_229 ;
}
static int F_52 ( struct V_258 * V_259 )
{
F_53 ( & V_259 -> V_2 ) ;
return 0 ;
}
