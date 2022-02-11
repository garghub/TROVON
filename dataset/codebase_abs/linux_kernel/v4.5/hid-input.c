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
static unsigned F_16 ( struct V_12 * V_62 )
{
unsigned V_63 = 0 ;
const struct V_64 * V_13 ;
V_13 = F_17 ( V_62 , V_65 ) ;
if ( V_13 != NULL )
V_63 = V_13 -> V_66 ;
return V_63 ;
}
static int F_18 ( struct V_67 * V_68 ,
enum V_69 V_70 ,
union V_71 * V_72 )
{
struct V_12 * V_32 = F_19 ( V_68 ) ;
int V_73 = 0 ;
T_4 * V_74 ;
switch ( V_70 ) {
case V_75 :
case V_76 :
V_72 -> V_77 = 1 ;
break;
case V_78 :
V_74 = F_20 ( 2 * sizeof( T_4 ) , V_79 ) ;
if ( ! V_74 ) {
V_73 = - V_80 ;
break;
}
V_73 = F_21 ( V_32 , V_32 -> V_81 , V_74 , 2 ,
V_32 -> V_82 ,
V_83 ) ;
if ( V_73 != 2 ) {
V_73 = - V_84 ;
F_22 ( V_74 ) ;
break;
}
V_73 = 0 ;
if ( V_32 -> V_85 < V_32 -> V_86 &&
V_74 [ 1 ] >= V_32 -> V_85 &&
V_74 [ 1 ] <= V_32 -> V_86 )
V_72 -> V_77 = ( 100 * ( V_74 [ 1 ] - V_32 -> V_85 ) ) /
( V_32 -> V_86 - V_32 -> V_85 ) ;
F_22 ( V_74 ) ;
break;
case V_87 :
V_72 -> V_88 = V_32 -> V_89 ;
break;
case V_90 :
V_72 -> V_77 = V_91 ;
break;
case V_92 :
V_72 -> V_77 = V_93 ;
break;
default:
V_73 = - V_35 ;
break;
}
return V_73 ;
}
static bool F_23 ( struct V_12 * V_32 , unsigned V_94 , struct V_38 * V_24 )
{
struct V_95 * V_96 = NULL ;
struct V_97 V_98 = { . V_99 = V_32 , } ;
unsigned V_63 ;
T_5 V_100 , V_101 ;
if ( V_24 -> V_2 -> V_5 != V_102 )
return false ;
if ( V_32 -> V_103 != NULL )
goto V_104;
V_63 = F_16 ( V_32 ) ;
F_24 ( V_32 , L_2 ,
V_32 -> V_105 , V_32 -> V_106 , V_32 -> V_107 , V_32 -> V_108 , V_63 ) ;
if ( V_63 & V_109 )
goto V_104;
V_96 = F_25 ( sizeof( * V_96 ) , V_79 ) ;
if ( V_96 == NULL )
goto V_104;
V_96 -> V_89 = F_26 ( V_79 , L_3 , V_32 -> V_110 ) ;
if ( V_96 -> V_89 == NULL ) {
F_22 ( V_96 ) ;
goto V_104;
}
V_96 -> type = V_111 ;
V_96 -> V_112 = V_113 ;
V_96 -> V_114 = F_27 ( V_113 ) ;
V_96 -> V_115 = 0 ;
V_96 -> V_116 = F_18 ;
V_100 = V_24 -> V_42 ;
V_101 = V_24 -> V_41 ;
if ( V_63 & V_117 ) {
V_100 = 0 ;
V_101 = 100 ;
}
if ( V_63 & V_118 )
V_94 = V_119 ;
V_32 -> V_85 = V_100 ;
V_32 -> V_86 = V_101 ;
V_32 -> V_82 = V_94 ;
V_32 -> V_81 = V_24 -> V_20 -> V_120 ;
V_32 -> V_103 = F_28 ( & V_32 -> V_32 , V_96 , & V_98 ) ;
if ( F_29 ( V_32 -> V_103 ) ) {
F_30 ( V_32 , L_4 ,
F_31 ( V_32 -> V_103 ) ) ;
F_22 ( V_96 -> V_89 ) ;
F_22 ( V_96 ) ;
V_32 -> V_103 = NULL ;
} else {
F_32 ( V_32 -> V_103 , & V_32 -> V_32 ) ;
}
V_104:
return true ;
}
static void F_33 ( struct V_12 * V_32 )
{
const struct V_95 * V_96 ;
if ( ! V_32 -> V_103 )
return;
V_96 = V_32 -> V_103 -> V_121 ;
F_34 ( V_32 -> V_103 ) ;
F_22 ( V_96 -> V_89 ) ;
F_22 ( V_96 ) ;
V_32 -> V_103 = NULL ;
}
static bool F_23 ( struct V_12 * V_32 , unsigned V_94 ,
struct V_38 * V_24 )
{
return false ;
}
static void F_33 ( struct V_12 * V_32 )
{
}
static void F_35 ( struct V_122 * V_123 , struct V_38 * V_24 ,
struct V_1 * V_2 )
{
struct V_31 * V_124 = V_123 -> V_124 ;
struct V_12 * V_125 = F_9 ( V_124 ) ;
int V_101 = 0 , V_10 ;
unsigned long * V_126 = NULL ;
V_24 -> V_123 = V_123 ;
if ( V_24 -> V_29 & V_127 )
goto V_128;
if ( V_24 -> V_129 < 1 )
goto V_128;
if ( V_24 -> V_94 == V_22 &&
( V_2 -> V_5 & V_6 ) != V_130 ) {
goto V_128;
}
if ( V_125 -> V_131 -> V_132 ) {
int V_73 = V_125 -> V_131 -> V_132 ( V_125 , V_123 , V_24 ,
V_2 , & V_126 , & V_101 ) ;
if ( V_73 > 0 )
goto V_133;
if ( V_73 < 0 )
goto V_128;
}
switch ( V_2 -> V_5 & V_6 ) {
case V_134 :
goto V_128;
case V_135 :
F_12 ( V_136 , V_124 -> V_137 ) ;
if ( ( V_2 -> V_5 & V_7 ) < 256 ) {
if ( ! V_138 [ V_2 -> V_5 & V_7 ] ) goto V_128;
F_36 ( V_138 [ V_2 -> V_5 & V_7 ] ) ;
} else
F_37 ( V_139 ) ;
break;
case V_140 :
V_10 = ( ( V_2 -> V_5 - 1 ) & V_7 ) ;
switch ( V_24 -> V_141 ) {
case V_142 :
case V_143 : V_10 += V_144 ; break;
case V_145 :
if ( V_10 <= 0xf )
V_10 += V_146 ;
else
V_10 += V_147 - 0x10 ;
break;
case V_148 :
if ( V_10 <= 0xf )
V_10 += V_149 ;
else
V_10 += V_147 - 0x10 ;
break;
default:
switch ( V_24 -> V_150 ) {
case V_142 :
case V_143 : V_10 += V_144 ; break;
case V_145 : V_10 += V_146 ; break;
case V_148 : V_10 += V_149 ; break;
default: V_10 += V_151 ;
}
}
F_37 ( V_10 ) ;
break;
case V_152 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0xba : F_38 ( V_153 ) ; break;
case 0xbb : F_38 ( V_154 ) ; break;
case 0xc4 : F_38 ( V_155 ) ; break;
case 0xc5 : F_38 ( V_156 ) ; break;
case 0xc8 : F_38 ( V_157 ) ; break;
default: goto V_128;
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
if ( ( V_2 -> V_5 & 0xf0 ) == 0x90 ) {
switch ( V_2 -> V_5 ) {
case V_175 : V_2 -> V_176 = 1 ; break;
case V_177 : V_2 -> V_176 = 5 ; break;
case V_178 : V_2 -> V_176 = 3 ; break;
case V_179 : V_2 -> V_176 = 7 ; break;
default: goto V_174;
}
if ( V_24 -> V_180 ) {
F_38 ( V_24 -> V_180 ) ;
goto V_128;
}
F_38 ( V_181 ) ;
break;
}
switch ( V_2 -> V_5 ) {
case V_182 : case V_183 : case V_184 :
case V_185 : case V_186 : case V_187 :
if ( V_24 -> V_29 & V_188 )
F_39 ( V_2 -> V_5 & 0xf ) ;
else
F_40 ( V_2 -> V_5 & 0xf ) ;
break;
case V_189 : case V_190 : case V_191 :
if ( V_24 -> V_29 & V_188 )
F_39 ( V_2 -> V_5 & 0xf ) ;
else
F_38 ( V_2 -> V_5 & 0xf ) ;
break;
case V_192 :
V_2 -> V_193 = V_24 -> V_42 ;
V_2 -> V_194 = V_24 -> V_41 ;
F_38 ( V_181 ) ;
break;
case V_195 : F_36 ( V_196 ) ; break;
case V_197 : F_36 ( V_198 ) ; break;
default: goto V_174;
}
break;
case V_130 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0x01 : F_41 ( V_199 ) ; break;
case 0x02 : F_41 ( V_200 ) ; break;
case 0x03 : F_41 ( V_201 ) ; break;
case 0x04 : F_41 ( V_202 ) ; break;
case 0x05 : F_41 ( V_203 ) ; break;
case 0x27 : F_41 ( V_204 ) ; break;
case 0x4c : F_41 ( V_205 ) ; break;
case 0x09 : F_41 ( V_206 ) ; break;
case 0x4b : F_41 ( V_207 ) ; break;
case 0x19 : F_41 ( V_208 ) ; break;
case 0x4d : F_41 ( V_209 ) ; break;
default: goto V_128;
}
break;
case V_210 :
switch ( V_2 -> V_5 & 0xff ) {
case 0x00 :
goto V_128;
case 0x30 :
if ( ! F_42 ( V_211 , V_124 -> V_37 ) ) {
V_125 -> V_63 |= V_212 ;
F_12 ( V_9 , V_124 -> V_137 ) ;
F_12 ( V_211 , V_124 -> V_37 ) ;
}
F_40 ( V_213 ) ;
break;
case 0x32 :
switch ( V_24 -> V_150 & 0xff ) {
case 0x21 : F_37 ( V_214 ) ; break;
case 0x22 : F_37 ( V_215 ) ; break;
default: F_37 ( V_216 ) ; break;
}
break;
case 0x3c :
F_36 ( V_217 ) ;
break;
case 0x3d :
F_40 ( V_60 ) ;
break;
case 0x3e :
F_40 ( V_61 ) ;
break;
case 0x33 :
case 0x42 :
case 0x43 :
V_125 -> V_63 &= ~ V_212 ;
F_36 ( V_211 ) ;
break;
case 0x44 :
F_36 ( V_218 ) ;
break;
case 0x46 :
case 0x5a :
F_36 ( V_219 ) ;
break;
case 0x5b :
V_2 -> type = V_220 ;
V_2 -> V_10 = V_221 ;
V_126 = V_124 -> V_222 ;
V_101 = V_223 ;
break;
default: goto V_174;
}
break;
case V_224 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x2f : F_36 ( V_225 ) ; break;
case 0xb0 : F_36 ( V_226 ) ; break;
case 0xb1 : F_36 ( V_227 ) ; break;
case 0xb2 : F_36 ( V_228 ) ; break;
case 0xb3 : F_36 ( V_229 ) ; break;
case 0xb4 : F_36 ( V_230 ) ; break;
case 0xb5 : F_36 ( V_231 ) ; break;
case 0xb6 : F_36 ( V_232 ) ; break;
case 0xb7 : F_36 ( V_233 ) ; break;
case 0xb8 : F_36 ( V_234 ) ; break;
case 0xb9 : F_36 ( V_235 ) ; break;
case 0xba : F_36 ( V_236 ) ; break;
case 0xbb : F_36 ( V_237 ) ; break;
case 0xbc : F_36 ( V_238 ) ; break;
case 0xbd : F_36 ( V_239 ) ; break;
case 0xbe : F_36 ( V_240 ) ; break;
case 0xbf : F_36 ( V_241 ) ; break;
default: goto V_128;
}
break;
case V_242 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x000 : goto V_128;
case 0x030 : F_36 ( V_159 ) ; break;
case 0x031 : F_36 ( V_173 ) ; break;
case 0x032 : F_36 ( V_160 ) ; break;
case 0x034 : F_36 ( V_160 ) ; break;
case 0x035 : F_36 ( V_243 ) ; break;
case 0x036 : F_36 ( V_151 ) ; break;
case 0x040 : F_36 ( V_163 ) ; break;
case 0x041 : F_36 ( V_167 ) ; break;
case 0x042 : F_36 ( V_170 ) ; break;
case 0x043 : F_36 ( V_171 ) ; break;
case 0x044 : F_36 ( V_169 ) ; break;
case 0x045 : F_36 ( V_168 ) ; break;
case 0x046 : F_36 ( V_244 ) ; break;
case 0x047 : F_36 ( V_245 ) ; break;
case 0x048 : F_36 ( V_246 ) ; break;
case 0x060 : F_36 ( V_247 ) ; break;
case 0x061 : F_36 ( V_248 ) ; break;
case 0x063 : F_36 ( V_249 ) ; break;
case 0x065 : F_36 ( V_250 ) ; break;
case 0x069 : F_36 ( V_251 ) ; break;
case 0x06a : F_36 ( V_252 ) ; break;
case 0x06b : F_36 ( V_253 ) ; break;
case 0x06c : F_36 ( V_254 ) ; break;
case 0x06d : F_36 ( V_255 ) ; break;
case 0x06f : F_36 ( V_256 ) ; break;
case 0x070 : F_36 ( V_257 ) ; break;
case 0x072 : F_36 ( V_258 ) ; break;
case 0x073 : F_36 ( V_259 ) ; break;
case 0x074 : F_36 ( V_260 ) ; break;
case 0x075 : F_36 ( V_261 ) ; break;
case 0x082 : F_36 ( V_262 ) ; break;
case 0x083 : F_36 ( V_263 ) ; break;
case 0x084 : F_36 ( V_264 ) ; break;
case 0x088 : F_36 ( V_265 ) ; break;
case 0x089 : F_36 ( V_266 ) ; break;
case 0x08a : F_36 ( V_267 ) ; break;
case 0x08b : F_36 ( V_268 ) ; break;
case 0x08c : F_36 ( V_269 ) ; break;
case 0x08d : F_36 ( V_270 ) ; break;
case 0x08e : F_36 ( V_271 ) ; break;
case 0x08f : F_36 ( V_272 ) ; break;
case 0x090 : F_36 ( V_273 ) ; break;
case 0x091 : F_36 ( V_274 ) ; break;
case 0x092 : F_36 ( V_249 ) ; break;
case 0x093 : F_36 ( V_275 ) ; break;
case 0x094 : F_36 ( V_166 ) ; break;
case 0x095 : F_36 ( V_165 ) ; break;
case 0x096 : F_36 ( V_276 ) ; break;
case 0x097 : F_36 ( V_277 ) ; break;
case 0x098 : F_36 ( V_278 ) ; break;
case 0x09a : F_36 ( V_279 ) ; break;
case 0x09c : F_36 ( V_280 ) ; break;
case 0x09d : F_36 ( V_281 ) ; break;
case 0x0a0 : F_36 ( V_282 ) ; break;
case 0x0b0 : F_36 ( V_283 ) ; break;
case 0x0b1 : F_36 ( V_284 ) ; break;
case 0x0b2 : F_36 ( V_285 ) ; break;
case 0x0b3 : F_36 ( V_286 ) ; break;
case 0x0b4 : F_36 ( V_287 ) ; break;
case 0x0b5 : F_36 ( V_288 ) ; break;
case 0x0b6 : F_36 ( V_289 ) ; break;
case 0x0b7 : F_36 ( V_290 ) ; break;
case 0x0b8 : F_36 ( V_291 ) ; break;
case 0x0bc : F_36 ( V_292 ) ; break;
case 0x0b9 : F_36 ( V_293 ) ; break;
case 0x0bf : F_36 ( V_294 ) ; break;
case 0x0cd : F_36 ( V_295 ) ; break;
case 0x0cf : F_36 ( V_296 ) ; break;
case 0x0e0 : F_40 ( V_297 ) ; break;
case 0x0e2 : F_36 ( V_298 ) ; break;
case 0x0e5 : F_36 ( V_299 ) ; break;
case 0x0e9 : F_36 ( V_300 ) ; break;
case 0x0ea : F_36 ( V_301 ) ; break;
case 0x0f5 : F_36 ( V_294 ) ; break;
case 0x181 : F_36 ( V_302 ) ; break;
case 0x182 : F_36 ( V_303 ) ; break;
case 0x183 : F_36 ( V_304 ) ; break;
case 0x184 : F_36 ( V_305 ) ; break;
case 0x185 : F_36 ( V_306 ) ; break;
case 0x186 : F_36 ( V_307 ) ; break;
case 0x187 : F_36 ( V_308 ) ; break;
case 0x188 : F_36 ( V_309 ) ; break;
case 0x189 : F_36 ( V_310 ) ; break;
case 0x18a : F_36 ( V_311 ) ; break;
case 0x18b : F_36 ( V_312 ) ; break;
case 0x18c : F_36 ( V_313 ) ; break;
case 0x18d : F_36 ( V_314 ) ; break;
case 0x18e : F_36 ( V_315 ) ; break;
case 0x18f : F_36 ( V_316 ) ; break;
case 0x190 : F_36 ( V_317 ) ; break;
case 0x191 : F_36 ( V_318 ) ; break;
case 0x192 : F_36 ( V_319 ) ; break;
case 0x193 : F_36 ( V_320 ) ; break;
case 0x194 : F_36 ( V_321 ) ; break;
case 0x196 : F_36 ( V_267 ) ; break;
case 0x199 : F_36 ( V_322 ) ; break;
case 0x19c : F_36 ( V_323 ) ; break;
case 0x19e : F_36 ( V_324 ) ; break;
case 0x19f : F_36 ( V_325 ) ; break;
case 0x1a2 : F_36 ( V_326 ) ; break;
case 0x1a3 : F_36 ( V_327 ) ; break;
case 0x1a4 : F_36 ( V_328 ) ; break;
case 0x1a6 : F_36 ( V_165 ) ; break;
case 0x1a7 : F_36 ( V_329 ) ; break;
case 0x1ab : F_36 ( V_330 ) ; break;
case 0x1ae : F_36 ( V_331 ) ; break;
case 0x1b1 : F_36 ( V_332 ) ; break;
case 0x1b4 : F_36 ( V_321 ) ; break;
case 0x1b6 : F_36 ( V_333 ) ; break;
case 0x1b7 : F_36 ( V_334 ) ; break;
case 0x1b8 : F_36 ( V_335 ) ; break;
case 0x1bc : F_36 ( V_336 ) ; break;
case 0x1bd : F_36 ( V_247 ) ; break;
case 0x201 : F_36 ( V_337 ) ; break;
case 0x202 : F_36 ( V_338 ) ; break;
case 0x203 : F_36 ( V_339 ) ; break;
case 0x204 : F_36 ( V_166 ) ; break;
case 0x207 : F_36 ( V_340 ) ; break;
case 0x208 : F_36 ( V_341 ) ; break;
case 0x209 : F_36 ( V_342 ) ; break;
case 0x21a : F_36 ( V_343 ) ; break;
case 0x21b : F_36 ( V_344 ) ; break;
case 0x21c : F_36 ( V_345 ) ; break;
case 0x21d : F_36 ( V_346 ) ; break;
case 0x21f : F_36 ( V_347 ) ; break;
case 0x221 : F_36 ( V_348 ) ; break;
case 0x222 : F_36 ( V_349 ) ; break;
case 0x223 : F_36 ( V_350 ) ; break;
case 0x224 : F_36 ( V_351 ) ; break;
case 0x225 : F_36 ( V_352 ) ; break;
case 0x226 : F_36 ( V_353 ) ; break;
case 0x227 : F_36 ( V_354 ) ; break;
case 0x22a : F_36 ( V_303 ) ; break;
case 0x22d : F_36 ( V_355 ) ; break;
case 0x22e : F_36 ( V_356 ) ; break;
case 0x22f : F_36 ( V_357 ) ; break;
case 0x233 : F_36 ( V_358 ) ; break;
case 0x234 : F_36 ( V_359 ) ; break;
case 0x238 : F_39 ( V_360 ) ; break;
case 0x23d : F_36 ( V_361 ) ; break;
case 0x25f : F_36 ( V_362 ) ; break;
case 0x269 : F_36 ( V_363 ) ; break;
case 0x26a : F_36 ( V_364 ) ; break;
case 0x279 : F_36 ( V_365 ) ; break;
case 0x289 : F_36 ( V_366 ) ; break;
case 0x28b : F_36 ( V_367 ) ; break;
case 0x28c : F_36 ( V_368 ) ; break;
case 0x2c7 : F_36 ( V_369 ) ; break;
case 0x2c8 : F_36 ( V_370 ) ; break;
case 0x2c9 : F_36 ( V_371 ) ; break;
case 0x2ca : F_36 ( V_372 ) ; break;
case 0x2cb : F_36 ( V_373 ) ; break;
case 0x2cc : F_36 ( V_374 ) ; break;
default: F_36 ( V_139 ) ;
}
break;
case V_375 :
if ( F_23 ( V_125 , V_21 , V_24 ) )
goto V_128;
else
goto V_174;
break;
case V_376 :
F_12 ( V_136 , V_124 -> V_137 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x021 : F_36 ( V_341 ) ; break;
case 0x070 : F_36 ( V_377 ) ; break;
case 0x071 : F_36 ( V_250 ) ; break;
case 0x072 : F_36 ( V_378 ) ; break;
case 0x073 : F_36 ( V_379 ) ; break;
case 0x080 : F_36 ( V_380 ) ; break;
case 0x081 : F_36 ( V_322 ) ; break;
case 0x082 : F_36 ( V_348 ) ; break;
case 0x083 : F_36 ( V_381 ) ; break;
case 0x084 : F_36 ( V_318 ) ; break;
case 0x085 : F_36 ( V_382 ) ; break;
case 0x086 : F_36 ( V_383 ) ; break;
default: goto V_128;
}
break;
case V_384 :
F_12 ( V_136 , V_124 -> V_137 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x003 : F_36 ( V_257 ) ; break;
case 0x004 : F_36 ( V_256 ) ; break;
default: goto V_128;
}
break;
case V_385 :
goto V_128;
case V_386 :
F_12 ( V_136 , V_124 -> V_137 ) ;
goto V_128;
case V_387 :
case V_388 :
case V_389 :
goto V_128;
case V_390 :
switch ( V_2 -> V_5 & V_7 ) {
case 0xa4 : F_36 ( V_391 ) ; break;
default: goto V_128;
}
break;
default:
V_174:
if ( V_24 -> V_392 == 1 ) {
if ( V_24 -> V_20 -> type == V_22 ) {
F_41 ( V_207 ) ;
break;
}
F_37 ( V_151 ) ;
break;
}
if ( V_24 -> V_29 & V_188 ) {
F_39 ( V_393 ) ;
break;
}
F_38 ( V_394 ) ;
break;
}
V_133:
if ( V_125 -> V_131 -> V_395 && V_125 -> V_131 -> V_395 ( V_125 ,
V_123 , V_24 , V_2 , & V_126 , & V_101 ) < 0 )
goto V_128;
F_12 ( V_2 -> type , V_124 -> V_137 ) ;
while ( V_2 -> V_10 <= V_101 && F_43 ( V_2 -> V_10 , V_126 ) )
V_2 -> V_10 = F_44 ( V_126 , V_101 + 1 , V_2 -> V_10 ) ;
if ( V_2 -> V_10 > V_101 )
goto V_128;
if ( V_2 -> type == V_396 ) {
int V_397 = V_24 -> V_42 ;
int V_398 = V_24 -> V_41 ;
if ( ( V_125 -> V_63 & V_399 ) && ( V_2 -> V_10 == V_47 || V_2 -> V_10 == V_48 ) ) {
V_397 = V_24 -> V_42 = 0 ;
V_398 = V_24 -> V_41 = 255 ;
}
if ( V_24 -> V_141 == V_148 || V_24 -> V_141 == V_145 )
F_45 ( V_124 , V_2 -> V_10 , V_397 , V_398 , ( V_398 - V_397 ) >> 8 , ( V_398 - V_397 ) >> 4 ) ;
else F_45 ( V_124 , V_2 -> V_10 , V_397 , V_398 , 0 , 0 ) ;
F_46 ( V_124 , V_2 -> V_10 ,
F_14 ( V_24 , V_2 -> V_10 ) ) ;
if ( V_2 -> V_10 == V_50 && V_124 -> V_400 == 0 )
F_47 ( V_124 , 60 ) ;
}
if ( V_2 -> type == V_396 &&
( V_2 -> V_193 < V_2 -> V_194 || V_2 -> V_176 ) ) {
int V_16 ;
for ( V_16 = V_2 -> V_10 ; V_16 < V_2 -> V_10 + 2 && V_16 <= V_101 ; V_16 ++ ) {
F_45 ( V_124 , V_16 , - 1 , 1 , 0 , 0 ) ;
F_12 ( V_16 , V_124 -> V_401 ) ;
}
if ( V_2 -> V_176 && ! V_24 -> V_180 )
V_24 -> V_180 = V_2 -> V_10 ;
}
if ( ( V_2 -> type == V_396 ) && ( V_24 -> V_29 & V_188 ) &&
( V_2 -> V_10 == V_297 ) ) {
F_12 ( V_300 , V_124 -> V_37 ) ;
F_12 ( V_301 , V_124 -> V_37 ) ;
}
if ( V_2 -> type == V_9 ) {
F_12 ( V_220 , V_124 -> V_137 ) ;
F_12 ( V_402 , V_124 -> V_222 ) ;
}
V_128:
return;
}
void F_48 ( struct V_12 * V_5 , struct V_38 * V_24 , struct V_1 * V_2 , T_2 V_14 )
{
struct V_31 * V_124 ;
unsigned * V_63 = & V_5 -> V_63 ;
if ( ! V_24 -> V_123 )
return;
V_124 = V_24 -> V_123 -> V_124 ;
if ( ! V_2 -> type )
return;
if ( V_2 -> V_193 < V_2 -> V_194 || V_2 -> V_176 ) {
int V_176 = V_2 -> V_176 ;
if ( ! V_176 )
V_176 = ( V_14 - V_2 -> V_193 ) * 8 / ( V_2 -> V_194 - V_2 -> V_193 + 1 ) + 1 ;
if ( V_176 < 0 || V_176 > 8 ) V_176 = 0 ;
F_49 ( V_124 , V_2 -> type , V_2 -> V_10 , V_403 [ V_176 ] . V_404 ) ;
F_49 ( V_124 , V_2 -> type , V_2 -> V_10 + 1 , V_403 [ V_176 ] . V_405 ) ;
return;
}
if ( V_2 -> V_5 == ( V_210 | 0x003c ) ) {
* V_63 = V_14 ? ( * V_63 | V_406 ) : ( * V_63 & ~ V_406 ) ;
return;
}
if ( V_2 -> V_5 == ( V_210 | 0x0032 ) ) {
if ( V_14 ) {
F_49 ( V_124 , V_2 -> type , ( * V_63 & V_406 ) ? V_217 : V_2 -> V_10 , 1 ) ;
return;
}
F_49 ( V_124 , V_2 -> type , V_2 -> V_10 , 0 ) ;
F_49 ( V_124 , V_2 -> type , V_217 , 0 ) ;
return;
}
if ( V_2 -> V_5 == ( V_210 | 0x0030 ) && ( * V_63 & V_212 ) ) {
int V_397 = V_24 -> V_42 ;
int V_398 = V_24 -> V_41 ;
F_49 ( V_124 , V_9 , V_211 , V_14 > V_397 + ( ( V_398 - V_397 ) >> 3 ) ) ;
}
if ( V_2 -> V_5 == ( V_390 | 0x83UL ) ) {
F_13 ( L_5 , V_14 ) ;
return;
}
if ( V_2 -> V_5 == ( V_390 | 0x7fUL ) ) {
F_13 ( L_6 ) ;
return;
}
if ( ( V_2 -> type == V_9 ) && ( V_2 -> V_10 == 0 ) )
return;
if ( ( V_2 -> type == V_396 ) && ( V_24 -> V_29 & V_188 ) &&
( V_2 -> V_10 == V_297 ) ) {
int V_407 = abs ( V_14 ) ;
int V_408 = V_14 > 0 ? V_300 : V_301 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_407 ; V_16 ++ ) {
F_49 ( V_124 , V_9 , V_408 , 1 ) ;
F_50 ( V_124 ) ;
F_49 ( V_124 , V_9 , V_408 , 0 ) ;
F_50 ( V_124 ) ;
}
return;
}
if ( ( V_24 -> V_29 & V_409 ) &&
( V_24 -> V_42 < V_24 -> V_41 ) &&
( V_14 < V_24 -> V_42 ||
V_14 > V_24 -> V_41 ) ) {
F_13 ( L_7 , V_14 ) ;
return;
}
if ( ! ( V_24 -> V_29 & ( V_188 |
V_410 ) ) &&
( V_24 -> V_29 & V_409 ) &&
V_2 -> V_411 < V_24 -> V_25 &&
V_14 == V_24 -> V_14 [ V_2 -> V_411 ] )
return;
if ( V_2 -> type == V_9 &&
( ! F_42 ( V_2 -> V_10 , V_124 -> V_412 ) ) == V_14 )
F_49 ( V_124 , V_220 , V_402 , V_2 -> V_5 ) ;
F_49 ( V_124 , V_2 -> type , V_2 -> V_10 , V_14 ) ;
if ( ( V_24 -> V_29 & V_188 ) &&
V_2 -> type == V_9 && V_14 ) {
F_50 ( V_124 ) ;
F_49 ( V_124 , V_2 -> type , V_2 -> V_10 , 0 ) ;
}
}
void F_51 ( struct V_12 * V_5 , struct V_19 * V_20 )
{
struct V_122 * V_123 ;
if ( V_5 -> V_63 & V_413 )
return;
F_5 (hidinput, &hid->inputs, list)
F_50 ( V_123 -> V_124 ) ;
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
if ( V_24 -> V_2 [ V_17 ] . type == V_414 )
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
unsigned int V_407 = 0 ;
F_5 (report,
&hid->report_enum[HID_OUTPUT_REPORT].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ ) {
V_24 = V_20 -> V_24 [ V_16 ] ;
for ( V_17 = 0 ; V_17 < V_24 -> V_25 ; V_17 ++ )
if ( V_24 -> V_2 [ V_17 ] . type == V_414 &&
V_24 -> V_14 [ V_17 ] )
V_407 += 1 ;
}
}
return V_407 ;
}
static void F_55 ( struct V_415 * V_416 )
{
struct V_12 * V_5 = F_56 ( V_416 , struct V_12 ,
V_417 ) ;
struct V_38 * V_24 ;
struct V_19 * V_20 ;
int V_34 , V_73 ;
T_4 * V_74 ;
V_24 = F_53 ( V_5 ) ;
if ( ! V_24 )
return;
V_20 = V_24 -> V_20 ;
if ( V_5 -> V_418 -> V_419 )
return V_5 -> V_418 -> V_419 ( V_5 , V_20 , V_420 ) ;
V_34 = F_57 ( V_20 ) ;
V_74 = F_58 ( V_20 , V_79 ) ;
if ( ! V_74 )
return;
F_59 ( V_20 , V_74 ) ;
V_73 = F_60 ( V_5 , V_74 , V_34 ) ;
if ( V_73 == - V_421 )
F_21 ( V_5 , V_20 -> V_120 , V_74 , V_34 , V_22 ,
V_420 ) ;
F_22 ( V_74 ) ;
}
static int F_61 ( struct V_31 * V_32 , unsigned int type ,
unsigned int V_10 , int V_14 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
struct V_38 * V_24 ;
int V_422 ;
if ( type == V_423 )
return F_62 ( V_32 , type , V_10 , V_14 ) ;
if ( type != V_414 )
return - 1 ;
if ( ( V_422 = F_52 ( V_5 , type , V_10 , & V_24 ) ) == - 1 ) {
F_30 ( V_32 , L_8 ) ;
return - 1 ;
}
F_63 ( V_24 , V_422 , V_14 ) ;
F_64 ( & V_5 -> V_417 ) ;
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
struct V_424 * V_425 = V_5 -> V_131 ;
struct V_426 * V_427 ;
struct V_19 * V_428 ;
int V_16 , V_17 ;
V_427 = & V_5 -> V_429 [ V_119 ] ;
F_5 (rep, &rep_enum->report_list, list)
for ( V_16 = 0 ; V_16 < V_428 -> V_23 ; V_16 ++ ) {
if ( V_428 -> V_24 [ V_16 ] -> V_129 < 1 )
continue;
for ( V_17 = 0 ; V_17 < V_428 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ ) {
F_23 ( V_5 , V_119 , V_428 -> V_24 [ V_16 ] ) ;
if ( V_425 -> V_430 )
V_425 -> V_430 ( V_5 , V_428 -> V_24 [ V_16 ] ,
V_428 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
}
}
}
static struct V_122 * F_70 ( struct V_12 * V_5 )
{
struct V_122 * V_123 = F_25 ( sizeof( * V_123 ) , V_79 ) ;
struct V_31 * V_31 = F_71 () ;
if ( ! V_123 || ! V_31 ) {
F_22 ( V_123 ) ;
F_72 ( V_31 ) ;
F_73 ( V_5 , L_9 ) ;
return NULL ;
}
F_74 ( V_31 , V_5 ) ;
V_31 -> V_431 = F_61 ;
V_31 -> V_432 = F_65 ;
V_31 -> V_433 = F_67 ;
V_31 -> V_434 = F_10 ;
V_31 -> V_435 = F_8 ;
V_31 -> V_89 = V_5 -> V_89 ;
V_31 -> V_436 = V_5 -> V_436 ;
V_31 -> V_110 = V_5 -> V_110 ;
V_31 -> V_120 . V_437 = V_5 -> V_105 ;
V_31 -> V_120 . V_106 = V_5 -> V_106 ;
V_31 -> V_120 . V_107 = V_5 -> V_107 ;
V_31 -> V_120 . V_108 = V_5 -> V_108 ;
V_31 -> V_32 . V_438 = & V_5 -> V_32 ;
V_123 -> V_124 = V_31 ;
F_75 ( & V_123 -> V_439 , & V_5 -> V_440 ) ;
return V_123 ;
}
static bool F_76 ( struct V_122 * V_123 )
{
int V_16 ;
unsigned long V_441 = 0 ;
for ( V_16 = 0 ; V_16 < F_77 ( V_442 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_137 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_443 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_37 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_444 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_445 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_446 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_401 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_447 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_222 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_448 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_449 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_450 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_451 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_452 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_453 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_77 ( V_454 ) ; V_16 ++ )
V_441 |= V_123 -> V_124 -> V_455 [ V_16 ] ;
return ! ! V_441 ;
}
static void F_78 ( struct V_12 * V_5 ,
struct V_122 * V_123 )
{
struct V_19 * V_20 ;
int V_16 , V_18 ;
F_79 ( & V_123 -> V_439 ) ;
F_72 ( V_123 -> V_124 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_63 & V_456 )
continue;
F_5 (report, &hid->report_enum[k].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
if ( V_20 -> V_24 [ V_16 ] -> V_123 == V_123 )
V_20 -> V_24 [ V_16 ] -> V_123 = NULL ;
}
}
F_22 ( V_123 ) ;
}
int F_80 ( struct V_12 * V_5 , unsigned int V_457 )
{
struct V_424 * V_425 = V_5 -> V_131 ;
struct V_19 * V_20 ;
struct V_122 * V_123 = NULL ;
int V_16 , V_17 , V_18 ;
F_81 ( & V_5 -> V_440 ) ;
F_82 ( & V_5 -> V_417 , F_55 ) ;
if ( ! V_457 ) {
for ( V_16 = 0 ; V_16 < V_5 -> V_458 ; V_16 ++ ) {
struct V_459 * V_460 = & V_5 -> V_461 [ V_16 ] ;
if ( V_460 -> type == V_462 ||
V_460 -> type == V_463 )
if ( F_83 ( V_460 -> V_2 ) )
break;
}
if ( V_16 == V_5 -> V_458 )
return - 1 ;
}
F_69 ( V_5 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_63 & V_456 )
continue;
F_5 (report, &hid->report_enum[k].report_list, list) {
if ( ! V_20 -> V_23 )
continue;
if ( ! V_123 ) {
V_123 = F_70 ( V_5 ) ;
if ( ! V_123 )
goto V_464;
}
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_20 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ )
F_35 ( V_123 , V_20 -> V_24 [ V_16 ] ,
V_20 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
if ( ( V_5 -> V_63 & V_465 ) &&
! F_76 ( V_123 ) )
continue;
if ( V_5 -> V_63 & V_466 ) {
V_123 -> V_20 = V_20 ;
if ( V_425 -> V_467 &&
V_425 -> V_467 ( V_5 , V_123 ) )
goto V_468;
if ( F_84 ( V_123 -> V_124 ) )
goto V_468;
V_123 = NULL ;
}
}
}
if ( V_123 && ( V_5 -> V_63 & V_465 ) &&
! F_76 ( V_123 ) ) {
F_78 ( V_5 , V_123 ) ;
V_123 = NULL ;
}
if ( F_85 ( & V_5 -> V_440 ) ) {
F_73 ( V_5 , L_10 ) ;
goto V_464;
}
if ( V_123 ) {
if ( V_425 -> V_467 &&
V_425 -> V_467 ( V_5 , V_123 ) )
goto V_468;
if ( F_84 ( V_123 -> V_124 ) )
goto V_468;
}
return 0 ;
V_468:
F_79 ( & V_123 -> V_439 ) ;
F_72 ( V_123 -> V_124 ) ;
F_22 ( V_123 ) ;
V_464:
F_86 ( V_5 ) ;
return - 1 ;
}
void F_86 ( struct V_12 * V_5 )
{
struct V_122 * V_123 , * V_469 ;
F_33 ( V_5 ) ;
F_87 (hidinput, next, &hid->inputs, list) {
F_79 ( & V_123 -> V_439 ) ;
F_88 ( V_123 -> V_124 ) ;
F_22 ( V_123 ) ;
}
F_89 ( & V_5 -> V_417 ) ;
}
