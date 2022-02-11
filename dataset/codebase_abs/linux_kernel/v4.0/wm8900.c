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
struct V_5 * V_6 = F_5 ( V_9 -> V_13 ) ;
T_1 V_14 = F_6 ( V_6 , V_15 ) ;
switch ( V_12 ) {
case V_16 :
V_14 = V_17 |
V_18 ;
F_3 ( V_6 , V_15 , V_14 ) ;
break;
case V_19 :
V_14 &= ~ V_17 ;
V_14 |= V_20 |
V_21 |
V_22 ;
F_3 ( V_6 , V_15 , V_14 ) ;
F_7 ( 400 ) ;
V_14 &= ~ V_18 ;
V_14 |= V_23 ;
F_3 ( V_6 , V_15 , V_14 ) ;
V_14 &= ~ V_21 ;
F_3 ( V_6 , V_15 , V_14 ) ;
V_14 &= ~ V_20 ;
F_3 ( V_6 , V_15 , V_14 ) ;
break;
case V_24 :
V_14 |= V_20 ;
F_3 ( V_6 , V_15 , V_14 ) ;
V_14 &= ~ V_23 ;
F_3 ( V_6 , V_15 , V_14 ) ;
V_14 |= V_17 |
V_18 ;
V_14 &= ~ V_22 ;
F_3 ( V_6 , V_15 , V_14 ) ;
break;
case V_25 :
F_3 ( V_6 , V_15 , 0 ) ;
break;
default:
F_8 ( 1 , L_1 , V_12 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_31 -> V_6 ;
T_1 V_3 ;
V_3 = F_6 ( V_6 , V_32 ) & ~ 0x60 ;
switch ( F_10 ( V_29 ) ) {
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
return - V_33 ;
}
F_3 ( V_6 , V_32 , V_3 ) ;
if ( V_27 -> V_34 == V_35 ) {
V_3 = F_6 ( V_6 , V_36 ) ;
if ( F_11 ( V_29 ) <= 24000 )
V_3 |= V_37 ;
else
V_3 &= ~ V_37 ;
F_3 ( V_6 , V_36 , V_3 ) ;
}
return 0 ;
}
static int F_12 ( struct V_38 * V_39 , unsigned int V_40 ,
unsigned int V_41 )
{
T_2 V_42 ;
unsigned int V_43 , V_44 , V_45 , V_46 ;
unsigned int div ;
if ( F_13 ( ! V_41 ) )
return - V_33 ;
V_46 = V_41 ;
div = 1 ;
while ( V_46 < 90000000 ) {
div *= 2 ;
V_46 *= 2 ;
}
if ( V_46 > 100000000 )
F_14 ( V_47 L_2
L_3 , V_46 , V_40 , V_41 ) ;
if ( div > 32 ) {
F_14 ( V_48 L_4
L_5 ,
div , V_40 , V_41 , V_46 ) ;
return - V_33 ;
}
V_39 -> V_49 = div >> 2 ;
if ( V_40 < 48000 )
V_39 -> V_50 = 1 ;
else
V_39 -> V_50 = 0 ;
V_44 = V_46 / V_40 ;
if ( V_40 < 1000000 )
V_39 -> V_51 = 8 ;
else
V_39 -> V_51 = 1 ;
V_39 -> V_52 = V_44 / V_39 -> V_51 ;
V_45 = ( V_46 / V_39 -> V_51 ) % V_40 ;
V_42 = V_53 * ( long long ) V_45 ;
F_15 ( V_42 , V_40 ) ;
V_43 = V_42 & 0xFFFFFFFF ;
if ( ( V_43 % 10 ) >= 5 )
V_43 += 5 ;
V_39 -> V_54 = V_43 / 10 ;
if ( F_13 ( V_46 != V_41 * ( V_39 -> V_49 << 2 ) ) ||
F_13 ( ! V_43 && V_46 != V_40 * V_39 -> V_51 * V_39 -> V_52 ) )
return - V_33 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
int V_55 , unsigned int V_56 , unsigned int V_57 )
{
struct V_58 * V_59 = F_17 ( V_6 ) ;
struct V_38 V_39 ;
if ( V_59 -> V_60 == V_56 && V_59 -> V_61 == V_57 )
return 0 ;
F_18 ( V_6 , V_62 ,
V_63 , 0 ) ;
if ( ! V_56 || ! V_57 ) {
F_18 ( V_6 , V_64 ,
V_65 , 0 ) ;
F_18 ( V_6 , V_66 ,
V_67 , 0 ) ;
V_59 -> V_60 = V_56 ;
V_59 -> V_61 = V_57 ;
return 0 ;
}
if ( F_12 ( & V_39 , V_56 , V_57 ) != 0 )
goto V_68;
V_59 -> V_60 = V_56 ;
V_59 -> V_61 = V_57 ;
F_3 ( V_6 , V_66 ,
V_39 . V_51 | V_67 ) ;
F_3 ( V_6 , V_69 , V_39 . V_52 >> 5 ) ;
F_3 ( V_6 , V_70 ,
( V_39 . V_49 << 6 ) | ( V_39 . V_52 & 0x1f ) ) ;
if ( V_39 . V_54 ) {
F_3 ( V_6 , V_71 ,
( V_39 . V_54 >> 8 ) | 0x100 ) ;
F_3 ( V_6 , V_72 , V_39 . V_54 & 0xff ) ;
} else
F_3 ( V_6 , V_71 , 0 ) ;
if ( V_39 . V_50 )
F_3 ( V_6 , V_73 ,
V_74 ) ;
else
F_3 ( V_6 , V_73 , 0 ) ;
F_18 ( V_6 , V_62 ,
V_63 ,
V_63 ) ;
V_68:
F_18 ( V_6 , V_64 ,
V_65 ,
V_65 ) ;
return 0 ;
}
static int F_19 ( struct V_30 * V_75 , int V_76 ,
int V_77 , unsigned int V_56 , unsigned int V_57 )
{
return F_16 ( V_75 -> V_6 , V_76 , V_56 , V_57 ) ;
}
static int F_20 ( struct V_30 * V_75 ,
int V_78 , int div )
{
struct V_5 * V_6 = V_75 -> V_6 ;
switch ( V_78 ) {
case V_79 :
F_18 ( V_6 , V_64 ,
V_80 , div ) ;
break;
case V_81 :
F_18 ( V_6 , V_64 ,
V_82 , div ) ;
break;
case V_83 :
F_18 ( V_6 , V_84 ,
V_85 , div ) ;
break;
case V_86 :
F_18 ( V_6 , V_87 ,
V_85 , div ) ;
break;
case V_88 :
F_18 ( V_6 , V_89 ,
V_90 , div ) ;
break;
case V_91 :
F_18 ( V_6 , V_89 ,
V_92 , div ) ;
break;
case V_93 :
F_18 ( V_6 , V_36 ,
V_94 , div ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_21 ( struct V_30 * V_75 ,
unsigned int V_95 )
{
struct V_5 * V_6 = V_75 -> V_6 ;
unsigned int V_96 , V_97 , V_98 , V_99 ;
V_96 = F_6 ( V_6 , V_64 ) ;
V_97 = F_6 ( V_6 , V_32 ) ;
V_98 = F_6 ( V_6 , V_87 ) ;
V_99 = F_6 ( V_6 , V_84 ) ;
switch ( V_95 & V_100 ) {
case V_101 :
V_96 &= ~ V_102 ;
V_98 &= ~ V_103 ;
V_99 &= ~ V_104 ;
break;
case V_105 :
V_96 &= ~ V_102 ;
V_98 |= V_103 ;
V_99 |= V_104 ;
break;
case V_106 :
V_96 |= V_102 ;
V_98 |= V_103 ;
V_99 |= V_104 ;
break;
case V_107 :
V_96 |= V_102 ;
V_98 &= ~ V_103 ;
V_99 &= ~ V_104 ;
break;
default:
return - V_33 ;
}
switch ( V_95 & V_108 ) {
case V_109 :
V_97 |= V_110 ;
V_97 &= ~ V_111 ;
break;
case V_112 :
V_97 |= V_110 ;
V_97 |= V_111 ;
break;
case V_113 :
V_97 &= ~ V_110 ;
V_97 |= 0x10 ;
break;
case V_114 :
V_97 &= ~ V_110 ;
break;
case V_115 :
V_97 &= ~ V_110 ;
V_97 |= 0x8 ;
break;
default:
return - V_33 ;
}
switch ( V_95 & V_108 ) {
case V_109 :
case V_112 :
switch ( V_95 & V_116 ) {
case V_117 :
V_97 &= ~ V_118 ;
break;
case V_119 :
V_97 |= V_118 ;
break;
default:
return - V_33 ;
}
break;
case V_113 :
case V_114 :
case V_115 :
switch ( V_95 & V_116 ) {
case V_117 :
V_97 &= ~ V_118 ;
V_97 &= ~ V_111 ;
break;
case V_120 :
V_97 |= V_118 ;
V_97 |= V_111 ;
break;
case V_119 :
V_97 |= V_118 ;
V_97 &= ~ V_111 ;
break;
case V_121 :
V_97 &= ~ V_118 ;
V_97 |= V_111 ;
break;
default:
return - V_33 ;
}
break;
default:
return - V_33 ;
}
F_3 ( V_6 , V_64 , V_96 ) ;
F_3 ( V_6 , V_32 , V_97 ) ;
F_3 ( V_6 , V_87 , V_98 ) ;
F_3 ( V_6 , V_84 , V_99 ) ;
return 0 ;
}
static int F_22 ( struct V_30 * V_75 , int V_122 )
{
struct V_5 * V_6 = V_75 -> V_6 ;
T_1 V_3 ;
V_3 = F_6 ( V_6 , V_36 ) ;
if ( V_122 )
V_3 |= V_123 ;
else
V_3 &= ~ V_123 ;
F_3 ( V_6 , V_36 , V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
enum V_124 V_125 )
{
T_1 V_3 ;
switch ( V_125 ) {
case V_126 :
F_18 ( V_6 , V_127 ,
V_128 ,
V_128 ) ;
F_18 ( V_6 , V_129 ,
V_130 ,
V_130 ) ;
break;
case V_131 :
break;
case V_132 :
if ( V_6 -> V_13 . V_133 == V_134 ) {
F_3 ( V_6 , V_62 ,
V_135 ) ;
F_3 ( V_6 , V_129 ,
V_136 |
V_137 ) ;
F_3 ( V_6 , V_62 ,
V_135 | 0x1 ) ;
F_24 ( F_25 ( 400 ) ) ;
F_3 ( V_6 , V_62 ,
V_135 |
V_138 | 0x1 ) ;
F_3 ( V_6 , V_129 , 0 ) ;
F_3 ( V_6 , V_62 ,
V_138 | 0x1 ) ;
}
V_3 = F_6 ( V_6 , V_62 ) ;
F_3 ( V_6 , V_62 ,
( V_3 & V_63 ) |
V_138 | 0x1 ) ;
F_3 ( V_6 , V_139 ,
V_140 ) ;
F_3 ( V_6 , V_141 , 0 ) ;
break;
case V_134 :
V_3 = F_6 ( V_6 , V_62 ) ;
F_3 ( V_6 , V_62 ,
V_3 & V_135 ) ;
F_3 ( V_6 , V_129 ,
V_136 |
V_137 ) ;
F_3 ( V_6 , V_62 ,
V_135 ) ;
F_24 ( F_25 ( 500 ) ) ;
F_3 ( V_6 , V_15 , 0 ) ;
F_3 ( V_6 , V_129 , 0 ) ;
F_3 ( V_6 , V_62 , 0 ) ;
F_3 ( V_6 , V_139 , 0 ) ;
F_3 ( V_6 , V_141 , 0 ) ;
F_24 ( F_25 ( 1 ) ) ;
F_3 ( V_6 , V_139 ,
V_140 ) ;
break;
}
V_6 -> V_13 . V_133 = V_125 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_58 * V_59 = F_17 ( V_6 ) ;
int V_61 = V_59 -> V_61 ;
int V_60 = V_59 -> V_60 ;
int V_142 ;
V_142 = F_16 ( V_6 , 0 , 0 , 0 ) ;
if ( V_142 != 0 ) {
F_27 ( V_6 -> V_2 , L_6 ) ;
return V_142 ;
}
V_59 -> V_61 = V_61 ;
V_59 -> V_60 = V_60 ;
F_23 ( V_6 , V_134 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_58 * V_59 = F_17 ( V_6 ) ;
int V_142 ;
F_2 ( V_6 ) ;
V_142 = F_29 ( V_59 -> V_143 ) ;
if ( V_142 != 0 ) {
F_27 ( V_6 -> V_2 , L_7 , V_142 ) ;
return V_142 ;
}
F_23 ( V_6 , V_132 ) ;
if ( V_59 -> V_61 ) {
int V_61 = V_59 -> V_61 ;
int V_60 = V_59 -> V_60 ;
V_59 -> V_60 = 0 ;
V_59 -> V_61 = 0 ;
V_142 = F_16 ( V_6 , 0 , V_60 , V_61 ) ;
if ( V_142 != 0 ) {
F_27 ( V_6 -> V_2 , L_8 ) ;
return V_142 ;
}
}
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
int V_3 ;
V_3 = F_6 ( V_6 , V_4 ) ;
if ( V_3 != 0x8900 ) {
F_27 ( V_6 -> V_2 , L_9 , V_3 ) ;
return - V_144 ;
}
F_2 ( V_6 ) ;
F_23 ( V_6 , V_132 ) ;
F_18 ( V_6 , V_145 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_146 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_147 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_148 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_149 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_150 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_151 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_152 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_153 , 0x100 , 0x100 ) ;
F_18 ( V_6 , V_154 , 0x100 , 0x100 ) ;
F_3 ( V_6 , V_155 , 0x81 ) ;
return 0 ;
}
static int F_31 ( struct V_156 * V_157 )
{
struct V_58 * V_59 ;
int V_142 ;
V_59 = F_32 ( & V_157 -> V_2 , sizeof( struct V_58 ) ,
V_158 ) ;
if ( V_59 == NULL )
return - V_159 ;
V_59 -> V_143 = F_33 ( V_157 , & V_160 ) ;
if ( F_34 ( V_59 -> V_143 ) )
return F_35 ( V_59 -> V_143 ) ;
F_36 ( V_157 , V_59 ) ;
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
struct V_58 * V_59 ;
int V_142 ;
V_59 = F_32 ( & V_164 -> V_2 , sizeof( struct V_58 ) ,
V_158 ) ;
if ( V_59 == NULL )
return - V_159 ;
V_59 -> V_143 = F_41 ( V_164 , & V_160 ) ;
if ( F_34 ( V_59 -> V_143 ) )
return F_35 ( V_59 -> V_143 ) ;
F_42 ( V_164 , V_59 ) ;
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
F_14 ( V_48 L_10 ,
V_142 ) ;
}
#endif
#if F_47 ( V_170 )
V_142 = F_48 ( & V_171 ) ;
if ( V_142 != 0 ) {
F_14 ( V_48 L_11 ,
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
