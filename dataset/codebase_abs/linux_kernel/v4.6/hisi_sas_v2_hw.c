static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
return F_2 ( V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
return F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_4 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
F_6 ( V_4 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_1 , int V_5 ,
T_1 V_2 , T_1 V_4 )
{
void T_2 * V_3 = V_1 -> V_3 + ( 0x400 * V_5 ) + V_2 ;
F_6 ( V_4 , V_3 ) ;
}
static T_1 F_8 ( struct V_1 * V_1 ,
int V_5 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + ( 0x400 * V_5 ) + V_2 ;
return F_2 ( V_3 ) ;
}
static void F_9 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_6 = F_8 ( V_1 , V_5 , V_7 ) ;
V_6 &= ~ V_8 ;
V_6 |= 1 << V_9 ;
F_7 ( V_1 , V_5 , V_7 , V_6 ) ;
}
static void F_10 ( struct V_1 * V_1 , int V_5 )
{
struct V_10 V_11 ;
T_1 * V_12 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_13 = V_14 ;
V_11 . V_15 = 0 ;
V_11 . V_16 = 1 ;
V_11 . V_17 = V_18 ;
V_11 . V_19 = V_20 ;
memcpy ( & V_11 . V_21 [ 0 ] , V_1 -> V_22 , V_23 ) ;
memcpy ( & V_11 . V_22 [ 0 ] , V_1 -> V_22 , V_23 ) ;
V_11 . V_24 = V_5 ;
V_12 = ( T_1 * ) ( & V_11 ) ;
F_7 ( V_1 , V_5 , V_25 ,
F_11 ( V_12 [ 0 ] ) ) ;
F_7 ( V_1 , V_5 , V_26 ,
V_12 [ 2 ] ) ;
F_7 ( V_1 , V_5 , V_27 ,
V_12 [ 1 ] ) ;
F_7 ( V_1 , V_5 , V_28 ,
V_12 [ 4 ] ) ;
F_7 ( V_1 , V_5 , V_29 ,
V_12 [ 3 ] ) ;
F_7 ( V_1 , V_5 , V_30 ,
F_11 ( V_12 [ 5 ] ) ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_1 -> V_32 ; V_31 ++ )
F_10 ( V_1 , V_31 ) ;
}
static void F_13 ( struct V_1 * V_1 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
T_3 V_40 , V_41 = V_34 -> V_41 ;
struct V_42 * V_43 = & V_1 -> V_43 [ V_41 ] ;
struct V_35 * V_44 = V_36 -> V_45 ;
struct V_46 * V_47 = V_36 -> V_47 -> V_48 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_40 = 0 ;
switch ( V_34 -> V_13 ) {
case V_14 :
case V_49 :
case V_50 :
V_40 = V_51 << V_52 ;
break;
case V_53 :
if ( V_44 && F_14 ( V_44 -> V_13 ) )
V_40 = V_54 << V_52 ;
else
V_40 = V_55 << V_52 ;
break;
default:
F_15 ( V_38 , L_1 ,
V_34 -> V_13 ) ;
}
V_40 |= ( ( 1 << V_56 ) |
( V_36 -> V_57 << V_58 ) |
( 1 << V_59 ) |
( V_47 -> V_60 << V_61 ) ) ;
V_43 -> V_40 = F_16 ( V_40 ) ;
memcpy ( & V_43 -> V_22 , V_36 -> V_22 , V_23 ) ;
V_43 -> V_22 = F_17 ( V_43 -> V_22 ) ;
V_43 -> V_62 = F_16 ( ( 500ULL << V_63 ) |
( 0xff00ULL << V_64 ) |
( 0xff00ULL << V_65 ) |
( 0xff00ULL << V_66 ) ) ;
}
static void F_18 ( struct V_1 * V_1 ,
struct V_33 * V_34 )
{
T_3 V_40 , V_67 = V_34 -> V_41 ;
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
struct V_42 * V_43 = & V_1 -> V_43 [ V_67 ] ;
T_1 V_68 = F_1 ( V_1 , V_69 ) ;
int V_31 ;
if ( V_70 & V_68 )
F_5 ( V_1 , V_69 ,
V_70 ) ;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
V_68 = F_1 ( V_1 , V_71 ) ;
V_68 |= V_72 | ( V_67 & V_73 ) ;
F_5 ( V_1 , V_71 , V_68 ) ;
F_19 ( 10 ) ;
V_68 = F_1 ( V_1 , V_69 ) ;
if ( V_70 & V_68 ) {
F_20 ( V_38 , L_2 ) ;
V_40 = F_16 ( V_43 -> V_40 ) ;
V_40 &= ~ ( 1 << V_56 ) ;
F_5 ( V_1 , V_69 ,
V_70 ) ;
V_1 -> V_74 [ V_67 ] . V_13 = V_75 ;
V_1 -> V_74 [ V_67 ] . V_76 = V_77 ;
F_5 ( V_1 , V_71 , 0 ) ;
F_20 ( V_38 , L_3 ) ;
break;
}
}
}
static int F_21 ( struct V_1 * V_1 )
{
int V_31 , V_78 ;
T_1 V_4 ;
unsigned long V_79 ;
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
if ( V_1 -> V_32 == 9 )
V_78 = 0x1fffff ;
else
V_78 = 0x7ffff ;
for ( V_31 = 0 ; V_31 < V_80 ; V_31 ++ )
F_5 ( V_1 , V_81 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_1 -> V_32 ; V_31 ++ ) {
T_1 V_82 = F_8 ( V_1 , V_31 , V_7 ) ;
V_82 &= ~ V_83 ;
F_7 ( V_1 , V_31 , V_7 , V_82 ) ;
}
F_19 ( 50 ) ;
for ( V_31 = 0 ; V_31 < V_1 -> V_32 ; V_31 ++ ) {
T_1 V_84 , V_85 ;
V_79 = V_86 + F_22 ( 1000 ) ;
while ( 1 ) {
V_84 = F_8 ( V_1 , V_31 ,
V_87 ) ;
V_85 = F_8 ( V_1 , V_31 ,
V_88 ) ;
if ( ! ( V_84 & V_89 ) &&
! ( V_85 & V_90 ) )
break;
F_23 ( 20 ) ;
if ( F_24 ( V_86 , V_79 ) )
return - V_91 ;
}
}
V_79 = V_86 + F_22 ( 1000 ) ;
while ( 1 ) {
T_1 V_92 =
F_1 ( V_1 , V_93 ) ;
if ( V_92 == 0 )
break;
F_23 ( 20 ) ;
if ( F_24 ( V_86 , V_79 ) )
return - V_91 ;
}
F_25 ( V_1 -> V_94 , V_1 -> V_95 ,
V_78 ) ;
F_25 ( V_1 -> V_94 , V_1 -> V_96 + 4 ,
V_78 ) ;
F_23 ( 1 ) ;
F_26 ( V_1 -> V_94 , V_1 -> V_97 , & V_4 ) ;
if ( V_78 != ( V_4 & V_78 ) ) {
F_27 ( V_38 , L_4 ) ;
return - V_91 ;
}
F_25 ( V_1 -> V_94 , V_1 -> V_95 + 4 ,
V_78 ) ;
F_25 ( V_1 -> V_94 , V_1 -> V_96 ,
V_78 ) ;
F_23 ( 1 ) ;
F_26 ( V_1 -> V_94 , V_1 -> V_97 ,
& V_4 ) ;
if ( V_4 & V_78 ) {
F_27 ( V_38 , L_5 ) ;
return - V_91 ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
struct V_98 * V_99 = V_38 -> V_100 ;
int V_31 ;
if ( F_29 ( V_99 , L_6 , NULL ) ) {
F_5 ( V_1 , V_101 , 0x2020 ) ;
F_5 ( V_1 , V_102 ,
0x2020 ) ;
}
F_5 ( V_1 , V_81 ,
( T_1 ) ( ( 1ULL << V_1 -> V_103 ) - 1 ) ) ;
F_5 ( V_1 , V_104 , 0xc0000000 ) ;
F_5 ( V_1 , V_105 , 0x10000 ) ;
F_5 ( V_1 , V_106 , 0x108 ) ;
F_5 ( V_1 , V_107 , 0x7FF ) ;
F_5 ( V_1 , V_108 , 0x1 ) ;
F_5 ( V_1 , V_109 , 0x1F4 ) ;
F_5 ( V_1 , V_110 , 0x4E20 ) ;
F_5 ( V_1 , V_111 , 0x1 ) ;
F_5 ( V_1 , V_112 , 0x1 ) ;
F_5 ( V_1 , V_113 , 0x1 ) ;
F_5 ( V_1 , V_114 , 0x1 ) ;
F_5 ( V_1 , V_115 , 0x1 ) ;
F_5 ( V_1 , V_116 , 0x1 ) ;
F_5 ( V_1 , V_117 , 0x1 ) ;
F_5 ( V_1 , V_118 , 0x1 ) ;
F_5 ( V_1 , V_119 , 0x1 ) ;
F_5 ( V_1 , V_120 , 0x0 ) ;
F_5 ( V_1 , V_121 , 0xffffffff ) ;
F_5 ( V_1 , V_122 , 0xffffffff ) ;
F_5 ( V_1 , V_69 , 0xffffffff ) ;
F_5 ( V_1 , V_123 , 0x7efefefe ) ;
F_5 ( V_1 , V_124 , 0x7efefefe ) ;
F_5 ( V_1 , V_125 , 0x7ffffffe ) ;
F_5 ( V_1 , V_126 , 0xfffff3c0 ) ;
for ( V_31 = 0 ; V_31 < V_1 -> V_103 ; V_31 ++ )
F_5 ( V_1 , V_127 + 0x4 * V_31 , 0 ) ;
F_5 ( V_1 , V_128 , 1 ) ;
F_5 ( V_1 , V_129 , 1 ) ;
for ( V_31 = 0 ; V_31 < V_1 -> V_32 ; V_31 ++ ) {
F_7 ( V_1 , V_31 , V_130 , 0x855 ) ;
F_7 ( V_1 , V_31 , V_131 , 0x30b9908 ) ;
F_7 ( V_1 , V_31 , V_132 , 0x7d7d7d7d ) ;
F_7 ( V_1 , V_31 , V_133 , 0x10 ) ;
F_7 ( V_1 , V_31 , V_134 , 0xffffffff ) ;
F_7 ( V_1 , V_31 , V_135 , 0xffffffff ) ;
F_7 ( V_1 , V_31 , V_136 , 0xffffffff ) ;
F_7 ( V_1 , V_31 , V_137 , 0x1000 ) ;
F_7 ( V_1 , V_31 , V_138 , 0xffffffff ) ;
F_7 ( V_1 , V_31 , V_139 , 0x8ffffbff ) ;
F_7 ( V_1 , V_31 , V_140 , 0x23f801fc ) ;
F_7 ( V_1 , V_31 , V_141 , 0x0 ) ;
F_7 ( V_1 , V_31 , V_142 , 0x0 ) ;
F_7 ( V_1 , V_31 , V_143 , 0x0 ) ;
F_7 ( V_1 , V_31 , V_144 , 0x0 ) ;
F_7 ( V_1 , V_31 , V_145 , 0x0 ) ;
F_7 ( V_1 , V_31 , V_146 , 0x0 ) ;
F_7 ( V_1 , V_31 , V_147 , 0x0 ) ;
F_7 ( V_1 , V_31 , V_148 , 0x199B694 ) ;
}
for ( V_31 = 0 ; V_31 < V_1 -> V_103 ; V_31 ++ ) {
F_5 ( V_1 ,
V_149 + ( V_31 * 0x14 ) ,
F_30 ( V_1 -> V_150 [ V_31 ] ) ) ;
F_5 ( V_1 , V_151 + ( V_31 * 0x14 ) ,
F_31 ( V_1 -> V_150 [ V_31 ] ) ) ;
F_5 ( V_1 , V_152 + ( V_31 * 0x14 ) ,
V_153 ) ;
F_5 ( V_1 , V_154 + ( V_31 * 0x14 ) ,
F_30 ( V_1 -> V_155 [ V_31 ] ) ) ;
F_5 ( V_1 , V_156 + ( V_31 * 0x14 ) ,
F_31 ( V_1 -> V_155 [ V_31 ] ) ) ;
F_5 ( V_1 , V_157 + ( V_31 * 0x14 ) ,
V_153 ) ;
}
F_5 ( V_1 , V_158 ,
F_31 ( V_1 -> V_159 ) ) ;
F_5 ( V_1 , V_160 ,
F_30 ( V_1 -> V_159 ) ) ;
F_5 ( V_1 , V_161 ,
F_31 ( V_1 -> V_162 ) ) ;
F_5 ( V_1 , V_163 ,
F_30 ( V_1 -> V_162 ) ) ;
F_5 ( V_1 , V_164 ,
F_31 ( V_1 -> V_165 ) ) ;
F_5 ( V_1 , V_166 ,
F_30 ( V_1 -> V_165 ) ) ;
F_5 ( V_1 , V_167 ,
F_31 ( V_1 -> V_168 ) ) ;
F_5 ( V_1 , V_169 ,
F_30 ( V_1 -> V_168 ) ) ;
F_5 ( V_1 , V_170 ,
F_31 ( V_1 -> V_171 ) ) ;
F_5 ( V_1 , V_172 ,
F_30 ( V_1 -> V_171 ) ) ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
int V_173 ;
V_173 = F_21 ( V_1 ) ;
if ( V_173 ) {
F_27 ( V_38 , L_7 , V_173 ) ;
return V_173 ;
}
F_23 ( 100 ) ;
F_28 ( V_1 ) ;
F_12 ( V_1 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_6 = F_8 ( V_1 , V_5 , V_7 ) ;
V_6 |= V_174 ;
F_7 ( V_1 , V_5 , V_7 , V_6 ) ;
}
static void F_34 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_6 = F_8 ( V_1 , V_5 , V_7 ) ;
V_6 &= ~ V_174 ;
F_7 ( V_1 , V_5 , V_7 , V_6 ) ;
}
static void F_35 ( struct V_1 * V_1 , int V_5 )
{
F_10 ( V_1 , V_5 ) ;
F_9 ( V_1 , V_5 ) ;
F_33 ( V_1 , V_5 ) ;
}
static void F_36 ( struct V_1 * V_1 , int V_5 )
{
F_34 ( V_1 , V_5 ) ;
}
static void F_37 ( struct V_1 * V_1 , int V_5 )
{
F_36 ( V_1 , V_5 ) ;
F_23 ( 100 ) ;
F_35 ( V_1 , V_5 ) ;
}
static void F_38 ( unsigned long V_175 )
{
struct V_1 * V_1 = (struct V_1 * ) V_175 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_1 -> V_32 ; V_31 ++ )
F_35 ( V_1 , V_31 ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
int V_31 ;
struct V_176 * V_177 = & V_1 -> V_177 ;
for ( V_31 = 0 ; V_31 < V_1 -> V_32 ; V_31 ++ ) {
F_7 ( V_1 , V_31 , V_139 , 0x6a ) ;
F_8 ( V_1 , V_31 , V_139 ) ;
}
F_40 ( V_177 , F_38 , ( unsigned long ) V_1 ) ;
F_41 ( V_177 , V_86 + V_178 ) ;
}
static void F_42 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_179 ;
V_179 = F_8 ( V_1 , V_5 , V_180 ) ;
V_179 |= V_181 ;
F_7 ( V_1 , V_5 , V_180 , V_179 ) ;
F_23 ( 1 ) ;
V_179 = F_8 ( V_1 , V_5 , V_180 ) ;
V_179 &= ~ V_181 ;
F_7 ( V_1 , V_5 , V_180 , V_179 ) ;
}
static int F_43 ( struct V_1 * V_1 , int V_182 )
{
int V_31 , V_183 = 0 ;
T_1 V_184 = F_1 ( V_1 , V_185 ) ;
T_1 V_186 = F_1 ( V_1 , V_187 ) ;
for ( V_31 = 0 ; V_31 < ( V_1 -> V_32 < 9 ? V_1 -> V_32 : 8 ) ; V_31 ++ )
if ( V_186 & 1 << V_31 )
if ( ( ( V_184 >> ( V_31 * 4 ) ) & 0xf ) == V_182 )
V_183 |= 1 << V_31 ;
if ( V_1 -> V_32 == 9 ) {
T_1 V_188 = F_1 ( V_1 , V_189 ) ;
if ( V_186 & 1 << 8 )
if ( ( ( V_188 & V_190 ) >>
V_191 ) == V_182 )
V_183 |= 1 << 9 ;
}
return V_183 ;
}
static int F_44 ( struct V_1 * V_1 , int * V_192 , int * V_193 )
{
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
T_1 V_194 , V_195 ;
int V_196 = V_1 -> V_196 ;
while ( 1 ) {
V_195 = F_3 ( V_1 ,
V_197 + ( V_196 * 0x14 ) ) ;
V_194 = F_3 ( V_1 ,
V_198 + ( V_196 * 0x14 ) ) ;
if ( V_194 == ( V_195 + 1 ) % V_153 ) {
V_196 = ( V_196 + 1 ) % V_1 -> V_103 ;
if ( V_196 == V_1 -> V_196 ) {
F_15 ( V_38 , L_8 ) ;
return - V_199 ;
}
continue;
}
break;
}
V_1 -> V_196 = ( V_196 + 1 ) % V_1 -> V_103 ;
* V_192 = V_196 ;
* V_193 = V_195 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_1 )
{
int V_200 = V_1 -> V_201 -> V_200 ;
int V_202 = V_1 -> V_201 -> V_202 ;
F_5 ( V_1 , V_197 + ( V_200 * 0x14 ) ,
++ V_202 % V_153 ) ;
}
static int F_46 ( struct V_1 * V_1 ,
struct V_203 * V_204 ,
struct V_205 * V_206 ,
struct V_207 * V_208 ,
int V_209 )
{
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
struct V_207 * V_210 ;
int V_31 ;
if ( V_209 > V_211 ) {
F_27 ( V_38 , L_9 ,
V_209 ) ;
return - V_212 ;
}
V_204 -> V_213 = F_47 ( V_1 -> V_214 , V_215 ,
& V_204 -> V_216 ) ;
if ( ! V_204 -> V_213 )
return - V_217 ;
F_48 (scatter, sg, n_elem, i) {
struct V_218 * V_219 = & V_204 -> V_213 -> V_220 [ V_31 ] ;
V_219 -> V_221 = F_16 ( F_49 ( V_210 ) ) ;
V_219 -> V_222 = V_219 -> V_223 = 0 ;
V_219 -> V_224 = F_50 ( F_51 ( V_210 ) ) ;
V_219 -> V_225 = 0 ;
}
V_206 -> V_226 = F_16 ( V_204 -> V_216 ) ;
V_206 -> V_227 = F_50 ( V_209 << V_228 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_1 ,
struct V_203 * V_204 )
{
struct V_229 * V_230 = V_204 -> V_230 ;
struct V_205 * V_206 = V_204 -> V_231 ;
struct V_35 * V_36 = V_230 -> V_38 ;
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
struct V_46 * V_47 = V_204 -> V_47 ;
struct V_207 * V_232 , * V_233 ;
struct V_33 * V_34 = V_36 -> V_234 ;
T_4 V_235 ;
unsigned int V_236 , V_237 ;
int V_238 , V_173 ;
V_232 = & V_230 -> V_239 . V_240 ;
V_238 = F_53 ( V_38 , V_232 , 1 , V_241 ) ;
if ( ! V_238 )
return - V_217 ;
V_236 = F_51 ( V_232 ) ;
V_235 = F_49 ( V_232 ) ;
V_233 = & V_230 -> V_239 . V_242 ;
V_238 = F_53 ( V_38 , V_233 , 1 , V_243 ) ;
if ( ! V_238 ) {
V_173 = - V_217 ;
goto V_244;
}
V_237 = F_51 ( V_233 ) ;
if ( ( V_236 & 0x3 ) || ( V_237 & 0x3 ) ) {
V_173 = - V_212 ;
goto V_245;
}
V_206 -> V_246 = F_50 ( ( V_47 -> V_60 << V_247 ) |
( 1 << V_248 ) |
( 2 << V_249 ) ) ;
V_206 -> V_250 = F_50 ( ( V_34 -> V_41 << V_251 ) |
( 1 << V_252 ) |
( V_253 << V_254 ) ) ;
V_206 -> V_255 = F_50 ( ( ( ( V_236 - 4 ) / 4 ) << V_256 ) |
( V_257 / 4 <<
V_258 ) ) ;
V_206 -> V_259 = F_50 ( V_204 -> V_260 << V_261 ) ;
V_206 -> V_262 = F_16 ( V_235 ) ;
V_206 -> V_263 = F_16 ( V_204 -> V_264 ) ;
return 0 ;
V_245:
F_54 ( V_38 , & V_204 -> V_230 -> V_239 . V_242 , 1 ,
V_243 ) ;
V_244:
F_54 ( V_38 , & V_204 -> V_230 -> V_239 . V_240 , 1 ,
V_241 ) ;
return V_173 ;
}
static int F_55 ( struct V_1 * V_1 ,
struct V_203 * V_204 , int V_265 ,
struct V_266 * V_267 )
{
struct V_229 * V_230 = V_204 -> V_230 ;
struct V_205 * V_206 = V_204 -> V_231 ;
struct V_35 * V_36 = V_230 -> V_38 ;
struct V_33 * V_34 = V_36 -> V_234 ;
struct V_46 * V_47 = V_204 -> V_47 ;
struct V_268 * V_269 = & V_230 -> V_269 ;
struct V_270 * V_270 = V_269 -> V_271 ;
int V_272 = 0 , V_173 , V_273 = V_265 ;
T_5 * V_274 ;
T_1 V_250 = 0 , V_255 = 0 ;
V_206 -> V_246 = F_50 ( ( 1 << V_275 ) |
( 2 << V_276 ) |
( V_47 -> V_60 << V_247 ) |
( V_273 << V_248 ) |
( 1 << V_249 ) ) ;
V_250 = 1 << V_277 ;
if ( V_265 ) {
V_250 |= 2 << V_252 ;
V_250 |= V_253 << V_254 ;
} else {
V_250 |= 1 << V_252 ;
switch ( V_270 -> V_278 ) {
case V_241 :
V_272 = 1 ;
V_250 |= V_279 << V_254 ;
break;
case V_243 :
V_272 = 1 ;
V_250 |= V_280 << V_254 ;
break;
default:
V_250 &= ~ V_281 ;
}
}
V_250 |= V_34 -> V_41 << V_251 ;
V_206 -> V_250 = F_50 ( V_250 ) ;
V_255 = ( ( ( sizeof( struct V_282 ) + sizeof( struct V_283 )
+ 3 ) / 4 ) << V_256 ) |
( ( V_284 / 4 ) << V_258 ) |
( 2 << V_285 ) ;
V_206 -> V_255 = F_50 ( V_255 ) ;
V_206 -> V_259 = F_50 ( V_204 -> V_260 ) ;
if ( V_272 ) {
V_173 = F_46 ( V_1 , V_204 , V_206 , V_230 -> V_208 ,
V_204 -> V_209 ) ;
if ( V_173 )
return V_173 ;
}
V_206 -> V_286 = F_50 ( V_230 -> V_287 ) ;
V_206 -> V_262 = F_16 ( V_204 -> V_288 ) ;
V_206 -> V_263 = F_16 ( V_204 -> V_264 ) ;
V_274 = V_204 -> V_289 + sizeof( struct V_283 ) ;
memcpy ( V_274 , & V_230 -> V_269 . V_290 , 8 ) ;
if ( ! V_265 ) {
V_274 [ 9 ] = V_230 -> V_269 . V_291 |
( V_230 -> V_269 . V_292 << 3 ) ;
memcpy ( V_274 + 12 , V_230 -> V_269 . V_271 -> V_293 ,
V_230 -> V_269 . V_271 -> V_294 ) ;
} else {
V_274 [ 10 ] = V_267 -> V_267 ;
switch ( V_267 -> V_267 ) {
case V_295 :
case V_296 :
V_274 [ 12 ] =
( V_267 -> V_297 >> 8 ) & 0xff ;
V_274 [ 13 ] =
V_267 -> V_297 & 0xff ;
break;
default:
break;
}
}
return 0 ;
}
static void F_56 ( struct V_1 * V_1 , struct V_229 * V_230 ,
struct V_203 * V_204 )
{
struct V_298 * V_299 = & V_230 -> V_300 ;
struct V_301 * V_302 = (struct V_301 * ) V_299 -> V_303 ;
struct V_304 * V_305 = V_204 -> V_306 +
sizeof( struct V_307 ) ;
V_302 -> V_308 = sizeof( struct V_304 ) ;
memcpy ( & V_302 -> V_309 [ 0 ] , V_305 , sizeof( struct V_304 ) ) ;
V_299 -> V_310 = sizeof( * V_302 ) ;
}
static void F_57 ( struct V_1 * V_1 ,
struct V_229 * V_230 ,
struct V_203 * V_204 )
{
struct V_298 * V_299 = & V_230 -> V_300 ;
struct V_311 * V_312 = V_204 -> V_306 ;
T_1 V_313 = F_50 ( V_312 -> V_313 ) ;
T_1 V_314 = F_50 ( V_312 -> V_314 ) ;
T_6 V_315 = F_58 ( V_312 -> V_315 ) ;
T_6 V_316 = F_58 ( V_312 -> V_316 ) ;
T_1 V_317 = F_50 ( V_312 -> V_317 ) ;
int error = - 1 ;
if ( V_317 ) {
error = F_59 ( V_317 )
- 1 + V_318 ;
} else if ( V_316 ) {
error = F_59 ( V_316 )
- 1 + V_319 ;
} else if ( V_315 ) {
error = F_59 ( V_315 )
- 1 + V_320 ;
} else if ( V_314 ) {
error = F_59 ( V_314 )
- 1 + V_321 ;
} else if ( V_313 ) {
error = F_59 ( V_313 )
- 1 + V_322 ;
}
switch ( V_230 -> V_323 ) {
case V_324 :
{
switch ( error ) {
case V_325 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_329 ;
break;
}
case V_330 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_331 ;
break;
}
case V_332 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_333 ;
break;
}
case V_334 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_335 ;
break;
}
case V_336 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_337 ;
break;
}
case V_338 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_339 ;
break;
}
case V_340 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_341 ;
break;
}
case V_342 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_343 ;
break;
}
case V_344 :
{
V_299 -> V_326 = V_345 ;
break;
}
case V_346 :
{
V_299 -> V_326 = V_347 ;
break;
}
case V_348 :
{
V_299 -> V_326 = V_349 ;
break;
}
case V_350 :
{
V_299 -> V_326 = V_351 ;
V_299 -> V_352 = 0 ;
break;
}
case V_353 :
case V_354 :
{
V_299 -> V_352 = V_313 ;
V_299 -> V_326 = V_355 ;
break;
}
case V_356 :
{
V_299 -> V_326 = V_357 ;
V_204 -> abort = 1 ;
break;
}
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
{
V_299 -> V_326 = V_327 ;
V_299 -> V_328 = V_343 ;
break;
}
default:
break;
}
}
break;
case V_396 :
V_299 -> V_326 = V_397 ;
break;
case V_398 :
case V_399 :
case V_398 | V_399 :
{
switch ( error ) {
case V_344 :
case V_330 :
case V_325 :
{
V_299 -> V_302 = V_400 ;
V_299 -> V_326 = V_345 ;
break;
}
case V_332 :
case V_334 :
case V_336 :
case V_338 :
case V_340 :
case V_342 :
case V_401 :
{
V_299 -> V_326 = V_327 ;
break;
}
case V_348 :
{
V_299 -> V_326 = V_349 ;
break;
}
case V_350 :
{
V_299 -> V_326 = V_351 ;
break;
}
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_373 :
case V_402 :
case V_375 :
case V_376 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_380 :
case V_346 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_394 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_395 :
{
V_299 -> V_326 = V_327 ;
break;
}
default:
{
V_299 -> V_326 = V_425 ;
break;
}
}
F_56 ( V_1 , V_230 , V_204 ) ;
}
break;
default:
break;
}
}
static int
F_60 ( struct V_1 * V_1 , struct V_203 * V_204 ,
int abort )
{
struct V_229 * V_230 = V_204 -> V_230 ;
struct V_33 * V_34 ;
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
struct V_298 * V_299 ;
struct V_35 * V_36 ;
enum V_426 V_427 ;
struct V_428 * V_429 =
V_1 -> V_430 [ V_204 -> V_431 ] ;
struct V_428 * V_430 =
& V_429 [ V_204 -> V_432 ] ;
if ( F_61 ( ! V_230 || ! V_230 -> V_433 || ! V_230 -> V_38 ) )
return - V_212 ;
V_299 = & V_230 -> V_300 ;
V_36 = V_230 -> V_38 ;
V_34 = V_36 -> V_234 ;
V_230 -> V_434 &=
~ ( V_435 | V_436 ) ;
V_230 -> V_434 |= V_437 ;
memset ( V_299 , 0 , sizeof( * V_299 ) ) ;
V_299 -> V_302 = V_438 ;
if ( F_61 ( ! V_34 || abort ) ) {
if ( ! V_34 )
F_20 ( V_38 , L_10 ) ;
V_299 -> V_326 = V_347 ;
goto V_439;
}
if ( ( V_430 -> V_246 & V_440 ) &&
( ! ( V_430 -> V_246 & V_441 ) ) ) {
F_57 ( V_1 , V_230 , V_204 ) ;
if ( F_61 ( V_204 -> abort ) ) {
F_62 ( V_1 -> V_442 , & V_204 -> V_443 ) ;
return V_299 -> V_326 ;
}
goto V_439;
}
switch ( V_230 -> V_323 ) {
case V_324 :
{
struct V_444 * V_445 = V_204 -> V_306 +
sizeof( struct V_307 ) ;
F_63 ( V_38 , V_230 , V_445 ) ;
break;
}
case V_396 :
{
struct V_207 * V_233 = & V_230 -> V_239 . V_242 ;
void * V_446 ;
V_299 -> V_326 = V_447 ;
V_446 = F_64 ( F_65 ( V_233 ) ) ;
F_54 ( V_38 , & V_230 -> V_239 . V_242 , 1 ,
V_243 ) ;
F_54 ( V_38 , & V_230 -> V_239 . V_240 , 1 ,
V_241 ) ;
memcpy ( V_446 + V_233 -> V_448 ,
V_204 -> V_306 +
sizeof( struct V_307 ) ,
F_51 ( V_233 ) ) ;
F_66 ( V_446 ) ;
break;
}
case V_398 :
case V_399 :
case V_398 | V_399 :
{
V_299 -> V_326 = V_447 ;
F_56 ( V_1 , V_230 , V_204 ) ;
break;
}
default:
V_299 -> V_326 = V_397 ;
break;
}
if ( ! V_204 -> V_47 -> V_449 ) {
F_27 ( V_38 , L_11 ,
V_204 -> V_47 -> V_450 . V_60 ) ;
V_299 -> V_326 = V_347 ;
}
V_439:
if ( V_34 && V_34 -> V_451 )
V_34 -> V_451 -- ;
F_67 ( V_1 , V_230 , V_204 ) ;
V_427 = V_299 -> V_326 ;
if ( V_230 -> V_452 )
V_230 -> V_452 ( V_230 ) ;
return V_427 ;
}
static T_5 F_68 ( T_5 V_271 , int V_453 )
{
switch ( V_271 ) {
case V_454 :
case V_455 :
return V_456 ;
case V_457 :
case V_458 :
case V_459 :
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
case V_465 :
return V_466 ;
case V_467 :
case V_468 :
case V_469 :
case V_470 :
case V_471 :
case V_472 :
case V_473 :
return V_474 ;
case V_475 :
case V_476 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
return V_485 ;
default:
if ( V_453 == V_486 )
return V_485 ;
return V_466 ;
}
}
static int F_69 ( struct V_229 * V_230 , T_1 * V_487 )
{
struct V_488 * V_489 = V_230 -> V_490 ;
if ( V_489 ) {
if ( V_489 -> V_491 . V_492 == V_454 ||
V_489 -> V_491 . V_492 == V_455 ) {
* V_487 = V_489 -> V_487 ;
return 1 ;
}
}
return 0 ;
}
static int F_70 ( struct V_1 * V_1 ,
struct V_203 * V_204 )
{
struct V_229 * V_230 = V_204 -> V_230 ;
struct V_35 * V_36 = V_230 -> V_38 ;
struct V_35 * V_44 = V_36 -> V_45 ;
struct V_33 * V_34 = V_36 -> V_234 ;
struct V_205 * V_206 = V_204 -> V_231 ;
struct V_46 * V_47 = V_36 -> V_47 -> V_48 ;
T_5 * V_274 ;
int V_272 = 0 , V_173 = 0 , V_493 = 0 ;
T_1 V_250 = 0 , V_255 = 0 ;
V_206 -> V_246 = F_50 ( V_47 -> V_60 << V_247 ) ;
if ( V_44 && F_14 ( V_44 -> V_13 ) )
V_206 -> V_246 |= F_50 ( 3 << V_249 ) ;
else
V_206 -> V_246 |= F_50 ( 4 << V_249 ) ;
switch ( V_230 -> V_494 ) {
case V_241 :
V_272 = 1 ;
V_250 |= V_279 << V_254 ;
break;
case V_243 :
V_272 = 1 ;
V_250 |= V_280 << V_254 ;
break;
default:
V_250 &= ~ V_281 ;
}
if ( 0 == V_230 -> V_495 . V_496 . V_492 )
V_250 |= 1 << V_497 ;
V_250 |= ( F_68 ( V_230 -> V_495 . V_496 . V_492 , V_230 -> V_494 ) )
<< V_252 ;
V_250 |= V_34 -> V_41 << V_251 ;
V_206 -> V_250 = F_50 ( V_250 ) ;
if ( V_230 -> V_495 . V_498 && F_69 ( V_230 , & V_493 ) ) {
V_230 -> V_495 . V_496 . V_499 |= ( T_5 ) ( V_493 << 3 ) ;
V_255 |= V_493 << V_500 ;
}
V_255 |= ( V_501 / 4 ) << V_256 |
2 << V_285 ;
V_206 -> V_255 = F_50 ( V_255 ) ;
V_206 -> V_259 = F_50 ( V_204 -> V_260 ) ;
if ( V_272 ) {
V_173 = F_46 ( V_1 , V_204 , V_206 , V_230 -> V_208 ,
V_204 -> V_209 ) ;
if ( V_173 )
return V_173 ;
}
V_206 -> V_286 = F_50 ( V_230 -> V_287 ) ;
V_206 -> V_262 = F_16 ( V_204 -> V_288 ) ;
V_206 -> V_263 = F_16 ( V_204 -> V_264 ) ;
V_274 = V_204 -> V_289 ;
if ( F_71 ( ! V_230 -> V_495 . V_502 ) )
V_230 -> V_495 . V_496 . V_503 |= 0x80 ;
memcpy ( V_274 , & V_230 -> V_495 . V_496 , sizeof( struct V_504 ) ) ;
return 0 ;
}
static int F_72 ( int V_5 , struct V_1 * V_1 )
{
int V_31 , V_505 = 0 ;
T_1 V_506 , V_182 , V_507 , V_508 ;
struct V_509 * V_510 = & V_1 -> V_510 [ V_5 ] ;
struct V_511 * V_512 = & V_510 -> V_512 ;
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
T_1 * V_513 = ( T_1 * ) V_512 -> V_513 ;
struct V_10 * V_60 = (struct V_10 * ) V_513 ;
F_7 ( V_1 , V_5 , V_144 , 1 ) ;
V_506 = F_1 ( V_1 , V_514 ) ;
if ( V_506 & ( 1 << V_5 ) )
goto V_515;
if ( V_5 == 8 ) {
T_1 V_188 = F_1 ( V_1 , V_189 ) ;
V_182 = ( V_188 & V_190 ) >>
V_191 ;
V_507 = ( V_188 & V_516 ) >>
V_517 ;
} else {
V_182 = F_1 ( V_1 , V_185 ) ;
V_182 = ( V_182 >> ( 4 * V_5 ) ) & 0xf ;
V_507 = F_1 ( V_1 , V_518 ) ;
V_507 = ( V_507 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_182 == 0xf ) {
F_27 ( V_38 , L_12 , V_5 ) ;
V_505 = V_519 ;
goto V_515;
}
for ( V_31 = 0 ; V_31 < 6 ; V_31 ++ ) {
T_1 V_520 = F_8 ( V_1 , V_5 ,
V_521 + ( V_31 * 4 ) ) ;
V_513 [ V_31 ] = F_11 ( V_520 ) ;
}
V_507 = F_1 ( V_1 , V_518 ) ;
V_507 = ( V_507 >> ( V_5 * 4 ) ) & 0xf ;
V_512 -> V_522 = V_507 ;
V_508 = F_8 ( V_1 , V_5 ,
V_523 ) ;
V_510 -> V_524 = V_508 & 0xf ;
V_510 -> V_525 = ( V_508 >> 4 ) & 0xf ;
V_512 -> V_526 = V_527 ;
memcpy ( V_512 -> V_528 , & V_60 -> V_22 , V_23 ) ;
F_73 ( V_38 , L_13 , V_5 , V_507 ) ;
V_510 -> V_182 = V_182 ;
V_510 -> V_529 &= ~ ( V_530 | V_531 ) ;
V_510 -> V_529 |= V_530 ;
V_510 -> V_532 = 1 ;
V_510 -> V_533 . V_534 = V_60 -> V_13 ;
V_510 -> V_535 = sizeof( struct V_10 ) ;
if ( V_510 -> V_533 . V_534 == V_14 )
V_510 -> V_533 . V_536 =
V_324 ;
else if ( V_510 -> V_533 . V_534 != V_75 )
V_510 -> V_533 . V_536 =
V_396 ;
F_62 ( V_1 -> V_442 , & V_510 -> V_537 ) ;
V_515:
F_7 ( V_1 , V_5 , V_134 ,
V_538 ) ;
F_7 ( V_1 , V_5 , V_144 , 0 ) ;
return V_505 ;
}
static int F_74 ( int V_5 , struct V_1 * V_1 )
{
int V_505 = 0 ;
T_1 V_82 , V_186 ;
F_7 ( V_1 , V_5 , V_142 , 1 ) ;
V_82 = F_8 ( V_1 , V_5 , V_7 ) ;
V_186 = F_1 ( V_1 , V_187 ) ;
F_75 ( V_1 , V_5 , ( V_186 & 1 << V_5 ) ? 1 : 0 ) ;
F_7 ( V_1 , V_5 , V_134 , V_539 ) ;
F_7 ( V_1 , V_5 , V_142 , 0 ) ;
return V_505 ;
}
static T_7 F_76 ( int V_540 , void * V_541 )
{
struct V_1 * V_1 = V_541 ;
T_1 V_542 ;
int V_5 = 0 ;
T_7 V_505 = V_543 ;
V_542 = ( F_1 ( V_1 , V_544 )
>> V_545 ) & 0x1ff ;
while ( V_542 ) {
if ( V_542 & 1 ) {
T_1 V_546 = F_8 ( V_1 , V_5 ,
V_134 ) ;
if ( V_546 & V_538 )
if ( F_72 ( V_5 , V_1 ) ) {
V_505 = V_519 ;
goto V_515;
}
if ( V_546 & V_539 )
if ( F_74 ( V_5 , V_1 ) ) {
V_505 = V_519 ;
goto V_515;
}
}
V_542 >>= 1 ;
V_5 ++ ;
}
V_515:
return V_505 ;
}
static void F_77 ( int V_5 , struct V_1 * V_1 )
{
struct V_509 * V_510 = & V_1 -> V_510 [ V_5 ] ;
struct V_511 * V_512 = & V_510 -> V_512 ;
struct V_547 * V_548 = & V_1 -> V_549 ;
unsigned long V_503 ;
F_7 ( V_1 , V_5 , V_145 , 1 ) ;
F_78 ( & V_1 -> V_550 , V_503 ) ;
V_548 -> V_551 ( V_512 , V_552 ) ;
F_79 ( & V_1 -> V_550 , V_503 ) ;
F_7 ( V_1 , V_5 , V_134 ,
V_553 ) ;
F_7 ( V_1 , V_5 , V_145 , 0 ) ;
}
static T_7 F_80 ( int V_540 , void * V_541 )
{
struct V_1 * V_1 = V_541 ;
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
T_1 V_554 , V_555 , V_542 ;
int V_5 = 0 ;
V_554 = F_1 ( V_1 , V_125 ) ;
V_555 = V_554 ;
V_554 |= V_556 ;
F_5 ( V_1 , V_125 , V_554 ) ;
V_542 = ( F_1 ( V_1 , V_544 ) >>
V_557 ) & 0x1ff ;
while ( V_542 ) {
if ( V_542 & ( 1 << V_5 ) ) {
T_1 V_558 = F_8 ( V_1 , V_5 ,
V_134 ) ;
T_1 V_559 = F_8 ( V_1 , V_5 ,
V_135 ) ;
T_1 V_560 = F_8 ( V_1 , V_5 ,
V_136 ) ;
if ( V_559 ) {
if ( V_559 & ( V_561 |
V_562 ) )
F_81 ( L_14 ,
F_82 ( V_38 ) , V_559 ) ;
F_7 ( V_1 , V_5 ,
V_135 , V_559 ) ;
}
if ( V_560 )
F_7 ( V_1 , V_5 ,
V_136 , V_560 ) ;
if ( V_558 ) {
if ( V_558 & V_553 )
F_77 ( V_5 , V_1 ) ;
F_7 ( V_1 , V_5 ,
V_134 , V_558
& ( ~ V_563 )
& ( ~ V_538 )
& ( ~ V_539 ) ) ;
}
}
V_542 &= ~ ( 1 << V_5 ) ;
V_5 ++ ;
}
F_5 ( V_1 , V_125 , V_555 ) ;
return V_543 ;
}
static T_7 F_83 ( int V_540 , void * V_541 )
{
struct V_564 * V_565 = V_541 ;
struct V_1 * V_1 = V_565 -> V_1 ;
struct V_203 * V_204 ;
struct V_42 * V_43 ;
struct V_428 * V_429 ;
T_1 V_546 , V_566 , V_567 , V_67 ;
int V_196 = V_565 -> V_60 ;
V_429 = V_1 -> V_430 [ V_196 ] ;
V_546 = F_1 ( V_1 , V_120 ) ;
F_5 ( V_1 , V_120 , 1 << V_196 ) ;
V_566 = F_1 ( V_1 , V_568 +
( 0x14 * V_196 ) ) ;
V_567 = F_1 ( V_1 , V_569 +
( 0x14 * V_196 ) ) ;
while ( V_566 != V_567 ) {
struct V_428 * V_430 ;
int V_570 ;
V_430 = & V_429 [ V_566 ] ;
if ( V_430 -> V_571 ) {
T_1 V_572 = V_430 -> V_571 ;
int V_573 = F_59 ( V_572 ) ;
V_67 = ( V_430 -> V_250 & V_574 ) >>
V_575 ;
V_43 = & V_1 -> V_43 [ V_67 ] ;
while ( V_573 ) {
T_8 * V_576 = & V_43 -> V_577 [ 0 ] ;
V_573 -= 1 ;
V_570 = ( V_576 [ V_573 / 5 ]
>> ( V_573 % 5 ) * 12 ) & 0xfff ;
V_204 = & V_1 -> V_578 [ V_570 ] ;
V_204 -> V_432 = V_566 ;
V_204 -> V_431 = V_196 ;
F_60 ( V_1 , V_204 , 0 ) ;
V_572 &= ~ ( 1 << V_573 ) ;
V_573 = F_59 ( V_572 ) ;
}
} else {
V_570 = ( V_430 -> V_250 ) & V_579 ;
V_204 = & V_1 -> V_578 [ V_570 ] ;
V_204 -> V_432 = V_566 ;
V_204 -> V_431 = V_196 ;
F_60 ( V_1 , V_204 , 0 ) ;
}
if ( ++ V_566 >= V_153 )
V_566 = 0 ;
}
F_5 ( V_1 , V_568 + ( 0x14 * V_196 ) , V_566 ) ;
return V_543 ;
}
static T_7 F_84 ( int V_540 , void * V_541 )
{
struct V_509 * V_510 = V_541 ;
struct V_1 * V_1 = V_510 -> V_1 ;
struct V_511 * V_512 = & V_510 -> V_512 ;
struct V_36 * V_38 = & V_1 -> V_39 -> V_38 ;
struct V_580 * V_581 ;
struct V_304 * V_496 ;
T_1 V_555 , V_554 , V_582 , V_182 , V_507 , V_508 ;
T_7 V_505 = V_543 ;
T_5 V_528 [ V_23 ] = { 0 } ;
int V_5 ;
V_5 = V_512 -> V_60 ;
V_581 = & V_1 -> V_581 [ V_5 ] ;
V_496 = & V_581 -> V_496 ;
V_554 = F_1 ( V_1 , V_123 ) ;
F_5 ( V_1 , V_123 , V_554 | 1 << V_5 ) ;
V_582 = F_1 ( V_1 , V_121 ) ;
V_555 = V_582 ;
V_582 >>= V_583 * ( V_5 % 4 ) ;
if ( ( V_582 & V_584 ) == 0 ) {
F_15 ( V_38 , L_15 , V_5 ) ;
F_5 ( V_1 , V_121 , V_555 ) ;
F_5 ( V_1 , V_123 , V_554 ) ;
V_505 = V_519 ;
goto V_515;
}
if ( F_61 ( V_5 == 8 ) ) {
T_1 V_188 = F_1 ( V_1 , V_189 ) ;
V_182 = ( V_188 & V_190 ) >>
V_191 ;
V_507 = ( V_188 & V_516 ) >>
V_517 ;
} else {
V_182 = F_1 ( V_1 , V_185 ) ;
V_182 = ( V_182 >> ( 4 * V_5 ) ) & 0xf ;
V_507 = F_1 ( V_1 , V_518 ) ;
V_507 = ( V_507 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_182 == 0xf ) {
F_27 ( V_38 , L_16 , V_5 ) ;
V_505 = V_519 ;
goto V_515;
}
V_512 -> V_522 = V_507 ;
V_508 = F_8 ( V_1 , V_5 ,
V_523 ) ;
V_510 -> V_524 = V_508 & 0xf ;
V_510 -> V_525 = ( V_508 >> 4 ) & 0xf ;
V_512 -> V_526 = V_585 ;
V_528 [ 0 ] = 0x50 ;
V_528 [ 7 ] = V_5 ;
memcpy ( V_512 -> V_528 , V_528 , V_23 ) ;
memcpy ( V_512 -> V_513 , V_496 , sizeof( struct V_304 ) ) ;
F_73 ( V_38 , L_17 , V_5 , V_507 ) ;
V_510 -> V_529 &= ~ ( V_530 | V_531 ) ;
V_510 -> V_182 = V_182 ;
V_510 -> V_529 |= V_531 ;
V_510 -> V_532 = 1 ;
V_510 -> V_533 . V_534 = V_53 ;
V_510 -> V_535 = sizeof( struct V_304 ) ;
V_510 -> V_533 . V_536 = V_398 ;
F_62 ( V_1 -> V_442 , & V_510 -> V_537 ) ;
V_515:
F_5 ( V_1 , V_121 , V_555 ) ;
F_5 ( V_1 , V_123 , V_554 ) ;
return V_505 ;
}
static int F_85 ( struct V_1 * V_1 )
{
struct V_586 * V_39 = V_1 -> V_39 ;
struct V_36 * V_38 = & V_39 -> V_38 ;
int V_31 , V_587 , V_173 , V_588 [ 128 ] ;
for ( V_31 = 0 ; V_31 < 128 ; V_31 ++ )
V_588 [ V_31 ] = F_86 ( V_39 , V_31 ) ;
for ( V_31 = 0 ; V_31 < V_589 ; V_31 ++ ) {
int V_260 = V_31 ;
V_587 = V_588 [ V_260 + 1 ] ;
if ( ! V_587 ) {
F_27 ( V_38 , L_18 ,
V_260 ) ;
return - V_590 ;
}
V_173 = F_87 ( V_38 , V_587 , V_591 [ V_31 ] , 0 ,
V_592 L_19 , V_1 ) ;
if ( V_173 ) {
F_27 ( V_38 , L_20
L_21 ,
V_587 , V_173 ) ;
return - V_590 ;
}
}
for ( V_31 = 0 ; V_31 < V_1 -> V_32 ; V_31 ++ ) {
struct V_509 * V_510 = & V_1 -> V_510 [ V_31 ] ;
int V_260 = V_31 + 72 ;
V_587 = V_588 [ V_260 ] ;
if ( ! V_587 ) {
F_27 ( V_38 , L_18 ,
V_260 ) ;
return - V_590 ;
}
V_173 = F_87 ( V_38 , V_587 , F_84 , 0 ,
V_592 L_22 , V_510 ) ;
if ( V_173 ) {
F_27 ( V_38 , L_20
L_23 ,
V_587 , V_173 ) ;
return - V_590 ;
}
}
for ( V_31 = 0 ; V_31 < V_1 -> V_103 ; V_31 ++ ) {
int V_260 = V_31 + 96 ;
V_587 = V_588 [ V_260 ] ;
if ( ! V_587 ) {
F_27 ( V_38 ,
L_24 ,
V_260 ) ;
return - V_590 ;
}
V_173 = F_87 ( V_38 , V_587 , F_83 , 0 ,
V_592 L_25 , & V_1 -> V_565 [ V_31 ] ) ;
if ( V_173 ) {
F_27 ( V_38 ,
L_26 ,
V_587 , V_173 ) ;
return - V_590 ;
}
}
return 0 ;
}
static int F_88 ( struct V_1 * V_1 )
{
int V_173 ;
V_173 = F_32 ( V_1 ) ;
if ( V_173 )
return V_173 ;
V_173 = F_85 ( V_1 ) ;
if ( V_173 )
return V_173 ;
F_39 ( V_1 ) ;
return 0 ;
}
static int F_89 ( struct V_586 * V_39 )
{
return F_90 ( V_39 , & V_593 ) ;
}
static int F_91 ( struct V_586 * V_39 )
{
return F_92 ( V_39 ) ;
}
