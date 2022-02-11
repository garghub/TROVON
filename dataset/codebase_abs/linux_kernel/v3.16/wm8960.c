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
F_13 (w, &codec->card->widgets, list) {
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
T_2 V_66 = F_18 ( V_64 ) ;
int V_10 ;
switch ( V_66 ) {
case V_67 :
case V_68 :
break;
case V_69 :
case V_70 :
V_45 |= 0x0004 ;
break;
case V_71 :
case V_72 :
V_45 |= 0x0008 ;
break;
default:
F_19 ( V_6 -> V_2 , L_5 , V_66 ) ;
return - V_23 ;
}
if ( V_62 -> V_73 == V_74 ) {
V_8 -> V_14 = F_20 ( V_64 ) ;
F_2 ( V_6 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_4 ( V_75 ) ; V_10 ++ )
if ( V_75 [ V_10 ] . V_76 == F_20 ( V_64 ) )
F_6 ( V_6 ,
V_77 , 0x7 ,
V_75 [ V_10 ] . V_9 ) ;
}
F_15 ( V_6 , V_60 , V_45 ) ;
return 0 ;
}
static int F_21 ( struct V_42 * V_65 , int V_78 )
{
struct V_5 * V_6 = V_65 -> V_6 ;
if ( V_78 )
F_6 ( V_6 , V_15 , 0x8 , 0x8 ) ;
else
F_6 ( V_6 , V_15 , 0x8 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
enum V_79 V_80 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_80 ) {
case V_81 :
break;
case V_82 :
F_6 ( V_6 , V_83 , 0x180 , 0x80 ) ;
break;
case V_84 :
if ( V_6 -> V_28 . V_85 == V_86 ) {
F_23 ( V_8 -> V_87 ) ;
F_15 ( V_6 , V_88 ,
V_89 | V_90 |
V_91 | V_92 ) ;
F_6 ( V_6 , V_83 , 0x80 , 0x80 ) ;
F_24 ( 100 ) ;
F_6 ( V_6 , V_83 , V_93 ,
V_93 ) ;
F_15 ( V_6 , V_88 , V_92 ) ;
}
F_6 ( V_6 , V_83 , 0x180 , 0x100 ) ;
break;
case V_86 :
F_15 ( V_6 , V_88 ,
V_89 | V_90 |
V_91 | V_92 ) ;
F_15 ( V_6 , V_83 , 0 ) ;
F_24 ( 600 ) ;
break;
}
V_6 -> V_28 . V_85 = V_80 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
enum V_79 V_80 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_3 ;
switch ( V_80 ) {
case V_81 :
break;
case V_82 :
switch ( V_6 -> V_28 . V_85 ) {
case V_84 :
F_6 ( V_6 , V_88 ,
V_89 | V_90 |
V_91 ,
V_89 | V_90 |
V_91 ) ;
V_3 = 0 ;
if ( V_8 -> V_39 && V_8 -> V_39 -> V_94 )
V_3 |= V_95 ;
if ( V_8 -> V_40 && V_8 -> V_40 -> V_94 )
V_3 |= V_96 ;
if ( V_8 -> V_41 && V_8 -> V_41 -> V_94 )
V_3 |= V_97 ;
F_6 ( V_6 , V_98 ,
V_95 |
V_96 |
V_97 , V_3 ) ;
F_6 ( V_6 , V_83 ,
V_99 , 0x80 ) ;
F_24 ( 100 ) ;
F_6 ( V_6 , V_83 ,
V_93 , V_93 ) ;
F_24 ( 100 ) ;
break;
case V_81 :
F_6 ( V_6 , V_88 ,
V_89 | V_90 |
V_91 ,
V_89 | V_90 |
V_91 ) ;
F_6 ( V_6 , V_83 ,
V_93 | V_99 , 0 ) ;
break;
case V_86 :
F_23 ( V_8 -> V_87 ) ;
break;
default:
break;
}
break;
case V_84 :
switch ( V_6 -> V_28 . V_85 ) {
case V_82 :
F_6 ( V_6 , V_100 ,
V_101 | V_102 ,
0 ) ;
F_6 ( V_6 , V_88 ,
V_89 | V_90 |
V_91 ,
V_89 | V_90 |
V_91 ) ;
break;
default:
break;
}
break;
case V_86 :
break;
}
V_6 -> V_28 . V_85 = V_80 ;
return 0 ;
}
static int F_26 ( unsigned int V_103 , unsigned int V_104 ,
struct V_105 * V_106 )
{
unsigned long long V_107 ;
unsigned int V_108 , V_109 , V_110 ;
F_27 ( L_6 , V_103 , V_104 ) ;
V_104 *= 4 ;
V_109 = V_104 / V_103 ;
if ( V_109 < 6 ) {
V_103 >>= 1 ;
V_106 -> V_111 = 1 ;
V_109 = V_104 / V_103 ;
} else
V_106 -> V_111 = 0 ;
if ( ( V_109 < 6 ) || ( V_109 > 12 ) ) {
F_28 ( L_7 , V_109 ) ;
return - V_23 ;
}
V_106 -> V_112 = V_109 ;
V_110 = V_104 % V_103 ;
V_107 = V_113 * ( long long ) V_110 ;
F_29 ( V_107 , V_103 ) ;
V_108 = V_107 & 0xFFFFFFFF ;
if ( ( V_108 % 10 ) >= 5 )
V_108 += 5 ;
V_108 /= 10 ;
V_106 -> V_114 = V_108 ;
F_27 ( L_8 ,
V_106 -> V_112 , V_106 -> V_114 , V_106 -> V_111 ) ;
return 0 ;
}
static int F_30 ( struct V_42 * V_43 , int V_115 ,
int V_103 , unsigned int V_116 , unsigned int V_117 )
{
struct V_5 * V_6 = V_43 -> V_6 ;
T_1 V_3 ;
static struct V_105 V_106 ;
int V_118 ;
if ( V_116 && V_117 ) {
V_118 = F_26 ( V_116 , V_117 , & V_106 ) ;
if ( V_118 != 0 )
return V_118 ;
}
F_6 ( V_6 , V_119 , 0x1 , 0 ) ;
F_6 ( V_6 , V_98 , 0x1 , 0 ) ;
if ( ! V_116 || ! V_117 )
return 0 ;
V_3 = F_17 ( V_6 , V_120 ) & ~ 0x3f ;
V_3 |= V_106 . V_111 << 4 ;
V_3 |= V_106 . V_112 ;
if ( V_106 . V_114 ) {
V_3 |= 0x20 ;
F_15 ( V_6 , V_121 , ( V_106 . V_114 >> 16 ) & 0xff ) ;
F_15 ( V_6 , V_122 , ( V_106 . V_114 >> 8 ) & 0xff ) ;
F_15 ( V_6 , V_123 , V_106 . V_114 & 0xff ) ;
}
F_15 ( V_6 , V_120 , V_3 ) ;
F_6 ( V_6 , V_98 , 0x1 , 0x1 ) ;
F_24 ( 250 ) ;
F_6 ( V_6 , V_119 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_31 ( struct V_42 * V_43 ,
int V_124 , int div )
{
struct V_5 * V_6 = V_43 -> V_6 ;
T_1 V_3 ;
switch ( V_124 ) {
case V_125 :
V_3 = F_17 ( V_6 , V_119 ) & 0x1f9 ;
F_15 ( V_6 , V_119 , V_3 | div ) ;
break;
case V_126 :
V_3 = F_17 ( V_6 , V_119 ) & 0x1c7 ;
F_15 ( V_6 , V_119 , V_3 | div ) ;
break;
case V_127 :
V_3 = F_17 ( V_6 , V_120 ) & 0x03f ;
F_15 ( V_6 , V_120 , V_3 | div ) ;
break;
case V_128 :
V_3 = F_17 ( V_6 , V_129 ) & 0x03f ;
F_15 ( V_6 , V_129 , V_3 | div ) ;
break;
case V_130 :
V_3 = F_17 ( V_6 , V_131 ) & 0x1fd ;
F_15 ( V_6 , V_131 , V_3 | div ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
enum V_79 V_80 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_132 ( V_6 , V_80 ) ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_132 ( V_6 , V_86 ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_132 ( V_6 , V_84 ) ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_36 ( V_6 -> V_2 ) ;
int V_118 ;
V_8 -> V_132 = F_22 ;
if ( ! V_25 ) {
F_37 ( V_6 -> V_2 , L_9 ) ;
} else {
if ( V_25 -> V_33 )
V_8 -> V_132 = F_25 ;
}
V_118 = F_38 ( V_6 ) ;
if ( V_118 < 0 ) {
F_19 ( V_6 -> V_2 , L_10 ) ;
return V_118 ;
}
V_8 -> V_132 ( V_6 , V_84 ) ;
F_6 ( V_6 , V_133 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_134 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_135 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_136 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_137 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_138 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_139 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_140 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_141 , 0x100 , 0x100 ) ;
F_6 ( V_6 , V_142 , 0x100 , 0x100 ) ;
F_39 ( V_6 , V_143 ,
F_4 ( V_143 ) ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_132 ( V_6 , V_86 ) ;
return 0 ;
}
static int F_41 ( struct V_144 * V_145 ,
const struct V_146 * V_147 )
{
struct V_24 * V_25 = F_36 ( & V_145 -> V_2 ) ;
struct V_7 * V_8 ;
int V_118 ;
V_8 = F_42 ( & V_145 -> V_2 , sizeof( struct V_7 ) ,
V_148 ) ;
if ( V_8 == NULL )
return - V_149 ;
V_8 -> V_87 = F_43 ( V_145 , & V_150 ) ;
if ( F_44 ( V_8 -> V_87 ) )
return F_45 ( V_8 -> V_87 ) ;
if ( V_25 && V_25 -> V_151 ) {
V_118 = F_46 ( V_8 -> V_87 , V_152 ,
0x4 , 0x4 ) ;
if ( V_118 != 0 ) {
F_19 ( & V_145 -> V_2 , L_11 ,
V_118 ) ;
return V_118 ;
}
}
F_47 ( V_145 , V_8 ) ;
V_118 = F_48 ( & V_145 -> V_2 ,
& V_153 , & V_154 , 1 ) ;
return V_118 ;
}
static int F_49 ( struct V_144 * V_155 )
{
F_50 ( & V_155 -> V_2 ) ;
return 0 ;
}
