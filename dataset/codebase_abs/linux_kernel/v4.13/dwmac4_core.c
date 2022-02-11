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
if ( V_27 & V_97 ) {
F_24 ( L_6 ) ;
V_22 |= V_98 | V_99 ;
}
if ( V_27 & V_100 ) {
F_24 ( L_7 ) ;
V_22 |= V_98 | V_101 | V_102 ;
}
F_3 ( V_22 , V_4 + V_103 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned char * V_104 , unsigned int V_105 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_33 ( V_4 , V_104 , F_34 ( V_105 ) ,
F_35 ( V_105 ) ) ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned char * V_104 , unsigned int V_105 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_37 ( V_4 , V_104 , F_34 ( V_105 ) ,
F_35 ( V_105 ) ) ;
}
static void F_38 ( struct V_1 * V_2 ,
bool V_106 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_107 ) ;
V_6 |= V_108 | V_109 ;
if ( V_106 )
V_6 |= V_110 ;
F_3 ( V_6 , V_4 + V_107 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_107 ) ;
V_6 &= ~ ( V_108 | V_109 ) ;
F_3 ( V_6 , V_4 + V_107 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_13 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_107 ) ;
if ( V_13 )
V_6 |= V_111 ;
else
V_6 &= ~ V_111 ;
F_3 ( V_6 , V_4 + V_107 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_112 , int V_113 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_113 & 0xffff ) ) | ( ( V_112 & 0x3ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_114 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_115 * V_116 )
{
void T_1 * V_4 = ( void T_1 * ) V_116 -> V_117 ;
unsigned int V_6 = 0 ;
if ( V_116 -> V_118 & V_119 ) {
V_6 = V_120 ;
} else if ( ( V_116 -> V_118 & V_121 ) ||
( F_43 ( V_116 ) > V_122 ) ) {
V_6 = V_123 ;
F_3 ( 0xffffffff , V_4 + V_124 ) ;
F_3 ( 0xffffffff , V_4 + V_125 ) ;
} else if ( ! F_44 ( V_116 ) ) {
T_2 V_126 [ 2 ] ;
struct V_127 * V_128 ;
V_6 = V_129 ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
F_45 (ha, dev) {
int V_130 =
( F_46 ( ~ F_47 ( ~ 0 , V_128 -> V_104 , 6 ) ) >> 26 ) ;
V_126 [ V_130 >> 5 ] |= ( 1 << ( V_130 & 0x1F ) ) ;
}
F_3 ( V_126 [ 0 ] , V_4 + V_124 ) ;
F_3 ( V_126 [ 1 ] , V_4 + V_125 ) ;
}
if ( F_48 ( V_116 ) > V_131 ) {
V_6 |= V_120 ;
} else if ( ! F_49 ( V_116 ) ) {
int V_132 = 1 ;
struct V_127 * V_128 ;
F_50 (ha, dev) {
F_32 ( V_2 , V_128 -> V_104 , V_132 ) ;
V_132 ++ ;
}
}
F_3 ( V_6 , V_4 + V_133 ) ;
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_134 ,
unsigned int V_135 , unsigned int V_136 ,
T_2 V_137 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_138 = 0 ;
T_2 V_28 = 0 ;
F_24 ( L_8 ) ;
if ( V_135 & V_139 ) {
F_24 ( L_9 ) ;
V_138 |= V_140 ;
F_3 ( V_138 , V_4 + V_141 ) ;
}
if ( V_135 & V_142 ) {
F_24 ( L_10 ) ;
if ( V_134 )
F_24 ( L_11 , V_136 ) ;
for ( V_28 = 0 ; V_28 < V_137 ; V_28 ++ ) {
V_138 |= V_143 ;
if ( V_134 )
V_138 |=
( V_136 << V_144 ) ;
F_3 ( V_138 , V_4 + F_52 ( V_28 ) ) ;
}
}
}
static void F_53 ( void T_1 * V_4 , bool V_145 , bool V_146 ,
bool V_147 )
{
F_54 ( V_4 , V_148 , V_145 , V_146 , V_147 ) ;
}
static void F_55 ( void T_1 * V_4 , bool V_149 )
{
F_56 ( V_4 , V_148 , V_149 ) ;
}
static void F_57 ( void T_1 * V_4 , struct V_150 * V_151 )
{
F_58 ( V_4 , V_148 , V_151 ) ;
}
static void F_59 ( void T_1 * V_4 , struct V_152 * V_153 )
{
T_2 V_154 ;
V_154 = F_2 ( V_4 + V_155 ) ;
V_153 -> V_156 ++ ;
if ( V_154 & V_157 ) {
int V_158 ;
V_153 -> V_159 = 1 ;
V_158 = ( ( V_154 & V_160 ) >>
V_161 ) ;
if ( V_158 == V_162 )
V_153 -> V_163 = V_15 ;
else if ( V_158 == V_164 )
V_153 -> V_163 = V_17 ;
else
V_153 -> V_163 = V_19 ;
V_153 -> V_165 = ( V_154 & V_166 ) ;
F_60 ( L_12 , ( int ) V_153 -> V_163 ,
V_153 -> V_165 ? L_13 : L_14 ) ;
} else {
V_153 -> V_159 = 0 ;
F_60 ( L_15 ) ;
}
}
static int F_61 ( struct V_1 * V_2 , T_2 V_79 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_167 ;
int V_168 = 0 ;
V_167 = F_2 ( V_4 + V_169 ) ;
if ( V_167 & F_62 ( V_79 ) ) {
T_2 V_154 = F_2 ( V_4 + F_63 ( V_79 ) ) ;
if ( V_154 & V_170 ) {
F_3 ( V_154 | V_170 ,
V_4 + F_63 ( V_79 ) ) ;
V_168 = V_171 ;
}
}
return V_168 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_172 ;
int V_168 = 0 ;
V_172 = F_2 ( V_4 + V_173 ) ;
if ( ( V_172 & V_174 ) )
V_153 -> V_175 ++ ;
if ( F_65 ( V_172 & V_176 ) )
V_153 -> V_177 ++ ;
if ( F_65 ( V_172 & V_178 ) )
V_153 -> V_179 ++ ;
if ( F_65 ( V_172 & V_180 ) ) {
F_2 ( V_4 + V_103 ) ;
V_153 -> V_181 ++ ;
}
F_66 ( V_4 , V_148 , V_172 , V_153 ) ;
if ( V_172 & V_182 )
F_59 ( V_4 , V_153 ) ;
return V_168 ;
}
static void F_67 ( void T_1 * V_4 , struct V_152 * V_153 ,
T_2 V_183 , T_2 V_184 )
{
T_2 V_6 ;
T_2 V_28 ;
for ( V_28 = 0 ; V_28 < V_184 ; V_28 ++ ) {
V_6 = F_2 ( V_4 + F_68 ( V_28 ) ) ;
if ( V_6 & V_185 )
V_153 -> V_186 ++ ;
if ( V_6 & V_187 )
V_153 -> V_188 ++ ;
if ( V_6 & V_189 )
V_153 -> V_190 ++ ;
if ( V_6 & V_191 ) {
T_2 V_192 = ( V_6 & V_191 )
>> V_193 ;
if ( V_192 == V_194 )
V_153 -> V_195 ++ ;
else if ( V_192 == V_196 )
V_153 -> V_197 ++ ;
else if ( V_192 == V_198 )
V_153 -> V_199 ++ ;
else
V_153 -> V_200 ++ ;
}
if ( V_6 & V_201 )
V_153 -> V_202 ++ ;
}
for ( V_28 = 0 ; V_28 < V_183 ; V_28 ++ ) {
V_6 = F_2 ( V_4 + F_69 ( V_28 ) ) ;
if ( V_6 & V_203 ) {
T_2 V_204 = ( V_6 & V_203 )
>> V_205 ;
if ( V_204 == V_206 )
V_153 -> V_207 ++ ;
else if ( V_204 == V_208 )
V_153 -> V_209 ++ ;
else if ( V_204 == V_210 )
V_153 -> V_211 ++ ;
else
V_153 -> V_212 ++ ;
}
if ( V_6 & V_213 ) {
T_2 V_214 = ( V_6 & V_213 ) >>
V_205 ;
if ( V_214 == V_215 )
V_153 -> V_216 ++ ;
else if ( V_214 == V_217 )
V_153 -> V_218 ++ ;
else if ( V_214 == V_219 )
V_153 -> V_220 ++ ;
else
V_153 -> V_221 ++ ;
}
if ( V_6 & V_222 )
V_153 -> V_223 ++ ;
}
V_6 = F_2 ( V_4 + V_224 ) ;
if ( V_6 & V_225 ) {
T_2 V_226 = ( V_6 & V_225 )
>> V_227 ;
if ( V_226 == V_228 )
V_153 -> V_229 ++ ;
else if ( V_226 == V_230 )
V_153 -> V_231 ++ ;
else if ( V_226 == V_232 )
V_153 -> V_233 ++ ;
else
V_153 -> V_234 ++ ;
}
if ( V_6 & V_235 )
V_153 -> V_236 ++ ;
if ( V_6 & V_237 )
V_153 -> V_238 = ( V_6 & V_237 )
>> V_239 ;
if ( V_6 & V_240 )
V_153 -> V_241 ++ ;
}
struct V_1 * F_70 ( void T_1 * V_4 , int V_242 ,
int V_243 , int * V_244 )
{
struct V_1 * V_245 ;
T_2 V_246 = F_2 ( V_4 + V_247 ) ;
V_245 = F_71 ( sizeof( const struct V_1 ) , V_248 ) ;
if ( ! V_245 )
return NULL ;
V_245 -> V_5 = V_4 ;
V_245 -> V_249 = V_242 ;
V_245 -> V_250 = V_243 ;
V_245 -> V_251 = 0 ;
if ( V_245 -> V_249 )
V_245 -> V_251 = F_72 ( V_245 -> V_249 ) ;
V_245 -> V_13 . V_134 = V_252 ;
V_245 -> V_13 . V_20 = V_253 ;
V_245 -> V_13 . V_18 = V_254 | V_253 ;
V_245 -> V_13 . V_16 = 0 ;
V_245 -> V_13 . V_14 = V_254 | V_253 ;
V_245 -> V_255 . V_104 = V_256 ;
V_245 -> V_255 . V_257 = V_258 ;
V_245 -> V_255 . V_259 = 21 ;
V_245 -> V_255 . V_260 = F_73 ( 25 , 21 ) ;
V_245 -> V_255 . V_53 = 16 ;
V_245 -> V_255 . V_52 = F_73 ( 20 , 16 ) ;
V_245 -> V_255 . V_261 = 8 ;
V_245 -> V_255 . V_262 = F_73 ( 11 , 8 ) ;
* V_244 = F_74 ( V_246 ) ;
if ( * V_244 > V_263 )
V_245 -> V_264 = & V_265 ;
else
V_245 -> V_264 = & V_266 ;
if ( * V_244 >= V_263 )
V_245 -> V_245 = & V_267 ;
else
V_245 -> V_245 = & V_268 ;
return V_245 ;
}
