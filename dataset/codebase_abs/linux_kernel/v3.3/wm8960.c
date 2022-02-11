static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 ;
if ( V_4 -> V_8 ) {
V_7 = 1 ;
for ( V_6 = 2 ; V_6 < F_3 ( V_9 ) ; V_6 ++ ) {
if ( abs ( V_9 [ V_6 ] - V_4 -> V_10 ) <
abs ( V_9 [ V_7 ] - V_4 -> V_10 ) )
V_7 = V_6 ;
}
V_5 = V_7 << 1 ;
} else {
V_5 = 0 ;
}
F_4 ( V_2 -> V_11 , L_1 , V_5 ) ;
return F_5 ( V_2 , V_12 ,
0x6 , V_5 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_16 -> V_17 . V_18 . V_19 [ 0 ] = V_4 -> V_8 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 = V_16 -> V_17 . V_18 . V_19 [ 0 ] ;
if ( V_8 > 1 )
return - V_20 ;
V_4 -> V_8 = V_8 ;
return F_1 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_11 -> V_23 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_25 = & V_2 -> V_25 ;
struct V_26 * V_27 ;
F_10 ( V_25 , V_28 ,
F_3 ( V_28 ) ) ;
F_11 ( V_25 , V_29 , F_3 ( V_29 ) ) ;
if ( V_22 && V_22 -> V_30 ) {
F_10 ( V_25 , V_31 ,
F_3 ( V_31 ) ) ;
F_11 ( V_25 , V_32 ,
F_3 ( V_32 ) ) ;
} else {
F_10 ( V_25 , V_33 ,
F_3 ( V_33 ) ) ;
F_11 ( V_25 , V_34 ,
F_3 ( V_34 ) ) ;
}
F_12 (w, &codec->card->widgets, list) {
if ( V_27 -> V_25 != & V_2 -> V_25 )
continue;
if ( strcmp ( V_27 -> V_35 , L_2 ) == 0 )
V_4 -> V_36 = V_27 ;
if ( strcmp ( V_27 -> V_35 , L_3 ) == 0 )
V_4 -> V_37 = V_27 ;
if ( strcmp ( V_27 -> V_35 , L_4 ) == 0 )
V_4 -> V_38 = V_27 ;
}
return 0 ;
}
static int F_13 ( struct V_39 * V_40 ,
unsigned int V_41 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_42 = 0 ;
switch ( V_41 & V_43 ) {
case V_44 :
V_42 |= 0x0040 ;
break;
case V_45 :
break;
default:
return - V_20 ;
}
switch ( V_41 & V_46 ) {
case V_47 :
V_42 |= 0x0002 ;
break;
case V_48 :
break;
case V_49 :
V_42 |= 0x0001 ;
break;
case V_50 :
V_42 |= 0x0003 ;
break;
case V_51 :
V_42 |= 0x0013 ;
break;
default:
return - V_20 ;
}
switch ( V_41 & V_52 ) {
case V_53 :
break;
case V_54 :
V_42 |= 0x0090 ;
break;
case V_55 :
V_42 |= 0x0080 ;
break;
case V_56 :
V_42 |= 0x0010 ;
break;
default:
return - V_20 ;
}
F_14 ( V_2 , V_57 , V_42 ) ;
return 0 ;
}
static int F_15 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_39 * V_62 )
{
struct V_63 * V_64 = V_59 -> V_65 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_42 = F_16 ( V_2 , V_57 ) & 0xfff3 ;
int V_6 ;
switch ( F_17 ( V_61 ) ) {
case V_66 :
break;
case V_67 :
V_42 |= 0x0004 ;
break;
case V_68 :
V_42 |= 0x0008 ;
break;
}
if ( V_59 -> V_69 == V_70 ) {
V_4 -> V_10 = F_18 ( V_61 ) ;
F_1 ( V_2 ) ;
} else {
for ( V_6 = 0 ; V_6 < F_3 ( V_71 ) ; V_6 ++ )
if ( V_71 [ V_6 ] . V_72 == F_18 ( V_61 ) )
F_5 ( V_2 ,
V_73 , 0x7 ,
V_71 [ V_6 ] . V_5 ) ;
}
F_14 ( V_2 , V_57 , V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_62 , int V_74 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
if ( V_74 )
F_5 ( V_2 , V_12 , 0x8 , 0x8 ) ;
else
F_5 ( V_2 , V_12 , 0x8 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_75 V_76 )
{
switch ( V_76 ) {
case V_77 :
break;
case V_78 :
F_5 ( V_2 , V_79 , 0x180 , 0x80 ) ;
break;
case V_80 :
if ( V_2 -> V_25 . V_81 == V_82 ) {
F_21 ( V_2 ) ;
F_14 ( V_2 , V_83 ,
V_84 | V_85 |
V_86 | V_87 ) ;
F_5 ( V_2 , V_79 , 0x80 , 0x80 ) ;
F_22 ( 100 ) ;
F_5 ( V_2 , V_79 , V_88 ,
V_88 ) ;
F_14 ( V_2 , V_83 , V_87 ) ;
}
F_5 ( V_2 , V_79 , 0x180 , 0x100 ) ;
break;
case V_82 :
F_14 ( V_2 , V_83 ,
V_84 | V_85 |
V_86 | V_87 ) ;
F_14 ( V_2 , V_79 , 0 ) ;
F_22 ( 600 ) ;
break;
}
V_2 -> V_25 . V_81 = V_76 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_75 V_76 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_89 ;
switch ( V_76 ) {
case V_77 :
break;
case V_78 :
switch ( V_2 -> V_25 . V_81 ) {
case V_80 :
F_5 ( V_2 , V_83 ,
V_84 | V_85 |
V_86 ,
V_84 | V_85 |
V_86 ) ;
V_89 = 0 ;
if ( V_4 -> V_36 && V_4 -> V_36 -> V_90 )
V_89 |= V_91 ;
if ( V_4 -> V_37 && V_4 -> V_37 -> V_90 )
V_89 |= V_92 ;
if ( V_4 -> V_38 && V_4 -> V_38 -> V_90 )
V_89 |= V_93 ;
F_5 ( V_2 , V_94 ,
V_91 |
V_92 |
V_93 , V_89 ) ;
F_5 ( V_2 , V_79 ,
V_95 , 0x80 ) ;
F_22 ( 100 ) ;
F_5 ( V_2 , V_79 ,
V_88 , V_88 ) ;
F_22 ( 100 ) ;
break;
case V_77 :
F_5 ( V_2 , V_83 ,
V_84 | V_85 |
V_86 ,
V_84 | V_85 |
V_86 ) ;
F_5 ( V_2 , V_79 ,
V_88 | V_95 , 0 ) ;
break;
case V_82 :
F_21 ( V_2 ) ;
break;
default:
break;
}
break;
case V_80 :
switch ( V_2 -> V_25 . V_81 ) {
case V_78 :
F_5 ( V_2 , V_96 ,
V_97 | V_98 ,
0 ) ;
F_5 ( V_2 , V_83 ,
V_84 | V_85 |
V_86 ,
V_84 | V_85 |
V_86 ) ;
break;
default:
break;
}
break;
case V_82 :
break;
}
V_2 -> V_25 . V_81 = V_76 ;
return 0 ;
}
static int F_24 ( unsigned int V_99 , unsigned int V_100 ,
struct V_101 * V_102 )
{
unsigned long long V_103 ;
unsigned int V_104 , V_105 , V_106 ;
F_25 ( L_5 , V_99 , V_100 ) ;
V_100 *= 4 ;
V_105 = V_100 / V_99 ;
if ( V_105 < 6 ) {
V_99 >>= 1 ;
V_102 -> V_107 = 1 ;
V_105 = V_100 / V_99 ;
} else
V_102 -> V_107 = 0 ;
if ( ( V_105 < 6 ) || ( V_105 > 12 ) ) {
F_26 ( L_6 , V_105 ) ;
return - V_20 ;
}
V_102 -> V_108 = V_105 ;
V_106 = V_100 % V_99 ;
V_103 = V_109 * ( long long ) V_106 ;
F_27 ( V_103 , V_99 ) ;
V_104 = V_103 & 0xFFFFFFFF ;
if ( ( V_104 % 10 ) >= 5 )
V_104 += 5 ;
V_104 /= 10 ;
V_102 -> V_110 = V_104 ;
F_25 ( L_7 ,
V_102 -> V_108 , V_102 -> V_110 , V_102 -> V_107 ) ;
return 0 ;
}
static int F_28 ( struct V_39 * V_40 , int V_111 ,
int V_99 , unsigned int V_112 , unsigned int V_113 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_89 ;
static struct V_101 V_102 ;
int V_114 ;
if ( V_112 && V_113 ) {
V_114 = F_24 ( V_112 , V_113 , & V_102 ) ;
if ( V_114 != 0 )
return V_114 ;
}
F_5 ( V_2 , V_115 , 0x1 , 0 ) ;
F_5 ( V_2 , V_94 , 0x1 , 0 ) ;
if ( ! V_112 || ! V_113 )
return 0 ;
V_89 = F_16 ( V_2 , V_116 ) & ~ 0x3f ;
V_89 |= V_102 . V_107 << 4 ;
V_89 |= V_102 . V_108 ;
if ( V_102 . V_110 ) {
V_89 |= 0x20 ;
F_14 ( V_2 , V_117 , ( V_102 . V_110 >> 18 ) & 0x3f ) ;
F_14 ( V_2 , V_118 , ( V_102 . V_110 >> 9 ) & 0x1ff ) ;
F_14 ( V_2 , V_119 , V_102 . V_110 & 0x1ff ) ;
}
F_14 ( V_2 , V_116 , V_89 ) ;
F_5 ( V_2 , V_94 , 0x1 , 0x1 ) ;
F_22 ( 250 ) ;
F_5 ( V_2 , V_115 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 ,
int V_120 , int div )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_89 ;
switch ( V_120 ) {
case V_121 :
V_89 = F_16 ( V_2 , V_115 ) & 0x1f9 ;
F_14 ( V_2 , V_115 , V_89 | div ) ;
break;
case V_122 :
V_89 = F_16 ( V_2 , V_115 ) & 0x1c7 ;
F_14 ( V_2 , V_115 , V_89 | div ) ;
break;
case V_123 :
V_89 = F_16 ( V_2 , V_116 ) & 0x03f ;
F_14 ( V_2 , V_116 , V_89 | div ) ;
break;
case V_124 :
V_89 = F_16 ( V_2 , V_125 ) & 0x03f ;
F_14 ( V_2 , V_125 , V_89 | div ) ;
break;
case V_126 :
V_89 = F_16 ( V_2 , V_127 ) & 0x1fd ;
F_14 ( V_2 , V_127 , V_89 | div ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_75 V_76 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_128 ( V_2 , V_76 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_128 ( V_2 , V_82 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_128 ( V_2 , V_80 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_34 ( V_2 -> V_11 ) ;
int V_114 ;
V_4 -> V_128 = F_20 ;
if ( ! V_22 ) {
F_35 ( V_2 -> V_11 , L_8 ) ;
} else {
if ( V_22 -> V_129 > V_130 ) {
F_36 ( V_2 -> V_11 , L_9 , V_22 -> V_129 ) ;
V_22 -> V_129 = 0 ;
}
if ( V_22 -> V_30 )
V_4 -> V_128 = F_23 ;
}
V_114 = F_37 ( V_2 , 7 , 9 , V_4 -> V_131 ) ;
if ( V_114 < 0 ) {
F_36 ( V_2 -> V_11 , L_10 , V_114 ) ;
return V_114 ;
}
V_114 = F_38 ( V_2 ) ;
if ( V_114 < 0 ) {
F_36 ( V_2 -> V_11 , L_11 ) ;
return V_114 ;
}
V_4 -> V_128 ( V_2 , V_80 ) ;
F_5 ( V_2 , V_132 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_133 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_134 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_135 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_136 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_137 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_138 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_139 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_140 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_141 , 0x100 , 0x100 ) ;
F_39 ( V_2 , V_142 ,
F_3 ( V_142 ) ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_128 ( V_2 , V_82 ) ;
return 0 ;
}
static T_2 int F_41 ( struct V_143 * V_144 ,
const struct V_145 * V_146 )
{
struct V_3 * V_4 ;
int V_114 ;
V_4 = F_42 ( & V_144 -> V_11 , sizeof( struct V_3 ) ,
V_147 ) ;
if ( V_4 == NULL )
return - V_148 ;
F_43 ( V_144 , V_4 ) ;
V_4 -> V_131 = V_149 ;
V_114 = F_44 ( & V_144 -> V_11 ,
& V_150 , & V_151 , 1 ) ;
return V_114 ;
}
static T_3 int F_45 ( struct V_143 * V_152 )
{
F_46 ( & V_152 -> V_11 ) ;
return 0 ;
}
static int T_4 F_47 ( void )
{
int V_114 = 0 ;
V_114 = F_48 ( & V_153 ) ;
if ( V_114 != 0 ) {
F_49 ( V_154 L_12 ,
V_114 ) ;
}
return V_114 ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_153 ) ;
}
