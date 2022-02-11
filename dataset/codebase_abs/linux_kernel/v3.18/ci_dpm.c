static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 . V_6 . V_7 ;
return V_4 ;
}
static struct V_8 * F_2 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = V_10 -> V_12 ;
return V_11 ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_3 -> V_13 -> V_14 ) {
case 0x6649 :
case 0x6650 :
case 0x6651 :
case 0x6658 :
case 0x665C :
case 0x665D :
default:
V_4 -> V_15 = & V_16 ;
break;
case 0x6640 :
case 0x6641 :
case 0x6646 :
case 0x6647 :
V_4 -> V_15 = & V_17 ;
break;
case 0x67B8 :
case 0x67B0 :
V_4 -> V_15 = & V_18 ;
break;
case 0x67BA :
case 0x67B1 :
V_4 -> V_15 = & V_19 ;
break;
case 0x67A0 :
case 0x67A1 :
case 0x67A2 :
case 0x67A8 :
case 0x67A9 :
case 0x67AA :
case 0x67B9 :
case 0x67BE :
V_4 -> V_15 = & V_16 ;
break;
}
V_4 -> V_20 = 0 ;
V_4 -> V_21 = true ;
V_4 -> V_22 = false ;
V_4 -> V_23 = false ;
V_4 -> V_24 = false ;
V_4 -> V_25 = false ;
V_4 -> V_26 = false ;
if ( V_4 -> V_21 ) {
V_4 -> V_22 = true ;
V_4 -> V_27 = true ;
V_4 -> V_28 = true ;
V_4 -> V_29 = true ;
}
}
static T_1 F_4 ( T_2 V_30 )
{
return ( 6200 - ( V_30 * V_31 ) ) / 25 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 * V_32 = V_4 -> V_33 . V_34 ;
T_1 * V_35 = V_4 -> V_33 . V_36 ;
T_1 * V_37 = V_4 -> V_33 . V_38 ;
T_3 V_39 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 == NULL )
return - V_43 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 > 8 )
return - V_43 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 !=
V_3 -> V_5 . V_6 . V_40 . V_45 . V_44 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 ; V_39 ++ ) {
if ( V_3 -> V_5 . V_6 . V_46 & V_47 ) {
V_35 [ V_39 ] = F_4 ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_39 ] . V_48 ) ;
V_32 [ V_39 ] = F_4 ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_39 ] . V_49 ) ;
V_37 [ V_39 ] = F_4 ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_39 ] . V_50 ) ;
} else {
V_35 [ V_39 ] = F_4 ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_39 ] . V_30 ) ;
V_32 [ V_39 ] = F_4 ( ( T_2 ) V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_39 ] . V_51 ) ;
}
}
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 * V_52 = V_4 -> V_33 . V_53 ;
T_3 V_39 ;
if ( V_4 -> V_54 . V_44 > 8 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_4 -> V_54 . V_44 ; V_39 ++ )
V_52 [ V_39 ] = F_4 ( V_4 -> V_54 . V_42 [ V_39 ] . V_55 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_56 * V_57 = V_4 -> V_15 ;
V_4 -> V_33 . V_58 = V_57 -> V_59 ;
V_4 -> V_33 . V_60 = V_57 -> V_61 ;
V_4 -> V_33 . V_62 = 3 ;
V_4 -> V_33 . V_63 = 0 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_56 * V_57 = V_4 -> V_15 ;
T_2 V_64 ;
V_64 = V_3 -> V_5 . V_6 . V_40 . V_65 -> V_66 * 256 ;
V_4 -> V_33 . V_67 = F_9 ( V_64 ) ;
V_4 -> V_33 . V_68 =
V_57 -> V_69 ;
V_4 -> V_33 . V_70 = V_57 -> V_71 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_56 * V_57 = V_4 -> V_15 ;
int V_72 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_75 ) +
F_12 ( V_76 , V_77 ) ,
( T_3 * ) & V_4 -> V_33 . V_77 ,
V_4 -> V_78 ) ;
if ( V_72 )
return - V_43 ;
else
V_4 -> V_33 . V_77 = V_57 -> V_79 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 * V_32 = V_4 -> V_33 . V_34 ;
T_1 * V_35 = V_4 -> V_33 . V_36 ;
int V_39 , V_80 , V_81 ;
V_80 = V_81 = V_32 [ 0 ] ;
for ( V_39 = 0 ; V_39 < 8 ; V_39 ++ ) {
if ( 0 != V_32 [ V_39 ] ) {
if ( V_80 > V_32 [ V_39 ] )
V_80 = V_32 [ V_39 ] ;
if ( V_81 < V_32 [ V_39 ] )
V_81 = V_32 [ V_39 ] ;
}
if ( 0 != V_35 [ V_39 ] ) {
if ( V_80 > V_35 [ V_39 ] )
V_80 = V_35 [ V_39 ] ;
if ( V_81 < V_35 [ V_39 ] )
V_81 = V_35 [ V_39 ] ;
}
}
if ( ( V_80 == 0 ) || ( V_81 == 0 ) )
return - V_43 ;
V_4 -> V_33 . V_82 = ( T_1 ) V_81 ;
V_4 -> V_33 . V_83 = ( T_1 ) V_80 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_84 = V_4 -> V_33 . V_85 ;
T_2 V_86 = V_4 -> V_33 . V_87 ;
struct V_88 * V_65 =
V_3 -> V_5 . V_6 . V_40 . V_65 ;
V_84 = V_65 -> V_89 / 100 * 256 ;
V_86 = V_65 -> V_90 / 100 * 256 ;
V_4 -> V_33 . V_85 = F_9 ( V_84 ) ;
V_4 -> V_33 . V_87 = F_9 ( V_86 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_56 * V_57 = V_4 -> V_15 ;
T_4 * V_91 = & V_4 -> V_92 ;
struct V_88 * V_65 =
V_3 -> V_5 . V_6 . V_40 . V_65 ;
struct V_93 * V_94 = V_3 -> V_5 . V_6 . V_40 . V_95 ;
int V_39 , V_96 , V_97 ;
const T_2 * V_98 ;
const T_2 * V_99 ;
V_91 -> V_100 = V_65 -> V_101 * 256 ;
V_91 -> V_102 = V_65 -> V_103 * 256 ;
V_91 -> V_104 = ( T_1 ) V_4 -> V_20 ;
V_91 -> V_105 =
( T_1 ) ( V_4 -> V_106 . V_107 / 1000 ) ;
V_91 -> V_108 = 8 ;
V_91 -> V_109 = V_57 -> V_110 ;
if ( V_94 ) {
V_91 -> V_111 = F_9 ( ( T_2 ) V_94 -> V_112 * 256 / 1000 ) ;
V_91 -> V_113 = F_9 ( ( T_2 ) V_94 -> V_114 * 256 ) ;
} else {
V_91 -> V_111 = F_9 ( 0 ) ;
V_91 -> V_113 = F_9 ( 0 ) ;
}
V_91 -> V_115 = F_16 ( V_57 -> V_116 ) ;
V_98 = V_57 -> V_117 ;
V_99 = V_57 -> V_118 ;
for ( V_39 = 0 ; V_39 < V_119 ; V_39 ++ ) {
for ( V_96 = 0 ; V_96 < V_120 ; V_96 ++ ) {
for ( V_97 = 0 ; V_97 < V_121 ; V_97 ++ ) {
V_91 -> V_122 [ V_39 ] [ V_96 ] [ V_97 ] = F_9 ( * V_98 ) ;
V_91 -> V_123 [ V_39 ] [ V_96 ] [ V_97 ] = F_9 ( * V_99 ) ;
V_98 ++ ;
V_99 ++ ;
}
}
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_124 ;
int V_72 ;
if ( V_4 -> V_21 ) {
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_75 ) ,
& V_124 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_5 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_6 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_7 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_8 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_10 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_13 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_14 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_18 ( V_3 , V_124 ,
( T_1 * ) & V_4 -> V_33 ,
sizeof( V_76 ) , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static void F_19 ( struct V_2 * V_3 , const bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_126 ;
if ( V_4 -> V_23 ) {
V_126 = F_20 ( V_127 ) ;
if ( V_125 )
V_126 |= V_128 ;
else
V_126 &= ~ V_128 ;
F_21 ( V_127 , V_126 ) ;
}
if ( V_4 -> V_24 ) {
V_126 = F_20 ( V_129 ) ;
if ( V_125 )
V_126 |= V_128 ;
else
V_126 &= ~ V_128 ;
F_21 ( V_129 , V_126 ) ;
}
if ( V_4 -> V_25 ) {
V_126 = F_20 ( V_130 ) ;
if ( V_125 )
V_126 |= V_128 ;
else
V_126 &= ~ V_128 ;
F_21 ( V_130 , V_126 ) ;
}
if ( V_4 -> V_26 ) {
V_126 = F_20 ( V_131 ) ;
if ( V_125 )
V_126 |= V_128 ;
else
V_126 &= ~ V_128 ;
F_21 ( V_131 , V_126 ) ;
}
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_132 * V_133 )
{
const struct V_132 * V_134 = V_133 ;
T_3 V_126 ;
T_3 V_135 = 0 ;
if ( V_134 == NULL )
return - V_43 ;
while ( V_134 -> V_136 != 0xFFFFFFFF ) {
if ( V_134 -> type == V_137 ) {
V_135 |= ( ( V_134 -> V_55 << V_134 -> V_138 ) & V_134 -> V_139 ) ;
} else {
switch ( V_134 -> type ) {
case V_140 :
V_126 = F_23 ( V_134 -> V_136 ) ;
break;
case V_141 :
V_126 = F_20 ( V_134 -> V_136 ) ;
break;
default:
V_126 = F_24 ( V_134 -> V_136 << 2 ) ;
break;
}
V_126 &= ~ V_134 -> V_139 ;
V_126 |= ( ( V_134 -> V_55 << V_134 -> V_138 ) & V_134 -> V_139 ) ;
V_126 |= V_135 ;
switch ( V_134 -> type ) {
case V_140 :
F_25 ( V_134 -> V_136 , V_126 ) ;
break;
case V_141 :
F_21 ( V_134 -> V_136 , V_126 ) ;
break;
default:
F_26 ( V_134 -> V_136 << 2 , V_126 ) ;
break;
}
V_135 = 0 ;
}
V_134 ++ ;
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
if ( V_4 -> V_23 || V_4 -> V_24 ||
V_4 -> V_25 || V_4 -> V_26 ) {
F_28 ( V_3 ) ;
if ( V_125 ) {
V_72 = F_22 ( V_3 , V_142 ) ;
if ( V_72 ) {
F_29 ( V_3 ) ;
return V_72 ;
}
}
F_19 ( V_3 , V_125 ) ;
F_29 ( V_3 ) ;
}
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
int V_72 = 0 ;
if ( V_125 ) {
V_4 -> V_144 = 0 ;
if ( V_4 -> V_21 ) {
if ( V_4 -> V_27 ) {
V_143 = F_31 ( V_3 , V_145 ) ;
if ( V_143 != V_146 )
V_72 = - V_43 ;
else
V_4 -> V_144 |= V_147 ;
}
if ( V_4 -> V_28 ) {
V_143 = F_31 ( V_3 , V_148 ) ;
if ( V_143 != V_146 )
V_72 = - V_43 ;
else
V_4 -> V_144 |= V_149 ;
}
if ( V_4 -> V_29 ) {
V_143 = F_31 ( V_3 , V_150 ) ;
if ( V_143 != V_146 ) {
V_72 = - V_43 ;
} else {
struct V_88 * V_65 =
V_3 -> V_5 . V_6 . V_40 . V_65 ;
T_3 V_151 =
( T_3 ) ( V_65 -> V_152 * 256 ) ;
V_4 -> V_144 |= V_153 ;
F_32 ( V_3 , V_151 ) ;
}
}
}
} else {
if ( V_4 -> V_21 && V_4 -> V_144 ) {
if ( V_4 -> V_144 & V_149 )
F_31 ( V_3 , V_154 ) ;
if ( V_4 -> V_144 & V_147 )
F_31 ( V_3 , V_155 ) ;
if ( V_4 -> V_144 & V_153 )
F_31 ( V_3 , V_156 ) ;
V_4 -> V_144 = 0 ;
}
}
return V_72 ;
}
static int F_33 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
int V_72 = 0 ;
if ( V_4 -> V_22 ) {
if ( V_125 ) {
V_143 = F_31 ( V_3 , V_157 ) ;
if ( V_143 != V_146 ) {
V_72 = - V_43 ;
V_4 -> V_158 = false ;
} else {
V_4 -> V_158 = true ;
}
} else if ( V_4 -> V_158 ) {
F_31 ( V_3 , V_159 ) ;
V_4 -> V_158 = false ;
}
}
return V_72 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_88 * V_65 =
V_3 -> V_5 . V_6 . V_40 . V_65 ;
T_6 V_160 ;
T_6 V_161 ;
int V_72 = 0 ;
bool V_162 = false ;
if ( V_4 -> V_21 &&
( V_4 -> V_144 & V_147 ) ) {
V_160 = V_162 ?
V_3 -> V_5 . V_6 . V_163 : ( - 1 * V_3 -> V_5 . V_6 . V_163 ) ;
V_161 = ( ( 100 + V_160 ) *
( T_6 ) V_65 -> V_103 ) / 100 ;
V_161 *= 256 ;
V_72 = F_35 ( V_3 , ( T_3 ) V_161 ) ;
}
return V_72 ;
}
void F_36 ( struct V_2 * V_3 , bool V_164 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_165 == V_164 )
return;
V_4 -> V_165 = V_164 ;
F_37 ( V_3 , V_164 ) ;
}
bool F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_166 = F_39 ( V_3 ) ;
T_3 V_167 = V_4 -> V_168 ? 450 : 300 ;
if ( V_166 < V_167 )
return true ;
else
return false ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_169 * V_170 ;
bool V_171 ;
T_3 V_172 , V_173 ;
int V_39 ;
if ( V_10 -> V_174 ) {
V_10 -> V_175 = V_3 -> V_5 . V_6 . V_176 [ V_3 -> V_5 . V_6 . V_177 ] . V_175 ;
V_10 -> V_178 = V_3 -> V_5 . V_6 . V_176 [ V_3 -> V_5 . V_6 . V_177 ] . V_178 ;
} else {
V_10 -> V_175 = 0 ;
V_10 -> V_178 = 0 ;
}
if ( ( V_3 -> V_5 . V_6 . V_179 > 1 ) ||
F_38 ( V_3 ) )
V_171 = true ;
else
V_171 = false ;
if ( ( V_10 -> V_180 & V_181 ) == V_182 )
V_4 -> V_183 = true ;
else
V_4 -> V_183 = false ;
if ( V_3 -> V_5 . V_6 . V_184 )
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_185 ;
else
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_186 ;
if ( V_3 -> V_5 . V_6 . V_184 == false ) {
for ( V_39 = 0 ; V_39 < V_11 -> V_187 ; V_39 ++ ) {
if ( V_11 -> V_188 [ V_39 ] . V_173 > V_170 -> V_173 )
V_11 -> V_188 [ V_39 ] . V_173 = V_170 -> V_173 ;
if ( V_11 -> V_188 [ V_39 ] . V_172 > V_170 -> V_172 )
V_11 -> V_188 [ V_39 ] . V_172 = V_170 -> V_172 ;
}
}
if ( V_171 ) {
V_173 = V_11 -> V_188 [ V_11 -> V_187 - 1 ] . V_173 ;
V_172 = V_11 -> V_188 [ 0 ] . V_172 ;
} else {
V_173 = V_11 -> V_188 [ 0 ] . V_173 ;
V_172 = V_11 -> V_188 [ 0 ] . V_172 ;
}
if ( V_10 -> V_174 ) {
if ( V_172 < V_3 -> V_5 . V_6 . V_176 [ V_3 -> V_5 . V_6 . V_177 ] . V_172 )
V_172 = V_3 -> V_5 . V_6 . V_176 [ V_3 -> V_5 . V_6 . V_177 ] . V_172 ;
if ( V_173 < V_3 -> V_5 . V_6 . V_176 [ V_3 -> V_5 . V_6 . V_177 ] . V_173 )
V_173 = V_3 -> V_5 . V_6 . V_176 [ V_3 -> V_5 . V_6 . V_177 ] . V_173 ;
}
V_11 -> V_188 [ 0 ] . V_172 = V_172 ;
V_11 -> V_188 [ 0 ] . V_173 = V_173 ;
if ( V_11 -> V_188 [ 1 ] . V_172 < V_11 -> V_188 [ 0 ] . V_172 )
V_11 -> V_188 [ 1 ] . V_172 = V_11 -> V_188 [ 0 ] . V_172 ;
if ( V_171 ) {
if ( V_11 -> V_188 [ 0 ] . V_173 < V_11 -> V_188 [ 1 ] . V_173 )
V_11 -> V_188 [ 0 ] . V_173 = V_11 -> V_188 [ 1 ] . V_173 ;
} else {
if ( V_11 -> V_188 [ 1 ] . V_173 < V_11 -> V_188 [ 0 ] . V_173 )
V_11 -> V_188 [ 1 ] . V_173 = V_11 -> V_188 [ 0 ] . V_173 ;
}
}
static int F_41 ( struct V_2 * V_3 ,
int V_189 , int V_190 )
{
int V_191 = 0 * 1000 ;
int V_192 = 255 * 1000 ;
T_3 V_193 ;
if ( V_191 < V_189 )
V_191 = V_189 ;
if ( V_192 > V_190 )
V_192 = V_190 ;
if ( V_192 < V_191 ) {
F_42 ( L_1 , V_191 , V_192 ) ;
return - V_43 ;
}
V_193 = F_23 ( V_194 ) ;
V_193 &= ~ ( V_195 | V_196 ) ;
V_193 |= F_43 ( V_192 / 1000 ) |
F_44 ( V_191 / 1000 ) ;
F_25 ( V_194 , V_193 ) ;
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DIG_THERM_DPM_MASK;
tmp |= DIG_THERM_DPM(high_temp / 1000);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
V_3 -> V_5 . V_6 . V_197 . V_189 = V_191 ;
V_3 -> V_5 . V_6 . V_197 . V_190 = V_192 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 ,
T_2 V_198 , T_3 V_55 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_46 ( V_3 ,
V_4 -> V_199 + V_198 ,
V_55 , V_4 -> V_78 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_4 * V_200 = & V_4 -> V_92 ;
if ( V_4 -> V_201 ) {
T_2 V_193 ;
V_193 = 45 ;
V_200 -> V_202 = F_9 ( V_193 ) ;
V_193 = 30 ;
V_200 -> V_203 = F_9 ( V_193 ) ;
}
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 = 0 ;
T_3 V_204 = 0 ;
if ( V_4 -> V_205 ) {
V_204 = F_16 ( V_4 -> V_204 ) ;
V_72 = F_18 ( V_3 ,
V_4 -> V_206 +
F_12 ( T_4 , V_207 ) ,
( T_1 * ) & V_204 ,
sizeof( T_3 ) , V_4 -> V_78 ) ;
}
return V_72 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_208 , V_209 ;
T_2 V_30 , V_210 ;
int V_39 ;
V_4 -> V_211 . V_44 = 0 ;
V_4 -> V_212 . V_44 = 0 ;
if ( V_3 -> V_5 . V_6 . V_46 & V_47 ) {
for ( V_39 = 0 ; V_39 < V_213 ; V_39 ++ ) {
V_209 = V_214 + V_39 ;
if ( F_50 ( V_3 , V_209 , & V_30 ) != 0 )
continue;
if ( V_30 != 0 && V_30 != V_209 ) {
V_4 -> V_211 . V_215 [ V_4 -> V_211 . V_44 ] = V_30 ;
V_4 -> V_211 . V_208 [ V_4 -> V_211 . V_44 ] = V_209 ;
V_4 -> V_211 . V_44 ++ ;
}
}
} else if ( F_51 ( V_3 , & V_208 ) == 0 ) {
for ( V_39 = 0 ; V_39 < V_213 ; V_39 ++ ) {
V_209 = V_214 + V_39 ;
if ( F_52 ( V_3 , & V_30 , & V_210 ,
V_209 ,
V_208 ) == 0 ) {
if ( V_30 != 0 && V_30 != V_209 ) {
V_4 -> V_211 . V_215 [ V_4 -> V_211 . V_44 ] = V_30 ;
V_4 -> V_211 . V_208 [ V_4 -> V_211 . V_44 ] = V_209 ;
V_4 -> V_211 . V_44 ++ ;
}
if ( V_210 != 0 && V_210 != V_209 ) {
V_4 -> V_212 . V_215 [ V_4 -> V_212 . V_44 ] = V_210 ;
V_4 -> V_212 . V_208 [ V_4 -> V_212 . V_44 ] = V_209 ;
V_4 -> V_212 . V_44 ++ ;
}
}
}
}
}
static void F_53 ( struct V_2 * V_3 , T_3 V_216 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
bool V_217 ;
enum V_218 V_219 ;
T_3 V_193 ;
switch ( V_216 ) {
case 0 :
default:
V_217 = false ;
break;
case ( 1 << V_220 ) :
V_217 = true ;
V_219 = V_221 ;
break;
case ( 1 << V_222 ) :
V_217 = true ;
V_219 = V_223 ;
break;
case ( ( 1 << V_222 ) |
( 1 << V_220 ) ) :
V_217 = true ;
V_219 = V_224 ;
break;
}
if ( V_217 ) {
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DPM_EVENT_SRC_MASK;
tmp |= DPM_EVENT_SRC(dpm_event_src);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
V_193 = F_23 ( V_225 ) ;
if ( V_4 -> V_226 )
V_193 &= ~ V_227 ;
else
V_193 |= V_227 ;
F_25 ( V_225 , V_193 ) ;
} else {
V_193 = F_23 ( V_225 ) ;
V_193 |= V_227 ;
F_25 ( V_225 , V_193 ) ;
}
}
static void F_54 ( struct V_2 * V_3 ,
enum V_228 V_229 ,
bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_125 ) {
if ( ! ( V_4 -> V_230 & ( 1 << V_229 ) ) ) {
V_4 -> V_230 |= 1 << V_229 ;
F_53 ( V_3 , V_4 -> V_230 ) ;
}
} else {
if ( V_4 -> V_230 & ( 1 << V_229 ) ) {
V_4 -> V_230 &= ~ ( 1 << V_229 ) ;
F_53 ( V_3 , V_4 -> V_230 ) ;
}
}
}
static void F_55 ( struct V_2 * V_3 )
{
if ( V_3 -> V_5 . V_6 . V_46 & V_231 )
F_31 ( V_3 , V_232 ) ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
if ( ! V_4 -> V_233 )
return 0 ;
if ( ( ! V_4 -> V_234 ) &&
( V_4 -> V_233 & ( V_235 | V_236 ) ) ) {
V_143 = F_31 ( V_3 , V_237 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ( ! V_4 -> V_238 ) &&
( V_4 -> V_233 & V_239 ) ) {
V_143 = F_31 ( V_3 , V_240 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
V_4 -> V_233 = 0 ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
if ( V_125 ) {
if ( ! V_4 -> V_234 ) {
V_143 = F_31 ( V_3 , V_241 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ! V_4 -> V_238 ) {
V_143 = F_31 ( V_3 , V_242 ) ;
if ( V_143 != V_146 )
return - V_43 ;
F_58 ( V_243 , V_244 , ~ V_244 ) ;
F_25 ( V_245 , 0x05 ) ;
F_25 ( V_246 , 0x05 ) ;
F_25 ( V_247 , 0x100005 ) ;
F_59 ( 10 ) ;
F_25 ( V_245 , 0x400005 ) ;
F_25 ( V_246 , 0x400005 ) ;
F_25 ( V_247 , 0x500005 ) ;
}
} else {
if ( ! V_4 -> V_234 ) {
V_143 = F_31 ( V_3 , V_248 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ! V_4 -> V_238 ) {
V_143 = F_31 ( V_3 , V_249 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
}
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
int V_72 ;
T_3 V_193 ;
V_193 = F_23 ( V_225 ) ;
V_193 |= V_250 ;
F_25 ( V_225 , V_193 ) ;
V_193 = F_23 ( V_251 ) ;
V_193 |= V_252 ;
F_25 ( V_251 , V_193 ) ;
F_45 ( V_3 , F_12 ( V_253 , V_254 ) , 0x1000 ) ;
F_58 ( V_255 , 0 , ~ V_256 ) ;
V_143 = F_31 ( V_3 , V_257 ) ;
if ( V_143 != V_146 )
return - V_43 ;
V_72 = F_57 ( V_3 , true ) ;
if ( V_72 )
return V_72 ;
if ( ! V_4 -> V_258 ) {
V_143 = F_31 ( V_3 , V_259 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
if ( ! V_4 -> V_233 )
return 0 ;
if ( ( ! V_4 -> V_234 ) &&
( V_4 -> V_233 & ( V_235 | V_236 ) ) ) {
V_143 = F_31 ( V_3 , V_260 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ( ! V_4 -> V_238 ) &&
( V_4 -> V_233 & V_239 ) ) {
V_143 = F_31 ( V_3 , V_261 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
int V_72 ;
T_3 V_193 ;
V_193 = F_23 ( V_225 ) ;
V_193 &= ~ V_250 ;
F_25 ( V_225 , V_193 ) ;
V_193 = F_23 ( V_251 ) ;
V_193 &= ~ V_252 ;
F_25 ( V_251 , V_193 ) ;
if ( ! V_4 -> V_258 ) {
V_143 = F_31 ( V_3 , V_262 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
V_72 = F_57 ( V_3 , false ) ;
if ( V_72 )
return V_72 ;
V_143 = F_31 ( V_3 , V_263 ) ;
if ( V_143 != V_146 )
return - V_43 ;
return 0 ;
}
static void F_63 ( struct V_2 * V_3 , bool V_125 )
{
T_3 V_193 = F_23 ( V_251 ) ;
if ( V_125 )
V_193 &= ~ V_264 ;
else
V_193 |= V_264 ;
F_25 ( V_251 , V_193 ) ;
}
static T_5 F_64 ( struct V_2 * V_3 ,
T_7 V_265 , T_3 V_266 )
{
F_26 ( V_267 , V_266 ) ;
return F_31 ( V_3 , V_265 ) ;
}
static T_5 F_65 ( struct V_2 * V_3 ,
T_7 V_265 , T_3 * V_266 )
{
T_5 V_143 ;
V_143 = F_31 ( V_3 , V_265 ) ;
if ( ( V_143 == V_146 ) && V_266 )
* V_266 = F_24 ( V_267 ) ;
return V_143 ;
}
static int F_66 ( struct V_2 * V_3 , T_3 V_268 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_234 ) {
T_5 V_143 =
F_64 ( V_3 , V_269 , V_268 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , T_3 V_268 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_238 ) {
T_5 V_143 =
F_64 ( V_3 , V_270 , V_268 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , T_3 V_268 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_258 ) {
T_5 V_143 =
F_64 ( V_3 , V_271 , V_268 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , T_3 V_268 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_144 & V_153 ) {
T_5 V_143 =
F_64 ( V_3 , V_272 , V_268 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
T_3 V_161 )
{
T_5 V_143 =
F_64 ( V_3 , V_273 , V_161 ) ;
if ( V_143 != V_146 )
return - V_43 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
return F_57 ( V_3 , false ) ;
}
static T_3 F_70 ( struct V_2 * V_3 )
{
T_3 V_274 ;
T_5 V_143 =
F_65 ( V_3 ,
V_275 ,
& V_274 ) ;
if ( V_143 != V_146 )
V_274 = 0 ;
return V_274 ;
}
static T_3 F_71 ( struct V_2 * V_3 )
{
T_3 V_276 ;
T_5 V_143 =
F_65 ( V_3 ,
V_277 ,
& V_276 ) ;
if ( V_143 != V_146 )
V_276 = 0 ;
return V_276 ;
}
static void F_72 ( struct V_2 * V_3 )
{
int V_39 ;
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
F_75 ( V_3 ) ;
for ( V_39 = 0 ; V_39 < V_3 -> V_278 ; V_39 ++ ) {
if ( F_23 ( V_279 ) & V_280 )
break;
}
}
static void F_76 ( struct V_2 * V_3 )
{
F_77 ( V_3 ) ;
F_78 ( V_3 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_193 ;
int V_72 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_281 ) ,
& V_193 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_206 = V_193 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_282 ) ,
& V_193 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_199 = V_193 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_283 ) ,
& V_193 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_284 = V_193 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_285 ) ,
& V_193 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_286 = V_193 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_287 ) ,
& V_193 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_288 = V_193 ;
return 0 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_289 . V_290 =
F_23 ( V_291 ) ;
V_4 -> V_289 . V_292 =
F_23 ( V_293 ) ;
V_4 -> V_289 . V_294 =
F_23 ( V_295 ) ;
V_4 -> V_289 . V_296 =
F_23 ( V_297 ) ;
V_4 -> V_289 . V_298 =
F_23 ( V_299 ) ;
V_4 -> V_289 . V_300 =
F_23 ( V_301 ) ;
V_4 -> V_289 . V_302 = F_24 ( V_303 ) ;
V_4 -> V_289 . V_304 = F_24 ( V_305 ) ;
V_4 -> V_289 . V_306 = F_24 ( V_307 ) ;
V_4 -> V_289 . V_308 = F_24 ( V_309 ) ;
V_4 -> V_289 . V_310 = F_24 ( V_311 ) ;
V_4 -> V_289 . V_312 = F_24 ( V_313 ) ;
V_4 -> V_289 . V_314 = F_24 ( V_315 ) ;
V_4 -> V_289 . V_316 = F_24 ( V_317 ) ;
V_4 -> V_289 . V_318 = F_24 ( V_319 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_204 = 0 ;
}
static void F_82 ( struct V_2 * V_3 ,
bool V_125 )
{
T_3 V_193 = F_23 ( V_225 ) ;
if ( V_125 )
V_193 &= ~ V_227 ;
else
V_193 |= V_227 ;
F_25 ( V_225 , V_193 ) ;
}
static void F_83 ( struct V_2 * V_3 )
{
T_3 V_193 = F_23 ( V_225 ) ;
V_193 |= V_320 ;
F_25 ( V_225 , V_193 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
bool V_321 )
{
T_7 V_265 = V_321 ? V_322 : V_323 ;
return ( F_31 ( V_3 , V_265 ) == V_146 ) ? 0 : - V_43 ;
}
static int F_85 ( struct V_2 * V_3 ,
bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_125 ) {
if ( V_4 -> V_324 ) {
if ( F_31 ( V_3 , V_325 ) != V_146 )
return - V_43 ;
} else {
if ( F_31 ( V_3 , V_326 ) != V_146 )
return - V_43 ;
}
} else {
if ( V_4 -> V_324 ) {
if ( F_31 ( V_3 , V_326 ) != V_146 )
return - V_43 ;
}
}
return 0 ;
}
static void F_86 ( struct V_2 * V_3 )
{
T_3 V_193 = F_23 ( V_327 ) ;
T_3 V_328 ;
T_3 V_329 ;
T_3 V_330 = V_3 -> clock . V_331 . V_332 ;
T_3 V_333 = F_87 ( V_3 ) ;
T_3 V_166 = F_39 ( V_3 ) ;
V_193 &= ~ V_334 ;
if ( V_3 -> V_5 . V_6 . V_179 > 0 )
V_193 |= F_88 ( V_335 ) ;
else
V_193 |= F_88 ( V_336 ) ;
F_25 ( V_327 , V_193 ) ;
if ( V_333 == 0 )
V_333 = 60 ;
if ( V_166 == 0xffffffff )
V_166 = 500 ;
V_329 = 1000000 / V_333 ;
V_328 =
V_329 - 200 - V_166 ;
V_193 = V_328 * ( V_330 / 100 ) ;
F_25 ( V_337 , V_193 ) ;
F_45 ( V_3 , F_12 ( V_253 , V_338 ) , 0x64 ) ;
F_45 ( V_3 , F_12 ( V_253 , V_339 ) , ( V_329 - V_328 ) ) ;
F_84 ( V_3 , ( V_3 -> V_5 . V_6 . V_179 == 1 ) ) ;
}
static void F_89 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_193 ;
if ( V_125 ) {
if ( V_4 -> V_340 ) {
V_193 = F_23 ( V_225 ) ;
V_193 |= V_341 ;
F_25 ( V_225 , V_193 ) ;
}
} else {
V_193 = F_23 ( V_299 ) ;
V_193 &= ~ V_342 ;
F_25 ( V_299 , V_193 ) ;
V_193 = F_23 ( V_225 ) ;
V_193 &= ~ V_341 ;
F_25 ( V_225 , V_193 ) ;
}
}
static void F_90 ( struct V_2 * V_3 )
{
F_25 ( V_343 , ( F_91 ( V_344 ) | F_92 ( V_345 ) ) ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
T_3 V_193 = F_23 ( V_327 ) ;
V_193 &= ~ ( V_334 | V_346 ) ;
V_193 |= ( F_88 ( V_336 ) |
F_94 ( V_347 ) ) ;
F_25 ( V_327 , V_193 ) ;
}
static void F_95 ( struct V_2 * V_3 )
{
T_3 V_193 ;
V_193 = F_23 ( V_251 ) ;
V_193 &= ~ ( V_348 | V_349 ) ;
F_25 ( V_251 , V_193 ) ;
F_25 ( V_350 , V_351 ) ;
F_25 ( V_352 , V_353 ) ;
F_25 ( V_354 , V_355 ) ;
F_25 ( V_356 , V_357 ) ;
F_25 ( V_358 , V_359 ) ;
F_25 ( V_360 , V_361 ) ;
F_25 ( V_362 , V_363 ) ;
F_25 ( V_364 , V_365 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
T_3 V_193 ;
V_193 = F_23 ( V_251 ) ;
V_193 |= ( V_348 | V_349 ) ;
F_25 ( V_251 , V_193 ) ;
F_25 ( V_350 , 0 ) ;
F_25 ( V_352 , 0 ) ;
F_25 ( V_354 , 0 ) ;
F_25 ( V_356 , 0 ) ;
F_25 ( V_358 , 0 ) ;
F_25 ( V_360 , 0 ) ;
F_25 ( V_362 , 0 ) ;
F_25 ( V_364 , 0 ) ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_39 , V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_278 ; V_39 ++ ) {
if ( F_23 ( V_366 ) & V_367 )
break;
}
F_25 ( V_368 , 1 ) ;
F_78 ( V_3 ) ;
F_77 ( V_3 ) ;
V_72 = F_98 ( V_3 , V_4 -> V_78 ) ;
return V_72 ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_369 * V_370 ,
struct V_371 * V_372 )
{
T_3 V_39 ;
if ( V_370 == NULL )
return - V_43 ;
V_372 -> V_373 = 0 ;
V_372 -> V_374 = 0 ;
V_372 -> V_44 = V_370 -> V_44 ;
for ( V_39 = 0 ; V_39 < V_372 -> V_44 ; V_39 ++ ) {
V_372 -> V_42 [ V_39 ] . V_55 = V_370 -> V_42 [ V_39 ] . V_375 ;
V_372 -> V_42 [ V_39 ] . V_376 = 0 ;
}
return 0 ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
if ( V_4 -> V_377 == V_378 ) {
V_72 = F_101 ( V_3 , V_379 ,
V_380 ,
& V_4 -> V_54 ) ;
if ( V_72 )
return V_72 ;
} else if ( V_4 -> V_377 == V_381 ) {
V_72 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_382 ,
& V_4 -> V_54 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_4 -> V_54 . V_44 > V_383 )
F_102 ( V_3 , V_383 ,
& V_4 -> V_54 ) ;
if ( V_4 -> V_384 == V_378 ) {
V_72 = F_101 ( V_3 , V_385 ,
V_380 ,
& V_4 -> V_386 ) ;
if ( V_72 )
return V_72 ;
} else if ( V_4 -> V_384 == V_381 ) {
V_72 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_387 ,
& V_4 -> V_386 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_4 -> V_386 . V_44 > V_388 )
F_102 ( V_3 , V_388 ,
& V_4 -> V_386 ) ;
if ( V_4 -> V_389 == V_378 ) {
V_72 = F_101 ( V_3 , V_390 ,
V_380 ,
& V_4 -> V_391 ) ;
if ( V_72 )
return V_72 ;
} else if ( V_4 -> V_389 == V_381 ) {
V_72 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_392 ,
& V_4 -> V_391 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_4 -> V_391 . V_44 > V_393 )
F_102 ( V_3 , V_393 ,
& V_4 -> V_391 ) ;
return 0 ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_394 * V_372 ,
T_8 * V_395 )
{
int V_72 ;
V_72 = F_104 ( V_3 , V_372 ,
& V_395 -> V_396 ,
& V_395 -> V_397 ) ;
if ( V_72 ) {
V_395 -> V_396 = V_372 -> V_55 * V_31 ;
V_395 -> V_397 = V_372 -> V_55 * V_31 ;
}
V_395 -> V_398 = F_9 ( V_372 -> V_55 * V_31 ) ;
V_395 -> V_396 =
F_9 ( V_395 -> V_396 ) ;
V_395 -> V_397 =
F_9 ( V_395 -> V_397 ) ;
}
static int F_105 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_44 ;
V_200 -> V_399 = V_4 -> V_54 . V_44 ;
for ( V_44 = 0 ; V_44 < V_200 -> V_399 ; V_44 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_54 . V_42 [ V_44 ] ,
& V_200 -> V_400 [ V_44 ] ) ;
if ( V_4 -> V_377 == V_378 )
V_200 -> V_400 [ V_44 ] . V_401 |=
V_4 -> V_54 . V_42 [ V_44 ] . V_376 ;
else
V_200 -> V_400 [ V_44 ] . V_401 = 0 ;
}
V_200 -> V_399 = F_16 ( V_200 -> V_399 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
unsigned int V_44 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_200 -> V_402 = V_4 -> V_386 . V_44 ;
for ( V_44 = 0 ; V_44 < V_200 -> V_402 ; V_44 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_386 . V_42 [ V_44 ] ,
& V_200 -> V_403 [ V_44 ] ) ;
if ( V_4 -> V_384 == V_378 )
V_200 -> V_403 [ V_44 ] . V_401 |=
V_4 -> V_386 . V_42 [ V_44 ] . V_376 ;
else
V_200 -> V_403 [ V_44 ] . V_401 = 0 ;
}
V_200 -> V_402 = F_16 ( V_200 -> V_402 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_44 ;
V_200 -> V_404 = V_4 -> V_391 . V_44 ;
for ( V_44 = 0 ; V_44 < V_200 -> V_404 ; V_44 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_391 . V_42 [ V_44 ] ,
& V_200 -> V_405 [ V_44 ] ) ;
if ( V_4 -> V_389 == V_378 )
V_200 -> V_405 [ V_44 ] . V_401 |=
V_4 -> V_391 . V_42 [ V_44 ] . V_376 ;
else
V_200 -> V_405 [ V_44 ] . V_401 = 0 ;
}
V_200 -> V_404 = F_16 ( V_200 -> V_404 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
int V_72 ;
V_72 = F_105 ( V_3 , V_200 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_106 ( V_3 , V_200 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_107 ( V_3 , V_200 ) ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , T_3 V_173 ,
T_8 * V_406 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 = 0 ;
if ( V_4 -> V_389 != V_407 ) {
for ( V_39 = 0 ; V_39 < V_3 -> V_5 . V_6 . V_40 . V_392 . V_44 ; V_39 ++ ) {
if ( V_173 <= V_3 -> V_5 . V_6 . V_40 . V_392 . V_42 [ V_39 ] . V_408 ) {
V_406 -> V_398 = V_4 -> V_391 . V_42 [ V_39 ] . V_55 ;
break;
}
}
if ( V_39 >= V_3 -> V_5 . V_6 . V_40 . V_392 . V_44 )
return - V_43 ;
}
return - V_43 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_394 * V_372 ,
T_2 * V_409 , T_2 * V_410 )
{
T_2 V_411 , V_412 ;
bool V_413 = false ;
* V_409 = V_372 -> V_55 * V_31 ;
* V_410 = V_372 -> V_55 * V_31 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 == NULL )
return - V_43 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 ) {
for ( V_411 = 0 ; ( T_3 ) V_411 < V_3 -> V_5 . V_6 . V_40 . V_45 . V_44 ; V_411 ++ ) {
if ( V_372 -> V_55 ==
V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ V_411 ] . V_375 ) {
V_413 = true ;
if ( ( T_3 ) V_411 < V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 )
V_412 = V_411 ;
else
V_412 = V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 - 1 ;
* V_410 =
V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_412 ] . V_30 * V_31 ;
* V_409 =
V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_412 ] . V_51 * V_31 ;
break;
}
}
if ( ! V_413 ) {
for ( V_411 = 0 ; ( T_3 ) V_411 < V_3 -> V_5 . V_6 . V_40 . V_45 . V_44 ; V_411 ++ ) {
if ( V_372 -> V_55 <=
V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ V_411 ] . V_375 ) {
V_413 = true ;
if ( ( T_3 ) V_411 < V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 )
V_412 = V_411 ;
else
V_412 = V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 - 1 ;
* V_410 =
V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_412 ] . V_30 * V_31 ;
* V_409 =
V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_412 ] . V_51 * V_31 ;
break;
}
}
}
}
return 0 ;
}
static void F_110 ( struct V_2 * V_3 ,
const struct V_414 * V_415 ,
T_3 V_172 ,
T_3 * V_416 )
{
unsigned int V_39 ;
* V_416 = 1 ;
for ( V_39 = 0 ; V_39 < V_415 -> V_44 ; V_39 ++ ) {
if ( V_172 < V_415 -> V_42 [ V_39 ] . V_172 ) {
* V_416 = V_39 ;
break;
}
}
}
static void F_111 ( struct V_2 * V_3 ,
const struct V_414 * V_415 ,
T_3 V_173 ,
T_3 * V_416 )
{
unsigned int V_39 ;
* V_416 = 1 ;
for ( V_39 = 0 ; V_39 < V_415 -> V_44 ; V_39 ++ ) {
if ( V_173 < V_415 -> V_42 [ V_39 ] . V_173 ) {
* V_416 = V_39 ;
break;
}
}
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_193 ;
int V_72 ;
V_72 = F_11 ( V_3 , V_4 -> V_288 ,
& V_193 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_193 &= 0x00FFFFFF ;
V_193 |= V_417 << 24 ;
return F_46 ( V_3 , V_4 -> V_288 ,
V_193 , V_4 -> V_78 ) ;
}
static int F_113 ( struct V_2 * V_3 ,
struct V_369 * V_418 ,
T_3 clock , T_3 * V_406 )
{
T_3 V_39 = 0 ;
if ( V_418 -> V_44 == 0 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_418 -> V_44 ; V_39 ++ ) {
if ( V_418 -> V_42 [ V_39 ] . V_408 >= clock ) {
* V_406 = V_418 -> V_42 [ V_39 ] . V_375 ;
return 0 ;
}
}
* V_406 = V_418 -> V_42 [ V_39 - 1 ] . V_375 ;
return 0 ;
}
static T_1 F_114 ( struct V_2 * V_3 ,
T_3 V_172 , T_3 V_419 )
{
T_3 V_39 ;
T_3 V_193 ;
T_3 V_80 = ( V_419 > V_420 ) ?
V_419 : V_420 ;
if ( V_172 < V_80 )
return 0 ;
for ( V_39 = V_421 ; ; V_39 -- ) {
V_193 = V_172 / ( 1 << V_39 ) ;
if ( V_193 >= V_80 || V_39 == 0 )
break;
}
return ( T_1 ) V_39 ;
}
static int F_115 ( struct V_2 * V_3 )
{
return F_116 ( V_3 , V_422 , V_417 ) ;
}
static int F_117 ( struct V_2 * V_3 )
{
return ( F_31 ( V_3 , V_423 ) == V_146 ) ?
0 : - V_43 ;
}
static int F_118 ( struct V_2 * V_3 )
{
T_3 V_193 ;
V_193 = ( F_23 ( V_424 ) & 0x0000ff00 ) >> 8 ;
if ( V_193 == V_422 )
return 0 ;
return F_116 ( V_3 , V_193 , V_422 ) ;
}
static int F_119 ( struct V_2 * V_3 ,
T_3 V_172 ,
T_3 V_173 ,
T_9 * V_425 )
{
T_3 V_426 ;
T_3 V_427 ;
T_3 V_428 ;
F_120 ( V_3 , V_172 , V_173 ) ;
V_426 = F_24 ( V_429 ) ;
V_427 = F_24 ( V_430 ) ;
V_428 = F_24 ( V_431 ) & V_432 ;
V_425 -> V_433 = F_16 ( V_426 ) ;
V_425 -> V_434 = F_16 ( V_427 ) ;
V_425 -> V_435 = ( T_1 ) V_428 ;
return 0 ;
}
static int F_121 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_10 V_425 ;
T_3 V_39 , V_96 ;
int V_72 = 0 ;
memset ( & V_425 , 0 , sizeof( T_10 ) ) ;
for ( V_39 = 0 ; V_39 < V_4 -> V_91 . V_436 . V_44 ; V_39 ++ ) {
for ( V_96 = 0 ; V_96 < V_4 -> V_91 . V_437 . V_44 ; V_96 ++ ) {
V_72 = F_119 ( V_3 ,
V_4 -> V_91 . V_436 . V_438 [ V_39 ] . V_55 ,
V_4 -> V_91 . V_437 . V_438 [ V_96 ] . V_55 ,
& V_425 . V_42 [ V_39 ] [ V_96 ] ) ;
if ( V_72 )
break;
}
}
if ( V_72 == 0 )
V_72 = F_18 ( V_3 ,
V_4 -> V_288 ,
( T_1 * ) & V_425 ,
sizeof( T_10 ) ,
V_4 -> V_78 ) ;
return V_72 ;
}
static int F_122 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_233 == 0 )
return 0 ;
return F_121 ( V_3 ) ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_9 * V_439 )
{
struct V_8 * V_440 = F_2 ( V_439 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_441 = 0 ;
for ( V_441 = 0 ; V_441 < V_3 -> V_5 . V_6 . V_40 . V_45 . V_44 ; V_441 ++ ) {
if ( V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ V_441 ] . V_408 >=
V_440 -> V_188 [ 0 ] . V_172 ) {
V_4 -> V_92 . V_442 = V_441 ;
break;
}
}
for ( V_441 = 0 ; V_441 < V_3 -> V_5 . V_6 . V_40 . V_382 . V_44 ; V_441 ++ ) {
if ( V_3 -> V_5 . V_6 . V_40 . V_382 . V_42 [ V_441 ] . V_408 >=
V_440 -> V_188 [ 0 ] . V_173 ) {
V_4 -> V_92 . V_443 = V_441 ;
break;
}
}
}
static T_3 F_124 ( struct V_444 * V_91 )
{
T_3 V_39 ;
T_3 V_445 = 0 ;
for ( V_39 = V_91 -> V_44 ; V_39 > 0 ; V_39 -- ) {
V_445 = V_445 << 1 ;
if ( V_91 -> V_438 [ V_39 - 1 ] . V_446 )
V_445 |= 0x1 ;
else
V_445 &= 0xFFFFFFFE ;
}
return V_445 ;
}
static void F_125 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_447 * V_91 = & V_4 -> V_91 ;
T_3 V_39 ;
for ( V_39 = 0 ; V_39 < V_91 -> V_448 . V_44 ; V_39 ++ ) {
V_200 -> V_449 [ V_39 ] . V_450 =
( T_1 ) V_91 -> V_448 . V_438 [ V_39 ] . V_55 ;
V_200 -> V_449 [ V_39 ] . V_451 =
F_126 ( V_91 -> V_448 . V_438 [ V_39 ] . V_452 ) ;
V_200 -> V_449 [ V_39 ] . V_453 = 1 ;
V_200 -> V_449 [ V_39 ] . V_454 = F_16 ( 5 ) ;
V_200 -> V_449 [ V_39 ] . V_455 = F_16 ( 30 ) ;
}
V_4 -> V_92 . V_456 = ( T_1 ) V_91 -> V_448 . V_44 ;
V_4 -> V_457 . V_458 =
F_124 ( & V_91 -> V_448 ) ;
}
static int F_127 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
T_3 V_44 ;
struct V_459 V_460 ;
int V_72 = - V_43 ;
V_200 -> V_461 =
V_3 -> V_5 . V_6 . V_40 . V_462 . V_44 ;
for ( V_44 = 0 ; V_44 < V_200 -> V_461 ; V_44 ++ ) {
V_200 -> V_463 [ V_44 ] . V_464 =
V_3 -> V_5 . V_6 . V_40 . V_462 . V_42 [ V_44 ] . V_465 ;
V_200 -> V_463 [ V_44 ] . V_466 =
V_3 -> V_5 . V_6 . V_40 . V_462 . V_42 [ V_44 ] . V_467 ;
V_200 -> V_463 [ V_44 ] . V_468 =
V_3 -> V_5 . V_6 . V_40 . V_462 . V_42 [ V_44 ] . V_375 * V_31 ;
V_200 -> V_463 [ V_44 ] . V_469 = 1 ;
V_72 = F_128 ( V_3 ,
V_470 ,
V_200 -> V_463 [ V_44 ] . V_464 , false , & V_460 ) ;
if ( V_72 )
return V_72 ;
V_200 -> V_463 [ V_44 ] . V_471 = ( T_1 ) V_460 . V_472 ;
V_72 = F_128 ( V_3 ,
V_470 ,
V_200 -> V_463 [ V_44 ] . V_466 , false , & V_460 ) ;
if ( V_72 )
return V_72 ;
V_200 -> V_463 [ V_44 ] . V_473 = ( T_1 ) V_460 . V_472 ;
V_200 -> V_463 [ V_44 ] . V_464 = F_16 ( V_200 -> V_463 [ V_44 ] . V_464 ) ;
V_200 -> V_463 [ V_44 ] . V_466 = F_16 ( V_200 -> V_463 [ V_44 ] . V_466 ) ;
V_200 -> V_463 [ V_44 ] . V_468 = F_9 ( V_200 -> V_463 [ V_44 ] . V_468 ) ;
}
return V_72 ;
}
static int F_129 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
T_3 V_44 ;
struct V_459 V_460 ;
int V_72 = - V_43 ;
V_200 -> V_474 =
V_3 -> V_5 . V_6 . V_40 . V_475 . V_44 ;
for ( V_44 = 0 ; V_44 < V_200 -> V_474 ; V_44 ++ ) {
V_200 -> V_476 [ V_44 ] . V_477 =
V_3 -> V_5 . V_6 . V_40 . V_475 . V_42 [ V_44 ] . V_175 ;
V_200 -> V_476 [ V_44 ] . V_478 =
( T_2 ) V_3 -> V_5 . V_6 . V_40 . V_475 . V_42 [ V_44 ] . V_375 * V_31 ;
V_200 -> V_476 [ V_44 ] . V_479 = 1 ;
V_72 = F_128 ( V_3 ,
V_470 ,
V_200 -> V_476 [ V_44 ] . V_477 , false , & V_460 ) ;
if ( V_72 )
return V_72 ;
V_200 -> V_476 [ V_44 ] . V_480 = ( T_1 ) V_460 . V_472 ;
V_200 -> V_476 [ V_44 ] . V_477 = F_16 ( V_200 -> V_476 [ V_44 ] . V_477 ) ;
V_200 -> V_476 [ V_44 ] . V_478 = F_9 ( V_200 -> V_476 [ V_44 ] . V_478 ) ;
}
return V_72 ;
}
static int F_130 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
T_3 V_44 ;
struct V_459 V_460 ;
int V_72 = - V_43 ;
V_200 -> V_481 = ( T_1 )
( V_3 -> V_5 . V_6 . V_40 . V_482 . V_44 ) ;
for ( V_44 = 0 ; V_44 < V_200 -> V_481 ; V_44 ++ ) {
V_200 -> V_483 [ V_44 ] . V_477 =
V_3 -> V_5 . V_6 . V_40 . V_482 . V_42 [ V_44 ] . V_408 ;
V_200 -> V_483 [ V_44 ] . V_478 =
V_3 -> V_5 . V_6 . V_40 . V_482 . V_42 [ V_44 ] . V_375 ;
V_200 -> V_483 [ V_44 ] . V_479 = 1 ;
V_72 = F_128 ( V_3 ,
V_470 ,
V_200 -> V_483 [ V_44 ] . V_477 , false , & V_460 ) ;
if ( V_72 )
return V_72 ;
V_200 -> V_483 [ V_44 ] . V_480 = ( T_1 ) V_460 . V_472 ;
V_200 -> V_483 [ V_44 ] . V_477 = F_16 ( V_200 -> V_483 [ V_44 ] . V_477 ) ;
V_200 -> V_483 [ V_44 ] . V_478 = F_9 ( V_200 -> V_483 [ V_44 ] . V_478 ) ;
}
return V_72 ;
}
static int F_131 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
T_3 V_44 ;
struct V_459 V_460 ;
int V_72 = - V_43 ;
V_200 -> V_484 =
V_3 -> V_5 . V_6 . V_40 . V_485 . V_44 ;
for ( V_44 = 0 ; V_44 < V_200 -> V_484 ; V_44 ++ ) {
V_200 -> V_486 [ V_44 ] . V_477 =
V_3 -> V_5 . V_6 . V_40 . V_485 . V_42 [ V_44 ] . V_408 ;
V_200 -> V_486 [ V_44 ] . V_478 =
V_3 -> V_5 . V_6 . V_40 . V_485 . V_42 [ V_44 ] . V_375 * V_31 ;
V_200 -> V_486 [ V_44 ] . V_479 = 1 ;
V_72 = F_128 ( V_3 ,
V_470 ,
V_200 -> V_486 [ V_44 ] . V_477 , false , & V_460 ) ;
if ( V_72 )
return V_72 ;
V_200 -> V_486 [ V_44 ] . V_480 = ( T_1 ) V_460 . V_472 ;
V_200 -> V_486 [ V_44 ] . V_477 = F_16 ( V_200 -> V_486 [ V_44 ] . V_477 ) ;
V_200 -> V_486 [ V_44 ] . V_478 = F_9 ( V_200 -> V_486 [ V_44 ] . V_478 ) ;
}
return V_72 ;
}
static int F_132 ( struct V_2 * V_3 ,
T_3 V_487 ,
T_11 * V_173 ,
bool V_488 ,
bool V_489 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_302 = V_4 -> V_289 . V_302 ;
T_3 V_304 = V_4 -> V_289 . V_304 ;
T_3 V_306 = V_4 -> V_289 . V_306 ;
T_3 V_308 = V_4 -> V_289 . V_308 ;
T_3 V_310 = V_4 -> V_289 . V_310 ;
T_3 V_312 = V_4 -> V_289 . V_312 ;
T_3 V_314 = V_4 -> V_289 . V_314 ;
T_3 V_316 = V_4 -> V_289 . V_316 ;
T_3 V_318 = V_4 -> V_289 . V_318 ;
struct V_490 V_491 ;
int V_72 ;
V_72 = F_133 ( V_3 , V_487 , V_488 , & V_491 ) ;
if ( V_72 )
return V_72 ;
V_310 &= ~ V_492 ;
V_310 |= F_134 ( V_491 . V_493 ) ;
V_312 &= ~ ( V_494 | V_495 | V_496 ) ;
V_312 |= F_135 ( V_491 . V_497 ) |
F_136 ( V_491 . V_498 ) | F_137 ( V_491 . V_499 ) ;
V_306 &= ~ V_500 ;
V_306 |= F_138 ( V_491 . V_501 ) ;
if ( V_4 -> V_168 ) {
V_308 &= ~ ( V_502 | V_500 ) ;
V_308 |= F_139 ( V_491 . V_503 ) |
F_138 ( V_491 . V_501 ) ;
}
if ( V_4 -> V_504 ) {
struct V_505 V_506 ;
T_3 V_507 ;
T_3 V_193 ;
T_3 V_508 = V_3 -> clock . V_509 . V_332 ;
if ( V_4 -> V_168 )
V_507 = V_487 * 4 ;
else
V_507 = V_487 * 2 ;
V_193 = ( V_507 / V_508 ) ;
V_193 = V_193 * V_193 ;
if ( F_140 ( V_3 , & V_506 ,
V_510 , V_507 ) ) {
T_3 V_511 = V_508 * 5 / V_506 . V_512 ;
T_3 V_513 = ( T_3 ) ( ( ( ( 131 * V_506 . V_514 * V_506 . V_512 ) / 100 ) * V_193 ) / V_507 ) ;
V_316 &= ~ V_515 ;
V_316 |= F_141 ( V_513 ) ;
V_318 &= ~ V_516 ;
V_318 |= F_142 ( V_511 ) ;
}
}
V_304 &= ~ V_517 ;
V_304 |= F_143 ( V_491 . V_518 ) ;
if ( V_489 )
V_304 |= V_519 | V_520 ;
else
V_304 &= ~ ( V_519 | V_520 ) ;
V_173 -> V_521 = V_487 ;
V_173 -> V_522 = V_310 ;
V_173 -> V_523 = V_312 ;
V_173 -> V_524 = V_314 ;
V_173 -> V_525 = V_306 ;
V_173 -> V_526 = V_308 ;
V_173 -> V_527 = V_304 ;
V_173 -> V_528 = V_302 ;
V_173 -> V_529 = V_316 ;
V_173 -> V_530 = V_318 ;
return 0 ;
}
static int F_144 ( struct V_2 * V_3 ,
T_3 V_487 ,
T_11 * V_531 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
bool V_489 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_382 . V_42 ) {
V_72 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_382 ,
V_487 , & V_531 -> V_468 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_3 -> V_5 . V_6 . V_40 . V_387 . V_42 ) {
V_72 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_387 ,
V_487 , & V_531 -> V_532 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_3 -> V_5 . V_6 . V_40 . V_392 . V_42 ) {
V_72 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_392 ,
V_487 , & V_531 -> V_533 ) ;
if ( V_72 )
return V_72 ;
}
V_531 -> V_469 = 1 ;
if ( V_4 -> V_534 )
F_111 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_535 ,
V_487 ,
& V_531 -> V_469 ) ;
V_531 -> V_536 = 1 ;
V_531 -> V_453 = 1 ;
V_531 -> V_537 = 0 ;
V_531 -> V_538 = 100 ;
V_531 -> V_539 = 0 ;
V_531 -> V_540 = ( T_2 ) V_4 -> V_541 ;
V_531 -> V_542 = false ;
V_531 -> V_543 = false ;
V_531 -> V_544 = false ;
V_531 -> V_545 = false ;
V_531 -> V_546 = false ;
V_531 -> V_547 = V_548 ;
if ( V_4 -> V_549 &&
( V_487 <= V_4 -> V_549 ) &&
( V_4 -> V_550 == false ) &&
( F_24 ( V_551 ) & V_552 ) &&
( V_3 -> V_5 . V_6 . V_179 <= 2 ) )
V_531 -> V_542 = true ;
if ( V_4 -> V_553 &&
( V_487 <= V_4 -> V_553 ) )
V_531 -> V_543 = 1 ;
if ( V_4 -> V_168 ) {
V_531 -> V_554 =
F_145 ( V_487 , V_531 -> V_543 ) ;
if ( V_4 -> V_555 &&
( V_487 > V_4 -> V_555 ) )
V_531 -> V_544 = true ;
if ( V_4 -> V_556 &&
( V_487 > V_4 -> V_556 ) )
V_531 -> V_545 = true ;
if ( V_531 -> V_543 ) {
if ( F_145 ( V_487 , true ) >=
( ( F_24 ( V_557 ) >> 16 ) & 0xf ) )
V_489 = ( ( F_24 ( V_558 ) >> 1 ) & 0x1 ) ? true : false ;
else
V_489 = ( ( F_24 ( V_559 ) >> 1 ) & 0x1 ) ? true : false ;
} else {
V_489 = V_4 -> V_560 ;
}
} else {
V_531 -> V_554 = F_146 ( V_487 ) ;
V_489 = ( ( F_24 ( V_558 ) >> 1 ) & 0x1 ) ? true : false ;
}
V_72 = F_132 ( V_3 , V_487 , V_531 , V_531 -> V_543 , V_489 ) ;
if ( V_72 )
return V_72 ;
V_531 -> V_468 = F_16 ( V_531 -> V_468 * V_31 ) ;
V_531 -> V_469 = F_16 ( V_531 -> V_469 ) ;
V_531 -> V_532 = F_16 ( V_531 -> V_532 * V_31 ) ;
V_531 -> V_533 = F_16 ( V_531 -> V_533 * V_31 ) ;
V_531 -> V_521 = F_16 ( V_531 -> V_521 ) ;
V_531 -> V_540 = F_9 ( V_531 -> V_540 ) ;
V_531 -> V_522 = F_16 ( V_531 -> V_522 ) ;
V_531 -> V_523 = F_16 ( V_531 -> V_523 ) ;
V_531 -> V_524 = F_16 ( V_531 -> V_524 ) ;
V_531 -> V_525 = F_16 ( V_531 -> V_525 ) ;
V_531 -> V_526 = F_16 ( V_531 -> V_526 ) ;
V_531 -> V_527 = F_16 ( V_531 -> V_527 ) ;
V_531 -> V_528 = F_16 ( V_531 -> V_528 ) ;
V_531 -> V_529 = F_16 ( V_531 -> V_529 ) ;
V_531 -> V_530 = F_16 ( V_531 -> V_530 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 ,
T_4 * V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_459 V_460 ;
T_8 V_561 ;
T_3 V_562 = V_4 -> V_289 . V_290 ;
T_3 V_563 = V_4 -> V_289 . V_292 ;
T_3 V_302 = V_4 -> V_289 . V_302 ;
T_3 V_304 = V_4 -> V_289 . V_304 ;
int V_72 ;
V_200 -> V_564 . V_565 &= ~ V_566 ;
if ( V_4 -> V_567 )
V_200 -> V_564 . V_468 = F_16 ( V_4 -> V_567 * V_31 ) ;
else
V_200 -> V_564 . V_468 = F_16 ( V_4 -> V_568 * V_31 ) ;
V_200 -> V_564 . V_469 = V_4 -> V_534 ? 0 : 1 ;
V_200 -> V_564 . V_569 = V_3 -> clock . V_331 . V_332 ;
V_72 = F_128 ( V_3 ,
V_570 ,
V_200 -> V_564 . V_569 , false , & V_460 ) ;
if ( V_72 )
return V_72 ;
V_200 -> V_564 . V_571 = ( T_1 ) V_460 . V_472 ;
V_200 -> V_564 . V_547 = V_548 ;
V_200 -> V_564 . V_572 = 0 ;
V_562 &= ~ V_573 ;
V_562 |= V_574 ;
V_563 &= ~ V_575 ;
V_563 |= F_148 ( 4 ) ;
V_200 -> V_564 . V_576 = V_562 ;
V_200 -> V_564 . V_577 = V_563 ;
V_200 -> V_564 . V_578 = V_4 -> V_289 . V_294 ;
V_200 -> V_564 . V_579 = V_4 -> V_289 . V_296 ;
V_200 -> V_564 . V_580 = V_4 -> V_289 . V_298 ;
V_200 -> V_564 . V_581 = V_4 -> V_289 . V_300 ;
V_200 -> V_564 . V_582 = 0 ;
V_200 -> V_564 . V_583 = 0 ;
V_200 -> V_564 . V_565 = F_16 ( V_200 -> V_564 . V_565 ) ;
V_200 -> V_564 . V_469 = F_16 ( V_200 -> V_564 . V_469 ) ;
V_200 -> V_564 . V_569 = F_16 ( V_200 -> V_564 . V_569 ) ;
V_200 -> V_564 . V_576 = F_16 ( V_200 -> V_564 . V_576 ) ;
V_200 -> V_564 . V_577 = F_16 ( V_200 -> V_564 . V_577 ) ;
V_200 -> V_564 . V_578 = F_16 ( V_200 -> V_564 . V_578 ) ;
V_200 -> V_564 . V_579 = F_16 ( V_200 -> V_564 . V_579 ) ;
V_200 -> V_564 . V_580 = F_16 ( V_200 -> V_564 . V_580 ) ;
V_200 -> V_564 . V_581 = F_16 ( V_200 -> V_564 . V_581 ) ;
V_200 -> V_564 . V_582 = F_16 ( V_200 -> V_564 . V_582 ) ;
V_200 -> V_564 . V_583 = F_16 ( V_200 -> V_564 . V_583 ) ;
V_200 -> V_584 . V_468 = V_200 -> V_564 . V_468 ;
V_200 -> V_584 . V_469 = V_200 -> V_564 . V_469 ;
if ( V_4 -> V_384 != V_407 ) {
if ( V_4 -> V_585 )
V_200 -> V_584 . V_532 =
F_16 ( V_4 -> V_585 * V_31 ) ;
else
V_200 -> V_584 . V_532 =
F_16 ( V_4 -> V_586 * V_31 ) ;
}
if ( F_109 ( V_3 , 0 , & V_561 ) )
V_200 -> V_584 . V_533 = 0 ;
else
V_200 -> V_584 . V_533 =
F_16 ( V_561 . V_398 * V_31 ) ;
V_304 |= V_587 | V_588 ;
V_304 &= ~ ( V_519 | V_520 ) ;
V_302 &= ~ ( V_589 | V_590 ) ;
V_200 -> V_584 . V_528 = F_16 ( V_302 ) ;
V_200 -> V_584 . V_527 = F_16 ( V_304 ) ;
V_200 -> V_584 . V_525 =
F_16 ( V_4 -> V_289 . V_306 ) ;
V_200 -> V_584 . V_526 =
F_16 ( V_4 -> V_289 . V_308 ) ;
V_200 -> V_584 . V_522 =
F_16 ( V_4 -> V_289 . V_310 ) ;
V_200 -> V_584 . V_523 =
F_16 ( V_4 -> V_289 . V_312 ) ;
V_200 -> V_584 . V_524 =
F_16 ( V_4 -> V_289 . V_314 ) ;
V_200 -> V_584 . V_529 = F_16 ( V_4 -> V_289 . V_316 ) ;
V_200 -> V_584 . V_530 = F_16 ( V_4 -> V_289 . V_318 ) ;
V_200 -> V_584 . V_536 = 0 ;
V_200 -> V_584 . V_453 = 0 ;
V_200 -> V_584 . V_537 = 0 ;
V_200 -> V_584 . V_538 = 100 ;
V_200 -> V_584 . V_539 = 0 ;
V_200 -> V_584 . V_540 =
F_9 ( ( T_2 ) V_4 -> V_541 ) ;
V_200 -> V_584 . V_542 = false ;
V_200 -> V_584 . V_543 = false ;
V_200 -> V_584 . V_544 = false ;
V_200 -> V_584 . V_545 = false ;
V_200 -> V_584 . V_546 = false ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_591 * V_592 = & V_4 -> V_592 ;
if ( V_592 -> V_593 ) {
if ( V_125 )
return ( F_31 ( V_3 , V_594 ) == V_146 ) ?
0 : - V_43 ;
else
return ( F_31 ( V_3 , V_595 ) == V_146 ) ?
0 : - V_43 ;
}
return 0 ;
}
static int F_150 ( struct V_2 * V_3 ,
T_12 * V_596 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_597 = V_3 -> V_5 . V_6 . V_598 ;
V_596 -> V_582 = 0 ;
V_596 -> V_583 = 0 ;
if ( V_597 == 0 ) {
V_4 -> V_592 . V_593 = false ;
return 0 ;
}
if ( V_4 -> V_377 != V_381 ) {
if ( V_597 > V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ 0 ] . V_375 )
V_596 -> V_599 = 0 ;
else
V_596 -> V_599 =
V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ 0 ] . V_375 - V_597 ;
} else {
if ( V_597 > V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ 0 ] . V_375 )
V_596 -> V_600 = 0 ;
else
V_596 -> V_600 = ( T_1 )
( ( V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ 0 ] . V_375 - V_597 ) *
V_601 / V_602 ) ;
}
V_596 -> V_603 = V_4 -> V_534 ? 0 : 1 ;
V_596 -> V_582 = F_16 ( V_596 -> V_582 ) ;
V_596 -> V_583 = F_16 ( V_596 -> V_583 ) ;
V_596 -> V_599 = F_9 ( V_596 -> V_599 ) ;
return 0 ;
}
static int F_151 ( struct V_2 * V_3 ,
T_3 V_604 ,
T_13 * V_172 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_459 V_460 ;
T_3 V_605 = V_4 -> V_289 . V_294 ;
T_3 V_606 = V_4 -> V_289 . V_296 ;
T_3 V_298 = V_4 -> V_289 . V_298 ;
T_3 V_300 = V_4 -> V_289 . V_300 ;
T_3 V_508 = V_3 -> clock . V_331 . V_332 ;
T_3 V_607 ;
T_3 V_608 ;
int V_72 ;
V_72 = F_128 ( V_3 ,
V_570 ,
V_604 , false , & V_460 ) ;
if ( V_72 )
return V_72 ;
V_607 = 1 + V_460 . V_609 ;
V_608 = V_460 . V_610 & 0x3FFFFFF ;
V_605 &= ~ V_611 ;
V_605 |= F_152 ( V_608 ) ;
V_605 |= V_612 ;
if ( V_4 -> V_340 ) {
struct V_505 V_506 ;
T_3 V_613 = V_604 * V_460 . V_501 ;
if ( F_140 ( V_3 , & V_506 ,
V_614 , V_613 ) ) {
T_3 V_615 = V_508 * 5 / ( V_607 * V_506 . V_512 ) ;
T_3 V_616 = 4 * V_506 . V_514 * V_608 / ( V_615 * 10000 ) ;
V_298 &= ~ V_617 ;
V_298 |= F_153 ( V_615 ) ;
V_298 |= V_342 ;
V_300 &= ~ V_618 ;
V_300 |= F_154 ( V_616 ) ;
}
}
V_172 -> V_569 = V_604 ;
V_172 -> V_578 = V_605 ;
V_172 -> V_579 = V_606 ;
V_172 -> V_580 = V_298 ;
V_172 -> V_581 = V_300 ;
V_172 -> V_571 = ( T_1 ) V_460 . V_472 ;
return 0 ;
}
static int F_155 ( struct V_2 * V_3 ,
T_3 V_604 ,
T_2 V_619 ,
T_13 * V_620 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
V_72 = F_151 ( V_3 , V_604 , V_620 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_45 ,
V_604 , & V_620 -> V_468 ) ;
if ( V_72 )
return V_72 ;
V_620 -> V_569 = V_604 ;
V_620 -> V_565 = 0 ;
V_620 -> V_469 = 1 ;
if ( V_4 -> V_534 )
F_110 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_535 ,
V_604 ,
& V_620 -> V_469 ) ;
V_620 -> V_540 = V_619 ;
V_620 -> V_582 = 0 ;
V_620 -> V_583 = 0 ;
V_620 -> V_453 = 1 ;
V_620 -> V_536 = 1 ;
V_620 -> V_537 = 0 ;
V_620 -> V_538 = 0 ;
V_620 -> V_539 = 0 ;
V_620 -> V_621 = 0 ;
if ( V_4 -> V_324 )
V_620 -> V_572 = F_114 ( V_3 ,
V_604 ,
V_420 ) ;
V_620 -> V_547 = V_548 ;
V_620 -> V_565 = F_16 ( V_620 -> V_565 ) ;
V_620 -> V_468 = F_16 ( V_620 -> V_468 * V_31 ) ;
V_620 -> V_469 = F_16 ( V_620 -> V_469 ) ;
V_620 -> V_569 = F_16 ( V_620 -> V_569 ) ;
V_620 -> V_540 = F_9 ( V_620 -> V_540 ) ;
V_620 -> V_578 = F_16 ( V_620 -> V_578 ) ;
V_620 -> V_579 = F_16 ( V_620 -> V_579 ) ;
V_620 -> V_580 = F_16 ( V_620 -> V_580 ) ;
V_620 -> V_581 = F_16 ( V_620 -> V_581 ) ;
V_620 -> V_582 = F_16 ( V_620 -> V_582 ) ;
V_620 -> V_583 = F_16 ( V_620 -> V_583 ) ;
return 0 ;
}
static int F_156 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_447 * V_91 = & V_4 -> V_91 ;
T_3 V_622 = V_4 -> V_206 +
F_12 ( T_4 , V_623 ) ;
T_3 V_624 = sizeof( T_13 ) *
V_625 ;
T_13 * V_626 = V_4 -> V_92 . V_623 ;
T_3 V_39 , V_72 ;
memset ( V_626 , 0 , V_624 ) ;
for ( V_39 = 0 ; V_39 < V_91 -> V_436 . V_44 ; V_39 ++ ) {
V_72 = F_155 ( V_3 ,
V_91 -> V_436 . V_438 [ V_39 ] . V_55 ,
( T_2 ) V_4 -> V_627 [ V_39 ] ,
& V_4 -> V_92 . V_623 [ V_39 ] ) ;
if ( V_72 )
return V_72 ;
if ( V_39 == ( V_91 -> V_436 . V_44 - 1 ) )
V_4 -> V_92 . V_623 [ V_39 ] . V_547 =
V_628 ;
}
V_4 -> V_92 . V_629 = ( T_1 ) V_91 -> V_436 . V_44 ;
V_4 -> V_457 . V_630 =
F_124 ( & V_91 -> V_436 ) ;
V_72 = F_18 ( V_3 , V_622 ,
( T_1 * ) V_626 , V_624 ,
V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static int F_157 ( struct V_2 * V_3 ,
T_12 * V_631 )
{
return F_150 ( V_3 , V_631 ) ;
}
static int F_158 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_447 * V_91 = & V_4 -> V_91 ;
T_3 V_622 = V_4 -> V_206 +
F_12 ( T_4 , V_632 ) ;
T_3 V_624 = sizeof( T_11 ) *
V_633 ;
T_11 * V_626 = V_4 -> V_92 . V_632 ;
T_3 V_39 , V_72 ;
memset ( V_626 , 0 , V_624 ) ;
for ( V_39 = 0 ; V_39 < V_91 -> V_437 . V_44 ; V_39 ++ ) {
if ( V_91 -> V_437 . V_438 [ V_39 ] . V_55 == 0 )
return - V_43 ;
V_72 = F_144 ( V_3 ,
V_91 -> V_437 . V_438 [ V_39 ] . V_55 ,
& V_4 -> V_92 . V_632 [ V_39 ] ) ;
if ( V_72 )
return V_72 ;
}
V_4 -> V_92 . V_632 [ 0 ] . V_540 = F_9 ( 0x1F ) ;
V_4 -> V_92 . V_634 = ( T_1 ) V_91 -> V_437 . V_44 ;
V_4 -> V_457 . V_635 =
F_124 ( & V_91 -> V_437 ) ;
V_4 -> V_92 . V_632 [ V_91 -> V_437 . V_44 - 1 ] . V_547 =
V_628 ;
V_72 = F_18 ( V_3 , V_622 ,
( T_1 * ) V_626 , V_624 ,
V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static void F_159 ( struct V_2 * V_3 ,
struct V_444 * V_91 ,
T_3 V_44 )
{
T_3 V_39 ;
V_91 -> V_44 = V_44 ;
for ( V_39 = 0 ; V_39 < V_636 ; V_39 ++ )
V_91 -> V_438 [ V_39 ] . V_446 = false ;
}
static void F_160 ( struct V_444 * V_91 ,
T_3 V_637 , T_3 V_638 , T_3 V_639 )
{
V_91 -> V_438 [ V_637 ] . V_55 = V_638 ;
V_91 -> V_438 [ V_637 ] . V_452 = V_639 ;
V_91 -> V_438 [ V_637 ] . V_446 = true ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_640 && ! V_4 -> V_641 )
return - V_43 ;
if ( V_4 -> V_640 && ! V_4 -> V_641 ) {
V_4 -> V_642 = V_4 -> V_643 ;
V_4 -> V_644 = V_4 -> V_645 ;
} else if ( ! V_4 -> V_640 && V_4 -> V_641 ) {
V_4 -> V_643 = V_4 -> V_642 ;
V_4 -> V_645 = V_4 -> V_644 ;
}
F_159 ( V_3 ,
& V_4 -> V_91 . V_448 ,
V_646 ) ;
F_160 ( & V_4 -> V_91 . V_448 , 0 ,
V_4 -> V_642 . V_80 ,
V_4 -> V_644 . V_80 ) ;
F_160 ( & V_4 -> V_91 . V_448 , 1 ,
V_4 -> V_643 . V_80 ,
V_4 -> V_645 . V_80 ) ;
F_160 ( & V_4 -> V_91 . V_448 , 2 ,
V_4 -> V_642 . V_80 ,
V_4 -> V_644 . V_81 ) ;
F_160 ( & V_4 -> V_91 . V_448 , 3 ,
V_4 -> V_643 . V_80 ,
V_4 -> V_645 . V_81 ) ;
F_160 ( & V_4 -> V_91 . V_448 , 4 ,
V_4 -> V_642 . V_81 ,
V_4 -> V_644 . V_81 ) ;
F_160 ( & V_4 -> V_91 . V_448 , 5 ,
V_4 -> V_643 . V_81 ,
V_4 -> V_645 . V_81 ) ;
V_4 -> V_91 . V_448 . V_44 = 6 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_369 * V_647 =
& V_3 -> V_5 . V_6 . V_40 . V_45 ;
struct V_369 * V_648 =
& V_3 -> V_5 . V_6 . V_40 . V_382 ;
struct V_649 * V_650 =
& V_3 -> V_5 . V_6 . V_40 . V_41 ;
T_3 V_39 ;
if ( V_647 == NULL )
return - V_43 ;
if ( V_647 -> V_44 < 1 )
return - V_43 ;
if ( V_648 == NULL )
return - V_43 ;
if ( V_648 -> V_44 < 1 )
return - V_43 ;
memset ( & V_4 -> V_91 , 0 , sizeof( struct V_447 ) ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_436 ,
V_625 ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_437 ,
V_633 ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_651 ,
V_383 ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_652 ,
V_388 ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_653 ,
V_393 ) ;
V_4 -> V_91 . V_436 . V_44 = 0 ;
for ( V_39 = 0 ; V_39 < V_647 -> V_44 ; V_39 ++ ) {
if ( ( V_39 == 0 ) ||
( V_4 -> V_91 . V_436 . V_438 [ V_4 -> V_91 . V_436 . V_44 - 1 ] . V_55 !=
V_647 -> V_42 [ V_39 ] . V_408 ) ) {
V_4 -> V_91 . V_436 . V_438 [ V_4 -> V_91 . V_436 . V_44 ] . V_55 =
V_647 -> V_42 [ V_39 ] . V_408 ;
V_4 -> V_91 . V_436 . V_438 [ V_4 -> V_91 . V_436 . V_44 ] . V_446 = true ;
V_4 -> V_91 . V_436 . V_44 ++ ;
}
}
V_4 -> V_91 . V_437 . V_44 = 0 ;
for ( V_39 = 0 ; V_39 < V_648 -> V_44 ; V_39 ++ ) {
if ( ( V_39 == 0 ) ||
( V_4 -> V_91 . V_437 . V_438 [ V_4 -> V_91 . V_437 . V_44 - 1 ] . V_55 !=
V_648 -> V_42 [ V_39 ] . V_408 ) ) {
V_4 -> V_91 . V_437 . V_438 [ V_4 -> V_91 . V_437 . V_44 ] . V_55 =
V_648 -> V_42 [ V_39 ] . V_408 ;
V_4 -> V_91 . V_437 . V_438 [ V_4 -> V_91 . V_437 . V_44 ] . V_446 = true ;
V_4 -> V_91 . V_437 . V_44 ++ ;
}
}
for ( V_39 = 0 ; V_39 < V_647 -> V_44 ; V_39 ++ ) {
V_4 -> V_91 . V_651 . V_438 [ V_39 ] . V_55 =
V_647 -> V_42 [ V_39 ] . V_375 ;
V_4 -> V_91 . V_651 . V_438 [ V_39 ] . V_452 =
V_650 -> V_42 [ V_39 ] . V_51 ;
V_4 -> V_91 . V_651 . V_438 [ V_39 ] . V_446 = true ;
}
V_4 -> V_91 . V_651 . V_44 = V_647 -> V_44 ;
V_648 = & V_3 -> V_5 . V_6 . V_40 . V_387 ;
if ( V_648 ) {
for ( V_39 = 0 ; V_39 < V_648 -> V_44 ; V_39 ++ ) {
V_4 -> V_91 . V_652 . V_438 [ V_39 ] . V_55 =
V_648 -> V_42 [ V_39 ] . V_375 ;
V_4 -> V_91 . V_652 . V_438 [ V_39 ] . V_446 = true ;
}
V_4 -> V_91 . V_652 . V_44 = V_648 -> V_44 ;
}
V_648 = & V_3 -> V_5 . V_6 . V_40 . V_392 ;
if ( V_648 ) {
for ( V_39 = 0 ; V_39 < V_648 -> V_44 ; V_39 ++ ) {
V_4 -> V_91 . V_653 . V_438 [ V_39 ] . V_55 =
V_648 -> V_42 [ V_39 ] . V_375 ;
V_4 -> V_91 . V_653 . V_438 [ V_39 ] . V_446 = true ;
}
V_4 -> V_91 . V_653 . V_44 = V_648 -> V_44 ;
}
F_161 ( V_3 ) ;
return 0 ;
}
static int F_163 ( struct V_444 * V_200 ,
T_3 V_55 , T_3 * V_654 )
{
T_3 V_39 ;
int V_72 = - V_43 ;
for( V_39 = 0 ; V_39 < V_200 -> V_44 ; V_39 ++ ) {
if ( V_55 == V_200 -> V_438 [ V_39 ] . V_55 ) {
* V_654 = V_39 ;
V_72 = 0 ;
}
}
return V_72 ;
}
static int F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_591 * V_592 = & V_4 -> V_592 ;
struct V_9 * V_439 = V_3 -> V_5 . V_6 . V_655 ;
T_4 * V_200 = & V_4 -> V_92 ;
int V_72 ;
V_72 = F_162 ( V_3 ) ;
if ( V_72 )
return V_72 ;
if ( V_4 -> V_377 != V_407 )
F_108 ( V_3 , V_200 ) ;
F_47 ( V_3 ) ;
if ( V_3 -> V_5 . V_6 . V_46 & V_656 )
V_200 -> V_657 |= V_658 ;
if ( V_3 -> V_5 . V_6 . V_46 & V_659 )
V_200 -> V_657 |= V_660 ;
if ( V_4 -> V_168 )
V_200 -> V_657 |= V_661 ;
if ( V_592 -> V_593 ) {
V_72 = F_157 ( V_3 , & V_4 -> V_92 . V_662 ) ;
if ( V_72 )
return V_72 ;
F_25 ( V_663 , V_592 -> V_664 ) ;
}
V_72 = F_156 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_158 ( V_3 ) ;
if ( V_72 )
return V_72 ;
F_125 ( V_3 , V_200 ) ;
V_72 = F_147 ( V_3 , V_200 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_129 ( V_3 , V_200 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_130 ( V_3 , V_200 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_131 ( V_3 , V_200 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_121 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_127 ( V_3 , V_200 ) ;
if ( V_72 )
return V_72 ;
V_200 -> V_665 = 0 ;
V_200 -> V_666 = 0 ;
V_200 -> V_667 = 0 ;
V_200 -> V_668 = 0 ;
V_200 -> V_442 = 0 ;
V_200 -> V_443 = 0 ;
V_72 = F_163 ( & V_4 -> V_91 . V_436 ,
V_4 -> V_669 . V_670 ,
( T_3 * ) & V_4 -> V_92 . V_442 ) ;
V_72 = F_163 ( & V_4 -> V_91 . V_437 ,
V_4 -> V_669 . V_671 ,
( T_3 * ) & V_4 -> V_92 . V_443 ) ;
V_200 -> V_672 = V_4 -> V_669 . V_673 ;
V_200 -> V_674 = V_4 -> V_669 . V_675 ;
V_200 -> V_676 = V_4 -> V_669 . V_677 ;
F_123 ( V_3 , V_439 ) ;
V_72 = F_15 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_200 -> V_678 = 1 ;
V_200 -> V_679 = 1 ;
V_200 -> V_680 = 1 ;
V_200 -> V_681 = 1 ;
V_200 -> V_682 = 1 ;
V_200 -> V_683 = 1 ;
V_200 -> V_684 = 1 ;
V_200 -> V_685 = 1 ;
V_200 -> V_686 = 1 ;
V_200 -> V_687 = ( T_2 ) ( ( V_4 -> V_106 . V_107 *
V_688 ) / 1000 ) ;
V_200 -> V_689 = ( T_2 ) ( ( V_4 -> V_106 . V_690 *
V_688 ) / 1000 ) ;
V_200 -> V_691 = 1 ;
V_200 -> V_692 = 1 ;
V_200 -> V_693 = 0 ;
V_200 -> V_694 = 4000 ;
V_200 -> V_695 = 0 ;
V_200 -> V_696 = 1 ;
V_200 -> V_697 = 0 ;
V_200 -> V_698 = 1 ;
if ( V_4 -> V_377 == V_381 )
V_200 -> V_699 = 1 ;
else
V_200 -> V_699 = 0 ;
V_200 -> V_700 = 17 ;
V_200 -> V_701 = 0x4000 ;
V_200 -> V_657 = F_16 ( V_200 -> V_657 ) ;
V_200 -> V_702 = F_16 ( V_200 -> V_702 ) ;
V_200 -> V_703 = F_16 ( V_200 -> V_703 ) ;
V_200 -> V_704 = F_16 ( V_200 -> V_704 ) ;
V_200 -> V_705 = F_16 ( V_200 -> V_705 ) ;
V_200 -> V_701 = F_16 ( V_200 -> V_701 ) ;
V_200 -> V_687 = F_9 ( V_200 -> V_687 ) ;
V_200 -> V_689 = F_9 ( V_200 -> V_689 ) ;
V_200 -> V_694 = F_9 ( V_200 -> V_694 ) ;
V_200 -> V_693 = F_9 ( V_200 -> V_693 ) ;
V_200 -> V_695 = F_9 ( V_200 -> V_695 ) ;
V_200 -> V_672 = F_9 ( V_200 -> V_672 * V_31 ) ;
V_200 -> V_674 = F_9 ( V_200 -> V_674 * V_31 ) ;
V_200 -> V_676 = F_9 ( V_200 -> V_676 * V_31 ) ;
V_72 = F_18 ( V_3 ,
V_4 -> V_206 +
F_12 ( T_4 , V_657 ) ,
( T_1 * ) & V_200 -> V_657 ,
sizeof( T_4 ) - 3 * sizeof( V_706 ) ,
V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static void F_165 ( struct V_2 * V_3 ,
struct V_444 * V_91 ,
T_3 V_707 , T_3 V_708 )
{
T_3 V_39 ;
for ( V_39 = 0 ; V_39 < V_91 -> V_44 ; V_39 ++ ) {
if ( ( V_91 -> V_438 [ V_39 ] . V_55 < V_707 ) ||
( V_91 -> V_438 [ V_39 ] . V_55 > V_708 ) )
V_91 -> V_438 [ V_39 ] . V_446 = false ;
else
V_91 -> V_438 [ V_39 ] . V_446 = true ;
}
}
static void F_166 ( struct V_2 * V_3 ,
T_3 V_709 , T_3 V_710 ,
T_3 V_711 , T_3 V_712 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_444 * V_713 = & V_4 -> V_91 . V_448 ;
T_3 V_39 , V_96 ;
for ( V_39 = 0 ; V_39 < V_713 -> V_44 ; V_39 ++ ) {
if ( ( V_713 -> V_438 [ V_39 ] . V_55 < V_709 ) ||
( V_713 -> V_438 [ V_39 ] . V_452 < V_710 ) ||
( V_713 -> V_438 [ V_39 ] . V_55 > V_711 ) ||
( V_713 -> V_438 [ V_39 ] . V_452 > V_712 ) )
V_713 -> V_438 [ V_39 ] . V_446 = false ;
else
V_713 -> V_438 [ V_39 ] . V_446 = true ;
}
for ( V_39 = 0 ; V_39 < V_713 -> V_44 ; V_39 ++ ) {
if ( V_713 -> V_438 [ V_39 ] . V_446 ) {
for ( V_96 = V_39 + 1 ; V_96 < V_713 -> V_44 ; V_96 ++ ) {
if ( V_713 -> V_438 [ V_96 ] . V_446 ) {
if ( ( V_713 -> V_438 [ V_39 ] . V_55 == V_713 -> V_438 [ V_96 ] . V_55 ) &&
( V_713 -> V_438 [ V_39 ] . V_452 == V_713 -> V_438 [ V_96 ] . V_452 ) )
V_713 -> V_438 [ V_96 ] . V_446 = false ;
}
}
}
}
}
static int F_167 ( struct V_2 * V_3 ,
struct V_9 * V_714 )
{
struct V_8 * V_596 = F_2 ( V_714 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_715 ;
if ( V_596 -> V_187 < 1 )
return - V_43 ;
if ( V_596 -> V_187 == 1 )
V_715 = 0 ;
else
V_715 = 1 ;
F_165 ( V_3 ,
& V_4 -> V_91 . V_436 ,
V_596 -> V_188 [ 0 ] . V_172 ,
V_596 -> V_188 [ V_715 ] . V_172 ) ;
F_165 ( V_3 ,
& V_4 -> V_91 . V_437 ,
V_596 -> V_188 [ 0 ] . V_173 ,
V_596 -> V_188 [ V_715 ] . V_173 ) ;
F_166 ( V_3 ,
V_596 -> V_188 [ 0 ] . V_638 ,
V_596 -> V_188 [ 0 ] . V_716 ,
V_596 -> V_188 [ V_715 ] . V_638 ,
V_596 -> V_188 [ V_715 ] . V_716 ) ;
return 0 ;
}
static int F_168 ( struct V_2 * V_3 )
{
struct V_369 * V_717 =
& V_3 -> V_5 . V_6 . V_40 . V_718 ;
struct V_369 * V_651 =
& V_3 -> V_5 . V_6 . V_40 . V_45 ;
T_3 V_719 = 0 ;
T_3 V_39 ;
if ( V_717 == NULL )
return - V_43 ;
if ( ! V_717 -> V_44 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_717 -> V_44 ; V_39 ++ ) {
if ( V_3 -> clock . V_720 == V_717 -> V_42 [ V_39 ] . V_408 )
V_719 = V_717 -> V_42 [ V_39 ] . V_375 ;
}
for ( V_39 = 0 ; V_39 < V_651 -> V_44 ; V_39 ++ ) {
if ( V_719 <= V_651 -> V_42 [ V_39 ] . V_375 ) {
V_719 = V_651 -> V_42 [ V_39 ] . V_375 ;
return ( F_64 ( V_3 ,
V_721 ,
V_719 * V_31 ) == V_146 ) ?
0 : - V_43 ;
}
}
return - V_43 ;
}
static int F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_722 ;
if ( ! V_4 -> V_234 ) {
if ( V_4 -> V_457 . V_630 ) {
V_722 = F_64 ( V_3 ,
V_723 ,
V_4 -> V_457 . V_630 ) ;
if ( V_722 != V_146 )
return - V_43 ;
}
}
if ( ! V_4 -> V_238 ) {
if ( V_4 -> V_457 . V_635 ) {
V_722 = F_64 ( V_3 ,
V_724 ,
V_4 -> V_457 . V_635 ) ;
if ( V_722 != V_146 )
return - V_43 ;
}
}
if ( ! V_4 -> V_258 ) {
if ( V_4 -> V_457 . V_458 ) {
V_722 = F_64 ( V_3 ,
V_725 ,
V_4 -> V_457 . V_458 ) ;
if ( V_722 != V_146 )
return - V_43 ;
}
}
F_168 ( V_3 ) ;
return 0 ;
}
static void F_170 ( struct V_2 * V_3 ,
struct V_9 * V_714 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_596 = F_2 ( V_714 ) ;
struct V_444 * V_436 = & V_4 -> V_91 . V_436 ;
T_3 V_172 = V_596 -> V_188 [ V_596 -> V_187 - 1 ] . V_172 ;
struct V_444 * V_437 = & V_4 -> V_91 . V_437 ;
T_3 V_173 = V_596 -> V_188 [ V_596 -> V_187 - 1 ] . V_173 ;
T_3 V_39 ;
V_4 -> V_233 = 0 ;
for ( V_39 = 0 ; V_39 < V_436 -> V_44 ; V_39 ++ ) {
if ( V_172 == V_436 -> V_438 [ V_39 ] . V_55 )
break;
}
if ( V_39 >= V_436 -> V_44 ) {
V_4 -> V_233 |= V_235 ;
} else {
if ( 0 != V_420 )
V_4 -> V_233 |= V_236 ;
}
for ( V_39 = 0 ; V_39 < V_437 -> V_44 ; V_39 ++ ) {
if ( V_173 == V_437 -> V_438 [ V_39 ] . V_55 )
break;
}
if ( V_39 >= V_437 -> V_44 )
V_4 -> V_233 |= V_239 ;
if ( V_3 -> V_5 . V_6 . V_726 !=
V_3 -> V_5 . V_6 . V_179 )
V_4 -> V_233 |= V_727 ;
}
static int F_171 ( struct V_2 * V_3 ,
struct V_9 * V_714 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_596 = F_2 ( V_714 ) ;
T_3 V_172 = V_596 -> V_188 [ V_596 -> V_187 - 1 ] . V_172 ;
T_3 V_173 = V_596 -> V_188 [ V_596 -> V_187 - 1 ] . V_173 ;
struct V_447 * V_91 = & V_4 -> V_91 ;
int V_72 ;
if ( ! V_4 -> V_233 )
return 0 ;
if ( V_4 -> V_233 & V_235 )
V_91 -> V_436 . V_438 [ V_91 -> V_436 . V_44 - 1 ] . V_55 = V_172 ;
if ( V_4 -> V_233 & V_239 )
V_91 -> V_437 . V_438 [ V_91 -> V_437 . V_44 - 1 ] . V_55 = V_173 ;
if ( V_4 -> V_233 & ( V_235 | V_236 ) ) {
V_72 = F_156 ( V_3 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_4 -> V_233 & ( V_239 | V_727 ) ) {
V_72 = F_158 ( V_3 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_172 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_169 * V_170 ;
int V_39 ;
if ( V_3 -> V_5 . V_6 . V_184 )
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_185 ;
else
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_186 ;
if ( V_125 ) {
V_4 -> V_457 . V_728 = 0 ;
for ( V_39 = V_3 -> V_5 . V_6 . V_40 . V_462 . V_44 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_3 -> V_5 . V_6 . V_40 . V_462 . V_42 [ V_39 ] . V_375 <= V_170 -> V_30 ) {
V_4 -> V_457 . V_728 |= 1 << V_39 ;
if ( ! V_4 -> V_729 )
break;
}
}
F_64 ( V_3 ,
V_730 ,
V_4 -> V_457 . V_728 ) ;
if ( V_4 -> V_731 & 0x1 ) {
V_4 -> V_550 = true ;
V_4 -> V_457 . V_635 &= 0xFFFFFFFE ;
F_64 ( V_3 ,
V_724 ,
V_4 -> V_457 . V_635 ) ;
}
} else {
if ( V_4 -> V_731 & 0x1 ) {
V_4 -> V_550 = false ;
V_4 -> V_457 . V_635 |= 1 ;
F_64 ( V_3 ,
V_724 ,
V_4 -> V_457 . V_635 ) ;
}
}
return ( F_31 ( V_3 , V_125 ?
V_732 : V_733 ) == V_146 ) ?
0 : - V_43 ;
}
static int F_173 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_169 * V_170 ;
int V_39 ;
if ( V_3 -> V_5 . V_6 . V_184 )
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_185 ;
else
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_186 ;
if ( V_125 ) {
V_4 -> V_457 . V_734 = 0 ;
for ( V_39 = V_3 -> V_5 . V_6 . V_40 . V_475 . V_44 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_3 -> V_5 . V_6 . V_40 . V_475 . V_42 [ V_39 ] . V_375 <= V_170 -> V_30 ) {
V_4 -> V_457 . V_734 |= 1 << V_39 ;
if ( ! V_4 -> V_735 )
break;
}
}
F_64 ( V_3 ,
V_736 ,
V_4 -> V_457 . V_734 ) ;
}
return ( F_31 ( V_3 , V_125 ?
V_737 : V_738 ) == V_146 ) ?
0 : - V_43 ;
}
static int F_37 ( struct V_2 * V_3 , bool V_164 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_193 ;
if ( ! V_164 ) {
if ( V_4 -> V_729 ||
( V_3 -> V_5 . V_6 . V_40 . V_462 . V_44 <= 0 ) )
V_4 -> V_92 . V_665 = 0 ;
else
V_4 -> V_92 . V_665 =
V_3 -> V_5 . V_6 . V_40 . V_462 . V_44 - 1 ;
V_193 = F_23 ( V_739 ) ;
V_193 &= ~ V_740 ;
V_193 |= V_665 ( V_4 -> V_92 . V_665 ) ;
F_25 ( V_739 , V_193 ) ;
}
return F_172 ( V_3 , ! V_164 ) ;
}
static T_1 F_174 ( struct V_2 * V_3 )
{
T_1 V_39 ;
T_3 V_741 = 30000 ;
struct V_742 * V_200 =
& V_3 -> V_5 . V_6 . V_40 . V_475 ;
for ( V_39 = 0 ; V_39 < V_200 -> V_44 ; V_39 ++ ) {
if ( V_200 -> V_42 [ V_39 ] . V_175 >= V_741 )
return V_39 ;
}
return V_200 -> V_44 - 1 ;
}
static int F_175 ( struct V_2 * V_3 ,
struct V_9 * V_743 ,
struct V_9 * V_744 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 = 0 ;
T_3 V_193 ;
if ( V_744 -> V_175 != V_743 -> V_175 ) {
if ( V_743 -> V_175 ) {
F_176 ( V_3 , V_745 , false ) ;
V_4 -> V_92 . V_666 = F_174 ( V_3 ) ;
V_193 = F_23 ( V_739 ) ;
V_193 &= ~ V_746 ;
V_193 |= V_666 ( V_4 -> V_92 . V_666 ) ;
F_25 ( V_739 , V_193 ) ;
V_72 = F_173 ( V_3 , true ) ;
} else {
F_176 ( V_3 , V_745 , true ) ;
V_72 = F_173 ( V_3 , false ) ;
}
}
return V_72 ;
}
static int F_177 ( struct V_2 * V_3 ,
struct V_9 * V_714 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
V_72 = F_167 ( V_3 , V_714 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_457 . V_630 =
F_124 ( & V_4 -> V_91 . V_436 ) ;
V_4 -> V_457 . V_635 =
F_124 ( & V_4 -> V_91 . V_437 ) ;
V_4 -> V_731 =
V_4 -> V_457 . V_635 ;
if ( V_4 -> V_550 ) {
if ( V_4 -> V_457 . V_635 & 1 )
V_4 -> V_457 . V_635 &= 0xFFFFFFFE ;
}
V_4 -> V_457 . V_458 =
F_124 ( & V_4 -> V_91 . V_448 ) ;
return 0 ;
}
static T_3 F_178 ( struct V_2 * V_3 ,
T_3 V_747 )
{
T_3 V_441 = 0 ;
while ( ( V_747 & ( 1 << V_441 ) ) == 0 )
V_441 ++ ;
return V_441 ;
}
int F_179 ( struct V_2 * V_3 ,
enum V_748 V_441 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
T_3 V_193 , V_626 , V_39 ;
int V_72 ;
if ( V_441 == V_749 ) {
if ( ( ! V_4 -> V_234 ) &&
V_4 -> V_457 . V_630 ) {
V_626 = 0 ;
V_193 = V_4 -> V_457 . V_630 ;
while ( V_193 >>= 1 )
V_626 ++ ;
if ( V_626 ) {
V_72 = F_66 ( V_3 , V_626 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_278 ; V_39 ++ ) {
V_193 = ( F_23 ( V_750 ) &
V_751 ) >> V_752 ;
if ( V_193 == V_626 )
break;
F_59 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_238 ) &&
V_4 -> V_457 . V_635 ) {
V_626 = 0 ;
V_193 = V_4 -> V_457 . V_635 ;
while ( V_193 >>= 1 )
V_626 ++ ;
if ( V_626 ) {
V_72 = F_67 ( V_3 , V_626 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_278 ; V_39 ++ ) {
V_193 = ( F_23 ( V_750 ) &
V_753 ) >> V_754 ;
if ( V_193 == V_626 )
break;
F_59 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_258 ) &&
V_4 -> V_457 . V_458 ) {
V_626 = 0 ;
V_193 = V_4 -> V_457 . V_458 ;
while ( V_193 >>= 1 )
V_626 ++ ;
if ( V_626 ) {
V_72 = F_68 ( V_3 , V_441 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_278 ; V_39 ++ ) {
V_193 = ( F_23 ( V_755 ) &
V_756 ) >> V_757 ;
if ( V_193 == V_626 )
break;
F_59 ( 1 ) ;
}
}
}
} else if ( V_441 == V_758 ) {
if ( ( ! V_4 -> V_234 ) &&
V_4 -> V_457 . V_630 ) {
V_626 = F_178 ( V_3 ,
V_4 -> V_457 . V_630 ) ;
V_72 = F_66 ( V_3 , V_626 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_278 ; V_39 ++ ) {
V_193 = ( F_23 ( V_750 ) &
V_751 ) >> V_752 ;
if ( V_193 == V_626 )
break;
F_59 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_238 ) &&
V_4 -> V_457 . V_635 ) {
V_626 = F_178 ( V_3 ,
V_4 -> V_457 . V_635 ) ;
V_72 = F_67 ( V_3 , V_626 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_278 ; V_39 ++ ) {
V_193 = ( F_23 ( V_750 ) &
V_753 ) >> V_754 ;
if ( V_193 == V_626 )
break;
F_59 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_258 ) &&
V_4 -> V_457 . V_458 ) {
V_626 = F_178 ( V_3 ,
V_4 -> V_457 . V_458 ) ;
V_72 = F_68 ( V_3 , V_626 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_278 ; V_39 ++ ) {
V_193 = ( F_23 ( V_755 ) &
V_756 ) >> V_757 ;
if ( V_193 == V_626 )
break;
F_59 ( 1 ) ;
}
}
} else if ( V_441 == V_759 ) {
if ( ! V_4 -> V_234 ) {
V_143 = F_31 ( V_3 , V_760 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ! V_4 -> V_238 ) {
V_143 = F_31 ( V_3 , V_761 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ! V_4 -> V_258 ) {
V_143 = F_31 ( V_3 , V_762 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
}
V_3 -> V_5 . V_6 . V_763 = V_441 ;
return 0 ;
}
static int F_180 ( struct V_2 * V_3 ,
struct V_764 * V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_39 , V_96 , V_97 ;
T_3 V_765 ;
for ( V_39 = 0 , V_96 = V_200 -> V_766 ; V_39 < V_200 -> V_766 ; V_39 ++ ) {
if ( V_96 >= V_767 )
return - V_43 ;
switch( V_200 -> V_768 [ V_39 ] . V_769 << 2 ) {
case V_770 :
V_765 = F_24 ( V_771 ) ;
V_200 -> V_768 [ V_96 ] . V_769 = V_771 >> 2 ;
V_200 -> V_768 [ V_96 ] . V_772 = V_773 >> 2 ;
for ( V_97 = 0 ; V_97 < V_200 -> V_774 ; V_97 ++ ) {
V_200 -> V_775 [ V_97 ] . V_776 [ V_96 ] =
( ( V_765 & 0xffff0000 ) ) | ( ( V_200 -> V_775 [ V_97 ] . V_776 [ V_39 ] & 0xffff0000 ) >> 16 ) ;
}
V_96 ++ ;
if ( V_96 >= V_767 )
return - V_43 ;
V_765 = F_24 ( V_777 ) ;
V_200 -> V_768 [ V_96 ] . V_769 = V_777 >> 2 ;
V_200 -> V_768 [ V_96 ] . V_772 = V_778 >> 2 ;
for ( V_97 = 0 ; V_97 < V_200 -> V_774 ; V_97 ++ ) {
V_200 -> V_775 [ V_97 ] . V_776 [ V_96 ] =
( V_765 & 0xffff0000 ) | ( V_200 -> V_775 [ V_97 ] . V_776 [ V_39 ] & 0x0000ffff ) ;
if ( ! V_4 -> V_168 )
V_200 -> V_775 [ V_97 ] . V_776 [ V_96 ] |= 0x100 ;
}
V_96 ++ ;
if ( V_96 > V_767 )
return - V_43 ;
if ( ! V_4 -> V_168 ) {
V_200 -> V_768 [ V_96 ] . V_769 = V_779 >> 2 ;
V_200 -> V_768 [ V_96 ] . V_772 = V_779 >> 2 ;
for ( V_97 = 0 ; V_97 < V_200 -> V_774 ; V_97 ++ ) {
V_200 -> V_775 [ V_97 ] . V_776 [ V_96 ] =
( V_200 -> V_775 [ V_97 ] . V_776 [ V_39 ] & 0xffff0000 ) >> 16 ;
}
V_96 ++ ;
if ( V_96 > V_767 )
return - V_43 ;
}
break;
case V_780 :
V_765 = F_24 ( V_781 ) ;
V_200 -> V_768 [ V_96 ] . V_769 = V_781 >> 2 ;
V_200 -> V_768 [ V_96 ] . V_772 = V_782 >> 2 ;
for ( V_97 = 0 ; V_97 < V_200 -> V_774 ; V_97 ++ ) {
V_200 -> V_775 [ V_97 ] . V_776 [ V_96 ] =
( V_765 & 0xffff0000 ) | ( V_200 -> V_775 [ V_97 ] . V_776 [ V_39 ] & 0x0000ffff ) ;
}
V_96 ++ ;
if ( V_96 > V_767 )
return - V_43 ;
break;
default:
break;
}
}
V_200 -> V_766 = V_96 ;
return 0 ;
}
static bool F_181 ( T_2 V_783 , T_2 * V_784 )
{
bool V_722 = true ;
switch( V_783 ) {
case V_785 >> 2 :
* V_784 = V_786 >> 2 ;
break;
case V_787 >> 2 :
* V_784 = V_788 >> 2 ;
break;
case V_789 >> 2 :
* V_784 = V_790 >> 2 ;
break;
case V_791 >> 2 :
* V_784 = V_792 >> 2 ;
break;
case V_793 >> 2 :
* V_784 = V_794 >> 2 ;
break;
case V_795 >> 2 :
* V_784 = V_796 >> 2 ;
break;
case V_797 >> 2 :
* V_784 = V_798 >> 2 ;
break;
case V_799 >> 2 :
* V_784 = V_800 >> 2 ;
break;
case V_801 >> 2 :
* V_784 = V_802 >> 2 ;
break;
case V_803 >> 2 :
* V_784 = V_804 >> 2 ;
break;
case V_805 >> 2 :
* V_784 = V_806 >> 2 ;
break;
case V_807 >> 2 :
* V_784 = V_808 >> 2 ;
break;
case V_809 >> 2 :
* V_784 = V_810 >> 2 ;
break;
case V_811 >> 2 :
* V_784 = V_812 >> 2 ;
break;
case V_771 >> 2 :
* V_784 = V_773 >> 2 ;
break;
case V_777 >> 2 :
* V_784 = V_778 >> 2 ;
break;
case V_781 >> 2 :
* V_784 = V_782 >> 2 ;
break;
case V_813 >> 2 :
* V_784 = V_814 >> 2 ;
break;
case V_815 >> 2 :
* V_784 = V_816 >> 2 ;
break;
case V_817 >> 2 :
* V_784 = V_818 >> 2 ;
break;
default:
V_722 = false ;
break;
}
return V_722 ;
}
static void F_182 ( struct V_764 * V_200 )
{
T_1 V_39 , V_96 ;
for ( V_39 = 0 ; V_39 < V_200 -> V_766 ; V_39 ++ ) {
for ( V_96 = 1 ; V_96 < V_200 -> V_774 ; V_96 ++ ) {
if ( V_200 -> V_775 [ V_96 - 1 ] . V_776 [ V_39 ] !=
V_200 -> V_775 [ V_96 ] . V_776 [ V_39 ] ) {
V_200 -> V_819 |= 1 << V_39 ;
break;
}
}
}
}
static void F_183 ( struct V_764 * V_200 )
{
T_3 V_39 ;
T_2 V_820 ;
for ( V_39 = 0 ; V_39 < V_200 -> V_766 ; V_39 ++ ) {
V_200 -> V_768 [ V_39 ] . V_772 =
F_181 ( V_200 -> V_768 [ V_39 ] . V_769 , & V_820 ) ?
V_820 : V_200 -> V_768 [ V_39 ] . V_769 ;
}
}
static int F_184 ( const struct V_821 * V_200 ,
struct V_764 * V_822 )
{
T_1 V_39 , V_96 ;
if ( V_200 -> V_766 > V_767 )
return - V_43 ;
if ( V_200 -> V_774 > V_823 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_200 -> V_766 ; V_39 ++ )
V_822 -> V_768 [ V_39 ] . V_769 = V_200 -> V_768 [ V_39 ] . V_769 ;
V_822 -> V_766 = V_200 -> V_766 ;
for ( V_39 = 0 ; V_39 < V_200 -> V_774 ; V_39 ++ ) {
V_822 -> V_775 [ V_39 ] . V_824 =
V_200 -> V_775 [ V_39 ] . V_824 ;
for ( V_96 = 0 ; V_96 < V_200 -> V_766 ; V_96 ++ )
V_822 -> V_775 [ V_39 ] . V_776 [ V_96 ] =
V_200 -> V_775 [ V_39 ] . V_776 [ V_96 ] ;
}
V_822 -> V_774 = V_200 -> V_774 ;
return 0 ;
}
static int F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_821 * V_200 ;
struct V_764 * V_822 = & V_4 -> V_825 ;
T_1 V_826 = F_186 ( V_3 ) ;
int V_72 ;
V_200 = F_187 ( sizeof( struct V_821 ) , V_827 ) ;
if ( ! V_200 )
return - V_828 ;
F_26 ( V_786 , F_24 ( V_785 ) ) ;
F_26 ( V_796 , F_24 ( V_795 ) ) ;
F_26 ( V_788 , F_24 ( V_787 ) ) ;
F_26 ( V_790 , F_24 ( V_789 ) ) ;
F_26 ( V_792 , F_24 ( V_791 ) ) ;
F_26 ( V_794 , F_24 ( V_793 ) ) ;
F_26 ( V_802 , F_24 ( V_801 ) ) ;
F_26 ( V_804 , F_24 ( V_803 ) ) ;
F_26 ( V_798 , F_24 ( V_797 ) ) ;
F_26 ( V_800 , F_24 ( V_799 ) ) ;
F_26 ( V_773 , F_24 ( V_771 ) ) ;
F_26 ( V_778 , F_24 ( V_777 ) ) ;
F_26 ( V_782 , F_24 ( V_781 ) ) ;
F_26 ( V_810 , F_24 ( V_809 ) ) ;
F_26 ( V_812 , F_24 ( V_811 ) ) ;
F_26 ( V_806 , F_24 ( V_805 ) ) ;
F_26 ( V_808 , F_24 ( V_807 ) ) ;
F_26 ( V_814 , F_24 ( V_813 ) ) ;
F_26 ( V_816 , F_24 ( V_815 ) ) ;
F_26 ( V_818 , F_24 ( V_817 ) ) ;
V_72 = F_188 ( V_3 , V_826 , V_200 ) ;
if ( V_72 )
goto V_829;
V_72 = F_184 ( V_200 , V_822 ) ;
if ( V_72 )
goto V_829;
F_183 ( V_822 ) ;
V_72 = F_180 ( V_3 , V_822 ) ;
if ( V_72 )
goto V_829;
F_182 ( V_822 ) ;
V_829:
F_189 ( V_200 ) ;
return V_72 ;
}
static int F_190 ( struct V_2 * V_3 ,
T_14 * V_825 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 , V_96 ;
for ( V_39 = 0 , V_96 = 0 ; V_96 < V_4 -> V_825 . V_766 ; V_96 ++ ) {
if ( V_4 -> V_825 . V_819 & ( 1 << V_96 ) ) {
if ( V_39 >= V_767 )
return - V_43 ;
V_825 -> V_820 [ V_39 ] . V_772 = F_9 ( V_4 -> V_825 . V_768 [ V_96 ] . V_772 ) ;
V_825 -> V_820 [ V_39 ] . V_769 = F_9 ( V_4 -> V_825 . V_768 [ V_96 ] . V_769 ) ;
V_39 ++ ;
}
}
V_825 -> V_766 = ( T_1 ) V_39 ;
return 0 ;
}
static void F_191 ( const struct V_830 * V_831 ,
T_15 * V_126 ,
T_3 V_774 , T_3 V_819 )
{
T_3 V_39 , V_96 ;
for ( V_39 = 0 , V_96 = 0 ; V_96 < V_774 ; V_96 ++ ) {
if ( V_819 & ( 1 << V_96 ) ) {
V_126 -> V_55 [ V_39 ] = F_16 ( V_831 -> V_776 [ V_96 ] ) ;
V_39 ++ ;
}
}
}
static void F_192 ( struct V_2 * V_3 ,
const T_3 V_487 ,
T_15 * V_832 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 = 0 ;
for( V_39 = 0 ; V_39 < V_4 -> V_825 . V_774 ; V_39 ++ ) {
if ( V_487 <= V_4 -> V_825 . V_775 [ V_39 ] . V_824 )
break;
}
if ( ( V_39 == V_4 -> V_825 . V_774 ) && ( V_39 > 0 ) )
-- V_39 ;
F_191 ( & V_4 -> V_825 . V_775 [ V_39 ] ,
V_832 , V_4 -> V_825 . V_766 ,
V_4 -> V_825 . V_819 ) ;
}
static void F_193 ( struct V_2 * V_3 ,
T_14 * V_825 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 ;
for ( V_39 = 0 ; V_39 < V_4 -> V_91 . V_437 . V_44 ; V_39 ++ )
F_192 ( V_3 ,
V_4 -> V_91 . V_437 . V_438 [ V_39 ] . V_55 ,
& V_825 -> V_126 [ V_39 ] ) ;
}
static int F_194 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
memset ( & V_4 -> V_833 , 0 , sizeof( T_14 ) ) ;
V_72 = F_190 ( V_3 , & V_4 -> V_833 ) ;
if ( V_72 )
return V_72 ;
F_193 ( V_3 , & V_4 -> V_833 ) ;
return F_18 ( V_3 ,
V_4 -> V_284 ,
( T_1 * ) & V_4 -> V_833 ,
sizeof( T_14 ) ,
V_4 -> V_78 ) ;
}
static int F_195 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! ( V_4 -> V_233 & V_239 ) )
return 0 ;
memset ( & V_4 -> V_833 , 0 , sizeof( T_14 ) ) ;
F_193 ( V_3 , & V_4 -> V_833 ) ;
return F_18 ( V_3 ,
V_4 -> V_284 +
F_12 ( T_14 , V_126 [ 0 ] ) ,
( T_1 * ) & V_4 -> V_833 . V_126 [ 0 ] ,
sizeof( T_15 ) *
V_4 -> V_91 . V_437 . V_44 ,
V_4 -> V_78 ) ;
}
static void F_196 ( struct V_2 * V_3 )
{
T_3 V_193 = F_23 ( V_225 ) ;
V_193 |= V_834 ;
F_25 ( V_225 , V_193 ) ;
}
static enum V_835 F_197 ( struct V_2 * V_3 ,
struct V_9 * V_714 )
{
struct V_8 * V_596 = F_2 ( V_714 ) ;
int V_39 ;
T_2 V_836 , V_837 = 0 ;
for ( V_39 = 0 ; V_39 < V_596 -> V_187 ; V_39 ++ ) {
V_836 = V_596 -> V_188 [ V_39 ] . V_638 ;
if ( V_837 < V_836 )
V_837 = V_836 ;
}
return V_837 ;
}
static T_2 F_198 ( struct V_2 * V_3 )
{
T_3 V_838 = 0 ;
V_838 = F_199 ( V_839 ) & V_840 ;
V_838 >>= V_841 ;
return ( T_2 ) V_838 ;
}
static int F_200 ( struct V_2 * V_3 )
{
T_3 V_842 = 0 ;
V_842 = F_199 ( V_843 ) & V_844 ;
V_842 >>= V_845 ;
switch ( V_842 ) {
case V_846 :
return 1 ;
case V_847 :
return 2 ;
case V_848 :
return 4 ;
case V_849 :
return 8 ;
case V_850 :
return 12 ;
case V_851 :
case V_852 :
default:
return 16 ;
}
}
static void F_201 ( struct V_2 * V_3 ,
struct V_9 * V_743 ,
struct V_9 * V_744 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_835 V_853 =
F_197 ( V_3 , V_743 ) ;
enum V_835 V_854 ;
if ( V_4 -> V_855 == V_856 )
V_854 = F_197 ( V_3 , V_744 ) ;
else
V_854 = V_4 -> V_855 ;
V_4 -> V_855 = V_856 ;
V_4 -> V_857 = false ;
if ( V_853 > V_854 ) {
switch ( V_853 ) {
#ifdef F_202
case V_858 :
if ( F_203 ( V_3 , V_859 , false ) == 0 )
break;
V_4 -> V_855 = V_860 ;
if ( V_854 == V_860 )
break;
case V_860 :
if ( F_203 ( V_3 , V_861 , false ) == 0 )
break;
#endif
default:
V_4 -> V_855 = F_198 ( V_3 ) ;
break;
}
} else {
if ( V_853 < V_854 )
V_4 -> V_857 = true ;
}
}
static void F_204 ( struct V_2 * V_3 ,
struct V_9 * V_743 ,
struct V_9 * V_744 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_835 V_853 =
F_197 ( V_3 , V_743 ) ;
T_1 V_862 ;
if ( V_4 -> V_857 ) {
if ( V_853 == V_858 )
V_862 = V_859 ;
else if ( V_853 == V_860 )
V_862 = V_861 ;
else
V_862 = V_863 ;
if ( ( V_862 == V_863 ) &&
( F_198 ( V_3 ) > 0 ) )
return;
#ifdef F_202
F_203 ( V_3 , V_862 , false ) ;
#endif
}
}
static int F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_369 * V_647 =
& V_3 -> V_5 . V_6 . V_40 . V_45 ;
struct V_369 * V_864 =
& V_3 -> V_5 . V_6 . V_40 . V_382 ;
struct V_369 * V_865 =
& V_3 -> V_5 . V_6 . V_40 . V_387 ;
if ( V_647 == NULL )
return - V_43 ;
if ( V_647 -> V_44 < 1 )
return - V_43 ;
if ( V_864 == NULL )
return - V_43 ;
if ( V_864 -> V_44 < 1 )
return - V_43 ;
if ( V_865 == NULL )
return - V_43 ;
if ( V_865 -> V_44 < 1 )
return - V_43 ;
V_4 -> V_568 = V_647 -> V_42 [ 0 ] . V_375 ;
V_4 -> V_866 =
V_647 -> V_42 [ V_647 -> V_44 - 1 ] . V_375 ;
V_4 -> V_586 = V_865 -> V_42 [ 0 ] . V_375 ;
V_4 -> V_867 =
V_865 -> V_42 [ V_865 -> V_44 - 1 ] . V_375 ;
V_3 -> V_5 . V_6 . V_40 . V_185 . V_172 =
V_647 -> V_42 [ V_647 -> V_44 - 1 ] . V_408 ;
V_3 -> V_5 . V_6 . V_40 . V_185 . V_173 =
V_864 -> V_42 [ V_647 -> V_44 - 1 ] . V_408 ;
V_3 -> V_5 . V_6 . V_40 . V_185 . V_30 =
V_647 -> V_42 [ V_647 -> V_44 - 1 ] . V_375 ;
V_3 -> V_5 . V_6 . V_40 . V_185 . V_210 =
V_865 -> V_42 [ V_865 -> V_44 - 1 ] . V_375 ;
return 0 ;
}
static void F_206 ( struct V_2 * V_3 , T_2 * V_30 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_868 * V_869 = & V_4 -> V_211 ;
T_3 V_870 ;
for ( V_870 = 0 ; V_870 < V_869 -> V_44 ; V_870 ++ ) {
if ( V_869 -> V_208 [ V_870 ] == * V_30 ) {
* V_30 = V_869 -> V_215 [ V_870 ] ;
break;
}
}
}
static void F_207 ( struct V_2 * V_3 , T_2 * V_210 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_868 * V_869 = & V_4 -> V_212 ;
T_3 V_870 ;
for ( V_870 = 0 ; V_870 < V_869 -> V_44 ; V_870 ++ ) {
if ( V_869 -> V_208 [ V_870 ] == * V_210 ) {
* V_210 = V_869 -> V_215 [ V_870 ] ;
break;
}
}
}
static void F_208 ( struct V_2 * V_3 ,
struct V_369 * V_200 )
{
T_3 V_39 ;
if ( V_200 ) {
for ( V_39 = 0 ; V_39 < V_200 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_200 -> V_42 [ V_39 ] . V_375 ) ;
}
}
static void F_209 ( struct V_2 * V_3 ,
struct V_369 * V_200 )
{
T_3 V_39 ;
if ( V_200 ) {
for ( V_39 = 0 ; V_39 < V_200 -> V_44 ; V_39 ++ )
F_207 ( V_3 , & V_200 -> V_42 [ V_39 ] . V_375 ) ;
}
}
static void F_210 ( struct V_2 * V_3 ,
struct V_742 * V_200 )
{
T_3 V_39 ;
if ( V_200 ) {
for ( V_39 = 0 ; V_39 < V_200 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_200 -> V_42 [ V_39 ] . V_375 ) ;
}
}
static void F_211 ( struct V_2 * V_3 ,
struct V_871 * V_200 )
{
T_3 V_39 ;
if ( V_200 ) {
for ( V_39 = 0 ; V_39 < V_200 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_200 -> V_42 [ V_39 ] . V_375 ) ;
}
}
static void F_212 ( struct V_2 * V_3 ,
struct V_414 * V_200 )
{
T_3 V_39 ;
if ( V_200 ) {
for ( V_39 = 0 ; V_39 < V_200 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_200 -> V_42 [ V_39 ] . V_406 ) ;
}
}
static void F_213 ( struct V_2 * V_3 ,
struct V_169 * V_200 )
{
if ( V_200 ) {
F_206 ( V_3 , ( T_2 * ) & V_200 -> V_30 ) ;
F_207 ( V_3 , ( T_2 * ) & V_200 -> V_210 ) ;
}
}
static void F_214 ( struct V_2 * V_3 ,
struct V_649 * V_200 )
{
T_3 V_39 ;
if ( V_200 ) {
for ( V_39 = 0 ; V_39 < V_200 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_200 -> V_42 [ V_39 ] . V_30 ) ;
}
}
static void F_215 ( struct V_2 * V_3 )
{
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_45 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_382 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_718 ) ;
F_209 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_387 ) ;
F_210 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_475 ) ;
F_211 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_462 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_485 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_482 ) ;
F_212 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_535 ) ;
F_213 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_185 ) ;
F_213 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_186 ) ;
F_214 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_41 ) ;
}
static void F_216 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_193 ;
V_193 = F_24 ( V_872 ) ;
if ( ( ( V_193 & V_873 ) >> V_874 ) ==
V_875 )
V_4 -> V_168 = true ;
else
V_4 -> V_168 = false ;
}
static void F_217 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_876 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_877 = * V_10 ;
V_4 -> V_878 = * V_876 ;
V_4 -> V_877 . V_12 = & V_4 -> V_878 ;
}
static void F_218 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_876 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_879 = * V_10 ;
V_4 -> V_880 = * V_876 ;
V_4 -> V_879 . V_12 = & V_4 -> V_880 ;
}
int F_219 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 V_880 = * V_3 -> V_5 . V_6 . V_880 ;
struct V_9 * V_876 = & V_880 ;
F_218 ( V_3 , V_876 ) ;
F_40 ( V_3 , & V_4 -> V_879 ) ;
return 0 ;
}
void F_220 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_876 = & V_4 -> V_879 ;
F_217 ( V_3 , V_876 ) ;
}
void F_221 ( struct V_2 * V_3 )
{
int V_881 ;
V_881 = F_222 ( V_3 ) ;
if ( V_881 )
F_42 ( L_2 ) ;
F_80 ( V_3 ) ;
F_216 ( V_3 ) ;
F_83 ( V_3 ) ;
F_81 ( V_3 ) ;
}
int F_223 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_655 = V_3 -> V_5 . V_6 . V_655 ;
int V_72 ;
if ( F_224 ( V_3 ) )
return - V_43 ;
if ( V_4 -> V_377 != V_407 ) {
F_196 ( V_3 ) ;
V_72 = F_100 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_3 ) ;
return V_72 ;
}
}
if ( V_4 -> V_882 ) {
V_72 = F_185 ( V_3 ) ;
if ( V_72 )
V_4 -> V_882 = false ;
}
if ( V_4 -> V_883 )
F_89 ( V_3 , true ) ;
if ( V_4 -> V_226 )
F_82 ( V_3 , true ) ;
F_90 ( V_3 ) ;
F_93 ( V_3 ) ;
F_95 ( V_3 ) ;
V_72 = F_97 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_4 ) ;
return V_72 ;
}
V_72 = F_79 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_5 ) ;
return V_72 ;
}
V_72 = F_115 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_6 ) ;
return V_72 ;
}
V_72 = F_164 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_7 ) ;
return V_72 ;
}
V_72 = F_112 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_8 ) ;
return V_72 ;
}
if ( V_4 -> V_882 ) {
V_72 = F_194 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_9 ) ;
return V_72 ;
}
}
V_72 = F_17 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_10 ) ;
return V_72 ;
}
F_72 ( V_3 ) ;
F_55 ( V_3 ) ;
V_72 = F_84 ( V_3 , false ) ;
if ( V_72 ) {
F_42 ( L_11 ) ;
return V_72 ;
}
F_63 ( V_3 , true ) ;
V_72 = F_149 ( V_3 , true ) ;
if ( V_72 ) {
F_42 ( L_12 ) ;
return V_72 ;
}
V_72 = F_85 ( V_3 , true ) ;
if ( V_72 ) {
F_42 ( L_13 ) ;
return V_72 ;
}
V_72 = F_60 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_14 ) ;
return V_72 ;
}
V_72 = F_27 ( V_3 , true ) ;
if ( V_72 ) {
F_42 ( L_15 ) ;
return V_72 ;
}
V_72 = F_33 ( V_3 , true ) ;
if ( V_72 ) {
F_42 ( L_16 ) ;
return V_72 ;
}
V_72 = F_30 ( V_3 , true ) ;
if ( V_72 ) {
F_42 ( L_17 ) ;
return V_72 ;
}
F_54 ( V_3 , V_220 , true ) ;
F_217 ( V_3 , V_655 ) ;
return 0 ;
}
int F_225 ( struct V_2 * V_3 )
{
int V_72 ;
if ( V_3 -> V_884 . V_885 &&
F_226 ( V_3 -> V_5 . V_886 ) ) {
#if 0
PPSMC_Result result;
#endif
V_72 = F_41 ( V_3 , V_887 , V_888 ) ;
if ( V_72 ) {
F_42 ( L_18 ) ;
return V_72 ;
}
V_3 -> V_884 . V_889 = true ;
F_227 ( V_3 ) ;
#if 0
result = ci_send_msg_to_smc(rdev, PPSMC_MSG_EnableThermalInterrupt);
if (result != PPSMC_Result_OK)
DRM_DEBUG_KMS("Could not enable thermal interrupts.\n");
#endif
}
F_36 ( V_3 , true ) ;
return 0 ;
}
void F_228 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_655 = V_3 -> V_5 . V_6 . V_655 ;
F_36 ( V_3 , false ) ;
if ( ! F_224 ( V_3 ) )
return;
if ( V_4 -> V_226 )
F_82 ( V_3 , false ) ;
F_30 ( V_3 , false ) ;
F_33 ( V_3 , false ) ;
F_27 ( V_3 , false ) ;
F_89 ( V_3 , false ) ;
F_54 ( V_3 , V_220 , false ) ;
F_62 ( V_3 ) ;
F_85 ( V_3 , true ) ;
F_149 ( V_3 , false ) ;
F_96 ( V_3 ) ;
F_117 ( V_3 ) ;
F_76 ( V_3 ) ;
F_118 ( V_3 ) ;
F_217 ( V_3 , V_655 ) ;
}
int F_229 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_876 = & V_4 -> V_879 ;
struct V_9 * V_890 = & V_4 -> V_877 ;
int V_72 ;
F_170 ( V_3 , V_876 ) ;
if ( V_4 -> V_891 )
F_201 ( V_3 , V_876 , V_890 ) ;
V_72 = F_61 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_19 ) ;
return V_72 ;
}
V_72 = F_171 ( V_3 , V_876 ) ;
if ( V_72 ) {
F_42 ( L_20 ) ;
return V_72 ;
}
V_72 = F_177 ( V_3 , V_876 ) ;
if ( V_72 ) {
F_42 ( L_21 ) ;
return V_72 ;
}
V_72 = F_175 ( V_3 , V_876 , V_890 ) ;
if ( V_72 ) {
F_42 ( L_22 ) ;
return V_72 ;
}
V_72 = F_48 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_23 ) ;
return V_72 ;
}
if ( V_4 -> V_882 ) {
V_72 = F_195 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_24 ) ;
return V_72 ;
}
}
V_72 = F_122 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_25 ) ;
return V_72 ;
}
V_72 = F_56 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_26 ) ;
return V_72 ;
}
V_72 = F_169 ( V_3 ) ;
if ( V_72 ) {
F_42 ( L_27 ) ;
return V_72 ;
}
if ( V_4 -> V_891 )
F_204 ( V_3 , V_876 , V_890 ) ;
return 0 ;
}
int F_230 ( struct V_2 * V_3 )
{
return F_34 ( V_3 ) ;
}
void F_231 ( struct V_2 * V_3 )
{
F_69 ( V_3 ) ;
}
void F_232 ( struct V_2 * V_3 )
{
F_86 ( V_3 ) ;
}
static void F_233 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_892 * V_893 ,
T_1 V_894 )
{
V_10 -> V_895 = F_234 ( V_893 -> V_896 ) ;
V_10 -> V_180 = F_235 ( V_893 -> V_897 ) ;
V_10 -> V_898 = F_235 ( V_893 -> V_899 ) ;
if ( V_900 < V_894 ) {
V_10 -> V_465 = F_234 ( V_893 -> V_901 ) ;
V_10 -> V_467 = F_234 ( V_893 -> V_902 ) ;
} else {
V_10 -> V_465 = 0 ;
V_10 -> V_467 = 0 ;
}
if ( V_10 -> V_180 & V_903 )
V_3 -> V_5 . V_6 . V_655 = V_10 ;
if ( V_10 -> V_180 & V_904 )
V_3 -> V_5 . V_6 . V_905 = V_10 ;
}
static void F_236 ( struct V_2 * V_3 ,
struct V_9 * V_10 , int V_637 ,
union V_906 * V_907 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_908 * V_909 = & V_11 -> V_188 [ V_637 ] ;
V_11 -> V_187 = V_637 + 1 ;
V_909 -> V_172 = F_235 ( V_907 -> V_910 . V_911 ) ;
V_909 -> V_172 |= V_907 -> V_910 . V_912 << 16 ;
V_909 -> V_173 = F_235 ( V_907 -> V_910 . V_913 ) ;
V_909 -> V_173 |= V_907 -> V_910 . V_914 << 16 ;
V_909 -> V_638 = F_237 ( V_3 ,
V_4 -> V_915 ,
V_4 -> V_669 . V_916 ,
V_907 -> V_910 . V_917 ) ;
V_909 -> V_716 = F_238 ( V_3 ,
V_4 -> V_669 . V_918 ,
F_235 ( V_907 -> V_910 . V_919 ) ) ;
if ( V_10 -> V_180 & V_920 ) {
V_4 -> V_921 = V_909 -> V_638 ;
}
if ( V_10 -> V_898 & V_922 ) {
V_4 -> V_592 . V_593 = true ;
V_4 -> V_592 . V_909 = * V_909 ;
V_4 -> V_592 . V_664 = V_923 ;
}
if ( V_10 -> V_180 & V_903 ) {
V_909 -> V_173 = V_4 -> V_669 . V_671 ;
V_909 -> V_172 = V_4 -> V_669 . V_670 ;
V_909 -> V_638 = V_4 -> V_669 . V_916 ;
V_909 -> V_716 = V_4 -> V_669 . V_918 ;
}
switch ( V_10 -> V_180 & V_181 ) {
case V_182 :
V_4 -> V_641 = true ;
if ( V_4 -> V_642 . V_81 < V_909 -> V_638 )
V_4 -> V_642 . V_81 = V_909 -> V_638 ;
if ( V_4 -> V_642 . V_80 > V_909 -> V_638 )
V_4 -> V_642 . V_80 = V_909 -> V_638 ;
if ( V_4 -> V_644 . V_81 < V_909 -> V_716 )
V_4 -> V_644 . V_81 = V_909 -> V_716 ;
if ( V_4 -> V_644 . V_80 > V_909 -> V_716 )
V_4 -> V_644 . V_80 = V_909 -> V_716 ;
break;
case V_924 :
V_4 -> V_640 = true ;
if ( V_4 -> V_643 . V_81 < V_909 -> V_638 )
V_4 -> V_643 . V_81 = V_909 -> V_638 ;
if ( V_4 -> V_643 . V_80 > V_909 -> V_638 )
V_4 -> V_643 . V_80 = V_909 -> V_638 ;
if ( V_4 -> V_645 . V_81 < V_909 -> V_716 )
V_4 -> V_645 . V_81 = V_909 -> V_716 ;
if ( V_4 -> V_645 . V_80 > V_909 -> V_716 )
V_4 -> V_645 . V_80 = V_909 -> V_716 ;
break;
default:
break;
}
}
static int F_239 ( struct V_2 * V_3 )
{
struct V_925 * V_926 = & V_3 -> V_926 ;
struct V_892 * V_893 ;
union V_927 * V_928 ;
int V_39 , V_96 , V_97 , V_929 , V_930 ;
union V_906 * V_907 ;
struct V_931 * V_932 ;
struct V_933 * V_934 ;
struct V_935 * V_936 ;
union V_937 * V_937 ;
int V_637 = F_240 ( V_938 , V_939 ) ;
T_2 V_940 ;
T_1 V_941 , V_942 ;
T_1 * V_943 ;
struct V_8 * V_11 ;
if ( ! F_241 ( V_926 -> V_944 , V_637 , NULL ,
& V_941 , & V_942 , & V_940 ) )
return - V_43 ;
V_937 = (union V_937 * ) ( V_926 -> V_944 -> V_945 + V_940 ) ;
V_932 = (struct V_931 * )
( V_926 -> V_944 -> V_945 + V_940 +
F_235 ( V_937 -> V_946 . V_947 ) ) ;
V_934 = (struct V_933 * )
( V_926 -> V_944 -> V_945 + V_940 +
F_235 ( V_937 -> V_946 . V_948 ) ) ;
V_936 = (struct V_935 * )
( V_926 -> V_944 -> V_945 + V_940 +
F_235 ( V_937 -> V_946 . V_949 ) ) ;
V_3 -> V_5 . V_6 . V_11 = F_187 ( sizeof( struct V_9 ) *
V_932 -> V_950 , V_827 ) ;
if ( ! V_3 -> V_5 . V_6 . V_11 )
return - V_828 ;
V_943 = ( T_1 * ) V_932 -> V_951 ;
for ( V_39 = 0 ; V_39 < V_932 -> V_950 ; V_39 ++ ) {
T_1 * V_412 ;
V_928 = (union V_927 * ) V_943 ;
V_929 = V_928 -> V_952 . V_953 ;
V_893 = (struct V_892 * )
& V_936 -> V_954 [ V_929 ] ;
if ( ! V_3 -> V_5 . V_928 [ V_39 ] . V_907 )
return - V_43 ;
V_11 = F_187 ( sizeof( struct V_8 ) , V_827 ) ;
if ( V_11 == NULL ) {
F_189 ( V_3 -> V_5 . V_6 . V_11 ) ;
return - V_828 ;
}
V_3 -> V_5 . V_6 . V_11 [ V_39 ] . V_12 = V_11 ;
F_233 ( V_3 , & V_3 -> V_5 . V_6 . V_11 [ V_39 ] ,
V_893 ,
V_936 -> V_955 ) ;
V_97 = 0 ;
V_412 = ( T_1 * ) & V_928 -> V_952 . V_956 [ 0 ] ;
for ( V_96 = 0 ; V_96 < V_928 -> V_952 . V_957 ; V_96 ++ ) {
V_930 = V_412 [ V_96 ] ;
if ( V_930 >= V_934 -> V_950 )
continue;
if ( V_97 >= V_958 )
break;
V_907 = (union V_906 * )
( ( T_1 * ) & V_934 -> V_959 [ 0 ] +
( V_930 * V_934 -> V_955 ) ) ;
F_236 ( V_3 ,
& V_3 -> V_5 . V_6 . V_11 [ V_39 ] , V_97 ,
V_907 ) ;
V_97 ++ ;
}
V_943 += 2 + V_928 -> V_952 . V_957 ;
}
V_3 -> V_5 . V_6 . V_960 = V_932 -> V_950 ;
for ( V_39 = 0 ; V_39 < V_961 ; V_39 ++ ) {
T_3 V_172 , V_173 ;
V_930 = V_3 -> V_5 . V_6 . V_176 [ V_39 ] . V_962 ;
V_907 = (union V_906 * )
& V_934 -> V_959 [ V_930 * V_934 -> V_955 ] ;
V_172 = F_235 ( V_907 -> V_910 . V_911 ) ;
V_172 |= V_907 -> V_910 . V_912 << 16 ;
V_173 = F_235 ( V_907 -> V_910 . V_913 ) ;
V_173 |= V_907 -> V_910 . V_914 << 16 ;
V_3 -> V_5 . V_6 . V_176 [ V_39 ] . V_172 = V_172 ;
V_3 -> V_5 . V_6 . V_176 [ V_39 ] . V_173 = V_173 ;
}
return 0 ;
}
static int F_242 ( struct V_2 * V_3 ,
struct V_963 * V_440 )
{
struct V_925 * V_926 = & V_3 -> V_926 ;
int V_637 = F_240 ( V_938 , V_964 ) ;
T_16 * V_965 ;
T_1 V_941 , V_942 ;
T_2 V_940 ;
if ( F_241 ( V_926 -> V_944 , V_637 , NULL ,
& V_941 , & V_942 , & V_940 ) ) {
V_965 =
( T_16 * ) ( V_926 -> V_944 -> V_945 +
V_940 ) ;
V_440 -> V_677 = F_235 ( V_965 -> V_966 ) ;
V_440 -> V_673 = F_235 ( V_965 -> V_967 ) ;
V_440 -> V_675 = F_235 ( V_965 -> V_968 ) ;
V_440 -> V_916 = F_198 ( V_3 ) ;
V_440 -> V_918 = F_200 ( V_3 ) ;
V_440 -> V_670 = F_234 ( V_965 -> V_969 ) ;
V_440 -> V_671 = F_234 ( V_965 -> V_970 ) ;
return 0 ;
}
return - V_43 ;
}
void F_243 ( struct V_2 * V_3 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 . V_6 . V_960 ; V_39 ++ ) {
F_189 ( V_3 -> V_5 . V_6 . V_11 [ V_39 ] . V_12 ) ;
}
F_189 ( V_3 -> V_5 . V_6 . V_11 ) ;
F_189 ( V_3 -> V_5 . V_6 . V_7 ) ;
F_189 ( V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 ) ;
F_244 ( V_3 ) ;
}
int F_245 ( struct V_2 * V_3 )
{
int V_637 = F_240 ( V_938 , V_971 ) ;
T_2 V_940 , V_972 ;
T_1 V_941 , V_942 ;
struct V_1 * V_4 ;
int V_72 ;
T_3 V_139 ;
V_4 = F_187 ( sizeof( struct V_1 ) , V_827 ) ;
if ( V_4 == NULL )
return - V_828 ;
V_3 -> V_5 . V_6 . V_7 = V_4 ;
V_72 = F_246 ( V_3 -> V_973 , & V_139 ) ;
if ( V_72 )
V_4 -> V_915 = 0 ;
else
V_4 -> V_915 = V_139 ;
V_4 -> V_855 = V_856 ;
V_4 -> V_643 . V_81 = V_974 ;
V_4 -> V_643 . V_80 = V_858 ;
V_4 -> V_642 . V_81 = V_974 ;
V_4 -> V_642 . V_80 = V_858 ;
V_4 -> V_645 . V_81 = 0 ;
V_4 -> V_645 . V_80 = 16 ;
V_4 -> V_644 . V_81 = 0 ;
V_4 -> V_644 . V_80 = 16 ;
V_72 = F_242 ( V_3 , & V_4 -> V_669 ) ;
if ( V_72 ) {
F_243 ( V_3 ) ;
return V_72 ;
}
V_72 = F_247 ( V_3 ) ;
if ( V_72 ) {
F_243 ( V_3 ) ;
return V_72 ;
}
V_72 = F_248 ( V_3 ) ;
if ( V_72 ) {
F_243 ( V_3 ) ;
return V_72 ;
}
V_72 = F_239 ( V_3 ) ;
if ( V_72 ) {
F_243 ( V_3 ) ;
return V_72 ;
}
V_4 -> V_560 = false ;
V_4 -> V_78 = V_975 ;
V_4 -> V_627 [ 0 ] = V_976 ;
V_4 -> V_627 [ 1 ] = V_976 ;
V_4 -> V_627 [ 2 ] = V_976 ;
V_4 -> V_627 [ 3 ] = V_976 ;
V_4 -> V_627 [ 4 ] = V_976 ;
V_4 -> V_627 [ 5 ] = V_976 ;
V_4 -> V_627 [ 6 ] = V_976 ;
V_4 -> V_627 [ 7 ] = V_976 ;
V_4 -> V_541 = V_977 ;
V_4 -> V_234 = 0 ;
V_4 -> V_238 = 0 ;
V_4 -> V_258 = 0 ;
if ( ( V_3 -> V_13 -> V_14 == 0x6658 ) &&
( V_3 -> V_978 -> V_972 == ( V_979 * 4 ) ) ) {
V_4 -> V_238 = 1 ;
}
V_4 -> V_324 = true ;
V_4 -> V_553 = 40000 ;
V_4 -> V_549 = 40000 ;
V_4 -> V_555 = 40000 ;
V_4 -> V_556 = 40000 ;
F_3 ( V_3 ) ;
V_4 -> V_201 = false ;
V_4 -> V_205 = false ;
V_4 -> V_729 = true ;
V_4 -> V_735 = true ;
F_49 ( V_3 ) ;
F_215 ( V_3 ) ;
F_205 ( V_3 ) ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 =
F_187 ( 4 * sizeof( struct V_980 ) , V_827 ) ;
if ( ! V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 ) {
F_243 ( V_3 ) ;
return - V_828 ;
}
V_3 -> V_5 . V_6 . V_40 . V_718 . V_44 = 4 ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 [ 0 ] . V_408 = 0 ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 [ 0 ] . V_375 = 0 ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 [ 1 ] . V_408 = 36000 ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 [ 1 ] . V_375 = 720 ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 [ 2 ] . V_408 = 54000 ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 [ 2 ] . V_375 = 810 ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 [ 3 ] . V_408 = 72000 ;
V_3 -> V_5 . V_6 . V_40 . V_718 . V_42 [ 3 ] . V_375 = 900 ;
V_3 -> V_5 . V_6 . V_40 . V_981 = 4 ;
V_3 -> V_5 . V_6 . V_40 . V_982 = 15000 ;
V_3 -> V_5 . V_6 . V_40 . V_983 = 200 ;
V_3 -> V_5 . V_6 . V_40 . V_984 . V_44 = 0 ;
V_3 -> V_5 . V_6 . V_40 . V_984 . V_985 = NULL ;
V_3 -> V_5 . V_6 . V_40 . V_986 . V_44 = 0 ;
V_3 -> V_5 . V_6 . V_40 . V_986 . V_985 = NULL ;
if ( V_3 -> V_987 == V_988 ) {
V_4 -> V_106 . V_690 = 94500 ;
V_4 -> V_106 . V_107 = 95000 ;
V_4 -> V_106 . V_989 = 104000 ;
} else {
V_4 -> V_106 . V_690 = 99500 ;
V_4 -> V_106 . V_107 = 100000 ;
V_4 -> V_106 . V_989 = 104000 ;
}
V_4 -> V_550 = false ;
V_4 -> V_377 = V_407 ;
V_4 -> V_384 = V_407 ;
V_4 -> V_389 = V_407 ;
if ( F_249 ( V_3 , V_379 , V_380 ) )
V_4 -> V_377 = V_378 ;
else if ( F_249 ( V_3 , V_379 , V_990 ) )
V_4 -> V_377 = V_381 ;
if ( V_3 -> V_5 . V_6 . V_46 & V_991 ) {
if ( F_249 ( V_3 , V_385 , V_380 ) )
V_4 -> V_384 = V_378 ;
else if ( F_249 ( V_3 , V_385 , V_990 ) )
V_4 -> V_384 = V_381 ;
else
V_3 -> V_5 . V_6 . V_46 &= ~ V_991 ;
}
if ( V_3 -> V_5 . V_6 . V_46 & V_992 ) {
if ( F_249 ( V_3 , V_390 , V_380 ) )
V_4 -> V_389 = V_378 ;
else if ( F_249 ( V_3 , V_390 , V_990 ) )
V_4 -> V_389 = V_381 ;
else
V_3 -> V_5 . V_6 . V_46 &= ~ V_992 ;
}
V_4 -> V_534 = true ;
#if F_250 ( F_202 )
V_4 -> V_891 =
F_251 ( V_3 ) ;
#else
V_4 -> V_891 = false ;
#endif
if ( F_241 ( V_3 -> V_926 . V_944 , V_637 , & V_972 ,
& V_941 , & V_942 , & V_940 ) ) {
V_4 -> V_340 = true ;
V_4 -> V_504 = true ;
V_4 -> V_883 = true ;
} else {
V_4 -> V_340 = false ;
V_4 -> V_504 = false ;
V_4 -> V_883 = true ;
}
if ( V_3 -> V_5 . V_886 != V_993 )
V_4 -> V_226 = true ;
else
V_4 -> V_226 = false ;
V_4 -> V_882 = true ;
V_4 -> V_165 = false ;
if ( ( V_3 -> V_5 . V_6 . V_40 . V_186 . V_172 == 0 ) ||
( V_3 -> V_5 . V_6 . V_40 . V_186 . V_173 == 0 ) )
V_3 -> V_5 . V_6 . V_40 . V_186 =
V_3 -> V_5 . V_6 . V_40 . V_185 ;
return 0 ;
}
void F_252 ( struct V_2 * V_3 ,
struct V_994 * V_995 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_10 = & V_4 -> V_877 ;
T_3 V_172 = F_70 ( V_3 ) ;
T_3 V_173 = F_71 ( V_3 ) ;
F_253 ( V_995 , L_28 , V_4 -> V_550 ? L_29 : L_30 ) ;
F_253 ( V_995 , L_31 , V_10 -> V_174 ? L_29 : L_30 ) ;
F_253 ( V_995 , L_32 ,
V_172 , V_173 ) ;
}
void F_254 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_908 * V_909 ;
int V_39 ;
F_255 ( V_10 -> V_180 , V_10 -> V_898 ) ;
F_256 ( V_10 -> V_895 ) ;
F_257 ( L_33 , V_10 -> V_465 , V_10 -> V_467 ) ;
for ( V_39 = 0 ; V_39 < V_11 -> V_187 ; V_39 ++ ) {
V_909 = & V_11 -> V_188 [ V_39 ] ;
F_257 ( L_34 ,
V_39 , V_909 -> V_172 , V_909 -> V_173 , V_909 -> V_638 + 1 , V_909 -> V_716 ) ;
}
F_258 ( V_3 , V_10 ) ;
}
T_3 F_259 ( struct V_2 * V_3 , bool V_996 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_997 = F_2 ( & V_4 -> V_879 ) ;
if ( V_996 )
return V_997 -> V_188 [ 0 ] . V_172 ;
else
return V_997 -> V_188 [ V_997 -> V_187 - 1 ] . V_172 ;
}
T_3 F_260 ( struct V_2 * V_3 , bool V_996 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_997 = F_2 ( & V_4 -> V_879 ) ;
if ( V_996 )
return V_997 -> V_188 [ 0 ] . V_173 ;
else
return V_997 -> V_188 [ V_997 -> V_187 - 1 ] . V_173 ;
}
