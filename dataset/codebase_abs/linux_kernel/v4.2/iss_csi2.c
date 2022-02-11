static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
F_2 ( V_2 -> V_7 , V_2 -> V_8 , V_9 , V_10 ,
V_3 ? V_10 : 0 ) ;
V_5 -> V_11 = V_3 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_2 V_12 = 0 ;
if ( V_5 -> V_13 )
V_12 |= V_14 ;
else
V_12 &= ~ V_14 ;
if ( V_5 -> V_15 )
V_12 |= V_16 ;
else
V_12 &= ~ V_16 ;
if ( V_5 -> V_17 )
V_12 |= V_18 ;
else
V_12 &= ~ V_18 ;
V_12 &= ~ V_19 ;
V_12 |= V_5 -> V_20 << V_21 ;
if ( V_5 -> V_22 )
V_12 |= V_23 ;
else
V_12 &= ~ V_23 ;
V_12 &= ~ ( V_24 | V_25 ) ;
V_12 |= ( 2 << V_26 ) |
( 4 << V_27 ) ;
V_12 |= V_28 ;
V_12 |= V_29 ;
V_12 |= V_30 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_9 , V_12 ) ;
}
static T_3 F_5 ( struct V_1 * V_2 )
{
const struct V_31 * V_32 = & V_2 -> V_33 [ V_34 ] ;
int V_35 , V_36 ;
switch ( V_32 -> V_37 ) {
case V_38 :
case V_39 :
case V_40 :
case V_41 :
V_35 = 0 ;
break;
case V_42 :
case V_43 :
case V_44 :
case V_45 :
V_35 = 1 ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_35 = 2 ;
break;
case V_50 :
case V_51 :
V_35 = 3 ;
break;
default:
F_6 ( 1 , V_52 L_1 ,
V_32 -> V_37 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_53 & V_54 ) &&
! ( V_2 -> V_53 & V_55 ) ) {
return V_56 ;
}
V_36 = V_2 -> V_57 ? 0 : ! ! ( V_2 -> V_53 & V_54 ) ;
return V_58 [ V_35 ] [ V_36 ] [ V_2 -> V_59 ] ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_60 )
{
struct V_61 * V_62 = & V_2 -> V_63 [ 0 ] ;
V_62 -> V_64 = V_60 ;
V_62 -> V_65 = V_60 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_8 ( V_62 -> V_66 ) ,
V_62 -> V_64 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_9 ( V_62 -> V_66 ) ,
V_62 -> V_65 ) ;
}
static inline int F_10 ( T_2 V_67 )
{
return ( V_67 & 0xf0 ) == 0x40 ? 1 : 0 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_66 , T_1 V_3 )
{
struct V_61 * V_62 = & V_2 -> V_63 [ V_66 ] ;
T_2 V_12 ;
V_12 = F_12 ( V_2 -> V_7 , V_2 -> V_8 , F_13 ( V_66 ) ) ;
if ( V_3 ) {
unsigned int V_68 = 0 ;
if ( V_2 -> V_57 )
V_68 = V_2 -> V_57 ;
else if ( V_2 -> V_53 & V_55 )
V_68 = 1 ;
V_12 &= ~ V_69 ;
V_12 |= V_70
| ( V_68 << V_71 )
| V_72 ;
} else {
V_12 &= ~ V_72 ;
}
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_13 ( V_66 ) , V_12 ) ;
V_62 -> V_73 = V_3 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
T_2 V_12 = 0 ;
V_62 -> V_74 = 0 ;
if ( V_62 -> V_75 )
V_12 = V_76 ;
if ( V_62 -> V_77 )
V_12 |= V_78 ;
if ( V_62 -> V_79 )
V_12 |= V_80 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_13 ( V_62 -> V_66 ) , V_12 ) ;
V_12 = V_62 -> V_81 << V_82 ;
V_12 |= V_62 -> V_67 << V_83 ;
if ( V_62 -> V_59 && V_62 -> V_84 )
V_12 |= V_85 ;
if ( F_10 ( V_62 -> V_67 ) )
V_12 |= 2 << V_86 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_15 ( V_62 -> V_66 ) , V_12 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_16 ( V_62 -> V_66 ) ,
V_62 -> V_87 << V_88 ) ;
F_2 ( V_2 -> V_7 , V_2 -> V_8 , F_17 ( V_62 -> V_66 ) ,
V_89 , V_62 -> V_90 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_8 ( V_62 -> V_66 ) ,
V_62 -> V_64 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_9 ( V_62 -> V_66 ) ,
V_62 -> V_65 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
T_2 V_12 ;
V_12 = F_12 ( V_2 -> V_7 , V_2 -> V_8 , V_93 ) ;
if ( V_92 -> V_94 )
V_12 |= V_95 ;
else
V_12 &= ~ V_95 ;
if ( V_92 -> V_96 )
V_12 |= V_97 ;
else
V_12 &= ~ V_97 ;
if ( V_92 -> V_98 )
V_12 |= V_99 ;
else
V_12 &= ~ V_99 ;
V_12 &= ~ V_100 ;
V_12 |= V_92 -> V_101 <<
V_102 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_93 , V_12 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_3 )
{
const T_2 V_103 = V_104 | V_105 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < 8 ; V_106 ++ ) {
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_20 ( V_106 ) ,
V_103 ) ;
if ( V_3 )
F_21 ( V_2 -> V_7 , V_2 -> V_8 ,
F_22 ( V_106 ) , V_103 ) ;
else
F_23 ( V_2 -> V_7 , V_2 -> V_8 ,
F_22 ( V_106 ) , V_103 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_12 ;
V_12 = V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_134 , V_12 ) ;
if ( V_3 )
F_21 ( V_2 -> V_7 , V_2 -> V_8 , V_135 ,
V_12 ) ;
else
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_135 ,
0 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_12 ;
V_12 = V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_143 , V_12 ) ;
if ( V_3 )
F_21 ( V_2 -> V_7 , V_2 -> V_8 , V_144 , V_12 ) ;
else
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_144 , 0 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
unsigned int V_145 ;
if ( ! V_2 -> V_146 )
return - V_147 ;
if ( V_2 -> V_148 -> V_149 )
return - V_150 ;
F_21 ( V_2 -> V_7 , V_2 -> V_8 , V_151 ,
V_152 ) ;
V_145 = F_27 (
F_12 ( V_2 -> V_7 , V_2 -> V_8 , V_153 ) &
V_154 , 500 , 100 , 200 ) ;
if ( V_145 ) {
F_28 ( V_2 -> V_7 -> V_155 , L_2 ) ;
return - V_150 ;
}
F_21 ( V_2 -> V_7 , V_2 -> V_8 , V_156 ,
V_157 ) ;
V_145 = F_27 (
F_12 ( V_2 -> V_7 , V_2 -> V_148 -> V_158 , V_159 ) &
V_160 , 10000 , 100 , 500 ) ;
if ( V_145 ) {
F_28 ( V_2 -> V_7 -> V_155 , L_3 ) ;
return - V_150 ;
}
F_2 ( V_2 -> V_7 , V_2 -> V_8 , V_151 ,
V_161 |
V_162 ,
V_163 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
const struct V_164 * V_165 ;
struct V_91 * V_92 = & V_2 -> V_92 [ 0 ] ;
struct V_166 * V_167 ;
struct V_168 * V_169 ;
if ( V_2 -> V_63 [ 0 ] . V_73 || V_2 -> V_6 . V_11 )
return - V_150 ;
V_169 = F_30 ( & V_2 -> V_170 [ V_34 ] ) ;
V_167 = F_31 ( V_169 -> V_171 ) ;
V_165 = V_167 -> V_172 ;
V_2 -> V_57 = 0 ;
F_32 ( V_167 , V_167 , V_173 , & V_2 -> V_57 ) ;
V_2 -> V_6 . V_20 = V_165 -> V_174 . V_2 . V_175 ;
V_2 -> V_6 . V_13 = V_176 ;
V_2 -> V_6 . V_22 = V_165 -> V_174 . V_2 . V_177 ;
V_92 -> V_94 = 1 ;
V_92 -> V_96 = 1 ;
V_92 -> V_98 = 1 ;
V_92 -> V_101 = 0x1ff ;
if ( V_2 -> V_33 [ V_34 ] . V_37 !=
V_2 -> V_33 [ V_178 ] . V_37 )
V_2 -> V_59 = true ;
else
V_2 -> V_59 = false ;
V_2 -> V_63 [ 0 ] . V_67 = F_5 ( V_2 ) ;
if ( V_2 -> V_179 . V_180 == 0 )
V_2 -> V_63 [ 0 ] . V_90 = 0 ;
else
V_2 -> V_63 [ 0 ] . V_90 = V_2 -> V_179 . V_181 ;
V_2 -> V_63 [ 0 ] . V_75 = 1 ;
V_2 -> V_63 [ 0 ] . V_77 = 1 ;
F_24 ( V_2 , 1 ) ;
F_19 ( V_2 , 1 ) ;
F_25 ( V_2 , 1 ) ;
F_18 ( V_2 , V_92 ) ;
F_3 ( V_2 , & V_2 -> V_6 ) ;
F_14 ( V_2 , & V_2 -> V_63 [ 0 ] ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_182 * V_7 = V_2 -> V_7 ;
if ( ! V_2 -> V_146 )
return;
F_34 ( V_7 -> V_155 , L_4 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_183 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_184 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_185 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_186 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_187 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_188 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_189 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_190 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_191 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_192 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_193 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_194 ) ;
F_35 ( V_7 , V_2 -> V_8 , F_36 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_37 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_38 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_39 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_40 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_41 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_42 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_43 ( 0 ) ) ;
F_34 ( V_7 -> V_155 , L_5 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_195 * V_196 ;
F_11 ( V_2 , 0 , 0 ) ;
V_196 = F_45 ( & V_2 -> V_179 ) ;
if ( V_196 == NULL )
return;
F_7 ( V_2 , V_196 -> V_197 ) ;
F_11 ( V_2 , 0 , 1 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
unsigned int V_198 = V_62 -> V_66 ;
T_2 V_199 ;
V_199 = F_12 ( V_2 -> V_7 , V_2 -> V_8 , F_20 ( V_198 ) ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_20 ( V_198 ) , V_199 ) ;
if ( V_199 & V_105 ) {
struct V_200 * V_201 =
F_47 ( & V_2 -> V_202 . V_171 ) ;
T_3 V_74 ;
T_3 V_203 ;
V_74 = F_12 ( V_2 -> V_7 , V_2 -> V_8 ,
F_15 ( V_62 -> V_66 ) )
>> V_204 ;
if ( V_74 == 0 ) {
F_48 ( & V_201 -> V_205 ) ;
} else {
V_203 = V_74 - V_62 -> V_74 ;
if ( V_74 < V_62 -> V_74 )
V_203 -- ;
V_62 -> V_74 = V_74 ;
F_49 ( V_203 , & V_201 -> V_205 ) ;
}
}
if ( ! ( V_199 & V_104 ) )
return;
if ( V_2 -> V_57 ) {
V_2 -> V_57 -- ;
if ( V_2 -> V_57 == 0 ) {
V_62 -> V_67 = F_5 ( V_2 ) ;
F_14 ( V_2 , V_62 ) ;
F_11 ( V_2 , V_198 , 1 ) ;
}
return;
}
if ( V_2 -> V_53 & V_55 )
F_44 ( V_2 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_47 ( & V_2 -> V_202 . V_171 ) ;
T_2 V_206 , V_207 ;
struct V_182 * V_7 = V_2 -> V_7 ;
if ( ! V_2 -> V_146 )
return;
V_206 = F_12 ( V_2 -> V_7 , V_2 -> V_8 , V_143 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_143 , V_206 ) ;
if ( V_206 & V_140 ) {
V_207 = F_12 ( V_2 -> V_7 , V_2 -> V_8 ,
V_134 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_134 ,
V_207 ) ;
F_34 ( V_7 -> V_155 , L_6 ,
V_207 ) ;
V_201 -> error = true ;
}
if ( V_206 & ( V_136 |
V_137 |
V_139 |
V_140 |
V_141 ) ) {
F_34 ( V_7 -> V_155 ,
L_7 ,
V_206 & V_136 ? 1 : 0 ,
V_206 & V_137 ? 1 : 0 ,
V_206 & V_139 ? 1 : 0 ,
V_206 & V_140 ? 1 : 0 ,
V_206 & V_141 ? 1 : 0 ) ;
V_201 -> error = true ;
}
if ( F_51 ( & V_2 -> V_208 , & V_2 -> V_209 ) )
return;
if ( V_206 & V_142 )
F_46 ( V_2 , & V_2 -> V_63 [ 0 ] ) ;
if ( V_206 & V_138 )
F_34 ( V_7 -> V_155 , L_8 ) ;
}
static int F_52 ( struct V_210 * V_211 , struct V_195 * V_196 )
{
struct V_1 * V_2 = F_53 ( V_211 ,
struct V_1 , V_179 ) ;
F_7 ( V_2 , V_196 -> V_197 ) ;
if ( V_2 -> V_179 . V_212 & V_213 ) {
F_1 ( V_2 , 1 ) ;
F_11 ( V_2 , 0 , 1 ) ;
F_54 ( & V_2 -> V_179 ) ;
}
return 0 ;
}
static struct V_31 *
F_55 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
unsigned int V_169 ,
enum V_216 V_217 )
{
if ( V_217 == V_218 )
return F_56 ( & V_2 -> V_202 , V_215 , V_169 ) ;
return & V_2 -> V_33 [ V_169 ] ;
}
static void
F_57 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
unsigned int V_169 ,
struct V_31 * V_32 ,
enum V_216 V_217 )
{
T_2 V_219 ;
struct V_31 * V_220 ;
const struct V_221 * V_222 ;
unsigned int V_106 ;
switch ( V_169 ) {
case V_34 :
for ( V_106 = 0 ; V_106 < F_58 ( V_223 ) ; V_106 ++ ) {
if ( V_32 -> V_37 == V_223 [ V_106 ] )
break;
}
if ( V_106 >= F_58 ( V_223 ) )
V_32 -> V_37 = V_38 ;
V_32 -> V_224 = F_59 ( T_2 , V_32 -> V_224 , 1 , 8191 ) ;
V_32 -> V_225 = F_59 ( T_2 , V_32 -> V_225 , 1 , 8191 ) ;
break;
case V_178 :
V_219 = V_32 -> V_37 ;
V_220 = F_55 ( V_2 , V_215 , V_34 , V_217 ) ;
memcpy ( V_32 , V_220 , sizeof( * V_32 ) ) ;
V_222 = F_60 ( V_32 -> V_37 ) ;
if ( V_222 -> V_226 == V_219 )
V_32 -> V_37 = V_219 ;
break;
}
V_32 -> V_227 = V_228 ;
V_32 -> V_229 = V_230 ;
}
static int F_61 ( struct V_166 * V_231 ,
struct V_214 * V_215 ,
struct V_232 * V_37 )
{
struct V_1 * V_2 = F_62 ( V_231 ) ;
struct V_31 * V_220 ;
const struct V_221 * V_222 ;
if ( V_37 -> V_169 == V_34 ) {
if ( V_37 -> V_233 >= F_58 ( V_223 ) )
return - V_234 ;
V_37 -> V_37 = V_223 [ V_37 -> V_233 ] ;
} else {
V_220 = F_55 ( V_2 , V_215 , V_34 ,
V_37 -> V_217 ) ;
switch ( V_37 -> V_233 ) {
case 0 :
V_37 -> V_37 = V_220 -> V_37 ;
break;
case 1 :
V_222 = F_60 ( V_220 -> V_37 ) ;
if ( V_222 -> V_226 == V_220 -> V_37 )
return - V_234 ;
V_37 -> V_37 = V_222 -> V_226 ;
break;
default:
return - V_234 ;
}
}
return 0 ;
}
static int F_63 ( struct V_166 * V_231 ,
struct V_214 * V_215 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_62 ( V_231 ) ;
struct V_31 V_220 ;
if ( V_236 -> V_233 != 0 )
return - V_234 ;
V_220 . V_37 = V_236 -> V_37 ;
V_220 . V_224 = 1 ;
V_220 . V_225 = 1 ;
F_57 ( V_2 , V_215 , V_236 -> V_169 , & V_220 , V_236 -> V_217 ) ;
V_236 -> V_237 = V_220 . V_224 ;
V_236 -> V_238 = V_220 . V_225 ;
if ( V_220 . V_37 != V_236 -> V_37 )
return - V_234 ;
V_220 . V_37 = V_236 -> V_37 ;
V_220 . V_224 = - 1 ;
V_220 . V_225 = - 1 ;
F_57 ( V_2 , V_215 , V_236 -> V_169 , & V_220 , V_236 -> V_217 ) ;
V_236 -> V_239 = V_220 . V_224 ;
V_236 -> V_240 = V_220 . V_225 ;
return 0 ;
}
static int F_64 ( struct V_166 * V_231 ,
struct V_214 * V_215 ,
struct V_241 * V_32 )
{
struct V_1 * V_2 = F_62 ( V_231 ) ;
struct V_31 * V_220 ;
V_220 = F_55 ( V_2 , V_215 , V_32 -> V_169 , V_32 -> V_217 ) ;
if ( V_220 == NULL )
return - V_234 ;
V_32 -> V_220 = * V_220 ;
return 0 ;
}
static int F_65 ( struct V_166 * V_231 ,
struct V_214 * V_215 ,
struct V_241 * V_32 )
{
struct V_1 * V_2 = F_62 ( V_231 ) ;
struct V_31 * V_220 ;
V_220 = F_55 ( V_2 , V_215 , V_32 -> V_169 , V_32 -> V_217 ) ;
if ( V_220 == NULL )
return - V_234 ;
F_57 ( V_2 , V_215 , V_32 -> V_169 , & V_32 -> V_220 , V_32 -> V_217 ) ;
* V_220 = V_32 -> V_220 ;
if ( V_32 -> V_169 == V_34 ) {
V_220 = F_55 ( V_2 , V_215 , V_178 ,
V_32 -> V_217 ) ;
* V_220 = V_32 -> V_220 ;
F_57 ( V_2 , V_215 , V_178 , V_220 , V_32 -> V_217 ) ;
}
return 0 ;
}
static int F_66 ( struct V_166 * V_231 , struct V_242 * V_243 ,
struct V_241 * V_244 ,
struct V_241 * V_245 )
{
struct V_1 * V_2 = F_62 ( V_231 ) ;
struct V_200 * V_201 = F_47 ( & V_2 -> V_202 . V_171 ) ;
int V_246 ;
V_201 -> V_247 = F_31 ( V_243 -> V_248 -> V_171 ) ;
V_246 = F_67 ( V_201 , V_243 ) ;
if ( V_246 < 0 )
return V_246 ;
return F_68 ( V_231 , V_243 , V_244 ,
V_245 ) ;
}
static int F_69 ( struct V_166 * V_231 , struct V_249 * V_250 )
{
struct V_241 V_220 ;
memset ( & V_220 , 0 , sizeof( V_220 ) ) ;
V_220 . V_169 = V_34 ;
V_220 . V_217 = V_250 ? V_218 : V_251 ;
V_220 . V_220 . V_37 = V_38 ;
V_220 . V_220 . V_224 = 4096 ;
V_220 . V_220 . V_225 = 4096 ;
F_65 ( V_231 , V_250 ? V_250 -> V_169 : NULL , & V_220 ) ;
return 0 ;
}
static int F_70 ( struct V_166 * V_231 , int V_3 )
{
struct V_1 * V_2 = F_62 ( V_231 ) ;
struct V_182 * V_7 = V_2 -> V_7 ;
struct V_210 * V_179 = & V_2 -> V_179 ;
int V_252 = 0 ;
if ( V_2 -> V_253 == V_254 ) {
if ( V_3 == V_254 )
return 0 ;
F_71 ( V_7 , V_2 -> V_255 ) ;
}
switch ( V_3 ) {
case V_256 : {
V_252 = F_72 ( V_7 , V_231 ) ;
if ( V_252 < 0 )
return V_252 ;
if ( F_73 ( V_2 -> V_148 ) < 0 )
return - V_147 ;
F_29 ( V_2 ) ;
F_33 ( V_2 ) ;
if ( V_2 -> V_53 & V_55 &&
! ( V_179 -> V_212 & V_257 ) )
break;
F_74 ( & V_2 -> V_209 , 0 ) ;
F_11 ( V_2 , 0 , 1 ) ;
F_1 ( V_2 , 1 ) ;
F_54 ( V_179 ) ;
break;
}
case V_254 :
if ( V_2 -> V_253 == V_254 )
return 0 ;
if ( F_75 ( & V_231 -> V_171 , & V_2 -> V_208 ,
& V_2 -> V_209 ) )
V_252 = - V_258 ;
F_11 ( V_2 , 0 , 0 ) ;
F_1 ( V_2 , 0 ) ;
F_19 ( V_2 , 0 ) ;
F_76 ( V_2 -> V_148 ) ;
F_77 ( V_7 , V_2 -> V_255 ) ;
F_54 ( V_179 ) ;
break;
}
V_2 -> V_253 = V_3 ;
return V_252 ;
}
static int F_78 ( struct V_259 * V_171 ,
const struct V_168 * V_260 ,
const struct V_168 * V_261 , T_2 V_262 )
{
struct V_166 * V_231 = F_31 ( V_171 ) ;
struct V_1 * V_2 = F_62 ( V_231 ) ;
struct V_4 * V_6 = & V_2 -> V_6 ;
switch ( V_260 -> V_233 | F_79 ( V_261 -> V_171 ) ) {
case V_178 | V_263 :
if ( V_262 & V_264 ) {
if ( V_2 -> V_53 & ~ V_55 )
return - V_150 ;
V_2 -> V_53 |= V_55 ;
} else {
V_2 -> V_53 &= ~ V_55 ;
}
break;
case V_178 | V_265 :
if ( V_262 & V_264 ) {
if ( V_2 -> V_53 & ~ V_54 )
return - V_150 ;
V_2 -> V_53 |= V_54 ;
} else {
V_2 -> V_53 &= ~ V_54 ;
}
break;
default:
return - V_234 ;
}
V_6 -> V_17 = V_2 -> V_53 & V_55 ? false : true ;
V_6 -> V_15 = ! ! ( V_2 -> V_53 & V_54 ) ;
return 0 ;
}
void F_80 ( struct V_1 * V_2 )
{
F_81 ( & V_2 -> V_202 ) ;
F_82 ( & V_2 -> V_179 ) ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_266 * V_267 )
{
int V_252 ;
V_252 = F_84 ( V_267 , & V_2 -> V_202 ) ;
if ( V_252 < 0 )
goto error;
V_252 = F_85 ( & V_2 -> V_179 , V_267 ) ;
if ( V_252 < 0 )
goto error;
return 0 ;
error:
F_80 ( V_2 ) ;
return V_252 ;
}
static int F_86 ( struct V_1 * V_2 , const char * V_268 )
{
struct V_166 * V_231 = & V_2 -> V_202 ;
struct V_168 * V_170 = V_2 -> V_170 ;
struct V_259 * V_269 = & V_231 -> V_171 ;
int V_252 ;
char V_270 [ V_271 ] ;
F_87 ( V_231 , & V_272 ) ;
V_231 -> V_273 = & V_274 ;
snprintf ( V_270 , sizeof( V_270 ) , L_9 , V_268 ) ;
snprintf ( V_231 -> V_270 , sizeof( V_231 -> V_270 ) , L_10 , V_270 ) ;
V_231 -> V_275 = 1 << 16 ;
F_88 ( V_231 , V_2 ) ;
V_231 -> V_262 |= V_276 ;
V_170 [ V_178 ] . V_262 = V_277 ;
V_170 [ V_34 ] . V_262 = V_278 ;
V_269 -> V_279 = & V_280 ;
V_252 = F_89 ( V_269 , V_281 , V_170 , 0 ) ;
if ( V_252 < 0 )
return V_252 ;
F_69 ( V_231 , NULL ) ;
V_2 -> V_179 . type = V_282 ;
V_2 -> V_179 . V_279 = & V_283 ;
V_2 -> V_179 . V_284 = 32 ;
V_2 -> V_179 . V_285 = 1 ;
V_2 -> V_179 . V_286 = 0x1ffe0 ;
V_2 -> V_179 . V_7 = V_2 -> V_7 ;
V_2 -> V_179 . V_287 = F_90 ( 4096 * 4096 ) * 3 ;
V_252 = F_91 ( & V_2 -> V_179 , V_270 ) ;
if ( V_252 < 0 )
goto V_288;
V_252 = F_92 ( & V_2 -> V_202 . V_171 , V_178 ,
& V_2 -> V_179 . V_211 . V_171 , 0 , 0 ) ;
if ( V_252 < 0 )
goto V_289;
return 0 ;
V_289:
F_93 ( & V_2 -> V_179 ) ;
V_288:
F_94 ( & V_2 -> V_202 . V_171 ) ;
return V_252 ;
}
int F_95 ( struct V_182 * V_7 )
{
struct V_1 * V_290 = & V_7 -> V_290 ;
struct V_1 * V_291 = & V_7 -> V_291 ;
int V_252 ;
V_290 -> V_7 = V_7 ;
V_290 -> V_146 = 1 ;
V_290 -> V_8 = V_292 ;
V_290 -> V_148 = & V_7 -> V_293 ;
V_290 -> V_255 = V_294 ;
V_290 -> V_253 = V_254 ;
F_96 ( & V_290 -> V_208 ) ;
V_252 = F_86 ( V_290 , L_11 ) ;
if ( V_252 < 0 )
return V_252 ;
V_291 -> V_7 = V_7 ;
V_291 -> V_146 = 1 ;
V_291 -> V_8 = V_295 ;
V_291 -> V_148 = & V_7 -> V_296 ;
V_291 -> V_255 = V_297 ;
V_291 -> V_253 = V_254 ;
F_96 ( & V_291 -> V_208 ) ;
V_252 = F_86 ( V_291 , L_12 ) ;
if ( V_252 < 0 )
return V_252 ;
return 0 ;
}
void F_97 ( struct V_182 * V_7 )
{
struct V_1 * V_290 = & V_7 -> V_290 ;
struct V_1 * V_291 = & V_7 -> V_291 ;
F_93 ( & V_290 -> V_179 ) ;
F_94 ( & V_290 -> V_202 . V_171 ) ;
F_93 ( & V_291 -> V_179 ) ;
F_94 ( & V_291 -> V_202 . V_171 ) ;
}
