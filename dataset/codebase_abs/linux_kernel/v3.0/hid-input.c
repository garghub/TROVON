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
static void F_15 ( struct V_54 * V_55 , struct V_38 * V_24 ,
struct V_1 * V_2 )
{
struct V_31 * V_56 = V_55 -> V_56 ;
struct V_12 * V_57 = F_9 ( V_56 ) ;
int V_58 = 0 , V_10 ;
unsigned long * V_59 = NULL ;
V_24 -> V_55 = V_55 ;
if ( V_24 -> V_29 & V_60 )
goto V_61;
if ( V_24 -> V_62 == V_22 &&
( V_2 -> V_5 & V_6 ) != V_63 ) {
goto V_61;
}
if ( V_57 -> V_64 -> V_65 ) {
int V_66 = V_57 -> V_64 -> V_65 ( V_57 , V_55 , V_24 ,
V_2 , & V_59 , & V_58 ) ;
if ( V_66 > 0 )
goto V_67;
if ( V_66 < 0 )
goto V_61;
}
switch ( V_2 -> V_5 & V_6 ) {
case V_68 :
goto V_61;
case V_69 :
F_12 ( V_70 , V_56 -> V_71 ) ;
if ( ( V_2 -> V_5 & V_7 ) < 256 ) {
if ( ! V_72 [ V_2 -> V_5 & V_7 ] ) goto V_61;
F_16 ( V_72 [ V_2 -> V_5 & V_7 ] ) ;
} else
F_17 ( V_73 ) ;
break;
case V_74 :
V_10 = ( ( V_2 -> V_5 - 1 ) & V_7 ) ;
switch ( V_24 -> V_75 ) {
case V_76 :
case V_77 : V_10 += V_78 ; break;
case V_79 :
if ( V_10 <= 0xf )
V_10 += V_80 ;
else
V_10 += V_81 ;
break;
case V_82 : V_10 += V_83 ; break;
default:
switch ( V_24 -> V_84 ) {
case V_76 :
case V_77 : V_10 += V_78 ; break;
case V_79 : V_10 += V_80 ; break;
case V_82 : V_10 += V_83 ; break;
default: V_10 += V_85 ;
}
}
F_17 ( V_10 ) ;
break;
case V_86 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0xba : F_18 ( V_87 ) ; break;
case 0xbb : F_18 ( V_88 ) ; break;
case 0xc4 : F_18 ( V_89 ) ; break;
case 0xc5 : F_18 ( V_90 ) ; break;
case 0xc8 : F_18 ( V_91 ) ; break;
default: goto V_61;
}
break;
case V_92 :
if ( ( V_2 -> V_5 & 0xf0 ) == 0x80 ) {
switch ( V_2 -> V_5 & 0xf ) {
case 0x1 : F_16 ( V_93 ) ; break;
case 0x2 : F_16 ( V_94 ) ; break;
case 0x3 : F_16 ( V_95 ) ; break;
case 0x4 : F_16 ( V_96 ) ; break;
case 0x5 : F_16 ( V_97 ) ; break;
case 0x6 : F_16 ( V_98 ) ; break;
case 0x7 : F_16 ( V_99 ) ; break;
case 0x8 : F_16 ( V_100 ) ; break;
case 0x9 : F_16 ( V_101 ) ; break;
case 0xa : F_16 ( V_102 ) ; break;
case 0xb : F_16 ( V_103 ) ; break;
case 0xc : F_16 ( V_104 ) ; break;
case 0xd : F_16 ( V_105 ) ; break;
case 0xe : F_16 ( V_106 ) ; break;
case 0xf : F_16 ( V_107 ) ; break;
default: goto V_108;
}
break;
}
if ( ( V_2 -> V_5 & 0xf0 ) == 0x90 ) {
switch ( V_2 -> V_5 ) {
case V_109 : V_2 -> V_110 = 1 ; break;
case V_111 : V_2 -> V_110 = 5 ; break;
case V_112 : V_2 -> V_110 = 3 ; break;
case V_113 : V_2 -> V_110 = 7 ; break;
default: goto V_108;
}
if ( V_24 -> V_114 ) {
F_18 ( V_24 -> V_114 ) ;
goto V_61;
}
F_18 ( V_115 ) ;
break;
}
switch ( V_2 -> V_5 ) {
case V_116 : case V_117 : case V_118 :
case V_119 : case V_120 : case V_121 :
case V_122 : case V_123 : case V_124 :
if ( V_24 -> V_29 & V_125 )
F_19 ( V_2 -> V_5 & 0xf ) ;
else
F_18 ( V_2 -> V_5 & 0xf ) ;
break;
case V_126 :
V_2 -> V_127 = V_24 -> V_42 ;
V_2 -> V_128 = V_24 -> V_41 ;
F_18 ( V_115 ) ;
break;
case V_129 : F_16 ( V_130 ) ; break;
case V_131 : F_16 ( V_132 ) ; break;
default: goto V_108;
}
break;
case V_63 :
switch ( V_2 -> V_5 & 0xffff ) {
case 0x01 : F_20 ( V_133 ) ; break;
case 0x02 : F_20 ( V_134 ) ; break;
case 0x03 : F_20 ( V_135 ) ; break;
case 0x04 : F_20 ( V_136 ) ; break;
case 0x05 : F_20 ( V_137 ) ; break;
case 0x27 : F_20 ( V_138 ) ; break;
case 0x4c : F_20 ( V_139 ) ; break;
case 0x09 : F_20 ( V_140 ) ; break;
case 0x4b : F_20 ( V_141 ) ; break;
case 0x19 : F_20 ( V_142 ) ; break;
case 0x4d : F_20 ( V_143 ) ; break;
default: goto V_61;
}
break;
case V_144 :
switch ( V_2 -> V_5 & 0xff ) {
case 0x00 :
goto V_61;
case 0x30 :
if ( ! F_21 ( V_145 , V_56 -> V_37 ) ) {
V_57 -> V_146 |= V_147 ;
F_12 ( V_9 , V_56 -> V_71 ) ;
F_12 ( V_145 , V_56 -> V_37 ) ;
}
F_22 ( V_148 ) ;
break;
case 0x32 :
switch ( V_24 -> V_84 & 0xff ) {
case 0x21 : F_17 ( V_149 ) ; break;
case 0x22 : F_17 ( V_150 ) ; break;
default: F_17 ( V_151 ) ; break;
}
break;
case 0x3c :
F_16 ( V_152 ) ;
break;
case 0x33 :
case 0x42 :
case 0x43 :
V_57 -> V_146 &= ~ V_147 ;
F_16 ( V_145 ) ;
break;
case 0x44 :
F_16 ( V_153 ) ;
break;
case 0x46 :
F_16 ( V_154 ) ;
break;
default: goto V_108;
}
break;
case V_155 :
switch ( V_2 -> V_5 & V_7 ) {
case 0x000 : goto V_61;
case 0x030 : F_16 ( V_93 ) ; break;
case 0x031 : F_16 ( V_107 ) ; break;
case 0x032 : F_16 ( V_94 ) ; break;
case 0x034 : F_16 ( V_94 ) ; break;
case 0x035 : F_16 ( V_156 ) ; break;
case 0x036 : F_16 ( V_85 ) ; break;
case 0x040 : F_16 ( V_97 ) ; break;
case 0x041 : F_16 ( V_101 ) ; break;
case 0x042 : F_16 ( V_104 ) ; break;
case 0x043 : F_16 ( V_105 ) ; break;
case 0x044 : F_16 ( V_103 ) ; break;
case 0x045 : F_16 ( V_102 ) ; break;
case 0x046 : F_16 ( V_157 ) ; break;
case 0x047 : F_16 ( V_158 ) ; break;
case 0x048 : F_16 ( V_159 ) ; break;
case 0x060 : F_16 ( V_160 ) ; break;
case 0x061 : F_16 ( V_161 ) ; break;
case 0x063 : F_16 ( V_162 ) ; break;
case 0x065 : F_16 ( V_163 ) ; break;
case 0x069 : F_16 ( V_164 ) ; break;
case 0x06a : F_16 ( V_165 ) ; break;
case 0x06b : F_16 ( V_166 ) ; break;
case 0x06c : F_16 ( V_167 ) ; break;
case 0x06d : F_16 ( V_168 ) ; break;
case 0x082 : F_16 ( V_169 ) ; break;
case 0x083 : F_16 ( V_170 ) ; break;
case 0x084 : F_16 ( V_171 ) ; break;
case 0x088 : F_16 ( V_172 ) ; break;
case 0x089 : F_16 ( V_173 ) ; break;
case 0x08a : F_16 ( V_174 ) ; break;
case 0x08b : F_16 ( V_175 ) ; break;
case 0x08c : F_16 ( V_176 ) ; break;
case 0x08d : F_16 ( V_177 ) ; break;
case 0x08e : F_16 ( V_178 ) ; break;
case 0x08f : F_16 ( V_179 ) ; break;
case 0x090 : F_16 ( V_180 ) ; break;
case 0x091 : F_16 ( V_181 ) ; break;
case 0x092 : F_16 ( V_162 ) ; break;
case 0x093 : F_16 ( V_182 ) ; break;
case 0x094 : F_16 ( V_100 ) ; break;
case 0x095 : F_16 ( V_99 ) ; break;
case 0x096 : F_16 ( V_183 ) ; break;
case 0x097 : F_16 ( V_184 ) ; break;
case 0x098 : F_16 ( V_185 ) ; break;
case 0x09a : F_16 ( V_186 ) ; break;
case 0x09c : F_16 ( V_187 ) ; break;
case 0x09d : F_16 ( V_188 ) ; break;
case 0x0a0 : F_16 ( V_189 ) ; break;
case 0x0b0 : F_16 ( V_190 ) ; break;
case 0x0b1 : F_16 ( V_191 ) ; break;
case 0x0b2 : F_16 ( V_192 ) ; break;
case 0x0b3 : F_16 ( V_193 ) ; break;
case 0x0b4 : F_16 ( V_194 ) ; break;
case 0x0b5 : F_16 ( V_195 ) ; break;
case 0x0b6 : F_16 ( V_196 ) ; break;
case 0x0b7 : F_16 ( V_197 ) ; break;
case 0x0b8 : F_16 ( V_198 ) ; break;
case 0x0bc : F_16 ( V_199 ) ; break;
case 0x0b9 : F_16 ( V_200 ) ; break;
case 0x0bf : F_16 ( V_201 ) ; break;
case 0x0cd : F_16 ( V_202 ) ; break;
case 0x0e0 : F_22 ( V_203 ) ; break;
case 0x0e2 : F_16 ( V_204 ) ; break;
case 0x0e5 : F_16 ( V_205 ) ; break;
case 0x0e9 : F_16 ( V_206 ) ; break;
case 0x0ea : F_16 ( V_207 ) ; break;
case 0x0f5 : F_16 ( V_201 ) ; break;
case 0x182 : F_16 ( V_208 ) ; break;
case 0x183 : F_16 ( V_209 ) ; break;
case 0x184 : F_16 ( V_210 ) ; break;
case 0x185 : F_16 ( V_211 ) ; break;
case 0x186 : F_16 ( V_212 ) ; break;
case 0x187 : F_16 ( V_213 ) ; break;
case 0x188 : F_16 ( V_214 ) ; break;
case 0x189 : F_16 ( V_215 ) ; break;
case 0x18a : F_16 ( V_216 ) ; break;
case 0x18b : F_16 ( V_217 ) ; break;
case 0x18c : F_16 ( V_218 ) ; break;
case 0x18d : F_16 ( V_219 ) ; break;
case 0x18e : F_16 ( V_220 ) ; break;
case 0x191 : F_16 ( V_221 ) ; break;
case 0x192 : F_16 ( V_222 ) ; break;
case 0x193 : F_16 ( V_223 ) ; break;
case 0x194 : F_16 ( V_224 ) ; break;
case 0x196 : F_16 ( V_174 ) ; break;
case 0x199 : F_16 ( V_225 ) ; break;
case 0x19c : F_16 ( V_226 ) ; break;
case 0x19e : F_16 ( V_227 ) ; break;
case 0x1a6 : F_16 ( V_99 ) ; break;
case 0x1a7 : F_16 ( V_228 ) ; break;
case 0x1ab : F_16 ( V_229 ) ; break;
case 0x1ae : F_16 ( V_230 ) ; break;
case 0x1b6 : F_16 ( V_231 ) ; break;
case 0x1b7 : F_16 ( V_232 ) ; break;
case 0x1b8 : F_16 ( V_233 ) ; break;
case 0x1bc : F_16 ( V_234 ) ; break;
case 0x1bd : F_16 ( V_160 ) ; break;
case 0x201 : F_16 ( V_235 ) ; break;
case 0x202 : F_16 ( V_236 ) ; break;
case 0x203 : F_16 ( V_237 ) ; break;
case 0x204 : F_16 ( V_100 ) ; break;
case 0x207 : F_16 ( V_238 ) ; break;
case 0x208 : F_16 ( V_239 ) ; break;
case 0x209 : F_16 ( V_240 ) ; break;
case 0x21a : F_16 ( V_241 ) ; break;
case 0x21b : F_16 ( V_242 ) ; break;
case 0x21c : F_16 ( V_243 ) ; break;
case 0x21d : F_16 ( V_244 ) ; break;
case 0x21f : F_16 ( V_245 ) ; break;
case 0x221 : F_16 ( V_246 ) ; break;
case 0x222 : F_16 ( V_247 ) ; break;
case 0x223 : F_16 ( V_248 ) ; break;
case 0x224 : F_16 ( V_249 ) ; break;
case 0x225 : F_16 ( V_250 ) ; break;
case 0x226 : F_16 ( V_251 ) ; break;
case 0x227 : F_16 ( V_252 ) ; break;
case 0x22a : F_16 ( V_208 ) ; break;
case 0x22d : F_16 ( V_253 ) ; break;
case 0x22e : F_16 ( V_254 ) ; break;
case 0x22f : F_16 ( V_255 ) ; break;
case 0x233 : F_16 ( V_256 ) ; break;
case 0x234 : F_16 ( V_257 ) ; break;
case 0x238 : F_19 ( V_258 ) ; break;
case 0x23d : F_16 ( V_259 ) ; break;
case 0x25f : F_16 ( V_260 ) ; break;
case 0x269 : F_16 ( V_261 ) ; break;
case 0x26a : F_16 ( V_262 ) ; break;
case 0x279 : F_16 ( V_263 ) ; break;
case 0x289 : F_16 ( V_264 ) ; break;
case 0x28b : F_16 ( V_265 ) ; break;
case 0x28c : F_16 ( V_266 ) ; break;
default: goto V_61;
}
break;
case V_267 :
F_12 ( V_70 , V_56 -> V_71 ) ;
switch ( V_2 -> V_5 & V_7 ) {
case 0x021 : F_16 ( V_239 ) ; break;
case 0x070 : F_16 ( V_268 ) ; break;
case 0x071 : F_16 ( V_163 ) ; break;
case 0x072 : F_16 ( V_269 ) ; break;
case 0x073 : F_16 ( V_270 ) ; break;
case 0x080 : F_16 ( V_271 ) ; break;
case 0x081 : F_16 ( V_225 ) ; break;
case 0x082 : F_16 ( V_246 ) ; break;
case 0x083 : F_16 ( V_272 ) ; break;
case 0x084 : F_16 ( V_221 ) ; break;
case 0x085 : F_16 ( V_273 ) ; break;
case 0x086 : F_16 ( V_274 ) ; break;
default: goto V_61;
}
break;
case V_275 :
goto V_61;
case V_276 :
F_12 ( V_70 , V_56 -> V_71 ) ;
goto V_61;
case V_277 :
goto V_61;
case V_278 :
switch ( V_2 -> V_5 & V_7 ) {
case 0xa4 : F_16 ( V_279 ) ; break;
default: goto V_61;
}
break;
default:
V_108:
if ( V_24 -> V_280 == 1 ) {
if ( V_24 -> V_20 -> type == V_22 ) {
F_20 ( V_141 ) ;
break;
}
F_17 ( V_85 ) ;
break;
}
if ( V_24 -> V_29 & V_125 ) {
F_19 ( V_281 ) ;
break;
}
F_18 ( V_282 ) ;
break;
}
V_67:
if ( V_57 -> V_64 -> V_283 && V_57 -> V_64 -> V_283 ( V_57 ,
V_55 , V_24 , V_2 , & V_59 , & V_58 ) < 0 )
goto V_61;
F_12 ( V_2 -> type , V_56 -> V_71 ) ;
while ( V_2 -> V_10 <= V_58 && F_23 ( V_2 -> V_10 , V_59 ) )
V_2 -> V_10 = F_24 ( V_59 , V_58 + 1 , V_2 -> V_10 ) ;
if ( V_2 -> V_10 > V_58 )
goto V_61;
if ( V_2 -> type == V_284 ) {
int V_285 = V_24 -> V_42 ;
int V_286 = V_24 -> V_41 ;
if ( ( V_57 -> V_146 & V_287 ) && ( V_2 -> V_10 == V_47 || V_2 -> V_10 == V_48 ) ) {
V_285 = V_24 -> V_42 = 0 ;
V_286 = V_24 -> V_41 = 255 ;
}
if ( V_24 -> V_75 == V_82 || V_24 -> V_75 == V_79 )
F_25 ( V_56 , V_2 -> V_10 , V_285 , V_286 , ( V_286 - V_285 ) >> 8 , ( V_286 - V_285 ) >> 4 ) ;
else F_25 ( V_56 , V_2 -> V_10 , V_285 , V_286 , 0 , 0 ) ;
F_26 ( V_56 , V_2 -> V_10 ,
F_14 ( V_24 , V_2 -> V_10 ) ) ;
if ( V_2 -> V_10 == V_288 && V_56 -> V_289 == 0 )
F_27 ( V_56 , 60 ) ;
}
if ( V_2 -> type == V_284 &&
( V_2 -> V_127 < V_2 -> V_128 || V_2 -> V_110 ) ) {
int V_16 ;
for ( V_16 = V_2 -> V_10 ; V_16 < V_2 -> V_10 + 2 && V_16 <= V_58 ; V_16 ++ ) {
F_25 ( V_56 , V_16 , - 1 , 1 , 0 , 0 ) ;
F_12 ( V_16 , V_56 -> V_290 ) ;
}
if ( V_2 -> V_110 && ! V_24 -> V_114 )
V_24 -> V_114 = V_2 -> V_10 ;
}
if ( ( V_2 -> type == V_284 ) && ( V_24 -> V_29 & V_125 ) &&
( V_2 -> V_10 == V_203 ) ) {
F_12 ( V_206 , V_56 -> V_37 ) ;
F_12 ( V_207 , V_56 -> V_37 ) ;
}
if ( V_2 -> type == V_9 ) {
F_12 ( V_291 , V_56 -> V_71 ) ;
F_12 ( V_292 , V_56 -> V_293 ) ;
}
V_61:
return;
}
void F_28 ( struct V_12 * V_5 , struct V_38 * V_24 , struct V_1 * V_2 , T_2 V_14 )
{
struct V_31 * V_56 ;
unsigned * V_146 = & V_5 -> V_146 ;
if ( ! V_24 -> V_55 )
return;
V_56 = V_24 -> V_55 -> V_56 ;
if ( ! V_2 -> type )
return;
if ( V_2 -> V_127 < V_2 -> V_128 || V_2 -> V_110 ) {
int V_110 = V_2 -> V_110 ;
if ( ! V_110 )
V_110 = ( V_14 - V_2 -> V_127 ) * 8 / ( V_2 -> V_128 - V_2 -> V_127 + 1 ) + 1 ;
if ( V_110 < 0 || V_110 > 8 ) V_110 = 0 ;
F_29 ( V_56 , V_2 -> type , V_2 -> V_10 , V_294 [ V_110 ] . V_295 ) ;
F_29 ( V_56 , V_2 -> type , V_2 -> V_10 + 1 , V_294 [ V_110 ] . V_296 ) ;
return;
}
if ( V_2 -> V_5 == ( V_144 | 0x003c ) ) {
* V_146 = V_14 ? ( * V_146 | V_297 ) : ( * V_146 & ~ V_297 ) ;
return;
}
if ( V_2 -> V_5 == ( V_144 | 0x0032 ) ) {
if ( V_14 ) {
F_29 ( V_56 , V_2 -> type , ( * V_146 & V_297 ) ? V_152 : V_2 -> V_10 , 1 ) ;
return;
}
F_29 ( V_56 , V_2 -> type , V_2 -> V_10 , 0 ) ;
F_29 ( V_56 , V_2 -> type , V_152 , 0 ) ;
return;
}
if ( V_2 -> V_5 == ( V_144 | 0x0030 ) && ( * V_146 & V_147 ) ) {
int V_285 = V_24 -> V_42 ;
int V_286 = V_24 -> V_41 ;
F_29 ( V_56 , V_9 , V_145 , V_14 > V_285 + ( ( V_286 - V_285 ) >> 3 ) ) ;
}
if ( V_2 -> V_5 == ( V_278 | 0x83UL ) ) {
F_13 ( L_2 , V_14 ) ;
return;
}
if ( V_2 -> V_5 == ( V_278 | 0x7fUL ) ) {
F_13 ( L_3 ) ;
return;
}
if ( ( V_2 -> type == V_9 ) && ( V_2 -> V_10 == 0 ) )
return;
if ( ( V_2 -> type == V_284 ) && ( V_24 -> V_29 & V_125 ) &&
( V_2 -> V_10 == V_203 ) ) {
int V_298 = abs ( V_14 ) ;
int V_299 = V_14 > 0 ? V_206 : V_207 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_298 ; V_16 ++ ) {
F_29 ( V_56 , V_9 , V_299 , 1 ) ;
F_30 ( V_56 ) ;
F_29 ( V_56 , V_9 , V_299 , 0 ) ;
F_30 ( V_56 ) ;
}
return;
}
if ( V_2 -> type == V_9 && ! ! F_21 ( V_2 -> V_10 , V_56 -> V_300 ) != V_14 )
F_29 ( V_56 , V_291 , V_292 , V_2 -> V_5 ) ;
F_29 ( V_56 , V_2 -> type , V_2 -> V_10 , V_14 ) ;
if ( ( V_24 -> V_29 & V_125 ) && ( V_2 -> type == V_9 ) )
F_29 ( V_56 , V_2 -> type , V_2 -> V_10 , 0 ) ;
}
void F_31 ( struct V_12 * V_5 , struct V_19 * V_20 )
{
struct V_54 * V_55 ;
if ( V_5 -> V_146 & V_301 )
return;
F_5 (hidinput, &hid->inputs, list)
F_30 ( V_55 -> V_56 ) ;
}
int F_32 ( struct V_12 * V_5 , unsigned int type , unsigned int V_10 , struct V_38 * * V_24 )
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
static int F_33 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
return F_34 ( V_5 ) ;
}
static void F_35 ( struct V_31 * V_32 )
{
struct V_12 * V_5 = F_9 ( V_32 ) ;
F_36 ( V_5 ) ;
}
static void F_37 ( struct V_12 * V_5 )
{
struct V_302 * V_303 = V_5 -> V_64 ;
struct V_304 * V_305 ;
struct V_19 * V_306 ;
int V_16 , V_17 ;
if ( ! V_303 -> V_307 )
return;
V_305 = & V_5 -> V_308 [ V_309 ] ;
F_5 (rep, &rep_enum->report_list, list)
for ( V_16 = 0 ; V_16 < V_306 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_306 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ )
V_303 -> V_307 ( V_5 , V_306 -> V_24 [ V_16 ] ,
V_306 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
}
int F_38 ( struct V_12 * V_5 , unsigned int V_310 )
{
struct V_19 * V_20 ;
struct V_54 * V_55 = NULL ;
struct V_31 * V_31 ;
int V_16 , V_17 , V_18 ;
F_39 ( & V_5 -> V_311 ) ;
if ( ! V_310 ) {
for ( V_16 = 0 ; V_16 < V_5 -> V_312 ; V_16 ++ ) {
struct V_313 * V_314 = & V_5 -> V_315 [ V_16 ] ;
if ( V_314 -> type == V_316 ||
V_314 -> type == V_317 )
if ( F_40 ( V_314 -> V_2 ) )
break;
}
if ( V_16 == V_5 -> V_312 )
return - 1 ;
}
F_37 ( V_5 ) ;
for ( V_18 = V_21 ; V_18 <= V_22 ; V_18 ++ ) {
if ( V_18 == V_22 &&
V_5 -> V_146 & V_318 )
continue;
F_5 (report, &hid->report_enum[k].report_list, list) {
if ( ! V_20 -> V_23 )
continue;
if ( ! V_55 ) {
V_55 = F_41 ( sizeof( * V_55 ) , V_319 ) ;
V_31 = F_42 () ;
if ( ! V_55 || ! V_31 ) {
F_43 ( V_55 ) ;
F_44 ( V_31 ) ;
F_45 ( V_5 , L_4 ) ;
goto V_320;
}
F_46 ( V_31 , V_5 ) ;
V_31 -> V_321 =
V_5 -> V_322 -> V_323 ;
V_31 -> V_324 = F_33 ;
V_31 -> V_325 = F_35 ;
V_31 -> V_326 = F_10 ;
V_31 -> V_327 = F_8 ;
V_31 -> V_328 = V_5 -> V_328 ;
V_31 -> V_329 = V_5 -> V_329 ;
V_31 -> V_330 = V_5 -> V_330 ;
V_31 -> V_331 . V_332 = V_5 -> V_333 ;
V_31 -> V_331 . V_334 = V_5 -> V_334 ;
V_31 -> V_331 . V_335 = V_5 -> V_335 ;
V_31 -> V_331 . V_336 = V_5 -> V_336 ;
V_31 -> V_32 . V_337 = V_5 -> V_32 . V_337 ;
V_55 -> V_56 = V_31 ;
F_47 ( & V_55 -> V_338 , & V_5 -> V_311 ) ;
}
for ( V_16 = 0 ; V_16 < V_20 -> V_23 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < V_20 -> V_24 [ V_16 ] -> V_25 ; V_17 ++ )
F_15 ( V_55 , V_20 -> V_24 [ V_16 ] ,
V_20 -> V_24 [ V_16 ] -> V_2 + V_17 ) ;
if ( V_5 -> V_146 & V_339 ) {
V_55 -> V_20 = V_20 ;
if ( F_48 ( V_55 -> V_56 ) )
goto V_340;
V_55 = NULL ;
}
}
}
if ( V_55 && F_48 ( V_55 -> V_56 ) )
goto V_340;
return 0 ;
V_340:
F_49 ( & V_55 -> V_338 ) ;
F_44 ( V_55 -> V_56 ) ;
F_43 ( V_55 ) ;
V_320:
F_50 ( V_5 ) ;
return - 1 ;
}
void F_50 ( struct V_12 * V_5 )
{
struct V_54 * V_55 , * V_341 ;
F_51 (hidinput, next, &hid->inputs, list) {
F_49 ( & V_55 -> V_338 ) ;
F_52 ( V_55 -> V_56 ) ;
F_43 ( V_55 ) ;
}
}
