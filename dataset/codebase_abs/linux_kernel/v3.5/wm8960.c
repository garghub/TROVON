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
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_42 = F_16 ( V_2 , V_57 ) & 0xfff3 ;
int V_6 ;
switch ( F_17 ( V_61 ) ) {
case V_63 :
break;
case V_64 :
V_42 |= 0x0004 ;
break;
case V_65 :
V_42 |= 0x0008 ;
break;
}
if ( V_59 -> V_66 == V_67 ) {
V_4 -> V_10 = F_18 ( V_61 ) ;
F_1 ( V_2 ) ;
} else {
for ( V_6 = 0 ; V_6 < F_3 ( V_68 ) ; V_6 ++ )
if ( V_68 [ V_6 ] . V_69 == F_18 ( V_61 ) )
F_5 ( V_2 ,
V_70 , 0x7 ,
V_68 [ V_6 ] . V_5 ) ;
}
F_14 ( V_2 , V_57 , V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_62 , int V_71 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
if ( V_71 )
F_5 ( V_2 , V_12 , 0x8 , 0x8 ) ;
else
F_5 ( V_2 , V_12 , 0x8 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_72 V_73 )
{
switch ( V_73 ) {
case V_74 :
break;
case V_75 :
F_5 ( V_2 , V_76 , 0x180 , 0x80 ) ;
break;
case V_77 :
if ( V_2 -> V_25 . V_78 == V_79 ) {
F_21 ( V_2 ) ;
F_14 ( V_2 , V_80 ,
V_81 | V_82 |
V_83 | V_84 ) ;
F_5 ( V_2 , V_76 , 0x80 , 0x80 ) ;
F_22 ( 100 ) ;
F_5 ( V_2 , V_76 , V_85 ,
V_85 ) ;
F_14 ( V_2 , V_80 , V_84 ) ;
}
F_5 ( V_2 , V_76 , 0x180 , 0x100 ) ;
break;
case V_79 :
F_14 ( V_2 , V_80 ,
V_81 | V_82 |
V_83 | V_84 ) ;
F_14 ( V_2 , V_76 , 0 ) ;
F_22 ( 600 ) ;
break;
}
V_2 -> V_25 . V_78 = V_73 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_72 V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_86 ;
switch ( V_73 ) {
case V_74 :
break;
case V_75 :
switch ( V_2 -> V_25 . V_78 ) {
case V_77 :
F_5 ( V_2 , V_80 ,
V_81 | V_82 |
V_83 ,
V_81 | V_82 |
V_83 ) ;
V_86 = 0 ;
if ( V_4 -> V_36 && V_4 -> V_36 -> V_87 )
V_86 |= V_88 ;
if ( V_4 -> V_37 && V_4 -> V_37 -> V_87 )
V_86 |= V_89 ;
if ( V_4 -> V_38 && V_4 -> V_38 -> V_87 )
V_86 |= V_90 ;
F_5 ( V_2 , V_91 ,
V_88 |
V_89 |
V_90 , V_86 ) ;
F_5 ( V_2 , V_76 ,
V_92 , 0x80 ) ;
F_22 ( 100 ) ;
F_5 ( V_2 , V_76 ,
V_85 , V_85 ) ;
F_22 ( 100 ) ;
break;
case V_74 :
F_5 ( V_2 , V_80 ,
V_81 | V_82 |
V_83 ,
V_81 | V_82 |
V_83 ) ;
F_5 ( V_2 , V_76 ,
V_85 | V_92 , 0 ) ;
break;
case V_79 :
F_21 ( V_2 ) ;
break;
default:
break;
}
break;
case V_77 :
switch ( V_2 -> V_25 . V_78 ) {
case V_75 :
F_5 ( V_2 , V_93 ,
V_94 | V_95 ,
0 ) ;
F_5 ( V_2 , V_80 ,
V_81 | V_82 |
V_83 ,
V_81 | V_82 |
V_83 ) ;
break;
default:
break;
}
break;
case V_79 :
break;
}
V_2 -> V_25 . V_78 = V_73 ;
return 0 ;
}
static int F_24 ( unsigned int V_96 , unsigned int V_97 ,
struct V_98 * V_99 )
{
unsigned long long V_100 ;
unsigned int V_101 , V_102 , V_103 ;
F_25 ( L_5 , V_96 , V_97 ) ;
V_97 *= 4 ;
V_102 = V_97 / V_96 ;
if ( V_102 < 6 ) {
V_96 >>= 1 ;
V_99 -> V_104 = 1 ;
V_102 = V_97 / V_96 ;
} else
V_99 -> V_104 = 0 ;
if ( ( V_102 < 6 ) || ( V_102 > 12 ) ) {
F_26 ( L_6 , V_102 ) ;
return - V_20 ;
}
V_99 -> V_105 = V_102 ;
V_103 = V_97 % V_96 ;
V_100 = V_106 * ( long long ) V_103 ;
F_27 ( V_100 , V_96 ) ;
V_101 = V_100 & 0xFFFFFFFF ;
if ( ( V_101 % 10 ) >= 5 )
V_101 += 5 ;
V_101 /= 10 ;
V_99 -> V_107 = V_101 ;
F_25 ( L_7 ,
V_99 -> V_105 , V_99 -> V_107 , V_99 -> V_104 ) ;
return 0 ;
}
static int F_28 ( struct V_39 * V_40 , int V_108 ,
int V_96 , unsigned int V_109 , unsigned int V_110 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_86 ;
static struct V_98 V_99 ;
int V_111 ;
if ( V_109 && V_110 ) {
V_111 = F_24 ( V_109 , V_110 , & V_99 ) ;
if ( V_111 != 0 )
return V_111 ;
}
F_5 ( V_2 , V_112 , 0x1 , 0 ) ;
F_5 ( V_2 , V_91 , 0x1 , 0 ) ;
if ( ! V_109 || ! V_110 )
return 0 ;
V_86 = F_16 ( V_2 , V_113 ) & ~ 0x3f ;
V_86 |= V_99 . V_104 << 4 ;
V_86 |= V_99 . V_105 ;
if ( V_99 . V_107 ) {
V_86 |= 0x20 ;
F_14 ( V_2 , V_114 , ( V_99 . V_107 >> 18 ) & 0x3f ) ;
F_14 ( V_2 , V_115 , ( V_99 . V_107 >> 9 ) & 0x1ff ) ;
F_14 ( V_2 , V_116 , V_99 . V_107 & 0x1ff ) ;
}
F_14 ( V_2 , V_113 , V_86 ) ;
F_5 ( V_2 , V_91 , 0x1 , 0x1 ) ;
F_22 ( 250 ) ;
F_5 ( V_2 , V_112 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 ,
int V_117 , int div )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_86 ;
switch ( V_117 ) {
case V_118 :
V_86 = F_16 ( V_2 , V_112 ) & 0x1f9 ;
F_14 ( V_2 , V_112 , V_86 | div ) ;
break;
case V_119 :
V_86 = F_16 ( V_2 , V_112 ) & 0x1c7 ;
F_14 ( V_2 , V_112 , V_86 | div ) ;
break;
case V_120 :
V_86 = F_16 ( V_2 , V_113 ) & 0x03f ;
F_14 ( V_2 , V_113 , V_86 | div ) ;
break;
case V_121 :
V_86 = F_16 ( V_2 , V_122 ) & 0x03f ;
F_14 ( V_2 , V_122 , V_86 | div ) ;
break;
case V_123 :
V_86 = F_16 ( V_2 , V_124 ) & 0x1fd ;
F_14 ( V_2 , V_124 , V_86 | div ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_72 V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_125 ( V_2 , V_73 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_125 ( V_2 , V_79 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_125 ( V_2 , V_77 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_34 ( V_2 -> V_11 ) ;
int V_111 ;
V_4 -> V_125 = F_20 ;
if ( ! V_22 ) {
F_35 ( V_2 -> V_11 , L_8 ) ;
} else {
if ( V_22 -> V_126 > V_127 ) {
F_36 ( V_2 -> V_11 , L_9 , V_22 -> V_126 ) ;
V_22 -> V_126 = 0 ;
}
if ( V_22 -> V_30 )
V_4 -> V_125 = F_23 ;
}
V_111 = F_37 ( V_2 , 7 , 9 , V_4 -> V_128 ) ;
if ( V_111 < 0 ) {
F_36 ( V_2 -> V_11 , L_10 , V_111 ) ;
return V_111 ;
}
V_111 = F_38 ( V_2 ) ;
if ( V_111 < 0 ) {
F_36 ( V_2 -> V_11 , L_11 ) ;
return V_111 ;
}
V_4 -> V_125 ( V_2 , V_77 ) ;
F_5 ( V_2 , V_129 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_130 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_131 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_132 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_133 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_134 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_135 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_136 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_137 , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_138 , 0x100 , 0x100 ) ;
F_39 ( V_2 , V_139 ,
F_3 ( V_139 ) ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_125 ( V_2 , V_79 ) ;
return 0 ;
}
static T_2 int F_41 ( struct V_140 * V_141 ,
const struct V_142 * V_143 )
{
struct V_3 * V_4 ;
int V_111 ;
V_4 = F_42 ( & V_141 -> V_11 , sizeof( struct V_3 ) ,
V_144 ) ;
if ( V_4 == NULL )
return - V_145 ;
F_43 ( V_141 , V_4 ) ;
V_4 -> V_128 = V_146 ;
V_111 = F_44 ( & V_141 -> V_11 ,
& V_147 , & V_148 , 1 ) ;
return V_111 ;
}
static T_3 int F_45 ( struct V_140 * V_149 )
{
F_46 ( & V_149 -> V_11 ) ;
return 0 ;
}
static int T_4 F_47 ( void )
{
int V_111 = 0 ;
V_111 = F_48 ( & V_150 ) ;
if ( V_111 != 0 ) {
F_49 ( V_151 L_12 ,
V_111 ) ;
}
return V_111 ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_150 ) ;
}
