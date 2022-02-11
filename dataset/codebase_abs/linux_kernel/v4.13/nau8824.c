static int F_1 ( struct V_1 * V_1 , long V_2 )
{
int V_3 ;
if ( V_2 ) {
V_3 = F_2 ( & V_1 -> V_4 , V_2 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_1 ) ;
} else {
V_3 = F_4 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_2 ) ;
}
return V_3 ;
}
static inline void F_5 ( struct V_1 * V_1 )
{
F_6 ( & V_1 -> V_4 ) ;
}
static bool F_7 ( struct V_6 * V_5 , unsigned int V_7 )
{
switch ( V_7 ) {
case V_8 ... V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 ... V_14 :
case V_15 :
case V_16 ... V_17 :
case V_18 ... V_19 :
case V_20 ... V_21 :
case V_22 ... V_23 :
case V_24 ... V_25 :
case V_26 ... V_27 :
case V_28 ... V_29 :
case V_30 :
case V_31 ... V_32 :
case V_33 ... V_34 :
case V_35 ... V_36 :
case V_37 ... V_38 :
return true ;
default:
return false ;
}
}
static bool F_8 ( struct V_6 * V_5 , unsigned int V_7 )
{
switch ( V_7 ) {
case V_39 ... V_9 :
case V_10 :
case V_11 :
case V_13 ... V_14 :
case V_15 :
case V_16 ... V_17 :
case V_18 ... V_19 :
case V_20 ... V_21 :
case V_22 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_24 ... V_47 :
case V_26 ... V_27 :
case V_30 :
case V_33 ... V_34 :
case V_35 ... V_36 :
case V_37 ... V_48 :
return true ;
default:
return false ;
}
}
static bool F_9 ( struct V_6 * V_5 , unsigned int V_7 )
{
switch ( V_7 ) {
case V_39 :
case V_12 ... V_13 :
case V_49 ... V_23 :
case V_50 ... V_25 :
case V_28 ... V_29 :
case V_31 ... V_32 :
case V_38 :
return true ;
default:
return false ;
}
}
static int F_10 ( struct V_51 * V_52 ,
struct V_53 * V_54 , int V_55 )
{
struct V_56 * V_57 = F_11 ( V_52 -> V_58 ) ;
struct V_1 * V_1 = F_12 ( V_57 ) ;
switch ( V_55 ) {
case V_59 :
F_13 ( V_1 -> V_60 , V_61 ,
V_62 , 0 ) ;
break;
case V_63 :
F_13 ( V_1 -> V_60 , V_61 ,
V_62 , V_62 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_14 ( struct V_51 * V_52 ,
struct V_53 * V_54 , int V_55 )
{
struct V_56 * V_57 = F_11 ( V_52 -> V_58 ) ;
struct V_1 * V_1 = F_12 ( V_57 ) ;
switch ( V_55 ) {
case V_59 :
F_13 ( V_1 -> V_60 ,
V_65 ,
V_66 , V_66 ) ;
break;
case V_63 :
F_13 ( V_1 -> V_60 ,
V_65 ,
V_66 , 0 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_15 ( struct V_51 * V_52 ,
struct V_53 * V_54 , int V_55 )
{
struct V_56 * V_57 = F_11 ( V_52 -> V_58 ) ;
struct V_1 * V_1 = F_12 ( V_57 ) ;
switch ( V_55 ) {
case V_67 :
F_16 ( 10 ) ;
F_13 ( V_1 -> V_60 ,
V_48 ,
V_68 , V_68 ) ;
break;
case V_69 :
F_13 ( V_1 -> V_60 ,
V_48 ,
V_68 , 0 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_17 ( struct V_51 * V_52 ,
struct V_53 * V_70 , int V_55 )
{
struct V_56 * V_57 = F_11 ( V_52 -> V_58 ) ;
struct V_1 * V_1 = F_12 ( V_57 ) ;
if ( F_18 ( V_55 ) ) {
if ( F_19 ( V_1 ) ) {
F_20 ( V_1 ,
V_71 , 0 ) ;
} else {
F_20 ( V_1 , V_72 , 0 ) ;
}
}
return 0 ;
}
static int F_21 ( struct V_51 * V_52 ,
struct V_53 * V_70 , int V_55 )
{
struct V_56 * V_57 = F_11 ( V_52 -> V_58 ) ;
struct V_1 * V_1 = F_12 ( V_57 ) ;
int V_73 ;
for ( V_73 = 0 ; V_73 < 5 ; V_73 ++ ) {
if ( ( 0x1 << ( 8 - V_73 ) ) * V_1 -> V_74 <= V_75 )
break;
}
F_22 ( V_1 -> V_5 , L_3 , V_73 , V_1 -> V_74 * 256 ) ;
F_13 ( V_1 -> V_60 , V_76 ,
V_77 , ( V_73 << V_78 ) ) ;
return 0 ;
}
static bool F_19 ( struct V_1 * V_1 )
{
struct V_79 * V_80 = V_1 -> V_80 ;
bool V_81 = FALSE ;
if ( V_1 -> V_82 && V_80 )
V_81 = V_80 -> V_83 & V_84 ;
return V_81 ;
}
static void F_23 ( struct V_60 * V_60 )
{
int V_85 , V_86 , V_87 ;
F_24 ( V_60 , V_12 , & V_85 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
V_86 = ( 0x1 << V_87 ) ;
if ( V_85 & V_86 )
F_25 ( V_60 ,
V_13 , V_86 ) ;
}
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_89 * V_58 = V_1 -> V_58 ;
struct V_60 * V_60 = V_1 -> V_60 ;
F_23 ( V_60 ) ;
F_27 ( V_58 , L_4 ) ;
F_27 ( V_58 , L_5 ) ;
F_28 ( V_58 ) ;
F_13 ( V_60 , V_90 ,
V_91 | V_92 |
V_93 | V_94 ,
V_91 | V_92 |
V_93 ) ;
F_13 ( V_60 , V_11 ,
V_95 | V_96 ,
V_95 ) ;
F_13 ( V_60 , V_8 ,
V_97 , V_97 ) ;
F_20 ( V_1 , V_72 , 0 ) ;
}
static void F_29 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_30 (
V_99 , struct V_1 , V_100 ) ;
struct V_89 * V_58 = V_1 -> V_58 ;
struct V_60 * V_60 = V_1 -> V_60 ;
int V_101 , V_55 = 0 , V_102 = 0 ;
F_31 ( V_58 , L_5 ) ;
F_31 ( V_58 , L_4 ) ;
F_28 ( V_58 ) ;
F_16 ( 100 ) ;
F_24 ( V_60 , V_32 , & V_101 ) ;
V_101 = V_101 & V_103 ;
F_22 ( V_1 -> V_5 , L_6 , V_101 ) ;
if ( V_101 < V_104 ) {
V_55 |= V_84 ;
F_27 ( V_58 , L_4 ) ;
F_27 ( V_58 , L_5 ) ;
F_28 ( V_58 ) ;
} else {
V_55 |= V_105 ;
}
V_102 |= V_105 ;
F_32 ( V_1 -> V_80 , V_55 , V_102 ) ;
F_5 ( V_1 ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
struct V_60 * V_60 = V_1 -> V_60 ;
F_13 ( V_60 , V_11 ,
V_95 | V_96 ,
V_96 ) ;
F_13 ( V_60 , V_90 ,
V_93 | V_91 |
V_92 , 0 ) ;
F_20 ( V_1 , V_71 , 0 ) ;
F_13 ( V_60 , V_8 ,
V_97 , 0 ) ;
}
static int F_34 ( int V_106 )
{
int V_107 = 0 ;
if ( V_106 & F_35 ( 0 ) )
V_107 |= V_108 ;
if ( V_106 & F_35 ( 1 ) )
V_107 |= V_109 ;
if ( V_106 & F_35 ( 2 ) )
V_107 |= V_110 ;
if ( V_106 & F_35 ( 3 ) )
V_107 |= V_111 ;
if ( V_106 & F_35 ( 4 ) )
V_107 |= V_112 ;
if ( V_106 & F_35 ( 5 ) )
V_107 |= V_113 ;
return V_107 ;
}
static T_1 F_36 ( int V_82 , void * V_114 )
{
struct V_1 * V_1 = (struct V_1 * ) V_114 ;
struct V_60 * V_60 = V_1 -> V_60 ;
int V_85 , V_86 = 0 , V_55 = 0 , V_102 = 0 ;
if ( F_24 ( V_60 , V_12 , & V_85 ) ) {
F_37 ( V_1 -> V_5 , L_7 ) ;
return V_115 ;
}
F_22 ( V_1 -> V_5 , L_8 , V_85 ) ;
if ( V_85 & V_116 ) {
F_26 ( V_1 ) ;
V_102 |= V_105 ;
V_86 = V_116 ;
F_5 ( V_1 ) ;
F_38 ( & V_1 -> V_100 ) ;
} else if ( V_85 & V_117 ) {
int V_118 , V_119 ;
F_24 ( V_60 , V_13 ,
& V_118 ) ;
V_119 = F_34 ( V_118 ) ;
V_55 |= V_119 ;
F_22 ( V_1 -> V_5 , L_9 , V_55 ) ;
V_102 |= V_120 ;
V_86 = V_117 ;
} else if ( V_85 & V_121 ) {
V_102 = V_120 ;
V_86 = V_121 ;
} else if ( V_85 & V_122 ) {
F_13 ( V_60 ,
V_90 ,
V_94 ,
V_94 ) ;
F_13 ( V_60 ,
V_11 ,
V_95 , 0 ) ;
F_38 ( & V_1 -> V_100 ) ;
F_39 ( & V_1 -> V_100 ) ;
F_33 ( V_1 ) ;
}
if ( ! V_86 )
V_86 = V_85 ;
F_25 ( V_60 , V_13 , V_86 ) ;
if ( V_102 )
F_32 ( V_1 -> V_80 , V_55 , V_102 ) ;
return V_123 ;
}
static int F_40 ( struct V_1 * V_1 ,
int V_124 , int V_125 , int V_126 )
{
int V_127 ;
if ( V_124 == V_128 ) {
if ( V_126 >= F_41 ( V_129 ) )
return - V_64 ;
V_127 = V_129 [ V_126 ] . V_126 ;
} else {
if ( V_126 >= F_41 ( V_130 ) )
return - V_64 ;
V_127 = V_130 [ V_126 ] . V_126 ;
}
if ( ! V_127 || V_125 * V_126 > V_131 ) {
F_37 ( V_1 -> V_5 , L_10 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_42 ( struct V_132 * V_133 ,
struct V_134 * V_135 , struct V_136 * V_137 )
{
struct V_56 * V_57 = V_137 -> V_57 ;
struct V_1 * V_1 = F_12 ( V_57 ) ;
unsigned int V_138 = 0 , V_126 , V_139 , V_140 , V_141 ;
F_1 ( V_1 , V_142 ) ;
V_1 -> V_74 = F_43 ( V_135 ) ;
if ( V_133 -> V_124 == V_128 ) {
F_24 ( V_1 -> V_60 ,
V_143 , & V_126 ) ;
V_126 &= V_144 ;
if ( F_40 ( V_1 , V_133 -> V_124 ,
V_1 -> V_74 , V_126 ) )
return - V_64 ;
F_13 ( V_1 -> V_60 , V_76 ,
V_145 ,
V_129 [ V_126 ] . V_146 << V_147 ) ;
} else {
F_24 ( V_1 -> V_60 ,
V_148 , & V_126 ) ;
V_126 &= V_149 ;
if ( F_40 ( V_1 , V_133 -> V_124 ,
V_1 -> V_74 , V_126 ) )
return - V_64 ;
F_13 ( V_1 -> V_60 , V_76 ,
V_150 ,
V_130 [ V_126 ] . V_146 << V_151 ) ;
}
F_24 ( V_1 -> V_60 ,
V_152 , & V_139 ) ;
if ( V_139 & V_153 ) {
V_140 = F_44 ( V_135 ) / V_1 -> V_74 ;
if ( V_140 <= 32 )
V_141 = 0x3 ;
else if ( V_140 <= 64 )
V_141 = 0x2 ;
else if ( V_140 <= 128 )
V_141 = 0x1 ;
else if ( V_140 <= 256 )
V_141 = 0 ;
else
return - V_64 ;
F_13 ( V_1 -> V_60 ,
V_152 ,
V_154 | V_155 ,
( V_141 << V_156 ) | V_141 ) ;
}
switch ( F_45 ( V_135 ) ) {
case 16 :
V_138 |= V_157 ;
break;
case 20 :
V_138 |= V_158 ;
break;
case 24 :
V_138 |= V_159 ;
break;
case 32 :
V_138 |= V_160 ;
break;
default:
return - V_64 ;
}
F_13 ( V_1 -> V_60 , V_16 ,
V_161 , V_138 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
static int F_46 ( struct V_136 * V_137 , unsigned int V_162 )
{
struct V_56 * V_57 = V_137 -> V_57 ;
struct V_1 * V_1 = F_12 ( V_57 ) ;
unsigned int V_163 = 0 , V_164 = 0 ;
F_1 ( V_1 , V_142 ) ;
switch ( V_162 & V_165 ) {
case V_166 :
V_164 |= V_153 ;
break;
case V_167 :
break;
default:
return - V_64 ;
}
switch ( V_162 & V_168 ) {
case V_169 :
break;
case V_170 :
V_163 |= V_171 ;
break;
default:
return - V_64 ;
}
switch ( V_162 & V_172 ) {
case V_173 :
V_163 |= V_174 ;
break;
case V_175 :
V_163 |= V_176 ;
break;
case V_177 :
V_163 |= V_178 ;
break;
case V_179 :
V_163 |= V_180 ;
break;
case V_181 :
V_163 |= V_180 ;
V_163 |= V_182 ;
break;
default:
return - V_64 ;
}
F_13 ( V_1 -> V_60 , V_16 ,
V_183 | V_184 |
V_182 , V_163 ) ;
F_13 ( V_1 -> V_60 , V_152 ,
V_185 , V_164 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
static int F_47 ( struct V_136 * V_137 ,
unsigned int V_186 , unsigned int V_187 , int V_188 , int V_189 )
{
struct V_56 * V_57 = V_137 -> V_57 ;
struct V_1 * V_1 = F_12 ( V_57 ) ;
unsigned int V_190 = 0 , V_139 = 0 ;
if ( V_188 > 4 || ( ( V_186 & 0xf0 ) && ( V_186 & 0xf ) ) ||
( ( V_187 & 0xf0 ) && ( V_187 & 0xf ) ) ||
( ( V_187 & 0xf0 ) && ( V_186 & 0xf ) ) ||
( ( V_187 & 0xf ) && ( V_186 & 0xf0 ) ) )
return - V_64 ;
V_139 |= ( V_191 | V_192 ) ;
if ( V_186 & 0xf0 ) {
V_190 = 4 * V_189 ;
V_139 |= ( V_186 >> 4 ) ;
} else {
V_139 |= V_186 ;
}
if ( V_187 & 0xf0 )
V_139 |= ( ( V_187 >> 4 ) << V_193 ) ;
else
V_139 |= ( V_187 << V_193 ) ;
F_13 ( V_1 -> V_60 , V_17 ,
V_191 | V_192 |
V_194 | V_195 |
V_196 , V_139 ) ;
F_13 ( V_1 -> V_60 , V_197 ,
V_198 , V_190 ) ;
return 0 ;
}
static int F_48 ( unsigned int V_199 ,
unsigned int V_74 , struct V_200 * V_201 )
{
T_2 V_202 , V_203 ;
unsigned int V_204 , V_87 , V_205 ;
for ( V_87 = 0 ; V_87 < F_41 ( V_206 ) ; V_87 ++ ) {
V_204 = V_199 / V_206 [ V_87 ] . V_207 ;
if ( V_204 <= V_208 )
break;
}
if ( V_87 == F_41 ( V_206 ) )
return - V_64 ;
V_201 -> V_209 = V_206 [ V_87 ] . V_210 ;
for ( V_87 = 0 ; V_87 < F_41 ( V_211 ) ; V_87 ++ ) {
if ( V_204 >= V_211 [ V_87 ] . V_207 )
break;
}
if ( V_87 == F_41 ( V_211 ) )
return - V_64 ;
V_201 -> V_212 = V_211 [ V_87 ] . V_210 ;
V_203 = 0 ;
V_205 = F_41 ( V_213 ) ;
for ( V_87 = 0 ; V_87 < F_41 ( V_213 ) ; V_87 ++ ) {
V_202 = 256 * V_74 * 2 * V_213 [ V_87 ] . V_207 ;
if ( V_202 > V_214 && V_202 < V_215 &&
V_203 < V_202 ) {
V_203 = V_202 ;
V_205 = V_87 ;
}
}
if ( F_41 ( V_213 ) == V_205 )
return - V_64 ;
V_201 -> V_216 = V_213 [ V_205 ] . V_210 ;
V_202 = F_49 ( V_203 << 16 , V_204 * V_201 -> V_212 ) ;
V_201 -> V_217 = ( V_202 >> 16 ) & 0x3FF ;
V_201 -> V_218 = V_202 & 0xFFFF ;
return 0 ;
}
static void F_50 ( struct V_60 * V_60 ,
struct V_200 * V_201 )
{
F_13 ( V_60 , V_76 ,
V_219 | V_220 ,
V_221 | V_201 -> V_216 ) ;
F_13 ( V_60 , V_222 ,
V_223 , V_201 -> V_212 ) ;
F_25 ( V_60 , V_224 , V_201 -> V_218 ) ;
F_13 ( V_60 , V_225 ,
V_226 , V_201 -> V_217 ) ;
F_13 ( V_60 , V_227 ,
V_228 ,
V_201 -> V_209 << V_229 ) ;
F_13 ( V_60 , V_230 ,
V_231 , V_232 ) ;
F_13 ( V_60 ,
V_233 , V_234 , 0 ) ;
if ( V_201 -> V_218 ) {
F_13 ( V_60 , V_230 ,
V_235 | V_236 |
V_237 ,
V_235 | V_236 |
V_238 ) ;
F_13 ( V_60 , V_233 ,
V_239 , V_239 ) ;
} else {
F_13 ( V_60 , V_230 ,
V_235 | V_236 |
V_237 , V_240 ) ;
F_13 ( V_60 ,
V_233 , V_239 , 0 ) ;
}
}
static int F_51 ( struct V_56 * V_57 , int V_241 , int V_242 ,
unsigned int V_243 , unsigned int V_244 )
{
struct V_1 * V_1 = F_12 ( V_57 ) ;
struct V_200 V_201 ;
int V_3 , V_74 ;
V_74 = V_244 / 256 ;
V_3 = F_48 ( V_243 , V_74 , & V_201 ) ;
if ( V_3 < 0 ) {
F_37 ( V_1 -> V_5 , L_11 , V_243 ) ;
return V_3 ;
}
F_22 ( V_1 -> V_5 , L_12 ,
V_201 . V_216 , V_201 . V_212 , V_201 . V_218 ,
V_201 . V_217 , V_201 . V_209 ) ;
F_50 ( V_1 -> V_60 , & V_201 ) ;
F_52 ( 2 ) ;
F_13 ( V_1 -> V_60 , V_76 ,
V_219 , V_245 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 ,
int V_246 , unsigned int V_247 )
{
struct V_60 * V_60 = V_1 -> V_60 ;
switch ( V_246 ) {
case V_72 :
F_13 ( V_60 , V_76 ,
V_219 , V_221 ) ;
F_13 ( V_60 , V_233 ,
V_234 , 0 ) ;
break;
case V_248 :
F_1 ( V_1 , V_142 ) ;
F_13 ( V_60 , V_76 ,
V_219 , V_221 ) ;
F_13 ( V_60 , V_233 ,
V_234 , 0 ) ;
F_5 ( V_1 ) ;
break;
case V_71 :
F_13 ( V_60 , V_233 ,
V_234 , V_234 ) ;
F_13 ( V_60 , V_76 ,
V_219 , V_245 ) ;
break;
case V_249 :
F_1 ( V_1 , V_142 ) ;
F_13 ( V_60 , V_225 ,
V_250 , V_251 ) ;
F_5 ( V_1 ) ;
break;
case V_252 :
F_1 ( V_1 , V_142 ) ;
F_13 ( V_60 , V_225 ,
V_250 , V_253 ) ;
F_5 ( V_1 ) ;
break;
case V_254 :
F_1 ( V_1 , V_142 ) ;
F_13 ( V_60 , V_225 ,
V_250 , V_255 ) ;
F_5 ( V_1 ) ;
break;
default:
F_37 ( V_1 -> V_5 , L_13 , V_246 ) ;
return - V_64 ;
}
F_22 ( V_1 -> V_5 , L_14 , V_247 ,
V_246 ) ;
return 0 ;
}
static int F_53 ( struct V_56 * V_57 ,
int V_246 , int V_242 , unsigned int V_247 , int V_256 )
{
struct V_1 * V_1 = F_12 ( V_57 ) ;
return F_20 ( V_1 , V_246 , V_247 ) ;
}
static void F_54 ( struct V_1 * V_1 )
{
F_20 ( V_1 , V_72 , 0 ) ;
if ( V_1 -> V_82 ) {
F_23 ( V_1 -> V_60 ) ;
F_13 ( V_1 -> V_60 , V_8 ,
V_97 , V_97 ) ;
F_13 ( V_1 -> V_60 ,
V_11 ,
V_96 | V_95 ,
V_96 | V_95 ) ;
F_13 ( V_1 -> V_60 ,
V_90 ,
V_93 | V_94 , 0 ) ;
}
}
static int F_55 ( struct V_56 * V_57 ,
enum V_257 V_258 )
{
struct V_1 * V_1 = F_12 ( V_57 ) ;
switch ( V_258 ) {
case V_259 :
break;
case V_260 :
break;
case V_261 :
if ( F_56 ( V_57 ) == V_262 ) {
F_54 ( V_1 ) ;
}
break;
case V_262 :
F_13 ( V_1 -> V_60 ,
V_90 , 0x3ff , 0x3ff ) ;
F_13 ( V_1 -> V_60 ,
V_11 ,
V_96 | V_95 , 0 ) ;
break;
}
return 0 ;
}
static int F_57 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = F_12 ( V_57 ) ;
struct V_89 * V_58 = F_58 ( V_57 ) ;
V_1 -> V_58 = V_58 ;
return 0 ;
}
static int T_3 F_59 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = F_12 ( V_57 ) ;
if ( V_1 -> V_82 ) {
F_60 ( V_1 -> V_82 ) ;
F_61 ( V_57 , V_262 ) ;
}
F_62 ( V_1 -> V_60 , true ) ;
F_63 ( V_1 -> V_60 ) ;
return 0 ;
}
static int T_3 F_64 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = F_12 ( V_57 ) ;
F_62 ( V_1 -> V_60 , false ) ;
F_65 ( V_1 -> V_60 ) ;
if ( V_1 -> V_82 ) {
F_1 ( V_1 , 0 ) ;
F_66 ( V_1 -> V_82 ) ;
}
return 0 ;
}
int F_67 ( struct V_56 * V_57 ,
struct V_79 * V_80 )
{
struct V_1 * V_1 = F_12 ( V_57 ) ;
int V_3 ;
V_1 -> V_80 = V_80 ;
F_68 ( & V_1 -> V_100 , F_29 ) ;
V_3 = F_69 ( V_1 -> V_5 , V_1 -> V_82 , NULL ,
F_36 , V_263 | V_264 ,
L_15 , V_1 ) ;
if ( V_3 ) {
F_37 ( V_1 -> V_5 , L_16 ,
V_1 -> V_82 , V_3 ) ;
}
return V_3 ;
}
static void F_70 ( struct V_60 * V_60 )
{
F_25 ( V_60 , V_39 , 0x00 ) ;
F_25 ( V_60 , V_39 , 0x00 ) ;
}
static void F_71 ( struct V_1 * V_1 )
{
struct V_60 * V_60 = V_1 -> V_60 ;
F_13 ( V_60 , V_265 ,
V_266 ,
V_1 -> V_267 << V_268 ) ;
F_13 ( V_60 , V_265 ,
V_269 ,
V_1 -> V_270 << V_271 ) ;
F_13 ( V_60 , V_265 ,
V_272 ,
V_1 -> V_273 << V_274 ) ;
F_13 ( V_60 , V_275 ,
V_276 ,
( V_1 -> V_277 - 1 ) << V_278 ) ;
F_13 ( V_60 , V_275 ,
V_279 ,
V_1 -> V_280 << V_281 ) ;
F_13 ( V_60 , V_275 ,
V_282 ,
V_1 -> V_283 << V_284 ) ;
F_25 ( V_60 , V_285 ,
( V_1 -> V_286 [ 0 ] << 8 ) | V_1 -> V_286 [ 1 ] ) ;
F_25 ( V_60 , V_287 ,
( V_1 -> V_286 [ 2 ] << 8 ) | V_1 -> V_286 [ 3 ] ) ;
F_25 ( V_60 , V_288 ,
( V_1 -> V_286 [ 4 ] << 8 ) | V_1 -> V_286 [ 5 ] ) ;
F_25 ( V_60 , V_14 ,
( V_1 -> V_286 [ 6 ] << 8 ) | V_1 -> V_286 [ 7 ] ) ;
}
static void F_72 ( struct V_1 * V_1 )
{
struct V_60 * V_60 = V_1 -> V_60 ;
F_13 ( V_60 , V_33 ,
V_289 | V_290 , V_289 |
( V_1 -> V_291 << V_292 ) ) ;
F_13 ( V_60 , V_293 ,
V_294 , V_294 ) ;
F_52 ( 2 ) ;
F_13 ( V_60 , V_295 ,
V_296 , V_1 -> V_297 ) ;
F_13 ( V_60 , V_293 ,
V_298 | V_299 |
V_300 | V_301 ,
V_298 | V_299 |
V_300 | V_301 ) ;
F_13 ( V_60 , V_76 ,
V_150 | V_145 ,
( 0x1 << V_151 ) |
( 0x1 << V_147 ) ) ;
F_13 ( V_60 , V_302 ,
V_303 , V_303 ) ;
F_13 ( V_60 , V_8 ,
V_304 | V_305 |
V_306 | V_307 |
V_308 | V_309 ,
V_304 | V_305 |
V_306 | V_307 |
V_308 | V_309 ) ;
F_13 ( V_60 , V_310 ,
V_311 | V_312 |
V_313 | V_314 |
V_315 | V_316 |
V_317 | V_318 ,
V_311 | V_312 |
V_313 | V_314 |
V_315 | V_316 |
V_317 | V_318 ) ;
F_13 ( V_60 , V_26 ,
V_319 ,
0x20 << V_320 ) ;
F_13 ( V_60 , V_321 ,
V_322 , V_322 ) ;
F_13 ( V_60 , V_48 ,
V_323 | V_324 |
V_325 | V_326 ,
V_323 | V_324 |
V_325 | V_326 ) ;
F_13 ( V_60 , V_61 ,
V_62 , V_62 ) ;
F_13 ( V_60 , V_327 ,
V_328 , V_329 ) ;
F_13 ( V_60 , V_330 ,
V_331 , V_332 ) ;
F_13 ( V_60 , V_61 ,
V_333 | V_334 ,
V_333 | V_334 ) ;
F_13 ( V_60 , V_148 ,
V_149 , V_335 ) ;
F_13 ( V_60 , V_143 ,
V_336 | V_144 ,
V_336 | V_337 ) ;
F_13 ( V_60 , V_338 ,
V_339 | V_340 ,
( 0x2 << V_341 ) |
( 0x3 << V_342 ) ) ;
F_13 ( V_60 , V_343 ,
V_344 | V_345 ,
V_344 | V_345 ) ;
F_13 ( V_60 , V_346 ,
V_347 | V_348 ,
V_347 | V_348 ) ;
F_13 ( V_60 , V_10 ,
V_349 ,
V_1 -> V_350 ? 0 : V_349 ) ;
F_13 ( V_60 ,
V_10 , V_351 ,
( V_1 -> V_352 << V_353 ) ) ;
if ( V_1 -> V_277 )
F_71 ( V_1 ) ;
}
static int F_73 ( struct V_1 * V_1 )
{
F_13 ( V_1 -> V_60 , V_8 ,
V_97 , V_97 ) ;
F_13 ( V_1 -> V_60 ,
V_90 , 0x3ff , 0x3ff ) ;
F_13 ( V_1 -> V_60 , V_11 ,
V_96 | V_95 , 0 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_1 )
{
struct V_6 * V_5 = V_1 -> V_5 ;
int V_87 ;
F_22 ( V_5 , L_17 , V_1 -> V_350 ) ;
F_22 ( V_5 , L_18 , V_1 -> V_297 ) ;
F_22 ( V_5 , L_19 , V_1 -> V_291 ) ;
F_22 ( V_5 , L_20 , V_1 -> V_277 ) ;
for ( V_87 = 0 ; V_87 < V_1 -> V_277 ; V_87 ++ )
F_22 ( V_5 , L_21 , V_87 ,
V_1 -> V_286 [ V_87 ] ) ;
F_22 ( V_5 , L_22 , V_1 -> V_280 ) ;
F_22 ( V_5 , L_23 , V_1 -> V_267 ) ;
F_22 ( V_5 , L_24 , V_1 -> V_270 ) ;
F_22 ( V_5 , L_25 , V_1 -> V_273 ) ;
F_22 ( V_5 , L_26 , V_1 -> V_283 ) ;
F_22 ( V_5 , L_27 ,
V_1 -> V_352 ) ;
}
static int F_75 ( struct V_6 * V_5 ,
struct V_1 * V_1 ) {
int V_3 ;
V_3 = F_76 ( V_5 , L_28 ,
& V_1 -> V_350 ) ;
if ( V_3 )
V_1 -> V_350 = 1 ;
V_3 = F_76 ( V_5 , L_29 ,
& V_1 -> V_297 ) ;
if ( V_3 )
V_1 -> V_297 = 6 ;
V_3 = F_76 ( V_5 , L_30 ,
& V_1 -> V_291 ) ;
if ( V_3 )
V_1 -> V_291 = 2 ;
V_3 = F_76 ( V_5 , L_31 ,
& V_1 -> V_277 ) ;
if ( V_3 )
V_1 -> V_277 = 4 ;
V_3 = F_77 ( V_5 , L_32 ,
V_1 -> V_286 , V_1 -> V_277 ) ;
if ( V_3 ) {
V_1 -> V_286 [ 0 ] = 0x0a ;
V_1 -> V_286 [ 1 ] = 0x14 ;
V_1 -> V_286 [ 2 ] = 0x26 ;
V_1 -> V_286 [ 3 ] = 0x73 ;
}
V_3 = F_76 ( V_5 , L_33 ,
& V_1 -> V_280 ) ;
if ( V_3 )
V_1 -> V_280 = 0 ;
V_3 = F_76 ( V_5 , L_34 ,
& V_1 -> V_267 ) ;
if ( V_3 )
V_1 -> V_267 = 6 ;
V_3 = F_76 ( V_5 , L_35 ,
& V_1 -> V_270 ) ;
if ( V_3 )
V_1 -> V_270 = 1 ;
V_3 = F_76 ( V_5 , L_36 ,
& V_1 -> V_273 ) ;
if ( V_3 )
V_1 -> V_273 = 1 ;
V_3 = F_76 ( V_5 , L_37 ,
& V_1 -> V_283 ) ;
if ( V_3 )
V_1 -> V_283 = 0 ;
V_3 = F_76 ( V_5 , L_38 ,
& V_1 -> V_352 ) ;
if ( V_3 )
V_1 -> V_352 = 1 ;
return 0 ;
}
static int F_78 ( struct V_354 * V_355 ,
const struct V_356 * V_357 )
{
struct V_6 * V_5 = & V_355 -> V_5 ;
struct V_1 * V_1 = F_79 ( V_5 ) ;
int V_3 , V_106 ;
if ( ! V_1 ) {
V_1 = F_80 ( V_5 , sizeof( * V_1 ) , V_358 ) ;
if ( ! V_1 )
return - V_359 ;
V_3 = F_75 ( V_5 , V_1 ) ;
if ( V_3 )
return V_3 ;
}
F_81 ( V_355 , V_1 ) ;
V_1 -> V_60 = F_82 ( V_355 , & V_360 ) ;
if ( F_83 ( V_1 -> V_60 ) )
return F_84 ( V_1 -> V_60 ) ;
V_1 -> V_5 = V_5 ;
V_1 -> V_82 = V_355 -> V_82 ;
F_85 ( & V_1 -> V_4 , 1 ) ;
F_74 ( V_1 ) ;
V_3 = F_24 ( V_1 -> V_60 , V_31 , & V_106 ) ;
if ( V_3 < 0 ) {
F_37 ( V_5 , L_39 ,
V_3 ) ;
return V_3 ;
}
F_70 ( V_1 -> V_60 ) ;
F_72 ( V_1 ) ;
if ( V_355 -> V_82 )
F_73 ( V_1 ) ;
return F_86 ( V_5 ,
& V_361 , & V_362 , 1 ) ;
}
static int F_87 ( struct V_354 * V_363 )
{
F_88 ( & V_363 -> V_5 ) ;
return 0 ;
}
