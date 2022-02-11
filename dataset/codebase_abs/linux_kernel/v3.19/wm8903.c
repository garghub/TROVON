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
struct V_87 * V_88 = V_82 -> V_88 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
switch ( V_85 ) {
case V_86 :
V_90 -> V_91 |= 1 << V_82 -> V_92 ;
break;
case V_93 :
F_8 ( V_88 , V_54 ,
1 << V_82 -> V_92 , 0 ) ;
break;
}
return 0 ;
}
static void F_9 ( struct V_94 * V_95 ,
enum V_96 V_85 , int V_97 )
{
struct V_87 * V_88 = F_10 ( V_95 ) ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_98 = V_99 ;
int V_100 , V_101 ;
if ( V_90 -> V_91 ) {
F_11 ( V_88 -> V_2 , L_1 ,
V_90 -> V_91 ) ;
for ( V_100 = 0 ; V_100 < F_12 ( V_90 -> V_102 ) ; V_100 ++ ) {
if ( ! ( V_90 -> V_91 & ( 1 << V_100 ) ) )
continue;
if ( V_90 -> V_102 [ V_100 ] ) {
F_11 ( V_88 -> V_2 ,
L_2 ,
3 - V_100 , V_90 -> V_102 [ V_100 ] ) ;
F_13 ( V_88 , V_103 + V_100 ,
V_90 -> V_102 [ V_100 ] & 0xff ) ;
} else {
F_11 ( V_88 -> V_2 ,
L_3 , 3 - V_100 ) ;
V_98 = V_104 ;
}
}
if ( V_90 -> V_105 )
V_98 = V_104 ;
F_8 ( V_88 , V_55 ,
V_106 , V_98 ) ;
F_8 ( V_88 , V_54 ,
V_107 , V_90 -> V_91 ) ;
switch ( V_98 ) {
case V_99 :
break;
case V_104 :
F_14 ( 270 ) ;
if ( V_90 -> V_105 )
break;
for ( V_100 = 0 ; V_100 < F_12 ( V_90 -> V_102 ) ; V_100 ++ ) {
if ( ! ( V_90 -> V_91 & ( 1 << V_100 ) ) )
continue;
V_101 = F_15 ( V_88 ,
V_56 + V_100 ) ;
F_11 ( V_88 -> V_2 , L_4 ,
3 - V_100 , V_101 ) ;
V_90 -> V_102 [ V_100 ] = V_101 ;
}
break;
default:
F_16 ( L_5 , V_98 ) ;
break;
}
V_90 -> V_91 = 0 ;
}
}
static int F_17 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_87 * V_88 = F_18 ( V_84 ) ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
T_1 V_3 ;
int V_110 ;
V_3 = F_15 ( V_88 , V_63 ) ;
if ( V_109 -> V_111 . integer . V_111 [ 0 ] ) {
if ( V_90 -> V_105 == 0 ) {
F_11 ( V_88 -> V_2 , L_6 ) ;
F_13 ( V_88 , V_63 , V_3 &
~ ( V_112 | V_113 ) ) ;
}
V_90 -> V_105 ++ ;
}
V_110 = F_19 ( V_84 , V_109 ) ;
if ( ! V_109 -> V_111 . integer . V_111 [ 0 ] ) {
if ( V_90 -> V_105 == 1 ) {
F_11 ( V_88 -> V_2 , L_7 ) ;
F_13 ( V_88 , V_63 , V_3 |
V_112 | V_113 ) ;
}
V_90 -> V_105 -- ;
}
F_11 ( V_88 -> V_2 , L_8 ,
V_90 -> V_105 ) ;
return V_110 ;
}
static int F_20 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_101 , V_100 , V_114 ;
if ( V_90 -> V_115 ) {
V_114 = 1 ;
for ( V_100 = 2 ; V_100 < F_12 ( V_116 ) ; V_100 ++ ) {
if ( abs ( V_116 [ V_100 ] - V_90 -> V_117 ) <
abs ( V_116 [ V_114 ] - V_90 -> V_117 ) )
V_114 = V_100 ;
}
V_101 = V_114 << V_118 ;
} else {
V_114 = 0 ;
V_101 = 0 ;
}
F_11 ( V_88 -> V_2 , L_9 ,
V_114 , V_116 [ V_114 ] ) ;
return F_8 ( V_88 , V_28 ,
V_119 , V_101 ) ;
}
static int F_21 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_87 * V_88 = F_22 ( V_84 ) ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
V_109 -> V_111 . V_120 . V_121 [ 0 ] = V_90 -> V_115 ;
return 0 ;
}
static int F_23 ( struct V_83 * V_84 ,
struct V_108 * V_109 )
{
struct V_87 * V_88 = F_22 ( V_84 ) ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_115 = V_109 -> V_111 . V_120 . V_121 [ 0 ] ;
int V_110 = 0 ;
if ( V_115 > 1 )
return - V_122 ;
F_24 ( & V_90 -> V_123 ) ;
if ( V_90 -> V_115 != V_115 ) {
V_90 -> V_115 = V_115 ;
F_20 ( V_88 ) ;
V_110 = 1 ;
}
F_25 ( & V_90 -> V_123 ) ;
return V_110 ;
}
static int F_26 ( struct V_87 * V_88 ,
enum V_124 V_125 )
{
switch ( V_125 ) {
case V_126 :
break;
case V_127 :
F_8 ( V_88 , V_7 ,
V_128 ,
V_129 ) ;
break;
case V_130 :
if ( V_88 -> V_95 . V_131 == V_132 ) {
F_8 ( V_88 , V_6 ,
V_133 | V_134 |
V_135 |
V_136 ,
V_133 |
( 2 << V_137 ) |
V_135 ) ;
F_8 ( V_88 ,
V_53 ,
V_138 ,
V_138 ) ;
F_14 ( 33 ) ;
F_8 ( V_88 , V_16 ,
V_139 | V_140 ,
V_139 | V_140 ) ;
F_8 ( V_88 ,
V_53 ,
V_138 , 0 ) ;
F_8 ( V_88 , V_7 ,
V_141 |
V_142 |
V_143 |
V_144 |
V_128 |
V_145 ,
V_141 |
V_142 |
V_143 |
( 2 << V_146 ) |
V_147 |
V_145 ) ;
F_14 ( 129 ) ;
F_8 ( V_88 , V_16 ,
V_139 | V_140 ,
0 ) ;
F_8 ( V_88 , V_7 ,
V_144 , 0 ) ;
F_8 ( V_88 , V_7 ,
V_128 ,
V_129 ) ;
F_8 ( V_88 , V_6 ,
V_136 | V_133 ,
V_136 ) ;
F_11 ( V_88 -> V_2 , L_7 ) ;
F_8 ( V_88 , V_63 ,
V_112 |
V_113 ,
V_112 |
V_113 ) ;
}
F_8 ( V_88 , V_7 ,
V_128 ,
V_147 ) ;
break;
case V_132 :
F_8 ( V_88 , V_6 ,
V_136 , 0 ) ;
F_8 ( V_88 , V_7 ,
V_144 ,
2 << V_146 ) ;
F_8 ( V_88 , V_7 ,
V_145 , 0 ) ;
F_14 ( 290 ) ;
F_8 ( V_88 , V_7 ,
V_141 | V_142 |
V_143 | V_128 |
V_144 |
V_145 , 0 ) ;
F_8 ( V_88 , V_6 ,
V_135 , 0 ) ;
break;
}
V_88 -> V_95 . V_131 = V_125 ;
return 0 ;
}
static int F_27 ( struct V_148 * V_149 ,
int V_150 , unsigned int V_151 , int V_152 )
{
struct V_87 * V_88 = V_149 -> V_88 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
V_90 -> V_153 = V_151 ;
return 0 ;
}
static int F_28 ( struct V_148 * V_149 ,
unsigned int V_154 )
{
struct V_87 * V_88 = V_149 -> V_88 ;
T_1 V_155 = F_15 ( V_88 , V_22 ) ;
V_155 &= ~ ( V_156 | V_157 | V_158 |
V_159 | V_160 ) ;
switch ( V_154 & V_161 ) {
case V_162 :
break;
case V_163 :
V_155 |= V_156 ;
break;
case V_164 :
V_155 |= V_156 | V_157 ;
break;
case V_165 :
V_155 |= V_157 ;
break;
default:
return - V_122 ;
}
switch ( V_154 & V_166 ) {
case V_167 :
V_155 |= 0x3 ;
break;
case V_168 :
V_155 |= 0x3 | V_159 ;
break;
case V_169 :
V_155 |= 0x2 ;
break;
case V_170 :
V_155 |= 0x1 ;
break;
case V_171 :
break;
default:
return - V_122 ;
}
switch ( V_154 & V_166 ) {
case V_167 :
case V_168 :
switch ( V_154 & V_172 ) {
case V_173 :
break;
case V_174 :
V_155 |= V_160 ;
break;
default:
return - V_122 ;
}
break;
case V_169 :
case V_170 :
case V_171 :
switch ( V_154 & V_172 ) {
case V_173 :
break;
case V_175 :
V_155 |= V_160 | V_159 ;
break;
case V_174 :
V_155 |= V_160 ;
break;
case V_176 :
V_155 |= V_159 ;
break;
default:
return - V_122 ;
}
break;
default:
return - V_122 ;
}
F_13 ( V_88 , V_22 , V_155 ) ;
return 0 ;
}
static int F_29 ( struct V_148 * V_149 , int V_177 )
{
struct V_87 * V_88 = V_149 -> V_88 ;
T_1 V_3 ;
V_3 = F_15 ( V_88 , V_28 ) ;
if ( V_177 )
V_3 |= V_178 ;
else
V_3 &= ~ V_178 ;
F_13 ( V_88 , V_28 , V_3 ) ;
return 0 ;
}
static int F_30 ( struct V_179 * V_180 ,
struct V_181 * V_182 ,
struct V_148 * V_183 )
{
struct V_87 * V_88 = V_183 -> V_88 ;
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_117 = F_31 ( V_182 ) ;
int V_184 ;
int V_185 ;
int V_100 ;
int V_186 ;
int V_187 ;
int V_188 ;
int V_189 ;
int V_190 ;
T_1 V_155 = F_15 ( V_88 , V_22 ) ;
T_1 V_191 = F_15 ( V_88 , V_23 ) ;
T_1 V_192 = F_15 ( V_88 , V_24 ) ;
T_1 V_193 = F_15 ( V_88 , V_18 ) ;
T_1 V_194 = F_15 ( V_88 , V_19 ) ;
T_1 V_195 = F_15 ( V_88 , V_28 ) ;
if ( V_117 <= 24000 )
V_195 |= V_196 ;
else
V_195 &= ~ V_196 ;
V_186 = 0 ;
V_188 = abs ( V_197 [ V_186 ] . V_198 - V_117 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_197 ) ; V_100 ++ ) {
V_189 = abs ( V_197 [ V_100 ] . V_198 - V_117 ) ;
if ( V_189 <= V_188 ) {
V_186 = V_100 ;
V_188 = V_189 ;
}
}
F_11 ( V_88 -> V_2 , L_10 , V_197 [ V_186 ] . V_198 ) ;
V_194 &= ~ V_199 ;
V_194 |= V_197 [ V_186 ] . V_111 ;
V_155 &= ~ V_200 ;
V_184 = 2 * V_117 ;
switch ( F_32 ( V_182 ) ) {
case 16 :
V_184 *= 16 ;
break;
case 20 :
V_184 *= 20 ;
V_155 |= 0x4 ;
break;
case 24 :
V_184 *= 24 ;
V_155 |= 0x8 ;
break;
case 32 :
V_184 *= 32 ;
V_155 |= 0xc ;
break;
default:
return - V_122 ;
}
F_11 ( V_88 -> V_2 , L_11 ,
V_90 -> V_153 , V_117 ) ;
V_187 = 0 ;
V_188 = abs ( ( V_90 -> V_153 /
( V_201 [ 0 ] . V_202 *
V_201 [ 0 ] . div ) ) - V_117 ) ;
for ( V_100 = 1 ; V_100 < F_12 ( V_201 ) ; V_100 ++ ) {
V_189 = abs ( ( V_90 -> V_153 /
( V_201 [ V_100 ] . V_202 *
V_201 [ V_100 ] . div ) ) - V_117 ) ;
if ( V_189 <= V_188 ) {
V_187 = V_100 ;
V_188 = V_189 ;
}
}
if ( V_201 [ V_187 ] . V_202 == 2 ) {
V_193 |= V_203 ;
V_190 = V_90 -> V_153 / 2 ;
} else {
V_193 &= ~ V_203 ;
V_190 = V_90 -> V_153 ;
}
V_194 &= ~ ( V_204 |
V_205 ) ;
V_194 |= V_201 [ V_187 ] . V_198 << V_206 ;
V_194 |= V_201 [ V_187 ] . V_207 << V_208 ;
F_11 ( V_88 -> V_2 , L_12 ,
V_201 [ V_187 ] . V_198 ,
V_201 [ V_187 ] . V_207 ,
V_201 [ V_187 ] . div ) ;
F_11 ( V_88 -> V_2 , L_13 , V_190 ) ;
V_185 = 0 ;
V_188 = ( ( V_190 * 10 ) / V_209 [ 0 ] . V_210 ) - V_184 ;
V_100 = 1 ;
while ( V_100 < F_12 ( V_209 ) ) {
V_189 = ( ( V_190 * 10 ) / V_209 [ V_100 ] . V_210 ) - V_184 ;
if ( V_189 < 0 )
break;
V_185 = V_100 ;
V_188 = V_189 ;
V_100 ++ ;
}
V_191 &= ~ V_211 ;
V_192 &= ~ V_212 ;
F_11 ( V_88 -> V_2 , L_14 ,
V_209 [ V_185 ] . V_210 / 10 , V_184 ,
( V_190 * 10 ) / V_209 [ V_185 ] . V_210 ) ;
V_191 |= V_209 [ V_185 ] . div ;
V_192 |= V_184 / V_117 ;
V_90 -> V_117 = F_31 ( V_182 ) ;
F_20 ( V_88 ) ;
F_13 ( V_88 , V_18 , V_193 ) ;
F_13 ( V_88 , V_19 , V_194 ) ;
F_13 ( V_88 , V_22 , V_155 ) ;
F_13 ( V_88 , V_23 , V_191 ) ;
F_13 ( V_88 , V_24 , V_192 ) ;
F_13 ( V_88 , V_28 , V_195 ) ;
return 0 ;
}
int F_33 ( struct V_87 * V_88 , struct V_213 * V_214 ,
int V_215 , int V_216 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
int V_217 = V_218 | V_219 ;
F_11 ( V_88 -> V_2 , L_15 ,
V_215 , V_216 ) ;
V_90 -> V_220 = V_214 ;
V_90 -> V_221 = V_215 ;
V_90 -> V_222 = V_216 ;
if ( V_215 )
V_217 &= ~ V_218 ;
if ( V_216 )
V_217 &= ~ V_219 ;
F_8 ( V_88 , V_76 ,
V_218 | V_219 ,
V_217 ) ;
if ( V_215 || V_216 ) {
F_8 ( V_88 , V_64 ,
V_223 , V_223 ) ;
F_8 ( V_88 , V_8 ,
V_224 , V_224 ) ;
} else {
F_8 ( V_88 , V_8 ,
V_224 , 0 ) ;
}
return 0 ;
}
static T_2 F_34 ( int V_225 , void * V_226 )
{
struct V_89 * V_90 = V_226 ;
int V_227 , V_110 ;
unsigned int V_228 , V_229 , V_230 ;
V_110 = F_35 ( V_90 -> V_231 , V_76 ,
& V_229 ) ;
if ( V_110 != 0 ) {
F_36 ( V_90 -> V_2 , L_16 , V_110 ) ;
return V_232 ;
}
V_110 = F_35 ( V_90 -> V_231 , V_75 , & V_228 ) ;
if ( V_110 != 0 ) {
F_36 ( V_90 -> V_2 , L_17 , V_110 ) ;
return V_232 ;
}
V_228 &= ~ V_229 ;
if ( V_228 & V_233 ) {
F_37 ( V_90 -> V_2 , L_18 ) ;
}
V_227 = V_90 -> V_234 ;
V_110 = F_35 ( V_90 -> V_231 , V_77 ,
& V_230 ) ;
if ( V_110 != 0 ) {
F_36 ( V_90 -> V_2 , L_19 ,
V_110 ) ;
return V_235 ;
}
#ifndef F_38
if ( V_228 & ( V_219 | V_218 ) )
F_39 ( F_40 ( V_90 -> V_2 ) ) ;
#endif
if ( V_228 & V_219 ) {
F_11 ( V_90 -> V_2 , L_20 , V_230 ) ;
V_227 ^= V_90 -> V_222 ;
V_230 ^= V_236 ;
}
if ( V_228 & V_218 ) {
F_11 ( V_90 -> V_2 , L_21 , V_230 ) ;
V_227 ^= V_90 -> V_221 ;
V_230 ^= V_237 ;
F_14 ( V_90 -> V_238 ) ;
}
F_41 ( V_90 -> V_231 , V_77 ,
V_236 | V_237 , V_230 ) ;
F_42 ( V_90 -> V_220 , V_227 ,
V_90 -> V_222 | V_90 -> V_221 ) ;
V_90 -> V_234 = V_227 ;
return V_235 ;
}
static int F_43 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_7 ( V_88 ) ;
F_44 ( V_90 -> V_231 ) ;
return 0 ;
}
static inline struct V_89 * F_45 ( struct V_239 * V_240 )
{
return F_46 ( V_240 , struct V_89 , V_239 ) ;
}
static int F_47 ( struct V_239 * V_240 , unsigned V_241 )
{
if ( V_241 >= V_242 )
return - V_122 ;
return 0 ;
}
static int F_48 ( struct V_239 * V_240 , unsigned V_241 )
{
struct V_89 * V_90 = F_45 ( V_240 ) ;
unsigned int V_229 , V_101 ;
int V_110 ;
V_229 = V_243 | V_244 ;
V_101 = ( V_245 << V_246 ) |
V_247 ;
V_110 = F_41 ( V_90 -> V_231 ,
V_70 + V_241 , V_229 , V_101 ) ;
if ( V_110 < 0 )
return V_110 ;
return 0 ;
}
static int F_49 ( struct V_239 * V_240 , unsigned V_241 )
{
struct V_89 * V_90 = F_45 ( V_240 ) ;
unsigned int V_3 ;
F_35 ( V_90 -> V_231 , V_70 + V_241 , & V_3 ) ;
return ( V_3 & V_248 ) >> V_249 ;
}
static int F_50 ( struct V_239 * V_240 ,
unsigned V_241 , int V_111 )
{
struct V_89 * V_90 = F_45 ( V_240 ) ;
unsigned int V_229 , V_101 ;
int V_110 ;
V_229 = V_243 | V_244 | V_248 ;
V_101 = ( V_250 << V_246 ) |
( V_111 << V_251 ) ;
V_110 = F_41 ( V_90 -> V_231 ,
V_70 + V_241 , V_229 , V_101 ) ;
if ( V_110 < 0 )
return V_110 ;
return 0 ;
}
static void F_51 ( struct V_239 * V_240 , unsigned V_241 , int V_111 )
{
struct V_89 * V_90 = F_45 ( V_240 ) ;
F_41 ( V_90 -> V_231 , V_70 + V_241 ,
V_248 ,
! ! V_111 << V_249 ) ;
}
static void F_52 ( struct V_89 * V_90 )
{
struct V_252 * V_253 = V_90 -> V_253 ;
int V_110 ;
V_90 -> V_239 = V_254 ;
V_90 -> V_239 . V_255 = V_242 ;
V_90 -> V_239 . V_2 = V_90 -> V_2 ;
if ( V_253 -> V_256 )
V_90 -> V_239 . V_257 = V_253 -> V_256 ;
else
V_90 -> V_239 . V_257 = - 1 ;
V_110 = F_53 ( & V_90 -> V_239 ) ;
if ( V_110 != 0 )
F_36 ( V_90 -> V_2 , L_22 , V_110 ) ;
}
static void F_54 ( struct V_89 * V_90 )
{
F_55 ( & V_90 -> V_239 ) ;
}
static void F_52 ( struct V_89 * V_90 )
{
}
static void F_54 ( struct V_89 * V_90 )
{
}
static int F_56 ( struct V_258 * V_259 ,
struct V_252 * V_253 )
{
struct V_260 * V_260 = F_57 ( V_259 -> V_225 ) ;
if ( ! V_260 ) {
F_36 ( & V_259 -> V_2 , L_23 ,
V_259 -> V_225 ) ;
return - V_122 ;
}
switch ( F_58 ( V_260 ) ) {
case V_261 :
default:
case V_262 :
V_253 -> V_263 = false ;
break;
case V_264 :
V_253 -> V_263 = true ;
break;
}
return 0 ;
}
static int F_59 ( struct V_258 * V_259 ,
struct V_252 * V_253 )
{
const struct V_265 * V_266 = V_259 -> V_2 . V_267 ;
T_3 V_268 ;
int V_100 ;
if ( F_60 ( V_266 , L_24 , & V_268 ) >= 0 )
V_253 -> V_269 = V_268 ;
if ( F_60 ( V_266 , L_25 , & V_268 ) >= 0 )
V_253 -> V_270 = V_268 ;
if ( F_61 ( V_266 , L_26 , V_253 -> V_271 ,
F_12 ( V_253 -> V_271 ) ) >= 0 ) {
for ( V_100 = 0 ; V_100 < F_12 ( V_253 -> V_271 ) ; V_100 ++ ) {
if ( V_253 -> V_271 [ V_100 ] == 0 ) {
V_253 -> V_271 [ V_100 ] = V_272 ;
} else if ( V_253 -> V_271 [ V_100 ] == 0xffffffff ) {
V_253 -> V_271 [ V_100 ] = 0 ;
} else if ( V_253 -> V_271 [ V_100 ] > 0x7fff ) {
F_36 ( & V_259 -> V_2 , L_27 ,
V_100 , V_253 -> V_271 [ V_100 ] ) ;
return - V_122 ;
}
}
}
return 0 ;
}
static int F_62 ( struct V_258 * V_259 ,
const struct V_273 * V_274 )
{
struct V_252 * V_253 = F_63 ( & V_259 -> V_2 ) ;
struct V_89 * V_90 ;
int V_275 ;
bool V_276 = false ;
unsigned int V_101 , V_277 ;
int V_110 , V_100 ;
V_90 = F_64 ( & V_259 -> V_2 , sizeof( struct V_89 ) ,
V_278 ) ;
if ( V_90 == NULL )
return - V_279 ;
F_65 ( & V_90 -> V_123 ) ;
V_90 -> V_2 = & V_259 -> V_2 ;
V_90 -> V_231 = F_66 ( V_259 , & V_280 ) ;
if ( F_67 ( V_90 -> V_231 ) ) {
V_110 = F_68 ( V_90 -> V_231 ) ;
F_36 ( & V_259 -> V_2 , L_28 ,
V_110 ) ;
return V_110 ;
}
F_69 ( V_259 , V_90 ) ;
if ( V_253 ) {
V_90 -> V_253 = V_253 ;
} else {
V_90 -> V_253 = F_64 ( & V_259 -> V_2 ,
sizeof( struct V_252 ) ,
V_278 ) ;
if ( V_90 -> V_253 == NULL ) {
F_36 ( & V_259 -> V_2 , L_29 ) ;
return - V_279 ;
}
if ( V_259 -> V_225 ) {
V_110 = F_56 ( V_259 , V_90 -> V_253 ) ;
if ( V_110 != 0 )
return V_110 ;
}
if ( V_259 -> V_2 . V_267 ) {
V_110 = F_59 ( V_259 , V_90 -> V_253 ) ;
if ( V_110 != 0 )
return V_110 ;
}
}
V_253 = V_90 -> V_253 ;
V_110 = F_35 ( V_90 -> V_231 , V_4 , & V_101 ) ;
if ( V_110 != 0 ) {
F_36 ( & V_259 -> V_2 , L_30 , V_110 ) ;
goto V_281;
}
if ( V_101 != 0x8903 ) {
F_36 ( & V_259 -> V_2 , L_31 , V_101 ) ;
V_110 = - V_282 ;
goto V_281;
}
V_110 = F_35 ( V_90 -> V_231 , V_5 , & V_101 ) ;
if ( V_110 != 0 ) {
F_36 ( & V_259 -> V_2 , L_32 , V_110 ) ;
goto V_281;
}
F_70 ( & V_259 -> V_2 , L_33 ,
( V_101 & V_283 ) + 'A' ) ;
F_71 ( V_90 -> V_231 , V_4 , 0x8903 ) ;
F_52 ( V_90 ) ;
for ( V_100 = 0 ; V_100 < F_12 ( V_253 -> V_271 ) ; V_100 ++ ) {
if ( ( ! V_253 -> V_271 [ V_100 ] ) ||
( V_253 -> V_271 [ V_100 ] > V_272 ) )
continue;
F_71 ( V_90 -> V_231 , V_70 + V_100 ,
V_253 -> V_271 [ V_100 ] & 0x7fff ) ;
V_101 = ( V_253 -> V_271 [ V_100 ] & V_243 )
>> V_246 ;
switch ( V_101 ) {
case V_284 :
case V_285 :
V_276 = true ;
break;
default:
break;
}
}
F_71 ( V_90 -> V_231 , V_8 ,
V_253 -> V_269 ) ;
if ( V_253 -> V_269 )
F_41 ( V_90 -> V_231 , V_64 ,
V_223 , V_223 ) ;
F_4 ( ! V_276 && ( V_253 -> V_269 & V_224 ) ) ;
V_90 -> V_238 = V_253 -> V_270 ;
if ( V_259 -> V_225 ) {
if ( V_253 -> V_263 ) {
V_275 = V_286 ;
V_277 = V_287 ;
} else {
V_275 = V_288 ;
V_277 = 0 ;
}
F_41 ( V_90 -> V_231 , V_78 ,
V_287 , V_277 ) ;
V_110 = F_72 ( V_259 -> V_225 , NULL , F_34 ,
V_275 | V_289 ,
L_34 , V_90 ) ;
if ( V_110 != 0 ) {
F_36 ( V_90 -> V_2 , L_35 ,
V_110 ) ;
return V_110 ;
}
F_41 ( V_90 -> V_231 ,
V_76 ,
V_290 , 0 ) ;
}
F_41 ( V_90 -> V_231 , V_29 ,
V_291 , V_291 ) ;
F_41 ( V_90 -> V_231 , V_30 ,
V_291 , V_291 ) ;
F_41 ( V_90 -> V_231 , V_25 ,
V_292 , V_292 ) ;
F_41 ( V_90 -> V_231 , V_26 ,
V_292 , V_292 ) ;
F_41 ( V_90 -> V_231 , V_47 ,
V_293 , V_293 ) ;
F_41 ( V_90 -> V_231 , V_48 ,
V_293 , V_293 ) ;
F_41 ( V_90 -> V_231 , V_49 ,
V_294 , V_294 ) ;
F_41 ( V_90 -> V_231 , V_50 ,
V_294 , V_294 ) ;
F_41 ( V_90 -> V_231 , V_51 ,
V_295 , V_295 ) ;
F_41 ( V_90 -> V_231 , V_52 ,
V_295 , V_295 ) ;
F_41 ( V_90 -> V_231 , V_28 ,
V_296 | V_178 ,
V_296 | V_178 ) ;
V_110 = F_73 ( & V_259 -> V_2 ,
& V_297 , & V_298 , 1 ) ;
if ( V_110 != 0 )
goto V_281;
return 0 ;
V_281:
return V_110 ;
}
static int F_74 ( struct V_258 * V_299 )
{
struct V_89 * V_90 = F_75 ( V_299 ) ;
if ( V_299 -> V_225 )
F_76 ( V_299 -> V_225 , V_90 ) ;
F_54 ( V_90 ) ;
F_77 ( & V_299 -> V_2 ) ;
return 0 ;
}
