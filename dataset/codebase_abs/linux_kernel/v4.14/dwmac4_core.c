static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
V_6 |= V_8 ;
if ( V_3 > 1500 )
V_6 |= V_9 ;
if ( V_3 > 2000 )
V_6 |= V_10 ;
if ( V_2 -> V_11 ) {
V_6 |= V_12 ;
V_6 &= V_2 -> V_13 . V_14 ;
switch ( V_2 -> V_11 ) {
case V_15 :
V_6 |= V_2 -> V_13 . V_16 ;
break;
case V_17 :
V_6 |= V_2 -> V_13 . V_18 ;
break;
case V_19 :
V_6 |= V_2 -> V_13 . V_20 ;
break;
}
}
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = V_21 ;
if ( V_2 -> V_22 )
V_6 |= V_23 ;
if ( V_2 -> V_24 )
V_6 |= V_25 ;
F_3 ( V_6 , V_4 + V_26 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_3 V_27 , T_2 V_28 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_29 ) ;
V_6 &= F_5 ( V_28 ) ;
if ( V_27 == V_30 )
V_6 |= F_6 ( V_28 ) ;
else if ( V_27 == V_31 )
V_6 |= F_7 ( V_28 ) ;
F_3 ( V_6 , V_4 + V_29 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
T_2 V_32 , T_2 V_28 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_33 ;
T_2 V_6 ;
V_33 = ( V_28 < 4 ) ? V_34 : V_35 ;
V_6 = F_2 ( V_4 + V_33 ) ;
V_6 &= ~ F_9 ( V_28 ) ;
V_6 |= ( V_32 << F_10 ( V_28 ) ) &
F_9 ( V_28 ) ;
F_3 ( V_6 , V_4 + V_33 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_2 V_32 , T_2 V_28 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_33 ;
T_2 V_6 ;
V_33 = ( V_28 < 4 ) ? V_36 : V_37 ;
V_6 = F_2 ( V_4 + V_33 ) ;
V_6 &= ~ F_12 ( V_28 ) ;
V_6 |= ( V_32 << F_13 ( V_28 ) ) &
F_12 ( V_28 ) ;
F_3 ( V_6 , V_4 + V_33 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
T_3 V_38 , T_2 V_28 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
static const struct V_39 V_40 [] = {
{ V_41 , V_42 } ,
{ V_43 , V_44 } ,
{ V_45 , V_46 } ,
{ V_47 , V_48 } ,
{ V_49 , V_50 } ,
} ;
V_6 = F_2 ( V_4 + V_51 ) ;
V_6 &= ~ V_40 [ V_38 - 1 ] . V_52 ;
V_6 |= ( V_28 << V_40 [ V_38 - 1 ] . V_53 ) &
V_40 [ V_38 - 1 ] . V_52 ;
if ( V_38 == V_54 ) {
V_6 &= ~ V_55 ;
V_6 |= 0x1 << V_56 ;
} else if ( V_38 == V_57 ) {
V_6 &= ~ V_58 ;
V_6 |= 0x1 << V_59 ;
}
F_3 ( V_6 , V_4 + V_51 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
T_2 V_60 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_61 ) ;
V_6 &= ~ V_62 ;
switch ( V_60 ) {
case V_63 :
V_6 |= V_64 ;
break;
case V_65 :
V_6 |= V_66 ;
break;
default:
break;
}
F_3 ( V_6 , V_4 + V_61 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_2 V_67 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_61 ) ;
V_6 &= ~ V_68 ;
switch ( V_67 ) {
case V_69 :
V_6 |= V_70 ;
break;
case V_71 :
V_6 |= V_72 ;
break;
case V_73 :
V_6 |= V_74 ;
break;
case V_75 :
V_6 |= V_76 ;
break;
default:
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
T_2 V_77 , T_2 V_28 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + F_18 ( V_28 ) ) ;
V_6 &= ~ V_78 ;
V_6 |= V_77 & V_78 ;
F_3 ( V_6 , V_4 + F_18 ( V_28 ) ) ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_79 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
if ( V_28 < 4 )
V_6 = F_2 ( V_4 + V_80 ) ;
else
V_6 = F_2 ( V_4 + V_81 ) ;
if ( V_28 == 0 || V_28 == 4 ) {
V_6 &= ~ V_82 ;
V_6 |= F_20 ( V_79 ) ;
} else {
V_6 &= ~ F_21 ( V_28 ) ;
V_6 |= F_22 ( V_79 , V_28 ) ;
}
if ( V_28 < 4 )
F_3 ( V_6 , V_4 + V_80 ) ;
else
F_3 ( V_6 , V_4 + V_81 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
T_2 V_83 , T_2 V_84 ,
T_2 V_85 , T_2 V_86 , T_2 V_28 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
F_24 ( L_1 , V_28 ) ;
F_24 ( L_2 , V_83 ) ;
F_24 ( L_3 , V_84 ) ;
F_24 ( L_4 , V_85 ) ;
F_24 ( L_5 , V_86 ) ;
V_6 = F_2 ( V_4 + F_25 ( V_28 ) ) ;
V_6 |= V_87 ;
V_6 |= V_88 ;
F_3 ( V_6 , V_4 + F_25 ( V_28 ) ) ;
V_6 = F_2 ( V_4 + F_26 ( V_28 ) ) ;
V_6 &= ~ V_89 ;
V_6 |= V_83 & V_89 ;
F_3 ( V_6 , V_4 + F_26 ( V_28 ) ) ;
F_17 ( V_2 , V_84 , V_28 ) ;
V_6 = F_2 ( V_4 + F_27 ( V_28 ) ) ;
V_6 &= ~ V_90 ;
V_6 |= V_85 & V_90 ;
F_3 ( V_6 , V_4 + F_27 ( V_28 ) ) ;
V_6 = F_2 ( V_4 + F_28 ( V_28 ) ) ;
V_6 &= ~ V_91 ;
V_6 |= V_86 & V_91 ;
F_3 ( V_6 , V_4 + F_28 ( V_28 ) ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 * V_92 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 ++ )
V_92 [ V_93 ] = F_2 ( V_4 + V_93 * 4 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_2 -> V_95 )
V_6 |= V_96 ;
else
V_6 &= ~ V_96 ;
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
return ! ! ( V_6 & V_96 ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned long V_27 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_22 = 0 ;
T_2 V_97 ;
if ( V_27 & V_98 ) {
F_24 ( L_6 ) ;
V_22 |= V_99 | V_100 ;
}
if ( V_27 & V_101 ) {
F_24 ( L_7 ) ;
V_22 |= V_99 | V_102 | V_103 ;
}
if ( V_22 ) {
V_97 = F_2 ( V_4 + V_7 ) ;
V_97 |= V_104 ;
F_3 ( V_97 , V_4 + V_7 ) ;
}
F_3 ( V_22 , V_4 + V_105 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned char * V_106 , unsigned int V_107 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_33 ( V_4 , V_106 , F_34 ( V_107 ) ,
F_35 ( V_107 ) ) ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned char * V_106 , unsigned int V_107 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_37 ( V_4 , V_106 , F_34 ( V_107 ) ,
F_35 ( V_107 ) ) ;
}
static void F_38 ( struct V_1 * V_2 ,
bool V_108 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_109 ) ;
V_6 |= V_110 | V_111 ;
if ( V_108 )
V_6 |= V_112 ;
F_3 ( V_6 , V_4 + V_109 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_109 ) ;
V_6 &= ~ ( V_110 | V_111 ) ;
F_3 ( V_6 , V_4 + V_109 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_13 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_109 ) ;
if ( V_13 )
V_6 |= V_113 ;
else
V_6 &= ~ V_113 ;
F_3 ( V_6 , V_4 + V_109 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_114 , int V_115 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_115 & 0xffff ) ) | ( ( V_114 & 0x3ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_116 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
void T_1 * V_4 = ( void T_1 * ) V_118 -> V_119 ;
unsigned int V_6 = 0 ;
if ( V_118 -> V_120 & V_121 ) {
V_6 = V_122 ;
} else if ( ( V_118 -> V_120 & V_123 ) ||
( F_43 ( V_118 ) > V_124 ) ) {
V_6 = V_125 ;
F_3 ( 0xffffffff , V_4 + V_126 ) ;
F_3 ( 0xffffffff , V_4 + V_127 ) ;
} else if ( ! F_44 ( V_118 ) ) {
T_2 V_128 [ 2 ] ;
struct V_129 * V_130 ;
V_6 = V_131 ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
F_45 (ha, dev) {
int V_132 =
( F_46 ( ~ F_47 ( ~ 0 , V_130 -> V_106 , 6 ) ) >> 26 ) ;
V_128 [ V_132 >> 5 ] |= ( 1 << ( V_132 & 0x1F ) ) ;
}
F_3 ( V_128 [ 0 ] , V_4 + V_126 ) ;
F_3 ( V_128 [ 1 ] , V_4 + V_127 ) ;
}
if ( F_48 ( V_118 ) > V_133 ) {
V_6 |= V_122 ;
} else if ( ! F_49 ( V_118 ) ) {
int V_134 = 1 ;
struct V_129 * V_130 ;
F_50 (ha, dev) {
F_32 ( V_2 , V_130 -> V_106 , V_134 ) ;
V_134 ++ ;
}
}
F_3 ( V_6 , V_4 + V_135 ) ;
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_136 ,
unsigned int V_137 , unsigned int V_138 ,
T_2 V_139 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_140 = 0 ;
T_2 V_28 = 0 ;
F_24 ( L_8 ) ;
if ( V_137 & V_141 ) {
F_24 ( L_9 ) ;
V_140 |= V_142 ;
F_3 ( V_140 , V_4 + V_143 ) ;
}
if ( V_137 & V_144 ) {
F_24 ( L_10 ) ;
if ( V_136 )
F_24 ( L_11 , V_138 ) ;
for ( V_28 = 0 ; V_28 < V_139 ; V_28 ++ ) {
V_140 |= V_145 ;
if ( V_136 )
V_140 |=
( V_138 << V_146 ) ;
F_3 ( V_140 , V_4 + F_52 ( V_28 ) ) ;
}
}
}
static void F_53 ( void T_1 * V_4 , bool V_147 , bool V_148 ,
bool V_149 )
{
F_54 ( V_4 , V_150 , V_147 , V_148 , V_149 ) ;
}
static void F_55 ( void T_1 * V_4 , bool V_151 )
{
F_56 ( V_4 , V_150 , V_151 ) ;
}
static void F_57 ( void T_1 * V_4 , struct V_152 * V_153 )
{
F_58 ( V_4 , V_150 , V_153 ) ;
}
static void F_59 ( void T_1 * V_4 , struct V_154 * V_155 )
{
T_2 V_156 ;
V_156 = F_2 ( V_4 + V_157 ) ;
V_155 -> V_158 ++ ;
if ( V_156 & V_159 ) {
int V_160 ;
V_155 -> V_161 = 1 ;
V_160 = ( ( V_156 & V_162 ) >>
V_163 ) ;
if ( V_160 == V_164 )
V_155 -> V_165 = V_15 ;
else if ( V_160 == V_166 )
V_155 -> V_165 = V_17 ;
else
V_155 -> V_165 = V_19 ;
V_155 -> V_167 = ( V_156 & V_168 ) ;
F_60 ( L_12 , ( int ) V_155 -> V_165 ,
V_155 -> V_167 ? L_13 : L_14 ) ;
} else {
V_155 -> V_161 = 0 ;
F_60 ( L_15 ) ;
}
}
static int F_61 ( struct V_1 * V_2 , T_2 V_79 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_169 ;
int V_170 = 0 ;
V_169 = F_2 ( V_4 + V_171 ) ;
if ( V_169 & F_62 ( V_79 ) ) {
T_2 V_156 = F_2 ( V_4 + F_63 ( V_79 ) ) ;
if ( V_156 & V_172 ) {
F_3 ( V_156 | V_172 ,
V_4 + F_63 ( V_79 ) ) ;
V_170 = V_173 ;
}
}
return V_170 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_154 * V_155 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_174 ;
int V_170 = 0 ;
V_174 = F_2 ( V_4 + V_175 ) ;
if ( ( V_174 & V_176 ) )
V_155 -> V_177 ++ ;
if ( F_65 ( V_174 & V_178 ) )
V_155 -> V_179 ++ ;
if ( F_65 ( V_174 & V_180 ) )
V_155 -> V_181 ++ ;
if ( F_65 ( V_174 & V_182 ) ) {
F_2 ( V_4 + V_105 ) ;
V_155 -> V_183 ++ ;
}
F_66 ( V_4 , V_150 , V_174 , V_155 ) ;
if ( V_174 & V_184 )
F_59 ( V_4 , V_155 ) ;
return V_170 ;
}
static void F_67 ( void T_1 * V_4 , struct V_154 * V_155 ,
T_2 V_185 , T_2 V_186 )
{
T_2 V_6 ;
T_2 V_28 ;
for ( V_28 = 0 ; V_28 < V_186 ; V_28 ++ ) {
V_6 = F_2 ( V_4 + F_68 ( V_28 ) ) ;
if ( V_6 & V_187 )
V_155 -> V_188 ++ ;
if ( V_6 & V_189 )
V_155 -> V_190 ++ ;
if ( V_6 & V_191 )
V_155 -> V_192 ++ ;
if ( V_6 & V_193 ) {
T_2 V_194 = ( V_6 & V_193 )
>> V_195 ;
if ( V_194 == V_196 )
V_155 -> V_197 ++ ;
else if ( V_194 == V_198 )
V_155 -> V_199 ++ ;
else if ( V_194 == V_200 )
V_155 -> V_201 ++ ;
else
V_155 -> V_202 ++ ;
}
if ( V_6 & V_203 )
V_155 -> V_204 ++ ;
}
for ( V_28 = 0 ; V_28 < V_185 ; V_28 ++ ) {
V_6 = F_2 ( V_4 + F_69 ( V_28 ) ) ;
if ( V_6 & V_205 ) {
T_2 V_206 = ( V_6 & V_205 )
>> V_207 ;
if ( V_206 == V_208 )
V_155 -> V_209 ++ ;
else if ( V_206 == V_210 )
V_155 -> V_211 ++ ;
else if ( V_206 == V_212 )
V_155 -> V_213 ++ ;
else
V_155 -> V_214 ++ ;
}
if ( V_6 & V_215 ) {
T_2 V_216 = ( V_6 & V_215 ) >>
V_207 ;
if ( V_216 == V_217 )
V_155 -> V_218 ++ ;
else if ( V_216 == V_219 )
V_155 -> V_220 ++ ;
else if ( V_216 == V_221 )
V_155 -> V_222 ++ ;
else
V_155 -> V_223 ++ ;
}
if ( V_6 & V_224 )
V_155 -> V_225 ++ ;
}
V_6 = F_2 ( V_4 + V_226 ) ;
if ( V_6 & V_227 ) {
T_2 V_228 = ( V_6 & V_227 )
>> V_229 ;
if ( V_228 == V_230 )
V_155 -> V_231 ++ ;
else if ( V_228 == V_232 )
V_155 -> V_233 ++ ;
else if ( V_228 == V_234 )
V_155 -> V_235 ++ ;
else
V_155 -> V_236 ++ ;
}
if ( V_6 & V_237 )
V_155 -> V_238 ++ ;
if ( V_6 & V_239 )
V_155 -> V_240 = ( V_6 & V_239 )
>> V_241 ;
if ( V_6 & V_242 )
V_155 -> V_243 ++ ;
}
struct V_1 * F_70 ( void T_1 * V_4 , int V_244 ,
int V_245 , int * V_246 )
{
struct V_1 * V_247 ;
T_2 V_248 = F_2 ( V_4 + V_249 ) ;
V_247 = F_71 ( sizeof( const struct V_1 ) , V_250 ) ;
if ( ! V_247 )
return NULL ;
V_247 -> V_5 = V_4 ;
V_247 -> V_251 = V_244 ;
V_247 -> V_252 = V_245 ;
V_247 -> V_253 = 0 ;
if ( V_247 -> V_251 )
V_247 -> V_253 = F_72 ( V_247 -> V_251 ) ;
V_247 -> V_13 . V_136 = V_254 ;
V_247 -> V_13 . V_20 = V_255 ;
V_247 -> V_13 . V_18 = V_256 | V_255 ;
V_247 -> V_13 . V_16 = 0 ;
V_247 -> V_13 . V_14 = V_256 | V_255 ;
V_247 -> V_257 . V_106 = V_258 ;
V_247 -> V_257 . V_259 = V_260 ;
V_247 -> V_257 . V_261 = 21 ;
V_247 -> V_257 . V_262 = F_73 ( 25 , 21 ) ;
V_247 -> V_257 . V_53 = 16 ;
V_247 -> V_257 . V_52 = F_73 ( 20 , 16 ) ;
V_247 -> V_257 . V_263 = 8 ;
V_247 -> V_257 . V_264 = F_73 ( 11 , 8 ) ;
* V_246 = F_74 ( V_248 ) ;
if ( * V_246 > V_265 )
V_247 -> V_266 = & V_267 ;
else
V_247 -> V_266 = & V_268 ;
if ( * V_246 >= V_265 )
V_247 -> V_247 = & V_269 ;
else
V_247 -> V_247 = & V_270 ;
return V_247 ;
}
