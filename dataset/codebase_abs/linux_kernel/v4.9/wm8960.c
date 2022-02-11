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
static int F_17 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_58 , V_59 , V_14 , V_60 , V_61 ;
T_1 V_62 = F_18 ( V_6 , V_57 ) ;
int V_10 , V_63 , V_64 ;
if ( ! ( V_62 & ( 1 << 6 ) ) ) {
F_5 ( V_6 -> V_2 ,
L_5 ) ;
return 0 ;
}
if ( V_8 -> V_65 != V_66 && ! V_8 -> V_61 ) {
F_19 ( V_6 -> V_2 , L_6 ) ;
return - V_21 ;
}
V_61 = V_8 -> V_61 ;
V_59 = V_8 -> V_59 ;
V_14 = V_8 -> V_14 ;
if ( V_8 -> V_65 == V_67 ) {
F_20 ( V_6 , 0 , 0 ) ;
V_60 = V_61 ;
} else if ( V_8 -> V_58 ) {
V_60 = V_8 -> V_58 ;
} else {
F_19 ( V_6 -> V_2 , L_7 ) ;
return - V_21 ;
}
if ( V_8 -> V_65 != V_68 ) {
for ( V_10 = 0 ; V_10 < F_4 ( V_69 ) ; ++ V_10 ) {
if ( V_69 [ V_10 ] == - 1 )
continue;
V_58 = V_60 / V_69 [ V_10 ] ;
for ( V_63 = 0 ; V_63 < F_4 ( V_70 ) ; ++ V_63 ) {
if ( V_58 != V_70 [ V_63 ] * V_14 )
continue;
for ( V_64 = 0 ; V_64 < F_4 ( V_71 ) ; ++ V_64 )
if ( V_58 == V_59 * V_71 [ V_64 ] / 10 )
break;
if ( V_64 != F_4 ( V_71 ) )
break;
}
if ( V_63 != F_4 ( V_70 ) )
break;
}
if ( V_10 != F_4 ( V_69 ) ) {
goto V_72;
} else if ( V_8 -> V_65 != V_67 ) {
F_19 ( V_6 -> V_2 , L_8 ) ;
return - V_21 ;
}
}
for ( V_10 = 0 ; V_10 < F_4 ( V_69 ) ; ++ V_10 ) {
if ( V_69 [ V_10 ] == - 1 )
continue;
for ( V_63 = 0 ; V_63 < F_4 ( V_70 ) ; ++ V_63 ) {
V_58 = V_14 * V_70 [ V_63 ] ;
V_60 = V_58 * V_69 [ V_10 ] ;
for ( V_64 = 0 ; V_64 < F_4 ( V_71 ) ; ++ V_64 ) {
if ( V_58 == V_59 * V_71 [ V_64 ] / 10 &&
F_21 ( V_61 , V_60 ) ) {
F_20 ( V_6 ,
V_61 , V_60 ) ;
break;
} else {
continue;
}
}
if ( V_64 != F_4 ( V_71 ) )
break;
}
if ( V_63 != F_4 ( V_70 ) )
break;
}
if ( V_10 == F_4 ( V_69 ) ) {
F_19 ( V_6 -> V_2 , L_8 ) ;
return - V_21 ;
}
V_72:
F_6 ( V_6 , V_73 , 3 << 1 , V_10 << 1 ) ;
F_6 ( V_6 , V_73 , 0x7 << 3 , V_63 << 3 ) ;
F_6 ( V_6 , V_73 , 0x7 << 6 , V_63 << 6 ) ;
F_6 ( V_6 , V_74 , 0xf , V_64 ) ;
return 0 ;
}
static int F_22 ( struct V_75 * V_76 ,
struct V_77 * V_78 ,
struct V_39 * V_79 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 = F_18 ( V_6 , V_57 ) & 0xfff3 ;
bool V_80 = V_76 -> V_81 == V_82 ;
int V_10 ;
V_8 -> V_59 = F_23 ( V_78 ) ;
if ( F_24 ( V_78 ) == 1 )
V_8 -> V_59 *= 2 ;
switch ( F_25 ( V_78 ) ) {
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
F_19 ( V_6 -> V_2 , L_9 ,
F_25 ( V_78 ) ) ;
return - V_21 ;
}
V_8 -> V_14 = F_26 ( V_78 ) ;
if ( V_80 ) {
F_2 ( V_6 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_4 ( V_83 ) ; V_10 ++ )
if ( V_83 [ V_10 ] . V_84 == F_26 ( V_78 ) )
F_6 ( V_6 ,
V_85 , 0x7 ,
V_83 [ V_10 ] . V_9 ) ;
}
F_16 ( V_6 , V_57 , V_42 ) ;
V_8 -> V_86 [ V_80 ] = true ;
if ( F_27 ( V_6 ) == V_87 &&
! V_8 -> V_86 [ ! V_80 ] )
return F_17 ( V_6 ) ;
return 0 ;
}
static int F_28 ( struct V_75 * V_76 ,
struct V_39 * V_79 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
bool V_80 = V_76 -> V_81 == V_82 ;
V_8 -> V_86 [ V_80 ] = false ;
return 0 ;
}
static int F_29 ( struct V_39 * V_79 , int V_88 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
if ( V_88 )
F_6 ( V_6 , V_15 , 0x8 , 0x8 ) ;
else
F_6 ( V_6 , V_15 , 0x8 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 ,
enum V_89 V_90 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_91 = F_18 ( V_6 , V_92 ) ;
int V_93 ;
switch ( V_90 ) {
case V_87 :
break;
case V_94 :
switch ( F_27 ( V_6 ) ) {
case V_95 :
if ( ! F_31 ( V_8 -> V_96 ) ) {
V_93 = F_32 ( V_8 -> V_96 ) ;
if ( V_93 ) {
F_19 ( V_6 -> V_2 ,
L_10 ,
V_93 ) ;
return V_93 ;
}
}
V_93 = F_17 ( V_6 ) ;
if ( V_93 )
return V_93 ;
F_6 ( V_6 , V_97 , 0x180 , 0x80 ) ;
break;
case V_87 :
if ( V_8 -> V_65 == V_67 && ( V_91 & 0x1 ) )
F_20 ( V_6 , 0 , 0 ) ;
if ( ! F_31 ( V_8 -> V_96 ) )
F_33 ( V_8 -> V_96 ) ;
break;
default:
break;
}
break;
case V_95 :
if ( F_27 ( V_6 ) == V_98 ) {
F_34 ( V_8 -> V_99 ) ;
F_16 ( V_6 , V_100 ,
V_101 | V_102 |
V_103 | V_104 ) ;
F_6 ( V_6 , V_97 , 0x80 , 0x80 ) ;
F_35 ( 100 ) ;
F_6 ( V_6 , V_97 , V_105 ,
V_105 ) ;
F_16 ( V_6 , V_100 , V_104 ) ;
}
F_6 ( V_6 , V_97 , 0x180 , 0x100 ) ;
break;
case V_98 :
F_16 ( V_6 , V_100 ,
V_101 | V_102 |
V_103 | V_104 ) ;
F_16 ( V_6 , V_97 , 0 ) ;
F_35 ( 600 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_5 * V_6 ,
enum V_89 V_90 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_91 = F_18 ( V_6 , V_92 ) ;
int V_3 , V_93 ;
switch ( V_90 ) {
case V_87 :
break;
case V_94 :
switch ( F_27 ( V_6 ) ) {
case V_95 :
F_6 ( V_6 , V_100 ,
V_101 | V_102 |
V_103 ,
V_101 | V_102 |
V_103 ) ;
V_3 = 0 ;
if ( V_8 -> V_36 && V_8 -> V_36 -> V_106 )
V_3 |= V_107 ;
if ( V_8 -> V_37 && V_8 -> V_37 -> V_106 )
V_3 |= V_108 ;
if ( V_8 -> V_38 && V_8 -> V_38 -> V_106 )
V_3 |= V_109 ;
F_6 ( V_6 , V_92 ,
V_107 |
V_108 |
V_109 , V_3 ) ;
F_6 ( V_6 , V_97 ,
V_110 , 0x80 ) ;
F_35 ( 100 ) ;
F_6 ( V_6 , V_97 ,
V_105 , V_105 ) ;
F_35 ( 100 ) ;
if ( ! F_31 ( V_8 -> V_96 ) ) {
V_93 = F_32 ( V_8 -> V_96 ) ;
if ( V_93 ) {
F_19 ( V_6 -> V_2 ,
L_10 ,
V_93 ) ;
return V_93 ;
}
}
V_93 = F_17 ( V_6 ) ;
if ( V_93 )
return V_93 ;
break;
case V_87 :
if ( V_8 -> V_65 == V_67 && ( V_91 & 0x1 ) )
F_20 ( V_6 , 0 , 0 ) ;
if ( ! F_31 ( V_8 -> V_96 ) )
F_33 ( V_8 -> V_96 ) ;
F_6 ( V_6 , V_100 ,
V_101 | V_102 |
V_103 ,
V_101 | V_102 |
V_103 ) ;
F_6 ( V_6 , V_97 ,
V_105 | V_110 , 0 ) ;
break;
case V_98 :
F_34 ( V_8 -> V_99 ) ;
break;
default:
break;
}
break;
case V_95 :
switch ( F_27 ( V_6 ) ) {
case V_94 :
F_6 ( V_6 , V_111 ,
V_112 | V_113 ,
0 ) ;
F_6 ( V_6 , V_100 ,
V_101 | V_102 |
V_103 ,
V_101 | V_102 |
V_103 ) ;
break;
default:
break;
}
break;
case V_98 :
break;
}
return 0 ;
}
static bool F_21 ( unsigned int V_114 , unsigned int V_115 )
{
unsigned int V_116 ;
if ( V_114 == 0 || V_115 == 0 )
return false ;
V_115 *= 4 ;
V_116 = V_115 / V_114 ;
if ( V_116 < 6 ) {
V_114 >>= 1 ;
V_116 = V_115 / V_114 ;
}
if ( ( V_116 < 6 ) || ( V_116 > 12 ) )
return false ;
return true ;
}
static int F_37 ( unsigned int V_114 , unsigned int V_115 ,
struct V_117 * V_118 )
{
unsigned long long V_119 ;
unsigned int V_120 , V_116 , V_121 ;
F_38 ( L_11 , V_114 , V_115 ) ;
V_115 *= 4 ;
V_116 = V_115 / V_114 ;
if ( V_116 < 6 ) {
V_114 >>= 1 ;
V_118 -> V_122 = 1 ;
V_116 = V_115 / V_114 ;
} else
V_118 -> V_122 = 0 ;
if ( ( V_116 < 6 ) || ( V_116 > 12 ) ) {
F_39 ( L_12 , V_116 ) ;
return - V_21 ;
}
V_118 -> V_123 = V_116 ;
V_121 = V_115 % V_114 ;
V_119 = V_124 * ( long long ) V_121 ;
F_40 ( V_119 , V_114 ) ;
V_120 = V_119 & 0xFFFFFFFF ;
if ( ( V_120 % 10 ) >= 5 )
V_120 += 5 ;
V_120 /= 10 ;
V_118 -> V_64 = V_120 ;
F_38 ( L_13 ,
V_118 -> V_123 , V_118 -> V_64 , V_118 -> V_122 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
unsigned int V_61 , unsigned int V_60 )
{
T_1 V_3 ;
static struct V_117 V_118 ;
int V_93 ;
if ( V_61 && V_60 ) {
V_93 = F_37 ( V_61 , V_60 , & V_118 ) ;
if ( V_93 != 0 )
return V_93 ;
}
F_6 ( V_6 , V_73 , 0x1 , 0 ) ;
F_6 ( V_6 , V_92 , 0x1 , 0 ) ;
if ( ! V_61 || ! V_60 )
return 0 ;
V_3 = F_18 ( V_6 , V_125 ) & ~ 0x3f ;
V_3 |= V_118 . V_122 << 4 ;
V_3 |= V_118 . V_123 ;
if ( V_118 . V_64 ) {
V_3 |= 0x20 ;
F_16 ( V_6 , V_126 , ( V_118 . V_64 >> 16 ) & 0xff ) ;
F_16 ( V_6 , V_127 , ( V_118 . V_64 >> 8 ) & 0xff ) ;
F_16 ( V_6 , V_128 , V_118 . V_64 & 0xff ) ;
}
F_16 ( V_6 , V_125 , V_3 ) ;
F_6 ( V_6 , V_92 , 0x1 , 0x1 ) ;
F_35 ( 250 ) ;
F_6 ( V_6 , V_73 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_41 ( struct V_39 * V_40 , int V_129 ,
int V_114 , unsigned int V_61 , unsigned int V_60 )
{
struct V_5 * V_6 = V_40 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_61 = V_61 ;
if ( V_129 == V_67 )
return 0 ;
return F_20 ( V_6 , V_61 , V_60 ) ;
}
static int F_42 ( struct V_39 * V_40 ,
int V_130 , int div )
{
struct V_5 * V_6 = V_40 -> V_6 ;
T_1 V_3 ;
switch ( V_130 ) {
case V_131 :
V_3 = F_18 ( V_6 , V_73 ) & 0x1f9 ;
F_16 ( V_6 , V_73 , V_3 | div ) ;
break;
case V_132 :
V_3 = F_18 ( V_6 , V_73 ) & 0x1c7 ;
F_16 ( V_6 , V_73 , V_3 | div ) ;
break;
case V_133 :
V_3 = F_18 ( V_6 , V_125 ) & 0x03f ;
F_16 ( V_6 , V_125 , V_3 | div ) ;
break;
case V_134 :
V_3 = F_18 ( V_6 , V_74 ) & 0x03f ;
F_16 ( V_6 , V_74 , V_3 | div ) ;
break;
case V_135 :
V_3 = F_18 ( V_6 , V_136 ) & 0x1fd ;
F_16 ( V_6 , V_136 , V_3 | div ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_43 ( struct V_5 * V_6 ,
enum V_89 V_90 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_137 ( V_6 , V_90 ) ;
}
static int F_44 ( struct V_39 * V_79 , int V_65 ,
unsigned int V_138 , int V_139 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_65 ) {
case V_66 :
F_6 ( V_6 , V_73 ,
0x1 , V_66 ) ;
break;
case V_68 :
F_6 ( V_6 , V_73 ,
0x1 , V_68 ) ;
break;
case V_67 :
break;
default:
return - V_21 ;
}
V_8 -> V_58 = V_138 ;
V_8 -> V_65 = V_65 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_22 * V_23 = & V_8 -> V_23 ;
if ( V_23 -> V_30 )
V_8 -> V_137 = F_36 ;
else
V_8 -> V_137 = F_30 ;
F_46 ( V_6 , V_140 ,
F_4 ( V_140 ) ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static void F_47 ( struct V_141 * V_142 ,
struct V_22 * V_23 )
{
const struct V_143 * V_144 = V_142 -> V_2 . V_145 ;
if ( F_48 ( V_144 , L_14 ) )
V_23 -> V_30 = true ;
if ( F_48 ( V_144 , L_15 ) )
V_23 -> V_146 = true ;
}
static int F_49 ( struct V_141 * V_142 ,
const struct V_147 * V_148 )
{
struct V_22 * V_23 = F_50 ( & V_142 -> V_2 ) ;
struct V_7 * V_8 ;
int V_93 ;
V_8 = F_51 ( & V_142 -> V_2 , sizeof( struct V_7 ) ,
V_149 ) ;
if ( V_8 == NULL )
return - V_150 ;
V_8 -> V_96 = F_52 ( & V_142 -> V_2 , L_16 ) ;
if ( F_31 ( V_8 -> V_96 ) ) {
if ( F_53 ( V_8 -> V_96 ) == - V_151 )
return - V_151 ;
}
V_8 -> V_99 = F_54 ( V_142 , & V_152 ) ;
if ( F_31 ( V_8 -> V_99 ) )
return F_53 ( V_8 -> V_99 ) ;
if ( V_23 )
memcpy ( & V_8 -> V_23 , V_23 , sizeof( struct V_22 ) ) ;
else if ( V_142 -> V_2 . V_145 )
F_47 ( V_142 , & V_8 -> V_23 ) ;
V_93 = F_55 ( V_8 -> V_99 ) ;
if ( V_93 != 0 ) {
F_19 ( & V_142 -> V_2 , L_17 ) ;
return V_93 ;
}
if ( V_8 -> V_23 . V_146 ) {
V_93 = F_56 ( V_8 -> V_99 , V_153 ,
0x4 , 0x4 ) ;
if ( V_93 != 0 ) {
F_19 ( & V_142 -> V_2 , L_18 ,
V_93 ) ;
return V_93 ;
}
}
F_56 ( V_8 -> V_99 , V_154 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_155 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_156 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_157 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_158 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_159 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_160 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_161 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_162 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_99 , V_163 , 0x100 , 0x100 ) ;
F_57 ( V_142 , V_8 ) ;
V_93 = F_58 ( & V_142 -> V_2 ,
& V_164 , & V_165 , 1 ) ;
return V_93 ;
}
static int F_59 ( struct V_141 * V_166 )
{
F_60 ( & V_166 -> V_2 ) ;
return 0 ;
}
