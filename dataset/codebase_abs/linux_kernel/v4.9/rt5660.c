static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ )
if ( ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_6 +
V_5 [ V_4 ] . V_7 ) ||
( V_3 >= V_5 [ V_4 ] . V_8 &&
V_3 <= V_5 [ V_4 ] . V_9 ) )
return true ;
switch ( V_3 ) {
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
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ )
if ( ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_6 +
V_5 [ V_4 ] . V_7 ) ||
( V_3 >= V_5 [ V_4 ] . V_8 &&
V_3 <= V_5 [ V_4 ] . V_9 ) )
return true ;
switch ( V_3 ) {
case V_10 :
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
case V_11 :
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
case V_12 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_13 :
case V_14 :
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
case V_107 :
case V_108 :
case V_15 :
case V_16 :
case V_17 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_109 * V_110 ,
struct V_111 * V_112 , int V_113 )
{
struct V_114 * V_115 = F_5 ( V_110 -> V_116 ) ;
struct V_117 * V_118 = F_6 ( V_115 ) ;
int V_119 , V_120 ;
V_120 = V_118 -> V_121 / F_7 ( V_118 -> V_122 ,
V_51 , V_123 ) ;
V_119 = F_8 ( V_120 ) ;
if ( V_119 < 0 )
F_9 ( V_115 -> V_2 , L_1 ) ;
else
F_10 ( V_115 , V_53 ,
V_124 , V_119 << V_125 ) ;
return V_119 ;
}
static int F_11 ( struct V_109 * V_126 ,
struct V_109 * V_127 )
{
struct V_114 * V_115 = F_5 ( V_126 -> V_116 ) ;
unsigned int V_128 ;
V_128 = F_12 ( V_115 , V_54 ) ;
V_128 &= V_129 ;
if ( V_128 == V_130 )
return 1 ;
else
return 0 ;
}
static int F_13 ( struct V_109 * V_110 ,
struct V_111 * V_112 , int V_113 )
{
struct V_114 * V_115 = F_5 ( V_110 -> V_116 ) ;
switch ( V_113 ) {
case V_131 :
F_10 ( V_115 , V_59 ,
V_132 | V_133 ,
V_134 | V_135 ) ;
break;
case V_136 :
F_10 ( V_115 , V_59 ,
V_132 | V_133 ,
V_137 | V_138 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_14 ( struct V_139 * V_140 ,
struct V_141 * V_142 , struct V_143 * V_144 )
{
struct V_114 * V_115 = V_144 -> V_115 ;
struct V_117 * V_118 = F_6 ( V_115 ) ;
unsigned int V_145 = 0 , V_146 , V_147 ;
int V_148 , V_149 , V_150 ;
V_118 -> V_151 [ V_144 -> V_152 ] = F_15 ( V_142 ) ;
V_148 = F_16 ( V_118 -> V_121 , V_118 -> V_151 [ V_144 -> V_152 ] ) ;
if ( V_148 < 0 ) {
F_9 ( V_115 -> V_2 , L_2 ,
V_118 -> V_151 [ V_144 -> V_152 ] , V_144 -> V_152 ) ;
return - V_153 ;
}
V_150 = F_17 ( V_142 ) ;
if ( V_150 < 0 ) {
F_9 ( V_115 -> V_2 , L_3 , V_150 ) ;
return V_150 ;
}
if ( V_150 > 32 )
V_149 = 1 ;
else
V_149 = 0 ;
V_118 -> V_154 [ V_144 -> V_152 ] = V_118 -> V_151 [ V_144 -> V_152 ] * ( 32 << V_149 ) ;
F_18 ( V_144 -> V_2 , L_4 ,
V_118 -> V_154 [ V_144 -> V_152 ] , V_118 -> V_151 [ V_144 -> V_152 ] ) ;
F_18 ( V_144 -> V_2 , L_5 ,
V_149 , V_148 , V_144 -> V_152 ) ;
switch ( F_19 ( V_142 ) ) {
case 16 :
break;
case 20 :
V_145 |= V_155 ;
break;
case 24 :
V_145 |= V_156 ;
break;
case 8 :
V_145 |= V_157 ;
break;
default:
return - V_153 ;
}
switch ( V_144 -> V_152 ) {
case V_158 :
V_147 = V_159 | V_160 ;
V_146 = V_149 << V_161 |
V_148 << V_123 ;
F_10 ( V_115 , V_50 , V_162 ,
V_145 ) ;
F_10 ( V_115 , V_51 , V_147 , V_146 ) ;
break;
default:
F_9 ( V_115 -> V_2 , L_6 , V_144 -> V_152 ) ;
return - V_153 ;
}
return 0 ;
}
static int F_20 ( struct V_143 * V_144 , unsigned int V_163 )
{
struct V_114 * V_115 = V_144 -> V_115 ;
struct V_117 * V_118 = F_6 ( V_115 ) ;
unsigned int V_164 = 0 ;
switch ( V_163 & V_165 ) {
case V_166 :
V_118 -> V_167 [ V_144 -> V_152 ] = 1 ;
break;
case V_168 :
V_164 |= V_169 ;
V_118 -> V_167 [ V_144 -> V_152 ] = 0 ;
break;
default:
return - V_153 ;
}
switch ( V_163 & V_170 ) {
case V_171 :
break;
case V_172 :
V_164 |= V_173 ;
break;
default:
return - V_153 ;
}
switch ( V_163 & V_174 ) {
case V_175 :
break;
case V_176 :
V_164 |= V_177 ;
break;
case V_178 :
V_164 |= V_179 ;
break;
case V_180 :
V_164 |= V_181 ;
break;
default:
return - V_153 ;
}
switch ( V_144 -> V_152 ) {
case V_158 :
F_10 ( V_115 , V_50 ,
V_182 | V_183 |
V_184 , V_164 ) ;
break;
default:
F_9 ( V_115 -> V_2 , L_6 , V_144 -> V_152 ) ;
return - V_153 ;
}
return 0 ;
}
static int F_21 ( struct V_143 * V_144 ,
int V_185 , unsigned int V_186 , int V_187 )
{
struct V_114 * V_115 = V_144 -> V_115 ;
struct V_117 * V_118 = F_6 ( V_115 ) ;
unsigned int V_164 = 0 ;
if ( V_186 == V_118 -> V_121 && V_185 == V_118 -> V_188 )
return 0 ;
switch ( V_185 ) {
case V_189 :
V_164 |= V_190 ;
break;
case V_191 :
V_164 |= V_130 ;
break;
case V_192 :
V_164 |= V_193 ;
break;
default:
F_9 ( V_115 -> V_2 , L_7 , V_185 ) ;
return - V_153 ;
}
F_10 ( V_115 , V_54 , V_129 ,
V_164 ) ;
V_118 -> V_121 = V_186 ;
V_118 -> V_188 = V_185 ;
F_18 ( V_144 -> V_2 , L_8 , V_186 , V_185 ) ;
return 0 ;
}
static int F_22 ( struct V_143 * V_144 , int V_194 , int V_126 ,
unsigned int V_195 , unsigned int V_196 )
{
struct V_114 * V_115 = V_144 -> V_115 ;
struct V_117 * V_118 = F_6 ( V_115 ) ;
struct V_197 V_198 ;
int V_199 ;
if ( V_126 == V_118 -> V_200 && V_195 == V_118 -> V_201 &&
V_196 == V_118 -> V_202 )
return 0 ;
if ( ! V_195 || ! V_196 ) {
F_18 ( V_115 -> V_2 , L_9 ) ;
V_118 -> V_201 = 0 ;
V_118 -> V_202 = 0 ;
F_10 ( V_115 , V_54 ,
V_129 , V_190 ) ;
return 0 ;
}
switch ( V_126 ) {
case V_203 :
F_10 ( V_115 , V_54 ,
V_204 , V_205 ) ;
break;
case V_206 :
F_10 ( V_115 , V_54 ,
V_204 , V_207 ) ;
break;
default:
F_9 ( V_115 -> V_2 , L_10 , V_126 ) ;
return - V_153 ;
}
V_199 = F_23 ( V_195 , V_196 , & V_198 ) ;
if ( V_199 < 0 ) {
F_9 ( V_115 -> V_2 , L_11 , V_195 ) ;
return V_199 ;
}
F_18 ( V_115 -> V_2 , L_12 ,
V_198 . V_208 , ( V_198 . V_208 ? 0 : V_198 . V_209 ) ,
V_198 . V_210 , V_198 . V_211 ) ;
F_24 ( V_115 , V_55 ,
V_198 . V_210 << V_212 | V_198 . V_211 ) ;
F_24 ( V_115 , V_56 ,
( V_198 . V_208 ? 0 : V_198 . V_209 ) << V_213 |
V_198 . V_208 << V_214 ) ;
V_118 -> V_201 = V_195 ;
V_118 -> V_202 = V_196 ;
V_118 -> V_200 = V_126 ;
return 0 ;
}
static int F_25 ( struct V_114 * V_115 ,
enum V_215 V_216 )
{
struct V_117 * V_118 = F_6 ( V_115 ) ;
int V_199 ;
switch ( V_216 ) {
case V_217 :
break;
case V_218 :
F_10 ( V_115 , V_106 ,
V_219 , V_219 ) ;
if ( F_26 ( V_118 -> V_220 ) )
break;
if ( F_27 ( V_115 ) == V_217 ) {
F_28 ( V_118 -> V_220 ) ;
} else {
V_199 = F_29 ( V_118 -> V_220 ) ;
if ( V_199 )
return V_199 ;
}
break;
case V_221 :
if ( F_27 ( V_115 ) == V_222 ) {
F_10 ( V_115 , V_45 ,
V_223 | V_224 |
V_225 | V_226 ,
V_223 | V_224 |
V_225 | V_226 ) ;
F_30 ( 10000 , 15000 ) ;
F_10 ( V_115 , V_45 ,
V_227 | V_228 ,
V_227 | V_228 ) ;
}
break;
case V_222 :
F_10 ( V_115 , V_106 ,
V_219 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_31 ( struct V_114 * V_115 )
{
struct V_117 * V_118 = F_6 ( V_115 ) ;
V_118 -> V_115 = V_115 ;
return 0 ;
}
static int F_32 ( struct V_114 * V_115 )
{
return F_24 ( V_115 , V_10 , 0 ) ;
}
static int F_33 ( struct V_114 * V_115 )
{
struct V_117 * V_118 = F_6 ( V_115 ) ;
F_34 ( V_118 -> V_122 , true ) ;
F_35 ( V_118 -> V_122 ) ;
return 0 ;
}
static int F_36 ( struct V_114 * V_115 )
{
struct V_117 * V_118 = F_6 ( V_115 ) ;
if ( V_118 -> V_229 . V_230 )
F_30 ( 350000 , 400000 ) ;
F_34 ( V_118 -> V_122 , false ) ;
F_37 ( V_118 -> V_122 ) ;
return 0 ;
}
static int F_38 ( struct V_117 * V_118 , struct V_1 * V_2 )
{
V_118 -> V_229 . V_231 = F_39 ( V_2 ,
L_13 ) ;
V_118 -> V_229 . V_232 = F_39 ( V_2 ,
L_14 ) ;
V_118 -> V_229 . V_230 = F_39 ( V_2 ,
L_15 ) ;
F_40 ( V_2 , L_16 ,
& V_118 -> V_229 . V_233 ) ;
return 0 ;
}
static int F_41 ( struct V_234 * V_235 ,
const struct V_236 * V_152 )
{
struct V_237 * V_229 = F_42 ( & V_235 -> V_2 ) ;
struct V_117 * V_118 ;
int V_199 ;
unsigned int V_128 ;
V_118 = F_43 ( & V_235 -> V_2 , sizeof( struct V_117 ) ,
V_238 ) ;
if ( V_118 == NULL )
return - V_239 ;
V_118 -> V_220 = F_44 ( & V_235 -> V_2 , L_17 ) ;
if ( F_45 ( V_118 -> V_220 ) == - V_240 )
return - V_240 ;
F_46 ( V_235 , V_118 ) ;
if ( V_229 )
V_118 -> V_229 = * V_229 ;
else if ( V_235 -> V_2 . V_241 )
F_38 ( V_118 , & V_235 -> V_2 ) ;
V_118 -> V_122 = F_47 ( V_235 , & V_242 ) ;
if ( F_26 ( V_118 -> V_122 ) ) {
V_199 = F_45 ( V_118 -> V_122 ) ;
F_9 ( & V_235 -> V_2 , L_18 ,
V_199 ) ;
return V_199 ;
}
F_48 ( V_118 -> V_122 , V_17 , & V_128 ) ;
if ( V_128 != V_243 ) {
F_9 ( & V_235 -> V_2 ,
L_19 , V_128 ) ;
return - V_244 ;
}
F_49 ( V_118 -> V_122 , V_10 , 0 ) ;
V_199 = F_50 ( V_118 -> V_122 , V_245 ,
F_2 ( V_245 ) ) ;
if ( V_199 != 0 )
F_51 ( & V_235 -> V_2 , L_20 , V_199 ) ;
if ( V_118 -> V_229 . V_233 ) {
F_52 ( V_118 -> V_122 , V_84 ,
V_246 , V_247 ) ;
if ( V_118 -> V_229 . V_233 == V_248 )
F_52 ( V_118 -> V_122 , V_53 ,
V_249 ,
V_250 ) ;
else if ( V_118 -> V_229 . V_233 == V_251 )
F_52 ( V_118 -> V_122 , V_53 ,
V_249 ,
V_252 ) ;
}
return F_53 ( & V_235 -> V_2 , & V_253 ,
V_254 , F_2 ( V_254 ) ) ;
}
static int F_54 ( struct V_234 * V_235 )
{
F_55 ( & V_235 -> V_2 ) ;
return 0 ;
}
