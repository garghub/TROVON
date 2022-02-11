static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 , V_10 , V_11 ;
if ( V_8 -> V_12 ) {
V_11 = 1 ;
for ( V_10 = 2 ; V_10 < F_4 ( V_13 ) ; V_10 ++ ) {
if ( abs ( V_13 [ V_10 ] - V_8 -> V_14 ) <
abs ( V_13 [ V_11 ] - V_8 -> V_14 ) )
V_11 = V_10 ;
}
V_9 = V_11 << 1 ;
} else {
V_9 = 0 ;
}
F_5 ( V_6 -> V_2 , L_1 , V_9 ) ;
return F_6 ( V_6 , V_15 ,
0x6 , V_9 ) ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_8 ( V_17 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_19 -> V_20 . integer . V_20 [ 0 ] = V_8 -> V_12 ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_8 ( V_17 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_12 = V_19 -> V_20 . integer . V_20 [ 0 ] ;
if ( V_12 > 1 )
return - V_21 ;
V_8 -> V_12 = V_12 ;
return F_2 ( V_6 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_22 * V_23 = & V_8 -> V_23 ;
struct V_24 * V_25 = & V_6 -> V_25 ;
struct V_26 * V_27 ;
F_11 ( V_25 , V_28 ,
F_4 ( V_28 ) ) ;
F_12 ( V_25 , V_29 , F_4 ( V_29 ) ) ;
if ( V_23 && V_23 -> V_30 ) {
F_11 ( V_25 , V_31 ,
F_4 ( V_31 ) ) ;
F_12 ( V_25 , V_32 ,
F_4 ( V_32 ) ) ;
} else {
F_11 ( V_25 , V_33 ,
F_4 ( V_33 ) ) ;
F_12 ( V_25 , V_34 ,
F_4 ( V_34 ) ) ;
}
F_13 (w, &codec->component.card->widgets, list) {
if ( V_27 -> V_25 != & V_6 -> V_25 )
continue;
if ( strcmp ( V_27 -> V_35 , L_2 ) == 0 )
V_8 -> V_36 = V_27 ;
if ( strcmp ( V_27 -> V_35 , L_3 ) == 0 )
V_8 -> V_37 = V_27 ;
if ( strcmp ( V_27 -> V_35 , L_4 ) == 0 )
V_8 -> V_38 = V_27 ;
}
return 0 ;
}
static int F_14 ( struct V_39 * V_40 ,
unsigned int V_41 )
{
struct V_5 * V_6 = V_40 -> V_6 ;
T_1 V_42 = 0 ;
switch ( V_41 & V_43 ) {
case V_44 :
V_42 |= 0x0040 ;
break;
case V_45 :
break;
default:
return - V_21 ;
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
return - V_21 ;
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
return - V_21 ;
}
F_15 ( V_6 , V_57 , V_42 ) ;
return 0 ;
}
static int F_16 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_39 * V_62 )
{
struct V_5 * V_6 = V_62 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 = F_17 ( V_6 , V_57 ) & 0xfff3 ;
int V_10 ;
switch ( F_18 ( V_61 ) ) {
case 16 :
break;
case 20 :
V_42 |= 0x0004 ;
break;
case 24 :
V_42 |= 0x0008 ;
break;
default:
F_19 ( V_6 -> V_2 , L_5 ,
F_18 ( V_61 ) ) ;
return - V_21 ;
}
if ( V_59 -> V_63 == V_64 ) {
V_8 -> V_14 = F_20 ( V_61 ) ;
F_2 ( V_6 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_4 ( V_65 ) ; V_10 ++ )
if ( V_65 [ V_10 ] . V_66 == F_20 ( V_61 ) )
F_6 ( V_6 ,
V_67 , 0x7 ,
V_65 [ V_10 ] . V_9 ) ;
}
F_15 ( V_6 , V_57 , V_42 ) ;
return 0 ;
}
static int F_21 ( struct V_39 * V_62 , int V_68 )
{
struct V_5 * V_6 = V_62 -> V_6 ;
if ( V_68 )
F_6 ( V_6 , V_15 , 0x8 , 0x8 ) ;
else
F_6 ( V_6 , V_15 , 0x8 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
enum V_69 V_70 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_71 ;
switch ( V_70 ) {
case V_72 :
break;
case V_73 :
switch ( V_6 -> V_25 . V_74 ) {
case V_75 :
if ( ! F_23 ( V_8 -> V_76 ) ) {
V_71 = F_24 ( V_8 -> V_76 ) ;
if ( V_71 ) {
F_19 ( V_6 -> V_2 ,
L_6 ,
V_71 ) ;
return V_71 ;
}
}
F_6 ( V_6 , V_77 , 0x180 , 0x80 ) ;
break;
case V_72 :
if ( ! F_23 ( V_8 -> V_76 ) )
F_25 ( V_8 -> V_76 ) ;
break;
default:
break;
}
break;
case V_75 :
if ( V_6 -> V_25 . V_74 == V_78 ) {
F_26 ( V_8 -> V_79 ) ;
F_15 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 | V_84 ) ;
F_6 ( V_6 , V_77 , 0x80 , 0x80 ) ;
F_27 ( 100 ) ;
F_6 ( V_6 , V_77 , V_85 ,
V_85 ) ;
F_15 ( V_6 , V_80 , V_84 ) ;
}
F_6 ( V_6 , V_77 , 0x180 , 0x100 ) ;
break;
case V_78 :
F_15 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 | V_84 ) ;
F_15 ( V_6 , V_77 , 0 ) ;
F_27 ( 600 ) ;
break;
}
V_6 -> V_25 . V_74 = V_70 ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 ,
enum V_69 V_70 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_3 , V_71 ;
switch ( V_70 ) {
case V_72 :
break;
case V_73 :
switch ( V_6 -> V_25 . V_74 ) {
case V_75 :
F_6 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 ,
V_81 | V_82 |
V_83 ) ;
V_3 = 0 ;
if ( V_8 -> V_36 && V_8 -> V_36 -> V_86 )
V_3 |= V_87 ;
if ( V_8 -> V_37 && V_8 -> V_37 -> V_86 )
V_3 |= V_88 ;
if ( V_8 -> V_38 && V_8 -> V_38 -> V_86 )
V_3 |= V_89 ;
F_6 ( V_6 , V_90 ,
V_87 |
V_88 |
V_89 , V_3 ) ;
F_6 ( V_6 , V_77 ,
V_91 , 0x80 ) ;
F_27 ( 100 ) ;
F_6 ( V_6 , V_77 ,
V_85 , V_85 ) ;
F_27 ( 100 ) ;
if ( ! F_23 ( V_8 -> V_76 ) ) {
V_71 = F_24 ( V_8 -> V_76 ) ;
if ( V_71 ) {
F_19 ( V_6 -> V_2 ,
L_6 ,
V_71 ) ;
return V_71 ;
}
}
break;
case V_72 :
if ( ! F_23 ( V_8 -> V_76 ) )
F_25 ( V_8 -> V_76 ) ;
F_6 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 ,
V_81 | V_82 |
V_83 ) ;
F_6 ( V_6 , V_77 ,
V_85 | V_91 , 0 ) ;
break;
case V_78 :
F_26 ( V_8 -> V_79 ) ;
break;
default:
break;
}
break;
case V_75 :
switch ( V_6 -> V_25 . V_74 ) {
case V_73 :
F_6 ( V_6 , V_92 ,
V_93 | V_94 ,
0 ) ;
F_6 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 ,
V_81 | V_82 |
V_83 ) ;
break;
default:
break;
}
break;
case V_78 :
break;
}
V_6 -> V_25 . V_74 = V_70 ;
return 0 ;
}
static int F_29 ( unsigned int V_95 , unsigned int V_96 ,
struct V_97 * V_98 )
{
unsigned long long V_99 ;
unsigned int V_100 , V_101 , V_102 ;
F_30 ( L_7 , V_95 , V_96 ) ;
V_96 *= 4 ;
V_101 = V_96 / V_95 ;
if ( V_101 < 6 ) {
V_95 >>= 1 ;
V_98 -> V_103 = 1 ;
V_101 = V_96 / V_95 ;
} else
V_98 -> V_103 = 0 ;
if ( ( V_101 < 6 ) || ( V_101 > 12 ) ) {
F_31 ( L_8 , V_101 ) ;
return - V_21 ;
}
V_98 -> V_104 = V_101 ;
V_102 = V_96 % V_95 ;
V_99 = V_105 * ( long long ) V_102 ;
F_32 ( V_99 , V_95 ) ;
V_100 = V_99 & 0xFFFFFFFF ;
if ( ( V_100 % 10 ) >= 5 )
V_100 += 5 ;
V_100 /= 10 ;
V_98 -> V_106 = V_100 ;
F_30 ( L_9 ,
V_98 -> V_104 , V_98 -> V_106 , V_98 -> V_103 ) ;
return 0 ;
}
static int F_33 ( struct V_39 * V_40 , int V_107 ,
int V_95 , unsigned int V_108 , unsigned int V_109 )
{
struct V_5 * V_6 = V_40 -> V_6 ;
T_1 V_3 ;
static struct V_97 V_98 ;
int V_71 ;
if ( V_108 && V_109 ) {
V_71 = F_29 ( V_108 , V_109 , & V_98 ) ;
if ( V_71 != 0 )
return V_71 ;
}
F_6 ( V_6 , V_110 , 0x1 , 0 ) ;
F_6 ( V_6 , V_90 , 0x1 , 0 ) ;
if ( ! V_108 || ! V_109 )
return 0 ;
V_3 = F_17 ( V_6 , V_111 ) & ~ 0x3f ;
V_3 |= V_98 . V_103 << 4 ;
V_3 |= V_98 . V_104 ;
if ( V_98 . V_106 ) {
V_3 |= 0x20 ;
F_15 ( V_6 , V_112 , ( V_98 . V_106 >> 16 ) & 0xff ) ;
F_15 ( V_6 , V_113 , ( V_98 . V_106 >> 8 ) & 0xff ) ;
F_15 ( V_6 , V_114 , V_98 . V_106 & 0xff ) ;
}
F_15 ( V_6 , V_111 , V_3 ) ;
F_6 ( V_6 , V_90 , 0x1 , 0x1 ) ;
F_27 ( 250 ) ;
F_6 ( V_6 , V_110 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_34 ( struct V_39 * V_40 ,
int V_115 , int div )
{
struct V_5 * V_6 = V_40 -> V_6 ;
T_1 V_3 ;
switch ( V_115 ) {
case V_116 :
V_3 = F_17 ( V_6 , V_110 ) & 0x1f9 ;
F_15 ( V_6 , V_110 , V_3 | div ) ;
break;
case V_117 :
V_3 = F_17 ( V_6 , V_110 ) & 0x1c7 ;
F_15 ( V_6 , V_110 , V_3 | div ) ;
break;
case V_118 :
V_3 = F_17 ( V_6 , V_111 ) & 0x03f ;
F_15 ( V_6 , V_111 , V_3 | div ) ;
break;
case V_119 :
V_3 = F_17 ( V_6 , V_120 ) & 0x03f ;
F_15 ( V_6 , V_120 , V_3 | div ) ;
break;
case V_121 :
V_3 = F_17 ( V_6 , V_122 ) & 0x1fd ;
F_15 ( V_6 , V_122 , V_3 | div ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_35 ( struct V_5 * V_6 ,
enum V_69 V_70 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_123 ( V_6 , V_70 ) ;
}
static int F_36 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_22 * V_23 = & V_8 -> V_23 ;
if ( V_23 -> V_30 )
V_8 -> V_123 = F_28 ;
else
V_8 -> V_123 = F_22 ;
F_37 ( V_6 , V_124 ,
F_4 ( V_124 ) ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static void F_38 ( struct V_125 * V_126 ,
struct V_22 * V_23 )
{
const struct V_127 * V_128 = V_126 -> V_2 . V_129 ;
if ( F_39 ( V_128 , L_10 ) )
V_23 -> V_30 = true ;
if ( F_39 ( V_128 , L_11 ) )
V_23 -> V_130 = true ;
}
static int F_40 ( struct V_125 * V_126 ,
const struct V_131 * V_132 )
{
struct V_22 * V_23 = F_41 ( & V_126 -> V_2 ) ;
struct V_7 * V_8 ;
int V_71 ;
V_8 = F_42 ( & V_126 -> V_2 , sizeof( struct V_7 ) ,
V_133 ) ;
if ( V_8 == NULL )
return - V_134 ;
V_8 -> V_76 = F_43 ( & V_126 -> V_2 , L_12 ) ;
if ( F_23 ( V_8 -> V_76 ) ) {
if ( F_44 ( V_8 -> V_76 ) == - V_135 )
return - V_135 ;
}
V_8 -> V_79 = F_45 ( V_126 , & V_136 ) ;
if ( F_23 ( V_8 -> V_79 ) )
return F_44 ( V_8 -> V_79 ) ;
if ( V_23 )
memcpy ( & V_8 -> V_23 , V_23 , sizeof( struct V_22 ) ) ;
else if ( V_126 -> V_2 . V_129 )
F_38 ( V_126 , & V_8 -> V_23 ) ;
V_71 = F_46 ( V_8 -> V_79 ) ;
if ( V_71 != 0 ) {
F_19 ( & V_126 -> V_2 , L_13 ) ;
return V_71 ;
}
if ( V_8 -> V_23 . V_130 ) {
V_71 = F_47 ( V_8 -> V_79 , V_137 ,
0x4 , 0x4 ) ;
if ( V_71 != 0 ) {
F_19 ( & V_126 -> V_2 , L_14 ,
V_71 ) ;
return V_71 ;
}
}
F_47 ( V_8 -> V_79 , V_138 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_139 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_140 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_141 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_142 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_143 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_144 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_145 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_146 , 0x100 , 0x100 ) ;
F_47 ( V_8 -> V_79 , V_147 , 0x100 , 0x100 ) ;
F_48 ( V_126 , V_8 ) ;
V_71 = F_49 ( & V_126 -> V_2 ,
& V_148 , & V_149 , 1 ) ;
return V_71 ;
}
static int F_50 ( struct V_125 * V_150 )
{
F_51 ( & V_150 -> V_2 ) ;
return 0 ;
}
