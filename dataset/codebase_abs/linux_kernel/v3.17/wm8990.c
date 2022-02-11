static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_11 * V_12 =
(struct V_11 * ) V_6 -> V_13 ;
int V_3 = V_12 -> V_3 ;
int V_14 ;
T_1 V_15 ;
V_14 = F_4 ( V_6 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_15 = F_5 ( V_10 , V_3 ) ;
return F_6 ( V_10 , V_3 , V_15 | 0x0100 ) ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_5 * V_6 , int V_18 )
{
T_2 V_19 = V_6 -> V_13 & 0xfff ;
int V_14 = 0 ;
T_1 V_3 ;
switch ( V_19 ) {
case V_20 | ( V_21 << 8 ) :
V_3 = F_5 ( V_17 -> V_10 , V_22 ) ;
if ( V_3 & V_23 ) {
F_8 ( V_24
L_1 ) ;
V_14 = - 1 ;
}
break;
case V_20 | ( V_25 << 8 ) :
V_3 = F_5 ( V_17 -> V_10 , V_26 ) ;
if ( V_3 & V_27 ) {
F_8 ( V_24
L_2 ) ;
V_14 = - 1 ;
}
break;
case V_22 | ( V_28 << 8 ) :
V_3 = F_5 ( V_17 -> V_10 , V_20 ) ;
if ( V_3 & V_29 ) {
F_8 ( V_24
L_3 ) ;
V_14 = - 1 ;
}
break;
case V_26 | ( V_30 << 8 ) :
V_3 = F_5 ( V_17 -> V_10 , V_20 ) ;
if ( V_3 & V_31 ) {
F_8 ( V_24
L_4 ) ;
V_14 = - 1 ;
}
break;
}
return V_14 ;
}
static void F_9 ( struct V_32 * V_33 , unsigned int V_34 ,
unsigned int V_35 )
{
T_3 V_36 ;
unsigned int V_37 , V_38 , V_39 ;
V_38 = V_34 / V_35 ;
if ( V_38 < 6 ) {
V_35 >>= 1 ;
V_33 -> V_40 = 1 ;
V_38 = V_34 / V_35 ;
} else
V_33 -> V_40 = 0 ;
if ( ( V_38 < 6 ) || ( V_38 > 12 ) )
F_8 ( V_24
L_5 , V_38 ) ;
V_33 -> V_41 = V_38 ;
V_39 = V_34 % V_35 ;
V_36 = V_42 * ( long long ) V_39 ;
F_10 ( V_36 , V_35 ) ;
V_37 = V_36 & 0xFFFFFFFF ;
if ( ( V_37 % 10 ) >= 5 )
V_37 += 5 ;
V_37 /= 10 ;
V_33 -> V_43 = V_37 ;
}
static int F_11 ( struct V_44 * V_45 , int V_46 ,
int V_35 , unsigned int V_47 , unsigned int V_48 )
{
struct V_9 * V_10 = V_45 -> V_10 ;
struct V_32 V_33 ;
if ( V_47 && V_48 ) {
F_9 ( & V_33 , V_48 * 4 , V_47 ) ;
F_12 ( V_10 , V_49 ,
V_50 , V_50 ) ;
F_12 ( V_10 , V_51 ,
V_52 , V_52 ) ;
F_6 ( V_10 , V_53 , V_33 . V_41 | V_54 |
( V_33 . V_40 ? V_55 : 0 ) ) ;
F_6 ( V_10 , V_56 , ( V_57 ) ( V_33 . V_43 >> 8 ) ) ;
F_6 ( V_10 , V_58 , ( V_57 ) ( V_33 . V_43 & 0xFF ) ) ;
} else {
F_12 ( V_10 , V_49 ,
V_50 , 0 ) ;
}
return 0 ;
}
static int F_13 ( struct V_44 * V_45 ,
int V_59 , unsigned int V_60 , int V_61 )
{
struct V_9 * V_10 = V_45 -> V_10 ;
struct V_62 * V_63 = F_14 ( V_10 ) ;
V_63 -> V_64 = V_60 ;
return 0 ;
}
static int F_15 ( struct V_44 * V_45 ,
unsigned int V_65 )
{
struct V_9 * V_10 = V_45 -> V_10 ;
T_1 V_66 , V_67 ;
V_66 = F_5 ( V_10 , V_68 ) ;
V_67 = F_5 ( V_10 , V_69 ) ;
switch ( V_65 & V_70 ) {
case V_71 :
V_67 &= ~ V_72 ;
break;
case V_73 :
V_67 |= V_72 ;
break;
default:
return - V_74 ;
}
V_66 &= ~ V_75 ;
switch ( V_65 & V_76 ) {
case V_77 :
V_66 |= V_78 ;
V_66 &= ~ V_79 ;
break;
case V_80 :
V_66 |= V_81 ;
V_66 &= ~ V_79 ;
break;
case V_82 :
V_66 |= V_83 ;
V_66 &= ~ V_79 ;
break;
case V_84 :
V_66 |= V_85 ;
V_66 &= ~ V_79 ;
break;
case V_86 :
V_66 |= V_85 | V_79 ;
break;
default:
return - V_74 ;
}
F_6 ( V_10 , V_68 , V_66 ) ;
F_6 ( V_10 , V_69 , V_67 ) ;
return 0 ;
}
static int F_16 ( struct V_44 * V_45 ,
int V_87 , int div )
{
struct V_9 * V_10 = V_45 -> V_10 ;
switch ( V_87 ) {
case V_88 :
F_12 ( V_10 , V_51 ,
V_89 , div ) ;
break;
case V_90 :
F_12 ( V_10 , V_51 ,
V_91 , div ) ;
break;
case V_92 :
F_12 ( V_10 , V_51 ,
V_93 , div ) ;
break;
case V_94 :
F_12 ( V_10 , V_95 ,
V_96 , div ) ;
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_17 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
struct V_44 * V_101 )
{
struct V_9 * V_10 = V_101 -> V_10 ;
T_1 V_66 = F_5 ( V_10 , V_68 ) ;
V_66 &= ~ V_102 ;
switch ( F_18 ( V_100 ) ) {
case 16 :
break;
case 20 :
V_66 |= V_103 ;
break;
case 24 :
V_66 |= V_104 ;
break;
case 32 :
V_66 |= V_105 ;
break;
}
F_6 ( V_10 , V_68 , V_66 ) ;
return 0 ;
}
static int F_19 ( struct V_44 * V_101 , int V_106 )
{
struct V_9 * V_10 = V_101 -> V_10 ;
T_1 V_15 ;
V_15 = F_5 ( V_10 , V_107 ) & ~ V_108 ;
if ( V_106 )
F_6 ( V_10 , V_107 , V_15 | V_108 ) ;
else
F_6 ( V_10 , V_107 , V_15 ) ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 ,
enum V_109 V_110 )
{
struct V_62 * V_63 = F_14 ( V_10 ) ;
int V_14 ;
switch ( V_110 ) {
case V_111 :
break;
case V_112 :
F_12 ( V_10 , V_113 ,
V_114 , 0x2 ) ;
break;
case V_115 :
if ( V_10 -> V_116 . V_117 == V_118 ) {
V_14 = F_21 ( V_63 -> V_119 ) ;
if ( V_14 < 0 ) {
F_22 ( V_10 -> V_2 , L_6 , V_14 ) ;
return V_14 ;
}
F_6 ( V_10 , V_120 , V_121 |
V_122 | V_123 |
V_124 | V_125 |
V_126 ) ;
F_6 ( V_10 , V_127 , V_128 |
V_129 | V_130 |
V_131 ) ;
F_23 ( 300 ) ;
F_6 ( V_10 , V_127 , V_128 |
V_129 | V_130 ) ;
F_6 ( V_10 , V_120 , 0 ) ;
F_6 ( V_10 , V_113 , 0x1b00 ) ;
F_23 ( 50 ) ;
F_6 ( V_10 , V_113 , 0x1f02 ) ;
F_23 ( 100 ) ;
F_6 ( V_10 , V_113 , 0x1f03 ) ;
F_23 ( 600 ) ;
F_6 ( V_10 , V_127 , V_128 |
V_129 | V_130 |
V_132 ) ;
F_6 ( V_10 , V_113 , 0x3 ) ;
F_6 ( V_10 , V_127 , V_132 ) ;
F_6 ( V_10 , V_133 , 0x2 ) ;
F_6 ( V_10 , V_134 , 0xa003 ) ;
F_6 ( V_10 , V_133 , 0 ) ;
}
F_12 ( V_10 , V_113 ,
V_114 , 0x4 ) ;
break;
case V_118 :
F_6 ( V_10 , V_127 , V_128 |
V_130 | V_132 ) ;
F_6 ( V_10 , V_127 , V_128 |
V_129 | V_130 |
V_132 ) ;
F_12 ( V_10 , V_107 ,
V_108 , V_108 ) ;
F_6 ( V_10 , V_113 , 0x1f03 ) ;
F_6 ( V_10 , V_113 , 0x1f01 ) ;
F_23 ( 300 ) ;
F_6 ( V_10 , V_120 , V_121 |
V_122 | V_123 |
V_124 | V_125 |
V_126 ) ;
F_6 ( V_10 , V_113 , 0x0 ) ;
F_6 ( V_10 , V_127 , 0x0 ) ;
F_24 ( V_63 -> V_119 ) ;
break;
}
V_10 -> V_116 . V_117 = V_110 ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
F_20 ( V_10 , V_118 ) ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 )
{
F_20 ( V_10 , V_115 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
F_28 ( V_10 ) ;
F_20 ( V_10 , V_115 ) ;
F_12 ( V_10 , V_135 ,
V_136 , V_136 ) ;
F_12 ( V_10 , V_137 ,
V_138 , 1 ) ;
F_12 ( V_10 , V_49 ,
V_139 , V_139 ) ;
F_6 ( V_10 , V_140 , 0x50 | ( 1 << 8 ) ) ;
F_6 ( V_10 , V_141 , 0x50 | ( 1 << 8 ) ) ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
F_20 ( V_10 , V_118 ) ;
return 0 ;
}
static int F_30 ( struct V_142 * V_143 ,
const struct V_144 * V_145 )
{
struct V_62 * V_63 ;
int V_14 ;
V_63 = F_31 ( & V_143 -> V_2 , sizeof( struct V_62 ) ,
V_146 ) ;
if ( V_63 == NULL )
return - V_147 ;
F_32 ( V_143 , V_63 ) ;
V_14 = F_33 ( & V_143 -> V_2 ,
& V_148 , & V_149 , 1 ) ;
return V_14 ;
}
static int F_34 ( struct V_142 * V_150 )
{
F_35 ( & V_150 -> V_2 ) ;
return 0 ;
}
