static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_10 ... V_11 :
case V_12 ... V_13 :
case V_14 :
case V_15 :
case V_16 ... V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 ... V_25 :
case V_26 ... V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 ... V_37 :
case V_38 :
case V_39 ... V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_47 :
case V_4 ... V_5 :
case V_48 ... V_49 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
return false ;
}
}
static const struct V_50 * F_4 (
unsigned int V_51 , unsigned int V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < F_5 ( V_54 ) ; V_53 ++ ) {
if ( V_54 [ V_53 ] . V_55 == V_51 &&
V_54 [ V_53 ] . V_56 == V_52 )
return & V_54 [ V_53 ] ;
}
return NULL ;
}
static int F_6 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_7 ( V_58 ) ;
const struct V_50 * V_61 ;
F_8 ( V_58 -> V_2 , L_1 ,
V_60 -> V_62 , V_60 -> V_63 ) ;
V_61 = F_4 ( V_60 -> V_62 , V_60 -> V_63 ) ;
if ( ! V_61 )
return - V_64 ;
if ( V_61 -> V_65 == 0 ) {
F_9 ( V_60 -> V_66 , V_16 ,
V_67 , 0 ) ;
V_60 -> V_68 = true ;
return 0 ;
}
V_60 -> V_68 = false ;
F_9 ( V_60 -> V_66 , V_69 ,
V_70 ,
V_61 -> V_71 >>
V_72 ) ;
F_9 ( V_60 -> V_66 , V_73 ,
V_70 ,
V_61 -> V_71 >>
V_74 ) ;
F_9 ( V_60 -> V_66 , V_75 ,
V_70 ,
V_61 -> V_71 >>
V_76 ) ;
F_10 ( V_60 -> V_66 , V_17 ,
V_61 -> V_77 ) ;
F_10 ( V_60 -> V_66 , V_18 , V_61 -> V_78 ) ;
F_10 ( V_60 -> V_66 , V_19 ,
V_61 -> V_65 ) ;
F_9 ( V_60 -> V_66 , V_20 ,
V_79 ,
V_61 -> V_80 << V_81 ) ;
F_10 ( V_60 -> V_66 , V_21 ,
V_61 -> V_82 ) ;
F_9 ( V_60 -> V_66 , V_16 ,
V_67 , 1 ) ;
return 0 ;
}
static int F_11 ( struct V_57 * V_58 , int V_83 , int V_84 ,
unsigned int V_51 , unsigned int V_52 )
{
int V_85 = 0 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_51 ) {
case 9600000 :
case 11289600 :
case 12000000 :
case 12288000 :
case 13000000 :
case 19200000 :
case 22579200 :
case 24000000 :
case 24576000 :
case 26000000 :
V_60 -> V_62 = V_51 ;
break;
default:
F_12 ( V_58 -> V_2 ,
L_2 , V_51 ) ;
return - V_64 ;
}
switch ( V_52 ) {
case 22579200 :
V_60 -> V_63 = V_52 ;
break;
case 24576000 :
V_60 -> V_63 = V_52 ;
break;
default:
F_12 ( V_58 -> V_2 ,
L_3 , V_52 ) ;
return - V_64 ;
}
V_85 = F_6 ( V_58 ) ;
F_8 ( V_58 -> V_2 , L_4 , V_60 -> V_68 ) ;
return V_85 ;
}
static int F_13 ( struct V_57 * V_58 ,
enum V_86 V_87 )
{
int V_85 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
int V_88 ;
if ( V_87 == V_60 -> V_89 ) {
return 0 ;
}
switch ( V_60 -> V_63 ) {
case V_90 :
V_88 = V_91 ;
break;
case V_92 :
V_88 = V_93 ;
break;
default:
F_12 ( V_58 -> V_2 , L_5 , V_60 -> V_63 ) ;
return - V_64 ;
}
switch ( V_87 ) {
case V_94 :
V_60 -> V_68 = true ;
V_60 -> V_89 = V_94 ;
if ( V_60 -> V_95 == V_96 ) {
F_9 ( V_60 -> V_66 , V_14 ,
V_97 ,
1 << V_98 ) ;
} else {
F_14 ( & V_60 -> V_99 ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_100 , 0 ) ;
F_9 ( V_60 -> V_66 , V_14 ,
V_97 , 0 ) ;
V_85 = F_15 ( & V_60 -> V_99 ,
F_16 ( 100 ) ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_100 ,
1 << V_101 ) ;
if ( V_85 == 0 ) {
F_12 ( V_58 -> V_2 , L_6 ) ;
return - V_102 ;
}
}
F_9 ( V_60 -> V_66 , V_11 ,
V_103 ,
V_87 << V_104 ) ;
F_9 ( V_60 -> V_66 , V_11 ,
V_105 ,
V_88 << V_106 ) ;
F_17 ( 150 , 200 ) ;
F_9 ( V_60 -> V_66 , V_14 ,
V_107 ,
1 << V_108 ) ;
break;
case V_109 :
V_60 -> V_68 = false ;
V_60 -> V_89 = V_109 ;
if ( V_60 -> V_95 == V_96 ) {
F_9 ( V_60 -> V_66 , V_14 ,
V_97 ,
1 << V_98 ) ;
} else {
F_14 ( & V_60 -> V_99 ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_100 , 0 ) ;
F_9 ( V_60 -> V_66 , V_14 ,
V_97 , 0 ) ;
V_85 = F_15 ( & V_60 -> V_99 ,
F_16 ( 100 ) ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_100 ,
1 << V_101 ) ;
if ( V_85 == 0 ) {
F_12 ( V_58 -> V_2 , L_6 ) ;
return - V_102 ;
}
}
F_14 ( & V_60 -> V_110 ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_111 , 0 ) ;
F_9 ( V_60 -> V_66 , V_14 ,
V_107 , 0 ) ;
V_85 = F_15 ( & V_60 -> V_110 ,
F_16 ( 100 ) ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_111 ,
1 << V_112 ) ;
if ( V_85 == 0 ) {
F_12 ( V_58 -> V_2 , L_7 ) ;
return - V_102 ;
}
F_9 ( V_60 -> V_66 , V_11 ,
V_103 ,
V_87 << V_104 ) ;
F_9 ( V_60 -> V_66 , V_11 ,
V_105 ,
V_88 << V_106 ) ;
F_17 ( 150 , 200 ) ;
break;
case V_113 :
V_60 -> V_89 = V_113 ;
F_9 ( V_60 -> V_66 , V_11 ,
V_103 ,
V_87 << V_104 ) ;
F_9 ( V_60 -> V_66 , V_11 ,
V_105 ,
V_91 << V_106 ) ;
F_17 ( 150 , 200 ) ;
F_9 ( V_60 -> V_66 , V_14 ,
V_97 ,
1 << V_98 ) ;
F_9 ( V_60 -> V_66 , V_14 ,
V_107 ,
1 << V_108 ) ;
break;
default:
F_12 ( V_58 -> V_2 , L_8 ) ;
return - V_64 ;
}
return 0 ;
}
static const struct V_114 * F_18 (
unsigned int V_115 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < F_5 ( V_116 ) ; V_53 ++ ) {
if ( V_116 [ V_53 ] . V_115 == V_115 )
return & V_116 [ V_53 ] ;
}
return NULL ;
}
static int F_19 ( int V_117 , unsigned int V_118 ,
struct V_66 * V_66 )
{
const struct V_114 * V_119 ;
V_119 = F_18 ( V_118 ) ;
if ( ! V_119 )
return - V_64 ;
switch ( V_117 ) {
case V_120 :
case V_121 :
F_9 ( V_66 , V_30 ,
V_122 , V_119 -> V_123 ) ;
F_9 ( V_66 , V_31 ,
V_122 , V_119 -> V_123 ) ;
F_9 ( V_66 , V_124 ,
V_125 , V_119 -> V_126 ) ;
break;
case V_127 :
F_9 ( V_66 , V_34 ,
V_122 , V_119 -> V_123 ) ;
F_9 ( V_66 , V_35 ,
V_122 , V_119 -> V_123 ) ;
F_9 ( V_66 , V_124 ,
V_128 , V_119 -> V_126 <<
V_129 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static const struct V_130 * F_20 ( int V_131 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < F_5 ( V_132 ) ; V_53 ++ ) {
if ( V_132 [ V_53 ] . V_131 == V_131 )
return & V_132 [ V_53 ] ;
}
return NULL ;
}
static const struct V_133 * F_21 ( int V_63 , int V_131 ,
const struct V_133 * V_134 , int V_135 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_135 ; V_53 ++ ) {
if ( V_134 [ V_53 ] . V_63 == V_63 &&
V_134 [ V_53 ] . V_131 == V_131 )
return & V_134 [ V_53 ] ;
}
return NULL ;
}
static int F_22 ( int V_117 , unsigned int V_136 ,
struct V_137 * V_138 ,
struct V_59 * V_60 )
{
T_1 V_139 ;
T_1 V_140 ;
T_2 V_141 ;
T_2 V_142 ;
T_2 V_143 ;
T_2 V_144 ;
T_2 V_145 ;
T_2 V_146 ;
T_2 V_147 ;
T_2 V_148 ;
T_2 V_149 ;
const struct V_133 * V_150 ;
switch ( V_60 -> V_151 [ V_117 ] . V_152 ) {
case V_153 :
V_140 = V_136 ;
V_141 = 2 ;
V_142 = 0 ;
break;
case V_154 :
V_140 = V_136 ;
V_141 = 2 ;
V_142 = 1 ;
break;
case V_155 :
V_140 = 1 ;
V_141 = 2 ;
V_142 = 1 ;
break;
case V_156 :
V_140 = 1 ;
V_141 = 0 ;
V_142 = 1 ;
break;
default:
return - V_64 ;
}
switch ( V_60 -> V_151 [ V_117 ] . V_157 ) {
case V_158 :
V_149 = 0 ;
break;
case V_159 :
V_149 = 1 ;
break;
default:
return - V_64 ;
}
V_139 = V_136 * F_23 ( V_138 ) ;
V_144 = 1 ;
V_145 = 0 ;
V_147 = 0 ;
V_148 = V_136 * ( F_23 ( V_138 ) - 1 ) ;
V_143 = V_141 & V_160 ;
V_143 |= ( V_142 << V_161 ) & V_162 ;
V_146 = V_145 & V_163 ;
V_146 |= ( V_145 << V_164 ) &
V_165 ;
V_146 |= ( V_144 << V_166 ) &
V_167 ;
V_146 |= ( V_144 << V_168 ) &
V_169 ;
V_146 |= ( V_149 << V_170 ) &
V_171 ;
switch ( V_117 ) {
case V_120 :
case V_121 :
F_9 ( V_60 -> V_66 , V_172 ,
V_173 , ( V_139 - 1 ) >>
V_174 ) ;
F_9 ( V_60 -> V_66 , V_175 ,
V_173 , ( V_139 - 1 ) >>
V_176 ) ;
F_9 ( V_60 -> V_66 , V_177 ,
V_178 , ( V_140 - 1 ) >>
V_179 ) ;
F_9 ( V_60 -> V_66 , V_180 ,
V_178 , ( V_140 - 1 ) >>
V_181 ) ;
F_10 ( V_60 -> V_66 , V_25 , V_143 ) ;
F_10 ( V_60 -> V_66 , V_28 , V_147 ) ;
F_10 ( V_60 -> V_66 , V_29 , V_148 ) ;
F_9 ( V_60 -> V_66 , V_30 ,
V_182 , 1 << V_183 ) ;
F_9 ( V_60 -> V_66 , V_31 ,
V_182 , 1 << V_183 ) ;
F_10 ( V_60 -> V_66 , V_184 , V_146 ) ;
break;
case V_127 :
F_9 ( V_60 -> V_66 , V_185 ,
V_173 , ( V_139 - 1 ) >>
V_174 ) ;
F_9 ( V_60 -> V_66 , V_186 ,
V_173 , ( V_139 - 1 ) >>
V_176 ) ;
F_9 ( V_60 -> V_66 , V_187 ,
V_178 , ( V_140 - 1 ) >>
V_179 ) ;
F_9 ( V_60 -> V_66 , V_188 ,
V_178 , ( V_140 - 1 ) >>
V_181 ) ;
F_10 ( V_60 -> V_66 , V_27 , V_143 ) ;
F_10 ( V_60 -> V_66 , V_32 , V_147 ) ;
F_10 ( V_60 -> V_66 , V_33 , V_148 ) ;
F_9 ( V_60 -> V_66 , V_34 ,
V_182 , 1 << V_183 ) ;
F_9 ( V_60 -> V_66 , V_35 ,
V_182 , 1 << V_183 ) ;
F_10 ( V_60 -> V_66 , V_189 , V_146 ) ;
break;
default:
return - V_64 ;
}
switch ( V_139 ) {
case 16 :
V_150 = F_21 ( V_60 -> V_63 ,
F_24 ( V_138 ) ,
V_190 ,
F_5 ( V_190 ) ) ;
break;
case 32 :
V_150 = F_21 ( V_60 -> V_63 ,
F_24 ( V_138 ) ,
V_191 ,
F_5 ( V_191 ) ) ;
break;
case 48 :
V_150 = F_21 ( V_60 -> V_63 ,
F_24 ( V_138 ) ,
V_192 ,
F_5 ( V_192 ) ) ;
break;
case 64 :
V_150 = F_21 ( V_60 -> V_63 ,
F_24 ( V_138 ) ,
V_193 ,
F_5 ( V_193 ) ) ;
break;
default:
return - V_64 ;
}
if ( ! V_150 )
return - V_64 ;
switch ( V_117 ) {
case V_120 :
case V_121 :
F_10 ( V_60 -> V_66 , V_194 ,
( V_150 -> V_195 & V_196 ) >>
V_197 ) ;
F_10 ( V_60 -> V_66 , V_198 ,
( V_150 -> V_195 & V_199 ) >>
V_200 ) ;
F_10 ( V_60 -> V_66 , V_24 ,
( V_150 -> V_201 & V_202 ) >>
V_203 ) ;
F_10 ( V_60 -> V_66 , V_204 ,
( V_150 -> V_201 & V_205 ) >>
V_206 ) ;
break;
case V_127 :
F_10 ( V_60 -> V_66 , V_207 ,
( V_150 -> V_195 & V_196 ) >>
V_197 ) ;
F_10 ( V_60 -> V_66 , V_208 ,
( V_150 -> V_195 & V_199 ) >>
V_200 ) ;
F_10 ( V_60 -> V_66 , V_26 ,
( V_150 -> V_201 & V_202 ) >>
V_203 ) ;
F_10 ( V_60 -> V_66 , V_209 ,
( V_150 -> V_201 & V_205 ) >>
V_206 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_25 ( bool V_210 , struct V_66 * V_66 )
{
if ( V_210 ) {
F_9 ( V_66 , V_211 ,
V_212 ,
1 << V_213 ) ;
F_17 ( 6000 , 6050 ) ;
F_9 ( V_66 , V_211 ,
V_214 ,
1 << V_215 ) ;
} else {
F_9 ( V_66 , V_211 ,
V_214 ,
0 << V_215 ) ;
F_17 ( 1600 , 1650 ) ;
F_9 ( V_66 , V_211 ,
V_212 ,
0 << V_213 ) ;
}
return 0 ;
}
static int F_26 ( struct V_216 * V_217 ,
struct V_137 * V_138 ,
struct V_218 * V_219 )
{
struct V_57 * V_58 = V_219 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
unsigned int V_220 ;
T_2 V_221 ;
F_27 ( & V_60 -> V_222 ) ;
if ( ! V_60 -> V_223 ) {
if ( ! ( V_90 % F_24 ( V_138 ) ) )
V_220 = V_90 ;
else
V_220 = V_92 ;
F_11 ( V_58 , 0 , 0 , V_60 -> V_62 , V_220 ) ;
if ( V_60 -> V_68 )
F_13 ( V_58 , V_94 ) ;
else
F_13 ( V_58 , V_109 ) ;
}
V_60 -> V_223 ++ ;
if ( V_60 -> V_223 == 2 )
F_25 ( true , V_60 -> V_66 ) ;
F_28 ( & V_60 -> V_222 ) ;
switch ( F_24 ( V_138 ) ) {
case 176400 :
V_221 = 0 ;
break;
case 352800 :
V_221 = 1 ;
break;
default:
F_12 ( V_58 -> V_2 , L_9 ,
F_24 ( V_138 ) ) ;
return - V_64 ;
}
if ( V_60 -> V_151 [ V_219 -> V_224 ] . V_157 == V_159 )
F_9 ( V_60 -> V_66 , V_225 ,
V_226 , V_226 ) ;
else
F_9 ( V_60 -> V_66 , V_225 ,
V_226 , 0 ) ;
F_9 ( V_60 -> V_66 , V_227 ,
V_228 ,
V_221 << V_229 ) ;
F_9 ( V_60 -> V_66 , V_227 ,
V_230 , V_231 <<
V_232 ) ;
return 0 ;
}
static int F_29 ( struct V_216 * V_217 ,
struct V_137 * V_138 ,
struct V_218 * V_219 )
{
struct V_57 * V_58 = V_219 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
const struct V_130 * V_233 ;
unsigned int V_234 = V_60 -> V_151 [ V_219 -> V_224 ] . V_234 ;
unsigned int V_136 ;
unsigned int V_118 = ( unsigned int ) ( F_30 ( V_138 ) ) ;
unsigned int V_220 ;
T_2 V_221 ;
F_27 ( & V_60 -> V_222 ) ;
if ( ! V_60 -> V_223 ) {
if ( ! ( V_90 % F_24 ( V_138 ) ) )
V_220 = V_90 ;
else
V_220 = V_92 ;
F_11 ( V_58 , 0 , 0 , V_60 -> V_62 , V_220 ) ;
if ( V_60 -> V_68 )
F_13 ( V_58 , V_94 ) ;
else
F_13 ( V_58 , V_109 ) ;
}
V_60 -> V_223 ++ ;
if ( V_60 -> V_223 == 2 )
F_25 ( true , V_60 -> V_66 ) ;
F_28 ( & V_60 -> V_222 ) ;
switch ( V_219 -> V_224 ) {
case V_121 :
case V_127 :
V_118 = 24 ;
V_234 = F_24 ( V_138 ) * V_118 *
F_23 ( V_138 ) ;
switch ( F_24 ( V_138 ) ) {
case 176400 :
V_221 = 0 ;
break;
case 352800 :
V_221 = 1 ;
break;
default:
F_12 ( V_58 -> V_2 , L_9 ,
F_24 ( V_138 ) ) ;
return - V_64 ;
}
F_9 ( V_60 -> V_66 , V_227 ,
V_228 ,
V_221 << V_229 ) ;
break;
case V_120 :
V_233 = F_20 ( F_24 ( V_138 ) ) ;
if ( ! V_233 )
return - V_64 ;
F_10 ( V_60 -> V_66 , V_12 , V_233 -> V_235 ) ;
break;
default:
F_12 ( V_58 -> V_2 , L_10 , V_219 -> V_224 ) ;
return - V_64 ;
}
switch ( V_219 -> V_224 ) {
case V_121 :
F_9 ( V_60 -> V_66 , V_227 ,
V_230 , V_236 <<
V_232 ) ;
break;
case V_127 :
F_9 ( V_60 -> V_66 , V_227 ,
V_230 , V_237 <<
V_232 ) ;
}
if ( ! V_234 && V_60 -> V_151 [ V_219 -> V_224 ] . V_157 == V_159 )
V_234 = F_24 ( V_138 ) * V_118 *
F_23 ( V_138 ) ;
if ( ! V_234 ) {
F_12 ( V_58 -> V_2 , L_11 ) ;
return - V_64 ;
}
V_136 = ( V_234 / F_24 ( V_138 ) ) / F_23 ( V_138 ) ;
if ( V_136 < V_118 ) {
F_12 ( V_58 -> V_2 , L_12 ) ;
return - V_64 ;
}
F_8 ( V_58 -> V_2 ,
L_13 ,
V_234 , F_24 ( V_138 ) , V_118 ) ;
F_8 ( V_58 -> V_2 ,
L_14 ,
V_136 , F_23 ( V_138 ) ) ;
F_19 ( V_219 -> V_224 , V_118 , V_60 -> V_66 ) ;
F_22 ( V_219 -> V_224 , V_136 , V_138 , V_60 ) ;
return 0 ;
}
static int F_31 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
struct V_57 * V_58 = V_219 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
F_27 ( & V_60 -> V_222 ) ;
V_60 -> V_223 -- ;
if ( ! V_60 -> V_223 ) {
F_13 ( V_58 , V_113 ) ;
F_25 ( false , V_60 -> V_66 ) ;
}
F_28 ( & V_60 -> V_222 ) ;
return 0 ;
}
static int F_32 ( struct V_238 * V_239 ,
struct V_240 * V_241 )
{
return F_33 ( V_239 , V_241 ) ;
}
static int F_34 ( struct V_238 * V_239 ,
struct V_240 * V_241 )
{
struct V_242 * V_243 = (struct V_242 * ) V_239 -> V_244 ;
unsigned int * V_245 = V_241 -> V_246 . V_247 . V_245 ;
struct V_57 * V_58 = F_35 ( V_239 ) ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
unsigned int V_235 ;
if ( V_245 [ 0 ] >= V_243 -> V_248 )
return - V_64 ;
V_235 = F_36 ( V_243 , V_245 [ 0 ] ) << V_243 -> V_249 ;
switch ( V_60 -> V_250 ) {
case V_251 :
case V_252 :
if ( V_235 >= 2 )
F_37 ( V_60 -> V_66 , V_253 ,
F_5 ( V_253 ) ) ;
else
F_37 ( V_60 -> V_66 , V_254 ,
F_5 ( V_254 ) ) ;
}
return F_38 ( V_239 , V_241 ) ;
}
static int F_39 ( struct V_255 * V_256 ,
struct V_238 * V_239 , int V_257 )
{
struct V_57 * V_58 = F_40 ( V_256 -> V_258 ) ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_257 ) {
case V_259 :
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_262 ,
F_5 ( V_262 ) ) ;
}
break;
case V_263 :
F_9 ( V_60 -> V_66 , V_264 ,
V_265 , 0 ) ;
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_266 ,
F_5 ( V_266 ) ) ;
}
break;
case V_267 :
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_268 ,
F_5 ( V_268 ) ) ;
F_9 ( V_60 -> V_66 ,
V_264 ,
V_265 , V_269 ) ;
F_41 ( 130 ) ;
break;
case V_251 :
case V_252 :
F_9 ( V_60 -> V_66 ,
V_264 ,
V_265 , V_269 ) ;
}
break;
default:
F_12 ( V_58 -> V_2 , L_15 , V_257 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_42 ( struct V_255 * V_256 ,
struct V_238 * V_239 , int V_257 )
{
struct V_57 * V_58 = F_40 ( V_256 -> V_258 ) ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_257 ) {
case V_259 :
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_270 ,
F_5 ( V_270 ) ) ;
}
break;
case V_263 :
F_9 ( V_60 -> V_66 , V_271 ,
V_265 , 0 ) ;
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_266 ,
F_5 ( V_266 ) ) ;
}
break;
case V_267 :
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_268 ,
F_5 ( V_268 ) ) ;
F_9 ( V_60 -> V_66 ,
V_271 ,
V_265 , V_269 ) ;
F_41 ( 130 ) ;
break;
case V_251 :
case V_252 :
F_9 ( V_60 -> V_66 ,
V_271 ,
V_265 , V_269 ) ;
}
break;
default:
F_12 ( V_58 -> V_2 , L_15 , V_257 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_43 ( struct V_255 * V_256 ,
struct V_238 * V_239 , int V_257 )
{
struct V_57 * V_58 = F_40 ( V_256 -> V_258 ) ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_257 ) {
case V_259 :
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_272 ,
F_5 ( V_272 ) ) ;
break;
case V_251 :
case V_252 :
F_37 ( V_60 -> V_66 , V_273 ,
F_5 ( V_273 ) ) ;
}
break;
case V_263 :
F_17 ( 10000 , 10050 ) ;
F_10 ( V_60 -> V_66 , V_274 , 0x99 ) ;
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_275 ,
F_5 ( V_275 ) ) ;
F_41 ( 1000 ) ;
F_10 ( V_60 -> V_66 , V_276 , 0 ) ;
break;
case V_251 :
case V_252 :
F_17 ( 12000 , 12010 ) ;
F_10 ( V_60 -> V_66 , V_277 , 0 ) ;
}
F_10 ( V_60 -> V_66 , V_274 , 0 ) ;
break;
case V_278 :
switch ( V_60 -> V_250 ) {
case V_260 :
case V_261 :
F_37 ( V_60 -> V_66 , V_279 ,
F_5 ( V_279 ) ) ;
}
break;
default:
F_12 ( V_58 -> V_2 , L_16 , V_257 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_44 ( struct V_255 * V_256 ,
struct V_238 * V_239 , int V_257 )
{
struct V_57 * V_58 = F_40 ( V_256 -> V_258 ) ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_257 ) {
case V_278 :
F_37 ( V_60 -> V_66 , V_280 ,
F_5 ( V_280 ) ) ;
break;
case V_259 :
F_37 ( V_60 -> V_66 , V_281 ,
F_5 ( V_281 ) ) ;
break;
default:
F_12 ( V_58 -> V_2 , L_17 , V_257 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_45 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
return F_46 ( V_217 -> V_282 , 0 ,
V_283 ,
& V_284 ) ;
}
static int F_47 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
return F_46 ( V_217 -> V_282 , 0 ,
V_283 ,
& V_285 ) ;
}
static int F_48 ( struct V_218 * V_286 , unsigned int V_287 )
{
struct V_57 * V_58 = V_286 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_287 & V_288 ) {
case V_158 :
V_60 -> V_151 [ V_286 -> V_224 ] . V_157 = V_158 ;
break;
case V_159 :
V_60 -> V_151 [ V_286 -> V_224 ] . V_157 = V_159 ;
break;
default:
F_12 ( V_58 -> V_2 , L_18 ) ;
return - V_64 ;
}
switch ( V_287 & V_289 ) {
case V_153 :
V_60 -> V_151 [ V_286 -> V_224 ] . V_152 = V_153 ;
break;
case V_154 :
V_60 -> V_151 [ V_286 -> V_224 ] . V_152 = V_154 ;
break;
case V_155 :
V_60 -> V_151 [ V_286 -> V_224 ] . V_152 = V_155 ;
break;
case V_156 :
V_60 -> V_151 [ V_286 -> V_224 ] . V_152 = V_156 ;
break;
default:
F_12 ( V_58 -> V_2 ,
L_19 ) ;
return - V_64 ;
}
F_8 ( V_58 -> V_2 , L_20 ,
V_286 -> V_224 ,
V_60 -> V_151 [ V_286 -> V_224 ] . V_157 ,
V_60 -> V_151 [ V_286 -> V_224 ] . V_152 ) ;
return 0 ;
}
static int F_49 ( struct V_218 * V_286 , unsigned int V_287 )
{
struct V_57 * V_58 = V_286 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
switch ( V_287 & V_288 ) {
case V_158 :
V_60 -> V_151 [ V_286 -> V_224 ] . V_157 = V_158 ;
break;
case V_159 :
V_60 -> V_151 [ V_286 -> V_224 ] . V_157 = V_159 ;
break;
default:
F_12 ( V_58 -> V_2 , L_21 ) ;
return - V_64 ;
}
F_8 ( V_58 -> V_2 , L_22 ,
V_60 -> V_151 [ V_286 -> V_224 ] . V_157 ) ;
return 0 ;
}
static int F_50 ( struct V_218 * V_286 ,
int V_290 , unsigned int V_291 , int V_292 )
{
struct V_57 * V_58 = V_286 -> V_58 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
V_60 -> V_151 [ V_286 -> V_224 ] . V_234 = V_291 ;
F_8 ( V_58 -> V_2 , L_23 , V_286 -> V_224 ,
V_60 -> V_151 [ V_286 -> V_224 ] . V_234 ) ;
return 0 ;
}
static int F_51 ( struct V_57 * V_58 ,
int V_290 , int V_84 , unsigned int V_291 ,
int V_292 )
{
struct V_59 * V_60 = F_7 ( V_58 ) ;
F_8 ( V_58 -> V_2 , L_24 ,
V_290 , V_84 , V_291 , V_292 ) ;
switch ( V_291 ) {
case V_90 :
case V_92 :
V_60 -> V_62 = V_291 ;
break;
default:
F_12 ( V_58 -> V_2 , L_5 , V_291 ) ;
return - V_64 ;
}
if ( V_84 == V_94 ) {
V_60 -> V_68 = true ;
} else {
F_12 ( V_58 -> V_2 , L_25 ) ;
return - V_64 ;
}
return 0 ;
}
static inline T_1 F_52 ( T_1 V_293 )
{
return V_293 / 6 ;
}
static int F_53 ( struct V_1 * V_2 , char * V_294 , T_2 V_295 )
{
struct V_296 * V_297 = F_54 ( V_2 ) ;
struct V_59 * V_60 = F_55 ( V_297 ) ;
if ( ! V_60 -> V_298 )
return F_56 ( V_294 , V_299 , L_26 ) ;
else
return F_56 ( V_294 , V_299 , L_27 ,
V_60 -> V_300 [ V_295 ] ) ;
}
static T_3 F_57 ( struct V_1 * V_2 ,
struct V_301 * V_302 , char * V_294 )
{
return F_53 ( V_2 , V_294 , V_303 ) ;
}
static T_3 F_58 ( struct V_1 * V_2 ,
struct V_301 * V_302 , char * V_294 )
{
return F_53 ( V_2 , V_294 , V_304 ) ;
}
static int F_59 ( struct V_1 * V_2 , char * V_294 , T_2 V_295 )
{
int V_53 , V_305 = 0 , V_306 ;
struct V_296 * V_297 = F_54 ( V_2 ) ;
struct V_59 * V_60 = F_55 ( V_297 ) ;
if ( V_60 -> V_298 && V_60 -> V_307 ) {
for ( V_53 = 0 ; V_53 < F_5 ( V_308 ) ; V_53 ++ ) {
V_306 = F_56 ( V_294 + V_305 , V_299 - V_305 , L_27 ,
V_60 -> V_309 [ V_53 ] [ V_295 ] ) ;
if ( ! V_306 )
break;
V_305 += V_306 ;
}
return V_305 ;
} else {
return F_56 ( V_294 , V_299 , L_26 ) ;
}
}
static T_3 F_60 ( struct V_1 * V_2 ,
struct V_301 * V_302 , char * V_294 )
{
return F_59 ( V_2 , V_294 , V_303 ) ;
}
static T_3 F_61 ( struct V_1 * V_2 ,
struct V_301 * V_302 , char * V_294 )
{
return F_59 ( V_2 , V_294 , V_304 ) ;
}
static int F_62 ( unsigned int V_310 , int V_311 ,
struct V_59 * V_60 )
{
bool V_312 = true ;
unsigned int V_3 ;
T_4 V_313 ;
T_1 V_314 ;
struct V_57 * V_58 = V_60 -> V_58 ;
switch ( V_310 ) {
case V_315 :
case V_316 :
break;
default:
return 0 ;
}
F_63 ( V_60 -> V_66 , V_44 , & V_3 ) ;
if ( V_3 & V_317 )
V_312 = false ;
if ( V_310 == V_315 )
V_313 = V_6 ;
else
V_313 = V_8 ;
F_63 ( V_60 -> V_66 , V_313 , & V_3 ) ;
V_314 = V_3 >> 3 ;
F_63 ( V_60 -> V_66 , V_313 + 1 , & V_3 ) ;
V_314 |= V_3 << 5 ;
if ( V_310 == V_315 ) {
if ( V_312 )
V_60 -> V_300 [ V_303 ] = V_314 ;
else
V_60 -> V_300 [ V_304 ] = V_314 ;
F_8 ( V_58 -> V_2 , L_28 , ! V_312 ,
V_314 ) ;
} else {
if ( V_312 )
V_60 -> V_309 [ V_311 ] [ V_303 ] = V_314 ;
else
V_60 -> V_309 [ V_311 ] [ V_304 ] = V_314 ;
F_8 ( V_58 -> V_2 , L_29 ,
V_60 -> V_293 [ V_311 ] , ! V_312 , V_314 ) ;
}
return 0 ;
}
static int F_64 ( struct V_59 * V_60 ,
struct V_318 * V_319 , int V_320 ,
unsigned int V_321 , int V_311 )
{
int V_85 ;
unsigned int V_310 ;
T_1 V_322 ;
struct V_57 * V_58 = V_60 -> V_58 ;
F_14 ( & V_60 -> V_323 ) ;
if ( V_321 == V_316 ) {
V_322 = F_52 ( V_60 -> V_293 [ V_311 ] ) ;
F_9 ( V_60 -> V_66 , V_44 ,
V_324 , 0 ) ;
F_9 ( V_60 -> V_66 , V_45 ,
V_325 ,
V_322 >> V_326 ) ;
F_9 ( V_60 -> V_66 , V_46 ,
V_325 ,
V_322 >> V_327 ) ;
}
F_37 ( V_60 -> V_66 , V_319 ,
V_320 ) ;
V_85 = F_15 ( & V_60 -> V_323 ,
F_16 ( 1000 ) ) ;
F_63 ( V_60 -> V_66 , V_328 , & V_310 ) ;
if ( ! V_85 ) {
F_12 ( V_58 -> V_2 , L_30 ) ;
return - 1 ;
}
F_8 ( V_58 -> V_2 , L_31 ,
V_60 -> V_329 , V_310 ) ;
if ( ( V_60 -> V_329 & ( V_330 |
V_331 |
V_332 ) ) ||
! ( V_60 -> V_329 & V_321 ) ) {
F_8 ( V_58 -> V_2 , L_32 ) ;
return - 1 ;
}
return 0 ;
}
static int F_65 ( struct V_66 * V_66 , T_1 V_300 ,
const T_1 * V_333 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_334 ; V_53 ++ ) {
if ( V_300 <= V_333 [ V_53 ] )
break;
}
F_37 ( V_66 , V_335 [ V_53 ] , F_5 ( V_335 [ V_53 ] ) ) ;
return 0 ;
}
static void F_66 ( struct V_336 * V_337 )
{
unsigned int V_3 , V_320 ;
int V_53 , V_85 , V_311 ;
struct V_59 * V_60 ;
struct V_57 * V_58 ;
struct V_338 * V_339 ;
V_60 = F_67 ( V_337 , struct V_59 , V_340 ) ;
V_58 = V_60 -> V_58 ;
if ( ! V_60 -> V_62 )
return;
V_60 -> V_298 = false ;
F_27 ( & V_60 -> V_222 ) ;
if ( ! V_60 -> V_223 ) {
F_11 ( V_58 , 0 , 0 , V_60 -> V_62 , V_90 ) ;
if ( V_60 -> V_68 )
F_13 ( V_58 , V_94 ) ;
else
F_13 ( V_58 , V_109 ) ;
}
V_60 -> V_223 ++ ;
F_28 ( & V_60 -> V_222 ) ;
F_63 ( V_60 -> V_66 , V_341 , & V_3 ) ;
switch ( V_60 -> V_250 ) {
case V_260 :
V_339 = V_342 ;
V_320 = F_5 ( V_342 ) ;
break;
case V_251 :
V_339 = V_343 ;
V_320 = F_5 ( V_343 ) ;
break;
default:
F_68 ( 1 , L_33 , V_60 -> V_250 ) ;
return;
}
V_53 = 0 ;
V_311 = 0 ;
while ( V_53 < V_320 ) {
V_85 = F_64 ( V_60 , V_339 [ V_53 ] . V_319 ,
V_339 [ V_53 ] . V_344 ,
V_339 [ V_53 ] . V_310 , V_311 ) ;
if ( V_85 < 0 )
goto exit;
F_62 ( V_339 [ V_53 ] . V_310 , V_311 , V_60 ) ;
if ( V_60 -> V_307 &&
V_339 [ V_53 ] . V_310 == V_316 &&
V_311 < V_345 - 1 ) {
V_311 ++ ;
} else {
V_311 = 0 ;
V_53 ++ ;
}
}
V_60 -> V_298 = true ;
if ( V_60 -> V_300 [ V_303 ] >= V_346 )
F_69 ( & V_60 -> V_347 , V_348 ,
V_349 ) ;
else
F_69 ( & V_60 -> V_347 , V_350 ,
V_349 ) ;
F_8 ( V_58 -> V_2 , L_34 ) ;
for ( V_53 = 0 ; V_53 < V_334 ; V_53 ++ )
F_8 ( V_58 -> V_2 , L_35 , V_53 ,
V_60 -> V_333 [ V_53 ] ) ;
F_65 ( V_60 -> V_66 , V_60 -> V_300 [ V_303 ] ,
V_60 -> V_333 ) ;
exit:
switch ( V_60 -> V_250 ) {
case V_260 :
F_64 ( V_60 , V_351 ,
F_5 ( V_351 ) ,
V_352 , V_311 ) ;
break;
case V_251 :
F_64 ( V_60 , V_353 ,
F_5 ( V_353 ) ,
V_352 , V_311 ) ;
}
F_37 ( V_60 -> V_66 , V_354 ,
F_5 ( V_354 ) ) ;
F_27 ( & V_60 -> V_222 ) ;
V_60 -> V_223 -- ;
if ( ! V_60 -> V_223 )
F_13 ( V_58 , V_113 ) ;
F_28 ( & V_60 -> V_222 ) ;
}
static T_5 F_70 ( int V_355 , void * V_356 )
{
struct V_59 * V_60 = (struct V_59 * ) V_356 ;
struct V_57 * V_58 = V_60 -> V_58 ;
unsigned int V_357 [ V_358 ] ;
unsigned int V_359 = 0 ;
unsigned int V_360 [ V_358 ] ;
int V_53 , V_305 ;
for ( V_53 = 0 ; V_53 < F_5 ( V_357 ) ; V_53 ++ ) {
F_63 ( V_60 -> V_66 , V_4 + V_53 ,
& V_357 [ V_53 ] ) ;
F_63 ( V_60 -> V_66 , V_48 + V_53 ,
& V_360 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < F_5 ( V_357 ) ; V_53 ++ ) {
V_357 [ V_53 ] = V_357 [ V_53 ] & ( ~ V_360 [ V_53 ] ) ;
for ( V_305 = 0 ; V_305 < 8 ; V_305 ++ )
V_359 += ( V_357 [ V_53 ] >> V_305 ) & 1 ;
}
F_8 ( V_58 -> V_2 , L_36 ,
V_359 ) ;
if ( ! V_359 )
return V_361 ;
if ( V_357 [ 0 ] & V_362 ) {
F_71 ( & V_60 -> V_99 ) ;
return V_363 ;
}
if ( V_357 [ 0 ] & V_364 ) {
F_71 ( & V_60 -> V_110 ) ;
return V_363 ;
}
if ( V_357 [ 3 ] & V_330 ) {
V_60 -> V_329 = V_357 [ 3 ] ;
F_12 ( V_58 -> V_2 ,
L_37 ,
V_60 -> V_329 ) ;
F_71 ( & V_60 -> V_323 ) ;
return V_363 ;
}
if ( V_357 [ 3 ] & V_331 ) {
V_60 -> V_329 = V_357 [ 3 ] ;
F_12 ( V_58 -> V_2 , L_38 ,
V_60 -> V_329 ) ;
F_71 ( & V_60 -> V_323 ) ;
return V_363 ;
}
if ( V_357 [ 3 ] & V_332 ) {
V_60 -> V_329 = V_357 [ 3 ] ;
F_12 ( V_58 -> V_2 , L_39 ,
V_60 -> V_329 ) ;
F_71 ( & V_60 -> V_323 ) ;
return V_363 ;
}
if ( V_357 [ 3 ] & V_316 ) {
V_60 -> V_329 = V_357 [ 3 ] ;
F_8 ( V_58 -> V_2 , L_40 ,
V_60 -> V_329 ) ;
F_71 ( & V_60 -> V_323 ) ;
return V_363 ;
}
if ( V_357 [ 3 ] & V_315 ) {
V_60 -> V_329 = V_357 [ 3 ] ;
F_8 ( V_58 -> V_2 , L_41 ,
V_60 -> V_329 ) ;
F_71 ( & V_60 -> V_323 ) ;
return V_363 ;
}
if ( V_357 [ 3 ] & V_365 ) {
V_60 -> V_329 = V_357 [ 3 ] ;
F_8 ( V_58 -> V_2 , L_42 ,
V_60 -> V_329 ) ;
F_71 ( & V_60 -> V_323 ) ;
return V_363 ;
}
if ( V_357 [ 3 ] & V_352 ) {
V_60 -> V_329 = V_357 [ 3 ] ;
F_8 ( V_58 -> V_2 , L_43 ,
V_60 -> V_329 ) ;
F_71 ( & V_60 -> V_323 ) ;
return V_363 ;
}
if ( V_357 [ 0 ] & V_366 ) {
F_12 ( V_58 -> V_2 , L_44 ) ;
return V_363 ;
}
if ( V_357 [ 0 ] & V_367 ) {
F_8 ( V_58 -> V_2 , L_45 ) ;
V_60 -> V_298 = false ;
F_69 ( & V_60 -> V_347 , 0 , V_349 ) ;
return V_363 ;
}
if ( V_357 [ 0 ] & V_368 ) {
if ( V_60 -> V_369 && ! V_60 -> V_298 &&
! F_72 ( & V_60 -> V_340 ) ) {
F_8 ( V_58 -> V_2 , L_46 ) ;
F_73 ( V_60 -> V_370 , & V_60 -> V_340 ) ;
}
F_69 ( & V_60 -> V_347 , V_371 ,
V_349 ) ;
return V_363 ;
}
return V_361 ;
}
static int F_74 ( struct V_57 * V_58 )
{
int V_85 ;
struct V_59 * V_60 = F_7 ( V_58 ) ;
struct V_372 * V_373 = V_58 -> V_374 . V_373 ;
unsigned int V_3 ;
V_60 -> V_58 = V_58 ;
if ( V_60 -> V_95 != V_96 ) {
F_9 ( V_60 -> V_66 , V_15 ,
V_375 ,
V_60 -> V_95 ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_366 , 0 ) ;
}
V_85 = F_75 ( V_373 , L_47 , V_349 ,
& V_60 -> V_347 , NULL , 0 ) ;
if ( V_85 < 0 ) {
F_12 ( V_58 -> V_2 , L_48 ) ;
return V_85 ;
}
V_60 -> V_298 = false ;
if ( V_60 -> V_369 ) {
V_85 = F_76 ( V_58 -> V_2 , & V_376 ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = F_76 ( V_58 -> V_2 , & V_377 ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = F_76 ( V_58 -> V_2 , & V_378 ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = F_76 ( V_58 -> V_2 , & V_379 ) ;
if ( V_85 < 0 )
return V_85 ;
V_60 -> V_370 = F_77 ( L_49 ) ;
F_78 ( & V_60 -> V_340 , F_66 ) ;
}
F_63 ( V_60 -> V_66 , V_4 , & V_3 ) ;
F_63 ( V_60 -> V_66 , V_43 , & V_3 ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_368 | V_367 , 0 ) ;
F_9 ( V_60 -> V_66 , V_42 ,
V_380 , 0 ) ;
F_9 ( V_60 -> V_66 , V_42 ,
V_380 ,
V_380 ) ;
return 0 ;
}
static int F_79 ( struct V_296 * V_296 ,
struct V_59 * V_60 )
{
struct V_381 * V_382 = V_296 -> V_2 . V_383 ;
unsigned int V_235 ;
int V_53 ;
if ( F_80 ( V_382 , L_50 , & V_235 ) < 0 ) {
V_60 -> V_95 = V_96 ;
return 0 ;
}
switch ( V_235 ) {
case 1 :
V_60 -> V_95 = V_384 ;
break;
case 2 :
V_60 -> V_95 = V_385 ;
break;
case 3 :
V_60 -> V_95 = V_386 ;
break;
default:
F_12 ( & V_296 -> V_2 ,
L_51 , V_235 ) ;
return - V_64 ;
}
V_60 -> V_369 = F_81 ( V_382 , L_52 ) ;
V_60 -> V_307 = F_81 ( V_382 , L_53 ) ;
if ( F_82 ( V_382 , L_54 , V_60 -> V_293 ,
V_345 ) < 0 ) {
for ( V_53 = 0 ; V_53 < V_345 ; V_53 ++ )
V_60 -> V_293 [ V_53 ] = V_308 [ V_53 ] ;
}
if ( F_82 ( V_382 , L_55 ,
V_60 -> V_333 ,
V_334 ) < 0 ) {
for ( V_53 = 0 ; V_53 < V_334 ; V_53 ++ )
V_60 -> V_333 [ V_53 ] = V_387 [ V_53 ] ;
}
return 0 ;
}
static int F_83 ( struct V_296 * V_297 ,
const struct V_388 * V_224 )
{
struct V_59 * V_60 ;
int V_85 ;
unsigned int V_389 = 0 ;
unsigned int V_3 ;
int V_53 ;
V_60 = F_84 ( & V_297 -> V_2 , sizeof( * V_60 ) , V_390 ) ;
if ( ! V_60 )
return - V_391 ;
F_85 ( V_297 , V_60 ) ;
V_60 -> V_66 = F_86 ( V_297 , & V_392 ) ;
if ( F_87 ( V_60 -> V_66 ) ) {
V_85 = F_88 ( V_60 -> V_66 ) ;
return V_85 ;
}
if ( V_297 -> V_2 . V_383 ) {
V_85 = F_79 ( V_297 , V_60 ) ;
if ( V_85 != 0 )
return V_85 ;
}
for ( V_53 = 0 ; V_53 < F_5 ( V_60 -> V_393 ) ; V_53 ++ )
V_60 -> V_393 [ V_53 ] . V_394 = V_395 [ V_53 ] ;
V_85 = F_89 ( & V_297 -> V_2 ,
F_5 ( V_60 -> V_393 ) ,
V_60 -> V_393 ) ;
if ( V_85 != 0 ) {
F_12 ( & V_297 -> V_2 , L_56 , V_85 ) ;
return V_85 ;
}
V_85 = F_90 ( F_5 ( V_60 -> V_393 ) ,
V_60 -> V_393 ) ;
if ( V_85 != 0 ) {
F_12 ( & V_297 -> V_2 , L_57 , V_85 ) ;
return V_85 ;
}
V_60 -> V_396 = F_91 ( & V_297 -> V_2 ,
L_58 , V_397 ) ;
if ( F_87 ( V_60 -> V_396 ) )
return F_88 ( V_60 -> V_396 ) ;
F_92 ( V_60 -> V_396 , 1 ) ;
F_17 ( 2000 , 2050 ) ;
V_85 = F_63 ( V_60 -> V_66 , V_10 , & V_3 ) ;
V_389 = ( V_3 & 0xFF ) << 12 ;
V_85 = F_63 ( V_60 -> V_66 , V_398 , & V_3 ) ;
V_389 |= ( V_3 & 0xFF ) << 4 ;
V_85 = F_63 ( V_60 -> V_66 , V_399 , & V_3 ) ;
V_389 |= ( V_3 & 0xF0 ) >> 4 ;
switch ( V_389 ) {
case V_260 :
case V_261 :
case V_251 :
case V_252 :
break;
default:
F_12 ( & V_297 -> V_2 ,
L_59 ,
V_389 , V_260 , V_261 ,
V_251 , V_252 ) ;
V_85 = - V_400 ;
goto V_401;
}
V_60 -> V_250 = V_389 ;
V_85 = F_63 ( V_60 -> V_66 , V_402 , & V_3 ) ;
if ( V_85 < 0 ) {
F_12 ( & V_297 -> V_2 , L_60 ) ;
goto V_401;
}
F_93 ( & V_297 -> V_2 ,
L_61 , V_389 ,
V_3 & 0xFF ) ;
F_94 ( & V_60 -> V_222 ) ;
F_95 ( & V_60 -> V_99 ) ;
F_95 ( & V_60 -> V_110 ) ;
F_95 ( & V_60 -> V_323 ) ;
V_85 = F_96 ( & V_297 -> V_2 , V_297 -> V_355 ,
NULL , F_70 ,
V_403 | V_404 ,
L_62 , V_60 ) ;
if ( V_85 != 0 ) {
F_12 ( & V_297 -> V_2 , L_63 , V_85 ) ;
return V_85 ;
}
V_60 -> V_89 = V_113 ;
F_97 ( & V_297 -> V_2 , 100 ) ;
F_98 ( & V_297 -> V_2 ) ;
F_99 ( & V_297 -> V_2 ) ;
F_100 ( & V_297 -> V_2 ) ;
switch ( V_60 -> V_250 ) {
case V_260 :
case V_251 :
memcpy ( V_405 , V_406 ,
sizeof( V_406 ) ) ;
memcpy ( V_405 + F_5 ( V_406 ) ,
V_407 , sizeof( V_407 ) ) ;
memcpy ( V_408 , V_409 ,
sizeof( V_409 ) ) ;
memcpy ( V_408 + F_5 ( V_409 ) ,
V_410 , sizeof( V_410 ) ) ;
V_411 . V_412 . V_413 =
V_405 ;
V_411 . V_412 . V_414 =
F_5 ( V_405 ) ;
V_411 . V_412 . V_415 =
V_408 ;
V_411 . V_412 . V_416 =
F_5 ( V_408 ) ;
break;
case V_252 :
case V_261 :
V_411 . V_412 . V_413 =
V_406 ;
V_411 . V_412 . V_414 =
F_5 ( V_406 ) ;
V_411 . V_412 . V_415 =
V_409 ;
V_411 . V_412 . V_416 =
F_5 ( V_409 ) ;
}
V_85 = F_101 ( & V_297 -> V_2 , & V_411 ,
V_417 , F_5 ( V_417 ) ) ;
if ( V_85 < 0 ) {
F_12 ( & V_297 -> V_2 ,
L_64 , V_85 ) ;
goto V_401;
}
F_9 ( V_60 -> V_66 , V_13 ,
V_418 , 0 ) ;
F_9 ( V_60 -> V_66 , V_13 ,
V_419 , 0 ) ;
return 0 ;
V_401:
return V_85 ;
}
static int F_102 ( struct V_296 * V_297 )
{
struct V_59 * V_60 = F_55 ( V_297 ) ;
if ( V_60 -> V_95 != V_96 )
F_9 ( V_60 -> V_66 , V_48 ,
V_366 ,
1 << V_420 ) ;
F_9 ( V_60 -> V_66 , V_48 ,
V_368 | V_367 ,
V_368 | V_367 ) ;
if ( V_60 -> V_369 ) {
F_103 ( & V_60 -> V_340 ) ;
F_104 ( V_60 -> V_370 ) ;
F_105 ( & V_297 -> V_2 , & V_376 ) ;
F_105 ( & V_297 -> V_2 , & V_377 ) ;
F_105 ( & V_297 -> V_2 , & V_378 ) ;
F_105 ( & V_297 -> V_2 , & V_379 ) ;
}
if ( V_60 -> V_396 )
F_92 ( V_60 -> V_396 , 0 ) ;
F_106 ( & V_297 -> V_2 ) ;
F_107 ( V_421 , V_60 -> V_393 ) ;
F_108 ( & V_297 -> V_2 ) ;
return 0 ;
}
static int T_6 F_109 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_110 ( V_2 ) ;
if ( V_60 -> V_95 != V_96 )
F_9 ( V_60 -> V_66 , V_48 ,
V_366 ,
1 << V_420 ) ;
F_111 ( V_60 -> V_66 , true ) ;
F_112 ( V_60 -> V_66 ) ;
F_92 ( V_60 -> V_396 , 0 ) ;
F_107 ( V_421 , V_60 -> V_393 ) ;
return 0 ;
}
static int T_6 F_113 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_110 ( V_2 ) ;
int V_85 ;
V_85 = F_90 ( V_421 , V_60 -> V_393 ) ;
if ( V_85 != 0 ) {
F_12 ( V_2 , L_57 , V_85 ) ;
return V_85 ;
}
F_111 ( V_60 -> V_66 , false ) ;
F_92 ( V_60 -> V_396 , 1 ) ;
F_17 ( 2000 , 2050 ) ;
V_85 = F_114 ( V_60 -> V_66 ) ;
if ( V_85 != 0 ) {
F_12 ( V_2 , L_65 ) ;
goto V_401;
}
if ( V_60 -> V_95 != V_96 )
F_9 ( V_60 -> V_66 , V_48 ,
V_366 , 0 ) ;
return 0 ;
V_401:
F_111 ( V_60 -> V_66 , true ) ;
F_107 ( V_421 , V_60 -> V_393 ) ;
return V_85 ;
}
