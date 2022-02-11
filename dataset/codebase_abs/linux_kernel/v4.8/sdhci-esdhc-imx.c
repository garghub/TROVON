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
if ( F_11 ( V_13 == V_46 || V_13 == V_47 ) ) {
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
static void F_17 ( struct V_9 * V_10 , T_4 V_12 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
T_1 V_79 ;
T_1 V_11 ;
switch ( V_13 ) {
case V_94 :
return;
case V_49 :
V_79 = V_12 & V_95 ;
V_79 |= V_96 ;
if ( ! F_1 ( V_19 ) ) {
V_79 |= ( V_12 & V_97 ) << 5 ;
}
V_11 = 0xffff & ~ ( V_98 | V_50 ) ;
F_5 ( V_10 , V_11 , V_79 , V_13 ) ;
return;
}
F_5 ( V_10 , 0xff , V_12 , V_13 ) ;
if ( ( V_13 == V_99 ) && ( V_12 & 1 ) ) {
F_5 ( V_10 , 0x7 , 0x7 , V_100 ) ;
if ( F_4 ( V_19 ) ) {
V_79 = F_7 ( V_10 -> V_15 + V_67 ) ;
F_6 ( V_79 & V_101 ,
V_10 -> V_15 + V_67 ) ;
V_19 -> V_102 = 0 ;
}
}
}
static unsigned int F_18 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
return V_18 -> clock ;
}
static unsigned int F_19 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
return V_18 -> clock / 256 / 16 ;
}
static inline void F_20 ( struct V_9 * V_10 ,
unsigned int clock )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
unsigned int V_103 = V_18 -> clock ;
int V_104 = 2 ;
int div = 1 ;
T_1 V_105 , V_12 ;
if ( clock == 0 ) {
V_10 -> V_106 -> V_107 = 0 ;
if ( F_4 ( V_19 ) ) {
V_12 = F_7 ( V_10 -> V_15 + V_54 ) ;
F_6 ( V_12 & ~ V_82 ,
V_10 -> V_15 + V_54 ) ;
}
return;
}
if ( F_4 ( V_19 ) && ! V_19 -> V_102 )
V_104 = 1 ;
V_105 = F_21 ( V_10 , V_100 ) ;
V_105 &= ~ ( V_108 | V_109 | V_110
| V_111 ) ;
F_22 ( V_10 , V_105 , V_100 ) ;
while ( V_103 / V_104 / 16 > clock && V_104 < 256 )
V_104 *= 2 ;
while ( V_103 / V_104 / div > clock && div < 16 )
div ++ ;
V_10 -> V_106 -> V_107 = V_103 / V_104 / div ;
F_23 ( F_24 ( V_10 -> V_106 ) , L_1 ,
clock , V_10 -> V_106 -> V_107 ) ;
if ( V_19 -> V_102 )
V_104 >>= 2 ;
else
V_104 >>= 1 ;
div -- ;
V_105 = F_21 ( V_10 , V_100 ) ;
V_105 |= ( V_108 | V_109 | V_110
| ( div << V_112 )
| ( V_104 << V_113 ) ) ;
F_22 ( V_10 , V_105 , V_100 ) ;
if ( F_4 ( V_19 ) ) {
V_12 = F_7 ( V_10 -> V_15 + V_54 ) ;
F_6 ( V_12 | V_82 ,
V_10 -> V_15 + V_54 ) ;
}
F_25 ( 1 ) ;
}
static unsigned int F_26 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
struct V_114 * V_115 = & V_19 -> V_115 ;
switch ( V_115 -> V_116 ) {
case V_117 :
return F_27 ( V_10 -> V_106 ) ;
case V_118 :
return ! ( F_7 ( V_10 -> V_15 + V_20 ) &
V_119 ) ;
case V_120 :
break;
}
return - V_121 ;
}
static void F_28 ( struct V_9 * V_10 , int V_122 )
{
T_1 V_123 ;
switch ( V_122 ) {
case V_124 :
V_123 = V_125 ;
break;
case V_126 :
V_123 = V_127 ;
break;
default:
V_123 = 0 ;
break;
}
F_5 ( V_10 , V_98 , V_123 ,
V_49 ) ;
}
static void F_29 ( struct V_9 * V_10 , T_1 V_12 )
{
T_1 V_13 ;
F_25 ( 1 ) ;
V_13 = F_7 ( V_10 -> V_15 + V_67 ) ;
V_13 |= V_70 | V_72 |
V_84 ;
F_6 ( V_13 , V_10 -> V_15 + V_67 ) ;
F_6 ( V_12 << 8 , V_10 -> V_15 + V_128 ) ;
F_23 ( F_24 ( V_10 -> V_106 ) ,
L_2 ,
V_12 , F_7 ( V_10 -> V_15 + V_128 ) ) ;
}
static void F_30 ( struct V_9 * V_10 )
{
T_1 V_13 ;
V_13 = F_7 ( V_10 -> V_15 + V_67 ) ;
V_13 &= ~ V_70 ;
V_13 |= V_83 ;
F_6 ( V_13 , V_10 -> V_15 + V_67 ) ;
}
static int F_31 ( struct V_9 * V_10 , T_1 V_86 )
{
int V_129 , V_130 , V_131 , V_60 ;
V_129 = V_132 ;
while ( V_129 < V_133 ) {
F_29 ( V_10 , V_129 ) ;
if ( ! F_32 ( V_10 -> V_106 , V_86 , NULL ) )
break;
V_129 += V_134 ;
}
V_130 = V_129 + V_134 ;
while ( V_130 < V_133 ) {
F_29 ( V_10 , V_130 ) ;
if ( F_32 ( V_10 -> V_106 , V_86 , NULL ) ) {
V_130 -= V_134 ;
break;
}
V_130 += V_134 ;
}
V_131 = ( V_129 + V_130 ) / 2 ;
F_29 ( V_10 , V_131 ) ;
V_60 = F_32 ( V_10 -> V_106 , V_86 , NULL ) ;
F_30 ( V_10 ) ;
F_23 ( F_24 ( V_10 -> V_106 ) , L_3 ,
V_60 ? L_4 : L_5 , V_131 , V_60 ) ;
return V_60 ;
}
static int F_33 ( struct V_9 * V_10 ,
unsigned int V_135 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
struct V_136 * V_137 ;
F_23 ( F_24 ( V_10 -> V_106 ) , L_6 , V_135 ) ;
if ( F_34 ( V_19 -> V_137 ) ||
F_34 ( V_19 -> V_138 ) ||
F_34 ( V_19 -> V_139 ) ||
F_34 ( V_19 -> V_140 ) )
return - V_141 ;
switch ( V_135 ) {
case V_142 :
V_137 = V_19 -> V_139 ;
break;
case V_143 :
case V_144 :
case V_145 :
V_137 = V_19 -> V_140 ;
break;
default:
V_137 = V_19 -> V_138 ;
}
return F_35 ( V_19 -> V_137 , V_137 ) ;
}
static void F_36 ( struct V_9 * V_10 )
{
T_1 V_53 ;
if ( V_10 -> V_106 -> V_107 > V_146 ) {
F_6 ( F_7 ( V_10 -> V_15 + V_54 ) &
~ V_82 ,
V_10 -> V_15 + V_54 ) ;
F_6 ( V_147 ,
V_10 -> V_15 + V_148 ) ;
V_53 = V_149 |
( 7 << V_150 ) ;
F_6 ( V_53 , V_10 -> V_15 + V_148 ) ;
F_37 ( 1 ) ;
V_53 = F_7 ( V_10 -> V_15 + V_151 ) ;
if ( ! ( V_53 & V_152 ) )
F_38 ( F_24 ( V_10 -> V_106 ) ,
L_7 ) ;
if ( ! ( V_53 & V_153 ) )
F_38 ( F_24 ( V_10 -> V_106 ) ,
L_8 ) ;
}
}
static void F_39 ( struct V_9 * V_10 , unsigned V_154 )
{
T_1 V_75 ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
struct V_114 * V_115 = & V_19 -> V_115 ;
V_75 = F_7 ( V_10 -> V_15 + V_67 ) ;
V_75 &= ~ ( V_155 | V_156 ) ;
V_19 -> V_102 = 0 ;
switch ( V_154 ) {
case V_157 :
case V_158 :
case V_142 :
case V_143 :
case V_144 :
F_6 ( V_75 , V_10 -> V_15 + V_67 ) ;
break;
case V_159 :
case V_160 :
V_75 |= V_155 ;
F_6 ( V_75 , V_10 -> V_15 + V_67 ) ;
V_19 -> V_102 = 1 ;
if ( V_115 -> V_161 ) {
T_1 V_53 ;
V_53 = V_115 -> V_161 <<
V_162 |
( 1 << V_163 ) ;
if ( F_2 ( V_19 ) )
V_53 <<= 1 ;
F_6 ( V_53 , V_10 -> V_15 + V_164 ) ;
}
break;
case V_145 :
V_75 |= V_155 | V_156 ;
F_6 ( V_75 , V_10 -> V_15 + V_67 ) ;
V_19 -> V_102 = 1 ;
V_10 -> V_165 -> V_166 ( V_10 , V_10 -> clock ) ;
F_36 ( V_10 ) ;
break;
}
F_33 ( V_10 , V_154 ) ;
}
static void F_40 ( struct V_9 * V_10 , T_4 V_11 )
{
F_41 ( V_10 , V_11 ) ;
F_22 ( V_10 , V_10 -> V_167 , V_46 ) ;
F_22 ( V_10 , V_10 -> V_167 , V_47 ) ;
}
static unsigned int F_42 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
return F_4 ( V_19 ) ? 1 << 28 : 1 << 27 ;
}
static void F_43 ( struct V_9 * V_10 , struct V_168 * V_85 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
F_44 ( V_10 , F_4 ( V_19 ) ? 0xF : 0xE ,
V_169 ) ;
}
static void F_45 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
int V_170 ;
if ( F_4 ( V_19 ) ) {
F_6 ( V_171 , V_10 -> V_15 + V_172 ) ;
F_6 ( F_7 ( V_10 -> V_15 + V_49 )
| V_173 ,
V_10 -> V_15 + V_49 ) ;
F_6 ( F_7 ( V_10 -> V_15 + 0x6c ) | F_46 ( 7 ) ,
V_10 -> V_15 + 0x6c ) ;
F_6 ( 0x0 , V_10 -> V_15 + V_164 ) ;
if ( V_19 -> V_3 -> V_7 & V_68 ) {
V_170 = F_7 ( V_10 -> V_15 + V_174 ) ;
V_170 |= V_175 |
V_176 ;
if ( V_19 -> V_115 . V_177 ) {
V_170 &= ~ V_178 ;
V_170 |= V_19 -> V_115 . V_177 ;
}
if ( V_19 -> V_115 . V_179 ) {
V_170 &= ~ V_180 ;
V_170 |= V_19 -> V_115 . V_179
<< V_181 ;
}
F_6 ( V_170 , V_10 -> V_15 + V_174 ) ;
}
}
}
static int
F_47 ( struct V_182 * V_183 ,
struct V_9 * V_10 ,
struct V_1 * V_19 )
{
struct V_184 * V_185 = V_183 -> V_186 . V_187 ;
struct V_114 * V_115 = & V_19 -> V_115 ;
int V_60 ;
if ( F_48 ( V_185 , L_9 , NULL ) )
V_115 -> V_116 = V_118 ;
V_115 -> V_188 = F_49 ( V_185 , L_10 , 0 ) ;
if ( F_50 ( V_115 -> V_188 ) )
V_115 -> V_116 = V_117 ;
F_51 ( V_185 , L_11 , & V_115 -> V_179 ) ;
F_51 ( V_185 , L_12 ,
& V_115 -> V_177 ) ;
if ( F_52 ( V_185 , L_13 , NULL ) )
V_115 -> V_189 = false ;
else
V_115 -> V_189 = true ;
if ( F_51 ( V_185 , L_14 , & V_115 -> V_161 ) )
V_115 -> V_161 = 0 ;
F_53 ( V_185 , & V_10 -> V_190 ) ;
if ( ( V_115 -> V_189 ) && F_4 ( V_19 ) &&
! F_34 ( V_19 -> V_138 ) ) {
V_19 -> V_139 = F_54 ( V_19 -> V_137 ,
V_191 ) ;
V_19 -> V_140 = F_54 ( V_19 -> V_137 ,
V_192 ) ;
if ( F_34 ( V_19 -> V_139 ) ||
F_34 ( V_19 -> V_140 ) ) {
F_38 ( F_24 ( V_10 -> V_106 ) ,
L_15 ) ;
V_10 -> V_193 |= V_194 ;
}
} else {
V_10 -> V_193 |= V_194 ;
}
V_60 = F_55 ( V_10 -> V_106 ) ;
if ( V_60 )
return V_60 ;
if ( F_56 ( V_10 -> V_106 ) >= 0 )
V_10 -> V_195 &= ~ V_196 ;
return 0 ;
}
static inline int
F_47 ( struct V_182 * V_183 ,
struct V_9 * V_10 ,
struct V_1 * V_19 )
{
return - V_197 ;
}
static int F_57 ( struct V_182 * V_183 ,
struct V_9 * V_10 ,
struct V_1 * V_19 )
{
struct V_114 * V_115 = & V_19 -> V_115 ;
int V_198 ;
if ( ! V_10 -> V_106 -> V_199 -> V_200 ) {
F_58 ( F_24 ( V_10 -> V_106 ) , L_16 ) ;
return - V_141 ;
}
V_19 -> V_115 = * ( (struct V_114 * )
V_10 -> V_106 -> V_199 -> V_200 ) ;
if ( V_115 -> V_116 == V_117 ) {
V_198 = F_59 ( V_10 -> V_106 , V_115 -> V_188 ) ;
if ( V_198 ) {
F_58 ( F_24 ( V_10 -> V_106 ) ,
L_17 ) ;
return V_198 ;
}
V_10 -> V_106 -> V_201 |= V_202 ;
}
switch ( V_115 -> V_203 ) {
case V_204 :
V_198 = F_60 ( V_10 -> V_106 , V_115 -> V_205 , 0 ) ;
if ( V_198 ) {
F_58 ( F_24 ( V_10 -> V_106 ) ,
L_18 ) ;
return V_198 ;
}
case V_206 :
V_10 -> V_195 &= ~ V_196 ;
break;
case V_207 :
V_10 -> V_106 -> V_208 |= V_209 ;
break;
case V_210 :
break;
}
switch ( V_115 -> V_211 ) {
case 8 :
V_10 -> V_106 -> V_208 |= V_212 | V_213 ;
break;
case 4 :
V_10 -> V_106 -> V_208 |= V_213 ;
break;
case 1 :
default:
V_10 -> V_195 |= V_214 ;
break;
}
return 0 ;
}
static int F_61 ( struct V_182 * V_183 )
{
const struct V_215 * V_216 =
F_62 ( V_217 , & V_183 -> V_186 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 ;
int V_198 ;
struct V_1 * V_19 ;
V_10 = F_63 ( V_183 , & V_218 ,
sizeof( * V_19 ) ) ;
if ( F_34 ( V_10 ) )
return F_64 ( V_10 ) ;
V_18 = F_9 ( V_10 ) ;
V_19 = F_10 ( V_18 ) ;
V_19 -> V_3 = V_216 ? V_216 -> V_2 : (struct V_219 * )
V_183 -> V_220 -> V_221 ;
V_19 -> V_222 = F_65 ( & V_183 -> V_186 , L_19 ) ;
if ( F_34 ( V_19 -> V_222 ) ) {
V_198 = F_64 ( V_19 -> V_222 ) ;
goto V_223;
}
V_19 -> V_224 = F_65 ( & V_183 -> V_186 , L_20 ) ;
if ( F_34 ( V_19 -> V_224 ) ) {
V_198 = F_64 ( V_19 -> V_224 ) ;
goto V_223;
}
V_19 -> V_225 = F_65 ( & V_183 -> V_186 , L_21 ) ;
if ( F_34 ( V_19 -> V_225 ) ) {
V_198 = F_64 ( V_19 -> V_225 ) ;
goto V_223;
}
V_18 -> V_226 = V_19 -> V_225 ;
V_18 -> clock = F_66 ( V_18 -> V_226 ) ;
F_67 ( V_19 -> V_225 ) ;
F_67 ( V_19 -> V_222 ) ;
F_67 ( V_19 -> V_224 ) ;
V_19 -> V_137 = F_68 ( & V_183 -> V_186 ) ;
if ( F_34 ( V_19 -> V_137 ) ) {
V_198 = F_64 ( V_19 -> V_137 ) ;
goto V_227;
}
V_19 -> V_138 = F_54 ( V_19 -> V_137 ,
V_228 ) ;
if ( F_34 ( V_19 -> V_138 ) )
F_38 ( F_24 ( V_10 -> V_106 ) , L_22 ) ;
if ( V_19 -> V_3 -> V_7 & V_229 )
V_10 -> V_195 |= V_230
| V_231 ;
if ( F_4 ( V_19 ) ) {
V_10 -> V_193 |= V_232 ;
V_10 -> V_106 -> V_208 |= V_233 ;
if ( ! ( V_19 -> V_3 -> V_7 & V_234 ) )
V_10 -> V_193 |= V_235 ;
F_6 ( 0x0 , V_10 -> V_15 + V_67 ) ;
F_6 ( 0x0 , V_10 -> V_15 + V_69 ) ;
F_6 ( 0x0 , V_10 -> V_15 + V_128 ) ;
}
if ( V_19 -> V_3 -> V_7 & V_66 )
V_236 . V_237 =
F_31 ;
if ( V_19 -> V_3 -> V_7 & V_238 )
V_10 -> V_195 |= V_231 ;
if ( V_19 -> V_3 -> V_7 & V_33 )
V_10 -> V_193 |= V_239 ;
if ( V_216 )
V_198 = F_47 ( V_183 , V_10 , V_19 ) ;
else
V_198 = F_57 ( V_183 , V_10 , V_19 ) ;
if ( V_198 )
goto V_227;
F_45 ( V_10 ) ;
V_198 = F_69 ( V_10 ) ;
if ( V_198 )
goto V_227;
F_70 ( & V_183 -> V_186 ) ;
F_71 ( & V_183 -> V_186 , 50 ) ;
F_72 ( & V_183 -> V_186 ) ;
F_73 ( & V_183 -> V_186 , 1 ) ;
F_74 ( & V_183 -> V_186 ) ;
return 0 ;
V_227:
F_75 ( V_19 -> V_225 ) ;
F_75 ( V_19 -> V_222 ) ;
F_75 ( V_19 -> V_224 ) ;
V_223:
F_76 ( V_183 ) ;
return V_198 ;
}
static int F_77 ( struct V_182 * V_183 )
{
struct V_9 * V_10 = F_78 ( V_183 ) ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
int V_240 = ( F_7 ( V_10 -> V_15 + V_39 ) == 0xffffffff ) ;
F_79 ( & V_183 -> V_186 ) ;
F_80 ( & V_183 -> V_186 ) ;
F_81 ( & V_183 -> V_186 ) ;
F_82 ( V_10 , V_240 ) ;
F_75 ( V_19 -> V_225 ) ;
F_75 ( V_19 -> V_222 ) ;
F_75 ( V_19 -> V_224 ) ;
F_76 ( V_183 ) ;
return 0 ;
}
static int F_83 ( struct V_241 * V_186 )
{
struct V_9 * V_10 = F_84 ( V_186 ) ;
return F_85 ( V_10 ) ;
}
static int F_86 ( struct V_241 * V_186 )
{
struct V_9 * V_10 = F_84 ( V_186 ) ;
F_45 ( V_10 ) ;
return F_87 ( V_10 ) ;
}
static int F_88 ( struct V_241 * V_186 )
{
struct V_9 * V_10 = F_84 ( V_186 ) ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
int V_60 ;
V_60 = F_89 ( V_10 ) ;
if ( ! F_90 ( V_10 ) ) {
F_75 ( V_19 -> V_225 ) ;
F_75 ( V_19 -> V_222 ) ;
}
F_75 ( V_19 -> V_224 ) ;
return V_60 ;
}
static int F_91 ( struct V_241 * V_186 )
{
struct V_9 * V_10 = F_84 ( V_186 ) ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = F_10 ( V_18 ) ;
if ( ! F_90 ( V_10 ) ) {
F_67 ( V_19 -> V_225 ) ;
F_67 ( V_19 -> V_222 ) ;
}
F_67 ( V_19 -> V_224 ) ;
return F_92 ( V_10 ) ;
}
