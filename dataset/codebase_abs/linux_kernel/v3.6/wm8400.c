static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 == V_6 )
return V_5 -> V_7 ;
else
return F_3 ( V_5 -> V_5 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 == V_6 ) {
V_5 -> V_7 = V_8 ;
return 0 ;
} else
return F_5 ( V_5 -> V_5 , V_3 , 0xffff , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_7 ( V_5 -> V_5 ) ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
struct V_13 * V_14 =
(struct V_13 * ) V_10 -> V_15 ;
int V_3 = V_14 -> V_3 ;
int V_16 ;
T_1 V_17 ;
V_16 = F_10 ( V_10 , V_12 ) ;
if ( V_16 < 0 )
return V_16 ;
V_17 = F_11 ( V_2 , V_3 ) ;
return F_12 ( V_2 , V_3 , V_17 | 0x0100 ) ;
}
static int F_13 ( struct V_18 * V_19 ,
struct V_9 * V_10 , int V_20 )
{
T_1 V_3 , V_21 ;
V_3 = F_11 ( V_19 -> V_2 , V_22 ) ;
V_21 = F_11 ( V_19 -> V_2 , V_6 ) ;
if ( V_21 & ( ( 1 << V_23 ) |
( 1 << V_24 ) ) ) {
V_3 |= V_25 ;
} else {
V_3 &= ~ V_25 ;
}
if ( V_21 & ( ( 1 << V_26 ) |
( 1 << V_27 ) ) ) {
V_3 |= V_28 ;
} else {
V_3 &= ~ V_28 ;
}
F_12 ( V_19 -> V_2 , V_22 , V_3 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_19 ,
struct V_9 * V_10 , int V_20 )
{
struct V_13 * V_14 =
(struct V_13 * ) V_10 -> V_15 ;
T_2 V_29 = V_14 -> V_30 ;
int V_16 = 0 ;
T_1 V_3 ;
switch ( V_29 ) {
case V_31 | ( V_32 << 8 ) :
V_3 = F_11 ( V_19 -> V_2 , V_33 ) ;
if ( V_3 & V_34 ) {
F_15 ( V_35
L_1 ) ;
V_16 = - 1 ;
}
break;
case V_31 | ( V_36 << 8 ) :
V_3 = F_11 ( V_19 -> V_2 , V_37 ) ;
if ( V_3 & V_38 ) {
F_15 ( V_35
L_2 ) ;
V_16 = - 1 ;
}
break;
case V_33 | ( V_34 << 8 ) :
V_3 = F_11 ( V_19 -> V_2 , V_31 ) ;
if ( V_3 & V_32 ) {
F_15 ( V_35
L_3 ) ;
V_16 = - 1 ;
}
break;
case V_37 | ( V_38 << 8 ) :
V_3 = F_11 ( V_19 -> V_2 , V_31 ) ;
if ( V_3 & V_36 ) {
F_15 ( V_35
L_4 ) ;
V_16 = - 1 ;
}
break;
}
return V_16 ;
}
static int F_16 ( struct V_39 * V_40 ,
int V_41 , unsigned int V_42 , int V_43 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_44 = V_42 ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 , struct F_17 * V_45 ,
unsigned int V_46 , unsigned int V_47 )
{
T_3 V_48 ;
unsigned int V_49 , V_50 , V_51 ;
V_45 -> V_52 = 2 ;
while ( V_47 * V_45 -> V_52 < 90000000 ||
V_47 * V_45 -> V_52 > 100000000 ) {
V_45 -> V_52 *= 2 ;
if ( V_45 -> V_52 > 32 ) {
F_18 ( V_5 -> V_5 -> V_53 ,
L_5 ,
V_47 ) ;
return - V_54 ;
}
}
V_51 = V_47 * V_45 -> V_52 ;
V_45 -> V_52 = V_45 -> V_52 >> 2 ;
if ( V_46 < 48000 )
V_45 -> V_55 = 1 ;
else
V_45 -> V_55 = 0 ;
if ( V_46 < 1000000 )
V_45 -> V_56 = 9 ;
else
V_45 -> V_56 = 0 ;
do {
if ( V_46 < 1000000 )
V_45 -> V_56 -- ;
else
V_45 -> V_56 ++ ;
if ( V_45 -> V_56 < 1 || V_45 -> V_56 > 8 ) {
F_18 ( V_5 -> V_5 -> V_53 ,
L_6 ) ;
return - V_54 ;
}
V_45 -> V_57 = V_51 / ( V_46 * V_45 -> V_56 ) ;
V_50 = V_51 % ( V_46 * V_45 -> V_56 ) ;
} while ( V_50 == 0 );
V_48 = V_58 * ( long long ) V_50 ;
F_19 ( V_48 , ( V_46 * V_45 -> V_56 ) ) ;
V_49 = V_48 & 0xFFFFFFFF ;
if ( ( V_49 % 10 ) >= 5 )
V_49 += 5 ;
V_45 -> V_59 = V_49 / 10 ;
F_20 ( V_5 -> V_5 -> V_53 ,
L_7 ,
V_46 , V_47 ,
V_45 -> V_57 , V_45 -> V_59 , V_45 -> V_56 , V_45 -> V_52 ) ;
return 0 ;
}
static int F_21 ( struct V_39 * V_40 , int V_60 ,
int V_61 , unsigned int V_62 ,
unsigned int V_63 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct F_17 V_45 ;
int V_16 ;
T_1 V_3 ;
if ( V_62 == V_5 -> V_64 && V_63 == V_5 -> V_65 )
return 0 ;
if ( V_63 ) {
V_16 = F_17 ( V_5 , & V_45 , V_62 , V_63 ) ;
if ( V_16 != 0 )
return V_16 ;
} else {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
}
V_5 -> V_65 = V_63 ;
V_5 -> V_64 = V_62 ;
V_3 = F_11 ( V_2 , V_22 ) ;
V_3 &= ~ V_66 ;
F_12 ( V_2 , V_22 , V_3 ) ;
V_3 = F_11 ( V_2 , V_67 ) ;
V_3 &= ~ V_68 ;
F_12 ( V_2 , V_67 , V_3 ) ;
if ( ! V_63 )
return 0 ;
V_3 &= ~ ( V_69 | V_70 ) ;
V_3 |= V_71 | V_45 . V_56 ;
V_3 |= V_45 . V_55 << V_72 ;
F_12 ( V_2 , V_67 , V_3 ) ;
F_12 ( V_2 , V_73 , V_45 . V_59 ) ;
F_12 ( V_2 , V_74 , V_45 . V_57 ) ;
V_3 = F_11 ( V_2 , V_75 ) ;
V_3 &= ~ V_76 ;
V_3 |= V_45 . V_52 ;
F_12 ( V_2 , V_75 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_39 * V_40 ,
unsigned int V_77 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_78 , V_79 ;
V_78 = F_11 ( V_2 , V_80 ) ;
V_79 = F_11 ( V_2 , V_81 ) ;
switch ( V_77 & V_82 ) {
case V_83 :
V_79 &= ~ V_84 ;
break;
case V_85 :
V_79 |= V_84 ;
break;
default:
return - V_54 ;
}
V_78 &= ~ V_86 ;
switch ( V_77 & V_87 ) {
case V_88 :
V_78 |= V_89 ;
V_78 &= ~ V_90 ;
break;
case V_91 :
V_78 |= V_92 ;
V_78 &= ~ V_90 ;
break;
case V_93 :
V_78 |= V_94 ;
V_78 &= ~ V_90 ;
break;
case V_95 :
V_78 |= V_96 ;
V_78 &= ~ V_90 ;
break;
case V_97 :
V_78 |= V_96 | V_90 ;
break;
default:
return - V_54 ;
}
F_12 ( V_2 , V_80 , V_78 ) ;
F_12 ( V_2 , V_81 , V_79 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_40 ,
int V_98 , int div )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_3 ;
switch ( V_98 ) {
case V_99 :
V_3 = F_11 ( V_2 , V_100 ) &
~ V_101 ;
F_12 ( V_2 , V_100 , V_3 | div ) ;
break;
case V_102 :
V_3 = F_11 ( V_2 , V_100 ) &
~ V_103 ;
F_12 ( V_2 , V_100 , V_3 | div ) ;
break;
case V_104 :
V_3 = F_11 ( V_2 , V_100 ) &
~ V_105 ;
F_12 ( V_2 , V_100 , V_3 | div ) ;
break;
case V_106 :
V_3 = F_11 ( V_2 , V_107 ) &
~ V_108 ;
F_12 ( V_2 , V_107 , V_3 | div ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_24 ( struct V_109 * V_110 ,
struct V_111 * V_112 ,
struct V_39 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
T_1 V_78 = F_11 ( V_2 , V_80 ) ;
V_78 &= ~ V_114 ;
switch ( F_25 ( V_112 ) ) {
case V_115 :
break;
case V_116 :
V_78 |= V_117 ;
break;
case V_118 :
V_78 |= V_119 ;
break;
case V_120 :
V_78 |= V_121 ;
break;
}
F_12 ( V_2 , V_80 , V_78 ) ;
return 0 ;
}
static int F_26 ( struct V_39 * V_113 , int V_122 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
T_1 V_17 = F_11 ( V_2 , V_123 ) & ~ V_124 ;
if ( V_122 )
F_12 ( V_2 , V_123 , V_17 | V_124 ) ;
else
F_12 ( V_2 , V_123 , V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
enum V_125 V_126 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_17 ;
int V_16 ;
switch ( V_126 ) {
case V_127 :
break;
case V_128 :
V_17 = F_11 ( V_2 , V_129 ) &
~ V_130 ;
F_12 ( V_2 , V_129 , V_17 | 0x2 ) ;
break;
case V_131 :
if ( V_2 -> V_132 . V_133 == V_134 ) {
V_16 = F_28 ( F_29 ( V_135 ) ,
& V_135 [ 0 ] ) ;
if ( V_16 != 0 ) {
F_18 ( V_5 -> V_5 -> V_53 ,
L_8 ,
V_16 ) ;
return V_16 ;
}
F_12 ( V_2 , V_129 ,
V_136 | V_137 ) ;
F_12 ( V_2 , V_138 , V_139 |
V_140 | V_141 ) ;
F_30 ( 50 ) ;
V_17 = F_11 ( V_2 , V_129 ) ;
V_17 |= 0x2 | V_142 ;
F_12 ( V_2 , V_129 , V_17 ) ;
F_12 ( V_2 , V_138 , V_139 |
V_140 | V_141 |
V_143 ) ;
F_12 ( V_2 , V_138 , V_143 ) ;
}
V_17 = F_11 ( V_2 , V_129 ) &
~ V_130 ;
F_12 ( V_2 , V_129 , V_17 | 0x4 ) ;
break;
case V_134 :
F_12 ( V_2 , V_138 , V_139 |
V_141 | V_143 ) ;
F_12 ( V_2 , V_138 , V_139 |
V_140 | V_141 |
V_143 ) ;
V_17 = F_11 ( V_2 , V_123 ) ;
F_12 ( V_2 , V_123 , V_17 | V_124 ) ;
V_17 = F_11 ( V_2 , V_129 ) ;
V_17 |= V_144 | V_145 |
V_146 | V_147 |
V_148 ;
F_12 ( V_2 , V_129 , V_17 ) ;
V_17 &= ~ V_130 ;
F_12 ( V_2 , V_129 , V_17 ) ;
F_30 ( 300 ) ;
F_12 ( V_2 , V_149 , V_150 |
V_151 | V_152 |
V_153 | V_154 |
V_155 ) ;
V_17 &= ~ V_142 ;
F_12 ( V_2 , V_129 , V_17 ) ;
F_12 ( V_2 , V_138 , 0x0 ) ;
V_16 = F_31 ( F_29 ( V_135 ) ,
& V_135 [ 0 ] ) ;
if ( V_16 != 0 )
return V_16 ;
break;
}
V_2 -> V_132 . V_133 = V_126 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_134 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_131 ) ;
return 0 ;
}
static void F_34 ( struct V_156 * V_157 )
{
struct V_4 * V_158 = F_35 ( V_157 , struct V_4 ,
V_157 ) ;
struct V_1 * V_2 = V_158 -> V_2 ;
F_27 ( V_2 , V_131 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_37 ( V_2 -> V_53 ) ;
struct V_4 * V_158 ;
int V_16 ;
T_1 V_3 ;
V_158 = F_38 ( V_2 -> V_53 , sizeof( struct V_4 ) ,
V_159 ) ;
if ( V_158 == NULL )
return - V_160 ;
F_39 ( V_2 , V_158 ) ;
V_2 -> V_161 = V_158 -> V_5 = V_5 ;
V_158 -> V_2 = V_2 ;
V_16 = F_40 ( V_5 -> V_53 ,
F_29 ( V_135 ) , & V_135 [ 0 ] ) ;
if ( V_16 != 0 ) {
F_18 ( V_2 -> V_53 , L_9 , V_16 ) ;
return V_16 ;
}
F_41 ( & V_158 -> V_157 , F_34 ) ;
F_6 ( V_2 ) ;
V_3 = F_11 ( V_2 , V_129 ) ;
F_12 ( V_2 , V_129 , V_3 | V_136 ) ;
V_3 = F_11 ( V_2 , V_162 ) ;
F_12 ( V_2 , V_162 ,
V_3 & V_163 ) ;
V_3 = F_11 ( V_2 , V_164 ) ;
F_12 ( V_2 , V_164 ,
V_3 & V_163 ) ;
F_12 ( V_2 , V_165 , 0x50 | ( 1 << 8 ) ) ;
F_12 ( V_2 , V_166 , 0x50 | ( 1 << 8 ) ) ;
if ( ! F_42 ( & V_158 -> V_157 ) ) {
V_16 = - V_54 ;
goto V_167;
}
return 0 ;
V_167:
F_43 ( F_29 ( V_135 ) , V_135 ) ;
return V_16 ;
}
static int F_44 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_11 ( V_2 , V_129 ) ;
F_12 ( V_2 , V_129 ,
V_3 & ( ~ V_136 ) ) ;
F_43 ( F_29 ( V_135 ) , V_135 ) ;
return 0 ;
}
static int T_4 F_45 ( struct V_168 * V_169 )
{
return F_46 ( & V_169 -> V_53 , & V_170 ,
& V_171 , 1 ) ;
}
static int T_5 F_47 ( struct V_168 * V_169 )
{
F_48 ( & V_169 -> V_53 ) ;
return 0 ;
}
