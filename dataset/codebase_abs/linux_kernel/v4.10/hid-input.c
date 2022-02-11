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
T_2 F_14 ( const struct V_38 * V_24 , T_3 V_10 )
{
T_2 V_39 = V_24 -> V_39 ;
T_2 V_40 = V_24 -> V_41 -
V_24 -> V_42 ;
T_2 V_43 = V_24 -> V_44 -
V_24 -> V_45 ;
T_2 V_46 ;
if ( V_40 <= 0 || V_43 <= 0 )
return 0 ;
switch ( V_10 ) {
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
if ( V_24 -> V_56 == 0x11 ) {
V_39 += 1 ;
} else if ( V_24 -> V_56 == 0x13 ) {
V_46 = V_43 ;
V_43 *= 254 ;
if ( V_43 < V_46 )
return 0 ;
V_39 -= 1 ;
} else {
return 0 ;
}
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
if ( V_24 -> V_56 == 0x14 ) {
V_46 = V_40 ;
V_40 *= 573 ;
if ( V_40 < V_46 )
return 0 ;
V_39 += 1 ;
} else if ( V_24 -> V_56 != 0x12 ) {
return 0 ;
}
break;
default:
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
return F_15 ( V_40 , V_43 ) ;
}
static unsigned F_16 ( struct V_12 * V_63 )
{
unsigned V_64 = 0 ;
const struct V_65 * V_13 ;
V_13 = F_17 ( V_63 , V_66 ) ;
if ( V_13 != NULL )
V_64 = V_13 -> V_67 ;
return V_64 ;
}
static int F_18 ( struct V_68 * V_69 ,
enum V_70 V_71 ,
union V_72 * V_73 )
{
struct V_12 * V_32 = F_19 ( V_69 ) ;
int V_74 = 0 ;
T_4 * V_75 ;
switch ( V_71 ) {
case V_76 :
case V_77 :
V_73 -> V_78 = 1 ;
break;
case V_79 :
V_75 = F_20 ( 2 * sizeof( T_4 ) , V_80 ) ;
if ( ! V_75 ) {
V_74 = - V_81 ;
break;
}
V_74 = F_21 ( V_32 , V_32 -> V_82 , V_75 , 2 ,
V_32 -> V_83 ,
V_84 ) ;
if ( V_74 != 2 ) {
V_74 = - V_85 ;
F_22 ( V_75 ) ;
break;
}
V_74 = 0 ;
if ( V_32 -> V_86 < V_32 -> V_87 &&
V_75 [ 1 ] >= V_32 -> V_86 &&
V_75 [ 1 ] <= V_32 -> V_87 )
V_73 -> V_78 = ( 100 * ( V_75 [ 1 ] - V_32 -> V_86 ) ) /
( V_32 -> V_87 - V_32 -> V_86 ) ;
F_22 ( V_75 ) ;
break;
case V_88 :
V_73 -> V_89 = V_32 -> V_90 ;
break;
case V_91 :
V_73 -> V_78 = V_92 ;
break;
case V_93 :
V_73 -> V_78 = V_94 ;
break;
default:
V_74 = - V_35 ;
break;
}
return V_74 ;
}
static bool F_23 ( struct V_12 * V_32 , unsigned V_95 , struct V_38 * V_24 )
{
struct V_96 * V_97 = NULL ;
struct V_98 V_99 = { . V_100 = V_32 , } ;
unsigned V_64 ;
T_5 V_101 , V_102 ;
if ( V_24 -> V_2 -> V_5 != V_103 )
return false ;
if ( V_32 -> V_104 != NULL )
goto V_105;
V_64 = F_16 ( V_32 ) ;
F_24 ( V_32 , L_2 ,
V_32 -> V_106 , V_32 -> V_107 , V_32 -> V_108 , V_32 -> V_109 , V_64 ) ;
if ( V_64 & V_110 )
goto V_105;
V_97 = F_25 ( sizeof( * V_97 ) , V_80 ) ;
if ( V_97 == NULL )
goto V_105;
V_97 -> V_90 = F_26 ( V_80 , L_3 , V_32 -> V_111 ) ;
if ( V_97 -> V_90 == NULL ) {
F_22 ( V_97 ) ;
goto V_105;
}
V_97 -> type = V_112 ;
V_97 -> V_113 = V_114 ;
V_97 -> V_115 = F_27 ( V_114 ) ;
V_97 -> V_116 = 0 ;
V_97 -> V_117 = F_18 ;
V_101 = V_24 -> V_42 ;
V_102 = V_24 -> V_41 ;
if ( V_64 & V_118 ) {
V_101 = 0 ;
V_102 = 100 ;
}
if ( V_64 & V_119 )
V_95 = V_120 ;
V_32 -> V_86 = V_101 ;
V_32 -> V_87 = V_102 ;
V_32 -> V_83 = V_95 ;
V_32 -> V_82 = V_24 -> V_20 -> V_121 ;
V_32 -> V_104 = F_28 ( & V_32 -> V_32 , V_97 , & V_99 ) ;
if ( F_29 ( V_32 -> V_104 ) ) {
F_30 ( V_32 , L_4 ,
F_31 ( V_32 -> V_104 ) ) ;
F_22 ( V_97 -> V_90 ) ;
F_22 ( V_97 ) ;
V_32 -> V_104 = NULL ;
} else {
F_32 ( V_32 -> V_104 , & V_32 -> V_32 ) ;
}
V_105:
return true ;
}
static void F_33 ( struct V_12 * V_32 )
{
const struct V_96 * V_97 ;
if ( ! V_32 -> V_104 )
return;
V_97 = V_32 -> V_104 -> V_122 ;
F_34 ( V_32 -> V_104 ) ;
F_22 ( V_97 -> V_90 ) ;
F_22 ( V_97 ) ;
V_32 -> V_104 = NULL ;
}
static bool F_23 ( struct V_12 * V_32 , unsigned V_95 ,
struct V_38 * V_24 )
{
return false ;
}
static void F_33 ( struct V_12 * V_32 )
{
}
static void F_35 ( struct V_123 * V_124 , struct V_38 * V_24 ,
struct V_1 * V_2 )
{
struct V_31 * V_125 = V_124 -> V_125 ;
struct V_12 * V_126 = F_9 ( V_125 ) ;
int V_102 = 0 , V_10 ;
unsigned long * V_127 = NULL ;
V_24 -> V_124 = V_124 ;
if ( V_24 -> V_29 & V_128 )
goto V_129;
if ( V_24 -> V_130 < 1 )
goto V_129;
if ( V_24 -> V_95 == V_22 &&
( V_2 -> V_5 & V_6 ) != V_131 ) {
goto V_129;
}
if ( V_126 -> V_132 -> V_133 ) {
int V_74 = V_126 -> V_132 -> V_133 ( V_126 , V_124 , V_24 ,
V_2 , & V_127 , & V_102 ) ;
if ( V_74 > 0 )
goto V_134;
if ( V_74 < 0 )
goto V_129;
}
switch ( V_2 -> V_5 & V_6 ) {
case V_135 :
goto V_129;
case V_136 :
F_12 ( V_137 , V_125 -> V_138 ) ;
if ( ( V_2 -> V_5 & V_7 ) < 256 ) {
if ( ! V_139 [ V_2 -> V_5 & V_7 ] ) goto V_129;
F_36 ( V_139 [ V_2 -> V_5 & V_7 ] ) ;
} else
F_37 ( V_140 ) ;
break;
case V_141 :
V_10 = ( ( V_2 -> V_5 - 1 ) & V_7 ) ;
switch ( V_24 -> V_142 ) {
case V_143 :
case V_144 : V_10 += V_145 ; break;
case V_146 :
if ( V_10 <= 0xf )
V_10 += V_147 ;
else
V_10 += V_148 - 0x10 ;
break;
case V_149 :
if ( V_10 <= 0xf )
V_10 += V_150 ;
else
V_10 += V_148 - 0x10 ;
break;
default:
switch ( V_24 -> V_151 ) {
case V_143 :
case V_144 : V_10 += V_145 ; break;
case V_146 : V_10 += V_147 ; break;
case V_149 : V_10 += V_150 ; break;
default: V_10 += V_152 ;
}
}
F_37 ( V_10 ) ;
break;
case V_153 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0xba : F_38 ( V_154 ) ; break;
case 0xbb : F_38 ( V_155 ) ; break;
case 0xc4 : F_38 ( V_156 ) ; break;
case 0xc5 : F_38 ( V_157 ) ; break;
case 0xc8 : F_38 ( V_60 ) ; break;
default: goto V_129;
}
break;
case V_158 :
if ( ( V_2 -> V_5 & 0xf0 ) == 0x80 ) {
switch ( V_2 -> V_5 & 0xf ) {
case 0x1 : F_36 ( V_159 ) ; break;
case 0x2 : F_36 ( V_160 ) ; break;
case 0x3 : F_36 ( V_161 ) ; break;
case 0x4 : F_36 ( V_162 ) ; break;
case 0x5 : F_36 ( V_163 ) ; break;
case 0x6 : F_36 ( V_164 ) ; break;
case 0x7 : F_36 ( V_165 ) ; break;
case 0x8 : F_36 ( V_166 ) ; break;
case 0x9 : F_36 ( V_167 ) ; break;
case 0xa : F_36 ( V_168 ) ; break;
case 0xb : F_36 ( V_169 ) ; break;
case 0xc : F_36 ( V_170 ) ; break;
case 0xd : F_36 ( V_171 ) ; break;
case 0xe : F_36 ( V_172 ) ; break;
case 0xf : F_36 ( V_173 ) ; break;
default: goto V_174;
}
break;
}
if ( V_24 -> V_142 == V_175 )
goto V_129;
if ( ( V_2 -> V_5 & 0xf0 ) == 0x90 ) {
switch ( V_2 -> V_5 ) {
case V_176 : V_2 -> V_177 = 1 ; break;
case V_178 : V_2 -> V_177 = 5 ; break;
case V_179 : V_2 -> V_177 = 3 ; break;
case V_180 : V_2 -> V_177 = 7 ; break;
default: goto V_174;
}
if ( V_24 -> V_181 ) {
F_38 ( V_24 -> V_181 ) ;
goto V_129;
}
F_38 ( V_182 ) ;
break;
}
switch ( V_2 -> V_5 ) {
case V_183 : case V_184 : case V_185 :
case V_186 : case V_187 : case V_188 :
if ( V_24 -> V_29 & V_189 )
F_39 ( V_2 -> V_5 & 0xf ) ;
else
F_40 ( V_2 -> V_5 & 0xf ) ;
break;
case V_190 : case V_191 : case V_192 :
if ( V_24 -> V_29 & V_189 )
F_39 ( V_2 -> V_5 & 0xf ) ;
else
F_38 ( V_2 -> V_5 & 0xf ) ;
break;
case V_193 :
V_2 -> V_194 = V_24 -> V_42 ;
V_2 -> V_195 = V_24 -> V_41 ;
F_38 ( V_182 ) ;
break;
case V_196 : F_36 ( V_197 ) ; break;
case V_198 : F_36 ( V_199 ) ; break;
default: goto V_174;
}
break;
case V_131 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0x01 : F_41 ( V_200 ) ; break;
case 0x02 : F_41 ( V_201 ) ; break;
case 0x03 : F_41 ( V_202 ) ; break;
case 0x04 : F_41 ( V_203 ) ; break;
case 0x05 : F_41 ( V_204 ) ; break;
case 0x27 : F_41 ( V_205 ) ; break;
case 0x4c : F_41 ( V_206 ) ; break;
case 0x09 : F_41 ( V_207 ) ; break;
case 0x4b : F_41 ( V_208 ) ; break;
case 0x19 : F_41 ( V_209 ) ; break;
case 0x4d : F_41 ( V_210 ) ; break;
default: goto V_129;
}
break;
case V_211 :
switch ( V_2 -> V_5 & 0xff ) {
case 0x00 :
goto V_129;
case 0x30 :
if ( ! F_42 ( V_212 , V_125 -> V_37 ) ) {
V_126 -> V_64 |= V_213 ;
F_12 ( V_9 , V_125 -> V_138 ) ;
F_12 ( V_212 , V_125 -> V_37 ) ;
}
F_40 ( V_214 ) ;
break;
case 0x32 :
switch ( V_24 -> V_151 & 0xff ) {
case 0x21 : F_37 ( V_215 ) ; break;
case 0x22 : F_37 ( V_216 ) ; break;
default: F_37 ( V_217 ) ; break;
}
break;
case 0x3c :
F_36 ( V_218 ) ;
break;
case 0x3d :
F_40 ( V_61 ) ;
break;
case 0x3e :
F_40 ( V_62 ) ;
break;
case 0x33 :
case 0x42 :
case 0x43 :
V_126 -> V_64 &= ~ V_213 ;
F_36 ( V_212 ) ;
break;
case 0x44 :
F_36 ( V_219 ) ;
break;
case 0x46 :
case 0x5a :
F_36 ( V_220 ) ;
break;
case 0x5b :
V_2 -> type = V_221 ;
V_2 -> V_10 = V_222 ;
V_127 = V_125 -> V_223 ;
V_102 = V_224 ;
break;
default: goto V_174;
}
break;
case V_225 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x2f : F_36 ( V_226 ) ; break;
case 0xb0 : F_36 ( V_227 ) ; break;
case 0xb1 : F_36 ( V_228 ) ; break;
case 0xb2 : F_36 ( V_229 ) ; break;
case 0xb3 : F_36 ( V_230 ) ; break;
case 0xb4 : F_36 ( V_231 ) ; break;
case 0xb5 : F_36 ( V_232 ) ; break;
case 0xb6 : F_36 ( V_233 ) ; break;
case 0xb7 : F_36 ( V_234 ) ; break;
case 0xb8 : F_36 ( V_235 ) ; break;
case 0xb9 : F_36 ( V_236 ) ; break;
case 0xba : F_36 ( V_237 ) ; break;
case 0xbb : F_36 ( V_238 ) ; break;
case 0xbc : F_36 ( V_239 ) ; break;
case 0xbd : F_36 ( V_240 ) ; break;
case 0xbe : F_36 ( V_241 ) ; break;
case 0xbf : F_36 ( V_242 ) ; break;
default: goto V_129;
}
break;
case V_243 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x000 : goto V_129;
case 0x030 : F_36 ( V_159 ) ; break;
case 0x031 : F_36 ( V_173 ) ; break;
case 0x032 : F_36 ( V_160 ) ; break;
case 0x034 : F_36 ( V_160 ) ; break;
case 0x035 : F_36 ( V_244 ) ; break;
case 0x036 : F_36 ( V_152 ) ; break;
case 0x040 : F_36 ( V_163 ) ; break;
case 0x041 : F_36 ( V_167 ) ; break;
case 0x042 : F_36 ( V_170 ) ; break;
case 0x043 : F_36 ( V_171 ) ; break;
case 0x044 : F_36 ( V_169 ) ; break;
case 0x045 : F_36 ( V_168 ) ; break;
case 0x046 : F_36 ( V_245 ) ; break;
case 0x047 : F_36 ( V_246 ) ; break;
case 0x048 : F_36 ( V_247 ) ; break;
case 0x060 : F_36 ( V_248 ) ; break;
case 0x061 : F_36 ( V_249 ) ; break;
case 0x063 : F_36 ( V_250 ) ; break;
case 0x065 : F_36 ( V_251 ) ; break;
case 0x069 : F_36 ( V_252 ) ; break;
case 0x06a : F_36 ( V_253 ) ; break;
case 0x06b : F_36 ( V_254 ) ; break;
case 0x06c : F_36 ( V_255 ) ; break;
case 0x06d : F_36 ( V_256 ) ; break;
case 0x06f : F_36 ( V_257 ) ; break;
case 0x070 : F_36 ( V_258 ) ; break;
case 0x072 : F_36 ( V_259 ) ; break;
case 0x073 : F_36 ( V_260 ) ; break;
case 0x074 : F_36 ( V_261 ) ; break;
case 0x075 : F_36 ( V_262 ) ; break;
case 0x082 : F_36 ( V_263 ) ; break;
case 0x083 : F_36 ( V_264 ) ; break;
case 0x084 : F_36 ( V_265 ) ; break;
case 0x088 : F_36 ( V_266 ) ; break;
case 0x089 : F_36 ( V_267 ) ; break;
case 0x08a : F_36 ( V_268 ) ; break;
case 0x08b : F_36 ( V_269 ) ; break;
case 0x08c : F_36 ( V_270 ) ; break;
case 0x08d : F_36 ( V_271 ) ; break;
case 0x08e : F_36 ( V_272 ) ; break;
case 0x08f : F_36 ( V_273 ) ; break;
case 0x090 : F_36 ( V_274 ) ; break;
case 0x091 : F_36 ( V_275 ) ; break;
case 0x092 : F_36 ( V_250 ) ; break;
case 0x093 : F_36 ( V_276 ) ; break;
case 0x094 : F_36 ( V_166 ) ; break;
case 0x095 : F_36 ( V_165 ) ; break;
case 0x096 : F_36 ( V_277 ) ; break;
case 0x097 : F_36 ( V_278 ) ; break;
case 0x098 : F_36 ( V_279 ) ; break;
case 0x09a : F_36 ( V_280 ) ; break;
case 0x09c : F_36 ( V_281 ) ; break;
case 0x09d : F_36 ( V_282 ) ; break;
case 0x0a0 : F_36 ( V_283 ) ; break;
case 0x0b0 : F_36 ( V_284 ) ; break;
case 0x0b1 : F_36 ( V_285 ) ; break;
case 0x0b2 : F_36 ( V_286 ) ; break;
case 0x0b3 : F_36 ( V_287 ) ; break;
case 0x0b4 : F_36 ( V_288 ) ; break;
case 0x0b5 : F_36 ( V_289 ) ; break;
case 0x0b6 : F_36 ( V_290 ) ; break;
case 0x0b7 : F_36 ( V_291 ) ; break;
case 0x0b8 : F_36 ( V_292 ) ; break;
case 0x0bc : F_36 ( V_293 ) ; break;
case 0x0b9 : F_36 ( V_294 ) ; break;
case 0x0bf : F_36 ( V_295 ) ; break;
case 0x0cd : F_36 ( V_296 ) ; break;
case 0x0cf : F_36 ( V_297 ) ; break;
case 0x0e0 : F_40 ( V_298 ) ; break;
case 0x0e2 : F_36 ( V_299 ) ; break;
case 0x0e5 : F_36 ( V_300 ) ; break;
case 0x0e9 : F_36 ( V_301 ) ; break;
case 0x0ea : F_36 ( V_302 ) ; break;
case 0x0f5 : F_36 ( V_295 ) ; break;
case 0x181 : F_36 ( V_303 ) ; break;
case 0x182 : F_36 ( V_304 ) ; break;
case 0x183 : F_36 ( V_305 ) ; break;
case 0x184 : F_36 ( V_306 ) ; break;
case 0x185 : F_36 ( V_307 ) ; break;
case 0x186 : F_36 ( V_308 ) ; break;
case 0x187 : F_36 ( V_309 ) ; break;
case 0x188 : F_36 ( V_310 ) ; break;
case 0x189 : F_36 ( V_311 ) ; break;
case 0x18a : F_36 ( V_312 ) ; break;
case 0x18b : F_36 ( V_313 ) ; break;
case 0x18c : F_36 ( V_314 ) ; break;
case 0x18d : F_36 ( V_315 ) ; break;
case 0x18e : F_36 ( V_316 ) ; break;
case 0x18f : F_36 ( V_317 ) ; break;
case 0x190 : F_36 ( V_318 ) ; break;
case 0x191 : F_36 ( V_319 ) ; break;
case 0x192 : F_36 ( V_320 ) ; break;
case 0x193 : F_36 ( V_321 ) ; break;
case 0x194 : F_36 ( V_322 ) ; break;
case 0x196 : F_36 ( V_268 ) ; break;
case 0x199 : F_36 ( V_323 ) ; break;
case 0x19c : F_36 ( V_324 ) ; break;
case 0x19e : F_36 ( V_325 ) ; break;
case 0x19f : F_36 ( V_326 ) ; break;
case 0x1a2 : F_36 ( V_327 ) ; break;
case 0x1a3 : F_36 ( V_328 ) ; break;
case 0x1a4 : F_36 ( V_329 ) ; break;
case 0x1a6 : F_36 ( V_165 ) ; break;
case 0x1a7 : F_36 ( V_330 ) ; break;
case 0x1ab : F_36 ( V_331 ) ; break;
case 0x1ae : F_36 ( V_332 ) ; break;
case 0x1b1 : F_36 ( V_333 ) ; break;
case 0x1b4 : F_36 ( V_322 ) ; break;
case 0x1b6 : F_36 ( V_334 ) ; break;
case 0x1b7 : F_36 ( V_335 ) ; break;
case 0x1b8 : F_36 ( V_336 ) ; break;
case 0x1bc : F_36 ( V_337 ) ; break;
case 0x1bd : F_36 ( V_248 ) ; break;
case 0x201 : F_36 ( V_338 ) ; break;
case 0x202 : F_36 ( V_339 ) ; break;
case 0x203 : F_36 ( V_340 ) ; break;
case 0x204 : F_36 ( V_166 ) ; break;
case 0x207 : F_36 ( V_341 ) ; break;
case 0x208 : F_36 ( V_342 ) ; break;
case 0x209 : F_36 ( V_343 ) ; break;
case 0x21a : F_36 ( V_344 ) ; break;
case 0x21b : F_36 ( V_345 ) ; break;
case 0x21c : F_36 ( V_346 ) ; break;
case 0x21d : F_36 ( V_347 ) ; break;
case 0x21f : F_36 ( V_348 ) ; break;
case 0x221 : F_36 ( V_349 ) ; break;
case 0x222 : F_36 ( V_350 ) ; break;
case 0x223 : F_36 ( V_351 ) ; break;
case 0x224 : F_36 ( V_352 ) ; break;
case 0x225 : F_36 ( V_353 ) ; break;
case 0x226 : F_36 ( V_354 ) ; break;
case 0x227 : F_36 ( V_355 ) ; break;
case 0x22a : F_36 ( V_304 ) ; break;
case 0x22d : F_36 ( V_356 ) ; break;
case 0x22e : F_36 ( V_357 ) ; break;
case 0x22f : F_36 ( V_358 ) ; break;
case 0x233 : F_36 ( V_359 ) ; break;
case 0x234 : F_36 ( V_360 ) ; break;
case 0x238 : F_39 ( V_361 ) ; break;
case 0x23d : F_36 ( V_362 ) ; break;
case 0x25f : F_36 ( V_363 ) ; break;
case 0x269 : F_36 ( V_364 ) ; break;
case 0x26a : F_36 ( V_365 ) ; break;
case 0x279 : F_36 ( V_366 ) ; break;
case 0x289 : F_36 ( V_367 ) ; break;
case 0x28b : F_36 ( V_368 ) ; break;
case 0x28c : F_36 ( V_369 ) ; break;
case 0x2c7 : F_36 ( V_370 ) ; break;
case 0x2c8 : F_36 ( V_371 ) ; break;
case 0x2c9 : F_36 ( V_372 ) ; break;
case 0x2ca : F_36 ( V_373 ) ; break;
case 0x2cb : F_36 ( V_374 ) ; break;
case 0x2cc : F_36 ( V_375 ) ; break;
default: F_36 ( V_140 ) ;
}
break;
case V_376 :
if ( F_23 ( V_126 , V_21 , V_24 ) )
goto V_129;
else
goto V_174;
break;
case V_377 :
F_12 ( V_137 , V_125 -> V_138 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x021 : F_36 ( V_342 ) ; break;
case 0x070 : F_36 ( V_378 ) ; break;
case 0x071 : F_36 ( V_251 ) ; break;
case 0x072 : F_36 ( V_379 ) ; break;
case 0x073 : F_36 ( V_380 ) ; break;
case 0x080 : F_36 ( V_381 ) ; break;
case 0x081 : F_36 ( V_323 ) ; break;
case 0x082 : F_36 ( V_349 ) ; break;
case 0x083 : F_36 ( V_382 ) ; break;
case 0x084 : F_36 ( V_319 ) ; break;
case 0x085 : F_36 ( V_383 ) ; break;
case 0x086 : F_36 ( V_384 ) ; break;
default: goto V_129;
}
break;
case V_385 :
F_12 ( V_137 , V_125 -> V_138 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x001 : F_36 ( V_226 ) ; break;
case 0x003 : F_36 ( V_258 ) ; break;
case 0x004 : F_36 ( V_257 ) ; break;
default: goto V_129;
}
break;
case V_386 :
goto V_129;
case V_387 :
F_12 ( V_137 , V_125 -> V_138 ) ;
goto V_129;
case V_388 :
case V_389 :
case V_390 :
goto V_129;
case V_391 :
switch ( V_2 -> V_5 & V_7 ) {
case 0xa4 : F_36 ( V_392 ) ; break;
default: goto V_129;
}
break;
default:
V_174:
if ( V_24 -> V_393 == 1 ) {
if ( V_24 -> V_20 -> type == V_22 ) {
F_41 ( V_208 ) ;
break;
}
F_37 ( V_152 ) ;
break;
}
if ( V_24 -> V_29 & V_189 ) {
F_39 ( V_394 ) ;
break;
}
F_38 ( V_395 ) ;
break;
}
V_134:
if ( V_126 -> V_132 -> V_396 && V_126 -> V_132 -> V_396 ( V_126 ,
V_124 , V_24 , V_2 , & V_127 , & V_102 ) < 0 )
goto V_129;
F_12 ( V_2 -> type , V_125 -> V_138 ) ;
while ( V_2 -> V_10 <= V_102 && F_43 ( V_2 -> V_10 , V_127 ) )
V_2 -> V_10 = F_44 ( V_127 , V_102 + 1 , V_2 -> V_10 ) ;
if ( V_2 -> V_10 > V_102 )
goto V_129;
if ( V_2 -> type == V_397 ) {
int V_398 = V_24 -> V_42 ;
int V_399 = V_24 -> V_41 ;
if ( ( V_126 -> V_64 & V_400 ) && ( V_2 -> V_10 == V_47 || V_2 -> V_10 == V_48 ) ) {
V_398 = V_24 -> V_42 = 0 ;
V_399 = V_24 -> V_41 = 255 ;
}
if ( V_24 -> V_142 == V_149 || V_24 -> V_142 == V_146 )
F_45 ( V_125 , V_2 -> V_10 , V_398 , V_399 , ( V_399 - V_398 ) >> 8 , ( V_399 - V_398 ) >> 4 ) ;
else F_45 ( V_125 , V_2 -> V_10 , V_398 , V_399 , 0 , 0 ) ;
F_46 ( V_125 , V_2 -> V_10 ,
F_14 ( V_24 , V_2 -> V_10 ) ) ;
if ( V_2 -> V_10 == V_50 && V_125 -> V_401 == 0 )
F_47 ( V_125 , 60 ) ;
}
if ( V_2 -> type == V_397 &&
( V_2 -> V_194 < V_2 -> V_195 || V_2 -> V_177 ) ) {
int V_16 ;
for ( V_16 = V_2 -> V_10 ; V_16 < V_2 -> V_10 + 2 && V_16 <= V_102 ; V_16 ++ ) {
F_45 ( V_125 , V_16 , - 1 , 1 , 0 , 0 ) ;
F_12 ( V_16 , V_125 -> V_402 ) ;
}
if ( V_2 -> V_177 && ! V_24 -> V_181 )
V_24 -> V_181 = V_2 -> V_10 ;
}
if ( ( V_2 -> type == V_397 ) && ( V_24 -> V_29 & V_189 ) &&
( V_2 -> V_10 == V_298 ) ) {
F_12 ( V_301 , V_125 -> V_37 ) ;
F_12 ( V_302 , V_125 -> V_37 ) ;
}
if ( V_2 -> type == V_9 ) {
F_12 ( V_221 , V_125 -> V_138 ) ;
F_12 ( V_403 , V_125 -> V_223 ) ;
}
V_129:
return;
}
void F_48 ( struct V_12 * V_5 , struct V_38 * V_24 , struct V_1 * V_2 , T_2 V_14 )
{
struct V_31 * V_125 ;
unsigned * V_64 = & V_5 -> V_64 ;
if ( ! V_24 -> V_124 )
return;
V_125 = V_24 -> V_124 -> V_125 ;
if ( ! V_2 -> type )
return;
if ( V_2 -> V_194 < V_2 -> V_195 || V_2 -> V_177 ) {
int V_177 = V_2 -> V_177 ;
if ( ! V_177 )
V_177 = ( V_14 - V_2 -> V_194 ) * 8 / ( V_2 -> V_195 - V_2 -> V_194 + 1 ) + 1 ;
if ( V_177 < 0 || V_177 > 8 ) V_177 = 0 ;
F_49 ( V_125 , V_2 -> type , V_2 -> V_10 , V_404 [ V_177 ] . V_405 ) ;
F_49 ( V_125 , V_2 -> type , V_2 -> V_10 + 1 , V_404 [ V_177 ] . V_406 ) ;
return;
}
if ( V_2 -> V_5 == ( V_211 | 0x003c ) ) {
* V_64 = V_14 ? ( * V_64 | V_407 ) : ( * V_64 & ~ V_407 ) ;
return;
}
if ( V_2 -> V_5 == ( V_211 | 0x0032 ) ) {
if ( V_14 ) {
F_49 ( V_125 , V_2 -> type , ( * V_64 & V_407 ) ? V_218 : V_2 -> V_10 , 1 ) ;
return;
}
F_49 ( V_125 , V_2 -> type , V_2 -> V_10 , 0 ) ;
F_49 ( V_125 , V_2 -> type , V_218 , 0 ) ;
return;
}
if ( V_2 -> V_5 == ( V_211 | 0x0030 ) && ( * V_64 & V_213 ) ) {
int V_398 = V_24 -> V_42 ;
int V_399 = V_24 -> V_41 ;
F_49 ( V_125 , V_9 , V_212 , V_14 > V_398 + ( ( V_399 - V_398 ) >> 3 ) ) ;
}
if ( V_2 -> V_5 == ( V_391 | 0x83UL ) ) {
F_13 ( L_5 , V_14 ) ;
return;
}
if ( V_2 -> V_5 == ( V_391 | 0x7fUL ) ) {
F_13 ( L_6 ) ;
return;
}
if ( ( V_2 -> type == V_9 ) && ( V_2 -> V_10 == 0 ) )
return;
if ( ( V_2 -> type == V_397 ) && ( V_24 -> V_29 & V_189 ) &&
( V_2 -> V_10 == V_298 ) ) {
int V_408 = abs ( V_14 ) ;
int V_409 = V_14 > 0 ? V_301 : V_302 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_408 ; V_16 ++ ) {
F_49 ( V_125 , V_9 , V_409 , 1 ) ;
F_50 ( V_125 ) ;
F_49 ( V_125 , V_9 , V_409 , 0 ) ;
F_50 ( V_125 ) ;
}
return;
}
if ( ( V_24 -> V_29 & V_410 ) &&
( V_24 -> V_42 < V_24 -> V_41 ) &&
( V_14 < V_24 -> V_42 ||
V_14 > V_24 -> V_41 ) ) {
F_13 ( L_7 , V_14 ) ;
return;
}
if ( ! ( V_24 -> V_29 & ( V_189 |
V_411 ) ) &&
( V_24 -> V_29 & V_410 ) &&
V_2 -> V_412 < V_24 -> V_25 &&
V_14 == V_24 -> V_14 [ V_2 -> V_412 ] )
return;
if ( V_2 -> type == V_9 &&
( ! F_42 ( V_2 -> V_10 , V_125 -> V_413 ) ) == V_14 )
F_49 ( V_125 , V_221 , V_403 , V_2 -> V_5 ) ;
F_49 ( V_125 , V_2 -> type , V_2 -> V_10 , V_14 ) ;
if ( ( V_24 -> V_29 & V_189 ) &&
V_2 -> type == V_9 && V_14 ) {
F_50 ( V_125 ) ;
F_49 ( V_125 , V_2 -> type , V_2 -> V_10 , 0 ) ;
}
}
void F_51 ( struct V_12 * V_5 , struct V_19 * V_20 )
{
struct V_123 * V_124 ;
if ( V_5 -> V_64 & V_414 )
return;
F_5 (hidinput, &hid->inputs, list)
F_50 ( V_124 -> V_125 ) ;
}
int F_52 ( struct V_12 * V_5 , unsigned int type , unsigned int V_10 , struct V_38 * * V_24 )
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
struct V_38 * F_53 ( struct V_12 * V_5 )
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
if ( V_24 -> V_2 [ V_17 ] . type == V_415 )
return V_24 ;
}
}
return NULL ;
}
unsigned int F_54 ( struct V_12 * V_5 )
{
struct V_19 * V_20 ;
struct V_38 * V_24 ;
int V_16 , V_17 ;
unsigned int V_408 = 0 ;
F_5 (report,
&hid->report_enum[HID_OUTPUT_REPORT].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ ) {
V_24 = V_20 -> V_24 [ V_16 ] ;
for ( V_17 = 0 ; V_17 < V_24 -> V_25 ; V_17 ++ )
if ( V_24 -> V_2 [ V_17 ] . type == V_415 &&
V_24 -> V_14 [ V_17 ] )
V_408 += 1 ;
}
}
return V_408 ;
}
static void F_55 ( struct V_416 * V_417 )
{
struct V_12 * V_5 = F_56 ( V_417 , struct V_12 ,
V_418 ) ;
struct V_38 * V_24 ;
struct V_19 * V_20 ;
int V_34 , V_74 ;
T_4 * V_75 ;
V_24 = F_53 ( V_5 ) ;
if ( ! V_24 )
return;
V_20 = V_24 -> V_20 ;
if ( V_5 -> V_419 -> V_420 )
return V_5 -> V_419 -> V_420 ( V_5 , V_20 , V_421 ) ;
V_34 = F_57 ( V_20 ) ;
V_75 = F_58 ( V_20 , V_80 ) ;
if ( ! V_75 )
return;
F_59 ( V_20 , V_75 ) ;
V_74 = F_60 ( V_5 , V_75 , V_34 ) ;
if ( V_74 == - V_422 )
F_21 ( V_5 , V_20 -> V_121 , V_75 , V_34 , V_22 ,
V_421 ) ;
F_22 ( V_75 ) ;
}
static int F_61 ( struct V_31 * V_32 , unsigned int type ,
unsigned int V_10 , int V_14 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
struct V_38 * V_24 ;
int V_423 ;
if ( type == V_424 )
return F_62 ( V_32 , type , V_10 , V_14 ) ;
if ( type != V_415 )
return - 1 ;
if ( ( V_423 = F_52 ( V_5 , type , V_10 , & V_24 ) ) == - 1 ) {
F_30 ( V_32 , L_8 ) ;
return - 1 ;
}
F_63 ( V_24 , V_423 , V_14 ) ;
F_64 ( & V_5 -> V_418 ) ;
return 0 ;
}
static int F_65 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
return F_66 ( V_5 ) ;
}
static void F_67 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
F_68 ( V_5 ) ;
}
static void F_69 ( struct V_12 * V_5 )
{
struct V_425 * V_426 = V_5 -> V_132 ;
struct V_427 * V_428 ;
struct V_19 * V_429 ;
int V_16 , V_17 ;
V_428 = & V_5 -> V_430 [ V_120 ] ;
F_5 (rep, &rep_enum->report_list, list)
for ( V_16 = 0 ; V_16 < V_429 -> V_23 ; V_16 ++ ) {
if ( V_429 -> V_24 [ V_16 ] -> V_130 < 1 )
continue;
for ( V_17 = 0 ; V_17 < V_429 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ ) {
F_23 ( V_5 , V_120 , V_429 -> V_24 [ V_16 ] ) ;
if ( V_426 -> V_431 )
V_426 -> V_431 ( V_5 , V_429 -> V_24 [ V_16 ] ,
V_429 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
}
}
}
static struct V_123 * F_70 ( struct V_12 * V_5 )
{
struct V_123 * V_124 = F_25 ( sizeof( * V_124 ) , V_80 ) ;
struct V_31 * V_31 = F_71 () ;
if ( ! V_124 || ! V_31 ) {
F_22 ( V_124 ) ;
F_72 ( V_31 ) ;
F_73 ( V_5 , L_9 ) ;
return NULL ;
}
F_74 ( V_31 , V_5 ) ;
V_31 -> V_432 = F_61 ;
V_31 -> V_433 = F_65 ;
V_31 -> V_434 = F_67 ;
V_31 -> V_435 = F_10 ;
V_31 -> V_436 = F_8 ;
V_31 -> V_90 = V_5 -> V_90 ;
V_31 -> V_437 = V_5 -> V_437 ;
V_31 -> V_111 = V_5 -> V_111 ;
V_31 -> V_121 . V_438 = V_5 -> V_106 ;
V_31 -> V_121 . V_107 = V_5 -> V_107 ;
V_31 -> V_121 . V_108 = V_5 -> V_108 ;
V_31 -> V_121 . V_109 = V_5 -> V_109 ;
V_31 -> V_32 . V_439 = & V_5 -> V_32 ;
V_124 -> V_125 = V_31 ;
F_75 ( & V_124 -> V_440 , & V_5 -> V_441 ) ;
return V_124 ;
}
static bool F_76 ( struct V_123 * V_124 )
{
int V_16 ;
unsigned long V_442 = 0 ;
for ( V_16 = 0 ; V_16 < F_77 ( V_443 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_138 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_444 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_37 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_445 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_446 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_447 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_402 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_448 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_223 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_449 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_450 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_451 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_452 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_453 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_454 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_455 ) ; V_16 ++ )
V_442 |= V_124 -> V_125 -> V_456 [ V_16 ] ;
return ! ! V_442 ;
}
static void F_78 ( struct V_12 * V_5 ,
struct V_123 * V_124 )
{
struct V_19 * V_20 ;
int V_16 , V_18 ;
F_79 ( & V_124 -> V_440 ) ;
F_72 ( V_124 -> V_125 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_64 & V_457 )
continue;
F_5 (report, &hid->report_enum[k].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
if ( V_20 -> V_24 [ V_16 ] -> V_124 == V_124 )
V_20 -> V_24 [ V_16 ] -> V_124 = NULL ;
}
}
F_22 ( V_124 ) ;
}
static struct V_123 * F_80 ( struct V_19 * V_20 )
{
struct V_12 * V_5 = V_20 -> V_126 ;
struct V_123 * V_124 ;
F_5 (hidinput, &hid->inputs, list) {
if ( V_124 -> V_20 &&
V_124 -> V_20 -> V_121 == V_20 -> V_121 )
return V_124 ;
}
return NULL ;
}
static inline void F_81 ( struct V_123 * V_124 ,
struct V_19 * V_20 )
{
int V_16 , V_17 ;
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_20 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ )
F_35 ( V_124 , V_20 -> V_24 [ V_16 ] ,
V_20 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
}
int F_82 ( struct V_12 * V_5 , unsigned int V_458 )
{
struct V_425 * V_426 = V_5 -> V_132 ;
struct V_19 * V_20 ;
struct V_123 * V_459 , * V_124 = NULL ;
int V_16 , V_18 ;
F_83 ( & V_5 -> V_441 ) ;
F_84 ( & V_5 -> V_418 , F_55 ) ;
if ( ! V_458 ) {
for ( V_16 = 0 ; V_16 < V_5 -> V_460 ; V_16 ++ ) {
struct V_461 * V_462 = & V_5 -> V_463 [ V_16 ] ;
if ( V_462 -> type == V_464 ||
V_462 -> type == V_465 )
if ( F_85 ( V_462 -> V_2 ) )
break;
}
if ( V_16 == V_5 -> V_460 )
return - 1 ;
}
F_69 ( V_5 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_64 & V_457 )
continue;
F_5 (report, &hid->report_enum[k].report_list, list) {
if ( ! V_20 -> V_23 )
continue;
if ( V_5 -> V_64 & V_466 )
V_124 = F_80 ( V_20 ) ;
if ( ! V_124 ) {
V_124 = F_70 ( V_5 ) ;
if ( ! V_124 )
goto V_467;
}
F_81 ( V_124 , V_20 ) ;
if ( V_5 -> V_64 & V_466 )
V_124 -> V_20 = V_20 ;
}
}
F_86 (hidinput, next, &hid->inputs, list) {
if ( ( V_5 -> V_64 & V_468 ) &&
! F_76 ( V_124 ) ) {
F_78 ( V_5 , V_124 ) ;
continue;
}
if ( V_426 -> V_469 &&
V_426 -> V_469 ( V_5 , V_124 ) )
goto V_467;
if ( F_87 ( V_124 -> V_125 ) )
goto V_467;
V_124 -> V_470 = true ;
}
if ( F_88 ( & V_5 -> V_441 ) ) {
F_73 ( V_5 , L_10 ) ;
goto V_467;
}
return 0 ;
V_467:
F_89 ( V_5 ) ;
return - 1 ;
}
void F_89 ( struct V_12 * V_5 )
{
struct V_123 * V_124 , * V_459 ;
F_33 ( V_5 ) ;
F_86 (hidinput, next, &hid->inputs, list) {
F_79 ( & V_124 -> V_440 ) ;
if ( V_124 -> V_470 )
F_90 ( V_124 -> V_125 ) ;
else
F_72 ( V_124 -> V_125 ) ;
F_22 ( V_124 ) ;
}
F_91 ( & V_5 -> V_418 ) ;
}
