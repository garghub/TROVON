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
V_20 | V_21 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_20 | V_21 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_22 * V_23 = & V_4 -> V_23 ;
F_3 ( V_6 , ( V_23 -> V_24 == 1 ? 0 : V_25 ) |
( V_23 -> V_26 == 1 ? 0 : V_27 ) |
( V_23 -> V_28 << V_29 ) ,
V_12 , V_30 ) ;
}
static void F_9 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_31 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_31 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
static const unsigned int V_32 [ 4 ] [ 4 ] = {
{ 0 , 1 , 2 , 3 } ,
{ 1 , 0 , 3 , 2 } ,
{ 2 , 3 , 0 , 1 } ,
{ 3 , 2 , 1 , 0 } ,
} ;
const unsigned int * V_33 = V_32 [ V_2 -> V_4 . V_34 ] ;
const struct V_35 * V_36 = & V_4 -> V_36 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_10 ;
unsigned int V_37 ;
F_3 ( V_6 ,
( V_36 -> V_38 << V_39 ) |
( V_36 -> V_40 << V_41 ) ,
V_12 , V_42 ) ;
F_3 ( V_6 , V_43 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < 4 ; ++ V_10 ) {
const T_1 * V_44 = V_36 -> V_15 [ V_33 [ V_10 ] ] ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 )
F_3 ( V_6 , V_44 [ V_37 ] , V_12 ,
V_16 ) ;
}
}
static void
F_11 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_46 * V_47 = & V_4 -> V_48 ;
F_3 ( V_6 ,
V_47 -> V_49 | ( V_47 -> V_28 << V_50 ) |
( V_47 -> V_51 << V_52 ) ,
V_12 , V_53 ) ;
}
static void
F_12 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_54 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_54 ) ;
}
static void
F_13 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_55 * V_56 = & V_4 -> V_56 ;
T_2 V_57 ;
F_3 ( V_6 , V_56 -> V_58 , V_12 , V_59 ) ;
V_57 = V_56 -> V_60 << V_61 ;
V_57 |= V_56 -> V_62 << V_63 ;
V_57 |= V_56 -> V_64 << V_65 ;
V_57 |= V_56 -> V_66 << V_67 ;
F_3 ( V_6 , V_57 , V_12 , V_68 ) ;
F_3 ( V_6 ,
V_69 << V_70 |
V_71 << V_72 |
V_69 << V_73 |
V_71 << V_74 |
V_75 << V_76 |
V_77 << V_78 |
V_75 << V_79 |
V_77 << V_80 |
V_69 << V_81 |
V_71 << V_82 |
V_69 << V_83 |
V_71 << V_84 |
V_75 << V_85 |
V_77 << V_86 |
V_75 << V_87 |
V_77 << V_88 ,
V_12 , V_89 ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_90 * V_91 = & V_4 -> V_91 ;
F_3 ( V_6 , ( V_91 -> V_92 << V_93 ) |
( V_91 -> V_94 << V_95 ) |
( V_91 -> V_96 << V_97 ) ,
V_12 , V_98 ) ;
}
static void
F_15 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_99 * V_100 = & V_4 -> V_101 ;
T_2 V_57 ;
V_57 = ( V_100 -> V_102 [ 0 ] [ 0 ] & 0xfff ) << V_103 ;
V_57 |= ( V_100 -> V_102 [ 0 ] [ 1 ] & 0xfff ) << V_104 ;
F_3 ( V_6 , V_57 , V_12 , V_105 ) ;
V_57 = ( V_100 -> V_102 [ 0 ] [ 2 ] & 0xfff ) << V_106 ;
V_57 |= ( V_100 -> V_102 [ 1 ] [ 0 ] & 0xfff ) << V_107 ;
F_3 ( V_6 , V_57 , V_12 , V_108 ) ;
V_57 = ( V_100 -> V_102 [ 1 ] [ 1 ] & 0xfff ) << V_109 ;
V_57 |= ( V_100 -> V_102 [ 1 ] [ 2 ] & 0xfff ) << V_110 ;
F_3 ( V_6 , V_57 , V_12 , V_111 ) ;
V_57 = ( V_100 -> V_102 [ 2 ] [ 0 ] & 0xfff ) << V_112 ;
V_57 |= ( V_100 -> V_102 [ 2 ] [ 1 ] & 0xfff ) << V_113 ;
F_3 ( V_6 , V_57 , V_12 , V_114 ) ;
V_57 = ( V_100 -> V_102 [ 2 ] [ 2 ] & 0xfff ) << V_115 ;
F_3 ( V_6 , V_57 , V_12 , V_116 ) ;
V_57 = ( V_100 -> V_117 [ 0 ] & 0x3ff ) << V_118 ;
V_57 |= ( V_100 -> V_117 [ 1 ] & 0x3ff ) << V_119 ;
F_3 ( V_6 , V_57 , V_12 , V_120 ) ;
V_57 = ( V_100 -> V_117 [ 2 ] & 0x3ff ) << V_121 ;
F_3 ( V_6 , V_57 , V_12 , V_122 ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_123 * V_124 = & V_4 -> V_124 ;
T_2 V_57 ;
V_57 = ( V_124 -> V_102 [ 0 ] [ 0 ] & 0x3ff ) << V_125 ;
V_57 |= ( V_124 -> V_102 [ 0 ] [ 1 ] & 0x3ff ) << V_126 ;
V_57 |= ( V_124 -> V_102 [ 0 ] [ 2 ] & 0x3ff ) << V_127 ;
F_3 ( V_6 , V_57 , V_12 , V_128 ) ;
V_57 = ( V_124 -> V_102 [ 1 ] [ 0 ] & 0x3ff ) << V_129 ;
V_57 |= ( V_124 -> V_102 [ 1 ] [ 1 ] & 0x3ff ) << V_130 ;
V_57 |= ( V_124 -> V_102 [ 1 ] [ 2 ] & 0x3ff ) << V_131 ;
F_3 ( V_6 , V_57 , V_12 , V_132 ) ;
V_57 = ( V_124 -> V_102 [ 2 ] [ 0 ] & 0x3ff ) << V_133 ;
V_57 |= ( V_124 -> V_102 [ 2 ] [ 1 ] & 0x3ff ) << V_134 ;
V_57 |= ( V_124 -> V_102 [ 2 ] [ 2 ] & 0x3ff ) << V_135 ;
F_3 ( V_6 , V_57 , V_12 , V_136 ) ;
V_57 = ( V_124 -> V_117 [ 0 ] & 0xff ) << V_137 ;
V_57 |= ( V_124 -> V_117 [ 1 ] & 0xff ) << V_138 ;
V_57 |= ( V_124 -> V_117 [ 2 ] & 0xff ) << V_139 ;
F_3 ( V_6 , V_57 , V_12 , V_140 ) ;
}
static void
F_17 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_141 * V_142 = & V_4 -> V_143 ;
F_3 ( V_6 ,
V_142 -> V_144 << V_145 |
V_142 -> V_146 << V_147 |
V_142 -> V_148 << V_149 |
V_142 -> V_150 << V_151 ,
V_12 , V_152 ) ;
}
static void
F_18 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_153 * V_154 = & V_4 -> V_154 ;
F_3 ( V_6 , V_154 -> V_155 [ 0 ] ,
V_12 , V_156 ) ;
F_3 ( V_6 , V_154 -> V_155 [ 1 ] ,
V_12 , V_157 ) ;
F_3 ( V_6 , V_154 -> V_155 [ 2 ] ,
V_12 , V_158 ) ;
F_3 ( V_6 , V_154 -> V_155 [ 3 ] ,
V_12 , V_159 ) ;
F_19 ( V_6 , V_12 , V_18 ,
V_160 ,
V_154 -> V_161 ? V_160 : 0 ) ;
}
static void F_20 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_162 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_162 ) ;
}
static void
F_21 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_163 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_163 ) ;
}
static void F_22 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_164 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_164 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_165 * V_166 = & V_4 -> V_166 ;
unsigned int V_10 ;
F_3 ( V_6 , V_166 -> V_167 , V_12 , V_168 ) ;
F_3 ( V_6 , V_169 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_170 ; V_10 ++ ) {
F_3 ( V_6 , V_166 -> V_15 [ V_10 ] ,
V_12 , V_16 ) ;
}
}
static void
F_24 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_5 ( V_6 , V_12 , V_18 ,
V_171 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_171 ) ;
}
static void
F_25 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_172 * V_173 = & V_4 -> gamma ;
unsigned int V_10 ;
F_3 ( V_6 , V_174 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_175 ; V_10 ++ )
F_3 ( V_6 , V_173 -> V_96 [ V_10 ] , V_12 ,
V_16 ) ;
F_3 ( V_6 , V_176 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_175 ; V_10 ++ )
F_3 ( V_6 , V_173 -> V_94 [ V_10 ] , V_12 ,
V_16 ) ;
F_3 ( V_6 , V_177 ,
V_12 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_175 ; V_10 ++ )
F_3 ( V_6 , V_173 -> V_92 [ V_10 ] , V_12 ,
V_16 ) ;
}
static void
F_26 ( struct V_1 * V_2 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_17 )
F_6 ( V_6 , V_12 , V_18 ,
V_178 ) ;
else
F_5 ( V_6 , V_12 , V_18 ,
V_178 ) ;
}
static void
F_27 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_6 , V_12 , V_179 ,
0xff << V_180 ,
V_4 -> V_181 << V_180 ) ;
}
static void
F_28 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_6 , V_12 , V_179 ,
0xff << V_182 ,
V_4 -> V_183 << V_182 ) ;
}
static void
F_29 ( struct V_1 * V_2 , T_3 V_181 )
{
struct V_3 * V_4 ;
unsigned long V_184 ;
F_30 ( & V_2 -> V_4 . V_185 , V_184 ) ;
V_4 = ( V_2 -> V_4 . V_186 & V_187 )
? & V_2 -> V_4 . V_4 [ 0 ] : & V_2 -> V_4 . V_4 [ 1 ] ;
if ( V_4 -> V_181 != ( V_181 * V_188 ) ) {
V_4 -> V_181 = V_181 * V_188 ;
V_4 -> V_189 |= V_187 ;
}
F_31 ( & V_2 -> V_4 . V_185 , V_184 ) ;
}
static void
F_32 ( struct V_1 * V_2 , T_3 V_183 )
{
struct V_3 * V_4 ;
unsigned long V_184 ;
F_30 ( & V_2 -> V_4 . V_185 , V_184 ) ;
V_4 = ( V_2 -> V_4 . V_186 & V_190 )
? & V_2 -> V_4 . V_4 [ 0 ] : & V_2 -> V_4 . V_4 [ 1 ] ;
if ( V_4 -> V_183 != ( V_183 * V_191 ) ) {
V_4 -> V_183 = V_183 * V_191 ;
V_4 -> V_189 |= V_190 ;
}
F_31 ( & V_2 -> V_4 . V_185 , V_184 ) ;
}
static T_2
F_33 ( struct V_1 * V_2 , T_2 V_189 , bool V_192 )
{
T_2 V_186 = V_2 -> V_4 . V_186 ;
if ( V_192 ) {
V_2 -> V_4 . V_4 [ 0 ] . V_193 |= ~ V_186 & V_189 ;
V_2 -> V_4 . V_4 [ 1 ] . V_193 |= V_186 & V_189 ;
} else {
V_189 = ( V_2 -> V_4 . V_4 [ 0 ] . V_189 & V_186 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_189 & ~ V_186 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_193 |= V_186 & V_189 ;
V_2 -> V_4 . V_4 [ 1 ] . V_193 |= ~ V_186 & V_189 ;
}
return V_189 ;
}
static void
F_34 ( struct V_1 * V_2 , T_2 V_189 , bool V_192 )
{
T_2 V_186 = V_2 -> V_4 . V_186 ;
if ( V_192 ) {
V_2 -> V_4 . V_4 [ 0 ] . V_189 |= ( ~ V_186 & V_189 ) ;
V_2 -> V_4 . V_4 [ 1 ] . V_189 |= ( V_186 & V_189 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_193 &= V_186 ;
V_2 -> V_4 . V_4 [ 1 ] . V_193 &= ~ V_186 ;
} else {
V_2 -> V_4 . V_4 [ 0 ] . V_189 &= ~ ( V_186 & V_189 ) ;
V_2 -> V_4 . V_4 [ 1 ] . V_189 &= ~ ( ~ V_186 & V_189 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_193 &= ~ V_186 ;
V_2 -> V_4 . V_4 [ 1 ] . V_193 &= V_186 ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
T_2 V_194 ;
V_194 = ( V_2 -> V_4 . V_4 [ 0 ] . V_189 & ~ V_2 -> V_4 . V_186 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_189 & V_2 -> V_4 . V_186 ) ;
V_194 &= ~ ( V_2 -> V_4 . V_4 [ 0 ] . V_193 |
V_2 -> V_4 . V_4 [ 1 ] . V_193 ) ;
if ( V_194 == 0 )
return;
V_2 -> V_4 . V_186 ^= V_194 ;
V_2 -> V_4 . V_4 [ 0 ] . V_189 &= ~ ( ~ V_2 -> V_4 . V_186 & V_194 ) ;
V_2 -> V_4 . V_4 [ 1 ] . V_189 &= ~ ( V_2 -> V_4 . V_186 & V_194 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
unsigned long V_184 ;
unsigned int V_10 ;
int V_197 = 0 ;
T_2 V_189 ;
T_2 V_186 ;
if ( V_196 -> V_189 == 0 )
return 0 ;
F_30 ( & V_2 -> V_4 . V_185 , V_184 ) ;
F_33 ( V_2 , V_196 -> V_189 , true ) ;
V_186 = V_2 -> V_4 . V_186 ;
F_31 ( & V_2 -> V_4 . V_185 , V_184 ) ;
V_189 = 0 ;
for ( V_10 = 0 ; V_10 < F_37 ( V_198 ) ; V_10 ++ ) {
const struct V_199 * V_200 = & V_198 [ V_10 ] ;
struct V_3 * V_4 ;
unsigned int V_201 = 1 << V_10 ;
if ( V_200 -> V_202 || ! ( V_196 -> V_189 & V_201 ) )
continue;
V_4 = & V_2 -> V_4 . V_4 [ ! ! ( V_186 & V_201 ) ] ;
if ( V_196 -> V_203 & V_201 ) {
void T_4 * V_204 = * ( void * T_4 * )
( ( void * ) V_196 + V_200 -> V_205 ) ;
void * V_206 = ( void * ) V_4 + V_200 -> V_207 ;
T_5 V_208 = V_200 -> V_209 ;
if ( V_206 && V_204 && V_208 ) {
if ( F_38 ( V_206 , V_204 , V_208 ) ) {
V_197 = - V_210 ;
break;
}
}
V_4 -> V_211 |= V_201 ;
} else {
V_4 -> V_211 &= ~ V_201 ;
}
V_189 |= V_201 ;
}
F_30 ( & V_2 -> V_4 . V_185 , V_184 ) ;
F_34 ( V_2 , V_189 , true ) ;
F_35 ( V_2 ) ;
F_31 ( & V_2 -> V_4 . V_185 , V_184 ) ;
return V_197 ;
}
static void F_39 ( struct V_1 * V_2 , T_2 V_189 ,
T_2 V_186 )
{
unsigned int V_10 ;
T_2 V_211 ;
if ( V_189 == 0 )
return;
V_211 = ( V_2 -> V_4 . V_4 [ 0 ] . V_211 & V_186 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_211 & ~ V_186 ) ;
for ( V_10 = 0 ; V_10 < F_37 ( V_198 ) ; V_10 ++ ) {
const struct V_199 * V_200 = & V_198 [ V_10 ] ;
struct V_3 * V_4 ;
unsigned int V_201 = 1 << V_10 ;
if ( ! ( V_189 & V_201 ) )
continue;
V_4 = & V_2 -> V_4 . V_4 [ ! ( V_186 & V_201 ) ] ;
if ( V_4 -> V_211 & V_201 ) {
if ( V_200 -> V_212 )
V_200 -> V_212 ( V_2 , V_4 ) ;
if ( V_200 -> V_17 )
V_200 -> V_17 ( V_2 , true ) ;
} else {
if ( V_200 -> V_17 )
V_200 -> V_17 ( V_2 , false ) ;
}
}
}
static void
F_40 ( struct V_1 * V_2 ,
enum V_213 V_214 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
enum V_215 V_216 ;
switch ( V_214 ) {
case V_217 :
V_216 = V_218 ;
break;
case V_219 :
V_216 = V_220 ;
break;
default:
return;
}
F_19 ( V_6 , V_12 , V_18 ,
V_221 ,
V_216 << V_222 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_3 V_223 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_224 << V_225 |
V_226 << V_227 |
V_223 , V_12 , V_228 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_229 * V_230 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
switch ( V_230 -> V_231 ) {
case V_232 :
V_2 -> V_4 . V_34 = 0 ;
break;
case V_233 :
V_2 -> V_4 . V_34 = 1 ;
break;
case V_234 :
V_2 -> V_4 . V_34 = 2 ;
break;
case V_235 :
V_2 -> V_4 . V_34 = 3 ;
break;
default:
F_6 ( V_6 , V_12 , V_18 ,
V_236 ) ;
return;
}
F_5 ( V_6 , V_12 , V_18 , V_236 ) ;
F_19 ( V_6 , V_12 , V_18 ,
V_237 , V_238 ) ;
V_4 = ( V_2 -> V_4 . V_186 & V_239 )
? & V_2 -> V_4 . V_4 [ 0 ] : & V_2 -> V_4 . V_4 [ 1 ] ;
F_10 ( V_2 , V_4 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_2 V_186 )
{
const struct V_229 * V_230 = & V_2 -> V_240 [ V_241 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_242 = V_2 -> V_243 . V_244 ;
unsigned int V_245 = V_2 -> V_243 . V_244 + V_2 -> V_243 . V_246 - 1 ;
unsigned int V_247 = V_2 -> V_243 . V_248 ;
unsigned int V_249 = V_2 -> V_243 . V_248 + V_2 -> V_243 . V_250 - 1 ;
T_2 V_211 ;
if ( V_230 -> V_231 != V_251 ) {
V_242 -= 2 ;
V_245 += 2 ;
V_247 -= 2 ;
V_249 += 2 ;
}
V_211 = ( V_2 -> V_4 . V_4 [ 0 ] . V_211 & V_186 )
| ( V_2 -> V_4 . V_4 [ 1 ] . V_211 & ~ V_186 ) ;
if ( V_211 & ( V_252 | V_253 ) ) {
V_242 -= 2 ;
V_245 += 2 ;
V_247 -= 2 ;
V_249 += 2 ;
}
if ( V_211 & V_254 ) {
V_242 -= 2 ;
V_245 += 2 ;
}
if ( V_211 & ( V_255 | V_256 ) )
V_242 -= 2 ;
F_3 ( V_6 , ( V_242 << V_257 ) | V_245 ,
V_12 , V_258 ) ;
F_3 ( V_6 , ( V_247 << V_259 ) | V_249 ,
V_12 , V_260 ) ;
}
static void
F_44 ( struct V_1 * V_2 , T_2 V_117 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_117 & 0xffff , V_12 ,
V_261 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_2 V_262 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_262 , V_12 , V_263 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
T_2 V_117 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_117 & 0xffff , V_12 ,
V_264 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_2 V_262 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_262 , V_12 , V_265 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_266 * V_267 = F_49 ( & V_2 -> V_268 . V_269 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_229 * V_270 = & V_2 -> V_240 [ V_241 ] ;
unsigned long V_271 = V_267 -> V_271 ;
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
V_276 = F_50 ( ( V_285 ) V_271 / 2 * 256 + V_267 -> V_286 - 1 ,
V_267 -> V_286 ) ;
V_277 = F_51 ( V_276 , 32 ) ;
V_273 = & V_267 -> V_287 ;
V_275 = F_51 ( V_270 -> V_246 * 2 , 256 ) * V_270 -> V_250 ;
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
const T_2 V_189 = V_295 - 1 ;
V_2 -> V_4 . V_4 [ 0 ] . V_189 = V_2 -> V_4 . V_186 & V_189 ;
V_2 -> V_4 . V_4 [ 1 ] . V_189 = ~ V_2 -> V_4 . V_186 & V_189 ;
F_39 ( V_2 , V_189 , V_2 -> V_4 . V_186 ) ;
V_2 -> V_4 . V_4 [ 0 ] . V_189 = 0 ;
V_2 -> V_4 . V_4 [ 1 ] . V_189 = 0 ;
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
F_60 ( & V_2 -> V_4 . V_185 ) ;
V_2 -> V_4 . V_186 = ~ 0 ;
V_2 -> V_4 . V_4 [ 0 ] . V_193 = 0 ;
V_2 -> V_4 . V_4 [ 0 ] . V_189 = V_295 - 1 ;
V_2 -> V_4 . V_4 [ 1 ] . V_193 = 0 ;
V_2 -> V_4 . V_4 [ 1 ] . V_189 = 0 ;
V_4 = & V_2 -> V_4 . V_4 [ 0 ] ;
V_4 -> V_181 = V_332 * V_188 ;
V_4 -> V_183 = V_333 * V_191 ;
V_4 -> V_36 . V_230 = V_334 ;
memcpy ( V_4 -> V_36 . V_15 , V_335 ,
sizeof( V_4 -> V_36 . V_15 ) ) ;
V_4 -> V_36 . V_40 = V_336 ;
V_4 -> V_36 . V_38 = V_337 ;
V_4 -> V_48 . V_49 = V_338 ;
V_4 -> V_48 . V_28 = V_339 ;
V_4 -> V_48 . V_51 = 0 ;
memcpy ( V_4 -> V_9 . V_15 , V_340 ,
sizeof( V_4 -> V_9 . V_15 ) ) ;
V_4 -> V_166 . V_167 = V_341 ;
memcpy ( V_4 -> V_166 . V_15 , V_342 , sizeof( V_4 -> V_166 . V_15 ) ) ;
V_4 -> V_154 . V_161 = 1 ;
for ( V_10 = 0 ; V_10 < V_343 ; V_10 ++ )
V_4 -> V_154 . V_155 [ V_10 ] = V_344 ;
memcpy ( V_4 -> gamma . V_92 , V_345 , sizeof( V_4 -> gamma . V_92 ) ) ;
memcpy ( V_4 -> gamma . V_94 , V_345 , sizeof( V_4 -> gamma . V_94 ) ) ;
memcpy ( V_4 -> gamma . V_96 , V_345 , sizeof( V_4 -> gamma . V_96 ) ) ;
V_4 -> V_56 . V_58 = V_346 ;
V_4 -> V_56 . V_60 = V_347 ;
V_4 -> V_56 . V_62 = V_347 ;
V_4 -> V_56 . V_64 = V_347 ;
V_4 -> V_56 . V_66 = V_347 ;
V_4 -> V_91 . V_96 = V_348 ;
V_4 -> V_91 . V_94 = V_349 ;
V_4 -> V_91 . V_92 = V_350 ;
V_4 -> V_101 = V_351 ;
V_4 -> V_124 = V_352 ;
V_4 -> V_143 . V_148 = V_353 ;
V_4 -> V_143 . V_144 = V_354 ;
V_4 -> V_143 . V_150 = V_353 ;
V_4 -> V_143 . V_146 = V_354 ;
V_4 -> V_211 = V_239 | V_252
| V_253 | V_355
| V_356 | V_357
| V_358 | V_359
| V_360 | V_190
| V_187 ;
}
static unsigned int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_361 ) {
case V_362 :
return V_363 ;
case V_364 :
default:
return V_365 ;
case V_366 :
return V_367 ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_229 * V_230 ;
unsigned long V_184 ;
T_2 V_189 ;
T_2 V_186 ;
F_30 ( & V_2 -> V_4 . V_185 , V_184 ) ;
V_189 = F_33 ( V_2 , 0 , false ) ;
V_186 = V_2 -> V_4 . V_186 ;
F_31 ( & V_2 -> V_4 . V_185 , V_184 ) ;
V_230 = & V_2 -> V_240 [ V_241 ] ;
F_48 ( V_2 ) ;
F_42 ( V_2 , V_230 ) ;
F_43 ( V_2 , V_186 ) ;
if ( V_2 -> V_280 == V_368 )
F_44 ( V_2 , 0 ) ;
else
F_44 ( V_2 ,
F_63 ( V_230 -> V_246 , 0x20 ) * 2 ) ;
F_39 ( V_2 , V_189 , V_186 ) ;
V_230 = & V_2 -> V_240 [ V_369 ] ;
if ( V_2 -> V_370 & V_371 )
F_5 ( V_6 , V_12 , V_18 ,
V_372 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_372 ) ;
if ( V_2 -> V_370 & V_373 )
F_5 ( V_6 , V_12 , V_18 ,
V_374 ) ;
else
F_6 ( V_6 , V_12 , V_18 ,
V_374 ) ;
if ( V_2 -> V_370 & V_371 )
F_46 ( V_2 ,
F_63 ( V_230 -> V_246 , 0x10 ) * 2 ) ;
F_41 ( V_2 , 0 ) ;
F_40 ( V_2 , V_230 -> V_231 ) ;
F_30 ( & V_2 -> V_4 . V_185 , V_184 ) ;
F_34 ( V_2 , V_189 , false ) ;
F_31 ( & V_2 -> V_4 . V_185 , V_184 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_2 -> V_280 == V_281 )
F_5 ( V_6 , V_12 , V_18 ,
V_375 ) ;
F_5 ( V_6 , V_12 , V_18 ,
V_376 | V_377 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_378 == V_379 &&
V_2 -> V_380 . V_381 & V_382 ) {
F_64 ( V_2 ) ;
F_66 ( & V_2 -> V_380 ) ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_266 * V_267 = F_49 ( & V_2 -> V_268 . V_269 ) ;
struct V_383 * V_384 ;
int V_385 = 0 ;
if ( V_2 -> V_280 == V_281 ) {
V_384 = F_68 ( & V_2 -> V_386 ) ;
if ( V_384 != NULL )
F_45 ( V_2 , V_384 -> V_387 ) ;
V_267 -> V_378 |= V_388 ;
}
if ( V_2 -> V_370 & V_371 ) {
V_384 = F_68 ( & V_2 -> V_380 ) ;
if ( V_384 != NULL ) {
F_47 ( V_2 , V_384 -> V_387 ) ;
V_385 = 1 ;
}
V_267 -> V_378 |= V_389 ;
}
switch ( V_2 -> V_378 ) {
case V_390 :
if ( F_69 ( V_267 ) )
F_70 ( V_267 ,
V_390 ) ;
break;
case V_379 :
if ( V_385 )
F_64 ( V_2 ) ;
break;
case V_391 :
default:
return;
}
}
void F_71 ( struct V_1 * V_2 )
{
unsigned long V_184 ;
T_2 V_189 ;
T_2 V_186 ;
if ( F_72 ( & V_2 -> V_392 , & V_2 -> V_393 ) )
return;
F_30 ( & V_2 -> V_4 . V_185 , V_184 ) ;
F_35 ( V_2 ) ;
V_189 = F_33 ( V_2 , 0 , false ) ;
V_186 = V_2 -> V_4 . V_186 ;
F_31 ( & V_2 -> V_4 . V_185 , V_184 ) ;
F_39 ( V_2 , V_189 , V_186 ) ;
F_43 ( V_2 , V_186 ) ;
if ( V_2 -> V_280 == V_281 ||
V_2 -> V_370 & V_371 )
F_67 ( V_2 ) ;
else if ( V_2 -> V_378 == V_379 )
F_64 ( V_2 ) ;
F_30 ( & V_2 -> V_4 . V_185 , V_184 ) ;
F_34 ( V_2 , V_189 , false ) ;
F_31 ( & V_2 -> V_4 . V_185 , V_184 ) ;
}
static int F_73 ( struct V_394 * V_395 ,
struct V_383 * V_384 )
{
struct V_1 * V_2 = & V_395 -> V_6 -> V_294 ;
if ( V_395 -> type == V_396 )
F_45 ( V_2 , V_384 -> V_387 ) ;
if ( V_395 -> type == V_397 )
F_47 ( V_2 , V_384 -> V_387 ) ;
return 0 ;
}
static int F_74 ( struct V_398 * V_399 )
{
struct V_1 * V_2 =
F_75 ( V_399 -> V_400 , struct V_1 , V_401 ) ;
switch ( V_399 -> V_402 ) {
case V_403 :
F_32 ( V_2 , V_399 -> V_57 ) ;
break;
case V_404 :
F_29 ( V_2 , V_399 -> V_57 ) ;
break;
}
return 0 ;
}
static long F_76 ( struct V_405 * V_406 , unsigned int V_407 , void * V_408 )
{
struct V_1 * V_2 = F_77 ( V_406 ) ;
switch ( V_407 ) {
case V_409 :
return F_36 ( V_2 , V_408 ) ;
default:
return - V_410 ;
}
}
static int F_78 ( struct V_405 * V_406 , int V_17 )
{
struct V_1 * V_2 = F_77 ( V_406 ) ;
struct V_394 * V_380 = & V_2 -> V_380 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_411 * V_290 = F_79 ( V_2 ) ;
if ( V_2 -> V_378 == V_391 ) {
if ( V_17 == V_391 )
return 0 ;
F_80 ( V_6 , V_412 ) ;
F_62 ( V_2 ) ;
F_81 ( & V_2 -> V_393 , 0 ) ;
F_57 ( V_2 ) ;
}
switch ( V_17 ) {
case V_379 :
if ( V_2 -> V_370 & V_371 )
F_82 ( V_6 , V_413 ) ;
if ( V_380 -> V_381 & V_382 ||
! ( V_2 -> V_370 & V_371 ) )
F_64 ( V_2 ) ;
F_66 ( V_380 ) ;
break;
case V_390 :
if ( V_2 -> V_280 == V_281 )
F_82 ( V_6 , V_414 ) ;
if ( V_2 -> V_370 & V_371 )
F_82 ( V_6 , V_413 ) ;
F_64 ( V_2 ) ;
break;
case V_391 :
if ( F_83 ( & V_406 -> V_269 , & V_2 -> V_392 ,
& V_2 -> V_393 ) )
F_53 ( V_290 , L_4 , V_406 -> V_415 ) ;
F_84 ( V_6 , V_414 ) ;
F_84 ( V_6 , V_413 ) ;
F_85 ( V_6 , V_412 ) ;
F_66 ( V_380 ) ;
break;
}
V_2 -> V_378 = V_17 ;
return 0 ;
}
static struct V_229 *
F_86 ( struct V_1 * V_2 , struct V_416 * V_417 ,
unsigned int V_418 , enum V_419 V_420 )
{
if ( V_420 == V_421 )
return F_87 ( V_417 , V_418 ) ;
else
return & V_2 -> V_240 [ V_418 ] ;
}
static struct V_422 *
F_88 ( struct V_1 * V_2 , struct V_416 * V_417 ,
enum V_419 V_420 )
{
if ( V_420 == V_421 )
return F_89 ( V_417 , V_241 ) ;
else
return & V_2 -> V_243 ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_416 * V_417 , unsigned int V_418 ,
struct V_229 * V_423 ,
enum V_419 V_420 )
{
enum V_213 V_214 ;
struct V_422 * V_243 ;
unsigned int V_10 ;
switch ( V_418 ) {
case V_241 :
if ( V_2 -> V_280 == V_281 ) {
V_423 -> V_246 = F_91 ( T_2 , V_423 -> V_246 , V_424 ,
F_61 ( V_2 ) ) ;
V_423 -> V_250 = F_91 ( T_2 , V_423 -> V_250 ,
V_425 ,
V_426 ) ;
}
V_423 -> V_427 = V_428 ;
for ( V_10 = 0 ; V_10 < F_37 ( V_429 ) ; V_10 ++ ) {
if ( V_423 -> V_231 == V_429 [ V_10 ] )
break;
}
if ( V_10 >= F_37 ( V_429 ) )
V_423 -> V_231 = V_232 ;
break;
case V_369 :
V_214 = V_423 -> V_231 ;
* V_423 = * F_86 ( V_2 , V_417 , V_241 , V_420 ) ;
switch ( V_214 ) {
case V_217 :
case V_219 :
V_423 -> V_231 = V_214 ;
break;
default:
V_423 -> V_231 = V_217 ;
break;
}
V_243 = F_88 ( V_2 , V_417 , V_420 ) ;
V_423 -> V_246 = V_243 -> V_246 ;
V_423 -> V_250 = V_243 -> V_250 ;
V_423 -> V_427 = V_430 ;
break;
}
V_423 -> V_431 = V_432 ;
}
static void F_92 ( struct V_1 * V_2 ,
const struct V_229 * V_433 ,
struct V_422 * V_243 )
{
unsigned int V_244 = V_434 ;
unsigned int V_435 = V_433 -> V_246 - V_436 ;
unsigned int V_248 = V_437 ;
unsigned int V_438 = V_433 -> V_250 - V_439 ;
if ( V_2 -> V_280 == V_368 ) {
V_244 += 2 ;
V_435 -= 2 ;
}
V_243 -> V_244 &= ~ 1 ;
V_243 -> V_248 &= ~ 1 ;
V_243 -> V_244 = F_91 ( T_2 , V_243 -> V_244 , V_244 , V_435 - V_440 ) ;
V_243 -> V_248 = F_91 ( T_2 , V_243 -> V_248 , V_248 , V_438 - V_441 ) ;
V_243 -> V_246 = F_91 ( T_2 , V_243 -> V_246 , V_440 ,
V_435 - V_243 -> V_244 ) ;
V_243 -> V_250 = F_91 ( T_2 , V_243 -> V_250 , V_441 ,
V_438 - V_243 -> V_248 ) ;
}
static int F_93 ( struct V_405 * V_406 ,
struct V_416 * V_417 ,
struct V_442 * V_231 )
{
switch ( V_231 -> V_418 ) {
case V_241 :
if ( V_231 -> V_443 >= F_37 ( V_429 ) )
return - V_444 ;
V_231 -> V_231 = V_429 [ V_231 -> V_443 ] ;
break;
case V_369 :
if ( V_231 -> V_443 >= F_37 ( V_445 ) )
return - V_444 ;
V_231 -> V_231 = V_445 [ V_231 -> V_443 ] ;
break;
default:
return - V_444 ;
}
return 0 ;
}
static int F_94 ( struct V_405 * V_406 ,
struct V_416 * V_417 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = F_77 ( V_406 ) ;
struct V_229 V_230 ;
if ( V_447 -> V_443 != 0 )
return - V_444 ;
V_230 . V_231 = V_447 -> V_231 ;
V_230 . V_246 = 1 ;
V_230 . V_250 = 1 ;
F_90 ( V_2 , V_417 , V_447 -> V_418 , & V_230 , V_421 ) ;
V_447 -> V_448 = V_230 . V_246 ;
V_447 -> V_449 = V_230 . V_250 ;
if ( V_230 . V_231 != V_447 -> V_231 )
return - V_444 ;
V_230 . V_231 = V_447 -> V_231 ;
V_230 . V_246 = - 1 ;
V_230 . V_250 = - 1 ;
F_90 ( V_2 , V_417 , V_447 -> V_418 , & V_230 , V_421 ) ;
V_447 -> V_450 = V_230 . V_246 ;
V_447 -> V_451 = V_230 . V_250 ;
return 0 ;
}
static int F_95 ( struct V_405 * V_406 ,
struct V_416 * V_417 ,
struct V_452 * V_453 )
{
struct V_1 * V_2 = F_77 ( V_406 ) ;
struct V_229 * V_230 ;
if ( V_453 -> V_418 != V_241 )
return - V_444 ;
switch ( V_453 -> V_454 ) {
case V_455 :
V_453 -> V_456 . V_244 = 0 ;
V_453 -> V_456 . V_248 = 0 ;
V_453 -> V_456 . V_246 = V_457 ;
V_453 -> V_456 . V_250 = V_457 ;
V_230 = F_86 ( V_2 , V_417 , V_241 ,
V_453 -> V_420 ) ;
F_92 ( V_2 , V_230 , & V_453 -> V_456 ) ;
break;
case V_458 :
V_453 -> V_456 = * F_88 ( V_2 , V_417 , V_453 -> V_420 ) ;
break;
default:
return - V_444 ;
}
return 0 ;
}
static int F_96 ( struct V_405 * V_406 ,
struct V_416 * V_417 ,
struct V_452 * V_453 )
{
struct V_1 * V_2 = F_77 ( V_406 ) ;
struct V_229 * V_230 ;
if ( V_453 -> V_454 != V_458 ||
V_453 -> V_418 != V_241 )
return - V_444 ;
if ( V_2 -> V_378 != V_391 )
return - V_459 ;
if ( V_453 -> V_184 & V_460 ) {
V_453 -> V_456 = * F_88 ( V_2 , V_417 , V_453 -> V_420 ) ;
return 0 ;
}
V_230 = F_86 ( V_2 , V_417 , V_241 , V_453 -> V_420 ) ;
F_92 ( V_2 , V_230 , & V_453 -> V_456 ) ;
* F_88 ( V_2 , V_417 , V_453 -> V_420 ) = V_453 -> V_456 ;
V_230 = F_86 ( V_2 , V_417 , V_369 , V_453 -> V_420 ) ;
F_90 ( V_2 , V_417 , V_369 , V_230 , V_453 -> V_420 ) ;
return 0 ;
}
static int F_97 ( struct V_405 * V_406 , struct V_416 * V_417 ,
struct V_461 * V_423 )
{
struct V_1 * V_2 = F_77 ( V_406 ) ;
struct V_229 * V_230 ;
V_230 = F_86 ( V_2 , V_417 , V_423 -> V_418 , V_423 -> V_420 ) ;
if ( V_230 == NULL )
return - V_444 ;
V_423 -> V_230 = * V_230 ;
return 0 ;
}
static int F_98 ( struct V_405 * V_406 , struct V_416 * V_417 ,
struct V_461 * V_423 )
{
struct V_1 * V_2 = F_77 ( V_406 ) ;
struct V_229 * V_230 ;
struct V_422 * V_243 ;
V_230 = F_86 ( V_2 , V_417 , V_423 -> V_418 , V_423 -> V_420 ) ;
if ( V_230 == NULL )
return - V_444 ;
F_90 ( V_2 , V_417 , V_423 -> V_418 , & V_423 -> V_230 , V_423 -> V_420 ) ;
* V_230 = V_423 -> V_230 ;
if ( V_423 -> V_418 == V_241 ) {
V_243 = F_88 ( V_2 , V_417 , V_423 -> V_420 ) ;
V_243 -> V_244 = 0 ;
V_243 -> V_248 = 0 ;
V_243 -> V_246 = V_423 -> V_230 . V_246 ;
V_243 -> V_250 = V_423 -> V_230 . V_250 ;
F_92 ( V_2 , & V_423 -> V_230 , V_243 ) ;
V_230 = F_86 ( V_2 , V_417 , V_369 ,
V_423 -> V_420 ) ;
F_90 ( V_2 , V_417 , V_369 , V_230 ,
V_423 -> V_420 ) ;
}
return 0 ;
}
static int F_99 ( struct V_405 * V_406 ,
struct V_416 * V_417 )
{
struct V_461 V_230 ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
V_230 . V_418 = V_241 ;
V_230 . V_420 = V_417 ? V_421 : V_462 ;
V_230 . V_230 . V_231 = V_232 ;
V_230 . V_230 . V_246 = 4096 ;
V_230 . V_230 . V_250 = 4096 ;
F_98 ( V_406 , V_417 , & V_230 ) ;
return 0 ;
}
static int F_100 ( struct V_463 * V_269 ,
const struct V_464 * V_465 ,
const struct V_464 * V_466 , T_2 V_184 )
{
struct V_405 * V_406 = F_101 ( V_269 ) ;
struct V_1 * V_2 = F_77 ( V_406 ) ;
switch ( V_465 -> V_443 | F_102 ( V_466 -> V_269 ) ) {
case V_241 | V_467 :
if ( V_184 & V_468 ) {
if ( V_2 -> V_280 == V_368 )
return - V_459 ;
V_2 -> V_280 = V_281 ;
} else {
if ( V_2 -> V_280 == V_281 )
V_2 -> V_280 = V_469 ;
}
break;
case V_241 | V_470 :
if ( V_184 & V_468 ) {
if ( V_2 -> V_280 == V_281 )
return - V_459 ;
V_2 -> V_280 = V_368 ;
} else {
if ( V_2 -> V_280 == V_368 )
V_2 -> V_280 = V_469 ;
}
break;
case V_369 | V_467 :
if ( V_184 & V_468 ) {
if ( V_2 -> V_370 & ~ V_371 )
return - V_459 ;
V_2 -> V_370 |= V_371 ;
} else {
V_2 -> V_370 &= ~ V_371 ;
}
break;
case V_369 | V_470 :
if ( V_184 & V_468 ) {
if ( V_2 -> V_370 & ~ V_373 )
return - V_459 ;
V_2 -> V_370 |= V_373 ;
} else {
V_2 -> V_370 &= ~ V_373 ;
}
break;
default:
return - V_444 ;
}
return 0 ;
}
void F_103 ( struct V_1 * V_2 )
{
F_104 ( & V_2 -> V_268 ) ;
F_105 ( & V_2 -> V_386 ) ;
F_105 ( & V_2 -> V_380 ) ;
}
int F_106 ( struct V_1 * V_2 ,
struct V_471 * V_472 )
{
int V_473 ;
V_473 = F_107 ( V_472 , & V_2 -> V_268 ) ;
if ( V_473 < 0 )
goto error;
V_473 = F_108 ( & V_2 -> V_386 , V_472 ) ;
if ( V_473 < 0 )
goto error;
V_473 = F_108 ( & V_2 -> V_380 , V_472 ) ;
if ( V_473 < 0 )
goto error;
return 0 ;
error:
F_103 ( V_2 ) ;
return V_473 ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_405 * V_406 = & V_2 -> V_268 ;
struct V_464 * V_474 = V_2 -> V_474 ;
struct V_463 * V_475 = & V_406 -> V_269 ;
int V_473 ;
V_2 -> V_280 = V_469 ;
F_110 ( V_406 , & V_476 ) ;
V_406 -> V_477 = & V_478 ;
F_111 ( V_406 -> V_415 , L_5 , sizeof( V_406 -> V_415 ) ) ;
V_406 -> V_479 = 1 << 16 ;
F_112 ( V_406 , V_2 ) ;
V_406 -> V_184 |= V_480 ;
F_113 ( & V_2 -> V_401 , 2 ) ;
F_114 ( & V_2 -> V_401 , & V_481 , V_403 ,
V_482 , V_483 ,
V_484 , V_333 ) ;
F_114 ( & V_2 -> V_401 , & V_481 , V_404 ,
V_485 , V_486 ,
V_487 , V_332 ) ;
F_115 ( & V_2 -> V_401 ) ;
V_406 -> V_488 = & V_2 -> V_401 ;
V_474 [ V_241 ] . V_184 = V_489 ;
V_474 [ V_369 ] . V_184 = V_490 ;
V_475 -> V_491 = & V_492 ;
V_473 = F_116 ( V_475 , V_493 , V_474 , 0 ) ;
if ( V_473 < 0 )
return V_473 ;
F_99 ( V_406 , NULL ) ;
V_2 -> V_386 . type = V_396 ;
V_2 -> V_386 . V_491 = & V_494 ;
V_2 -> V_386 . V_6 = F_2 ( V_2 ) ;
V_2 -> V_386 . V_495 = F_117 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_386 . V_496 = 64 ;
V_2 -> V_380 . type = V_397 ;
V_2 -> V_380 . V_491 = & V_494 ;
V_2 -> V_380 . V_6 = F_2 ( V_2 ) ;
V_2 -> V_380 . V_495 = F_117 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_380 . V_496 = 32 ;
V_473 = F_118 ( & V_2 -> V_386 , L_6 ) ;
if ( V_473 < 0 )
goto V_497;
V_473 = F_118 ( & V_2 -> V_380 , L_6 ) ;
if ( V_473 < 0 )
goto V_498;
V_473 = F_119 ( & V_2 -> V_386 . V_395 . V_269 , 0 ,
& V_2 -> V_268 . V_269 , V_241 , 0 ) ;
if ( V_473 < 0 )
goto V_499;
V_473 = F_119 ( & V_2 -> V_268 . V_269 , V_369 ,
& V_2 -> V_380 . V_395 . V_269 , 0 , 0 ) ;
if ( V_473 < 0 )
goto V_499;
return 0 ;
V_499:
F_120 ( & V_2 -> V_380 ) ;
V_498:
F_120 ( & V_2 -> V_386 ) ;
V_497:
F_121 ( & V_2 -> V_268 . V_269 ) ;
return V_473 ;
}
int F_122 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_294 ;
F_123 ( & V_2 -> V_392 ) ;
F_59 ( V_2 ) ;
return F_109 ( V_2 ) ;
}
void F_124 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_294 ;
F_125 ( & V_2 -> V_401 ) ;
F_120 ( & V_2 -> V_386 ) ;
F_120 ( & V_2 -> V_380 ) ;
F_121 ( & V_2 -> V_268 . V_269 ) ;
}
