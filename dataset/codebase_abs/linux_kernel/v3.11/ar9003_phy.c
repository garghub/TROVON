static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 = 0 , V_7 = 0 ;
T_2 V_8 , V_9 , div , V_10 = 0 , V_11 = 0 ;
struct V_12 V_13 ;
int V_14 ;
F_2 ( V_2 , V_4 , & V_13 ) ;
V_8 = V_13 . V_15 ;
if ( V_8 < 4800 ) {
if ( F_3 ( V_2 ) ) {
if ( V_2 -> V_16 )
div = 75 ;
else
div = 120 ;
V_10 = ( V_8 * 4 ) / div ;
V_9 = ( ( ( V_8 * 4 ) % div ) * 0x20000 ) / div ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else if ( F_4 ( V_2 ) || F_5 ( V_2 ) ) {
V_10 = ( V_8 * 4 ) / 120 ;
V_9 = ( ( ( V_8 * 4 ) % 120 ) * 0x20000 ) / 120 ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else if ( F_6 ( V_2 ) ) {
if ( V_2 -> V_16 ) {
V_10 = ( V_8 * 2 ) / 75 ;
V_9 = ( ( ( V_8 * 2 ) % 75 ) * 0x20000 ) / 75 ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else {
V_10 = F_7 ( V_8 ) >> 1 ;
}
} else if ( F_8 ( V_2 ) ) {
if ( V_2 -> V_16 )
div = 75 ;
else
div = 120 ;
V_10 = ( V_8 * 4 ) / div ;
V_9 = ( ( ( V_8 * 4 ) % div ) * 0x20000 ) / div ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else {
V_10 = F_7 ( V_8 ) ;
}
V_5 = 1 ;
} else {
if ( ( F_6 ( V_2 ) || F_8 ( V_2 ) ) &&
V_2 -> V_16 ) {
V_10 = V_8 / 75 ;
V_9 = ( ( V_8 % 75 ) * 0x20000 ) / 75 ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else {
V_10 = F_9 ( V_8 ) ;
V_10 >>= 1 ;
}
V_5 = 0 ;
}
V_6 = 1 ;
V_7 = 0 ;
V_14 = 0 ;
V_11 = ( V_5 << 29 ) ;
F_10 ( V_2 , V_17 , V_11 ) ;
F_11 ( V_2 , V_18 ,
V_19 , 1 ) ;
V_11 = ( V_10 << 2 ) | ( V_6 << 30 ) |
( V_7 << 28 ) | ( V_14 << 31 ) ;
F_10 ( V_2 , V_20 , V_11 ) ;
V_14 = 1 ;
V_11 = ( V_10 << 2 ) | ( V_6 << 30 ) |
( V_7 << 28 ) | ( V_14 << 31 ) ;
F_10 ( V_2 , V_20 , V_11 ) ;
V_2 -> V_21 = V_4 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const T_2 V_22 [ 4 ] = { 2420 , 2440 , 2464 , 2480 } ;
int V_23 , V_24 = 0 , V_25 ;
int V_26 ;
int V_27 , V_28 , V_29 ;
T_3 * V_30 = F_13 ( V_2 , F_14 ( V_4 ) ) ;
if ( F_4 ( V_2 ) || F_6 ( V_2 ) || F_3 ( V_2 ) ||
F_8 ( V_2 ) ) {
if ( V_30 [ 0 ] == 0 )
return;
V_28 = 5 ;
if ( F_15 ( V_4 ) ) {
V_27 = 19 ;
if ( F_16 ( V_2 , V_31 ,
V_32 ) == 0 )
V_29 = V_4 -> V_33 + 10 ;
else
V_29 = V_4 -> V_33 - 10 ;
} else {
V_27 = 10 ;
V_29 = V_4 -> V_33 ;
}
} else {
V_27 = F_17 ( V_2 ) ? 5 : 10 ;
V_28 = 4 ;
V_29 = V_4 -> V_33 ;
}
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( F_17 ( V_2 ) && ( V_26 == 0 || V_26 == 3 ) )
continue;
V_24 = 0 ;
if ( F_4 ( V_2 ) || F_6 ( V_2 ) || F_3 ( V_2 ) ||
F_8 ( V_2 ) )
V_23 = F_18 ( V_30 [ V_26 ] ,
F_14 ( V_4 ) ) ;
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
F_11 ( V_2 , V_34 ,
V_35 , 0x7 ) ;
F_11 ( V_2 , V_36 ,
V_37 , 0x7f ) ;
F_11 ( V_2 , V_36 ,
V_38 ,
0x2 ) ;
F_11 ( V_2 , V_36 ,
V_39 ,
0x1 ) ;
F_11 ( V_2 , V_36 ,
V_40 ,
V_25 ) ;
return;
}
}
F_11 ( V_2 , V_34 ,
V_35 , 0x5 ) ;
F_11 ( V_2 , V_36 ,
V_39 , 0x0 ) ;
F_11 ( V_2 , V_36 ,
V_40 , 0x0 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_41 ,
V_42 , 0 ) ;
F_11 ( V_2 , V_43 ,
V_44 , 0 ) ;
F_11 ( V_2 , V_43 ,
V_45 , 0 ) ;
F_11 ( V_2 , V_46 ,
V_47 , 0 ) ;
F_11 ( V_2 , V_43 ,
V_48 , 0 ) ;
F_11 ( V_2 , V_43 ,
V_49 , 0 ) ;
F_11 ( V_2 , V_41 ,
V_50 , 0 ) ;
F_11 ( V_2 , V_51 ,
V_52 , 0 ) ;
F_11 ( V_2 , V_51 ,
V_53 , 0 ) ;
F_11 ( V_2 , V_51 ,
V_54 , 0 ) ;
F_11 ( V_2 , V_41 ,
V_55 , 0 ) ;
F_11 ( V_2 , V_41 ,
V_56 , 0 ) ;
F_11 ( V_2 , V_57 ,
V_58 , 0 ) ;
F_11 ( V_2 , V_59 ,
V_60 , 0 ) ;
F_11 ( V_2 , V_61 ,
V_62 , 0 ) ;
F_11 ( V_2 , V_57 ,
V_63 , 0 ) ;
F_11 ( V_2 , V_61 ,
V_64 , 0 ) ;
F_11 ( V_2 , V_59 ,
V_65 , 0 ) ;
F_11 ( V_2 , V_51 ,
V_66 , 0 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
int V_67 ,
int V_68 ,
int V_69 ,
int V_70 ,
int V_27 ,
int V_29 )
{
int V_71 = 0 ;
F_11 ( V_2 , V_41 ,
V_42 , 0x1 ) ;
F_11 ( V_2 , V_43 ,
V_44 , V_68 ) ;
F_11 ( V_2 , V_43 ,
V_45 , V_69 ) ;
F_11 ( V_2 , V_46 ,
V_47 , V_70 ) ;
F_11 ( V_2 , V_43 ,
V_48 , 0x1 ) ;
if ( ! ( F_5 ( V_2 ) && V_27 == 10 && V_29 == 2437 ) )
F_11 ( V_2 , V_43 ,
V_49 , 0x1 ) ;
F_11 ( V_2 , V_41 ,
V_50 , 0x1 ) ;
F_11 ( V_2 , V_51 ,
V_72 , 34 ) ;
F_11 ( V_2 , V_51 ,
V_52 , 1 ) ;
if ( ! F_6 ( V_2 ) &&
F_16 ( V_2 , V_73 ,
V_74 ) == 0x1 )
F_11 ( V_2 , V_51 ,
V_53 , 1 ) ;
V_71 = ( V_67 << 4 ) / 5 ;
if ( V_71 < 0 )
V_71 = V_71 - 1 ;
V_71 = V_71 & 0x7f ;
F_11 ( V_2 , V_51 ,
V_54 , 0x1 ) ;
F_11 ( V_2 , V_41 ,
V_55 , 0x1 ) ;
F_11 ( V_2 , V_41 ,
V_56 , 0x1 ) ;
F_11 ( V_2 , V_57 ,
V_58 , V_71 ) ;
F_11 ( V_2 , V_59 ,
V_60 , V_71 ) ;
F_11 ( V_2 , V_61 ,
V_62 , V_71 ) ;
F_11 ( V_2 , V_57 ,
V_63 , 0xc ) ;
F_11 ( V_2 , V_61 ,
V_64 , 0xc ) ;
F_11 ( V_2 , V_59 ,
V_65 , 0xa0 ) ;
F_11 ( V_2 , V_51 ,
V_66 , 0xff ) ;
}
static void F_21 ( struct V_1 * V_2 ,
int V_67 )
{
int V_71 = 0 ;
V_71 = ( V_67 << 4 ) / 5 ;
if ( V_71 < 0 )
V_71 = V_71 - 1 ;
V_71 = V_71 & 0x7f ;
F_11 ( V_2 , V_57 ,
V_75 ,
V_71 ) ;
F_11 ( V_2 , V_76 ,
V_60 ,
V_71 ) ;
F_11 ( V_2 , V_61 ,
V_77 ,
V_71 ) ;
F_11 ( V_2 , V_57 ,
V_78 , 0xe ) ;
F_11 ( V_2 , V_61 ,
V_79 , 0xe ) ;
F_11 ( V_2 , V_76 ,
V_65 , 0xa0 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_67 ,
int V_27 ,
int V_29 )
{
int V_68 = 0 ;
int V_70 = 0 ;
int V_69 = 0 ;
if ( F_15 ( V_4 ) ) {
if ( V_67 < 0 ) {
if ( F_16 ( V_2 , V_31 ,
V_32 ) == 0x0 )
V_70 = 1 ;
else
V_70 = 0 ;
V_68 = ( ( V_67 + 10 ) << 9 ) / 11 ;
} else {
if ( F_16 ( V_2 , V_31 ,
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
F_20 ( V_2 ,
V_67 ,
V_68 ,
V_69 ,
V_70 ,
V_27 , V_29 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_29 ;
int V_27 = 10 ;
int V_67 = 0 ;
int V_80 ;
T_3 * V_81 ;
unsigned int V_26 ;
struct V_82 * V_83 = & V_2 -> V_84 . V_85 ;
if ( F_24 ( V_4 ) ) {
V_81 = & ( V_83 -> V_86 . V_87 [ 0 ] ) ;
V_80 = 0 ;
}
else {
V_81 = & ( V_83 -> V_88 . V_87 [ 0 ] ) ;
V_80 = 1 ;
}
if ( V_81 [ 0 ] == 0 )
return;
if ( F_15 ( V_4 ) ) {
V_27 = 19 ;
if ( F_16 ( V_2 , V_31 ,
V_32 ) == 0x0 )
V_29 = V_4 -> V_33 - 10 ;
else
V_29 = V_4 -> V_33 + 10 ;
} else {
V_27 = 10 ;
V_29 = V_4 -> V_33 ;
}
F_19 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_89 && V_81 [ V_26 ] ; V_26 ++ ) {
V_67 = F_18 ( V_81 [ V_26 ] , V_80 ) ;
V_67 -= V_29 ;
if ( abs ( V_67 ) < V_27 ) {
F_22 ( V_2 , V_4 , V_67 ,
V_27 , V_29 ) ;
if ( F_5 ( V_2 ) && ( V_26 < 4 ) ) {
V_67 = F_18 ( V_81 [ V_26 + 1 ] ,
V_80 ) ;
V_67 -= V_29 ;
if ( abs ( V_67 ) < V_27 )
F_21 ( V_2 , V_67 ) ;
}
break;
}
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! F_5 ( V_2 ) )
F_12 ( V_2 , V_4 ) ;
F_23 ( V_2 , V_4 ) ;
}
static T_2 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_90 ;
V_90 = F_27 ( 0x5 , V_91 ) ;
if ( V_4 && F_28 ( V_4 ) )
V_90 |= F_27 ( 0x1 , V_92 ) ;
else if ( V_4 && F_29 ( V_4 ) )
V_90 |= F_27 ( 0x2 , V_92 ) ;
V_90 |= F_27 ( 0x2c , V_93 ) ;
return V_90 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_94 ;
T_2 V_95 = 0 ;
V_95 =
( F_31 ( V_2 , V_31 ) & V_96 ) ;
V_94 = V_97 | V_98 |
V_99 | V_95 ;
if ( F_15 ( V_4 ) ) {
V_94 |= V_100 ;
if ( ( V_4 -> V_101 == V_102 ) ||
( V_4 -> V_101 == V_103 ) )
V_94 |= V_32 ;
}
V_94 |= F_31 ( V_2 , V_31 ) ;
V_94 &= ~ V_104 ;
F_10 ( V_2 , V_31 , V_94 ) ;
F_32 ( V_2 ) ;
F_10 ( V_2 , V_105 , 25 << V_106 ) ;
F_10 ( V_2 , V_107 , 0xF << V_108 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_109 ;
V_109 = F_31 ( V_2 , V_110 ) & V_111 ;
F_10 ( V_2 , V_112 , V_113 ) ;
F_34 ( V_2 , V_4 , V_109 ) ;
}
void F_35 ( struct V_1 * V_2 , T_3 V_114 , T_3 V_115 )
{
if ( V_2 -> V_116 . V_117 == 5 || V_2 -> V_116 . V_118 == 5 )
F_36 ( V_2 , V_119 ,
V_120 ) ;
F_10 ( V_2 , V_121 , V_114 ) ;
F_10 ( V_2 , V_122 , V_114 ) ;
if ( ( V_2 -> V_116 . V_123 & V_124 ) && ( V_115 == 0x7 ) )
V_115 = 3 ;
F_10 ( V_2 , V_125 , V_115 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
T_2 V_126 ;
F_36 ( V_2 , V_127 , ( V_128 | V_129 ) ) ;
V_126 = F_31 ( V_2 , V_130 ) & ( ~ V_131 ) ;
F_10 ( V_2 , V_130 ,
V_126 | V_132 | V_133 ) ;
F_36 ( V_2 , V_134 ,
V_135 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_136 * V_137 ,
int V_138 )
{
unsigned int V_26 , V_139 = 0 ;
if ( ! V_137 -> V_140 )
return;
if ( V_138 >= V_137 -> V_141 )
V_138 = 1 ;
for ( V_26 = 0 ; V_26 < V_137 -> V_142 ; V_26 ++ ) {
T_2 V_143 = F_39 ( V_137 , V_26 , 0 ) ;
T_2 V_126 = F_39 ( V_137 , V_26 , V_138 ) ;
F_10 ( V_2 , V_143 , V_126 ) ;
F_40 ( V_139 ) ;
}
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_144 ;
switch ( V_4 -> V_101 ) {
case V_145 :
case V_146 :
if ( V_4 -> V_33 <= 5350 )
V_144 = 1 ;
else if ( ( V_4 -> V_33 > 5350 ) && ( V_4 -> V_33 <= 5600 ) )
V_144 = 3 ;
else
V_144 = 5 ;
break;
case V_102 :
case V_147 :
if ( V_4 -> V_33 <= 5350 )
V_144 = 2 ;
else if ( ( V_4 -> V_33 > 5350 ) && ( V_4 -> V_33 <= 5600 ) )
V_144 = 4 ;
else
V_144 = 6 ;
break;
case V_148 :
case V_149 :
case V_150 :
V_144 = 8 ;
break;
case V_103 :
case V_151 :
V_144 = 7 ;
break;
default:
V_144 = - V_152 ;
}
return V_144 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_139 = 0 , V_26 ;
T_2 V_153 ;
switch ( V_4 -> V_101 ) {
case V_145 :
case V_146 :
V_153 = 1 ;
break;
case V_102 :
case V_147 :
V_153 = 2 ;
break;
case V_148 :
case V_149 :
case V_150 :
V_153 = 4 ;
break;
case V_103 :
case V_151 :
V_153 = 3 ;
break;
default:
return - V_152 ;
}
for ( V_26 = 0 ; V_26 < V_154 ; V_26 ++ ) {
F_38 ( V_2 , & V_2 -> V_155 [ V_26 ] , V_153 ) ;
F_38 ( V_2 , & V_2 -> V_156 [ V_26 ] , V_153 ) ;
F_38 ( V_2 , & V_2 -> V_157 [ V_26 ] , V_153 ) ;
F_38 ( V_2 , & V_2 -> V_158 [ V_26 ] , V_153 ) ;
if ( V_26 == V_159 && F_43 ( V_2 ) )
F_38 ( V_2 ,
& V_2 -> V_160 ,
V_153 ) ;
}
F_44 ( & V_2 -> V_161 , 1 , V_139 ) ;
if ( F_43 ( V_2 ) ) {
if ( F_45 ( V_2 ) == 2 ) {
F_44 ( & V_2 -> V_162 ,
1 , V_139 ) ;
F_44 ( & V_2 -> V_163 ,
V_153 , V_139 ) ;
}
if ( ( F_45 ( V_2 ) == 2 ) ||
( F_45 ( V_2 ) == 3 ) ) {
F_44 ( & V_2 -> V_164 ,
V_153 , V_139 ) ;
}
}
if ( F_8 ( V_2 ) )
F_44 ( & V_2 -> V_165 , V_153 ,
V_139 ) ;
if ( F_8 ( V_2 ) ) {
int V_166 ;
V_166 = F_41 ( V_2 , V_4 ) ;
if ( V_166 < 0 )
return - V_152 ;
F_44 ( & V_2 -> V_167 , V_166 ,
V_139 ) ;
} else {
F_44 ( & V_2 -> V_167 , V_153 , V_139 ) ;
}
if ( F_46 ( V_2 , V_4 ) )
F_44 ( & V_2 -> V_168 ,
V_153 , V_139 ) ;
F_44 ( & V_2 -> V_169 , 1 , V_139 ) ;
if ( V_4 -> V_33 == 2484 )
F_38 ( V_2 , & V_2 -> V_170 , 1 ) ;
if ( F_17 ( V_2 ) || F_5 ( V_2 ) )
F_10 ( V_2 , V_171 ,
V_172 ) ;
V_2 -> V_173 = V_153 ;
F_37 ( V_2 ) ;
F_30 ( V_2 , V_4 ) ;
F_35 ( V_2 , V_2 -> V_174 , V_2 -> V_175 ) ;
F_47 ( V_2 , V_4 , false ) ;
if ( F_17 ( V_2 ) || F_5 ( V_2 ) ) {
if ( F_16 ( V_2 , V_176 ,
V_177 ) )
V_2 -> V_178 |= V_179 ;
else
V_2 -> V_178 &= ~ V_179 ;
if ( F_31 ( V_2 , V_180 ) & V_181 )
V_2 -> V_178 |= V_182 ;
else
V_2 -> V_178 &= ~ V_182 ;
}
return 0 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_183 = 0 ;
if ( V_4 == NULL )
return;
V_183 |= ( F_49 ( V_4 ) || F_50 ( V_4 ) )
? V_74 : V_184 ;
if ( F_46 ( V_2 , V_4 ) )
V_183 |= ( V_74 | V_185 ) ;
if ( F_29 ( V_4 ) )
V_183 |= V_186 ;
if ( F_28 ( V_4 ) )
V_183 |= V_187 ;
if ( V_183 & ( V_186 | V_187 ) )
F_11 ( V_2 , V_188 ,
V_189 , 3 ) ;
F_10 ( V_2 , V_73 , V_183 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_112 , V_190 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_191 , V_192 , V_193 ;
T_2 V_194 = 0x64000000 ;
struct V_12 V_13 ;
if ( F_28 ( V_4 ) )
V_194 = V_194 >> 1 ;
else if ( F_29 ( V_4 ) )
V_194 = V_194 >> 2 ;
F_2 ( V_2 , V_4 , & V_13 ) ;
V_191 = V_194 / V_13 . V_15 ;
F_53 ( V_2 , V_191 , & V_193 ,
& V_192 ) ;
F_11 ( V_2 , V_195 ,
V_196 , V_193 ) ;
F_11 ( V_2 , V_195 ,
V_197 , V_192 ) ;
V_191 = ( 9 * V_191 ) / 10 ;
F_53 ( V_2 , V_191 , & V_193 ,
& V_192 ) ;
F_11 ( V_2 , V_198 ,
V_199 , V_193 ) ;
F_11 ( V_2 , V_198 ,
V_200 , V_192 ) ;
}
static bool F_54 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_201 , V_202 ) ;
return F_55 ( V_2 , V_203 , V_204 ,
V_204 , V_205 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_2 V_109 = F_31 ( V_2 , V_110 ) & V_111 ;
F_34 ( V_2 , V_2 -> V_21 , V_109 ) ;
F_10 ( V_2 , V_201 , 0 ) ;
}
static bool F_57 ( struct V_1 * V_2 ,
enum V_206 V_207 , int V_208 )
{
struct V_209 * V_210 = F_58 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_211 * V_212 = & V_2 -> V_213 ;
int V_214 , V_215 ;
int V_216 , V_217 ;
int V_218 , V_219 ;
int V_220 , V_221 ;
int V_222 , V_223 ;
T_4 V_224 , V_225 ;
switch ( V_207 & V_2 -> V_226 ) {
case V_227 : {
T_2 V_228 = V_208 ? 1 : 0 ;
if ( F_17 ( V_2 ) || F_5 ( V_2 ) )
goto V_229;
V_214 = V_228 ?
V_212 -> V_230 . V_214 : V_231 ;
V_215 = V_228 ?
V_212 -> V_230 . V_215 : V_232 ;
V_216 = V_228 ?
V_212 -> V_230 . V_216 : V_233 ;
V_217 = V_228 ?
V_212 -> V_230 . V_217 : V_234 ;
V_218 = V_228 ?
V_212 -> V_230 . V_218 : V_235 ;
V_219 = V_228 ?
V_212 -> V_230 . V_219 : V_236 ;
V_220 = V_228 ?
V_212 -> V_230 . V_220 : V_237 ;
V_221 = V_228 ?
V_212 -> V_230 . V_221 : V_238 ;
V_222 = V_228 ?
V_212 -> V_230 . V_222 : V_239 ;
V_223 = V_228 ?
V_212 -> V_230 . V_223 : V_240 ;
F_11 ( V_2 , V_241 ,
V_242 ,
V_214 ) ;
F_11 ( V_2 , V_241 ,
V_243 ,
V_215 ) ;
F_11 ( V_2 , V_244 ,
V_245 ,
V_216 ) ;
F_11 ( V_2 , V_244 ,
V_246 ,
V_217 ) ;
F_11 ( V_2 , V_244 ,
V_247 ,
V_218 ) ;
F_11 ( V_2 , V_241 ,
V_248 ,
V_219 ) ;
F_11 ( V_2 , V_46 ,
V_249 ,
V_220 ) ;
F_11 ( V_2 , V_46 ,
V_250 ,
V_221 ) ;
F_11 ( V_2 , V_46 ,
V_251 ,
V_222 ) ;
F_11 ( V_2 , V_46 ,
V_252 ,
V_223 ) ;
V_229:
if ( V_228 )
F_36 ( V_2 , V_241 ,
V_253 ) ;
else
F_59 ( V_2 , V_241 ,
V_253 ) ;
if ( V_228 != V_212 -> V_254 ) {
F_60 ( V_210 , V_255 ,
L_1 ,
V_4 -> V_33 ,
V_212 -> V_254 ?
L_2 : L_3 ,
V_228 ? L_2 : L_3 ) ;
if ( V_228 )
V_2 -> V_256 . V_257 ++ ;
else
V_2 -> V_256 . V_258 ++ ;
V_212 -> V_254 = V_228 ;
}
break;
}
case V_259 : {
T_2 V_260 = V_208 ;
if ( V_260 >= F_61 ( V_261 ) ) {
F_60 ( V_210 , V_255 ,
L_4 ,
V_260 , F_61 ( V_261 ) ) ;
return false ;
}
V_224 = V_261 [ V_260 ] -
V_261 [ V_262 ] +
V_212 -> V_230 . V_263 ;
if ( V_224 < V_264 )
V_224 = V_264 ;
if ( V_224 > V_265 )
V_224 = V_265 ;
F_11 ( V_2 , V_266 ,
V_267 ,
V_224 ) ;
V_225 = V_261 [ V_260 ] -
V_261 [ V_262 ] +
V_212 -> V_230 . V_268 ;
if ( V_225 < V_264 )
V_225 = V_264 ;
if ( V_225 > V_265 )
V_225 = V_265 ;
F_11 ( V_2 , V_269 ,
V_270 , V_225 ) ;
if ( V_260 != V_212 -> V_271 ) {
F_60 ( V_210 , V_255 ,
L_5 ,
V_4 -> V_33 ,
V_212 -> V_271 ,
V_260 ,
V_262 ,
V_224 ,
V_212 -> V_230 . V_263 ) ;
F_60 ( V_210 , V_255 ,
L_6 ,
V_4 -> V_33 ,
V_212 -> V_271 ,
V_260 ,
V_262 ,
V_225 ,
V_212 -> V_230 . V_268 ) ;
if ( V_260 > V_212 -> V_271 )
V_2 -> V_256 . V_272 ++ ;
else if ( V_260 < V_212 -> V_271 )
V_2 -> V_256 . V_273 ++ ;
V_212 -> V_271 = V_260 ;
}
break;
}
case V_274 : {
T_2 V_260 = V_208 ;
if ( V_260 >= F_61 ( V_275 ) ) {
F_60 ( V_210 , V_255 ,
L_7 ,
V_260 , F_61 ( V_275 ) ) ;
return false ;
}
V_224 = V_275 [ V_260 ] -
V_275 [ V_276 ] +
V_212 -> V_230 . V_277 ;
if ( V_224 < V_278 )
V_224 = V_278 ;
if ( V_224 > V_279 )
V_224 = V_279 ;
F_11 ( V_2 , V_280 ,
V_281 ,
V_224 ) ;
V_225 = V_275 [ V_260 ] -
V_275 [ V_276 ] +
V_212 -> V_230 . V_282 ;
if ( V_225 < V_278 )
V_225 = V_278 ;
if ( V_225 > V_279 )
V_225 = V_279 ;
F_11 ( V_2 , V_283 ,
V_284 , V_225 ) ;
if ( V_260 != V_212 -> V_285 ) {
F_60 ( V_210 , V_255 ,
L_8 ,
V_4 -> V_33 ,
V_212 -> V_285 ,
V_260 ,
V_276 ,
V_224 ,
V_212 -> V_230 . V_277 ) ;
F_60 ( V_210 , V_255 ,
L_9 ,
V_4 -> V_33 ,
V_212 -> V_285 ,
V_260 ,
V_276 ,
V_225 ,
V_212 -> V_230 . V_282 ) ;
if ( V_260 > V_212 -> V_285 )
V_2 -> V_256 . V_286 ++ ;
else if ( V_260 < V_212 -> V_285 )
V_2 -> V_256 . V_287 ++ ;
V_212 -> V_285 = V_260 ;
}
break;
}
case V_288 : {
bool V_289 = V_208 ? 1 : 0 ;
F_11 ( V_2 , V_290 ,
V_291 , V_289 ) ;
F_11 ( V_2 , V_290 ,
V_292 , V_289 ) ;
if ( V_289 != V_212 -> V_293 ) {
F_60 ( V_210 , V_255 , L_10 ,
V_4 -> V_33 ,
V_212 -> V_293 ? L_2 : L_3 ,
V_289 ? L_2 : L_3 ) ;
if ( V_289 )
V_2 -> V_256 . V_294 ++ ;
else
V_2 -> V_256 . V_295 ++ ;
V_212 -> V_293 = V_289 ;
}
break;
}
case V_296 :
break;
default:
F_60 ( V_210 , V_255 , L_11 , V_207 ) ;
return false ;
}
F_60 ( V_210 , V_255 ,
L_12 ,
V_212 -> V_285 ,
V_212 -> V_254 ? L_2 : L_3 ,
V_212 -> V_271 ,
V_212 -> V_293 ? L_2 : L_3 ,
V_212 -> V_297 ,
V_212 -> V_298 ,
V_212 -> V_299 ) ;
return true ;
}
static void F_62 ( struct V_1 * V_2 ,
T_5 V_300 [ V_301 ] )
{
#define F_63 0x1FF00000
#define F_64 20
#define F_65 0x01FF0000
#define F_66 16
T_5 V_302 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_303 ; V_26 ++ ) {
if ( V_2 -> V_174 & F_67 ( V_26 ) ) {
V_302 = F_68 ( F_31 ( V_2 , V_2 -> V_304 [ V_26 ] ) ,
F_63 ) ;
V_300 [ V_26 ] = F_69 ( V_302 , 8 ) ;
if ( F_15 ( V_2 -> V_21 ) ) {
T_3 V_305 = V_303 + V_26 ;
V_302 = F_68 ( F_31 ( V_2 , V_2 -> V_304 [ V_305 ] ) ,
F_65 ) ;
V_300 [ V_305 ] = F_69 ( V_302 , 8 ) ;
}
}
}
}
static void F_70 ( struct V_1 * V_2 )
{
V_2 -> V_306 . V_307 = V_308 ;
V_2 -> V_306 . V_309 = V_310 ;
V_2 -> V_306 . V_311 = V_312 ;
V_2 -> V_313 . V_307 = V_314 ;
V_2 -> V_313 . V_309 = V_315 ;
V_2 -> V_313 . V_311 = V_316 ;
if ( F_3 ( V_2 ) )
V_2 -> V_306 . V_311 = V_317 ;
if ( F_17 ( V_2 ) || F_5 ( V_2 ) ) {
V_2 -> V_306 . V_309 = V_318 ;
V_2 -> V_306 . V_311 = V_319 ;
V_2 -> V_313 . V_309 = V_320 ;
V_2 -> V_313 . V_311 = V_321 ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_211 * V_212 ;
struct V_209 * V_210 = F_58 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_322 * V_230 ;
T_2 V_126 ;
V_212 = & V_2 -> V_213 ;
V_230 = & V_212 -> V_230 ;
F_60 ( V_210 , V_255 , L_13 ,
V_2 -> V_323 . V_324 ,
V_2 -> V_323 . V_325 ,
V_2 -> V_326 ,
V_4 -> V_33 ,
V_4 -> V_327 ) ;
V_126 = F_31 ( V_2 , V_244 ) ;
V_230 -> V_216 = F_68 ( V_126 , V_245 ) ;
V_230 -> V_217 = F_68 ( V_126 , V_246 ) ;
V_230 -> V_218 = F_68 ( V_126 , V_247 ) ;
V_126 = F_31 ( V_2 , V_241 ) ;
V_230 -> V_214 = F_68 ( V_126 , V_242 ) ;
V_230 -> V_215 = F_68 ( V_126 , V_243 ) ;
V_230 -> V_219 = F_68 ( V_126 , V_248 ) ;
V_126 = F_31 ( V_2 , V_46 ) ;
V_230 -> V_222 = F_68 ( V_126 , V_251 ) ;
V_230 -> V_223 = F_68 ( V_126 , V_252 ) ;
V_230 -> V_220 = F_68 ( V_126 , V_249 ) ;
V_230 -> V_221 = F_68 ( V_126 , V_250 ) ;
V_230 -> V_263 = F_16 ( V_2 ,
V_266 ,
V_267 ) ;
V_230 -> V_268 = F_16 ( V_2 ,
V_269 ,
V_270 ) ;
V_230 -> V_277 = F_16 ( V_2 ,
V_280 ,
V_281 ) ;
V_230 -> V_282 = F_16 ( V_2 ,
V_283 ,
V_284 ) ;
V_212 -> V_285 = V_276 ;
V_212 -> V_271 = V_262 ;
V_212 -> V_254 = true ;
V_212 -> V_293 = true ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_328 * V_329 )
{
T_2 V_330 = 0 , V_331 = 0 ;
if ( ! V_329 ) {
F_59 ( V_2 , V_332 , V_333 ) ;
return;
}
V_330 |= V_333 | V_334 ;
V_330 |= F_27 ( V_329 -> V_335 , V_336 ) ;
V_330 |= F_27 ( V_329 -> V_337 , V_338 ) ;
V_330 |= F_27 ( V_329 -> V_339 , V_340 ) ;
V_330 |= F_27 ( V_329 -> V_341 , V_342 ) ;
V_330 |= F_27 ( V_329 -> V_343 , V_344 ) ;
V_331 |= V_345 ;
V_331 |= V_346 ;
V_331 |= F_27 ( V_329 -> V_347 , V_348 ) ;
V_331 |= F_27 ( V_329 -> V_349 , V_350 ) ;
V_331 |= F_27 ( V_329 -> V_351 , V_352 ) ;
F_10 ( V_2 , V_332 , V_330 ) ;
F_10 ( V_2 , V_353 , V_331 ) ;
if ( V_329 -> V_354 )
F_36 ( V_2 , V_355 , V_356 ) ;
else
F_59 ( V_2 , V_355 , V_356 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_328 * V_329 = & V_2 -> V_357 ;
V_329 -> V_335 = - 28 ;
V_329 -> V_337 = 0 ;
V_329 -> V_339 = 10 ;
V_329 -> V_341 = 24 ;
V_329 -> V_343 = 8 ;
V_329 -> V_347 = 255 ;
V_329 -> V_349 = 12 ;
V_329 -> V_351 = 8 ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_358 * V_359 )
{
T_2 V_360 ;
V_360 = F_31 ( V_2 , V_361 ) ;
V_359 -> V_362 = ( V_360 & V_363 ) >>
V_364 ;
V_359 -> V_365 = ( V_360 & V_366 ) >>
V_367 ;
V_359 -> V_368 = ( V_360 & V_369 ) >>
V_370 ;
if ( F_75 ( V_2 ) ) {
V_359 -> V_371 = - 9 ;
V_359 -> V_372 = 1 ;
} else if ( F_4 ( V_2 ) ) {
V_359 -> V_371 = - 9 ;
V_359 -> V_372 = 2 ;
} else if ( F_5 ( V_2 ) ) {
V_359 -> V_371 = - 3 ;
V_359 -> V_372 = 3 ;
} else {
V_359 -> V_371 = - 3 ;
V_359 -> V_372 = 0 ;
}
}
static void F_76 ( struct V_1 * V_2 ,
struct V_358 * V_359 )
{
T_2 V_360 ;
V_360 = F_31 ( V_2 , V_361 ) ;
V_360 &= ~ ( V_363 |
V_366 |
V_369 |
V_373 |
V_374 ) ;
V_360 |= ( ( V_359 -> V_362 << V_364 )
& V_363 ) ;
V_360 |= ( ( V_359 -> V_365 << V_367 )
& V_366 ) ;
V_360 |= ( ( V_359 -> V_368 << V_370 )
& V_369 ) ;
V_360 |= ( ( V_359 -> V_375 << V_376 )
& V_373 ) ;
V_360 |= ( ( V_359 -> V_377 << V_378 )
& V_374 ) ;
F_10 ( V_2 , V_361 , V_360 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
bool V_379 )
{
T_3 V_380 ;
T_2 V_360 ;
if ( ! F_5 ( V_2 ) )
return;
V_2 -> V_381 = V_379 ;
V_380 = V_2 -> V_382 -> V_383 ( V_2 , V_384 ) ;
V_360 = F_31 ( V_2 , V_361 ) ;
V_360 &= ( ~ V_385 ) ;
V_360 |= ( V_380 & 0x3f ) << V_386 ;
V_360 &= ~ V_387 ;
V_360 |= ( ( V_380 >> 6 ) & 0x1 ) << V_388 ;
if ( V_379 )
V_360 |= V_389 ;
F_10 ( V_2 , V_361 , V_360 ) ;
V_360 = F_31 ( V_2 , V_134 ) ;
V_360 &= ~ V_390 ;
V_360 |= ( ( V_380 >> 7 ) & 0x1 ) << V_391 ;
if ( V_379 )
V_360 |= V_390 ;
F_10 ( V_2 , V_134 , V_360 ) ;
if ( V_379 ) {
F_36 ( V_2 , V_361 ,
( 1 << V_392 ) ) ;
if ( V_2 -> V_21 && F_14 ( V_2 -> V_21 ) )
F_36 ( V_2 , V_393 ,
V_394 ) ;
F_36 ( V_2 , V_395 ,
V_396 ) ;
} else {
F_59 ( V_2 , V_361 , V_389 ) ;
F_59 ( V_2 , V_361 ,
( 1 << V_392 ) ) ;
F_59 ( V_2 , V_134 , V_390 ) ;
F_59 ( V_2 , V_395 ,
V_396 ) ;
V_360 = F_31 ( V_2 , V_361 ) ;
V_360 &= ~ ( V_363 |
V_366 |
V_373 |
V_374 ) ;
V_360 |= ( V_397 << V_364 ) ;
V_360 |= ( V_398 << V_367 ) ;
F_10 ( V_2 , V_361 , V_360 ) ;
}
}
static int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 * V_399 )
{
unsigned int V_139 = 0 ;
T_2 V_153 ;
switch ( V_4 -> V_101 ) {
case V_145 :
case V_146 :
V_153 = 1 ;
break;
case V_102 :
case V_147 :
V_153 = 2 ;
break;
case V_148 :
case V_149 :
case V_150 :
V_153 = 4 ;
break;
case V_103 :
case V_151 :
V_153 = 3 ;
break;
default:
return - V_152 ;
}
if ( V_153 == V_2 -> V_173 ) {
* V_399 = false ;
goto V_400;
}
F_38 ( V_2 , & V_2 -> V_155 [ V_159 ] , V_153 ) ;
F_38 ( V_2 , & V_2 -> V_156 [ V_159 ] , V_153 ) ;
F_38 ( V_2 , & V_2 -> V_157 [ V_159 ] , V_153 ) ;
F_38 ( V_2 , & V_2 -> V_158 [ V_159 ] , V_153 ) ;
if ( F_43 ( V_2 ) )
F_38 ( V_2 , & V_2 -> V_160 ,
V_153 ) ;
F_44 ( & V_2 -> V_167 , V_153 , V_139 ) ;
if ( F_46 ( V_2 , V_4 ) )
F_44 ( & V_2 -> V_168 , V_153 , V_139 ) ;
if ( F_5 ( V_2 ) )
F_44 ( & V_2 -> V_168 , 1 , V_139 ) ;
F_44 ( & V_2 -> V_169 , 1 , V_139 ) ;
V_2 -> V_173 = V_153 ;
* V_399 = true ;
V_400:
F_48 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_401 * V_208 )
{
T_3 V_402 ;
if ( ! V_208 -> V_403 ) {
F_59 ( V_2 , V_404 ,
V_405 ) ;
return;
}
F_36 ( V_2 , V_332 , V_334 ) ;
F_36 ( V_2 , V_404 , V_405 ) ;
V_402 = V_208 -> V_402 ;
if ( V_208 -> V_406 )
V_402 = 0 ;
else if ( V_208 -> V_402 == 0 )
V_402 = 1 ;
if ( V_208 -> V_407 )
F_36 ( V_2 , V_404 ,
V_408 ) ;
else
F_59 ( V_2 , V_404 ,
V_408 ) ;
F_11 ( V_2 , V_404 ,
V_409 , V_402 ) ;
F_11 ( V_2 , V_404 ,
V_410 , V_208 -> V_411 ) ;
F_11 ( V_2 , V_404 ,
V_412 , V_208 -> V_413 ) ;
return;
}
static void F_80 ( struct V_1 * V_2 )
{
F_36 ( V_2 , V_404 ,
V_414 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_209 * V_210 = F_58 ( V_2 ) ;
if ( ! F_55 ( V_2 , V_404 ,
V_414 ,
0 , V_205 ) ) {
F_82 ( V_210 , L_14 ) ;
return;
}
}
void F_83 ( struct V_1 * V_2 )
{
struct V_415 * V_416 = F_84 ( V_2 ) ;
struct V_417 * V_418 = F_85 ( V_2 ) ;
static const T_2 V_419 [ 6 ] = {
V_420 ,
V_421 ,
V_422 ,
V_283 ,
V_423 ,
V_424 ,
} ;
V_416 -> V_425 = F_1 ;
V_416 -> V_426 = F_25 ;
V_416 -> V_427 = F_26 ;
V_416 -> V_428 = F_30 ;
V_416 -> V_429 = F_33 ;
V_416 -> V_430 = F_42 ;
V_416 -> V_400 = F_48 ;
V_416 -> V_431 = F_51 ;
V_416 -> V_432 = F_52 ;
V_416 -> V_433 = F_54 ;
V_416 -> V_434 = F_56 ;
V_416 -> V_435 = F_57 ;
V_416 -> V_436 = F_62 ;
V_416 -> V_437 = F_71 ;
V_416 -> V_438 = F_72 ;
V_416 -> V_439 = F_78 ;
V_418 -> V_440 = F_74 ;
V_418 -> V_441 = F_76 ;
V_418 -> V_442 = F_77 ;
V_418 -> V_443 = F_79 ;
V_418 -> V_444 = F_80 ;
V_418 -> V_445 = F_81 ;
F_70 ( V_2 ) ;
F_73 ( V_2 ) ;
memcpy ( V_2 -> V_304 , V_419 , sizeof( V_2 -> V_304 ) ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_209 * V_210 = F_58 ( V_2 ) ;
T_2 V_446 = V_2 -> V_447 ;
T_2 V_126 , V_448 ;
if ( ! V_446 ) {
F_10 ( V_2 , V_449 ,
F_31 ( V_2 , V_449 ) &
~ ( V_450 |
V_451 ) ) ;
F_10 ( V_2 , V_452 ,
F_31 ( V_2 , V_452 ) &
~ ( V_453 |
V_454 ) ) ;
F_60 ( V_210 , V_455 , L_15 ) ;
return;
}
V_126 = F_31 ( V_2 , V_449 ) & V_456 ;
F_10 ( V_2 , V_449 ,
( V_126 | V_451 ) &
~ V_450 ) ;
if ( V_446 > 10000 )
V_446 = 10000 ;
V_448 = ( 100 * V_446 ) / 74 ;
if ( V_2 -> V_21 && F_15 ( V_2 -> V_21 ) )
V_448 = ( 100 * V_446 ) / 37 ;
F_10 ( V_2 , V_452 ,
V_453 |
V_457 |
( V_458 & ( V_448 << 2 ) ) ) ;
F_60 ( V_210 , V_455 , L_16 ,
V_446 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
V_2 -> V_459 = F_31 ( V_2 , V_460 ) ;
F_10 ( V_2 , V_460 ,
V_2 -> V_459 & ~ V_461 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_209 * V_210 = F_58 ( V_2 ) ;
T_2 V_462 ;
if ( F_89 ( ! ( V_210 -> V_463 & V_464 ) ) )
return;
V_462 = V_2 -> V_459 ;
F_60 ( V_210 , V_455 ,
L_17 , V_462 ) ;
F_60 ( V_210 , V_455 ,
L_18 ,
F_68 ( V_462 , V_465 ) ,
F_68 ( V_462 , V_466 ) ,
F_68 ( V_462 , V_467 ) ,
F_68 ( V_462 , V_468 ) ,
F_68 ( V_462 , V_469 ) ,
F_68 ( V_462 , V_470 ) ,
F_68 ( V_462 , V_471 ) ,
F_68 ( V_462 , V_472 ) ,
F_68 ( V_462 , V_473 ) ) ;
F_60 ( V_210 , V_455 , L_19 ,
F_31 ( V_2 , V_452 ) ,
F_31 ( V_2 , V_449 ) ) ;
F_60 ( V_210 , V_455 , L_20 ,
F_31 ( V_2 , V_31 ) ) ;
#define F_90 ( T_6 ) (common->cc_survey._field * 100 / common->cc_survey.cycles)
if ( V_210 -> V_474 . V_475 )
F_60 ( V_210 , V_455 ,
L_21 ,
F_90 ( V_476 ) , F_90 ( V_477 ) , F_90 ( V_478 ) ) ;
F_60 ( V_210 , V_455 , L_22 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
T_2 V_126 ;
if ( ! ( ( F_68 ( V_2 -> V_459 ,
V_468 ) == 0xb ) ||
V_2 -> V_479 ) )
return;
V_2 -> V_479 = true ;
V_126 = F_31 ( V_2 , V_393 ) ;
V_126 &= ~ V_480 ;
F_10 ( V_2 , V_393 , V_126 ) ;
}
