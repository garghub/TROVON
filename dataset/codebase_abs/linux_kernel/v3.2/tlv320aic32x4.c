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
struct V_4 * V_5 = F_2 ( V_2 ) ;
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
V_5 -> V_44 = 1 ;
V_36 |= V_45 | V_46 ;
break;
case V_47 :
V_5 -> V_44 = 0 ;
break;
default:
F_8 ( V_21 L_3 ) ;
return - V_22 ;
}
switch ( V_35 & V_48 ) {
case V_49 :
break;
case V_50 :
V_36 |= ( V_51 << V_52 ) ;
V_38 |= ( 1 << 3 ) ;
V_37 = 0x01 ;
break;
case V_53 :
V_36 |= ( V_51 << V_52 ) ;
V_38 |= ( 1 << 3 ) ;
break;
case V_54 :
V_36 |=
( V_55 << V_52 ) ;
break;
case V_56 :
V_36 |=
( V_57 << V_52 ) ;
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
static int F_17 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_26 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
int V_19 ;
V_19 = F_6 ( V_5 -> V_34 , F_18 ( V_61 ) ) ;
if ( V_19 < 0 ) {
F_8 ( V_21 L_5 ) ;
return V_19 ;
}
F_16 ( V_2 , V_63 , V_64 ) ;
F_16 ( V_2 , V_41 , V_65 ) ;
V_6 = F_15 ( V_2 , V_66 ) ;
V_6 &= ~ ( 7 << 4 ) ;
F_16 ( V_2 , V_66 ,
( V_6 | ( V_20 [ V_19 ] . V_67 << 4 ) | 0x01 ) ) ;
F_16 ( V_2 , V_68 , V_20 [ V_19 ] . V_69 ) ;
F_16 ( V_2 , V_70 , ( V_20 [ V_19 ] . V_71 >> 8 ) ) ;
F_16 ( V_2 , V_72 ,
( V_20 [ V_19 ] . V_71 & 0xff ) ) ;
V_6 = F_15 ( V_2 , V_73 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_73 , V_6 | V_20 [ V_19 ] . V_74 ) ;
V_6 = F_15 ( V_2 , V_75 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_75 , V_6 | V_20 [ V_19 ] . V_76 ) ;
F_16 ( V_2 , V_77 , V_20 [ V_19 ] . V_78 >> 8 ) ;
F_16 ( V_2 , V_79 ,
( V_20 [ V_19 ] . V_78 & 0xff ) ) ;
V_6 = F_15 ( V_2 , V_80 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_80 , V_6 | V_20 [ V_19 ] . V_81 ) ;
V_6 = F_15 ( V_2 , V_82 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_82 , V_6 | V_20 [ V_19 ] . V_83 ) ;
F_16 ( V_2 , V_84 , V_20 [ V_19 ] . V_85 ) ;
V_6 = F_15 ( V_2 , V_86 ) ;
V_6 &= ~ ( 0x7f ) ;
F_16 ( V_2 , V_86 , V_6 | V_20 [ V_19 ] . V_87 ) ;
V_6 = F_15 ( V_2 , V_39 ) ;
V_6 = V_6 & ~ ( 3 << 4 ) ;
switch ( F_19 ( V_61 ) ) {
case V_88 :
break;
case V_89 :
V_6 |= ( V_90 << V_91 ) ;
break;
case V_92 :
V_6 |= ( V_93 << V_91 ) ;
break;
case V_94 :
V_6 |= ( V_95 << V_91 ) ;
break;
}
F_16 ( V_2 , V_39 , V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_26 * V_62 , int V_96 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 V_97 ;
V_97 = F_15 ( V_2 , V_98 ) & ~ V_99 ;
if ( V_96 )
F_16 ( V_2 , V_98 , V_97 | V_99 ) ;
else
F_16 ( V_2 , V_98 , V_97 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_100 V_101 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_101 ) {
case V_102 :
if ( V_5 -> V_44 ) {
F_22 ( V_2 , V_66 ,
V_103 , V_103 ) ;
F_22 ( V_2 , V_73 ,
V_104 , V_104 ) ;
F_22 ( V_2 , V_75 ,
V_105 , V_105 ) ;
F_22 ( V_2 , V_80 ,
V_106 , V_106 ) ;
F_22 ( V_2 , V_82 ,
V_107 , V_107 ) ;
F_22 ( V_2 , V_86 ,
V_108 , V_108 ) ;
}
break;
case V_109 :
break;
case V_110 :
if ( V_5 -> V_44 ) {
F_22 ( V_2 , V_66 ,
V_103 , 0 ) ;
F_22 ( V_2 , V_73 ,
V_104 , 0 ) ;
F_22 ( V_2 , V_75 ,
V_105 , 0 ) ;
F_22 ( V_2 , V_80 ,
V_106 , 0 ) ;
F_22 ( V_2 , V_82 ,
V_107 , 0 ) ;
F_22 ( V_2 , V_86 ,
V_108 , 0 ) ;
}
break;
case V_111 :
break;
}
V_2 -> V_23 . V_112 = V_101 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_113 )
{
F_21 ( V_2 , V_111 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_110 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_114 ;
V_2 -> V_8 = ( V_115 ) V_116 ;
V_2 -> V_9 = V_5 -> V_9 ;
F_16 ( V_2 , V_117 , 0x01 ) ;
if ( V_5 -> V_118 & V_119 ) {
F_16 ( V_2 , V_120 , V_121 |
V_122 ) ;
}
if ( V_5 -> V_118 & V_123 ) {
F_16 ( V_2 , V_124 , V_125 ) ;
}
if ( V_5 -> V_118 & V_126 ) {
F_16 ( V_2 , V_127 , V_128 ) ;
}
V_114 = F_15 ( V_2 , V_129 ) ;
if ( V_5 -> V_118 & V_130 ) {
V_114 |= V_131 ;
}
if ( V_5 -> V_118 & V_132 ) {
V_114 |= V_133 ;
}
F_16 ( V_2 , V_129 , V_114 ) ;
if ( V_5 -> V_134 ) {
F_16 ( V_2 , V_135 , V_136 | V_137 ) ;
} else {
F_16 ( V_2 , V_135 , V_138 | V_139 ) ;
}
if ( V_5 -> V_140 & V_141 ) {
F_16 ( V_2 , V_142 , V_143 ) ;
}
if ( V_5 -> V_140 & V_144 ) {
F_16 ( V_2 , V_145 , V_146 ) ;
}
F_21 ( V_2 , V_110 ) ;
F_26 ( V_2 , V_147 ,
F_7 ( V_147 ) ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_111 ) ;
return 0 ;
}
static T_4 int F_28 ( struct V_148 * V_149 ,
const struct V_150 * V_151 )
{
struct V_152 * V_153 = V_149 -> V_154 . V_155 ;
struct V_4 * V_5 ;
int V_7 ;
V_5 = F_29 ( sizeof( struct V_4 ) , V_156 ) ;
if ( V_5 == NULL )
return - V_157 ;
V_5 -> V_9 = V_149 ;
F_30 ( V_149 , V_5 ) ;
if ( V_153 ) {
V_5 -> V_118 = V_153 -> V_118 ;
V_5 -> V_134 = V_153 -> V_134 ;
V_5 -> V_140 = V_153 -> V_140 ;
} else {
V_5 -> V_118 = 0 ;
V_5 -> V_134 = false ;
V_5 -> V_140 = 0 ;
}
V_7 = F_31 ( & V_149 -> V_154 ,
& V_158 , & V_159 , 1 ) ;
if ( V_7 < 0 )
F_32 ( V_5 ) ;
return V_7 ;
}
static T_5 int F_33 ( struct V_148 * V_160 )
{
F_34 ( & V_160 -> V_154 ) ;
F_32 ( F_35 ( V_160 ) ) ;
return 0 ;
}
static int T_6 F_36 ( void )
{
int V_7 = 0 ;
V_7 = F_37 ( & V_161 ) ;
if ( V_7 != 0 ) {
F_8 ( V_21 L_6 ,
V_7 ) ;
}
return V_7 ;
}
static void T_7 F_38 ( void )
{
F_39 ( & V_161 ) ;
}
