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
struct V_9 * V_10 = F_8 ( V_15 -> V_17 ) ;
T_2 V_18 = V_6 -> V_11 & 0xfff ;
int V_12 = 0 ;
T_1 V_3 ;
switch ( V_18 ) {
case V_19 | ( V_20 << 8 ) :
V_3 = F_5 ( V_10 , V_21 ) ;
if ( V_3 & V_22 ) {
F_9 ( V_23
L_1 ) ;
V_12 = - 1 ;
}
break;
case V_19 | ( V_24 << 8 ) :
V_3 = F_5 ( V_10 , V_25 ) ;
if ( V_3 & V_26 ) {
F_9 ( V_23
L_2 ) ;
V_12 = - 1 ;
}
break;
case V_21 | ( V_27 << 8 ) :
V_3 = F_5 ( V_10 , V_19 ) ;
if ( V_3 & V_28 ) {
F_9 ( V_23
L_3 ) ;
V_12 = - 1 ;
}
break;
case V_25 | ( V_29 << 8 ) :
V_3 = F_5 ( V_10 , V_19 ) ;
if ( V_3 & V_30 ) {
F_9 ( V_23
L_4 ) ;
V_12 = - 1 ;
}
break;
}
return V_12 ;
}
static void F_10 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
T_3 V_35 ;
unsigned int V_36 , V_37 , V_38 ;
V_37 = V_33 / V_34 ;
if ( V_37 < 6 ) {
V_34 >>= 1 ;
V_32 -> V_39 = 1 ;
V_37 = V_33 / V_34 ;
} else
V_32 -> V_39 = 0 ;
if ( ( V_37 < 6 ) || ( V_37 > 12 ) )
F_9 ( V_23
L_5 , V_37 ) ;
V_32 -> V_40 = V_37 ;
V_38 = V_33 % V_34 ;
V_35 = V_41 * ( long long ) V_38 ;
F_11 ( V_35 , V_34 ) ;
V_36 = V_35 & 0xFFFFFFFF ;
if ( ( V_36 % 10 ) >= 5 )
V_36 += 5 ;
V_36 /= 10 ;
V_32 -> V_42 = V_36 ;
}
static int F_12 ( struct V_43 * V_44 ,
int V_45 , int V_46 , unsigned int V_47 , unsigned int V_48 )
{
T_1 V_3 ;
struct V_9 * V_10 = V_44 -> V_10 ;
struct V_31 V_32 ;
if ( V_47 && V_48 ) {
F_10 ( & V_32 , V_48 * 4 , V_47 ) ;
V_3 = F_5 ( V_10 , V_49 ) ;
V_3 |= V_50 ;
F_6 ( V_10 , V_49 , V_3 ) ;
V_3 = F_5 ( V_10 , V_51 ) ;
F_6 ( V_10 , V_51 , V_3 | V_52 ) ;
F_6 ( V_10 , V_53 , V_32 . V_40 | V_54 |
( V_32 . V_39 ? V_55 : 0 ) ) ;
F_6 ( V_10 , V_56 , ( V_57 ) ( V_32 . V_42 >> 8 ) ) ;
F_6 ( V_10 , V_58 , ( V_57 ) ( V_32 . V_42 & 0xFF ) ) ;
} else {
V_3 = F_5 ( V_10 , V_49 ) ;
V_3 &= ~ V_50 ;
F_6 ( V_10 , V_49 , V_3 ) ;
}
return 0 ;
}
static int F_13 ( struct V_43 * V_44 ,
unsigned int V_59 )
{
struct V_9 * V_10 = V_44 -> V_10 ;
T_1 V_60 , V_61 ;
V_60 = F_5 ( V_10 , V_62 ) ;
V_61 = F_5 ( V_10 , V_63 ) ;
switch ( V_59 & V_64 ) {
case V_65 :
V_61 &= ~ V_66 ;
break;
case V_67 :
V_61 |= V_66 ;
break;
default:
return - V_68 ;
}
V_60 &= ~ V_69 ;
switch ( V_59 & V_70 ) {
case V_71 :
V_60 |= V_72 ;
V_60 &= ~ V_73 ;
break;
case V_74 :
V_60 |= V_75 ;
V_60 &= ~ V_73 ;
break;
case V_76 :
V_60 |= V_77 ;
V_60 &= ~ V_73 ;
break;
case V_78 :
V_60 |= V_79 ;
V_60 &= ~ V_73 ;
break;
case V_80 :
V_60 |= V_79 | V_73 ;
break;
default:
return - V_68 ;
}
F_6 ( V_10 , V_62 , V_60 ) ;
F_6 ( V_10 , V_63 , V_61 ) ;
return 0 ;
}
static int F_14 ( struct V_43 * V_44 ,
int V_81 , int div )
{
struct V_9 * V_10 = V_44 -> V_10 ;
T_1 V_3 ;
switch ( V_81 ) {
case V_82 :
V_3 = F_5 ( V_10 , V_51 ) &
~ V_83 ;
F_6 ( V_10 , V_51 , V_3 | div ) ;
break;
case V_84 :
V_3 = F_5 ( V_10 , V_51 ) &
~ V_85 ;
F_6 ( V_10 , V_51 , V_3 | div ) ;
break;
case V_86 :
V_3 = F_5 ( V_10 , V_51 ) &
~ V_87 ;
F_6 ( V_10 , V_51 , V_3 | div ) ;
break;
case V_88 :
V_3 = F_5 ( V_10 , V_89 ) &
~ V_90 ;
F_6 ( V_10 , V_89 , V_3 | div ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_15 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
struct V_43 * V_95 )
{
struct V_9 * V_10 = V_95 -> V_10 ;
T_1 V_60 = F_5 ( V_10 , V_62 ) ;
V_60 &= ~ V_96 ;
switch ( F_16 ( V_94 ) ) {
case 16 :
break;
case 20 :
V_60 |= V_97 ;
break;
case 24 :
V_60 |= V_98 ;
break;
case 32 :
V_60 |= V_99 ;
break;
}
F_6 ( V_10 , V_62 , V_60 ) ;
return 0 ;
}
static int F_17 ( struct V_43 * V_95 , int V_100 )
{
struct V_9 * V_10 = V_95 -> V_10 ;
T_1 V_13 ;
V_13 = F_5 ( V_10 , V_101 ) & ~ V_102 ;
if ( V_100 )
F_6 ( V_10 , V_101 , V_13 | V_102 ) ;
else
F_6 ( V_10 , V_101 , V_13 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 ,
enum V_103 V_104 )
{
struct V_105 * V_106 = F_19 ( V_10 ) ;
T_1 V_13 ;
switch ( V_104 ) {
case V_107 :
break;
case V_108 :
V_13 = F_5 ( V_10 , V_109 ) &
~ V_110 ;
F_6 ( V_10 , V_109 , V_13 | 0x2 ) ;
break;
case V_111 :
if ( F_20 ( V_10 ) == V_112 ) {
F_21 ( V_106 -> V_113 ) ;
F_6 ( V_10 , V_114 , V_115 |
V_116 | V_117 |
V_118 | V_119 |
V_120 ) ;
F_6 ( V_10 , V_121 , V_122 |
V_123 | V_124 |
V_125 ) ;
F_22 ( 300 ) ;
F_6 ( V_10 , V_121 , V_122 |
V_123 | V_124 ) ;
F_6 ( V_10 , V_114 , 0 ) ;
F_6 ( V_10 , V_109 , 0x1b00 ) ;
F_22 ( 50 ) ;
F_6 ( V_10 , V_109 , 0x1f02 ) ;
F_22 ( 100 ) ;
F_6 ( V_10 , V_109 , 0x1f03 ) ;
F_22 ( 600 ) ;
F_6 ( V_10 , V_121 , V_122 |
V_123 | V_124 |
V_126 ) ;
F_6 ( V_10 , V_109 , 0x3 ) ;
F_6 ( V_10 , V_121 , V_126 ) ;
}
V_13 = F_5 ( V_10 , V_109 ) &
~ V_110 ;
F_6 ( V_10 , V_109 , V_13 | 0x4 ) ;
break;
case V_112 :
F_6 ( V_10 , V_121 , V_122 |
V_124 | V_126 ) ;
F_6 ( V_10 , V_121 , V_122 |
V_123 | V_124 |
V_126 ) ;
V_13 = F_5 ( V_10 , V_101 ) ;
F_6 ( V_10 , V_101 , V_13 | V_102 ) ;
F_6 ( V_10 , V_109 , 0x1f03 ) ;
F_6 ( V_10 , V_109 , 0x1f01 ) ;
F_22 ( 300 ) ;
F_6 ( V_10 , V_114 , V_115 |
V_116 | V_117 |
V_118 | V_119 |
V_120 ) ;
F_6 ( V_10 , V_109 , 0x0 ) ;
F_6 ( V_10 , V_121 , 0x0 ) ;
F_23 ( V_106 -> V_113 ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_127 * V_128 ,
const struct V_129 * V_130 )
{
struct V_105 * V_106 ;
unsigned int V_13 ;
int V_12 ;
V_106 = F_25 ( & V_128 -> V_2 , sizeof( * V_106 ) , V_131 ) ;
if ( ! V_106 )
return - V_132 ;
V_106 -> V_113 = F_26 ( V_128 , & V_133 ) ;
if ( F_27 ( V_106 -> V_113 ) )
return F_28 ( V_106 -> V_113 ) ;
F_29 ( V_128 , V_106 ) ;
V_12 = F_30 ( V_106 -> V_113 , V_4 , & V_13 ) ;
if ( V_12 != 0 ) {
F_31 ( & V_128 -> V_2 , L_6 , V_12 ) ;
return V_12 ;
}
if ( V_13 != 0x8991 ) {
F_31 ( & V_128 -> V_2 , L_7 , V_13 ) ;
return - V_68 ;
}
V_12 = F_32 ( V_106 -> V_113 , V_4 , 0 ) ;
if ( V_12 < 0 ) {
F_31 ( & V_128 -> V_2 , L_8 , V_12 ) ;
return V_12 ;
}
F_33 ( V_106 -> V_113 , V_134 ,
V_135 , V_135 ) ;
F_33 ( V_106 -> V_113 , V_136 ,
V_137 , 1 ) ;
F_33 ( V_106 -> V_113 , V_109 ,
V_138 | V_110 ,
V_138 | V_110 ) ;
F_33 ( V_106 -> V_113 , V_49 ,
V_139 , V_139 ) ;
F_32 ( V_106 -> V_113 , V_101 , 0 ) ;
F_32 ( V_106 -> V_113 , V_140 ,
0x50 | ( 1 << 8 ) ) ;
F_32 ( V_106 -> V_113 , V_141 ,
0x50 | ( 1 << 8 ) ) ;
V_12 = F_34 ( & V_128 -> V_2 ,
& V_142 , & V_143 , 1 ) ;
return V_12 ;
}
static int F_35 ( struct V_127 * V_144 )
{
F_36 ( & V_144 -> V_2 ) ;
return 0 ;
}
