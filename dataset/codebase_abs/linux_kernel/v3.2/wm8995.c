static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 1 ;
int V_4 = 0 ;
int V_5 , V_6 ;
V_5 = F_2 ( V_2 , V_7 ) ;
switch ( V_5 ) {
case V_8 :
F_3 ( V_2 -> V_9 , L_1 ) ;
V_4 = 2 << V_10 ;
break;
case V_11 :
F_3 ( V_2 -> V_9 , L_2 ) ;
V_4 = 1 << V_10 ;
break;
case V_12 :
F_3 ( V_2 -> V_9 , L_3 ) ;
V_4 = 0 << V_10 ;
break;
default:
F_3 ( V_2 -> V_9 , L_4 , V_5 ) ;
V_3 = 0 ;
break;
}
V_6 = F_2 ( V_2 , V_13 ) ;
if ( V_6 != V_5 ) {
F_3 ( V_2 -> V_9 , L_5 ) ;
V_3 = 0 ;
}
if ( V_3 ) {
F_3 ( V_2 -> V_9 , L_6 ) ;
F_4 ( V_2 , V_14 ,
V_15 |
V_16 ,
V_4 | V_17 ) ;
} else {
F_3 ( V_2 -> V_9 , L_7 ) ;
F_4 ( V_2 , V_14 ,
V_15 , 0 ) ;
}
}
static int F_5 ( struct V_18 * V_4 ,
struct V_18 * V_19 )
{
unsigned int V_5 ;
const char * V_20 ;
V_5 = F_2 ( V_4 -> V_2 , V_21 ) ;
if ( V_5 & V_22 )
V_20 = L_8 ;
else
V_20 = L_9 ;
return ! strcmp ( V_4 -> V_23 , V_20 ) ;
}
static int F_6 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = F_7 ( V_25 ) ;
struct V_18 * V_30 = V_29 -> V_31 [ 0 ] ;
struct V_1 * V_2 ;
int V_32 ;
V_2 = V_30 -> V_2 ;
V_32 = F_8 ( V_25 , V_27 ) ;
F_1 ( V_2 ) ;
return V_32 ;
}
static int F_9 ( struct V_18 * V_30 ,
struct V_24 * V_25 , int V_33 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_2 = V_30 -> V_2 ;
V_35 = F_10 ( V_2 ) ;
switch ( V_33 ) {
case V_36 :
F_4 ( V_2 , V_37 ,
V_38 |
V_39 ,
V_40 |
V_41 ) ;
F_4 ( V_2 , V_42 ,
V_43 |
V_44 ,
V_45 |
V_46 ) ;
break;
case V_47 :
F_4 ( V_2 , V_48 ,
V_49 , 0 ) ;
break;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_50 , unsigned int V_51 )
{
int V_52 = 10 ;
F_3 ( V_2 -> V_9 , L_10 ,
V_53 , V_5 , V_50 , V_51 ) ;
F_12 ( V_2 , V_5 , V_50 ) ;
while ( V_52 -- ) {
F_13 ( 10 ) ;
V_50 = F_2 ( V_2 , V_54 ) ;
if ( ( V_50 & V_51 ) == V_51 )
return;
}
F_14 ( V_2 -> V_9 , L_11 ) ;
}
static int F_15 ( struct V_18 * V_30 ,
struct V_24 * V_25 , int V_33 )
{
struct V_1 * V_2 ;
unsigned int V_5 ;
V_2 = V_30 -> V_2 ;
V_5 = F_2 ( V_2 , V_42 ) ;
switch ( V_33 ) {
case V_55 :
F_4 ( V_2 , V_48 ,
V_49 , V_56 ) ;
F_13 ( 5 ) ;
F_4 ( V_2 , V_37 ,
V_38 |
V_39 ,
V_40 | V_41 ) ;
F_16 ( 20 ) ;
V_5 |= V_45 | V_46 ;
F_12 ( V_2 , V_42 , V_5 ) ;
F_12 ( V_2 , V_57 , V_58 |
V_59 ) ;
F_11 ( V_2 , V_60 ,
V_61 |
V_62 ,
V_63 |
V_64 ) ;
V_5 |= V_65 | V_66 |
V_67 | V_68 ;
F_12 ( V_2 , V_42 , V_5 ) ;
break;
case V_47 :
F_4 ( V_2 , V_42 ,
V_69 |
V_70 |
V_71 |
V_72 , 0 ) ;
F_4 ( V_2 , V_42 ,
V_43 |
V_44 , 0 ) ;
F_12 ( V_2 , V_57 , 0 ) ;
F_4 ( V_2 , V_37 ,
V_38 |
V_39 ,
0 ) ;
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_73 )
{
struct V_34 * V_35 ;
int V_74 ;
int V_75 = 0 ;
int V_76 ;
V_35 = F_10 ( V_2 ) ;
if ( V_73 )
V_76 = 4 ;
else
V_76 = 0 ;
switch ( V_35 -> V_77 [ V_73 ] ) {
case V_78 :
V_74 = V_35 -> V_79 [ 0 ] ;
break;
case V_80 :
V_75 |= 0x8 ;
V_74 = V_35 -> V_79 [ 1 ] ;
break;
case V_81 :
V_75 |= 0x10 ;
V_74 = V_35 -> V_82 [ 0 ] . V_83 ;
break;
case V_84 :
V_75 |= 0x18 ;
V_74 = V_35 -> V_82 [ 1 ] . V_83 ;
break;
default:
return - V_85 ;
}
if ( V_74 >= 13500000 ) {
V_74 /= 2 ;
V_75 |= V_86 ;
F_3 ( V_2 -> V_9 , L_12 ,
V_73 + 1 , V_74 ) ;
}
V_35 -> V_87 [ V_73 ] = V_74 ;
F_4 ( V_2 , V_88 + V_76 ,
V_89 | V_90 ,
V_75 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_91 , V_92 ;
V_35 = F_10 ( V_2 ) ;
F_17 ( V_2 , 0 ) ;
F_17 ( V_2 , 1 ) ;
if ( V_35 -> V_87 [ 0 ] == V_35 -> V_87 [ 1 ] )
return 0 ;
if ( V_35 -> V_87 [ 0 ] < V_35 -> V_87 [ 1 ] )
V_92 = V_22 ;
else
V_92 = 0 ;
V_91 = F_4 ( V_2 , V_21 ,
V_93 , V_92 ) ;
if ( ! V_91 )
return 0 ;
F_19 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_30 ,
struct V_24 * V_25 , int V_33 )
{
struct V_1 * V_2 ;
V_2 = V_30 -> V_2 ;
switch ( V_33 ) {
case V_36 :
return F_18 ( V_2 ) ;
case V_95 :
F_18 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_5 )
{
if ( V_5 > V_96 )
return 1 ;
switch ( V_5 ) {
case V_97 :
case V_54 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
return 1 ;
}
return 0 ;
}
static int F_22 ( struct V_107 * V_108 , int V_109 )
{
struct V_1 * V_2 = V_108 -> V_2 ;
int V_110 ;
switch ( V_108 -> V_111 ) {
case 0 :
V_110 = V_112 ;
break;
case 1 :
V_110 = V_113 ;
break;
default:
return - V_85 ;
}
F_4 ( V_2 , V_110 , V_114 ,
! ! V_109 << V_115 ) ;
return 0 ;
}
static int F_23 ( struct V_107 * V_108 , unsigned int V_116 )
{
struct V_1 * V_2 ;
int V_117 ;
int V_73 ;
V_2 = V_108 -> V_2 ;
V_117 = 0 ;
switch ( V_116 & V_118 ) {
case V_119 :
break;
case V_120 :
V_117 = V_121 ;
break;
default:
F_14 ( V_108 -> V_9 , L_13 ) ;
return - V_85 ;
}
V_73 = 0 ;
switch ( V_116 & V_122 ) {
case V_123 :
V_73 |= V_124 ;
case V_125 :
V_73 |= ( 0x3 << V_126 ) ;
break;
case V_127 :
V_73 |= ( 0x2 << V_126 ) ;
break;
case V_128 :
break;
case V_129 :
V_73 |= ( 0x1 << V_126 ) ;
break;
default:
F_14 ( V_108 -> V_9 , L_14 ) ;
return - V_85 ;
}
switch ( V_116 & V_122 ) {
case V_125 :
case V_123 :
switch ( V_116 & V_130 ) {
case V_131 :
break;
case V_132 :
V_73 |= V_133 ;
break;
default:
return - V_85 ;
}
break;
case V_127 :
case V_128 :
case V_129 :
switch ( V_116 & V_130 ) {
case V_131 :
break;
case V_134 :
V_73 |= V_133 | V_124 ;
break;
case V_132 :
V_73 |= V_133 ;
break;
case V_135 :
V_73 |= V_124 ;
break;
default:
return - V_85 ;
}
break;
default:
return - V_85 ;
}
F_4 ( V_2 , V_136 ,
V_137 |
V_138 |
V_139 , V_73 ) ;
F_4 ( V_2 , V_140 ,
V_141 , V_117 ) ;
return 0 ;
}
static int F_24 ( struct V_142 * V_143 ,
struct V_144 * V_145 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_146 ;
int V_147 ;
int V_148 ;
int V_149 ;
int V_150 ;
int V_151 ;
int V_152 , V_153 ;
int V_154 , V_155 , V_156 , V_157 , V_158 ;
V_2 = V_108 -> V_2 ;
V_35 = F_10 ( V_2 ) ;
switch ( V_108 -> V_111 ) {
case 0 :
V_146 = V_136 ;
V_147 = V_159 ;
V_149 = V_160 ;
if ( V_143 -> V_161 == V_162 ) {
V_148 = V_163 ;
} else {
V_148 = V_164 ;
F_3 ( V_2 -> V_9 , L_15 ) ;
}
break;
case 1 :
V_146 = V_165 ;
V_147 = V_166 ;
V_149 = V_167 ;
if ( V_143 -> V_161 == V_162 ) {
V_148 = V_168 ;
} else {
V_148 = V_169 ;
F_3 ( V_2 -> V_9 , L_16 ) ;
}
break;
default:
return - V_85 ;
}
V_150 = F_25 ( V_145 ) ;
if ( V_150 < 0 )
return V_150 ;
V_151 = 0 ;
switch ( F_26 ( V_145 ) ) {
case V_170 :
break;
case V_171 :
V_151 |= ( 0x1 << V_172 ) ;
break;
case V_173 :
V_151 |= ( 0x2 << V_172 ) ;
break;
case V_174 :
V_151 |= ( 0x3 << V_172 ) ;
break;
default:
F_14 ( V_108 -> V_9 , L_17 ,
F_26 ( V_145 ) ) ;
return - V_85 ;
}
for ( V_154 = 0 ; V_154 < F_27 ( V_175 ) ; ++ V_154 )
if ( V_175 [ V_154 ] == F_28 ( V_145 ) )
break;
if ( V_154 == F_27 ( V_175 ) ) {
F_14 ( V_108 -> V_9 , L_18 ,
F_28 ( V_145 ) ) ;
return - V_85 ;
}
V_155 = V_154 << V_176 ;
F_3 ( V_108 -> V_9 , L_19 , V_175 [ V_154 ] ) ;
F_3 ( V_108 -> V_9 , L_20 ,
V_108 -> V_111 + 1 , V_35 -> V_87 [ V_108 -> V_111 ] , V_150 ) ;
V_156 = 1 ;
V_157 = abs ( ( V_177 [ 1 ] * F_28 ( V_145 ) )
- V_35 -> V_87 [ V_108 -> V_111 ] ) ;
for ( V_154 = 2 ; V_154 < F_27 ( V_177 ) ; V_154 ++ ) {
V_158 = abs ( ( V_177 [ V_154 ] * F_28 ( V_145 ) )
- V_35 -> V_87 [ V_108 -> V_111 ] ) ;
if ( V_158 >= V_157 )
continue;
V_156 = V_154 ;
V_157 = V_158 ;
}
V_155 |= V_156 ;
F_3 ( V_108 -> V_9 , L_21 ,
V_108 -> V_111 + 1 , V_177 [ V_156 ] ) ;
V_156 = 0 ;
V_153 = 0 ;
for ( V_154 = 0 ; V_154 < F_27 ( V_178 ) ; V_154 ++ ) {
V_158 = ( V_35 -> V_87 [ V_108 -> V_111 ] * 10 / V_178 [ V_154 ] ) - V_150 ;
if ( V_158 < 0 )
break;
V_156 = V_154 ;
}
V_153 |= V_156 << V_179 ;
V_150 = V_35 -> V_87 [ V_108 -> V_111 ] * 10 / V_178 [ V_156 ] ;
F_3 ( V_108 -> V_9 , L_22 ,
V_178 [ V_156 ] , V_150 ) ;
V_152 = V_150 / F_28 ( V_145 ) ;
F_3 ( V_108 -> V_9 , L_23 ,
V_152 , V_150 / V_152 ) ;
F_4 ( V_2 , V_146 ,
V_180 , V_151 ) ;
F_4 ( V_2 , V_147 ,
V_181 , V_153 ) ;
F_4 ( V_2 , V_148 ,
V_182 , V_152 ) ;
F_4 ( V_2 , V_149 ,
V_183 |
V_184 , V_155 ) ;
return 0 ;
}
static int F_29 ( struct V_107 * V_185 , int V_186 )
{
struct V_1 * V_2 = V_185 -> V_2 ;
int V_5 , V_50 , V_51 ;
switch ( V_185 -> V_111 ) {
case 0 :
V_5 = V_140 ;
V_51 = V_187 ;
break;
case 1 :
V_5 = V_188 ;
V_51 = V_189 ;
break;
case 2 :
V_5 = V_190 ;
V_51 = V_191 ;
break;
default:
return - V_85 ;
}
if ( V_186 )
V_50 = V_51 ;
else
V_50 = 0 ;
return F_4 ( V_2 , V_5 , V_51 , V_50 ) ;
}
static int F_30 ( struct V_192 * V_82 ,
int V_193 , int V_194 )
{
T_1 V_195 ;
unsigned int V_196 , V_197 , V_198 ;
F_31 ( L_24 , V_193 , V_194 ) ;
V_82 -> V_199 = 0 ;
while ( V_193 > 13500000 ) {
V_82 -> V_199 ++ ;
V_193 /= 2 ;
if ( V_82 -> V_199 > 3 )
return - V_85 ;
}
F_31 ( L_25 , V_82 -> V_199 , V_193 ) ;
V_82 -> V_200 = 3 ;
while ( V_194 * ( V_82 -> V_200 + 1 ) < 90000000 ) {
V_82 -> V_200 ++ ;
if ( V_82 -> V_200 > 63 )
return - V_85 ;
}
V_194 *= V_82 -> V_200 + 1 ;
F_31 ( L_26 , V_82 -> V_200 , V_194 ) ;
if ( V_193 > 1000000 ) {
V_82 -> V_201 = 0 ;
} else if ( V_193 > 256000 ) {
V_82 -> V_201 = 1 ;
V_193 *= 2 ;
} else if ( V_193 > 128000 ) {
V_82 -> V_201 = 2 ;
V_193 *= 4 ;
} else if ( V_193 > 64000 ) {
V_82 -> V_201 = 3 ;
V_193 *= 8 ;
} else {
V_82 -> V_201 = 4 ;
V_193 *= 16 ;
}
F_31 ( L_27 , V_82 -> V_201 , V_193 ) ;
V_197 = V_194 / V_193 ;
V_82 -> V_202 = V_197 ;
V_198 = V_194 % V_193 ;
F_31 ( L_28 , V_198 ) ;
V_195 = V_203 * ( long long ) V_198 ;
F_32 ( V_195 , V_193 ) ;
V_196 = V_195 & 0xFFFFFFFF ;
if ( ( V_196 % 10 ) >= 5 )
V_196 += 5 ;
V_82 -> V_204 = V_196 / 10 ;
F_31 ( L_29 , V_82 -> V_202 , V_82 -> V_204 ) ;
return 0 ;
}
static int F_33 ( struct V_107 * V_108 , int V_111 ,
int V_205 , unsigned int V_193 ,
unsigned int V_194 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_206 , V_32 ;
struct V_192 V_82 ;
T_2 V_5 , V_151 , V_207 ;
V_2 = V_108 -> V_2 ;
V_35 = F_10 ( V_2 ) ;
V_151 = F_2 ( V_2 , V_88 )
& V_208 ;
V_207 = F_2 ( V_2 , V_209 )
& V_210 ;
switch ( V_111 ) {
case V_211 :
V_206 = 0 ;
V_111 = 0 ;
break;
case V_212 :
V_206 = 0x20 ;
V_111 = 1 ;
break;
default:
return - V_85 ;
}
switch ( V_205 ) {
case 0 :
if ( V_194 )
return - V_85 ;
break;
case V_213 :
case V_214 :
case V_215 :
case V_216 :
break;
default:
return - V_85 ;
}
if ( V_35 -> V_82 [ V_111 ] . V_205 == V_205 &&
V_35 -> V_82 [ V_111 ] . V_217 == V_193 && V_35 -> V_82 [ V_111 ] . V_83 == V_194 )
return 0 ;
if ( V_194 )
V_32 = F_30 ( & V_82 , V_193 , V_194 ) ;
else
V_32 = F_30 ( & V_82 , V_35 -> V_82 [ V_111 ] . V_217 ,
V_35 -> V_82 [ V_111 ] . V_83 ) ;
if ( V_32 < 0 )
return V_32 ;
F_4 ( V_2 , V_88 ,
V_218 , 0 ) ;
F_4 ( V_2 , V_209 ,
V_219 , 0 ) ;
F_4 ( V_2 , V_220 + V_206 ,
V_221 , 0 ) ;
V_5 = ( V_82 . V_200 << V_222 ) |
( V_82 . V_201 << V_223 ) ;
F_4 ( V_2 , V_224 + V_206 ,
V_225 |
V_226 , V_5 ) ;
F_12 ( V_2 , V_227 + V_206 , V_82 . V_204 ) ;
F_4 ( V_2 , V_228 + V_206 ,
V_229 ,
V_82 . V_202 << V_230 ) ;
F_4 ( V_2 , V_231 + V_206 ,
V_232 |
V_233 ,
( V_82 . V_199 << V_234 ) |
( V_205 - 1 ) ) ;
if ( V_194 )
F_4 ( V_2 , V_220 + V_206 ,
V_221 , V_235 ) ;
V_35 -> V_82 [ V_111 ] . V_217 = V_193 ;
V_35 -> V_82 [ V_111 ] . V_83 = V_194 ;
V_35 -> V_82 [ V_111 ] . V_205 = V_205 ;
F_4 ( V_2 , V_88 ,
V_218 , V_151 ) ;
F_4 ( V_2 , V_209 ,
V_219 , V_207 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_107 * V_108 ,
int V_236 , unsigned int V_237 , int V_238 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_2 = V_108 -> V_2 ;
V_35 = F_10 ( V_2 ) ;
switch ( V_108 -> V_111 ) {
case 0 :
case 1 :
break;
default:
return - V_85 ;
}
switch ( V_236 ) {
case V_78 :
V_35 -> V_77 [ V_108 -> V_111 ] = V_78 ;
V_35 -> V_79 [ 0 ] = V_237 ;
F_3 ( V_108 -> V_9 , L_30 ,
V_108 -> V_111 + 1 , V_237 ) ;
break;
case V_80 :
V_35 -> V_77 [ V_108 -> V_111 ] = V_78 ;
V_35 -> V_79 [ 1 ] = V_237 ;
F_3 ( V_108 -> V_9 , L_31 ,
V_108 -> V_111 + 1 , V_237 ) ;
break;
case V_81 :
V_35 -> V_77 [ V_108 -> V_111 ] = V_81 ;
F_3 ( V_108 -> V_9 , L_32 , V_108 -> V_111 + 1 ) ;
break;
case V_84 :
V_35 -> V_77 [ V_108 -> V_111 ] = V_84 ;
F_3 ( V_108 -> V_9 , L_33 , V_108 -> V_111 + 1 ) ;
break;
case V_239 :
default:
F_14 ( V_108 -> V_9 , L_34 , V_236 ) ;
return - V_85 ;
}
F_18 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
enum V_240 V_241 )
{
struct V_34 * V_35 ;
int V_32 ;
V_35 = F_10 ( V_2 ) ;
switch ( V_241 ) {
case V_242 :
case V_243 :
break;
case V_244 :
if ( V_2 -> V_94 . V_245 == V_246 ) {
V_32 = F_36 ( F_27 ( V_35 -> V_247 ) ,
V_35 -> V_247 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_37 ( V_2 ) ;
if ( V_32 ) {
F_14 ( V_2 -> V_9 ,
L_35 , V_32 ) ;
return V_32 ;
}
F_4 ( V_2 , V_37 ,
V_248 , V_249 ) ;
}
break;
case V_246 :
F_4 ( V_2 , V_37 ,
V_248 , 0 ) ;
F_38 ( F_27 ( V_35 -> V_247 ) ,
V_35 -> V_247 ) ;
break;
}
V_2 -> V_94 . V_245 = V_241 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_3 V_250 )
{
F_35 ( V_2 , V_246 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_244 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_154 ;
V_35 = F_10 ( V_2 ) ;
F_35 ( V_2 , V_246 ) ;
for ( V_154 = 0 ; V_154 < F_27 ( V_35 -> V_247 ) ; ++ V_154 )
F_42 ( V_35 -> V_247 [ V_154 ] . V_251 ,
& V_35 -> V_252 [ V_154 ] ) ;
F_43 ( F_27 ( V_35 -> V_247 ) , V_35 -> V_247 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_154 ;
int V_32 ;
V_2 -> V_94 . V_253 = 1 ;
V_35 = F_10 ( V_2 ) ;
V_35 -> V_2 = V_2 ;
V_32 = F_45 ( V_2 , 16 , 16 , V_35 -> V_254 ) ;
if ( V_32 < 0 ) {
F_14 ( V_2 -> V_9 , L_36 , V_32 ) ;
return V_32 ;
}
for ( V_154 = 0 ; V_154 < F_27 ( V_35 -> V_247 ) ; V_154 ++ )
V_35 -> V_247 [ V_154 ] . V_255 = V_256 [ V_154 ] ;
V_32 = F_46 ( V_2 -> V_9 , F_27 ( V_35 -> V_247 ) ,
V_35 -> V_247 ) ;
if ( V_32 ) {
F_14 ( V_2 -> V_9 , L_37 , V_32 ) ;
return V_32 ;
}
V_35 -> V_252 [ 0 ] . V_257 = V_258 ;
V_35 -> V_252 [ 1 ] . V_257 = V_259 ;
V_35 -> V_252 [ 2 ] . V_257 = V_260 ;
V_35 -> V_252 [ 3 ] . V_257 = V_261 ;
V_35 -> V_252 [ 4 ] . V_257 = V_262 ;
V_35 -> V_252 [ 5 ] . V_257 = V_263 ;
V_35 -> V_252 [ 6 ] . V_257 = V_264 ;
V_35 -> V_252 [ 7 ] . V_257 = V_265 ;
for ( V_154 = 0 ; V_154 < F_27 ( V_35 -> V_247 ) ; V_154 ++ ) {
V_32 = F_47 ( V_35 -> V_247 [ V_154 ] . V_251 ,
& V_35 -> V_252 [ V_154 ] ) ;
if ( V_32 ) {
F_14 ( V_2 -> V_9 ,
L_38 ,
V_32 ) ;
}
}
V_32 = F_36 ( F_27 ( V_35 -> V_247 ) ,
V_35 -> V_247 ) ;
if ( V_32 ) {
F_14 ( V_2 -> V_9 , L_39 , V_32 ) ;
goto V_266;
}
V_32 = F_2 ( V_2 , V_97 ) ;
if ( V_32 < 0 ) {
F_14 ( V_2 -> V_9 , L_40 , V_32 ) ;
goto V_267;
}
if ( V_32 != 0x8995 ) {
F_14 ( V_2 -> V_9 , L_41 , V_32 ) ;
V_32 = - V_85 ;
goto V_267;
}
V_32 = F_12 ( V_2 , V_97 , 0 ) ;
if ( V_32 < 0 ) {
F_14 ( V_2 -> V_9 , L_42 , V_32 ) ;
goto V_267;
}
F_35 ( V_2 , V_244 ) ;
F_4 ( V_2 , V_268 ,
V_269 , V_270 ) ;
F_4 ( V_2 , V_271 ,
V_272 , V_273 ) ;
F_4 ( V_2 , V_274 ,
V_275 , V_276 ) ;
F_4 ( V_2 , V_277 ,
V_278 , V_279 ) ;
F_4 ( V_2 , V_280 ,
V_281 , V_282 ) ;
F_4 ( V_2 , V_283 ,
V_284 , V_282 ) ;
F_4 ( V_2 , V_285 ,
V_286 , V_287 ) ;
F_4 ( V_2 , V_288 ,
V_289 , V_290 ) ;
F_4 ( V_2 , V_291 ,
V_292 , V_293 ) ;
F_1 ( V_2 ) ;
F_48 ( V_2 , V_294 ,
F_27 ( V_294 ) ) ;
F_49 ( & V_2 -> V_94 , V_295 ,
F_27 ( V_295 ) ) ;
F_50 ( & V_2 -> V_94 , V_296 ,
F_27 ( V_296 ) ) ;
return 0 ;
V_267:
F_38 ( F_27 ( V_35 -> V_247 ) , V_35 -> V_247 ) ;
V_266:
F_43 ( F_27 ( V_35 -> V_247 ) , V_35 -> V_247 ) ;
return V_32 ;
}
static int T_4 F_51 ( struct V_297 * V_298 )
{
struct V_34 * V_35 ;
int V_32 ;
V_35 = F_52 ( sizeof *V_35 , V_299 ) ;
if ( ! V_35 )
return - V_300 ;
V_35 -> V_254 = V_301 ;
F_53 ( V_298 , V_35 ) ;
V_32 = F_54 ( & V_298 -> V_9 ,
& V_302 , V_303 ,
F_27 ( V_303 ) ) ;
if ( V_32 < 0 )
F_55 ( V_35 ) ;
return V_32 ;
}
static int T_5 F_56 ( struct V_297 * V_298 )
{
F_57 ( & V_298 -> V_9 ) ;
F_55 ( F_58 ( V_298 ) ) ;
return 0 ;
}
static T_4 int F_59 ( struct V_304 * V_305 ,
const struct V_306 * V_111 )
{
struct V_34 * V_35 ;
int V_32 ;
V_35 = F_52 ( sizeof *V_35 , V_299 ) ;
if ( ! V_35 )
return - V_300 ;
V_35 -> V_254 = V_307 ;
F_60 ( V_305 , V_35 ) ;
V_32 = F_54 ( & V_305 -> V_9 ,
& V_302 , V_303 ,
F_27 ( V_303 ) ) ;
if ( V_32 < 0 )
F_55 ( V_35 ) ;
return V_32 ;
}
static T_5 int F_61 ( struct V_304 * V_308 )
{
F_57 ( & V_308 -> V_9 ) ;
F_55 ( F_62 ( V_308 ) ) ;
return 0 ;
}
static int T_6 F_63 ( void )
{
int V_32 = 0 ;
#if F_64 ( V_309 ) || F_64 ( V_310 )
V_32 = F_65 ( & V_311 ) ;
if ( V_32 ) {
F_66 ( V_312 L_43 ,
V_32 ) ;
}
#endif
#if F_64 ( V_313 )
V_32 = F_67 ( & V_314 ) ;
if ( V_32 ) {
F_66 ( V_312 L_44 ,
V_32 ) ;
}
#endif
return V_32 ;
}
static void T_7 F_68 ( void )
{
#if F_64 ( V_309 ) || F_64 ( V_310 )
F_69 ( & V_311 ) ;
#endif
#if F_64 ( V_313 )
F_70 ( & V_314 ) ;
#endif
}
