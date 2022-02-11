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
static void F_17 ( struct V_5 * V_6 ,
bool V_58 , int V_59 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_60 = F_18 ( V_6 , V_57 ) ;
T_1 V_61 = F_18 ( V_6 , V_62 ) ;
T_2 V_63 ;
int V_10 , V_64 ;
if ( ! ( V_60 & ( 1 << 6 ) ) ) {
F_5 ( V_6 -> V_2 ,
L_5 ) ;
return;
}
if ( ! V_8 -> V_63 ) {
F_5 ( V_6 -> V_2 , L_6 ) ;
return;
}
if ( ! V_8 -> V_65 || ! V_59 ) {
F_5 ( V_6 -> V_2 , L_7 ) ;
return;
}
for ( V_10 = 0 ; V_10 < F_4 ( V_66 ) ; ++ V_10 ) {
if ( V_8 -> V_63 == V_59 * V_66 [ V_10 ] ) {
for ( V_64 = 0 ; V_64 < F_4 ( V_67 ) ; ++ V_64 ) {
V_63 = V_8 -> V_65 * V_67 [ V_64 ] / 10 ;
if ( V_8 -> V_63 == V_63 )
break;
}
if( V_64 != F_4 ( V_67 ) )
break;
}
}
if ( V_10 == F_4 ( V_66 ) ) {
F_19 ( V_6 -> V_2 , L_8 , V_8 -> V_63 ) ;
return;
}
if ( V_61 & ( 1 << 6 ) )
F_6 ( V_6 , V_68 , 0x7 << 3 , V_10 << 3 ) ;
else if ( V_58 )
F_6 ( V_6 , V_68 , 0x7 << 3 , V_10 << 3 ) ;
else if ( ! V_58 )
F_6 ( V_6 , V_68 , 0x7 << 6 , V_10 << 6 ) ;
F_6 ( V_6 , V_69 , 0xf , V_64 ) ;
}
static int F_20 ( struct V_70 * V_71 ,
struct V_72 * V_73 ,
struct V_39 * V_74 )
{
struct V_5 * V_6 = V_74 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 = F_18 ( V_6 , V_57 ) & 0xfff3 ;
bool V_58 = V_71 -> V_75 == V_76 ;
int V_10 ;
V_8 -> V_65 = F_21 ( V_73 ) ;
if ( F_22 ( V_73 ) == 1 )
V_8 -> V_65 *= 2 ;
switch ( F_23 ( V_73 ) ) {
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
F_23 ( V_73 ) ) ;
return - V_21 ;
}
if ( V_71 -> V_75 == V_76 ) {
V_8 -> V_14 = F_24 ( V_73 ) ;
F_2 ( V_6 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_4 ( V_77 ) ; V_10 ++ )
if ( V_77 [ V_10 ] . V_78 == F_24 ( V_73 ) )
F_6 ( V_6 ,
V_79 , 0x7 ,
V_77 [ V_10 ] . V_9 ) ;
}
F_16 ( V_6 , V_57 , V_42 ) ;
F_17 ( V_6 , V_58 , F_24 ( V_73 ) ) ;
return 0 ;
}
static int F_25 ( struct V_39 * V_74 , int V_80 )
{
struct V_5 * V_6 = V_74 -> V_6 ;
if ( V_80 )
F_6 ( V_6 , V_15 , 0x8 , 0x8 ) ;
else
F_6 ( V_6 , V_15 , 0x8 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
enum V_81 V_82 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_83 ;
switch ( V_82 ) {
case V_84 :
break;
case V_85 :
switch ( F_27 ( V_6 ) ) {
case V_86 :
if ( ! F_28 ( V_8 -> V_87 ) ) {
V_83 = F_29 ( V_8 -> V_87 ) ;
if ( V_83 ) {
F_19 ( V_6 -> V_2 ,
L_10 ,
V_83 ) ;
return V_83 ;
}
}
F_6 ( V_6 , V_88 , 0x180 , 0x80 ) ;
break;
case V_84 :
if ( ! F_28 ( V_8 -> V_87 ) )
F_30 ( V_8 -> V_87 ) ;
break;
default:
break;
}
break;
case V_86 :
if ( F_27 ( V_6 ) == V_89 ) {
F_31 ( V_8 -> V_90 ) ;
F_16 ( V_6 , V_91 ,
V_92 | V_93 |
V_94 | V_95 ) ;
F_6 ( V_6 , V_88 , 0x80 , 0x80 ) ;
F_32 ( 100 ) ;
F_6 ( V_6 , V_88 , V_96 ,
V_96 ) ;
F_16 ( V_6 , V_91 , V_95 ) ;
}
F_6 ( V_6 , V_88 , 0x180 , 0x100 ) ;
break;
case V_89 :
F_16 ( V_6 , V_91 ,
V_92 | V_93 |
V_94 | V_95 ) ;
F_16 ( V_6 , V_88 , 0 ) ;
F_32 ( 600 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_5 * V_6 ,
enum V_81 V_82 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_3 , V_83 ;
switch ( V_82 ) {
case V_84 :
break;
case V_85 :
switch ( F_27 ( V_6 ) ) {
case V_86 :
F_6 ( V_6 , V_91 ,
V_92 | V_93 |
V_94 ,
V_92 | V_93 |
V_94 ) ;
V_3 = 0 ;
if ( V_8 -> V_36 && V_8 -> V_36 -> V_97 )
V_3 |= V_98 ;
if ( V_8 -> V_37 && V_8 -> V_37 -> V_97 )
V_3 |= V_99 ;
if ( V_8 -> V_38 && V_8 -> V_38 -> V_97 )
V_3 |= V_100 ;
F_6 ( V_6 , V_101 ,
V_98 |
V_99 |
V_100 , V_3 ) ;
F_6 ( V_6 , V_88 ,
V_102 , 0x80 ) ;
F_32 ( 100 ) ;
F_6 ( V_6 , V_88 ,
V_96 , V_96 ) ;
F_32 ( 100 ) ;
if ( ! F_28 ( V_8 -> V_87 ) ) {
V_83 = F_29 ( V_8 -> V_87 ) ;
if ( V_83 ) {
F_19 ( V_6 -> V_2 ,
L_10 ,
V_83 ) ;
return V_83 ;
}
}
break;
case V_84 :
if ( ! F_28 ( V_8 -> V_87 ) )
F_30 ( V_8 -> V_87 ) ;
F_6 ( V_6 , V_91 ,
V_92 | V_93 |
V_94 ,
V_92 | V_93 |
V_94 ) ;
F_6 ( V_6 , V_88 ,
V_96 | V_102 , 0 ) ;
break;
case V_89 :
F_31 ( V_8 -> V_90 ) ;
break;
default:
break;
}
break;
case V_86 :
switch ( F_27 ( V_6 ) ) {
case V_85 :
F_6 ( V_6 , V_103 ,
V_104 | V_105 ,
0 ) ;
F_6 ( V_6 , V_91 ,
V_92 | V_93 |
V_94 ,
V_92 | V_93 |
V_94 ) ;
break;
default:
break;
}
break;
case V_89 :
break;
}
return 0 ;
}
static int F_34 ( unsigned int V_106 , unsigned int V_107 ,
struct V_108 * V_109 )
{
unsigned long long V_110 ;
unsigned int V_111 , V_112 , V_113 ;
F_35 ( L_11 , V_106 , V_107 ) ;
V_107 *= 4 ;
V_112 = V_107 / V_106 ;
if ( V_112 < 6 ) {
V_106 >>= 1 ;
V_109 -> V_114 = 1 ;
V_112 = V_107 / V_106 ;
} else
V_109 -> V_114 = 0 ;
if ( ( V_112 < 6 ) || ( V_112 > 12 ) ) {
F_36 ( L_12 , V_112 ) ;
return - V_21 ;
}
V_109 -> V_115 = V_112 ;
V_113 = V_107 % V_106 ;
V_110 = V_116 * ( long long ) V_113 ;
F_37 ( V_110 , V_106 ) ;
V_111 = V_110 & 0xFFFFFFFF ;
if ( ( V_111 % 10 ) >= 5 )
V_111 += 5 ;
V_111 /= 10 ;
V_109 -> V_117 = V_111 ;
F_35 ( L_13 ,
V_109 -> V_115 , V_109 -> V_117 , V_109 -> V_114 ) ;
return 0 ;
}
static int F_38 ( struct V_39 * V_40 , int V_118 ,
int V_106 , unsigned int V_119 , unsigned int V_120 )
{
struct V_5 * V_6 = V_40 -> V_6 ;
T_1 V_3 ;
static struct V_108 V_109 ;
int V_83 ;
if ( V_119 && V_120 ) {
V_83 = F_34 ( V_119 , V_120 , & V_109 ) ;
if ( V_83 != 0 )
return V_83 ;
}
F_6 ( V_6 , V_68 , 0x1 , 0 ) ;
F_6 ( V_6 , V_101 , 0x1 , 0 ) ;
if ( ! V_119 || ! V_120 )
return 0 ;
V_3 = F_18 ( V_6 , V_121 ) & ~ 0x3f ;
V_3 |= V_109 . V_114 << 4 ;
V_3 |= V_109 . V_115 ;
if ( V_109 . V_117 ) {
V_3 |= 0x20 ;
F_16 ( V_6 , V_122 , ( V_109 . V_117 >> 16 ) & 0xff ) ;
F_16 ( V_6 , V_123 , ( V_109 . V_117 >> 8 ) & 0xff ) ;
F_16 ( V_6 , V_124 , V_109 . V_117 & 0xff ) ;
}
F_16 ( V_6 , V_121 , V_3 ) ;
F_6 ( V_6 , V_101 , 0x1 , 0x1 ) ;
F_32 ( 250 ) ;
F_6 ( V_6 , V_68 , 0x1 , 0x1 ) ;
return 0 ;
}
static int F_39 ( struct V_39 * V_40 ,
int V_125 , int div )
{
struct V_5 * V_6 = V_40 -> V_6 ;
T_1 V_3 ;
switch ( V_125 ) {
case V_126 :
V_3 = F_18 ( V_6 , V_68 ) & 0x1f9 ;
F_16 ( V_6 , V_68 , V_3 | div ) ;
break;
case V_127 :
V_3 = F_18 ( V_6 , V_68 ) & 0x1c7 ;
F_16 ( V_6 , V_68 , V_3 | div ) ;
break;
case V_128 :
V_3 = F_18 ( V_6 , V_121 ) & 0x03f ;
F_16 ( V_6 , V_121 , V_3 | div ) ;
break;
case V_129 :
V_3 = F_18 ( V_6 , V_69 ) & 0x03f ;
F_16 ( V_6 , V_69 , V_3 | div ) ;
break;
case V_130 :
V_3 = F_18 ( V_6 , V_131 ) & 0x1fd ;
F_16 ( V_6 , V_131 , V_3 | div ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_40 ( struct V_5 * V_6 ,
enum V_81 V_82 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_132 ( V_6 , V_82 ) ;
}
static int F_41 ( struct V_39 * V_74 , int V_133 ,
unsigned int V_134 , int V_135 )
{
struct V_5 * V_6 = V_74 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_133 ) {
case V_136 :
F_6 ( V_6 , V_68 ,
0x1 , V_136 ) ;
break;
case V_137 :
F_6 ( V_6 , V_68 ,
0x1 , V_137 ) ;
break;
default:
return - V_21 ;
}
V_8 -> V_63 = V_134 ;
return 0 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_22 * V_23 = & V_8 -> V_23 ;
if ( V_23 -> V_30 )
V_8 -> V_132 = F_33 ;
else
V_8 -> V_132 = F_26 ;
F_43 ( V_6 , V_138 ,
F_4 ( V_138 ) ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static void F_44 ( struct V_139 * V_140 ,
struct V_22 * V_23 )
{
const struct V_141 * V_142 = V_140 -> V_2 . V_143 ;
if ( F_45 ( V_142 , L_14 ) )
V_23 -> V_30 = true ;
if ( F_45 ( V_142 , L_15 ) )
V_23 -> V_144 = true ;
}
static int F_46 ( struct V_139 * V_140 ,
const struct V_145 * V_146 )
{
struct V_22 * V_23 = F_47 ( & V_140 -> V_2 ) ;
struct V_7 * V_8 ;
int V_83 ;
V_8 = F_48 ( & V_140 -> V_2 , sizeof( struct V_7 ) ,
V_147 ) ;
if ( V_8 == NULL )
return - V_148 ;
V_8 -> V_87 = F_49 ( & V_140 -> V_2 , L_16 ) ;
if ( F_28 ( V_8 -> V_87 ) ) {
if ( F_50 ( V_8 -> V_87 ) == - V_149 )
return - V_149 ;
}
V_8 -> V_90 = F_51 ( V_140 , & V_150 ) ;
if ( F_28 ( V_8 -> V_90 ) )
return F_50 ( V_8 -> V_90 ) ;
if ( V_23 )
memcpy ( & V_8 -> V_23 , V_23 , sizeof( struct V_22 ) ) ;
else if ( V_140 -> V_2 . V_143 )
F_44 ( V_140 , & V_8 -> V_23 ) ;
V_83 = F_52 ( V_8 -> V_90 ) ;
if ( V_83 != 0 ) {
F_19 ( & V_140 -> V_2 , L_17 ) ;
return V_83 ;
}
if ( V_8 -> V_23 . V_144 ) {
V_83 = F_53 ( V_8 -> V_90 , V_151 ,
0x4 , 0x4 ) ;
if ( V_83 != 0 ) {
F_19 ( & V_140 -> V_2 , L_18 ,
V_83 ) ;
return V_83 ;
}
}
F_53 ( V_8 -> V_90 , V_152 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_153 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_154 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_155 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_156 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_157 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_158 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_159 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_160 , 0x100 , 0x100 ) ;
F_53 ( V_8 -> V_90 , V_161 , 0x100 , 0x100 ) ;
F_54 ( V_140 , V_8 ) ;
V_83 = F_55 ( & V_140 -> V_2 ,
& V_162 , & V_163 , 1 ) ;
return V_83 ;
}
static int F_56 ( struct V_139 * V_164 )
{
F_57 ( & V_164 -> V_2 ) ;
return 0 ;
}
