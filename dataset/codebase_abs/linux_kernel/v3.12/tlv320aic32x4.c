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
static int F_9 ( struct V_23 * V_24 ,
int V_25 , unsigned int V_26 , int V_27 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_26 ) {
case V_28 :
case V_29 :
case V_30 :
V_5 -> V_31 = V_26 ;
return 0 ;
}
F_8 ( V_21 L_2 ) ;
return - V_22 ;
}
static int F_10 ( struct V_23 * V_24 , unsigned int V_32 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_1 V_33 ;
T_1 V_34 ;
T_1 V_35 ;
V_33 = F_11 ( V_2 , V_36 ) ;
V_33 = V_33 & ~ ( 3 << 6 | 3 << 2 ) ;
V_34 = F_11 ( V_2 , V_37 ) ;
V_34 = 0 ;
V_35 = F_11 ( V_2 , V_38 ) ;
V_35 = V_35 & ~ ( 1 << 3 ) ;
switch ( V_32 & V_39 ) {
case V_40 :
V_33 |= V_41 | V_42 ;
break;
case V_43 :
break;
default:
F_8 ( V_21 L_3 ) ;
return - V_22 ;
}
switch ( V_32 & V_44 ) {
case V_45 :
break;
case V_46 :
V_33 |= ( V_47 << V_48 ) ;
V_35 |= ( 1 << 3 ) ;
V_34 = 0x01 ;
break;
case V_49 :
V_33 |= ( V_47 << V_48 ) ;
V_35 |= ( 1 << 3 ) ;
break;
case V_50 :
V_33 |=
( V_51 << V_48 ) ;
break;
case V_52 :
V_33 |=
( V_53 << V_48 ) ;
break;
default:
F_8 ( V_21 L_4 ) ;
return - V_22 ;
}
F_12 ( V_2 , V_36 , V_33 ) ;
F_12 ( V_2 , V_37 , V_34 ) ;
F_12 ( V_2 , V_38 , V_35 ) ;
return 0 ;
}
static int F_13 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_23 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
int V_19 ;
V_19 = F_6 ( V_5 -> V_31 , F_14 ( V_57 ) ) ;
if ( V_19 < 0 ) {
F_8 ( V_21 L_5 ) ;
return V_19 ;
}
F_12 ( V_2 , V_59 , V_60 ) ;
F_12 ( V_2 , V_38 , V_61 ) ;
V_6 = F_11 ( V_2 , V_62 ) ;
V_6 &= ~ ( 7 << 4 ) ;
F_12 ( V_2 , V_62 ,
( V_6 | ( V_20 [ V_19 ] . V_63 << 4 ) | 0x01 ) ) ;
F_12 ( V_2 , V_64 , V_20 [ V_19 ] . V_65 ) ;
F_12 ( V_2 , V_66 , ( V_20 [ V_19 ] . V_67 >> 8 ) ) ;
F_12 ( V_2 , V_68 ,
( V_20 [ V_19 ] . V_67 & 0xff ) ) ;
V_6 = F_11 ( V_2 , V_69 ) ;
V_6 &= ~ ( 0x7f ) ;
F_12 ( V_2 , V_69 , V_6 | V_20 [ V_19 ] . V_70 ) ;
V_6 = F_11 ( V_2 , V_71 ) ;
V_6 &= ~ ( 0x7f ) ;
F_12 ( V_2 , V_71 , V_6 | V_20 [ V_19 ] . V_72 ) ;
F_12 ( V_2 , V_73 , V_20 [ V_19 ] . V_74 >> 8 ) ;
F_12 ( V_2 , V_75 ,
( V_20 [ V_19 ] . V_74 & 0xff ) ) ;
V_6 = F_11 ( V_2 , V_76 ) ;
V_6 &= ~ ( 0x7f ) ;
F_12 ( V_2 , V_76 , V_6 | V_20 [ V_19 ] . V_77 ) ;
V_6 = F_11 ( V_2 , V_78 ) ;
V_6 &= ~ ( 0x7f ) ;
F_12 ( V_2 , V_78 , V_6 | V_20 [ V_19 ] . V_79 ) ;
F_12 ( V_2 , V_80 , V_20 [ V_19 ] . V_81 ) ;
V_6 = F_11 ( V_2 , V_82 ) ;
V_6 &= ~ ( 0x7f ) ;
F_12 ( V_2 , V_82 , V_6 | V_20 [ V_19 ] . V_83 ) ;
V_6 = F_11 ( V_2 , V_36 ) ;
V_6 = V_6 & ~ ( 3 << 4 ) ;
switch ( F_15 ( V_57 ) ) {
case V_84 :
break;
case V_85 :
V_6 |= ( V_86 << V_87 ) ;
break;
case V_88 :
V_6 |= ( V_89 << V_87 ) ;
break;
case V_90 :
V_6 |= ( V_91 << V_87 ) ;
break;
}
F_12 ( V_2 , V_36 , V_6 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_58 , int V_92 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 V_93 ;
V_93 = F_11 ( V_2 , V_94 ) & ~ V_95 ;
if ( V_92 )
F_12 ( V_2 , V_94 , V_93 | V_95 ) ;
else
F_12 ( V_2 , V_94 , V_93 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_96 V_97 )
{
switch ( V_97 ) {
case V_98 :
F_18 ( V_2 , V_62 ,
V_99 , V_99 ) ;
F_18 ( V_2 , V_69 ,
V_100 , V_100 ) ;
F_18 ( V_2 , V_71 ,
V_101 , V_101 ) ;
F_18 ( V_2 , V_76 ,
V_102 , V_102 ) ;
F_18 ( V_2 , V_78 ,
V_103 , V_103 ) ;
F_18 ( V_2 , V_82 ,
V_104 , V_104 ) ;
break;
case V_105 :
break;
case V_106 :
F_18 ( V_2 , V_62 ,
V_99 , 0 ) ;
F_18 ( V_2 , V_69 ,
V_100 , 0 ) ;
F_18 ( V_2 , V_71 ,
V_101 , 0 ) ;
F_18 ( V_2 , V_76 ,
V_102 , 0 ) ;
F_18 ( V_2 , V_78 ,
V_103 , 0 ) ;
F_18 ( V_2 , V_82 ,
V_104 , 0 ) ;
break;
case V_107 :
break;
}
V_2 -> V_108 . V_109 = V_97 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_107 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_106 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_110 ;
int V_7 ;
V_2 -> V_8 = ( V_111 ) V_112 ;
V_2 -> V_9 = V_5 -> V_9 ;
if ( V_5 -> V_113 >= 0 ) {
V_7 = F_22 ( V_2 -> V_114 , V_5 -> V_113 ,
V_115 , L_6 ) ;
if ( V_7 != 0 )
return V_7 ;
F_23 ( 10 ) ;
F_24 ( V_5 -> V_113 , 1 ) ;
}
F_12 ( V_2 , V_116 , 0x01 ) ;
if ( V_5 -> V_117 & V_118 ) {
F_12 ( V_2 , V_119 , V_120 |
V_121 ) ;
}
if ( V_5 -> V_117 & V_122 ) {
F_12 ( V_2 , V_123 , V_124 ) ;
}
V_110 = ( V_5 -> V_117 & V_125 ) ?
V_126 : 0 ;
F_12 ( V_2 , V_127 , V_110 ) ;
V_110 = F_11 ( V_2 , V_128 ) ;
if ( V_5 -> V_117 & V_129 ) {
V_110 |= V_130 ;
}
if ( V_5 -> V_117 & V_131 ) {
V_110 |= V_132 ;
}
F_12 ( V_2 , V_128 , V_110 ) ;
if ( V_5 -> V_133 ) {
F_12 ( V_2 , V_134 , V_135 | V_136 ) ;
} else {
F_12 ( V_2 , V_134 , V_137 | V_138 ) ;
}
if ( V_5 -> V_139 & V_140 ) {
F_12 ( V_2 , V_141 , V_142 ) ;
}
if ( V_5 -> V_139 & V_143 ) {
F_12 ( V_2 , V_144 , V_145 ) ;
}
F_17 ( V_2 , V_106 ) ;
V_110 = F_11 ( V_2 , V_146 ) ;
F_12 ( V_2 , V_146 , V_110 |
V_147 | V_148 ) ;
F_12 ( V_2 , V_146 , V_110 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_107 ) ;
return 0 ;
}
static int F_26 ( struct V_149 * V_150 ,
const struct V_151 * V_152 )
{
struct V_153 * V_154 = V_150 -> V_114 . V_155 ;
struct V_4 * V_5 ;
int V_7 ;
V_5 = F_27 ( & V_150 -> V_114 , sizeof( struct V_4 ) ,
V_156 ) ;
if ( V_5 == NULL )
return - V_157 ;
V_5 -> V_9 = V_150 ;
F_28 ( V_150 , V_5 ) ;
if ( V_154 ) {
V_5 -> V_117 = V_154 -> V_117 ;
V_5 -> V_133 = V_154 -> V_133 ;
V_5 -> V_139 = V_154 -> V_139 ;
V_5 -> V_113 = V_154 -> V_113 ;
} else {
V_5 -> V_117 = 0 ;
V_5 -> V_133 = false ;
V_5 -> V_139 = 0 ;
V_5 -> V_113 = - 1 ;
}
V_7 = F_29 ( & V_150 -> V_114 ,
& V_158 , & V_159 , 1 ) ;
return V_7 ;
}
static int F_30 ( struct V_149 * V_160 )
{
F_31 ( & V_160 -> V_114 ) ;
return 0 ;
}
