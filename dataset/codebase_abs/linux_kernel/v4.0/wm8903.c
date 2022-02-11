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
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
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
case V_75 :
case V_68 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return 1 ;
default:
return 0 ;
}
}
static int F_3 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
F_4 ( V_85 != V_86 ) ;
F_5 ( 4 ) ;
return 0 ;
}
static int F_6 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
struct V_87 * V_88 = F_7 ( V_82 -> V_89 ) ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
switch ( V_85 ) {
case V_86 :
V_91 -> V_92 |= 1 << V_82 -> V_93 ;
break;
case V_94 :
F_9 ( V_88 , V_54 ,
1 << V_82 -> V_93 , 0 ) ;
break;
}
return 0 ;
}
static void F_10 ( struct V_95 * V_89 ,
enum V_96 V_85 , int V_97 )
{
struct V_87 * V_88 = F_7 ( V_89 ) ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
int V_98 = V_99 ;
int V_100 , V_101 ;
if ( V_91 -> V_92 ) {
F_11 ( V_88 -> V_2 , L_1 ,
V_91 -> V_92 ) ;
for ( V_100 = 0 ; V_100 < F_12 ( V_91 -> V_102 ) ; V_100 ++ ) {
if ( ! ( V_91 -> V_92 & ( 1 << V_100 ) ) )
continue;
if ( V_91 -> V_102 [ V_100 ] ) {
F_11 ( V_88 -> V_2 ,
L_2 ,
3 - V_100 , V_91 -> V_102 [ V_100 ] ) ;
F_13 ( V_88 , V_103 + V_100 ,
V_91 -> V_102 [ V_100 ] & 0xff ) ;
} else {
F_11 ( V_88 -> V_2 ,
L_3 , 3 - V_100 ) ;
V_98 = V_104 ;
}
}
if ( V_91 -> V_105 )
V_98 = V_104 ;
F_9 ( V_88 , V_55 ,
V_106 , V_98 ) ;
F_9 ( V_88 , V_54 ,
V_107 , V_91 -> V_92 ) ;
switch ( V_98 ) {
case V_99 :
break;
case V_104 :
F_14 ( 270 ) ;
if ( V_91 -> V_105 )
break;
for ( V_100 = 0 ; V_100 < F_12 ( V_91 -> V_102 ) ; V_100 ++ ) {
if ( ! ( V_91 -> V_92 & ( 1 << V_100 ) ) )
continue;
V_101 = F_15 ( V_88 ,
V_56 + V_100 ) ;
F_11 ( V_88 -> V_2 , L_4 ,
3 - V_100 , V_101 ) ;
V_91 -> V_102 [ V_100 ] = V_101 ;
}
break;
default:
F_16 ( L_5 , V_98 ) ;
break;
}
V_91 -> V_92 = 0 ;
}
}
static int F_17 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_87 * V_88 = F_18 ( V_84 ) ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
T_1 V_3 ;
int V_110 ;
V_3 = F_15 ( V_88 , V_63 ) ;
if ( V_109 -> V_111 . integer . V_111 [ 0 ] ) {
if ( V_91 -> V_105 == 0 ) {
F_11 ( V_88 -> V_2 , L_6 ) ;
F_13 ( V_88 , V_63 , V_3 &
~ ( V_112 | V_113 ) ) ;
}
V_91 -> V_105 ++ ;
}
V_110 = F_19 ( V_84 , V_109 ) ;
if ( ! V_109 -> V_111 . integer . V_111 [ 0 ] ) {
if ( V_91 -> V_105 == 1 ) {
F_11 ( V_88 -> V_2 , L_7 ) ;
F_13 ( V_88 , V_63 , V_3 |
V_112 | V_113 ) ;
}
V_91 -> V_105 -- ;
}
F_11 ( V_88 -> V_2 , L_8 ,
V_91 -> V_105 ) ;
return V_110 ;
}
static int F_20 ( struct V_87 * V_88 )
{
struct V_90 * V_91 = F_8 ( V_88 ) ;
int V_101 , V_100 , V_114 ;
if ( V_91 -> V_115 ) {
V_114 = 1 ;
for ( V_100 = 2 ; V_100 < F_12 ( V_116 ) ; V_100 ++ ) {
if ( abs ( V_116 [ V_100 ] - V_91 -> V_117 ) <
abs ( V_116 [ V_114 ] - V_91 -> V_117 ) )
V_114 = V_100 ;
}
V_101 = V_114 << V_118 ;
} else {
V_114 = 0 ;
V_101 = 0 ;
}
F_11 ( V_88 -> V_2 , L_9 ,
V_114 , V_116 [ V_114 ] ) ;
return F_9 ( V_88 , V_28 ,
V_119 , V_101 ) ;
}
static int F_21 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_87 * V_88 = F_22 ( V_84 ) ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
V_109 -> V_111 . integer . V_111 [ 0 ] = V_91 -> V_115 ;
return 0 ;
}
static int F_23 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_87 * V_88 = F_22 ( V_84 ) ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
int V_115 = V_109 -> V_111 . integer . V_111 [ 0 ] ;
int V_110 = 0 ;
if ( V_115 > 1 )
return - V_120 ;
F_24 ( & V_91 -> V_121 ) ;
if ( V_91 -> V_115 != V_115 ) {
V_91 -> V_115 = V_115 ;
F_20 ( V_88 ) ;
V_110 = 1 ;
}
F_25 ( & V_91 -> V_121 ) ;
return V_110 ;
}
static int F_26 ( struct V_87 * V_88 ,
enum V_122 V_123 )
{
switch ( V_123 ) {
case V_124 :
break;
case V_125 :
F_9 ( V_88 , V_7 ,
V_126 ,
V_127 ) ;
break;
case V_128 :
if ( V_88 -> V_89 . V_129 == V_130 ) {
F_9 ( V_88 , V_6 ,
V_131 | V_132 |
V_133 |
V_134 ,
V_131 |
( 2 << V_135 ) |
V_133 ) ;
F_9 ( V_88 ,
V_53 ,
V_136 ,
V_136 ) ;
F_14 ( 33 ) ;
F_9 ( V_88 , V_16 ,
V_137 | V_138 ,
V_137 | V_138 ) ;
F_9 ( V_88 ,
V_53 ,
V_136 , 0 ) ;
F_9 ( V_88 , V_7 ,
V_139 |
V_140 |
V_141 |
V_142 |
V_126 |
V_143 ,
V_139 |
V_140 |
V_141 |
( 2 << V_144 ) |
V_145 |
V_143 ) ;
F_14 ( 129 ) ;
F_9 ( V_88 , V_16 ,
V_137 | V_138 ,
0 ) ;
F_9 ( V_88 , V_7 ,
V_142 , 0 ) ;
F_9 ( V_88 , V_7 ,
V_126 ,
V_127 ) ;
F_9 ( V_88 , V_6 ,
V_134 | V_131 ,
V_134 ) ;
F_11 ( V_88 -> V_2 , L_7 ) ;
F_9 ( V_88 , V_63 ,
V_112 |
V_113 ,
V_112 |
V_113 ) ;
}
F_9 ( V_88 , V_7 ,
V_126 ,
V_145 ) ;
break;
case V_130 :
F_9 ( V_88 , V_6 ,
V_134 , 0 ) ;
F_9 ( V_88 , V_7 ,
V_142 ,
2 << V_144 ) ;
F_9 ( V_88 , V_7 ,
V_143 , 0 ) ;
F_14 ( 290 ) ;
F_9 ( V_88 , V_7 ,
V_139 | V_140 |
V_141 | V_126 |
V_142 |
V_143 , 0 ) ;
F_9 ( V_88 , V_6 ,
V_133 , 0 ) ;
break;
}
V_88 -> V_89 . V_129 = V_123 ;
return 0 ;
}
static int F_27 ( struct V_146 * V_147 ,
int V_148 , unsigned int V_149 , int V_150 )
{
struct V_87 * V_88 = V_147 -> V_88 ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
V_91 -> V_151 = V_149 ;
return 0 ;
}
static int F_28 ( struct V_146 * V_147 ,
unsigned int V_152 )
{
struct V_87 * V_88 = V_147 -> V_88 ;
T_1 V_153 = F_15 ( V_88 , V_22 ) ;
V_153 &= ~ ( V_154 | V_155 | V_156 |
V_157 | V_158 ) ;
switch ( V_152 & V_159 ) {
case V_160 :
break;
case V_161 :
V_153 |= V_154 ;
break;
case V_162 :
V_153 |= V_154 | V_155 ;
break;
case V_163 :
V_153 |= V_155 ;
break;
default:
return - V_120 ;
}
switch ( V_152 & V_164 ) {
case V_165 :
V_153 |= 0x3 ;
break;
case V_166 :
V_153 |= 0x3 | V_157 ;
break;
case V_167 :
V_153 |= 0x2 ;
break;
case V_168 :
V_153 |= 0x1 ;
break;
case V_169 :
break;
default:
return - V_120 ;
}
switch ( V_152 & V_164 ) {
case V_165 :
case V_166 :
switch ( V_152 & V_170 ) {
case V_171 :
break;
case V_172 :
V_153 |= V_158 ;
break;
default:
return - V_120 ;
}
break;
case V_167 :
case V_168 :
case V_169 :
switch ( V_152 & V_170 ) {
case V_171 :
break;
case V_173 :
V_153 |= V_158 | V_157 ;
break;
case V_172 :
V_153 |= V_158 ;
break;
case V_174 :
V_153 |= V_157 ;
break;
default:
return - V_120 ;
}
break;
default:
return - V_120 ;
}
F_13 ( V_88 , V_22 , V_153 ) ;
return 0 ;
}
static int F_29 ( struct V_146 * V_147 , int V_175 )
{
struct V_87 * V_88 = V_147 -> V_88 ;
T_1 V_3 ;
V_3 = F_15 ( V_88 , V_28 ) ;
if ( V_175 )
V_3 |= V_176 ;
else
V_3 &= ~ V_176 ;
F_13 ( V_88 , V_28 , V_3 ) ;
return 0 ;
}
static int F_30 ( struct V_177 * V_178 ,
struct V_179 * V_180 ,
struct V_146 * V_181 )
{
struct V_87 * V_88 = V_181 -> V_88 ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
int V_117 = F_31 ( V_180 ) ;
int V_182 ;
int V_183 ;
int V_100 ;
int V_184 ;
int V_185 ;
int V_186 ;
int V_187 ;
int V_188 ;
T_1 V_153 = F_15 ( V_88 , V_22 ) ;
T_1 V_189 = F_15 ( V_88 , V_23 ) ;
T_1 V_190 = F_15 ( V_88 , V_24 ) ;
T_1 V_191 = F_15 ( V_88 , V_18 ) ;
T_1 V_192 = F_15 ( V_88 , V_19 ) ;
T_1 V_193 = F_15 ( V_88 , V_28 ) ;
if ( V_117 <= 24000 )
V_193 |= V_194 ;
else
V_193 &= ~ V_194 ;
V_184 = 0 ;
V_186 = abs ( V_195 [ V_184 ] . V_196 - V_117 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_195 ) ; V_100 ++ ) {
V_187 = abs ( V_195 [ V_100 ] . V_196 - V_117 ) ;
if ( V_187 <= V_186 ) {
V_184 = V_100 ;
V_186 = V_187 ;
}
}
F_11 ( V_88 -> V_2 , L_10 , V_195 [ V_184 ] . V_196 ) ;
V_192 &= ~ V_197 ;
V_192 |= V_195 [ V_184 ] . V_111 ;
V_153 &= ~ V_198 ;
V_182 = 2 * V_117 ;
switch ( F_32 ( V_180 ) ) {
case 16 :
V_182 *= 16 ;
break;
case 20 :
V_182 *= 20 ;
V_153 |= 0x4 ;
break;
case 24 :
V_182 *= 24 ;
V_153 |= 0x8 ;
break;
case 32 :
V_182 *= 32 ;
V_153 |= 0xc ;
break;
default:
return - V_120 ;
}
F_11 ( V_88 -> V_2 , L_11 ,
V_91 -> V_151 , V_117 ) ;
V_185 = 0 ;
V_186 = abs ( ( V_91 -> V_151 /
( V_199 [ 0 ] . V_200 *
V_199 [ 0 ] . div ) ) - V_117 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_199 ) ; V_100 ++ ) {
V_187 = abs ( ( V_91 -> V_151 /
( V_199 [ V_100 ] . V_200 *
V_199 [ V_100 ] . div ) ) - V_117 ) ;
if ( V_187 <= V_186 ) {
V_185 = V_100 ;
V_186 = V_187 ;
}
}
if ( V_199 [ V_185 ] . V_200 == 2 ) {
V_191 |= V_201 ;
V_188 = V_91 -> V_151 / 2 ;
} else {
V_191 &= ~ V_201 ;
V_188 = V_91 -> V_151 ;
}
V_192 &= ~ ( V_202 |
V_203 ) ;
V_192 |= V_199 [ V_185 ] . V_196 << V_204 ;
V_192 |= V_199 [ V_185 ] . V_205 << V_206 ;
F_11 ( V_88 -> V_2 , L_12 ,
V_199 [ V_185 ] . V_196 ,
V_199 [ V_185 ] . V_205 ,
V_199 [ V_185 ] . div ) ;
F_11 ( V_88 -> V_2 , L_13 , V_188 ) ;
V_183 = 0 ;
V_186 = ( ( V_188 * 10 ) / V_207 [ 0 ] . V_208 ) - V_182 ;
V_100 = 1 ;
while ( V_100 < F_12 ( V_207 ) ) {
V_187 = ( ( V_188 * 10 ) / V_207 [ V_100 ] . V_208 ) - V_182 ;
if ( V_187 < 0 )
break;
V_183 = V_100 ;
V_186 = V_187 ;
V_100 ++ ;
}
V_189 &= ~ V_209 ;
V_190 &= ~ V_210 ;
F_11 ( V_88 -> V_2 , L_14 ,
V_207 [ V_183 ] . V_208 / 10 , V_182 ,
( V_188 * 10 ) / V_207 [ V_183 ] . V_208 ) ;
V_189 |= V_207 [ V_183 ] . div ;
V_190 |= V_182 / V_117 ;
V_91 -> V_117 = F_31 ( V_180 ) ;
F_20 ( V_88 ) ;
F_13 ( V_88 , V_18 , V_191 ) ;
F_13 ( V_88 , V_19 , V_192 ) ;
F_13 ( V_88 , V_22 , V_153 ) ;
F_13 ( V_88 , V_23 , V_189 ) ;
F_13 ( V_88 , V_24 , V_190 ) ;
F_13 ( V_88 , V_28 , V_193 ) ;
return 0 ;
}
int F_33 ( struct V_87 * V_88 , struct V_211 * V_212 ,
int V_213 , int V_214 )
{
struct V_90 * V_91 = F_8 ( V_88 ) ;
int V_215 = V_216 | V_217 ;
F_11 ( V_88 -> V_2 , L_15 ,
V_213 , V_214 ) ;
V_91 -> V_218 = V_212 ;
V_91 -> V_219 = V_213 ;
V_91 -> V_220 = V_214 ;
if ( V_213 )
V_215 &= ~ V_216 ;
if ( V_214 )
V_215 &= ~ V_217 ;
F_9 ( V_88 , V_76 ,
V_216 | V_217 ,
V_215 ) ;
if ( V_213 || V_214 ) {
F_9 ( V_88 , V_64 ,
V_221 , V_221 ) ;
F_9 ( V_88 , V_8 ,
V_222 , V_222 ) ;
} else {
F_9 ( V_88 , V_8 ,
V_222 , 0 ) ;
}
return 0 ;
}
static T_2 F_34 ( int V_223 , void * V_224 )
{
struct V_90 * V_91 = V_224 ;
int V_225 , V_110 ;
unsigned int V_226 , V_227 , V_228 ;
V_110 = F_35 ( V_91 -> V_229 , V_76 ,
& V_227 ) ;
if ( V_110 != 0 ) {
F_36 ( V_91 -> V_2 , L_16 , V_110 ) ;
return V_230 ;
}
V_110 = F_35 ( V_91 -> V_229 , V_75 , & V_226 ) ;
if ( V_110 != 0 ) {
F_36 ( V_91 -> V_2 , L_17 , V_110 ) ;
return V_230 ;
}
V_226 &= ~ V_227 ;
if ( V_226 & V_231 ) {
F_37 ( V_91 -> V_2 , L_18 ) ;
}
V_225 = V_91 -> V_232 ;
V_110 = F_35 ( V_91 -> V_229 , V_77 ,
& V_228 ) ;
if ( V_110 != 0 ) {
F_36 ( V_91 -> V_2 , L_19 ,
V_110 ) ;
return V_233 ;
}
#ifndef F_38
if ( V_226 & ( V_217 | V_216 ) )
F_39 ( F_40 ( V_91 -> V_2 ) ) ;
#endif
if ( V_226 & V_217 ) {
F_11 ( V_91 -> V_2 , L_20 , V_228 ) ;
V_225 ^= V_91 -> V_220 ;
V_228 ^= V_234 ;
}
if ( V_226 & V_216 ) {
F_11 ( V_91 -> V_2 , L_21 , V_228 ) ;
V_225 ^= V_91 -> V_219 ;
V_228 ^= V_235 ;
F_14 ( V_91 -> V_236 ) ;
}
F_41 ( V_91 -> V_229 , V_77 ,
V_234 | V_235 , V_228 ) ;
F_42 ( V_91 -> V_218 , V_225 ,
V_91 -> V_220 | V_91 -> V_219 ) ;
V_91 -> V_232 = V_225 ;
return V_233 ;
}
static int F_43 ( struct V_87 * V_88 )
{
struct V_90 * V_91 = F_8 ( V_88 ) ;
F_44 ( V_91 -> V_229 ) ;
return 0 ;
}
static inline struct V_90 * F_45 ( struct V_237 * V_238 )
{
return F_46 ( V_238 , struct V_90 , V_237 ) ;
}
static int F_47 ( struct V_237 * V_238 , unsigned V_239 )
{
if ( V_239 >= V_240 )
return - V_120 ;
return 0 ;
}
static int F_48 ( struct V_237 * V_238 , unsigned V_239 )
{
struct V_90 * V_91 = F_45 ( V_238 ) ;
unsigned int V_227 , V_101 ;
int V_110 ;
V_227 = V_241 | V_242 ;
V_101 = ( V_243 << V_244 ) |
V_245 ;
V_110 = F_41 ( V_91 -> V_229 ,
V_70 + V_239 , V_227 , V_101 ) ;
if ( V_110 < 0 )
return V_110 ;
return 0 ;
}
static int F_49 ( struct V_237 * V_238 , unsigned V_239 )
{
struct V_90 * V_91 = F_45 ( V_238 ) ;
unsigned int V_3 ;
F_35 ( V_91 -> V_229 , V_70 + V_239 , & V_3 ) ;
return ( V_3 & V_246 ) >> V_247 ;
}
static int F_50 ( struct V_237 * V_238 ,
unsigned V_239 , int V_111 )
{
struct V_90 * V_91 = F_45 ( V_238 ) ;
unsigned int V_227 , V_101 ;
int V_110 ;
V_227 = V_241 | V_242 | V_246 ;
V_101 = ( V_248 << V_244 ) |
( V_111 << V_249 ) ;
V_110 = F_41 ( V_91 -> V_229 ,
V_70 + V_239 , V_227 , V_101 ) ;
if ( V_110 < 0 )
return V_110 ;
return 0 ;
}
static void F_51 ( struct V_237 * V_238 , unsigned V_239 , int V_111 )
{
struct V_90 * V_91 = F_45 ( V_238 ) ;
F_41 ( V_91 -> V_229 , V_70 + V_239 ,
V_246 ,
! ! V_111 << V_247 ) ;
}
static void F_52 ( struct V_90 * V_91 )
{
struct V_250 * V_251 = V_91 -> V_251 ;
int V_110 ;
V_91 -> V_237 = V_252 ;
V_91 -> V_237 . V_253 = V_240 ;
V_91 -> V_237 . V_2 = V_91 -> V_2 ;
if ( V_251 -> V_254 )
V_91 -> V_237 . V_255 = V_251 -> V_254 ;
else
V_91 -> V_237 . V_255 = - 1 ;
V_110 = F_53 ( & V_91 -> V_237 ) ;
if ( V_110 != 0 )
F_36 ( V_91 -> V_2 , L_22 , V_110 ) ;
}
static void F_54 ( struct V_90 * V_91 )
{
F_55 ( & V_91 -> V_237 ) ;
}
static void F_52 ( struct V_90 * V_91 )
{
}
static void F_54 ( struct V_90 * V_91 )
{
}
static int F_56 ( struct V_256 * V_257 ,
struct V_250 * V_251 )
{
struct V_258 * V_258 = F_57 ( V_257 -> V_223 ) ;
if ( ! V_258 ) {
F_36 ( & V_257 -> V_2 , L_23 ,
V_257 -> V_223 ) ;
return - V_120 ;
}
switch ( F_58 ( V_258 ) ) {
case V_259 :
default:
case V_260 :
V_251 -> V_261 = false ;
break;
case V_262 :
V_251 -> V_261 = true ;
break;
}
return 0 ;
}
static int F_59 ( struct V_256 * V_257 ,
struct V_250 * V_251 )
{
const struct V_263 * V_264 = V_257 -> V_2 . V_265 ;
T_3 V_266 ;
int V_100 ;
if ( F_60 ( V_264 , L_24 , & V_266 ) >= 0 )
V_251 -> V_267 = V_266 ;
if ( F_60 ( V_264 , L_25 , & V_266 ) >= 0 )
V_251 -> V_268 = V_266 ;
if ( F_61 ( V_264 , L_26 , V_251 -> V_269 ,
F_12 ( V_251 -> V_269 ) ) >= 0 ) {
for ( V_100 = 0 ; V_100 < F_12 ( V_251 -> V_269 ) ; V_100 ++ ) {
if ( V_251 -> V_269 [ V_100 ] == 0 ) {
V_251 -> V_269 [ V_100 ] = V_270 ;
} else if ( V_251 -> V_269 [ V_100 ] == 0xffffffff ) {
V_251 -> V_269 [ V_100 ] = 0 ;
} else if ( V_251 -> V_269 [ V_100 ] > 0x7fff ) {
F_36 ( & V_257 -> V_2 , L_27 ,
V_100 , V_251 -> V_269 [ V_100 ] ) ;
return - V_120 ;
}
}
}
return 0 ;
}
static int F_62 ( struct V_256 * V_257 ,
const struct V_271 * V_272 )
{
struct V_250 * V_251 = F_63 ( & V_257 -> V_2 ) ;
struct V_90 * V_91 ;
int V_273 ;
bool V_274 = false ;
unsigned int V_101 , V_275 ;
int V_110 , V_100 ;
V_91 = F_64 ( & V_257 -> V_2 , sizeof( struct V_90 ) ,
V_276 ) ;
if ( V_91 == NULL )
return - V_277 ;
F_65 ( & V_91 -> V_121 ) ;
V_91 -> V_2 = & V_257 -> V_2 ;
V_91 -> V_229 = F_66 ( V_257 , & V_278 ) ;
if ( F_67 ( V_91 -> V_229 ) ) {
V_110 = F_68 ( V_91 -> V_229 ) ;
F_36 ( & V_257 -> V_2 , L_28 ,
V_110 ) ;
return V_110 ;
}
F_69 ( V_257 , V_91 ) ;
if ( V_251 ) {
V_91 -> V_251 = V_251 ;
} else {
V_91 -> V_251 = F_64 ( & V_257 -> V_2 ,
sizeof( struct V_250 ) ,
V_276 ) ;
if ( V_91 -> V_251 == NULL ) {
F_36 ( & V_257 -> V_2 , L_29 ) ;
return - V_277 ;
}
if ( V_257 -> V_223 ) {
V_110 = F_56 ( V_257 , V_91 -> V_251 ) ;
if ( V_110 != 0 )
return V_110 ;
}
if ( V_257 -> V_2 . V_265 ) {
V_110 = F_59 ( V_257 , V_91 -> V_251 ) ;
if ( V_110 != 0 )
return V_110 ;
}
}
V_251 = V_91 -> V_251 ;
V_110 = F_35 ( V_91 -> V_229 , V_4 , & V_101 ) ;
if ( V_110 != 0 ) {
F_36 ( & V_257 -> V_2 , L_30 , V_110 ) ;
goto V_279;
}
if ( V_101 != 0x8903 ) {
F_36 ( & V_257 -> V_2 , L_31 , V_101 ) ;
V_110 = - V_280 ;
goto V_279;
}
V_110 = F_35 ( V_91 -> V_229 , V_5 , & V_101 ) ;
if ( V_110 != 0 ) {
F_36 ( & V_257 -> V_2 , L_32 , V_110 ) ;
goto V_279;
}
F_70 ( & V_257 -> V_2 , L_33 ,
( V_101 & V_281 ) + 'A' ) ;
F_71 ( V_91 -> V_229 , V_4 , 0x8903 ) ;
F_52 ( V_91 ) ;
for ( V_100 = 0 ; V_100 < F_12 ( V_251 -> V_269 ) ; V_100 ++ ) {
if ( ( ! V_251 -> V_269 [ V_100 ] ) ||
( V_251 -> V_269 [ V_100 ] > V_270 ) )
continue;
F_71 ( V_91 -> V_229 , V_70 + V_100 ,
V_251 -> V_269 [ V_100 ] & 0x7fff ) ;
V_101 = ( V_251 -> V_269 [ V_100 ] & V_241 )
>> V_244 ;
switch ( V_101 ) {
case V_282 :
case V_283 :
V_274 = true ;
break;
default:
break;
}
}
F_71 ( V_91 -> V_229 , V_8 ,
V_251 -> V_267 ) ;
if ( V_251 -> V_267 )
F_41 ( V_91 -> V_229 , V_64 ,
V_221 , V_221 ) ;
F_4 ( ! V_274 && ( V_251 -> V_267 & V_222 ) ) ;
V_91 -> V_236 = V_251 -> V_268 ;
if ( V_257 -> V_223 ) {
if ( V_251 -> V_261 ) {
V_273 = V_284 ;
V_275 = V_285 ;
} else {
V_273 = V_286 ;
V_275 = 0 ;
}
F_41 ( V_91 -> V_229 , V_78 ,
V_285 , V_275 ) ;
V_110 = F_72 ( V_257 -> V_223 , NULL , F_34 ,
V_273 | V_287 ,
L_34 , V_91 ) ;
if ( V_110 != 0 ) {
F_36 ( V_91 -> V_2 , L_35 ,
V_110 ) ;
return V_110 ;
}
F_41 ( V_91 -> V_229 ,
V_76 ,
V_288 , 0 ) ;
}
F_41 ( V_91 -> V_229 , V_29 ,
V_289 , V_289 ) ;
F_41 ( V_91 -> V_229 , V_30 ,
V_289 , V_289 ) ;
F_41 ( V_91 -> V_229 , V_25 ,
V_290 , V_290 ) ;
F_41 ( V_91 -> V_229 , V_26 ,
V_290 , V_290 ) ;
F_41 ( V_91 -> V_229 , V_47 ,
V_291 , V_291 ) ;
F_41 ( V_91 -> V_229 , V_48 ,
V_291 , V_291 ) ;
F_41 ( V_91 -> V_229 , V_49 ,
V_292 , V_292 ) ;
F_41 ( V_91 -> V_229 , V_50 ,
V_292 , V_292 ) ;
F_41 ( V_91 -> V_229 , V_51 ,
V_293 , V_293 ) ;
F_41 ( V_91 -> V_229 , V_52 ,
V_293 , V_293 ) ;
F_41 ( V_91 -> V_229 , V_28 ,
V_294 | V_176 ,
V_294 | V_176 ) ;
V_110 = F_73 ( & V_257 -> V_2 ,
& V_295 , & V_296 , 1 ) ;
if ( V_110 != 0 )
goto V_279;
return 0 ;
V_279:
return V_110 ;
}
static int F_74 ( struct V_256 * V_297 )
{
struct V_90 * V_91 = F_75 ( V_297 ) ;
if ( V_297 -> V_223 )
F_76 ( V_297 -> V_223 , V_91 ) ;
F_54 ( V_91 ) ;
F_77 ( & V_297 -> V_2 ) ;
return 0 ;
}
