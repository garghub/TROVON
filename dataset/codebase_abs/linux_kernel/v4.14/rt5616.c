static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_7 )
return true ;
}
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_7 )
return true ;
}
switch ( V_3 ) {
case V_8 :
case V_18 :
case V_16 :
case V_17 :
case V_19 :
case V_20 :
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
case V_9 :
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
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_10 :
case V_64 :
case V_65 :
case V_11 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_12 :
case V_13 :
case V_72 :
case V_73 :
case V_74 :
case V_14 :
case V_75 :
case V_15 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_92 * V_93 ,
struct V_92 * V_94 )
{
unsigned int V_95 ;
V_95 = F_5 ( F_6 ( V_93 -> V_96 ) , V_52 ) ;
V_95 &= V_97 ;
if ( V_95 == V_98 )
return 1 ;
else
return 0 ;
}
static int F_7 ( struct V_92 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_103 * V_104 = F_6 ( V_99 -> V_96 ) ;
switch ( V_102 ) {
case V_105 :
F_8 ( V_104 , V_25 ,
V_106 | V_107 , 0 ) ;
break;
case V_108 :
F_8 ( V_104 , V_25 ,
V_106 | V_107 ,
V_106 | V_107 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_9 ( struct V_92 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_103 * V_104 = F_6 ( V_99 -> V_96 ) ;
switch ( V_102 ) {
case V_105 :
F_8 ( V_104 , V_57 ,
V_109 , V_110 ) ;
F_8 ( V_104 , V_56 ,
V_111 | V_112 |
V_113 , V_114 |
V_115 | V_116 ) ;
F_10 ( V_104 , V_117 +
V_118 , 0x9f00 ) ;
F_8 ( V_104 , V_44 ,
V_119 | V_120 , 0 ) ;
F_8 ( V_104 , V_47 ,
V_121 | V_122 ,
V_121 | V_122 ) ;
F_8 ( V_104 , V_44 ,
V_123 | V_124 |
V_125 , V_123 |
V_124 | V_125 ) ;
F_11 ( 50 ) ;
F_8 ( V_104 , V_44 ,
V_119 | V_120 ,
V_119 | V_120 ) ;
F_8 ( V_104 , V_59 ,
V_126 , V_127 ) ;
F_8 ( V_104 , V_117 +
V_128 , 0x0200 , 0x0200 ) ;
F_8 ( V_104 , V_56 ,
V_129 | V_112 ,
V_130 | V_131 ) ;
break;
case V_132 :
F_8 ( V_104 , V_117 +
V_128 , 0x0200 , 0x0 ) ;
F_8 ( V_104 , V_56 ,
V_112 | V_133 |
V_134 , V_115 |
V_135 | V_136 ) ;
F_8 ( V_104 , V_56 ,
V_137 |
V_138 | V_129 |
V_111 | V_112 |
V_113 ,
V_139 | V_140 |
V_141 | V_142 |
V_131 | V_143 ) ;
F_8 ( V_104 , V_44 ,
V_123 | V_124 |
V_125 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_12 ( struct V_92 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_103 * V_104 = F_6 ( V_99 -> V_96 ) ;
switch ( V_102 ) {
case V_105 :
F_8 ( V_104 , V_58 ,
V_144 | V_145 |
V_146 ,
V_147 << V_148 |
V_149 << V_150 |
V_147 << V_151 ) ;
F_10 ( V_104 , V_117 +
V_152 , 0xfc00 ) ;
F_8 ( V_104 , V_56 ,
V_137 , V_153 ) ;
F_8 ( V_104 , V_56 ,
V_154 , V_155 ) ;
F_8 ( V_104 , V_56 ,
V_154 | V_133 |
V_134 , V_156 |
V_157 | V_158 ) ;
F_8 ( V_104 , V_19 ,
V_106 | V_107 , 0 ) ;
F_11 ( 100 ) ;
F_8 ( V_104 , V_56 ,
V_112 | V_133 |
V_134 , V_115 |
V_135 | V_136 ) ;
F_11 ( 20 ) ;
F_8 ( V_104 , V_85 ,
V_159 , V_160 ) ;
break;
case V_132 :
F_8 ( V_104 , V_58 ,
V_144 | V_145 |
V_146 ,
V_161 << V_148 |
V_149 << V_150 |
V_161 << V_151 ) ;
F_10 ( V_104 , V_117 +
V_152 , 0xfc00 ) ;
F_8 ( V_104 , V_56 ,
V_112 , V_131 ) ;
F_8 ( V_104 , V_56 ,
V_162 , V_163 ) ;
F_8 ( V_104 , V_56 ,
V_162 | V_133 |
V_134 , V_164 |
V_157 | V_158 ) ;
F_8 ( V_104 , V_85 ,
V_159 , V_165 ) ;
F_11 ( 90 ) ;
F_8 ( V_104 , V_19 ,
V_106 | V_107 ,
V_106 | V_107 ) ;
F_11 ( 30 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_13 ( struct V_92 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_103 * V_104 = F_6 ( V_99 -> V_96 ) ;
switch ( V_102 ) {
case V_105 :
F_8 ( V_104 , V_44 ,
V_166 , V_166 ) ;
F_8 ( V_104 , V_20 ,
V_106 | V_107 , 0 ) ;
break;
case V_132 :
F_8 ( V_104 , V_20 ,
V_106 | V_107 ,
V_106 | V_107 ) ;
F_8 ( V_104 , V_44 ,
V_166 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_14 ( struct V_92 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_103 * V_104 = F_6 ( V_99 -> V_96 ) ;
switch ( V_102 ) {
case V_105 :
F_8 ( V_104 , V_45 ,
V_167 , V_167 ) ;
break;
case V_132 :
F_8 ( V_104 , V_45 ,
V_167 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_15 ( struct V_92 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_103 * V_104 = F_6 ( V_99 -> V_96 ) ;
switch ( V_102 ) {
case V_105 :
F_8 ( V_104 , V_45 ,
V_168 , V_168 ) ;
break;
case V_132 :
F_8 ( V_104 , V_45 ,
V_168 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_16 ( struct V_169 * V_170 ,
struct V_171 * V_172 ,
struct V_173 * V_174 )
{
struct V_103 * V_104 = V_174 -> V_104 ;
struct V_175 * V_176 = F_17 ( V_104 ) ;
unsigned int V_177 = 0 , V_178 , V_179 ;
int V_180 , V_181 , V_182 ;
V_176 -> V_183 [ V_174 -> V_184 ] = F_18 ( V_172 ) ;
V_180 = F_19 ( V_176 -> V_185 , V_176 -> V_183 [ V_174 -> V_184 ] ) ;
if ( V_180 < 0 ) {
F_20 ( V_104 -> V_2 , L_1 ) ;
return - V_186 ;
}
V_182 = F_21 ( V_172 ) ;
if ( V_182 < 0 ) {
F_20 ( V_104 -> V_2 , L_2 , V_182 ) ;
return - V_186 ;
}
V_181 = V_182 > 32 ? 1 : 0 ;
V_176 -> V_187 [ V_174 -> V_184 ] = V_176 -> V_183 [ V_174 -> V_184 ] * ( 32 << V_181 ) ;
F_22 ( V_174 -> V_2 , L_3 ,
V_176 -> V_187 [ V_174 -> V_184 ] , V_176 -> V_183 [ V_174 -> V_184 ] ) ;
F_22 ( V_174 -> V_2 , L_4 ,
V_181 , V_180 , V_174 -> V_184 ) ;
switch ( F_23 ( V_172 ) ) {
case V_188 :
break;
case V_189 :
V_177 |= V_190 ;
break;
case V_191 :
V_177 |= V_192 ;
break;
case V_193 :
V_177 |= V_194 ;
break;
default:
return - V_186 ;
}
V_179 = V_195 ;
V_178 = V_180 << V_196 ;
F_8 ( V_104 , V_49 ,
V_197 , V_177 ) ;
F_8 ( V_104 , V_50 , V_179 , V_178 ) ;
return 0 ;
}
static int F_24 ( struct V_173 * V_174 , unsigned int V_198 )
{
struct V_103 * V_104 = V_174 -> V_104 ;
struct V_175 * V_176 = F_17 ( V_104 ) ;
unsigned int V_199 = 0 ;
switch ( V_198 & V_200 ) {
case V_201 :
V_176 -> V_202 [ V_174 -> V_184 ] = 1 ;
break;
case V_203 :
V_199 |= V_204 ;
V_176 -> V_202 [ V_174 -> V_184 ] = 0 ;
break;
default:
return - V_186 ;
}
switch ( V_198 & V_205 ) {
case V_206 :
break;
case V_207 :
V_199 |= V_208 ;
break;
default:
return - V_186 ;
}
switch ( V_198 & V_209 ) {
case V_210 :
break;
case V_211 :
V_199 |= V_212 ;
break;
case V_213 :
V_199 |= V_214 ;
break;
case V_215 :
V_199 |= V_216 ;
break;
default:
return - V_186 ;
}
F_8 ( V_104 , V_49 ,
V_217 | V_218 |
V_219 , V_199 ) ;
return 0 ;
}
static int F_25 ( struct V_173 * V_174 ,
int V_220 , unsigned int V_221 , int V_222 )
{
struct V_103 * V_104 = V_174 -> V_104 ;
struct V_175 * V_176 = F_17 ( V_104 ) ;
unsigned int V_199 = 0 ;
if ( V_221 == V_176 -> V_185 && V_220 == V_176 -> V_223 )
return 0 ;
switch ( V_220 ) {
case V_224 :
V_199 |= V_225 ;
break;
case V_226 :
V_199 |= V_98 ;
break;
default:
F_20 ( V_104 -> V_2 , L_5 , V_220 ) ;
return - V_186 ;
}
F_8 ( V_104 , V_52 ,
V_97 , V_199 ) ;
V_176 -> V_185 = V_221 ;
V_176 -> V_223 = V_220 ;
F_22 ( V_174 -> V_2 , L_6 , V_221 , V_220 ) ;
return 0 ;
}
static int F_26 ( struct V_173 * V_174 , int V_227 , int V_93 ,
unsigned int V_228 , unsigned int V_229 )
{
struct V_103 * V_104 = V_174 -> V_104 ;
struct V_175 * V_176 = F_17 ( V_104 ) ;
struct V_230 V_231 ;
int V_232 ;
if ( V_93 == V_176 -> V_233 && V_228 == V_176 -> V_234 &&
V_229 == V_176 -> V_235 )
return 0 ;
if ( ! V_228 || ! V_229 ) {
F_22 ( V_104 -> V_2 , L_7 ) ;
V_176 -> V_234 = 0 ;
V_176 -> V_235 = 0 ;
F_8 ( V_104 , V_52 ,
V_97 ,
V_225 ) ;
return 0 ;
}
switch ( V_93 ) {
case V_236 :
F_8 ( V_104 , V_52 ,
V_237 ,
V_238 ) ;
break;
case V_239 :
case V_240 :
F_8 ( V_104 , V_52 ,
V_237 ,
V_241 ) ;
break;
default:
F_20 ( V_104 -> V_2 , L_8 , V_93 ) ;
return - V_186 ;
}
V_232 = F_27 ( V_228 , V_229 , & V_231 ) ;
if ( V_232 < 0 ) {
F_20 ( V_104 -> V_2 , L_9 , V_228 ) ;
return V_232 ;
}
F_22 ( V_104 -> V_2 , L_10 ,
V_231 . V_242 , ( V_231 . V_242 ? 0 : V_231 . V_243 ) ,
V_231 . V_244 , V_231 . V_245 ) ;
F_10 ( V_104 , V_53 ,
V_231 . V_244 << V_246 | V_231 . V_245 ) ;
F_10 ( V_104 , V_54 ,
( V_231 . V_242 ? 0 : V_231 . V_243 ) <<
V_247 |
V_231 . V_242 << V_248 ) ;
V_176 -> V_234 = V_228 ;
V_176 -> V_235 = V_229 ;
V_176 -> V_233 = V_93 ;
return 0 ;
}
static int F_28 ( struct V_103 * V_104 ,
enum V_249 V_250 )
{
struct V_175 * V_176 = F_17 ( V_104 ) ;
int V_232 ;
switch ( V_250 ) {
case V_251 :
break;
case V_252 :
if ( F_29 ( V_176 -> V_253 ) )
break;
if ( F_30 ( V_104 ) == V_251 ) {
F_31 ( V_176 -> V_253 ) ;
} else {
V_232 = F_32 ( V_176 -> V_253 ) ;
if ( V_232 )
return V_232 ;
}
break;
case V_254 :
if ( F_30 ( V_104 ) == V_255 ) {
F_8 ( V_104 , V_44 ,
V_256 | V_257 |
V_258 | V_259 ,
V_256 | V_257 |
V_258 | V_259 ) ;
F_33 ( 10 ) ;
F_8 ( V_104 , V_44 ,
V_119 | V_120 ,
V_119 | V_120 ) ;
F_8 ( V_104 , V_89 ,
V_260 ,
V_260 ) ;
}
break;
case V_255 :
F_8 ( V_104 , V_89 , V_260 , 0 ) ;
F_10 ( V_104 , V_42 , 0x0000 ) ;
F_10 ( V_104 , V_43 , 0x0000 ) ;
F_10 ( V_104 , V_47 , 0x0000 ) ;
F_10 ( V_104 , V_46 , 0x0000 ) ;
F_10 ( V_104 , V_44 , 0x0000 ) ;
F_10 ( V_104 , V_45 , 0x0000 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_34 ( struct V_103 * V_104 )
{
struct V_175 * V_176 = F_17 ( V_104 ) ;
V_176 -> V_253 = F_35 ( V_104 -> V_2 , L_11 ) ;
if ( F_36 ( V_176 -> V_253 ) == - V_261 )
return - V_261 ;
V_176 -> V_104 = V_104 ;
return 0 ;
}
static int F_37 ( struct V_103 * V_104 )
{
struct V_175 * V_176 = F_17 ( V_104 ) ;
F_38 ( V_176 -> V_262 , true ) ;
F_39 ( V_176 -> V_262 ) ;
return 0 ;
}
static int F_40 ( struct V_103 * V_104 )
{
struct V_175 * V_176 = F_17 ( V_104 ) ;
F_38 ( V_176 -> V_262 , false ) ;
F_41 ( V_176 -> V_262 ) ;
return 0 ;
}
static int F_42 ( struct V_263 * V_264 ,
const struct V_265 * V_184 )
{
struct V_175 * V_176 ;
unsigned int V_95 ;
int V_232 ;
V_176 = F_43 ( & V_264 -> V_2 , sizeof( struct V_175 ) ,
V_266 ) ;
if ( ! V_176 )
return - V_267 ;
F_44 ( V_264 , V_176 ) ;
V_176 -> V_262 = F_45 ( V_264 , & V_268 ) ;
if ( F_29 ( V_176 -> V_262 ) ) {
V_232 = F_36 ( V_176 -> V_262 ) ;
F_20 ( & V_264 -> V_2 , L_12 ,
V_232 ) ;
return V_232 ;
}
F_46 ( V_176 -> V_262 , V_17 , & V_95 ) ;
if ( V_95 != 0x6281 ) {
F_20 ( & V_264 -> V_2 ,
L_13 ,
V_95 ) ;
return - V_269 ;
}
F_47 ( V_176 -> V_262 , V_8 , 0 ) ;
F_48 ( V_176 -> V_262 , V_44 ,
V_256 | V_257 |
V_258 | V_259 ,
V_256 | V_257 |
V_258 | V_259 ) ;
F_33 ( 10 ) ;
F_48 ( V_176 -> V_262 , V_44 ,
V_119 | V_120 ,
V_119 | V_120 ) ;
V_232 = F_49 ( V_176 -> V_262 , V_270 ,
F_2 ( V_270 ) ) ;
if ( V_232 != 0 )
F_50 ( & V_264 -> V_2 , L_14 , V_232 ) ;
F_48 ( V_176 -> V_262 , V_44 ,
V_271 , V_272 ) ;
return F_51 ( & V_264 -> V_2 , & V_273 ,
V_274 , F_2 ( V_274 ) ) ;
}
static int F_52 ( struct V_263 * V_264 )
{
F_53 ( & V_264 -> V_2 ) ;
return 0 ;
}
static void F_54 ( struct V_263 * V_275 )
{
struct V_175 * V_176 = F_55 ( V_275 ) ;
F_47 ( V_176 -> V_262 , V_19 , 0xc8c8 ) ;
F_47 ( V_176 -> V_262 , V_20 , 0xc8c8 ) ;
}
