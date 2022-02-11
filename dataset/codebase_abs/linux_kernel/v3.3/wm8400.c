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
V_17 = F_1 ( V_2 , V_3 ) ;
return F_4 ( V_2 , V_3 , V_17 | 0x0100 ) ;
}
static int F_11 ( struct V_18 * V_19 ,
struct V_9 * V_10 , int V_20 )
{
T_1 V_3 , V_21 ;
V_3 = F_1 ( V_19 -> V_2 , V_22 ) ;
V_21 = F_1 ( V_19 -> V_2 , V_6 ) ;
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
F_4 ( V_19 -> V_2 , V_22 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 ,
struct V_9 * V_10 , int V_20 )
{
struct V_13 * V_14 =
(struct V_13 * ) V_10 -> V_15 ;
T_2 V_29 = V_14 -> V_30 ;
int V_16 = 0 ;
T_1 V_3 ;
switch ( V_29 ) {
case V_31 | ( V_32 << 8 ) :
V_3 = F_1 ( V_19 -> V_2 , V_33 ) ;
if ( V_3 & V_34 ) {
F_13 ( V_35
L_1 ) ;
V_16 = - 1 ;
}
break;
case V_31 | ( V_36 << 8 ) :
V_3 = F_1 ( V_19 -> V_2 , V_37 ) ;
if ( V_3 & V_38 ) {
F_13 ( V_35
L_2 ) ;
V_16 = - 1 ;
}
break;
case V_33 | ( V_34 << 8 ) :
V_3 = F_1 ( V_19 -> V_2 , V_31 ) ;
if ( V_3 & V_32 ) {
F_13 ( V_35
L_3 ) ;
V_16 = - 1 ;
}
break;
case V_37 | ( V_38 << 8 ) :
V_3 = F_1 ( V_19 -> V_2 , V_31 ) ;
if ( V_3 & V_36 ) {
F_13 ( V_35
L_4 ) ;
V_16 = - 1 ;
}
break;
}
return V_16 ;
}
static int F_14 ( struct V_39 * V_40 ,
int V_41 , unsigned int V_42 , int V_43 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_44 = V_42 ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , struct F_15 * V_45 ,
unsigned int V_46 , unsigned int V_47 )
{
T_3 V_48 ;
unsigned int V_49 , V_50 , V_51 ;
V_45 -> V_52 = 2 ;
while ( V_47 * V_45 -> V_52 < 90000000 ||
V_47 * V_45 -> V_52 > 100000000 ) {
V_45 -> V_52 *= 2 ;
if ( V_45 -> V_52 > 32 ) {
F_16 ( V_5 -> V_5 -> V_53 ,
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
F_16 ( V_5 -> V_5 -> V_53 ,
L_6 ) ;
return - V_54 ;
}
V_45 -> V_57 = V_51 / ( V_46 * V_45 -> V_56 ) ;
V_50 = V_51 % ( V_46 * V_45 -> V_56 ) ;
} while ( V_50 == 0 );
V_48 = V_58 * ( long long ) V_50 ;
F_17 ( V_48 , ( V_46 * V_45 -> V_56 ) ) ;
V_49 = V_48 & 0xFFFFFFFF ;
if ( ( V_49 % 10 ) >= 5 )
V_49 += 5 ;
V_45 -> V_59 = V_49 / 10 ;
F_18 ( V_5 -> V_5 -> V_53 ,
L_7 ,
V_46 , V_47 ,
V_45 -> V_57 , V_45 -> V_59 , V_45 -> V_56 , V_45 -> V_52 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_40 , int V_60 ,
int V_61 , unsigned int V_62 ,
unsigned int V_63 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct F_15 V_45 ;
int V_16 ;
T_1 V_3 ;
if ( V_62 == V_5 -> V_64 && V_63 == V_5 -> V_65 )
return 0 ;
if ( V_63 ) {
V_16 = F_15 ( V_5 , & V_45 , V_62 , V_63 ) ;
if ( V_16 != 0 )
return V_16 ;
} else {
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
}
V_5 -> V_65 = V_63 ;
V_5 -> V_64 = V_62 ;
V_3 = F_1 ( V_2 , V_22 ) ;
V_3 &= ~ V_66 ;
F_4 ( V_2 , V_22 , V_3 ) ;
V_3 = F_1 ( V_2 , V_67 ) ;
V_3 &= ~ V_68 ;
F_4 ( V_2 , V_67 , V_3 ) ;
if ( ! V_63 )
return 0 ;
V_3 &= ~ ( V_69 | V_70 ) ;
V_3 |= V_71 | V_45 . V_56 ;
V_3 |= V_45 . V_55 << V_72 ;
F_4 ( V_2 , V_67 , V_3 ) ;
F_4 ( V_2 , V_73 , V_45 . V_59 ) ;
F_4 ( V_2 , V_74 , V_45 . V_57 ) ;
V_3 = F_1 ( V_2 , V_75 ) ;
V_3 &= ~ V_76 ;
V_3 |= V_45 . V_52 ;
F_4 ( V_2 , V_75 , V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_39 * V_40 ,
unsigned int V_77 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_78 , V_79 ;
V_78 = F_1 ( V_2 , V_80 ) ;
V_79 = F_1 ( V_2 , V_81 ) ;
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
F_4 ( V_2 , V_80 , V_78 ) ;
F_4 ( V_2 , V_81 , V_79 ) ;
return 0 ;
}
static int F_21 ( struct V_39 * V_40 ,
int V_98 , int div )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_3 ;
switch ( V_98 ) {
case V_99 :
V_3 = F_1 ( V_2 , V_100 ) &
~ V_101 ;
F_4 ( V_2 , V_100 , V_3 | div ) ;
break;
case V_102 :
V_3 = F_1 ( V_2 , V_100 ) &
~ V_103 ;
F_4 ( V_2 , V_100 , V_3 | div ) ;
break;
case V_104 :
V_3 = F_1 ( V_2 , V_100 ) &
~ V_105 ;
F_4 ( V_2 , V_100 , V_3 | div ) ;
break;
case V_106 :
V_3 = F_1 ( V_2 , V_107 ) &
~ V_108 ;
F_4 ( V_2 , V_107 , V_3 | div ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_22 ( struct V_109 * V_110 ,
struct V_111 * V_112 ,
struct V_39 * V_113 )
{
struct V_114 * V_115 = V_110 -> V_116 ;
struct V_1 * V_2 = V_115 -> V_2 ;
T_1 V_78 = F_1 ( V_2 , V_80 ) ;
V_78 &= ~ V_117 ;
switch ( F_23 ( V_112 ) ) {
case V_118 :
break;
case V_119 :
V_78 |= V_120 ;
break;
case V_121 :
V_78 |= V_122 ;
break;
case V_123 :
V_78 |= V_124 ;
break;
}
F_4 ( V_2 , V_80 , V_78 ) ;
return 0 ;
}
static int F_24 ( struct V_39 * V_113 , int V_125 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
T_1 V_17 = F_1 ( V_2 , V_126 ) & ~ V_127 ;
if ( V_125 )
F_4 ( V_2 , V_126 , V_17 | V_127 ) ;
else
F_4 ( V_2 , V_126 , V_17 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_128 V_129 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_17 ;
int V_16 ;
switch ( V_129 ) {
case V_130 :
break;
case V_131 :
V_17 = F_1 ( V_2 , V_132 ) &
~ V_133 ;
F_4 ( V_2 , V_132 , V_17 | 0x2 ) ;
break;
case V_134 :
if ( V_2 -> V_135 . V_136 == V_137 ) {
V_16 = F_26 ( F_27 ( V_138 ) ,
& V_138 [ 0 ] ) ;
if ( V_16 != 0 ) {
F_16 ( V_5 -> V_5 -> V_53 ,
L_8 ,
V_16 ) ;
return V_16 ;
}
F_4 ( V_2 , V_132 ,
V_139 | V_140 ) ;
F_4 ( V_2 , V_141 , V_142 |
V_143 | V_144 ) ;
F_28 ( 50 ) ;
V_17 = F_1 ( V_2 , V_132 ) ;
V_17 |= 0x2 | V_145 ;
F_4 ( V_2 , V_132 , V_17 ) ;
F_4 ( V_2 , V_141 , V_142 |
V_143 | V_144 |
V_146 ) ;
F_4 ( V_2 , V_141 , V_146 ) ;
}
V_17 = F_1 ( V_2 , V_132 ) &
~ V_133 ;
F_4 ( V_2 , V_132 , V_17 | 0x4 ) ;
break;
case V_137 :
F_4 ( V_2 , V_141 , V_142 |
V_144 | V_146 ) ;
F_4 ( V_2 , V_141 , V_142 |
V_143 | V_144 |
V_146 ) ;
V_17 = F_1 ( V_2 , V_126 ) ;
F_4 ( V_2 , V_126 , V_17 | V_127 ) ;
V_17 = F_1 ( V_2 , V_132 ) ;
V_17 |= V_147 | V_148 |
V_149 | V_150 |
V_151 ;
F_4 ( V_2 , V_132 , V_17 ) ;
V_17 &= ~ V_133 ;
F_4 ( V_2 , V_132 , V_17 ) ;
F_28 ( 300 ) ;
F_4 ( V_2 , V_152 , V_153 |
V_154 | V_155 |
V_156 | V_157 |
V_158 ) ;
V_17 &= ~ V_145 ;
F_4 ( V_2 , V_132 , V_17 ) ;
F_4 ( V_2 , V_141 , 0x0 ) ;
V_16 = F_29 ( F_27 ( V_138 ) ,
& V_138 [ 0 ] ) ;
if ( V_16 != 0 )
return V_16 ;
break;
}
V_2 -> V_135 . V_136 = V_129 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_137 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_134 ) ;
return 0 ;
}
static void F_32 ( struct V_159 * V_160 )
{
struct V_4 * V_161 = F_33 ( V_160 , struct V_4 ,
V_160 ) ;
struct V_1 * V_2 = V_161 -> V_2 ;
F_25 ( V_2 , V_134 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_35 ( V_2 -> V_53 ) ;
struct V_4 * V_161 ;
int V_16 ;
T_1 V_3 ;
V_161 = F_36 ( V_2 -> V_53 , sizeof( struct V_4 ) ,
V_162 ) ;
if ( V_161 == NULL )
return - V_163 ;
F_37 ( V_2 , V_161 ) ;
V_2 -> V_164 = V_161 -> V_5 = V_5 ;
V_161 -> V_2 = V_2 ;
V_16 = F_38 ( V_5 -> V_53 ,
F_27 ( V_138 ) , & V_138 [ 0 ] ) ;
if ( V_16 != 0 ) {
F_16 ( V_2 -> V_53 , L_9 , V_16 ) ;
return V_16 ;
}
F_39 ( & V_161 -> V_160 , F_32 ) ;
F_6 ( V_2 ) ;
V_3 = F_1 ( V_2 , V_132 ) ;
F_4 ( V_2 , V_132 , V_3 | V_139 ) ;
V_3 = F_1 ( V_2 , V_165 ) ;
F_4 ( V_2 , V_165 ,
V_3 & V_166 ) ;
V_3 = F_1 ( V_2 , V_167 ) ;
F_4 ( V_2 , V_167 ,
V_3 & V_166 ) ;
F_4 ( V_2 , V_168 , 0x50 | ( 1 << 8 ) ) ;
F_4 ( V_2 , V_169 , 0x50 | ( 1 << 8 ) ) ;
if ( ! F_40 ( & V_161 -> V_160 ) ) {
V_16 = - V_54 ;
goto V_170;
}
return 0 ;
V_170:
F_41 ( F_27 ( V_138 ) , V_138 ) ;
return V_16 ;
}
static int F_42 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_132 ) ;
F_4 ( V_2 , V_132 ,
V_3 & ( ~ V_139 ) ) ;
F_41 ( F_27 ( V_138 ) , V_138 ) ;
return 0 ;
}
static int T_4 F_43 ( struct V_171 * V_172 )
{
return F_44 ( & V_172 -> V_53 , & V_173 ,
& V_174 , 1 ) ;
}
static int T_5 F_45 ( struct V_171 * V_172 )
{
F_46 ( & V_172 -> V_53 ) ;
return 0 ;
}
