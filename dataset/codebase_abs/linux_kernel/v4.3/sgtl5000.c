static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_5 ) {
case V_11 :
F_4 ( V_7 , V_12 ,
V_13 ,
V_10 -> V_14 << V_15 ) ;
break;
case V_16 :
F_4 ( V_7 , V_12 ,
V_13 , 0 ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
const T_1 V_17 = V_18 | V_19 ;
switch ( V_5 ) {
case V_11 :
F_4 ( V_7 , V_20 ,
V_21 , V_21 ) ;
break;
case V_16 :
if ( ( F_6 ( V_7 , V_20 ) &
V_17 ) != V_17 ) {
F_4 ( V_7 , V_20 ,
V_21 , 0 ) ;
F_7 ( 400 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_22 * V_23 )
{
V_23 -> type = V_24 ;
V_23 -> V_25 = 2 ;
V_23 -> V_26 . integer . V_27 = 0 ;
V_23 -> V_26 . integer . V_28 = 0xfc - 0x3c ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
int V_31 ;
int V_32 ;
int V_33 ;
V_31 = F_6 ( V_7 , V_34 ) ;
V_32 = ( V_31 & V_35 ) >> V_36 ;
V_33 = ( V_31 & V_37 ) >> V_38 ;
V_32 = F_11 ( V_32 , 0x3c , 0xfc ) ;
V_33 = F_11 ( V_33 , 0x3c , 0xfc ) ;
V_32 = 0xfc - V_32 ;
V_33 = 0xfc - V_33 ;
V_30 -> V_26 . integer . V_26 [ 0 ] = V_32 ;
V_30 -> V_26 . integer . V_26 [ 1 ] = V_33 ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
int V_31 ;
int V_32 ;
int V_33 ;
V_32 = V_30 -> V_26 . integer . V_26 [ 0 ] ;
V_33 = V_30 -> V_26 . integer . V_26 [ 1 ] ;
V_32 = F_11 ( V_32 , 0 , 0xfc - 0x3c ) ;
V_33 = F_11 ( V_33 , 0 , 0xfc - 0x3c ) ;
V_32 = 0xfc - V_32 ;
V_33 = 0xfc - V_33 ;
V_31 = V_32 << V_36 |
V_33 << V_38 ;
F_13 ( V_7 , V_34 , V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_39 * V_40 , int V_41 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
T_2 V_42 = V_43 | V_44 ;
F_4 ( V_7 , V_45 ,
V_42 , V_41 ? V_42 : 0 ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 , unsigned int V_46 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
T_2 V_47 = 0 ;
V_10 -> V_48 = 0 ;
switch ( V_46 & V_49 ) {
case V_50 :
break;
case V_51 :
V_47 |= V_52 ;
V_10 -> V_48 = 1 ;
break;
default:
return - V_53 ;
}
switch ( V_46 & V_54 ) {
case V_55 :
V_47 |= V_56 << V_57 ;
break;
case V_58 :
V_47 |= V_56 << V_57 ;
V_47 |= V_59 ;
break;
case V_60 :
V_47 |= V_61 << V_57 ;
break;
case V_62 :
V_47 |= V_63 << V_57 ;
V_47 |= V_64 ;
break;
case V_65 :
V_47 |= V_61 << V_57 ;
V_47 |= V_59 ;
break;
default:
return - V_53 ;
}
V_10 -> V_46 = V_46 & V_54 ;
switch ( V_46 & V_66 ) {
case V_67 :
break;
case V_68 :
V_47 |= V_69 ;
break;
default:
return - V_53 ;
}
F_13 ( V_7 , V_70 , V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_39 * V_40 ,
int V_71 , unsigned int V_72 , int V_73 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_71 ) {
case V_74 :
V_10 -> V_75 = V_72 ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , int V_76 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_77 = 0 ;
int V_78 ;
switch ( V_76 ) {
case 8000 :
case 16000 :
V_78 = 32000 ;
break;
case 11025 :
case 22050 :
V_78 = 44100 ;
break;
default:
V_78 = V_76 ;
break;
}
switch ( V_78 / V_76 ) {
case 4 :
V_77 |= V_79 << V_80 ;
break;
case 2 :
V_77 |= V_81 << V_80 ;
break;
case 1 :
V_77 |= V_82 << V_80 ;
break;
default:
return - V_53 ;
}
switch ( V_78 ) {
case 32000 :
V_77 |= V_83 << V_84 ;
break;
case 44100 :
V_77 |= V_85 << V_84 ;
break;
case 48000 :
V_77 |= V_86 << V_84 ;
break;
case 96000 :
V_77 |= V_87 << V_84 ;
break;
default:
F_18 ( V_7 -> V_88 , L_1 ,
V_76 ) ;
return - V_53 ;
}
switch ( V_10 -> V_75 / V_76 ) {
case 256 :
V_77 |= V_89 <<
V_90 ;
break;
case 384 :
V_77 |= V_91 <<
V_90 ;
break;
case 512 :
V_77 |= V_92 <<
V_90 ;
break;
default:
if ( V_10 -> V_48 ) {
V_77 |= V_93 <<
V_90 ;
} else {
F_18 ( V_7 -> V_88 ,
L_2 ) ;
F_18 ( V_7 -> V_88 , L_3
L_4 ,
V_10 -> V_75 / V_76 ) ;
return - V_53 ;
}
}
if ( ( V_77 & V_94 ) == V_93 ) {
T_3 V_95 , V_96 ;
int V_97 ;
int V_98 ;
unsigned int V_99 , V_100 , V_101 ;
if ( V_10 -> V_75 > 17000000 ) {
V_97 = 1 ;
V_99 = V_10 -> V_75 / 2 ;
} else {
V_97 = 0 ;
V_99 = V_10 -> V_75 ;
}
if ( V_78 == 44100 )
V_95 = 180633600 ;
else
V_95 = 196608000 ;
V_96 = F_19 ( V_95 , V_99 ) ;
V_100 = V_95 ;
V_96 *= 2048 ;
F_19 ( V_96 , V_99 ) ;
V_101 = V_96 ;
V_98 = V_100 << V_102 |
V_101 << V_103 ;
F_13 ( V_7 , V_104 , V_98 ) ;
if ( V_97 )
F_4 ( V_7 ,
V_105 ,
V_106 ,
V_106 ) ;
else
F_4 ( V_7 ,
V_105 ,
V_106 ,
0 ) ;
F_4 ( V_7 , V_20 ,
V_107 | V_108 ,
V_107 | V_108 ) ;
F_13 ( V_7 , V_109 , V_77 ) ;
} else {
F_13 ( V_7 , V_109 , V_77 ) ;
F_4 ( V_7 , V_20 ,
V_107 | V_108 ,
0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_110 * V_111 ,
struct V_112 * V_113 ,
struct V_39 * V_114 )
{
struct V_6 * V_7 = V_114 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_115 = F_21 ( V_113 ) ;
int V_116 = 0 ;
int V_117 ;
int V_118 ;
if ( ! V_10 -> V_75 ) {
F_18 ( V_7 -> V_88 , L_5 , V_119 ) ;
return - V_120 ;
}
if ( V_111 -> V_121 == V_122 )
V_117 = V_123 ;
else
V_117 = V_124 ;
F_4 ( V_7 , V_20 , V_117 ,
V_115 == 1 ? 0 : V_117 ) ;
V_118 = F_17 ( V_7 , F_22 ( V_113 ) ) ;
if ( V_118 )
return V_118 ;
switch ( F_23 ( V_113 ) ) {
case 16 :
if ( V_10 -> V_46 == V_62 )
return - V_53 ;
V_116 |= V_125 << V_126 ;
V_116 |= V_127 <<
V_128 ;
break;
case 20 :
V_116 |= V_129 << V_126 ;
V_116 |= V_130 <<
V_128 ;
break;
case 24 :
V_116 |= V_131 << V_126 ;
V_116 |= V_130 <<
V_128 ;
break;
case 32 :
if ( V_10 -> V_46 == V_62 )
return - V_53 ;
V_116 |= V_132 << V_126 ;
V_116 |= V_130 <<
V_128 ;
break;
default:
return - V_53 ;
}
F_4 ( V_7 , V_70 ,
V_133 | V_134 ,
V_116 ) ;
return 0 ;
}
static int F_24 ( struct V_135 * V_88 )
{
struct V_136 * V_137 = F_25 ( V_88 ) ;
return V_137 -> V_138 ;
}
static int F_26 ( struct V_135 * V_88 )
{
struct V_136 * V_137 = F_25 ( V_88 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_137 -> V_139 ;
int V_31 ;
if ( F_24 ( V_88 ) )
return 0 ;
V_31 = ( 1600 - V_137 -> V_140 / 1000 ) / 50 ;
V_31 = F_11 ( V_31 , 0x0 , 0xf ) ;
V_137 -> V_140 = ( 1600 - V_31 * 50 ) * 1000 ;
F_4 ( V_7 , V_141 ,
V_142 , V_31 ) ;
F_4 ( V_7 , V_20 ,
V_143 ,
V_143 ) ;
F_4 ( V_7 , V_20 ,
V_144 ,
0 ) ;
V_137 -> V_138 = 1 ;
return 0 ;
}
static int F_27 ( struct V_135 * V_88 )
{
struct V_136 * V_137 = F_25 ( V_88 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_137 -> V_139 ;
F_4 ( V_7 , V_20 ,
V_143 ,
0 ) ;
F_4 ( V_7 , V_141 ,
V_142 , 0 ) ;
V_137 -> V_138 = 0 ;
return 0 ;
}
static int F_28 ( struct V_135 * V_88 )
{
struct V_136 * V_137 = F_25 ( V_88 ) ;
return V_137 -> V_140 ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_145 * V_146 ,
int V_140 )
{
struct V_136 * V_137 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_147 V_148 = { } ;
V_137 = F_30 ( sizeof( struct V_136 ) , V_149 ) ;
if ( ! V_137 )
return - V_150 ;
V_137 -> V_151 . V_152 = F_31 ( F_32 ( V_7 -> V_88 ) , V_149 ) ;
if ( ! V_137 -> V_151 . V_152 ) {
F_33 ( V_137 ) ;
F_18 ( V_7 -> V_88 , L_6 ) ;
return - V_150 ;
}
V_137 -> V_151 . type = V_153 ;
V_137 -> V_151 . V_154 = V_155 ;
V_137 -> V_151 . V_156 = & V_157 ;
V_137 -> V_151 . V_158 = 1 ;
V_137 -> V_139 = V_7 ;
V_137 -> V_140 = V_140 ;
V_148 . V_88 = V_7 -> V_88 ;
V_148 . V_159 = V_137 ;
V_148 . V_146 = V_146 ;
V_137 -> V_88 = F_34 ( & V_137 -> V_151 , & V_148 ) ;
if ( F_35 ( V_137 -> V_88 ) ) {
int V_118 = F_36 ( V_137 -> V_88 ) ;
F_18 ( V_7 -> V_88 , L_7 ) ;
F_33 ( V_137 -> V_151 . V_152 ) ;
F_33 ( V_137 ) ;
return V_118 ;
}
V_10 -> V_137 = V_137 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_136 * V_137 = V_10 -> V_137 ;
if ( ! V_137 )
return 0 ;
F_38 ( V_137 -> V_88 ) ;
F_33 ( V_137 -> V_151 . V_152 ) ;
F_33 ( V_137 ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_145 * V_146 ,
int V_140 )
{
F_18 ( V_7 -> V_88 , L_8 ) ;
return - V_53 ;
}
static int F_37 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_39 ( struct V_6 * V_7 ,
enum V_160 V_161 )
{
int V_118 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_161 ) {
case V_162 :
case V_163 :
break;
case V_164 :
if ( F_40 ( V_7 ) == V_165 ) {
V_118 = F_41 (
F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
if ( V_118 )
return V_118 ;
F_43 ( 10 ) ;
F_44 ( V_10 -> V_167 , false ) ;
V_118 = F_45 ( V_10 -> V_167 ) ;
if ( V_118 != 0 ) {
F_18 ( V_7 -> V_88 ,
L_9 , V_118 ) ;
F_44 ( V_10 -> V_167 , true ) ;
F_46 ( F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
return V_118 ;
}
}
break;
case V_165 :
F_44 ( V_10 -> V_167 , true ) ;
F_46 ( F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
break;
}
return 0 ;
}
static bool F_47 ( struct V_168 * V_88 , unsigned int V_31 )
{
switch ( V_31 ) {
case V_169 :
case V_45 :
case V_170 :
return true ;
}
return false ;
}
static bool F_48 ( struct V_168 * V_88 , unsigned int V_31 )
{
switch ( V_31 ) {
case V_169 :
case V_171 :
case V_109 :
case V_70 :
case V_172 :
case V_45 :
case V_34 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_141 :
case V_177 :
case V_12 :
case V_178 :
case V_179 :
case V_20 :
case V_104 :
case V_105 :
case V_170 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
return true ;
default:
return false ;
}
}
static int F_49 ( struct V_6 * V_7 )
{
int V_210 ;
int V_211 ;
int V_212 ;
T_2 V_213 ;
T_2 V_214 ;
int V_215 ;
int V_216 ;
int V_217 ;
int V_218 ;
T_4 V_219 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_211 = F_50 ( V_10 -> V_166 [ V_220 ] . V_221 ) ;
V_212 = F_50 ( V_10 -> V_166 [ V_222 ] . V_221 ) ;
V_210 = F_50 ( V_10 -> V_166 [ V_223 ] . V_221 ) ;
V_211 = V_211 / 1000 ;
V_212 = V_212 / 1000 ;
V_210 = V_210 / 1000 ;
if ( V_211 <= 0 || V_212 <= 0 || V_210 < 0 ) {
F_18 ( V_7 -> V_88 , L_10 ) ;
return - V_53 ;
}
if ( V_211 > 3600 || V_212 > 3600 || V_210 > 1980 ) {
F_18 ( V_7 -> V_88 ,
L_11 ,
V_211 , V_212 , V_210 ) ;
return - V_53 ;
}
V_213 = F_6 ( V_7 , V_20 ) ;
V_213 |= V_123 |
V_124 |
V_224 ;
V_214 = F_6 ( V_7 , V_141 ) ;
if ( V_212 < 3100 && V_211 < 3100 ) {
F_4 ( V_7 , V_105 ,
V_225 ,
V_225 ) ;
V_213 |= V_226 ;
} else if ( V_212 >= 3100 && V_211 >= 3100 ) {
V_213 &= ~ V_226 ;
V_214 |= V_227 ;
V_214 |= V_228 <<
V_229 ;
}
F_13 ( V_7 , V_141 , V_214 ) ;
F_13 ( V_7 , V_20 , V_213 ) ;
F_4 ( V_7 , V_141 ,
V_142 , 0x8 ) ;
if ( V_213 & V_143 )
F_4 ( V_7 , V_20 ,
V_144 ,
0 ) ;
else
F_4 ( V_7 , V_20 ,
V_144 |
V_230 ,
0 ) ;
V_215 = V_211 / 2 ;
if ( V_215 <= V_231 )
V_215 = 0 ;
else if ( V_215 >= V_231 + V_232 *
( V_233 >> V_234 ) )
V_215 = V_233 >> V_234 ;
else
V_215 = ( V_215 - V_231 ) / V_232 ;
F_4 ( V_7 , V_177 ,
V_233 , V_215 << V_234 ) ;
V_216 = V_212 / 2 ;
if ( V_216 <= V_235 )
V_216 = 0 ;
else if ( V_216 >= V_235 +
V_236 * V_237 )
V_216 = V_237 ;
else
V_216 = ( V_216 - V_235 ) /
V_236 ;
F_4 ( V_7 , V_178 ,
V_238 |
V_239 ,
V_216 << V_240 |
V_241 <<
V_242 ) ;
V_217 = ( V_215 * 100 ) / V_216 ;
V_218 = 0 ;
for ( V_219 = 0 ; V_219 < F_42 ( V_243 ) ; V_219 ++ ) {
if ( V_217 >= V_243 [ V_219 ] )
V_218 = V_219 ;
else
break;
}
F_4 ( V_7 , V_179 ,
V_244 |
V_245 ,
V_218 << V_246 |
V_218 << V_247 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_118 ;
V_118 = F_29 ( V_7 , & V_248 , V_249 ) ;
if ( V_118 ) {
F_18 ( V_7 -> V_88 ,
L_12 , V_118 ) ;
return V_118 ;
}
V_10 -> V_166 [ V_223 ] . V_250 = V_251 ;
F_52 ( V_7 -> V_88 , L_13 ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 )
{
int V_118 ;
int V_219 ;
int V_252 = 0 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_253 * V_210 ;
for ( V_219 = 0 ; V_219 < F_42 ( V_10 -> V_166 ) ; V_219 ++ )
V_10 -> V_166 [ V_219 ] . V_250 = V_254 [ V_219 ] ;
if ( V_10 -> V_255 < 0x11 ) {
V_210 = F_54 ( V_7 -> V_88 , L_14 ) ;
if ( F_35 ( V_210 ) ) {
if ( F_36 ( V_210 ) == - V_256 )
return - V_256 ;
} else {
V_252 = 1 ;
F_55 ( V_210 ) ;
}
}
if ( ! V_252 ) {
V_118 = F_51 ( V_7 ) ;
if ( V_118 )
return V_118 ;
}
V_118 = F_56 ( V_7 -> V_88 , F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
if ( V_118 )
goto V_257;
V_118 = F_41 ( F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
if ( V_118 )
goto V_258;
F_43 ( 10 ) ;
return 0 ;
V_258:
F_57 ( F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
V_257:
if ( ! V_252 )
F_37 ( V_7 ) ;
return V_118 ;
}
static int F_58 ( struct V_6 * V_7 )
{
int V_118 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_118 = F_53 ( V_7 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_49 ( V_7 ) ;
if ( V_118 )
goto V_259;
F_4 ( V_7 , V_177 ,
V_260 , 1 ) ;
F_13 ( V_7 , V_180 , 0 ) ;
F_13 ( V_7 , V_172 ,
V_261 << V_262 ) ;
F_13 ( V_7 , V_171 ,
V_263 | V_264 ) ;
F_13 ( V_7 , V_45 ,
V_265 |
V_44 |
V_43 ) ;
F_13 ( V_7 , V_173 , 0x015f ) ;
F_13 ( V_7 , V_176 ,
V_266 |
V_267 ) ;
F_4 ( V_7 , V_12 ,
V_13 ,
V_10 -> V_14 << V_15 ) ;
F_4 ( V_7 , V_12 ,
V_268 ,
V_10 -> V_269 << V_270 ) ;
F_13 ( V_7 , V_182 , 0 ) ;
return 0 ;
V_259:
F_46 ( F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
F_57 ( F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
F_37 ( V_7 ) ;
return V_118 ;
}
static int F_59 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_46 ( F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
F_57 ( F_42 ( V_10 -> V_166 ) ,
V_10 -> V_166 ) ;
F_37 ( V_7 ) ;
return 0 ;
}
static int F_60 ( struct V_9 * V_10 )
{
int V_219 , V_118 , V_271 , V_272 ;
for ( V_219 = 0 ; V_219 < F_42 ( V_273 ) ; V_219 ++ ) {
V_271 = V_273 [ V_219 ] . V_274 ;
V_272 = V_273 [ V_219 ] . V_31 ;
V_118 = F_61 ( V_10 -> V_167 , V_272 , V_271 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_62 ( struct V_275 * V_276 ,
const struct V_277 * V_278 )
{
struct V_9 * V_10 ;
int V_118 , V_31 , V_279 ;
struct V_280 * V_281 = V_276 -> V_88 . V_282 ;
T_1 V_26 ;
V_10 = F_63 ( & V_276 -> V_88 , sizeof( * V_10 ) , V_149 ) ;
if ( ! V_10 )
return - V_150 ;
V_10 -> V_167 = F_64 ( V_276 , & V_283 ) ;
if ( F_35 ( V_10 -> V_167 ) ) {
V_118 = F_36 ( V_10 -> V_167 ) ;
F_18 ( & V_276 -> V_88 , L_15 , V_118 ) ;
return V_118 ;
}
V_10 -> V_284 = F_65 ( & V_276 -> V_88 , NULL ) ;
if ( F_35 ( V_10 -> V_284 ) ) {
V_118 = F_36 ( V_10 -> V_284 ) ;
F_18 ( & V_276 -> V_88 , L_16 , V_118 ) ;
if ( V_118 == - V_285 )
return - V_256 ;
return V_118 ;
}
V_118 = F_66 ( V_10 -> V_284 ) ;
if ( V_118 )
return V_118 ;
F_43 ( 1 ) ;
V_118 = F_67 ( V_10 -> V_167 , V_169 , & V_31 ) ;
if ( V_118 )
goto V_286;
if ( ( ( V_31 & V_287 ) >> V_288 ) !=
V_289 ) {
F_18 ( & V_276 -> V_88 ,
L_17 , V_31 ) ;
V_118 = - V_290 ;
goto V_286;
}
V_279 = ( V_31 & V_291 ) >> V_292 ;
F_52 ( & V_276 -> V_88 , L_18 , V_279 ) ;
V_10 -> V_255 = V_279 ;
if ( V_281 ) {
if ( ! F_68 ( V_281 ,
L_19 , & V_26 ) ) {
switch ( V_26 ) {
case V_293 :
V_10 -> V_14 = 0 ;
break;
case V_294 :
V_10 -> V_14 = 1 ;
break;
case V_295 :
V_10 -> V_14 = 2 ;
break;
case V_296 :
V_10 -> V_14 = 3 ;
break;
default:
V_10 -> V_14 = 2 ;
F_18 ( & V_276 -> V_88 ,
L_20 ) ;
}
} else {
V_10 -> V_14 = 2 ;
}
if ( ! F_68 ( V_281 ,
L_21 , & V_26 ) ) {
if ( ( V_26 >= 1250 ) && ( V_26 <= 3000 ) )
V_10 -> V_269 = ( V_26 / 250 ) - 5 ;
else {
V_10 -> V_269 = 0 ;
F_18 ( & V_276 -> V_88 ,
L_22 ) ;
}
} else {
V_10 -> V_269 = 0 ;
}
}
F_69 ( V_276 , V_10 ) ;
V_118 = F_60 ( V_10 ) ;
if ( V_118 )
goto V_286;
V_118 = F_70 ( & V_276 -> V_88 ,
& V_297 , & V_298 , 1 ) ;
if ( V_118 )
goto V_286;
return 0 ;
V_286:
F_71 ( V_10 -> V_284 ) ;
return V_118 ;
}
static int F_72 ( struct V_275 * V_276 )
{
struct V_9 * V_10 = F_73 ( V_276 ) ;
F_74 ( & V_276 -> V_88 ) ;
F_71 ( V_10 -> V_284 ) ;
return 0 ;
}
