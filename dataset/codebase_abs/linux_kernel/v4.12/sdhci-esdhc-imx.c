static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_5 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_6 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 -> V_7 & V_8 ) ;
}
static inline void F_5 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 , int V_13 )
{
void T_2 * V_14 = V_10 -> V_15 + ( V_13 & ~ 0x3 ) ;
T_1 V_16 = ( V_13 & 0x3 ) * 8 ;
F_6 ( ( ( F_7 ( V_14 ) & ~ ( V_11 << V_16 ) ) | ( V_12 << V_16 ) ) , V_14 ) ;
}
static T_1 F_8 ( struct V_9 * V_10 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
T_1 V_12 = F_7 ( V_10 -> V_15 + V_13 ) ;
if ( F_11 ( V_13 == V_20 ) ) {
T_1 V_21 = V_12 ;
V_12 = V_21 & 0x000FFFFF ;
V_12 |= ( V_21 & 0x0F000000 ) >> 4 ;
V_12 |= ( V_21 & 0x00800000 ) << 1 ;
}
if ( F_11 ( V_13 == V_22 ) ) {
if ( V_19 -> V_3 -> V_7 & V_23 )
V_12 &= 0xffff0000 ;
if ( V_12 & V_24 ) {
V_12 &= ~ V_24 ;
V_12 |= V_25 ;
}
}
if ( F_11 ( V_13 == V_26 ) ) {
if ( F_4 ( V_19 ) ) {
if ( V_19 -> V_3 -> V_7 & V_23 )
V_12 = F_7 ( V_10 -> V_15 + V_22 ) & 0xFFFF ;
else
V_12 = V_27 | V_28
| V_29
| V_30
| ( V_31 << V_32 ) ;
if ( V_19 -> V_3 -> V_7 & V_33 )
V_12 |= V_34 ;
}
}
if ( F_11 ( V_13 == V_35 ) && F_4 ( V_19 ) ) {
V_12 = 0 ;
V_12 |= 0xFF << V_36 ;
V_12 |= 0xFF << V_37 ;
V_12 |= 0xFF << V_38 ;
}
if ( F_11 ( V_13 == V_39 ) ) {
if ( V_12 & V_40 ) {
V_12 &= ~ V_40 ;
V_12 |= V_41 ;
}
if ( ( V_19 -> V_42 == V_43 ) &&
( ( V_12 & V_44 ) == V_44 ) ) {
V_12 &= ~ V_44 ;
F_6 ( V_44 , V_10 -> V_15 +
V_39 ) ;
V_19 -> V_42 = V_45 ;
}
}
return V_12 ;
}
static void F_12 ( struct V_9 * V_10 , T_1 V_12 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
T_1 V_2 ;
if ( F_11 ( V_13 == V_46 || V_13 == V_47 ||
V_13 == V_39 ) ) {
if ( ( V_12 & V_48 ) && ! F_4 ( V_19 ) ) {
V_2 = F_7 ( V_10 -> V_15 + V_49 ) ;
V_2 &= ~ V_50 ;
F_6 ( V_2 , V_10 -> V_15 + V_49 ) ;
V_2 |= V_50 ;
F_6 ( V_2 , V_10 -> V_15 + V_49 ) ;
}
if ( V_12 & V_41 ) {
V_12 &= ~ V_41 ;
V_12 |= V_40 ;
}
}
if ( F_11 ( ( V_19 -> V_3 -> V_7 & V_51 )
&& ( V_13 == V_39 )
&& ( V_12 & V_52 ) ) ) {
T_1 V_53 ;
V_53 = F_7 ( V_10 -> V_15 + V_54 ) ;
V_53 &= ~ V_55 ;
F_6 ( V_53 , V_10 -> V_15 + V_54 ) ;
if ( V_19 -> V_42 == V_56 )
{
V_2 = V_57 << 24 |
V_58 << 16 ;
F_6 ( V_2 , V_10 -> V_15 + V_59 ) ;
V_19 -> V_42 = V_43 ;
}
}
F_6 ( V_12 , V_10 -> V_15 + V_13 ) ;
}
static T_3 F_13 ( struct V_9 * V_10 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
T_3 V_60 = 0 ;
T_1 V_12 ;
if ( F_11 ( V_13 == V_61 ) ) {
V_13 ^= 2 ;
if ( F_4 ( V_19 ) ) {
return V_62 ;
}
}
if ( F_11 ( V_13 == V_63 ) ) {
V_12 = F_7 ( V_10 -> V_15 + V_54 ) ;
if ( V_12 & V_64 )
V_60 |= V_65 ;
if ( F_4 ( V_19 ) ) {
if ( V_19 -> V_3 -> V_7 & V_66 )
V_12 = F_7 ( V_10 -> V_15 + V_67 ) ;
else if ( V_19 -> V_3 -> V_7 & V_68 )
V_12 = F_7 ( V_10 -> V_15 + V_69 ) ;
}
if ( V_12 & V_70 )
V_60 |= V_71 ;
if ( V_12 & V_72 )
V_60 |= V_73 ;
V_60 &= ~ V_74 ;
return V_60 ;
}
if ( F_11 ( V_13 == V_59 ) ) {
if ( F_4 ( V_19 ) ) {
T_1 V_75 = F_7 ( V_10 -> V_15 + V_67 ) ;
V_60 = V_75 & V_76 ;
if ( V_75 & V_77 ) {
V_60 &= ~ V_77 ;
V_60 |= V_78 ;
}
} else {
V_60 = F_14 ( V_10 -> V_15 + V_59 ) ;
}
return V_60 ;
}
return F_14 ( V_10 -> V_15 + V_13 ) ;
}
static void F_15 ( struct V_9 * V_10 , T_3 V_12 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
T_1 V_79 = 0 ;
switch ( V_13 ) {
case V_80 :
V_79 = F_7 ( V_10 -> V_15 + V_54 ) ;
if ( V_12 & V_81 )
V_79 |= V_82 ;
else
V_79 &= ~ V_82 ;
F_6 ( V_79 , V_10 -> V_15 + V_54 ) ;
return;
case V_63 :
V_79 = F_7 ( V_10 -> V_15 + V_54 ) ;
if ( V_12 & V_65 )
V_79 |= V_64 ;
else
V_79 &= ~ V_64 ;
F_6 ( V_79 , V_10 -> V_15 + V_54 ) ;
if ( V_19 -> V_3 -> V_7 & V_66 ) {
V_79 = F_7 ( V_10 -> V_15 + V_67 ) ;
if ( V_12 & V_73 ) {
V_79 |= V_72 ;
V_79 |= V_83 ;
} else {
V_79 &= ~ V_72 ;
V_79 &= ~ V_83 ;
}
F_6 ( V_79 , V_10 -> V_15 + V_67 ) ;
} else if ( V_19 -> V_3 -> V_7 & V_68 ) {
T_1 V_53 = F_7 ( V_10 -> V_15 + V_69 ) ;
T_1 V_75 = F_7 ( V_10 -> V_15 + V_67 ) ;
if ( V_12 & V_73 ) {
V_53 |= V_72 ;
} else {
V_53 &= ~ V_72 ;
V_75 &= ~ V_84 ;
V_75 &= ~ V_83 ;
}
if ( V_12 & V_71 ) {
V_53 |= V_70 ;
V_75 |= V_84 ;
V_75 |= V_83 ;
} else {
V_53 &= ~ V_70 ;
}
F_6 ( V_53 , V_10 -> V_15 + V_69 ) ;
F_6 ( V_75 , V_10 -> V_15 + V_67 ) ;
}
return;
case V_59 :
if ( ( V_19 -> V_3 -> V_7 & V_51 )
&& ( V_10 -> V_85 -> V_86 == V_87 )
&& ( V_10 -> V_85 -> V_2 -> V_88 > 1 )
&& ( V_10 -> V_85 -> V_2 -> V_7 & V_89 ) ) {
T_1 V_53 ;
V_53 = F_7 ( V_10 -> V_15 + V_54 ) ;
V_53 |= V_55 ;
F_6 ( V_53 , V_10 -> V_15 + V_54 ) ;
}
if ( F_4 ( V_19 ) ) {
T_1 V_75 = F_7 ( V_10 -> V_15 + V_67 ) ;
if ( V_12 & V_78 ) {
V_12 &= ~ V_78 ;
V_12 |= V_77 ;
}
V_75 = V_12 | ( V_75 & ~ V_76 ) ;
F_6 ( V_75 , V_10 -> V_15 + V_67 ) ;
} else {
V_19 -> V_90 = V_12 ;
}
return;
case V_91 :
if ( V_10 -> V_85 -> V_86 == V_57 )
V_12 |= V_58 ;
if ( ( V_10 -> V_85 -> V_86 == V_92 ) &&
( V_19 -> V_3 -> V_7 & V_51 ) )
V_19 -> V_42 = V_56 ;
if ( F_4 ( V_19 ) )
F_6 ( V_12 << 16 ,
V_10 -> V_15 + V_59 ) ;
else
F_6 ( V_12 << 16 | V_19 -> V_90 ,
V_10 -> V_15 + V_59 ) ;
return;
case V_93 :
V_12 &= ~ F_16 ( 0x7 , 0 ) ;
break;
}
F_5 ( V_10 , 0xffff , V_12 , V_13 ) ;
}
static T_4 F_17 ( struct V_9 * V_10 , int V_13 )
{
T_4 V_60 ;
T_1 V_12 ;
switch ( V_13 ) {
case V_49 :
V_12 = F_7 ( V_10 -> V_15 + V_13 ) ;
V_60 = V_12 & V_94 ;
V_60 |= ( V_12 >> 5 ) & V_95 ;
V_60 |= ( V_12 & V_96 ) ;
V_60 |= ( V_12 & V_97 ) << 3 ;
return V_60 ;
}
return F_18 ( V_10 -> V_15 + V_13 ) ;
}
static void F_19 ( struct V_9 * V_10 , T_4 V_12 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
T_1 V_79 ;
T_1 V_11 ;
switch ( V_13 ) {
case V_98 :
return;
case V_49 :
V_79 = V_12 & V_94 ;
V_79 |= V_99 ;
if ( ! F_1 ( V_19 ) ) {
V_79 |= ( V_12 & V_95 ) << 5 ;
}
V_11 = 0xffff & ~ ( V_100 | V_50 ) ;
F_5 ( V_10 , V_11 , V_79 , V_13 ) ;
return;
}
F_5 ( V_10 , 0xff , V_12 , V_13 ) ;
if ( ( V_13 == V_101 ) && ( V_12 & 1 ) ) {
F_5 ( V_10 , 0x7 , 0x7 , V_102 ) ;
if ( F_4 ( V_19 ) ) {
V_79 = F_7 ( V_10 -> V_15 + V_67 ) ;
F_6 ( V_79 & V_103 ,
V_10 -> V_15 + V_67 ) ;
V_19 -> V_104 = 0 ;
}
}
}
static unsigned int F_20 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
return V_18 -> clock ;
}
static unsigned int F_21 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
return V_18 -> clock / 256 / 16 ;
}
static inline void F_22 ( struct V_9 * V_10 ,
unsigned int clock )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
unsigned int V_105 = V_18 -> clock ;
int V_106 = 2 ;
int div = 1 ;
T_1 V_107 , V_12 ;
if ( clock == 0 ) {
V_10 -> V_108 -> V_109 = 0 ;
if ( F_4 ( V_19 ) ) {
V_12 = F_7 ( V_10 -> V_15 + V_54 ) ;
F_6 ( V_12 & ~ V_82 ,
V_10 -> V_15 + V_54 ) ;
}
return;
}
if ( F_4 ( V_19 ) && ! V_19 -> V_104 )
V_106 = 1 ;
V_107 = F_23 ( V_10 , V_102 ) ;
V_107 &= ~ ( V_110 | V_111 | V_112
| V_113 ) ;
F_24 ( V_10 , V_107 , V_102 ) ;
while ( V_105 / V_106 / 16 > clock && V_106 < 256 )
V_106 *= 2 ;
while ( V_105 / V_106 / div > clock && div < 16 )
div ++ ;
V_10 -> V_108 -> V_109 = V_105 / V_106 / div ;
F_25 ( F_26 ( V_10 -> V_108 ) , L_1 ,
clock , V_10 -> V_108 -> V_109 ) ;
if ( V_19 -> V_104 )
V_106 >>= 2 ;
else
V_106 >>= 1 ;
div -- ;
V_107 = F_23 ( V_10 , V_102 ) ;
V_107 |= ( V_110 | V_111 | V_112
| ( div << V_114 )
| ( V_106 << V_115 ) ) ;
F_24 ( V_10 , V_107 , V_102 ) ;
if ( F_4 ( V_19 ) ) {
V_12 = F_7 ( V_10 -> V_15 + V_54 ) ;
F_6 ( V_12 | V_82 ,
V_10 -> V_15 + V_54 ) ;
}
F_27 ( 1 ) ;
}
static unsigned int F_28 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
struct V_116 * V_117 = & V_19 -> V_117 ;
switch ( V_117 -> V_118 ) {
case V_119 :
return F_29 ( V_10 -> V_108 ) ;
case V_120 :
return ! ( F_7 ( V_10 -> V_15 + V_20 ) &
V_121 ) ;
case V_122 :
break;
}
return - V_123 ;
}
static void F_30 ( struct V_9 * V_10 , int V_124 )
{
T_1 V_125 ;
switch ( V_124 ) {
case V_126 :
V_125 = V_97 ;
break;
case V_127 :
V_125 = V_96 ;
break;
default:
V_125 = 0 ;
break;
}
F_5 ( V_10 , V_100 , V_125 ,
V_49 ) ;
}
static void F_31 ( struct V_9 * V_10 , T_1 V_12 )
{
T_1 V_13 ;
F_27 ( 1 ) ;
V_13 = F_7 ( V_10 -> V_15 + V_67 ) ;
V_13 |= V_70 | V_72 |
V_84 ;
F_6 ( V_13 , V_10 -> V_15 + V_67 ) ;
F_6 ( V_12 << 8 , V_10 -> V_15 + V_128 ) ;
F_25 ( F_26 ( V_10 -> V_108 ) ,
L_2 ,
V_12 , F_7 ( V_10 -> V_15 + V_128 ) ) ;
}
static void F_32 ( struct V_9 * V_10 )
{
T_1 V_13 ;
V_13 = F_7 ( V_10 -> V_15 + V_67 ) ;
V_13 &= ~ V_70 ;
V_13 |= V_83 ;
F_6 ( V_13 , V_10 -> V_15 + V_67 ) ;
}
static int F_33 ( struct V_9 * V_10 , T_1 V_86 )
{
int V_129 , V_130 , V_131 , V_60 ;
V_129 = V_132 ;
while ( V_129 < V_133 ) {
F_31 ( V_10 , V_129 ) ;
if ( ! F_34 ( V_10 -> V_108 , V_86 , NULL ) )
break;
V_129 += V_134 ;
}
V_130 = V_129 + V_134 ;
while ( V_130 < V_133 ) {
F_31 ( V_10 , V_130 ) ;
if ( F_34 ( V_10 -> V_108 , V_86 , NULL ) ) {
V_130 -= V_134 ;
break;
}
V_130 += V_134 ;
}
V_131 = ( V_129 + V_130 ) / 2 ;
F_31 ( V_10 , V_131 ) ;
V_60 = F_34 ( V_10 -> V_108 , V_86 , NULL ) ;
F_32 ( V_10 ) ;
F_25 ( F_26 ( V_10 -> V_108 ) , L_3 ,
V_60 ? L_4 : L_5 , V_131 , V_60 ) ;
return V_60 ;
}
static int F_35 ( struct V_9 * V_10 ,
unsigned int V_135 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
struct V_136 * V_137 ;
F_25 ( F_26 ( V_10 -> V_108 ) , L_6 , V_135 ) ;
if ( F_36 ( V_19 -> V_137 ) ||
F_36 ( V_19 -> V_138 ) ||
F_36 ( V_19 -> V_139 ) ||
F_36 ( V_19 -> V_140 ) )
return - V_141 ;
switch ( V_135 ) {
case V_142 :
case V_143 :
V_137 = V_19 -> V_139 ;
break;
case V_144 :
case V_145 :
case V_146 :
V_137 = V_19 -> V_140 ;
break;
default:
V_137 = V_19 -> V_138 ;
}
return F_37 ( V_19 -> V_137 , V_137 ) ;
}
static void F_38 ( struct V_9 * V_10 )
{
T_1 V_53 ;
if ( V_10 -> V_108 -> V_109 > V_147 ) {
F_6 ( F_7 ( V_10 -> V_15 + V_54 ) &
~ V_82 ,
V_10 -> V_15 + V_54 ) ;
F_6 ( V_148 ,
V_10 -> V_15 + V_149 ) ;
V_53 = V_150 |
( 7 << V_151 ) ;
F_6 ( V_53 , V_10 -> V_15 + V_149 ) ;
F_39 ( 1 ) ;
V_53 = F_7 ( V_10 -> V_15 + V_152 ) ;
if ( ! ( V_53 & V_153 ) )
F_40 ( F_26 ( V_10 -> V_108 ) ,
L_7 ) ;
if ( ! ( V_53 & V_154 ) )
F_40 ( F_26 ( V_10 -> V_108 ) ,
L_8 ) ;
}
}
static void F_41 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
T_1 V_125 ;
if ( F_4 ( V_19 ) ) {
if ( V_19 -> V_3 -> V_7 & V_66 ) {
V_125 = F_7 ( V_10 -> V_15 + V_67 ) ;
V_125 &= ~ V_72 ;
V_125 &= ~ V_84 ;
F_6 ( V_125 , V_10 -> V_15 + V_67 ) ;
F_6 ( 0 , V_10 -> V_15 + V_128 ) ;
} else if ( V_19 -> V_3 -> V_7 & V_68 ) {
V_125 = F_7 ( V_10 -> V_15 + V_69 ) ;
V_125 &= ~ V_72 ;
F_6 ( V_125 , V_10 -> V_15 + V_69 ) ;
}
}
}
static void F_42 ( struct V_9 * V_10 , unsigned V_155 )
{
T_1 V_75 ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
struct V_116 * V_117 = & V_19 -> V_117 ;
V_75 = F_7 ( V_10 -> V_15 + V_67 ) ;
V_75 &= ~ ( V_156 | V_157 ) ;
V_19 -> V_104 = 0 ;
switch ( V_155 ) {
case V_158 :
case V_159 :
case V_142 :
case V_144 :
case V_145 :
F_6 ( V_75 , V_10 -> V_15 + V_67 ) ;
break;
case V_143 :
case V_160 :
V_75 |= V_156 ;
F_6 ( V_75 , V_10 -> V_15 + V_67 ) ;
V_19 -> V_104 = 1 ;
if ( V_117 -> V_161 ) {
T_1 V_53 ;
V_53 = V_117 -> V_161 <<
V_162 |
( 1 << V_163 ) ;
if ( F_2 ( V_19 ) )
V_53 <<= 1 ;
F_6 ( V_53 , V_10 -> V_15 + V_164 ) ;
}
break;
case V_146 :
V_75 |= V_156 | V_157 ;
F_6 ( V_75 , V_10 -> V_15 + V_67 ) ;
V_19 -> V_104 = 1 ;
V_10 -> V_165 -> V_166 ( V_10 , V_10 -> clock ) ;
F_38 ( V_10 ) ;
break;
case V_167 :
default:
F_41 ( V_10 ) ;
break;
}
F_35 ( V_10 , V_155 ) ;
}
static void F_43 ( struct V_9 * V_10 , T_4 V_11 )
{
F_44 ( V_10 , V_11 ) ;
F_24 ( V_10 , V_10 -> V_168 , V_46 ) ;
F_24 ( V_10 , V_10 -> V_168 , V_47 ) ;
}
static unsigned int F_45 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
return F_4 ( V_19 ) ? 1 << 29 : 1 << 27 ;
}
static void F_46 ( struct V_9 * V_10 , struct V_169 * V_85 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
F_5 ( V_10 , V_170 ,
F_4 ( V_19 ) ? 0xF : 0xE ,
V_171 ) ;
}
static void F_47 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
int V_172 ;
if ( F_4 ( V_19 ) ) {
F_6 ( V_173 , V_10 -> V_15 + V_174 ) ;
F_6 ( F_7 ( V_10 -> V_15 + V_49 )
| V_175 ,
V_10 -> V_15 + V_49 ) ;
F_6 ( F_7 ( V_10 -> V_15 + 0x6c ) | F_48 ( 7 ) ,
V_10 -> V_15 + 0x6c ) ;
F_6 ( 0x0 , V_10 -> V_15 + V_164 ) ;
if ( V_19 -> V_3 -> V_7 & V_68 ) {
V_172 = F_7 ( V_10 -> V_15 + V_176 ) ;
V_172 |= V_177 |
V_178 ;
if ( V_19 -> V_117 . V_179 ) {
V_172 &= ~ V_180 ;
V_172 |= V_19 -> V_117 . V_179 ;
}
if ( V_19 -> V_117 . V_181 ) {
V_172 &= ~ V_182 ;
V_172 |= V_19 -> V_117 . V_181
<< V_183 ;
}
F_6 ( V_172 , V_10 -> V_15 + V_176 ) ;
}
}
}
static int
F_49 ( struct V_184 * V_185 ,
struct V_9 * V_10 ,
struct V_1 * V_19 )
{
struct V_186 * V_187 = V_185 -> V_188 . V_189 ;
struct V_116 * V_117 = & V_19 -> V_117 ;
int V_60 ;
if ( F_50 ( V_187 , L_9 , NULL ) )
V_117 -> V_118 = V_120 ;
V_117 -> V_190 = F_51 ( V_187 , L_10 , 0 ) ;
if ( F_52 ( V_117 -> V_190 ) )
V_117 -> V_118 = V_119 ;
F_53 ( V_187 , L_11 , & V_117 -> V_181 ) ;
F_53 ( V_187 , L_12 ,
& V_117 -> V_179 ) ;
if ( F_54 ( V_187 , L_13 , NULL ) )
V_117 -> V_191 = false ;
else
V_117 -> V_191 = true ;
if ( F_53 ( V_187 , L_14 , & V_117 -> V_161 ) )
V_117 -> V_161 = 0 ;
F_55 ( V_187 , & V_10 -> V_192 ) ;
if ( ( V_117 -> V_191 ) && F_4 ( V_19 ) &&
! F_36 ( V_19 -> V_138 ) ) {
V_19 -> V_139 = F_56 ( V_19 -> V_137 ,
V_193 ) ;
V_19 -> V_140 = F_56 ( V_19 -> V_137 ,
V_194 ) ;
if ( F_36 ( V_19 -> V_139 ) ||
F_36 ( V_19 -> V_140 ) ) {
F_40 ( F_26 ( V_10 -> V_108 ) ,
L_15 ) ;
V_10 -> V_195 |= V_196 ;
}
} else {
V_10 -> V_195 |= V_196 ;
}
V_60 = F_57 ( V_10 -> V_108 ) ;
if ( V_60 )
return V_60 ;
if ( F_58 ( V_10 -> V_108 ) >= 0 )
V_10 -> V_197 &= ~ V_198 ;
return 0 ;
}
static inline int
F_49 ( struct V_184 * V_185 ,
struct V_9 * V_10 ,
struct V_1 * V_19 )
{
return - V_199 ;
}
static int F_59 ( struct V_184 * V_185 ,
struct V_9 * V_10 ,
struct V_1 * V_19 )
{
struct V_116 * V_117 = & V_19 -> V_117 ;
int V_200 ;
if ( ! V_10 -> V_108 -> V_201 -> V_202 ) {
F_60 ( F_26 ( V_10 -> V_108 ) , L_16 ) ;
return - V_141 ;
}
V_19 -> V_117 = * ( (struct V_116 * )
V_10 -> V_108 -> V_201 -> V_202 ) ;
if ( V_117 -> V_118 == V_119 ) {
V_200 = F_61 ( V_10 -> V_108 , V_117 -> V_190 ) ;
if ( V_200 ) {
F_60 ( F_26 ( V_10 -> V_108 ) ,
L_17 ) ;
return V_200 ;
}
V_10 -> V_108 -> V_203 |= V_204 ;
}
switch ( V_117 -> V_205 ) {
case V_206 :
V_200 = F_62 ( V_10 -> V_108 , V_117 -> V_207 , 0 ) ;
if ( V_200 ) {
F_60 ( F_26 ( V_10 -> V_108 ) ,
L_18 ) ;
return V_200 ;
}
case V_208 :
V_10 -> V_197 &= ~ V_198 ;
break;
case V_209 :
V_10 -> V_108 -> V_210 |= V_211 ;
break;
case V_212 :
break;
}
switch ( V_117 -> V_213 ) {
case 8 :
V_10 -> V_108 -> V_210 |= V_214 | V_215 ;
break;
case 4 :
V_10 -> V_108 -> V_210 |= V_215 ;
break;
case 1 :
default:
V_10 -> V_197 |= V_216 ;
break;
}
return 0 ;
}
static int F_63 ( struct V_184 * V_185 )
{
const struct V_217 * V_218 =
F_64 ( V_219 , & V_185 -> V_188 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 ;
int V_200 ;
struct V_1 * V_19 ;
V_10 = F_65 ( V_185 , & V_220 ,
sizeof( * V_19 ) ) ;
if ( F_36 ( V_10 ) )
return F_66 ( V_10 ) ;
V_18 = F_9 ( V_10 ) ;
V_19 = F_10 ( V_18 ) ;
V_19 -> V_3 = V_218 ? V_218 -> V_2 : (struct V_221 * )
V_185 -> V_222 -> V_223 ;
V_19 -> V_224 = F_67 ( & V_185 -> V_188 , L_19 ) ;
if ( F_36 ( V_19 -> V_224 ) ) {
V_200 = F_66 ( V_19 -> V_224 ) ;
goto V_225;
}
V_19 -> V_226 = F_67 ( & V_185 -> V_188 , L_20 ) ;
if ( F_36 ( V_19 -> V_226 ) ) {
V_200 = F_66 ( V_19 -> V_226 ) ;
goto V_225;
}
V_19 -> V_227 = F_67 ( & V_185 -> V_188 , L_21 ) ;
if ( F_36 ( V_19 -> V_227 ) ) {
V_200 = F_66 ( V_19 -> V_227 ) ;
goto V_225;
}
V_18 -> V_228 = V_19 -> V_227 ;
V_18 -> clock = F_68 ( V_18 -> V_228 ) ;
F_69 ( V_19 -> V_227 ) ;
F_69 ( V_19 -> V_224 ) ;
F_69 ( V_19 -> V_226 ) ;
V_19 -> V_137 = F_70 ( & V_185 -> V_188 ) ;
if ( F_36 ( V_19 -> V_137 ) ) {
V_200 = F_66 ( V_19 -> V_137 ) ;
goto V_229;
}
V_19 -> V_138 = F_56 ( V_19 -> V_137 ,
V_230 ) ;
if ( F_36 ( V_19 -> V_138 ) )
F_40 ( F_26 ( V_10 -> V_108 ) , L_22 ) ;
if ( V_19 -> V_3 -> V_7 & V_231 )
V_10 -> V_197 |= V_232
| V_233 ;
if ( F_4 ( V_19 ) ) {
V_10 -> V_195 |= V_234 ;
V_10 -> V_108 -> V_210 |= V_235 ;
if ( ! ( V_19 -> V_3 -> V_7 & V_236 ) )
V_10 -> V_195 |= V_237 ;
F_6 ( 0x0 , V_10 -> V_15 + V_67 ) ;
F_6 ( 0x0 , V_10 -> V_15 + V_69 ) ;
F_6 ( 0x0 , V_10 -> V_15 + V_128 ) ;
}
if ( V_19 -> V_3 -> V_7 & V_66 )
V_238 . V_239 =
F_33 ;
if ( V_19 -> V_3 -> V_7 & V_240 )
V_10 -> V_197 |= V_233 ;
if ( V_19 -> V_3 -> V_7 & V_33 )
V_10 -> V_195 |= V_241 ;
if ( V_218 )
V_200 = F_49 ( V_185 , V_10 , V_19 ) ;
else
V_200 = F_59 ( V_185 , V_10 , V_19 ) ;
if ( V_200 )
goto V_229;
F_47 ( V_10 ) ;
V_200 = F_71 ( V_10 ) ;
if ( V_200 )
goto V_229;
F_72 ( & V_185 -> V_188 ) ;
F_73 ( & V_185 -> V_188 , 50 ) ;
F_74 ( & V_185 -> V_188 ) ;
F_75 ( & V_185 -> V_188 , 1 ) ;
F_76 ( & V_185 -> V_188 ) ;
return 0 ;
V_229:
F_77 ( V_19 -> V_227 ) ;
F_77 ( V_19 -> V_224 ) ;
F_77 ( V_19 -> V_226 ) ;
V_225:
F_78 ( V_185 ) ;
return V_200 ;
}
static int F_79 ( struct V_184 * V_185 )
{
struct V_9 * V_10 = F_80 ( V_185 ) ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
int V_242 = ( F_7 ( V_10 -> V_15 + V_39 ) == 0xffffffff ) ;
F_81 ( & V_185 -> V_188 ) ;
F_82 ( & V_185 -> V_188 ) ;
F_83 ( & V_185 -> V_188 ) ;
F_84 ( V_10 , V_242 ) ;
F_77 ( V_19 -> V_227 ) ;
F_77 ( V_19 -> V_224 ) ;
F_77 ( V_19 -> V_226 ) ;
F_78 ( V_185 ) ;
return 0 ;
}
static int F_85 ( struct V_243 * V_188 )
{
struct V_9 * V_10 = F_86 ( V_188 ) ;
if ( V_10 -> V_244 != V_31 )
F_87 ( V_10 -> V_108 ) ;
return F_88 ( V_10 ) ;
}
static int F_89 ( struct V_243 * V_188 )
{
struct V_9 * V_10 = F_86 ( V_188 ) ;
F_47 ( V_10 ) ;
return F_90 ( V_10 ) ;
}
static int F_91 ( struct V_243 * V_188 )
{
struct V_9 * V_10 = F_86 ( V_188 ) ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
int V_60 ;
V_60 = F_92 ( V_10 ) ;
if ( V_10 -> V_244 != V_31 )
F_87 ( V_10 -> V_108 ) ;
if ( ! F_93 ( V_10 ) ) {
F_77 ( V_19 -> V_227 ) ;
F_77 ( V_19 -> V_224 ) ;
}
F_77 ( V_19 -> V_226 ) ;
return V_60 ;
}
static int F_94 ( struct V_243 * V_188 )
{
struct V_9 * V_10 = F_86 ( V_188 ) ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
if ( ! F_93 ( V_10 ) ) {
F_69 ( V_19 -> V_227 ) ;
F_69 ( V_19 -> V_224 ) ;
}
F_69 ( V_19 -> V_226 ) ;
return F_95 ( V_10 ) ;
}
