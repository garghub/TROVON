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
static int F_18 ( struct V_12 * V_32 ,
int V_14 )
{
if ( V_32 -> V_68 < V_32 -> V_69 &&
V_14 >= V_32 -> V_68 && V_14 <= V_32 -> V_69 )
V_14 = ( ( V_14 - V_32 -> V_68 ) * 100 ) /
( V_32 -> V_69 - V_32 -> V_68 ) ;
return V_14 ;
}
static int F_19 ( struct V_12 * V_32 )
{
T_4 * V_70 ;
int V_71 ;
V_70 = F_20 ( 2 , V_72 ) ;
if ( ! V_70 )
return - V_73 ;
V_71 = F_21 ( V_32 , V_32 -> V_74 , V_70 , 2 ,
V_32 -> V_75 , V_76 ) ;
if ( V_71 != 2 ) {
F_22 ( V_70 ) ;
return - V_77 ;
}
V_71 = F_18 ( V_32 , V_70 [ 1 ] ) ;
F_22 ( V_70 ) ;
return V_71 ;
}
static int F_23 ( struct V_78 * V_79 ,
enum V_80 V_81 ,
union V_82 * V_83 )
{
struct V_12 * V_32 = F_24 ( V_79 ) ;
int V_14 ;
int V_71 = 0 ;
switch ( V_81 ) {
case V_84 :
case V_85 :
V_83 -> V_86 = 1 ;
break;
case V_87 :
if ( V_32 -> V_75 == V_88 ) {
V_14 = F_19 ( V_32 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
V_14 = V_32 -> V_89 ;
}
V_83 -> V_86 = V_14 ;
break;
case V_90 :
V_83 -> V_91 = V_32 -> V_92 ;
break;
case V_93 :
if ( ! V_32 -> V_94 &&
V_32 -> V_75 == V_88 ) {
V_14 = F_19 ( V_32 ) ;
if ( V_14 < 0 )
return V_14 ;
V_32 -> V_89 = V_14 ;
V_32 -> V_94 = true ;
}
if ( ! V_32 -> V_94 )
V_83 -> V_86 = V_95 ;
else if ( V_32 -> V_89 == 100 )
V_83 -> V_86 = V_96 ;
else
V_83 -> V_86 = V_97 ;
break;
case V_98 :
V_83 -> V_86 = V_99 ;
break;
default:
V_71 = - V_35 ;
break;
}
return V_71 ;
}
static int F_25 ( struct V_12 * V_32 , unsigned V_100 , struct V_38 * V_24 )
{
struct V_101 * V_102 ;
struct V_103 V_104 = { . V_105 = V_32 , } ;
unsigned V_64 ;
T_5 V_106 , V_107 ;
int error ;
if ( V_32 -> V_108 )
return 0 ;
V_64 = F_16 ( V_32 ) ;
F_26 ( V_32 , L_2 ,
V_32 -> V_109 , V_32 -> V_110 , V_32 -> V_111 , V_32 -> V_112 , V_64 ) ;
if ( V_64 & V_113 )
return 0 ;
V_102 = F_27 ( sizeof( * V_102 ) , V_72 ) ;
if ( ! V_102 )
return - V_73 ;
V_102 -> V_92 = F_28 ( V_72 , L_3 ,
strlen ( V_32 -> V_114 ) ?
V_32 -> V_114 : F_29 ( & V_32 -> V_32 ) ) ;
if ( ! V_102 -> V_92 ) {
error = - V_73 ;
goto V_115;
}
V_102 -> type = V_116 ;
V_102 -> V_117 = V_118 ;
V_102 -> V_119 = F_30 ( V_118 ) ;
V_102 -> V_120 = 0 ;
V_102 -> V_121 = F_23 ;
V_106 = V_24 -> V_42 ;
V_107 = V_24 -> V_41 ;
if ( V_64 & V_122 ) {
V_106 = 0 ;
V_107 = 100 ;
}
if ( V_64 & V_123 )
V_100 = V_88 ;
V_32 -> V_68 = V_106 ;
V_32 -> V_69 = V_107 ;
V_32 -> V_75 = V_100 ;
V_32 -> V_74 = V_24 -> V_20 -> V_124 ;
V_32 -> V_108 = F_31 ( & V_32 -> V_32 , V_102 , & V_104 ) ;
if ( F_32 ( V_32 -> V_108 ) ) {
error = F_33 ( V_32 -> V_108 ) ;
F_34 ( V_32 , L_4 , error ) ;
goto V_125;
}
F_35 ( V_32 -> V_108 , & V_32 -> V_32 ) ;
return 0 ;
V_125:
F_22 ( V_102 -> V_92 ) ;
V_115:
F_22 ( V_102 ) ;
V_32 -> V_108 = NULL ;
return error ;
}
static void F_36 ( struct V_12 * V_32 )
{
const struct V_101 * V_102 ;
if ( ! V_32 -> V_108 )
return;
V_102 = V_32 -> V_108 -> V_126 ;
F_37 ( V_32 -> V_108 ) ;
F_22 ( V_102 -> V_92 ) ;
F_22 ( V_102 ) ;
V_32 -> V_108 = NULL ;
}
static void F_38 ( struct V_12 * V_32 , int V_14 )
{
int V_127 ;
if ( ! V_32 -> V_108 )
return;
if ( V_14 == 0 || V_14 < V_32 -> V_68 || V_14 > V_32 -> V_69 )
return;
V_127 = F_18 ( V_32 , V_14 ) ;
if ( ! V_32 -> V_94 || V_127 != V_32 -> V_89 ) {
V_32 -> V_89 = V_127 ;
V_32 -> V_94 = true ;
F_39 ( V_32 -> V_108 ) ;
}
}
static int F_25 ( struct V_12 * V_32 , unsigned V_100 ,
struct V_38 * V_24 )
{
return 0 ;
}
static void F_36 ( struct V_12 * V_32 )
{
}
static void F_38 ( struct V_12 * V_32 , int V_14 )
{
}
static void F_40 ( struct V_128 * V_129 , struct V_38 * V_24 ,
struct V_1 * V_2 )
{
struct V_31 * V_130 = V_129 -> V_130 ;
struct V_12 * V_131 = F_9 ( V_130 ) ;
int V_107 = 0 , V_10 ;
unsigned long * V_132 = NULL ;
V_24 -> V_129 = V_129 ;
if ( V_24 -> V_29 & V_133 )
goto V_134;
if ( V_24 -> V_135 < 1 )
goto V_134;
if ( V_24 -> V_100 == V_22 &&
( V_2 -> V_5 & V_6 ) != V_136 ) {
goto V_134;
}
if ( V_131 -> V_137 -> V_138 ) {
int V_71 = V_131 -> V_137 -> V_138 ( V_131 , V_129 , V_24 ,
V_2 , & V_132 , & V_107 ) ;
if ( V_71 > 0 )
goto V_139;
if ( V_71 < 0 )
goto V_134;
}
switch ( V_2 -> V_5 & V_6 ) {
case V_140 :
goto V_134;
case V_141 :
F_12 ( V_142 , V_130 -> V_143 ) ;
if ( ( V_2 -> V_5 & V_7 ) < 256 ) {
if ( ! V_144 [ V_2 -> V_5 & V_7 ] ) goto V_134;
F_41 ( V_144 [ V_2 -> V_5 & V_7 ] ) ;
} else
F_42 ( V_145 ) ;
break;
case V_146 :
V_10 = ( ( V_2 -> V_5 - 1 ) & V_7 ) ;
switch ( V_24 -> V_147 ) {
case V_148 :
case V_149 : V_10 += V_150 ; break;
case V_151 :
if ( V_10 <= 0xf )
V_10 += V_152 ;
else
V_10 += V_153 - 0x10 ;
break;
case V_154 :
if ( V_10 <= 0xf )
V_10 += V_155 ;
else
V_10 += V_153 - 0x10 ;
break;
default:
switch ( V_24 -> V_156 ) {
case V_148 :
case V_149 : V_10 += V_150 ; break;
case V_151 : V_10 += V_152 ; break;
case V_154 : V_10 += V_155 ; break;
default: V_10 += V_157 ;
}
}
F_42 ( V_10 ) ;
break;
case V_158 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0xba : F_43 ( V_159 ) ; break;
case 0xbb : F_43 ( V_160 ) ; break;
case 0xc4 : F_43 ( V_161 ) ; break;
case 0xc5 : F_43 ( V_162 ) ; break;
case 0xc8 : F_43 ( V_60 ) ; break;
default: goto V_134;
}
break;
case V_163 :
if ( ( V_2 -> V_5 & 0xf0 ) == 0x80 ) {
switch ( V_2 -> V_5 & 0xf ) {
case 0x1 : F_41 ( V_164 ) ; break;
case 0x2 : F_41 ( V_165 ) ; break;
case 0x3 : F_41 ( V_166 ) ; break;
case 0x4 : F_41 ( V_167 ) ; break;
case 0x5 : F_41 ( V_168 ) ; break;
case 0x6 : F_41 ( V_169 ) ; break;
case 0x7 : F_41 ( V_170 ) ; break;
case 0x8 : F_41 ( V_171 ) ; break;
case 0x9 : F_41 ( V_172 ) ; break;
case 0xa : F_41 ( V_173 ) ; break;
case 0xb : F_41 ( V_174 ) ; break;
case 0xc : F_41 ( V_175 ) ; break;
case 0xd : F_41 ( V_176 ) ; break;
case 0xe : F_41 ( V_177 ) ; break;
case 0xf : F_41 ( V_178 ) ; break;
default: goto V_179;
}
break;
}
if ( V_24 -> V_147 == V_180 )
goto V_134;
if ( ( V_2 -> V_5 & 0xf0 ) == 0x90 ) {
switch ( V_2 -> V_5 ) {
case V_181 : V_2 -> V_182 = 1 ; break;
case V_183 : V_2 -> V_182 = 5 ; break;
case V_184 : V_2 -> V_182 = 3 ; break;
case V_185 : V_2 -> V_182 = 7 ; break;
default: goto V_179;
}
if ( V_24 -> V_186 ) {
F_43 ( V_24 -> V_186 ) ;
goto V_134;
}
F_43 ( V_187 ) ;
break;
}
switch ( V_2 -> V_5 ) {
case V_188 : case V_189 : case V_190 :
case V_191 : case V_192 : case V_193 :
if ( V_24 -> V_29 & V_194 )
F_44 ( V_2 -> V_5 & 0xf ) ;
else
F_45 ( V_2 -> V_5 & 0xf ) ;
break;
case V_195 : case V_196 : case V_197 :
if ( V_24 -> V_29 & V_194 )
F_44 ( V_2 -> V_5 & 0xf ) ;
else
F_43 ( V_2 -> V_5 & 0xf ) ;
break;
case V_198 :
V_2 -> V_199 = V_24 -> V_42 ;
V_2 -> V_200 = V_24 -> V_41 ;
F_43 ( V_187 ) ;
break;
case V_201 : F_41 ( V_202 ) ; break;
case V_203 : F_41 ( V_204 ) ; break;
case V_205 :
if ( V_24 -> V_147 == V_206 ) {
F_41 ( V_207 ) ;
V_24 -> V_29 |= V_194 ;
break;
}
default: goto V_179;
}
break;
case V_136 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0x01 : F_46 ( V_208 ) ; break;
case 0x02 : F_46 ( V_209 ) ; break;
case 0x03 : F_46 ( V_210 ) ; break;
case 0x04 : F_46 ( V_211 ) ; break;
case 0x05 : F_46 ( V_212 ) ; break;
case 0x27 : F_46 ( V_213 ) ; break;
case 0x4c : F_46 ( V_214 ) ; break;
case 0x09 : F_46 ( V_215 ) ; break;
case 0x4b : F_46 ( V_216 ) ; break;
case 0x19 : F_46 ( V_217 ) ; break;
case 0x4d : F_46 ( V_218 ) ; break;
default: goto V_134;
}
break;
case V_219 :
switch ( V_2 -> V_5 & 0xff ) {
case 0x00 :
goto V_134;
case 0x30 :
if ( ! F_47 ( V_220 , V_130 -> V_37 ) ) {
V_131 -> V_64 |= V_221 ;
F_12 ( V_9 , V_130 -> V_143 ) ;
F_12 ( V_220 , V_130 -> V_37 ) ;
}
F_45 ( V_222 ) ;
break;
case 0x32 :
switch ( V_24 -> V_156 & 0xff ) {
case 0x21 : F_42 ( V_223 ) ; break;
case 0x22 : F_42 ( V_224 ) ; break;
default: F_42 ( V_225 ) ; break;
}
break;
case 0x3b :
F_25 ( V_131 , V_21 , V_24 ) ;
V_2 -> type = V_226 ;
goto V_134;
case 0x3c :
F_41 ( V_227 ) ;
break;
case 0x3d :
F_45 ( V_61 ) ;
break;
case 0x3e :
F_45 ( V_62 ) ;
break;
case 0x33 :
case 0x42 :
case 0x43 :
V_131 -> V_64 &= ~ V_221 ;
F_41 ( V_220 ) ;
break;
case 0x44 :
F_41 ( V_228 ) ;
break;
case 0x46 :
case 0x5a :
F_41 ( V_229 ) ;
break;
case 0x5b :
V_2 -> type = V_230 ;
V_2 -> V_10 = V_231 ;
V_132 = V_130 -> V_232 ;
V_107 = V_233 ;
break;
default: goto V_179;
}
break;
case V_234 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x2f : F_41 ( V_235 ) ; break;
case 0xb0 : F_41 ( V_236 ) ; break;
case 0xb1 : F_41 ( V_237 ) ; break;
case 0xb2 : F_41 ( V_238 ) ; break;
case 0xb3 : F_41 ( V_239 ) ; break;
case 0xb4 : F_41 ( V_240 ) ; break;
case 0xb5 : F_41 ( V_241 ) ; break;
case 0xb6 : F_41 ( V_242 ) ; break;
case 0xb7 : F_41 ( V_243 ) ; break;
case 0xb8 : F_41 ( V_244 ) ; break;
case 0xb9 : F_41 ( V_245 ) ; break;
case 0xba : F_41 ( V_246 ) ; break;
case 0xbb : F_41 ( V_247 ) ; break;
case 0xbc : F_41 ( V_248 ) ; break;
case 0xbd : F_41 ( V_249 ) ; break;
case 0xbe : F_41 ( V_250 ) ; break;
case 0xbf : F_41 ( V_251 ) ; break;
default: goto V_134;
}
break;
case V_252 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x000 : goto V_134;
case 0x030 : F_41 ( V_164 ) ; break;
case 0x031 : F_41 ( V_178 ) ; break;
case 0x032 : F_41 ( V_165 ) ; break;
case 0x034 : F_41 ( V_165 ) ; break;
case 0x035 : F_41 ( V_253 ) ; break;
case 0x036 : F_41 ( V_157 ) ; break;
case 0x040 : F_41 ( V_168 ) ; break;
case 0x041 : F_41 ( V_172 ) ; break;
case 0x042 : F_41 ( V_175 ) ; break;
case 0x043 : F_41 ( V_176 ) ; break;
case 0x044 : F_41 ( V_174 ) ; break;
case 0x045 : F_41 ( V_173 ) ; break;
case 0x046 : F_41 ( V_254 ) ; break;
case 0x047 : F_41 ( V_255 ) ; break;
case 0x048 : F_41 ( V_256 ) ; break;
case 0x060 : F_41 ( V_257 ) ; break;
case 0x061 : F_41 ( V_258 ) ; break;
case 0x063 : F_41 ( V_259 ) ; break;
case 0x065 : F_41 ( V_260 ) ; break;
case 0x069 : F_41 ( V_261 ) ; break;
case 0x06a : F_41 ( V_262 ) ; break;
case 0x06b : F_41 ( V_263 ) ; break;
case 0x06c : F_41 ( V_264 ) ; break;
case 0x06d : F_41 ( V_265 ) ; break;
case 0x06f : F_41 ( V_266 ) ; break;
case 0x070 : F_41 ( V_267 ) ; break;
case 0x072 : F_41 ( V_268 ) ; break;
case 0x073 : F_41 ( V_269 ) ; break;
case 0x074 : F_41 ( V_270 ) ; break;
case 0x075 : F_41 ( V_271 ) ; break;
case 0x082 : F_41 ( V_272 ) ; break;
case 0x083 : F_41 ( V_273 ) ; break;
case 0x084 : F_41 ( V_274 ) ; break;
case 0x088 : F_41 ( V_275 ) ; break;
case 0x089 : F_41 ( V_276 ) ; break;
case 0x08a : F_41 ( V_277 ) ; break;
case 0x08b : F_41 ( V_278 ) ; break;
case 0x08c : F_41 ( V_279 ) ; break;
case 0x08d : F_41 ( V_280 ) ; break;
case 0x08e : F_41 ( V_281 ) ; break;
case 0x08f : F_41 ( V_282 ) ; break;
case 0x090 : F_41 ( V_283 ) ; break;
case 0x091 : F_41 ( V_284 ) ; break;
case 0x092 : F_41 ( V_259 ) ; break;
case 0x093 : F_41 ( V_285 ) ; break;
case 0x094 : F_41 ( V_171 ) ; break;
case 0x095 : F_41 ( V_170 ) ; break;
case 0x096 : F_41 ( V_286 ) ; break;
case 0x097 : F_41 ( V_287 ) ; break;
case 0x098 : F_41 ( V_288 ) ; break;
case 0x09a : F_41 ( V_289 ) ; break;
case 0x09c : F_41 ( V_290 ) ; break;
case 0x09d : F_41 ( V_291 ) ; break;
case 0x0a0 : F_41 ( V_292 ) ; break;
case 0x0b0 : F_41 ( V_293 ) ; break;
case 0x0b1 : F_41 ( V_294 ) ; break;
case 0x0b2 : F_41 ( V_295 ) ; break;
case 0x0b3 : F_41 ( V_296 ) ; break;
case 0x0b4 : F_41 ( V_297 ) ; break;
case 0x0b5 : F_41 ( V_298 ) ; break;
case 0x0b6 : F_41 ( V_299 ) ; break;
case 0x0b7 : F_41 ( V_300 ) ; break;
case 0x0b8 : F_41 ( V_301 ) ; break;
case 0x0bc : F_41 ( V_302 ) ; break;
case 0x0b9 : F_41 ( V_303 ) ; break;
case 0x0bf : F_41 ( V_304 ) ; break;
case 0x0cd : F_41 ( V_305 ) ; break;
case 0x0cf : F_41 ( V_306 ) ; break;
case 0x0e0 : F_45 ( V_307 ) ; break;
case 0x0e2 : F_41 ( V_308 ) ; break;
case 0x0e5 : F_41 ( V_309 ) ; break;
case 0x0e9 : F_41 ( V_310 ) ; break;
case 0x0ea : F_41 ( V_311 ) ; break;
case 0x0f5 : F_41 ( V_304 ) ; break;
case 0x181 : F_41 ( V_312 ) ; break;
case 0x182 : F_41 ( V_313 ) ; break;
case 0x183 : F_41 ( V_314 ) ; break;
case 0x184 : F_41 ( V_315 ) ; break;
case 0x185 : F_41 ( V_316 ) ; break;
case 0x186 : F_41 ( V_317 ) ; break;
case 0x187 : F_41 ( V_318 ) ; break;
case 0x188 : F_41 ( V_319 ) ; break;
case 0x189 : F_41 ( V_320 ) ; break;
case 0x18a : F_41 ( V_321 ) ; break;
case 0x18b : F_41 ( V_322 ) ; break;
case 0x18c : F_41 ( V_323 ) ; break;
case 0x18d : F_41 ( V_324 ) ; break;
case 0x18e : F_41 ( V_325 ) ; break;
case 0x18f : F_41 ( V_326 ) ; break;
case 0x190 : F_41 ( V_327 ) ; break;
case 0x191 : F_41 ( V_328 ) ; break;
case 0x192 : F_41 ( V_329 ) ; break;
case 0x193 : F_41 ( V_330 ) ; break;
case 0x194 : F_41 ( V_331 ) ; break;
case 0x196 : F_41 ( V_277 ) ; break;
case 0x199 : F_41 ( V_332 ) ; break;
case 0x19c : F_41 ( V_333 ) ; break;
case 0x19e : F_41 ( V_334 ) ; break;
case 0x19f : F_41 ( V_335 ) ; break;
case 0x1a2 : F_41 ( V_336 ) ; break;
case 0x1a3 : F_41 ( V_337 ) ; break;
case 0x1a4 : F_41 ( V_338 ) ; break;
case 0x1a6 : F_41 ( V_170 ) ; break;
case 0x1a7 : F_41 ( V_339 ) ; break;
case 0x1ab : F_41 ( V_340 ) ; break;
case 0x1ae : F_41 ( V_341 ) ; break;
case 0x1b1 : F_41 ( V_342 ) ; break;
case 0x1b4 : F_41 ( V_331 ) ; break;
case 0x1b6 : F_41 ( V_343 ) ; break;
case 0x1b7 : F_41 ( V_344 ) ; break;
case 0x1b8 : F_41 ( V_345 ) ; break;
case 0x1bc : F_41 ( V_346 ) ; break;
case 0x1bd : F_41 ( V_257 ) ; break;
case 0x201 : F_41 ( V_347 ) ; break;
case 0x202 : F_41 ( V_348 ) ; break;
case 0x203 : F_41 ( V_349 ) ; break;
case 0x204 : F_41 ( V_171 ) ; break;
case 0x207 : F_41 ( V_350 ) ; break;
case 0x208 : F_41 ( V_351 ) ; break;
case 0x209 : F_41 ( V_352 ) ; break;
case 0x21a : F_41 ( V_353 ) ; break;
case 0x21b : F_41 ( V_354 ) ; break;
case 0x21c : F_41 ( V_355 ) ; break;
case 0x21d : F_41 ( V_356 ) ; break;
case 0x21f : F_41 ( V_357 ) ; break;
case 0x221 : F_41 ( V_358 ) ; break;
case 0x222 : F_41 ( V_359 ) ; break;
case 0x223 : F_41 ( V_360 ) ; break;
case 0x224 : F_41 ( V_361 ) ; break;
case 0x225 : F_41 ( V_362 ) ; break;
case 0x226 : F_41 ( V_363 ) ; break;
case 0x227 : F_41 ( V_364 ) ; break;
case 0x22a : F_41 ( V_313 ) ; break;
case 0x22d : F_41 ( V_365 ) ; break;
case 0x22e : F_41 ( V_366 ) ; break;
case 0x22f : F_41 ( V_367 ) ; break;
case 0x233 : F_41 ( V_368 ) ; break;
case 0x234 : F_41 ( V_369 ) ; break;
case 0x238 : F_44 ( V_370 ) ; break;
case 0x23d : F_41 ( V_371 ) ; break;
case 0x25f : F_41 ( V_372 ) ; break;
case 0x269 : F_41 ( V_373 ) ; break;
case 0x26a : F_41 ( V_374 ) ; break;
case 0x279 : F_41 ( V_375 ) ; break;
case 0x289 : F_41 ( V_376 ) ; break;
case 0x28b : F_41 ( V_377 ) ; break;
case 0x28c : F_41 ( V_378 ) ; break;
case 0x2c7 : F_41 ( V_379 ) ; break;
case 0x2c8 : F_41 ( V_380 ) ; break;
case 0x2c9 : F_41 ( V_381 ) ; break;
case 0x2ca : F_41 ( V_382 ) ; break;
case 0x2cb : F_41 ( V_383 ) ; break;
case 0x2cc : F_41 ( V_384 ) ; break;
default: F_41 ( V_145 ) ;
}
break;
case V_385 :
switch ( V_2 -> V_5 ) {
case V_386 :
F_25 ( V_131 , V_21 , V_24 ) ;
V_2 -> type = V_226 ;
goto V_134;
}
goto V_179;
case V_387 :
F_12 ( V_142 , V_130 -> V_143 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x021 : F_41 ( V_351 ) ; break;
case 0x070 : F_41 ( V_388 ) ; break;
case 0x071 : F_41 ( V_260 ) ; break;
case 0x072 : F_41 ( V_389 ) ; break;
case 0x073 : F_41 ( V_390 ) ; break;
case 0x080 : F_41 ( V_391 ) ; break;
case 0x081 : F_41 ( V_332 ) ; break;
case 0x082 : F_41 ( V_358 ) ; break;
case 0x083 : F_41 ( V_392 ) ; break;
case 0x084 : F_41 ( V_328 ) ; break;
case 0x085 : F_41 ( V_393 ) ; break;
case 0x086 : F_41 ( V_394 ) ; break;
default: goto V_134;
}
break;
case V_395 :
F_12 ( V_142 , V_130 -> V_143 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x001 : F_41 ( V_235 ) ; break;
case 0x003 : F_41 ( V_267 ) ; break;
case 0x004 : F_41 ( V_266 ) ; break;
default: goto V_134;
}
break;
case V_396 :
goto V_134;
case V_397 :
F_12 ( V_142 , V_130 -> V_143 ) ;
goto V_134;
case V_398 :
case V_399 :
case V_400 :
goto V_134;
case V_401 :
switch ( V_2 -> V_5 & V_7 ) {
case 0xa4 : F_41 ( V_402 ) ; break;
default: goto V_134;
}
break;
default:
V_179:
if ( V_24 -> V_403 == 1 ) {
if ( V_24 -> V_20 -> type == V_22 ) {
F_46 ( V_216 ) ;
break;
}
F_42 ( V_157 ) ;
break;
}
if ( V_24 -> V_29 & V_194 ) {
F_44 ( V_404 ) ;
break;
}
F_43 ( V_405 ) ;
break;
}
V_139:
if ( V_131 -> V_137 -> V_406 && V_131 -> V_137 -> V_406 ( V_131 ,
V_129 , V_24 , V_2 , & V_132 , & V_107 ) < 0 )
goto V_134;
F_12 ( V_2 -> type , V_130 -> V_143 ) ;
while ( V_2 -> V_10 <= V_107 && F_48 ( V_2 -> V_10 , V_132 ) )
V_2 -> V_10 = F_49 ( V_132 , V_107 + 1 , V_2 -> V_10 ) ;
if ( V_2 -> V_10 > V_107 )
goto V_134;
if ( V_2 -> type == V_407 ) {
int V_408 = V_24 -> V_42 ;
int V_409 = V_24 -> V_41 ;
if ( ( V_131 -> V_64 & V_410 ) && ( V_2 -> V_10 == V_47 || V_2 -> V_10 == V_48 ) ) {
V_408 = V_24 -> V_42 = 0 ;
V_409 = V_24 -> V_41 = 255 ;
}
if ( V_24 -> V_147 == V_154 || V_24 -> V_147 == V_151 )
F_50 ( V_130 , V_2 -> V_10 , V_408 , V_409 , ( V_409 - V_408 ) >> 8 , ( V_409 - V_408 ) >> 4 ) ;
else F_50 ( V_130 , V_2 -> V_10 , V_408 , V_409 , 0 , 0 ) ;
F_51 ( V_130 , V_2 -> V_10 ,
F_14 ( V_24 , V_2 -> V_10 ) ) ;
if ( V_2 -> V_10 == V_50 && V_130 -> V_411 == 0 )
F_52 ( V_130 , 60 ) ;
}
if ( V_2 -> type == V_407 &&
( V_2 -> V_199 < V_2 -> V_200 || V_2 -> V_182 ) ) {
int V_16 ;
for ( V_16 = V_2 -> V_10 ; V_16 < V_2 -> V_10 + 2 && V_16 <= V_107 ; V_16 ++ ) {
F_50 ( V_130 , V_16 , - 1 , 1 , 0 , 0 ) ;
F_12 ( V_16 , V_130 -> V_412 ) ;
}
if ( V_2 -> V_182 && ! V_24 -> V_186 )
V_24 -> V_186 = V_2 -> V_10 ;
}
if ( ( V_2 -> type == V_407 ) && ( V_24 -> V_29 & V_194 ) &&
( V_2 -> V_10 == V_307 ) ) {
F_12 ( V_310 , V_130 -> V_37 ) ;
F_12 ( V_311 , V_130 -> V_37 ) ;
}
if ( V_2 -> type == V_9 ) {
F_12 ( V_230 , V_130 -> V_143 ) ;
F_12 ( V_413 , V_130 -> V_232 ) ;
}
V_134:
return;
}
void F_53 ( struct V_12 * V_5 , struct V_38 * V_24 , struct V_1 * V_2 , T_2 V_14 )
{
struct V_31 * V_130 ;
unsigned * V_64 = & V_5 -> V_64 ;
if ( ! V_2 -> type )
return;
if ( V_2 -> type == V_226 ) {
F_38 ( V_5 , V_14 ) ;
return;
}
if ( ! V_24 -> V_129 )
return;
V_130 = V_24 -> V_129 -> V_130 ;
if ( V_2 -> V_199 < V_2 -> V_200 || V_2 -> V_182 ) {
int V_182 = V_2 -> V_182 ;
if ( ! V_182 )
V_182 = ( V_14 - V_2 -> V_199 ) * 8 / ( V_2 -> V_200 - V_2 -> V_199 + 1 ) + 1 ;
if ( V_182 < 0 || V_182 > 8 ) V_182 = 0 ;
F_54 ( V_130 , V_2 -> type , V_2 -> V_10 , V_414 [ V_182 ] . V_415 ) ;
F_54 ( V_130 , V_2 -> type , V_2 -> V_10 + 1 , V_414 [ V_182 ] . V_416 ) ;
return;
}
if ( V_2 -> V_5 == ( V_219 | 0x003c ) ) {
* V_64 = V_14 ? ( * V_64 | V_417 ) : ( * V_64 & ~ V_417 ) ;
return;
}
if ( V_2 -> V_5 == ( V_219 | 0x0032 ) ) {
if ( V_14 ) {
F_54 ( V_130 , V_2 -> type , ( * V_64 & V_417 ) ? V_227 : V_2 -> V_10 , 1 ) ;
return;
}
F_54 ( V_130 , V_2 -> type , V_2 -> V_10 , 0 ) ;
F_54 ( V_130 , V_2 -> type , V_227 , 0 ) ;
return;
}
if ( V_2 -> V_5 == ( V_219 | 0x0030 ) && ( * V_64 & V_221 ) ) {
int V_408 = V_24 -> V_42 ;
int V_409 = V_24 -> V_41 ;
F_54 ( V_130 , V_9 , V_220 , V_14 > V_408 + ( ( V_409 - V_408 ) >> 3 ) ) ;
}
if ( V_2 -> V_5 == ( V_401 | 0x83UL ) ) {
F_13 ( L_5 , V_14 ) ;
return;
}
if ( V_2 -> V_5 == ( V_401 | 0x7fUL ) ) {
F_13 ( L_6 ) ;
return;
}
if ( ( V_2 -> type == V_9 ) && ( V_2 -> V_10 == 0 ) )
return;
if ( ( V_2 -> type == V_407 ) && ( V_24 -> V_29 & V_194 ) &&
( V_2 -> V_10 == V_307 ) ) {
int V_418 = abs ( V_14 ) ;
int V_419 = V_14 > 0 ? V_310 : V_311 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_418 ; V_16 ++ ) {
F_54 ( V_130 , V_9 , V_419 , 1 ) ;
F_55 ( V_130 ) ;
F_54 ( V_130 , V_9 , V_419 , 0 ) ;
F_55 ( V_130 ) ;
}
return;
}
if ( ( V_24 -> V_29 & V_420 ) &&
( V_24 -> V_42 < V_24 -> V_41 ) ) {
if ( V_24 -> V_29 & V_421 &&
( V_14 < V_24 -> V_42 ||
V_14 > V_24 -> V_41 ) ) {
F_13 ( L_7 , V_14 ) ;
return;
}
V_14 = F_56 ( V_14 ,
V_24 -> V_42 ,
V_24 -> V_41 ) ;
}
if ( ! ( V_24 -> V_29 & ( V_194 |
V_422 ) ) &&
( V_24 -> V_29 & V_420 ) &&
V_2 -> V_423 < V_24 -> V_25 &&
V_14 == V_24 -> V_14 [ V_2 -> V_423 ] )
return;
if ( V_2 -> type == V_9 &&
( ! F_47 ( V_2 -> V_10 , V_130 -> V_424 ) ) == V_14 )
F_54 ( V_130 , V_230 , V_413 , V_2 -> V_5 ) ;
F_54 ( V_130 , V_2 -> type , V_2 -> V_10 , V_14 ) ;
if ( ( V_24 -> V_29 & V_194 ) &&
V_2 -> type == V_9 && V_14 ) {
F_55 ( V_130 ) ;
F_54 ( V_130 , V_2 -> type , V_2 -> V_10 , 0 ) ;
}
}
void F_57 ( struct V_12 * V_5 , struct V_19 * V_20 )
{
struct V_128 * V_129 ;
if ( V_5 -> V_64 & V_425 )
return;
F_5 (hidinput, &hid->inputs, list)
F_55 ( V_129 -> V_130 ) ;
}
int F_58 ( struct V_12 * V_5 , unsigned int type , unsigned int V_10 , struct V_38 * * V_24 )
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
struct V_38 * F_59 ( struct V_12 * V_5 )
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
if ( V_24 -> V_2 [ V_17 ] . type == V_426 )
return V_24 ;
}
}
return NULL ;
}
unsigned int F_60 ( struct V_12 * V_5 )
{
struct V_19 * V_20 ;
struct V_38 * V_24 ;
int V_16 , V_17 ;
unsigned int V_418 = 0 ;
F_5 (report,
&hid->report_enum[HID_OUTPUT_REPORT].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ ) {
V_24 = V_20 -> V_24 [ V_16 ] ;
for ( V_17 = 0 ; V_17 < V_24 -> V_25 ; V_17 ++ )
if ( V_24 -> V_2 [ V_17 ] . type == V_426 &&
V_24 -> V_14 [ V_17 ] )
V_418 += 1 ;
}
}
return V_418 ;
}
static void F_61 ( struct V_427 * V_428 )
{
struct V_12 * V_5 = F_62 ( V_428 , struct V_12 ,
V_429 ) ;
struct V_38 * V_24 ;
struct V_19 * V_20 ;
int V_34 , V_71 ;
T_6 * V_70 ;
V_24 = F_59 ( V_5 ) ;
if ( ! V_24 )
return;
V_20 = V_24 -> V_20 ;
if ( V_5 -> V_430 -> V_431 )
return V_5 -> V_430 -> V_431 ( V_5 , V_20 , V_432 ) ;
V_34 = F_63 ( V_20 ) ;
V_70 = F_64 ( V_20 , V_72 ) ;
if ( ! V_70 )
return;
F_65 ( V_20 , V_70 ) ;
V_71 = F_66 ( V_5 , V_70 , V_34 ) ;
if ( V_71 == - V_433 )
F_21 ( V_5 , V_20 -> V_124 , V_70 , V_34 , V_22 ,
V_432 ) ;
F_22 ( V_70 ) ;
}
static int F_67 ( struct V_31 * V_32 , unsigned int type ,
unsigned int V_10 , int V_14 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
struct V_38 * V_24 ;
int V_434 ;
if ( type == V_435 )
return F_68 ( V_32 , type , V_10 , V_14 ) ;
if ( type != V_426 )
return - 1 ;
if ( ( V_434 = F_58 ( V_5 , type , V_10 , & V_24 ) ) == - 1 ) {
F_34 ( V_32 , L_8 ) ;
return - 1 ;
}
F_69 ( V_24 , V_434 , V_14 ) ;
F_70 ( & V_5 -> V_429 ) ;
return 0 ;
}
static int F_71 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
return F_72 ( V_5 ) ;
}
static void F_73 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
F_74 ( V_5 ) ;
}
static void F_75 ( struct V_12 * V_5 )
{
struct V_436 * V_437 = V_5 -> V_137 ;
struct V_438 * V_439 ;
struct V_19 * V_440 ;
struct V_1 * V_2 ;
int V_16 , V_17 ;
V_439 = & V_5 -> V_441 [ V_88 ] ;
F_5 (rep, &rep_enum->report_list, list)
for ( V_16 = 0 ; V_16 < V_440 -> V_23 ; V_16 ++ ) {
if ( V_440 -> V_24 [ V_16 ] -> V_135 < 1 )
continue;
for ( V_17 = 0 ; V_17 < V_440 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ ) {
V_2 = & V_440 -> V_24 [ V_16 ] -> V_2 [ V_17 ] ;
if ( V_2 -> V_5 == V_386 )
F_25 ( V_5 , V_88 ,
V_440 -> V_24 [ V_16 ] ) ;
if ( V_437 -> V_442 )
V_437 -> V_442 ( V_5 , V_440 -> V_24 [ V_16 ] , V_2 ) ;
}
}
}
static struct V_128 * F_76 ( struct V_12 * V_5 )
{
struct V_128 * V_129 = F_27 ( sizeof( * V_129 ) , V_72 ) ;
struct V_31 * V_31 = F_77 () ;
if ( ! V_129 || ! V_31 ) {
F_22 ( V_129 ) ;
F_78 ( V_31 ) ;
F_79 ( V_5 , L_9 ) ;
return NULL ;
}
F_80 ( V_31 , V_5 ) ;
V_31 -> V_443 = F_67 ;
V_31 -> V_444 = F_71 ;
V_31 -> V_445 = F_73 ;
V_31 -> V_446 = F_10 ;
V_31 -> V_447 = F_8 ;
V_31 -> V_92 = V_5 -> V_92 ;
V_31 -> V_448 = V_5 -> V_448 ;
V_31 -> V_114 = V_5 -> V_114 ;
V_31 -> V_124 . V_449 = V_5 -> V_109 ;
V_31 -> V_124 . V_110 = V_5 -> V_110 ;
V_31 -> V_124 . V_111 = V_5 -> V_111 ;
V_31 -> V_124 . V_112 = V_5 -> V_112 ;
V_31 -> V_32 . V_450 = & V_5 -> V_32 ;
V_129 -> V_130 = V_31 ;
F_81 ( & V_129 -> V_451 , & V_5 -> V_452 ) ;
return V_129 ;
}
static bool F_82 ( struct V_128 * V_129 )
{
int V_16 ;
unsigned long V_453 = 0 ;
for ( V_16 = 0 ; V_16 < F_83 ( V_454 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_143 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_83 ( V_455 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_37 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_83 ( V_456 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_457 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_83 ( V_458 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_412 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_83 ( V_459 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_232 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_83 ( V_460 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_461 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_83 ( V_462 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_463 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_83 ( V_464 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_465 [ V_16 ] ;
for ( V_16 = 0 ; V_16 < F_83 ( V_466 ) ; V_16 ++ )
V_453 |= V_129 -> V_130 -> V_467 [ V_16 ] ;
return ! ! V_453 ;
}
static void F_84 ( struct V_12 * V_5 ,
struct V_128 * V_129 )
{
struct V_19 * V_20 ;
int V_16 , V_18 ;
F_85 ( & V_129 -> V_451 ) ;
F_78 ( V_129 -> V_130 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_64 & V_468 )
continue;
F_5 (report, &hid->report_enum[k].report_list,
list) {
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
if ( V_20 -> V_24 [ V_16 ] -> V_129 == V_129 )
V_20 -> V_24 [ V_16 ] -> V_129 = NULL ;
}
}
F_22 ( V_129 ) ;
}
static struct V_128 * F_86 ( struct V_19 * V_20 )
{
struct V_12 * V_5 = V_20 -> V_131 ;
struct V_128 * V_129 ;
F_5 (hidinput, &hid->inputs, list) {
if ( V_129 -> V_20 &&
V_129 -> V_20 -> V_124 == V_20 -> V_124 )
return V_129 ;
}
return NULL ;
}
static inline void F_87 ( struct V_128 * V_129 ,
struct V_19 * V_20 )
{
int V_16 , V_17 ;
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_20 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ )
F_40 ( V_129 , V_20 -> V_24 [ V_16 ] ,
V_20 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
}
int F_88 ( struct V_12 * V_5 , unsigned int V_469 )
{
struct V_436 * V_437 = V_5 -> V_137 ;
struct V_19 * V_20 ;
struct V_128 * V_470 , * V_129 = NULL ;
int V_16 , V_18 ;
F_89 ( & V_5 -> V_452 ) ;
F_90 ( & V_5 -> V_429 , F_61 ) ;
if ( ! V_469 ) {
for ( V_16 = 0 ; V_16 < V_5 -> V_471 ; V_16 ++ ) {
struct V_472 * V_473 = & V_5 -> V_474 [ V_16 ] ;
if ( V_473 -> type == V_475 ||
V_473 -> type == V_476 )
if ( F_91 ( V_473 -> V_2 ) )
break;
}
if ( V_16 == V_5 -> V_471 )
return - 1 ;
}
F_75 ( V_5 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_64 & V_468 )
continue;
F_5 (report, &hid->report_enum[k].report_list, list) {
if ( ! V_20 -> V_23 )
continue;
if ( V_5 -> V_64 & V_477 )
V_129 = F_86 ( V_20 ) ;
if ( ! V_129 ) {
V_129 = F_76 ( V_5 ) ;
if ( ! V_129 )
goto V_478;
}
F_87 ( V_129 , V_20 ) ;
if ( V_5 -> V_64 & V_477 )
V_129 -> V_20 = V_20 ;
}
}
F_92 (hidinput, next, &hid->inputs, list) {
if ( ( V_5 -> V_64 & V_479 ) &&
! F_82 ( V_129 ) ) {
F_84 ( V_5 , V_129 ) ;
continue;
}
if ( V_437 -> V_480 &&
V_437 -> V_480 ( V_5 , V_129 ) )
goto V_478;
if ( F_93 ( V_129 -> V_130 ) )
goto V_478;
V_129 -> V_481 = true ;
}
if ( F_94 ( & V_5 -> V_452 ) ) {
F_79 ( V_5 , L_10 ) ;
goto V_478;
}
return 0 ;
V_478:
F_95 ( V_5 ) ;
return - 1 ;
}
void F_95 ( struct V_12 * V_5 )
{
struct V_128 * V_129 , * V_470 ;
F_36 ( V_5 ) ;
F_92 (hidinput, next, &hid->inputs, list) {
F_85 ( & V_129 -> V_451 ) ;
if ( V_129 -> V_481 )
F_96 ( V_129 -> V_130 ) ;
else
F_78 ( V_129 -> V_130 ) ;
F_22 ( V_129 ) ;
}
F_97 ( & V_5 -> V_429 ) ;
}
