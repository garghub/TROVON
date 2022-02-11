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
T_3 V_174 , V_175 , V_176 ;
int V_39 ;
if ( V_10 -> V_177 ) {
V_10 -> V_178 = V_3 -> V_5 . V_6 . V_179 [ V_3 -> V_5 . V_6 . V_180 ] . V_178 ;
V_10 -> V_181 = V_3 -> V_5 . V_6 . V_179 [ V_3 -> V_5 . V_6 . V_180 ] . V_181 ;
} else {
V_10 -> V_178 = 0 ;
V_10 -> V_181 = 0 ;
}
if ( ( V_3 -> V_5 . V_6 . V_182 > 1 ) ||
F_38 ( V_3 ) )
V_171 = true ;
else
V_171 = false ;
if ( ( V_10 -> V_183 & V_184 ) == V_185 )
V_4 -> V_186 = true ;
else
V_4 -> V_186 = false ;
if ( V_3 -> V_5 . V_6 . V_187 )
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_188 ;
else
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_189 ;
if ( V_3 -> V_5 . V_6 . V_187 == false ) {
for ( V_39 = 0 ; V_39 < V_11 -> V_190 ; V_39 ++ ) {
if ( V_11 -> V_191 [ V_39 ] . V_173 > V_170 -> V_173 )
V_11 -> V_191 [ V_39 ] . V_173 = V_170 -> V_173 ;
if ( V_11 -> V_191 [ V_39 ] . V_172 > V_170 -> V_172 )
V_11 -> V_191 [ V_39 ] . V_172 = V_170 -> V_172 ;
}
}
F_41 ( & V_3 -> V_5 . V_6 . V_40 . V_45 ,
& V_174 ) ;
F_41 ( & V_3 -> V_5 . V_6 . V_40 . V_192 ,
& V_175 ) ;
F_41 ( & V_3 -> V_5 . V_6 . V_40 . V_193 ,
& V_176 ) ;
for ( V_39 = 0 ; V_39 < V_11 -> V_190 ; V_39 ++ ) {
if ( V_174 ) {
if ( V_11 -> V_191 [ V_39 ] . V_172 > V_174 )
V_11 -> V_191 [ V_39 ] . V_172 = V_174 ;
}
if ( V_175 ) {
if ( V_11 -> V_191 [ V_39 ] . V_173 > V_175 )
V_11 -> V_191 [ V_39 ] . V_173 = V_175 ;
}
if ( V_176 ) {
if ( V_11 -> V_191 [ V_39 ] . V_173 > V_176 )
V_11 -> V_191 [ V_39 ] . V_173 = V_176 ;
}
}
if ( V_171 ) {
V_173 = V_11 -> V_191 [ V_11 -> V_190 - 1 ] . V_173 ;
V_172 = V_11 -> V_191 [ 0 ] . V_172 ;
} else {
V_173 = V_11 -> V_191 [ 0 ] . V_173 ;
V_172 = V_11 -> V_191 [ 0 ] . V_172 ;
}
if ( V_10 -> V_177 ) {
if ( V_172 < V_3 -> V_5 . V_6 . V_179 [ V_3 -> V_5 . V_6 . V_180 ] . V_172 )
V_172 = V_3 -> V_5 . V_6 . V_179 [ V_3 -> V_5 . V_6 . V_180 ] . V_172 ;
if ( V_173 < V_3 -> V_5 . V_6 . V_179 [ V_3 -> V_5 . V_6 . V_180 ] . V_173 )
V_173 = V_3 -> V_5 . V_6 . V_179 [ V_3 -> V_5 . V_6 . V_180 ] . V_173 ;
}
V_11 -> V_191 [ 0 ] . V_172 = V_172 ;
V_11 -> V_191 [ 0 ] . V_173 = V_173 ;
if ( V_11 -> V_191 [ 1 ] . V_172 < V_11 -> V_191 [ 0 ] . V_172 )
V_11 -> V_191 [ 1 ] . V_172 = V_11 -> V_191 [ 0 ] . V_172 ;
if ( V_171 ) {
if ( V_11 -> V_191 [ 0 ] . V_173 < V_11 -> V_191 [ 1 ] . V_173 )
V_11 -> V_191 [ 0 ] . V_173 = V_11 -> V_191 [ 1 ] . V_173 ;
} else {
if ( V_11 -> V_191 [ 1 ] . V_173 < V_11 -> V_191 [ 0 ] . V_173 )
V_11 -> V_191 [ 1 ] . V_173 = V_11 -> V_191 [ 0 ] . V_173 ;
}
}
static int F_42 ( struct V_2 * V_3 ,
int V_194 , int V_195 )
{
int V_196 = 0 * 1000 ;
int V_197 = 255 * 1000 ;
T_3 V_198 ;
if ( V_196 < V_194 )
V_196 = V_194 ;
if ( V_197 > V_195 )
V_197 = V_195 ;
if ( V_197 < V_196 ) {
F_43 ( L_1 , V_196 , V_197 ) ;
return - V_43 ;
}
V_198 = F_23 ( V_199 ) ;
V_198 &= ~ ( V_200 | V_201 ) ;
V_198 |= F_44 ( V_197 / 1000 ) |
F_45 ( V_196 / 1000 ) ;
F_25 ( V_199 , V_198 ) ;
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DIG_THERM_DPM_MASK;
tmp |= DIG_THERM_DPM(high_temp / 1000);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
return 0 ;
}
static int F_46 ( struct V_2 * V_3 ,
T_2 V_202 , T_3 V_55 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_47 ( V_3 ,
V_4 -> V_203 + V_202 ,
V_55 , V_4 -> V_78 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_4 * V_204 = & V_4 -> V_92 ;
if ( V_4 -> V_205 ) {
T_2 V_198 ;
V_198 = 45 ;
V_204 -> V_206 = F_9 ( V_198 ) ;
V_198 = 30 ;
V_204 -> V_207 = F_9 ( V_198 ) ;
}
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 = 0 ;
T_3 V_208 = 0 ;
if ( V_4 -> V_209 ) {
V_208 = F_16 ( V_4 -> V_208 ) ;
V_72 = F_18 ( V_3 ,
V_4 -> V_210 +
F_12 ( T_4 , V_211 ) ,
( T_1 * ) & V_208 ,
sizeof( T_3 ) , V_4 -> V_78 ) ;
}
return V_72 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_212 , V_213 ;
T_2 V_30 , V_214 ;
int V_39 ;
V_4 -> V_215 . V_44 = 0 ;
V_4 -> V_216 . V_44 = 0 ;
if ( F_51 ( V_3 , & V_212 ) == 0 ) {
for ( V_39 = 0 ; V_39 < V_217 ; V_39 ++ ) {
V_213 = V_218 + V_39 ;
if ( F_52 ( V_3 , & V_30 , & V_214 ,
V_213 ,
V_212 ) == 0 ) {
if ( V_30 != 0 && V_30 != V_213 ) {
V_4 -> V_215 . V_219 [ V_4 -> V_215 . V_44 ] = V_30 ;
V_4 -> V_215 . V_212 [ V_4 -> V_215 . V_44 ] = V_213 ;
V_4 -> V_215 . V_44 ++ ;
}
if ( V_214 != 0 && V_214 != V_213 ) {
V_4 -> V_216 . V_219 [ V_4 -> V_216 . V_44 ] = V_214 ;
V_4 -> V_216 . V_212 [ V_4 -> V_216 . V_44 ] = V_213 ;
V_4 -> V_216 . V_44 ++ ;
}
}
}
}
}
static void F_53 ( struct V_2 * V_3 , T_3 V_220 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
bool V_221 ;
enum V_222 V_223 ;
T_3 V_198 ;
switch ( V_220 ) {
case 0 :
default:
V_221 = false ;
break;
case ( 1 << V_224 ) :
V_221 = true ;
V_223 = V_225 ;
break;
case ( 1 << V_226 ) :
V_221 = true ;
V_223 = V_227 ;
break;
case ( ( 1 << V_226 ) |
( 1 << V_224 ) ) :
V_221 = true ;
V_223 = V_228 ;
break;
}
if ( V_221 ) {
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DPM_EVENT_SRC_MASK;
tmp |= DPM_EVENT_SRC(dpm_event_src);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
V_198 = F_23 ( V_229 ) ;
if ( V_4 -> V_230 )
V_198 &= ~ V_231 ;
else
V_198 |= V_231 ;
F_25 ( V_229 , V_198 ) ;
} else {
V_198 = F_23 ( V_229 ) ;
V_198 |= V_231 ;
F_25 ( V_229 , V_198 ) ;
}
}
static void F_54 ( struct V_2 * V_3 ,
enum V_232 V_233 ,
bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_125 ) {
if ( ! ( V_4 -> V_234 & ( 1 << V_233 ) ) ) {
V_4 -> V_234 |= 1 << V_233 ;
F_53 ( V_3 , V_4 -> V_234 ) ;
}
} else {
if ( V_4 -> V_234 & ( 1 << V_233 ) ) {
V_4 -> V_234 &= ~ ( 1 << V_233 ) ;
F_53 ( V_3 , V_4 -> V_234 ) ;
}
}
}
static void F_55 ( struct V_2 * V_3 )
{
if ( V_3 -> V_5 . V_6 . V_46 & V_235 )
F_31 ( V_3 , V_236 ) ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
if ( ! V_4 -> V_237 )
return 0 ;
if ( ( ! V_4 -> V_238 ) &&
( V_4 -> V_237 & ( V_239 | V_240 ) ) ) {
V_143 = F_31 ( V_3 , V_241 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ( ! V_4 -> V_242 ) &&
( V_4 -> V_237 & V_243 ) ) {
V_143 = F_31 ( V_3 , V_244 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
V_4 -> V_237 = 0 ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
if ( V_125 ) {
if ( ! V_4 -> V_238 ) {
V_143 = F_31 ( V_3 , V_245 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ! V_4 -> V_242 ) {
V_143 = F_31 ( V_3 , V_246 ) ;
if ( V_143 != V_146 )
return - V_43 ;
F_58 ( V_247 , V_248 , ~ V_248 ) ;
F_25 ( V_249 , 0x05 ) ;
F_25 ( V_250 , 0x05 ) ;
F_25 ( V_251 , 0x100005 ) ;
F_59 ( 10 ) ;
F_25 ( V_249 , 0x400005 ) ;
F_25 ( V_250 , 0x400005 ) ;
F_25 ( V_251 , 0x500005 ) ;
}
} else {
if ( ! V_4 -> V_238 ) {
V_143 = F_31 ( V_3 , V_252 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ! V_4 -> V_242 ) {
V_143 = F_31 ( V_3 , V_253 ) ;
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
T_3 V_198 ;
V_198 = F_23 ( V_229 ) ;
V_198 |= V_254 ;
F_25 ( V_229 , V_198 ) ;
V_198 = F_23 ( V_255 ) ;
V_198 |= V_256 ;
F_25 ( V_255 , V_198 ) ;
F_46 ( V_3 , F_12 ( V_257 , V_258 ) , 0x1000 ) ;
F_58 ( V_259 , 0 , ~ V_260 ) ;
V_143 = F_31 ( V_3 , V_261 ) ;
if ( V_143 != V_146 )
return - V_43 ;
V_72 = F_57 ( V_3 , true ) ;
if ( V_72 )
return V_72 ;
if ( ! V_4 -> V_262 ) {
V_143 = F_31 ( V_3 , V_263 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
if ( ! V_4 -> V_237 )
return 0 ;
if ( ( ! V_4 -> V_238 ) &&
( V_4 -> V_237 & ( V_239 | V_240 ) ) ) {
V_143 = F_31 ( V_3 , V_264 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ( ! V_4 -> V_242 ) &&
( V_4 -> V_237 & V_243 ) ) {
V_143 = F_31 ( V_3 , V_265 ) ;
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
T_3 V_198 ;
V_198 = F_23 ( V_229 ) ;
V_198 &= ~ V_254 ;
F_25 ( V_229 , V_198 ) ;
V_198 = F_23 ( V_255 ) ;
V_198 &= ~ V_256 ;
F_25 ( V_255 , V_198 ) ;
if ( ! V_4 -> V_262 ) {
V_143 = F_31 ( V_3 , V_266 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
V_72 = F_57 ( V_3 , false ) ;
if ( V_72 )
return V_72 ;
V_143 = F_31 ( V_3 , V_267 ) ;
if ( V_143 != V_146 )
return - V_43 ;
return 0 ;
}
static void F_63 ( struct V_2 * V_3 , bool V_125 )
{
T_3 V_198 = F_23 ( V_255 ) ;
if ( V_125 )
V_198 &= ~ V_268 ;
else
V_198 |= V_268 ;
F_25 ( V_255 , V_198 ) ;
}
static T_5 F_64 ( struct V_2 * V_3 ,
T_7 V_269 , T_3 V_270 )
{
F_26 ( V_271 , V_270 ) ;
return F_31 ( V_3 , V_269 ) ;
}
static T_5 F_65 ( struct V_2 * V_3 ,
T_7 V_269 , T_3 * V_270 )
{
T_5 V_143 ;
V_143 = F_31 ( V_3 , V_269 ) ;
if ( ( V_143 == V_146 ) && V_270 )
* V_270 = F_24 ( V_271 ) ;
return V_143 ;
}
static int F_66 ( struct V_2 * V_3 , T_3 V_272 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_238 ) {
T_5 V_143 =
F_64 ( V_3 , V_273 , V_272 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , T_3 V_272 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_242 ) {
T_5 V_143 =
F_64 ( V_3 , V_274 , V_272 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , T_3 V_272 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_262 ) {
T_5 V_143 =
F_64 ( V_3 , V_275 , V_272 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , T_3 V_272 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_144 & V_153 ) {
T_5 V_143 =
F_64 ( V_3 , V_276 , V_272 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
T_3 V_161 )
{
T_5 V_143 =
F_64 ( V_3 , V_277 , V_161 ) ;
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
T_3 V_278 ;
T_5 V_143 =
F_65 ( V_3 ,
V_279 ,
& V_278 ) ;
if ( V_143 != V_146 )
V_278 = 0 ;
return V_278 ;
}
static T_3 F_71 ( struct V_2 * V_3 )
{
T_3 V_280 ;
T_5 V_143 =
F_65 ( V_3 ,
V_281 ,
& V_280 ) ;
if ( V_143 != V_146 )
V_280 = 0 ;
return V_280 ;
}
static void F_72 ( struct V_2 * V_3 )
{
int V_39 ;
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
F_75 ( V_3 ) ;
for ( V_39 = 0 ; V_39 < V_3 -> V_282 ; V_39 ++ ) {
if ( F_23 ( V_283 ) & V_284 )
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
T_3 V_198 ;
int V_72 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_285 ) ,
& V_198 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_210 = V_198 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_286 ) ,
& V_198 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_203 = V_198 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_287 ) ,
& V_198 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_288 = V_198 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_289 ) ,
& V_198 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_290 = V_198 ;
V_72 = F_11 ( V_3 ,
V_73 +
F_12 ( V_74 , V_291 ) ,
& V_198 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_292 = V_198 ;
return 0 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_293 . V_294 =
F_23 ( V_295 ) ;
V_4 -> V_293 . V_296 =
F_23 ( V_297 ) ;
V_4 -> V_293 . V_298 =
F_23 ( V_299 ) ;
V_4 -> V_293 . V_300 =
F_23 ( V_301 ) ;
V_4 -> V_293 . V_302 =
F_23 ( V_303 ) ;
V_4 -> V_293 . V_304 =
F_23 ( V_305 ) ;
V_4 -> V_293 . V_306 = F_24 ( V_307 ) ;
V_4 -> V_293 . V_308 = F_24 ( V_309 ) ;
V_4 -> V_293 . V_310 = F_24 ( V_311 ) ;
V_4 -> V_293 . V_312 = F_24 ( V_313 ) ;
V_4 -> V_293 . V_314 = F_24 ( V_315 ) ;
V_4 -> V_293 . V_316 = F_24 ( V_317 ) ;
V_4 -> V_293 . V_318 = F_24 ( V_319 ) ;
V_4 -> V_293 . V_320 = F_24 ( V_321 ) ;
V_4 -> V_293 . V_322 = F_24 ( V_323 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_208 = 0 ;
}
static void F_82 ( struct V_2 * V_3 ,
bool V_125 )
{
T_3 V_198 = F_23 ( V_229 ) ;
if ( V_125 )
V_198 &= ~ V_231 ;
else
V_198 |= V_231 ;
F_25 ( V_229 , V_198 ) ;
}
static void F_83 ( struct V_2 * V_3 )
{
T_3 V_198 = F_23 ( V_229 ) ;
V_198 |= V_324 ;
F_25 ( V_229 , V_198 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
bool V_325 )
{
T_7 V_269 = V_325 ? V_326 : V_327 ;
return ( F_31 ( V_3 , V_269 ) == V_146 ) ? 0 : - V_43 ;
}
static int F_85 ( struct V_2 * V_3 ,
bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_125 ) {
if ( V_4 -> V_328 ) {
if ( F_31 ( V_3 , V_329 ) != V_146 )
return - V_43 ;
} else {
if ( F_31 ( V_3 , V_330 ) != V_146 )
return - V_43 ;
}
} else {
if ( V_4 -> V_328 ) {
if ( F_31 ( V_3 , V_330 ) != V_146 )
return - V_43 ;
}
}
return 0 ;
}
static void F_86 ( struct V_2 * V_3 )
{
T_3 V_198 = F_23 ( V_331 ) ;
T_3 V_332 ;
T_3 V_333 ;
T_3 V_334 = V_3 -> clock . V_335 . V_336 ;
T_3 V_337 = F_87 ( V_3 ) ;
T_3 V_166 = F_39 ( V_3 ) ;
V_198 &= ~ V_338 ;
if ( V_3 -> V_5 . V_6 . V_182 > 0 )
V_198 |= F_88 ( V_339 ) ;
else
V_198 |= F_88 ( V_340 ) ;
F_25 ( V_331 , V_198 ) ;
if ( V_337 == 0 )
V_337 = 60 ;
if ( V_166 == 0xffffffff )
V_166 = 500 ;
V_333 = 1000000 / V_337 ;
V_332 =
V_333 - 200 - V_166 ;
V_198 = V_332 * ( V_334 / 100 ) ;
F_25 ( V_341 , V_198 ) ;
F_46 ( V_3 , F_12 ( V_257 , V_342 ) , 0x64 ) ;
F_46 ( V_3 , F_12 ( V_257 , V_343 ) , ( V_333 - V_332 ) ) ;
F_84 ( V_3 , ( V_3 -> V_5 . V_6 . V_182 == 1 ) ) ;
}
static void F_89 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_198 ;
if ( V_125 ) {
if ( V_4 -> V_344 ) {
V_198 = F_23 ( V_229 ) ;
V_198 |= V_345 ;
F_25 ( V_229 , V_198 ) ;
}
} else {
V_198 = F_23 ( V_303 ) ;
V_198 &= ~ V_346 ;
F_25 ( V_303 , V_198 ) ;
V_198 = F_23 ( V_229 ) ;
V_198 &= ~ V_345 ;
F_25 ( V_229 , V_198 ) ;
}
}
static void F_90 ( struct V_2 * V_3 )
{
F_25 ( V_347 , ( F_91 ( V_348 ) | F_92 ( V_349 ) ) ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
T_3 V_198 = F_23 ( V_331 ) ;
V_198 &= ~ ( V_338 | V_350 ) ;
V_198 |= ( F_88 ( V_340 ) |
F_94 ( V_351 ) ) ;
F_25 ( V_331 , V_198 ) ;
}
static void F_95 ( struct V_2 * V_3 )
{
T_3 V_198 ;
V_198 = F_23 ( V_255 ) ;
V_198 &= ~ ( V_352 | V_353 ) ;
F_25 ( V_255 , V_198 ) ;
F_25 ( V_354 , V_355 ) ;
F_25 ( V_356 , V_357 ) ;
F_25 ( V_358 , V_359 ) ;
F_25 ( V_360 , V_361 ) ;
F_25 ( V_362 , V_363 ) ;
F_25 ( V_364 , V_365 ) ;
F_25 ( V_366 , V_367 ) ;
F_25 ( V_368 , V_369 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
T_3 V_198 ;
V_198 = F_23 ( V_255 ) ;
V_198 |= ( V_352 | V_353 ) ;
F_25 ( V_255 , V_198 ) ;
F_25 ( V_354 , 0 ) ;
F_25 ( V_356 , 0 ) ;
F_25 ( V_358 , 0 ) ;
F_25 ( V_360 , 0 ) ;
F_25 ( V_362 , 0 ) ;
F_25 ( V_364 , 0 ) ;
F_25 ( V_366 , 0 ) ;
F_25 ( V_368 , 0 ) ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_39 , V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_282 ; V_39 ++ ) {
if ( F_23 ( V_370 ) & V_371 )
break;
}
F_25 ( V_372 , 1 ) ;
F_78 ( V_3 ) ;
F_77 ( V_3 ) ;
V_72 = F_98 ( V_3 , V_4 -> V_78 ) ;
return V_72 ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_373 * V_374 ,
struct V_375 * V_376 )
{
T_3 V_39 ;
if ( V_374 == NULL )
return - V_43 ;
V_376 -> V_377 = 0 ;
V_376 -> V_378 = 0 ;
V_376 -> V_44 = V_374 -> V_44 ;
for ( V_39 = 0 ; V_39 < V_376 -> V_44 ; V_39 ++ ) {
V_376 -> V_42 [ V_39 ] . V_55 = V_374 -> V_42 [ V_39 ] . V_379 ;
V_376 -> V_42 [ V_39 ] . V_380 = 0 ;
}
return 0 ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
if ( V_4 -> V_381 == V_382 ) {
V_72 = F_101 ( V_3 , V_383 ,
V_384 ,
& V_4 -> V_54 ) ;
if ( V_72 )
return V_72 ;
} else if ( V_4 -> V_381 == V_385 ) {
V_72 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_193 ,
& V_4 -> V_54 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_4 -> V_54 . V_44 > V_386 )
F_102 ( V_3 , V_386 ,
& V_4 -> V_54 ) ;
if ( V_4 -> V_387 == V_382 ) {
V_72 = F_101 ( V_3 , V_388 ,
V_384 ,
& V_4 -> V_389 ) ;
if ( V_72 )
return V_72 ;
} else if ( V_4 -> V_387 == V_385 ) {
V_72 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_192 ,
& V_4 -> V_389 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_4 -> V_389 . V_44 > V_390 )
F_102 ( V_3 , V_390 ,
& V_4 -> V_389 ) ;
if ( V_4 -> V_391 == V_382 ) {
V_72 = F_101 ( V_3 , V_392 ,
V_384 ,
& V_4 -> V_393 ) ;
if ( V_72 )
return V_72 ;
} else if ( V_4 -> V_391 == V_385 ) {
V_72 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_394 ,
& V_4 -> V_393 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_4 -> V_393 . V_44 > V_395 )
F_102 ( V_3 , V_395 ,
& V_4 -> V_393 ) ;
return 0 ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_396 * V_376 ,
T_8 * V_397 )
{
int V_72 ;
V_72 = F_104 ( V_3 , V_376 ,
& V_397 -> V_398 ,
& V_397 -> V_399 ) ;
if ( V_72 ) {
V_397 -> V_398 = V_376 -> V_55 * V_31 ;
V_397 -> V_399 = V_376 -> V_55 * V_31 ;
}
V_397 -> V_400 = F_9 ( V_376 -> V_55 * V_31 ) ;
V_397 -> V_398 =
F_9 ( V_397 -> V_398 ) ;
V_397 -> V_399 =
F_9 ( V_397 -> V_399 ) ;
}
static int F_105 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_44 ;
V_204 -> V_401 = V_4 -> V_54 . V_44 ;
for ( V_44 = 0 ; V_44 < V_204 -> V_401 ; V_44 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_54 . V_42 [ V_44 ] ,
& V_204 -> V_402 [ V_44 ] ) ;
if ( V_4 -> V_381 == V_382 )
V_204 -> V_402 [ V_44 ] . V_403 |=
V_4 -> V_54 . V_42 [ V_44 ] . V_380 ;
else
V_204 -> V_402 [ V_44 ] . V_403 = 0 ;
}
V_204 -> V_401 = F_16 ( V_204 -> V_401 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
unsigned int V_44 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_204 -> V_404 = V_4 -> V_389 . V_44 ;
for ( V_44 = 0 ; V_44 < V_204 -> V_404 ; V_44 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_389 . V_42 [ V_44 ] ,
& V_204 -> V_405 [ V_44 ] ) ;
if ( V_4 -> V_387 == V_382 )
V_204 -> V_405 [ V_44 ] . V_403 |=
V_4 -> V_389 . V_42 [ V_44 ] . V_380 ;
else
V_204 -> V_405 [ V_44 ] . V_403 = 0 ;
}
V_204 -> V_404 = F_16 ( V_204 -> V_404 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_44 ;
V_204 -> V_406 = V_4 -> V_393 . V_44 ;
for ( V_44 = 0 ; V_44 < V_204 -> V_406 ; V_44 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_393 . V_42 [ V_44 ] ,
& V_204 -> V_407 [ V_44 ] ) ;
if ( V_4 -> V_391 == V_382 )
V_204 -> V_407 [ V_44 ] . V_403 |=
V_4 -> V_393 . V_42 [ V_44 ] . V_380 ;
else
V_204 -> V_407 [ V_44 ] . V_403 = 0 ;
}
V_204 -> V_406 = F_16 ( V_204 -> V_406 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
int V_72 ;
V_72 = F_105 ( V_3 , V_204 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_106 ( V_3 , V_204 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_107 ( V_3 , V_204 ) ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , T_3 V_173 ,
T_8 * V_408 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 = 0 ;
if ( V_4 -> V_391 != V_409 ) {
for ( V_39 = 0 ; V_39 < V_3 -> V_5 . V_6 . V_40 . V_394 . V_44 ; V_39 ++ ) {
if ( V_173 <= V_3 -> V_5 . V_6 . V_40 . V_394 . V_42 [ V_39 ] . V_410 ) {
V_408 -> V_400 = V_4 -> V_393 . V_42 [ V_39 ] . V_55 ;
break;
}
}
if ( V_39 >= V_3 -> V_5 . V_6 . V_40 . V_394 . V_44 )
return - V_43 ;
}
return - V_43 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_396 * V_376 ,
T_2 * V_411 , T_2 * V_412 )
{
T_2 V_413 , V_414 ;
bool V_415 = false ;
* V_411 = V_376 -> V_55 * V_31 ;
* V_412 = V_376 -> V_55 * V_31 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 == NULL )
return - V_43 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 ) {
for ( V_413 = 0 ; ( T_3 ) V_413 < V_3 -> V_5 . V_6 . V_40 . V_45 . V_44 ; V_413 ++ ) {
if ( V_376 -> V_55 ==
V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ V_413 ] . V_379 ) {
V_415 = true ;
if ( ( T_3 ) V_413 < V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 )
V_414 = V_413 ;
else
V_414 = V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 - 1 ;
* V_412 =
V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_414 ] . V_30 * V_31 ;
* V_411 =
V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_414 ] . V_51 * V_31 ;
break;
}
}
if ( ! V_415 ) {
for ( V_413 = 0 ; ( T_3 ) V_413 < V_3 -> V_5 . V_6 . V_40 . V_45 . V_44 ; V_413 ++ ) {
if ( V_376 -> V_55 <=
V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ V_413 ] . V_379 ) {
V_415 = true ;
if ( ( T_3 ) V_413 < V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 )
V_414 = V_413 ;
else
V_414 = V_3 -> V_5 . V_6 . V_40 . V_41 . V_44 - 1 ;
* V_412 =
V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_414 ] . V_30 * V_31 ;
* V_411 =
V_3 -> V_5 . V_6 . V_40 . V_41 . V_42 [ V_414 ] . V_51 * V_31 ;
break;
}
}
}
}
return 0 ;
}
static void F_110 ( struct V_2 * V_3 ,
const struct V_416 * V_417 ,
T_3 V_172 ,
T_3 * V_418 )
{
unsigned int V_39 ;
* V_418 = 1 ;
for ( V_39 = 0 ; V_39 < V_417 -> V_44 ; V_39 ++ ) {
if ( V_172 < V_417 -> V_42 [ V_39 ] . V_172 ) {
* V_418 = V_39 ;
break;
}
}
}
static void F_111 ( struct V_2 * V_3 ,
const struct V_416 * V_417 ,
T_3 V_173 ,
T_3 * V_418 )
{
unsigned int V_39 ;
* V_418 = 1 ;
for ( V_39 = 0 ; V_39 < V_417 -> V_44 ; V_39 ++ ) {
if ( V_173 < V_417 -> V_42 [ V_39 ] . V_173 ) {
* V_418 = V_39 ;
break;
}
}
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_198 ;
int V_72 ;
V_72 = F_11 ( V_3 , V_4 -> V_292 ,
& V_198 , V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
V_198 &= 0x00FFFFFF ;
V_198 |= V_419 << 24 ;
return F_47 ( V_3 , V_4 -> V_292 ,
V_198 , V_4 -> V_78 ) ;
}
static int F_113 ( struct V_2 * V_3 ,
struct V_373 * V_420 ,
T_3 clock , T_3 * V_408 )
{
T_3 V_39 = 0 ;
if ( V_420 -> V_44 == 0 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_420 -> V_44 ; V_39 ++ ) {
if ( V_420 -> V_42 [ V_39 ] . V_410 >= clock ) {
* V_408 = V_420 -> V_42 [ V_39 ] . V_379 ;
return 0 ;
}
}
* V_408 = V_420 -> V_42 [ V_39 - 1 ] . V_379 ;
return 0 ;
}
static T_1 F_114 ( struct V_2 * V_3 ,
T_3 V_172 , T_3 V_421 )
{
T_3 V_39 ;
T_3 V_198 ;
T_3 V_80 = ( V_421 > V_422 ) ?
V_421 : V_422 ;
if ( V_172 < V_80 )
return 0 ;
for ( V_39 = V_423 ; ; V_39 -- ) {
V_198 = V_172 / ( 1 << V_39 ) ;
if ( V_198 >= V_80 || V_39 == 0 )
break;
}
return ( T_1 ) V_39 ;
}
static int F_115 ( struct V_2 * V_3 )
{
return F_116 ( V_3 , V_424 , V_419 ) ;
}
static int F_117 ( struct V_2 * V_3 )
{
return ( F_31 ( V_3 , V_425 ) == V_146 ) ?
0 : - V_43 ;
}
static int F_118 ( struct V_2 * V_3 )
{
T_3 V_198 ;
V_198 = ( F_23 ( V_426 ) & 0x0000ff00 ) >> 8 ;
if ( V_198 == V_424 )
return 0 ;
return F_116 ( V_3 , V_198 , V_424 ) ;
}
static int F_119 ( struct V_2 * V_3 ,
T_3 V_172 ,
T_3 V_173 ,
T_9 * V_427 )
{
T_3 V_428 ;
T_3 V_429 ;
T_3 V_430 ;
F_120 ( V_3 , V_172 , V_173 ) ;
V_428 = F_24 ( V_431 ) ;
V_429 = F_24 ( V_432 ) ;
V_430 = F_24 ( V_433 ) & V_434 ;
V_427 -> V_435 = F_16 ( V_428 ) ;
V_427 -> V_436 = F_16 ( V_429 ) ;
V_427 -> V_437 = ( T_1 ) V_430 ;
return 0 ;
}
static int F_121 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_10 V_427 ;
T_3 V_39 , V_96 ;
int V_72 = 0 ;
memset ( & V_427 , 0 , sizeof( T_10 ) ) ;
for ( V_39 = 0 ; V_39 < V_4 -> V_91 . V_438 . V_44 ; V_39 ++ ) {
for ( V_96 = 0 ; V_96 < V_4 -> V_91 . V_439 . V_44 ; V_96 ++ ) {
V_72 = F_119 ( V_3 ,
V_4 -> V_91 . V_438 . V_440 [ V_39 ] . V_55 ,
V_4 -> V_91 . V_439 . V_440 [ V_96 ] . V_55 ,
& V_427 . V_42 [ V_39 ] [ V_96 ] ) ;
if ( V_72 )
break;
}
}
if ( V_72 == 0 )
V_72 = F_18 ( V_3 ,
V_4 -> V_292 ,
( T_1 * ) & V_427 ,
sizeof( T_10 ) ,
V_4 -> V_78 ) ;
return V_72 ;
}
static int F_122 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_237 == 0 )
return 0 ;
return F_121 ( V_3 ) ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_9 * V_441 )
{
struct V_8 * V_442 = F_2 ( V_441 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_443 = 0 ;
for ( V_443 = 0 ; V_443 < V_3 -> V_5 . V_6 . V_40 . V_45 . V_44 ; V_443 ++ ) {
if ( V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ V_443 ] . V_410 >=
V_442 -> V_191 [ 0 ] . V_172 ) {
V_4 -> V_92 . V_444 = V_443 ;
break;
}
}
for ( V_443 = 0 ; V_443 < V_3 -> V_5 . V_6 . V_40 . V_193 . V_44 ; V_443 ++ ) {
if ( V_3 -> V_5 . V_6 . V_40 . V_193 . V_42 [ V_443 ] . V_410 >=
V_442 -> V_191 [ 0 ] . V_173 ) {
V_4 -> V_92 . V_445 = V_443 ;
break;
}
}
}
static T_3 F_124 ( struct V_446 * V_91 )
{
T_3 V_39 ;
T_3 V_447 = 0 ;
for ( V_39 = V_91 -> V_44 ; V_39 > 0 ; V_39 -- ) {
V_447 = V_447 << 1 ;
if ( V_91 -> V_440 [ V_39 - 1 ] . V_448 )
V_447 |= 0x1 ;
else
V_447 &= 0xFFFFFFFE ;
}
return V_447 ;
}
static void F_125 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_449 * V_91 = & V_4 -> V_91 ;
T_3 V_39 ;
for ( V_39 = 0 ; V_39 < V_91 -> V_450 . V_44 ; V_39 ++ ) {
V_204 -> V_451 [ V_39 ] . V_452 =
( T_1 ) V_91 -> V_450 . V_440 [ V_39 ] . V_55 ;
V_204 -> V_451 [ V_39 ] . V_453 =
F_126 ( V_91 -> V_450 . V_440 [ V_39 ] . V_454 ) ;
V_204 -> V_451 [ V_39 ] . V_455 = 1 ;
V_204 -> V_451 [ V_39 ] . V_456 = F_16 ( 5 ) ;
V_204 -> V_451 [ V_39 ] . V_457 = F_16 ( 30 ) ;
}
V_4 -> V_92 . V_458 = ( T_1 ) V_91 -> V_450 . V_44 ;
V_4 -> V_459 . V_460 =
F_124 ( & V_91 -> V_450 ) ;
}
static int F_127 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
T_3 V_44 ;
struct V_461 V_462 ;
int V_72 = - V_43 ;
V_204 -> V_463 =
V_3 -> V_5 . V_6 . V_40 . V_464 . V_44 ;
for ( V_44 = 0 ; V_44 < V_204 -> V_463 ; V_44 ++ ) {
V_204 -> V_465 [ V_44 ] . V_466 =
V_3 -> V_5 . V_6 . V_40 . V_464 . V_42 [ V_44 ] . V_467 ;
V_204 -> V_465 [ V_44 ] . V_468 =
V_3 -> V_5 . V_6 . V_40 . V_464 . V_42 [ V_44 ] . V_469 ;
V_204 -> V_465 [ V_44 ] . V_470 =
V_3 -> V_5 . V_6 . V_40 . V_464 . V_42 [ V_44 ] . V_379 * V_31 ;
V_204 -> V_465 [ V_44 ] . V_471 = 1 ;
V_72 = F_128 ( V_3 ,
V_472 ,
V_204 -> V_465 [ V_44 ] . V_466 , false , & V_462 ) ;
if ( V_72 )
return V_72 ;
V_204 -> V_465 [ V_44 ] . V_473 = ( T_1 ) V_462 . V_474 ;
V_72 = F_128 ( V_3 ,
V_472 ,
V_204 -> V_465 [ V_44 ] . V_468 , false , & V_462 ) ;
if ( V_72 )
return V_72 ;
V_204 -> V_465 [ V_44 ] . V_475 = ( T_1 ) V_462 . V_474 ;
V_204 -> V_465 [ V_44 ] . V_466 = F_16 ( V_204 -> V_465 [ V_44 ] . V_466 ) ;
V_204 -> V_465 [ V_44 ] . V_468 = F_16 ( V_204 -> V_465 [ V_44 ] . V_468 ) ;
V_204 -> V_465 [ V_44 ] . V_470 = F_9 ( V_204 -> V_465 [ V_44 ] . V_470 ) ;
}
return V_72 ;
}
static int F_129 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
T_3 V_44 ;
struct V_461 V_462 ;
int V_72 = - V_43 ;
V_204 -> V_476 =
V_3 -> V_5 . V_6 . V_40 . V_477 . V_44 ;
for ( V_44 = 0 ; V_44 < V_204 -> V_476 ; V_44 ++ ) {
V_204 -> V_478 [ V_44 ] . V_479 =
V_3 -> V_5 . V_6 . V_40 . V_477 . V_42 [ V_44 ] . V_178 ;
V_204 -> V_478 [ V_44 ] . V_480 =
( T_2 ) V_3 -> V_5 . V_6 . V_40 . V_477 . V_42 [ V_44 ] . V_379 * V_31 ;
V_204 -> V_478 [ V_44 ] . V_481 = 1 ;
V_72 = F_128 ( V_3 ,
V_472 ,
V_204 -> V_478 [ V_44 ] . V_479 , false , & V_462 ) ;
if ( V_72 )
return V_72 ;
V_204 -> V_478 [ V_44 ] . V_482 = ( T_1 ) V_462 . V_474 ;
V_204 -> V_478 [ V_44 ] . V_479 = F_16 ( V_204 -> V_478 [ V_44 ] . V_479 ) ;
V_204 -> V_478 [ V_44 ] . V_480 = F_9 ( V_204 -> V_478 [ V_44 ] . V_480 ) ;
}
return V_72 ;
}
static int F_130 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
T_3 V_44 ;
struct V_461 V_462 ;
int V_72 = - V_43 ;
V_204 -> V_483 = ( T_1 )
( V_3 -> V_5 . V_6 . V_40 . V_484 . V_44 ) ;
for ( V_44 = 0 ; V_44 < V_204 -> V_483 ; V_44 ++ ) {
V_204 -> V_485 [ V_44 ] . V_479 =
V_3 -> V_5 . V_6 . V_40 . V_484 . V_42 [ V_44 ] . V_410 ;
V_204 -> V_485 [ V_44 ] . V_480 =
V_3 -> V_5 . V_6 . V_40 . V_484 . V_42 [ V_44 ] . V_379 ;
V_204 -> V_485 [ V_44 ] . V_481 = 1 ;
V_72 = F_128 ( V_3 ,
V_472 ,
V_204 -> V_485 [ V_44 ] . V_479 , false , & V_462 ) ;
if ( V_72 )
return V_72 ;
V_204 -> V_485 [ V_44 ] . V_482 = ( T_1 ) V_462 . V_474 ;
V_204 -> V_485 [ V_44 ] . V_479 = F_16 ( V_204 -> V_485 [ V_44 ] . V_479 ) ;
V_204 -> V_485 [ V_44 ] . V_480 = F_9 ( V_204 -> V_485 [ V_44 ] . V_480 ) ;
}
return V_72 ;
}
static int F_131 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
T_3 V_44 ;
struct V_461 V_462 ;
int V_72 = - V_43 ;
V_204 -> V_486 =
V_3 -> V_5 . V_6 . V_40 . V_487 . V_44 ;
for ( V_44 = 0 ; V_44 < V_204 -> V_486 ; V_44 ++ ) {
V_204 -> V_488 [ V_44 ] . V_479 =
V_3 -> V_5 . V_6 . V_40 . V_487 . V_42 [ V_44 ] . V_410 ;
V_204 -> V_488 [ V_44 ] . V_480 =
V_3 -> V_5 . V_6 . V_40 . V_487 . V_42 [ V_44 ] . V_379 * V_31 ;
V_204 -> V_488 [ V_44 ] . V_481 = 1 ;
V_72 = F_128 ( V_3 ,
V_472 ,
V_204 -> V_488 [ V_44 ] . V_479 , false , & V_462 ) ;
if ( V_72 )
return V_72 ;
V_204 -> V_488 [ V_44 ] . V_482 = ( T_1 ) V_462 . V_474 ;
V_204 -> V_488 [ V_44 ] . V_479 = F_16 ( V_204 -> V_488 [ V_44 ] . V_479 ) ;
V_204 -> V_488 [ V_44 ] . V_480 = F_9 ( V_204 -> V_488 [ V_44 ] . V_480 ) ;
}
return V_72 ;
}
static int F_132 ( struct V_2 * V_3 ,
T_3 V_489 ,
T_11 * V_173 ,
bool V_490 ,
bool V_491 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_306 = V_4 -> V_293 . V_306 ;
T_3 V_308 = V_4 -> V_293 . V_308 ;
T_3 V_310 = V_4 -> V_293 . V_310 ;
T_3 V_312 = V_4 -> V_293 . V_312 ;
T_3 V_314 = V_4 -> V_293 . V_314 ;
T_3 V_316 = V_4 -> V_293 . V_316 ;
T_3 V_318 = V_4 -> V_293 . V_318 ;
T_3 V_320 = V_4 -> V_293 . V_320 ;
T_3 V_322 = V_4 -> V_293 . V_322 ;
struct V_492 V_493 ;
int V_72 ;
V_72 = F_133 ( V_3 , V_489 , V_490 , & V_493 ) ;
if ( V_72 )
return V_72 ;
V_314 &= ~ V_494 ;
V_314 |= F_134 ( V_493 . V_495 ) ;
V_316 &= ~ ( V_496 | V_497 | V_498 ) ;
V_316 |= F_135 ( V_493 . V_499 ) |
F_136 ( V_493 . V_500 ) | F_137 ( V_493 . V_501 ) ;
V_310 &= ~ V_502 ;
V_310 |= F_138 ( V_493 . V_503 ) ;
if ( V_4 -> V_168 ) {
V_312 &= ~ ( V_504 | V_502 ) ;
V_312 |= F_139 ( V_493 . V_505 ) |
F_138 ( V_493 . V_503 ) ;
}
if ( V_4 -> V_506 ) {
struct V_507 V_508 ;
T_3 V_509 ;
T_3 V_198 ;
T_3 V_510 = V_3 -> clock . V_511 . V_336 ;
if ( V_4 -> V_168 )
V_509 = V_489 * 4 ;
else
V_509 = V_489 * 2 ;
V_198 = ( V_509 / V_510 ) ;
V_198 = V_198 * V_198 ;
if ( F_140 ( V_3 , & V_508 ,
V_512 , V_509 ) ) {
T_3 V_513 = V_510 * 5 / V_508 . V_514 ;
T_3 V_515 = ( T_3 ) ( ( ( ( 131 * V_508 . V_516 * V_508 . V_514 ) / 100 ) * V_198 ) / V_509 ) ;
V_320 &= ~ V_517 ;
V_320 |= F_141 ( V_515 ) ;
V_322 &= ~ V_518 ;
V_322 |= F_142 ( V_513 ) ;
}
}
V_308 &= ~ V_519 ;
V_308 |= F_143 ( V_493 . V_520 ) ;
if ( V_491 )
V_308 |= V_521 | V_522 ;
else
V_308 &= ~ ( V_521 | V_522 ) ;
V_173 -> V_523 = V_489 ;
V_173 -> V_524 = V_314 ;
V_173 -> V_525 = V_316 ;
V_173 -> V_526 = V_318 ;
V_173 -> V_527 = V_310 ;
V_173 -> V_528 = V_312 ;
V_173 -> V_529 = V_308 ;
V_173 -> V_530 = V_306 ;
V_173 -> V_531 = V_320 ;
V_173 -> V_532 = V_322 ;
return 0 ;
}
static int F_144 ( struct V_2 * V_3 ,
T_3 V_489 ,
T_11 * V_533 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
bool V_491 ;
if ( V_3 -> V_5 . V_6 . V_40 . V_193 . V_42 ) {
V_72 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_193 ,
V_489 , & V_533 -> V_470 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_3 -> V_5 . V_6 . V_40 . V_192 . V_42 ) {
V_72 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_192 ,
V_489 , & V_533 -> V_534 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_3 -> V_5 . V_6 . V_40 . V_394 . V_42 ) {
V_72 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_394 ,
V_489 , & V_533 -> V_535 ) ;
if ( V_72 )
return V_72 ;
}
V_533 -> V_471 = 1 ;
if ( V_4 -> V_536 )
F_111 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_537 ,
V_489 ,
& V_533 -> V_471 ) ;
V_533 -> V_538 = 1 ;
V_533 -> V_455 = 1 ;
V_533 -> V_539 = 0 ;
V_533 -> V_540 = 100 ;
V_533 -> V_541 = 0 ;
V_533 -> V_542 = ( T_2 ) V_4 -> V_543 ;
V_533 -> V_544 = false ;
V_533 -> V_545 = false ;
V_533 -> V_546 = false ;
V_533 -> V_547 = false ;
V_533 -> V_548 = false ;
V_533 -> V_549 = V_550 ;
if ( V_4 -> V_551 &&
( V_489 <= V_4 -> V_551 ) &&
( V_4 -> V_552 == false ) &&
( F_24 ( V_553 ) & V_554 ) &&
( V_3 -> V_5 . V_6 . V_182 <= 2 ) )
V_533 -> V_544 = true ;
if ( V_4 -> V_555 &&
( V_489 <= V_4 -> V_555 ) )
V_533 -> V_545 = 1 ;
if ( V_4 -> V_168 ) {
V_533 -> V_556 =
F_145 ( V_489 , V_533 -> V_545 ) ;
if ( V_4 -> V_557 &&
( V_489 > V_4 -> V_557 ) )
V_533 -> V_546 = true ;
if ( V_4 -> V_558 &&
( V_489 > V_4 -> V_558 ) )
V_533 -> V_547 = true ;
if ( V_533 -> V_545 ) {
if ( F_145 ( V_489 , true ) >=
( ( F_24 ( V_559 ) >> 16 ) & 0xf ) )
V_491 = ( ( F_24 ( V_560 ) >> 1 ) & 0x1 ) ? true : false ;
else
V_491 = ( ( F_24 ( V_561 ) >> 1 ) & 0x1 ) ? true : false ;
} else {
V_491 = V_4 -> V_562 ;
}
} else {
V_533 -> V_556 = F_146 ( V_489 ) ;
V_491 = ( ( F_24 ( V_560 ) >> 1 ) & 0x1 ) ? true : false ;
}
V_72 = F_132 ( V_3 , V_489 , V_533 , V_533 -> V_545 , V_491 ) ;
if ( V_72 )
return V_72 ;
V_533 -> V_470 = F_16 ( V_533 -> V_470 * V_31 ) ;
V_533 -> V_471 = F_16 ( V_533 -> V_471 ) ;
V_533 -> V_534 = F_16 ( V_533 -> V_534 * V_31 ) ;
V_533 -> V_535 = F_16 ( V_533 -> V_535 * V_31 ) ;
V_533 -> V_523 = F_16 ( V_533 -> V_523 ) ;
V_533 -> V_542 = F_9 ( V_533 -> V_542 ) ;
V_533 -> V_524 = F_16 ( V_533 -> V_524 ) ;
V_533 -> V_525 = F_16 ( V_533 -> V_525 ) ;
V_533 -> V_526 = F_16 ( V_533 -> V_526 ) ;
V_533 -> V_527 = F_16 ( V_533 -> V_527 ) ;
V_533 -> V_528 = F_16 ( V_533 -> V_528 ) ;
V_533 -> V_529 = F_16 ( V_533 -> V_529 ) ;
V_533 -> V_530 = F_16 ( V_533 -> V_530 ) ;
V_533 -> V_531 = F_16 ( V_533 -> V_531 ) ;
V_533 -> V_532 = F_16 ( V_533 -> V_532 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 ,
T_4 * V_204 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_461 V_462 ;
T_8 V_563 ;
T_3 V_564 = V_4 -> V_293 . V_294 ;
T_3 V_565 = V_4 -> V_293 . V_296 ;
T_3 V_306 = V_4 -> V_293 . V_306 ;
T_3 V_308 = V_4 -> V_293 . V_308 ;
int V_72 ;
V_204 -> V_566 . V_567 &= ~ V_568 ;
if ( V_4 -> V_569 )
V_204 -> V_566 . V_470 = F_16 ( V_4 -> V_569 * V_31 ) ;
else
V_204 -> V_566 . V_470 = F_16 ( V_4 -> V_570 * V_31 ) ;
V_204 -> V_566 . V_471 = V_4 -> V_536 ? 0 : 1 ;
V_204 -> V_566 . V_571 = V_3 -> clock . V_335 . V_336 ;
V_72 = F_128 ( V_3 ,
V_572 ,
V_204 -> V_566 . V_571 , false , & V_462 ) ;
if ( V_72 )
return V_72 ;
V_204 -> V_566 . V_573 = ( T_1 ) V_462 . V_474 ;
V_204 -> V_566 . V_549 = V_550 ;
V_204 -> V_566 . V_574 = 0 ;
V_564 &= ~ V_575 ;
V_564 |= V_576 ;
V_565 &= ~ V_577 ;
V_565 |= F_148 ( 4 ) ;
V_204 -> V_566 . V_578 = V_564 ;
V_204 -> V_566 . V_579 = V_565 ;
V_204 -> V_566 . V_580 = V_4 -> V_293 . V_298 ;
V_204 -> V_566 . V_581 = V_4 -> V_293 . V_300 ;
V_204 -> V_566 . V_582 = V_4 -> V_293 . V_302 ;
V_204 -> V_566 . V_583 = V_4 -> V_293 . V_304 ;
V_204 -> V_566 . V_584 = 0 ;
V_204 -> V_566 . V_585 = 0 ;
V_204 -> V_566 . V_567 = F_16 ( V_204 -> V_566 . V_567 ) ;
V_204 -> V_566 . V_471 = F_16 ( V_204 -> V_566 . V_471 ) ;
V_204 -> V_566 . V_571 = F_16 ( V_204 -> V_566 . V_571 ) ;
V_204 -> V_566 . V_578 = F_16 ( V_204 -> V_566 . V_578 ) ;
V_204 -> V_566 . V_579 = F_16 ( V_204 -> V_566 . V_579 ) ;
V_204 -> V_566 . V_580 = F_16 ( V_204 -> V_566 . V_580 ) ;
V_204 -> V_566 . V_581 = F_16 ( V_204 -> V_566 . V_581 ) ;
V_204 -> V_566 . V_582 = F_16 ( V_204 -> V_566 . V_582 ) ;
V_204 -> V_566 . V_583 = F_16 ( V_204 -> V_566 . V_583 ) ;
V_204 -> V_566 . V_584 = F_16 ( V_204 -> V_566 . V_584 ) ;
V_204 -> V_566 . V_585 = F_16 ( V_204 -> V_566 . V_585 ) ;
V_204 -> V_586 . V_470 = V_204 -> V_566 . V_470 ;
V_204 -> V_586 . V_471 = V_204 -> V_566 . V_471 ;
if ( V_4 -> V_387 != V_409 ) {
if ( V_4 -> V_587 )
V_204 -> V_586 . V_534 =
F_16 ( V_4 -> V_587 * V_31 ) ;
else
V_204 -> V_586 . V_534 =
F_16 ( V_4 -> V_588 * V_31 ) ;
}
if ( F_109 ( V_3 , 0 , & V_563 ) )
V_204 -> V_586 . V_535 = 0 ;
else
V_204 -> V_586 . V_535 =
F_16 ( V_563 . V_400 * V_31 ) ;
V_308 |= V_589 | V_590 ;
V_308 &= ~ ( V_521 | V_522 ) ;
V_306 &= ~ ( V_591 | V_592 ) ;
V_204 -> V_586 . V_530 = F_16 ( V_306 ) ;
V_204 -> V_586 . V_529 = F_16 ( V_308 ) ;
V_204 -> V_586 . V_527 =
F_16 ( V_4 -> V_293 . V_310 ) ;
V_204 -> V_586 . V_528 =
F_16 ( V_4 -> V_293 . V_312 ) ;
V_204 -> V_586 . V_524 =
F_16 ( V_4 -> V_293 . V_314 ) ;
V_204 -> V_586 . V_525 =
F_16 ( V_4 -> V_293 . V_316 ) ;
V_204 -> V_586 . V_526 =
F_16 ( V_4 -> V_293 . V_318 ) ;
V_204 -> V_586 . V_531 = F_16 ( V_4 -> V_293 . V_320 ) ;
V_204 -> V_586 . V_532 = F_16 ( V_4 -> V_293 . V_322 ) ;
V_204 -> V_586 . V_538 = 0 ;
V_204 -> V_586 . V_455 = 0 ;
V_204 -> V_586 . V_539 = 0 ;
V_204 -> V_586 . V_540 = 100 ;
V_204 -> V_586 . V_541 = 0 ;
V_204 -> V_586 . V_542 =
F_9 ( ( T_2 ) V_4 -> V_543 ) ;
V_204 -> V_586 . V_544 = false ;
V_204 -> V_586 . V_545 = false ;
V_204 -> V_586 . V_546 = false ;
V_204 -> V_586 . V_547 = false ;
V_204 -> V_586 . V_548 = false ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_593 * V_594 = & V_4 -> V_594 ;
if ( V_594 -> V_595 ) {
if ( V_125 )
return ( F_31 ( V_3 , V_596 ) == V_146 ) ?
0 : - V_43 ;
else
return ( F_31 ( V_3 , V_597 ) == V_146 ) ?
0 : - V_43 ;
}
return 0 ;
}
static int F_150 ( struct V_2 * V_3 ,
T_12 * V_598 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_599 = V_3 -> V_5 . V_6 . V_600 ;
V_598 -> V_584 = 0 ;
V_598 -> V_585 = 0 ;
if ( V_599 == 0 ) {
V_4 -> V_594 . V_595 = false ;
return 0 ;
}
if ( V_4 -> V_381 != V_385 ) {
if ( V_599 > V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ 0 ] . V_379 )
V_598 -> V_601 = 0 ;
else
V_598 -> V_601 =
V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ 0 ] . V_379 - V_599 ;
} else {
if ( V_599 > V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ 0 ] . V_379 )
V_598 -> V_602 = 0 ;
else
V_598 -> V_602 = ( T_1 )
( ( V_3 -> V_5 . V_6 . V_40 . V_45 . V_42 [ 0 ] . V_379 - V_599 ) *
V_603 / V_604 ) ;
}
V_598 -> V_605 = V_4 -> V_536 ? 0 : 1 ;
V_598 -> V_584 = F_16 ( V_598 -> V_584 ) ;
V_598 -> V_585 = F_16 ( V_598 -> V_585 ) ;
V_598 -> V_601 = F_9 ( V_598 -> V_601 ) ;
return 0 ;
}
static int F_151 ( struct V_2 * V_3 ,
T_3 V_606 ,
T_13 * V_172 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_461 V_462 ;
T_3 V_607 = V_4 -> V_293 . V_298 ;
T_3 V_608 = V_4 -> V_293 . V_300 ;
T_3 V_302 = V_4 -> V_293 . V_302 ;
T_3 V_304 = V_4 -> V_293 . V_304 ;
T_3 V_510 = V_3 -> clock . V_335 . V_336 ;
T_3 V_609 ;
T_3 V_610 ;
int V_72 ;
V_72 = F_128 ( V_3 ,
V_572 ,
V_606 , false , & V_462 ) ;
if ( V_72 )
return V_72 ;
V_609 = 1 + V_462 . V_611 ;
V_610 = V_462 . V_612 & 0x3FFFFFF ;
V_607 &= ~ V_613 ;
V_607 |= F_152 ( V_610 ) ;
V_607 |= V_614 ;
if ( V_4 -> V_344 ) {
struct V_507 V_508 ;
T_3 V_615 = V_606 * V_462 . V_503 ;
if ( F_140 ( V_3 , & V_508 ,
V_616 , V_615 ) ) {
T_3 V_617 = V_510 * 5 / ( V_609 * V_508 . V_514 ) ;
T_3 V_618 = 4 * V_508 . V_516 * V_610 / ( V_617 * 10000 ) ;
V_302 &= ~ V_619 ;
V_302 |= F_153 ( V_617 ) ;
V_302 |= V_346 ;
V_304 &= ~ V_620 ;
V_304 |= F_154 ( V_618 ) ;
}
}
V_172 -> V_571 = V_606 ;
V_172 -> V_580 = V_607 ;
V_172 -> V_581 = V_608 ;
V_172 -> V_582 = V_302 ;
V_172 -> V_583 = V_304 ;
V_172 -> V_573 = ( T_1 ) V_462 . V_474 ;
return 0 ;
}
static int F_155 ( struct V_2 * V_3 ,
T_3 V_606 ,
T_2 V_621 ,
T_13 * V_622 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
V_72 = F_151 ( V_3 , V_606 , V_622 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_45 ,
V_606 , & V_622 -> V_470 ) ;
if ( V_72 )
return V_72 ;
V_622 -> V_571 = V_606 ;
V_622 -> V_567 = 0 ;
V_622 -> V_471 = 1 ;
if ( V_4 -> V_536 )
F_110 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_537 ,
V_606 ,
& V_622 -> V_471 ) ;
V_622 -> V_542 = V_621 ;
V_622 -> V_584 = 0 ;
V_622 -> V_585 = 0 ;
V_622 -> V_455 = 1 ;
V_622 -> V_538 = 1 ;
V_622 -> V_539 = 0 ;
V_622 -> V_540 = 0 ;
V_622 -> V_541 = 0 ;
V_622 -> V_623 = 0 ;
if ( V_4 -> V_328 )
V_622 -> V_574 = F_114 ( V_3 ,
V_606 ,
V_422 ) ;
V_622 -> V_549 = V_550 ;
V_622 -> V_567 = F_16 ( V_622 -> V_567 ) ;
V_622 -> V_470 = F_16 ( V_622 -> V_470 * V_31 ) ;
V_622 -> V_471 = F_16 ( V_622 -> V_471 ) ;
V_622 -> V_571 = F_16 ( V_622 -> V_571 ) ;
V_622 -> V_542 = F_9 ( V_622 -> V_542 ) ;
V_622 -> V_580 = F_16 ( V_622 -> V_580 ) ;
V_622 -> V_581 = F_16 ( V_622 -> V_581 ) ;
V_622 -> V_582 = F_16 ( V_622 -> V_582 ) ;
V_622 -> V_583 = F_16 ( V_622 -> V_583 ) ;
V_622 -> V_584 = F_16 ( V_622 -> V_584 ) ;
V_622 -> V_585 = F_16 ( V_622 -> V_585 ) ;
return 0 ;
}
static int F_156 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_449 * V_91 = & V_4 -> V_91 ;
T_3 V_624 = V_4 -> V_210 +
F_12 ( T_4 , V_625 ) ;
T_3 V_626 = sizeof( T_13 ) *
V_627 ;
T_13 * V_628 = V_4 -> V_92 . V_625 ;
T_3 V_39 , V_72 ;
memset ( V_628 , 0 , V_626 ) ;
for ( V_39 = 0 ; V_39 < V_91 -> V_438 . V_44 ; V_39 ++ ) {
V_72 = F_155 ( V_3 ,
V_91 -> V_438 . V_440 [ V_39 ] . V_55 ,
( T_2 ) V_4 -> V_629 [ V_39 ] ,
& V_4 -> V_92 . V_625 [ V_39 ] ) ;
if ( V_72 )
return V_72 ;
if ( V_39 == ( V_91 -> V_438 . V_44 - 1 ) )
V_4 -> V_92 . V_625 [ V_39 ] . V_549 =
V_630 ;
}
V_4 -> V_92 . V_631 = ( T_1 ) V_91 -> V_438 . V_44 ;
V_4 -> V_459 . V_632 =
F_124 ( & V_91 -> V_438 ) ;
V_72 = F_18 ( V_3 , V_624 ,
( T_1 * ) V_628 , V_626 ,
V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static int F_157 ( struct V_2 * V_3 ,
T_12 * V_633 )
{
return F_150 ( V_3 , V_633 ) ;
}
static int F_158 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_449 * V_91 = & V_4 -> V_91 ;
T_3 V_624 = V_4 -> V_210 +
F_12 ( T_4 , V_634 ) ;
T_3 V_626 = sizeof( T_11 ) *
V_635 ;
T_11 * V_628 = V_4 -> V_92 . V_634 ;
T_3 V_39 , V_72 ;
memset ( V_628 , 0 , V_626 ) ;
for ( V_39 = 0 ; V_39 < V_91 -> V_439 . V_44 ; V_39 ++ ) {
if ( V_91 -> V_439 . V_440 [ V_39 ] . V_55 == 0 )
return - V_43 ;
V_72 = F_144 ( V_3 ,
V_91 -> V_439 . V_440 [ V_39 ] . V_55 ,
& V_4 -> V_92 . V_634 [ V_39 ] ) ;
if ( V_72 )
return V_72 ;
}
V_4 -> V_92 . V_634 [ 0 ] . V_542 = F_9 ( 0x1F ) ;
V_4 -> V_92 . V_636 = ( T_1 ) V_91 -> V_439 . V_44 ;
V_4 -> V_459 . V_637 =
F_124 ( & V_91 -> V_439 ) ;
V_4 -> V_92 . V_634 [ V_91 -> V_439 . V_44 - 1 ] . V_549 =
V_630 ;
V_72 = F_18 ( V_3 , V_624 ,
( T_1 * ) V_628 , V_626 ,
V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static void F_159 ( struct V_2 * V_3 ,
struct V_446 * V_91 ,
T_3 V_44 )
{
T_3 V_39 ;
V_91 -> V_44 = V_44 ;
for ( V_39 = 0 ; V_39 < V_638 ; V_39 ++ )
V_91 -> V_440 [ V_39 ] . V_448 = false ;
}
static void F_160 ( struct V_446 * V_91 ,
T_3 V_639 , T_3 V_640 , T_3 V_641 )
{
V_91 -> V_440 [ V_639 ] . V_55 = V_640 ;
V_91 -> V_440 [ V_639 ] . V_454 = V_641 ;
V_91 -> V_440 [ V_639 ] . V_448 = true ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_642 && ! V_4 -> V_643 )
return - V_43 ;
if ( V_4 -> V_642 && ! V_4 -> V_643 ) {
V_4 -> V_644 = V_4 -> V_645 ;
V_4 -> V_646 = V_4 -> V_647 ;
} else if ( ! V_4 -> V_642 && V_4 -> V_643 ) {
V_4 -> V_645 = V_4 -> V_644 ;
V_4 -> V_647 = V_4 -> V_646 ;
}
F_159 ( V_3 ,
& V_4 -> V_91 . V_450 ,
V_648 ) ;
F_160 ( & V_4 -> V_91 . V_450 , 0 ,
V_4 -> V_644 . V_80 ,
V_4 -> V_646 . V_80 ) ;
F_160 ( & V_4 -> V_91 . V_450 , 1 ,
V_4 -> V_645 . V_80 ,
V_4 -> V_647 . V_80 ) ;
F_160 ( & V_4 -> V_91 . V_450 , 2 ,
V_4 -> V_644 . V_80 ,
V_4 -> V_646 . V_81 ) ;
F_160 ( & V_4 -> V_91 . V_450 , 3 ,
V_4 -> V_645 . V_80 ,
V_4 -> V_647 . V_81 ) ;
F_160 ( & V_4 -> V_91 . V_450 , 4 ,
V_4 -> V_644 . V_81 ,
V_4 -> V_646 . V_81 ) ;
F_160 ( & V_4 -> V_91 . V_450 , 5 ,
V_4 -> V_645 . V_81 ,
V_4 -> V_647 . V_81 ) ;
V_4 -> V_91 . V_450 . V_44 = 6 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_373 * V_649 =
& V_3 -> V_5 . V_6 . V_40 . V_45 ;
struct V_373 * V_650 =
& V_3 -> V_5 . V_6 . V_40 . V_193 ;
struct V_651 * V_652 =
& V_3 -> V_5 . V_6 . V_40 . V_41 ;
T_3 V_39 ;
if ( V_649 == NULL )
return - V_43 ;
if ( V_649 -> V_44 < 1 )
return - V_43 ;
if ( V_650 == NULL )
return - V_43 ;
if ( V_650 -> V_44 < 1 )
return - V_43 ;
memset ( & V_4 -> V_91 , 0 , sizeof( struct V_449 ) ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_438 ,
V_627 ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_439 ,
V_635 ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_653 ,
V_386 ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_654 ,
V_390 ) ;
F_159 ( V_3 ,
& V_4 -> V_91 . V_655 ,
V_395 ) ;
V_4 -> V_91 . V_438 . V_44 = 0 ;
for ( V_39 = 0 ; V_39 < V_649 -> V_44 ; V_39 ++ ) {
if ( ( V_39 == 0 ) ||
( V_4 -> V_91 . V_438 . V_440 [ V_4 -> V_91 . V_438 . V_44 - 1 ] . V_55 !=
V_649 -> V_42 [ V_39 ] . V_410 ) ) {
V_4 -> V_91 . V_438 . V_440 [ V_4 -> V_91 . V_438 . V_44 ] . V_55 =
V_649 -> V_42 [ V_39 ] . V_410 ;
V_4 -> V_91 . V_438 . V_440 [ V_4 -> V_91 . V_438 . V_44 ] . V_448 = true ;
V_4 -> V_91 . V_438 . V_44 ++ ;
}
}
V_4 -> V_91 . V_439 . V_44 = 0 ;
for ( V_39 = 0 ; V_39 < V_650 -> V_44 ; V_39 ++ ) {
if ( ( V_39 == 0 ) ||
( V_4 -> V_91 . V_439 . V_440 [ V_4 -> V_91 . V_439 . V_44 - 1 ] . V_55 !=
V_650 -> V_42 [ V_39 ] . V_410 ) ) {
V_4 -> V_91 . V_439 . V_440 [ V_4 -> V_91 . V_439 . V_44 ] . V_55 =
V_650 -> V_42 [ V_39 ] . V_410 ;
V_4 -> V_91 . V_439 . V_440 [ V_4 -> V_91 . V_439 . V_44 ] . V_448 = true ;
V_4 -> V_91 . V_439 . V_44 ++ ;
}
}
for ( V_39 = 0 ; V_39 < V_649 -> V_44 ; V_39 ++ ) {
V_4 -> V_91 . V_653 . V_440 [ V_39 ] . V_55 =
V_649 -> V_42 [ V_39 ] . V_379 ;
V_4 -> V_91 . V_653 . V_440 [ V_39 ] . V_454 =
V_652 -> V_42 [ V_39 ] . V_51 ;
V_4 -> V_91 . V_653 . V_440 [ V_39 ] . V_448 = true ;
}
V_4 -> V_91 . V_653 . V_44 = V_649 -> V_44 ;
V_650 = & V_3 -> V_5 . V_6 . V_40 . V_192 ;
if ( V_650 ) {
for ( V_39 = 0 ; V_39 < V_650 -> V_44 ; V_39 ++ ) {
V_4 -> V_91 . V_654 . V_440 [ V_39 ] . V_55 =
V_650 -> V_42 [ V_39 ] . V_379 ;
V_4 -> V_91 . V_654 . V_440 [ V_39 ] . V_448 = true ;
}
V_4 -> V_91 . V_654 . V_44 = V_650 -> V_44 ;
}
V_650 = & V_3 -> V_5 . V_6 . V_40 . V_394 ;
if ( V_650 ) {
for ( V_39 = 0 ; V_39 < V_650 -> V_44 ; V_39 ++ ) {
V_4 -> V_91 . V_655 . V_440 [ V_39 ] . V_55 =
V_650 -> V_42 [ V_39 ] . V_379 ;
V_4 -> V_91 . V_655 . V_440 [ V_39 ] . V_448 = true ;
}
V_4 -> V_91 . V_655 . V_44 = V_650 -> V_44 ;
}
F_161 ( V_3 ) ;
return 0 ;
}
static int F_163 ( struct V_446 * V_204 ,
T_3 V_55 , T_3 * V_656 )
{
T_3 V_39 ;
int V_72 = - V_43 ;
for( V_39 = 0 ; V_39 < V_204 -> V_44 ; V_39 ++ ) {
if ( V_55 == V_204 -> V_440 [ V_39 ] . V_55 ) {
* V_656 = V_39 ;
V_72 = 0 ;
}
}
return V_72 ;
}
static int F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_593 * V_594 = & V_4 -> V_594 ;
struct V_9 * V_441 = V_3 -> V_5 . V_6 . V_657 ;
T_4 * V_204 = & V_4 -> V_92 ;
int V_72 ;
V_72 = F_162 ( V_3 ) ;
if ( V_72 )
return V_72 ;
if ( V_4 -> V_381 != V_409 )
F_108 ( V_3 , V_204 ) ;
F_48 ( V_3 ) ;
if ( V_3 -> V_5 . V_6 . V_46 & V_658 )
V_204 -> V_659 |= V_660 ;
if ( V_3 -> V_5 . V_6 . V_46 & V_661 )
V_204 -> V_659 |= V_662 ;
if ( V_4 -> V_168 )
V_204 -> V_659 |= V_663 ;
if ( V_594 -> V_595 ) {
V_72 = F_157 ( V_3 , & V_4 -> V_92 . V_664 ) ;
if ( V_72 )
return V_72 ;
F_25 ( V_665 , V_594 -> V_666 ) ;
}
V_72 = F_156 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_158 ( V_3 ) ;
if ( V_72 )
return V_72 ;
F_125 ( V_3 , V_204 ) ;
V_72 = F_147 ( V_3 , V_204 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_129 ( V_3 , V_204 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_130 ( V_3 , V_204 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_131 ( V_3 , V_204 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_121 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_127 ( V_3 , V_204 ) ;
if ( V_72 )
return V_72 ;
V_204 -> V_667 = 0 ;
V_204 -> V_668 = 0 ;
V_204 -> V_669 = 0 ;
V_204 -> V_670 = 0 ;
V_204 -> V_444 = 0 ;
V_204 -> V_445 = 0 ;
V_72 = F_163 ( & V_4 -> V_91 . V_438 ,
V_4 -> V_671 . V_672 ,
( T_3 * ) & V_4 -> V_92 . V_444 ) ;
V_72 = F_163 ( & V_4 -> V_91 . V_439 ,
V_4 -> V_671 . V_673 ,
( T_3 * ) & V_4 -> V_92 . V_445 ) ;
V_204 -> V_674 = V_4 -> V_671 . V_675 ;
V_204 -> V_676 = V_4 -> V_671 . V_677 ;
V_204 -> V_678 = V_4 -> V_671 . V_679 ;
F_123 ( V_3 , V_441 ) ;
V_72 = F_15 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_204 -> V_680 = 1 ;
V_204 -> V_681 = 1 ;
V_204 -> V_682 = 1 ;
V_204 -> V_683 = 1 ;
V_204 -> V_684 = 1 ;
V_204 -> V_685 = 1 ;
V_204 -> V_686 = 1 ;
V_204 -> V_687 = 1 ;
V_204 -> V_688 = 1 ;
V_204 -> V_689 = ( T_2 ) ( ( V_4 -> V_106 . V_107 *
V_690 ) / 1000 ) ;
V_204 -> V_691 = ( T_2 ) ( ( V_4 -> V_106 . V_692 *
V_690 ) / 1000 ) ;
V_204 -> V_693 = 1 ;
V_204 -> V_694 = 1 ;
V_204 -> V_695 = 0 ;
V_204 -> V_696 = 4000 ;
V_204 -> V_697 = 0 ;
V_204 -> V_698 = 1 ;
V_204 -> V_699 = 0 ;
V_204 -> V_700 = 1 ;
if ( V_4 -> V_381 == V_385 )
V_204 -> V_701 = 1 ;
else
V_204 -> V_701 = 0 ;
V_204 -> V_702 = 17 ;
V_204 -> V_703 = 0x4000 ;
V_204 -> V_659 = F_16 ( V_204 -> V_659 ) ;
V_204 -> V_704 = F_16 ( V_204 -> V_704 ) ;
V_204 -> V_705 = F_16 ( V_204 -> V_705 ) ;
V_204 -> V_706 = F_16 ( V_204 -> V_706 ) ;
V_204 -> V_707 = F_16 ( V_204 -> V_707 ) ;
V_204 -> V_703 = F_16 ( V_204 -> V_703 ) ;
V_204 -> V_689 = F_9 ( V_204 -> V_689 ) ;
V_204 -> V_691 = F_9 ( V_204 -> V_691 ) ;
V_204 -> V_696 = F_9 ( V_204 -> V_696 ) ;
V_204 -> V_695 = F_9 ( V_204 -> V_695 ) ;
V_204 -> V_697 = F_9 ( V_204 -> V_697 ) ;
V_204 -> V_674 = F_9 ( V_204 -> V_674 * V_31 ) ;
V_204 -> V_676 = F_9 ( V_204 -> V_676 * V_31 ) ;
V_204 -> V_678 = F_9 ( V_204 -> V_678 * V_31 ) ;
V_72 = F_18 ( V_3 ,
V_4 -> V_210 +
F_12 ( T_4 , V_659 ) ,
( T_1 * ) & V_204 -> V_659 ,
sizeof( T_4 ) - 3 * sizeof( V_708 ) ,
V_4 -> V_78 ) ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static void F_165 ( struct V_2 * V_3 ,
struct V_446 * V_91 ,
T_3 V_709 , T_3 V_710 )
{
T_3 V_39 ;
for ( V_39 = 0 ; V_39 < V_91 -> V_44 ; V_39 ++ ) {
if ( ( V_91 -> V_440 [ V_39 ] . V_55 < V_709 ) ||
( V_91 -> V_440 [ V_39 ] . V_55 > V_710 ) )
V_91 -> V_440 [ V_39 ] . V_448 = false ;
else
V_91 -> V_440 [ V_39 ] . V_448 = true ;
}
}
static void F_166 ( struct V_2 * V_3 ,
T_3 V_711 , T_3 V_712 ,
T_3 V_713 , T_3 V_714 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_446 * V_715 = & V_4 -> V_91 . V_450 ;
T_3 V_39 , V_96 ;
for ( V_39 = 0 ; V_39 < V_715 -> V_44 ; V_39 ++ ) {
if ( ( V_715 -> V_440 [ V_39 ] . V_55 < V_711 ) ||
( V_715 -> V_440 [ V_39 ] . V_454 < V_712 ) ||
( V_715 -> V_440 [ V_39 ] . V_55 > V_713 ) ||
( V_715 -> V_440 [ V_39 ] . V_454 > V_714 ) )
V_715 -> V_440 [ V_39 ] . V_448 = false ;
else
V_715 -> V_440 [ V_39 ] . V_448 = true ;
}
for ( V_39 = 0 ; V_39 < V_715 -> V_44 ; V_39 ++ ) {
if ( V_715 -> V_440 [ V_39 ] . V_448 ) {
for ( V_96 = V_39 + 1 ; V_96 < V_715 -> V_44 ; V_96 ++ ) {
if ( V_715 -> V_440 [ V_96 ] . V_448 ) {
if ( ( V_715 -> V_440 [ V_39 ] . V_55 == V_715 -> V_440 [ V_96 ] . V_55 ) &&
( V_715 -> V_440 [ V_39 ] . V_454 == V_715 -> V_440 [ V_96 ] . V_454 ) )
V_715 -> V_440 [ V_96 ] . V_448 = false ;
}
}
}
}
}
static int F_167 ( struct V_2 * V_3 ,
struct V_9 * V_716 )
{
struct V_8 * V_598 = F_2 ( V_716 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_717 ;
if ( V_598 -> V_190 < 1 )
return - V_43 ;
if ( V_598 -> V_190 == 1 )
V_717 = 0 ;
else
V_717 = 1 ;
F_165 ( V_3 ,
& V_4 -> V_91 . V_438 ,
V_598 -> V_191 [ 0 ] . V_172 ,
V_598 -> V_191 [ V_717 ] . V_172 ) ;
F_165 ( V_3 ,
& V_4 -> V_91 . V_439 ,
V_598 -> V_191 [ 0 ] . V_173 ,
V_598 -> V_191 [ V_717 ] . V_173 ) ;
F_166 ( V_3 ,
V_598 -> V_191 [ 0 ] . V_640 ,
V_598 -> V_191 [ 0 ] . V_718 ,
V_598 -> V_191 [ V_717 ] . V_640 ,
V_598 -> V_191 [ V_717 ] . V_718 ) ;
return 0 ;
}
static int F_168 ( struct V_2 * V_3 )
{
struct V_373 * V_719 =
& V_3 -> V_5 . V_6 . V_40 . V_720 ;
struct V_373 * V_653 =
& V_3 -> V_5 . V_6 . V_40 . V_45 ;
T_3 V_721 = 0 ;
T_3 V_39 ;
if ( V_719 == NULL )
return - V_43 ;
if ( ! V_719 -> V_44 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_719 -> V_44 ; V_39 ++ ) {
if ( V_3 -> clock . V_722 == V_719 -> V_42 [ V_39 ] . V_410 )
V_721 = V_719 -> V_42 [ V_39 ] . V_379 ;
}
for ( V_39 = 0 ; V_39 < V_653 -> V_44 ; V_39 ++ ) {
if ( V_721 <= V_653 -> V_42 [ V_39 ] . V_379 ) {
V_721 = V_653 -> V_42 [ V_39 ] . V_379 ;
return ( F_64 ( V_3 ,
V_723 ,
V_721 * V_31 ) == V_146 ) ?
0 : - V_43 ;
}
}
return - V_43 ;
}
static int F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_724 ;
if ( ! V_4 -> V_238 ) {
if ( V_4 -> V_459 . V_632 ) {
V_724 = F_64 ( V_3 ,
V_725 ,
V_4 -> V_459 . V_632 ) ;
if ( V_724 != V_146 )
return - V_43 ;
}
}
if ( ! V_4 -> V_242 ) {
if ( V_4 -> V_459 . V_637 ) {
V_724 = F_64 ( V_3 ,
V_726 ,
V_4 -> V_459 . V_637 ) ;
if ( V_724 != V_146 )
return - V_43 ;
}
}
if ( ! V_4 -> V_262 ) {
if ( V_4 -> V_459 . V_460 ) {
V_724 = F_64 ( V_3 ,
V_727 ,
V_4 -> V_459 . V_460 ) ;
if ( V_724 != V_146 )
return - V_43 ;
}
}
F_168 ( V_3 ) ;
return 0 ;
}
static void F_170 ( struct V_2 * V_3 ,
struct V_9 * V_716 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_598 = F_2 ( V_716 ) ;
struct V_446 * V_438 = & V_4 -> V_91 . V_438 ;
T_3 V_172 = V_598 -> V_191 [ V_598 -> V_190 - 1 ] . V_172 ;
struct V_446 * V_439 = & V_4 -> V_91 . V_439 ;
T_3 V_173 = V_598 -> V_191 [ V_598 -> V_190 - 1 ] . V_173 ;
T_3 V_39 ;
V_4 -> V_237 = 0 ;
for ( V_39 = 0 ; V_39 < V_438 -> V_44 ; V_39 ++ ) {
if ( V_172 == V_438 -> V_440 [ V_39 ] . V_55 )
break;
}
if ( V_39 >= V_438 -> V_44 ) {
V_4 -> V_237 |= V_239 ;
} else {
if ( 0 != V_422 )
V_4 -> V_237 |= V_240 ;
}
for ( V_39 = 0 ; V_39 < V_439 -> V_44 ; V_39 ++ ) {
if ( V_173 == V_439 -> V_440 [ V_39 ] . V_55 )
break;
}
if ( V_39 >= V_439 -> V_44 )
V_4 -> V_237 |= V_243 ;
if ( V_3 -> V_5 . V_6 . V_728 !=
V_3 -> V_5 . V_6 . V_182 )
V_4 -> V_237 |= V_729 ;
}
static int F_171 ( struct V_2 * V_3 ,
struct V_9 * V_716 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_598 = F_2 ( V_716 ) ;
T_3 V_172 = V_598 -> V_191 [ V_598 -> V_190 - 1 ] . V_172 ;
T_3 V_173 = V_598 -> V_191 [ V_598 -> V_190 - 1 ] . V_173 ;
struct V_449 * V_91 = & V_4 -> V_91 ;
int V_72 ;
if ( ! V_4 -> V_237 )
return 0 ;
if ( V_4 -> V_237 & V_239 )
V_91 -> V_438 . V_440 [ V_91 -> V_438 . V_44 - 1 ] . V_55 = V_172 ;
if ( V_4 -> V_237 & V_243 )
V_91 -> V_439 . V_440 [ V_91 -> V_439 . V_44 - 1 ] . V_55 = V_173 ;
if ( V_4 -> V_237 & ( V_239 | V_240 ) ) {
V_72 = F_156 ( V_3 ) ;
if ( V_72 )
return V_72 ;
}
if ( V_4 -> V_237 & ( V_243 | V_729 ) ) {
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
if ( V_3 -> V_5 . V_6 . V_187 )
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_188 ;
else
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_189 ;
if ( V_125 ) {
V_4 -> V_459 . V_730 = 0 ;
for ( V_39 = V_3 -> V_5 . V_6 . V_40 . V_464 . V_44 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_3 -> V_5 . V_6 . V_40 . V_464 . V_42 [ V_39 ] . V_379 <= V_170 -> V_30 ) {
V_4 -> V_459 . V_730 |= 1 << V_39 ;
if ( ! V_4 -> V_731 )
break;
}
}
F_64 ( V_3 ,
V_732 ,
V_4 -> V_459 . V_730 ) ;
if ( V_4 -> V_733 & 0x1 ) {
V_4 -> V_552 = true ;
V_4 -> V_459 . V_637 &= 0xFFFFFFFE ;
F_64 ( V_3 ,
V_726 ,
V_4 -> V_459 . V_637 ) ;
}
} else {
if ( V_4 -> V_733 & 0x1 ) {
V_4 -> V_552 = false ;
V_4 -> V_459 . V_637 |= 1 ;
F_64 ( V_3 ,
V_726 ,
V_4 -> V_459 . V_637 ) ;
}
}
return ( F_31 ( V_3 , V_125 ?
V_734 : V_735 ) == V_146 ) ?
0 : - V_43 ;
}
static int F_173 ( struct V_2 * V_3 , bool V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_169 * V_170 ;
int V_39 ;
if ( V_3 -> V_5 . V_6 . V_187 )
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_188 ;
else
V_170 = & V_3 -> V_5 . V_6 . V_40 . V_189 ;
if ( V_125 ) {
V_4 -> V_459 . V_736 = 0 ;
for ( V_39 = V_3 -> V_5 . V_6 . V_40 . V_477 . V_44 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_3 -> V_5 . V_6 . V_40 . V_477 . V_42 [ V_39 ] . V_379 <= V_170 -> V_30 ) {
V_4 -> V_459 . V_736 |= 1 << V_39 ;
if ( ! V_4 -> V_737 )
break;
}
}
F_64 ( V_3 ,
V_738 ,
V_4 -> V_459 . V_736 ) ;
}
return ( F_31 ( V_3 , V_125 ?
V_739 : V_740 ) == V_146 ) ?
0 : - V_43 ;
}
static int F_37 ( struct V_2 * V_3 , bool V_164 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_198 ;
if ( ! V_164 ) {
if ( V_4 -> V_731 ||
( V_3 -> V_5 . V_6 . V_40 . V_464 . V_44 <= 0 ) )
V_4 -> V_92 . V_667 = 0 ;
else
V_4 -> V_92 . V_667 =
V_3 -> V_5 . V_6 . V_40 . V_464 . V_44 - 1 ;
V_198 = F_23 ( V_741 ) ;
V_198 &= ~ V_742 ;
V_198 |= V_667 ( V_4 -> V_92 . V_667 ) ;
F_25 ( V_741 , V_198 ) ;
}
return F_172 ( V_3 , ! V_164 ) ;
}
static T_1 F_174 ( struct V_2 * V_3 )
{
T_1 V_39 ;
T_3 V_743 = 30000 ;
struct V_744 * V_204 =
& V_3 -> V_5 . V_6 . V_40 . V_477 ;
for ( V_39 = 0 ; V_39 < V_204 -> V_44 ; V_39 ++ ) {
if ( V_204 -> V_42 [ V_39 ] . V_178 >= V_743 )
return V_39 ;
}
return V_204 -> V_44 - 1 ;
}
static int F_175 ( struct V_2 * V_3 ,
struct V_9 * V_745 ,
struct V_9 * V_746 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 = 0 ;
T_3 V_198 ;
if ( V_746 -> V_178 != V_745 -> V_178 ) {
if ( V_745 -> V_178 ) {
F_176 ( V_3 , V_747 , false ) ;
V_4 -> V_92 . V_668 = F_174 ( V_3 ) ;
V_198 = F_23 ( V_741 ) ;
V_198 &= ~ V_748 ;
V_198 |= V_668 ( V_4 -> V_92 . V_668 ) ;
F_25 ( V_741 , V_198 ) ;
V_72 = F_173 ( V_3 , true ) ;
} else {
F_176 ( V_3 , V_747 , true ) ;
V_72 = F_173 ( V_3 , false ) ;
}
}
return V_72 ;
}
static int F_177 ( struct V_2 * V_3 ,
struct V_9 * V_716 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
V_72 = F_167 ( V_3 , V_716 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_459 . V_632 =
F_124 ( & V_4 -> V_91 . V_438 ) ;
V_4 -> V_459 . V_637 =
F_124 ( & V_4 -> V_91 . V_439 ) ;
V_4 -> V_733 =
V_4 -> V_459 . V_637 ;
if ( V_4 -> V_552 ) {
if ( V_4 -> V_459 . V_637 & 1 )
V_4 -> V_459 . V_637 &= 0xFFFFFFFE ;
}
V_4 -> V_459 . V_460 =
F_124 ( & V_4 -> V_91 . V_450 ) ;
return 0 ;
}
static T_3 F_178 ( struct V_2 * V_3 ,
T_3 V_749 )
{
T_3 V_443 = 0 ;
while ( ( V_749 & ( 1 << V_443 ) ) == 0 )
V_443 ++ ;
return V_443 ;
}
int F_179 ( struct V_2 * V_3 ,
enum V_750 V_443 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_143 ;
T_3 V_198 , V_628 , V_39 ;
int V_72 ;
if ( V_443 == V_751 ) {
if ( ( ! V_4 -> V_238 ) &&
V_4 -> V_459 . V_632 ) {
V_628 = 0 ;
V_198 = V_4 -> V_459 . V_632 ;
while ( V_198 >>= 1 )
V_628 ++ ;
if ( V_628 ) {
V_72 = F_66 ( V_3 , V_628 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_282 ; V_39 ++ ) {
V_198 = ( F_23 ( V_752 ) &
V_753 ) >> V_754 ;
if ( V_198 == V_628 )
break;
F_59 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_242 ) &&
V_4 -> V_459 . V_637 ) {
V_628 = 0 ;
V_198 = V_4 -> V_459 . V_637 ;
while ( V_198 >>= 1 )
V_628 ++ ;
if ( V_628 ) {
V_72 = F_67 ( V_3 , V_628 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_282 ; V_39 ++ ) {
V_198 = ( F_23 ( V_752 ) &
V_755 ) >> V_756 ;
if ( V_198 == V_628 )
break;
F_59 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_262 ) &&
V_4 -> V_459 . V_460 ) {
V_628 = 0 ;
V_198 = V_4 -> V_459 . V_460 ;
while ( V_198 >>= 1 )
V_628 ++ ;
if ( V_628 ) {
V_72 = F_68 ( V_3 , V_443 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_282 ; V_39 ++ ) {
V_198 = ( F_23 ( V_757 ) &
V_758 ) >> V_759 ;
if ( V_198 == V_628 )
break;
F_59 ( 1 ) ;
}
}
}
} else if ( V_443 == V_760 ) {
if ( ( ! V_4 -> V_238 ) &&
V_4 -> V_459 . V_632 ) {
V_628 = F_178 ( V_3 ,
V_4 -> V_459 . V_632 ) ;
V_72 = F_66 ( V_3 , V_628 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_282 ; V_39 ++ ) {
V_198 = ( F_23 ( V_752 ) &
V_753 ) >> V_754 ;
if ( V_198 == V_628 )
break;
F_59 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_242 ) &&
V_4 -> V_459 . V_637 ) {
V_628 = F_178 ( V_3 ,
V_4 -> V_459 . V_637 ) ;
V_72 = F_67 ( V_3 , V_628 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_282 ; V_39 ++ ) {
V_198 = ( F_23 ( V_752 ) &
V_755 ) >> V_756 ;
if ( V_198 == V_628 )
break;
F_59 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_262 ) &&
V_4 -> V_459 . V_460 ) {
V_628 = F_178 ( V_3 ,
V_4 -> V_459 . V_460 ) ;
V_72 = F_68 ( V_3 , V_628 ) ;
if ( V_72 )
return V_72 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_282 ; V_39 ++ ) {
V_198 = ( F_23 ( V_757 ) &
V_758 ) >> V_759 ;
if ( V_198 == V_628 )
break;
F_59 ( 1 ) ;
}
}
} else if ( V_443 == V_761 ) {
if ( ! V_4 -> V_238 ) {
V_143 = F_31 ( V_3 , V_762 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ! V_4 -> V_242 ) {
V_143 = F_31 ( V_3 , V_763 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
if ( ! V_4 -> V_262 ) {
V_143 = F_31 ( V_3 , V_764 ) ;
if ( V_143 != V_146 )
return - V_43 ;
}
}
V_3 -> V_5 . V_6 . V_765 = V_443 ;
return 0 ;
}
static int F_180 ( struct V_2 * V_3 ,
struct V_766 * V_204 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_39 , V_96 , V_97 ;
T_3 V_767 ;
for ( V_39 = 0 , V_96 = V_204 -> V_768 ; V_39 < V_204 -> V_768 ; V_39 ++ ) {
if ( V_96 >= V_769 )
return - V_43 ;
switch( V_204 -> V_770 [ V_39 ] . V_771 << 2 ) {
case V_772 :
V_767 = F_24 ( V_773 ) ;
V_204 -> V_770 [ V_96 ] . V_771 = V_773 >> 2 ;
V_204 -> V_770 [ V_96 ] . V_774 = V_775 >> 2 ;
for ( V_97 = 0 ; V_97 < V_204 -> V_776 ; V_97 ++ ) {
V_204 -> V_777 [ V_97 ] . V_778 [ V_96 ] =
( ( V_767 & 0xffff0000 ) ) | ( ( V_204 -> V_777 [ V_97 ] . V_778 [ V_39 ] & 0xffff0000 ) >> 16 ) ;
}
V_96 ++ ;
if ( V_96 >= V_769 )
return - V_43 ;
V_767 = F_24 ( V_779 ) ;
V_204 -> V_770 [ V_96 ] . V_771 = V_779 >> 2 ;
V_204 -> V_770 [ V_96 ] . V_774 = V_780 >> 2 ;
for ( V_97 = 0 ; V_97 < V_204 -> V_776 ; V_97 ++ ) {
V_204 -> V_777 [ V_97 ] . V_778 [ V_96 ] =
( V_767 & 0xffff0000 ) | ( V_204 -> V_777 [ V_97 ] . V_778 [ V_39 ] & 0x0000ffff ) ;
if ( ! V_4 -> V_168 )
V_204 -> V_777 [ V_97 ] . V_778 [ V_96 ] |= 0x100 ;
}
V_96 ++ ;
if ( V_96 > V_769 )
return - V_43 ;
if ( ! V_4 -> V_168 ) {
V_204 -> V_770 [ V_96 ] . V_771 = V_781 >> 2 ;
V_204 -> V_770 [ V_96 ] . V_774 = V_781 >> 2 ;
for ( V_97 = 0 ; V_97 < V_204 -> V_776 ; V_97 ++ ) {
V_204 -> V_777 [ V_97 ] . V_778 [ V_96 ] =
( V_204 -> V_777 [ V_97 ] . V_778 [ V_39 ] & 0xffff0000 ) >> 16 ;
}
V_96 ++ ;
if ( V_96 > V_769 )
return - V_43 ;
}
break;
case V_782 :
V_767 = F_24 ( V_783 ) ;
V_204 -> V_770 [ V_96 ] . V_771 = V_783 >> 2 ;
V_204 -> V_770 [ V_96 ] . V_774 = V_784 >> 2 ;
for ( V_97 = 0 ; V_97 < V_204 -> V_776 ; V_97 ++ ) {
V_204 -> V_777 [ V_97 ] . V_778 [ V_96 ] =
( V_767 & 0xffff0000 ) | ( V_204 -> V_777 [ V_97 ] . V_778 [ V_39 ] & 0x0000ffff ) ;
}
V_96 ++ ;
if ( V_96 > V_769 )
return - V_43 ;
break;
default:
break;
}
}
V_204 -> V_768 = V_96 ;
return 0 ;
}
static bool F_181 ( T_2 V_785 , T_2 * V_786 )
{
bool V_724 = true ;
switch( V_785 ) {
case V_787 >> 2 :
* V_786 = V_788 >> 2 ;
break;
case V_789 >> 2 :
* V_786 = V_790 >> 2 ;
break;
case V_791 >> 2 :
* V_786 = V_792 >> 2 ;
break;
case V_793 >> 2 :
* V_786 = V_794 >> 2 ;
break;
case V_795 >> 2 :
* V_786 = V_796 >> 2 ;
break;
case V_797 >> 2 :
* V_786 = V_798 >> 2 ;
break;
case V_799 >> 2 :
* V_786 = V_800 >> 2 ;
break;
case V_801 >> 2 :
* V_786 = V_802 >> 2 ;
break;
case V_803 >> 2 :
* V_786 = V_804 >> 2 ;
break;
case V_805 >> 2 :
* V_786 = V_806 >> 2 ;
break;
case V_807 >> 2 :
* V_786 = V_808 >> 2 ;
break;
case V_809 >> 2 :
* V_786 = V_810 >> 2 ;
break;
case V_811 >> 2 :
* V_786 = V_812 >> 2 ;
break;
case V_813 >> 2 :
* V_786 = V_814 >> 2 ;
break;
case V_773 >> 2 :
* V_786 = V_775 >> 2 ;
break;
case V_779 >> 2 :
* V_786 = V_780 >> 2 ;
break;
case V_783 >> 2 :
* V_786 = V_784 >> 2 ;
break;
case V_815 >> 2 :
* V_786 = V_816 >> 2 ;
break;
case V_817 >> 2 :
* V_786 = V_818 >> 2 ;
break;
case V_819 >> 2 :
* V_786 = V_820 >> 2 ;
break;
default:
V_724 = false ;
break;
}
return V_724 ;
}
static void F_182 ( struct V_766 * V_204 )
{
T_1 V_39 , V_96 ;
for ( V_39 = 0 ; V_39 < V_204 -> V_768 ; V_39 ++ ) {
for ( V_96 = 1 ; V_96 < V_204 -> V_776 ; V_96 ++ ) {
if ( V_204 -> V_777 [ V_96 - 1 ] . V_778 [ V_39 ] !=
V_204 -> V_777 [ V_96 ] . V_778 [ V_39 ] ) {
V_204 -> V_821 |= 1 << V_39 ;
break;
}
}
}
}
static void F_183 ( struct V_766 * V_204 )
{
T_3 V_39 ;
T_2 V_822 ;
for ( V_39 = 0 ; V_39 < V_204 -> V_768 ; V_39 ++ ) {
V_204 -> V_770 [ V_39 ] . V_774 =
F_181 ( V_204 -> V_770 [ V_39 ] . V_771 , & V_822 ) ?
V_822 : V_204 -> V_770 [ V_39 ] . V_771 ;
}
}
static int F_184 ( const struct V_823 * V_204 ,
struct V_766 * V_824 )
{
T_1 V_39 , V_96 ;
if ( V_204 -> V_768 > V_769 )
return - V_43 ;
if ( V_204 -> V_776 > V_825 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_204 -> V_768 ; V_39 ++ )
V_824 -> V_770 [ V_39 ] . V_771 = V_204 -> V_770 [ V_39 ] . V_771 ;
V_824 -> V_768 = V_204 -> V_768 ;
for ( V_39 = 0 ; V_39 < V_204 -> V_776 ; V_39 ++ ) {
V_824 -> V_777 [ V_39 ] . V_826 =
V_204 -> V_777 [ V_39 ] . V_826 ;
for ( V_96 = 0 ; V_96 < V_204 -> V_768 ; V_96 ++ )
V_824 -> V_777 [ V_39 ] . V_778 [ V_96 ] =
V_204 -> V_777 [ V_39 ] . V_778 [ V_96 ] ;
}
V_824 -> V_776 = V_204 -> V_776 ;
return 0 ;
}
static int F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_823 * V_204 ;
struct V_766 * V_824 = & V_4 -> V_827 ;
T_1 V_828 = F_186 ( V_3 ) ;
int V_72 ;
V_204 = F_187 ( sizeof( struct V_823 ) , V_829 ) ;
if ( ! V_204 )
return - V_830 ;
F_26 ( V_788 , F_24 ( V_787 ) ) ;
F_26 ( V_798 , F_24 ( V_797 ) ) ;
F_26 ( V_790 , F_24 ( V_789 ) ) ;
F_26 ( V_792 , F_24 ( V_791 ) ) ;
F_26 ( V_794 , F_24 ( V_793 ) ) ;
F_26 ( V_796 , F_24 ( V_795 ) ) ;
F_26 ( V_804 , F_24 ( V_803 ) ) ;
F_26 ( V_806 , F_24 ( V_805 ) ) ;
F_26 ( V_800 , F_24 ( V_799 ) ) ;
F_26 ( V_802 , F_24 ( V_801 ) ) ;
F_26 ( V_775 , F_24 ( V_773 ) ) ;
F_26 ( V_780 , F_24 ( V_779 ) ) ;
F_26 ( V_784 , F_24 ( V_783 ) ) ;
F_26 ( V_812 , F_24 ( V_811 ) ) ;
F_26 ( V_814 , F_24 ( V_813 ) ) ;
F_26 ( V_808 , F_24 ( V_807 ) ) ;
F_26 ( V_810 , F_24 ( V_809 ) ) ;
F_26 ( V_816 , F_24 ( V_815 ) ) ;
F_26 ( V_818 , F_24 ( V_817 ) ) ;
F_26 ( V_820 , F_24 ( V_819 ) ) ;
V_72 = F_188 ( V_3 , V_828 , V_204 ) ;
if ( V_72 )
goto V_831;
V_72 = F_184 ( V_204 , V_824 ) ;
if ( V_72 )
goto V_831;
F_183 ( V_824 ) ;
V_72 = F_180 ( V_3 , V_824 ) ;
if ( V_72 )
goto V_831;
F_182 ( V_824 ) ;
V_831:
F_189 ( V_204 ) ;
return V_72 ;
}
static int F_190 ( struct V_2 * V_3 ,
T_14 * V_827 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 , V_96 ;
for ( V_39 = 0 , V_96 = 0 ; V_96 < V_4 -> V_827 . V_768 ; V_96 ++ ) {
if ( V_4 -> V_827 . V_821 & ( 1 << V_96 ) ) {
if ( V_39 >= V_769 )
return - V_43 ;
V_827 -> V_822 [ V_39 ] . V_774 = F_9 ( V_4 -> V_827 . V_770 [ V_96 ] . V_774 ) ;
V_827 -> V_822 [ V_39 ] . V_771 = F_9 ( V_4 -> V_827 . V_770 [ V_96 ] . V_771 ) ;
V_39 ++ ;
}
}
V_827 -> V_768 = ( T_1 ) V_39 ;
return 0 ;
}
static void F_191 ( const struct V_832 * V_833 ,
T_15 * V_126 ,
T_3 V_776 , T_3 V_821 )
{
T_3 V_39 , V_96 ;
for ( V_39 = 0 , V_96 = 0 ; V_96 < V_776 ; V_96 ++ ) {
if ( V_821 & ( 1 << V_96 ) ) {
V_126 -> V_55 [ V_39 ] = F_16 ( V_833 -> V_778 [ V_96 ] ) ;
V_39 ++ ;
}
}
}
static void F_192 ( struct V_2 * V_3 ,
const T_3 V_489 ,
T_15 * V_834 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 = 0 ;
for( V_39 = 0 ; V_39 < V_4 -> V_827 . V_776 ; V_39 ++ ) {
if ( V_489 <= V_4 -> V_827 . V_777 [ V_39 ] . V_826 )
break;
}
if ( ( V_39 == V_4 -> V_827 . V_776 ) && ( V_39 > 0 ) )
-- V_39 ;
F_191 ( & V_4 -> V_827 . V_777 [ V_39 ] ,
V_834 , V_4 -> V_827 . V_768 ,
V_4 -> V_827 . V_821 ) ;
}
static void F_193 ( struct V_2 * V_3 ,
T_14 * V_827 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 ;
for ( V_39 = 0 ; V_39 < V_4 -> V_91 . V_439 . V_44 ; V_39 ++ )
F_192 ( V_3 ,
V_4 -> V_91 . V_439 . V_440 [ V_39 ] . V_55 ,
& V_827 -> V_126 [ V_39 ] ) ;
}
static int F_194 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_72 ;
memset ( & V_4 -> V_835 , 0 , sizeof( T_14 ) ) ;
V_72 = F_190 ( V_3 , & V_4 -> V_835 ) ;
if ( V_72 )
return V_72 ;
F_193 ( V_3 , & V_4 -> V_835 ) ;
return F_18 ( V_3 ,
V_4 -> V_288 ,
( T_1 * ) & V_4 -> V_835 ,
sizeof( T_14 ) ,
V_4 -> V_78 ) ;
}
static int F_195 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! ( V_4 -> V_237 & V_243 ) )
return 0 ;
memset ( & V_4 -> V_835 , 0 , sizeof( T_14 ) ) ;
F_193 ( V_3 , & V_4 -> V_835 ) ;
return F_18 ( V_3 ,
V_4 -> V_288 +
F_12 ( T_14 , V_126 [ 0 ] ) ,
( T_1 * ) & V_4 -> V_835 . V_126 [ 0 ] ,
sizeof( T_15 ) *
V_4 -> V_91 . V_439 . V_44 ,
V_4 -> V_78 ) ;
}
static void F_196 ( struct V_2 * V_3 )
{
T_3 V_198 = F_23 ( V_229 ) ;
V_198 |= V_836 ;
F_25 ( V_229 , V_198 ) ;
}
static enum V_837 F_197 ( struct V_2 * V_3 ,
struct V_9 * V_716 )
{
struct V_8 * V_598 = F_2 ( V_716 ) ;
int V_39 ;
T_2 V_838 , V_839 = 0 ;
for ( V_39 = 0 ; V_39 < V_598 -> V_190 ; V_39 ++ ) {
V_838 = V_598 -> V_191 [ V_39 ] . V_640 ;
if ( V_839 < V_838 )
V_839 = V_838 ;
}
return V_839 ;
}
static T_2 F_198 ( struct V_2 * V_3 )
{
T_3 V_840 = 0 ;
V_840 = F_199 ( V_841 ) & V_842 ;
V_840 >>= V_843 ;
return ( T_2 ) V_840 ;
}
static int F_200 ( struct V_2 * V_3 )
{
T_3 V_844 = 0 ;
V_844 = F_199 ( V_845 ) & V_846 ;
V_844 >>= V_847 ;
switch ( V_844 ) {
case V_848 :
return 1 ;
case V_849 :
return 2 ;
case V_850 :
return 4 ;
case V_851 :
return 8 ;
case V_852 :
return 12 ;
case V_853 :
case V_854 :
default:
return 16 ;
}
}
static void F_201 ( struct V_2 * V_3 ,
struct V_9 * V_745 ,
struct V_9 * V_746 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_837 V_855 =
F_197 ( V_3 , V_745 ) ;
enum V_837 V_856 ;
if ( V_4 -> V_857 == V_858 )
V_856 = F_197 ( V_3 , V_746 ) ;
else
V_856 = V_4 -> V_857 ;
V_4 -> V_857 = V_858 ;
V_4 -> V_859 = false ;
if ( V_855 > V_856 ) {
switch ( V_855 ) {
#ifdef F_202
case V_860 :
if ( F_203 ( V_3 , V_861 , false ) == 0 )
break;
V_4 -> V_857 = V_862 ;
if ( V_856 == V_862 )
break;
case V_862 :
if ( F_203 ( V_3 , V_863 , false ) == 0 )
break;
#endif
default:
V_4 -> V_857 = F_198 ( V_3 ) ;
break;
}
} else {
if ( V_855 < V_856 )
V_4 -> V_859 = true ;
}
}
static void F_204 ( struct V_2 * V_3 ,
struct V_9 * V_745 ,
struct V_9 * V_746 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_837 V_855 =
F_197 ( V_3 , V_745 ) ;
T_1 V_864 ;
if ( V_4 -> V_859 ) {
if ( V_855 == V_860 )
V_864 = V_861 ;
else if ( V_855 == V_862 )
V_864 = V_863 ;
else
V_864 = V_865 ;
if ( ( V_864 == V_865 ) &&
( F_198 ( V_3 ) > 0 ) )
return;
#ifdef F_202
F_203 ( V_3 , V_864 , false ) ;
#endif
}
}
static int F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_373 * V_649 =
& V_3 -> V_5 . V_6 . V_40 . V_45 ;
struct V_373 * V_866 =
& V_3 -> V_5 . V_6 . V_40 . V_193 ;
struct V_373 * V_867 =
& V_3 -> V_5 . V_6 . V_40 . V_192 ;
if ( V_649 == NULL )
return - V_43 ;
if ( V_649 -> V_44 < 1 )
return - V_43 ;
if ( V_866 == NULL )
return - V_43 ;
if ( V_866 -> V_44 < 1 )
return - V_43 ;
if ( V_867 == NULL )
return - V_43 ;
if ( V_867 -> V_44 < 1 )
return - V_43 ;
V_4 -> V_570 = V_649 -> V_42 [ 0 ] . V_379 ;
V_4 -> V_868 =
V_649 -> V_42 [ V_649 -> V_44 - 1 ] . V_379 ;
V_4 -> V_588 = V_867 -> V_42 [ 0 ] . V_379 ;
V_4 -> V_869 =
V_867 -> V_42 [ V_867 -> V_44 - 1 ] . V_379 ;
V_3 -> V_5 . V_6 . V_40 . V_188 . V_172 =
V_649 -> V_42 [ V_649 -> V_44 - 1 ] . V_410 ;
V_3 -> V_5 . V_6 . V_40 . V_188 . V_173 =
V_866 -> V_42 [ V_649 -> V_44 - 1 ] . V_410 ;
V_3 -> V_5 . V_6 . V_40 . V_188 . V_30 =
V_649 -> V_42 [ V_649 -> V_44 - 1 ] . V_379 ;
V_3 -> V_5 . V_6 . V_40 . V_188 . V_214 =
V_867 -> V_42 [ V_867 -> V_44 - 1 ] . V_379 ;
return 0 ;
}
static void F_206 ( struct V_2 * V_3 , T_2 * V_30 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_870 * V_871 = & V_4 -> V_215 ;
T_3 V_872 ;
for ( V_872 = 0 ; V_872 < V_871 -> V_44 ; V_872 ++ ) {
if ( V_871 -> V_212 [ V_872 ] == * V_30 ) {
* V_30 = V_871 -> V_219 [ V_872 ] ;
break;
}
}
}
static void F_207 ( struct V_2 * V_3 , T_2 * V_214 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_870 * V_871 = & V_4 -> V_216 ;
T_3 V_872 ;
for ( V_872 = 0 ; V_872 < V_871 -> V_44 ; V_872 ++ ) {
if ( V_871 -> V_212 [ V_872 ] == * V_214 ) {
* V_214 = V_871 -> V_219 [ V_872 ] ;
break;
}
}
}
static void F_208 ( struct V_2 * V_3 ,
struct V_373 * V_204 )
{
T_3 V_39 ;
if ( V_204 ) {
for ( V_39 = 0 ; V_39 < V_204 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_204 -> V_42 [ V_39 ] . V_379 ) ;
}
}
static void F_209 ( struct V_2 * V_3 ,
struct V_373 * V_204 )
{
T_3 V_39 ;
if ( V_204 ) {
for ( V_39 = 0 ; V_39 < V_204 -> V_44 ; V_39 ++ )
F_207 ( V_3 , & V_204 -> V_42 [ V_39 ] . V_379 ) ;
}
}
static void F_210 ( struct V_2 * V_3 ,
struct V_744 * V_204 )
{
T_3 V_39 ;
if ( V_204 ) {
for ( V_39 = 0 ; V_39 < V_204 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_204 -> V_42 [ V_39 ] . V_379 ) ;
}
}
static void F_211 ( struct V_2 * V_3 ,
struct V_873 * V_204 )
{
T_3 V_39 ;
if ( V_204 ) {
for ( V_39 = 0 ; V_39 < V_204 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_204 -> V_42 [ V_39 ] . V_379 ) ;
}
}
static void F_212 ( struct V_2 * V_3 ,
struct V_416 * V_204 )
{
T_3 V_39 ;
if ( V_204 ) {
for ( V_39 = 0 ; V_39 < V_204 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_204 -> V_42 [ V_39 ] . V_408 ) ;
}
}
static void F_213 ( struct V_2 * V_3 ,
struct V_169 * V_204 )
{
if ( V_204 ) {
F_206 ( V_3 , ( T_2 * ) & V_204 -> V_30 ) ;
F_207 ( V_3 , ( T_2 * ) & V_204 -> V_214 ) ;
}
}
static void F_214 ( struct V_2 * V_3 ,
struct V_651 * V_204 )
{
T_3 V_39 ;
if ( V_204 ) {
for ( V_39 = 0 ; V_39 < V_204 -> V_44 ; V_39 ++ )
F_206 ( V_3 , & V_204 -> V_42 [ V_39 ] . V_30 ) ;
}
}
static void F_215 ( struct V_2 * V_3 )
{
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_45 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_193 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_720 ) ;
F_209 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_192 ) ;
F_210 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_477 ) ;
F_211 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_464 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_487 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_484 ) ;
F_212 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_537 ) ;
F_213 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_188 ) ;
F_213 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_189 ) ;
F_214 ( V_3 ,
& V_3 -> V_5 . V_6 . V_40 . V_41 ) ;
}
static void F_216 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_198 ;
V_198 = F_24 ( V_874 ) ;
if ( ( ( V_198 & V_875 ) >> V_876 ) ==
V_877 )
V_4 -> V_168 = true ;
else
V_4 -> V_168 = false ;
}
static void F_217 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_878 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_879 = * V_10 ;
V_4 -> V_880 = * V_878 ;
V_4 -> V_879 . V_12 = & V_4 -> V_880 ;
}
static void F_218 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_878 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_881 = * V_10 ;
V_4 -> V_882 = * V_878 ;
V_4 -> V_881 . V_12 = & V_4 -> V_882 ;
}
int F_219 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 V_882 = * V_3 -> V_5 . V_6 . V_882 ;
struct V_9 * V_878 = & V_882 ;
F_218 ( V_3 , V_878 ) ;
F_40 ( V_3 , & V_4 -> V_881 ) ;
return 0 ;
}
void F_220 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_878 = & V_4 -> V_881 ;
F_217 ( V_3 , V_878 ) ;
}
void F_221 ( struct V_2 * V_3 )
{
int V_883 ;
V_883 = F_222 ( V_3 ) ;
if ( V_883 )
F_43 ( L_2 ) ;
F_80 ( V_3 ) ;
F_216 ( V_3 ) ;
F_83 ( V_3 ) ;
F_81 ( V_3 ) ;
}
int F_223 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_657 = V_3 -> V_5 . V_6 . V_657 ;
int V_72 ;
if ( F_224 ( V_3 ) )
return - V_43 ;
if ( V_4 -> V_381 != V_409 ) {
F_196 ( V_3 ) ;
V_72 = F_100 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_3 ) ;
return V_72 ;
}
}
if ( V_4 -> V_884 ) {
V_72 = F_185 ( V_3 ) ;
if ( V_72 )
V_4 -> V_884 = false ;
}
if ( V_4 -> V_885 )
F_89 ( V_3 , true ) ;
if ( V_4 -> V_230 )
F_82 ( V_3 , true ) ;
F_90 ( V_3 ) ;
F_93 ( V_3 ) ;
F_95 ( V_3 ) ;
V_72 = F_97 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_4 ) ;
return V_72 ;
}
V_72 = F_79 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_5 ) ;
return V_72 ;
}
V_72 = F_115 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_6 ) ;
return V_72 ;
}
V_72 = F_164 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_7 ) ;
return V_72 ;
}
V_72 = F_112 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_8 ) ;
return V_72 ;
}
if ( V_4 -> V_884 ) {
V_72 = F_194 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_9 ) ;
return V_72 ;
}
}
V_72 = F_17 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_10 ) ;
return V_72 ;
}
F_72 ( V_3 ) ;
F_55 ( V_3 ) ;
V_72 = F_84 ( V_3 , false ) ;
if ( V_72 ) {
F_43 ( L_11 ) ;
return V_72 ;
}
F_63 ( V_3 , true ) ;
V_72 = F_149 ( V_3 , true ) ;
if ( V_72 ) {
F_43 ( L_12 ) ;
return V_72 ;
}
V_72 = F_85 ( V_3 , true ) ;
if ( V_72 ) {
F_43 ( L_13 ) ;
return V_72 ;
}
V_72 = F_60 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_14 ) ;
return V_72 ;
}
V_72 = F_27 ( V_3 , true ) ;
if ( V_72 ) {
F_43 ( L_15 ) ;
return V_72 ;
}
V_72 = F_33 ( V_3 , true ) ;
if ( V_72 ) {
F_43 ( L_16 ) ;
return V_72 ;
}
V_72 = F_30 ( V_3 , true ) ;
if ( V_72 ) {
F_43 ( L_17 ) ;
return V_72 ;
}
F_54 ( V_3 , V_224 , true ) ;
F_217 ( V_3 , V_657 ) ;
return 0 ;
}
int F_225 ( struct V_2 * V_3 )
{
int V_72 ;
if ( V_3 -> V_886 . V_887 &&
F_226 ( V_3 -> V_5 . V_888 ) ) {
#if 0
PPSMC_Result result;
#endif
V_72 = F_42 ( V_3 , V_889 , V_890 ) ;
if ( V_72 ) {
F_43 ( L_18 ) ;
return V_72 ;
}
V_3 -> V_886 . V_891 = true ;
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
struct V_9 * V_657 = V_3 -> V_5 . V_6 . V_657 ;
F_36 ( V_3 , false ) ;
if ( ! F_224 ( V_3 ) )
return;
if ( V_4 -> V_230 )
F_82 ( V_3 , false ) ;
F_30 ( V_3 , false ) ;
F_33 ( V_3 , false ) ;
F_27 ( V_3 , false ) ;
F_89 ( V_3 , false ) ;
F_54 ( V_3 , V_224 , false ) ;
F_62 ( V_3 ) ;
F_85 ( V_3 , true ) ;
F_149 ( V_3 , false ) ;
F_96 ( V_3 ) ;
F_117 ( V_3 ) ;
F_76 ( V_3 ) ;
F_118 ( V_3 ) ;
F_217 ( V_3 , V_657 ) ;
}
int F_229 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_878 = & V_4 -> V_881 ;
struct V_9 * V_892 = & V_4 -> V_879 ;
int V_72 ;
F_170 ( V_3 , V_878 ) ;
if ( V_4 -> V_893 )
F_201 ( V_3 , V_878 , V_892 ) ;
V_72 = F_61 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_19 ) ;
return V_72 ;
}
V_72 = F_171 ( V_3 , V_878 ) ;
if ( V_72 ) {
F_43 ( L_20 ) ;
return V_72 ;
}
V_72 = F_177 ( V_3 , V_878 ) ;
if ( V_72 ) {
F_43 ( L_21 ) ;
return V_72 ;
}
V_72 = F_175 ( V_3 , V_878 , V_892 ) ;
if ( V_72 ) {
F_43 ( L_22 ) ;
return V_72 ;
}
V_72 = F_49 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_23 ) ;
return V_72 ;
}
if ( V_4 -> V_884 ) {
V_72 = F_195 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_24 ) ;
return V_72 ;
}
}
V_72 = F_122 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_25 ) ;
return V_72 ;
}
V_72 = F_56 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_26 ) ;
return V_72 ;
}
V_72 = F_169 ( V_3 ) ;
if ( V_72 ) {
F_43 ( L_27 ) ;
return V_72 ;
}
if ( V_4 -> V_893 )
F_204 ( V_3 , V_878 , V_892 ) ;
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
struct V_894 * V_895 ,
T_1 V_896 )
{
V_10 -> V_897 = F_234 ( V_895 -> V_898 ) ;
V_10 -> V_183 = F_235 ( V_895 -> V_899 ) ;
V_10 -> V_900 = F_235 ( V_895 -> V_901 ) ;
if ( V_902 < V_896 ) {
V_10 -> V_467 = F_234 ( V_895 -> V_903 ) ;
V_10 -> V_469 = F_234 ( V_895 -> V_904 ) ;
} else {
V_10 -> V_467 = 0 ;
V_10 -> V_469 = 0 ;
}
if ( V_10 -> V_183 & V_905 )
V_3 -> V_5 . V_6 . V_657 = V_10 ;
if ( V_10 -> V_183 & V_906 )
V_3 -> V_5 . V_6 . V_907 = V_10 ;
}
static void F_236 ( struct V_2 * V_3 ,
struct V_9 * V_10 , int V_639 ,
union V_908 * V_909 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_910 * V_911 = & V_11 -> V_191 [ V_639 ] ;
V_11 -> V_190 = V_639 + 1 ;
V_911 -> V_172 = F_235 ( V_909 -> V_912 . V_913 ) ;
V_911 -> V_172 |= V_909 -> V_912 . V_914 << 16 ;
V_911 -> V_173 = F_235 ( V_909 -> V_912 . V_915 ) ;
V_911 -> V_173 |= V_909 -> V_912 . V_916 << 16 ;
V_911 -> V_640 = F_237 ( V_3 ,
V_4 -> V_917 ,
V_4 -> V_671 . V_918 ,
V_909 -> V_912 . V_919 ) ;
V_911 -> V_718 = F_238 ( V_3 ,
V_4 -> V_671 . V_920 ,
F_235 ( V_909 -> V_912 . V_921 ) ) ;
if ( V_10 -> V_183 & V_922 ) {
V_4 -> V_923 = V_911 -> V_640 ;
}
if ( V_10 -> V_900 & V_924 ) {
V_4 -> V_594 . V_595 = true ;
V_4 -> V_594 . V_911 = * V_911 ;
V_4 -> V_594 . V_666 = V_925 ;
}
if ( V_10 -> V_183 & V_905 ) {
V_911 -> V_173 = V_4 -> V_671 . V_673 ;
V_911 -> V_172 = V_4 -> V_671 . V_672 ;
V_911 -> V_640 = V_4 -> V_671 . V_918 ;
V_911 -> V_718 = V_4 -> V_671 . V_920 ;
}
switch ( V_10 -> V_183 & V_184 ) {
case V_185 :
V_4 -> V_643 = true ;
if ( V_4 -> V_644 . V_81 < V_911 -> V_640 )
V_4 -> V_644 . V_81 = V_911 -> V_640 ;
if ( V_4 -> V_644 . V_80 > V_911 -> V_640 )
V_4 -> V_644 . V_80 = V_911 -> V_640 ;
if ( V_4 -> V_646 . V_81 < V_911 -> V_718 )
V_4 -> V_646 . V_81 = V_911 -> V_718 ;
if ( V_4 -> V_646 . V_80 > V_911 -> V_718 )
V_4 -> V_646 . V_80 = V_911 -> V_718 ;
break;
case V_926 :
V_4 -> V_642 = true ;
if ( V_4 -> V_645 . V_81 < V_911 -> V_640 )
V_4 -> V_645 . V_81 = V_911 -> V_640 ;
if ( V_4 -> V_645 . V_80 > V_911 -> V_640 )
V_4 -> V_645 . V_80 = V_911 -> V_640 ;
if ( V_4 -> V_647 . V_81 < V_911 -> V_718 )
V_4 -> V_647 . V_81 = V_911 -> V_718 ;
if ( V_4 -> V_647 . V_80 > V_911 -> V_718 )
V_4 -> V_647 . V_80 = V_911 -> V_718 ;
break;
default:
break;
}
}
static int F_239 ( struct V_2 * V_3 )
{
struct V_927 * V_928 = & V_3 -> V_928 ;
struct V_894 * V_895 ;
union V_929 * V_930 ;
int V_39 , V_96 , V_97 , V_931 , V_932 ;
union V_908 * V_909 ;
struct V_933 * V_934 ;
struct V_935 * V_936 ;
struct V_937 * V_938 ;
union V_939 * V_939 ;
int V_639 = F_240 ( V_940 , V_941 ) ;
T_2 V_942 ;
T_1 V_943 , V_944 ;
T_1 * V_945 ;
struct V_8 * V_11 ;
if ( ! F_241 ( V_928 -> V_946 , V_639 , NULL ,
& V_943 , & V_944 , & V_942 ) )
return - V_43 ;
V_939 = (union V_939 * ) ( V_928 -> V_946 -> V_947 + V_942 ) ;
V_934 = (struct V_933 * )
( V_928 -> V_946 -> V_947 + V_942 +
F_235 ( V_939 -> V_948 . V_949 ) ) ;
V_936 = (struct V_935 * )
( V_928 -> V_946 -> V_947 + V_942 +
F_235 ( V_939 -> V_948 . V_950 ) ) ;
V_938 = (struct V_937 * )
( V_928 -> V_946 -> V_947 + V_942 +
F_235 ( V_939 -> V_948 . V_951 ) ) ;
V_3 -> V_5 . V_6 . V_11 = F_187 ( sizeof( struct V_9 ) *
V_934 -> V_952 , V_829 ) ;
if ( ! V_3 -> V_5 . V_6 . V_11 )
return - V_830 ;
V_945 = ( T_1 * ) V_934 -> V_953 ;
for ( V_39 = 0 ; V_39 < V_934 -> V_952 ; V_39 ++ ) {
T_1 * V_414 ;
V_930 = (union V_929 * ) V_945 ;
V_931 = V_930 -> V_954 . V_955 ;
V_895 = (struct V_894 * )
& V_938 -> V_956 [ V_931 ] ;
if ( ! V_3 -> V_5 . V_930 [ V_39 ] . V_909 )
return - V_43 ;
V_11 = F_187 ( sizeof( struct V_8 ) , V_829 ) ;
if ( V_11 == NULL ) {
F_189 ( V_3 -> V_5 . V_6 . V_11 ) ;
return - V_830 ;
}
V_3 -> V_5 . V_6 . V_11 [ V_39 ] . V_12 = V_11 ;
F_233 ( V_3 , & V_3 -> V_5 . V_6 . V_11 [ V_39 ] ,
V_895 ,
V_938 -> V_957 ) ;
V_97 = 0 ;
V_414 = ( T_1 * ) & V_930 -> V_954 . V_958 [ 0 ] ;
for ( V_96 = 0 ; V_96 < V_930 -> V_954 . V_959 ; V_96 ++ ) {
V_932 = V_414 [ V_96 ] ;
if ( V_932 >= V_936 -> V_952 )
continue;
if ( V_97 >= V_960 )
break;
V_909 = (union V_908 * )
( ( T_1 * ) & V_936 -> V_961 [ 0 ] +
( V_932 * V_936 -> V_957 ) ) ;
F_236 ( V_3 ,
& V_3 -> V_5 . V_6 . V_11 [ V_39 ] , V_97 ,
V_909 ) ;
V_97 ++ ;
}
V_945 += 2 + V_930 -> V_954 . V_959 ;
}
V_3 -> V_5 . V_6 . V_962 = V_934 -> V_952 ;
for ( V_39 = 0 ; V_39 < V_963 ; V_39 ++ ) {
T_3 V_172 , V_173 ;
V_932 = V_3 -> V_5 . V_6 . V_179 [ V_39 ] . V_964 ;
V_909 = (union V_908 * )
& V_936 -> V_961 [ V_932 * V_936 -> V_957 ] ;
V_172 = F_235 ( V_909 -> V_912 . V_913 ) ;
V_172 |= V_909 -> V_912 . V_914 << 16 ;
V_173 = F_235 ( V_909 -> V_912 . V_915 ) ;
V_173 |= V_909 -> V_912 . V_916 << 16 ;
V_3 -> V_5 . V_6 . V_179 [ V_39 ] . V_172 = V_172 ;
V_3 -> V_5 . V_6 . V_179 [ V_39 ] . V_173 = V_173 ;
}
return 0 ;
}
static int F_242 ( struct V_2 * V_3 ,
struct V_965 * V_442 )
{
struct V_927 * V_928 = & V_3 -> V_928 ;
int V_639 = F_240 ( V_940 , V_966 ) ;
T_16 * V_967 ;
T_1 V_943 , V_944 ;
T_2 V_942 ;
if ( F_241 ( V_928 -> V_946 , V_639 , NULL ,
& V_943 , & V_944 , & V_942 ) ) {
V_967 =
( T_16 * ) ( V_928 -> V_946 -> V_947 +
V_942 ) ;
V_442 -> V_679 = F_235 ( V_967 -> V_968 ) ;
V_442 -> V_675 = F_235 ( V_967 -> V_969 ) ;
V_442 -> V_677 = F_235 ( V_967 -> V_970 ) ;
V_442 -> V_918 = F_198 ( V_3 ) ;
V_442 -> V_920 = F_200 ( V_3 ) ;
V_442 -> V_672 = F_234 ( V_967 -> V_971 ) ;
V_442 -> V_673 = F_234 ( V_967 -> V_972 ) ;
return 0 ;
}
return - V_43 ;
}
void F_243 ( struct V_2 * V_3 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 . V_6 . V_962 ; V_39 ++ ) {
F_189 ( V_3 -> V_5 . V_6 . V_11 [ V_39 ] . V_12 ) ;
}
F_189 ( V_3 -> V_5 . V_6 . V_11 ) ;
F_189 ( V_3 -> V_5 . V_6 . V_7 ) ;
F_189 ( V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 ) ;
F_244 ( V_3 ) ;
}
int F_245 ( struct V_2 * V_3 )
{
int V_639 = F_240 ( V_940 , V_973 ) ;
T_2 V_942 , V_974 ;
T_1 V_943 , V_944 ;
struct V_1 * V_4 ;
int V_72 ;
T_3 V_139 ;
V_4 = F_187 ( sizeof( struct V_1 ) , V_829 ) ;
if ( V_4 == NULL )
return - V_830 ;
V_3 -> V_5 . V_6 . V_7 = V_4 ;
V_72 = F_246 ( V_3 -> V_975 , & V_139 ) ;
if ( V_72 )
V_4 -> V_917 = 0 ;
else
V_4 -> V_917 = V_139 ;
V_4 -> V_857 = V_858 ;
V_4 -> V_645 . V_81 = V_976 ;
V_4 -> V_645 . V_80 = V_860 ;
V_4 -> V_644 . V_81 = V_976 ;
V_4 -> V_644 . V_80 = V_860 ;
V_4 -> V_647 . V_81 = 0 ;
V_4 -> V_647 . V_80 = 16 ;
V_4 -> V_646 . V_81 = 0 ;
V_4 -> V_646 . V_80 = 16 ;
V_72 = F_242 ( V_3 , & V_4 -> V_671 ) ;
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
V_4 -> V_562 = false ;
V_4 -> V_78 = V_977 ;
V_4 -> V_629 [ 0 ] = V_978 ;
V_4 -> V_629 [ 1 ] = V_978 ;
V_4 -> V_629 [ 2 ] = V_978 ;
V_4 -> V_629 [ 3 ] = V_978 ;
V_4 -> V_629 [ 4 ] = V_978 ;
V_4 -> V_629 [ 5 ] = V_978 ;
V_4 -> V_629 [ 6 ] = V_978 ;
V_4 -> V_629 [ 7 ] = V_978 ;
V_4 -> V_543 = V_979 ;
V_4 -> V_238 = 0 ;
V_4 -> V_242 = 0 ;
V_4 -> V_262 = 0 ;
if ( ( V_3 -> V_13 -> V_14 == 0x6658 ) &&
( V_3 -> V_980 -> V_974 == ( V_981 * 4 ) ) ) {
V_4 -> V_242 = 1 ;
}
V_4 -> V_328 = true ;
V_4 -> V_555 = 40000 ;
V_4 -> V_551 = 40000 ;
V_4 -> V_557 = 40000 ;
V_4 -> V_558 = 40000 ;
F_3 ( V_3 ) ;
V_4 -> V_205 = false ;
V_4 -> V_209 = false ;
V_4 -> V_731 = true ;
V_4 -> V_737 = true ;
F_50 ( V_3 ) ;
F_215 ( V_3 ) ;
F_205 ( V_3 ) ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 =
F_187 ( 4 * sizeof( struct V_982 ) , V_829 ) ;
if ( ! V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 ) {
F_243 ( V_3 ) ;
return - V_830 ;
}
V_3 -> V_5 . V_6 . V_40 . V_720 . V_44 = 4 ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 [ 0 ] . V_410 = 0 ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 [ 0 ] . V_379 = 0 ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 [ 1 ] . V_410 = 36000 ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 [ 1 ] . V_379 = 720 ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 [ 2 ] . V_410 = 54000 ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 [ 2 ] . V_379 = 810 ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 [ 3 ] . V_410 = 72000 ;
V_3 -> V_5 . V_6 . V_40 . V_720 . V_42 [ 3 ] . V_379 = 900 ;
V_3 -> V_5 . V_6 . V_40 . V_983 = 4 ;
V_3 -> V_5 . V_6 . V_40 . V_984 = 15000 ;
V_3 -> V_5 . V_6 . V_40 . V_985 = 200 ;
V_3 -> V_5 . V_6 . V_40 . V_986 . V_44 = 0 ;
V_3 -> V_5 . V_6 . V_40 . V_986 . V_987 = NULL ;
V_3 -> V_5 . V_6 . V_40 . V_988 . V_44 = 0 ;
V_3 -> V_5 . V_6 . V_40 . V_988 . V_987 = NULL ;
if ( V_3 -> V_989 == V_990 ) {
V_4 -> V_106 . V_692 = 94500 ;
V_4 -> V_106 . V_107 = 95000 ;
V_4 -> V_106 . V_991 = 104000 ;
} else {
V_4 -> V_106 . V_692 = 99500 ;
V_4 -> V_106 . V_107 = 100000 ;
V_4 -> V_106 . V_991 = 104000 ;
}
V_4 -> V_552 = false ;
V_4 -> V_381 = V_409 ;
V_4 -> V_387 = V_409 ;
V_4 -> V_391 = V_409 ;
if ( F_249 ( V_3 , V_383 , V_384 ) )
V_4 -> V_381 = V_382 ;
else if ( F_249 ( V_3 , V_383 , V_992 ) )
V_4 -> V_381 = V_385 ;
if ( V_3 -> V_5 . V_6 . V_46 & V_993 ) {
if ( F_249 ( V_3 , V_388 , V_384 ) )
V_4 -> V_387 = V_382 ;
else if ( F_249 ( V_3 , V_388 , V_992 ) )
V_4 -> V_387 = V_385 ;
else
V_3 -> V_5 . V_6 . V_46 &= ~ V_993 ;
}
if ( V_3 -> V_5 . V_6 . V_46 & V_994 ) {
if ( F_249 ( V_3 , V_392 , V_384 ) )
V_4 -> V_391 = V_382 ;
else if ( F_249 ( V_3 , V_392 , V_992 ) )
V_4 -> V_391 = V_385 ;
else
V_3 -> V_5 . V_6 . V_46 &= ~ V_994 ;
}
V_4 -> V_536 = true ;
#if F_250 ( F_202 )
V_4 -> V_893 =
F_251 ( V_3 ) ;
#else
V_4 -> V_893 = false ;
#endif
if ( F_241 ( V_3 -> V_928 . V_946 , V_639 , & V_974 ,
& V_943 , & V_944 , & V_942 ) ) {
V_4 -> V_344 = true ;
V_4 -> V_506 = true ;
V_4 -> V_885 = true ;
} else {
V_4 -> V_344 = false ;
V_4 -> V_506 = false ;
V_4 -> V_885 = true ;
}
if ( V_3 -> V_5 . V_888 != V_995 )
V_4 -> V_230 = true ;
else
V_4 -> V_230 = false ;
V_4 -> V_884 = true ;
V_4 -> V_165 = false ;
if ( ( V_3 -> V_5 . V_6 . V_40 . V_189 . V_172 == 0 ) ||
( V_3 -> V_5 . V_6 . V_40 . V_189 . V_173 == 0 ) )
V_3 -> V_5 . V_6 . V_40 . V_189 =
V_3 -> V_5 . V_6 . V_40 . V_188 ;
return 0 ;
}
void F_252 ( struct V_2 * V_3 ,
struct V_996 * V_997 )
{
T_3 V_172 = F_70 ( V_3 ) ;
T_3 V_173 = F_71 ( V_3 ) ;
F_253 ( V_997 , L_28 ,
V_172 , V_173 ) ;
}
void F_254 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_910 * V_911 ;
int V_39 ;
F_255 ( V_10 -> V_183 , V_10 -> V_900 ) ;
F_256 ( V_10 -> V_897 ) ;
F_257 ( L_29 , V_10 -> V_467 , V_10 -> V_469 ) ;
for ( V_39 = 0 ; V_39 < V_11 -> V_190 ; V_39 ++ ) {
V_911 = & V_11 -> V_191 [ V_39 ] ;
F_257 ( L_30 ,
V_39 , V_911 -> V_172 , V_911 -> V_173 , V_911 -> V_640 + 1 , V_911 -> V_718 ) ;
}
F_258 ( V_3 , V_10 ) ;
}
T_3 F_259 ( struct V_2 * V_3 , bool V_998 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_999 = F_2 ( & V_4 -> V_881 ) ;
if ( V_998 )
return V_999 -> V_191 [ 0 ] . V_172 ;
else
return V_999 -> V_191 [ V_999 -> V_190 - 1 ] . V_172 ;
}
T_3 F_260 ( struct V_2 * V_3 , bool V_998 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_999 = F_2 ( & V_4 -> V_881 ) ;
if ( V_998 )
return V_999 -> V_191 [ 0 ] . V_173 ;
else
return V_999 -> V_191 [ V_999 -> V_190 - 1 ] . V_173 ;
}
