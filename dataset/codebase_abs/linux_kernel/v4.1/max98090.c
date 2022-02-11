static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
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
case V_67 ... V_67 + 0x68 :
case V_68 ... V_68 + 0x0E :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 ... V_74 + 0x0E :
case V_7 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_75 * V_76 )
{
int V_77 ;
V_77 = F_4 ( V_76 -> V_78 , V_4 ,
V_79 ) ;
if ( V_77 < 0 ) {
F_5 ( V_76 -> V_80 -> V_2 ,
L_1 , V_77 ) ;
return V_77 ;
}
F_6 ( 20 ) ;
return V_77 ;
}
static int F_7 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_80 = F_8 ( V_82 ) ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_86 * V_87 =
(struct V_86 * ) V_82 -> V_88 ;
unsigned int V_89 = ( 1 << F_10 ( V_87 -> V_90 ) ) - 1 ;
unsigned int V_91 = F_11 ( V_80 , V_87 -> V_3 ) ;
unsigned int * V_92 ;
switch ( V_87 -> V_3 ) {
case V_13 :
V_92 = & ( V_76 -> V_93 ) ;
break;
case V_14 :
V_92 = & ( V_76 -> V_94 ) ;
break;
case V_23 :
V_92 = & ( V_76 -> V_95 ) ;
break;
default:
return - V_96 ;
}
V_91 = ( V_91 >> V_87 -> V_97 ) & V_89 ;
if ( V_91 >= 1 ) {
V_91 = V_91 - 1 ;
* V_92 = V_91 ;
} else {
V_91 = * V_92 ;
}
V_84 -> V_98 . integer . V_98 [ 0 ] = V_91 ;
return 0 ;
}
static int F_12 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_80 = F_8 ( V_82 ) ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_86 * V_87 =
(struct V_86 * ) V_82 -> V_88 ;
unsigned int V_89 = ( 1 << F_10 ( V_87 -> V_90 ) ) - 1 ;
unsigned int V_99 = V_84 -> V_98 . integer . V_98 [ 0 ] ;
unsigned int V_91 = F_11 ( V_80 , V_87 -> V_3 ) ;
unsigned int * V_92 ;
switch ( V_87 -> V_3 ) {
case V_13 :
V_92 = & ( V_76 -> V_93 ) ;
break;
case V_14 :
V_92 = & ( V_76 -> V_94 ) ;
break;
case V_23 :
V_92 = & ( V_76 -> V_95 ) ;
break;
default:
return - V_96 ;
}
V_91 = ( V_91 >> V_87 -> V_97 ) & V_89 ;
* V_92 = V_99 ;
if ( V_91 >= 1 ) {
V_99 = V_99 + 1 ;
} else {
V_99 = V_91 ;
}
F_13 ( V_80 , V_87 -> V_3 ,
V_89 << V_87 -> V_97 ,
V_99 << V_87 -> V_97 ) ;
return 0 ;
}
static int F_14 ( struct V_100 * V_101 ,
struct V_81 * V_82 , int V_102 )
{
struct V_85 * V_80 = F_15 ( V_101 -> V_103 ) ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
unsigned int V_91 = F_11 ( V_80 , V_101 -> V_3 ) ;
if ( V_101 -> V_3 == V_13 )
V_91 = ( V_91 & V_104 ) >> V_105 ;
else
V_91 = ( V_91 & V_106 ) >> V_107 ;
if ( V_91 >= 1 ) {
if ( V_101 -> V_3 == V_13 ) {
V_76 -> V_93 = V_91 - 1 ;
} else {
V_76 -> V_94 = V_91 - 1 ;
}
}
switch ( V_102 ) {
case V_108 :
if ( V_101 -> V_3 == V_13 )
V_91 = V_76 -> V_93 + 1 ;
else
V_91 = V_76 -> V_94 + 1 ;
break;
case V_109 :
V_91 = 0 ;
break;
default:
return - V_96 ;
}
if ( V_101 -> V_3 == V_13 )
F_13 ( V_80 , V_101 -> V_3 , V_104 ,
V_91 << V_105 ) ;
else
F_13 ( V_80 , V_101 -> V_3 , V_106 ,
V_91 << V_107 ) ;
return 0 ;
}
static int F_16 ( struct V_85 * V_80 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_110 * V_103 = & V_80 -> V_103 ;
F_17 ( V_80 , V_111 ,
F_18 ( V_111 ) ) ;
if ( V_76 -> V_112 == V_113 ) {
F_17 ( V_80 , V_114 ,
F_18 ( V_114 ) ) ;
}
F_19 ( V_103 , V_115 ,
F_18 ( V_115 ) ) ;
F_20 ( V_103 , V_116 ,
F_18 ( V_116 ) ) ;
if ( V_76 -> V_112 == V_113 ) {
F_19 ( V_103 , V_117 ,
F_18 ( V_117 ) ) ;
F_20 ( V_103 , V_118 ,
F_18 ( V_118 ) ) ;
}
return 0 ;
}
static void F_21 ( struct V_85 * V_80 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
unsigned long long V_119 ;
int V_120 ;
if ( ! V_76 -> V_121 ) {
F_5 ( V_80 -> V_2 , L_2 ) ;
return;
}
if ( ! V_76 -> V_122 || ! V_76 -> V_123 ) {
F_5 ( V_80 -> V_2 , L_3 ) ;
return;
}
if ( ! ( F_11 ( V_80 , V_30 ) &
V_124 ) ) {
return;
}
for ( V_120 = 0 ; V_120 < F_18 ( V_125 ) ; V_120 ++ ) {
if ( ( V_125 [ V_120 ] == V_76 -> V_121 ) &&
( V_126 [ V_120 ] == V_76 -> V_123 ) ) {
F_22 ( V_80 -> V_2 ,
L_4 ,
V_120 + 0x8 ) ;
F_13 ( V_80 , V_25 ,
V_127 ,
( V_120 + 0x8 ) << V_128 ) ;
F_13 ( V_80 , V_25 ,
V_129 , 0 ) ;
return;
}
}
for ( V_120 = 0 ; V_120 < F_18 ( V_130 ) ; V_120 ++ ) {
if ( ( V_130 [ V_120 ] == V_76 -> V_121 ) &&
( V_131 [ V_120 ] == V_76 -> V_123 ) ) {
F_22 ( V_80 -> V_2 ,
L_5 ) ;
F_22 ( V_80 -> V_2 , L_6 ,
V_120 , V_132 [ V_120 ] , V_133 [ V_120 ] ) ;
F_13 ( V_80 , V_25 ,
V_127 , 0 ) ;
F_13 ( V_80 , V_25 ,
V_129 ,
1 << V_134 ) ;
F_23 ( V_80 , V_26 ,
( V_132 [ V_120 ] >> 8 ) & 0x7F ) ;
F_23 ( V_80 , V_27 ,
V_132 [ V_120 ] & 0xFF ) ;
F_23 ( V_80 , V_28 ,
( V_133 [ V_120 ] >> 8 ) & 0x7F ) ;
F_23 ( V_80 , V_29 ,
V_133 [ V_120 ] & 0xFF ) ;
return;
}
}
F_13 ( V_80 , V_25 ,
V_127 , 0 ) ;
F_13 ( V_80 , V_25 ,
V_129 , 0 ) ;
V_119 = 65536ULL * ( V_76 -> V_123 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_76 -> V_123 ;
F_24 ( V_119 , ( unsigned long long int ) V_76 -> V_121 ) ;
F_25 ( V_80 -> V_2 , L_7 ) ;
F_25 ( V_80 -> V_2 , L_8 , V_119 ) ;
F_23 ( V_80 , V_26 ,
( V_119 >> 8 ) & 0x7F ) ;
F_23 ( V_80 , V_27 , V_119 & 0xFF ) ;
}
static int F_26 ( struct V_135 * V_136 ,
unsigned int V_137 )
{
struct V_85 * V_80 = V_136 -> V_80 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
T_1 V_140 ;
V_76 -> V_141 = V_137 ;
V_139 = & V_76 -> V_142 [ 0 ] ;
if ( V_137 != V_139 -> V_137 ) {
V_139 -> V_137 = V_137 ;
V_140 = 0 ;
switch ( V_137 & V_143 ) {
case V_144 :
F_23 ( V_80 ,
V_26 , 0x00 ) ;
F_23 ( V_80 ,
V_27 , 0x00 ) ;
F_13 ( V_80 , V_25 ,
V_129 , 0 ) ;
V_76 -> V_145 = false ;
break;
case V_146 :
if ( V_76 -> V_147 == 4 ) {
V_140 |= V_124 |
V_148 ;
} else if ( V_76 -> V_147 == 3 ) {
V_140 |= V_124 |
V_149 ;
} else {
V_140 |= V_124 |
V_150 ;
}
V_76 -> V_145 = true ;
break;
case V_151 :
case V_152 :
default:
F_5 ( V_80 -> V_2 , L_9 ) ;
return - V_96 ;
}
F_23 ( V_80 , V_30 , V_140 ) ;
V_140 = 0 ;
switch ( V_137 & V_153 ) {
case V_154 :
V_140 |= V_155 ;
break;
case V_156 :
break;
case V_157 :
V_140 |= V_158 ;
break;
case V_159 :
default:
F_5 ( V_80 -> V_2 , L_10 ) ;
return - V_96 ;
}
switch ( V_137 & V_160 ) {
case V_161 :
break;
case V_162 :
V_140 |= V_163 ;
break;
case V_164 :
V_140 |= V_165 ;
break;
case V_166 :
V_140 |= V_165 | V_163 ;
break;
default:
F_5 ( V_80 -> V_2 , L_11 ) ;
return - V_96 ;
}
if ( V_76 -> V_147 > 1 )
V_140 ^= V_165 ;
F_23 ( V_80 ,
V_31 , V_140 ) ;
}
return 0 ;
}
static int F_27 ( struct V_135 * V_136 ,
unsigned int V_167 , unsigned int V_168 , int V_169 , int V_170 )
{
struct V_85 * V_80 = V_136 -> V_80 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
V_139 = & V_76 -> V_142 [ 0 ] ;
if ( V_169 < 0 || V_169 > 4 )
return - V_96 ;
V_76 -> V_147 = V_169 ;
V_76 -> V_171 = V_170 ;
if ( V_76 -> V_147 > 1 ) {
F_23 ( V_80 , V_33 ,
0 << V_172 |
1 << V_173 |
0 << V_174 ) ;
F_13 ( V_80 , V_32 ,
V_175 ,
V_175 ) ;
}
V_139 -> V_137 = 0 ;
F_26 ( V_136 , V_76 -> V_141 ) ;
return 0 ;
}
static int F_28 ( struct V_85 * V_80 ,
enum V_176 V_177 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
int V_77 ;
switch ( V_177 ) {
case V_178 :
break;
case V_179 :
if ( ! F_29 ( V_76 -> V_180 ) ) {
if ( V_80 -> V_103 . V_181 == V_178 )
F_30 ( V_76 -> V_180 ) ;
else
F_31 ( V_76 -> V_180 ) ;
}
break;
case V_182 :
if ( V_80 -> V_103 . V_181 == V_183 ) {
V_77 = F_32 ( V_76 -> V_78 ) ;
if ( V_77 != 0 ) {
F_5 ( V_80 -> V_2 ,
L_12 , V_77 ) ;
return V_77 ;
}
}
break;
case V_183 :
F_13 ( V_80 , V_58 ,
V_184 , V_184 ) ;
F_33 ( V_76 -> V_78 ) ;
break;
}
V_80 -> V_103 . V_181 = V_177 ;
return 0 ;
}
static int F_34 ( int V_185 , int V_186 )
{
int V_187 = V_188 ;
int V_189 = V_188 ;
int V_190 = 0 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < F_18 ( V_191 ) ; V_120 ++ ) {
V_189 = abs ( V_185 - ( V_186 / V_191 [ V_120 ] ) ) ;
if ( V_189 < V_187 ) {
V_187 = V_189 ;
V_190 = V_120 ;
}
}
return V_190 ;
}
static int F_35 ( int V_186 )
{
int V_192 ;
int V_193 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < F_18 ( V_194 ) ; V_120 ++ ) {
if ( V_186 == V_194 [ V_120 ] . V_186 )
return V_120 ;
if ( V_186 < V_194 [ V_120 ] . V_186 ) {
if ( V_120 == 0 )
return V_120 ;
V_192 = V_186 - V_194 [ V_120 - 1 ] . V_186 ;
V_193 = V_194 [ V_120 ] . V_186 - V_186 ;
if ( V_192 < V_193 )
return V_120 - 1 ;
else
return V_120 ;
}
}
return - V_96 ;
}
static int F_36 ( struct V_75 * V_76 ,
int V_195 , int V_186 , int V_196 )
{
int V_197 ;
int V_198 ;
int V_199 ;
int V_200 ;
int V_120 ;
V_198 = F_35 ( V_186 ) ;
if ( V_198 < 0 )
return V_198 ;
V_197 = F_34 ( V_195 , V_186 ) ;
for ( V_120 = 0 ; V_120 < F_18 ( V_201 ) - 1 ; V_120 ++ ) {
if ( V_196 <= ( V_201 [ V_120 ] + V_201 [ V_120 + 1 ] ) / 2 )
break;
}
V_199 = V_194 [ V_198 ] . V_202 [ V_197 ] . V_203 ;
V_200 = V_194 [ V_198 ] . V_202 [ V_197 ] . V_204 [ V_120 ] ;
F_37 ( V_76 -> V_78 , V_16 ,
V_205 ,
V_197 << V_206 ) ;
F_37 ( V_76 -> V_78 , V_17 ,
V_207 | V_208 ,
V_200 << V_209 |
V_199 << V_210 ) ;
return 0 ;
}
static int F_38 ( struct V_211 * V_212 ,
struct V_213 * V_214 ,
struct V_135 * V_142 )
{
struct V_85 * V_80 = V_142 -> V_80 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
V_139 = & V_76 -> V_142 [ 0 ] ;
V_76 -> V_122 = F_39 ( V_214 ) ;
if ( F_40 ( V_214 ) == 1 )
V_76 -> V_122 *= 2 ;
V_76 -> V_123 = F_41 ( V_214 ) ;
switch ( F_42 ( V_214 ) ) {
case 16 :
F_13 ( V_80 , V_31 ,
V_215 , 0 ) ;
break;
default:
return - V_96 ;
}
if ( V_76 -> V_145 )
F_21 ( V_80 ) ;
V_139 -> V_216 = V_76 -> V_123 ;
if ( V_76 -> V_123 < 24000 )
F_13 ( V_80 , V_35 ,
V_217 , 0 ) ;
else
F_13 ( V_80 , V_35 ,
V_217 , V_217 ) ;
if ( V_76 -> V_123 < 50000 )
F_13 ( V_80 , V_35 ,
V_218 , 0 ) ;
else
F_13 ( V_80 , V_35 ,
V_218 , V_218 ) ;
F_36 ( V_76 , V_76 -> V_199 , V_76 -> V_186 ,
V_76 -> V_123 ) ;
return 0 ;
}
static int F_43 ( struct V_135 * V_142 ,
int V_219 , unsigned int V_203 , int V_220 )
{
struct V_85 * V_80 = V_142 -> V_80 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
if ( V_203 == V_76 -> V_121 )
return 0 ;
if ( ! F_29 ( V_76 -> V_180 ) ) {
V_203 = F_44 ( V_76 -> V_180 , V_203 ) ;
F_45 ( V_76 -> V_180 , V_203 ) ;
}
if ( ( V_203 >= 10000000 ) && ( V_203 <= 20000000 ) ) {
F_23 ( V_80 , V_24 ,
V_221 ) ;
V_76 -> V_186 = V_203 ;
} else if ( ( V_203 > 20000000 ) && ( V_203 <= 40000000 ) ) {
F_23 ( V_80 , V_24 ,
V_222 ) ;
V_76 -> V_186 = V_203 >> 1 ;
} else if ( ( V_203 > 40000000 ) && ( V_203 <= 60000000 ) ) {
F_23 ( V_80 , V_24 ,
V_223 ) ;
V_76 -> V_186 = V_203 >> 2 ;
} else {
F_5 ( V_80 -> V_2 , L_13 ) ;
return - V_96 ;
}
V_76 -> V_121 = V_203 ;
return 0 ;
}
static int F_46 ( struct V_135 * V_136 , int V_224 )
{
struct V_85 * V_80 = V_136 -> V_80 ;
int V_140 ;
V_140 = V_224 ? V_225 : 0 ;
F_13 ( V_80 , V_36 ,
V_225 , V_140 ) ;
return 0 ;
}
static int F_47 ( struct V_211 * V_212 , int V_226 ,
struct V_135 * V_142 )
{
struct V_85 * V_80 = V_142 -> V_80 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
switch ( V_226 ) {
case V_227 :
case V_228 :
case V_229 :
if ( ! V_76 -> V_145 && V_142 -> V_230 == 1 )
F_48 ( V_231 ,
& V_76 -> V_232 ,
F_49 ( 10 ) ) ;
break;
case V_233 :
case V_234 :
case V_235 :
if ( ! V_76 -> V_145 && V_142 -> V_230 == 1 )
F_50 ( & V_76 -> V_236 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_51 ( struct V_237 * V_238 )
{
struct V_75 * V_76 =
F_52 ( V_238 , struct V_75 ,
V_232 . V_238 ) ;
struct V_85 * V_80 = V_76 -> V_80 ;
unsigned int V_239 , V_89 ;
F_53 ( V_76 -> V_78 , V_5 , & V_239 ) ;
F_53 ( V_76 -> V_78 , V_8 , & V_89 ) ;
V_239 &= V_89 ;
if ( V_239 & V_240 )
F_48 ( V_231 ,
& V_76 -> V_241 ,
F_49 ( 100 ) ) ;
F_13 ( V_80 , V_8 ,
V_242 ,
1 << V_243 ) ;
}
static void F_54 ( struct V_237 * V_238 )
{
struct V_75 * V_76 =
F_52 ( V_238 , struct V_75 , V_236 ) ;
struct V_85 * V_80 = V_76 -> V_80 ;
F_55 ( & V_76 -> V_232 ) ;
F_13 ( V_80 , V_8 ,
V_242 , 0 ) ;
}
static void F_56 ( struct V_237 * V_238 )
{
struct V_75 * V_76 =
F_52 ( V_238 , struct V_75 , V_244 ) ;
struct V_85 * V_80 = V_76 -> V_80 ;
if ( ! F_57 ( V_80 ) )
return;
F_25 ( V_80 -> V_2 , L_14 ) ;
F_13 ( V_80 , V_66 ,
V_245 , 0 ) ;
F_6 ( 10 ) ;
F_13 ( V_80 , V_66 ,
V_245 , V_245 ) ;
F_6 ( 10 ) ;
}
static void F_58 ( struct V_237 * V_238 )
{
struct V_75 * V_76 = F_52 ( V_238 ,
struct V_75 ,
V_241 . V_238 ) ;
struct V_85 * V_80 = V_76 -> V_80 ;
struct V_110 * V_103 = & V_80 -> V_103 ;
int V_239 = 0 ;
int V_3 ;
if ( V_76 -> V_246 == V_247 ) {
F_13 ( V_80 , V_58 ,
V_184 , 0 ) ;
F_6 ( 50 ) ;
V_3 = F_11 ( V_80 , V_6 ) ;
F_13 ( V_80 , V_58 ,
V_184 , V_184 ) ;
} else {
V_3 = F_11 ( V_80 , V_6 ) ;
}
V_3 = F_11 ( V_80 , V_6 ) ;
switch ( V_3 & ( V_248 | V_249 ) ) {
case V_248 | V_249 :
F_22 ( V_80 -> V_2 , L_15 ) ;
V_76 -> V_246 = V_247 ;
V_239 |= 0 ;
break;
case 0 :
if ( V_76 -> V_246 ==
V_250 ) {
F_22 ( V_80 -> V_2 ,
L_16 ) ;
V_239 |= V_251 ;
V_239 |= V_252 ;
break;
}
F_22 ( V_80 -> V_2 , L_17 ) ;
V_76 -> V_246 = V_253 ;
V_239 |= V_254 ;
break;
case V_249 :
F_22 ( V_80 -> V_2 , L_18 ) ;
V_76 -> V_246 = V_250 ;
V_239 |= V_251 ;
break;
default:
F_22 ( V_80 -> V_2 , L_19 ) ;
break;
}
F_59 ( V_76 -> V_255 , V_239 ,
V_251 | V_252 ) ;
F_60 ( V_103 ) ;
}
static T_2 F_61 ( int V_256 , void * V_257 )
{
struct V_75 * V_76 = V_257 ;
struct V_85 * V_80 = V_76 -> V_80 ;
int V_77 ;
unsigned int V_89 ;
unsigned int V_230 ;
if ( V_80 == NULL )
return V_258 ;
F_22 ( V_80 -> V_2 , L_20 ) ;
V_77 = F_53 ( V_76 -> V_78 , V_8 , & V_89 ) ;
if ( V_77 != 0 ) {
F_5 ( V_80 -> V_2 ,
L_21 ,
V_77 ) ;
return V_258 ;
}
V_77 = F_53 ( V_76 -> V_78 , V_5 , & V_230 ) ;
if ( V_77 != 0 ) {
F_5 ( V_80 -> V_2 ,
L_22 ,
V_77 ) ;
return V_258 ;
}
F_22 ( V_80 -> V_2 , L_23 ,
V_230 , V_89 , V_230 & V_89 ) ;
V_230 &= V_89 ;
if ( ! V_230 )
return V_258 ;
if ( V_230 & V_259 )
F_5 ( V_80 -> V_2 , L_24 ) ;
if ( V_230 & V_260 )
F_22 ( V_80 -> V_2 , L_25 ) ;
if ( V_230 & V_261 ) {
F_22 ( V_80 -> V_2 , L_26 ) ;
F_50 ( & V_76 -> V_244 ) ;
}
if ( V_230 & V_240 ) {
F_22 ( V_80 -> V_2 , L_27 ) ;
F_62 ( V_80 -> V_2 , 100 ) ;
F_48 ( V_231 ,
& V_76 -> V_241 ,
F_49 ( 100 ) ) ;
}
if ( V_230 & V_262 )
F_22 ( V_80 -> V_2 , L_28 ) ;
if ( V_230 & V_263 )
F_5 ( V_80 -> V_2 , L_29 ) ;
return V_264 ;
}
int F_63 ( struct V_85 * V_80 ,
struct V_265 * V_255 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
F_22 ( V_80 -> V_2 , L_30 ) ;
V_76 -> V_255 = V_255 ;
if ( V_255 ) {
F_13 ( V_80 , V_8 ,
V_266 ,
1 << V_267 ) ;
} else {
F_13 ( V_80 , V_8 ,
V_266 ,
0 ) ;
}
F_59 ( V_76 -> V_255 , 0 ,
V_251 | V_252 ) ;
F_48 ( V_231 ,
& V_76 -> V_241 ,
F_49 ( 100 ) ) ;
return 0 ;
}
static int F_64 ( struct V_85 * V_80 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
enum V_268 V_112 ;
int V_77 = 0 ;
F_22 ( V_80 -> V_2 , L_31 ) ;
V_76 -> V_180 = F_65 ( V_80 -> V_2 , L_32 ) ;
if ( F_66 ( V_76 -> V_180 ) == - V_269 )
return - V_269 ;
V_76 -> V_80 = V_80 ;
F_3 ( V_76 ) ;
V_76 -> V_121 = ( unsigned ) - 1 ;
V_76 -> V_186 = ( unsigned ) - 1 ;
V_76 -> V_145 = false ;
V_139 = & V_76 -> V_142 [ 0 ] ;
V_139 -> V_216 = ( unsigned ) - 1 ;
V_139 -> V_137 = ( unsigned ) - 1 ;
V_76 -> V_270 = 0 ;
V_76 -> V_93 = 0 ;
V_76 -> V_94 = 0 ;
V_77 = F_11 ( V_80 , V_7 ) ;
if ( V_77 < 0 ) {
F_5 ( V_80 -> V_2 , L_33 ,
V_77 ) ;
goto V_271;
}
if ( ( V_77 >= V_272 ) && ( V_77 <= V_272 + 0x0f ) ) {
V_112 = V_273 ;
F_25 ( V_80 -> V_2 , L_34 , V_77 ) ;
} else if ( ( V_77 >= V_274 ) && ( V_77 <= V_274 + 0x0f ) ) {
V_112 = V_113 ;
F_25 ( V_80 -> V_2 , L_35 , V_77 ) ;
} else {
V_112 = V_273 ;
F_5 ( V_80 -> V_2 , L_36 , V_77 ) ;
}
if ( V_76 -> V_112 != V_112 ) {
F_67 ( V_80 -> V_2 , L_37 ) ;
V_76 -> V_112 = V_112 ;
}
V_76 -> V_246 = V_247 ;
F_68 ( & V_76 -> V_241 , F_58 ) ;
F_68 ( & V_76 -> V_232 ,
F_51 ) ;
F_69 ( & V_76 -> V_236 ,
F_54 ) ;
F_69 ( & V_76 -> V_244 , F_56 ) ;
F_23 ( V_80 , V_58 ,
V_275 | V_276 ) ;
F_11 ( V_80 , V_5 ) ;
F_13 ( V_80 , V_64 ,
V_277 ,
1 << V_278 ) ;
F_13 ( V_80 , V_64 ,
V_279 ,
0 << V_280 ) ;
F_13 ( V_80 , V_65 ,
V_281 ,
1 << V_282 ) ;
F_23 ( V_80 , V_63 ,
V_283 ) ;
F_13 ( V_80 , V_15 ,
V_284 , V_285 ) ;
F_16 ( V_80 ) ;
V_271:
return V_77 ;
}
static int F_70 ( struct V_85 * V_80 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
F_55 ( & V_76 -> V_241 ) ;
F_55 ( & V_76 -> V_232 ) ;
F_71 ( & V_76 -> V_236 ) ;
F_71 ( & V_76 -> V_244 ) ;
V_76 -> V_80 = NULL ;
return 0 ;
}
static int F_72 ( struct V_286 * V_287 ,
const struct V_288 * V_289 )
{
struct V_75 * V_76 ;
const struct V_290 * V_291 ;
T_3 V_292 = 0 ;
int V_77 ;
F_73 ( L_38 ) ;
V_76 = F_74 ( & V_287 -> V_2 , sizeof( struct V_75 ) ,
V_293 ) ;
if ( V_76 == NULL )
return - V_294 ;
if ( F_75 ( & V_287 -> V_2 ) ) {
V_291 = F_76 ( V_287 -> V_2 . V_295 -> V_296 ,
& V_287 -> V_2 ) ;
if ( ! V_291 ) {
F_5 ( & V_287 -> V_2 , L_39 ) ;
return - V_96 ;
}
V_292 = V_291 -> V_292 ;
} else if ( V_289 ) {
V_292 = V_289 -> V_292 ;
}
V_76 -> V_112 = V_292 ;
F_77 ( V_287 , V_76 ) ;
V_76 -> V_297 = V_287 -> V_2 . V_298 ;
V_77 = F_78 ( V_287 -> V_2 . V_299 , L_40 ,
& V_76 -> V_199 ) ;
if ( V_77 < 0 )
V_76 -> V_199 = V_300 ;
V_76 -> V_78 = F_79 ( V_287 , & V_301 ) ;
if ( F_29 ( V_76 -> V_78 ) ) {
V_77 = F_66 ( V_76 -> V_78 ) ;
F_5 ( & V_287 -> V_2 , L_41 , V_77 ) ;
goto V_302;
}
V_77 = F_80 ( & V_287 -> V_2 , V_287 -> V_256 , NULL ,
F_61 , V_303 | V_304 ,
L_42 , V_76 ) ;
if ( V_77 < 0 ) {
F_5 ( & V_287 -> V_2 , L_43 ,
V_77 ) ;
return V_77 ;
}
V_77 = F_81 ( & V_287 -> V_2 ,
& V_305 , V_306 ,
F_18 ( V_306 ) ) ;
V_302:
return V_77 ;
}
static void F_82 ( struct V_286 * V_287 )
{
struct V_75 * V_76 = F_83 ( & V_287 -> V_2 ) ;
F_4 ( V_76 -> V_78 ,
V_61 , V_307 ) ;
F_4 ( V_76 -> V_78 ,
V_66 , 0x00 ) ;
F_6 ( 40 ) ;
}
static int F_84 ( struct V_286 * V_308 )
{
F_82 ( V_308 ) ;
F_85 ( & V_308 -> V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = F_83 ( V_2 ) ;
F_87 ( V_76 -> V_78 , false ) ;
F_3 ( V_76 ) ;
F_32 ( V_76 -> V_78 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = F_83 ( V_2 ) ;
F_87 ( V_76 -> V_78 , true ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = F_83 ( V_2 ) ;
unsigned int V_239 ;
F_33 ( V_76 -> V_78 ) ;
F_3 ( V_76 ) ;
F_53 ( V_76 -> V_78 , V_5 , & V_239 ) ;
F_32 ( V_76 -> V_78 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
return 0 ;
}
