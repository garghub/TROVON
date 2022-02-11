static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
const char * V_7 ;
switch ( V_6 -> V_8 ) {
case V_9 :
V_7 = L_1 ;
break;
case V_10 :
V_7 = L_2 ;
break;
case V_11 :
V_7 = L_3 ;
break;
default:
return 0 ;
}
return strcmp ( V_2 -> V_12 , V_7 ) == 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
return V_6 -> V_13 == V_14 ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_6 -> V_16 ) {
switch ( V_6 -> V_17 ) {
case 32000 :
V_15 = V_18 ;
break;
case 44100 :
V_15 = V_19 ;
break;
case 48000 :
case 64000 :
case 88200 :
case 96000 :
V_15 = V_20 ;
break;
default:
V_15 = V_21 ;
break;
}
} else {
V_15 = V_21 ;
}
return F_5 ( V_5 , V_22 ,
V_23 , V_15 ) ;
}
static int F_6 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = F_7 ( V_25 ) ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_16 = V_27 -> V_28 . V_29 . V_30 [ 0 ] ;
if ( V_16 > 1 )
return - V_31 ;
V_6 -> V_16 = V_16 ;
return F_4 ( V_5 ) ;
}
static int F_8 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = F_7 ( V_25 ) ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
V_27 -> V_28 . V_29 . V_30 [ 0 ] = V_6 -> V_16 ;
return 0 ;
}
static int F_9 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_35 = 0x00 ;
unsigned int V_36 = 0x00 ;
switch ( V_34 & V_37 ) {
case V_38 :
V_35 |= V_39 ;
V_36 |= V_40 ;
case V_41 :
break;
default:
return - V_31 ;
}
switch ( V_34 & V_42 ) {
case V_43 :
V_35 |= V_44 ;
V_36 |= V_45 ;
break;
case V_46 :
V_35 |= V_47 ;
V_36 |= V_48 ;
break;
case V_49 :
V_35 |= V_50 ;
V_36 |= V_51 ;
break;
default:
return - V_31 ;
}
switch ( V_34 & V_52 ) {
case V_53 :
break;
default:
return - V_31 ;
}
F_5 ( V_5 , V_54 [ V_33 -> V_55 ] [ 0 ] ,
V_56 | V_39 ,
V_35 ) ;
F_10 ( V_5 , V_54 [ V_33 -> V_55 ] [ 1 ] , V_36 ) ;
V_6 -> V_57 [ V_33 -> V_55 ] = V_34 & V_42 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 ,
unsigned int V_58 )
{
unsigned int V_15 ;
if ( V_58 <= 48000 )
V_15 = V_59 ;
else
V_15 = V_60 ;
F_5 ( V_5 , V_61 ,
V_62 , V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
unsigned int V_58 )
{
unsigned int V_15 ;
if ( V_58 <= 48000 )
V_15 = V_63 | V_64 ;
else
V_15 = V_65 | V_66 ;
F_5 ( V_5 , V_22 ,
V_67 | V_68 ,
V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_32 * V_33 , T_1 V_69 )
{
unsigned int V_15 ;
switch ( V_69 ) {
case V_70 :
V_15 = V_71 ;
break;
case V_72 :
V_15 = V_73 ;
break;
case V_74 :
V_15 = V_75 ;
break;
case V_76 :
V_15 = V_77 ;
break;
default:
return - V_31 ;
}
F_5 ( V_5 , V_54 [ V_33 -> V_55 ] [ 0 ] ,
V_78 , V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_32 * V_33 , T_1 V_69 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_6 -> V_57 [ V_33 -> V_55 ] != V_49 )
return 0 ;
switch ( V_69 ) {
case V_70 :
V_15 = V_79 ;
break;
case V_72 :
V_15 = V_80 ;
break;
case V_74 :
V_15 = V_81 ;
break;
case V_76 :
V_15 = V_51 ;
break;
default:
return - V_31 ;
}
F_5 ( V_5 , V_54 [ V_33 -> V_55 ] [ 1 ] ,
V_82 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_83 * V_84 ,
struct V_85 * V_86 , struct V_32 * V_33 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_17 = F_16 ( V_86 ) ;
if ( V_17 * 256 != V_6 -> V_87 )
return - V_31 ;
if ( V_84 -> V_88 == V_89 ) {
F_14 ( V_5 , V_33 ,
F_17 ( V_86 ) ) ;
F_12 ( V_5 , V_17 ) ;
} else {
F_13 ( V_5 , V_33 ,
F_17 ( V_86 ) ) ;
F_11 ( V_5 , V_17 ) ;
}
V_6 -> V_17 = V_17 ;
F_4 ( V_5 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
int V_90 , unsigned int V_91 , int V_92 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
if ( V_92 == V_93 ) {
switch ( V_90 ) {
case V_94 :
case V_11 :
case V_95 :
case V_9 :
case V_10 :
break;
default:
return - V_31 ;
}
V_6 -> V_87 = V_91 ;
if ( V_6 -> V_8 != V_90 ) {
unsigned int V_96 , V_97 ;
V_6 -> V_8 = V_90 ;
if ( V_90 == V_11 )
V_90 = V_94 ;
V_96 = F_19 ( V_90 ) |
F_20 ( V_90 ) |
F_21 ( V_90 ) ;
V_97 = F_22 ( V_90 ) ;
F_10 ( V_5 , V_98 , V_96 ) ;
F_10 ( V_5 , V_99 , V_97 ) ;
F_23 ( & V_5 -> V_100 ) ;
}
} else {
unsigned int V_101 ;
switch ( V_90 ) {
case V_102 :
case V_103 :
case V_104 :
break;
default:
return - V_31 ;
}
V_90 -= V_102 ;
V_101 = F_24 ( V_90 ) ;
if ( V_91 == 0 ) {
F_5 ( V_5 , V_105 , V_101 , V_101 ) ;
V_6 -> V_106 [ V_90 ] = true ;
} else {
F_5 ( V_5 , V_105 , V_101 , 0 ) ;
V_6 -> V_106 [ V_90 ] = false ;
}
if ( V_6 -> V_106 [ 0 ] )
F_25 ( & V_5 -> V_100 , L_1 ) ;
else
F_26 ( & V_5 -> V_100 , L_1 ) ;
if ( V_6 -> V_106 [ 1 ] || V_6 -> V_106 [ 2 ] )
F_25 ( & V_5 -> V_100 , L_2 ) ;
else
F_26 ( & V_5 -> V_100 , L_2 ) ;
F_23 ( & V_5 -> V_100 ) ;
}
return 0 ;
}
static int F_27 ( struct V_4 * V_5 , int V_107 ,
int V_2 , unsigned int V_108 , unsigned int V_109 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_110 = 0 ;
unsigned int V_111 = 0 ;
unsigned int V_13 ;
switch ( V_2 ) {
case V_14 :
case V_112 :
case V_113 :
break;
default:
return - V_31 ;
}
if ( ! V_109 )
return 0 ;
switch ( V_108 ) {
case 27000000 :
break;
case 54000000 :
if ( V_2 == V_112 ) {
V_110 |= V_114 ;
break;
}
default:
return - V_31 ;
}
if ( V_109 > 12288000 ) {
V_111 |= F_28 ( V_107 ) ;
V_109 /= 2 ;
}
switch ( V_109 ) {
case 8192000 :
V_111 |= F_29 ( V_107 ) ;
break;
case 11289600 :
V_111 |= F_30 ( V_107 ) ;
break;
case 12288000 :
V_111 |= F_31 ( V_107 ) ;
break;
default:
return - V_31 ;
}
F_5 ( V_5 , V_115 , V_114 ,
V_110 ) ;
F_5 ( V_5 , V_116 ,
F_32 ( V_107 ) , V_111 ) ;
if ( V_2 != V_6 -> V_13 ) {
if ( V_2 == V_113 )
V_13 = F_33 ( V_107 ) ;
else
V_13 = F_34 ( V_107 ) ;
F_5 ( V_5 , V_117 ,
F_35 ( V_107 ) , V_13 ) ;
V_6 -> V_13 = V_2 ;
F_23 ( & V_5 -> V_100 ) ;
}
return 0 ;
}
static int F_36 ( struct V_4 * V_5 ,
enum V_118 V_119 )
{
unsigned int V_101 = V_120 ;
switch ( V_119 ) {
case V_121 :
break;
case V_122 :
break;
case V_123 :
F_5 ( V_5 , V_124 , V_101 , 0x00 ) ;
break;
case V_125 :
F_5 ( V_5 , V_124 , V_101 , V_101 ) ;
break;
}
V_5 -> V_100 . V_126 = V_119 ;
return 0 ;
}
static int F_37 ( struct V_83 * V_84 ,
struct V_32 * V_33 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
if ( ! V_5 -> V_127 || ! V_6 -> V_17 )
return 0 ;
return F_38 ( V_84 -> V_128 ,
V_129 , V_6 -> V_17 , V_6 -> V_17 ) ;
}
static void F_39 ( struct V_83 * V_84 ,
struct V_32 * V_33 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
if ( ! V_5 -> V_127 )
V_6 -> V_17 = 0 ;
}
static int F_40 ( struct V_4 * V_5 )
{
int V_130 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
V_130 = F_41 ( V_5 , 7 , 9 , V_6 -> V_131 ) ;
if ( V_130 ) {
F_42 ( V_5 -> V_132 , L_4 , V_130 ) ;
return V_130 ;
}
F_26 ( & V_5 -> V_100 , L_1 ) ;
F_26 ( & V_5 -> V_100 , L_2 ) ;
F_10 ( V_5 , V_105 , 0x20 ) ;
F_10 ( V_5 , V_133 , 0x6 ) ;
return F_36 ( V_5 , V_123 ) ;
}
static int F_43 ( struct V_4 * V_5 , T_2 V_134 )
{
return F_36 ( V_5 , V_125 ) ;
}
static int F_44 ( struct V_4 * V_5 )
{
F_36 ( V_5 , V_123 ) ;
V_5 -> V_135 = 1 ;
F_45 ( V_5 ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 )
{
return F_36 ( V_5 , V_125 ) ;
}
static int T_3 F_47 ( struct V_136 * V_132 ,
enum V_137 V_131 )
{
struct V_6 * V_6 ;
int V_130 ;
V_6 = F_48 ( sizeof( * V_6 ) , V_138 ) ;
if ( ! V_6 )
return - V_139 ;
F_49 ( V_132 , V_6 ) ;
V_6 -> V_131 = V_131 ;
V_130 = F_50 ( V_132 , & V_140 ,
V_141 , F_51 ( V_141 ) ) ;
if ( V_130 )
F_52 ( V_6 ) ;
return V_130 ;
}
static int T_4 F_53 ( struct V_136 * V_132 )
{
F_54 ( V_132 ) ;
F_52 ( F_55 ( V_132 ) ) ;
return 0 ;
}
static int T_3 F_56 ( struct V_142 * V_143 )
{
return F_47 ( & V_143 -> V_132 , V_144 ) ;
}
static int T_4 F_57 ( struct V_142 * V_143 )
{
return F_53 ( & V_143 -> V_132 ) ;
}
static int T_3 F_58 ( struct V_145 * V_146 ,
const struct V_147 * V_55 )
{
return F_47 ( & V_146 -> V_132 , V_148 ) ;
}
static int T_4 F_59 ( struct V_145 * V_146 )
{
return F_53 ( & V_146 -> V_132 ) ;
}
static int T_5 F_60 ( void )
{
int V_130 = 0 ;
#if F_61 ( V_149 ) || F_61 ( V_150 )
V_130 = F_62 ( & V_151 ) ;
if ( V_130 )
return V_130 ;
#endif
#if F_61 ( V_152 )
V_130 = F_63 ( & V_153 ) ;
#endif
return V_130 ;
}
static void T_6 F_64 ( void )
{
#if F_61 ( V_149 ) || F_61 ( V_150 )
F_65 ( & V_151 ) ;
#endif
#if F_61 ( V_152 )
F_66 ( & V_153 ) ;
#endif
}
