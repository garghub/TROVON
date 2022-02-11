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
if ( V_188 == 0 )
return;
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
static void F_40 ( struct V_1 * V_2 , T_2 V_212 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
enum V_213 V_214 ;
switch ( V_212 ) {
case V_215 :
V_214 = V_216 ;
break;
case V_217 :
V_214 = V_218 ;
break;
default:
return;
}
F_19 ( V_6 , V_12 , V_18 ,
V_219 ,
V_214 << V_220 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_3 V_221 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_222 << V_223 |
V_224 << V_225 |
V_221 , V_12 , V_226 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_227 * V_228 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_228 -> V_229 == 8 )
F_5 ( V_6 , V_12 , V_18 ,
V_230 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_230 ) ;
switch ( V_228 -> V_231 ) {
case V_232 :
V_2 -> V_4 . V_33 = 0 ;
break;
case V_233 :
V_2 -> V_4 . V_33 = 1 ;
break;
case V_234 :
V_2 -> V_4 . V_33 = 2 ;
break;
case V_235 :
V_2 -> V_4 . V_33 = 3 ;
break;
default:
F_6 ( V_6 , V_12 , V_18 ,
V_236 ) ;
return;
}
F_5 ( V_6 , V_12 , V_18 , V_236 ) ;
F_19 ( V_6 , V_12 , V_18 ,
V_237 , V_238 ) ;
V_4 = ( V_2 -> V_4 . V_185 & V_239 )
? & V_2 -> V_4 . V_4 [ 0 ] : & V_2 -> V_4 . V_4 [ 1 ] ;
F_10 ( V_2 , V_4 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_2 V_185 )
{
const struct V_240 * V_241 = & V_2 -> V_242 [ V_243 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_244 = V_2 -> V_245 . V_246 ;
unsigned int V_247 = V_2 -> V_245 . V_246 + V_2 -> V_245 . V_229 - 1 ;
unsigned int V_248 = V_2 -> V_245 . V_249 ;
unsigned int V_250 = V_2 -> V_245 . V_249 + V_2 -> V_245 . V_251 - 1 ;
T_2 V_210 ;
if ( V_241 -> V_252 != V_253 &&
V_241 -> V_252 != V_254 ) {
V_244 -= 2 ;
V_247 += 2 ;
V_248 -= 2 ;
V_250 += 2 ;
}
V_210 = ( V_2 -> V_4 . V_4 [ 0 ] . V_210 & V_185 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_210 & ~ V_185 ) ;
if ( V_210 & ( V_255 | V_256 ) ) {
V_244 -= 2 ;
V_247 += 2 ;
V_248 -= 2 ;
V_250 += 2 ;
}
if ( V_210 & V_257 ) {
V_244 -= 2 ;
V_247 += 2 ;
}
if ( V_210 & ( V_258 | V_259 ) )
V_244 -= 2 ;
F_3 ( V_6 , ( V_244 << V_260 ) | V_247 ,
V_12 , V_261 ) ;
F_3 ( V_6 , ( V_248 << V_262 ) | V_250 ,
V_12 , V_263 ) ;
}
static void
F_44 ( struct V_1 * V_2 , T_2 V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_116 & 0xffff , V_12 ,
V_264 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_2 V_265 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_265 , V_12 , V_266 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
T_2 V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_116 & 0xffff , V_12 ,
V_267 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_2 V_265 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_265 , V_12 , V_268 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_269 * V_270 = F_49 ( & V_2 -> V_271 . V_272 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_240 * V_273 = & V_2 -> V_242 [ V_243 ] ;
unsigned long V_274 = V_270 -> V_274 ;
struct V_275 * V_276 ;
unsigned int V_277 ;
unsigned int V_278 ;
unsigned int V_279 ;
unsigned int V_280 ;
unsigned int V_281 ;
unsigned int V_282 ;
if ( V_2 -> V_283 != V_284 ) {
F_6 ( V_6 , V_285 , V_286 ,
V_287 ) ;
return;
}
V_279 = F_50 ( ( V_288 ) V_274 / 2 * 256 + V_270 -> V_289 - 1 ,
V_270 -> V_289 ) ;
V_280 = F_51 ( V_279 , 32 ) ;
V_276 = & V_270 -> V_290 ;
V_278 = F_51 ( V_273 -> V_229 * 2 , 256 ) * V_273 -> V_251 ;
V_277 = F_50 ( ( V_288 ) V_274 * V_276 -> V_291 ,
V_276 -> V_292 ) ;
V_279 = V_277 / V_278 ;
V_281 = V_279 / 32 ;
V_282 = F_52 ( V_280 , V_281 ) ;
F_53 ( V_6 -> V_293 , L_1 , V_294 , V_282 ) ;
F_19 ( V_6 , V_285 , V_286 ,
V_287 ,
V_282 << V_295 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_55 ( V_6 , V_12 , V_18 )
& V_296 ;
}
void F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_297 ;
const T_2 V_188 = V_298 - 1 ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = V_2 -> V_4 . V_185 & V_188 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = ~ V_2 -> V_4 . V_185 & V_188 ;
F_39 ( V_2 , V_188 , V_2 -> V_4 . V_185 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = 0 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_53 ( V_6 -> V_293 , L_2 ) ;
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
F_58 ( V_6 , V_332 ) ;
F_58 ( V_6 , V_333 ) ;
F_58 ( V_6 , V_334 ) ;
F_53 ( V_6 -> V_293 , L_3 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_10 ;
F_60 ( & V_2 -> V_4 . V_184 ) ;
V_2 -> V_4 . V_185 = ~ 0 ;
V_2 -> V_4 . V_4 [ 0 ] . V_192 = 0 ;
V_2 -> V_4 . V_4 [ 0 ] . V_188 = V_298 - 1 ;
V_2 -> V_4 . V_4 [ 1 ] . V_192 = 0 ;
V_2 -> V_4 . V_4 [ 1 ] . V_188 = 0 ;
V_4 = & V_2 -> V_4 . V_4 [ 0 ] ;
V_4 -> V_180 = V_335 * V_187 ;
V_4 -> V_182 = V_336 * V_190 ;
V_4 -> V_35 . V_241 = V_337 ;
memcpy ( V_4 -> V_35 . V_15 , V_338 ,
sizeof( V_4 -> V_35 . V_15 ) ) ;
V_4 -> V_35 . V_39 = V_339 ;
V_4 -> V_35 . V_37 = V_340 ;
V_4 -> V_47 . V_48 = V_341 ;
V_4 -> V_47 . V_27 = V_342 ;
V_4 -> V_47 . V_50 = 0 ;
memcpy ( V_4 -> V_9 . V_15 , V_343 ,
sizeof( V_4 -> V_9 . V_15 ) ) ;
V_4 -> V_165 . V_166 = V_344 ;
memcpy ( V_4 -> V_165 . V_15 , V_345 , sizeof( V_4 -> V_165 . V_15 ) ) ;
V_4 -> V_153 . V_160 = 1 ;
for ( V_10 = 0 ; V_10 < V_346 ; V_10 ++ )
V_4 -> V_153 . V_154 [ V_10 ] = V_347 ;
memcpy ( V_4 -> gamma . V_91 , V_348 , sizeof( V_4 -> gamma . V_91 ) ) ;
memcpy ( V_4 -> gamma . V_93 , V_348 , sizeof( V_4 -> gamma . V_93 ) ) ;
memcpy ( V_4 -> gamma . V_95 , V_348 , sizeof( V_4 -> gamma . V_95 ) ) ;
V_4 -> V_55 . V_57 = V_349 ;
V_4 -> V_55 . V_59 = V_350 ;
V_4 -> V_55 . V_61 = V_350 ;
V_4 -> V_55 . V_63 = V_350 ;
V_4 -> V_55 . V_65 = V_350 ;
V_4 -> V_90 . V_95 = V_351 ;
V_4 -> V_90 . V_93 = V_352 ;
V_4 -> V_90 . V_91 = V_353 ;
V_4 -> V_100 = V_354 ;
V_4 -> V_123 = V_355 ;
V_4 -> V_142 . V_147 = V_356 ;
V_4 -> V_142 . V_143 = V_357 ;
V_4 -> V_142 . V_149 = V_356 ;
V_4 -> V_142 . V_145 = V_357 ;
V_4 -> V_210 = V_239 | V_255
| V_256 | V_358
| V_359 | V_360
| V_361 | V_362
| V_363 | V_189
| V_186 ;
}
static unsigned int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_364 ) {
case V_365 :
return V_366 ;
case V_367 :
default:
return V_368 ;
case V_369 :
return V_370 ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_227 * V_228 ;
struct V_240 * V_241 ;
unsigned long V_183 ;
T_2 V_188 ;
T_2 V_185 ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_188 = F_33 ( V_2 , 0 , false ) ;
V_185 = V_2 -> V_4 . V_185 ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
V_241 = & V_2 -> V_242 [ V_243 ] ;
V_228 = F_63 ( V_241 -> V_252 ) ;
F_48 ( V_2 ) ;
F_42 ( V_2 , V_228 ) ;
F_43 ( V_2 , V_185 ) ;
if ( V_2 -> V_283 == V_371 )
F_44 ( V_2 , 0 ) ;
else
F_44 ( V_2 , F_64 ( V_241 -> V_229 , 0x20 ) *
V_228 -> V_372 ) ;
F_39 ( V_2 , V_188 , V_185 ) ;
V_241 = & V_2 -> V_242 [ V_373 ] ;
if ( V_2 -> V_374 & V_375 )
F_5 ( V_6 , V_12 , V_18 ,
V_376 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_376 ) ;
if ( V_2 -> V_374 & V_377 )
F_5 ( V_6 , V_12 , V_18 ,
V_378 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_378 ) ;
if ( V_2 -> V_374 & V_375 )
F_46 ( V_2 ,
F_64 ( V_241 -> V_229 , 0x10 ) * 2 ) ;
F_41 ( V_2 , 0 ) ;
F_40 ( V_2 , V_241 -> V_252 ) ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_34 ( V_2 , V_188 , false ) ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_2 -> V_283 == V_284 )
F_5 ( V_6 , V_12 , V_18 ,
V_379 ) ;
F_5 ( V_6 , V_12 , V_18 ,
V_380 | V_381 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_382 == V_383 &&
V_2 -> V_384 . V_385 & V_386 ) {
F_65 ( V_2 ) ;
F_67 ( & V_2 -> V_384 ) ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_269 * V_270 = F_49 ( & V_2 -> V_271 . V_272 ) ;
struct V_387 * V_388 ;
int V_389 = 0 ;
if ( V_2 -> V_283 == V_284 ) {
V_388 = F_69 ( & V_2 -> V_390 ) ;
if ( V_388 != NULL )
F_45 ( V_2 , V_388 -> V_391 ) ;
V_270 -> V_382 |= V_392 ;
}
if ( V_2 -> V_374 & V_375 ) {
V_388 = F_69 ( & V_2 -> V_384 ) ;
if ( V_388 != NULL ) {
F_47 ( V_2 , V_388 -> V_391 ) ;
V_389 = 1 ;
}
V_270 -> V_382 |= V_393 ;
}
switch ( V_2 -> V_382 ) {
case V_394 :
if ( F_70 ( V_270 ) )
F_71 ( V_270 ,
V_394 ) ;
break;
case V_383 :
if ( V_389 )
F_65 ( V_2 ) ;
break;
case V_395 :
default:
return;
}
}
void F_72 ( struct V_1 * V_2 )
{
unsigned long V_183 ;
T_2 V_188 ;
T_2 V_185 ;
if ( F_73 ( & V_2 -> V_396 , & V_2 -> V_397 ) )
return;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_35 ( V_2 ) ;
V_188 = F_33 ( V_2 , 0 , false ) ;
V_185 = V_2 -> V_4 . V_185 ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_39 ( V_2 , V_188 , V_185 ) ;
F_43 ( V_2 , V_185 ) ;
if ( V_2 -> V_283 == V_284 ||
V_2 -> V_374 & V_375 )
F_68 ( V_2 ) ;
else if ( V_2 -> V_382 == V_383 )
F_65 ( V_2 ) ;
F_30 ( & V_2 -> V_4 . V_184 , V_183 ) ;
F_34 ( V_2 , V_188 , false ) ;
F_31 ( & V_2 -> V_4 . V_184 , V_183 ) ;
}
static int F_74 ( struct V_398 * V_399 ,
struct V_387 * V_388 )
{
struct V_1 * V_2 = & V_399 -> V_6 -> V_297 ;
if ( V_399 -> type == V_400 )
F_45 ( V_2 , V_388 -> V_391 ) ;
if ( V_399 -> type == V_401 )
F_47 ( V_2 , V_388 -> V_391 ) ;
return 0 ;
}
static int F_75 ( struct V_402 * V_403 )
{
struct V_1 * V_2 =
F_76 ( V_403 -> V_404 , struct V_1 , V_405 ) ;
switch ( V_403 -> V_406 ) {
case V_407 :
F_32 ( V_2 , V_403 -> V_56 ) ;
break;
case V_408 :
F_29 ( V_2 , V_403 -> V_56 ) ;
break;
}
return 0 ;
}
static long F_77 ( struct V_409 * V_410 , unsigned int V_411 , void * V_412 )
{
struct V_1 * V_2 = F_78 ( V_410 ) ;
switch ( V_411 ) {
case V_413 :
return F_36 ( V_2 , V_412 ) ;
default:
return - V_414 ;
}
}
static int F_79 ( struct V_409 * V_410 , int V_17 )
{
struct V_1 * V_2 = F_78 ( V_410 ) ;
struct V_398 * V_384 = & V_2 -> V_384 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_415 * V_293 = F_80 ( V_2 ) ;
if ( V_2 -> V_382 == V_395 ) {
if ( V_17 == V_395 )
return 0 ;
F_81 ( V_6 , V_416 ) ;
F_62 ( V_2 ) ;
F_82 ( & V_2 -> V_397 , 0 ) ;
F_57 ( V_2 ) ;
}
switch ( V_17 ) {
case V_383 :
if ( V_2 -> V_374 & V_375 )
F_83 ( V_6 , V_417 ) ;
if ( V_384 -> V_385 & V_386 ||
! ( V_2 -> V_374 & V_375 ) )
F_65 ( V_2 ) ;
F_67 ( V_384 ) ;
break;
case V_394 :
if ( V_2 -> V_283 == V_284 )
F_83 ( V_6 , V_418 ) ;
if ( V_2 -> V_374 & V_375 )
F_83 ( V_6 , V_417 ) ;
F_65 ( V_2 ) ;
break;
case V_395 :
if ( F_84 ( & V_410 -> V_272 , & V_2 -> V_396 ,
& V_2 -> V_397 ) )
F_53 ( V_293 , L_4 , V_410 -> V_419 ) ;
F_85 ( V_6 , V_418 ) ;
F_85 ( V_6 , V_417 ) ;
F_86 ( V_6 , V_416 ) ;
F_67 ( V_384 ) ;
break;
}
V_2 -> V_382 = V_17 ;
return 0 ;
}
static struct V_240 *
F_87 ( struct V_1 * V_2 , struct V_420 * V_195 ,
unsigned int V_421 , enum V_422 V_423 )
{
if ( V_423 == V_424 )
return F_88 ( & V_2 -> V_271 , V_195 , V_421 ) ;
else
return & V_2 -> V_242 [ V_421 ] ;
}
static struct V_425 *
F_89 ( struct V_1 * V_2 , struct V_420 * V_195 ,
enum V_422 V_423 )
{
if ( V_423 == V_424 )
return F_90 ( & V_2 -> V_271 , V_195 , V_243 ) ;
else
return & V_2 -> V_245 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_420 * V_195 , unsigned int V_421 ,
struct V_240 * V_426 ,
enum V_422 V_423 )
{
T_2 V_212 ;
struct V_425 * V_245 ;
unsigned int V_10 ;
switch ( V_421 ) {
case V_243 :
if ( V_2 -> V_283 == V_284 ) {
V_426 -> V_229 = F_92 ( T_2 , V_426 -> V_229 , V_427 ,
F_61 ( V_2 ) ) ;
V_426 -> V_251 = F_92 ( T_2 , V_426 -> V_251 ,
V_428 ,
V_429 ) ;
}
V_426 -> V_430 = V_431 ;
for ( V_10 = 0 ; V_10 < F_37 ( V_432 ) ; V_10 ++ ) {
if ( V_426 -> V_252 == V_432 [ V_10 ] )
break;
}
if ( V_10 >= F_37 ( V_432 ) )
V_426 -> V_252 = V_433 ;
break;
case V_373 :
V_212 = V_426 -> V_252 ;
* V_426 = * F_87 ( V_2 , V_195 , V_243 , V_423 ) ;
switch ( V_212 ) {
case V_215 :
case V_217 :
V_426 -> V_252 = V_212 ;
break;
default:
V_426 -> V_252 = V_215 ;
break;
}
V_245 = F_89 ( V_2 , V_195 , V_423 ) ;
V_426 -> V_229 = V_245 -> V_229 ;
V_426 -> V_251 = V_245 -> V_251 ;
V_426 -> V_430 = V_434 ;
break;
}
V_426 -> V_435 = V_436 ;
}
static void F_93 ( struct V_1 * V_2 ,
const struct V_240 * V_437 ,
struct V_425 * V_245 )
{
unsigned int V_246 = V_438 ;
unsigned int V_439 = V_437 -> V_229 - V_440 ;
unsigned int V_249 = V_441 ;
unsigned int V_442 = V_437 -> V_251 - V_443 ;
if ( V_2 -> V_283 == V_371 ) {
V_246 += 2 ;
V_439 -= 2 ;
}
if ( V_437 -> V_252 != V_253 &&
V_437 -> V_252 != V_254 ) {
V_246 += 2 ;
V_439 -= 2 ;
V_249 += 2 ;
V_442 -= 2 ;
}
V_245 -> V_246 &= ~ 1 ;
V_245 -> V_249 &= ~ 1 ;
V_245 -> V_246 = F_92 ( T_2 , V_245 -> V_246 , V_246 , V_439 - V_444 ) ;
V_245 -> V_249 = F_92 ( T_2 , V_245 -> V_249 , V_249 , V_442 - V_445 ) ;
V_245 -> V_229 = F_92 ( T_2 , V_245 -> V_229 , V_444 ,
V_439 - V_245 -> V_246 ) ;
V_245 -> V_251 = F_92 ( T_2 , V_245 -> V_251 , V_445 ,
V_442 - V_245 -> V_249 ) ;
}
static int F_94 ( struct V_409 * V_410 ,
struct V_420 * V_195 ,
struct V_446 * V_252 )
{
switch ( V_252 -> V_421 ) {
case V_243 :
if ( V_252 -> V_447 >= F_37 ( V_432 ) )
return - V_448 ;
V_252 -> V_252 = V_432 [ V_252 -> V_447 ] ;
break;
case V_373 :
if ( V_252 -> V_447 >= F_37 ( V_449 ) )
return - V_448 ;
V_252 -> V_252 = V_449 [ V_252 -> V_447 ] ;
break;
default:
return - V_448 ;
}
return 0 ;
}
static int F_95 ( struct V_409 * V_410 ,
struct V_420 * V_195 ,
struct V_450 * V_451 )
{
struct V_1 * V_2 = F_78 ( V_410 ) ;
struct V_240 V_241 ;
if ( V_451 -> V_447 != 0 )
return - V_448 ;
V_241 . V_252 = V_451 -> V_252 ;
V_241 . V_229 = 1 ;
V_241 . V_251 = 1 ;
F_91 ( V_2 , V_195 , V_451 -> V_421 , & V_241 , V_451 -> V_423 ) ;
V_451 -> V_452 = V_241 . V_229 ;
V_451 -> V_453 = V_241 . V_251 ;
if ( V_241 . V_252 != V_451 -> V_252 )
return - V_448 ;
V_241 . V_252 = V_451 -> V_252 ;
V_241 . V_229 = - 1 ;
V_241 . V_251 = - 1 ;
F_91 ( V_2 , V_195 , V_451 -> V_421 , & V_241 , V_451 -> V_423 ) ;
V_451 -> V_454 = V_241 . V_229 ;
V_451 -> V_455 = V_241 . V_251 ;
return 0 ;
}
static int F_96 ( struct V_409 * V_410 ,
struct V_420 * V_195 ,
struct V_456 * V_457 )
{
struct V_1 * V_2 = F_78 ( V_410 ) ;
struct V_240 * V_241 ;
if ( V_457 -> V_421 != V_243 )
return - V_448 ;
switch ( V_457 -> V_458 ) {
case V_459 :
V_457 -> V_460 . V_246 = 0 ;
V_457 -> V_460 . V_249 = 0 ;
V_457 -> V_460 . V_229 = V_461 ;
V_457 -> V_460 . V_251 = V_461 ;
V_241 = F_87 ( V_2 , V_195 , V_243 ,
V_457 -> V_423 ) ;
F_93 ( V_2 , V_241 , & V_457 -> V_460 ) ;
break;
case V_462 :
V_457 -> V_460 = * F_89 ( V_2 , V_195 , V_457 -> V_423 ) ;
break;
default:
return - V_448 ;
}
return 0 ;
}
static int F_97 ( struct V_409 * V_410 ,
struct V_420 * V_195 ,
struct V_456 * V_457 )
{
struct V_1 * V_2 = F_78 ( V_410 ) ;
struct V_240 * V_241 ;
if ( V_457 -> V_458 != V_462 ||
V_457 -> V_421 != V_243 )
return - V_448 ;
if ( V_2 -> V_382 != V_395 )
return - V_463 ;
if ( V_457 -> V_183 & V_464 ) {
V_457 -> V_460 = * F_89 ( V_2 , V_195 , V_457 -> V_423 ) ;
return 0 ;
}
V_241 = F_87 ( V_2 , V_195 , V_243 , V_457 -> V_423 ) ;
F_93 ( V_2 , V_241 , & V_457 -> V_460 ) ;
* F_89 ( V_2 , V_195 , V_457 -> V_423 ) = V_457 -> V_460 ;
V_241 = F_87 ( V_2 , V_195 , V_373 , V_457 -> V_423 ) ;
F_91 ( V_2 , V_195 , V_373 , V_241 , V_457 -> V_423 ) ;
return 0 ;
}
static int F_98 ( struct V_409 * V_410 , struct V_420 * V_195 ,
struct V_465 * V_426 )
{
struct V_1 * V_2 = F_78 ( V_410 ) ;
struct V_240 * V_241 ;
V_241 = F_87 ( V_2 , V_195 , V_426 -> V_421 , V_426 -> V_423 ) ;
if ( V_241 == NULL )
return - V_448 ;
V_426 -> V_241 = * V_241 ;
return 0 ;
}
static int F_99 ( struct V_409 * V_410 , struct V_420 * V_195 ,
struct V_465 * V_426 )
{
struct V_1 * V_2 = F_78 ( V_410 ) ;
struct V_240 * V_241 ;
struct V_425 * V_245 ;
V_241 = F_87 ( V_2 , V_195 , V_426 -> V_421 , V_426 -> V_423 ) ;
if ( V_241 == NULL )
return - V_448 ;
F_91 ( V_2 , V_195 , V_426 -> V_421 , & V_426 -> V_241 , V_426 -> V_423 ) ;
* V_241 = V_426 -> V_241 ;
if ( V_426 -> V_421 == V_243 ) {
V_245 = F_89 ( V_2 , V_195 , V_426 -> V_423 ) ;
V_245 -> V_246 = 0 ;
V_245 -> V_249 = 0 ;
V_245 -> V_229 = V_426 -> V_241 . V_229 ;
V_245 -> V_251 = V_426 -> V_241 . V_251 ;
F_93 ( V_2 , & V_426 -> V_241 , V_245 ) ;
V_241 = F_87 ( V_2 , V_195 , V_373 ,
V_426 -> V_423 ) ;
F_91 ( V_2 , V_195 , V_373 , V_241 ,
V_426 -> V_423 ) ;
}
return 0 ;
}
static int F_100 ( struct V_409 * V_410 ,
struct V_466 * V_467 )
{
struct V_465 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_421 = V_243 ;
V_241 . V_423 = V_467 ? V_424 : V_468 ;
V_241 . V_241 . V_252 = V_433 ;
V_241 . V_241 . V_229 = 4096 ;
V_241 . V_241 . V_251 = 4096 ;
F_99 ( V_410 , V_467 ? V_467 -> V_421 : NULL , & V_241 ) ;
return 0 ;
}
static int F_101 ( struct V_469 * V_272 ,
const struct V_470 * V_471 ,
const struct V_470 * V_472 , T_2 V_183 )
{
struct V_409 * V_410 = F_102 ( V_272 ) ;
struct V_1 * V_2 = F_78 ( V_410 ) ;
unsigned int V_447 = V_471 -> V_447 ;
if ( F_103 ( V_472 -> V_272 ) )
V_447 |= 2 << 16 ;
switch ( V_447 ) {
case V_243 :
if ( V_183 & V_473 ) {
if ( V_2 -> V_283 == V_371 )
return - V_463 ;
V_2 -> V_283 = V_284 ;
} else {
if ( V_2 -> V_283 == V_284 )
V_2 -> V_283 = V_474 ;
}
break;
case V_243 | 2 << 16 :
if ( V_183 & V_473 ) {
if ( V_2 -> V_283 == V_284 )
return - V_463 ;
V_2 -> V_283 = V_371 ;
} else {
if ( V_2 -> V_283 == V_371 )
V_2 -> V_283 = V_474 ;
}
break;
case V_373 :
if ( V_183 & V_473 ) {
if ( V_2 -> V_374 & ~ V_375 )
return - V_463 ;
V_2 -> V_374 |= V_375 ;
} else {
V_2 -> V_374 &= ~ V_375 ;
}
break;
case V_373 | 2 << 16 :
if ( V_183 & V_473 ) {
if ( V_2 -> V_374 & ~ V_377 )
return - V_463 ;
V_2 -> V_374 |= V_377 ;
} else {
V_2 -> V_374 &= ~ V_377 ;
}
break;
default:
return - V_448 ;
}
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_271 ) ;
F_106 ( & V_2 -> V_390 ) ;
F_106 ( & V_2 -> V_384 ) ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_475 * V_476 )
{
int V_477 ;
V_477 = F_108 ( V_476 , & V_2 -> V_271 ) ;
if ( V_477 < 0 )
goto error;
V_477 = F_109 ( & V_2 -> V_390 , V_476 ) ;
if ( V_477 < 0 )
goto error;
V_477 = F_109 ( & V_2 -> V_384 , V_476 ) ;
if ( V_477 < 0 )
goto error;
return 0 ;
error:
F_104 ( V_2 ) ;
return V_477 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_409 * V_410 = & V_2 -> V_271 ;
struct V_470 * V_478 = V_2 -> V_478 ;
struct V_469 * V_479 = & V_410 -> V_272 ;
int V_477 ;
V_2 -> V_283 = V_474 ;
F_111 ( V_410 , & V_480 ) ;
V_410 -> V_481 = & V_482 ;
F_112 ( V_410 -> V_419 , L_5 , sizeof( V_410 -> V_419 ) ) ;
V_410 -> V_483 = 1 << 16 ;
F_113 ( V_410 , V_2 ) ;
V_410 -> V_183 |= V_484 ;
F_114 ( & V_2 -> V_405 , 2 ) ;
F_115 ( & V_2 -> V_405 , & V_485 , V_407 ,
V_486 , V_487 ,
V_488 , V_336 ) ;
F_115 ( & V_2 -> V_405 , & V_485 , V_408 ,
V_489 , V_490 ,
V_491 , V_335 ) ;
F_116 ( & V_2 -> V_405 ) ;
V_410 -> V_492 = & V_2 -> V_405 ;
V_478 [ V_243 ] . V_183 = V_493
| V_494 ;
V_478 [ V_373 ] . V_183 = V_495 ;
V_479 -> V_496 = & V_497 ;
V_477 = F_117 ( V_479 , V_498 , V_478 ) ;
if ( V_477 < 0 )
return V_477 ;
F_100 ( V_410 , NULL ) ;
V_2 -> V_390 . type = V_400 ;
V_2 -> V_390 . V_496 = & V_499 ;
V_2 -> V_390 . V_6 = F_2 ( V_2 ) ;
V_2 -> V_390 . V_500 = F_118 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_390 . V_501 = 64 ;
V_2 -> V_384 . type = V_401 ;
V_2 -> V_384 . V_496 = & V_499 ;
V_2 -> V_384 . V_6 = F_2 ( V_2 ) ;
V_2 -> V_384 . V_500 = F_118 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_384 . V_501 = 32 ;
V_477 = F_119 ( & V_2 -> V_390 , L_6 ) ;
if ( V_477 < 0 )
goto V_502;
V_477 = F_119 ( & V_2 -> V_384 , L_6 ) ;
if ( V_477 < 0 )
goto V_503;
return 0 ;
V_503:
F_120 ( & V_2 -> V_390 ) ;
V_502:
F_121 ( & V_2 -> V_271 . V_272 ) ;
return V_477 ;
}
int F_122 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_297 ;
F_123 ( & V_2 -> V_396 ) ;
F_59 ( V_2 ) ;
return F_110 ( V_2 ) ;
}
void F_124 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_297 ;
F_125 ( & V_2 -> V_405 ) ;
F_120 ( & V_2 -> V_390 ) ;
F_120 ( & V_2 -> V_384 ) ;
F_121 ( & V_2 -> V_271 . V_272 ) ;
}
