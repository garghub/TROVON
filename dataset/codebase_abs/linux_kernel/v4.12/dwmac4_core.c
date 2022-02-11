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
if ( V_2 -> V_11 == V_13 ) {
V_6 &= ~ V_14 ;
} else {
V_6 |= V_14 ;
if ( V_2 -> V_11 == V_15 )
V_6 &= ~ V_16 ;
else
V_6 |= V_16 ;
}
}
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = V_17 ;
if ( V_2 -> V_18 )
V_6 |= V_19 ;
if ( V_2 -> V_20 )
V_6 |= V_21 ;
F_3 ( V_6 , V_4 + V_22 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_3 V_23 , T_2 V_24 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_25 ) ;
V_6 &= F_5 ( V_24 ) ;
if ( V_23 == V_26 )
V_6 |= F_6 ( V_24 ) ;
else if ( V_23 == V_27 )
V_6 |= F_7 ( V_24 ) ;
F_3 ( V_6 , V_4 + V_25 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
T_2 V_28 , T_2 V_24 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_29 ;
T_2 V_6 ;
V_29 = ( V_24 < 4 ) ? V_30 : V_31 ;
V_6 = F_2 ( V_4 + V_29 ) ;
V_6 &= ~ F_9 ( V_24 ) ;
V_6 |= ( V_28 << F_10 ( V_24 ) ) &
F_9 ( V_24 ) ;
F_3 ( V_6 , V_4 + V_29 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_2 V_28 , T_2 V_24 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_29 ;
T_2 V_6 ;
V_29 = ( V_24 < 4 ) ? V_32 : V_33 ;
V_6 = F_2 ( V_4 + V_29 ) ;
V_6 &= ~ F_12 ( V_24 ) ;
V_6 |= ( V_28 << F_13 ( V_24 ) ) &
F_12 ( V_24 ) ;
F_3 ( V_6 , V_4 + V_29 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
T_3 V_34 , T_2 V_24 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
const struct V_35 V_36 [] = {
{ V_37 , V_38 } ,
{ V_39 , V_40 } ,
{ V_41 , V_42 } ,
{ V_43 , V_44 } ,
{ V_45 , V_46 } ,
} ;
V_6 = F_2 ( V_4 + V_47 ) ;
V_6 &= ~ V_36 [ V_34 - 1 ] . V_48 ;
V_6 |= ( V_24 << V_36 [ V_34 - 1 ] . V_49 ) &
V_36 [ V_34 - 1 ] . V_48 ;
if ( V_34 == V_50 ) {
V_6 &= ~ V_51 ;
V_6 |= 0x1 << V_52 ;
} else if ( V_34 == V_53 ) {
V_6 &= ~ V_54 ;
V_6 |= 0x1 << V_55 ;
}
F_3 ( V_6 , V_4 + V_47 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
T_2 V_56 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_57 ) ;
V_6 &= ~ V_58 ;
switch ( V_56 ) {
case V_59 :
V_6 |= V_60 ;
break;
case V_61 :
V_6 |= V_62 ;
break;
default:
break;
}
F_3 ( V_6 , V_4 + V_57 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_2 V_63 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_57 ) ;
V_6 &= ~ V_64 ;
switch ( V_63 ) {
case V_65 :
V_6 |= V_66 ;
break;
case V_67 :
V_6 |= V_68 ;
break;
case V_69 :
V_6 |= V_70 ;
break;
case V_71 :
V_6 |= V_72 ;
break;
default:
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
T_2 V_73 , T_2 V_24 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + F_18 ( V_24 ) ) ;
V_6 &= ~ V_74 ;
V_6 |= V_73 & V_74 ;
F_3 ( V_6 , V_4 + F_18 ( V_24 ) ) ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_24 , T_2 V_75 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
if ( V_24 < 4 )
V_6 = F_2 ( V_4 + V_76 ) ;
else
V_6 = F_2 ( V_4 + V_77 ) ;
if ( V_24 == 0 || V_24 == 4 ) {
V_6 &= ~ V_78 ;
V_6 |= F_20 ( V_75 ) ;
} else {
V_6 &= ~ F_21 ( V_24 ) ;
V_6 |= F_22 ( V_75 , V_24 ) ;
}
if ( V_24 < 4 )
F_3 ( V_6 , V_4 + V_76 ) ;
else
F_3 ( V_6 , V_4 + V_77 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
T_2 V_79 , T_2 V_80 ,
T_2 V_81 , T_2 V_82 , T_2 V_24 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
F_24 ( L_1 , V_24 ) ;
F_24 ( L_2 , V_79 ) ;
F_24 ( L_3 , V_80 ) ;
F_24 ( L_4 , V_81 ) ;
F_24 ( L_5 , V_82 ) ;
V_6 = F_2 ( V_4 + F_25 ( V_24 ) ) ;
V_6 |= V_83 ;
V_6 |= V_84 ;
F_3 ( V_6 , V_4 + F_25 ( V_24 ) ) ;
V_6 = F_2 ( V_4 + F_26 ( V_24 ) ) ;
V_6 &= ~ V_85 ;
V_6 |= V_79 & V_85 ;
F_3 ( V_6 , V_4 + F_26 ( V_24 ) ) ;
F_17 ( V_2 , V_80 , V_24 ) ;
V_6 = F_2 ( V_4 + F_27 ( V_24 ) ) ;
V_6 &= ~ V_86 ;
V_6 |= V_81 & V_86 ;
F_3 ( V_6 , V_4 + F_27 ( V_24 ) ) ;
V_6 = F_2 ( V_4 + F_28 ( V_24 ) ) ;
V_6 &= ~ V_87 ;
V_6 |= V_82 & V_87 ;
F_3 ( V_6 , V_4 + F_28 ( V_24 ) ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 * V_88 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_89 ;
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ )
V_88 [ V_89 ] = F_2 ( V_4 + V_89 * 4 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_2 -> V_91 )
V_6 |= V_92 ;
else
V_6 &= ~ V_92 ;
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
return ! ! ( V_6 & V_92 ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned long V_23 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_18 = 0 ;
if ( V_23 & V_93 ) {
F_24 ( L_6 ) ;
V_18 |= V_94 | V_95 ;
}
if ( V_23 & V_96 ) {
F_24 ( L_7 ) ;
V_18 |= V_94 | V_97 | V_98 ;
}
F_3 ( V_18 , V_4 + V_99 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned char * V_100 , unsigned int V_101 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_33 ( V_4 , V_100 , F_34 ( V_101 ) ,
F_35 ( V_101 ) ) ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned char * V_100 , unsigned int V_101 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_37 ( V_4 , V_100 , F_34 ( V_101 ) ,
F_35 ( V_101 ) ) ;
}
static void F_38 ( struct V_1 * V_2 ,
bool V_102 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_103 ) ;
V_6 |= V_104 | V_105 ;
if ( V_102 )
V_6 |= V_106 ;
F_3 ( V_6 , V_4 + V_103 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_103 ) ;
V_6 &= ~ ( V_104 | V_105 ) ;
F_3 ( V_6 , V_4 + V_103 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_107 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_103 ) ;
if ( V_107 )
V_6 |= V_108 ;
else
V_6 &= ~ V_108 ;
F_3 ( V_6 , V_4 + V_103 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_109 , int V_110 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_110 & 0xffff ) ) | ( ( V_109 & 0x3ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_111 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
void T_1 * V_4 = ( void T_1 * ) V_113 -> V_114 ;
unsigned int V_6 = 0 ;
if ( V_113 -> V_115 & V_116 ) {
V_6 = V_117 ;
} else if ( ( V_113 -> V_115 & V_118 ) ||
( F_43 ( V_113 ) > V_119 ) ) {
V_6 = V_120 ;
F_3 ( 0xffffffff , V_4 + V_121 ) ;
F_3 ( 0xffffffff , V_4 + V_122 ) ;
} else if ( ! F_44 ( V_113 ) ) {
T_2 V_123 [ 2 ] ;
struct V_124 * V_125 ;
V_6 = V_126 ;
memset ( V_123 , 0 , sizeof( V_123 ) ) ;
F_45 (ha, dev) {
int V_127 =
( F_46 ( ~ F_47 ( ~ 0 , V_125 -> V_100 , 6 ) ) >> 26 ) ;
V_123 [ V_127 >> 5 ] |= ( 1 << ( V_127 & 0x1F ) ) ;
}
F_3 ( V_123 [ 0 ] , V_4 + V_121 ) ;
F_3 ( V_123 [ 1 ] , V_4 + V_122 ) ;
}
if ( F_48 ( V_113 ) > V_128 ) {
V_6 |= V_117 ;
} else if ( ! F_49 ( V_113 ) ) {
int V_129 = 1 ;
struct V_124 * V_125 ;
F_50 (ha, dev) {
F_32 ( V_2 , V_125 -> V_100 , V_129 ) ;
V_129 ++ ;
}
}
F_3 ( V_6 , V_4 + V_130 ) ;
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_131 ,
unsigned int V_132 , unsigned int V_133 ,
T_2 V_134 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_135 = 0 ;
T_2 V_24 = 0 ;
F_24 ( L_8 ) ;
if ( V_132 & V_136 ) {
F_24 ( L_9 ) ;
V_135 |= V_137 ;
F_3 ( V_135 , V_4 + V_138 ) ;
}
if ( V_132 & V_139 ) {
F_24 ( L_10 ) ;
if ( V_131 )
F_24 ( L_11 , V_133 ) ;
for ( V_24 = 0 ; V_24 < V_134 ; V_24 ++ ) {
V_135 |= V_140 ;
if ( V_131 )
V_135 |=
( V_133 << V_141 ) ;
F_3 ( V_135 , V_4 + F_52 ( V_24 ) ) ;
}
}
}
static void F_53 ( void T_1 * V_4 , bool V_142 , bool V_143 ,
bool V_144 )
{
F_54 ( V_4 , V_145 , V_142 , V_143 , V_144 ) ;
}
static void F_55 ( void T_1 * V_4 , bool V_146 )
{
F_56 ( V_4 , V_145 , V_146 ) ;
}
static void F_57 ( void T_1 * V_4 , struct V_147 * V_148 )
{
F_58 ( V_4 , V_145 , V_148 ) ;
}
static void F_59 ( void T_1 * V_4 , struct V_149 * V_150 )
{
T_2 V_151 ;
V_151 = F_2 ( V_4 + V_152 ) ;
V_150 -> V_153 ++ ;
if ( V_151 & V_154 ) {
int V_155 ;
V_150 -> V_156 = 1 ;
V_155 = ( ( V_151 & V_157 ) >>
V_158 ) ;
if ( V_155 == V_159 )
V_150 -> V_160 = V_13 ;
else if ( V_155 == V_161 )
V_150 -> V_160 = V_162 ;
else
V_150 -> V_160 = V_15 ;
V_150 -> V_163 = ( V_151 & V_164 ) ;
F_60 ( L_12 , ( int ) V_150 -> V_160 ,
V_150 -> V_163 ? L_13 : L_14 ) ;
} else {
V_150 -> V_156 = 0 ;
F_60 ( L_15 ) ;
}
}
static int F_61 ( struct V_1 * V_2 , T_2 V_75 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_165 ;
int V_166 = 0 ;
V_165 = F_2 ( V_4 + V_167 ) ;
if ( V_165 & F_62 ( V_75 ) ) {
T_2 V_151 = F_2 ( V_4 + F_63 ( V_75 ) ) ;
if ( V_151 & V_168 ) {
F_3 ( V_151 | V_168 ,
V_4 + F_63 ( V_75 ) ) ;
V_166 = V_169 ;
}
}
return V_166 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_170 ;
int V_166 = 0 ;
V_170 = F_2 ( V_4 + V_171 ) ;
if ( ( V_170 & V_172 ) )
V_150 -> V_173 ++ ;
if ( F_65 ( V_170 & V_174 ) )
V_150 -> V_175 ++ ;
if ( F_65 ( V_170 & V_176 ) )
V_150 -> V_177 ++ ;
if ( F_65 ( V_170 & V_178 ) ) {
F_2 ( V_4 + V_99 ) ;
V_150 -> V_179 ++ ;
}
F_66 ( V_4 , V_145 , V_170 , V_150 ) ;
if ( V_170 & V_180 )
F_59 ( V_4 , V_150 ) ;
return V_166 ;
}
static void F_67 ( void T_1 * V_4 , struct V_149 * V_150 ,
T_2 V_181 , T_2 V_182 )
{
T_2 V_6 ;
T_2 V_24 ;
for ( V_24 = 0 ; V_24 < V_182 ; V_24 ++ ) {
V_6 = F_2 ( V_4 + F_68 ( V_24 ) ) ;
if ( V_6 & V_183 )
V_150 -> V_184 ++ ;
if ( V_6 & V_185 )
V_150 -> V_186 ++ ;
if ( V_6 & V_187 )
V_150 -> V_188 ++ ;
if ( V_6 & V_189 ) {
T_2 V_190 = ( V_6 & V_189 )
>> V_191 ;
if ( V_190 == V_192 )
V_150 -> V_193 ++ ;
else if ( V_190 == V_194 )
V_150 -> V_195 ++ ;
else if ( V_190 == V_196 )
V_150 -> V_197 ++ ;
else
V_150 -> V_198 ++ ;
}
if ( V_6 & V_199 )
V_150 -> V_200 ++ ;
}
for ( V_24 = 0 ; V_24 < V_181 ; V_24 ++ ) {
V_6 = F_2 ( V_4 + F_69 ( V_24 ) ) ;
if ( V_6 & V_201 ) {
T_2 V_202 = ( V_6 & V_201 )
>> V_203 ;
if ( V_202 == V_204 )
V_150 -> V_205 ++ ;
else if ( V_202 == V_206 )
V_150 -> V_207 ++ ;
else if ( V_202 == V_208 )
V_150 -> V_209 ++ ;
else
V_150 -> V_210 ++ ;
}
if ( V_6 & V_211 ) {
T_2 V_212 = ( V_6 & V_211 ) >>
V_203 ;
if ( V_212 == V_213 )
V_150 -> V_214 ++ ;
else if ( V_212 == V_215 )
V_150 -> V_216 ++ ;
else if ( V_212 == V_217 )
V_150 -> V_218 ++ ;
else
V_150 -> V_219 ++ ;
}
if ( V_6 & V_220 )
V_150 -> V_221 ++ ;
}
V_6 = F_2 ( V_4 + V_222 ) ;
if ( V_6 & V_223 ) {
T_2 V_224 = ( V_6 & V_223 )
>> V_225 ;
if ( V_224 == V_226 )
V_150 -> V_227 ++ ;
else if ( V_224 == V_228 )
V_150 -> V_229 ++ ;
else if ( V_224 == V_230 )
V_150 -> V_231 ++ ;
else
V_150 -> V_232 ++ ;
}
if ( V_6 & V_233 )
V_150 -> V_234 ++ ;
if ( V_6 & V_235 )
V_150 -> V_236 = ( V_6 & V_235 )
>> V_237 ;
if ( V_6 & V_238 )
V_150 -> V_239 ++ ;
}
struct V_1 * F_70 ( void T_1 * V_4 , int V_240 ,
int V_241 , int * V_242 )
{
struct V_1 * V_243 ;
T_2 V_244 = F_2 ( V_4 + V_245 ) ;
V_243 = F_71 ( sizeof( const struct V_1 ) , V_246 ) ;
if ( ! V_243 )
return NULL ;
V_243 -> V_5 = V_4 ;
V_243 -> V_247 = V_240 ;
V_243 -> V_248 = V_241 ;
V_243 -> V_249 = 0 ;
if ( V_243 -> V_247 )
V_243 -> V_249 = F_72 ( V_243 -> V_247 ) ;
V_243 -> V_107 . V_250 = V_14 ;
V_243 -> V_107 . V_131 = V_251 ;
V_243 -> V_107 . V_252 = V_16 ;
V_243 -> V_253 . V_100 = V_254 ;
V_243 -> V_253 . V_255 = V_256 ;
V_243 -> V_253 . V_257 = 21 ;
V_243 -> V_253 . V_258 = F_73 ( 25 , 21 ) ;
V_243 -> V_253 . V_49 = 16 ;
V_243 -> V_253 . V_48 = F_73 ( 20 , 16 ) ;
V_243 -> V_253 . V_259 = 8 ;
V_243 -> V_253 . V_260 = F_73 ( 11 , 8 ) ;
* V_242 = F_74 ( V_244 ) ;
if ( * V_242 > V_261 )
V_243 -> V_262 = & V_263 ;
else
V_243 -> V_262 = & V_264 ;
if ( * V_242 >= V_261 )
V_243 -> V_243 = & V_265 ;
else
V_243 -> V_243 = & V_266 ;
return V_243 ;
}
