static bool F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
return ( V_2 -> V_5 & ( V_6 | V_7 ) ) == V_4 ;
}
static bool F_2 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
return ( V_2 -> type == V_9 && V_2 -> V_10 == V_8 ) ;
}
static bool F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_11 )
{
return V_3 == V_11 ;
}
static struct V_1 * F_4 ( struct V_12 * V_5 ,
T_1 V_13 ,
unsigned int V_14 ,
unsigned int * V_15 )
{
unsigned int V_16 , V_17 , V_18 , V_3 = 0 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
F_5 (report, &hid->report_enum[k].report_list, list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_20 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ ) {
V_2 = V_20 -> V_24 [ V_16 ] -> V_2 + V_17 ;
if ( V_2 -> type == V_9 || V_2 -> type == 0 ) {
if ( V_13 ( V_2 , V_3 , V_14 ) ) {
if ( V_15 )
* V_15 = V_3 ;
return V_2 ;
}
V_3 ++ ;
}
}
}
}
}
return NULL ;
}
static struct V_1 * F_6 ( struct V_12 * V_5 ,
const struct V_26 * V_27 ,
unsigned int * V_28 )
{
struct V_1 * V_2 ;
unsigned int V_4 ;
if ( V_27 -> V_29 & V_30 )
V_2 = F_4 ( V_5 , F_3 , V_27 -> V_28 , V_28 ) ;
else if ( F_7 ( V_27 , & V_4 ) == 0 )
V_2 = F_4 ( V_5 , F_1 , V_4 , V_28 ) ;
else
V_2 = NULL ;
return V_2 ;
}
static int F_8 ( struct V_31 * V_32 ,
struct V_26 * V_27 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
struct V_1 * V_2 ;
unsigned int V_4 , V_28 ;
V_2 = F_6 ( V_5 , V_27 , & V_28 ) ;
if ( V_2 ) {
V_27 -> V_8 = V_2 -> type == V_9 ?
V_2 -> V_10 : V_33 ;
V_27 -> V_28 = V_28 ;
V_4 = V_2 -> V_5 & ( V_6 | V_7 ) ;
V_27 -> V_34 = sizeof( V_4 ) ;
memcpy ( V_27 -> V_4 , & V_4 , sizeof( V_4 ) ) ;
return 0 ;
}
return - V_35 ;
}
static int F_10 ( struct V_31 * V_32 ,
const struct V_26 * V_27 ,
unsigned int * V_36 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_5 , V_27 , NULL ) ;
if ( V_2 ) {
* V_36 = V_2 -> type == V_9 ?
V_2 -> V_10 : V_33 ;
V_2 -> V_10 = V_27 -> V_8 ;
F_11 ( * V_36 , V_32 -> V_37 ) ;
F_12 ( V_2 -> V_10 , V_32 -> V_37 ) ;
F_13 ( L_1 ,
V_2 -> V_10 , V_2 -> V_5 ) ;
if ( F_4 ( V_5 , F_2 , * V_36 , NULL ) )
F_12 ( * V_36 , V_32 -> V_37 ) ;
return 0 ;
}
return - V_35 ;
}
static T_2 F_14 ( const struct V_38 * V_24 , T_3 V_10 )
{
T_2 V_39 = V_24 -> V_39 ;
T_2 V_40 = V_24 -> V_41 -
V_24 -> V_42 ;
T_2 V_43 = V_24 -> V_44 -
V_24 -> V_45 ;
T_2 V_46 ;
if ( V_40 <= 0 || V_43 <= 0 )
return 0 ;
if ( V_10 == V_47 || V_10 == V_48 || V_10 == V_49 ) {
if ( V_24 -> V_50 == 0x11 ) {
V_39 += 1 ;
} else if ( V_24 -> V_50 == 0x13 ) {
V_46 = V_43 ;
V_43 *= 254 ;
if ( V_43 < V_46 )
return 0 ;
V_39 -= 1 ;
} else {
return 0 ;
}
} else if ( V_10 == V_51 || V_10 == V_52 || V_10 == V_53 ) {
if ( V_24 -> V_50 == 0x14 ) {
V_46 = V_40 ;
V_40 *= 573 ;
if ( V_40 < V_46 )
return 0 ;
V_39 += 1 ;
} else if ( V_24 -> V_50 != 0x12 ) {
return 0 ;
}
} else {
return 0 ;
}
for (; V_39 < 0 ; V_39 ++ ) {
V_46 = V_40 ;
V_40 *= 10 ;
if ( V_40 < V_46 )
return 0 ;
}
for (; V_39 > 0 ; V_39 -- ) {
V_46 = V_43 ;
V_43 *= 10 ;
if ( V_43 < V_46 )
return 0 ;
}
return V_40 / V_43 ;
}
static unsigned F_15 ( struct V_12 * V_54 )
{
unsigned V_55 = 0 ;
const struct V_56 * V_13 ;
V_13 = F_16 ( V_54 , V_57 ) ;
if ( V_13 != NULL )
V_55 = V_13 -> V_58 ;
return V_55 ;
}
static int F_17 ( struct V_59 * V_60 ,
enum V_61 V_62 ,
union V_63 * V_64 )
{
struct V_12 * V_32 = F_18 ( V_60 , struct V_12 , V_65 ) ;
int V_66 = 0 ;
T_4 V_67 [ 2 ] = {} ;
switch ( V_62 ) {
case V_68 :
case V_69 :
V_64 -> V_70 = 1 ;
break;
case V_71 :
V_66 = V_32 -> V_72 ( V_32 , V_32 -> V_73 ,
V_67 , sizeof( V_67 ) ,
V_32 -> V_74 ) ;
if ( V_66 != 2 ) {
if ( V_66 >= 0 )
V_66 = - V_35 ;
break;
}
if ( V_32 -> V_75 < V_32 -> V_76 &&
V_67 [ 1 ] >= V_32 -> V_75 &&
V_67 [ 1 ] <= V_32 -> V_76 )
V_64 -> V_70 = ( 100 * ( V_67 [ 1 ] - V_32 -> V_75 ) ) /
( V_32 -> V_76 - V_32 -> V_75 ) ;
break;
case V_77 :
V_64 -> V_78 = V_32 -> V_79 ;
break;
case V_80 :
V_64 -> V_70 = V_81 ;
break;
case V_82 :
V_64 -> V_70 = V_83 ;
break;
default:
V_66 = - V_35 ;
break;
}
return V_66 ;
}
static bool F_19 ( struct V_12 * V_32 , unsigned V_84 , struct V_38 * V_24 )
{
struct V_59 * V_65 = & V_32 -> V_65 ;
int V_66 ;
unsigned V_55 ;
T_5 V_85 , V_86 ;
if ( V_24 -> V_2 -> V_5 != V_87 )
return false ;
if ( V_65 -> V_79 != NULL )
goto V_88;
V_65 -> V_79 = F_20 ( V_89 , L_2 , V_32 -> V_90 ) ;
if ( V_65 -> V_79 == NULL )
goto V_88;
V_65 -> type = V_91 ;
V_65 -> V_92 = V_93 ;
V_65 -> V_94 = F_21 ( V_93 ) ;
V_65 -> V_95 = 0 ;
V_65 -> V_96 = F_17 ;
V_55 = F_15 ( V_32 ) ;
F_22 ( V_32 , L_3 ,
V_32 -> V_97 , V_32 -> V_98 , V_32 -> V_99 , V_32 -> V_100 , V_55 ) ;
V_85 = V_24 -> V_42 ;
V_86 = V_24 -> V_41 ;
if ( V_55 & V_101 ) {
V_85 = 0 ;
V_86 = 100 ;
}
if ( V_55 & V_102 )
V_84 = V_103 ;
V_32 -> V_75 = V_85 ;
V_32 -> V_76 = V_86 ;
V_32 -> V_74 = V_84 ;
V_32 -> V_73 = V_24 -> V_20 -> V_104 ;
V_66 = F_23 ( & V_32 -> V_32 , V_65 ) ;
if ( V_66 != 0 ) {
F_24 ( V_32 , L_4 , V_66 ) ;
F_25 ( V_65 -> V_79 ) ;
V_65 -> V_79 = NULL ;
}
F_26 ( V_65 , & V_32 -> V_32 ) ;
V_88:
return true ;
}
static void F_27 ( struct V_12 * V_32 )
{
if ( ! V_32 -> V_65 . V_79 )
return;
F_28 ( & V_32 -> V_65 ) ;
F_25 ( V_32 -> V_65 . V_79 ) ;
V_32 -> V_65 . V_79 = NULL ;
}
static bool F_19 ( struct V_12 * V_32 , unsigned V_84 ,
struct V_38 * V_24 )
{
return false ;
}
static void F_27 ( struct V_12 * V_32 )
{
}
static void F_29 ( struct V_105 * V_106 , struct V_38 * V_24 ,
struct V_1 * V_2 )
{
struct V_31 * V_107 = V_106 -> V_107 ;
struct V_12 * V_108 = F_9 ( V_107 ) ;
int V_86 = 0 , V_10 ;
unsigned long * V_109 = NULL ;
V_24 -> V_106 = V_106 ;
if ( V_24 -> V_29 & V_110 )
goto V_111;
if ( V_24 -> V_84 == V_22 &&
( V_2 -> V_5 & V_6 ) != V_112 ) {
goto V_111;
}
if ( V_108 -> V_113 -> V_114 ) {
int V_66 = V_108 -> V_113 -> V_114 ( V_108 , V_106 , V_24 ,
V_2 , & V_109 , & V_86 ) ;
if ( V_66 > 0 )
goto V_115;
if ( V_66 < 0 )
goto V_111;
}
switch ( V_2 -> V_5 & V_6 ) {
case V_116 :
goto V_111;
case V_117 :
F_12 ( V_118 , V_107 -> V_119 ) ;
if ( ( V_2 -> V_5 & V_7 ) < 256 ) {
if ( ! V_120 [ V_2 -> V_5 & V_7 ] ) goto V_111;
F_30 ( V_120 [ V_2 -> V_5 & V_7 ] ) ;
} else
F_31 ( V_121 ) ;
break;
case V_122 :
V_10 = ( ( V_2 -> V_5 - 1 ) & V_7 ) ;
switch ( V_24 -> V_123 ) {
case V_124 :
case V_125 : V_10 += V_126 ; break;
case V_127 :
if ( V_10 <= 0xf )
V_10 += V_128 ;
else
V_10 += V_129 ;
break;
case V_130 : V_10 += V_131 ; break;
default:
switch ( V_24 -> V_132 ) {
case V_124 :
case V_125 : V_10 += V_126 ; break;
case V_127 : V_10 += V_128 ; break;
case V_130 : V_10 += V_131 ; break;
default: V_10 += V_133 ;
}
}
F_31 ( V_10 ) ;
break;
case V_134 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0xba : F_32 ( V_135 ) ; break;
case 0xbb : F_32 ( V_136 ) ; break;
case 0xc4 : F_32 ( V_137 ) ; break;
case 0xc5 : F_32 ( V_138 ) ; break;
case 0xc8 : F_32 ( V_139 ) ; break;
default: goto V_111;
}
break;
case V_140 :
if ( ( V_2 -> V_5 & 0xf0 ) == 0x80 ) {
switch ( V_2 -> V_5 & 0xf ) {
case 0x1 : F_30 ( V_141 ) ; break;
case 0x2 : F_30 ( V_142 ) ; break;
case 0x3 : F_30 ( V_143 ) ; break;
case 0x4 : F_30 ( V_144 ) ; break;
case 0x5 : F_30 ( V_145 ) ; break;
case 0x6 : F_30 ( V_146 ) ; break;
case 0x7 : F_30 ( V_147 ) ; break;
case 0x8 : F_30 ( V_148 ) ; break;
case 0x9 : F_30 ( V_149 ) ; break;
case 0xa : F_30 ( V_150 ) ; break;
case 0xb : F_30 ( V_151 ) ; break;
case 0xc : F_30 ( V_152 ) ; break;
case 0xd : F_30 ( V_153 ) ; break;
case 0xe : F_30 ( V_154 ) ; break;
case 0xf : F_30 ( V_155 ) ; break;
default: goto V_156;
}
break;
}
if ( ( V_2 -> V_5 & 0xf0 ) == 0x90 ) {
switch ( V_2 -> V_5 ) {
case V_157 : V_2 -> V_158 = 1 ; break;
case V_159 : V_2 -> V_158 = 5 ; break;
case V_160 : V_2 -> V_158 = 3 ; break;
case V_161 : V_2 -> V_158 = 7 ; break;
default: goto V_156;
}
if ( V_24 -> V_162 ) {
F_32 ( V_24 -> V_162 ) ;
goto V_111;
}
F_32 ( V_163 ) ;
break;
}
switch ( V_2 -> V_5 ) {
case V_164 : case V_165 : case V_166 :
case V_167 : case V_168 : case V_169 :
case V_170 : case V_171 : case V_172 :
if ( V_24 -> V_29 & V_173 )
F_33 ( V_2 -> V_5 & 0xf ) ;
else
F_32 ( V_2 -> V_5 & 0xf ) ;
break;
case V_174 :
V_2 -> V_175 = V_24 -> V_42 ;
V_2 -> V_176 = V_24 -> V_41 ;
F_32 ( V_163 ) ;
break;
case V_177 : F_30 ( V_178 ) ; break;
case V_179 : F_30 ( V_180 ) ; break;
default: goto V_156;
}
break;
case V_112 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0x01 : F_34 ( V_181 ) ; break;
case 0x02 : F_34 ( V_182 ) ; break;
case 0x03 : F_34 ( V_183 ) ; break;
case 0x04 : F_34 ( V_184 ) ; break;
case 0x05 : F_34 ( V_185 ) ; break;
case 0x27 : F_34 ( V_186 ) ; break;
case 0x4c : F_34 ( V_187 ) ; break;
case 0x09 : F_34 ( V_188 ) ; break;
case 0x4b : F_34 ( V_189 ) ; break;
case 0x19 : F_34 ( V_190 ) ; break;
case 0x4d : F_34 ( V_191 ) ; break;
default: goto V_111;
}
break;
case V_192 :
switch ( V_2 -> V_5 & 0xff ) {
case 0x00 :
goto V_111;
case 0x30 :
if ( ! F_35 ( V_193 , V_107 -> V_37 ) ) {
V_108 -> V_55 |= V_194 ;
F_12 ( V_9 , V_107 -> V_119 ) ;
F_12 ( V_193 , V_107 -> V_37 ) ;
}
F_36 ( V_195 ) ;
break;
case 0x32 :
switch ( V_24 -> V_132 & 0xff ) {
case 0x21 : F_31 ( V_196 ) ; break;
case 0x22 : F_31 ( V_197 ) ; break;
default: F_31 ( V_198 ) ; break;
}
break;
case 0x3c :
F_30 ( V_199 ) ;
break;
case 0x33 :
case 0x42 :
case 0x43 :
V_108 -> V_55 &= ~ V_194 ;
F_30 ( V_193 ) ;
break;
case 0x44 :
F_30 ( V_200 ) ;
break;
case 0x46 :
F_30 ( V_201 ) ;
break;
case 0x51 :
V_108 -> V_55 |= V_202 ;
goto V_156;
default: goto V_156;
}
break;
case V_203 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x000 : goto V_111;
case 0x030 : F_30 ( V_141 ) ; break;
case 0x031 : F_30 ( V_155 ) ; break;
case 0x032 : F_30 ( V_142 ) ; break;
case 0x034 : F_30 ( V_142 ) ; break;
case 0x035 : F_30 ( V_204 ) ; break;
case 0x036 : F_30 ( V_133 ) ; break;
case 0x040 : F_30 ( V_145 ) ; break;
case 0x041 : F_30 ( V_149 ) ; break;
case 0x042 : F_30 ( V_152 ) ; break;
case 0x043 : F_30 ( V_153 ) ; break;
case 0x044 : F_30 ( V_151 ) ; break;
case 0x045 : F_30 ( V_150 ) ; break;
case 0x046 : F_30 ( V_205 ) ; break;
case 0x047 : F_30 ( V_206 ) ; break;
case 0x048 : F_30 ( V_207 ) ; break;
case 0x060 : F_30 ( V_208 ) ; break;
case 0x061 : F_30 ( V_209 ) ; break;
case 0x063 : F_30 ( V_210 ) ; break;
case 0x065 : F_30 ( V_211 ) ; break;
case 0x069 : F_30 ( V_212 ) ; break;
case 0x06a : F_30 ( V_213 ) ; break;
case 0x06b : F_30 ( V_214 ) ; break;
case 0x06c : F_30 ( V_215 ) ; break;
case 0x06d : F_30 ( V_216 ) ; break;
case 0x082 : F_30 ( V_217 ) ; break;
case 0x083 : F_30 ( V_218 ) ; break;
case 0x084 : F_30 ( V_219 ) ; break;
case 0x088 : F_30 ( V_220 ) ; break;
case 0x089 : F_30 ( V_221 ) ; break;
case 0x08a : F_30 ( V_222 ) ; break;
case 0x08b : F_30 ( V_223 ) ; break;
case 0x08c : F_30 ( V_224 ) ; break;
case 0x08d : F_30 ( V_225 ) ; break;
case 0x08e : F_30 ( V_226 ) ; break;
case 0x08f : F_30 ( V_227 ) ; break;
case 0x090 : F_30 ( V_228 ) ; break;
case 0x091 : F_30 ( V_229 ) ; break;
case 0x092 : F_30 ( V_210 ) ; break;
case 0x093 : F_30 ( V_230 ) ; break;
case 0x094 : F_30 ( V_148 ) ; break;
case 0x095 : F_30 ( V_147 ) ; break;
case 0x096 : F_30 ( V_231 ) ; break;
case 0x097 : F_30 ( V_232 ) ; break;
case 0x098 : F_30 ( V_233 ) ; break;
case 0x09a : F_30 ( V_234 ) ; break;
case 0x09c : F_30 ( V_235 ) ; break;
case 0x09d : F_30 ( V_236 ) ; break;
case 0x0a0 : F_30 ( V_237 ) ; break;
case 0x0b0 : F_30 ( V_238 ) ; break;
case 0x0b1 : F_30 ( V_239 ) ; break;
case 0x0b2 : F_30 ( V_240 ) ; break;
case 0x0b3 : F_30 ( V_241 ) ; break;
case 0x0b4 : F_30 ( V_242 ) ; break;
case 0x0b5 : F_30 ( V_243 ) ; break;
case 0x0b6 : F_30 ( V_244 ) ; break;
case 0x0b7 : F_30 ( V_245 ) ; break;
case 0x0b8 : F_30 ( V_246 ) ; break;
case 0x0bc : F_30 ( V_247 ) ; break;
case 0x0b9 : F_30 ( V_248 ) ; break;
case 0x0bf : F_30 ( V_249 ) ; break;
case 0x0cd : F_30 ( V_250 ) ; break;
case 0x0e0 : F_36 ( V_251 ) ; break;
case 0x0e2 : F_30 ( V_252 ) ; break;
case 0x0e5 : F_30 ( V_253 ) ; break;
case 0x0e9 : F_30 ( V_254 ) ; break;
case 0x0ea : F_30 ( V_255 ) ; break;
case 0x0f5 : F_30 ( V_249 ) ; break;
case 0x182 : F_30 ( V_256 ) ; break;
case 0x183 : F_30 ( V_257 ) ; break;
case 0x184 : F_30 ( V_258 ) ; break;
case 0x185 : F_30 ( V_259 ) ; break;
case 0x186 : F_30 ( V_260 ) ; break;
case 0x187 : F_30 ( V_261 ) ; break;
case 0x188 : F_30 ( V_262 ) ; break;
case 0x189 : F_30 ( V_263 ) ; break;
case 0x18a : F_30 ( V_264 ) ; break;
case 0x18b : F_30 ( V_265 ) ; break;
case 0x18c : F_30 ( V_266 ) ; break;
case 0x18d : F_30 ( V_267 ) ; break;
case 0x18e : F_30 ( V_268 ) ; break;
case 0x191 : F_30 ( V_269 ) ; break;
case 0x192 : F_30 ( V_270 ) ; break;
case 0x193 : F_30 ( V_271 ) ; break;
case 0x194 : F_30 ( V_272 ) ; break;
case 0x196 : F_30 ( V_222 ) ; break;
case 0x199 : F_30 ( V_273 ) ; break;
case 0x19c : F_30 ( V_274 ) ; break;
case 0x19e : F_30 ( V_275 ) ; break;
case 0x1a6 : F_30 ( V_147 ) ; break;
case 0x1a7 : F_30 ( V_276 ) ; break;
case 0x1ab : F_30 ( V_277 ) ; break;
case 0x1ae : F_30 ( V_278 ) ; break;
case 0x1b6 : F_30 ( V_279 ) ; break;
case 0x1b7 : F_30 ( V_280 ) ; break;
case 0x1b8 : F_30 ( V_281 ) ; break;
case 0x1bc : F_30 ( V_282 ) ; break;
case 0x1bd : F_30 ( V_208 ) ; break;
case 0x201 : F_30 ( V_283 ) ; break;
case 0x202 : F_30 ( V_284 ) ; break;
case 0x203 : F_30 ( V_285 ) ; break;
case 0x204 : F_30 ( V_148 ) ; break;
case 0x207 : F_30 ( V_286 ) ; break;
case 0x208 : F_30 ( V_287 ) ; break;
case 0x209 : F_30 ( V_288 ) ; break;
case 0x21a : F_30 ( V_289 ) ; break;
case 0x21b : F_30 ( V_290 ) ; break;
case 0x21c : F_30 ( V_291 ) ; break;
case 0x21d : F_30 ( V_292 ) ; break;
case 0x21f : F_30 ( V_293 ) ; break;
case 0x221 : F_30 ( V_294 ) ; break;
case 0x222 : F_30 ( V_295 ) ; break;
case 0x223 : F_30 ( V_296 ) ; break;
case 0x224 : F_30 ( V_297 ) ; break;
case 0x225 : F_30 ( V_298 ) ; break;
case 0x226 : F_30 ( V_299 ) ; break;
case 0x227 : F_30 ( V_300 ) ; break;
case 0x22a : F_30 ( V_256 ) ; break;
case 0x22d : F_30 ( V_301 ) ; break;
case 0x22e : F_30 ( V_302 ) ; break;
case 0x22f : F_30 ( V_303 ) ; break;
case 0x233 : F_30 ( V_304 ) ; break;
case 0x234 : F_30 ( V_305 ) ; break;
case 0x238 : F_33 ( V_306 ) ; break;
case 0x23d : F_30 ( V_307 ) ; break;
case 0x25f : F_30 ( V_308 ) ; break;
case 0x269 : F_30 ( V_309 ) ; break;
case 0x26a : F_30 ( V_310 ) ; break;
case 0x279 : F_30 ( V_311 ) ; break;
case 0x289 : F_30 ( V_312 ) ; break;
case 0x28b : F_30 ( V_313 ) ; break;
case 0x28c : F_30 ( V_314 ) ; break;
default: goto V_111;
}
break;
case V_315 :
if ( F_19 ( V_108 , V_21 , V_24 ) )
goto V_111;
else
goto V_156;
break;
case V_316 :
F_12 ( V_118 , V_107 -> V_119 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x021 : F_30 ( V_287 ) ; break;
case 0x070 : F_30 ( V_317 ) ; break;
case 0x071 : F_30 ( V_211 ) ; break;
case 0x072 : F_30 ( V_318 ) ; break;
case 0x073 : F_30 ( V_319 ) ; break;
case 0x080 : F_30 ( V_320 ) ; break;
case 0x081 : F_30 ( V_273 ) ; break;
case 0x082 : F_30 ( V_294 ) ; break;
case 0x083 : F_30 ( V_321 ) ; break;
case 0x084 : F_30 ( V_269 ) ; break;
case 0x085 : F_30 ( V_322 ) ; break;
case 0x086 : F_30 ( V_323 ) ; break;
default: goto V_111;
}
break;
case V_324 :
goto V_111;
case V_325 :
F_12 ( V_118 , V_107 -> V_119 ) ;
goto V_111;
case V_326 :
goto V_111;
case V_327 :
switch ( V_2 -> V_5 & V_7 ) {
case 0xa4 : F_30 ( V_328 ) ; break;
default: goto V_111;
}
break;
default:
V_156:
if ( V_24 -> V_329 == 1 ) {
if ( V_24 -> V_20 -> type == V_22 ) {
F_34 ( V_189 ) ;
break;
}
F_31 ( V_133 ) ;
break;
}
if ( V_24 -> V_29 & V_173 ) {
F_33 ( V_330 ) ;
break;
}
F_32 ( V_331 ) ;
break;
}
V_115:
if ( V_108 -> V_113 -> V_332 && V_108 -> V_113 -> V_332 ( V_108 ,
V_106 , V_24 , V_2 , & V_109 , & V_86 ) < 0 )
goto V_111;
F_12 ( V_2 -> type , V_107 -> V_119 ) ;
while ( V_2 -> V_10 <= V_86 && F_37 ( V_2 -> V_10 , V_109 ) )
V_2 -> V_10 = F_38 ( V_109 , V_86 + 1 , V_2 -> V_10 ) ;
if ( V_2 -> V_10 > V_86 )
goto V_111;
if ( V_2 -> type == V_333 ) {
int V_334 = V_24 -> V_42 ;
int V_335 = V_24 -> V_41 ;
if ( ( V_108 -> V_55 & V_336 ) && ( V_2 -> V_10 == V_47 || V_2 -> V_10 == V_48 ) ) {
V_334 = V_24 -> V_42 = 0 ;
V_335 = V_24 -> V_41 = 255 ;
}
if ( V_24 -> V_123 == V_130 || V_24 -> V_123 == V_127 )
F_39 ( V_107 , V_2 -> V_10 , V_334 , V_335 , ( V_335 - V_334 ) >> 8 , ( V_335 - V_334 ) >> 4 ) ;
else F_39 ( V_107 , V_2 -> V_10 , V_334 , V_335 , 0 , 0 ) ;
F_40 ( V_107 , V_2 -> V_10 ,
F_14 ( V_24 , V_2 -> V_10 ) ) ;
if ( V_2 -> V_10 == V_337 && V_107 -> V_338 == 0 )
F_41 ( V_107 , 60 ) ;
}
if ( V_2 -> type == V_333 &&
( V_2 -> V_175 < V_2 -> V_176 || V_2 -> V_158 ) ) {
int V_16 ;
for ( V_16 = V_2 -> V_10 ; V_16 < V_2 -> V_10 + 2 && V_16 <= V_86 ; V_16 ++ ) {
F_39 ( V_107 , V_16 , - 1 , 1 , 0 , 0 ) ;
F_12 ( V_16 , V_107 -> V_339 ) ;
}
if ( V_2 -> V_158 && ! V_24 -> V_162 )
V_24 -> V_162 = V_2 -> V_10 ;
}
if ( ( V_2 -> type == V_333 ) && ( V_24 -> V_29 & V_173 ) &&
( V_2 -> V_10 == V_251 ) ) {
F_12 ( V_254 , V_107 -> V_37 ) ;
F_12 ( V_255 , V_107 -> V_37 ) ;
}
if ( V_2 -> type == V_9 ) {
F_12 ( V_340 , V_107 -> V_119 ) ;
F_12 ( V_341 , V_107 -> V_342 ) ;
}
V_111:
return;
}
void F_42 ( struct V_12 * V_5 , struct V_38 * V_24 , struct V_1 * V_2 , T_2 V_14 )
{
struct V_31 * V_107 ;
unsigned * V_55 = & V_5 -> V_55 ;
if ( ! V_24 -> V_106 )
return;
V_107 = V_24 -> V_106 -> V_107 ;
if ( ! V_2 -> type )
return;
if ( V_2 -> V_175 < V_2 -> V_176 || V_2 -> V_158 ) {
int V_158 = V_2 -> V_158 ;
if ( ! V_158 )
V_158 = ( V_14 - V_2 -> V_175 ) * 8 / ( V_2 -> V_176 - V_2 -> V_175 + 1 ) + 1 ;
if ( V_158 < 0 || V_158 > 8 ) V_158 = 0 ;
F_43 ( V_107 , V_2 -> type , V_2 -> V_10 , V_343 [ V_158 ] . V_344 ) ;
F_43 ( V_107 , V_2 -> type , V_2 -> V_10 + 1 , V_343 [ V_158 ] . V_345 ) ;
return;
}
if ( V_2 -> V_5 == ( V_192 | 0x003c ) ) {
* V_55 = V_14 ? ( * V_55 | V_346 ) : ( * V_55 & ~ V_346 ) ;
return;
}
if ( V_2 -> V_5 == ( V_192 | 0x0032 ) ) {
if ( V_14 ) {
F_43 ( V_107 , V_2 -> type , ( * V_55 & V_346 ) ? V_199 : V_2 -> V_10 , 1 ) ;
return;
}
F_43 ( V_107 , V_2 -> type , V_2 -> V_10 , 0 ) ;
F_43 ( V_107 , V_2 -> type , V_199 , 0 ) ;
return;
}
if ( V_2 -> V_5 == ( V_192 | 0x0030 ) && ( * V_55 & V_194 ) ) {
int V_334 = V_24 -> V_42 ;
int V_335 = V_24 -> V_41 ;
F_43 ( V_107 , V_9 , V_193 , V_14 > V_334 + ( ( V_335 - V_334 ) >> 3 ) ) ;
}
if ( V_2 -> V_5 == ( V_327 | 0x83UL ) ) {
F_13 ( L_5 , V_14 ) ;
return;
}
if ( V_2 -> V_5 == ( V_327 | 0x7fUL ) ) {
F_13 ( L_6 ) ;
return;
}
if ( ( V_2 -> type == V_9 ) && ( V_2 -> V_10 == 0 ) )
return;
if ( ( V_2 -> type == V_333 ) && ( V_24 -> V_29 & V_173 ) &&
( V_2 -> V_10 == V_251 ) ) {
int V_347 = abs ( V_14 ) ;
int V_348 = V_14 > 0 ? V_254 : V_255 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_347 ; V_16 ++ ) {
F_43 ( V_107 , V_9 , V_348 , 1 ) ;
F_44 ( V_107 ) ;
F_43 ( V_107 , V_9 , V_348 , 0 ) ;
F_44 ( V_107 ) ;
}
return;
}
if ( ( V_24 -> V_29 & V_349 ) &&
( V_14 < V_24 -> V_42 ||
V_14 > V_24 -> V_41 ) ) {
F_13 ( L_7 , V_14 ) ;
return;
}
if ( V_2 -> type == V_9 && ! ! F_35 ( V_2 -> V_10 , V_107 -> V_350 ) != V_14 )
F_43 ( V_107 , V_340 , V_341 , V_2 -> V_5 ) ;
F_43 ( V_107 , V_2 -> type , V_2 -> V_10 , V_14 ) ;
if ( ( V_24 -> V_29 & V_173 ) && ( V_2 -> type == V_9 ) )
F_43 ( V_107 , V_2 -> type , V_2 -> V_10 , 0 ) ;
}
void F_45 ( struct V_12 * V_5 , struct V_19 * V_20 )
{
struct V_105 * V_106 ;
if ( V_5 -> V_55 & V_351 )
return;
F_5 (hidinput, &hid->inputs, list)
F_44 ( V_106 -> V_107 ) ;
}
int F_46 ( struct V_12 * V_5 , unsigned int type , unsigned int V_10 , struct V_38 * * V_24 )
{
struct V_19 * V_20 ;
int V_16 , V_17 ;
F_5 (report, &hid->report_enum[HID_OUTPUT_REPORT].report_list, list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ ) {
* V_24 = V_20 -> V_24 [ V_16 ] ;
for ( V_17 = 0 ; V_17 < ( * V_24 ) -> V_25 ; V_17 ++ )
if ( ( * V_24 ) -> V_2 [ V_17 ] . type == type && ( * V_24 ) -> V_2 [ V_17 ] . V_10 == V_10 )
return V_17 ;
}
}
return - 1 ;
}
struct V_38 * F_47 ( struct V_12 * V_5 )
{
struct V_19 * V_20 ;
struct V_38 * V_24 ;
int V_16 , V_17 ;
F_5 (report,
&hid->report_enum[HID_OUTPUT_REPORT].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ ) {
V_24 = V_20 -> V_24 [ V_16 ] ;
for ( V_17 = 0 ; V_17 < V_24 -> V_25 ; V_17 ++ )
if ( V_24 -> V_2 [ V_17 ] . type == V_352 )
return V_24 ;
}
}
return NULL ;
}
unsigned int F_48 ( struct V_12 * V_5 )
{
struct V_19 * V_20 ;
struct V_38 * V_24 ;
int V_16 , V_17 ;
unsigned int V_347 = 0 ;
F_5 (report,
&hid->report_enum[HID_OUTPUT_REPORT].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ ) {
V_24 = V_20 -> V_24 [ V_16 ] ;
for ( V_17 = 0 ; V_17 < V_24 -> V_25 ; V_17 ++ )
if ( V_24 -> V_2 [ V_17 ] . type == V_352 &&
V_24 -> V_14 [ V_17 ] )
V_347 += 1 ;
}
}
return V_347 ;
}
static int F_49 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
return F_50 ( V_5 ) ;
}
static void F_51 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
F_52 ( V_5 ) ;
}
static void F_53 ( struct V_12 * V_5 )
{
struct V_353 * V_354 = V_5 -> V_113 ;
struct V_355 * V_356 ;
struct V_19 * V_357 ;
int V_16 , V_17 ;
V_356 = & V_5 -> V_358 [ V_103 ] ;
F_5 (rep, &rep_enum->report_list, list)
for ( V_16 = 0 ; V_16 < V_357 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_357 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ ) {
F_19 ( V_5 , V_103 , V_357 -> V_24 [ V_16 ] ) ;
if ( V_354 -> V_359 )
V_354 -> V_359 ( V_5 , V_357 -> V_24 [ V_16 ] ,
V_357 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
}
}
int F_54 ( struct V_12 * V_5 , unsigned int V_360 )
{
struct V_19 * V_20 ;
struct V_105 * V_106 = NULL ;
struct V_31 * V_31 ;
int V_16 , V_17 , V_18 ;
F_55 ( & V_5 -> V_361 ) ;
if ( ! V_360 ) {
for ( V_16 = 0 ; V_16 < V_5 -> V_362 ; V_16 ++ ) {
struct V_363 * V_364 = & V_5 -> V_365 [ V_16 ] ;
if ( V_364 -> type == V_366 ||
V_364 -> type == V_367 )
if ( F_56 ( V_364 -> V_2 ) )
break;
}
if ( V_16 == V_5 -> V_362 )
return - 1 ;
}
F_53 ( V_5 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_55 & V_368 )
continue;
F_5 (report, &hid->report_enum[k].report_list, list) {
if ( ! V_20 -> V_23 )
continue;
if ( ! V_106 ) {
V_106 = F_57 ( sizeof( * V_106 ) , V_89 ) ;
V_31 = F_58 () ;
if ( ! V_106 || ! V_31 ) {
F_25 ( V_106 ) ;
F_59 ( V_31 ) ;
F_60 ( V_5 , L_8 ) ;
goto V_369;
}
F_61 ( V_31 , V_5 ) ;
V_31 -> V_370 =
V_5 -> V_371 -> V_372 ;
V_31 -> V_373 = F_49 ;
V_31 -> V_374 = F_51 ;
V_31 -> V_375 = F_10 ;
V_31 -> V_376 = F_8 ;
V_31 -> V_79 = V_5 -> V_79 ;
V_31 -> V_377 = V_5 -> V_377 ;
V_31 -> V_90 = V_5 -> V_90 ;
V_31 -> V_104 . V_378 = V_5 -> V_97 ;
V_31 -> V_104 . V_98 = V_5 -> V_98 ;
V_31 -> V_104 . V_99 = V_5 -> V_99 ;
V_31 -> V_104 . V_100 = V_5 -> V_100 ;
V_31 -> V_32 . V_379 = V_5 -> V_32 . V_379 ;
V_106 -> V_107 = V_31 ;
F_62 ( & V_106 -> V_380 , & V_5 -> V_361 ) ;
}
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_20 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ )
F_29 ( V_106 , V_20 -> V_24 [ V_16 ] ,
V_20 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
if ( V_5 -> V_55 & V_381 ) {
V_106 -> V_20 = V_20 ;
if ( F_63 ( V_106 -> V_107 ) )
goto V_382;
V_106 = NULL ;
}
}
}
if ( V_5 -> V_55 & V_202 ) {
if ( V_106 )
goto V_382;
goto V_369;
}
if ( V_106 && F_63 ( V_106 -> V_107 ) )
goto V_382;
return 0 ;
V_382:
F_64 ( & V_106 -> V_380 ) ;
F_59 ( V_106 -> V_107 ) ;
F_25 ( V_106 ) ;
V_369:
F_65 ( V_5 ) ;
return - 1 ;
}
void F_65 ( struct V_12 * V_5 )
{
struct V_105 * V_106 , * V_383 ;
F_27 ( V_5 ) ;
F_66 (hidinput, next, &hid->inputs, list) {
F_64 ( & V_106 -> V_380 ) ;
F_67 ( V_106 -> V_107 ) ;
F_25 ( V_106 ) ;
}
}
