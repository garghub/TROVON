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
V_19 -> V_20 . V_21 . V_22 [ 0 ] = V_8 -> V_12 ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_8 ( V_17 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_12 = V_19 -> V_20 . V_21 . V_22 [ 0 ] ;
if ( V_12 > 1 )
return - V_23 ;
V_8 -> V_12 = V_12 ;
return F_2 ( V_6 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = V_6 -> V_2 -> V_26 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_27 * V_28 = & V_6 -> V_28 ;
struct V_29 * V_30 ;
F_11 ( V_28 , V_31 ,
F_4 ( V_31 ) ) ;
F_12 ( V_28 , V_32 , F_4 ( V_32 ) ) ;
if ( V_25 && V_25 -> V_33 ) {
F_11 ( V_28 , V_34 ,
F_4 ( V_34 ) ) ;
F_12 ( V_28 , V_35 ,
F_4 ( V_35 ) ) ;
} else {
F_11 ( V_28 , V_36 ,
F_4 ( V_36 ) ) ;
F_12 ( V_28 , V_37 ,
F_4 ( V_37 ) ) ;
}
F_13 (w, &codec->component.card->widgets, list) {
if ( V_30 -> V_28 != & V_6 -> V_28 )
continue;
if ( strcmp ( V_30 -> V_38 , L_2 ) == 0 )
V_8 -> V_39 = V_30 ;
if ( strcmp ( V_30 -> V_38 , L_3 ) == 0 )
V_8 -> V_40 = V_30 ;
if ( strcmp ( V_30 -> V_38 , L_4 ) == 0 )
V_8 -> V_41 = V_30 ;
}
return 0 ;
}
static int F_14 ( struct V_42 * V_43 ,
unsigned int V_44 )
{
struct V_5 * V_6 = V_43 -> V_6 ;
T_1 V_45 = 0 ;
switch ( V_44 & V_46 ) {
case V_47 :
V_45 |= 0x0040 ;
break;
case V_48 :
break;
default:
return - V_23 ;
}
switch ( V_44 & V_49 ) {
case V_50 :
V_45 |= 0x0002 ;
break;
case V_51 :
break;
case V_52 :
V_45 |= 0x0001 ;
break;
case V_53 :
V_45 |= 0x0003 ;
break;
case V_54 :
V_45 |= 0x0013 ;
break;
default:
return - V_23 ;
}
switch ( V_44 & V_55 ) {
case V_56 :
break;
case V_57 :
V_45 |= 0x0090 ;
break;
case V_58 :
V_45 |= 0x0080 ;
break;
case V_59 :
V_45 |= 0x0010 ;
break;
default:
return - V_23 ;
}
F_15 ( V_6 , V_60 , V_45 ) ;
return 0 ;
}
static int F_16 ( struct V_61 * V_62 ,
struct V_63 * V_64 ,
struct V_42 * V_65 )
{
struct V_5 * V_6 = V_65 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_45 = F_17 ( V_6 , V_60 ) & 0xfff3 ;
int V_10 ;
switch ( F_18 ( V_64 ) ) {
case 16 :
break;
case 20 :
V_45 |= 0x0004 ;
break;
case 24 :
V_45 |= 0x0008 ;
break;
default:
F_19 ( V_6 -> V_2 , L_5 ,
F_18 ( V_64 ) ) ;
return - V_23 ;
}
if ( V_62 -> V_66 == V_67 ) {
V_8 -> V_14 = F_20 ( V_64 ) ;
F_2 ( V_6 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_4 ( V_68 ) ; V_10 ++ )
if ( V_68 [ V_10 ] . V_69 == F_20 ( V_64 ) )
F_6 ( V_6 ,
V_70 , 0x7 ,
V_68 [ V_10 ] . V_9 ) ;
}
F_15 ( V_6 , V_60 , V_45 ) ;
return 0 ;
}
static int F_21 ( struct V_42 * V_65 , int V_71 )
{
struct V_5 * V_6 = V_65 -> V_6 ;
if ( V_71 )
F_6 ( V_6 , V_15 , 0x8 , 0x8 ) ;
else
F_6 ( V_6 , V_15 , 0x8 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
enum V_72 V_73 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_73 ) {
case V_74 :
break;
case V_75 :
F_6 ( V_6 , V_76 , 0x180 , 0x80 ) ;
break;
case V_77 :
if ( V_6 -> V_28 . V_78 == V_79 ) {
F_23 ( V_8 -> V_80 ) ;
F_15 ( V_6 , V_81 ,
V_82 | V_83 |
V_84 | V_85 ) ;
F_6 ( V_6 , V_76 , 0x80 , 0x80 ) ;
F_24 ( 100 ) ;
F_6 ( V_6 , V_76 , V_86 ,
V_86 ) ;
F_15 ( V_6 , V_81 , V_85 ) ;
}
F_6 ( V_6 , V_76 , 0x180 , 0x100 ) ;
break;
case V_79 :
F_15 ( V_6 , V_81 ,
V_82 | V_83 |
V_84 | V_85 ) ;
F_15 ( V_6 , V_76 , 0 ) ;
F_24 ( 600 ) ;
break;
}
V_6 -> V_28 . V_78 = V_73 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
enum V_72 V_73 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_3 ;
switch ( V_73 ) {
case V_74 :
break;
case V_75 :
switch ( V_6 -> V_28 . V_78 ) {
case V_77 :
F_6 ( V_6 , V_81 ,
V_82 | V_83 |
V_84 ,
V_82 | V_83 |
V_84 ) ;
V_3 = 0 ;
if ( V_8 -> V_39 && V_8 -> V_39 -> V_87 )
V_3 |= V_88 ;
if ( V_8 -> V_40 && V_8 -> V_40 -> V_87 )
V_3 |= V_89 ;
if ( V_8 -> V_41 && V_8 -> V_41 -> V_87 )
V_3 |= V_90 ;
F_6 ( V_6 , V_91 ,
V_88 |
V_89 |
V_90 , V_3 ) ;
F_6 ( V_6 , V_76 ,
V_92 , 0x80 ) ;
F_24 ( 100 ) ;
F_6 ( V_6 , V_76 ,
V_86 , V_86 ) ;
F_24 ( 100 ) ;
break;
case V_74 :
F_6 ( V_6 , V_81 ,
V_82 | V_83 |
V_84 ,
V_82 | V_83 |
V_84 ) ;
F_6 ( V_6 , V_76 ,
V_86 | V_92 , 0 ) ;
break;
case V_79 :
F_23 ( V_8 -> V_80 ) ;
break;
default:
break;
}
break;
case V_77 :
switch ( V_6 -> V_28 . V_78 ) {
case V_75 :
F_6 ( V_6 , V_93 ,
V_94 | V_95 ,
0 ) ;
F_6 ( V_6 , V_81 ,
V_82 | V_83 |
V_84 ,
V_82 | V_83 |
V_84 ) ;
break;
default:
break;
}
break;
case V_79 :
break;
}
V_6 -> V_28 . V_78 = V_73 ;
return 0 ;
}
static int F_26 ( unsigned int V_96 , unsigned int V_97 ,
struct V_98 * V_99 )
{
unsigned long long V_100 ;
unsigned int V_101 , V_102 , V_103 ;
F_27 ( L_6 , V_96 , V_97 ) ;
V_97 *= 4 ;
V_102 = V_97 / V_96 ;
if ( V_102 < 6 ) {
V_96 >>= 1 ;
V_99 -> V_104 = 1 ;
V_102 = V_97 / V_96 ;
} else
V_99 -> V_104 = 0 ;
if ( ( V_102 < 6 ) || ( V_102 > 12 ) ) {
F_28 ( L_7 , V_102 ) ;
return - V_23 ;
}
V_99 -> V_105 = V_102 ;
V_103 = V_97 % V_96 ;
V_100 = V_106 * ( long long ) V_103 ;
F_29 ( V_100 , V_96 ) ;
V_101 = V_100 & 0xFFFFFFFF ;
if ( ( V_101 % 10 ) >= 5 )
V_101 += 5 ;
V_101 /= 10 ;
V_99 -> V_107 = V_101 ;
F_27 ( L_8 ,
V_99 -> V_105 , V_99 -> V_107 , V_99 -> V_104 ) ;
return 0 ;
}
static int F_30 ( struct V_42 * V_43 , int V_108 ,
int V_96 , unsigned int V_109 , unsigned int V_110 )
{
struct V_5 * V_6 = V_43 -> V_6 ;
T_1 V_3 ;
static struct V_98 V_99 ;
int V_111 ;
if ( V_109 && V_110 ) {
V_111 = F_26 ( V_109 , V_110 , & V_99 ) ;
if ( V_111 != 0 )
return V_111 ;
}
F_6 ( V_6 , V_112 , 0x1 , 0 ) ;
F_6 ( V_6 , V_91 , 0x1 , 0 ) ;
if ( ! V_109 || ! V_110 )
return 0 ;
V_3 = F_17 ( V_6 , V_113 ) & ~ 0x3f ;
V_3 |= V_99 . V_104 << 4 ;
V_3 |= V_99 . V_105 ;
if ( V_99 . V_107 ) {
V_3 |= 0x20 ;
F_15 ( V_6 , V_114 , ( V_99 . V_107 >> 16 ) & 0xff ) ;
F_15 ( V_6 , V_115 , ( V_99 . V_107 >> 8 ) & 0xff ) ;
F_15 ( V_6 , V_116 , V_99 . V_107 & 0xff ) ;
}
F_15 ( V_6 , V_113 , V_3 ) ;
F_6 ( V_6 , V_91 , 0x1 , 0x1 ) ;
F_24 ( 250 ) ;
F_6 ( V_6 , V_112 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_31 ( struct V_42 * V_43 ,
int V_117 , int div )
{
struct V_5 * V_6 = V_43 -> V_6 ;
T_1 V_3 ;
switch ( V_117 ) {
case V_118 :
V_3 = F_17 ( V_6 , V_112 ) & 0x1f9 ;
F_15 ( V_6 , V_112 , V_3 | div ) ;
break;
case V_119 :
V_3 = F_17 ( V_6 , V_112 ) & 0x1c7 ;
F_15 ( V_6 , V_112 , V_3 | div ) ;
break;
case V_120 :
V_3 = F_17 ( V_6 , V_113 ) & 0x03f ;
F_15 ( V_6 , V_113 , V_3 | div ) ;
break;
case V_121 :
V_3 = F_17 ( V_6 , V_122 ) & 0x03f ;
F_15 ( V_6 , V_122 , V_3 | div ) ;
break;
case V_123 :
V_3 = F_17 ( V_6 , V_124 ) & 0x1fd ;
F_15 ( V_6 , V_124 , V_3 | div ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
enum V_72 V_73 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_125 ( V_6 , V_73 ) ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_125 ( V_6 , V_79 ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_125 ( V_6 , V_77 ) ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_36 ( V_6 -> V_2 ) ;
int V_111 ;
V_8 -> V_125 = F_22 ;
if ( ! V_25 ) {
F_37 ( V_6 -> V_2 , L_9 ) ;
} else {
if ( V_25 -> V_33 )
V_8 -> V_125 = F_25 ;
}
V_111 = F_38 ( V_6 ) ;
if ( V_111 < 0 ) {
F_19 ( V_6 -> V_2 , L_10 ) ;
return V_111 ;
}
V_8 -> V_125 ( V_6 , V_77 ) ;
F_6 ( V_6 , V_126 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_127 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_128 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_129 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_130 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_131 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_132 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_133 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_134 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_135 , 0x100 , 0x100 ) ;
F_39 ( V_6 , V_136 ,
F_4 ( V_136 ) ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_125 ( V_6 , V_79 ) ;
return 0 ;
}
static int F_41 ( struct V_137 * V_138 ,
const struct V_139 * V_140 )
{
struct V_24 * V_25 = F_36 ( & V_138 -> V_2 ) ;
struct V_7 * V_8 ;
int V_111 ;
V_8 = F_42 ( & V_138 -> V_2 , sizeof( struct V_7 ) ,
V_141 ) ;
if ( V_8 == NULL )
return - V_142 ;
V_8 -> V_80 = F_43 ( V_138 , & V_143 ) ;
if ( F_44 ( V_8 -> V_80 ) )
return F_45 ( V_8 -> V_80 ) ;
if ( V_25 && V_25 -> V_144 ) {
V_111 = F_46 ( V_8 -> V_80 , V_145 ,
0x4 , 0x4 ) ;
if ( V_111 != 0 ) {
F_19 ( & V_138 -> V_2 , L_11 ,
V_111 ) ;
return V_111 ;
}
}
F_47 ( V_138 , V_8 ) ;
V_111 = F_48 ( & V_138 -> V_2 ,
& V_146 , & V_147 , 1 ) ;
return V_111 ;
}
static int F_49 ( struct V_137 * V_148 )
{
F_50 ( & V_148 -> V_2 ) ;
return 0 ;
}
