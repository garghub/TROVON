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
if ( V_8 -> V_13 . V_14 & V_20 ) {
V_4 -> V_16 . V_21 &= ~ ( V_22 |
V_23 ) ;
V_4 -> V_16 . V_24 = 44100 ;
}
case V_25 :
case V_11 :
V_4 -> V_16 . V_26 = 0 ;
break;
case V_27 :
V_4 -> V_16 . V_28 = V_8 -> V_13 . V_29 ;
break;
}
if ( V_8 -> V_13 . V_30 )
V_8 -> V_13 . V_30 ( V_6 , & V_4 -> V_16 ) ;
V_10 = F_4 ( V_4 , 0 ,
V_31 , 32 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_4 ( V_4 , 0 ,
V_32 , 32 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_4 -> V_16 . V_33 & V_34 ) {
V_10 = F_5 ( V_4 , 0 , 32 , 24 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_4 -> V_16 . V_28 > 2 ) {
V_10 = F_4 ( V_4 , 0 ,
V_35 ,
2 ) ;
if ( V_10 < 0 )
return V_10 ;
}
F_6 ( V_2 ) ;
V_8 -> V_36 [ V_6 ] = V_2 ;
F_7 ( & V_8 -> V_37 ) ;
V_8 -> V_38 |= 1 << V_6 ;
if ( V_6 == V_39 ) {
V_8 -> V_40 = V_8 -> V_41 ;
V_8 -> V_42 [ V_43 ] -> V_44 [ 0 ] . V_45 &=
~ V_46 ;
F_8 ( V_8 -> V_47 , V_48 |
V_49 ,
& V_8 -> V_42 [ V_43 ] -> V_50 ) ;
}
F_9 ( & V_8 -> V_37 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_25 ) ;
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
return F_2 ( V_2 , V_39 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_27 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_51 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
F_7 ( & V_8 -> V_37 ) ;
V_8 -> V_38 &= ~ ( 1 << V_6 ) ;
if ( V_6 == V_39 ) {
V_8 -> V_42 [ V_43 ] -> V_44 [ 0 ] . V_45 |=
V_46 ;
F_8 ( V_8 -> V_47 , V_48 |
V_49 ,
& V_8 -> V_42 [ V_43 ] -> V_50 ) ;
}
if ( V_6 == V_39 || V_6 == V_27 )
F_17 ( V_8 ) ;
F_9 ( & V_8 -> V_37 ) ;
V_8 -> V_36 [ V_6 ] = NULL ;
return 0 ;
}
static unsigned int F_18 ( struct V_52 * V_53 )
{
if ( F_19 ( V_53 ) == V_54 )
return V_55 ;
else
return V_56 ;
}
static unsigned int F_20 ( struct V_52 * V_53 )
{
switch ( F_21 ( V_53 ) ) {
case 32000 :
return V_57 ;
case 44100 :
return V_58 ;
default:
return V_59 ;
case 64000 :
return V_60 ;
case 88200 :
return V_61 ;
case 96000 :
return V_62 ;
case 176400 :
return V_63 ;
case 192000 :
return V_64 ;
}
}
static unsigned int F_22 ( struct V_52 * V_53 )
{
if ( F_19 ( V_53 ) == V_54 )
return V_65 ;
else
return V_66 ;
}
static unsigned int F_23 ( struct V_52 * V_53 )
{
switch ( F_24 ( V_53 ) ) {
default:
return V_67 ;
case 4 :
return V_68 ;
case 6 :
return V_69 ;
case 8 :
return V_70 ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
int V_10 ;
V_10 = F_26 ( V_2 ,
F_27 ( V_53 ) ) ;
if ( V_10 < 0 )
return V_10 ;
F_28 ( V_8 , V_71 [ V_6 ] ,
( V_72 ) V_2 -> V_4 -> V_73 ) ;
if ( V_6 == V_27 ) {
F_28 ( V_8 , V_74 ,
F_27 ( V_53 ) / 4 - 1 ) ;
F_28 ( V_8 , V_75 ,
F_29 ( V_53 ) / 4 - 1 ) ;
} else {
F_30 ( V_8 , V_71 [ V_6 ] + 4 ,
F_27 ( V_53 ) / 4 - 1 ) ;
F_30 ( V_8 , V_71 [ V_6 ] + 6 ,
F_29 ( V_53 ) / 4 - 1 ) ;
}
return 0 ;
}
static T_1 F_31 ( struct V_7 * V_8 , unsigned int V_6 ,
struct V_52 * V_76 )
{
unsigned int V_77 , V_78 ;
if ( V_6 == V_27 )
V_77 = V_8 -> V_13 . V_79 ;
else
V_77 = V_8 -> V_13 . V_80 ;
if ( F_21 ( V_76 ) <= 48000 )
V_78 = 0 ;
else if ( F_21 ( V_76 ) <= 96000 )
V_78 = 2 ;
else
V_78 = 4 ;
return F_32 ( V_77 >> V_78 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_25 ( V_2 , V_53 ) ;
if ( V_10 < 0 )
return V_10 ;
F_34 ( & V_8 -> V_81 ) ;
F_35 ( V_8 , V_82 ,
F_18 ( V_53 ) << V_83 ,
V_84 ) ;
F_36 ( V_8 , V_85 ,
F_20 ( V_53 ) |
V_8 -> V_13 . V_86 |
F_31 ( V_8 , V_25 , V_53 ) |
F_22 ( V_53 ) ,
V_87 |
V_88 |
V_89 |
V_90 ) ;
F_37 ( & V_8 -> V_81 ) ;
F_7 ( & V_8 -> V_37 ) ;
V_8 -> V_13 . V_91 ( V_8 , V_53 ) ;
F_9 ( & V_8 -> V_37 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_92 ;
int V_10 ;
V_10 = F_25 ( V_2 , V_53 ) ;
if ( V_10 < 0 )
return V_10 ;
V_92 = V_8 -> V_12 &&
( V_8 -> V_13 . V_14 & V_15 ) ;
F_34 ( & V_8 -> V_81 ) ;
F_35 ( V_8 , V_82 ,
F_18 ( V_53 ) << V_93 ,
V_94 ) ;
if ( ! V_92 )
F_36 ( V_8 , V_95 ,
F_20 ( V_53 ) |
V_8 -> V_13 . V_86 |
F_31 ( V_8 , V_11 , V_53 ) |
F_22 ( V_53 ) ,
V_87 |
V_88 |
V_89 |
V_90 ) ;
F_37 ( & V_8 -> V_81 ) ;
if ( ! V_92 ) {
F_7 ( & V_8 -> V_37 ) ;
V_8 -> V_13 . V_91 ( V_8 , V_53 ) ;
F_9 ( & V_8 -> V_37 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
bool V_96 ;
int V_10 ;
V_10 = F_25 ( V_2 , V_53 ) ;
if ( V_10 < 0 )
return V_10 ;
V_96 = V_8 -> V_13 . V_14 & V_20 ;
F_34 ( & V_8 -> V_81 ) ;
F_35 ( V_8 , V_82 ,
F_18 ( V_53 ) << V_97 ,
V_98 ) ;
if ( ! V_96 )
F_36 ( V_8 , V_99 ,
F_20 ( V_53 ) |
V_8 -> V_13 . V_86 |
F_31 ( V_8 , V_11 , V_53 ) |
F_22 ( V_53 ) ,
V_87 |
V_88 |
V_89 |
V_90 ) ;
F_37 ( & V_8 -> V_81 ) ;
if ( ! V_96 ) {
F_7 ( & V_8 -> V_37 ) ;
V_8 -> V_13 . V_91 ( V_8 , V_53 ) ;
F_9 ( & V_8 -> V_37 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_25 ( V_2 , V_53 ) ;
if ( V_10 < 0 )
return V_10 ;
F_7 ( & V_8 -> V_37 ) ;
F_34 ( & V_8 -> V_81 ) ;
F_41 ( V_8 , V_100 ,
V_101 ) ;
F_35 ( V_8 , V_102 ,
F_18 ( V_53 ) << V_103 ,
V_104 ) ;
F_42 ( V_8 , V_100 ,
F_20 ( V_53 ) << V_105 ,
V_106 ) ;
F_17 ( V_8 ) ;
F_37 ( & V_8 -> V_81 ) ;
F_9 ( & V_8 -> V_37 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_25 ( V_2 , V_53 ) ;
if ( V_10 < 0 )
return V_10 ;
F_7 ( & V_8 -> V_37 ) ;
F_34 ( & V_8 -> V_81 ) ;
F_35 ( V_8 , V_107 ,
F_23 ( V_53 ) ,
V_108 ) ;
F_35 ( V_8 , V_102 ,
F_18 ( V_53 ) << V_109 ,
V_110 ) ;
F_36 ( V_8 , V_111 ,
F_20 ( V_53 ) |
V_8 -> V_13 . V_112 |
F_31 ( V_8 , V_27 , V_53 ) |
F_22 ( V_53 ) ,
V_87 |
V_88 |
V_89 |
V_90 ) ;
F_17 ( V_8 ) ;
F_37 ( & V_8 -> V_81 ) ;
V_8 -> V_13 . V_113 ( V_8 , V_53 ) ;
F_44 ( V_8 ) ;
F_9 ( & V_8 -> V_37 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
unsigned int V_114 = 1 << V_6 ;
F_34 ( & V_8 -> V_81 ) ;
V_8 -> V_115 &= ~ V_114 ;
F_30 ( V_8 , V_116 , V_8 -> V_115 ) ;
F_46 ( V_8 , V_117 , V_114 ) ;
F_47 ( V_8 , V_117 , V_114 ) ;
F_37 ( & V_8 -> V_81 ) ;
return F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
F_34 ( & V_8 -> V_81 ) ;
F_41 ( V_8 , V_100 ,
V_101 ) ;
F_37 ( & V_8 -> V_81 ) ;
return F_45 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
unsigned int V_114 = 1 << V_6 ;
F_34 ( & V_8 -> V_81 ) ;
F_46 ( V_8 , V_117 , V_114 ) ;
F_47 ( V_8 , V_117 , V_114 ) ;
if ( V_2 -> V_4 -> V_118 )
V_8 -> V_115 &= ~ V_114 ;
else
V_8 -> V_115 |= V_114 ;
F_30 ( V_8 , V_116 , V_8 -> V_115 ) ;
F_37 ( & V_8 -> V_81 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , int V_119 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_1 * V_120 ;
unsigned int V_121 = 0 ;
int V_122 ;
switch ( V_119 ) {
case V_123 :
case V_124 :
case V_125 :
V_122 = 0 ;
break;
case V_126 :
case V_127 :
V_122 = 1 ;
break;
default:
return - V_128 ;
}
F_52 (s, substream) {
if ( F_3 ( V_120 ) == V_8 ) {
V_121 |= 1 << F_1 ( V_120 ) ;
F_53 ( V_120 , V_2 ) ;
}
}
F_54 ( & V_8 -> V_81 ) ;
if ( ! V_122 ) {
if ( V_119 == V_124 )
V_8 -> V_129 |= V_121 ;
else
V_8 -> V_129 &= ~ V_121 ;
F_55 ( V_8 , V_130 , V_8 -> V_129 ) ;
} else {
if ( V_119 == V_126 )
F_46 ( V_8 , V_131 , V_121 ) ;
else
F_47 ( V_8 , V_131 , V_121 ) ;
}
F_56 ( & V_8 -> V_81 ) ;
return 0 ;
}
static T_2 F_57 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_4 = V_2 -> V_4 ;
unsigned int V_6 = F_1 ( V_2 ) ;
V_72 V_132 ;
V_132 = F_58 ( V_8 , V_71 [ V_6 ] ) ;
return F_59 ( V_4 , V_132 - ( V_72 ) V_4 -> V_73 ) ;
}
int F_60 ( struct V_7 * V_8 )
{
struct V_133 * V_134 ;
int V_135 , V_136 ;
int V_10 ;
V_135 = ! ! ( V_8 -> V_13 . V_14 & V_137 ) ;
V_136 = ! ! ( V_8 -> V_13 . V_14 & ( V_138 |
V_139 ) ) ;
if ( V_135 | V_136 ) {
V_10 = F_61 ( V_8 -> V_47 , L_1 ,
0 , V_135 , V_136 , & V_134 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_135 )
F_62 ( V_134 , V_140 ,
& V_141 ) ;
if ( V_8 -> V_13 . V_14 & V_138 )
F_62 ( V_134 , V_142 ,
& V_143 ) ;
else if ( V_8 -> V_13 . V_14 & V_139 )
F_62 ( V_134 , V_142 ,
& V_144 ) ;
V_134 -> V_5 = V_8 ;
strcpy ( V_134 -> V_145 , L_1 ) ;
if ( V_135 )
F_63 ( V_134 -> V_36 [ V_140 ] . V_2 ,
V_146 ,
F_64 ( V_8 -> V_147 ) ,
V_148 ,
V_149 ) ;
if ( V_136 )
F_63 ( V_134 -> V_36 [ V_142 ] . V_2 ,
V_146 ,
F_64 ( V_8 -> V_147 ) ,
V_150 ,
V_151 ) ;
}
V_135 = ! ! ( V_8 -> V_13 . V_14 & V_152 ) ;
V_136 = ! ! ( V_8 -> V_13 . V_14 & V_20 ) ;
if ( V_135 | V_136 ) {
V_10 = F_61 ( V_8 -> V_47 , L_2 , 1 , V_135 , V_136 , & V_134 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_135 )
F_62 ( V_134 , V_140 ,
& V_153 ) ;
if ( V_136 )
F_62 ( V_134 , V_142 ,
& V_154 ) ;
V_134 -> V_5 = V_8 ;
strcpy ( V_134 -> V_145 , L_2 ) ;
F_65 ( V_134 , V_146 ,
F_64 ( V_8 -> V_147 ) ,
V_150 ,
V_151 ) ;
}
if ( V_8 -> V_12 ) {
V_135 = ! ! ( V_8 -> V_13 . V_14 & V_155 ) ;
V_136 = ! ! ( V_8 -> V_13 . V_14 & V_15 ) ;
} else {
V_135 = 0 ;
V_136 = ! ! ( V_8 -> V_13 . V_14 & V_156 ) ;
}
if ( V_135 | V_136 ) {
V_10 = F_61 ( V_8 -> V_47 , V_135 ? L_3 : L_4 ,
2 , V_135 , V_136 , & V_134 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_135 ) {
F_62 ( V_134 , V_140 ,
& V_157 ) ;
F_35 ( V_8 , V_158 ,
V_159 ,
V_160 ) ;
}
if ( V_136 )
F_62 ( V_134 , V_142 ,
& V_144 ) ;
V_134 -> V_5 = V_8 ;
strcpy ( V_134 -> V_145 , V_135 ? L_5 : L_6 ) ;
F_65 ( V_134 , V_146 ,
F_64 ( V_8 -> V_147 ) ,
V_150 ,
V_151 ) ;
}
V_136 = ! ! ( V_8 -> V_13 . V_14 & V_161 ) ;
if ( V_136 ) {
V_10 = F_61 ( V_8 -> V_47 , L_7 , 3 , 0 , V_136 , & V_134 ) ;
if ( V_10 < 0 )
return V_10 ;
F_62 ( V_134 , V_142 ,
& V_154 ) ;
F_35 ( V_8 , V_158 ,
V_162 ,
V_163 ) ;
V_134 -> V_5 = V_8 ;
strcpy ( V_134 -> V_145 , L_8 ) ;
F_65 ( V_134 , V_146 ,
F_64 ( V_8 -> V_147 ) ,
V_150 ,
V_151 ) ;
}
return 0 ;
}
