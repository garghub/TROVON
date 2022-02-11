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
if ( V_24 -> V_56 & 0xffffff00 )
return 0 ;
V_39 += F_15 ( V_24 -> V_56 >> 4 , 4 ) - 1 ;
switch ( V_24 -> V_56 & 0xf ) {
case 0x1 :
V_39 += 1 ;
break;
case 0x3 :
V_46 = V_43 ;
V_43 *= 254 ;
if ( V_43 < V_46 )
return 0 ;
V_39 -= 1 ;
break;
default:
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
return F_16 ( V_40 , V_43 ) ;
}
static unsigned F_17 ( struct V_12 * V_62 )
{
unsigned V_63 = 0 ;
const struct V_64 * V_13 ;
V_13 = F_18 ( V_62 , V_65 ) ;
if ( V_13 != NULL )
V_63 = V_13 -> V_66 ;
return V_63 ;
}
static int F_19 ( struct V_67 * V_68 ,
enum V_69 V_70 ,
union V_71 * V_72 )
{
struct V_12 * V_32 = F_20 ( V_68 , struct V_12 , V_73 ) ;
int V_74 = 0 ;
T_4 V_75 [ 2 ] = {} ;
switch ( V_70 ) {
case V_76 :
case V_77 :
V_72 -> V_78 = 1 ;
break;
case V_79 :
V_74 = V_32 -> V_80 ( V_32 , V_32 -> V_81 ,
V_75 , sizeof( V_75 ) ,
V_32 -> V_82 ) ;
if ( V_74 != 2 ) {
V_74 = - V_83 ;
break;
}
V_74 = 0 ;
if ( V_32 -> V_84 < V_32 -> V_85 &&
V_75 [ 1 ] >= V_32 -> V_84 &&
V_75 [ 1 ] <= V_32 -> V_85 )
V_72 -> V_78 = ( 100 * ( V_75 [ 1 ] - V_32 -> V_84 ) ) /
( V_32 -> V_85 - V_32 -> V_84 ) ;
break;
case V_86 :
V_72 -> V_87 = V_32 -> V_88 ;
break;
case V_89 :
V_72 -> V_78 = V_90 ;
break;
case V_91 :
V_72 -> V_78 = V_92 ;
break;
default:
V_74 = - V_35 ;
break;
}
return V_74 ;
}
static bool F_21 ( struct V_12 * V_32 , unsigned V_93 , struct V_38 * V_24 )
{
struct V_67 * V_73 = & V_32 -> V_73 ;
int V_74 ;
unsigned V_63 ;
T_5 V_94 , V_95 ;
if ( V_24 -> V_2 -> V_5 != V_96 )
return false ;
if ( V_73 -> V_88 != NULL )
goto V_97;
V_73 -> V_88 = F_22 ( V_98 , L_2 , V_32 -> V_99 ) ;
if ( V_73 -> V_88 == NULL )
goto V_97;
V_73 -> type = V_100 ;
V_73 -> V_101 = V_102 ;
V_73 -> V_103 = F_23 ( V_102 ) ;
V_73 -> V_104 = 0 ;
V_73 -> V_105 = F_19 ;
V_63 = F_17 ( V_32 ) ;
F_24 ( V_32 , L_3 ,
V_32 -> V_106 , V_32 -> V_107 , V_32 -> V_108 , V_32 -> V_109 , V_63 ) ;
V_94 = V_24 -> V_42 ;
V_95 = V_24 -> V_41 ;
if ( V_63 & V_110 ) {
V_94 = 0 ;
V_95 = 100 ;
}
if ( V_63 & V_111 )
V_93 = V_112 ;
V_32 -> V_84 = V_94 ;
V_32 -> V_85 = V_95 ;
V_32 -> V_82 = V_93 ;
V_32 -> V_81 = V_24 -> V_20 -> V_113 ;
V_74 = F_25 ( & V_32 -> V_32 , V_73 ) ;
if ( V_74 != 0 ) {
F_26 ( V_32 , L_4 , V_74 ) ;
F_27 ( V_73 -> V_88 ) ;
V_73 -> V_88 = NULL ;
}
F_28 ( V_73 , & V_32 -> V_32 ) ;
V_97:
return true ;
}
static void F_29 ( struct V_12 * V_32 )
{
if ( ! V_32 -> V_73 . V_88 )
return;
F_30 ( & V_32 -> V_73 ) ;
F_27 ( V_32 -> V_73 . V_88 ) ;
V_32 -> V_73 . V_88 = NULL ;
}
static bool F_21 ( struct V_12 * V_32 , unsigned V_93 ,
struct V_38 * V_24 )
{
return false ;
}
static void F_29 ( struct V_12 * V_32 )
{
}
static void F_31 ( struct V_114 * V_115 , struct V_38 * V_24 ,
struct V_1 * V_2 )
{
struct V_31 * V_116 = V_115 -> V_116 ;
struct V_12 * V_117 = F_9 ( V_116 ) ;
int V_95 = 0 , V_10 ;
unsigned long * V_118 = NULL ;
V_24 -> V_115 = V_115 ;
if ( V_24 -> V_29 & V_119 )
goto V_120;
if ( V_24 -> V_93 == V_22 &&
( V_2 -> V_5 & V_6 ) != V_121 ) {
goto V_120;
}
if ( V_117 -> V_122 -> V_123 ) {
int V_74 = V_117 -> V_122 -> V_123 ( V_117 , V_115 , V_24 ,
V_2 , & V_118 , & V_95 ) ;
if ( V_74 > 0 )
goto V_124;
if ( V_74 < 0 )
goto V_120;
}
switch ( V_2 -> V_5 & V_6 ) {
case V_125 :
goto V_120;
case V_126 :
F_12 ( V_127 , V_116 -> V_128 ) ;
if ( ( V_2 -> V_5 & V_7 ) < 256 ) {
if ( ! V_129 [ V_2 -> V_5 & V_7 ] ) goto V_120;
F_32 ( V_129 [ V_2 -> V_5 & V_7 ] ) ;
} else
F_33 ( V_130 ) ;
break;
case V_131 :
V_10 = ( ( V_2 -> V_5 - 1 ) & V_7 ) ;
switch ( V_24 -> V_132 ) {
case V_133 :
case V_134 : V_10 += V_135 ; break;
case V_136 :
if ( V_10 <= 0xf )
V_10 += V_137 ;
else
V_10 += V_138 - 0x10 ;
break;
case V_139 :
if ( V_10 <= 0xf )
V_10 += V_140 ;
else
V_10 += V_138 - 0x10 ;
break;
default:
switch ( V_24 -> V_141 ) {
case V_133 :
case V_134 : V_10 += V_135 ; break;
case V_136 : V_10 += V_137 ; break;
case V_139 : V_10 += V_140 ; break;
default: V_10 += V_142 ;
}
}
F_33 ( V_10 ) ;
break;
case V_143 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0xba : F_34 ( V_144 ) ; break;
case 0xbb : F_34 ( V_145 ) ; break;
case 0xc4 : F_34 ( V_146 ) ; break;
case 0xc5 : F_34 ( V_147 ) ; break;
case 0xc8 : F_34 ( V_148 ) ; break;
default: goto V_120;
}
break;
case V_149 :
if ( ( V_2 -> V_5 & 0xf0 ) == 0x80 ) {
switch ( V_2 -> V_5 & 0xf ) {
case 0x1 : F_32 ( V_150 ) ; break;
case 0x2 : F_32 ( V_151 ) ; break;
case 0x3 : F_32 ( V_152 ) ; break;
case 0x4 : F_32 ( V_153 ) ; break;
case 0x5 : F_32 ( V_154 ) ; break;
case 0x6 : F_32 ( V_155 ) ; break;
case 0x7 : F_32 ( V_156 ) ; break;
case 0x8 : F_32 ( V_157 ) ; break;
case 0x9 : F_32 ( V_158 ) ; break;
case 0xa : F_32 ( V_159 ) ; break;
case 0xb : F_32 ( V_160 ) ; break;
case 0xc : F_32 ( V_161 ) ; break;
case 0xd : F_32 ( V_162 ) ; break;
case 0xe : F_32 ( V_163 ) ; break;
case 0xf : F_32 ( V_164 ) ; break;
default: goto V_165;
}
break;
}
if ( ( V_2 -> V_5 & 0xf0 ) == 0x90 ) {
switch ( V_2 -> V_5 ) {
case V_166 : V_2 -> V_167 = 1 ; break;
case V_168 : V_2 -> V_167 = 5 ; break;
case V_169 : V_2 -> V_167 = 3 ; break;
case V_170 : V_2 -> V_167 = 7 ; break;
default: goto V_165;
}
if ( V_24 -> V_171 ) {
F_34 ( V_24 -> V_171 ) ;
goto V_120;
}
F_34 ( V_172 ) ;
break;
}
switch ( V_2 -> V_5 ) {
case V_173 : case V_174 : case V_175 :
case V_176 : case V_177 : case V_178 :
case V_179 : case V_180 : case V_181 :
if ( V_24 -> V_29 & V_182 )
F_35 ( V_2 -> V_5 & 0xf ) ;
else
F_34 ( V_2 -> V_5 & 0xf ) ;
break;
case V_183 :
V_2 -> V_184 = V_24 -> V_42 ;
V_2 -> V_185 = V_24 -> V_41 ;
F_34 ( V_172 ) ;
break;
case V_186 : F_32 ( V_187 ) ; break;
case V_188 : F_32 ( V_189 ) ; break;
default: goto V_165;
}
break;
case V_121 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0x01 : F_36 ( V_190 ) ; break;
case 0x02 : F_36 ( V_191 ) ; break;
case 0x03 : F_36 ( V_192 ) ; break;
case 0x04 : F_36 ( V_193 ) ; break;
case 0x05 : F_36 ( V_194 ) ; break;
case 0x27 : F_36 ( V_195 ) ; break;
case 0x4c : F_36 ( V_196 ) ; break;
case 0x09 : F_36 ( V_197 ) ; break;
case 0x4b : F_36 ( V_198 ) ; break;
case 0x19 : F_36 ( V_199 ) ; break;
case 0x4d : F_36 ( V_200 ) ; break;
default: goto V_120;
}
break;
case V_201 :
switch ( V_2 -> V_5 & 0xff ) {
case 0x00 :
goto V_120;
case 0x30 :
if ( ! F_37 ( V_202 , V_116 -> V_37 ) ) {
V_117 -> V_63 |= V_203 ;
F_12 ( V_9 , V_116 -> V_128 ) ;
F_12 ( V_202 , V_116 -> V_37 ) ;
}
F_38 ( V_204 ) ;
break;
case 0x32 :
switch ( V_24 -> V_141 & 0xff ) {
case 0x21 : F_33 ( V_205 ) ; break;
case 0x22 : F_33 ( V_206 ) ; break;
default: F_33 ( V_207 ) ; break;
}
break;
case 0x3c :
F_32 ( V_208 ) ;
break;
case 0x3d :
F_38 ( V_60 ) ;
break;
case 0x3e :
F_38 ( V_61 ) ;
break;
case 0x33 :
case 0x42 :
case 0x43 :
V_117 -> V_63 &= ~ V_203 ;
F_32 ( V_202 ) ;
break;
case 0x44 :
F_32 ( V_209 ) ;
break;
case 0x46 :
F_32 ( V_210 ) ;
break;
default: goto V_165;
}
break;
case V_211 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x000 : goto V_120;
case 0x030 : F_32 ( V_150 ) ; break;
case 0x031 : F_32 ( V_164 ) ; break;
case 0x032 : F_32 ( V_151 ) ; break;
case 0x034 : F_32 ( V_151 ) ; break;
case 0x035 : F_32 ( V_212 ) ; break;
case 0x036 : F_32 ( V_142 ) ; break;
case 0x040 : F_32 ( V_154 ) ; break;
case 0x041 : F_32 ( V_158 ) ; break;
case 0x042 : F_32 ( V_161 ) ; break;
case 0x043 : F_32 ( V_162 ) ; break;
case 0x044 : F_32 ( V_160 ) ; break;
case 0x045 : F_32 ( V_159 ) ; break;
case 0x046 : F_32 ( V_213 ) ; break;
case 0x047 : F_32 ( V_214 ) ; break;
case 0x048 : F_32 ( V_215 ) ; break;
case 0x060 : F_32 ( V_216 ) ; break;
case 0x061 : F_32 ( V_217 ) ; break;
case 0x063 : F_32 ( V_218 ) ; break;
case 0x065 : F_32 ( V_219 ) ; break;
case 0x069 : F_32 ( V_220 ) ; break;
case 0x06a : F_32 ( V_221 ) ; break;
case 0x06b : F_32 ( V_222 ) ; break;
case 0x06c : F_32 ( V_223 ) ; break;
case 0x06d : F_32 ( V_224 ) ; break;
case 0x082 : F_32 ( V_225 ) ; break;
case 0x083 : F_32 ( V_226 ) ; break;
case 0x084 : F_32 ( V_227 ) ; break;
case 0x088 : F_32 ( V_228 ) ; break;
case 0x089 : F_32 ( V_229 ) ; break;
case 0x08a : F_32 ( V_230 ) ; break;
case 0x08b : F_32 ( V_231 ) ; break;
case 0x08c : F_32 ( V_232 ) ; break;
case 0x08d : F_32 ( V_233 ) ; break;
case 0x08e : F_32 ( V_234 ) ; break;
case 0x08f : F_32 ( V_235 ) ; break;
case 0x090 : F_32 ( V_236 ) ; break;
case 0x091 : F_32 ( V_237 ) ; break;
case 0x092 : F_32 ( V_218 ) ; break;
case 0x093 : F_32 ( V_238 ) ; break;
case 0x094 : F_32 ( V_157 ) ; break;
case 0x095 : F_32 ( V_156 ) ; break;
case 0x096 : F_32 ( V_239 ) ; break;
case 0x097 : F_32 ( V_240 ) ; break;
case 0x098 : F_32 ( V_241 ) ; break;
case 0x09a : F_32 ( V_242 ) ; break;
case 0x09c : F_32 ( V_243 ) ; break;
case 0x09d : F_32 ( V_244 ) ; break;
case 0x0a0 : F_32 ( V_245 ) ; break;
case 0x0b0 : F_32 ( V_246 ) ; break;
case 0x0b1 : F_32 ( V_247 ) ; break;
case 0x0b2 : F_32 ( V_248 ) ; break;
case 0x0b3 : F_32 ( V_249 ) ; break;
case 0x0b4 : F_32 ( V_250 ) ; break;
case 0x0b5 : F_32 ( V_251 ) ; break;
case 0x0b6 : F_32 ( V_252 ) ; break;
case 0x0b7 : F_32 ( V_253 ) ; break;
case 0x0b8 : F_32 ( V_254 ) ; break;
case 0x0bc : F_32 ( V_255 ) ; break;
case 0x0b9 : F_32 ( V_256 ) ; break;
case 0x0bf : F_32 ( V_257 ) ; break;
case 0x0cd : F_32 ( V_258 ) ; break;
case 0x0e0 : F_38 ( V_259 ) ; break;
case 0x0e2 : F_32 ( V_260 ) ; break;
case 0x0e5 : F_32 ( V_261 ) ; break;
case 0x0e9 : F_32 ( V_262 ) ; break;
case 0x0ea : F_32 ( V_263 ) ; break;
case 0x0f5 : F_32 ( V_257 ) ; break;
case 0x182 : F_32 ( V_264 ) ; break;
case 0x183 : F_32 ( V_265 ) ; break;
case 0x184 : F_32 ( V_266 ) ; break;
case 0x185 : F_32 ( V_267 ) ; break;
case 0x186 : F_32 ( V_268 ) ; break;
case 0x187 : F_32 ( V_269 ) ; break;
case 0x188 : F_32 ( V_270 ) ; break;
case 0x189 : F_32 ( V_271 ) ; break;
case 0x18a : F_32 ( V_272 ) ; break;
case 0x18b : F_32 ( V_273 ) ; break;
case 0x18c : F_32 ( V_274 ) ; break;
case 0x18d : F_32 ( V_275 ) ; break;
case 0x18e : F_32 ( V_276 ) ; break;
case 0x191 : F_32 ( V_277 ) ; break;
case 0x192 : F_32 ( V_278 ) ; break;
case 0x193 : F_32 ( V_279 ) ; break;
case 0x194 : F_32 ( V_280 ) ; break;
case 0x196 : F_32 ( V_230 ) ; break;
case 0x199 : F_32 ( V_281 ) ; break;
case 0x19c : F_32 ( V_282 ) ; break;
case 0x19e : F_32 ( V_283 ) ; break;
case 0x1a6 : F_32 ( V_156 ) ; break;
case 0x1a7 : F_32 ( V_284 ) ; break;
case 0x1ab : F_32 ( V_285 ) ; break;
case 0x1ae : F_32 ( V_286 ) ; break;
case 0x1b6 : F_32 ( V_287 ) ; break;
case 0x1b7 : F_32 ( V_288 ) ; break;
case 0x1b8 : F_32 ( V_289 ) ; break;
case 0x1bc : F_32 ( V_290 ) ; break;
case 0x1bd : F_32 ( V_216 ) ; break;
case 0x201 : F_32 ( V_291 ) ; break;
case 0x202 : F_32 ( V_292 ) ; break;
case 0x203 : F_32 ( V_293 ) ; break;
case 0x204 : F_32 ( V_157 ) ; break;
case 0x207 : F_32 ( V_294 ) ; break;
case 0x208 : F_32 ( V_295 ) ; break;
case 0x209 : F_32 ( V_296 ) ; break;
case 0x21a : F_32 ( V_297 ) ; break;
case 0x21b : F_32 ( V_298 ) ; break;
case 0x21c : F_32 ( V_299 ) ; break;
case 0x21d : F_32 ( V_300 ) ; break;
case 0x21f : F_32 ( V_301 ) ; break;
case 0x221 : F_32 ( V_302 ) ; break;
case 0x222 : F_32 ( V_303 ) ; break;
case 0x223 : F_32 ( V_304 ) ; break;
case 0x224 : F_32 ( V_305 ) ; break;
case 0x225 : F_32 ( V_306 ) ; break;
case 0x226 : F_32 ( V_307 ) ; break;
case 0x227 : F_32 ( V_308 ) ; break;
case 0x22a : F_32 ( V_264 ) ; break;
case 0x22d : F_32 ( V_309 ) ; break;
case 0x22e : F_32 ( V_310 ) ; break;
case 0x22f : F_32 ( V_311 ) ; break;
case 0x233 : F_32 ( V_312 ) ; break;
case 0x234 : F_32 ( V_313 ) ; break;
case 0x238 : F_35 ( V_314 ) ; break;
case 0x23d : F_32 ( V_315 ) ; break;
case 0x25f : F_32 ( V_316 ) ; break;
case 0x269 : F_32 ( V_317 ) ; break;
case 0x26a : F_32 ( V_318 ) ; break;
case 0x279 : F_32 ( V_319 ) ; break;
case 0x289 : F_32 ( V_320 ) ; break;
case 0x28b : F_32 ( V_321 ) ; break;
case 0x28c : F_32 ( V_322 ) ; break;
default: goto V_120;
}
break;
case V_323 :
if ( F_21 ( V_117 , V_21 , V_24 ) )
goto V_120;
else
goto V_165;
break;
case V_324 :
F_12 ( V_127 , V_116 -> V_128 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x021 : F_32 ( V_295 ) ; break;
case 0x070 : F_32 ( V_325 ) ; break;
case 0x071 : F_32 ( V_219 ) ; break;
case 0x072 : F_32 ( V_326 ) ; break;
case 0x073 : F_32 ( V_327 ) ; break;
case 0x080 : F_32 ( V_328 ) ; break;
case 0x081 : F_32 ( V_281 ) ; break;
case 0x082 : F_32 ( V_302 ) ; break;
case 0x083 : F_32 ( V_329 ) ; break;
case 0x084 : F_32 ( V_277 ) ; break;
case 0x085 : F_32 ( V_330 ) ; break;
case 0x086 : F_32 ( V_331 ) ; break;
default: goto V_120;
}
break;
case V_332 :
F_12 ( V_127 , V_116 -> V_128 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x003 : F_32 ( V_333 ) ; break;
case 0x004 : F_32 ( V_334 ) ; break;
default: goto V_120;
}
break;
case V_335 :
goto V_120;
case V_336 :
F_12 ( V_127 , V_116 -> V_128 ) ;
goto V_120;
case V_337 :
goto V_120;
case V_338 :
switch ( V_2 -> V_5 & V_7 ) {
case 0xa4 : F_32 ( V_339 ) ; break;
default: goto V_120;
}
break;
default:
V_165:
if ( V_24 -> V_340 == 1 ) {
if ( V_24 -> V_20 -> type == V_22 ) {
F_36 ( V_198 ) ;
break;
}
F_33 ( V_142 ) ;
break;
}
if ( V_24 -> V_29 & V_182 ) {
F_35 ( V_341 ) ;
break;
}
F_34 ( V_342 ) ;
break;
}
V_124:
if ( V_117 -> V_122 -> V_343 && V_117 -> V_122 -> V_343 ( V_117 ,
V_115 , V_24 , V_2 , & V_118 , & V_95 ) < 0 )
goto V_120;
F_12 ( V_2 -> type , V_116 -> V_128 ) ;
while ( V_2 -> V_10 <= V_95 && F_39 ( V_2 -> V_10 , V_118 ) )
V_2 -> V_10 = F_40 ( V_118 , V_95 + 1 , V_2 -> V_10 ) ;
if ( V_2 -> V_10 > V_95 )
goto V_120;
if ( V_2 -> type == V_344 ) {
int V_345 = V_24 -> V_42 ;
int V_346 = V_24 -> V_41 ;
if ( ( V_117 -> V_63 & V_347 ) && ( V_2 -> V_10 == V_47 || V_2 -> V_10 == V_48 ) ) {
V_345 = V_24 -> V_42 = 0 ;
V_346 = V_24 -> V_41 = 255 ;
}
if ( V_24 -> V_132 == V_139 || V_24 -> V_132 == V_136 )
F_41 ( V_116 , V_2 -> V_10 , V_345 , V_346 , ( V_346 - V_345 ) >> 8 , ( V_346 - V_345 ) >> 4 ) ;
else F_41 ( V_116 , V_2 -> V_10 , V_345 , V_346 , 0 , 0 ) ;
F_42 ( V_116 , V_2 -> V_10 ,
F_14 ( V_24 , V_2 -> V_10 ) ) ;
if ( V_2 -> V_10 == V_50 && V_116 -> V_348 == 0 )
F_43 ( V_116 , 60 ) ;
}
if ( V_2 -> type == V_344 &&
( V_2 -> V_184 < V_2 -> V_185 || V_2 -> V_167 ) ) {
int V_16 ;
for ( V_16 = V_2 -> V_10 ; V_16 < V_2 -> V_10 + 2 && V_16 <= V_95 ; V_16 ++ ) {
F_41 ( V_116 , V_16 , - 1 , 1 , 0 , 0 ) ;
F_12 ( V_16 , V_116 -> V_349 ) ;
}
if ( V_2 -> V_167 && ! V_24 -> V_171 )
V_24 -> V_171 = V_2 -> V_10 ;
}
if ( ( V_2 -> type == V_344 ) && ( V_24 -> V_29 & V_182 ) &&
( V_2 -> V_10 == V_259 ) ) {
F_12 ( V_262 , V_116 -> V_37 ) ;
F_12 ( V_263 , V_116 -> V_37 ) ;
}
if ( V_2 -> type == V_9 ) {
F_12 ( V_350 , V_116 -> V_128 ) ;
F_12 ( V_351 , V_116 -> V_352 ) ;
}
V_120:
return;
}
void F_44 ( struct V_12 * V_5 , struct V_38 * V_24 , struct V_1 * V_2 , T_2 V_14 )
{
struct V_31 * V_116 ;
unsigned * V_63 = & V_5 -> V_63 ;
if ( ! V_24 -> V_115 )
return;
V_116 = V_24 -> V_115 -> V_116 ;
if ( ! V_2 -> type )
return;
if ( V_2 -> V_184 < V_2 -> V_185 || V_2 -> V_167 ) {
int V_167 = V_2 -> V_167 ;
if ( ! V_167 )
V_167 = ( V_14 - V_2 -> V_184 ) * 8 / ( V_2 -> V_185 - V_2 -> V_184 + 1 ) + 1 ;
if ( V_167 < 0 || V_167 > 8 ) V_167 = 0 ;
F_45 ( V_116 , V_2 -> type , V_2 -> V_10 , V_353 [ V_167 ] . V_354 ) ;
F_45 ( V_116 , V_2 -> type , V_2 -> V_10 + 1 , V_353 [ V_167 ] . V_355 ) ;
return;
}
if ( V_2 -> V_5 == ( V_201 | 0x003c ) ) {
* V_63 = V_14 ? ( * V_63 | V_356 ) : ( * V_63 & ~ V_356 ) ;
return;
}
if ( V_2 -> V_5 == ( V_201 | 0x0032 ) ) {
if ( V_14 ) {
F_45 ( V_116 , V_2 -> type , ( * V_63 & V_356 ) ? V_208 : V_2 -> V_10 , 1 ) ;
return;
}
F_45 ( V_116 , V_2 -> type , V_2 -> V_10 , 0 ) ;
F_45 ( V_116 , V_2 -> type , V_208 , 0 ) ;
return;
}
if ( V_2 -> V_5 == ( V_201 | 0x0030 ) && ( * V_63 & V_203 ) ) {
int V_345 = V_24 -> V_42 ;
int V_346 = V_24 -> V_41 ;
F_45 ( V_116 , V_9 , V_202 , V_14 > V_345 + ( ( V_346 - V_345 ) >> 3 ) ) ;
}
if ( V_2 -> V_5 == ( V_338 | 0x83UL ) ) {
F_13 ( L_5 , V_14 ) ;
return;
}
if ( V_2 -> V_5 == ( V_338 | 0x7fUL ) ) {
F_13 ( L_6 ) ;
return;
}
if ( ( V_2 -> type == V_9 ) && ( V_2 -> V_10 == 0 ) )
return;
if ( ( V_2 -> type == V_344 ) && ( V_24 -> V_29 & V_182 ) &&
( V_2 -> V_10 == V_259 ) ) {
int V_357 = abs ( V_14 ) ;
int V_358 = V_14 > 0 ? V_262 : V_263 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_357 ; V_16 ++ ) {
F_45 ( V_116 , V_9 , V_358 , 1 ) ;
F_46 ( V_116 ) ;
F_45 ( V_116 , V_9 , V_358 , 0 ) ;
F_46 ( V_116 ) ;
}
return;
}
if ( ( V_24 -> V_29 & V_359 ) &&
( V_24 -> V_42 < V_24 -> V_41 ) &&
( V_14 < V_24 -> V_42 ||
V_14 > V_24 -> V_41 ) ) {
F_13 ( L_7 , V_14 ) ;
return;
}
if ( V_2 -> type == V_9 && ! ! F_37 ( V_2 -> V_10 , V_116 -> V_360 ) != V_14 )
F_45 ( V_116 , V_350 , V_351 , V_2 -> V_5 ) ;
F_45 ( V_116 , V_2 -> type , V_2 -> V_10 , V_14 ) ;
if ( ( V_24 -> V_29 & V_182 ) && ( V_2 -> type == V_9 ) )
F_45 ( V_116 , V_2 -> type , V_2 -> V_10 , 0 ) ;
}
void F_47 ( struct V_12 * V_5 , struct V_19 * V_20 )
{
struct V_114 * V_115 ;
if ( V_5 -> V_63 & V_361 )
return;
F_5 (hidinput, &hid->inputs, list)
F_46 ( V_115 -> V_116 ) ;
}
int F_48 ( struct V_12 * V_5 , unsigned int type , unsigned int V_10 , struct V_38 * * V_24 )
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
struct V_38 * F_49 ( struct V_12 * V_5 )
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
if ( V_24 -> V_2 [ V_17 ] . type == V_362 )
return V_24 ;
}
}
return NULL ;
}
unsigned int F_50 ( struct V_12 * V_5 )
{
struct V_19 * V_20 ;
struct V_38 * V_24 ;
int V_16 , V_17 ;
unsigned int V_357 = 0 ;
F_5 (report,
&hid->report_enum[HID_OUTPUT_REPORT].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ ) {
V_24 = V_20 -> V_24 [ V_16 ] ;
for ( V_17 = 0 ; V_17 < V_24 -> V_25 ; V_17 ++ )
if ( V_24 -> V_2 [ V_17 ] . type == V_362 &&
V_24 -> V_14 [ V_17 ] )
V_357 += 1 ;
}
}
return V_357 ;
}
static int F_51 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
return F_52 ( V_5 ) ;
}
static void F_53 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
F_54 ( V_5 ) ;
}
static void F_55 ( struct V_12 * V_5 )
{
struct V_363 * V_364 = V_5 -> V_122 ;
struct V_365 * V_366 ;
struct V_19 * V_367 ;
int V_16 , V_17 ;
V_366 = & V_5 -> V_368 [ V_112 ] ;
F_5 (rep, &rep_enum->report_list, list)
for ( V_16 = 0 ; V_16 < V_367 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_367 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ ) {
F_21 ( V_5 , V_112 , V_367 -> V_24 [ V_16 ] ) ;
if ( V_364 -> V_369 )
V_364 -> V_369 ( V_5 , V_367 -> V_24 [ V_16 ] ,
V_367 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
}
}
static struct V_114 * F_56 ( struct V_12 * V_5 )
{
struct V_114 * V_115 = F_57 ( sizeof( * V_115 ) , V_98 ) ;
struct V_31 * V_31 = F_58 () ;
if ( ! V_115 || ! V_31 ) {
F_27 ( V_115 ) ;
F_59 ( V_31 ) ;
F_60 ( V_5 , L_8 ) ;
return NULL ;
}
F_61 ( V_31 , V_5 ) ;
V_31 -> V_370 = V_5 -> V_371 -> V_372 ;
V_31 -> V_373 = F_51 ;
V_31 -> V_374 = F_53 ;
V_31 -> V_375 = F_10 ;
V_31 -> V_376 = F_8 ;
V_31 -> V_88 = V_5 -> V_88 ;
V_31 -> V_377 = V_5 -> V_377 ;
V_31 -> V_99 = V_5 -> V_99 ;
V_31 -> V_113 . V_378 = V_5 -> V_106 ;
V_31 -> V_113 . V_107 = V_5 -> V_107 ;
V_31 -> V_113 . V_108 = V_5 -> V_108 ;
V_31 -> V_113 . V_109 = V_5 -> V_109 ;
V_31 -> V_32 . V_379 = V_5 -> V_32 . V_379 ;
V_115 -> V_116 = V_31 ;
F_62 ( & V_115 -> V_380 , & V_5 -> V_381 ) ;
return V_115 ;
}
static bool F_63 ( struct V_114 * V_115 )
{
int V_16 ;
unsigned long V_382 = 0 ;
for ( V_16 = 0 ; V_16 < F_64 ( V_383 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_128 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_64 ( V_384 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_37 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_64 ( V_385 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_386 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_64 ( V_387 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_349 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_64 ( V_388 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_352 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_64 ( V_389 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_390 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_64 ( V_391 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_392 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_64 ( V_393 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_394 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_64 ( V_395 ) ; V_16 ++ )
V_382 |= V_115 -> V_116 -> V_396 [ V_16 ] ;
return ! ! V_382 ;
}
static void F_65 ( struct V_12 * V_5 ,
struct V_114 * V_115 )
{
struct V_19 * V_20 ;
int V_16 , V_18 ;
F_66 ( & V_115 -> V_380 ) ;
F_59 ( V_115 -> V_116 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_63 & V_397 )
continue;
F_5 (report, &hid->report_enum[k].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
if ( V_20 -> V_24 [ V_16 ] -> V_115 == V_115 )
V_20 -> V_24 [ V_16 ] -> V_115 = NULL ;
}
}
F_27 ( V_115 ) ;
}
int F_67 ( struct V_12 * V_5 , unsigned int V_398 )
{
struct V_363 * V_364 = V_5 -> V_122 ;
struct V_19 * V_20 ;
struct V_114 * V_115 = NULL ;
int V_16 , V_17 , V_18 ;
F_68 ( & V_5 -> V_381 ) ;
if ( ! V_398 ) {
for ( V_16 = 0 ; V_16 < V_5 -> V_399 ; V_16 ++ ) {
struct V_400 * V_401 = & V_5 -> V_402 [ V_16 ] ;
if ( V_401 -> type == V_403 ||
V_401 -> type == V_404 )
if ( F_69 ( V_401 -> V_2 ) )
break;
}
if ( V_16 == V_5 -> V_399 )
return - 1 ;
}
F_55 ( V_5 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_63 & V_397 )
continue;
F_5 (report, &hid->report_enum[k].report_list, list) {
if ( ! V_20 -> V_23 )
continue;
if ( ! V_115 ) {
V_115 = F_56 ( V_5 ) ;
if ( ! V_115 )
goto V_405;
}
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_20 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ )
F_31 ( V_115 , V_20 -> V_24 [ V_16 ] ,
V_20 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
if ( ( V_5 -> V_63 & V_406 ) &&
! F_63 ( V_115 ) )
continue;
if ( V_5 -> V_63 & V_407 ) {
V_115 -> V_20 = V_20 ;
if ( V_364 -> V_408 )
V_364 -> V_408 ( V_5 , V_115 ) ;
if ( F_70 ( V_115 -> V_116 ) )
goto V_409;
V_115 = NULL ;
}
}
}
if ( V_115 && ( V_5 -> V_63 & V_406 ) &&
! F_63 ( V_115 ) ) {
F_65 ( V_5 , V_115 ) ;
V_115 = NULL ;
}
if ( F_71 ( & V_5 -> V_381 ) ) {
F_60 ( V_5 , L_9 ) ;
goto V_405;
}
if ( V_115 ) {
if ( V_364 -> V_408 )
V_364 -> V_408 ( V_5 , V_115 ) ;
if ( F_70 ( V_115 -> V_116 ) )
goto V_409;
}
return 0 ;
V_409:
F_66 ( & V_115 -> V_380 ) ;
F_59 ( V_115 -> V_116 ) ;
F_27 ( V_115 ) ;
V_405:
F_72 ( V_5 ) ;
return - 1 ;
}
void F_72 ( struct V_12 * V_5 )
{
struct V_114 * V_115 , * V_410 ;
F_29 ( V_5 ) ;
F_73 (hidinput, next, &hid->inputs, list) {
F_66 ( & V_115 -> V_380 ) ;
F_74 ( V_115 -> V_116 ) ;
F_27 ( V_115 ) ;
}
}
