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
case V_41 :
V_29 = 2 ;
break;
default:
F_7 ( 1 , V_42 L_1 ,
V_26 -> V_32 ) ;
return 0 ;
}
if ( ! ( V_4 -> V_43 & V_44 ) &&
! ( V_4 -> V_43 & V_45 ) ) {
return V_46 ;
}
V_30 = V_4 -> V_47 ? 0 : ! ! ( V_4 -> V_43 & V_44 ) ;
V_31 = V_4 -> V_2 -> V_48 == V_49 ;
return V_50 [ V_29 ] [ V_30 ] [ V_4 -> V_51 ] [ V_31 ] ;
}
static void F_8 ( struct V_3 * V_4 , T_2 V_52 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_53 * V_54 = & V_4 -> V_55 [ 0 ] ;
V_54 -> V_56 = V_52 ;
V_54 -> V_57 = V_52 ;
F_5 ( V_2 , V_54 -> V_56 ,
V_4 -> V_9 , F_9 ( V_54 -> V_58 ) ) ;
F_5 ( V_2 , V_54 -> V_57 ,
V_4 -> V_9 , F_10 ( V_54 -> V_58 ) ) ;
}
static inline int F_11 ( T_2 V_59 )
{
return ( V_59 & 0x40 ) ? 1 : 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_58 , T_1 V_5 )
{
struct V_53 * V_54 = & V_4 -> V_55 [ V_58 ] ;
unsigned int V_60 = 0 ;
T_2 V_13 ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , F_13 ( V_58 ) ) ;
if ( V_5 ) {
if ( V_4 -> V_47 )
V_60 = V_4 -> V_47 ;
else if ( V_4 -> V_43 & V_45 )
V_60 = 1 ;
V_13 &= ~ V_61 ;
V_13 |= V_62
| ( V_60 << V_63 )
| V_64 ;
} else {
V_13 &= ~ V_64 ;
}
F_5 ( V_2 , V_13 , V_4 -> V_9 , F_13 ( V_58 ) ) ;
V_54 -> V_65 = V_5 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_53 * V_54 )
{
T_2 V_13 ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , F_13 ( V_54 -> V_58 ) ) ;
if ( V_54 -> V_66 )
V_13 |= V_67 ;
else
V_13 &= ~ V_67 ;
if ( V_54 -> V_68 )
V_13 |= V_69 ;
else
V_13 &= ~ V_69 ;
if ( V_54 -> V_70 )
V_13 |= V_71 ;
else
V_13 &= ~ V_71 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , F_13 ( V_54 -> V_58 ) ) ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , F_15 ( V_54 -> V_58 ) ) ;
V_13 &= ~ ( V_72 ) ;
V_13 |= V_54 -> V_73 << V_74 ;
V_13 &= ~ ( V_75 ) ;
V_13 |= V_54 -> V_59 << V_76 ;
if ( V_54 -> V_51 ) {
if ( V_54 -> V_77 )
V_13 |= V_78 ;
else
V_13 &= ~ V_78 ;
}
if ( F_11 ( V_54 -> V_59 ) ) {
V_13 &= ~ V_79 ;
V_13 |= 2 << V_80 ;
}
F_5 ( V_2 , V_13 , V_4 -> V_9 , F_15 ( V_54 -> V_58 ) ) ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , F_16 ( V_54 -> V_58 ) ) ;
V_13 &= ~ ( V_81 ) ;
V_13 |= ( V_54 -> V_82 << V_83 ) ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , F_16 ( V_54 -> V_58 ) ) ;
V_13 = F_4 ( V_2 , V_4 -> V_9 ,
F_17 ( V_54 -> V_58 ) ) ;
V_13 &= ~ V_84 ;
V_13 |= V_54 -> V_85 << V_86 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 ,
F_17 ( V_54 -> V_58 ) ) ;
F_5 ( V_2 , V_54 -> V_56 ,
V_4 -> V_9 , F_9 ( V_54 -> V_58 ) ) ;
F_5 ( V_2 , V_54 -> V_57 ,
V_4 -> V_9 , F_10 ( V_54 -> V_58 ) ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_88 )
{
T_2 V_13 ;
V_13 = F_4 ( V_2 , V_4 -> V_9 , V_89 ) ;
if ( V_88 -> V_90 )
V_13 |= F_19 ( V_88 -> V_91 ) ;
else
V_13 &= ~ F_19 ( V_88 -> V_91 ) ;
if ( V_88 -> V_92 )
V_13 |= F_20 ( V_88 -> V_91 ) ;
else
V_13 &= ~ F_20 ( V_88 -> V_91 ) ;
if ( V_88 -> V_93 )
V_13 |= F_21 ( V_88 -> V_91 ) ;
else
V_13 &= ~ F_21 ( V_88 -> V_91 ) ;
V_13 &= ~ F_22 ( V_88 -> V_91 ) ;
V_13 |= V_88 -> V_94 <<
F_23 ( V_88 -> V_91 ) ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_89 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < 8 ; V_95 ++ ) {
F_5 ( V_2 , V_96 , V_4 -> V_9 ,
F_25 ( V_95 ) ) ;
if ( V_5 )
F_26 ( V_2 , V_4 -> V_9 , F_27 ( V_95 ) ,
V_96 ) ;
else
F_28 ( V_2 , V_4 -> V_9 , F_27 ( V_95 ) ,
V_96 ) ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_2 V_13 ;
V_13 = V_97 |
V_98 |
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
V_123 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_124 ) ;
if ( V_5 )
V_13 |= F_4 ( V_2 , V_4 -> V_9 , V_125 ) ;
else
V_13 = 0 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_125 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_2 V_13 ;
V_13 = V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
F_31 ( 0 ) ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_133 ) ;
if ( V_5 )
V_13 |= F_4 ( V_2 , V_4 -> V_9 , V_134 ) ;
else
V_13 = 0 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_134 ) ;
}
int F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_135 = 0 ;
T_2 V_13 ;
int V_95 ;
if ( ! V_4 -> V_136 )
return - V_137 ;
if ( V_4 -> V_138 -> V_139 )
return - V_140 ;
F_26 ( V_2 , V_4 -> V_9 , V_141 ,
V_142 ) ;
do {
V_13 = F_4 ( V_2 , V_4 -> V_9 , V_143 ) &
V_144 ;
if ( V_13 == V_144 )
break;
V_135 ++ ;
if ( V_135 < 5 )
F_33 ( 100 ) ;
} while ( V_135 < 5 );
if ( V_135 == 5 ) {
F_34 ( V_2 -> V_145 , L_2 ) ;
return - V_140 ;
}
if ( V_2 -> V_48 == V_49 )
F_26 ( V_2 , V_4 -> V_9 , V_146 ,
V_147 ) ;
V_95 = 100 ;
do {
V_13 = F_4 ( V_2 , V_4 -> V_138 -> V_148 , V_149 )
& V_150 ;
if ( V_13 == V_150 )
break;
F_33 ( 100 ) ;
} while ( -- V_95 > 0 );
if ( V_95 == 0 ) {
F_34 ( V_2 -> V_145 ,
L_3 ) ;
return - V_140 ;
}
if ( V_2 -> V_151 )
F_2 ( V_2 , V_4 -> V_9 , V_141 ,
V_152 |
V_153 ,
V_154 |
( ( V_2 -> V_48 == V_49 ) ?
V_153 : 0 ) ) ;
else
F_2 ( V_2 , V_4 -> V_9 , V_141 ,
V_152 |
V_153 ,
V_155 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_156 * V_157 = F_36 ( & V_4 -> V_158 . V_159 ) ;
const struct V_160 * V_161 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_87 * V_88 = & V_4 -> V_88 [ 0 ] ;
struct V_162 * V_163 ;
struct V_164 * V_165 ;
if ( V_4 -> V_55 [ 0 ] . V_65 || V_4 -> V_8 . V_12 )
return - V_140 ;
V_165 = F_37 ( & V_4 -> V_166 [ V_28 ] ) ;
V_163 = F_38 ( V_165 -> V_159 ) ;
V_161 = V_163 -> V_167 ;
V_4 -> V_47 = 0 ;
F_39 ( V_163 , V_163 , V_168 , & V_4 -> V_47 ) ;
V_4 -> V_8 . V_21 =
F_40 (unsigned int, pipe->l3_ick / pipe->external_rate - 1 ,
1 , 3 ) ;
F_41 ( V_2 -> V_145 , L_4 ,
V_169 , V_157 -> V_170 , V_157 -> V_171 ,
V_4 -> V_8 . V_21 ) ;
V_4 -> V_8 . V_14 = V_172 ;
V_4 -> V_8 . V_23 = V_161 -> V_173 . V_4 . V_174 ;
V_88 -> V_91 = 1 ;
V_88 -> V_90 = 1 ;
V_88 -> V_92 = 1 ;
V_88 -> V_93 = 1 ;
V_88 -> V_94 = 0x1FF ;
if ( V_4 -> V_27 [ V_28 ] . V_32 !=
V_4 -> V_27 [ V_175 ] . V_32 )
V_4 -> V_51 = true ;
else
V_4 -> V_51 = false ;
V_4 -> V_55 [ 0 ] . V_59 = F_6 ( V_4 ) ;
if ( V_4 -> V_176 . V_177 == 0 )
V_4 -> V_55 [ 0 ] . V_85 = 0 ;
else
V_4 -> V_55 [ 0 ] . V_85 = V_4 -> V_176 . V_178 ;
V_4 -> V_55 [ 0 ] . V_66 = 1 ;
V_4 -> V_55 [ 0 ] . V_68 = 1 ;
F_29 ( V_2 , V_4 , 1 ) ;
F_24 ( V_2 , V_4 , 1 ) ;
F_30 ( V_2 , V_4 , 1 ) ;
F_18 ( V_2 , V_4 , V_88 ) ;
F_3 ( V_2 , V_4 , & V_4 -> V_8 ) ;
F_14 ( V_2 , V_4 , & V_4 -> V_55 [ 0 ] ) ;
return 0 ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_4 -> V_136 )
return;
F_41 ( V_2 -> V_145 , L_5 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_179 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_180 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_181 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_182 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_183 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_184 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_185 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_186 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_187 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_188 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_189 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_190 ) ;
F_43 ( V_2 , V_4 -> V_9 , V_191 ) ;
F_43 ( V_2 , V_4 -> V_9 , F_44 ( 0 ) ) ;
F_43 ( V_2 , V_4 -> V_9 , F_45 ( 0 ) ) ;
F_43 ( V_2 , V_4 -> V_9 , F_46 ( 0 ) ) ;
F_43 ( V_2 , V_4 -> V_9 , F_47 ( 0 ) ) ;
F_43 ( V_2 , V_4 -> V_9 , F_48 ( 0 ) ) ;
F_43 ( V_2 , V_4 -> V_9 , F_49 ( 0 ) ) ;
F_43 ( V_2 , V_4 -> V_9 , F_50 ( 0 ) ) ;
F_43 ( V_2 , V_4 -> V_9 , F_51 ( 0 ) ) ;
F_41 ( V_2 -> V_145 , L_6 ) ;
}
static void F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_192 * V_193 ;
F_12 ( V_2 , V_4 , 0 , 0 ) ;
V_193 = F_53 ( & V_4 -> V_176 ) ;
if ( V_193 == NULL )
return;
F_8 ( V_4 , V_193 -> V_194 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
}
static void F_54 ( struct V_3 * V_4 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_195 = V_54 -> V_58 ;
T_2 V_196 ;
V_196 = F_4 ( V_2 , V_4 -> V_9 , F_25 ( V_195 ) ) ;
F_5 ( V_2 , V_196 , V_4 -> V_9 , F_25 ( V_195 ) ) ;
if ( ! ( V_196 & V_96 ) )
return;
if ( V_4 -> V_47 ) {
V_4 -> V_47 -- ;
if ( V_4 -> V_47 == 0 ) {
V_54 -> V_59 = F_6 ( V_4 ) ;
F_14 ( V_2 , V_4 , V_54 ) ;
F_12 ( V_2 , V_4 , V_195 , 1 ) ;
}
return;
}
if ( V_4 -> V_43 & V_45 )
F_52 ( V_4 ) ;
}
void F_55 ( struct V_3 * V_4 )
{
struct V_156 * V_157 = F_36 ( & V_4 -> V_158 . V_159 ) ;
T_2 V_197 , V_198 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_4 -> V_136 )
return;
V_197 = F_4 ( V_2 , V_4 -> V_9 , V_133 ) ;
F_5 ( V_2 , V_197 , V_4 -> V_9 , V_133 ) ;
if ( V_197 & V_131 ) {
V_198 = F_4 ( V_2 , V_4 -> V_9 ,
V_124 ) ;
F_5 ( V_2 , V_198 ,
V_4 -> V_9 , V_124 ) ;
F_41 ( V_2 -> V_145 , L_7
L_8 , V_198 ) ;
V_157 -> error = true ;
}
if ( V_197 & ( V_126 |
V_127 |
V_129 |
V_130 |
V_132 ) ) {
F_41 ( V_2 -> V_145 , L_9
L_10
L_11
L_12
L_13
L_14
L_15 ,
( V_197 &
V_126 ) ? 1 : 0 ,
( V_197 &
V_127 ) ? 1 : 0 ,
( V_197 &
V_129 ) ? 1 : 0 ,
( V_197 &
V_130 ) ? 1 : 0 ,
( V_197 &
V_132 ) ? 1 : 0 ) ;
V_157 -> error = true ;
}
if ( F_56 ( & V_4 -> V_199 , & V_4 -> V_200 ) )
return;
if ( V_197 & F_31 ( 0 ) )
F_54 ( V_4 , & V_4 -> V_55 [ 0 ] ) ;
if ( V_197 & V_128 )
F_41 ( V_2 -> V_145 , L_16 ) ;
}
static int F_57 ( struct V_201 * V_202 , struct V_192 * V_193 )
{
struct V_1 * V_2 = V_202 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_203 ;
F_8 ( V_4 , V_193 -> V_194 ) ;
if ( V_4 -> V_176 . V_204 & V_205 ) {
F_1 ( V_2 , V_4 , 1 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
F_58 ( & V_4 -> V_176 ) ;
}
return 0 ;
}
static struct V_25 *
F_59 ( struct V_3 * V_4 , struct V_206 * V_207 ,
unsigned int V_165 , enum V_208 V_209 )
{
if ( V_209 == V_210 )
return F_60 ( & V_4 -> V_158 , V_207 , V_165 ) ;
else
return & V_4 -> V_27 [ V_165 ] ;
}
static void
F_61 ( struct V_3 * V_4 , struct V_206 * V_207 ,
unsigned int V_165 , struct V_25 * V_26 ,
enum V_208 V_209 )
{
T_2 V_211 ;
struct V_25 * V_212 ;
const struct V_213 * V_214 ;
unsigned int V_95 ;
switch ( V_165 ) {
case V_28 :
for ( V_95 = 0 ; V_95 < F_62 ( V_215 ) ; V_95 ++ ) {
if ( V_26 -> V_32 == V_215 [ V_95 ] )
break;
}
if ( V_95 >= F_62 ( V_215 ) )
V_26 -> V_32 = V_33 ;
V_26 -> V_216 = F_40 ( T_2 , V_26 -> V_216 , 1 , 8191 ) ;
V_26 -> V_217 = F_40 ( T_2 , V_26 -> V_217 , 1 , 8191 ) ;
break;
case V_175 :
V_211 = V_26 -> V_32 ;
V_212 = F_59 ( V_4 , V_207 , V_28 , V_209 ) ;
memcpy ( V_26 , V_212 , sizeof( * V_26 ) ) ;
V_214 = F_63 ( V_26 -> V_32 ) ;
if ( V_214 -> V_218 == V_211 )
V_26 -> V_32 = V_211 ;
break;
}
V_26 -> V_219 = V_220 ;
V_26 -> V_221 = V_222 ;
}
static int F_64 ( struct V_162 * V_223 ,
struct V_206 * V_207 ,
struct V_224 * V_32 )
{
struct V_3 * V_4 = F_65 ( V_223 ) ;
struct V_25 * V_212 ;
const struct V_213 * V_214 ;
if ( V_32 -> V_165 == V_28 ) {
if ( V_32 -> V_225 >= F_62 ( V_215 ) )
return - V_226 ;
V_32 -> V_32 = V_215 [ V_32 -> V_225 ] ;
} else {
V_212 = F_59 ( V_4 , V_207 , V_28 ,
V_32 -> V_209 ) ;
switch ( V_32 -> V_225 ) {
case 0 :
V_32 -> V_32 = V_212 -> V_32 ;
break;
case 1 :
V_214 = F_63 ( V_212 -> V_32 ) ;
if ( V_214 -> V_218 == V_212 -> V_32 )
return - V_226 ;
V_32 -> V_32 = V_214 -> V_218 ;
break;
default:
return - V_226 ;
}
}
return 0 ;
}
static int F_66 ( struct V_162 * V_223 ,
struct V_206 * V_207 ,
struct V_227 * V_228 )
{
struct V_3 * V_4 = F_65 ( V_223 ) ;
struct V_25 V_212 ;
if ( V_228 -> V_225 != 0 )
return - V_226 ;
V_212 . V_32 = V_228 -> V_32 ;
V_212 . V_216 = 1 ;
V_212 . V_217 = 1 ;
F_61 ( V_4 , V_207 , V_228 -> V_165 , & V_212 , V_228 -> V_209 ) ;
V_228 -> V_229 = V_212 . V_216 ;
V_228 -> V_230 = V_212 . V_217 ;
if ( V_212 . V_32 != V_228 -> V_32 )
return - V_226 ;
V_212 . V_32 = V_228 -> V_32 ;
V_212 . V_216 = - 1 ;
V_212 . V_217 = - 1 ;
F_61 ( V_4 , V_207 , V_228 -> V_165 , & V_212 , V_228 -> V_209 ) ;
V_228 -> V_231 = V_212 . V_216 ;
V_228 -> V_232 = V_212 . V_217 ;
return 0 ;
}
static int F_67 ( struct V_162 * V_223 , struct V_206 * V_207 ,
struct V_233 * V_26 )
{
struct V_3 * V_4 = F_65 ( V_223 ) ;
struct V_25 * V_212 ;
V_212 = F_59 ( V_4 , V_207 , V_26 -> V_165 , V_26 -> V_209 ) ;
if ( V_212 == NULL )
return - V_226 ;
V_26 -> V_212 = * V_212 ;
return 0 ;
}
static int F_68 ( struct V_162 * V_223 , struct V_206 * V_207 ,
struct V_233 * V_26 )
{
struct V_3 * V_4 = F_65 ( V_223 ) ;
struct V_25 * V_212 ;
V_212 = F_59 ( V_4 , V_207 , V_26 -> V_165 , V_26 -> V_209 ) ;
if ( V_212 == NULL )
return - V_226 ;
F_61 ( V_4 , V_207 , V_26 -> V_165 , & V_26 -> V_212 , V_26 -> V_209 ) ;
* V_212 = V_26 -> V_212 ;
if ( V_26 -> V_165 == V_28 ) {
V_212 = F_59 ( V_4 , V_207 , V_175 ,
V_26 -> V_209 ) ;
* V_212 = V_26 -> V_212 ;
F_61 ( V_4 , V_207 , V_175 , V_212 , V_26 -> V_209 ) ;
}
return 0 ;
}
static int F_69 ( struct V_162 * V_223 , struct V_234 * V_235 )
{
struct V_233 V_212 ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_165 = V_28 ;
V_212 . V_209 = V_235 ? V_210 : V_236 ;
V_212 . V_212 . V_32 = V_33 ;
V_212 . V_212 . V_216 = 4096 ;
V_212 . V_212 . V_217 = 4096 ;
F_68 ( V_223 , V_235 ? V_235 -> V_165 : NULL , & V_212 ) ;
return 0 ;
}
static int F_70 ( struct V_162 * V_223 , int V_5 )
{
struct V_3 * V_4 = F_65 ( V_223 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_201 * V_176 = & V_4 -> V_176 ;
switch ( V_5 ) {
case V_237 :
if ( F_71 ( V_4 -> V_138 ) < 0 )
return - V_137 ;
if ( V_4 -> V_43 & V_45 )
F_72 ( V_2 , V_238 ) ;
F_35 ( V_4 ) ;
F_42 ( V_4 ) ;
if ( V_4 -> V_43 & V_45 &&
! ( V_176 -> V_204 & V_239 ) )
break;
F_73 ( & V_4 -> V_200 , 0 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
F_58 ( V_176 ) ;
break;
case V_240 :
if ( V_4 -> V_241 == V_240 )
return 0 ;
if ( F_74 ( & V_223 -> V_159 , & V_4 -> V_199 ,
& V_4 -> V_200 ) )
F_41 ( V_2 -> V_145 , L_17 ,
V_223 -> V_242 ) ;
F_12 ( V_2 , V_4 , 0 , 0 ) ;
F_1 ( V_2 , V_4 , 0 ) ;
F_24 ( V_2 , V_4 , 0 ) ;
F_75 ( V_4 -> V_138 ) ;
F_58 ( V_176 ) ;
F_76 ( V_2 , V_238 ) ;
break;
}
V_4 -> V_241 = V_5 ;
return 0 ;
}
static int F_77 ( struct V_243 * V_159 ,
const struct V_164 * V_244 ,
const struct V_164 * V_245 , T_2 V_246 )
{
struct V_162 * V_223 = F_38 ( V_159 ) ;
struct V_3 * V_4 = F_65 ( V_223 ) ;
struct V_6 * V_8 = & V_4 -> V_8 ;
unsigned int V_225 = V_244 -> V_225 ;
if ( F_78 ( V_245 -> V_159 ) )
V_225 |= 2 << 16 ;
switch ( V_225 ) {
case V_175 :
if ( V_246 & V_247 ) {
if ( V_4 -> V_43 & ~ V_45 )
return - V_140 ;
V_4 -> V_43 |= V_45 ;
} else {
V_4 -> V_43 &= ~ V_45 ;
}
break;
case V_175 | 2 << 16 :
if ( V_246 & V_247 ) {
if ( V_4 -> V_43 & ~ V_44 )
return - V_140 ;
V_4 -> V_43 |= V_44 ;
} else {
V_4 -> V_43 &= ~ V_44 ;
}
break;
default:
return - V_226 ;
}
V_8 -> V_18 =
( V_4 -> V_43 & V_45 ) ? false : true ;
V_8 -> V_16 = ! ! ( V_4 -> V_43 & V_44 ) ;
return 0 ;
}
void F_79 ( struct V_3 * V_4 )
{
F_80 ( & V_4 -> V_158 ) ;
F_81 ( & V_4 -> V_176 ) ;
}
int F_82 ( struct V_3 * V_4 ,
struct V_248 * V_249 )
{
int V_250 ;
V_250 = F_83 ( V_249 , & V_4 -> V_158 ) ;
if ( V_250 < 0 )
goto error;
V_250 = F_84 ( & V_4 -> V_176 , V_249 ) ;
if ( V_250 < 0 )
goto error;
return 0 ;
error:
F_79 ( V_4 ) ;
return V_250 ;
}
static int F_85 ( struct V_3 * V_4 )
{
struct V_162 * V_223 = & V_4 -> V_158 ;
struct V_164 * V_166 = V_4 -> V_166 ;
struct V_243 * V_251 = & V_223 -> V_159 ;
int V_250 ;
F_86 ( V_223 , & V_252 ) ;
V_223 -> V_253 = & V_254 ;
F_87 ( V_223 -> V_242 , L_18 , sizeof( V_223 -> V_242 ) ) ;
V_223 -> V_255 = 1 << 16 ;
F_88 ( V_223 , V_4 ) ;
V_223 -> V_246 |= V_256 ;
V_166 [ V_175 ] . V_246 = V_257 ;
V_166 [ V_28 ] . V_246 = V_258
| V_259 ;
V_251 -> V_260 = & V_261 ;
V_250 = F_89 ( V_251 , V_262 , V_166 ) ;
if ( V_250 < 0 )
return V_250 ;
F_69 ( V_223 , NULL ) ;
V_4 -> V_176 . type = V_263 ;
V_4 -> V_176 . V_260 = & V_264 ;
V_4 -> V_176 . V_265 = 32 ;
V_4 -> V_176 . V_266 = 1 ;
V_4 -> V_176 . V_267 = 0x1ffe0 ;
V_4 -> V_176 . V_2 = V_4 -> V_2 ;
V_4 -> V_176 . V_268 = F_90 ( 4096 * 4096 ) * 3 ;
V_250 = F_91 ( & V_4 -> V_176 , L_19 ) ;
if ( V_250 < 0 )
goto V_269;
return 0 ;
V_269:
F_92 ( & V_4 -> V_158 . V_159 ) ;
return V_250 ;
}
int F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_270 = & V_2 -> V_203 ;
struct V_3 * V_271 = & V_2 -> V_272 ;
int V_250 ;
V_270 -> V_2 = V_2 ;
V_270 -> V_136 = 1 ;
V_270 -> V_9 = V_273 ;
V_270 -> V_274 = V_275 ;
V_270 -> V_138 = & V_2 -> V_276 ;
V_270 -> V_241 = V_240 ;
F_94 ( & V_270 -> V_199 ) ;
V_250 = F_85 ( V_270 ) ;
if ( V_250 < 0 )
return V_250 ;
if ( V_2 -> V_48 == V_49 ) {
V_271 -> V_2 = V_2 ;
V_271 -> V_136 = 1 ;
V_271 -> V_9 = V_277 ;
V_271 -> V_274 = V_278 ;
V_271 -> V_138 = & V_2 -> V_279 ;
V_271 -> V_241 = V_240 ;
F_94 ( & V_271 -> V_199 ) ;
}
return 0 ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_270 = & V_2 -> V_203 ;
F_96 ( & V_270 -> V_176 ) ;
F_92 ( & V_270 -> V_158 . V_159 ) ;
}
