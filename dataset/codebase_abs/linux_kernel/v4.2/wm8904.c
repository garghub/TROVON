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
V_139 -> V_140 . integer . V_140 [ 0 ] = V_110 -> V_158 ;
return 0 ;
}
static int F_19 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_107 * V_108 = F_11 ( V_137 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_158 = V_139 -> V_140 . integer . V_140 [ 0 ] ;
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
if ( F_23 ( V_167 != V_168 ) )
return - V_122 ;
F_24 ( 500 ) ;
return 0 ;
}
static int F_25 ( struct V_165 * V_166 ,
struct V_136 * V_137 , int V_167 )
{
struct V_107 * V_108 = F_26 ( V_166 -> V_169 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
switch ( V_167 ) {
case V_170 :
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
case V_171 :
F_6 ( V_108 , V_65 ,
V_118 | V_119 , 0 ) ;
break;
}
return 0 ;
}
static int F_27 ( struct V_165 * V_166 ,
struct V_136 * V_137 , int V_167 )
{
struct V_107 * V_108 = F_26 ( V_166 -> V_169 ) ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_3 , V_157 ;
int V_172 ;
int V_173 , V_174 ;
int V_175 , V_176 ;
int V_177 ;
int V_178 ;
V_3 = V_166 -> V_179 ;
switch ( V_3 ) {
case V_56 :
V_178 = V_21 ;
V_172 = V_180 | V_181 ;
V_176 = V_9 ;
V_175 = V_10 ;
V_173 = 0 ;
V_174 = 1 ;
break;
case V_57 :
V_178 = V_22 ;
V_172 = V_182 | V_183 ;
V_176 = V_7 ;
V_175 = V_8 ;
V_173 = 2 ;
V_174 = 3 ;
break;
default:
F_28 ( 1 , L_7 , V_3 ) ;
return - V_122 ;
}
switch ( V_167 ) {
case V_170 :
F_6 ( V_108 , V_178 ,
V_184 | V_185 ,
V_184 | V_185 ) ;
F_6 ( V_108 , V_3 ,
V_186 | V_187 ,
V_186 | V_187 ) ;
F_6 ( V_108 , V_3 ,
V_188 | V_189 ,
V_188 | V_189 ) ;
F_6 ( V_108 , V_52 ,
V_172 , V_172 ) ;
if ( V_110 -> V_190 [ V_173 ] || V_110 -> V_190 [ V_174 ] ) {
F_7 ( V_108 -> V_2 , L_8 ) ;
F_29 ( V_108 , V_175 ,
V_110 -> V_190 [ V_173 ] ) ;
F_29 ( V_108 , V_176 ,
V_110 -> V_190 [ V_174 ] ) ;
F_29 ( V_108 , V_6 , V_172 ) ;
V_177 = 20 ;
} else {
F_7 ( V_108 -> V_2 , L_9 ) ;
F_29 ( V_108 , V_6 ,
V_172 << V_191 ) ;
V_177 = 500 ;
}
V_172 <<= V_192 ;
do {
V_157 = F_5 ( V_108 , V_11 ) ;
if ( ( V_157 & V_172 ) == V_172 )
break;
F_30 ( 1 ) ;
} while ( -- V_177 );
if ( ( V_157 & V_172 ) != V_172 )
F_31 ( V_108 -> V_2 , L_10 ) ;
else
F_7 ( V_108 -> V_2 , L_11 ) ;
F_6 ( V_108 , V_3 ,
V_193 | V_194 ,
V_193 | V_194 ) ;
break;
case V_168 :
F_6 ( V_108 , V_3 ,
V_195 |
V_196 ,
V_195 |
V_196 ) ;
break;
case V_197 :
F_6 ( V_108 , V_3 ,
V_195 |
V_196 , 0 ) ;
break;
case V_171 :
V_110 -> V_190 [ V_173 ] = F_5 ( V_108 , V_175 ) ;
V_110 -> V_190 [ V_174 ] = F_5 ( V_108 , V_176 ) ;
F_6 ( V_108 , V_52 ,
V_172 , 0 ) ;
F_6 ( V_108 , V_3 ,
V_186 | V_187 |
V_188 | V_189 |
V_193 | V_194 ,
0 ) ;
F_6 ( V_108 , V_178 ,
V_184 | V_185 ,
0 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_198 * V_169 = F_33 ( V_108 ) ;
F_34 ( V_169 , V_199 ,
F_17 ( V_199 ) ) ;
F_35 ( V_169 , V_200 ,
F_17 ( V_200 ) ) ;
switch ( V_110 -> V_201 ) {
case V_202 :
F_36 ( V_108 , V_203 ,
F_17 ( V_203 ) ) ;
F_36 ( V_108 , V_204 ,
F_17 ( V_204 ) ) ;
F_36 ( V_108 , V_205 ,
F_17 ( V_205 ) ) ;
F_34 ( V_169 , V_206 ,
F_17 ( V_206 ) ) ;
F_34 ( V_169 , V_207 ,
F_17 ( V_207 ) ) ;
F_34 ( V_169 , V_208 ,
F_17 ( V_208 ) ) ;
F_35 ( V_169 , V_209 ,
F_17 ( V_209 ) ) ;
F_35 ( V_169 , V_210 ,
F_17 ( V_210 ) ) ;
F_35 ( V_169 , V_211 ,
F_17 ( V_211 ) ) ;
break;
case V_212 :
F_36 ( V_108 , V_204 ,
F_17 ( V_204 ) ) ;
F_34 ( V_169 , V_207 ,
F_17 ( V_207 ) ) ;
F_35 ( V_169 , V_210 ,
F_17 ( V_210 ) ) ;
F_35 ( V_169 , V_213 ,
F_17 ( V_213 ) ) ;
break;
}
return 0 ;
}
static int F_37 ( struct V_214 * V_215 ,
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
V_110 -> V_154 = F_38 ( V_217 ) ;
if ( V_110 -> V_226 ) {
F_7 ( V_108 -> V_2 , L_12 ,
V_110 -> V_226 , V_110 -> V_227 ) ;
V_110 -> V_228 = F_39 ( V_110 -> V_154 ,
V_110 -> V_227 , 2 ,
V_110 -> V_226 ) ;
} else {
V_110 -> V_228 = F_40 ( V_217 ) ;
}
switch ( F_41 ( V_217 ) ) {
case 16 :
break;
case 20 :
V_221 |= 0x40 ;
break;
case 24 :
V_221 |= 0x80 ;
break;
case 32 :
V_221 |= 0xc0 ;
break;
default:
return - V_122 ;
}
F_7 ( V_108 -> V_2 , L_13 , V_110 -> V_228 ) ;
V_162 = F_3 ( V_108 ) ;
if ( V_162 != 0 )
return V_162 ;
V_144 = 0 ;
V_145 = abs ( ( V_110 -> V_124 / V_229 [ 0 ] . V_230 )
- V_110 -> V_154 ) ;
for ( V_129 = 1 ; V_129 < F_17 ( V_229 ) ; V_129 ++ ) {
V_220 = abs ( ( V_110 -> V_124 /
V_229 [ V_129 ] . V_230 ) - V_110 -> V_154 ) ;
if ( V_220 < V_145 ) {
V_144 = V_129 ;
V_145 = V_220 ;
}
}
F_7 ( V_108 -> V_2 , L_14 ,
V_229 [ V_144 ] . V_230 ) ;
V_224 |= ( V_229 [ V_144 ] . V_231
<< V_232 ) ;
V_144 = 0 ;
V_145 = abs ( V_110 -> V_154 - V_233 [ 0 ] . V_113 ) ;
for ( V_129 = 1 ; V_129 < F_17 ( V_233 ) ; V_129 ++ ) {
V_220 = abs ( V_110 -> V_154 - V_233 [ V_129 ] . V_113 ) ;
if ( V_220 < V_145 ) {
V_144 = V_129 ;
V_145 = V_220 ;
}
}
F_7 ( V_108 -> V_2 , L_15 ,
V_233 [ V_144 ] . V_113 ) ;
V_224 |= ( V_233 [ V_144 ] . V_234
<< V_235 ) ;
if ( V_110 -> V_154 <= 24000 )
V_225 |= V_236 ;
V_144 = 0 ;
V_145 = V_149 ;
for ( V_129 = 0 ; V_129 < F_17 ( V_237 ) ; V_129 ++ ) {
V_220 = ( ( V_110 -> V_124 * 10 ) / V_237 [ V_129 ] . div )
- V_110 -> V_228 ;
if ( V_220 < 0 )
break;
if ( V_220 < V_145 ) {
V_144 = V_129 ;
V_145 = V_220 ;
}
}
V_110 -> V_228 = ( V_110 -> V_124 * 10 ) / V_237 [ V_144 ] . div ;
F_7 ( V_108 -> V_2 , L_16 ,
V_237 [ V_144 ] . div , V_110 -> V_228 ) ;
V_222 |= V_237 [ V_144 ] . V_238 ;
F_7 ( V_108 -> V_2 , L_17 , V_110 -> V_228 / V_110 -> V_154 ) ;
V_223 |= V_110 -> V_228 / V_110 -> V_154 ;
F_6 ( V_108 , V_34 ,
V_236 , V_225 ) ;
F_6 ( V_108 , V_28 ,
V_239 , V_221 ) ;
F_6 ( V_108 , V_29 ,
V_240 , V_222 ) ;
F_6 ( V_108 , V_30 ,
V_241 , V_223 ) ;
F_6 ( V_108 , V_25 ,
V_242 |
V_243 , V_224 ) ;
F_13 ( V_108 ) ;
F_16 ( V_108 ) ;
return 0 ;
}
static int F_42 ( struct V_218 * V_219 , int V_244 ,
unsigned int V_245 , int V_246 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
struct V_109 * V_247 = F_4 ( V_108 ) ;
switch ( V_244 ) {
case V_116 :
V_247 -> V_115 = V_244 ;
V_247 -> V_117 = V_245 ;
break;
case V_120 :
V_247 -> V_115 = V_244 ;
break;
default:
return - V_122 ;
}
F_7 ( V_219 -> V_2 , L_18 , V_244 , V_245 ) ;
F_3 ( V_108 ) ;
return 0 ;
}
static int F_43 ( struct V_218 * V_219 , unsigned int V_248 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
unsigned int V_221 = 0 ;
unsigned int V_223 = 0 ;
switch ( V_248 & V_249 ) {
case V_250 :
break;
case V_251 :
V_223 |= V_252 ;
break;
case V_253 :
V_221 |= V_254 ;
break;
case V_255 :
V_221 |= V_254 ;
V_223 |= V_252 ;
break;
default:
return - V_122 ;
}
switch ( V_248 & V_256 ) {
case V_257 :
V_221 |= 0x3 | V_258 ;
case V_259 :
V_221 |= 0x3 ;
break;
case V_260 :
V_221 |= 0x2 ;
break;
case V_261 :
break;
case V_262 :
V_221 |= 0x1 ;
break;
default:
return - V_122 ;
}
switch ( V_248 & V_256 ) {
case V_259 :
case V_257 :
switch ( V_248 & V_263 ) {
case V_264 :
break;
case V_265 :
V_221 |= V_266 ;
break;
default:
return - V_122 ;
}
break;
case V_260 :
case V_261 :
case V_262 :
switch ( V_248 & V_263 ) {
case V_264 :
break;
case V_267 :
V_221 |= V_266 | V_258 ;
break;
case V_265 :
V_221 |= V_266 ;
break;
case V_268 :
V_221 |= V_258 ;
break;
default:
return - V_122 ;
}
break;
default:
return - V_122 ;
}
F_6 ( V_108 , V_28 ,
V_266 | V_258 |
V_269 | V_254 , V_221 ) ;
F_6 ( V_108 , V_30 ,
V_252 , V_223 ) ;
return 0 ;
}
static int F_44 ( struct V_218 * V_219 , unsigned int V_270 ,
unsigned int V_271 , int V_272 , int V_273 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_221 = 0 ;
if ( V_272 == 0 )
goto V_274;
V_221 |= V_275 | V_276 ;
switch ( V_271 ) {
case 3 :
break;
case 0xc :
V_221 |= V_277 ;
break;
default:
return - V_122 ;
}
switch ( V_270 ) {
case 3 :
break;
case 0xc :
V_221 |= V_278 ;
break;
default:
return - V_122 ;
}
V_274:
V_110 -> V_227 = V_273 ;
V_110 -> V_226 = V_272 / 2 ;
F_6 ( V_108 , V_28 ,
V_275 | V_277 |
V_276 | V_278 , V_221 ) ;
return 0 ;
}
static int F_45 ( struct V_279 * V_280 , unsigned int V_281 ,
unsigned int V_282 )
{
T_1 V_283 ;
unsigned int V_284 , V_285 , V_286 , V_287 ;
unsigned int div ;
int V_129 ;
div = 1 ;
V_280 -> V_288 = 0 ;
while ( ( V_281 / div ) > 13500000 ) {
div *= 2 ;
V_280 -> V_288 ++ ;
if ( div > 8 ) {
F_46 ( L_19 ,
V_281 ) ;
return - V_122 ;
}
}
F_47 ( L_20 , V_281 , V_282 ) ;
V_281 /= div ;
div = 4 ;
while ( V_282 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_46 ( L_21 ,
V_282 ) ;
return - V_122 ;
}
}
V_287 = V_282 * div ;
V_280 -> V_289 = div - 1 ;
F_47 ( L_22 , V_287 ) ;
for ( V_129 = 0 ; V_129 < F_17 ( V_290 ) ; V_129 ++ ) {
if ( V_290 [ V_129 ] . V_291 <= V_281 && V_281 <= V_290 [ V_129 ] . V_292 ) {
V_280 -> V_293 = V_290 [ V_129 ] . V_293 ;
V_287 /= V_290 [ V_129 ] . V_230 ;
break;
}
}
if ( V_129 == F_17 ( V_290 ) ) {
F_46 ( L_23 , V_281 ) ;
return - V_122 ;
}
V_285 = V_287 / V_281 ;
V_280 -> V_294 = V_285 ;
V_286 = V_287 % V_281 ;
F_47 ( L_24 , V_286 ) ;
V_283 = V_295 * ( long long ) V_286 ;
F_48 ( V_283 , V_281 ) ;
V_284 = V_283 & 0xFFFFFFFF ;
if ( ( V_284 % 10 ) >= 5 )
V_284 += 5 ;
V_280 -> V_296 = V_284 / 10 ;
F_47 ( L_25 ,
V_280 -> V_294 , V_280 -> V_296 ,
V_280 -> V_293 , V_280 -> V_289 ,
V_280 -> V_288 ) ;
return 0 ;
}
static int F_49 ( struct V_218 * V_219 , int V_297 , int V_298 ,
unsigned int V_281 , unsigned int V_282 )
{
struct V_107 * V_108 = V_219 -> V_108 ;
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_279 V_280 ;
int V_162 , V_157 ;
int V_112 , V_299 ;
if ( V_298 == V_110 -> V_300 && V_281 == V_110 -> V_301 &&
V_282 == V_110 -> V_121 )
return 0 ;
V_112 = F_5 ( V_108 , V_26 ) ;
if ( V_282 == 0 ) {
F_7 ( V_108 -> V_2 , L_26 ) ;
V_110 -> V_301 = 0 ;
V_110 -> V_121 = 0 ;
F_6 ( V_108 , V_26 ,
V_125 , 0 ) ;
F_6 ( V_108 , V_65 ,
V_118 | V_119 , 0 ) ;
goto V_274;
}
switch ( V_298 ) {
case V_302 :
case V_303 :
case V_304 :
V_162 = F_45 ( & V_280 , V_281 , V_282 ) ;
if ( V_162 != 0 )
return V_162 ;
break;
case V_305 :
F_7 ( V_108 -> V_2 , L_27 ) ;
V_282 = 12000000 ;
V_281 = 12000000 ;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
V_280 . V_289 = 3 ;
break;
default:
F_8 ( V_108 -> V_2 , L_28 , V_297 ) ;
return - V_122 ;
}
V_299 = F_5 ( V_108 , V_65 ) ;
F_6 ( V_108 , V_26 ,
V_125 , 0 ) ;
F_6 ( V_108 , V_65 ,
V_118 | V_119 , 0 ) ;
F_6 ( V_108 , V_102 ,
V_306 , V_306 ) ;
if ( V_297 == V_305 ) {
V_157 = V_307 ;
} else {
V_157 = 0 ;
}
F_6 ( V_108 , V_106 , V_307 ,
V_157 ) ;
F_6 ( V_108 , V_102 ,
V_306 , 0 ) ;
switch ( V_297 ) {
case V_302 :
F_6 ( V_108 , V_69 ,
V_308 , 0 ) ;
break;
case V_303 :
F_6 ( V_108 , V_69 ,
V_308 , 1 ) ;
break;
case V_304 :
F_6 ( V_108 , V_69 ,
V_308 , 2 ) ;
break;
}
if ( V_280 . V_296 )
V_157 = V_309 ;
else
V_157 = 0 ;
F_6 ( V_108 , V_65 ,
V_309 , V_157 ) ;
F_6 ( V_108 , V_66 ,
V_310 | V_311 ,
( V_280 . V_289 << V_312 ) |
( V_280 . V_293 << V_313 ) ) ;
F_29 ( V_108 , V_67 , V_280 . V_296 ) ;
F_6 ( V_108 , V_68 , V_314 ,
V_280 . V_294 << V_315 ) ;
F_6 ( V_108 , V_69 ,
V_316 ,
V_280 . V_288
<< V_317 ) ;
F_7 ( V_108 -> V_2 , L_29 , V_281 , V_282 ) ;
V_110 -> V_301 = V_281 ;
V_110 -> V_121 = V_282 ;
V_110 -> V_300 = V_298 ;
F_6 ( V_108 , V_65 ,
V_118 , V_299 ) ;
F_6 ( V_108 , V_65 ,
V_119 , V_299 ) ;
V_274:
F_6 ( V_108 , V_26 ,
V_125 , V_112 ) ;
return 0 ;
}
static int F_50 ( struct V_218 * V_318 , int V_319 )
{
struct V_107 * V_108 = V_318 -> V_108 ;
int V_157 ;
if ( V_319 )
V_157 = V_320 ;
else
V_157 = 0 ;
F_6 ( V_108 , V_34 , V_320 , V_157 ) ;
return 0 ;
}
static int F_51 ( struct V_107 * V_108 ,
enum V_321 V_322 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
int V_162 ;
switch ( V_322 ) {
case V_323 :
F_52 ( V_110 -> V_324 ) ;
break;
case V_325 :
F_6 ( V_108 , V_14 ,
V_326 ,
0x1 << V_327 ) ;
F_6 ( V_108 , V_13 ,
V_328 , 2 << V_329 ) ;
break;
case V_330 :
if ( F_53 ( V_108 ) == V_331 ) {
V_162 = F_54 ( F_17 ( V_110 -> V_332 ) ,
V_110 -> V_332 ) ;
if ( V_162 != 0 ) {
F_8 ( V_108 -> V_2 ,
L_30 ,
V_162 ) ;
return V_162 ;
}
F_55 ( V_110 -> V_333 , false ) ;
F_56 ( V_110 -> V_333 ) ;
F_6 ( V_108 , V_13 ,
V_334 , V_334 ) ;
F_6 ( V_108 , V_14 ,
V_335 |
V_326 ,
V_335 |
0x3 << V_327 ) ;
F_30 ( 1 ) ;
}
F_6 ( V_108 , V_14 ,
V_326 ,
0x2 << V_327 ) ;
F_6 ( V_108 , V_13 ,
V_328 , 0 ) ;
break;
case V_331 :
F_6 ( V_108 , V_14 ,
V_326 | V_335 , 0 ) ;
F_6 ( V_108 , V_13 ,
V_334 , 0 ) ;
F_55 ( V_110 -> V_333 , true ) ;
F_57 ( V_110 -> V_333 ) ;
F_58 ( F_17 ( V_110 -> V_332 ) ,
V_110 -> V_332 ) ;
F_59 ( V_110 -> V_324 ) ;
break;
}
return 0 ;
}
static void F_60 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_126 * V_127 = V_110 -> V_127 ;
struct V_336 V_337 =
F_61 ( L_31 ,
V_110 -> V_338 ,
F_15 ,
F_14 ) ;
int V_162 , V_129 , V_339 ;
const char * * V_340 ;
V_110 -> V_147 = 0 ;
V_110 -> V_153 = NULL ;
for ( V_129 = 0 ; V_129 < V_127 -> V_150 ; V_129 ++ ) {
for ( V_339 = 0 ; V_339 < V_110 -> V_147 ; V_339 ++ ) {
if ( strcmp ( V_127 -> V_151 [ V_129 ] . V_152 ,
V_110 -> V_153 [ V_339 ] ) == 0 )
break;
}
if ( V_339 != V_110 -> V_147 )
continue;
V_340 = F_62 ( V_110 -> V_153 ,
sizeof( char * ) *
( V_110 -> V_147 + 1 ) ,
V_341 ) ;
if ( V_340 == NULL )
continue;
V_340 [ V_110 -> V_147 ] =
V_127 -> V_151 [ V_129 ] . V_152 ;
V_110 -> V_147 ++ ;
V_110 -> V_153 = V_340 ;
}
F_7 ( V_108 -> V_2 , L_32 ,
V_110 -> V_147 ) ;
V_110 -> V_338 . V_342 = V_110 -> V_147 ;
V_110 -> V_338 . V_343 = V_110 -> V_153 ;
V_162 = F_36 ( V_108 , & V_337 , 1 ) ;
if ( V_162 != 0 )
F_8 ( V_108 -> V_2 ,
L_33 , V_162 ) ;
}
static void F_63 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
struct V_126 * V_127 = V_110 -> V_127 ;
int V_162 , V_129 ;
if ( ! V_127 ) {
F_36 ( V_108 , V_344 ,
F_17 ( V_344 ) ) ;
return;
}
F_7 ( V_108 -> V_2 , L_34 , V_127 -> V_141 ) ;
if ( V_127 -> V_141 ) {
struct V_336 V_337 =
F_61 ( L_35 , V_110 -> V_345 ,
F_12 , F_10 ) ;
V_110 -> V_346 = F_64 ( sizeof( char * )
* V_127 -> V_141 , V_341 ) ;
if ( ! V_110 -> V_346 )
return;
for ( V_129 = 0 ; V_129 < V_127 -> V_141 ; V_129 ++ )
V_110 -> V_346 [ V_129 ] = V_127 -> V_131 [ V_129 ] . V_152 ;
V_110 -> V_345 . V_342 = V_127 -> V_141 ;
V_110 -> V_345 . V_343 = V_110 -> V_346 ;
V_162 = F_36 ( V_108 , & V_337 , 1 ) ;
if ( V_162 != 0 )
F_8 ( V_108 -> V_2 ,
L_36 , V_162 ) ;
F_9 ( V_108 ) ;
}
F_7 ( V_108 -> V_2 , L_37 ,
V_127 -> V_150 ) ;
if ( V_127 -> V_150 )
F_60 ( V_108 ) ;
else
F_36 ( V_108 , V_344 ,
F_17 ( V_344 ) ) ;
}
static int F_65 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
switch ( V_110 -> V_201 ) {
case V_202 :
break;
case V_212 :
memset ( & V_347 . V_348 , 0 , sizeof( V_347 . V_348 ) ) ;
break;
default:
F_8 ( V_108 -> V_2 , L_38 ,
V_110 -> V_201 ) ;
return - V_122 ;
}
F_63 ( V_108 ) ;
F_32 ( V_108 ) ;
return 0 ;
}
static int F_66 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_4 ( V_108 ) ;
F_67 ( V_110 -> V_153 ) ;
F_67 ( V_110 -> V_346 ) ;
return 0 ;
}
static int F_68 ( struct V_349 * V_350 ,
const struct V_351 * V_352 )
{
struct V_109 * V_110 ;
unsigned int V_157 ;
int V_162 , V_129 ;
V_110 = F_69 ( & V_350 -> V_2 , sizeof( struct V_109 ) ,
V_341 ) ;
if ( V_110 == NULL )
return - V_353 ;
V_110 -> V_324 = F_70 ( & V_350 -> V_2 , L_39 ) ;
if ( F_71 ( V_110 -> V_324 ) ) {
V_162 = F_72 ( V_110 -> V_324 ) ;
F_8 ( & V_350 -> V_2 , L_40 ) ;
return V_162 ;
}
V_110 -> V_333 = F_73 ( V_350 , & V_354 ) ;
if ( F_71 ( V_110 -> V_333 ) ) {
V_162 = F_72 ( V_110 -> V_333 ) ;
F_8 ( & V_350 -> V_2 , L_41 ,
V_162 ) ;
return V_162 ;
}
if ( V_350 -> V_2 . V_355 ) {
const struct V_356 * V_357 ;
V_357 = F_74 ( V_358 , V_350 -> V_2 . V_355 ) ;
if ( V_357 == NULL )
return - V_122 ;
V_110 -> V_201 = * ( (enum V_359 * ) V_357 -> V_360 ) ;
} else {
V_110 -> V_201 = V_352 -> V_361 ;
}
F_75 ( V_350 , V_110 ) ;
V_110 -> V_127 = V_350 -> V_2 . V_362 ;
for ( V_129 = 0 ; V_129 < F_17 ( V_110 -> V_332 ) ; V_129 ++ )
V_110 -> V_332 [ V_129 ] . V_363 = V_364 [ V_129 ] ;
V_162 = F_76 ( & V_350 -> V_2 , F_17 ( V_110 -> V_332 ) ,
V_110 -> V_332 ) ;
if ( V_162 != 0 ) {
F_8 ( & V_350 -> V_2 , L_42 , V_162 ) ;
return V_162 ;
}
V_162 = F_54 ( F_17 ( V_110 -> V_332 ) ,
V_110 -> V_332 ) ;
if ( V_162 != 0 ) {
F_8 ( & V_350 -> V_2 , L_30 , V_162 ) ;
return V_162 ;
}
V_162 = F_77 ( V_110 -> V_333 , V_4 , & V_157 ) ;
if ( V_162 < 0 ) {
F_8 ( & V_350 -> V_2 , L_43 , V_162 ) ;
goto V_365;
}
if ( V_157 != 0x8904 ) {
F_8 ( & V_350 -> V_2 , L_44 , V_157 ) ;
V_162 = - V_122 ;
goto V_365;
}
V_162 = F_77 ( V_110 -> V_333 , V_5 , & V_157 ) ;
if ( V_162 < 0 ) {
F_8 ( & V_350 -> V_2 , L_45 ,
V_162 ) ;
goto V_365;
}
F_78 ( & V_350 -> V_2 , L_46 , V_157 + 'A' ) ;
V_162 = F_79 ( V_110 -> V_333 , V_4 , 0 ) ;
if ( V_162 < 0 ) {
F_8 ( & V_350 -> V_2 , L_47 , V_162 ) ;
goto V_365;
}
F_80 ( V_110 -> V_333 , V_35 ,
V_366 , V_366 ) ;
F_80 ( V_110 -> V_333 , V_36 ,
V_366 , V_366 ) ;
F_80 ( V_110 -> V_333 , V_31 ,
V_367 , V_367 ) ;
F_80 ( V_110 -> V_333 , V_32 ,
V_367 , V_367 ) ;
F_80 ( V_110 -> V_333 , V_47 ,
V_368 | V_369 ,
V_368 | V_369 ) ;
F_80 ( V_110 -> V_333 , V_48 ,
V_368 | V_370 ,
V_368 | V_370 ) ;
F_80 ( V_110 -> V_333 , V_49 ,
V_371 | V_372 ,
V_371 | V_372 ) ;
F_80 ( V_110 -> V_333 , V_50 ,
V_371 | V_373 ,
V_371 | V_373 ) ;
F_80 ( V_110 -> V_333 , V_24 ,
V_374 , 0 ) ;
if ( V_110 -> V_127 ) {
for ( V_129 = 0 ; V_129 < V_375 ; V_129 ++ ) {
if ( ! V_110 -> V_127 -> V_376 [ V_129 ] )
continue;
F_80 ( V_110 -> V_333 ,
V_70 + V_129 ,
0xffff ,
V_110 -> V_127 -> V_376 [ V_129 ] ) ;
}
for ( V_129 = 0 ; V_129 < V_377 ; V_129 ++ )
F_80 ( V_110 -> V_333 ,
V_15 + V_129 ,
0xffff ,
V_110 -> V_127 -> V_378 [ V_129 ] ) ;
}
F_80 ( V_110 -> V_333 , V_59 ,
V_379 , V_379 ) ;
F_80 ( V_110 -> V_333 , V_13 ,
V_380 , 0 ) ;
F_55 ( V_110 -> V_333 , true ) ;
F_58 ( F_17 ( V_110 -> V_332 ) , V_110 -> V_332 ) ;
V_162 = F_81 ( & V_350 -> V_2 ,
& V_381 , & V_347 , 1 ) ;
if ( V_162 != 0 )
return V_162 ;
return 0 ;
V_365:
F_58 ( F_17 ( V_110 -> V_332 ) , V_110 -> V_332 ) ;
return V_162 ;
}
static int F_82 ( struct V_349 * V_382 )
{
F_83 ( & V_382 -> V_2 ) ;
return 0 ;
}
