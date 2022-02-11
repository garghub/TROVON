static inline void F_1 ( void )
{
#undef V_1
#define V_1 ( T_1 , T_2 ) \
BUILD_BUG_ON(ARRAY_SIZE(b43_ntab_##table) != B43_NTAB_##size##_SIZE)
V_1 ( V_2 , V_3 ) ;
V_1 ( V_4 , V_5 ) ;
V_1 ( V_6 , V_7 ) ;
V_1 ( V_8 , V_9 ) ;
V_1 ( V_10 , V_11 ) ;
V_1 ( V_12 , V_13 ) ;
V_1 ( V_14 , V_15 ) ;
V_1 ( V_16 , V_17 ) ;
V_1 ( V_18 , V_19 ) ;
V_1 ( V_20 , V_21 ) ;
V_1 ( V_22 , V_23 ) ;
V_1 ( V_24 , V_25 ) ;
V_1 ( V_26 , V_27 ) ;
V_1 ( V_28 , V_29 ) ;
V_1 ( V_30 , V_31 ) ;
V_1 ( V_32 , V_33 ) ;
V_1 ( V_34 , V_35 ) ;
V_1 ( V_36 , V_37 ) ;
V_1 ( V_38 , V_39 ) ;
V_1 ( V_40 , V_41 ) ;
V_1 ( V_42 , V_43 ) ;
V_1 ( V_44 , V_45 ) ;
V_1 ( V_46 , V_47 ) ;
V_1 ( V_48 , V_49 ) ;
V_1 ( V_50 , V_51 ) ;
V_1 ( V_52 , V_53 ) ;
#undef V_1
}
T_3 F_2 ( struct V_54 * V_55 , T_3 V_56 )
{
T_3 type , V_57 ;
type = V_56 & V_58 ;
V_56 &= ~ V_58 ;
F_3 ( V_56 > 0xFFFF ) ;
switch ( type ) {
case V_59 :
F_4 ( V_55 , V_60 , V_56 ) ;
V_57 = F_5 ( V_55 , V_61 ) & 0xFF ;
break;
case V_62 :
F_4 ( V_55 , V_60 , V_56 ) ;
V_57 = F_5 ( V_55 , V_61 ) ;
break;
case V_63 :
F_4 ( V_55 , V_60 , V_56 ) ;
V_57 = F_5 ( V_55 , V_61 ) ;
V_57 |= F_5 ( V_55 , V_64 ) << 16 ;
break;
default:
F_3 ( 1 ) ;
V_57 = 0 ;
}
return V_57 ;
}
void F_6 ( struct V_54 * V_55 , T_3 V_56 ,
unsigned int V_65 , void * V_66 )
{
T_3 type ;
T_4 * V_67 = V_66 ;
unsigned int V_68 ;
type = V_56 & V_58 ;
V_56 &= ~ V_58 ;
F_3 ( V_56 > 0xFFFF ) ;
F_4 ( V_55 , V_60 , V_56 ) ;
for ( V_68 = 0 ; V_68 < V_65 ; V_68 ++ ) {
if ( V_55 -> V_55 -> V_69 == 43224 && V_55 -> V_55 -> V_70 == 1 ) {
F_5 ( V_55 , V_61 ) ;
F_4 ( V_55 , V_60 , V_56 + V_68 ) ;
}
switch ( type ) {
case V_59 :
* V_67 = F_5 ( V_55 , V_61 ) & 0xFF ;
V_67 ++ ;
break;
case V_62 :
* ( ( V_71 * ) V_67 ) = F_5 ( V_55 , V_61 ) ;
V_67 += 2 ;
break;
case V_63 :
* ( ( T_3 * ) V_67 ) =
F_5 ( V_55 , V_61 ) ;
* ( ( T_3 * ) V_67 ) |=
F_5 ( V_55 , V_64 ) << 16 ;
V_67 += 4 ;
break;
default:
F_3 ( 1 ) ;
}
}
}
void F_7 ( struct V_54 * V_55 , T_3 V_56 , T_3 V_57 )
{
T_3 type ;
type = V_56 & V_58 ;
V_56 &= 0xFFFF ;
switch ( type ) {
case V_59 :
F_3 ( V_57 & ~ 0xFF ) ;
F_4 ( V_55 , V_60 , V_56 ) ;
F_4 ( V_55 , V_61 , V_57 ) ;
break;
case V_62 :
F_3 ( V_57 & ~ 0xFFFF ) ;
F_4 ( V_55 , V_60 , V_56 ) ;
F_4 ( V_55 , V_61 , V_57 ) ;
break;
case V_63 :
F_4 ( V_55 , V_60 , V_56 ) ;
F_4 ( V_55 , V_64 , V_57 >> 16 ) ;
F_4 ( V_55 , V_61 , V_57 & 0xFFFF ) ;
break;
default:
F_3 ( 1 ) ;
}
return;
F_1 () ;
}
void F_8 ( struct V_54 * V_55 , T_3 V_56 ,
unsigned int V_65 , const void * V_66 )
{
T_3 type , V_57 ;
const T_4 * V_67 = V_66 ;
unsigned int V_68 ;
type = V_56 & V_58 ;
V_56 &= ~ V_58 ;
F_3 ( V_56 > 0xFFFF ) ;
F_4 ( V_55 , V_60 , V_56 ) ;
for ( V_68 = 0 ; V_68 < V_65 ; V_68 ++ ) {
if ( ( V_56 >> 10 ) == 9 && V_55 -> V_55 -> V_69 == 43224 &&
V_55 -> V_55 -> V_70 == 1 ) {
F_5 ( V_55 , V_61 ) ;
F_4 ( V_55 , V_60 , V_56 + V_68 ) ;
}
switch ( type ) {
case V_59 :
V_57 = * V_67 ;
V_67 ++ ;
F_3 ( V_57 & ~ 0xFF ) ;
F_4 ( V_55 , V_61 , V_57 ) ;
break;
case V_62 :
V_57 = * ( ( V_71 * ) V_67 ) ;
V_67 += 2 ;
F_3 ( V_57 & ~ 0xFFFF ) ;
F_4 ( V_55 , V_61 , V_57 ) ;
break;
case V_63 :
V_57 = * ( ( T_3 * ) V_67 ) ;
V_67 += 4 ;
F_4 ( V_55 , V_64 , V_57 >> 16 ) ;
F_4 ( V_55 , V_61 ,
V_57 & 0xFFFF ) ;
break;
default:
F_3 ( 1 ) ;
}
}
}
static void F_9 ( struct V_54 * V_55 )
{
F_10 ( V_55 , V_72 , V_73 ) ;
F_10 ( V_55 , V_74 , V_75 ) ;
F_10 ( V_55 , V_76 , V_77 ) ;
F_10 ( V_55 , V_78 , V_79 ) ;
F_10 ( V_55 , V_80 , V_81 ) ;
F_10 ( V_55 , V_82 , V_83 ) ;
F_10 ( V_55 , V_84 , V_85 ) ;
F_10 ( V_55 , V_86 , V_87 ) ;
F_10 ( V_55 , V_88 , V_89 ) ;
F_10 ( V_55 , V_90 , V_91 ) ;
}
static void F_11 ( struct V_54 * V_55 )
{
struct V_92 * V_93 = V_55 -> V_55 -> V_94 ;
T_4 V_95 ;
int V_96 , V_56 , V_68 ;
const int V_97 [] = { 0 , 4 , 8 , } ;
const T_4 V_98 [] [ 3 ] = {
{ 0x2 , 0x12 , 0x8 } ,
{ 0x2 , 0x18 , 0x2 } ,
} ;
if ( F_12 ( V_55 -> V_99 ) == V_100 )
V_95 = V_93 -> V_101 . V_102 . V_95 ;
else
V_95 = V_93 -> V_101 . V_103 . V_95 ;
switch ( V_95 ) {
case 0 :
for ( V_96 = 0 ; V_96 < 2 ; V_96 ++ ) {
for ( V_68 = 0 ; V_68 < F_13 ( V_98 [ 0 ] ) ; V_68 ++ ) {
V_56 = V_96 ? 0x20 : 0x00 ;
V_56 += V_97 [ V_68 ] ;
F_7 ( V_55 , F_14 ( 9 , V_56 ) ,
V_98 [ V_96 ] [ V_68 ] ) ;
}
}
break;
default:
F_15 ( V_55 -> V_99 , L_1 , V_95 ) ;
break;
}
}
static void F_16 ( struct V_54 * V_55 )
{
if ( V_55 -> V_104 . V_105 ) {
F_10 ( V_55 , V_106 , V_107 ) ;
F_9 ( V_55 ) ;
}
F_11 ( V_55 ) ;
}
static void F_17 ( struct V_54 * V_55 )
{
if ( V_55 -> V_104 . V_105 ) {
F_10 ( V_55 , V_108 , V_109 ) ;
F_10 ( V_55 , V_110 , V_111 ) ;
F_10 ( V_55 , V_112 , V_113 ) ;
F_10 ( V_55 , V_114 , V_115 ) ;
F_10 ( V_55 , V_116 , V_117 ) ;
F_10 ( V_55 , V_106 , V_107 ) ;
F_10 ( V_55 , V_118 , V_119 ) ;
F_10 ( V_55 , V_120 , V_121 ) ;
F_10 ( V_55 , V_122 , V_123 ) ;
F_10 ( V_55 , V_124 , V_125 ) ;
F_10 ( V_55 , V_126 , V_127 ) ;
F_10 ( V_55 , V_128 , V_129 ) ;
F_10 ( V_55 , V_130 , V_131 ) ;
F_10 ( V_55 , V_132 , V_133 ) ;
F_9 ( V_55 ) ;
}
F_11 ( V_55 ) ;
}
static void F_18 ( struct V_54 * V_55 )
{
struct V_92 * V_93 = V_55 -> V_55 -> V_94 ;
T_4 V_95 ;
if ( F_12 ( V_55 -> V_99 ) == V_100 )
V_95 = V_93 -> V_101 . V_102 . V_95 ;
else
V_95 = V_93 -> V_101 . V_103 . V_95 ;
if ( V_55 -> V_104 . V_105 ) {
F_10 ( V_55 , V_108 , V_109 ) ;
F_10 ( V_55 , V_110 , V_111 ) ;
F_10 ( V_55 , V_134 , V_135 ) ;
F_10 ( V_55 , V_114 , V_115 ) ;
F_10 ( V_55 , V_116 , V_117 ) ;
F_10 ( V_55 , V_136 , V_137 ) ;
F_10 ( V_55 , V_118 , V_119 ) ;
F_10 ( V_55 , V_120 , V_121 ) ;
F_10 ( V_55 , V_122 , V_123 ) ;
F_10 ( V_55 , V_124 , V_125 ) ;
F_10 ( V_55 , V_126 , V_127 ) ;
F_10 ( V_55 , V_128 , V_129 ) ;
F_10 ( V_55 , V_130 , V_131 ) ;
F_10 ( V_55 , V_132 , V_133 ) ;
F_9 ( V_55 ) ;
}
if ( V_95 < F_13 ( V_138 ) )
F_10 ( V_55 , V_139 ,
V_138 [ V_95 ] ) ;
else
F_3 ( 1 ) ;
}
static void F_19 ( struct V_54 * V_55 )
{
if ( V_55 -> V_104 . V_105 ) {
F_10 ( V_55 , V_140 , V_141 ) ;
F_10 ( V_55 , V_142 , V_143 ) ;
F_10 ( V_55 , V_144 , V_145 ) ;
F_10 ( V_55 , V_146 , V_147 ) ;
F_10 ( V_55 , V_148 , V_149 ) ;
F_10 ( V_55 , V_150 , V_151 ) ;
F_10 ( V_55 , V_152 , V_153 ) ;
F_10 ( V_55 , V_154 , V_155 ) ;
F_10 ( V_55 , V_156 , V_157 ) ;
F_10 ( V_55 , V_158 , V_159 ) ;
F_10 ( V_55 , V_160 , V_161 ) ;
F_10 ( V_55 , V_162 , V_163 ) ;
F_10 ( V_55 , V_164 , V_165 ) ;
F_10 ( V_55 , V_166 , V_167 ) ;
}
F_10 ( V_55 , V_168 , V_169 ) ;
F_10 ( V_55 , V_170 , V_171 ) ;
F_10 ( V_55 , V_172 , V_173 ) ;
F_10 ( V_55 , V_174 , V_175 ) ;
F_10 ( V_55 , V_176 , V_177 ) ;
F_10 ( V_55 , V_178 , V_179 ) ;
F_10 ( V_55 , V_180 , V_181 ) ;
F_10 ( V_55 , V_182 , V_183 ) ;
F_10 ( V_55 , V_184 , V_185 ) ;
F_10 ( V_55 , V_186 , V_187 ) ;
F_10 ( V_55 , V_188 , V_189 ) ;
F_10 ( V_55 , V_190 , V_191 ) ;
}
void F_20 ( struct V_54 * V_55 )
{
if ( V_55 -> V_104 . V_192 >= 16 )
F_16 ( V_55 ) ;
else if ( V_55 -> V_104 . V_192 >= 7 )
F_17 ( V_55 ) ;
else if ( V_55 -> V_104 . V_192 >= 3 )
F_18 ( V_55 ) ;
else
F_19 ( V_55 ) ;
}
static const T_3 * F_21 ( struct V_54 * V_55 )
{
struct V_193 * V_104 = & V_55 -> V_104 ;
if ( F_12 ( V_55 -> V_99 ) == V_194 ) {
switch ( V_104 -> V_192 ) {
case 17 :
if ( V_104 -> V_195 == 14 )
return V_196 ;
break;
case 16 :
if ( V_104 -> V_195 == 9 )
return V_197 ;
break;
case 8 :
if ( V_104 -> V_195 == 5 )
return V_198 ;
break;
case 6 :
if ( V_55 -> V_55 -> V_69 == V_199 )
return V_200 ;
return V_201 ;
case 5 :
return V_200 ;
case 4 :
case 3 :
return V_202 ;
}
F_15 ( V_55 -> V_99 ,
L_2 ) ;
return NULL ;
} else {
switch ( V_104 -> V_192 ) {
case 16 :
if ( V_104 -> V_195 == 9 )
return V_203 ;
break;
case 3 ... 6 :
return V_204 ;
}
F_15 ( V_55 -> V_99 ,
L_3 ) ;
return NULL ;
}
}
const T_3 * F_22 ( struct V_54 * V_55 )
{
struct V_193 * V_104 = & V_55 -> V_104 ;
enum V_205 V_206 = F_12 ( V_55 -> V_99 ) ;
struct V_92 * V_93 = V_55 -> V_55 -> V_94 ;
if ( V_55 -> V_104 . V_192 < 3 )
return V_207 ;
if ( ( V_55 -> V_104 . V_208 -> V_209 && V_206 == V_194 ) ||
( V_55 -> V_104 . V_208 -> V_210 && V_206 == V_100 ) ) {
return F_21 ( V_55 ) ;
} else if ( F_12 ( V_55 -> V_99 ) == V_100 ) {
switch ( V_104 -> V_192 ) {
case 6 :
case 5 :
return V_211 ;
case 4 :
return V_93 -> V_101 . V_102 . V_212 == 3 ?
V_213 :
V_214 ;
case 3 :
return V_215 ;
default:
F_15 ( V_55 -> V_99 ,
L_4 ) ;
return NULL ;
}
} else {
switch ( V_104 -> V_192 ) {
case 6 :
case 5 :
if ( V_93 -> V_101 . V_102 . V_212 == 3 )
return V_216 ;
case 4 :
case 3 :
return V_217 ;
default:
F_15 ( V_55 -> V_99 ,
L_5 ) ;
return NULL ;
}
}
}
const T_5 * F_23 ( struct V_54 * V_55 )
{
struct V_193 * V_104 = & V_55 -> V_104 ;
if ( F_12 ( V_55 -> V_99 ) == V_194 ) {
switch ( V_104 -> V_192 ) {
case 17 :
if ( V_104 -> V_195 == 14 )
return V_218 ;
break;
case 16 :
if ( V_104 -> V_195 == 9 )
return V_219 ;
break;
}
F_15 ( V_55 -> V_99 ,
L_6 ) ;
return NULL ;
} else {
switch ( V_104 -> V_192 ) {
case 16 :
if ( V_104 -> V_195 == 9 )
return V_220 ;
break;
}
F_15 ( V_55 -> V_99 ,
L_7 ) ;
return NULL ;
}
}
struct V_221 * F_24 (
struct V_54 * V_55 , bool V_102 , bool V_222 )
{
struct V_193 * V_104 = & V_55 -> V_104 ;
struct V_221 * V_223 ;
T_4 V_224 ;
if ( ! V_102 && V_55 -> V_104 . V_192 >= 6 && V_55 -> V_104 . V_195 == 11 )
return & V_225 ;
F_3 ( V_55 -> V_104 . V_192 < 3 ) ;
if ( V_55 -> V_104 . V_192 >= 6 )
V_224 = 3 ;
else if ( V_55 -> V_104 . V_192 == 5 )
V_224 = 2 ;
else if ( V_55 -> V_104 . V_192 == 4 )
V_224 = 1 ;
else
V_224 = 0 ;
V_223 = & V_226 [ V_102 ] [ V_224 ] ;
if ( ! V_102 ) {
T_4 V_227 = V_55 -> V_55 -> V_94 -> V_101 . V_103 . V_227 ;
if ( V_227 > 7 )
V_227 = 3 ;
if ( V_104 -> V_192 >= 6 ) {
static const int V_228 [] = { 0x106a , 0x106c , 0x1074 ,
0x107c , 0x007e , 0x107e ,
0x207e , 0x307e , } ;
V_223 -> V_229 = V_228 [ V_227 ] ;
} else if ( V_104 -> V_192 == 5 ) {
static const int V_228 [] = { 0x0062 , 0x0064 , 0x006a ,
0x106a , 0x106c , 0x1074 ,
0x107c , 0x207c , } ;
V_223 -> V_229 = V_228 [ V_227 ] ;
}
if ( V_104 -> V_192 >= 5 && V_222 ) {
V_223 -> V_230 [ 0 ] &= ~ 0x4000 ;
V_223 -> V_230 [ 1 ] &= ~ 0x4000 ;
V_223 -> V_230 [ 2 ] &= ~ 0x4000 ;
V_223 -> V_230 [ 3 ] &= ~ 0x4000 ;
V_223 -> V_231 &= ~ 0x4000 ;
}
} else {
if ( V_104 -> V_192 >= 6 ) {
if ( V_104 -> V_195 == 11 && ! F_25 ( V_55 ) )
V_223 -> V_232 = 0x2d ;
} else if ( V_104 -> V_192 == 4 && V_222 ) {
V_223 -> V_230 [ 0 ] &= ~ 0x4000 ;
V_223 -> V_230 [ 1 ] &= ~ 0x4000 ;
V_223 -> V_230 [ 2 ] &= ~ 0x4000 ;
V_223 -> V_230 [ 3 ] &= ~ 0x4000 ;
V_223 -> V_231 &= ~ 0x4000 ;
V_223 -> V_230 [ 0 ] |= 0x1000 ;
V_223 -> V_230 [ 1 ] |= 0x1000 ;
V_223 -> V_230 [ 2 ] |= 0x1000 ;
V_223 -> V_230 [ 3 ] |= 0x1000 ;
V_223 -> V_231 |= 0x1000 ;
}
}
return V_223 ;
}
const struct V_233 * F_26 (
struct V_54 * V_55 , V_71 V_234 , T_4 V_235 )
{
const struct V_233 * V_223 ;
T_4 T_2 , V_68 ;
switch ( V_235 ) {
case 0 :
V_223 = V_236 ;
T_2 = F_13 ( V_236 ) ;
break;
case 1 :
V_223 = V_237 ;
T_2 = F_13 ( V_237 ) ;
break;
case 2 :
V_223 = V_238 ;
T_2 = F_13 ( V_238 ) ;
break;
default:
F_15 ( V_55 -> V_99 , L_8 , V_235 ) ;
return NULL ;
}
for ( V_68 = 0 ; V_68 < T_2 ; V_68 ++ ) {
if ( V_223 [ V_68 ] . V_234 == V_234 )
return & V_223 [ V_68 ] ;
}
return NULL ;
}
