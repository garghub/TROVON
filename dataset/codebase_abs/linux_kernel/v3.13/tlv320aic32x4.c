static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( ( V_4 [ V_3 ] . V_2 == V_2 )
&& ( V_4 [ V_3 ] . V_1 == V_1 ) ) {
return V_3 ;
}
}
F_3 ( V_5 L_1 ) ;
return - V_6 ;
}
static int F_4 ( struct V_7 * V_8 ,
int V_9 , unsigned int V_10 , int V_11 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
switch ( V_10 ) {
case V_16 :
case V_17 :
case V_18 :
V_15 -> V_19 = V_10 ;
return 0 ;
}
F_3 ( V_5 L_2 ) ;
return - V_6 ;
}
static int F_6 ( struct V_7 * V_8 , unsigned int V_20 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
T_1 V_21 ;
T_1 V_22 ;
T_1 V_23 ;
V_21 = F_7 ( V_13 , V_24 ) ;
V_21 = V_21 & ~ ( 3 << 6 | 3 << 2 ) ;
V_22 = F_7 ( V_13 , V_25 ) ;
V_22 = 0 ;
V_23 = F_7 ( V_13 , V_26 ) ;
V_23 = V_23 & ~ ( 1 << 3 ) ;
switch ( V_20 & V_27 ) {
case V_28 :
V_21 |= V_29 | V_30 ;
break;
case V_31 :
break;
default:
F_3 ( V_5 L_3 ) ;
return - V_6 ;
}
switch ( V_20 & V_32 ) {
case V_33 :
break;
case V_34 :
V_21 |= ( V_35 << V_36 ) ;
V_23 |= ( 1 << 3 ) ;
V_22 = 0x01 ;
break;
case V_37 :
V_21 |= ( V_35 << V_36 ) ;
V_23 |= ( 1 << 3 ) ;
break;
case V_38 :
V_21 |=
( V_39 << V_36 ) ;
break;
case V_40 :
V_21 |=
( V_41 << V_36 ) ;
break;
default:
F_3 ( V_5 L_4 ) ;
return - V_6 ;
}
F_8 ( V_13 , V_24 , V_21 ) ;
F_8 ( V_13 , V_25 , V_22 ) ;
F_8 ( V_13 , V_26 , V_23 ) ;
return 0 ;
}
static int F_9 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_7 * V_46 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
T_1 V_47 ;
int V_3 ;
V_3 = F_1 ( V_15 -> V_19 , F_10 ( V_45 ) ) ;
if ( V_3 < 0 ) {
F_3 ( V_5 L_5 ) ;
return V_3 ;
}
F_8 ( V_13 , V_48 , V_49 ) ;
F_8 ( V_13 , V_26 , V_50 ) ;
V_47 = F_7 ( V_13 , V_51 ) ;
V_47 &= ~ ( 7 << 4 ) ;
F_8 ( V_13 , V_51 ,
( V_47 | ( V_4 [ V_3 ] . V_52 << 4 ) | 0x01 ) ) ;
F_8 ( V_13 , V_53 , V_4 [ V_3 ] . V_54 ) ;
F_8 ( V_13 , V_55 , ( V_4 [ V_3 ] . V_56 >> 8 ) ) ;
F_8 ( V_13 , V_57 ,
( V_4 [ V_3 ] . V_56 & 0xff ) ) ;
V_47 = F_7 ( V_13 , V_58 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_58 , V_47 | V_4 [ V_3 ] . V_59 ) ;
V_47 = F_7 ( V_13 , V_60 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_60 , V_47 | V_4 [ V_3 ] . V_61 ) ;
F_8 ( V_13 , V_62 , V_4 [ V_3 ] . V_63 >> 8 ) ;
F_8 ( V_13 , V_64 ,
( V_4 [ V_3 ] . V_63 & 0xff ) ) ;
V_47 = F_7 ( V_13 , V_65 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_65 , V_47 | V_4 [ V_3 ] . V_66 ) ;
V_47 = F_7 ( V_13 , V_67 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_67 , V_47 | V_4 [ V_3 ] . V_68 ) ;
F_8 ( V_13 , V_69 , V_4 [ V_3 ] . V_70 ) ;
V_47 = F_7 ( V_13 , V_71 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_71 , V_47 | V_4 [ V_3 ] . V_72 ) ;
V_47 = F_7 ( V_13 , V_24 ) ;
V_47 = V_47 & ~ ( 3 << 4 ) ;
switch ( F_11 ( V_45 ) ) {
case V_73 :
break;
case V_74 :
V_47 |= ( V_75 << V_76 ) ;
break;
case V_77 :
V_47 |= ( V_78 << V_76 ) ;
break;
case V_79 :
V_47 |= ( V_80 << V_76 ) ;
break;
}
F_8 ( V_13 , V_24 , V_47 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_46 , int V_81 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
T_1 V_82 ;
V_82 = F_7 ( V_13 , V_83 ) & ~ V_84 ;
if ( V_81 )
F_8 ( V_13 , V_83 , V_82 | V_84 ) ;
else
F_8 ( V_13 , V_83 , V_82 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 ,
enum V_85 V_86 )
{
switch ( V_86 ) {
case V_87 :
F_14 ( V_13 , V_51 ,
V_88 , V_88 ) ;
F_14 ( V_13 , V_58 ,
V_89 , V_89 ) ;
F_14 ( V_13 , V_60 ,
V_90 , V_90 ) ;
F_14 ( V_13 , V_65 ,
V_91 , V_91 ) ;
F_14 ( V_13 , V_67 ,
V_92 , V_92 ) ;
F_14 ( V_13 , V_71 ,
V_93 , V_93 ) ;
break;
case V_94 :
break;
case V_95 :
F_14 ( V_13 , V_51 ,
V_88 , 0 ) ;
F_14 ( V_13 , V_58 ,
V_89 , 0 ) ;
F_14 ( V_13 , V_60 ,
V_90 , 0 ) ;
F_14 ( V_13 , V_65 ,
V_91 , 0 ) ;
F_14 ( V_13 , V_67 ,
V_92 , 0 ) ;
F_14 ( V_13 , V_71 ,
V_93 , 0 ) ;
break;
case V_96 :
break;
}
V_13 -> V_97 . V_98 = V_86 ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 )
{
F_13 ( V_13 , V_96 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 )
{
F_13 ( V_13 , V_95 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
T_2 V_99 ;
F_18 ( V_13 , 8 , 8 , V_100 ) ;
if ( V_15 -> V_101 >= 0 ) {
F_19 ( 10 ) ;
F_20 ( V_15 -> V_101 , 1 ) ;
}
F_8 ( V_13 , V_102 , 0x01 ) ;
if ( V_15 -> V_103 & V_104 ) {
F_8 ( V_13 , V_105 , V_106 |
V_107 ) ;
}
if ( V_15 -> V_103 & V_108 ) {
F_8 ( V_13 , V_109 , V_110 ) ;
}
V_99 = ( V_15 -> V_103 & V_111 ) ?
V_112 : 0 ;
F_8 ( V_13 , V_113 , V_99 ) ;
V_99 = F_7 ( V_13 , V_114 ) ;
if ( V_15 -> V_103 & V_115 ) {
V_99 |= V_116 ;
}
if ( V_15 -> V_103 & V_117 ) {
V_99 |= V_118 ;
}
F_8 ( V_13 , V_114 , V_99 ) ;
if ( V_15 -> V_119 ) {
F_8 ( V_13 , V_120 , V_121 | V_122 ) ;
} else {
F_8 ( V_13 , V_120 , V_123 | V_124 ) ;
}
if ( V_15 -> V_125 & V_126 ) {
F_8 ( V_13 , V_127 , V_128 ) ;
}
if ( V_15 -> V_125 & V_129 ) {
F_8 ( V_13 , V_130 , V_131 ) ;
}
F_13 ( V_13 , V_95 ) ;
V_99 = F_7 ( V_13 , V_132 ) ;
F_8 ( V_13 , V_132 , V_99 |
V_133 | V_134 ) ;
F_8 ( V_13 , V_132 , V_99 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
F_13 ( V_13 , V_96 ) ;
return 0 ;
}
static int F_22 ( struct V_135 * V_136 ,
const struct V_137 * V_138 )
{
struct V_139 * V_140 = V_136 -> V_141 . V_142 ;
struct V_14 * V_15 ;
int V_143 ;
V_15 = F_23 ( & V_136 -> V_141 , sizeof( struct V_14 ) ,
V_144 ) ;
if ( V_15 == NULL )
return - V_145 ;
V_15 -> V_146 = F_24 ( V_136 , & V_147 ) ;
if ( F_25 ( V_15 -> V_146 ) )
return F_26 ( V_15 -> V_146 ) ;
F_27 ( V_136 , V_15 ) ;
if ( V_140 ) {
V_15 -> V_103 = V_140 -> V_103 ;
V_15 -> V_119 = V_140 -> V_119 ;
V_15 -> V_125 = V_140 -> V_125 ;
V_15 -> V_101 = V_140 -> V_101 ;
} else {
V_15 -> V_103 = 0 ;
V_15 -> V_119 = false ;
V_15 -> V_125 = 0 ;
V_15 -> V_101 = - 1 ;
}
if ( V_15 -> V_101 >= 0 ) {
V_143 = F_28 ( & V_136 -> V_141 , V_15 -> V_101 ,
V_148 , L_6 ) ;
if ( V_143 != 0 )
return V_143 ;
}
V_143 = F_29 ( & V_136 -> V_141 ,
& V_149 , & V_150 , 1 ) ;
return V_143 ;
}
static int F_30 ( struct V_135 * V_151 )
{
F_31 ( & V_151 -> V_141 ) ;
return 0 ;
}
