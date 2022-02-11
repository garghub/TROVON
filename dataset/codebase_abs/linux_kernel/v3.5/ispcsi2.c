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
int V_94 ;
for ( V_94 = 0 ; V_94 < 8 ; V_94 ++ ) {
F_5 ( V_2 , V_95 , V_4 -> V_9 ,
F_25 ( V_94 ) ) ;
if ( V_5 )
F_26 ( V_2 , V_4 -> V_9 , F_27 ( V_94 ) ,
V_95 ) ;
else
F_28 ( V_2 , V_4 -> V_9 , F_27 ( V_94 ) ,
V_95 ) ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_2 V_13 ;
V_13 = V_96 |
V_97 |
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
V_122 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_123 ) ;
if ( V_5 )
V_13 |= F_4 ( V_2 , V_4 -> V_9 , V_124 ) ;
else
V_13 = 0 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_124 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_2 V_13 ;
V_13 = V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
F_31 ( 0 ) ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_132 ) ;
if ( V_5 )
V_13 |= F_4 ( V_2 , V_4 -> V_9 , V_133 ) ;
else
V_13 = 0 ;
F_5 ( V_2 , V_13 , V_4 -> V_9 , V_133 ) ;
}
int F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_134 = 0 ;
T_2 V_13 ;
int V_94 ;
if ( ! V_4 -> V_135 )
return - V_136 ;
if ( V_4 -> V_137 -> V_138 )
return - V_139 ;
F_26 ( V_2 , V_4 -> V_9 , V_140 ,
V_141 ) ;
do {
V_13 = F_4 ( V_2 , V_4 -> V_9 , V_142 ) &
V_143 ;
if ( V_13 == V_143 )
break;
V_134 ++ ;
if ( V_134 < 5 )
F_33 ( 100 ) ;
} while ( V_134 < 5 );
if ( V_134 == 5 ) {
F_34 ( V_41 L_2 ) ;
return - V_139 ;
}
if ( V_2 -> V_47 == V_48 )
F_26 ( V_2 , V_4 -> V_9 , V_144 ,
V_145 ) ;
V_94 = 100 ;
do {
V_13 = F_4 ( V_2 , V_4 -> V_137 -> V_146 , V_147 )
& V_148 ;
if ( V_13 == V_148 )
break;
F_33 ( 100 ) ;
} while ( -- V_94 > 0 );
if ( V_94 == 0 ) {
F_34 ( V_41
L_3 ) ;
return - V_139 ;
}
if ( V_2 -> V_149 )
F_2 ( V_2 , V_4 -> V_9 , V_140 ,
V_150 |
V_151 ,
V_152 |
( ( V_2 -> V_47 == V_48 ) ?
V_151 : 0 ) ) ;
else
F_2 ( V_2 , V_4 -> V_9 , V_140 ,
V_150 |
V_151 ,
V_153 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
const struct V_154 * V_155 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_86 * V_87 = & V_4 -> V_87 [ 0 ] ;
struct V_156 * V_157 ;
struct V_158 * V_159 ;
if ( V_4 -> V_54 [ 0 ] . V_64 || V_4 -> V_8 . V_12 )
return - V_139 ;
V_159 = F_36 ( & V_4 -> V_160 [ V_28 ] ) ;
V_157 = F_37 ( V_159 -> V_161 ) ;
V_155 = V_157 -> V_162 ;
V_4 -> V_46 = 0 ;
F_38 ( V_157 , V_157 , V_163 , & V_4 -> V_46 ) ;
V_4 -> V_8 . V_21 = V_155 -> V_164 . V_4 . V_165 ;
V_4 -> V_8 . V_14 = V_166 ;
V_4 -> V_8 . V_23 = V_155 -> V_164 . V_4 . V_167 ;
V_87 -> V_90 = 1 ;
V_87 -> V_89 = 1 ;
V_87 -> V_91 = 1 ;
V_87 -> V_92 = 1 ;
V_87 -> V_93 = 0x1FF ;
if ( V_4 -> V_27 [ V_28 ] . V_32 !=
V_4 -> V_27 [ V_168 ] . V_32 )
V_4 -> V_50 = true ;
else
V_4 -> V_50 = false ;
V_4 -> V_54 [ 0 ] . V_58 = F_6 ( V_4 ) ;
if ( V_4 -> V_169 . V_170 == 0 )
V_4 -> V_54 [ 0 ] . V_84 = 0 ;
else
V_4 -> V_54 [ 0 ] . V_84 = V_4 -> V_169 . V_171 ;
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
if ( ! V_4 -> V_135 )
return;
F_40 ( V_2 -> V_172 , L_4 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_173 ) ;
F_41 ( V_2 , V_4 -> V_9 , V_174 ) ;
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
F_41 ( V_2 , V_4 -> V_9 , F_42 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_43 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_44 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_45 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_46 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_47 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_48 ( 0 ) ) ;
F_41 ( V_2 , V_4 -> V_9 , F_49 ( 0 ) ) ;
F_40 ( V_2 -> V_172 , L_5 ) ;
}
static void F_50 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_186 * V_187 ;
F_12 ( V_2 , V_4 , 0 , 0 ) ;
V_187 = F_51 ( & V_4 -> V_169 ) ;
if ( V_187 == NULL )
return;
F_8 ( V_4 , V_187 -> V_188 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
}
static void F_52 ( struct V_3 * V_4 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_189 = V_53 -> V_57 ;
T_2 V_190 ;
V_190 = F_4 ( V_2 , V_4 -> V_9 , F_25 ( V_189 ) ) ;
F_5 ( V_2 , V_190 , V_4 -> V_9 , F_25 ( V_189 ) ) ;
if ( ! ( V_190 & V_95 ) )
return;
if ( V_4 -> V_46 ) {
V_4 -> V_46 -- ;
if ( V_4 -> V_46 == 0 ) {
V_53 -> V_58 = F_6 ( V_4 ) ;
F_14 ( V_2 , V_4 , V_53 ) ;
F_12 ( V_2 , V_4 , V_189 , 1 ) ;
}
return;
}
if ( V_4 -> V_42 & V_44 )
F_50 ( V_4 ) ;
}
void F_53 ( struct V_3 * V_4 )
{
struct V_191 * V_192 = F_54 ( & V_4 -> V_193 . V_161 ) ;
T_2 V_194 , V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_4 -> V_135 )
return;
V_194 = F_4 ( V_2 , V_4 -> V_9 , V_132 ) ;
F_5 ( V_2 , V_194 , V_4 -> V_9 , V_132 ) ;
if ( V_194 & V_130 ) {
V_195 = F_4 ( V_2 , V_4 -> V_9 ,
V_123 ) ;
F_5 ( V_2 , V_195 ,
V_4 -> V_9 , V_123 ) ;
F_40 ( V_2 -> V_172 , L_6
L_7 , V_195 ) ;
V_192 -> error = true ;
}
if ( V_194 & ( V_125 |
V_126 |
V_128 |
V_129 |
V_131 ) ) {
F_40 ( V_2 -> V_172 , L_8
L_9
L_10
L_11
L_12
L_13
L_14 ,
( V_194 &
V_125 ) ? 1 : 0 ,
( V_194 &
V_126 ) ? 1 : 0 ,
( V_194 &
V_128 ) ? 1 : 0 ,
( V_194 &
V_129 ) ? 1 : 0 ,
( V_194 &
V_131 ) ? 1 : 0 ) ;
V_192 -> error = true ;
}
if ( F_55 ( & V_4 -> V_196 , & V_4 -> V_197 ) )
return;
if ( V_194 & F_31 ( 0 ) )
F_52 ( V_4 , & V_4 -> V_54 [ 0 ] ) ;
if ( V_194 & V_127 )
F_40 ( V_2 -> V_172 , L_15 ) ;
}
static int F_56 ( struct V_198 * V_199 , struct V_186 * V_187 )
{
struct V_1 * V_2 = V_199 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_200 ;
F_8 ( V_4 , V_187 -> V_188 ) ;
if ( V_4 -> V_169 . V_201 & V_202 ) {
F_1 ( V_2 , V_4 , 1 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
F_57 ( & V_4 -> V_169 ) ;
}
return 0 ;
}
static struct V_25 *
F_58 ( struct V_3 * V_4 , struct V_203 * V_204 ,
unsigned int V_159 , enum V_205 V_206 )
{
if ( V_206 == V_207 )
return F_59 ( V_204 , V_159 ) ;
else
return & V_4 -> V_27 [ V_159 ] ;
}
static void
F_60 ( struct V_3 * V_4 , struct V_203 * V_204 ,
unsigned int V_159 , struct V_25 * V_26 ,
enum V_205 V_206 )
{
enum V_208 V_209 ;
struct V_25 * V_210 ;
const struct V_211 * V_212 ;
unsigned int V_94 ;
switch ( V_159 ) {
case V_28 :
for ( V_94 = 0 ; V_94 < F_61 ( V_213 ) ; V_94 ++ ) {
if ( V_26 -> V_32 == V_213 [ V_94 ] )
break;
}
if ( V_94 >= F_61 ( V_213 ) )
V_26 -> V_32 = V_33 ;
V_26 -> V_214 = F_62 ( T_2 , V_26 -> V_214 , 1 , 8191 ) ;
V_26 -> V_215 = F_62 ( T_2 , V_26 -> V_215 , 1 , 8191 ) ;
break;
case V_168 :
V_209 = V_26 -> V_32 ;
V_210 = F_58 ( V_4 , V_204 , V_28 , V_206 ) ;
memcpy ( V_26 , V_210 , sizeof( * V_26 ) ) ;
V_212 = F_63 ( V_26 -> V_32 ) ;
if ( V_212 -> V_216 == V_209 )
V_26 -> V_32 = V_209 ;
break;
}
V_26 -> V_217 = V_218 ;
V_26 -> V_219 = V_220 ;
}
static int F_64 ( struct V_156 * V_221 ,
struct V_203 * V_204 ,
struct V_222 * V_32 )
{
struct V_3 * V_4 = F_65 ( V_221 ) ;
struct V_25 * V_210 ;
const struct V_211 * V_212 ;
if ( V_32 -> V_159 == V_28 ) {
if ( V_32 -> V_223 >= F_61 ( V_213 ) )
return - V_224 ;
V_32 -> V_32 = V_213 [ V_32 -> V_223 ] ;
} else {
V_210 = F_58 ( V_4 , V_204 , V_28 ,
V_207 ) ;
switch ( V_32 -> V_223 ) {
case 0 :
V_32 -> V_32 = V_210 -> V_32 ;
break;
case 1 :
V_212 = F_63 ( V_210 -> V_32 ) ;
if ( V_212 -> V_216 == V_210 -> V_32 )
return - V_224 ;
V_32 -> V_32 = V_212 -> V_216 ;
break;
default:
return - V_224 ;
}
}
return 0 ;
}
static int F_66 ( struct V_156 * V_221 ,
struct V_203 * V_204 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 = F_65 ( V_221 ) ;
struct V_25 V_210 ;
if ( V_226 -> V_223 != 0 )
return - V_224 ;
V_210 . V_32 = V_226 -> V_32 ;
V_210 . V_214 = 1 ;
V_210 . V_215 = 1 ;
F_60 ( V_4 , V_204 , V_226 -> V_159 , & V_210 , V_207 ) ;
V_226 -> V_227 = V_210 . V_214 ;
V_226 -> V_228 = V_210 . V_215 ;
if ( V_210 . V_32 != V_226 -> V_32 )
return - V_224 ;
V_210 . V_32 = V_226 -> V_32 ;
V_210 . V_214 = - 1 ;
V_210 . V_215 = - 1 ;
F_60 ( V_4 , V_204 , V_226 -> V_159 , & V_210 , V_207 ) ;
V_226 -> V_229 = V_210 . V_214 ;
V_226 -> V_230 = V_210 . V_215 ;
return 0 ;
}
static int F_67 ( struct V_156 * V_221 , struct V_203 * V_204 ,
struct V_231 * V_26 )
{
struct V_3 * V_4 = F_65 ( V_221 ) ;
struct V_25 * V_210 ;
V_210 = F_58 ( V_4 , V_204 , V_26 -> V_159 , V_26 -> V_206 ) ;
if ( V_210 == NULL )
return - V_224 ;
V_26 -> V_210 = * V_210 ;
return 0 ;
}
static int F_68 ( struct V_156 * V_221 , struct V_203 * V_204 ,
struct V_231 * V_26 )
{
struct V_3 * V_4 = F_65 ( V_221 ) ;
struct V_25 * V_210 ;
V_210 = F_58 ( V_4 , V_204 , V_26 -> V_159 , V_26 -> V_206 ) ;
if ( V_210 == NULL )
return - V_224 ;
F_60 ( V_4 , V_204 , V_26 -> V_159 , & V_26 -> V_210 , V_26 -> V_206 ) ;
* V_210 = V_26 -> V_210 ;
if ( V_26 -> V_159 == V_28 ) {
V_210 = F_58 ( V_4 , V_204 , V_168 ,
V_26 -> V_206 ) ;
* V_210 = V_26 -> V_210 ;
F_60 ( V_4 , V_204 , V_168 , V_210 , V_26 -> V_206 ) ;
}
return 0 ;
}
static int F_69 ( struct V_156 * V_221 , struct V_203 * V_204 )
{
struct V_231 V_210 ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
V_210 . V_159 = V_28 ;
V_210 . V_206 = V_204 ? V_207 : V_232 ;
V_210 . V_210 . V_32 = V_33 ;
V_210 . V_210 . V_214 = 4096 ;
V_210 . V_210 . V_215 = 4096 ;
F_68 ( V_221 , V_204 , & V_210 ) ;
return 0 ;
}
static int F_70 ( struct V_156 * V_221 , int V_5 )
{
struct V_3 * V_4 = F_65 ( V_221 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_198 * V_169 = & V_4 -> V_169 ;
switch ( V_5 ) {
case V_233 :
if ( F_71 ( V_4 -> V_137 ) < 0 )
return - V_136 ;
if ( V_4 -> V_42 & V_44 )
F_72 ( V_2 , V_234 ) ;
F_35 ( V_4 ) ;
F_39 ( V_4 ) ;
if ( V_4 -> V_42 & V_44 &&
! ( V_169 -> V_201 & V_235 ) )
break;
F_73 ( & V_4 -> V_197 , 0 ) ;
F_12 ( V_2 , V_4 , 0 , 1 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
F_57 ( V_169 ) ;
break;
case V_236 :
if ( V_4 -> V_237 == V_236 )
return 0 ;
if ( F_74 ( & V_221 -> V_161 , & V_4 -> V_196 ,
& V_4 -> V_197 ) )
F_40 ( V_2 -> V_172 , L_16 ,
V_221 -> V_238 ) ;
F_12 ( V_2 , V_4 , 0 , 0 ) ;
F_1 ( V_2 , V_4 , 0 ) ;
F_24 ( V_2 , V_4 , 0 ) ;
F_75 ( V_4 -> V_137 ) ;
F_57 ( V_169 ) ;
F_76 ( V_2 , V_234 ) ;
break;
}
V_4 -> V_237 = V_5 ;
return 0 ;
}
static int F_77 ( struct V_239 * V_161 ,
const struct V_158 * V_240 ,
const struct V_158 * V_241 , T_2 V_242 )
{
struct V_156 * V_221 = F_37 ( V_161 ) ;
struct V_3 * V_4 = F_65 ( V_221 ) ;
struct V_6 * V_8 = & V_4 -> V_8 ;
switch ( V_240 -> V_223 | F_78 ( V_241 -> V_161 ) ) {
case V_168 | V_243 :
if ( V_242 & V_244 ) {
if ( V_4 -> V_42 & ~ V_44 )
return - V_139 ;
V_4 -> V_42 |= V_44 ;
} else {
V_4 -> V_42 &= ~ V_44 ;
}
break;
case V_168 | V_245 :
if ( V_242 & V_244 ) {
if ( V_4 -> V_42 & ~ V_43 )
return - V_139 ;
V_4 -> V_42 |= V_43 ;
} else {
V_4 -> V_42 &= ~ V_43 ;
}
break;
default:
return - V_224 ;
}
V_8 -> V_18 =
( V_4 -> V_42 & V_44 ) ? false : true ;
V_8 -> V_16 = ! ! ( V_4 -> V_42 & V_43 ) ;
return 0 ;
}
void F_79 ( struct V_3 * V_4 )
{
F_80 ( & V_4 -> V_193 ) ;
F_81 ( & V_4 -> V_169 ) ;
}
int F_82 ( struct V_3 * V_4 ,
struct V_246 * V_247 )
{
int V_248 ;
V_248 = F_83 ( V_247 , & V_4 -> V_193 ) ;
if ( V_248 < 0 )
goto error;
V_248 = F_84 ( & V_4 -> V_169 , V_247 ) ;
if ( V_248 < 0 )
goto error;
return 0 ;
error:
F_79 ( V_4 ) ;
return V_248 ;
}
static int F_85 ( struct V_3 * V_4 )
{
struct V_156 * V_221 = & V_4 -> V_193 ;
struct V_158 * V_160 = V_4 -> V_160 ;
struct V_239 * V_249 = & V_221 -> V_161 ;
int V_248 ;
F_86 ( V_221 , & V_250 ) ;
V_221 -> V_251 = & V_252 ;
F_87 ( V_221 -> V_238 , L_17 , sizeof( V_221 -> V_238 ) ) ;
V_221 -> V_253 = 1 << 16 ;
F_88 ( V_221 , V_4 ) ;
V_221 -> V_242 |= V_254 ;
V_160 [ V_168 ] . V_242 = V_255 ;
V_160 [ V_28 ] . V_242 = V_256 ;
V_249 -> V_257 = & V_258 ;
V_248 = F_89 ( V_249 , V_259 , V_160 , 0 ) ;
if ( V_248 < 0 )
return V_248 ;
F_69 ( V_221 , NULL ) ;
V_4 -> V_169 . type = V_260 ;
V_4 -> V_169 . V_257 = & V_261 ;
V_4 -> V_169 . V_262 = 32 ;
V_4 -> V_169 . V_263 = 1 ;
V_4 -> V_169 . V_264 = 0x1ffe0 ;
V_4 -> V_169 . V_2 = V_4 -> V_2 ;
V_4 -> V_169 . V_265 = F_90 ( 4096 * 4096 ) * 3 ;
V_248 = F_91 ( & V_4 -> V_169 , L_18 ) ;
if ( V_248 < 0 )
goto V_266;
V_248 = F_92 ( & V_4 -> V_193 . V_161 , V_168 ,
& V_4 -> V_169 . V_199 . V_161 , 0 , 0 ) ;
if ( V_248 < 0 )
goto V_267;
return 0 ;
V_267:
F_93 ( & V_4 -> V_169 ) ;
V_266:
F_94 ( & V_4 -> V_193 . V_161 ) ;
return V_248 ;
}
int F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_268 = & V_2 -> V_200 ;
struct V_3 * V_269 = & V_2 -> V_270 ;
int V_248 ;
V_268 -> V_2 = V_2 ;
V_268 -> V_135 = 1 ;
V_268 -> V_9 = V_271 ;
V_268 -> V_272 = V_273 ;
V_268 -> V_137 = & V_2 -> V_274 ;
V_268 -> V_237 = V_236 ;
F_96 ( & V_268 -> V_196 ) ;
V_248 = F_85 ( V_268 ) ;
if ( V_248 < 0 )
return V_248 ;
if ( V_2 -> V_47 == V_48 ) {
V_269 -> V_2 = V_2 ;
V_269 -> V_135 = 1 ;
V_269 -> V_9 = V_275 ;
V_269 -> V_272 = V_276 ;
V_269 -> V_137 = & V_2 -> V_277 ;
V_269 -> V_237 = V_236 ;
F_96 ( & V_269 -> V_196 ) ;
}
return 0 ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_268 = & V_2 -> V_200 ;
F_93 ( & V_268 -> V_169 ) ;
F_94 ( & V_268 -> V_193 . V_161 ) ;
}
