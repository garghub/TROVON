static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
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
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_6 -> V_11 ;
int V_3 = V_10 -> V_3 ;
int V_12 ;
T_1 V_13 ;
V_12 = F_4 ( V_6 , V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_13 = F_5 ( V_2 , V_3 ) ;
return F_6 ( V_2 , V_3 , V_13 | 0x0100 ) ;
}
static int F_7 ( struct V_14 * V_15 ,
struct V_5 * V_6 , int V_16 )
{
T_1 V_3 , V_17 ;
V_3 = F_5 ( V_15 -> V_2 , V_18 ) ;
V_17 = F_5 ( V_15 -> V_2 , V_19 ) ;
if ( V_17 & ( ( 1 << V_20 ) |
( 1 << V_21 ) ) ) {
V_3 |= V_22 ;
} else {
V_3 &= ~ V_22 ;
}
if ( V_17 & ( ( 1 << V_23 ) |
( 1 << V_24 ) ) ) {
V_3 |= V_25 ;
} else {
V_3 &= ~ V_25 ;
}
F_6 ( V_15 -> V_2 , V_18 , V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 ,
struct V_5 * V_6 , int V_16 )
{
T_2 V_26 = V_6 -> V_11 & 0xfff ;
int V_12 = 0 ;
T_1 V_3 ;
switch ( V_26 ) {
case V_27 | ( V_28 << 8 ) :
V_3 = F_5 ( V_15 -> V_2 , V_29 ) ;
if ( V_3 & V_30 ) {
F_9 ( V_31
L_1 ) ;
V_12 = - 1 ;
}
break;
case V_27 | ( V_32 << 8 ) :
V_3 = F_5 ( V_15 -> V_2 , V_33 ) ;
if ( V_3 & V_34 ) {
F_9 ( V_31
L_2 ) ;
V_12 = - 1 ;
}
break;
case V_29 | ( V_35 << 8 ) :
V_3 = F_5 ( V_15 -> V_2 , V_27 ) ;
if ( V_3 & V_36 ) {
F_9 ( V_31
L_3 ) ;
V_12 = - 1 ;
}
break;
case V_33 | ( V_37 << 8 ) :
V_3 = F_5 ( V_15 -> V_2 , V_27 ) ;
if ( V_3 & V_38 ) {
F_9 ( V_31
L_4 ) ;
V_12 = - 1 ;
}
break;
}
return V_12 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = & V_2 -> V_40 ;
F_11 ( V_40 , V_41 ,
F_12 ( V_41 ) ) ;
F_13 ( V_40 , V_42 , F_12 ( V_42 ) ) ;
return 0 ;
}
static void F_14 ( struct V_43 * V_44 , unsigned int V_45 ,
unsigned int V_46 )
{
T_3 V_47 ;
unsigned int V_48 , V_49 , V_50 ;
V_49 = V_45 / V_46 ;
if ( V_49 < 6 ) {
V_46 >>= 1 ;
V_44 -> V_51 = 1 ;
V_49 = V_45 / V_46 ;
} else
V_44 -> V_51 = 0 ;
if ( ( V_49 < 6 ) || ( V_49 > 12 ) )
F_9 ( V_31
L_5 , V_49 ) ;
V_44 -> V_52 = V_49 ;
V_50 = V_45 % V_46 ;
V_47 = V_53 * ( long long ) V_50 ;
F_15 ( V_47 , V_46 ) ;
V_48 = V_47 & 0xFFFFFFFF ;
if ( ( V_48 % 10 ) >= 5 )
V_48 += 5 ;
V_48 /= 10 ;
V_44 -> V_54 = V_48 ;
}
static int F_16 ( struct V_55 * V_56 , int V_57 ,
int V_46 , unsigned int V_58 , unsigned int V_59 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_43 V_44 ;
if ( V_58 && V_59 ) {
F_14 ( & V_44 , V_59 * 4 , V_58 ) ;
F_17 ( V_2 , V_18 ,
V_60 , V_60 ) ;
F_17 ( V_2 , V_61 ,
V_62 , V_62 ) ;
F_6 ( V_2 , V_63 , V_44 . V_52 | V_64 |
( V_44 . V_51 ? V_65 : 0 ) ) ;
F_6 ( V_2 , V_66 , ( V_67 ) ( V_44 . V_54 >> 8 ) ) ;
F_6 ( V_2 , V_68 , ( V_67 ) ( V_44 . V_54 & 0xFF ) ) ;
} else {
F_17 ( V_2 , V_18 ,
V_60 , 0 ) ;
}
return 0 ;
}
static int F_18 ( struct V_55 * V_56 ,
int V_69 , unsigned int V_70 , int V_71 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_72 * V_73 = F_19 ( V_2 ) ;
V_73 -> V_74 = V_70 ;
return 0 ;
}
static int F_20 ( struct V_55 * V_56 ,
unsigned int V_75 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
T_1 V_76 , V_77 ;
V_76 = F_5 ( V_2 , V_78 ) ;
V_77 = F_5 ( V_2 , V_79 ) ;
switch ( V_75 & V_80 ) {
case V_81 :
V_77 &= ~ V_82 ;
break;
case V_83 :
V_77 |= V_82 ;
break;
default:
return - V_84 ;
}
V_76 &= ~ V_85 ;
switch ( V_75 & V_86 ) {
case V_87 :
V_76 |= V_88 ;
V_76 &= ~ V_89 ;
break;
case V_90 :
V_76 |= V_91 ;
V_76 &= ~ V_89 ;
break;
case V_92 :
V_76 |= V_93 ;
V_76 &= ~ V_89 ;
break;
case V_94 :
V_76 |= V_95 ;
V_76 &= ~ V_89 ;
break;
case V_96 :
V_76 |= V_95 | V_89 ;
break;
default:
return - V_84 ;
}
F_6 ( V_2 , V_78 , V_76 ) ;
F_6 ( V_2 , V_79 , V_77 ) ;
return 0 ;
}
static int F_21 ( struct V_55 * V_56 ,
int V_97 , int div )
{
struct V_1 * V_2 = V_56 -> V_2 ;
switch ( V_97 ) {
case V_98 :
F_17 ( V_2 , V_61 ,
V_99 , div ) ;
break;
case V_100 :
F_17 ( V_2 , V_61 ,
V_101 , div ) ;
break;
case V_102 :
F_17 ( V_2 , V_61 ,
V_103 , div ) ;
break;
case V_104 :
F_17 ( V_2 , V_105 ,
V_106 , div ) ;
break;
default:
return - V_84 ;
}
return 0 ;
}
static int F_22 ( struct V_107 * V_108 ,
struct V_109 * V_110 ,
struct V_55 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
T_1 V_76 = F_5 ( V_2 , V_78 ) ;
V_76 &= ~ V_112 ;
switch ( F_23 ( V_110 ) ) {
case V_113 :
break;
case V_114 :
V_76 |= V_115 ;
break;
case V_116 :
V_76 |= V_117 ;
break;
case V_118 :
V_76 |= V_119 ;
break;
}
F_6 ( V_2 , V_78 , V_76 ) ;
return 0 ;
}
static int F_24 ( struct V_55 * V_111 , int V_120 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
T_1 V_13 ;
V_13 = F_5 ( V_2 , V_121 ) & ~ V_122 ;
if ( V_120 )
F_6 ( V_2 , V_121 , V_13 | V_122 ) ;
else
F_6 ( V_2 , V_121 , V_13 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_123 V_124 )
{
int V_12 ;
switch ( V_124 ) {
case V_125 :
break;
case V_126 :
F_17 ( V_2 , V_127 ,
V_128 , 0x2 ) ;
break;
case V_129 :
if ( V_2 -> V_40 . V_130 == V_131 ) {
V_12 = F_26 ( V_2 ) ;
if ( V_12 < 0 ) {
F_27 ( V_2 -> V_132 , L_6 , V_12 ) ;
return V_12 ;
}
F_6 ( V_2 , V_133 , V_134 |
V_135 | V_136 |
V_137 | V_138 |
V_139 ) ;
F_6 ( V_2 , V_140 , V_141 |
V_142 | V_143 |
V_144 ) ;
F_28 ( 300 ) ;
F_6 ( V_2 , V_140 , V_141 |
V_142 | V_143 ) ;
F_6 ( V_2 , V_133 , 0 ) ;
F_6 ( V_2 , V_127 , 0x1b00 ) ;
F_28 ( 50 ) ;
F_6 ( V_2 , V_127 , 0x1f02 ) ;
F_28 ( 100 ) ;
F_6 ( V_2 , V_127 , 0x1f03 ) ;
F_28 ( 600 ) ;
F_6 ( V_2 , V_140 , V_141 |
V_142 | V_143 |
V_145 ) ;
F_6 ( V_2 , V_127 , 0x3 ) ;
F_6 ( V_2 , V_140 , V_145 ) ;
F_6 ( V_2 , V_146 , 0x2 ) ;
F_6 ( V_2 , V_147 , 0xa003 ) ;
F_6 ( V_2 , V_146 , 0 ) ;
}
F_17 ( V_2 , V_127 ,
V_128 , 0x4 ) ;
break;
case V_131 :
F_6 ( V_2 , V_140 , V_141 |
V_143 | V_145 ) ;
F_6 ( V_2 , V_140 , V_141 |
V_142 | V_143 |
V_145 ) ;
F_17 ( V_2 , V_121 ,
V_122 , V_122 ) ;
F_6 ( V_2 , V_127 , 0x1f03 ) ;
F_6 ( V_2 , V_127 , 0x1f01 ) ;
F_28 ( 300 ) ;
F_6 ( V_2 , V_133 , V_134 |
V_135 | V_136 |
V_137 | V_138 |
V_139 ) ;
F_6 ( V_2 , V_127 , 0x0 ) ;
F_6 ( V_2 , V_140 , 0x0 ) ;
V_2 -> V_148 = 1 ;
break;
}
V_2 -> V_40 . V_130 = V_124 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_131 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_129 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_32 ( V_2 , 8 , 16 , V_149 ) ;
if ( V_12 < 0 ) {
F_9 ( V_150 L_7 , V_12 ) ;
return V_12 ;
}
F_33 ( V_2 ) ;
F_25 ( V_2 , V_129 ) ;
F_17 ( V_2 , V_151 ,
V_152 , V_152 ) ;
F_17 ( V_2 , V_153 ,
V_154 , 1 ) ;
F_17 ( V_2 , V_18 ,
V_155 , V_155 ) ;
F_6 ( V_2 , V_156 , 0x50 | ( 1 << 8 ) ) ;
F_6 ( V_2 , V_157 , 0x50 | ( 1 << 8 ) ) ;
F_34 ( V_2 , V_158 ,
F_12 ( V_158 ) ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_131 ) ;
return 0 ;
}
static int F_36 ( struct V_159 * V_160 ,
const struct V_161 * V_162 )
{
struct V_72 * V_73 ;
int V_12 ;
V_73 = F_37 ( & V_160 -> V_132 , sizeof( struct V_72 ) ,
V_163 ) ;
if ( V_73 == NULL )
return - V_164 ;
F_38 ( V_160 , V_73 ) ;
V_12 = F_39 ( & V_160 -> V_132 ,
& V_165 , & V_166 , 1 ) ;
return V_12 ;
}
static int F_40 ( struct V_159 * V_167 )
{
F_41 ( & V_167 -> V_132 ) ;
return 0 ;
}
static int T_4 F_42 ( void )
{
int V_12 = 0 ;
#if F_43 ( V_168 ) || F_43 ( V_169 )
V_12 = F_44 ( & V_170 ) ;
if ( V_12 != 0 ) {
F_9 ( V_150 L_8 ,
V_12 ) ;
}
#endif
return V_12 ;
}
static void T_5 F_45 ( void )
{
#if F_43 ( V_168 ) || F_43 ( V_169 )
F_46 ( & V_170 ) ;
#endif
}
