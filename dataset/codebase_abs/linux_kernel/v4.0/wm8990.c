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
struct V_9 * V_10 = F_8 ( V_17 -> V_19 ) ;
T_2 V_20 = V_6 -> V_13 & 0xfff ;
int V_14 = 0 ;
T_1 V_3 ;
switch ( V_20 ) {
case V_21 | ( V_22 << 8 ) :
V_3 = F_5 ( V_10 , V_23 ) ;
if ( V_3 & V_24 ) {
F_9 ( V_25
L_1 ) ;
V_14 = - 1 ;
}
break;
case V_21 | ( V_26 << 8 ) :
V_3 = F_5 ( V_10 , V_27 ) ;
if ( V_3 & V_28 ) {
F_9 ( V_25
L_2 ) ;
V_14 = - 1 ;
}
break;
case V_23 | ( V_29 << 8 ) :
V_3 = F_5 ( V_10 , V_21 ) ;
if ( V_3 & V_30 ) {
F_9 ( V_25
L_3 ) ;
V_14 = - 1 ;
}
break;
case V_27 | ( V_31 << 8 ) :
V_3 = F_5 ( V_10 , V_21 ) ;
if ( V_3 & V_32 ) {
F_9 ( V_25
L_4 ) ;
V_14 = - 1 ;
}
break;
}
return V_14 ;
}
static void F_10 ( struct V_33 * V_34 , unsigned int V_35 ,
unsigned int V_36 )
{
T_3 V_37 ;
unsigned int V_38 , V_39 , V_40 ;
V_39 = V_35 / V_36 ;
if ( V_39 < 6 ) {
V_36 >>= 1 ;
V_34 -> V_41 = 1 ;
V_39 = V_35 / V_36 ;
} else
V_34 -> V_41 = 0 ;
if ( ( V_39 < 6 ) || ( V_39 > 12 ) )
F_9 ( V_25
L_5 , V_39 ) ;
V_34 -> V_42 = V_39 ;
V_40 = V_35 % V_36 ;
V_37 = V_43 * ( long long ) V_40 ;
F_11 ( V_37 , V_36 ) ;
V_38 = V_37 & 0xFFFFFFFF ;
if ( ( V_38 % 10 ) >= 5 )
V_38 += 5 ;
V_38 /= 10 ;
V_34 -> V_44 = V_38 ;
}
static int F_12 ( struct V_45 * V_46 , int V_47 ,
int V_36 , unsigned int V_48 , unsigned int V_49 )
{
struct V_9 * V_10 = V_46 -> V_10 ;
struct V_33 V_34 ;
if ( V_48 && V_49 ) {
F_10 ( & V_34 , V_49 * 4 , V_48 ) ;
F_13 ( V_10 , V_50 ,
V_51 , V_51 ) ;
F_13 ( V_10 , V_52 ,
V_53 , V_53 ) ;
F_6 ( V_10 , V_54 , V_34 . V_42 | V_55 |
( V_34 . V_41 ? V_56 : 0 ) ) ;
F_6 ( V_10 , V_57 , ( V_58 ) ( V_34 . V_44 >> 8 ) ) ;
F_6 ( V_10 , V_59 , ( V_58 ) ( V_34 . V_44 & 0xFF ) ) ;
} else {
F_13 ( V_10 , V_50 ,
V_51 , 0 ) ;
}
return 0 ;
}
static int F_14 ( struct V_45 * V_46 ,
int V_60 , unsigned int V_61 , int V_62 )
{
struct V_9 * V_10 = V_46 -> V_10 ;
struct V_63 * V_64 = F_15 ( V_10 ) ;
V_64 -> V_65 = V_61 ;
return 0 ;
}
static int F_16 ( struct V_45 * V_46 ,
unsigned int V_66 )
{
struct V_9 * V_10 = V_46 -> V_10 ;
T_1 V_67 , V_68 ;
V_67 = F_5 ( V_10 , V_69 ) ;
V_68 = F_5 ( V_10 , V_70 ) ;
switch ( V_66 & V_71 ) {
case V_72 :
V_68 &= ~ V_73 ;
break;
case V_74 :
V_68 |= V_73 ;
break;
default:
return - V_75 ;
}
V_67 &= ~ V_76 ;
switch ( V_66 & V_77 ) {
case V_78 :
V_67 |= V_79 ;
V_67 &= ~ V_80 ;
break;
case V_81 :
V_67 |= V_82 ;
V_67 &= ~ V_80 ;
break;
case V_83 :
V_67 |= V_84 ;
V_67 &= ~ V_80 ;
break;
case V_85 :
V_67 |= V_86 ;
V_67 &= ~ V_80 ;
break;
case V_87 :
V_67 |= V_86 | V_80 ;
break;
default:
return - V_75 ;
}
F_6 ( V_10 , V_69 , V_67 ) ;
F_6 ( V_10 , V_70 , V_68 ) ;
return 0 ;
}
static int F_17 ( struct V_45 * V_46 ,
int V_88 , int div )
{
struct V_9 * V_10 = V_46 -> V_10 ;
switch ( V_88 ) {
case V_89 :
F_13 ( V_10 , V_52 ,
V_90 , div ) ;
break;
case V_91 :
F_13 ( V_10 , V_52 ,
V_92 , div ) ;
break;
case V_93 :
F_13 ( V_10 , V_52 ,
V_94 , div ) ;
break;
case V_95 :
F_13 ( V_10 , V_96 ,
V_97 , div ) ;
break;
default:
return - V_75 ;
}
return 0 ;
}
static int F_18 ( struct V_98 * V_99 ,
struct V_100 * V_101 ,
struct V_45 * V_102 )
{
struct V_9 * V_10 = V_102 -> V_10 ;
T_1 V_67 = F_5 ( V_10 , V_69 ) ;
V_67 &= ~ V_103 ;
switch ( F_19 ( V_101 ) ) {
case 16 :
break;
case 20 :
V_67 |= V_104 ;
break;
case 24 :
V_67 |= V_105 ;
break;
case 32 :
V_67 |= V_106 ;
break;
}
F_6 ( V_10 , V_69 , V_67 ) ;
return 0 ;
}
static int F_20 ( struct V_45 * V_102 , int V_107 )
{
struct V_9 * V_10 = V_102 -> V_10 ;
T_1 V_15 ;
V_15 = F_5 ( V_10 , V_108 ) & ~ V_109 ;
if ( V_107 )
F_6 ( V_10 , V_108 , V_15 | V_109 ) ;
else
F_6 ( V_10 , V_108 , V_15 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
enum V_110 V_111 )
{
struct V_63 * V_64 = F_15 ( V_10 ) ;
int V_14 ;
switch ( V_111 ) {
case V_112 :
break;
case V_113 :
F_13 ( V_10 , V_114 ,
V_115 , 0x2 ) ;
break;
case V_116 :
if ( V_10 -> V_19 . V_117 == V_118 ) {
V_14 = F_22 ( V_64 -> V_119 ) ;
if ( V_14 < 0 ) {
F_23 ( V_10 -> V_2 , L_6 , V_14 ) ;
return V_14 ;
}
F_6 ( V_10 , V_120 , V_121 |
V_122 | V_123 |
V_124 | V_125 |
V_126 ) ;
F_6 ( V_10 , V_127 , V_128 |
V_129 | V_130 |
V_131 ) ;
F_24 ( 300 ) ;
F_6 ( V_10 , V_127 , V_128 |
V_129 | V_130 ) ;
F_6 ( V_10 , V_120 , 0 ) ;
F_6 ( V_10 , V_114 , 0x1b00 ) ;
F_24 ( 50 ) ;
F_6 ( V_10 , V_114 , 0x1f02 ) ;
F_24 ( 100 ) ;
F_6 ( V_10 , V_114 , 0x1f03 ) ;
F_24 ( 600 ) ;
F_6 ( V_10 , V_127 , V_128 |
V_129 | V_130 |
V_132 ) ;
F_6 ( V_10 , V_114 , 0x3 ) ;
F_6 ( V_10 , V_127 , V_132 ) ;
F_6 ( V_10 , V_133 , 0x2 ) ;
F_6 ( V_10 , V_134 , 0xa003 ) ;
F_6 ( V_10 , V_133 , 0 ) ;
}
F_13 ( V_10 , V_114 ,
V_115 , 0x4 ) ;
break;
case V_118 :
F_6 ( V_10 , V_127 , V_128 |
V_130 | V_132 ) ;
F_6 ( V_10 , V_127 , V_128 |
V_129 | V_130 |
V_132 ) ;
F_13 ( V_10 , V_108 ,
V_109 , V_109 ) ;
F_6 ( V_10 , V_114 , 0x1f03 ) ;
F_6 ( V_10 , V_114 , 0x1f01 ) ;
F_24 ( 300 ) ;
F_6 ( V_10 , V_120 , V_121 |
V_122 | V_123 |
V_124 | V_125 |
V_126 ) ;
F_6 ( V_10 , V_114 , 0x0 ) ;
F_6 ( V_10 , V_127 , 0x0 ) ;
F_25 ( V_64 -> V_119 ) ;
break;
}
V_10 -> V_19 . V_117 = V_111 ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 )
{
F_27 ( V_10 ) ;
F_21 ( V_10 , V_116 ) ;
F_13 ( V_10 , V_135 ,
V_136 , V_136 ) ;
F_13 ( V_10 , V_137 ,
V_138 , 1 ) ;
F_13 ( V_10 , V_50 ,
V_139 , V_139 ) ;
F_6 ( V_10 , V_140 , 0x50 | ( 1 << 8 ) ) ;
F_6 ( V_10 , V_141 , 0x50 | ( 1 << 8 ) ) ;
return 0 ;
}
static int F_28 ( struct V_142 * V_143 ,
const struct V_144 * V_145 )
{
struct V_63 * V_64 ;
int V_14 ;
V_64 = F_29 ( & V_143 -> V_2 , sizeof( struct V_63 ) ,
V_146 ) ;
if ( V_64 == NULL )
return - V_147 ;
F_30 ( V_143 , V_64 ) ;
V_14 = F_31 ( & V_143 -> V_2 ,
& V_148 , & V_149 , 1 ) ;
return V_14 ;
}
static int F_32 ( struct V_142 * V_150 )
{
F_33 ( & V_150 -> V_2 ) ;
return 0 ;
}
