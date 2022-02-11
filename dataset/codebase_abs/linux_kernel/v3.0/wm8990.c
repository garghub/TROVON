static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 =
(struct V_7 * ) V_2 -> V_9 ;
int V_10 = V_8 -> V_10 ;
int V_11 ;
T_1 V_12 ;
V_11 = F_3 ( V_2 , V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 = F_4 ( V_6 , V_10 ) ;
return F_5 ( V_6 , V_10 , V_12 | 0x0100 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_1 * V_2 , int V_15 )
{
T_1 V_10 , V_16 ;
V_10 = F_4 ( V_14 -> V_6 , V_17 ) ;
V_16 = F_4 ( V_14 -> V_6 , V_18 ) ;
if ( V_16 & ( ( 1 << V_19 ) |
( 1 << V_20 ) ) ) {
V_10 |= V_21 ;
} else {
V_10 &= ~ V_21 ;
}
if ( V_16 & ( ( 1 << V_22 ) |
( 1 << V_23 ) ) ) {
V_10 |= V_24 ;
} else {
V_10 &= ~ V_21 ;
}
F_5 ( V_14 -> V_6 , V_17 , V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_1 * V_2 , int V_15 )
{
T_2 V_25 = V_2 -> V_9 & 0xfff ;
int V_11 = 0 ;
T_1 V_10 ;
switch ( V_25 ) {
case V_26 | ( V_27 << 8 ) :
V_10 = F_4 ( V_14 -> V_6 , V_28 ) ;
if ( V_10 & V_29 ) {
F_8 ( V_30
L_1 ) ;
V_11 = - 1 ;
}
break;
case V_26 | ( V_31 << 8 ) :
V_10 = F_4 ( V_14 -> V_6 , V_32 ) ;
if ( V_10 & V_33 ) {
F_8 ( V_30
L_2 ) ;
V_11 = - 1 ;
}
break;
case V_28 | ( V_34 << 8 ) :
V_10 = F_4 ( V_14 -> V_6 , V_26 ) ;
if ( V_10 & V_35 ) {
F_8 ( V_30
L_3 ) ;
V_11 = - 1 ;
}
break;
case V_32 | ( V_36 << 8 ) :
V_10 = F_4 ( V_14 -> V_6 , V_26 ) ;
if ( V_10 & V_37 ) {
F_8 ( V_30
L_4 ) ;
V_11 = - 1 ;
}
break;
}
return V_11 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_38 * V_39 = & V_6 -> V_39 ;
F_10 ( V_39 , V_40 ,
F_11 ( V_40 ) ) ;
F_12 ( V_39 , V_41 , F_11 ( V_41 ) ) ;
return 0 ;
}
static void F_13 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned int V_45 )
{
T_3 V_46 ;
unsigned int V_47 , V_48 , V_49 ;
V_48 = V_44 / V_45 ;
if ( V_48 < 6 ) {
V_45 >>= 1 ;
V_43 -> V_50 = 1 ;
V_48 = V_44 / V_45 ;
} else
V_43 -> V_50 = 0 ;
if ( ( V_48 < 6 ) || ( V_48 > 12 ) )
F_8 ( V_30
L_5 , V_48 ) ;
V_43 -> V_51 = V_48 ;
V_49 = V_44 % V_45 ;
V_46 = V_52 * ( long long ) V_49 ;
F_14 ( V_46 , V_45 ) ;
V_47 = V_46 & 0xFFFFFFFF ;
if ( ( V_47 % 10 ) >= 5 )
V_47 += 5 ;
V_47 /= 10 ;
V_43 -> V_53 = V_47 ;
}
static int F_15 ( struct V_54 * V_55 , int V_56 ,
int V_45 , unsigned int V_57 , unsigned int V_58 )
{
T_1 V_10 ;
struct V_5 * V_6 = V_55 -> V_6 ;
struct V_42 V_43 ;
if ( V_57 && V_58 ) {
F_13 ( & V_43 , V_58 * 4 , V_57 ) ;
V_10 = F_4 ( V_6 , V_17 ) ;
V_10 |= V_59 ;
F_5 ( V_6 , V_17 , V_10 ) ;
V_10 = F_4 ( V_6 , V_60 ) ;
F_5 ( V_6 , V_60 , V_10 | V_61 ) ;
F_5 ( V_6 , V_62 , V_43 . V_51 | V_63 |
( V_43 . V_50 ? V_64 : 0 ) ) ;
F_5 ( V_6 , V_65 , ( V_66 ) ( V_43 . V_53 >> 8 ) ) ;
F_5 ( V_6 , V_67 , ( V_66 ) ( V_43 . V_53 & 0xFF ) ) ;
} else {
V_10 = F_4 ( V_6 , V_17 ) ;
V_10 &= ~ V_59 ;
F_5 ( V_6 , V_17 , V_10 ) ;
}
return 0 ;
}
static int F_16 ( struct V_54 * V_55 ,
int V_68 , unsigned int V_69 , int V_70 )
{
struct V_5 * V_6 = V_55 -> V_6 ;
struct V_71 * V_72 = F_17 ( V_6 ) ;
V_72 -> V_73 = V_69 ;
return 0 ;
}
static int F_18 ( struct V_54 * V_55 ,
unsigned int V_74 )
{
struct V_5 * V_6 = V_55 -> V_6 ;
T_1 V_75 , V_76 ;
V_75 = F_4 ( V_6 , V_77 ) ;
V_76 = F_4 ( V_6 , V_78 ) ;
switch ( V_74 & V_79 ) {
case V_80 :
V_76 &= ~ V_81 ;
break;
case V_82 :
V_76 |= V_81 ;
break;
default:
return - V_83 ;
}
V_75 &= ~ V_84 ;
switch ( V_74 & V_85 ) {
case V_86 :
V_75 |= V_87 ;
V_75 &= ~ V_88 ;
break;
case V_89 :
V_75 |= V_90 ;
V_75 &= ~ V_88 ;
break;
case V_91 :
V_75 |= V_92 ;
V_75 &= ~ V_88 ;
break;
case V_93 :
V_75 |= V_94 ;
V_75 &= ~ V_88 ;
break;
case V_95 :
V_75 |= V_94 | V_88 ;
break;
default:
return - V_83 ;
}
F_5 ( V_6 , V_77 , V_75 ) ;
F_5 ( V_6 , V_78 , V_76 ) ;
return 0 ;
}
static int F_19 ( struct V_54 * V_55 ,
int V_96 , int div )
{
struct V_5 * V_6 = V_55 -> V_6 ;
T_1 V_10 ;
switch ( V_96 ) {
case V_97 :
V_10 = F_4 ( V_6 , V_60 ) &
~ V_98 ;
F_5 ( V_6 , V_60 , V_10 | div ) ;
break;
case V_99 :
V_10 = F_4 ( V_6 , V_60 ) &
~ V_100 ;
F_5 ( V_6 , V_60 , V_10 | div ) ;
break;
case V_101 :
V_10 = F_4 ( V_6 , V_60 ) &
~ V_102 ;
F_5 ( V_6 , V_60 , V_10 | div ) ;
break;
case V_103 :
V_10 = F_4 ( V_6 , V_104 ) &
~ V_105 ;
F_5 ( V_6 , V_104 , V_10 | div ) ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static int F_20 ( struct V_106 * V_107 ,
struct V_108 * V_109 ,
struct V_54 * V_110 )
{
struct V_111 * V_112 = V_107 -> V_113 ;
struct V_5 * V_6 = V_112 -> V_6 ;
T_1 V_75 = F_4 ( V_6 , V_77 ) ;
V_75 &= ~ V_114 ;
switch ( F_21 ( V_109 ) ) {
case V_115 :
break;
case V_116 :
V_75 |= V_117 ;
break;
case V_118 :
V_75 |= V_119 ;
break;
case V_120 :
V_75 |= V_121 ;
break;
}
F_5 ( V_6 , V_77 , V_75 ) ;
return 0 ;
}
static int F_22 ( struct V_54 * V_110 , int V_122 )
{
struct V_5 * V_6 = V_110 -> V_6 ;
T_1 V_12 ;
V_12 = F_4 ( V_6 , V_123 ) & ~ V_124 ;
if ( V_122 )
F_5 ( V_6 , V_123 , V_12 | V_124 ) ;
else
F_5 ( V_6 , V_123 , V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
enum V_125 V_126 )
{
T_1 V_12 ;
switch ( V_126 ) {
case V_127 :
break;
case V_128 :
V_12 = F_4 ( V_6 , V_129 ) &
~ V_130 ;
F_5 ( V_6 , V_129 , V_12 | 0x2 ) ;
break;
case V_131 :
if ( V_6 -> V_39 . V_132 == V_133 ) {
F_5 ( V_6 , V_134 , V_135 |
V_136 | V_137 |
V_138 | V_139 |
V_140 ) ;
F_5 ( V_6 , V_141 , V_142 |
V_143 | V_144 |
V_145 ) ;
F_24 ( 300 ) ;
F_5 ( V_6 , V_141 , V_142 |
V_143 | V_144 ) ;
F_5 ( V_6 , V_134 , 0 ) ;
F_5 ( V_6 , V_129 , 0x1b00 ) ;
F_24 ( 50 ) ;
F_5 ( V_6 , V_129 , 0x1f02 ) ;
F_24 ( 100 ) ;
F_5 ( V_6 , V_129 , 0x1f03 ) ;
F_24 ( 600 ) ;
F_5 ( V_6 , V_141 , V_142 |
V_143 | V_144 |
V_146 ) ;
F_5 ( V_6 , V_129 , 0x3 ) ;
F_5 ( V_6 , V_141 , V_146 ) ;
F_5 ( V_6 , V_147 , 0x2 ) ;
F_5 ( V_6 , V_148 , 0xa003 ) ;
F_5 ( V_6 , V_147 , 0 ) ;
}
V_12 = F_4 ( V_6 , V_129 ) &
~ V_130 ;
F_5 ( V_6 , V_129 , V_12 | 0x4 ) ;
break;
case V_133 :
F_5 ( V_6 , V_141 , V_142 |
V_144 | V_146 ) ;
F_5 ( V_6 , V_141 , V_142 |
V_143 | V_144 |
V_146 ) ;
V_12 = F_4 ( V_6 , V_123 ) ;
F_5 ( V_6 , V_123 , V_12 | V_124 ) ;
F_5 ( V_6 , V_129 , 0x1f03 ) ;
F_5 ( V_6 , V_129 , 0x1f01 ) ;
F_24 ( 300 ) ;
F_5 ( V_6 , V_134 , V_135 |
V_136 | V_137 |
V_138 | V_139 |
V_140 ) ;
F_5 ( V_6 , V_129 , 0x0 ) ;
F_5 ( V_6 , V_141 , 0x0 ) ;
break;
}
V_6 -> V_39 . V_132 = V_126 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , T_4 V_149 )
{
F_23 ( V_6 , V_133 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
int V_150 ;
V_66 V_151 [ 2 ] ;
T_1 * V_152 = V_6 -> V_153 ;
for ( V_150 = 0 ; V_150 < F_11 ( V_154 ) ; V_150 ++ ) {
if ( V_150 + 1 == V_155 )
continue;
V_151 [ 0 ] = ( ( V_150 + 1 ) << 1 ) | ( ( V_152 [ V_150 ] >> 8 ) & 0x0001 ) ;
V_151 [ 1 ] = V_152 [ V_150 ] & 0x00ff ;
V_6 -> V_156 ( V_6 -> V_157 , V_151 , 2 ) ;
}
F_23 ( V_6 , V_131 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
int V_11 ;
T_1 V_10 ;
V_11 = F_28 ( V_6 , 8 , 16 , V_158 ) ;
if ( V_11 < 0 ) {
F_8 ( V_159 L_6 , V_11 ) ;
return V_11 ;
}
F_29 ( V_6 ) ;
F_23 ( V_6 , V_131 ) ;
V_10 = F_4 ( V_6 , V_160 ) ;
F_5 ( V_6 , V_160 , V_10 | V_161 ) ;
V_10 = F_4 ( V_6 , V_162 ) &
~ V_163 ;
F_5 ( V_6 , V_162 , V_10 | 1 ) ;
V_10 = F_4 ( V_6 , V_17 ) ;
F_5 ( V_6 , V_17 , V_10 | V_164 ) ;
F_5 ( V_6 , V_165 , 0x50 | ( 1 << 8 ) ) ;
F_5 ( V_6 , V_166 , 0x50 | ( 1 << 8 ) ) ;
F_30 ( V_6 , V_167 ,
F_11 ( V_167 ) ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
F_23 ( V_6 , V_133 ) ;
return 0 ;
}
static T_5 int F_32 ( struct V_168 * V_169 ,
const struct V_170 * V_171 )
{
struct V_71 * V_72 ;
int V_11 ;
V_72 = F_33 ( sizeof( struct V_71 ) , V_172 ) ;
if ( V_72 == NULL )
return - V_173 ;
F_34 ( V_169 , V_72 ) ;
V_11 = F_35 ( & V_169 -> V_174 ,
& V_175 , & V_176 , 1 ) ;
if ( V_11 < 0 )
F_36 ( V_72 ) ;
return V_11 ;
}
static T_6 int F_37 ( struct V_168 * V_177 )
{
F_38 ( & V_177 -> V_174 ) ;
F_36 ( F_39 ( V_177 ) ) ;
return 0 ;
}
static int T_7 F_40 ( void )
{
int V_11 = 0 ;
#if F_41 ( V_178 ) || F_41 ( V_179 )
V_11 = F_42 ( & V_180 ) ;
if ( V_11 != 0 ) {
F_8 ( V_159 L_7 ,
V_11 ) ;
}
#endif
return V_11 ;
}
static void T_8 F_43 ( void )
{
#if F_41 ( V_178 ) || F_41 ( V_179 )
F_44 ( & V_180 ) ;
#endif
}
