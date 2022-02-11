static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static T_1 F_4 ( struct V_1 * V_8 , T_1 V_9 )
{
return F_5 ( V_8 -> V_10 + V_9 ) ;
}
static void F_6 ( struct V_1 * V_8 , T_1 V_9 , T_1 V_11 )
{
F_7 ( V_11 , V_8 -> V_10 + V_9 ) ;
}
static void F_8 ( struct V_1 * V_8 , T_1 V_9 , T_1 V_12 )
{
void T_2 * V_13 = V_8 -> V_10 + V_9 ;
T_1 V_14 ;
V_14 = F_5 ( V_13 ) ;
V_14 &= ~ V_12 ;
F_7 ( V_14 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_8 , T_1 V_9 , T_1 V_12 )
{
void T_2 * V_13 = V_8 -> V_10 + V_9 ;
T_1 V_14 ;
V_14 = F_5 ( V_13 ) ;
V_14 |= V_12 ;
F_7 ( V_14 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_8 , T_1 V_9 , T_1 V_11 , T_1 V_15 )
{
void T_2 * V_13 = V_8 -> V_10 + V_9 ;
T_1 V_14 ;
V_14 = F_5 ( V_13 ) ;
V_14 = ( V_14 & ~ V_15 ) | ( V_11 & V_15 ) ;
F_7 ( V_14 , V_13 ) ;
}
static void F_11 ( struct V_1 * V_8 , bool V_16 )
{
F_10 ( V_8 , V_17 , V_16 ? V_18 : V_19 ,
V_20 ) ;
}
static void F_12 ( struct V_1 * V_8 , bool V_21 )
{
struct V_22 V_23 ;
F_13 ( V_24 , 0x14000904 , 0x80000000 ,
0 , 0 , 0 , 0 , 0 , & V_23 ) ;
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_27 ,
V_28 , V_21 ? V_28 : 0 ) ;
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_29 ,
V_30 | V_31 , V_21 ? ( V_30 | V_31 ) : 0 ) ;
}
static void F_15 ( struct V_1 * V_8 , bool V_21 )
{
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_27 ,
V_32 , V_21 ? 0 : V_32 ) ;
}
static void F_16 ( struct V_1 * V_8 )
{
F_9 ( V_8 , V_33 , V_34 ) ;
}
static void F_17 ( struct V_1 * V_8 )
{
F_8 ( V_8 , V_33 , V_34 ) ;
}
static void F_18 ( struct V_1 * V_8 )
{
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_29 ,
V_35 , V_35 ) ;
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_29 ,
V_35 , 0 ) ;
F_8 ( V_8 , V_36 , V_37 ) ;
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_29 ,
V_31 , V_31 ) ;
}
static void F_19 ( struct V_1 * V_8 , bool V_38 )
{
F_10 ( V_8 , V_39 , V_38 ? V_40 : 0 ,
V_40 ) ;
}
static void F_20 ( struct V_1 * V_8 , T_1 V_41 )
{
F_6 ( V_8 , V_42 , V_41 ) ;
}
static void F_21 ( struct V_1 * V_8 , bool V_21 )
{
F_10 ( V_8 , V_43 , V_21 ? V_44 : 0 , V_44 ) ;
}
static void F_22 ( struct V_1 * V_8 , T_3 * V_45 ,
T_3 V_46 )
{
T_1 V_47 = V_48 ;
int V_49 ;
T_3 * V_50 ;
enum V_51 V_52 ;
T_3 V_53 ;
T_3 V_54 ;
T_3 V_55 ;
int V_56 = 0 ;
V_52 = * V_45 ;
V_45 += 1 ;
V_53 = * V_45 ;
V_45 += 1 ;
V_54 = * V_45 ;
V_45 += 1 ;
V_55 = * V_45 ;
V_45 += 1 ;
V_50 = V_45 ;
F_23 ( V_8 -> V_57 ,
L_1 ,
V_52 , V_53 , V_54 , V_55 ) ;
switch ( V_52 ) {
case V_58 :
V_56 = V_59 ;
V_47 = V_48 ;
break;
case V_60 :
V_56 = V_61 ;
V_47 = V_48 ;
break;
case V_62 :
V_56 = V_63 ;
V_47 = V_48 ;
break;
case V_64 :
V_56 = V_65 ;
V_47 = V_66 ;
break;
}
F_8 ( V_8 , V_47 , V_56 ) ;
F_6 ( V_8 , V_67 , V_52 ) ;
F_6 ( V_8 , V_68 , V_53 ) ;
F_6 ( V_8 , V_69 , V_54 ) ;
F_6 ( V_8 , V_70 , V_55 ) ;
for ( V_49 = 0 ; V_49 < V_54 ; V_49 ++ )
F_6 ( V_8 , V_70 , V_50 [ V_49 ] ) ;
F_9 ( V_8 , V_47 , V_56 ) ;
}
static void F_24 ( struct V_1 * V_8 , bool V_21 )
{
F_10 ( V_8 , V_71 , V_21 ? 0 : V_72 ,
V_72 ) ;
}
static void F_25 ( struct V_1 * V_8 )
{
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_27 ,
V_73 | V_74 , 0 ) ;
F_26 ( 2000 , 4000 ) ;
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_27 ,
V_73 | V_74 , V_73 ) ;
}
static void F_27 ( struct V_1 * V_8 )
{
F_14 ( V_8 -> V_25 , V_8 -> V_26 + V_27 ,
V_75 | V_76 ,
V_77 ) ;
}
static void F_28 ( struct V_1 * V_8 )
{
F_8 ( V_8 , V_78 , V_79 ) ;
F_26 ( 2000 , 4000 ) ;
F_9 ( V_8 , V_78 , V_79 ) ;
}
static void F_29 ( struct V_1 * V_8 )
{
F_10 ( V_8 , V_78 , V_80 ,
V_80 | V_81 ) ;
F_26 ( 2000 , 4000 ) ;
F_10 ( V_8 , V_78 , V_81 ,
V_80 | V_81 ) ;
}
static void F_30 ( struct V_1 * V_8 , bool V_82 )
{
F_10 ( V_8 , V_83 , V_82 ? 0 : V_84 ,
V_84 ) ;
}
static void F_31 ( struct V_1 * V_8 ,
bool V_21 )
{
F_10 ( V_8 , V_83 , V_21 ? V_85 : 0 ,
V_85 ) ;
}
static void F_32 ( struct V_1 * V_8 ,
struct V_86 * V_87 )
{
F_8 ( V_8 , V_78 , V_88 ) ;
if ( V_87 -> V_89 & V_90 &&
V_87 -> clock == 74250 &&
V_87 -> V_91 == 1080 )
F_8 ( V_8 , V_39 , V_92 ) ;
else
F_9 ( V_8 , V_39 , V_92 ) ;
}
static void F_33 ( struct V_1 * V_8 ,
enum V_93 V_94 )
{
T_3 V_95 ;
switch ( V_94 ) {
case V_96 :
V_95 = V_97 ;
break;
case V_98 :
V_95 = V_99 ;
break;
case V_100 :
V_95 = V_101 ;
break;
case V_102 :
V_95 = V_103 ;
break;
case V_104 :
V_95 = V_105 ;
break;
default:
V_95 = V_99 ;
break;
}
F_10 ( V_8 , V_106 , V_95 , 0xff ) ;
}
static void F_34 ( struct V_1 * V_8 ,
enum V_107 V_108 )
{
T_1 V_11 ;
switch ( V_108 ) {
case V_109 :
V_11 = V_110 ;
break;
case V_111 :
V_11 = V_112 ;
break;
case V_113 :
case V_114 :
V_11 = V_115 ;
break;
}
F_10 ( V_8 , V_116 , V_11 , V_117 ) ;
}
static void F_35 ( struct V_1 * V_8 ,
enum V_118 V_119 )
{
T_1 V_11 ;
V_11 = F_4 ( V_8 , V_120 ) ;
V_11 &= ~ ( V_121 | V_122 ) ;
switch ( V_119 ) {
case V_123 :
V_11 |= V_124 | V_125 ;
break;
case V_126 :
V_11 |= V_124 | V_127 ;
break;
case V_128 :
default:
V_11 |= V_129 | V_125 ;
break;
case V_130 :
V_11 |= V_129 | V_127 ;
break;
case V_131 :
V_11 |= V_132 | V_125 ;
break;
case V_133 :
V_11 |= V_132 | V_127 ;
break;
}
F_6 ( V_8 , V_120 , V_11 ) ;
}
static void F_36 ( struct V_1 * V_8 , bool V_134 )
{
const T_3 V_15 = V_135 | V_136 | V_137 | V_138 ;
T_3 V_11 ;
F_8 ( V_8 , V_116 , V_139 ) ;
if ( V_134 )
V_11 = V_136 | V_137 ;
else
V_11 = 0 ;
F_10 ( V_8 , V_33 , V_11 , V_15 ) ;
}
static void F_37 ( struct V_1 * V_8 ,
enum V_140 V_141 ,
T_3 V_142 )
{
unsigned int V_143 ;
T_3 V_144 ;
V_143 = F_38 ( 7 , 7 ) | F_38 ( 6 , 6 ) |
F_38 ( 5 , 5 ) | F_38 ( 4 , 4 ) |
F_38 ( 3 , 3 ) | F_38 ( 1 , 2 ) |
F_38 ( 2 , 1 ) | F_38 ( 0 , 0 ) ;
if ( V_142 == 2 ) {
V_144 = F_39 ( 0 ) ;
} else if ( V_142 == 3 || V_142 == 4 ) {
if ( V_142 == 4 &&
( V_141 == V_145 ||
V_141 == V_146 ) )
V_144 = F_39 ( 2 ) | F_39 ( 0 ) ;
else
V_144 = F_39 ( 3 ) | F_39 ( 2 ) ;
} else if ( V_142 == 6 || V_142 == 5 ) {
if ( V_142 == 6 &&
V_141 != V_147 &&
V_141 != V_148 ) {
V_144 = F_39 ( 3 ) | F_39 ( 2 ) |
F_39 ( 1 ) | F_39 ( 0 ) ;
} else {
V_144 = F_39 ( 2 ) | F_39 ( 1 ) |
F_39 ( 0 ) ;
}
} else if ( V_142 == 8 || V_142 == 7 ) {
V_144 = F_39 ( 3 ) | F_39 ( 2 ) |
F_39 ( 1 ) | F_39 ( 0 ) ;
} else {
V_144 = F_39 ( 0 ) ;
}
F_6 ( V_8 , V_149 , V_143 & 0xff ) ;
F_6 ( V_8 , V_150 , ( V_143 >> 8 ) & 0xff ) ;
F_6 ( V_8 , V_151 , ( V_143 >> 16 ) & 0xff ) ;
F_6 ( V_8 , V_152 , V_144 ) ;
}
static void F_40 ( struct V_1 * V_8 ,
enum V_153 V_154 )
{
T_1 V_11 ;
V_11 = F_4 ( V_8 , V_43 ) ;
if ( V_154 == V_155 &&
( V_11 & V_156 ) == V_156 ) {
V_11 &= ~ V_156 ;
} else if ( V_154 == V_157 &&
( V_11 & V_156 ) == 0 ) {
V_11 |= V_156 ;
}
F_6 ( V_8 , V_43 , V_11 ) ;
}
static void F_41 ( struct V_1 * V_8 ,
T_3 * V_158 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ ) {
F_6 ( V_8 , V_159 + V_49 * 4 , V_158 [ V_49 ] ) ;
F_6 ( V_8 , V_160 + V_49 * 4 , V_158 [ V_49 ] ) ;
F_6 ( V_8 , V_161 + V_49 * 4 , V_158 [ V_49 ] ) ;
}
for (; V_49 < 24 ; V_49 ++ ) {
F_6 ( V_8 , V_160 + V_49 * 4 , 0 ) ;
F_6 ( V_8 , V_161 + V_49 * 4 , 0 ) ;
}
}
static void F_42 ( struct V_1 * V_8 )
{
T_1 V_11 ;
V_11 = F_4 ( V_8 , V_162 ) ;
if ( V_11 & V_163 ) {
V_11 &= ~ V_163 ;
F_6 ( V_8 , V_162 , V_11 ) ;
F_26 ( 255 , 512 ) ;
V_11 |= V_163 ;
F_6 ( V_8 , V_162 , V_11 ) ;
}
}
static void F_43 ( struct V_1 * V_8 )
{
T_1 V_11 ;
V_11 = F_4 ( V_8 , V_162 ) ;
V_11 &= ~ V_163 ;
F_6 ( V_8 , V_162 , V_11 ) ;
F_6 ( V_8 , V_164 , 0x00 ) ;
}
static void F_44 ( struct V_1 * V_8 ,
enum V_165 V_166 )
{
T_1 V_11 ;
V_11 = F_4 ( V_8 , V_167 ) ;
V_11 &= V_168 ;
switch ( V_166 ) {
case V_169 :
V_11 |= V_170 ;
break;
case V_171 :
V_11 |= V_172 ;
break;
case V_173 :
V_11 |= V_174 ;
break;
case V_175 :
V_11 |= V_176 ;
break;
case V_177 :
V_11 |= V_178 ;
break;
default:
V_11 |= V_172 ;
break;
}
F_6 ( V_8 , V_167 , V_11 ) ;
}
static unsigned int F_45 ( unsigned int V_179 , unsigned int clock )
{
const struct V_180 * V_181 ;
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < F_46 ( V_182 ) - 1 ; V_49 ++ ) {
if ( clock == V_182 [ V_49 ] . clock )
break;
}
V_181 = V_182 + V_49 ;
switch ( V_179 ) {
case 32000 :
return V_181 -> V_183 [ 0 ] ;
case 44100 :
return V_181 -> V_183 [ 1 ] ;
case 48000 :
return V_181 -> V_183 [ 2 ] ;
case 88200 :
return V_181 -> V_183 [ 1 ] * 2 ;
case 96000 :
return V_181 -> V_183 [ 2 ] * 2 ;
case 176400 :
return V_181 -> V_183 [ 1 ] * 4 ;
case 192000 :
return V_181 -> V_183 [ 2 ] * 4 ;
default:
return ( 128 * V_179 ) / 1000 ;
}
}
static unsigned int F_47 ( unsigned int clock )
{
switch ( clock ) {
case 25175 :
return 25174825 ;
case 74176 :
return 74175824 ;
case 148352 :
return 148351648 ;
case 296703 :
return 296703297 ;
default:
return clock * 1000 ;
}
}
static unsigned int F_48 ( unsigned int V_184 ,
unsigned int V_185 , unsigned int V_183 )
{
return F_49 ( ( V_186 ) F_47 ( V_185 ) * V_183 ,
128 * V_184 ) ;
}
static void F_50 ( struct V_1 * V_8 , unsigned int V_183 ,
unsigned int V_187 )
{
unsigned char V_11 [ V_188 ] ;
int V_49 ;
F_6 ( V_8 , V_189 , 0 ) ;
F_6 ( V_8 , V_189 , 0 ) ;
F_6 ( V_8 , V_189 , 0 ) ;
memset ( V_11 , 0 , sizeof( V_11 ) ) ;
V_11 [ 0 ] = ( V_187 >> 24 ) & 0xff ;
V_11 [ 1 ] = ( V_187 >> 16 ) & 0xff ;
V_11 [ 2 ] = ( V_187 >> 8 ) & 0xff ;
V_11 [ 3 ] = V_187 & 0xff ;
V_11 [ 4 ] = ( V_183 >> 16 ) & 0xff ;
V_11 [ 5 ] = ( V_183 >> 8 ) & 0xff ;
V_11 [ 6 ] = V_183 & 0xff ;
for ( V_49 = 0 ; V_49 < V_188 ; V_49 ++ )
F_6 ( V_8 , V_189 , V_11 [ V_49 ] ) ;
}
static void F_51 ( struct V_1 * V_8 ,
unsigned int V_190 ,
unsigned int clock )
{
unsigned int V_183 , V_187 ;
V_183 = F_45 ( V_190 , clock ) ;
V_187 = F_48 ( V_190 , clock , V_183 ) ;
F_23 ( V_8 -> V_57 , L_2 ,
V_191 , V_190 , clock , V_183 , V_187 ) ;
F_10 ( V_8 , V_192 , V_193 ,
V_194 ) ;
F_50 ( V_8 , V_183 , V_187 ) ;
}
static T_3 F_52 ( enum V_140 V_141 )
{
switch ( V_141 ) {
case V_195 :
case V_196 :
case V_197 :
return 2 ;
case V_198 :
case V_199 :
return 3 ;
case V_200 :
case V_146 :
case V_145 :
return 4 ;
case V_201 :
case V_202 :
case V_203 :
case V_204 :
return 5 ;
case V_147 :
case V_205 :
case V_148 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
return 6 ;
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
return 7 ;
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
return 8 ;
default:
return 2 ;
}
}
static int F_53 ( struct V_1 * V_8 , T_1 clock )
{
unsigned long V_246 ;
int V_247 ;
V_247 = F_54 ( V_8 -> V_248 [ V_249 ] , clock ) ;
if ( V_247 ) {
F_55 ( V_8 -> V_57 , L_3 , clock ,
V_247 ) ;
return V_247 ;
}
V_246 = F_56 ( V_8 -> V_248 [ V_249 ] ) ;
if ( F_57 ( V_246 , 1000 ) != F_57 ( clock , 1000 ) )
F_58 ( V_8 -> V_57 , L_4 , clock ,
V_246 ) ;
else
F_23 ( V_8 -> V_57 , L_4 , clock , V_246 ) ;
F_25 ( V_8 ) ;
F_27 ( V_8 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_8 ,
struct V_86 * V_87 )
{
F_18 ( V_8 ) ;
F_19 ( V_8 , true ) ;
F_20 ( V_8 , 0xff ) ;
F_21 ( V_8 , V_8 -> V_250 ) ;
F_31 ( V_8 , true ) ;
F_32 ( V_8 , V_87 ) ;
}
static int F_60 ( struct V_1 * V_8 , bool V_21 )
{
F_24 ( V_8 , V_21 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_8 , bool V_82 )
{
F_30 ( V_8 , V_82 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_8 )
{
enum V_140 V_251 ;
T_3 V_252 ;
bool V_134 ;
F_33 ( V_8 , V_98 ) ;
F_9 ( V_8 , V_162 , V_253 ) ;
if ( V_8 -> V_254 . V_255 == V_157 &&
V_8 -> V_254 . V_256 == V_257 ) {
F_34 ( V_8 , V_113 ) ;
} else if ( V_8 -> V_254 . V_258 == V_128 ) {
V_8 -> V_254 . V_258 = V_130 ;
}
F_35 ( V_8 , V_8 -> V_254 . V_258 ) ;
F_34 ( V_8 , V_113 ) ;
V_134 = ( ( V_8 -> V_254 . V_255 == V_157 ) &&
( V_8 -> V_254 . V_256 == V_257 ) ) ;
F_36 ( V_8 , V_134 ) ;
if ( V_8 -> V_254 . V_255 == V_157 )
V_251 = V_197 ;
else
V_251 = V_8 -> V_254 . V_259 ;
V_252 = F_52 ( V_251 ) ;
F_37 ( V_8 , V_251 , V_252 ) ;
F_40 ( V_8 , V_8 -> V_254 . V_255 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_8 ,
struct V_86 * V_260 )
{
unsigned int V_190 = V_8 -> V_254 . V_261 . V_190 ;
F_61 ( V_8 , false ) ;
F_43 ( V_8 ) ;
F_8 ( V_8 , V_39 , V_262 ) ;
if ( V_8 -> V_254 . V_255 == V_155 ) {
switch ( V_190 ) {
case 32000 :
case 44100 :
case 48000 :
case 88200 :
case 96000 :
break;
default:
return - V_263 ;
}
F_44 ( V_8 , V_8 -> V_254 . V_264 ) ;
} else {
switch ( V_190 ) {
case 32000 :
case 44100 :
case 48000 :
break;
default:
return - V_263 ;
}
F_44 ( V_8 , V_169 ) ;
}
F_51 ( V_8 , V_190 , V_260 -> clock ) ;
F_42 ( V_8 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_8 ,
struct V_86 * V_260 )
{
F_16 ( V_8 ) ;
F_60 ( V_8 , false ) ;
F_62 ( V_8 ) ;
F_63 ( V_8 , V_260 ) ;
F_41 ( V_8 ,
V_8 -> V_254 . V_261 . V_265 . V_266 ) ;
F_26 ( 50 , 100 ) ;
F_61 ( V_8 , true ) ;
F_60 ( V_8 , true ) ;
F_17 ( V_8 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_8 ,
struct V_86 * V_87 )
{
struct V_267 V_268 ;
T_3 V_45 [ 17 ] ;
T_4 V_269 ;
V_269 = F_66 ( & V_268 , V_87 ) ;
if ( V_269 < 0 ) {
F_55 ( V_8 -> V_57 ,
L_5 , V_269 ) ;
return V_269 ;
}
V_269 = F_67 ( & V_268 , V_45 , sizeof( V_45 ) ) ;
if ( V_269 < 0 ) {
F_55 ( V_8 -> V_57 , L_6 , V_269 ) ;
return V_269 ;
}
F_22 ( V_8 , V_45 , sizeof( V_45 ) ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_8 ,
const char * V_270 ,
const char * V_271 )
{
struct V_272 V_268 ;
T_3 V_45 [ 29 ] ;
T_4 V_269 ;
V_269 = F_69 ( & V_268 , V_270 , V_271 ) ;
if ( V_269 < 0 ) {
F_55 ( V_8 -> V_57 , L_7 ,
V_269 ) ;
return V_269 ;
}
V_269 = F_70 ( & V_268 , V_45 , sizeof( V_45 ) ) ;
if ( V_269 < 0 ) {
F_55 ( V_8 -> V_57 , L_8 , V_269 ) ;
return V_269 ;
}
F_22 ( V_8 , V_45 , sizeof( V_45 ) ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_8 )
{
struct V_273 V_268 ;
T_3 V_45 [ 14 ] ;
T_4 V_269 ;
V_269 = F_72 ( & V_268 ) ;
if ( V_269 < 0 ) {
F_55 ( V_8 -> V_57 , L_9 ,
V_269 ) ;
return V_269 ;
}
V_268 . V_274 = V_275 ;
V_268 . V_276 = V_277 ;
V_268 . V_278 = V_114 ;
V_268 . V_279 = F_52 (
V_8 -> V_254 . V_259 ) ;
V_269 = F_73 ( & V_268 , V_45 , sizeof( V_45 ) ) ;
if ( V_269 < 0 ) {
F_55 ( V_8 -> V_57 , L_10 ,
V_269 ) ;
return V_269 ;
}
F_22 ( V_8 , V_45 , sizeof( V_45 ) ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_8 ,
struct V_86 * V_87 )
{
struct V_280 V_268 ;
T_3 V_45 [ 10 ] ;
T_4 V_269 ;
V_269 = F_75 ( & V_268 , V_87 ) ;
if ( V_269 ) {
F_55 ( V_8 -> V_57 ,
L_11 , V_269 ) ;
return V_269 ;
}
V_269 = F_76 ( & V_268 , V_45 , sizeof( V_45 ) ) ;
if ( V_269 ) {
F_55 ( V_8 -> V_57 , L_12 ,
V_269 ) ;
return V_269 ;
}
F_22 ( V_8 , V_45 , sizeof( V_45 ) ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_8 )
{
struct V_281 * V_254 = & V_8 -> V_254 ;
V_8 -> V_282 = V_283 ;
V_254 -> V_256 = V_284 ;
V_254 -> V_285 = V_109 ;
V_254 -> V_255 = V_155 ;
V_254 -> V_258 = V_131 ;
V_254 -> V_264 = V_169 ;
V_254 -> V_259 = V_197 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_8 )
{
F_60 ( V_8 , true ) ;
V_8 -> V_286 = true ;
}
static void F_79 ( struct V_1 * V_8 )
{
F_60 ( V_8 , false ) ;
V_8 -> V_286 = false ;
}
static int F_80 ( struct V_1 * V_8 ,
struct V_281 * V_287 )
{
if ( ! V_8 -> V_286 ) {
F_55 ( V_8 -> V_57 , L_13 ) ;
return - V_263 ;
}
F_23 ( V_8 -> V_57 , L_14 ,
V_287 -> V_256 , V_287 -> V_255 ,
V_287 -> V_259 , V_287 -> V_261 . V_190 ) ;
memcpy ( & V_8 -> V_254 , V_287 , sizeof( * V_287 ) ) ;
return F_64 ( V_8 , & V_8 -> V_87 ) ;
}
static int F_81 ( struct V_1 * V_8 ,
struct V_86 * V_87 )
{
int V_247 ;
F_11 ( V_8 , true ) ;
F_16 ( V_8 ) ;
F_28 ( V_8 ) ;
F_82 ( V_8 -> V_288 ) ;
V_247 = F_53 ( V_8 ,
V_87 -> clock * 1000 ) ;
if ( V_247 ) {
F_55 ( V_8 -> V_57 , L_15 , V_247 ) ;
return V_247 ;
}
F_59 ( V_8 , V_87 ) ;
F_83 ( V_8 -> V_288 ) ;
F_64 ( V_8 , V_87 ) ;
F_11 ( V_8 , false ) ;
F_17 ( V_8 ) ;
F_29 ( V_8 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_8 ,
struct V_289 * V_290 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < F_46 ( V_291 ) ; V_49 ++ ) {
V_8 -> V_248 [ V_49 ] = F_85 ( V_290 ,
V_291 [ V_49 ] ) ;
if ( F_86 ( V_8 -> V_248 [ V_49 ] ) )
return F_87 ( V_8 -> V_248 [ V_49 ] ) ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_8 )
{
int V_247 ;
V_247 = F_89 ( V_8 -> V_248 [ V_292 ] ) ;
if ( V_247 )
return V_247 ;
V_247 = F_89 ( V_8 -> V_248 [ V_293 ] ) ;
if ( V_247 )
goto V_269;
return 0 ;
V_269:
F_90 ( V_8 -> V_248 [ V_292 ] ) ;
return V_247 ;
}
static void F_91 ( struct V_1 * V_8 )
{
F_90 ( V_8 -> V_248 [ V_292 ] ) ;
F_90 ( V_8 -> V_248 [ V_293 ] ) ;
}
static enum V_294 F_92 ( struct V_5 * V_7 ,
bool V_295 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
return F_93 ( V_8 -> V_296 ) ?
V_297 : V_298 ;
}
static void F_94 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
F_95 ( V_8 -> V_296 , NULL , NULL ) ;
F_96 ( V_7 ) ;
}
static int F_97 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_299 * V_299 ;
int V_247 ;
if ( ! V_8 -> V_300 )
return - V_301 ;
V_299 = F_98 ( V_7 , V_8 -> V_300 ) ;
if ( ! V_299 )
return - V_301 ;
V_8 -> V_250 = ! F_99 ( V_299 ) ;
F_100 ( V_7 , V_299 ) ;
V_247 = F_101 ( V_7 , V_299 ) ;
F_102 ( V_7 , V_299 ) ;
F_103 ( V_299 ) ;
return V_247 ;
}
static int F_104 ( struct V_5 * V_7 ,
struct V_86 * V_87 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
F_23 ( V_8 -> V_57 , L_16 ,
V_87 -> V_302 , V_87 -> V_91 , V_87 -> V_303 ,
! ! ( V_87 -> V_89 & V_90 ) , V_87 -> clock * 1000 ) ;
if ( V_8 -> V_4 . V_304 ) {
struct V_86 V_305 ;
F_105 ( & V_305 , V_87 ) ;
if ( ! F_106 ( V_8 -> V_4 . V_304 , V_87 ,
& V_305 ) )
return V_306 ;
}
if ( V_87 -> clock < 27000 )
return V_307 ;
if ( V_87 -> clock > 297000 )
return V_308 ;
return F_107 ( V_87 , 0x1fff , 0x1fff ) ;
}
static struct V_309 * F_108 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
return V_8 -> V_4 . V_310 ;
}
static void F_109 ( bool V_311 , struct V_312 * V_57 )
{
struct V_1 * V_8 = F_110 ( V_57 ) ;
if ( V_8 && V_8 -> V_4 . V_310 && V_8 -> V_4 . V_310 -> V_57 )
F_111 ( V_8 -> V_4 . V_310 -> V_57 ) ;
}
static int F_112 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
int V_247 ;
V_247 = F_113 ( V_4 -> V_310 -> V_57 , & V_8 -> V_7 ,
& V_313 ,
V_314 ) ;
if ( V_247 ) {
F_55 ( V_8 -> V_57 , L_17 , V_247 ) ;
return V_247 ;
}
F_114 ( & V_8 -> V_7 , & V_315 ) ;
V_8 -> V_7 . V_316 = V_317 ;
V_8 -> V_7 . V_318 = true ;
V_8 -> V_7 . V_319 = false ;
V_247 = F_115 ( & V_8 -> V_7 ,
V_4 -> V_310 ) ;
if ( V_247 ) {
F_55 ( V_8 -> V_57 ,
L_18 , V_247 ) ;
return V_247 ;
}
if ( V_8 -> V_320 ) {
V_247 = F_116 ( V_4 -> V_310 , V_8 -> V_320 ,
V_4 ) ;
if ( V_247 ) {
F_55 ( V_8 -> V_57 ,
L_19 , V_247 ) ;
return V_247 ;
}
}
F_95 ( V_8 -> V_296 , F_109 , V_8 -> V_57 ) ;
return 0 ;
}
static bool F_117 ( struct V_2 * V_4 ,
const struct V_86 * V_87 ,
struct V_86 * V_305 )
{
return true ;
}
static void F_118 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
if ( ! V_8 -> V_321 )
return;
F_82 ( V_8 -> V_288 ) ;
F_90 ( V_8 -> V_248 [ V_322 ] ) ;
F_90 ( V_8 -> V_248 [ V_249 ] ) ;
V_8 -> V_321 = false ;
}
static void F_119 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
if ( ! V_8 -> V_323 )
return;
F_15 ( V_8 , true ) ;
F_12 ( V_8 , false ) ;
V_8 -> V_323 = false ;
}
static void F_120 ( struct V_2 * V_4 ,
struct V_86 * V_87 ,
struct V_86 * V_305 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_23 ( V_8 -> V_57 , L_20 ,
V_305 -> V_324 , V_305 -> V_302 ) ;
F_23 ( V_8 -> V_57 , L_21 ,
V_305 -> V_325 , V_305 -> V_326 ,
V_305 -> V_327 ) ;
F_23 ( V_8 -> V_57 , L_22 ,
V_305 -> V_328 , V_305 -> V_91 ) ;
F_23 ( V_8 -> V_57 , L_23 ,
V_305 -> V_329 , V_305 -> V_330 ,
V_305 -> V_331 ) ;
F_23 ( V_8 -> V_57 , L_24 ,
V_305 -> V_332 , V_305 -> V_89 ) ;
F_105 ( & V_8 -> V_87 , V_305 ) ;
}
static void F_121 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_12 ( V_8 , true ) ;
F_15 ( V_8 , true ) ;
V_8 -> V_323 = true ;
}
static void F_122 ( struct V_1 * V_8 ,
struct V_86 * V_87 )
{
F_71 ( V_8 ) ;
F_65 ( V_8 , V_87 ) ;
F_68 ( V_8 , L_25 , L_26 ) ;
if ( V_87 -> V_89 & V_333 )
F_74 ( V_8 , V_87 ) ;
}
static void F_123 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_81 ( V_8 , & V_8 -> V_87 ) ;
F_89 ( V_8 -> V_248 [ V_249 ] ) ;
F_89 ( V_8 -> V_248 [ V_322 ] ) ;
F_83 ( V_8 -> V_288 ) ;
F_122 ( V_8 , & V_8 -> V_87 ) ;
V_8 -> V_321 = true ;
}
static int F_124 ( struct V_1 * V_8 ,
struct V_334 * V_335 )
{
struct V_312 * V_57 = & V_335 -> V_57 ;
struct V_289 * V_290 = V_57 -> V_336 ;
struct V_289 * V_337 , * V_338 , * V_339 , * V_340 , * V_341 ;
struct V_334 * V_342 ;
struct V_343 * V_343 ;
struct V_344 * V_345 ;
int V_247 ;
V_247 = F_84 ( V_8 , V_290 ) ;
if ( V_247 ) {
F_55 ( V_57 , L_27 , V_247 ) ;
return V_247 ;
}
V_337 = F_125 ( V_290 -> V_346 , NULL ,
L_28 ) ;
if ( ! V_337 ) {
F_55 ( V_57 , L_29 ) ;
return - V_263 ;
}
V_342 = F_126 ( V_337 ) ;
if ( ! V_342 ) {
F_55 ( V_8 -> V_57 , L_30 ,
V_337 -> V_347 ) ;
return - V_348 ;
}
V_8 -> V_296 = & V_342 -> V_57 ;
V_343 = F_127 ( V_290 , L_31 ) ;
V_247 = F_128 ( V_290 , L_31 , 1 ,
& V_8 -> V_26 ) ;
if ( F_86 ( V_343 ) )
V_247 = F_87 ( V_343 ) ;
if ( V_247 ) {
V_247 = F_87 ( V_343 ) ;
F_55 ( V_57 ,
L_32 ,
V_247 ) ;
return V_247 ;
}
V_8 -> V_25 = V_343 ;
V_345 = F_129 ( V_335 , V_349 , 0 ) ;
V_8 -> V_10 = F_130 ( V_57 , V_345 ) ;
if ( F_86 ( V_8 -> V_10 ) )
return F_87 ( V_8 -> V_10 ) ;
V_338 = F_131 ( V_290 , 1 ) ;
if ( ! V_338 ) {
F_55 ( V_57 , L_33 ) ;
return - V_263 ;
}
V_339 = F_132 ( V_338 , L_34 ) ;
if ( ! V_339 ) {
F_55 ( V_57 , L_35 ,
V_338 -> V_347 ) ;
F_133 ( V_338 ) ;
return - V_263 ;
}
F_133 ( V_338 ) ;
V_340 = F_134 ( V_339 ) ;
if ( ! V_340 ) {
F_55 ( V_57 , L_36 ,
V_339 -> V_347 ) ;
F_133 ( V_339 ) ;
return - V_263 ;
}
F_133 ( V_339 ) ;
if ( ! F_135 ( V_340 , L_37 ) ) {
V_8 -> V_320 = F_136 ( V_340 ) ;
if ( ! V_8 -> V_320 ) {
F_55 ( V_57 , L_38 ) ;
F_133 ( V_340 ) ;
return - V_348 ;
}
}
V_341 = F_137 ( V_340 , L_39 , 0 ) ;
if ( ! V_341 ) {
F_55 ( V_57 , L_40 ,
V_340 -> V_347 ) ;
F_133 ( V_340 ) ;
return - V_263 ;
}
F_133 ( V_340 ) ;
V_8 -> V_300 = F_138 ( V_341 ) ;
if ( ! V_8 -> V_300 ) {
F_55 ( V_57 , L_41 ) ;
return - V_263 ;
}
return 0 ;
}
static int F_139 ( struct V_312 * V_57 , void * V_350 ,
struct V_351 * V_352 ,
struct V_353 * V_354 )
{
struct V_1 * V_8 = F_110 ( V_57 ) ;
struct V_281 V_355 ;
unsigned int V_356 = V_354 -> V_357 . V_279 ;
F_23 ( V_8 -> V_57 , L_42 , V_191 ,
V_354 -> V_190 , V_354 -> V_358 , V_356 ) ;
if ( ! V_8 -> V_4 . V_310 )
return - V_301 ;
switch ( V_356 ) {
case 2 :
V_355 . V_259 = V_197 ;
break;
case 4 :
V_355 . V_259 = V_146 ;
break;
case 6 :
V_355 . V_259 = V_147 ;
break;
case 8 :
V_355 . V_259 = V_231 ;
break;
default:
F_55 ( V_8 -> V_57 , L_43 , V_356 ) ;
return - V_263 ;
}
switch ( V_354 -> V_190 ) {
case 32000 :
case 44100 :
case 48000 :
case 88200 :
case 96000 :
case 176400 :
case 192000 :
break;
default:
F_55 ( V_8 -> V_57 , L_44 ,
V_354 -> V_190 ) ;
return - V_263 ;
}
switch ( V_352 -> V_359 ) {
case V_360 :
V_355 . V_256 = V_284 ;
V_355 . V_285 = V_109 ;
V_355 . V_255 = V_155 ;
V_355 . V_258 = V_131 ;
V_355 . V_264 = V_169 ;
break;
default:
F_55 ( V_8 -> V_57 , L_45 , V_191 ,
V_352 -> V_359 ) ;
return - V_263 ;
}
memcpy ( & V_355 . V_261 , V_354 ,
sizeof( V_355 . V_261 ) ) ;
F_80 ( V_8 , & V_355 ) ;
return 0 ;
}
static int F_140 ( struct V_312 * V_57 , void * V_350 )
{
struct V_1 * V_8 = F_110 ( V_57 ) ;
F_23 ( V_57 , L_46 , V_191 ) ;
F_78 ( V_8 ) ;
return 0 ;
}
static void F_141 ( struct V_312 * V_57 , void * V_350 )
{
struct V_1 * V_8 = F_110 ( V_57 ) ;
F_23 ( V_57 , L_46 , V_191 ) ;
F_79 ( V_8 ) ;
}
static int
F_142 ( struct V_312 * V_57 , void * V_350 , bool V_21 )
{
struct V_1 * V_8 = F_110 ( V_57 ) ;
F_23 ( V_57 , L_47 , V_191 , V_21 ) ;
if ( V_21 )
F_16 ( V_8 ) ;
else
F_17 ( V_8 ) ;
return 0 ;
}
static int F_143 ( struct V_312 * V_57 , void * V_350 , T_5 * V_361 , T_6 V_46 )
{
struct V_1 * V_8 = F_110 ( V_57 ) ;
F_23 ( V_57 , L_46 , V_191 ) ;
memcpy ( V_361 , V_8 -> V_7 . V_362 , F_144 ( sizeof( V_8 -> V_7 . V_362 ) , V_46 ) ) ;
return 0 ;
}
static void F_145 ( struct V_312 * V_57 )
{
struct V_363 V_364 = {
. V_365 = & V_366 ,
. V_367 = 2 ,
. V_368 = 1 ,
} ;
struct V_334 * V_335 ;
V_335 = F_146 ( V_57 , V_369 ,
V_370 , & V_364 ,
sizeof( V_364 ) ) ;
if ( F_86 ( V_335 ) )
return;
F_147 ( L_48 , V_369 ) ;
}
static int F_148 ( struct V_334 * V_335 )
{
struct V_1 * V_8 ;
struct V_312 * V_57 = & V_335 -> V_57 ;
int V_247 ;
V_8 = F_149 ( V_57 , sizeof( * V_8 ) , V_371 ) ;
if ( ! V_8 )
return - V_372 ;
V_8 -> V_57 = V_57 ;
V_247 = F_124 ( V_8 , V_335 ) ;
if ( V_247 )
return V_247 ;
V_8 -> V_288 = F_150 ( V_57 , L_49 ) ;
if ( F_86 ( V_8 -> V_288 ) ) {
V_247 = F_87 ( V_8 -> V_288 ) ;
F_55 ( V_57 , L_50 , V_247 ) ;
return V_247 ;
}
F_151 ( V_335 , V_8 ) ;
V_247 = F_77 ( V_8 ) ;
if ( V_247 ) {
F_55 ( V_57 , L_51 ) ;
return V_247 ;
}
F_145 ( V_57 ) ;
V_8 -> V_4 . V_373 = & V_374 ;
V_8 -> V_4 . V_336 = V_335 -> V_57 . V_336 ;
V_247 = F_152 ( & V_8 -> V_4 ) ;
if ( V_247 ) {
F_55 ( V_57 , L_52 , V_247 ) ;
return V_247 ;
}
V_247 = F_88 ( V_8 ) ;
if ( V_247 ) {
F_55 ( V_57 , L_53 , V_247 ) ;
goto V_375;
}
F_23 ( V_57 , L_54 ) ;
return 0 ;
V_375:
F_153 ( & V_8 -> V_4 ) ;
return V_247 ;
}
static int F_154 ( struct V_334 * V_335 )
{
struct V_1 * V_8 = F_155 ( V_335 ) ;
F_153 ( & V_8 -> V_4 ) ;
F_91 ( V_8 ) ;
return 0 ;
}
static int F_156 ( struct V_312 * V_57 )
{
struct V_1 * V_8 = F_110 ( V_57 ) ;
F_91 ( V_8 ) ;
F_23 ( V_57 , L_55 ) ;
return 0 ;
}
static int F_157 ( struct V_312 * V_57 )
{
struct V_1 * V_8 = F_110 ( V_57 ) ;
int V_247 = 0 ;
V_247 = F_88 ( V_8 ) ;
if ( V_247 ) {
F_55 ( V_57 , L_56 ) ;
return V_247 ;
}
F_23 ( V_57 , L_57 ) ;
return 0 ;
}
static int T_7 F_158 ( void )
{
int V_247 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_46 ( V_376 ) ; V_49 ++ ) {
V_247 = F_159 ( V_376 [ V_49 ] ) ;
if ( V_247 < 0 ) {
F_160 ( L_58 ,
V_376 [ V_49 ] -> V_377 . V_324 , V_247 ) ;
goto V_269;
}
}
return 0 ;
V_269:
while ( -- V_49 >= 0 )
F_161 ( V_376 [ V_49 ] ) ;
return V_247 ;
}
static void T_8 F_162 ( void )
{
int V_49 ;
for ( V_49 = F_46 ( V_376 ) - 1 ; V_49 >= 0 ; V_49 -- )
F_161 ( V_376 [ V_49 ] ) ;
}
