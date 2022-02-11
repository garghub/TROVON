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
case 0x6650 :
case 0x6658 :
case 0x665C :
default:
V_4 -> V_15 = & V_16 ;
break;
case 0x6651 :
case 0x665D :
V_4 -> V_15 = & V_17 ;
break;
case 0x6640 :
V_4 -> V_15 = & V_18 ;
break;
case 0x6641 :
V_4 -> V_15 = & V_19 ;
break;
case 0x67B8 :
case 0x67B0 :
case 0x67A0 :
case 0x67A1 :
case 0x67A2 :
case 0x67A8 :
case 0x67A9 :
case 0x67AA :
case 0x67B9 :
case 0x67BE :
V_4 -> V_15 = & V_20 ;
break;
case 0x67BA :
case 0x67B1 :
V_4 -> V_15 = & V_21 ;
break;
}
V_4 -> V_22 = 0 ;
V_4 -> V_23 = true ;
V_4 -> V_24 = false ;
V_4 -> V_25 = false ;
V_4 -> V_26 = false ;
V_4 -> V_27 = false ;
V_4 -> V_28 = false ;
if ( V_4 -> V_23 ) {
V_4 -> V_24 = true ;
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
T_1 * V_34 = V_4 -> V_35 . V_36 ;
T_1 * V_37 = V_4 -> V_35 . V_38 ;
int V_41 , V_82 , V_83 ;
V_82 = V_83 = V_34 [ 0 ] ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
if ( 0 != V_34 [ V_41 ] ) {
if ( V_82 > V_34 [ V_41 ] )
V_82 = V_34 [ V_41 ] ;
if ( V_83 < V_34 [ V_41 ] )
V_83 = V_34 [ V_41 ] ;
}
if ( 0 != V_37 [ V_41 ] ) {
if ( V_82 > V_37 [ V_41 ] )
V_82 = V_37 [ V_41 ] ;
if ( V_83 < V_37 [ V_41 ] )
V_83 = V_37 [ V_41 ] ;
}
}
if ( ( V_82 == 0 ) || ( V_83 == 0 ) )
return - V_45 ;
V_4 -> V_35 . V_84 = ( T_1 ) V_83 ;
V_4 -> V_35 . V_85 = ( T_1 ) V_82 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_86 = V_4 -> V_35 . V_87 ;
T_2 V_88 = V_4 -> V_35 . V_89 ;
struct V_90 * V_67 =
V_3 -> V_5 . V_6 . V_42 . V_67 ;
V_86 = V_67 -> V_91 / 100 * 256 ;
V_88 = V_67 -> V_92 / 100 * 256 ;
V_4 -> V_35 . V_87 = F_9 ( V_86 ) ;
V_4 -> V_35 . V_89 = F_9 ( V_88 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_58 * V_59 = V_4 -> V_15 ;
T_4 * V_93 = & V_4 -> V_94 ;
struct V_90 * V_67 =
V_3 -> V_5 . V_6 . V_42 . V_67 ;
struct V_95 * V_96 = V_3 -> V_5 . V_6 . V_42 . V_97 ;
int V_41 , V_98 , V_99 ;
const T_2 * V_100 ;
const T_2 * V_101 ;
V_93 -> V_102 = V_67 -> V_103 * 256 ;
V_93 -> V_104 = V_67 -> V_105 * 256 ;
V_93 -> V_106 = ( T_1 ) V_4 -> V_22 ;
V_93 -> V_107 =
( T_1 ) ( V_4 -> V_108 . V_109 / 1000 ) ;
V_93 -> V_110 = 8 ;
V_93 -> V_111 = V_59 -> V_112 ;
if ( V_96 ) {
V_93 -> V_113 = F_9 ( ( T_2 ) V_96 -> V_114 * 256 / 1000 ) ;
V_93 -> V_115 = F_9 ( ( T_2 ) V_96 -> V_116 * 256 ) ;
} else {
V_93 -> V_113 = F_9 ( 0 ) ;
V_93 -> V_115 = F_9 ( 0 ) ;
}
V_93 -> V_117 = F_16 ( V_59 -> V_118 ) ;
V_100 = V_59 -> V_119 ;
V_101 = V_59 -> V_120 ;
for ( V_41 = 0 ; V_41 < V_121 ; V_41 ++ ) {
for ( V_98 = 0 ; V_98 < V_122 ; V_98 ++ ) {
for ( V_99 = 0 ; V_99 < V_123 ; V_99 ++ ) {
V_93 -> V_124 [ V_41 ] [ V_98 ] [ V_99 ] = F_9 ( * V_100 ) ;
V_93 -> V_125 [ V_41 ] [ V_98 ] [ V_99 ] = F_9 ( * V_101 ) ;
V_100 ++ ;
V_101 ++ ;
}
}
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_126 ;
int V_74 ;
if ( V_4 -> V_23 ) {
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_77 ) ,
& V_126 , V_4 -> V_80 ) ;
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
V_74 = F_18 ( V_3 , V_126 ,
( T_1 * ) & V_4 -> V_35 ,
sizeof( V_78 ) , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static void F_19 ( struct V_2 * V_3 , const bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_128 ;
if ( V_4 -> V_25 ) {
V_128 = F_20 ( V_129 ) ;
if ( V_127 )
V_128 |= V_130 ;
else
V_128 &= ~ V_130 ;
F_21 ( V_129 , V_128 ) ;
}
if ( V_4 -> V_26 ) {
V_128 = F_20 ( V_131 ) ;
if ( V_127 )
V_128 |= V_130 ;
else
V_128 &= ~ V_130 ;
F_21 ( V_131 , V_128 ) ;
}
if ( V_4 -> V_27 ) {
V_128 = F_20 ( V_132 ) ;
if ( V_127 )
V_128 |= V_130 ;
else
V_128 &= ~ V_130 ;
F_21 ( V_132 , V_128 ) ;
}
if ( V_4 -> V_28 ) {
V_128 = F_20 ( V_133 ) ;
if ( V_127 )
V_128 |= V_130 ;
else
V_128 &= ~ V_130 ;
F_21 ( V_133 , V_128 ) ;
}
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_134 * V_135 )
{
const struct V_134 * V_136 = V_135 ;
T_3 V_128 ;
T_3 V_137 = 0 ;
if ( V_136 == NULL )
return - V_45 ;
while ( V_136 -> V_138 != 0xFFFFFFFF ) {
if ( V_136 -> type == V_139 ) {
V_137 |= ( ( V_136 -> V_57 << V_136 -> V_140 ) & V_136 -> V_141 ) ;
} else {
switch ( V_136 -> type ) {
case V_142 :
V_128 = F_23 ( V_136 -> V_138 ) ;
break;
case V_143 :
V_128 = F_20 ( V_136 -> V_138 ) ;
break;
default:
V_128 = F_24 ( V_136 -> V_138 << 2 ) ;
break;
}
V_128 &= ~ V_136 -> V_141 ;
V_128 |= ( ( V_136 -> V_57 << V_136 -> V_140 ) & V_136 -> V_141 ) ;
V_128 |= V_137 ;
switch ( V_136 -> type ) {
case V_142 :
F_25 ( V_136 -> V_138 , V_128 ) ;
break;
case V_143 :
F_21 ( V_136 -> V_138 , V_128 ) ;
break;
default:
F_26 ( V_136 -> V_138 << 2 , V_128 ) ;
break;
}
V_137 = 0 ;
}
V_136 ++ ;
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
if ( V_4 -> V_25 || V_4 -> V_26 ||
V_4 -> V_27 || V_4 -> V_28 ) {
F_28 ( V_3 ) ;
if ( V_127 ) {
V_74 = F_22 ( V_3 , V_144 ) ;
if ( V_74 ) {
F_29 ( V_3 ) ;
return V_74 ;
}
}
F_19 ( V_3 , V_127 ) ;
F_29 ( V_3 ) ;
}
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_145 ;
int V_74 = 0 ;
if ( V_127 ) {
V_4 -> V_146 = 0 ;
if ( V_4 -> V_23 ) {
if ( V_4 -> V_29 ) {
V_145 = F_31 ( V_3 , V_147 ) ;
if ( V_145 != V_148 )
V_74 = - V_45 ;
else
V_4 -> V_146 |= V_149 ;
}
if ( V_4 -> V_30 ) {
V_145 = F_31 ( V_3 , V_150 ) ;
if ( V_145 != V_148 )
V_74 = - V_45 ;
else
V_4 -> V_146 |= V_151 ;
}
if ( V_4 -> V_31 ) {
V_145 = F_31 ( V_3 , V_152 ) ;
if ( V_145 != V_148 ) {
V_74 = - V_45 ;
} else {
struct V_90 * V_67 =
V_3 -> V_5 . V_6 . V_42 . V_67 ;
T_3 V_153 =
( T_3 ) ( V_67 -> V_154 * 256 ) ;
V_4 -> V_146 |= V_155 ;
F_32 ( V_3 , V_153 ) ;
}
}
}
} else {
if ( V_4 -> V_23 && V_4 -> V_146 ) {
if ( V_4 -> V_146 & V_151 )
F_31 ( V_3 , V_156 ) ;
if ( V_4 -> V_146 & V_149 )
F_31 ( V_3 , V_157 ) ;
if ( V_4 -> V_146 & V_155 )
F_31 ( V_3 , V_158 ) ;
V_4 -> V_146 = 0 ;
}
}
return V_74 ;
}
static int F_33 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_145 ;
int V_74 = 0 ;
if ( V_4 -> V_24 ) {
if ( V_127 ) {
V_145 = F_31 ( V_3 , V_159 ) ;
if ( V_145 != V_148 ) {
V_74 = - V_45 ;
V_4 -> V_160 = false ;
} else {
V_4 -> V_160 = true ;
}
} else if ( V_4 -> V_160 ) {
F_31 ( V_3 , V_161 ) ;
V_4 -> V_160 = false ;
}
}
return V_74 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_90 * V_67 =
V_3 -> V_5 . V_6 . V_42 . V_67 ;
T_6 V_162 ;
T_6 V_163 ;
int V_74 = 0 ;
bool V_164 = false ;
if ( V_4 -> V_23 &&
( V_4 -> V_146 & V_149 ) ) {
V_162 = V_164 ?
V_3 -> V_5 . V_6 . V_165 : ( - 1 * V_3 -> V_5 . V_6 . V_165 ) ;
V_163 = ( ( 100 + V_162 ) *
( T_6 ) V_67 -> V_105 ) / 100 ;
V_163 *= 256 ;
V_74 = F_35 ( V_3 , ( T_3 ) V_163 ) ;
}
return V_74 ;
}
void F_36 ( struct V_2 * V_3 , bool V_166 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_167 == V_166 )
return;
V_4 -> V_167 = V_166 ;
F_37 ( V_3 , V_166 ) ;
}
bool F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_168 = F_39 ( V_3 ) ;
T_3 V_169 = V_4 -> V_170 ? 450 : 300 ;
if ( V_168 < V_169 )
return true ;
else
return false ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_171 * V_172 ;
bool V_173 ;
T_3 V_174 , V_175 ;
T_3 V_176 , V_177 , V_178 ;
int V_41 ;
if ( ( V_3 -> V_5 . V_6 . V_179 > 1 ) ||
F_38 ( V_3 ) )
V_173 = true ;
else
V_173 = false ;
if ( ( V_10 -> V_180 & V_181 ) == V_182 )
V_4 -> V_183 = true ;
else
V_4 -> V_183 = false ;
if ( V_3 -> V_5 . V_6 . V_184 )
V_172 = & V_3 -> V_5 . V_6 . V_42 . V_185 ;
else
V_172 = & V_3 -> V_5 . V_6 . V_42 . V_186 ;
if ( V_3 -> V_5 . V_6 . V_184 == false ) {
for ( V_41 = 0 ; V_41 < V_11 -> V_187 ; V_41 ++ ) {
if ( V_11 -> V_188 [ V_41 ] . V_175 > V_172 -> V_175 )
V_11 -> V_188 [ V_41 ] . V_175 = V_172 -> V_175 ;
if ( V_11 -> V_188 [ V_41 ] . V_174 > V_172 -> V_174 )
V_11 -> V_188 [ V_41 ] . V_174 = V_172 -> V_174 ;
}
}
F_41 ( & V_3 -> V_5 . V_6 . V_42 . V_47 ,
& V_176 ) ;
F_41 ( & V_3 -> V_5 . V_6 . V_42 . V_189 ,
& V_177 ) ;
F_41 ( & V_3 -> V_5 . V_6 . V_42 . V_190 ,
& V_178 ) ;
for ( V_41 = 0 ; V_41 < V_11 -> V_187 ; V_41 ++ ) {
if ( V_176 ) {
if ( V_11 -> V_188 [ V_41 ] . V_174 > V_176 )
V_11 -> V_188 [ V_41 ] . V_174 = V_176 ;
}
if ( V_177 ) {
if ( V_11 -> V_188 [ V_41 ] . V_175 > V_177 )
V_11 -> V_188 [ V_41 ] . V_175 = V_177 ;
}
if ( V_178 ) {
if ( V_11 -> V_188 [ V_41 ] . V_175 > V_178 )
V_11 -> V_188 [ V_41 ] . V_175 = V_178 ;
}
}
if ( V_173 ) {
V_175 = V_11 -> V_188 [ V_11 -> V_187 - 1 ] . V_175 ;
V_174 = V_11 -> V_188 [ 0 ] . V_174 ;
} else {
V_175 = V_11 -> V_188 [ 0 ] . V_175 ;
V_174 = V_11 -> V_188 [ 0 ] . V_174 ;
}
V_11 -> V_188 [ 0 ] . V_174 = V_174 ;
V_11 -> V_188 [ 0 ] . V_175 = V_175 ;
if ( V_11 -> V_188 [ 1 ] . V_174 < V_11 -> V_188 [ 0 ] . V_174 )
V_11 -> V_188 [ 1 ] . V_174 = V_11 -> V_188 [ 0 ] . V_174 ;
if ( V_173 ) {
if ( V_11 -> V_188 [ 0 ] . V_175 < V_11 -> V_188 [ 1 ] . V_175 )
V_11 -> V_188 [ 0 ] . V_175 = V_11 -> V_188 [ 1 ] . V_175 ;
} else {
if ( V_11 -> V_188 [ 1 ] . V_175 < V_11 -> V_188 [ 0 ] . V_175 )
V_11 -> V_188 [ 1 ] . V_175 = V_11 -> V_188 [ 0 ] . V_175 ;
}
}
static int F_42 ( struct V_2 * V_3 ,
int V_191 , int V_192 )
{
int V_193 = 0 * 1000 ;
int V_194 = 255 * 1000 ;
T_3 V_195 ;
if ( V_193 < V_191 )
V_193 = V_191 ;
if ( V_194 > V_192 )
V_194 = V_192 ;
if ( V_194 < V_193 ) {
F_43 ( L_1 , V_193 , V_194 ) ;
return - V_45 ;
}
V_195 = F_23 ( V_196 ) ;
V_195 &= ~ ( V_197 | V_198 ) ;
V_195 |= F_44 ( V_194 / 1000 ) |
F_45 ( V_193 / 1000 ) ;
F_25 ( V_196 , V_195 ) ;
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DIG_THERM_DPM_MASK;
tmp |= DIG_THERM_DPM(high_temp / 1000);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
return 0 ;
}
static int F_46 ( struct V_2 * V_3 ,
T_2 V_199 , T_3 V_57 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_47 ( V_3 ,
V_4 -> V_200 + V_199 ,
V_57 , V_4 -> V_80 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_4 * V_201 = & V_4 -> V_94 ;
if ( V_4 -> V_202 ) {
T_2 V_195 ;
V_195 = 45 ;
V_201 -> V_203 = F_9 ( V_195 ) ;
V_195 = 30 ;
V_201 -> V_204 = F_9 ( V_195 ) ;
}
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 = 0 ;
T_3 V_205 = 0 ;
if ( V_4 -> V_206 ) {
V_205 = F_16 ( V_4 -> V_205 ) ;
V_74 = F_18 ( V_3 ,
V_4 -> V_207 +
F_12 ( T_4 , V_208 ) ,
( T_1 * ) & V_205 ,
sizeof( T_3 ) , V_4 -> V_80 ) ;
}
return V_74 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_209 , V_210 ;
T_2 V_32 , V_211 ;
int V_41 ;
V_4 -> V_212 . V_46 = 0 ;
V_4 -> V_213 . V_46 = 0 ;
if ( F_51 ( V_3 , & V_209 ) == 0 ) {
for ( V_41 = 0 ; V_41 < V_214 ; V_41 ++ ) {
V_210 = V_215 + V_41 ;
if ( F_52 ( V_3 , & V_32 , & V_211 ,
V_210 ,
V_209 ) == 0 ) {
if ( V_32 != 0 && V_32 != V_210 ) {
V_4 -> V_212 . V_216 [ V_4 -> V_212 . V_46 ] = V_32 ;
V_4 -> V_212 . V_209 [ V_4 -> V_212 . V_46 ] = V_210 ;
V_4 -> V_212 . V_46 ++ ;
}
if ( V_211 != 0 && V_211 != V_210 ) {
V_4 -> V_213 . V_216 [ V_4 -> V_213 . V_46 ] = V_211 ;
V_4 -> V_213 . V_209 [ V_4 -> V_213 . V_46 ] = V_210 ;
V_4 -> V_213 . V_46 ++ ;
}
}
}
}
}
static void F_53 ( struct V_2 * V_3 , T_3 V_217 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
bool V_218 ;
enum V_219 V_220 ;
T_3 V_195 ;
switch ( V_217 ) {
case 0 :
default:
V_218 = false ;
break;
case ( 1 << V_221 ) :
V_218 = true ;
V_220 = V_222 ;
break;
case ( 1 << V_223 ) :
V_218 = true ;
V_220 = V_224 ;
break;
case ( ( 1 << V_223 ) |
( 1 << V_221 ) ) :
V_218 = true ;
V_220 = V_225 ;
break;
}
if ( V_218 ) {
#if 0
tmp = RREG32_SMC(CG_THERMAL_CTRL);
tmp &= DPM_EVENT_SRC_MASK;
tmp |= DPM_EVENT_SRC(dpm_event_src);
WREG32_SMC(CG_THERMAL_CTRL, tmp);
#endif
V_195 = F_23 ( V_226 ) ;
if ( V_4 -> V_227 )
V_195 &= ~ V_228 ;
else
V_195 |= V_228 ;
F_25 ( V_226 , V_195 ) ;
} else {
V_195 = F_23 ( V_226 ) ;
V_195 |= V_228 ;
F_25 ( V_226 , V_195 ) ;
}
}
static void F_54 ( struct V_2 * V_3 ,
enum V_229 V_230 ,
bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_127 ) {
if ( ! ( V_4 -> V_231 & ( 1 << V_230 ) ) ) {
V_4 -> V_231 |= 1 << V_230 ;
F_53 ( V_3 , V_4 -> V_231 ) ;
}
} else {
if ( V_4 -> V_231 & ( 1 << V_230 ) ) {
V_4 -> V_231 &= ~ ( 1 << V_230 ) ;
F_53 ( V_3 , V_4 -> V_231 ) ;
}
}
}
static void F_55 ( struct V_2 * V_3 )
{
if ( V_3 -> V_5 . V_6 . V_48 & V_232 )
F_31 ( V_3 , V_233 ) ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_145 ;
if ( ! V_4 -> V_234 )
return 0 ;
if ( ( ! V_4 -> V_235 ) &&
( V_4 -> V_234 & ( V_236 | V_237 ) ) ) {
V_145 = F_31 ( V_3 , V_238 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
if ( ( ! V_4 -> V_239 ) &&
( V_4 -> V_234 & V_240 ) ) {
V_145 = F_31 ( V_3 , V_241 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
V_4 -> V_234 = 0 ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_145 ;
if ( V_127 ) {
if ( ! V_4 -> V_235 ) {
V_145 = F_31 ( V_3 , V_242 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
if ( ! V_4 -> V_239 ) {
V_145 = F_31 ( V_3 , V_243 ) ;
if ( V_145 != V_148 )
return - V_45 ;
F_58 ( V_244 , V_245 , ~ V_245 ) ;
F_25 ( V_246 , 0x05 ) ;
F_25 ( V_247 , 0x05 ) ;
F_25 ( V_248 , 0x100005 ) ;
F_59 ( 10 ) ;
F_25 ( V_246 , 0x400005 ) ;
F_25 ( V_247 , 0x400005 ) ;
F_25 ( V_248 , 0x500005 ) ;
}
} else {
if ( ! V_4 -> V_235 ) {
V_145 = F_31 ( V_3 , V_249 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
if ( ! V_4 -> V_239 ) {
V_145 = F_31 ( V_3 , V_250 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
}
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_145 ;
int V_74 ;
T_3 V_195 ;
V_195 = F_23 ( V_226 ) ;
V_195 |= V_251 ;
F_25 ( V_226 , V_195 ) ;
V_195 = F_23 ( V_252 ) ;
V_195 |= V_253 ;
F_25 ( V_252 , V_195 ) ;
F_46 ( V_3 , F_12 ( V_254 , V_255 ) , 0x1000 ) ;
F_58 ( V_256 , 0 , ~ V_257 ) ;
V_145 = F_31 ( V_3 , V_258 ) ;
if ( V_145 != V_148 )
return - V_45 ;
V_74 = F_57 ( V_3 , true ) ;
if ( V_74 )
return V_74 ;
if ( ! V_4 -> V_259 ) {
V_145 = F_31 ( V_3 , V_260 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_145 ;
if ( ! V_4 -> V_234 )
return 0 ;
if ( ( ! V_4 -> V_235 ) &&
( V_4 -> V_234 & ( V_236 | V_237 ) ) ) {
V_145 = F_31 ( V_3 , V_261 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
if ( ( ! V_4 -> V_239 ) &&
( V_4 -> V_234 & V_240 ) ) {
V_145 = F_31 ( V_3 , V_262 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_145 ;
int V_74 ;
T_3 V_195 ;
V_195 = F_23 ( V_226 ) ;
V_195 &= ~ V_251 ;
F_25 ( V_226 , V_195 ) ;
V_195 = F_24 ( V_252 ) ;
V_195 &= ~ V_253 ;
F_25 ( V_252 , V_195 ) ;
if ( ! V_4 -> V_259 ) {
V_145 = F_31 ( V_3 , V_263 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
V_74 = F_57 ( V_3 , false ) ;
if ( V_74 )
return V_74 ;
V_145 = F_31 ( V_3 , V_264 ) ;
if ( V_145 != V_148 )
return - V_45 ;
return 0 ;
}
static void F_63 ( struct V_2 * V_3 , bool V_127 )
{
T_3 V_195 = F_23 ( V_252 ) ;
if ( V_127 )
V_195 &= ~ V_265 ;
else
V_195 |= V_265 ;
F_25 ( V_252 , V_195 ) ;
}
static T_5 F_64 ( struct V_2 * V_3 ,
T_7 V_266 , T_3 V_267 )
{
F_26 ( V_268 , V_267 ) ;
return F_31 ( V_3 , V_266 ) ;
}
static T_5 F_65 ( struct V_2 * V_3 ,
T_7 V_266 , T_3 * V_267 )
{
T_5 V_145 ;
V_145 = F_31 ( V_3 , V_266 ) ;
if ( ( V_145 == V_148 ) && V_267 )
* V_267 = F_24 ( V_268 ) ;
return V_145 ;
}
static int F_66 ( struct V_2 * V_3 , T_3 V_269 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_235 ) {
T_5 V_145 =
F_64 ( V_3 , V_270 , V_269 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , T_3 V_269 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_239 ) {
T_5 V_145 =
F_64 ( V_3 , V_271 , V_269 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , T_3 V_269 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_259 ) {
T_5 V_145 =
F_64 ( V_3 , V_272 , V_269 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , T_3 V_269 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_146 & V_155 ) {
T_5 V_145 =
F_64 ( V_3 , V_273 , V_269 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
T_3 V_163 )
{
T_5 V_145 =
F_64 ( V_3 , V_274 , V_163 ) ;
if ( V_145 != V_148 )
return - V_45 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
return F_57 ( V_3 , false ) ;
}
static T_3 F_70 ( struct V_2 * V_3 )
{
T_3 V_275 ;
T_5 V_145 =
F_65 ( V_3 ,
V_276 ,
& V_275 ) ;
if ( V_145 != V_148 )
V_275 = 0 ;
return V_275 ;
}
static T_3 F_71 ( struct V_2 * V_3 )
{
T_3 V_277 ;
T_5 V_145 =
F_65 ( V_3 ,
V_278 ,
& V_277 ) ;
if ( V_145 != V_148 )
V_277 = 0 ;
return V_277 ;
}
static void F_72 ( struct V_2 * V_3 )
{
int V_41 ;
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
F_75 ( V_3 ) ;
for ( V_41 = 0 ; V_41 < V_3 -> V_279 ; V_41 ++ ) {
if ( F_23 ( V_280 ) & V_281 )
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
T_3 V_195 ;
int V_74 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_282 ) ,
& V_195 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_207 = V_195 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_283 ) ,
& V_195 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_200 = V_195 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_284 ) ,
& V_195 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_285 = V_195 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_286 ) ,
& V_195 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_287 = V_195 ;
V_74 = F_11 ( V_3 ,
V_75 +
F_12 ( V_76 , V_288 ) ,
& V_195 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_289 = V_195 ;
return 0 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_290 . V_291 =
F_23 ( V_292 ) ;
V_4 -> V_290 . V_293 =
F_23 ( V_294 ) ;
V_4 -> V_290 . V_295 =
F_23 ( V_296 ) ;
V_4 -> V_290 . V_297 =
F_23 ( V_298 ) ;
V_4 -> V_290 . V_299 =
F_23 ( V_300 ) ;
V_4 -> V_290 . V_301 =
F_23 ( V_302 ) ;
V_4 -> V_290 . V_303 = F_24 ( V_304 ) ;
V_4 -> V_290 . V_305 = F_24 ( V_306 ) ;
V_4 -> V_290 . V_307 = F_24 ( V_308 ) ;
V_4 -> V_290 . V_309 = F_24 ( V_310 ) ;
V_4 -> V_290 . V_311 = F_24 ( V_312 ) ;
V_4 -> V_290 . V_313 = F_24 ( V_314 ) ;
V_4 -> V_290 . V_315 = F_24 ( V_316 ) ;
V_4 -> V_290 . V_317 = F_24 ( V_318 ) ;
V_4 -> V_290 . V_319 = F_24 ( V_320 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_205 = 0 ;
}
static void F_82 ( struct V_2 * V_3 ,
bool V_127 )
{
T_3 V_195 = F_23 ( V_226 ) ;
if ( V_127 )
V_195 &= ~ V_228 ;
else
V_195 |= V_228 ;
F_25 ( V_226 , V_195 ) ;
}
static void F_83 ( struct V_2 * V_3 )
{
T_3 V_195 = F_23 ( V_226 ) ;
V_195 |= V_321 ;
F_25 ( V_226 , V_195 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
bool V_322 )
{
T_7 V_266 = V_322 ? V_323 : V_324 ;
return ( F_31 ( V_3 , V_266 ) == V_148 ) ? 0 : - V_45 ;
}
static int F_85 ( struct V_2 * V_3 ,
bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_127 ) {
if ( V_4 -> V_325 ) {
if ( F_31 ( V_3 , V_326 ) != V_148 )
return - V_45 ;
} else {
if ( F_31 ( V_3 , V_327 ) != V_148 )
return - V_45 ;
}
} else {
if ( V_4 -> V_325 ) {
if ( F_31 ( V_3 , V_327 ) != V_148 )
return - V_45 ;
}
}
return 0 ;
}
static void F_86 ( struct V_2 * V_3 )
{
T_3 V_195 = F_23 ( V_328 ) ;
T_3 V_329 ;
T_3 V_330 ;
T_3 V_331 = V_3 -> clock . V_332 . V_333 ;
T_3 V_334 = F_87 ( V_3 ) ;
T_3 V_168 = F_39 ( V_3 ) ;
V_195 &= ~ V_335 ;
if ( V_3 -> V_5 . V_6 . V_179 > 0 )
V_195 |= F_88 ( V_336 ) ;
else
V_195 |= F_88 ( V_337 ) ;
F_25 ( V_328 , V_195 ) ;
if ( V_334 == 0 )
V_334 = 60 ;
if ( V_168 == 0xffffffff )
V_168 = 500 ;
V_330 = 1000000 / V_334 ;
V_329 =
V_330 - 200 - V_168 ;
V_195 = V_329 * ( V_331 / 100 ) ;
F_25 ( V_338 , V_195 ) ;
F_46 ( V_3 , F_12 ( V_254 , V_339 ) , 0x64 ) ;
F_46 ( V_3 , F_12 ( V_254 , V_340 ) , ( V_330 - V_329 ) ) ;
F_84 ( V_3 , ( V_3 -> V_5 . V_6 . V_179 == 1 ) ) ;
}
static void F_89 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_195 ;
if ( V_127 ) {
if ( V_4 -> V_341 ) {
V_195 = F_23 ( V_226 ) ;
V_195 |= V_342 ;
F_25 ( V_226 , V_195 ) ;
}
} else {
V_195 = F_23 ( V_300 ) ;
V_195 &= ~ V_343 ;
F_25 ( V_300 , V_195 ) ;
V_195 = F_23 ( V_226 ) ;
V_195 &= ~ V_342 ;
F_25 ( V_226 , V_195 ) ;
}
}
static void F_90 ( struct V_2 * V_3 )
{
F_25 ( V_344 , ( F_91 ( V_345 ) | F_92 ( V_346 ) ) ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
T_3 V_195 = F_23 ( V_328 ) ;
V_195 &= ~ ( V_335 | V_347 ) ;
V_195 |= ( F_88 ( V_337 ) |
F_94 ( V_348 ) ) ;
F_25 ( V_328 , V_195 ) ;
}
static void F_95 ( struct V_2 * V_3 )
{
T_3 V_195 ;
V_195 = F_23 ( V_252 ) ;
V_195 &= ~ ( V_349 | V_350 ) ;
F_25 ( V_252 , V_195 ) ;
F_25 ( V_351 , V_352 ) ;
F_25 ( V_353 , V_354 ) ;
F_25 ( V_355 , V_356 ) ;
F_25 ( V_357 , V_358 ) ;
F_25 ( V_359 , V_360 ) ;
F_25 ( V_361 , V_362 ) ;
F_25 ( V_363 , V_364 ) ;
F_25 ( V_365 , V_366 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
T_3 V_195 ;
V_195 = F_23 ( V_252 ) ;
V_195 |= ( V_349 | V_350 ) ;
F_25 ( V_252 , V_195 ) ;
F_25 ( V_351 , 0 ) ;
F_25 ( V_353 , 0 ) ;
F_25 ( V_355 , 0 ) ;
F_25 ( V_357 , 0 ) ;
F_25 ( V_359 , 0 ) ;
F_25 ( V_361 , 0 ) ;
F_25 ( V_363 , 0 ) ;
F_25 ( V_365 , 0 ) ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_41 , V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_279 ; V_41 ++ ) {
if ( F_23 ( V_367 ) & V_368 )
break;
}
F_25 ( V_369 , 1 ) ;
F_78 ( V_3 ) ;
F_77 ( V_3 ) ;
V_74 = F_98 ( V_3 , V_4 -> V_80 ) ;
return V_74 ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_370 * V_371 ,
struct V_372 * V_373 )
{
T_3 V_41 ;
if ( V_371 == NULL )
return - V_45 ;
V_373 -> V_374 = 0 ;
V_373 -> V_375 = 0 ;
V_373 -> V_46 = V_371 -> V_46 ;
for ( V_41 = 0 ; V_41 < V_373 -> V_46 ; V_41 ++ ) {
V_373 -> V_44 [ V_41 ] . V_57 = V_371 -> V_44 [ V_41 ] . V_376 ;
V_373 -> V_44 [ V_41 ] . V_377 = 0 ;
}
return 0 ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
if ( V_4 -> V_378 == V_379 ) {
V_74 = F_101 ( V_3 , V_380 ,
V_381 ,
& V_4 -> V_56 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_378 == V_382 ) {
V_74 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_190 ,
& V_4 -> V_56 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_56 . V_46 > V_383 )
F_102 ( V_3 , V_383 ,
& V_4 -> V_56 ) ;
if ( V_4 -> V_384 == V_379 ) {
V_74 = F_101 ( V_3 , V_385 ,
V_381 ,
& V_4 -> V_386 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_384 == V_382 ) {
V_74 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_189 ,
& V_4 -> V_386 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_386 . V_46 > V_387 )
F_102 ( V_3 , V_387 ,
& V_4 -> V_386 ) ;
if ( V_4 -> V_388 == V_379 ) {
V_74 = F_101 ( V_3 , V_389 ,
V_381 ,
& V_4 -> V_390 ) ;
if ( V_74 )
return V_74 ;
} else if ( V_4 -> V_388 == V_382 ) {
V_74 = F_99 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_391 ,
& V_4 -> V_390 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_390 . V_46 > V_392 )
F_102 ( V_3 , V_392 ,
& V_4 -> V_390 ) ;
return 0 ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_393 * V_373 ,
T_8 * V_394 )
{
int V_74 ;
V_74 = F_104 ( V_3 , V_373 ,
& V_394 -> V_395 ,
& V_394 -> V_396 ) ;
if ( V_74 ) {
V_394 -> V_395 = V_373 -> V_57 * V_33 ;
V_394 -> V_396 = V_373 -> V_57 * V_33 ;
}
V_394 -> V_397 = F_9 ( V_373 -> V_57 * V_33 ) ;
V_394 -> V_395 =
F_9 ( V_394 -> V_395 ) ;
V_394 -> V_396 =
F_9 ( V_394 -> V_396 ) ;
}
static int F_105 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_46 ;
V_201 -> V_398 = V_4 -> V_56 . V_46 ;
for ( V_46 = 0 ; V_46 < V_201 -> V_398 ; V_46 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_56 . V_44 [ V_46 ] ,
& V_201 -> V_399 [ V_46 ] ) ;
if ( V_4 -> V_378 == V_379 )
V_201 -> V_399 [ V_46 ] . V_400 |=
V_4 -> V_56 . V_44 [ V_46 ] . V_377 ;
else
V_201 -> V_399 [ V_46 ] . V_400 = 0 ;
}
V_201 -> V_398 = F_16 ( V_201 -> V_398 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
unsigned int V_46 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_201 -> V_401 = V_4 -> V_386 . V_46 ;
for ( V_46 = 0 ; V_46 < V_201 -> V_401 ; V_46 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_386 . V_44 [ V_46 ] ,
& V_201 -> V_402 [ V_46 ] ) ;
if ( V_4 -> V_384 == V_379 )
V_201 -> V_402 [ V_46 ] . V_400 |=
V_4 -> V_386 . V_44 [ V_46 ] . V_377 ;
else
V_201 -> V_402 [ V_46 ] . V_400 = 0 ;
}
V_201 -> V_401 = F_16 ( V_201 -> V_401 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_46 ;
V_201 -> V_403 = V_4 -> V_390 . V_46 ;
for ( V_46 = 0 ; V_46 < V_201 -> V_403 ; V_46 ++ ) {
F_103 ( V_3 ,
& V_4 -> V_390 . V_44 [ V_46 ] ,
& V_201 -> V_404 [ V_46 ] ) ;
if ( V_4 -> V_388 == V_379 )
V_201 -> V_404 [ V_46 ] . V_400 |=
V_4 -> V_390 . V_44 [ V_46 ] . V_377 ;
else
V_201 -> V_404 [ V_46 ] . V_400 = 0 ;
}
V_201 -> V_403 = F_16 ( V_201 -> V_403 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
int V_74 ;
V_74 = F_105 ( V_3 , V_201 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_106 ( V_3 , V_201 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_107 ( V_3 , V_201 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , T_3 V_175 ,
T_8 * V_405 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 = 0 ;
if ( V_4 -> V_388 != V_406 ) {
for ( V_41 = 0 ; V_41 < V_3 -> V_5 . V_6 . V_42 . V_391 . V_46 ; V_41 ++ ) {
if ( V_175 <= V_3 -> V_5 . V_6 . V_42 . V_391 . V_44 [ V_41 ] . V_407 ) {
V_405 -> V_397 = V_4 -> V_390 . V_44 [ V_41 ] . V_57 ;
break;
}
}
if ( V_41 >= V_3 -> V_5 . V_6 . V_42 . V_391 . V_46 )
return - V_45 ;
}
return - V_45 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_393 * V_373 ,
T_2 * V_408 , T_2 * V_409 )
{
T_2 V_410 , V_411 ;
bool V_412 = false ;
* V_408 = V_373 -> V_57 * V_33 ;
* V_409 = V_373 -> V_57 * V_33 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 == NULL )
return - V_45 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 ) {
for ( V_410 = 0 ; ( T_3 ) V_410 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_410 ++ ) {
if ( V_373 -> V_57 ==
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_410 ] . V_376 ) {
V_412 = true ;
if ( ( T_3 ) V_410 < V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 )
V_411 = V_410 ;
else
V_411 = V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 - 1 ;
* V_409 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_411 ] . V_32 * V_33 ;
* V_408 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_411 ] . V_53 * V_33 ;
break;
}
}
if ( ! V_412 ) {
for ( V_410 = 0 ; ( T_3 ) V_410 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_410 ++ ) {
if ( V_373 -> V_57 <=
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_410 ] . V_376 ) {
V_412 = true ;
if ( ( T_3 ) V_410 < V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 )
V_411 = V_410 ;
else
V_411 = V_3 -> V_5 . V_6 . V_42 . V_43 . V_46 - 1 ;
* V_409 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_411 ] . V_32 * V_33 ;
* V_408 =
V_3 -> V_5 . V_6 . V_42 . V_43 . V_44 [ V_411 ] . V_53 * V_33 ;
break;
}
}
}
}
return 0 ;
}
static void F_110 ( struct V_2 * V_3 ,
const struct V_413 * V_414 ,
T_3 V_174 ,
T_3 * V_415 )
{
unsigned int V_41 ;
* V_415 = 1 ;
for ( V_41 = 0 ; V_41 < V_414 -> V_46 ; V_41 ++ ) {
if ( V_174 < V_414 -> V_44 [ V_41 ] . V_174 ) {
* V_415 = V_41 ;
break;
}
}
}
static void F_111 ( struct V_2 * V_3 ,
const struct V_413 * V_414 ,
T_3 V_175 ,
T_3 * V_415 )
{
unsigned int V_41 ;
* V_415 = 1 ;
for ( V_41 = 0 ; V_41 < V_414 -> V_46 ; V_41 ++ ) {
if ( V_175 < V_414 -> V_44 [ V_41 ] . V_175 ) {
* V_415 = V_41 ;
break;
}
}
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_195 ;
int V_74 ;
V_74 = F_11 ( V_3 , V_4 -> V_289 ,
& V_195 , V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
V_195 &= 0x00FFFFFF ;
V_195 |= V_416 << 24 ;
return F_47 ( V_3 , V_4 -> V_289 ,
V_195 , V_4 -> V_80 ) ;
}
static int F_113 ( struct V_2 * V_3 ,
struct V_370 * V_417 ,
T_3 clock , T_3 * V_405 )
{
T_3 V_41 = 0 ;
if ( V_417 -> V_46 == 0 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_417 -> V_46 ; V_41 ++ ) {
if ( V_417 -> V_44 [ V_41 ] . V_407 >= clock ) {
* V_405 = V_417 -> V_44 [ V_41 ] . V_376 ;
return 0 ;
}
}
* V_405 = V_417 -> V_44 [ V_41 - 1 ] . V_376 ;
return 0 ;
}
static T_1 F_114 ( struct V_2 * V_3 ,
T_3 V_174 , T_3 V_418 )
{
T_3 V_41 ;
T_3 V_195 ;
T_3 V_82 = ( V_418 > V_419 ) ?
V_418 : V_419 ;
if ( V_174 < V_82 )
return 0 ;
for ( V_41 = V_420 ; ; V_41 -- ) {
V_195 = V_174 / ( 1 << V_41 ) ;
if ( V_195 >= V_82 || V_41 == 0 )
break;
}
return ( T_1 ) V_41 ;
}
static int F_115 ( struct V_2 * V_3 )
{
return F_116 ( V_3 , V_421 , V_416 ) ;
}
static int F_117 ( struct V_2 * V_3 )
{
return ( F_31 ( V_3 , V_422 ) == V_148 ) ?
0 : - V_45 ;
}
static int F_118 ( struct V_2 * V_3 )
{
T_3 V_195 ;
V_195 = ( F_23 ( V_423 ) & 0x0000ff00 ) >> 8 ;
if ( V_195 == V_421 )
return 0 ;
return F_116 ( V_3 , V_195 , V_421 ) ;
}
static int F_119 ( struct V_2 * V_3 ,
T_3 V_174 ,
T_3 V_175 ,
T_9 * V_424 )
{
T_3 V_425 ;
T_3 V_426 ;
T_3 V_427 ;
F_120 ( V_3 , V_174 , V_175 ) ;
V_425 = F_24 ( V_428 ) ;
V_426 = F_24 ( V_429 ) ;
V_427 = F_24 ( V_430 ) & V_431 ;
V_424 -> V_432 = F_16 ( V_425 ) ;
V_424 -> V_433 = F_16 ( V_426 ) ;
V_424 -> V_434 = ( T_1 ) V_427 ;
return 0 ;
}
static int F_121 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_10 V_424 ;
T_3 V_41 , V_98 ;
int V_74 = 0 ;
memset ( & V_424 , 0 , sizeof( T_10 ) ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_93 . V_435 . V_46 ; V_41 ++ ) {
for ( V_98 = 0 ; V_98 < V_4 -> V_93 . V_436 . V_46 ; V_98 ++ ) {
V_74 = F_119 ( V_3 ,
V_4 -> V_93 . V_435 . V_437 [ V_41 ] . V_57 ,
V_4 -> V_93 . V_436 . V_437 [ V_98 ] . V_57 ,
& V_424 . V_44 [ V_41 ] [ V_98 ] ) ;
if ( V_74 )
break;
}
}
if ( V_74 == 0 )
V_74 = F_18 ( V_3 ,
V_4 -> V_289 ,
( T_1 * ) & V_424 ,
sizeof( T_10 ) ,
V_4 -> V_80 ) ;
return V_74 ;
}
static int F_122 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_234 == 0 )
return 0 ;
return F_121 ( V_3 ) ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_9 * V_438 )
{
struct V_8 * V_439 = F_2 ( V_438 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_440 = 0 ;
for ( V_440 = 0 ; V_440 < V_3 -> V_5 . V_6 . V_42 . V_47 . V_46 ; V_440 ++ ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ V_440 ] . V_407 >=
V_439 -> V_188 [ 0 ] . V_174 ) {
V_4 -> V_94 . V_441 = V_440 ;
break;
}
}
for ( V_440 = 0 ; V_440 < V_3 -> V_5 . V_6 . V_42 . V_190 . V_46 ; V_440 ++ ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_190 . V_44 [ V_440 ] . V_407 >=
V_439 -> V_188 [ 0 ] . V_175 ) {
V_4 -> V_94 . V_442 = V_440 ;
break;
}
}
}
static T_3 F_124 ( struct V_443 * V_93 )
{
T_3 V_41 ;
T_3 V_444 = 0 ;
for ( V_41 = V_93 -> V_46 ; V_41 > 0 ; V_41 -- ) {
V_444 = V_444 << 1 ;
if ( V_93 -> V_437 [ V_41 - 1 ] . V_445 )
V_444 |= 0x1 ;
else
V_444 &= 0xFFFFFFFE ;
}
return V_444 ;
}
static void F_125 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_446 * V_93 = & V_4 -> V_93 ;
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_93 -> V_447 . V_46 ; V_41 ++ ) {
V_201 -> V_448 [ V_41 ] . V_449 =
( T_1 ) V_93 -> V_447 . V_437 [ V_41 ] . V_57 ;
V_201 -> V_448 [ V_41 ] . V_450 =
F_126 ( V_93 -> V_447 . V_437 [ V_41 ] . V_451 ) ;
V_201 -> V_448 [ V_41 ] . V_452 = 1 ;
V_201 -> V_448 [ V_41 ] . V_453 = F_16 ( 5 ) ;
V_201 -> V_448 [ V_41 ] . V_454 = F_16 ( 30 ) ;
}
V_4 -> V_94 . V_455 = ( T_1 ) V_93 -> V_447 . V_46 ;
V_4 -> V_456 . V_457 =
F_124 ( & V_93 -> V_447 ) ;
}
static int F_127 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
T_3 V_46 ;
struct V_458 V_459 ;
int V_74 = - V_45 ;
V_201 -> V_460 =
V_3 -> V_5 . V_6 . V_42 . V_461 . V_46 ;
for ( V_46 = 0 ; V_46 < V_201 -> V_460 ; V_46 ++ ) {
V_201 -> V_462 [ V_46 ] . V_463 =
V_3 -> V_5 . V_6 . V_42 . V_461 . V_44 [ V_46 ] . V_464 ;
V_201 -> V_462 [ V_46 ] . V_465 =
V_3 -> V_5 . V_6 . V_42 . V_461 . V_44 [ V_46 ] . V_466 ;
V_201 -> V_462 [ V_46 ] . V_467 =
V_3 -> V_5 . V_6 . V_42 . V_461 . V_44 [ V_46 ] . V_376 * V_33 ;
V_201 -> V_462 [ V_46 ] . V_468 = 1 ;
V_74 = F_128 ( V_3 ,
V_469 ,
V_201 -> V_462 [ V_46 ] . V_463 , false , & V_459 ) ;
if ( V_74 )
return V_74 ;
V_201 -> V_462 [ V_46 ] . V_470 = ( T_1 ) V_459 . V_471 ;
V_74 = F_128 ( V_3 ,
V_469 ,
V_201 -> V_462 [ V_46 ] . V_465 , false , & V_459 ) ;
if ( V_74 )
return V_74 ;
V_201 -> V_462 [ V_46 ] . V_472 = ( T_1 ) V_459 . V_471 ;
V_201 -> V_462 [ V_46 ] . V_463 = F_16 ( V_201 -> V_462 [ V_46 ] . V_463 ) ;
V_201 -> V_462 [ V_46 ] . V_465 = F_16 ( V_201 -> V_462 [ V_46 ] . V_465 ) ;
V_201 -> V_462 [ V_46 ] . V_467 = F_9 ( V_201 -> V_462 [ V_46 ] . V_467 ) ;
}
return V_74 ;
}
static int F_129 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
T_3 V_46 ;
struct V_458 V_459 ;
int V_74 = - V_45 ;
V_201 -> V_473 =
V_3 -> V_5 . V_6 . V_42 . V_474 . V_46 ;
for ( V_46 = 0 ; V_46 < V_201 -> V_473 ; V_46 ++ ) {
V_201 -> V_475 [ V_46 ] . V_476 =
V_3 -> V_5 . V_6 . V_42 . V_474 . V_44 [ V_46 ] . V_477 ;
V_201 -> V_475 [ V_46 ] . V_478 =
( T_2 ) V_3 -> V_5 . V_6 . V_42 . V_474 . V_44 [ V_46 ] . V_376 * V_33 ;
V_201 -> V_475 [ V_46 ] . V_479 = 1 ;
V_74 = F_128 ( V_3 ,
V_469 ,
V_201 -> V_475 [ V_46 ] . V_476 , false , & V_459 ) ;
if ( V_74 )
return V_74 ;
V_201 -> V_475 [ V_46 ] . V_480 = ( T_1 ) V_459 . V_471 ;
V_201 -> V_475 [ V_46 ] . V_476 = F_16 ( V_201 -> V_475 [ V_46 ] . V_476 ) ;
V_201 -> V_475 [ V_46 ] . V_478 = F_9 ( V_201 -> V_475 [ V_46 ] . V_478 ) ;
}
return V_74 ;
}
static int F_130 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
T_3 V_46 ;
struct V_458 V_459 ;
int V_74 = - V_45 ;
V_201 -> V_481 = ( T_1 )
( V_3 -> V_5 . V_6 . V_42 . V_482 . V_46 ) ;
for ( V_46 = 0 ; V_46 < V_201 -> V_481 ; V_46 ++ ) {
V_201 -> V_483 [ V_46 ] . V_476 =
V_3 -> V_5 . V_6 . V_42 . V_482 . V_44 [ V_46 ] . V_407 ;
V_201 -> V_483 [ V_46 ] . V_478 =
V_3 -> V_5 . V_6 . V_42 . V_482 . V_44 [ V_46 ] . V_376 ;
V_201 -> V_483 [ V_46 ] . V_479 = 1 ;
V_74 = F_128 ( V_3 ,
V_469 ,
V_201 -> V_483 [ V_46 ] . V_476 , false , & V_459 ) ;
if ( V_74 )
return V_74 ;
V_201 -> V_483 [ V_46 ] . V_480 = ( T_1 ) V_459 . V_471 ;
V_201 -> V_483 [ V_46 ] . V_476 = F_16 ( V_201 -> V_483 [ V_46 ] . V_476 ) ;
V_201 -> V_483 [ V_46 ] . V_478 = F_9 ( V_201 -> V_483 [ V_46 ] . V_478 ) ;
}
return V_74 ;
}
static int F_131 ( struct V_2 * V_3 ,
T_4 * V_201 )
{
T_3 V_46 ;
struct V_458 V_459 ;
int V_74 = - V_45 ;
V_201 -> V_484 =
V_3 -> V_5 . V_6 . V_42 . V_485 . V_46 ;
for ( V_46 = 0 ; V_46 < V_201 -> V_484 ; V_46 ++ ) {
V_201 -> V_486 [ V_46 ] . V_476 =
V_3 -> V_5 . V_6 . V_42 . V_485 . V_44 [ V_46 ] . V_407 ;
V_201 -> V_486 [ V_46 ] . V_478 =
V_3 -> V_5 . V_6 . V_42 . V_485 . V_44 [ V_46 ] . V_376 * V_33 ;
V_201 -> V_486 [ V_46 ] . V_479 = 1 ;
V_74 = F_128 ( V_3 ,
V_469 ,
V_201 -> V_486 [ V_46 ] . V_476 , false , & V_459 ) ;
if ( V_74 )
return V_74 ;
V_201 -> V_486 [ V_46 ] . V_480 = ( T_1 ) V_459 . V_471 ;
V_201 -> V_486 [ V_46 ] . V_476 = F_16 ( V_201 -> V_486 [ V_46 ] . V_476 ) ;
V_201 -> V_486 [ V_46 ] . V_478 = F_9 ( V_201 -> V_486 [ V_46 ] . V_478 ) ;
}
return V_74 ;
}
static int F_132 ( struct V_2 * V_3 ,
T_3 V_487 ,
T_11 * V_175 ,
bool V_488 ,
bool V_489 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_303 = V_4 -> V_290 . V_303 ;
T_3 V_305 = V_4 -> V_290 . V_305 ;
T_3 V_307 = V_4 -> V_290 . V_307 ;
T_3 V_309 = V_4 -> V_290 . V_309 ;
T_3 V_311 = V_4 -> V_290 . V_311 ;
T_3 V_313 = V_4 -> V_290 . V_313 ;
T_3 V_315 = V_4 -> V_290 . V_315 ;
T_3 V_317 = V_4 -> V_290 . V_317 ;
T_3 V_319 = V_4 -> V_290 . V_319 ;
struct V_490 V_491 ;
int V_74 ;
V_74 = F_133 ( V_3 , V_487 , V_488 , & V_491 ) ;
if ( V_74 )
return V_74 ;
V_311 &= ~ V_492 ;
V_311 |= F_134 ( V_491 . V_493 ) ;
V_313 &= ~ ( V_494 | V_495 | V_496 ) ;
V_313 |= F_135 ( V_491 . V_497 ) |
F_136 ( V_491 . V_498 ) | F_137 ( V_491 . V_499 ) ;
V_307 &= ~ V_500 ;
V_307 |= F_138 ( V_491 . V_501 ) ;
if ( V_4 -> V_170 ) {
V_309 &= ~ ( V_502 | V_500 ) ;
V_309 |= F_139 ( V_491 . V_503 ) |
F_138 ( V_491 . V_501 ) ;
}
if ( V_4 -> V_504 ) {
struct V_505 V_506 ;
T_3 V_507 ;
T_3 V_195 ;
T_3 V_508 = V_3 -> clock . V_509 . V_333 ;
if ( V_4 -> V_170 )
V_507 = V_487 * 4 ;
else
V_507 = V_487 * 2 ;
V_195 = ( V_507 / V_508 ) ;
V_195 = V_195 * V_195 ;
if ( F_140 ( V_3 , & V_506 ,
V_510 , V_507 ) ) {
T_3 V_511 = V_508 * 5 / V_506 . V_512 ;
T_3 V_513 = ( T_3 ) ( ( ( ( 131 * V_506 . V_514 * V_506 . V_512 ) / 100 ) * V_195 ) / V_507 ) ;
V_317 &= ~ V_515 ;
V_317 |= F_141 ( V_513 ) ;
V_319 &= ~ V_516 ;
V_319 |= F_142 ( V_511 ) ;
}
}
V_305 &= ~ V_517 ;
V_305 |= F_143 ( V_491 . V_518 ) ;
if ( V_489 )
V_305 |= V_519 | V_520 ;
else
V_305 &= ~ ( V_519 | V_520 ) ;
V_175 -> V_521 = V_487 ;
V_175 -> V_522 = V_311 ;
V_175 -> V_523 = V_313 ;
V_175 -> V_524 = V_315 ;
V_175 -> V_525 = V_307 ;
V_175 -> V_526 = V_309 ;
V_175 -> V_527 = V_305 ;
V_175 -> V_528 = V_303 ;
V_175 -> V_529 = V_317 ;
V_175 -> V_530 = V_319 ;
return 0 ;
}
static int F_144 ( struct V_2 * V_3 ,
T_3 V_487 ,
T_11 * V_531 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
bool V_489 ;
if ( V_3 -> V_5 . V_6 . V_42 . V_190 . V_44 ) {
V_74 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_190 ,
V_487 , & V_531 -> V_467 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_3 -> V_5 . V_6 . V_42 . V_189 . V_44 ) {
V_74 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_189 ,
V_487 , & V_531 -> V_532 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_3 -> V_5 . V_6 . V_42 . V_391 . V_44 ) {
V_74 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_391 ,
V_487 , & V_531 -> V_533 ) ;
if ( V_74 )
return V_74 ;
}
V_531 -> V_468 = 1 ;
if ( V_4 -> V_534 )
F_111 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_535 ,
V_487 ,
& V_531 -> V_468 ) ;
V_531 -> V_536 = 1 ;
V_531 -> V_452 = 1 ;
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
if ( V_4 -> V_170 ) {
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
V_74 = F_132 ( V_3 , V_487 , V_531 , V_531 -> V_543 , V_489 ) ;
if ( V_74 )
return V_74 ;
V_531 -> V_467 = F_16 ( V_531 -> V_467 * V_33 ) ;
V_531 -> V_468 = F_16 ( V_531 -> V_468 ) ;
V_531 -> V_532 = F_16 ( V_531 -> V_532 * V_33 ) ;
V_531 -> V_533 = F_16 ( V_531 -> V_533 * V_33 ) ;
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
T_4 * V_201 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_458 V_459 ;
T_8 V_561 ;
T_3 V_562 = V_4 -> V_290 . V_291 ;
T_3 V_563 = V_4 -> V_290 . V_293 ;
T_3 V_303 = V_4 -> V_290 . V_303 ;
T_3 V_305 = V_4 -> V_290 . V_305 ;
int V_74 ;
V_201 -> V_564 . V_565 &= ~ V_566 ;
if ( V_4 -> V_567 )
V_201 -> V_564 . V_467 = F_16 ( V_4 -> V_567 * V_33 ) ;
else
V_201 -> V_564 . V_467 = F_16 ( V_4 -> V_568 * V_33 ) ;
V_201 -> V_564 . V_468 = V_4 -> V_534 ? 0 : 1 ;
V_201 -> V_564 . V_569 = V_3 -> clock . V_332 . V_333 ;
V_74 = F_128 ( V_3 ,
V_570 ,
V_201 -> V_564 . V_569 , false , & V_459 ) ;
if ( V_74 )
return V_74 ;
V_201 -> V_564 . V_571 = ( T_1 ) V_459 . V_471 ;
V_201 -> V_564 . V_547 = V_548 ;
V_201 -> V_564 . V_572 = 0 ;
V_562 &= ~ V_573 ;
V_562 |= V_574 ;
V_563 &= ~ V_575 ;
V_563 |= F_148 ( 4 ) ;
V_201 -> V_564 . V_576 = V_562 ;
V_201 -> V_564 . V_577 = V_563 ;
V_201 -> V_564 . V_578 = V_4 -> V_290 . V_295 ;
V_201 -> V_564 . V_579 = V_4 -> V_290 . V_297 ;
V_201 -> V_564 . V_580 = V_4 -> V_290 . V_299 ;
V_201 -> V_564 . V_581 = V_4 -> V_290 . V_301 ;
V_201 -> V_564 . V_582 = 0 ;
V_201 -> V_564 . V_583 = 0 ;
V_201 -> V_564 . V_565 = F_16 ( V_201 -> V_564 . V_565 ) ;
V_201 -> V_564 . V_468 = F_16 ( V_201 -> V_564 . V_468 ) ;
V_201 -> V_564 . V_569 = F_16 ( V_201 -> V_564 . V_569 ) ;
V_201 -> V_564 . V_576 = F_16 ( V_201 -> V_564 . V_576 ) ;
V_201 -> V_564 . V_577 = F_16 ( V_201 -> V_564 . V_577 ) ;
V_201 -> V_564 . V_578 = F_16 ( V_201 -> V_564 . V_578 ) ;
V_201 -> V_564 . V_579 = F_16 ( V_201 -> V_564 . V_579 ) ;
V_201 -> V_564 . V_580 = F_16 ( V_201 -> V_564 . V_580 ) ;
V_201 -> V_564 . V_581 = F_16 ( V_201 -> V_564 . V_581 ) ;
V_201 -> V_564 . V_582 = F_16 ( V_201 -> V_564 . V_582 ) ;
V_201 -> V_564 . V_583 = F_16 ( V_201 -> V_564 . V_583 ) ;
V_201 -> V_584 . V_467 = V_201 -> V_564 . V_467 ;
V_201 -> V_584 . V_468 = V_201 -> V_564 . V_468 ;
if ( V_4 -> V_384 != V_406 ) {
if ( V_4 -> V_585 )
V_201 -> V_584 . V_532 =
F_16 ( V_4 -> V_585 * V_33 ) ;
else
V_201 -> V_584 . V_532 =
F_16 ( V_4 -> V_586 * V_33 ) ;
}
if ( F_109 ( V_3 , 0 , & V_561 ) )
V_201 -> V_584 . V_533 = 0 ;
else
V_201 -> V_584 . V_533 =
F_16 ( V_561 . V_397 * V_33 ) ;
V_305 |= V_587 | V_588 ;
V_305 &= ~ ( V_519 | V_520 ) ;
V_303 &= ~ ( V_589 | V_590 ) ;
V_201 -> V_584 . V_528 = F_16 ( V_303 ) ;
V_201 -> V_584 . V_527 = F_16 ( V_305 ) ;
V_201 -> V_584 . V_525 =
F_16 ( V_4 -> V_290 . V_307 ) ;
V_201 -> V_584 . V_526 =
F_16 ( V_4 -> V_290 . V_309 ) ;
V_201 -> V_584 . V_522 =
F_16 ( V_4 -> V_290 . V_311 ) ;
V_201 -> V_584 . V_523 =
F_16 ( V_4 -> V_290 . V_313 ) ;
V_201 -> V_584 . V_524 =
F_16 ( V_4 -> V_290 . V_315 ) ;
V_201 -> V_584 . V_529 = F_16 ( V_4 -> V_290 . V_317 ) ;
V_201 -> V_584 . V_530 = F_16 ( V_4 -> V_290 . V_319 ) ;
V_201 -> V_584 . V_536 = 0 ;
V_201 -> V_584 . V_452 = 0 ;
V_201 -> V_584 . V_537 = 0 ;
V_201 -> V_584 . V_538 = 100 ;
V_201 -> V_584 . V_539 = 0 ;
V_201 -> V_584 . V_540 =
F_9 ( ( T_2 ) V_4 -> V_541 ) ;
V_201 -> V_584 . V_542 = false ;
V_201 -> V_584 . V_543 = false ;
V_201 -> V_584 . V_544 = false ;
V_201 -> V_584 . V_545 = false ;
V_201 -> V_584 . V_546 = false ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_591 * V_592 = & V_4 -> V_592 ;
if ( V_592 -> V_593 ) {
if ( V_127 )
return ( F_31 ( V_3 , V_594 ) == V_148 ) ?
0 : - V_45 ;
else
return ( F_31 ( V_3 , V_595 ) == V_148 ) ?
0 : - V_45 ;
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
if ( V_4 -> V_378 != V_382 ) {
if ( V_597 > V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_376 )
V_596 -> V_599 = 0 ;
else
V_596 -> V_599 =
V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_376 - V_597 ;
} else {
if ( V_597 > V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_376 )
V_596 -> V_600 = 0 ;
else
V_596 -> V_600 = ( T_1 )
( ( V_3 -> V_5 . V_6 . V_42 . V_47 . V_44 [ 0 ] . V_376 - V_597 ) *
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
T_13 * V_174 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_458 V_459 ;
T_3 V_605 = V_4 -> V_290 . V_295 ;
T_3 V_606 = V_4 -> V_290 . V_297 ;
T_3 V_299 = V_4 -> V_290 . V_299 ;
T_3 V_301 = V_4 -> V_290 . V_301 ;
T_3 V_508 = V_3 -> clock . V_332 . V_333 ;
T_3 V_607 ;
T_3 V_608 ;
int V_74 ;
V_74 = F_128 ( V_3 ,
V_570 ,
V_604 , false , & V_459 ) ;
if ( V_74 )
return V_74 ;
V_607 = 1 + V_459 . V_609 ;
V_608 = V_459 . V_610 & 0x3FFFFFF ;
V_605 &= ~ V_611 ;
V_605 |= F_152 ( V_608 ) ;
V_605 |= V_612 ;
if ( V_4 -> V_341 ) {
struct V_505 V_506 ;
T_3 V_613 = V_604 * V_459 . V_501 ;
if ( F_140 ( V_3 , & V_506 ,
V_614 , V_613 ) ) {
T_3 V_615 = V_508 * 5 / ( V_607 * V_506 . V_512 ) ;
T_3 V_616 = 4 * V_506 . V_514 * V_608 / ( V_615 * 10000 ) ;
V_299 &= ~ V_617 ;
V_299 |= F_153 ( V_615 ) ;
V_299 |= V_343 ;
V_301 &= ~ V_618 ;
V_301 |= F_154 ( V_616 ) ;
}
}
V_174 -> V_569 = V_604 ;
V_174 -> V_578 = V_605 ;
V_174 -> V_579 = V_606 ;
V_174 -> V_580 = V_299 ;
V_174 -> V_581 = V_301 ;
V_174 -> V_571 = ( T_1 ) V_459 . V_471 ;
return 0 ;
}
static int F_155 ( struct V_2 * V_3 ,
T_3 V_604 ,
T_2 V_619 ,
T_13 * V_620 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
V_74 = F_151 ( V_3 , V_604 , V_620 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_113 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_47 ,
V_604 , & V_620 -> V_467 ) ;
if ( V_74 )
return V_74 ;
V_620 -> V_569 = V_604 ;
V_620 -> V_565 = 0 ;
V_620 -> V_468 = 1 ;
if ( V_4 -> V_534 )
F_110 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_535 ,
V_604 ,
& V_620 -> V_468 ) ;
V_620 -> V_540 = V_619 ;
V_620 -> V_582 = 0 ;
V_620 -> V_583 = 0 ;
V_620 -> V_452 = 1 ;
V_620 -> V_536 = 1 ;
V_620 -> V_537 = 0 ;
V_620 -> V_538 = 0 ;
V_620 -> V_539 = 0 ;
V_620 -> V_621 = 0 ;
if ( V_4 -> V_325 )
V_620 -> V_572 = F_114 ( V_3 ,
V_604 ,
V_419 ) ;
V_620 -> V_547 = V_548 ;
V_620 -> V_565 = F_16 ( V_620 -> V_565 ) ;
V_620 -> V_467 = F_16 ( V_620 -> V_467 * V_33 ) ;
V_620 -> V_468 = F_16 ( V_620 -> V_468 ) ;
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
struct V_446 * V_93 = & V_4 -> V_93 ;
T_3 V_622 = V_4 -> V_207 +
F_12 ( T_4 , V_623 ) ;
T_3 V_624 = sizeof( T_13 ) *
V_625 ;
T_13 * V_626 = V_4 -> V_94 . V_623 ;
T_3 V_41 , V_74 ;
memset ( V_626 , 0 , V_624 ) ;
for ( V_41 = 0 ; V_41 < V_93 -> V_435 . V_46 ; V_41 ++ ) {
V_74 = F_155 ( V_3 ,
V_93 -> V_435 . V_437 [ V_41 ] . V_57 ,
( T_2 ) V_4 -> V_627 [ V_41 ] ,
& V_4 -> V_94 . V_623 [ V_41 ] ) ;
if ( V_74 )
return V_74 ;
if ( V_41 == ( V_93 -> V_435 . V_46 - 1 ) )
V_4 -> V_94 . V_623 [ V_41 ] . V_547 =
V_628 ;
}
V_4 -> V_94 . V_629 = ( T_1 ) V_93 -> V_435 . V_46 ;
V_4 -> V_456 . V_630 =
F_124 ( & V_93 -> V_435 ) ;
V_74 = F_18 ( V_3 , V_622 ,
( T_1 * ) V_626 , V_624 ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
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
struct V_446 * V_93 = & V_4 -> V_93 ;
T_3 V_622 = V_4 -> V_207 +
F_12 ( T_4 , V_632 ) ;
T_3 V_624 = sizeof( T_11 ) *
V_633 ;
T_11 * V_626 = V_4 -> V_94 . V_632 ;
T_3 V_41 , V_74 ;
memset ( V_626 , 0 , V_624 ) ;
for ( V_41 = 0 ; V_41 < V_93 -> V_436 . V_46 ; V_41 ++ ) {
if ( V_93 -> V_436 . V_437 [ V_41 ] . V_57 == 0 )
return - V_45 ;
V_74 = F_144 ( V_3 ,
V_93 -> V_436 . V_437 [ V_41 ] . V_57 ,
& V_4 -> V_94 . V_632 [ V_41 ] ) ;
if ( V_74 )
return V_74 ;
}
V_4 -> V_94 . V_632 [ 0 ] . V_540 = F_9 ( 0x1F ) ;
V_4 -> V_94 . V_634 = ( T_1 ) V_93 -> V_436 . V_46 ;
V_4 -> V_456 . V_635 =
F_124 ( & V_93 -> V_436 ) ;
V_4 -> V_94 . V_632 [ V_93 -> V_436 . V_46 - 1 ] . V_547 =
V_628 ;
V_74 = F_18 ( V_3 , V_622 ,
( T_1 * ) V_626 , V_624 ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static void F_159 ( struct V_2 * V_3 ,
struct V_443 * V_93 ,
T_3 V_46 )
{
T_3 V_41 ;
V_93 -> V_46 = V_46 ;
for ( V_41 = 0 ; V_41 < V_636 ; V_41 ++ )
V_93 -> V_437 [ V_41 ] . V_445 = false ;
}
static void F_160 ( struct V_443 * V_93 ,
T_3 V_637 , T_3 V_638 , T_3 V_639 )
{
V_93 -> V_437 [ V_637 ] . V_57 = V_638 ;
V_93 -> V_437 [ V_637 ] . V_451 = V_639 ;
V_93 -> V_437 [ V_637 ] . V_445 = true ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_640 && ! V_4 -> V_641 )
return - V_45 ;
if ( V_4 -> V_640 && ! V_4 -> V_641 ) {
V_4 -> V_642 = V_4 -> V_643 ;
V_4 -> V_644 = V_4 -> V_645 ;
} else if ( ! V_4 -> V_640 && V_4 -> V_641 ) {
V_4 -> V_643 = V_4 -> V_642 ;
V_4 -> V_645 = V_4 -> V_644 ;
}
F_159 ( V_3 ,
& V_4 -> V_93 . V_447 ,
V_646 ) ;
F_160 ( & V_4 -> V_93 . V_447 , 0 ,
V_4 -> V_642 . V_82 ,
V_4 -> V_644 . V_82 ) ;
F_160 ( & V_4 -> V_93 . V_447 , 1 ,
V_4 -> V_643 . V_82 ,
V_4 -> V_645 . V_82 ) ;
F_160 ( & V_4 -> V_93 . V_447 , 2 ,
V_4 -> V_642 . V_82 ,
V_4 -> V_644 . V_83 ) ;
F_160 ( & V_4 -> V_93 . V_447 , 3 ,
V_4 -> V_643 . V_82 ,
V_4 -> V_645 . V_83 ) ;
F_160 ( & V_4 -> V_93 . V_447 , 4 ,
V_4 -> V_642 . V_83 ,
V_4 -> V_644 . V_83 ) ;
F_160 ( & V_4 -> V_93 . V_447 , 5 ,
V_4 -> V_643 . V_83 ,
V_4 -> V_645 . V_83 ) ;
V_4 -> V_93 . V_447 . V_46 = 6 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_370 * V_647 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
struct V_370 * V_648 =
& V_3 -> V_5 . V_6 . V_42 . V_190 ;
struct V_649 * V_650 =
& V_3 -> V_5 . V_6 . V_42 . V_43 ;
T_3 V_41 ;
if ( V_647 == NULL )
return - V_45 ;
if ( V_647 -> V_46 < 1 )
return - V_45 ;
if ( V_648 == NULL )
return - V_45 ;
if ( V_648 -> V_46 < 1 )
return - V_45 ;
memset ( & V_4 -> V_93 , 0 , sizeof( struct V_446 ) ) ;
F_159 ( V_3 ,
& V_4 -> V_93 . V_435 ,
V_625 ) ;
F_159 ( V_3 ,
& V_4 -> V_93 . V_436 ,
V_633 ) ;
F_159 ( V_3 ,
& V_4 -> V_93 . V_651 ,
V_383 ) ;
F_159 ( V_3 ,
& V_4 -> V_93 . V_652 ,
V_387 ) ;
F_159 ( V_3 ,
& V_4 -> V_93 . V_653 ,
V_392 ) ;
V_4 -> V_93 . V_435 . V_46 = 0 ;
for ( V_41 = 0 ; V_41 < V_647 -> V_46 ; V_41 ++ ) {
if ( ( V_41 == 0 ) ||
( V_4 -> V_93 . V_435 . V_437 [ V_4 -> V_93 . V_435 . V_46 - 1 ] . V_57 !=
V_647 -> V_44 [ V_41 ] . V_407 ) ) {
V_4 -> V_93 . V_435 . V_437 [ V_4 -> V_93 . V_435 . V_46 ] . V_57 =
V_647 -> V_44 [ V_41 ] . V_407 ;
V_4 -> V_93 . V_435 . V_437 [ V_4 -> V_93 . V_435 . V_46 ] . V_445 = true ;
V_4 -> V_93 . V_435 . V_46 ++ ;
}
}
V_4 -> V_93 . V_436 . V_46 = 0 ;
for ( V_41 = 0 ; V_41 < V_648 -> V_46 ; V_41 ++ ) {
if ( ( V_41 == 0 ) ||
( V_4 -> V_93 . V_436 . V_437 [ V_4 -> V_93 . V_436 . V_46 - 1 ] . V_57 !=
V_648 -> V_44 [ V_41 ] . V_407 ) ) {
V_4 -> V_93 . V_436 . V_437 [ V_4 -> V_93 . V_436 . V_46 ] . V_57 =
V_648 -> V_44 [ V_41 ] . V_407 ;
V_4 -> V_93 . V_436 . V_437 [ V_4 -> V_93 . V_436 . V_46 ] . V_445 = true ;
V_4 -> V_93 . V_436 . V_46 ++ ;
}
}
for ( V_41 = 0 ; V_41 < V_647 -> V_46 ; V_41 ++ ) {
V_4 -> V_93 . V_651 . V_437 [ V_41 ] . V_57 =
V_647 -> V_44 [ V_41 ] . V_376 ;
V_4 -> V_93 . V_651 . V_437 [ V_41 ] . V_451 =
V_650 -> V_44 [ V_41 ] . V_53 ;
V_4 -> V_93 . V_651 . V_437 [ V_41 ] . V_445 = true ;
}
V_4 -> V_93 . V_651 . V_46 = V_647 -> V_46 ;
V_648 = & V_3 -> V_5 . V_6 . V_42 . V_189 ;
if ( V_648 ) {
for ( V_41 = 0 ; V_41 < V_648 -> V_46 ; V_41 ++ ) {
V_4 -> V_93 . V_652 . V_437 [ V_41 ] . V_57 =
V_648 -> V_44 [ V_41 ] . V_376 ;
V_4 -> V_93 . V_652 . V_437 [ V_41 ] . V_445 = true ;
}
V_4 -> V_93 . V_652 . V_46 = V_648 -> V_46 ;
}
V_648 = & V_3 -> V_5 . V_6 . V_42 . V_391 ;
if ( V_648 ) {
for ( V_41 = 0 ; V_41 < V_648 -> V_46 ; V_41 ++ ) {
V_4 -> V_93 . V_653 . V_437 [ V_41 ] . V_57 =
V_648 -> V_44 [ V_41 ] . V_376 ;
V_4 -> V_93 . V_653 . V_437 [ V_41 ] . V_445 = true ;
}
V_4 -> V_93 . V_653 . V_46 = V_648 -> V_46 ;
}
F_161 ( V_3 ) ;
return 0 ;
}
static int F_163 ( struct V_443 * V_201 ,
T_3 V_57 , T_3 * V_654 )
{
T_3 V_41 ;
int V_74 = - V_45 ;
for( V_41 = 0 ; V_41 < V_201 -> V_46 ; V_41 ++ ) {
if ( V_57 == V_201 -> V_437 [ V_41 ] . V_57 ) {
* V_654 = V_41 ;
V_74 = 0 ;
}
}
return V_74 ;
}
static int F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_591 * V_592 = & V_4 -> V_592 ;
struct V_9 * V_438 = V_3 -> V_5 . V_6 . V_655 ;
T_4 * V_201 = & V_4 -> V_94 ;
int V_74 ;
V_74 = F_162 ( V_3 ) ;
if ( V_74 )
return V_74 ;
if ( V_4 -> V_378 != V_406 )
F_108 ( V_3 , V_201 ) ;
F_48 ( V_3 ) ;
if ( V_3 -> V_5 . V_6 . V_48 & V_656 )
V_201 -> V_657 |= V_658 ;
if ( V_3 -> V_5 . V_6 . V_48 & V_659 )
V_201 -> V_657 |= V_660 ;
if ( V_4 -> V_170 )
V_201 -> V_657 |= V_661 ;
if ( V_592 -> V_593 ) {
V_74 = F_157 ( V_3 , & V_4 -> V_94 . V_662 ) ;
if ( V_74 )
return V_74 ;
F_25 ( V_663 , V_592 -> V_664 ) ;
}
V_74 = F_156 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_158 ( V_3 ) ;
if ( V_74 )
return V_74 ;
F_125 ( V_3 , V_201 ) ;
V_74 = F_147 ( V_3 , V_201 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_129 ( V_3 , V_201 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_130 ( V_3 , V_201 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_131 ( V_3 , V_201 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_121 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_127 ( V_3 , V_201 ) ;
if ( V_74 )
return V_74 ;
V_201 -> V_665 = 0 ;
V_201 -> V_666 = 0 ;
V_201 -> V_667 = 0 ;
V_201 -> V_668 = 0 ;
V_201 -> V_441 = 0 ;
V_201 -> V_442 = 0 ;
V_74 = F_163 ( & V_4 -> V_93 . V_435 ,
V_4 -> V_669 . V_670 ,
( T_3 * ) & V_4 -> V_94 . V_441 ) ;
V_74 = F_163 ( & V_4 -> V_93 . V_436 ,
V_4 -> V_669 . V_671 ,
( T_3 * ) & V_4 -> V_94 . V_442 ) ;
V_201 -> V_672 = V_4 -> V_669 . V_673 ;
V_201 -> V_674 = V_4 -> V_669 . V_675 ;
V_201 -> V_676 = V_4 -> V_669 . V_677 ;
F_123 ( V_3 , V_438 ) ;
V_74 = F_15 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_201 -> V_678 = 1 ;
V_201 -> V_679 = 1 ;
V_201 -> V_680 = 1 ;
V_201 -> V_681 = 1 ;
V_201 -> V_682 = 1 ;
V_201 -> V_683 = 1 ;
V_201 -> V_684 = 1 ;
V_201 -> V_685 = 1 ;
V_201 -> V_686 = 1 ;
V_201 -> V_687 = ( T_2 ) ( ( V_4 -> V_108 . V_109 *
V_688 ) / 1000 ) ;
V_201 -> V_689 = ( T_2 ) ( ( V_4 -> V_108 . V_690 *
V_688 ) / 1000 ) ;
V_201 -> V_691 = 1 ;
V_201 -> V_692 = 1 ;
V_201 -> V_693 = 0 ;
V_201 -> V_694 = 4000 ;
V_201 -> V_695 = 0 ;
V_201 -> V_696 = 1 ;
V_201 -> V_697 = 0 ;
V_201 -> V_698 = 1 ;
if ( V_4 -> V_378 == V_382 )
V_201 -> V_699 = 1 ;
else
V_201 -> V_699 = 0 ;
V_201 -> V_700 = 17 ;
V_201 -> V_701 = 0x4000 ;
V_201 -> V_657 = F_16 ( V_201 -> V_657 ) ;
V_201 -> V_702 = F_16 ( V_201 -> V_702 ) ;
V_201 -> V_703 = F_16 ( V_201 -> V_703 ) ;
V_201 -> V_704 = F_16 ( V_201 -> V_704 ) ;
V_201 -> V_705 = F_16 ( V_201 -> V_705 ) ;
V_201 -> V_701 = F_16 ( V_201 -> V_701 ) ;
V_201 -> V_687 = F_9 ( V_201 -> V_687 ) ;
V_201 -> V_689 = F_9 ( V_201 -> V_689 ) ;
V_201 -> V_694 = F_9 ( V_201 -> V_694 ) ;
V_201 -> V_693 = F_9 ( V_201 -> V_693 ) ;
V_201 -> V_695 = F_9 ( V_201 -> V_695 ) ;
V_201 -> V_672 = F_9 ( V_201 -> V_672 * V_33 ) ;
V_201 -> V_674 = F_9 ( V_201 -> V_674 * V_33 ) ;
V_201 -> V_676 = F_9 ( V_201 -> V_676 * V_33 ) ;
V_74 = F_18 ( V_3 ,
V_4 -> V_207 +
F_12 ( T_4 , V_657 ) ,
( T_1 * ) & V_201 -> V_657 ,
sizeof( T_4 ) - 3 * sizeof( V_706 ) ,
V_4 -> V_80 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static void F_165 ( struct V_2 * V_3 ,
struct V_443 * V_93 ,
T_3 V_707 , T_3 V_708 )
{
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_93 -> V_46 ; V_41 ++ ) {
if ( ( V_93 -> V_437 [ V_41 ] . V_57 < V_707 ) ||
( V_93 -> V_437 [ V_41 ] . V_57 > V_708 ) )
V_93 -> V_437 [ V_41 ] . V_445 = false ;
else
V_93 -> V_437 [ V_41 ] . V_445 = true ;
}
}
static void F_166 ( struct V_2 * V_3 ,
T_3 V_709 , T_3 V_710 ,
T_3 V_711 , T_3 V_712 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_443 * V_713 = & V_4 -> V_93 . V_447 ;
T_3 V_41 , V_98 ;
for ( V_41 = 0 ; V_41 < V_713 -> V_46 ; V_41 ++ ) {
if ( ( V_713 -> V_437 [ V_41 ] . V_57 < V_709 ) ||
( V_713 -> V_437 [ V_41 ] . V_451 < V_710 ) ||
( V_713 -> V_437 [ V_41 ] . V_57 > V_711 ) ||
( V_713 -> V_437 [ V_41 ] . V_451 > V_712 ) )
V_713 -> V_437 [ V_41 ] . V_445 = false ;
else
V_713 -> V_437 [ V_41 ] . V_445 = true ;
}
for ( V_41 = 0 ; V_41 < V_713 -> V_46 ; V_41 ++ ) {
if ( V_713 -> V_437 [ V_41 ] . V_445 ) {
for ( V_98 = V_41 + 1 ; V_98 < V_713 -> V_46 ; V_98 ++ ) {
if ( V_713 -> V_437 [ V_98 ] . V_445 ) {
if ( ( V_713 -> V_437 [ V_41 ] . V_57 == V_713 -> V_437 [ V_98 ] . V_57 ) &&
( V_713 -> V_437 [ V_41 ] . V_451 == V_713 -> V_437 [ V_98 ] . V_451 ) )
V_713 -> V_437 [ V_98 ] . V_445 = false ;
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
return - V_45 ;
if ( V_596 -> V_187 == 1 )
V_715 = 0 ;
else
V_715 = 1 ;
F_165 ( V_3 ,
& V_4 -> V_93 . V_435 ,
V_596 -> V_188 [ 0 ] . V_174 ,
V_596 -> V_188 [ V_715 ] . V_174 ) ;
F_165 ( V_3 ,
& V_4 -> V_93 . V_436 ,
V_596 -> V_188 [ 0 ] . V_175 ,
V_596 -> V_188 [ V_715 ] . V_175 ) ;
F_166 ( V_3 ,
V_596 -> V_188 [ 0 ] . V_638 ,
V_596 -> V_188 [ 0 ] . V_716 ,
V_596 -> V_188 [ V_715 ] . V_638 ,
V_596 -> V_188 [ V_715 ] . V_716 ) ;
return 0 ;
}
static int F_168 ( struct V_2 * V_3 )
{
struct V_370 * V_717 =
& V_3 -> V_5 . V_6 . V_42 . V_718 ;
struct V_370 * V_651 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
T_3 V_719 = 0 ;
T_3 V_41 ;
if ( V_717 == NULL )
return - V_45 ;
if ( ! V_717 -> V_46 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_717 -> V_46 ; V_41 ++ ) {
if ( V_3 -> clock . V_720 == V_717 -> V_44 [ V_41 ] . V_407 )
V_719 = V_717 -> V_44 [ V_41 ] . V_376 ;
}
for ( V_41 = 0 ; V_41 < V_651 -> V_46 ; V_41 ++ ) {
if ( V_719 <= V_651 -> V_44 [ V_41 ] . V_376 ) {
V_719 = V_651 -> V_44 [ V_41 ] . V_376 ;
return ( F_64 ( V_3 ,
V_721 ,
V_719 * V_33 ) == V_148 ) ?
0 : - V_45 ;
}
}
return - V_45 ;
}
static int F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_722 ;
if ( ! V_4 -> V_235 ) {
if ( V_4 -> V_456 . V_630 ) {
V_722 = F_64 ( V_3 ,
V_723 ,
V_4 -> V_456 . V_630 ) ;
if ( V_722 != V_148 )
return - V_45 ;
}
}
if ( ! V_4 -> V_239 ) {
if ( V_4 -> V_456 . V_635 ) {
V_722 = F_64 ( V_3 ,
V_724 ,
V_4 -> V_456 . V_635 ) ;
if ( V_722 != V_148 )
return - V_45 ;
}
}
if ( ! V_4 -> V_259 ) {
if ( V_4 -> V_456 . V_457 ) {
V_722 = F_64 ( V_3 ,
V_725 ,
V_4 -> V_456 . V_457 ) ;
if ( V_722 != V_148 )
return - V_45 ;
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
struct V_443 * V_435 = & V_4 -> V_93 . V_435 ;
T_3 V_174 = V_596 -> V_188 [ V_596 -> V_187 - 1 ] . V_174 ;
struct V_443 * V_436 = & V_4 -> V_93 . V_436 ;
T_3 V_175 = V_596 -> V_188 [ V_596 -> V_187 - 1 ] . V_175 ;
T_3 V_41 ;
V_4 -> V_234 = 0 ;
for ( V_41 = 0 ; V_41 < V_435 -> V_46 ; V_41 ++ ) {
if ( V_174 == V_435 -> V_437 [ V_41 ] . V_57 )
break;
}
if ( V_41 >= V_435 -> V_46 ) {
V_4 -> V_234 |= V_236 ;
} else {
if ( 0 != V_419 )
V_4 -> V_234 |= V_237 ;
}
for ( V_41 = 0 ; V_41 < V_436 -> V_46 ; V_41 ++ ) {
if ( V_175 == V_436 -> V_437 [ V_41 ] . V_57 )
break;
}
if ( V_41 >= V_436 -> V_46 )
V_4 -> V_234 |= V_240 ;
if ( V_3 -> V_5 . V_6 . V_726 !=
V_3 -> V_5 . V_6 . V_179 )
V_4 -> V_234 |= V_727 ;
}
static int F_171 ( struct V_2 * V_3 ,
struct V_9 * V_714 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_596 = F_2 ( V_714 ) ;
T_3 V_174 = V_596 -> V_188 [ V_596 -> V_187 - 1 ] . V_174 ;
T_3 V_175 = V_596 -> V_188 [ V_596 -> V_187 - 1 ] . V_175 ;
struct V_446 * V_93 = & V_4 -> V_93 ;
int V_74 ;
if ( ! V_4 -> V_234 )
return 0 ;
if ( V_4 -> V_234 & V_236 )
V_93 -> V_435 . V_437 [ V_93 -> V_435 . V_46 - 1 ] . V_57 = V_174 ;
if ( V_4 -> V_234 & V_240 )
V_93 -> V_436 . V_437 [ V_93 -> V_436 . V_46 - 1 ] . V_57 = V_175 ;
if ( V_4 -> V_234 & ( V_236 | V_237 ) ) {
V_74 = F_156 ( V_3 ) ;
if ( V_74 )
return V_74 ;
}
if ( V_4 -> V_234 & ( V_240 | V_727 ) ) {
V_74 = F_158 ( V_3 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static int F_172 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_171 * V_172 ;
int V_41 ;
if ( V_3 -> V_5 . V_6 . V_184 )
V_172 = & V_3 -> V_5 . V_6 . V_42 . V_185 ;
else
V_172 = & V_3 -> V_5 . V_6 . V_42 . V_186 ;
if ( V_127 ) {
V_4 -> V_456 . V_728 = 0 ;
for ( V_41 = V_3 -> V_5 . V_6 . V_42 . V_461 . V_46 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( V_3 -> V_5 . V_6 . V_42 . V_461 . V_44 [ V_41 ] . V_376 <= V_172 -> V_32 ) {
V_4 -> V_456 . V_728 |= 1 << V_41 ;
if ( ! V_4 -> V_729 )
break;
}
}
F_64 ( V_3 ,
V_730 ,
V_4 -> V_456 . V_728 ) ;
if ( V_4 -> V_731 & 0x1 ) {
V_4 -> V_550 = true ;
V_4 -> V_456 . V_635 &= 0xFFFFFFFE ;
F_64 ( V_3 ,
V_724 ,
V_4 -> V_456 . V_635 ) ;
}
} else {
if ( V_4 -> V_731 & 0x1 ) {
V_4 -> V_550 = false ;
V_4 -> V_456 . V_635 |= 1 ;
F_64 ( V_3 ,
V_724 ,
V_4 -> V_456 . V_635 ) ;
}
}
return ( F_31 ( V_3 , V_127 ?
V_732 : V_733 ) == V_148 ) ?
0 : - V_45 ;
}
static int F_37 ( struct V_2 * V_3 , bool V_166 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_195 ;
if ( ! V_166 ) {
if ( V_4 -> V_729 ||
( V_3 -> V_5 . V_6 . V_42 . V_461 . V_46 <= 0 ) )
V_4 -> V_94 . V_665 = 0 ;
else
V_4 -> V_94 . V_665 =
V_3 -> V_5 . V_6 . V_42 . V_461 . V_46 - 1 ;
V_195 = F_23 ( V_734 ) ;
V_195 &= ~ V_735 ;
V_195 |= V_665 ( V_4 -> V_94 . V_665 ) ;
F_25 ( V_734 , V_195 ) ;
}
return F_172 ( V_3 , ! V_166 ) ;
}
static int F_173 ( struct V_2 * V_3 ,
struct V_9 * V_714 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
V_74 = F_167 ( V_3 , V_714 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_456 . V_630 =
F_124 ( & V_4 -> V_93 . V_435 ) ;
V_4 -> V_456 . V_635 =
F_124 ( & V_4 -> V_93 . V_436 ) ;
V_4 -> V_731 =
V_4 -> V_456 . V_635 ;
if ( V_4 -> V_550 ) {
if ( V_4 -> V_456 . V_635 & 1 )
V_4 -> V_456 . V_635 &= 0xFFFFFFFE ;
}
V_4 -> V_456 . V_457 =
F_124 ( & V_4 -> V_93 . V_447 ) ;
return 0 ;
}
static T_3 F_174 ( struct V_2 * V_3 ,
T_3 V_736 )
{
T_3 V_440 = 0 ;
while ( ( V_736 & ( 1 << V_440 ) ) == 0 )
V_440 ++ ;
return V_440 ;
}
int F_175 ( struct V_2 * V_3 ,
enum V_737 V_440 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_145 ;
T_3 V_195 , V_626 , V_41 ;
int V_74 ;
if ( V_440 == V_738 ) {
if ( ( ! V_4 -> V_235 ) &&
V_4 -> V_456 . V_630 ) {
V_626 = 0 ;
V_195 = V_4 -> V_456 . V_630 ;
while ( V_195 >>= 1 )
V_626 ++ ;
if ( V_626 ) {
V_74 = F_66 ( V_3 , V_626 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_279 ; V_41 ++ ) {
V_195 = ( F_23 ( V_739 ) &
V_740 ) >> V_741 ;
if ( V_195 == V_626 )
break;
F_59 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_239 ) &&
V_4 -> V_456 . V_635 ) {
V_626 = 0 ;
V_195 = V_4 -> V_456 . V_635 ;
while ( V_195 >>= 1 )
V_626 ++ ;
if ( V_626 ) {
V_74 = F_67 ( V_3 , V_626 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_279 ; V_41 ++ ) {
V_195 = ( F_23 ( V_739 ) &
V_742 ) >> V_743 ;
if ( V_195 == V_626 )
break;
F_59 ( 1 ) ;
}
}
}
if ( ( ! V_4 -> V_259 ) &&
V_4 -> V_456 . V_457 ) {
V_626 = 0 ;
V_195 = V_4 -> V_456 . V_457 ;
while ( V_195 >>= 1 )
V_626 ++ ;
if ( V_626 ) {
V_74 = F_68 ( V_3 , V_440 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_279 ; V_41 ++ ) {
V_195 = ( F_23 ( V_744 ) &
V_745 ) >> V_746 ;
if ( V_195 == V_626 )
break;
F_59 ( 1 ) ;
}
}
}
} else if ( V_440 == V_747 ) {
if ( ( ! V_4 -> V_235 ) &&
V_4 -> V_456 . V_630 ) {
V_626 = F_174 ( V_3 ,
V_4 -> V_456 . V_630 ) ;
V_74 = F_66 ( V_3 , V_626 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_279 ; V_41 ++ ) {
V_195 = ( F_23 ( V_739 ) &
V_740 ) >> V_741 ;
if ( V_195 == V_626 )
break;
F_59 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_239 ) &&
V_4 -> V_456 . V_635 ) {
V_626 = F_174 ( V_3 ,
V_4 -> V_456 . V_635 ) ;
V_74 = F_67 ( V_3 , V_626 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_279 ; V_41 ++ ) {
V_195 = ( F_23 ( V_739 ) &
V_742 ) >> V_743 ;
if ( V_195 == V_626 )
break;
F_59 ( 1 ) ;
}
}
if ( ( ! V_4 -> V_259 ) &&
V_4 -> V_456 . V_457 ) {
V_626 = F_174 ( V_3 ,
V_4 -> V_456 . V_457 ) ;
V_74 = F_68 ( V_3 , V_626 ) ;
if ( V_74 )
return V_74 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_279 ; V_41 ++ ) {
V_195 = ( F_23 ( V_744 ) &
V_745 ) >> V_746 ;
if ( V_195 == V_626 )
break;
F_59 ( 1 ) ;
}
}
} else if ( V_440 == V_748 ) {
if ( ! V_4 -> V_235 ) {
V_145 = F_31 ( V_3 , V_749 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
if ( ! V_4 -> V_239 ) {
V_145 = F_31 ( V_3 , V_750 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
if ( ! V_4 -> V_259 ) {
V_145 = F_31 ( V_3 , V_751 ) ;
if ( V_145 != V_148 )
return - V_45 ;
}
}
V_3 -> V_5 . V_6 . V_752 = V_440 ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 ,
struct V_753 * V_201 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_41 , V_98 , V_99 ;
T_3 V_754 ;
for ( V_41 = 0 , V_98 = V_201 -> V_755 ; V_41 < V_201 -> V_755 ; V_41 ++ ) {
if ( V_98 >= V_756 )
return - V_45 ;
switch( V_201 -> V_757 [ V_41 ] . V_758 << 2 ) {
case V_759 :
V_754 = F_24 ( V_760 ) ;
V_201 -> V_757 [ V_98 ] . V_758 = V_760 >> 2 ;
V_201 -> V_757 [ V_98 ] . V_761 = V_762 >> 2 ;
for ( V_99 = 0 ; V_99 < V_201 -> V_763 ; V_99 ++ ) {
V_201 -> V_764 [ V_99 ] . V_765 [ V_98 ] =
( ( V_754 & 0xffff0000 ) ) | ( ( V_201 -> V_764 [ V_99 ] . V_765 [ V_41 ] & 0xffff0000 ) >> 16 ) ;
}
V_98 ++ ;
if ( V_98 >= V_756 )
return - V_45 ;
V_754 = F_24 ( V_766 ) ;
V_201 -> V_757 [ V_98 ] . V_758 = V_766 >> 2 ;
V_201 -> V_757 [ V_98 ] . V_761 = V_767 >> 2 ;
for ( V_99 = 0 ; V_99 < V_201 -> V_763 ; V_99 ++ ) {
V_201 -> V_764 [ V_99 ] . V_765 [ V_98 ] =
( V_754 & 0xffff0000 ) | ( V_201 -> V_764 [ V_99 ] . V_765 [ V_41 ] & 0x0000ffff ) ;
if ( ! V_4 -> V_170 )
V_201 -> V_764 [ V_99 ] . V_765 [ V_98 ] |= 0x100 ;
}
V_98 ++ ;
if ( V_98 > V_756 )
return - V_45 ;
if ( ! V_4 -> V_170 ) {
V_201 -> V_757 [ V_98 ] . V_758 = V_768 >> 2 ;
V_201 -> V_757 [ V_98 ] . V_761 = V_768 >> 2 ;
for ( V_99 = 0 ; V_99 < V_201 -> V_763 ; V_99 ++ ) {
V_201 -> V_764 [ V_99 ] . V_765 [ V_98 ] =
( V_201 -> V_764 [ V_99 ] . V_765 [ V_41 ] & 0xffff0000 ) >> 16 ;
}
V_98 ++ ;
if ( V_98 > V_756 )
return - V_45 ;
}
break;
case V_769 :
V_754 = F_24 ( V_770 ) ;
V_201 -> V_757 [ V_98 ] . V_758 = V_770 >> 2 ;
V_201 -> V_757 [ V_98 ] . V_761 = V_771 >> 2 ;
for ( V_99 = 0 ; V_99 < V_201 -> V_763 ; V_99 ++ ) {
V_201 -> V_764 [ V_99 ] . V_765 [ V_98 ] =
( V_754 & 0xffff0000 ) | ( V_201 -> V_764 [ V_99 ] . V_765 [ V_41 ] & 0x0000ffff ) ;
}
V_98 ++ ;
if ( V_98 > V_756 )
return - V_45 ;
break;
default:
break;
}
}
V_201 -> V_755 = V_98 ;
return 0 ;
}
static bool F_177 ( T_2 V_772 , T_2 * V_773 )
{
bool V_722 = true ;
switch( V_772 ) {
case V_774 >> 2 :
* V_773 = V_775 >> 2 ;
break;
case V_776 >> 2 :
* V_773 = V_777 >> 2 ;
break;
case V_778 >> 2 :
* V_773 = V_779 >> 2 ;
break;
case V_780 >> 2 :
* V_773 = V_781 >> 2 ;
break;
case V_782 >> 2 :
* V_773 = V_783 >> 2 ;
break;
case V_784 >> 2 :
* V_773 = V_785 >> 2 ;
break;
case V_786 >> 2 :
* V_773 = V_787 >> 2 ;
break;
case V_788 >> 2 :
* V_773 = V_789 >> 2 ;
break;
case V_790 >> 2 :
* V_773 = V_791 >> 2 ;
break;
case V_792 >> 2 :
* V_773 = V_793 >> 2 ;
break;
case V_794 >> 2 :
* V_773 = V_795 >> 2 ;
break;
case V_796 >> 2 :
* V_773 = V_797 >> 2 ;
break;
case V_798 >> 2 :
* V_773 = V_799 >> 2 ;
break;
case V_800 >> 2 :
* V_773 = V_801 >> 2 ;
break;
case V_760 >> 2 :
* V_773 = V_762 >> 2 ;
break;
case V_766 >> 2 :
* V_773 = V_767 >> 2 ;
break;
case V_770 >> 2 :
* V_773 = V_771 >> 2 ;
break;
case V_802 >> 2 :
* V_773 = V_803 >> 2 ;
break;
case V_804 >> 2 :
* V_773 = V_805 >> 2 ;
break;
case V_806 >> 2 :
* V_773 = V_807 >> 2 ;
break;
default:
V_722 = false ;
break;
}
return V_722 ;
}
static void F_178 ( struct V_753 * V_201 )
{
T_1 V_41 , V_98 ;
for ( V_41 = 0 ; V_41 < V_201 -> V_755 ; V_41 ++ ) {
for ( V_98 = 1 ; V_98 < V_201 -> V_763 ; V_98 ++ ) {
if ( V_201 -> V_764 [ V_98 - 1 ] . V_765 [ V_41 ] !=
V_201 -> V_764 [ V_98 ] . V_765 [ V_41 ] ) {
V_201 -> V_808 |= 1 << V_41 ;
break;
}
}
}
}
static void F_179 ( struct V_753 * V_201 )
{
T_3 V_41 ;
T_2 V_809 ;
for ( V_41 = 0 ; V_41 < V_201 -> V_755 ; V_41 ++ ) {
V_201 -> V_757 [ V_41 ] . V_761 =
F_177 ( V_201 -> V_757 [ V_41 ] . V_758 , & V_809 ) ?
V_809 : V_201 -> V_757 [ V_41 ] . V_758 ;
}
}
static int F_180 ( const struct V_810 * V_201 ,
struct V_753 * V_811 )
{
T_1 V_41 , V_98 ;
if ( V_201 -> V_755 > V_756 )
return - V_45 ;
if ( V_201 -> V_763 > V_812 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_201 -> V_755 ; V_41 ++ )
V_811 -> V_757 [ V_41 ] . V_758 = V_201 -> V_757 [ V_41 ] . V_758 ;
V_811 -> V_755 = V_201 -> V_755 ;
for ( V_41 = 0 ; V_41 < V_201 -> V_763 ; V_41 ++ ) {
V_811 -> V_764 [ V_41 ] . V_813 =
V_201 -> V_764 [ V_41 ] . V_813 ;
for ( V_98 = 0 ; V_98 < V_201 -> V_755 ; V_98 ++ )
V_811 -> V_764 [ V_41 ] . V_765 [ V_98 ] =
V_201 -> V_764 [ V_41 ] . V_765 [ V_98 ] ;
}
V_811 -> V_763 = V_201 -> V_763 ;
return 0 ;
}
static int F_181 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_810 * V_201 ;
struct V_753 * V_811 = & V_4 -> V_814 ;
T_1 V_815 = F_182 ( V_3 ) ;
int V_74 ;
V_201 = F_183 ( sizeof( struct V_810 ) , V_816 ) ;
if ( ! V_201 )
return - V_817 ;
F_26 ( V_775 , F_24 ( V_774 ) ) ;
F_26 ( V_785 , F_24 ( V_784 ) ) ;
F_26 ( V_777 , F_24 ( V_776 ) ) ;
F_26 ( V_779 , F_24 ( V_778 ) ) ;
F_26 ( V_781 , F_24 ( V_780 ) ) ;
F_26 ( V_783 , F_24 ( V_782 ) ) ;
F_26 ( V_791 , F_24 ( V_790 ) ) ;
F_26 ( V_793 , F_24 ( V_792 ) ) ;
F_26 ( V_787 , F_24 ( V_786 ) ) ;
F_26 ( V_789 , F_24 ( V_788 ) ) ;
F_26 ( V_762 , F_24 ( V_760 ) ) ;
F_26 ( V_767 , F_24 ( V_766 ) ) ;
F_26 ( V_771 , F_24 ( V_770 ) ) ;
F_26 ( V_799 , F_24 ( V_798 ) ) ;
F_26 ( V_801 , F_24 ( V_800 ) ) ;
F_26 ( V_795 , F_24 ( V_794 ) ) ;
F_26 ( V_797 , F_24 ( V_796 ) ) ;
F_26 ( V_803 , F_24 ( V_802 ) ) ;
F_26 ( V_805 , F_24 ( V_804 ) ) ;
F_26 ( V_807 , F_24 ( V_806 ) ) ;
V_74 = F_184 ( V_3 , V_815 , V_201 ) ;
if ( V_74 )
goto V_818;
V_74 = F_180 ( V_201 , V_811 ) ;
if ( V_74 )
goto V_818;
F_179 ( V_811 ) ;
V_74 = F_176 ( V_3 , V_811 ) ;
if ( V_74 )
goto V_818;
F_178 ( V_811 ) ;
V_818:
F_185 ( V_201 ) ;
return V_74 ;
}
static int F_186 ( struct V_2 * V_3 ,
T_14 * V_814 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 , V_98 ;
for ( V_41 = 0 , V_98 = 0 ; V_98 < V_4 -> V_814 . V_755 ; V_98 ++ ) {
if ( V_4 -> V_814 . V_808 & ( 1 << V_98 ) ) {
if ( V_41 >= V_756 )
return - V_45 ;
V_814 -> V_809 [ V_41 ] . V_761 = F_9 ( V_4 -> V_814 . V_757 [ V_98 ] . V_761 ) ;
V_814 -> V_809 [ V_41 ] . V_758 = F_9 ( V_4 -> V_814 . V_757 [ V_98 ] . V_758 ) ;
V_41 ++ ;
}
}
V_814 -> V_755 = ( T_1 ) V_41 ;
return 0 ;
}
static void F_187 ( const struct V_819 * V_820 ,
T_15 * V_128 ,
T_3 V_763 , T_3 V_808 )
{
T_3 V_41 , V_98 ;
for ( V_41 = 0 , V_98 = 0 ; V_98 < V_763 ; V_98 ++ ) {
if ( V_808 & ( 1 << V_98 ) ) {
V_128 -> V_57 [ V_41 ] = F_16 ( V_820 -> V_765 [ V_98 ] ) ;
V_41 ++ ;
}
}
}
static void F_188 ( struct V_2 * V_3 ,
const T_3 V_487 ,
T_15 * V_821 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 = 0 ;
for( V_41 = 0 ; V_41 < V_4 -> V_814 . V_763 ; V_41 ++ ) {
if ( V_487 <= V_4 -> V_814 . V_764 [ V_41 ] . V_813 )
break;
}
if ( ( V_41 == V_4 -> V_814 . V_763 ) && ( V_41 > 0 ) )
-- V_41 ;
F_187 ( & V_4 -> V_814 . V_764 [ V_41 ] ,
V_821 , V_4 -> V_814 . V_755 ,
V_4 -> V_814 . V_808 ) ;
}
static void F_189 ( struct V_2 * V_3 ,
T_14 * V_814 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_93 . V_436 . V_46 ; V_41 ++ )
F_188 ( V_3 ,
V_4 -> V_93 . V_436 . V_437 [ V_41 ] . V_57 ,
& V_814 -> V_128 [ V_41 ] ) ;
}
static int F_190 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_74 ;
memset ( & V_4 -> V_822 , 0 , sizeof( T_14 ) ) ;
V_74 = F_186 ( V_3 , & V_4 -> V_822 ) ;
if ( V_74 )
return V_74 ;
F_189 ( V_3 , & V_4 -> V_822 ) ;
return F_18 ( V_3 ,
V_4 -> V_285 ,
( T_1 * ) & V_4 -> V_822 ,
sizeof( T_14 ) ,
V_4 -> V_80 ) ;
}
static int F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! ( V_4 -> V_234 & V_240 ) )
return 0 ;
memset ( & V_4 -> V_822 , 0 , sizeof( T_14 ) ) ;
F_189 ( V_3 , & V_4 -> V_822 ) ;
return F_18 ( V_3 ,
V_4 -> V_285 +
F_12 ( T_14 , V_128 [ 0 ] ) ,
( T_1 * ) & V_4 -> V_822 . V_128 [ 0 ] ,
sizeof( T_15 ) *
V_4 -> V_93 . V_436 . V_46 ,
V_4 -> V_80 ) ;
}
static void F_192 ( struct V_2 * V_3 )
{
T_3 V_195 = F_23 ( V_226 ) ;
V_195 |= V_823 ;
F_25 ( V_226 , V_195 ) ;
}
static enum V_824 F_193 ( struct V_2 * V_3 ,
struct V_9 * V_714 )
{
struct V_8 * V_596 = F_2 ( V_714 ) ;
int V_41 ;
T_2 V_825 , V_826 = 0 ;
for ( V_41 = 0 ; V_41 < V_596 -> V_187 ; V_41 ++ ) {
V_825 = V_596 -> V_188 [ V_41 ] . V_638 ;
if ( V_826 < V_825 )
V_826 = V_825 ;
}
return V_826 ;
}
static T_2 F_194 ( struct V_2 * V_3 )
{
T_3 V_827 = 0 ;
V_827 = F_195 ( V_828 ) & V_829 ;
V_827 >>= V_830 ;
return ( T_2 ) V_827 ;
}
static int F_196 ( struct V_2 * V_3 )
{
T_3 V_831 = 0 ;
V_831 = F_195 ( V_832 ) & V_833 ;
V_831 >>= V_834 ;
switch ( V_831 ) {
case V_835 :
return 1 ;
case V_836 :
return 2 ;
case V_837 :
return 4 ;
case V_838 :
return 8 ;
case V_839 :
return 12 ;
case V_840 :
case V_841 :
default:
return 16 ;
}
}
static void F_197 ( struct V_2 * V_3 ,
struct V_9 * V_842 ,
struct V_9 * V_843 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_824 V_844 =
F_193 ( V_3 , V_842 ) ;
enum V_824 V_845 ;
if ( V_4 -> V_846 == V_847 )
V_845 = F_193 ( V_3 , V_843 ) ;
else
V_845 = V_4 -> V_846 ;
V_4 -> V_846 = V_847 ;
V_4 -> V_848 = false ;
if ( V_844 > V_845 ) {
switch ( V_844 ) {
#ifdef F_198
case V_849 :
if ( F_199 ( V_3 , V_850 , false ) == 0 )
break;
V_4 -> V_846 = V_851 ;
if ( V_845 == V_851 )
break;
case V_851 :
if ( F_199 ( V_3 , V_852 , false ) == 0 )
break;
#endif
default:
V_4 -> V_846 = F_194 ( V_3 ) ;
break;
}
} else {
if ( V_844 < V_845 )
V_4 -> V_848 = true ;
}
}
static void F_200 ( struct V_2 * V_3 ,
struct V_9 * V_842 ,
struct V_9 * V_843 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
enum V_824 V_844 =
F_193 ( V_3 , V_842 ) ;
T_1 V_853 ;
if ( V_4 -> V_848 ) {
if ( V_844 == V_849 )
V_853 = V_850 ;
else if ( V_844 == V_851 )
V_853 = V_852 ;
else
V_853 = V_854 ;
if ( ( V_853 == V_854 ) &&
( F_194 ( V_3 ) > 0 ) )
return;
#ifdef F_198
F_199 ( V_3 , V_853 , false ) ;
#endif
}
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_370 * V_647 =
& V_3 -> V_5 . V_6 . V_42 . V_47 ;
struct V_370 * V_855 =
& V_3 -> V_5 . V_6 . V_42 . V_190 ;
struct V_370 * V_856 =
& V_3 -> V_5 . V_6 . V_42 . V_189 ;
if ( V_647 == NULL )
return - V_45 ;
if ( V_647 -> V_46 < 1 )
return - V_45 ;
if ( V_855 == NULL )
return - V_45 ;
if ( V_855 -> V_46 < 1 )
return - V_45 ;
if ( V_856 == NULL )
return - V_45 ;
if ( V_856 -> V_46 < 1 )
return - V_45 ;
V_4 -> V_568 = V_647 -> V_44 [ 0 ] . V_376 ;
V_4 -> V_857 =
V_647 -> V_44 [ V_647 -> V_46 - 1 ] . V_376 ;
V_4 -> V_586 = V_856 -> V_44 [ 0 ] . V_376 ;
V_4 -> V_858 =
V_856 -> V_44 [ V_856 -> V_46 - 1 ] . V_376 ;
V_3 -> V_5 . V_6 . V_42 . V_185 . V_174 =
V_647 -> V_44 [ V_647 -> V_46 - 1 ] . V_407 ;
V_3 -> V_5 . V_6 . V_42 . V_185 . V_175 =
V_855 -> V_44 [ V_647 -> V_46 - 1 ] . V_407 ;
V_3 -> V_5 . V_6 . V_42 . V_185 . V_32 =
V_647 -> V_44 [ V_647 -> V_46 - 1 ] . V_376 ;
V_3 -> V_5 . V_6 . V_42 . V_185 . V_211 =
V_856 -> V_44 [ V_856 -> V_46 - 1 ] . V_376 ;
return 0 ;
}
static void F_202 ( struct V_2 * V_3 , T_2 * V_32 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_859 * V_860 = & V_4 -> V_212 ;
T_3 V_861 ;
for ( V_861 = 0 ; V_861 < V_860 -> V_46 ; V_861 ++ ) {
if ( V_860 -> V_209 [ V_861 ] == * V_32 ) {
* V_32 = V_860 -> V_216 [ V_861 ] ;
break;
}
}
}
static void F_203 ( struct V_2 * V_3 , T_2 * V_211 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_859 * V_860 = & V_4 -> V_213 ;
T_3 V_861 ;
for ( V_861 = 0 ; V_861 < V_860 -> V_46 ; V_861 ++ ) {
if ( V_860 -> V_209 [ V_861 ] == * V_211 ) {
* V_211 = V_860 -> V_216 [ V_861 ] ;
break;
}
}
}
static void F_204 ( struct V_2 * V_3 ,
struct V_370 * V_201 )
{
T_3 V_41 ;
if ( V_201 ) {
for ( V_41 = 0 ; V_41 < V_201 -> V_46 ; V_41 ++ )
F_202 ( V_3 , & V_201 -> V_44 [ V_41 ] . V_376 ) ;
}
}
static void F_205 ( struct V_2 * V_3 ,
struct V_370 * V_201 )
{
T_3 V_41 ;
if ( V_201 ) {
for ( V_41 = 0 ; V_41 < V_201 -> V_46 ; V_41 ++ )
F_203 ( V_3 , & V_201 -> V_44 [ V_41 ] . V_376 ) ;
}
}
static void F_206 ( struct V_2 * V_3 ,
struct V_862 * V_201 )
{
T_3 V_41 ;
if ( V_201 ) {
for ( V_41 = 0 ; V_41 < V_201 -> V_46 ; V_41 ++ )
F_202 ( V_3 , & V_201 -> V_44 [ V_41 ] . V_376 ) ;
}
}
static void F_207 ( struct V_2 * V_3 ,
struct V_863 * V_201 )
{
T_3 V_41 ;
if ( V_201 ) {
for ( V_41 = 0 ; V_41 < V_201 -> V_46 ; V_41 ++ )
F_202 ( V_3 , & V_201 -> V_44 [ V_41 ] . V_376 ) ;
}
}
static void F_208 ( struct V_2 * V_3 ,
struct V_413 * V_201 )
{
T_3 V_41 ;
if ( V_201 ) {
for ( V_41 = 0 ; V_41 < V_201 -> V_46 ; V_41 ++ )
F_202 ( V_3 , & V_201 -> V_44 [ V_41 ] . V_405 ) ;
}
}
static void F_209 ( struct V_2 * V_3 ,
struct V_171 * V_201 )
{
if ( V_201 ) {
F_202 ( V_3 , ( T_2 * ) & V_201 -> V_32 ) ;
F_203 ( V_3 , ( T_2 * ) & V_201 -> V_211 ) ;
}
}
static void F_210 ( struct V_2 * V_3 ,
struct V_649 * V_201 )
{
T_3 V_41 ;
if ( V_201 ) {
for ( V_41 = 0 ; V_41 < V_201 -> V_46 ; V_41 ++ )
F_202 ( V_3 , & V_201 -> V_44 [ V_41 ] . V_32 ) ;
}
}
static void F_211 ( struct V_2 * V_3 )
{
F_204 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_47 ) ;
F_204 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_190 ) ;
F_204 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_718 ) ;
F_205 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_189 ) ;
F_206 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_474 ) ;
F_207 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_461 ) ;
F_204 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_485 ) ;
F_204 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_482 ) ;
F_208 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_535 ) ;
F_209 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_185 ) ;
F_209 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_186 ) ;
F_210 ( V_3 ,
& V_3 -> V_5 . V_6 . V_42 . V_43 ) ;
}
static void F_212 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_195 ;
V_195 = F_24 ( V_864 ) ;
if ( ( ( V_195 & V_865 ) >> V_866 ) ==
V_867 )
V_4 -> V_170 = true ;
else
V_4 -> V_170 = false ;
}
void F_213 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_868 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_869 = * V_10 ;
V_4 -> V_870 = * V_868 ;
V_4 -> V_869 . V_12 = & V_4 -> V_870 ;
}
void F_214 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_868 = F_2 ( V_10 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_871 = * V_10 ;
V_4 -> V_872 = * V_868 ;
V_4 -> V_871 . V_12 = & V_4 -> V_872 ;
}
int F_215 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 V_872 = * V_3 -> V_5 . V_6 . V_872 ;
struct V_9 * V_868 = & V_872 ;
F_214 ( V_3 , V_868 ) ;
F_40 ( V_3 , & V_4 -> V_871 ) ;
return 0 ;
}
void F_216 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_868 = & V_4 -> V_871 ;
F_213 ( V_3 , V_868 ) ;
}
void F_217 ( struct V_2 * V_3 )
{
F_80 ( V_3 ) ;
F_212 ( V_3 ) ;
F_83 ( V_3 ) ;
F_81 ( V_3 ) ;
}
int F_218 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_655 = V_3 -> V_5 . V_6 . V_655 ;
int V_74 ;
F_219 ( V_3 , ( V_873 |
V_874 |
V_875 |
V_876 |
V_877 |
V_878 ) , false ) ;
if ( F_220 ( V_3 ) )
return - V_45 ;
if ( V_4 -> V_378 != V_406 ) {
F_192 ( V_3 ) ;
V_74 = F_100 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_2 ) ;
return V_74 ;
}
}
if ( V_4 -> V_879 ) {
V_74 = F_181 ( V_3 ) ;
if ( V_74 )
V_4 -> V_879 = false ;
}
if ( V_4 -> V_880 )
F_89 ( V_3 , true ) ;
if ( V_4 -> V_227 )
F_82 ( V_3 , true ) ;
F_90 ( V_3 ) ;
F_93 ( V_3 ) ;
F_95 ( V_3 ) ;
V_74 = F_97 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_3 ) ;
return V_74 ;
}
V_74 = F_79 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_4 ) ;
return V_74 ;
}
V_74 = F_115 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_5 ) ;
return V_74 ;
}
V_74 = F_164 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_6 ) ;
return V_74 ;
}
V_74 = F_112 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_7 ) ;
return V_74 ;
}
if ( V_4 -> V_879 ) {
V_74 = F_190 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_8 ) ;
return V_74 ;
}
}
V_74 = F_17 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_9 ) ;
return V_74 ;
}
F_72 ( V_3 ) ;
F_55 ( V_3 ) ;
V_74 = F_84 ( V_3 , false ) ;
if ( V_74 ) {
F_43 ( L_10 ) ;
return V_74 ;
}
F_63 ( V_3 , true ) ;
V_74 = F_149 ( V_3 , true ) ;
if ( V_74 ) {
F_43 ( L_11 ) ;
return V_74 ;
}
V_74 = F_85 ( V_3 , true ) ;
if ( V_74 ) {
F_43 ( L_12 ) ;
return V_74 ;
}
V_74 = F_60 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_13 ) ;
return V_74 ;
}
V_74 = F_27 ( V_3 , true ) ;
if ( V_74 ) {
F_43 ( L_14 ) ;
return V_74 ;
}
V_74 = F_33 ( V_3 , true ) ;
if ( V_74 ) {
F_43 ( L_15 ) ;
return V_74 ;
}
V_74 = F_30 ( V_3 , true ) ;
if ( V_74 ) {
F_43 ( L_16 ) ;
return V_74 ;
}
if ( V_3 -> V_881 . V_882 &&
F_221 ( V_3 -> V_5 . V_883 ) ) {
#if 0
PPSMC_Result result;
#endif
V_74 = F_42 ( V_3 , V_884 , V_885 ) ;
if ( V_74 ) {
F_43 ( L_17 ) ;
return V_74 ;
}
V_3 -> V_881 . V_886 = true ;
F_222 ( V_3 ) ;
#if 0
result = ci_send_msg_to_smc(rdev, PPSMC_MSG_EnableThermalInterrupt);
if (result != PPSMC_Result_OK)
DRM_DEBUG_KMS("Could not enable thermal interrupts.\n");
#endif
}
F_54 ( V_3 , V_221 , true ) ;
F_36 ( V_3 , true ) ;
F_219 ( V_3 , ( V_873 |
V_874 |
V_875 |
V_876 |
V_877 |
V_878 ) , true ) ;
F_213 ( V_3 , V_655 ) ;
return 0 ;
}
void F_223 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_655 = V_3 -> V_5 . V_6 . V_655 ;
F_219 ( V_3 , ( V_873 |
V_874 |
V_875 |
V_877 |
V_878 ) , false ) ;
F_36 ( V_3 , false ) ;
if ( ! F_220 ( V_3 ) )
return;
if ( V_4 -> V_227 )
F_82 ( V_3 , false ) ;
F_30 ( V_3 , false ) ;
F_33 ( V_3 , false ) ;
F_27 ( V_3 , false ) ;
F_89 ( V_3 , false ) ;
F_54 ( V_3 , V_221 , false ) ;
F_62 ( V_3 ) ;
F_85 ( V_3 , true ) ;
F_149 ( V_3 , false ) ;
F_96 ( V_3 ) ;
F_117 ( V_3 ) ;
F_76 ( V_3 ) ;
F_118 ( V_3 ) ;
F_213 ( V_3 , V_655 ) ;
}
int F_224 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_868 = & V_4 -> V_871 ;
struct V_9 * V_887 = & V_4 -> V_869 ;
int V_74 ;
F_219 ( V_3 , ( V_873 |
V_874 |
V_875 |
V_876 |
V_877 |
V_878 ) , false ) ;
F_170 ( V_3 , V_868 ) ;
if ( V_4 -> V_888 )
F_197 ( V_3 , V_868 , V_887 ) ;
V_74 = F_61 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_18 ) ;
return V_74 ;
}
V_74 = F_171 ( V_3 , V_868 ) ;
if ( V_74 ) {
F_43 ( L_19 ) ;
return V_74 ;
}
V_74 = F_173 ( V_3 , V_868 ) ;
if ( V_74 ) {
F_43 ( L_20 ) ;
return V_74 ;
}
#if 0
ret = ci_update_vce_dpm(rdev, new_ps, old_ps);
if (ret) {
DRM_ERROR("ci_update_vce_dpm failed\n");
return ret;
}
#endif
V_74 = F_49 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_21 ) ;
return V_74 ;
}
if ( V_4 -> V_879 ) {
V_74 = F_191 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_22 ) ;
return V_74 ;
}
}
V_74 = F_122 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_23 ) ;
return V_74 ;
}
V_74 = F_56 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_24 ) ;
return V_74 ;
}
V_74 = F_169 ( V_3 ) ;
if ( V_74 ) {
F_43 ( L_25 ) ;
return V_74 ;
}
if ( V_4 -> V_888 )
F_200 ( V_3 , V_868 , V_887 ) ;
F_219 ( V_3 , ( V_873 |
V_874 |
V_875 |
V_876 |
V_877 |
V_878 ) , true ) ;
return 0 ;
}
int F_225 ( struct V_2 * V_3 )
{
return F_34 ( V_3 ) ;
}
void F_226 ( struct V_2 * V_3 )
{
F_69 ( V_3 ) ;
}
void F_227 ( struct V_2 * V_3 )
{
F_86 ( V_3 ) ;
}
static void F_228 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_889 * V_890 ,
T_1 V_891 )
{
V_10 -> V_892 = F_229 ( V_890 -> V_893 ) ;
V_10 -> V_180 = F_230 ( V_890 -> V_894 ) ;
V_10 -> V_895 = F_230 ( V_890 -> V_896 ) ;
if ( V_897 < V_891 ) {
V_10 -> V_464 = F_229 ( V_890 -> V_898 ) ;
V_10 -> V_466 = F_229 ( V_890 -> V_899 ) ;
} else {
V_10 -> V_464 = 0 ;
V_10 -> V_466 = 0 ;
}
if ( V_10 -> V_180 & V_900 )
V_3 -> V_5 . V_6 . V_655 = V_10 ;
if ( V_10 -> V_180 & V_901 )
V_3 -> V_5 . V_6 . V_902 = V_10 ;
}
static void F_231 ( struct V_2 * V_3 ,
struct V_9 * V_10 , int V_637 ,
union V_903 * V_904 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_905 * V_906 = & V_11 -> V_188 [ V_637 ] ;
V_11 -> V_187 = V_637 + 1 ;
V_906 -> V_174 = F_230 ( V_904 -> V_907 . V_908 ) ;
V_906 -> V_174 |= V_904 -> V_907 . V_909 << 16 ;
V_906 -> V_175 = F_230 ( V_904 -> V_907 . V_910 ) ;
V_906 -> V_175 |= V_904 -> V_907 . V_911 << 16 ;
V_906 -> V_638 = F_232 ( V_3 ,
V_4 -> V_912 ,
V_4 -> V_669 . V_913 ,
V_904 -> V_907 . V_914 ) ;
V_906 -> V_716 = F_233 ( V_3 ,
V_4 -> V_669 . V_915 ,
F_230 ( V_904 -> V_907 . V_916 ) ) ;
if ( V_10 -> V_180 & V_917 ) {
V_4 -> V_918 = V_906 -> V_638 ;
}
if ( V_10 -> V_895 & V_919 ) {
V_4 -> V_592 . V_593 = true ;
V_4 -> V_592 . V_906 = * V_906 ;
V_4 -> V_592 . V_664 = V_920 ;
}
if ( V_10 -> V_180 & V_900 ) {
V_906 -> V_175 = V_4 -> V_669 . V_671 ;
V_906 -> V_174 = V_4 -> V_669 . V_670 ;
V_906 -> V_638 = V_4 -> V_669 . V_913 ;
V_906 -> V_716 = V_4 -> V_669 . V_915 ;
}
switch ( V_10 -> V_180 & V_181 ) {
case V_182 :
V_4 -> V_641 = true ;
if ( V_4 -> V_642 . V_83 < V_906 -> V_638 )
V_4 -> V_642 . V_83 = V_906 -> V_638 ;
if ( V_4 -> V_642 . V_82 > V_906 -> V_638 )
V_4 -> V_642 . V_82 = V_906 -> V_638 ;
if ( V_4 -> V_644 . V_83 < V_906 -> V_716 )
V_4 -> V_644 . V_83 = V_906 -> V_716 ;
if ( V_4 -> V_644 . V_82 > V_906 -> V_716 )
V_4 -> V_644 . V_82 = V_906 -> V_716 ;
break;
case V_921 :
V_4 -> V_640 = true ;
if ( V_4 -> V_643 . V_83 < V_906 -> V_638 )
V_4 -> V_643 . V_83 = V_906 -> V_638 ;
if ( V_4 -> V_643 . V_82 > V_906 -> V_638 )
V_4 -> V_643 . V_82 = V_906 -> V_638 ;
if ( V_4 -> V_645 . V_83 < V_906 -> V_716 )
V_4 -> V_645 . V_83 = V_906 -> V_716 ;
if ( V_4 -> V_645 . V_82 > V_906 -> V_716 )
V_4 -> V_645 . V_82 = V_906 -> V_716 ;
break;
default:
break;
}
}
static int F_234 ( struct V_2 * V_3 )
{
struct V_922 * V_923 = & V_3 -> V_923 ;
struct V_889 * V_890 ;
union V_924 * V_925 ;
int V_41 , V_98 , V_99 , V_926 , V_927 ;
union V_903 * V_904 ;
struct V_928 * V_929 ;
struct V_930 * V_931 ;
struct V_932 * V_933 ;
union V_934 * V_934 ;
int V_637 = F_235 ( V_935 , V_936 ) ;
T_2 V_937 ;
T_1 V_938 , V_939 ;
T_1 * V_940 ;
struct V_8 * V_11 ;
if ( ! F_236 ( V_923 -> V_941 , V_637 , NULL ,
& V_938 , & V_939 , & V_937 ) )
return - V_45 ;
V_934 = (union V_934 * ) ( V_923 -> V_941 -> V_942 + V_937 ) ;
V_929 = (struct V_928 * )
( V_923 -> V_941 -> V_942 + V_937 +
F_230 ( V_934 -> V_943 . V_944 ) ) ;
V_931 = (struct V_930 * )
( V_923 -> V_941 -> V_942 + V_937 +
F_230 ( V_934 -> V_943 . V_945 ) ) ;
V_933 = (struct V_932 * )
( V_923 -> V_941 -> V_942 + V_937 +
F_230 ( V_934 -> V_943 . V_946 ) ) ;
V_3 -> V_5 . V_6 . V_11 = F_183 ( sizeof( struct V_9 ) *
V_929 -> V_947 , V_816 ) ;
if ( ! V_3 -> V_5 . V_6 . V_11 )
return - V_817 ;
V_940 = ( T_1 * ) V_929 -> V_948 ;
V_3 -> V_5 . V_6 . V_48 = F_229 ( V_934 -> V_943 . V_949 ) ;
V_3 -> V_5 . V_6 . V_598 = F_230 ( V_934 -> V_943 . V_950 ) ;
V_3 -> V_5 . V_6 . V_951 = F_230 ( V_934 -> V_943 . V_952 ) ;
for ( V_41 = 0 ; V_41 < V_929 -> V_947 ; V_41 ++ ) {
T_1 * V_411 ;
V_925 = (union V_924 * ) V_940 ;
V_926 = V_925 -> V_953 . V_954 ;
V_890 = (struct V_889 * )
& V_933 -> V_955 [ V_926 ] ;
if ( ! V_3 -> V_5 . V_925 [ V_41 ] . V_904 )
return - V_45 ;
V_11 = F_183 ( sizeof( struct V_8 ) , V_816 ) ;
if ( V_11 == NULL ) {
F_185 ( V_3 -> V_5 . V_6 . V_11 ) ;
return - V_817 ;
}
V_3 -> V_5 . V_6 . V_11 [ V_41 ] . V_12 = V_11 ;
F_228 ( V_3 , & V_3 -> V_5 . V_6 . V_11 [ V_41 ] ,
V_890 ,
V_933 -> V_956 ) ;
V_99 = 0 ;
V_411 = ( T_1 * ) & V_925 -> V_953 . V_957 [ 0 ] ;
for ( V_98 = 0 ; V_98 < V_925 -> V_953 . V_958 ; V_98 ++ ) {
V_927 = V_411 [ V_98 ] ;
if ( V_927 >= V_931 -> V_947 )
continue;
if ( V_99 >= V_959 )
break;
V_904 = (union V_903 * )
( ( T_1 * ) & V_931 -> V_960 [ 0 ] +
( V_927 * V_931 -> V_956 ) ) ;
F_231 ( V_3 ,
& V_3 -> V_5 . V_6 . V_11 [ V_41 ] , V_99 ,
V_904 ) ;
V_99 ++ ;
}
V_940 += 2 + V_925 -> V_953 . V_958 ;
}
V_3 -> V_5 . V_6 . V_961 = V_929 -> V_947 ;
return 0 ;
}
int F_237 ( struct V_2 * V_3 ,
struct V_962 * V_439 )
{
struct V_922 * V_923 = & V_3 -> V_923 ;
int V_637 = F_235 ( V_935 , V_963 ) ;
T_16 * V_964 ;
T_1 V_938 , V_939 ;
T_2 V_937 ;
if ( F_236 ( V_923 -> V_941 , V_637 , NULL ,
& V_938 , & V_939 , & V_937 ) ) {
V_964 =
( T_16 * ) ( V_923 -> V_941 -> V_942 +
V_937 ) ;
V_439 -> V_677 = F_230 ( V_964 -> V_965 ) ;
V_439 -> V_673 = F_230 ( V_964 -> V_966 ) ;
V_439 -> V_675 = F_230 ( V_964 -> V_967 ) ;
V_439 -> V_913 = F_194 ( V_3 ) ;
V_439 -> V_915 = F_196 ( V_3 ) ;
V_439 -> V_670 = F_229 ( V_964 -> V_968 ) ;
V_439 -> V_671 = F_229 ( V_964 -> V_969 ) ;
return 0 ;
}
return - V_45 ;
}
void F_238 ( struct V_2 * V_3 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_5 . V_6 . V_961 ; V_41 ++ ) {
F_185 ( V_3 -> V_5 . V_6 . V_11 [ V_41 ] . V_12 ) ;
}
F_185 ( V_3 -> V_5 . V_6 . V_11 ) ;
F_185 ( V_3 -> V_5 . V_6 . V_7 ) ;
F_185 ( V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 ) ;
F_239 ( V_3 ) ;
}
int F_240 ( struct V_2 * V_3 )
{
int V_637 = F_235 ( V_935 , V_970 ) ;
T_2 V_937 , V_971 ;
T_1 V_938 , V_939 ;
struct V_1 * V_4 ;
int V_74 ;
T_3 V_141 ;
V_4 = F_183 ( sizeof( struct V_1 ) , V_816 ) ;
if ( V_4 == NULL )
return - V_817 ;
V_3 -> V_5 . V_6 . V_7 = V_4 ;
V_74 = F_241 ( V_3 -> V_972 , & V_141 ) ;
if ( V_74 )
V_4 -> V_912 = 0 ;
else
V_4 -> V_912 = V_141 ;
V_4 -> V_846 = V_847 ;
V_4 -> V_643 . V_83 = V_973 ;
V_4 -> V_643 . V_82 = V_849 ;
V_4 -> V_642 . V_83 = V_973 ;
V_4 -> V_642 . V_82 = V_849 ;
V_4 -> V_645 . V_83 = 0 ;
V_4 -> V_645 . V_82 = 16 ;
V_4 -> V_644 . V_83 = 0 ;
V_4 -> V_644 . V_82 = 16 ;
V_74 = F_237 ( V_3 , & V_4 -> V_669 ) ;
if ( V_74 ) {
F_238 ( V_3 ) ;
return V_74 ;
}
V_74 = F_234 ( V_3 ) ;
if ( V_74 ) {
F_238 ( V_3 ) ;
return V_74 ;
}
V_74 = F_242 ( V_3 ) ;
if ( V_74 ) {
F_238 ( V_3 ) ;
return V_74 ;
}
V_4 -> V_560 = false ;
V_4 -> V_80 = V_974 ;
V_4 -> V_627 [ 0 ] = V_975 ;
V_4 -> V_627 [ 1 ] = V_975 ;
V_4 -> V_627 [ 2 ] = V_975 ;
V_4 -> V_627 [ 3 ] = V_975 ;
V_4 -> V_627 [ 4 ] = V_975 ;
V_4 -> V_627 [ 5 ] = V_975 ;
V_4 -> V_627 [ 6 ] = V_975 ;
V_4 -> V_627 [ 7 ] = V_975 ;
V_4 -> V_541 = V_976 ;
V_4 -> V_235 = 0 ;
V_4 -> V_239 = 0 ;
V_4 -> V_259 = 0 ;
V_4 -> V_325 = true ;
V_4 -> V_553 = 40000 ;
V_4 -> V_549 = 40000 ;
V_4 -> V_555 = 40000 ;
V_4 -> V_556 = 40000 ;
F_3 ( V_3 ) ;
V_4 -> V_202 = false ;
V_4 -> V_206 = false ;
V_4 -> V_729 = true ;
F_50 ( V_3 ) ;
F_211 ( V_3 ) ;
F_201 ( V_3 ) ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 =
F_183 ( 4 * sizeof( struct V_977 ) , V_816 ) ;
if ( ! V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 ) {
F_238 ( V_3 ) ;
return - V_817 ;
}
V_3 -> V_5 . V_6 . V_42 . V_718 . V_46 = 4 ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 [ 0 ] . V_407 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 [ 0 ] . V_376 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 [ 1 ] . V_407 = 36000 ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 [ 1 ] . V_376 = 720 ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 [ 2 ] . V_407 = 54000 ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 [ 2 ] . V_376 = 810 ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 [ 3 ] . V_407 = 72000 ;
V_3 -> V_5 . V_6 . V_42 . V_718 . V_44 [ 3 ] . V_376 = 900 ;
V_3 -> V_5 . V_6 . V_42 . V_978 = 4 ;
V_3 -> V_5 . V_6 . V_42 . V_979 = 15000 ;
V_3 -> V_5 . V_6 . V_42 . V_980 = 200 ;
V_3 -> V_5 . V_6 . V_42 . V_981 . V_46 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_981 . V_982 = NULL ;
V_3 -> V_5 . V_6 . V_42 . V_983 . V_46 = 0 ;
V_3 -> V_5 . V_6 . V_42 . V_983 . V_982 = NULL ;
if ( V_3 -> V_984 == V_985 ) {
V_4 -> V_108 . V_690 = 94500 ;
V_4 -> V_108 . V_109 = 95000 ;
V_4 -> V_108 . V_986 = 104000 ;
} else {
V_4 -> V_108 . V_690 = 99500 ;
V_4 -> V_108 . V_109 = 100000 ;
V_4 -> V_108 . V_986 = 104000 ;
}
V_4 -> V_550 = false ;
V_4 -> V_378 = V_406 ;
V_4 -> V_384 = V_406 ;
V_4 -> V_388 = V_406 ;
if ( F_243 ( V_3 , V_380 , V_381 ) )
V_4 -> V_378 = V_379 ;
else if ( F_243 ( V_3 , V_380 , V_987 ) )
V_4 -> V_378 = V_382 ;
if ( V_3 -> V_5 . V_6 . V_48 & V_988 ) {
if ( F_243 ( V_3 , V_385 , V_381 ) )
V_4 -> V_384 = V_379 ;
else if ( F_243 ( V_3 , V_385 , V_987 ) )
V_4 -> V_384 = V_382 ;
else
V_3 -> V_5 . V_6 . V_48 &= ~ V_988 ;
}
if ( V_3 -> V_5 . V_6 . V_48 & V_989 ) {
if ( F_243 ( V_3 , V_389 , V_381 ) )
V_4 -> V_388 = V_379 ;
else if ( F_243 ( V_3 , V_389 , V_987 ) )
V_4 -> V_388 = V_382 ;
else
V_3 -> V_5 . V_6 . V_48 &= ~ V_989 ;
}
V_4 -> V_534 = true ;
#if F_244 ( F_198 )
V_4 -> V_888 =
F_245 ( V_3 ) ;
#else
V_4 -> V_888 = false ;
#endif
if ( F_236 ( V_3 -> V_923 . V_941 , V_637 , & V_971 ,
& V_938 , & V_939 , & V_937 ) ) {
V_4 -> V_341 = true ;
V_4 -> V_504 = true ;
V_4 -> V_880 = true ;
} else {
V_4 -> V_341 = false ;
V_4 -> V_504 = false ;
V_4 -> V_880 = true ;
}
if ( V_3 -> V_5 . V_883 != V_990 )
V_4 -> V_227 = true ;
else
V_4 -> V_227 = false ;
V_4 -> V_879 = true ;
V_4 -> V_167 = false ;
if ( ( V_3 -> V_5 . V_6 . V_42 . V_186 . V_174 == 0 ) ||
( V_3 -> V_5 . V_6 . V_42 . V_186 . V_175 == 0 ) )
V_3 -> V_5 . V_6 . V_42 . V_186 =
V_3 -> V_5 . V_6 . V_42 . V_185 ;
return 0 ;
}
void F_246 ( struct V_2 * V_3 ,
struct V_991 * V_992 )
{
T_3 V_174 = F_70 ( V_3 ) ;
T_3 V_175 = F_71 ( V_3 ) ;
F_247 ( V_992 , L_26 ,
V_174 , V_175 ) ;
}
void F_248 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( V_10 ) ;
struct V_905 * V_906 ;
int V_41 ;
F_249 ( V_10 -> V_180 , V_10 -> V_895 ) ;
F_250 ( V_10 -> V_892 ) ;
F_251 ( L_27 , V_10 -> V_464 , V_10 -> V_466 ) ;
for ( V_41 = 0 ; V_41 < V_11 -> V_187 ; V_41 ++ ) {
V_906 = & V_11 -> V_188 [ V_41 ] ;
F_251 ( L_28 ,
V_41 , V_906 -> V_174 , V_906 -> V_175 , V_906 -> V_638 + 1 , V_906 -> V_716 ) ;
}
F_252 ( V_3 , V_10 ) ;
}
T_3 F_253 ( struct V_2 * V_3 , bool V_993 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_994 = F_2 ( & V_4 -> V_871 ) ;
if ( V_993 )
return V_994 -> V_188 [ 0 ] . V_174 ;
else
return V_994 -> V_188 [ V_994 -> V_187 - 1 ] . V_174 ;
}
T_3 F_254 ( struct V_2 * V_3 , bool V_993 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_8 * V_994 = F_2 ( & V_4 -> V_871 ) ;
if ( V_993 )
return V_994 -> V_188 [ 0 ] . V_175 ;
else
return V_994 -> V_188 [ V_994 -> V_187 - 1 ] . V_175 ;
}
