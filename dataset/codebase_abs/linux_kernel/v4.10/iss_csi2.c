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
F_6 ( 1 , L_1 ,
V_32 -> V_37 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_52 & V_53 ) &&
! ( V_2 -> V_52 & V_54 ) ) {
return V_55 ;
}
V_36 = V_2 -> V_56 ? 0 : ! ! ( V_2 -> V_52 & V_53 ) ;
return V_57 [ V_35 ] [ V_36 ] [ V_2 -> V_58 ] ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_59 )
{
struct V_60 * V_61 = & V_2 -> V_62 [ 0 ] ;
V_61 -> V_63 = V_59 ;
V_61 -> V_64 = V_59 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_8 ( V_61 -> V_65 ) ,
V_61 -> V_63 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_9 ( V_61 -> V_65 ) ,
V_61 -> V_64 ) ;
}
static inline int F_10 ( T_2 V_66 )
{
return ( V_66 & 0xf0 ) == 0x40 ? 1 : 0 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_65 , T_1 V_3 )
{
struct V_60 * V_61 = & V_2 -> V_62 [ V_65 ] ;
T_2 V_12 ;
V_12 = F_12 ( V_2 -> V_7 , V_2 -> V_8 , F_13 ( V_65 ) ) ;
if ( V_3 ) {
unsigned int V_67 = 0 ;
if ( V_2 -> V_56 )
V_67 = V_2 -> V_56 ;
else if ( V_2 -> V_52 & V_54 )
V_67 = 1 ;
V_12 &= ~ V_68 ;
V_12 |= V_69
| ( V_67 << V_70 )
| V_71 ;
} else {
V_12 &= ~ V_71 ;
}
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_13 ( V_65 ) , V_12 ) ;
V_61 -> V_72 = V_3 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
T_2 V_12 = 0 ;
V_61 -> V_73 = 0 ;
if ( V_61 -> V_74 )
V_12 = V_75 ;
if ( V_61 -> V_76 )
V_12 |= V_77 ;
if ( V_61 -> V_78 )
V_12 |= V_79 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_13 ( V_61 -> V_65 ) , V_12 ) ;
V_12 = V_61 -> V_80 << V_81 ;
V_12 |= V_61 -> V_66 << V_82 ;
if ( V_61 -> V_58 && V_61 -> V_83 )
V_12 |= V_84 ;
if ( F_10 ( V_61 -> V_66 ) )
V_12 |= 2 << V_85 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_15 ( V_61 -> V_65 ) , V_12 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_16 ( V_61 -> V_65 ) ,
V_61 -> V_86 << V_87 ) ;
F_2 ( V_2 -> V_7 , V_2 -> V_8 , F_17 ( V_61 -> V_65 ) ,
V_88 , V_61 -> V_89 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_8 ( V_61 -> V_65 ) ,
V_61 -> V_63 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_9 ( V_61 -> V_65 ) ,
V_61 -> V_64 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
T_2 V_12 ;
V_12 = F_12 ( V_2 -> V_7 , V_2 -> V_8 , V_92 ) ;
if ( V_91 -> V_93 )
V_12 |= V_94 ;
else
V_12 &= ~ V_94 ;
if ( V_91 -> V_95 )
V_12 |= V_96 ;
else
V_12 &= ~ V_96 ;
if ( V_91 -> V_97 )
V_12 |= V_98 ;
else
V_12 &= ~ V_98 ;
V_12 &= ~ V_99 ;
V_12 |= V_91 -> V_100 <<
V_101 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_92 , V_12 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_3 )
{
const T_2 V_102 = V_103 | V_104 ;
int V_105 ;
for ( V_105 = 0 ; V_105 < 8 ; V_105 ++ ) {
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_20 ( V_105 ) ,
V_102 ) ;
if ( V_3 )
F_21 ( V_2 -> V_7 , V_2 -> V_8 ,
F_22 ( V_105 ) , V_102 ) ;
else
F_23 ( V_2 -> V_7 , V_2 -> V_8 ,
F_22 ( V_105 ) , V_102 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_12 ;
V_12 = V_106 |
V_107 |
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
V_132 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_133 , V_12 ) ;
if ( V_3 )
F_21 ( V_2 -> V_7 , V_2 -> V_8 , V_134 ,
V_12 ) ;
else
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_134 ,
0 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_12 ;
V_12 = V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_142 , V_12 ) ;
if ( V_3 )
F_21 ( V_2 -> V_7 , V_2 -> V_8 , V_143 , V_12 ) ;
else
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_143 , 0 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
unsigned int V_144 ;
if ( ! V_2 -> V_145 )
return - V_146 ;
if ( V_2 -> V_147 -> V_148 )
return - V_149 ;
F_21 ( V_2 -> V_7 , V_2 -> V_8 , V_150 ,
V_151 ) ;
V_144 = F_27 (
F_12 ( V_2 -> V_7 , V_2 -> V_8 , V_152 ) &
V_153 , 500 , 100 , 200 ) ;
if ( V_144 ) {
F_28 ( V_2 -> V_7 -> V_154 , L_2 ) ;
return - V_149 ;
}
F_21 ( V_2 -> V_7 , V_2 -> V_8 , V_155 ,
V_156 ) ;
V_144 = F_27 (
F_12 ( V_2 -> V_7 , V_2 -> V_147 -> V_157 , V_158 ) &
V_159 , 10000 , 100 , 500 ) ;
if ( V_144 ) {
F_28 ( V_2 -> V_7 -> V_154 , L_3 ) ;
return - V_149 ;
}
F_2 ( V_2 -> V_7 , V_2 -> V_8 , V_150 ,
V_160 |
V_161 ,
V_162 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
const struct V_163 * V_164 ;
struct V_90 * V_91 = & V_2 -> V_91 [ 0 ] ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
if ( V_2 -> V_62 [ 0 ] . V_72 || V_2 -> V_6 . V_11 )
return - V_149 ;
V_168 = F_30 ( & V_2 -> V_169 [ V_34 ] ) ;
V_166 = F_31 ( V_168 -> V_170 ) ;
V_164 = V_166 -> V_171 ;
V_2 -> V_56 = 0 ;
F_32 ( V_166 , V_166 , V_172 , & V_2 -> V_56 ) ;
V_2 -> V_6 . V_20 = V_164 -> V_173 . V_2 . V_174 ;
V_2 -> V_6 . V_13 = V_175 ;
V_2 -> V_6 . V_22 = V_164 -> V_173 . V_2 . V_176 ;
V_91 -> V_93 = 1 ;
V_91 -> V_95 = 1 ;
V_91 -> V_97 = 1 ;
V_91 -> V_100 = 0x1ff ;
if ( V_2 -> V_33 [ V_34 ] . V_37 !=
V_2 -> V_33 [ V_177 ] . V_37 )
V_2 -> V_58 = true ;
else
V_2 -> V_58 = false ;
V_2 -> V_62 [ 0 ] . V_66 = F_5 ( V_2 ) ;
if ( V_2 -> V_178 . V_179 == 0 )
V_2 -> V_62 [ 0 ] . V_89 = 0 ;
else
V_2 -> V_62 [ 0 ] . V_89 = V_2 -> V_178 . V_180 ;
V_2 -> V_62 [ 0 ] . V_74 = 1 ;
V_2 -> V_62 [ 0 ] . V_76 = 1 ;
F_24 ( V_2 , 1 ) ;
F_19 ( V_2 , 1 ) ;
F_25 ( V_2 , 1 ) ;
F_18 ( V_2 , V_91 ) ;
F_3 ( V_2 , & V_2 -> V_6 ) ;
F_14 ( V_2 , & V_2 -> V_62 [ 0 ] ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_181 * V_7 = V_2 -> V_7 ;
if ( ! V_2 -> V_145 )
return;
F_34 ( V_7 -> V_154 , L_4 ) ;
F_35 ( V_7 , V_2 -> V_8 , V_182 ) ;
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
F_35 ( V_7 , V_2 -> V_8 , F_36 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_37 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_38 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_39 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_40 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_41 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_42 ( 0 ) ) ;
F_35 ( V_7 , V_2 -> V_8 , F_43 ( 0 ) ) ;
F_34 ( V_7 -> V_154 , L_5 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_194 * V_195 ;
F_11 ( V_2 , 0 , 0 ) ;
V_195 = F_45 ( & V_2 -> V_178 ) ;
if ( ! V_195 )
return;
F_7 ( V_2 , V_195 -> V_196 ) ;
F_11 ( V_2 , 0 , 1 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
unsigned int V_197 = V_61 -> V_65 ;
T_2 V_198 ;
V_198 = F_12 ( V_2 -> V_7 , V_2 -> V_8 , F_20 ( V_197 ) ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , F_20 ( V_197 ) , V_198 ) ;
if ( F_47 ( & V_2 -> V_199 , & V_2 -> V_200 ) )
return;
if ( V_198 & V_104 ) {
struct V_201 * V_202 =
F_48 ( & V_2 -> V_203 . V_170 ) ;
T_3 V_73 ;
T_3 V_204 ;
V_73 = F_12 ( V_2 -> V_7 , V_2 -> V_8 ,
F_15 ( V_61 -> V_65 ) )
>> V_205 ;
if ( V_73 == 0 ) {
F_49 ( & V_202 -> V_206 ) ;
} else {
V_204 = V_73 - V_61 -> V_73 ;
if ( V_73 < V_61 -> V_73 )
V_204 -- ;
V_61 -> V_73 = V_73 ;
F_50 ( V_204 , & V_202 -> V_206 ) ;
}
}
if ( ! ( V_198 & V_103 ) )
return;
if ( V_2 -> V_56 ) {
V_2 -> V_56 -- ;
if ( V_2 -> V_56 == 0 ) {
V_61 -> V_66 = F_5 ( V_2 ) ;
F_14 ( V_2 , V_61 ) ;
F_11 ( V_2 , V_197 , 1 ) ;
}
return;
}
if ( V_2 -> V_52 & V_54 )
F_44 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_201 * V_202 = F_48 ( & V_2 -> V_203 . V_170 ) ;
T_2 V_207 , V_208 ;
struct V_181 * V_7 = V_2 -> V_7 ;
if ( ! V_2 -> V_145 )
return;
V_207 = F_12 ( V_2 -> V_7 , V_2 -> V_8 , V_142 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_142 , V_207 ) ;
if ( V_207 & V_139 ) {
V_208 = F_12 ( V_2 -> V_7 , V_2 -> V_8 ,
V_133 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_133 ,
V_208 ) ;
F_34 ( V_7 -> V_154 , L_6 ,
V_208 ) ;
V_202 -> error = true ;
}
if ( V_207 & ( V_135 |
V_136 |
V_138 |
V_139 |
V_140 ) ) {
F_34 ( V_7 -> V_154 ,
L_7 ,
V_207 & V_135 ? 1 : 0 ,
V_207 & V_136 ? 1 : 0 ,
V_207 & V_138 ? 1 : 0 ,
V_207 & V_139 ? 1 : 0 ,
V_207 & V_140 ? 1 : 0 ) ;
V_202 -> error = true ;
}
if ( V_207 & V_141 )
F_46 ( V_2 , & V_2 -> V_62 [ 0 ] ) ;
if ( V_207 & V_137 )
F_34 ( V_7 -> V_154 , L_8 ) ;
}
static int F_52 ( struct V_209 * V_210 , struct V_194 * V_195 )
{
struct V_1 * V_2 = F_53 ( V_210 ,
struct V_1 , V_178 ) ;
F_7 ( V_2 , V_195 -> V_196 ) ;
if ( V_2 -> V_178 . V_211 & V_212 ) {
F_1 ( V_2 , 1 ) ;
F_11 ( V_2 , 0 , 1 ) ;
F_54 ( & V_2 -> V_178 ) ;
}
return 0 ;
}
static struct V_31 *
F_55 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
unsigned int V_168 ,
enum V_215 V_216 )
{
if ( V_216 == V_217 )
return F_56 ( & V_2 -> V_203 , V_214 , V_168 ) ;
return & V_2 -> V_33 [ V_168 ] ;
}
static void
F_57 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
unsigned int V_168 ,
struct V_31 * V_32 ,
enum V_215 V_216 )
{
T_2 V_218 ;
struct V_31 * V_219 ;
const struct V_220 * V_221 ;
unsigned int V_105 ;
switch ( V_168 ) {
case V_34 :
for ( V_105 = 0 ; V_105 < F_58 ( V_222 ) ; V_105 ++ ) {
if ( V_32 -> V_37 == V_222 [ V_105 ] )
break;
}
if ( V_105 >= F_58 ( V_222 ) )
V_32 -> V_37 = V_38 ;
V_32 -> V_223 = F_59 ( T_2 , V_32 -> V_223 , 1 , 8191 ) ;
V_32 -> V_224 = F_59 ( T_2 , V_32 -> V_224 , 1 , 8191 ) ;
break;
case V_177 :
V_218 = V_32 -> V_37 ;
V_219 = F_55 ( V_2 , V_214 , V_34 , V_216 ) ;
memcpy ( V_32 , V_219 , sizeof( * V_32 ) ) ;
V_221 = F_60 ( V_32 -> V_37 ) ;
if ( V_221 -> V_225 == V_218 )
V_32 -> V_37 = V_218 ;
break;
}
V_32 -> V_226 = V_227 ;
V_32 -> V_228 = V_229 ;
}
static int F_61 ( struct V_165 * V_230 ,
struct V_213 * V_214 ,
struct V_231 * V_37 )
{
struct V_1 * V_2 = F_62 ( V_230 ) ;
struct V_31 * V_219 ;
const struct V_220 * V_221 ;
if ( V_37 -> V_168 == V_34 ) {
if ( V_37 -> V_232 >= F_58 ( V_222 ) )
return - V_233 ;
V_37 -> V_37 = V_222 [ V_37 -> V_232 ] ;
} else {
V_219 = F_55 ( V_2 , V_214 , V_34 ,
V_37 -> V_216 ) ;
switch ( V_37 -> V_232 ) {
case 0 :
V_37 -> V_37 = V_219 -> V_37 ;
break;
case 1 :
V_221 = F_60 ( V_219 -> V_37 ) ;
if ( V_221 -> V_225 == V_219 -> V_37 )
return - V_233 ;
V_37 -> V_37 = V_221 -> V_225 ;
break;
default:
return - V_233 ;
}
}
return 0 ;
}
static int F_63 ( struct V_165 * V_230 ,
struct V_213 * V_214 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_62 ( V_230 ) ;
struct V_31 V_219 ;
if ( V_235 -> V_232 != 0 )
return - V_233 ;
V_219 . V_37 = V_235 -> V_37 ;
V_219 . V_223 = 1 ;
V_219 . V_224 = 1 ;
F_57 ( V_2 , V_214 , V_235 -> V_168 , & V_219 , V_235 -> V_216 ) ;
V_235 -> V_236 = V_219 . V_223 ;
V_235 -> V_237 = V_219 . V_224 ;
if ( V_219 . V_37 != V_235 -> V_37 )
return - V_233 ;
V_219 . V_37 = V_235 -> V_37 ;
V_219 . V_223 = - 1 ;
V_219 . V_224 = - 1 ;
F_57 ( V_2 , V_214 , V_235 -> V_168 , & V_219 , V_235 -> V_216 ) ;
V_235 -> V_238 = V_219 . V_223 ;
V_235 -> V_239 = V_219 . V_224 ;
return 0 ;
}
static int F_64 ( struct V_165 * V_230 ,
struct V_213 * V_214 ,
struct V_240 * V_32 )
{
struct V_1 * V_2 = F_62 ( V_230 ) ;
struct V_31 * V_219 ;
V_219 = F_55 ( V_2 , V_214 , V_32 -> V_168 , V_32 -> V_216 ) ;
if ( ! V_219 )
return - V_233 ;
V_32 -> V_219 = * V_219 ;
return 0 ;
}
static int F_65 ( struct V_165 * V_230 ,
struct V_213 * V_214 ,
struct V_240 * V_32 )
{
struct V_1 * V_2 = F_62 ( V_230 ) ;
struct V_31 * V_219 ;
V_219 = F_55 ( V_2 , V_214 , V_32 -> V_168 , V_32 -> V_216 ) ;
if ( ! V_219 )
return - V_233 ;
F_57 ( V_2 , V_214 , V_32 -> V_168 , & V_32 -> V_219 , V_32 -> V_216 ) ;
* V_219 = V_32 -> V_219 ;
if ( V_32 -> V_168 == V_34 ) {
V_219 = F_55 ( V_2 , V_214 , V_177 ,
V_32 -> V_216 ) ;
* V_219 = V_32 -> V_219 ;
F_57 ( V_2 , V_214 , V_177 , V_219 , V_32 -> V_216 ) ;
}
return 0 ;
}
static int F_66 ( struct V_165 * V_230 , struct V_241 * V_242 ,
struct V_240 * V_243 ,
struct V_240 * V_244 )
{
struct V_1 * V_2 = F_62 ( V_230 ) ;
struct V_201 * V_202 = F_48 ( & V_2 -> V_203 . V_170 ) ;
int V_245 ;
V_202 -> V_246 = F_31 ( V_242 -> V_247 -> V_170 ) ;
V_245 = F_67 ( V_202 , V_242 ) ;
if ( V_245 < 0 )
return V_245 ;
return F_68 ( V_230 , V_242 , V_243 ,
V_244 ) ;
}
static int F_69 ( struct V_165 * V_230 , struct V_248 * V_249 )
{
struct V_240 V_219 ;
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
V_219 . V_168 = V_34 ;
V_219 . V_216 = V_249 ? V_217 : V_250 ;
V_219 . V_219 . V_37 = V_38 ;
V_219 . V_219 . V_223 = 4096 ;
V_219 . V_219 . V_224 = 4096 ;
F_65 ( V_230 , V_249 ? V_249 -> V_168 : NULL , & V_219 ) ;
return 0 ;
}
static int F_70 ( struct V_165 * V_230 , int V_3 )
{
struct V_1 * V_2 = F_62 ( V_230 ) ;
struct V_181 * V_7 = V_2 -> V_7 ;
struct V_209 * V_178 = & V_2 -> V_178 ;
int V_251 = 0 ;
if ( V_2 -> V_252 == V_253 ) {
if ( V_3 == V_253 )
return 0 ;
F_71 ( V_7 , V_2 -> V_254 ) ;
}
switch ( V_3 ) {
case V_255 : {
V_251 = F_72 ( V_7 , V_230 ) ;
if ( V_251 < 0 )
return V_251 ;
if ( F_73 ( V_2 -> V_147 ) < 0 )
return - V_146 ;
F_29 ( V_2 ) ;
F_33 ( V_2 ) ;
if ( V_2 -> V_52 & V_54 &&
! ( V_178 -> V_211 & V_256 ) )
break;
F_74 ( & V_2 -> V_200 , 0 ) ;
F_11 ( V_2 , 0 , 1 ) ;
F_1 ( V_2 , 1 ) ;
F_54 ( V_178 ) ;
break;
}
case V_253 :
if ( V_2 -> V_252 == V_253 )
return 0 ;
if ( F_75 ( & V_230 -> V_170 , & V_2 -> V_199 ,
& V_2 -> V_200 ) )
V_251 = - V_257 ;
F_11 ( V_2 , 0 , 0 ) ;
F_1 ( V_2 , 0 ) ;
F_19 ( V_2 , 0 ) ;
F_76 ( V_2 -> V_147 ) ;
F_77 ( V_7 , V_2 -> V_254 ) ;
F_54 ( V_178 ) ;
break;
}
V_2 -> V_252 = V_3 ;
return V_251 ;
}
static int F_78 ( struct V_258 * V_170 ,
const struct V_167 * V_259 ,
const struct V_167 * V_260 , T_2 V_261 )
{
struct V_165 * V_230 = F_31 ( V_170 ) ;
struct V_1 * V_2 = F_62 ( V_230 ) ;
struct V_4 * V_6 = & V_2 -> V_6 ;
unsigned int V_232 = V_259 -> V_232 ;
if ( F_79 ( V_260 -> V_170 ) )
V_232 |= 2 << 16 ;
switch ( V_232 ) {
case V_177 :
if ( V_261 & V_262 ) {
if ( V_2 -> V_52 & ~ V_54 )
return - V_149 ;
V_2 -> V_52 |= V_54 ;
} else {
V_2 -> V_52 &= ~ V_54 ;
}
break;
case V_177 | 2 << 16 :
if ( V_261 & V_262 ) {
if ( V_2 -> V_52 & ~ V_53 )
return - V_149 ;
V_2 -> V_52 |= V_53 ;
} else {
V_2 -> V_52 &= ~ V_53 ;
}
break;
default:
return - V_233 ;
}
V_6 -> V_17 = V_2 -> V_52 & V_54 ? false : true ;
V_6 -> V_15 = ! ! ( V_2 -> V_52 & V_53 ) ;
return 0 ;
}
void F_80 ( struct V_1 * V_2 )
{
F_81 ( & V_2 -> V_203 ) ;
F_82 ( & V_2 -> V_178 ) ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_263 * V_264 )
{
int V_251 ;
V_251 = F_84 ( V_264 , & V_2 -> V_203 ) ;
if ( V_251 < 0 )
goto error;
V_251 = F_85 ( & V_2 -> V_178 , V_264 ) ;
if ( V_251 < 0 )
goto error;
return 0 ;
error:
F_80 ( V_2 ) ;
return V_251 ;
}
static int F_86 ( struct V_1 * V_2 , const char * V_265 )
{
struct V_165 * V_230 = & V_2 -> V_203 ;
struct V_167 * V_169 = V_2 -> V_169 ;
struct V_258 * V_266 = & V_230 -> V_170 ;
int V_251 ;
char V_267 [ V_268 ] ;
F_87 ( V_230 , & V_269 ) ;
V_230 -> V_270 = & V_271 ;
snprintf ( V_267 , sizeof( V_267 ) , L_9 , V_265 ) ;
snprintf ( V_230 -> V_267 , sizeof( V_230 -> V_267 ) , L_10 , V_267 ) ;
V_230 -> V_272 = 1 << 16 ;
F_88 ( V_230 , V_2 ) ;
V_230 -> V_261 |= V_273 ;
V_169 [ V_177 ] . V_261 = V_274 ;
V_169 [ V_34 ] . V_261 = V_275 ;
V_266 -> V_276 = & V_277 ;
V_251 = F_89 ( V_266 , V_278 , V_169 ) ;
if ( V_251 < 0 )
return V_251 ;
F_69 ( V_230 , NULL ) ;
V_2 -> V_178 . type = V_279 ;
V_2 -> V_178 . V_276 = & V_280 ;
V_2 -> V_178 . V_281 = 32 ;
V_2 -> V_178 . V_282 = 1 ;
V_2 -> V_178 . V_283 = 0x1ffe0 ;
V_2 -> V_178 . V_7 = V_2 -> V_7 ;
V_2 -> V_178 . V_284 = F_90 ( 4096 * 4096 ) * 3 ;
V_251 = F_91 ( & V_2 -> V_178 , V_267 ) ;
if ( V_251 < 0 )
goto V_285;
return 0 ;
V_285:
F_92 ( & V_2 -> V_203 . V_170 ) ;
return V_251 ;
}
int F_93 ( struct V_181 * V_7 )
{
struct V_1 * V_286 = & V_7 -> V_286 ;
struct V_1 * V_287 = & V_7 -> V_287 ;
int V_251 ;
V_286 -> V_7 = V_7 ;
V_286 -> V_145 = 1 ;
V_286 -> V_8 = V_288 ;
V_286 -> V_147 = & V_7 -> V_289 ;
V_286 -> V_254 = V_290 ;
V_286 -> V_252 = V_253 ;
F_94 ( & V_286 -> V_199 ) ;
V_251 = F_86 ( V_286 , L_11 ) ;
if ( V_251 < 0 )
return V_251 ;
V_287 -> V_7 = V_7 ;
V_287 -> V_145 = 1 ;
V_287 -> V_8 = V_291 ;
V_287 -> V_147 = & V_7 -> V_292 ;
V_287 -> V_254 = V_293 ;
V_287 -> V_252 = V_253 ;
F_94 ( & V_287 -> V_199 ) ;
V_251 = F_86 ( V_287 , L_12 ) ;
if ( V_251 < 0 )
return V_251 ;
return 0 ;
}
int F_95 ( struct V_181 * V_7 )
{
struct V_1 * V_286 = & V_7 -> V_286 ;
struct V_1 * V_287 = & V_7 -> V_287 ;
int V_251 ;
V_251 = F_96 ( & V_286 -> V_203 . V_170 , V_177 ,
& V_286 -> V_178 . V_210 . V_170 , 0 , 0 ) ;
if ( V_251 < 0 )
return V_251 ;
V_251 = F_96 ( & V_287 -> V_203 . V_170 , V_177 ,
& V_287 -> V_178 . V_210 . V_170 , 0 , 0 ) ;
if ( V_251 < 0 )
return V_251 ;
return 0 ;
}
void F_97 ( struct V_181 * V_7 )
{
struct V_1 * V_286 = & V_7 -> V_286 ;
struct V_1 * V_287 = & V_7 -> V_287 ;
F_98 ( & V_286 -> V_178 ) ;
F_92 ( & V_286 -> V_203 . V_170 ) ;
F_98 ( & V_287 -> V_178 ) ;
F_92 ( & V_287 -> V_203 . V_170 ) ;
}
