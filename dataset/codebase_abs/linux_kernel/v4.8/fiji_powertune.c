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
V_17 ) ;
V_3 -> V_23 = 100 ;
if ( V_2 -> V_24 ) {
F_3 ( V_2 -> V_14 . V_15 ,
V_16 ) ;
V_8 = 1 ;
V_3 -> V_25 = V_8 ? false : true ;
V_3 -> V_26 = V_8 ? true : false ;
V_3 -> V_27 = V_8 ? true : false ;
}
}
}
static T_2 F_4 ( T_2 V_28 )
{
T_1 V_8 ;
V_8 = V_28 * 4096 / 100 ;
return ( T_2 ) V_8 ;
}
static void F_5 ( T_3 line , T_3 * V_29 , T_3 * V_30 )
{
switch ( line ) {
case V_31 :
* V_29 = V_32 ;
* V_30 = V_33 ;
break;
case V_34 :
* V_29 = V_35 ;
* V_30 = V_36 ;
break;
case V_37 :
* V_29 = V_38 ;
* V_30 = V_39 ;
break;
case V_40 :
* V_29 = V_41 ;
* V_30 = V_42 ;
break;
case V_43 :
* V_29 = V_44 ;
* V_30 = V_45 ;
break;
case V_46 :
* V_29 = V_47 ;
* V_30 = V_48 ;
break;
case V_49 :
* V_29 = V_50 ;
* V_30 = V_51 ;
break;
case V_52 :
* V_29 = V_53 ;
* V_30 = V_54 ;
break;
default:
* V_29 = 0 ;
* V_30 = 0 ;
break;
}
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_56 * V_57 = V_55 -> V_12 ;
T_4 * V_58 = & ( V_55 -> V_59 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
struct V_60 * V_9 = V_6 -> V_9 ;
struct V_61 * V_62 =
& V_2 -> V_63 . V_64 ;
T_3 V_65 , V_66 ;
V_58 -> V_67 = F_7 (
( T_2 ) ( V_9 -> V_68 * 128 ) ) ;
V_58 -> V_69 = F_7 (
( T_2 ) ( V_9 -> V_68 * 128 ) ) ;
F_8 ( V_9 -> V_70 <= 255 ,
L_1 ,) ;
V_58 -> V_71 = ( T_3 ) ( V_9 -> V_70 ) ;
V_58 -> V_72 = 8 ;
V_58 -> V_73 = V_57 -> V_73 ;
V_58 -> V_74 = F_7 (
V_9 -> V_70 * 256 ) ;
V_58 -> V_75 = F_7 (
V_9 -> V_76 * 256 ) ;
V_58 -> V_77 = F_7 (
V_9 -> V_78 * 256 ) ;
V_58 -> V_79 = F_7 (
V_9 -> V_80 * 256 ) ;
V_58 -> V_81 = F_7 (
V_9 -> V_82 * 256 ) ;
V_58 -> V_83 = F_7 (
V_9 -> V_84 * 256 ) ;
V_58 -> V_85 = F_7 (
V_9 -> V_86 * 256 ) ;
V_58 -> V_87 = F_7 (
F_4 ( V_62 -> V_88 ) ) ;
V_58 -> V_89 = F_7 (
F_4 ( V_62 -> V_90 ) ) ;
V_58 -> V_91 = F_7 (
F_4 ( V_62 -> V_92 ) ) ;
V_58 -> V_93 = F_7 (
F_4 ( V_62 -> V_94 ) ) ;
V_58 -> V_95 = F_7 (
F_4 ( V_62 -> V_96 ) ) ;
V_58 -> V_97 = F_7 (
F_4 ( V_62 -> V_98 ) ) ;
V_58 -> V_99 = F_7 (
F_4 ( V_62 -> V_100 ) ) ;
V_58 -> V_101 = V_9 -> V_102 ;
V_58 -> V_103 = V_9 -> V_104 ;
V_58 -> V_105 = V_9 -> V_106 ;
V_58 -> V_107 = V_9 -> V_108 ;
F_5 ( V_9 -> V_109 , & V_65 , & V_66 ) ;
V_58 -> V_110 = V_65 ;
V_58 -> V_111 = V_66 ;
F_5 ( V_9 -> V_112 , & V_65 , & V_66 ) ;
V_58 -> V_113 = V_65 ;
V_58 -> V_114 = V_66 ;
F_5 ( V_9 -> V_115 , & V_65 , & V_66 ) ;
V_58 -> V_116 = V_65 ;
V_58 -> V_117 = V_66 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_56 * V_57 = V_55 -> V_12 ;
V_55 -> V_118 . V_119 = V_57 -> V_119 ;
V_55 -> V_118 . V_120 = V_57 -> V_120 ;
V_55 -> V_118 . V_121 = 3 ;
V_55 -> V_118 . V_122 = 0 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_123 ;
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
const struct V_56 * V_57 = V_55 -> V_12 ;
V_123 = ( T_2 ) ( V_6 -> V_9 -> V_124 * 128 ) ;
V_55 -> V_118 . V_125 =
F_11 ( V_123 ) ;
V_55 -> V_118 . V_126 =
V_57 -> V_126 ;
V_55 -> V_118 . V_127 = V_57 -> V_127 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
const struct V_56 * V_57 = V_55 -> V_12 ;
T_1 V_129 ;
if ( F_13 ( V_2 -> V_130 ,
V_128 +
F_14 ( V_131 , V_132 ) ,
( T_1 * ) & V_129 , V_55 -> V_133 ) )
F_8 (false,
L_2 ,
return -EINVAL) ;
else {
V_55 -> V_118 . V_132 = V_57 -> V_132 ;
V_55 -> V_118 . V_134 =
( T_3 ) ( ( V_129 >> 16 ) & 0xff ) ;
V_55 -> V_118 . V_135 =
( T_3 ) ( ( V_129 >> 8 ) & 0xff ) ;
V_55 -> V_118 . V_136 = ( T_3 ) ( V_129 & 0xff ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_137 ;
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
for ( V_137 = 0 ; V_137 < 16 ; V_137 ++ )
V_55 -> V_118 . V_138 [ V_137 ] = 0 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
if( ( V_2 -> V_63 . V_64 .
V_139 & ( 1 << 15 ) ) ||
0 == V_2 -> V_63 . V_64 .
V_139 )
V_2 -> V_63 . V_64 .
V_139 = V_2 -> V_63 .
V_64 . V_140 ;
V_55 -> V_118 . V_141 =
F_7 ( V_2 -> V_63 .
V_64 . V_139 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_137 ;
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
for ( V_137 = 0 ; V_137 < 16 ; V_137 ++ )
V_55 -> V_118 . V_142 [ V_137 ] = 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
T_2 V_143 = V_55 -> V_118 . V_144 ;
T_2 V_145 = V_55 -> V_118 . V_146 ;
struct V_60 * V_147 = V_6 -> V_9 ;
V_143 = ( T_2 ) ( V_147 -> V_148 / 100 * 256 ) ;
V_145 = ( T_2 ) ( V_147 -> V_149 / 100 * 256 ) ;
V_55 -> V_118 . V_144 =
F_11 ( V_143 ) ;
V_55 -> V_118 . V_146 =
F_11 ( V_145 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
T_1 V_150 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_16 ) ) {
if ( F_13 ( V_2 -> V_130 ,
V_151 +
F_14 ( V_152 , V_153 ) ,
& V_150 , V_55 -> V_133 ) )
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
if ( F_12 ( V_2 , V_150 ) )
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
if ( F_22 ( V_2 -> V_130 , V_150 ,
( T_3 * ) & V_55 -> V_118 ,
sizeof( struct V_131 ) , V_55 -> V_133 ) )
F_8 (false,
L_14 ,
return -EINVAL) ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
int V_154 = 0 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_17 ) ) {
int V_155 ;
V_155 = F_24 ( V_2 -> V_130 ,
( T_2 ) ( V_156 ) ) ;
F_8 ( ( 0 == V_155 ) ,
L_15 , V_154 = - 1 ) ;
V_55 -> V_157 = ( 0 == V_155 ) ? true : false ;
}
return V_154 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
int V_154 = 0 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_17 ) && V_55 -> V_157 ) {
int V_155 = F_24 ( V_2 -> V_130 ,
( T_2 ) ( V_158 ) ) ;
F_8 ( ( V_155 == 0 ) ,
L_16 , V_154 = - 1 ) ;
V_55 -> V_157 = false ;
}
return V_154 ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_159 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
if( V_55 -> V_160 &
V_161 )
return F_27 ( V_2 -> V_130 ,
V_162 , V_159 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_163 , T_1 V_164 )
{
return F_27 ( V_163 -> V_130 ,
V_165 , V_164 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
int V_155 ;
int V_154 = 0 ;
V_55 -> V_160 = 0 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_16 ) ) {
if ( V_55 -> V_25 ) {
V_155 = F_24 ( V_2 -> V_130 ,
( T_2 ) ( V_166 ) ) ;
F_8 ((0 == smc_result),
L_17 , result = -1;) ;
if ( 0 == V_155 )
V_55 -> V_160 |= V_167 ;
}
if ( V_55 -> V_26 ) {
V_155 = F_24 ( V_2 -> V_130 ,
( T_2 ) ( V_168 ) ) ;
F_8 ((0 == smc_result),
L_18 , result = -1;) ;
if ( 0 == V_155 )
V_55 -> V_160 |=
V_169 ;
}
if ( V_55 -> V_27 ) {
V_155 = F_24 ( V_2 -> V_130 ,
( T_2 ) ( V_170 ) ) ;
F_8 ((0 == smc_result),
L_19 , result = -1;) ;
if ( 0 == V_155 ) {
struct V_60 * V_147 =
V_6 -> V_9 ;
T_1 V_171 =
( T_1 ) ( V_147 -> V_172 * 256 ) ;
V_55 -> V_160 |=
V_161 ;
if ( F_26 ( V_2 , V_171 ) )
F_30 ( V_173 L_20 ) ;
}
}
}
return V_154 ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_55 = (struct V_3 * ) ( V_2 -> V_4 ) ;
int V_154 = 0 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_16 ) &&
V_55 -> V_160 ) {
int V_155 ;
if ( V_55 -> V_160 &
V_169 ) {
V_155 = F_24 ( V_2 -> V_130 ,
( T_2 ) ( V_174 ) ) ;
F_8 ( ( V_155 == 0 ) ,
L_21 ,
V_154 = V_155 ) ;
}
if ( V_55 -> V_160 &
V_167 ) {
V_155 = F_24 ( V_2 -> V_130 ,
( T_2 ) ( V_175 ) ) ;
F_8 ( ( V_155 == 0 ) ,
L_22 ,
V_154 = V_155 ) ;
}
if ( V_55 -> V_160 &
V_161 ) {
V_155 = F_24 ( V_2 -> V_130 ,
( T_2 ) ( V_176 ) ) ;
F_8 ( ( V_155 == 0 ) ,
L_23 ,
V_154 = V_155 ) ;
}
V_55 -> V_160 = 0 ;
}
return V_154 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
(struct V_5 * ) ( V_2 -> V_7 ) ;
struct V_60 * V_147 = V_6 -> V_9 ;
int V_177 , V_164 ;
int V_154 = 0 ;
if ( F_21 ( V_2 -> V_14 . V_15 ,
V_16 ) ) {
V_177 = V_2 -> V_14 . V_178 ?
V_2 -> V_14 . V_179 :
( - 1 * V_2 -> V_14 . V_179 ) ;
V_164 = ( ( 100 + V_177 ) * ( int ) ( V_147 -> V_68 * 256 ) ) / 100 ;
V_154 = F_28 ( V_2 , ( T_1 ) V_164 ) ;
}
return V_154 ;
}
