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
switch ( V_136 ) {
case V_139 :
if ( ( V_137 == 32768 ) ||
( ( V_137 >= 5000000 ) && ( V_137 <= 54000000 ) ) ) {
V_33 -> V_140 = V_137 ;
return 0 ;
} else {
F_22 ( V_107 -> V_31 , L_2 ,
V_137 ) ;
return - V_93 ;
}
break;
default:
F_22 ( V_107 -> V_31 , L_3 , V_136 ) ;
return - V_93 ;
}
}
static int F_23 ( struct V_85 * V_107 , int V_141 ,
int V_142 , unsigned int V_143 , unsigned int V_144 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_145 , V_146 , V_147 ;
T_1 V_148 , V_149 , V_150 ;
T_2 V_151 ;
T_3 V_152 ;
F_2 ( V_2 , V_153 , 0 ) ;
V_145 = 0 ;
if ( ( V_33 -> V_140 == 32768 ) && ( V_142 == V_154 ) ) {
V_146 = V_155 ;
V_147 = V_156 ;
V_151 = 3750000 ;
V_145 |= V_157 ;
} else {
if ( V_33 -> V_140 < 5000000 ) {
goto V_158;
} else if ( V_33 -> V_140 <= 10000000 ) {
V_146 = V_159 ;
V_147 = V_160 ;
} else if ( V_33 -> V_140 <= 20000000 ) {
V_146 = V_155 ;
V_147 = V_156 ;
} else if ( V_33 -> V_140 <= 40000000 ) {
V_146 = V_161 ;
V_147 = V_162 ;
} else if ( V_33 -> V_140 <= 54000000 ) {
V_146 = V_163 ;
V_147 = V_164 ;
} else {
goto V_158;
}
V_151 = ( V_33 -> V_140 / V_147 ) ;
}
V_145 |= V_146 ;
if ( V_142 == V_165 ) {
F_2 ( V_2 , V_153 , V_145 ) ;
return 0 ;
}
if ( ! V_33 -> V_113 && V_33 -> V_166 ) {
V_144 = V_167 ;
V_145 |= V_168 ;
}
if ( V_33 -> V_169 )
V_145 |= V_170 ;
V_150 = V_144 / V_151 ;
V_152 = ( T_3 ) ( V_144 % V_151 ) * 8192ULL ;
F_24 ( V_152 , V_151 ) ;
V_148 = ( V_152 >> V_171 ) & V_172 ;
V_149 = ( V_152 ) & V_172 ;
F_2 ( V_2 , V_173 , V_148 ) ;
F_2 ( V_2 , V_174 , V_149 ) ;
F_2 ( V_2 , V_175 , V_150 ) ;
V_145 |= V_176 ;
F_2 ( V_2 , V_153 , V_145 ) ;
return 0 ;
V_158:
F_22 ( V_107 -> V_31 , L_4 ,
V_33 -> V_140 ) ;
return - V_93 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_177 V_178 )
{
switch ( V_178 ) {
case V_179 :
case V_180 :
break;
case V_181 :
if ( V_2 -> V_182 . V_183 == V_184 ) {
F_5 ( V_2 , V_185 ,
V_186 | V_187 ,
V_186 | V_187 ) ;
}
break;
case V_184 :
F_5 ( V_2 , V_185 ,
V_186 | V_187 , 0 ) ;
break;
}
V_2 -> V_182 . V_183 = V_178 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_57 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
struct V_188 * V_189 = V_33 -> V_189 ;
V_2 -> V_190 = V_33 -> V_191 ;
V_57 = F_27 ( V_2 , 8 , 8 , V_192 ) ;
if ( V_57 < 0 ) {
F_22 ( V_2 -> V_31 , L_5 , V_57 ) ;
return V_57 ;
}
F_5 ( V_2 , V_25 ,
V_193 , 0 ) ;
V_33 -> V_52 = true ;
V_33 -> V_166 = true ;
F_5 ( V_2 , V_194 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_196 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_197 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_198 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_40 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_41 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_134 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_135 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_199 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_200 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_201 ,
V_195 , V_195 ) ;
F_5 ( V_2 , V_197 ,
V_202 , V_202 ) ;
F_5 ( V_2 , V_198 ,
V_202 , V_202 ) ;
F_5 ( V_2 , V_203 ,
V_204 , V_204 ) ;
F_5 ( V_2 , V_205 ,
V_204 , V_204 ) ;
F_5 ( V_2 , V_199 ,
V_206 , V_206 ) ;
F_5 ( V_2 , V_200 ,
V_206 , V_206 ) ;
F_5 ( V_2 , V_201 ,
V_207 , V_207 ) ;
if ( V_33 -> V_189 ) {
T_1 V_208 = 0 , V_209 = 0 ;
switch ( V_189 -> V_210 ) {
case V_211 :
case V_212 :
case V_213 :
case V_214 :
V_208 |= ( V_189 -> V_210 <<
V_215 ) ;
break;
}
switch ( V_189 -> V_216 ) {
case V_211 :
case V_212 :
case V_213 :
case V_214 :
V_208 |= ( V_189 -> V_216 <<
V_217 ) ;
break;
}
F_5 ( V_2 , V_218 ,
V_219 |
V_220 , V_208 ) ;
switch ( V_189 -> V_221 ) {
case V_222 :
case V_223 :
V_209 |= ( V_189 -> V_221 <<
V_224 ) ;
break;
}
switch ( V_189 -> V_225 ) {
case V_226 :
case V_227 :
V_209 |= ( V_189 -> V_225 <<
V_228 ) ;
break;
}
switch ( V_189 -> V_229 ) {
case V_230 :
case V_231 :
V_209 |= ( V_189 -> V_229 <<
V_232 ) ;
break;
}
F_5 ( V_2 , V_233 ,
V_234 |
V_235 |
V_236 , V_209 ) ;
V_33 -> V_169 = V_189 -> V_237 ;
}
return 0 ;
}
static int F_28 ( struct V_238 * V_239 ,
const struct V_240 * V_241 )
{
struct V_32 * V_33 ;
struct V_188 * V_189 = F_29 ( & V_239 -> V_31 ) ;
int V_57 ;
V_33 = F_30 ( & V_239 -> V_31 , sizeof( struct V_32 ) ,
V_242 ) ;
if ( ! V_33 )
return - V_243 ;
if ( V_189 )
V_33 -> V_189 = V_189 ;
F_31 ( V_239 , V_33 ) ;
V_33 -> V_191 = F_32 ( V_239 , & V_244 ) ;
if ( F_33 ( V_33 -> V_191 ) ) {
V_57 = F_34 ( V_33 -> V_191 ) ;
F_22 ( & V_239 -> V_31 , L_6 , V_57 ) ;
return V_57 ;
}
V_57 = F_35 ( & V_239 -> V_31 ,
& V_245 , & V_246 , 1 ) ;
if ( V_57 < 0 ) {
F_22 ( & V_239 -> V_31 , L_7 ,
V_57 ) ;
}
return V_57 ;
}
static int F_36 ( struct V_238 * V_247 )
{
F_37 ( & V_247 -> V_31 ) ;
return 0 ;
}
