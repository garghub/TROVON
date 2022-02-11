static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_4 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_6 -> V_11 ;
int V_12 = V_10 -> V_12 ;
int V_13 ;
T_1 V_14 ;
V_13 = F_6 ( V_6 , V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_14 = F_7 ( V_2 , V_12 ) ;
return F_8 ( V_2 , V_12 , V_14 | 0x0100 ) ;
}
static int F_9 ( struct V_15 * V_16 ,
struct V_5 * V_6 , int V_17 )
{
struct V_1 * V_2 = F_10 ( V_16 -> V_18 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_6 -> V_11 ;
T_2 V_19 = V_10 -> V_20 ;
int V_13 = 0 ;
T_1 V_12 ;
switch ( V_19 ) {
case V_21 | ( V_22 << 8 ) :
V_12 = F_7 ( V_2 , V_23 ) ;
if ( V_12 & V_24 ) {
F_11 ( V_25
L_1 ) ;
V_13 = - 1 ;
}
break;
case V_21 | ( V_26 << 8 ) :
V_12 = F_7 ( V_2 , V_27 ) ;
if ( V_12 & V_28 ) {
F_11 ( V_25
L_2 ) ;
V_13 = - 1 ;
}
break;
case V_23 | ( V_24 << 8 ) :
V_12 = F_7 ( V_2 , V_21 ) ;
if ( V_12 & V_22 ) {
F_11 ( V_25
L_3 ) ;
V_13 = - 1 ;
}
break;
case V_27 | ( V_28 << 8 ) :
V_12 = F_7 ( V_2 , V_21 ) ;
if ( V_12 & V_26 ) {
F_11 ( V_25
L_4 ) ;
V_13 = - 1 ;
}
break;
}
return V_13 ;
}
static int F_12 ( struct V_29 * V_30 ,
int V_31 , unsigned int V_32 , int V_33 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_34 = V_32 ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 , struct F_13 * V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
T_3 V_38 ;
unsigned int V_39 , V_40 , V_41 ;
V_35 -> V_42 = 2 ;
while ( V_37 * V_35 -> V_42 < 90000000 ||
V_37 * V_35 -> V_42 > 100000000 ) {
V_35 -> V_42 *= 2 ;
if ( V_35 -> V_42 > 32 ) {
F_14 ( V_4 -> V_4 -> V_43 ,
L_5 ,
V_37 ) ;
return - V_44 ;
}
}
V_41 = V_37 * V_35 -> V_42 ;
V_35 -> V_42 = V_35 -> V_42 >> 2 ;
if ( V_36 < 48000 )
V_35 -> V_45 = 1 ;
else
V_35 -> V_45 = 0 ;
if ( V_36 < 1000000 )
V_35 -> V_46 = 9 ;
else
V_35 -> V_46 = 0 ;
do {
if ( V_36 < 1000000 )
V_35 -> V_46 -- ;
else
V_35 -> V_46 ++ ;
if ( V_35 -> V_46 < 1 || V_35 -> V_46 > 8 ) {
F_14 ( V_4 -> V_4 -> V_43 ,
L_6 ) ;
return - V_44 ;
}
V_35 -> V_47 = V_41 / ( V_36 * V_35 -> V_46 ) ;
V_40 = V_41 % ( V_36 * V_35 -> V_46 ) ;
} while ( V_40 == 0 );
V_38 = V_48 * ( long long ) V_40 ;
F_15 ( V_38 , ( V_36 * V_35 -> V_46 ) ) ;
V_39 = V_38 & 0xFFFFFFFF ;
if ( ( V_39 % 10 ) >= 5 )
V_39 += 5 ;
V_35 -> V_49 = V_39 / 10 ;
F_16 ( V_4 -> V_4 -> V_43 ,
L_7 ,
V_36 , V_37 ,
V_35 -> V_47 , V_35 -> V_49 , V_35 -> V_46 , V_35 -> V_42 ) ;
return 0 ;
}
static int F_17 ( struct V_29 * V_30 , int V_50 ,
int V_51 , unsigned int V_52 ,
unsigned int V_53 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct F_13 V_35 ;
int V_13 ;
T_1 V_12 ;
if ( V_52 == V_4 -> V_54 && V_53 == V_4 -> V_55 )
return 0 ;
if ( V_53 ) {
V_13 = F_13 ( V_4 , & V_35 , V_52 , V_53 ) ;
if ( V_13 != 0 )
return V_13 ;
} else {
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
}
V_4 -> V_55 = V_53 ;
V_4 -> V_54 = V_52 ;
V_12 = F_7 ( V_2 , V_56 ) ;
V_12 &= ~ V_57 ;
F_8 ( V_2 , V_56 , V_12 ) ;
V_12 = F_7 ( V_2 , V_58 ) ;
V_12 &= ~ V_59 ;
F_8 ( V_2 , V_58 , V_12 ) ;
if ( ! V_53 )
return 0 ;
V_12 &= ~ ( V_60 | V_61 ) ;
V_12 |= V_62 | V_35 . V_46 ;
V_12 |= V_35 . V_45 << V_63 ;
F_8 ( V_2 , V_58 , V_12 ) ;
F_8 ( V_2 , V_64 , V_35 . V_49 ) ;
F_8 ( V_2 , V_65 , V_35 . V_47 ) ;
V_12 = F_7 ( V_2 , V_66 ) ;
V_12 &= ~ V_67 ;
V_12 |= V_35 . V_42 ;
F_8 ( V_2 , V_66 , V_12 ) ;
return 0 ;
}
static int F_18 ( struct V_29 * V_30 ,
unsigned int V_68 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_69 , V_70 ;
V_69 = F_7 ( V_2 , V_71 ) ;
V_70 = F_7 ( V_2 , V_72 ) ;
switch ( V_68 & V_73 ) {
case V_74 :
V_70 &= ~ V_75 ;
break;
case V_76 :
V_70 |= V_75 ;
break;
default:
return - V_44 ;
}
V_69 &= ~ V_77 ;
switch ( V_68 & V_78 ) {
case V_79 :
V_69 |= V_80 ;
V_69 &= ~ V_81 ;
break;
case V_82 :
V_69 |= V_83 ;
V_69 &= ~ V_81 ;
break;
case V_84 :
V_69 |= V_85 ;
V_69 &= ~ V_81 ;
break;
case V_86 :
V_69 |= V_87 ;
V_69 &= ~ V_81 ;
break;
case V_88 :
V_69 |= V_87 | V_81 ;
break;
default:
return - V_44 ;
}
F_8 ( V_2 , V_71 , V_69 ) ;
F_8 ( V_2 , V_72 , V_70 ) ;
return 0 ;
}
static int F_19 ( struct V_29 * V_30 ,
int V_89 , int div )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_12 ;
switch ( V_89 ) {
case V_90 :
V_12 = F_7 ( V_2 , V_91 ) &
~ V_92 ;
F_8 ( V_2 , V_91 , V_12 | div ) ;
break;
case V_93 :
V_12 = F_7 ( V_2 , V_91 ) &
~ V_94 ;
F_8 ( V_2 , V_91 , V_12 | div ) ;
break;
case V_95 :
V_12 = F_7 ( V_2 , V_91 ) &
~ V_96 ;
F_8 ( V_2 , V_91 , V_12 | div ) ;
break;
case V_97 :
V_12 = F_7 ( V_2 , V_98 ) &
~ V_99 ;
F_8 ( V_2 , V_98 , V_12 | div ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_20 ( struct V_100 * V_101 ,
struct V_102 * V_103 ,
struct V_29 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
T_1 V_69 = F_7 ( V_2 , V_71 ) ;
V_69 &= ~ V_105 ;
switch ( F_21 ( V_103 ) ) {
case 16 :
break;
case 20 :
V_69 |= V_106 ;
break;
case 24 :
V_69 |= V_107 ;
break;
case 32 :
V_69 |= V_108 ;
break;
}
F_8 ( V_2 , V_71 , V_69 ) ;
return 0 ;
}
static int F_22 ( struct V_29 * V_104 , int V_109 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
T_1 V_14 = F_7 ( V_2 , V_110 ) & ~ V_111 ;
if ( V_109 )
F_8 ( V_2 , V_110 , V_14 | V_111 ) ;
else
F_8 ( V_2 , V_110 , V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_112 V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_14 ;
int V_13 ;
switch ( V_113 ) {
case V_114 :
break;
case V_115 :
V_14 = F_7 ( V_2 , V_116 ) &
~ V_117 ;
F_8 ( V_2 , V_116 , V_14 | 0x2 ) ;
break;
case V_118 :
if ( V_2 -> V_18 . V_119 == V_120 ) {
V_13 = F_24 ( F_25 ( V_121 ) ,
& V_121 [ 0 ] ) ;
if ( V_13 != 0 ) {
F_14 ( V_4 -> V_4 -> V_43 ,
L_8 ,
V_13 ) ;
return V_13 ;
}
F_8 ( V_2 , V_116 ,
V_122 | V_123 ) ;
F_8 ( V_2 , V_124 , V_125 |
V_126 | V_127 ) ;
F_26 ( 50 ) ;
V_14 = F_7 ( V_2 , V_116 ) ;
V_14 |= 0x2 | V_128 ;
F_8 ( V_2 , V_116 , V_14 ) ;
F_8 ( V_2 , V_124 , V_125 |
V_126 | V_127 |
V_129 ) ;
F_8 ( V_2 , V_124 , V_129 ) ;
}
V_14 = F_7 ( V_2 , V_116 ) &
~ V_117 ;
F_8 ( V_2 , V_116 , V_14 | 0x4 ) ;
break;
case V_120 :
F_8 ( V_2 , V_124 , V_125 |
V_127 | V_129 ) ;
F_8 ( V_2 , V_124 , V_125 |
V_126 | V_127 |
V_129 ) ;
V_14 = F_7 ( V_2 , V_110 ) ;
F_8 ( V_2 , V_110 , V_14 | V_111 ) ;
V_14 = F_7 ( V_2 , V_116 ) ;
V_14 |= V_130 | V_131 |
V_132 | V_133 |
V_134 ;
F_8 ( V_2 , V_116 , V_14 ) ;
V_14 &= ~ V_117 ;
F_8 ( V_2 , V_116 , V_14 ) ;
F_26 ( 300 ) ;
F_8 ( V_2 , V_135 , V_136 |
V_137 | V_138 |
V_139 | V_140 |
V_141 ) ;
V_14 &= ~ V_128 ;
F_8 ( V_2 , V_116 , V_14 ) ;
F_8 ( V_2 , V_124 , 0x0 ) ;
V_13 = F_27 ( F_25 ( V_121 ) ,
& V_121 [ 0 ] ) ;
if ( V_13 != 0 )
return V_13 ;
break;
}
V_2 -> V_18 . V_119 = V_113 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_29 ( V_2 -> V_43 ) ;
struct V_3 * V_142 ;
int V_13 ;
T_1 V_12 ;
V_142 = F_30 ( V_2 -> V_43 , sizeof( struct V_3 ) ,
V_143 ) ;
if ( V_142 == NULL )
return - V_144 ;
F_31 ( V_2 , V_142 ) ;
V_142 -> V_4 = V_4 ;
V_13 = F_32 ( V_4 -> V_43 ,
F_25 ( V_121 ) , & V_121 [ 0 ] ) ;
if ( V_13 != 0 ) {
F_14 ( V_2 -> V_43 , L_9 , V_13 ) ;
return V_13 ;
}
F_1 ( V_2 ) ;
V_12 = F_7 ( V_2 , V_116 ) ;
F_8 ( V_2 , V_116 , V_12 | V_122 ) ;
V_12 = F_7 ( V_2 , V_145 ) ;
F_8 ( V_2 , V_145 ,
V_12 & V_146 ) ;
V_12 = F_7 ( V_2 , V_147 ) ;
F_8 ( V_2 , V_147 ,
V_12 & V_146 ) ;
F_8 ( V_2 , V_148 , 0x50 | ( 1 << 8 ) ) ;
F_8 ( V_2 , V_149 , 0x50 | ( 1 << 8 ) ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_1 V_12 ;
V_12 = F_7 ( V_2 , V_116 ) ;
F_8 ( V_2 , V_116 ,
V_12 & ( ~ V_122 ) ) ;
return 0 ;
}
static struct V_150 * F_34 ( struct V_151 * V_43 )
{
struct V_4 * V_4 = F_29 ( V_43 ) ;
return V_4 -> V_150 ;
}
static int F_35 ( struct V_152 * V_153 )
{
return F_36 ( & V_153 -> V_43 , & V_154 ,
& V_155 , 1 ) ;
}
static int F_37 ( struct V_152 * V_153 )
{
F_38 ( & V_153 -> V_43 ) ;
return 0 ;
}
