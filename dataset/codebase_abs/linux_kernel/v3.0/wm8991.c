static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_2 -> V_8 & 0xff ;
int V_9 ;
T_1 V_10 ;
V_9 = F_3 ( V_2 , V_4 ) ;
if ( V_9 < 0 )
return V_9 ;
V_10 = F_4 ( V_6 , V_7 ) ;
return F_5 ( V_6 , V_7 , V_10 | 0x0100 ) ;
}
static int F_6 ( struct V_11 * V_12 ,
struct V_1 * V_2 , int V_13 )
{
T_1 V_7 , V_14 ;
V_7 = F_4 ( V_12 -> V_6 , V_15 ) ;
V_14 = F_4 ( V_12 -> V_6 , V_16 ) ;
if ( V_14 & ( ( 1 << V_17 ) |
( 1 << V_18 ) ) )
V_7 |= V_19 ;
else
V_7 &= ~ V_19 ;
if ( V_14 & ( ( 1 << V_20 ) |
( 1 << V_21 ) ) )
V_7 |= V_22 ;
else
V_7 &= ~ V_19 ;
F_5 ( V_12 -> V_6 , V_15 , V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_1 * V_2 , int V_13 )
{
T_2 V_23 = V_2 -> V_8 & 0xfff ;
int V_9 = 0 ;
T_1 V_7 ;
switch ( V_23 ) {
case V_24 | ( V_25 << 8 ) :
V_7 = F_4 ( V_12 -> V_6 , V_26 ) ;
if ( V_7 & V_27 ) {
F_8 ( V_28
L_1 ) ;
V_9 = - 1 ;
}
break;
case V_24 | ( V_29 << 8 ) :
V_7 = F_4 ( V_12 -> V_6 , V_30 ) ;
if ( V_7 & V_31 ) {
F_8 ( V_28
L_2 ) ;
V_9 = - 1 ;
}
break;
case V_26 | ( V_32 << 8 ) :
V_7 = F_4 ( V_12 -> V_6 , V_24 ) ;
if ( V_7 & V_33 ) {
F_8 ( V_28
L_3 ) ;
V_9 = - 1 ;
}
break;
case V_30 | ( V_34 << 8 ) :
V_7 = F_4 ( V_12 -> V_6 , V_24 ) ;
if ( V_7 & V_35 ) {
F_8 ( V_28
L_4 ) ;
V_9 = - 1 ;
}
break;
}
return V_9 ;
}
static void F_9 ( struct V_36 * V_37 , unsigned int V_38 ,
unsigned int V_39 )
{
T_3 V_40 ;
unsigned int V_41 , V_42 , V_43 ;
V_42 = V_38 / V_39 ;
if ( V_42 < 6 ) {
V_39 >>= 1 ;
V_37 -> V_44 = 1 ;
V_42 = V_38 / V_39 ;
} else
V_37 -> V_44 = 0 ;
if ( ( V_42 < 6 ) || ( V_42 > 12 ) )
F_8 ( V_28
L_5 , V_42 ) ;
V_37 -> V_45 = V_42 ;
V_43 = V_38 % V_39 ;
V_40 = V_46 * ( long long ) V_43 ;
F_10 ( V_40 , V_39 ) ;
V_41 = V_40 & 0xFFFFFFFF ;
if ( ( V_41 % 10 ) >= 5 )
V_41 += 5 ;
V_41 /= 10 ;
V_37 -> V_47 = V_41 ;
}
static int F_11 ( struct V_48 * V_49 ,
int V_50 , int V_51 , unsigned int V_52 , unsigned int V_53 )
{
T_1 V_7 ;
struct V_5 * V_6 = V_49 -> V_6 ;
struct V_36 V_37 ;
if ( V_52 && V_53 ) {
F_9 ( & V_37 , V_53 * 4 , V_52 ) ;
V_7 = F_4 ( V_6 , V_15 ) ;
V_7 |= V_54 ;
F_5 ( V_6 , V_15 , V_7 ) ;
V_7 = F_4 ( V_6 , V_55 ) ;
F_5 ( V_6 , V_55 , V_7 | V_56 ) ;
F_5 ( V_6 , V_57 , V_37 . V_45 | V_58 |
( V_37 . V_44 ? V_59 : 0 ) ) ;
F_5 ( V_6 , V_60 , ( V_61 ) ( V_37 . V_47 >> 8 ) ) ;
F_5 ( V_6 , V_62 , ( V_61 ) ( V_37 . V_47 & 0xFF ) ) ;
} else {
V_7 = F_4 ( V_6 , V_15 ) ;
V_7 &= ~ V_54 ;
F_5 ( V_6 , V_15 , V_7 ) ;
}
return 0 ;
}
static int F_12 ( struct V_48 * V_49 ,
unsigned int V_63 )
{
struct V_5 * V_6 = V_49 -> V_6 ;
T_1 V_64 , V_65 ;
V_64 = F_4 ( V_6 , V_66 ) ;
V_65 = F_4 ( V_6 , V_67 ) ;
switch ( V_63 & V_68 ) {
case V_69 :
V_65 &= ~ V_70 ;
break;
case V_71 :
V_65 |= V_70 ;
break;
default:
return - V_72 ;
}
V_64 &= ~ V_73 ;
switch ( V_63 & V_74 ) {
case V_75 :
V_64 |= V_76 ;
V_64 &= ~ V_77 ;
break;
case V_78 :
V_64 |= V_79 ;
V_64 &= ~ V_77 ;
break;
case V_80 :
V_64 |= V_81 ;
V_64 &= ~ V_77 ;
break;
case V_82 :
V_64 |= V_83 ;
V_64 &= ~ V_77 ;
break;
case V_84 :
V_64 |= V_83 | V_77 ;
break;
default:
return - V_72 ;
}
F_5 ( V_6 , V_66 , V_64 ) ;
F_5 ( V_6 , V_67 , V_65 ) ;
return 0 ;
}
static int F_13 ( struct V_48 * V_49 ,
int V_85 , int div )
{
struct V_5 * V_6 = V_49 -> V_6 ;
T_1 V_7 ;
switch ( V_85 ) {
case V_86 :
V_7 = F_4 ( V_6 , V_55 ) &
~ V_87 ;
F_5 ( V_6 , V_55 , V_7 | div ) ;
break;
case V_88 :
V_7 = F_4 ( V_6 , V_55 ) &
~ V_89 ;
F_5 ( V_6 , V_55 , V_7 | div ) ;
break;
case V_90 :
V_7 = F_4 ( V_6 , V_55 ) &
~ V_91 ;
F_5 ( V_6 , V_55 , V_7 | div ) ;
break;
case V_92 :
V_7 = F_4 ( V_6 , V_93 ) &
~ V_94 ;
F_5 ( V_6 , V_93 , V_7 | div ) ;
break;
default:
return - V_72 ;
}
return 0 ;
}
static int F_14 ( struct V_95 * V_96 ,
struct V_97 * V_98 ,
struct V_48 * V_99 )
{
struct V_5 * V_6 = V_99 -> V_6 ;
T_1 V_64 = F_4 ( V_6 , V_66 ) ;
V_64 &= ~ V_100 ;
switch ( F_15 ( V_98 ) ) {
case V_101 :
break;
case V_102 :
V_64 |= V_103 ;
break;
case V_104 :
V_64 |= V_105 ;
break;
case V_106 :
V_64 |= V_107 ;
break;
}
F_5 ( V_6 , V_66 , V_64 ) ;
return 0 ;
}
static int F_16 ( struct V_48 * V_99 , int V_108 )
{
struct V_5 * V_6 = V_99 -> V_6 ;
T_1 V_10 ;
V_10 = F_4 ( V_6 , V_109 ) & ~ V_110 ;
if ( V_108 )
F_5 ( V_6 , V_109 , V_10 | V_110 ) ;
else
F_5 ( V_6 , V_109 , V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
enum V_111 V_112 )
{
T_1 V_10 ;
switch ( V_112 ) {
case V_113 :
break;
case V_114 :
V_10 = F_4 ( V_6 , V_115 ) &
~ V_116 ;
F_5 ( V_6 , V_115 , V_10 | 0x2 ) ;
break;
case V_117 :
if ( V_6 -> V_118 . V_119 == V_120 ) {
F_18 ( V_6 ) ;
F_5 ( V_6 , V_121 , V_122 |
V_123 | V_124 |
V_125 | V_126 |
V_127 ) ;
F_5 ( V_6 , V_128 , V_129 |
V_130 | V_131 |
V_132 ) ;
F_19 ( 300 ) ;
F_5 ( V_6 , V_128 , V_129 |
V_130 | V_131 ) ;
F_5 ( V_6 , V_121 , 0 ) ;
F_5 ( V_6 , V_115 , 0x1b00 ) ;
F_19 ( 50 ) ;
F_5 ( V_6 , V_115 , 0x1f02 ) ;
F_19 ( 100 ) ;
F_5 ( V_6 , V_115 , 0x1f03 ) ;
F_19 ( 600 ) ;
F_5 ( V_6 , V_128 , V_129 |
V_130 | V_131 |
V_133 ) ;
F_5 ( V_6 , V_115 , 0x3 ) ;
F_5 ( V_6 , V_128 , V_133 ) ;
}
V_10 = F_4 ( V_6 , V_115 ) &
~ V_116 ;
F_5 ( V_6 , V_115 , V_10 | 0x4 ) ;
break;
case V_120 :
F_5 ( V_6 , V_128 , V_129 |
V_131 | V_133 ) ;
F_5 ( V_6 , V_128 , V_129 |
V_130 | V_131 |
V_133 ) ;
V_10 = F_4 ( V_6 , V_109 ) ;
F_5 ( V_6 , V_109 , V_10 | V_110 ) ;
F_5 ( V_6 , V_115 , 0x1f03 ) ;
F_5 ( V_6 , V_115 , 0x1f01 ) ;
F_19 ( 300 ) ;
F_5 ( V_6 , V_121 , V_122 |
V_123 | V_124 |
V_125 | V_126 |
V_127 ) ;
F_5 ( V_6 , V_115 , 0x0 ) ;
F_5 ( V_6 , V_128 , 0x0 ) ;
V_6 -> V_134 = 1 ;
break;
}
V_6 -> V_118 . V_119 = V_112 ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , T_4 V_135 )
{
F_17 ( V_6 , V_120 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
F_17 ( V_6 , V_117 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
F_17 ( V_6 , V_120 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 )
{
struct V_136 * V_137 ;
int V_9 ;
unsigned int V_7 ;
V_137 = F_24 ( V_6 ) ;
V_9 = F_25 ( V_6 , 8 , 16 , V_137 -> V_138 ) ;
if ( V_9 < 0 ) {
F_26 ( V_6 -> V_139 , L_6 , V_9 ) ;
return V_9 ;
}
V_9 = F_27 ( V_6 ) ;
if ( V_9 < 0 ) {
F_26 ( V_6 -> V_139 , L_7 ) ;
return V_9 ;
}
F_17 ( V_6 , V_117 ) ;
V_7 = F_4 ( V_6 , V_140 ) ;
F_5 ( V_6 , V_140 , V_7 | V_141 ) ;
V_7 = F_4 ( V_6 , V_142 ) &
~ V_143 ;
F_5 ( V_6 , V_142 , V_7 | 1 ) ;
V_7 = F_4 ( V_6 , V_115 ) ;
F_5 ( V_6 , V_115 , V_7 | V_144 |
V_116 ) ;
V_7 = F_4 ( V_6 , V_15 ) ;
F_5 ( V_6 , V_15 , V_7 | V_145 ) ;
F_5 ( V_6 , V_109 , 0 ) ;
F_5 ( V_6 , V_146 , 0x50 | ( 1 << 8 ) ) ;
F_5 ( V_6 , V_147 , 0x50 | ( 1 << 8 ) ) ;
F_28 ( V_6 , V_148 ,
F_29 ( V_148 ) ) ;
F_30 ( & V_6 -> V_118 , V_149 ,
F_29 ( V_149 ) ) ;
F_31 ( & V_6 -> V_118 , V_150 ,
F_29 ( V_150 ) ) ;
return 0 ;
}
static T_5 int F_32 ( struct V_151 * V_152 ,
const struct V_153 * V_154 )
{
struct V_136 * V_137 ;
int V_9 ;
V_137 = F_33 ( sizeof *V_137 , V_155 ) ;
if ( ! V_137 )
return - V_156 ;
V_137 -> V_138 = V_157 ;
F_34 ( V_152 , V_137 ) ;
V_9 = F_35 ( & V_152 -> V_139 ,
& V_158 , & V_159 , 1 ) ;
if ( V_9 < 0 )
F_36 ( V_137 ) ;
return V_9 ;
}
static T_6 int F_37 ( struct V_151 * V_160 )
{
F_38 ( & V_160 -> V_139 ) ;
F_36 ( F_39 ( V_160 ) ) ;
return 0 ;
}
static int T_7 F_40 ( void )
{
int V_9 ;
V_9 = F_41 ( & V_161 ) ;
if ( V_9 != 0 ) {
F_8 ( V_162 L_8 ,
V_9 ) ;
}
return 0 ;
}
static void T_8 F_42 ( void )
{
F_43 ( & V_161 ) ;
}
