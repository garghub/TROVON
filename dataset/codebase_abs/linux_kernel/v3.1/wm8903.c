static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return 1 ;
default:
return 0 ;
}
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_4 , 0 ) ;
memcpy ( V_2 -> V_12 , V_13 ,
sizeof( V_13 ) ) ;
}
static int F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 , int V_18 )
{
F_5 ( V_18 != V_19 ) ;
F_6 ( 4 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 ,
struct V_16 * V_17 , int V_18 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
switch ( V_18 ) {
case V_19 :
V_21 -> V_22 |= 1 << V_15 -> V_23 ;
break;
case V_24 :
F_9 ( V_2 , V_25 ,
1 << V_15 -> V_23 , 0 ) ;
break;
}
return 0 ;
}
static void F_10 ( struct V_26 * V_27 ,
enum V_28 V_18 , int V_29 )
{
struct V_1 * V_2 = F_11 ( V_27 ,
struct V_1 , V_27 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_30 = V_31 ;
int V_32 , V_33 ;
if ( V_21 -> V_22 ) {
F_12 ( V_2 -> V_34 , L_1 ,
V_21 -> V_22 ) ;
for ( V_32 = 0 ; V_32 < F_13 ( V_21 -> V_35 ) ; V_32 ++ ) {
if ( ! ( V_21 -> V_22 & ( 1 << V_32 ) ) )
continue;
if ( V_21 -> V_35 [ V_32 ] ) {
F_12 ( V_2 -> V_34 ,
L_2 ,
3 - V_32 , V_21 -> V_35 [ V_32 ] ) ;
F_3 ( V_2 , V_36 + V_32 ,
V_21 -> V_35 [ V_32 ] & 0xff ) ;
} else {
F_12 ( V_2 -> V_34 ,
L_3 , 3 - V_32 ) ;
V_30 = V_37 ;
}
}
if ( V_21 -> V_38 )
V_30 = V_37 ;
F_9 ( V_2 , V_39 ,
V_40 , V_30 ) ;
F_9 ( V_2 , V_25 ,
V_41 , V_21 -> V_22 ) ;
switch ( V_30 ) {
case V_31 :
break;
case V_37 :
F_14 ( 270 ) ;
if ( V_21 -> V_38 )
break;
for ( V_32 = 0 ; V_32 < F_13 ( V_21 -> V_35 ) ; V_32 ++ ) {
if ( ! ( V_21 -> V_22 & ( 1 << V_32 ) ) )
continue;
V_33 = F_15 ( V_2 ,
V_8 + V_32 ) ;
F_12 ( V_2 -> V_34 , L_4 ,
3 - V_32 , V_33 ) ;
V_21 -> V_35 [ V_32 ] = V_33 ;
}
break;
default:
F_16 ( L_5 , V_30 ) ;
break;
}
V_21 -> V_22 = 0 ;
}
}
static int F_17 ( struct V_16 * V_17 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = F_18 ( V_17 ) ;
struct V_14 * V_46 = V_45 -> V_47 [ 0 ] ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
T_1 V_3 ;
int V_48 ;
V_3 = F_15 ( V_2 , V_49 ) ;
if ( V_43 -> V_50 . integer . V_50 [ 0 ] ) {
if ( V_21 -> V_38 == 0 ) {
F_12 ( V_2 -> V_34 , L_6 ) ;
F_3 ( V_2 , V_49 , V_3 &
~ ( V_51 | V_52 ) ) ;
}
V_21 -> V_38 ++ ;
}
V_48 = F_19 ( V_17 , V_43 ) ;
if ( ! V_43 -> V_50 . integer . V_50 [ 0 ] ) {
if ( V_21 -> V_38 == 1 ) {
F_12 ( V_2 -> V_34 , L_7 ) ;
F_3 ( V_2 , V_49 , V_3 |
V_51 | V_52 ) ;
}
V_21 -> V_38 -- ;
}
F_12 ( V_2 -> V_34 , L_8 ,
V_21 -> V_38 ) ;
return V_48 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_33 , V_32 , V_53 ;
if ( V_21 -> V_54 ) {
V_53 = 1 ;
for ( V_32 = 2 ; V_32 < F_13 ( V_55 ) ; V_32 ++ ) {
if ( abs ( V_55 [ V_32 ] - V_21 -> V_56 ) <
abs ( V_55 [ V_53 ] - V_21 -> V_56 ) )
V_53 = V_32 ;
}
V_33 = V_53 << V_57 ;
} else {
V_53 = 0 ;
V_33 = 0 ;
}
F_12 ( V_2 -> V_34 , L_9 ,
V_53 , V_55 [ V_53 ] ) ;
return F_9 ( V_2 , V_58 ,
V_59 , V_33 ) ;
}
static int F_21 ( struct V_16 * V_17 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
V_43 -> V_50 . V_60 . V_61 [ 0 ] = V_21 -> V_54 ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_54 = V_43 -> V_50 . V_60 . V_61 [ 0 ] ;
int V_48 = 0 ;
if ( V_54 > 1 )
return - V_62 ;
F_23 ( & V_2 -> V_63 ) ;
if ( V_21 -> V_54 != V_54 ) {
V_21 -> V_54 = V_54 ;
F_20 ( V_2 ) ;
V_48 = 1 ;
}
F_24 ( & V_2 -> V_63 ) ;
return V_48 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_64 V_65 )
{
switch ( V_65 ) {
case V_66 :
break;
case V_67 :
F_9 ( V_2 , V_68 ,
V_69 ,
V_70 ) ;
break;
case V_71 :
if ( V_2 -> V_27 . V_72 == V_73 ) {
F_9 ( V_2 , V_74 ,
V_75 | V_76 |
V_77 |
V_78 ,
V_75 |
( 2 << V_79 ) |
V_77 ) ;
F_9 ( V_2 ,
V_80 ,
V_81 ,
V_81 ) ;
F_14 ( 33 ) ;
F_9 ( V_2 , V_82 ,
V_83 | V_84 ,
V_83 | V_84 ) ;
F_9 ( V_2 ,
V_80 ,
V_81 , 0 ) ;
F_9 ( V_2 , V_68 ,
V_85 |
V_86 |
V_87 |
V_88 |
V_69 |
V_89 ,
V_85 |
V_86 |
V_87 |
( 2 << V_90 ) |
V_91 |
V_89 ) ;
F_14 ( 129 ) ;
F_9 ( V_2 , V_82 ,
V_83 | V_84 ,
0 ) ;
F_9 ( V_2 , V_68 ,
V_88 , 0 ) ;
F_9 ( V_2 , V_68 ,
V_69 ,
V_70 ) ;
F_9 ( V_2 , V_74 ,
V_78 | V_75 ,
V_78 ) ;
F_12 ( V_2 -> V_34 , L_7 ) ;
F_9 ( V_2 , V_49 ,
V_51 |
V_52 ,
V_51 |
V_52 ) ;
}
F_9 ( V_2 , V_68 ,
V_69 ,
V_91 ) ;
break;
case V_73 :
F_9 ( V_2 , V_74 ,
V_78 , 0 ) ;
F_9 ( V_2 , V_68 ,
V_88 ,
2 << V_90 ) ;
F_9 ( V_2 , V_68 ,
V_89 , 0 ) ;
F_14 ( 290 ) ;
F_9 ( V_2 , V_68 ,
V_85 | V_86 |
V_87 | V_69 |
V_88 |
V_89 , 0 ) ;
F_9 ( V_2 , V_74 ,
V_77 , 0 ) ;
break;
}
V_2 -> V_27 . V_72 = V_65 ;
return 0 ;
}
static int F_26 ( struct V_92 * V_93 ,
int V_94 , unsigned int V_95 , int V_96 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
V_21 -> V_97 = V_95 ;
return 0 ;
}
static int F_27 ( struct V_92 * V_93 ,
unsigned int V_98 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
T_1 V_99 = F_15 ( V_2 , V_100 ) ;
V_99 &= ~ ( V_101 | V_102 | V_103 |
V_104 | V_105 ) ;
switch ( V_98 & V_106 ) {
case V_107 :
break;
case V_108 :
V_99 |= V_101 ;
break;
case V_109 :
V_99 |= V_101 | V_102 ;
break;
case V_110 :
V_99 |= V_102 ;
break;
default:
return - V_62 ;
}
switch ( V_98 & V_111 ) {
case V_112 :
V_99 |= 0x3 ;
break;
case V_113 :
V_99 |= 0x3 | V_104 ;
break;
case V_114 :
V_99 |= 0x2 ;
break;
case V_115 :
V_99 |= 0x1 ;
break;
case V_116 :
break;
default:
return - V_62 ;
}
switch ( V_98 & V_111 ) {
case V_112 :
case V_113 :
switch ( V_98 & V_117 ) {
case V_118 :
break;
case V_119 :
V_99 |= V_105 ;
break;
default:
return - V_62 ;
}
break;
case V_114 :
case V_115 :
case V_116 :
switch ( V_98 & V_117 ) {
case V_118 :
break;
case V_120 :
V_99 |= V_105 | V_104 ;
break;
case V_119 :
V_99 |= V_105 ;
break;
case V_121 :
V_99 |= V_104 ;
break;
default:
return - V_62 ;
}
break;
default:
return - V_62 ;
}
F_3 ( V_2 , V_100 , V_99 ) ;
return 0 ;
}
static int F_28 ( struct V_92 * V_93 , int V_122 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
T_1 V_3 ;
V_3 = F_15 ( V_2 , V_58 ) ;
if ( V_122 )
V_3 |= V_123 ;
else
V_3 &= ~ V_123 ;
F_3 ( V_2 , V_58 , V_3 ) ;
return 0 ;
}
static int F_29 ( struct V_124 * V_125 ,
struct V_126 * V_127 ,
struct V_92 * V_128 )
{
struct V_129 * V_130 = V_125 -> V_131 ;
struct V_1 * V_2 = V_130 -> V_2 ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_56 = F_30 ( V_127 ) ;
int V_132 ;
int V_133 ;
int V_32 ;
int V_134 ;
int V_135 ;
int V_136 ;
int V_137 ;
int V_138 ;
T_1 V_99 = F_15 ( V_2 , V_100 ) ;
T_1 V_139 = F_15 ( V_2 , V_140 ) ;
T_1 V_141 = F_15 ( V_2 , V_142 ) ;
T_1 V_143 = F_15 ( V_2 , V_144 ) ;
T_1 V_145 = F_15 ( V_2 , V_146 ) ;
T_1 V_147 = F_15 ( V_2 , V_58 ) ;
if ( V_56 <= 24000 )
V_147 |= V_148 ;
else
V_147 &= ~ V_148 ;
V_134 = 0 ;
V_136 = abs ( V_149 [ V_134 ] . V_150 - V_56 ) ;
for ( V_32 = 1 ; V_32 < F_13 ( V_149 ) ; V_32 ++ ) {
V_137 = abs ( V_149 [ V_32 ] . V_150 - V_56 ) ;
if ( V_137 <= V_136 ) {
V_134 = V_32 ;
V_136 = V_137 ;
}
}
F_12 ( V_2 -> V_34 , L_10 , V_149 [ V_134 ] . V_150 ) ;
V_145 &= ~ V_151 ;
V_145 |= V_149 [ V_134 ] . V_50 ;
V_99 &= ~ V_152 ;
V_132 = 2 * V_56 ;
switch ( F_31 ( V_127 ) ) {
case V_153 :
V_132 *= 16 ;
break;
case V_154 :
V_132 *= 20 ;
V_99 |= 0x4 ;
break;
case V_155 :
V_132 *= 24 ;
V_99 |= 0x8 ;
break;
case V_156 :
V_132 *= 32 ;
V_99 |= 0xc ;
break;
default:
return - V_62 ;
}
F_12 ( V_2 -> V_34 , L_11 ,
V_21 -> V_97 , V_56 ) ;
V_135 = 0 ;
V_136 = abs ( ( V_21 -> V_97 /
( V_157 [ 0 ] . V_158 *
V_157 [ 0 ] . div ) ) - V_56 ) ;
for ( V_32 = 1 ; V_32 < F_13 ( V_157 ) ; V_32 ++ ) {
V_137 = abs ( ( V_21 -> V_97 /
( V_157 [ V_32 ] . V_158 *
V_157 [ V_32 ] . div ) ) - V_56 ) ;
if ( V_137 <= V_136 ) {
V_135 = V_32 ;
V_136 = V_137 ;
}
}
if ( V_157 [ V_135 ] . V_158 == 2 ) {
V_143 |= V_159 ;
V_138 = V_21 -> V_97 / 2 ;
} else {
V_143 &= ~ V_159 ;
V_138 = V_21 -> V_97 ;
}
V_145 &= ~ ( V_160 |
V_161 ) ;
V_145 |= V_157 [ V_135 ] . V_150 << V_162 ;
V_145 |= V_157 [ V_135 ] . V_163 << V_164 ;
F_12 ( V_2 -> V_34 , L_12 ,
V_157 [ V_135 ] . V_150 ,
V_157 [ V_135 ] . V_163 ,
V_157 [ V_135 ] . div ) ;
F_12 ( V_2 -> V_34 , L_13 , V_138 ) ;
V_133 = 0 ;
V_136 = ( ( V_138 * 10 ) / V_165 [ 0 ] . V_166 ) - V_132 ;
V_32 = 1 ;
while ( V_32 < F_13 ( V_165 ) ) {
V_137 = ( ( V_138 * 10 ) / V_165 [ V_32 ] . V_166 ) - V_132 ;
if ( V_137 < 0 )
break;
V_133 = V_32 ;
V_136 = V_137 ;
V_32 ++ ;
}
V_139 &= ~ V_167 ;
V_141 &= ~ V_168 ;
F_12 ( V_2 -> V_34 , L_14 ,
V_165 [ V_133 ] . V_166 / 10 , V_132 ,
( V_138 * 10 ) / V_165 [ V_133 ] . V_166 ) ;
V_139 |= V_165 [ V_133 ] . div ;
V_141 |= V_132 / V_56 ;
V_21 -> V_56 = F_30 ( V_127 ) ;
F_20 ( V_2 ) ;
F_3 ( V_2 , V_144 , V_143 ) ;
F_3 ( V_2 , V_146 , V_145 ) ;
F_3 ( V_2 , V_100 , V_99 ) ;
F_3 ( V_2 , V_140 , V_139 ) ;
F_3 ( V_2 , V_142 , V_141 ) ;
F_3 ( V_2 , V_58 , V_147 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , struct V_169 * V_170 ,
int V_171 , int V_172 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_173 = V_174 | V_175 ;
F_12 ( V_2 -> V_34 , L_15 ,
V_171 , V_172 ) ;
V_21 -> V_176 = V_170 ;
V_21 -> V_177 = V_171 ;
V_21 -> V_178 = V_172 ;
if ( V_171 )
V_173 &= ~ V_174 ;
if ( V_172 )
V_173 &= ~ V_175 ;
F_9 ( V_2 , V_179 ,
V_174 | V_175 ,
V_173 ) ;
if ( V_171 || V_172 ) {
F_9 ( V_2 , V_180 ,
V_181 , V_181 ) ;
F_9 ( V_2 , V_182 ,
V_183 , V_183 ) ;
} else {
F_9 ( V_2 , V_182 ,
V_183 , 0 ) ;
}
return 0 ;
}
static T_2 F_33 ( int V_184 , void * V_185 )
{
struct V_1 * V_2 = V_185 ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_186 ;
int V_187 ;
int V_188 = 0 ;
int V_189 = ~ F_15 ( V_2 , V_179 ) ;
V_188 = F_15 ( V_2 , V_6 ) & V_189 ;
if ( V_188 & V_190 ) {
F_34 ( V_2 -> V_34 , L_16 ) ;
}
V_186 = V_21 -> V_191 ;
V_187 = F_15 ( V_2 , V_192 ) ;
#ifndef F_35
if ( V_188 & ( V_175 | V_174 ) )
F_36 ( F_37 ( V_2 -> V_34 ) ) ;
#endif
if ( V_188 & V_175 ) {
F_12 ( V_2 -> V_34 , L_17 , V_187 ) ;
V_186 ^= V_21 -> V_178 ;
V_187 ^= V_193 ;
}
if ( V_188 & V_174 ) {
F_12 ( V_2 -> V_34 , L_18 , V_187 ) ;
V_186 ^= V_21 -> V_177 ;
V_187 ^= V_194 ;
F_14 ( V_21 -> V_195 ) ;
}
F_9 ( V_2 , V_192 ,
V_193 | V_194 , V_187 ) ;
F_38 ( V_21 -> V_176 , V_186 ,
V_21 -> V_178 | V_21 -> V_177 ) ;
V_21 -> V_191 = V_186 ;
return V_196 ;
}
static int F_39 ( struct V_1 * V_2 , T_3 V_197 )
{
F_25 ( V_2 , V_73 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_32 ;
T_1 * V_12 = V_2 -> V_12 ;
T_1 * V_198 = F_41 ( V_12 , sizeof( V_13 ) ,
V_199 ) ;
F_25 ( V_2 , V_71 ) ;
if ( V_198 ) {
for ( V_32 = 2 ; V_32 < F_13 ( V_13 ) ; V_32 ++ )
if ( V_198 [ V_32 ] != V_12 [ V_32 ] )
F_3 ( V_2 , V_32 , V_198 [ V_32 ] ) ;
F_42 ( V_198 ) ;
} else {
F_43 ( V_2 -> V_34 , L_19 ) ;
}
return 0 ;
}
static inline struct V_20 * F_44 ( struct V_200 * V_201 )
{
return F_11 ( V_201 , struct V_20 , V_200 ) ;
}
static int F_45 ( struct V_200 * V_201 , unsigned V_202 )
{
if ( V_202 >= V_203 )
return - V_62 ;
return 0 ;
}
static int F_46 ( struct V_200 * V_201 , unsigned V_202 )
{
struct V_20 * V_21 = F_44 ( V_201 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
unsigned int V_189 , V_33 ;
V_189 = V_204 | V_205 ;
V_33 = ( V_206 << V_207 ) |
V_208 ;
return F_9 ( V_2 , V_209 + V_202 ,
V_189 , V_33 ) ;
}
static int F_47 ( struct V_200 * V_201 , unsigned V_202 )
{
struct V_20 * V_21 = F_44 ( V_201 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_3 ;
V_3 = F_15 ( V_2 , V_209 + V_202 ) ;
return ( V_3 & V_210 ) >> V_211 ;
}
static int F_48 ( struct V_200 * V_201 ,
unsigned V_202 , int V_50 )
{
struct V_20 * V_21 = F_44 ( V_201 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
unsigned int V_189 , V_33 ;
V_189 = V_204 | V_205 | V_210 ;
V_33 = ( V_212 << V_207 ) |
( V_50 << V_213 ) ;
return F_9 ( V_2 , V_209 + V_202 ,
V_189 , V_33 ) ;
}
static void F_49 ( struct V_200 * V_201 , unsigned V_202 , int V_50 )
{
struct V_20 * V_21 = F_44 ( V_201 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_9 ( V_2 , V_209 + V_202 ,
V_210 ,
! ! V_50 << V_211 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_214 * V_215 = F_51 ( V_2 -> V_34 ) ;
int V_48 ;
V_21 -> V_200 = V_216 ;
V_21 -> V_200 . V_217 = V_203 ;
V_21 -> V_200 . V_34 = V_2 -> V_34 ;
if ( V_215 && V_215 -> V_218 )
V_21 -> V_200 . V_219 = V_215 -> V_218 ;
else
V_21 -> V_200 . V_219 = - 1 ;
V_48 = F_52 ( & V_21 -> V_200 ) ;
if ( V_48 != 0 )
F_43 ( V_2 -> V_34 , L_20 , V_48 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_48 ;
V_48 = F_54 ( & V_21 -> V_200 ) ;
if ( V_48 != 0 )
F_43 ( V_2 -> V_34 , L_21 , V_48 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
}
static void F_53 ( struct V_1 * V_2 )
{
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_214 * V_215 = F_51 ( V_2 -> V_34 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_48 , V_32 ;
int V_220 , V_221 ;
T_1 V_33 ;
V_21 -> V_2 = V_2 ;
V_48 = F_56 ( V_2 , 8 , 16 , V_222 ) ;
if ( V_48 != 0 ) {
F_43 ( V_2 -> V_34 , L_22 , V_48 ) ;
return V_48 ;
}
V_33 = F_15 ( V_2 , V_4 ) ;
if ( V_33 != V_13 [ V_4 ] ) {
F_43 ( V_2 -> V_34 ,
L_23 , V_33 ) ;
return - V_223 ;
}
V_33 = F_15 ( V_2 , V_5 ) ;
F_57 ( V_2 -> V_34 , L_24 ,
( V_33 & V_224 ) + 'A' ) ;
F_2 ( V_2 ) ;
if ( V_215 ) {
bool V_225 = false ;
for ( V_32 = 0 ; V_32 < F_13 ( V_215 -> V_226 ) ; V_32 ++ ) {
if ( V_215 -> V_226 [ V_32 ] == V_227 )
continue;
F_3 ( V_2 , V_209 + V_32 ,
V_215 -> V_226 [ V_32 ] & 0xffff ) ;
V_33 = ( V_215 -> V_226 [ V_32 ] & V_204 )
>> V_207 ;
switch ( V_33 ) {
case V_228 :
case V_229 :
V_225 = true ;
break;
default:
break;
}
}
F_3 ( V_2 , V_182 ,
V_215 -> V_230 ) ;
if ( V_215 -> V_230 )
F_9 ( V_2 , V_180 ,
V_181 , V_181 ) ;
F_5 ( ! V_225 && ( V_215 -> V_230 & V_183 ) ) ;
V_21 -> V_195 = V_215 -> V_231 ;
}
if ( V_21 -> V_184 ) {
if ( V_215 && V_215 -> V_232 ) {
V_220 = V_233 ;
V_221 = V_234 ;
} else {
V_220 = V_235 ;
V_221 = 0 ;
}
F_9 ( V_2 , V_236 ,
V_234 , V_221 ) ;
V_48 = F_58 ( V_21 -> V_184 , NULL , F_33 ,
V_220 | V_237 ,
L_25 , V_2 ) ;
if ( V_48 != 0 ) {
F_43 ( V_2 -> V_34 , L_26 ,
V_48 ) ;
return V_48 ;
}
F_9 ( V_2 , V_179 ,
V_238 , 0 ) ;
}
F_25 ( V_2 , V_71 ) ;
V_33 = F_15 ( V_2 , V_239 ) ;
V_33 |= V_240 ;
F_3 ( V_2 , V_239 , V_33 ) ;
F_3 ( V_2 , V_241 , V_33 ) ;
V_33 = F_15 ( V_2 , V_242 ) ;
V_33 |= V_243 ;
F_3 ( V_2 , V_242 , V_33 ) ;
F_3 ( V_2 , V_244 , V_33 ) ;
V_33 = F_15 ( V_2 , V_245 ) ;
V_33 |= V_246 ;
F_3 ( V_2 , V_245 , V_33 ) ;
F_3 ( V_2 , V_247 , V_33 ) ;
V_33 = F_15 ( V_2 , V_248 ) ;
V_33 |= V_249 ;
F_3 ( V_2 , V_248 , V_33 ) ;
F_3 ( V_2 , V_250 , V_33 ) ;
V_33 = F_15 ( V_2 , V_251 ) ;
V_33 |= V_252 ;
F_3 ( V_2 , V_251 , V_33 ) ;
F_3 ( V_2 , V_253 , V_33 ) ;
F_9 ( V_2 , V_58 ,
V_254 | V_123 ,
V_254 | V_123 ) ;
F_59 ( V_2 , V_255 ,
F_13 ( V_255 ) ) ;
F_50 ( V_2 ) ;
return V_48 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
F_53 ( V_2 ) ;
F_25 ( V_2 , V_73 ) ;
if ( V_21 -> V_184 )
F_61 ( V_21 -> V_184 , V_2 ) ;
return 0 ;
}
static T_4 int F_62 ( struct V_256 * V_257 ,
const struct V_258 * V_259 )
{
struct V_20 * V_21 ;
int V_48 ;
V_21 = F_63 ( sizeof( struct V_20 ) , V_199 ) ;
if ( V_21 == NULL )
return - V_260 ;
F_64 ( V_257 , V_21 ) ;
V_21 -> V_184 = V_257 -> V_184 ;
V_48 = F_65 ( & V_257 -> V_34 ,
& V_261 , & V_262 , 1 ) ;
if ( V_48 < 0 )
F_42 ( V_21 ) ;
return V_48 ;
}
static T_5 int F_66 ( struct V_256 * V_263 )
{
F_67 ( & V_263 -> V_34 ) ;
F_42 ( F_68 ( V_263 ) ) ;
return 0 ;
}
static int T_6 F_69 ( void )
{
int V_48 = 0 ;
#if F_70 ( V_264 ) || F_70 ( V_265 )
V_48 = F_71 ( & V_266 ) ;
if ( V_48 != 0 ) {
F_72 ( V_267 L_27 ,
V_48 ) ;
}
#endif
return V_48 ;
}
static void T_7 F_73 ( void )
{
#if F_70 ( V_264 ) || F_70 ( V_265 )
F_74 ( & V_266 ) ;
#endif
}
