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
case V_89 :
V_87 |= V_90 ;
break;
case V_91 :
V_87 |= V_92 ;
break;
case V_93 :
V_87 |= V_94 ;
break;
case V_95 :
V_87 |= V_96 ;
break;
default:
return - V_97 ;
}
switch ( F_18 ( V_84 ) ) {
case 8000 :
V_88 = V_98 ;
break;
case 11025 :
V_88 = V_99 ;
break;
case 12000 :
V_88 = V_100 ;
break;
case 16000 :
V_88 = V_101 ;
break;
case 22050 :
V_88 = V_102 ;
break;
case 32000 :
V_88 = V_103 ;
break;
case 44100 :
V_88 = V_104 ;
break;
case 48000 :
V_88 = V_105 ;
break;
case 88200 :
V_88 = V_106 ;
break;
case 96000 :
V_88 = V_107 ;
break;
default:
return - V_97 ;
}
F_5 ( V_2 , V_108 , V_109 ,
V_87 ) ;
F_2 ( V_2 , V_110 , V_88 ) ;
return 0 ;
}
static int F_19 ( struct V_85 * V_111 , unsigned int V_112 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_113 = 0 , V_87 = 0 ;
switch ( V_112 & V_114 ) {
case V_115 :
V_113 |= V_116 ;
V_33 -> V_117 = true ;
break;
case V_118 :
V_113 |= V_119 ;
V_33 -> V_117 = false ;
break;
default:
return - V_97 ;
}
switch ( V_112 & V_120 ) {
case V_121 :
break;
case V_122 :
V_113 |= V_123 ;
break;
case V_124 :
V_113 |= V_125 ;
break;
case V_126 :
V_113 |= V_123 | V_125 ;
break;
default:
return - V_97 ;
}
switch ( V_112 & V_127 ) {
case V_128 :
V_87 |= V_129 ;
break;
case V_130 :
V_87 |= V_131 ;
break;
case V_132 :
V_87 |= V_133 ;
break;
default:
return - V_97 ;
}
V_113 |= V_134 ;
F_2 ( V_2 , V_135 , V_113 ) ;
F_5 ( V_2 , V_108 , V_136 ,
V_87 ) ;
return 0 ;
}
static int F_20 ( struct V_85 * V_86 , int V_137 )
{
struct V_1 * V_2 = V_86 -> V_2 ;
if ( V_137 ) {
F_5 ( V_2 , V_138 ,
V_51 , V_51 ) ;
F_5 ( V_2 , V_139 ,
V_51 , V_51 ) ;
} else {
F_5 ( V_2 , V_138 ,
V_51 , 0 ) ;
F_5 ( V_2 , V_139 ,
V_51 , 0 ) ;
}
return 0 ;
}
static int F_21 ( struct V_85 * V_111 ,
int V_140 , unsigned int V_141 , int V_142 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
switch ( V_140 ) {
case V_143 :
if ( ( V_141 == 32768 ) ||
( ( V_141 >= 5000000 ) && ( V_141 <= 54000000 ) ) ) {
V_33 -> V_144 = V_141 ;
return 0 ;
} else {
F_22 ( V_111 -> V_31 , L_2 ,
V_141 ) ;
return - V_97 ;
}
break;
default:
F_22 ( V_111 -> V_31 , L_3 , V_140 ) ;
return - V_97 ;
}
}
static int F_23 ( struct V_85 * V_111 , int V_145 ,
int V_146 , unsigned int V_147 , unsigned int V_148 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_149 , V_150 , V_151 ;
T_1 V_152 , V_153 , V_154 ;
T_2 V_155 ;
T_3 V_156 ;
F_2 ( V_2 , V_157 , 0 ) ;
V_149 = 0 ;
if ( ( V_33 -> V_144 == 32768 ) && ( V_146 == V_158 ) ) {
V_150 = V_159 ;
V_151 = V_160 ;
V_155 = 3750000 ;
V_149 |= V_161 ;
} else {
if ( V_33 -> V_144 < 5000000 ) {
goto V_162;
} else if ( V_33 -> V_144 <= 10000000 ) {
V_150 = V_163 ;
V_151 = V_164 ;
} else if ( V_33 -> V_144 <= 20000000 ) {
V_150 = V_159 ;
V_151 = V_160 ;
} else if ( V_33 -> V_144 <= 40000000 ) {
V_150 = V_165 ;
V_151 = V_166 ;
} else if ( V_33 -> V_144 <= 54000000 ) {
V_150 = V_167 ;
V_151 = V_168 ;
} else {
goto V_162;
}
V_155 = ( V_33 -> V_144 / V_151 ) ;
}
V_149 |= V_150 ;
if ( V_146 == V_169 ) {
F_2 ( V_2 , V_157 , V_149 ) ;
return 0 ;
}
if ( ! V_33 -> V_117 && V_33 -> V_170 ) {
V_148 = V_171 ;
V_149 |= V_172 ;
}
if ( V_33 -> V_173 )
V_149 |= V_174 ;
V_154 = V_148 / V_155 ;
V_156 = ( T_3 ) ( V_148 % V_155 ) * 8192ULL ;
F_24 ( V_156 , V_155 ) ;
V_152 = ( V_156 >> V_175 ) & V_176 ;
V_153 = ( V_156 ) & V_176 ;
F_2 ( V_2 , V_177 , V_152 ) ;
F_2 ( V_2 , V_178 , V_153 ) ;
F_2 ( V_2 , V_179 , V_154 ) ;
V_149 |= V_180 ;
F_2 ( V_2 , V_157 , V_149 ) ;
return 0 ;
V_162:
F_22 ( V_111 -> V_31 , L_4 ,
V_33 -> V_144 ) ;
return - V_97 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_181 V_182 )
{
switch ( V_182 ) {
case V_183 :
case V_184 :
break;
case V_185 :
if ( V_2 -> V_186 . V_187 == V_188 ) {
F_5 ( V_2 , V_189 ,
V_190 | V_191 ,
V_190 | V_191 ) ;
}
break;
case V_188 :
F_5 ( V_2 , V_189 ,
V_190 | V_191 , 0 ) ;
break;
}
V_2 -> V_186 . V_187 = V_182 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_57 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
struct V_192 * V_193 = V_33 -> V_193 ;
V_2 -> V_194 = V_33 -> V_195 ;
V_57 = F_27 ( V_2 , 8 , 8 , V_196 ) ;
if ( V_57 < 0 ) {
F_22 ( V_2 -> V_31 , L_5 , V_57 ) ;
return V_57 ;
}
F_5 ( V_2 , V_25 ,
V_197 , 0 ) ;
V_33 -> V_52 = true ;
V_33 -> V_170 = true ;
F_5 ( V_2 , V_198 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_200 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_201 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_202 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_40 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_41 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_138 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_139 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_203 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_204 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_205 ,
V_199 , V_199 ) ;
F_5 ( V_2 , V_201 ,
V_206 , V_206 ) ;
F_5 ( V_2 , V_202 ,
V_206 , V_206 ) ;
F_5 ( V_2 , V_207 ,
V_208 , V_208 ) ;
F_5 ( V_2 , V_209 ,
V_208 , V_208 ) ;
F_5 ( V_2 , V_203 ,
V_210 , V_210 ) ;
F_5 ( V_2 , V_204 ,
V_210 , V_210 ) ;
F_5 ( V_2 , V_205 ,
V_211 , V_211 ) ;
if ( V_33 -> V_193 ) {
T_1 V_212 = 0 , V_213 = 0 ;
switch ( V_193 -> V_214 ) {
case V_215 :
case V_216 :
case V_217 :
case V_218 :
V_212 |= ( V_193 -> V_214 <<
V_219 ) ;
break;
}
switch ( V_193 -> V_220 ) {
case V_215 :
case V_216 :
case V_217 :
case V_218 :
V_212 |= ( V_193 -> V_220 <<
V_221 ) ;
break;
}
F_5 ( V_2 , V_222 ,
V_223 |
V_224 , V_212 ) ;
switch ( V_193 -> V_225 ) {
case V_226 :
case V_227 :
V_213 |= ( V_193 -> V_225 <<
V_228 ) ;
break;
}
switch ( V_193 -> V_229 ) {
case V_230 :
case V_231 :
V_213 |= ( V_193 -> V_229 <<
V_232 ) ;
break;
}
switch ( V_193 -> V_233 ) {
case V_234 :
case V_235 :
V_213 |= ( V_193 -> V_233 <<
V_236 ) ;
break;
}
F_5 ( V_2 , V_237 ,
V_238 |
V_239 |
V_240 , V_213 ) ;
V_33 -> V_173 = V_193 -> V_241 ;
}
return 0 ;
}
static int F_28 ( struct V_242 * V_243 ,
const struct V_244 * V_245 )
{
struct V_32 * V_33 ;
struct V_192 * V_193 = F_29 ( & V_243 -> V_31 ) ;
int V_57 ;
V_33 = F_30 ( & V_243 -> V_31 , sizeof( struct V_32 ) ,
V_246 ) ;
if ( ! V_33 )
return - V_247 ;
if ( V_193 )
V_33 -> V_193 = V_193 ;
F_31 ( V_243 , V_33 ) ;
V_33 -> V_195 = F_32 ( V_243 , & V_248 ) ;
if ( F_33 ( V_33 -> V_195 ) ) {
V_57 = F_34 ( V_33 -> V_195 ) ;
F_22 ( & V_243 -> V_31 , L_6 , V_57 ) ;
return V_57 ;
}
V_57 = F_35 ( & V_243 -> V_31 ,
& V_249 , & V_250 , 1 ) ;
if ( V_57 < 0 ) {
F_22 ( & V_243 -> V_31 , L_7 ,
V_57 ) ;
}
return V_57 ;
}
static int F_36 ( struct V_242 * V_251 )
{
F_37 ( & V_251 -> V_31 ) ;
return 0 ;
}
