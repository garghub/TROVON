static void
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = & V_4 -> V_9 ;
unsigned int V_10 ;
F_3 ( V_6 , V_11 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
F_3 ( V_6 , V_8 -> V_15 [ V_10 ] ,
V_12 , V_16 ) ;
}
}
static void
F_4 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_19 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_19 ) ;
}
static void F_7 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_20 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_20 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_21 * V_22 = & V_4 -> V_22 ;
F_3 ( V_6 , ( V_22 -> V_23 == 1 ? 0 : V_24 ) |
( V_22 -> V_25 == 1 ? 0 : V_26 ) |
( V_22 -> V_27 << V_28 ) ,
V_12 , V_29 ) ;
}
static void F_9 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_30 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_30 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
static const unsigned int V_31 [ 4 ] [ 4 ] = {
{ 0 , 1 , 2 , 3 } ,
{ 1 , 0 , 3 , 2 } ,
{ 2 , 3 , 0 , 1 } ,
{ 3 , 2 , 1 , 0 } ,
} ;
const unsigned int * V_32 = V_31 [ V_2 -> V_4 . V_33 ] ;
const struct V_34 * V_35 = & V_4 -> V_35 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_10 ;
unsigned int V_36 ;
F_3 ( V_6 ,
( V_35 -> V_37 << V_38 ) |
( V_35 -> V_39 << V_40 ) ,
V_12 , V_41 ) ;
F_3 ( V_6 , V_42 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < 4 ; ++ V_10 ) {
const T_1 * V_43 = V_35 -> V_15 [ V_32 [ V_10 ] ] ;
for ( V_36 = 0 ; V_36 < V_44 ; ++ V_36 )
F_3 ( V_6 , V_43 [ V_36 ] , V_12 ,
V_16 ) ;
}
}
static void
F_11 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_45 * V_46 = & V_4 -> V_47 ;
F_3 ( V_6 ,
V_46 -> V_48 | ( V_46 -> V_27 << V_49 ) |
( V_46 -> V_50 << V_51 ) ,
V_12 , V_52 ) ;
}
static void
F_12 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_53 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_53 ) ;
}
static void
F_13 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_54 * V_55 = & V_4 -> V_55 ;
T_2 V_56 ;
F_3 ( V_6 , V_55 -> V_57 , V_12 , V_58 ) ;
V_56 = V_55 -> V_59 << V_60 ;
V_56 |= V_55 -> V_61 << V_62 ;
V_56 |= V_55 -> V_63 << V_64 ;
V_56 |= V_55 -> V_65 << V_66 ;
F_3 ( V_6 , V_56 , V_12 , V_67 ) ;
F_3 ( V_6 ,
V_68 << V_69 |
V_70 << V_71 |
V_68 << V_72 |
V_70 << V_73 |
V_74 << V_75 |
V_76 << V_77 |
V_74 << V_78 |
V_76 << V_79 |
V_68 << V_80 |
V_70 << V_81 |
V_68 << V_82 |
V_70 << V_83 |
V_74 << V_84 |
V_76 << V_85 |
V_74 << V_86 |
V_76 << V_87 ,
V_12 , V_88 ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_89 * V_90 = & V_4 -> V_90 ;
F_3 ( V_6 , ( V_90 -> V_91 << V_92 ) |
( V_90 -> V_93 << V_94 ) |
( V_90 -> V_95 << V_96 ) ,
V_12 , V_97 ) ;
}
static void
F_15 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_98 * V_99 = & V_4 -> V_100 ;
T_2 V_56 ;
V_56 = ( V_99 -> V_101 [ 0 ] [ 0 ] & 0xfff ) << V_102 ;
V_56 |= ( V_99 -> V_101 [ 0 ] [ 1 ] & 0xfff ) << V_103 ;
F_3 ( V_6 , V_56 , V_12 , V_104 ) ;
V_56 = ( V_99 -> V_101 [ 0 ] [ 2 ] & 0xfff ) << V_105 ;
V_56 |= ( V_99 -> V_101 [ 1 ] [ 0 ] & 0xfff ) << V_106 ;
F_3 ( V_6 , V_56 , V_12 , V_107 ) ;
V_56 = ( V_99 -> V_101 [ 1 ] [ 1 ] & 0xfff ) << V_108 ;
V_56 |= ( V_99 -> V_101 [ 1 ] [ 2 ] & 0xfff ) << V_109 ;
F_3 ( V_6 , V_56 , V_12 , V_110 ) ;
V_56 = ( V_99 -> V_101 [ 2 ] [ 0 ] & 0xfff ) << V_111 ;
V_56 |= ( V_99 -> V_101 [ 2 ] [ 1 ] & 0xfff ) << V_112 ;
F_3 ( V_6 , V_56 , V_12 , V_113 ) ;
V_56 = ( V_99 -> V_101 [ 2 ] [ 2 ] & 0xfff ) << V_114 ;
F_3 ( V_6 , V_56 , V_12 , V_115 ) ;
V_56 = ( V_99 -> V_116 [ 0 ] & 0x3ff ) << V_117 ;
V_56 |= ( V_99 -> V_116 [ 1 ] & 0x3ff ) << V_118 ;
F_3 ( V_6 , V_56 , V_12 , V_119 ) ;
V_56 = ( V_99 -> V_116 [ 2 ] & 0x3ff ) << V_120 ;
F_3 ( V_6 , V_56 , V_12 , V_121 ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_122 * V_123 = & V_4 -> V_123 ;
T_2 V_56 ;
V_56 = ( V_123 -> V_101 [ 0 ] [ 0 ] & 0x3ff ) << V_124 ;
V_56 |= ( V_123 -> V_101 [ 0 ] [ 1 ] & 0x3ff ) << V_125 ;
V_56 |= ( V_123 -> V_101 [ 0 ] [ 2 ] & 0x3ff ) << V_126 ;
F_3 ( V_6 , V_56 , V_12 , V_127 ) ;
V_56 = ( V_123 -> V_101 [ 1 ] [ 0 ] & 0x3ff ) << V_128 ;
V_56 |= ( V_123 -> V_101 [ 1 ] [ 1 ] & 0x3ff ) << V_129 ;
V_56 |= ( V_123 -> V_101 [ 1 ] [ 2 ] & 0x3ff ) << V_130 ;
F_3 ( V_6 , V_56 , V_12 , V_131 ) ;
V_56 = ( V_123 -> V_101 [ 2 ] [ 0 ] & 0x3ff ) << V_132 ;
V_56 |= ( V_123 -> V_101 [ 2 ] [ 1 ] & 0x3ff ) << V_133 ;
V_56 |= ( V_123 -> V_101 [ 2 ] [ 2 ] & 0x3ff ) << V_134 ;
F_3 ( V_6 , V_56 , V_12 , V_135 ) ;
V_56 = ( V_123 -> V_116 [ 0 ] & 0xff ) << V_136 ;
V_56 |= ( V_123 -> V_116 [ 1 ] & 0xff ) << V_137 ;
V_56 |= ( V_123 -> V_116 [ 2 ] & 0xff ) << V_138 ;
F_3 ( V_6 , V_56 , V_12 , V_139 ) ;
}
static void
F_17 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_140 * V_141 = & V_4 -> V_142 ;
F_3 ( V_6 ,
V_141 -> V_143 << V_144 |
V_141 -> V_145 << V_146 |
V_141 -> V_147 << V_148 |
V_141 -> V_149 << V_150 ,
V_12 , V_151 ) ;
}
static void
F_18 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_152 * V_153 = & V_4 -> V_153 ;
F_3 ( V_6 , V_153 -> V_154 [ 0 ] ,
V_12 , V_155 ) ;
F_3 ( V_6 , V_153 -> V_154 [ 1 ] ,
V_12 , V_156 ) ;
F_3 ( V_6 , V_153 -> V_154 [ 2 ] ,
V_12 , V_157 ) ;
F_3 ( V_6 , V_153 -> V_154 [ 3 ] ,
V_12 , V_158 ) ;
F_19 ( V_6 , V_12 , V_18 ,
V_159 ,
V_153 -> V_160 ? V_159 : 0 ) ;
}
static void F_20 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_161 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_161 ) ;
}
static void
F_21 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_162 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_162 ) ;
}
static void F_22 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_163 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_163 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_164 * V_165 = & V_4 -> V_165 ;
unsigned int V_10 ;
F_3 ( V_6 , V_165 -> V_166 , V_12 , V_167 ) ;
F_3 ( V_6 , V_168 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_169 ; V_10 ++ ) {
F_3 ( V_6 , V_165 -> V_15 [ V_10 ] ,
V_12 , V_16 ) ;
}
}
static void
F_24 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_170 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_170 ) ;
}
static void
F_25 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_171 * V_172 = & V_4 -> gamma ;
unsigned int V_10 ;
F_3 ( V_6 , V_173 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_174 ; V_10 ++ )
F_3 ( V_6 , V_172 -> V_95 [ V_10 ] , V_12 ,
V_16 ) ;
F_3 ( V_6 , V_175 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_174 ; V_10 ++ )
F_3 ( V_6 , V_172 -> V_93 [ V_10 ] , V_12 ,
V_16 ) ;
F_3 ( V_6 , V_176 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_174 ; V_10 ++ )
F_3 ( V_6 , V_172 -> V_91 [ V_10 ] , V_12 ,
V_16 ) ;
}
static void
F_26 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_6 ( V_6 , V_12 , V_18 ,
V_177 ) ;
else
F_5 ( V_6 , V_12 , V_18 ,
V_177 ) ;
}
static void
F_27 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_6 , V_12 , V_178 ,
0xff << V_179 ,
V_4 -> V_180 << V_179 ) ;
}
static void
F_28 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_6 , V_12 , V_178 ,
0xff << V_181 ,
V_4 -> V_182 << V_181 ) ;
}
static void
F_29 ( struct V_1 * V_2 , T_3 V_180 )
{
struct V_3 * V_4 ;
unsigned long V_183 ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_4 = ( V_2 -> V_4 . V_185 & V_186 )
? & V_2 -> V_4 . V_4 [ 0 ] : & V_2 -> V_4 . V_4 [ 1 ] ;
if ( V_4 -> V_180 != ( V_180 * V_187 ) ) {
V_4 -> V_180 = V_180 * V_187 ;
V_4 -> V_188 |= V_186 ;
}
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
}
static void
F_32 ( struct V_1 * V_2 , T_3 V_182 )
{
struct V_3 * V_4 ;
unsigned long V_183 ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_4 = ( V_2 -> V_4 . V_185 & V_189 )
? & V_2 -> V_4 . V_4 [ 0 ] : & V_2 -> V_4 . V_4 [ 1 ] ;
if ( V_4 -> V_182 != ( V_182 * V_190 ) ) {
V_4 -> V_182 = V_182 * V_190 ;
V_4 -> V_188 |= V_189 ;
}
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
}
static T_2
F_33 ( struct V_1 * V_2 , T_2 V_188 , bool V_191 )
{
T_2 V_185 = V_2 -> V_4 . V_185 ;
if ( V_191 ) {
V_2 -> V_4 . V_4 [ 0 ] . V_192 |= ~ V_185 & V_188 ;
V_2 -> V_4 . V_4 [ 1 ] . V_192 |= V_185 & V_188 ;
} else {
V_188 = ( V_2 -> V_4 . V_4 [ 0 ] . V_188 & V_185 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_188 & ~ V_185 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_192 |= V_185 & V_188 ;
V_2 -> V_4 . V_4 [ 1 ] . V_192 |= ~ V_185 & V_188 ;
}
return V_188 ;
}
static void
F_34 ( struct V_1 * V_2 , T_2 V_188 , bool V_191 )
{
T_2 V_185 = V_2 -> V_4 . V_185 ;
if ( V_191 ) {
V_2 -> V_4 . V_4 [ 0 ] . V_188 |= ( ~ V_185 & V_188 ) ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 |= ( V_185 & V_188 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_192 &= V_185 ;
V_2 -> V_4 . V_4 [ 1 ] . V_192 &= ~ V_185 ;
} else {
V_2 -> V_4 . V_4 [ 0 ] . V_188 &= ~ ( V_185 & V_188 ) ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 &= ~ ( ~ V_185 & V_188 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_192 &= ~ V_185 ;
V_2 -> V_4 . V_4 [ 1 ] . V_192 &= V_185 ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
T_2 V_193 ;
V_193 = ( V_2 -> V_4 . V_4 [ 0 ] . V_188 & ~ V_2 -> V_4 . V_185 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_188 & V_2 -> V_4 . V_185 ) ;
V_193 &= ~ ( V_2 -> V_4 . V_4 [ 0 ] . V_192 |
V_2 -> V_4 . V_4 [ 1 ] . V_192 ) ;
if ( V_193 == 0 )
return;
V_2 -> V_4 . V_185 ^= V_193 ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 &= ~ ( ~ V_2 -> V_4 . V_185 & V_193 ) ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 &= ~ ( V_2 -> V_4 . V_185 & V_193 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_194 * V_195 )
{
unsigned long V_183 ;
unsigned int V_10 ;
int V_196 = 0 ;
T_2 V_188 ;
T_2 V_185 ;
if ( V_195 -> V_188 == 0 )
return 0 ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_33 ( V_2 , V_195 -> V_188 , true ) ;
V_185 = V_2 -> V_4 . V_185 ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_188 = 0 ;
for ( V_10 = 0 ; V_10 < F_37 ( V_197 ) ; V_10 ++ ) {
const struct V_198 * V_199 = & V_197 [ V_10 ] ;
struct V_3 * V_4 ;
unsigned int V_200 = 1 << V_10 ;
if ( V_199 -> V_201 || ! ( V_195 -> V_188 & V_200 ) )
continue;
V_4 = & V_2 -> V_4 . V_4 [ ! ! ( V_185 & V_200 ) ] ;
if ( V_195 -> V_202 & V_200 ) {
void T_4 * V_203 = * ( void * T_4 * )
( ( void * ) V_195 + V_199 -> V_204 ) ;
void * V_205 = ( void * ) V_4 + V_199 -> V_206 ;
T_5 V_207 = V_199 -> V_208 ;
if ( V_205 && V_203 && V_207 ) {
if ( F_38 ( V_205 , V_203 , V_207 ) ) {
V_196 = - V_209 ;
break;
}
}
V_4 -> V_210 |= V_200 ;
} else {
V_4 -> V_210 &= ~ V_200 ;
}
V_188 |= V_200 ;
}
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_34 ( V_2 , V_188 , true ) ;
F_35 ( V_2 ) ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
return V_196 ;
}
static void F_39 ( struct V_1 * V_2 , T_2 V_188 ,
T_2 V_185 )
{
unsigned int V_10 ;
T_2 V_210 ;
if ( V_188 == 0 )
return;
V_210 = ( V_2 -> V_4 . V_4 [ 0 ] . V_210 & V_185 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_210 & ~ V_185 ) ;
for ( V_10 = 0 ; V_10 < F_37 ( V_197 ) ; V_10 ++ ) {
const struct V_198 * V_199 = & V_197 [ V_10 ] ;
struct V_3 * V_4 ;
unsigned int V_200 = 1 << V_10 ;
if ( ! ( V_188 & V_200 ) )
continue;
V_4 = & V_2 -> V_4 . V_4 [ ! ( V_185 & V_200 ) ] ;
if ( V_4 -> V_210 & V_200 ) {
if ( V_199 -> V_211 )
V_199 -> V_211 ( V_2 , V_4 ) ;
if ( V_199 -> V_17 )
V_199 -> V_17 ( V_2 , true ) ;
} else {
if ( V_199 -> V_17 )
V_199 -> V_17 ( V_2 , false ) ;
}
}
}
static void
F_40 ( struct V_1 * V_2 ,
enum V_212 V_213 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
enum V_214 V_215 ;
switch ( V_213 ) {
case V_216 :
V_215 = V_217 ;
break;
case V_218 :
V_215 = V_219 ;
break;
default:
return;
}
F_19 ( V_6 , V_12 , V_18 ,
V_220 ,
V_215 << V_221 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_3 V_222 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_223 << V_224 |
V_225 << V_226 |
V_222 , V_12 , V_227 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_228 * V_229 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_229 -> V_230 == 8 )
F_5 ( V_6 , V_12 , V_18 ,
V_231 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_231 ) ;
switch ( V_229 -> V_232 ) {
case V_233 :
V_2 -> V_4 . V_33 = 0 ;
break;
case V_234 :
V_2 -> V_4 . V_33 = 1 ;
break;
case V_235 :
V_2 -> V_4 . V_33 = 2 ;
break;
case V_236 :
V_2 -> V_4 . V_33 = 3 ;
break;
default:
F_6 ( V_6 , V_12 , V_18 ,
V_237 ) ;
return;
}
F_5 ( V_6 , V_12 , V_18 , V_237 ) ;
F_19 ( V_6 , V_12 , V_18 ,
V_238 , V_239 ) ;
V_4 = ( V_2 -> V_4 . V_185 & V_240 )
? & V_2 -> V_4 . V_4 [ 0 ] : & V_2 -> V_4 . V_4 [ 1 ] ;
F_10 ( V_2 , V_4 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_2 V_185 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_241 = V_2 -> V_242 . V_243 ;
unsigned int V_244 = V_2 -> V_242 . V_243 + V_2 -> V_242 . V_230 - 1 ;
unsigned int V_245 = V_2 -> V_242 . V_246 ;
unsigned int V_247 = V_2 -> V_242 . V_246 + V_2 -> V_242 . V_248 - 1 ;
T_2 V_210 ;
V_210 = ( V_2 -> V_4 . V_4 [ 0 ] . V_210 & V_185 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_210 & ~ V_185 ) ;
if ( V_210 & ( V_249 | V_250 ) ) {
V_241 -= 2 ;
V_244 += 2 ;
V_245 -= 2 ;
V_247 += 2 ;
}
if ( V_210 & V_251 ) {
V_241 -= 2 ;
V_244 += 2 ;
}
if ( V_210 & ( V_252 | V_253 ) )
V_241 -= 2 ;
F_3 ( V_6 , ( V_241 << V_254 ) | V_244 ,
V_12 , V_255 ) ;
F_3 ( V_6 , ( V_245 << V_256 ) | V_247 ,
V_12 , V_257 ) ;
}
static void
F_44 ( struct V_1 * V_2 , T_2 V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_116 & 0xffff , V_12 ,
V_258 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_2 V_259 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_259 , V_12 , V_260 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
T_2 V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_116 & 0xffff , V_12 ,
V_261 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_2 V_259 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_259 , V_12 , V_262 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_263 * V_264 = F_49 ( & V_2 -> V_265 . V_266 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_267 * V_268 = & V_2 -> V_269 [ V_270 ] ;
unsigned long V_271 = V_264 -> V_271 ;
struct V_272 * V_273 ;
unsigned int V_274 ;
unsigned int V_275 ;
unsigned int V_276 ;
unsigned int V_277 ;
unsigned int V_278 ;
unsigned int V_279 ;
if ( V_2 -> V_280 != V_281 ) {
F_6 ( V_6 , V_282 , V_283 ,
V_284 ) ;
return;
}
V_276 = F_50 ( ( V_285 ) V_271 / 2 * 256 + V_264 -> V_286 - 1 ,
V_264 -> V_286 ) ;
V_277 = F_51 ( V_276 , 32 ) ;
V_273 = & V_264 -> V_287 ;
V_275 = F_51 ( V_268 -> V_230 * 2 , 256 ) * V_268 -> V_248 ;
V_274 = F_50 ( ( V_285 ) V_271 * V_273 -> V_288 ,
V_273 -> V_289 ) ;
V_276 = V_274 / V_275 ;
V_278 = V_276 / 32 ;
V_279 = F_52 ( V_277 , V_278 ) ;
F_53 ( V_6 -> V_290 , L_1 , V_291 , V_279 ) ;
F_19 ( V_6 , V_282 , V_283 ,
V_284 ,
V_279 << V_292 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_55 ( V_6 , V_12 , V_18 )
& V_293 ;
}
void F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_294 ;
const T_2 V_188 = V_295 - 1 ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = V_2 -> V_4 . V_185 & V_188 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = ~ V_2 -> V_4 . V_185 & V_188 ;
F_39 ( V_2 , V_188 , V_2 -> V_4 . V_185 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = 0 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_53 ( V_6 -> V_290 , L_2 ) ;
F_58 ( V_6 , V_296 ) ;
F_58 ( V_6 , V_297 ) ;
F_58 ( V_6 , V_298 ) ;
F_58 ( V_6 , V_299 ) ;
F_58 ( V_6 , V_300 ) ;
F_58 ( V_6 , V_301 ) ;
F_58 ( V_6 , V_302 ) ;
F_58 ( V_6 , V_303 ) ;
F_58 ( V_6 , V_304 ) ;
F_58 ( V_6 , V_305 ) ;
F_58 ( V_6 , V_306 ) ;
F_58 ( V_6 , V_307 ) ;
F_58 ( V_6 , V_308 ) ;
F_58 ( V_6 , V_309 ) ;
F_58 ( V_6 , V_310 ) ;
F_58 ( V_6 , V_311 ) ;
F_58 ( V_6 , V_312 ) ;
F_58 ( V_6 , V_313 ) ;
F_58 ( V_6 , V_314 ) ;
F_58 ( V_6 , V_315 ) ;
F_58 ( V_6 , V_316 ) ;
F_58 ( V_6 , V_317 ) ;
F_58 ( V_6 , V_318 ) ;
F_58 ( V_6 , V_319 ) ;
F_58 ( V_6 , V_320 ) ;
F_58 ( V_6 , V_321 ) ;
F_58 ( V_6 , V_322 ) ;
F_58 ( V_6 , V_323 ) ;
F_58 ( V_6 , V_324 ) ;
F_58 ( V_6 , V_325 ) ;
F_58 ( V_6 , V_326 ) ;
F_58 ( V_6 , V_327 ) ;
F_58 ( V_6 , V_328 ) ;
F_58 ( V_6 , V_329 ) ;
F_58 ( V_6 , V_330 ) ;
F_58 ( V_6 , V_331 ) ;
F_53 ( V_6 -> V_290 , L_3 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_10 ;
F_60 ( & V_2 -> V_4 . V_184 ) ;
V_2 -> V_4 . V_185 = ~ 0 ;
V_2 -> V_4 . V_4 [ 0 ] . V_192 = 0 ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = V_295 - 1 ;
V_2 -> V_4 . V_4 [ 1 ] . V_192 = 0 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = 0 ;
V_4 = & V_2 -> V_4 . V_4 [ 0 ] ;
V_4 -> V_180 = V_332 * V_187 ;
V_4 -> V_182 = V_333 * V_190 ;
V_4 -> V_35 . V_334 = V_335 ;
memcpy ( V_4 -> V_35 . V_15 , V_336 ,
sizeof( V_4 -> V_35 . V_15 ) ) ;
V_4 -> V_35 . V_39 = V_337 ;
V_4 -> V_35 . V_37 = V_338 ;
V_4 -> V_47 . V_48 = V_339 ;
V_4 -> V_47 . V_27 = V_340 ;
V_4 -> V_47 . V_50 = 0 ;
memcpy ( V_4 -> V_9 . V_15 , V_341 ,
sizeof( V_4 -> V_9 . V_15 ) ) ;
V_4 -> V_165 . V_166 = V_342 ;
memcpy ( V_4 -> V_165 . V_15 , V_343 , sizeof( V_4 -> V_165 . V_15 ) ) ;
V_4 -> V_153 . V_160 = 1 ;
for ( V_10 = 0 ; V_10 < V_344 ; V_10 ++ )
V_4 -> V_153 . V_154 [ V_10 ] = V_345 ;
memcpy ( V_4 -> gamma . V_91 , V_346 , sizeof( V_4 -> gamma . V_91 ) ) ;
memcpy ( V_4 -> gamma . V_93 , V_346 , sizeof( V_4 -> gamma . V_93 ) ) ;
memcpy ( V_4 -> gamma . V_95 , V_346 , sizeof( V_4 -> gamma . V_95 ) ) ;
V_4 -> V_55 . V_57 = V_347 ;
V_4 -> V_55 . V_59 = V_348 ;
V_4 -> V_55 . V_61 = V_348 ;
V_4 -> V_55 . V_63 = V_348 ;
V_4 -> V_55 . V_65 = V_348 ;
V_4 -> V_90 . V_95 = V_349 ;
V_4 -> V_90 . V_93 = V_350 ;
V_4 -> V_90 . V_91 = V_351 ;
V_4 -> V_100 = V_352 ;
V_4 -> V_123 = V_353 ;
V_4 -> V_142 . V_147 = V_354 ;
V_4 -> V_142 . V_143 = V_355 ;
V_4 -> V_142 . V_149 = V_354 ;
V_4 -> V_142 . V_145 = V_355 ;
V_4 -> V_210 = V_240 | V_249
| V_250 | V_356
| V_357 | V_358
| V_359 | V_360
| V_361 | V_189
| V_186 ;
}
static unsigned int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_362 ) {
case V_363 :
return V_364 ;
case V_365 :
default:
return V_366 ;
case V_367 :
return V_368 ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_228 * V_229 ;
struct V_267 * V_334 ;
unsigned long V_183 ;
T_2 V_188 ;
T_2 V_185 ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_188 = F_33 ( V_2 , 0 , false ) ;
V_185 = V_2 -> V_4 . V_185 ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_334 = & V_2 -> V_269 [ V_270 ] ;
V_229 = F_63 ( V_334 -> V_369 ) ;
F_48 ( V_2 ) ;
F_42 ( V_2 , V_229 ) ;
F_43 ( V_2 , V_185 ) ;
if ( V_2 -> V_280 == V_370 )
F_44 ( V_2 , 0 ) ;
else
F_44 ( V_2 , F_64 ( V_334 -> V_230 , 0x20 ) *
V_229 -> V_371 ) ;
F_39 ( V_2 , V_188 , V_185 ) ;
V_334 = & V_2 -> V_269 [ V_372 ] ;
if ( V_2 -> V_373 & V_374 )
F_5 ( V_6 , V_12 , V_18 ,
V_375 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_375 ) ;
if ( V_2 -> V_373 & V_376 )
F_5 ( V_6 , V_12 , V_18 ,
V_377 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_377 ) ;
if ( V_2 -> V_373 & V_374 )
F_46 ( V_2 ,
F_64 ( V_334 -> V_230 , 0x10 ) * 2 ) ;
F_41 ( V_2 , 0 ) ;
F_40 ( V_2 , V_334 -> V_369 ) ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_34 ( V_2 , V_188 , false ) ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_2 -> V_280 == V_281 )
F_5 ( V_6 , V_12 , V_18 ,
V_378 ) ;
F_5 ( V_6 , V_12 , V_18 ,
V_379 | V_380 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_381 == V_382 &&
V_2 -> V_383 . V_384 & V_385 ) {
F_65 ( V_2 ) ;
F_67 ( & V_2 -> V_383 ) ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_263 * V_264 = F_49 ( & V_2 -> V_265 . V_266 ) ;
struct V_386 * V_387 ;
int V_388 = 0 ;
if ( V_2 -> V_280 == V_281 ) {
V_387 = F_69 ( & V_2 -> V_389 ) ;
if ( V_387 != NULL )
F_45 ( V_2 , V_387 -> V_390 ) ;
V_264 -> V_381 |= V_391 ;
}
if ( V_2 -> V_373 & V_374 ) {
V_387 = F_69 ( & V_2 -> V_383 ) ;
if ( V_387 != NULL ) {
F_47 ( V_2 , V_387 -> V_390 ) ;
V_388 = 1 ;
}
V_264 -> V_381 |= V_392 ;
}
switch ( V_2 -> V_381 ) {
case V_393 :
if ( F_70 ( V_264 ) )
F_71 ( V_264 ,
V_393 ) ;
break;
case V_382 :
if ( V_388 )
F_65 ( V_2 ) ;
break;
case V_394 :
default:
return;
}
}
void F_72 ( struct V_1 * V_2 )
{
unsigned long V_183 ;
T_2 V_188 ;
T_2 V_185 ;
if ( F_73 ( & V_2 -> V_395 , & V_2 -> V_396 ) )
return;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_35 ( V_2 ) ;
V_188 = F_33 ( V_2 , 0 , false ) ;
V_185 = V_2 -> V_4 . V_185 ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_39 ( V_2 , V_188 , V_185 ) ;
F_43 ( V_2 , V_185 ) ;
if ( V_2 -> V_280 == V_281 ||
V_2 -> V_373 & V_374 )
F_68 ( V_2 ) ;
else if ( V_2 -> V_381 == V_382 )
F_65 ( V_2 ) ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_34 ( V_2 , V_188 , false ) ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
}
static int F_74 ( struct V_397 * V_398 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = & V_398 -> V_6 -> V_294 ;
if ( V_398 -> type == V_399 )
F_45 ( V_2 , V_387 -> V_390 ) ;
if ( V_398 -> type == V_400 )
F_47 ( V_2 , V_387 -> V_390 ) ;
return 0 ;
}
static int F_75 ( struct V_401 * V_402 )
{
struct V_1 * V_2 =
F_76 ( V_402 -> V_403 , struct V_1 , V_404 ) ;
switch ( V_402 -> V_405 ) {
case V_406 :
F_32 ( V_2 , V_402 -> V_56 ) ;
break;
case V_407 :
F_29 ( V_2 , V_402 -> V_56 ) ;
break;
}
return 0 ;
}
static long F_77 ( struct V_408 * V_409 , unsigned int V_410 , void * V_411 )
{
struct V_1 * V_2 = F_78 ( V_409 ) ;
switch ( V_410 ) {
case V_412 :
return F_36 ( V_2 , V_411 ) ;
default:
return - V_413 ;
}
}
static int F_79 ( struct V_408 * V_409 , int V_17 )
{
struct V_1 * V_2 = F_78 ( V_409 ) ;
struct V_397 * V_383 = & V_2 -> V_383 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_414 * V_290 = F_80 ( V_2 ) ;
if ( V_2 -> V_381 == V_394 ) {
if ( V_17 == V_394 )
return 0 ;
F_81 ( V_6 , V_415 ) ;
F_62 ( V_2 ) ;
F_82 ( & V_2 -> V_396 , 0 ) ;
F_57 ( V_2 ) ;
}
switch ( V_17 ) {
case V_382 :
if ( V_2 -> V_373 & V_374 )
F_83 ( V_6 , V_416 ) ;
if ( V_383 -> V_384 & V_385 ||
! ( V_2 -> V_373 & V_374 ) )
F_65 ( V_2 ) ;
F_67 ( V_383 ) ;
break;
case V_393 :
if ( V_2 -> V_280 == V_281 )
F_83 ( V_6 , V_417 ) ;
if ( V_2 -> V_373 & V_374 )
F_83 ( V_6 , V_416 ) ;
F_65 ( V_2 ) ;
break;
case V_394 :
if ( F_84 ( & V_409 -> V_266 , & V_2 -> V_395 ,
& V_2 -> V_396 ) )
F_53 ( V_290 , L_4 , V_409 -> V_418 ) ;
F_85 ( V_6 , V_417 ) ;
F_85 ( V_6 , V_416 ) ;
F_86 ( V_6 , V_415 ) ;
F_67 ( V_383 ) ;
break;
}
V_2 -> V_381 = V_17 ;
return 0 ;
}
static struct V_267 *
F_87 ( struct V_1 * V_2 , struct V_419 * V_420 ,
unsigned int V_421 , enum V_422 V_423 )
{
if ( V_423 == V_424 )
return F_88 ( V_420 , V_421 ) ;
else
return & V_2 -> V_269 [ V_421 ] ;
}
static struct V_425 *
F_89 ( struct V_1 * V_2 , struct V_419 * V_420 ,
enum V_422 V_423 )
{
if ( V_423 == V_424 )
return F_90 ( V_420 , V_270 ) ;
else
return & V_2 -> V_242 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_419 * V_420 , unsigned int V_421 ,
struct V_267 * V_426 ,
enum V_422 V_423 )
{
enum V_212 V_213 ;
struct V_425 * V_242 ;
unsigned int V_10 ;
switch ( V_421 ) {
case V_270 :
if ( V_2 -> V_280 == V_281 ) {
V_426 -> V_230 = F_92 ( T_2 , V_426 -> V_230 , V_427 ,
F_61 ( V_2 ) ) ;
V_426 -> V_248 = F_92 ( T_2 , V_426 -> V_248 ,
V_428 ,
V_429 ) ;
}
V_426 -> V_430 = V_431 ;
for ( V_10 = 0 ; V_10 < F_37 ( V_432 ) ; V_10 ++ ) {
if ( V_426 -> V_369 == V_432 [ V_10 ] )
break;
}
if ( V_10 >= F_37 ( V_432 ) )
V_426 -> V_369 = V_433 ;
break;
case V_372 :
V_213 = V_426 -> V_369 ;
* V_426 = * F_87 ( V_2 , V_420 , V_270 , V_423 ) ;
switch ( V_213 ) {
case V_216 :
case V_218 :
V_426 -> V_369 = V_213 ;
break;
default:
V_426 -> V_369 = V_216 ;
break;
}
V_242 = F_89 ( V_2 , V_420 , V_423 ) ;
V_426 -> V_230 = V_242 -> V_230 ;
V_426 -> V_248 = V_242 -> V_248 ;
V_426 -> V_430 = V_434 ;
break;
}
V_426 -> V_435 = V_436 ;
}
static void F_93 ( struct V_1 * V_2 ,
const struct V_267 * V_437 ,
struct V_425 * V_242 )
{
unsigned int V_243 = V_438 ;
unsigned int V_439 = V_437 -> V_230 - V_440 ;
unsigned int V_246 = V_441 ;
unsigned int V_442 = V_437 -> V_248 - V_443 ;
if ( V_2 -> V_280 == V_370 ) {
V_243 += 2 ;
V_439 -= 2 ;
}
if ( V_437 -> V_369 != V_444 &&
V_437 -> V_369 != V_445 ) {
V_243 += 2 ;
V_439 -= 2 ;
V_246 += 2 ;
V_442 -= 2 ;
}
V_242 -> V_243 &= ~ 1 ;
V_242 -> V_246 &= ~ 1 ;
V_242 -> V_243 = F_92 ( T_2 , V_242 -> V_243 , V_243 , V_439 - V_446 ) ;
V_242 -> V_246 = F_92 ( T_2 , V_242 -> V_246 , V_246 , V_442 - V_447 ) ;
V_242 -> V_230 = F_92 ( T_2 , V_242 -> V_230 , V_446 ,
V_439 - V_242 -> V_243 ) ;
V_242 -> V_248 = F_92 ( T_2 , V_242 -> V_248 , V_447 ,
V_442 - V_242 -> V_246 ) ;
}
static int F_94 ( struct V_408 * V_409 ,
struct V_419 * V_420 ,
struct V_448 * V_369 )
{
switch ( V_369 -> V_421 ) {
case V_270 :
if ( V_369 -> V_449 >= F_37 ( V_432 ) )
return - V_450 ;
V_369 -> V_369 = V_432 [ V_369 -> V_449 ] ;
break;
case V_372 :
if ( V_369 -> V_449 >= F_37 ( V_451 ) )
return - V_450 ;
V_369 -> V_369 = V_451 [ V_369 -> V_449 ] ;
break;
default:
return - V_450 ;
}
return 0 ;
}
static int F_95 ( struct V_408 * V_409 ,
struct V_419 * V_420 ,
struct V_452 * V_453 )
{
struct V_1 * V_2 = F_78 ( V_409 ) ;
struct V_267 V_334 ;
if ( V_453 -> V_449 != 0 )
return - V_450 ;
V_334 . V_369 = V_453 -> V_369 ;
V_334 . V_230 = 1 ;
V_334 . V_248 = 1 ;
F_91 ( V_2 , V_420 , V_453 -> V_421 , & V_334 , V_424 ) ;
V_453 -> V_454 = V_334 . V_230 ;
V_453 -> V_455 = V_334 . V_248 ;
if ( V_334 . V_369 != V_453 -> V_369 )
return - V_450 ;
V_334 . V_369 = V_453 -> V_369 ;
V_334 . V_230 = - 1 ;
V_334 . V_248 = - 1 ;
F_91 ( V_2 , V_420 , V_453 -> V_421 , & V_334 , V_424 ) ;
V_453 -> V_456 = V_334 . V_230 ;
V_453 -> V_457 = V_334 . V_248 ;
return 0 ;
}
static int F_96 ( struct V_408 * V_409 ,
struct V_419 * V_420 ,
struct V_458 * V_459 )
{
struct V_1 * V_2 = F_78 ( V_409 ) ;
struct V_267 * V_334 ;
if ( V_459 -> V_421 != V_270 )
return - V_450 ;
switch ( V_459 -> V_460 ) {
case V_461 :
V_459 -> V_462 . V_243 = 0 ;
V_459 -> V_462 . V_246 = 0 ;
V_459 -> V_462 . V_230 = V_463 ;
V_459 -> V_462 . V_248 = V_463 ;
V_334 = F_87 ( V_2 , V_420 , V_270 ,
V_459 -> V_423 ) ;
F_93 ( V_2 , V_334 , & V_459 -> V_462 ) ;
break;
case V_464 :
V_459 -> V_462 = * F_89 ( V_2 , V_420 , V_459 -> V_423 ) ;
break;
default:
return - V_450 ;
}
return 0 ;
}
static int F_97 ( struct V_408 * V_409 ,
struct V_419 * V_420 ,
struct V_458 * V_459 )
{
struct V_1 * V_2 = F_78 ( V_409 ) ;
struct V_267 * V_334 ;
if ( V_459 -> V_460 != V_464 ||
V_459 -> V_421 != V_270 )
return - V_450 ;
if ( V_2 -> V_381 != V_394 )
return - V_465 ;
if ( V_459 -> V_183 & V_466 ) {
V_459 -> V_462 = * F_89 ( V_2 , V_420 , V_459 -> V_423 ) ;
return 0 ;
}
V_334 = F_87 ( V_2 , V_420 , V_270 , V_459 -> V_423 ) ;
F_93 ( V_2 , V_334 , & V_459 -> V_462 ) ;
* F_89 ( V_2 , V_420 , V_459 -> V_423 ) = V_459 -> V_462 ;
V_334 = F_87 ( V_2 , V_420 , V_372 , V_459 -> V_423 ) ;
F_91 ( V_2 , V_420 , V_372 , V_334 , V_459 -> V_423 ) ;
return 0 ;
}
static int F_98 ( struct V_408 * V_409 , struct V_419 * V_420 ,
struct V_467 * V_426 )
{
struct V_1 * V_2 = F_78 ( V_409 ) ;
struct V_267 * V_334 ;
V_334 = F_87 ( V_2 , V_420 , V_426 -> V_421 , V_426 -> V_423 ) ;
if ( V_334 == NULL )
return - V_450 ;
V_426 -> V_334 = * V_334 ;
return 0 ;
}
static int F_99 ( struct V_408 * V_409 , struct V_419 * V_420 ,
struct V_467 * V_426 )
{
struct V_1 * V_2 = F_78 ( V_409 ) ;
struct V_267 * V_334 ;
struct V_425 * V_242 ;
V_334 = F_87 ( V_2 , V_420 , V_426 -> V_421 , V_426 -> V_423 ) ;
if ( V_334 == NULL )
return - V_450 ;
F_91 ( V_2 , V_420 , V_426 -> V_421 , & V_426 -> V_334 , V_426 -> V_423 ) ;
* V_334 = V_426 -> V_334 ;
if ( V_426 -> V_421 == V_270 ) {
V_242 = F_89 ( V_2 , V_420 , V_426 -> V_423 ) ;
V_242 -> V_243 = 0 ;
V_242 -> V_246 = 0 ;
V_242 -> V_230 = V_426 -> V_334 . V_230 ;
V_242 -> V_248 = V_426 -> V_334 . V_248 ;
F_93 ( V_2 , & V_426 -> V_334 , V_242 ) ;
V_334 = F_87 ( V_2 , V_420 , V_372 ,
V_426 -> V_423 ) ;
F_91 ( V_2 , V_420 , V_372 , V_334 ,
V_426 -> V_423 ) ;
}
return 0 ;
}
static int F_100 ( struct V_408 * V_409 ,
struct V_419 * V_420 )
{
struct V_467 V_334 ;
memset ( & V_334 , 0 , sizeof( V_334 ) ) ;
V_334 . V_421 = V_270 ;
V_334 . V_423 = V_420 ? V_424 : V_468 ;
V_334 . V_334 . V_369 = V_433 ;
V_334 . V_334 . V_230 = 4096 ;
V_334 . V_334 . V_248 = 4096 ;
F_99 ( V_409 , V_420 , & V_334 ) ;
return 0 ;
}
static int F_101 ( struct V_469 * V_266 ,
const struct V_470 * V_471 ,
const struct V_470 * V_472 , T_2 V_183 )
{
struct V_408 * V_409 = F_102 ( V_266 ) ;
struct V_1 * V_2 = F_78 ( V_409 ) ;
switch ( V_471 -> V_449 | F_103 ( V_472 -> V_266 ) ) {
case V_270 | V_473 :
if ( V_183 & V_474 ) {
if ( V_2 -> V_280 == V_370 )
return - V_465 ;
V_2 -> V_280 = V_281 ;
} else {
if ( V_2 -> V_280 == V_281 )
V_2 -> V_280 = V_475 ;
}
break;
case V_270 | V_476 :
if ( V_183 & V_474 ) {
if ( V_2 -> V_280 == V_281 )
return - V_465 ;
V_2 -> V_280 = V_370 ;
} else {
if ( V_2 -> V_280 == V_370 )
V_2 -> V_280 = V_475 ;
}
break;
case V_372 | V_473 :
if ( V_183 & V_474 ) {
if ( V_2 -> V_373 & ~ V_374 )
return - V_465 ;
V_2 -> V_373 |= V_374 ;
} else {
V_2 -> V_373 &= ~ V_374 ;
}
break;
case V_372 | V_476 :
if ( V_183 & V_474 ) {
if ( V_2 -> V_373 & ~ V_376 )
return - V_465 ;
V_2 -> V_373 |= V_376 ;
} else {
V_2 -> V_373 &= ~ V_376 ;
}
break;
default:
return - V_450 ;
}
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_265 ) ;
F_106 ( & V_2 -> V_389 ) ;
F_106 ( & V_2 -> V_383 ) ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_477 * V_478 )
{
int V_479 ;
V_479 = F_108 ( V_478 , & V_2 -> V_265 ) ;
if ( V_479 < 0 )
goto error;
V_479 = F_109 ( & V_2 -> V_389 , V_478 ) ;
if ( V_479 < 0 )
goto error;
V_479 = F_109 ( & V_2 -> V_383 , V_478 ) ;
if ( V_479 < 0 )
goto error;
return 0 ;
error:
F_104 ( V_2 ) ;
return V_479 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_408 * V_409 = & V_2 -> V_265 ;
struct V_470 * V_480 = V_2 -> V_480 ;
struct V_469 * V_481 = & V_409 -> V_266 ;
int V_479 ;
V_2 -> V_280 = V_475 ;
F_111 ( V_409 , & V_482 ) ;
V_409 -> V_483 = & V_484 ;
F_112 ( V_409 -> V_418 , L_5 , sizeof( V_409 -> V_418 ) ) ;
V_409 -> V_485 = 1 << 16 ;
F_113 ( V_409 , V_2 ) ;
V_409 -> V_183 |= V_486 ;
F_114 ( & V_2 -> V_404 , 2 ) ;
F_115 ( & V_2 -> V_404 , & V_487 , V_406 ,
V_488 , V_489 ,
V_490 , V_333 ) ;
F_115 ( & V_2 -> V_404 , & V_487 , V_407 ,
V_491 , V_492 ,
V_493 , V_332 ) ;
F_116 ( & V_2 -> V_404 ) ;
V_409 -> V_494 = & V_2 -> V_404 ;
V_480 [ V_270 ] . V_183 = V_495
| V_496 ;
V_480 [ V_372 ] . V_183 = V_497 ;
V_481 -> V_498 = & V_499 ;
V_479 = F_117 ( V_481 , V_500 , V_480 , 0 ) ;
if ( V_479 < 0 )
return V_479 ;
F_100 ( V_409 , NULL ) ;
V_2 -> V_389 . type = V_399 ;
V_2 -> V_389 . V_498 = & V_501 ;
V_2 -> V_389 . V_6 = F_2 ( V_2 ) ;
V_2 -> V_389 . V_502 = F_118 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_389 . V_503 = 64 ;
V_2 -> V_383 . type = V_400 ;
V_2 -> V_383 . V_498 = & V_501 ;
V_2 -> V_383 . V_6 = F_2 ( V_2 ) ;
V_2 -> V_383 . V_502 = F_118 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_383 . V_503 = 32 ;
V_479 = F_119 ( & V_2 -> V_389 , L_6 ) ;
if ( V_479 < 0 )
goto V_504;
V_479 = F_119 ( & V_2 -> V_383 , L_6 ) ;
if ( V_479 < 0 )
goto V_505;
V_479 = F_120 ( & V_2 -> V_389 . V_398 . V_266 , 0 ,
& V_2 -> V_265 . V_266 , V_270 , 0 ) ;
if ( V_479 < 0 )
goto V_506;
V_479 = F_120 ( & V_2 -> V_265 . V_266 , V_372 ,
& V_2 -> V_383 . V_398 . V_266 , 0 , 0 ) ;
if ( V_479 < 0 )
goto V_506;
return 0 ;
V_506:
F_121 ( & V_2 -> V_383 ) ;
V_505:
F_121 ( & V_2 -> V_389 ) ;
V_504:
F_122 ( & V_2 -> V_265 . V_266 ) ;
return V_479 ;
}
int F_123 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_294 ;
F_124 ( & V_2 -> V_395 ) ;
F_59 ( V_2 ) ;
return F_110 ( V_2 ) ;
}
void F_125 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_294 ;
F_126 ( & V_2 -> V_404 ) ;
F_121 ( & V_2 -> V_389 ) ;
F_121 ( & V_2 -> V_383 ) ;
F_122 ( & V_2 -> V_265 . V_266 ) ;
}
