void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
if ( V_6 &&
V_6 -> V_8 -> V_9 <= V_10 &&
V_6 -> V_8 -> V_9 )
V_3 -> V_11 =
& V_12
[ V_6 -> V_8 -> V_9 - 1 ] ;
else
V_3 -> V_11 = & V_12 [ 0 ] ;
}
static T_1 F_2 ( T_1 V_13 )
{
T_2 V_14 ;
V_14 = V_13 * 4096 / 100 ;
return ( T_1 ) V_14 ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_16 * V_17 = V_15 -> V_11 ;
T_3 * V_18 = & ( V_15 -> V_19 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
struct V_20 * V_8 = V_6 -> V_8 ;
struct V_21 * V_22 =
& V_2 -> V_23 . V_24 ;
int V_25 , V_26 , V_27 ;
const T_1 * V_28 ;
const T_1 * V_29 ;
V_18 -> V_30 = F_4 ( ( T_1 ) ( V_8 -> V_31 * 128 ) ) ;
V_18 -> V_32 = F_4 ( ( T_1 ) ( V_8 -> V_31 * 128 ) ) ;
F_5 ( V_8 -> V_33 <= 255 ,
L_1 ,
) ;
V_18 -> V_34 = F_4 (
V_8 -> V_33 * 256 ) ;
V_18 -> V_35 = F_4 (
V_8 -> V_36 * 256 ) ;
V_18 -> V_37 = F_4 (
F_2 ( V_22 -> V_38 ) ) ;
V_18 -> V_39 = F_4 (
F_2 ( V_22 -> V_40 ) ) ;
V_28 = V_17 -> V_41 ;
V_29 = V_17 -> V_42 ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
for ( V_26 = 0 ; V_26 < V_44 ; V_26 ++ ) {
for ( V_27 = 0 ; V_27 < V_45 ; V_27 ++ ) {
V_18 -> V_41 [ V_25 ] [ V_26 ] [ V_27 ] = F_4 ( * V_28 ) ;
V_18 -> V_42 [ V_25 ] [ V_26 ] [ V_27 ] = F_4 ( * V_29 ) ;
V_28 ++ ;
V_29 ++ ;
}
}
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_16 * V_17 = V_15 -> V_11 ;
V_15 -> V_46 . V_47 = V_17 -> V_47 ;
V_15 -> V_46 . V_48 = V_17 -> V_48 ;
V_15 -> V_46 . V_49 = 3 ;
V_15 -> V_46 . V_50 = 0 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_51 ;
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
const struct V_16 * V_17 = V_15 -> V_11 ;
V_51 = ( T_1 ) ( V_6 -> V_8 -> V_52 * 128 ) ;
V_15 -> V_46 . V_53 =
F_8 ( V_51 ) ;
V_15 -> V_46 . V_54 =
V_17 -> V_54 ;
V_15 -> V_46 . V_55 = V_17 -> V_55 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_56 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_16 * V_17 = V_15 -> V_11 ;
T_2 V_57 ;
if ( F_10 ( V_2 -> V_58 ,
V_56 +
F_11 ( V_59 , V_60 ) ,
( T_2 * ) & V_57 , V_15 -> V_61 ) )
F_5 (false,
L_2 ,
return -EINVAL) ;
else {
V_15 -> V_46 . V_60 = V_17 -> V_60 ;
V_15 -> V_46 . V_62 =
( V_63 ) ( ( V_57 >> 16 ) & 0xff ) ;
V_15 -> V_46 . V_64 =
( V_63 ) ( ( V_57 >> 8 ) & 0xff ) ;
V_15 -> V_46 . V_65 = ( V_63 ) ( V_57 & 0xff ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
V_15 -> V_46 . V_66 [ V_25 ] = 0 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
if ( ( V_2 -> V_23 . V_24 . V_67 & ( 1 << 15 ) )
|| 0 == V_2 -> V_23 . V_24 . V_67 )
V_2 -> V_23 . V_24 . V_67 =
V_2 -> V_23 . V_24 . V_68 ;
V_15 -> V_46 . V_69 = F_4 (
V_2 -> V_23 . V_24 . V_67 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
V_15 -> V_46 . V_70 [ V_25 ] = 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const bool V_71 )
{
T_2 V_72 = V_71 ? 1 : 0 ;
T_4 V_73 = 0 ;
T_2 V_15 ;
if ( F_17 ( V_2 -> V_74 . V_75 , V_76 ) ) {
V_15 = F_18 ( V_2 -> V_77 , V_78 , V_79 ) ;
V_15 &= ~ V_80 ;
V_15 |= ( ( V_72 << V_81 ) & V_80 ) ;
F_19 ( V_2 -> V_77 , V_78 , V_79 , V_15 ) ;
V_82 &= ~ V_83 ;
V_82 |= V_72 << V_84 ;
}
if ( F_17 ( V_2 -> V_74 . V_75 , V_85 ) ) {
V_15 = F_18 ( V_2 -> V_77 , V_78 , V_86 ) ;
V_15 &= ~ V_87 ;
V_15 |= ( ( V_72 << V_88 ) & V_87 ) ;
F_19 ( V_2 -> V_77 , V_78 , V_86 , V_15 ) ;
V_82 &= ~ V_89 ;
V_82 |= V_72 << V_90 ;
}
if ( F_17 ( V_2 -> V_74 . V_75 , V_91 ) ) {
V_15 = F_18 ( V_2 -> V_77 , V_78 , V_92 ) ;
V_15 &= ~ V_93 ;
V_15 |= ( ( V_72 << V_94 ) & V_93 ) ;
F_19 ( V_2 -> V_77 , V_78 , V_92 , V_15 ) ;
V_82 &= ~ V_95 ;
V_82 |= V_72 << V_96 ;
}
if ( F_17 ( V_2 -> V_74 . V_75 , V_97 ) ) {
V_15 = F_18 ( V_2 -> V_77 , V_78 , V_98 ) ;
V_15 &= ~ V_99 ;
V_15 |= ( ( V_72 << V_100 ) & V_99 ) ;
F_19 ( V_2 -> V_77 , V_78 , V_98 , V_15 ) ;
V_82 &= ~ V_101 ;
V_82 |= V_72 << V_102 ;
}
if ( V_71 )
V_73 = F_20 ( V_2 -> V_58 , V_103 , V_82 ) ;
return V_73 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_104 * V_106 = V_105 ;
T_2 V_107 = 0 ;
T_2 V_15 = 0 ;
F_5 ((config_regs != NULL), L_3 , return -EINVAL) ;
while ( V_106 -> V_108 != 0xFFFFFFFF ) {
if ( V_106 -> type == V_109 )
V_107 |= ( ( V_106 -> V_110 << V_106 -> V_111 ) & V_106 -> V_112 ) ;
else {
switch ( V_106 -> type ) {
case V_113 :
V_15 = F_18 ( V_2 -> V_77 , V_114 , V_106 -> V_108 ) ;
break;
case V_115 :
V_15 = F_18 ( V_2 -> V_77 , V_78 , V_106 -> V_108 ) ;
break;
case V_116 :
V_15 = F_18 ( V_2 -> V_77 , V_117 , V_106 -> V_108 ) ;
break;
default:
V_15 = F_22 ( V_2 -> V_77 , V_106 -> V_108 ) ;
break;
}
V_15 &= ~ V_106 -> V_112 ;
V_15 |= ( ( V_106 -> V_110 << V_106 -> V_111 ) & V_106 -> V_112 ) ;
V_15 |= V_107 ;
switch ( V_106 -> type ) {
case V_113 :
F_19 ( V_2 -> V_77 , V_114 , V_106 -> V_108 , V_15 ) ;
break;
case V_115 :
F_19 ( V_2 -> V_77 , V_78 , V_106 -> V_108 , V_15 ) ;
break;
case V_116 :
F_19 ( V_2 -> V_77 , V_117 , V_106 -> V_108 , V_15 ) ;
break;
default:
F_23 ( V_2 -> V_77 , V_106 -> V_108 , V_15 ) ;
break;
}
V_107 = 0 ;
}
V_106 ++ ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_73 ;
T_2 V_118 = 0 ;
T_2 V_119 , V_110 , V_120 ;
struct V_121 V_122 = { 0 } ;
V_122 . V_123 = sizeof( struct V_121 ) ;
V_122 . V_124 = V_125 ;
V_73 = F_25 ( V_2 -> V_77 , & V_122 ) ;
if ( V_73 == 0 )
V_118 = V_122 . V_110 ;
if ( F_17 ( V_2 -> V_74 . V_75 , V_76 ) ||
F_17 ( V_2 -> V_74 . V_75 , V_85 ) ||
F_17 ( V_2 -> V_74 . V_75 , V_91 ) ||
F_17 ( V_2 -> V_74 . V_75 , V_97 ) ) {
V_110 = 0 ;
V_120 = F_22 ( V_2 -> V_77 , V_126 ) ;
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
V_110 = V_127
| V_128
| ( V_119 << V_129 ) ;
F_23 ( V_2 -> V_77 , V_126 , V_110 ) ;
if ( V_2 -> V_130 == V_131 ) {
V_73 = F_21 ( V_2 , V_132 ) ;
F_5 ((result == 0), L_4 , return result) ;
V_73 = F_21 ( V_2 , V_133 ) ;
F_5 ((result == 0), L_4 , return result) ;
} else if ( V_2 -> V_130 == V_134 ) {
V_73 = F_21 ( V_2 , V_135 ) ;
F_5 ((result == 0), L_4 , return result) ;
V_73 = F_21 ( V_2 , V_136 ) ;
F_5 ((result == 0), L_4 , return result) ;
}
}
F_23 ( V_2 -> V_77 , V_126 , V_120 ) ;
V_73 = F_16 ( V_2 , true ) ;
F_5 ((result == 0), L_5 , return result) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_73 ;
if ( F_17 ( V_2 -> V_74 . V_75 , V_76 ) ||
F_17 ( V_2 -> V_74 . V_75 , V_85 ) ||
F_17 ( V_2 -> V_74 . V_75 , V_91 ) ||
F_17 ( V_2 -> V_74 . V_75 , V_97 ) ) {
V_73 = F_16 ( V_2 , false ) ;
F_5 ((result == 0), L_6 , return result) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
T_1 V_137 = V_15 -> V_46 . V_138 ;
T_1 V_139 = V_15 -> V_46 . V_140 ;
struct V_20 * V_141 = V_6 -> V_8 ;
V_137 = ( T_1 ) ( V_141 -> V_142 / 100 * 256 ) ;
V_139 = ( T_1 ) ( V_141 -> V_143 / 100 * 256 ) ;
V_15 -> V_46 . V_138 =
F_8 ( V_137 ) ;
V_15 -> V_46 . V_140 =
F_8 ( V_139 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
T_2 V_144 ;
if ( F_17 ( V_2 -> V_74 . V_75 ,
V_145 ) ) {
if ( F_10 ( V_2 -> V_58 ,
V_146 +
F_11 ( V_147 , V_148 ) ,
& V_144 , V_15 -> V_61 ) )
F_5 (false,
L_7 ,
return -EINVAL) ;
if ( F_6 ( V_2 ) )
F_5 (false,
L_8 ,
return -EINVAL) ;
if ( F_7 ( V_2 ) )
F_5 (false,
L_9 , return -EINVAL) ;
if ( F_9 ( V_2 , V_144 ) )
F_5 (false,
L_10
L_11 ,
return -EINVAL) ;
if ( 0 != F_12 ( V_2 ) )
F_5 (false,
L_12 ,
return -EINVAL) ;
if ( F_13 ( V_2 ) )
F_5 (false,
L_13 ,
return -EINVAL) ;
if ( F_14 ( V_2 ) )
F_5 (false,
L_14 ,
return -EINVAL) ;
if ( F_15 ( V_2 ) )
F_5 (false,
L_15 ,
return -EINVAL) ;
if ( F_27 ( V_2 ) )
F_5 (false,
L_16
L_17 , return -EINVAL) ;
if ( F_29 ( V_2 -> V_58 , V_144 ,
( V_63 * ) & V_15 -> V_46 ,
( sizeof( struct V_59 ) - 92 ) , V_15 -> V_61 ) )
F_5 (false,
L_18 ,
return -EINVAL) ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
int V_73 = 0 ;
if ( F_17 ( V_2 -> V_74 . V_75 ,
V_149 ) ) {
int V_150 ;
V_150 = F_31 ( V_2 -> V_58 ,
( T_1 ) ( V_151 ) ) ;
F_5 ( ( 0 == V_150 ) ,
L_19 , V_73 = - 1 ) ;
V_15 -> V_152 = ( 0 == V_150 ) ? true : false ;
}
return V_73 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
int V_73 = 0 ;
if ( F_17 ( V_2 -> V_74 . V_75 ,
V_149 ) && V_15 -> V_152 ) {
int V_150 = F_31 ( V_2 -> V_58 ,
( T_1 ) ( V_153 ) ) ;
F_5 ( ( V_150 == 0 ) ,
L_20 , V_73 = - 1 ) ;
V_15 -> V_152 = false ;
}
return V_73 ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_154 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
if ( V_15 -> V_155 &
V_156 )
return F_20 ( V_2 -> V_58 ,
V_157 , V_154 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_158 , T_2 V_159 )
{
return F_20 ( V_158 -> V_58 ,
V_160 , V_159 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
int V_150 ;
int V_73 = 0 ;
V_15 -> V_155 = 0 ;
if ( F_17 ( V_2 -> V_74 . V_75 ,
V_145 ) ) {
if ( V_15 -> V_161 ) {
V_150 = F_31 ( V_2 -> V_58 ,
( T_1 ) ( V_162 ) ) ;
F_5 ((0 == smc_result),
L_21 , result = -1;) ;
if ( 0 == V_150 )
V_15 -> V_155 |=
V_163 ;
}
if ( V_15 -> V_164 ) {
V_150 = F_31 ( V_2 -> V_58 ,
( T_1 ) ( V_165 ) ) ;
F_5 ((0 == smc_result),
L_22 , result = -1;) ;
if ( 0 == V_150 ) {
struct V_20 * V_141 =
V_6 -> V_8 ;
T_2 V_166 =
( T_2 ) ( V_141 -> V_167 * 256 ) ;
V_15 -> V_155 |=
V_156 ;
if ( F_33 ( V_2 , V_166 ) )
F_36 ( V_168 L_23 ) ;
}
}
}
return V_73 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_15 = (struct V_3 * ) ( V_2 -> V_4 ) ;
int V_73 = 0 ;
if ( F_17 ( V_2 -> V_74 . V_75 ,
V_145 ) &&
V_15 -> V_155 ) {
int V_150 ;
if ( V_15 -> V_155 &
V_163 ) {
V_150 = F_31 ( V_2 -> V_58 ,
( T_1 ) ( V_169 ) ) ;
F_5 ( ( V_150 == 0 ) ,
L_24 ,
V_73 = V_150 ) ;
}
if ( V_15 -> V_155 &
V_170 ) {
V_150 = F_31 ( V_2 -> V_58 ,
( T_1 ) ( V_171 ) ) ;
F_5 ( ( V_150 == 0 ) ,
L_25 ,
V_73 = V_150 ) ;
}
if ( V_15 -> V_155 &
V_156 ) {
V_150 = F_31 ( V_2 -> V_58 ,
( T_1 ) ( V_172 ) ) ;
F_5 ( ( V_150 == 0 ) ,
L_26 ,
V_73 = V_150 ) ;
}
V_15 -> V_155 = 0 ;
}
return V_73 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
struct V_20 * V_141 = V_6 -> V_8 ;
int V_173 , V_159 ;
int V_73 = 0 ;
if ( F_17 ( V_2 -> V_74 . V_75 ,
V_145 ) ) {
V_173 = V_2 -> V_74 . V_174 ?
V_2 -> V_74 . V_175 :
( - 1 * V_2 -> V_74 . V_175 ) ;
V_159 = ( ( 100 + V_173 ) * ( int ) ( V_141 -> V_31 * 256 ) ) / 100 ;
V_73 = F_34 ( V_2 , ( T_2 ) V_159 ) ;
}
return V_73 ;
}
