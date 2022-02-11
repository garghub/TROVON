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
static bool F_15 ( struct V_60 * V_31 , unsigned int V_61 )
{
switch ( V_61 ) {
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
case V_25 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_11 :
return 1 ;
default:
return 0 ;
}
}
static int F_16 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_2 ;
T_1 V_87 = 0 ;
T_1 V_88 ;
switch ( F_17 ( V_84 ) ) {
case 16 :
V_87 |= V_89 ;
break;
case 20 :
V_87 |= V_90 ;
break;
case 24 :
V_87 |= V_91 ;
break;
case 32 :
V_87 |= V_92 ;
break;
default:
return - V_93 ;
}
switch ( F_18 ( V_84 ) ) {
case 8000 :
V_88 = V_94 ;
break;
case 11025 :
V_88 = V_95 ;
break;
case 12000 :
V_88 = V_96 ;
break;
case 16000 :
V_88 = V_97 ;
break;
case 22050 :
V_88 = V_98 ;
break;
case 32000 :
V_88 = V_99 ;
break;
case 44100 :
V_88 = V_100 ;
break;
case 48000 :
V_88 = V_101 ;
break;
case 88200 :
V_88 = V_102 ;
break;
case 96000 :
V_88 = V_103 ;
break;
default:
return - V_93 ;
}
F_5 ( V_2 , V_104 , V_105 ,
V_87 ) ;
F_2 ( V_2 , V_106 , V_88 ) ;
return 0 ;
}
static int F_19 ( struct V_85 * V_107 , unsigned int V_108 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_109 = 0 , V_87 = 0 ;
switch ( V_108 & V_110 ) {
case V_111 :
V_109 |= V_112 ;
V_33 -> V_113 = true ;
break;
case V_114 :
V_109 |= V_115 ;
V_33 -> V_113 = false ;
break;
default:
return - V_93 ;
}
switch ( V_108 & V_116 ) {
case V_117 :
break;
case V_118 :
V_109 |= V_119 ;
break;
case V_120 :
V_109 |= V_121 ;
break;
case V_122 :
V_109 |= V_119 | V_121 ;
break;
default:
return - V_93 ;
}
switch ( V_108 & V_123 ) {
case V_124 :
V_87 |= V_125 ;
break;
case V_126 :
V_87 |= V_127 ;
break;
case V_128 :
V_87 |= V_129 ;
break;
default:
return - V_93 ;
}
V_109 |= V_130 ;
F_2 ( V_2 , V_131 , V_109 ) ;
F_5 ( V_2 , V_104 , V_132 ,
V_87 ) ;
return 0 ;
}
static int F_20 ( struct V_85 * V_86 , int V_133 )
{
struct V_1 * V_2 = V_86 -> V_2 ;
if ( V_133 ) {
F_5 ( V_2 , V_134 ,
V_51 , V_51 ) ;
F_5 ( V_2 , V_135 ,
V_51 , V_51 ) ;
} else {
F_5 ( V_2 , V_134 ,
V_51 , 0 ) ;
F_5 ( V_2 , V_135 ,
V_51 , 0 ) ;
}
return 0 ;
}
static int F_21 ( struct V_85 * V_107 ,
int V_136 , unsigned int V_137 , int V_138 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
int V_57 = 0 ;
if ( ( V_33 -> V_139 == V_136 ) && ( V_33 -> V_140 == V_137 ) )
return 0 ;
if ( ( ( V_137 < 5000000 ) && ( V_137 != 32768 ) ) || ( V_137 > 54000000 ) ) {
F_22 ( V_107 -> V_31 , L_2 ,
V_137 ) ;
return - V_93 ;
}
switch ( V_136 ) {
case V_141 :
V_33 -> V_142 = false ;
break;
case V_143 :
V_33 -> V_142 = true ;
break;
default:
F_22 ( V_107 -> V_31 , L_3 , V_136 ) ;
return - V_93 ;
}
V_33 -> V_139 = V_136 ;
if ( V_33 -> V_144 ) {
V_137 = F_23 ( V_33 -> V_144 , V_137 ) ;
V_57 = F_24 ( V_33 -> V_144 , V_137 ) ;
if ( V_57 ) {
F_22 ( V_107 -> V_31 , L_4 ,
V_137 ) ;
return V_57 ;
}
}
V_33 -> V_140 = V_137 ;
return 0 ;
}
static int F_25 ( struct V_85 * V_107 , int V_145 ,
int V_146 , unsigned int V_147 , unsigned int V_148 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_149 , V_150 , V_151 ;
T_1 V_152 , V_153 , V_154 ;
T_2 V_155 ;
T_3 V_156 ;
F_2 ( V_2 , V_157 , 0 ) ;
V_149 = 0 ;
if ( ( V_33 -> V_140 == 32768 ) && ( V_146 == V_158 ) ) {
V_150 = V_159 ;
V_151 = V_160 ;
V_155 = 3750000 ;
V_149 |= V_161 ;
} else {
if ( V_33 -> V_140 < 5000000 ) {
goto V_162;
} else if ( V_33 -> V_140 <= 10000000 ) {
V_150 = V_163 ;
V_151 = V_164 ;
} else if ( V_33 -> V_140 <= 20000000 ) {
V_150 = V_159 ;
V_151 = V_160 ;
} else if ( V_33 -> V_140 <= 40000000 ) {
V_150 = V_165 ;
V_151 = V_166 ;
} else if ( V_33 -> V_140 <= 54000000 ) {
V_150 = V_167 ;
V_151 = V_168 ;
} else {
goto V_162;
}
V_155 = ( V_33 -> V_140 / V_151 ) ;
}
V_149 |= V_150 ;
if ( V_146 == V_169 ) {
F_2 ( V_2 , V_157 , V_149 ) ;
return 0 ;
}
if ( ! V_33 -> V_113 && V_33 -> V_170 ) {
V_148 = V_171 ;
V_149 |= V_172 ;
}
if ( V_33 -> V_142 )
V_149 |= V_173 ;
V_154 = V_148 / V_155 ;
V_156 = ( T_3 ) ( V_148 % V_155 ) * 8192ULL ;
F_26 ( V_156 , V_155 ) ;
V_152 = ( V_156 >> V_174 ) & V_175 ;
V_153 = ( V_156 ) & V_175 ;
F_2 ( V_2 , V_176 , V_152 ) ;
F_2 ( V_2 , V_177 , V_153 ) ;
F_2 ( V_2 , V_178 , V_154 ) ;
V_149 |= V_179 ;
F_2 ( V_2 , V_157 , V_149 ) ;
return 0 ;
V_162:
F_22 ( V_107 -> V_31 , L_5 ,
V_33 -> V_140 ) ;
return - V_93 ;
}
static int F_27 ( struct V_1 * V_2 ,
enum V_180 V_181 )
{
struct V_32 * V_33 = F_9 ( V_2 ) ;
int V_57 ;
switch ( V_181 ) {
case V_182 :
case V_183 :
break;
case V_184 :
if ( F_28 ( V_2 ) == V_185 ) {
if ( V_33 -> V_144 ) {
V_57 = F_29 ( V_33 -> V_144 ) ;
if ( V_57 ) {
F_22 ( V_2 -> V_31 ,
L_6 ) ;
return V_57 ;
}
}
F_5 ( V_2 , V_186 ,
V_187 | V_188 ,
V_187 | V_188 ) ;
}
break;
case V_185 :
F_5 ( V_2 , V_186 ,
V_187 | V_188 , 0 ) ;
if ( V_33 -> V_144 )
F_30 ( V_33 -> V_144 ) ;
break;
}
return 0 ;
}
static enum V_189
F_31 ( struct V_1 * V_2 , T_2 V_190 )
{
switch ( V_190 ) {
case 1600 :
return V_191 ;
case 2200 :
return V_192 ;
case 2500 :
return V_193 ;
case 3000 :
return V_194 ;
default:
F_7 ( V_2 -> V_31 , L_7 ) ;
return V_192 ;
}
}
static enum V_195
F_32 ( struct V_1 * V_2 , const char * V_196 )
{
if ( ! strcmp ( V_196 , L_8 ) ) {
return V_197 ;
} else if ( ! strcmp ( V_196 , L_9 ) ) {
return V_198 ;
} else {
F_7 ( V_2 -> V_31 , L_10 ) ;
return V_197 ;
}
}
static enum V_199
F_33 ( struct V_1 * V_2 , const char * V_196 )
{
if ( ! strcmp ( V_196 , L_11 ) ) {
return V_200 ;
} else if ( ! strcmp ( V_196 , L_12 ) ) {
return V_201 ;
} else {
F_7 ( V_2 -> V_31 , L_13 ) ;
return V_200 ;
}
}
static enum V_202
F_34 ( struct V_1 * V_2 , T_2 V_190 )
{
switch ( V_190 ) {
case 1500000 :
return V_203 ;
case 3000000 :
return V_204 ;
default:
F_7 ( V_2 -> V_31 , L_14 ) ;
return V_203 ;
}
}
static struct V_205
* F_35 ( struct V_1 * V_2 )
{
struct V_206 * V_207 = V_2 -> V_31 -> V_208 ;
struct V_205 * V_209 ;
const char * V_210 ;
T_2 V_211 ;
V_209 = F_36 ( V_2 -> V_31 , sizeof( * V_209 ) , V_212 ) ;
if ( ! V_209 ) {
F_7 ( V_2 -> V_31 , L_15 ) ;
return NULL ;
}
if ( F_37 ( V_207 , L_16 , & V_211 ) >= 0 )
V_209 -> V_213 = F_31 ( V_2 , V_211 ) ;
else
V_209 -> V_213 = V_192 ;
if ( F_37 ( V_207 , L_17 , & V_211 ) >= 0 )
V_209 -> V_214 = F_31 ( V_2 , V_211 ) ;
else
V_209 -> V_214 = V_192 ;
if ( ! F_38 ( V_207 , L_18 , & V_210 ) )
V_209 -> V_215 = F_32 ( V_2 , V_210 ) ;
else
V_209 -> V_215 = V_197 ;
if ( ! F_38 ( V_207 , L_19 , & V_210 ) )
V_209 -> V_216 =
F_33 ( V_2 , V_210 ) ;
else
V_209 -> V_216 = V_200 ;
if ( F_37 ( V_207 , L_20 , & V_211 ) >= 0 )
V_209 -> V_217 = F_34 ( V_2 , V_211 ) ;
else
V_209 -> V_217 = V_204 ;
return V_209 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_9 ( V_2 ) ;
F_5 ( V_2 , V_25 ,
V_218 , 0 ) ;
V_33 -> V_52 = true ;
V_33 -> V_170 = true ;
F_5 ( V_2 , V_219 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_221 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_222 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_223 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_40 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_41 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_134 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_135 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_224 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_225 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_226 ,
V_220 , V_220 ) ;
F_5 ( V_2 , V_222 ,
V_227 , V_227 ) ;
F_5 ( V_2 , V_223 ,
V_227 , V_227 ) ;
F_5 ( V_2 , V_228 ,
V_229 , V_229 ) ;
F_5 ( V_2 , V_230 ,
V_229 , V_229 ) ;
F_5 ( V_2 , V_224 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_225 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_226 ,
V_232 , V_232 ) ;
if ( V_2 -> V_31 -> V_208 )
V_33 -> V_209 = F_35 ( V_2 ) ;
else
V_33 -> V_209 = F_40 ( V_2 -> V_31 ) ;
if ( V_33 -> V_209 ) {
struct V_205 * V_209 = V_33 -> V_209 ;
T_1 V_233 = 0 , V_234 = 0 ;
switch ( V_209 -> V_213 ) {
case V_191 :
case V_192 :
case V_193 :
case V_194 :
V_233 |= ( V_209 -> V_213 <<
V_235 ) ;
break;
}
switch ( V_209 -> V_214 ) {
case V_191 :
case V_192 :
case V_193 :
case V_194 :
V_233 |= ( V_209 -> V_214 <<
V_236 ) ;
break;
}
F_5 ( V_2 , V_237 ,
V_238 |
V_239 , V_233 ) ;
switch ( V_209 -> V_215 ) {
case V_198 :
case V_197 :
V_234 |= ( V_209 -> V_215 <<
V_240 ) ;
break;
}
switch ( V_209 -> V_216 ) {
case V_200 :
case V_201 :
V_234 |= ( V_209 -> V_216 <<
V_241 ) ;
break;
}
switch ( V_209 -> V_217 ) {
case V_204 :
case V_203 :
V_234 |= ( V_209 -> V_217 <<
V_242 ) ;
break;
}
F_5 ( V_2 , V_243 ,
V_244 |
V_245 |
V_246 , V_234 ) ;
}
V_33 -> V_144 = F_41 ( V_2 -> V_31 , L_21 ) ;
if ( F_42 ( V_33 -> V_144 ) ) {
if ( F_43 ( V_33 -> V_144 ) != - V_247 )
return F_43 ( V_33 -> V_144 ) ;
else
V_33 -> V_144 = NULL ;
}
return 0 ;
}
static int F_44 ( struct V_248 * V_249 ,
const struct V_250 * V_251 )
{
struct V_32 * V_33 ;
int V_57 ;
V_33 = F_36 ( & V_249 -> V_31 , sizeof( struct V_32 ) ,
V_212 ) ;
if ( ! V_33 )
return - V_252 ;
F_45 ( V_249 , V_33 ) ;
V_33 -> V_253 = F_46 ( V_249 , & V_254 ) ;
if ( F_42 ( V_33 -> V_253 ) ) {
V_57 = F_43 ( V_33 -> V_253 ) ;
F_22 ( & V_249 -> V_31 , L_22 , V_57 ) ;
return V_57 ;
}
V_57 = F_47 ( & V_249 -> V_31 ,
& V_255 , & V_256 , 1 ) ;
if ( V_57 < 0 ) {
F_22 ( & V_249 -> V_31 , L_23 ,
V_57 ) ;
}
return V_57 ;
}
static int F_48 ( struct V_248 * V_257 )
{
F_49 ( & V_257 -> V_31 ) ;
return 0 ;
}
