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
if ( F_42 ( V_3 ) > 120 )
return true ;
if ( V_175 < V_176 )
return true ;
else
return false ;
}
static void F_43 ( struct V_2 * V_3 ,
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
static int F_44 ( struct V_2 * V_3 ,
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
F_45 ( L_1 , V_200 , V_201 ) ;
return - V_45 ;
}
V_202 = F_24 ( V_203 ) ;
V_202 &= ~ ( V_204 | V_205 ) ;
V_202 |= F_46 ( V_201 / 1000 ) |
F_47 ( V_200 / 1000 ) ;
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
static int F_48 ( struct V_2 * V_3 ,
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
F_49 ( L_2 ) ;
return - V_45 ;
}
} else {
V_207 |= V_209 | V_210 ;
F_26 ( V_203 , V_207 ) ;
V_3 -> V_211 . V_212 = true ;
V_208 = F_32 ( V_3 , V_214 ) ;
if ( V_208 != V_152 ) {
F_49 ( L_3 ) ;
return - V_45 ;
}
}
return 0 ;
}
static void F_50 ( struct V_2 * V_3 , T_3 V_215 )
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
V_202 |= F_51 ( 0 ) ;
F_26 ( V_217 , V_202 ) ;
V_202 = F_24 ( V_217 ) & ~ V_218 ;
V_202 |= F_52 ( V_215 ) ;
F_26 ( V_217 , V_202 ) ;
}
static int F_53 ( struct V_2 * V_3 )
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
F_54 ( V_235 , 10000 ) ;
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
V_234 = F_55 ( V_3 ) ;
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
F_45 ( L_4 ) ;
V_3 -> V_5 . V_6 . V_82 . V_237 = false ;
}
return 0 ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_74 ;
if ( V_4 -> V_266 ) {
V_74 = F_57 ( V_3 ,
V_267 ,
V_268 ) ;
if ( V_74 != V_152 )
return - V_45 ;
V_74 = F_57 ( V_3 ,
V_269 ,
V_3 -> V_5 . V_6 . V_82 . V_270 ) ;
if ( V_74 != V_152 )
return - V_45 ;
} else {
V_74 = F_57 ( V_3 ,
V_267 ,
V_271 ) ;
if ( V_74 != V_152 )
return - V_45 ;
}
V_4 -> V_272 = true ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 )
{
T_5 V_74 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_74 = F_32 ( V_3 , V_273 ) ;
if ( V_74 == V_152 ) {
V_4 -> V_272 = false ;
return 0 ;
} else
return - V_45 ;
}
int F_59 ( struct V_2 * V_3 ,
T_3 * V_274 )
{
T_3 V_275 , V_226 ;
T_8 V_235 ;
if ( V_3 -> V_5 . V_276 )
return - V_277 ;
V_226 = ( F_24 ( V_238 ) & V_239 ) >> V_240 ;
V_275 = ( F_24 ( V_278 ) & V_279 ) >> V_280 ;
if ( V_226 == 0 )
return - V_45 ;
V_235 = ( T_8 ) V_275 * 100 ;
F_54 ( V_235 , V_226 ) ;
* V_274 = ( T_3 ) V_235 ;
if ( * V_274 > 100 )
* V_274 = 100 ;
return 0 ;
}
int F_60 ( struct V_2 * V_3 ,
T_3 V_274 )
{
T_3 V_202 ;
T_3 V_275 , V_226 ;
T_8 V_235 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_3 -> V_5 . V_276 )
return - V_277 ;
if ( V_4 -> V_272 )
return - V_45 ;
if ( V_274 > 100 )
return - V_45 ;
V_226 = ( F_24 ( V_238 ) & V_239 ) >> V_240 ;
if ( V_226 == 0 )
return - V_45 ;
V_235 = ( T_8 ) V_274 * V_226 ;
F_54 ( V_235 , 100 ) ;
V_275 = ( T_3 ) V_235 ;
V_202 = F_24 ( V_281 ) & ~ V_282 ;
V_202 |= F_61 ( V_275 ) ;
F_26 ( V_281 , V_202 ) ;
return 0 ;
}
void F_62 ( struct V_2 * V_3 , T_3 V_215 )
{
if ( V_215 ) {
if ( V_3 -> V_5 . V_6 . V_82 . V_237 )
F_58 ( V_3 ) ;
F_50 ( V_3 , V_215 ) ;
} else {
if ( V_3 -> V_5 . V_6 . V_82 . V_237 )
F_63 ( V_3 ) ;
else
F_64 ( V_3 ) ;
}
}
T_3 F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
if ( V_4 -> V_272 )
return 0 ;
V_202 = F_24 ( V_217 ) & V_218 ;
return ( V_202 >> V_219 ) ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
if ( ! V_4 -> V_216 ) {
V_202 = F_24 ( V_217 ) & ~ V_218 ;
V_202 |= F_52 ( V_4 -> V_220 ) ;
F_26 ( V_217 , V_202 ) ;
V_202 = F_24 ( V_217 ) & ~ V_221 ;
V_202 |= F_51 ( V_4 -> V_223 ) ;
F_26 ( V_217 , V_202 ) ;
V_4 -> V_216 = true ;
}
}
static void F_63 ( struct V_2 * V_3 )
{
if ( V_3 -> V_5 . V_6 . V_82 . V_237 ) {
F_56 ( V_3 ) ;
F_50 ( V_3 , V_283 ) ;
}
}
static void F_66 ( struct V_2 * V_3 )
{
T_3 V_202 ;
if ( V_3 -> V_5 . V_284 ) {
V_202 = F_24 ( V_285 ) & ~ V_286 ;
V_202 |= F_67 ( V_3 -> V_5 . V_284 - 1 ) ;
F_26 ( V_285 , V_202 ) ;
}
V_202 = F_24 ( V_217 ) & ~ V_287 ;
V_202 |= F_68 ( 0x28 ) ;
F_26 ( V_217 , V_202 ) ;
}
static int F_69 ( struct V_2 * V_3 )
{
int V_74 ;
F_66 ( V_3 ) ;
V_74 = F_44 ( V_3 , V_288 , V_289 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_48 ( V_3 , true ) ;
if ( V_74 )
return V_74 ;
if ( V_3 -> V_5 . V_6 . V_82 . V_237 ) {
V_74 = F_53 ( V_3 ) ;
if ( V_74 )
return V_74 ;
F_63 ( V_3 ) ;
}
return 0 ;
}
static void F_70 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_5 . V_276 )
F_64 ( V_3 ) ;
}
static int F_71 ( struct V_2 * V_3 ,
T_2 V_290 , T_3 V_57 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_72 ( V_3 ,
V_4 -> V_291 + V_290 ,
V_57 , V_4 -> V_80 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_4 * V_292 = & V_4 -> V_98 ;
if ( V_4 -> V_293 ) {
T_2 V_202 ;
V_202 = 45 ;
V_292 -> V_294 = F_9 ( V_202 ) ;
V_202 = 30 ;
V_292 -> V_295 = F_9 ( V_202 ) ;
}
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 = 0 ;
T_3 V_296 = 0 ;
if ( V_4 -> V_297 ) {
V_296 = F_17 ( V_4 -> V_296 ) ;
V_74 = F_19 ( V_3 ,
V_4 -> V_298 +
F_12 ( T_4 , V_299 ) ,
( T_1 * ) & V_296 ,
sizeof( T_3 ) , V_4 -> V_80 ) ;
}
return V_74 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_300 , V_301 ;
T_2 V_32 , V_302 ;
int V_41 ;
V_4 -> V_303 . V_46 = 0 ;
V_4 -> V_304 . V_46 = 0 ;
if ( V_3 -> V_5 . V_6 . V_48 & V_49 ) {
for ( V_41 = 0 ; V_41 < V_305 ; V_41 ++ ) {
V_301 = V_306 + V_41 ;
if ( F_76 ( V_3 , V_301 , & V_32 ) != 0 )
continue;
if ( V_32 != 0 && V_32 != V_301 ) {
V_4 -> V_303 . V_307 [ V_4 -> V_303 . V_46 ] = V_32 ;
V_4 -> V_303 . V_300 [ V_4 -> V_303 . V_46 ] = V_301 ;
V_4 -> V_303 . V_46 ++ ;
}
}
} else if ( F_77 ( V_3 , & V_300 ) == 0 ) {
for ( V_41 = 0 ; V_41 < V_305 ; V_41 ++ ) {
V_301 = V_306 + V_41 ;
if ( F_78 ( V_3 , & V_32 , & V_302 ,
V_301 ,
V_300 ) == 0 ) {
if ( V_32 != 0 && V_32 != V_301 ) {
V_4 -> V_303 . V_307 [ V_4 -> V_303 . V_46 ] = V_32 ;
V_4 -> V_303 . V_300 [ V_4 -> V_303 . V_46 ] = V_301 ;
V_4 -> V_303 . V_46 ++ ;
}
if ( V_302 != 0 && V_302 != V_301 ) {
V_4 -> V_304 . V_307 [ V_4 -> V_304 . V_46 ] = V_302 ;
V_4 -> V_304 . V_300 [ V_4 -> V_304 . V_46 ] = V_301 ;
V_4 -> V_304 . V_46 ++ ;
}
}
}
}
}
static void F_79 ( struct V_2 * V_3 , T_3 V_308 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
bool V_309 ;
enum V_310 V_311 ;
T_3 V_202 ;
switch ( V_308 ) {
case 0 :
default:
V_309 = false ;
break;
case ( 1 << V_312 ) :
V_309 = true ;
V_311 = V_313 ;
break;
case ( 1 << V_314 ) :
V_309 = true ;
V_311 = V_315 ;
break;
case ( ( 1 << V_314 ) |
( 1 << V_312 ) ) :
V_309 = true ;
V_311 = V_316 ;
break;
}
if ( V_309 ) {
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DPM_EVENT_SRC_MASK;
tmp |= DPM_EVENT_SRC(dpm_event_src);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
V_202 = F_24 ( V_317 ) ;
if ( V_4 -> V_318 )
V_202 &= ~ V_319 ;
else
V_202 |= V_319 ;
F_26 ( V_317 , V_202 ) ;
} else {
V_202 = F_24 ( V_317 ) ;
V_202 |= V_319 ;
F_26 ( V_317 , V_202 ) ;
}
}
static void F_80 ( struct V_2 * V_3 ,
enum V_320 V_321 ,
bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_131 ) {
if ( ! ( V_4 -> V_322 & ( 1 << V_321 ) ) ) {
V_4 -> V_322 |= 1 << V_321 ;
F_79 ( V_3 , V_4 -> V_322 ) ;
}
} else {
if ( V_4 -> V_322 & ( 1 << V_321 ) ) {
V_4 -> V_322 &= ~ ( 1 << V_321 ) ;
F_79 ( V_3 , V_4 -> V_322 ) ;
}
}
}
static void F_81 ( struct V_2 * V_3 )
{
if ( V_3 -> V_5 . V_6 . V_48 & V_323 )
F_32 ( V_3 , V_324 ) ;
}
static int F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
if ( ! V_4 -> V_325 )
return 0 ;
if ( ( ! V_4 -> V_326 ) &&
( V_4 -> V_325 & ( V_327 | V_328 ) ) ) {
V_149 = F_32 ( V_3 , V_329 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
if ( ( ! V_4 -> V_330 ) &&
( V_4 -> V_325 & V_331 ) ) {
V_149 = F_32 ( V_3 , V_332 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
V_4 -> V_325 = 0 ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
if ( V_131 ) {
if ( ! V_4 -> V_326 ) {
V_149 = F_32 ( V_3 , V_333 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
if ( ! V_4 -> V_330 ) {
V_149 = F_32 ( V_3 , V_334 ) ;
if ( V_149 != V_152 )
return - V_45 ;
F_84 ( V_335 , V_336 , ~ V_336 ) ;
F_26 ( V_337 , 0x05 ) ;
F_26 ( V_338 , 0x05 ) ;
F_26 ( V_339 , 0x100005 ) ;
F_85 ( 10 ) ;
F_26 ( V_337 , 0x400005 ) ;
F_26 ( V_338 , 0x400005 ) ;
F_26 ( V_339 , 0x500005 ) ;
}
} else {
if ( ! V_4 -> V_326 ) {
V_149 = F_32 ( V_3 , V_340 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
if ( ! V_4 -> V_330 ) {
V_149 = F_32 ( V_3 , V_341 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
}
return 0 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
int V_74 ;
T_3 V_202 ;
V_202 = F_24 ( V_317 ) ;
V_202 |= V_342 ;
F_26 ( V_317 , V_202 ) ;
V_202 = F_24 ( V_343 ) ;
V_202 |= V_344 ;
F_26 ( V_343 , V_202 ) ;
F_71 ( V_3 , F_12 ( V_345 , V_346 ) , 0x1000 ) ;
F_84 ( V_347 , 0 , ~ V_348 ) ;
V_149 = F_32 ( V_3 , V_349 ) ;
if ( V_149 != V_152 )
return - V_45 ;
V_74 = F_83 ( V_3 , true ) ;
if ( V_74 )
return V_74 ;
if ( ! V_4 -> V_350 ) {
V_149 = F_32 ( V_3 , V_351 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
if ( ! V_4 -> V_325 )
return 0 ;
if ( ( ! V_4 -> V_326 ) &&
( V_4 -> V_325 & ( V_327 | V_328 ) ) ) {
V_149 = F_32 ( V_3 , V_352 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
if ( ( ! V_4 -> V_330 ) &&
( V_4 -> V_325 & V_331 ) ) {
V_149 = F_32 ( V_3 , V_353 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_149 ;
int V_74 ;
T_3 V_202 ;
V_202 = F_24 ( V_317 ) ;
V_202 &= ~ V_342 ;
F_26 ( V_317 , V_202 ) ;
V_202 = F_24 ( V_343 ) ;
V_202 &= ~ V_344 ;
F_26 ( V_343 , V_202 ) ;
if ( ! V_4 -> V_350 ) {
V_149 = F_32 ( V_3 , V_354 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
V_74 = F_83 ( V_3 , false ) ;
if ( V_74 )
return V_74 ;
V_149 = F_32 ( V_3 , V_355 ) ;
if ( V_149 != V_152 )
return - V_45 ;
return 0 ;
}
static void F_89 ( struct V_2 * V_3 , bool V_131 )
{
T_3 V_202 = F_24 ( V_343 ) ;
if ( V_131 )
V_202 &= ~ V_356 ;
else
V_202 |= V_356 ;
F_26 ( V_343 , V_202 ) ;
}
static T_5 F_57 ( struct V_2 * V_3 ,
T_9 V_357 , T_3 V_358 )
{
F_27 ( V_359 , V_358 ) ;
return F_32 ( V_3 , V_357 ) ;
}
static T_5 F_90 ( struct V_2 * V_3 ,
T_9 V_357 , T_3 * V_358 )
{
T_5 V_149 ;
V_149 = F_32 ( V_3 , V_357 ) ;
if ( ( V_149 == V_152 ) && V_358 )
* V_358 = F_25 ( V_359 ) ;
return V_149 ;
}
static int F_91 ( struct V_2 * V_3 , T_3 V_360 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_326 ) {
T_5 V_149 =
F_57 ( V_3 , V_361 , 1 << V_360 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_92 ( struct V_2 * V_3 , T_3 V_360 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_330 ) {
T_5 V_149 =
F_57 ( V_3 , V_362 , 1 << V_360 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_93 ( struct V_2 * V_3 , T_3 V_360 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_350 ) {
T_5 V_149 =
F_57 ( V_3 , V_363 , V_360 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , T_3 V_360 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_150 & V_159 ) {
T_5 V_149 =
F_57 ( V_3 , V_364 , V_360 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
T_3 V_170 )
{
T_5 V_149 =
F_57 ( V_3 , V_365 , V_170 ) ;
if ( V_149 != V_152 )
return - V_45 ;
return 0 ;
}
static T_3 F_94 ( struct V_2 * V_3 )
{
T_3 V_366 ;
T_5 V_149 =
F_90 ( V_3 ,
V_367 ,
& V_366 ) ;
if ( V_149 != V_152 )
V_366 = 0 ;
return V_366 ;
}
static T_3 F_95 ( struct V_2 * V_3 )
{
T_3 V_368 ;
T_5 V_149 =
F_90 ( V_3 ,
V_369 ,
& V_368 ) ;
if ( V_149 != V_152 )
V_368 = 0 ;
return V_368 ;
}
static void F_96 ( struct V_2 * V_3 )
{
int V_41 ;
F_97 ( V_3 ) ;
F_98 ( V_3 ) ;
F_99 ( V_3 ) ;
for ( V_41 = 0 ; V_41 < V_3 -> V_370 ; V_41 ++ ) {
if ( F_24 ( V_371 ) & V_372 )
break;
}
}
static void F_100 ( struct V_2 * V_3 )
{
F_101 ( V_3 ) ;
F_102 ( V_3 ) ;
}
static int F_103 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
int V_74 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_373 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_298 = V_202 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_374 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_291 = V_202 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_375 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_376 = V_202 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_377 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_236 = V_202 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_378 ) ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_379 = V_202 ;
return 0 ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_380 . V_381 =
F_24 ( V_382 ) ;
V_4 -> V_380 . V_383 =
F_24 ( V_384 ) ;
V_4 -> V_380 . V_385 =
F_24 ( V_386 ) ;
V_4 -> V_380 . V_387 =
F_24 ( V_388 ) ;
V_4 -> V_380 . V_389 =
F_24 ( V_390 ) ;
V_4 -> V_380 . V_391 =
F_24 ( V_392 ) ;
V_4 -> V_380 . V_393 = F_25 ( V_394 ) ;
V_4 -> V_380 . V_395 = F_25 ( V_396 ) ;
V_4 -> V_380 . V_397 = F_25 ( V_398 ) ;
V_4 -> V_380 . V_399 = F_25 ( V_400 ) ;
V_4 -> V_380 . V_401 = F_25 ( V_402 ) ;
V_4 -> V_380 . V_403 = F_25 ( V_404 ) ;
V_4 -> V_380 . V_405 = F_25 ( V_406 ) ;
V_4 -> V_380 . V_407 = F_25 ( V_408 ) ;
V_4 -> V_380 . V_409 = F_25 ( V_410 ) ;
}
static void F_105 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_296 = 0 ;
}
static void F_106 ( struct V_2 * V_3 ,
bool V_131 )
{
T_3 V_202 = F_24 ( V_317 ) ;
if ( V_131 )
V_202 &= ~ V_319 ;
else
V_202 |= V_319 ;
F_26 ( V_317 , V_202 ) ;
}
static void F_107 ( struct V_2 * V_3 )
{
T_3 V_202 = F_24 ( V_317 ) ;
V_202 |= V_411 ;
F_26 ( V_317 , V_202 ) ;
}
static int F_108 ( struct V_2 * V_3 ,
bool V_412 )
{
T_9 V_357 = V_412 ? V_413 : V_414 ;
return ( F_32 ( V_3 , V_357 ) == V_152 ) ? 0 : - V_45 ;
}
static int F_109 ( struct V_2 * V_3 ,
bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_131 ) {
if ( V_4 -> V_415 ) {
if ( F_32 ( V_3 , V_416 ) != V_152 )
return - V_45 ;
} else {
if ( F_32 ( V_3 , V_417 ) != V_152 )
return - V_45 ;
}
} else {
if ( V_4 -> V_415 ) {
if ( F_32 ( V_3 , V_417 ) != V_152 )
return - V_45 ;
}
}
return 0 ;
}
static void F_110 ( struct V_2 * V_3 )
{
T_3 V_202 = F_24 ( V_418 ) ;
T_3 V_419 ;
T_3 V_420 ;
T_3 V_421 = V_3 -> clock . V_422 . V_423 ;
T_3 V_424 = F_42 ( V_3 ) ;
T_3 V_175 = F_41 ( V_3 ) ;
V_202 &= ~ V_425 ;
if ( V_3 -> V_5 . V_6 . V_188 > 0 )
V_202 |= F_111 ( V_426 ) ;
else
V_202 |= F_111 ( V_427 ) ;
F_26 ( V_418 , V_202 ) ;
if ( V_424 == 0 )
V_424 = 60 ;
if ( V_175 == 0xffffffff )
V_175 = 500 ;
V_420 = 1000000 / V_424 ;
V_419 =
V_420 - 200 - V_175 ;
V_202 = V_419 * ( V_421 / 100 ) ;
F_26 ( V_428 , V_202 ) ;
F_71 ( V_3 , F_12 ( V_345 , V_429 ) , 0x64 ) ;
F_71 ( V_3 , F_12 ( V_345 , V_430 ) , ( V_420 - V_419 ) ) ;
F_108 ( V_3 , ( V_3 -> V_5 . V_6 . V_188 == 1 ) ) ;
}
static void F_112 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
if ( V_131 ) {
if ( V_4 -> V_431 ) {
V_202 = F_24 ( V_317 ) ;
V_202 |= V_432 ;
F_26 ( V_317 , V_202 ) ;
}
} else {
V_202 = F_24 ( V_390 ) ;
V_202 &= ~ V_433 ;
F_26 ( V_390 , V_202 ) ;
V_202 = F_24 ( V_317 ) ;
V_202 &= ~ V_432 ;
F_26 ( V_317 , V_202 ) ;
}
}
static void F_113 ( struct V_2 * V_3 )
{
F_26 ( V_434 , ( F_114 ( V_435 ) | F_115 ( V_436 ) ) ) ;
}
static void F_116 ( struct V_2 * V_3 )
{
T_3 V_202 = F_24 ( V_418 ) ;
V_202 &= ~ ( V_425 | V_437 ) ;
V_202 |= ( F_111 ( V_427 ) |
F_117 ( V_438 ) ) ;
F_26 ( V_418 , V_202 ) ;
}
static void F_118 ( struct V_2 * V_3 )
{
T_3 V_202 ;
V_202 = F_24 ( V_343 ) ;
V_202 &= ~ ( V_439 | V_440 ) ;
F_26 ( V_343 , V_202 ) ;
F_26 ( V_441 , V_442 ) ;
F_26 ( V_443 , V_444 ) ;
F_26 ( V_445 , V_446 ) ;
F_26 ( V_447 , V_448 ) ;
F_26 ( V_449 , V_450 ) ;
F_26 ( V_451 , V_452 ) ;
F_26 ( V_453 , V_454 ) ;
F_26 ( V_455 , V_456 ) ;
}
static void F_119 ( struct V_2 * V_3 )
{
T_3 V_202 ;
V_202 = F_24 ( V_343 ) ;
V_202 |= ( V_439 | V_440 ) ;
F_26 ( V_343 , V_202 ) ;
F_26 ( V_441 , 0 ) ;
F_26 ( V_443 , 0 ) ;
F_26 ( V_445 , 0 ) ;
F_26 ( V_447 , 0 ) ;
F_26 ( V_449 , 0 ) ;
F_26 ( V_451 , 0 ) ;
F_26 ( V_453 , 0 ) ;
F_26 ( V_455 , 0 ) ;
}
static int F_120 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_41 , V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_370 ; V_41 ++ ) {
if ( F_24 ( V_457 ) & V_458 )
break;
}
F_26 ( V_459 , 1 ) ;
F_102 ( V_3 ) ;
F_101 ( V_3 ) ;
V_74 = F_121 ( V_3 , V_4 -> V_80 ) ;
return V_74 ;
}
static int F_122 ( struct V_2 * V_3 ,
struct V_460 * V_461 ,
struct V_462 * V_463 )
{
T_3 V_41 ;
if ( V_461 == NULL )
return - V_45 ;
V_463 -> V_464 = 0 ;
V_463 -> V_465 = 0 ;
V_463 -> V_46 = V_461 -> V_46 ;
for ( V_41 = 0 ; V_41 < V_463 -> V_46 ; V_41 ++ ) {
V_463 -> V_44 [ V_41 ] . V_57 = V_461 -> V_44 [ V_41 ] . V_466 ;
V_463 -> V_44 [ V_41 ] . V_467 = 0 ;
}
return 0 ;
}
static int F_123 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
if ( V_4 -> V_468 == V_469 ) {
V_74 = F_124 ( V_3 , V_470 ,
V_471 ,
& V_4 -> V_56 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_468 == V_472 ) {
V_74 = F_122 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_473 ,
& V_4 -> V_56 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_56 . V_46 > V_474 )
F_125 ( V_3 , V_474 ,
& V_4 -> V_56 ) ;
if ( V_4 -> V_475 == V_469 ) {
V_74 = F_124 ( V_3 , V_476 ,
V_471 ,
& V_4 -> V_477 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_475 == V_472 ) {
V_74 = F_122 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_478 ,
& V_4 -> V_477 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_477 . V_46 > V_479 )
F_125 ( V_3 , V_479 ,
& V_4 -> V_477 ) ;
if ( V_4 -> V_480 == V_469 ) {
V_74 = F_124 ( V_3 , V_481 ,
V_471 ,
& V_4 -> V_482 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_480 == V_472 ) {
V_74 = F_122 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_483 ,
& V_4 -> V_482 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_482 . V_46 > V_484 )
F_125 ( V_3 , V_484 ,
& V_4 -> V_482 ) ;
return 0 ;
}
static void F_126 ( struct V_2 * V_3 ,
struct V_485 * V_463 ,
T_10 * V_486 )
{
int V_74 ;
V_74 = F_127 ( V_3 , V_463 ,
& V_486 -> V_487 ,
& V_486 -> V_488 ) ;
if ( V_74 ) {
V_486 -> V_487 = V_463 -> V_57 * V_33 ;
V_486 -> V_488 = V_463 -> V_57 * V_33 ;
}
V_486 -> V_489 = F_9 ( V_463 -> V_57 * V_33 ) ;
V_486 -> V_487 =
F_9 ( V_486 -> V_487 ) ;
V_486 -> V_488 =
F_9 ( V_486 -> V_488 ) ;
}
static int F_128 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_46 ;
V_292 -> V_490 = V_4 -> V_56 . V_46 ;
for ( V_46 = 0 ; V_46 < V_292 -> V_490 ; V_46 ++ ) {
F_126 ( V_3 ,
& V_4 -> V_56 . V_44 [ V_46 ] ,
& V_292 -> V_491 [ V_46 ] ) ;
if ( V_4 -> V_468 == V_469 )
V_292 -> V_491 [ V_46 ] . V_492 |=
V_4 -> V_56 . V_44 [ V_46 ] . V_467 ;
else
V_292 -> V_491 [ V_46 ] . V_492 = 0 ;
}
V_292 -> V_490 = F_17 ( V_292 -> V_490 ) ;
return 0 ;
}
static int F_129 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
unsigned int V_46 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_292 -> V_493 = V_4 -> V_477 . V_46 ;
for ( V_46 = 0 ; V_46 < V_292 -> V_493 ; V_46 ++ ) {
F_126 ( V_3 ,
& V_4 -> V_477 . V_44 [ V_46 ] ,
& V_292 -> V_494 [ V_46 ] ) ;
if ( V_4 -> V_475 == V_469 )
V_292 -> V_494 [ V_46 ] . V_492 |=
V_4 -> V_477 . V_44 [ V_46 ] . V_467 ;
else
V_292 -> V_494 [ V_46 ] . V_492 = 0 ;
}
V_292 -> V_493 = F_17 ( V_292 -> V_493 ) ;
return 0 ;
}
static int F_130 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_46 ;
V_292 -> V_495 = V_4 -> V_482 . V_46 ;
for ( V_46 = 0 ; V_46 < V_292 -> V_495 ; V_46 ++ ) {
F_126 ( V_3 ,
& V_4 -> V_482 . V_44 [ V_46 ] ,
& V_292 -> V_496 [ V_46 ] ) ;
if ( V_4 -> V_480 == V_469 )
V_292 -> V_496 [ V_46 ] . V_492 |=
V_4 -> V_482 . V_44 [ V_46 ] . V_467 ;
else
V_292 -> V_496 [ V_46 ] . V_492 = 0 ;
}
V_292 -> V_495 = F_17 ( V_292 -> V_495 ) ;
return 0 ;
}
static int F_131 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
int V_74 ;
V_74 = F_128 ( V_3 , V_292 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_129 ( V_3 , V_292 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_130 ( V_3 , V_292 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static int F_132 ( struct V_2 * V_3 , T_3 V_182 ,
T_10 * V_497 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 = 0 ;
if ( V_4 -> V_480 != V_498 ) {
for ( V_41 = 0 ; V_41 < V_3 -> V_5 . V_6 . V_42 . V_483 . V_46 ; V_41 ++ ) {
if ( V_182 <= V_3 -> V_5 . V_6 . V_42 . V_483 . V_44 [ V_41 ] . V_499 ) {
V_497 -> V_489 = V_4 -> V_482 . V_44 [ V_41 ] . V_57 ;
break;
}
}
if ( V_41 >= V_3 -> V_5 . V_6 . V_42 . V_483 . V_46 )
return - V_45 ;
}
return - V_45 ;
}
static int F_127 ( struct V_2 * V_3 ,
struct V_485 * V_463 ,
T_2 * V_500 , T_2 * V_501 )
{
T_2 V_502 , V_503 ;
bool V_504 = false ;
* V_500 = V_463 -> V_57 * V_33 ;
* V_501 = V_463 -> V_57 * V_33 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 == NULL )
return - V_45 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 ) {
for ( V_502 = 0 ; ( T_3 ) V_502 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_502 ++ ) {
if ( V_463 -> V_57 ==
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_502 ] . V_466 ) {
V_504 = true ;
if ( ( T_3 ) V_502 < V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 )
V_503 = V_502 ;
else
V_503 = V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 - 1 ;
* V_501 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_503 ] . V_32 * V_33 ;
* V_500 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_503 ] . V_53 * V_33 ;
break;
}
}
if ( ! V_504 ) {
for ( V_502 = 0 ; ( T_3 ) V_502 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_502 ++ ) {
if ( V_463 -> V_57 <=
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_502 ] . V_466 ) {
V_504 = true ;
if ( ( T_3 ) V_502 < V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 )
V_503 = V_502 ;
else
V_503 = V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 - 1 ;
* V_501 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_503 ] . V_32 * V_33 ;
* V_500 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_503 ] . V_53 * V_33 ;
break;
}
}
}
}
return 0 ;
}
static void F_133 ( struct V_2 * V_3 ,
const struct V_505 * V_506 ,
T_3 V_181 ,
T_3 * V_507 )
{
unsigned int V_41 ;
* V_507 = 1 ;
for ( V_41 = 0 ; V_41 < V_506 -> V_46 ; V_41 ++ ) {
if ( V_181 < V_506 -> V_44 [ V_41 ] . V_181 ) {
* V_507 = V_41 ;
break;
}
}
}
static void F_134 ( struct V_2 * V_3 ,
const struct V_505 * V_506 ,
T_3 V_182 ,
T_3 * V_507 )
{
unsigned int V_41 ;
* V_507 = 1 ;
for ( V_41 = 0 ; V_41 < V_506 -> V_46 ; V_41 ++ ) {
if ( V_182 < V_506 -> V_44 [ V_41 ] . V_182 ) {
* V_507 = V_41 ;
break;
}
}
}
static int F_135 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
int V_74 ;
V_74 = F_11 ( V_3 , V_4 -> V_379 ,
& V_202 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_202 &= 0x00FFFFFF ;
V_202 |= V_508 << 24 ;
return F_72 ( V_3 , V_4 -> V_379 ,
V_202 , V_4 -> V_80 ) ;
}
static int F_136 ( struct V_2 * V_3 ,
struct V_460 * V_509 ,
T_3 clock , T_3 * V_497 )
{
T_3 V_41 = 0 ;
if ( V_509 -> V_46 == 0 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_509 -> V_46 ; V_41 ++ ) {
if ( V_509 -> V_44 [ V_41 ] . V_499 >= clock ) {
* V_497 = V_509 -> V_44 [ V_41 ] . V_466 ;
return 0 ;
}
}
* V_497 = V_509 -> V_44 [ V_41 - 1 ] . V_466 ;
return 0 ;
}
static T_1 F_137 ( struct V_2 * V_3 ,
T_3 V_181 , T_3 V_510 )
{
T_3 V_41 ;
T_3 V_202 ;
T_3 V_86 = ( V_510 > V_511 ) ?
V_510 : V_511 ;
if ( V_181 < V_86 )
return 0 ;
for ( V_41 = V_512 ; ; V_41 -- ) {
V_202 = V_181 / ( 1 << V_41 ) ;
if ( V_202 >= V_86 || V_41 == 0 )
break;
}
return ( T_1 ) V_41 ;
}
static int F_138 ( struct V_2 * V_3 )
{
return F_139 ( V_3 , V_513 , V_508 ) ;
}
static int F_140 ( struct V_2 * V_3 )
{
return ( F_32 ( V_3 , V_514 ) == V_152 ) ?
0 : - V_45 ;
}
static int F_141 ( struct V_2 * V_3 )
{
T_3 V_202 ;
V_202 = ( F_24 ( V_515 ) & 0x0000ff00 ) >> 8 ;
if ( V_202 == V_513 )
return 0 ;
return F_139 ( V_3 , V_202 , V_513 ) ;
}
static void F_142 ( struct V_2 * V_3 ,
const T_3 V_516 ,
const T_3 V_517 ,
T_3 * V_518 )
{
bool V_519 ;
T_3 V_202 , V_520 ;
V_202 = F_25 ( V_521 ) ;
V_519 = ( ( V_202 & 0x0000f00 ) == 0x300 ) ? true : false ;
if ( V_519 &&
( ( V_3 -> V_13 -> V_14 == 0x67B0 ) ||
( V_3 -> V_13 -> V_14 == 0x67B1 ) ) ) {
if ( ( V_517 > 100000 ) && ( V_517 <= 125000 ) ) {
V_520 = ( ( ( 0x31 * V_516 ) / 125000 ) - 1 ) & 0xff ;
* V_518 &= ~ 0x00ff0000 ;
* V_518 |= V_520 << 16 ;
} else if ( ( V_517 > 125000 ) && ( V_517 <= 137500 ) ) {
V_520 = ( ( ( 0x36 * V_516 ) / 137500 ) - 1 ) & 0xff ;
* V_518 &= ~ 0x00ff0000 ;
* V_518 |= V_520 << 16 ;
}
}
}
static int F_143 ( struct V_2 * V_3 ,
T_3 V_181 ,
T_3 V_182 ,
T_11 * V_522 )
{
T_3 V_523 ;
T_3 V_524 ;
T_3 V_525 ;
F_144 ( V_3 , V_181 , V_182 ) ;
V_523 = F_25 ( V_526 ) ;
V_524 = F_25 ( V_527 ) ;
V_525 = F_25 ( V_528 ) & V_529 ;
F_142 ( V_3 , V_181 , V_182 , & V_524 ) ;
V_522 -> V_530 = F_17 ( V_523 ) ;
V_522 -> V_531 = F_17 ( V_524 ) ;
V_522 -> V_532 = ( T_1 ) V_525 ;
return 0 ;
}
static int F_145 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_12 V_522 ;
T_3 V_41 , V_102 ;
int V_74 = 0 ;
memset ( & V_522 , 0 , sizeof( T_12 ) ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_97 . V_533 . V_46 ; V_41 ++ ) {
for ( V_102 = 0 ; V_102 < V_4 -> V_97 . V_534 . V_46 ; V_102 ++ ) {
V_74 = F_143 ( V_3 ,
V_4 -> V_97 . V_533 . V_535 [ V_41 ] . V_57 ,
V_4 -> V_97 . V_534 . V_535 [ V_102 ] . V_57 ,
& V_522 . V_44 [ V_41 ] [ V_102 ] ) ;
if ( V_74 )
break;
}
}
if ( V_74 == 0 )
V_74 = F_19 ( V_3 ,
V_4 -> V_379 ,
( T_1 * ) & V_522 ,
sizeof( T_12 ) ,
V_4 -> V_80 ) ;
return V_74 ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_325 == 0 )
return 0 ;
return F_145 ( V_3 ) ;
}
static void F_147 ( struct V_2 * V_3 ,
struct V_9 * V_536 )
{
struct V_8 * V_537 = F_2 ( V_536 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_538 = 0 ;
for ( V_538 = 0 ; V_538 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_538 ++ ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_538 ] . V_499 >=
V_537 -> V_197 [ 0 ] . V_181 ) {
V_4 -> V_98 . V_539 = V_538 ;
break;
}
}
for ( V_538 = 0 ; V_538 < V_3 -> V_5 . V_6 . V_42 . V_473 . V_46 ; V_538 ++ ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_473 . V_44 [ V_538 ] . V_499 >=
V_537 -> V_197 [ 0 ] . V_182 ) {
V_4 -> V_98 . V_540 = V_538 ;
break;
}
}
}
static T_3 F_148 ( struct V_541 * V_97 )
{
T_3 V_41 ;
T_3 V_542 = 0 ;
for ( V_41 = V_97 -> V_46 ; V_41 > 0 ; V_41 -- ) {
V_542 = V_542 << 1 ;
if ( V_97 -> V_535 [ V_41 - 1 ] . V_543 )
V_542 |= 0x1 ;
else
V_542 &= 0xFFFFFFFE ;
}
return V_542 ;
}
static void F_149 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_544 * V_97 = & V_4 -> V_97 ;
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_97 -> V_545 . V_46 ; V_41 ++ ) {
V_292 -> V_546 [ V_41 ] . V_547 =
( T_1 ) V_97 -> V_545 . V_535 [ V_41 ] . V_57 ;
V_292 -> V_546 [ V_41 ] . V_548 =
F_150 ( V_97 -> V_545 . V_535 [ V_41 ] . V_549 ) ;
V_292 -> V_546 [ V_41 ] . V_550 = 1 ;
V_292 -> V_546 [ V_41 ] . V_551 = F_17 ( 5 ) ;
V_292 -> V_546 [ V_41 ] . V_552 = F_17 ( 30 ) ;
}
V_4 -> V_98 . V_553 = ( T_1 ) V_97 -> V_545 . V_46 ;
V_4 -> V_554 . V_555 =
F_148 ( & V_97 -> V_545 ) ;
}
static int F_151 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
T_3 V_46 ;
struct V_556 V_557 ;
int V_74 = - V_45 ;
V_292 -> V_558 =
V_3 -> V_5 . V_6 . V_42 . V_559 . V_46 ;
for ( V_46 = 0 ; V_46 < V_292 -> V_558 ; V_46 ++ ) {
V_292 -> V_560 [ V_46 ] . V_561 =
V_3 -> V_5 . V_6 . V_42 . V_559 . V_44 [ V_46 ] . V_562 ;
V_292 -> V_560 [ V_46 ] . V_563 =
V_3 -> V_5 . V_6 . V_42 . V_559 . V_44 [ V_46 ] . V_564 ;
V_292 -> V_560 [ V_46 ] . V_565 =
V_3 -> V_5 . V_6 . V_42 . V_559 . V_44 [ V_46 ] . V_466 * V_33 ;
V_292 -> V_560 [ V_46 ] . V_566 = 1 ;
V_74 = F_152 ( V_3 ,
V_567 ,
V_292 -> V_560 [ V_46 ] . V_561 , false , & V_557 ) ;
if ( V_74 )
return V_74 ;
V_292 -> V_560 [ V_46 ] . V_568 = ( T_1 ) V_557 . V_569 ;
V_74 = F_152 ( V_3 ,
V_567 ,
V_292 -> V_560 [ V_46 ] . V_563 , false , & V_557 ) ;
if ( V_74 )
return V_74 ;
V_292 -> V_560 [ V_46 ] . V_570 = ( T_1 ) V_557 . V_569 ;
V_292 -> V_560 [ V_46 ] . V_561 = F_17 ( V_292 -> V_560 [ V_46 ] . V_561 ) ;
V_292 -> V_560 [ V_46 ] . V_563 = F_17 ( V_292 -> V_560 [ V_46 ] . V_563 ) ;
V_292 -> V_560 [ V_46 ] . V_565 = F_9 ( V_292 -> V_560 [ V_46 ] . V_565 ) ;
}
return V_74 ;
}
static int F_153 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
T_3 V_46 ;
struct V_556 V_557 ;
int V_74 = - V_45 ;
V_292 -> V_571 =
V_3 -> V_5 . V_6 . V_42 . V_572 . V_46 ;
for ( V_46 = 0 ; V_46 < V_292 -> V_571 ; V_46 ++ ) {
V_292 -> V_573 [ V_46 ] . V_574 =
V_3 -> V_5 . V_6 . V_42 . V_572 . V_44 [ V_46 ] . V_184 ;
V_292 -> V_573 [ V_46 ] . V_575 =
( T_2 ) V_3 -> V_5 . V_6 . V_42 . V_572 . V_44 [ V_46 ] . V_466 * V_33 ;
V_292 -> V_573 [ V_46 ] . V_576 = 1 ;
V_74 = F_152 ( V_3 ,
V_567 ,
V_292 -> V_573 [ V_46 ] . V_574 , false , & V_557 ) ;
if ( V_74 )
return V_74 ;
V_292 -> V_573 [ V_46 ] . V_577 = ( T_1 ) V_557 . V_569 ;
V_292 -> V_573 [ V_46 ] . V_574 = F_17 ( V_292 -> V_573 [ V_46 ] . V_574 ) ;
V_292 -> V_573 [ V_46 ] . V_575 = F_9 ( V_292 -> V_573 [ V_46 ] . V_575 ) ;
}
return V_74 ;
}
static int F_154 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
T_3 V_46 ;
struct V_556 V_557 ;
int V_74 = - V_45 ;
V_292 -> V_578 = ( T_1 )
( V_3 -> V_5 . V_6 . V_42 . V_579 . V_46 ) ;
for ( V_46 = 0 ; V_46 < V_292 -> V_578 ; V_46 ++ ) {
V_292 -> V_580 [ V_46 ] . V_574 =
V_3 -> V_5 . V_6 . V_42 . V_579 . V_44 [ V_46 ] . V_499 ;
V_292 -> V_580 [ V_46 ] . V_575 =
V_3 -> V_5 . V_6 . V_42 . V_579 . V_44 [ V_46 ] . V_466 ;
V_292 -> V_580 [ V_46 ] . V_576 = 1 ;
V_74 = F_152 ( V_3 ,
V_567 ,
V_292 -> V_580 [ V_46 ] . V_574 , false , & V_557 ) ;
if ( V_74 )
return V_74 ;
V_292 -> V_580 [ V_46 ] . V_577 = ( T_1 ) V_557 . V_569 ;
V_292 -> V_580 [ V_46 ] . V_574 = F_17 ( V_292 -> V_580 [ V_46 ] . V_574 ) ;
V_292 -> V_580 [ V_46 ] . V_575 = F_9 ( V_292 -> V_580 [ V_46 ] . V_575 ) ;
}
return V_74 ;
}
static int F_155 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
T_3 V_46 ;
struct V_556 V_557 ;
int V_74 = - V_45 ;
V_292 -> V_581 =
V_3 -> V_5 . V_6 . V_42 . V_582 . V_46 ;
for ( V_46 = 0 ; V_46 < V_292 -> V_581 ; V_46 ++ ) {
V_292 -> V_583 [ V_46 ] . V_574 =
V_3 -> V_5 . V_6 . V_42 . V_582 . V_44 [ V_46 ] . V_499 ;
V_292 -> V_583 [ V_46 ] . V_575 =
V_3 -> V_5 . V_6 . V_42 . V_582 . V_44 [ V_46 ] . V_466 * V_33 ;
V_292 -> V_583 [ V_46 ] . V_576 = 1 ;
V_74 = F_152 ( V_3 ,
V_567 ,
V_292 -> V_583 [ V_46 ] . V_574 , false , & V_557 ) ;
if ( V_74 )
return V_74 ;
V_292 -> V_583 [ V_46 ] . V_577 = ( T_1 ) V_557 . V_569 ;
V_292 -> V_583 [ V_46 ] . V_574 = F_17 ( V_292 -> V_583 [ V_46 ] . V_574 ) ;
V_292 -> V_583 [ V_46 ] . V_575 = F_9 ( V_292 -> V_583 [ V_46 ] . V_575 ) ;
}
return V_74 ;
}
static int F_156 ( struct V_2 * V_3 ,
T_3 V_517 ,
T_13 * V_182 ,
bool V_584 ,
bool V_585 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_393 = V_4 -> V_380 . V_393 ;
T_3 V_395 = V_4 -> V_380 . V_395 ;
T_3 V_397 = V_4 -> V_380 . V_397 ;
T_3 V_399 = V_4 -> V_380 . V_399 ;
T_3 V_401 = V_4 -> V_380 . V_401 ;
T_3 V_403 = V_4 -> V_380 . V_403 ;
T_3 V_405 = V_4 -> V_380 . V_405 ;
T_3 V_407 = V_4 -> V_380 . V_407 ;
T_3 V_409 = V_4 -> V_380 . V_409 ;
struct V_586 V_587 ;
int V_74 ;
V_74 = F_157 ( V_3 , V_517 , V_584 , & V_587 ) ;
if ( V_74 )
return V_74 ;
V_401 &= ~ V_588 ;
V_401 |= F_158 ( V_587 . V_589 ) ;
V_403 &= ~ ( V_590 | V_591 | V_592 ) ;
V_403 |= F_159 ( V_587 . V_593 ) |
F_160 ( V_587 . V_594 ) | F_161 ( V_587 . V_595 ) ;
V_397 &= ~ V_596 ;
V_397 |= F_162 ( V_587 . V_597 ) ;
if ( V_4 -> V_177 ) {
V_399 &= ~ ( V_598 | V_596 ) ;
V_399 |= F_163 ( V_587 . V_599 ) |
F_162 ( V_587 . V_597 ) ;
}
if ( V_4 -> V_600 ) {
struct V_601 V_602 ;
T_3 V_603 ;
T_3 V_202 ;
T_3 V_234 = V_3 -> clock . V_604 . V_423 ;
if ( V_587 . V_605 == 1 )
V_603 = V_517 * 4 * ( 1 << V_587 . V_597 ) ;
else
V_603 = V_517 * 2 * ( 1 << V_587 . V_597 ) ;
V_202 = ( V_603 / V_234 ) ;
V_202 = V_202 * V_202 ;
if ( F_164 ( V_3 , & V_602 ,
V_606 , V_603 ) ) {
T_3 V_607 = V_234 * 5 / V_602 . V_608 ;
T_3 V_609 = ( T_3 ) ( ( ( ( 131 * V_602 . V_610 * V_602 . V_608 ) / 100 ) * V_202 ) / V_603 ) ;
V_407 &= ~ V_611 ;
V_407 |= F_165 ( V_609 ) ;
V_409 &= ~ V_612 ;
V_409 |= F_166 ( V_607 ) ;
}
}
V_395 &= ~ V_613 ;
V_395 |= F_167 ( V_587 . V_614 ) ;
if ( V_585 )
V_395 |= V_615 | V_616 ;
else
V_395 &= ~ ( V_615 | V_616 ) ;
V_182 -> V_617 = V_517 ;
V_182 -> V_618 = V_401 ;
V_182 -> V_619 = V_403 ;
V_182 -> V_620 = V_405 ;
V_182 -> V_621 = V_397 ;
V_182 -> V_622 = V_399 ;
V_182 -> V_623 = V_395 ;
V_182 -> V_624 = V_393 ;
V_182 -> V_625 = V_407 ;
V_182 -> V_626 = V_409 ;
return 0 ;
}
static int F_168 ( struct V_2 * V_3 ,
T_3 V_517 ,
T_13 * V_627 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
bool V_585 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_473 . V_44 ) {
V_74 = F_136 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_473 ,
V_517 , & V_627 -> V_565 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_3 -> V_5 . V_6 . V_42 . V_478 . V_44 ) {
V_74 = F_136 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_478 ,
V_517 , & V_627 -> V_628 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_3 -> V_5 . V_6 . V_42 . V_483 . V_44 ) {
V_74 = F_136 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_483 ,
V_517 , & V_627 -> V_629 ) ;
if ( V_74 )
return V_74 ;
}
V_627 -> V_566 = 1 ;
if ( V_4 -> V_630 )
F_134 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_631 ,
V_517 ,
& V_627 -> V_566 ) ;
V_627 -> V_632 = 1 ;
V_627 -> V_633 = 0 ;
V_627 -> V_634 = 100 ;
V_627 -> V_635 = 0 ;
V_627 -> V_636 = ( T_2 ) V_4 -> V_637 ;
V_627 -> V_638 = false ;
V_627 -> V_639 = false ;
V_627 -> V_640 = false ;
V_627 -> V_641 = false ;
V_627 -> V_642 = false ;
V_627 -> V_643 = V_644 ;
if ( V_4 -> V_645 &&
( V_517 <= V_4 -> V_645 ) &&
( V_4 -> V_646 == false ) &&
( F_25 ( V_647 ) & V_648 ) &&
( V_3 -> V_5 . V_6 . V_188 <= 2 ) )
V_627 -> V_638 = true ;
if ( V_4 -> V_649 &&
( V_517 <= V_4 -> V_649 ) )
V_627 -> V_639 = 1 ;
if ( V_4 -> V_177 ) {
V_627 -> V_650 =
F_169 ( V_517 , V_627 -> V_639 ) ;
if ( V_4 -> V_651 &&
( V_517 > V_4 -> V_651 ) )
V_627 -> V_640 = true ;
if ( V_4 -> V_652 &&
( V_517 > V_4 -> V_652 ) )
V_627 -> V_641 = true ;
if ( V_627 -> V_639 ) {
if ( F_169 ( V_517 , true ) >=
( ( F_25 ( V_653 ) >> 16 ) & 0xf ) )
V_585 = ( ( F_25 ( V_654 ) >> 1 ) & 0x1 ) ? true : false ;
else
V_585 = ( ( F_25 ( V_655 ) >> 1 ) & 0x1 ) ? true : false ;
} else {
V_585 = V_4 -> V_656 ;
}
} else {
V_627 -> V_650 = F_170 ( V_517 ) ;
V_585 = ( ( F_25 ( V_654 ) >> 1 ) & 0x1 ) ? true : false ;
}
V_74 = F_156 ( V_3 , V_517 , V_627 , V_627 -> V_639 , V_585 ) ;
if ( V_74 )
return V_74 ;
V_627 -> V_565 = F_17 ( V_627 -> V_565 * V_33 ) ;
V_627 -> V_566 = F_17 ( V_627 -> V_566 ) ;
V_627 -> V_628 = F_17 ( V_627 -> V_628 * V_33 ) ;
V_627 -> V_629 = F_17 ( V_627 -> V_629 * V_33 ) ;
V_627 -> V_617 = F_17 ( V_627 -> V_617 ) ;
V_627 -> V_636 = F_9 ( V_627 -> V_636 ) ;
V_627 -> V_618 = F_17 ( V_627 -> V_618 ) ;
V_627 -> V_619 = F_17 ( V_627 -> V_619 ) ;
V_627 -> V_620 = F_17 ( V_627 -> V_620 ) ;
V_627 -> V_621 = F_17 ( V_627 -> V_621 ) ;
V_627 -> V_622 = F_17 ( V_627 -> V_622 ) ;
V_627 -> V_623 = F_17 ( V_627 -> V_623 ) ;
V_627 -> V_624 = F_17 ( V_627 -> V_624 ) ;
V_627 -> V_625 = F_17 ( V_627 -> V_625 ) ;
V_627 -> V_626 = F_17 ( V_627 -> V_626 ) ;
return 0 ;
}
static int F_171 ( struct V_2 * V_3 ,
T_4 * V_292 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_556 V_557 ;
T_10 V_657 ;
T_3 V_658 = V_4 -> V_380 . V_381 ;
T_3 V_659 = V_4 -> V_380 . V_383 ;
T_3 V_393 = V_4 -> V_380 . V_393 ;
T_3 V_395 = V_4 -> V_380 . V_395 ;
int V_74 ;
V_292 -> V_660 . V_661 &= ~ V_662 ;
if ( V_4 -> V_663 )
V_292 -> V_660 . V_565 = F_17 ( V_4 -> V_663 * V_33 ) ;
else
V_292 -> V_660 . V_565 = F_17 ( V_4 -> V_664 * V_33 ) ;
V_292 -> V_660 . V_566 = V_4 -> V_630 ? 0 : 1 ;
V_292 -> V_660 . V_665 = V_3 -> clock . V_422 . V_423 ;
V_74 = F_152 ( V_3 ,
V_666 ,
V_292 -> V_660 . V_665 , false , & V_557 ) ;
if ( V_74 )
return V_74 ;
V_292 -> V_660 . V_667 = ( T_1 ) V_557 . V_569 ;
V_292 -> V_660 . V_643 = V_644 ;
V_292 -> V_660 . V_668 = 0 ;
V_658 &= ~ V_669 ;
V_658 |= V_670 ;
V_659 &= ~ V_671 ;
V_659 |= F_172 ( 4 ) ;
V_292 -> V_660 . V_672 = V_658 ;
V_292 -> V_660 . V_673 = V_659 ;
V_292 -> V_660 . V_674 = V_4 -> V_380 . V_385 ;
V_292 -> V_660 . V_675 = V_4 -> V_380 . V_387 ;
V_292 -> V_660 . V_676 = V_4 -> V_380 . V_389 ;
V_292 -> V_660 . V_677 = V_4 -> V_380 . V_391 ;
V_292 -> V_660 . V_678 = 0 ;
V_292 -> V_660 . V_679 = 0 ;
V_292 -> V_660 . V_661 = F_17 ( V_292 -> V_660 . V_661 ) ;
V_292 -> V_660 . V_566 = F_17 ( V_292 -> V_660 . V_566 ) ;
V_292 -> V_660 . V_665 = F_17 ( V_292 -> V_660 . V_665 ) ;
V_292 -> V_660 . V_672 = F_17 ( V_292 -> V_660 . V_672 ) ;
V_292 -> V_660 . V_673 = F_17 ( V_292 -> V_660 . V_673 ) ;
V_292 -> V_660 . V_674 = F_17 ( V_292 -> V_660 . V_674 ) ;
V_292 -> V_660 . V_675 = F_17 ( V_292 -> V_660 . V_675 ) ;
V_292 -> V_660 . V_676 = F_17 ( V_292 -> V_660 . V_676 ) ;
V_292 -> V_660 . V_677 = F_17 ( V_292 -> V_660 . V_677 ) ;
V_292 -> V_660 . V_678 = F_17 ( V_292 -> V_660 . V_678 ) ;
V_292 -> V_660 . V_679 = F_17 ( V_292 -> V_660 . V_679 ) ;
V_292 -> V_680 . V_565 = V_292 -> V_660 . V_565 ;
V_292 -> V_680 . V_566 = V_292 -> V_660 . V_566 ;
if ( V_4 -> V_475 != V_498 ) {
if ( V_4 -> V_681 )
V_292 -> V_680 . V_628 =
F_17 ( V_4 -> V_681 * V_33 ) ;
else
V_292 -> V_680 . V_628 =
F_17 ( V_4 -> V_682 * V_33 ) ;
}
if ( F_132 ( V_3 , 0 , & V_657 ) )
V_292 -> V_680 . V_629 = 0 ;
else
V_292 -> V_680 . V_629 =
F_17 ( V_657 . V_489 * V_33 ) ;
V_395 |= V_683 | V_684 ;
V_395 &= ~ ( V_615 | V_616 ) ;
V_393 &= ~ ( V_685 | V_686 ) ;
V_292 -> V_680 . V_624 = F_17 ( V_393 ) ;
V_292 -> V_680 . V_623 = F_17 ( V_395 ) ;
V_292 -> V_680 . V_621 =
F_17 ( V_4 -> V_380 . V_397 ) ;
V_292 -> V_680 . V_622 =
F_17 ( V_4 -> V_380 . V_399 ) ;
V_292 -> V_680 . V_618 =
F_17 ( V_4 -> V_380 . V_401 ) ;
V_292 -> V_680 . V_619 =
F_17 ( V_4 -> V_380 . V_403 ) ;
V_292 -> V_680 . V_620 =
F_17 ( V_4 -> V_380 . V_405 ) ;
V_292 -> V_680 . V_625 = F_17 ( V_4 -> V_380 . V_407 ) ;
V_292 -> V_680 . V_626 = F_17 ( V_4 -> V_380 . V_409 ) ;
V_292 -> V_680 . V_632 = 0 ;
V_292 -> V_680 . V_550 = 0 ;
V_292 -> V_680 . V_633 = 0 ;
V_292 -> V_680 . V_634 = 100 ;
V_292 -> V_680 . V_635 = 0 ;
V_292 -> V_680 . V_636 =
F_9 ( ( T_2 ) V_4 -> V_637 ) ;
V_292 -> V_680 . V_638 = false ;
V_292 -> V_680 . V_639 = false ;
V_292 -> V_680 . V_640 = false ;
V_292 -> V_680 . V_641 = false ;
V_292 -> V_680 . V_642 = false ;
return 0 ;
}
static int F_173 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_687 * V_688 = & V_4 -> V_688 ;
if ( V_688 -> V_689 ) {
if ( V_131 )
return ( F_32 ( V_3 , V_690 ) == V_152 ) ?
0 : - V_45 ;
else
return ( F_32 ( V_3 , V_691 ) == V_152 ) ?
0 : - V_45 ;
}
return 0 ;
}
static int F_174 ( struct V_2 * V_3 ,
T_14 * V_692 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_693 = V_3 -> V_5 . V_6 . V_694 ;
V_692 -> V_678 = 0 ;
V_692 -> V_679 = 0 ;
if ( V_693 == 0 ) {
V_4 -> V_688 . V_689 = false ;
return 0 ;
}
if ( V_4 -> V_468 != V_472 ) {
if ( V_693 > V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_466 )
V_692 -> V_695 = 0 ;
else
V_692 -> V_695 =
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_466 - V_693 ;
} else {
if ( V_693 > V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_466 )
V_692 -> V_696 = 0 ;
else
V_692 -> V_696 = ( T_1 )
( ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_466 - V_693 ) *
V_697 / V_698 ) ;
}
V_692 -> V_699 = V_4 -> V_630 ? 0 : 1 ;
V_692 -> V_678 = F_17 ( V_692 -> V_678 ) ;
V_692 -> V_679 = F_17 ( V_692 -> V_679 ) ;
V_692 -> V_695 = F_9 ( V_692 -> V_695 ) ;
return 0 ;
}
static int F_175 ( struct V_2 * V_3 ,
T_3 V_516 ,
T_15 * V_181 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_556 V_557 ;
T_3 V_700 = V_4 -> V_380 . V_385 ;
T_3 V_701 = V_4 -> V_380 . V_387 ;
T_3 V_389 = V_4 -> V_380 . V_389 ;
T_3 V_391 = V_4 -> V_380 . V_391 ;
T_3 V_234 = V_3 -> clock . V_422 . V_423 ;
T_3 V_702 ;
T_3 V_703 ;
int V_74 ;
V_74 = F_152 ( V_3 ,
V_666 ,
V_516 , false , & V_557 ) ;
if ( V_74 )
return V_74 ;
V_702 = 1 + V_557 . V_704 ;
V_703 = V_557 . V_705 & 0x3FFFFFF ;
V_700 &= ~ V_706 ;
V_700 |= F_176 ( V_703 ) ;
V_700 |= V_707 ;
if ( V_4 -> V_431 ) {
struct V_601 V_602 ;
T_3 V_708 = V_516 * V_557 . V_597 ;
if ( F_164 ( V_3 , & V_602 ,
V_709 , V_708 ) ) {
T_3 V_710 = V_234 * 5 / ( V_702 * V_602 . V_608 ) ;
T_3 V_711 = 4 * V_602 . V_610 * V_703 / ( V_710 * 10000 ) ;
V_389 &= ~ V_712 ;
V_389 |= F_177 ( V_710 ) ;
V_389 |= V_433 ;
V_391 &= ~ V_713 ;
V_391 |= F_178 ( V_711 ) ;
}
}
V_181 -> V_665 = V_516 ;
V_181 -> V_674 = V_700 ;
V_181 -> V_675 = V_701 ;
V_181 -> V_676 = V_389 ;
V_181 -> V_677 = V_391 ;
V_181 -> V_667 = ( T_1 ) V_557 . V_569 ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 ,
T_3 V_516 ,
T_2 V_714 ,
T_15 * V_715 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
V_74 = F_175 ( V_3 , V_516 , V_715 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_136 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_47 ,
V_516 , & V_715 -> V_565 ) ;
if ( V_74 )
return V_74 ;
V_715 -> V_665 = V_516 ;
V_715 -> V_661 = 0 ;
V_715 -> V_566 = 1 ;
if ( V_4 -> V_630 )
F_133 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_631 ,
V_516 ,
& V_715 -> V_566 ) ;
V_715 -> V_636 = V_714 ;
V_715 -> V_678 = 0 ;
V_715 -> V_679 = 0 ;
V_715 -> V_632 = 1 ;
V_715 -> V_633 = 0 ;
V_715 -> V_634 = 0 ;
V_715 -> V_635 = 0 ;
V_715 -> V_716 = 0 ;
if ( V_4 -> V_415 )
V_715 -> V_668 = F_137 ( V_3 ,
V_516 ,
V_511 ) ;
V_715 -> V_643 = V_644 ;
V_715 -> V_661 = F_17 ( V_715 -> V_661 ) ;
V_715 -> V_565 = F_17 ( V_715 -> V_565 * V_33 ) ;
V_715 -> V_566 = F_17 ( V_715 -> V_566 ) ;
V_715 -> V_665 = F_17 ( V_715 -> V_665 ) ;
V_715 -> V_636 = F_9 ( V_715 -> V_636 ) ;
V_715 -> V_674 = F_17 ( V_715 -> V_674 ) ;
V_715 -> V_675 = F_17 ( V_715 -> V_675 ) ;
V_715 -> V_676 = F_17 ( V_715 -> V_676 ) ;
V_715 -> V_677 = F_17 ( V_715 -> V_677 ) ;
V_715 -> V_678 = F_17 ( V_715 -> V_678 ) ;
V_715 -> V_679 = F_17 ( V_715 -> V_679 ) ;
return 0 ;
}
static int F_180 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_544 * V_97 = & V_4 -> V_97 ;
T_3 V_717 = V_4 -> V_298 +
F_12 ( T_4 , V_718 ) ;
T_3 V_719 = sizeof( T_15 ) *
V_720 ;
T_15 * V_721 = V_4 -> V_98 . V_718 ;
T_3 V_41 , V_74 ;
memset ( V_721 , 0 , V_719 ) ;
for ( V_41 = 0 ; V_41 < V_97 -> V_533 . V_46 ; V_41 ++ ) {
V_74 = F_179 ( V_3 ,
V_97 -> V_533 . V_535 [ V_41 ] . V_57 ,
( T_2 ) V_4 -> V_722 [ V_41 ] ,
& V_4 -> V_98 . V_718 [ V_41 ] ) ;
if ( V_74 )
return V_74 ;
if ( V_41 > 1 )
V_4 -> V_98 . V_718 [ V_41 ] . V_668 = 0 ;
if ( V_41 == ( V_97 -> V_533 . V_46 - 1 ) )
V_4 -> V_98 . V_718 [ V_41 ] . V_643 =
V_723 ;
}
V_4 -> V_98 . V_718 [ 0 ] . V_550 = 1 ;
V_4 -> V_98 . V_724 = ( T_1 ) V_97 -> V_533 . V_46 ;
V_4 -> V_554 . V_725 =
F_148 ( & V_97 -> V_533 ) ;
V_74 = F_19 ( V_3 , V_717 ,
( T_1 * ) V_721 , V_719 ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static int F_181 ( struct V_2 * V_3 ,
T_14 * V_726 )
{
return F_174 ( V_3 , V_726 ) ;
}
static int F_182 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_544 * V_97 = & V_4 -> V_97 ;
T_3 V_717 = V_4 -> V_298 +
F_12 ( T_4 , V_727 ) ;
T_3 V_719 = sizeof( T_13 ) *
V_728 ;
T_13 * V_721 = V_4 -> V_98 . V_727 ;
T_3 V_41 , V_74 ;
memset ( V_721 , 0 , V_719 ) ;
for ( V_41 = 0 ; V_41 < V_97 -> V_534 . V_46 ; V_41 ++ ) {
if ( V_97 -> V_534 . V_535 [ V_41 ] . V_57 == 0 )
return - V_45 ;
V_74 = F_168 ( V_3 ,
V_97 -> V_534 . V_535 [ V_41 ] . V_57 ,
& V_4 -> V_98 . V_727 [ V_41 ] ) ;
if ( V_74 )
return V_74 ;
}
V_4 -> V_98 . V_727 [ 0 ] . V_550 = 1 ;
if ( ( V_97 -> V_534 . V_46 >= 2 ) &&
( ( V_3 -> V_13 -> V_14 == 0x67B0 ) || ( V_3 -> V_13 -> V_14 == 0x67B1 ) ) ) {
V_4 -> V_98 . V_727 [ 1 ] . V_565 =
V_4 -> V_98 . V_727 [ 0 ] . V_565 ;
V_4 -> V_98 . V_727 [ 1 ] . V_566 =
V_4 -> V_98 . V_727 [ 0 ] . V_566 ;
}
V_4 -> V_98 . V_727 [ 0 ] . V_636 = F_9 ( 0x1F ) ;
V_4 -> V_98 . V_729 = ( T_1 ) V_97 -> V_534 . V_46 ;
V_4 -> V_554 . V_730 =
F_148 ( & V_97 -> V_534 ) ;
V_4 -> V_98 . V_727 [ V_97 -> V_534 . V_46 - 1 ] . V_643 =
V_723 ;
V_74 = F_19 ( V_3 , V_717 ,
( T_1 * ) V_721 , V_719 ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static void F_183 ( struct V_2 * V_3 ,
struct V_541 * V_97 ,
T_3 V_46 )
{
T_3 V_41 ;
V_97 -> V_46 = V_46 ;
for ( V_41 = 0 ; V_41 < V_731 ; V_41 ++ )
V_97 -> V_535 [ V_41 ] . V_543 = false ;
}
static void F_184 ( struct V_541 * V_97 ,
T_3 V_732 , T_3 V_733 , T_3 V_734 )
{
V_97 -> V_535 [ V_732 ] . V_57 = V_733 ;
V_97 -> V_535 [ V_732 ] . V_549 = V_734 ;
V_97 -> V_535 [ V_732 ] . V_543 = true ;
}
static int F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_735 && ! V_4 -> V_736 )
return - V_45 ;
if ( V_4 -> V_735 && ! V_4 -> V_736 ) {
V_4 -> V_737 = V_4 -> V_738 ;
V_4 -> V_739 = V_4 -> V_740 ;
} else if ( ! V_4 -> V_735 && V_4 -> V_736 ) {
V_4 -> V_738 = V_4 -> V_737 ;
V_4 -> V_740 = V_4 -> V_739 ;
}
F_183 ( V_3 ,
& V_4 -> V_97 . V_545 ,
V_741 ) ;
if ( V_3 -> V_27 == V_742 )
F_184 ( & V_4 -> V_97 . V_545 , 0 ,
V_4 -> V_737 . V_86 ,
V_4 -> V_739 . V_87 ) ;
else
F_184 ( & V_4 -> V_97 . V_545 , 0 ,
V_4 -> V_737 . V_86 ,
V_4 -> V_739 . V_86 ) ;
F_184 ( & V_4 -> V_97 . V_545 , 1 ,
V_4 -> V_738 . V_86 ,
V_4 -> V_740 . V_86 ) ;
F_184 ( & V_4 -> V_97 . V_545 , 2 ,
V_4 -> V_737 . V_86 ,
V_4 -> V_739 . V_87 ) ;
F_184 ( & V_4 -> V_97 . V_545 , 3 ,
V_4 -> V_738 . V_86 ,
V_4 -> V_740 . V_87 ) ;
F_184 ( & V_4 -> V_97 . V_545 , 4 ,
V_4 -> V_737 . V_87 ,
V_4 -> V_739 . V_87 ) ;
F_184 ( & V_4 -> V_97 . V_545 , 5 ,
V_4 -> V_738 . V_87 ,
V_4 -> V_740 . V_87 ) ;
V_4 -> V_97 . V_545 . V_46 = 6 ;
return 0 ;
}
static int F_186 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_460 * V_743 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
struct V_460 * V_744 =
& V_3 -> V_5 . V_6 . V_42 . V_473 ;
struct V_745 * V_746 =
& V_3 -> V_5 . V_6 . V_42 . V_43 ;
T_3 V_41 ;
if ( V_743 == NULL )
return - V_45 ;
if ( V_743 -> V_46 < 1 )
return - V_45 ;
if ( V_744 == NULL )
return - V_45 ;
if ( V_744 -> V_46 < 1 )
return - V_45 ;
memset ( & V_4 -> V_97 , 0 , sizeof( struct V_544 ) ) ;
F_183 ( V_3 ,
& V_4 -> V_97 . V_533 ,
V_720 ) ;
F_183 ( V_3 ,
& V_4 -> V_97 . V_534 ,
V_728 ) ;
F_183 ( V_3 ,
& V_4 -> V_97 . V_747 ,
V_474 ) ;
F_183 ( V_3 ,
& V_4 -> V_97 . V_748 ,
V_479 ) ;
F_183 ( V_3 ,
& V_4 -> V_97 . V_749 ,
V_484 ) ;
V_4 -> V_97 . V_533 . V_46 = 0 ;
for ( V_41 = 0 ; V_41 < V_743 -> V_46 ; V_41 ++ ) {
if ( ( V_41 == 0 ) ||
( V_4 -> V_97 . V_533 . V_535 [ V_4 -> V_97 . V_533 . V_46 - 1 ] . V_57 !=
V_743 -> V_44 [ V_41 ] . V_499 ) ) {
V_4 -> V_97 . V_533 . V_535 [ V_4 -> V_97 . V_533 . V_46 ] . V_57 =
V_743 -> V_44 [ V_41 ] . V_499 ;
V_4 -> V_97 . V_533 . V_535 [ V_4 -> V_97 . V_533 . V_46 ] . V_543 =
( V_41 == 0 ) ? true : false ;
V_4 -> V_97 . V_533 . V_46 ++ ;
}
}
V_4 -> V_97 . V_534 . V_46 = 0 ;
for ( V_41 = 0 ; V_41 < V_744 -> V_46 ; V_41 ++ ) {
if ( ( V_41 == 0 ) ||
( V_4 -> V_97 . V_534 . V_535 [ V_4 -> V_97 . V_534 . V_46 - 1 ] . V_57 !=
V_744 -> V_44 [ V_41 ] . V_499 ) ) {
V_4 -> V_97 . V_534 . V_535 [ V_4 -> V_97 . V_534 . V_46 ] . V_57 =
V_744 -> V_44 [ V_41 ] . V_499 ;
V_4 -> V_97 . V_534 . V_535 [ V_4 -> V_97 . V_534 . V_46 ] . V_543 =
( V_41 == 0 ) ? true : false ;
V_4 -> V_97 . V_534 . V_46 ++ ;
}
}
for ( V_41 = 0 ; V_41 < V_743 -> V_46 ; V_41 ++ ) {
V_4 -> V_97 . V_747 . V_535 [ V_41 ] . V_57 =
V_743 -> V_44 [ V_41 ] . V_466 ;
V_4 -> V_97 . V_747 . V_535 [ V_41 ] . V_549 =
V_746 -> V_44 [ V_41 ] . V_53 ;
V_4 -> V_97 . V_747 . V_535 [ V_41 ] . V_543 = true ;
}
V_4 -> V_97 . V_747 . V_46 = V_743 -> V_46 ;
V_744 = & V_3 -> V_5 . V_6 . V_42 . V_478 ;
if ( V_744 ) {
for ( V_41 = 0 ; V_41 < V_744 -> V_46 ; V_41 ++ ) {
V_4 -> V_97 . V_748 . V_535 [ V_41 ] . V_57 =
V_744 -> V_44 [ V_41 ] . V_466 ;
V_4 -> V_97 . V_748 . V_535 [ V_41 ] . V_543 = true ;
}
V_4 -> V_97 . V_748 . V_46 = V_744 -> V_46 ;
}
V_744 = & V_3 -> V_5 . V_6 . V_42 . V_483 ;
if ( V_744 ) {
for ( V_41 = 0 ; V_41 < V_744 -> V_46 ; V_41 ++ ) {
V_4 -> V_97 . V_749 . V_535 [ V_41 ] . V_57 =
V_744 -> V_44 [ V_41 ] . V_466 ;
V_4 -> V_97 . V_749 . V_535 [ V_41 ] . V_543 = true ;
}
V_4 -> V_97 . V_749 . V_46 = V_744 -> V_46 ;
}
F_185 ( V_3 ) ;
return 0 ;
}
static int F_187 ( struct V_541 * V_292 ,
T_3 V_57 , T_3 * V_750 )
{
T_3 V_41 ;
int V_74 = - V_45 ;
for( V_41 = 0 ; V_41 < V_292 -> V_46 ; V_41 ++ ) {
if ( V_57 == V_292 -> V_535 [ V_41 ] . V_57 ) {
* V_750 = V_41 ;
V_74 = 0 ;
}
}
return V_74 ;
}
static int F_188 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_687 * V_688 = & V_4 -> V_688 ;
struct V_9 * V_536 = V_3 -> V_5 . V_6 . V_751 ;
T_4 * V_292 = & V_4 -> V_98 ;
int V_74 ;
V_74 = F_186 ( V_3 ) ;
if ( V_74 )
return V_74 ;
if ( V_4 -> V_468 != V_498 )
F_131 ( V_3 , V_292 ) ;
F_73 ( V_3 ) ;
if ( V_3 -> V_5 . V_6 . V_48 & V_752 )
V_292 -> V_753 |= V_754 ;
if ( V_3 -> V_5 . V_6 . V_48 & V_755 )
V_292 -> V_753 |= V_756 ;
if ( V_4 -> V_177 )
V_292 -> V_753 |= V_757 ;
if ( V_688 -> V_689 ) {
V_74 = F_181 ( V_3 , & V_4 -> V_98 . V_758 ) ;
if ( V_74 )
return V_74 ;
F_26 ( V_759 , V_688 -> V_760 ) ;
}
V_74 = F_180 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_182 ( V_3 ) ;
if ( V_74 )
return V_74 ;
F_149 ( V_3 , V_292 ) ;
V_74 = F_171 ( V_3 , V_292 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_153 ( V_3 , V_292 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_154 ( V_3 , V_292 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_155 ( V_3 , V_292 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_145 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_151 ( V_3 , V_292 ) ;
if ( V_74 )
return V_74 ;
V_292 -> V_761 = 0 ;
V_292 -> V_762 = 0 ;
V_292 -> V_763 = 0 ;
V_292 -> V_764 = 0 ;
V_292 -> V_539 = 0 ;
V_292 -> V_540 = 0 ;
V_74 = F_187 ( & V_4 -> V_97 . V_533 ,
V_4 -> V_765 . V_766 ,
( T_3 * ) & V_4 -> V_98 . V_539 ) ;
V_74 = F_187 ( & V_4 -> V_97 . V_534 ,
V_4 -> V_765 . V_767 ,
( T_3 * ) & V_4 -> V_98 . V_540 ) ;
V_292 -> V_768 = V_4 -> V_765 . V_769 ;
V_292 -> V_770 = V_4 -> V_765 . V_771 ;
V_292 -> V_772 = V_4 -> V_765 . V_773 ;
F_147 ( V_3 , V_536 ) ;
V_74 = F_16 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_292 -> V_774 = 1 ;
V_292 -> V_775 = 1 ;
V_292 -> V_776 = 1 ;
V_292 -> V_777 = 1 ;
V_292 -> V_778 = 1 ;
V_292 -> V_779 = 1 ;
V_292 -> V_780 = 1 ;
V_292 -> V_781 = 1 ;
V_292 -> V_782 = 1 ;
V_292 -> V_783 = ( T_2 ) ( ( V_4 -> V_112 . V_113 *
V_784 ) / 1000 ) ;
V_292 -> V_785 = ( T_2 ) ( ( V_4 -> V_112 . V_786 *
V_784 ) / 1000 ) ;
V_292 -> V_787 = 1 ;
V_292 -> V_788 = 1 ;
V_292 -> V_789 = 0 ;
V_292 -> V_790 = 4000 ;
V_292 -> V_791 = 0 ;
V_292 -> V_792 = 1 ;
V_292 -> V_793 = V_4 -> V_97 . V_545 . V_46 - 1 ;
V_292 -> V_794 = 1 ;
if ( V_4 -> V_468 == V_472 )
V_292 -> V_795 = 1 ;
else
V_292 -> V_795 = 0 ;
V_292 -> V_796 = 17 ;
V_292 -> V_797 = 0x4000 ;
V_292 -> V_753 = F_17 ( V_292 -> V_753 ) ;
V_292 -> V_798 = F_17 ( V_292 -> V_798 ) ;
V_292 -> V_799 = F_17 ( V_292 -> V_799 ) ;
V_292 -> V_800 = F_17 ( V_292 -> V_800 ) ;
V_292 -> V_801 = F_17 ( V_292 -> V_801 ) ;
V_292 -> V_797 = F_17 ( V_292 -> V_797 ) ;
V_292 -> V_783 = F_9 ( V_292 -> V_783 ) ;
V_292 -> V_785 = F_9 ( V_292 -> V_785 ) ;
V_292 -> V_790 = F_9 ( V_292 -> V_790 ) ;
V_292 -> V_789 = F_9 ( V_292 -> V_789 ) ;
V_292 -> V_791 = F_9 ( V_292 -> V_791 ) ;
V_292 -> V_768 = F_9 ( V_292 -> V_768 * V_33 ) ;
V_292 -> V_770 = F_9 ( V_292 -> V_770 * V_33 ) ;
V_292 -> V_772 = F_9 ( V_292 -> V_772 * V_33 ) ;
V_74 = F_19 ( V_3 ,
V_4 -> V_298 +
F_12 ( T_4 , V_753 ) ,
( T_1 * ) & V_292 -> V_753 ,
sizeof( T_4 ) - 3 * sizeof( V_802 ) ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static void F_189 ( struct V_2 * V_3 ,
struct V_541 * V_97 ,
T_3 V_803 , T_3 V_804 )
{
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_97 -> V_46 ; V_41 ++ ) {
if ( ( V_97 -> V_535 [ V_41 ] . V_57 < V_803 ) ||
( V_97 -> V_535 [ V_41 ] . V_57 > V_804 ) )
V_97 -> V_535 [ V_41 ] . V_543 = false ;
else
V_97 -> V_535 [ V_41 ] . V_543 = true ;
}
}
static void F_190 ( struct V_2 * V_3 ,
T_3 V_805 , T_3 V_806 ,
T_3 V_807 , T_3 V_808 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_541 * V_809 = & V_4 -> V_97 . V_545 ;
T_3 V_41 , V_102 ;
for ( V_41 = 0 ; V_41 < V_809 -> V_46 ; V_41 ++ ) {
if ( ( V_809 -> V_535 [ V_41 ] . V_57 < V_805 ) ||
( V_809 -> V_535 [ V_41 ] . V_549 < V_806 ) ||
( V_809 -> V_535 [ V_41 ] . V_57 > V_807 ) ||
( V_809 -> V_535 [ V_41 ] . V_549 > V_808 ) )
V_809 -> V_535 [ V_41 ] . V_543 = false ;
else
V_809 -> V_535 [ V_41 ] . V_543 = true ;
}
for ( V_41 = 0 ; V_41 < V_809 -> V_46 ; V_41 ++ ) {
if ( V_809 -> V_535 [ V_41 ] . V_543 ) {
for ( V_102 = V_41 + 1 ; V_102 < V_809 -> V_46 ; V_102 ++ ) {
if ( V_809 -> V_535 [ V_102 ] . V_543 ) {
if ( ( V_809 -> V_535 [ V_41 ] . V_57 == V_809 -> V_535 [ V_102 ] . V_57 ) &&
( V_809 -> V_535 [ V_41 ] . V_549 == V_809 -> V_535 [ V_102 ] . V_549 ) )
V_809 -> V_535 [ V_102 ] . V_543 = false ;
}
}
}
}
}
static int F_191 ( struct V_2 * V_3 ,
struct V_9 * V_810 )
{
struct V_8 * V_692 = F_2 ( V_810 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_811 ;
if ( V_692 -> V_196 < 1 )
return - V_45 ;
if ( V_692 -> V_196 == 1 )
V_811 = 0 ;
else
V_811 = 1 ;
F_189 ( V_3 ,
& V_4 -> V_97 . V_533 ,
V_692 -> V_197 [ 0 ] . V_181 ,
V_692 -> V_197 [ V_811 ] . V_181 ) ;
F_189 ( V_3 ,
& V_4 -> V_97 . V_534 ,
V_692 -> V_197 [ 0 ] . V_182 ,
V_692 -> V_197 [ V_811 ] . V_182 ) ;
F_190 ( V_3 ,
V_692 -> V_197 [ 0 ] . V_733 ,
V_692 -> V_197 [ 0 ] . V_812 ,
V_692 -> V_197 [ V_811 ] . V_733 ,
V_692 -> V_197 [ V_811 ] . V_812 ) ;
return 0 ;
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_460 * V_813 =
& V_3 -> V_5 . V_6 . V_42 . V_814 ;
struct V_460 * V_747 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
T_3 V_815 = 0 ;
T_3 V_41 ;
if ( V_813 == NULL )
return - V_45 ;
if ( ! V_813 -> V_46 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_813 -> V_46 ; V_41 ++ ) {
if ( V_3 -> clock . V_816 == V_813 -> V_44 [ V_41 ] . V_499 )
V_815 = V_813 -> V_44 [ V_41 ] . V_466 ;
}
for ( V_41 = 0 ; V_41 < V_747 -> V_46 ; V_41 ++ ) {
if ( V_815 <= V_747 -> V_44 [ V_41 ] . V_466 ) {
V_815 = V_747 -> V_44 [ V_41 ] . V_466 ;
return ( F_57 ( V_3 ,
V_817 ,
V_815 * V_33 ) == V_152 ) ?
0 : - V_45 ;
}
}
return - V_45 ;
}
static int F_193 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_208 ;
F_192 ( V_3 ) ;
if ( ! V_4 -> V_326 ) {
if ( V_4 -> V_554 . V_725 ) {
V_208 = F_57 ( V_3 ,
V_361 ,
V_4 -> V_554 . V_725 ) ;
if ( V_208 != V_152 )
return - V_45 ;
}
}
if ( ! V_4 -> V_330 ) {
if ( V_4 -> V_554 . V_730 ) {
V_208 = F_57 ( V_3 ,
V_362 ,
V_4 -> V_554 . V_730 ) ;
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
static void F_194 ( struct V_2 * V_3 ,
struct V_9 * V_810 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_692 = F_2 ( V_810 ) ;
struct V_541 * V_533 = & V_4 -> V_97 . V_533 ;
T_3 V_181 = V_692 -> V_197 [ V_692 -> V_196 - 1 ] . V_181 ;
struct V_541 * V_534 = & V_4 -> V_97 . V_534 ;
T_3 V_182 = V_692 -> V_197 [ V_692 -> V_196 - 1 ] . V_182 ;
T_3 V_41 ;
V_4 -> V_325 = 0 ;
for ( V_41 = 0 ; V_41 < V_533 -> V_46 ; V_41 ++ ) {
if ( V_181 == V_533 -> V_535 [ V_41 ] . V_57 )
break;
}
if ( V_41 >= V_533 -> V_46 ) {
V_4 -> V_325 |= V_327 ;
} else {
if ( V_511 != V_511 )
V_4 -> V_325 |= V_328 ;
}
for ( V_41 = 0 ; V_41 < V_534 -> V_46 ; V_41 ++ ) {
if ( V_182 == V_534 -> V_535 [ V_41 ] . V_57 )
break;
}
if ( V_41 >= V_534 -> V_46 )
V_4 -> V_325 |= V_331 ;
if ( V_3 -> V_5 . V_6 . V_818 !=
V_3 -> V_5 . V_6 . V_188 )
V_4 -> V_325 |= V_819 ;
}
static int F_195 ( struct V_2 * V_3 ,
struct V_9 * V_810 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_692 = F_2 ( V_810 ) ;
T_3 V_181 = V_692 -> V_197 [ V_692 -> V_196 - 1 ] . V_181 ;
T_3 V_182 = V_692 -> V_197 [ V_692 -> V_196 - 1 ] . V_182 ;
struct V_544 * V_97 = & V_4 -> V_97 ;
int V_74 ;
if ( ! V_4 -> V_325 )
return 0 ;
if ( V_4 -> V_325 & V_327 )
V_97 -> V_533 . V_535 [ V_97 -> V_533 . V_46 - 1 ] . V_57 = V_181 ;
if ( V_4 -> V_325 & V_331 )
V_97 -> V_534 . V_535 [ V_97 -> V_534 . V_46 - 1 ] . V_57 = V_182 ;
if ( V_4 -> V_325 & ( V_327 | V_328 ) ) {
V_74 = F_180 ( V_3 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_325 & ( V_331 | V_819 ) ) {
V_74 = F_182 ( V_3 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static int F_196 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_178 * V_179 ;
int V_41 ;
if ( V_3 -> V_5 . V_6 . V_193 )
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_194 ;
else
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_195 ;
if ( V_131 ) {
V_4 -> V_554 . V_820 = 0 ;
for ( V_41 = V_3 -> V_5 . V_6 . V_42 . V_559 . V_46 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_559 . V_44 [ V_41 ] . V_466 <= V_179 -> V_32 ) {
V_4 -> V_554 . V_820 |= 1 << V_41 ;
if ( ! V_4 -> V_821 )
break;
}
}
F_57 ( V_3 ,
V_822 ,
V_4 -> V_554 . V_820 ) ;
if ( V_4 -> V_823 & 0x1 ) {
V_4 -> V_646 = true ;
V_4 -> V_554 . V_730 &= 0xFFFFFFFE ;
F_57 ( V_3 ,
V_362 ,
V_4 -> V_554 . V_730 ) ;
}
} else {
if ( V_4 -> V_823 & 0x1 ) {
V_4 -> V_646 = false ;
V_4 -> V_554 . V_730 |= 1 ;
F_57 ( V_3 ,
V_362 ,
V_4 -> V_554 . V_730 ) ;
}
}
return ( F_32 ( V_3 , V_131 ?
V_824 : V_825 ) == V_152 ) ?
0 : - V_45 ;
}
static int F_197 ( struct V_2 * V_3 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_178 * V_179 ;
int V_41 ;
if ( V_3 -> V_5 . V_6 . V_193 )
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_194 ;
else
V_179 = & V_3 -> V_5 . V_6 . V_42 . V_195 ;
if ( V_131 ) {
V_4 -> V_554 . V_826 = 0 ;
for ( V_41 = V_3 -> V_5 . V_6 . V_42 . V_572 . V_46 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_572 . V_44 [ V_41 ] . V_466 <= V_179 -> V_32 ) {
V_4 -> V_554 . V_826 |= 1 << V_41 ;
if ( ! V_4 -> V_827 )
break;
}
}
F_57 ( V_3 ,
V_828 ,
V_4 -> V_554 . V_826 ) ;
}
return ( F_32 ( V_3 , V_131 ?
V_829 : V_830 ) == V_152 ) ?
0 : - V_45 ;
}
static int F_39 ( struct V_2 * V_3 , bool V_173 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
if ( ! V_173 ) {
if ( V_4 -> V_821 ||
( V_3 -> V_5 . V_6 . V_42 . V_559 . V_46 <= 0 ) )
V_4 -> V_98 . V_761 = 0 ;
else
V_4 -> V_98 . V_761 =
V_3 -> V_5 . V_6 . V_42 . V_559 . V_46 - 1 ;
V_202 = F_24 ( V_831 ) ;
V_202 &= ~ V_832 ;
V_202 |= V_761 ( V_4 -> V_98 . V_761 ) ;
F_26 ( V_831 , V_202 ) ;
}
return F_196 ( V_3 , ! V_173 ) ;
}
static T_1 F_198 ( struct V_2 * V_3 )
{
T_1 V_41 ;
T_3 V_833 = 30000 ;
struct V_834 * V_292 =
& V_3 -> V_5 . V_6 . V_42 . V_572 ;
for ( V_41 = 0 ; V_41 < V_292 -> V_46 ; V_41 ++ ) {
if ( V_292 -> V_44 [ V_41 ] . V_184 >= V_833 )
return V_41 ;
}
return V_292 -> V_46 - 1 ;
}
static int F_199 ( struct V_2 * V_3 ,
struct V_9 * V_835 ,
struct V_9 * V_836 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 = 0 ;
T_3 V_202 ;
if ( V_836 -> V_184 != V_835 -> V_184 ) {
if ( V_835 -> V_184 ) {
F_200 ( V_3 , V_837 , false ) ;
V_4 -> V_98 . V_762 = F_198 ( V_3 ) ;
V_202 = F_24 ( V_831 ) ;
V_202 &= ~ V_838 ;
V_202 |= V_762 ( V_4 -> V_98 . V_762 ) ;
F_26 ( V_831 , V_202 ) ;
V_74 = F_197 ( V_3 , true ) ;
} else {
F_200 ( V_3 , V_837 , true ) ;
V_74 = F_197 ( V_3 , false ) ;
}
}
return V_74 ;
}
static int F_201 ( struct V_2 * V_3 ,
struct V_9 * V_810 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
V_74 = F_191 ( V_3 , V_810 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_554 . V_725 =
F_148 ( & V_4 -> V_97 . V_533 ) ;
V_4 -> V_554 . V_730 =
F_148 ( & V_4 -> V_97 . V_534 ) ;
V_4 -> V_823 =
V_4 -> V_554 . V_730 ;
if ( V_4 -> V_646 ) {
if ( V_4 -> V_554 . V_730 & 1 )
V_4 -> V_554 . V_730 &= 0xFFFFFFFE ;
}
V_4 -> V_554 . V_555 =
F_148 ( & V_4 -> V_97 . V_545 ) ;
return 0 ;
}
static T_3 F_202 ( struct V_2 * V_3 ,
T_3 V_839 )
{
T_3 V_538 = 0 ;
while ( ( V_839 & ( 1 << V_538 ) ) == 0 )
V_538 ++ ;
return V_538 ;
}
int F_203 ( struct V_2 * V_3 ,
enum V_840 V_538 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 , V_721 , V_41 ;
int V_74 ;
if ( V_538 == V_841 ) {
if ( ( ! V_4 -> V_350 ) &&
V_4 -> V_554 . V_555 ) {
V_721 = 0 ;
V_202 = V_4 -> V_554 . V_555 ;
while ( V_202 >>= 1 )
V_721 ++ ;
if ( V_721 ) {
V_74 = F_93 ( V_3 , V_538 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_370 ; V_41 ++ ) {
V_202 = ( F_24 ( V_842 ) &
V_843 ) >> V_844 ;
if ( V_202 == V_721 )
break;
F_85 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_326 ) &&
V_4 -> V_554 . V_725 ) {
V_721 = 0 ;
V_202 = V_4 -> V_554 . V_725 ;
while ( V_202 >>= 1 )
V_721 ++ ;
if ( V_721 ) {
V_74 = F_91 ( V_3 , V_721 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_370 ; V_41 ++ ) {
V_202 = ( F_24 ( V_845 ) &
V_846 ) >> V_847 ;
if ( V_202 == V_721 )
break;
F_85 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_330 ) &&
V_4 -> V_554 . V_730 ) {
V_721 = 0 ;
V_202 = V_4 -> V_554 . V_730 ;
while ( V_202 >>= 1 )
V_721 ++ ;
if ( V_721 ) {
V_74 = F_92 ( V_3 , V_721 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_370 ; V_41 ++ ) {
V_202 = ( F_24 ( V_845 ) &
V_848 ) >> V_849 ;
if ( V_202 == V_721 )
break;
F_85 ( 1 ) ;
}
}
}
} else if ( V_538 == V_850 ) {
if ( ( ! V_4 -> V_326 ) &&
V_4 -> V_554 . V_725 ) {
V_721 = F_202 ( V_3 ,
V_4 -> V_554 . V_725 ) ;
V_74 = F_91 ( V_3 , V_721 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_370 ; V_41 ++ ) {
V_202 = ( F_24 ( V_845 ) &
V_846 ) >> V_847 ;
if ( V_202 == V_721 )
break;
F_85 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_330 ) &&
V_4 -> V_554 . V_730 ) {
V_721 = F_202 ( V_3 ,
V_4 -> V_554 . V_730 ) ;
V_74 = F_92 ( V_3 , V_721 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_370 ; V_41 ++ ) {
V_202 = ( F_24 ( V_845 ) &
V_848 ) >> V_849 ;
if ( V_202 == V_721 )
break;
F_85 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_350 ) &&
V_4 -> V_554 . V_555 ) {
V_721 = F_202 ( V_3 ,
V_4 -> V_554 . V_555 ) ;
V_74 = F_93 ( V_3 , V_721 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_370 ; V_41 ++ ) {
V_202 = ( F_24 ( V_842 ) &
V_843 ) >> V_844 ;
if ( V_202 == V_721 )
break;
F_85 ( 1 ) ;
}
}
} else if ( V_538 == V_851 ) {
if ( ! V_4 -> V_350 ) {
T_5 V_149 ;
V_149 = F_32 ( V_3 ,
V_852 ) ;
if ( V_149 != V_152 )
return - V_45 ;
}
V_74 = F_193 ( V_3 ) ;
if ( V_74 )
return V_74 ;
}
V_3 -> V_5 . V_6 . V_853 = V_538 ;
return 0 ;
}
static int F_204 ( struct V_2 * V_3 ,
struct V_854 * V_292 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_41 , V_102 , V_103 ;
T_3 V_855 ;
for ( V_41 = 0 , V_102 = V_292 -> V_856 ; V_41 < V_292 -> V_856 ; V_41 ++ ) {
if ( V_102 >= V_857 )
return - V_45 ;
switch( V_292 -> V_858 [ V_41 ] . V_859 << 2 ) {
case V_860 :
V_855 = F_25 ( V_861 ) ;
V_292 -> V_858 [ V_102 ] . V_859 = V_861 >> 2 ;
V_292 -> V_858 [ V_102 ] . V_862 = V_863 >> 2 ;
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
V_292 -> V_865 [ V_103 ] . V_866 [ V_102 ] =
( ( V_855 & 0xffff0000 ) ) | ( ( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xffff0000 ) >> 16 ) ;
}
V_102 ++ ;
if ( V_102 >= V_857 )
return - V_45 ;
V_855 = F_25 ( V_867 ) ;
V_292 -> V_858 [ V_102 ] . V_859 = V_867 >> 2 ;
V_292 -> V_858 [ V_102 ] . V_862 = V_868 >> 2 ;
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
V_292 -> V_865 [ V_103 ] . V_866 [ V_102 ] =
( V_855 & 0xffff0000 ) | ( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0x0000ffff ) ;
if ( ! V_4 -> V_177 )
V_292 -> V_865 [ V_103 ] . V_866 [ V_102 ] |= 0x100 ;
}
V_102 ++ ;
if ( V_102 > V_857 )
return - V_45 ;
if ( ! V_4 -> V_177 ) {
V_292 -> V_858 [ V_102 ] . V_859 = V_869 >> 2 ;
V_292 -> V_858 [ V_102 ] . V_862 = V_869 >> 2 ;
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
V_292 -> V_865 [ V_103 ] . V_866 [ V_102 ] =
( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xffff0000 ) >> 16 ;
}
V_102 ++ ;
if ( V_102 > V_857 )
return - V_45 ;
}
break;
case V_870 :
V_855 = F_25 ( V_871 ) ;
V_292 -> V_858 [ V_102 ] . V_859 = V_871 >> 2 ;
V_292 -> V_858 [ V_102 ] . V_862 = V_872 >> 2 ;
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
V_292 -> V_865 [ V_103 ] . V_866 [ V_102 ] =
( V_855 & 0xffff0000 ) | ( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0x0000ffff ) ;
}
V_102 ++ ;
if ( V_102 > V_857 )
return - V_45 ;
break;
default:
break;
}
}
V_292 -> V_856 = V_102 ;
return 0 ;
}
static bool F_205 ( T_2 V_873 , T_2 * V_874 )
{
bool V_208 = true ;
switch( V_873 ) {
case V_875 >> 2 :
* V_874 = V_876 >> 2 ;
break;
case V_877 >> 2 :
* V_874 = V_878 >> 2 ;
break;
case V_879 >> 2 :
* V_874 = V_880 >> 2 ;
break;
case V_881 >> 2 :
* V_874 = V_882 >> 2 ;
break;
case V_883 >> 2 :
* V_874 = V_884 >> 2 ;
break;
case V_885 >> 2 :
* V_874 = V_886 >> 2 ;
break;
case V_887 >> 2 :
* V_874 = V_888 >> 2 ;
break;
case V_889 >> 2 :
* V_874 = V_890 >> 2 ;
break;
case V_891 >> 2 :
* V_874 = V_892 >> 2 ;
break;
case V_893 >> 2 :
* V_874 = V_894 >> 2 ;
break;
case V_895 >> 2 :
* V_874 = V_896 >> 2 ;
break;
case V_897 >> 2 :
* V_874 = V_898 >> 2 ;
break;
case V_899 >> 2 :
* V_874 = V_900 >> 2 ;
break;
case V_901 >> 2 :
* V_874 = V_902 >> 2 ;
break;
case V_861 >> 2 :
* V_874 = V_863 >> 2 ;
break;
case V_867 >> 2 :
* V_874 = V_868 >> 2 ;
break;
case V_871 >> 2 :
* V_874 = V_872 >> 2 ;
break;
case V_903 >> 2 :
* V_874 = V_904 >> 2 ;
break;
case V_905 >> 2 :
* V_874 = V_906 >> 2 ;
break;
case V_907 >> 2 :
* V_874 = V_908 >> 2 ;
break;
default:
V_208 = false ;
break;
}
return V_208 ;
}
static void F_206 ( struct V_854 * V_292 )
{
T_1 V_41 , V_102 ;
for ( V_41 = 0 ; V_41 < V_292 -> V_856 ; V_41 ++ ) {
for ( V_102 = 1 ; V_102 < V_292 -> V_864 ; V_102 ++ ) {
if ( V_292 -> V_865 [ V_102 - 1 ] . V_866 [ V_41 ] !=
V_292 -> V_865 [ V_102 ] . V_866 [ V_41 ] ) {
V_292 -> V_909 |= 1 << V_41 ;
break;
}
}
}
}
static void F_207 ( struct V_854 * V_292 )
{
T_3 V_41 ;
T_2 V_910 ;
for ( V_41 = 0 ; V_41 < V_292 -> V_856 ; V_41 ++ ) {
V_292 -> V_858 [ V_41 ] . V_862 =
F_205 ( V_292 -> V_858 [ V_41 ] . V_859 , & V_910 ) ?
V_910 : V_292 -> V_858 [ V_41 ] . V_859 ;
}
}
static int F_208 ( const struct V_911 * V_292 ,
struct V_854 * V_912 )
{
T_1 V_41 , V_102 ;
if ( V_292 -> V_856 > V_857 )
return - V_45 ;
if ( V_292 -> V_864 > V_913 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_292 -> V_856 ; V_41 ++ )
V_912 -> V_858 [ V_41 ] . V_859 = V_292 -> V_858 [ V_41 ] . V_859 ;
V_912 -> V_856 = V_292 -> V_856 ;
for ( V_41 = 0 ; V_41 < V_292 -> V_864 ; V_41 ++ ) {
V_912 -> V_865 [ V_41 ] . V_914 =
V_292 -> V_865 [ V_41 ] . V_914 ;
for ( V_102 = 0 ; V_102 < V_292 -> V_856 ; V_102 ++ )
V_912 -> V_865 [ V_41 ] . V_866 [ V_102 ] =
V_292 -> V_865 [ V_41 ] . V_866 [ V_102 ] ;
}
V_912 -> V_864 = V_292 -> V_864 ;
return 0 ;
}
static int F_209 ( struct V_2 * V_3 ,
struct V_854 * V_292 )
{
T_1 V_41 , V_103 ;
T_3 V_202 ;
bool V_519 ;
V_202 = F_25 ( V_521 ) ;
V_519 = ( ( V_202 & 0x0000f00 ) == 0x300 ) ? true : false ;
if ( V_519 &&
( ( V_3 -> V_13 -> V_14 == 0x67B0 ) ||
( V_3 -> V_13 -> V_14 == 0x67B1 ) ) ) {
for ( V_41 = 0 ; V_41 < V_292 -> V_856 ; V_41 ++ ) {
if ( V_292 -> V_856 >= V_857 )
return - V_45 ;
switch( V_292 -> V_858 [ V_41 ] . V_859 >> 2 ) {
case V_860 :
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
if ( ( V_292 -> V_865 [ V_103 ] . V_914 == 125000 ) ||
( V_292 -> V_865 [ V_103 ] . V_914 == 137500 ) )
V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] =
( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xFFFFFFF8 ) |
0x00000007 ;
}
break;
case V_899 :
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
if ( ( V_292 -> V_865 [ V_103 ] . V_914 == 125000 ) ||
( V_292 -> V_865 [ V_103 ] . V_914 == 137500 ) )
V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] =
( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xFFFF0F00 ) |
0x0000D0DD ;
}
break;
case V_901 :
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
if ( ( V_292 -> V_865 [ V_103 ] . V_914 == 125000 ) ||
( V_292 -> V_865 [ V_103 ] . V_914 == 137500 ) )
V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] =
( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xFFFF0F00 ) |
0x0000D0DD ;
}
break;
case V_907 :
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
if ( ( V_292 -> V_865 [ V_103 ] . V_914 == 125000 ) ||
( V_292 -> V_865 [ V_103 ] . V_914 == 137500 ) )
V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] = 0 ;
}
break;
case V_885 :
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
if ( V_292 -> V_865 [ V_103 ] . V_914 == 125000 )
V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] =
( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xFFE0FE0F ) |
0x000C0140 ;
else if ( V_292 -> V_865 [ V_103 ] . V_914 == 137500 )
V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] =
( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xFFE0FE0F ) |
0x000C0150 ;
}
break;
case V_887 :
for ( V_103 = 0 ; V_103 < V_292 -> V_864 ; V_103 ++ ) {
if ( V_292 -> V_865 [ V_103 ] . V_914 == 125000 )
V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] =
( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xFFFFFFE0 ) |
0x00000030 ;
else if ( V_292 -> V_865 [ V_103 ] . V_914 == 137500 )
V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] =
( V_292 -> V_865 [ V_103 ] . V_866 [ V_41 ] & 0xFFFFFFE0 ) |
0x00000035 ;
}
break;
default:
break;
}
}
F_27 ( V_915 , 3 ) ;
V_202 = F_25 ( V_916 ) ;
V_202 = ( V_202 & 0xFFF8FFFF ) | ( 1 << 16 ) ;
F_27 ( V_915 , 3 ) ;
F_27 ( V_916 , V_202 ) ;
}
return 0 ;
}
static int F_210 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_911 * V_292 ;
struct V_854 * V_912 = & V_4 -> V_917 ;
T_1 V_918 = F_211 ( V_3 ) ;
int V_74 ;
V_292 = F_212 ( sizeof( struct V_911 ) , V_919 ) ;
if ( ! V_292 )
return - V_920 ;
F_27 ( V_876 , F_25 ( V_875 ) ) ;
F_27 ( V_886 , F_25 ( V_885 ) ) ;
F_27 ( V_878 , F_25 ( V_877 ) ) ;
F_27 ( V_880 , F_25 ( V_879 ) ) ;
F_27 ( V_882 , F_25 ( V_881 ) ) ;
F_27 ( V_884 , F_25 ( V_883 ) ) ;
F_27 ( V_892 , F_25 ( V_891 ) ) ;
F_27 ( V_894 , F_25 ( V_893 ) ) ;
F_27 ( V_888 , F_25 ( V_887 ) ) ;
F_27 ( V_890 , F_25 ( V_889 ) ) ;
F_27 ( V_863 , F_25 ( V_861 ) ) ;
F_27 ( V_868 , F_25 ( V_867 ) ) ;
F_27 ( V_872 , F_25 ( V_871 ) ) ;
F_27 ( V_900 , F_25 ( V_899 ) ) ;
F_27 ( V_902 , F_25 ( V_901 ) ) ;
F_27 ( V_896 , F_25 ( V_895 ) ) ;
F_27 ( V_898 , F_25 ( V_897 ) ) ;
F_27 ( V_904 , F_25 ( V_903 ) ) ;
F_27 ( V_906 , F_25 ( V_905 ) ) ;
F_27 ( V_908 , F_25 ( V_907 ) ) ;
V_74 = F_213 ( V_3 , V_918 , V_292 ) ;
if ( V_74 )
goto V_921;
V_74 = F_208 ( V_292 , V_912 ) ;
if ( V_74 )
goto V_921;
F_207 ( V_912 ) ;
V_74 = F_209 ( V_3 , V_912 ) ;
if ( V_74 )
goto V_921;
V_74 = F_204 ( V_3 , V_912 ) ;
if ( V_74 )
goto V_921;
F_206 ( V_912 ) ;
V_921:
F_214 ( V_292 ) ;
return V_74 ;
}
static int F_215 ( struct V_2 * V_3 ,
T_16 * V_917 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 , V_102 ;
for ( V_41 = 0 , V_102 = 0 ; V_102 < V_4 -> V_917 . V_856 ; V_102 ++ ) {
if ( V_4 -> V_917 . V_909 & ( 1 << V_102 ) ) {
if ( V_41 >= V_857 )
return - V_45 ;
V_917 -> V_910 [ V_41 ] . V_862 = F_9 ( V_4 -> V_917 . V_858 [ V_102 ] . V_862 ) ;
V_917 -> V_910 [ V_41 ] . V_859 = F_9 ( V_4 -> V_917 . V_858 [ V_102 ] . V_859 ) ;
V_41 ++ ;
}
}
V_917 -> V_856 = ( T_1 ) V_41 ;
return 0 ;
}
static void F_216 ( const struct V_922 * V_923 ,
T_17 * V_132 ,
T_3 V_864 , T_3 V_909 )
{
T_3 V_41 , V_102 ;
for ( V_41 = 0 , V_102 = 0 ; V_102 < V_864 ; V_102 ++ ) {
if ( V_909 & ( 1 << V_102 ) ) {
V_132 -> V_57 [ V_41 ] = F_17 ( V_923 -> V_866 [ V_102 ] ) ;
V_41 ++ ;
}
}
}
static void F_217 ( struct V_2 * V_3 ,
const T_3 V_517 ,
T_17 * V_924 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 = 0 ;
for( V_41 = 0 ; V_41 < V_4 -> V_917 . V_864 ; V_41 ++ ) {
if ( V_517 <= V_4 -> V_917 . V_865 [ V_41 ] . V_914 )
break;
}
if ( ( V_41 == V_4 -> V_917 . V_864 ) && ( V_41 > 0 ) )
-- V_41 ;
F_216 ( & V_4 -> V_917 . V_865 [ V_41 ] ,
V_924 , V_4 -> V_917 . V_856 ,
V_4 -> V_917 . V_909 ) ;
}
static void F_218 ( struct V_2 * V_3 ,
T_16 * V_917 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_97 . V_534 . V_46 ; V_41 ++ )
F_217 ( V_3 ,
V_4 -> V_97 . V_534 . V_535 [ V_41 ] . V_57 ,
& V_917 -> V_132 [ V_41 ] ) ;
}
static int F_219 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
memset ( & V_4 -> V_925 , 0 , sizeof( T_16 ) ) ;
V_74 = F_215 ( V_3 , & V_4 -> V_925 ) ;
if ( V_74 )
return V_74 ;
F_218 ( V_3 , & V_4 -> V_925 ) ;
return F_19 ( V_3 ,
V_4 -> V_376 ,
( T_1 * ) & V_4 -> V_925 ,
sizeof( T_16 ) ,
V_4 -> V_80 ) ;
}
static int F_220 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! ( V_4 -> V_325 & V_331 ) )
return 0 ;
memset ( & V_4 -> V_925 , 0 , sizeof( T_16 ) ) ;
F_218 ( V_3 , & V_4 -> V_925 ) ;
return F_19 ( V_3 ,
V_4 -> V_376 +
F_12 ( T_16 , V_132 [ 0 ] ) ,
( T_1 * ) & V_4 -> V_925 . V_132 [ 0 ] ,
sizeof( T_17 ) *
V_4 -> V_97 . V_534 . V_46 ,
V_4 -> V_80 ) ;
}
static void F_221 ( struct V_2 * V_3 )
{
T_3 V_202 = F_24 ( V_317 ) ;
V_202 |= V_926 ;
F_26 ( V_317 , V_202 ) ;
}
static enum V_927 F_222 ( struct V_2 * V_3 ,
struct V_9 * V_810 )
{
struct V_8 * V_692 = F_2 ( V_810 ) ;
int V_41 ;
T_2 V_928 , V_929 = 0 ;
for ( V_41 = 0 ; V_41 < V_692 -> V_196 ; V_41 ++ ) {
V_928 = V_692 -> V_197 [ V_41 ] . V_733 ;
if ( V_929 < V_928 )
V_929 = V_928 ;
}
return V_929 ;
}
static T_2 F_223 ( struct V_2 * V_3 )
{
T_3 V_930 = 0 ;
V_930 = F_224 ( V_931 ) & V_932 ;
V_930 >>= V_933 ;
return ( T_2 ) V_930 ;
}
static int F_225 ( struct V_2 * V_3 )
{
T_3 V_934 = 0 ;
V_934 = F_224 ( V_935 ) & V_936 ;
V_934 >>= V_937 ;
switch ( V_934 ) {
case V_938 :
return 1 ;
case V_939 :
return 2 ;
case V_940 :
return 4 ;
case V_941 :
return 8 ;
case V_942 :
return 12 ;
case V_943 :
case V_944 :
default:
return 16 ;
}
}
static void F_226 ( struct V_2 * V_3 ,
struct V_9 * V_835 ,
struct V_9 * V_836 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_927 V_945 =
F_222 ( V_3 , V_835 ) ;
enum V_927 V_946 ;
if ( V_4 -> V_947 == V_948 )
V_946 = F_222 ( V_3 , V_836 ) ;
else
V_946 = V_4 -> V_947 ;
V_4 -> V_947 = V_948 ;
V_4 -> V_949 = false ;
if ( V_945 > V_946 ) {
switch ( V_945 ) {
#ifdef F_227
case V_950 :
if ( F_228 ( V_3 , V_951 , false ) == 0 )
break;
V_4 -> V_947 = V_952 ;
if ( V_946 == V_952 )
break;
case V_952 :
if ( F_228 ( V_3 , V_953 , false ) == 0 )
break;
#endif
default:
V_4 -> V_947 = F_223 ( V_3 ) ;
break;
}
} else {
if ( V_945 < V_946 )
V_4 -> V_949 = true ;
}
}
static void F_229 ( struct V_2 * V_3 ,
struct V_9 * V_835 ,
struct V_9 * V_836 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_927 V_945 =
F_222 ( V_3 , V_835 ) ;
T_1 V_954 ;
if ( V_4 -> V_949 ) {
if ( V_945 == V_950 )
V_954 = V_951 ;
else if ( V_945 == V_952 )
V_954 = V_953 ;
else
V_954 = V_955 ;
if ( ( V_954 == V_955 ) &&
( F_223 ( V_3 ) > 0 ) )
return;
#ifdef F_227
F_228 ( V_3 , V_954 , false ) ;
#endif
}
}
static int F_230 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_460 * V_743 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
struct V_460 * V_956 =
& V_3 -> V_5 . V_6 . V_42 . V_473 ;
struct V_460 * V_957 =
& V_3 -> V_5 . V_6 . V_42 . V_478 ;
if ( V_743 == NULL )
return - V_45 ;
if ( V_743 -> V_46 < 1 )
return - V_45 ;
if ( V_956 == NULL )
return - V_45 ;
if ( V_956 -> V_46 < 1 )
return - V_45 ;
if ( V_957 == NULL )
return - V_45 ;
if ( V_957 -> V_46 < 1 )
return - V_45 ;
V_4 -> V_664 = V_743 -> V_44 [ 0 ] . V_466 ;
V_4 -> V_958 =
V_743 -> V_44 [ V_743 -> V_46 - 1 ] . V_466 ;
V_4 -> V_682 = V_957 -> V_44 [ 0 ] . V_466 ;
V_4 -> V_959 =
V_957 -> V_44 [ V_957 -> V_46 - 1 ] . V_466 ;
V_3 -> V_5 . V_6 . V_42 . V_194 . V_181 =
V_743 -> V_44 [ V_743 -> V_46 - 1 ] . V_499 ;
V_3 -> V_5 . V_6 . V_42 . V_194 . V_182 =
V_956 -> V_44 [ V_743 -> V_46 - 1 ] . V_499 ;
V_3 -> V_5 . V_6 . V_42 . V_194 . V_32 =
V_743 -> V_44 [ V_743 -> V_46 - 1 ] . V_466 ;
V_3 -> V_5 . V_6 . V_42 . V_194 . V_302 =
V_957 -> V_44 [ V_957 -> V_46 - 1 ] . V_466 ;
return 0 ;
}
static void F_231 ( struct V_2 * V_3 , T_2 * V_32 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_960 * V_961 = & V_4 -> V_303 ;
T_3 V_962 ;
for ( V_962 = 0 ; V_962 < V_961 -> V_46 ; V_962 ++ ) {
if ( V_961 -> V_300 [ V_962 ] == * V_32 ) {
* V_32 = V_961 -> V_307 [ V_962 ] ;
break;
}
}
}
static void F_232 ( struct V_2 * V_3 , T_2 * V_302 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_960 * V_961 = & V_4 -> V_304 ;
T_3 V_962 ;
for ( V_962 = 0 ; V_962 < V_961 -> V_46 ; V_962 ++ ) {
if ( V_961 -> V_300 [ V_962 ] == * V_302 ) {
* V_302 = V_961 -> V_307 [ V_962 ] ;
break;
}
}
}
static void F_233 ( struct V_2 * V_3 ,
struct V_460 * V_292 )
{
T_3 V_41 ;
if ( V_292 ) {
for ( V_41 = 0 ; V_41 < V_292 -> V_46 ; V_41 ++ )
F_231 ( V_3 , & V_292 -> V_44 [ V_41 ] . V_466 ) ;
}
}
static void F_234 ( struct V_2 * V_3 ,
struct V_460 * V_292 )
{
T_3 V_41 ;
if ( V_292 ) {
for ( V_41 = 0 ; V_41 < V_292 -> V_46 ; V_41 ++ )
F_232 ( V_3 , & V_292 -> V_44 [ V_41 ] . V_466 ) ;
}
}
static void F_235 ( struct V_2 * V_3 ,
struct V_834 * V_292 )
{
T_3 V_41 ;
if ( V_292 ) {
for ( V_41 = 0 ; V_41 < V_292 -> V_46 ; V_41 ++ )
F_231 ( V_3 , & V_292 -> V_44 [ V_41 ] . V_466 ) ;
}
}
static void F_236 ( struct V_2 * V_3 ,
struct V_963 * V_292 )
{
T_3 V_41 ;
if ( V_292 ) {
for ( V_41 = 0 ; V_41 < V_292 -> V_46 ; V_41 ++ )
F_231 ( V_3 , & V_292 -> V_44 [ V_41 ] . V_466 ) ;
}
}
static void F_237 ( struct V_2 * V_3 ,
struct V_505 * V_292 )
{
T_3 V_41 ;
if ( V_292 ) {
for ( V_41 = 0 ; V_41 < V_292 -> V_46 ; V_41 ++ )
F_231 ( V_3 , & V_292 -> V_44 [ V_41 ] . V_497 ) ;
}
}
static void F_238 ( struct V_2 * V_3 ,
struct V_178 * V_292 )
{
if ( V_292 ) {
F_231 ( V_3 , ( T_2 * ) & V_292 -> V_32 ) ;
F_232 ( V_3 , ( T_2 * ) & V_292 -> V_302 ) ;
}
}
static void F_239 ( struct V_2 * V_3 ,
struct V_745 * V_292 )
{
T_3 V_41 ;
if ( V_292 ) {
for ( V_41 = 0 ; V_41 < V_292 -> V_46 ; V_41 ++ )
F_231 ( V_3 , & V_292 -> V_44 [ V_41 ] . V_32 ) ;
}
}
static void F_240 ( struct V_2 * V_3 )
{
F_233 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_47 ) ;
F_233 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_473 ) ;
F_233 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_814 ) ;
F_234 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_478 ) ;
F_235 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_572 ) ;
F_236 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_559 ) ;
F_233 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_582 ) ;
F_233 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_579 ) ;
F_237 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_631 ) ;
F_238 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_194 ) ;
F_238 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_195 ) ;
F_239 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_43 ) ;
}
static void F_241 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_202 ;
V_202 = F_25 ( V_521 ) ;
if ( ( ( V_202 & V_964 ) >> V_965 ) ==
V_966 )
V_4 -> V_177 = true ;
else
V_4 -> V_177 = false ;
}
static void F_242 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_967 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_968 = * V_10 ;
V_4 -> V_969 = * V_967 ;
V_4 -> V_968 . V_12 = & V_4 -> V_969 ;
}
static void F_243 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_967 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_970 = * V_10 ;
V_4 -> V_971 = * V_967 ;
V_4 -> V_970 . V_12 = & V_4 -> V_971 ;
}
int F_244 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 V_971 = * V_3 -> V_5 . V_6 . V_971 ;
struct V_9 * V_967 = & V_971 ;
F_243 ( V_3 , V_967 ) ;
F_43 ( V_3 , & V_4 -> V_970 ) ;
return 0 ;
}
void F_245 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_967 = & V_4 -> V_970 ;
F_242 ( V_3 , V_967 ) ;
}
void F_246 ( struct V_2 * V_3 )
{
int V_972 ;
V_972 = F_247 ( V_3 ) ;
if ( V_972 )
F_45 ( L_5 ) ;
F_104 ( V_3 ) ;
F_241 ( V_3 ) ;
F_107 ( V_3 ) ;
F_105 ( V_3 ) ;
}
int F_248 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_751 = V_3 -> V_5 . V_6 . V_751 ;
int V_74 ;
if ( F_249 ( V_3 ) )
return - V_45 ;
if ( V_4 -> V_468 != V_498 ) {
F_221 ( V_3 ) ;
V_74 = F_123 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_6 ) ;
return V_74 ;
}
}
if ( V_4 -> V_973 ) {
V_74 = F_210 ( V_3 ) ;
if ( V_74 )
V_4 -> V_973 = false ;
}
if ( V_4 -> V_974 )
F_112 ( V_3 , true ) ;
if ( V_4 -> V_318 )
F_106 ( V_3 , true ) ;
F_113 ( V_3 ) ;
F_116 ( V_3 ) ;
F_118 ( V_3 ) ;
V_74 = F_120 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_7 ) ;
return V_74 ;
}
V_74 = F_103 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_8 ) ;
return V_74 ;
}
V_74 = F_138 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_9 ) ;
return V_74 ;
}
V_74 = F_188 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_10 ) ;
return V_74 ;
}
V_74 = F_135 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_11 ) ;
return V_74 ;
}
if ( V_4 -> V_973 ) {
V_74 = F_219 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_12 ) ;
return V_74 ;
}
}
V_74 = F_18 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_13 ) ;
return V_74 ;
}
F_96 ( V_3 ) ;
F_81 ( V_3 ) ;
V_74 = F_108 ( V_3 , false ) ;
if ( V_74 ) {
F_45 ( L_14 ) ;
return V_74 ;
}
F_89 ( V_3 , true ) ;
V_74 = F_173 ( V_3 , true ) ;
if ( V_74 ) {
F_45 ( L_15 ) ;
return V_74 ;
}
V_74 = F_109 ( V_3 , true ) ;
if ( V_74 ) {
F_45 ( L_16 ) ;
return V_74 ;
}
V_74 = F_86 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_17 ) ;
return V_74 ;
}
V_74 = F_28 ( V_3 , true ) ;
if ( V_74 ) {
F_45 ( L_18 ) ;
return V_74 ;
}
V_74 = F_34 ( V_3 , true ) ;
if ( V_74 ) {
F_45 ( L_19 ) ;
return V_74 ;
}
V_74 = F_31 ( V_3 , true ) ;
if ( V_74 ) {
F_45 ( L_20 ) ;
return V_74 ;
}
V_74 = F_36 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_21 ) ;
return V_74 ;
}
F_80 ( V_3 , V_312 , true ) ;
V_74 = F_35 ( V_3 , true ) ;
if ( V_74 ) {
F_45 ( L_22 ) ;
return V_74 ;
}
F_69 ( V_3 ) ;
F_242 ( V_3 , V_751 ) ;
return 0 ;
}
static int F_250 ( struct V_2 * V_3 )
{
int V_74 ;
V_74 = F_48 ( V_3 , false ) ;
if ( V_74 )
return V_74 ;
V_74 = F_44 ( V_3 , V_288 , V_289 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_48 ( V_3 , true ) ;
if ( V_74 )
return V_74 ;
return V_74 ;
}
int F_251 ( struct V_2 * V_3 )
{
int V_74 ;
V_74 = F_250 ( V_3 ) ;
if ( V_74 )
return V_74 ;
F_38 ( V_3 , true ) ;
return 0 ;
}
void F_252 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_751 = V_3 -> V_5 . V_6 . V_751 ;
F_38 ( V_3 , false ) ;
if ( ! F_249 ( V_3 ) )
return;
F_70 ( V_3 ) ;
if ( V_4 -> V_318 )
F_106 ( V_3 , false ) ;
F_31 ( V_3 , false ) ;
F_34 ( V_3 , false ) ;
F_28 ( V_3 , false ) ;
F_112 ( V_3 , false ) ;
F_80 ( V_3 , V_312 , false ) ;
F_88 ( V_3 ) ;
F_109 ( V_3 , false ) ;
F_173 ( V_3 , false ) ;
F_119 ( V_3 ) ;
F_140 ( V_3 ) ;
F_100 ( V_3 ) ;
F_141 ( V_3 ) ;
F_35 ( V_3 , false ) ;
F_242 ( V_3 , V_751 ) ;
}
int F_253 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_967 = & V_4 -> V_970 ;
struct V_9 * V_975 = & V_4 -> V_968 ;
int V_74 ;
F_194 ( V_3 , V_967 ) ;
if ( V_4 -> V_976 )
F_226 ( V_3 , V_967 , V_975 ) ;
V_74 = F_87 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_23 ) ;
return V_74 ;
}
V_74 = F_195 ( V_3 , V_967 ) ;
if ( V_74 ) {
F_45 ( L_24 ) ;
return V_74 ;
}
V_74 = F_201 ( V_3 , V_967 ) ;
if ( V_74 ) {
F_45 ( L_25 ) ;
return V_74 ;
}
V_74 = F_199 ( V_3 , V_967 , V_975 ) ;
if ( V_74 ) {
F_45 ( L_26 ) ;
return V_74 ;
}
V_74 = F_74 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_27 ) ;
return V_74 ;
}
if ( V_4 -> V_973 ) {
V_74 = F_220 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_28 ) ;
return V_74 ;
}
}
V_74 = F_146 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_29 ) ;
return V_74 ;
}
V_74 = F_82 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_30 ) ;
return V_74 ;
}
V_74 = F_193 ( V_3 ) ;
if ( V_74 ) {
F_45 ( L_31 ) ;
return V_74 ;
}
if ( V_4 -> V_976 )
F_229 ( V_3 , V_967 , V_975 ) ;
return 0 ;
}
void F_254 ( struct V_2 * V_3 )
{
F_110 ( V_3 ) ;
}
static void F_255 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_977 * V_978 ,
T_1 V_979 )
{
V_10 -> V_980 = F_256 ( V_978 -> V_981 ) ;
V_10 -> V_189 = F_257 ( V_978 -> V_982 ) ;
V_10 -> V_983 = F_257 ( V_978 -> V_984 ) ;
if ( V_985 < V_979 ) {
V_10 -> V_562 = F_256 ( V_978 -> V_986 ) ;
V_10 -> V_564 = F_256 ( V_978 -> V_987 ) ;
} else {
V_10 -> V_562 = 0 ;
V_10 -> V_564 = 0 ;
}
if ( V_10 -> V_189 & V_988 )
V_3 -> V_5 . V_6 . V_751 = V_10 ;
if ( V_10 -> V_189 & V_989 )
V_3 -> V_5 . V_6 . V_990 = V_10 ;
}
static void F_258 ( struct V_2 * V_3 ,
struct V_9 * V_10 , int V_732 ,
union V_991 * V_992 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_993 * V_994 = & V_11 -> V_197 [ V_732 ] ;
V_11 -> V_196 = V_732 + 1 ;
V_994 -> V_181 = F_257 ( V_992 -> V_995 . V_996 ) ;
V_994 -> V_181 |= V_992 -> V_995 . V_997 << 16 ;
V_994 -> V_182 = F_257 ( V_992 -> V_995 . V_998 ) ;
V_994 -> V_182 |= V_992 -> V_995 . V_999 << 16 ;
V_994 -> V_733 = F_259 ( V_3 ,
V_4 -> V_1000 ,
V_4 -> V_765 . V_1001 ,
V_992 -> V_995 . V_1002 ) ;
V_994 -> V_812 = F_260 ( V_3 ,
V_4 -> V_765 . V_1003 ,
F_257 ( V_992 -> V_995 . V_1004 ) ) ;
if ( V_10 -> V_189 & V_1005 ) {
V_4 -> V_1006 = V_994 -> V_733 ;
}
if ( V_10 -> V_983 & V_1007 ) {
V_4 -> V_688 . V_689 = true ;
V_4 -> V_688 . V_994 = * V_994 ;
V_4 -> V_688 . V_760 = V_1008 ;
}
if ( V_10 -> V_189 & V_988 ) {
V_994 -> V_182 = V_4 -> V_765 . V_767 ;
V_994 -> V_181 = V_4 -> V_765 . V_766 ;
V_994 -> V_733 = V_4 -> V_765 . V_1001 ;
V_994 -> V_812 = V_4 -> V_765 . V_1003 ;
}
switch ( V_10 -> V_189 & V_190 ) {
case V_191 :
V_4 -> V_736 = true ;
if ( V_4 -> V_737 . V_87 < V_994 -> V_733 )
V_4 -> V_737 . V_87 = V_994 -> V_733 ;
if ( V_4 -> V_737 . V_86 > V_994 -> V_733 )
V_4 -> V_737 . V_86 = V_994 -> V_733 ;
if ( V_4 -> V_739 . V_87 < V_994 -> V_812 )
V_4 -> V_739 . V_87 = V_994 -> V_812 ;
if ( V_4 -> V_739 . V_86 > V_994 -> V_812 )
V_4 -> V_739 . V_86 = V_994 -> V_812 ;
break;
case V_1009 :
V_4 -> V_735 = true ;
if ( V_4 -> V_738 . V_87 < V_994 -> V_733 )
V_4 -> V_738 . V_87 = V_994 -> V_733 ;
if ( V_4 -> V_738 . V_86 > V_994 -> V_733 )
V_4 -> V_738 . V_86 = V_994 -> V_733 ;
if ( V_4 -> V_740 . V_87 < V_994 -> V_812 )
V_4 -> V_740 . V_87 = V_994 -> V_812 ;
if ( V_4 -> V_740 . V_86 > V_994 -> V_812 )
V_4 -> V_740 . V_86 = V_994 -> V_812 ;
break;
default:
break;
}
}
static int F_261 ( struct V_2 * V_3 )
{
struct V_1010 * V_1011 = & V_3 -> V_1011 ;
struct V_977 * V_978 ;
union V_1012 * V_1013 ;
int V_41 , V_102 , V_103 , V_1014 , V_1015 ;
union V_991 * V_992 ;
struct V_1016 * V_1017 ;
struct V_1018 * V_1019 ;
struct V_1020 * V_1021 ;
union V_1022 * V_1022 ;
int V_732 = F_262 ( V_1023 , V_1024 ) ;
T_2 V_1025 ;
T_1 V_1026 , V_1027 ;
T_1 * V_1028 ;
struct V_8 * V_11 ;
if ( ! F_263 ( V_1011 -> V_1029 , V_732 , NULL ,
& V_1026 , & V_1027 , & V_1025 ) )
return - V_45 ;
V_1022 = (union V_1022 * ) ( V_1011 -> V_1029 -> V_1030 + V_1025 ) ;
V_1017 = (struct V_1016 * )
( V_1011 -> V_1029 -> V_1030 + V_1025 +
F_257 ( V_1022 -> V_1031 . V_1032 ) ) ;
V_1019 = (struct V_1018 * )
( V_1011 -> V_1029 -> V_1030 + V_1025 +
F_257 ( V_1022 -> V_1031 . V_1033 ) ) ;
V_1021 = (struct V_1020 * )
( V_1011 -> V_1029 -> V_1030 + V_1025 +
F_257 ( V_1022 -> V_1031 . V_1034 ) ) ;
V_3 -> V_5 . V_6 . V_11 = F_212 ( sizeof( struct V_9 ) *
V_1017 -> V_1035 , V_919 ) ;
if ( ! V_3 -> V_5 . V_6 . V_11 )
return - V_920 ;
V_1028 = ( T_1 * ) V_1017 -> V_1036 ;
for ( V_41 = 0 ; V_41 < V_1017 -> V_1035 ; V_41 ++ ) {
T_1 * V_503 ;
V_1013 = (union V_1012 * ) V_1028 ;
V_1014 = V_1013 -> V_1037 . V_1038 ;
V_978 = (struct V_977 * )
& V_1021 -> V_1039 [ V_1014 ] ;
if ( ! V_3 -> V_5 . V_1013 [ V_41 ] . V_992 )
return - V_45 ;
V_11 = F_212 ( sizeof( struct V_8 ) , V_919 ) ;
if ( V_11 == NULL ) {
F_214 ( V_3 -> V_5 . V_6 . V_11 ) ;
return - V_920 ;
}
V_3 -> V_5 . V_6 . V_11 [ V_41 ] . V_12 = V_11 ;
F_255 ( V_3 , & V_3 -> V_5 . V_6 . V_11 [ V_41 ] ,
V_978 ,
V_1021 -> V_1040 ) ;
V_103 = 0 ;
V_503 = ( T_1 * ) & V_1013 -> V_1037 . V_1041 [ 0 ] ;
for ( V_102 = 0 ; V_102 < V_1013 -> V_1037 . V_1042 ; V_102 ++ ) {
V_1015 = V_503 [ V_102 ] ;
if ( V_1015 >= V_1019 -> V_1035 )
continue;
if ( V_103 >= V_1043 )
break;
V_992 = (union V_991 * )
( ( T_1 * ) & V_1019 -> V_1044 [ 0 ] +
( V_1015 * V_1019 -> V_1040 ) ) ;
F_258 ( V_3 ,
& V_3 -> V_5 . V_6 . V_11 [ V_41 ] , V_103 ,
V_992 ) ;
V_103 ++ ;
}
V_1028 += 2 + V_1013 -> V_1037 . V_1042 ;
}
V_3 -> V_5 . V_6 . V_1045 = V_1017 -> V_1035 ;
for ( V_41 = 0 ; V_41 < V_1046 ; V_41 ++ ) {
T_3 V_181 , V_182 ;
V_1015 = V_3 -> V_5 . V_6 . V_185 [ V_41 ] . V_1047 ;
V_992 = (union V_991 * )
& V_1019 -> V_1044 [ V_1015 * V_1019 -> V_1040 ] ;
V_181 = F_257 ( V_992 -> V_995 . V_996 ) ;
V_181 |= V_992 -> V_995 . V_997 << 16 ;
V_182 = F_257 ( V_992 -> V_995 . V_998 ) ;
V_182 |= V_992 -> V_995 . V_999 << 16 ;
V_3 -> V_5 . V_6 . V_185 [ V_41 ] . V_181 = V_181 ;
V_3 -> V_5 . V_6 . V_185 [ V_41 ] . V_182 = V_182 ;
}
return 0 ;
}
static int F_264 ( struct V_2 * V_3 ,
struct V_1048 * V_537 )
{
struct V_1010 * V_1011 = & V_3 -> V_1011 ;
int V_732 = F_262 ( V_1023 , V_1049 ) ;
T_18 * V_1050 ;
T_1 V_1026 , V_1027 ;
T_2 V_1025 ;
if ( F_263 ( V_1011 -> V_1029 , V_732 , NULL ,
& V_1026 , & V_1027 , & V_1025 ) ) {
V_1050 =
( T_18 * ) ( V_1011 -> V_1029 -> V_1030 +
V_1025 ) ;
V_537 -> V_773 = F_257 ( V_1050 -> V_1051 ) ;
V_537 -> V_769 = F_257 ( V_1050 -> V_1052 ) ;
V_537 -> V_771 = F_257 ( V_1050 -> V_1053 ) ;
V_537 -> V_1001 = F_223 ( V_3 ) ;
V_537 -> V_1003 = F_225 ( V_3 ) ;
V_537 -> V_766 = F_256 ( V_1050 -> V_1054 ) ;
V_537 -> V_767 = F_256 ( V_1050 -> V_1055 ) ;
return 0 ;
}
return - V_45 ;
}
void F_265 ( struct V_2 * V_3 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_5 . V_6 . V_1045 ; V_41 ++ ) {
F_214 ( V_3 -> V_5 . V_6 . V_11 [ V_41 ] . V_12 ) ;
}
F_214 ( V_3 -> V_5 . V_6 . V_11 ) ;
F_214 ( V_3 -> V_5 . V_6 . V_7 ) ;
F_214 ( V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 ) ;
F_266 ( V_3 ) ;
}
int F_267 ( struct V_2 * V_3 )
{
int V_732 = F_262 ( V_1023 , V_1056 ) ;
T_4 * V_97 ;
struct V_1057 V_1058 ;
T_2 V_1025 , V_1059 ;
T_1 V_1026 , V_1027 ;
struct V_1 * V_4 ;
int V_74 ;
T_3 V_145 ;
V_4 = F_212 ( sizeof( struct V_1 ) , V_919 ) ;
if ( V_4 == NULL )
return - V_920 ;
V_3 -> V_5 . V_6 . V_7 = V_4 ;
V_74 = F_268 ( V_3 -> V_1060 , & V_145 ) ;
if ( V_74 )
V_4 -> V_1000 = 0 ;
else
V_4 -> V_1000 = V_145 ;
V_4 -> V_947 = V_948 ;
V_4 -> V_738 . V_87 = V_1061 ;
V_4 -> V_738 . V_86 = V_950 ;
V_4 -> V_737 . V_87 = V_1061 ;
V_4 -> V_737 . V_86 = V_950 ;
V_4 -> V_740 . V_87 = 0 ;
V_4 -> V_740 . V_86 = 16 ;
V_4 -> V_739 . V_87 = 0 ;
V_4 -> V_739 . V_86 = 16 ;
V_74 = F_264 ( V_3 , & V_4 -> V_765 ) ;
if ( V_74 ) {
F_265 ( V_3 ) ;
return V_74 ;
}
V_74 = F_269 ( V_3 ) ;
if ( V_74 ) {
F_265 ( V_3 ) ;
return V_74 ;
}
V_74 = F_270 ( V_3 ) ;
if ( V_74 ) {
F_265 ( V_3 ) ;
return V_74 ;
}
V_74 = F_261 ( V_3 ) ;
if ( V_74 ) {
F_265 ( V_3 ) ;
return V_74 ;
}
V_4 -> V_656 = false ;
V_4 -> V_80 = V_1062 ;
V_4 -> V_722 [ 0 ] = V_1063 ;
V_4 -> V_722 [ 1 ] = V_1063 ;
V_4 -> V_722 [ 2 ] = V_1063 ;
V_4 -> V_722 [ 3 ] = V_1063 ;
V_4 -> V_722 [ 4 ] = V_1063 ;
V_4 -> V_722 [ 5 ] = V_1063 ;
V_4 -> V_722 [ 6 ] = V_1063 ;
V_4 -> V_722 [ 7 ] = V_1063 ;
V_4 -> V_637 = V_1064 ;
V_4 -> V_326 = 0 ;
V_4 -> V_330 = 0 ;
V_4 -> V_350 = 0 ;
V_4 -> V_166 = 0 ;
if ( ( V_3 -> V_13 -> V_14 == 0x6658 ) &&
( V_3 -> V_1065 -> V_1059 == ( V_1066 * 4 ) ) ) {
V_4 -> V_330 = 1 ;
}
V_4 -> V_415 = true ;
V_4 -> V_649 = 40000 ;
V_4 -> V_645 = 40000 ;
V_4 -> V_651 = 40000 ;
V_4 -> V_652 = 40000 ;
F_3 ( V_3 ) ;
V_4 -> V_293 = false ;
V_4 -> V_297 = false ;
V_4 -> V_821 = true ;
V_4 -> V_827 = true ;
F_75 ( V_3 ) ;
F_240 ( V_3 ) ;
F_230 ( V_3 ) ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 =
F_212 ( 4 * sizeof( struct V_1067 ) , V_919 ) ;
if ( ! V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 ) {
F_265 ( V_3 ) ;
return - V_920 ;
}
V_3 -> V_5 . V_6 . V_42 . V_814 . V_46 = 4 ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 [ 0 ] . V_499 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 [ 0 ] . V_466 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 [ 1 ] . V_499 = 36000 ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 [ 1 ] . V_466 = 720 ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 [ 2 ] . V_499 = 54000 ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 [ 2 ] . V_466 = 810 ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 [ 3 ] . V_499 = 72000 ;
V_3 -> V_5 . V_6 . V_42 . V_814 . V_44 [ 3 ] . V_466 = 900 ;
V_3 -> V_5 . V_6 . V_42 . V_1068 = 4 ;
V_3 -> V_5 . V_6 . V_42 . V_1069 = 15000 ;
V_3 -> V_5 . V_6 . V_42 . V_1070 = 200 ;
V_3 -> V_5 . V_6 . V_42 . V_1071 . V_46 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_1071 . V_1072 = NULL ;
V_3 -> V_5 . V_6 . V_42 . V_1073 . V_46 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_1073 . V_1072 = NULL ;
if ( V_3 -> V_27 == V_28 ) {
V_4 -> V_112 . V_786 = 94500 ;
V_4 -> V_112 . V_113 = 95000 ;
V_4 -> V_112 . V_1074 = 104000 ;
} else {
V_4 -> V_112 . V_786 = 99500 ;
V_4 -> V_112 . V_113 = 100000 ;
V_4 -> V_112 . V_1074 = 104000 ;
}
V_4 -> V_646 = false ;
V_97 = & V_4 -> V_98 ;
V_1058 = F_271 ( V_3 , V_1075 ) ;
if ( V_1058 . V_1076 ) {
V_97 -> V_1077 = V_1058 . V_144 ;
V_3 -> V_5 . V_6 . V_48 |= V_323 ;
} else {
V_97 -> V_1077 = V_1078 ;
V_3 -> V_5 . V_6 . V_48 &= ~ V_323 ;
}
V_1058 = F_271 ( V_3 , V_1079 ) ;
if ( V_1058 . V_1076 ) {
V_97 -> V_1080 = V_1058 . V_144 ;
V_3 -> V_5 . V_6 . V_48 |= V_752 ;
} else {
V_97 -> V_1080 = V_1078 ;
V_3 -> V_5 . V_6 . V_48 &= ~ V_752 ;
}
V_1058 = F_271 ( V_3 , V_1081 ) ;
if ( V_1058 . V_1076 ) {
T_3 V_202 = F_24 ( V_1082 ) ;
switch ( V_1058 . V_144 ) {
case 0 :
V_202 &= ~ V_1083 ;
V_202 |= F_272 ( 1 ) ;
break;
case 1 :
V_202 &= ~ V_1083 ;
V_202 |= F_272 ( 2 ) ;
break;
case 2 :
V_202 |= V_1084 ;
break;
case 3 :
V_202 |= V_1085 ;
break;
case 4 :
V_202 |= V_1086 ;
break;
default:
F_273 ( L_32 , V_1058 . V_144 ) ;
break;
}
F_26 ( V_1082 , V_202 ) ;
}
V_4 -> V_468 = V_498 ;
V_4 -> V_475 = V_498 ;
V_4 -> V_480 = V_498 ;
if ( F_274 ( V_3 , V_470 , V_471 ) )
V_4 -> V_468 = V_469 ;
else if ( F_274 ( V_3 , V_470 , V_1087 ) )
V_4 -> V_468 = V_472 ;
if ( V_3 -> V_5 . V_6 . V_48 & V_1088 ) {
if ( F_274 ( V_3 , V_476 , V_471 ) )
V_4 -> V_475 = V_469 ;
else if ( F_274 ( V_3 , V_476 , V_1087 ) )
V_4 -> V_475 = V_472 ;
else
V_3 -> V_5 . V_6 . V_48 &= ~ V_1088 ;
}
if ( V_3 -> V_5 . V_6 . V_48 & V_1089 ) {
if ( F_274 ( V_3 , V_481 , V_471 ) )
V_4 -> V_480 = V_469 ;
else if ( F_274 ( V_3 , V_481 , V_1087 ) )
V_4 -> V_480 = V_472 ;
else
V_3 -> V_5 . V_6 . V_48 &= ~ V_1089 ;
}
V_4 -> V_630 = true ;
#if F_275 ( F_227 )
V_4 -> V_976 =
F_276 ( V_3 ) ;
#else
V_4 -> V_976 = false ;
#endif
if ( F_263 ( V_3 -> V_1011 . V_1029 , V_732 , & V_1059 ,
& V_1026 , & V_1027 , & V_1025 ) ) {
V_4 -> V_431 = true ;
V_4 -> V_600 = true ;
V_4 -> V_974 = true ;
} else {
V_4 -> V_431 = false ;
V_4 -> V_600 = false ;
V_4 -> V_974 = true ;
}
if ( V_3 -> V_5 . V_1090 != V_1091 )
V_4 -> V_318 = true ;
else
V_4 -> V_318 = false ;
V_4 -> V_973 = true ;
V_4 -> V_174 = false ;
if ( ( V_3 -> V_5 . V_6 . V_42 . V_195 . V_181 == 0 ) ||
( V_3 -> V_5 . V_6 . V_42 . V_195 . V_182 == 0 ) )
V_3 -> V_5 . V_6 . V_42 . V_195 =
V_3 -> V_5 . V_6 . V_42 . V_194 ;
V_4 -> V_216 = true ;
return 0 ;
}
void F_277 ( struct V_2 * V_3 ,
struct V_1092 * V_1093 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_10 = & V_4 -> V_968 ;
T_3 V_181 = F_94 ( V_3 ) ;
T_3 V_182 = F_95 ( V_3 ) ;
F_278 ( V_1093 , L_33 , V_4 -> V_646 ? L_34 : L_35 ) ;
F_278 ( V_1093 , L_36 , V_10 -> V_183 ? L_34 : L_35 ) ;
F_278 ( V_1093 , L_37 ,
V_181 , V_182 ) ;
}
void F_279 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_993 * V_994 ;
int V_41 ;
F_280 ( V_10 -> V_189 , V_10 -> V_983 ) ;
F_281 ( V_10 -> V_980 ) ;
F_282 ( L_38 , V_10 -> V_562 , V_10 -> V_564 ) ;
for ( V_41 = 0 ; V_41 < V_11 -> V_196 ; V_41 ++ ) {
V_994 = & V_11 -> V_197 [ V_41 ] ;
F_282 ( L_39 ,
V_41 , V_994 -> V_181 , V_994 -> V_182 , V_994 -> V_733 + 1 , V_994 -> V_812 ) ;
}
F_283 ( V_3 , V_10 ) ;
}
T_3 F_284 ( struct V_2 * V_3 )
{
T_3 V_181 = F_94 ( V_3 ) ;
return V_181 ;
}
T_3 F_285 ( struct V_2 * V_3 )
{
T_3 V_182 = F_95 ( V_3 ) ;
return V_182 ;
}
T_3 F_286 ( struct V_2 * V_3 , bool V_1094 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_1095 = F_2 ( & V_4 -> V_970 ) ;
if ( V_1094 )
return V_1095 -> V_197 [ 0 ] . V_181 ;
else
return V_1095 -> V_197 [ V_1095 -> V_196 - 1 ] . V_181 ;
}
T_3 F_287 ( struct V_2 * V_3 , bool V_1094 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_1095 = F_2 ( & V_4 -> V_970 ) ;
if ( V_1094 )
return V_1095 -> V_197 [ 0 ] . V_182 ;
else
return V_1095 -> V_197 [ V_1095 -> V_196 - 1 ] . V_182 ;
}
