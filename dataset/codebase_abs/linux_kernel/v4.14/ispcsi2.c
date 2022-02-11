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
struct V_156 * V_157 = F_36 ( & V_4 -> V_158 . V_139 ) ;
const struct V_159 * V_160 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_87 * V_88 = & V_4 -> V_88 [ 0 ] ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
if ( V_4 -> V_55 [ 0 ] . V_65 || V_4 -> V_8 . V_12 )
return - V_140 ;
V_164 = F_37 ( & V_4 -> V_165 [ V_28 ] ) ;
V_162 = F_38 ( V_164 -> V_139 ) ;
V_160 = F_39 ( V_157 -> V_166 ) ;
V_4 -> V_47 = 0 ;
F_40 ( V_162 , V_162 , V_167 , & V_4 -> V_47 ) ;
V_4 -> V_8 . V_21 =
F_41 (unsigned int, pipe->l3_ick / pipe->external_rate - 1 ,
1 , 3 ) ;
F_42 ( V_2 -> V_145 , L_4 ,
V_168 , V_157 -> V_169 , V_157 -> V_170 ,
V_4 -> V_8 . V_21 ) ;
V_4 -> V_8 . V_14 = V_171 ;
V_4 -> V_8 . V_23 = V_160 -> V_172 . V_4 . V_173 ;
V_88 -> V_91 = 1 ;
V_88 -> V_90 = 1 ;
V_88 -> V_92 = 1 ;
V_88 -> V_93 = 1 ;
V_88 -> V_94 = 0x1FF ;
if ( V_4 -> V_27 [ V_28 ] . V_32 !=
V_4 -> V_27 [ V_174 ] . V_32 )
V_4 -> V_51 = true ;
else
V_4 -> V_51 = false ;
V_4 -> V_55 [ 0 ] . V_59 = F_6 ( V_4 ) ;
if ( V_4 -> V_175 . V_176 == 0 )
V_4 -> V_55 [ 0 ] . V_85 = 0 ;
else
V_4 -> V_55 [ 0 ] . V_85 = V_4 -> V_175 . V_177 ;
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
static void F_43 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_4 -> V_136 )
return;
F_42 ( V_2 -> V_145 , L_5 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_178 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_179 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_180 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_181 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_182 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_183 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_184 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_185 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_186 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_187 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_188 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_189 ) ;
F_44 ( V_2 , V_4 -> V_9 , V_190 ) ;
F_44 ( V_2 , V_4 -> V_9 , F_45 ( 0 ) ) ;
F_44 ( V_2 , V_4 -> V_9 , F_46 ( 0 ) ) ;
F_44 ( V_2 , V_4 -> V_9 , F_47 ( 0 ) ) ;
F_44 ( V_2 , V_4 -> V_9 , F_48 ( 0 ) ) ;
F_44 ( V_2 , V_4 -> V_9 , F_49 ( 0 ) ) ;
F_44 ( V_2 , V_4 -> V_9 , F_50 ( 0 ) ) ;
F_44 ( V_2 , V_4 -> V_9 , F_51 ( 0 ) ) ;
F_44 ( V_2 , V_4 -> V_9 , F_52 ( 0 ) ) ;
F_42 ( V_2 -> V_145 , L_6 ) ;
}
static void F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_191 * V_192 ;
F_12 ( V_2 , V_4 , 0 , 0 ) ;
V_192 = F_54 ( & V_4 -> V_175 ) ;
if ( V_192 == NULL )
return;
F_8 ( V_4 , V_192 -> V_193 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
}
static void F_55 ( struct V_3 * V_4 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_194 = V_54 -> V_58 ;
T_2 V_195 ;
V_195 = F_4 ( V_2 , V_4 -> V_9 , F_25 ( V_194 ) ) ;
F_5 ( V_2 , V_195 , V_4 -> V_9 , F_25 ( V_194 ) ) ;
if ( ! ( V_195 & V_96 ) )
return;
if ( V_4 -> V_47 ) {
V_4 -> V_47 -- ;
if ( V_4 -> V_47 == 0 ) {
V_54 -> V_59 = F_6 ( V_4 ) ;
F_14 ( V_2 , V_4 , V_54 ) ;
F_12 ( V_2 , V_4 , V_194 , 1 ) ;
}
return;
}
if ( V_4 -> V_43 & V_45 )
F_53 ( V_4 ) ;
}
void F_56 ( struct V_3 * V_4 )
{
struct V_156 * V_157 = F_36 ( & V_4 -> V_158 . V_139 ) ;
T_2 V_196 , V_197 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_4 -> V_136 )
return;
V_196 = F_4 ( V_2 , V_4 -> V_9 , V_133 ) ;
F_5 ( V_2 , V_196 , V_4 -> V_9 , V_133 ) ;
if ( V_196 & V_131 ) {
V_197 = F_4 ( V_2 , V_4 -> V_9 ,
V_124 ) ;
F_5 ( V_2 , V_197 ,
V_4 -> V_9 , V_124 ) ;
F_42 ( V_2 -> V_145 , L_7 ,
V_197 ) ;
V_157 -> error = true ;
}
if ( V_196 & ( V_126 |
V_127 |
V_129 |
V_130 |
V_132 ) ) {
F_42 ( V_2 -> V_145 ,
L_8 ,
( V_196 &
V_126 ) ? 1 : 0 ,
( V_196 &
V_127 ) ? 1 : 0 ,
( V_196 &
V_129 ) ? 1 : 0 ,
( V_196 &
V_130 ) ? 1 : 0 ,
( V_196 &
V_132 ) ? 1 : 0 ) ;
V_157 -> error = true ;
}
if ( F_57 ( & V_4 -> V_198 , & V_4 -> V_199 ) )
return;
if ( V_196 & F_31 ( 0 ) )
F_55 ( V_4 , & V_4 -> V_55 [ 0 ] ) ;
if ( V_196 & V_128 )
F_42 ( V_2 -> V_145 , L_9 ) ;
}
static int F_58 ( struct V_200 * V_201 , struct V_191 * V_192 )
{
struct V_1 * V_2 = V_201 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_202 ;
F_8 ( V_4 , V_192 -> V_193 ) ;
if ( V_4 -> V_175 . V_203 & V_204 ) {
F_1 ( V_2 , V_4 , 1 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
F_59 ( & V_4 -> V_175 ) ;
}
return 0 ;
}
static struct V_25 *
F_60 ( struct V_3 * V_4 , struct V_205 * V_206 ,
unsigned int V_164 , enum V_207 V_208 )
{
if ( V_208 == V_209 )
return F_61 ( & V_4 -> V_158 , V_206 , V_164 ) ;
else
return & V_4 -> V_27 [ V_164 ] ;
}
static void
F_62 ( struct V_3 * V_4 , struct V_205 * V_206 ,
unsigned int V_164 , struct V_25 * V_26 ,
enum V_207 V_208 )
{
T_2 V_210 ;
struct V_25 * V_211 ;
const struct V_212 * V_213 ;
unsigned int V_95 ;
switch ( V_164 ) {
case V_28 :
for ( V_95 = 0 ; V_95 < F_63 ( V_214 ) ; V_95 ++ ) {
if ( V_26 -> V_32 == V_214 [ V_95 ] )
break;
}
if ( V_95 >= F_63 ( V_214 ) )
V_26 -> V_32 = V_33 ;
V_26 -> V_215 = F_41 ( T_2 , V_26 -> V_215 , 1 , 8191 ) ;
V_26 -> V_216 = F_41 ( T_2 , V_26 -> V_216 , 1 , 8191 ) ;
break;
case V_174 :
V_210 = V_26 -> V_32 ;
V_211 = F_60 ( V_4 , V_206 , V_28 , V_208 ) ;
memcpy ( V_26 , V_211 , sizeof( * V_26 ) ) ;
V_213 = F_64 ( V_26 -> V_32 ) ;
if ( V_213 -> V_217 == V_210 )
V_26 -> V_32 = V_210 ;
break;
}
V_26 -> V_218 = V_219 ;
V_26 -> V_220 = V_221 ;
}
static int F_65 ( struct V_161 * V_222 ,
struct V_205 * V_206 ,
struct V_223 * V_32 )
{
struct V_3 * V_4 = F_66 ( V_222 ) ;
struct V_25 * V_211 ;
const struct V_212 * V_213 ;
if ( V_32 -> V_164 == V_28 ) {
if ( V_32 -> V_224 >= F_63 ( V_214 ) )
return - V_225 ;
V_32 -> V_32 = V_214 [ V_32 -> V_224 ] ;
} else {
V_211 = F_60 ( V_4 , V_206 , V_28 ,
V_32 -> V_208 ) ;
switch ( V_32 -> V_224 ) {
case 0 :
V_32 -> V_32 = V_211 -> V_32 ;
break;
case 1 :
V_213 = F_64 ( V_211 -> V_32 ) ;
if ( V_213 -> V_217 == V_211 -> V_32 )
return - V_225 ;
V_32 -> V_32 = V_213 -> V_217 ;
break;
default:
return - V_225 ;
}
}
return 0 ;
}
static int F_67 ( struct V_161 * V_222 ,
struct V_205 * V_206 ,
struct V_226 * V_227 )
{
struct V_3 * V_4 = F_66 ( V_222 ) ;
struct V_25 V_211 ;
if ( V_227 -> V_224 != 0 )
return - V_225 ;
V_211 . V_32 = V_227 -> V_32 ;
V_211 . V_215 = 1 ;
V_211 . V_216 = 1 ;
F_62 ( V_4 , V_206 , V_227 -> V_164 , & V_211 , V_227 -> V_208 ) ;
V_227 -> V_228 = V_211 . V_215 ;
V_227 -> V_229 = V_211 . V_216 ;
if ( V_211 . V_32 != V_227 -> V_32 )
return - V_225 ;
V_211 . V_32 = V_227 -> V_32 ;
V_211 . V_215 = - 1 ;
V_211 . V_216 = - 1 ;
F_62 ( V_4 , V_206 , V_227 -> V_164 , & V_211 , V_227 -> V_208 ) ;
V_227 -> V_230 = V_211 . V_215 ;
V_227 -> V_231 = V_211 . V_216 ;
return 0 ;
}
static int F_68 ( struct V_161 * V_222 , struct V_205 * V_206 ,
struct V_232 * V_26 )
{
struct V_3 * V_4 = F_66 ( V_222 ) ;
struct V_25 * V_211 ;
V_211 = F_60 ( V_4 , V_206 , V_26 -> V_164 , V_26 -> V_208 ) ;
if ( V_211 == NULL )
return - V_225 ;
V_26 -> V_211 = * V_211 ;
return 0 ;
}
static int F_69 ( struct V_161 * V_222 , struct V_205 * V_206 ,
struct V_232 * V_26 )
{
struct V_3 * V_4 = F_66 ( V_222 ) ;
struct V_25 * V_211 ;
V_211 = F_60 ( V_4 , V_206 , V_26 -> V_164 , V_26 -> V_208 ) ;
if ( V_211 == NULL )
return - V_225 ;
F_62 ( V_4 , V_206 , V_26 -> V_164 , & V_26 -> V_211 , V_26 -> V_208 ) ;
* V_211 = V_26 -> V_211 ;
if ( V_26 -> V_164 == V_28 ) {
V_211 = F_60 ( V_4 , V_206 , V_174 ,
V_26 -> V_208 ) ;
* V_211 = V_26 -> V_211 ;
F_62 ( V_4 , V_206 , V_174 , V_211 , V_26 -> V_208 ) ;
}
return 0 ;
}
static int F_70 ( struct V_161 * V_222 , struct V_233 * V_234 )
{
struct V_232 V_211 ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_164 = V_28 ;
V_211 . V_208 = V_234 ? V_209 : V_235 ;
V_211 . V_211 . V_32 = V_33 ;
V_211 . V_211 . V_215 = 4096 ;
V_211 . V_211 . V_216 = 4096 ;
F_69 ( V_222 , V_234 ? V_234 -> V_164 : NULL , & V_211 ) ;
return 0 ;
}
static int F_71 ( struct V_161 * V_222 , int V_5 )
{
struct V_3 * V_4 = F_66 ( V_222 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_200 * V_175 = & V_4 -> V_175 ;
switch ( V_5 ) {
case V_236 :
if ( F_72 ( V_4 -> V_138 , & V_222 -> V_139 ) < 0 )
return - V_137 ;
if ( V_4 -> V_43 & V_45 )
F_73 ( V_2 , V_237 ) ;
F_35 ( V_4 ) ;
F_43 ( V_4 ) ;
if ( V_4 -> V_43 & V_45 &&
! ( V_175 -> V_203 & V_238 ) )
break;
F_74 ( & V_4 -> V_199 , 0 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
F_59 ( V_175 ) ;
break;
case V_239 :
if ( V_4 -> V_240 == V_239 )
return 0 ;
if ( F_75 ( & V_222 -> V_139 , & V_4 -> V_198 ,
& V_4 -> V_199 ) )
F_42 ( V_2 -> V_145 , L_10 ,
V_222 -> V_241 ) ;
F_12 ( V_2 , V_4 , 0 , 0 ) ;
F_1 ( V_2 , V_4 , 0 ) ;
F_24 ( V_2 , V_4 , 0 ) ;
F_76 ( V_4 -> V_138 ) ;
F_59 ( V_175 ) ;
F_77 ( V_2 , V_237 ) ;
break;
}
V_4 -> V_240 = V_5 ;
return 0 ;
}
static int F_78 ( struct V_242 * V_139 ,
const struct V_163 * V_243 ,
const struct V_163 * V_244 , T_2 V_245 )
{
struct V_161 * V_222 = F_38 ( V_139 ) ;
struct V_3 * V_4 = F_66 ( V_222 ) ;
struct V_6 * V_8 = & V_4 -> V_8 ;
unsigned int V_224 = V_243 -> V_224 ;
if ( F_79 ( V_244 -> V_139 ) )
V_224 |= 2 << 16 ;
switch ( V_224 ) {
case V_174 :
if ( V_245 & V_246 ) {
if ( V_4 -> V_43 & ~ V_45 )
return - V_140 ;
V_4 -> V_43 |= V_45 ;
} else {
V_4 -> V_43 &= ~ V_45 ;
}
break;
case V_174 | 2 << 16 :
if ( V_245 & V_246 ) {
if ( V_4 -> V_43 & ~ V_44 )
return - V_140 ;
V_4 -> V_43 |= V_44 ;
} else {
V_4 -> V_43 &= ~ V_44 ;
}
break;
default:
return - V_225 ;
}
V_8 -> V_18 =
( V_4 -> V_43 & V_45 ) ? false : true ;
V_8 -> V_16 = ! ! ( V_4 -> V_43 & V_44 ) ;
return 0 ;
}
void F_80 ( struct V_3 * V_4 )
{
F_81 ( & V_4 -> V_158 ) ;
F_82 ( & V_4 -> V_175 ) ;
}
int F_83 ( struct V_3 * V_4 ,
struct V_247 * V_248 )
{
int V_249 ;
V_249 = F_84 ( V_248 , & V_4 -> V_158 ) ;
if ( V_249 < 0 )
goto error;
V_249 = F_85 ( & V_4 -> V_175 , V_248 ) ;
if ( V_249 < 0 )
goto error;
return 0 ;
error:
F_80 ( V_4 ) ;
return V_249 ;
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_161 * V_222 = & V_4 -> V_158 ;
struct V_163 * V_165 = V_4 -> V_165 ;
struct V_242 * V_250 = & V_222 -> V_139 ;
int V_249 ;
F_87 ( V_222 , & V_251 ) ;
V_222 -> V_252 = & V_253 ;
F_88 ( V_222 -> V_241 , L_11 , sizeof( V_222 -> V_241 ) ) ;
V_222 -> V_254 = 1 << 16 ;
F_89 ( V_222 , V_4 ) ;
V_222 -> V_245 |= V_255 ;
V_165 [ V_174 ] . V_245 = V_256 ;
V_165 [ V_28 ] . V_245 = V_257
| V_258 ;
V_250 -> V_259 = & V_260 ;
V_249 = F_90 ( V_250 , V_261 , V_165 ) ;
if ( V_249 < 0 )
return V_249 ;
F_70 ( V_222 , NULL ) ;
V_4 -> V_175 . type = V_262 ;
V_4 -> V_175 . V_259 = & V_263 ;
V_4 -> V_175 . V_264 = 32 ;
V_4 -> V_175 . V_265 = 1 ;
V_4 -> V_175 . V_266 = 0x1ffe0 ;
V_4 -> V_175 . V_2 = V_4 -> V_2 ;
V_4 -> V_175 . V_267 = F_91 ( 4096 * 4096 ) * 3 ;
V_249 = F_92 ( & V_4 -> V_175 , L_12 ) ;
if ( V_249 < 0 )
goto V_268;
return 0 ;
V_268:
F_93 ( & V_4 -> V_158 . V_139 ) ;
return V_249 ;
}
int F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_269 = & V_2 -> V_202 ;
struct V_3 * V_270 = & V_2 -> V_271 ;
int V_249 ;
V_269 -> V_2 = V_2 ;
V_269 -> V_136 = 1 ;
V_269 -> V_9 = V_272 ;
V_269 -> V_273 = V_274 ;
V_269 -> V_138 = & V_2 -> V_275 ;
V_269 -> V_240 = V_239 ;
F_95 ( & V_269 -> V_198 ) ;
V_249 = F_86 ( V_269 ) ;
if ( V_249 < 0 )
return V_249 ;
if ( V_2 -> V_48 == V_49 ) {
V_270 -> V_2 = V_2 ;
V_270 -> V_136 = 1 ;
V_270 -> V_9 = V_276 ;
V_270 -> V_273 = V_277 ;
V_270 -> V_138 = & V_2 -> V_278 ;
V_270 -> V_240 = V_239 ;
F_95 ( & V_270 -> V_198 ) ;
}
return 0 ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_269 = & V_2 -> V_202 ;
F_97 ( & V_269 -> V_175 ) ;
F_93 ( & V_269 -> V_158 . V_139 ) ;
}
