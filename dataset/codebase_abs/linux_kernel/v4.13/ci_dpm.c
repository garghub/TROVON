static T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) ( ( F_2 ( V_3 ) >> 16 ) & 0xff ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_2 V_4 , T_2 V_5 )
{
T_2 V_6 ;
T_2 V_7 ;
T_2 V_8 ;
T_2 V_9 ;
switch ( V_4 ) {
case V_10 :
V_6 = F_2 ( V_11 ) ;
V_7 = F_2 ( V_12 ) ;
V_8 = ( F_2 ( V_13 ) & V_14 ) >>
V_15 ;
break;
case V_16 :
V_6 = F_2 ( V_17 ) ;
V_7 = F_2 ( V_18 ) ;
V_8 = ( F_2 ( V_13 ) & V_19 ) >>
V_20 ;
break;
default:
return - V_21 ;
}
switch ( V_5 ) {
case V_10 :
F_4 ( V_11 , V_6 ) ;
F_4 ( V_12 , V_7 ) ;
F_5 ( V_13 , ( V_8 << V_15 ) ,
~ V_14 ) ;
break;
case V_16 :
F_4 ( V_17 , V_6 ) ;
F_4 ( V_18 , V_7 ) ;
F_5 ( V_13 , ( V_8 << V_20 ) ,
~ V_19 ) ;
break;
default:
return - V_21 ;
}
V_9 = F_2 ( V_22 ) | 0x0000000F ;
F_4 ( V_22 , V_9 ) ;
F_5 ( V_23 , ( V_5 ) << V_24 ,
~ V_25 ) ;
return 0 ;
}
static T_1 F_6 ( T_2 V_26 )
{
T_1 V_27 ;
if ( V_26 < 10000 )
V_27 = 0 ;
else if ( V_26 >= 80000 )
V_27 = 0x0f ;
else
V_27 = ( T_1 ) ( ( V_26 - 10000 ) / 5000 + 1 ) ;
return V_27 ;
}
static T_1 F_7 ( T_2 V_26 , bool V_28 )
{
T_1 V_27 ;
if ( V_28 ) {
if ( V_26 < 12500 )
V_27 = 0x00 ;
else if ( V_26 > 47500 )
V_27 = 0x0f ;
else
V_27 = ( T_1 ) ( ( V_26 - 10000 ) / 2500 ) ;
} else {
if ( V_26 < 65000 )
V_27 = 0x00 ;
else if ( V_26 > 135000 )
V_27 = 0x0f ;
else
V_27 = ( T_1 ) ( ( V_26 - 60000 ) / 5000 ) ;
}
return V_27 ;
}
static void F_8 ( struct V_1 * V_2 ,
T_2 V_29 ,
struct V_30 * V_31 )
{
unsigned int V_32 , V_33 ;
if ( V_31 -> V_34 <= V_29 )
return;
V_33 = V_31 -> V_34 - V_29 ;
for ( V_32 = 0 ; V_32 < V_29 ; V_32 ++ )
V_31 -> V_35 [ V_32 ] = V_31 -> V_35 [ V_32 + V_33 ] ;
V_31 -> V_34 = V_29 ;
}
static struct V_36 * F_9 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_38 . V_39 . V_40 ;
return V_37 ;
}
static struct V_41 * F_10 ( struct V_42 * V_43 )
{
struct V_41 * V_44 = V_43 -> V_45 ;
return V_44 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
switch ( V_2 -> V_46 -> V_47 ) {
case 0x6649 :
case 0x6650 :
case 0x6651 :
case 0x6658 :
case 0x665C :
case 0x665D :
default:
V_37 -> V_48 = & V_49 ;
break;
case 0x6640 :
case 0x6641 :
case 0x6646 :
case 0x6647 :
V_37 -> V_48 = & V_50 ;
break;
case 0x67B8 :
case 0x67B0 :
V_37 -> V_48 = & V_51 ;
break;
case 0x67BA :
case 0x67B1 :
V_37 -> V_48 = & V_52 ;
break;
case 0x67A0 :
case 0x67A1 :
case 0x67A2 :
case 0x67A8 :
case 0x67A9 :
case 0x67AA :
case 0x67B9 :
case 0x67BE :
V_37 -> V_48 = & V_49 ;
break;
}
V_37 -> V_53 = 0 ;
V_37 -> V_54 = true ;
V_37 -> V_55 = false ;
V_37 -> V_56 = false ;
V_37 -> V_57 = false ;
V_37 -> V_58 = false ;
V_37 -> V_59 = false ;
if ( V_37 -> V_54 ) {
V_37 -> V_55 = true ;
if ( V_2 -> V_60 == V_61 )
V_37 -> V_62 = false ;
else
V_37 -> V_62 = true ;
V_37 -> V_63 = true ;
V_37 -> V_64 = true ;
}
}
static T_1 F_12 ( T_3 V_65 )
{
return ( 6200 - ( V_65 * V_66 ) ) / 25 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_1 * V_67 = V_37 -> V_68 . V_69 ;
T_1 * V_70 = V_37 -> V_68 . V_71 ;
T_1 * V_72 = V_37 -> V_68 . V_73 ;
T_2 V_32 ;
if ( V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 == NULL )
return - V_21 ;
if ( V_2 -> V_38 . V_39 . V_74 . V_75 . V_34 > 8 )
return - V_21 ;
if ( V_2 -> V_38 . V_39 . V_74 . V_75 . V_34 !=
V_2 -> V_38 . V_39 . V_74 . V_76 . V_34 )
return - V_21 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_38 . V_39 . V_74 . V_75 . V_34 ; V_32 ++ ) {
if ( V_2 -> V_38 . V_39 . V_77 & V_78 ) {
V_70 [ V_32 ] = F_12 ( V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_32 ] . V_79 ) ;
V_67 [ V_32 ] = F_12 ( V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_32 ] . V_80 ) ;
V_72 [ V_32 ] = F_12 ( V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_32 ] . V_81 ) ;
} else {
V_70 [ V_32 ] = F_12 ( V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_32 ] . V_65 ) ;
V_67 [ V_32 ] = F_12 ( ( T_3 ) V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_32 ] . V_82 ) ;
}
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_1 * V_83 = V_37 -> V_68 . V_84 ;
T_2 V_32 ;
if ( V_37 -> V_85 . V_34 > 8 )
return - V_21 ;
for ( V_32 = 0 ; V_32 < V_37 -> V_85 . V_34 ; V_32 ++ )
V_83 [ V_32 ] = F_12 ( V_37 -> V_85 . V_35 [ V_32 ] . V_86 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
const struct V_87 * V_88 = V_37 -> V_48 ;
V_37 -> V_68 . V_89 = V_88 -> V_90 ;
V_37 -> V_68 . V_91 = V_88 -> V_92 ;
V_37 -> V_68 . V_93 = 3 ;
V_37 -> V_68 . V_94 = 0 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
const struct V_87 * V_88 = V_37 -> V_48 ;
T_3 V_95 ;
V_95 = V_2 -> V_38 . V_39 . V_74 . V_96 -> V_97 * 256 ;
V_37 -> V_68 . V_98 = F_17 ( V_95 ) ;
V_37 -> V_68 . V_99 =
V_88 -> V_100 ;
V_37 -> V_68 . V_101 = V_88 -> V_102 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
const struct V_87 * V_88 = V_37 -> V_48 ;
int V_103 ;
V_103 = F_19 ( V_2 ,
V_104 +
F_20 ( V_105 , V_106 ) +
F_20 ( V_107 , V_108 ) ,
( T_2 * ) & V_37 -> V_68 . V_108 ,
V_37 -> V_109 ) ;
if ( V_103 )
return - V_21 ;
else
V_37 -> V_68 . V_108 = V_88 -> V_110 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( ( V_2 -> V_38 . V_39 . V_111 . V_112 & ( 1 << 15 ) ) ||
( V_2 -> V_38 . V_39 . V_111 . V_112 == 0 ) )
V_2 -> V_38 . V_39 . V_111 . V_112 =
V_2 -> V_38 . V_39 . V_111 . V_113 ;
V_37 -> V_68 . V_114 =
F_17 ( V_2 -> V_38 . V_39 . V_111 . V_112 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_1 * V_67 = V_37 -> V_68 . V_69 ;
T_1 * V_70 = V_37 -> V_68 . V_71 ;
int V_32 , V_115 , V_116 ;
V_115 = V_116 = V_67 [ 0 ] ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
if ( 0 != V_67 [ V_32 ] ) {
if ( V_115 > V_67 [ V_32 ] )
V_115 = V_67 [ V_32 ] ;
if ( V_116 < V_67 [ V_32 ] )
V_116 = V_67 [ V_32 ] ;
}
if ( 0 != V_70 [ V_32 ] ) {
if ( V_115 > V_70 [ V_32 ] )
V_115 = V_70 [ V_32 ] ;
if ( V_116 < V_70 [ V_32 ] )
V_116 = V_70 [ V_32 ] ;
}
}
if ( ( V_115 == 0 ) || ( V_116 == 0 ) )
return - V_21 ;
V_37 -> V_68 . V_117 = ( T_1 ) V_116 ;
V_37 -> V_68 . V_118 = ( T_1 ) V_115 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_3 V_119 = V_37 -> V_68 . V_120 ;
T_3 V_121 = V_37 -> V_68 . V_122 ;
struct V_123 * V_96 =
V_2 -> V_38 . V_39 . V_74 . V_96 ;
V_119 = V_96 -> V_124 / 100 * 256 ;
V_121 = V_96 -> V_125 / 100 * 256 ;
V_37 -> V_68 . V_120 = F_17 ( V_119 ) ;
V_37 -> V_68 . V_122 = F_17 ( V_121 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
const struct V_87 * V_88 = V_37 -> V_48 ;
T_4 * V_126 = & V_37 -> V_127 ;
struct V_123 * V_96 =
V_2 -> V_38 . V_39 . V_74 . V_96 ;
struct V_128 * V_129 = V_2 -> V_38 . V_39 . V_74 . V_130 ;
int V_32 , V_131 , V_132 ;
const T_3 * V_133 ;
const T_3 * V_134 ;
V_126 -> V_135 = V_96 -> V_136 * 256 ;
V_126 -> V_137 = V_96 -> V_138 * 256 ;
V_126 -> V_139 = ( T_1 ) V_37 -> V_53 ;
V_126 -> V_140 =
( T_1 ) ( V_37 -> V_141 . V_142 / 1000 ) ;
V_126 -> V_143 = 8 ;
V_126 -> V_144 = V_88 -> V_145 ;
if ( V_129 ) {
V_126 -> V_146 = F_17 ( ( T_3 ) V_129 -> V_147 * 256 / 1000 ) ;
V_126 -> V_148 = F_17 ( ( T_3 ) V_129 -> V_149 * 256 ) ;
} else {
V_126 -> V_146 = F_17 ( 0 ) ;
V_126 -> V_148 = F_17 ( 0 ) ;
}
V_126 -> V_150 = F_25 ( V_88 -> V_151 ) ;
V_133 = V_88 -> V_152 ;
V_134 = V_88 -> V_153 ;
for ( V_32 = 0 ; V_32 < V_154 ; V_32 ++ ) {
for ( V_131 = 0 ; V_131 < V_155 ; V_131 ++ ) {
for ( V_132 = 0 ; V_132 < V_156 ; V_132 ++ ) {
V_126 -> V_157 [ V_32 ] [ V_131 ] [ V_132 ] = F_17 ( * V_133 ) ;
V_126 -> V_158 [ V_32 ] [ V_131 ] [ V_132 ] = F_17 ( * V_134 ) ;
V_133 ++ ;
V_134 ++ ;
}
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_159 ;
int V_103 ;
if ( V_37 -> V_54 ) {
V_103 = F_19 ( V_2 ,
V_104 +
F_20 ( V_105 , V_106 ) ,
& V_159 , V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_13 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_14 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_15 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_16 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_18 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_21 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_22 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_23 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_27 ( V_2 , V_159 ,
( T_1 * ) & V_37 -> V_68 ,
sizeof( V_107 ) , V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , const bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_161 ;
if ( V_37 -> V_56 ) {
V_161 = F_29 ( V_162 ) ;
if ( V_160 )
V_161 |= V_163 ;
else
V_161 &= ~ V_163 ;
F_30 ( V_162 , V_161 ) ;
}
if ( V_37 -> V_57 ) {
V_161 = F_29 ( V_164 ) ;
if ( V_160 )
V_161 |= V_165 ;
else
V_161 &= ~ V_165 ;
F_30 ( V_164 , V_161 ) ;
}
if ( V_37 -> V_58 ) {
V_161 = F_29 ( V_166 ) ;
if ( V_160 )
V_161 |= V_167 ;
else
V_161 &= ~ V_167 ;
F_30 ( V_166 , V_161 ) ;
}
if ( V_37 -> V_59 ) {
V_161 = F_29 ( V_168 ) ;
if ( V_160 )
V_161 |= V_169 ;
else
V_161 &= ~ V_169 ;
F_30 ( V_168 , V_161 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_170 * V_171 )
{
const struct V_170 * V_172 = V_171 ;
T_2 V_161 ;
T_2 V_173 = 0 ;
if ( V_172 == NULL )
return - V_21 ;
while ( V_172 -> V_174 != 0xFFFFFFFF ) {
if ( V_172 -> type == V_175 ) {
V_173 |= ( ( V_172 -> V_86 << V_172 -> V_176 ) & V_172 -> V_177 ) ;
} else {
switch ( V_172 -> type ) {
case V_178 :
V_161 = F_32 ( V_172 -> V_174 ) ;
break;
case V_179 :
V_161 = F_29 ( V_172 -> V_174 ) ;
break;
default:
V_161 = F_2 ( V_172 -> V_174 ) ;
break;
}
V_161 &= ~ V_172 -> V_177 ;
V_161 |= ( ( V_172 -> V_86 << V_172 -> V_176 ) & V_172 -> V_177 ) ;
V_161 |= V_173 ;
switch ( V_172 -> type ) {
case V_178 :
F_33 ( V_172 -> V_174 , V_161 ) ;
break;
case V_179 :
F_30 ( V_172 -> V_174 , V_161 ) ;
break;
default:
F_4 ( V_172 -> V_174 , V_161 ) ;
break;
}
V_173 = 0 ;
}
V_172 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 ;
if ( V_37 -> V_56 || V_37 -> V_57 ||
V_37 -> V_58 || V_37 -> V_59 ) {
V_2 -> V_180 . V_181 . V_182 -> V_183 ( V_2 ) ;
if ( V_160 ) {
V_103 = F_31 ( V_2 , V_184 ) ;
if ( V_103 ) {
V_2 -> V_180 . V_181 . V_182 -> V_185 ( V_2 ) ;
return V_103 ;
}
}
F_28 ( V_2 , V_160 ) ;
V_2 -> V_180 . V_181 . V_182 -> V_185 ( V_2 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_186 ;
int V_103 = 0 ;
if ( V_160 ) {
V_37 -> V_187 = 0 ;
if ( V_37 -> V_54 ) {
if ( V_37 -> V_62 ) {
V_186 = F_36 ( V_2 , V_188 ) ;
if ( V_186 != V_189 )
V_103 = - V_21 ;
else
V_37 -> V_187 |= V_190 ;
}
if ( V_37 -> V_63 ) {
V_186 = F_36 ( V_2 , V_191 ) ;
if ( V_186 != V_189 )
V_103 = - V_21 ;
else
V_37 -> V_187 |= V_192 ;
}
if ( V_37 -> V_64 ) {
V_186 = F_36 ( V_2 , V_193 ) ;
if ( V_186 != V_189 ) {
V_103 = - V_21 ;
} else {
struct V_123 * V_96 =
V_2 -> V_38 . V_39 . V_74 . V_96 ;
T_2 V_194 =
( T_2 ) ( V_96 -> V_195 * 256 ) ;
V_37 -> V_187 |= V_196 ;
F_37 ( V_2 , V_194 ) ;
}
}
}
} else {
if ( V_37 -> V_54 && V_37 -> V_187 ) {
if ( V_37 -> V_187 & V_192 )
F_36 ( V_2 , V_197 ) ;
if ( V_37 -> V_187 & V_190 )
F_36 ( V_2 , V_198 ) ;
if ( V_37 -> V_187 & V_196 )
F_36 ( V_2 , V_199 ) ;
V_37 -> V_187 = 0 ;
}
}
return V_103 ;
}
static int F_38 ( struct V_1 * V_2 , bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_186 ;
int V_103 = 0 ;
if ( V_37 -> V_55 ) {
if ( V_160 ) {
V_186 = F_36 ( V_2 , V_200 ) ;
if ( V_186 != V_189 ) {
V_103 = - V_21 ;
V_37 -> V_201 = false ;
} else {
V_37 -> V_201 = true ;
}
} else if ( V_37 -> V_201 ) {
F_36 ( V_2 , V_202 ) ;
V_37 -> V_201 = false ;
}
}
return V_103 ;
}
static int F_39 ( struct V_1 * V_2 ,
bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_186 = V_189 ;
if ( V_37 -> V_203 ) {
if ( V_160 )
V_186 = F_36 ( V_2 , V_204 ) ;
else
V_186 = F_36 ( V_2 , V_205 ) ;
}
if ( V_186 == V_189 )
return 0 ;
else
return - V_21 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_123 * V_96 =
V_2 -> V_38 . V_39 . V_74 . V_96 ;
T_6 V_206 ;
T_6 V_207 ;
int V_103 = 0 ;
bool V_208 = false ;
if ( V_37 -> V_54 ) {
V_206 = V_208 ?
V_2 -> V_38 . V_39 . V_209 : ( - 1 * V_2 -> V_38 . V_39 . V_209 ) ;
V_207 = ( ( 100 + V_206 ) *
( T_6 ) V_96 -> V_138 ) / 100 ;
V_103 = F_41 ( V_2 , ( T_2 ) V_207 ) ;
}
return V_103 ;
}
static void F_42 ( struct V_1 * V_2 , bool V_210 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
V_37 -> V_211 = V_210 ;
if ( V_210 ) {
F_43 ( V_2 , V_212 ,
V_213 ) ;
F_44 ( V_2 , V_210 ) ;
} else {
F_43 ( V_2 , V_212 ,
V_214 ) ;
F_44 ( V_2 , V_210 ) ;
}
}
static bool F_45 ( struct V_1 * V_2 )
{
T_2 V_215 = F_46 ( V_2 ) ;
T_2 V_216 = V_2 -> V_217 . V_218 == V_219 ? 450 : 300 ;
if ( F_47 ( V_2 ) > 120 )
return true ;
if ( V_215 < V_216 )
return true ;
else
return false ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_41 * V_44 = F_10 ( V_43 ) ;
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_220 * V_221 ;
bool V_222 ;
T_2 V_223 , V_224 ;
int V_32 ;
if ( V_43 -> V_225 ) {
V_43 -> V_226 = V_2 -> V_38 . V_39 . V_227 [ V_2 -> V_38 . V_39 . V_228 ] . V_226 ;
V_43 -> V_229 = V_2 -> V_38 . V_39 . V_227 [ V_2 -> V_38 . V_39 . V_228 ] . V_229 ;
} else {
V_43 -> V_226 = 0 ;
V_43 -> V_229 = 0 ;
}
if ( ( V_2 -> V_38 . V_39 . V_230 > 1 ) ||
F_45 ( V_2 ) )
V_222 = true ;
else
V_222 = false ;
if ( ( V_43 -> V_231 & V_232 ) == V_233 )
V_37 -> V_234 = true ;
else
V_37 -> V_234 = false ;
if ( V_2 -> V_38 . V_39 . V_235 )
V_221 = & V_2 -> V_38 . V_39 . V_74 . V_236 ;
else
V_221 = & V_2 -> V_38 . V_39 . V_74 . V_237 ;
if ( V_2 -> V_38 . V_39 . V_235 == false ) {
for ( V_32 = 0 ; V_32 < V_44 -> V_238 ; V_32 ++ ) {
if ( V_44 -> V_239 [ V_32 ] . V_224 > V_221 -> V_224 )
V_44 -> V_239 [ V_32 ] . V_224 = V_221 -> V_224 ;
if ( V_44 -> V_239 [ V_32 ] . V_223 > V_221 -> V_223 )
V_44 -> V_239 [ V_32 ] . V_223 = V_221 -> V_223 ;
}
}
if ( V_222 ) {
V_224 = V_44 -> V_239 [ V_44 -> V_238 - 1 ] . V_224 ;
V_223 = V_44 -> V_239 [ 0 ] . V_223 ;
} else {
V_224 = V_44 -> V_239 [ 0 ] . V_224 ;
V_223 = V_44 -> V_239 [ 0 ] . V_223 ;
}
if ( V_2 -> V_38 . V_240 . V_241 > V_223 )
V_223 = V_2 -> V_38 . V_240 . V_241 ;
if ( V_2 -> V_38 . V_240 . V_242 > V_224 )
V_224 = V_2 -> V_38 . V_240 . V_242 ;
if ( V_43 -> V_225 ) {
if ( V_223 < V_2 -> V_38 . V_39 . V_227 [ V_2 -> V_38 . V_39 . V_228 ] . V_223 )
V_223 = V_2 -> V_38 . V_39 . V_227 [ V_2 -> V_38 . V_39 . V_228 ] . V_223 ;
if ( V_224 < V_2 -> V_38 . V_39 . V_227 [ V_2 -> V_38 . V_39 . V_228 ] . V_224 )
V_224 = V_2 -> V_38 . V_39 . V_227 [ V_2 -> V_38 . V_39 . V_228 ] . V_224 ;
}
V_44 -> V_239 [ 0 ] . V_223 = V_223 ;
V_44 -> V_239 [ 0 ] . V_224 = V_224 ;
if ( V_44 -> V_239 [ 1 ] . V_223 < V_44 -> V_239 [ 0 ] . V_223 )
V_44 -> V_239 [ 1 ] . V_223 = V_44 -> V_239 [ 0 ] . V_223 ;
if ( V_222 ) {
if ( V_44 -> V_239 [ 0 ] . V_224 < V_44 -> V_239 [ 1 ] . V_224 )
V_44 -> V_239 [ 0 ] . V_224 = V_44 -> V_239 [ 1 ] . V_224 ;
} else {
if ( V_44 -> V_239 [ 1 ] . V_224 < V_44 -> V_239 [ 0 ] . V_224 )
V_44 -> V_239 [ 1 ] . V_224 = V_44 -> V_239 [ 0 ] . V_224 ;
}
}
static int F_49 ( struct V_1 * V_2 ,
int V_243 , int V_244 )
{
int V_245 = 0 * 1000 ;
int V_246 = 255 * 1000 ;
T_2 V_247 ;
if ( V_245 < V_243 )
V_245 = V_243 ;
if ( V_246 > V_244 )
V_246 = V_244 ;
if ( V_246 < V_245 ) {
F_50 ( L_1 , V_245 , V_246 ) ;
return - V_21 ;
}
V_247 = F_32 ( V_248 ) ;
V_247 &= ~ ( V_249 | V_250 ) ;
V_247 |= ( ( V_246 / 1000 ) << V_251 ) |
( ( V_245 / 1000 ) ) << V_252 ;
F_33 ( V_248 , V_247 ) ;
#if 0
tmp = RREG32_SMC(ixCG_THERMAL_CTRL);
tmp &= DIG_THERM_DPM_MASK;
tmp |= DIG_THERM_DPM(high_temp / 1000);
WREG32_SMC(ixCG_THERMAL_CTRL, tmp);
#endif
V_2 -> V_38 . V_39 . V_253 . V_243 = V_245 ;
V_2 -> V_38 . V_39 . V_253 . V_244 = V_246 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
bool V_160 )
{
T_2 V_254 = F_32 ( V_248 ) ;
T_5 V_255 ;
if ( V_160 ) {
V_254 &= ~ ( V_256 |
V_257 ) ;
F_33 ( V_248 , V_254 ) ;
V_255 = F_36 ( V_2 , V_258 ) ;
if ( V_255 != V_189 ) {
F_52 ( L_2 ) ;
return - V_21 ;
}
} else {
V_254 |= V_256 |
V_257 ;
F_33 ( V_248 , V_254 ) ;
V_255 = F_36 ( V_2 , V_259 ) ;
if ( V_255 != V_189 ) {
F_52 ( L_3 ) ;
return - V_21 ;
}
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , T_2 V_260 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_247 ;
if ( V_37 -> V_261 ) {
V_247 = ( F_32 ( V_262 ) & V_263 )
>> V_264 ;
V_37 -> V_265 = V_247 ;
V_247 = ( F_32 ( V_262 ) & V_266 )
>> V_267 ;
V_37 -> V_268 = V_247 ;
V_37 -> V_261 = false ;
}
V_247 = F_32 ( V_262 ) & ~ V_266 ;
V_247 |= 0 << V_267 ;
F_33 ( V_262 , V_247 ) ;
V_247 = F_32 ( V_262 ) & ~ V_263 ;
V_247 |= V_260 << V_264 ;
F_33 ( V_262 , V_247 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_7 V_269 = { V_270 } ;
T_2 V_271 ;
T_2 V_272 , V_273 , V_274 , V_275 ;
T_3 V_276 , V_277 , V_278 ;
T_2 V_279 , V_247 ;
int V_103 ;
T_8 V_280 ;
if ( ! V_37 -> V_281 ) {
V_2 -> V_38 . V_39 . V_111 . V_282 = false ;
return 0 ;
}
V_271 = ( F_32 ( V_283 ) & V_284 )
>> V_285 ;
if ( V_271 == 0 ) {
V_2 -> V_38 . V_39 . V_111 . V_282 = false ;
return 0 ;
}
V_280 = ( T_8 ) V_2 -> V_38 . V_39 . V_111 . V_286 * V_271 ;
F_55 ( V_280 , 10000 ) ;
V_276 = ( T_3 ) V_280 ;
V_272 = V_2 -> V_38 . V_39 . V_111 . V_287 - V_2 -> V_38 . V_39 . V_111 . V_268 ;
V_273 = V_2 -> V_38 . V_39 . V_111 . V_288 - V_2 -> V_38 . V_39 . V_111 . V_287 ;
V_274 = V_2 -> V_38 . V_39 . V_111 . V_289 - V_2 -> V_38 . V_39 . V_111 . V_286 ;
V_275 = V_2 -> V_38 . V_39 . V_111 . V_290 - V_2 -> V_38 . V_39 . V_111 . V_289 ;
V_277 = ( T_3 ) ( ( 50 + ( ( 16 * V_271 * V_274 ) / V_272 ) ) / 100 ) ;
V_278 = ( T_3 ) ( ( 50 + ( ( 16 * V_271 * V_275 ) / V_273 ) ) / 100 ) ;
V_269 . V_291 = F_17 ( ( 50 + V_2 -> V_38 . V_39 . V_111 . V_268 ) / 100 ) ;
V_269 . V_292 = F_17 ( ( 50 + V_2 -> V_38 . V_39 . V_111 . V_287 ) / 100 ) ;
V_269 . V_293 = F_17 ( ( 50 + V_2 -> V_38 . V_39 . V_111 . V_294 ) / 100 ) ;
V_269 . V_295 = F_17 ( V_277 ) ;
V_269 . V_296 = F_17 ( V_278 ) ;
V_269 . V_297 = F_17 ( V_276 ) ;
V_269 . V_298 = F_17 ( V_2 -> V_38 . V_39 . V_111 . V_299 ) ;
V_269 . V_300 = F_17 ( 1 ) ;
V_269 . V_301 = F_17 ( 1 ) ;
V_269 . V_302 = F_17 ( 5 ) ;
V_279 = F_56 ( V_2 ) ;
V_269 . V_303 = F_25 ( ( V_2 -> V_38 . V_39 . V_111 . V_304 *
V_279 ) / 1600 ) ;
V_269 . V_305 = F_17 ( ( T_3 ) V_271 ) ;
V_247 = ( F_32 ( V_306 ) & V_307 )
>> V_308 ;
V_269 . V_309 = ( V_310 ) V_247 ;
V_103 = F_27 ( V_2 ,
V_37 -> V_281 ,
( T_1 * ) ( & V_269 ) ,
sizeof( V_269 ) ,
V_37 -> V_109 ) ;
if ( V_103 ) {
F_50 ( L_4 ) ;
V_2 -> V_38 . V_39 . V_111 . V_282 = false ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_103 ;
if ( V_37 -> V_311 ) {
V_103 = F_58 ( V_2 ,
V_312 ,
V_313 ) ;
if ( V_103 != V_189 )
return - V_21 ;
V_103 = F_58 ( V_2 ,
V_314 ,
V_2 -> V_38 . V_39 . V_111 . V_315 ) ;
if ( V_103 != V_189 )
return - V_21 ;
} else {
V_103 = F_58 ( V_2 ,
V_312 ,
V_316 ) ;
if ( V_103 != V_189 )
return - V_21 ;
}
V_37 -> V_317 = true ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
T_5 V_103 ;
struct V_36 * V_37 = F_9 ( V_2 ) ;
V_103 = F_36 ( V_2 , V_318 ) ;
if ( V_103 == V_189 ) {
V_37 -> V_317 = false ;
return 0 ;
} else {
return - V_21 ;
}
}
static int F_60 ( struct V_1 * V_2 ,
T_2 * V_319 )
{
T_2 V_320 , V_271 ;
T_8 V_280 ;
if ( V_2 -> V_38 . V_321 )
return - V_322 ;
V_271 = ( F_32 ( V_283 ) & V_284 )
>> V_285 ;
V_320 = ( F_32 ( V_323 ) & V_324 )
>> V_325 ;
if ( V_271 == 0 )
return - V_21 ;
V_280 = ( T_8 ) V_320 * 100 ;
F_55 ( V_280 , V_271 ) ;
* V_319 = ( T_2 ) V_280 ;
if ( * V_319 > 100 )
* V_319 = 100 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
T_2 V_319 )
{
T_2 V_247 ;
T_2 V_320 , V_271 ;
T_8 V_280 ;
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( V_2 -> V_38 . V_321 )
return - V_322 ;
if ( V_37 -> V_317 )
return - V_21 ;
if ( V_319 > 100 )
return - V_21 ;
V_271 = ( F_32 ( V_283 ) & V_284 )
>> V_285 ;
if ( V_271 == 0 )
return - V_21 ;
V_280 = ( T_8 ) V_319 * V_271 ;
F_55 ( V_280 , 100 ) ;
V_320 = ( T_2 ) V_280 ;
V_247 = F_32 ( V_326 ) & ~ V_327 ;
V_247 |= V_320 << V_328 ;
F_33 ( V_326 , V_247 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 , T_2 V_260 )
{
switch ( V_260 ) {
case V_329 :
if ( V_2 -> V_38 . V_39 . V_111 . V_282 )
F_59 ( V_2 ) ;
F_61 ( V_2 , 100 ) ;
break;
case V_330 :
if ( V_2 -> V_38 . V_39 . V_111 . V_282 )
F_59 ( V_2 ) ;
break;
case V_331 :
if ( V_2 -> V_38 . V_39 . V_111 . V_282 )
F_63 ( V_2 ) ;
break;
default:
break;
}
}
static T_2 F_64 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( V_37 -> V_317 )
return V_331 ;
else
return V_330 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_247 ;
if ( ! V_37 -> V_261 ) {
V_247 = F_32 ( V_262 ) & ~ V_263 ;
V_247 |= V_37 -> V_265 << V_264 ;
F_33 ( V_262 , V_247 ) ;
V_247 = F_32 ( V_262 ) & ~ V_266 ;
V_247 |= V_37 -> V_268 << V_267 ;
F_33 ( V_262 , V_247 ) ;
V_37 -> V_261 = true ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 . V_39 . V_111 . V_282 ) {
F_57 ( V_2 ) ;
F_53 ( V_2 , V_332 ) ;
}
}
static void F_66 ( struct V_1 * V_2 )
{
T_2 V_247 ;
if ( V_2 -> V_38 . V_333 ) {
V_247 = F_32 ( V_334 ) & ~ V_335 ;
V_247 |= ( V_2 -> V_38 . V_333 - 1 )
<< V_336 ;
F_33 ( V_334 , V_247 ) ;
}
V_247 = F_32 ( V_262 ) & ~ V_337 ;
V_247 |= 0x28 << V_338 ;
F_33 ( V_262 , V_247 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_103 ;
F_66 ( V_2 ) ;
V_103 = F_49 ( V_2 , V_339 , V_340 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_51 ( V_2 , true ) ;
if ( V_103 )
return V_103 ;
if ( V_2 -> V_38 . V_39 . V_111 . V_282 ) {
V_103 = F_54 ( V_2 ) ;
if ( V_103 )
return V_103 ;
F_63 ( V_2 ) ;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_38 . V_321 )
F_65 ( V_2 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
T_3 V_341 , T_2 * V_86 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
return F_19 ( V_2 ,
V_37 -> V_342 + V_341 ,
V_86 , V_37 -> V_109 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
T_3 V_341 , T_2 V_86 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
return F_71 ( V_2 ,
V_37 -> V_342 + V_341 ,
V_86 , V_37 -> V_109 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_4 * V_343 = & V_37 -> V_127 ;
if ( V_37 -> V_344 ) {
T_3 V_247 ;
V_247 = 45 ;
V_343 -> V_345 = F_17 ( V_247 ) ;
V_247 = 30 ;
V_343 -> V_346 = F_17 ( V_247 ) ;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 = 0 ;
T_2 V_347 = 0 ;
if ( V_37 -> V_348 ) {
V_347 = F_25 ( V_37 -> V_347 ) ;
V_103 = F_27 ( V_2 ,
V_37 -> V_349 +
F_20 ( T_4 , V_350 ) ,
( T_1 * ) & V_347 ,
sizeof( T_2 ) , V_37 -> V_109 ) ;
}
return V_103 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_3 V_351 , V_352 ;
T_3 V_65 , V_353 ;
int V_32 ;
V_37 -> V_354 . V_34 = 0 ;
V_37 -> V_355 . V_34 = 0 ;
if ( V_2 -> V_38 . V_39 . V_77 & V_78 ) {
for ( V_32 = 0 ; V_32 < V_356 ; V_32 ++ ) {
V_352 = V_357 + V_32 ;
if ( F_75 ( V_2 , V_352 , & V_65 ) != 0 )
continue;
if ( V_65 != 0 && V_65 != V_352 ) {
V_37 -> V_354 . V_358 [ V_37 -> V_354 . V_34 ] = V_65 ;
V_37 -> V_354 . V_351 [ V_37 -> V_354 . V_34 ] = V_352 ;
V_37 -> V_354 . V_34 ++ ;
}
}
} else if ( F_76 ( V_2 , & V_351 ) == 0 ) {
for ( V_32 = 0 ; V_32 < V_356 ; V_32 ++ ) {
V_352 = V_357 + V_32 ;
if ( F_77 ( V_2 , & V_65 , & V_353 ,
V_352 ,
V_351 ) == 0 ) {
if ( V_65 != 0 && V_65 != V_352 ) {
V_37 -> V_354 . V_358 [ V_37 -> V_354 . V_34 ] = V_65 ;
V_37 -> V_354 . V_351 [ V_37 -> V_354 . V_34 ] = V_352 ;
V_37 -> V_354 . V_34 ++ ;
}
if ( V_353 != 0 && V_353 != V_352 ) {
V_37 -> V_355 . V_358 [ V_37 -> V_355 . V_34 ] = V_353 ;
V_37 -> V_355 . V_351 [ V_37 -> V_355 . V_34 ] = V_352 ;
V_37 -> V_355 . V_34 ++ ;
}
}
}
}
}
static void F_78 ( struct V_1 * V_2 , T_2 V_359 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
bool V_360 ;
enum V_361 V_362 ;
T_2 V_247 ;
switch ( V_359 ) {
case 0 :
default:
V_360 = false ;
break;
case ( 1 << V_363 ) :
V_360 = true ;
V_362 = V_364 ;
break;
case ( 1 << V_365 ) :
V_360 = true ;
V_362 = V_366 ;
break;
case ( ( 1 << V_365 ) |
( 1 << V_363 ) ) :
V_360 = true ;
V_362 = V_367 ;
break;
}
if ( V_360 ) {
#if 0
tmp = RREG32_SMC(ixCG_THERMAL_CTRL);
tmp &= DPM_EVENT_SRC_MASK;
tmp |= DPM_EVENT_SRC(dpm_event_src);
WREG32_SMC(ixCG_THERMAL_CTRL, tmp);
#endif
V_247 = F_32 ( V_368 ) ;
if ( V_37 -> V_369 )
V_247 &= ~ V_370 ;
else
V_247 |= V_370 ;
F_33 ( V_368 , V_247 ) ;
} else {
V_247 = F_32 ( V_368 ) ;
V_247 |= V_370 ;
F_33 ( V_368 , V_247 ) ;
}
}
static void F_79 ( struct V_1 * V_2 ,
enum V_371 V_372 ,
bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( V_160 ) {
if ( ! ( V_37 -> V_373 & ( 1 << V_372 ) ) ) {
V_37 -> V_373 |= 1 << V_372 ;
F_78 ( V_2 , V_37 -> V_373 ) ;
}
} else {
if ( V_37 -> V_373 & ( 1 << V_372 ) ) {
V_37 -> V_373 &= ~ ( 1 << V_372 ) ;
F_78 ( V_2 , V_37 -> V_373 ) ;
}
}
}
static void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 . V_39 . V_77 & V_374 )
F_36 ( V_2 , V_375 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_186 ;
if ( ! V_37 -> V_376 )
return 0 ;
if ( ( ! V_37 -> V_377 ) &&
( V_37 -> V_376 & ( V_378 | V_379 ) ) ) {
V_186 = F_36 ( V_2 , V_380 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
if ( ( ! V_37 -> V_381 ) &&
( V_37 -> V_376 & V_382 ) ) {
V_186 = F_36 ( V_2 , V_383 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
V_37 -> V_376 = 0 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_186 ;
if ( V_160 ) {
if ( ! V_37 -> V_377 ) {
V_186 = F_36 ( V_2 , V_384 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
if ( ! V_37 -> V_381 ) {
V_186 = F_36 ( V_2 , V_385 ) ;
if ( V_186 != V_189 )
return - V_21 ;
F_5 ( V_386 , V_387 ,
~ V_387 ) ;
F_33 ( V_388 , 0x05 ) ;
F_33 ( V_389 , 0x05 ) ;
F_33 ( V_390 , 0x100005 ) ;
F_83 ( 10 ) ;
F_33 ( V_388 , 0x400005 ) ;
F_33 ( V_389 , 0x400005 ) ;
F_33 ( V_390 , 0x500005 ) ;
}
} else {
if ( ! V_37 -> V_377 ) {
V_186 = F_36 ( V_2 , V_391 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
if ( ! V_37 -> V_381 ) {
V_186 = F_36 ( V_2 , V_392 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
}
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_186 ;
int V_103 ;
T_2 V_247 ;
V_247 = F_32 ( V_368 ) ;
V_247 |= V_393 ;
F_33 ( V_368 , V_247 ) ;
V_247 = F_32 ( V_394 ) ;
V_247 |= V_395 ;
F_33 ( V_394 , V_247 ) ;
F_70 ( V_2 , F_20 ( V_396 , V_397 ) , 0x1000 ) ;
F_5 ( V_398 , 0 , ~ V_399 ) ;
V_186 = F_36 ( V_2 , V_400 ) ;
if ( V_186 != V_189 )
return - V_21 ;
V_103 = F_82 ( V_2 , true ) ;
if ( V_103 )
return V_103 ;
if ( ! V_37 -> V_401 ) {
V_186 = F_36 ( V_2 , V_402 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_186 ;
if ( ! V_37 -> V_376 )
return 0 ;
if ( ( ! V_37 -> V_377 ) &&
( V_37 -> V_376 & ( V_378 | V_379 ) ) ) {
V_186 = F_36 ( V_2 , V_403 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
if ( ( ! V_37 -> V_381 ) &&
( V_37 -> V_376 & V_382 ) ) {
V_186 = F_36 ( V_2 , V_404 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_186 ;
int V_103 ;
T_2 V_247 ;
V_247 = F_32 ( V_368 ) ;
V_247 &= ~ V_393 ;
F_33 ( V_368 , V_247 ) ;
V_247 = F_32 ( V_394 ) ;
V_247 &= ~ V_395 ;
F_33 ( V_394 , V_247 ) ;
if ( ! V_37 -> V_401 ) {
V_186 = F_36 ( V_2 , V_405 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
V_103 = F_82 ( V_2 , false ) ;
if ( V_103 )
return V_103 ;
V_186 = F_36 ( V_2 , V_406 ) ;
if ( V_186 != V_189 )
return - V_21 ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 , bool V_160 )
{
T_2 V_247 = F_32 ( V_394 ) ;
if ( V_160 )
V_247 &= ~ V_407 ;
else
V_247 |= V_407 ;
F_33 ( V_394 , V_247 ) ;
}
static T_5 F_58 ( struct V_1 * V_2 ,
T_9 V_408 , T_2 V_409 )
{
F_4 ( V_410 , V_409 ) ;
return F_36 ( V_2 , V_408 ) ;
}
static T_5 F_88 ( struct V_1 * V_2 ,
T_9 V_408 , T_2 * V_409 )
{
T_5 V_186 ;
V_186 = F_36 ( V_2 , V_408 ) ;
if ( ( V_186 == V_189 ) && V_409 )
* V_409 = F_2 ( V_410 ) ;
return V_186 ;
}
static int F_89 ( struct V_1 * V_2 , T_2 V_411 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( ! V_37 -> V_377 ) {
T_5 V_186 =
F_58 ( V_2 , V_412 , 1 << V_411 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , T_2 V_411 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( ! V_37 -> V_381 ) {
T_5 V_186 =
F_58 ( V_2 , V_413 , 1 << V_411 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_2 V_411 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( ! V_37 -> V_401 ) {
T_5 V_186 =
F_58 ( V_2 , V_414 , V_411 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_411 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( V_37 -> V_187 & V_196 ) {
T_5 V_186 =
F_58 ( V_2 , V_415 , V_411 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_2 V_207 )
{
T_5 V_186 =
F_58 ( V_2 , V_416 , V_207 ) ;
if ( V_186 != V_189 )
return - V_21 ;
return 0 ;
}
static T_2 F_92 ( struct V_1 * V_2 )
{
T_2 V_417 ;
T_5 V_186 =
F_88 ( V_2 ,
V_418 ,
& V_417 ) ;
if ( V_186 != V_189 )
V_417 = 0 ;
return V_417 ;
}
static T_2 F_93 ( struct V_1 * V_2 )
{
T_2 V_419 ;
T_5 V_186 =
F_88 ( V_2 ,
V_420 ,
& V_419 ) ;
if ( V_186 != V_189 )
V_419 = 0 ;
return V_419 ;
}
static void F_94 ( struct V_1 * V_2 )
{
int V_32 ;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_421 ; V_32 ++ ) {
if ( F_32 ( V_422 ) & V_423 )
break;
}
}
static void F_98 ( struct V_1 * V_2 )
{
F_99 ( V_2 ) ;
F_100 ( V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_247 ;
int V_103 ;
V_103 = F_19 ( V_2 ,
V_104 +
F_20 ( V_105 , V_424 ) ,
& V_247 , V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
V_37 -> V_349 = V_247 ;
V_103 = F_19 ( V_2 ,
V_104 +
F_20 ( V_105 , V_425 ) ,
& V_247 , V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
V_37 -> V_342 = V_247 ;
V_103 = F_19 ( V_2 ,
V_104 +
F_20 ( V_105 , V_426 ) ,
& V_247 , V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
V_37 -> V_427 = V_247 ;
V_103 = F_19 ( V_2 ,
V_104 +
F_20 ( V_105 , V_428 ) ,
& V_247 , V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
V_37 -> V_281 = V_247 ;
V_103 = F_19 ( V_2 ,
V_104 +
F_20 ( V_105 , V_429 ) ,
& V_247 , V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
V_37 -> V_430 = V_247 ;
return 0 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
V_37 -> V_431 . V_432 =
F_32 ( V_433 ) ;
V_37 -> V_431 . V_434 =
F_32 ( V_435 ) ;
V_37 -> V_431 . V_436 =
F_32 ( V_437 ) ;
V_37 -> V_431 . V_438 =
F_32 ( V_439 ) ;
V_37 -> V_431 . V_440 =
F_32 ( V_441 ) ;
V_37 -> V_431 . V_442 =
F_32 ( V_443 ) ;
V_37 -> V_431 . V_444 = F_2 ( V_445 ) ;
V_37 -> V_431 . V_446 = F_2 ( V_447 ) ;
V_37 -> V_431 . V_448 = F_2 ( V_449 ) ;
V_37 -> V_431 . V_450 = F_2 ( V_451 ) ;
V_37 -> V_431 . V_452 = F_2 ( V_453 ) ;
V_37 -> V_431 . V_454 = F_2 ( V_455 ) ;
V_37 -> V_431 . V_456 = F_2 ( V_457 ) ;
V_37 -> V_431 . V_458 = F_2 ( V_459 ) ;
V_37 -> V_431 . V_460 = F_2 ( V_461 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
V_37 -> V_347 = 0 ;
}
static void F_104 ( struct V_1 * V_2 ,
bool V_160 )
{
T_2 V_247 = F_32 ( V_368 ) ;
if ( V_160 )
V_247 &= ~ V_370 ;
else
V_247 |= V_370 ;
F_33 ( V_368 , V_247 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_2 V_247 = F_32 ( V_368 ) ;
V_247 |= V_462 ;
F_33 ( V_368 , V_247 ) ;
}
static int F_106 ( struct V_1 * V_2 ,
bool V_463 )
{
T_9 V_408 = V_463 ? V_464 : V_465 ;
return ( F_36 ( V_2 , V_408 ) == V_189 ) ? 0 : - V_21 ;
}
static int F_107 ( struct V_1 * V_2 ,
bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( V_160 ) {
if ( V_37 -> V_466 ) {
if ( F_36 ( V_2 , V_467 ) != V_189 )
return - V_21 ;
} else {
if ( F_36 ( V_2 , V_468 ) != V_189 )
return - V_21 ;
}
} else {
if ( V_37 -> V_466 ) {
if ( F_36 ( V_2 , V_468 ) != V_189 )
return - V_21 ;
}
}
return 0 ;
}
static void F_108 ( struct V_1 * V_2 )
{
T_2 V_247 = F_32 ( V_469 ) ;
T_2 V_470 ;
T_2 V_471 ;
T_2 V_472 = V_2 -> clock . V_473 . V_474 ;
T_2 V_475 = F_47 ( V_2 ) ;
T_2 V_215 = F_46 ( V_2 ) ;
V_247 &= ~ V_476 ;
if ( V_2 -> V_38 . V_39 . V_230 > 0 )
V_247 |= ( V_477 << V_478 ) ;
else
V_247 |= ( V_479 << V_478 ) ;
F_33 ( V_469 , V_247 ) ;
if ( V_475 == 0 )
V_475 = 60 ;
if ( V_215 == 0xffffffff )
V_215 = 500 ;
V_471 = 1000000 / V_475 ;
V_470 =
V_471 - 200 - V_215 ;
V_247 = V_470 * ( V_472 / 100 ) ;
F_33 ( V_480 , V_247 ) ;
F_70 ( V_2 , F_20 ( V_396 , V_481 ) , 0x64 ) ;
F_70 ( V_2 , F_20 ( V_396 , V_482 ) , ( V_471 - V_470 ) ) ;
F_106 ( V_2 , ( V_2 -> V_38 . V_39 . V_230 == 1 ) ) ;
}
static void F_109 ( struct V_1 * V_2 , bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_247 ;
if ( V_160 ) {
if ( V_37 -> V_483 ) {
V_247 = F_32 ( V_368 ) ;
V_247 |= V_484 ;
F_33 ( V_368 , V_247 ) ;
}
} else {
V_247 = F_32 ( V_441 ) ;
V_247 &= ~ V_485 ;
F_33 ( V_441 , V_247 ) ;
V_247 = F_32 ( V_368 ) ;
V_247 &= ~ V_484 ;
F_33 ( V_368 , V_247 ) ;
}
}
static void F_110 ( struct V_1 * V_2 )
{
F_33 ( V_486 ,
( ( V_487 << V_488 ) |
( V_489 << V_490 ) ) ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
T_2 V_247 = F_32 ( V_469 ) ;
V_247 &= ~ ( V_476 |
V_491 ) ;
V_247 |= ( ( V_479 << V_478 ) |
( V_492 << V_493 ) ) ;
F_33 ( V_469 , V_247 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
T_2 V_247 ;
V_247 = F_32 ( V_394 ) ;
V_247 &= ~ ( V_494 | V_495 ) ;
F_33 ( V_394 , V_247 ) ;
F_33 ( V_496 , V_497 ) ;
F_33 ( V_498 , V_499 ) ;
F_33 ( V_500 , V_501 ) ;
F_33 ( V_502 , V_503 ) ;
F_33 ( V_504 , V_505 ) ;
F_33 ( V_506 , V_507 ) ;
F_33 ( V_508 , V_509 ) ;
F_33 ( V_510 , V_511 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
T_2 V_247 ;
V_247 = F_32 ( V_394 ) ;
V_247 |= ( V_494 | V_495 ) ;
F_33 ( V_394 , V_247 ) ;
F_33 ( V_496 , 0 ) ;
F_33 ( V_498 , 0 ) ;
F_33 ( V_500 , 0 ) ;
F_33 ( V_502 , 0 ) ;
F_33 ( V_504 , 0 ) ;
F_33 ( V_506 , 0 ) ;
F_33 ( V_508 , 0 ) ;
F_33 ( V_510 , 0 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_32 , V_103 ;
if ( F_115 ( V_2 ) ) {
F_116 ( L_5 ) ;
return 0 ;
}
for ( V_32 = 0 ; V_32 < V_2 -> V_421 ; V_32 ++ ) {
if ( F_32 ( V_512 ) & V_513 )
break;
}
F_33 ( V_514 , 1 ) ;
F_100 ( V_2 ) ;
F_99 ( V_2 ) ;
V_103 = F_117 ( V_2 , V_515 ) ;
return V_103 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_516 * V_517 ,
struct V_30 * V_31 )
{
T_2 V_32 ;
if ( V_517 == NULL )
return - V_21 ;
V_31 -> V_518 = 0 ;
V_31 -> V_519 = 0 ;
V_31 -> V_34 = V_517 -> V_34 ;
for ( V_32 = 0 ; V_32 < V_31 -> V_34 ; V_32 ++ ) {
V_31 -> V_35 [ V_32 ] . V_86 = V_517 -> V_35 [ V_32 ] . V_520 ;
V_31 -> V_35 [ V_32 ] . V_521 = 0 ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 ;
if ( V_37 -> V_522 == V_523 ) {
V_103 = F_120 ( V_2 , V_524 ,
V_525 ,
& V_37 -> V_85 ) ;
if ( V_103 )
return V_103 ;
} else if ( V_37 -> V_522 == V_526 ) {
V_103 = F_118 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_527 ,
& V_37 -> V_85 ) ;
if ( V_103 )
return V_103 ;
}
if ( V_37 -> V_85 . V_34 > V_528 )
F_8 ( V_2 , V_528 ,
& V_37 -> V_85 ) ;
if ( V_37 -> V_529 == V_523 ) {
V_103 = F_120 ( V_2 , V_530 ,
V_525 ,
& V_37 -> V_531 ) ;
if ( V_103 )
return V_103 ;
} else if ( V_37 -> V_529 == V_526 ) {
V_103 = F_118 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_532 ,
& V_37 -> V_531 ) ;
if ( V_103 )
return V_103 ;
}
if ( V_37 -> V_531 . V_34 > V_533 )
F_8 ( V_2 , V_533 ,
& V_37 -> V_531 ) ;
if ( V_37 -> V_534 == V_523 ) {
V_103 = F_120 ( V_2 , V_535 ,
V_525 ,
& V_37 -> V_536 ) ;
if ( V_103 )
return V_103 ;
} else if ( V_37 -> V_534 == V_526 ) {
V_103 = F_118 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_537 ,
& V_37 -> V_536 ) ;
if ( V_103 )
return V_103 ;
}
if ( V_37 -> V_536 . V_34 > V_538 )
F_8 ( V_2 , V_538 ,
& V_37 -> V_536 ) ;
return 0 ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_539 * V_31 ,
T_10 * V_540 )
{
int V_103 ;
V_103 = F_122 ( V_2 , V_31 ,
& V_540 -> V_541 ,
& V_540 -> V_542 ) ;
if ( V_103 ) {
V_540 -> V_541 = V_31 -> V_86 * V_66 ;
V_540 -> V_542 = V_31 -> V_86 * V_66 ;
}
V_540 -> V_543 = F_17 ( V_31 -> V_86 * V_66 ) ;
V_540 -> V_541 =
F_17 ( V_540 -> V_541 ) ;
V_540 -> V_542 =
F_17 ( V_540 -> V_542 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
unsigned int V_34 ;
V_343 -> V_544 = V_37 -> V_85 . V_34 ;
for ( V_34 = 0 ; V_34 < V_343 -> V_544 ; V_34 ++ ) {
F_121 ( V_2 ,
& V_37 -> V_85 . V_35 [ V_34 ] ,
& V_343 -> V_545 [ V_34 ] ) ;
if ( V_37 -> V_522 == V_523 )
V_343 -> V_545 [ V_34 ] . V_546 |=
V_37 -> V_85 . V_35 [ V_34 ] . V_521 ;
else
V_343 -> V_545 [ V_34 ] . V_546 = 0 ;
}
V_343 -> V_544 = F_25 ( V_343 -> V_544 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
unsigned int V_34 ;
struct V_36 * V_37 = F_9 ( V_2 ) ;
V_343 -> V_547 = V_37 -> V_531 . V_34 ;
for ( V_34 = 0 ; V_34 < V_343 -> V_547 ; V_34 ++ ) {
F_121 ( V_2 ,
& V_37 -> V_531 . V_35 [ V_34 ] ,
& V_343 -> V_548 [ V_34 ] ) ;
if ( V_37 -> V_529 == V_523 )
V_343 -> V_548 [ V_34 ] . V_546 |=
V_37 -> V_531 . V_35 [ V_34 ] . V_521 ;
else
V_343 -> V_548 [ V_34 ] . V_546 = 0 ;
}
V_343 -> V_547 = F_25 ( V_343 -> V_547 ) ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
unsigned int V_34 ;
V_343 -> V_549 = V_37 -> V_536 . V_34 ;
for ( V_34 = 0 ; V_34 < V_343 -> V_549 ; V_34 ++ ) {
F_121 ( V_2 ,
& V_37 -> V_536 . V_35 [ V_34 ] ,
& V_343 -> V_550 [ V_34 ] ) ;
if ( V_37 -> V_534 == V_523 )
V_343 -> V_550 [ V_34 ] . V_546 |=
V_37 -> V_536 . V_35 [ V_34 ] . V_521 ;
else
V_343 -> V_550 [ V_34 ] . V_546 = 0 ;
}
V_343 -> V_549 = F_25 ( V_343 -> V_549 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
int V_103 ;
V_103 = F_123 ( V_2 , V_343 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_124 ( V_2 , V_343 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_125 ( V_2 , V_343 ) ;
if ( V_103 )
return V_103 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 , T_2 V_224 ,
T_10 * V_551 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_32 = 0 ;
if ( V_37 -> V_534 != V_552 ) {
for ( V_32 = 0 ; V_32 < V_2 -> V_38 . V_39 . V_74 . V_537 . V_34 ; V_32 ++ ) {
if ( V_224 <= V_2 -> V_38 . V_39 . V_74 . V_537 . V_35 [ V_32 ] . V_553 ) {
V_551 -> V_543 = V_37 -> V_536 . V_35 [ V_32 ] . V_86 ;
break;
}
}
if ( V_32 >= V_2 -> V_38 . V_39 . V_74 . V_537 . V_34 )
return - V_21 ;
}
return - V_21 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_539 * V_31 ,
T_3 * V_554 , T_3 * V_555 )
{
T_3 V_556 , V_557 ;
bool V_558 = false ;
* V_554 = V_31 -> V_86 * V_66 ;
* V_555 = V_31 -> V_86 * V_66 ;
if ( V_2 -> V_38 . V_39 . V_74 . V_76 . V_35 == NULL )
return - V_21 ;
if ( V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 ) {
for ( V_556 = 0 ; ( T_2 ) V_556 < V_2 -> V_38 . V_39 . V_74 . V_76 . V_34 ; V_556 ++ ) {
if ( V_31 -> V_86 ==
V_2 -> V_38 . V_39 . V_74 . V_76 . V_35 [ V_556 ] . V_520 ) {
V_558 = true ;
if ( ( T_2 ) V_556 < V_2 -> V_38 . V_39 . V_74 . V_75 . V_34 )
V_557 = V_556 ;
else
V_557 = V_2 -> V_38 . V_39 . V_74 . V_75 . V_34 - 1 ;
* V_555 =
V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_557 ] . V_65 * V_66 ;
* V_554 =
V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_557 ] . V_82 * V_66 ;
break;
}
}
if ( ! V_558 ) {
for ( V_556 = 0 ; ( T_2 ) V_556 < V_2 -> V_38 . V_39 . V_74 . V_76 . V_34 ; V_556 ++ ) {
if ( V_31 -> V_86 <=
V_2 -> V_38 . V_39 . V_74 . V_76 . V_35 [ V_556 ] . V_520 ) {
V_558 = true ;
if ( ( T_2 ) V_556 < V_2 -> V_38 . V_39 . V_74 . V_75 . V_34 )
V_557 = V_556 ;
else
V_557 = V_2 -> V_38 . V_39 . V_74 . V_75 . V_34 - 1 ;
* V_555 =
V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_557 ] . V_65 * V_66 ;
* V_554 =
V_2 -> V_38 . V_39 . V_74 . V_75 . V_35 [ V_557 ] . V_82 * V_66 ;
break;
}
}
}
}
return 0 ;
}
static void F_128 ( struct V_1 * V_2 ,
const struct V_559 * V_560 ,
T_2 V_223 ,
T_2 * V_561 )
{
unsigned int V_32 ;
* V_561 = 1 ;
for ( V_32 = 0 ; V_32 < V_560 -> V_34 ; V_32 ++ ) {
if ( V_223 < V_560 -> V_35 [ V_32 ] . V_223 ) {
* V_561 = V_32 ;
break;
}
}
}
static void F_129 ( struct V_1 * V_2 ,
const struct V_559 * V_560 ,
T_2 V_224 ,
T_2 * V_561 )
{
unsigned int V_32 ;
* V_561 = 1 ;
for ( V_32 = 0 ; V_32 < V_560 -> V_34 ; V_32 ++ ) {
if ( V_224 < V_560 -> V_35 [ V_32 ] . V_224 ) {
* V_561 = V_32 ;
break;
}
}
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_247 ;
int V_103 ;
V_103 = F_19 ( V_2 , V_37 -> V_430 ,
& V_247 , V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
V_247 &= 0x00FFFFFF ;
V_247 |= V_16 << 24 ;
return F_71 ( V_2 , V_37 -> V_430 ,
V_247 , V_37 -> V_109 ) ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_516 * V_562 ,
T_2 clock , T_2 * V_551 )
{
T_2 V_32 = 0 ;
if ( V_562 -> V_34 == 0 )
return - V_21 ;
for ( V_32 = 0 ; V_32 < V_562 -> V_34 ; V_32 ++ ) {
if ( V_562 -> V_35 [ V_32 ] . V_553 >= clock ) {
* V_551 = V_562 -> V_35 [ V_32 ] . V_520 ;
return 0 ;
}
}
* V_551 = V_562 -> V_35 [ V_32 - 1 ] . V_520 ;
return 0 ;
}
static T_1 F_132 ( T_2 V_223 , T_2 V_563 )
{
T_2 V_32 ;
T_2 V_247 ;
T_2 V_115 = V_116 ( V_563 , ( T_2 ) V_564 ) ;
if ( V_223 < V_115 )
return 0 ;
for ( V_32 = V_565 ; ; V_32 -- ) {
V_247 = V_223 >> V_32 ;
if ( V_247 >= V_115 || V_32 == 0 )
break;
}
return ( T_1 ) V_32 ;
}
static int F_133 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_10 , V_16 ) ;
}
static int F_134 ( struct V_1 * V_2 )
{
return ( F_36 ( V_2 , V_566 ) == V_189 ) ?
0 : - V_21 ;
}
static int F_135 ( struct V_1 * V_2 )
{
T_2 V_247 ;
V_247 = ( F_32 ( V_567 ) & 0x0000ff00 ) >> 8 ;
if ( V_247 == V_10 )
return 0 ;
return F_3 ( V_2 , V_247 , V_10 ) ;
}
static void F_136 ( struct V_1 * V_2 ,
const T_2 V_568 ,
const T_2 V_26 ,
T_2 * V_569 )
{
bool V_570 ;
T_2 V_247 , V_571 ;
V_247 = F_2 ( V_572 ) ;
V_570 = ( ( V_247 & 0x0000f00 ) == 0x300 ) ? true : false ;
if ( V_570 &&
( ( V_2 -> V_46 -> V_47 == 0x67B0 ) ||
( V_2 -> V_46 -> V_47 == 0x67B1 ) ) ) {
if ( ( V_26 > 100000 ) && ( V_26 <= 125000 ) ) {
V_571 = ( ( ( 0x31 * V_568 ) / 125000 ) - 1 ) & 0xff ;
* V_569 &= ~ 0x00ff0000 ;
* V_569 |= V_571 << 16 ;
} else if ( ( V_26 > 125000 ) && ( V_26 <= 137500 ) ) {
V_571 = ( ( ( 0x36 * V_568 ) / 137500 ) - 1 ) & 0xff ;
* V_569 &= ~ 0x00ff0000 ;
* V_569 |= V_571 << 16 ;
}
}
}
static int F_137 ( struct V_1 * V_2 ,
T_2 V_223 ,
T_2 V_224 ,
T_11 * V_573 )
{
T_2 V_574 ;
T_2 V_575 ;
T_2 V_8 ;
F_138 ( V_2 , V_223 , V_224 ) ;
V_574 = F_2 ( V_11 ) ;
V_575 = F_2 ( V_12 ) ;
V_8 = F_2 ( V_13 ) & V_14 ;
F_136 ( V_2 , V_223 , V_224 , & V_575 ) ;
V_573 -> V_576 = F_25 ( V_574 ) ;
V_573 -> V_577 = F_25 ( V_575 ) ;
V_573 -> V_578 = ( T_1 ) V_8 ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_12 V_573 ;
T_2 V_32 , V_131 ;
int V_103 = 0 ;
memset ( & V_573 , 0 , sizeof( T_12 ) ) ;
for ( V_32 = 0 ; V_32 < V_37 -> V_126 . V_579 . V_34 ; V_32 ++ ) {
for ( V_131 = 0 ; V_131 < V_37 -> V_126 . V_580 . V_34 ; V_131 ++ ) {
V_103 = F_137 ( V_2 ,
V_37 -> V_126 . V_579 . V_581 [ V_32 ] . V_86 ,
V_37 -> V_126 . V_580 . V_581 [ V_131 ] . V_86 ,
& V_573 . V_35 [ V_32 ] [ V_131 ] ) ;
if ( V_103 )
break;
}
}
if ( V_103 == 0 )
V_103 = F_27 ( V_2 ,
V_37 -> V_430 ,
( T_1 * ) & V_573 ,
sizeof( T_12 ) ,
V_37 -> V_109 ) ;
return V_103 ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( V_37 -> V_376 == 0 )
return 0 ;
return F_139 ( V_2 ) ;
}
static void F_141 ( struct V_1 * V_2 ,
struct V_42 * V_582 )
{
struct V_41 * V_583 = F_10 ( V_582 ) ;
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_584 = 0 ;
for ( V_584 = 0 ; V_584 < V_2 -> V_38 . V_39 . V_74 . V_76 . V_34 ; V_584 ++ ) {
if ( V_2 -> V_38 . V_39 . V_74 . V_76 . V_35 [ V_584 ] . V_553 >=
V_583 -> V_239 [ 0 ] . V_223 ) {
V_37 -> V_127 . V_585 = V_584 ;
break;
}
}
for ( V_584 = 0 ; V_584 < V_2 -> V_38 . V_39 . V_74 . V_527 . V_34 ; V_584 ++ ) {
if ( V_2 -> V_38 . V_39 . V_74 . V_527 . V_35 [ V_584 ] . V_553 >=
V_583 -> V_239 [ 0 ] . V_224 ) {
V_37 -> V_127 . V_586 = V_584 ;
break;
}
}
}
static T_2 F_142 ( struct V_587 * V_126 )
{
T_2 V_32 ;
T_2 V_588 = 0 ;
for ( V_32 = V_126 -> V_34 ; V_32 > 0 ; V_32 -- ) {
V_588 = V_588 << 1 ;
if ( V_126 -> V_581 [ V_32 - 1 ] . V_589 )
V_588 |= 0x1 ;
else
V_588 &= 0xFFFFFFFE ;
}
return V_588 ;
}
static void F_143 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_590 * V_126 = & V_37 -> V_126 ;
T_2 V_32 ;
for ( V_32 = 0 ; V_32 < V_126 -> V_591 . V_34 ; V_32 ++ ) {
V_343 -> V_592 [ V_32 ] . V_593 =
( T_1 ) V_126 -> V_591 . V_581 [ V_32 ] . V_86 ;
V_343 -> V_592 [ V_32 ] . V_594 =
F_144 ( V_126 -> V_591 . V_581 [ V_32 ] . V_595 ) ;
V_343 -> V_592 [ V_32 ] . V_596 = 1 ;
V_343 -> V_592 [ V_32 ] . V_597 = F_25 ( 5 ) ;
V_343 -> V_592 [ V_32 ] . V_598 = F_25 ( 30 ) ;
}
V_37 -> V_127 . V_599 = ( T_1 ) V_126 -> V_591 . V_34 ;
V_37 -> V_600 . V_601 =
F_142 ( & V_126 -> V_591 ) ;
}
static int F_145 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
T_2 V_34 ;
struct V_602 V_603 ;
int V_103 = - V_21 ;
V_343 -> V_604 =
V_2 -> V_38 . V_39 . V_74 . V_605 . V_34 ;
for ( V_34 = 0 ; V_34 < V_343 -> V_604 ; V_34 ++ ) {
V_343 -> V_606 [ V_34 ] . V_607 =
V_2 -> V_38 . V_39 . V_74 . V_605 . V_35 [ V_34 ] . V_608 ;
V_343 -> V_606 [ V_34 ] . V_609 =
V_2 -> V_38 . V_39 . V_74 . V_605 . V_35 [ V_34 ] . V_610 ;
V_343 -> V_606 [ V_34 ] . V_611 =
V_2 -> V_38 . V_39 . V_74 . V_605 . V_35 [ V_34 ] . V_520 * V_66 ;
V_343 -> V_606 [ V_34 ] . V_612 = 1 ;
V_103 = F_146 ( V_2 ,
V_613 ,
V_343 -> V_606 [ V_34 ] . V_607 , false , & V_603 ) ;
if ( V_103 )
return V_103 ;
V_343 -> V_606 [ V_34 ] . V_614 = ( T_1 ) V_603 . V_615 ;
V_103 = F_146 ( V_2 ,
V_613 ,
V_343 -> V_606 [ V_34 ] . V_609 , false , & V_603 ) ;
if ( V_103 )
return V_103 ;
V_343 -> V_606 [ V_34 ] . V_616 = ( T_1 ) V_603 . V_615 ;
V_343 -> V_606 [ V_34 ] . V_607 = F_25 ( V_343 -> V_606 [ V_34 ] . V_607 ) ;
V_343 -> V_606 [ V_34 ] . V_609 = F_25 ( V_343 -> V_606 [ V_34 ] . V_609 ) ;
V_343 -> V_606 [ V_34 ] . V_611 = F_17 ( V_343 -> V_606 [ V_34 ] . V_611 ) ;
}
return V_103 ;
}
static int F_147 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
T_2 V_34 ;
struct V_602 V_603 ;
int V_103 = - V_21 ;
V_343 -> V_617 =
V_2 -> V_38 . V_39 . V_74 . V_618 . V_34 ;
for ( V_34 = 0 ; V_34 < V_343 -> V_617 ; V_34 ++ ) {
V_343 -> V_619 [ V_34 ] . V_620 =
V_2 -> V_38 . V_39 . V_74 . V_618 . V_35 [ V_34 ] . V_226 ;
V_343 -> V_619 [ V_34 ] . V_621 =
( T_3 ) V_2 -> V_38 . V_39 . V_74 . V_618 . V_35 [ V_34 ] . V_520 * V_66 ;
V_343 -> V_619 [ V_34 ] . V_622 = 1 ;
V_103 = F_146 ( V_2 ,
V_613 ,
V_343 -> V_619 [ V_34 ] . V_620 , false , & V_603 ) ;
if ( V_103 )
return V_103 ;
V_343 -> V_619 [ V_34 ] . V_623 = ( T_1 ) V_603 . V_615 ;
V_343 -> V_619 [ V_34 ] . V_620 = F_25 ( V_343 -> V_619 [ V_34 ] . V_620 ) ;
V_343 -> V_619 [ V_34 ] . V_621 = F_17 ( V_343 -> V_619 [ V_34 ] . V_621 ) ;
}
return V_103 ;
}
static int F_148 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
T_2 V_34 ;
struct V_602 V_603 ;
int V_103 = - V_21 ;
V_343 -> V_624 = ( T_1 )
( V_2 -> V_38 . V_39 . V_74 . V_625 . V_34 ) ;
for ( V_34 = 0 ; V_34 < V_343 -> V_624 ; V_34 ++ ) {
V_343 -> V_626 [ V_34 ] . V_620 =
V_2 -> V_38 . V_39 . V_74 . V_625 . V_35 [ V_34 ] . V_553 ;
V_343 -> V_626 [ V_34 ] . V_621 =
V_2 -> V_38 . V_39 . V_74 . V_625 . V_35 [ V_34 ] . V_520 ;
V_343 -> V_626 [ V_34 ] . V_622 = 1 ;
V_103 = F_146 ( V_2 ,
V_613 ,
V_343 -> V_626 [ V_34 ] . V_620 , false , & V_603 ) ;
if ( V_103 )
return V_103 ;
V_343 -> V_626 [ V_34 ] . V_623 = ( T_1 ) V_603 . V_615 ;
V_343 -> V_626 [ V_34 ] . V_620 = F_25 ( V_343 -> V_626 [ V_34 ] . V_620 ) ;
V_343 -> V_626 [ V_34 ] . V_621 = F_17 ( V_343 -> V_626 [ V_34 ] . V_621 ) ;
}
return V_103 ;
}
static int F_149 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
T_2 V_34 ;
struct V_602 V_603 ;
int V_103 = - V_21 ;
V_343 -> V_627 =
V_2 -> V_38 . V_39 . V_74 . V_628 . V_34 ;
for ( V_34 = 0 ; V_34 < V_343 -> V_627 ; V_34 ++ ) {
V_343 -> V_629 [ V_34 ] . V_620 =
V_2 -> V_38 . V_39 . V_74 . V_628 . V_35 [ V_34 ] . V_553 ;
V_343 -> V_629 [ V_34 ] . V_621 =
V_2 -> V_38 . V_39 . V_74 . V_628 . V_35 [ V_34 ] . V_520 * V_66 ;
V_343 -> V_629 [ V_34 ] . V_622 = 1 ;
V_103 = F_146 ( V_2 ,
V_613 ,
V_343 -> V_629 [ V_34 ] . V_620 , false , & V_603 ) ;
if ( V_103 )
return V_103 ;
V_343 -> V_629 [ V_34 ] . V_623 = ( T_1 ) V_603 . V_615 ;
V_343 -> V_629 [ V_34 ] . V_620 = F_25 ( V_343 -> V_629 [ V_34 ] . V_620 ) ;
V_343 -> V_629 [ V_34 ] . V_621 = F_17 ( V_343 -> V_629 [ V_34 ] . V_621 ) ;
}
return V_103 ;
}
static int F_150 ( struct V_1 * V_2 ,
T_2 V_26 ,
T_13 * V_224 ,
bool V_28 ,
bool V_630 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_444 = V_37 -> V_431 . V_444 ;
T_2 V_446 = V_37 -> V_431 . V_446 ;
T_2 V_448 = V_37 -> V_431 . V_448 ;
T_2 V_450 = V_37 -> V_431 . V_450 ;
T_2 V_452 = V_37 -> V_431 . V_452 ;
T_2 V_454 = V_37 -> V_431 . V_454 ;
T_2 V_456 = V_37 -> V_431 . V_456 ;
T_2 V_458 = V_37 -> V_431 . V_458 ;
T_2 V_460 = V_37 -> V_431 . V_460 ;
struct V_631 V_632 ;
int V_103 ;
V_103 = F_151 ( V_2 , V_26 , V_28 , & V_632 ) ;
if ( V_103 )
return V_103 ;
V_452 &= ~ V_633 ;
V_452 |= ( V_632 . V_634 << V_635 ) ;
V_454 &= ~ ( V_636 | V_637 |
V_638 ) ;
V_454 |= ( V_632 . V_639 ) << V_640 |
( V_632 . V_641 << V_642 ) |
( V_632 . V_643 << V_644 ) ;
V_448 &= ~ V_645 ;
V_448 |= ( V_632 . V_646 << V_647 ) ;
if ( V_2 -> V_217 . V_218 == V_219 ) {
V_450 &= ~ ( V_648 |
V_645 ) ;
V_450 |= ( V_632 . V_649 << V_650 ) |
( V_632 . V_646 << V_647 ) ;
}
if ( V_37 -> V_651 ) {
struct V_652 V_653 ;
T_2 V_654 ;
T_2 V_247 ;
T_2 V_279 = V_2 -> clock . V_655 . V_474 ;
if ( V_632 . V_656 == 1 )
V_654 = V_26 * 4 * ( 1 << V_632 . V_646 ) ;
else
V_654 = V_26 * 2 * ( 1 << V_632 . V_646 ) ;
V_247 = ( V_654 / V_279 ) ;
V_247 = V_247 * V_247 ;
if ( F_152 ( V_2 , & V_653 ,
V_657 , V_654 ) ) {
T_2 V_658 = V_279 * 5 / V_653 . V_659 ;
T_2 V_660 = ( T_2 ) ( ( ( ( 131 * V_653 . V_661 * V_653 . V_659 ) / 100 ) * V_247 ) / V_654 ) ;
V_458 &= ~ V_662 ;
V_458 |= ( V_660 << V_663 ) ;
V_460 &= ~ V_664 ;
V_460 |= ( V_658 << V_665 ) ;
}
}
V_446 &= ~ V_666 ;
V_446 |= ( V_632 . V_667 << V_668 ) ;
if ( V_630 )
V_446 |= V_669 |
V_670 ;
else
V_446 &= ~ ( V_669 |
V_670 ) ;
V_224 -> V_671 = V_26 ;
V_224 -> V_672 = V_452 ;
V_224 -> V_673 = V_454 ;
V_224 -> V_674 = V_456 ;
V_224 -> V_675 = V_448 ;
V_224 -> V_676 = V_450 ;
V_224 -> V_677 = V_446 ;
V_224 -> V_678 = V_444 ;
V_224 -> V_679 = V_458 ;
V_224 -> V_680 = V_460 ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 ,
T_2 V_26 ,
T_13 * V_681 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 ;
bool V_630 ;
if ( V_2 -> V_38 . V_39 . V_74 . V_527 . V_35 ) {
V_103 = F_131 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_527 ,
V_26 , & V_681 -> V_611 ) ;
if ( V_103 )
return V_103 ;
}
if ( V_2 -> V_38 . V_39 . V_74 . V_532 . V_35 ) {
V_103 = F_131 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_532 ,
V_26 , & V_681 -> V_682 ) ;
if ( V_103 )
return V_103 ;
}
if ( V_2 -> V_38 . V_39 . V_74 . V_537 . V_35 ) {
V_103 = F_131 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_537 ,
V_26 , & V_681 -> V_683 ) ;
if ( V_103 )
return V_103 ;
}
V_681 -> V_612 = 1 ;
if ( V_37 -> V_684 )
F_129 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_685 ,
V_26 ,
& V_681 -> V_612 ) ;
V_681 -> V_596 = 1 ;
V_681 -> V_686 = 1 ;
V_681 -> V_687 = 0 ;
V_681 -> V_688 = 100 ;
V_681 -> V_689 = 0 ;
V_681 -> V_690 = ( T_3 ) V_37 -> V_691 ;
V_681 -> V_692 = false ;
V_681 -> V_693 = false ;
V_681 -> V_694 = false ;
V_681 -> V_695 = false ;
V_681 -> V_696 = false ;
V_681 -> V_697 = V_698 ;
if ( V_37 -> V_699 &&
( V_26 <= V_37 -> V_699 ) &&
( ! V_37 -> V_700 ) &&
( F_2 ( V_701 ) & V_702 ) &&
( V_2 -> V_38 . V_39 . V_230 <= 2 ) )
V_681 -> V_692 = true ;
if ( V_37 -> V_703 &&
( V_26 <= V_37 -> V_703 ) )
V_681 -> V_693 = 1 ;
if ( V_2 -> V_217 . V_218 == V_219 ) {
V_681 -> V_704 =
F_7 ( V_26 , V_681 -> V_693 ) ;
if ( V_37 -> V_705 &&
( V_26 > V_37 -> V_705 ) )
V_681 -> V_694 = true ;
if ( V_37 -> V_706 &&
( V_26 > V_37 -> V_706 ) )
V_681 -> V_695 = true ;
if ( V_681 -> V_693 ) {
if ( F_7 ( V_26 , true ) >=
( ( F_2 ( V_707 ) >> 16 ) & 0xf ) )
V_630 = ( ( F_2 ( V_708 ) >> 1 ) & 0x1 ) ? true : false ;
else
V_630 = ( ( F_2 ( V_709 ) >> 1 ) & 0x1 ) ? true : false ;
} else {
V_630 = V_37 -> V_710 ;
}
} else {
V_681 -> V_704 = F_6 ( V_26 ) ;
V_630 = ( ( F_2 ( V_708 ) >> 1 ) & 0x1 ) ? true : false ;
}
V_103 = F_150 ( V_2 , V_26 , V_681 , V_681 -> V_693 , V_630 ) ;
if ( V_103 )
return V_103 ;
V_681 -> V_611 = F_25 ( V_681 -> V_611 * V_66 ) ;
V_681 -> V_612 = F_25 ( V_681 -> V_612 ) ;
V_681 -> V_682 = F_25 ( V_681 -> V_682 * V_66 ) ;
V_681 -> V_683 = F_25 ( V_681 -> V_683 * V_66 ) ;
V_681 -> V_671 = F_25 ( V_681 -> V_671 ) ;
V_681 -> V_690 = F_17 ( V_681 -> V_690 ) ;
V_681 -> V_672 = F_25 ( V_681 -> V_672 ) ;
V_681 -> V_673 = F_25 ( V_681 -> V_673 ) ;
V_681 -> V_674 = F_25 ( V_681 -> V_674 ) ;
V_681 -> V_675 = F_25 ( V_681 -> V_675 ) ;
V_681 -> V_676 = F_25 ( V_681 -> V_676 ) ;
V_681 -> V_677 = F_25 ( V_681 -> V_677 ) ;
V_681 -> V_678 = F_25 ( V_681 -> V_678 ) ;
V_681 -> V_679 = F_25 ( V_681 -> V_679 ) ;
V_681 -> V_680 = F_25 ( V_681 -> V_680 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_2 ,
T_4 * V_343 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_602 V_603 ;
T_10 V_711 ;
T_2 V_712 = V_37 -> V_431 . V_432 ;
T_2 V_713 = V_37 -> V_431 . V_434 ;
T_2 V_444 = V_37 -> V_431 . V_444 ;
T_2 V_446 = V_37 -> V_431 . V_446 ;
int V_103 ;
V_343 -> V_714 . V_715 &= ~ V_716 ;
if ( V_37 -> V_717 )
V_343 -> V_714 . V_611 = F_25 ( V_37 -> V_717 * V_66 ) ;
else
V_343 -> V_714 . V_611 = F_25 ( V_37 -> V_718 * V_66 ) ;
V_343 -> V_714 . V_612 = V_37 -> V_684 ? 0 : 1 ;
V_343 -> V_714 . V_719 = V_2 -> clock . V_473 . V_474 ;
V_103 = F_146 ( V_2 ,
V_720 ,
V_343 -> V_714 . V_719 , false , & V_603 ) ;
if ( V_103 )
return V_103 ;
V_343 -> V_714 . V_721 = ( T_1 ) V_603 . V_615 ;
V_343 -> V_714 . V_697 = V_698 ;
V_343 -> V_714 . V_722 = 0 ;
V_712 &= ~ V_723 ;
V_712 |= V_724 ;
V_713 &= ~ V_725 ;
V_713 |= ( 4 << V_726 ) ;
V_343 -> V_714 . V_727 = V_712 ;
V_343 -> V_714 . V_728 = V_713 ;
V_343 -> V_714 . V_729 = V_37 -> V_431 . V_436 ;
V_343 -> V_714 . V_730 = V_37 -> V_431 . V_438 ;
V_343 -> V_714 . V_731 = V_37 -> V_431 . V_440 ;
V_343 -> V_714 . V_732 = V_37 -> V_431 . V_442 ;
V_343 -> V_714 . V_733 = 0 ;
V_343 -> V_714 . V_734 = 0 ;
V_343 -> V_714 . V_715 = F_25 ( V_343 -> V_714 . V_715 ) ;
V_343 -> V_714 . V_612 = F_25 ( V_343 -> V_714 . V_612 ) ;
V_343 -> V_714 . V_719 = F_25 ( V_343 -> V_714 . V_719 ) ;
V_343 -> V_714 . V_727 = F_25 ( V_343 -> V_714 . V_727 ) ;
V_343 -> V_714 . V_728 = F_25 ( V_343 -> V_714 . V_728 ) ;
V_343 -> V_714 . V_729 = F_25 ( V_343 -> V_714 . V_729 ) ;
V_343 -> V_714 . V_730 = F_25 ( V_343 -> V_714 . V_730 ) ;
V_343 -> V_714 . V_731 = F_25 ( V_343 -> V_714 . V_731 ) ;
V_343 -> V_714 . V_732 = F_25 ( V_343 -> V_714 . V_732 ) ;
V_343 -> V_714 . V_733 = F_25 ( V_343 -> V_714 . V_733 ) ;
V_343 -> V_714 . V_734 = F_25 ( V_343 -> V_714 . V_734 ) ;
V_343 -> V_735 . V_611 = V_343 -> V_714 . V_611 ;
V_343 -> V_735 . V_612 = V_343 -> V_714 . V_612 ;
if ( V_37 -> V_529 != V_552 ) {
if ( V_37 -> V_736 )
V_343 -> V_735 . V_682 =
F_25 ( V_37 -> V_736 * V_66 ) ;
else
V_343 -> V_735 . V_682 =
F_25 ( V_37 -> V_737 * V_66 ) ;
}
if ( F_127 ( V_2 , 0 , & V_711 ) )
V_343 -> V_735 . V_683 = 0 ;
else
V_343 -> V_735 . V_683 =
F_25 ( V_711 . V_543 * V_66 ) ;
V_446 |= V_738 |
V_739 ;
V_446 &= ~ ( V_669 |
V_670 ) ;
V_444 &= ~ ( V_740 | V_741 ) ;
V_343 -> V_735 . V_678 = F_25 ( V_444 ) ;
V_343 -> V_735 . V_677 = F_25 ( V_446 ) ;
V_343 -> V_735 . V_675 =
F_25 ( V_37 -> V_431 . V_448 ) ;
V_343 -> V_735 . V_676 =
F_25 ( V_37 -> V_431 . V_450 ) ;
V_343 -> V_735 . V_672 =
F_25 ( V_37 -> V_431 . V_452 ) ;
V_343 -> V_735 . V_673 =
F_25 ( V_37 -> V_431 . V_454 ) ;
V_343 -> V_735 . V_674 =
F_25 ( V_37 -> V_431 . V_456 ) ;
V_343 -> V_735 . V_679 = F_25 ( V_37 -> V_431 . V_458 ) ;
V_343 -> V_735 . V_680 = F_25 ( V_37 -> V_431 . V_460 ) ;
V_343 -> V_735 . V_686 = 0 ;
V_343 -> V_735 . V_596 = 0 ;
V_343 -> V_735 . V_687 = 0 ;
V_343 -> V_735 . V_688 = 100 ;
V_343 -> V_735 . V_689 = 0 ;
V_343 -> V_735 . V_690 =
F_17 ( ( T_3 ) V_37 -> V_691 ) ;
V_343 -> V_735 . V_692 = false ;
V_343 -> V_735 . V_693 = false ;
V_343 -> V_735 . V_694 = false ;
V_343 -> V_735 . V_695 = false ;
V_343 -> V_735 . V_696 = false ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 , bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_742 * V_743 = & V_37 -> V_743 ;
if ( V_743 -> V_744 ) {
if ( V_160 )
return ( F_36 ( V_2 , V_745 ) == V_189 ) ?
0 : - V_21 ;
else
return ( F_36 ( V_2 , V_746 ) == V_189 ) ?
0 : - V_21 ;
}
return 0 ;
}
static int F_156 ( struct V_1 * V_2 ,
T_14 * V_747 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_3 V_748 = V_2 -> V_38 . V_39 . V_749 ;
V_747 -> V_733 = 0 ;
V_747 -> V_734 = 0 ;
if ( V_748 == 0 ) {
V_37 -> V_743 . V_744 = false ;
return 0 ;
}
if ( V_37 -> V_522 != V_526 ) {
if ( V_748 > V_2 -> V_38 . V_39 . V_74 . V_76 . V_35 [ 0 ] . V_520 )
V_747 -> V_750 = 0 ;
else
V_747 -> V_750 =
V_2 -> V_38 . V_39 . V_74 . V_76 . V_35 [ 0 ] . V_520 - V_748 ;
} else {
if ( V_748 > V_2 -> V_38 . V_39 . V_74 . V_76 . V_35 [ 0 ] . V_520 )
V_747 -> V_751 = 0 ;
else
V_747 -> V_751 = ( T_1 )
( ( V_2 -> V_38 . V_39 . V_74 . V_76 . V_35 [ 0 ] . V_520 - V_748 ) *
V_752 / V_753 ) ;
}
V_747 -> V_754 = V_37 -> V_684 ? 0 : 1 ;
V_747 -> V_733 = F_25 ( V_747 -> V_733 ) ;
V_747 -> V_734 = F_25 ( V_747 -> V_734 ) ;
V_747 -> V_750 = F_17 ( V_747 -> V_750 ) ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 ,
T_2 V_568 ,
T_15 * V_223 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_602 V_603 ;
T_2 V_755 = V_37 -> V_431 . V_436 ;
T_2 V_756 = V_37 -> V_431 . V_438 ;
T_2 V_440 = V_37 -> V_431 . V_440 ;
T_2 V_442 = V_37 -> V_431 . V_442 ;
T_2 V_279 = V_2 -> clock . V_473 . V_474 ;
T_2 V_757 ;
T_2 V_758 ;
int V_103 ;
V_103 = F_146 ( V_2 ,
V_720 ,
V_568 , false , & V_603 ) ;
if ( V_103 )
return V_103 ;
V_757 = 1 + V_603 . V_759 ;
V_758 = V_603 . V_760 & 0x3FFFFFF ;
V_755 &= ~ V_761 ;
V_755 |= ( V_758 << V_762 ) ;
V_755 |= V_763 ;
if ( V_37 -> V_483 ) {
struct V_652 V_653 ;
T_2 V_764 = V_568 * V_603 . V_646 ;
if ( F_152 ( V_2 , & V_653 ,
V_765 , V_764 ) ) {
T_2 V_766 = V_279 * 5 / ( V_757 * V_653 . V_659 ) ;
T_2 V_767 = 4 * V_653 . V_661 * V_758 / ( V_766 * 10000 ) ;
V_440 &= ~ ( V_768 | V_485 ) ;
V_440 |= ( V_766 << V_769 ) ;
V_440 |= ( 1 << V_770 ) ;
V_442 &= ~ V_771 ;
V_442 |= ( V_767 << V_772 ) ;
}
}
V_223 -> V_719 = V_568 ;
V_223 -> V_729 = V_755 ;
V_223 -> V_730 = V_756 ;
V_223 -> V_731 = V_440 ;
V_223 -> V_732 = V_442 ;
V_223 -> V_721 = ( T_1 ) V_603 . V_615 ;
return 0 ;
}
static int F_158 ( struct V_1 * V_2 ,
T_2 V_568 ,
T_3 V_773 ,
T_15 * V_774 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 ;
V_103 = F_157 ( V_2 , V_568 , V_774 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_131 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_76 ,
V_568 , & V_774 -> V_611 ) ;
if ( V_103 )
return V_103 ;
V_774 -> V_719 = V_568 ;
V_774 -> V_715 = 0 ;
V_774 -> V_612 = 1 ;
if ( V_37 -> V_684 )
F_128 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_685 ,
V_568 ,
& V_774 -> V_612 ) ;
V_774 -> V_690 = V_773 ;
V_774 -> V_733 = 0 ;
V_774 -> V_734 = 0 ;
V_774 -> V_686 = 1 ;
V_774 -> V_687 = 0 ;
V_774 -> V_688 = 0 ;
V_774 -> V_689 = 0 ;
V_774 -> V_775 = 0 ;
if ( V_37 -> V_466 )
V_774 -> V_722 = F_132 ( V_568 ,
V_564 ) ;
V_774 -> V_697 = V_698 ;
V_774 -> V_715 = F_25 ( V_774 -> V_715 ) ;
V_774 -> V_611 = F_25 ( V_774 -> V_611 * V_66 ) ;
V_774 -> V_612 = F_25 ( V_774 -> V_612 ) ;
V_774 -> V_719 = F_25 ( V_774 -> V_719 ) ;
V_774 -> V_690 = F_17 ( V_774 -> V_690 ) ;
V_774 -> V_729 = F_25 ( V_774 -> V_729 ) ;
V_774 -> V_730 = F_25 ( V_774 -> V_730 ) ;
V_774 -> V_731 = F_25 ( V_774 -> V_731 ) ;
V_774 -> V_732 = F_25 ( V_774 -> V_732 ) ;
V_774 -> V_733 = F_25 ( V_774 -> V_733 ) ;
V_774 -> V_734 = F_25 ( V_774 -> V_734 ) ;
return 0 ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_590 * V_126 = & V_37 -> V_126 ;
T_2 V_776 = V_37 -> V_349 +
F_20 ( T_4 , V_777 ) ;
T_2 V_778 = sizeof( T_15 ) *
V_779 ;
T_15 * V_780 = V_37 -> V_127 . V_777 ;
T_2 V_32 , V_103 ;
memset ( V_780 , 0 , V_778 ) ;
for ( V_32 = 0 ; V_32 < V_126 -> V_579 . V_34 ; V_32 ++ ) {
V_103 = F_158 ( V_2 ,
V_126 -> V_579 . V_581 [ V_32 ] . V_86 ,
( T_3 ) V_37 -> V_781 [ V_32 ] ,
& V_37 -> V_127 . V_777 [ V_32 ] ) ;
if ( V_103 )
return V_103 ;
if ( V_32 > 1 )
V_37 -> V_127 . V_777 [ V_32 ] . V_722 = 0 ;
if ( V_32 == ( V_126 -> V_579 . V_34 - 1 ) )
V_37 -> V_127 . V_777 [ V_32 ] . V_697 =
V_782 ;
}
V_37 -> V_127 . V_777 [ 0 ] . V_596 = 1 ;
V_37 -> V_127 . V_783 = ( T_1 ) V_126 -> V_579 . V_34 ;
V_37 -> V_600 . V_784 =
F_142 ( & V_126 -> V_579 ) ;
V_103 = F_27 ( V_2 , V_776 ,
( T_1 * ) V_780 , V_778 ,
V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 ,
T_14 * V_785 )
{
return F_156 ( V_2 , V_785 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_590 * V_126 = & V_37 -> V_126 ;
T_2 V_776 = V_37 -> V_349 +
F_20 ( T_4 , V_786 ) ;
T_2 V_778 = sizeof( T_13 ) *
V_787 ;
T_13 * V_780 = V_37 -> V_127 . V_786 ;
T_2 V_32 , V_103 ;
memset ( V_780 , 0 , V_778 ) ;
for ( V_32 = 0 ; V_32 < V_126 -> V_580 . V_34 ; V_32 ++ ) {
if ( V_126 -> V_580 . V_581 [ V_32 ] . V_86 == 0 )
return - V_21 ;
V_103 = F_153 ( V_2 ,
V_126 -> V_580 . V_581 [ V_32 ] . V_86 ,
& V_37 -> V_127 . V_786 [ V_32 ] ) ;
if ( V_103 )
return V_103 ;
}
if ( ( V_126 -> V_580 . V_34 >= 2 ) &&
( ( V_2 -> V_46 -> V_47 == 0x67B0 ) || ( V_2 -> V_46 -> V_47 == 0x67B1 ) ) ) {
V_37 -> V_127 . V_786 [ 1 ] . V_611 =
V_37 -> V_127 . V_786 [ 0 ] . V_611 ;
V_37 -> V_127 . V_786 [ 1 ] . V_612 =
V_37 -> V_127 . V_786 [ 0 ] . V_612 ;
}
V_37 -> V_127 . V_786 [ 0 ] . V_690 = F_17 ( 0x1F ) ;
V_37 -> V_127 . V_788 = ( T_1 ) V_126 -> V_580 . V_34 ;
V_37 -> V_600 . V_789 =
F_142 ( & V_126 -> V_580 ) ;
V_37 -> V_127 . V_786 [ V_126 -> V_580 . V_34 - 1 ] . V_697 =
V_782 ;
V_103 = F_27 ( V_2 , V_776 ,
( T_1 * ) V_780 , V_778 ,
V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_587 * V_126 ,
T_2 V_34 )
{
T_2 V_32 ;
V_126 -> V_34 = V_34 ;
for ( V_32 = 0 ; V_32 < V_790 ; V_32 ++ )
V_126 -> V_581 [ V_32 ] . V_589 = false ;
}
static void F_163 ( struct V_587 * V_126 ,
T_2 V_791 , T_2 V_792 , T_2 V_793 )
{
V_126 -> V_581 [ V_791 ] . V_86 = V_792 ;
V_126 -> V_581 [ V_791 ] . V_595 = V_793 ;
V_126 -> V_581 [ V_791 ] . V_589 = true ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( ! V_37 -> V_794 && ! V_37 -> V_795 )
return - V_21 ;
if ( V_37 -> V_794 && ! V_37 -> V_795 ) {
V_37 -> V_796 = V_37 -> V_797 ;
V_37 -> V_798 = V_37 -> V_799 ;
} else if ( ! V_37 -> V_794 && V_37 -> V_795 ) {
V_37 -> V_797 = V_37 -> V_796 ;
V_37 -> V_799 = V_37 -> V_798 ;
}
F_162 ( V_2 ,
& V_37 -> V_126 . V_591 ,
V_800 ) ;
if ( V_2 -> V_60 == V_801 )
F_163 ( & V_37 -> V_126 . V_591 , 0 ,
V_37 -> V_796 . V_115 ,
V_37 -> V_798 . V_116 ) ;
else
F_163 ( & V_37 -> V_126 . V_591 , 0 ,
V_37 -> V_796 . V_115 ,
V_37 -> V_798 . V_115 ) ;
F_163 ( & V_37 -> V_126 . V_591 , 1 ,
V_37 -> V_797 . V_115 ,
V_37 -> V_799 . V_115 ) ;
F_163 ( & V_37 -> V_126 . V_591 , 2 ,
V_37 -> V_796 . V_115 ,
V_37 -> V_798 . V_116 ) ;
F_163 ( & V_37 -> V_126 . V_591 , 3 ,
V_37 -> V_797 . V_115 ,
V_37 -> V_799 . V_116 ) ;
F_163 ( & V_37 -> V_126 . V_591 , 4 ,
V_37 -> V_796 . V_116 ,
V_37 -> V_798 . V_116 ) ;
F_163 ( & V_37 -> V_126 . V_591 , 5 ,
V_37 -> V_797 . V_116 ,
V_37 -> V_799 . V_116 ) ;
V_37 -> V_126 . V_591 . V_34 = 6 ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_516 * V_802 =
& V_2 -> V_38 . V_39 . V_74 . V_76 ;
struct V_516 * V_803 =
& V_2 -> V_38 . V_39 . V_74 . V_527 ;
struct V_804 * V_805 =
& V_2 -> V_38 . V_39 . V_74 . V_75 ;
T_2 V_32 ;
if ( V_802 == NULL )
return - V_21 ;
if ( V_802 -> V_34 < 1 )
return - V_21 ;
if ( V_803 == NULL )
return - V_21 ;
if ( V_803 -> V_34 < 1 )
return - V_21 ;
memset ( & V_37 -> V_126 , 0 , sizeof( struct V_590 ) ) ;
F_162 ( V_2 ,
& V_37 -> V_126 . V_579 ,
V_779 ) ;
F_162 ( V_2 ,
& V_37 -> V_126 . V_580 ,
V_787 ) ;
F_162 ( V_2 ,
& V_37 -> V_126 . V_806 ,
V_528 ) ;
F_162 ( V_2 ,
& V_37 -> V_126 . V_807 ,
V_533 ) ;
F_162 ( V_2 ,
& V_37 -> V_126 . V_808 ,
V_538 ) ;
V_37 -> V_126 . V_579 . V_34 = 0 ;
for ( V_32 = 0 ; V_32 < V_802 -> V_34 ; V_32 ++ ) {
if ( ( V_32 == 0 ) ||
( V_37 -> V_126 . V_579 . V_581 [ V_37 -> V_126 . V_579 . V_34 - 1 ] . V_86 !=
V_802 -> V_35 [ V_32 ] . V_553 ) ) {
V_37 -> V_126 . V_579 . V_581 [ V_37 -> V_126 . V_579 . V_34 ] . V_86 =
V_802 -> V_35 [ V_32 ] . V_553 ;
V_37 -> V_126 . V_579 . V_581 [ V_37 -> V_126 . V_579 . V_34 ] . V_589 =
( V_32 == 0 ) ? true : false ;
V_37 -> V_126 . V_579 . V_34 ++ ;
}
}
V_37 -> V_126 . V_580 . V_34 = 0 ;
for ( V_32 = 0 ; V_32 < V_803 -> V_34 ; V_32 ++ ) {
if ( ( V_32 == 0 ) ||
( V_37 -> V_126 . V_580 . V_581 [ V_37 -> V_126 . V_580 . V_34 - 1 ] . V_86 !=
V_803 -> V_35 [ V_32 ] . V_553 ) ) {
V_37 -> V_126 . V_580 . V_581 [ V_37 -> V_126 . V_580 . V_34 ] . V_86 =
V_803 -> V_35 [ V_32 ] . V_553 ;
V_37 -> V_126 . V_580 . V_581 [ V_37 -> V_126 . V_580 . V_34 ] . V_589 =
( V_32 == 0 ) ? true : false ;
V_37 -> V_126 . V_580 . V_34 ++ ;
}
}
for ( V_32 = 0 ; V_32 < V_802 -> V_34 ; V_32 ++ ) {
V_37 -> V_126 . V_806 . V_581 [ V_32 ] . V_86 =
V_802 -> V_35 [ V_32 ] . V_520 ;
V_37 -> V_126 . V_806 . V_581 [ V_32 ] . V_595 =
V_805 -> V_35 [ V_32 ] . V_82 ;
V_37 -> V_126 . V_806 . V_581 [ V_32 ] . V_589 = true ;
}
V_37 -> V_126 . V_806 . V_34 = V_802 -> V_34 ;
V_803 = & V_2 -> V_38 . V_39 . V_74 . V_532 ;
if ( V_803 ) {
for ( V_32 = 0 ; V_32 < V_803 -> V_34 ; V_32 ++ ) {
V_37 -> V_126 . V_807 . V_581 [ V_32 ] . V_86 =
V_803 -> V_35 [ V_32 ] . V_520 ;
V_37 -> V_126 . V_807 . V_581 [ V_32 ] . V_589 = true ;
}
V_37 -> V_126 . V_807 . V_34 = V_803 -> V_34 ;
}
V_803 = & V_2 -> V_38 . V_39 . V_74 . V_537 ;
if ( V_803 ) {
for ( V_32 = 0 ; V_32 < V_803 -> V_34 ; V_32 ++ ) {
V_37 -> V_126 . V_808 . V_581 [ V_32 ] . V_86 =
V_803 -> V_35 [ V_32 ] . V_520 ;
V_37 -> V_126 . V_808 . V_581 [ V_32 ] . V_589 = true ;
}
V_37 -> V_126 . V_808 . V_34 = V_803 -> V_34 ;
}
F_164 ( V_2 ) ;
memcpy ( & ( V_37 -> V_809 ) , & ( V_37 -> V_126 ) ,
sizeof( struct V_590 ) ) ;
return 0 ;
}
static int F_166 ( struct V_587 * V_343 ,
T_2 V_86 , T_2 * V_810 )
{
T_2 V_32 ;
int V_103 = - V_21 ;
for( V_32 = 0 ; V_32 < V_343 -> V_34 ; V_32 ++ ) {
if ( V_86 == V_343 -> V_581 [ V_32 ] . V_86 ) {
* V_810 = V_32 ;
V_103 = 0 ;
}
}
return V_103 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct T_15 * V_780 =
V_37 -> V_127 . V_777 ;
T_16 V_811 = 0 ;
V_37 -> V_812 . V_813 =
F_168 ( V_780 [ 0 ] . V_690 ) ;
V_37 -> V_812 . V_814 = V_780 [ 0 ] . V_687 ;
V_37 -> V_812 . V_815 = V_780 [ 0 ] . V_688 ;
V_37 -> V_812 . type = V_816 ;
V_37 -> V_817 = V_37 -> V_812 ;
V_37 -> V_817 . type = V_818 ;
if ( V_37 -> V_127 . V_783 > 2 )
V_811 = V_37 -> V_127 . V_783 - 2 ;
else if ( V_37 -> V_127 . V_783 == 2 )
V_811 = 1 ;
V_37 -> V_817 . V_819 =
F_169 ( V_780 [ V_811 ] . V_719 ) ;
V_37 -> V_817 . V_814 = 0 ;
V_37 -> V_817 . V_815 = 5 ;
V_37 -> V_820 = V_37 -> V_812 ;
V_37 -> V_821 = V_37 -> V_817 ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_742 * V_743 = & V_37 -> V_743 ;
struct V_42 * V_582 = V_2 -> V_38 . V_39 . V_822 ;
T_4 * V_343 = & V_37 -> V_127 ;
int V_103 ;
V_103 = F_165 ( V_2 ) ;
if ( V_103 )
return V_103 ;
if ( V_37 -> V_522 != V_552 )
F_126 ( V_2 , V_343 ) ;
F_72 ( V_2 ) ;
if ( V_2 -> V_38 . V_39 . V_77 & V_823 )
V_343 -> V_824 |= V_825 ;
if ( V_2 -> V_38 . V_39 . V_77 & V_826 )
V_343 -> V_824 |= V_827 ;
if ( V_2 -> V_217 . V_218 == V_219 )
V_343 -> V_824 |= V_828 ;
if ( V_743 -> V_744 ) {
V_103 = F_160 ( V_2 , & V_37 -> V_127 . V_829 ) ;
if ( V_103 )
return V_103 ;
F_33 ( V_830 , V_743 -> V_831 ) ;
}
V_103 = F_159 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_161 ( V_2 ) ;
if ( V_103 )
return V_103 ;
F_143 ( V_2 , V_343 ) ;
V_103 = F_154 ( V_2 , V_343 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_147 ( V_2 , V_343 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_148 ( V_2 , V_343 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_149 ( V_2 , V_343 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_139 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_145 ( V_2 , V_343 ) ;
if ( V_103 )
return V_103 ;
V_343 -> V_832 = 0 ;
V_343 -> V_833 = 0 ;
V_343 -> V_834 = 0 ;
V_343 -> V_835 = 0 ;
V_343 -> V_585 = 0 ;
V_343 -> V_586 = 0 ;
V_103 = F_166 ( & V_37 -> V_126 . V_579 ,
V_37 -> V_836 . V_837 ,
( T_2 * ) & V_37 -> V_127 . V_585 ) ;
V_103 = F_166 ( & V_37 -> V_126 . V_580 ,
V_37 -> V_836 . V_838 ,
( T_2 * ) & V_37 -> V_127 . V_586 ) ;
V_343 -> V_839 = V_37 -> V_836 . V_840 ;
V_343 -> V_841 = V_37 -> V_836 . V_842 ;
V_343 -> V_843 = V_37 -> V_836 . V_844 ;
F_141 ( V_2 , V_582 ) ;
V_103 = F_24 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_343 -> V_845 = 1 ;
V_343 -> V_846 = 1 ;
V_343 -> V_847 = 1 ;
V_343 -> V_848 = 1 ;
V_343 -> V_849 = 1 ;
V_343 -> V_850 = 1 ;
V_343 -> V_851 = 1 ;
V_343 -> V_852 = 1 ;
V_343 -> V_853 = 1 ;
V_343 -> V_854 = ( T_3 ) ( ( V_37 -> V_141 . V_142 *
V_855 ) / 1000 ) ;
V_343 -> V_856 = ( T_3 ) ( ( V_37 -> V_141 . V_857 *
V_855 ) / 1000 ) ;
V_343 -> V_858 = 1 ;
V_343 -> V_859 = 1 ;
V_343 -> V_860 = 0 ;
V_343 -> V_861 = 4000 ;
V_343 -> V_862 = 0 ;
V_343 -> V_863 = 1 ;
V_343 -> V_864 = V_37 -> V_126 . V_591 . V_34 - 1 ;
V_343 -> V_865 = 1 ;
if ( V_37 -> V_522 == V_526 )
V_343 -> V_866 = 1 ;
else
V_343 -> V_866 = 0 ;
V_343 -> V_867 = 17 ;
V_343 -> V_868 = 0x4000 ;
V_343 -> V_824 = F_25 ( V_343 -> V_824 ) ;
V_343 -> V_869 = F_25 ( V_343 -> V_869 ) ;
V_343 -> V_870 = F_25 ( V_343 -> V_870 ) ;
V_343 -> V_871 = F_25 ( V_343 -> V_871 ) ;
V_343 -> V_872 = F_25 ( V_343 -> V_872 ) ;
V_343 -> V_868 = F_25 ( V_343 -> V_868 ) ;
V_343 -> V_854 = F_17 ( V_343 -> V_854 ) ;
V_343 -> V_856 = F_17 ( V_343 -> V_856 ) ;
V_343 -> V_861 = F_17 ( V_343 -> V_861 ) ;
V_343 -> V_860 = F_17 ( V_343 -> V_860 ) ;
V_343 -> V_862 = F_17 ( V_343 -> V_862 ) ;
V_343 -> V_839 = F_17 ( V_343 -> V_839 * V_66 ) ;
V_343 -> V_841 = F_17 ( V_343 -> V_841 * V_66 ) ;
V_343 -> V_843 = F_17 ( V_343 -> V_843 * V_66 ) ;
V_103 = F_27 ( V_2 ,
V_37 -> V_349 +
F_20 ( T_4 , V_824 ) ,
( T_1 * ) & V_343 -> V_824 ,
sizeof( T_4 ) - 3 * sizeof( V_873 ) ,
V_37 -> V_109 ) ;
if ( V_103 )
return V_103 ;
F_167 ( V_2 ) ;
return 0 ;
}
static void F_171 ( struct V_1 * V_2 ,
struct V_587 * V_126 ,
T_2 V_874 , T_2 V_875 )
{
T_2 V_32 ;
for ( V_32 = 0 ; V_32 < V_126 -> V_34 ; V_32 ++ ) {
if ( ( V_126 -> V_581 [ V_32 ] . V_86 < V_874 ) ||
( V_126 -> V_581 [ V_32 ] . V_86 > V_875 ) )
V_126 -> V_581 [ V_32 ] . V_589 = false ;
else
V_126 -> V_581 [ V_32 ] . V_589 = true ;
}
}
static void F_172 ( struct V_1 * V_2 ,
T_2 V_876 , T_2 V_877 ,
T_2 V_878 , T_2 V_879 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_587 * V_880 = & V_37 -> V_126 . V_591 ;
T_2 V_32 , V_131 ;
for ( V_32 = 0 ; V_32 < V_880 -> V_34 ; V_32 ++ ) {
if ( ( V_880 -> V_581 [ V_32 ] . V_86 < V_876 ) ||
( V_880 -> V_581 [ V_32 ] . V_595 < V_877 ) ||
( V_880 -> V_581 [ V_32 ] . V_86 > V_878 ) ||
( V_880 -> V_581 [ V_32 ] . V_595 > V_879 ) )
V_880 -> V_581 [ V_32 ] . V_589 = false ;
else
V_880 -> V_581 [ V_32 ] . V_589 = true ;
}
for ( V_32 = 0 ; V_32 < V_880 -> V_34 ; V_32 ++ ) {
if ( V_880 -> V_581 [ V_32 ] . V_589 ) {
for ( V_131 = V_32 + 1 ; V_131 < V_880 -> V_34 ; V_131 ++ ) {
if ( V_880 -> V_581 [ V_131 ] . V_589 ) {
if ( ( V_880 -> V_581 [ V_32 ] . V_86 == V_880 -> V_581 [ V_131 ] . V_86 ) &&
( V_880 -> V_581 [ V_32 ] . V_595 == V_880 -> V_581 [ V_131 ] . V_595 ) )
V_880 -> V_581 [ V_131 ] . V_589 = false ;
}
}
}
}
}
static int F_173 ( struct V_1 * V_2 ,
struct V_42 * V_881 )
{
struct V_41 * V_747 = F_10 ( V_881 ) ;
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_882 ;
if ( V_747 -> V_238 < 1 )
return - V_21 ;
if ( V_747 -> V_238 == 1 )
V_882 = 0 ;
else
V_882 = 1 ;
F_171 ( V_2 ,
& V_37 -> V_126 . V_579 ,
V_747 -> V_239 [ 0 ] . V_223 ,
V_747 -> V_239 [ V_882 ] . V_223 ) ;
F_171 ( V_2 ,
& V_37 -> V_126 . V_580 ,
V_747 -> V_239 [ 0 ] . V_224 ,
V_747 -> V_239 [ V_882 ] . V_224 ) ;
F_172 ( V_2 ,
V_747 -> V_239 [ 0 ] . V_792 ,
V_747 -> V_239 [ 0 ] . V_883 ,
V_747 -> V_239 [ V_882 ] . V_792 ,
V_747 -> V_239 [ V_882 ] . V_883 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_516 * V_884 =
& V_2 -> V_38 . V_39 . V_74 . V_885 ;
struct V_516 * V_806 =
& V_2 -> V_38 . V_39 . V_74 . V_76 ;
T_2 V_886 = 0 ;
T_2 V_32 ;
if ( V_884 == NULL )
return - V_21 ;
if ( ! V_884 -> V_34 )
return - V_21 ;
for ( V_32 = 0 ; V_32 < V_884 -> V_34 ; V_32 ++ ) {
if ( V_2 -> clock . V_887 == V_884 -> V_35 [ V_32 ] . V_553 )
V_886 = V_884 -> V_35 [ V_32 ] . V_520 ;
}
for ( V_32 = 0 ; V_32 < V_806 -> V_34 ; V_32 ++ ) {
if ( V_886 <= V_806 -> V_35 [ V_32 ] . V_520 ) {
V_886 = V_806 -> V_35 [ V_32 ] . V_520 ;
return ( F_58 ( V_2 ,
V_888 ,
V_886 * V_66 ) == V_189 ) ?
0 : - V_21 ;
}
}
return - V_21 ;
}
static int F_175 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_5 V_255 ;
F_174 ( V_2 ) ;
if ( ! V_37 -> V_377 ) {
if ( V_37 -> V_600 . V_784 ) {
V_255 = F_58 ( V_2 ,
V_412 ,
V_37 -> V_600 . V_784 ) ;
if ( V_255 != V_189 )
return - V_21 ;
}
}
if ( ! V_37 -> V_381 ) {
if ( V_37 -> V_600 . V_789 ) {
V_255 = F_58 ( V_2 ,
V_413 ,
V_37 -> V_600 . V_789 ) ;
if ( V_255 != V_189 )
return - V_21 ;
}
}
#if 0
if (!pi->pcie_dpm_key_disabled) {
if (pi->dpm_level_enable_mask.pcie_dpm_enable_mask) {
result = amdgpu_ci_send_msg_to_smc_with_parameter(adev,
PPSMC_MSG_PCIeDPM_SetEnabledMask,
pi->dpm_level_enable_mask.pcie_dpm_enable_mask);
if (result != PPSMC_Result_OK)
return -EINVAL;
}
}
#endif
return 0 ;
}
static void F_176 ( struct V_1 * V_2 ,
struct V_42 * V_881 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_41 * V_747 = F_10 ( V_881 ) ;
struct V_587 * V_579 = & V_37 -> V_126 . V_579 ;
T_2 V_223 = V_747 -> V_239 [ V_747 -> V_238 - 1 ] . V_223 ;
struct V_587 * V_580 = & V_37 -> V_126 . V_580 ;
T_2 V_224 = V_747 -> V_239 [ V_747 -> V_238 - 1 ] . V_224 ;
T_2 V_32 ;
V_37 -> V_376 = 0 ;
for ( V_32 = 0 ; V_32 < V_579 -> V_34 ; V_32 ++ ) {
if ( V_223 == V_579 -> V_581 [ V_32 ] . V_86 )
break;
}
if ( V_32 >= V_579 -> V_34 ) {
V_37 -> V_376 |= V_378 ;
} else {
if ( V_564 != V_564 )
V_37 -> V_376 |= V_379 ;
}
for ( V_32 = 0 ; V_32 < V_580 -> V_34 ; V_32 ++ ) {
if ( V_224 == V_580 -> V_581 [ V_32 ] . V_86 )
break;
}
if ( V_32 >= V_580 -> V_34 )
V_37 -> V_376 |= V_382 ;
if ( V_2 -> V_38 . V_39 . V_889 !=
V_2 -> V_38 . V_39 . V_230 )
V_37 -> V_376 |= V_890 ;
}
static int F_177 ( struct V_1 * V_2 ,
struct V_42 * V_881 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_41 * V_747 = F_10 ( V_881 ) ;
T_2 V_223 = V_747 -> V_239 [ V_747 -> V_238 - 1 ] . V_223 ;
T_2 V_224 = V_747 -> V_239 [ V_747 -> V_238 - 1 ] . V_224 ;
struct V_590 * V_126 = & V_37 -> V_126 ;
int V_103 ;
if ( ! V_37 -> V_376 )
return 0 ;
if ( V_37 -> V_376 & V_378 )
V_126 -> V_579 . V_581 [ V_126 -> V_579 . V_34 - 1 ] . V_86 = V_223 ;
if ( V_37 -> V_376 & V_382 )
V_126 -> V_580 . V_581 [ V_126 -> V_580 . V_34 - 1 ] . V_86 = V_224 ;
if ( V_37 -> V_376 & ( V_378 | V_379 ) ) {
V_103 = F_159 ( V_2 ) ;
if ( V_103 )
return V_103 ;
}
if ( V_37 -> V_376 & ( V_382 | V_890 ) ) {
V_103 = F_161 ( V_2 ) ;
if ( V_103 )
return V_103 ;
}
return 0 ;
}
static int F_178 ( struct V_1 * V_2 , bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
const struct V_220 * V_221 ;
int V_32 ;
if ( V_2 -> V_38 . V_39 . V_235 )
V_221 = & V_2 -> V_38 . V_39 . V_74 . V_236 ;
else
V_221 = & V_2 -> V_38 . V_39 . V_74 . V_237 ;
if ( V_160 ) {
V_37 -> V_600 . V_891 = 0 ;
for ( V_32 = V_2 -> V_38 . V_39 . V_74 . V_605 . V_34 - 1 ; V_32 >= 0 ; V_32 -- ) {
if ( V_2 -> V_38 . V_39 . V_74 . V_605 . V_35 [ V_32 ] . V_520 <= V_221 -> V_65 ) {
V_37 -> V_600 . V_891 |= 1 << V_32 ;
if ( ! V_37 -> V_892 )
break;
}
}
F_58 ( V_2 ,
V_893 ,
V_37 -> V_600 . V_891 ) ;
if ( V_37 -> V_894 & 0x1 ) {
V_37 -> V_700 = true ;
V_37 -> V_600 . V_789 &= 0xFFFFFFFE ;
F_58 ( V_2 ,
V_413 ,
V_37 -> V_600 . V_789 ) ;
}
} else {
if ( V_37 -> V_700 ) {
V_37 -> V_700 = false ;
V_37 -> V_600 . V_789 |= 1 ;
F_58 ( V_2 ,
V_413 ,
V_37 -> V_600 . V_789 ) ;
}
}
return ( F_36 ( V_2 , V_160 ?
V_895 : V_896 ) == V_189 ) ?
0 : - V_21 ;
}
static int F_179 ( struct V_1 * V_2 , bool V_160 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
const struct V_220 * V_221 ;
int V_32 ;
if ( V_2 -> V_38 . V_39 . V_235 )
V_221 = & V_2 -> V_38 . V_39 . V_74 . V_236 ;
else
V_221 = & V_2 -> V_38 . V_39 . V_74 . V_237 ;
if ( V_160 ) {
V_37 -> V_600 . V_897 = 0 ;
for ( V_32 = V_2 -> V_38 . V_39 . V_74 . V_618 . V_34 - 1 ; V_32 >= 0 ; V_32 -- ) {
if ( V_2 -> V_38 . V_39 . V_74 . V_618 . V_35 [ V_32 ] . V_520 <= V_221 -> V_65 ) {
V_37 -> V_600 . V_897 |= 1 << V_32 ;
if ( ! V_37 -> V_898 )
break;
}
}
F_58 ( V_2 ,
V_899 ,
V_37 -> V_600 . V_897 ) ;
}
return ( F_36 ( V_2 , V_160 ?
V_900 : V_901 ) == V_189 ) ?
0 : - V_21 ;
}
static int F_44 ( struct V_1 * V_2 , bool V_210 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_247 ;
int V_103 = 0 ;
if ( ! V_210 ) {
if ( V_37 -> V_892 ||
( V_2 -> V_38 . V_39 . V_74 . V_605 . V_34 <= 0 ) )
V_37 -> V_127 . V_832 = 0 ;
else
V_37 -> V_127 . V_832 =
V_2 -> V_38 . V_39 . V_74 . V_605 . V_34 - 1 ;
V_247 = F_32 ( V_902 ) ;
V_247 &= ~ V_903 ;
V_247 |= ( V_37 -> V_127 . V_832 << V_904 ) ;
F_33 ( V_902 , V_247 ) ;
V_103 = F_178 ( V_2 , true ) ;
} else {
V_103 = F_178 ( V_2 , false ) ;
if ( V_103 )
return V_103 ;
}
return V_103 ;
}
static T_1 F_180 ( struct V_1 * V_2 )
{
T_1 V_32 ;
T_2 V_905 = 30000 ;
struct V_906 * V_343 =
& V_2 -> V_38 . V_39 . V_74 . V_618 ;
for ( V_32 = 0 ; V_32 < V_343 -> V_34 ; V_32 ++ ) {
if ( V_343 -> V_35 [ V_32 ] . V_226 >= V_905 )
return V_32 ;
}
return V_343 -> V_34 - 1 ;
}
static int F_181 ( struct V_1 * V_2 ,
struct V_42 * V_907 ,
struct V_42 * V_908 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 = 0 ;
T_2 V_247 ;
if ( V_908 -> V_226 != V_907 -> V_226 ) {
if ( V_907 -> V_226 ) {
V_37 -> V_127 . V_833 = F_180 ( V_2 ) ;
V_247 = F_32 ( V_902 ) ;
V_247 &= ~ V_909 ;
V_247 |= ( V_37 -> V_127 . V_833 << V_910 ) ;
F_33 ( V_902 , V_247 ) ;
V_103 = F_179 ( V_2 , true ) ;
} else {
V_103 = F_179 ( V_2 , false ) ;
if ( V_103 )
return V_103 ;
}
}
return V_103 ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_42 * V_881 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 ;
V_103 = F_173 ( V_2 , V_881 ) ;
if ( V_103 )
return V_103 ;
V_37 -> V_600 . V_784 =
F_142 ( & V_37 -> V_126 . V_579 ) ;
V_37 -> V_600 . V_789 =
F_142 ( & V_37 -> V_126 . V_580 ) ;
V_37 -> V_894 =
V_37 -> V_600 . V_789 ;
if ( V_37 -> V_700 ) {
if ( V_37 -> V_600 . V_789 & 1 )
V_37 -> V_600 . V_789 &= 0xFFFFFFFE ;
}
V_37 -> V_600 . V_601 =
F_142 ( & V_37 -> V_126 . V_591 ) ;
return 0 ;
}
static T_2 F_183 ( struct V_1 * V_2 ,
T_2 V_911 )
{
T_2 V_584 = 0 ;
while ( ( V_911 & ( 1 << V_584 ) ) == 0 )
V_584 ++ ;
return V_584 ;
}
static int F_184 ( struct V_1 * V_2 ,
enum V_912 V_584 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_247 , V_780 , V_32 ;
int V_103 ;
if ( V_584 == V_913 ) {
if ( ( ! V_37 -> V_401 ) &&
V_37 -> V_600 . V_601 ) {
V_780 = 0 ;
V_247 = V_37 -> V_600 . V_601 ;
while ( V_247 >>= 1 )
V_780 ++ ;
if ( V_780 ) {
V_103 = F_91 ( V_2 , V_584 ) ;
if ( V_103 )
return V_103 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_421 ; V_32 ++ ) {
V_247 = ( F_32 ( V_914 ) &
V_915 ) >>
V_916 ;
if ( V_247 == V_780 )
break;
F_83 ( 1 ) ;
}
}
}
if ( ( ! V_37 -> V_377 ) &&
V_37 -> V_600 . V_784 ) {
V_780 = 0 ;
V_247 = V_37 -> V_600 . V_784 ;
while ( V_247 >>= 1 )
V_780 ++ ;
if ( V_780 ) {
V_103 = F_89 ( V_2 , V_780 ) ;
if ( V_103 )
return V_103 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_421 ; V_32 ++ ) {
V_247 = ( F_32 ( V_917 ) &
V_918 ) >>
V_919 ;
if ( V_247 == V_780 )
break;
F_83 ( 1 ) ;
}
}
}
if ( ( ! V_37 -> V_381 ) &&
V_37 -> V_600 . V_789 ) {
V_780 = 0 ;
V_247 = V_37 -> V_600 . V_789 ;
while ( V_247 >>= 1 )
V_780 ++ ;
if ( V_780 ) {
V_103 = F_90 ( V_2 , V_780 ) ;
if ( V_103 )
return V_103 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_421 ; V_32 ++ ) {
V_247 = ( F_32 ( V_917 ) &
V_920 ) >>
V_921 ;
if ( V_247 == V_780 )
break;
F_83 ( 1 ) ;
}
}
}
} else if ( V_584 == V_922 ) {
if ( ( ! V_37 -> V_377 ) &&
V_37 -> V_600 . V_784 ) {
V_780 = F_183 ( V_2 ,
V_37 -> V_600 . V_784 ) ;
V_103 = F_89 ( V_2 , V_780 ) ;
if ( V_103 )
return V_103 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_421 ; V_32 ++ ) {
V_247 = ( F_32 ( V_917 ) &
V_918 ) >>
V_919 ;
if ( V_247 == V_780 )
break;
F_83 ( 1 ) ;
}
}
if ( ( ! V_37 -> V_381 ) &&
V_37 -> V_600 . V_789 ) {
V_780 = F_183 ( V_2 ,
V_37 -> V_600 . V_789 ) ;
V_103 = F_90 ( V_2 , V_780 ) ;
if ( V_103 )
return V_103 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_421 ; V_32 ++ ) {
V_247 = ( F_32 ( V_917 ) &
V_920 ) >>
V_921 ;
if ( V_247 == V_780 )
break;
F_83 ( 1 ) ;
}
}
if ( ( ! V_37 -> V_401 ) &&
V_37 -> V_600 . V_601 ) {
V_780 = F_183 ( V_2 ,
V_37 -> V_600 . V_601 ) ;
V_103 = F_91 ( V_2 , V_780 ) ;
if ( V_103 )
return V_103 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_421 ; V_32 ++ ) {
V_247 = ( F_32 ( V_914 ) &
V_915 ) >>
V_916 ;
if ( V_247 == V_780 )
break;
F_83 ( 1 ) ;
}
}
} else if ( V_584 == V_923 ) {
if ( ! V_37 -> V_401 ) {
T_5 V_186 ;
V_186 = F_36 ( V_2 ,
V_924 ) ;
if ( V_186 != V_189 )
return - V_21 ;
}
V_103 = F_175 ( V_2 ) ;
if ( V_103 )
return V_103 ;
}
V_2 -> V_38 . V_39 . V_925 = V_584 ;
return 0 ;
}
static int F_185 ( struct V_1 * V_2 ,
struct V_926 * V_343 )
{
T_1 V_32 , V_131 , V_132 ;
T_2 V_927 ;
for ( V_32 = 0 , V_131 = V_343 -> V_928 ; V_32 < V_343 -> V_928 ; V_32 ++ ) {
if ( V_131 >= V_929 )
return - V_21 ;
switch( V_343 -> V_930 [ V_32 ] . V_931 ) {
case V_932 :
V_927 = F_2 ( V_933 ) ;
V_343 -> V_930 [ V_131 ] . V_931 = V_933 ;
V_343 -> V_930 [ V_131 ] . V_934 = V_935 ;
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
V_343 -> V_937 [ V_132 ] . V_938 [ V_131 ] =
( ( V_927 & 0xffff0000 ) ) | ( ( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xffff0000 ) >> 16 ) ;
}
V_131 ++ ;
if ( V_131 >= V_929 )
return - V_21 ;
V_927 = F_2 ( V_939 ) ;
V_343 -> V_930 [ V_131 ] . V_931 = V_939 ;
V_343 -> V_930 [ V_131 ] . V_934 = V_940 ;
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
V_343 -> V_937 [ V_132 ] . V_938 [ V_131 ] =
( V_927 & 0xffff0000 ) | ( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0x0000ffff ) ;
if ( V_2 -> V_217 . V_218 != V_219 )
V_343 -> V_937 [ V_132 ] . V_938 [ V_131 ] |= 0x100 ;
}
V_131 ++ ;
if ( V_131 > V_929 )
return - V_21 ;
if ( V_2 -> V_217 . V_218 != V_219 ) {
V_343 -> V_930 [ V_131 ] . V_931 = V_941 ;
V_343 -> V_930 [ V_131 ] . V_934 = V_941 ;
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
V_343 -> V_937 [ V_132 ] . V_938 [ V_131 ] =
( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xffff0000 ) >> 16 ;
}
V_131 ++ ;
if ( V_131 > V_929 )
return - V_21 ;
}
break;
case V_942 :
V_927 = F_2 ( V_943 ) ;
V_343 -> V_930 [ V_131 ] . V_931 = V_943 ;
V_343 -> V_930 [ V_131 ] . V_934 = V_944 ;
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
V_343 -> V_937 [ V_132 ] . V_938 [ V_131 ] =
( V_927 & 0xffff0000 ) | ( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0x0000ffff ) ;
}
V_131 ++ ;
if ( V_131 > V_929 )
return - V_21 ;
break;
default:
break;
}
}
V_343 -> V_928 = V_131 ;
return 0 ;
}
static bool F_186 ( T_3 V_945 , T_3 * V_946 )
{
bool V_255 = true ;
switch( V_945 ) {
case V_947 :
* V_946 = V_948 ;
break;
case V_949 :
* V_946 = V_950 ;
break;
case V_951 :
* V_946 = V_952 ;
break;
case V_953 :
* V_946 = V_954 ;
break;
case V_955 :
* V_946 = V_956 ;
break;
case V_957 :
* V_946 = V_958 ;
break;
case V_959 :
* V_946 = V_960 ;
break;
case V_961 :
* V_946 = V_962 ;
break;
case V_963 :
* V_946 = V_964 ;
break;
case V_965 :
* V_946 = V_966 ;
break;
case V_967 :
* V_946 = V_968 ;
break;
case V_969 :
* V_946 = V_970 ;
break;
case V_971 :
* V_946 = V_972 ;
break;
case V_973 :
* V_946 = V_974 ;
break;
case V_933 :
* V_946 = V_935 ;
break;
case V_939 :
* V_946 = V_940 ;
break;
case V_943 :
* V_946 = V_944 ;
break;
case V_975 :
* V_946 = V_976 ;
break;
case V_977 :
* V_946 = V_978 ;
break;
case V_979 :
* V_946 = V_980 ;
break;
default:
V_255 = false ;
break;
}
return V_255 ;
}
static void F_187 ( struct V_926 * V_343 )
{
T_1 V_32 , V_131 ;
for ( V_32 = 0 ; V_32 < V_343 -> V_928 ; V_32 ++ ) {
for ( V_131 = 1 ; V_131 < V_343 -> V_936 ; V_131 ++ ) {
if ( V_343 -> V_937 [ V_131 - 1 ] . V_938 [ V_32 ] !=
V_343 -> V_937 [ V_131 ] . V_938 [ V_32 ] ) {
V_343 -> V_981 |= 1 << V_32 ;
break;
}
}
}
}
static void F_188 ( struct V_926 * V_343 )
{
T_2 V_32 ;
T_3 V_982 ;
for ( V_32 = 0 ; V_32 < V_343 -> V_928 ; V_32 ++ ) {
V_343 -> V_930 [ V_32 ] . V_934 =
F_186 ( V_343 -> V_930 [ V_32 ] . V_931 , & V_982 ) ?
V_982 : V_343 -> V_930 [ V_32 ] . V_931 ;
}
}
static int F_189 ( const struct V_983 * V_343 ,
struct V_926 * V_984 )
{
T_1 V_32 , V_131 ;
if ( V_343 -> V_928 > V_929 )
return - V_21 ;
if ( V_343 -> V_936 > V_985 )
return - V_21 ;
for ( V_32 = 0 ; V_32 < V_343 -> V_928 ; V_32 ++ )
V_984 -> V_930 [ V_32 ] . V_931 = V_343 -> V_930 [ V_32 ] . V_931 ;
V_984 -> V_928 = V_343 -> V_928 ;
for ( V_32 = 0 ; V_32 < V_343 -> V_936 ; V_32 ++ ) {
V_984 -> V_937 [ V_32 ] . V_986 =
V_343 -> V_937 [ V_32 ] . V_986 ;
for ( V_131 = 0 ; V_131 < V_343 -> V_928 ; V_131 ++ )
V_984 -> V_937 [ V_32 ] . V_938 [ V_131 ] =
V_343 -> V_937 [ V_32 ] . V_938 [ V_131 ] ;
}
V_984 -> V_936 = V_343 -> V_936 ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 ,
struct V_926 * V_343 )
{
T_1 V_32 , V_132 ;
T_2 V_247 ;
bool V_570 ;
V_247 = F_2 ( V_572 ) ;
V_570 = ( ( V_247 & 0x0000f00 ) == 0x300 ) ? true : false ;
if ( V_570 &&
( ( V_2 -> V_46 -> V_47 == 0x67B0 ) ||
( V_2 -> V_46 -> V_47 == 0x67B1 ) ) ) {
for ( V_32 = 0 ; V_32 < V_343 -> V_928 ; V_32 ++ ) {
if ( V_343 -> V_928 >= V_929 )
return - V_21 ;
switch ( V_343 -> V_930 [ V_32 ] . V_931 ) {
case V_932 :
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
if ( ( V_343 -> V_937 [ V_132 ] . V_986 == 125000 ) ||
( V_343 -> V_937 [ V_132 ] . V_986 == 137500 ) )
V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] =
( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xFFFFFFF8 ) |
0x00000007 ;
}
break;
case V_971 :
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
if ( ( V_343 -> V_937 [ V_132 ] . V_986 == 125000 ) ||
( V_343 -> V_937 [ V_132 ] . V_986 == 137500 ) )
V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] =
( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xFFFF0F00 ) |
0x0000D0DD ;
}
break;
case V_973 :
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
if ( ( V_343 -> V_937 [ V_132 ] . V_986 == 125000 ) ||
( V_343 -> V_937 [ V_132 ] . V_986 == 137500 ) )
V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] =
( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xFFFF0F00 ) |
0x0000D0DD ;
}
break;
case V_979 :
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
if ( ( V_343 -> V_937 [ V_132 ] . V_986 == 125000 ) ||
( V_343 -> V_937 [ V_132 ] . V_986 == 137500 ) )
V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] = 0 ;
}
break;
case V_957 :
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
if ( V_343 -> V_937 [ V_132 ] . V_986 == 125000 )
V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] =
( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xFFE0FE0F ) |
0x000C0140 ;
else if ( V_343 -> V_937 [ V_132 ] . V_986 == 137500 )
V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] =
( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xFFE0FE0F ) |
0x000C0150 ;
}
break;
case V_959 :
for ( V_132 = 0 ; V_132 < V_343 -> V_936 ; V_132 ++ ) {
if ( V_343 -> V_937 [ V_132 ] . V_986 == 125000 )
V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] =
( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xFFFFFFE0 ) |
0x00000030 ;
else if ( V_343 -> V_937 [ V_132 ] . V_986 == 137500 )
V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] =
( V_343 -> V_937 [ V_132 ] . V_938 [ V_32 ] & 0xFFFFFFE0 ) |
0x00000035 ;
}
break;
default:
break;
}
}
F_4 ( V_987 , 3 ) ;
V_247 = F_2 ( V_988 ) ;
V_247 = ( V_247 & 0xFFF8FFFF ) | ( 1 << 16 ) ;
F_4 ( V_987 , 3 ) ;
F_4 ( V_988 , V_247 ) ;
}
return 0 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_983 * V_343 ;
struct V_926 * V_984 = & V_37 -> V_989 ;
T_1 V_990 = F_1 ( V_2 ) ;
int V_103 ;
V_343 = F_192 ( sizeof( struct V_983 ) , V_991 ) ;
if ( ! V_343 )
return - V_992 ;
F_4 ( V_948 , F_2 ( V_947 ) ) ;
F_4 ( V_958 , F_2 ( V_957 ) ) ;
F_4 ( V_950 , F_2 ( V_949 ) ) ;
F_4 ( V_952 , F_2 ( V_951 ) ) ;
F_4 ( V_954 , F_2 ( V_953 ) ) ;
F_4 ( V_956 , F_2 ( V_955 ) ) ;
F_4 ( V_964 , F_2 ( V_963 ) ) ;
F_4 ( V_966 , F_2 ( V_965 ) ) ;
F_4 ( V_960 , F_2 ( V_959 ) ) ;
F_4 ( V_962 , F_2 ( V_961 ) ) ;
F_4 ( V_935 , F_2 ( V_933 ) ) ;
F_4 ( V_940 , F_2 ( V_939 ) ) ;
F_4 ( V_944 , F_2 ( V_943 ) ) ;
F_4 ( V_972 , F_2 ( V_971 ) ) ;
F_4 ( V_974 , F_2 ( V_973 ) ) ;
F_4 ( V_968 , F_2 ( V_967 ) ) ;
F_4 ( V_970 , F_2 ( V_969 ) ) ;
F_4 ( V_976 , F_2 ( V_975 ) ) ;
F_4 ( V_978 , F_2 ( V_977 ) ) ;
F_4 ( V_980 , F_2 ( V_979 ) ) ;
V_103 = F_193 ( V_2 , V_990 , V_343 ) ;
if ( V_103 )
goto V_993;
V_103 = F_189 ( V_343 , V_984 ) ;
if ( V_103 )
goto V_993;
F_188 ( V_984 ) ;
V_103 = F_190 ( V_2 , V_984 ) ;
if ( V_103 )
goto V_993;
V_103 = F_185 ( V_2 , V_984 ) ;
if ( V_103 )
goto V_993;
F_187 ( V_984 ) ;
V_993:
F_194 ( V_343 ) ;
return V_103 ;
}
static int F_195 ( struct V_1 * V_2 ,
T_17 * V_989 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_32 , V_131 ;
for ( V_32 = 0 , V_131 = 0 ; V_131 < V_37 -> V_989 . V_928 ; V_131 ++ ) {
if ( V_37 -> V_989 . V_981 & ( 1 << V_131 ) ) {
if ( V_32 >= V_929 )
return - V_21 ;
V_989 -> V_982 [ V_32 ] . V_934 = F_17 ( V_37 -> V_989 . V_930 [ V_131 ] . V_934 ) ;
V_989 -> V_982 [ V_32 ] . V_931 = F_17 ( V_37 -> V_989 . V_930 [ V_131 ] . V_931 ) ;
V_32 ++ ;
}
}
V_989 -> V_928 = ( T_1 ) V_32 ;
return 0 ;
}
static void F_196 ( const struct V_994 * V_995 ,
T_18 * V_161 ,
T_2 V_936 , T_2 V_981 )
{
T_2 V_32 , V_131 ;
for ( V_32 = 0 , V_131 = 0 ; V_131 < V_936 ; V_131 ++ ) {
if ( V_981 & ( 1 << V_131 ) ) {
V_161 -> V_86 [ V_32 ] = F_25 ( V_995 -> V_938 [ V_131 ] ) ;
V_32 ++ ;
}
}
}
static void F_197 ( struct V_1 * V_2 ,
const T_2 V_26 ,
T_18 * V_996 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_32 = 0 ;
for( V_32 = 0 ; V_32 < V_37 -> V_989 . V_936 ; V_32 ++ ) {
if ( V_26 <= V_37 -> V_989 . V_937 [ V_32 ] . V_986 )
break;
}
if ( ( V_32 == V_37 -> V_989 . V_936 ) && ( V_32 > 0 ) )
-- V_32 ;
F_196 ( & V_37 -> V_989 . V_937 [ V_32 ] ,
V_996 , V_37 -> V_989 . V_928 ,
V_37 -> V_989 . V_981 ) ;
}
static void F_198 ( struct V_1 * V_2 ,
T_17 * V_989 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
T_2 V_32 ;
for ( V_32 = 0 ; V_32 < V_37 -> V_126 . V_580 . V_34 ; V_32 ++ )
F_197 ( V_2 ,
V_37 -> V_126 . V_580 . V_581 [ V_32 ] . V_86 ,
& V_989 -> V_161 [ V_32 ] ) ;
}
static int F_199 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 ;
memset ( & V_37 -> V_997 , 0 , sizeof( T_17 ) ) ;
V_103 = F_195 ( V_2 , & V_37 -> V_997 ) ;
if ( V_103 )
return V_103 ;
F_198 ( V_2 , & V_37 -> V_997 ) ;
return F_27 ( V_2 ,
V_37 -> V_427 ,
( T_1 * ) & V_37 -> V_997 ,
sizeof( T_17 ) ,
V_37 -> V_109 ) ;
}
static int F_200 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( ! ( V_37 -> V_376 & V_382 ) )
return 0 ;
memset ( & V_37 -> V_997 , 0 , sizeof( T_17 ) ) ;
F_198 ( V_2 , & V_37 -> V_997 ) ;
return F_27 ( V_2 ,
V_37 -> V_427 +
F_20 ( T_17 , V_161 [ 0 ] ) ,
( T_1 * ) & V_37 -> V_997 . V_161 [ 0 ] ,
sizeof( T_18 ) *
V_37 -> V_126 . V_580 . V_34 ,
V_37 -> V_109 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
T_2 V_247 = F_32 ( V_368 ) ;
V_247 |= V_998 ;
F_33 ( V_368 , V_247 ) ;
}
static enum V_999 F_202 ( struct V_1 * V_2 ,
struct V_42 * V_881 )
{
struct V_41 * V_747 = F_10 ( V_881 ) ;
int V_32 ;
T_3 V_1000 , V_1001 = 0 ;
for ( V_32 = 0 ; V_32 < V_747 -> V_238 ; V_32 ++ ) {
V_1000 = V_747 -> V_239 [ V_32 ] . V_792 ;
if ( V_1001 < V_1000 )
V_1001 = V_1000 ;
}
return V_1001 ;
}
static T_3 F_203 ( struct V_1 * V_2 )
{
T_2 V_1002 = 0 ;
V_1002 = F_204 ( V_1003 ) &
V_1004 ;
V_1002 >>= V_1005 ;
return ( T_3 ) V_1002 ;
}
static int F_205 ( struct V_1 * V_2 )
{
T_2 V_1006 = 0 ;
V_1006 = F_204 ( V_1007 ) &
V_1008 ;
V_1006 >>= V_1009 ;
switch ( V_1006 ) {
case 1 :
return 1 ;
case 2 :
return 2 ;
case 3 :
return 4 ;
case 4 :
return 8 ;
case 0 :
case 6 :
default:
return 16 ;
}
}
static void F_206 ( struct V_1 * V_2 ,
struct V_42 * V_907 ,
struct V_42 * V_908 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
enum V_999 V_1010 =
F_202 ( V_2 , V_907 ) ;
enum V_999 V_1011 ;
if ( V_37 -> V_1012 == V_1013 )
V_1011 = F_202 ( V_2 , V_908 ) ;
else
V_1011 = V_37 -> V_1012 ;
V_37 -> V_1012 = V_1013 ;
V_37 -> V_1014 = false ;
if ( V_1010 > V_1011 ) {
switch ( V_1010 ) {
#ifdef F_207
case V_1015 :
if ( F_208 ( V_2 , V_1016 , false ) == 0 )
break;
V_37 -> V_1012 = V_1017 ;
if ( V_1011 == V_1017 )
break;
case V_1017 :
if ( F_208 ( V_2 , V_1018 , false ) == 0 )
break;
#endif
default:
V_37 -> V_1012 = F_203 ( V_2 ) ;
break;
}
} else {
if ( V_1010 < V_1011 )
V_37 -> V_1014 = true ;
}
}
static void F_209 ( struct V_1 * V_2 ,
struct V_42 * V_907 ,
struct V_42 * V_908 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
enum V_999 V_1010 =
F_202 ( V_2 , V_907 ) ;
T_1 V_1019 ;
if ( V_37 -> V_1014 ) {
if ( V_1010 == V_1015 )
V_1019 = V_1016 ;
else if ( V_1010 == V_1017 )
V_1019 = V_1018 ;
else
V_1019 = V_1020 ;
if ( ( V_1019 == V_1020 ) &&
( F_203 ( V_2 ) > 0 ) )
return;
#ifdef F_207
F_208 ( V_2 , V_1019 , false ) ;
#endif
}
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_516 * V_802 =
& V_2 -> V_38 . V_39 . V_74 . V_76 ;
struct V_516 * V_1021 =
& V_2 -> V_38 . V_39 . V_74 . V_527 ;
struct V_516 * V_1022 =
& V_2 -> V_38 . V_39 . V_74 . V_532 ;
if ( V_802 == NULL )
return - V_21 ;
if ( V_802 -> V_34 < 1 )
return - V_21 ;
if ( V_1021 == NULL )
return - V_21 ;
if ( V_1021 -> V_34 < 1 )
return - V_21 ;
if ( V_1022 == NULL )
return - V_21 ;
if ( V_1022 -> V_34 < 1 )
return - V_21 ;
V_37 -> V_718 = V_802 -> V_35 [ 0 ] . V_520 ;
V_37 -> V_1023 =
V_802 -> V_35 [ V_802 -> V_34 - 1 ] . V_520 ;
V_37 -> V_737 = V_1022 -> V_35 [ 0 ] . V_520 ;
V_37 -> V_1024 =
V_1022 -> V_35 [ V_1022 -> V_34 - 1 ] . V_520 ;
V_2 -> V_38 . V_39 . V_74 . V_236 . V_223 =
V_802 -> V_35 [ V_802 -> V_34 - 1 ] . V_553 ;
V_2 -> V_38 . V_39 . V_74 . V_236 . V_224 =
V_1021 -> V_35 [ V_802 -> V_34 - 1 ] . V_553 ;
V_2 -> V_38 . V_39 . V_74 . V_236 . V_65 =
V_802 -> V_35 [ V_802 -> V_34 - 1 ] . V_520 ;
V_2 -> V_38 . V_39 . V_74 . V_236 . V_353 =
V_1022 -> V_35 [ V_1022 -> V_34 - 1 ] . V_520 ;
return 0 ;
}
static void F_211 ( struct V_1 * V_2 , T_3 * V_65 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_1025 * V_1026 = & V_37 -> V_354 ;
T_2 V_1027 ;
for ( V_1027 = 0 ; V_1027 < V_1026 -> V_34 ; V_1027 ++ ) {
if ( V_1026 -> V_351 [ V_1027 ] == * V_65 ) {
* V_65 = V_1026 -> V_358 [ V_1027 ] ;
break;
}
}
}
static void F_212 ( struct V_1 * V_2 , T_3 * V_353 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_1025 * V_1026 = & V_37 -> V_355 ;
T_2 V_1027 ;
for ( V_1027 = 0 ; V_1027 < V_1026 -> V_34 ; V_1027 ++ ) {
if ( V_1026 -> V_351 [ V_1027 ] == * V_353 ) {
* V_353 = V_1026 -> V_358 [ V_1027 ] ;
break;
}
}
}
static void F_213 ( struct V_1 * V_2 ,
struct V_516 * V_343 )
{
T_2 V_32 ;
if ( V_343 ) {
for ( V_32 = 0 ; V_32 < V_343 -> V_34 ; V_32 ++ )
F_211 ( V_2 , & V_343 -> V_35 [ V_32 ] . V_520 ) ;
}
}
static void F_214 ( struct V_1 * V_2 ,
struct V_516 * V_343 )
{
T_2 V_32 ;
if ( V_343 ) {
for ( V_32 = 0 ; V_32 < V_343 -> V_34 ; V_32 ++ )
F_212 ( V_2 , & V_343 -> V_35 [ V_32 ] . V_520 ) ;
}
}
static void F_215 ( struct V_1 * V_2 ,
struct V_906 * V_343 )
{
T_2 V_32 ;
if ( V_343 ) {
for ( V_32 = 0 ; V_32 < V_343 -> V_34 ; V_32 ++ )
F_211 ( V_2 , & V_343 -> V_35 [ V_32 ] . V_520 ) ;
}
}
static void F_216 ( struct V_1 * V_2 ,
struct V_1028 * V_343 )
{
T_2 V_32 ;
if ( V_343 ) {
for ( V_32 = 0 ; V_32 < V_343 -> V_34 ; V_32 ++ )
F_211 ( V_2 , & V_343 -> V_35 [ V_32 ] . V_520 ) ;
}
}
static void F_217 ( struct V_1 * V_2 ,
struct V_559 * V_343 )
{
T_2 V_32 ;
if ( V_343 ) {
for ( V_32 = 0 ; V_32 < V_343 -> V_34 ; V_32 ++ )
F_211 ( V_2 , & V_343 -> V_35 [ V_32 ] . V_551 ) ;
}
}
static void F_218 ( struct V_1 * V_2 ,
struct V_220 * V_343 )
{
if ( V_343 ) {
F_211 ( V_2 , ( T_3 * ) & V_343 -> V_65 ) ;
F_212 ( V_2 , ( T_3 * ) & V_343 -> V_353 ) ;
}
}
static void F_219 ( struct V_1 * V_2 ,
struct V_804 * V_343 )
{
T_2 V_32 ;
if ( V_343 ) {
for ( V_32 = 0 ; V_32 < V_343 -> V_34 ; V_32 ++ )
F_211 ( V_2 , & V_343 -> V_35 [ V_32 ] . V_65 ) ;
}
}
static void F_220 ( struct V_1 * V_2 )
{
F_213 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_76 ) ;
F_213 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_527 ) ;
F_213 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_885 ) ;
F_214 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_532 ) ;
F_215 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_618 ) ;
F_216 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_605 ) ;
F_213 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_628 ) ;
F_213 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_625 ) ;
F_217 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_685 ) ;
F_218 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_236 ) ;
F_218 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_237 ) ;
F_219 ( V_2 ,
& V_2 -> V_38 . V_39 . V_74 . V_75 ) ;
}
static void F_221 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_41 * V_1029 = F_10 ( V_43 ) ;
struct V_36 * V_37 = F_9 ( V_2 ) ;
V_37 -> V_1030 = * V_43 ;
V_37 -> V_1031 = * V_1029 ;
V_37 -> V_1030 . V_45 = & V_37 -> V_1031 ;
V_2 -> V_38 . V_39 . V_1031 = & V_37 -> V_1030 ;
}
static void F_222 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_41 * V_1029 = F_10 ( V_43 ) ;
struct V_36 * V_37 = F_9 ( V_2 ) ;
V_37 -> V_1032 = * V_43 ;
V_37 -> V_1033 = * V_1029 ;
V_37 -> V_1032 . V_45 = & V_37 -> V_1033 ;
V_2 -> V_38 . V_39 . V_1033 = & V_37 -> V_1032 ;
}
static int F_223 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_42 V_1033 = * V_2 -> V_38 . V_39 . V_1033 ;
struct V_42 * V_1029 = & V_1033 ;
F_222 ( V_2 , V_1029 ) ;
F_48 ( V_2 , & V_37 -> V_1032 ) ;
return 0 ;
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_42 * V_1029 = & V_37 -> V_1032 ;
F_221 ( V_2 , V_1029 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
F_102 ( V_2 ) ;
F_105 ( V_2 ) ;
F_103 ( V_2 ) ;
}
static int F_226 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_42 * V_822 = V_2 -> V_38 . V_39 . V_822 ;
int V_103 ;
if ( V_37 -> V_522 != V_552 ) {
F_201 ( V_2 ) ;
V_103 = F_119 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_6 ) ;
return V_103 ;
}
}
if ( V_37 -> V_1034 ) {
V_103 = F_191 ( V_2 ) ;
if ( V_103 )
V_37 -> V_1034 = false ;
}
if ( V_37 -> V_1035 )
F_109 ( V_2 , true ) ;
if ( V_37 -> V_369 )
F_104 ( V_2 , true ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
V_103 = F_114 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_7 ) ;
return V_103 ;
}
V_103 = F_101 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_8 ) ;
return V_103 ;
}
V_103 = F_133 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_9 ) ;
return V_103 ;
}
V_103 = F_170 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_10 ) ;
return V_103 ;
}
V_103 = F_130 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_11 ) ;
return V_103 ;
}
if ( V_37 -> V_1034 ) {
V_103 = F_199 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_12 ) ;
return V_103 ;
}
}
V_103 = F_26 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_13 ) ;
return V_103 ;
}
F_94 ( V_2 ) ;
F_80 ( V_2 ) ;
V_103 = F_106 ( V_2 , false ) ;
if ( V_103 ) {
F_50 ( L_14 ) ;
return V_103 ;
}
F_87 ( V_2 , true ) ;
V_103 = F_155 ( V_2 , true ) ;
if ( V_103 ) {
F_50 ( L_15 ) ;
return V_103 ;
}
V_103 = F_107 ( V_2 , true ) ;
if ( V_103 ) {
F_50 ( L_16 ) ;
return V_103 ;
}
V_103 = F_84 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_17 ) ;
return V_103 ;
}
V_103 = F_34 ( V_2 , true ) ;
if ( V_103 ) {
F_50 ( L_18 ) ;
return V_103 ;
}
V_103 = F_38 ( V_2 , true ) ;
if ( V_103 ) {
F_50 ( L_19 ) ;
return V_103 ;
}
V_103 = F_35 ( V_2 , true ) ;
if ( V_103 ) {
F_50 ( L_20 ) ;
return V_103 ;
}
V_103 = F_40 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_21 ) ;
return V_103 ;
}
F_79 ( V_2 , V_363 , true ) ;
V_103 = F_39 ( V_2 , true ) ;
if ( V_103 ) {
F_50 ( L_22 ) ;
return V_103 ;
}
F_67 ( V_2 ) ;
F_221 ( V_2 , V_822 ) ;
return 0 ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_42 * V_822 = V_2 -> V_38 . V_39 . V_822 ;
F_228 ( V_2 , & V_2 -> V_38 . V_39 . V_253 . V_1036 ,
V_1037 ) ;
F_228 ( V_2 , & V_2 -> V_38 . V_39 . V_253 . V_1036 ,
V_1038 ) ;
F_42 ( V_2 , true ) ;
if ( ! F_115 ( V_2 ) )
return;
F_68 ( V_2 ) ;
if ( V_37 -> V_369 )
F_104 ( V_2 , false ) ;
F_35 ( V_2 , false ) ;
F_38 ( V_2 , false ) ;
F_34 ( V_2 , false ) ;
F_109 ( V_2 , false ) ;
F_79 ( V_2 , V_363 , false ) ;
F_86 ( V_2 ) ;
F_107 ( V_2 , false ) ;
F_155 ( V_2 , false ) ;
F_113 ( V_2 ) ;
F_134 ( V_2 ) ;
F_98 ( V_2 ) ;
F_135 ( V_2 ) ;
F_39 ( V_2 , false ) ;
F_221 ( V_2 , V_822 ) ;
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_42 * V_1029 = & V_37 -> V_1032 ;
struct V_42 * V_1039 = & V_37 -> V_1030 ;
int V_103 ;
F_176 ( V_2 , V_1029 ) ;
if ( V_37 -> V_1040 )
F_206 ( V_2 , V_1029 , V_1039 ) ;
V_103 = F_85 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_23 ) ;
return V_103 ;
}
V_103 = F_177 ( V_2 , V_1029 ) ;
if ( V_103 ) {
F_50 ( L_24 ) ;
return V_103 ;
}
V_103 = F_182 ( V_2 , V_1029 ) ;
if ( V_103 ) {
F_50 ( L_25 ) ;
return V_103 ;
}
V_103 = F_181 ( V_2 , V_1029 , V_1039 ) ;
if ( V_103 ) {
F_50 ( L_26 ) ;
return V_103 ;
}
V_103 = F_73 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_27 ) ;
return V_103 ;
}
if ( V_37 -> V_1034 ) {
V_103 = F_200 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_28 ) ;
return V_103 ;
}
}
V_103 = F_140 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_29 ) ;
return V_103 ;
}
V_103 = F_81 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_30 ) ;
return V_103 ;
}
V_103 = F_175 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_31 ) ;
return V_103 ;
}
if ( V_37 -> V_1040 )
F_209 ( V_2 , V_1029 , V_1039 ) ;
return 0 ;
}
static void F_230 ( struct V_1 * V_2 )
{
F_108 ( V_2 ) ;
}
static void F_231 ( struct V_1 * V_2 ,
struct V_42 * V_43 ,
struct V_1041 * V_1042 ,
T_1 V_1043 )
{
V_43 -> V_1044 = F_232 ( V_1042 -> V_1045 ) ;
V_43 -> V_231 = F_233 ( V_1042 -> V_1046 ) ;
V_43 -> V_1047 = F_233 ( V_1042 -> V_1048 ) ;
if ( V_1049 < V_1043 ) {
V_43 -> V_608 = F_232 ( V_1042 -> V_1050 ) ;
V_43 -> V_610 = F_232 ( V_1042 -> V_1051 ) ;
} else {
V_43 -> V_608 = 0 ;
V_43 -> V_610 = 0 ;
}
if ( V_43 -> V_231 & V_1052 )
V_2 -> V_38 . V_39 . V_822 = V_43 ;
if ( V_43 -> V_231 & V_1053 )
V_2 -> V_38 . V_39 . V_1054 = V_43 ;
}
static void F_234 ( struct V_1 * V_2 ,
struct V_42 * V_43 , int V_791 ,
union V_1055 * V_1056 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_41 * V_44 = F_10 ( V_43 ) ;
struct V_1057 * V_1058 = & V_44 -> V_239 [ V_791 ] ;
V_44 -> V_238 = V_791 + 1 ;
V_1058 -> V_223 = F_233 ( V_1056 -> V_1059 . V_1060 ) ;
V_1058 -> V_223 |= V_1056 -> V_1059 . V_1061 << 16 ;
V_1058 -> V_224 = F_233 ( V_1056 -> V_1059 . V_1062 ) ;
V_1058 -> V_224 |= V_1056 -> V_1059 . V_1063 << 16 ;
V_1058 -> V_792 = F_235 ( V_2 ,
V_37 -> V_1064 ,
V_37 -> V_836 . V_1065 ,
V_1056 -> V_1059 . V_1066 ) ;
V_1058 -> V_883 = F_236 ( V_2 ,
V_37 -> V_836 . V_1067 ,
F_233 ( V_1056 -> V_1059 . V_1068 ) ) ;
if ( V_43 -> V_231 & V_1069 ) {
V_37 -> V_1070 = V_1058 -> V_792 ;
}
if ( V_43 -> V_1047 & V_1071 ) {
V_37 -> V_743 . V_744 = true ;
V_37 -> V_743 . V_1058 = * V_1058 ;
V_37 -> V_743 . V_831 = V_1072 ;
}
if ( V_43 -> V_231 & V_1052 ) {
V_1058 -> V_224 = V_37 -> V_836 . V_838 ;
V_1058 -> V_223 = V_37 -> V_836 . V_837 ;
V_1058 -> V_792 = V_37 -> V_836 . V_1065 ;
V_1058 -> V_883 = V_37 -> V_836 . V_1067 ;
}
switch ( V_43 -> V_231 & V_232 ) {
case V_233 :
V_37 -> V_795 = true ;
if ( V_37 -> V_796 . V_116 < V_1058 -> V_792 )
V_37 -> V_796 . V_116 = V_1058 -> V_792 ;
if ( V_37 -> V_796 . V_115 > V_1058 -> V_792 )
V_37 -> V_796 . V_115 = V_1058 -> V_792 ;
if ( V_37 -> V_798 . V_116 < V_1058 -> V_883 )
V_37 -> V_798 . V_116 = V_1058 -> V_883 ;
if ( V_37 -> V_798 . V_115 > V_1058 -> V_883 )
V_37 -> V_798 . V_115 = V_1058 -> V_883 ;
break;
case V_1073 :
V_37 -> V_794 = true ;
if ( V_37 -> V_797 . V_116 < V_1058 -> V_792 )
V_37 -> V_797 . V_116 = V_1058 -> V_792 ;
if ( V_37 -> V_797 . V_115 > V_1058 -> V_792 )
V_37 -> V_797 . V_115 = V_1058 -> V_792 ;
if ( V_37 -> V_799 . V_116 < V_1058 -> V_883 )
V_37 -> V_799 . V_116 = V_1058 -> V_883 ;
if ( V_37 -> V_799 . V_115 > V_1058 -> V_883 )
V_37 -> V_799 . V_115 = V_1058 -> V_883 ;
break;
default:
break;
}
}
static int F_237 ( struct V_1 * V_2 )
{
struct V_1074 * V_1075 = & V_2 -> V_1075 ;
struct V_1041 * V_1042 ;
union V_1076 * V_1077 ;
int V_32 , V_131 , V_132 , V_1078 , V_1079 ;
union V_1055 * V_1056 ;
struct V_1080 * V_1081 ;
struct V_1082 * V_1083 ;
struct V_1084 * V_1085 ;
union V_1086 * V_1086 ;
int V_791 = F_238 ( V_1087 , V_1088 ) ;
T_3 V_1089 ;
T_1 V_1090 , V_1091 ;
T_1 * V_1092 ;
struct V_41 * V_44 ;
if ( ! F_239 ( V_1075 -> V_1093 , V_791 , NULL ,
& V_1090 , & V_1091 , & V_1089 ) )
return - V_21 ;
V_1086 = (union V_1086 * ) ( V_1075 -> V_1093 -> V_1094 + V_1089 ) ;
F_240 ( V_2 ) ;
V_1081 = (struct V_1080 * )
( V_1075 -> V_1093 -> V_1094 + V_1089 +
F_233 ( V_1086 -> V_1095 . V_1096 ) ) ;
V_1083 = (struct V_1082 * )
( V_1075 -> V_1093 -> V_1094 + V_1089 +
F_233 ( V_1086 -> V_1095 . V_1097 ) ) ;
V_1085 = (struct V_1084 * )
( V_1075 -> V_1093 -> V_1094 + V_1089 +
F_233 ( V_1086 -> V_1095 . V_1098 ) ) ;
V_2 -> V_38 . V_39 . V_44 = F_192 ( sizeof( struct V_42 ) *
V_1081 -> V_1099 , V_991 ) ;
if ( ! V_2 -> V_38 . V_39 . V_44 )
return - V_992 ;
V_1092 = ( T_1 * ) V_1081 -> V_1100 ;
for ( V_32 = 0 ; V_32 < V_1081 -> V_1099 ; V_32 ++ ) {
T_1 * V_557 ;
V_1077 = (union V_1076 * ) V_1092 ;
V_1078 = V_1077 -> V_1101 . V_1102 ;
V_1042 = (struct V_1041 * )
& V_1085 -> V_1103 [ V_1078 ] ;
V_44 = F_192 ( sizeof( struct V_41 ) , V_991 ) ;
if ( V_44 == NULL ) {
F_194 ( V_2 -> V_38 . V_39 . V_44 ) ;
return - V_992 ;
}
V_2 -> V_38 . V_39 . V_44 [ V_32 ] . V_45 = V_44 ;
F_231 ( V_2 , & V_2 -> V_38 . V_39 . V_44 [ V_32 ] ,
V_1042 ,
V_1085 -> V_1104 ) ;
V_132 = 0 ;
V_557 = ( T_1 * ) & V_1077 -> V_1101 . V_1105 [ 0 ] ;
for ( V_131 = 0 ; V_131 < V_1077 -> V_1101 . V_1106 ; V_131 ++ ) {
V_1079 = V_557 [ V_131 ] ;
if ( V_1079 >= V_1083 -> V_1099 )
continue;
if ( V_132 >= V_1107 )
break;
V_1056 = (union V_1055 * )
( ( T_1 * ) & V_1083 -> V_1108 [ 0 ] +
( V_1079 * V_1083 -> V_1104 ) ) ;
F_234 ( V_2 ,
& V_2 -> V_38 . V_39 . V_44 [ V_32 ] , V_132 ,
V_1056 ) ;
V_132 ++ ;
}
V_1092 += 2 + V_1077 -> V_1101 . V_1106 ;
}
V_2 -> V_38 . V_39 . V_1109 = V_1081 -> V_1099 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_38 . V_39 . V_1110 ; V_32 ++ ) {
T_2 V_223 , V_224 ;
V_1079 = V_2 -> V_38 . V_39 . V_227 [ V_32 ] . V_1111 ;
V_1056 = (union V_1055 * )
& V_1083 -> V_1108 [ V_1079 * V_1083 -> V_1104 ] ;
V_223 = F_233 ( V_1056 -> V_1059 . V_1060 ) ;
V_223 |= V_1056 -> V_1059 . V_1061 << 16 ;
V_224 = F_233 ( V_1056 -> V_1059 . V_1062 ) ;
V_224 |= V_1056 -> V_1059 . V_1063 << 16 ;
V_2 -> V_38 . V_39 . V_227 [ V_32 ] . V_223 = V_223 ;
V_2 -> V_38 . V_39 . V_227 [ V_32 ] . V_224 = V_224 ;
}
return 0 ;
}
static int F_241 ( struct V_1 * V_2 ,
struct V_1112 * V_583 )
{
struct V_1074 * V_1075 = & V_2 -> V_1075 ;
int V_791 = F_238 ( V_1087 , V_1113 ) ;
T_19 * V_1114 ;
T_1 V_1090 , V_1091 ;
T_3 V_1089 ;
if ( F_239 ( V_1075 -> V_1093 , V_791 , NULL ,
& V_1090 , & V_1091 , & V_1089 ) ) {
V_1114 =
( T_19 * ) ( V_1075 -> V_1093 -> V_1094 +
V_1089 ) ;
V_583 -> V_844 = F_233 ( V_1114 -> V_1115 ) ;
V_583 -> V_840 = F_233 ( V_1114 -> V_1116 ) ;
V_583 -> V_842 = F_233 ( V_1114 -> V_1117 ) ;
V_583 -> V_1065 = F_203 ( V_2 ) ;
V_583 -> V_1067 = F_205 ( V_2 ) ;
V_583 -> V_837 = F_232 ( V_1114 -> V_1118 ) ;
V_583 -> V_838 = F_232 ( V_1114 -> V_1119 ) ;
return 0 ;
}
return - V_21 ;
}
static void F_242 ( struct V_1 * V_2 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_38 . V_39 . V_1109 ; V_32 ++ ) {
F_194 ( V_2 -> V_38 . V_39 . V_44 [ V_32 ] . V_45 ) ;
}
F_194 ( V_2 -> V_38 . V_39 . V_44 ) ;
F_194 ( V_2 -> V_38 . V_39 . V_40 ) ;
F_194 ( V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 ) ;
F_243 ( V_2 ) ;
}
static int F_244 ( struct V_1 * V_2 )
{
const char * V_1120 ;
char V_1121 [ 30 ] ;
int V_1122 ;
F_245 ( L_32 ) ;
switch ( V_2 -> V_60 ) {
case V_801 :
if ( ( V_2 -> V_46 -> V_1123 == 0x80 ) ||
( V_2 -> V_46 -> V_1123 == 0x81 ) ||
( V_2 -> V_46 -> V_47 == 0x665f ) )
V_1120 = L_33 ;
else
V_1120 = L_34 ;
break;
case V_61 :
if ( V_2 -> V_46 -> V_1123 == 0x80 )
V_1120 = L_35 ;
else
V_1120 = L_36 ;
break;
case V_1124 :
case V_1125 :
case V_1126 :
default: F_246 () ;
}
snprintf ( V_1121 , sizeof( V_1121 ) , L_37 , V_1120 ) ;
V_1122 = F_247 ( & V_2 -> V_38 . V_1127 , V_1121 , V_2 -> V_1128 ) ;
if ( V_1122 )
goto V_1129;
V_1122 = F_248 ( V_2 -> V_38 . V_1127 ) ;
V_1129:
if ( V_1122 ) {
F_249 ( L_38 , V_1121 ) ;
F_250 ( V_2 -> V_38 . V_1127 ) ;
V_2 -> V_38 . V_1127 = NULL ;
}
return V_1122 ;
}
static int F_251 ( struct V_1 * V_2 )
{
int V_791 = F_238 ( V_1087 , V_1130 ) ;
T_4 * V_126 ;
struct V_1131 V_1132 ;
T_3 V_1089 , V_1133 ;
T_1 V_1090 , V_1091 ;
struct V_36 * V_37 ;
int V_103 ;
V_37 = F_192 ( sizeof( struct V_36 ) , V_991 ) ;
if ( V_37 == NULL )
return - V_992 ;
V_2 -> V_38 . V_39 . V_40 = V_37 ;
V_37 -> V_1064 =
( V_2 -> V_38 . V_1134 & V_1135 ) >>
V_1136 ;
V_37 -> V_1012 = V_1013 ;
V_37 -> V_797 . V_116 = V_1137 ;
V_37 -> V_797 . V_115 = V_1015 ;
V_37 -> V_796 . V_116 = V_1137 ;
V_37 -> V_796 . V_115 = V_1015 ;
V_37 -> V_799 . V_116 = 0 ;
V_37 -> V_799 . V_115 = 16 ;
V_37 -> V_798 . V_116 = 0 ;
V_37 -> V_798 . V_115 = 16 ;
V_103 = F_241 ( V_2 , & V_37 -> V_836 ) ;
if ( V_103 ) {
F_242 ( V_2 ) ;
return V_103 ;
}
V_103 = F_252 ( V_2 ) ;
if ( V_103 ) {
F_242 ( V_2 ) ;
return V_103 ;
}
V_103 = F_253 ( V_2 ) ;
if ( V_103 ) {
F_242 ( V_2 ) ;
return V_103 ;
}
V_103 = F_237 ( V_2 ) ;
if ( V_103 ) {
F_242 ( V_2 ) ;
return V_103 ;
}
V_37 -> V_710 = false ;
V_37 -> V_109 = V_515 ;
V_37 -> V_781 [ 0 ] = V_1138 ;
V_37 -> V_781 [ 1 ] = V_1138 ;
V_37 -> V_781 [ 2 ] = V_1138 ;
V_37 -> V_781 [ 3 ] = V_1138 ;
V_37 -> V_781 [ 4 ] = V_1138 ;
V_37 -> V_781 [ 5 ] = V_1138 ;
V_37 -> V_781 [ 6 ] = V_1138 ;
V_37 -> V_781 [ 7 ] = V_1138 ;
V_37 -> V_691 = V_1139 ;
V_37 -> V_377 = 0 ;
V_37 -> V_381 = 0 ;
V_37 -> V_401 = 0 ;
V_37 -> V_203 = 0 ;
if ( V_1140 & V_1141 )
V_37 -> V_466 = true ;
else
V_37 -> V_466 = false ;
V_37 -> V_703 = 40000 ;
V_37 -> V_699 = 40000 ;
V_37 -> V_705 = 40000 ;
V_37 -> V_706 = 40000 ;
F_11 ( V_2 ) ;
V_37 -> V_344 = false ;
V_37 -> V_348 = false ;
V_37 -> V_892 = true ;
V_37 -> V_898 = true ;
F_74 ( V_2 ) ;
F_220 ( V_2 ) ;
F_210 ( V_2 ) ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 =
F_192 ( 4 * sizeof( struct V_1142 ) , V_991 ) ;
if ( ! V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 ) {
F_242 ( V_2 ) ;
return - V_992 ;
}
V_2 -> V_38 . V_39 . V_74 . V_885 . V_34 = 4 ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 [ 0 ] . V_553 = 0 ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 [ 0 ] . V_520 = 0 ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 [ 1 ] . V_553 = 36000 ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 [ 1 ] . V_520 = 720 ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 [ 2 ] . V_553 = 54000 ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 [ 2 ] . V_520 = 810 ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 [ 3 ] . V_553 = 72000 ;
V_2 -> V_38 . V_39 . V_74 . V_885 . V_35 [ 3 ] . V_520 = 900 ;
V_2 -> V_38 . V_39 . V_74 . V_1143 = 4 ;
V_2 -> V_38 . V_39 . V_74 . V_1144 = 15000 ;
V_2 -> V_38 . V_39 . V_74 . V_1145 = 200 ;
V_2 -> V_38 . V_39 . V_74 . V_1146 . V_34 = 0 ;
V_2 -> V_38 . V_39 . V_74 . V_1146 . V_1147 = NULL ;
V_2 -> V_38 . V_39 . V_74 . V_1148 . V_34 = 0 ;
V_2 -> V_38 . V_39 . V_74 . V_1148 . V_1147 = NULL ;
if ( V_2 -> V_60 == V_61 ) {
V_37 -> V_141 . V_857 = 94500 ;
V_37 -> V_141 . V_142 = 95000 ;
V_37 -> V_141 . V_1149 = 104000 ;
} else {
V_37 -> V_141 . V_857 = 99500 ;
V_37 -> V_141 . V_142 = 100000 ;
V_37 -> V_141 . V_1149 = 104000 ;
}
V_37 -> V_700 = false ;
V_126 = & V_37 -> V_127 ;
V_1132 = F_254 ( V_2 , V_1150 ) ;
if ( V_1132 . V_1151 ) {
V_126 -> V_1152 = V_1132 . V_176 ;
V_2 -> V_38 . V_39 . V_77 |= V_374 ;
} else {
V_126 -> V_1152 = V_1153 ;
V_2 -> V_38 . V_39 . V_77 &= ~ V_374 ;
}
V_1132 = F_254 ( V_2 , V_1154 ) ;
if ( V_1132 . V_1151 ) {
V_126 -> V_1155 = V_1132 . V_176 ;
V_2 -> V_38 . V_39 . V_77 |= V_823 ;
} else {
V_126 -> V_1155 = V_1153 ;
V_2 -> V_38 . V_39 . V_77 &= ~ V_823 ;
}
V_1132 = F_254 ( V_2 , V_1156 ) ;
if ( V_1132 . V_1151 ) {
T_2 V_247 = F_32 ( V_1157 ) ;
switch ( V_1132 . V_176 ) {
case 0 :
V_247 &= ~ V_1158 ;
V_247 |= 1 << V_1159 ;
break;
case 1 :
V_247 &= ~ V_1158 ;
V_247 |= 2 << V_1159 ;
break;
case 2 :
V_247 |= V_1160 ;
break;
case 3 :
V_247 |= V_1161 ;
break;
case 4 :
V_247 |= V_1162 ;
break;
default:
F_116 ( L_39 , V_1132 . V_176 ) ;
break;
}
F_33 ( V_1157 , V_247 ) ;
}
V_37 -> V_522 = V_552 ;
V_37 -> V_529 = V_552 ;
V_37 -> V_534 = V_552 ;
if ( F_255 ( V_2 , V_524 , V_525 ) )
V_37 -> V_522 = V_523 ;
else if ( F_255 ( V_2 , V_524 , V_1163 ) )
V_37 -> V_522 = V_526 ;
if ( V_2 -> V_38 . V_39 . V_77 & V_1164 ) {
if ( F_255 ( V_2 , V_530 , V_525 ) )
V_37 -> V_529 = V_523 ;
else if ( F_255 ( V_2 , V_530 , V_1163 ) )
V_37 -> V_529 = V_526 ;
else
V_2 -> V_38 . V_39 . V_77 &= ~ V_1164 ;
}
if ( V_2 -> V_38 . V_39 . V_77 & V_1165 ) {
if ( F_255 ( V_2 , V_535 , V_525 ) )
V_37 -> V_534 = V_523 ;
else if ( F_255 ( V_2 , V_535 , V_1163 ) )
V_37 -> V_534 = V_526 ;
else
V_2 -> V_38 . V_39 . V_77 &= ~ V_1165 ;
}
V_37 -> V_684 = true ;
#if F_256 ( F_207 )
V_37 -> V_1040 =
F_257 ( V_2 ) ;
#else
V_37 -> V_1040 = false ;
#endif
if ( F_239 ( V_2 -> V_1075 . V_1093 , V_791 , & V_1133 ,
& V_1090 , & V_1091 , & V_1089 ) ) {
V_37 -> V_483 = true ;
V_37 -> V_651 = true ;
V_37 -> V_1035 = true ;
} else {
V_37 -> V_483 = false ;
V_37 -> V_651 = false ;
V_37 -> V_1035 = true ;
}
if ( V_2 -> V_38 . V_1166 != V_1167 )
V_37 -> V_369 = true ;
else
V_37 -> V_369 = false ;
V_37 -> V_1034 = true ;
V_37 -> V_211 = true ;
if ( ( V_2 -> V_38 . V_39 . V_74 . V_237 . V_223 == 0 ) ||
( V_2 -> V_38 . V_39 . V_74 . V_237 . V_224 == 0 ) )
V_2 -> V_38 . V_39 . V_74 . V_237 =
V_2 -> V_38 . V_39 . V_74 . V_236 ;
V_37 -> V_261 = true ;
return 0 ;
}
static void
F_258 ( struct V_1 * V_2 ,
struct V_1168 * V_1169 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_42 * V_43 = & V_37 -> V_1030 ;
T_2 V_223 = F_92 ( V_2 ) ;
T_2 V_224 = F_93 ( V_2 ) ;
T_2 V_1170 = 50 ;
int V_103 ;
V_103 = F_69 ( V_2 , F_20 ( V_396 , V_1171 ) ,
& V_1170 ) ;
if ( V_103 == 0 ) {
V_1170 += 0x80 ;
V_1170 >>= 8 ;
V_1170 = V_1170 > 100 ? 100 : V_1170 ;
}
F_259 ( V_1169 , L_40 , V_37 -> V_211 ? L_41 : L_42 ) ;
F_259 ( V_1169 , L_43 , V_43 -> V_225 ? L_42 : L_41 ) ;
F_259 ( V_1169 , L_44 ,
V_223 , V_224 ) ;
F_259 ( V_1169 , L_45 , V_1170 ) ;
}
static void F_260 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_41 * V_44 = F_10 ( V_43 ) ;
struct V_1057 * V_1058 ;
int V_32 ;
F_261 ( V_43 -> V_231 , V_43 -> V_1047 ) ;
F_262 ( V_43 -> V_1044 ) ;
F_263 ( L_46 , V_43 -> V_608 , V_43 -> V_610 ) ;
for ( V_32 = 0 ; V_32 < V_44 -> V_238 ; V_32 ++ ) {
V_1058 = & V_44 -> V_239 [ V_32 ] ;
F_263 ( L_47 ,
V_32 , V_1058 -> V_223 , V_1058 -> V_224 , V_1058 -> V_792 + 1 , V_1058 -> V_883 ) ;
}
F_264 ( V_2 , V_43 ) ;
}
static inline bool F_265 ( const struct V_1057 * V_1172 ,
const struct V_1057 * V_1173 )
{
return ( ( V_1172 -> V_224 == V_1173 -> V_224 ) &&
( V_1172 -> V_223 == V_1173 -> V_223 ) &&
( V_1172 -> V_792 == V_1173 -> V_792 ) &&
( V_1172 -> V_883 == V_1173 -> V_883 ) ) ;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_42 * V_1174 ,
struct V_42 * V_43 ,
bool * V_1175 )
{
struct V_41 * V_1176 ;
struct V_41 * V_1177 ;
int V_32 ;
if ( V_2 == NULL || V_1174 == NULL || V_43 == NULL || V_1175 == NULL )
return - V_21 ;
V_1176 = F_10 ( V_1174 ) ;
V_1177 = F_10 ( V_43 ) ;
if ( V_1176 == NULL ) {
* V_1175 = false ;
return 0 ;
}
if ( V_1176 -> V_238 != V_1177 -> V_238 ) {
* V_1175 = false ;
return 0 ;
}
for ( V_32 = 0 ; V_32 < V_1176 -> V_238 ; V_32 ++ ) {
if ( ! F_265 ( & ( V_1176 -> V_239 [ V_32 ] ) ,
& ( V_1177 -> V_239 [ V_32 ] ) ) ) {
* V_1175 = false ;
return 0 ;
}
}
* V_1175 = ( ( V_1174 -> V_608 == V_43 -> V_608 ) && ( V_1174 -> V_610 == V_43 -> V_610 ) ) ;
* V_1175 &= ( ( V_1174 -> V_226 == V_43 -> V_226 ) && ( V_1174 -> V_229 == V_43 -> V_229 ) ) ;
return 0 ;
}
static T_2 F_267 ( struct V_1 * V_2 , bool V_1178 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_41 * V_1179 = F_10 ( & V_37 -> V_1032 ) ;
if ( V_1178 )
return V_1179 -> V_239 [ 0 ] . V_223 ;
else
return V_1179 -> V_239 [ V_1179 -> V_238 - 1 ] . V_223 ;
}
static T_2 F_268 ( struct V_1 * V_2 , bool V_1178 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_41 * V_1179 = F_10 ( & V_37 -> V_1032 ) ;
if ( V_1178 )
return V_1179 -> V_239 [ 0 ] . V_224 ;
else
return V_1179 -> V_239 [ V_1179 -> V_238 - 1 ] . V_224 ;
}
static int F_269 ( struct V_1 * V_2 )
{
T_2 V_1180 ;
int V_1181 = 0 ;
V_1180 = ( F_32 ( V_1182 ) & V_1183 ) >>
V_1184 ;
if ( V_1180 & 0x200 )
V_1181 = 255 ;
else
V_1181 = V_1180 & 0x1ff ;
V_1181 = V_1181 * 1000 ;
return V_1181 ;
}
static int F_270 ( struct V_1 * V_2 )
{
int V_103 ;
V_103 = F_51 ( V_2 , false ) ;
if ( V_103 )
return V_103 ;
V_103 = F_49 ( V_2 , V_339 ,
V_340 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_51 ( V_2 , true ) ;
if ( V_103 )
return V_103 ;
return V_103 ;
}
static int F_271 ( void * V_1185 )
{
struct V_1 * V_2 = (struct V_1 * ) V_1185 ;
F_272 ( V_2 ) ;
F_273 ( V_2 ) ;
return 0 ;
}
static int F_274 ( void * V_1185 )
{
int V_103 ;
struct V_1 * V_2 = (struct V_1 * ) V_1185 ;
if ( ! V_1186 )
return 0 ;
V_103 = F_275 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_270 ( V_2 ) ;
if ( V_103 )
return V_103 ;
return 0 ;
}
static int F_276 ( void * V_1185 )
{
int V_103 ;
struct V_1 * V_2 = (struct V_1 * ) V_1185 ;
V_103 = F_277 ( V_2 , V_1187 , 230 ,
& V_2 -> V_38 . V_39 . V_253 . V_1036 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_277 ( V_2 , V_1187 , 231 ,
& V_2 -> V_38 . V_39 . V_253 . V_1036 ) ;
if ( V_103 )
return V_103 ;
V_2 -> V_38 . V_39 . V_747 = V_1188 ;
V_2 -> V_38 . V_39 . V_1189 = V_1188 ;
V_2 -> V_38 . V_39 . V_925 = V_923 ;
V_2 -> V_38 . V_1190 = V_2 -> clock . V_1190 ;
V_2 -> V_38 . V_1191 = V_2 -> clock . V_1191 ;
V_2 -> V_38 . V_1192 = V_2 -> clock . V_1190 ;
V_2 -> V_38 . V_1193 = V_2 -> clock . V_1191 ;
V_2 -> V_38 . V_1166 = V_1167 ;
V_103 = F_244 ( V_2 ) ;
if ( V_103 )
return V_103 ;
if ( V_1186 == 0 )
return 0 ;
F_278 ( & V_2 -> V_38 . V_39 . V_253 . V_1194 , V_1195 ) ;
F_279 ( & V_2 -> V_38 . V_1196 ) ;
V_103 = F_251 ( V_2 ) ;
if ( V_103 )
goto V_1197;
V_2 -> V_38 . V_39 . V_1031 = V_2 -> V_38 . V_39 . V_1033 = V_2 -> V_38 . V_39 . V_822 ;
if ( V_1186 == 1 )
F_280 ( V_2 ) ;
F_281 ( & V_2 -> V_38 . V_1196 ) ;
F_116 ( L_48 ) ;
return 0 ;
V_1197:
F_242 ( V_2 ) ;
F_281 ( & V_2 -> V_38 . V_1196 ) ;
F_50 ( L_49 ) ;
return V_103 ;
}
static int F_282 ( void * V_1185 )
{
struct V_1 * V_2 = (struct V_1 * ) V_1185 ;
F_283 ( & V_2 -> V_38 . V_39 . V_253 . V_1194 ) ;
F_279 ( & V_2 -> V_38 . V_1196 ) ;
F_284 ( V_2 ) ;
F_242 ( V_2 ) ;
F_281 ( & V_2 -> V_38 . V_1196 ) ;
F_250 ( V_2 -> V_38 . V_1127 ) ;
V_2 -> V_38 . V_1127 = NULL ;
return 0 ;
}
static int F_285 ( void * V_1185 )
{
int V_103 ;
struct V_1 * V_2 = (struct V_1 * ) V_1185 ;
if ( ! V_1186 ) {
V_103 = F_114 ( V_2 ) ;
if ( V_103 ) {
F_50 ( L_7 ) ;
return V_103 ;
}
F_94 ( V_2 ) ;
return 0 ;
}
F_279 ( & V_2 -> V_38 . V_1196 ) ;
F_225 ( V_2 ) ;
V_103 = F_226 ( V_2 ) ;
if ( V_103 )
V_2 -> V_38 . V_1198 = false ;
else
V_2 -> V_38 . V_1198 = true ;
F_281 ( & V_2 -> V_38 . V_1196 ) ;
return V_103 ;
}
static int F_286 ( void * V_1185 )
{
struct V_1 * V_2 = (struct V_1 * ) V_1185 ;
if ( V_2 -> V_38 . V_1198 ) {
F_279 ( & V_2 -> V_38 . V_1196 ) ;
F_227 ( V_2 ) ;
F_281 ( & V_2 -> V_38 . V_1196 ) ;
} else {
F_98 ( V_2 ) ;
}
return 0 ;
}
static int F_287 ( void * V_1185 )
{
struct V_1 * V_2 = (struct V_1 * ) V_1185 ;
if ( V_2 -> V_38 . V_1198 ) {
F_279 ( & V_2 -> V_38 . V_1196 ) ;
F_228 ( V_2 , & V_2 -> V_38 . V_39 . V_253 . V_1036 ,
V_1037 ) ;
F_228 ( V_2 , & V_2 -> V_38 . V_39 . V_253 . V_1036 ,
V_1038 ) ;
V_2 -> V_38 . V_39 . V_1199 = V_2 -> V_38 . V_39 . V_1189 ;
V_2 -> V_38 . V_39 . V_1200 = V_2 -> V_38 . V_39 . V_747 ;
V_2 -> V_38 . V_39 . V_1189 = V_1201 ;
V_2 -> V_38 . V_39 . V_747 = V_1201 ;
F_281 ( & V_2 -> V_38 . V_1196 ) ;
F_288 ( V_2 ) ;
}
return 0 ;
}
static int F_289 ( void * V_1185 )
{
int V_103 ;
struct V_1 * V_2 = (struct V_1 * ) V_1185 ;
if ( V_2 -> V_38 . V_1198 ) {
F_279 ( & V_2 -> V_38 . V_1196 ) ;
F_225 ( V_2 ) ;
V_103 = F_226 ( V_2 ) ;
if ( V_103 )
V_2 -> V_38 . V_1198 = false ;
else
V_2 -> V_38 . V_1198 = true ;
V_2 -> V_38 . V_39 . V_1189 = V_2 -> V_38 . V_39 . V_1199 ;
V_2 -> V_38 . V_39 . V_747 = V_2 -> V_38 . V_39 . V_1200 ;
F_281 ( & V_2 -> V_38 . V_1196 ) ;
if ( V_2 -> V_38 . V_1198 )
F_288 ( V_2 ) ;
}
return 0 ;
}
static bool F_290 ( void * V_1185 )
{
return true ;
}
static int F_291 ( void * V_1185 )
{
return 0 ;
}
static int F_292 ( void * V_1185 )
{
return 0 ;
}
static int F_293 ( struct V_1 * V_2 ,
struct V_1202 * V_372 ,
unsigned type ,
enum V_1203 V_747 )
{
T_2 V_1204 ;
switch ( type ) {
case V_1037 :
switch ( V_747 ) {
case V_1205 :
V_1204 = F_32 ( V_248 ) ;
V_1204 |= V_256 ;
F_33 ( V_248 , V_1204 ) ;
break;
case V_1206 :
V_1204 = F_32 ( V_248 ) ;
V_1204 &= ~ V_256 ;
F_33 ( V_248 , V_1204 ) ;
break;
default:
break;
}
break;
case V_1038 :
switch ( V_747 ) {
case V_1205 :
V_1204 = F_32 ( V_248 ) ;
V_1204 |= V_257 ;
F_33 ( V_248 , V_1204 ) ;
break;
case V_1206 :
V_1204 = F_32 ( V_248 ) ;
V_1204 &= ~ V_257 ;
F_33 ( V_248 , V_1204 ) ;
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
static int F_294 ( struct V_1 * V_2 ,
struct V_1202 * V_372 ,
struct V_1207 * V_995 )
{
bool V_1208 = false ;
if ( V_995 == NULL )
return - V_21 ;
switch ( V_995 -> V_1209 ) {
case 230 :
F_245 ( L_50 ) ;
V_2 -> V_38 . V_39 . V_253 . V_1210 = false ;
V_1208 = true ;
break;
case 231 :
F_245 ( L_51 ) ;
V_2 -> V_38 . V_39 . V_253 . V_1210 = true ;
V_1208 = true ;
break;
default:
break;
}
if ( V_1208 )
F_295 ( & V_2 -> V_38 . V_39 . V_253 . V_1194 ) ;
return 0 ;
}
static int F_296 ( void * V_1185 ,
enum V_1211 V_747 )
{
return 0 ;
}
static int F_297 ( void * V_1185 ,
enum V_1212 V_747 )
{
return 0 ;
}
static int F_298 ( struct V_1 * V_2 ,
enum V_1213 type , char * V_1214 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_587 * V_579 = & V_37 -> V_126 . V_579 ;
struct V_587 * V_580 = & V_37 -> V_126 . V_580 ;
struct V_587 * V_880 = & V_37 -> V_126 . V_591 ;
int V_32 , V_1215 , V_1133 = 0 ;
T_16 clock , V_1000 ;
switch ( type ) {
case V_1216 :
F_36 ( V_2 , V_418 ) ;
clock = F_2 ( V_410 ) ;
for ( V_32 = 0 ; V_32 < V_579 -> V_34 ; V_32 ++ ) {
if ( clock > V_579 -> V_581 [ V_32 ] . V_86 )
continue;
break;
}
V_1215 = V_32 ;
for ( V_32 = 0 ; V_32 < V_579 -> V_34 ; V_32 ++ )
V_1133 += sprintf ( V_1214 + V_1133 , L_52 ,
V_32 , V_579 -> V_581 [ V_32 ] . V_86 / 100 ,
( V_32 == V_1215 ) ? L_53 : L_54 ) ;
break;
case V_1217 :
F_36 ( V_2 , V_420 ) ;
clock = F_2 ( V_410 ) ;
for ( V_32 = 0 ; V_32 < V_580 -> V_34 ; V_32 ++ ) {
if ( clock > V_580 -> V_581 [ V_32 ] . V_86 )
continue;
break;
}
V_1215 = V_32 ;
for ( V_32 = 0 ; V_32 < V_580 -> V_34 ; V_32 ++ )
V_1133 += sprintf ( V_1214 + V_1133 , L_52 ,
V_32 , V_580 -> V_581 [ V_32 ] . V_86 / 100 ,
( V_32 == V_1215 ) ? L_53 : L_54 ) ;
break;
case V_1218 :
V_1000 = F_203 ( V_2 ) ;
for ( V_32 = 0 ; V_32 < V_880 -> V_34 ; V_32 ++ ) {
if ( V_1000 != V_880 -> V_581 [ V_32 ] . V_86 )
continue;
break;
}
V_1215 = V_32 ;
for ( V_32 = 0 ; V_32 < V_880 -> V_34 ; V_32 ++ )
V_1133 += sprintf ( V_1214 + V_1133 , L_55 , V_32 ,
( V_880 -> V_581 [ V_32 ] . V_86 == 0 ) ? L_56 :
( V_880 -> V_581 [ V_32 ] . V_86 == 1 ) ? L_57 :
( V_880 -> V_581 [ V_32 ] . V_86 == 2 ) ? L_58 : L_54 ,
( V_32 == V_1215 ) ? L_53 : L_54 ) ;
break;
default:
break;
}
return V_1133 ;
}
static int F_299 ( struct V_1 * V_2 ,
enum V_1213 type , T_16 V_177 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( V_2 -> V_38 . V_39 . V_925 & ( V_923 |
V_922 |
V_913 ) )
return - V_21 ;
switch ( type ) {
case V_1216 :
if ( ! V_37 -> V_377 )
F_58 ( V_2 ,
V_412 ,
V_37 -> V_600 . V_784 & V_177 ) ;
break;
case V_1217 :
if ( ! V_37 -> V_381 )
F_58 ( V_2 ,
V_413 ,
V_37 -> V_600 . V_789 & V_177 ) ;
break;
case V_1218 :
{
T_16 V_247 = V_177 & V_37 -> V_600 . V_601 ;
T_16 V_584 = 0 ;
while ( V_247 >>= 1 )
V_584 ++ ;
if ( ! V_37 -> V_401 )
F_58 ( V_2 ,
V_414 ,
V_584 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_300 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_587 * V_579 = & ( V_37 -> V_126 . V_579 ) ;
struct V_587 * V_1219 =
& ( V_37 -> V_809 . V_579 ) ;
int V_86 ;
V_86 = ( V_579 -> V_581 [ V_579 -> V_34 - 1 ] . V_86 -
V_1219 -> V_581 [ V_1219 -> V_34 - 1 ] . V_86 ) *
100 /
V_1219 -> V_581 [ V_1219 -> V_34 - 1 ] . V_86 ;
return V_86 ;
}
static int F_301 ( struct V_1 * V_2 , T_16 V_86 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_41 * V_44 = F_10 ( V_2 -> V_38 . V_39 . V_1033 ) ;
struct V_587 * V_1219 =
& ( V_37 -> V_809 . V_579 ) ;
if ( V_86 > 20 )
V_86 = 20 ;
V_44 -> V_239 [ V_44 -> V_238 - 1 ] . V_223 =
V_1219 -> V_581 [ V_1219 -> V_34 - 1 ] . V_86 *
V_86 / 100 +
V_1219 -> V_581 [ V_1219 -> V_34 - 1 ] . V_86 ;
return 0 ;
}
static int F_302 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_587 * V_580 = & ( V_37 -> V_126 . V_580 ) ;
struct V_587 * V_1220 =
& ( V_37 -> V_809 . V_580 ) ;
int V_86 ;
V_86 = ( V_580 -> V_581 [ V_580 -> V_34 - 1 ] . V_86 -
V_1220 -> V_581 [ V_1220 -> V_34 - 1 ] . V_86 ) *
100 /
V_1220 -> V_581 [ V_1220 -> V_34 - 1 ] . V_86 ;
return V_86 ;
}
static int F_303 ( struct V_1 * V_2 , T_16 V_86 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_41 * V_44 = F_10 ( V_2 -> V_38 . V_39 . V_1033 ) ;
struct V_587 * V_1220 =
& ( V_37 -> V_809 . V_580 ) ;
if ( V_86 > 20 )
V_86 = 20 ;
V_44 -> V_239 [ V_44 -> V_238 - 1 ] . V_224 =
V_1220 -> V_581 [ V_1220 -> V_34 - 1 ] . V_86 *
V_86 / 100 +
V_1220 -> V_581 [ V_1220 -> V_34 - 1 ] . V_86 ;
return 0 ;
}
static int F_304 ( struct V_1 * V_2 ,
struct V_1221 * V_1222 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( ! V_37 || ! V_1222 )
return - V_21 ;
if ( V_1222 -> type == V_816 )
memcpy ( V_1222 , & V_37 -> V_820 ,
sizeof( struct V_1221 ) ) ;
else if ( V_1222 -> type == V_818 )
memcpy ( V_1222 , & V_37 -> V_821 ,
sizeof( struct V_1221 ) ) ;
else
return - V_21 ;
return 0 ;
}
static int F_305 ( struct V_1 * V_2 ,
struct V_1221 * V_1019 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_590 * V_126 = & ( V_37 -> V_126 ) ;
struct T_15 * V_780 =
V_37 -> V_127 . V_777 ;
T_16 V_1223 = V_37 -> V_349 +
F_20 ( T_4 , V_777 ) ;
T_16 V_1224 = sizeof( struct T_15 ) *
V_779 ;
T_16 V_32 ;
for ( V_32 = 0 ; V_32 < V_126 -> V_579 . V_34 ; V_32 ++ ) {
V_780 [ V_32 ] . V_690 =
F_17 ( V_1019 -> V_813 ) ;
V_780 [ V_32 ] . V_596 = 1 ;
V_780 [ V_32 ] . V_687 = V_1019 -> V_814 ;
V_780 [ V_32 ] . V_688 = V_1019 -> V_815 ;
}
return F_27 ( V_2 , V_1223 , ( V_310 * ) V_780 ,
V_1224 , V_37 -> V_109 ) ;
}
static void F_306 ( struct V_1 * V_2 ,
T_16 * V_1225 , T_16 * V_1226 ,
T_16 V_819 , T_16 V_1227 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_590 * V_126 = & ( V_37 -> V_126 ) ;
T_16 V_32 ;
for ( V_32 = 0 ; V_32 < V_126 -> V_579 . V_34 ; V_32 ++ ) {
if ( V_126 -> V_579 . V_581 [ V_32 ] . V_589 &&
V_126 -> V_579 . V_581 [ V_32 ] . V_86 >= V_819 )
* V_1225 |= 1 << V_32 ;
}
for ( V_32 = 0 ; V_32 < V_126 -> V_580 . V_34 ; V_32 ++ ) {
if ( V_126 -> V_580 . V_581 [ V_32 ] . V_589 &&
V_126 -> V_580 . V_581 [ V_32 ] . V_86 >= V_1227 )
* V_1226 |= 1 << V_32 ;
}
}
static int F_307 ( struct V_1 * V_2 ,
struct V_1221 * V_1019 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_1228 , V_255 = 0 ;
T_16 V_1225 = 0 , V_1226 = 0 ;
V_1228 = F_85 ( V_2 ) ;
if ( V_1228 ) {
F_50 ( L_59 ) ;
V_255 = V_1228 ;
}
V_1228 = F_305 ( V_2 ,
V_1019 ) ;
if ( V_1228 ) {
F_50 ( L_60 ) ;
V_255 = V_1228 ;
}
V_1228 = F_81 ( V_2 ) ;
if ( V_1228 ) {
F_50 ( L_61 ) ;
V_255 = V_1228 ;
}
F_306 ( V_2 , & V_1225 , & V_1226 ,
V_1019 -> V_819 , V_1019 -> V_1227 ) ;
if ( V_1225 ) {
if ( ! V_37 -> V_377 )
F_58 (
V_2 ,
V_412 ,
V_37 -> V_600 .
V_784 &
V_1225 ) ;
}
if ( V_1226 ) {
if ( ! V_37 -> V_381 )
F_58 (
V_2 ,
V_413 ,
V_37 -> V_600 .
V_789 &
V_1226 ) ;
}
return V_255 ;
}
static int F_308 ( struct V_1 * V_2 ,
struct V_1221 * V_1019 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
int V_103 = - 1 ;
if ( ! V_37 || ! V_1019 )
return - V_21 ;
if ( V_2 -> V_38 . V_39 . V_925 !=
V_923 )
return - V_21 ;
if ( V_1019 -> V_819 ||
V_1019 -> V_1227 ||
V_1019 -> V_813 ||
V_1019 -> V_814 ||
V_1019 -> V_815 ) {
if ( V_1019 -> type == V_816 )
memcpy ( & V_37 -> V_820 , V_1019 ,
sizeof( struct V_1221 ) ) ;
else if ( V_1019 -> type == V_818 )
memcpy ( & V_37 -> V_821 , V_1019 ,
sizeof( struct V_1221 ) ) ;
else
return - V_21 ;
if ( V_1019 -> type == V_37 -> V_1229 )
V_103 = F_307 (
V_2 ,
V_1019 ) ;
} else {
switch ( V_1019 -> type ) {
case V_816 :
V_103 = F_307 (
V_2 ,
& V_37 -> V_820 ) ;
break;
case V_818 :
V_103 = F_307 (
V_2 ,
& V_37 -> V_821 ) ;
break;
default:
return - V_21 ;
}
}
if ( ! V_103 )
V_37 -> V_1229 = V_1019 -> type ;
return 0 ;
}
static int F_309 ( struct V_1 * V_2 ,
struct V_1221 * V_1019 )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
if ( ! V_37 || ! V_1019 )
return - V_21 ;
if ( V_1019 -> type == V_816 ) {
V_37 -> V_820 = V_37 -> V_812 ;
return F_308 ( V_2 ,
& V_37 -> V_820 ) ;
} else if ( V_1019 -> type == V_818 ) {
V_37 -> V_821 =
V_37 -> V_817 ;
return F_308 ( V_2 ,
& V_37 -> V_821 ) ;
} else
return - V_21 ;
}
static int F_310 ( struct V_1 * V_2 ,
enum V_1230 type )
{
struct V_36 * V_37 = F_9 ( V_2 ) ;
struct V_1221 V_1019 = { 0 } ;
if ( ! V_37 )
return - V_21 ;
if ( V_37 -> V_1229 != type ) {
V_1019 . type = type ;
return F_308 ( V_2 , & V_1019 ) ;
}
return 0 ;
}
static int F_311 ( struct V_1 * V_2 , int V_557 ,
void * V_86 , int * V_1133 )
{
T_2 V_1170 = 50 ;
int V_103 ;
if ( * V_1133 < 4 )
return - V_21 ;
switch ( V_557 ) {
case V_1231 :
* ( ( T_16 * ) V_86 ) = F_92 ( V_2 ) ;
* V_1133 = 4 ;
return 0 ;
case V_1232 :
* ( ( T_16 * ) V_86 ) = F_93 ( V_2 ) ;
* V_1133 = 4 ;
return 0 ;
case V_1233 :
* ( ( T_16 * ) V_86 ) = F_269 ( V_2 ) ;
* V_1133 = 4 ;
return 0 ;
case V_1234 :
V_103 = F_69 ( V_2 ,
F_20 ( V_396 ,
V_1171 ) ,
& V_1170 ) ;
if ( V_103 == 0 ) {
V_1170 += 0x80 ;
V_1170 >>= 8 ;
V_1170 =
V_1170 > 100 ? 100 : V_1170 ;
}
* ( ( T_16 * ) V_86 ) = V_1170 ;
* V_1133 = 4 ;
return 0 ;
default:
return - V_21 ;
}
}
static void F_272 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 . V_182 == NULL )
V_2 -> V_38 . V_182 = & V_1235 ;
}
static void F_273 ( struct V_1 * V_2 )
{
V_2 -> V_38 . V_39 . V_253 . V_1036 . V_1236 = V_1237 ;
V_2 -> V_38 . V_39 . V_253 . V_1036 . V_182 = & V_1238 ;
}
