static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 = 0 , V_7 = 0 ;
T_2 V_8 , V_9 = 0 , V_10 = 0 ;
struct V_11 V_12 ;
int V_13 ;
F_2 ( V_2 , V_4 , & V_12 ) ;
V_8 = V_12 . V_14 ;
if ( V_8 < 4800 ) {
if ( F_3 ( V_2 ) ) {
T_2 V_15 ;
T_2 div ;
if ( V_2 -> V_16 )
div = 75 ;
else
div = 120 ;
V_9 = ( V_8 * 4 ) / div ;
V_15 = ( ( ( V_8 * 4 ) % div ) * 0x20000 ) / div ;
V_9 = ( V_9 << 17 ) | V_15 ;
} else if ( F_4 ( V_2 ) ) {
T_2 V_15 ;
V_9 = ( V_8 * 4 ) / 120 ;
V_15 = ( ( ( V_8 * 4 ) % 120 ) * 0x20000 ) / 120 ;
V_9 = ( V_9 << 17 ) | V_15 ;
} else if ( F_5 ( V_2 ) || F_6 ( V_2 ) ) {
if ( V_2 -> V_16 ) {
T_2 V_15 ;
V_9 = ( V_8 * 2 ) / 75 ;
V_15 = ( ( ( V_8 * 2 ) % 75 ) * 0x20000 ) / 75 ;
V_9 = ( V_9 << 17 ) | V_15 ;
} else
V_9 = F_7 ( V_8 ) >> 1 ;
} else
V_9 = F_7 ( V_8 ) ;
V_5 = 1 ;
} else {
if ( ( F_5 ( V_2 ) || F_6 ( V_2 ) ) &&
V_2 -> V_16 ) {
T_2 V_15 ;
V_9 = V_8 / 75 ;
V_15 = ( ( V_8 % 75 ) * 0x20000 ) / 75 ;
V_9 = ( V_9 << 17 ) | V_15 ;
} else {
V_9 = F_8 ( V_8 ) ;
V_9 >>= 1 ;
}
V_5 = 0 ;
}
V_6 = 1 ;
V_7 = 0 ;
V_13 = 0 ;
V_10 = ( V_5 << 29 ) ;
F_9 ( V_2 , V_17 , V_10 ) ;
F_10 ( V_2 , V_18 ,
V_19 , 1 ) ;
V_10 = ( V_9 << 2 ) | ( V_6 << 30 ) |
( V_7 << 28 ) | ( V_13 << 31 ) ;
F_9 ( V_2 , V_20 , V_10 ) ;
V_13 = 1 ;
V_10 = ( V_9 << 2 ) | ( V_6 << 30 ) |
( V_7 << 28 ) | ( V_13 << 31 ) ;
F_9 ( V_2 , V_20 , V_10 ) ;
V_2 -> V_21 = V_4 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const T_2 V_22 [ 4 ] = { 2420 , 2440 , 2464 , 2480 } ;
int V_23 , V_24 = 0 , V_25 ;
int V_26 ;
int V_27 , V_28 , V_29 ;
T_3 * V_30 = F_12 ( V_2 , F_13 ( V_4 ) ) ;
if ( F_4 ( V_2 ) || F_5 ( V_2 ) || F_3 ( V_2 ) ||
F_6 ( V_2 ) ) {
if ( V_30 [ 0 ] == 0 )
return;
V_28 = 5 ;
if ( F_14 ( V_4 ) ) {
V_27 = 19 ;
if ( F_15 ( V_2 , V_31 ,
V_32 ) == 0 )
V_29 = V_4 -> V_33 + 10 ;
else
V_29 = V_4 -> V_33 - 10 ;
} else {
V_27 = 10 ;
V_29 = V_4 -> V_33 ;
}
} else {
V_27 = F_16 ( V_2 ) ? 5 : 10 ;
V_28 = 4 ;
V_29 = V_4 -> V_33 ;
}
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( F_16 ( V_2 ) && ( V_26 == 0 || V_26 == 3 ) )
continue;
V_24 = 0 ;
if ( F_4 ( V_2 ) || F_5 ( V_2 ) || F_3 ( V_2 ) ||
F_6 ( V_2 ) )
V_23 = F_17 ( V_30 [ V_26 ] ,
F_13 ( V_4 ) ) ;
else
V_23 = V_22 [ V_26 ] ;
V_23 -= V_29 ;
if ( V_23 < 0 ) {
V_24 = 1 ;
V_23 = - V_23 ;
}
if ( V_23 < V_27 ) {
V_25 = ( int ) ( ( V_23 << 19 ) / 11 ) ;
if ( V_24 == 1 )
V_25 = - V_25 ;
V_25 = V_25 & 0xfffff ;
F_10 ( V_2 , V_34 ,
V_35 , 0x7 ) ;
F_10 ( V_2 , V_36 ,
V_37 , 0x7f ) ;
F_10 ( V_2 , V_36 ,
V_38 ,
0x2 ) ;
F_10 ( V_2 , V_36 ,
V_39 ,
0x1 ) ;
F_10 ( V_2 , V_36 ,
V_40 ,
V_25 ) ;
return;
}
}
F_10 ( V_2 , V_34 ,
V_35 , 0x5 ) ;
F_10 ( V_2 , V_36 ,
V_39 , 0x0 ) ;
F_10 ( V_2 , V_36 ,
V_40 , 0x0 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_41 ,
V_42 , 0 ) ;
F_10 ( V_2 , V_43 ,
V_44 , 0 ) ;
F_10 ( V_2 , V_43 ,
V_45 , 0 ) ;
F_10 ( V_2 , V_46 ,
V_47 , 0 ) ;
F_10 ( V_2 , V_43 ,
V_48 , 0 ) ;
F_10 ( V_2 , V_43 ,
V_49 , 0 ) ;
F_10 ( V_2 , V_41 ,
V_50 , 0 ) ;
F_10 ( V_2 , V_51 ,
V_52 , 0 ) ;
F_10 ( V_2 , V_51 ,
V_53 , 0 ) ;
F_10 ( V_2 , V_51 ,
V_54 , 0 ) ;
F_10 ( V_2 , V_41 ,
V_55 , 0 ) ;
F_10 ( V_2 , V_41 ,
V_56 , 0 ) ;
F_10 ( V_2 , V_57 ,
V_58 , 0 ) ;
F_10 ( V_2 , V_59 ,
V_60 , 0 ) ;
F_10 ( V_2 , V_61 ,
V_62 , 0 ) ;
F_10 ( V_2 , V_57 ,
V_63 , 0 ) ;
F_10 ( V_2 , V_61 ,
V_64 , 0 ) ;
F_10 ( V_2 , V_59 ,
V_65 , 0 ) ;
F_10 ( V_2 , V_51 ,
V_66 , 0 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
int V_67 ,
int V_68 ,
int V_69 ,
int V_70 )
{
int V_71 = 0 ;
F_10 ( V_2 , V_41 ,
V_42 , 0x1 ) ;
F_10 ( V_2 , V_43 ,
V_44 , V_68 ) ;
F_10 ( V_2 , V_43 ,
V_45 , V_69 ) ;
F_10 ( V_2 , V_46 ,
V_47 , V_70 ) ;
F_10 ( V_2 , V_43 ,
V_48 , 0x1 ) ;
F_10 ( V_2 , V_43 ,
V_49 , 0x1 ) ;
F_10 ( V_2 , V_41 ,
V_50 , 0x1 ) ;
F_10 ( V_2 , V_51 ,
V_72 , 34 ) ;
F_10 ( V_2 , V_51 ,
V_52 , 1 ) ;
if ( F_15 ( V_2 , V_73 ,
V_74 ) == 0x1 )
F_10 ( V_2 , V_51 ,
V_53 , 1 ) ;
V_71 = ( V_67 << 4 ) / 5 ;
if ( V_71 < 0 )
V_71 = V_71 - 1 ;
V_71 = V_71 & 0x7f ;
F_10 ( V_2 , V_51 ,
V_54 , 0x1 ) ;
F_10 ( V_2 , V_41 ,
V_55 , 0x1 ) ;
F_10 ( V_2 , V_41 ,
V_56 , 0x1 ) ;
F_10 ( V_2 , V_57 ,
V_58 , V_71 ) ;
F_10 ( V_2 , V_59 ,
V_60 , V_71 ) ;
F_10 ( V_2 , V_61 ,
V_62 , V_71 ) ;
F_10 ( V_2 , V_57 ,
V_63 , 0xc ) ;
F_10 ( V_2 , V_61 ,
V_64 , 0xc ) ;
F_10 ( V_2 , V_59 ,
V_65 , 0xa0 ) ;
F_10 ( V_2 , V_51 ,
V_66 , 0xff ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_67 )
{
int V_68 = 0 ;
int V_70 = 0 ;
int V_69 = 0 ;
if ( F_14 ( V_4 ) ) {
if ( V_67 < 0 ) {
if ( F_15 ( V_2 , V_31 ,
V_32 ) == 0x0 )
V_70 = 1 ;
else
V_70 = 0 ;
V_68 = ( ( V_67 + 10 ) << 9 ) / 11 ;
} else {
if ( F_15 ( V_2 , V_31 ,
V_32 ) == 0x0 )
V_70 = 0 ;
else
V_70 = 1 ;
V_68 = ( ( V_67 - 10 ) << 9 ) / 11 ;
}
V_69 = ( V_67 << 17 ) / 5 ;
} else {
V_70 = 0 ;
V_68 = ( V_67 << 9 ) / 11 ;
V_69 = ( V_67 << 18 ) / 5 ;
}
V_68 = V_68 & 0x3ff ;
V_69 = V_69 & 0xfffff ;
F_19 ( V_2 ,
V_67 ,
V_68 ,
V_69 ,
V_70 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_29 ;
int V_27 = 10 ;
int V_67 = 0 ;
int V_75 ;
T_3 * V_76 ;
unsigned int V_26 ;
struct V_77 * V_78 = & V_2 -> V_79 . V_80 ;
if ( F_22 ( V_4 ) ) {
V_76 = & ( V_78 -> V_81 . V_82 [ 0 ] ) ;
V_75 = 0 ;
}
else {
V_76 = & ( V_78 -> V_83 . V_82 [ 0 ] ) ;
V_75 = 1 ;
}
if ( V_76 [ 0 ] == 0 )
return;
if ( F_14 ( V_4 ) ) {
V_27 = 19 ;
if ( F_15 ( V_2 , V_31 ,
V_32 ) == 0x0 )
V_29 = V_4 -> V_33 - 10 ;
else
V_29 = V_4 -> V_33 + 10 ;
} else {
V_27 = 10 ;
V_29 = V_4 -> V_33 ;
}
F_18 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_84 && V_76 [ V_26 ] ; V_26 ++ ) {
V_67 = F_17 ( V_76 [ V_26 ] , V_75 ) ;
V_67 -= V_29 ;
if ( abs ( V_67 ) < V_27 ) {
F_20 ( V_2 , V_4 , V_67 ) ;
break;
}
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_11 ( V_2 , V_4 ) ;
F_21 ( V_2 , V_4 ) ;
}
static T_2 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_85 ;
V_85 = F_25 ( 0x5 , V_86 ) ;
if ( V_4 && F_26 ( V_4 ) )
V_85 |= F_25 ( 0x1 , V_87 ) ;
else if ( V_4 && F_27 ( V_4 ) )
V_85 |= F_25 ( 0x2 , V_87 ) ;
V_85 |= F_25 ( 0x2c , V_88 ) ;
return V_85 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_89 ;
T_2 V_90 = 0 ;
V_90 =
( F_29 ( V_2 , V_31 ) & V_91 ) ;
V_89 = V_92 | V_93 |
V_94 | V_90 ;
if ( F_14 ( V_4 ) ) {
V_89 |= V_95 ;
if ( ( V_4 -> V_96 == V_97 ) ||
( V_4 -> V_96 == V_98 ) )
V_89 |= V_32 ;
}
V_89 |= F_29 ( V_2 , V_31 ) ;
V_89 &= ~ V_99 ;
F_9 ( V_2 , V_31 , V_89 ) ;
F_30 ( V_2 ) ;
F_9 ( V_2 , V_100 , 25 << V_101 ) ;
F_9 ( V_2 , V_102 , 0xF << V_103 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_104 ;
V_104 = F_29 ( V_2 , V_105 ) & V_106 ;
F_9 ( V_2 , V_107 , V_108 ) ;
F_32 ( V_2 , V_4 , V_104 ) ;
}
static void F_33 ( struct V_1 * V_2 , T_3 V_109 , T_3 V_110 )
{
switch ( V_109 ) {
case 0x5 :
F_34 ( V_2 , V_111 ,
V_112 ) ;
case 0x3 :
case 0x1 :
case 0x2 :
case 0x7 :
F_9 ( V_2 , V_113 , V_109 ) ;
F_9 ( V_2 , V_114 , V_109 ) ;
break;
default:
break;
}
if ( ( V_2 -> V_115 . V_116 & V_117 ) && ( V_110 == 0x7 ) )
F_9 ( V_2 , V_118 , 0x3 ) ;
else if ( F_16 ( V_2 ) )
F_9 ( V_2 , V_118 , 0x3 ) ;
else
F_9 ( V_2 , V_118 , V_110 ) ;
if ( V_110 == 0x5 ) {
F_34 ( V_2 , V_111 ,
V_112 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
T_2 V_119 ;
F_34 ( V_2 , V_120 , ( V_121 | V_122 ) ) ;
V_119 = F_29 ( V_2 , V_123 ) & ( ~ V_124 ) ;
F_9 ( V_2 , V_123 ,
V_119 | V_125 | V_126 ) ;
F_34 ( V_2 , V_127 ,
V_128 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
int V_131 )
{
unsigned int V_26 , V_132 = 0 ;
if ( ! V_130 -> V_133 )
return;
if ( V_131 >= V_130 -> V_134 )
V_131 = 1 ;
for ( V_26 = 0 ; V_26 < V_130 -> V_135 ; V_26 ++ ) {
T_2 V_136 = F_37 ( V_130 , V_26 , 0 ) ;
T_2 V_119 = F_37 ( V_130 , V_26 , V_131 ) ;
F_9 ( V_2 , V_136 , V_119 ) ;
F_38 ( V_132 ) ;
}
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_137 ;
switch ( V_4 -> V_96 ) {
case V_138 :
case V_139 :
if ( V_4 -> V_33 <= 5350 )
V_137 = 1 ;
else if ( ( V_4 -> V_33 > 5350 ) && ( V_4 -> V_33 <= 5600 ) )
V_137 = 3 ;
else
V_137 = 5 ;
break;
case V_97 :
case V_140 :
if ( V_4 -> V_33 <= 5350 )
V_137 = 2 ;
else if ( ( V_4 -> V_33 > 5350 ) && ( V_4 -> V_33 <= 5600 ) )
V_137 = 4 ;
else
V_137 = 6 ;
break;
case V_141 :
case V_142 :
case V_143 :
V_137 = 8 ;
break;
case V_98 :
case V_144 :
V_137 = 7 ;
break;
default:
V_137 = - V_145 ;
}
return V_137 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_132 = 0 , V_26 ;
T_2 V_146 ;
switch ( V_4 -> V_96 ) {
case V_138 :
case V_139 :
V_146 = 1 ;
break;
case V_97 :
case V_140 :
V_146 = 2 ;
break;
case V_141 :
case V_142 :
case V_143 :
V_146 = 4 ;
break;
case V_98 :
case V_144 :
V_146 = 3 ;
break;
default:
return - V_145 ;
}
for ( V_26 = 0 ; V_26 < V_147 ; V_26 ++ ) {
F_36 ( V_2 , & V_2 -> V_148 [ V_26 ] , V_146 ) ;
F_36 ( V_2 , & V_2 -> V_149 [ V_26 ] , V_146 ) ;
F_36 ( V_2 , & V_2 -> V_150 [ V_26 ] , V_146 ) ;
F_36 ( V_2 , & V_2 -> V_151 [ V_26 ] , V_146 ) ;
if ( V_26 == V_152 && F_41 ( V_2 ) )
F_36 ( V_2 ,
& V_2 -> V_153 ,
V_146 ) ;
}
F_42 ( & V_2 -> V_154 , 1 , V_132 ) ;
if ( F_6 ( V_2 ) )
F_42 ( & V_2 -> V_155 , V_146 ,
V_132 ) ;
if ( F_6 ( V_2 ) ) {
int V_156 ;
V_156 = F_39 ( V_2 , V_4 ) ;
if ( V_156 < 0 )
return - V_145 ;
F_42 ( & V_2 -> V_157 , V_156 ,
V_132 ) ;
} else {
F_42 ( & V_2 -> V_157 , V_146 , V_132 ) ;
}
if ( F_43 ( V_2 , V_4 ) )
F_42 ( & V_2 -> V_158 ,
V_146 , V_132 ) ;
F_42 ( & V_2 -> V_159 , 1 , V_132 ) ;
if ( V_4 -> V_33 == 2484 )
F_36 ( V_2 , & V_2 -> V_160 , 1 ) ;
if ( F_16 ( V_2 ) )
F_9 ( V_2 , V_161 ,
V_162 ) ;
V_2 -> V_163 = V_146 ;
F_35 ( V_2 ) ;
F_28 ( V_2 , V_4 ) ;
F_33 ( V_2 , V_2 -> V_164 , V_2 -> V_165 ) ;
F_44 ( V_2 , V_4 , false ) ;
if ( F_16 ( V_2 ) ) {
if ( F_15 ( V_2 , V_166 ,
V_167 ) )
V_2 -> V_168 |= V_169 ;
else
V_2 -> V_168 &= ~ V_169 ;
if ( F_29 ( V_2 , V_170 ) & V_171 )
V_2 -> V_168 |= V_172 ;
else
V_2 -> V_168 &= ~ V_172 ;
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_173 = 0 ;
if ( V_4 == NULL )
return;
V_173 |= ( F_46 ( V_4 ) || F_47 ( V_4 ) )
? V_74 : V_174 ;
if ( F_43 ( V_2 , V_4 ) )
V_173 |= ( V_74 | V_175 ) ;
if ( F_27 ( V_4 ) )
V_173 |= V_176 ;
if ( F_26 ( V_4 ) )
V_173 |= V_177 ;
if ( V_173 & ( V_176 | V_177 ) )
F_10 ( V_2 , V_178 ,
V_179 , 3 ) ;
F_9 ( V_2 , V_73 , V_173 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_107 , V_180 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_181 , V_182 , V_183 ;
T_2 V_184 = 0x64000000 ;
struct V_11 V_12 ;
if ( F_26 ( V_4 ) )
V_184 = V_184 >> 1 ;
else if ( F_27 ( V_4 ) )
V_184 = V_184 >> 2 ;
F_2 ( V_2 , V_4 , & V_12 ) ;
V_181 = V_184 / V_12 . V_14 ;
F_50 ( V_2 , V_181 , & V_183 ,
& V_182 ) ;
F_10 ( V_2 , V_185 ,
V_186 , V_183 ) ;
F_10 ( V_2 , V_185 ,
V_187 , V_182 ) ;
V_181 = ( 9 * V_181 ) / 10 ;
F_50 ( V_2 , V_181 , & V_183 ,
& V_182 ) ;
F_10 ( V_2 , V_188 ,
V_189 , V_183 ) ;
F_10 ( V_2 , V_188 ,
V_190 , V_182 ) ;
}
static bool F_51 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_191 , V_192 ) ;
return F_52 ( V_2 , V_193 , V_194 ,
V_194 , V_195 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
T_2 V_104 = F_29 ( V_2 , V_105 ) & V_106 ;
F_32 ( V_2 , V_2 -> V_21 , V_104 ) ;
F_9 ( V_2 , V_191 , 0 ) ;
}
static bool F_54 ( struct V_1 * V_2 ,
enum V_196 V_197 , int V_198 )
{
struct V_199 * V_200 = F_55 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_201 * V_202 = & V_4 -> V_203 ;
T_4 V_204 , V_205 ;
switch ( V_197 & V_2 -> V_206 ) {
case V_207 : {
T_2 V_208 = V_198 ? 1 : 0 ;
if ( V_208 )
F_34 ( V_2 , V_209 ,
V_210 ) ;
else
F_56 ( V_2 , V_209 ,
V_210 ) ;
if ( V_208 != V_202 -> V_211 ) {
F_57 ( V_200 , V_212 ,
L_1 ,
V_4 -> V_33 ,
V_202 -> V_211 ?
L_2 : L_3 ,
V_208 ? L_2 : L_3 ) ;
if ( V_208 )
V_2 -> V_213 . V_214 ++ ;
else
V_2 -> V_213 . V_215 ++ ;
V_202 -> V_211 = V_208 ;
}
break;
}
case V_216 : {
T_2 V_217 = V_198 ;
if ( V_217 >= F_58 ( V_218 ) ) {
F_57 ( V_200 , V_212 ,
L_4 ,
V_217 , F_58 ( V_218 ) ) ;
return false ;
}
V_204 = V_218 [ V_217 ] -
V_218 [ V_219 ] +
V_202 -> V_220 . V_221 ;
if ( V_204 < V_222 )
V_204 = V_222 ;
if ( V_204 > V_223 )
V_204 = V_223 ;
F_10 ( V_2 , V_224 ,
V_225 ,
V_204 ) ;
V_205 = V_218 [ V_217 ] -
V_218 [ V_219 ] +
V_202 -> V_220 . V_226 ;
if ( V_205 < V_222 )
V_205 = V_222 ;
if ( V_205 > V_223 )
V_205 = V_223 ;
F_10 ( V_2 , V_227 ,
V_228 , V_205 ) ;
if ( V_217 != V_202 -> V_229 ) {
F_57 ( V_200 , V_212 ,
L_5 ,
V_4 -> V_33 ,
V_202 -> V_229 ,
V_217 ,
V_219 ,
V_204 ,
V_202 -> V_220 . V_221 ) ;
F_57 ( V_200 , V_212 ,
L_6 ,
V_4 -> V_33 ,
V_202 -> V_229 ,
V_217 ,
V_219 ,
V_205 ,
V_202 -> V_220 . V_226 ) ;
if ( V_217 > V_202 -> V_229 )
V_2 -> V_213 . V_230 ++ ;
else if ( V_217 < V_202 -> V_229 )
V_2 -> V_213 . V_231 ++ ;
V_202 -> V_229 = V_217 ;
}
break;
}
case V_232 : {
T_2 V_217 = V_198 ;
if ( V_217 >= F_58 ( V_233 ) ) {
F_57 ( V_200 , V_212 ,
L_7 ,
V_217 , F_58 ( V_233 ) ) ;
return false ;
}
V_204 = V_233 [ V_217 ] -
V_233 [ V_234 ] +
V_202 -> V_220 . V_235 ;
if ( V_204 < V_236 )
V_204 = V_236 ;
if ( V_204 > V_237 )
V_204 = V_237 ;
F_10 ( V_2 , V_238 ,
V_239 ,
V_204 ) ;
V_205 = V_233 [ V_217 ] -
V_233 [ V_234 ] +
V_202 -> V_220 . V_240 ;
if ( V_205 < V_236 )
V_205 = V_236 ;
if ( V_205 > V_237 )
V_205 = V_237 ;
F_10 ( V_2 , V_241 ,
V_242 , V_205 ) ;
if ( V_217 != V_202 -> V_243 ) {
F_57 ( V_200 , V_212 ,
L_8 ,
V_4 -> V_33 ,
V_202 -> V_243 ,
V_217 ,
V_234 ,
V_204 ,
V_202 -> V_220 . V_235 ) ;
F_57 ( V_200 , V_212 ,
L_9 ,
V_4 -> V_33 ,
V_202 -> V_243 ,
V_217 ,
V_234 ,
V_205 ,
V_202 -> V_220 . V_240 ) ;
if ( V_217 > V_202 -> V_243 )
V_2 -> V_213 . V_244 ++ ;
else if ( V_217 < V_202 -> V_243 )
V_2 -> V_213 . V_245 ++ ;
V_202 -> V_243 = V_217 ;
}
break;
}
case V_246 : {
bool V_247 = V_198 ? 1 : 0 ;
F_10 ( V_2 , V_248 ,
V_249 , V_247 ) ;
F_10 ( V_2 , V_248 ,
V_250 , V_247 ) ;
if ( V_247 != V_202 -> V_251 ) {
F_57 ( V_200 , V_212 , L_10 ,
V_4 -> V_33 ,
V_202 -> V_251 ? L_2 : L_3 ,
V_247 ? L_2 : L_3 ) ;
if ( V_247 )
V_2 -> V_213 . V_252 ++ ;
else
V_2 -> V_213 . V_253 ++ ;
V_202 -> V_251 = V_247 ;
}
break;
}
case V_254 :
break;
default:
F_57 ( V_200 , V_212 , L_11 , V_197 ) ;
return false ;
}
F_57 ( V_200 , V_212 ,
L_12 ,
V_202 -> V_243 ,
V_202 -> V_211 ? L_2 : L_3 ,
V_202 -> V_229 ,
V_202 -> V_251 ? L_2 : L_3 ,
V_202 -> V_255 ,
V_202 -> V_256 ,
V_202 -> V_257 ) ;
return true ;
}
static void F_59 ( struct V_1 * V_2 ,
T_5 V_258 [ V_259 ] )
{
#define F_60 0x1FF00000
#define F_61 20
#define F_62 0x01FF0000
#define F_63 16
T_5 V_260 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_261 ; V_26 ++ ) {
if ( V_2 -> V_164 & F_64 ( V_26 ) ) {
V_260 = F_65 ( F_29 ( V_2 , V_2 -> V_262 [ V_26 ] ) ,
F_60 ) ;
V_258 [ V_26 ] = F_66 ( V_260 , 8 ) ;
if ( F_14 ( V_2 -> V_21 ) ) {
T_3 V_263 = V_261 + V_26 ;
V_260 = F_65 ( F_29 ( V_2 , V_2 -> V_262 [ V_263 ] ) ,
F_62 ) ;
V_258 [ V_263 ] = F_66 ( V_260 , 8 ) ;
}
}
}
}
static void F_67 ( struct V_1 * V_2 )
{
V_2 -> V_264 . V_265 = V_266 ;
V_2 -> V_264 . V_267 = V_268 ;
V_2 -> V_264 . V_269 = V_270 ;
V_2 -> V_271 . V_265 = V_272 ;
V_2 -> V_271 . V_267 = V_273 ;
V_2 -> V_271 . V_269 = V_274 ;
if ( F_3 ( V_2 ) )
V_2 -> V_264 . V_269 = V_275 ;
if ( F_16 ( V_2 ) ) {
V_2 -> V_264 . V_267 = V_276 ;
V_2 -> V_264 . V_269 = V_277 ;
V_2 -> V_271 . V_267 = V_278 ;
V_2 -> V_271 . V_269 = V_279 ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_201 * V_202 ;
struct V_199 * V_200 = F_55 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_280 * V_220 ;
T_2 V_119 ;
V_202 = & V_2 -> V_21 -> V_203 ;
V_220 = & V_202 -> V_220 ;
F_57 ( V_200 , V_212 , L_13 ,
V_2 -> V_281 . V_282 ,
V_2 -> V_281 . V_283 ,
V_2 -> V_284 ,
V_4 -> V_33 ,
V_4 -> V_285 ) ;
V_119 = F_29 ( V_2 , V_286 ) ;
V_220 -> V_287 = F_65 ( V_119 , V_288 ) ;
V_220 -> V_289 = F_65 ( V_119 , V_290 ) ;
V_220 -> V_291 = F_65 ( V_119 , V_292 ) ;
V_119 = F_29 ( V_2 , V_209 ) ;
V_220 -> V_293 = F_65 ( V_119 , V_294 ) ;
V_220 -> V_295 = F_65 ( V_119 , V_296 ) ;
V_220 -> V_297 = F_65 ( V_119 , V_298 ) ;
V_119 = F_29 ( V_2 , V_46 ) ;
V_220 -> V_299 = F_65 ( V_119 , V_300 ) ;
V_220 -> V_301 = F_65 ( V_119 , V_302 ) ;
V_220 -> V_303 = F_65 ( V_119 , V_304 ) ;
V_220 -> V_305 = F_65 ( V_119 , V_306 ) ;
V_220 -> V_221 = F_15 ( V_2 ,
V_224 ,
V_225 ) ;
V_220 -> V_226 = F_15 ( V_2 ,
V_227 ,
V_228 ) ;
V_220 -> V_235 = F_15 ( V_2 ,
V_238 ,
V_239 ) ;
V_220 -> V_240 = F_15 ( V_2 ,
V_241 ,
V_242 ) ;
V_202 -> V_243 = V_234 ;
V_202 -> V_229 = V_219 ;
V_202 -> V_211 = V_307 ;
V_202 -> V_251 = true ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_308 * V_309 )
{
T_2 V_310 = 0 , V_311 = 0 ;
if ( ! V_309 ) {
F_56 ( V_2 , V_312 , V_313 ) ;
return;
}
V_310 |= V_313 | V_314 ;
V_310 |= F_25 ( V_309 -> V_315 , V_316 ) ;
V_310 |= F_25 ( V_309 -> V_317 , V_318 ) ;
V_310 |= F_25 ( V_309 -> V_319 , V_320 ) ;
V_310 |= F_25 ( V_309 -> V_321 , V_322 ) ;
V_310 |= F_25 ( V_309 -> V_323 , V_324 ) ;
V_311 |= V_325 ;
V_311 |= V_326 ;
V_311 |= F_25 ( V_309 -> V_327 , V_328 ) ;
V_311 |= F_25 ( V_309 -> V_329 , V_330 ) ;
V_311 |= F_25 ( V_309 -> V_331 , V_332 ) ;
F_9 ( V_2 , V_312 , V_310 ) ;
F_9 ( V_2 , V_333 , V_311 ) ;
if ( V_309 -> V_334 )
F_34 ( V_2 , V_335 , V_336 ) ;
else
F_56 ( V_2 , V_335 , V_336 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_308 * V_309 = & V_2 -> V_337 ;
V_309 -> V_315 = - 28 ;
V_309 -> V_317 = 0 ;
V_309 -> V_319 = 10 ;
V_309 -> V_321 = 24 ;
V_309 -> V_323 = 8 ;
V_309 -> V_327 = 255 ;
V_309 -> V_329 = 12 ;
V_309 -> V_331 = 8 ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_338 * V_339 )
{
T_2 V_340 ;
V_340 = F_29 ( V_2 , V_341 ) ;
V_339 -> V_342 = ( V_340 & V_343 ) >>
V_344 ;
V_339 -> V_345 = ( V_340 & V_346 ) >>
V_347 ;
V_339 -> V_348 = ( V_340 & V_349 ) >>
V_350 ;
if ( F_72 ( V_2 ) ) {
V_339 -> V_351 = - 9 ;
V_339 -> V_352 = 1 ;
} else if ( F_4 ( V_2 ) ) {
V_339 -> V_351 = - 9 ;
V_339 -> V_352 = 2 ;
} else {
V_339 -> V_351 = - 3 ;
V_339 -> V_352 = 0 ;
}
}
static void F_73 ( struct V_1 * V_2 ,
struct V_338 * V_339 )
{
T_2 V_340 ;
V_340 = F_29 ( V_2 , V_341 ) ;
V_340 &= ~ ( V_343 |
V_346 |
V_349 |
V_353 |
V_354 ) ;
V_340 |= ( ( V_339 -> V_342 <<
V_344 )
& V_343 ) ;
V_340 |= ( ( V_339 -> V_345 << V_347 )
& V_346 ) ;
V_340 |= ( ( V_339 -> V_348 << V_350 )
& V_349 ) ;
V_340 |= ( ( V_339 -> V_355 << V_356 )
& V_353 ) ;
V_340 |= ( ( V_339 -> V_357 << V_358 )
& V_354 ) ;
F_9 ( V_2 , V_341 , V_340 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 * V_359 )
{
unsigned int V_132 = 0 ;
T_2 V_146 ;
switch ( V_4 -> V_96 ) {
case V_138 :
case V_139 :
V_146 = 1 ;
break;
case V_97 :
case V_140 :
V_146 = 2 ;
break;
case V_141 :
case V_142 :
case V_143 :
V_146 = 4 ;
break;
case V_98 :
case V_144 :
V_146 = 3 ;
break;
default:
return - V_145 ;
}
if ( V_146 == V_2 -> V_163 ) {
* V_359 = false ;
goto V_360;
}
F_36 ( V_2 , & V_2 -> V_148 [ V_152 ] , V_146 ) ;
F_36 ( V_2 , & V_2 -> V_149 [ V_152 ] , V_146 ) ;
F_36 ( V_2 , & V_2 -> V_150 [ V_152 ] , V_146 ) ;
F_36 ( V_2 , & V_2 -> V_151 [ V_152 ] , V_146 ) ;
if ( F_41 ( V_2 ) )
F_36 ( V_2 ,
& V_2 -> V_153 ,
V_146 ) ;
F_42 ( & V_2 -> V_157 , V_146 , V_132 ) ;
if ( F_43 ( V_2 , V_4 ) )
F_42 ( & V_2 -> V_158 , V_146 , V_132 ) ;
F_42 ( & V_2 -> V_159 , 1 , V_132 ) ;
V_2 -> V_163 = V_146 ;
* V_359 = true ;
V_360:
F_45 ( V_2 , V_4 ) ;
return 0 ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_361 * V_362 = F_76 ( V_2 ) ;
struct V_363 * V_364 = F_77 ( V_2 ) ;
static const T_2 V_365 [ 6 ] = {
V_366 ,
V_367 ,
V_368 ,
V_241 ,
V_369 ,
V_370 ,
} ;
V_362 -> V_371 = F_1 ;
V_362 -> V_372 = F_23 ;
V_362 -> V_373 = F_24 ;
V_362 -> V_374 = F_28 ;
V_362 -> V_375 = F_31 ;
V_362 -> V_376 = F_40 ;
V_362 -> V_360 = F_45 ;
V_362 -> V_377 = F_48 ;
V_362 -> V_378 = F_49 ;
V_362 -> V_379 = F_51 ;
V_362 -> V_380 = F_53 ;
V_362 -> V_381 = F_54 ;
V_362 -> V_382 = F_59 ;
V_362 -> V_383 = F_68 ;
V_362 -> V_384 = F_69 ;
V_362 -> V_385 = F_74 ;
V_364 -> V_386 = F_71 ;
V_364 -> V_387 = F_73 ;
F_67 ( V_2 ) ;
F_70 ( V_2 ) ;
memcpy ( V_2 -> V_262 , V_365 , sizeof( V_2 -> V_262 ) ) ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = F_55 ( V_2 ) ;
T_2 V_388 = V_2 -> V_389 ;
T_2 V_119 , V_390 ;
if ( ! V_388 ) {
F_9 ( V_2 , V_391 ,
F_29 ( V_2 , V_391 ) &
~ ( V_392 |
V_393 ) ) ;
F_9 ( V_2 , V_394 ,
F_29 ( V_2 , V_394 ) &
~ ( V_395 |
V_396 ) ) ;
F_57 ( V_200 , V_397 , L_14 ) ;
return;
}
V_119 = F_29 ( V_2 , V_391 ) & V_398 ;
F_9 ( V_2 , V_391 ,
( V_119 | V_393 ) &
~ V_392 ) ;
if ( V_388 > 10000 )
V_388 = 10000 ;
V_390 = ( 100 * V_388 ) / 74 ;
if ( V_2 -> V_21 && F_14 ( V_2 -> V_21 ) )
V_390 = ( 100 * V_388 ) / 37 ;
F_9 ( V_2 , V_394 ,
V_395 |
V_399 |
( V_400 & ( V_390 << 2 ) ) ) ;
F_57 ( V_200 , V_397 , L_15 ,
V_388 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
V_2 -> V_401 = F_29 ( V_2 , V_402 ) ;
F_9 ( V_2 , V_402 ,
V_2 -> V_401 & ~ V_403 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = F_55 ( V_2 ) ;
T_2 V_404 ;
if ( F_81 ( ! ( V_200 -> V_405 & V_406 ) ) )
return;
V_404 = V_2 -> V_401 ;
F_57 ( V_200 , V_397 ,
L_16 , V_404 ) ;
F_57 ( V_200 , V_397 ,
L_17 ,
F_65 ( V_404 , V_407 ) ,
F_65 ( V_404 , V_408 ) ,
F_65 ( V_404 , V_409 ) ,
F_65 ( V_404 , V_410 ) ,
F_65 ( V_404 , V_411 ) ,
F_65 ( V_404 , V_412 ) ,
F_65 ( V_404 , V_413 ) ,
F_65 ( V_404 , V_414 ) ,
F_65 ( V_404 , V_415 ) ) ;
F_57 ( V_200 , V_397 , L_18 ,
F_29 ( V_2 , V_394 ) ,
F_29 ( V_2 , V_391 ) ) ;
F_57 ( V_200 , V_397 , L_19 ,
F_29 ( V_2 , V_31 ) ) ;
#define F_82 ( T_6 ) (common->cc_survey._field * 100 / common->cc_survey.cycles)
if ( V_200 -> V_416 . V_417 )
F_57 ( V_200 , V_397 ,
L_20 ,
F_82 ( V_418 ) , F_82 ( V_419 ) , F_82 ( V_420 ) ) ;
F_57 ( V_200 , V_397 , L_21 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
T_2 V_119 ;
if ( ! ( ( F_65 ( V_2 -> V_401 ,
V_410 ) == 0xb ) ||
V_2 -> V_421 ) )
return;
V_2 -> V_421 = true ;
V_119 = F_29 ( V_2 , V_422 ) ;
V_119 &= ~ V_423 ;
F_9 ( V_2 , V_422 , V_119 ) ;
}
