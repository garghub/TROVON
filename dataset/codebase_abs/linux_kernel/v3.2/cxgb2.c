static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 , V_3 * V_5 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_4 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_9 * V_10 = V_1 -> V_11 [ V_7 -> V_12 ] . V_10 ;
struct V_13 V_14 ;
V_14 . V_7 = V_7 ;
V_10 -> V_15 -> V_16 ( V_10 , & V_14 ) ;
}
static void F_6 ( struct V_17 * V_18 )
{
if ( ! F_7 ( V_18 -> V_7 ) )
F_8 ( V_19 L_1 , V_18 -> V_7 -> V_20 ) ;
else {
const char * V_21 = L_2 ;
switch ( V_18 -> V_22 . V_23 ) {
case V_24 : V_21 = L_3 ; break;
case V_25 : V_21 = L_4 ; break;
case V_26 : V_21 = L_5 ; break;
}
F_8 ( V_19 L_6 ,
V_18 -> V_7 -> V_20 , V_21 ,
V_18 -> V_22 . V_27 == V_28 ? L_7 : L_8 ) ;
}
}
void F_9 ( struct V_1 * V_1 , int V_29 , int V_30 ,
int V_23 , int V_27 , int V_31 )
{
struct V_17 * V_18 = & V_1 -> V_11 [ V_29 ] ;
if ( V_30 != F_7 ( V_18 -> V_7 ) ) {
if ( V_30 )
F_10 ( V_18 -> V_7 ) ;
else
F_11 ( V_18 -> V_7 ) ;
F_6 ( V_18 ) ;
if ( ( V_23 > 0 ) && ( V_1 -> V_32 . V_33 > 1 ) ) {
unsigned int V_34 = 10 ;
switch ( V_23 ) {
case V_25 :
V_34 = 1000 ;
break;
case V_26 :
V_34 = 100 ;
break;
case V_35 :
V_34 = 10 ;
break;
}
F_12 ( V_1 -> V_36 , V_29 , 0 , V_34 ) ;
}
}
}
static void F_13 ( struct V_17 * V_18 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
V_10 -> V_15 -> V_37 ( V_10 ) ;
if ( V_10 -> V_15 -> V_38 )
V_10 -> V_15 -> V_38 ( V_10 , V_18 -> V_7 -> V_39 ) ;
F_5 ( V_18 -> V_7 ) ;
F_14 ( V_18 -> V_40 , V_10 , & V_18 -> V_22 ) ;
V_10 -> V_15 -> V_41 ( V_10 , V_42 | V_43 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
if ( V_1 -> V_11 [ 0 ] . V_7 -> V_44 & V_45 )
F_16 ( V_1 -> V_46 , 1 ) ;
F_17 ( V_1 -> V_46 , 1 ) ;
}
static int F_18 ( struct V_1 * V_1 )
{
int V_47 = 0 ;
if ( ! ( V_1 -> V_48 & V_49 ) ) {
V_47 = F_19 ( V_1 ) ;
if ( V_47 )
goto V_50;
F_15 ( V_1 ) ;
V_1 -> V_48 |= V_49 ;
}
F_20 ( V_1 ) ;
V_1 -> V_32 . V_51 = ! V_52 && ! F_21 ( V_1 -> V_53 ) ;
V_47 = F_22 ( V_1 -> V_53 -> V_54 , V_55 ,
V_1 -> V_32 . V_51 ? 0 : V_56 ,
V_1 -> V_20 , V_1 ) ;
if ( V_47 ) {
if ( V_1 -> V_32 . V_51 )
F_23 ( V_1 -> V_53 ) ;
goto V_50;
}
F_24 ( V_1 -> V_36 ) ;
F_25 ( V_1 ) ;
V_50:
return V_47 ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_27 ( V_1 -> V_36 ) ;
F_28 ( V_1 ) ;
F_29 ( V_1 -> V_53 -> V_54 , V_1 ) ;
if ( V_1 -> V_32 . V_51 )
F_23 ( V_1 -> V_53 ) ;
}
static int F_30 ( struct V_6 * V_7 )
{
int V_47 ;
struct V_1 * V_1 = V_7 -> V_8 ;
int V_57 = V_1 -> V_58 & V_59 ;
F_31 ( & V_1 -> V_60 ) ;
if ( ! V_1 -> V_58 && ( V_47 = F_18 ( V_1 ) ) < 0 ) {
F_32 ( & V_1 -> V_60 ) ;
return V_47 ;
}
F_33 ( V_7 -> V_12 , & V_1 -> V_58 ) ;
F_13 ( & V_1 -> V_11 [ V_7 -> V_12 ] ) ;
F_34 ( V_7 ) ;
if ( ! V_57 && V_1 -> V_32 . V_61 )
F_1 ( V_1 ,
V_1 -> V_32 . V_61 ) ;
F_35 ( V_1 , V_7 -> V_62 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_17 * V_18 = & V_1 -> V_11 [ V_7 -> V_12 ] ;
struct V_9 * V_10 = V_18 -> V_10 ;
F_37 ( V_7 ) ;
F_32 ( & V_1 -> V_60 ) ;
V_10 -> V_15 -> V_63 ( V_10 , V_43 | V_42 ) ;
F_11 ( V_7 ) ;
F_38 ( V_7 -> V_12 , & V_1 -> V_58 ) ;
if ( V_1 -> V_32 . V_61 &&
! ( V_1 -> V_58 & V_59 ) ) {
F_39 () ;
F_40 ( & V_1 -> V_64 ) ;
F_41 ( & V_1 -> V_64 ) ;
F_3 ( V_1 ) ;
}
if ( ! V_1 -> V_58 )
F_26 ( V_1 ) ;
return 0 ;
}
static struct V_65 * F_42 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_17 * V_18 = & V_1 -> V_11 [ V_7 -> V_12 ] ;
struct V_65 * V_66 = & V_18 -> V_67 ;
const struct V_68 * V_69 ;
V_69 = V_18 -> V_10 -> V_15 -> V_70 ( V_18 -> V_10 ,
V_71 ) ;
V_66 -> V_72 = V_69 -> V_73 +
V_69 -> V_74 + V_69 -> V_75 ;
V_66 -> V_76 = V_69 -> V_77 +
V_69 -> V_78 + V_69 -> V_79 ;
V_66 -> V_80 = V_69 -> V_81 ;
V_66 -> V_82 = V_69 -> V_83 ;
V_66 -> V_84 = V_69 -> V_85 + V_69 -> V_86 +
V_69 -> V_87 + V_69 -> V_88 ;
V_66 -> V_89 = V_69 -> V_90 + V_69 -> V_91 +
V_69 -> V_92 + V_69 -> V_93 +
V_69 -> V_94 + V_69 -> V_95 +
V_69 -> V_96 + V_69 -> V_97 ;
V_66 -> V_98 = V_69 -> V_78 ;
V_66 -> V_99 = V_69 -> V_100 ;
V_66 -> V_101 = V_69 -> V_95 +
V_69 -> V_91 ;
V_66 -> V_102 = 0 ;
V_66 -> V_103 = V_69 -> V_92 ;
V_66 -> V_104 = V_69 -> V_93 ;
V_66 -> V_105 = 0 ;
V_66 -> V_106 = 0 ;
V_66 -> V_107 = V_69 -> V_88 ;
V_66 -> V_108 = 0 ;
V_66 -> V_109 = V_69 -> V_87 ;
V_66 -> V_110 = 0 ;
V_66 -> V_111 = V_69 -> V_85 ;
return V_66 ;
}
static T_1 F_43 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
return V_1 -> V_112 ;
}
static void F_44 ( struct V_6 * V_7 , T_1 V_113 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
V_1 -> V_112 = V_113 ;
}
static int F_45 ( struct V_6 * V_7 )
{
return V_114 ;
}
static void F_46 ( struct V_6 * V_7 , struct V_115 * V_116 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
strcpy ( V_116 -> V_117 , V_118 ) ;
strcpy ( V_116 -> V_119 , V_120 ) ;
strcpy ( V_116 -> V_121 , L_9 ) ;
strcpy ( V_116 -> V_122 , F_47 ( V_1 -> V_53 ) ) ;
}
static int F_48 ( struct V_6 * V_7 , int V_123 )
{
switch ( V_123 ) {
case V_124 :
return F_49 ( V_125 ) ;
default:
return - V_126 ;
}
}
static void F_50 ( struct V_6 * V_7 , T_1 V_127 , T_2 * V_128 )
{
if ( V_127 == V_124 )
memcpy ( V_128 , V_125 , sizeof( V_125 ) ) ;
}
static void F_51 ( struct V_6 * V_7 , struct V_129 * V_130 ,
T_3 * V_128 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_9 * V_10 = V_1 -> V_11 [ V_7 -> V_12 ] . V_10 ;
const struct V_68 * V_21 ;
const struct V_131 * V_132 ;
struct V_133 V_134 ;
V_21 = V_10 -> V_15 -> V_70 ( V_10 , V_71 ) ;
V_132 = F_52 ( V_1 -> V_36 ) ;
F_53 ( V_1 -> V_36 , V_7 -> V_12 , & V_134 ) ;
* V_128 ++ = V_21 -> V_81 ;
* V_128 ++ = V_21 -> V_135 ;
* V_128 ++ = V_21 -> V_73 ;
* V_128 ++ = V_21 -> V_74 ;
* V_128 ++ = V_21 -> V_75 ;
* V_128 ++ = V_21 -> V_136 ;
* V_128 ++ = V_21 -> V_137 ;
* V_128 ++ = V_21 -> V_85 ;
* V_128 ++ = V_21 -> V_100 ;
* V_128 ++ = V_21 -> V_88 ;
* V_128 ++ = V_21 -> V_87 ;
* V_128 ++ = V_21 -> V_86 ;
* V_128 ++ = V_21 -> V_138 ;
* V_128 ++ = V_21 -> V_139 ;
* V_128 ++ = V_21 -> V_140 ;
* V_128 ++ = V_21 -> V_141 ;
* V_128 ++ = V_21 -> V_142 ;
* V_128 ++ = V_21 -> V_83 ;
* V_128 ++ = V_21 -> V_143 ;
* V_128 ++ = V_21 -> V_77 ;
* V_128 ++ = V_21 -> V_78 ;
* V_128 ++ = V_21 -> V_79 ;
* V_128 ++ = V_21 -> V_144 ;
* V_128 ++ = V_21 -> V_92 ;
* V_128 ++ = V_21 -> V_93 ;
* V_128 ++ = V_21 -> V_96 ;
* V_128 ++ = V_21 -> V_90 ;
* V_128 ++ = V_21 -> V_94 ;
* V_128 ++ = V_21 -> V_97 ;
* V_128 ++ = V_21 -> V_91 ;
* V_128 ++ = V_21 -> V_145 ;
* V_128 ++ = V_21 -> V_146 ;
* V_128 ++ = V_21 -> V_147 ;
* V_128 ++ = V_21 -> V_95 ;
* V_128 ++ = V_21 -> V_148 ;
* V_128 ++ = V_21 -> V_149 ;
* V_128 ++ = V_134 . V_150 ;
* V_128 ++ = V_134 . V_151 ;
* V_128 ++ = V_134 . V_152 ;
* V_128 ++ = V_134 . V_153 ;
* V_128 ++ = V_134 . V_154 ;
* V_128 ++ = V_134 . V_155 ;
* V_128 ++ = V_132 -> V_156 ;
* V_128 ++ = V_132 -> V_157 ;
* V_128 ++ = V_132 -> V_158 ;
* V_128 ++ = V_132 -> V_159 ;
* V_128 ++ = V_132 -> V_160 ;
* V_128 ++ = V_132 -> V_161 ;
* V_128 ++ = V_132 -> V_162 ;
* V_128 ++ = V_132 -> V_163 ;
* V_128 ++ = V_132 -> V_164 [ 0 ] ;
* V_128 ++ = V_132 -> V_164 [ 1 ] ;
if ( V_1 -> V_165 ) {
const struct V_166 * V_167 ;
V_167 = F_54 ( V_1 -> V_165 ) ;
* V_128 ++ = V_167 -> V_168 ;
* V_128 ++ = V_167 -> V_169 ;
* V_128 ++ = V_167 -> V_156 ;
* V_128 ++ = V_167 -> V_170 ;
* V_128 ++ = V_167 -> V_171 ;
* V_128 ++ = V_167 -> V_172 ;
}
}
static inline void F_55 ( struct V_1 * V_2 , void * V_173 ,
unsigned int V_174 , unsigned int V_175 )
{
T_1 * V_18 = V_173 + V_174 ;
for ( ; V_174 <= V_175 ; V_174 += sizeof( T_1 ) )
* V_18 ++ = F_56 ( V_2 -> V_176 + V_174 ) ;
}
static void F_57 ( struct V_6 * V_7 , struct V_177 * V_176 ,
void * V_173 )
{
struct V_1 * V_2 = V_7 -> V_8 ;
V_176 -> V_119 = 2 ;
memset ( V_173 , 0 , V_114 ) ;
F_55 ( V_2 , V_173 , 0 , V_178 ) ;
F_55 ( V_2 , V_173 , V_179 , V_180 ) ;
F_55 ( V_2 , V_173 , V_181 , V_182 ) ;
F_55 ( V_2 , V_173 , V_183 , V_184 ) ;
F_55 ( V_2 , V_173 , V_185 , V_186 ) ;
F_55 ( V_2 , V_173 , V_187 , V_188 ) ;
F_55 ( V_2 , V_173 , V_189 , V_190 ) ;
F_55 ( V_2 , V_173 , V_191 , V_192 ) ;
F_55 ( V_2 , V_173 , V_193 , V_194 ) ;
F_55 ( V_2 , V_173 , V_195 , V_196 ) ;
}
static int F_58 ( struct V_6 * V_7 , struct V_197 * V_198 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_17 * V_18 = & V_1 -> V_11 [ V_7 -> V_12 ] ;
V_198 -> V_199 = V_18 -> V_22 . V_199 ;
V_198 -> V_200 = V_18 -> V_22 . V_200 ;
if ( F_7 ( V_7 ) ) {
F_59 ( V_198 , V_18 -> V_22 . V_23 ) ;
V_198 -> V_27 = V_18 -> V_22 . V_27 ;
} else {
F_59 ( V_198 , - 1 ) ;
V_198 -> V_27 = - 1 ;
}
V_198 -> V_11 = ( V_198 -> V_199 & V_201 ) ? V_202 : V_203 ;
V_198 -> V_204 = V_18 -> V_40 -> V_205 . V_206 ;
V_198 -> V_207 = V_208 ;
V_198 -> V_209 = V_18 -> V_22 . V_209 ;
V_198 -> V_210 = 0 ;
V_198 -> V_211 = 0 ;
return 0 ;
}
static int F_60 ( int V_23 , int V_27 )
{
int V_212 = 0 ;
switch ( V_23 ) {
case V_35 :
if ( V_27 == V_28 )
V_212 = V_213 ;
else
V_212 = V_214 ;
break;
case V_26 :
if ( V_27 == V_28 )
V_212 = V_215 ;
else
V_212 = V_216 ;
break;
case V_25 :
if ( V_27 == V_28 )
V_212 = V_217 ;
else
V_212 = V_218 ;
break;
case V_24 :
if ( V_27 == V_28 )
V_212 = V_219 ;
}
return V_212 ;
}
static int F_61 ( struct V_6 * V_7 , struct V_197 * V_198 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_17 * V_18 = & V_1 -> V_11 [ V_7 -> V_12 ] ;
struct V_22 * V_220 = & V_18 -> V_22 ;
if ( ! ( V_220 -> V_199 & V_221 ) )
return - V_126 ;
if ( V_198 -> V_209 == V_222 ) {
T_1 V_23 = F_62 ( V_198 ) ;
int V_212 = F_60 ( V_23 , V_198 -> V_27 ) ;
if ( ! ( V_220 -> V_199 & V_212 ) || ( V_23 == V_25 ) )
return - V_223 ;
V_220 -> V_224 = V_23 ;
V_220 -> V_225 = V_198 -> V_27 ;
V_220 -> V_200 = 0 ;
} else {
V_198 -> V_200 &= V_226 ;
if ( V_198 -> V_200 & ( V_198 -> V_200 - 1 ) )
V_198 -> V_200 = V_220 -> V_199 ;
V_198 -> V_200 &= V_220 -> V_199 ;
if ( ! V_198 -> V_200 )
return - V_223 ;
V_220 -> V_224 = V_227 ;
V_220 -> V_225 = V_228 ;
V_220 -> V_200 = V_198 -> V_200 | V_229 ;
}
V_220 -> V_209 = V_198 -> V_209 ;
if ( F_63 ( V_7 ) )
F_14 ( V_18 -> V_40 , V_18 -> V_10 , V_220 ) ;
return 0 ;
}
static void F_64 ( struct V_6 * V_7 ,
struct V_230 * V_231 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_17 * V_18 = & V_1 -> V_11 [ V_7 -> V_12 ] ;
V_231 -> V_209 = ( V_18 -> V_22 . V_232 & V_233 ) != 0 ;
V_231 -> V_234 = ( V_18 -> V_22 . V_235 & V_236 ) != 0 ;
V_231 -> V_237 = ( V_18 -> V_22 . V_235 & V_238 ) != 0 ;
}
static int F_65 ( struct V_6 * V_7 ,
struct V_230 * V_231 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_17 * V_18 = & V_1 -> V_11 [ V_7 -> V_12 ] ;
struct V_22 * V_220 = & V_18 -> V_22 ;
if ( V_231 -> V_209 == V_222 )
V_220 -> V_232 = 0 ;
else if ( V_220 -> V_199 & V_221 )
V_220 -> V_232 = V_233 ;
else
return - V_223 ;
if ( V_231 -> V_234 )
V_220 -> V_232 |= V_236 ;
if ( V_231 -> V_237 )
V_220 -> V_232 |= V_238 ;
if ( V_220 -> V_209 == V_239 ) {
if ( F_63 ( V_7 ) )
F_14 ( V_18 -> V_40 , V_18 -> V_10 , V_220 ) ;
} else {
V_220 -> V_235 = V_220 -> V_232 & ( V_236 | V_238 ) ;
if ( F_63 ( V_7 ) )
V_18 -> V_10 -> V_15 -> V_240 ( V_18 -> V_10 , - 1 , - 1 ,
V_220 -> V_235 ) ;
}
return 0 ;
}
static void F_66 ( struct V_6 * V_7 , struct V_241 * V_167 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
int V_242 = F_67 ( V_1 ) ? 1 : 0 ;
V_167 -> V_243 = V_244 ;
V_167 -> V_245 = V_246 ;
V_167 -> V_247 = V_248 ;
V_167 -> V_249 = V_1 -> V_32 . V_36 . V_250 [ ! V_242 ] ;
V_167 -> V_251 = V_1 -> V_32 . V_36 . V_250 [ V_242 ] ;
V_167 -> V_252 = V_1 -> V_32 . V_36 . V_253 [ 0 ] ;
}
static int F_68 ( struct V_6 * V_7 , struct V_241 * V_167 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
int V_242 = F_67 ( V_1 ) ? 1 : 0 ;
if ( V_167 -> V_249 > V_244 || V_167 -> V_254 ||
V_167 -> V_251 > V_246 ||
V_167 -> V_252 > V_248 ||
V_167 -> V_249 < V_255 ||
V_167 -> V_251 < V_255 ||
V_167 -> V_252 < ( V_1 -> V_32 . V_33 + 1 ) * ( V_256 + 1 ) )
return - V_223 ;
if ( V_1 -> V_48 & V_49 )
return - V_257 ;
V_1 -> V_32 . V_36 . V_250 [ ! V_242 ] = V_167 -> V_249 ;
V_1 -> V_32 . V_36 . V_250 [ V_242 ] = V_167 -> V_251 ;
V_1 -> V_32 . V_36 . V_253 [ 0 ] = V_167 -> V_252 ;
V_1 -> V_32 . V_36 . V_253 [ 1 ] = V_167 -> V_252 > V_258 ?
V_258 : V_167 -> V_252 ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 , struct V_259 * V_260 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
V_1 -> V_32 . V_36 . V_261 = V_260 -> V_261 ;
V_1 -> V_32 . V_36 . V_262 = V_260 -> V_263 ;
V_1 -> V_32 . V_36 . V_264 = V_260 -> V_265 ;
F_70 ( V_1 -> V_36 , & V_1 -> V_32 . V_36 ) ;
return 0 ;
}
static int F_71 ( struct V_6 * V_7 , struct V_259 * V_260 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
V_260 -> V_261 = V_1 -> V_32 . V_36 . V_261 ;
V_260 -> V_265 = V_1 -> V_32 . V_36 . V_264 ;
V_260 -> V_263 = V_1 -> V_32 . V_36 . V_262 ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
return F_73 ( V_1 ) ? V_266 : 0 ;
}
static int F_74 ( struct V_6 * V_7 , struct V_267 * V_167 ,
T_2 * V_128 )
{
int V_268 ;
T_2 V_173 [ V_266 ] V_269 ( ( F_75 ( 4 ) ) ) ;
struct V_1 * V_1 = V_7 -> V_8 ;
V_167 -> V_270 = F_76 ( V_1 ) ;
for ( V_268 = V_167 -> V_271 & ~ 3 ; V_268 < V_167 -> V_271 + V_167 -> V_272 ; V_268 += sizeof( T_1 ) )
F_77 ( V_1 , V_268 , ( V_273 * ) & V_173 [ V_268 ] ) ;
memcpy ( V_128 , V_173 + V_167 -> V_271 , V_167 -> V_272 ) ;
return 0 ;
}
static int F_78 ( struct V_6 * V_7 , struct V_274 * V_275 , int V_198 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_276 * V_205 = & V_1 -> V_11 [ V_7 -> V_12 ] . V_40 -> V_205 ;
return F_79 ( V_205 , F_80 ( V_275 ) , V_198 ) ;
}
static int F_81 ( struct V_6 * V_7 , int V_277 )
{
int V_278 ;
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_9 * V_10 = V_1 -> V_11 [ V_7 -> V_12 ] . V_10 ;
if ( ! V_10 -> V_15 -> V_279 )
return - V_126 ;
if ( V_277 < 68 )
return - V_223 ;
if ( ( V_278 = V_10 -> V_15 -> V_279 ( V_10 , V_277 ) ) )
return V_278 ;
V_7 -> V_280 = V_277 ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 , void * V_18 )
{
struct V_1 * V_1 = V_7 -> V_8 ;
struct V_9 * V_10 = V_1 -> V_11 [ V_7 -> V_12 ] . V_10 ;
struct V_281 * V_282 = V_18 ;
if ( ! V_10 -> V_15 -> V_38 )
return - V_126 ;
memcpy ( V_7 -> V_39 , V_282 -> V_283 , V_7 -> V_284 ) ;
V_10 -> V_15 -> V_38 ( V_10 , V_7 -> V_39 ) ;
return 0 ;
}
static T_1 F_83 ( struct V_6 * V_7 , T_1 V_62 )
{
if ( V_62 & V_285 )
V_62 |= V_286 ;
else
V_62 &= ~ V_286 ;
return V_62 ;
}
static int F_84 ( struct V_6 * V_7 , T_1 V_62 )
{
T_1 V_287 = V_7 -> V_62 ^ V_62 ;
struct V_1 * V_1 = V_7 -> V_8 ;
if ( V_287 & V_285 )
F_35 ( V_1 , V_62 ) ;
return 0 ;
}
static void F_85 ( struct V_6 * V_7 )
{
unsigned long V_48 ;
struct V_1 * V_1 = V_7 -> V_8 ;
F_86 ( V_48 ) ;
V_55 ( V_1 -> V_53 -> V_54 , V_1 ) ;
F_87 ( V_48 ) ;
}
static void F_88 ( struct V_288 * V_289 )
{
int V_268 ;
struct V_1 * V_1 =
F_89 ( V_289 , struct V_1 , V_4 . V_289 ) ;
F_90 (adapter, i) {
struct V_17 * V_18 = & V_1 -> V_11 [ V_268 ] ;
if ( F_63 ( V_18 -> V_7 ) )
V_18 -> V_10 -> V_15 -> V_70 ( V_18 -> V_10 ,
V_290 ) ;
}
F_40 ( & V_1 -> V_64 ) ;
if ( V_1 -> V_58 & V_59 )
F_1 ( V_1 ,
V_1 -> V_32 . V_61 ) ;
F_41 ( & V_1 -> V_64 ) ;
}
static void F_91 ( struct V_288 * V_289 )
{
struct V_1 * V_1 =
F_89 ( V_289 , struct V_1 , V_291 ) ;
F_92 ( V_1 ) ;
F_93 ( & V_1 -> V_292 ) ;
V_1 -> V_293 |= V_294 ;
F_94 ( V_294 , V_1 -> V_176 + V_194 ) ;
F_94 ( V_1 -> V_293 | V_295 ,
V_1 -> V_176 + V_193 ) ;
F_95 ( & V_1 -> V_292 ) ;
}
void F_96 ( struct V_1 * V_1 )
{
V_1 -> V_293 &= ~ V_294 ;
F_94 ( V_1 -> V_293 | V_295 ,
V_1 -> V_176 + V_193 ) ;
F_97 ( & V_1 -> V_291 ) ;
}
void F_98 ( struct V_1 * V_1 )
{
if ( V_1 -> V_48 & V_49 ) {
F_27 ( V_1 -> V_36 ) ;
F_28 ( V_1 ) ;
}
F_99 ( L_10 ,
V_1 -> V_20 ) ;
}
static int T_4 F_100 ( struct V_296 * V_53 ,
const struct V_297 * V_298 )
{
static int V_299 ;
int V_268 , V_47 , V_300 = 0 ;
unsigned long V_301 , V_302 ;
const struct V_303 * V_304 ;
struct V_1 * V_1 = NULL ;
struct V_17 * V_305 ;
if ( ! V_299 ) {
F_8 ( V_19 L_11 , V_306 ,
V_120 ) ;
++ V_299 ;
}
V_47 = F_101 ( V_53 ) ;
if ( V_47 )
return V_47 ;
if ( ! ( F_102 ( V_53 , 0 ) & V_307 ) ) {
F_103 ( L_12 ,
F_47 ( V_53 ) ) ;
V_47 = - V_308 ;
goto V_309;
}
if ( ! F_104 ( V_53 , F_105 ( 64 ) ) ) {
V_300 = 1 ;
if ( F_106 ( V_53 , F_105 ( 64 ) ) ) {
F_103 ( L_13
L_14 , F_47 ( V_53 ) ) ;
V_47 = - V_308 ;
goto V_309;
}
} else if ( ( V_47 = F_104 ( V_53 , F_105 ( 32 ) ) ) != 0 ) {
F_103 ( L_15 , F_47 ( V_53 ) ) ;
goto V_309;
}
V_47 = F_107 ( V_53 , V_118 ) ;
if ( V_47 ) {
F_103 ( L_16 , F_47 ( V_53 ) ) ;
goto V_309;
}
F_108 ( V_53 ) ;
V_301 = F_109 ( V_53 , 0 ) ;
V_302 = F_110 ( V_53 , 0 ) ;
V_304 = F_111 ( V_298 -> V_310 ) ;
for ( V_268 = 0 ; V_268 < V_304 -> V_311 ; ++ V_268 ) {
struct V_6 * V_312 ;
V_312 = F_112 ( V_1 ? 0 : sizeof( * V_1 ) ) ;
if ( ! V_312 ) {
V_47 = - V_313 ;
goto V_314;
}
F_113 ( V_312 , & V_53 -> V_7 ) ;
if ( ! V_1 ) {
V_1 = F_114 ( V_312 ) ;
V_1 -> V_53 = V_53 ;
V_1 -> V_11 [ 0 ] . V_7 = V_312 ;
V_1 -> V_176 = F_115 ( V_301 , V_302 ) ;
if ( ! V_1 -> V_176 ) {
F_103 ( L_17 ,
F_47 ( V_53 ) ) ;
V_47 = - V_313 ;
goto V_314;
}
if ( F_116 ( V_1 , V_304 , & V_1 -> V_32 ) ) {
V_47 = - V_308 ;
goto V_314;
}
V_1 -> V_20 = F_47 ( V_53 ) ;
V_1 -> V_112 = V_315 ;
V_1 -> V_302 = V_302 ;
F_117 ( & V_1 -> V_316 ) ;
F_117 ( & V_1 -> V_64 ) ;
F_117 ( & V_1 -> V_292 ) ;
F_117 ( & V_1 -> V_317 ) ;
F_118 ( & V_1 -> V_291 ,
F_91 ) ;
F_119 ( & V_1 -> V_4 ,
F_88 ) ;
F_120 ( V_53 , V_312 ) ;
}
V_305 = & V_1 -> V_11 [ V_268 ] ;
V_305 -> V_7 = V_312 ;
F_11 ( V_312 ) ;
V_312 -> V_54 = V_53 -> V_54 ;
V_312 -> V_12 = V_268 ;
V_312 -> V_318 = V_301 ;
V_312 -> V_319 = V_301 + V_302 - 1 ;
V_312 -> V_8 = V_1 ;
V_312 -> V_44 |= V_320 | V_321 |
V_322 ;
V_312 -> V_62 |= V_320 | V_321 |
V_322 | V_323 ;
if ( V_300 )
V_312 -> V_62 |= V_324 ;
if ( F_121 ( V_1 ) ) {
V_312 -> V_62 |=
V_286 | V_285 ;
V_312 -> V_44 |= V_285 ;
if ( ! ( F_122 ( V_1 ) ) || V_304 -> V_311 != 4 ) {
V_312 -> V_44 |= V_45 ;
V_312 -> V_62 |= V_45 ;
}
}
V_312 -> V_325 = & V_326 ;
V_312 -> V_327 += ( V_312 -> V_44 & V_45 ) ?
sizeof( struct V_328 ) : sizeof( struct V_329 ) ;
F_123 ( V_312 , & V_1 -> V_60 , V_330 , 64 ) ;
F_124 ( V_312 , & V_331 ) ;
}
if ( F_125 ( V_1 , V_304 ) < 0 ) {
V_47 = - V_308 ;
goto V_314;
}
for ( V_268 = 0 ; V_268 < V_304 -> V_311 ; ++ V_268 ) {
V_47 = F_126 ( V_1 -> V_11 [ V_268 ] . V_7 ) ;
if ( V_47 )
F_127 ( L_18 ,
F_47 ( V_53 ) , V_1 -> V_11 [ V_268 ] . V_7 -> V_20 ) ;
else {
if ( ! V_1 -> V_332 )
V_1 -> V_20 = V_1 -> V_11 [ V_268 ] . V_7 -> V_20 ;
F_33 ( V_268 , & V_1 -> V_332 ) ;
}
}
if ( ! V_1 -> V_332 ) {
F_103 ( L_19 ,
F_47 ( V_53 ) ) ;
goto V_333;
}
F_8 ( V_19 L_20 , V_1 -> V_20 ,
V_304 -> V_334 , V_1 -> V_32 . V_335 ,
V_1 -> V_32 . V_336 . V_337 ? L_21 : L_22 ,
V_1 -> V_32 . V_336 . V_23 , V_1 -> V_32 . V_336 . V_338 ) ;
if ( V_339 )
V_1 -> V_339 = V_340 ;
else
V_1 -> V_339 = V_341 ;
if ( F_67 ( V_1 ) )
F_128 ( V_1 , V_339 ) ;
return 0 ;
V_333:
F_129 ( V_1 ) ;
V_314:
if ( V_1 ) {
if ( V_1 -> V_176 )
F_130 ( V_1 -> V_176 ) ;
for ( V_268 = V_304 -> V_311 - 1 ; V_268 >= 0 ; -- V_268 )
if ( V_1 -> V_11 [ V_268 ] . V_7 )
F_131 ( V_1 -> V_11 [ V_268 ] . V_7 ) ;
}
F_132 ( V_53 ) ;
V_309:
F_133 ( V_53 ) ;
F_120 ( V_53 , NULL ) ;
return V_47 ;
}
static void F_134 ( struct V_1 * V_1 , int V_342 , int V_343 )
{
int V_128 ;
int V_268 ;
T_1 V_113 ;
enum {
V_344 = 1 << 3 ,
V_345 = 1 << 4
};
for ( V_268 = ( V_343 - 1 ) ; V_268 > - 1 ; V_268 -- ) {
F_135 ( 50 ) ;
V_128 = ( ( V_342 >> V_268 ) & 0x1 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
if ( V_128 )
V_113 |= V_345 ;
else
V_113 &= ~ V_345 ;
F_135 ( 50 ) ;
V_113 &= ~ V_344 ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_135 ( 50 ) ;
V_113 |= V_344 ;
F_137 ( V_1 , V_346 , V_113 ) ;
}
}
static int F_128 ( struct V_1 * V_1 , int V_347 )
{
T_1 V_113 ;
int V_348 ;
int V_349 ;
enum {
V_350 = 9 ,
V_351 = 0 ,
V_352 = 2 ,
V_353 = 0 ,
V_354 = 2 ,
V_355 = 9 ,
V_356 = 0 ,
V_357 = 2 ,
V_358 = 0 ,
V_359 = 2 ,
V_360 = 1 << 17 ,
V_361 = 1 << 5 ,
V_362 = 1 << 6 ,
V_344 = 1 << 3
};
if ( ! F_67 ( V_1 ) )
return - V_308 ;
if ( V_347 & 2 )
return 0 ;
if ( ( V_1 -> V_339 & 1 ) == ( V_347 & 1 ) )
return - V_363 ;
if ( ( V_347 & 1 ) == V_341 ) {
V_348 = 0x14 ;
V_349 = 0x18 ;
V_1 -> V_339 = V_341 ;
} else {
V_348 = 0xe ;
V_349 = 0x10 ;
V_1 -> V_339 = V_340 ;
}
F_40 ( & V_1 -> V_316 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
V_113 |= V_360 ;
F_135 ( 50 ) ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_135 ( 50 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
V_113 &= ~ V_362 ;
V_113 &= ~ V_344 ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_135 ( 50 ) ;
F_134 ( V_1 , V_351 , V_352 ) ;
F_134 ( V_1 , V_353 , V_354 ) ;
F_134 ( V_1 , V_348 , V_350 ) ;
F_135 ( 50 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
V_113 |= V_362 ;
F_135 ( 50 ) ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_135 ( 50 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
V_113 &= ~ V_362 ;
F_135 ( 50 ) ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_135 ( 50 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
V_113 |= V_360 ;
F_135 ( 50 ) ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_135 ( 50 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
V_113 &= ~ V_361 ;
V_113 &= ~ V_344 ;
F_135 ( 50 ) ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_135 ( 50 ) ;
F_134 ( V_1 , V_356 , V_357 ) ;
F_134 ( V_1 , V_358 , V_359 ) ;
F_134 ( V_1 , V_349 , V_355 ) ;
F_135 ( 50 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
V_113 |= V_361 ;
F_135 ( 50 ) ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_135 ( 50 ) ;
F_136 ( V_1 , V_346 , & V_113 ) ;
V_113 &= ~ V_361 ;
F_135 ( 50 ) ;
F_137 ( V_1 , V_346 , V_113 ) ;
F_41 ( & V_1 -> V_316 ) ;
return 0 ;
}
static inline void F_138 ( struct V_296 * V_53 )
{
F_139 ( V_53 , V_364 , 3 ) ;
F_139 ( V_53 , V_364 , 0 ) ;
}
static void T_5 F_140 ( struct V_296 * V_53 )
{
struct V_6 * V_7 = F_141 ( V_53 ) ;
struct V_1 * V_1 = V_7 -> V_8 ;
int V_268 ;
F_90 (adapter, i) {
if ( F_142 ( V_268 , & V_1 -> V_332 ) )
F_143 ( V_1 -> V_11 [ V_268 ] . V_7 ) ;
}
F_129 ( V_1 ) ;
F_130 ( V_1 -> V_176 ) ;
while ( -- V_268 >= 0 ) {
if ( V_1 -> V_11 [ V_268 ] . V_7 )
F_131 ( V_1 -> V_11 [ V_268 ] . V_7 ) ;
}
F_132 ( V_53 ) ;
F_133 ( V_53 ) ;
F_120 ( V_53 , NULL ) ;
F_138 ( V_53 ) ;
}
static int T_6 F_144 ( void )
{
return F_145 ( & V_117 ) ;
}
static void T_7 F_146 ( void )
{
F_147 ( & V_117 ) ;
}
