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
static void F_5 ( struct V_1 * V_1 ,
T_1 V_2 , T_1 V_4 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
F_6 ( V_4 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_1 ,
int V_5 , T_1 V_2 , T_1 V_4 )
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
T_1 V_6 = F_8 ( V_1 , V_5 , V_10 ) ;
V_6 &= ~ V_11 ;
F_7 ( V_1 , V_5 , V_10 , V_6 ) ;
}
static void F_11 ( struct V_1 * V_1 , int V_5 )
{
struct V_12 V_13 ;
T_1 * V_14 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_15 = V_16 ;
V_13 . V_17 = 0 ;
V_13 . V_18 = 1 ;
V_13 . V_19 = V_20 ;
V_13 . V_21 = V_22 ;
memcpy ( & V_13 . V_23 [ 0 ] , V_1 -> V_24 , V_25 ) ;
memcpy ( & V_13 . V_24 [ 0 ] , V_1 -> V_24 , V_25 ) ;
V_13 . V_26 = V_5 ;
V_14 = ( T_1 * ) ( & V_13 ) ;
F_7 ( V_1 , V_5 , V_27 ,
F_12 ( V_14 [ 0 ] ) ) ;
F_7 ( V_1 , V_5 , V_28 ,
V_14 [ 2 ] ) ;
F_7 ( V_1 , V_5 , V_29 ,
V_14 [ 1 ] ) ;
F_7 ( V_1 , V_5 , V_30 ,
V_14 [ 4 ] ) ;
F_7 ( V_1 , V_5 , V_31 ,
V_14 [ 3 ] ) ;
F_7 ( V_1 , V_5 , V_32 ,
F_12 ( V_14 [ 5 ] ) ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ )
F_11 ( V_1 , V_33 ) ;
}
static void F_14 ( struct V_1 * V_1 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_39 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
T_3 V_42 , V_43 = V_36 -> V_43 ;
struct V_44 * V_45 = & V_1 -> V_45 [ V_43 ] ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_42 = 0 ;
switch ( V_36 -> V_15 ) {
case V_16 :
case V_46 :
case V_47 :
V_42 = V_48 << V_49 ;
break;
default:
F_15 ( V_40 , L_1 ,
V_36 -> V_15 ) ;
}
V_42 |= ( ( 1 << V_50 ) |
( 1 << V_51 ) |
( V_38 -> V_52 << V_53 ) |
( 1 << V_54 ) |
( V_38 -> V_55 -> V_56 << V_57 ) ) ;
V_45 -> V_42 = F_16 ( V_42 ) ;
memcpy ( & V_45 -> V_24 , V_38 -> V_24 , V_25 ) ;
V_45 -> V_24 = F_17 ( V_45 -> V_24 ) ;
V_45 -> V_58 = F_16 ( ( 500ULL << V_59 ) |
( 0xff00ULL << V_60 ) |
( 0xff00ULL << V_61 ) |
( 0xff00ULL << V_62 ) ) ;
}
static void F_18 ( struct V_1 * V_1 ,
struct V_35 * V_36 )
{
T_3 V_63 = V_36 -> V_43 ;
struct V_44 * V_45 = & V_1 -> V_45 [ V_63 ] ;
T_3 V_42 ;
T_1 V_64 = F_1 ( V_1 , V_65 ) ;
V_64 |= V_66 ;
F_5 ( V_1 , V_65 , V_64 ) ;
F_19 ( 1 ) ;
V_64 = F_1 ( V_1 , V_65 ) ;
V_64 &= ~ V_66 ;
F_5 ( V_1 , V_65 , V_64 ) ;
V_42 = F_16 ( V_45 -> V_42 ) ;
V_42 &= ~ V_67 ;
V_45 -> V_42 = F_16 ( V_42 ) ;
}
static int F_20 ( struct V_1 * V_1 )
{
int V_33 ;
unsigned long V_68 ;
T_1 V_4 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ ) {
T_1 V_69 = F_8 ( V_1 , V_33 , V_70 ) ;
V_69 |= V_71 ;
F_7 ( V_1 , V_33 , V_70 , V_69 ) ;
}
F_21 ( 1 ) ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ ) {
T_1 V_72 , V_73 ;
V_68 = V_74 + F_22 ( 1000 ) ;
while ( 1 ) {
V_72 = F_8 ( V_1 , V_33 ,
V_75 ) ;
V_73 = F_8 ( V_1 , V_33 ,
V_76 ) ;
if ( ! ( V_72 & V_77 ) &&
! ( V_73 & V_78 ) )
break;
F_21 ( 20 ) ;
if ( F_23 ( V_74 , V_68 ) )
return - V_79 ;
}
}
V_68 = V_74 + F_22 ( 1000 ) ;
while ( 1 ) {
T_1 V_80 =
F_1 ( V_1 , V_81 ) ;
if ( V_80 == 0 )
break;
F_21 ( 20 ) ;
if ( F_23 ( V_74 , V_68 ) )
return - V_79 ;
}
F_24 ( V_1 -> V_82 , V_1 -> V_83 ,
V_84 ) ;
F_24 ( V_1 -> V_82 , V_1 -> V_85 + 4 ,
V_84 ) ;
F_21 ( 1 ) ;
F_25 ( V_1 -> V_82 , V_1 -> V_86 , & V_4 ) ;
if ( V_84 != ( V_4 & V_84 ) ) {
F_26 ( V_40 , L_2 ) ;
return - V_79 ;
}
F_24 ( V_1 -> V_82 , V_1 -> V_83 + 4 ,
V_84 ) ;
F_24 ( V_1 -> V_82 , V_1 -> V_85 ,
V_84 ) ;
F_21 ( 1 ) ;
F_25 ( V_1 -> V_82 , V_1 -> V_86 , & V_4 ) ;
if ( V_4 & V_84 ) {
F_26 ( V_40 , L_3 ) ;
return - V_79 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_1 )
{
int V_33 ;
F_5 ( V_1 , V_87 ,
( T_1 ) ( ( 1ULL << V_1 -> V_88 ) - 1 ) ) ;
F_5 ( V_1 , V_89 , 0x11 ) ;
F_5 ( V_1 , V_90 , 0x1 ) ;
F_5 ( V_1 , V_91 , 0x1ff ) ;
F_5 ( V_1 , V_92 , 0x401 ) ;
F_5 ( V_1 , V_93 , 0x64 ) ;
F_5 ( V_1 , V_94 , 0x1 ) ;
F_5 ( V_1 , V_95 , 0x64 ) ;
F_5 ( V_1 , V_96 , 0x2710 ) ;
F_5 ( V_1 , V_97 , 0x1 ) ;
F_5 ( V_1 , V_65 , 0x7a12 ) ;
F_5 ( V_1 , V_98 , 0x9c40 ) ;
F_5 ( V_1 , V_99 , 0x2 ) ;
F_5 ( V_1 , V_100 , 0xc ) ;
F_5 ( V_1 , V_101 , 0x186a0 ) ;
F_5 ( V_1 , V_102 , 1 ) ;
F_5 ( V_1 , V_103 , 0x1 ) ;
F_5 ( V_1 , V_104 , 0x1 ) ;
F_5 ( V_1 , V_105 , 0xffffffff ) ;
F_5 ( V_1 , V_106 , 0 ) ;
F_5 ( V_1 , V_107 , 0xffffffff ) ;
F_5 ( V_1 , V_108 , 0 ) ;
F_5 ( V_1 , V_109 , 0xffffffff ) ;
F_5 ( V_1 , V_110 , 0 ) ;
F_5 ( V_1 , V_111 , 0 ) ;
F_5 ( V_1 , V_112 , 0x2 ) ;
F_5 ( V_1 , V_113 , 0x22000000 ) ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ ) {
F_7 ( V_1 , V_33 , V_114 , 0x88a ) ;
F_7 ( V_1 , V_33 , V_10 , 0x7c080 ) ;
F_7 ( V_1 , V_33 , V_115 , 0x415ee00 ) ;
F_7 ( V_1 , V_33 , V_116 , 0x80a80000 ) ;
F_7 ( V_1 , V_33 , V_117 , 0x7d7d7d7d ) ;
F_7 ( V_1 , V_33 , V_118 , 0x0 ) ;
F_7 ( V_1 , V_33 , V_119 , 0x1000 ) ;
F_7 ( V_1 , V_33 , V_118 , 0 ) ;
F_7 ( V_1 , V_33 , V_120 , 0x13f0a ) ;
F_7 ( V_1 , V_33 , V_121 , 3 ) ;
F_7 ( V_1 , V_33 , V_118 , 8 ) ;
}
for ( V_33 = 0 ; V_33 < V_1 -> V_88 ; V_33 ++ ) {
F_5 ( V_1 ,
V_122 + ( V_33 * 0x14 ) ,
F_28 ( V_1 -> V_123 [ V_33 ] ) ) ;
F_5 ( V_1 ,
V_124 + ( V_33 * 0x14 ) ,
F_29 ( V_1 -> V_123 [ V_33 ] ) ) ;
F_5 ( V_1 ,
V_125 + ( V_33 * 0x14 ) ,
V_126 ) ;
F_5 ( V_1 ,
V_127 + ( V_33 * 0x14 ) ,
F_28 ( V_1 -> V_128 [ V_33 ] ) ) ;
F_5 ( V_1 ,
V_129 + ( V_33 * 0x14 ) ,
F_29 ( V_1 -> V_128 [ V_33 ] ) ) ;
F_5 ( V_1 , V_130 + ( V_33 * 0x14 ) ,
V_126 ) ;
}
F_5 ( V_1 , V_131 ,
F_29 ( V_1 -> V_132 ) ) ;
F_5 ( V_1 , V_133 ,
F_28 ( V_1 -> V_132 ) ) ;
F_5 ( V_1 , V_134 ,
F_29 ( V_1 -> V_135 ) ) ;
F_5 ( V_1 , V_136 ,
F_28 ( V_1 -> V_135 ) ) ;
F_5 ( V_1 , V_137 ,
F_29 ( V_1 -> V_138 ) ) ;
F_5 ( V_1 , V_139 ,
F_28 ( V_1 -> V_138 ) ) ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
int V_140 ;
V_140 = F_20 ( V_1 ) ;
if ( V_140 ) {
F_26 ( V_40 , L_4 , V_140 ) ;
return V_140 ;
}
F_21 ( 100 ) ;
F_27 ( V_1 ) ;
F_13 ( V_1 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_6 = F_8 ( V_1 , V_5 , V_7 ) ;
V_6 |= V_141 ;
F_7 ( V_1 , V_5 , V_7 , V_6 ) ;
}
static void F_32 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_6 = F_8 ( V_1 , V_5 , V_7 ) ;
V_6 &= ~ V_141 ;
F_7 ( V_1 , V_5 , V_7 , V_6 ) ;
}
static void F_33 ( struct V_1 * V_1 , int V_5 )
{
F_11 ( V_1 , V_5 ) ;
F_9 ( V_1 , V_5 ) ;
F_10 ( V_1 , V_5 ) ;
F_31 ( V_1 , V_5 ) ;
}
static void F_34 ( struct V_1 * V_1 , int V_5 )
{
F_32 ( V_1 , V_5 ) ;
}
static void F_35 ( struct V_1 * V_1 , int V_5 )
{
F_34 ( V_1 , V_5 ) ;
F_21 ( 100 ) ;
F_33 ( V_1 , V_5 ) ;
}
static void F_36 ( unsigned long V_142 )
{
struct V_1 * V_1 = (struct V_1 * ) V_142 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ ) {
F_7 ( V_1 , V_33 , V_143 , 0x12a ) ;
F_33 ( V_1 , V_33 ) ;
}
}
static void F_37 ( struct V_1 * V_1 )
{
int V_33 ;
struct V_144 * V_145 = & V_1 -> V_145 ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ ) {
F_7 ( V_1 , V_33 , V_143 , 0x6a ) ;
F_8 ( V_1 , V_33 , V_143 ) ;
}
F_38 ( V_145 , F_36 , ( unsigned long ) V_1 ) ;
F_39 ( V_145 , V_74 + V_146 ) ;
}
static void F_40 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_147 ;
V_147 = F_8 ( V_1 , V_5 , V_148 ) ;
V_147 |= V_149 ;
F_7 ( V_1 , V_5 , V_148 , V_147 ) ;
F_21 ( 1 ) ;
V_147 = F_8 ( V_1 , V_5 , V_148 ) ;
V_147 &= ~ V_149 ;
F_7 ( V_1 , V_5 , V_148 , V_147 ) ;
}
static int F_41 ( struct V_1 * V_1 , int V_150 )
{
int V_33 , V_151 = 0 ;
T_1 V_152 = F_1 ( V_1 , V_153 ) ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ )
if ( ( ( V_152 >> ( V_33 * 4 ) ) & 0xf ) == V_150 )
V_151 |= 1 << V_33 ;
return V_151 ;
}
static int F_42 ( struct V_1 * V_1 , int * V_154 , int * V_155 )
{
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
T_1 V_156 , V_157 ;
int V_158 = V_1 -> V_158 ;
while ( 1 ) {
V_157 = F_3 ( V_1 ,
V_159 + ( V_158 * 0x14 ) ) ;
V_156 = F_3 ( V_1 ,
V_160 + ( V_158 * 0x14 ) ) ;
if ( V_156 == ( V_157 + 1 ) % V_126 ) {
V_158 = ( V_158 + 1 ) % V_1 -> V_88 ;
if ( V_158 == V_1 -> V_158 ) {
F_15 ( V_40 , L_5 ) ;
return - V_161 ;
}
continue;
}
break;
}
V_1 -> V_158 = ( V_158 + 1 ) % V_1 -> V_88 ;
* V_154 = V_158 ;
* V_155 = V_157 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_1 )
{
int V_162 = V_1 -> V_163 -> V_162 ;
int V_164 = V_1 -> V_163 -> V_164 ;
F_5 ( V_1 ,
V_159 + ( V_162 * 0x14 ) ,
++ V_164 % V_126 ) ;
}
static int F_44 ( struct V_1 * V_1 ,
struct V_165 * V_166 ,
struct V_167 * V_168 ,
struct V_169 * V_170 ,
int V_171 )
{
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
struct V_169 * V_172 ;
int V_33 ;
if ( V_171 > V_173 ) {
F_26 ( V_40 , L_6 ,
V_171 ) ;
return - V_174 ;
}
V_166 -> V_175 = F_45 ( V_1 -> V_176 , V_177 ,
& V_166 -> V_178 ) ;
if ( ! V_166 -> V_175 )
return - V_179 ;
F_46 (scatter, sg, n_elem, i) {
struct V_180 * V_181 = & V_166 -> V_175 -> V_182 [ V_33 ] ;
V_181 -> V_183 = F_16 ( F_47 ( V_172 ) ) ;
V_181 -> V_184 = V_181 -> V_185 = 0 ;
V_181 -> V_186 = F_48 ( F_49 ( V_172 ) ) ;
V_181 -> V_187 = 0 ;
}
V_168 -> V_188 = F_16 ( V_166 -> V_178 ) ;
V_168 -> V_189 = F_48 ( V_171 << V_190 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_1 ,
struct V_165 * V_166 )
{
struct V_191 * V_192 = V_166 -> V_192 ;
struct V_167 * V_168 = V_166 -> V_193 ;
struct V_37 * V_38 = V_192 -> V_40 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
struct V_194 * V_55 = V_166 -> V_55 ;
struct V_169 * V_195 , * V_196 ;
struct V_35 * V_36 = V_38 -> V_197 ;
T_4 V_198 ;
unsigned int V_199 , V_200 ;
int V_201 , V_140 ;
V_195 = & V_192 -> V_202 . V_203 ;
V_201 = F_51 ( V_40 , V_195 , 1 , V_204 ) ;
if ( ! V_201 )
return - V_179 ;
V_199 = F_49 ( V_195 ) ;
V_198 = F_47 ( V_195 ) ;
V_196 = & V_192 -> V_202 . V_205 ;
V_201 = F_51 ( V_40 , V_196 , 1 , V_206 ) ;
if ( ! V_201 ) {
V_140 = - V_179 ;
goto V_207;
}
V_200 = F_49 ( V_196 ) ;
if ( ( V_199 & 0x3 ) || ( V_200 & 0x3 ) ) {
V_140 = - V_174 ;
goto V_208;
}
V_168 -> V_209 = F_48 ( ( V_55 -> V_56 << V_210 ) |
( 1 << V_211 ) |
( 1 << V_212 ) |
( 2 << V_213 ) ) ;
V_168 -> V_214 = F_48 ( V_36 -> V_43 << V_215 ) ;
V_168 -> V_216 = F_48 ( ( ( ( V_199 - 4 ) / 4 ) << V_217 ) |
( V_218 / 4 <<
V_219 ) ) ;
V_168 -> V_220 = F_48 ( V_166 -> V_221 << V_222 ) ;
V_168 -> V_223 = F_16 ( V_198 ) ;
V_168 -> V_224 = F_16 ( V_166 -> V_225 ) ;
return 0 ;
V_208:
F_52 ( V_40 , & V_166 -> V_192 -> V_202 . V_205 , 1 ,
V_206 ) ;
V_207:
F_52 ( V_40 , & V_166 -> V_192 -> V_202 . V_203 , 1 ,
V_204 ) ;
return V_140 ;
}
static int F_53 ( struct V_1 * V_1 ,
struct V_165 * V_166 , int V_226 ,
struct V_227 * V_228 )
{
struct V_191 * V_192 = V_166 -> V_192 ;
struct V_167 * V_168 = V_166 -> V_193 ;
struct V_37 * V_38 = V_192 -> V_40 ;
struct V_35 * V_36 = V_38 -> V_197 ;
struct V_194 * V_55 = V_166 -> V_55 ;
struct V_229 * V_230 = & V_192 -> V_230 ;
struct V_231 * V_231 = V_230 -> V_232 ;
int V_233 = 0 , V_140 , V_234 = V_226 ;
T_5 * V_235 , V_236 = 0 ;
T_1 V_214 , V_216 ;
V_168 -> V_209 = F_48 ( ( 1 << V_237 ) |
( 0x2 << V_238 ) |
( V_55 -> V_56 << V_210 ) |
( V_234 << V_211 ) |
( 1 << V_212 ) |
( 1 << V_213 ) ) ;
V_214 = 1 << V_239 ;
if ( V_226 ) {
V_214 |= 3 << V_240 ;
} else {
switch ( V_231 -> V_241 ) {
case V_204 :
V_214 |= 2 << V_240 ;
V_233 = 1 ;
break;
case V_206 :
V_214 |= 1 << V_240 ;
V_233 = 1 ;
break;
default:
V_214 |= 0 << V_240 ;
}
}
V_214 |= V_36 -> V_43 << V_215 ;
V_168 -> V_214 = F_48 ( V_214 ) ;
if ( V_226 ) {
V_216 = ( ( sizeof( struct V_242 ) +
sizeof( struct V_243 ) + 3 ) / 4 ) <<
V_217 ;
} else {
V_216 = ( ( sizeof( struct V_244 ) +
sizeof( struct V_243 ) + 3 ) / 4 ) <<
V_217 ;
}
V_216 |= ( V_245 / 4 ) << V_219 ;
V_168 -> V_220 = F_48 ( V_166 -> V_221 << V_222 ) ;
if ( V_233 ) {
V_140 = F_44 ( V_1 , V_166 , V_168 , V_192 -> V_170 ,
V_166 -> V_171 ) ;
if ( V_140 )
return V_140 ;
}
V_168 -> V_246 = F_48 ( V_192 -> V_247 ) ;
V_168 -> V_223 = F_16 ( V_166 -> V_248 ) ;
V_168 -> V_224 = F_16 ( V_166 -> V_225 ) ;
V_235 = V_166 -> V_249 + sizeof( struct V_243 ) ;
if ( V_192 -> V_230 . V_250 ) {
V_236 = ( 1 << 7 ) ;
V_216 |= 1 << V_251 ;
}
V_168 -> V_216 = F_48 ( V_216 ) ;
memcpy ( V_235 , & V_192 -> V_230 . V_252 , 8 ) ;
if ( ! V_226 ) {
V_235 [ 9 ] = V_236 | V_192 -> V_230 . V_253 |
( V_192 -> V_230 . V_254 << 3 ) ;
memcpy ( V_235 + 12 , V_192 -> V_230 . V_232 -> V_255 ,
V_192 -> V_230 . V_232 -> V_256 ) ;
} else {
V_235 [ 10 ] = V_228 -> V_228 ;
switch ( V_228 -> V_228 ) {
case V_257 :
case V_258 :
V_235 [ 12 ] =
( V_228 -> V_259 >> 8 ) & 0xff ;
V_235 [ 13 ] =
V_228 -> V_259 & 0xff ;
break;
default:
break;
}
}
return 0 ;
}
static void F_54 ( struct V_1 * V_1 ,
struct V_191 * V_192 ,
struct V_165 * V_166 )
{
struct V_260 * V_261 = & V_192 -> V_262 ;
struct V_263 * V_264 = V_166 -> V_265 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
switch ( V_192 -> V_266 ) {
case V_267 :
{
int error = - 1 ;
T_1 V_268 = F_48 ( V_264 -> V_268 ) ;
T_1 V_269 = ( ( V_268 &
V_270 ) ) >>
V_271 ;
T_1 V_272 = ( ( V_268 &
V_273 ) ) >>
V_274 ;
T_1 V_275 =
F_48 ( V_264 -> V_275 ) ;
T_1 V_276 =
F_48 ( V_264 -> V_276 ) ;
if ( V_269 ) {
error = F_55 ( V_269 )
- 1 + V_277 ;
} else if ( V_272 ) {
error = F_55 ( V_272 )
- 1 + V_278 ;
} else if ( V_275 ) {
error = F_55 ( V_275 )
- 1 + V_279 ;
} else if ( V_276 ) {
error = F_55 ( V_276 )
- 1 + V_280 ;
}
switch ( error ) {
case V_281 :
case V_282 :
{
V_261 -> V_283 = 0 ;
V_261 -> V_284 = V_285 ;
break;
}
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
{
V_261 -> V_284 = V_292 ;
V_261 -> V_283 = 0 ;
break;
}
case V_293 :
{
V_261 -> V_284 = V_294 ;
break;
}
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_305 :
case V_306 :
{
V_261 -> V_284 = V_307 ;
V_261 -> V_308 = V_309 ;
break;
}
case V_310 :
{
V_261 -> V_284 = V_311 ;
break;
}
case V_312 :
case V_313 :
{
V_261 -> V_284 = V_314 ;
break;
}
default:
{
V_261 -> V_284 = V_315 ;
break;
}
}
}
break;
case V_316 :
V_261 -> V_284 = V_315 ;
break;
case V_317 :
case V_318 :
case V_317 | V_318 :
{
F_26 ( V_40 , L_7 ) ;
}
break;
default:
break;
}
}
static int F_56 ( struct V_1 * V_1 ,
struct V_165 * V_166 , int abort )
{
struct V_191 * V_192 = V_166 -> V_192 ;
struct V_35 * V_36 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
struct V_260 * V_261 ;
struct V_37 * V_38 ;
enum V_319 V_320 ;
struct V_321 * V_322 =
(struct V_321 * )
V_1 -> V_323 [ V_166 -> V_324 ] ;
struct V_321 * V_323 ;
T_1 V_325 ;
V_323 = & V_322 [ V_166 -> V_326 ] ;
V_325 = F_57 ( V_323 -> V_142 ) ;
if ( F_58 ( ! V_192 || ! V_192 -> V_327 || ! V_192 -> V_40 ) )
return - V_174 ;
V_261 = & V_192 -> V_262 ;
V_38 = V_192 -> V_40 ;
V_36 = V_38 -> V_197 ;
V_192 -> V_328 &=
~ ( V_329 | V_330 ) ;
V_192 -> V_328 |= V_331 ;
memset ( V_261 , 0 , sizeof( * V_261 ) ) ;
V_261 -> V_332 = V_333 ;
if ( F_58 ( ! V_36 || abort ) ) {
if ( ! V_36 )
F_59 ( V_40 , L_8 ) ;
V_261 -> V_284 = V_294 ;
goto V_334;
}
if ( V_325 & V_335 ) {
T_1 V_336 = F_1 ( V_1 , V_337 ) ;
if ( V_336 & V_338 )
F_26 ( V_40 , L_9 ,
V_166 -> V_324 , V_166 -> V_326 ) ;
if ( V_336 & V_339 )
F_26 ( V_40 , L_10 ,
V_166 -> V_324 , V_166 -> V_326 ) ;
if ( V_336 & V_340 )
F_26 ( V_40 , L_11 ,
V_166 -> V_324 , V_166 -> V_326 ) ;
if ( V_336 & V_341 )
F_26 ( V_40 , L_12 ,
V_166 -> V_324 , V_166 -> V_326 ) ;
if ( V_336 & V_342 )
F_26 ( V_40 , L_13 ,
V_166 -> V_324 , V_166 -> V_326 ) ;
if ( V_336 & V_343 )
F_26 ( V_40 , L_14 ,
V_166 -> V_324 , V_166 -> V_326 ) ;
if ( V_336 & V_344 )
F_26 ( V_40 , L_15 ,
V_166 -> V_324 , V_166 -> V_326 ) ;
if ( V_336 & V_345 )
F_26 ( V_40 , L_16 ,
V_166 -> V_324 , V_166 -> V_326 ) ;
V_261 -> V_284 = V_307 ;
V_261 -> V_308 = V_309 ;
goto V_334;
}
if ( V_325 & V_346 &&
! ( V_325 & V_347 ) ) {
F_54 ( V_1 , V_192 , V_166 ) ;
goto V_334;
}
switch ( V_192 -> V_266 ) {
case V_267 :
{
struct V_348 * V_349 = V_166 -> V_265 +
sizeof( struct V_263 ) ;
F_60 ( V_40 , V_192 , V_349 ) ;
break;
}
case V_316 :
{
void * V_350 ;
struct V_169 * V_196 = & V_192 -> V_202 . V_205 ;
V_261 -> V_284 = V_351 ;
V_350 = F_61 ( F_62 ( V_196 ) ) ;
F_52 ( V_40 , & V_192 -> V_202 . V_205 , 1 ,
V_206 ) ;
F_52 ( V_40 , & V_192 -> V_202 . V_203 , 1 ,
V_204 ) ;
memcpy ( V_350 + V_196 -> V_352 ,
V_166 -> V_265 +
sizeof( struct V_263 ) ,
F_49 ( V_196 ) ) ;
F_63 ( V_350 ) ;
break;
}
case V_317 :
case V_318 :
case V_317 | V_318 :
F_26 ( V_40 , L_17 ) ;
break;
default:
V_261 -> V_284 = V_315 ;
break;
}
if ( ! V_166 -> V_55 -> V_353 ) {
F_26 ( V_40 , L_18 ,
V_166 -> V_55 -> V_354 . V_56 ) ;
V_261 -> V_284 = V_294 ;
}
V_334:
if ( V_36 && V_36 -> V_355 )
V_36 -> V_355 -- ;
F_64 ( V_1 , V_192 , V_166 ) ;
V_320 = V_261 -> V_284 ;
if ( V_192 -> V_356 )
V_192 -> V_356 ( V_192 ) ;
return V_320 ;
}
static T_6 F_65 ( int V_357 , void * V_358 )
{
struct V_359 * V_360 = V_358 ;
struct V_1 * V_1 = V_360 -> V_1 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
struct V_361 * V_362 = & V_360 -> V_362 ;
int V_33 , V_5 = V_362 -> V_56 ;
T_1 V_363 , V_364 , V_150 , V_365 ;
T_1 * V_366 = ( T_1 * ) V_362 -> V_366 ;
struct V_12 * V_56 = (struct V_12 * ) V_366 ;
T_6 V_367 = V_368 ;
V_363 = F_8 ( V_1 , V_5 , V_369 ) ;
if ( ! ( V_363 & V_370 ) ) {
F_59 ( V_40 , L_19 ,
V_363 ) ;
V_367 = V_371 ;
goto V_372;
}
V_364 = F_1 ( V_1 , V_373 ) ;
if ( V_364 & 1 << V_5 ) {
F_26 ( V_40 , L_20 ,
V_5 ) ;
goto V_372;
}
V_150 = ( F_1 ( V_1 , V_153 ) >> ( 4 * V_5 ) )
& 0xf ;
if ( V_150 == 0xf ) {
F_26 ( V_40 , L_21 , V_5 ) ;
V_367 = V_371 ;
goto V_372;
}
for ( V_33 = 0 ; V_33 < 6 ; V_33 ++ ) {
T_1 V_374 = F_8 ( V_1 , V_5 ,
V_375 + ( V_33 * 4 ) ) ;
V_366 [ V_33 ] = F_12 ( V_374 ) ;
}
V_365 = F_1 ( V_1 , V_376 ) ;
V_365 = ( V_365 >> ( V_5 * 4 ) ) & 0xf ;
V_362 -> V_377 = V_365 ;
V_362 -> V_378 = V_379 ;
memcpy ( V_362 -> V_380 ,
& V_56 -> V_24 , V_25 ) ;
F_66 ( V_40 , L_22 ,
V_5 , V_365 ) ;
V_360 -> V_150 = V_150 ;
V_360 -> V_381 &= ~ ( V_382 | V_383 ) ;
V_360 -> V_381 |= V_382 ;
V_360 -> V_384 = 1 ;
V_360 -> V_385 . V_386 = V_56 -> V_15 ;
V_360 -> V_387 = sizeof( struct V_12 ) ;
if ( V_360 -> V_385 . V_386 == V_16 )
V_360 -> V_385 . V_388 =
V_267 ;
else if ( V_360 -> V_385 . V_386 != V_389 )
V_360 -> V_385 . V_388 =
V_316 ;
F_67 ( V_1 -> V_390 , & V_360 -> V_391 ) ;
V_372:
F_7 ( V_1 , V_5 , V_369 ,
V_370 ) ;
if ( V_363 & V_370 ) {
T_1 V_392 = F_8 ( V_1 , V_5 , V_393 ) ;
V_392 &= ~ V_394 ;
F_7 ( V_1 , V_5 , V_393 , V_392 ) ;
F_7 ( V_1 , V_5 , V_395 , 0x3ce3ee ) ;
}
return V_367 ;
}
static T_6 F_68 ( int V_396 , void * V_358 )
{
struct V_359 * V_360 = V_358 ;
struct V_1 * V_1 = V_360 -> V_1 ;
struct V_361 * V_362 = & V_360 -> V_362 ;
struct V_397 * V_398 = & V_1 -> V_398 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
int V_5 = V_362 -> V_56 ;
T_1 V_363 ;
T_6 V_367 = V_368 ;
V_363 = F_8 ( V_1 , V_5 , V_369 ) ;
if ( ! ( V_363 & V_399 ) ) {
F_26 ( V_40 , L_23 ,
V_363 ) ;
V_367 = V_371 ;
goto V_372;
}
V_398 -> V_400 ( V_362 , V_401 ) ;
V_372:
F_7 ( V_1 , V_5 , V_369 ,
V_399 ) ;
return V_367 ;
}
static T_6 F_69 ( int V_396 , void * V_358 )
{
struct V_359 * V_360 = V_358 ;
struct V_1 * V_1 = V_360 -> V_1 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
struct V_361 * V_362 = & V_360 -> V_362 ;
T_1 V_363 , V_402 ;
int V_5 = V_362 -> V_56 ;
V_402 = F_8 ( V_1 , V_5 , V_395 ) ;
F_7 ( V_1 , V_5 , V_395 , 0x3fffff ) ;
V_363 = F_8 ( V_1 , V_5 , V_393 ) ;
if ( V_363 & V_394 ) {
T_1 V_403 = F_1 ( V_1 , V_404 ) ;
F_70 ( V_1 , V_5 ,
( V_403 & 1 << V_5 ) ? 1 : 0 ) ;
}
if ( V_363 & V_405 )
F_59 ( V_40 , L_24 ,
V_5 ) ;
if ( V_363 & V_406 )
F_59 ( V_40 , L_25 , V_5 ) ;
if ( V_363 & V_407 )
F_59 ( V_40 , L_26 ,
V_5 ) ;
if ( V_363 & V_408 ||
V_363 & V_409 )
F_59 ( V_40 , L_27 ,
V_5 ) ;
if ( V_363 & V_410 )
F_59 ( V_40 , L_28 , V_5 ) ;
F_7 ( V_1 , V_5 , V_393 , V_363 ) ;
if ( V_363 & V_394 )
F_7 ( V_1 , V_5 , V_395 ,
0x3fffff & ~ V_411 ) ;
else
F_7 ( V_1 , V_5 , V_395 ,
V_402 ) ;
return V_368 ;
}
static T_6 F_71 ( int V_396 , void * V_358 )
{
struct V_412 * V_413 = V_358 ;
struct V_1 * V_1 = V_413 -> V_1 ;
struct V_165 * V_166 ;
int V_158 = V_413 -> V_56 ;
struct V_321 * V_322 =
(struct V_321 * )
V_1 -> V_323 [ V_158 ] ;
T_1 V_363 , V_414 , V_415 ;
V_363 = F_1 ( V_1 , V_105 ) ;
F_5 ( V_1 , V_105 , 1 << V_158 ) ;
V_414 = F_1 ( V_1 ,
V_416 + ( 0x14 * V_158 ) ) ;
V_415 = F_1 ( V_1 ,
V_417 + ( 0x14 * V_158 ) ) ;
while ( V_414 != V_415 ) {
struct V_321 * V_323 ;
int V_221 ;
T_1 V_325 ;
V_323 = & V_322 [ V_414 ] ;
V_325 = F_48 ( V_323 -> V_142 ) ;
V_221 = ( V_325 & V_418 ) >>
V_419 ;
V_166 = & V_1 -> V_420 [ V_221 ] ;
V_166 -> V_326 = V_414 ;
V_166 -> V_324 = V_158 ;
F_56 ( V_1 , V_166 , 0 ) ;
if ( ++ V_414 >= V_126 )
V_414 = 0 ;
}
F_5 ( V_1 , V_416 + ( 0x14 * V_158 ) , V_414 ) ;
return V_368 ;
}
static T_6 F_72 ( int V_396 , void * V_358 )
{
struct V_1 * V_1 = V_358 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
T_1 V_421 = F_1 ( V_1 , V_422 ) ;
if ( V_421 & V_423 ) {
T_1 V_424 = F_1 ( V_1 , V_425 ) ;
F_73 ( L_29 ,
F_74 ( V_40 ) , V_424 ) ;
}
if ( V_421 & V_426 ) {
T_1 V_183 = ( F_1 ( V_1 , V_427 ) &
V_428 ) >>
V_429 ;
F_73 ( L_30 ,
F_74 ( V_40 ) , V_183 ) ;
}
if ( V_421 & V_430 ) {
T_1 V_424 = F_1 ( V_1 , V_425 ) ;
F_73 ( L_31 ,
F_74 ( V_40 ) , V_424 ) ;
}
if ( V_421 & V_431 ) {
T_1 V_183 = ( F_1 ( V_1 , V_432 ) &
V_433 ) >>
V_434 ;
F_73 ( L_32 ,
F_74 ( V_40 ) , V_183 ) ;
}
if ( V_421 & V_435 ) {
T_1 V_183 = ( F_1 ( V_1 , V_436 ) &
V_437 ) >>
V_438 ;
F_73 ( L_33 ,
F_74 ( V_40 ) , V_183 ) ;
}
if ( V_421 & V_439 ) {
T_1 V_424 = F_1 ( V_1 , V_425 ) ;
F_73 ( L_34 ,
F_74 ( V_40 ) , V_424 ) ;
}
F_5 ( V_1 , V_422 , V_421 | 0x3f ) ;
return V_368 ;
}
static T_6 F_75 ( int V_396 , void * V_358 )
{
struct V_1 * V_1 = V_358 ;
struct V_38 * V_40 = & V_1 -> V_41 -> V_40 ;
T_1 V_440 = F_1 ( V_1 , V_109 ) ;
T_1 V_441 = F_1 ( V_1 , V_442 ) ;
if ( V_440 & V_443 )
F_73 ( L_35 ,
F_74 ( V_40 ) , V_441 ) ;
if ( V_440 & V_444 )
F_73 ( L_36 ,
F_74 ( V_40 ) , V_441 ) ;
if ( V_440 & V_445 )
F_73 ( L_37 ,
F_74 ( V_40 ) , V_441 ) ;
if ( V_440 & V_446 )
F_73 ( L_38 ,
F_74 ( V_40 ) , V_441 ) ;
F_5 ( V_1 , V_109 , V_440 | 0x30000000 ) ;
return V_368 ;
}
static int F_76 ( struct V_1 * V_1 )
{
struct V_447 * V_41 = V_1 -> V_41 ;
struct V_38 * V_40 = & V_41 -> V_40 ;
int V_33 , V_448 , V_396 , V_140 , V_221 ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ ) {
struct V_359 * V_360 = & V_1 -> V_360 [ V_33 ] ;
V_221 = V_33 * V_449 ;
for ( V_448 = 0 ; V_448 < V_449 ; V_448 ++ , V_221 ++ ) {
V_396 = F_77 ( V_41 , V_221 ) ;
if ( ! V_396 ) {
F_26 ( V_40 ,
L_39 ,
V_221 ) ;
return - V_450 ;
}
V_140 = F_78 ( V_40 , V_396 , V_451 [ V_448 ] , 0 ,
V_452 L_40 , V_360 ) ;
if ( V_140 ) {
F_26 ( V_40 , L_41
L_42 ,
V_396 , V_140 ) ;
return - V_450 ;
}
}
}
V_221 = V_1 -> V_34 * V_449 ;
for ( V_33 = 0 ; V_33 < V_1 -> V_88 ; V_33 ++ , V_221 ++ ) {
V_396 = F_77 ( V_41 , V_221 ) ;
if ( ! V_396 ) {
F_26 ( V_40 , L_43 ,
V_221 ) ;
return - V_450 ;
}
V_140 = F_78 ( V_40 , V_396 , F_71 , 0 ,
V_452 L_44 , & V_1 -> V_413 [ V_33 ] ) ;
if ( V_140 ) {
F_26 ( V_40 , L_45 ,
V_396 , V_140 ) ;
return - V_450 ;
}
}
V_221 = ( V_1 -> V_34 * V_449 ) + V_1 -> V_88 ;
for ( V_33 = 0 ; V_33 < V_453 ; V_33 ++ , V_221 ++ ) {
V_396 = F_77 ( V_41 , V_221 ) ;
if ( ! V_396 ) {
F_26 ( V_40 , L_46 ,
V_221 ) ;
return - V_450 ;
}
V_140 = F_78 ( V_40 , V_396 , V_454 [ V_33 ] , 0 ,
V_452 L_47 , V_1 ) ;
if ( V_140 ) {
F_26 ( V_40 ,
L_48 ,
V_396 , V_140 ) ;
return - V_450 ;
}
}
return 0 ;
}
static int F_79 ( struct V_1 * V_1 )
{
int V_33 ;
T_1 V_4 ;
for ( V_33 = 0 ; V_33 < V_1 -> V_34 ; V_33 ++ ) {
V_4 = F_8 ( V_1 , V_33 , V_393 ) ;
F_7 ( V_1 , V_33 , V_393 , V_4 ) ;
V_4 = F_8 ( V_1 , V_33 , V_455 ) ;
F_7 ( V_1 , V_33 , V_455 , V_4 ) ;
V_4 = F_8 ( V_1 , V_33 , V_369 ) ;
F_7 ( V_1 , V_33 , V_369 , V_4 ) ;
F_7 ( V_1 , V_33 , V_395 , 0x3ce3ee ) ;
F_7 ( V_1 , V_33 , V_456 , 0x17fff ) ;
F_7 ( V_1 , V_33 , V_143 , 0x8000012a ) ;
F_7 ( V_1 , V_33 , V_395 ,
0x3fffff & ~ V_411 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_1 )
{
int V_140 ;
V_140 = F_30 ( V_1 ) ;
if ( V_140 )
return V_140 ;
V_140 = F_76 ( V_1 ) ;
if ( V_140 )
return V_140 ;
V_140 = F_79 ( V_1 ) ;
if ( V_140 )
return V_140 ;
F_37 ( V_1 ) ;
return 0 ;
}
static int F_81 ( struct V_447 * V_41 )
{
return F_82 ( V_41 , & V_457 ) ;
}
static int F_83 ( struct V_447 * V_41 )
{
return F_84 ( V_41 ) ;
}
