static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 , V_5 ;
int V_6 = 0 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ;
V_7 ++ ) {
F_2 ( V_2 , V_9 , V_3 ) ;
F_2 ( V_2 , V_9 ,
V_3 | V_10 ) ;
V_4 = F_3 ( V_2 , V_11 ) ;
F_2 ( V_2 , V_9 ,
V_3 | V_12 ) ;
V_5 = F_3 ( V_2 , V_11 ) ;
V_6 += ( ( V_4 << 8 ) | ( V_5 << 16 ) ) ;
}
return V_6 / V_8 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_13 , V_14 , V_15 , V_16 ;
V_13 = F_1 ( V_2 ,
V_17 ) ;
V_14 = F_1 ( V_2 ,
V_18 ) ;
V_15 = - V_13 ;
V_16 = - V_14 ;
V_3 = ( V_15 & V_19 ) >> 8 ;
F_2 ( V_2 , V_20 , V_3 ) ;
V_3 = ( V_15 & V_21 ) >> 16 ;
F_2 ( V_2 , V_22 , V_3 ) ;
V_3 = ( V_16 & V_19 ) >> 8 ;
F_2 ( V_2 , V_23 , V_3 ) ;
V_3 = ( V_16 & V_21 ) >> 16 ;
F_2 ( V_2 , V_24 , V_3 ) ;
F_5 ( V_2 , V_25 ,
V_26 | V_27 ,
V_26 | V_27 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_28 ;
F_5 ( V_2 , V_25 , V_29 ,
V_29 ) ;
do {
V_28 = F_3 ( V_2 , V_25 ) ;
} while ( V_28 & V_29 );
if ( V_28 & V_30 ) {
F_7 ( V_2 -> V_31 ,
L_1 ) ;
F_5 ( V_2 , V_25 ,
V_26 | V_27 ,
0 ) ;
} else {
F_5 ( V_2 , V_25 ,
V_26 | V_27 ,
V_26 | V_27 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_34 , V_35 ;
T_1 V_36 , V_37 ;
T_1 V_38 , V_39 ;
V_34 = F_3 ( V_2 , V_40 ) ;
V_35 = F_3 ( V_2 , V_41 ) ;
V_36 = F_3 ( V_2 , V_42 ) ;
V_37 = F_3 ( V_2 , V_43 ) ;
V_38 = F_3 ( V_2 , V_44 ) ;
V_39 = F_3 ( V_2 , V_45 ) ;
F_5 ( V_2 , V_40 , V_46 ,
V_46 ) ;
F_5 ( V_2 , V_41 , V_46 ,
V_46 ) ;
F_5 ( V_2 , V_42 ,
V_47 |
V_48 ,
V_47 |
V_48 ) ;
F_5 ( V_2 , V_43 ,
V_49 |
V_50 ,
V_49 |
V_50 ) ;
F_5 ( V_2 , V_44 , V_51 ,
V_51 ) ;
F_5 ( V_2 , V_45 , V_51 ,
V_51 ) ;
if ( V_33 -> V_52 )
F_6 ( V_2 ) ;
else
F_4 ( V_2 ) ;
F_2 ( V_2 , V_42 , V_36 ) ;
F_2 ( V_2 , V_43 , V_37 ) ;
F_2 ( V_2 , V_40 , V_34 ) ;
F_2 ( V_2 , V_41 , V_35 ) ;
F_2 ( V_2 , V_44 , V_38 ) ;
F_2 ( V_2 , V_45 , V_39 ) ;
}
static int F_10 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_11 ( V_54 ) ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
int V_57 ;
V_57 = F_12 ( V_54 , V_56 ) ;
if ( ( ! V_57 ) && ( V_33 -> V_58 ) )
F_8 ( V_2 ) ;
return V_57 ;
}
static int F_13 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_11 ( V_54 ) ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
if ( V_56 -> V_59 . integer . V_59 [ 0 ] ||
V_56 -> V_59 . integer . V_59 [ 1 ] ) {
if ( ! V_33 -> V_58 ) {
F_8 ( V_2 ) ;
V_33 -> V_58 = true ;
}
} else {
V_33 -> V_58 = false ;
}
return F_14 ( V_54 , V_56 ) ;
}
static int F_15 ( struct V_60 * V_61 ,
struct V_53 * V_54 , int V_62 )
{
struct V_1 * V_2 = F_16 ( V_61 -> V_63 ) ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_64 , V_65 ;
int V_66 = 0 ;
bool V_67 = false ;
switch ( V_62 ) {
case V_68 :
if ( V_33 -> V_69 )
F_5 ( V_2 , V_70 ,
V_71 ,
V_71 ) ;
F_5 ( V_2 , V_72 ,
V_73 , 0 ) ;
V_64 = F_3 ( V_2 , V_74 ) ;
if ( ! ( V_64 & V_75 ) )
return 0 ;
if ( V_64 & V_76 ) {
F_2 ( V_2 , 0xF0 , 0x8B ) ;
F_2 ( V_2 , 0xF2 , 0x03 ) ;
F_2 ( V_2 , 0xF0 , 0x00 ) ;
}
do {
V_65 = F_3 ( V_2 , V_77 ) ;
if ( V_65 & V_78 ) {
V_67 = true ;
} else {
++ V_66 ;
F_17 ( 50 ) ;
}
} while ( ( V_66 < V_79 ) & ( ! V_67 ) );
if ( ! V_67 )
F_7 ( V_2 -> V_31 , L_2 ) ;
return 0 ;
case V_80 :
V_64 = F_3 ( V_2 , V_74 ) ;
if ( V_64 & V_76 ) {
F_2 ( V_2 , 0xF0 , 0x8B ) ;
F_2 ( V_2 , 0xF2 , 0x01 ) ;
F_2 ( V_2 , 0xF0 , 0x00 ) ;
}
F_5 ( V_2 , V_72 ,
V_73 ,
V_73 ) ;
if ( V_33 -> V_69 )
F_5 ( V_2 , V_70 ,
V_71 , 0 ) ;
return 0 ;
default:
return - V_81 ;
}
}
static bool F_18 ( struct V_82 * V_31 , unsigned int V_83 )
{
switch ( V_83 ) {
case V_84 :
case V_77 :
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
case V_25 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_11 :
return 1 ;
default:
return 0 ;
}
}
static int F_19 ( struct V_102 * V_103 ,
struct V_104 * V_105 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
T_1 V_108 = 0 ;
T_1 V_109 ;
switch ( F_20 ( V_105 ) ) {
case 16 :
V_108 |= V_110 ;
break;
case 20 :
V_108 |= V_111 ;
break;
case 24 :
V_108 |= V_112 ;
break;
case 32 :
V_108 |= V_113 ;
break;
default:
return - V_81 ;
}
switch ( F_21 ( V_105 ) ) {
case 8000 :
V_109 = V_114 ;
break;
case 11025 :
V_109 = V_115 ;
break;
case 12000 :
V_109 = V_116 ;
break;
case 16000 :
V_109 = V_117 ;
break;
case 22050 :
V_109 = V_118 ;
break;
case 32000 :
V_109 = V_119 ;
break;
case 44100 :
V_109 = V_120 ;
break;
case 48000 :
V_109 = V_121 ;
break;
case 88200 :
V_109 = V_122 ;
break;
case 96000 :
V_109 = V_123 ;
break;
default:
return - V_81 ;
}
F_5 ( V_2 , V_124 , V_125 ,
V_108 ) ;
F_2 ( V_2 , V_126 , V_109 ) ;
return 0 ;
}
static int F_22 ( struct V_106 * V_127 , unsigned int V_128 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_129 = 0 , V_108 = 0 ;
switch ( V_128 & V_130 ) {
case V_131 :
V_33 -> V_69 = true ;
break;
case V_132 :
V_33 -> V_69 = false ;
break;
default:
return - V_81 ;
}
switch ( V_128 & V_133 ) {
case V_134 :
break;
case V_135 :
V_129 |= V_136 ;
break;
case V_137 :
V_129 |= V_138 ;
break;
case V_139 :
V_129 |= V_136 | V_138 ;
break;
default:
return - V_81 ;
}
switch ( V_128 & V_140 ) {
case V_141 :
V_108 |= V_142 ;
break;
case V_143 :
V_108 |= V_144 ;
break;
case V_145 :
V_108 |= V_146 ;
break;
default:
return - V_81 ;
}
V_129 |= V_147 ;
F_2 ( V_2 , V_70 , V_129 ) ;
F_5 ( V_2 , V_124 , V_148 ,
V_108 ) ;
return 0 ;
}
static int F_23 ( struct V_106 * V_107 , int V_149 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
if ( V_149 ) {
F_5 ( V_2 , V_150 ,
V_51 , V_51 ) ;
F_5 ( V_2 , V_151 ,
V_51 , V_51 ) ;
} else {
F_5 ( V_2 , V_150 ,
V_51 , 0 ) ;
F_5 ( V_2 , V_151 ,
V_51 , 0 ) ;
}
return 0 ;
}
static int F_24 ( struct V_106 * V_127 ,
int V_152 , unsigned int V_153 , int V_154 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
int V_57 = 0 ;
if ( ( V_33 -> V_155 == V_152 ) && ( V_33 -> V_156 == V_153 ) )
return 0 ;
if ( ( ( V_153 < 5000000 ) && ( V_153 != 32768 ) ) || ( V_153 > 54000000 ) ) {
F_25 ( V_127 -> V_31 , L_3 ,
V_153 ) ;
return - V_81 ;
}
switch ( V_152 ) {
case V_157 :
F_5 ( V_2 , V_74 ,
V_158 , 0 ) ;
break;
case V_159 :
F_5 ( V_2 , V_74 ,
V_158 ,
V_158 ) ;
break;
default:
F_25 ( V_127 -> V_31 , L_4 , V_152 ) ;
return - V_81 ;
}
V_33 -> V_155 = V_152 ;
if ( V_33 -> V_160 ) {
V_153 = F_26 ( V_33 -> V_160 , V_153 ) ;
V_57 = F_27 ( V_33 -> V_160 , V_153 ) ;
if ( V_57 ) {
F_25 ( V_127 -> V_31 , L_5 ,
V_153 ) ;
return V_57 ;
}
}
V_33 -> V_156 = V_153 ;
return 0 ;
}
static int F_28 ( struct V_106 * V_127 , int V_161 ,
int V_162 , unsigned int V_163 , unsigned int V_164 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_64 , V_165 , V_166 ;
T_1 V_167 , V_168 , V_169 ;
T_2 V_170 ;
T_3 V_171 ;
if ( V_33 -> V_156 == 32768 ) {
if ( ! V_33 -> V_69 ) {
F_25 ( V_2 -> V_31 ,
L_6 ) ;
return - V_81 ;
}
V_165 = V_172 ;
V_166 = V_173 ;
V_162 = V_174 ;
V_170 = 3750000 ;
} else {
if ( V_33 -> V_156 < 5000000 ) {
F_25 ( V_2 -> V_31 ,
L_7 ,
V_33 -> V_156 ) ;
return - V_81 ;
} else if ( V_33 -> V_156 <= 9000000 ) {
V_165 = V_175 ;
V_166 = V_176 ;
} else if ( V_33 -> V_156 <= 18000000 ) {
V_165 = V_172 ;
V_166 = V_173 ;
} else if ( V_33 -> V_156 <= 36000000 ) {
V_165 = V_177 ;
V_166 = V_178 ;
} else if ( V_33 -> V_156 <= 54000000 ) {
V_165 = V_179 ;
V_166 = V_180 ;
} else {
F_25 ( V_2 -> V_31 ,
L_8 ,
V_33 -> V_156 ) ;
return - V_81 ;
}
V_170 = ( V_33 -> V_156 / V_166 ) ;
}
V_64 = V_165 ;
switch ( V_162 ) {
case V_181 :
F_5 ( V_2 , V_74 ,
V_182 |
V_183 , V_64 ) ;
return 0 ;
case V_184 :
break;
case V_185 :
V_64 |= V_75 ;
V_164 = V_186 ;
break;
case V_174 :
if ( V_33 -> V_156 != 32768 ) {
F_25 ( V_2 -> V_31 ,
L_9 ) ;
return - V_81 ;
}
V_64 |= V_76 | V_75 ;
V_164 = V_186 ;
break;
default:
F_25 ( V_2 -> V_31 , L_10 ) ;
return - V_81 ;
}
V_169 = V_164 / V_170 ;
V_171 = ( T_3 ) ( V_164 % V_170 ) * 8192ULL ;
F_29 ( V_171 , V_170 ) ;
V_167 = ( V_171 >> V_187 ) & V_188 ;
V_168 = ( V_171 ) & V_188 ;
F_2 ( V_2 , V_189 , V_167 ) ;
F_2 ( V_2 , V_190 , V_168 ) ;
F_2 ( V_2 , V_191 , V_169 ) ;
V_64 |= V_192 ;
F_5 ( V_2 , V_74 ,
V_182 | V_183 ,
V_64 ) ;
if ( V_162 == V_174 ) {
F_2 ( V_2 , 0xF0 , 0x8B ) ;
F_2 ( V_2 , 0xF1 , 0x03 ) ;
F_2 ( V_2 , 0xF1 , 0x01 ) ;
F_2 ( V_2 , 0xF0 , 0x00 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_193 V_194 )
{
struct V_32 * V_33 = F_9 ( V_2 ) ;
int V_57 ;
switch ( V_194 ) {
case V_195 :
break;
case V_196 :
if ( F_31 ( V_2 ) == V_197 ) {
if ( V_33 -> V_160 ) {
V_57 = F_32 ( V_33 -> V_160 ) ;
if ( V_57 ) {
F_25 ( V_2 -> V_31 ,
L_11 ) ;
return V_57 ;
}
}
}
break;
case V_197 :
if ( F_31 ( V_2 ) == V_198 ) {
F_5 ( V_2 , V_199 ,
V_200 | V_201 ,
V_200 | V_201 ) ;
} else {
if ( V_33 -> V_160 )
F_33 ( V_33 -> V_160 ) ;
}
break;
case V_198 :
F_5 ( V_2 , V_199 ,
V_200 | V_201 , 0 ) ;
break;
}
return 0 ;
}
static enum V_202
F_34 ( struct V_1 * V_2 , T_2 V_203 )
{
switch ( V_203 ) {
case 1600 :
return V_204 ;
case 2200 :
return V_205 ;
case 2500 :
return V_206 ;
case 3000 :
return V_207 ;
default:
F_7 ( V_2 -> V_31 , L_12 ) ;
return V_205 ;
}
}
static enum V_208
F_35 ( struct V_1 * V_2 , const char * V_209 )
{
if ( ! strcmp ( V_209 , L_13 ) ) {
return V_210 ;
} else if ( ! strcmp ( V_209 , L_14 ) ) {
return V_211 ;
} else {
F_7 ( V_2 -> V_31 , L_15 ) ;
return V_210 ;
}
}
static enum V_212
F_36 ( struct V_1 * V_2 , const char * V_209 )
{
if ( ! strcmp ( V_209 , L_16 ) ) {
return V_213 ;
} else if ( ! strcmp ( V_209 , L_17 ) ) {
return V_214 ;
} else {
F_7 ( V_2 -> V_31 , L_18 ) ;
return V_213 ;
}
}
static enum V_215
F_37 ( struct V_1 * V_2 , T_2 V_203 )
{
switch ( V_203 ) {
case 1500000 :
return V_216 ;
case 3000000 :
return V_217 ;
default:
F_7 ( V_2 -> V_31 , L_19 ) ;
return V_216 ;
}
}
static struct V_218
* F_38 ( struct V_1 * V_2 )
{
struct V_219 * V_220 = V_2 -> V_31 -> V_221 ;
struct V_218 * V_222 ;
const char * V_223 ;
T_2 V_224 ;
V_222 = F_39 ( V_2 -> V_31 , sizeof( * V_222 ) , V_225 ) ;
if ( ! V_222 ) {
F_7 ( V_2 -> V_31 , L_20 ) ;
return NULL ;
}
if ( F_40 ( V_220 , L_21 , & V_224 ) >= 0 )
V_222 -> V_226 = F_34 ( V_2 , V_224 ) ;
else
V_222 -> V_226 = V_205 ;
if ( F_40 ( V_220 , L_22 , & V_224 ) >= 0 )
V_222 -> V_227 = F_34 ( V_2 , V_224 ) ;
else
V_222 -> V_227 = V_205 ;
if ( ! F_41 ( V_220 , L_23 , & V_223 ) )
V_222 -> V_228 = F_35 ( V_2 , V_223 ) ;
else
V_222 -> V_228 = V_210 ;
if ( ! F_41 ( V_220 , L_24 , & V_223 ) )
V_222 -> V_229 =
F_36 ( V_2 , V_223 ) ;
else
V_222 -> V_229 = V_213 ;
if ( F_40 ( V_220 , L_25 , & V_224 ) >= 0 )
V_222 -> V_230 = F_37 ( V_2 , V_224 ) ;
else
V_222 -> V_230 = V_217 ;
return V_222 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_9 ( V_2 ) ;
F_5 ( V_2 , V_25 ,
V_231 , 0 ) ;
V_33 -> V_52 = true ;
F_5 ( V_2 , V_72 , V_73 ,
V_73 ) ;
F_5 ( V_2 , V_232 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_234 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_235 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_236 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_40 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_41 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_150 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_151 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_237 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_238 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_239 ,
V_233 , V_233 ) ;
F_5 ( V_2 , V_235 ,
V_240 , V_240 ) ;
F_5 ( V_2 , V_236 ,
V_240 , V_240 ) ;
F_5 ( V_2 , V_241 ,
V_242 , V_242 ) ;
F_5 ( V_2 , V_243 ,
V_242 , V_242 ) ;
F_5 ( V_2 , V_237 ,
V_244 , V_244 ) ;
F_5 ( V_2 , V_238 ,
V_244 , V_244 ) ;
F_5 ( V_2 , V_239 ,
V_245 , V_245 ) ;
if ( V_2 -> V_31 -> V_221 )
V_33 -> V_222 = F_38 ( V_2 ) ;
else
V_33 -> V_222 = F_43 ( V_2 -> V_31 ) ;
if ( V_33 -> V_222 ) {
struct V_218 * V_222 = V_33 -> V_222 ;
T_1 V_246 = 0 , V_247 = 0 ;
switch ( V_222 -> V_226 ) {
case V_204 :
case V_205 :
case V_206 :
case V_207 :
V_246 |= ( V_222 -> V_226 <<
V_248 ) ;
break;
}
switch ( V_222 -> V_227 ) {
case V_204 :
case V_205 :
case V_206 :
case V_207 :
V_246 |= ( V_222 -> V_227 <<
V_249 ) ;
break;
}
F_5 ( V_2 , V_250 ,
V_251 |
V_252 , V_246 ) ;
switch ( V_222 -> V_228 ) {
case V_211 :
case V_210 :
V_247 |= ( V_222 -> V_228 <<
V_253 ) ;
break;
}
switch ( V_222 -> V_229 ) {
case V_213 :
case V_214 :
V_247 |= ( V_222 -> V_229 <<
V_254 ) ;
break;
}
switch ( V_222 -> V_230 ) {
case V_217 :
case V_216 :
V_247 |= ( V_222 -> V_230 <<
V_255 ) ;
break;
}
F_5 ( V_2 , V_256 ,
V_257 |
V_258 |
V_259 , V_247 ) ;
}
V_33 -> V_160 = F_44 ( V_2 -> V_31 , L_26 ) ;
if ( F_45 ( V_33 -> V_160 ) ) {
if ( F_46 ( V_33 -> V_160 ) != - V_260 )
return F_46 ( V_33 -> V_160 ) ;
else
V_33 -> V_160 = NULL ;
}
return 0 ;
}
static int F_47 ( struct V_261 * V_262 ,
const struct V_263 * V_264 )
{
struct V_32 * V_33 ;
int V_57 ;
V_33 = F_39 ( & V_262 -> V_31 , sizeof( struct V_32 ) ,
V_225 ) ;
if ( ! V_33 )
return - V_265 ;
F_48 ( V_262 , V_33 ) ;
V_33 -> V_266 = F_49 ( V_262 , & V_267 ) ;
if ( F_45 ( V_33 -> V_266 ) ) {
V_57 = F_46 ( V_33 -> V_266 ) ;
F_25 ( & V_262 -> V_31 , L_27 , V_57 ) ;
return V_57 ;
}
V_57 = F_50 ( & V_262 -> V_31 ,
& V_268 , & V_269 , 1 ) ;
if ( V_57 < 0 ) {
F_25 ( & V_262 -> V_31 , L_28 ,
V_57 ) ;
}
return V_57 ;
}
static int F_51 ( struct V_261 * V_270 )
{
F_52 ( & V_270 -> V_31 ) ;
return 0 ;
}
