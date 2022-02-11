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
if ( V_3 -> V_27 == V_28 )
V_4 -> V_29 = false ;
else
V_4 -> V_29 = true ;
V_4 -> V_30 = true ;
V_4 -> V_31 = true ;
}
}
static T_1 F_4 ( T_2 V_32 )
{
return ( 6200 - ( V_32 * V_33 ) ) / 25 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 * V_34 = V_4 -> V_35 . V_36 ;
T_1 * V_37 = V_4 -> V_35 . V_38 ;
T_1 * V_39 = V_4 -> V_35 . V_40 ;
T_3 V_41 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 == NULL )
return - V_45 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 > 8 )
return - V_45 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 !=
V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 ; V_41 ++ ) {
if ( V_3 -> V_5 . V_6 . V_48 & V_49 ) {
V_37 [ V_41 ] = F_4 ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_41 ] . V_50 ) ;
V_34 [ V_41 ] = F_4 ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_41 ] . V_51 ) ;
V_39 [ V_41 ] = F_4 ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_41 ] . V_52 ) ;
} else {
V_37 [ V_41 ] = F_4 ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_41 ] . V_32 ) ;
V_34 [ V_41 ] = F_4 ( ( T_2 ) V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_41 ] . V_53 ) ;
}
}
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 * V_54 = V_4 -> V_35 . V_55 ;
T_3 V_41 ;
if ( V_4 -> V_56 . V_46 > 8 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_56 . V_46 ; V_41 ++ )
V_54 [ V_41 ] = F_4 ( V_4 -> V_56 . V_44 [ V_41 ] . V_57 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_58 * V_59 = V_4 -> V_15 ;
V_4 -> V_35 . V_60 = V_59 -> V_61 ;
V_4 -> V_35 . V_62 = V_59 -> V_63 ;
V_4 -> V_35 . V_64 = 3 ;
V_4 -> V_35 . V_65 = 0 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_58 * V_59 = V_4 -> V_15 ;
T_2 V_66 ;
V_66 = V_3 -> V_5 . V_6 . V_42 . V_67 -> V_68 * 256 ;
V_4 -> V_35 . V_69 = F_9 ( V_66 ) ;
V_4 -> V_35 . V_70 =
V_59 -> V_71 ;
V_4 -> V_35 . V_72 = V_59 -> V_73 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_58 * V_59 = V_4 -> V_15 ;
int V_74 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_77 ) +
F_12 ( V_78 , V_79 ) ,
( T_3 * ) & V_4 -> V_35 . V_79 ,
V_4 -> V_80 ) ;
if ( V_74 )
return - V_45 ;
else
V_4 -> V_35 . V_79 = V_59 -> V_81 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ( V_3 -> V_5 . V_6 . V_82 . V_83 & ( 1 << 15 ) ) ||
( V_3 -> V_5 . V_6 . V_82 . V_83 == 0 ) )
V_3 -> V_5 . V_6 . V_82 . V_83 =
V_3 -> V_5 . V_6 . V_82 . V_84 ;
V_4 -> V_35 . V_85 =
F_9 ( V_3 -> V_5 . V_6 . V_82 . V_83 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 * V_34 = V_4 -> V_35 . V_36 ;
T_1 * V_37 = V_4 -> V_35 . V_38 ;
int V_41 , V_86 , V_87 ;
V_86 = V_87 = V_34 [ 0 ] ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
if ( 0 != V_34 [ V_41 ] ) {
if ( V_86 > V_34 [ V_41 ] )
V_86 = V_34 [ V_41 ] ;
if ( V_87 < V_34 [ V_41 ] )
V_87 = V_34 [ V_41 ] ;
}
if ( 0 != V_37 [ V_41 ] ) {
if ( V_86 > V_37 [ V_41 ] )
V_86 = V_37 [ V_41 ] ;
if ( V_87 < V_37 [ V_41 ] )
V_87 = V_37 [ V_41 ] ;
}
}
if ( ( V_86 == 0 ) || ( V_87 == 0 ) )
return - V_45 ;
V_4 -> V_35 . V_88 = ( T_1 ) V_87 ;
V_4 -> V_35 . V_89 = ( T_1 ) V_86 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_90 = V_4 -> V_35 . V_91 ;
T_2 V_92 = V_4 -> V_35 . V_93 ;
struct V_94 * V_67 =
V_3 -> V_5 . V_6 . V_42 . V_67 ;
V_90 = V_67 -> V_95 / 100 * 256 ;
V_92 = V_67 -> V_96 / 100 * 256 ;
V_4 -> V_35 . V_91 = F_9 ( V_90 ) ;
V_4 -> V_35 . V_93 = F_9 ( V_92 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_58 * V_59 = V_4 -> V_15 ;
T_4 * V_97 = & V_4 -> V_98 ;
struct V_94 * V_67 =
V_3 -> V_5 . V_6 . V_42 . V_67 ;
struct V_99 * V_100 = V_3 -> V_5 . V_6 . V_42 . V_101 ;
int V_41 , V_102 , V_103 ;
const T_2 * V_104 ;
const T_2 * V_105 ;
V_97 -> V_106 = V_67 -> V_107 * 256 ;
V_97 -> V_108 = V_67 -> V_109 * 256 ;
V_97 -> V_110 = ( T_1 ) V_4 -> V_20 ;
V_97 -> V_111 =
( T_1 ) ( V_4 -> V_112 . V_113 / 1000 ) ;
V_97 -> V_114 = 8 ;
V_97 -> V_115 = V_59 -> V_116 ;
if ( V_100 ) {
V_97 -> V_117 = F_9 ( ( T_2 ) V_100 -> V_118 * 256 / 1000 ) ;
V_97 -> V_119 = F_9 ( ( T_2 ) V_100 -> V_120 * 256 ) ;
} else {
V_97 -> V_117 = F_9 ( 0 ) ;
V_97 -> V_119 = F_9 ( 0 ) ;
}
V_97 -> V_121 = F_17 ( V_59 -> V_122 ) ;
V_104 = V_59 -> V_123 ;
V_105 = V_59 -> V_124 ;
for ( V_41 = 0 ; V_41 < V_125 ; V_41 ++ ) {
for ( V_102 = 0 ; V_102 < V_126 ; V_102 ++ ) {
for ( V_103 = 0 ; V_103 < V_127 ; V_103 ++ ) {
V_97 -> V_128 [ V_41 ] [ V_102 ] [ V_103 ] = F_9 ( * V_104 ) ;
V_97 -> V_129 [ V_41 ] [ V_102 ] [ V_103 ] = F_9 ( * V_105 ) ;
V_104 ++ ;
V_105 ++ ;
}
}
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_130 ;
int V_74 ;
if ( V_4 -> V_21 ) {
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_77 ) ,
& V_130 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_5 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_6 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_7 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_8 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_10 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_13 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_14 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_15 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_19 ( V_3 , V_130 ,
( T_1 * ) & V_4 -> V_35 ,
sizeof( V_78 ) , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static void F_20 ( struct V_2 * V_3 , const bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_132 ;
if ( V_4 -> V_23 ) {
V_132 = F_21 ( V_133 ) ;
if ( V_131 )
V_132 |= V_134 ;
else
V_132 &= ~ V_134 ;
F_22 ( V_133 , V_132 ) ;
}
if ( V_4 -> V_24 ) {
V_132 = F_21 ( V_135 ) ;
if ( V_131 )
V_132 |= V_134 ;
else
V_132 &= ~ V_134 ;
F_22 ( V_135 , V_132 ) ;
}
if ( V_4 -> V_25 ) {
V_132 = F_21 ( V_136 ) ;
if ( V_131 )
V_132 |= V_134 ;
else
V_132 &= ~ V_134 ;
F_22 ( V_136 , V_132 ) ;
}
if ( V_4 -> V_26 ) {
V_132 = F_21 ( V_137 ) ;
if ( V_131 )
V_132 |= V_134 ;
else
V_132 &= ~ V_134 ;
F_22 ( V_137 , V_132 ) ;
}
}
static int F_23 ( struct V_2 * V_3 ,
const struct V_138 * V_139 )
{
const struct V_138 * V_140 = V_139 ;
T_3 V_132 ;
T_3 V_141 = 0 ;
if ( V_140 == NULL )
return - V_45 ;
while ( V_140 -> V_142 != 0xFFFFFFFF ) {
if ( V_140 -> type == V_143 ) {
V_141 |= ( ( V_140 -> V_57 << V_140 -> V_144 ) & V_140 -> V_145 ) ;
} else {
switch ( V_140 -> type ) {
case V_146 :
V_132 = F_24 ( V_140 -> V_142 ) ;
break;
case V_147 :
V_132 = F_21 ( V_140 -> V_142 ) ;
break;
default:
V_132 = F_25 ( V_140 -> V_142 << 2 ) ;
break;
}
V_132 &= ~ V_140 -> V_145 ;
V_132 |= ( ( V_140 -> V_57 << V_140 -> V_144 ) & V_140 -> V_145 ) ;
V_132 |= V_141 ;
switch ( V_140 -> type ) {
case V_146 :
F_26 ( V_140 -> V_142 , V_132 ) ;
break;
case V_147 :
F_22 ( V_140 -> V_142 , V_132 ) ;
break;
default:
F_27 ( V_140 -> V_142 << 2 , V_132 ) ;
break;
}
V_141 = 0 ;
}
V_140 ++ ;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
if ( V_4 -> V_23 || V_4 -> V_24 ||
V_4 -> V_25 || V_4 -> V_26 ) {
F_29 ( V_3 ) ;
if ( V_131 ) {
V_74 = F_23 ( V_3 , V_148 ) ;
if ( V_74 ) {
F_30 ( V_3 ) ;
return V_74 ;
}
}
F_20 ( V_3 , V_131 ) ;
F_30 ( V_3 ) ;
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
int V_74 = 0 ;
if ( V_131 ) {
V_4 -> V_150 = 0 ;
if ( V_4 -> V_21 ) {
if ( V_4 -> V_29 ) {
V_149 = F_32 ( V_3 , V_151 ) ;
if ( V_149 != V_152 )
V_74 = - V_45 ;
else
V_4 -> V_150 |= V_153 ;
}
if ( V_4 -> V_30 ) {
V_149 = F_32 ( V_3 , V_154 ) ;
if ( V_149 != V_152 )
V_74 = - V_45 ;
else
V_4 -> V_150 |= V_155 ;
}
if ( V_4 -> V_31 ) {
V_149 = F_32 ( V_3 , V_156 ) ;
if ( V_149 != V_152 ) {
V_74 = - V_45 ;
} else {
struct V_94 * V_67 =
V_3 -> V_5 . V_6 . V_42 . V_67 ;
T_3 V_157 =
( T_3 ) ( V_67 -> V_158 * 256 ) ;
V_4 -> V_150 |= V_159 ;
F_33 ( V_3 , V_157 ) ;
}
}
}
} else {
if ( V_4 -> V_21 && V_4 -> V_150 ) {
if ( V_4 -> V_150 & V_155 )
F_32 ( V_3 , V_160 ) ;
if ( V_4 -> V_150 & V_153 )
F_32 ( V_3 , V_161 ) ;
if ( V_4 -> V_150 & V_159 )
F_32 ( V_3 , V_162 ) ;
V_4 -> V_150 = 0 ;
}
}
return V_74 ;
}
static int F_34 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
int V_74 = 0 ;
if ( V_4 -> V_22 ) {
if ( V_131 ) {
V_149 = F_32 ( V_3 , V_163 ) ;
if ( V_149 != V_152 ) {
V_74 = - V_45 ;
V_4 -> V_164 = false ;
} else {
V_4 -> V_164 = true ;
}
} else if ( V_4 -> V_164 ) {
F_32 ( V_3 , V_165 ) ;
V_4 -> V_164 = false ;
}
}
return V_74 ;
}
static int F_35 ( struct V_2 * V_3 ,
bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 = V_152 ;
if ( V_4 -> V_166 ) {
if ( V_131 )
V_149 = F_32 ( V_3 , V_167 ) ;
else
V_149 = F_32 ( V_3 , V_168 ) ;
}
if ( V_149 == V_152 )
return 0 ;
else
return - V_45 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_94 * V_67 =
V_3 -> V_5 . V_6 . V_42 . V_67 ;
T_6 V_169 ;
T_6 V_170 ;
int V_74 = 0 ;
bool V_171 = false ;
if ( V_4 -> V_21 ) {
V_169 = V_171 ?
V_3 -> V_5 . V_6 . V_172 : ( - 1 * V_3 -> V_5 . V_6 . V_172 ) ;
V_170 = ( ( 100 + V_169 ) *
( T_6 ) V_67 -> V_109 ) / 100 ;
V_74 = F_37 ( V_3 , ( T_3 ) V_170 ) ;
}
return V_74 ;
}
void F_38 ( struct V_2 * V_3 , bool V_173 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_174 == V_173 )
return;
V_4 -> V_174 = V_173 ;
F_39 ( V_3 , V_173 ) ;
}
bool F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_175 = F_41 ( V_3 ) ;
T_3 V_176 = V_4 -> V_177 ? 450 : 300 ;
if ( V_175 < V_176 )
return true ;
else
return false ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_178 * V_179 ;
bool V_180 ;
T_3 V_181 , V_182 ;
int V_41 ;
if ( V_10 -> V_183 ) {
V_10 -> V_184 = V_3 -> V_5 . V_6 . V_185 [ V_3 -> V_5 . V_6 . V_186 ] . V_184 ;
V_10 -> V_187 = V_3 -> V_5 . V_6 . V_185 [ V_3 -> V_5 . V_6 . V_186 ] . V_187 ;
} else {
V_10 -> V_184 = 0 ;
V_10 -> V_187 = 0 ;
}
if ( ( V_3 -> V_5 . V_6 . V_188 > 1 ) ||
F_40 ( V_3 ) )
V_180 = true ;
else
V_180 = false ;
if ( ( V_10 -> V_189 & V_190 ) == V_191 )
V_4 -> V_192 = true ;
else
V_4 -> V_192 = false ;
if ( V_3 -> V_5 . V_6 . V_193 )
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_194 ;
else
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_195 ;
if ( V_3 -> V_5 . V_6 . V_193 == false ) {
for ( V_41 = 0 ; V_41 < V_11 -> V_196 ; V_41 ++ ) {
if ( V_11 -> V_197 [ V_41 ] . V_182 > V_179 -> V_182 )
V_11 -> V_197 [ V_41 ] . V_182 = V_179 -> V_182 ;
if ( V_11 -> V_197 [ V_41 ] . V_181 > V_179 -> V_181 )
V_11 -> V_197 [ V_41 ] . V_181 = V_179 -> V_181 ;
}
}
if ( V_180 ) {
V_182 = V_11 -> V_197 [ V_11 -> V_196 - 1 ] . V_182 ;
V_181 = V_11 -> V_197 [ 0 ] . V_181 ;
} else {
V_182 = V_11 -> V_197 [ 0 ] . V_182 ;
V_181 = V_11 -> V_197 [ 0 ] . V_181 ;
}
if ( V_10 -> V_183 ) {
if ( V_181 < V_3 -> V_5 . V_6 . V_185 [ V_3 -> V_5 . V_6 . V_186 ] . V_181 )
V_181 = V_3 -> V_5 . V_6 . V_185 [ V_3 -> V_5 . V_6 . V_186 ] . V_181 ;
if ( V_182 < V_3 -> V_5 . V_6 . V_185 [ V_3 -> V_5 . V_6 . V_186 ] . V_182 )
V_182 = V_3 -> V_5 . V_6 . V_185 [ V_3 -> V_5 . V_6 . V_186 ] . V_182 ;
}
V_11 -> V_197 [ 0 ] . V_181 = V_181 ;
V_11 -> V_197 [ 0 ] . V_182 = V_182 ;
if ( V_11 -> V_197 [ 1 ] . V_181 < V_11 -> V_197 [ 0 ] . V_181 )
V_11 -> V_197 [ 1 ] . V_181 = V_11 -> V_197 [ 0 ] . V_181 ;
if ( V_180 ) {
if ( V_11 -> V_197 [ 0 ] . V_182 < V_11 -> V_197 [ 1 ] . V_182 )
V_11 -> V_197 [ 0 ] . V_182 = V_11 -> V_197 [ 1 ] . V_182 ;
} else {
if ( V_11 -> V_197 [ 1 ] . V_182 < V_11 -> V_197 [ 0 ] . V_182 )
V_11 -> V_197 [ 1 ] . V_182 = V_11 -> V_197 [ 0 ] . V_182 ;
}
}
static int F_43 ( struct V_2 * V_3 ,
int V_198 , int V_199 )
{
int V_200 = 0 * 1000 ;
int V_201 = 255 * 1000 ;
T_3 V_202 ;
if ( V_200 < V_198 )
V_200 = V_198 ;
if ( V_201 > V_199 )
V_201 = V_199 ;
if ( V_201 < V_200 ) {
F_44 ( L_1 , V_200 , V_201 ) ;
return - V_45 ;
}
V_202 = F_24 ( V_203 ) ;
V_202 &= ~ ( V_204 | V_205 ) ;
V_202 |= F_45 ( V_201 / 1000 ) |
F_46 ( V_200 / 1000 ) ;
F_26 ( V_203 , V_202 ) ;
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DIG_THERM_DPM_MASK;
tmp |= DIG_THERM_DPM(high_temp / 1000);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
V_3 -> V_5 . V_6 . V_206 . V_198 = V_200 ;
V_3 -> V_5 . V_6 . V_206 . V_199 = V_201 ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 ,
bool V_131 )
{
T_3 V_207 = F_24 ( V_203 ) ;
T_5 V_208 ;
if ( V_131 ) {
V_207 &= ~ ( V_209 | V_210 ) ;
F_26 ( V_203 , V_207 ) ;
V_3 -> V_211 . V_212 = false ;
V_208 = F_32 ( V_3 , V_213 ) ;
if ( V_208 != V_152 ) {
F_48 ( L_2 ) ;
return - V_45 ;
}
} else {
V_207 |= V_209 | V_210 ;
F_26 ( V_203 , V_207 ) ;
V_3 -> V_211 . V_212 = true ;
V_208 = F_32 ( V_3 , V_214 ) ;
if ( V_208 != V_152 ) {
F_48 ( L_3 ) ;
return - V_45 ;
}
}
return 0 ;
}
static void F_49 ( struct V_2 * V_3 , T_3 V_215 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
if ( V_4 -> V_216 ) {
V_202 = ( F_24 ( V_217 ) & V_218 ) >> V_219 ;
V_4 -> V_220 = V_202 ;
V_202 = ( F_24 ( V_217 ) & V_221 ) >> V_222 ;
V_4 -> V_223 = V_202 ;
V_4 -> V_216 = false ;
}
V_202 = F_24 ( V_217 ) & ~ V_221 ;
V_202 |= F_50 ( 0 ) ;
F_26 ( V_217 , V_202 ) ;
V_202 = F_24 ( V_217 ) & ~ V_218 ;
V_202 |= F_51 ( V_215 ) ;
F_26 ( V_217 , V_202 ) ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_7 V_224 = { V_225 } ;
T_3 V_226 ;
T_3 V_227 , V_228 , V_229 , V_230 ;
T_2 V_231 , V_232 , V_233 ;
T_3 V_234 , V_202 ;
int V_74 ;
T_8 V_235 ;
if ( ! V_4 -> V_236 ) {
V_3 -> V_5 . V_6 . V_82 . V_237 = false ;
return 0 ;
}
V_226 = ( F_24 ( V_238 ) & V_239 ) >> V_240 ;
if ( V_226 == 0 ) {
V_3 -> V_5 . V_6 . V_82 . V_237 = false ;
return 0 ;
}
V_235 = ( T_8 ) V_3 -> V_5 . V_6 . V_82 . V_241 * V_226 ;
F_53 ( V_235 , 10000 ) ;
V_231 = ( T_2 ) V_235 ;
V_227 = V_3 -> V_5 . V_6 . V_82 . V_242 - V_3 -> V_5 . V_6 . V_82 . V_223 ;
V_228 = V_3 -> V_5 . V_6 . V_82 . V_243 - V_3 -> V_5 . V_6 . V_82 . V_242 ;
V_229 = V_3 -> V_5 . V_6 . V_82 . V_244 - V_3 -> V_5 . V_6 . V_82 . V_241 ;
V_230 = V_3 -> V_5 . V_6 . V_82 . V_245 - V_3 -> V_5 . V_6 . V_82 . V_244 ;
V_232 = ( T_2 ) ( ( 50 + ( ( 16 * V_226 * V_229 ) / V_227 ) ) / 100 ) ;
V_233 = ( T_2 ) ( ( 50 + ( ( 16 * V_226 * V_230 ) / V_228 ) ) / 100 ) ;
V_224 . V_246 = F_9 ( ( 50 + V_3 -> V_5 . V_6 . V_82 . V_223 ) / 100 ) ;
V_224 . V_247 = F_9 ( ( 50 + V_3 -> V_5 . V_6 . V_82 . V_242 ) / 100 ) ;
V_224 . V_248 = F_9 ( ( 50 + V_3 -> V_5 . V_6 . V_82 . V_249 ) / 100 ) ;
V_224 . V_250 = F_9 ( V_232 ) ;
V_224 . V_251 = F_9 ( V_233 ) ;
V_224 . V_252 = F_9 ( V_231 ) ;
V_224 . V_253 = F_9 ( V_3 -> V_5 . V_6 . V_82 . V_254 ) ;
V_224 . V_255 = F_9 ( 1 ) ;
V_224 . V_256 = F_9 ( 1 ) ;
V_224 . V_257 = F_9 ( 5 ) ;
V_234 = F_54 ( V_3 ) ;
V_224 . V_258 = F_17 ( ( V_3 -> V_5 . V_6 . V_82 . V_259 *
V_234 ) / 1600 ) ;
V_224 . V_260 = F_9 ( ( T_2 ) V_226 ) ;
V_202 = ( F_24 ( V_261 ) & V_262 ) >> V_263 ;
V_224 . V_264 = ( V_265 ) V_202 ;
V_74 = F_19 ( V_3 ,
V_4 -> V_236 ,
( T_1 * ) ( & V_224 ) ,
sizeof( V_224 ) ,
V_4 -> V_80 ) ;
if ( V_74 ) {
F_44 ( L_4 ) ;
V_3 -> V_5 . V_6 . V_82 . V_237 = false ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_74 ;
if ( V_4 -> V_266 ) {
V_74 = F_56 ( V_3 ,
V_267 ,
V_268 ) ;
if ( V_74 != V_152 )
return - V_45 ;
V_74 = F_56 ( V_3 ,
V_269 ,
V_3 -> V_5 . V_6 . V_82 . V_270 ) ;
if ( V_74 != V_152 )
return - V_45 ;
} else {
V_74 = F_56 ( V_3 ,
V_267 ,
V_271 ) ;
if ( V_74 != V_152 )
return - V_45 ;
}
return 0 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
if ( ! V_4 -> V_216 ) {
V_202 = F_24 ( V_217 ) & ~ V_218 ;
V_202 |= F_51 ( V_4 -> V_220 ) ;
F_26 ( V_217 , V_202 ) ;
V_202 = F_24 ( V_217 ) & ~ V_221 ;
V_202 |= F_50 ( V_4 -> V_223 ) ;
F_26 ( V_217 , V_202 ) ;
V_4 -> V_216 = true ;
}
}
static void F_58 ( struct V_2 * V_3 )
{
if ( V_3 -> V_5 . V_6 . V_82 . V_237 ) {
F_55 ( V_3 ) ;
F_49 ( V_3 , V_272 ) ;
}
}
static void F_59 ( struct V_2 * V_3 )
{
T_3 V_202 ;
if ( V_3 -> V_5 . V_273 ) {
V_202 = F_24 ( V_274 ) & ~ V_275 ;
V_202 |= F_60 ( V_3 -> V_5 . V_273 - 1 ) ;
F_26 ( V_274 , V_202 ) ;
}
V_202 = F_24 ( V_217 ) & ~ V_276 ;
V_202 |= F_61 ( 0x28 ) ;
F_26 ( V_217 , V_202 ) ;
}
static int F_62 ( struct V_2 * V_3 )
{
int V_74 ;
F_59 ( V_3 ) ;
V_74 = F_43 ( V_3 , V_277 , V_278 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_47 ( V_3 , true ) ;
if ( V_74 )
return V_74 ;
if ( V_3 -> V_5 . V_6 . V_82 . V_237 ) {
V_74 = F_52 ( V_3 ) ;
if ( V_74 )
return V_74 ;
F_58 ( V_3 ) ;
}
return 0 ;
}
static void F_63 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_5 . V_279 )
F_57 ( V_3 ) ;
}
static int F_64 ( struct V_2 * V_3 ,
T_2 V_280 , T_3 V_57 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_65 ( V_3 ,
V_4 -> V_281 + V_280 ,
V_57 , V_4 -> V_80 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_4 * V_282 = & V_4 -> V_98 ;
if ( V_4 -> V_283 ) {
T_2 V_202 ;
V_202 = 45 ;
V_282 -> V_284 = F_9 ( V_202 ) ;
V_202 = 30 ;
V_282 -> V_285 = F_9 ( V_202 ) ;
}
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 = 0 ;
T_3 V_286 = 0 ;
if ( V_4 -> V_287 ) {
V_286 = F_17 ( V_4 -> V_286 ) ;
V_74 = F_19 ( V_3 ,
V_4 -> V_288 +
F_12 ( T_4 , V_289 ) ,
( T_1 * ) & V_286 ,
sizeof( T_3 ) , V_4 -> V_80 ) ;
}
return V_74 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_290 , V_291 ;
T_2 V_32 , V_292 ;
int V_41 ;
V_4 -> V_293 . V_46 = 0 ;
V_4 -> V_294 . V_46 = 0 ;
if ( V_3 -> V_5 . V_6 . V_48 & V_49 ) {
for ( V_41 = 0 ; V_41 < V_295 ; V_41 ++ ) {
V_291 = V_296 + V_41 ;
if ( F_69 ( V_3 , V_291 , & V_32 ) != 0 )
continue;
if ( V_32 != 0 && V_32 != V_291 ) {
V_4 -> V_293 . V_297 [ V_4 -> V_293 . V_46 ] = V_32 ;
V_4 -> V_293 . V_290 [ V_4 -> V_293 . V_46 ] = V_291 ;
V_4 -> V_293 . V_46 ++ ;
}
}
} else if ( F_70 ( V_3 , & V_290 ) == 0 ) {
for ( V_41 = 0 ; V_41 < V_295 ; V_41 ++ ) {
V_291 = V_296 + V_41 ;
if ( F_71 ( V_3 , & V_32 , & V_292 ,
V_291 ,
V_290 ) == 0 ) {
if ( V_32 != 0 && V_32 != V_291 ) {
V_4 -> V_293 . V_297 [ V_4 -> V_293 . V_46 ] = V_32 ;
V_4 -> V_293 . V_290 [ V_4 -> V_293 . V_46 ] = V_291 ;
V_4 -> V_293 . V_46 ++ ;
}
if ( V_292 != 0 && V_292 != V_291 ) {
V_4 -> V_294 . V_297 [ V_4 -> V_294 . V_46 ] = V_292 ;
V_4 -> V_294 . V_290 [ V_4 -> V_294 . V_46 ] = V_291 ;
V_4 -> V_294 . V_46 ++ ;
}
}
}
}
}
static void F_72 ( struct V_2 * V_3 , T_3 V_298 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
bool V_299 ;
enum V_300 V_301 ;
T_3 V_202 ;
switch ( V_298 ) {
case 0 :
default:
V_299 = false ;
break;
case ( 1 << V_302 ) :
V_299 = true ;
V_301 = V_303 ;
break;
case ( 1 << V_304 ) :
V_299 = true ;
V_301 = V_305 ;
break;
case ( ( 1 << V_304 ) |
( 1 << V_302 ) ) :
V_299 = true ;
V_301 = V_306 ;
break;
}
if ( V_299 ) {
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DPM_EVENT_SRC_MASK;
tmp |= DPM_EVENT_SRC(dpm_event_src);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
V_202 = F_24 ( V_307 ) ;
if ( V_4 -> V_308 )
V_202 &= ~ V_309 ;
else
V_202 |= V_309 ;
F_26 ( V_307 , V_202 ) ;
} else {
V_202 = F_24 ( V_307 ) ;
V_202 |= V_309 ;
F_26 ( V_307 , V_202 ) ;
}
}
static void F_73 ( struct V_2 * V_3 ,
enum V_310 V_311 ,
bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_131 ) {
if ( ! ( V_4 -> V_312 & ( 1 << V_311 ) ) ) {
V_4 -> V_312 |= 1 << V_311 ;
F_72 ( V_3 , V_4 -> V_312 ) ;
}
} else {
if ( V_4 -> V_312 & ( 1 << V_311 ) ) {
V_4 -> V_312 &= ~ ( 1 << V_311 ) ;
F_72 ( V_3 , V_4 -> V_312 ) ;
}
}
}
static void F_74 ( struct V_2 * V_3 )
{
if ( V_3 -> V_5 . V_6 . V_48 & V_313 )
F_32 ( V_3 , V_314 ) ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
if ( ! V_4 -> V_315 )
return 0 ;
if ( ( ! V_4 -> V_316 ) &&
( V_4 -> V_315 & ( V_317 | V_318 ) ) ) {
V_149 = F_32 ( V_3 , V_319 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
if ( ( ! V_4 -> V_320 ) &&
( V_4 -> V_315 & V_321 ) ) {
V_149 = F_32 ( V_3 , V_322 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
V_4 -> V_315 = 0 ;
return 0 ;
}
static int F_76 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
if ( V_131 ) {
if ( ! V_4 -> V_316 ) {
V_149 = F_32 ( V_3 , V_323 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
if ( ! V_4 -> V_320 ) {
V_149 = F_32 ( V_3 , V_324 ) ;
if ( V_149 != V_152 )
return - V_45 ;
F_77 ( V_325 , V_326 , ~ V_326 ) ;
F_26 ( V_327 , 0x05 ) ;
F_26 ( V_328 , 0x05 ) ;
F_26 ( V_329 , 0x100005 ) ;
F_78 ( 10 ) ;
F_26 ( V_327 , 0x400005 ) ;
F_26 ( V_328 , 0x400005 ) ;
F_26 ( V_329 , 0x500005 ) ;
}
} else {
if ( ! V_4 -> V_316 ) {
V_149 = F_32 ( V_3 , V_330 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
if ( ! V_4 -> V_320 ) {
V_149 = F_32 ( V_3 , V_331 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
}
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
int V_74 ;
T_3 V_202 ;
V_202 = F_24 ( V_307 ) ;
V_202 |= V_332 ;
F_26 ( V_307 , V_202 ) ;
V_202 = F_24 ( V_333 ) ;
V_202 |= V_334 ;
F_26 ( V_333 , V_202 ) ;
F_64 ( V_3 , F_12 ( V_335 , V_336 ) , 0x1000 ) ;
F_77 ( V_337 , 0 , ~ V_338 ) ;
V_149 = F_32 ( V_3 , V_339 ) ;
if ( V_149 != V_152 )
return - V_45 ;
V_74 = F_76 ( V_3 , true ) ;
if ( V_74 )
return V_74 ;
if ( ! V_4 -> V_340 ) {
V_149 = F_32 ( V_3 , V_341 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
if ( ! V_4 -> V_315 )
return 0 ;
if ( ( ! V_4 -> V_316 ) &&
( V_4 -> V_315 & ( V_317 | V_318 ) ) ) {
V_149 = F_32 ( V_3 , V_342 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
if ( ( ! V_4 -> V_320 ) &&
( V_4 -> V_315 & V_321 ) ) {
V_149 = F_32 ( V_3 , V_343 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
int V_74 ;
T_3 V_202 ;
V_202 = F_24 ( V_307 ) ;
V_202 &= ~ V_332 ;
F_26 ( V_307 , V_202 ) ;
V_202 = F_24 ( V_333 ) ;
V_202 &= ~ V_334 ;
F_26 ( V_333 , V_202 ) ;
if ( ! V_4 -> V_340 ) {
V_149 = F_32 ( V_3 , V_344 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
V_74 = F_76 ( V_3 , false ) ;
if ( V_74 )
return V_74 ;
V_149 = F_32 ( V_3 , V_345 ) ;
if ( V_149 != V_152 )
return - V_45 ;
return 0 ;
}
static void F_82 ( struct V_2 * V_3 , bool V_131 )
{
T_3 V_202 = F_24 ( V_333 ) ;
if ( V_131 )
V_202 &= ~ V_346 ;
else
V_202 |= V_346 ;
F_26 ( V_333 , V_202 ) ;
}
static T_5 F_56 ( struct V_2 * V_3 ,
T_9 V_347 , T_3 V_348 )
{
F_27 ( V_349 , V_348 ) ;
return F_32 ( V_3 , V_347 ) ;
}
static T_5 F_83 ( struct V_2 * V_3 ,
T_9 V_347 , T_3 * V_348 )
{
T_5 V_149 ;
V_149 = F_32 ( V_3 , V_347 ) ;
if ( ( V_149 == V_152 ) && V_348 )
* V_348 = F_25 ( V_349 ) ;
return V_149 ;
}
static int F_84 ( struct V_2 * V_3 , T_3 V_350 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_316 ) {
T_5 V_149 =
F_56 ( V_3 , V_351 , 1 << V_350 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_85 ( struct V_2 * V_3 , T_3 V_350 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_320 ) {
T_5 V_149 =
F_56 ( V_3 , V_352 , 1 << V_350 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_86 ( struct V_2 * V_3 , T_3 V_350 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_340 ) {
T_5 V_149 =
F_56 ( V_3 , V_353 , V_350 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , T_3 V_350 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_150 & V_159 ) {
T_5 V_149 =
F_56 ( V_3 , V_354 , V_350 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
T_3 V_170 )
{
T_5 V_149 =
F_56 ( V_3 , V_355 , V_170 ) ;
if ( V_149 != V_152 )
return - V_45 ;
return 0 ;
}
static int F_87 ( struct V_2 * V_3 )
{
return F_76 ( V_3 , false ) ;
}
static T_3 F_88 ( struct V_2 * V_3 )
{
T_3 V_356 ;
T_5 V_149 =
F_83 ( V_3 ,
V_357 ,
& V_356 ) ;
if ( V_149 != V_152 )
V_356 = 0 ;
return V_356 ;
}
static T_3 F_89 ( struct V_2 * V_3 )
{
T_3 V_358 ;
T_5 V_149 =
F_83 ( V_3 ,
V_359 ,
& V_358 ) ;
if ( V_149 != V_152 )
V_358 = 0 ;
return V_358 ;
}
static void F_90 ( struct V_2 * V_3 )
{
int V_41 ;
F_91 ( V_3 ) ;
F_92 ( V_3 ) ;
F_93 ( V_3 ) ;
for ( V_41 = 0 ; V_41 < V_3 -> V_360 ; V_41 ++ ) {
if ( F_24 ( V_361 ) & V_362 )
break;
}
}
static void F_94 ( struct V_2 * V_3 )
{
F_95 ( V_3 ) ;
F_96 ( V_3 ) ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
int V_74 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_363 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_288 = V_202 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_364 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_281 = V_202 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_365 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_366 = V_202 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_367 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_236 = V_202 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_368 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_369 = V_202 ;
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_370 . V_371 =
F_24 ( V_372 ) ;
V_4 -> V_370 . V_373 =
F_24 ( V_374 ) ;
V_4 -> V_370 . V_375 =
F_24 ( V_376 ) ;
V_4 -> V_370 . V_377 =
F_24 ( V_378 ) ;
V_4 -> V_370 . V_379 =
F_24 ( V_380 ) ;
V_4 -> V_370 . V_381 =
F_24 ( V_382 ) ;
V_4 -> V_370 . V_383 = F_25 ( V_384 ) ;
V_4 -> V_370 . V_385 = F_25 ( V_386 ) ;
V_4 -> V_370 . V_387 = F_25 ( V_388 ) ;
V_4 -> V_370 . V_389 = F_25 ( V_390 ) ;
V_4 -> V_370 . V_391 = F_25 ( V_392 ) ;
V_4 -> V_370 . V_393 = F_25 ( V_394 ) ;
V_4 -> V_370 . V_395 = F_25 ( V_396 ) ;
V_4 -> V_370 . V_397 = F_25 ( V_398 ) ;
V_4 -> V_370 . V_399 = F_25 ( V_400 ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_286 = 0 ;
}
static void F_100 ( struct V_2 * V_3 ,
bool V_131 )
{
T_3 V_202 = F_24 ( V_307 ) ;
if ( V_131 )
V_202 &= ~ V_309 ;
else
V_202 |= V_309 ;
F_26 ( V_307 , V_202 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
T_3 V_202 = F_24 ( V_307 ) ;
V_202 |= V_401 ;
F_26 ( V_307 , V_202 ) ;
}
static int F_102 ( struct V_2 * V_3 ,
bool V_402 )
{
T_9 V_347 = V_402 ? V_403 : V_404 ;
return ( F_32 ( V_3 , V_347 ) == V_152 ) ? 0 : - V_45 ;
}
static int F_103 ( struct V_2 * V_3 ,
bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_131 ) {
if ( V_4 -> V_405 ) {
if ( F_32 ( V_3 , V_406 ) != V_152 )
return - V_45 ;
} else {
if ( F_32 ( V_3 , V_407 ) != V_152 )
return - V_45 ;
}
} else {
if ( V_4 -> V_405 ) {
if ( F_32 ( V_3 , V_407 ) != V_152 )
return - V_45 ;
}
}
return 0 ;
}
static void F_104 ( struct V_2 * V_3 )
{
T_3 V_202 = F_24 ( V_408 ) ;
T_3 V_409 ;
T_3 V_410 ;
T_3 V_411 = V_3 -> clock . V_412 . V_413 ;
T_3 V_414 = F_105 ( V_3 ) ;
T_3 V_175 = F_41 ( V_3 ) ;
V_202 &= ~ V_415 ;
if ( V_3 -> V_5 . V_6 . V_188 > 0 )
V_202 |= F_106 ( V_416 ) ;
else
V_202 |= F_106 ( V_417 ) ;
F_26 ( V_408 , V_202 ) ;
if ( V_414 == 0 )
V_414 = 60 ;
if ( V_175 == 0xffffffff )
V_175 = 500 ;
V_410 = 1000000 / V_414 ;
V_409 =
V_410 - 200 - V_175 ;
V_202 = V_409 * ( V_411 / 100 ) ;
F_26 ( V_418 , V_202 ) ;
F_64 ( V_3 , F_12 ( V_335 , V_419 ) , 0x64 ) ;
F_64 ( V_3 , F_12 ( V_335 , V_420 ) , ( V_410 - V_409 ) ) ;
F_102 ( V_3 , ( V_3 -> V_5 . V_6 . V_188 == 1 ) ) ;
}
static void F_107 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
if ( V_131 ) {
if ( V_4 -> V_421 ) {
V_202 = F_24 ( V_307 ) ;
V_202 |= V_422 ;
F_26 ( V_307 , V_202 ) ;
}
} else {
V_202 = F_24 ( V_380 ) ;
V_202 &= ~ V_423 ;
F_26 ( V_380 , V_202 ) ;
V_202 = F_24 ( V_307 ) ;
V_202 &= ~ V_422 ;
F_26 ( V_307 , V_202 ) ;
}
}
static void F_108 ( struct V_2 * V_3 )
{
F_26 ( V_424 , ( F_109 ( V_425 ) | F_110 ( V_426 ) ) ) ;
}
static void F_111 ( struct V_2 * V_3 )
{
T_3 V_202 = F_24 ( V_408 ) ;
V_202 &= ~ ( V_415 | V_427 ) ;
V_202 |= ( F_106 ( V_417 ) |
F_112 ( V_428 ) ) ;
F_26 ( V_408 , V_202 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
T_3 V_202 ;
V_202 = F_24 ( V_333 ) ;
V_202 &= ~ ( V_429 | V_430 ) ;
F_26 ( V_333 , V_202 ) ;
F_26 ( V_431 , V_432 ) ;
F_26 ( V_433 , V_434 ) ;
F_26 ( V_435 , V_436 ) ;
F_26 ( V_437 , V_438 ) ;
F_26 ( V_439 , V_440 ) ;
F_26 ( V_441 , V_442 ) ;
F_26 ( V_443 , V_444 ) ;
F_26 ( V_445 , V_446 ) ;
}
static void F_114 ( struct V_2 * V_3 )
{
T_3 V_202 ;
V_202 = F_24 ( V_333 ) ;
V_202 |= ( V_429 | V_430 ) ;
F_26 ( V_333 , V_202 ) ;
F_26 ( V_431 , 0 ) ;
F_26 ( V_433 , 0 ) ;
F_26 ( V_435 , 0 ) ;
F_26 ( V_437 , 0 ) ;
F_26 ( V_439 , 0 ) ;
F_26 ( V_441 , 0 ) ;
F_26 ( V_443 , 0 ) ;
F_26 ( V_445 , 0 ) ;
}
static int F_115 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_41 , V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_360 ; V_41 ++ ) {
if ( F_24 ( V_447 ) & V_448 )
break;
}
F_26 ( V_449 , 1 ) ;
F_96 ( V_3 ) ;
F_95 ( V_3 ) ;
V_74 = F_116 ( V_3 , V_4 -> V_80 ) ;
return V_74 ;
}
static int F_117 ( struct V_2 * V_3 ,
struct V_450 * V_451 ,
struct V_452 * V_453 )
{
T_3 V_41 ;
if ( V_451 == NULL )
return - V_45 ;
V_453 -> V_454 = 0 ;
V_453 -> V_455 = 0 ;
V_453 -> V_46 = V_451 -> V_46 ;
for ( V_41 = 0 ; V_41 < V_453 -> V_46 ; V_41 ++ ) {
V_453 -> V_44 [ V_41 ] . V_57 = V_451 -> V_44 [ V_41 ] . V_456 ;
V_453 -> V_44 [ V_41 ] . V_457 = 0 ;
}
return 0 ;
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
if ( V_4 -> V_458 == V_459 ) {
V_74 = F_119 ( V_3 , V_460 ,
V_461 ,
& V_4 -> V_56 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_458 == V_462 ) {
V_74 = F_117 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_463 ,
& V_4 -> V_56 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_56 . V_46 > V_464 )
F_120 ( V_3 , V_464 ,
& V_4 -> V_56 ) ;
if ( V_4 -> V_465 == V_459 ) {
V_74 = F_119 ( V_3 , V_466 ,
V_461 ,
& V_4 -> V_467 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_465 == V_462 ) {
V_74 = F_117 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_468 ,
& V_4 -> V_467 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_467 . V_46 > V_469 )
F_120 ( V_3 , V_469 ,
& V_4 -> V_467 ) ;
if ( V_4 -> V_470 == V_459 ) {
V_74 = F_119 ( V_3 , V_471 ,
V_461 ,
& V_4 -> V_472 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_470 == V_462 ) {
V_74 = F_117 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_473 ,
& V_4 -> V_472 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_472 . V_46 > V_474 )
F_120 ( V_3 , V_474 ,
& V_4 -> V_472 ) ;
return 0 ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_475 * V_453 ,
T_10 * V_476 )
{
int V_74 ;
V_74 = F_122 ( V_3 , V_453 ,
& V_476 -> V_477 ,
& V_476 -> V_478 ) ;
if ( V_74 ) {
V_476 -> V_477 = V_453 -> V_57 * V_33 ;
V_476 -> V_478 = V_453 -> V_57 * V_33 ;
}
V_476 -> V_479 = F_9 ( V_453 -> V_57 * V_33 ) ;
V_476 -> V_477 =
F_9 ( V_476 -> V_477 ) ;
V_476 -> V_478 =
F_9 ( V_476 -> V_478 ) ;
}
static int F_123 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_46 ;
V_282 -> V_480 = V_4 -> V_56 . V_46 ;
for ( V_46 = 0 ; V_46 < V_282 -> V_480 ; V_46 ++ ) {
F_121 ( V_3 ,
& V_4 -> V_56 . V_44 [ V_46 ] ,
& V_282 -> V_481 [ V_46 ] ) ;
if ( V_4 -> V_458 == V_459 )
V_282 -> V_481 [ V_46 ] . V_482 |=
V_4 -> V_56 . V_44 [ V_46 ] . V_457 ;
else
V_282 -> V_481 [ V_46 ] . V_482 = 0 ;
}
V_282 -> V_480 = F_17 ( V_282 -> V_480 ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
unsigned int V_46 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_282 -> V_483 = V_4 -> V_467 . V_46 ;
for ( V_46 = 0 ; V_46 < V_282 -> V_483 ; V_46 ++ ) {
F_121 ( V_3 ,
& V_4 -> V_467 . V_44 [ V_46 ] ,
& V_282 -> V_484 [ V_46 ] ) ;
if ( V_4 -> V_465 == V_459 )
V_282 -> V_484 [ V_46 ] . V_482 |=
V_4 -> V_467 . V_44 [ V_46 ] . V_457 ;
else
V_282 -> V_484 [ V_46 ] . V_482 = 0 ;
}
V_282 -> V_483 = F_17 ( V_282 -> V_483 ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_46 ;
V_282 -> V_485 = V_4 -> V_472 . V_46 ;
for ( V_46 = 0 ; V_46 < V_282 -> V_485 ; V_46 ++ ) {
F_121 ( V_3 ,
& V_4 -> V_472 . V_44 [ V_46 ] ,
& V_282 -> V_486 [ V_46 ] ) ;
if ( V_4 -> V_470 == V_459 )
V_282 -> V_486 [ V_46 ] . V_482 |=
V_4 -> V_472 . V_44 [ V_46 ] . V_457 ;
else
V_282 -> V_486 [ V_46 ] . V_482 = 0 ;
}
V_282 -> V_485 = F_17 ( V_282 -> V_485 ) ;
return 0 ;
}
static int F_126 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
int V_74 ;
V_74 = F_123 ( V_3 , V_282 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_124 ( V_3 , V_282 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_125 ( V_3 , V_282 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , T_3 V_182 ,
T_10 * V_487 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 = 0 ;
if ( V_4 -> V_470 != V_488 ) {
for ( V_41 = 0 ; V_41 < V_3 -> V_5 . V_6 . V_42 . V_473 . V_46 ; V_41 ++ ) {
if ( V_182 <= V_3 -> V_5 . V_6 . V_42 . V_473 . V_44 [ V_41 ] . V_489 ) {
V_487 -> V_479 = V_4 -> V_472 . V_44 [ V_41 ] . V_57 ;
break;
}
}
if ( V_41 >= V_3 -> V_5 . V_6 . V_42 . V_473 . V_46 )
return - V_45 ;
}
return - V_45 ;
}
static int F_122 ( struct V_2 * V_3 ,
struct V_475 * V_453 ,
T_2 * V_490 , T_2 * V_491 )
{
T_2 V_492 , V_493 ;
bool V_494 = false ;
* V_490 = V_453 -> V_57 * V_33 ;
* V_491 = V_453 -> V_57 * V_33 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 == NULL )
return - V_45 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 ) {
for ( V_492 = 0 ; ( T_3 ) V_492 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_492 ++ ) {
if ( V_453 -> V_57 ==
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_492 ] . V_456 ) {
V_494 = true ;
if ( ( T_3 ) V_492 < V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 )
V_493 = V_492 ;
else
V_493 = V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 - 1 ;
* V_491 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_493 ] . V_32 * V_33 ;
* V_490 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_493 ] . V_53 * V_33 ;
break;
}
}
if ( ! V_494 ) {
for ( V_492 = 0 ; ( T_3 ) V_492 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_492 ++ ) {
if ( V_453 -> V_57 <=
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_492 ] . V_456 ) {
V_494 = true ;
if ( ( T_3 ) V_492 < V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 )
V_493 = V_492 ;
else
V_493 = V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 - 1 ;
* V_491 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_493 ] . V_32 * V_33 ;
* V_490 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_493 ] . V_53 * V_33 ;
break;
}
}
}
}
return 0 ;
}
static void F_128 ( struct V_2 * V_3 ,
const struct V_495 * V_496 ,
T_3 V_181 ,
T_3 * V_497 )
{
unsigned int V_41 ;
* V_497 = 1 ;
for ( V_41 = 0 ; V_41 < V_496 -> V_46 ; V_41 ++ ) {
if ( V_181 < V_496 -> V_44 [ V_41 ] . V_181 ) {
* V_497 = V_41 ;
break;
}
}
}
static void F_129 ( struct V_2 * V_3 ,
const struct V_495 * V_496 ,
T_3 V_182 ,
T_3 * V_497 )
{
unsigned int V_41 ;
* V_497 = 1 ;
for ( V_41 = 0 ; V_41 < V_496 -> V_46 ; V_41 ++ ) {
if ( V_182 < V_496 -> V_44 [ V_41 ] . V_182 ) {
* V_497 = V_41 ;
break;
}
}
}
static int F_130 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
int V_74 ;
V_74 = F_11 ( V_3 , V_4 -> V_369 ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_202 &= 0x00FFFFFF ;
V_202 |= V_498 << 24 ;
return F_65 ( V_3 , V_4 -> V_369 ,
V_202 , V_4 -> V_80 ) ;
}
static int F_131 ( struct V_2 * V_3 ,
struct V_450 * V_499 ,
T_3 clock , T_3 * V_487 )
{
T_3 V_41 = 0 ;
if ( V_499 -> V_46 == 0 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_499 -> V_46 ; V_41 ++ ) {
if ( V_499 -> V_44 [ V_41 ] . V_489 >= clock ) {
* V_487 = V_499 -> V_44 [ V_41 ] . V_456 ;
return 0 ;
}
}
* V_487 = V_499 -> V_44 [ V_41 - 1 ] . V_456 ;
return 0 ;
}
static T_1 F_132 ( struct V_2 * V_3 ,
T_3 V_181 , T_3 V_500 )
{
T_3 V_41 ;
T_3 V_202 ;
T_3 V_86 = ( V_500 > V_501 ) ?
V_500 : V_501 ;
if ( V_181 < V_86 )
return 0 ;
for ( V_41 = V_502 ; ; V_41 -- ) {
V_202 = V_181 / ( 1 << V_41 ) ;
if ( V_202 >= V_86 || V_41 == 0 )
break;
}
return ( T_1 ) V_41 ;
}
static int F_133 ( struct V_2 * V_3 )
{
return F_134 ( V_3 , V_503 , V_498 ) ;
}
static int F_135 ( struct V_2 * V_3 )
{
return ( F_32 ( V_3 , V_504 ) == V_152 ) ?
0 : - V_45 ;
}
static int F_136 ( struct V_2 * V_3 )
{
T_3 V_202 ;
V_202 = ( F_24 ( V_505 ) & 0x0000ff00 ) >> 8 ;
if ( V_202 == V_503 )
return 0 ;
return F_134 ( V_3 , V_202 , V_503 ) ;
}
static void F_137 ( struct V_2 * V_3 ,
const T_3 V_506 ,
const T_3 V_507 ,
T_3 * V_508 )
{
bool V_509 ;
T_3 V_202 , V_510 ;
V_202 = F_25 ( V_511 ) ;
V_509 = ( ( V_202 & 0x0000f00 ) == 0x300 ) ? true : false ;
if ( V_509 &&
( ( V_3 -> V_13 -> V_14 == 0x67B0 ) ||
( V_3 -> V_13 -> V_14 == 0x67B1 ) ) ) {
if ( ( V_507 > 100000 ) && ( V_507 <= 125000 ) ) {
V_510 = ( ( ( 0x31 * V_506 ) / 125000 ) - 1 ) & 0xff ;
* V_508 &= ~ 0x00ff0000 ;
* V_508 |= V_510 << 16 ;
} else if ( ( V_507 > 125000 ) && ( V_507 <= 137500 ) ) {
V_510 = ( ( ( 0x36 * V_506 ) / 137500 ) - 1 ) & 0xff ;
* V_508 &= ~ 0x00ff0000 ;
* V_508 |= V_510 << 16 ;
}
}
}
static int F_138 ( struct V_2 * V_3 ,
T_3 V_181 ,
T_3 V_182 ,
T_11 * V_512 )
{
T_3 V_513 ;
T_3 V_514 ;
T_3 V_515 ;
F_139 ( V_3 , V_181 , V_182 ) ;
V_513 = F_25 ( V_516 ) ;
V_514 = F_25 ( V_517 ) ;
V_515 = F_25 ( V_518 ) & V_519 ;
F_137 ( V_3 , V_181 , V_182 , & V_514 ) ;
V_512 -> V_520 = F_17 ( V_513 ) ;
V_512 -> V_521 = F_17 ( V_514 ) ;
V_512 -> V_522 = ( T_1 ) V_515 ;
return 0 ;
}
static int F_140 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_12 V_512 ;
T_3 V_41 , V_102 ;
int V_74 = 0 ;
memset ( & V_512 , 0 , sizeof( T_12 ) ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_97 . V_523 . V_46 ; V_41 ++ ) {
for ( V_102 = 0 ; V_102 < V_4 -> V_97 . V_524 . V_46 ; V_102 ++ ) {
V_74 = F_138 ( V_3 ,
V_4 -> V_97 . V_523 . V_525 [ V_41 ] . V_57 ,
V_4 -> V_97 . V_524 . V_525 [ V_102 ] . V_57 ,
& V_512 . V_44 [ V_41 ] [ V_102 ] ) ;
if ( V_74 )
break;
}
}
if ( V_74 == 0 )
V_74 = F_19 ( V_3 ,
V_4 -> V_369 ,
( T_1 * ) & V_512 ,
sizeof( T_12 ) ,
V_4 -> V_80 ) ;
return V_74 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_315 == 0 )
return 0 ;
return F_140 ( V_3 ) ;
}
static void F_142 ( struct V_2 * V_3 ,
struct V_9 * V_526 )
{
struct V_8 * V_527 = F_2 ( V_526 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_528 = 0 ;
for ( V_528 = 0 ; V_528 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_528 ++ ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_528 ] . V_489 >=
V_527 -> V_197 [ 0 ] . V_181 ) {
V_4 -> V_98 . V_529 = V_528 ;
break;
}
}
for ( V_528 = 0 ; V_528 < V_3 -> V_5 . V_6 . V_42 . V_463 . V_46 ; V_528 ++ ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_463 . V_44 [ V_528 ] . V_489 >=
V_527 -> V_197 [ 0 ] . V_182 ) {
V_4 -> V_98 . V_530 = V_528 ;
break;
}
}
}
static T_3 F_143 ( struct V_531 * V_97 )
{
T_3 V_41 ;
T_3 V_532 = 0 ;
for ( V_41 = V_97 -> V_46 ; V_41 > 0 ; V_41 -- ) {
V_532 = V_532 << 1 ;
if ( V_97 -> V_525 [ V_41 - 1 ] . V_533 )
V_532 |= 0x1 ;
else
V_532 &= 0xFFFFFFFE ;
}
return V_532 ;
}
static void F_144 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_534 * V_97 = & V_4 -> V_97 ;
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_97 -> V_535 . V_46 ; V_41 ++ ) {
V_282 -> V_536 [ V_41 ] . V_537 =
( T_1 ) V_97 -> V_535 . V_525 [ V_41 ] . V_57 ;
V_282 -> V_536 [ V_41 ] . V_538 =
F_145 ( V_97 -> V_535 . V_525 [ V_41 ] . V_539 ) ;
V_282 -> V_536 [ V_41 ] . V_540 = 1 ;
V_282 -> V_536 [ V_41 ] . V_541 = F_17 ( 5 ) ;
V_282 -> V_536 [ V_41 ] . V_542 = F_17 ( 30 ) ;
}
V_4 -> V_98 . V_543 = ( T_1 ) V_97 -> V_535 . V_46 ;
V_4 -> V_544 . V_545 =
F_143 ( & V_97 -> V_535 ) ;
}
static int F_146 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
T_3 V_46 ;
struct V_546 V_547 ;
int V_74 = - V_45 ;
V_282 -> V_548 =
V_3 -> V_5 . V_6 . V_42 . V_549 . V_46 ;
for ( V_46 = 0 ; V_46 < V_282 -> V_548 ; V_46 ++ ) {
V_282 -> V_550 [ V_46 ] . V_551 =
V_3 -> V_5 . V_6 . V_42 . V_549 . V_44 [ V_46 ] . V_552 ;
V_282 -> V_550 [ V_46 ] . V_553 =
V_3 -> V_5 . V_6 . V_42 . V_549 . V_44 [ V_46 ] . V_554 ;
V_282 -> V_550 [ V_46 ] . V_555 =
V_3 -> V_5 . V_6 . V_42 . V_549 . V_44 [ V_46 ] . V_456 * V_33 ;
V_282 -> V_550 [ V_46 ] . V_556 = 1 ;
V_74 = F_147 ( V_3 ,
V_557 ,
V_282 -> V_550 [ V_46 ] . V_551 , false , & V_547 ) ;
if ( V_74 )
return V_74 ;
V_282 -> V_550 [ V_46 ] . V_558 = ( T_1 ) V_547 . V_559 ;
V_74 = F_147 ( V_3 ,
V_557 ,
V_282 -> V_550 [ V_46 ] . V_553 , false , & V_547 ) ;
if ( V_74 )
return V_74 ;
V_282 -> V_550 [ V_46 ] . V_560 = ( T_1 ) V_547 . V_559 ;
V_282 -> V_550 [ V_46 ] . V_551 = F_17 ( V_282 -> V_550 [ V_46 ] . V_551 ) ;
V_282 -> V_550 [ V_46 ] . V_553 = F_17 ( V_282 -> V_550 [ V_46 ] . V_553 ) ;
V_282 -> V_550 [ V_46 ] . V_555 = F_9 ( V_282 -> V_550 [ V_46 ] . V_555 ) ;
}
return V_74 ;
}
static int F_148 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
T_3 V_46 ;
struct V_546 V_547 ;
int V_74 = - V_45 ;
V_282 -> V_561 =
V_3 -> V_5 . V_6 . V_42 . V_562 . V_46 ;
for ( V_46 = 0 ; V_46 < V_282 -> V_561 ; V_46 ++ ) {
V_282 -> V_563 [ V_46 ] . V_564 =
V_3 -> V_5 . V_6 . V_42 . V_562 . V_44 [ V_46 ] . V_184 ;
V_282 -> V_563 [ V_46 ] . V_565 =
( T_2 ) V_3 -> V_5 . V_6 . V_42 . V_562 . V_44 [ V_46 ] . V_456 * V_33 ;
V_282 -> V_563 [ V_46 ] . V_566 = 1 ;
V_74 = F_147 ( V_3 ,
V_557 ,
V_282 -> V_563 [ V_46 ] . V_564 , false , & V_547 ) ;
if ( V_74 )
return V_74 ;
V_282 -> V_563 [ V_46 ] . V_567 = ( T_1 ) V_547 . V_559 ;
V_282 -> V_563 [ V_46 ] . V_564 = F_17 ( V_282 -> V_563 [ V_46 ] . V_564 ) ;
V_282 -> V_563 [ V_46 ] . V_565 = F_9 ( V_282 -> V_563 [ V_46 ] . V_565 ) ;
}
return V_74 ;
}
static int F_149 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
T_3 V_46 ;
struct V_546 V_547 ;
int V_74 = - V_45 ;
V_282 -> V_568 = ( T_1 )
( V_3 -> V_5 . V_6 . V_42 . V_569 . V_46 ) ;
for ( V_46 = 0 ; V_46 < V_282 -> V_568 ; V_46 ++ ) {
V_282 -> V_570 [ V_46 ] . V_564 =
V_3 -> V_5 . V_6 . V_42 . V_569 . V_44 [ V_46 ] . V_489 ;
V_282 -> V_570 [ V_46 ] . V_565 =
V_3 -> V_5 . V_6 . V_42 . V_569 . V_44 [ V_46 ] . V_456 ;
V_282 -> V_570 [ V_46 ] . V_566 = 1 ;
V_74 = F_147 ( V_3 ,
V_557 ,
V_282 -> V_570 [ V_46 ] . V_564 , false , & V_547 ) ;
if ( V_74 )
return V_74 ;
V_282 -> V_570 [ V_46 ] . V_567 = ( T_1 ) V_547 . V_559 ;
V_282 -> V_570 [ V_46 ] . V_564 = F_17 ( V_282 -> V_570 [ V_46 ] . V_564 ) ;
V_282 -> V_570 [ V_46 ] . V_565 = F_9 ( V_282 -> V_570 [ V_46 ] . V_565 ) ;
}
return V_74 ;
}
static int F_150 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
T_3 V_46 ;
struct V_546 V_547 ;
int V_74 = - V_45 ;
V_282 -> V_571 =
V_3 -> V_5 . V_6 . V_42 . V_572 . V_46 ;
for ( V_46 = 0 ; V_46 < V_282 -> V_571 ; V_46 ++ ) {
V_282 -> V_573 [ V_46 ] . V_564 =
V_3 -> V_5 . V_6 . V_42 . V_572 . V_44 [ V_46 ] . V_489 ;
V_282 -> V_573 [ V_46 ] . V_565 =
V_3 -> V_5 . V_6 . V_42 . V_572 . V_44 [ V_46 ] . V_456 * V_33 ;
V_282 -> V_573 [ V_46 ] . V_566 = 1 ;
V_74 = F_147 ( V_3 ,
V_557 ,
V_282 -> V_573 [ V_46 ] . V_564 , false , & V_547 ) ;
if ( V_74 )
return V_74 ;
V_282 -> V_573 [ V_46 ] . V_567 = ( T_1 ) V_547 . V_559 ;
V_282 -> V_573 [ V_46 ] . V_564 = F_17 ( V_282 -> V_573 [ V_46 ] . V_564 ) ;
V_282 -> V_573 [ V_46 ] . V_565 = F_9 ( V_282 -> V_573 [ V_46 ] . V_565 ) ;
}
return V_74 ;
}
static int F_151 ( struct V_2 * V_3 ,
T_3 V_507 ,
T_13 * V_182 ,
bool V_574 ,
bool V_575 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_383 = V_4 -> V_370 . V_383 ;
T_3 V_385 = V_4 -> V_370 . V_385 ;
T_3 V_387 = V_4 -> V_370 . V_387 ;
T_3 V_389 = V_4 -> V_370 . V_389 ;
T_3 V_391 = V_4 -> V_370 . V_391 ;
T_3 V_393 = V_4 -> V_370 . V_393 ;
T_3 V_395 = V_4 -> V_370 . V_395 ;
T_3 V_397 = V_4 -> V_370 . V_397 ;
T_3 V_399 = V_4 -> V_370 . V_399 ;
struct V_576 V_577 ;
int V_74 ;
V_74 = F_152 ( V_3 , V_507 , V_574 , & V_577 ) ;
if ( V_74 )
return V_74 ;
V_391 &= ~ V_578 ;
V_391 |= F_153 ( V_577 . V_579 ) ;
V_393 &= ~ ( V_580 | V_581 | V_582 ) ;
V_393 |= F_154 ( V_577 . V_583 ) |
F_155 ( V_577 . V_584 ) | F_156 ( V_577 . V_585 ) ;
V_387 &= ~ V_586 ;
V_387 |= F_157 ( V_577 . V_587 ) ;
if ( V_4 -> V_177 ) {
V_389 &= ~ ( V_588 | V_586 ) ;
V_389 |= F_158 ( V_577 . V_589 ) |
F_157 ( V_577 . V_587 ) ;
}
if ( V_4 -> V_590 ) {
struct V_591 V_592 ;
T_3 V_593 ;
T_3 V_202 ;
T_3 V_234 = V_3 -> clock . V_594 . V_413 ;
if ( V_577 . V_595 == 1 )
V_593 = V_507 * 4 * ( 1 << V_577 . V_587 ) ;
else
V_593 = V_507 * 2 * ( 1 << V_577 . V_587 ) ;
V_202 = ( V_593 / V_234 ) ;
V_202 = V_202 * V_202 ;
if ( F_159 ( V_3 , & V_592 ,
V_596 , V_593 ) ) {
T_3 V_597 = V_234 * 5 / V_592 . V_598 ;
T_3 V_599 = ( T_3 ) ( ( ( ( 131 * V_592 . V_600 * V_592 . V_598 ) / 100 ) * V_202 ) / V_593 ) ;
V_397 &= ~ V_601 ;
V_397 |= F_160 ( V_599 ) ;
V_399 &= ~ V_602 ;
V_399 |= F_161 ( V_597 ) ;
}
}
V_385 &= ~ V_603 ;
V_385 |= F_162 ( V_577 . V_604 ) ;
if ( V_575 )
V_385 |= V_605 | V_606 ;
else
V_385 &= ~ ( V_605 | V_606 ) ;
V_182 -> V_607 = V_507 ;
V_182 -> V_608 = V_391 ;
V_182 -> V_609 = V_393 ;
V_182 -> V_610 = V_395 ;
V_182 -> V_611 = V_387 ;
V_182 -> V_612 = V_389 ;
V_182 -> V_613 = V_385 ;
V_182 -> V_614 = V_383 ;
V_182 -> V_615 = V_397 ;
V_182 -> V_616 = V_399 ;
return 0 ;
}
static int F_163 ( struct V_2 * V_3 ,
T_3 V_507 ,
T_13 * V_617 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
bool V_575 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_463 . V_44 ) {
V_74 = F_131 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_463 ,
V_507 , & V_617 -> V_555 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_3 -> V_5 . V_6 . V_42 . V_468 . V_44 ) {
V_74 = F_131 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_468 ,
V_507 , & V_617 -> V_618 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_3 -> V_5 . V_6 . V_42 . V_473 . V_44 ) {
V_74 = F_131 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_473 ,
V_507 , & V_617 -> V_619 ) ;
if ( V_74 )
return V_74 ;
}
V_617 -> V_556 = 1 ;
if ( V_4 -> V_620 )
F_129 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_621 ,
V_507 ,
& V_617 -> V_556 ) ;
V_617 -> V_622 = 1 ;
V_617 -> V_623 = 0 ;
V_617 -> V_624 = 100 ;
V_617 -> V_625 = 0 ;
V_617 -> V_626 = ( T_2 ) V_4 -> V_627 ;
V_617 -> V_628 = false ;
V_617 -> V_629 = false ;
V_617 -> V_630 = false ;
V_617 -> V_631 = false ;
V_617 -> V_632 = false ;
V_617 -> V_633 = V_634 ;
if ( V_4 -> V_635 &&
( V_507 <= V_4 -> V_635 ) &&
( V_4 -> V_636 == false ) &&
( F_25 ( V_637 ) & V_638 ) &&
( V_3 -> V_5 . V_6 . V_188 <= 2 ) )
V_617 -> V_628 = true ;
if ( V_4 -> V_639 &&
( V_507 <= V_4 -> V_639 ) )
V_617 -> V_629 = 1 ;
if ( V_4 -> V_177 ) {
V_617 -> V_640 =
F_164 ( V_507 , V_617 -> V_629 ) ;
if ( V_4 -> V_641 &&
( V_507 > V_4 -> V_641 ) )
V_617 -> V_630 = true ;
if ( V_4 -> V_642 &&
( V_507 > V_4 -> V_642 ) )
V_617 -> V_631 = true ;
if ( V_617 -> V_629 ) {
if ( F_164 ( V_507 , true ) >=
( ( F_25 ( V_643 ) >> 16 ) & 0xf ) )
V_575 = ( ( F_25 ( V_644 ) >> 1 ) & 0x1 ) ? true : false ;
else
V_575 = ( ( F_25 ( V_645 ) >> 1 ) & 0x1 ) ? true : false ;
} else {
V_575 = V_4 -> V_646 ;
}
} else {
V_617 -> V_640 = F_165 ( V_507 ) ;
V_575 = ( ( F_25 ( V_644 ) >> 1 ) & 0x1 ) ? true : false ;
}
V_74 = F_151 ( V_3 , V_507 , V_617 , V_617 -> V_629 , V_575 ) ;
if ( V_74 )
return V_74 ;
V_617 -> V_555 = F_17 ( V_617 -> V_555 * V_33 ) ;
V_617 -> V_556 = F_17 ( V_617 -> V_556 ) ;
V_617 -> V_618 = F_17 ( V_617 -> V_618 * V_33 ) ;
V_617 -> V_619 = F_17 ( V_617 -> V_619 * V_33 ) ;
V_617 -> V_607 = F_17 ( V_617 -> V_607 ) ;
V_617 -> V_626 = F_9 ( V_617 -> V_626 ) ;
V_617 -> V_608 = F_17 ( V_617 -> V_608 ) ;
V_617 -> V_609 = F_17 ( V_617 -> V_609 ) ;
V_617 -> V_610 = F_17 ( V_617 -> V_610 ) ;
V_617 -> V_611 = F_17 ( V_617 -> V_611 ) ;
V_617 -> V_612 = F_17 ( V_617 -> V_612 ) ;
V_617 -> V_613 = F_17 ( V_617 -> V_613 ) ;
V_617 -> V_614 = F_17 ( V_617 -> V_614 ) ;
V_617 -> V_615 = F_17 ( V_617 -> V_615 ) ;
V_617 -> V_616 = F_17 ( V_617 -> V_616 ) ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 ,
T_4 * V_282 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_546 V_547 ;
T_10 V_647 ;
T_3 V_648 = V_4 -> V_370 . V_371 ;
T_3 V_649 = V_4 -> V_370 . V_373 ;
T_3 V_383 = V_4 -> V_370 . V_383 ;
T_3 V_385 = V_4 -> V_370 . V_385 ;
int V_74 ;
V_282 -> V_650 . V_651 &= ~ V_652 ;
if ( V_4 -> V_653 )
V_282 -> V_650 . V_555 = F_17 ( V_4 -> V_653 * V_33 ) ;
else
V_282 -> V_650 . V_555 = F_17 ( V_4 -> V_654 * V_33 ) ;
V_282 -> V_650 . V_556 = V_4 -> V_620 ? 0 : 1 ;
V_282 -> V_650 . V_655 = V_3 -> clock . V_412 . V_413 ;
V_74 = F_147 ( V_3 ,
V_656 ,
V_282 -> V_650 . V_655 , false , & V_547 ) ;
if ( V_74 )
return V_74 ;
V_282 -> V_650 . V_657 = ( T_1 ) V_547 . V_559 ;
V_282 -> V_650 . V_633 = V_634 ;
V_282 -> V_650 . V_658 = 0 ;
V_648 &= ~ V_659 ;
V_648 |= V_660 ;
V_649 &= ~ V_661 ;
V_649 |= F_167 ( 4 ) ;
V_282 -> V_650 . V_662 = V_648 ;
V_282 -> V_650 . V_663 = V_649 ;
V_282 -> V_650 . V_664 = V_4 -> V_370 . V_375 ;
V_282 -> V_650 . V_665 = V_4 -> V_370 . V_377 ;
V_282 -> V_650 . V_666 = V_4 -> V_370 . V_379 ;
V_282 -> V_650 . V_667 = V_4 -> V_370 . V_381 ;
V_282 -> V_650 . V_668 = 0 ;
V_282 -> V_650 . V_669 = 0 ;
V_282 -> V_650 . V_651 = F_17 ( V_282 -> V_650 . V_651 ) ;
V_282 -> V_650 . V_556 = F_17 ( V_282 -> V_650 . V_556 ) ;
V_282 -> V_650 . V_655 = F_17 ( V_282 -> V_650 . V_655 ) ;
V_282 -> V_650 . V_662 = F_17 ( V_282 -> V_650 . V_662 ) ;
V_282 -> V_650 . V_663 = F_17 ( V_282 -> V_650 . V_663 ) ;
V_282 -> V_650 . V_664 = F_17 ( V_282 -> V_650 . V_664 ) ;
V_282 -> V_650 . V_665 = F_17 ( V_282 -> V_650 . V_665 ) ;
V_282 -> V_650 . V_666 = F_17 ( V_282 -> V_650 . V_666 ) ;
V_282 -> V_650 . V_667 = F_17 ( V_282 -> V_650 . V_667 ) ;
V_282 -> V_650 . V_668 = F_17 ( V_282 -> V_650 . V_668 ) ;
V_282 -> V_650 . V_669 = F_17 ( V_282 -> V_650 . V_669 ) ;
V_282 -> V_670 . V_555 = V_282 -> V_650 . V_555 ;
V_282 -> V_670 . V_556 = V_282 -> V_650 . V_556 ;
if ( V_4 -> V_465 != V_488 ) {
if ( V_4 -> V_671 )
V_282 -> V_670 . V_618 =
F_17 ( V_4 -> V_671 * V_33 ) ;
else
V_282 -> V_670 . V_618 =
F_17 ( V_4 -> V_672 * V_33 ) ;
}
if ( F_127 ( V_3 , 0 , & V_647 ) )
V_282 -> V_670 . V_619 = 0 ;
else
V_282 -> V_670 . V_619 =
F_17 ( V_647 . V_479 * V_33 ) ;
V_385 |= V_673 | V_674 ;
V_385 &= ~ ( V_605 | V_606 ) ;
V_383 &= ~ ( V_675 | V_676 ) ;
V_282 -> V_670 . V_614 = F_17 ( V_383 ) ;
V_282 -> V_670 . V_613 = F_17 ( V_385 ) ;
V_282 -> V_670 . V_611 =
F_17 ( V_4 -> V_370 . V_387 ) ;
V_282 -> V_670 . V_612 =
F_17 ( V_4 -> V_370 . V_389 ) ;
V_282 -> V_670 . V_608 =
F_17 ( V_4 -> V_370 . V_391 ) ;
V_282 -> V_670 . V_609 =
F_17 ( V_4 -> V_370 . V_393 ) ;
V_282 -> V_670 . V_610 =
F_17 ( V_4 -> V_370 . V_395 ) ;
V_282 -> V_670 . V_615 = F_17 ( V_4 -> V_370 . V_397 ) ;
V_282 -> V_670 . V_616 = F_17 ( V_4 -> V_370 . V_399 ) ;
V_282 -> V_670 . V_622 = 0 ;
V_282 -> V_670 . V_540 = 0 ;
V_282 -> V_670 . V_623 = 0 ;
V_282 -> V_670 . V_624 = 100 ;
V_282 -> V_670 . V_625 = 0 ;
V_282 -> V_670 . V_626 =
F_9 ( ( T_2 ) V_4 -> V_627 ) ;
V_282 -> V_670 . V_628 = false ;
V_282 -> V_670 . V_629 = false ;
V_282 -> V_670 . V_630 = false ;
V_282 -> V_670 . V_631 = false ;
V_282 -> V_670 . V_632 = false ;
return 0 ;
}
static int F_168 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_677 * V_678 = & V_4 -> V_678 ;
if ( V_678 -> V_679 ) {
if ( V_131 )
return ( F_32 ( V_3 , V_680 ) == V_152 ) ?
0 : - V_45 ;
else
return ( F_32 ( V_3 , V_681 ) == V_152 ) ?
0 : - V_45 ;
}
return 0 ;
}
static int F_169 ( struct V_2 * V_3 ,
T_14 * V_682 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_683 = V_3 -> V_5 . V_6 . V_684 ;
V_682 -> V_668 = 0 ;
V_682 -> V_669 = 0 ;
if ( V_683 == 0 ) {
V_4 -> V_678 . V_679 = false ;
return 0 ;
}
if ( V_4 -> V_458 != V_462 ) {
if ( V_683 > V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_456 )
V_682 -> V_685 = 0 ;
else
V_682 -> V_685 =
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_456 - V_683 ;
} else {
if ( V_683 > V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_456 )
V_682 -> V_686 = 0 ;
else
V_682 -> V_686 = ( T_1 )
( ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_456 - V_683 ) *
V_687 / V_688 ) ;
}
V_682 -> V_689 = V_4 -> V_620 ? 0 : 1 ;
V_682 -> V_668 = F_17 ( V_682 -> V_668 ) ;
V_682 -> V_669 = F_17 ( V_682 -> V_669 ) ;
V_682 -> V_685 = F_9 ( V_682 -> V_685 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_3 ,
T_3 V_506 ,
T_15 * V_181 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_546 V_547 ;
T_3 V_690 = V_4 -> V_370 . V_375 ;
T_3 V_691 = V_4 -> V_370 . V_377 ;
T_3 V_379 = V_4 -> V_370 . V_379 ;
T_3 V_381 = V_4 -> V_370 . V_381 ;
T_3 V_234 = V_3 -> clock . V_412 . V_413 ;
T_3 V_692 ;
T_3 V_693 ;
int V_74 ;
V_74 = F_147 ( V_3 ,
V_656 ,
V_506 , false , & V_547 ) ;
if ( V_74 )
return V_74 ;
V_692 = 1 + V_547 . V_694 ;
V_693 = V_547 . V_695 & 0x3FFFFFF ;
V_690 &= ~ V_696 ;
V_690 |= F_171 ( V_693 ) ;
V_690 |= V_697 ;
if ( V_4 -> V_421 ) {
struct V_591 V_592 ;
T_3 V_698 = V_506 * V_547 . V_587 ;
if ( F_159 ( V_3 , & V_592 ,
V_699 , V_698 ) ) {
T_3 V_700 = V_234 * 5 / ( V_692 * V_592 . V_598 ) ;
T_3 V_701 = 4 * V_592 . V_600 * V_693 / ( V_700 * 10000 ) ;
V_379 &= ~ V_702 ;
V_379 |= F_172 ( V_700 ) ;
V_379 |= V_423 ;
V_381 &= ~ V_703 ;
V_381 |= F_173 ( V_701 ) ;
}
}
V_181 -> V_655 = V_506 ;
V_181 -> V_664 = V_690 ;
V_181 -> V_665 = V_691 ;
V_181 -> V_666 = V_379 ;
V_181 -> V_667 = V_381 ;
V_181 -> V_657 = ( T_1 ) V_547 . V_559 ;
return 0 ;
}
static int F_174 ( struct V_2 * V_3 ,
T_3 V_506 ,
T_2 V_704 ,
T_15 * V_705 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
V_74 = F_170 ( V_3 , V_506 , V_705 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_131 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_47 ,
V_506 , & V_705 -> V_555 ) ;
if ( V_74 )
return V_74 ;
V_705 -> V_655 = V_506 ;
V_705 -> V_651 = 0 ;
V_705 -> V_556 = 1 ;
if ( V_4 -> V_620 )
F_128 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_621 ,
V_506 ,
& V_705 -> V_556 ) ;
V_705 -> V_626 = V_704 ;
V_705 -> V_668 = 0 ;
V_705 -> V_669 = 0 ;
V_705 -> V_622 = 1 ;
V_705 -> V_623 = 0 ;
V_705 -> V_624 = 0 ;
V_705 -> V_625 = 0 ;
V_705 -> V_706 = 0 ;
if ( V_4 -> V_405 )
V_705 -> V_658 = F_132 ( V_3 ,
V_506 ,
V_501 ) ;
V_705 -> V_633 = V_634 ;
V_705 -> V_651 = F_17 ( V_705 -> V_651 ) ;
V_705 -> V_555 = F_17 ( V_705 -> V_555 * V_33 ) ;
V_705 -> V_556 = F_17 ( V_705 -> V_556 ) ;
V_705 -> V_655 = F_17 ( V_705 -> V_655 ) ;
V_705 -> V_626 = F_9 ( V_705 -> V_626 ) ;
V_705 -> V_664 = F_17 ( V_705 -> V_664 ) ;
V_705 -> V_665 = F_17 ( V_705 -> V_665 ) ;
V_705 -> V_666 = F_17 ( V_705 -> V_666 ) ;
V_705 -> V_667 = F_17 ( V_705 -> V_667 ) ;
V_705 -> V_668 = F_17 ( V_705 -> V_668 ) ;
V_705 -> V_669 = F_17 ( V_705 -> V_669 ) ;
return 0 ;
}
static int F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_534 * V_97 = & V_4 -> V_97 ;
T_3 V_707 = V_4 -> V_288 +
F_12 ( T_4 , V_708 ) ;
T_3 V_709 = sizeof( T_15 ) *
V_710 ;
T_15 * V_711 = V_4 -> V_98 . V_708 ;
T_3 V_41 , V_74 ;
memset ( V_711 , 0 , V_709 ) ;
for ( V_41 = 0 ; V_41 < V_97 -> V_523 . V_46 ; V_41 ++ ) {
V_74 = F_174 ( V_3 ,
V_97 -> V_523 . V_525 [ V_41 ] . V_57 ,
( T_2 ) V_4 -> V_712 [ V_41 ] ,
& V_4 -> V_98 . V_708 [ V_41 ] ) ;
if ( V_74 )
return V_74 ;
if ( V_41 > 1 )
V_4 -> V_98 . V_708 [ V_41 ] . V_658 = 0 ;
if ( V_41 == ( V_97 -> V_523 . V_46 - 1 ) )
V_4 -> V_98 . V_708 [ V_41 ] . V_633 =
V_713 ;
}
V_4 -> V_98 . V_708 [ 0 ] . V_540 = 1 ;
V_4 -> V_98 . V_714 = ( T_1 ) V_97 -> V_523 . V_46 ;
V_4 -> V_544 . V_715 =
F_143 ( & V_97 -> V_523 ) ;
V_74 = F_19 ( V_3 , V_707 ,
( T_1 * ) V_711 , V_709 ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 ,
T_14 * V_716 )
{
return F_169 ( V_3 , V_716 ) ;
}
static int F_177 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_534 * V_97 = & V_4 -> V_97 ;
T_3 V_707 = V_4 -> V_288 +
F_12 ( T_4 , V_717 ) ;
T_3 V_709 = sizeof( T_13 ) *
V_718 ;
T_13 * V_711 = V_4 -> V_98 . V_717 ;
T_3 V_41 , V_74 ;
memset ( V_711 , 0 , V_709 ) ;
for ( V_41 = 0 ; V_41 < V_97 -> V_524 . V_46 ; V_41 ++ ) {
if ( V_97 -> V_524 . V_525 [ V_41 ] . V_57 == 0 )
return - V_45 ;
V_74 = F_163 ( V_3 ,
V_97 -> V_524 . V_525 [ V_41 ] . V_57 ,
& V_4 -> V_98 . V_717 [ V_41 ] ) ;
if ( V_74 )
return V_74 ;
}
V_4 -> V_98 . V_717 [ 0 ] . V_540 = 1 ;
if ( ( V_97 -> V_524 . V_46 >= 2 ) &&
( ( V_3 -> V_13 -> V_14 == 0x67B0 ) || ( V_3 -> V_13 -> V_14 == 0x67B1 ) ) ) {
V_4 -> V_98 . V_717 [ 1 ] . V_555 =
V_4 -> V_98 . V_717 [ 0 ] . V_555 ;
V_4 -> V_98 . V_717 [ 1 ] . V_556 =
V_4 -> V_98 . V_717 [ 0 ] . V_556 ;
}
V_4 -> V_98 . V_717 [ 0 ] . V_626 = F_9 ( 0x1F ) ;
V_4 -> V_98 . V_719 = ( T_1 ) V_97 -> V_524 . V_46 ;
V_4 -> V_544 . V_720 =
F_143 ( & V_97 -> V_524 ) ;
V_4 -> V_98 . V_717 [ V_97 -> V_524 . V_46 - 1 ] . V_633 =
V_713 ;
V_74 = F_19 ( V_3 , V_707 ,
( T_1 * ) V_711 , V_709 ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static void F_178 ( struct V_2 * V_3 ,
struct V_531 * V_97 ,
T_3 V_46 )
{
T_3 V_41 ;
V_97 -> V_46 = V_46 ;
for ( V_41 = 0 ; V_41 < V_721 ; V_41 ++ )
V_97 -> V_525 [ V_41 ] . V_533 = false ;
}
static void F_179 ( struct V_531 * V_97 ,
T_3 V_722 , T_3 V_723 , T_3 V_724 )
{
V_97 -> V_525 [ V_722 ] . V_57 = V_723 ;
V_97 -> V_525 [ V_722 ] . V_539 = V_724 ;
V_97 -> V_525 [ V_722 ] . V_533 = true ;
}
static int F_180 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_725 && ! V_4 -> V_726 )
return - V_45 ;
if ( V_4 -> V_725 && ! V_4 -> V_726 ) {
V_4 -> V_727 = V_4 -> V_728 ;
V_4 -> V_729 = V_4 -> V_730 ;
} else if ( ! V_4 -> V_725 && V_4 -> V_726 ) {
V_4 -> V_728 = V_4 -> V_727 ;
V_4 -> V_730 = V_4 -> V_729 ;
}
F_178 ( V_3 ,
& V_4 -> V_97 . V_535 ,
V_731 ) ;
if ( V_3 -> V_27 == V_732 )
F_179 ( & V_4 -> V_97 . V_535 , 0 ,
V_4 -> V_727 . V_86 ,
V_4 -> V_729 . V_87 ) ;
else
F_179 ( & V_4 -> V_97 . V_535 , 0 ,
V_4 -> V_727 . V_86 ,
V_4 -> V_729 . V_86 ) ;
F_179 ( & V_4 -> V_97 . V_535 , 1 ,
V_4 -> V_728 . V_86 ,
V_4 -> V_730 . V_86 ) ;
F_179 ( & V_4 -> V_97 . V_535 , 2 ,
V_4 -> V_727 . V_86 ,
V_4 -> V_729 . V_87 ) ;
F_179 ( & V_4 -> V_97 . V_535 , 3 ,
V_4 -> V_728 . V_86 ,
V_4 -> V_730 . V_87 ) ;
F_179 ( & V_4 -> V_97 . V_535 , 4 ,
V_4 -> V_727 . V_87 ,
V_4 -> V_729 . V_87 ) ;
F_179 ( & V_4 -> V_97 . V_535 , 5 ,
V_4 -> V_728 . V_87 ,
V_4 -> V_730 . V_87 ) ;
V_4 -> V_97 . V_535 . V_46 = 6 ;
return 0 ;
}
static int F_181 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_450 * V_733 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
struct V_450 * V_734 =
& V_3 -> V_5 . V_6 . V_42 . V_463 ;
struct V_735 * V_736 =
& V_3 -> V_5 . V_6 . V_42 . V_43 ;
T_3 V_41 ;
if ( V_733 == NULL )
return - V_45 ;
if ( V_733 -> V_46 < 1 )
return - V_45 ;
if ( V_734 == NULL )
return - V_45 ;
if ( V_734 -> V_46 < 1 )
return - V_45 ;
memset ( & V_4 -> V_97 , 0 , sizeof( struct V_534 ) ) ;
F_178 ( V_3 ,
& V_4 -> V_97 . V_523 ,
V_710 ) ;
F_178 ( V_3 ,
& V_4 -> V_97 . V_524 ,
V_718 ) ;
F_178 ( V_3 ,
& V_4 -> V_97 . V_737 ,
V_464 ) ;
F_178 ( V_3 ,
& V_4 -> V_97 . V_738 ,
V_469 ) ;
F_178 ( V_3 ,
& V_4 -> V_97 . V_739 ,
V_474 ) ;
V_4 -> V_97 . V_523 . V_46 = 0 ;
for ( V_41 = 0 ; V_41 < V_733 -> V_46 ; V_41 ++ ) {
if ( ( V_41 == 0 ) ||
( V_4 -> V_97 . V_523 . V_525 [ V_4 -> V_97 . V_523 . V_46 - 1 ] . V_57 !=
V_733 -> V_44 [ V_41 ] . V_489 ) ) {
V_4 -> V_97 . V_523 . V_525 [ V_4 -> V_97 . V_523 . V_46 ] . V_57 =
V_733 -> V_44 [ V_41 ] . V_489 ;
V_4 -> V_97 . V_523 . V_525 [ V_4 -> V_97 . V_523 . V_46 ] . V_533 =
( V_41 == 0 ) ? true : false ;
V_4 -> V_97 . V_523 . V_46 ++ ;
}
}
V_4 -> V_97 . V_524 . V_46 = 0 ;
for ( V_41 = 0 ; V_41 < V_734 -> V_46 ; V_41 ++ ) {
if ( ( V_41 == 0 ) ||
( V_4 -> V_97 . V_524 . V_525 [ V_4 -> V_97 . V_524 . V_46 - 1 ] . V_57 !=
V_734 -> V_44 [ V_41 ] . V_489 ) ) {
V_4 -> V_97 . V_524 . V_525 [ V_4 -> V_97 . V_524 . V_46 ] . V_57 =
V_734 -> V_44 [ V_41 ] . V_489 ;
V_4 -> V_97 . V_524 . V_525 [ V_4 -> V_97 . V_524 . V_46 ] . V_533 =
( V_41 == 0 ) ? true : false ;
V_4 -> V_97 . V_524 . V_46 ++ ;
}
}
for ( V_41 = 0 ; V_41 < V_733 -> V_46 ; V_41 ++ ) {
V_4 -> V_97 . V_737 . V_525 [ V_41 ] . V_57 =
V_733 -> V_44 [ V_41 ] . V_456 ;
V_4 -> V_97 . V_737 . V_525 [ V_41 ] . V_539 =
V_736 -> V_44 [ V_41 ] . V_53 ;
V_4 -> V_97 . V_737 . V_525 [ V_41 ] . V_533 = true ;
}
V_4 -> V_97 . V_737 . V_46 = V_733 -> V_46 ;
V_734 = & V_3 -> V_5 . V_6 . V_42 . V_468 ;
if ( V_734 ) {
for ( V_41 = 0 ; V_41 < V_734 -> V_46 ; V_41 ++ ) {
V_4 -> V_97 . V_738 . V_525 [ V_41 ] . V_57 =
V_734 -> V_44 [ V_41 ] . V_456 ;
V_4 -> V_97 . V_738 . V_525 [ V_41 ] . V_533 = true ;
}
V_4 -> V_97 . V_738 . V_46 = V_734 -> V_46 ;
}
V_734 = & V_3 -> V_5 . V_6 . V_42 . V_473 ;
if ( V_734 ) {
for ( V_41 = 0 ; V_41 < V_734 -> V_46 ; V_41 ++ ) {
V_4 -> V_97 . V_739 . V_525 [ V_41 ] . V_57 =
V_734 -> V_44 [ V_41 ] . V_456 ;
V_4 -> V_97 . V_739 . V_525 [ V_41 ] . V_533 = true ;
}
V_4 -> V_97 . V_739 . V_46 = V_734 -> V_46 ;
}
F_180 ( V_3 ) ;
return 0 ;
}
static int F_182 ( struct V_531 * V_282 ,
T_3 V_57 , T_3 * V_740 )
{
T_3 V_41 ;
int V_74 = - V_45 ;
for( V_41 = 0 ; V_41 < V_282 -> V_46 ; V_41 ++ ) {
if ( V_57 == V_282 -> V_525 [ V_41 ] . V_57 ) {
* V_740 = V_41 ;
V_74 = 0 ;
}
}
return V_74 ;
}
static int F_183 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_677 * V_678 = & V_4 -> V_678 ;
struct V_9 * V_526 = V_3 -> V_5 . V_6 . V_741 ;
T_4 * V_282 = & V_4 -> V_98 ;
int V_74 ;
V_74 = F_181 ( V_3 ) ;
if ( V_74 )
return V_74 ;
if ( V_4 -> V_458 != V_488 )
F_126 ( V_3 , V_282 ) ;
F_66 ( V_3 ) ;
if ( V_3 -> V_5 . V_6 . V_48 & V_742 )
V_282 -> V_743 |= V_744 ;
if ( V_3 -> V_5 . V_6 . V_48 & V_745 )
V_282 -> V_743 |= V_746 ;
if ( V_4 -> V_177 )
V_282 -> V_743 |= V_747 ;
if ( V_678 -> V_679 ) {
V_74 = F_176 ( V_3 , & V_4 -> V_98 . V_748 ) ;
if ( V_74 )
return V_74 ;
F_26 ( V_749 , V_678 -> V_750 ) ;
}
V_74 = F_175 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_177 ( V_3 ) ;
if ( V_74 )
return V_74 ;
F_144 ( V_3 , V_282 ) ;
V_74 = F_166 ( V_3 , V_282 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_148 ( V_3 , V_282 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_149 ( V_3 , V_282 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_150 ( V_3 , V_282 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_140 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_146 ( V_3 , V_282 ) ;
if ( V_74 )
return V_74 ;
V_282 -> V_751 = 0 ;
V_282 -> V_752 = 0 ;
V_282 -> V_753 = 0 ;
V_282 -> V_754 = 0 ;
V_282 -> V_529 = 0 ;
V_282 -> V_530 = 0 ;
V_74 = F_182 ( & V_4 -> V_97 . V_523 ,
V_4 -> V_755 . V_756 ,
( T_3 * ) & V_4 -> V_98 . V_529 ) ;
V_74 = F_182 ( & V_4 -> V_97 . V_524 ,
V_4 -> V_755 . V_757 ,
( T_3 * ) & V_4 -> V_98 . V_530 ) ;
V_282 -> V_758 = V_4 -> V_755 . V_759 ;
V_282 -> V_760 = V_4 -> V_755 . V_761 ;
V_282 -> V_762 = V_4 -> V_755 . V_763 ;
F_142 ( V_3 , V_526 ) ;
V_74 = F_16 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_282 -> V_764 = 1 ;
V_282 -> V_765 = 1 ;
V_282 -> V_766 = 1 ;
V_282 -> V_767 = 1 ;
V_282 -> V_768 = 1 ;
V_282 -> V_769 = 1 ;
V_282 -> V_770 = 1 ;
V_282 -> V_771 = 1 ;
V_282 -> V_772 = 1 ;
V_282 -> V_773 = ( T_2 ) ( ( V_4 -> V_112 . V_113 *
V_774 ) / 1000 ) ;
V_282 -> V_775 = ( T_2 ) ( ( V_4 -> V_112 . V_776 *
V_774 ) / 1000 ) ;
V_282 -> V_777 = 1 ;
V_282 -> V_778 = 1 ;
V_282 -> V_779 = 0 ;
V_282 -> V_780 = 4000 ;
V_282 -> V_781 = 0 ;
V_282 -> V_782 = 1 ;
V_282 -> V_783 = V_4 -> V_97 . V_535 . V_46 - 1 ;
V_282 -> V_784 = 1 ;
if ( V_4 -> V_458 == V_462 )
V_282 -> V_785 = 1 ;
else
V_282 -> V_785 = 0 ;
V_282 -> V_786 = 17 ;
V_282 -> V_787 = 0x4000 ;
V_282 -> V_743 = F_17 ( V_282 -> V_743 ) ;
V_282 -> V_788 = F_17 ( V_282 -> V_788 ) ;
V_282 -> V_789 = F_17 ( V_282 -> V_789 ) ;
V_282 -> V_790 = F_17 ( V_282 -> V_790 ) ;
V_282 -> V_791 = F_17 ( V_282 -> V_791 ) ;
V_282 -> V_787 = F_17 ( V_282 -> V_787 ) ;
V_282 -> V_773 = F_9 ( V_282 -> V_773 ) ;
V_282 -> V_775 = F_9 ( V_282 -> V_775 ) ;
V_282 -> V_780 = F_9 ( V_282 -> V_780 ) ;
V_282 -> V_779 = F_9 ( V_282 -> V_779 ) ;
V_282 -> V_781 = F_9 ( V_282 -> V_781 ) ;
V_282 -> V_758 = F_9 ( V_282 -> V_758 * V_33 ) ;
V_282 -> V_760 = F_9 ( V_282 -> V_760 * V_33 ) ;
V_282 -> V_762 = F_9 ( V_282 -> V_762 * V_33 ) ;
V_74 = F_19 ( V_3 ,
V_4 -> V_288 +
F_12 ( T_4 , V_743 ) ,
( T_1 * ) & V_282 -> V_743 ,
sizeof( T_4 ) - 3 * sizeof( V_792 ) ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static void F_184 ( struct V_2 * V_3 ,
struct V_531 * V_97 ,
T_3 V_793 , T_3 V_794 )
{
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_97 -> V_46 ; V_41 ++ ) {
if ( ( V_97 -> V_525 [ V_41 ] . V_57 < V_793 ) ||
( V_97 -> V_525 [ V_41 ] . V_57 > V_794 ) )
V_97 -> V_525 [ V_41 ] . V_533 = false ;
else
V_97 -> V_525 [ V_41 ] . V_533 = true ;
}
}
static void F_185 ( struct V_2 * V_3 ,
T_3 V_795 , T_3 V_796 ,
T_3 V_797 , T_3 V_798 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_531 * V_799 = & V_4 -> V_97 . V_535 ;
T_3 V_41 , V_102 ;
for ( V_41 = 0 ; V_41 < V_799 -> V_46 ; V_41 ++ ) {
if ( ( V_799 -> V_525 [ V_41 ] . V_57 < V_795 ) ||
( V_799 -> V_525 [ V_41 ] . V_539 < V_796 ) ||
( V_799 -> V_525 [ V_41 ] . V_57 > V_797 ) ||
( V_799 -> V_525 [ V_41 ] . V_539 > V_798 ) )
V_799 -> V_525 [ V_41 ] . V_533 = false ;
else
V_799 -> V_525 [ V_41 ] . V_533 = true ;
}
for ( V_41 = 0 ; V_41 < V_799 -> V_46 ; V_41 ++ ) {
if ( V_799 -> V_525 [ V_41 ] . V_533 ) {
for ( V_102 = V_41 + 1 ; V_102 < V_799 -> V_46 ; V_102 ++ ) {
if ( V_799 -> V_525 [ V_102 ] . V_533 ) {
if ( ( V_799 -> V_525 [ V_41 ] . V_57 == V_799 -> V_525 [ V_102 ] . V_57 ) &&
( V_799 -> V_525 [ V_41 ] . V_539 == V_799 -> V_525 [ V_102 ] . V_539 ) )
V_799 -> V_525 [ V_102 ] . V_533 = false ;
}
}
}
}
}
static int F_186 ( struct V_2 * V_3 ,
struct V_9 * V_800 )
{
struct V_8 * V_682 = F_2 ( V_800 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_801 ;
if ( V_682 -> V_196 < 1 )
return - V_45 ;
if ( V_682 -> V_196 == 1 )
V_801 = 0 ;
else
V_801 = 1 ;
F_184 ( V_3 ,
& V_4 -> V_97 . V_523 ,
V_682 -> V_197 [ 0 ] . V_181 ,
V_682 -> V_197 [ V_801 ] . V_181 ) ;
F_184 ( V_3 ,
& V_4 -> V_97 . V_524 ,
V_682 -> V_197 [ 0 ] . V_182 ,
V_682 -> V_197 [ V_801 ] . V_182 ) ;
F_185 ( V_3 ,
V_682 -> V_197 [ 0 ] . V_723 ,
V_682 -> V_197 [ 0 ] . V_802 ,
V_682 -> V_197 [ V_801 ] . V_723 ,
V_682 -> V_197 [ V_801 ] . V_802 ) ;
return 0 ;
}
static int F_187 ( struct V_2 * V_3 )
{
struct V_450 * V_803 =
& V_3 -> V_5 . V_6 . V_42 . V_804 ;
struct V_450 * V_737 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
T_3 V_805 = 0 ;
T_3 V_41 ;
if ( V_803 == NULL )
return - V_45 ;
if ( ! V_803 -> V_46 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_803 -> V_46 ; V_41 ++ ) {
if ( V_3 -> clock . V_806 == V_803 -> V_44 [ V_41 ] . V_489 )
V_805 = V_803 -> V_44 [ V_41 ] . V_456 ;
}
for ( V_41 = 0 ; V_41 < V_737 -> V_46 ; V_41 ++ ) {
if ( V_805 <= V_737 -> V_44 [ V_41 ] . V_456 ) {
V_805 = V_737 -> V_44 [ V_41 ] . V_456 ;
return ( F_56 ( V_3 ,
V_807 ,
V_805 * V_33 ) == V_152 ) ?
0 : - V_45 ;
}
}
return - V_45 ;
}
static int F_188 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_208 ;
F_187 ( V_3 ) ;
if ( ! V_4 -> V_316 ) {
if ( V_4 -> V_544 . V_715 ) {
V_208 = F_56 ( V_3 ,
V_351 ,
V_4 -> V_544 . V_715 ) ;
if ( V_208 != V_152 )
return - V_45 ;
}
}
if ( ! V_4 -> V_320 ) {
if ( V_4 -> V_544 . V_720 ) {
V_208 = F_56 ( V_3 ,
V_352 ,
V_4 -> V_544 . V_720 ) ;
if ( V_208 != V_152 )
return - V_45 ;
}
}
#if 0
if (!pi->pcie_dpm_key_disabled) {
if (pi->dpm_level_enable_mask.pcie_dpm_enable_mask) {
result = ci_send_msg_to_smc_with_parameter(rdev,
PPSMC_MSG_PCIeDPM_SetEnabledMask,
pi->dpm_level_enable_mask.pcie_dpm_enable_mask);
if (result != PPSMC_Result_OK)
return -EINVAL;
}
}
#endif
return 0 ;
}
static void F_189 ( struct V_2 * V_3 ,
struct V_9 * V_800 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_682 = F_2 ( V_800 ) ;
struct V_531 * V_523 = & V_4 -> V_97 . V_523 ;
T_3 V_181 = V_682 -> V_197 [ V_682 -> V_196 - 1 ] . V_181 ;
struct V_531 * V_524 = & V_4 -> V_97 . V_524 ;
T_3 V_182 = V_682 -> V_197 [ V_682 -> V_196 - 1 ] . V_182 ;
T_3 V_41 ;
V_4 -> V_315 = 0 ;
for ( V_41 = 0 ; V_41 < V_523 -> V_46 ; V_41 ++ ) {
if ( V_181 == V_523 -> V_525 [ V_41 ] . V_57 )
break;
}
if ( V_41 >= V_523 -> V_46 ) {
V_4 -> V_315 |= V_317 ;
} else {
if ( V_501 != V_501 )
V_4 -> V_315 |= V_318 ;
}
for ( V_41 = 0 ; V_41 < V_524 -> V_46 ; V_41 ++ ) {
if ( V_182 == V_524 -> V_525 [ V_41 ] . V_57 )
break;
}
if ( V_41 >= V_524 -> V_46 )
V_4 -> V_315 |= V_321 ;
if ( V_3 -> V_5 . V_6 . V_808 !=
V_3 -> V_5 . V_6 . V_188 )
V_4 -> V_315 |= V_809 ;
}
static int F_190 ( struct V_2 * V_3 ,
struct V_9 * V_800 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_682 = F_2 ( V_800 ) ;
T_3 V_181 = V_682 -> V_197 [ V_682 -> V_196 - 1 ] . V_181 ;
T_3 V_182 = V_682 -> V_197 [ V_682 -> V_196 - 1 ] . V_182 ;
struct V_534 * V_97 = & V_4 -> V_97 ;
int V_74 ;
if ( ! V_4 -> V_315 )
return 0 ;
if ( V_4 -> V_315 & V_317 )
V_97 -> V_523 . V_525 [ V_97 -> V_523 . V_46 - 1 ] . V_57 = V_181 ;
if ( V_4 -> V_315 & V_321 )
V_97 -> V_524 . V_525 [ V_97 -> V_524 . V_46 - 1 ] . V_57 = V_182 ;
if ( V_4 -> V_315 & ( V_317 | V_318 ) ) {
V_74 = F_175 ( V_3 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_315 & ( V_321 | V_809 ) ) {
V_74 = F_177 ( V_3 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static int F_191 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_178 * V_179 ;
int V_41 ;
if ( V_3 -> V_5 . V_6 . V_193 )
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_194 ;
else
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_195 ;
if ( V_131 ) {
V_4 -> V_544 . V_810 = 0 ;
for ( V_41 = V_3 -> V_5 . V_6 . V_42 . V_549 . V_46 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_549 . V_44 [ V_41 ] . V_456 <= V_179 -> V_32 ) {
V_4 -> V_544 . V_810 |= 1 << V_41 ;
if ( ! V_4 -> V_811 )
break;
}
}
F_56 ( V_3 ,
V_812 ,
V_4 -> V_544 . V_810 ) ;
if ( V_4 -> V_813 & 0x1 ) {
V_4 -> V_636 = true ;
V_4 -> V_544 . V_720 &= 0xFFFFFFFE ;
F_56 ( V_3 ,
V_352 ,
V_4 -> V_544 . V_720 ) ;
}
} else {
if ( V_4 -> V_813 & 0x1 ) {
V_4 -> V_636 = false ;
V_4 -> V_544 . V_720 |= 1 ;
F_56 ( V_3 ,
V_352 ,
V_4 -> V_544 . V_720 ) ;
}
}
return ( F_32 ( V_3 , V_131 ?
V_814 : V_815 ) == V_152 ) ?
0 : - V_45 ;
}
static int F_192 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_178 * V_179 ;
int V_41 ;
if ( V_3 -> V_5 . V_6 . V_193 )
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_194 ;
else
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_195 ;
if ( V_131 ) {
V_4 -> V_544 . V_816 = 0 ;
for ( V_41 = V_3 -> V_5 . V_6 . V_42 . V_562 . V_46 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_562 . V_44 [ V_41 ] . V_456 <= V_179 -> V_32 ) {
V_4 -> V_544 . V_816 |= 1 << V_41 ;
if ( ! V_4 -> V_817 )
break;
}
}
F_56 ( V_3 ,
V_818 ,
V_4 -> V_544 . V_816 ) ;
}
return ( F_32 ( V_3 , V_131 ?
V_819 : V_820 ) == V_152 ) ?
0 : - V_45 ;
}
static int F_39 ( struct V_2 * V_3 , bool V_173 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
if ( ! V_173 ) {
if ( V_4 -> V_811 ||
( V_3 -> V_5 . V_6 . V_42 . V_549 . V_46 <= 0 ) )
V_4 -> V_98 . V_751 = 0 ;
else
V_4 -> V_98 . V_751 =
V_3 -> V_5 . V_6 . V_42 . V_549 . V_46 - 1 ;
V_202 = F_24 ( V_821 ) ;
V_202 &= ~ V_822 ;
V_202 |= V_751 ( V_4 -> V_98 . V_751 ) ;
F_26 ( V_821 , V_202 ) ;
}
return F_191 ( V_3 , ! V_173 ) ;
}
static T_1 F_193 ( struct V_2 * V_3 )
{
T_1 V_41 ;
T_3 V_823 = 30000 ;
struct V_824 * V_282 =
& V_3 -> V_5 . V_6 . V_42 . V_562 ;
for ( V_41 = 0 ; V_41 < V_282 -> V_46 ; V_41 ++ ) {
if ( V_282 -> V_44 [ V_41 ] . V_184 >= V_823 )
return V_41 ;
}
return V_282 -> V_46 - 1 ;
}
static int F_194 ( struct V_2 * V_3 ,
struct V_9 * V_825 ,
struct V_9 * V_826 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 = 0 ;
T_3 V_202 ;
if ( V_826 -> V_184 != V_825 -> V_184 ) {
if ( V_825 -> V_184 ) {
F_195 ( V_3 , V_827 , false ) ;
V_4 -> V_98 . V_752 = F_193 ( V_3 ) ;
V_202 = F_24 ( V_821 ) ;
V_202 &= ~ V_828 ;
V_202 |= V_752 ( V_4 -> V_98 . V_752 ) ;
F_26 ( V_821 , V_202 ) ;
V_74 = F_192 ( V_3 , true ) ;
} else {
F_195 ( V_3 , V_827 , true ) ;
V_74 = F_192 ( V_3 , false ) ;
}
}
return V_74 ;
}
static int F_196 ( struct V_2 * V_3 ,
struct V_9 * V_800 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
V_74 = F_186 ( V_3 , V_800 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_544 . V_715 =
F_143 ( & V_4 -> V_97 . V_523 ) ;
V_4 -> V_544 . V_720 =
F_143 ( & V_4 -> V_97 . V_524 ) ;
V_4 -> V_813 =
V_4 -> V_544 . V_720 ;
if ( V_4 -> V_636 ) {
if ( V_4 -> V_544 . V_720 & 1 )
V_4 -> V_544 . V_720 &= 0xFFFFFFFE ;
}
V_4 -> V_544 . V_545 =
F_143 ( & V_4 -> V_97 . V_535 ) ;
return 0 ;
}
static T_3 F_197 ( struct V_2 * V_3 ,
T_3 V_829 )
{
T_3 V_528 = 0 ;
while ( ( V_829 & ( 1 << V_528 ) ) == 0 )
V_528 ++ ;
return V_528 ;
}
int F_198 ( struct V_2 * V_3 ,
enum V_830 V_528 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 , V_711 , V_41 ;
int V_74 ;
if ( V_528 == V_831 ) {
if ( ( ! V_4 -> V_340 ) &&
V_4 -> V_544 . V_545 ) {
V_711 = 0 ;
V_202 = V_4 -> V_544 . V_545 ;
while ( V_202 >>= 1 )
V_711 ++ ;
if ( V_711 ) {
V_74 = F_86 ( V_3 , V_528 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_360 ; V_41 ++ ) {
V_202 = ( F_24 ( V_832 ) &
V_833 ) >> V_834 ;
if ( V_202 == V_711 )
break;
F_78 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_316 ) &&
V_4 -> V_544 . V_715 ) {
V_711 = 0 ;
V_202 = V_4 -> V_544 . V_715 ;
while ( V_202 >>= 1 )
V_711 ++ ;
if ( V_711 ) {
V_74 = F_84 ( V_3 , V_711 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_360 ; V_41 ++ ) {
V_202 = ( F_24 ( V_835 ) &
V_836 ) >> V_837 ;
if ( V_202 == V_711 )
break;
F_78 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_320 ) &&
V_4 -> V_544 . V_720 ) {
V_711 = 0 ;
V_202 = V_4 -> V_544 . V_720 ;
while ( V_202 >>= 1 )
V_711 ++ ;
if ( V_711 ) {
V_74 = F_85 ( V_3 , V_711 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_360 ; V_41 ++ ) {
V_202 = ( F_24 ( V_835 ) &
V_838 ) >> V_839 ;
if ( V_202 == V_711 )
break;
F_78 ( 1 ) ;
}
}
}
} else if ( V_528 == V_840 ) {
if ( ( ! V_4 -> V_316 ) &&
V_4 -> V_544 . V_715 ) {
V_711 = F_197 ( V_3 ,
V_4 -> V_544 . V_715 ) ;
V_74 = F_84 ( V_3 , V_711 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_360 ; V_41 ++ ) {
V_202 = ( F_24 ( V_835 ) &
V_836 ) >> V_837 ;
if ( V_202 == V_711 )
break;
F_78 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_320 ) &&
V_4 -> V_544 . V_720 ) {
V_711 = F_197 ( V_3 ,
V_4 -> V_544 . V_720 ) ;
V_74 = F_85 ( V_3 , V_711 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_360 ; V_41 ++ ) {
V_202 = ( F_24 ( V_835 ) &
V_838 ) >> V_839 ;
if ( V_202 == V_711 )
break;
F_78 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_340 ) &&
V_4 -> V_544 . V_545 ) {
V_711 = F_197 ( V_3 ,
V_4 -> V_544 . V_545 ) ;
V_74 = F_86 ( V_3 , V_711 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_360 ; V_41 ++ ) {
V_202 = ( F_24 ( V_832 ) &
V_833 ) >> V_834 ;
if ( V_202 == V_711 )
break;
F_78 ( 1 ) ;
}
}
} else if ( V_528 == V_841 ) {
if ( ! V_4 -> V_340 ) {
T_5 V_149 ;
V_149 = F_32 ( V_3 ,
V_842 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
V_74 = F_188 ( V_3 ) ;
if ( V_74 )
return V_74 ;
}
V_3 -> V_5 . V_6 . V_843 = V_528 ;
return 0 ;
}
static int F_199 ( struct V_2 * V_3 ,
struct V_844 * V_282 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_41 , V_102 , V_103 ;
T_3 V_845 ;
for ( V_41 = 0 , V_102 = V_282 -> V_846 ; V_41 < V_282 -> V_846 ; V_41 ++ ) {
if ( V_102 >= V_847 )
return - V_45 ;
switch( V_282 -> V_848 [ V_41 ] . V_849 << 2 ) {
case V_850 :
V_845 = F_25 ( V_851 ) ;
V_282 -> V_848 [ V_102 ] . V_849 = V_851 >> 2 ;
V_282 -> V_848 [ V_102 ] . V_852 = V_853 >> 2 ;
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
V_282 -> V_855 [ V_103 ] . V_856 [ V_102 ] =
( ( V_845 & 0xffff0000 ) ) | ( ( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xffff0000 ) >> 16 ) ;
}
V_102 ++ ;
if ( V_102 >= V_847 )
return - V_45 ;
V_845 = F_25 ( V_857 ) ;
V_282 -> V_848 [ V_102 ] . V_849 = V_857 >> 2 ;
V_282 -> V_848 [ V_102 ] . V_852 = V_858 >> 2 ;
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
V_282 -> V_855 [ V_103 ] . V_856 [ V_102 ] =
( V_845 & 0xffff0000 ) | ( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0x0000ffff ) ;
if ( ! V_4 -> V_177 )
V_282 -> V_855 [ V_103 ] . V_856 [ V_102 ] |= 0x100 ;
}
V_102 ++ ;
if ( V_102 > V_847 )
return - V_45 ;
if ( ! V_4 -> V_177 ) {
V_282 -> V_848 [ V_102 ] . V_849 = V_859 >> 2 ;
V_282 -> V_848 [ V_102 ] . V_852 = V_859 >> 2 ;
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
V_282 -> V_855 [ V_103 ] . V_856 [ V_102 ] =
( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xffff0000 ) >> 16 ;
}
V_102 ++ ;
if ( V_102 > V_847 )
return - V_45 ;
}
break;
case V_860 :
V_845 = F_25 ( V_861 ) ;
V_282 -> V_848 [ V_102 ] . V_849 = V_861 >> 2 ;
V_282 -> V_848 [ V_102 ] . V_852 = V_862 >> 2 ;
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
V_282 -> V_855 [ V_103 ] . V_856 [ V_102 ] =
( V_845 & 0xffff0000 ) | ( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0x0000ffff ) ;
}
V_102 ++ ;
if ( V_102 > V_847 )
return - V_45 ;
break;
default:
break;
}
}
V_282 -> V_846 = V_102 ;
return 0 ;
}
static bool F_200 ( T_2 V_863 , T_2 * V_864 )
{
bool V_208 = true ;
switch( V_863 ) {
case V_865 >> 2 :
* V_864 = V_866 >> 2 ;
break;
case V_867 >> 2 :
* V_864 = V_868 >> 2 ;
break;
case V_869 >> 2 :
* V_864 = V_870 >> 2 ;
break;
case V_871 >> 2 :
* V_864 = V_872 >> 2 ;
break;
case V_873 >> 2 :
* V_864 = V_874 >> 2 ;
break;
case V_875 >> 2 :
* V_864 = V_876 >> 2 ;
break;
case V_877 >> 2 :
* V_864 = V_878 >> 2 ;
break;
case V_879 >> 2 :
* V_864 = V_880 >> 2 ;
break;
case V_881 >> 2 :
* V_864 = V_882 >> 2 ;
break;
case V_883 >> 2 :
* V_864 = V_884 >> 2 ;
break;
case V_885 >> 2 :
* V_864 = V_886 >> 2 ;
break;
case V_887 >> 2 :
* V_864 = V_888 >> 2 ;
break;
case V_889 >> 2 :
* V_864 = V_890 >> 2 ;
break;
case V_891 >> 2 :
* V_864 = V_892 >> 2 ;
break;
case V_851 >> 2 :
* V_864 = V_853 >> 2 ;
break;
case V_857 >> 2 :
* V_864 = V_858 >> 2 ;
break;
case V_861 >> 2 :
* V_864 = V_862 >> 2 ;
break;
case V_893 >> 2 :
* V_864 = V_894 >> 2 ;
break;
case V_895 >> 2 :
* V_864 = V_896 >> 2 ;
break;
case V_897 >> 2 :
* V_864 = V_898 >> 2 ;
break;
default:
V_208 = false ;
break;
}
return V_208 ;
}
static void F_201 ( struct V_844 * V_282 )
{
T_1 V_41 , V_102 ;
for ( V_41 = 0 ; V_41 < V_282 -> V_846 ; V_41 ++ ) {
for ( V_102 = 1 ; V_102 < V_282 -> V_854 ; V_102 ++ ) {
if ( V_282 -> V_855 [ V_102 - 1 ] . V_856 [ V_41 ] !=
V_282 -> V_855 [ V_102 ] . V_856 [ V_41 ] ) {
V_282 -> V_899 |= 1 << V_41 ;
break;
}
}
}
}
static void F_202 ( struct V_844 * V_282 )
{
T_3 V_41 ;
T_2 V_900 ;
for ( V_41 = 0 ; V_41 < V_282 -> V_846 ; V_41 ++ ) {
V_282 -> V_848 [ V_41 ] . V_852 =
F_200 ( V_282 -> V_848 [ V_41 ] . V_849 , & V_900 ) ?
V_900 : V_282 -> V_848 [ V_41 ] . V_849 ;
}
}
static int F_203 ( const struct V_901 * V_282 ,
struct V_844 * V_902 )
{
T_1 V_41 , V_102 ;
if ( V_282 -> V_846 > V_847 )
return - V_45 ;
if ( V_282 -> V_854 > V_903 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_282 -> V_846 ; V_41 ++ )
V_902 -> V_848 [ V_41 ] . V_849 = V_282 -> V_848 [ V_41 ] . V_849 ;
V_902 -> V_846 = V_282 -> V_846 ;
for ( V_41 = 0 ; V_41 < V_282 -> V_854 ; V_41 ++ ) {
V_902 -> V_855 [ V_41 ] . V_904 =
V_282 -> V_855 [ V_41 ] . V_904 ;
for ( V_102 = 0 ; V_102 < V_282 -> V_846 ; V_102 ++ )
V_902 -> V_855 [ V_41 ] . V_856 [ V_102 ] =
V_282 -> V_855 [ V_41 ] . V_856 [ V_102 ] ;
}
V_902 -> V_854 = V_282 -> V_854 ;
return 0 ;
}
static int F_204 ( struct V_2 * V_3 ,
struct V_844 * V_282 )
{
T_1 V_41 , V_103 ;
T_3 V_202 ;
bool V_509 ;
V_202 = F_25 ( V_511 ) ;
V_509 = ( ( V_202 & 0x0000f00 ) == 0x300 ) ? true : false ;
if ( V_509 &&
( ( V_3 -> V_13 -> V_14 == 0x67B0 ) ||
( V_3 -> V_13 -> V_14 == 0x67B1 ) ) ) {
for ( V_41 = 0 ; V_41 < V_282 -> V_846 ; V_41 ++ ) {
if ( V_282 -> V_846 >= V_847 )
return - V_45 ;
switch( V_282 -> V_848 [ V_41 ] . V_849 >> 2 ) {
case V_850 :
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
if ( ( V_282 -> V_855 [ V_103 ] . V_904 == 125000 ) ||
( V_282 -> V_855 [ V_103 ] . V_904 == 137500 ) )
V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] =
( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xFFFFFFF8 ) |
0x00000007 ;
}
break;
case V_889 :
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
if ( ( V_282 -> V_855 [ V_103 ] . V_904 == 125000 ) ||
( V_282 -> V_855 [ V_103 ] . V_904 == 137500 ) )
V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] =
( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xFFFF0F00 ) |
0x0000D0DD ;
}
break;
case V_891 :
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
if ( ( V_282 -> V_855 [ V_103 ] . V_904 == 125000 ) ||
( V_282 -> V_855 [ V_103 ] . V_904 == 137500 ) )
V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] =
( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xFFFF0F00 ) |
0x0000D0DD ;
}
break;
case V_897 :
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
if ( ( V_282 -> V_855 [ V_103 ] . V_904 == 125000 ) ||
( V_282 -> V_855 [ V_103 ] . V_904 == 137500 ) )
V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] = 0 ;
}
break;
case V_875 :
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
if ( V_282 -> V_855 [ V_103 ] . V_904 == 125000 )
V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] =
( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xFFE0FE0F ) |
0x000C0140 ;
else if ( V_282 -> V_855 [ V_103 ] . V_904 == 137500 )
V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] =
( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xFFE0FE0F ) |
0x000C0150 ;
}
break;
case V_877 :
for ( V_103 = 0 ; V_103 < V_282 -> V_854 ; V_103 ++ ) {
if ( V_282 -> V_855 [ V_103 ] . V_904 == 125000 )
V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] =
( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xFFFFFFE0 ) |
0x00000030 ;
else if ( V_282 -> V_855 [ V_103 ] . V_904 == 137500 )
V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] =
( V_282 -> V_855 [ V_103 ] . V_856 [ V_41 ] & 0xFFFFFFE0 ) |
0x00000035 ;
}
break;
default:
break;
}
}
F_27 ( V_905 , 3 ) ;
V_202 = F_25 ( V_906 ) ;
V_202 = ( V_202 & 0xFFF8FFFF ) | ( 1 << 16 ) ;
F_27 ( V_905 , 3 ) ;
F_27 ( V_906 , V_202 ) ;
}
return 0 ;
}
static int F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_901 * V_282 ;
struct V_844 * V_902 = & V_4 -> V_907 ;
T_1 V_908 = F_206 ( V_3 ) ;
int V_74 ;
V_282 = F_207 ( sizeof( struct V_901 ) , V_909 ) ;
if ( ! V_282 )
return - V_910 ;
F_27 ( V_866 , F_25 ( V_865 ) ) ;
F_27 ( V_876 , F_25 ( V_875 ) ) ;
F_27 ( V_868 , F_25 ( V_867 ) ) ;
F_27 ( V_870 , F_25 ( V_869 ) ) ;
F_27 ( V_872 , F_25 ( V_871 ) ) ;
F_27 ( V_874 , F_25 ( V_873 ) ) ;
F_27 ( V_882 , F_25 ( V_881 ) ) ;
F_27 ( V_884 , F_25 ( V_883 ) ) ;
F_27 ( V_878 , F_25 ( V_877 ) ) ;
F_27 ( V_880 , F_25 ( V_879 ) ) ;
F_27 ( V_853 , F_25 ( V_851 ) ) ;
F_27 ( V_858 , F_25 ( V_857 ) ) ;
F_27 ( V_862 , F_25 ( V_861 ) ) ;
F_27 ( V_890 , F_25 ( V_889 ) ) ;
F_27 ( V_892 , F_25 ( V_891 ) ) ;
F_27 ( V_886 , F_25 ( V_885 ) ) ;
F_27 ( V_888 , F_25 ( V_887 ) ) ;
F_27 ( V_894 , F_25 ( V_893 ) ) ;
F_27 ( V_896 , F_25 ( V_895 ) ) ;
F_27 ( V_898 , F_25 ( V_897 ) ) ;
V_74 = F_208 ( V_3 , V_908 , V_282 ) ;
if ( V_74 )
goto V_911;
V_74 = F_203 ( V_282 , V_902 ) ;
if ( V_74 )
goto V_911;
F_202 ( V_902 ) ;
V_74 = F_204 ( V_3 , V_902 ) ;
if ( V_74 )
goto V_911;
V_74 = F_199 ( V_3 , V_902 ) ;
if ( V_74 )
goto V_911;
F_201 ( V_902 ) ;
V_911:
F_209 ( V_282 ) ;
return V_74 ;
}
static int F_210 ( struct V_2 * V_3 ,
T_16 * V_907 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 , V_102 ;
for ( V_41 = 0 , V_102 = 0 ; V_102 < V_4 -> V_907 . V_846 ; V_102 ++ ) {
if ( V_4 -> V_907 . V_899 & ( 1 << V_102 ) ) {
if ( V_41 >= V_847 )
return - V_45 ;
V_907 -> V_900 [ V_41 ] . V_852 = F_9 ( V_4 -> V_907 . V_848 [ V_102 ] . V_852 ) ;
V_907 -> V_900 [ V_41 ] . V_849 = F_9 ( V_4 -> V_907 . V_848 [ V_102 ] . V_849 ) ;
V_41 ++ ;
}
}
V_907 -> V_846 = ( T_1 ) V_41 ;
return 0 ;
}
static void F_211 ( const struct V_912 * V_913 ,
T_17 * V_132 ,
T_3 V_854 , T_3 V_899 )
{
T_3 V_41 , V_102 ;
for ( V_41 = 0 , V_102 = 0 ; V_102 < V_854 ; V_102 ++ ) {
if ( V_899 & ( 1 << V_102 ) ) {
V_132 -> V_57 [ V_41 ] = F_17 ( V_913 -> V_856 [ V_102 ] ) ;
V_41 ++ ;
}
}
}
static void F_212 ( struct V_2 * V_3 ,
const T_3 V_507 ,
T_17 * V_914 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 = 0 ;
for( V_41 = 0 ; V_41 < V_4 -> V_907 . V_854 ; V_41 ++ ) {
if ( V_507 <= V_4 -> V_907 . V_855 [ V_41 ] . V_904 )
break;
}
if ( ( V_41 == V_4 -> V_907 . V_854 ) && ( V_41 > 0 ) )
-- V_41 ;
F_211 ( & V_4 -> V_907 . V_855 [ V_41 ] ,
V_914 , V_4 -> V_907 . V_846 ,
V_4 -> V_907 . V_899 ) ;
}
static void F_213 ( struct V_2 * V_3 ,
T_16 * V_907 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_97 . V_524 . V_46 ; V_41 ++ )
F_212 ( V_3 ,
V_4 -> V_97 . V_524 . V_525 [ V_41 ] . V_57 ,
& V_907 -> V_132 [ V_41 ] ) ;
}
static int F_214 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
memset ( & V_4 -> V_915 , 0 , sizeof( T_16 ) ) ;
V_74 = F_210 ( V_3 , & V_4 -> V_915 ) ;
if ( V_74 )
return V_74 ;
F_213 ( V_3 , & V_4 -> V_915 ) ;
return F_19 ( V_3 ,
V_4 -> V_366 ,
( T_1 * ) & V_4 -> V_915 ,
sizeof( T_16 ) ,
V_4 -> V_80 ) ;
}
static int F_215 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! ( V_4 -> V_315 & V_321 ) )
return 0 ;
memset ( & V_4 -> V_915 , 0 , sizeof( T_16 ) ) ;
F_213 ( V_3 , & V_4 -> V_915 ) ;
return F_19 ( V_3 ,
V_4 -> V_366 +
F_12 ( T_16 , V_132 [ 0 ] ) ,
( T_1 * ) & V_4 -> V_915 . V_132 [ 0 ] ,
sizeof( T_17 ) *
V_4 -> V_97 . V_524 . V_46 ,
V_4 -> V_80 ) ;
}
static void F_216 ( struct V_2 * V_3 )
{
T_3 V_202 = F_24 ( V_307 ) ;
V_202 |= V_916 ;
F_26 ( V_307 , V_202 ) ;
}
static enum V_917 F_217 ( struct V_2 * V_3 ,
struct V_9 * V_800 )
{
struct V_8 * V_682 = F_2 ( V_800 ) ;
int V_41 ;
T_2 V_918 , V_919 = 0 ;
for ( V_41 = 0 ; V_41 < V_682 -> V_196 ; V_41 ++ ) {
V_918 = V_682 -> V_197 [ V_41 ] . V_723 ;
if ( V_919 < V_918 )
V_919 = V_918 ;
}
return V_919 ;
}
static T_2 F_218 ( struct V_2 * V_3 )
{
T_3 V_920 = 0 ;
V_920 = F_219 ( V_921 ) & V_922 ;
V_920 >>= V_923 ;
return ( T_2 ) V_920 ;
}
static int F_220 ( struct V_2 * V_3 )
{
T_3 V_924 = 0 ;
V_924 = F_219 ( V_925 ) & V_926 ;
V_924 >>= V_927 ;
switch ( V_924 ) {
case V_928 :
return 1 ;
case V_929 :
return 2 ;
case V_930 :
return 4 ;
case V_931 :
return 8 ;
case V_932 :
return 12 ;
case V_933 :
case V_934 :
default:
return 16 ;
}
}
static void F_221 ( struct V_2 * V_3 ,
struct V_9 * V_825 ,
struct V_9 * V_826 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_917 V_935 =
F_217 ( V_3 , V_825 ) ;
enum V_917 V_936 ;
if ( V_4 -> V_937 == V_938 )
V_936 = F_217 ( V_3 , V_826 ) ;
else
V_936 = V_4 -> V_937 ;
V_4 -> V_937 = V_938 ;
V_4 -> V_939 = false ;
if ( V_935 > V_936 ) {
switch ( V_935 ) {
#ifdef F_222
case V_940 :
if ( F_223 ( V_3 , V_941 , false ) == 0 )
break;
V_4 -> V_937 = V_942 ;
if ( V_936 == V_942 )
break;
case V_942 :
if ( F_223 ( V_3 , V_943 , false ) == 0 )
break;
#endif
default:
V_4 -> V_937 = F_218 ( V_3 ) ;
break;
}
} else {
if ( V_935 < V_936 )
V_4 -> V_939 = true ;
}
}
static void F_224 ( struct V_2 * V_3 ,
struct V_9 * V_825 ,
struct V_9 * V_826 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_917 V_935 =
F_217 ( V_3 , V_825 ) ;
T_1 V_944 ;
if ( V_4 -> V_939 ) {
if ( V_935 == V_940 )
V_944 = V_941 ;
else if ( V_935 == V_942 )
V_944 = V_943 ;
else
V_944 = V_945 ;
if ( ( V_944 == V_945 ) &&
( F_218 ( V_3 ) > 0 ) )
return;
#ifdef F_222
F_223 ( V_3 , V_944 , false ) ;
#endif
}
}
static int F_225 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_450 * V_733 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
struct V_450 * V_946 =
& V_3 -> V_5 . V_6 . V_42 . V_463 ;
struct V_450 * V_947 =
& V_3 -> V_5 . V_6 . V_42 . V_468 ;
if ( V_733 == NULL )
return - V_45 ;
if ( V_733 -> V_46 < 1 )
return - V_45 ;
if ( V_946 == NULL )
return - V_45 ;
if ( V_946 -> V_46 < 1 )
return - V_45 ;
if ( V_947 == NULL )
return - V_45 ;
if ( V_947 -> V_46 < 1 )
return - V_45 ;
V_4 -> V_654 = V_733 -> V_44 [ 0 ] . V_456 ;
V_4 -> V_948 =
V_733 -> V_44 [ V_733 -> V_46 - 1 ] . V_456 ;
V_4 -> V_672 = V_947 -> V_44 [ 0 ] . V_456 ;
V_4 -> V_949 =
V_947 -> V_44 [ V_947 -> V_46 - 1 ] . V_456 ;
V_3 -> V_5 . V_6 . V_42 . V_194 . V_181 =
V_733 -> V_44 [ V_733 -> V_46 - 1 ] . V_489 ;
V_3 -> V_5 . V_6 . V_42 . V_194 . V_182 =
V_946 -> V_44 [ V_733 -> V_46 - 1 ] . V_489 ;
V_3 -> V_5 . V_6 . V_42 . V_194 . V_32 =
V_733 -> V_44 [ V_733 -> V_46 - 1 ] . V_456 ;
V_3 -> V_5 . V_6 . V_42 . V_194 . V_292 =
V_947 -> V_44 [ V_947 -> V_46 - 1 ] . V_456 ;
return 0 ;
}
static void F_226 ( struct V_2 * V_3 , T_2 * V_32 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_950 * V_951 = & V_4 -> V_293 ;
T_3 V_952 ;
for ( V_952 = 0 ; V_952 < V_951 -> V_46 ; V_952 ++ ) {
if ( V_951 -> V_290 [ V_952 ] == * V_32 ) {
* V_32 = V_951 -> V_297 [ V_952 ] ;
break;
}
}
}
static void F_227 ( struct V_2 * V_3 , T_2 * V_292 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_950 * V_951 = & V_4 -> V_294 ;
T_3 V_952 ;
for ( V_952 = 0 ; V_952 < V_951 -> V_46 ; V_952 ++ ) {
if ( V_951 -> V_290 [ V_952 ] == * V_292 ) {
* V_292 = V_951 -> V_297 [ V_952 ] ;
break;
}
}
}
static void F_228 ( struct V_2 * V_3 ,
struct V_450 * V_282 )
{
T_3 V_41 ;
if ( V_282 ) {
for ( V_41 = 0 ; V_41 < V_282 -> V_46 ; V_41 ++ )
F_226 ( V_3 , & V_282 -> V_44 [ V_41 ] . V_456 ) ;
}
}
static void F_229 ( struct V_2 * V_3 ,
struct V_450 * V_282 )
{
T_3 V_41 ;
if ( V_282 ) {
for ( V_41 = 0 ; V_41 < V_282 -> V_46 ; V_41 ++ )
F_227 ( V_3 , & V_282 -> V_44 [ V_41 ] . V_456 ) ;
}
}
static void F_230 ( struct V_2 * V_3 ,
struct V_824 * V_282 )
{
T_3 V_41 ;
if ( V_282 ) {
for ( V_41 = 0 ; V_41 < V_282 -> V_46 ; V_41 ++ )
F_226 ( V_3 , & V_282 -> V_44 [ V_41 ] . V_456 ) ;
}
}
static void F_231 ( struct V_2 * V_3 ,
struct V_953 * V_282 )
{
T_3 V_41 ;
if ( V_282 ) {
for ( V_41 = 0 ; V_41 < V_282 -> V_46 ; V_41 ++ )
F_226 ( V_3 , & V_282 -> V_44 [ V_41 ] . V_456 ) ;
}
}
static void F_232 ( struct V_2 * V_3 ,
struct V_495 * V_282 )
{
T_3 V_41 ;
if ( V_282 ) {
for ( V_41 = 0 ; V_41 < V_282 -> V_46 ; V_41 ++ )
F_226 ( V_3 , & V_282 -> V_44 [ V_41 ] . V_487 ) ;
}
}
static void F_233 ( struct V_2 * V_3 ,
struct V_178 * V_282 )
{
if ( V_282 ) {
F_226 ( V_3 , ( T_2 * ) & V_282 -> V_32 ) ;
F_227 ( V_3 , ( T_2 * ) & V_282 -> V_292 ) ;
}
}
static void F_234 ( struct V_2 * V_3 ,
struct V_735 * V_282 )
{
T_3 V_41 ;
if ( V_282 ) {
for ( V_41 = 0 ; V_41 < V_282 -> V_46 ; V_41 ++ )
F_226 ( V_3 , & V_282 -> V_44 [ V_41 ] . V_32 ) ;
}
}
static void F_235 ( struct V_2 * V_3 )
{
F_228 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_47 ) ;
F_228 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_463 ) ;
F_228 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_804 ) ;
F_229 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_468 ) ;
F_230 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_562 ) ;
F_231 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_549 ) ;
F_228 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_572 ) ;
F_228 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_569 ) ;
F_232 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_621 ) ;
F_233 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_194 ) ;
F_233 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_195 ) ;
F_234 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_43 ) ;
}
static void F_236 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
V_202 = F_25 ( V_511 ) ;
if ( ( ( V_202 & V_954 ) >> V_955 ) ==
V_956 )
V_4 -> V_177 = true ;
else
V_4 -> V_177 = false ;
}
static void F_237 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_957 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_958 = * V_10 ;
V_4 -> V_959 = * V_957 ;
V_4 -> V_958 . V_12 = & V_4 -> V_959 ;
}
static void F_238 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_957 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_960 = * V_10 ;
V_4 -> V_961 = * V_957 ;
V_4 -> V_960 . V_12 = & V_4 -> V_961 ;
}
int F_239 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 V_961 = * V_3 -> V_5 . V_6 . V_961 ;
struct V_9 * V_957 = & V_961 ;
F_238 ( V_3 , V_957 ) ;
F_42 ( V_3 , & V_4 -> V_960 ) ;
return 0 ;
}
void F_240 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_957 = & V_4 -> V_960 ;
F_237 ( V_3 , V_957 ) ;
}
void F_241 ( struct V_2 * V_3 )
{
int V_962 ;
V_962 = F_242 ( V_3 ) ;
if ( V_962 )
F_44 ( L_5 ) ;
F_98 ( V_3 ) ;
F_236 ( V_3 ) ;
F_101 ( V_3 ) ;
F_99 ( V_3 ) ;
}
int F_243 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_741 = V_3 -> V_5 . V_6 . V_741 ;
int V_74 ;
if ( F_244 ( V_3 ) )
return - V_45 ;
if ( V_4 -> V_458 != V_488 ) {
F_216 ( V_3 ) ;
V_74 = F_118 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_6 ) ;
return V_74 ;
}
}
if ( V_4 -> V_963 ) {
V_74 = F_205 ( V_3 ) ;
if ( V_74 )
V_4 -> V_963 = false ;
}
if ( V_4 -> V_964 )
F_107 ( V_3 , true ) ;
if ( V_4 -> V_308 )
F_100 ( V_3 , true ) ;
F_108 ( V_3 ) ;
F_111 ( V_3 ) ;
F_113 ( V_3 ) ;
V_74 = F_115 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_7 ) ;
return V_74 ;
}
V_74 = F_97 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_8 ) ;
return V_74 ;
}
V_74 = F_133 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_9 ) ;
return V_74 ;
}
V_74 = F_183 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_10 ) ;
return V_74 ;
}
V_74 = F_130 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_11 ) ;
return V_74 ;
}
if ( V_4 -> V_963 ) {
V_74 = F_214 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_12 ) ;
return V_74 ;
}
}
V_74 = F_18 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_13 ) ;
return V_74 ;
}
F_90 ( V_3 ) ;
F_74 ( V_3 ) ;
V_74 = F_102 ( V_3 , false ) ;
if ( V_74 ) {
F_44 ( L_14 ) ;
return V_74 ;
}
F_82 ( V_3 , true ) ;
V_74 = F_168 ( V_3 , true ) ;
if ( V_74 ) {
F_44 ( L_15 ) ;
return V_74 ;
}
V_74 = F_103 ( V_3 , true ) ;
if ( V_74 ) {
F_44 ( L_16 ) ;
return V_74 ;
}
V_74 = F_79 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_17 ) ;
return V_74 ;
}
V_74 = F_28 ( V_3 , true ) ;
if ( V_74 ) {
F_44 ( L_18 ) ;
return V_74 ;
}
V_74 = F_34 ( V_3 , true ) ;
if ( V_74 ) {
F_44 ( L_19 ) ;
return V_74 ;
}
V_74 = F_31 ( V_3 , true ) ;
if ( V_74 ) {
F_44 ( L_20 ) ;
return V_74 ;
}
V_74 = F_36 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_21 ) ;
return V_74 ;
}
F_73 ( V_3 , V_302 , true ) ;
V_74 = F_35 ( V_3 , true ) ;
if ( V_74 ) {
F_44 ( L_22 ) ;
return V_74 ;
}
F_62 ( V_3 ) ;
F_237 ( V_3 , V_741 ) ;
return 0 ;
}
static int F_245 ( struct V_2 * V_3 )
{
int V_74 ;
V_74 = F_47 ( V_3 , false ) ;
if ( V_74 )
return V_74 ;
V_74 = F_43 ( V_3 , V_277 , V_278 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_47 ( V_3 , true ) ;
if ( V_74 )
return V_74 ;
return V_74 ;
}
int F_246 ( struct V_2 * V_3 )
{
int V_74 ;
V_74 = F_245 ( V_3 ) ;
if ( V_74 )
return V_74 ;
F_38 ( V_3 , true ) ;
return 0 ;
}
void F_247 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_741 = V_3 -> V_5 . V_6 . V_741 ;
F_38 ( V_3 , false ) ;
if ( ! F_244 ( V_3 ) )
return;
F_63 ( V_3 ) ;
if ( V_4 -> V_308 )
F_100 ( V_3 , false ) ;
F_31 ( V_3 , false ) ;
F_34 ( V_3 , false ) ;
F_28 ( V_3 , false ) ;
F_107 ( V_3 , false ) ;
F_73 ( V_3 , V_302 , false ) ;
F_81 ( V_3 ) ;
F_103 ( V_3 , false ) ;
F_168 ( V_3 , false ) ;
F_114 ( V_3 ) ;
F_135 ( V_3 ) ;
F_94 ( V_3 ) ;
F_136 ( V_3 ) ;
F_35 ( V_3 , false ) ;
F_237 ( V_3 , V_741 ) ;
}
int F_248 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_957 = & V_4 -> V_960 ;
struct V_9 * V_965 = & V_4 -> V_958 ;
int V_74 ;
F_189 ( V_3 , V_957 ) ;
if ( V_4 -> V_966 )
F_221 ( V_3 , V_957 , V_965 ) ;
V_74 = F_80 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_23 ) ;
return V_74 ;
}
V_74 = F_190 ( V_3 , V_957 ) ;
if ( V_74 ) {
F_44 ( L_24 ) ;
return V_74 ;
}
V_74 = F_196 ( V_3 , V_957 ) ;
if ( V_74 ) {
F_44 ( L_25 ) ;
return V_74 ;
}
V_74 = F_194 ( V_3 , V_957 , V_965 ) ;
if ( V_74 ) {
F_44 ( L_26 ) ;
return V_74 ;
}
V_74 = F_67 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_27 ) ;
return V_74 ;
}
if ( V_4 -> V_963 ) {
V_74 = F_215 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_28 ) ;
return V_74 ;
}
}
V_74 = F_141 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_29 ) ;
return V_74 ;
}
V_74 = F_75 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_30 ) ;
return V_74 ;
}
V_74 = F_188 ( V_3 ) ;
if ( V_74 ) {
F_44 ( L_31 ) ;
return V_74 ;
}
if ( V_4 -> V_966 )
F_224 ( V_3 , V_957 , V_965 ) ;
return 0 ;
}
void F_249 ( struct V_2 * V_3 )
{
F_87 ( V_3 ) ;
}
void F_250 ( struct V_2 * V_3 )
{
F_104 ( V_3 ) ;
}
static void F_251 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_967 * V_968 ,
T_1 V_969 )
{
V_10 -> V_970 = F_252 ( V_968 -> V_971 ) ;
V_10 -> V_189 = F_253 ( V_968 -> V_972 ) ;
V_10 -> V_973 = F_253 ( V_968 -> V_974 ) ;
if ( V_975 < V_969 ) {
V_10 -> V_552 = F_252 ( V_968 -> V_976 ) ;
V_10 -> V_554 = F_252 ( V_968 -> V_977 ) ;
} else {
V_10 -> V_552 = 0 ;
V_10 -> V_554 = 0 ;
}
if ( V_10 -> V_189 & V_978 )
V_3 -> V_5 . V_6 . V_741 = V_10 ;
if ( V_10 -> V_189 & V_979 )
V_3 -> V_5 . V_6 . V_980 = V_10 ;
}
static void F_254 ( struct V_2 * V_3 ,
struct V_9 * V_10 , int V_722 ,
union V_981 * V_982 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_983 * V_984 = & V_11 -> V_197 [ V_722 ] ;
V_11 -> V_196 = V_722 + 1 ;
V_984 -> V_181 = F_253 ( V_982 -> V_985 . V_986 ) ;
V_984 -> V_181 |= V_982 -> V_985 . V_987 << 16 ;
V_984 -> V_182 = F_253 ( V_982 -> V_985 . V_988 ) ;
V_984 -> V_182 |= V_982 -> V_985 . V_989 << 16 ;
V_984 -> V_723 = F_255 ( V_3 ,
V_4 -> V_990 ,
V_4 -> V_755 . V_991 ,
V_982 -> V_985 . V_992 ) ;
V_984 -> V_802 = F_256 ( V_3 ,
V_4 -> V_755 . V_993 ,
F_253 ( V_982 -> V_985 . V_994 ) ) ;
if ( V_10 -> V_189 & V_995 ) {
V_4 -> V_996 = V_984 -> V_723 ;
}
if ( V_10 -> V_973 & V_997 ) {
V_4 -> V_678 . V_679 = true ;
V_4 -> V_678 . V_984 = * V_984 ;
V_4 -> V_678 . V_750 = V_998 ;
}
if ( V_10 -> V_189 & V_978 ) {
V_984 -> V_182 = V_4 -> V_755 . V_757 ;
V_984 -> V_181 = V_4 -> V_755 . V_756 ;
V_984 -> V_723 = V_4 -> V_755 . V_991 ;
V_984 -> V_802 = V_4 -> V_755 . V_993 ;
}
switch ( V_10 -> V_189 & V_190 ) {
case V_191 :
V_4 -> V_726 = true ;
if ( V_4 -> V_727 . V_87 < V_984 -> V_723 )
V_4 -> V_727 . V_87 = V_984 -> V_723 ;
if ( V_4 -> V_727 . V_86 > V_984 -> V_723 )
V_4 -> V_727 . V_86 = V_984 -> V_723 ;
if ( V_4 -> V_729 . V_87 < V_984 -> V_802 )
V_4 -> V_729 . V_87 = V_984 -> V_802 ;
if ( V_4 -> V_729 . V_86 > V_984 -> V_802 )
V_4 -> V_729 . V_86 = V_984 -> V_802 ;
break;
case V_999 :
V_4 -> V_725 = true ;
if ( V_4 -> V_728 . V_87 < V_984 -> V_723 )
V_4 -> V_728 . V_87 = V_984 -> V_723 ;
if ( V_4 -> V_728 . V_86 > V_984 -> V_723 )
V_4 -> V_728 . V_86 = V_984 -> V_723 ;
if ( V_4 -> V_730 . V_87 < V_984 -> V_802 )
V_4 -> V_730 . V_87 = V_984 -> V_802 ;
if ( V_4 -> V_730 . V_86 > V_984 -> V_802 )
V_4 -> V_730 . V_86 = V_984 -> V_802 ;
break;
default:
break;
}
}
static int F_257 ( struct V_2 * V_3 )
{
struct V_1000 * V_1001 = & V_3 -> V_1001 ;
struct V_967 * V_968 ;
union V_1002 * V_1003 ;
int V_41 , V_102 , V_103 , V_1004 , V_1005 ;
union V_981 * V_982 ;
struct V_1006 * V_1007 ;
struct V_1008 * V_1009 ;
struct V_1010 * V_1011 ;
union V_1012 * V_1012 ;
int V_722 = F_258 ( V_1013 , V_1014 ) ;
T_2 V_1015 ;
T_1 V_1016 , V_1017 ;
T_1 * V_1018 ;
struct V_8 * V_11 ;
if ( ! F_259 ( V_1001 -> V_1019 , V_722 , NULL ,
& V_1016 , & V_1017 , & V_1015 ) )
return - V_45 ;
V_1012 = (union V_1012 * ) ( V_1001 -> V_1019 -> V_1020 + V_1015 ) ;
V_1007 = (struct V_1006 * )
( V_1001 -> V_1019 -> V_1020 + V_1015 +
F_253 ( V_1012 -> V_1021 . V_1022 ) ) ;
V_1009 = (struct V_1008 * )
( V_1001 -> V_1019 -> V_1020 + V_1015 +
F_253 ( V_1012 -> V_1021 . V_1023 ) ) ;
V_1011 = (struct V_1010 * )
( V_1001 -> V_1019 -> V_1020 + V_1015 +
F_253 ( V_1012 -> V_1021 . V_1024 ) ) ;
V_3 -> V_5 . V_6 . V_11 = F_207 ( sizeof( struct V_9 ) *
V_1007 -> V_1025 , V_909 ) ;
if ( ! V_3 -> V_5 . V_6 . V_11 )
return - V_910 ;
V_1018 = ( T_1 * ) V_1007 -> V_1026 ;
for ( V_41 = 0 ; V_41 < V_1007 -> V_1025 ; V_41 ++ ) {
T_1 * V_493 ;
V_1003 = (union V_1002 * ) V_1018 ;
V_1004 = V_1003 -> V_1027 . V_1028 ;
V_968 = (struct V_967 * )
& V_1011 -> V_1029 [ V_1004 ] ;
if ( ! V_3 -> V_5 . V_1003 [ V_41 ] . V_982 )
return - V_45 ;
V_11 = F_207 ( sizeof( struct V_8 ) , V_909 ) ;
if ( V_11 == NULL ) {
F_209 ( V_3 -> V_5 . V_6 . V_11 ) ;
return - V_910 ;
}
V_3 -> V_5 . V_6 . V_11 [ V_41 ] . V_12 = V_11 ;
F_251 ( V_3 , & V_3 -> V_5 . V_6 . V_11 [ V_41 ] ,
V_968 ,
V_1011 -> V_1030 ) ;
V_103 = 0 ;
V_493 = ( T_1 * ) & V_1003 -> V_1027 . V_1031 [ 0 ] ;
for ( V_102 = 0 ; V_102 < V_1003 -> V_1027 . V_1032 ; V_102 ++ ) {
V_1005 = V_493 [ V_102 ] ;
if ( V_1005 >= V_1009 -> V_1025 )
continue;
if ( V_103 >= V_1033 )
break;
V_982 = (union V_981 * )
( ( T_1 * ) & V_1009 -> V_1034 [ 0 ] +
( V_1005 * V_1009 -> V_1030 ) ) ;
F_254 ( V_3 ,
& V_3 -> V_5 . V_6 . V_11 [ V_41 ] , V_103 ,
V_982 ) ;
V_103 ++ ;
}
V_1018 += 2 + V_1003 -> V_1027 . V_1032 ;
}
V_3 -> V_5 . V_6 . V_1035 = V_1007 -> V_1025 ;
for ( V_41 = 0 ; V_41 < V_1036 ; V_41 ++ ) {
T_3 V_181 , V_182 ;
V_1005 = V_3 -> V_5 . V_6 . V_185 [ V_41 ] . V_1037 ;
V_982 = (union V_981 * )
& V_1009 -> V_1034 [ V_1005 * V_1009 -> V_1030 ] ;
V_181 = F_253 ( V_982 -> V_985 . V_986 ) ;
V_181 |= V_982 -> V_985 . V_987 << 16 ;
V_182 = F_253 ( V_982 -> V_985 . V_988 ) ;
V_182 |= V_982 -> V_985 . V_989 << 16 ;
V_3 -> V_5 . V_6 . V_185 [ V_41 ] . V_181 = V_181 ;
V_3 -> V_5 . V_6 . V_185 [ V_41 ] . V_182 = V_182 ;
}
return 0 ;
}
static int F_260 ( struct V_2 * V_3 ,
struct V_1038 * V_527 )
{
struct V_1000 * V_1001 = & V_3 -> V_1001 ;
int V_722 = F_258 ( V_1013 , V_1039 ) ;
T_18 * V_1040 ;
T_1 V_1016 , V_1017 ;
T_2 V_1015 ;
if ( F_259 ( V_1001 -> V_1019 , V_722 , NULL ,
& V_1016 , & V_1017 , & V_1015 ) ) {
V_1040 =
( T_18 * ) ( V_1001 -> V_1019 -> V_1020 +
V_1015 ) ;
V_527 -> V_763 = F_253 ( V_1040 -> V_1041 ) ;
V_527 -> V_759 = F_253 ( V_1040 -> V_1042 ) ;
V_527 -> V_761 = F_253 ( V_1040 -> V_1043 ) ;
V_527 -> V_991 = F_218 ( V_3 ) ;
V_527 -> V_993 = F_220 ( V_3 ) ;
V_527 -> V_756 = F_252 ( V_1040 -> V_1044 ) ;
V_527 -> V_757 = F_252 ( V_1040 -> V_1045 ) ;
return 0 ;
}
return - V_45 ;
}
void F_261 ( struct V_2 * V_3 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_5 . V_6 . V_1035 ; V_41 ++ ) {
F_209 ( V_3 -> V_5 . V_6 . V_11 [ V_41 ] . V_12 ) ;
}
F_209 ( V_3 -> V_5 . V_6 . V_11 ) ;
F_209 ( V_3 -> V_5 . V_6 . V_7 ) ;
F_209 ( V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 ) ;
F_262 ( V_3 ) ;
}
int F_263 ( struct V_2 * V_3 )
{
int V_722 = F_258 ( V_1013 , V_1046 ) ;
T_4 * V_97 ;
struct V_1047 V_1048 ;
T_2 V_1015 , V_1049 ;
T_1 V_1016 , V_1017 ;
struct V_1 * V_4 ;
int V_74 ;
T_3 V_145 ;
V_4 = F_207 ( sizeof( struct V_1 ) , V_909 ) ;
if ( V_4 == NULL )
return - V_910 ;
V_3 -> V_5 . V_6 . V_7 = V_4 ;
V_74 = F_264 ( V_3 -> V_1050 , & V_145 ) ;
if ( V_74 )
V_4 -> V_990 = 0 ;
else
V_4 -> V_990 = V_145 ;
V_4 -> V_937 = V_938 ;
V_4 -> V_728 . V_87 = V_1051 ;
V_4 -> V_728 . V_86 = V_940 ;
V_4 -> V_727 . V_87 = V_1051 ;
V_4 -> V_727 . V_86 = V_940 ;
V_4 -> V_730 . V_87 = 0 ;
V_4 -> V_730 . V_86 = 16 ;
V_4 -> V_729 . V_87 = 0 ;
V_4 -> V_729 . V_86 = 16 ;
V_74 = F_260 ( V_3 , & V_4 -> V_755 ) ;
if ( V_74 ) {
F_261 ( V_3 ) ;
return V_74 ;
}
V_74 = F_265 ( V_3 ) ;
if ( V_74 ) {
F_261 ( V_3 ) ;
return V_74 ;
}
V_74 = F_266 ( V_3 ) ;
if ( V_74 ) {
F_261 ( V_3 ) ;
return V_74 ;
}
V_74 = F_257 ( V_3 ) ;
if ( V_74 ) {
F_261 ( V_3 ) ;
return V_74 ;
}
V_4 -> V_646 = false ;
V_4 -> V_80 = V_1052 ;
V_4 -> V_712 [ 0 ] = V_1053 ;
V_4 -> V_712 [ 1 ] = V_1053 ;
V_4 -> V_712 [ 2 ] = V_1053 ;
V_4 -> V_712 [ 3 ] = V_1053 ;
V_4 -> V_712 [ 4 ] = V_1053 ;
V_4 -> V_712 [ 5 ] = V_1053 ;
V_4 -> V_712 [ 6 ] = V_1053 ;
V_4 -> V_712 [ 7 ] = V_1053 ;
V_4 -> V_627 = V_1054 ;
V_4 -> V_316 = 0 ;
V_4 -> V_320 = 0 ;
V_4 -> V_340 = 0 ;
V_4 -> V_166 = 0 ;
if ( ( V_3 -> V_13 -> V_14 == 0x6658 ) &&
( V_3 -> V_1055 -> V_1049 == ( V_1056 * 4 ) ) ) {
V_4 -> V_320 = 1 ;
}
V_4 -> V_405 = true ;
V_4 -> V_639 = 40000 ;
V_4 -> V_635 = 40000 ;
V_4 -> V_641 = 40000 ;
V_4 -> V_642 = 40000 ;
F_3 ( V_3 ) ;
V_4 -> V_283 = false ;
V_4 -> V_287 = false ;
V_4 -> V_811 = true ;
V_4 -> V_817 = true ;
F_68 ( V_3 ) ;
F_235 ( V_3 ) ;
F_225 ( V_3 ) ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 =
F_207 ( 4 * sizeof( struct V_1057 ) , V_909 ) ;
if ( ! V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 ) {
F_261 ( V_3 ) ;
return - V_910 ;
}
V_3 -> V_5 . V_6 . V_42 . V_804 . V_46 = 4 ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 [ 0 ] . V_489 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 [ 0 ] . V_456 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 [ 1 ] . V_489 = 36000 ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 [ 1 ] . V_456 = 720 ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 [ 2 ] . V_489 = 54000 ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 [ 2 ] . V_456 = 810 ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 [ 3 ] . V_489 = 72000 ;
V_3 -> V_5 . V_6 . V_42 . V_804 . V_44 [ 3 ] . V_456 = 900 ;
V_3 -> V_5 . V_6 . V_42 . V_1058 = 4 ;
V_3 -> V_5 . V_6 . V_42 . V_1059 = 15000 ;
V_3 -> V_5 . V_6 . V_42 . V_1060 = 200 ;
V_3 -> V_5 . V_6 . V_42 . V_1061 . V_46 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_1061 . V_1062 = NULL ;
V_3 -> V_5 . V_6 . V_42 . V_1063 . V_46 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_1063 . V_1062 = NULL ;
if ( V_3 -> V_27 == V_28 ) {
V_4 -> V_112 . V_776 = 94500 ;
V_4 -> V_112 . V_113 = 95000 ;
V_4 -> V_112 . V_1064 = 104000 ;
} else {
V_4 -> V_112 . V_776 = 99500 ;
V_4 -> V_112 . V_113 = 100000 ;
V_4 -> V_112 . V_1064 = 104000 ;
}
V_4 -> V_636 = false ;
V_97 = & V_4 -> V_98 ;
V_1048 = F_267 ( V_3 , V_1065 ) ;
if ( V_1048 . V_1066 ) {
V_97 -> V_1067 = V_1048 . V_144 ;
V_3 -> V_5 . V_6 . V_48 |= V_313 ;
} else {
V_97 -> V_1067 = V_1068 ;
V_3 -> V_5 . V_6 . V_48 &= ~ V_313 ;
}
V_1048 = F_267 ( V_3 , V_1069 ) ;
if ( V_1048 . V_1066 ) {
V_97 -> V_1070 = V_1048 . V_144 ;
V_3 -> V_5 . V_6 . V_48 |= V_742 ;
} else {
V_97 -> V_1070 = V_1068 ;
V_3 -> V_5 . V_6 . V_48 &= ~ V_742 ;
}
V_1048 = F_267 ( V_3 , V_1071 ) ;
if ( V_1048 . V_1066 ) {
T_3 V_202 = F_24 ( V_1072 ) ;
switch ( V_1048 . V_144 ) {
case 0 :
V_202 &= ~ V_1073 ;
V_202 |= F_268 ( 1 ) ;
break;
case 1 :
V_202 &= ~ V_1073 ;
V_202 |= F_268 ( 2 ) ;
break;
case 2 :
V_202 |= V_1074 ;
break;
case 3 :
V_202 |= V_1075 ;
break;
case 4 :
V_202 |= V_1076 ;
break;
default:
F_44 ( L_32 , V_1048 . V_144 ) ;
break;
}
F_26 ( V_1072 , V_202 ) ;
}
V_4 -> V_458 = V_488 ;
V_4 -> V_465 = V_488 ;
V_4 -> V_470 = V_488 ;
if ( F_269 ( V_3 , V_460 , V_461 ) )
V_4 -> V_458 = V_459 ;
else if ( F_269 ( V_3 , V_460 , V_1077 ) )
V_4 -> V_458 = V_462 ;
if ( V_3 -> V_5 . V_6 . V_48 & V_1078 ) {
if ( F_269 ( V_3 , V_466 , V_461 ) )
V_4 -> V_465 = V_459 ;
else if ( F_269 ( V_3 , V_466 , V_1077 ) )
V_4 -> V_465 = V_462 ;
else
V_3 -> V_5 . V_6 . V_48 &= ~ V_1078 ;
}
if ( V_3 -> V_5 . V_6 . V_48 & V_1079 ) {
if ( F_269 ( V_3 , V_471 , V_461 ) )
V_4 -> V_470 = V_459 ;
else if ( F_269 ( V_3 , V_471 , V_1077 ) )
V_4 -> V_470 = V_462 ;
else
V_3 -> V_5 . V_6 . V_48 &= ~ V_1079 ;
}
V_4 -> V_620 = true ;
#if F_270 ( F_222 )
V_4 -> V_966 =
F_271 ( V_3 ) ;
#else
V_4 -> V_966 = false ;
#endif
if ( F_259 ( V_3 -> V_1001 . V_1019 , V_722 , & V_1049 ,
& V_1016 , & V_1017 , & V_1015 ) ) {
V_4 -> V_421 = true ;
V_4 -> V_590 = true ;
V_4 -> V_964 = true ;
} else {
V_4 -> V_421 = false ;
V_4 -> V_590 = false ;
V_4 -> V_964 = true ;
}
if ( V_3 -> V_5 . V_1080 != V_1081 )
V_4 -> V_308 = true ;
else
V_4 -> V_308 = false ;
V_4 -> V_963 = true ;
V_4 -> V_174 = false ;
if ( ( V_3 -> V_5 . V_6 . V_42 . V_195 . V_181 == 0 ) ||
( V_3 -> V_5 . V_6 . V_42 . V_195 . V_182 == 0 ) )
V_3 -> V_5 . V_6 . V_42 . V_195 =
V_3 -> V_5 . V_6 . V_42 . V_194 ;
V_4 -> V_216 = true ;
return 0 ;
}
void F_272 ( struct V_2 * V_3 ,
struct V_1082 * V_1083 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_10 = & V_4 -> V_958 ;
T_3 V_181 = F_88 ( V_3 ) ;
T_3 V_182 = F_89 ( V_3 ) ;
F_273 ( V_1083 , L_33 , V_4 -> V_636 ? L_34 : L_35 ) ;
F_273 ( V_1083 , L_36 , V_10 -> V_183 ? L_34 : L_35 ) ;
F_273 ( V_1083 , L_37 ,
V_181 , V_182 ) ;
}
void F_274 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_983 * V_984 ;
int V_41 ;
F_275 ( V_10 -> V_189 , V_10 -> V_973 ) ;
F_276 ( V_10 -> V_970 ) ;
F_277 ( L_38 , V_10 -> V_552 , V_10 -> V_554 ) ;
for ( V_41 = 0 ; V_41 < V_11 -> V_196 ; V_41 ++ ) {
V_984 = & V_11 -> V_197 [ V_41 ] ;
F_277 ( L_39 ,
V_41 , V_984 -> V_181 , V_984 -> V_182 , V_984 -> V_723 + 1 , V_984 -> V_802 ) ;
}
F_278 ( V_3 , V_10 ) ;
}
T_3 F_279 ( struct V_2 * V_3 , bool V_1084 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_1085 = F_2 ( & V_4 -> V_960 ) ;
if ( V_1084 )
return V_1085 -> V_197 [ 0 ] . V_181 ;
else
return V_1085 -> V_197 [ V_1085 -> V_196 - 1 ] . V_181 ;
}
T_3 F_280 ( struct V_2 * V_3 , bool V_1084 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_1085 = F_2 ( & V_4 -> V_960 ) ;
if ( V_1084 )
return V_1085 -> V_197 [ 0 ] . V_182 ;
else
return V_1085 -> V_197 [ V_1085 -> V_196 - 1 ] . V_182 ;
}
