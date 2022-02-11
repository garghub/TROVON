static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = & V_4 -> V_8 ;
F_2 ( V_2 , V_4 -> V_9 , V_10 , V_11 ,
V_5 ? V_11 : 0 ) ;
V_7 -> V_12 = V_5 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
T_2 V_13 ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , V_10 ) ;
if ( V_7 -> V_14 )
V_13 |= V_15 ;
else
V_13 &= ~ V_15 ;
if ( V_7 -> V_16 )
V_13 |= V_17 ;
else
V_13 &= ~ V_17 ;
if ( V_7 -> V_18 )
V_13 |= V_19 ;
else
V_13 &= ~ V_19 ;
V_13 &= ~ V_20 ;
V_13 |= V_7 -> V_21 << V_22 ;
if ( V_7 -> V_23 )
V_13 |= V_24 ;
else
V_13 &= ~ V_24 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_10 ) ;
}
static T_3 F_6 ( struct V_3 * V_4 )
{
const struct V_25 * V_26 = & V_4 -> V_27 [ V_28 ] ;
int V_29 , V_30 , V_31 ;
switch ( V_26 -> V_32 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
V_29 = 0 ;
break;
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_29 = 1 ;
break;
default:
F_7 ( 1 , V_41 L_1 ,
V_26 -> V_32 ) ;
return 0 ;
}
if ( ! ( V_4 -> V_42 & V_43 ) &&
! ( V_4 -> V_42 & V_44 ) ) {
return V_45 ;
}
V_30 = V_4 -> V_46 ? 0 : ! ! ( V_4 -> V_42 & V_43 ) ;
V_31 = V_4 -> V_2 -> V_47 == V_48 ;
return V_49 [ V_29 ] [ V_30 ] [ V_4 -> V_50 ] [ V_31 ] ;
}
static void F_8 ( struct V_3 * V_4 , T_2 V_51 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_52 * V_53 = & V_4 -> V_54 [ 0 ] ;
V_53 -> V_55 = V_51 ;
V_53 -> V_56 = V_51 ;
F_5 ( V_2 , V_53 -> V_55 ,
V_4 -> V_9 , F_9 ( V_53 -> V_57 ) ) ;
F_5 ( V_2 , V_53 -> V_56 ,
V_4 -> V_9 , F_10 ( V_53 -> V_57 ) ) ;
}
static inline int F_11 ( T_2 V_58 )
{
return ( V_58 & 0x40 ) ? 1 : 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_57 , T_1 V_5 )
{
struct V_52 * V_53 = & V_4 -> V_54 [ V_57 ] ;
unsigned int V_59 = 0 ;
T_2 V_13 ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , F_13 ( V_57 ) ) ;
if ( V_5 ) {
if ( V_4 -> V_46 )
V_59 = V_4 -> V_46 ;
else if ( V_4 -> V_42 & V_44 )
V_59 = 1 ;
V_13 &= ~ V_60 ;
V_13 |= V_61
| ( V_59 << V_62 )
| V_63 ;
} else {
V_13 &= ~ V_63 ;
}
F_5 ( V_2 , V_13 , V_4 -> V_9 , F_13 ( V_57 ) ) ;
V_53 -> V_64 = V_5 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_52 * V_53 )
{
T_2 V_13 ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , F_13 ( V_53 -> V_57 ) ) ;
if ( V_53 -> V_65 )
V_13 |= V_66 ;
else
V_13 &= ~ V_66 ;
if ( V_53 -> V_67 )
V_13 |= V_68 ;
else
V_13 &= ~ V_68 ;
if ( V_53 -> V_69 )
V_13 |= V_70 ;
else
V_13 &= ~ V_70 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , F_13 ( V_53 -> V_57 ) ) ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , F_15 ( V_53 -> V_57 ) ) ;
V_13 &= ~ ( V_71 ) ;
V_13 |= V_53 -> V_72 << V_73 ;
V_13 &= ~ ( V_74 ) ;
V_13 |= V_53 -> V_58 << V_75 ;
if ( V_53 -> V_50 ) {
if ( V_53 -> V_76 )
V_13 |= V_77 ;
else
V_13 &= ~ V_77 ;
}
if ( F_11 ( V_53 -> V_58 ) ) {
V_13 &= ~ V_78 ;
V_13 |= 2 << V_79 ;
}
F_5 ( V_2 , V_13 , V_4 -> V_9 , F_15 ( V_53 -> V_57 ) ) ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , F_16 ( V_53 -> V_57 ) ) ;
V_13 &= ~ ( V_80 ) ;
V_13 |= ( V_53 -> V_81 << V_82 ) ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , F_16 ( V_53 -> V_57 ) ) ;
V_13 = F_4 ( V_2 , V_4 -> V_9 ,
F_17 ( V_53 -> V_57 ) ) ;
V_13 &= ~ V_83 ;
V_13 |= V_53 -> V_84 << V_85 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 ,
F_17 ( V_53 -> V_57 ) ) ;
F_5 ( V_2 , V_53 -> V_55 ,
V_4 -> V_9 , F_9 ( V_53 -> V_57 ) ) ;
F_5 ( V_2 , V_53 -> V_56 ,
V_4 -> V_9 , F_10 ( V_53 -> V_57 ) ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_86 * V_87 )
{
T_2 V_13 ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , V_88 ) ;
if ( V_87 -> V_89 )
V_13 |= F_19 ( V_87 -> V_90 ) ;
else
V_13 &= ~ F_19 ( V_87 -> V_90 ) ;
if ( V_87 -> V_91 )
V_13 |= F_20 ( V_87 -> V_90 ) ;
else
V_13 &= ~ F_20 ( V_87 -> V_90 ) ;
if ( V_87 -> V_92 )
V_13 |= F_21 ( V_87 -> V_90 ) ;
else
V_13 &= ~ F_21 ( V_87 -> V_90 ) ;
V_13 &= ~ F_22 ( V_87 -> V_90 ) ;
V_13 |= V_87 -> V_93 <<
F_23 ( V_87 -> V_90 ) ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_88 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_2 V_13 = V_94 ;
int V_95 ;
if ( V_4 -> V_96 )
V_13 |= V_97 ;
for ( V_95 = 0 ; V_95 < 8 ; V_95 ++ ) {
F_5 ( V_2 , V_13 , V_4 -> V_9 ,
F_25 ( V_95 ) ) ;
if ( V_5 )
F_26 ( V_2 , V_4 -> V_9 , F_27 ( V_95 ) ,
V_13 ) ;
else
F_28 ( V_2 , V_4 -> V_9 , F_27 ( V_95 ) ,
V_13 ) ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_2 V_13 ;
V_13 = V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 |
V_106 |
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
V_124 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_125 ) ;
if ( V_5 )
V_13 |= F_4 ( V_2 , V_4 -> V_9 , V_126 ) ;
else
V_13 = 0 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_126 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_2 V_13 ;
V_13 = V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
F_31 ( 0 ) ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_134 ) ;
if ( V_5 )
V_13 |= F_4 ( V_2 , V_4 -> V_9 , V_135 ) ;
else
V_13 = 0 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_135 ) ;
}
int F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_136 = 0 ;
T_2 V_13 ;
int V_95 ;
if ( ! V_4 -> V_137 )
return - V_138 ;
if ( V_4 -> V_139 -> V_140 )
return - V_141 ;
F_26 ( V_2 , V_4 -> V_9 , V_142 ,
V_143 ) ;
do {
V_13 = F_4 ( V_2 , V_4 -> V_9 , V_144 ) &
V_145 ;
if ( V_13 == V_145 )
break;
V_136 ++ ;
if ( V_136 < 5 )
F_33 ( 100 ) ;
} while ( V_136 < 5 );
if ( V_136 == 5 ) {
F_34 ( V_41 L_2 ) ;
return - V_141 ;
}
if ( V_2 -> V_47 == V_48 )
F_26 ( V_2 , V_4 -> V_9 , V_146 ,
V_147 ) ;
V_95 = 100 ;
do {
V_13 = F_4 ( V_2 , V_4 -> V_139 -> V_148 , V_149 )
& V_150 ;
if ( V_13 == V_150 )
break;
F_33 ( 100 ) ;
} while ( -- V_95 > 0 );
if ( V_95 == 0 ) {
F_34 ( V_41
L_3 ) ;
return - V_141 ;
}
if ( V_2 -> V_151 )
F_2 ( V_2 , V_4 -> V_9 , V_142 ,
V_152 |
V_153 ,
V_154 |
( ( V_2 -> V_47 == V_48 ) ?
V_153 : 0 ) ) ;
else
F_2 ( V_2 , V_4 -> V_9 , V_142 ,
V_152 |
V_153 ,
V_155 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
const struct V_156 * V_157 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_86 * V_87 = & V_4 -> V_87 [ 0 ] ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
if ( V_4 -> V_54 [ 0 ] . V_64 || V_4 -> V_8 . V_12 )
return - V_141 ;
V_161 = F_36 ( & V_4 -> V_162 [ V_28 ] ) ;
V_159 = F_37 ( V_161 -> V_163 ) ;
V_157 = V_159 -> V_164 ;
V_4 -> V_46 = 0 ;
F_38 ( V_159 , V_159 , V_165 , & V_4 -> V_46 ) ;
V_4 -> V_8 . V_21 = V_157 -> V_166 . V_4 . V_167 ;
V_4 -> V_8 . V_14 = V_168 ;
V_4 -> V_8 . V_23 = V_157 -> V_166 . V_4 . V_169 ;
V_87 -> V_90 = 1 ;
V_87 -> V_89 = 1 ;
V_87 -> V_91 = 1 ;
V_87 -> V_92 = 1 ;
V_87 -> V_93 = 0x1FF ;
if ( V_4 -> V_27 [ V_28 ] . V_32 !=
V_4 -> V_27 [ V_170 ] . V_32 )
V_4 -> V_50 = true ;
else
V_4 -> V_50 = false ;
V_4 -> V_54 [ 0 ] . V_58 = F_6 ( V_4 ) ;
if ( V_4 -> V_171 . V_172 == 0 )
V_4 -> V_54 [ 0 ] . V_84 = 0 ;
else
V_4 -> V_54 [ 0 ] . V_84 = V_4 -> V_171 . V_173 ;
V_4 -> V_54 [ 0 ] . V_65 = 1 ;
V_4 -> V_54 [ 0 ] . V_67 = 1 ;
F_29 ( V_2 , V_4 , 1 ) ;
F_24 ( V_2 , V_4 , 1 ) ;
F_30 ( V_2 , V_4 , 1 ) ;
F_18 ( V_2 , V_4 , V_87 ) ;
F_3 ( V_2 , V_4 , & V_4 -> V_8 ) ;
F_14 ( V_2 , V_4 , & V_4 -> V_54 [ 0 ] ) ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_4 -> V_137 )
return;
F_40 ( V_2 -> V_174 , L_4 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_175 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_176 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_177 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_178 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_179 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_180 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_181 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_182 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_183 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_184 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_185 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_186 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_187 ) ;
F_41 ( V_2 , V_4 -> V_9 , F_42 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_43 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_44 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_45 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_46 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_47 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_48 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_49 ( 0 ) ) ;
F_40 ( V_2 -> V_174 , L_5 ) ;
}
static void F_50 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_188 * V_189 ;
F_12 ( V_2 , V_4 , 0 , 0 ) ;
V_189 = F_51 ( & V_4 -> V_171 , 0 ) ;
if ( V_189 == NULL )
return;
F_8 ( V_4 , V_189 -> V_190 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
}
static void F_52 ( struct V_3 * V_4 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_191 = V_53 -> V_57 ;
T_2 V_192 ;
V_192 = F_4 ( V_2 , V_4 -> V_9 , F_25 ( V_191 ) ) ;
F_5 ( V_2 , V_192 , V_4 -> V_9 , F_25 ( V_191 ) ) ;
if ( V_192 & V_97 ) {
struct V_193 * V_194 =
F_53 ( & V_4 -> V_195 . V_163 ) ;
if ( V_194 -> V_196 )
F_54 ( & V_194 -> V_197 ) ;
}
if ( ! ( V_192 & V_94 ) )
return;
if ( V_4 -> V_46 ) {
V_4 -> V_46 -- ;
if ( V_4 -> V_46 == 0 ) {
V_53 -> V_58 = F_6 ( V_4 ) ;
F_14 ( V_2 , V_4 , V_53 ) ;
F_12 ( V_2 , V_4 , V_191 , 1 ) ;
}
return;
}
if ( V_4 -> V_42 & V_44 )
F_50 ( V_4 ) ;
}
int F_55 ( struct V_3 * V_4 )
{
T_2 V_198 , V_199 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_200 = 0 ;
if ( ! V_4 -> V_137 )
return - V_138 ;
V_198 = F_4 ( V_2 , V_4 -> V_9 , V_134 ) ;
F_5 ( V_2 , V_198 , V_4 -> V_9 , V_134 ) ;
if ( V_198 & V_132 ) {
V_199 = F_4 ( V_2 , V_4 -> V_9 ,
V_125 ) ;
F_5 ( V_2 , V_199 ,
V_4 -> V_9 , V_125 ) ;
F_40 ( V_2 -> V_174 , L_6
L_7 , V_199 ) ;
V_200 = - V_201 ;
}
if ( V_198 & ( V_127 |
V_128 |
V_130 |
V_131 |
V_133 ) ) {
F_40 ( V_2 -> V_174 , L_8
L_9
L_10
L_11
L_12
L_13
L_14 ,
( V_198 &
V_127 ) ? 1 : 0 ,
( V_198 &
V_128 ) ? 1 : 0 ,
( V_198 &
V_130 ) ? 1 : 0 ,
( V_198 &
V_131 ) ? 1 : 0 ,
( V_198 &
V_133 ) ? 1 : 0 ) ;
V_200 = - V_201 ;
}
if ( F_56 ( & V_4 -> V_202 , & V_4 -> V_203 ) )
return 0 ;
if ( V_198 & F_31 ( 0 ) )
F_52 ( V_4 , & V_4 -> V_54 [ 0 ] ) ;
if ( V_198 & V_129 )
F_40 ( V_2 -> V_174 , L_15 ) ;
return V_200 ;
}
static int F_57 ( struct V_204 * V_205 , struct V_188 * V_189 )
{
struct V_1 * V_2 = V_205 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_206 ;
F_8 ( V_4 , V_189 -> V_190 ) ;
if ( V_4 -> V_171 . V_207 & V_208 ) {
F_1 ( V_2 , V_4 , 1 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
F_58 ( & V_4 -> V_171 ) ;
}
return 0 ;
}
static struct V_25 *
F_59 ( struct V_3 * V_4 , struct V_209 * V_210 ,
unsigned int V_161 , enum V_211 V_212 )
{
if ( V_212 == V_213 )
return F_60 ( V_210 , V_161 ) ;
else
return & V_4 -> V_27 [ V_161 ] ;
}
static void
F_61 ( struct V_3 * V_4 , struct V_209 * V_210 ,
unsigned int V_161 , struct V_25 * V_26 ,
enum V_211 V_212 )
{
enum V_214 V_215 ;
struct V_25 * V_216 ;
const struct V_217 * V_218 ;
unsigned int V_95 ;
switch ( V_161 ) {
case V_28 :
for ( V_95 = 0 ; V_95 < F_62 ( V_219 ) ; V_95 ++ ) {
if ( V_26 -> V_32 == V_219 [ V_95 ] )
break;
}
if ( V_95 >= F_62 ( V_219 ) )
V_26 -> V_32 = V_33 ;
V_26 -> V_220 = F_63 ( T_2 , V_26 -> V_220 , 1 , 8191 ) ;
V_26 -> V_221 = F_63 ( T_2 , V_26 -> V_221 , 1 , 8191 ) ;
break;
case V_170 :
V_215 = V_26 -> V_32 ;
V_216 = F_59 ( V_4 , V_210 , V_28 , V_212 ) ;
memcpy ( V_26 , V_216 , sizeof( * V_26 ) ) ;
V_218 = F_64 ( V_26 -> V_32 ) ;
if ( V_218 -> V_222 == V_215 )
V_26 -> V_32 = V_215 ;
break;
}
V_26 -> V_223 = V_224 ;
V_26 -> V_225 = V_226 ;
}
static int F_65 ( struct V_158 * V_227 ,
struct V_209 * V_210 ,
struct V_228 * V_32 )
{
struct V_3 * V_4 = F_66 ( V_227 ) ;
struct V_25 * V_216 ;
const struct V_217 * V_218 ;
if ( V_32 -> V_161 == V_28 ) {
if ( V_32 -> V_229 >= F_62 ( V_219 ) )
return - V_230 ;
V_32 -> V_32 = V_219 [ V_32 -> V_229 ] ;
} else {
V_216 = F_59 ( V_4 , V_210 , V_28 ,
V_213 ) ;
switch ( V_32 -> V_229 ) {
case 0 :
V_32 -> V_32 = V_216 -> V_32 ;
break;
case 1 :
V_218 = F_64 ( V_216 -> V_32 ) ;
if ( V_218 -> V_222 == V_216 -> V_32 )
return - V_230 ;
V_32 -> V_32 = V_218 -> V_222 ;
break;
default:
return - V_230 ;
}
}
return 0 ;
}
static int F_67 ( struct V_158 * V_227 ,
struct V_209 * V_210 ,
struct V_231 * V_232 )
{
struct V_3 * V_4 = F_66 ( V_227 ) ;
struct V_25 V_216 ;
if ( V_232 -> V_229 != 0 )
return - V_230 ;
V_216 . V_32 = V_232 -> V_32 ;
V_216 . V_220 = 1 ;
V_216 . V_221 = 1 ;
F_61 ( V_4 , V_210 , V_232 -> V_161 , & V_216 , V_213 ) ;
V_232 -> V_233 = V_216 . V_220 ;
V_232 -> V_234 = V_216 . V_221 ;
if ( V_216 . V_32 != V_232 -> V_32 )
return - V_230 ;
V_216 . V_32 = V_232 -> V_32 ;
V_216 . V_220 = - 1 ;
V_216 . V_221 = - 1 ;
F_61 ( V_4 , V_210 , V_232 -> V_161 , & V_216 , V_213 ) ;
V_232 -> V_235 = V_216 . V_220 ;
V_232 -> V_236 = V_216 . V_221 ;
return 0 ;
}
static int F_68 ( struct V_158 * V_227 , struct V_209 * V_210 ,
struct V_237 * V_26 )
{
struct V_3 * V_4 = F_66 ( V_227 ) ;
struct V_25 * V_216 ;
V_216 = F_59 ( V_4 , V_210 , V_26 -> V_161 , V_26 -> V_212 ) ;
if ( V_216 == NULL )
return - V_230 ;
V_26 -> V_216 = * V_216 ;
return 0 ;
}
static int F_69 ( struct V_158 * V_227 , struct V_209 * V_210 ,
struct V_237 * V_26 )
{
struct V_3 * V_4 = F_66 ( V_227 ) ;
struct V_25 * V_216 ;
V_216 = F_59 ( V_4 , V_210 , V_26 -> V_161 , V_26 -> V_212 ) ;
if ( V_216 == NULL )
return - V_230 ;
F_61 ( V_4 , V_210 , V_26 -> V_161 , & V_26 -> V_216 , V_26 -> V_212 ) ;
* V_216 = V_26 -> V_216 ;
if ( V_26 -> V_161 == V_28 ) {
V_216 = F_59 ( V_4 , V_210 , V_170 ,
V_26 -> V_212 ) ;
* V_216 = V_26 -> V_216 ;
F_61 ( V_4 , V_210 , V_170 , V_216 , V_26 -> V_212 ) ;
}
return 0 ;
}
static int F_70 ( struct V_158 * V_227 , struct V_209 * V_210 )
{
struct V_237 V_216 ;
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
V_216 . V_161 = V_28 ;
V_216 . V_212 = V_210 ? V_213 : V_238 ;
V_216 . V_216 . V_32 = V_33 ;
V_216 . V_216 . V_220 = 4096 ;
V_216 . V_216 . V_221 = 4096 ;
F_69 ( V_227 , V_210 , & V_216 ) ;
return 0 ;
}
static int F_71 ( struct V_158 * V_227 , int V_5 )
{
struct V_3 * V_4 = F_66 ( V_227 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_193 * V_194 = F_53 ( & V_4 -> V_195 . V_163 ) ;
struct V_204 * V_171 = & V_4 -> V_171 ;
switch ( V_5 ) {
case V_239 :
if ( F_72 ( V_4 -> V_139 ) < 0 )
return - V_138 ;
V_4 -> V_96 = V_194 -> V_196 ;
if ( V_4 -> V_42 & V_44 )
F_73 ( V_2 , V_240 ) ;
F_35 ( V_4 ) ;
F_39 ( V_4 ) ;
if ( V_4 -> V_42 & V_44 &&
! ( V_171 -> V_207 & V_241 ) )
break;
F_74 ( & V_4 -> V_203 , 0 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
F_58 ( V_171 ) ;
break;
case V_242 :
if ( V_4 -> V_243 == V_242 )
return 0 ;
if ( F_75 ( & V_227 -> V_163 , & V_4 -> V_202 ,
& V_4 -> V_203 ) )
F_40 ( V_2 -> V_174 , L_16 ,
V_227 -> V_244 ) ;
F_12 ( V_2 , V_4 , 0 , 0 ) ;
F_1 ( V_2 , V_4 , 0 ) ;
F_24 ( V_2 , V_4 , 0 ) ;
F_76 ( V_4 -> V_139 ) ;
F_58 ( V_171 ) ;
F_77 ( V_2 , V_240 ) ;
break;
}
V_4 -> V_243 = V_5 ;
return 0 ;
}
static int F_78 ( struct V_245 * V_163 ,
const struct V_160 * V_246 ,
const struct V_160 * V_247 , T_2 V_248 )
{
struct V_158 * V_227 = F_37 ( V_163 ) ;
struct V_3 * V_4 = F_66 ( V_227 ) ;
struct V_6 * V_8 = & V_4 -> V_8 ;
switch ( V_246 -> V_229 | F_79 ( V_247 -> V_163 ) ) {
case V_170 | V_249 :
if ( V_248 & V_250 ) {
if ( V_4 -> V_42 & ~ V_44 )
return - V_141 ;
V_4 -> V_42 |= V_44 ;
} else {
V_4 -> V_42 &= ~ V_44 ;
}
break;
case V_170 | V_251 :
if ( V_248 & V_250 ) {
if ( V_4 -> V_42 & ~ V_43 )
return - V_141 ;
V_4 -> V_42 |= V_43 ;
} else {
V_4 -> V_42 &= ~ V_43 ;
}
break;
default:
return - V_230 ;
}
V_8 -> V_18 =
( V_4 -> V_42 & V_44 ) ? false : true ;
V_8 -> V_16 = ! ! ( V_4 -> V_42 & V_43 ) ;
return 0 ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_158 * V_227 = & V_4 -> V_195 ;
struct V_160 * V_162 = V_4 -> V_162 ;
struct V_245 * V_252 = & V_227 -> V_163 ;
int V_253 ;
F_81 ( V_227 , & V_254 ) ;
V_227 -> V_255 = & V_256 ;
F_82 ( V_227 -> V_244 , L_17 , sizeof( V_227 -> V_244 ) ) ;
V_227 -> V_257 = 1 << 16 ;
F_83 ( V_227 , V_4 ) ;
V_227 -> V_248 |= V_258 ;
V_162 [ V_170 ] . V_248 = V_259 ;
V_162 [ V_28 ] . V_248 = V_260 ;
V_252 -> V_261 = & V_262 ;
V_253 = F_84 ( V_252 , V_263 , V_162 , 0 ) ;
if ( V_253 < 0 )
return V_253 ;
F_70 ( V_227 , NULL ) ;
V_4 -> V_171 . type = V_264 ;
V_4 -> V_171 . V_261 = & V_265 ;
V_4 -> V_171 . V_266 = 32 ;
V_4 -> V_171 . V_267 = 1 ;
V_4 -> V_171 . V_268 = 0x1ffe0 ;
V_4 -> V_171 . V_2 = V_4 -> V_2 ;
V_4 -> V_171 . V_269 = F_85 ( 4096 * 4096 ) * 3 ;
V_253 = F_86 ( & V_4 -> V_171 , L_18 ) ;
if ( V_253 < 0 )
return V_253 ;
V_253 = F_87 ( & V_4 -> V_195 . V_163 , V_170 ,
& V_4 -> V_171 . V_205 . V_163 , 0 , 0 ) ;
if ( V_253 < 0 )
return V_253 ;
return 0 ;
}
void F_88 ( struct V_3 * V_4 )
{
F_89 ( & V_4 -> V_195 . V_163 ) ;
F_90 ( & V_4 -> V_195 ) ;
F_91 ( & V_4 -> V_171 ) ;
}
int F_92 ( struct V_3 * V_4 ,
struct V_270 * V_271 )
{
int V_253 ;
V_253 = F_93 ( V_271 , & V_4 -> V_195 ) ;
if ( V_253 < 0 )
goto error;
V_253 = F_94 ( & V_4 -> V_171 , V_271 ) ;
if ( V_253 < 0 )
goto error;
return 0 ;
error:
F_88 ( V_4 ) ;
return V_253 ;
}
void F_95 ( struct V_1 * V_2 )
{
}
int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_272 = & V_2 -> V_206 ;
struct V_3 * V_273 = & V_2 -> V_274 ;
int V_253 ;
V_272 -> V_2 = V_2 ;
V_272 -> V_137 = 1 ;
V_272 -> V_9 = V_275 ;
V_272 -> V_276 = V_277 ;
V_272 -> V_139 = & V_2 -> V_278 ;
V_272 -> V_243 = V_242 ;
F_97 ( & V_272 -> V_202 ) ;
V_253 = F_80 ( V_272 ) ;
if ( V_253 < 0 )
goto V_279;
if ( V_2 -> V_47 == V_48 ) {
V_273 -> V_2 = V_2 ;
V_273 -> V_137 = 1 ;
V_273 -> V_9 = V_280 ;
V_273 -> V_276 = V_281 ;
V_273 -> V_139 = & V_2 -> V_282 ;
V_273 -> V_243 = V_242 ;
F_97 ( & V_273 -> V_202 ) ;
}
return 0 ;
V_279:
F_95 ( V_2 ) ;
return V_253 ;
}
