static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 >= V_4 )
return 0 ;
return V_5 [ V_3 ] . V_6 != 0 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 > V_7 )
return 1 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
return 1 ;
}
return 0 ;
}
static void F_3 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned int V_26 , T_1 * V_27 )
{
unsigned int V_28 ;
unsigned int V_29 ;
if ( F_4 ( V_26 > 4 ) ||
F_4 ( V_25 > 1 ) )
return;
V_28 = V_25 ? V_30 : V_31 ;
V_28 += V_26 * ( V_32 << 1 ) ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
F_5 ( V_24 , V_28 ++ , F_6 ( V_27 [ V_29 ] ) ) ;
F_5 ( V_24 , V_28 ++ , F_7 ( V_27 [ V_29 ] ) ) ;
}
}
static void F_8 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned int V_26 , T_1 * V_27 )
{
unsigned int V_33 ;
unsigned int V_29 ;
if ( F_4 ( V_26 > 1 ) ||
F_4 ( V_25 > 1 ) )
return;
V_33 = V_25 ? V_34 : V_35 ;
V_33 += V_26 * ( V_32 << 1 ) ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
F_5 ( V_24 , V_33 ++ , F_6 ( V_27 [ V_29 ] ) ) ;
F_5 ( V_24 , V_33 ++ , F_7 ( V_27 [ V_29 ] ) ) ;
}
}
static int F_9 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
V_41 -> V_44 = V_42 ;
F_12 ( V_24 , V_45 , V_46 ,
( 1 + V_42 ) << V_47 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
V_39 -> V_43 . integer . V_43 [ 0 ] = V_41 -> V_44 ;
return 0 ;
}
static int F_14 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
V_41 -> V_48 = V_42 ;
F_12 ( V_24 , V_49 , V_46 ,
( 1 + V_42 ) << V_47 ) ;
return 0 ;
}
static int F_15 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
V_39 -> V_43 . integer . V_43 [ 0 ] = V_41 -> V_48 ;
return 0 ;
}
static int F_16 ( struct V_50 * V_51 ,
struct V_36 * V_37 , int V_52 )
{
struct V_23 * V_24 = V_51 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
switch ( V_52 ) {
case V_53 :
if ( V_51 -> V_3 == V_45 ) {
F_12 ( V_24 , V_51 -> V_3 , V_46 ,
( 1 + V_41 -> V_44 ) << V_47 ) ;
} else {
F_12 ( V_24 , V_51 -> V_3 , V_46 ,
( 1 + V_41 -> V_48 ) << V_47 ) ;
}
break;
case V_54 :
F_12 ( V_24 , V_51 -> V_3 , V_46 , 0 ) ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int F_17 ( struct V_50 * V_51 ,
int V_52 , T_2 V_56 )
{
struct V_23 * V_24 = V_51 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
T_2 * V_57 ;
if ( F_4 ( ! ( V_56 == 1 || V_56 == 2 ) ) )
return - V_55 ;
V_57 = & V_41 -> V_58 ;
switch ( V_52 ) {
case V_53 :
* V_57 |= V_56 ;
F_12 ( V_24 , V_51 -> V_3 ,
( 1 << V_51 -> V_59 ) , ( 1 << V_51 -> V_59 ) ) ;
break;
case V_54 :
* V_57 &= ~ V_56 ;
if ( * V_57 == 0 ) {
F_12 ( V_24 , V_51 -> V_3 ,
( 1 << V_51 -> V_59 ) , 0 ) ;
}
break;
default:
return - V_55 ;
}
return 0 ;
}
static int F_18 ( struct V_50 * V_51 ,
struct V_36 * V_60 , int V_52 )
{
return F_17 ( V_51 , V_52 , 1 ) ;
}
static int F_19 ( struct V_50 * V_51 ,
struct V_36 * V_60 , int V_52 )
{
return F_17 ( V_51 , V_52 , 2 ) ;
}
static int F_20 ( struct V_50 * V_51 ,
struct V_36 * V_37 , int V_52 )
{
struct V_23 * V_24 = V_51 -> V_24 ;
switch ( V_52 ) {
case V_53 :
F_12 ( V_24 , V_51 -> V_3 ,
( 1 << ( V_51 -> V_59 + 2 ) ) , ( 1 << ( V_51 -> V_59 + 2 ) ) ) ;
break;
case V_54 :
F_12 ( V_24 , V_51 -> V_3 ,
( 1 << ( V_51 -> V_59 + 2 ) ) , 0 ) ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int F_21 ( int V_61 , T_2 * V_43 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_22 ( V_62 ) ; V_29 ++ ) {
if ( V_62 [ V_29 ] . V_61 >= V_61 ) {
* V_43 = V_62 [ V_29 ] . V_63 ;
return 0 ;
}
}
* V_43 = V_62 [ 0 ] . V_63 ;
return - V_55 ;
}
static int F_23 ( struct V_64 * V_65 ,
struct V_66 * V_67 ,
struct V_68 * V_25 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
unsigned long long V_71 ;
unsigned int V_61 ;
T_2 V_72 ;
V_70 = & V_41 -> V_25 [ 0 ] ;
V_61 = F_24 ( V_67 ) ;
switch ( F_25 ( V_67 ) ) {
case 16 :
F_12 ( V_24 , V_73 ,
V_74 , 0 ) ;
break;
case 24 :
F_12 ( V_24 , V_73 ,
V_74 , V_74 ) ;
break;
default:
return - V_55 ;
}
if ( F_21 ( V_61 , & V_72 ) )
return - V_55 ;
F_12 ( V_24 , V_75 ,
V_76 , V_72 ) ;
V_70 -> V_61 = V_61 ;
if ( F_26 ( V_24 , V_73 ) & V_77 ) {
if ( V_41 -> V_78 == 0 ) {
F_27 ( V_24 -> V_2 , L_1 ) ;
return - V_55 ;
}
V_71 = 65536ULL * ( V_61 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_61 ;
F_28 ( V_71 , ( unsigned long long int ) V_41 -> V_78 ) ;
F_5 ( V_24 , V_79 ,
( V_71 >> 8 ) & 0x7F ) ;
F_5 ( V_24 , V_80 ,
V_71 & 0xFF ) ;
}
if ( V_61 < 50000 )
F_12 ( V_24 , V_81 ,
V_82 , 0 ) ;
else
F_12 ( V_24 , V_81 ,
V_82 , V_82 ) ;
return 0 ;
}
static int F_29 ( struct V_64 * V_65 ,
struct V_66 * V_67 ,
struct V_68 * V_25 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
unsigned long long V_71 ;
unsigned int V_61 ;
T_2 V_72 ;
V_70 = & V_41 -> V_25 [ 1 ] ;
V_61 = F_24 ( V_67 ) ;
switch ( F_25 ( V_67 ) ) {
case 16 :
F_12 ( V_24 , V_83 ,
V_74 , 0 ) ;
break;
case 24 :
F_12 ( V_24 , V_83 ,
V_74 , V_74 ) ;
break;
default:
return - V_55 ;
}
if ( F_21 ( V_61 , & V_72 ) )
return - V_55 ;
F_12 ( V_24 , V_84 ,
V_76 , V_72 ) ;
V_70 -> V_61 = V_61 ;
if ( F_26 ( V_24 , V_83 ) & V_77 ) {
if ( V_41 -> V_78 == 0 ) {
F_27 ( V_24 -> V_2 , L_1 ) ;
return - V_55 ;
}
V_71 = 65536ULL * ( V_61 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_61 ;
F_28 ( V_71 , ( unsigned long long int ) V_41 -> V_78 ) ;
F_5 ( V_24 , V_85 ,
( V_71 >> 8 ) & 0x7F ) ;
F_5 ( V_24 , V_86 ,
V_71 & 0xFF ) ;
}
if ( V_61 < 50000 )
F_12 ( V_24 , V_87 ,
V_82 , 0 ) ;
else
F_12 ( V_24 , V_87 ,
V_82 , V_82 ) ;
return 0 ;
}
static int F_30 ( struct V_64 * V_65 ,
struct V_66 * V_67 ,
struct V_68 * V_25 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
unsigned long long V_71 ;
unsigned int V_61 ;
T_2 V_72 ;
V_70 = & V_41 -> V_25 [ 2 ] ;
V_61 = F_24 ( V_67 ) ;
switch ( F_25 ( V_67 ) ) {
case 16 :
F_12 ( V_24 , V_88 ,
V_74 , 0 ) ;
break;
case 24 :
F_12 ( V_24 , V_88 ,
V_74 , V_74 ) ;
break;
default:
return - V_55 ;
}
if ( F_21 ( V_61 , & V_72 ) )
return - V_55 ;
F_12 ( V_24 , V_89 ,
V_76 , V_72 ) ;
V_70 -> V_61 = V_61 ;
if ( F_26 ( V_24 , V_88 ) & V_77 ) {
if ( V_41 -> V_78 == 0 ) {
F_27 ( V_24 -> V_2 , L_1 ) ;
return - V_55 ;
}
V_71 = 65536ULL * ( V_61 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_61 ;
F_28 ( V_71 , ( unsigned long long int ) V_41 -> V_78 ) ;
F_5 ( V_24 , V_90 ,
( V_71 >> 8 ) & 0x7F ) ;
F_5 ( V_24 , V_91 ,
V_71 & 0xFF ) ;
}
if ( V_61 < 50000 )
F_12 ( V_24 , V_92 ,
V_82 , 0 ) ;
else
F_12 ( V_24 , V_92 ,
V_82 , V_82 ) ;
return 0 ;
}
static int F_31 ( struct V_68 * V_25 ,
int V_93 , unsigned int V_94 , int V_95 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
if ( V_94 == V_41 -> V_78 )
return 0 ;
if ( ! F_32 ( V_41 -> V_96 ) ) {
V_94 = F_33 ( V_41 -> V_96 , V_94 ) ;
F_34 ( V_41 -> V_96 , V_94 ) ;
}
if ( ( V_94 >= 10000000 ) && ( V_94 < 20000000 ) ) {
F_5 ( V_24 , V_97 , 0x10 ) ;
} else if ( ( V_94 >= 20000000 ) && ( V_94 < 40000000 ) ) {
F_5 ( V_24 , V_97 , 0x20 ) ;
} else if ( ( V_94 >= 40000000 ) && ( V_94 < 60000000 ) ) {
F_5 ( V_24 , V_97 , 0x30 ) ;
} else {
F_27 ( V_24 -> V_2 , L_2 ) ;
return - V_55 ;
}
F_35 ( V_25 -> V_2 , L_3 , V_93 , V_94 ) ;
V_41 -> V_78 = V_94 ;
return 0 ;
}
static int F_36 ( struct V_68 * V_98 ,
unsigned int V_99 )
{
struct V_23 * V_24 = V_98 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 0 ] ;
if ( V_99 != V_70 -> V_99 ) {
V_70 -> V_99 = V_99 ;
switch ( V_99 & V_100 ) {
case V_101 :
F_5 ( V_24 , V_79 ,
0x80 ) ;
F_5 ( V_24 , V_80 ,
0x00 ) ;
break;
case V_102 :
V_72 |= V_77 ;
break;
case V_103 :
case V_104 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_99 & V_105 ) {
case V_106 :
V_72 |= V_107 ;
break;
case V_108 :
break;
default:
return - V_55 ;
}
switch ( V_99 & V_109 ) {
case V_110 :
break;
case V_111 :
V_72 |= V_112 ;
break;
case V_113 :
V_72 |= V_114 ;
break;
case V_115 :
V_72 |= V_114 | V_112 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_73 ,
V_77 | V_107 | V_114 |
V_112 , V_72 ) ;
F_5 ( V_24 , V_116 , V_117 ) ;
}
return 0 ;
}
static int F_37 ( struct V_68 * V_98 ,
unsigned int V_99 )
{
struct V_23 * V_24 = V_98 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 1 ] ;
if ( V_99 != V_70 -> V_99 ) {
V_70 -> V_99 = V_99 ;
switch ( V_99 & V_100 ) {
case V_101 :
F_5 ( V_24 , V_85 ,
0x80 ) ;
F_5 ( V_24 , V_86 ,
0x00 ) ;
break;
case V_102 :
V_72 |= V_77 ;
break;
case V_103 :
case V_104 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_99 & V_105 ) {
case V_106 :
V_72 |= V_107 ;
break;
case V_108 :
break;
default:
return - V_55 ;
}
switch ( V_99 & V_109 ) {
case V_110 :
break;
case V_111 :
V_72 |= V_112 ;
break;
case V_113 :
V_72 |= V_114 ;
break;
case V_115 :
V_72 |= V_114 | V_112 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_83 ,
V_77 | V_107 | V_114 |
V_112 , V_72 ) ;
F_5 ( V_24 , V_118 ,
V_117 ) ;
}
return 0 ;
}
static int F_38 ( struct V_68 * V_98 ,
unsigned int V_99 )
{
struct V_23 * V_24 = V_98 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 2 ] ;
if ( V_99 != V_70 -> V_99 ) {
V_70 -> V_99 = V_99 ;
switch ( V_99 & V_100 ) {
case V_101 :
F_5 ( V_24 , V_90 ,
0x80 ) ;
F_5 ( V_24 , V_91 ,
0x00 ) ;
break;
case V_102 :
V_72 |= V_77 ;
break;
case V_103 :
case V_104 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_99 & V_105 ) {
case V_106 :
V_72 |= V_107 ;
break;
case V_108 :
break;
default:
return - V_55 ;
}
switch ( V_99 & V_109 ) {
case V_110 :
break;
case V_111 :
V_72 |= V_112 ;
break;
case V_113 :
V_72 |= V_114 ;
break;
case V_115 :
V_72 |= V_114 | V_112 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_88 ,
V_77 | V_107 | V_114 |
V_112 , V_72 ) ;
F_5 ( V_24 , V_119 ,
V_117 ) ;
}
return 0 ;
}
static int F_39 ( struct V_23 * V_24 ,
enum V_120 V_121 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_122 ;
switch ( V_121 ) {
case V_123 :
break;
case V_124 :
if ( ! F_32 ( V_41 -> V_96 ) ) {
if ( V_24 -> V_125 . V_126 == V_123 )
F_40 ( V_41 -> V_96 ) ;
else
F_41 ( V_41 -> V_96 ) ;
}
break;
case V_127 :
if ( V_24 -> V_125 . V_126 == V_128 ) {
V_122 = F_42 ( V_41 -> V_129 ) ;
if ( V_122 != 0 ) {
F_27 ( V_24 -> V_2 , L_5 , V_122 ) ;
return V_122 ;
}
}
F_12 ( V_24 , V_130 ,
V_131 , V_131 ) ;
break;
case V_128 :
F_12 ( V_24 , V_130 ,
V_131 , 0 ) ;
F_43 ( V_41 -> V_129 ) ;
break;
}
V_24 -> V_125 . V_126 = V_121 ;
return 0 ;
}
static int F_44 ( const char * V_132 )
{
if ( strcmp ( V_132 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_132 , L_7 ) == 0 )
return 1 ;
return - V_55 ;
}
static int F_45 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_133 * V_134 = V_41 -> V_134 ;
int V_56 = F_44 ( V_37 -> V_135 . V_132 ) ;
struct V_69 * V_70 ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
struct V_136 * V_137 ;
int V_138 , V_139 , V_140 , V_29 ;
int V_141 , V_142 ;
if ( F_4 ( V_56 > 1 ) )
return - V_55 ;
if ( ! V_134 || ! V_41 -> V_143 )
return 0 ;
if ( V_42 >= V_134 -> V_144 )
return - V_55 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_70 -> V_145 = V_42 ;
V_138 = V_70 -> V_61 ;
V_139 = 0 ;
V_140 = V_146 ;
for ( V_29 = 0 ; V_29 < V_134 -> V_144 ; V_29 ++ ) {
if ( strcmp ( V_134 -> V_147 [ V_29 ] . V_132 , V_41 -> V_148 [ V_42 ] ) == 0 &&
abs ( V_134 -> V_147 [ V_29 ] . V_61 - V_138 ) < V_140 ) {
V_139 = V_29 ;
V_140 = abs ( V_134 -> V_147 [ V_29 ] . V_61 - V_138 ) ;
}
}
F_35 ( V_24 -> V_2 , L_8 ,
V_134 -> V_147 [ V_139 ] . V_132 ,
V_134 -> V_147 [ V_139 ] . V_61 , V_138 ) ;
V_137 = & V_134 -> V_147 [ V_139 ] ;
V_141 = ( V_56 == 0 ) ? V_149 : V_150 ;
V_142 = F_26 ( V_24 , V_151 ) ;
F_12 ( V_24 , V_151 , V_141 , 0 ) ;
F_46 ( & V_24 -> V_152 ) ;
F_12 ( V_24 , V_153 , V_154 , V_154 ) ;
F_3 ( V_24 , V_56 , 0 , V_137 -> V_155 ) ;
F_3 ( V_24 , V_56 , 1 , V_137 -> V_156 ) ;
F_3 ( V_24 , V_56 , 2 , V_137 -> V_157 ) ;
F_3 ( V_24 , V_56 , 3 , V_137 -> V_158 ) ;
F_3 ( V_24 , V_56 , 4 , V_137 -> V_159 ) ;
F_12 ( V_24 , V_153 , V_154 , 0 ) ;
F_47 ( & V_24 -> V_152 ) ;
F_12 ( V_24 , V_151 , V_141 , V_142 ) ;
return 0 ;
}
static int F_48 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_56 = F_44 ( V_37 -> V_135 . V_132 ) ;
struct V_69 * V_70 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_39 -> V_43 . V_160 . V_161 [ 0 ] = V_70 -> V_145 ;
return 0 ;
}
static void F_49 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_133 * V_134 = V_41 -> V_134 ;
struct V_136 * V_162 ;
unsigned int V_163 ;
int V_29 , V_164 ;
const char * * V_165 ;
int V_122 ;
struct V_166 V_167 [] = {
F_50 ( L_6 ,
V_41 -> V_168 ,
F_48 ,
F_45 ) ,
F_50 ( L_7 ,
V_41 -> V_168 ,
F_48 ,
F_45 ) ,
} ;
V_162 = V_134 -> V_147 ;
V_163 = V_134 -> V_144 ;
V_41 -> V_143 = 0 ;
V_41 -> V_148 = NULL ;
for ( V_29 = 0 ; V_29 < V_163 ; V_29 ++ ) {
for ( V_164 = 0 ; V_164 < V_41 -> V_143 ; V_164 ++ ) {
if ( strcmp ( V_162 [ V_29 ] . V_132 , V_41 -> V_148 [ V_164 ] ) == 0 )
break;
}
if ( V_164 != V_41 -> V_143 )
continue;
V_165 = F_51 ( V_41 -> V_148 ,
sizeof( char * ) * ( V_41 -> V_143 + 1 ) ,
V_169 ) ;
if ( V_165 == NULL )
continue;
V_165 [ V_41 -> V_143 ] = V_162 [ V_29 ] . V_132 ;
V_41 -> V_143 ++ ;
V_41 -> V_148 = V_165 ;
}
V_41 -> V_168 . V_170 = V_41 -> V_148 ;
V_41 -> V_168 . V_171 = V_41 -> V_143 ;
V_122 = F_52 ( V_24 , V_167 , F_22 ( V_167 ) ) ;
if ( V_122 != 0 )
F_27 ( V_24 -> V_2 , L_9 , V_122 ) ;
}
static int F_53 ( struct V_23 * V_24 ,
const char * V_132 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_22 ( V_172 ) ; V_29 ++ )
if ( strcmp ( V_132 , V_172 [ V_29 ] ) == 0 )
return V_29 ;
F_27 ( V_24 -> V_2 , L_10 , V_132 ) ;
return - V_55 ;
}
static int F_54 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_133 * V_134 = V_41 -> V_134 ;
int V_56 = F_53 ( V_24 , V_37 -> V_135 . V_132 ) ;
struct V_69 * V_70 ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
struct V_173 * V_137 ;
int V_138 , V_139 , V_140 , V_29 ;
int V_141 , V_142 ;
if ( V_56 < 0 )
return V_56 ;
if ( ! V_134 || ! V_41 -> V_174 )
return 0 ;
if ( V_42 >= V_134 -> V_175 )
return - V_55 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_70 -> V_176 = V_42 ;
V_138 = V_70 -> V_61 ;
V_139 = 0 ;
V_140 = V_146 ;
for ( V_29 = 0 ; V_29 < V_134 -> V_175 ; V_29 ++ ) {
if ( strcmp ( V_134 -> V_177 [ V_29 ] . V_132 , V_41 -> V_178 [ V_42 ] ) == 0 &&
abs ( V_134 -> V_177 [ V_29 ] . V_61 - V_138 ) < V_140 ) {
V_139 = V_29 ;
V_140 = abs ( V_134 -> V_177 [ V_29 ] . V_61 - V_138 ) ;
}
}
F_35 ( V_24 -> V_2 , L_8 ,
V_134 -> V_177 [ V_139 ] . V_132 ,
V_134 -> V_177 [ V_139 ] . V_61 , V_138 ) ;
V_137 = & V_134 -> V_177 [ V_139 ] ;
V_141 = ( V_56 == 0 ) ? V_179 : V_180 ;
V_142 = F_26 ( V_24 , V_151 ) ;
F_12 ( V_24 , V_151 , V_141 , 0 ) ;
F_46 ( & V_24 -> V_152 ) ;
F_12 ( V_24 , V_153 , V_154 , V_154 ) ;
F_8 ( V_24 , V_56 , 0 , V_137 -> V_155 ) ;
F_8 ( V_24 , V_56 , 1 , V_137 -> V_156 ) ;
F_12 ( V_24 , V_153 , V_154 , 0 ) ;
F_47 ( & V_24 -> V_152 ) ;
F_12 ( V_24 , V_151 , V_141 , V_142 ) ;
return 0 ;
}
static int F_55 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_56 = F_53 ( V_24 , V_37 -> V_135 . V_132 ) ;
struct V_69 * V_70 ;
if ( V_56 < 0 )
return V_56 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_39 -> V_43 . V_160 . V_161 [ 0 ] = V_70 -> V_176 ;
return 0 ;
}
static void F_56 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_133 * V_134 = V_41 -> V_134 ;
struct V_173 * V_162 ;
unsigned int V_163 ;
int V_29 , V_164 ;
const char * * V_165 ;
int V_122 ;
struct V_166 V_167 [] = {
F_50 ( ( char * ) V_172 [ 0 ] ,
V_41 -> V_181 ,
F_55 ,
F_54 ) ,
F_50 ( ( char * ) V_172 [ 1 ] ,
V_41 -> V_181 ,
F_55 ,
F_54 ) ,
} ;
F_57 ( F_22 ( V_167 ) != F_22 ( V_172 ) ) ;
V_162 = V_134 -> V_177 ;
V_163 = V_134 -> V_175 ;
V_41 -> V_174 = 0 ;
V_41 -> V_178 = NULL ;
for ( V_29 = 0 ; V_29 < V_163 ; V_29 ++ ) {
for ( V_164 = 0 ; V_164 < V_41 -> V_174 ; V_164 ++ ) {
if ( strcmp ( V_162 [ V_29 ] . V_132 , V_41 -> V_178 [ V_164 ] ) == 0 )
break;
}
if ( V_164 != V_41 -> V_174 )
continue;
V_165 = F_51 ( V_41 -> V_178 ,
sizeof( char * ) * ( V_41 -> V_174 + 1 ) ,
V_169 ) ;
if ( V_165 == NULL )
continue;
V_165 [ V_41 -> V_174 ] = V_162 [ V_29 ] . V_132 ;
V_41 -> V_174 ++ ;
V_41 -> V_178 = V_165 ;
}
V_41 -> V_181 . V_170 = V_41 -> V_178 ;
V_41 -> V_181 . V_171 = V_41 -> V_174 ;
V_122 = F_52 ( V_24 , V_167 , F_22 ( V_167 ) ) ;
if ( V_122 != 0 )
F_27 ( V_24 -> V_2 , L_11 , V_122 ) ;
}
static void F_58 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_133 * V_134 = V_41 -> V_134 ;
T_2 V_72 = 0 ;
if ( ! V_134 ) {
F_35 ( V_24 -> V_2 , L_12 ) ;
return;
}
if ( V_134 -> V_182 )
V_72 |= V_183 ;
if ( V_134 -> V_184 )
V_72 |= V_185 ;
F_5 ( V_24 , V_186 , V_72 ) ;
if ( V_134 -> V_144 )
F_49 ( V_24 ) ;
if ( V_134 -> V_175 )
F_56 ( V_24 ) ;
}
static T_3 F_59 ( int V_187 , void * V_188 )
{
struct V_23 * V_24 = V_188 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
unsigned int V_43 ;
int V_189 = 0 ;
int V_190 = 0 ;
V_43 = F_26 ( V_24 , V_15 ) ;
if ( ( V_43 & V_191 ) == 0 )
return V_192 ;
if ( ( V_43 & V_193 || V_43 & V_194 ) &&
V_41 -> V_195 )
V_189 |= V_196 ;
if ( ( V_43 & V_197 ) && V_41 -> V_198 )
V_190 |= V_199 ;
if ( V_41 -> V_195 == V_41 -> V_198 ) {
F_60 ( V_41 -> V_195 ,
V_189 | V_190 ,
V_200 ) ;
} else {
if ( V_41 -> V_195 )
F_60 ( V_41 -> V_195 ,
V_189 , V_196 ) ;
if ( V_41 -> V_198 )
F_60 ( V_41 -> V_198 ,
V_190 , V_199 ) ;
}
return V_201 ;
}
static int F_61 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_122 = 0 ;
int V_202 = V_203 ;
unsigned int V_204 = V_205 ;
if ( V_41 -> V_134 -> V_206 )
V_202 |= V_207 ;
if ( V_41 -> V_134 -> V_208 )
V_204 = V_41 -> V_134 -> V_208 ;
V_122 = F_5 ( V_24 , V_209 , V_204 ) ;
if ( V_122 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_122 ) ;
return V_122 ;
}
V_122 = F_5 ( V_24 , V_210 , V_202 ) ;
if ( V_122 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_122 ) ;
return V_122 ;
}
return V_122 ;
}
static int F_62 ( struct V_23 * V_24 )
{
int V_122 = 0 ;
V_122 = F_5 ( V_24 , V_210 , 0x0 ) ;
if ( V_122 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_122 ) ;
return V_122 ;
}
return V_122 ;
}
int F_63 ( struct V_23 * V_24 ,
struct V_211 * V_212 , struct V_211 * V_198 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_213 * V_214 = F_64 ( V_24 -> V_2 ) ;
int V_122 = 0 ;
V_41 -> V_195 = V_212 ;
V_41 -> V_198 = V_198 ;
if ( ! V_212 && ! V_198 )
return - V_55 ;
F_61 ( V_24 ) ;
V_122 = F_12 ( V_24 , V_215 ,
V_216 , V_216 ) ;
if ( V_122 < 0 ) {
F_27 ( V_24 -> V_2 , L_14 , V_122 ) ;
return V_122 ;
}
F_59 ( V_214 -> V_187 , V_24 ) ;
return 0 ;
}
static int F_65 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
if ( V_41 -> V_195 || V_41 -> V_198 )
F_62 ( V_24 ) ;
F_39 ( V_24 , V_128 ) ;
return 0 ;
}
static int F_66 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_213 * V_214 = F_64 ( V_24 -> V_2 ) ;
F_39 ( V_24 , V_127 ) ;
if ( V_41 -> V_195 || V_41 -> V_198 ) {
F_61 ( V_24 ) ;
F_59 ( V_214 -> V_187 , V_24 ) ;
}
return 0 ;
}
static int F_67 ( struct V_23 * V_24 )
{
int V_29 , V_122 ;
V_122 = F_5 ( V_24 , V_153 , 0 ) ;
if ( V_122 < 0 ) {
F_27 ( V_24 -> V_2 , L_15 , V_122 ) ;
return V_122 ;
}
V_122 = F_5 ( V_24 , V_217 , 0 ) ;
if ( V_122 < 0 ) {
F_27 ( V_24 -> V_2 , L_16 , V_122 ) ;
return V_122 ;
}
for ( V_29 = V_218 ; V_29 < V_7 ; V_29 ++ ) {
V_122 = F_5 ( V_24 , V_29 , F_26 ( V_24 , V_29 ) ) ;
if ( V_122 < 0 ) {
F_27 ( V_24 -> V_2 , L_17 , V_122 ) ;
return V_122 ;
}
}
return V_122 ;
}
static int F_68 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
struct V_213 * V_214 ;
int V_122 = 0 ;
V_41 -> V_96 = F_69 ( V_24 -> V_2 , L_18 ) ;
if ( F_70 ( V_41 -> V_96 ) == - V_219 )
return - V_219 ;
F_67 ( V_24 ) ;
V_214 = F_64 ( V_24 -> V_2 ) ;
V_41 -> V_78 = ( unsigned ) - 1 ;
V_41 -> V_143 = 0 ;
V_41 -> V_174 = 0 ;
V_70 = & V_41 -> V_25 [ 0 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_99 = ( unsigned ) - 1 ;
V_70 -> V_145 = 0 ;
V_70 -> V_176 = 0 ;
V_70 = & V_41 -> V_25 [ 1 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_99 = ( unsigned ) - 1 ;
V_70 -> V_145 = 0 ;
V_70 -> V_176 = 0 ;
V_70 = & V_41 -> V_25 [ 2 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_99 = ( unsigned ) - 1 ;
V_70 -> V_145 = 0 ;
V_70 -> V_176 = 0 ;
V_41 -> V_58 = 0 ;
V_41 -> V_44 = 0 ;
V_41 -> V_48 = 0 ;
if ( V_214 -> V_187 ) {
V_122 = F_71 ( V_214 -> V_187 , NULL ,
F_59 ,
V_220 | V_221 ,
L_19 , V_24 ) ;
if ( V_122 ) {
F_27 ( V_24 -> V_2 , L_20 , V_122 ) ;
goto V_222;
}
}
V_122 = F_26 ( V_24 , V_223 ) ;
if ( V_122 < 0 ) {
F_27 ( V_24 -> V_2 , L_21 ,
V_122 ) ;
goto V_224;
}
F_72 ( V_24 -> V_2 , L_22 , V_122 - 0x40 + 'A' ) ;
F_5 ( V_24 , V_217 , V_225 ) ;
F_39 ( V_24 , V_127 ) ;
F_5 ( V_24 , V_226 ,
V_227 | V_228 ) ;
F_5 ( V_24 , V_229 ,
V_230 | V_231 ) ;
F_5 ( V_24 , V_232 , V_233 ) ;
F_5 ( V_24 , V_234 , V_235 ) ;
F_5 ( V_24 , V_236 , V_237 ) ;
F_5 ( V_24 , V_238 ,
V_239 | V_240 ) ;
F_5 ( V_24 , V_241 ,
V_242 | V_240 ) ;
F_5 ( V_24 , V_243 ,
V_244 | V_240 ) ;
F_58 ( V_24 ) ;
F_12 ( V_24 , V_217 , V_245 ,
V_245 ) ;
return 0 ;
V_224:
if ( V_214 -> V_187 )
F_73 ( V_214 -> V_187 , V_24 ) ;
V_222:
return V_122 ;
}
static int F_74 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_213 * V_214 = F_64 ( V_24 -> V_2 ) ;
F_39 ( V_24 , V_128 ) ;
if ( V_41 -> V_195 || V_41 -> V_198 )
F_62 ( V_24 ) ;
if ( V_214 -> V_187 )
F_73 ( V_214 -> V_187 , V_24 ) ;
return 0 ;
}
static int F_75 ( struct V_213 * V_246 ,
const struct V_247 * V_135 )
{
struct V_40 * V_41 ;
int V_122 ;
V_41 = F_76 ( & V_246 -> V_2 , sizeof( struct V_40 ) ,
V_169 ) ;
if ( V_41 == NULL )
return - V_248 ;
V_41 -> V_129 = F_77 ( V_246 , & V_249 ) ;
if ( F_32 ( V_41 -> V_129 ) ) {
V_122 = F_70 ( V_41 -> V_129 ) ;
F_27 ( & V_246 -> V_2 , L_23 , V_122 ) ;
return V_122 ;
}
V_41 -> V_250 = V_135 -> V_251 ;
F_78 ( V_246 , V_41 ) ;
V_41 -> V_134 = V_246 -> V_2 . V_252 ;
V_122 = F_79 ( & V_246 -> V_2 , & V_253 ,
V_254 , F_22 ( V_254 ) ) ;
return V_122 ;
}
static int F_80 ( struct V_213 * V_214 )
{
F_81 ( & V_214 -> V_2 ) ;
return 0 ;
}
