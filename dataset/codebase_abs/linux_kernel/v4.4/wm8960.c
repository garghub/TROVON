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
for ( V_10 = 0 ; V_10 < F_4 ( V_68 ) ; ++ V_10 ) {
if ( V_68 [ V_10 ] == - 1 )
continue;
V_58 = V_60 / V_68 [ V_10 ] ;
for ( V_63 = 0 ; V_63 < F_4 ( V_69 ) ; ++ V_63 ) {
if ( V_58 == V_69 [ V_63 ] * V_14 ) {
for ( V_64 = 0 ; V_64 < F_4 ( V_70 ) ; ++ V_64 )
if ( V_58 == V_59 * V_70 [ V_64 ] / 10 )
break;
if ( V_64 != F_4 ( V_70 ) )
break;
}
}
if ( V_63 != F_4 ( V_69 ) )
break;
}
if ( V_10 != F_4 ( V_68 ) ) {
goto V_71;
} else if ( V_8 -> V_65 != V_67 ) {
F_19 ( V_6 -> V_2 , L_8 ) ;
return - V_21 ;
}
for ( V_10 = 0 ; V_10 < F_4 ( V_68 ) ; ++ V_10 ) {
if ( V_68 [ V_10 ] == - 1 )
continue;
for ( V_63 = 0 ; V_63 < F_4 ( V_69 ) ; ++ V_63 ) {
V_58 = V_14 * V_69 [ V_63 ] ;
V_60 = V_58 * V_68 [ V_10 ] ;
for ( V_64 = 0 ; V_64 < F_4 ( V_70 ) ; ++ V_64 ) {
if ( V_58 == V_59 * V_70 [ V_64 ] / 10 &&
F_21 ( V_61 , V_60 ) ) {
F_20 ( V_6 ,
V_61 , V_60 ) ;
break;
} else {
continue;
}
}
if ( V_64 != F_4 ( V_70 ) )
break;
}
if ( V_63 != F_4 ( V_69 ) )
break;
}
if ( V_10 == F_4 ( V_68 ) ) {
F_19 ( V_6 -> V_2 , L_8 ) ;
return - V_21 ;
}
V_71:
F_6 ( V_6 , V_72 , 3 << 1 , V_10 << 1 ) ;
F_6 ( V_6 , V_72 , 0x7 << 3 , V_63 << 3 ) ;
F_6 ( V_6 , V_72 , 0x7 << 6 , V_63 << 6 ) ;
F_6 ( V_6 , V_73 , 0xf , V_64 ) ;
return 0 ;
}
static int F_22 ( struct V_74 * V_75 ,
struct V_76 * V_77 ,
struct V_39 * V_78 )
{
struct V_5 * V_6 = V_78 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 = F_18 ( V_6 , V_57 ) & 0xfff3 ;
bool V_79 = V_75 -> V_80 == V_81 ;
int V_10 ;
V_8 -> V_59 = F_23 ( V_77 ) ;
if ( F_24 ( V_77 ) == 1 )
V_8 -> V_59 *= 2 ;
switch ( F_25 ( V_77 ) ) {
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
F_25 ( V_77 ) ) ;
return - V_21 ;
}
V_8 -> V_14 = F_26 ( V_77 ) ;
if ( V_79 ) {
F_2 ( V_6 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_4 ( V_82 ) ; V_10 ++ )
if ( V_82 [ V_10 ] . V_83 == F_26 ( V_77 ) )
F_6 ( V_6 ,
V_84 , 0x7 ,
V_82 [ V_10 ] . V_9 ) ;
}
F_16 ( V_6 , V_57 , V_42 ) ;
V_8 -> V_85 [ V_79 ] = true ;
if ( F_27 ( V_6 ) == V_86 &&
! V_8 -> V_85 [ ! V_79 ] )
return F_17 ( V_6 ) ;
return 0 ;
}
static int F_28 ( struct V_74 * V_75 ,
struct V_39 * V_78 )
{
struct V_5 * V_6 = V_78 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
bool V_79 = V_75 -> V_80 == V_81 ;
V_8 -> V_85 [ V_79 ] = false ;
return 0 ;
}
static int F_29 ( struct V_39 * V_78 , int V_87 )
{
struct V_5 * V_6 = V_78 -> V_6 ;
if ( V_87 )
F_6 ( V_6 , V_15 , 0x8 , 0x8 ) ;
else
F_6 ( V_6 , V_15 , 0x8 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 ,
enum V_88 V_89 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_90 = F_18 ( V_6 , V_91 ) ;
int V_92 ;
switch ( V_89 ) {
case V_86 :
break;
case V_93 :
switch ( F_27 ( V_6 ) ) {
case V_94 :
if ( ! F_31 ( V_8 -> V_95 ) ) {
V_92 = F_32 ( V_8 -> V_95 ) ;
if ( V_92 ) {
F_19 ( V_6 -> V_2 ,
L_10 ,
V_92 ) ;
return V_92 ;
}
}
V_92 = F_17 ( V_6 ) ;
if ( V_92 )
return V_92 ;
F_6 ( V_6 , V_96 , 0x180 , 0x80 ) ;
break;
case V_86 :
if ( V_8 -> V_65 == V_67 && ( V_90 & 0x1 ) )
F_20 ( V_6 , 0 , 0 ) ;
if ( ! F_31 ( V_8 -> V_95 ) )
F_33 ( V_8 -> V_95 ) ;
break;
default:
break;
}
break;
case V_94 :
if ( F_27 ( V_6 ) == V_97 ) {
F_34 ( V_8 -> V_98 ) ;
F_16 ( V_6 , V_99 ,
V_100 | V_101 |
V_102 | V_103 ) ;
F_6 ( V_6 , V_96 , 0x80 , 0x80 ) ;
F_35 ( 100 ) ;
F_6 ( V_6 , V_96 , V_104 ,
V_104 ) ;
F_16 ( V_6 , V_99 , V_103 ) ;
}
F_6 ( V_6 , V_96 , 0x180 , 0x100 ) ;
break;
case V_97 :
F_16 ( V_6 , V_99 ,
V_100 | V_101 |
V_102 | V_103 ) ;
F_16 ( V_6 , V_96 , 0 ) ;
F_35 ( 600 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_5 * V_6 ,
enum V_88 V_89 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_90 = F_18 ( V_6 , V_91 ) ;
int V_3 , V_92 ;
switch ( V_89 ) {
case V_86 :
break;
case V_93 :
switch ( F_27 ( V_6 ) ) {
case V_94 :
F_6 ( V_6 , V_99 ,
V_100 | V_101 |
V_102 ,
V_100 | V_101 |
V_102 ) ;
V_3 = 0 ;
if ( V_8 -> V_36 && V_8 -> V_36 -> V_105 )
V_3 |= V_106 ;
if ( V_8 -> V_37 && V_8 -> V_37 -> V_105 )
V_3 |= V_107 ;
if ( V_8 -> V_38 && V_8 -> V_38 -> V_105 )
V_3 |= V_108 ;
F_6 ( V_6 , V_91 ,
V_106 |
V_107 |
V_108 , V_3 ) ;
F_6 ( V_6 , V_96 ,
V_109 , 0x80 ) ;
F_35 ( 100 ) ;
F_6 ( V_6 , V_96 ,
V_104 , V_104 ) ;
F_35 ( 100 ) ;
if ( ! F_31 ( V_8 -> V_95 ) ) {
V_92 = F_32 ( V_8 -> V_95 ) ;
if ( V_92 ) {
F_19 ( V_6 -> V_2 ,
L_10 ,
V_92 ) ;
return V_92 ;
}
}
V_92 = F_17 ( V_6 ) ;
if ( V_92 )
return V_92 ;
break;
case V_86 :
if ( V_8 -> V_65 == V_67 && ( V_90 & 0x1 ) )
F_20 ( V_6 , 0 , 0 ) ;
if ( ! F_31 ( V_8 -> V_95 ) )
F_33 ( V_8 -> V_95 ) ;
F_6 ( V_6 , V_99 ,
V_100 | V_101 |
V_102 ,
V_100 | V_101 |
V_102 ) ;
F_6 ( V_6 , V_96 ,
V_104 | V_109 , 0 ) ;
break;
case V_97 :
F_34 ( V_8 -> V_98 ) ;
break;
default:
break;
}
break;
case V_94 :
switch ( F_27 ( V_6 ) ) {
case V_93 :
F_6 ( V_6 , V_110 ,
V_111 | V_112 ,
0 ) ;
F_6 ( V_6 , V_99 ,
V_100 | V_101 |
V_102 ,
V_100 | V_101 |
V_102 ) ;
break;
default:
break;
}
break;
case V_97 :
break;
}
return 0 ;
}
static bool F_21 ( unsigned int V_113 , unsigned int V_114 )
{
unsigned int V_115 ;
if ( V_113 == 0 || V_114 == 0 )
return false ;
V_114 *= 4 ;
V_115 = V_114 / V_113 ;
if ( V_115 < 6 ) {
V_113 >>= 1 ;
V_115 = V_114 / V_113 ;
}
if ( ( V_115 < 6 ) || ( V_115 > 12 ) )
return false ;
return true ;
}
static int F_37 ( unsigned int V_113 , unsigned int V_114 ,
struct V_116 * V_117 )
{
unsigned long long V_118 ;
unsigned int V_119 , V_115 , V_120 ;
F_38 ( L_11 , V_113 , V_114 ) ;
V_114 *= 4 ;
V_115 = V_114 / V_113 ;
if ( V_115 < 6 ) {
V_113 >>= 1 ;
V_117 -> V_121 = 1 ;
V_115 = V_114 / V_113 ;
} else
V_117 -> V_121 = 0 ;
if ( ( V_115 < 6 ) || ( V_115 > 12 ) ) {
F_39 ( L_12 , V_115 ) ;
return - V_21 ;
}
V_117 -> V_122 = V_115 ;
V_120 = V_114 % V_113 ;
V_118 = V_123 * ( long long ) V_120 ;
F_40 ( V_118 , V_113 ) ;
V_119 = V_118 & 0xFFFFFFFF ;
if ( ( V_119 % 10 ) >= 5 )
V_119 += 5 ;
V_119 /= 10 ;
V_117 -> V_64 = V_119 ;
F_38 ( L_13 ,
V_117 -> V_122 , V_117 -> V_64 , V_117 -> V_121 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
unsigned int V_61 , unsigned int V_60 )
{
T_1 V_3 ;
static struct V_116 V_117 ;
int V_92 ;
if ( V_61 && V_60 ) {
V_92 = F_37 ( V_61 , V_60 , & V_117 ) ;
if ( V_92 != 0 )
return V_92 ;
}
F_6 ( V_6 , V_72 , 0x1 , 0 ) ;
F_6 ( V_6 , V_91 , 0x1 , 0 ) ;
if ( ! V_61 || ! V_60 )
return 0 ;
V_3 = F_18 ( V_6 , V_124 ) & ~ 0x3f ;
V_3 |= V_117 . V_121 << 4 ;
V_3 |= V_117 . V_122 ;
if ( V_117 . V_64 ) {
V_3 |= 0x20 ;
F_16 ( V_6 , V_125 , ( V_117 . V_64 >> 16 ) & 0xff ) ;
F_16 ( V_6 , V_126 , ( V_117 . V_64 >> 8 ) & 0xff ) ;
F_16 ( V_6 , V_127 , V_117 . V_64 & 0xff ) ;
}
F_16 ( V_6 , V_124 , V_3 ) ;
F_6 ( V_6 , V_91 , 0x1 , 0x1 ) ;
F_35 ( 250 ) ;
F_6 ( V_6 , V_72 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_41 ( struct V_39 * V_40 , int V_128 ,
int V_113 , unsigned int V_61 , unsigned int V_60 )
{
struct V_5 * V_6 = V_40 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_61 = V_61 ;
if ( V_128 == V_67 )
return 0 ;
return F_20 ( V_6 , V_61 , V_60 ) ;
}
static int F_42 ( struct V_39 * V_40 ,
int V_129 , int div )
{
struct V_5 * V_6 = V_40 -> V_6 ;
T_1 V_3 ;
switch ( V_129 ) {
case V_130 :
V_3 = F_18 ( V_6 , V_72 ) & 0x1f9 ;
F_16 ( V_6 , V_72 , V_3 | div ) ;
break;
case V_131 :
V_3 = F_18 ( V_6 , V_72 ) & 0x1c7 ;
F_16 ( V_6 , V_72 , V_3 | div ) ;
break;
case V_132 :
V_3 = F_18 ( V_6 , V_124 ) & 0x03f ;
F_16 ( V_6 , V_124 , V_3 | div ) ;
break;
case V_133 :
V_3 = F_18 ( V_6 , V_73 ) & 0x03f ;
F_16 ( V_6 , V_73 , V_3 | div ) ;
break;
case V_134 :
V_3 = F_18 ( V_6 , V_135 ) & 0x1fd ;
F_16 ( V_6 , V_135 , V_3 | div ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_43 ( struct V_5 * V_6 ,
enum V_88 V_89 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_136 ( V_6 , V_89 ) ;
}
static int F_44 ( struct V_39 * V_78 , int V_65 ,
unsigned int V_137 , int V_138 )
{
struct V_5 * V_6 = V_78 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_65 ) {
case V_66 :
F_6 ( V_6 , V_72 ,
0x1 , V_66 ) ;
break;
case V_139 :
F_6 ( V_6 , V_72 ,
0x1 , V_139 ) ;
break;
case V_67 :
break;
default:
return - V_21 ;
}
V_8 -> V_58 = V_137 ;
V_8 -> V_65 = V_65 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_22 * V_23 = & V_8 -> V_23 ;
if ( V_23 -> V_30 )
V_8 -> V_136 = F_36 ;
else
V_8 -> V_136 = F_30 ;
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
int V_92 ;
V_8 = F_51 ( & V_142 -> V_2 , sizeof( struct V_7 ) ,
V_149 ) ;
if ( V_8 == NULL )
return - V_150 ;
V_8 -> V_95 = F_52 ( & V_142 -> V_2 , L_16 ) ;
if ( F_31 ( V_8 -> V_95 ) ) {
if ( F_53 ( V_8 -> V_95 ) == - V_151 )
return - V_151 ;
}
V_8 -> V_98 = F_54 ( V_142 , & V_152 ) ;
if ( F_31 ( V_8 -> V_98 ) )
return F_53 ( V_8 -> V_98 ) ;
if ( V_23 )
memcpy ( & V_8 -> V_23 , V_23 , sizeof( struct V_22 ) ) ;
else if ( V_142 -> V_2 . V_145 )
F_47 ( V_142 , & V_8 -> V_23 ) ;
V_92 = F_55 ( V_8 -> V_98 ) ;
if ( V_92 != 0 ) {
F_19 ( & V_142 -> V_2 , L_17 ) ;
return V_92 ;
}
if ( V_8 -> V_23 . V_146 ) {
V_92 = F_56 ( V_8 -> V_98 , V_153 ,
0x4 , 0x4 ) ;
if ( V_92 != 0 ) {
F_19 ( & V_142 -> V_2 , L_18 ,
V_92 ) ;
return V_92 ;
}
}
F_56 ( V_8 -> V_98 , V_154 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_155 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_156 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_157 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_158 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_159 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_160 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_161 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_162 , 0x100 , 0x100 ) ;
F_56 ( V_8 -> V_98 , V_163 , 0x100 , 0x100 ) ;
F_57 ( V_142 , V_8 ) ;
V_92 = F_58 ( & V_142 -> V_2 ,
& V_164 , & V_165 , 1 ) ;
return V_92 ;
}
static int F_59 ( struct V_141 * V_166 )
{
F_60 ( & V_166 -> V_2 ) ;
return 0 ;
}
