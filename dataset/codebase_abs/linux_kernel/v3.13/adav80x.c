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
return F_5 ( V_6 -> V_22 , V_23 ,
V_24 , V_15 ) ;
}
static int F_6 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_4 * V_5 = F_7 ( V_26 ) ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_16 = V_28 -> V_29 . V_30 . V_31 [ 0 ] ;
if ( V_16 > 1 )
return - V_32 ;
V_6 -> V_16 = V_16 ;
return F_4 ( V_5 ) ;
}
static int F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_4 * V_5 = F_7 ( V_26 ) ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
V_28 -> V_29 . V_30 . V_31 [ 0 ] = V_6 -> V_16 ;
return 0 ;
}
static int F_9 ( struct V_33 * V_34 , unsigned int V_35 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_36 = 0x00 ;
unsigned int V_37 = 0x00 ;
switch ( V_35 & V_38 ) {
case V_39 :
V_36 |= V_40 ;
V_37 |= V_41 ;
case V_42 :
break;
default:
return - V_32 ;
}
switch ( V_35 & V_43 ) {
case V_44 :
V_36 |= V_45 ;
V_37 |= V_46 ;
break;
case V_47 :
V_36 |= V_48 ;
V_37 |= V_49 ;
break;
case V_50 :
V_36 |= V_51 ;
V_37 |= V_52 ;
break;
default:
return - V_32 ;
}
switch ( V_35 & V_53 ) {
case V_54 :
break;
default:
return - V_32 ;
}
F_5 ( V_6 -> V_22 , V_55 [ V_34 -> V_56 ] [ 0 ] ,
V_57 | V_40 ,
V_36 ) ;
F_10 ( V_6 -> V_22 , V_55 [ V_34 -> V_56 ] [ 1 ] ,
V_37 ) ;
V_6 -> V_58 [ V_34 -> V_56 ] = V_35 & V_43 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 ,
unsigned int V_59 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_59 <= 48000 )
V_15 = V_60 ;
else
V_15 = V_61 ;
F_5 ( V_6 -> V_22 , V_62 ,
V_63 , V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
unsigned int V_59 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_59 <= 48000 )
V_15 = V_64 | V_65 ;
else
V_15 = V_66 | V_67 ;
F_5 ( V_6 -> V_22 , V_23 ,
V_68 | V_69 ,
V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_33 * V_34 , T_1 V_70 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
switch ( V_70 ) {
case V_71 :
V_15 = V_72 ;
break;
case V_73 :
V_15 = V_74 ;
break;
case V_75 :
V_15 = V_76 ;
break;
case V_77 :
V_15 = V_78 ;
break;
default:
return - V_32 ;
}
F_5 ( V_6 -> V_22 , V_55 [ V_34 -> V_56 ] [ 0 ] ,
V_79 , V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_33 * V_34 , T_1 V_70 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_6 -> V_58 [ V_34 -> V_56 ] != V_50 )
return 0 ;
switch ( V_70 ) {
case V_71 :
V_15 = V_80 ;
break;
case V_73 :
V_15 = V_81 ;
break;
case V_75 :
V_15 = V_82 ;
break;
case V_77 :
V_15 = V_52 ;
break;
default:
return - V_32 ;
}
F_5 ( V_6 -> V_22 , V_55 [ V_34 -> V_56 ] [ 1 ] ,
V_83 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_84 * V_85 ,
struct V_86 * V_87 , struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_17 = F_16 ( V_87 ) ;
if ( V_17 * 256 != V_6 -> V_88 )
return - V_32 ;
if ( V_85 -> V_89 == V_90 ) {
F_14 ( V_5 , V_34 ,
F_17 ( V_87 ) ) ;
F_12 ( V_5 , V_17 ) ;
} else {
F_13 ( V_5 , V_34 ,
F_17 ( V_87 ) ) ;
F_11 ( V_5 , V_17 ) ;
}
V_6 -> V_17 = V_17 ;
F_4 ( V_5 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
int V_91 , int V_2 ,
unsigned int V_92 , int V_93 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
if ( V_93 == V_94 ) {
switch ( V_91 ) {
case V_95 :
case V_11 :
case V_96 :
case V_9 :
case V_10 :
break;
default:
return - V_32 ;
}
V_6 -> V_88 = V_92 ;
if ( V_6 -> V_8 != V_91 ) {
unsigned int V_97 , V_98 ;
V_6 -> V_8 = V_91 ;
if ( V_91 == V_11 )
V_91 = V_95 ;
V_97 = F_19 ( V_91 ) |
F_20 ( V_91 ) |
F_21 ( V_91 ) ;
V_98 = F_22 ( V_91 ) ;
F_10 ( V_6 -> V_22 , V_99 ,
V_97 ) ;
F_10 ( V_6 -> V_22 , V_100 ,
V_98 ) ;
F_23 ( & V_5 -> V_101 ) ;
}
} else {
unsigned int V_102 ;
switch ( V_91 ) {
case V_103 :
case V_104 :
case V_105 :
break;
default:
return - V_32 ;
}
V_91 -= V_103 ;
V_102 = F_24 ( V_91 ) ;
if ( V_92 == 0 ) {
F_5 ( V_6 -> V_22 , V_106 ,
V_102 , V_102 ) ;
V_6 -> V_107 [ V_91 ] = true ;
} else {
F_5 ( V_6 -> V_22 , V_106 ,
V_102 , 0 ) ;
V_6 -> V_107 [ V_91 ] = false ;
}
if ( V_6 -> V_107 [ 0 ] )
F_25 ( & V_5 -> V_101 , L_1 ) ;
else
F_26 ( & V_5 -> V_101 , L_1 ) ;
if ( V_6 -> V_107 [ 1 ] || V_6 -> V_107 [ 2 ] )
F_25 ( & V_5 -> V_101 , L_2 ) ;
else
F_26 ( & V_5 -> V_101 , L_2 ) ;
F_23 ( & V_5 -> V_101 ) ;
}
return 0 ;
}
static int F_27 ( struct V_4 * V_5 , int V_108 ,
int V_2 , unsigned int V_109 , unsigned int V_110 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_111 = 0 ;
unsigned int V_112 = 0 ;
unsigned int V_13 ;
switch ( V_2 ) {
case V_14 :
case V_113 :
case V_114 :
break;
default:
return - V_32 ;
}
if ( ! V_110 )
return 0 ;
switch ( V_109 ) {
case 27000000 :
break;
case 54000000 :
if ( V_2 == V_113 ) {
V_111 |= V_115 ;
break;
}
default:
return - V_32 ;
}
if ( V_110 > 12288000 ) {
V_112 |= F_28 ( V_108 ) ;
V_110 /= 2 ;
}
switch ( V_110 ) {
case 8192000 :
V_112 |= F_29 ( V_108 ) ;
break;
case 11289600 :
V_112 |= F_30 ( V_108 ) ;
break;
case 12288000 :
V_112 |= F_31 ( V_108 ) ;
break;
default:
return - V_32 ;
}
F_5 ( V_6 -> V_22 , V_116 ,
V_115 , V_111 ) ;
F_5 ( V_6 -> V_22 , V_117 ,
F_32 ( V_108 ) , V_112 ) ;
if ( V_2 != V_6 -> V_13 ) {
if ( V_2 == V_114 )
V_13 = F_33 ( V_108 ) ;
else
V_13 = F_34 ( V_108 ) ;
F_5 ( V_6 -> V_22 , V_118 ,
F_35 ( V_108 ) , V_13 ) ;
V_6 -> V_13 = V_2 ;
F_23 ( & V_5 -> V_101 ) ;
}
return 0 ;
}
static int F_36 ( struct V_4 * V_5 ,
enum V_119 V_120 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_102 = V_121 ;
switch ( V_120 ) {
case V_122 :
break;
case V_123 :
break;
case V_124 :
F_5 ( V_6 -> V_22 , V_125 , V_102 ,
0x00 ) ;
break;
case V_126 :
F_5 ( V_6 -> V_22 , V_125 , V_102 ,
V_102 ) ;
break;
}
V_5 -> V_101 . V_127 = V_120 ;
return 0 ;
}
static int F_37 ( struct V_84 * V_85 ,
struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
if ( ! V_5 -> V_128 || ! V_6 -> V_17 )
return 0 ;
return F_38 ( V_85 -> V_129 ,
V_130 , V_6 -> V_17 , V_6 -> V_17 ) ;
}
static void F_39 ( struct V_84 * V_85 ,
struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
if ( ! V_5 -> V_128 )
V_6 -> V_17 = 0 ;
}
static int F_40 ( struct V_4 * V_5 )
{
int V_131 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
V_131 = F_41 ( V_5 , 0 , 0 , V_132 ) ;
if ( V_131 ) {
F_42 ( V_5 -> V_133 , L_4 , V_131 ) ;
return V_131 ;
}
F_26 ( & V_5 -> V_101 , L_1 ) ;
F_26 ( & V_5 -> V_101 , L_2 ) ;
F_10 ( V_6 -> V_22 , V_106 , 0x20 ) ;
F_10 ( V_6 -> V_22 , V_134 , 0x6 ) ;
return F_36 ( V_5 , V_124 ) ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
int V_131 ;
V_131 = F_36 ( V_5 , V_126 ) ;
F_44 ( V_6 -> V_22 , true ) ;
return V_131 ;
}
static int F_45 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
F_44 ( V_6 -> V_22 , false ) ;
F_36 ( V_5 , V_124 ) ;
F_46 ( V_6 -> V_22 ) ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 )
{
return F_36 ( V_5 , V_126 ) ;
}
static int F_48 ( struct V_135 * V_133 , struct V_22 * V_22 )
{
struct V_6 * V_6 ;
int V_131 ;
if ( F_49 ( V_22 ) )
return F_50 ( V_22 ) ;
V_6 = F_51 ( sizeof( * V_6 ) , V_136 ) ;
if ( ! V_6 )
return - V_137 ;
F_52 ( V_133 , V_6 ) ;
V_6 -> V_22 = V_22 ;
V_131 = F_53 ( V_133 , & V_138 ,
V_139 , F_54 ( V_139 ) ) ;
if ( V_131 )
F_55 ( V_6 ) ;
return V_131 ;
}
static int F_56 ( struct V_135 * V_133 )
{
F_57 ( V_133 ) ;
F_55 ( F_58 ( V_133 ) ) ;
return 0 ;
}
static int F_59 ( struct V_140 * V_141 )
{
return F_48 ( & V_141 -> V_133 ,
F_60 ( V_141 , & V_142 ) ) ;
}
static int F_61 ( struct V_140 * V_141 )
{
return F_56 ( & V_141 -> V_133 ) ;
}
static int F_62 ( struct V_143 * V_144 ,
const struct V_145 * V_56 )
{
return F_48 ( & V_144 -> V_133 ,
F_63 ( V_144 , & V_146 ) ) ;
}
static int F_64 ( struct V_143 * V_144 )
{
return F_56 ( & V_144 -> V_133 ) ;
}
static int T_2 F_65 ( void )
{
int V_131 = 0 ;
#if F_66 ( V_147 ) || F_66 ( V_148 )
V_131 = F_67 ( & V_149 ) ;
if ( V_131 )
return V_131 ;
#endif
#if F_66 ( V_150 )
V_131 = F_68 ( & V_151 ) ;
#endif
return V_131 ;
}
static void T_3 F_69 ( void )
{
#if F_66 ( V_147 ) || F_66 ( V_148 )
F_70 ( & V_149 ) ;
#endif
#if F_66 ( V_150 )
F_71 ( & V_151 ) ;
#endif
}
