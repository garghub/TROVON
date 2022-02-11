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
const struct V_241 * V_242 = & V_2 -> V_243 [ V_244 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_245 = V_2 -> V_246 . V_247 ;
unsigned int V_248 = V_2 -> V_246 . V_247 + V_2 -> V_246 . V_230 - 1 ;
unsigned int V_249 = V_2 -> V_246 . V_250 ;
unsigned int V_251 = V_2 -> V_246 . V_250 + V_2 -> V_246 . V_252 - 1 ;
T_2 V_210 ;
if ( V_242 -> V_253 != V_254 &&
V_242 -> V_253 != V_255 ) {
V_245 -= 2 ;
V_248 += 2 ;
V_249 -= 2 ;
V_251 += 2 ;
}
V_210 = ( V_2 -> V_4 . V_4 [ 0 ] . V_210 & V_185 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_210 & ~ V_185 ) ;
if ( V_210 & ( V_256 | V_257 ) ) {
V_245 -= 2 ;
V_248 += 2 ;
V_249 -= 2 ;
V_251 += 2 ;
}
if ( V_210 & V_258 ) {
V_245 -= 2 ;
V_248 += 2 ;
}
if ( V_210 & ( V_259 | V_260 ) )
V_245 -= 2 ;
F_3 ( V_6 , ( V_245 << V_261 ) | V_248 ,
V_12 , V_262 ) ;
F_3 ( V_6 , ( V_249 << V_263 ) | V_251 ,
V_12 , V_264 ) ;
}
static void
F_44 ( struct V_1 * V_2 , T_2 V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_116 & 0xffff , V_12 ,
V_265 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_2 V_266 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_266 , V_12 , V_267 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
T_2 V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_116 & 0xffff , V_12 ,
V_268 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_2 V_266 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_266 , V_12 , V_269 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_270 * V_271 = F_49 ( & V_2 -> V_272 . V_273 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_241 * V_274 = & V_2 -> V_243 [ V_244 ] ;
unsigned long V_275 = V_271 -> V_275 ;
struct V_276 * V_277 ;
unsigned int V_278 ;
unsigned int V_279 ;
unsigned int V_280 ;
unsigned int V_281 ;
unsigned int V_282 ;
unsigned int V_283 ;
if ( V_2 -> V_284 != V_285 ) {
F_6 ( V_6 , V_286 , V_287 ,
V_288 ) ;
return;
}
V_280 = F_50 ( ( V_289 ) V_275 / 2 * 256 + V_271 -> V_290 - 1 ,
V_271 -> V_290 ) ;
V_281 = F_51 ( V_280 , 32 ) ;
V_277 = & V_271 -> V_291 ;
V_279 = F_51 ( V_274 -> V_230 * 2 , 256 ) * V_274 -> V_252 ;
V_278 = F_50 ( ( V_289 ) V_275 * V_277 -> V_292 ,
V_277 -> V_293 ) ;
V_280 = V_278 / V_279 ;
V_282 = V_280 / 32 ;
V_283 = F_52 ( V_281 , V_282 ) ;
F_53 ( V_6 -> V_294 , L_1 , V_295 , V_283 ) ;
F_19 ( V_6 , V_286 , V_287 ,
V_288 ,
V_283 << V_296 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_55 ( V_6 , V_12 , V_18 )
& V_297 ;
}
void F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_298 ;
const T_2 V_188 = V_299 - 1 ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = V_2 -> V_4 . V_185 & V_188 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = ~ V_2 -> V_4 . V_185 & V_188 ;
F_39 ( V_2 , V_188 , V_2 -> V_4 . V_185 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = 0 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_53 ( V_6 -> V_294 , L_2 ) ;
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
F_58 ( V_6 , V_332 ) ;
F_58 ( V_6 , V_333 ) ;
F_58 ( V_6 , V_334 ) ;
F_58 ( V_6 , V_335 ) ;
F_53 ( V_6 -> V_294 , L_3 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_10 ;
F_60 ( & V_2 -> V_4 . V_184 ) ;
V_2 -> V_4 . V_185 = ~ 0 ;
V_2 -> V_4 . V_4 [ 0 ] . V_192 = 0 ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = V_299 - 1 ;
V_2 -> V_4 . V_4 [ 1 ] . V_192 = 0 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = 0 ;
V_4 = & V_2 -> V_4 . V_4 [ 0 ] ;
V_4 -> V_180 = V_336 * V_187 ;
V_4 -> V_182 = V_337 * V_190 ;
V_4 -> V_35 . V_242 = V_338 ;
memcpy ( V_4 -> V_35 . V_15 , V_339 ,
sizeof( V_4 -> V_35 . V_15 ) ) ;
V_4 -> V_35 . V_39 = V_340 ;
V_4 -> V_35 . V_37 = V_341 ;
V_4 -> V_47 . V_48 = V_342 ;
V_4 -> V_47 . V_27 = V_343 ;
V_4 -> V_47 . V_50 = 0 ;
memcpy ( V_4 -> V_9 . V_15 , V_344 ,
sizeof( V_4 -> V_9 . V_15 ) ) ;
V_4 -> V_165 . V_166 = V_345 ;
memcpy ( V_4 -> V_165 . V_15 , V_346 , sizeof( V_4 -> V_165 . V_15 ) ) ;
V_4 -> V_153 . V_160 = 1 ;
for ( V_10 = 0 ; V_10 < V_347 ; V_10 ++ )
V_4 -> V_153 . V_154 [ V_10 ] = V_348 ;
memcpy ( V_4 -> gamma . V_91 , V_349 , sizeof( V_4 -> gamma . V_91 ) ) ;
memcpy ( V_4 -> gamma . V_93 , V_349 , sizeof( V_4 -> gamma . V_93 ) ) ;
memcpy ( V_4 -> gamma . V_95 , V_349 , sizeof( V_4 -> gamma . V_95 ) ) ;
V_4 -> V_55 . V_57 = V_350 ;
V_4 -> V_55 . V_59 = V_351 ;
V_4 -> V_55 . V_61 = V_351 ;
V_4 -> V_55 . V_63 = V_351 ;
V_4 -> V_55 . V_65 = V_351 ;
V_4 -> V_90 . V_95 = V_352 ;
V_4 -> V_90 . V_93 = V_353 ;
V_4 -> V_90 . V_91 = V_354 ;
V_4 -> V_100 = V_355 ;
V_4 -> V_123 = V_356 ;
V_4 -> V_142 . V_147 = V_357 ;
V_4 -> V_142 . V_143 = V_358 ;
V_4 -> V_142 . V_149 = V_357 ;
V_4 -> V_142 . V_145 = V_358 ;
V_4 -> V_210 = V_240 | V_256
| V_257 | V_359
| V_360 | V_361
| V_362 | V_363
| V_364 | V_189
| V_186 ;
}
static unsigned int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_365 ) {
case V_366 :
return V_367 ;
case V_368 :
default:
return V_369 ;
case V_370 :
return V_371 ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_228 * V_229 ;
struct V_241 * V_242 ;
unsigned long V_183 ;
T_2 V_188 ;
T_2 V_185 ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_188 = F_33 ( V_2 , 0 , false ) ;
V_185 = V_2 -> V_4 . V_185 ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_242 = & V_2 -> V_243 [ V_244 ] ;
V_229 = F_63 ( V_242 -> V_253 ) ;
F_48 ( V_2 ) ;
F_42 ( V_2 , V_229 ) ;
F_43 ( V_2 , V_185 ) ;
if ( V_2 -> V_284 == V_372 )
F_44 ( V_2 , 0 ) ;
else
F_44 ( V_2 , F_64 ( V_242 -> V_230 , 0x20 ) *
V_229 -> V_373 ) ;
F_39 ( V_2 , V_188 , V_185 ) ;
V_242 = & V_2 -> V_243 [ V_374 ] ;
if ( V_2 -> V_375 & V_376 )
F_5 ( V_6 , V_12 , V_18 ,
V_377 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_377 ) ;
if ( V_2 -> V_375 & V_378 )
F_5 ( V_6 , V_12 , V_18 ,
V_379 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_379 ) ;
if ( V_2 -> V_375 & V_376 )
F_46 ( V_2 ,
F_64 ( V_242 -> V_230 , 0x10 ) * 2 ) ;
F_41 ( V_2 , 0 ) ;
F_40 ( V_2 , V_242 -> V_253 ) ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_34 ( V_2 , V_188 , false ) ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_2 -> V_284 == V_285 )
F_5 ( V_6 , V_12 , V_18 ,
V_380 ) ;
F_5 ( V_6 , V_12 , V_18 ,
V_381 | V_382 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_383 == V_384 &&
V_2 -> V_385 . V_386 & V_387 ) {
F_65 ( V_2 ) ;
F_67 ( & V_2 -> V_385 ) ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_270 * V_271 = F_49 ( & V_2 -> V_272 . V_273 ) ;
struct V_388 * V_389 ;
int V_390 = 0 ;
if ( V_2 -> V_284 == V_285 ) {
V_389 = F_69 ( & V_2 -> V_391 ) ;
if ( V_389 != NULL )
F_45 ( V_2 , V_389 -> V_392 ) ;
V_271 -> V_383 |= V_393 ;
}
if ( V_2 -> V_375 & V_376 ) {
V_389 = F_69 ( & V_2 -> V_385 ) ;
if ( V_389 != NULL ) {
F_47 ( V_2 , V_389 -> V_392 ) ;
V_390 = 1 ;
}
V_271 -> V_383 |= V_394 ;
}
switch ( V_2 -> V_383 ) {
case V_395 :
if ( F_70 ( V_271 ) )
F_71 ( V_271 ,
V_395 ) ;
break;
case V_384 :
if ( V_390 )
F_65 ( V_2 ) ;
break;
case V_396 :
default:
return;
}
}
void F_72 ( struct V_1 * V_2 )
{
unsigned long V_183 ;
T_2 V_188 ;
T_2 V_185 ;
if ( F_73 ( & V_2 -> V_397 , & V_2 -> V_398 ) )
return;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_35 ( V_2 ) ;
V_188 = F_33 ( V_2 , 0 , false ) ;
V_185 = V_2 -> V_4 . V_185 ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_39 ( V_2 , V_188 , V_185 ) ;
F_43 ( V_2 , V_185 ) ;
if ( V_2 -> V_284 == V_285 ||
V_2 -> V_375 & V_376 )
F_68 ( V_2 ) ;
else if ( V_2 -> V_383 == V_384 )
F_65 ( V_2 ) ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_34 ( V_2 , V_188 , false ) ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
}
static int F_74 ( struct V_399 * V_400 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = & V_400 -> V_6 -> V_298 ;
if ( V_400 -> type == V_401 )
F_45 ( V_2 , V_389 -> V_392 ) ;
if ( V_400 -> type == V_402 )
F_47 ( V_2 , V_389 -> V_392 ) ;
return 0 ;
}
static int F_75 ( struct V_403 * V_404 )
{
struct V_1 * V_2 =
F_76 ( V_404 -> V_405 , struct V_1 , V_406 ) ;
switch ( V_404 -> V_407 ) {
case V_408 :
F_32 ( V_2 , V_404 -> V_56 ) ;
break;
case V_409 :
F_29 ( V_2 , V_404 -> V_56 ) ;
break;
}
return 0 ;
}
static long F_77 ( struct V_410 * V_411 , unsigned int V_412 , void * V_413 )
{
struct V_1 * V_2 = F_78 ( V_411 ) ;
switch ( V_412 ) {
case V_414 :
return F_36 ( V_2 , V_413 ) ;
default:
return - V_415 ;
}
}
static int F_79 ( struct V_410 * V_411 , int V_17 )
{
struct V_1 * V_2 = F_78 ( V_411 ) ;
struct V_399 * V_385 = & V_2 -> V_385 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_416 * V_294 = F_80 ( V_2 ) ;
if ( V_2 -> V_383 == V_396 ) {
if ( V_17 == V_396 )
return 0 ;
F_81 ( V_6 , V_417 ) ;
F_62 ( V_2 ) ;
F_82 ( & V_2 -> V_398 , 0 ) ;
F_57 ( V_2 ) ;
}
switch ( V_17 ) {
case V_384 :
if ( V_2 -> V_375 & V_376 )
F_83 ( V_6 , V_418 ) ;
if ( V_385 -> V_386 & V_387 ||
! ( V_2 -> V_375 & V_376 ) )
F_65 ( V_2 ) ;
F_67 ( V_385 ) ;
break;
case V_395 :
if ( V_2 -> V_284 == V_285 )
F_83 ( V_6 , V_419 ) ;
if ( V_2 -> V_375 & V_376 )
F_83 ( V_6 , V_418 ) ;
F_65 ( V_2 ) ;
break;
case V_396 :
if ( F_84 ( & V_411 -> V_273 , & V_2 -> V_397 ,
& V_2 -> V_398 ) )
F_53 ( V_294 , L_4 , V_411 -> V_420 ) ;
F_85 ( V_6 , V_419 ) ;
F_85 ( V_6 , V_418 ) ;
F_86 ( V_6 , V_417 ) ;
F_67 ( V_385 ) ;
break;
}
V_2 -> V_383 = V_17 ;
return 0 ;
}
static struct V_241 *
F_87 ( struct V_1 * V_2 , struct V_421 * V_422 ,
unsigned int V_423 , enum V_424 V_425 )
{
if ( V_425 == V_426 )
return F_88 ( V_422 , V_423 ) ;
else
return & V_2 -> V_243 [ V_423 ] ;
}
static struct V_427 *
F_89 ( struct V_1 * V_2 , struct V_421 * V_422 ,
enum V_424 V_425 )
{
if ( V_425 == V_426 )
return F_90 ( V_422 , V_244 ) ;
else
return & V_2 -> V_246 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_421 * V_422 , unsigned int V_423 ,
struct V_241 * V_428 ,
enum V_424 V_425 )
{
enum V_212 V_213 ;
struct V_427 * V_246 ;
unsigned int V_10 ;
switch ( V_423 ) {
case V_244 :
if ( V_2 -> V_284 == V_285 ) {
V_428 -> V_230 = F_92 ( T_2 , V_428 -> V_230 , V_429 ,
F_61 ( V_2 ) ) ;
V_428 -> V_252 = F_92 ( T_2 , V_428 -> V_252 ,
V_430 ,
V_431 ) ;
}
V_428 -> V_432 = V_433 ;
for ( V_10 = 0 ; V_10 < F_37 ( V_434 ) ; V_10 ++ ) {
if ( V_428 -> V_253 == V_434 [ V_10 ] )
break;
}
if ( V_10 >= F_37 ( V_434 ) )
V_428 -> V_253 = V_435 ;
break;
case V_374 :
V_213 = V_428 -> V_253 ;
* V_428 = * F_87 ( V_2 , V_422 , V_244 , V_425 ) ;
switch ( V_213 ) {
case V_216 :
case V_218 :
V_428 -> V_253 = V_213 ;
break;
default:
V_428 -> V_253 = V_216 ;
break;
}
V_246 = F_89 ( V_2 , V_422 , V_425 ) ;
V_428 -> V_230 = V_246 -> V_230 ;
V_428 -> V_252 = V_246 -> V_252 ;
V_428 -> V_432 = V_436 ;
break;
}
V_428 -> V_437 = V_438 ;
}
static void F_93 ( struct V_1 * V_2 ,
const struct V_241 * V_439 ,
struct V_427 * V_246 )
{
unsigned int V_247 = V_440 ;
unsigned int V_441 = V_439 -> V_230 - V_442 ;
unsigned int V_250 = V_443 ;
unsigned int V_444 = V_439 -> V_252 - V_445 ;
if ( V_2 -> V_284 == V_372 ) {
V_247 += 2 ;
V_441 -= 2 ;
}
if ( V_439 -> V_253 != V_254 &&
V_439 -> V_253 != V_255 ) {
V_247 += 2 ;
V_441 -= 2 ;
V_250 += 2 ;
V_444 -= 2 ;
}
V_246 -> V_247 &= ~ 1 ;
V_246 -> V_250 &= ~ 1 ;
V_246 -> V_247 = F_92 ( T_2 , V_246 -> V_247 , V_247 , V_441 - V_446 ) ;
V_246 -> V_250 = F_92 ( T_2 , V_246 -> V_250 , V_250 , V_444 - V_447 ) ;
V_246 -> V_230 = F_92 ( T_2 , V_246 -> V_230 , V_446 ,
V_441 - V_246 -> V_247 ) ;
V_246 -> V_252 = F_92 ( T_2 , V_246 -> V_252 , V_447 ,
V_444 - V_246 -> V_250 ) ;
}
static int F_94 ( struct V_410 * V_411 ,
struct V_421 * V_422 ,
struct V_448 * V_253 )
{
switch ( V_253 -> V_423 ) {
case V_244 :
if ( V_253 -> V_449 >= F_37 ( V_434 ) )
return - V_450 ;
V_253 -> V_253 = V_434 [ V_253 -> V_449 ] ;
break;
case V_374 :
if ( V_253 -> V_449 >= F_37 ( V_451 ) )
return - V_450 ;
V_253 -> V_253 = V_451 [ V_253 -> V_449 ] ;
break;
default:
return - V_450 ;
}
return 0 ;
}
static int F_95 ( struct V_410 * V_411 ,
struct V_421 * V_422 ,
struct V_452 * V_453 )
{
struct V_1 * V_2 = F_78 ( V_411 ) ;
struct V_241 V_242 ;
if ( V_453 -> V_449 != 0 )
return - V_450 ;
V_242 . V_253 = V_453 -> V_253 ;
V_242 . V_230 = 1 ;
V_242 . V_252 = 1 ;
F_91 ( V_2 , V_422 , V_453 -> V_423 , & V_242 , V_426 ) ;
V_453 -> V_454 = V_242 . V_230 ;
V_453 -> V_455 = V_242 . V_252 ;
if ( V_242 . V_253 != V_453 -> V_253 )
return - V_450 ;
V_242 . V_253 = V_453 -> V_253 ;
V_242 . V_230 = - 1 ;
V_242 . V_252 = - 1 ;
F_91 ( V_2 , V_422 , V_453 -> V_423 , & V_242 , V_426 ) ;
V_453 -> V_456 = V_242 . V_230 ;
V_453 -> V_457 = V_242 . V_252 ;
return 0 ;
}
static int F_96 ( struct V_410 * V_411 ,
struct V_421 * V_422 ,
struct V_458 * V_459 )
{
struct V_1 * V_2 = F_78 ( V_411 ) ;
struct V_241 * V_242 ;
if ( V_459 -> V_423 != V_244 )
return - V_450 ;
switch ( V_459 -> V_460 ) {
case V_461 :
V_459 -> V_462 . V_247 = 0 ;
V_459 -> V_462 . V_250 = 0 ;
V_459 -> V_462 . V_230 = V_463 ;
V_459 -> V_462 . V_252 = V_463 ;
V_242 = F_87 ( V_2 , V_422 , V_244 ,
V_459 -> V_425 ) ;
F_93 ( V_2 , V_242 , & V_459 -> V_462 ) ;
break;
case V_464 :
V_459 -> V_462 = * F_89 ( V_2 , V_422 , V_459 -> V_425 ) ;
break;
default:
return - V_450 ;
}
return 0 ;
}
static int F_97 ( struct V_410 * V_411 ,
struct V_421 * V_422 ,
struct V_458 * V_459 )
{
struct V_1 * V_2 = F_78 ( V_411 ) ;
struct V_241 * V_242 ;
if ( V_459 -> V_460 != V_464 ||
V_459 -> V_423 != V_244 )
return - V_450 ;
if ( V_2 -> V_383 != V_396 )
return - V_465 ;
if ( V_459 -> V_183 & V_466 ) {
V_459 -> V_462 = * F_89 ( V_2 , V_422 , V_459 -> V_425 ) ;
return 0 ;
}
V_242 = F_87 ( V_2 , V_422 , V_244 , V_459 -> V_425 ) ;
F_93 ( V_2 , V_242 , & V_459 -> V_462 ) ;
* F_89 ( V_2 , V_422 , V_459 -> V_425 ) = V_459 -> V_462 ;
V_242 = F_87 ( V_2 , V_422 , V_374 , V_459 -> V_425 ) ;
F_91 ( V_2 , V_422 , V_374 , V_242 , V_459 -> V_425 ) ;
return 0 ;
}
static int F_98 ( struct V_410 * V_411 , struct V_421 * V_422 ,
struct V_467 * V_428 )
{
struct V_1 * V_2 = F_78 ( V_411 ) ;
struct V_241 * V_242 ;
V_242 = F_87 ( V_2 , V_422 , V_428 -> V_423 , V_428 -> V_425 ) ;
if ( V_242 == NULL )
return - V_450 ;
V_428 -> V_242 = * V_242 ;
return 0 ;
}
static int F_99 ( struct V_410 * V_411 , struct V_421 * V_422 ,
struct V_467 * V_428 )
{
struct V_1 * V_2 = F_78 ( V_411 ) ;
struct V_241 * V_242 ;
struct V_427 * V_246 ;
V_242 = F_87 ( V_2 , V_422 , V_428 -> V_423 , V_428 -> V_425 ) ;
if ( V_242 == NULL )
return - V_450 ;
F_91 ( V_2 , V_422 , V_428 -> V_423 , & V_428 -> V_242 , V_428 -> V_425 ) ;
* V_242 = V_428 -> V_242 ;
if ( V_428 -> V_423 == V_244 ) {
V_246 = F_89 ( V_2 , V_422 , V_428 -> V_425 ) ;
V_246 -> V_247 = 0 ;
V_246 -> V_250 = 0 ;
V_246 -> V_230 = V_428 -> V_242 . V_230 ;
V_246 -> V_252 = V_428 -> V_242 . V_252 ;
F_93 ( V_2 , & V_428 -> V_242 , V_246 ) ;
V_242 = F_87 ( V_2 , V_422 , V_374 ,
V_428 -> V_425 ) ;
F_91 ( V_2 , V_422 , V_374 , V_242 ,
V_428 -> V_425 ) ;
}
return 0 ;
}
static int F_100 ( struct V_410 * V_411 ,
struct V_421 * V_422 )
{
struct V_467 V_242 ;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
V_242 . V_423 = V_244 ;
V_242 . V_425 = V_422 ? V_426 : V_468 ;
V_242 . V_242 . V_253 = V_435 ;
V_242 . V_242 . V_230 = 4096 ;
V_242 . V_242 . V_252 = 4096 ;
F_99 ( V_411 , V_422 , & V_242 ) ;
return 0 ;
}
static int F_101 ( struct V_469 * V_273 ,
const struct V_470 * V_471 ,
const struct V_470 * V_472 , T_2 V_183 )
{
struct V_410 * V_411 = F_102 ( V_273 ) ;
struct V_1 * V_2 = F_78 ( V_411 ) ;
switch ( V_471 -> V_449 | F_103 ( V_472 -> V_273 ) ) {
case V_244 | V_473 :
if ( V_183 & V_474 ) {
if ( V_2 -> V_284 == V_372 )
return - V_465 ;
V_2 -> V_284 = V_285 ;
} else {
if ( V_2 -> V_284 == V_285 )
V_2 -> V_284 = V_475 ;
}
break;
case V_244 | V_476 :
if ( V_183 & V_474 ) {
if ( V_2 -> V_284 == V_285 )
return - V_465 ;
V_2 -> V_284 = V_372 ;
} else {
if ( V_2 -> V_284 == V_372 )
V_2 -> V_284 = V_475 ;
}
break;
case V_374 | V_473 :
if ( V_183 & V_474 ) {
if ( V_2 -> V_375 & ~ V_376 )
return - V_465 ;
V_2 -> V_375 |= V_376 ;
} else {
V_2 -> V_375 &= ~ V_376 ;
}
break;
case V_374 | V_476 :
if ( V_183 & V_474 ) {
if ( V_2 -> V_375 & ~ V_378 )
return - V_465 ;
V_2 -> V_375 |= V_378 ;
} else {
V_2 -> V_375 &= ~ V_378 ;
}
break;
default:
return - V_450 ;
}
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_272 ) ;
F_106 ( & V_2 -> V_391 ) ;
F_106 ( & V_2 -> V_385 ) ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_477 * V_478 )
{
int V_479 ;
V_479 = F_108 ( V_478 , & V_2 -> V_272 ) ;
if ( V_479 < 0 )
goto error;
V_479 = F_109 ( & V_2 -> V_391 , V_478 ) ;
if ( V_479 < 0 )
goto error;
V_479 = F_109 ( & V_2 -> V_385 , V_478 ) ;
if ( V_479 < 0 )
goto error;
return 0 ;
error:
F_104 ( V_2 ) ;
return V_479 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_410 * V_411 = & V_2 -> V_272 ;
struct V_470 * V_480 = V_2 -> V_480 ;
struct V_469 * V_481 = & V_411 -> V_273 ;
int V_479 ;
V_2 -> V_284 = V_475 ;
F_111 ( V_411 , & V_482 ) ;
V_411 -> V_483 = & V_484 ;
F_112 ( V_411 -> V_420 , L_5 , sizeof( V_411 -> V_420 ) ) ;
V_411 -> V_485 = 1 << 16 ;
F_113 ( V_411 , V_2 ) ;
V_411 -> V_183 |= V_486 ;
F_114 ( & V_2 -> V_406 , 2 ) ;
F_115 ( & V_2 -> V_406 , & V_487 , V_408 ,
V_488 , V_489 ,
V_490 , V_337 ) ;
F_115 ( & V_2 -> V_406 , & V_487 , V_409 ,
V_491 , V_492 ,
V_493 , V_336 ) ;
F_116 ( & V_2 -> V_406 ) ;
V_411 -> V_494 = & V_2 -> V_406 ;
V_480 [ V_244 ] . V_183 = V_495
| V_496 ;
V_480 [ V_374 ] . V_183 = V_497 ;
V_481 -> V_498 = & V_499 ;
V_479 = F_117 ( V_481 , V_500 , V_480 , 0 ) ;
if ( V_479 < 0 )
return V_479 ;
F_100 ( V_411 , NULL ) ;
V_2 -> V_391 . type = V_401 ;
V_2 -> V_391 . V_498 = & V_501 ;
V_2 -> V_391 . V_6 = F_2 ( V_2 ) ;
V_2 -> V_391 . V_502 = F_118 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_391 . V_503 = 64 ;
V_2 -> V_385 . type = V_402 ;
V_2 -> V_385 . V_498 = & V_501 ;
V_2 -> V_385 . V_6 = F_2 ( V_2 ) ;
V_2 -> V_385 . V_502 = F_118 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_385 . V_503 = 32 ;
V_479 = F_119 ( & V_2 -> V_391 , L_6 ) ;
if ( V_479 < 0 )
goto V_504;
V_479 = F_119 ( & V_2 -> V_385 , L_6 ) ;
if ( V_479 < 0 )
goto V_505;
V_479 = F_120 ( & V_2 -> V_391 . V_400 . V_273 , 0 ,
& V_2 -> V_272 . V_273 , V_244 , 0 ) ;
if ( V_479 < 0 )
goto V_506;
V_479 = F_120 ( & V_2 -> V_272 . V_273 , V_374 ,
& V_2 -> V_385 . V_400 . V_273 , 0 , 0 ) ;
if ( V_479 < 0 )
goto V_506;
return 0 ;
V_506:
F_121 ( & V_2 -> V_385 ) ;
V_505:
F_121 ( & V_2 -> V_391 ) ;
V_504:
F_122 ( & V_2 -> V_272 . V_273 ) ;
return V_479 ;
}
int F_123 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_298 ;
F_124 ( & V_2 -> V_397 ) ;
F_59 ( V_2 ) ;
return F_110 ( V_2 ) ;
}
void F_125 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_298 ;
F_126 ( & V_2 -> V_406 ) ;
F_121 ( & V_2 -> V_391 ) ;
F_121 ( & V_2 -> V_385 ) ;
F_122 ( & V_2 -> V_272 . V_273 ) ;
}
