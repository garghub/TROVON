void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
T_1 V_8 = 0 ;
if( V_6 &&
V_6 -> V_9 -> V_10 <= V_11 &&
V_6 -> V_9 -> V_10 )
V_3 -> V_12 =
& V_13
[ V_6 -> V_9 -> V_10 - 1 ] ;
else
V_3 -> V_12 = & V_13 [ 0 ] ;
F_2 ( V_2 -> V_14 . V_15 ,
V_16 ) ;
F_2 ( V_2 -> V_14 . V_15 ,
V_17 ) ;
F_2 ( V_2 -> V_14 . V_15 ,
V_18 ) ;
F_2 ( V_2 -> V_14 . V_15 ,
V_19 ) ;
F_2 ( V_2 -> V_14 . V_15 ,
V_20 ) ;
F_2 ( V_2 -> V_14 . V_15 ,
V_21 ) ;
V_3 -> V_22 = V_8 ;
if ( ! V_8 ) {
F_3 ( V_2 -> V_14 . V_15 ,
V_16 ) ;
F_3 ( V_2 -> V_14 . V_15 ,
V_17 ) ;
V_3 -> V_23 = 100 ;
V_8 = 1 ;
V_3 -> V_24 = V_8 ? false : true ;
V_3 -> V_25 = V_8 ? true : false ;
V_3 -> V_26 = V_8 ? true : false ;
}
}
static T_2 F_4 ( T_2 V_27 )
{
T_1 V_8 ;
V_8 = V_27 * 4096 / 100 ;
return ( T_2 ) V_8 ;
}
static void F_5 ( T_3 line , T_3 * V_28 , T_3 * V_29 )
{
switch ( line ) {
case V_30 :
* V_28 = V_31 ;
* V_29 = V_32 ;
break;
case V_33 :
* V_28 = V_34 ;
* V_29 = V_35 ;
break;
case V_36 :
* V_28 = V_37 ;
* V_29 = V_38 ;
break;
case V_39 :
* V_28 = V_40 ;
* V_29 = V_41 ;
break;
case V_42 :
* V_28 = V_43 ;
* V_29 = V_44 ;
break;
case V_45 :
* V_28 = V_46 ;
* V_29 = V_47 ;
break;
case V_48 :
* V_28 = V_49 ;
* V_29 = V_50 ;
break;
case V_51 :
* V_28 = V_52 ;
* V_29 = V_53 ;
break;
default:
* V_28 = 0 ;
* V_29 = 0 ;
break;
}
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_55 * V_56 = V_54 -> V_12 ;
T_4 * V_57 = & ( V_54 -> V_58 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
struct V_59 * V_9 = V_6 -> V_9 ;
struct V_60 * V_61 =
& V_2 -> V_62 . V_63 ;
T_3 V_64 , V_65 ;
V_57 -> V_66 = F_7 (
( T_2 ) ( V_9 -> V_67 * 128 ) ) ;
V_57 -> V_68 = F_7 (
( T_2 ) ( V_9 -> V_67 * 128 ) ) ;
F_8 ( V_9 -> V_69 <= 255 ,
L_1 ,) ;
V_57 -> V_70 = ( T_3 ) ( V_9 -> V_69 ) ;
V_57 -> V_71 = 8 ;
V_57 -> V_72 = V_56 -> V_72 ;
V_57 -> V_73 = F_7 (
V_9 -> V_69 * 256 ) ;
V_57 -> V_74 = F_7 (
V_9 -> V_75 * 256 ) ;
V_57 -> V_76 = F_7 (
V_9 -> V_77 * 256 ) ;
V_57 -> V_78 = F_7 (
V_9 -> V_79 * 256 ) ;
V_57 -> V_80 = F_7 (
V_9 -> V_81 * 256 ) ;
V_57 -> V_82 = F_7 (
V_9 -> V_83 * 256 ) ;
V_57 -> V_84 = F_7 (
V_9 -> V_85 * 256 ) ;
V_57 -> V_86 = F_7 (
F_4 ( V_61 -> V_87 ) ) ;
V_57 -> V_88 = F_7 (
F_4 ( V_61 -> V_89 ) ) ;
V_57 -> V_90 = F_7 (
F_4 ( V_61 -> V_91 ) ) ;
V_57 -> V_92 = F_7 (
F_4 ( V_61 -> V_93 ) ) ;
V_57 -> V_94 = F_7 (
F_4 ( V_61 -> V_95 ) ) ;
V_57 -> V_96 = F_7 (
F_4 ( V_61 -> V_97 ) ) ;
V_57 -> V_98 = F_7 (
F_4 ( V_61 -> V_99 ) ) ;
V_57 -> V_100 = V_9 -> V_101 ;
V_57 -> V_102 = V_9 -> V_103 ;
V_57 -> V_104 = V_9 -> V_105 ;
V_57 -> V_106 = V_9 -> V_107 ;
F_5 ( V_9 -> V_108 , & V_64 , & V_65 ) ;
V_57 -> V_109 = V_64 ;
V_57 -> V_110 = V_65 ;
F_5 ( V_9 -> V_111 , & V_64 , & V_65 ) ;
V_57 -> V_112 = V_64 ;
V_57 -> V_113 = V_65 ;
F_5 ( V_9 -> V_114 , & V_64 , & V_65 ) ;
V_57 -> V_115 = V_64 ;
V_57 -> V_116 = V_65 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_55 * V_56 = V_54 -> V_12 ;
V_54 -> V_117 . V_118 = V_56 -> V_118 ;
V_54 -> V_117 . V_119 = V_56 -> V_119 ;
V_54 -> V_117 . V_120 = 3 ;
V_54 -> V_117 . V_121 = 0 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_122 ;
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
const struct V_55 * V_56 = V_54 -> V_12 ;
V_122 = ( T_2 ) ( V_6 -> V_9 -> V_123 * 128 ) ;
V_54 -> V_117 . V_124 =
F_11 ( V_122 ) ;
V_54 -> V_117 . V_125 =
V_56 -> V_125 ;
V_54 -> V_117 . V_126 = V_56 -> V_126 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_127 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_55 * V_56 = V_54 -> V_12 ;
T_1 V_128 ;
if ( F_13 ( V_2 -> V_129 ,
V_127 +
F_14 ( V_130 , V_131 ) ,
( T_1 * ) & V_128 , V_54 -> V_132 ) )
F_8 (false,
L_2 ,
return -EINVAL) ;
else {
V_54 -> V_117 . V_131 = V_56 -> V_131 ;
V_54 -> V_117 . V_133 =
( T_3 ) ( ( V_128 >> 16 ) & 0xff ) ;
V_54 -> V_117 . V_134 =
( T_3 ) ( ( V_128 >> 8 ) & 0xff ) ;
V_54 -> V_117 . V_135 = ( T_3 ) ( V_128 & 0xff ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_136 ;
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
for ( V_136 = 0 ; V_136 < 16 ; V_136 ++ )
V_54 -> V_117 . V_137 [ V_136 ] = 0 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
if( ( V_2 -> V_62 . V_63 .
V_138 & ( 1 << 15 ) ) ||
0 == V_2 -> V_62 . V_63 .
V_138 )
V_2 -> V_62 . V_63 .
V_138 = V_2 -> V_62 .
V_63 . V_139 ;
V_54 -> V_117 . V_140 =
F_7 ( V_2 -> V_62 .
V_63 . V_138 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_136 ;
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
for ( V_136 = 0 ; V_136 < 16 ; V_136 ++ )
V_54 -> V_117 . V_141 [ V_136 ] = 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
T_2 V_142 = V_54 -> V_117 . V_143 ;
T_2 V_144 = V_54 -> V_117 . V_145 ;
struct V_59 * V_146 = V_6 -> V_9 ;
V_142 = ( T_2 ) ( V_146 -> V_147 / 100 * 256 ) ;
V_144 = ( T_2 ) ( V_146 -> V_148 / 100 * 256 ) ;
V_54 -> V_117 . V_143 =
F_11 ( V_142 ) ;
V_54 -> V_117 . V_145 =
F_11 ( V_144 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
T_1 V_149 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_16 ) ) {
if ( F_13 ( V_2 -> V_129 ,
V_150 +
F_14 ( V_151 , V_152 ) ,
& V_149 , V_54 -> V_132 ) )
F_8 (false,
L_3 ,
return -EINVAL) ;
if ( F_9 ( V_2 ) )
F_8 (false,
L_4 ,
return -EINVAL) ;
if ( F_10 ( V_2 ) )
F_8 (false,
L_5 , return -EINVAL) ;
if ( F_12 ( V_2 , V_149 ) )
F_8 (false,
L_6
L_7 ,
return -EINVAL) ;
if ( 0 != F_15 ( V_2 ) )
F_8 (false,
L_8 ,
return -EINVAL) ;
if( F_16 ( V_2 ) )
F_8 (false,
L_9 ,
return -EINVAL) ;
if ( F_17 ( V_2 ) )
F_8 (false,
L_10 ,
return -EINVAL) ;
if ( F_18 ( V_2 ) )
F_8 (false,
L_11 ,
return -EINVAL) ;
if ( F_19 ( V_2 ) )
F_8 (false,
L_12
L_13 , return -EINVAL) ;
if ( F_22 ( V_2 -> V_129 , V_149 ,
( T_3 * ) & V_54 -> V_117 ,
sizeof( struct V_130 ) , V_54 -> V_132 ) )
F_8 (false,
L_14 ,
return -EINVAL) ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
int V_153 = 0 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_17 ) ) {
int V_154 ;
V_154 = F_24 ( V_2 -> V_129 ,
( T_2 ) ( V_155 ) ) ;
F_8 ( ( 0 == V_154 ) ,
L_15 , V_153 = - 1 ) ;
V_54 -> V_156 = ( 0 == V_154 ) ? true : false ;
}
return V_153 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_157 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
if( V_54 -> V_158 &
V_159 )
return F_26 ( V_2 -> V_129 ,
V_160 , V_157 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_161 , T_1 V_162 )
{
return F_26 ( V_161 -> V_129 ,
V_163 , V_162 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
int V_154 ;
int V_153 = 0 ;
V_54 -> V_158 = 0 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_16 ) ) {
if ( V_54 -> V_24 ) {
V_154 = F_24 ( V_2 -> V_129 ,
( T_2 ) ( V_164 ) ) ;
F_8 ((0 == smc_result),
L_16 , result = -1;) ;
if ( 0 == V_154 )
V_54 -> V_158 |= V_165 ;
}
if ( V_54 -> V_25 ) {
V_154 = F_24 ( V_2 -> V_129 ,
( T_2 ) ( V_166 ) ) ;
F_8 ((0 == smc_result),
L_17 , result = -1;) ;
if ( 0 == V_154 )
V_54 -> V_158 |=
V_167 ;
}
if ( V_54 -> V_26 ) {
V_154 = F_24 ( V_2 -> V_129 ,
( T_2 ) ( V_168 ) ) ;
F_8 ((0 == smc_result),
L_18 , result = -1;) ;
if ( 0 == V_154 ) {
struct V_59 * V_146 =
V_6 -> V_9 ;
T_1 V_169 =
( T_1 ) ( V_146 -> V_170 * 256 ) ;
V_54 -> V_158 |=
V_159 ;
if ( F_25 ( V_2 , V_169 ) )
F_29 ( V_171 L_19 ) ;
}
}
}
return V_153 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
struct V_59 * V_146 = V_6 -> V_9 ;
int V_172 , V_162 ;
int V_153 = 0 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_16 ) ) {
V_172 = V_2 -> V_14 . V_173 ?
V_2 -> V_14 . V_174 :
( - 1 * V_2 -> V_14 . V_174 ) ;
V_162 = ( ( 100 + V_172 ) * ( int ) ( V_146 -> V_67 * 256 ) ) / 100 ;
V_153 = F_27 ( V_2 , ( T_1 ) V_162 ) ;
}
return V_153 ;
}
