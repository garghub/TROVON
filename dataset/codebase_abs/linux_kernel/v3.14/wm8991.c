static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
int V_3 = V_6 -> V_11 & 0xff ;
int V_12 ;
T_1 V_13 ;
V_12 = F_4 ( V_6 , V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_13 = F_5 ( V_10 , V_3 ) ;
return F_6 ( V_10 , V_3 , V_13 | 0x0100 ) ;
}
static int F_7 ( struct V_14 * V_15 ,
struct V_5 * V_6 , int V_16 )
{
T_2 V_17 = V_6 -> V_11 & 0xfff ;
int V_12 = 0 ;
T_1 V_3 ;
switch ( V_17 ) {
case V_18 | ( V_19 << 8 ) :
V_3 = F_5 ( V_15 -> V_10 , V_20 ) ;
if ( V_3 & V_21 ) {
F_8 ( V_22
L_1 ) ;
V_12 = - 1 ;
}
break;
case V_18 | ( V_23 << 8 ) :
V_3 = F_5 ( V_15 -> V_10 , V_24 ) ;
if ( V_3 & V_25 ) {
F_8 ( V_22
L_2 ) ;
V_12 = - 1 ;
}
break;
case V_20 | ( V_26 << 8 ) :
V_3 = F_5 ( V_15 -> V_10 , V_18 ) ;
if ( V_3 & V_27 ) {
F_8 ( V_22
L_3 ) ;
V_12 = - 1 ;
}
break;
case V_24 | ( V_28 << 8 ) :
V_3 = F_5 ( V_15 -> V_10 , V_18 ) ;
if ( V_3 & V_29 ) {
F_8 ( V_22
L_4 ) ;
V_12 = - 1 ;
}
break;
}
return V_12 ;
}
static void F_9 ( struct V_30 * V_31 , unsigned int V_32 ,
unsigned int V_33 )
{
T_3 V_34 ;
unsigned int V_35 , V_36 , V_37 ;
V_36 = V_32 / V_33 ;
if ( V_36 < 6 ) {
V_33 >>= 1 ;
V_31 -> V_38 = 1 ;
V_36 = V_32 / V_33 ;
} else
V_31 -> V_38 = 0 ;
if ( ( V_36 < 6 ) || ( V_36 > 12 ) )
F_8 ( V_22
L_5 , V_36 ) ;
V_31 -> V_39 = V_36 ;
V_37 = V_32 % V_33 ;
V_34 = V_40 * ( long long ) V_37 ;
F_10 ( V_34 , V_33 ) ;
V_35 = V_34 & 0xFFFFFFFF ;
if ( ( V_35 % 10 ) >= 5 )
V_35 += 5 ;
V_35 /= 10 ;
V_31 -> V_41 = V_35 ;
}
static int F_11 ( struct V_42 * V_43 ,
int V_44 , int V_45 , unsigned int V_46 , unsigned int V_47 )
{
T_1 V_3 ;
struct V_9 * V_10 = V_43 -> V_10 ;
struct V_30 V_31 ;
if ( V_46 && V_47 ) {
F_9 ( & V_31 , V_47 * 4 , V_46 ) ;
V_3 = F_5 ( V_10 , V_48 ) ;
V_3 |= V_49 ;
F_6 ( V_10 , V_48 , V_3 ) ;
V_3 = F_5 ( V_10 , V_50 ) ;
F_6 ( V_10 , V_50 , V_3 | V_51 ) ;
F_6 ( V_10 , V_52 , V_31 . V_39 | V_53 |
( V_31 . V_38 ? V_54 : 0 ) ) ;
F_6 ( V_10 , V_55 , ( V_56 ) ( V_31 . V_41 >> 8 ) ) ;
F_6 ( V_10 , V_57 , ( V_56 ) ( V_31 . V_41 & 0xFF ) ) ;
} else {
V_3 = F_5 ( V_10 , V_48 ) ;
V_3 &= ~ V_49 ;
F_6 ( V_10 , V_48 , V_3 ) ;
}
return 0 ;
}
static int F_12 ( struct V_42 * V_43 ,
unsigned int V_58 )
{
struct V_9 * V_10 = V_43 -> V_10 ;
T_1 V_59 , V_60 ;
V_59 = F_5 ( V_10 , V_61 ) ;
V_60 = F_5 ( V_10 , V_62 ) ;
switch ( V_58 & V_63 ) {
case V_64 :
V_60 &= ~ V_65 ;
break;
case V_66 :
V_60 |= V_65 ;
break;
default:
return - V_67 ;
}
V_59 &= ~ V_68 ;
switch ( V_58 & V_69 ) {
case V_70 :
V_59 |= V_71 ;
V_59 &= ~ V_72 ;
break;
case V_73 :
V_59 |= V_74 ;
V_59 &= ~ V_72 ;
break;
case V_75 :
V_59 |= V_76 ;
V_59 &= ~ V_72 ;
break;
case V_77 :
V_59 |= V_78 ;
V_59 &= ~ V_72 ;
break;
case V_79 :
V_59 |= V_78 | V_72 ;
break;
default:
return - V_67 ;
}
F_6 ( V_10 , V_61 , V_59 ) ;
F_6 ( V_10 , V_62 , V_60 ) ;
return 0 ;
}
static int F_13 ( struct V_42 * V_43 ,
int V_80 , int div )
{
struct V_9 * V_10 = V_43 -> V_10 ;
T_1 V_3 ;
switch ( V_80 ) {
case V_81 :
V_3 = F_5 ( V_10 , V_50 ) &
~ V_82 ;
F_6 ( V_10 , V_50 , V_3 | div ) ;
break;
case V_83 :
V_3 = F_5 ( V_10 , V_50 ) &
~ V_84 ;
F_6 ( V_10 , V_50 , V_3 | div ) ;
break;
case V_85 :
V_3 = F_5 ( V_10 , V_50 ) &
~ V_86 ;
F_6 ( V_10 , V_50 , V_3 | div ) ;
break;
case V_87 :
V_3 = F_5 ( V_10 , V_88 ) &
~ V_89 ;
F_6 ( V_10 , V_88 , V_3 | div ) ;
break;
default:
return - V_67 ;
}
return 0 ;
}
static int F_14 ( struct V_90 * V_91 ,
struct V_92 * V_93 ,
struct V_42 * V_94 )
{
struct V_9 * V_10 = V_94 -> V_10 ;
T_1 V_59 = F_5 ( V_10 , V_61 ) ;
V_59 &= ~ V_95 ;
switch ( F_15 ( V_93 ) ) {
case V_96 :
break;
case V_97 :
V_59 |= V_98 ;
break;
case V_99 :
V_59 |= V_100 ;
break;
case V_101 :
V_59 |= V_102 ;
break;
}
F_6 ( V_10 , V_61 , V_59 ) ;
return 0 ;
}
static int F_16 ( struct V_42 * V_94 , int V_103 )
{
struct V_9 * V_10 = V_94 -> V_10 ;
T_1 V_13 ;
V_13 = F_5 ( V_10 , V_104 ) & ~ V_105 ;
if ( V_103 )
F_6 ( V_10 , V_104 , V_13 | V_105 ) ;
else
F_6 ( V_10 , V_104 , V_13 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 ,
enum V_106 V_107 )
{
struct V_108 * V_109 = F_18 ( V_10 ) ;
T_1 V_13 ;
switch ( V_107 ) {
case V_110 :
break;
case V_111 :
V_13 = F_5 ( V_10 , V_112 ) &
~ V_113 ;
F_6 ( V_10 , V_112 , V_13 | 0x2 ) ;
break;
case V_114 :
if ( V_10 -> V_115 . V_116 == V_117 ) {
F_19 ( V_109 -> V_118 ) ;
F_6 ( V_10 , V_119 , V_120 |
V_121 | V_122 |
V_123 | V_124 |
V_125 ) ;
F_6 ( V_10 , V_126 , V_127 |
V_128 | V_129 |
V_130 ) ;
F_20 ( 300 ) ;
F_6 ( V_10 , V_126 , V_127 |
V_128 | V_129 ) ;
F_6 ( V_10 , V_119 , 0 ) ;
F_6 ( V_10 , V_112 , 0x1b00 ) ;
F_20 ( 50 ) ;
F_6 ( V_10 , V_112 , 0x1f02 ) ;
F_20 ( 100 ) ;
F_6 ( V_10 , V_112 , 0x1f03 ) ;
F_20 ( 600 ) ;
F_6 ( V_10 , V_126 , V_127 |
V_128 | V_129 |
V_131 ) ;
F_6 ( V_10 , V_112 , 0x3 ) ;
F_6 ( V_10 , V_126 , V_131 ) ;
}
V_13 = F_5 ( V_10 , V_112 ) &
~ V_113 ;
F_6 ( V_10 , V_112 , V_13 | 0x4 ) ;
break;
case V_117 :
F_6 ( V_10 , V_126 , V_127 |
V_129 | V_131 ) ;
F_6 ( V_10 , V_126 , V_127 |
V_128 | V_129 |
V_131 ) ;
V_13 = F_5 ( V_10 , V_104 ) ;
F_6 ( V_10 , V_104 , V_13 | V_105 ) ;
F_6 ( V_10 , V_112 , 0x1f03 ) ;
F_6 ( V_10 , V_112 , 0x1f01 ) ;
F_20 ( 300 ) ;
F_6 ( V_10 , V_119 , V_120 |
V_121 | V_122 |
V_123 | V_124 |
V_125 ) ;
F_6 ( V_10 , V_112 , 0x0 ) ;
F_6 ( V_10 , V_126 , 0x0 ) ;
F_21 ( V_109 -> V_118 ) ;
break;
}
V_10 -> V_115 . V_116 = V_107 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
F_17 ( V_10 , V_117 ) ;
return 0 ;
}
static int F_23 ( struct V_9 * V_10 )
{
F_17 ( V_10 , V_114 ) ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
F_17 ( V_10 , V_117 ) ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_108 * V_109 ;
int V_12 ;
V_109 = F_18 ( V_10 ) ;
V_12 = F_26 ( V_10 , 8 , 16 , V_132 ) ;
if ( V_12 < 0 ) {
F_27 ( V_10 -> V_2 , L_6 , V_12 ) ;
return V_12 ;
}
F_17 ( V_10 , V_114 ) ;
return 0 ;
}
static int F_28 ( struct V_133 * V_134 ,
const struct V_135 * V_136 )
{
struct V_108 * V_109 ;
unsigned int V_13 ;
int V_12 ;
V_109 = F_29 ( & V_134 -> V_2 , sizeof( * V_109 ) , V_137 ) ;
if ( ! V_109 )
return - V_138 ;
V_109 -> V_118 = F_30 ( V_134 , & V_139 ) ;
if ( F_31 ( V_109 -> V_118 ) )
return F_32 ( V_109 -> V_118 ) ;
F_33 ( V_134 , V_109 ) ;
V_12 = F_34 ( V_109 -> V_118 , V_4 , & V_13 ) ;
if ( V_12 != 0 ) {
F_27 ( & V_134 -> V_2 , L_7 , V_12 ) ;
return V_12 ;
}
if ( V_13 != 0x8991 ) {
F_27 ( & V_134 -> V_2 , L_8 , V_13 ) ;
return - V_67 ;
}
V_12 = F_35 ( V_109 -> V_118 , V_4 , 0 ) ;
if ( V_12 < 0 ) {
F_27 ( & V_134 -> V_2 , L_9 , V_12 ) ;
return V_12 ;
}
F_36 ( V_109 -> V_118 , V_140 ,
V_141 , V_141 ) ;
F_36 ( V_109 -> V_118 , V_142 ,
V_143 , 1 ) ;
F_36 ( V_109 -> V_118 , V_112 ,
V_144 | V_113 ,
V_144 | V_113 ) ;
F_36 ( V_109 -> V_118 , V_48 ,
V_145 , V_145 ) ;
F_35 ( V_109 -> V_118 , V_104 , 0 ) ;
F_35 ( V_109 -> V_118 , V_146 ,
0x50 | ( 1 << 8 ) ) ;
F_35 ( V_109 -> V_118 , V_147 ,
0x50 | ( 1 << 8 ) ) ;
V_12 = F_37 ( & V_134 -> V_2 ,
& V_148 , & V_149 , 1 ) ;
return V_12 ;
}
static int F_38 ( struct V_133 * V_150 )
{
F_39 ( & V_150 -> V_2 ) ;
return 0 ;
}
