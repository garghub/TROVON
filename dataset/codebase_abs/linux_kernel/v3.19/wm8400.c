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
struct V_9 * V_10 =
(struct V_9 * ) V_6 -> V_11 ;
T_2 V_18 = V_10 -> V_19 ;
int V_13 = 0 ;
T_1 V_12 ;
switch ( V_18 ) {
case V_20 | ( V_21 << 8 ) :
V_12 = F_7 ( V_16 -> V_2 , V_22 ) ;
if ( V_12 & V_23 ) {
F_10 ( V_24
L_1 ) ;
V_13 = - 1 ;
}
break;
case V_20 | ( V_25 << 8 ) :
V_12 = F_7 ( V_16 -> V_2 , V_26 ) ;
if ( V_12 & V_27 ) {
F_10 ( V_24
L_2 ) ;
V_13 = - 1 ;
}
break;
case V_22 | ( V_23 << 8 ) :
V_12 = F_7 ( V_16 -> V_2 , V_20 ) ;
if ( V_12 & V_21 ) {
F_10 ( V_24
L_3 ) ;
V_13 = - 1 ;
}
break;
case V_26 | ( V_27 << 8 ) :
V_12 = F_7 ( V_16 -> V_2 , V_20 ) ;
if ( V_12 & V_25 ) {
F_10 ( V_24
L_4 ) ;
V_13 = - 1 ;
}
break;
}
return V_13 ;
}
static int F_11 ( struct V_28 * V_29 ,
int V_30 , unsigned int V_31 , int V_32 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_33 = V_31 ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , struct F_12 * V_34 ,
unsigned int V_35 , unsigned int V_36 )
{
T_3 V_37 ;
unsigned int V_38 , V_39 , V_40 ;
V_34 -> V_41 = 2 ;
while ( V_36 * V_34 -> V_41 < 90000000 ||
V_36 * V_34 -> V_41 > 100000000 ) {
V_34 -> V_41 *= 2 ;
if ( V_34 -> V_41 > 32 ) {
F_13 ( V_4 -> V_4 -> V_42 ,
L_5 ,
V_36 ) ;
return - V_43 ;
}
}
V_40 = V_36 * V_34 -> V_41 ;
V_34 -> V_41 = V_34 -> V_41 >> 2 ;
if ( V_35 < 48000 )
V_34 -> V_44 = 1 ;
else
V_34 -> V_44 = 0 ;
if ( V_35 < 1000000 )
V_34 -> V_45 = 9 ;
else
V_34 -> V_45 = 0 ;
do {
if ( V_35 < 1000000 )
V_34 -> V_45 -- ;
else
V_34 -> V_45 ++ ;
if ( V_34 -> V_45 < 1 || V_34 -> V_45 > 8 ) {
F_13 ( V_4 -> V_4 -> V_42 ,
L_6 ) ;
return - V_43 ;
}
V_34 -> V_46 = V_40 / ( V_35 * V_34 -> V_45 ) ;
V_39 = V_40 % ( V_35 * V_34 -> V_45 ) ;
} while ( V_39 == 0 );
V_37 = V_47 * ( long long ) V_39 ;
F_14 ( V_37 , ( V_35 * V_34 -> V_45 ) ) ;
V_38 = V_37 & 0xFFFFFFFF ;
if ( ( V_38 % 10 ) >= 5 )
V_38 += 5 ;
V_34 -> V_48 = V_38 / 10 ;
F_15 ( V_4 -> V_4 -> V_42 ,
L_7 ,
V_35 , V_36 ,
V_34 -> V_46 , V_34 -> V_48 , V_34 -> V_45 , V_34 -> V_41 ) ;
return 0 ;
}
static int F_16 ( struct V_28 * V_29 , int V_49 ,
int V_50 , unsigned int V_51 ,
unsigned int V_52 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct F_12 V_34 ;
int V_13 ;
T_1 V_12 ;
if ( V_51 == V_4 -> V_53 && V_52 == V_4 -> V_54 )
return 0 ;
if ( V_52 ) {
V_13 = F_12 ( V_4 , & V_34 , V_51 , V_52 ) ;
if ( V_13 != 0 )
return V_13 ;
} else {
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
}
V_4 -> V_54 = V_52 ;
V_4 -> V_53 = V_51 ;
V_12 = F_7 ( V_2 , V_55 ) ;
V_12 &= ~ V_56 ;
F_8 ( V_2 , V_55 , V_12 ) ;
V_12 = F_7 ( V_2 , V_57 ) ;
V_12 &= ~ V_58 ;
F_8 ( V_2 , V_57 , V_12 ) ;
if ( ! V_52 )
return 0 ;
V_12 &= ~ ( V_59 | V_60 ) ;
V_12 |= V_61 | V_34 . V_45 ;
V_12 |= V_34 . V_44 << V_62 ;
F_8 ( V_2 , V_57 , V_12 ) ;
F_8 ( V_2 , V_63 , V_34 . V_48 ) ;
F_8 ( V_2 , V_64 , V_34 . V_46 ) ;
V_12 = F_7 ( V_2 , V_65 ) ;
V_12 &= ~ V_66 ;
V_12 |= V_34 . V_41 ;
F_8 ( V_2 , V_65 , V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_28 * V_29 ,
unsigned int V_67 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
T_1 V_68 , V_69 ;
V_68 = F_7 ( V_2 , V_70 ) ;
V_69 = F_7 ( V_2 , V_71 ) ;
switch ( V_67 & V_72 ) {
case V_73 :
V_69 &= ~ V_74 ;
break;
case V_75 :
V_69 |= V_74 ;
break;
default:
return - V_43 ;
}
V_68 &= ~ V_76 ;
switch ( V_67 & V_77 ) {
case V_78 :
V_68 |= V_79 ;
V_68 &= ~ V_80 ;
break;
case V_81 :
V_68 |= V_82 ;
V_68 &= ~ V_80 ;
break;
case V_83 :
V_68 |= V_84 ;
V_68 &= ~ V_80 ;
break;
case V_85 :
V_68 |= V_86 ;
V_68 &= ~ V_80 ;
break;
case V_87 :
V_68 |= V_86 | V_80 ;
break;
default:
return - V_43 ;
}
F_8 ( V_2 , V_70 , V_68 ) ;
F_8 ( V_2 , V_71 , V_69 ) ;
return 0 ;
}
static int F_18 ( struct V_28 * V_29 ,
int V_88 , int div )
{
struct V_1 * V_2 = V_29 -> V_2 ;
T_1 V_12 ;
switch ( V_88 ) {
case V_89 :
V_12 = F_7 ( V_2 , V_90 ) &
~ V_91 ;
F_8 ( V_2 , V_90 , V_12 | div ) ;
break;
case V_92 :
V_12 = F_7 ( V_2 , V_90 ) &
~ V_93 ;
F_8 ( V_2 , V_90 , V_12 | div ) ;
break;
case V_94 :
V_12 = F_7 ( V_2 , V_90 ) &
~ V_95 ;
F_8 ( V_2 , V_90 , V_12 | div ) ;
break;
case V_96 :
V_12 = F_7 ( V_2 , V_97 ) &
~ V_98 ;
F_8 ( V_2 , V_97 , V_12 | div ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_19 ( struct V_99 * V_100 ,
struct V_101 * V_102 ,
struct V_28 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_2 ;
T_1 V_68 = F_7 ( V_2 , V_70 ) ;
V_68 &= ~ V_104 ;
switch ( F_20 ( V_102 ) ) {
case 16 :
break;
case 20 :
V_68 |= V_105 ;
break;
case 24 :
V_68 |= V_106 ;
break;
case 32 :
V_68 |= V_107 ;
break;
}
F_8 ( V_2 , V_70 , V_68 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_103 , int V_108 )
{
struct V_1 * V_2 = V_103 -> V_2 ;
T_1 V_14 = F_7 ( V_2 , V_109 ) & ~ V_110 ;
if ( V_108 )
F_8 ( V_2 , V_109 , V_14 | V_110 ) ;
else
F_8 ( V_2 , V_109 , V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
enum V_111 V_112 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_14 ;
int V_13 ;
switch ( V_112 ) {
case V_113 :
break;
case V_114 :
V_14 = F_7 ( V_2 , V_115 ) &
~ V_116 ;
F_8 ( V_2 , V_115 , V_14 | 0x2 ) ;
break;
case V_117 :
if ( V_2 -> V_118 . V_119 == V_120 ) {
V_13 = F_23 ( F_24 ( V_121 ) ,
& V_121 [ 0 ] ) ;
if ( V_13 != 0 ) {
F_13 ( V_4 -> V_4 -> V_42 ,
L_8 ,
V_13 ) ;
return V_13 ;
}
F_8 ( V_2 , V_115 ,
V_122 | V_123 ) ;
F_8 ( V_2 , V_124 , V_125 |
V_126 | V_127 ) ;
F_25 ( 50 ) ;
V_14 = F_7 ( V_2 , V_115 ) ;
V_14 |= 0x2 | V_128 ;
F_8 ( V_2 , V_115 , V_14 ) ;
F_8 ( V_2 , V_124 , V_125 |
V_126 | V_127 |
V_129 ) ;
F_8 ( V_2 , V_124 , V_129 ) ;
}
V_14 = F_7 ( V_2 , V_115 ) &
~ V_116 ;
F_8 ( V_2 , V_115 , V_14 | 0x4 ) ;
break;
case V_120 :
F_8 ( V_2 , V_124 , V_125 |
V_127 | V_129 ) ;
F_8 ( V_2 , V_124 , V_125 |
V_126 | V_127 |
V_129 ) ;
V_14 = F_7 ( V_2 , V_109 ) ;
F_8 ( V_2 , V_109 , V_14 | V_110 ) ;
V_14 = F_7 ( V_2 , V_115 ) ;
V_14 |= V_130 | V_131 |
V_132 | V_133 |
V_134 ;
F_8 ( V_2 , V_115 , V_14 ) ;
V_14 &= ~ V_116 ;
F_8 ( V_2 , V_115 , V_14 ) ;
F_25 ( 300 ) ;
F_8 ( V_2 , V_135 , V_136 |
V_137 | V_138 |
V_139 | V_140 |
V_141 ) ;
V_14 &= ~ V_128 ;
F_8 ( V_2 , V_115 , V_14 ) ;
F_8 ( V_2 , V_124 , 0x0 ) ;
V_13 = F_26 ( F_24 ( V_121 ) ,
& V_121 [ 0 ] ) ;
if ( V_13 != 0 )
return V_13 ;
break;
}
V_2 -> V_118 . V_119 = V_112 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_28 ( V_2 -> V_42 ) ;
struct V_3 * V_142 ;
int V_13 ;
T_1 V_12 ;
V_142 = F_29 ( V_2 -> V_42 , sizeof( struct V_3 ) ,
V_143 ) ;
if ( V_142 == NULL )
return - V_144 ;
F_30 ( V_2 , V_142 ) ;
V_142 -> V_4 = V_4 ;
V_13 = F_31 ( V_4 -> V_42 ,
F_24 ( V_121 ) , & V_121 [ 0 ] ) ;
if ( V_13 != 0 ) {
F_13 ( V_2 -> V_42 , L_9 , V_13 ) ;
return V_13 ;
}
F_1 ( V_2 ) ;
V_12 = F_7 ( V_2 , V_115 ) ;
F_8 ( V_2 , V_115 , V_12 | V_122 ) ;
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
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_12 ;
V_12 = F_7 ( V_2 , V_115 ) ;
F_8 ( V_2 , V_115 ,
V_12 & ( ~ V_122 ) ) ;
return 0 ;
}
static struct V_150 * F_33 ( struct V_151 * V_42 )
{
struct V_4 * V_4 = F_28 ( V_42 ) ;
return V_4 -> V_150 ;
}
static int F_34 ( struct V_152 * V_153 )
{
return F_35 ( & V_153 -> V_42 , & V_154 ,
& V_155 , 1 ) ;
}
static int F_36 ( struct V_152 * V_153 )
{
F_37 ( & V_153 -> V_42 ) ;
return 0 ;
}
