static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
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
case V_66 ... V_66 + 0x68 :
case V_67 ... V_67 + 0x0E :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 ... V_73 + 0x0E :
case V_6 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_74 * V_75 )
{
int V_76 ;
V_76 = F_4 ( V_75 -> V_77 , V_78 ,
V_79 ) ;
if ( V_76 < 0 ) {
F_5 ( V_75 -> V_80 -> V_2 ,
L_1 , V_76 ) ;
return V_76 ;
}
F_6 ( 20 ) ;
return V_76 ;
}
static int F_7 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_80 = F_8 ( V_82 ) ;
struct V_74 * V_75 = F_9 ( V_80 ) ;
struct V_86 * V_87 =
(struct V_86 * ) V_82 -> V_88 ;
unsigned int V_89 = ( 1 << F_10 ( V_87 -> V_90 ) ) - 1 ;
unsigned int V_91 = F_11 ( V_80 , V_87 -> V_3 ) ;
unsigned int * V_92 ;
switch ( V_87 -> V_3 ) {
case V_12 :
V_92 = & ( V_75 -> V_93 ) ;
break;
case V_13 :
V_92 = & ( V_75 -> V_94 ) ;
break;
case V_22 :
V_92 = & ( V_75 -> V_95 ) ;
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
struct V_74 * V_75 = F_9 ( V_80 ) ;
struct V_86 * V_87 =
(struct V_86 * ) V_82 -> V_88 ;
unsigned int V_89 = ( 1 << F_10 ( V_87 -> V_90 ) ) - 1 ;
unsigned int V_99 = V_84 -> V_98 . integer . V_98 [ 0 ] ;
unsigned int V_91 = F_11 ( V_80 , V_87 -> V_3 ) ;
unsigned int * V_92 ;
switch ( V_87 -> V_3 ) {
case V_12 :
V_92 = & ( V_75 -> V_93 ) ;
break;
case V_13 :
V_92 = & ( V_75 -> V_94 ) ;
break;
case V_22 :
V_92 = & ( V_75 -> V_95 ) ;
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
struct V_85 * V_80 = V_101 -> V_80 ;
struct V_74 * V_75 = F_9 ( V_80 ) ;
unsigned int V_91 = F_11 ( V_80 , V_101 -> V_3 ) ;
if ( V_101 -> V_3 == V_12 )
V_91 = ( V_91 & V_103 ) >> V_104 ;
else
V_91 = ( V_91 & V_105 ) >> V_106 ;
if ( V_91 >= 1 ) {
if ( V_101 -> V_3 == V_12 ) {
V_75 -> V_93 = V_91 - 1 ;
} else {
V_75 -> V_94 = V_91 - 1 ;
}
}
switch ( V_102 ) {
case V_107 :
if ( V_101 -> V_3 == V_12 )
V_91 = V_75 -> V_93 + 1 ;
else
V_91 = V_75 -> V_94 + 1 ;
break;
case V_108 :
V_91 = 0 ;
break;
default:
return - V_96 ;
}
if ( V_101 -> V_3 == V_12 )
F_13 ( V_80 , V_101 -> V_3 , V_103 ,
V_91 << V_104 ) ;
else
F_13 ( V_80 , V_101 -> V_3 , V_105 ,
V_91 << V_106 ) ;
return 0 ;
}
static int F_15 ( struct V_85 * V_80 )
{
struct V_74 * V_75 = F_9 ( V_80 ) ;
struct V_109 * V_110 = & V_80 -> V_110 ;
F_16 ( V_80 , V_111 ,
F_17 ( V_111 ) ) ;
if ( V_75 -> V_112 == V_113 ) {
F_16 ( V_80 , V_114 ,
F_17 ( V_114 ) ) ;
}
F_18 ( V_110 , V_115 ,
F_17 ( V_115 ) ) ;
F_19 ( V_110 , V_116 ,
F_17 ( V_116 ) ) ;
if ( V_75 -> V_112 == V_113 ) {
F_18 ( V_110 , V_117 ,
F_17 ( V_117 ) ) ;
F_19 ( V_110 , V_118 ,
F_17 ( V_118 ) ) ;
}
return 0 ;
}
static void F_20 ( struct V_85 * V_80 )
{
struct V_74 * V_75 = F_9 ( V_80 ) ;
unsigned long long V_119 ;
int V_120 ;
if ( ! V_75 -> V_121 ) {
F_5 ( V_80 -> V_2 , L_2 ) ;
return;
}
if ( ! V_75 -> V_122 || ! V_75 -> V_123 ) {
F_5 ( V_80 -> V_2 , L_3 ) ;
return;
}
if ( ! ( F_11 ( V_80 , V_29 ) &
V_124 ) ) {
return;
}
for ( V_120 = 0 ; V_120 < F_17 ( V_125 ) ; V_120 ++ ) {
if ( ( V_125 [ V_120 ] == V_75 -> V_121 ) &&
( V_126 [ V_120 ] == V_75 -> V_123 ) ) {
F_21 ( V_80 -> V_2 ,
L_4 ,
V_120 + 0x8 ) ;
F_13 ( V_80 , V_24 ,
V_127 ,
( V_120 + 0x8 ) << V_128 ) ;
F_13 ( V_80 , V_24 ,
V_129 , 0 ) ;
return;
}
}
for ( V_120 = 0 ; V_120 < F_17 ( V_130 ) ; V_120 ++ ) {
if ( ( V_130 [ V_120 ] == V_75 -> V_121 ) &&
( V_131 [ V_120 ] == V_75 -> V_123 ) ) {
F_21 ( V_80 -> V_2 ,
L_5 ) ;
F_21 ( V_80 -> V_2 , L_6 ,
V_120 , V_132 [ V_120 ] , V_133 [ V_120 ] ) ;
F_13 ( V_80 , V_24 ,
V_127 , 0 ) ;
F_13 ( V_80 , V_24 ,
V_129 ,
1 << V_134 ) ;
F_22 ( V_80 , V_25 ,
( V_132 [ V_120 ] >> 8 ) & 0x7F ) ;
F_22 ( V_80 , V_26 ,
V_132 [ V_120 ] & 0xFF ) ;
F_22 ( V_80 , V_27 ,
( V_133 [ V_120 ] >> 8 ) & 0x7F ) ;
F_22 ( V_80 , V_28 ,
V_133 [ V_120 ] & 0xFF ) ;
return;
}
}
F_13 ( V_80 , V_24 ,
V_127 , 0 ) ;
F_13 ( V_80 , V_24 ,
V_129 , 0 ) ;
V_119 = 65536ULL * ( V_75 -> V_123 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_75 -> V_123 ;
F_23 ( V_119 , ( unsigned long long int ) V_75 -> V_121 ) ;
F_24 ( V_80 -> V_2 , L_7 ) ;
F_24 ( V_80 -> V_2 , L_8 , V_119 ) ;
F_22 ( V_80 , V_25 ,
( V_119 >> 8 ) & 0x7F ) ;
F_22 ( V_80 , V_26 , V_119 & 0xFF ) ;
}
static int F_25 ( struct V_135 * V_136 ,
unsigned int V_137 )
{
struct V_85 * V_80 = V_136 -> V_80 ;
struct V_74 * V_75 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
T_1 V_140 ;
V_75 -> V_141 = V_137 ;
V_139 = & V_75 -> V_142 [ 0 ] ;
if ( V_137 != V_139 -> V_137 ) {
V_139 -> V_137 = V_137 ;
V_140 = 0 ;
switch ( V_137 & V_143 ) {
case V_144 :
F_22 ( V_80 ,
V_25 , 0x00 ) ;
F_22 ( V_80 ,
V_26 , 0x00 ) ;
F_13 ( V_80 , V_24 ,
V_129 , 0 ) ;
break;
case V_145 :
if ( V_75 -> V_146 == 4 ) {
V_140 |= V_124 |
V_147 ;
} else if ( V_75 -> V_146 == 3 ) {
V_140 |= V_124 |
V_148 ;
} else {
V_140 |= V_124 |
V_149 ;
}
break;
case V_150 :
case V_151 :
default:
F_5 ( V_80 -> V_2 , L_9 ) ;
return - V_96 ;
}
F_22 ( V_80 , V_29 , V_140 ) ;
V_140 = 0 ;
switch ( V_137 & V_152 ) {
case V_153 :
V_140 |= V_154 ;
break;
case V_155 :
break;
case V_156 :
V_140 |= V_157 ;
break;
case V_158 :
default:
F_5 ( V_80 -> V_2 , L_10 ) ;
return - V_96 ;
}
switch ( V_137 & V_159 ) {
case V_160 :
break;
case V_161 :
V_140 |= V_162 ;
break;
case V_163 :
V_140 |= V_164 ;
break;
case V_165 :
V_140 |= V_164 | V_162 ;
break;
default:
F_5 ( V_80 -> V_2 , L_11 ) ;
return - V_96 ;
}
if ( V_75 -> V_146 > 1 )
V_140 ^= V_164 ;
F_22 ( V_80 ,
V_30 , V_140 ) ;
}
return 0 ;
}
static int F_26 ( struct V_135 * V_136 ,
unsigned int V_166 , unsigned int V_167 , int V_168 , int V_169 )
{
struct V_85 * V_80 = V_136 -> V_80 ;
struct V_74 * V_75 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
V_139 = & V_75 -> V_142 [ 0 ] ;
if ( V_168 < 0 || V_168 > 4 )
return - V_96 ;
V_75 -> V_146 = V_168 ;
V_75 -> V_170 = V_169 ;
if ( V_75 -> V_146 > 1 ) {
F_22 ( V_80 , V_32 ,
0 << V_171 |
1 << V_172 |
0 << V_173 ) ;
F_13 ( V_80 , V_31 ,
V_174 ,
V_174 ) ;
}
V_139 -> V_137 = 0 ;
F_25 ( V_136 , V_75 -> V_141 ) ;
return 0 ;
}
static int F_27 ( struct V_85 * V_80 ,
enum V_175 V_176 )
{
struct V_74 * V_75 = F_9 ( V_80 ) ;
int V_76 ;
switch ( V_176 ) {
case V_177 :
if ( V_75 -> V_178 == V_179 ) {
F_13 ( V_80 , V_14 ,
V_180 , V_181 ) ;
}
break;
case V_182 :
break;
case V_183 :
if ( V_80 -> V_110 . V_184 == V_185 ) {
V_76 = F_28 ( V_75 -> V_77 ) ;
if ( V_76 != 0 ) {
F_5 ( V_80 -> V_2 ,
L_12 , V_76 ) ;
return V_76 ;
}
}
break;
case V_185 :
F_13 ( V_80 , V_57 ,
V_186 , V_186 ) ;
F_29 ( V_75 -> V_77 ) ;
break;
}
V_80 -> V_110 . V_184 = V_176 ;
return 0 ;
}
static int F_30 ( struct V_187 * V_188 ,
struct V_189 * V_190 ,
struct V_135 * V_142 )
{
struct V_85 * V_80 = V_142 -> V_80 ;
struct V_74 * V_75 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
int V_120 , V_191 ;
V_139 = & V_75 -> V_142 [ 0 ] ;
V_75 -> V_122 = F_31 ( V_190 ) ;
if ( F_32 ( V_190 ) == 1 )
V_75 -> V_122 *= 2 ;
V_75 -> V_123 = F_33 ( V_190 ) ;
switch ( F_34 ( V_190 ) ) {
case 16 :
F_13 ( V_80 , V_30 ,
V_192 , 0 ) ;
break;
default:
return - V_96 ;
}
F_20 ( V_80 ) ;
V_139 -> V_193 = V_75 -> V_123 ;
if ( V_75 -> V_123 < 24000 )
F_13 ( V_80 , V_34 ,
V_194 , 0 ) ;
else
F_13 ( V_80 , V_34 ,
V_194 , V_194 ) ;
if ( V_75 -> V_123 < 50000 )
F_13 ( V_80 , V_34 ,
V_195 , 0 ) ;
else
F_13 ( V_80 , V_34 ,
V_195 , V_195 ) ;
for ( V_191 = 0 ; V_191 < F_17 ( V_196 ) ; V_191 ++ ) {
if ( V_196 [ V_191 ] == V_75 -> V_121 ) {
break;
}
}
for ( V_120 = 0 ; V_120 < F_17 ( V_197 ) - 1 ; V_120 ++ ) {
if ( V_75 -> V_123 <= ( V_197 [ V_120 ] +
V_197 [ V_120 + 1 ] ) / 2 ) {
break;
}
}
F_13 ( V_80 , V_15 ,
V_198 ,
V_199 [ V_191 ] << V_200 ) ;
F_13 ( V_80 , V_16 ,
V_201 ,
V_202 [ V_191 ] [ V_120 ] << V_203 ) ;
return 0 ;
}
static int F_35 ( struct V_135 * V_142 ,
int V_204 , unsigned int V_205 , int V_206 )
{
struct V_85 * V_80 = V_142 -> V_80 ;
struct V_74 * V_75 = F_9 ( V_80 ) ;
if ( V_205 == V_75 -> V_121 )
return 0 ;
if ( ( V_205 >= 10000000 ) && ( V_205 < 20000000 ) ) {
F_22 ( V_80 , V_23 ,
V_207 ) ;
} else if ( ( V_205 >= 20000000 ) && ( V_205 < 40000000 ) ) {
F_22 ( V_80 , V_23 ,
V_208 ) ;
} else if ( ( V_205 >= 40000000 ) && ( V_205 < 60000000 ) ) {
F_22 ( V_80 , V_23 ,
V_209 ) ;
} else {
F_5 ( V_80 -> V_2 , L_13 ) ;
return - V_96 ;
}
V_75 -> V_121 = V_205 ;
F_20 ( V_80 ) ;
return 0 ;
}
static int F_36 ( struct V_135 * V_136 , int V_210 )
{
struct V_85 * V_80 = V_136 -> V_80 ;
int V_140 ;
V_140 = V_210 ? V_211 : 0 ;
F_13 ( V_80 , V_35 ,
V_211 , V_140 ) ;
return 0 ;
}
static void F_37 ( struct V_212 * V_213 )
{
struct V_74 * V_75 = F_38 ( V_213 ,
struct V_74 ,
V_214 . V_213 ) ;
struct V_85 * V_80 = V_75 -> V_80 ;
struct V_109 * V_110 = & V_80 -> V_110 ;
int V_215 = 0 ;
int V_3 ;
if ( V_75 -> V_178 == V_216 ) {
F_13 ( V_80 , V_57 ,
V_186 , 0 ) ;
F_6 ( 50 ) ;
V_3 = F_11 ( V_80 , V_5 ) ;
F_13 ( V_80 , V_57 ,
V_186 , V_186 ) ;
} else {
V_3 = F_11 ( V_80 , V_5 ) ;
}
V_3 = F_11 ( V_80 , V_5 ) ;
switch ( V_3 & ( V_217 | V_218 ) ) {
case V_217 | V_218 :
F_21 ( V_80 -> V_2 , L_14 ) ;
V_75 -> V_178 = V_216 ;
V_215 |= 0 ;
break;
case 0 :
if ( V_75 -> V_178 ==
V_179 ) {
F_21 ( V_80 -> V_2 ,
L_15 ) ;
V_215 |= V_219 ;
V_215 |= V_220 ;
break;
}
F_21 ( V_80 -> V_2 , L_16 ) ;
V_75 -> V_178 = V_221 ;
V_215 |= V_222 ;
break;
case V_218 :
F_21 ( V_80 -> V_2 , L_17 ) ;
V_75 -> V_178 = V_179 ;
V_215 |= V_219 ;
break;
default:
F_21 ( V_80 -> V_2 , L_18 ) ;
break;
}
F_39 ( V_75 -> V_223 , V_215 ,
V_219 | V_220 ) ;
F_40 ( V_110 ) ;
}
static T_2 F_41 ( int V_224 , void * V_225 )
{
struct V_85 * V_80 = V_225 ;
struct V_74 * V_75 = F_9 ( V_80 ) ;
int V_76 ;
unsigned int V_89 ;
unsigned int V_226 ;
F_21 ( V_80 -> V_2 , L_19 ) ;
V_76 = F_42 ( V_75 -> V_77 , V_7 , & V_89 ) ;
if ( V_76 != 0 ) {
F_5 ( V_80 -> V_2 ,
L_20 ,
V_76 ) ;
return V_227 ;
}
V_76 = F_42 ( V_75 -> V_77 , V_4 , & V_226 ) ;
if ( V_76 != 0 ) {
F_5 ( V_80 -> V_2 ,
L_21 ,
V_76 ) ;
return V_227 ;
}
F_21 ( V_80 -> V_2 , L_22 ,
V_226 , V_89 , V_226 & V_89 ) ;
V_226 &= V_89 ;
if ( ! V_226 )
return V_227 ;
if ( V_226 & V_228 )
F_5 ( V_80 -> V_2 , L_23 ) ;
if ( V_226 & V_229 )
F_21 ( V_80 -> V_2 , L_24 ) ;
if ( V_226 & V_230 )
F_5 ( V_80 -> V_2 , L_25 ) ;
if ( V_226 & V_231 ) {
F_21 ( V_80 -> V_2 , L_26 ) ;
F_43 ( V_80 -> V_2 , 100 ) ;
F_44 ( V_232 ,
& V_75 -> V_214 ,
F_45 ( 100 ) ) ;
}
if ( V_226 & V_233 )
F_21 ( V_80 -> V_2 , L_27 ) ;
if ( V_226 & V_234 )
F_5 ( V_80 -> V_2 , L_28 ) ;
return V_235 ;
}
int F_46 ( struct V_85 * V_80 ,
struct V_236 * V_223 )
{
struct V_74 * V_75 = F_9 ( V_80 ) ;
F_21 ( V_80 -> V_2 , L_29 ) ;
V_75 -> V_223 = V_223 ;
if ( V_223 ) {
F_13 ( V_80 , V_7 ,
V_237 ,
1 << V_238 ) ;
} else {
F_13 ( V_80 , V_7 ,
V_237 ,
0 ) ;
}
F_39 ( V_75 -> V_223 , 0 ,
V_219 | V_220 ) ;
F_44 ( V_232 ,
& V_75 -> V_214 ,
F_45 ( 100 ) ) ;
return 0 ;
}
static void F_47 ( struct V_85 * V_80 )
{
struct V_74 * V_75 = F_9 ( V_80 ) ;
struct V_239 * V_240 = V_75 -> V_240 ;
if ( ! V_240 ) {
F_5 ( V_80 -> V_2 , L_30 ) ;
return;
}
}
static int F_48 ( struct V_85 * V_80 )
{
struct V_74 * V_75 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
int V_76 = 0 ;
F_21 ( V_80 -> V_2 , L_31 ) ;
V_75 -> V_80 = V_80 ;
V_80 -> V_241 = V_75 -> V_77 ;
V_76 = F_49 ( V_80 , 8 , 8 , V_242 ) ;
if ( V_76 != 0 ) {
F_5 ( V_80 -> V_2 , L_32 , V_76 ) ;
return V_76 ;
}
F_3 ( V_75 ) ;
V_75 -> V_121 = ( unsigned ) - 1 ;
V_139 = & V_75 -> V_142 [ 0 ] ;
V_139 -> V_193 = ( unsigned ) - 1 ;
V_139 -> V_137 = ( unsigned ) - 1 ;
V_75 -> V_243 = 0 ;
V_75 -> V_93 = 0 ;
V_75 -> V_94 = 0 ;
V_75 -> V_244 = 0 ;
V_76 = F_11 ( V_80 , V_6 ) ;
if ( V_76 < 0 ) {
F_5 ( V_80 -> V_2 , L_33 ,
V_76 ) ;
goto V_245;
}
if ( ( V_76 >= V_246 ) && ( V_76 <= V_246 + 0x0f ) ) {
V_75 -> V_112 = V_247 ;
F_24 ( V_80 -> V_2 , L_34 , V_76 ) ;
} else if ( ( V_76 >= V_248 ) && ( V_76 <= V_248 + 0x0f ) ) {
V_75 -> V_112 = V_113 ;
F_24 ( V_80 -> V_2 , L_35 , V_76 ) ;
} else {
V_75 -> V_112 = V_247 ;
F_5 ( V_80 -> V_2 , L_36 , V_76 ) ;
}
V_75 -> V_178 = V_216 ;
F_50 ( & V_75 -> V_214 , F_37 ) ;
F_22 ( V_80 , V_57 ,
V_249 | V_250 ) ;
F_21 ( V_80 -> V_2 , L_37 , V_75 -> V_224 ) ;
V_76 = F_51 ( V_75 -> V_224 , NULL ,
F_41 , V_251 | V_252 ,
L_38 , V_80 ) ;
if ( V_76 < 0 ) {
F_5 ( V_80 -> V_2 , L_39 ,
V_76 ) ;
}
F_11 ( V_80 , V_4 ) ;
F_13 ( V_80 , V_63 ,
V_253 ,
1 << V_254 ) ;
F_13 ( V_80 , V_63 ,
V_255 ,
0 << V_256 ) ;
F_13 ( V_80 , V_64 ,
V_257 ,
1 << V_258 ) ;
F_22 ( V_80 , V_62 ,
V_259 ) ;
F_47 ( V_80 ) ;
F_15 ( V_80 ) ;
V_245:
return V_76 ;
}
static int F_52 ( struct V_85 * V_80 )
{
struct V_74 * V_75 = F_9 ( V_80 ) ;
F_53 ( & V_75 -> V_214 ) ;
return 0 ;
}
static int F_54 ( struct V_260 * V_261 ,
const struct V_262 * V_263 )
{
struct V_74 * V_75 ;
int V_76 ;
F_55 ( L_40 ) ;
V_75 = F_56 ( & V_261 -> V_2 , sizeof( struct V_74 ) ,
V_264 ) ;
if ( V_75 == NULL )
return - V_265 ;
V_75 -> V_112 = V_263 -> V_266 ;
F_57 ( V_261 , V_75 ) ;
V_75 -> V_241 = V_261 ;
V_75 -> V_240 = V_261 -> V_2 . V_267 ;
V_75 -> V_224 = V_261 -> V_224 ;
V_75 -> V_77 = F_58 ( V_261 , & V_268 ) ;
if ( F_59 ( V_75 -> V_77 ) ) {
V_76 = F_60 ( V_75 -> V_77 ) ;
F_5 ( & V_261 -> V_2 , L_41 , V_76 ) ;
goto V_269;
}
V_76 = F_61 ( & V_261 -> V_2 ,
& V_270 , V_271 ,
F_17 ( V_271 ) ) ;
V_269:
return V_76 ;
}
static int F_62 ( struct V_260 * V_272 )
{
F_63 ( & V_272 -> V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = F_65 ( V_2 ) ;
F_66 ( V_75 -> V_77 , false ) ;
F_28 ( V_75 -> V_77 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = F_65 ( V_2 ) ;
F_66 ( V_75 -> V_77 , true ) ;
return 0 ;
}
