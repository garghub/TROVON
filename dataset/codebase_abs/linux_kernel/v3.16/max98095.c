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
switch ( F_30 ( V_67 ) ) {
case V_83 :
F_12 ( V_24 , V_84 ,
V_74 , 0 ) ;
break;
case V_85 :
F_12 ( V_24 , V_84 ,
V_74 , V_74 ) ;
break;
default:
return - V_55 ;
}
if ( F_21 ( V_61 , & V_72 ) )
return - V_55 ;
F_12 ( V_24 , V_86 ,
V_76 , V_72 ) ;
V_70 -> V_61 = V_61 ;
if ( F_26 ( V_24 , V_84 ) & V_77 ) {
if ( V_41 -> V_78 == 0 ) {
F_27 ( V_24 -> V_2 , L_1 ) ;
return - V_55 ;
}
V_71 = 65536ULL * ( V_61 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_61 ;
F_28 ( V_71 , ( unsigned long long int ) V_41 -> V_78 ) ;
F_5 ( V_24 , V_87 ,
( V_71 >> 8 ) & 0x7F ) ;
F_5 ( V_24 , V_88 ,
V_71 & 0xFF ) ;
}
if ( V_61 < 50000 )
F_12 ( V_24 , V_89 ,
V_82 , 0 ) ;
else
F_12 ( V_24 , V_89 ,
V_82 , V_82 ) ;
return 0 ;
}
static int F_31 ( struct V_64 * V_65 ,
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
switch ( F_30 ( V_67 ) ) {
case V_83 :
F_12 ( V_24 , V_90 ,
V_74 , 0 ) ;
break;
case V_85 :
F_12 ( V_24 , V_90 ,
V_74 , V_74 ) ;
break;
default:
return - V_55 ;
}
if ( F_21 ( V_61 , & V_72 ) )
return - V_55 ;
F_12 ( V_24 , V_91 ,
V_76 , V_72 ) ;
V_70 -> V_61 = V_61 ;
if ( F_26 ( V_24 , V_90 ) & V_77 ) {
if ( V_41 -> V_78 == 0 ) {
F_27 ( V_24 -> V_2 , L_1 ) ;
return - V_55 ;
}
V_71 = 65536ULL * ( V_61 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_61 ;
F_28 ( V_71 , ( unsigned long long int ) V_41 -> V_78 ) ;
F_5 ( V_24 , V_92 ,
( V_71 >> 8 ) & 0x7F ) ;
F_5 ( V_24 , V_93 ,
V_71 & 0xFF ) ;
}
if ( V_61 < 50000 )
F_12 ( V_24 , V_94 ,
V_82 , 0 ) ;
else
F_12 ( V_24 , V_94 ,
V_82 , V_82 ) ;
return 0 ;
}
static int F_32 ( struct V_68 * V_25 ,
int V_95 , unsigned int V_96 , int V_97 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
if ( V_96 == V_41 -> V_78 )
return 0 ;
if ( ! F_33 ( V_41 -> V_98 ) ) {
V_96 = F_34 ( V_41 -> V_98 , V_96 ) ;
F_35 ( V_41 -> V_98 , V_96 ) ;
}
if ( ( V_96 >= 10000000 ) && ( V_96 < 20000000 ) ) {
F_5 ( V_24 , V_99 , 0x10 ) ;
} else if ( ( V_96 >= 20000000 ) && ( V_96 < 40000000 ) ) {
F_5 ( V_24 , V_99 , 0x20 ) ;
} else if ( ( V_96 >= 40000000 ) && ( V_96 < 60000000 ) ) {
F_5 ( V_24 , V_99 , 0x30 ) ;
} else {
F_27 ( V_24 -> V_2 , L_2 ) ;
return - V_55 ;
}
F_36 ( V_25 -> V_2 , L_3 , V_95 , V_96 ) ;
V_41 -> V_78 = V_96 ;
return 0 ;
}
static int F_37 ( struct V_68 * V_100 ,
unsigned int V_101 )
{
struct V_23 * V_24 = V_100 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 0 ] ;
if ( V_101 != V_70 -> V_101 ) {
V_70 -> V_101 = V_101 ;
switch ( V_101 & V_102 ) {
case V_103 :
F_5 ( V_24 , V_79 ,
0x80 ) ;
F_5 ( V_24 , V_80 ,
0x00 ) ;
break;
case V_104 :
V_72 |= V_77 ;
break;
case V_105 :
case V_106 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_101 & V_107 ) {
case V_108 :
V_72 |= V_109 ;
break;
case V_110 :
break;
default:
return - V_55 ;
}
switch ( V_101 & V_111 ) {
case V_112 :
break;
case V_113 :
V_72 |= V_114 ;
break;
case V_115 :
V_72 |= V_116 ;
break;
case V_117 :
V_72 |= V_116 | V_114 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_73 ,
V_77 | V_109 | V_116 |
V_114 , V_72 ) ;
F_5 ( V_24 , V_118 , V_119 ) ;
}
return 0 ;
}
static int F_38 ( struct V_68 * V_100 ,
unsigned int V_101 )
{
struct V_23 * V_24 = V_100 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 1 ] ;
if ( V_101 != V_70 -> V_101 ) {
V_70 -> V_101 = V_101 ;
switch ( V_101 & V_102 ) {
case V_103 :
F_5 ( V_24 , V_87 ,
0x80 ) ;
F_5 ( V_24 , V_88 ,
0x00 ) ;
break;
case V_104 :
V_72 |= V_77 ;
break;
case V_105 :
case V_106 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_101 & V_107 ) {
case V_108 :
V_72 |= V_109 ;
break;
case V_110 :
break;
default:
return - V_55 ;
}
switch ( V_101 & V_111 ) {
case V_112 :
break;
case V_113 :
V_72 |= V_114 ;
break;
case V_115 :
V_72 |= V_116 ;
break;
case V_117 :
V_72 |= V_116 | V_114 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_84 ,
V_77 | V_109 | V_116 |
V_114 , V_72 ) ;
F_5 ( V_24 , V_120 ,
V_119 ) ;
}
return 0 ;
}
static int F_39 ( struct V_68 * V_100 ,
unsigned int V_101 )
{
struct V_23 * V_24 = V_100 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 2 ] ;
if ( V_101 != V_70 -> V_101 ) {
V_70 -> V_101 = V_101 ;
switch ( V_101 & V_102 ) {
case V_103 :
F_5 ( V_24 , V_92 ,
0x80 ) ;
F_5 ( V_24 , V_93 ,
0x00 ) ;
break;
case V_104 :
V_72 |= V_77 ;
break;
case V_105 :
case V_106 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_101 & V_107 ) {
case V_108 :
V_72 |= V_109 ;
break;
case V_110 :
break;
default:
return - V_55 ;
}
switch ( V_101 & V_111 ) {
case V_112 :
break;
case V_113 :
V_72 |= V_114 ;
break;
case V_115 :
V_72 |= V_116 ;
break;
case V_117 :
V_72 |= V_116 | V_114 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_90 ,
V_77 | V_109 | V_116 |
V_114 , V_72 ) ;
F_5 ( V_24 , V_121 ,
V_119 ) ;
}
return 0 ;
}
static int F_40 ( struct V_23 * V_24 ,
enum V_122 V_123 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_124 ;
switch ( V_123 ) {
case V_125 :
break;
case V_126 :
if ( ! F_33 ( V_41 -> V_98 ) ) {
if ( V_24 -> V_127 . V_128 == V_125 )
F_41 ( V_41 -> V_98 ) ;
else
F_42 ( V_41 -> V_98 ) ;
}
break;
case V_129 :
if ( V_24 -> V_127 . V_128 == V_130 ) {
V_124 = F_43 ( V_41 -> V_131 ) ;
if ( V_124 != 0 ) {
F_27 ( V_24 -> V_2 , L_5 , V_124 ) ;
return V_124 ;
}
}
F_12 ( V_24 , V_132 ,
V_133 , V_133 ) ;
break;
case V_130 :
F_12 ( V_24 , V_132 ,
V_133 , 0 ) ;
F_44 ( V_41 -> V_131 ) ;
break;
}
V_24 -> V_127 . V_128 = V_123 ;
return 0 ;
}
static int F_45 ( const char * V_134 )
{
if ( strcmp ( V_134 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_134 , L_7 ) == 0 )
return 1 ;
return - V_55 ;
}
static int F_46 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_135 * V_136 = V_41 -> V_136 ;
int V_56 = F_45 ( V_37 -> V_137 . V_134 ) ;
struct V_69 * V_70 ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
struct V_138 * V_139 ;
int V_140 , V_141 , V_142 , V_29 ;
int V_143 , V_144 ;
if ( F_4 ( V_56 > 1 ) )
return - V_55 ;
if ( ! V_136 || ! V_41 -> V_145 )
return 0 ;
if ( V_42 >= V_136 -> V_146 )
return - V_55 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_70 -> V_147 = V_42 ;
V_140 = V_70 -> V_61 ;
V_141 = 0 ;
V_142 = V_148 ;
for ( V_29 = 0 ; V_29 < V_136 -> V_146 ; V_29 ++ ) {
if ( strcmp ( V_136 -> V_149 [ V_29 ] . V_134 , V_41 -> V_150 [ V_42 ] ) == 0 &&
abs ( V_136 -> V_149 [ V_29 ] . V_61 - V_140 ) < V_142 ) {
V_141 = V_29 ;
V_142 = abs ( V_136 -> V_149 [ V_29 ] . V_61 - V_140 ) ;
}
}
F_36 ( V_24 -> V_2 , L_8 ,
V_136 -> V_149 [ V_141 ] . V_134 ,
V_136 -> V_149 [ V_141 ] . V_61 , V_140 ) ;
V_139 = & V_136 -> V_149 [ V_141 ] ;
V_143 = ( V_56 == 0 ) ? V_151 : V_152 ;
V_144 = F_26 ( V_24 , V_153 ) ;
F_12 ( V_24 , V_153 , V_143 , 0 ) ;
F_47 ( & V_24 -> V_154 ) ;
F_12 ( V_24 , V_155 , V_156 , V_156 ) ;
F_3 ( V_24 , V_56 , 0 , V_139 -> V_157 ) ;
F_3 ( V_24 , V_56 , 1 , V_139 -> V_158 ) ;
F_3 ( V_24 , V_56 , 2 , V_139 -> V_159 ) ;
F_3 ( V_24 , V_56 , 3 , V_139 -> V_160 ) ;
F_3 ( V_24 , V_56 , 4 , V_139 -> V_161 ) ;
F_12 ( V_24 , V_155 , V_156 , 0 ) ;
F_48 ( & V_24 -> V_154 ) ;
F_12 ( V_24 , V_153 , V_143 , V_144 ) ;
return 0 ;
}
static int F_49 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_56 = F_45 ( V_37 -> V_137 . V_134 ) ;
struct V_69 * V_70 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_39 -> V_43 . V_162 . V_163 [ 0 ] = V_70 -> V_147 ;
return 0 ;
}
static void F_50 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_135 * V_136 = V_41 -> V_136 ;
struct V_138 * V_164 ;
unsigned int V_165 ;
int V_29 , V_166 ;
const char * * V_167 ;
int V_124 ;
struct V_168 V_169 [] = {
F_51 ( L_6 ,
V_41 -> V_170 ,
F_49 ,
F_46 ) ,
F_51 ( L_7 ,
V_41 -> V_170 ,
F_49 ,
F_46 ) ,
} ;
V_164 = V_136 -> V_149 ;
V_165 = V_136 -> V_146 ;
V_41 -> V_145 = 0 ;
V_41 -> V_150 = NULL ;
for ( V_29 = 0 ; V_29 < V_165 ; V_29 ++ ) {
for ( V_166 = 0 ; V_166 < V_41 -> V_145 ; V_166 ++ ) {
if ( strcmp ( V_164 [ V_29 ] . V_134 , V_41 -> V_150 [ V_166 ] ) == 0 )
break;
}
if ( V_166 != V_41 -> V_145 )
continue;
V_167 = F_52 ( V_41 -> V_150 ,
sizeof( char * ) * ( V_41 -> V_145 + 1 ) ,
V_171 ) ;
if ( V_167 == NULL )
continue;
V_167 [ V_41 -> V_145 ] = V_164 [ V_29 ] . V_134 ;
V_41 -> V_145 ++ ;
V_41 -> V_150 = V_167 ;
}
V_41 -> V_170 . V_172 = V_41 -> V_150 ;
V_41 -> V_170 . V_173 = V_41 -> V_145 ;
V_124 = F_53 ( V_24 , V_169 , F_22 ( V_169 ) ) ;
if ( V_124 != 0 )
F_27 ( V_24 -> V_2 , L_9 , V_124 ) ;
}
static int F_54 ( struct V_23 * V_24 ,
const char * V_134 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_22 ( V_174 ) ; V_29 ++ )
if ( strcmp ( V_134 , V_174 [ V_29 ] ) == 0 )
return V_29 ;
F_27 ( V_24 -> V_2 , L_10 , V_134 ) ;
return - V_55 ;
}
static int F_55 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_135 * V_136 = V_41 -> V_136 ;
int V_56 = F_54 ( V_24 , V_37 -> V_137 . V_134 ) ;
struct V_69 * V_70 ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
struct V_175 * V_139 ;
int V_140 , V_141 , V_142 , V_29 ;
int V_143 , V_144 ;
if ( V_56 < 0 )
return V_56 ;
if ( ! V_136 || ! V_41 -> V_176 )
return 0 ;
if ( V_42 >= V_136 -> V_177 )
return - V_55 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_70 -> V_178 = V_42 ;
V_140 = V_70 -> V_61 ;
V_141 = 0 ;
V_142 = V_148 ;
for ( V_29 = 0 ; V_29 < V_136 -> V_177 ; V_29 ++ ) {
if ( strcmp ( V_136 -> V_179 [ V_29 ] . V_134 , V_41 -> V_180 [ V_42 ] ) == 0 &&
abs ( V_136 -> V_179 [ V_29 ] . V_61 - V_140 ) < V_142 ) {
V_141 = V_29 ;
V_142 = abs ( V_136 -> V_179 [ V_29 ] . V_61 - V_140 ) ;
}
}
F_36 ( V_24 -> V_2 , L_8 ,
V_136 -> V_179 [ V_141 ] . V_134 ,
V_136 -> V_179 [ V_141 ] . V_61 , V_140 ) ;
V_139 = & V_136 -> V_179 [ V_141 ] ;
V_143 = ( V_56 == 0 ) ? V_181 : V_182 ;
V_144 = F_26 ( V_24 , V_153 ) ;
F_12 ( V_24 , V_153 , V_143 , 0 ) ;
F_47 ( & V_24 -> V_154 ) ;
F_12 ( V_24 , V_155 , V_156 , V_156 ) ;
F_8 ( V_24 , V_56 , 0 , V_139 -> V_157 ) ;
F_8 ( V_24 , V_56 , 1 , V_139 -> V_158 ) ;
F_12 ( V_24 , V_155 , V_156 , 0 ) ;
F_48 ( & V_24 -> V_154 ) ;
F_12 ( V_24 , V_153 , V_143 , V_144 ) ;
return 0 ;
}
static int F_56 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_56 = F_54 ( V_24 , V_37 -> V_137 . V_134 ) ;
struct V_69 * V_70 ;
if ( V_56 < 0 )
return V_56 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_39 -> V_43 . V_162 . V_163 [ 0 ] = V_70 -> V_178 ;
return 0 ;
}
static void F_57 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_135 * V_136 = V_41 -> V_136 ;
struct V_175 * V_164 ;
unsigned int V_165 ;
int V_29 , V_166 ;
const char * * V_167 ;
int V_124 ;
struct V_168 V_169 [] = {
F_51 ( ( char * ) V_174 [ 0 ] ,
V_41 -> V_183 ,
F_56 ,
F_55 ) ,
F_51 ( ( char * ) V_174 [ 1 ] ,
V_41 -> V_183 ,
F_56 ,
F_55 ) ,
} ;
F_58 ( F_22 ( V_169 ) != F_22 ( V_174 ) ) ;
V_164 = V_136 -> V_179 ;
V_165 = V_136 -> V_177 ;
V_41 -> V_176 = 0 ;
V_41 -> V_180 = NULL ;
for ( V_29 = 0 ; V_29 < V_165 ; V_29 ++ ) {
for ( V_166 = 0 ; V_166 < V_41 -> V_176 ; V_166 ++ ) {
if ( strcmp ( V_164 [ V_29 ] . V_134 , V_41 -> V_180 [ V_166 ] ) == 0 )
break;
}
if ( V_166 != V_41 -> V_176 )
continue;
V_167 = F_52 ( V_41 -> V_180 ,
sizeof( char * ) * ( V_41 -> V_176 + 1 ) ,
V_171 ) ;
if ( V_167 == NULL )
continue;
V_167 [ V_41 -> V_176 ] = V_164 [ V_29 ] . V_134 ;
V_41 -> V_176 ++ ;
V_41 -> V_180 = V_167 ;
}
V_41 -> V_183 . V_172 = V_41 -> V_180 ;
V_41 -> V_183 . V_173 = V_41 -> V_176 ;
V_124 = F_53 ( V_24 , V_169 , F_22 ( V_169 ) ) ;
if ( V_124 != 0 )
F_27 ( V_24 -> V_2 , L_11 , V_124 ) ;
}
static void F_59 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_135 * V_136 = V_41 -> V_136 ;
T_2 V_72 = 0 ;
if ( ! V_136 ) {
F_36 ( V_24 -> V_2 , L_12 ) ;
return;
}
if ( V_136 -> V_184 )
V_72 |= V_185 ;
if ( V_136 -> V_186 )
V_72 |= V_187 ;
F_5 ( V_24 , V_188 , V_72 ) ;
if ( V_136 -> V_146 )
F_50 ( V_24 ) ;
if ( V_136 -> V_177 )
F_57 ( V_24 ) ;
}
static T_3 F_60 ( int V_189 , void * V_190 )
{
struct V_23 * V_24 = V_190 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
unsigned int V_43 ;
int V_191 = 0 ;
int V_192 = 0 ;
V_43 = F_26 ( V_24 , V_15 ) ;
if ( ( V_43 & V_193 ) == 0 )
return V_194 ;
if ( ( V_43 & V_195 || V_43 & V_196 ) &&
V_41 -> V_197 )
V_191 |= V_198 ;
if ( ( V_43 & V_199 ) && V_41 -> V_200 )
V_192 |= V_201 ;
if ( V_41 -> V_197 == V_41 -> V_200 ) {
F_61 ( V_41 -> V_197 ,
V_191 | V_192 ,
V_202 ) ;
} else {
if ( V_41 -> V_197 )
F_61 ( V_41 -> V_197 ,
V_191 , V_198 ) ;
if ( V_41 -> V_200 )
F_61 ( V_41 -> V_200 ,
V_192 , V_201 ) ;
}
return V_203 ;
}
static int F_62 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_124 = 0 ;
int V_204 = V_205 ;
unsigned int V_206 = V_207 ;
if ( V_41 -> V_136 -> V_208 )
V_204 |= V_209 ;
if ( V_41 -> V_136 -> V_210 )
V_206 = V_41 -> V_136 -> V_210 ;
V_124 = F_5 ( V_24 , V_211 , V_206 ) ;
if ( V_124 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_124 ) ;
return V_124 ;
}
V_124 = F_5 ( V_24 , V_212 , V_204 ) ;
if ( V_124 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_124 ) ;
return V_124 ;
}
return V_124 ;
}
static int F_63 ( struct V_23 * V_24 )
{
int V_124 = 0 ;
V_124 = F_5 ( V_24 , V_212 , 0x0 ) ;
if ( V_124 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_124 ) ;
return V_124 ;
}
return V_124 ;
}
int F_64 ( struct V_23 * V_24 ,
struct V_213 * V_214 , struct V_213 * V_200 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_215 * V_216 = F_65 ( V_24 -> V_2 ) ;
int V_124 = 0 ;
V_41 -> V_197 = V_214 ;
V_41 -> V_200 = V_200 ;
if ( ! V_214 && ! V_200 )
return - V_55 ;
F_62 ( V_24 ) ;
V_124 = F_12 ( V_24 , V_217 ,
V_218 , V_218 ) ;
if ( V_124 < 0 ) {
F_27 ( V_24 -> V_2 , L_14 , V_124 ) ;
return V_124 ;
}
F_60 ( V_216 -> V_189 , V_24 ) ;
return 0 ;
}
static int F_66 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
if ( V_41 -> V_197 || V_41 -> V_200 )
F_63 ( V_24 ) ;
F_40 ( V_24 , V_130 ) ;
return 0 ;
}
static int F_67 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_215 * V_216 = F_65 ( V_24 -> V_2 ) ;
F_40 ( V_24 , V_129 ) ;
if ( V_41 -> V_197 || V_41 -> V_200 ) {
F_62 ( V_24 ) ;
F_60 ( V_216 -> V_189 , V_24 ) ;
}
return 0 ;
}
static int F_68 ( struct V_23 * V_24 )
{
int V_29 , V_124 ;
V_124 = F_5 ( V_24 , V_155 , 0 ) ;
if ( V_124 < 0 ) {
F_27 ( V_24 -> V_2 , L_15 , V_124 ) ;
return V_124 ;
}
V_124 = F_5 ( V_24 , V_219 , 0 ) ;
if ( V_124 < 0 ) {
F_27 ( V_24 -> V_2 , L_16 , V_124 ) ;
return V_124 ;
}
for ( V_29 = V_220 ; V_29 < V_7 ; V_29 ++ ) {
V_124 = F_5 ( V_24 , V_29 , F_26 ( V_24 , V_29 ) ) ;
if ( V_124 < 0 ) {
F_27 ( V_24 -> V_2 , L_17 , V_124 ) ;
return V_124 ;
}
}
return V_124 ;
}
static int F_69 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
struct V_215 * V_216 ;
int V_124 = 0 ;
V_41 -> V_98 = F_70 ( V_24 -> V_2 , L_18 ) ;
if ( F_71 ( V_41 -> V_98 ) == - V_221 )
return - V_221 ;
F_68 ( V_24 ) ;
V_216 = F_65 ( V_24 -> V_2 ) ;
V_41 -> V_78 = ( unsigned ) - 1 ;
V_41 -> V_145 = 0 ;
V_41 -> V_176 = 0 ;
V_70 = & V_41 -> V_25 [ 0 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_101 = ( unsigned ) - 1 ;
V_70 -> V_147 = 0 ;
V_70 -> V_178 = 0 ;
V_70 = & V_41 -> V_25 [ 1 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_101 = ( unsigned ) - 1 ;
V_70 -> V_147 = 0 ;
V_70 -> V_178 = 0 ;
V_70 = & V_41 -> V_25 [ 2 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_101 = ( unsigned ) - 1 ;
V_70 -> V_147 = 0 ;
V_70 -> V_178 = 0 ;
V_41 -> V_58 = 0 ;
V_41 -> V_44 = 0 ;
V_41 -> V_48 = 0 ;
if ( V_216 -> V_189 ) {
V_124 = F_72 ( V_216 -> V_189 , NULL ,
F_60 ,
V_222 | V_223 ,
L_19 , V_24 ) ;
if ( V_124 ) {
F_27 ( V_24 -> V_2 , L_20 , V_124 ) ;
goto V_224;
}
}
V_124 = F_26 ( V_24 , V_225 ) ;
if ( V_124 < 0 ) {
F_27 ( V_24 -> V_2 , L_21 ,
V_124 ) ;
goto V_226;
}
F_73 ( V_24 -> V_2 , L_22 , V_124 - 0x40 + 'A' ) ;
F_5 ( V_24 , V_219 , V_227 ) ;
F_40 ( V_24 , V_129 ) ;
F_5 ( V_24 , V_228 ,
V_229 | V_230 ) ;
F_5 ( V_24 , V_231 ,
V_232 | V_233 ) ;
F_5 ( V_24 , V_234 , V_235 ) ;
F_5 ( V_24 , V_236 , V_237 ) ;
F_5 ( V_24 , V_238 , V_239 ) ;
F_5 ( V_24 , V_240 ,
V_241 | V_242 ) ;
F_5 ( V_24 , V_243 ,
V_244 | V_242 ) ;
F_5 ( V_24 , V_245 ,
V_246 | V_242 ) ;
F_59 ( V_24 ) ;
F_12 ( V_24 , V_219 , V_247 ,
V_247 ) ;
return 0 ;
V_226:
if ( V_216 -> V_189 )
F_74 ( V_216 -> V_189 , V_24 ) ;
V_224:
return V_124 ;
}
static int F_75 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_215 * V_216 = F_65 ( V_24 -> V_2 ) ;
F_40 ( V_24 , V_130 ) ;
if ( V_41 -> V_197 || V_41 -> V_200 )
F_63 ( V_24 ) ;
if ( V_216 -> V_189 )
F_74 ( V_216 -> V_189 , V_24 ) ;
return 0 ;
}
static int F_76 ( struct V_215 * V_248 ,
const struct V_249 * V_137 )
{
struct V_40 * V_41 ;
int V_124 ;
V_41 = F_77 ( & V_248 -> V_2 , sizeof( struct V_40 ) ,
V_171 ) ;
if ( V_41 == NULL )
return - V_250 ;
V_41 -> V_131 = F_78 ( V_248 , & V_251 ) ;
if ( F_33 ( V_41 -> V_131 ) ) {
V_124 = F_71 ( V_41 -> V_131 ) ;
F_27 ( & V_248 -> V_2 , L_23 , V_124 ) ;
return V_124 ;
}
V_41 -> V_252 = V_137 -> V_253 ;
F_79 ( V_248 , V_41 ) ;
V_41 -> V_136 = V_248 -> V_2 . V_254 ;
V_124 = F_80 ( & V_248 -> V_2 , & V_255 ,
V_256 , F_22 ( V_256 ) ) ;
return V_124 ;
}
static int F_81 ( struct V_215 * V_216 )
{
F_82 ( & V_216 -> V_2 ) ;
return 0 ;
}
