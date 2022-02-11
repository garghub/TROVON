static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
switch ( V_5 ) {
case V_6 :
F_2 ( V_2 -> V_7 , V_8 ,
V_9 ,
V_10 << V_11 ) ;
break;
case V_12 :
F_2 ( V_2 -> V_7 , V_8 ,
V_9 , 0 ) ;
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
const T_1 V_13 = V_14 | V_15 ;
switch ( V_5 ) {
case V_6 :
F_2 ( V_2 -> V_7 , V_16 ,
V_17 , V_17 ) ;
break;
case V_12 :
if ( ( F_4 ( V_2 -> V_7 , V_16 ) &
V_13 ) != V_13 ) {
F_2 ( V_2 -> V_7 , V_16 ,
V_17 , 0 ) ;
F_5 ( 400 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_18 * V_19 )
{
V_19 -> type = V_20 ;
V_19 -> V_21 = 2 ;
V_19 -> V_22 . integer . V_23 = 0 ;
V_19 -> V_22 . integer . V_24 = 0xfc - 0x3c ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_25 * V_26 )
{
struct V_27 * V_7 = F_8 ( V_4 ) ;
int V_28 ;
int V_29 ;
int V_30 ;
V_28 = F_4 ( V_7 , V_31 ) ;
V_29 = ( V_28 & V_32 ) >> V_33 ;
V_30 = ( V_28 & V_34 ) >> V_35 ;
V_29 = F_9 ( V_29 , 0x3c , 0xfc ) ;
V_30 = F_9 ( V_30 , 0x3c , 0xfc ) ;
V_29 = 0xfc - V_29 ;
V_30 = 0xfc - V_30 ;
V_26 -> V_22 . integer . V_22 [ 0 ] = V_29 ;
V_26 -> V_22 . integer . V_22 [ 1 ] = V_30 ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_25 * V_26 )
{
struct V_27 * V_7 = F_8 ( V_4 ) ;
int V_28 ;
int V_29 ;
int V_30 ;
V_29 = V_26 -> V_22 . integer . V_22 [ 0 ] ;
V_30 = V_26 -> V_22 . integer . V_22 [ 1 ] ;
V_29 = F_9 ( V_29 , 0 , 0xfc - 0x3c ) ;
V_30 = F_9 ( V_30 , 0 , 0xfc - 0x3c ) ;
V_29 = 0xfc - V_29 ;
V_30 = 0xfc - V_30 ;
V_28 = V_29 << V_33 |
V_30 << V_35 ;
F_11 ( V_7 , V_31 , V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_36 * V_37 , int V_38 )
{
struct V_27 * V_7 = V_37 -> V_7 ;
T_2 V_39 = V_40 | V_41 ;
F_2 ( V_7 , V_42 ,
V_39 , V_38 ? V_39 : 0 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 , unsigned int V_43 )
{
struct V_27 * V_7 = V_37 -> V_7 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
T_2 V_46 = 0 ;
V_45 -> V_47 = 0 ;
switch ( V_43 & V_48 ) {
case V_49 :
break;
case V_50 :
V_46 |= V_51 ;
V_45 -> V_47 = 1 ;
break;
default:
return - V_52 ;
}
switch ( V_43 & V_53 ) {
case V_54 :
V_46 |= V_55 ;
break;
case V_56 :
V_46 |= V_55 ;
V_46 |= V_57 ;
break;
case V_58 :
V_46 |= V_59 ;
break;
case V_60 :
V_46 |= V_61 ;
V_46 |= V_62 ;
break;
case V_63 :
V_46 |= V_59 ;
V_46 |= V_57 ;
break;
default:
return - V_52 ;
}
V_45 -> V_43 = V_43 & V_53 ;
switch ( V_43 & V_64 ) {
case V_65 :
break;
case V_66 :
V_46 |= V_67 ;
break;
default:
return - V_52 ;
}
F_11 ( V_7 , V_68 , V_46 ) ;
return 0 ;
}
static int F_15 ( struct V_36 * V_37 ,
int V_69 , unsigned int V_70 , int V_71 )
{
struct V_27 * V_7 = V_37 -> V_7 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
switch ( V_69 ) {
case V_72 :
V_45 -> V_73 = V_70 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_16 ( struct V_27 * V_7 , int V_74 )
{
struct V_44 * V_45 = F_14 ( V_7 ) ;
int V_75 = 0 ;
int V_76 ;
switch ( V_74 ) {
case 8000 :
case 16000 :
V_76 = 32000 ;
break;
case 11025 :
case 22050 :
V_76 = 44100 ;
break;
default:
V_76 = V_74 ;
break;
}
switch ( V_76 / V_74 ) {
case 4 :
V_75 |= V_77 << V_78 ;
break;
case 2 :
V_75 |= V_79 << V_78 ;
break;
case 1 :
V_75 |= V_80 << V_78 ;
break;
default:
return - V_52 ;
}
switch ( V_76 ) {
case 32000 :
V_75 |= V_81 << V_82 ;
break;
case 44100 :
V_75 |= V_83 << V_82 ;
break;
case 48000 :
V_75 |= V_84 << V_82 ;
break;
case 96000 :
V_75 |= V_85 << V_82 ;
break;
default:
F_17 ( V_7 -> V_86 , L_1 ,
V_74 ) ;
return - V_52 ;
}
switch ( V_45 -> V_73 / V_76 ) {
case 256 :
V_75 |= V_87 <<
V_88 ;
break;
case 384 :
V_75 |= V_89 <<
V_88 ;
break;
case 512 :
V_75 |= V_90 <<
V_88 ;
break;
default:
if ( V_45 -> V_47 ) {
V_75 |= V_91 <<
V_88 ;
} else {
F_17 ( V_7 -> V_86 ,
L_2 ) ;
return - V_52 ;
}
}
if ( ( V_75 & V_92 ) == V_91 ) {
T_3 V_93 , V_94 ;
int V_95 ;
int V_96 ;
unsigned int V_97 , V_98 , V_99 ;
if ( V_45 -> V_73 > 17000000 ) {
V_95 = 1 ;
V_97 = V_45 -> V_73 / 2 ;
} else {
V_95 = 0 ;
V_97 = V_45 -> V_73 ;
}
if ( V_76 == 44100 )
V_93 = 180633600 ;
else
V_93 = 196608000 ;
V_94 = F_18 ( V_93 , V_97 ) ;
V_98 = V_93 ;
V_94 *= 2048 ;
F_18 ( V_94 , V_97 ) ;
V_99 = V_94 ;
V_96 = V_98 << V_100 |
V_99 << V_101 ;
F_11 ( V_7 , V_102 , V_96 ) ;
if ( V_95 )
F_2 ( V_7 ,
V_103 ,
V_104 ,
V_104 ) ;
else
F_2 ( V_7 ,
V_103 ,
V_104 ,
0 ) ;
F_2 ( V_7 , V_16 ,
V_105 | V_106 ,
V_105 | V_106 ) ;
F_11 ( V_7 , V_107 , V_75 ) ;
} else {
F_11 ( V_7 , V_107 , V_75 ) ;
F_2 ( V_7 , V_16 ,
V_105 | V_106 ,
0 ) ;
}
return 0 ;
}
static int F_19 ( struct V_108 * V_109 ,
struct V_110 * V_111 ,
struct V_36 * V_112 )
{
struct V_27 * V_7 = V_112 -> V_7 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
int V_113 = F_20 ( V_111 ) ;
int V_114 = 0 ;
int V_115 ;
int V_116 ;
if ( ! V_45 -> V_73 ) {
F_17 ( V_7 -> V_86 , L_3 , V_117 ) ;
return - V_118 ;
}
if ( V_109 -> V_119 == V_120 )
V_115 = V_121 ;
else
V_115 = V_122 ;
F_2 ( V_7 , V_16 , V_115 ,
V_113 == 1 ? 0 : V_115 ) ;
V_116 = F_16 ( V_7 , F_21 ( V_111 ) ) ;
if ( V_116 )
return V_116 ;
switch ( F_22 ( V_111 ) ) {
case V_123 :
if ( V_45 -> V_43 == V_60 )
return - V_52 ;
V_114 |= V_124 << V_125 ;
V_114 |= V_126 <<
V_127 ;
break;
case V_128 :
V_114 |= V_129 << V_125 ;
V_114 |= V_130 <<
V_127 ;
break;
case V_131 :
V_114 |= V_132 << V_125 ;
V_114 |= V_130 <<
V_127 ;
break;
case V_133 :
if ( V_45 -> V_43 == V_60 )
return - V_52 ;
V_114 |= V_134 << V_125 ;
V_114 |= V_130 <<
V_127 ;
break;
default:
return - V_52 ;
}
F_2 ( V_7 , V_68 ,
V_135 | V_136 ,
V_114 ) ;
return 0 ;
}
static int F_23 ( struct V_137 * V_86 )
{
struct V_138 * V_139 = F_24 ( V_86 ) ;
return V_139 -> V_140 ;
}
static int F_25 ( struct V_137 * V_86 )
{
struct V_138 * V_139 = F_24 ( V_86 ) ;
struct V_27 * V_7 = (struct V_27 * ) V_139 -> V_141 ;
int V_28 ;
if ( F_23 ( V_86 ) )
return 0 ;
V_28 = ( 1600 - V_139 -> V_142 / 1000 ) / 50 ;
V_28 = F_9 ( V_28 , 0x0 , 0xf ) ;
V_139 -> V_142 = ( 1600 - V_28 * 50 ) * 1000 ;
F_2 ( V_7 , V_143 ,
V_144 , V_28 ) ;
F_2 ( V_7 , V_16 ,
V_145 ,
V_145 ) ;
F_2 ( V_7 , V_16 ,
V_146 ,
0 ) ;
V_139 -> V_140 = 1 ;
return 0 ;
}
static int F_26 ( struct V_137 * V_86 )
{
struct V_138 * V_139 = F_24 ( V_86 ) ;
struct V_27 * V_7 = (struct V_27 * ) V_139 -> V_141 ;
F_2 ( V_7 , V_16 ,
V_145 ,
0 ) ;
F_2 ( V_7 , V_143 ,
V_144 , 0 ) ;
V_139 -> V_140 = 0 ;
return 0 ;
}
static int F_27 ( struct V_137 * V_86 )
{
struct V_138 * V_139 = F_24 ( V_86 ) ;
return V_139 -> V_142 ;
}
static int F_28 ( struct V_27 * V_7 ,
struct V_147 * V_148 ,
int V_142 )
{
struct V_138 * V_139 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
struct V_149 V_150 = { } ;
V_139 = F_29 ( sizeof( struct V_138 ) , V_151 ) ;
if ( ! V_139 ) {
F_17 ( V_7 -> V_86 , L_4 ) ;
return - V_152 ;
}
V_139 -> V_153 . V_154 = F_30 ( F_31 ( V_7 -> V_86 ) , V_151 ) ;
if ( ! V_139 -> V_153 . V_154 ) {
F_32 ( V_139 ) ;
F_17 ( V_7 -> V_86 , L_5 ) ;
return - V_152 ;
}
V_139 -> V_153 . type = V_155 ;
V_139 -> V_153 . V_156 = V_157 ;
V_139 -> V_153 . V_158 = & V_159 ;
V_139 -> V_153 . V_160 = 1 ;
V_139 -> V_141 = V_7 ;
V_139 -> V_142 = V_142 ;
V_150 . V_86 = V_7 -> V_86 ;
V_150 . V_161 = V_139 ;
V_150 . V_148 = V_148 ;
V_139 -> V_86 = F_33 ( & V_139 -> V_153 , & V_150 ) ;
if ( F_34 ( V_139 -> V_86 ) ) {
int V_116 = F_35 ( V_139 -> V_86 ) ;
F_17 ( V_7 -> V_86 , L_6 ) ;
F_32 ( V_139 -> V_153 . V_154 ) ;
F_32 ( V_139 ) ;
return V_116 ;
}
V_45 -> V_139 = V_139 ;
return 0 ;
}
static int F_36 ( struct V_27 * V_7 )
{
struct V_44 * V_45 = F_14 ( V_7 ) ;
struct V_138 * V_139 = V_45 -> V_139 ;
if ( ! V_139 )
return 0 ;
F_37 ( V_139 -> V_86 ) ;
F_32 ( V_139 -> V_153 . V_154 ) ;
F_32 ( V_139 ) ;
return 0 ;
}
static int F_28 ( struct V_27 * V_7 ,
struct V_147 * V_148 ,
int V_142 )
{
F_17 ( V_7 -> V_86 , L_7 ) ;
return - V_52 ;
}
static int F_36 ( struct V_27 * V_7 )
{
return 0 ;
}
static int F_38 ( struct V_27 * V_7 ,
enum V_162 V_163 )
{
int V_116 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
switch ( V_163 ) {
case V_164 :
case V_165 :
break;
case V_166 :
if ( V_7 -> V_167 . V_168 == V_169 ) {
V_116 = F_39 (
F_40 ( V_45 -> V_170 ) ,
V_45 -> V_170 ) ;
if ( V_116 )
return V_116 ;
F_41 ( 10 ) ;
F_42 ( V_45 -> V_171 , false ) ;
V_116 = F_43 ( V_45 -> V_171 ) ;
if ( V_116 != 0 ) {
F_17 ( V_7 -> V_86 ,
L_8 , V_116 ) ;
F_42 ( V_45 -> V_171 , true ) ;
F_44 ( F_40 ( V_45 -> V_170 ) ,
V_45 -> V_170 ) ;
return V_116 ;
}
}
break;
case V_169 :
F_42 ( V_45 -> V_171 , true ) ;
F_44 ( F_40 ( V_45 -> V_170 ) ,
V_45 -> V_170 ) ;
break;
}
V_7 -> V_167 . V_168 = V_163 ;
return 0 ;
}
static bool F_45 ( struct V_172 * V_86 , unsigned int V_28 )
{
switch ( V_28 ) {
case V_173 :
case V_42 :
case V_174 :
return true ;
}
return false ;
}
static bool F_46 ( struct V_172 * V_86 , unsigned int V_28 )
{
switch ( V_28 ) {
case V_173 :
case V_175 :
case V_107 :
case V_68 :
case V_176 :
case V_42 :
case V_31 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_143 :
case V_181 :
case V_8 :
case V_182 :
case V_183 :
case V_16 :
case V_102 :
case V_103 :
case V_174 :
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
case V_210 :
case V_211 :
case V_212 :
case V_213 :
return true ;
default:
return false ;
}
}
static int F_47 ( struct V_27 * V_7 )
{
F_38 ( V_7 , V_169 ) ;
return 0 ;
}
static int F_48 ( struct V_27 * V_7 )
{
F_38 ( V_7 , V_166 ) ;
return 0 ;
}
static int F_49 ( struct V_27 * V_7 )
{
int V_214 ;
int V_215 ;
int V_216 ;
T_2 V_217 ;
T_2 V_218 ;
int V_219 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
V_215 = F_50 ( V_45 -> V_170 [ V_220 ] . V_221 ) ;
V_216 = F_50 ( V_45 -> V_170 [ V_222 ] . V_221 ) ;
V_214 = F_50 ( V_45 -> V_170 [ V_223 ] . V_221 ) ;
V_215 = V_215 / 1000 ;
V_216 = V_216 / 1000 ;
V_214 = V_214 / 1000 ;
if ( V_215 <= 0 || V_216 <= 0 || V_214 < 0 ) {
F_17 ( V_7 -> V_86 , L_9 ) ;
return - V_52 ;
}
if ( V_215 > 3600 || V_216 > 3600 || V_214 > 1980 ) {
F_17 ( V_7 -> V_86 ,
L_10 ,
V_215 , V_216 , V_214 ) ;
return - V_52 ;
}
V_217 = F_4 ( V_7 , V_16 ) ;
V_217 |= V_121 |
V_122 |
V_224 ;
V_218 = F_4 ( V_7 , V_143 ) ;
if ( V_216 < 3100 && V_215 < 3100 ) {
F_2 ( V_7 , V_103 ,
V_225 ,
V_225 ) ;
V_217 |= V_226 ;
} else if ( V_216 >= 3100 && V_215 >= 3100 ) {
F_2 ( V_7 , V_16 ,
V_226 , 0 ) ;
V_218 |= V_227 ;
V_218 |= V_228 <<
V_229 ;
}
F_11 ( V_7 , V_143 , V_218 ) ;
F_11 ( V_7 , V_16 , V_217 ) ;
F_2 ( V_7 , V_143 ,
V_144 , 0x8 ) ;
if ( V_217 & V_145 )
F_2 ( V_7 , V_16 ,
V_146 ,
0 ) ;
else
F_2 ( V_7 , V_16 ,
V_146 |
V_230 ,
0 ) ;
V_219 = V_215 / 2 ;
if ( V_219 <= V_231 )
V_219 = 0 ;
else if ( V_219 >= V_231 + V_232 *
( V_233 >> V_234 ) )
V_219 = V_233 >> V_234 ;
else
V_219 = ( V_219 - V_231 ) / V_232 ;
F_2 ( V_7 , V_181 ,
V_233 , V_219 << V_234 ) ;
V_219 = V_216 / 2 ;
if ( V_219 <= V_235 )
V_219 = 0 ;
else if ( V_219 >= V_235 +
V_236 * V_237 )
V_219 = V_237 ;
else
V_219 = ( V_219 - V_235 ) /
V_236 ;
F_2 ( V_7 , V_182 ,
V_238 |
V_239 ,
V_219 << V_240 |
V_241 <<
V_242 ) ;
return 0 ;
}
static int F_51 ( struct V_27 * V_7 )
{
struct V_44 * V_45 = F_14 ( V_7 ) ;
int V_116 ;
V_116 = F_28 ( V_7 , & V_243 , V_244 ) ;
if ( V_116 ) {
F_17 ( V_7 -> V_86 ,
L_11 , V_116 ) ;
return V_116 ;
}
V_45 -> V_170 [ V_223 ] . V_245 = V_246 ;
F_52 ( V_7 -> V_86 , L_12 ) ;
return 0 ;
}
static int F_53 ( struct V_27 * V_7 )
{
int V_116 ;
int V_247 ;
int V_248 = 0 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
struct V_249 * V_214 ;
for ( V_247 = 0 ; V_247 < F_40 ( V_45 -> V_170 ) ; V_247 ++ )
V_45 -> V_170 [ V_247 ] . V_245 = V_250 [ V_247 ] ;
if ( V_45 -> V_251 < 0x11 ) {
V_214 = F_54 ( V_7 -> V_86 , L_13 ) ;
if ( F_34 ( V_214 ) ) {
if ( F_35 ( V_214 ) == - V_252 )
return - V_252 ;
} else {
V_248 = 1 ;
F_55 ( V_214 ) ;
}
}
if ( ! V_248 ) {
V_116 = F_51 ( V_7 ) ;
if ( V_116 )
return V_116 ;
}
V_116 = F_56 ( V_7 -> V_86 , F_40 ( V_45 -> V_170 ) ,
V_45 -> V_170 ) ;
if ( V_116 )
goto V_253;
V_116 = F_39 ( F_40 ( V_45 -> V_170 ) ,
V_45 -> V_170 ) ;
if ( V_116 )
goto V_253;
F_41 ( 10 ) ;
return 0 ;
V_253:
if ( ! V_248 )
F_36 ( V_7 ) ;
return V_116 ;
}
static int F_57 ( struct V_27 * V_7 )
{
int V_116 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
V_116 = F_53 ( V_7 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_49 ( V_7 ) ;
if ( V_116 )
goto V_254;
F_2 ( V_7 , V_181 ,
V_255 ,
V_255 ) ;
F_11 ( V_7 , V_184 , 0 ) ;
F_11 ( V_7 , V_176 ,
V_256 << V_257 ) ;
F_11 ( V_7 , V_175 ,
V_258 | V_259 ) ;
F_11 ( V_7 , V_42 ,
V_260 |
V_41 |
V_40 ) ;
F_11 ( V_7 , V_177 , 0x015f ) ;
F_11 ( V_7 , V_180 ,
V_261 |
V_262 ) ;
F_11 ( V_7 , V_8 , 2 ) ;
F_11 ( V_7 , V_186 , 0 ) ;
V_116 = F_38 ( V_7 , V_166 ) ;
if ( V_116 )
goto V_254;
return 0 ;
V_254:
F_44 ( F_40 ( V_45 -> V_170 ) ,
V_45 -> V_170 ) ;
F_36 ( V_7 ) ;
return V_116 ;
}
static int F_58 ( struct V_27 * V_7 )
{
struct V_44 * V_45 = F_14 ( V_7 ) ;
F_38 ( V_7 , V_169 ) ;
F_44 ( F_40 ( V_45 -> V_170 ) ,
V_45 -> V_170 ) ;
F_36 ( V_7 ) ;
return 0 ;
}
static int F_59 ( struct V_44 * V_45 )
{
int V_247 , V_116 , V_263 , V_264 ;
for ( V_247 = 0 ; V_247 < F_40 ( V_265 ) ; V_247 ++ ) {
V_263 = V_265 [ V_247 ] . V_266 ;
V_264 = V_265 [ V_247 ] . V_28 ;
V_116 = F_60 ( V_45 -> V_171 , V_264 , V_263 ) ;
if ( V_116 )
return V_116 ;
}
return 0 ;
}
static int F_61 ( struct V_267 * V_268 ,
const struct V_269 * V_270 )
{
struct V_44 * V_45 ;
int V_116 , V_28 , V_271 ;
V_45 = F_62 ( & V_268 -> V_86 , sizeof( struct V_44 ) ,
V_151 ) ;
if ( ! V_45 )
return - V_152 ;
V_45 -> V_171 = F_63 ( V_268 , & V_272 ) ;
if ( F_34 ( V_45 -> V_171 ) ) {
V_116 = F_35 ( V_45 -> V_171 ) ;
F_17 ( & V_268 -> V_86 , L_14 , V_116 ) ;
return V_116 ;
}
V_45 -> V_273 = F_64 ( & V_268 -> V_86 , NULL ) ;
if ( F_34 ( V_45 -> V_273 ) ) {
V_116 = F_35 ( V_45 -> V_273 ) ;
F_17 ( & V_268 -> V_86 , L_15 , V_116 ) ;
if ( V_116 == - V_274 )
return - V_252 ;
return V_116 ;
}
V_116 = F_65 ( V_45 -> V_273 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_66 ( V_45 -> V_171 , V_173 , & V_28 ) ;
if ( V_116 )
goto V_275;
if ( ( ( V_28 & V_276 ) >> V_277 ) !=
V_278 ) {
F_17 ( & V_268 -> V_86 ,
L_16 , V_28 ) ;
V_116 = - V_279 ;
goto V_275;
}
V_271 = ( V_28 & V_280 ) >> V_281 ;
F_52 ( & V_268 -> V_86 , L_17 , V_271 ) ;
V_45 -> V_251 = V_271 ;
F_67 ( V_268 , V_45 ) ;
V_116 = F_59 ( V_45 ) ;
if ( V_116 )
goto V_275;
V_116 = F_68 ( & V_268 -> V_86 ,
& V_282 , & V_283 , 1 ) ;
if ( V_116 )
goto V_275;
return 0 ;
V_275:
F_69 ( V_45 -> V_273 ) ;
return V_116 ;
}
static int F_70 ( struct V_267 * V_268 )
{
struct V_44 * V_45 = F_71 ( V_268 ) ;
F_72 ( & V_268 -> V_86 ) ;
F_69 ( V_45 -> V_273 ) ;
return 0 ;
}
