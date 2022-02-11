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
struct V_85 * V_80 = V_101 -> V_80 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
unsigned int V_91 = F_11 ( V_80 , V_101 -> V_3 ) ;
if ( V_101 -> V_3 == V_13 )
V_91 = ( V_91 & V_103 ) >> V_104 ;
else
V_91 = ( V_91 & V_105 ) >> V_106 ;
if ( V_91 >= 1 ) {
if ( V_101 -> V_3 == V_13 ) {
V_76 -> V_93 = V_91 - 1 ;
} else {
V_76 -> V_94 = V_91 - 1 ;
}
}
switch ( V_102 ) {
case V_107 :
if ( V_101 -> V_3 == V_13 )
V_91 = V_76 -> V_93 + 1 ;
else
V_91 = V_76 -> V_94 + 1 ;
break;
case V_108 :
V_91 = 0 ;
break;
default:
return - V_96 ;
}
if ( V_101 -> V_3 == V_13 )
F_13 ( V_80 , V_101 -> V_3 , V_103 ,
V_91 << V_104 ) ;
else
F_13 ( V_80 , V_101 -> V_3 , V_105 ,
V_91 << V_106 ) ;
return 0 ;
}
static int F_15 ( struct V_85 * V_80 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_109 * V_110 = & V_80 -> V_110 ;
F_16 ( V_80 , V_111 ,
F_17 ( V_111 ) ) ;
if ( V_76 -> V_112 == V_113 ) {
F_16 ( V_80 , V_114 ,
F_17 ( V_114 ) ) ;
}
F_18 ( V_110 , V_115 ,
F_17 ( V_115 ) ) ;
F_19 ( V_110 , V_116 ,
F_17 ( V_116 ) ) ;
if ( V_76 -> V_112 == V_113 ) {
F_18 ( V_110 , V_117 ,
F_17 ( V_117 ) ) ;
F_19 ( V_110 , V_118 ,
F_17 ( V_118 ) ) ;
}
return 0 ;
}
static void F_20 ( struct V_85 * V_80 )
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
for ( V_120 = 0 ; V_120 < F_17 ( V_125 ) ; V_120 ++ ) {
if ( ( V_125 [ V_120 ] == V_76 -> V_121 ) &&
( V_126 [ V_120 ] == V_76 -> V_123 ) ) {
F_21 ( V_80 -> V_2 ,
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
for ( V_120 = 0 ; V_120 < F_17 ( V_130 ) ; V_120 ++ ) {
if ( ( V_130 [ V_120 ] == V_76 -> V_121 ) &&
( V_131 [ V_120 ] == V_76 -> V_123 ) ) {
F_21 ( V_80 -> V_2 ,
L_5 ) ;
F_21 ( V_80 -> V_2 , L_6 ,
V_120 , V_132 [ V_120 ] , V_133 [ V_120 ] ) ;
F_13 ( V_80 , V_25 ,
V_127 , 0 ) ;
F_13 ( V_80 , V_25 ,
V_129 ,
1 << V_134 ) ;
F_22 ( V_80 , V_26 ,
( V_132 [ V_120 ] >> 8 ) & 0x7F ) ;
F_22 ( V_80 , V_27 ,
V_132 [ V_120 ] & 0xFF ) ;
F_22 ( V_80 , V_28 ,
( V_133 [ V_120 ] >> 8 ) & 0x7F ) ;
F_22 ( V_80 , V_29 ,
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
F_23 ( V_119 , ( unsigned long long int ) V_76 -> V_121 ) ;
F_24 ( V_80 -> V_2 , L_7 ) ;
F_24 ( V_80 -> V_2 , L_8 , V_119 ) ;
F_22 ( V_80 , V_26 ,
( V_119 >> 8 ) & 0x7F ) ;
F_22 ( V_80 , V_27 , V_119 & 0xFF ) ;
}
static int F_25 ( struct V_135 * V_136 ,
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
F_22 ( V_80 ,
V_26 , 0x00 ) ;
F_22 ( V_80 ,
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
F_22 ( V_80 , V_30 , V_140 ) ;
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
F_22 ( V_80 ,
V_31 , V_140 ) ;
}
return 0 ;
}
static int F_26 ( struct V_135 * V_136 ,
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
F_22 ( V_80 , V_33 ,
0 << V_172 |
1 << V_173 |
0 << V_174 ) ;
F_13 ( V_80 , V_32 ,
V_175 ,
V_175 ) ;
}
V_139 -> V_137 = 0 ;
F_25 ( V_136 , V_76 -> V_141 ) ;
return 0 ;
}
static int F_27 ( struct V_85 * V_80 ,
enum V_176 V_177 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
int V_77 ;
switch ( V_177 ) {
case V_178 :
break;
case V_179 :
if ( ! F_28 ( V_76 -> V_180 ) ) {
if ( V_80 -> V_110 . V_181 == V_178 )
F_29 ( V_76 -> V_180 ) ;
else
F_30 ( V_76 -> V_180 ) ;
}
break;
case V_182 :
if ( V_80 -> V_110 . V_181 == V_183 ) {
V_77 = F_31 ( V_76 -> V_78 ) ;
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
F_32 ( V_76 -> V_78 ) ;
break;
}
V_80 -> V_110 . V_181 = V_177 ;
return 0 ;
}
static int F_33 ( struct V_185 * V_186 ,
struct V_187 * V_188 ,
struct V_135 * V_142 )
{
struct V_85 * V_80 = V_142 -> V_80 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
int V_120 , V_189 ;
V_139 = & V_76 -> V_142 [ 0 ] ;
V_76 -> V_122 = F_34 ( V_188 ) ;
if ( F_35 ( V_188 ) == 1 )
V_76 -> V_122 *= 2 ;
V_76 -> V_123 = F_36 ( V_188 ) ;
switch ( F_37 ( V_188 ) ) {
case 16 :
F_13 ( V_80 , V_31 ,
V_190 , 0 ) ;
break;
default:
return - V_96 ;
}
if ( V_76 -> V_145 )
F_20 ( V_80 ) ;
V_139 -> V_191 = V_76 -> V_123 ;
if ( V_76 -> V_123 < 24000 )
F_13 ( V_80 , V_35 ,
V_192 , 0 ) ;
else
F_13 ( V_80 , V_35 ,
V_192 , V_192 ) ;
if ( V_76 -> V_123 < 50000 )
F_13 ( V_80 , V_35 ,
V_193 , 0 ) ;
else
F_13 ( V_80 , V_35 ,
V_193 , V_193 ) ;
for ( V_189 = 0 ; V_189 < F_17 ( V_194 ) ; V_189 ++ ) {
if ( V_194 [ V_189 ] == V_76 -> V_121 ) {
break;
}
}
for ( V_120 = 0 ; V_120 < F_17 ( V_195 ) - 1 ; V_120 ++ ) {
if ( V_76 -> V_123 <= ( V_195 [ V_120 ] +
V_195 [ V_120 + 1 ] ) / 2 ) {
break;
}
}
F_13 ( V_80 , V_16 ,
V_196 ,
V_197 [ V_189 ] << V_198 ) ;
F_13 ( V_80 , V_17 ,
V_199 ,
V_200 [ V_189 ] [ V_120 ] << V_201 ) ;
return 0 ;
}
static int F_38 ( struct V_135 * V_142 ,
int V_202 , unsigned int V_203 , int V_204 )
{
struct V_85 * V_80 = V_142 -> V_80 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
if ( V_203 == V_76 -> V_121 )
return 0 ;
if ( ! F_28 ( V_76 -> V_180 ) ) {
V_203 = F_39 ( V_76 -> V_180 , V_203 ) ;
F_40 ( V_76 -> V_180 , V_203 ) ;
}
if ( ( V_203 >= 10000000 ) && ( V_203 < 20000000 ) ) {
F_22 ( V_80 , V_24 ,
V_205 ) ;
} else if ( ( V_203 >= 20000000 ) && ( V_203 < 40000000 ) ) {
F_22 ( V_80 , V_24 ,
V_206 ) ;
} else if ( ( V_203 >= 40000000 ) && ( V_203 < 60000000 ) ) {
F_22 ( V_80 , V_24 ,
V_207 ) ;
} else {
F_5 ( V_80 -> V_2 , L_13 ) ;
return - V_96 ;
}
V_76 -> V_121 = V_203 ;
return 0 ;
}
static int F_41 ( struct V_135 * V_136 , int V_208 )
{
struct V_85 * V_80 = V_136 -> V_80 ;
int V_140 ;
V_140 = V_208 ? V_209 : 0 ;
F_13 ( V_80 , V_36 ,
V_209 , V_140 ) ;
return 0 ;
}
static void F_42 ( struct V_210 * V_211 )
{
struct V_75 * V_76 = F_43 ( V_211 ,
struct V_75 ,
V_212 . V_211 ) ;
struct V_85 * V_80 = V_76 -> V_80 ;
struct V_109 * V_110 = & V_80 -> V_110 ;
int V_213 = 0 ;
int V_3 ;
if ( V_76 -> V_214 == V_215 ) {
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
switch ( V_3 & ( V_216 | V_217 ) ) {
case V_216 | V_217 :
F_21 ( V_80 -> V_2 , L_14 ) ;
V_76 -> V_214 = V_215 ;
V_213 |= 0 ;
break;
case 0 :
if ( V_76 -> V_214 ==
V_218 ) {
F_21 ( V_80 -> V_2 ,
L_15 ) ;
V_213 |= V_219 ;
V_213 |= V_220 ;
break;
}
F_21 ( V_80 -> V_2 , L_16 ) ;
V_76 -> V_214 = V_221 ;
V_213 |= V_222 ;
break;
case V_217 :
F_21 ( V_80 -> V_2 , L_17 ) ;
V_76 -> V_214 = V_218 ;
V_213 |= V_219 ;
break;
default:
F_21 ( V_80 -> V_2 , L_18 ) ;
break;
}
F_44 ( V_76 -> V_223 , V_213 ,
V_219 | V_220 ) ;
F_45 ( V_110 ) ;
}
static T_2 F_46 ( int V_224 , void * V_225 )
{
struct V_85 * V_80 = V_225 ;
struct V_75 * V_76 = F_9 ( V_80 ) ;
int V_77 ;
unsigned int V_89 ;
unsigned int V_226 ;
F_21 ( V_80 -> V_2 , L_19 ) ;
V_77 = F_47 ( V_76 -> V_78 , V_8 , & V_89 ) ;
if ( V_77 != 0 ) {
F_5 ( V_80 -> V_2 ,
L_20 ,
V_77 ) ;
return V_227 ;
}
V_77 = F_47 ( V_76 -> V_78 , V_5 , & V_226 ) ;
if ( V_77 != 0 ) {
F_5 ( V_80 -> V_2 ,
L_21 ,
V_77 ) ;
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
F_48 ( V_80 -> V_2 , 100 ) ;
F_49 ( V_232 ,
& V_76 -> V_212 ,
F_50 ( 100 ) ) ;
}
if ( V_226 & V_233 )
F_21 ( V_80 -> V_2 , L_27 ) ;
if ( V_226 & V_234 )
F_5 ( V_80 -> V_2 , L_28 ) ;
return V_235 ;
}
int F_51 ( struct V_85 * V_80 ,
struct V_236 * V_223 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
F_21 ( V_80 -> V_2 , L_29 ) ;
V_76 -> V_223 = V_223 ;
if ( V_223 ) {
F_13 ( V_80 , V_8 ,
V_237 ,
1 << V_238 ) ;
} else {
F_13 ( V_80 , V_8 ,
V_237 ,
0 ) ;
}
F_44 ( V_76 -> V_223 , 0 ,
V_219 | V_220 ) ;
F_49 ( V_232 ,
& V_76 -> V_212 ,
F_50 ( 100 ) ) ;
return 0 ;
}
static void F_52 ( struct V_85 * V_80 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_239 * V_240 = V_76 -> V_240 ;
if ( ! V_240 ) {
F_5 ( V_80 -> V_2 , L_30 ) ;
return;
}
}
static int F_53 ( struct V_85 * V_80 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
struct V_138 * V_139 ;
int V_77 = 0 ;
F_21 ( V_80 -> V_2 , L_31 ) ;
V_76 -> V_180 = F_54 ( V_80 -> V_2 , L_32 ) ;
if ( F_55 ( V_76 -> V_180 ) == - V_241 )
return - V_241 ;
V_76 -> V_80 = V_80 ;
F_3 ( V_76 ) ;
V_76 -> V_121 = ( unsigned ) - 1 ;
V_76 -> V_145 = false ;
V_139 = & V_76 -> V_142 [ 0 ] ;
V_139 -> V_191 = ( unsigned ) - 1 ;
V_139 -> V_137 = ( unsigned ) - 1 ;
V_76 -> V_242 = 0 ;
V_76 -> V_93 = 0 ;
V_76 -> V_94 = 0 ;
V_76 -> V_243 = 0 ;
V_77 = F_11 ( V_80 , V_7 ) ;
if ( V_77 < 0 ) {
F_5 ( V_80 -> V_2 , L_33 ,
V_77 ) ;
goto V_244;
}
if ( ( V_77 >= V_245 ) && ( V_77 <= V_245 + 0x0f ) ) {
V_76 -> V_112 = V_246 ;
F_24 ( V_80 -> V_2 , L_34 , V_77 ) ;
} else if ( ( V_77 >= V_247 ) && ( V_77 <= V_247 + 0x0f ) ) {
V_76 -> V_112 = V_113 ;
F_24 ( V_80 -> V_2 , L_35 , V_77 ) ;
} else {
V_76 -> V_112 = V_246 ;
F_5 ( V_80 -> V_2 , L_36 , V_77 ) ;
}
V_76 -> V_214 = V_215 ;
F_56 ( & V_76 -> V_212 , F_42 ) ;
F_22 ( V_80 , V_58 ,
V_248 | V_249 ) ;
F_21 ( V_80 -> V_2 , L_37 , V_76 -> V_224 ) ;
V_77 = F_57 ( V_76 -> V_224 , NULL ,
F_46 , V_250 | V_251 ,
L_38 , V_80 ) ;
if ( V_77 < 0 ) {
F_5 ( V_80 -> V_2 , L_39 ,
V_77 ) ;
}
F_11 ( V_80 , V_5 ) ;
F_13 ( V_80 , V_64 ,
V_252 ,
1 << V_253 ) ;
F_13 ( V_80 , V_64 ,
V_254 ,
0 << V_255 ) ;
F_13 ( V_80 , V_65 ,
V_256 ,
1 << V_257 ) ;
F_22 ( V_80 , V_63 ,
V_258 ) ;
F_13 ( V_80 , V_15 ,
V_259 , V_260 ) ;
F_52 ( V_80 ) ;
F_15 ( V_80 ) ;
V_244:
return V_77 ;
}
static int F_58 ( struct V_85 * V_80 )
{
struct V_75 * V_76 = F_9 ( V_80 ) ;
F_59 ( & V_76 -> V_212 ) ;
return 0 ;
}
static int F_60 ( struct V_261 * V_262 ,
const struct V_263 * V_264 )
{
struct V_75 * V_76 ;
const struct V_265 * V_266 ;
T_3 V_267 = 0 ;
int V_77 ;
F_61 ( L_40 ) ;
V_76 = F_62 ( & V_262 -> V_2 , sizeof( struct V_75 ) ,
V_268 ) ;
if ( V_76 == NULL )
return - V_269 ;
if ( F_63 ( & V_262 -> V_2 ) ) {
V_266 = F_64 ( V_262 -> V_2 . V_270 -> V_271 ,
& V_262 -> V_2 ) ;
if ( ! V_266 ) {
F_5 ( & V_262 -> V_2 , L_41 ) ;
return - V_96 ;
}
V_267 = V_266 -> V_267 ;
} else if ( V_264 ) {
V_267 = V_264 -> V_267 ;
}
V_76 -> V_112 = V_267 ;
F_65 ( V_262 , V_76 ) ;
V_76 -> V_240 = V_262 -> V_2 . V_272 ;
V_76 -> V_224 = V_262 -> V_224 ;
V_76 -> V_78 = F_66 ( V_262 , & V_273 ) ;
if ( F_28 ( V_76 -> V_78 ) ) {
V_77 = F_55 ( V_76 -> V_78 ) ;
F_5 ( & V_262 -> V_2 , L_42 , V_77 ) ;
goto V_274;
}
V_77 = F_67 ( & V_262 -> V_2 ,
& V_275 , V_276 ,
F_17 ( V_276 ) ) ;
V_274:
return V_77 ;
}
static int F_68 ( struct V_261 * V_277 )
{
F_69 ( & V_277 -> V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = F_71 ( V_2 ) ;
F_72 ( V_76 -> V_78 , false ) ;
F_3 ( V_76 ) ;
F_31 ( V_76 -> V_78 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = F_71 ( V_2 ) ;
F_72 ( V_76 -> V_78 , true ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = F_71 ( V_2 ) ;
unsigned int V_213 ;
F_32 ( V_76 -> V_78 ) ;
F_3 ( V_76 ) ;
F_47 ( V_76 -> V_78 , V_5 , & V_213 ) ;
F_31 ( V_76 -> V_78 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
return 0 ;
}
