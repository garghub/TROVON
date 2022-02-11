static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
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
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_6 :
case V_53 :
case V_54 :
case V_55 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
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
case V_12 :
case V_75 :
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
case V_92 :
case V_93 :
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
return true ;
default:
return true ;
}
}
static int F_3 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
unsigned int V_111 , V_112 , V_113 ;
V_112 = F_5 ( V_108 , V_26 ) ;
F_6 ( V_108 , V_26 ,
V_114 , 0 ) ;
switch ( V_110 -> V_115 ) {
case V_116 :
F_7 ( V_108 -> V_2 , L_1 , V_110 -> V_117 ) ;
V_112 &= ~ V_114 ;
V_113 = V_110 -> V_117 ;
F_6 ( V_108 , V_65 ,
V_118 | V_119 , 0 ) ;
break;
case V_120 :
F_7 ( V_108 -> V_2 , L_2 ,
V_110 -> V_121 ) ;
V_112 |= V_114 ;
V_113 = V_110 -> V_121 ;
break;
default:
F_8 ( V_108 -> V_2 , L_3 ) ;
return - V_122 ;
}
if ( V_113 > 13500000 ) {
V_111 = V_123 ;
V_110 -> V_124 = V_113 / 2 ;
} else {
V_111 = 0 ;
V_110 -> V_124 = V_113 ;
}
F_6 ( V_108 , V_24 , V_123 ,
V_111 ) ;
F_6 ( V_108 , V_26 ,
V_125 | V_114 , V_112 ) ;
F_7 ( V_108 -> V_2 , L_4 , V_110 -> V_124 ) ;
return 0 ;
}
static void F_9 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_126 * V_127 = V_110 -> V_127 ;
int V_128 , V_129 ;
V_128 = F_5 ( V_108 , V_39 ) ;
for ( V_129 = 0 ; V_129 < V_130 ; V_129 ++ )
F_6 ( V_108 , V_39 + V_129 , 0xffff ,
V_127 -> V_131 [ V_110 -> V_132 ] . V_133 [ V_129 ] ) ;
F_6 ( V_108 , V_39 ,
V_134 | V_135 , V_128 ) ;
}
static int F_10 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_107 * V_108 = F_11 ( V_137 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_126 * V_127 = V_110 -> V_127 ;
int V_140 = V_139 -> V_140 . integer . V_140 [ 0 ] ;
if ( V_140 >= V_127 -> V_141 )
return - V_122 ;
V_110 -> V_132 = V_140 ;
F_9 ( V_108 ) ;
return 0 ;
}
static int F_12 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_107 * V_108 = F_11 ( V_137 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
V_139 -> V_140 . V_142 . V_143 [ 0 ] = V_110 -> V_132 ;
return 0 ;
}
static void F_13 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_126 * V_127 = V_110 -> V_127 ;
int V_144 , V_145 , V_128 , V_129 , V_146 ;
if ( ! V_127 || ! V_110 -> V_147 )
return;
V_146 = V_110 -> V_148 ;
V_144 = 0 ;
V_145 = V_149 ;
for ( V_129 = 0 ; V_129 < V_127 -> V_150 ; V_129 ++ ) {
if ( strcmp ( V_127 -> V_151 [ V_129 ] . V_152 ,
V_110 -> V_153 [ V_146 ] ) == 0 &&
abs ( V_127 -> V_151 [ V_129 ] . V_113
- V_110 -> V_154 ) < V_145 ) {
V_144 = V_129 ;
V_145 = abs ( V_127 -> V_151 [ V_129 ] . V_113
- V_110 -> V_154 ) ;
}
}
F_7 ( V_108 -> V_2 , L_5 ,
V_127 -> V_151 [ V_144 ] . V_152 ,
V_127 -> V_151 [ V_144 ] . V_113 ,
V_110 -> V_154 ) ;
V_128 = F_5 ( V_108 , V_78 ) ;
for ( V_129 = 0 ; V_129 < V_155 ; V_129 ++ )
F_6 ( V_108 , V_78 + V_129 , 0xffff ,
V_127 -> V_151 [ V_144 ] . V_133 [ V_129 ] ) ;
F_6 ( V_108 , V_78 , V_156 , V_128 ) ;
}
static int F_14 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_107 * V_108 = F_11 ( V_137 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_126 * V_127 = V_110 -> V_127 ;
int V_140 = V_139 -> V_140 . integer . V_140 [ 0 ] ;
if ( V_140 >= V_127 -> V_150 )
return - V_122 ;
V_110 -> V_148 = V_140 ;
F_13 ( V_108 ) ;
return 0 ;
}
static int F_15 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_107 * V_108 = F_11 ( V_137 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
V_139 -> V_140 . V_142 . V_143 [ 0 ] = V_110 -> V_148 ;
return 0 ;
}
static int F_16 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_157 , V_129 , V_144 ;
if ( V_110 -> V_158 ) {
V_144 = 1 ;
for ( V_129 = 2 ; V_129 < F_17 ( V_159 ) ; V_129 ++ ) {
if ( abs ( V_159 [ V_129 ] - V_110 -> V_154 ) <
abs ( V_159 [ V_144 ] - V_110 -> V_154 ) )
V_144 = V_129 ;
}
V_157 = V_144 << V_160 ;
} else {
V_157 = 0 ;
}
F_7 ( V_108 -> V_2 , L_6 , V_157 ) ;
return F_6 ( V_108 , V_34 ,
V_161 , V_157 ) ;
}
static int F_18 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_107 * V_108 = F_11 ( V_137 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
V_139 -> V_140 . V_142 . V_143 [ 0 ] = V_110 -> V_158 ;
return 0 ;
}
static int F_19 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_107 * V_108 = F_11 ( V_137 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_158 = V_139 -> V_140 . V_142 . V_143 [ 0 ] ;
if ( V_158 > 1 )
return - V_122 ;
V_110 -> V_158 = V_158 ;
return F_16 ( V_108 ) ;
}
static int F_20 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_107 * V_108 = F_11 ( V_137 ) ;
unsigned int V_157 ;
int V_162 ;
V_162 = F_21 ( V_137 , V_139 ) ;
if ( V_162 < 0 )
return V_162 ;
if ( V_139 -> V_140 . integer . V_140 [ 0 ] )
V_157 = 0 ;
else
V_157 = V_163 | V_164 ;
F_6 ( V_108 , V_103 ,
V_163 | V_164 ,
V_157 ) ;
return V_162 ;
}
static int F_22 ( struct V_165 * V_166 ,
struct V_136 * V_137 , int V_167 )
{
F_23 ( V_167 != V_168 ) ;
F_24 ( 500 ) ;
return 0 ;
}
static int F_25 ( struct V_165 * V_166 ,
struct V_136 * V_137 , int V_167 )
{
struct V_107 * V_108 = V_166 -> V_108 ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
switch ( V_167 ) {
case V_169 :
switch ( V_110 -> V_115 ) {
case V_120 :
F_6 ( V_108 , V_65 ,
V_118 ,
V_118 ) ;
F_6 ( V_108 , V_65 ,
V_119 ,
V_119 ) ;
break;
default:
break;
}
break;
case V_170 :
F_6 ( V_108 , V_65 ,
V_118 | V_119 , 0 ) ;
break;
}
return 0 ;
}
static int F_26 ( struct V_165 * V_166 ,
struct V_136 * V_137 , int V_167 )
{
struct V_107 * V_108 = V_166 -> V_108 ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_3 , V_157 ;
int V_171 ;
int V_172 , V_173 ;
int V_174 , V_175 ;
int V_176 ;
int V_177 ;
V_3 = V_166 -> V_178 ;
switch ( V_3 ) {
case V_56 :
V_177 = V_21 ;
V_171 = V_179 | V_180 ;
V_175 = V_9 ;
V_174 = V_10 ;
V_172 = 0 ;
V_173 = 1 ;
break;
case V_57 :
V_177 = V_22 ;
V_171 = V_181 | V_182 ;
V_175 = V_7 ;
V_174 = V_8 ;
V_172 = 2 ;
V_173 = 3 ;
break;
default:
F_27 () ;
return - V_122 ;
}
switch ( V_167 ) {
case V_169 :
F_6 ( V_108 , V_177 ,
V_183 | V_184 ,
V_183 | V_184 ) ;
F_6 ( V_108 , V_3 ,
V_185 | V_186 ,
V_185 | V_186 ) ;
F_6 ( V_108 , V_3 ,
V_187 | V_188 ,
V_187 | V_188 ) ;
F_6 ( V_108 , V_52 ,
V_171 , V_171 ) ;
if ( V_110 -> V_189 [ V_172 ] || V_110 -> V_189 [ V_173 ] ) {
F_7 ( V_108 -> V_2 , L_7 ) ;
F_28 ( V_108 , V_174 ,
V_110 -> V_189 [ V_172 ] ) ;
F_28 ( V_108 , V_175 ,
V_110 -> V_189 [ V_173 ] ) ;
F_28 ( V_108 , V_6 , V_171 ) ;
V_176 = 20 ;
} else {
F_7 ( V_108 -> V_2 , L_8 ) ;
F_28 ( V_108 , V_6 ,
V_171 << V_190 ) ;
V_176 = 500 ;
}
V_171 <<= V_191 ;
do {
V_157 = F_5 ( V_108 , V_11 ) ;
if ( ( V_157 & V_171 ) == V_171 )
break;
F_29 ( 1 ) ;
} while ( -- V_176 );
if ( ( V_157 & V_171 ) != V_171 )
F_30 ( V_108 -> V_2 , L_9 ) ;
else
F_7 ( V_108 -> V_2 , L_10 ) ;
F_6 ( V_108 , V_3 ,
V_192 | V_193 ,
V_192 | V_193 ) ;
break;
case V_168 :
F_6 ( V_108 , V_3 ,
V_194 |
V_195 ,
V_194 |
V_195 ) ;
break;
case V_196 :
F_6 ( V_108 , V_3 ,
V_194 |
V_195 , 0 ) ;
break;
case V_170 :
V_110 -> V_189 [ V_172 ] = F_5 ( V_108 , V_174 ) ;
V_110 -> V_189 [ V_173 ] = F_5 ( V_108 , V_175 ) ;
F_6 ( V_108 , V_52 ,
V_171 , 0 ) ;
F_6 ( V_108 , V_3 ,
V_185 | V_186 |
V_187 | V_188 |
V_192 | V_193 ,
0 ) ;
F_6 ( V_108 , V_177 ,
V_183 | V_184 ,
0 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_197 * V_198 = & V_108 -> V_198 ;
F_32 ( V_198 , V_199 ,
F_17 ( V_199 ) ) ;
F_33 ( V_198 , V_200 ,
F_17 ( V_200 ) ) ;
switch ( V_110 -> V_201 ) {
case V_202 :
F_34 ( V_108 , V_203 ,
F_17 ( V_203 ) ) ;
F_34 ( V_108 , V_204 ,
F_17 ( V_204 ) ) ;
F_34 ( V_108 , V_205 ,
F_17 ( V_205 ) ) ;
F_32 ( V_198 , V_206 ,
F_17 ( V_206 ) ) ;
F_32 ( V_198 , V_207 ,
F_17 ( V_207 ) ) ;
F_32 ( V_198 , V_208 ,
F_17 ( V_208 ) ) ;
F_33 ( V_198 , V_209 ,
F_17 ( V_209 ) ) ;
F_33 ( V_198 , V_210 ,
F_17 ( V_210 ) ) ;
F_33 ( V_198 , V_211 ,
F_17 ( V_211 ) ) ;
break;
case V_212 :
F_34 ( V_108 , V_204 ,
F_17 ( V_204 ) ) ;
F_32 ( V_198 , V_207 ,
F_17 ( V_207 ) ) ;
F_33 ( V_198 , V_210 ,
F_17 ( V_210 ) ) ;
F_33 ( V_198 , V_213 ,
F_17 ( V_213 ) ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_214 * V_215 ,
struct V_216 * V_217 ,
struct V_218 * V_219 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_162 , V_129 , V_144 , V_145 , V_220 ;
unsigned int V_221 = 0 ;
unsigned int V_222 = 0 ;
unsigned int V_223 = 0 ;
unsigned int V_224 = 0 ;
unsigned int V_225 = 0 ;
V_110 -> V_154 = F_36 ( V_217 ) ;
if ( V_110 -> V_226 ) {
F_7 ( V_108 -> V_2 , L_11 ,
V_110 -> V_226 , V_110 -> V_227 ) ;
V_110 -> V_228 = F_37 ( V_110 -> V_154 ,
V_110 -> V_227 , 2 ,
V_110 -> V_226 ) ;
} else {
V_110 -> V_228 = F_38 ( V_217 ) ;
}
switch ( F_39 ( V_217 ) ) {
case V_229 :
break;
case V_230 :
V_221 |= 0x40 ;
break;
case V_231 :
V_221 |= 0x80 ;
break;
case V_232 :
V_221 |= 0xc0 ;
break;
default:
return - V_122 ;
}
F_7 ( V_108 -> V_2 , L_12 , V_110 -> V_228 ) ;
V_162 = F_3 ( V_108 ) ;
if ( V_162 != 0 )
return V_162 ;
V_144 = 0 ;
V_145 = abs ( ( V_110 -> V_124 / V_233 [ 0 ] . V_234 )
- V_110 -> V_154 ) ;
for ( V_129 = 1 ; V_129 < F_17 ( V_233 ) ; V_129 ++ ) {
V_220 = abs ( ( V_110 -> V_124 /
V_233 [ V_129 ] . V_234 ) - V_110 -> V_154 ) ;
if ( V_220 < V_145 ) {
V_144 = V_129 ;
V_145 = V_220 ;
}
}
F_7 ( V_108 -> V_2 , L_13 ,
V_233 [ V_144 ] . V_234 ) ;
V_224 |= ( V_233 [ V_144 ] . V_235
<< V_236 ) ;
V_144 = 0 ;
V_145 = abs ( V_110 -> V_154 - V_237 [ 0 ] . V_113 ) ;
for ( V_129 = 1 ; V_129 < F_17 ( V_237 ) ; V_129 ++ ) {
V_220 = abs ( V_110 -> V_154 - V_237 [ V_129 ] . V_113 ) ;
if ( V_220 < V_145 ) {
V_144 = V_129 ;
V_145 = V_220 ;
}
}
F_7 ( V_108 -> V_2 , L_14 ,
V_237 [ V_144 ] . V_113 ) ;
V_224 |= ( V_237 [ V_144 ] . V_238
<< V_239 ) ;
if ( V_110 -> V_154 <= 24000 )
V_225 |= V_240 ;
V_144 = 0 ;
V_145 = V_149 ;
for ( V_129 = 0 ; V_129 < F_17 ( V_241 ) ; V_129 ++ ) {
V_220 = ( ( V_110 -> V_124 * 10 ) / V_241 [ V_129 ] . div )
- V_110 -> V_228 ;
if ( V_220 < 0 )
break;
if ( V_220 < V_145 ) {
V_144 = V_129 ;
V_145 = V_220 ;
}
}
V_110 -> V_228 = ( V_110 -> V_124 * 10 ) / V_241 [ V_144 ] . div ;
F_7 ( V_108 -> V_2 , L_15 ,
V_241 [ V_144 ] . div , V_110 -> V_228 ) ;
V_222 |= V_241 [ V_144 ] . V_242 ;
F_7 ( V_108 -> V_2 , L_16 , V_110 -> V_228 / V_110 -> V_154 ) ;
V_223 |= V_110 -> V_228 / V_110 -> V_154 ;
F_6 ( V_108 , V_34 ,
V_240 , V_225 ) ;
F_6 ( V_108 , V_28 ,
V_243 , V_221 ) ;
F_6 ( V_108 , V_29 ,
V_244 , V_222 ) ;
F_6 ( V_108 , V_30 ,
V_245 , V_223 ) ;
F_6 ( V_108 , V_25 ,
V_246 |
V_247 , V_224 ) ;
F_13 ( V_108 ) ;
F_16 ( V_108 ) ;
return 0 ;
}
static int F_40 ( struct V_218 * V_219 , int V_248 ,
unsigned int V_249 , int V_250 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
struct V_109 * V_251 = F_4 ( V_108 ) ;
switch ( V_248 ) {
case V_116 :
V_251 -> V_115 = V_248 ;
V_251 -> V_117 = V_249 ;
break;
case V_120 :
V_251 -> V_115 = V_248 ;
break;
default:
return - V_122 ;
}
F_7 ( V_219 -> V_2 , L_17 , V_248 , V_249 ) ;
F_3 ( V_108 ) ;
return 0 ;
}
static int F_41 ( struct V_218 * V_219 , unsigned int V_252 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
unsigned int V_221 = 0 ;
unsigned int V_223 = 0 ;
switch ( V_252 & V_253 ) {
case V_254 :
break;
case V_255 :
V_223 |= V_256 ;
break;
case V_257 :
V_221 |= V_258 ;
break;
case V_259 :
V_221 |= V_258 ;
V_223 |= V_256 ;
break;
default:
return - V_122 ;
}
switch ( V_252 & V_260 ) {
case V_261 :
V_221 |= V_262 ;
case V_263 :
V_221 |= 0x3 ;
break;
case V_264 :
V_221 |= 0x2 ;
break;
case V_265 :
break;
case V_266 :
V_221 |= 0x1 ;
break;
default:
return - V_122 ;
}
switch ( V_252 & V_260 ) {
case V_263 :
case V_261 :
switch ( V_252 & V_267 ) {
case V_268 :
break;
case V_269 :
V_221 |= V_270 ;
break;
default:
return - V_122 ;
}
break;
case V_264 :
case V_265 :
case V_266 :
switch ( V_252 & V_267 ) {
case V_268 :
break;
case V_271 :
V_221 |= V_270 | V_262 ;
break;
case V_269 :
V_221 |= V_270 ;
break;
case V_272 :
V_221 |= V_262 ;
break;
default:
return - V_122 ;
}
break;
default:
return - V_122 ;
}
F_6 ( V_108 , V_28 ,
V_270 | V_262 |
V_273 | V_258 , V_221 ) ;
F_6 ( V_108 , V_30 ,
V_256 , V_223 ) ;
return 0 ;
}
static int F_42 ( struct V_218 * V_219 , unsigned int V_274 ,
unsigned int V_275 , int V_276 , int V_277 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_221 = 0 ;
if ( V_276 == 0 )
goto V_278;
V_221 |= V_279 | V_280 ;
switch ( V_275 ) {
case 3 :
break;
case 0xc :
V_221 |= V_281 ;
break;
default:
return - V_122 ;
}
switch ( V_274 ) {
case 3 :
break;
case 0xc :
V_221 |= V_282 ;
break;
default:
return - V_122 ;
}
V_278:
V_110 -> V_227 = V_277 ;
V_110 -> V_226 = V_276 / 2 ;
F_6 ( V_108 , V_28 ,
V_279 | V_281 |
V_280 | V_282 , V_221 ) ;
return 0 ;
}
static int F_43 ( struct V_283 * V_284 , unsigned int V_285 ,
unsigned int V_286 )
{
T_1 V_287 ;
unsigned int V_288 , V_289 , V_290 , V_291 ;
unsigned int div ;
int V_129 ;
div = 1 ;
V_284 -> V_292 = 0 ;
while ( ( V_285 / div ) > 13500000 ) {
div *= 2 ;
V_284 -> V_292 ++ ;
if ( div > 8 ) {
F_44 ( L_18 ,
V_285 ) ;
return - V_122 ;
}
}
F_45 ( L_19 , V_285 , V_286 ) ;
V_285 /= div ;
div = 4 ;
while ( V_286 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_44 ( L_20 ,
V_286 ) ;
return - V_122 ;
}
}
V_291 = V_286 * div ;
V_284 -> V_293 = div - 1 ;
F_45 ( L_21 , V_291 ) ;
for ( V_129 = 0 ; V_129 < F_17 ( V_294 ) ; V_129 ++ ) {
if ( V_294 [ V_129 ] . V_295 <= V_285 && V_285 <= V_294 [ V_129 ] . V_296 ) {
V_284 -> V_297 = V_294 [ V_129 ] . V_297 ;
V_291 /= V_294 [ V_129 ] . V_234 ;
break;
}
}
if ( V_129 == F_17 ( V_294 ) ) {
F_44 ( L_22 , V_285 ) ;
return - V_122 ;
}
V_289 = V_291 / V_285 ;
V_284 -> V_298 = V_289 ;
V_290 = V_291 % V_285 ;
F_45 ( L_23 , V_290 ) ;
V_287 = V_299 * ( long long ) V_290 ;
F_46 ( V_287 , V_285 ) ;
V_288 = V_287 & 0xFFFFFFFF ;
if ( ( V_288 % 10 ) >= 5 )
V_288 += 5 ;
V_284 -> V_300 = V_288 / 10 ;
F_45 ( L_24 ,
V_284 -> V_298 , V_284 -> V_300 ,
V_284 -> V_297 , V_284 -> V_293 ,
V_284 -> V_292 ) ;
return 0 ;
}
static int F_47 ( struct V_218 * V_219 , int V_301 , int V_302 ,
unsigned int V_285 , unsigned int V_286 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_283 V_284 ;
int V_162 , V_157 ;
int V_112 , V_303 ;
if ( V_302 == V_110 -> V_304 && V_285 == V_110 -> V_305 &&
V_286 == V_110 -> V_121 )
return 0 ;
V_112 = F_5 ( V_108 , V_26 ) ;
if ( V_286 == 0 ) {
F_7 ( V_108 -> V_2 , L_25 ) ;
V_110 -> V_305 = 0 ;
V_110 -> V_121 = 0 ;
F_6 ( V_108 , V_26 ,
V_125 , 0 ) ;
F_6 ( V_108 , V_65 ,
V_118 | V_119 , 0 ) ;
goto V_278;
}
switch ( V_302 ) {
case V_306 :
case V_307 :
case V_308 :
V_162 = F_43 ( & V_284 , V_285 , V_286 ) ;
if ( V_162 != 0 )
return V_162 ;
break;
case V_309 :
F_7 ( V_108 -> V_2 , L_26 ) ;
V_286 = 12000000 ;
V_285 = 12000000 ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_284 . V_293 = 3 ;
break;
default:
F_8 ( V_108 -> V_2 , L_27 , V_301 ) ;
return - V_122 ;
}
V_303 = F_5 ( V_108 , V_65 ) ;
F_6 ( V_108 , V_26 ,
V_125 , 0 ) ;
F_6 ( V_108 , V_65 ,
V_118 | V_119 , 0 ) ;
F_6 ( V_108 , V_102 ,
V_310 , V_310 ) ;
if ( V_301 == V_309 ) {
V_157 = V_311 ;
} else {
V_157 = 0 ;
}
F_6 ( V_108 , V_106 , V_311 ,
V_157 ) ;
F_6 ( V_108 , V_102 ,
V_310 , 0 ) ;
switch ( V_301 ) {
case V_306 :
F_6 ( V_108 , V_69 ,
V_312 , 0 ) ;
break;
case V_307 :
F_6 ( V_108 , V_69 ,
V_312 , 1 ) ;
break;
case V_308 :
F_6 ( V_108 , V_69 ,
V_312 , 2 ) ;
break;
}
if ( V_284 . V_300 )
V_157 = V_313 ;
else
V_157 = 0 ;
F_6 ( V_108 , V_65 ,
V_313 , V_157 ) ;
F_6 ( V_108 , V_66 ,
V_314 | V_315 ,
( V_284 . V_293 << V_316 ) |
( V_284 . V_297 << V_317 ) ) ;
F_28 ( V_108 , V_67 , V_284 . V_300 ) ;
F_6 ( V_108 , V_68 , V_318 ,
V_284 . V_298 << V_319 ) ;
F_6 ( V_108 , V_69 ,
V_320 ,
V_284 . V_292
<< V_321 ) ;
F_7 ( V_108 -> V_2 , L_28 , V_285 , V_286 ) ;
V_110 -> V_305 = V_285 ;
V_110 -> V_121 = V_286 ;
V_110 -> V_304 = V_302 ;
F_6 ( V_108 , V_65 ,
V_118 , V_303 ) ;
F_6 ( V_108 , V_65 ,
V_119 , V_303 ) ;
V_278:
F_6 ( V_108 , V_26 ,
V_125 , V_112 ) ;
return 0 ;
}
static int F_48 ( struct V_218 * V_322 , int V_323 )
{
struct V_107 * V_108 = V_322 -> V_108 ;
int V_157 ;
if ( V_323 )
V_157 = V_324 ;
else
V_157 = 0 ;
F_6 ( V_108 , V_34 , V_324 , V_157 ) ;
return 0 ;
}
static int F_49 ( struct V_107 * V_108 ,
enum V_325 V_326 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_162 ;
switch ( V_326 ) {
case V_327 :
break;
case V_328 :
F_6 ( V_108 , V_14 ,
V_329 ,
0x1 << V_330 ) ;
F_6 ( V_108 , V_13 ,
V_331 , 2 << V_332 ) ;
break;
case V_333 :
if ( V_108 -> V_198 . V_334 == V_335 ) {
V_162 = F_50 ( F_17 ( V_110 -> V_336 ) ,
V_110 -> V_336 ) ;
if ( V_162 != 0 ) {
F_8 ( V_108 -> V_2 ,
L_29 ,
V_162 ) ;
return V_162 ;
}
F_51 ( V_110 -> V_337 , false ) ;
F_52 ( V_110 -> V_337 ) ;
F_6 ( V_108 , V_13 ,
V_338 , V_338 ) ;
F_6 ( V_108 , V_14 ,
V_339 |
V_329 ,
V_339 |
0x3 << V_330 ) ;
F_29 ( 1 ) ;
}
F_6 ( V_108 , V_14 ,
V_329 ,
0x2 << V_330 ) ;
F_6 ( V_108 , V_13 ,
V_331 , 0 ) ;
break;
case V_335 :
F_6 ( V_108 , V_14 ,
V_329 | V_339 , 0 ) ;
F_6 ( V_108 , V_13 ,
V_338 , 0 ) ;
F_51 ( V_110 -> V_337 , true ) ;
F_53 ( V_110 -> V_337 ) ;
F_54 ( F_17 ( V_110 -> V_336 ) ,
V_110 -> V_336 ) ;
break;
}
V_108 -> V_198 . V_334 = V_326 ;
return 0 ;
}
static void F_55 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_126 * V_127 = V_110 -> V_127 ;
struct V_340 V_341 =
F_56 ( L_30 ,
V_110 -> V_342 ,
F_15 ,
F_14 ) ;
int V_162 , V_129 , V_343 ;
const char * * V_344 ;
V_110 -> V_147 = 0 ;
V_110 -> V_153 = NULL ;
for ( V_129 = 0 ; V_129 < V_127 -> V_150 ; V_129 ++ ) {
for ( V_343 = 0 ; V_343 < V_110 -> V_147 ; V_343 ++ ) {
if ( strcmp ( V_127 -> V_151 [ V_129 ] . V_152 ,
V_110 -> V_153 [ V_343 ] ) == 0 )
break;
}
if ( V_343 != V_110 -> V_147 )
continue;
V_344 = F_57 ( V_110 -> V_153 ,
sizeof( char * ) *
( V_110 -> V_147 + 1 ) ,
V_345 ) ;
if ( V_344 == NULL )
continue;
V_344 [ V_110 -> V_147 ] =
V_127 -> V_151 [ V_129 ] . V_152 ;
V_110 -> V_147 ++ ;
V_110 -> V_153 = V_344 ;
}
F_7 ( V_108 -> V_2 , L_31 ,
V_110 -> V_147 ) ;
V_110 -> V_342 . V_296 = V_110 -> V_147 ;
V_110 -> V_342 . V_346 = V_110 -> V_153 ;
V_162 = F_34 ( V_108 , & V_341 , 1 ) ;
if ( V_162 != 0 )
F_8 ( V_108 -> V_2 ,
L_32 , V_162 ) ;
}
static void F_58 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_126 * V_127 = V_110 -> V_127 ;
int V_162 , V_129 ;
if ( ! V_127 ) {
F_34 ( V_108 , V_347 ,
F_17 ( V_347 ) ) ;
return;
}
F_7 ( V_108 -> V_2 , L_33 , V_127 -> V_141 ) ;
if ( V_127 -> V_141 ) {
struct V_340 V_341 =
F_56 ( L_34 , V_110 -> V_348 ,
F_12 , F_10 ) ;
V_110 -> V_349 = F_59 ( sizeof( char * )
* V_127 -> V_141 , V_345 ) ;
if ( ! V_110 -> V_349 ) {
F_8 ( V_108 -> V_2 ,
L_35 ,
V_127 -> V_141 ) ;
return;
}
for ( V_129 = 0 ; V_129 < V_127 -> V_141 ; V_129 ++ )
V_110 -> V_349 [ V_129 ] = V_127 -> V_131 [ V_129 ] . V_152 ;
V_110 -> V_348 . V_296 = V_127 -> V_141 ;
V_110 -> V_348 . V_346 = V_110 -> V_349 ;
V_162 = F_34 ( V_108 , & V_341 , 1 ) ;
if ( V_162 != 0 )
F_8 ( V_108 -> V_2 ,
L_36 , V_162 ) ;
F_9 ( V_108 ) ;
}
F_7 ( V_108 -> V_2 , L_37 ,
V_127 -> V_150 ) ;
if ( V_127 -> V_150 )
F_55 ( V_108 ) ;
else
F_34 ( V_108 , V_347 ,
F_17 ( V_347 ) ) ;
}
static int F_60 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_162 ;
V_108 -> V_350 = V_110 -> V_337 ;
switch ( V_110 -> V_201 ) {
case V_202 :
break;
case V_212 :
memset ( & V_351 . V_352 , 0 , sizeof( V_351 . V_352 ) ) ;
break;
default:
F_8 ( V_108 -> V_2 , L_38 ,
V_110 -> V_201 ) ;
return - V_122 ;
}
V_162 = F_61 ( V_108 , 8 , 16 , V_353 ) ;
if ( V_162 != 0 ) {
F_8 ( V_108 -> V_2 , L_39 , V_162 ) ;
return V_162 ;
}
F_58 ( V_108 ) ;
F_31 ( V_108 ) ;
return 0 ;
}
static int F_62 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
F_63 ( V_110 -> V_153 ) ;
F_63 ( V_110 -> V_349 ) ;
return 0 ;
}
static int F_64 ( struct V_354 * V_355 ,
const struct V_356 * V_357 )
{
struct V_109 * V_110 ;
unsigned int V_157 ;
int V_162 , V_129 ;
V_110 = F_65 ( & V_355 -> V_2 , sizeof( struct V_109 ) ,
V_345 ) ;
if ( V_110 == NULL )
return - V_358 ;
V_110 -> V_337 = F_66 ( V_355 , & V_359 ) ;
if ( F_67 ( V_110 -> V_337 ) ) {
V_162 = F_68 ( V_110 -> V_337 ) ;
F_8 ( & V_355 -> V_2 , L_40 ,
V_162 ) ;
return V_162 ;
}
V_110 -> V_201 = V_357 -> V_360 ;
F_69 ( V_355 , V_110 ) ;
V_110 -> V_127 = V_355 -> V_2 . V_361 ;
for ( V_129 = 0 ; V_129 < F_17 ( V_110 -> V_336 ) ; V_129 ++ )
V_110 -> V_336 [ V_129 ] . V_362 = V_363 [ V_129 ] ;
V_162 = F_70 ( & V_355 -> V_2 , F_17 ( V_110 -> V_336 ) ,
V_110 -> V_336 ) ;
if ( V_162 != 0 ) {
F_8 ( & V_355 -> V_2 , L_41 , V_162 ) ;
return V_162 ;
}
V_162 = F_50 ( F_17 ( V_110 -> V_336 ) ,
V_110 -> V_336 ) ;
if ( V_162 != 0 ) {
F_8 ( & V_355 -> V_2 , L_29 , V_162 ) ;
return V_162 ;
}
V_162 = F_71 ( V_110 -> V_337 , V_4 , & V_157 ) ;
if ( V_162 < 0 ) {
F_8 ( & V_355 -> V_2 , L_42 , V_162 ) ;
goto V_364;
}
if ( V_157 != 0x8904 ) {
F_8 ( & V_355 -> V_2 , L_43 , V_157 ) ;
V_162 = - V_122 ;
goto V_364;
}
V_162 = F_71 ( V_110 -> V_337 , V_5 , & V_157 ) ;
if ( V_162 < 0 ) {
F_8 ( & V_355 -> V_2 , L_44 ,
V_162 ) ;
goto V_364;
}
F_72 ( & V_355 -> V_2 , L_45 , V_157 + 'A' ) ;
V_162 = F_73 ( V_110 -> V_337 , V_4 , 0 ) ;
if ( V_162 < 0 ) {
F_8 ( & V_355 -> V_2 , L_46 , V_162 ) ;
goto V_364;
}
F_74 ( V_110 -> V_337 , V_35 ,
V_365 , V_365 ) ;
F_74 ( V_110 -> V_337 , V_36 ,
V_365 , V_365 ) ;
F_74 ( V_110 -> V_337 , V_31 ,
V_366 , V_366 ) ;
F_74 ( V_110 -> V_337 , V_32 ,
V_366 , V_366 ) ;
F_74 ( V_110 -> V_337 , V_47 ,
V_367 | V_368 ,
V_367 | V_368 ) ;
F_74 ( V_110 -> V_337 , V_48 ,
V_367 | V_369 ,
V_367 | V_369 ) ;
F_74 ( V_110 -> V_337 , V_49 ,
V_370 | V_371 ,
V_370 | V_371 ) ;
F_74 ( V_110 -> V_337 , V_50 ,
V_370 | V_372 ,
V_370 | V_372 ) ;
F_74 ( V_110 -> V_337 , V_24 ,
V_373 , 0 ) ;
if ( V_110 -> V_127 ) {
for ( V_129 = 0 ; V_129 < V_374 ; V_129 ++ ) {
if ( ! V_110 -> V_127 -> V_375 [ V_129 ] )
continue;
F_74 ( V_110 -> V_337 ,
V_70 + V_129 ,
0xffff ,
V_110 -> V_127 -> V_375 [ V_129 ] ) ;
}
for ( V_129 = 0 ; V_129 < V_376 ; V_129 ++ )
F_74 ( V_110 -> V_337 ,
V_15 + V_129 ,
0xffff ,
V_110 -> V_127 -> V_377 [ V_129 ] ) ;
}
F_74 ( V_110 -> V_337 , V_59 ,
V_378 , V_378 ) ;
F_74 ( V_110 -> V_337 , V_13 ,
V_379 , 0 ) ;
F_51 ( V_110 -> V_337 , true ) ;
F_54 ( F_17 ( V_110 -> V_336 ) , V_110 -> V_336 ) ;
V_162 = F_75 ( & V_355 -> V_2 ,
& V_380 , & V_351 , 1 ) ;
if ( V_162 != 0 )
return V_162 ;
return 0 ;
V_364:
F_54 ( F_17 ( V_110 -> V_336 ) , V_110 -> V_336 ) ;
return V_162 ;
}
static int F_76 ( struct V_354 * V_381 )
{
F_77 ( & V_381 -> V_2 ) ;
return 0 ;
}
