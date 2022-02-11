static inline unsigned int
F_1 ( struct V_1 * V_2 )
{
return ( unsigned int ) ( V_3 ) V_2 -> V_4 -> V_5 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_4 = V_2 -> V_4 ;
int V_10 ;
V_4 -> V_5 = ( void * ) ( V_3 ) V_6 ;
if ( V_6 == V_11 && V_8 -> V_12 &&
( V_8 -> V_13 . V_14 & V_15 ) )
V_4 -> V_16 = V_17 ;
else
V_4 -> V_16 = * V_18 [ V_6 ] ;
switch ( V_6 ) {
case V_19 :
V_4 -> V_16 . V_20 &= ~ ( V_21 |
V_22 ) ;
V_4 -> V_16 . V_23 = 44100 ;
break;
case V_24 :
V_4 -> V_16 . V_25 = V_8 -> V_13 . V_26 ;
break;
}
if ( V_8 -> V_13 . V_27 )
V_8 -> V_13 . V_27 ( V_6 , & V_4 -> V_16 ) ;
V_10 = F_4 ( V_4 , 0 ,
V_28 , 32 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_4 ( V_4 , 0 ,
V_29 , 32 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_4 -> V_16 . V_30 & V_31 ) {
V_10 = F_5 ( V_4 , 0 , 32 , 24 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_4 -> V_16 . V_25 > 2 ) {
V_10 = F_4 ( V_4 , 0 ,
V_32 ,
2 ) ;
if ( V_10 < 0 )
return V_10 ;
}
F_6 ( V_2 ) ;
V_8 -> V_33 [ V_6 ] = V_2 ;
F_7 ( & V_8 -> V_34 ) ;
V_8 -> V_35 |= 1 << V_6 ;
if ( V_6 == V_36 ) {
V_8 -> V_37 = V_8 -> V_38 ;
V_8 -> V_39 [ V_40 ] -> V_41 [ 0 ] . V_42 &=
~ V_43 ;
F_8 ( V_8 -> V_44 , V_45 |
V_46 ,
& V_8 -> V_39 [ V_40 ] -> V_47 ) ;
}
F_9 ( & V_8 -> V_34 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_48 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_11 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_19 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_36 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_24 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_49 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
F_7 ( & V_8 -> V_34 ) ;
V_8 -> V_35 &= ~ ( 1 << V_6 ) ;
if ( V_6 == V_36 ) {
V_8 -> V_39 [ V_40 ] -> V_41 [ 0 ] . V_42 |=
V_43 ;
F_8 ( V_8 -> V_44 , V_45 |
V_46 ,
& V_8 -> V_39 [ V_40 ] -> V_47 ) ;
}
if ( V_6 == V_36 || V_6 == V_24 )
F_17 ( V_8 ) ;
F_9 ( & V_8 -> V_34 ) ;
V_8 -> V_33 [ V_6 ] = NULL ;
return 0 ;
}
static unsigned int F_18 ( struct V_50 * V_51 )
{
if ( F_19 ( V_51 ) == V_52 )
return V_53 ;
else
return V_54 ;
}
static unsigned int F_20 ( struct V_50 * V_51 )
{
switch ( F_21 ( V_51 ) ) {
case 32000 :
return V_55 ;
case 44100 :
return V_56 ;
default:
return V_57 ;
case 64000 :
return V_58 ;
case 88200 :
return V_59 ;
case 96000 :
return V_60 ;
case 176400 :
return V_61 ;
case 192000 :
return V_62 ;
}
}
static unsigned int F_22 ( struct V_50 * V_51 )
{
if ( F_19 ( V_51 ) == V_52 )
return V_63 ;
else
return V_64 ;
}
static unsigned int F_23 ( struct V_50 * V_51 )
{
switch ( F_24 ( V_51 ) ) {
default:
return V_65 ;
case 4 :
return V_66 ;
case 6 :
return V_67 ;
case 8 :
return V_68 ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
int V_10 ;
V_10 = F_26 ( V_2 ,
F_27 ( V_51 ) ) ;
if ( V_10 < 0 )
return V_10 ;
F_28 ( V_8 , V_69 [ V_6 ] ,
( V_70 ) V_2 -> V_4 -> V_71 ) ;
if ( V_6 == V_24 ) {
F_28 ( V_8 , V_72 ,
F_27 ( V_51 ) / 4 - 1 ) ;
F_28 ( V_8 , V_73 ,
F_29 ( V_51 ) / 4 - 1 ) ;
} else {
F_30 ( V_8 , V_69 [ V_6 ] + 4 ,
F_27 ( V_51 ) / 4 - 1 ) ;
F_30 ( V_8 , V_69 [ V_6 ] + 6 ,
F_29 ( V_51 ) / 4 - 1 ) ;
}
return 0 ;
}
static T_1 F_31 ( struct V_7 * V_8 , unsigned int V_6 ,
struct V_50 * V_74 )
{
unsigned int V_75 , V_76 ;
if ( V_6 == V_24 )
V_75 = V_8 -> V_13 . V_77 ;
else
V_75 = V_8 -> V_13 . V_78 ;
if ( F_21 ( V_74 ) <= 48000 )
V_76 = 0 ;
else if ( F_21 ( V_74 ) <= 96000 )
V_76 = 2 ;
else
V_76 = 4 ;
return F_32 ( V_75 >> V_76 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_25 ( V_2 , V_51 ) ;
if ( V_10 < 0 )
return V_10 ;
F_34 ( & V_8 -> V_79 ) ;
F_35 ( V_8 , V_80 ,
F_18 ( V_51 ) << V_81 ,
V_82 ) ;
F_36 ( V_8 , V_83 ,
F_20 ( V_51 ) |
V_8 -> V_13 . V_84 |
F_31 ( V_8 , V_48 , V_51 ) |
F_22 ( V_51 ) ,
V_85 |
V_86 |
V_87 |
V_88 ) ;
F_37 ( & V_8 -> V_79 ) ;
F_7 ( & V_8 -> V_34 ) ;
V_8 -> V_13 . V_89 ( V_8 , V_51 ) ;
F_9 ( & V_8 -> V_34 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_90 ;
int V_10 ;
V_10 = F_25 ( V_2 , V_51 ) ;
if ( V_10 < 0 )
return V_10 ;
V_90 = V_8 -> V_12 &&
( V_8 -> V_13 . V_14 & V_15 ) ;
F_34 ( & V_8 -> V_79 ) ;
F_35 ( V_8 , V_80 ,
F_18 ( V_51 ) << V_91 ,
V_92 ) ;
if ( ! V_90 )
F_36 ( V_8 , V_93 ,
F_20 ( V_51 ) |
V_8 -> V_13 . V_84 |
F_31 ( V_8 , V_11 , V_51 ) |
F_22 ( V_51 ) ,
V_85 |
V_86 |
V_87 |
V_88 ) ;
F_37 ( & V_8 -> V_79 ) ;
if ( ! V_90 ) {
F_7 ( & V_8 -> V_34 ) ;
V_8 -> V_13 . V_89 ( V_8 , V_51 ) ;
F_9 ( & V_8 -> V_34 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_25 ( V_2 , V_51 ) ;
if ( V_10 < 0 )
return V_10 ;
F_34 ( & V_8 -> V_79 ) ;
F_35 ( V_8 , V_80 ,
F_18 ( V_51 ) << V_94 ,
V_95 ) ;
F_37 ( & V_8 -> V_79 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_25 ( V_2 , V_51 ) ;
if ( V_10 < 0 )
return V_10 ;
F_7 ( & V_8 -> V_34 ) ;
F_34 ( & V_8 -> V_79 ) ;
F_41 ( V_8 , V_96 ,
V_97 ) ;
F_35 ( V_8 , V_98 ,
F_18 ( V_51 ) << V_99 ,
V_100 ) ;
F_42 ( V_8 , V_96 ,
F_20 ( V_51 ) << V_101 ,
V_102 ) ;
F_17 ( V_8 ) ;
F_37 ( & V_8 -> V_79 ) ;
F_9 ( & V_8 -> V_34 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_25 ( V_2 , V_51 ) ;
if ( V_10 < 0 )
return V_10 ;
F_7 ( & V_8 -> V_34 ) ;
F_34 ( & V_8 -> V_79 ) ;
F_35 ( V_8 , V_103 ,
F_23 ( V_51 ) ,
V_104 ) ;
F_35 ( V_8 , V_98 ,
F_18 ( V_51 ) << V_105 ,
V_106 ) ;
F_36 ( V_8 , V_107 ,
F_20 ( V_51 ) |
V_8 -> V_13 . V_108 |
F_31 ( V_8 , V_24 , V_51 ) |
F_22 ( V_51 ) ,
V_85 |
V_86 |
V_87 |
V_88 ) ;
F_17 ( V_8 ) ;
F_37 ( & V_8 -> V_79 ) ;
V_8 -> V_13 . V_109 ( V_8 , V_51 ) ;
F_44 ( V_8 ) ;
F_9 ( & V_8 -> V_34 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
unsigned int V_110 = 1 << V_6 ;
F_34 ( & V_8 -> V_79 ) ;
V_8 -> V_111 &= ~ V_110 ;
F_30 ( V_8 , V_112 , V_8 -> V_111 ) ;
F_46 ( V_8 , V_113 , V_110 ) ;
F_47 ( V_8 , V_113 , V_110 ) ;
F_37 ( & V_8 -> V_79 ) ;
return F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
F_34 ( & V_8 -> V_79 ) ;
F_41 ( V_8 , V_96 ,
V_97 ) ;
F_37 ( & V_8 -> V_79 ) ;
return F_45 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
unsigned int V_110 = 1 << V_6 ;
F_34 ( & V_8 -> V_79 ) ;
F_46 ( V_8 , V_113 , V_110 ) ;
F_47 ( V_8 , V_113 , V_110 ) ;
if ( V_2 -> V_4 -> V_114 )
V_8 -> V_111 &= ~ V_110 ;
else
V_8 -> V_111 |= V_110 ;
F_30 ( V_8 , V_112 , V_8 -> V_111 ) ;
F_37 ( & V_8 -> V_79 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , int V_115 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_1 * V_116 ;
unsigned int V_117 = 0 ;
int V_118 ;
switch ( V_115 ) {
case V_119 :
case V_120 :
case V_121 :
V_118 = 0 ;
break;
case V_122 :
case V_123 :
V_118 = 1 ;
break;
default:
return - V_124 ;
}
F_52 (s, substream) {
if ( F_3 ( V_116 ) == V_8 ) {
V_117 |= 1 << F_1 ( V_116 ) ;
F_53 ( V_116 , V_2 ) ;
}
}
F_54 ( & V_8 -> V_79 ) ;
if ( ! V_118 ) {
if ( V_115 == V_120 )
V_8 -> V_125 |= V_117 ;
else
V_8 -> V_125 &= ~ V_117 ;
F_55 ( V_8 , V_126 , V_8 -> V_125 ) ;
} else {
if ( V_115 == V_122 )
F_46 ( V_8 , V_127 , V_117 ) ;
else
F_47 ( V_8 , V_127 , V_117 ) ;
}
F_56 ( & V_8 -> V_79 ) ;
return 0 ;
}
static T_2 F_57 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_4 = V_2 -> V_4 ;
unsigned int V_6 = F_1 ( V_2 ) ;
V_70 V_128 ;
V_128 = F_58 ( V_8 , V_69 [ V_6 ] ) ;
return F_59 ( V_4 , V_128 - ( V_70 ) V_4 -> V_71 ) ;
}
static void F_60 ( struct V_129 * V_130 )
{
F_61 ( V_130 ) ;
}
int F_62 ( struct V_7 * V_8 )
{
struct V_129 * V_130 ;
int V_131 , V_132 ;
int V_10 ;
V_131 = ! ! ( V_8 -> V_13 . V_14 & V_133 ) ;
V_132 = ! ! ( V_8 -> V_13 . V_14 & ( V_134 |
V_135 ) ) ;
if ( V_131 | V_132 ) {
V_10 = F_63 ( V_8 -> V_44 , L_1 ,
0 , V_131 , V_132 , & V_130 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_131 )
F_64 ( V_130 , V_136 ,
& V_137 ) ;
if ( V_8 -> V_13 . V_14 & V_134 )
F_64 ( V_130 , V_138 ,
& V_139 ) ;
else if ( V_8 -> V_13 . V_14 & V_135 )
F_64 ( V_130 , V_138 ,
& V_140 ) ;
V_130 -> V_5 = V_8 ;
V_130 -> V_141 = F_60 ;
strcpy ( V_130 -> V_142 , L_1 ) ;
if ( V_131 )
F_65 ( V_130 -> V_33 [ V_136 ] . V_2 ,
V_143 ,
F_66 ( V_8 -> V_144 ) ,
V_145 ,
V_146 ) ;
if ( V_132 )
F_65 ( V_130 -> V_33 [ V_138 ] . V_2 ,
V_143 ,
F_66 ( V_8 -> V_144 ) ,
V_147 ,
V_148 ) ;
}
V_131 = ! ! ( V_8 -> V_13 . V_14 & V_149 ) ;
V_132 = ! ! ( V_8 -> V_13 . V_14 & V_150 ) ;
if ( V_131 | V_132 ) {
V_10 = F_63 ( V_8 -> V_44 , L_2 , 1 , V_131 , V_132 , & V_130 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_131 )
F_64 ( V_130 , V_136 ,
& V_151 ) ;
if ( V_132 )
F_64 ( V_130 , V_138 ,
& V_152 ) ;
V_130 -> V_5 = V_8 ;
V_130 -> V_141 = F_60 ;
strcpy ( V_130 -> V_142 , L_2 ) ;
F_67 ( V_130 , V_143 ,
F_66 ( V_8 -> V_144 ) ,
V_147 ,
V_148 ) ;
}
if ( V_8 -> V_12 ) {
V_131 = ! ! ( V_8 -> V_13 . V_14 & V_153 ) ;
V_132 = ! ! ( V_8 -> V_13 . V_14 & V_15 ) ;
} else {
V_131 = 0 ;
V_132 = ! ! ( V_8 -> V_13 . V_14 & V_154 ) ;
}
if ( V_131 | V_132 ) {
V_10 = F_63 ( V_8 -> V_44 , V_131 ? L_3 : L_4 ,
2 , V_131 , V_132 , & V_130 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_131 ) {
F_64 ( V_130 , V_136 ,
& V_155 ) ;
F_35 ( V_8 , V_156 ,
V_157 ,
V_158 ) ;
}
if ( V_132 )
F_64 ( V_130 , V_138 ,
& V_140 ) ;
V_130 -> V_5 = V_8 ;
V_130 -> V_141 = F_60 ;
strcpy ( V_130 -> V_142 , V_131 ? L_5 : L_6 ) ;
F_67 ( V_130 , V_143 ,
F_66 ( V_8 -> V_144 ) ,
V_147 ,
V_148 ) ;
}
return 0 ;
}
