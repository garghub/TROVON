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
unsigned int V_12 = V_19 -> V_20 . integer . V_20 [ 0 ] ;
if ( V_12 > 1 )
return - V_21 ;
V_8 -> V_12 = V_12 ;
return F_2 ( V_6 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_22 * V_23 = & V_8 -> V_23 ;
struct V_24 * V_25 = F_11 ( V_6 ) ;
struct V_26 * V_27 ;
F_12 ( V_25 , V_28 ,
F_4 ( V_28 ) ) ;
F_13 ( V_25 , V_29 , F_4 ( V_29 ) ) ;
if ( V_23 && V_23 -> V_30 ) {
F_12 ( V_25 , V_31 ,
F_4 ( V_31 ) ) ;
F_13 ( V_25 , V_32 ,
F_4 ( V_32 ) ) ;
} else {
F_12 ( V_25 , V_33 ,
F_4 ( V_33 ) ) ;
F_13 ( V_25 , V_34 ,
F_4 ( V_34 ) ) ;
}
F_14 (w, &codec->component.card->widgets, list) {
if ( V_27 -> V_25 != V_25 )
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
static int F_15 ( struct V_39 * V_40 ,
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
F_16 ( V_6 , V_57 , V_42 ) ;
return 0 ;
}
static
int F_17 ( struct V_7 * V_8 , int V_58 ,
int * V_59 , int * V_60 , int * V_61 )
{
int V_62 , V_63 , V_14 ;
int V_10 , V_64 , V_65 ;
int V_66 , V_67 = V_58 ;
* V_61 = - 1 ;
V_63 = V_8 -> V_63 ;
V_14 = V_8 -> V_14 ;
for ( V_10 = 0 ; V_10 < F_4 ( V_68 ) ; ++ V_10 ) {
if ( V_68 [ V_10 ] == - 1 )
continue;
V_62 = V_58 / V_68 [ V_10 ] ;
for ( V_64 = 0 ; V_64 < F_4 ( V_69 ) ; ++ V_64 ) {
if ( V_62 != V_69 [ V_64 ] * V_14 )
continue;
for ( V_65 = 0 ; V_65 < F_4 ( V_70 ) ; ++ V_65 ) {
V_66 = V_62 - V_63 * V_70 [ V_65 ] / 10 ;
if ( V_66 == 0 ) {
* V_59 = V_10 ;
* V_60 = V_64 ;
* V_61 = V_65 ;
break;
}
if ( V_66 > 0 && V_67 > V_66 ) {
* V_59 = V_10 ;
* V_60 = V_64 ;
* V_61 = V_65 ;
V_67 = V_66 ;
}
}
if ( V_65 != F_4 ( V_70 ) )
break;
}
if ( V_64 != F_4 ( V_69 ) )
break;
}
return * V_61 ;
}
static
int F_18 ( struct V_5 * V_6 , int V_71 ,
int * V_59 , int * V_60 , int * V_61 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_62 , V_63 , V_14 , V_72 ;
int V_66 , V_67 , V_73 ;
int V_10 , V_64 , V_65 ;
V_63 = V_8 -> V_63 ;
V_14 = V_8 -> V_14 ;
V_67 = V_71 ;
V_73 = - V_21 ;
* V_59 = * V_60 = * V_61 = - 1 ;
for ( V_10 = 0 ; V_10 < F_4 ( V_68 ) ; ++ V_10 ) {
if ( V_68 [ V_10 ] == - 1 )
continue;
for ( V_64 = 0 ; V_64 < F_4 ( V_69 ) ; ++ V_64 ) {
V_62 = V_14 * V_69 [ V_64 ] ;
V_72 = V_62 * V_68 [ V_10 ] ;
for ( V_65 = 0 ; V_65 < F_4 ( V_70 ) ; ++ V_65 ) {
if ( ! F_19 ( V_71 , V_72 ) )
continue;
V_66 = V_62 - V_63 * V_70 [ V_65 ] / 10 ;
if ( V_66 == 0 ) {
* V_59 = V_10 ;
* V_60 = V_64 ;
* V_61 = V_65 ;
return V_72 ;
}
if ( V_66 > 0 && V_67 > V_66 ) {
* V_59 = V_10 ;
* V_60 = V_64 ;
* V_61 = V_65 ;
V_67 = V_66 ;
V_73 = V_72 ;
}
}
}
}
return V_73 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_72 , V_71 ;
T_1 V_74 = F_21 ( V_6 , V_57 ) ;
int V_10 , V_64 , V_65 ;
int V_75 ;
if ( ! ( V_74 & ( 1 << 6 ) ) ) {
F_5 ( V_6 -> V_2 ,
L_5 ) ;
return 0 ;
}
if ( V_8 -> V_76 != V_77 && ! V_8 -> V_71 ) {
F_22 ( V_6 -> V_2 , L_6 ) ;
return - V_21 ;
}
V_71 = V_8 -> V_71 ;
if ( V_8 -> V_76 == V_78 ) {
F_23 ( V_6 , 0 , 0 ) ;
V_72 = V_71 ;
} else if ( V_8 -> V_62 ) {
V_72 = V_8 -> V_62 ;
} else {
F_22 ( V_6 -> V_2 , L_7 ) ;
return - V_21 ;
}
if ( V_8 -> V_76 != V_79 ) {
V_75 = F_17 ( V_8 , V_72 , & V_10 , & V_64 , & V_65 ) ;
if ( V_75 >= 0 ) {
goto V_80;
} else if ( V_8 -> V_76 != V_78 ) {
F_22 ( V_6 -> V_2 , L_8 ) ;
return - V_21 ;
}
}
V_72 = F_18 ( V_6 , V_71 , & V_10 , & V_64 , & V_65 ) ;
if ( V_72 < 0 ) {
F_22 ( V_6 -> V_2 , L_9 ) ;
return V_72 ;
}
F_23 ( V_6 , V_71 , V_72 ) ;
V_80:
F_6 ( V_6 , V_81 , 3 << 1 , V_10 << 1 ) ;
F_6 ( V_6 , V_81 , 0x7 << 3 , V_64 << 3 ) ;
F_6 ( V_6 , V_81 , 0x7 << 6 , V_64 << 6 ) ;
F_6 ( V_6 , V_82 , 0xf , V_65 ) ;
return 0 ;
}
static int F_24 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
struct V_39 * V_87 )
{
struct V_5 * V_6 = V_87 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 = F_21 ( V_6 , V_57 ) & 0xfff3 ;
bool V_88 = V_84 -> V_89 == V_90 ;
int V_10 ;
V_8 -> V_63 = F_25 ( V_86 ) ;
if ( F_26 ( V_86 ) == 1 )
V_8 -> V_63 *= 2 ;
switch ( F_27 ( V_86 ) ) {
case 16 :
break;
case 20 :
V_42 |= 0x0004 ;
break;
case 24 :
V_42 |= 0x0008 ;
break;
case 32 :
if ( ( V_42 & 0x3 ) != 0 ) {
V_42 |= 0x000c ;
break;
}
default:
F_22 ( V_6 -> V_2 , L_10 ,
F_27 ( V_86 ) ) ;
return - V_21 ;
}
V_8 -> V_14 = F_28 ( V_86 ) ;
if ( V_88 ) {
F_2 ( V_6 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_4 ( V_91 ) ; V_10 ++ )
if ( V_91 [ V_10 ] . V_92 == F_28 ( V_86 ) )
F_6 ( V_6 ,
V_93 , 0x7 ,
V_91 [ V_10 ] . V_9 ) ;
}
F_16 ( V_6 , V_57 , V_42 ) ;
V_8 -> V_94 [ V_88 ] = true ;
if ( F_29 ( V_6 ) == V_95 &&
! V_8 -> V_94 [ ! V_88 ] )
return F_20 ( V_6 ) ;
return 0 ;
}
static int F_30 ( struct V_83 * V_84 ,
struct V_39 * V_87 )
{
struct V_5 * V_6 = V_87 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
bool V_88 = V_84 -> V_89 == V_90 ;
V_8 -> V_94 [ V_88 ] = false ;
return 0 ;
}
static int F_31 ( struct V_39 * V_87 , int V_96 )
{
struct V_5 * V_6 = V_87 -> V_6 ;
if ( V_96 )
F_6 ( V_6 , V_15 , 0x8 , 0x8 ) ;
else
F_6 ( V_6 , V_15 , 0x8 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
enum V_97 V_98 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_99 = F_21 ( V_6 , V_100 ) ;
int V_75 ;
switch ( V_98 ) {
case V_95 :
break;
case V_101 :
switch ( F_29 ( V_6 ) ) {
case V_102 :
if ( ! F_33 ( V_8 -> V_58 ) ) {
V_75 = F_34 ( V_8 -> V_58 ) ;
if ( V_75 ) {
F_22 ( V_6 -> V_2 ,
L_11 ,
V_75 ) ;
return V_75 ;
}
}
V_75 = F_20 ( V_6 ) ;
if ( V_75 )
return V_75 ;
F_6 ( V_6 , V_103 , 0x180 , 0x80 ) ;
break;
case V_95 :
if ( V_8 -> V_76 == V_78 && ( V_99 & 0x1 ) )
F_23 ( V_6 , 0 , 0 ) ;
if ( ! F_33 ( V_8 -> V_58 ) )
F_35 ( V_8 -> V_58 ) ;
break;
default:
break;
}
break;
case V_102 :
if ( F_29 ( V_6 ) == V_104 ) {
F_36 ( V_8 -> V_105 ) ;
F_16 ( V_6 , V_106 ,
V_107 | V_108 |
V_109 | V_110 ) ;
F_6 ( V_6 , V_103 , 0x80 , 0x80 ) ;
F_37 ( 100 ) ;
F_6 ( V_6 , V_103 , V_111 ,
V_111 ) ;
F_16 ( V_6 , V_106 , V_110 ) ;
}
F_6 ( V_6 , V_103 , 0x180 , 0x100 ) ;
break;
case V_104 :
F_16 ( V_6 , V_106 ,
V_107 | V_108 |
V_109 | V_110 ) ;
F_16 ( V_6 , V_103 , 0 ) ;
F_37 ( 600 ) ;
break;
}
return 0 ;
}
static int F_38 ( struct V_5 * V_6 ,
enum V_97 V_98 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_99 = F_21 ( V_6 , V_100 ) ;
int V_3 , V_75 ;
switch ( V_98 ) {
case V_95 :
break;
case V_101 :
switch ( F_29 ( V_6 ) ) {
case V_102 :
F_6 ( V_6 , V_106 ,
V_107 | V_108 |
V_109 ,
V_107 | V_108 |
V_109 ) ;
V_3 = 0 ;
if ( V_8 -> V_36 && V_8 -> V_36 -> V_112 )
V_3 |= V_113 ;
if ( V_8 -> V_37 && V_8 -> V_37 -> V_112 )
V_3 |= V_114 ;
if ( V_8 -> V_38 && V_8 -> V_38 -> V_112 )
V_3 |= V_115 ;
F_6 ( V_6 , V_100 ,
V_113 |
V_114 |
V_115 , V_3 ) ;
F_6 ( V_6 , V_103 ,
V_116 , 0x80 ) ;
F_37 ( 100 ) ;
F_6 ( V_6 , V_103 ,
V_111 , V_111 ) ;
F_37 ( 100 ) ;
if ( ! F_33 ( V_8 -> V_58 ) ) {
V_75 = F_34 ( V_8 -> V_58 ) ;
if ( V_75 ) {
F_22 ( V_6 -> V_2 ,
L_11 ,
V_75 ) ;
return V_75 ;
}
}
V_75 = F_20 ( V_6 ) ;
if ( V_75 )
return V_75 ;
break;
case V_95 :
if ( V_8 -> V_76 == V_78 && ( V_99 & 0x1 ) )
F_23 ( V_6 , 0 , 0 ) ;
if ( ! F_33 ( V_8 -> V_58 ) )
F_35 ( V_8 -> V_58 ) ;
F_6 ( V_6 , V_106 ,
V_107 | V_108 |
V_109 ,
V_107 | V_108 |
V_109 ) ;
F_6 ( V_6 , V_103 ,
V_111 | V_116 , 0 ) ;
break;
case V_104 :
F_36 ( V_8 -> V_105 ) ;
break;
default:
break;
}
break;
case V_102 :
switch ( F_29 ( V_6 ) ) {
case V_101 :
F_6 ( V_6 , V_117 ,
V_118 | V_119 ,
0 ) ;
F_6 ( V_6 , V_106 ,
V_107 | V_108 |
V_109 ,
V_107 | V_108 |
V_109 ) ;
break;
default:
break;
}
break;
case V_104 :
break;
}
return 0 ;
}
static bool F_19 ( unsigned int V_120 , unsigned int V_121 )
{
unsigned int V_122 ;
if ( V_120 == 0 || V_121 == 0 )
return false ;
V_121 *= 4 ;
V_122 = V_121 / V_120 ;
if ( V_122 < 6 ) {
V_120 >>= 1 ;
V_122 = V_121 / V_120 ;
}
if ( ( V_122 < 6 ) || ( V_122 > 12 ) )
return false ;
return true ;
}
static int F_39 ( unsigned int V_120 , unsigned int V_121 ,
struct V_123 * V_124 )
{
unsigned long long V_125 ;
unsigned int V_126 , V_122 , V_127 ;
F_40 ( L_12 , V_120 , V_121 ) ;
V_121 *= 4 ;
V_122 = V_121 / V_120 ;
if ( V_122 < 6 ) {
V_120 >>= 1 ;
V_124 -> V_128 = 1 ;
V_122 = V_121 / V_120 ;
} else
V_124 -> V_128 = 0 ;
if ( ( V_122 < 6 ) || ( V_122 > 12 ) ) {
F_41 ( L_13 , V_122 ) ;
return - V_21 ;
}
V_124 -> V_129 = V_122 ;
V_127 = V_121 % V_120 ;
V_125 = V_130 * ( long long ) V_127 ;
F_42 ( V_125 , V_120 ) ;
V_126 = V_125 & 0xFFFFFFFF ;
if ( ( V_126 % 10 ) >= 5 )
V_126 += 5 ;
V_126 /= 10 ;
V_124 -> V_65 = V_126 ;
F_40 ( L_14 ,
V_124 -> V_129 , V_124 -> V_65 , V_124 -> V_128 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
unsigned int V_71 , unsigned int V_72 )
{
T_1 V_3 ;
static struct V_123 V_124 ;
int V_75 ;
if ( V_71 && V_72 ) {
V_75 = F_39 ( V_71 , V_72 , & V_124 ) ;
if ( V_75 != 0 )
return V_75 ;
}
F_6 ( V_6 , V_81 , 0x1 , 0 ) ;
F_6 ( V_6 , V_100 , 0x1 , 0 ) ;
if ( ! V_71 || ! V_72 )
return 0 ;
V_3 = F_21 ( V_6 , V_131 ) & ~ 0x3f ;
V_3 |= V_124 . V_128 << 4 ;
V_3 |= V_124 . V_129 ;
if ( V_124 . V_65 ) {
V_3 |= 0x20 ;
F_16 ( V_6 , V_132 , ( V_124 . V_65 >> 16 ) & 0xff ) ;
F_16 ( V_6 , V_133 , ( V_124 . V_65 >> 8 ) & 0xff ) ;
F_16 ( V_6 , V_134 , V_124 . V_65 & 0xff ) ;
}
F_16 ( V_6 , V_131 , V_3 ) ;
F_6 ( V_6 , V_100 , 0x1 , 0x1 ) ;
F_37 ( 250 ) ;
F_6 ( V_6 , V_81 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_43 ( struct V_39 * V_40 , int V_135 ,
int V_120 , unsigned int V_71 , unsigned int V_72 )
{
struct V_5 * V_6 = V_40 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_71 = V_71 ;
if ( V_135 == V_78 )
return 0 ;
return F_23 ( V_6 , V_71 , V_72 ) ;
}
static int F_44 ( struct V_39 * V_40 ,
int V_136 , int div )
{
struct V_5 * V_6 = V_40 -> V_6 ;
T_1 V_3 ;
switch ( V_136 ) {
case V_137 :
V_3 = F_21 ( V_6 , V_81 ) & 0x1f9 ;
F_16 ( V_6 , V_81 , V_3 | div ) ;
break;
case V_138 :
V_3 = F_21 ( V_6 , V_81 ) & 0x1c7 ;
F_16 ( V_6 , V_81 , V_3 | div ) ;
break;
case V_139 :
V_3 = F_21 ( V_6 , V_131 ) & 0x03f ;
F_16 ( V_6 , V_131 , V_3 | div ) ;
break;
case V_140 :
V_3 = F_21 ( V_6 , V_82 ) & 0x03f ;
F_16 ( V_6 , V_82 , V_3 | div ) ;
break;
case V_141 :
V_3 = F_21 ( V_6 , V_142 ) & 0x1fd ;
F_16 ( V_6 , V_142 , V_3 | div ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
enum V_97 V_98 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_143 ( V_6 , V_98 ) ;
}
static int F_46 ( struct V_39 * V_87 , int V_76 ,
unsigned int V_144 , int V_145 )
{
struct V_5 * V_6 = V_87 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_76 ) {
case V_77 :
F_6 ( V_6 , V_81 ,
0x1 , V_77 ) ;
break;
case V_79 :
F_6 ( V_6 , V_81 ,
0x1 , V_79 ) ;
break;
case V_78 :
break;
default:
return - V_21 ;
}
V_8 -> V_62 = V_144 ;
V_8 -> V_76 = V_76 ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_22 * V_23 = & V_8 -> V_23 ;
if ( V_23 -> V_30 )
V_8 -> V_143 = F_38 ;
else
V_8 -> V_143 = F_32 ;
F_48 ( V_6 , V_146 ,
F_4 ( V_146 ) ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static void F_49 ( struct V_147 * V_148 ,
struct V_22 * V_23 )
{
const struct V_149 * V_150 = V_148 -> V_2 . V_151 ;
if ( F_50 ( V_150 , L_15 ) )
V_23 -> V_30 = true ;
if ( F_50 ( V_150 , L_16 ) )
V_23 -> V_152 = true ;
}
static int F_51 ( struct V_147 * V_148 ,
const struct V_153 * V_154 )
{
struct V_22 * V_23 = F_52 ( & V_148 -> V_2 ) ;
struct V_7 * V_8 ;
int V_75 ;
V_8 = F_53 ( & V_148 -> V_2 , sizeof( struct V_7 ) ,
V_155 ) ;
if ( V_8 == NULL )
return - V_156 ;
V_8 -> V_58 = F_54 ( & V_148 -> V_2 , L_17 ) ;
if ( F_33 ( V_8 -> V_58 ) ) {
if ( F_55 ( V_8 -> V_58 ) == - V_157 )
return - V_157 ;
}
V_8 -> V_105 = F_56 ( V_148 , & V_158 ) ;
if ( F_33 ( V_8 -> V_105 ) )
return F_55 ( V_8 -> V_105 ) ;
if ( V_23 )
memcpy ( & V_8 -> V_23 , V_23 , sizeof( struct V_22 ) ) ;
else if ( V_148 -> V_2 . V_151 )
F_49 ( V_148 , & V_8 -> V_23 ) ;
V_75 = F_57 ( V_8 -> V_105 ) ;
if ( V_75 != 0 ) {
F_22 ( & V_148 -> V_2 , L_18 ) ;
return V_75 ;
}
if ( V_8 -> V_23 . V_152 ) {
V_75 = F_58 ( V_8 -> V_105 , V_159 ,
0x4 , 0x4 ) ;
if ( V_75 != 0 ) {
F_22 ( & V_148 -> V_2 , L_19 ,
V_75 ) ;
return V_75 ;
}
}
F_58 ( V_8 -> V_105 , V_160 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_161 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_162 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_163 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_164 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_165 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_166 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_167 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_168 , 0x100 , 0x100 ) ;
F_58 ( V_8 -> V_105 , V_169 , 0x100 , 0x100 ) ;
F_59 ( V_148 , V_8 ) ;
V_75 = F_60 ( & V_148 -> V_2 ,
& V_170 , & V_171 , 1 ) ;
return V_75 ;
}
static int F_61 ( struct V_147 * V_172 )
{
F_62 ( & V_172 -> V_2 ) ;
return 0 ;
}
