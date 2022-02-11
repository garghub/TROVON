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
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_24 * V_25 = & V_8 -> V_25 ;
struct V_26 * V_27 = & V_6 -> V_27 ;
struct V_28 * V_29 ;
F_11 ( V_27 , V_30 ,
F_4 ( V_30 ) ) ;
F_12 ( V_27 , V_31 , F_4 ( V_31 ) ) ;
if ( V_25 && V_25 -> V_32 ) {
F_11 ( V_27 , V_33 ,
F_4 ( V_33 ) ) ;
F_12 ( V_27 , V_34 ,
F_4 ( V_34 ) ) ;
} else {
F_11 ( V_27 , V_35 ,
F_4 ( V_35 ) ) ;
F_12 ( V_27 , V_36 ,
F_4 ( V_36 ) ) ;
}
F_13 (w, &codec->component.card->widgets, list) {
if ( V_29 -> V_27 != & V_6 -> V_27 )
continue;
if ( strcmp ( V_29 -> V_37 , L_2 ) == 0 )
V_8 -> V_38 = V_29 ;
if ( strcmp ( V_29 -> V_37 , L_3 ) == 0 )
V_8 -> V_39 = V_29 ;
if ( strcmp ( V_29 -> V_37 , L_4 ) == 0 )
V_8 -> V_40 = V_29 ;
}
return 0 ;
}
static int F_14 ( struct V_41 * V_42 ,
unsigned int V_43 )
{
struct V_5 * V_6 = V_42 -> V_6 ;
T_1 V_44 = 0 ;
switch ( V_43 & V_45 ) {
case V_46 :
V_44 |= 0x0040 ;
break;
case V_47 :
break;
default:
return - V_23 ;
}
switch ( V_43 & V_48 ) {
case V_49 :
V_44 |= 0x0002 ;
break;
case V_50 :
break;
case V_51 :
V_44 |= 0x0001 ;
break;
case V_52 :
V_44 |= 0x0003 ;
break;
case V_53 :
V_44 |= 0x0013 ;
break;
default:
return - V_23 ;
}
switch ( V_43 & V_54 ) {
case V_55 :
break;
case V_56 :
V_44 |= 0x0090 ;
break;
case V_57 :
V_44 |= 0x0080 ;
break;
case V_58 :
V_44 |= 0x0010 ;
break;
default:
return - V_23 ;
}
F_15 ( V_6 , V_59 , V_44 ) ;
return 0 ;
}
static int F_16 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_41 * V_64 )
{
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_44 = F_17 ( V_6 , V_59 ) & 0xfff3 ;
int V_10 ;
switch ( F_18 ( V_63 ) ) {
case 16 :
break;
case 20 :
V_44 |= 0x0004 ;
break;
case 24 :
V_44 |= 0x0008 ;
break;
default:
F_19 ( V_6 -> V_2 , L_5 ,
F_18 ( V_63 ) ) ;
return - V_23 ;
}
if ( V_61 -> V_65 == V_66 ) {
V_8 -> V_14 = F_20 ( V_63 ) ;
F_2 ( V_6 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_4 ( V_67 ) ; V_10 ++ )
if ( V_67 [ V_10 ] . V_68 == F_20 ( V_63 ) )
F_6 ( V_6 ,
V_69 , 0x7 ,
V_67 [ V_10 ] . V_9 ) ;
}
F_15 ( V_6 , V_59 , V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_41 * V_64 , int V_70 )
{
struct V_5 * V_6 = V_64 -> V_6 ;
if ( V_70 )
F_6 ( V_6 , V_15 , 0x8 , 0x8 ) ;
else
F_6 ( V_6 , V_15 , 0x8 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
enum V_71 V_72 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_72 ) {
case V_73 :
break;
case V_74 :
F_6 ( V_6 , V_75 , 0x180 , 0x80 ) ;
break;
case V_76 :
if ( V_6 -> V_27 . V_77 == V_78 ) {
F_23 ( V_8 -> V_79 ) ;
F_15 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 | V_84 ) ;
F_6 ( V_6 , V_75 , 0x80 , 0x80 ) ;
F_24 ( 100 ) ;
F_6 ( V_6 , V_75 , V_85 ,
V_85 ) ;
F_15 ( V_6 , V_80 , V_84 ) ;
}
F_6 ( V_6 , V_75 , 0x180 , 0x100 ) ;
break;
case V_78 :
F_15 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 | V_84 ) ;
F_15 ( V_6 , V_75 , 0 ) ;
F_24 ( 600 ) ;
break;
}
V_6 -> V_27 . V_77 = V_72 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
enum V_71 V_72 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_3 ;
switch ( V_72 ) {
case V_73 :
break;
case V_74 :
switch ( V_6 -> V_27 . V_77 ) {
case V_76 :
F_6 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 ,
V_81 | V_82 |
V_83 ) ;
V_3 = 0 ;
if ( V_8 -> V_38 && V_8 -> V_38 -> V_86 )
V_3 |= V_87 ;
if ( V_8 -> V_39 && V_8 -> V_39 -> V_86 )
V_3 |= V_88 ;
if ( V_8 -> V_40 && V_8 -> V_40 -> V_86 )
V_3 |= V_89 ;
F_6 ( V_6 , V_90 ,
V_87 |
V_88 |
V_89 , V_3 ) ;
F_6 ( V_6 , V_75 ,
V_91 , 0x80 ) ;
F_24 ( 100 ) ;
F_6 ( V_6 , V_75 ,
V_85 , V_85 ) ;
F_24 ( 100 ) ;
break;
case V_73 :
F_6 ( V_6 , V_80 ,
V_81 | V_82 |
V_83 ,
V_81 | V_82 |
V_83 ) ;
F_6 ( V_6 , V_75 ,
V_85 | V_91 , 0 ) ;
break;
case V_78 :
F_23 ( V_8 -> V_79 ) ;
break;
default:
break;
}
break;
case V_76 :
switch ( V_6 -> V_27 . V_77 ) {
case V_74 :
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
V_6 -> V_27 . V_77 = V_72 ;
return 0 ;
}
static int F_26 ( unsigned int V_95 , unsigned int V_96 ,
struct V_97 * V_98 )
{
unsigned long long V_99 ;
unsigned int V_100 , V_101 , V_102 ;
F_27 ( L_6 , V_95 , V_96 ) ;
V_96 *= 4 ;
V_101 = V_96 / V_95 ;
if ( V_101 < 6 ) {
V_95 >>= 1 ;
V_98 -> V_103 = 1 ;
V_101 = V_96 / V_95 ;
} else
V_98 -> V_103 = 0 ;
if ( ( V_101 < 6 ) || ( V_101 > 12 ) ) {
F_28 ( L_7 , V_101 ) ;
return - V_23 ;
}
V_98 -> V_104 = V_101 ;
V_102 = V_96 % V_95 ;
V_99 = V_105 * ( long long ) V_102 ;
F_29 ( V_99 , V_95 ) ;
V_100 = V_99 & 0xFFFFFFFF ;
if ( ( V_100 % 10 ) >= 5 )
V_100 += 5 ;
V_100 /= 10 ;
V_98 -> V_106 = V_100 ;
F_27 ( L_8 ,
V_98 -> V_104 , V_98 -> V_106 , V_98 -> V_103 ) ;
return 0 ;
}
static int F_30 ( struct V_41 * V_42 , int V_107 ,
int V_95 , unsigned int V_108 , unsigned int V_109 )
{
struct V_5 * V_6 = V_42 -> V_6 ;
T_1 V_3 ;
static struct V_97 V_98 ;
int V_110 ;
if ( V_108 && V_109 ) {
V_110 = F_26 ( V_108 , V_109 , & V_98 ) ;
if ( V_110 != 0 )
return V_110 ;
}
F_6 ( V_6 , V_111 , 0x1 , 0 ) ;
F_6 ( V_6 , V_90 , 0x1 , 0 ) ;
if ( ! V_108 || ! V_109 )
return 0 ;
V_3 = F_17 ( V_6 , V_112 ) & ~ 0x3f ;
V_3 |= V_98 . V_103 << 4 ;
V_3 |= V_98 . V_104 ;
if ( V_98 . V_106 ) {
V_3 |= 0x20 ;
F_15 ( V_6 , V_113 , ( V_98 . V_106 >> 16 ) & 0xff ) ;
F_15 ( V_6 , V_114 , ( V_98 . V_106 >> 8 ) & 0xff ) ;
F_15 ( V_6 , V_115 , V_98 . V_106 & 0xff ) ;
}
F_15 ( V_6 , V_112 , V_3 ) ;
F_6 ( V_6 , V_90 , 0x1 , 0x1 ) ;
F_24 ( 250 ) ;
F_6 ( V_6 , V_111 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_31 ( struct V_41 * V_42 ,
int V_116 , int div )
{
struct V_5 * V_6 = V_42 -> V_6 ;
T_1 V_3 ;
switch ( V_116 ) {
case V_117 :
V_3 = F_17 ( V_6 , V_111 ) & 0x1f9 ;
F_15 ( V_6 , V_111 , V_3 | div ) ;
break;
case V_118 :
V_3 = F_17 ( V_6 , V_111 ) & 0x1c7 ;
F_15 ( V_6 , V_111 , V_3 | div ) ;
break;
case V_119 :
V_3 = F_17 ( V_6 , V_112 ) & 0x03f ;
F_15 ( V_6 , V_112 , V_3 | div ) ;
break;
case V_120 :
V_3 = F_17 ( V_6 , V_121 ) & 0x03f ;
F_15 ( V_6 , V_121 , V_3 | div ) ;
break;
case V_122 :
V_3 = F_17 ( V_6 , V_123 ) & 0x1fd ;
F_15 ( V_6 , V_123 , V_3 | div ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
enum V_71 V_72 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_124 ( V_6 , V_72 ) ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_24 * V_25 = & V_8 -> V_25 ;
if ( V_25 -> V_32 )
V_8 -> V_124 = F_25 ;
else
V_8 -> V_124 = F_22 ;
F_34 ( V_6 , V_125 ,
F_4 ( V_125 ) ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static void F_35 ( struct V_126 * V_127 ,
struct V_24 * V_25 )
{
const struct V_128 * V_129 = V_127 -> V_2 . V_130 ;
if ( F_36 ( V_129 , L_9 ) )
V_25 -> V_32 = true ;
if ( F_36 ( V_129 , L_10 ) )
V_25 -> V_131 = true ;
}
static int F_37 ( struct V_126 * V_127 ,
const struct V_132 * V_133 )
{
struct V_24 * V_25 = F_38 ( & V_127 -> V_2 ) ;
struct V_7 * V_8 ;
int V_110 ;
V_8 = F_39 ( & V_127 -> V_2 , sizeof( struct V_7 ) ,
V_134 ) ;
if ( V_8 == NULL )
return - V_135 ;
V_8 -> V_79 = F_40 ( V_127 , & V_136 ) ;
if ( F_41 ( V_8 -> V_79 ) )
return F_42 ( V_8 -> V_79 ) ;
if ( V_25 )
memcpy ( & V_8 -> V_25 , V_25 , sizeof( struct V_24 ) ) ;
else if ( V_127 -> V_2 . V_130 )
F_35 ( V_127 , & V_8 -> V_25 ) ;
V_110 = F_43 ( V_8 -> V_79 ) ;
if ( V_110 != 0 ) {
F_19 ( & V_127 -> V_2 , L_11 ) ;
return V_110 ;
}
if ( V_8 -> V_25 . V_131 ) {
V_110 = F_44 ( V_8 -> V_79 , V_137 ,
0x4 , 0x4 ) ;
if ( V_110 != 0 ) {
F_19 ( & V_127 -> V_2 , L_12 ,
V_110 ) ;
return V_110 ;
}
}
F_44 ( V_8 -> V_79 , V_138 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_139 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_140 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_141 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_142 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_143 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_144 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_145 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_146 , 0x100 , 0x100 ) ;
F_44 ( V_8 -> V_79 , V_147 , 0x100 , 0x100 ) ;
F_45 ( V_127 , V_8 ) ;
V_110 = F_46 ( & V_127 -> V_2 ,
& V_148 , & V_149 , 1 ) ;
return V_110 ;
}
static int F_47 ( struct V_126 * V_150 )
{
F_48 ( & V_150 -> V_2 ) ;
return 0 ;
}
