static inline int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 [ 2 ] ;
int V_7 ;
V_6 [ 0 ] = 0x00 ;
V_6 [ 1 ] = V_3 & 0xff ;
V_7 = V_2 -> V_8 ( V_2 -> V_9 , V_6 , 2 ) ;
if ( V_7 == 2 ) {
V_5 -> V_10 = V_3 ;
return 0 ;
} else {
return V_7 ;
}
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_11 ,
unsigned int V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_13 = V_11 / 128 ;
unsigned int V_14 = V_11 % 128 ;
T_1 V_6 [ 2 ] ;
int V_7 ;
if ( V_11 == V_15 )
return F_1 ( V_2 , V_12 ) ;
if ( V_5 -> V_10 != V_13 ) {
V_7 = F_1 ( V_2 , V_13 ) ;
if ( V_7 != 0 )
return V_7 ;
}
V_6 [ 0 ] = V_14 & 0xff ;
V_6 [ 1 ] = V_12 & 0xff ;
if ( V_2 -> V_8 ( V_2 -> V_9 , V_6 , 2 ) == 2 )
return 0 ;
else
return - V_16 ;
}
static unsigned int F_4 ( struct V_1 * V_2 , unsigned int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_13 = V_11 / 128 ;
unsigned int V_14 = V_11 % 128 ;
int V_7 ;
if ( V_5 -> V_10 != V_13 ) {
V_7 = F_1 ( V_2 , V_13 ) ;
if ( V_7 != 0 )
return V_7 ;
}
return F_5 ( V_2 -> V_9 , V_14 & 0xff ) ;
}
static inline int F_6 ( int V_17 , int V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_7 ( V_20 ) ; V_19 ++ ) {
if ( ( V_20 [ V_19 ] . V_18 == V_18 )
&& ( V_20 [ V_19 ] . V_17 == V_17 ) ) {
return V_19 ;
}
}
F_8 ( V_21 L_1 ) ;
return - V_22 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_23 , V_24 ,
F_7 ( V_24 ) ) ;
F_11 ( & V_2 -> V_23 , V_25 ,
F_7 ( V_25 ) ) ;
F_12 ( & V_2 -> V_23 ) ;
return 0 ;
}
static int F_13 ( struct V_26 * V_27 ,
int V_28 , unsigned int V_29 , int V_30 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_29 ) {
case V_31 :
case V_32 :
case V_33 :
V_5 -> V_34 = V_29 ;
return 0 ;
}
F_8 ( V_21 L_2 ) ;
return - V_22 ;
}
static int F_14 ( struct V_26 * V_27 , unsigned int V_35 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
T_1 V_36 ;
T_1 V_37 ;
T_1 V_38 ;
V_36 = F_15 ( V_2 , V_39 ) ;
V_36 = V_36 & ~ ( 3 << 6 | 3 << 2 ) ;
V_37 = F_15 ( V_2 , V_40 ) ;
V_37 = 0 ;
V_38 = F_15 ( V_2 , V_41 ) ;
V_38 = V_38 & ~ ( 1 << 3 ) ;
switch ( V_35 & V_42 ) {
case V_43 :
V_36 |= V_44 | V_45 ;
break;
case V_46 :
break;
default:
F_8 ( V_21 L_3 ) ;
return - V_22 ;
}
switch ( V_35 & V_47 ) {
case V_48 :
break;
case V_49 :
V_36 |= ( V_50 << V_51 ) ;
V_38 |= ( 1 << 3 ) ;
V_37 = 0x01 ;
break;
case V_52 :
V_36 |= ( V_50 << V_51 ) ;
V_38 |= ( 1 << 3 ) ;
break;
case V_53 :
V_36 |=
( V_54 << V_51 ) ;
break;
case V_55 :
V_36 |=
( V_56 << V_51 ) ;
break;
default:
F_8 ( V_21 L_4 ) ;
return - V_22 ;
}
F_16 ( V_2 , V_39 , V_36 ) ;
F_16 ( V_2 , V_40 , V_37 ) ;
F_16 ( V_2 , V_41 , V_38 ) ;
return 0 ;
}
static int F_17 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
struct V_26 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
int V_19 ;
V_19 = F_6 ( V_5 -> V_34 , F_18 ( V_60 ) ) ;
if ( V_19 < 0 ) {
F_8 ( V_21 L_5 ) ;
return V_19 ;
}
F_16 ( V_2 , V_62 , V_63 ) ;
F_16 ( V_2 , V_41 , V_64 ) ;
V_6 = F_15 ( V_2 , V_65 ) ;
V_6 &= ~ ( 7 << 4 ) ;
F_16 ( V_2 , V_65 ,
( V_6 | ( V_20 [ V_19 ] . V_66 << 4 ) | 0x01 ) ) ;
F_16 ( V_2 , V_67 , V_20 [ V_19 ] . V_68 ) ;
F_16 ( V_2 , V_69 , ( V_20 [ V_19 ] . V_70 >> 8 ) ) ;
F_16 ( V_2 , V_71 ,
( V_20 [ V_19 ] . V_70 & 0xff ) ) ;
V_6 = F_15 ( V_2 , V_72 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_72 , V_6 | V_20 [ V_19 ] . V_73 ) ;
V_6 = F_15 ( V_2 , V_74 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_74 , V_6 | V_20 [ V_19 ] . V_75 ) ;
F_16 ( V_2 , V_76 , V_20 [ V_19 ] . V_77 >> 8 ) ;
F_16 ( V_2 , V_78 ,
( V_20 [ V_19 ] . V_77 & 0xff ) ) ;
V_6 = F_15 ( V_2 , V_79 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_79 , V_6 | V_20 [ V_19 ] . V_80 ) ;
V_6 = F_15 ( V_2 , V_81 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_81 , V_6 | V_20 [ V_19 ] . V_82 ) ;
F_16 ( V_2 , V_83 , V_20 [ V_19 ] . V_84 ) ;
V_6 = F_15 ( V_2 , V_85 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_85 , V_6 | V_20 [ V_19 ] . V_86 ) ;
V_6 = F_15 ( V_2 , V_39 ) ;
V_6 = V_6 & ~ ( 3 << 4 ) ;
switch ( F_19 ( V_60 ) ) {
case V_87 :
break;
case V_88 :
V_6 |= ( V_89 << V_90 ) ;
break;
case V_91 :
V_6 |= ( V_92 << V_90 ) ;
break;
case V_93 :
V_6 |= ( V_94 << V_90 ) ;
break;
}
F_16 ( V_2 , V_39 , V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_26 * V_61 , int V_95 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
T_1 V_96 ;
V_96 = F_15 ( V_2 , V_97 ) & ~ V_98 ;
if ( V_95 )
F_16 ( V_2 , V_97 , V_96 | V_98 ) ;
else
F_16 ( V_2 , V_97 , V_96 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_99 V_100 )
{
switch ( V_100 ) {
case V_101 :
F_22 ( V_2 , V_65 ,
V_102 , V_102 ) ;
F_22 ( V_2 , V_72 ,
V_103 , V_103 ) ;
F_22 ( V_2 , V_74 ,
V_104 , V_104 ) ;
F_22 ( V_2 , V_79 ,
V_105 , V_105 ) ;
F_22 ( V_2 , V_81 ,
V_106 , V_106 ) ;
F_22 ( V_2 , V_85 ,
V_107 , V_107 ) ;
break;
case V_108 :
break;
case V_109 :
F_22 ( V_2 , V_65 ,
V_102 , 0 ) ;
F_22 ( V_2 , V_72 ,
V_103 , 0 ) ;
F_22 ( V_2 , V_74 ,
V_104 , 0 ) ;
F_22 ( V_2 , V_79 ,
V_105 , 0 ) ;
F_22 ( V_2 , V_81 ,
V_106 , 0 ) ;
F_22 ( V_2 , V_85 ,
V_107 , 0 ) ;
break;
case V_110 :
break;
}
V_2 -> V_23 . V_111 = V_100 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_110 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_109 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_112 ;
V_2 -> V_8 = ( V_113 ) V_114 ;
V_2 -> V_9 = V_5 -> V_9 ;
F_16 ( V_2 , V_115 , 0x01 ) ;
if ( V_5 -> V_116 & V_117 ) {
F_16 ( V_2 , V_118 , V_119 |
V_120 ) ;
}
if ( V_5 -> V_116 & V_121 ) {
F_16 ( V_2 , V_122 , V_123 ) ;
}
V_112 = ( V_5 -> V_116 & V_124 ) ?
V_125 : 0 ;
F_16 ( V_2 , V_126 , V_112 ) ;
V_112 = F_15 ( V_2 , V_127 ) ;
if ( V_5 -> V_116 & V_128 ) {
V_112 |= V_129 ;
}
if ( V_5 -> V_116 & V_130 ) {
V_112 |= V_131 ;
}
F_16 ( V_2 , V_127 , V_112 ) ;
if ( V_5 -> V_132 ) {
F_16 ( V_2 , V_133 , V_134 | V_135 ) ;
} else {
F_16 ( V_2 , V_133 , V_136 | V_137 ) ;
}
if ( V_5 -> V_138 & V_139 ) {
F_16 ( V_2 , V_140 , V_141 ) ;
}
if ( V_5 -> V_138 & V_142 ) {
F_16 ( V_2 , V_143 , V_144 ) ;
}
F_21 ( V_2 , V_109 ) ;
F_26 ( V_2 , V_145 ,
F_7 ( V_145 ) ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_110 ) ;
return 0 ;
}
static T_3 int F_28 ( struct V_146 * V_147 ,
const struct V_148 * V_149 )
{
struct V_150 * V_151 = V_147 -> V_152 . V_153 ;
struct V_4 * V_5 ;
int V_7 ;
V_5 = F_29 ( & V_147 -> V_152 , sizeof( struct V_4 ) ,
V_154 ) ;
if ( V_5 == NULL )
return - V_155 ;
V_5 -> V_9 = V_147 ;
F_30 ( V_147 , V_5 ) ;
if ( V_151 ) {
V_5 -> V_116 = V_151 -> V_116 ;
V_5 -> V_132 = V_151 -> V_132 ;
V_5 -> V_138 = V_151 -> V_138 ;
} else {
V_5 -> V_116 = 0 ;
V_5 -> V_132 = false ;
V_5 -> V_138 = 0 ;
}
V_7 = F_31 ( & V_147 -> V_152 ,
& V_156 , & V_157 , 1 ) ;
return V_7 ;
}
static T_4 int F_32 ( struct V_146 * V_158 )
{
F_33 ( & V_158 -> V_152 ) ;
return 0 ;
}
