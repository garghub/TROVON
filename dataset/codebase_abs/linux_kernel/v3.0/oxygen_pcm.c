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
if ( V_6 == V_24 ) {
V_10 = F_6
( V_4 , V_33 , 0 , 8192000 ) ;
if ( V_10 < 0 )
return V_10 ;
}
F_7 ( V_2 ) ;
V_8 -> V_34 [ V_6 ] = V_2 ;
F_8 ( & V_8 -> V_35 ) ;
V_8 -> V_36 |= 1 << V_6 ;
if ( V_6 == V_37 ) {
V_8 -> V_38 = V_8 -> V_39 ;
V_8 -> V_40 [ V_41 ] -> V_42 [ 0 ] . V_43 &=
~ V_44 ;
F_9 ( V_8 -> V_45 , V_46 |
V_47 ,
& V_8 -> V_40 [ V_41 ] -> V_48 ) ;
}
F_10 ( & V_8 -> V_35 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_49 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_19 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_37 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_24 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_50 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
F_8 ( & V_8 -> V_35 ) ;
V_8 -> V_36 &= ~ ( 1 << V_6 ) ;
if ( V_6 == V_37 ) {
V_8 -> V_40 [ V_41 ] -> V_42 [ 0 ] . V_43 |=
V_44 ;
F_9 ( V_8 -> V_45 , V_46 |
V_47 ,
& V_8 -> V_40 [ V_41 ] -> V_48 ) ;
}
if ( V_6 == V_37 || V_6 == V_24 )
F_18 ( V_8 ) ;
F_10 ( & V_8 -> V_35 ) ;
V_8 -> V_34 [ V_6 ] = NULL ;
return 0 ;
}
static unsigned int F_19 ( struct V_51 * V_52 )
{
if ( F_20 ( V_52 ) == V_53 )
return V_54 ;
else
return V_55 ;
}
static unsigned int F_21 ( struct V_51 * V_52 )
{
switch ( F_22 ( V_52 ) ) {
case 32000 :
return V_56 ;
case 44100 :
return V_57 ;
default:
return V_58 ;
case 64000 :
return V_59 ;
case 88200 :
return V_60 ;
case 96000 :
return V_61 ;
case 176400 :
return V_62 ;
case 192000 :
return V_63 ;
}
}
static unsigned int F_23 ( struct V_51 * V_52 )
{
if ( F_20 ( V_52 ) == V_53 )
return V_64 ;
else
return V_65 ;
}
static unsigned int F_24 ( struct V_51 * V_52 )
{
switch ( F_25 ( V_52 ) ) {
default:
return V_66 ;
case 4 :
return V_67 ;
case 6 :
return V_68 ;
case 8 :
return V_69 ;
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
int V_10 ;
V_10 = F_27 ( V_2 ,
F_28 ( V_52 ) ) ;
if ( V_10 < 0 )
return V_10 ;
F_29 ( V_8 , V_70 [ V_6 ] ,
( V_71 ) V_2 -> V_4 -> V_72 ) ;
if ( V_6 == V_24 ) {
F_29 ( V_8 , V_73 ,
F_28 ( V_52 ) / 4 - 1 ) ;
F_29 ( V_8 , V_74 ,
F_30 ( V_52 ) / 4 - 1 ) ;
} else {
F_31 ( V_8 , V_70 [ V_6 ] + 4 ,
F_28 ( V_52 ) / 4 - 1 ) ;
F_31 ( V_8 , V_70 [ V_6 ] + 6 ,
F_30 ( V_52 ) / 4 - 1 ) ;
}
return 0 ;
}
static T_1 F_32 ( struct V_7 * V_8 , unsigned int V_6 ,
struct V_51 * V_75 )
{
unsigned int V_76 , V_77 ;
if ( V_6 == V_24 )
V_76 = V_8 -> V_13 . V_78 ;
else
V_76 = V_8 -> V_13 . V_79 ;
if ( F_22 ( V_75 ) <= 48000 )
V_77 = 0 ;
else if ( F_22 ( V_75 ) <= 96000 )
V_77 = 2 ;
else
V_77 = 4 ;
return F_33 ( V_76 >> V_77 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_26 ( V_2 , V_52 ) ;
if ( V_10 < 0 )
return V_10 ;
F_35 ( & V_8 -> V_80 ) ;
F_36 ( V_8 , V_81 ,
F_19 ( V_52 ) << V_82 ,
V_83 ) ;
F_37 ( V_8 , V_84 ,
F_21 ( V_52 ) |
V_8 -> V_13 . V_85 |
F_32 ( V_8 , V_49 , V_52 ) |
F_23 ( V_52 ) ,
V_86 |
V_87 |
V_88 |
V_89 ) ;
F_38 ( & V_8 -> V_80 ) ;
F_8 ( & V_8 -> V_35 ) ;
V_8 -> V_13 . V_90 ( V_8 , V_52 ) ;
F_10 ( & V_8 -> V_35 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_91 ;
int V_10 ;
V_10 = F_26 ( V_2 , V_52 ) ;
if ( V_10 < 0 )
return V_10 ;
V_91 = V_8 -> V_12 &&
( V_8 -> V_13 . V_14 & V_15 ) ;
F_35 ( & V_8 -> V_80 ) ;
F_36 ( V_8 , V_81 ,
F_19 ( V_52 ) << V_92 ,
V_93 ) ;
if ( ! V_91 )
F_37 ( V_8 , V_94 ,
F_21 ( V_52 ) |
V_8 -> V_13 . V_85 |
F_32 ( V_8 , V_11 , V_52 ) |
F_23 ( V_52 ) ,
V_86 |
V_87 |
V_88 |
V_89 ) ;
F_38 ( & V_8 -> V_80 ) ;
if ( ! V_91 ) {
F_8 ( & V_8 -> V_35 ) ;
V_8 -> V_13 . V_90 ( V_8 , V_52 ) ;
F_10 ( & V_8 -> V_35 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_26 ( V_2 , V_52 ) ;
if ( V_10 < 0 )
return V_10 ;
F_35 ( & V_8 -> V_80 ) ;
F_36 ( V_8 , V_81 ,
F_19 ( V_52 ) << V_95 ,
V_96 ) ;
F_38 ( & V_8 -> V_80 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_26 ( V_2 , V_52 ) ;
if ( V_10 < 0 )
return V_10 ;
F_8 ( & V_8 -> V_35 ) ;
F_35 ( & V_8 -> V_80 ) ;
F_42 ( V_8 , V_97 ,
V_98 ) ;
F_36 ( V_8 , V_99 ,
F_19 ( V_52 ) << V_100 ,
V_101 ) ;
F_43 ( V_8 , V_97 ,
F_21 ( V_52 ) << V_102 ,
V_103 ) ;
F_18 ( V_8 ) ;
F_38 ( & V_8 -> V_80 ) ;
F_10 ( & V_8 -> V_35 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_26 ( V_2 , V_52 ) ;
if ( V_10 < 0 )
return V_10 ;
F_8 ( & V_8 -> V_35 ) ;
F_35 ( & V_8 -> V_80 ) ;
F_36 ( V_8 , V_104 ,
F_24 ( V_52 ) ,
V_105 ) ;
F_36 ( V_8 , V_99 ,
F_19 ( V_52 ) << V_106 ,
V_107 ) ;
F_37 ( V_8 , V_108 ,
F_21 ( V_52 ) |
V_8 -> V_13 . V_109 |
F_32 ( V_8 , V_24 , V_52 ) |
F_23 ( V_52 ) ,
V_86 |
V_87 |
V_88 |
V_89 ) ;
F_18 ( V_8 ) ;
F_38 ( & V_8 -> V_80 ) ;
V_8 -> V_13 . V_110 ( V_8 , V_52 ) ;
F_45 ( V_8 ) ;
F_10 ( & V_8 -> V_35 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
unsigned int V_111 = 1 << V_6 ;
F_35 ( & V_8 -> V_80 ) ;
V_8 -> V_112 &= ~ V_111 ;
F_31 ( V_8 , V_113 , V_8 -> V_112 ) ;
F_47 ( V_8 , V_114 , V_111 ) ;
F_48 ( V_8 , V_114 , V_111 ) ;
F_38 ( & V_8 -> V_80 ) ;
return F_49 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
F_35 ( & V_8 -> V_80 ) ;
F_42 ( V_8 , V_97 ,
V_98 ) ;
F_38 ( & V_8 -> V_80 ) ;
return F_46 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
unsigned int V_111 = 1 << V_6 ;
F_35 ( & V_8 -> V_80 ) ;
F_47 ( V_8 , V_114 , V_111 ) ;
F_48 ( V_8 , V_114 , V_111 ) ;
if ( V_2 -> V_4 -> V_115 )
V_8 -> V_112 &= ~ V_111 ;
else
V_8 -> V_112 |= V_111 ;
F_31 ( V_8 , V_113 , V_8 -> V_112 ) ;
F_38 ( & V_8 -> V_80 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , int V_116 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_1 * V_117 ;
unsigned int V_118 = 0 ;
int V_119 ;
switch ( V_116 ) {
case V_120 :
case V_121 :
case V_122 :
V_119 = 0 ;
break;
case V_123 :
case V_124 :
V_119 = 1 ;
break;
default:
return - V_125 ;
}
F_53 (s, substream) {
if ( F_3 ( V_117 ) == V_8 ) {
V_118 |= 1 << F_1 ( V_117 ) ;
F_54 ( V_117 , V_2 ) ;
}
}
F_55 ( & V_8 -> V_80 ) ;
if ( ! V_119 ) {
if ( V_116 == V_121 )
V_8 -> V_126 |= V_118 ;
else
V_8 -> V_126 &= ~ V_118 ;
F_56 ( V_8 , V_127 , V_8 -> V_126 ) ;
} else {
if ( V_116 == V_123 )
F_47 ( V_8 , V_128 , V_118 ) ;
else
F_48 ( V_8 , V_128 , V_118 ) ;
}
F_57 ( & V_8 -> V_80 ) ;
return 0 ;
}
static T_2 F_58 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_4 = V_2 -> V_4 ;
unsigned int V_6 = F_1 ( V_2 ) ;
V_71 V_129 ;
V_129 = F_59 ( V_8 , V_70 [ V_6 ] ) ;
return F_60 ( V_4 , V_129 - ( V_71 ) V_4 -> V_72 ) ;
}
static void F_61 ( struct V_130 * V_131 )
{
F_62 ( V_131 ) ;
}
int F_63 ( struct V_7 * V_8 )
{
struct V_130 * V_131 ;
int V_132 , V_133 ;
int V_10 ;
V_132 = ! ! ( V_8 -> V_13 . V_14 & V_134 ) ;
V_133 = ! ! ( V_8 -> V_13 . V_14 & ( V_135 |
V_136 ) ) ;
if ( V_132 | V_133 ) {
V_10 = F_64 ( V_8 -> V_45 , L_1 ,
0 , V_132 , V_133 , & V_131 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_132 )
F_65 ( V_131 , V_137 ,
& V_138 ) ;
if ( V_8 -> V_13 . V_14 & V_135 )
F_65 ( V_131 , V_139 ,
& V_140 ) ;
else if ( V_8 -> V_13 . V_14 & V_136 )
F_65 ( V_131 , V_139 ,
& V_141 ) ;
V_131 -> V_5 = V_8 ;
V_131 -> V_142 = F_61 ;
strcpy ( V_131 -> V_143 , L_1 ) ;
if ( V_132 )
F_66 ( V_131 -> V_34 [ V_137 ] . V_2 ,
V_144 ,
F_67 ( V_8 -> V_145 ) ,
V_146 ,
V_147 ) ;
if ( V_133 )
F_66 ( V_131 -> V_34 [ V_139 ] . V_2 ,
V_144 ,
F_67 ( V_8 -> V_145 ) ,
V_148 ,
V_149 ) ;
}
V_132 = ! ! ( V_8 -> V_13 . V_14 & V_150 ) ;
V_133 = ! ! ( V_8 -> V_13 . V_14 & V_151 ) ;
if ( V_132 | V_133 ) {
V_10 = F_64 ( V_8 -> V_45 , L_2 , 1 , V_132 , V_133 , & V_131 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_132 )
F_65 ( V_131 , V_137 ,
& V_152 ) ;
if ( V_133 )
F_65 ( V_131 , V_139 ,
& V_153 ) ;
V_131 -> V_5 = V_8 ;
V_131 -> V_142 = F_61 ;
strcpy ( V_131 -> V_143 , L_2 ) ;
F_68 ( V_131 , V_144 ,
F_67 ( V_8 -> V_145 ) ,
V_148 ,
V_149 ) ;
}
if ( V_8 -> V_12 ) {
V_132 = ! ! ( V_8 -> V_13 . V_14 & V_154 ) ;
V_133 = ! ! ( V_8 -> V_13 . V_14 & V_15 ) ;
} else {
V_132 = 0 ;
V_133 = ! ! ( V_8 -> V_13 . V_14 & V_155 ) ;
}
if ( V_132 | V_133 ) {
V_10 = F_64 ( V_8 -> V_45 , V_132 ? L_3 : L_4 ,
2 , V_132 , V_133 , & V_131 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_132 ) {
F_65 ( V_131 , V_137 ,
& V_156 ) ;
F_36 ( V_8 , V_157 ,
V_158 ,
V_159 ) ;
}
if ( V_133 )
F_65 ( V_131 , V_139 ,
& V_141 ) ;
V_131 -> V_5 = V_8 ;
V_131 -> V_142 = F_61 ;
strcpy ( V_131 -> V_143 , V_132 ? L_5 : L_6 ) ;
F_68 ( V_131 , V_144 ,
F_67 ( V_8 -> V_145 ) ,
V_148 ,
V_149 ) ;
}
return 0 ;
}
