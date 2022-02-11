static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static void F_2 ( struct V_5 * V_6 )
{
F_3 ( V_6 , V_7 , 0 ) ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 , int V_12 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
T_1 V_13 = F_5 ( V_6 , V_14 ) ;
switch ( V_12 ) {
case V_15 :
V_13 = V_16 |
V_17 ;
F_3 ( V_6 , V_14 , V_13 ) ;
break;
case V_18 :
V_13 &= ~ V_16 ;
V_13 |= V_19 |
V_20 |
V_21 ;
F_3 ( V_6 , V_14 , V_13 ) ;
F_6 ( 400 ) ;
V_13 &= ~ V_17 ;
V_13 |= V_22 ;
F_3 ( V_6 , V_14 , V_13 ) ;
V_13 &= ~ V_20 ;
F_3 ( V_6 , V_14 , V_13 ) ;
V_13 &= ~ V_19 ;
F_3 ( V_6 , V_14 , V_13 ) ;
break;
case V_23 :
V_13 |= V_19 ;
F_3 ( V_6 , V_14 , V_13 ) ;
V_13 &= ~ V_22 ;
F_3 ( V_6 , V_14 , V_13 ) ;
V_13 |= V_16 |
V_17 ;
V_13 &= ~ V_21 ;
F_3 ( V_6 , V_14 , V_13 ) ;
break;
case V_24 :
F_3 ( V_6 , V_14 , 0 ) ;
break;
default:
F_7 ( 1 , L_1 , V_12 ) ;
break;
}
return 0 ;
}
static int F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_5 * V_6 = V_30 -> V_6 ;
T_1 V_3 ;
V_3 = F_5 ( V_6 , V_31 ) & ~ 0x60 ;
switch ( F_9 ( V_28 ) ) {
case 16 :
break;
case 20 :
V_3 |= 0x20 ;
break;
case 24 :
V_3 |= 0x40 ;
break;
case 32 :
V_3 |= 0x60 ;
break;
default:
return - V_32 ;
}
F_3 ( V_6 , V_31 , V_3 ) ;
if ( V_26 -> V_33 == V_34 ) {
V_3 = F_5 ( V_6 , V_35 ) ;
if ( F_10 ( V_28 ) <= 24000 )
V_3 |= V_36 ;
else
V_3 &= ~ V_36 ;
F_3 ( V_6 , V_35 , V_3 ) ;
}
return 0 ;
}
static int F_11 ( struct V_37 * V_38 , unsigned int V_39 ,
unsigned int V_40 )
{
T_2 V_41 ;
unsigned int V_42 , V_43 , V_44 , V_45 ;
unsigned int div ;
if ( F_12 ( ! V_40 ) )
return - V_32 ;
V_45 = V_40 ;
div = 1 ;
while ( V_45 < 90000000 ) {
div *= 2 ;
V_45 *= 2 ;
}
if ( V_45 > 100000000 )
F_13 ( V_46 L_2
L_3 , V_45 , V_39 , V_40 ) ;
if ( div > 32 ) {
F_13 ( V_47 L_4
L_5 ,
div , V_39 , V_40 , V_45 ) ;
return - V_32 ;
}
V_38 -> V_48 = div >> 2 ;
if ( V_39 < 48000 )
V_38 -> V_49 = 1 ;
else
V_38 -> V_49 = 0 ;
V_43 = V_45 / V_39 ;
if ( V_39 < 1000000 )
V_38 -> V_50 = 8 ;
else
V_38 -> V_50 = 1 ;
V_38 -> V_51 = V_43 / V_38 -> V_50 ;
V_44 = ( V_45 / V_38 -> V_50 ) % V_39 ;
V_41 = V_52 * ( long long ) V_44 ;
F_14 ( V_41 , V_39 ) ;
V_42 = V_41 & 0xFFFFFFFF ;
if ( ( V_42 % 10 ) >= 5 )
V_42 += 5 ;
V_38 -> V_53 = V_42 / 10 ;
if ( F_12 ( V_45 != V_40 * ( V_38 -> V_48 << 2 ) ) ||
F_12 ( ! V_42 && V_45 != V_39 * V_38 -> V_50 * V_38 -> V_51 ) )
return - V_32 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
int V_54 , unsigned int V_55 , unsigned int V_56 )
{
struct V_57 * V_58 = F_16 ( V_6 ) ;
struct V_37 V_38 ;
if ( V_58 -> V_59 == V_55 && V_58 -> V_60 == V_56 )
return 0 ;
F_17 ( V_6 , V_61 ,
V_62 , 0 ) ;
if ( ! V_55 || ! V_56 ) {
F_17 ( V_6 , V_63 ,
V_64 , 0 ) ;
F_17 ( V_6 , V_65 ,
V_66 , 0 ) ;
V_58 -> V_59 = V_55 ;
V_58 -> V_60 = V_56 ;
return 0 ;
}
if ( F_11 ( & V_38 , V_55 , V_56 ) != 0 )
goto V_67;
V_58 -> V_59 = V_55 ;
V_58 -> V_60 = V_56 ;
F_3 ( V_6 , V_65 ,
V_38 . V_50 | V_66 ) ;
F_3 ( V_6 , V_68 , V_38 . V_51 >> 5 ) ;
F_3 ( V_6 , V_69 ,
( V_38 . V_48 << 6 ) | ( V_38 . V_51 & 0x1f ) ) ;
if ( V_38 . V_53 ) {
F_3 ( V_6 , V_70 ,
( V_38 . V_53 >> 8 ) | 0x100 ) ;
F_3 ( V_6 , V_71 , V_38 . V_53 & 0xff ) ;
} else
F_3 ( V_6 , V_70 , 0 ) ;
if ( V_38 . V_49 )
F_3 ( V_6 , V_72 ,
V_73 ) ;
else
F_3 ( V_6 , V_72 , 0 ) ;
F_17 ( V_6 , V_61 ,
V_62 ,
V_62 ) ;
V_67:
F_17 ( V_6 , V_63 ,
V_64 ,
V_64 ) ;
return 0 ;
}
static int F_18 ( struct V_29 * V_74 , int V_75 ,
int V_76 , unsigned int V_55 , unsigned int V_56 )
{
return F_15 ( V_74 -> V_6 , V_75 , V_55 , V_56 ) ;
}
static int F_19 ( struct V_29 * V_74 ,
int V_77 , int div )
{
struct V_5 * V_6 = V_74 -> V_6 ;
switch ( V_77 ) {
case V_78 :
F_17 ( V_6 , V_63 ,
V_79 , div ) ;
break;
case V_80 :
F_17 ( V_6 , V_63 ,
V_81 , div ) ;
break;
case V_82 :
F_17 ( V_6 , V_83 ,
V_84 , div ) ;
break;
case V_85 :
F_17 ( V_6 , V_86 ,
V_84 , div ) ;
break;
case V_87 :
F_17 ( V_6 , V_88 ,
V_89 , div ) ;
break;
case V_90 :
F_17 ( V_6 , V_88 ,
V_91 , div ) ;
break;
case V_92 :
F_17 ( V_6 , V_35 ,
V_93 , div ) ;
break;
default:
return - V_32 ;
}
return 0 ;
}
static int F_20 ( struct V_29 * V_74 ,
unsigned int V_94 )
{
struct V_5 * V_6 = V_74 -> V_6 ;
unsigned int V_95 , V_96 , V_97 , V_98 ;
V_95 = F_5 ( V_6 , V_63 ) ;
V_96 = F_5 ( V_6 , V_31 ) ;
V_97 = F_5 ( V_6 , V_86 ) ;
V_98 = F_5 ( V_6 , V_83 ) ;
switch ( V_94 & V_99 ) {
case V_100 :
V_95 &= ~ V_101 ;
V_97 &= ~ V_102 ;
V_98 &= ~ V_103 ;
break;
case V_104 :
V_95 &= ~ V_101 ;
V_97 |= V_102 ;
V_98 |= V_103 ;
break;
case V_105 :
V_95 |= V_101 ;
V_97 |= V_102 ;
V_98 |= V_103 ;
break;
case V_106 :
V_95 |= V_101 ;
V_97 &= ~ V_102 ;
V_98 &= ~ V_103 ;
break;
default:
return - V_32 ;
}
switch ( V_94 & V_107 ) {
case V_108 :
V_96 |= V_109 ;
V_96 &= ~ V_110 ;
break;
case V_111 :
V_96 |= V_109 ;
V_96 |= V_110 ;
break;
case V_112 :
V_96 &= ~ V_109 ;
V_96 |= 0x10 ;
break;
case V_113 :
V_96 &= ~ V_109 ;
break;
case V_114 :
V_96 &= ~ V_109 ;
V_96 |= 0x8 ;
break;
default:
return - V_32 ;
}
switch ( V_94 & V_107 ) {
case V_108 :
case V_111 :
switch ( V_94 & V_115 ) {
case V_116 :
V_96 &= ~ V_117 ;
break;
case V_118 :
V_96 |= V_117 ;
break;
default:
return - V_32 ;
}
break;
case V_112 :
case V_113 :
case V_114 :
switch ( V_94 & V_115 ) {
case V_116 :
V_96 &= ~ V_117 ;
V_96 &= ~ V_110 ;
break;
case V_119 :
V_96 |= V_117 ;
V_96 |= V_110 ;
break;
case V_118 :
V_96 |= V_117 ;
V_96 &= ~ V_110 ;
break;
case V_120 :
V_96 &= ~ V_117 ;
V_96 |= V_110 ;
break;
default:
return - V_32 ;
}
break;
default:
return - V_32 ;
}
F_3 ( V_6 , V_63 , V_95 ) ;
F_3 ( V_6 , V_31 , V_96 ) ;
F_3 ( V_6 , V_86 , V_97 ) ;
F_3 ( V_6 , V_83 , V_98 ) ;
return 0 ;
}
static int F_21 ( struct V_29 * V_74 , int V_121 )
{
struct V_5 * V_6 = V_74 -> V_6 ;
T_1 V_3 ;
V_3 = F_5 ( V_6 , V_35 ) ;
if ( V_121 )
V_3 |= V_122 ;
else
V_3 &= ~ V_122 ;
F_3 ( V_6 , V_35 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
enum V_123 V_124 )
{
T_1 V_3 ;
switch ( V_124 ) {
case V_125 :
F_17 ( V_6 , V_126 ,
V_127 ,
V_127 ) ;
F_17 ( V_6 , V_128 ,
V_129 ,
V_129 ) ;
break;
case V_130 :
break;
case V_131 :
if ( V_6 -> V_132 . V_133 == V_134 ) {
F_3 ( V_6 , V_61 ,
V_135 ) ;
F_3 ( V_6 , V_128 ,
V_136 |
V_137 ) ;
F_3 ( V_6 , V_61 ,
V_135 | 0x1 ) ;
F_23 ( F_24 ( 400 ) ) ;
F_3 ( V_6 , V_61 ,
V_135 |
V_138 | 0x1 ) ;
F_3 ( V_6 , V_128 , 0 ) ;
F_3 ( V_6 , V_61 ,
V_138 | 0x1 ) ;
}
V_3 = F_5 ( V_6 , V_61 ) ;
F_3 ( V_6 , V_61 ,
( V_3 & V_62 ) |
V_138 | 0x1 ) ;
F_3 ( V_6 , V_139 ,
V_140 ) ;
F_3 ( V_6 , V_141 , 0 ) ;
break;
case V_134 :
V_3 = F_5 ( V_6 , V_61 ) ;
F_3 ( V_6 , V_61 ,
V_3 & V_135 ) ;
F_3 ( V_6 , V_128 ,
V_136 |
V_137 ) ;
F_3 ( V_6 , V_61 ,
V_135 ) ;
F_23 ( F_24 ( 500 ) ) ;
F_3 ( V_6 , V_14 , 0 ) ;
F_3 ( V_6 , V_128 , 0 ) ;
F_3 ( V_6 , V_61 , 0 ) ;
F_3 ( V_6 , V_139 , 0 ) ;
F_3 ( V_6 , V_141 , 0 ) ;
F_23 ( F_24 ( 1 ) ) ;
F_3 ( V_6 , V_139 ,
V_140 ) ;
break;
}
V_6 -> V_132 . V_133 = V_124 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_57 * V_58 = F_16 ( V_6 ) ;
int V_60 = V_58 -> V_60 ;
int V_59 = V_58 -> V_59 ;
int V_142 ;
V_142 = F_15 ( V_6 , 0 , 0 , 0 ) ;
if ( V_142 != 0 ) {
F_26 ( V_6 -> V_2 , L_6 ) ;
return V_142 ;
}
V_58 -> V_60 = V_60 ;
V_58 -> V_59 = V_59 ;
F_22 ( V_6 , V_134 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_57 * V_58 = F_16 ( V_6 ) ;
int V_142 ;
F_2 ( V_6 ) ;
V_142 = F_28 ( V_58 -> V_143 ) ;
if ( V_142 != 0 ) {
F_26 ( V_6 -> V_2 , L_7 , V_142 ) ;
return V_142 ;
}
F_22 ( V_6 , V_131 ) ;
if ( V_58 -> V_60 ) {
int V_60 = V_58 -> V_60 ;
int V_59 = V_58 -> V_59 ;
V_58 -> V_59 = 0 ;
V_58 -> V_60 = 0 ;
V_142 = F_15 ( V_6 , 0 , V_59 , V_60 ) ;
if ( V_142 != 0 ) {
F_26 ( V_6 -> V_2 , L_8 ) ;
return V_142 ;
}
}
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
int V_3 ;
V_3 = F_5 ( V_6 , V_4 ) ;
if ( V_3 != 0x8900 ) {
F_26 ( V_6 -> V_2 , L_9 , V_3 ) ;
return - V_144 ;
}
F_2 ( V_6 ) ;
F_22 ( V_6 , V_131 ) ;
F_17 ( V_6 , V_145 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_146 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_147 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_148 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_149 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_150 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_151 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_152 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_153 , 0x100 , 0x100 ) ;
F_17 ( V_6 , V_154 , 0x100 , 0x100 ) ;
F_3 ( V_6 , V_155 , 0x81 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
F_22 ( V_6 , V_134 ) ;
return 0 ;
}
static int F_31 ( struct V_156 * V_157 )
{
struct V_57 * V_58 ;
int V_142 ;
V_58 = F_32 ( & V_157 -> V_2 , sizeof( struct V_57 ) ,
V_158 ) ;
if ( V_58 == NULL )
return - V_159 ;
V_58 -> V_143 = F_33 ( V_157 , & V_160 ) ;
if ( F_34 ( V_58 -> V_143 ) )
return F_35 ( V_58 -> V_143 ) ;
F_36 ( V_157 , V_58 ) ;
V_142 = F_37 ( & V_157 -> V_2 ,
& V_161 , & V_162 , 1 ) ;
return V_142 ;
}
static int F_38 ( struct V_156 * V_157 )
{
F_39 ( & V_157 -> V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_163 * V_164 ,
const struct V_165 * V_166 )
{
struct V_57 * V_58 ;
int V_142 ;
V_58 = F_32 ( & V_164 -> V_2 , sizeof( struct V_57 ) ,
V_158 ) ;
if ( V_58 == NULL )
return - V_159 ;
V_58 -> V_143 = F_41 ( V_164 , & V_160 ) ;
if ( F_34 ( V_58 -> V_143 ) )
return F_35 ( V_58 -> V_143 ) ;
F_42 ( V_164 , V_58 ) ;
V_142 = F_37 ( & V_164 -> V_2 ,
& V_161 , & V_162 , 1 ) ;
return V_142 ;
}
static int F_43 ( struct V_163 * V_167 )
{
F_39 ( & V_167 -> V_2 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
int V_142 = 0 ;
#if F_45 ( V_168 )
V_142 = F_46 ( & V_169 ) ;
if ( V_142 != 0 ) {
F_13 ( V_47 L_10 ,
V_142 ) ;
}
#endif
#if F_47 ( V_170 )
V_142 = F_48 ( & V_171 ) ;
if ( V_142 != 0 ) {
F_13 ( V_47 L_11 ,
V_142 ) ;
}
#endif
return V_142 ;
}
static void T_4 F_49 ( void )
{
#if F_45 ( V_168 )
F_50 ( & V_169 ) ;
#endif
#if F_47 ( V_170 )
F_51 ( & V_171 ) ;
#endif
}
