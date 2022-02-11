static void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_8 | V_9 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_8 | V_9 ) ;
}
static void
F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_10 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_10 ) ;
}
static void
F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_11 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_11 ) ;
}
static void
F_7 ( struct V_1 * V_2 ,
const void * V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const T_2 * V_13 = V_12 ;
F_8 ( V_5 , V_6 , V_7 ,
V_14 ,
* V_13 << V_15 ) ;
}
static void
F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_16 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_16 ) ;
}
static void
F_10 ( struct V_1 * V_2 , const void * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_18 * V_19 = V_17 ;
F_11 ( V_5 , ( V_19 -> V_20 == 1 ? 0 : V_21 ) |
( V_19 -> V_22 == 1 ? 0 : V_23 ) |
( V_19 -> V_24 << V_25 ) ,
V_6 , V_26 ) ;
}
static void
F_12 ( struct V_1 * V_2 , const void * V_27 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_28 * V_29 = V_27 ;
unsigned int V_30 ;
F_11 ( V_5 , V_29 -> V_31 , V_6 , V_32 ) ;
F_11 ( V_5 , V_33 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
F_11 ( V_5 , V_29 -> V_36 [ V_30 ] ,
V_6 , V_37 ) ;
}
}
static void
F_13 ( struct V_1 * V_2 , const void * V_38 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_39 * V_40 = V_38 ;
F_11 ( V_5 , V_40 -> V_41 [ 0 ] ,
V_6 , V_42 ) ;
F_11 ( V_5 , V_40 -> V_41 [ 1 ] ,
V_6 , V_43 ) ;
F_11 ( V_5 , V_40 -> V_41 [ 2 ] ,
V_6 , V_44 ) ;
F_11 ( V_5 , V_40 -> V_41 [ 3 ] ,
V_6 , V_45 ) ;
F_8 ( V_5 , V_6 , V_7 ,
V_46 ,
V_40 -> V_47 ? V_46 : 0 ) ;
}
static void
F_14 ( struct V_1 * V_2 , const void * V_48 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_49 * V_50 = V_48 ;
unsigned int V_30 ;
F_8 ( V_5 , V_6 , V_7 ,
V_51 ,
V_50 -> V_52 << V_53 ) ;
F_11 ( V_5 ,
( V_50 -> V_54 << V_55 ) |
( V_50 -> V_56 << V_57 ) ,
V_6 , V_58 ) ;
F_11 ( V_5 , V_59 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_60 ; V_30 ++ ) {
F_11 ( V_5 , V_50 -> V_36 [ V_30 ] ,
V_6 , V_37 ) ;
}
}
static void
F_15 ( struct V_1 * V_2 , const void * V_61 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_62 * V_63 = V_61 ;
unsigned int V_30 ;
F_11 ( V_5 , V_64 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_65 ; V_30 ++ )
F_11 ( V_5 , V_63 -> V_66 [ V_30 ] , V_6 ,
V_37 ) ;
F_11 ( V_5 , V_67 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_65 ; V_30 ++ )
F_11 ( V_5 , V_63 -> V_68 [ V_30 ] , V_6 ,
V_37 ) ;
F_11 ( V_5 , V_69 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_65 ; V_30 ++ )
F_11 ( V_5 , V_63 -> V_70 [ V_30 ] , V_6 ,
V_37 ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
const void * V_71 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_72 * V_73 = V_71 ;
unsigned int V_30 ;
F_11 ( V_5 , V_74 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_75 ; V_30 ++ ) {
F_11 ( V_5 , V_73 -> V_36 [ V_30 ] ,
V_6 , V_37 ) ;
}
}
static void
F_17 ( struct V_1 * V_2 ,
const void * V_76 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_77 * V_78 = V_76 ;
F_11 ( V_5 ,
V_78 -> V_79 | ( V_78 -> V_24 << V_80 ) |
( V_78 -> V_81 << V_82 ) ,
V_6 , V_83 ) ;
}
static void
F_18 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_84 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_84 ) ;
}
static void
F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_85 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_85 ) ;
}
static void
F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_86 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_86 ) ;
}
static void
F_21 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_87 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_87 ) ;
}
static void
F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_88 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_88 ) ;
}
static void
F_23 ( struct V_1 * V_2 , const void * V_89 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_90 * V_91 = V_89 ;
T_2 V_92 ;
F_11 ( V_5 , V_91 -> V_93 , V_6 , V_94 ) ;
V_92 = V_91 -> V_95 << V_96 ;
V_92 |= V_91 -> V_97 << V_98 ;
V_92 |= V_91 -> V_99 << V_100 ;
V_92 |= V_91 -> V_101 << V_102 ;
F_11 ( V_5 , V_92 , V_6 , V_103 ) ;
F_11 ( V_5 ,
V_104 << V_105 |
V_106 << V_107 |
V_104 << V_108 |
V_106 << V_109 |
V_110 << V_111 |
V_112 << V_113 |
V_110 << V_114 |
V_112 << V_115 |
V_104 << V_116 |
V_106 << V_117 |
V_104 << V_118 |
V_106 << V_119 |
V_110 << V_120 |
V_112 << V_121 |
V_110 << V_122 |
V_112 << V_123 ,
V_6 , V_124 ) ;
}
static void
F_24 ( struct V_1 * V_2 , const void * V_125 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_126 * V_127 = V_125 ;
F_11 ( V_5 , ( V_127 -> V_70 << V_128 ) |
( V_127 -> V_68 << V_129 ) |
( V_127 -> V_66 << V_130 ) ,
V_6 , V_131 ) ;
}
static void
F_25 ( struct V_1 * V_2 , const void * V_132 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_133 * V_134 = V_132 ;
T_2 V_92 ;
V_92 = ( V_134 -> V_135 [ 0 ] [ 0 ] & 0xfff ) << V_136 ;
V_92 |= ( V_134 -> V_135 [ 0 ] [ 1 ] & 0xfff ) << V_137 ;
F_11 ( V_5 , V_92 , V_6 , V_138 ) ;
V_92 = ( V_134 -> V_135 [ 0 ] [ 2 ] & 0xfff ) << V_139 ;
V_92 |= ( V_134 -> V_135 [ 1 ] [ 0 ] & 0xfff ) << V_140 ;
F_11 ( V_5 , V_92 , V_6 , V_141 ) ;
V_92 = ( V_134 -> V_135 [ 1 ] [ 1 ] & 0xfff ) << V_142 ;
V_92 |= ( V_134 -> V_135 [ 1 ] [ 2 ] & 0xfff ) << V_143 ;
F_11 ( V_5 , V_92 , V_6 , V_144 ) ;
V_92 = ( V_134 -> V_135 [ 2 ] [ 0 ] & 0xfff ) << V_145 ;
V_92 |= ( V_134 -> V_135 [ 2 ] [ 1 ] & 0xfff ) << V_146 ;
F_11 ( V_5 , V_92 , V_6 , V_147 ) ;
V_92 = ( V_134 -> V_135 [ 2 ] [ 2 ] & 0xfff ) << V_148 ;
F_11 ( V_5 , V_92 , V_6 , V_149 ) ;
V_92 = ( V_134 -> V_150 [ 0 ] & 0x3ff ) << V_151 ;
V_92 |= ( V_134 -> V_150 [ 1 ] & 0x3ff ) << V_152 ;
F_11 ( V_5 , V_92 , V_6 , V_153 ) ;
V_92 = ( V_134 -> V_150 [ 2 ] & 0x3ff ) << V_154 ;
F_11 ( V_5 , V_92 , V_6 , V_155 ) ;
}
static void
F_26 ( struct V_1 * V_2 , const void * V_156 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_157 * V_158 = V_156 ;
T_2 V_92 ;
V_92 = ( V_158 -> V_135 [ 0 ] [ 0 ] & 0x3ff ) << V_159 ;
V_92 |= ( V_158 -> V_135 [ 0 ] [ 1 ] & 0x3ff ) << V_160 ;
V_92 |= ( V_158 -> V_135 [ 0 ] [ 2 ] & 0x3ff ) << V_161 ;
F_11 ( V_5 , V_92 , V_6 , V_162 ) ;
V_92 = ( V_158 -> V_135 [ 1 ] [ 0 ] & 0x3ff ) << V_163 ;
V_92 |= ( V_158 -> V_135 [ 1 ] [ 1 ] & 0x3ff ) << V_164 ;
V_92 |= ( V_158 -> V_135 [ 1 ] [ 2 ] & 0x3ff ) << V_165 ;
F_11 ( V_5 , V_92 , V_6 , V_166 ) ;
V_92 = ( V_158 -> V_135 [ 2 ] [ 0 ] & 0x3ff ) << V_167 ;
V_92 |= ( V_158 -> V_135 [ 2 ] [ 1 ] & 0x3ff ) << V_168 ;
V_92 |= ( V_158 -> V_135 [ 2 ] [ 2 ] & 0x3ff ) << V_169 ;
F_11 ( V_5 , V_92 , V_6 , V_170 ) ;
V_92 = ( V_158 -> V_150 [ 0 ] & 0xff ) << V_171 ;
V_92 |= ( V_158 -> V_150 [ 1 ] & 0xff ) << V_172 ;
V_92 |= ( V_158 -> V_150 [ 2 ] & 0xff ) << V_173 ;
F_11 ( V_5 , V_92 , V_6 , V_174 ) ;
}
static void
F_27 ( struct V_1 * V_2 , T_1 V_175 )
{
struct V_176 * V_177 ;
unsigned long V_178 ;
F_28 ( & V_2 -> V_177 . V_179 , V_178 ) ;
V_177 = ( V_2 -> V_177 . V_180 & V_181 )
? & V_2 -> V_177 . V_177 [ 0 ] : & V_2 -> V_177 . V_177 [ 1 ] ;
if ( V_177 -> V_175 != ( V_175 * V_182 ) ) {
V_177 -> V_175 = V_175 * V_182 ;
V_177 -> V_183 |= V_181 ;
}
F_29 ( & V_2 -> V_177 . V_179 , V_178 ) ;
}
static void
F_30 ( struct V_1 * V_2 , const void * V_177 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_8 ( V_5 , V_6 , V_184 ,
0xff << V_185 ,
* ( T_1 * ) V_177 << V_185 ) ;
}
static void
F_31 ( struct V_1 * V_2 , T_1 V_186 )
{
struct V_176 * V_177 ;
unsigned long V_178 ;
F_28 ( & V_2 -> V_177 . V_179 , V_178 ) ;
V_177 = ( V_2 -> V_177 . V_180 & V_187 )
? & V_2 -> V_177 . V_177 [ 0 ] : & V_2 -> V_177 . V_177 [ 1 ] ;
if ( V_177 -> V_186 != ( V_186 * V_188 ) ) {
V_177 -> V_186 = V_186 * V_188 ;
V_177 -> V_183 |= V_187 ;
}
F_29 ( & V_2 -> V_177 . V_179 , V_178 ) ;
}
static void
F_32 ( struct V_1 * V_2 , const void * V_177 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_8 ( V_5 , V_6 , V_184 ,
0xff << V_189 ,
* ( T_1 * ) V_177 << V_189 ) ;
}
static void
F_33 ( struct V_1 * V_2 , const void * V_190 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_191 * V_192 = V_190 ;
F_11 ( V_5 ,
V_192 -> V_193 << V_194 |
V_192 -> V_195 << V_196 |
V_192 -> V_197 << V_198 |
V_192 -> V_199 << V_200 ,
V_6 , V_201 ) ;
}
static T_2
F_34 ( struct V_1 * V_2 , T_2 V_183 , bool V_202 )
{
T_2 V_180 = V_2 -> V_177 . V_180 ;
if ( V_202 ) {
V_2 -> V_177 . V_177 [ 0 ] . V_203 |= ~ V_180 & V_183 ;
V_2 -> V_177 . V_177 [ 1 ] . V_203 |= V_180 & V_183 ;
} else {
V_183 = ( V_2 -> V_177 . V_177 [ 0 ] . V_183 & V_180 )
| ( V_2 -> V_177 . V_177 [ 1 ] . V_183 & ~ V_180 ) ;
V_2 -> V_177 . V_177 [ 0 ] . V_203 |= V_180 & V_183 ;
V_2 -> V_177 . V_177 [ 1 ] . V_203 |= ~ V_180 & V_183 ;
}
return V_183 ;
}
static void
F_35 ( struct V_1 * V_2 , T_2 V_183 , bool V_202 )
{
T_2 V_180 = V_2 -> V_177 . V_180 ;
if ( V_202 ) {
V_2 -> V_177 . V_177 [ 0 ] . V_183 |= ( ~ V_180 & V_183 ) ;
V_2 -> V_177 . V_177 [ 1 ] . V_183 |= ( V_180 & V_183 ) ;
V_2 -> V_177 . V_177 [ 0 ] . V_203 &= V_180 ;
V_2 -> V_177 . V_177 [ 1 ] . V_203 &= ~ V_180 ;
} else {
V_2 -> V_177 . V_177 [ 0 ] . V_183 &= ~ ( V_180 & V_183 ) ;
V_2 -> V_177 . V_177 [ 1 ] . V_183 &= ~ ( ~ V_180 & V_183 ) ;
V_2 -> V_177 . V_177 [ 0 ] . V_203 &= ~ V_180 ;
V_2 -> V_177 . V_177 [ 1 ] . V_203 &= V_180 ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
T_2 V_204 ;
V_204 = ( V_2 -> V_177 . V_177 [ 0 ] . V_183 & ~ V_2 -> V_177 . V_180 )
| ( V_2 -> V_177 . V_177 [ 1 ] . V_183 & V_2 -> V_177 . V_180 ) ;
V_204 &= ~ ( V_2 -> V_177 . V_177 [ 0 ] . V_203 |
V_2 -> V_177 . V_177 [ 1 ] . V_203 ) ;
if ( V_204 == 0 )
return;
V_2 -> V_177 . V_180 ^= V_204 ;
V_2 -> V_177 . V_177 [ 0 ] . V_183 &= ~ ( ~ V_2 -> V_177 . V_180 & V_204 ) ;
V_2 -> V_177 . V_177 [ 1 ] . V_183 &= ~ ( V_2 -> V_177 . V_180 & V_204 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_205 * V_206 )
{
unsigned long V_178 ;
unsigned int V_30 ;
int V_207 = 0 ;
T_2 V_183 ;
T_2 V_180 ;
if ( V_206 -> V_183 == 0 )
return 0 ;
F_28 ( & V_2 -> V_177 . V_179 , V_178 ) ;
F_34 ( V_2 , V_206 -> V_183 , true ) ;
V_180 = V_2 -> V_177 . V_180 ;
F_29 ( & V_2 -> V_177 . V_179 , V_178 ) ;
V_183 = 0 ;
for ( V_30 = 0 ; V_30 < F_38 ( V_208 ) ; V_30 ++ ) {
const struct V_209 * V_210 = & V_208 [ V_30 ] ;
struct V_176 * V_177 ;
unsigned int V_211 = 1 << V_30 ;
if ( V_210 -> V_212 || ! ( V_206 -> V_183 & V_211 ) )
continue;
V_177 = & V_2 -> V_177 . V_177 [ ! ! ( V_180 & V_211 ) ] ;
if ( V_206 -> V_213 & V_211 ) {
void T_3 * V_214 = * ( void * T_3 * )
( ( void * ) V_206 + V_210 -> V_215 ) ;
void * V_216 = ( void * ) V_177 + V_210 -> V_217 ;
T_4 V_218 = V_210 -> V_219 ;
if ( V_216 && V_214 && V_218 ) {
if ( F_39 ( V_216 , V_214 , V_218 ) ) {
V_207 = - V_220 ;
break;
}
}
V_177 -> V_221 |= V_211 ;
} else {
V_177 -> V_221 &= ~ V_211 ;
}
V_183 |= V_211 ;
}
F_28 ( & V_2 -> V_177 . V_179 , V_178 ) ;
F_35 ( V_2 , V_183 , true ) ;
F_36 ( V_2 ) ;
F_29 ( & V_2 -> V_177 . V_179 , V_178 ) ;
return V_207 ;
}
static void F_40 ( struct V_1 * V_2 , T_2 V_183 ,
T_2 V_180 )
{
unsigned int V_30 ;
T_2 V_221 ;
if ( V_183 == 0 )
return;
V_221 = ( V_2 -> V_177 . V_177 [ 0 ] . V_221 & V_180 )
| ( V_2 -> V_177 . V_177 [ 1 ] . V_221 & ~ V_180 ) ;
for ( V_30 = 0 ; V_30 < F_38 ( V_208 ) ; V_30 ++ ) {
const struct V_209 * V_210 = & V_208 [ V_30 ] ;
struct V_176 * V_177 ;
unsigned int V_211 = 1 << V_30 ;
void * V_222 ;
if ( ! ( V_183 & V_211 ) )
continue;
V_177 = & V_2 -> V_177 . V_177 [ ! ( V_180 & V_211 ) ] ;
if ( V_177 -> V_221 & V_211 ) {
if ( V_210 -> V_223 ) {
V_222 = ( void * ) V_177 + V_210 -> V_217 ;
V_210 -> V_223 ( V_2 , V_222 ) ;
}
if ( V_210 -> V_3 )
V_210 -> V_3 ( V_2 , 1 ) ;
} else {
if ( V_210 -> V_3 )
V_210 -> V_3 ( V_2 , 0 ) ;
}
}
}
static void
F_41 ( struct V_1 * V_2 ,
enum V_224 V_225 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
enum V_226 V_227 ;
switch ( V_225 ) {
case V_228 :
V_227 = V_229 ;
break;
case V_230 :
V_227 = V_231 ;
break;
default:
return;
}
F_8 ( V_5 , V_6 , V_7 ,
V_232 ,
V_227 << V_233 ) ;
}
static void F_42 ( struct V_1 * V_2 , T_1 V_234 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_176 * V_177 ;
int V_235 = 0 ;
V_177 = ( V_2 -> V_177 . V_180 & V_236 )
? & V_2 -> V_177 . V_177 [ 0 ] : & V_2 -> V_177 . V_177 [ 1 ] ;
if ( V_177 -> V_50 . V_52 == V_237 )
V_235 = V_238 << V_239 |
V_240 << V_241 |
V_234 ;
else if ( V_177 -> V_50 . V_52 == V_242 )
V_235 = V_243 << V_239 |
V_244 << V_241 |
V_234 ;
F_11 ( V_5 , V_235 , V_6 , V_245 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
const struct V_246 * V_52 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_52 -> V_247 != V_248 )
F_3 ( V_5 , V_6 , V_7 ,
V_249 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_249 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_2 V_180 )
{
const struct V_246 * V_52 = & V_2 -> V_250 [ V_251 ] ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_252 = V_2 -> V_253 . V_254 ;
unsigned int V_255 = V_2 -> V_253 . V_254 + V_2 -> V_253 . V_256 - 1 ;
unsigned int V_257 = V_2 -> V_253 . V_258 ;
unsigned int V_259 = V_2 -> V_253 . V_258 + V_2 -> V_253 . V_260 - 1 ;
T_2 V_221 ;
if ( V_52 -> V_247 != V_248 ) {
V_252 -= 2 ;
V_255 += 2 ;
V_257 -= 2 ;
V_259 += 2 ;
}
V_221 = ( V_2 -> V_177 . V_177 [ 0 ] . V_221 & V_180 )
| ( V_2 -> V_177 . V_177 [ 1 ] . V_221 & ~ V_180 ) ;
if ( V_221 & ( V_261 | V_262 ) ) {
V_252 -= 2 ;
V_255 += 2 ;
V_257 -= 2 ;
V_259 += 2 ;
}
if ( V_221 & V_263 ) {
V_252 -= 2 ;
V_255 += 2 ;
}
if ( V_221 & ( V_264 | V_265 ) )
V_252 -= 2 ;
F_11 ( V_5 , ( V_252 << V_266 ) | V_255 ,
V_6 , V_267 ) ;
F_11 ( V_5 , ( V_257 << V_268 ) | V_259 ,
V_6 , V_269 ) ;
}
static void
F_45 ( struct V_1 * V_2 , T_2 V_150 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 , V_150 & 0xffff , V_6 ,
V_270 ) ;
}
static void F_46 ( struct V_1 * V_2 , T_2 V_271 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 , V_271 , V_6 , V_272 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_2 V_150 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 , V_150 & 0xffff , V_6 ,
V_273 ) ;
}
static void F_48 ( struct V_1 * V_2 , T_2 V_271 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 , V_271 , V_6 , V_274 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_275 * V_276 = F_50 ( & V_2 -> V_277 . V_278 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_246 * V_279 = & V_2 -> V_250 [ V_251 ] ;
unsigned long V_280 = V_276 -> V_280 ;
struct V_281 * V_282 ;
unsigned int V_283 ;
unsigned int V_284 ;
unsigned int V_285 ;
unsigned int V_286 ;
unsigned int V_287 ;
unsigned int V_288 ;
if ( V_2 -> V_289 != V_290 ) {
F_4 ( V_5 , V_291 , V_292 ,
V_293 ) ;
return;
}
V_285 = F_51 ( ( V_294 ) V_280 / 2 * 256 + V_276 -> V_295 - 1 ,
V_276 -> V_295 ) ;
V_286 = F_52 ( V_285 , 32 ) ;
V_282 = & V_276 -> V_296 ;
V_284 = F_52 ( V_279 -> V_256 * 2 , 256 ) * V_279 -> V_260 ;
V_283 = F_51 ( ( V_294 ) V_280 * V_282 -> V_297 ,
V_282 -> V_298 ) ;
V_285 = V_283 / V_284 ;
V_287 = V_285 / 32 ;
V_288 = F_53 ( V_286 , V_287 ) ;
F_54 ( V_5 -> V_299 , L_1 , V_300 , V_288 ) ;
F_8 ( V_5 , V_291 , V_292 ,
V_293 ,
V_288 << V_301 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_56 ( V_5 , V_6 , V_7 )
& V_302 ;
}
void F_57 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_303 ;
const T_2 V_183 = V_304 - 1 ;
V_2 -> V_177 . V_177 [ 0 ] . V_183 = V_2 -> V_177 . V_180 & V_183 ;
V_2 -> V_177 . V_177 [ 1 ] . V_183 = ~ V_2 -> V_177 . V_180 & V_183 ;
F_40 ( V_2 , V_183 , V_2 -> V_177 . V_180 ) ;
V_2 -> V_177 . V_177 [ 0 ] . V_183 = 0 ;
V_2 -> V_177 . V_177 [ 1 ] . V_183 = 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_54 ( V_5 -> V_299 , L_2 ) ;
F_59 ( V_5 , V_305 ) ;
F_59 ( V_5 , V_306 ) ;
F_59 ( V_5 , V_307 ) ;
F_59 ( V_5 , V_308 ) ;
F_59 ( V_5 , V_309 ) ;
F_59 ( V_5 , V_310 ) ;
F_59 ( V_5 , V_311 ) ;
F_59 ( V_5 , V_312 ) ;
F_59 ( V_5 , V_313 ) ;
F_59 ( V_5 , V_314 ) ;
F_59 ( V_5 , V_315 ) ;
F_59 ( V_5 , V_316 ) ;
F_59 ( V_5 , V_317 ) ;
F_59 ( V_5 , V_318 ) ;
F_59 ( V_5 , V_319 ) ;
F_59 ( V_5 , V_320 ) ;
F_59 ( V_5 , V_321 ) ;
F_59 ( V_5 , V_322 ) ;
F_59 ( V_5 , V_323 ) ;
F_59 ( V_5 , V_324 ) ;
F_59 ( V_5 , V_325 ) ;
F_59 ( V_5 , V_326 ) ;
F_59 ( V_5 , V_327 ) ;
F_59 ( V_5 , V_328 ) ;
F_59 ( V_5 , V_329 ) ;
F_59 ( V_5 , V_330 ) ;
F_59 ( V_5 , V_331 ) ;
F_59 ( V_5 , V_332 ) ;
F_59 ( V_5 , V_333 ) ;
F_59 ( V_5 , V_334 ) ;
F_59 ( V_5 , V_335 ) ;
F_59 ( V_5 , V_336 ) ;
F_59 ( V_5 , V_337 ) ;
F_59 ( V_5 , V_338 ) ;
F_59 ( V_5 , V_339 ) ;
F_59 ( V_5 , V_340 ) ;
F_54 ( V_5 -> V_299 , L_3 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_176 * V_177 ;
unsigned int V_30 ;
F_61 ( & V_2 -> V_177 . V_179 ) ;
V_2 -> V_177 . V_180 = ~ 0 ;
V_2 -> V_177 . V_177 [ 0 ] . V_203 = 0 ;
V_2 -> V_177 . V_177 [ 0 ] . V_183 = V_304 - 1 ;
V_2 -> V_177 . V_177 [ 1 ] . V_203 = 0 ;
V_2 -> V_177 . V_177 [ 1 ] . V_183 = 0 ;
V_177 = & V_2 -> V_177 . V_177 [ 0 ] ;
V_177 -> V_175 = V_341 * V_182 ;
V_177 -> V_186 = V_342 * V_188 ;
V_177 -> V_50 . V_52 = V_237 ;
memcpy ( V_177 -> V_50 . V_36 , V_343 ,
sizeof( V_177 -> V_50 . V_36 ) ) ;
V_177 -> V_50 . V_56 = V_344 ;
V_177 -> V_50 . V_54 = V_345 ;
V_177 -> V_76 . V_79 = V_346 ;
V_177 -> V_76 . V_24 = V_347 ;
V_177 -> V_76 . V_81 = 0 ;
memcpy ( V_177 -> V_348 . V_36 , V_349 ,
sizeof( V_177 -> V_348 . V_36 ) ) ;
V_177 -> V_29 . V_31 = V_350 ;
memcpy ( V_177 -> V_29 . V_36 , V_351 , sizeof( V_177 -> V_29 . V_36 ) ) ;
V_177 -> V_40 . V_47 = 1 ;
for ( V_30 = 0 ; V_30 < V_352 ; V_30 ++ )
V_177 -> V_40 . V_41 [ V_30 ] = V_353 ;
memcpy ( V_177 -> gamma . V_70 , V_354 , sizeof( V_177 -> gamma . V_70 ) ) ;
memcpy ( V_177 -> gamma . V_68 , V_354 , sizeof( V_177 -> gamma . V_68 ) ) ;
memcpy ( V_177 -> gamma . V_66 , V_354 , sizeof( V_177 -> gamma . V_66 ) ) ;
V_177 -> V_91 . V_93 = V_355 ;
V_177 -> V_91 . V_95 = V_356 ;
V_177 -> V_91 . V_97 = V_356 ;
V_177 -> V_91 . V_99 = V_356 ;
V_177 -> V_91 . V_101 = V_356 ;
V_177 -> V_127 . V_66 = V_357 ;
V_177 -> V_127 . V_68 = V_358 ;
V_177 -> V_127 . V_70 = V_359 ;
V_177 -> V_132 = V_360 ;
V_177 -> V_158 = V_361 ;
V_177 -> V_190 . V_197 = V_362 ;
V_177 -> V_190 . V_193 = V_363 ;
V_177 -> V_190 . V_199 = V_362 ;
V_177 -> V_190 . V_195 = V_363 ;
V_177 -> V_221 = V_236 | V_261
| V_262 | V_364
| V_365 | V_366
| V_367 | V_368
| V_369 | V_187
| V_181 ;
}
static unsigned int F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_370 ) {
case V_371 :
return V_372 ;
case V_373 :
default:
return V_374 ;
case V_375 :
return V_376 ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_246 * V_52 ;
unsigned long V_178 ;
T_2 V_183 ;
T_2 V_180 ;
F_28 ( & V_2 -> V_177 . V_179 , V_178 ) ;
V_183 = F_34 ( V_2 , 0 , false ) ;
V_180 = V_2 -> V_177 . V_180 ;
F_29 ( & V_2 -> V_177 . V_179 , V_178 ) ;
F_40 ( V_2 , V_183 , V_180 ) ;
if ( V_2 -> V_377 & V_378 )
F_3 ( V_5 , V_6 , V_7 ,
V_379 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_379 ) ;
if ( V_2 -> V_377 & V_380 )
F_3 ( V_5 , V_6 , V_7 ,
V_381 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_381 ) ;
V_52 = & V_2 -> V_250 [ V_251 ] ;
F_49 ( V_2 ) ;
F_43 ( V_2 , V_52 ) ;
F_44 ( V_2 , V_180 ) ;
if ( V_2 -> V_289 == V_382 )
F_45 ( V_2 , 0 ) ;
else
F_45 ( V_2 ,
F_64 ( V_52 -> V_256 , 0x20 ) * 2 ) ;
V_52 = & V_2 -> V_250 [ V_383 ] ;
if ( V_2 -> V_377 & V_378 )
F_47 ( V_2 ,
F_64 ( V_52 -> V_256 , 0x10 ) * 2 ) ;
F_42 ( V_2 , 0 ) ;
F_41 ( V_2 , V_52 -> V_247 ) ;
F_28 ( & V_2 -> V_177 . V_179 , V_178 ) ;
F_35 ( V_2 , V_183 , false ) ;
F_29 ( & V_2 -> V_177 . V_179 , V_178 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_2 -> V_289 == V_290 )
F_3 ( V_5 , V_6 , V_7 ,
V_384 ) ;
F_3 ( V_5 , V_6 , V_7 ,
V_385 | V_386 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_387 == V_388 &&
V_2 -> V_389 . V_390 & V_391 ) {
F_65 ( V_2 ) ;
F_67 ( & V_2 -> V_389 ) ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_275 * V_276 = F_50 ( & V_2 -> V_277 . V_278 ) ;
struct V_392 * V_393 ;
int V_394 = 0 ;
if ( V_2 -> V_289 == V_290 ) {
V_393 = F_69 ( & V_2 -> V_395 ) ;
if ( V_393 != NULL )
F_46 ( V_2 , V_393 -> V_396 ) ;
V_276 -> V_387 |= V_397 ;
}
if ( V_2 -> V_377 & V_378 ) {
V_393 = F_69 ( & V_2 -> V_389 ) ;
if ( V_393 != NULL ) {
F_48 ( V_2 , V_393 -> V_396 ) ;
V_394 = 1 ;
}
V_276 -> V_387 |= V_398 ;
}
switch ( V_2 -> V_387 ) {
case V_399 :
if ( F_70 ( V_276 ) )
F_71 ( V_276 ,
V_399 ) ;
break;
case V_388 :
if ( V_394 )
F_65 ( V_2 ) ;
break;
case V_400 :
default:
return;
}
}
void F_72 ( struct V_1 * V_2 )
{
unsigned long V_178 ;
T_2 V_183 ;
T_2 V_180 ;
if ( F_73 ( & V_2 -> V_401 , & V_2 -> V_402 ) )
return;
F_28 ( & V_2 -> V_177 . V_179 , V_178 ) ;
F_36 ( V_2 ) ;
V_183 = F_34 ( V_2 , 0 , false ) ;
V_180 = V_2 -> V_177 . V_180 ;
F_29 ( & V_2 -> V_177 . V_179 , V_178 ) ;
F_40 ( V_2 , V_183 , V_180 ) ;
F_44 ( V_2 , V_180 ) ;
if ( V_2 -> V_289 == V_290 ||
V_2 -> V_377 & V_378 )
F_68 ( V_2 ) ;
else if ( V_2 -> V_387 == V_388 )
F_65 ( V_2 ) ;
F_28 ( & V_2 -> V_177 . V_179 , V_178 ) ;
F_35 ( V_2 , V_183 , false ) ;
F_29 ( & V_2 -> V_177 . V_179 , V_178 ) ;
}
static int F_74 ( struct V_403 * V_404 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = & V_404 -> V_5 -> V_303 ;
if ( V_404 -> type == V_405 )
F_46 ( V_2 , V_393 -> V_396 ) ;
if ( V_404 -> type == V_406 )
F_48 ( V_2 , V_393 -> V_396 ) ;
return 0 ;
}
static int F_75 ( struct V_407 * V_408 )
{
struct V_1 * V_2 =
F_76 ( V_408 -> V_409 , struct V_1 , V_410 ) ;
switch ( V_408 -> V_411 ) {
case V_412 :
F_31 ( V_2 , V_408 -> V_92 ) ;
break;
case V_413 :
F_27 ( V_2 , V_408 -> V_92 ) ;
break;
}
return 0 ;
}
static long F_77 ( struct V_414 * V_415 , unsigned int V_416 , void * V_417 )
{
struct V_1 * V_2 = F_78 ( V_415 ) ;
switch ( V_416 ) {
case V_418 :
return F_37 ( V_2 , V_417 ) ;
default:
return - V_419 ;
}
}
static int F_79 ( struct V_414 * V_415 , int V_3 )
{
struct V_1 * V_2 = F_78 ( V_415 ) ;
struct V_403 * V_389 = & V_2 -> V_389 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_420 * V_299 = F_80 ( V_2 ) ;
if ( V_2 -> V_387 == V_400 ) {
if ( V_3 == V_400 )
return 0 ;
F_81 ( V_5 , V_421 ) ;
F_63 ( V_2 ) ;
F_82 ( & V_2 -> V_402 , 0 ) ;
F_58 ( V_2 ) ;
}
switch ( V_3 ) {
case V_388 :
if ( V_2 -> V_377 & V_378 )
F_83 ( V_5 , V_422 ) ;
if ( V_389 -> V_390 & V_391 ||
! ( V_2 -> V_377 & V_378 ) )
F_65 ( V_2 ) ;
F_67 ( V_389 ) ;
break;
case V_399 :
if ( V_2 -> V_289 == V_290 )
F_83 ( V_5 , V_423 ) ;
if ( V_2 -> V_377 & V_378 )
F_83 ( V_5 , V_422 ) ;
F_65 ( V_2 ) ;
break;
case V_400 :
if ( F_84 ( & V_415 -> V_278 , & V_2 -> V_401 ,
& V_2 -> V_402 ) )
F_54 ( V_299 , L_4 , V_415 -> V_424 ) ;
F_85 ( V_5 , V_423 ) ;
F_85 ( V_5 , V_422 ) ;
F_86 ( V_5 , V_421 ) ;
F_67 ( V_389 ) ;
break;
}
V_2 -> V_387 = V_3 ;
return 0 ;
}
static struct V_246 *
F_87 ( struct V_1 * V_2 , struct V_425 * V_426 ,
unsigned int V_427 , enum V_428 V_429 )
{
if ( V_429 == V_430 )
return F_88 ( V_426 , V_427 ) ;
else
return & V_2 -> V_250 [ V_427 ] ;
}
static struct V_431 *
F_89 ( struct V_1 * V_2 , struct V_425 * V_426 ,
enum V_428 V_429 )
{
if ( V_429 == V_430 )
return F_90 ( V_426 , V_251 ) ;
else
return & V_2 -> V_253 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_425 * V_426 , unsigned int V_427 ,
struct V_246 * V_432 ,
enum V_428 V_429 )
{
enum V_224 V_225 ;
struct V_431 * V_253 ;
unsigned int V_30 ;
switch ( V_427 ) {
case V_251 :
if ( V_2 -> V_289 == V_290 ) {
V_432 -> V_256 = F_92 ( T_2 , V_432 -> V_256 , V_433 ,
F_62 ( V_2 ) ) ;
V_432 -> V_260 = F_92 ( T_2 , V_432 -> V_260 ,
V_434 ,
V_435 ) ;
}
V_432 -> V_436 = V_437 ;
for ( V_30 = 0 ; V_30 < F_38 ( V_438 ) ; V_30 ++ ) {
if ( V_432 -> V_247 == V_438 [ V_30 ] )
break;
}
if ( V_30 >= F_38 ( V_438 ) )
V_432 -> V_247 = V_439 ;
break;
case V_383 :
V_225 = V_432 -> V_247 ;
* V_432 = * F_87 ( V_2 , V_426 , V_251 , V_429 ) ;
switch ( V_225 ) {
case V_228 :
case V_230 :
V_432 -> V_247 = V_225 ;
break;
default:
V_432 -> V_247 = V_228 ;
break;
}
V_253 = F_89 ( V_2 , V_426 , V_429 ) ;
V_432 -> V_256 = V_253 -> V_256 ;
V_432 -> V_260 = V_253 -> V_260 ;
V_432 -> V_436 = V_440 ;
break;
}
V_432 -> V_441 = V_442 ;
}
static void F_93 ( struct V_1 * V_2 ,
const struct V_246 * V_443 ,
struct V_431 * V_253 )
{
unsigned int V_254 = V_444 ;
unsigned int V_445 = V_443 -> V_256 - V_446 ;
unsigned int V_258 = V_447 ;
unsigned int V_448 = V_443 -> V_260 - V_449 ;
if ( V_2 -> V_289 == V_382 ) {
V_254 += 2 ;
V_445 -= 2 ;
}
V_253 -> V_254 &= ~ 1 ;
V_253 -> V_258 &= ~ 1 ;
V_253 -> V_254 = F_92 ( T_2 , V_253 -> V_254 , V_254 , V_445 - V_450 ) ;
V_253 -> V_258 = F_92 ( T_2 , V_253 -> V_258 , V_258 , V_448 - V_451 ) ;
V_253 -> V_256 = F_92 ( T_2 , V_253 -> V_256 , V_450 ,
V_445 - V_253 -> V_254 ) ;
V_253 -> V_260 = F_92 ( T_2 , V_253 -> V_260 , V_451 ,
V_448 - V_253 -> V_258 ) ;
}
static int F_94 ( struct V_414 * V_415 ,
struct V_425 * V_426 ,
struct V_452 * V_247 )
{
switch ( V_247 -> V_427 ) {
case V_251 :
if ( V_247 -> V_453 >= F_38 ( V_438 ) )
return - V_454 ;
V_247 -> V_247 = V_438 [ V_247 -> V_453 ] ;
break;
case V_383 :
if ( V_247 -> V_453 >= F_38 ( V_455 ) )
return - V_454 ;
V_247 -> V_247 = V_455 [ V_247 -> V_453 ] ;
break;
default:
return - V_454 ;
}
return 0 ;
}
static int F_95 ( struct V_414 * V_415 ,
struct V_425 * V_426 ,
struct V_456 * V_457 )
{
struct V_1 * V_2 = F_78 ( V_415 ) ;
struct V_246 V_52 ;
if ( V_457 -> V_453 != 0 )
return - V_454 ;
V_52 . V_247 = V_457 -> V_247 ;
V_52 . V_256 = 1 ;
V_52 . V_260 = 1 ;
F_91 ( V_2 , V_426 , V_457 -> V_427 , & V_52 , V_430 ) ;
V_457 -> V_458 = V_52 . V_256 ;
V_457 -> V_459 = V_52 . V_260 ;
if ( V_52 . V_247 != V_457 -> V_247 )
return - V_454 ;
V_52 . V_247 = V_457 -> V_247 ;
V_52 . V_256 = - 1 ;
V_52 . V_260 = - 1 ;
F_91 ( V_2 , V_426 , V_457 -> V_427 , & V_52 , V_430 ) ;
V_457 -> V_460 = V_52 . V_256 ;
V_457 -> V_461 = V_52 . V_260 ;
return 0 ;
}
static int F_96 ( struct V_414 * V_415 ,
struct V_425 * V_426 ,
struct V_462 * V_463 )
{
struct V_1 * V_2 = F_78 ( V_415 ) ;
struct V_246 * V_52 ;
if ( V_463 -> V_427 != V_251 )
return - V_454 ;
switch ( V_463 -> V_464 ) {
case V_465 :
V_463 -> V_466 . V_254 = 0 ;
V_463 -> V_466 . V_258 = 0 ;
V_463 -> V_466 . V_256 = V_467 ;
V_463 -> V_466 . V_260 = V_467 ;
V_52 = F_87 ( V_2 , V_426 , V_251 ,
V_463 -> V_429 ) ;
F_93 ( V_2 , V_52 , & V_463 -> V_466 ) ;
break;
case V_468 :
V_463 -> V_466 = * F_89 ( V_2 , V_426 , V_463 -> V_429 ) ;
break;
default:
return - V_454 ;
}
return 0 ;
}
static int F_97 ( struct V_414 * V_415 ,
struct V_425 * V_426 ,
struct V_462 * V_463 )
{
struct V_1 * V_2 = F_78 ( V_415 ) ;
struct V_246 * V_52 ;
if ( V_463 -> V_464 != V_468 ||
V_463 -> V_427 != V_251 )
return - V_454 ;
if ( V_2 -> V_387 != V_400 )
return - V_469 ;
if ( V_463 -> V_178 & V_470 ) {
V_463 -> V_466 = * F_89 ( V_2 , V_426 , V_463 -> V_429 ) ;
return 0 ;
}
V_52 = F_87 ( V_2 , V_426 , V_251 , V_463 -> V_429 ) ;
F_93 ( V_2 , V_52 , & V_463 -> V_466 ) ;
* F_89 ( V_2 , V_426 , V_463 -> V_429 ) = V_463 -> V_466 ;
V_52 = F_87 ( V_2 , V_426 , V_383 , V_463 -> V_429 ) ;
F_91 ( V_2 , V_426 , V_383 , V_52 , V_463 -> V_429 ) ;
return 0 ;
}
static int F_98 ( struct V_414 * V_415 , struct V_425 * V_426 ,
struct V_471 * V_432 )
{
struct V_1 * V_2 = F_78 ( V_415 ) ;
struct V_246 * V_52 ;
V_52 = F_87 ( V_2 , V_426 , V_432 -> V_427 , V_432 -> V_429 ) ;
if ( V_52 == NULL )
return - V_454 ;
V_432 -> V_52 = * V_52 ;
return 0 ;
}
static int F_99 ( struct V_414 * V_415 , struct V_425 * V_426 ,
struct V_471 * V_432 )
{
struct V_1 * V_2 = F_78 ( V_415 ) ;
struct V_246 * V_52 ;
struct V_431 * V_253 ;
V_52 = F_87 ( V_2 , V_426 , V_432 -> V_427 , V_432 -> V_429 ) ;
if ( V_52 == NULL )
return - V_454 ;
F_91 ( V_2 , V_426 , V_432 -> V_427 , & V_432 -> V_52 , V_432 -> V_429 ) ;
* V_52 = V_432 -> V_52 ;
if ( V_432 -> V_427 == V_251 ) {
V_253 = F_89 ( V_2 , V_426 , V_432 -> V_429 ) ;
V_253 -> V_254 = 0 ;
V_253 -> V_258 = 0 ;
V_253 -> V_256 = V_432 -> V_52 . V_256 ;
V_253 -> V_260 = V_432 -> V_52 . V_260 ;
F_93 ( V_2 , & V_432 -> V_52 , V_253 ) ;
V_52 = F_87 ( V_2 , V_426 , V_383 ,
V_432 -> V_429 ) ;
F_91 ( V_2 , V_426 , V_383 , V_52 ,
V_432 -> V_429 ) ;
}
return 0 ;
}
static int F_100 ( struct V_414 * V_415 ,
struct V_425 * V_426 )
{
struct V_471 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_427 = V_251 ;
V_52 . V_429 = V_426 ? V_430 : V_472 ;
V_52 . V_52 . V_247 = V_439 ;
V_52 . V_52 . V_256 = 4096 ;
V_52 . V_52 . V_260 = 4096 ;
F_99 ( V_415 , V_426 , & V_52 ) ;
return 0 ;
}
static int F_101 ( struct V_473 * V_278 ,
const struct V_474 * V_475 ,
const struct V_474 * V_476 , T_2 V_178 )
{
struct V_414 * V_415 = F_102 ( V_278 ) ;
struct V_1 * V_2 = F_78 ( V_415 ) ;
switch ( V_475 -> V_453 | F_103 ( V_476 -> V_278 ) ) {
case V_251 | V_477 :
if ( V_178 & V_478 ) {
if ( V_2 -> V_289 == V_382 )
return - V_469 ;
V_2 -> V_289 = V_290 ;
} else {
if ( V_2 -> V_289 == V_290 )
V_2 -> V_289 = V_479 ;
}
break;
case V_251 | V_480 :
if ( V_178 & V_478 ) {
if ( V_2 -> V_289 == V_290 )
return - V_469 ;
V_2 -> V_289 = V_382 ;
} else {
if ( V_2 -> V_289 == V_382 )
V_2 -> V_289 = V_479 ;
}
break;
case V_383 | V_477 :
if ( V_178 & V_478 ) {
if ( V_2 -> V_377 & ~ V_378 )
return - V_469 ;
V_2 -> V_377 |= V_378 ;
} else {
V_2 -> V_377 &= ~ V_378 ;
}
break;
case V_383 | V_480 :
if ( V_178 & V_478 ) {
if ( V_2 -> V_377 & ~ V_380 )
return - V_469 ;
V_2 -> V_377 |= V_380 ;
} else {
V_2 -> V_377 &= ~ V_380 ;
}
break;
default:
return - V_454 ;
}
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_277 ) ;
F_106 ( & V_2 -> V_395 ) ;
F_106 ( & V_2 -> V_389 ) ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_481 * V_482 )
{
int V_483 ;
V_483 = F_108 ( V_482 , & V_2 -> V_277 ) ;
if ( V_483 < 0 )
goto error;
V_483 = F_109 ( & V_2 -> V_395 , V_482 ) ;
if ( V_483 < 0 )
goto error;
V_483 = F_109 ( & V_2 -> V_389 , V_482 ) ;
if ( V_483 < 0 )
goto error;
return 0 ;
error:
F_104 ( V_2 ) ;
return V_483 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_414 * V_415 = & V_2 -> V_277 ;
struct V_474 * V_484 = V_2 -> V_484 ;
struct V_473 * V_485 = & V_415 -> V_278 ;
int V_483 ;
V_2 -> V_289 = V_479 ;
F_111 ( V_415 , & V_486 ) ;
V_415 -> V_487 = & V_488 ;
F_112 ( V_415 -> V_424 , L_5 , sizeof( V_415 -> V_424 ) ) ;
V_415 -> V_489 = 1 << 16 ;
F_113 ( V_415 , V_2 ) ;
V_415 -> V_178 |= V_490 ;
F_114 ( & V_2 -> V_410 , 2 ) ;
F_115 ( & V_2 -> V_410 , & V_491 , V_412 ,
V_492 , V_493 ,
V_494 , V_342 ) ;
F_115 ( & V_2 -> V_410 , & V_491 , V_413 ,
V_495 , V_496 ,
V_497 , V_341 ) ;
F_116 ( & V_2 -> V_410 ) ;
V_415 -> V_498 = & V_2 -> V_410 ;
V_484 [ V_251 ] . V_178 = V_499 ;
V_484 [ V_383 ] . V_178 = V_500 ;
V_485 -> V_501 = & V_502 ;
V_483 = F_117 ( V_485 , V_503 , V_484 , 0 ) ;
if ( V_483 < 0 )
return V_483 ;
F_100 ( V_415 , NULL ) ;
V_2 -> V_395 . type = V_405 ;
V_2 -> V_395 . V_501 = & V_504 ;
V_2 -> V_395 . V_5 = F_2 ( V_2 ) ;
V_2 -> V_395 . V_505 = F_118 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_395 . V_506 = 64 ;
V_2 -> V_389 . type = V_406 ;
V_2 -> V_389 . V_501 = & V_504 ;
V_2 -> V_389 . V_5 = F_2 ( V_2 ) ;
V_2 -> V_389 . V_505 = F_118 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_389 . V_506 = 32 ;
V_483 = F_119 ( & V_2 -> V_395 , L_6 ) ;
if ( V_483 < 0 )
goto V_507;
V_483 = F_119 ( & V_2 -> V_389 , L_6 ) ;
if ( V_483 < 0 )
goto V_508;
V_483 = F_120 ( & V_2 -> V_395 . V_404 . V_278 , 0 ,
& V_2 -> V_277 . V_278 , V_251 , 0 ) ;
if ( V_483 < 0 )
goto V_509;
V_483 = F_120 ( & V_2 -> V_277 . V_278 , V_383 ,
& V_2 -> V_389 . V_404 . V_278 , 0 , 0 ) ;
if ( V_483 < 0 )
goto V_509;
return 0 ;
V_509:
F_121 ( & V_2 -> V_389 ) ;
V_508:
F_121 ( & V_2 -> V_395 ) ;
V_507:
F_122 ( & V_2 -> V_277 . V_278 ) ;
return V_483 ;
}
int F_123 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_303 ;
F_124 ( & V_2 -> V_401 ) ;
F_60 ( V_2 ) ;
return F_110 ( V_2 ) ;
}
void F_125 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_303 ;
F_126 ( & V_2 -> V_410 ) ;
F_121 ( & V_2 -> V_395 ) ;
F_121 ( & V_2 -> V_389 ) ;
F_122 ( & V_2 -> V_277 . V_278 ) ;
}
