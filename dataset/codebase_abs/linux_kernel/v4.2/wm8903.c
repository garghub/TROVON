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
if ( F_27 ( V_88 ) == V_129 ) {
F_9 ( V_88 , V_6 ,
V_130 | V_131 |
V_132 |
V_133 ,
V_130 |
( 2 << V_134 ) |
V_132 ) ;
F_9 ( V_88 ,
V_53 ,
V_135 ,
V_135 ) ;
F_14 ( 33 ) ;
F_9 ( V_88 , V_16 ,
V_136 | V_137 ,
V_136 | V_137 ) ;
F_9 ( V_88 ,
V_53 ,
V_135 , 0 ) ;
F_9 ( V_88 , V_7 ,
V_138 |
V_139 |
V_140 |
V_141 |
V_126 |
V_142 ,
V_138 |
V_139 |
V_140 |
( 2 << V_143 ) |
V_144 |
V_142 ) ;
F_14 ( 129 ) ;
F_9 ( V_88 , V_16 ,
V_136 | V_137 ,
0 ) ;
F_9 ( V_88 , V_7 ,
V_141 , 0 ) ;
F_9 ( V_88 , V_7 ,
V_126 ,
V_127 ) ;
F_9 ( V_88 , V_6 ,
V_133 | V_130 ,
V_133 ) ;
F_11 ( V_88 -> V_2 , L_7 ) ;
F_9 ( V_88 , V_63 ,
V_112 |
V_113 ,
V_112 |
V_113 ) ;
}
F_9 ( V_88 , V_7 ,
V_126 ,
V_144 ) ;
break;
case V_129 :
F_9 ( V_88 , V_6 ,
V_133 , 0 ) ;
F_9 ( V_88 , V_7 ,
V_141 ,
2 << V_143 ) ;
F_9 ( V_88 , V_7 ,
V_142 , 0 ) ;
F_14 ( 290 ) ;
F_9 ( V_88 , V_7 ,
V_138 | V_139 |
V_140 | V_126 |
V_141 |
V_142 , 0 ) ;
F_9 ( V_88 , V_6 ,
V_132 , 0 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_145 * V_146 ,
int V_147 , unsigned int V_148 , int V_149 )
{
struct V_87 * V_88 = V_146 -> V_88 ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
V_91 -> V_150 = V_148 ;
return 0 ;
}
static int F_29 ( struct V_145 * V_146 ,
unsigned int V_151 )
{
struct V_87 * V_88 = V_146 -> V_88 ;
T_1 V_152 = F_15 ( V_88 , V_22 ) ;
V_152 &= ~ ( V_153 | V_154 | V_155 |
V_156 | V_157 ) ;
switch ( V_151 & V_158 ) {
case V_159 :
break;
case V_160 :
V_152 |= V_153 ;
break;
case V_161 :
V_152 |= V_153 | V_154 ;
break;
case V_162 :
V_152 |= V_154 ;
break;
default:
return - V_120 ;
}
switch ( V_151 & V_163 ) {
case V_164 :
V_152 |= 0x3 ;
break;
case V_165 :
V_152 |= 0x3 | V_156 ;
break;
case V_166 :
V_152 |= 0x2 ;
break;
case V_167 :
V_152 |= 0x1 ;
break;
case V_168 :
break;
default:
return - V_120 ;
}
switch ( V_151 & V_163 ) {
case V_164 :
case V_165 :
switch ( V_151 & V_169 ) {
case V_170 :
break;
case V_171 :
V_152 |= V_157 ;
break;
default:
return - V_120 ;
}
break;
case V_166 :
case V_167 :
case V_168 :
switch ( V_151 & V_169 ) {
case V_170 :
break;
case V_172 :
V_152 |= V_157 | V_156 ;
break;
case V_171 :
V_152 |= V_157 ;
break;
case V_173 :
V_152 |= V_156 ;
break;
default:
return - V_120 ;
}
break;
default:
return - V_120 ;
}
F_13 ( V_88 , V_22 , V_152 ) ;
return 0 ;
}
static int F_30 ( struct V_145 * V_146 , int V_174 )
{
struct V_87 * V_88 = V_146 -> V_88 ;
T_1 V_3 ;
V_3 = F_15 ( V_88 , V_28 ) ;
if ( V_174 )
V_3 |= V_175 ;
else
V_3 &= ~ V_175 ;
F_13 ( V_88 , V_28 , V_3 ) ;
return 0 ;
}
static int F_31 ( struct V_176 * V_177 ,
struct V_178 * V_179 ,
struct V_145 * V_180 )
{
struct V_87 * V_88 = V_180 -> V_88 ;
struct V_90 * V_91 = F_8 ( V_88 ) ;
int V_117 = F_32 ( V_179 ) ;
int V_181 ;
int V_182 ;
int V_100 ;
int V_183 ;
int V_184 ;
int V_185 ;
int V_186 ;
int V_187 ;
T_1 V_152 = F_15 ( V_88 , V_22 ) ;
T_1 V_188 = F_15 ( V_88 , V_23 ) ;
T_1 V_189 = F_15 ( V_88 , V_24 ) ;
T_1 V_190 = F_15 ( V_88 , V_18 ) ;
T_1 V_191 = F_15 ( V_88 , V_19 ) ;
T_1 V_192 = F_15 ( V_88 , V_28 ) ;
if ( V_117 <= 24000 )
V_192 |= V_193 ;
else
V_192 &= ~ V_193 ;
V_183 = 0 ;
V_185 = abs ( V_194 [ V_183 ] . V_195 - V_117 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_194 ) ; V_100 ++ ) {
V_186 = abs ( V_194 [ V_100 ] . V_195 - V_117 ) ;
if ( V_186 <= V_185 ) {
V_183 = V_100 ;
V_185 = V_186 ;
}
}
F_11 ( V_88 -> V_2 , L_10 , V_194 [ V_183 ] . V_195 ) ;
V_191 &= ~ V_196 ;
V_191 |= V_194 [ V_183 ] . V_111 ;
V_152 &= ~ V_197 ;
V_181 = 2 * V_117 ;
switch ( F_33 ( V_179 ) ) {
case 16 :
V_181 *= 16 ;
break;
case 20 :
V_181 *= 20 ;
V_152 |= 0x4 ;
break;
case 24 :
V_181 *= 24 ;
V_152 |= 0x8 ;
break;
case 32 :
V_181 *= 32 ;
V_152 |= 0xc ;
break;
default:
return - V_120 ;
}
F_11 ( V_88 -> V_2 , L_11 ,
V_91 -> V_150 , V_117 ) ;
V_184 = 0 ;
V_185 = abs ( ( V_91 -> V_150 /
( V_198 [ 0 ] . V_199 *
V_198 [ 0 ] . div ) ) - V_117 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_198 ) ; V_100 ++ ) {
V_186 = abs ( ( V_91 -> V_150 /
( V_198 [ V_100 ] . V_199 *
V_198 [ V_100 ] . div ) ) - V_117 ) ;
if ( V_186 <= V_185 ) {
V_184 = V_100 ;
V_185 = V_186 ;
}
}
if ( V_198 [ V_184 ] . V_199 == 2 ) {
V_190 |= V_200 ;
V_187 = V_91 -> V_150 / 2 ;
} else {
V_190 &= ~ V_200 ;
V_187 = V_91 -> V_150 ;
}
V_191 &= ~ ( V_201 |
V_202 ) ;
V_191 |= V_198 [ V_184 ] . V_195 << V_203 ;
V_191 |= V_198 [ V_184 ] . V_204 << V_205 ;
F_11 ( V_88 -> V_2 , L_12 ,
V_198 [ V_184 ] . V_195 ,
V_198 [ V_184 ] . V_204 ,
V_198 [ V_184 ] . div ) ;
F_11 ( V_88 -> V_2 , L_13 , V_187 ) ;
V_182 = 0 ;
V_185 = ( ( V_187 * 10 ) / V_206 [ 0 ] . V_207 ) - V_181 ;
V_100 = 1 ;
while ( V_100 < F_12 ( V_206 ) ) {
V_186 = ( ( V_187 * 10 ) / V_206 [ V_100 ] . V_207 ) - V_181 ;
if ( V_186 < 0 )
break;
V_182 = V_100 ;
V_185 = V_186 ;
V_100 ++ ;
}
V_188 &= ~ V_208 ;
V_189 &= ~ V_209 ;
F_11 ( V_88 -> V_2 , L_14 ,
V_206 [ V_182 ] . V_207 / 10 , V_181 ,
( V_187 * 10 ) / V_206 [ V_182 ] . V_207 ) ;
V_188 |= V_206 [ V_182 ] . div ;
V_189 |= V_181 / V_117 ;
V_91 -> V_117 = F_32 ( V_179 ) ;
F_20 ( V_88 ) ;
F_13 ( V_88 , V_18 , V_190 ) ;
F_13 ( V_88 , V_19 , V_191 ) ;
F_13 ( V_88 , V_22 , V_152 ) ;
F_13 ( V_88 , V_23 , V_188 ) ;
F_13 ( V_88 , V_24 , V_189 ) ;
F_13 ( V_88 , V_28 , V_192 ) ;
return 0 ;
}
int F_34 ( struct V_87 * V_88 , struct V_210 * V_211 ,
int V_212 , int V_213 )
{
struct V_90 * V_91 = F_8 ( V_88 ) ;
int V_214 = V_215 | V_216 ;
F_11 ( V_88 -> V_2 , L_15 ,
V_212 , V_213 ) ;
V_91 -> V_217 = V_211 ;
V_91 -> V_218 = V_212 ;
V_91 -> V_219 = V_213 ;
if ( V_212 )
V_214 &= ~ V_215 ;
if ( V_213 )
V_214 &= ~ V_216 ;
F_9 ( V_88 , V_76 ,
V_215 | V_216 ,
V_214 ) ;
if ( V_212 || V_213 ) {
F_9 ( V_88 , V_64 ,
V_220 , V_220 ) ;
F_9 ( V_88 , V_8 ,
V_221 , V_221 ) ;
} else {
F_9 ( V_88 , V_8 ,
V_221 , 0 ) ;
}
return 0 ;
}
static T_2 F_35 ( int V_222 , void * V_223 )
{
struct V_90 * V_91 = V_223 ;
int V_224 , V_110 ;
unsigned int V_225 , V_226 , V_227 ;
V_110 = F_36 ( V_91 -> V_228 , V_76 ,
& V_226 ) ;
if ( V_110 != 0 ) {
F_37 ( V_91 -> V_2 , L_16 , V_110 ) ;
return V_229 ;
}
V_110 = F_36 ( V_91 -> V_228 , V_75 , & V_225 ) ;
if ( V_110 != 0 ) {
F_37 ( V_91 -> V_2 , L_17 , V_110 ) ;
return V_229 ;
}
V_225 &= ~ V_226 ;
if ( V_225 & V_230 ) {
F_38 ( V_91 -> V_2 , L_18 ) ;
}
V_224 = V_91 -> V_231 ;
V_110 = F_36 ( V_91 -> V_228 , V_77 ,
& V_227 ) ;
if ( V_110 != 0 ) {
F_37 ( V_91 -> V_2 , L_19 ,
V_110 ) ;
return V_232 ;
}
#ifndef F_39
if ( V_225 & ( V_216 | V_215 ) )
F_40 ( F_41 ( V_91 -> V_2 ) ) ;
#endif
if ( V_225 & V_216 ) {
F_11 ( V_91 -> V_2 , L_20 , V_227 ) ;
V_224 ^= V_91 -> V_219 ;
V_227 ^= V_233 ;
}
if ( V_225 & V_215 ) {
F_11 ( V_91 -> V_2 , L_21 , V_227 ) ;
V_224 ^= V_91 -> V_218 ;
V_227 ^= V_234 ;
F_14 ( V_91 -> V_235 ) ;
}
F_42 ( V_91 -> V_228 , V_77 ,
V_233 | V_234 , V_227 ) ;
F_43 ( V_91 -> V_217 , V_224 ,
V_91 -> V_219 | V_91 -> V_218 ) ;
V_91 -> V_231 = V_224 ;
return V_232 ;
}
static int F_44 ( struct V_87 * V_88 )
{
struct V_90 * V_91 = F_8 ( V_88 ) ;
F_45 ( V_91 -> V_228 ) ;
return 0 ;
}
static inline struct V_90 * F_46 ( struct V_236 * V_237 )
{
return F_47 ( V_237 , struct V_90 , V_236 ) ;
}
static int F_48 ( struct V_236 * V_237 , unsigned V_238 )
{
if ( V_238 >= V_239 )
return - V_120 ;
return 0 ;
}
static int F_49 ( struct V_236 * V_237 , unsigned V_238 )
{
struct V_90 * V_91 = F_46 ( V_237 ) ;
unsigned int V_226 , V_101 ;
int V_110 ;
V_226 = V_240 | V_241 ;
V_101 = ( V_242 << V_243 ) |
V_244 ;
V_110 = F_42 ( V_91 -> V_228 ,
V_70 + V_238 , V_226 , V_101 ) ;
if ( V_110 < 0 )
return V_110 ;
return 0 ;
}
static int F_50 ( struct V_236 * V_237 , unsigned V_238 )
{
struct V_90 * V_91 = F_46 ( V_237 ) ;
unsigned int V_3 ;
F_36 ( V_91 -> V_228 , V_70 + V_238 , & V_3 ) ;
return ( V_3 & V_245 ) >> V_246 ;
}
static int F_51 ( struct V_236 * V_237 ,
unsigned V_238 , int V_111 )
{
struct V_90 * V_91 = F_46 ( V_237 ) ;
unsigned int V_226 , V_101 ;
int V_110 ;
V_226 = V_240 | V_241 | V_245 ;
V_101 = ( V_247 << V_243 ) |
( V_111 << V_248 ) ;
V_110 = F_42 ( V_91 -> V_228 ,
V_70 + V_238 , V_226 , V_101 ) ;
if ( V_110 < 0 )
return V_110 ;
return 0 ;
}
static void F_52 ( struct V_236 * V_237 , unsigned V_238 , int V_111 )
{
struct V_90 * V_91 = F_46 ( V_237 ) ;
F_42 ( V_91 -> V_228 , V_70 + V_238 ,
V_245 ,
! ! V_111 << V_246 ) ;
}
static void F_53 ( struct V_90 * V_91 )
{
struct V_249 * V_250 = V_91 -> V_250 ;
int V_110 ;
V_91 -> V_236 = V_251 ;
V_91 -> V_236 . V_252 = V_239 ;
V_91 -> V_236 . V_2 = V_91 -> V_2 ;
if ( V_250 -> V_253 )
V_91 -> V_236 . V_254 = V_250 -> V_253 ;
else
V_91 -> V_236 . V_254 = - 1 ;
V_110 = F_54 ( & V_91 -> V_236 ) ;
if ( V_110 != 0 )
F_37 ( V_91 -> V_2 , L_22 , V_110 ) ;
}
static void F_55 ( struct V_90 * V_91 )
{
F_56 ( & V_91 -> V_236 ) ;
}
static void F_53 ( struct V_90 * V_91 )
{
}
static void F_55 ( struct V_90 * V_91 )
{
}
static int F_57 ( struct V_255 * V_256 ,
struct V_249 * V_250 )
{
struct V_257 * V_257 = F_58 ( V_256 -> V_222 ) ;
if ( ! V_257 ) {
F_37 ( & V_256 -> V_2 , L_23 ,
V_256 -> V_222 ) ;
return - V_120 ;
}
switch ( F_59 ( V_257 ) ) {
case V_258 :
default:
case V_259 :
V_250 -> V_260 = false ;
break;
case V_261 :
V_250 -> V_260 = true ;
break;
}
return 0 ;
}
static int F_60 ( struct V_255 * V_256 ,
struct V_249 * V_250 )
{
const struct V_262 * V_263 = V_256 -> V_2 . V_264 ;
T_3 V_265 ;
int V_100 ;
if ( F_61 ( V_263 , L_24 , & V_265 ) >= 0 )
V_250 -> V_266 = V_265 ;
if ( F_61 ( V_263 , L_25 , & V_265 ) >= 0 )
V_250 -> V_267 = V_265 ;
if ( F_62 ( V_263 , L_26 , V_250 -> V_268 ,
F_12 ( V_250 -> V_268 ) ) >= 0 ) {
for ( V_100 = 0 ; V_100 < F_12 ( V_250 -> V_268 ) ; V_100 ++ ) {
if ( V_250 -> V_268 [ V_100 ] == 0 ) {
V_250 -> V_268 [ V_100 ] = V_269 ;
} else if ( V_250 -> V_268 [ V_100 ] == 0xffffffff ) {
V_250 -> V_268 [ V_100 ] = 0 ;
} else if ( V_250 -> V_268 [ V_100 ] > 0x7fff ) {
F_37 ( & V_256 -> V_2 , L_27 ,
V_100 , V_250 -> V_268 [ V_100 ] ) ;
return - V_120 ;
}
}
}
return 0 ;
}
static int F_63 ( struct V_255 * V_256 ,
const struct V_270 * V_271 )
{
struct V_249 * V_250 = F_64 ( & V_256 -> V_2 ) ;
struct V_90 * V_91 ;
int V_272 ;
bool V_273 = false ;
unsigned int V_101 , V_274 ;
int V_110 , V_100 ;
V_91 = F_65 ( & V_256 -> V_2 , sizeof( struct V_90 ) ,
V_275 ) ;
if ( V_91 == NULL )
return - V_276 ;
F_66 ( & V_91 -> V_121 ) ;
V_91 -> V_2 = & V_256 -> V_2 ;
V_91 -> V_228 = F_67 ( V_256 , & V_277 ) ;
if ( F_68 ( V_91 -> V_228 ) ) {
V_110 = F_69 ( V_91 -> V_228 ) ;
F_37 ( & V_256 -> V_2 , L_28 ,
V_110 ) ;
return V_110 ;
}
F_70 ( V_256 , V_91 ) ;
if ( V_250 ) {
V_91 -> V_250 = V_250 ;
} else {
V_91 -> V_250 = F_65 ( & V_256 -> V_2 ,
sizeof( struct V_249 ) ,
V_275 ) ;
if ( V_91 -> V_250 == NULL ) {
F_37 ( & V_256 -> V_2 , L_29 ) ;
return - V_276 ;
}
if ( V_256 -> V_222 ) {
V_110 = F_57 ( V_256 , V_91 -> V_250 ) ;
if ( V_110 != 0 )
return V_110 ;
}
if ( V_256 -> V_2 . V_264 ) {
V_110 = F_60 ( V_256 , V_91 -> V_250 ) ;
if ( V_110 != 0 )
return V_110 ;
}
}
V_250 = V_91 -> V_250 ;
V_110 = F_36 ( V_91 -> V_228 , V_4 , & V_101 ) ;
if ( V_110 != 0 ) {
F_37 ( & V_256 -> V_2 , L_30 , V_110 ) ;
goto V_278;
}
if ( V_101 != 0x8903 ) {
F_37 ( & V_256 -> V_2 , L_31 , V_101 ) ;
V_110 = - V_279 ;
goto V_278;
}
V_110 = F_36 ( V_91 -> V_228 , V_5 , & V_101 ) ;
if ( V_110 != 0 ) {
F_37 ( & V_256 -> V_2 , L_32 , V_110 ) ;
goto V_278;
}
F_71 ( & V_256 -> V_2 , L_33 ,
( V_101 & V_280 ) + 'A' ) ;
F_72 ( V_91 -> V_228 , V_4 , 0x8903 ) ;
F_53 ( V_91 ) ;
for ( V_100 = 0 ; V_100 < F_12 ( V_250 -> V_268 ) ; V_100 ++ ) {
if ( ( ! V_250 -> V_268 [ V_100 ] ) ||
( V_250 -> V_268 [ V_100 ] > V_269 ) )
continue;
F_72 ( V_91 -> V_228 , V_70 + V_100 ,
V_250 -> V_268 [ V_100 ] & 0x7fff ) ;
V_101 = ( V_250 -> V_268 [ V_100 ] & V_240 )
>> V_243 ;
switch ( V_101 ) {
case V_281 :
case V_282 :
V_273 = true ;
break;
default:
break;
}
}
F_72 ( V_91 -> V_228 , V_8 ,
V_250 -> V_266 ) ;
if ( V_250 -> V_266 )
F_42 ( V_91 -> V_228 , V_64 ,
V_220 , V_220 ) ;
F_4 ( ! V_273 && ( V_250 -> V_266 & V_221 ) ) ;
V_91 -> V_235 = V_250 -> V_267 ;
if ( V_256 -> V_222 ) {
if ( V_250 -> V_260 ) {
V_272 = V_283 ;
V_274 = V_284 ;
} else {
V_272 = V_285 ;
V_274 = 0 ;
}
F_42 ( V_91 -> V_228 , V_78 ,
V_284 , V_274 ) ;
V_110 = F_73 ( V_256 -> V_222 , NULL , F_35 ,
V_272 | V_286 ,
L_34 , V_91 ) ;
if ( V_110 != 0 ) {
F_37 ( V_91 -> V_2 , L_35 ,
V_110 ) ;
return V_110 ;
}
F_42 ( V_91 -> V_228 ,
V_76 ,
V_287 , 0 ) ;
}
F_42 ( V_91 -> V_228 , V_29 ,
V_288 , V_288 ) ;
F_42 ( V_91 -> V_228 , V_30 ,
V_288 , V_288 ) ;
F_42 ( V_91 -> V_228 , V_25 ,
V_289 , V_289 ) ;
F_42 ( V_91 -> V_228 , V_26 ,
V_289 , V_289 ) ;
F_42 ( V_91 -> V_228 , V_47 ,
V_290 , V_290 ) ;
F_42 ( V_91 -> V_228 , V_48 ,
V_290 , V_290 ) ;
F_42 ( V_91 -> V_228 , V_49 ,
V_291 , V_291 ) ;
F_42 ( V_91 -> V_228 , V_50 ,
V_291 , V_291 ) ;
F_42 ( V_91 -> V_228 , V_51 ,
V_292 , V_292 ) ;
F_42 ( V_91 -> V_228 , V_52 ,
V_292 , V_292 ) ;
F_42 ( V_91 -> V_228 , V_28 ,
V_293 | V_175 ,
V_293 | V_175 ) ;
V_110 = F_74 ( & V_256 -> V_2 ,
& V_294 , & V_295 , 1 ) ;
if ( V_110 != 0 )
goto V_278;
return 0 ;
V_278:
return V_110 ;
}
static int F_75 ( struct V_255 * V_296 )
{
struct V_90 * V_91 = F_76 ( V_296 ) ;
if ( V_296 -> V_222 )
F_77 ( V_296 -> V_222 , V_91 ) ;
F_55 ( V_91 ) ;
F_78 ( & V_296 -> V_2 ) ;
return 0 ;
}
