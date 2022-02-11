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
struct V_23 * V_24 = F_17 ( V_51 -> V_53 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
switch ( V_52 ) {
case V_54 :
if ( V_51 -> V_3 == V_45 ) {
F_12 ( V_24 , V_51 -> V_3 , V_46 ,
( 1 + V_41 -> V_44 ) << V_47 ) ;
} else {
F_12 ( V_24 , V_51 -> V_3 , V_46 ,
( 1 + V_41 -> V_48 ) << V_47 ) ;
}
break;
case V_55 :
F_12 ( V_24 , V_51 -> V_3 , V_46 , 0 ) ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_18 ( struct V_50 * V_51 ,
int V_52 , T_2 V_57 )
{
struct V_23 * V_24 = F_17 ( V_51 -> V_53 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
T_2 * V_58 ;
if ( F_4 ( ! ( V_57 == 1 || V_57 == 2 ) ) )
return - V_56 ;
V_58 = & V_41 -> V_59 ;
switch ( V_52 ) {
case V_54 :
* V_58 |= V_57 ;
F_12 ( V_24 , V_51 -> V_3 ,
( 1 << V_51 -> V_60 ) , ( 1 << V_51 -> V_60 ) ) ;
break;
case V_55 :
* V_58 &= ~ V_57 ;
if ( * V_58 == 0 ) {
F_12 ( V_24 , V_51 -> V_3 ,
( 1 << V_51 -> V_60 ) , 0 ) ;
}
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_19 ( struct V_50 * V_51 ,
struct V_36 * V_61 , int V_52 )
{
return F_18 ( V_51 , V_52 , 1 ) ;
}
static int F_20 ( struct V_50 * V_51 ,
struct V_36 * V_61 , int V_52 )
{
return F_18 ( V_51 , V_52 , 2 ) ;
}
static int F_21 ( struct V_50 * V_51 ,
struct V_36 * V_37 , int V_52 )
{
struct V_23 * V_24 = F_17 ( V_51 -> V_53 ) ;
switch ( V_52 ) {
case V_54 :
F_12 ( V_24 , V_51 -> V_3 ,
( 1 << ( V_51 -> V_60 + 2 ) ) , ( 1 << ( V_51 -> V_60 + 2 ) ) ) ;
break;
case V_55 :
F_12 ( V_24 , V_51 -> V_3 ,
( 1 << ( V_51 -> V_60 + 2 ) ) , 0 ) ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_22 ( int V_62 , T_2 * V_43 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_23 ( V_63 ) ; V_29 ++ ) {
if ( V_63 [ V_29 ] . V_62 >= V_62 ) {
* V_43 = V_63 [ V_29 ] . V_64 ;
return 0 ;
}
}
* V_43 = V_63 [ 0 ] . V_64 ;
return - V_56 ;
}
static int F_24 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
struct V_69 * V_25 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_70 * V_71 ;
unsigned long long V_72 ;
unsigned int V_62 ;
T_2 V_73 ;
V_71 = & V_41 -> V_25 [ 0 ] ;
V_62 = F_25 ( V_68 ) ;
switch ( F_26 ( V_68 ) ) {
case 16 :
F_12 ( V_24 , V_74 ,
V_75 , 0 ) ;
break;
case 24 :
F_12 ( V_24 , V_74 ,
V_75 , V_75 ) ;
break;
default:
return - V_56 ;
}
if ( F_22 ( V_62 , & V_73 ) )
return - V_56 ;
F_12 ( V_24 , V_76 ,
V_77 , V_73 ) ;
V_71 -> V_62 = V_62 ;
if ( F_27 ( V_24 , V_74 ) & V_78 ) {
if ( V_41 -> V_79 == 0 ) {
F_28 ( V_24 -> V_2 , L_1 ) ;
return - V_56 ;
}
V_72 = 65536ULL * ( V_62 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_62 ;
F_29 ( V_72 , ( unsigned long long int ) V_41 -> V_79 ) ;
F_5 ( V_24 , V_80 ,
( V_72 >> 8 ) & 0x7F ) ;
F_5 ( V_24 , V_81 ,
V_72 & 0xFF ) ;
}
if ( V_62 < 50000 )
F_12 ( V_24 , V_82 ,
V_83 , 0 ) ;
else
F_12 ( V_24 , V_82 ,
V_83 , V_83 ) ;
return 0 ;
}
static int F_30 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
struct V_69 * V_25 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_70 * V_71 ;
unsigned long long V_72 ;
unsigned int V_62 ;
T_2 V_73 ;
V_71 = & V_41 -> V_25 [ 1 ] ;
V_62 = F_25 ( V_68 ) ;
switch ( F_26 ( V_68 ) ) {
case 16 :
F_12 ( V_24 , V_84 ,
V_75 , 0 ) ;
break;
case 24 :
F_12 ( V_24 , V_84 ,
V_75 , V_75 ) ;
break;
default:
return - V_56 ;
}
if ( F_22 ( V_62 , & V_73 ) )
return - V_56 ;
F_12 ( V_24 , V_85 ,
V_77 , V_73 ) ;
V_71 -> V_62 = V_62 ;
if ( F_27 ( V_24 , V_84 ) & V_78 ) {
if ( V_41 -> V_79 == 0 ) {
F_28 ( V_24 -> V_2 , L_1 ) ;
return - V_56 ;
}
V_72 = 65536ULL * ( V_62 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_62 ;
F_29 ( V_72 , ( unsigned long long int ) V_41 -> V_79 ) ;
F_5 ( V_24 , V_86 ,
( V_72 >> 8 ) & 0x7F ) ;
F_5 ( V_24 , V_87 ,
V_72 & 0xFF ) ;
}
if ( V_62 < 50000 )
F_12 ( V_24 , V_88 ,
V_83 , 0 ) ;
else
F_12 ( V_24 , V_88 ,
V_83 , V_83 ) ;
return 0 ;
}
static int F_31 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
struct V_69 * V_25 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_70 * V_71 ;
unsigned long long V_72 ;
unsigned int V_62 ;
T_2 V_73 ;
V_71 = & V_41 -> V_25 [ 2 ] ;
V_62 = F_25 ( V_68 ) ;
switch ( F_26 ( V_68 ) ) {
case 16 :
F_12 ( V_24 , V_89 ,
V_75 , 0 ) ;
break;
case 24 :
F_12 ( V_24 , V_89 ,
V_75 , V_75 ) ;
break;
default:
return - V_56 ;
}
if ( F_22 ( V_62 , & V_73 ) )
return - V_56 ;
F_12 ( V_24 , V_90 ,
V_77 , V_73 ) ;
V_71 -> V_62 = V_62 ;
if ( F_27 ( V_24 , V_89 ) & V_78 ) {
if ( V_41 -> V_79 == 0 ) {
F_28 ( V_24 -> V_2 , L_1 ) ;
return - V_56 ;
}
V_72 = 65536ULL * ( V_62 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_62 ;
F_29 ( V_72 , ( unsigned long long int ) V_41 -> V_79 ) ;
F_5 ( V_24 , V_91 ,
( V_72 >> 8 ) & 0x7F ) ;
F_5 ( V_24 , V_92 ,
V_72 & 0xFF ) ;
}
if ( V_62 < 50000 )
F_12 ( V_24 , V_93 ,
V_83 , 0 ) ;
else
F_12 ( V_24 , V_93 ,
V_83 , V_83 ) ;
return 0 ;
}
static int F_32 ( struct V_69 * V_25 ,
int V_94 , unsigned int V_95 , int V_96 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
if ( V_95 == V_41 -> V_79 )
return 0 ;
if ( ! F_33 ( V_41 -> V_97 ) ) {
V_95 = F_34 ( V_41 -> V_97 , V_95 ) ;
F_35 ( V_41 -> V_97 , V_95 ) ;
}
if ( ( V_95 >= 10000000 ) && ( V_95 < 20000000 ) ) {
F_5 ( V_24 , V_98 , 0x10 ) ;
} else if ( ( V_95 >= 20000000 ) && ( V_95 < 40000000 ) ) {
F_5 ( V_24 , V_98 , 0x20 ) ;
} else if ( ( V_95 >= 40000000 ) && ( V_95 < 60000000 ) ) {
F_5 ( V_24 , V_98 , 0x30 ) ;
} else {
F_28 ( V_24 -> V_2 , L_2 ) ;
return - V_56 ;
}
F_36 ( V_25 -> V_2 , L_3 , V_94 , V_95 ) ;
V_41 -> V_79 = V_95 ;
return 0 ;
}
static int F_37 ( struct V_69 * V_99 ,
unsigned int V_100 )
{
struct V_23 * V_24 = V_99 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_70 * V_71 ;
T_2 V_73 = 0 ;
V_71 = & V_41 -> V_25 [ 0 ] ;
if ( V_100 != V_71 -> V_100 ) {
V_71 -> V_100 = V_100 ;
switch ( V_100 & V_101 ) {
case V_102 :
F_5 ( V_24 , V_80 ,
0x80 ) ;
F_5 ( V_24 , V_81 ,
0x00 ) ;
break;
case V_103 :
V_73 |= V_78 ;
break;
case V_104 :
case V_105 :
default:
F_28 ( V_24 -> V_2 , L_4 ) ;
return - V_56 ;
}
switch ( V_100 & V_106 ) {
case V_107 :
V_73 |= V_108 ;
break;
case V_109 :
break;
default:
return - V_56 ;
}
switch ( V_100 & V_110 ) {
case V_111 :
break;
case V_112 :
V_73 |= V_113 ;
break;
case V_114 :
V_73 |= V_115 ;
break;
case V_116 :
V_73 |= V_115 | V_113 ;
break;
default:
return - V_56 ;
}
F_12 ( V_24 , V_74 ,
V_78 | V_108 | V_115 |
V_113 , V_73 ) ;
F_5 ( V_24 , V_117 , V_118 ) ;
}
return 0 ;
}
static int F_38 ( struct V_69 * V_99 ,
unsigned int V_100 )
{
struct V_23 * V_24 = V_99 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_70 * V_71 ;
T_2 V_73 = 0 ;
V_71 = & V_41 -> V_25 [ 1 ] ;
if ( V_100 != V_71 -> V_100 ) {
V_71 -> V_100 = V_100 ;
switch ( V_100 & V_101 ) {
case V_102 :
F_5 ( V_24 , V_86 ,
0x80 ) ;
F_5 ( V_24 , V_87 ,
0x00 ) ;
break;
case V_103 :
V_73 |= V_78 ;
break;
case V_104 :
case V_105 :
default:
F_28 ( V_24 -> V_2 , L_4 ) ;
return - V_56 ;
}
switch ( V_100 & V_106 ) {
case V_107 :
V_73 |= V_108 ;
break;
case V_109 :
break;
default:
return - V_56 ;
}
switch ( V_100 & V_110 ) {
case V_111 :
break;
case V_112 :
V_73 |= V_113 ;
break;
case V_114 :
V_73 |= V_115 ;
break;
case V_116 :
V_73 |= V_115 | V_113 ;
break;
default:
return - V_56 ;
}
F_12 ( V_24 , V_84 ,
V_78 | V_108 | V_115 |
V_113 , V_73 ) ;
F_5 ( V_24 , V_119 ,
V_118 ) ;
}
return 0 ;
}
static int F_39 ( struct V_69 * V_99 ,
unsigned int V_100 )
{
struct V_23 * V_24 = V_99 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_70 * V_71 ;
T_2 V_73 = 0 ;
V_71 = & V_41 -> V_25 [ 2 ] ;
if ( V_100 != V_71 -> V_100 ) {
V_71 -> V_100 = V_100 ;
switch ( V_100 & V_101 ) {
case V_102 :
F_5 ( V_24 , V_91 ,
0x80 ) ;
F_5 ( V_24 , V_92 ,
0x00 ) ;
break;
case V_103 :
V_73 |= V_78 ;
break;
case V_104 :
case V_105 :
default:
F_28 ( V_24 -> V_2 , L_4 ) ;
return - V_56 ;
}
switch ( V_100 & V_106 ) {
case V_107 :
V_73 |= V_108 ;
break;
case V_109 :
break;
default:
return - V_56 ;
}
switch ( V_100 & V_110 ) {
case V_111 :
break;
case V_112 :
V_73 |= V_113 ;
break;
case V_114 :
V_73 |= V_115 ;
break;
case V_116 :
V_73 |= V_115 | V_113 ;
break;
default:
return - V_56 ;
}
F_12 ( V_24 , V_89 ,
V_78 | V_108 | V_115 |
V_113 , V_73 ) ;
F_5 ( V_24 , V_120 ,
V_118 ) ;
}
return 0 ;
}
static int F_40 ( struct V_23 * V_24 ,
enum V_121 V_122 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_123 ;
switch ( V_122 ) {
case V_124 :
break;
case V_125 :
if ( F_33 ( V_41 -> V_97 ) )
break;
if ( F_41 ( V_24 ) == V_124 )
F_42 ( V_41 -> V_97 ) ;
else
F_43 ( V_41 -> V_97 ) ;
break;
case V_126 :
if ( F_41 ( V_24 ) == V_127 ) {
V_123 = F_44 ( V_41 -> V_128 ) ;
if ( V_123 != 0 ) {
F_28 ( V_24 -> V_2 , L_5 , V_123 ) ;
return V_123 ;
}
}
F_12 ( V_24 , V_129 ,
V_130 , V_130 ) ;
break;
case V_127 :
F_12 ( V_24 , V_129 ,
V_130 , 0 ) ;
F_45 ( V_41 -> V_128 ) ;
break;
}
return 0 ;
}
static int F_46 ( const char * V_131 )
{
if ( strcmp ( V_131 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_131 , L_7 ) == 0 )
return 1 ;
return - V_56 ;
}
static int F_47 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_132 * V_133 = V_41 -> V_133 ;
int V_57 = F_46 ( V_37 -> V_134 . V_131 ) ;
struct V_70 * V_71 ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
struct V_135 * V_136 ;
int V_137 , V_138 , V_139 , V_29 ;
int V_140 , V_141 ;
if ( F_4 ( V_57 > 1 ) )
return - V_56 ;
if ( ! V_133 || ! V_41 -> V_142 )
return 0 ;
if ( V_42 >= V_133 -> V_143 )
return - V_56 ;
V_71 = & V_41 -> V_25 [ V_57 ] ;
V_71 -> V_144 = V_42 ;
V_137 = V_71 -> V_62 ;
V_138 = 0 ;
V_139 = V_145 ;
for ( V_29 = 0 ; V_29 < V_133 -> V_143 ; V_29 ++ ) {
if ( strcmp ( V_133 -> V_146 [ V_29 ] . V_131 , V_41 -> V_147 [ V_42 ] ) == 0 &&
abs ( V_133 -> V_146 [ V_29 ] . V_62 - V_137 ) < V_139 ) {
V_138 = V_29 ;
V_139 = abs ( V_133 -> V_146 [ V_29 ] . V_62 - V_137 ) ;
}
}
F_36 ( V_24 -> V_2 , L_8 ,
V_133 -> V_146 [ V_138 ] . V_131 ,
V_133 -> V_146 [ V_138 ] . V_62 , V_137 ) ;
V_136 = & V_133 -> V_146 [ V_138 ] ;
V_140 = ( V_57 == 0 ) ? V_148 : V_149 ;
V_141 = F_27 ( V_24 , V_150 ) ;
F_12 ( V_24 , V_150 , V_140 , 0 ) ;
F_48 ( & V_41 -> V_151 ) ;
F_12 ( V_24 , V_152 , V_153 , V_153 ) ;
F_3 ( V_24 , V_57 , 0 , V_136 -> V_154 ) ;
F_3 ( V_24 , V_57 , 1 , V_136 -> V_155 ) ;
F_3 ( V_24 , V_57 , 2 , V_136 -> V_156 ) ;
F_3 ( V_24 , V_57 , 3 , V_136 -> V_157 ) ;
F_3 ( V_24 , V_57 , 4 , V_136 -> V_158 ) ;
F_12 ( V_24 , V_152 , V_153 , 0 ) ;
F_49 ( & V_41 -> V_151 ) ;
F_12 ( V_24 , V_150 , V_140 , V_141 ) ;
return 0 ;
}
static int F_50 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_57 = F_46 ( V_37 -> V_134 . V_131 ) ;
struct V_70 * V_71 ;
V_71 = & V_41 -> V_25 [ V_57 ] ;
V_39 -> V_43 . V_159 . V_160 [ 0 ] = V_71 -> V_144 ;
return 0 ;
}
static void F_51 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_132 * V_133 = V_41 -> V_133 ;
struct V_135 * V_161 ;
unsigned int V_162 ;
int V_29 , V_163 ;
const char * * V_164 ;
int V_123 ;
struct V_165 V_166 [] = {
F_52 ( L_6 ,
V_41 -> V_167 ,
F_50 ,
F_47 ) ,
F_52 ( L_7 ,
V_41 -> V_167 ,
F_50 ,
F_47 ) ,
} ;
V_161 = V_133 -> V_146 ;
V_162 = V_133 -> V_143 ;
V_41 -> V_142 = 0 ;
V_41 -> V_147 = NULL ;
for ( V_29 = 0 ; V_29 < V_162 ; V_29 ++ ) {
for ( V_163 = 0 ; V_163 < V_41 -> V_142 ; V_163 ++ ) {
if ( strcmp ( V_161 [ V_29 ] . V_131 , V_41 -> V_147 [ V_163 ] ) == 0 )
break;
}
if ( V_163 != V_41 -> V_142 )
continue;
V_164 = F_53 ( V_41 -> V_147 ,
sizeof( char * ) * ( V_41 -> V_142 + 1 ) ,
V_168 ) ;
if ( V_164 == NULL )
continue;
V_164 [ V_41 -> V_142 ] = V_161 [ V_29 ] . V_131 ;
V_41 -> V_142 ++ ;
V_41 -> V_147 = V_164 ;
}
V_41 -> V_167 . V_169 = V_41 -> V_147 ;
V_41 -> V_167 . V_170 = V_41 -> V_142 ;
V_123 = F_54 ( V_24 , V_166 , F_23 ( V_166 ) ) ;
if ( V_123 != 0 )
F_28 ( V_24 -> V_2 , L_9 , V_123 ) ;
}
static int F_55 ( struct V_23 * V_24 ,
const char * V_131 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_23 ( V_171 ) ; V_29 ++ )
if ( strcmp ( V_131 , V_171 [ V_29 ] ) == 0 )
return V_29 ;
F_28 ( V_24 -> V_2 , L_10 , V_131 ) ;
return - V_56 ;
}
static int F_56 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_132 * V_133 = V_41 -> V_133 ;
int V_57 = F_55 ( V_24 , V_37 -> V_134 . V_131 ) ;
struct V_70 * V_71 ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
struct V_172 * V_136 ;
int V_137 , V_138 , V_139 , V_29 ;
int V_140 , V_141 ;
if ( V_57 < 0 )
return V_57 ;
if ( ! V_133 || ! V_41 -> V_173 )
return 0 ;
if ( V_42 >= V_133 -> V_174 )
return - V_56 ;
V_71 = & V_41 -> V_25 [ V_57 ] ;
V_71 -> V_175 = V_42 ;
V_137 = V_71 -> V_62 ;
V_138 = 0 ;
V_139 = V_145 ;
for ( V_29 = 0 ; V_29 < V_133 -> V_174 ; V_29 ++ ) {
if ( strcmp ( V_133 -> V_176 [ V_29 ] . V_131 , V_41 -> V_177 [ V_42 ] ) == 0 &&
abs ( V_133 -> V_176 [ V_29 ] . V_62 - V_137 ) < V_139 ) {
V_138 = V_29 ;
V_139 = abs ( V_133 -> V_176 [ V_29 ] . V_62 - V_137 ) ;
}
}
F_36 ( V_24 -> V_2 , L_8 ,
V_133 -> V_176 [ V_138 ] . V_131 ,
V_133 -> V_176 [ V_138 ] . V_62 , V_137 ) ;
V_136 = & V_133 -> V_176 [ V_138 ] ;
V_140 = ( V_57 == 0 ) ? V_178 : V_179 ;
V_141 = F_27 ( V_24 , V_150 ) ;
F_12 ( V_24 , V_150 , V_140 , 0 ) ;
F_48 ( & V_41 -> V_151 ) ;
F_12 ( V_24 , V_152 , V_153 , V_153 ) ;
F_8 ( V_24 , V_57 , 0 , V_136 -> V_154 ) ;
F_8 ( V_24 , V_57 , 1 , V_136 -> V_155 ) ;
F_12 ( V_24 , V_152 , V_153 , 0 ) ;
F_49 ( & V_41 -> V_151 ) ;
F_12 ( V_24 , V_150 , V_140 , V_141 ) ;
return 0 ;
}
static int F_57 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_57 = F_55 ( V_24 , V_37 -> V_134 . V_131 ) ;
struct V_70 * V_71 ;
if ( V_57 < 0 )
return V_57 ;
V_71 = & V_41 -> V_25 [ V_57 ] ;
V_39 -> V_43 . V_159 . V_160 [ 0 ] = V_71 -> V_175 ;
return 0 ;
}
static void F_58 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_132 * V_133 = V_41 -> V_133 ;
struct V_172 * V_161 ;
unsigned int V_162 ;
int V_29 , V_163 ;
const char * * V_164 ;
int V_123 ;
struct V_165 V_166 [] = {
F_52 ( ( char * ) V_171 [ 0 ] ,
V_41 -> V_180 ,
F_57 ,
F_56 ) ,
F_52 ( ( char * ) V_171 [ 1 ] ,
V_41 -> V_180 ,
F_57 ,
F_56 ) ,
} ;
F_59 ( F_23 ( V_166 ) != F_23 ( V_171 ) ) ;
V_161 = V_133 -> V_176 ;
V_162 = V_133 -> V_174 ;
V_41 -> V_173 = 0 ;
V_41 -> V_177 = NULL ;
for ( V_29 = 0 ; V_29 < V_162 ; V_29 ++ ) {
for ( V_163 = 0 ; V_163 < V_41 -> V_173 ; V_163 ++ ) {
if ( strcmp ( V_161 [ V_29 ] . V_131 , V_41 -> V_177 [ V_163 ] ) == 0 )
break;
}
if ( V_163 != V_41 -> V_173 )
continue;
V_164 = F_53 ( V_41 -> V_177 ,
sizeof( char * ) * ( V_41 -> V_173 + 1 ) ,
V_168 ) ;
if ( V_164 == NULL )
continue;
V_164 [ V_41 -> V_173 ] = V_161 [ V_29 ] . V_131 ;
V_41 -> V_173 ++ ;
V_41 -> V_177 = V_164 ;
}
V_41 -> V_180 . V_169 = V_41 -> V_177 ;
V_41 -> V_180 . V_170 = V_41 -> V_173 ;
V_123 = F_54 ( V_24 , V_166 , F_23 ( V_166 ) ) ;
if ( V_123 != 0 )
F_28 ( V_24 -> V_2 , L_11 , V_123 ) ;
}
static void F_60 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_132 * V_133 = V_41 -> V_133 ;
T_2 V_73 = 0 ;
if ( ! V_133 ) {
F_36 ( V_24 -> V_2 , L_12 ) ;
return;
}
if ( V_133 -> V_181 )
V_73 |= V_182 ;
if ( V_133 -> V_183 )
V_73 |= V_184 ;
F_5 ( V_24 , V_185 , V_73 ) ;
if ( V_133 -> V_143 )
F_51 ( V_24 ) ;
if ( V_133 -> V_174 )
F_58 ( V_24 ) ;
}
static T_3 F_61 ( int V_186 , void * V_187 )
{
struct V_23 * V_24 = V_187 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
unsigned int V_43 ;
int V_188 = 0 ;
int V_189 = 0 ;
V_43 = F_27 ( V_24 , V_15 ) ;
if ( ( V_43 & V_190 ) == 0 )
return V_191 ;
if ( ( V_43 & V_192 || V_43 & V_193 ) &&
V_41 -> V_194 )
V_188 |= V_195 ;
if ( ( V_43 & V_196 ) && V_41 -> V_197 )
V_189 |= V_198 ;
if ( V_41 -> V_194 == V_41 -> V_197 ) {
F_62 ( V_41 -> V_194 ,
V_188 | V_189 ,
V_199 ) ;
} else {
if ( V_41 -> V_194 )
F_62 ( V_41 -> V_194 ,
V_188 , V_195 ) ;
if ( V_41 -> V_197 )
F_62 ( V_41 -> V_197 ,
V_189 , V_198 ) ;
}
return V_200 ;
}
static int F_63 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_123 = 0 ;
int V_201 = V_202 ;
unsigned int V_203 = V_204 ;
if ( V_41 -> V_133 -> V_205 )
V_201 |= V_206 ;
if ( V_41 -> V_133 -> V_207 )
V_203 = V_41 -> V_133 -> V_207 ;
V_123 = F_5 ( V_24 , V_208 , V_203 ) ;
if ( V_123 < 0 ) {
F_28 ( V_24 -> V_2 , L_13 , V_123 ) ;
return V_123 ;
}
V_123 = F_5 ( V_24 , V_209 , V_201 ) ;
if ( V_123 < 0 ) {
F_28 ( V_24 -> V_2 , L_13 , V_123 ) ;
return V_123 ;
}
return V_123 ;
}
static int F_64 ( struct V_23 * V_24 )
{
int V_123 = 0 ;
V_123 = F_5 ( V_24 , V_209 , 0x0 ) ;
if ( V_123 < 0 ) {
F_28 ( V_24 -> V_2 , L_13 , V_123 ) ;
return V_123 ;
}
return V_123 ;
}
int F_65 ( struct V_23 * V_24 ,
struct V_210 * V_211 , struct V_210 * V_197 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_212 * V_213 = F_66 ( V_24 -> V_2 ) ;
int V_123 = 0 ;
V_41 -> V_194 = V_211 ;
V_41 -> V_197 = V_197 ;
if ( ! V_211 && ! V_197 )
return - V_56 ;
F_63 ( V_24 ) ;
V_123 = F_12 ( V_24 , V_214 ,
V_215 , V_215 ) ;
if ( V_123 < 0 ) {
F_28 ( V_24 -> V_2 , L_14 , V_123 ) ;
return V_123 ;
}
F_61 ( V_213 -> V_186 , V_24 ) ;
return 0 ;
}
static int F_67 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
if ( V_41 -> V_194 || V_41 -> V_197 )
F_64 ( V_24 ) ;
F_68 ( V_24 , V_127 ) ;
return 0 ;
}
static int F_69 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_212 * V_213 = F_66 ( V_24 -> V_2 ) ;
F_68 ( V_24 , V_126 ) ;
if ( V_41 -> V_194 || V_41 -> V_197 ) {
F_63 ( V_24 ) ;
F_61 ( V_213 -> V_186 , V_24 ) ;
}
return 0 ;
}
static int F_70 ( struct V_23 * V_24 )
{
int V_29 , V_123 ;
V_123 = F_5 ( V_24 , V_152 , 0 ) ;
if ( V_123 < 0 ) {
F_28 ( V_24 -> V_2 , L_15 , V_123 ) ;
return V_123 ;
}
V_123 = F_5 ( V_24 , V_216 , 0 ) ;
if ( V_123 < 0 ) {
F_28 ( V_24 -> V_2 , L_16 , V_123 ) ;
return V_123 ;
}
for ( V_29 = V_217 ; V_29 < V_7 ; V_29 ++ ) {
V_123 = F_5 ( V_24 , V_29 , F_27 ( V_24 , V_29 ) ) ;
if ( V_123 < 0 ) {
F_28 ( V_24 -> V_2 , L_17 , V_123 ) ;
return V_123 ;
}
}
return V_123 ;
}
static int F_71 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_70 * V_71 ;
struct V_212 * V_213 ;
int V_123 = 0 ;
V_41 -> V_97 = F_72 ( V_24 -> V_2 , L_18 ) ;
if ( F_73 ( V_41 -> V_97 ) == - V_218 )
return - V_218 ;
F_70 ( V_24 ) ;
V_213 = F_66 ( V_24 -> V_2 ) ;
V_41 -> V_79 = ( unsigned ) - 1 ;
V_41 -> V_142 = 0 ;
V_41 -> V_173 = 0 ;
V_71 = & V_41 -> V_25 [ 0 ] ;
V_71 -> V_62 = ( unsigned ) - 1 ;
V_71 -> V_100 = ( unsigned ) - 1 ;
V_71 -> V_144 = 0 ;
V_71 -> V_175 = 0 ;
V_71 = & V_41 -> V_25 [ 1 ] ;
V_71 -> V_62 = ( unsigned ) - 1 ;
V_71 -> V_100 = ( unsigned ) - 1 ;
V_71 -> V_144 = 0 ;
V_71 -> V_175 = 0 ;
V_71 = & V_41 -> V_25 [ 2 ] ;
V_71 -> V_62 = ( unsigned ) - 1 ;
V_71 -> V_100 = ( unsigned ) - 1 ;
V_71 -> V_144 = 0 ;
V_71 -> V_175 = 0 ;
V_41 -> V_59 = 0 ;
V_41 -> V_44 = 0 ;
V_41 -> V_48 = 0 ;
if ( V_213 -> V_186 ) {
V_123 = F_74 ( V_213 -> V_186 , NULL ,
F_61 ,
V_219 | V_220 |
V_221 , L_19 , V_24 ) ;
if ( V_123 ) {
F_28 ( V_24 -> V_2 , L_20 , V_123 ) ;
goto V_222;
}
}
V_123 = F_27 ( V_24 , V_223 ) ;
if ( V_123 < 0 ) {
F_28 ( V_24 -> V_2 , L_21 ,
V_123 ) ;
goto V_224;
}
F_75 ( V_24 -> V_2 , L_22 , V_123 - 0x40 + 'A' ) ;
F_5 ( V_24 , V_216 , V_225 ) ;
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
F_60 ( V_24 ) ;
F_12 ( V_24 , V_216 , V_245 ,
V_245 ) ;
return 0 ;
V_224:
if ( V_213 -> V_186 )
F_76 ( V_213 -> V_186 , V_24 ) ;
V_222:
return V_123 ;
}
static int F_77 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_212 * V_213 = F_66 ( V_24 -> V_2 ) ;
if ( V_41 -> V_194 || V_41 -> V_197 )
F_64 ( V_24 ) ;
if ( V_213 -> V_186 )
F_76 ( V_213 -> V_186 , V_24 ) ;
return 0 ;
}
static int F_78 ( struct V_212 * V_246 ,
const struct V_247 * V_134 )
{
struct V_40 * V_41 ;
int V_123 ;
V_41 = F_79 ( & V_246 -> V_2 , sizeof( struct V_40 ) ,
V_168 ) ;
if ( V_41 == NULL )
return - V_248 ;
F_80 ( & V_41 -> V_151 ) ;
V_41 -> V_128 = F_81 ( V_246 , & V_249 ) ;
if ( F_33 ( V_41 -> V_128 ) ) {
V_123 = F_73 ( V_41 -> V_128 ) ;
F_28 ( & V_246 -> V_2 , L_23 , V_123 ) ;
return V_123 ;
}
V_41 -> V_250 = V_134 -> V_251 ;
F_82 ( V_246 , V_41 ) ;
V_41 -> V_133 = V_246 -> V_2 . V_252 ;
V_123 = F_83 ( & V_246 -> V_2 , & V_253 ,
V_254 , F_23 ( V_254 ) ) ;
return V_123 ;
}
static int F_84 ( struct V_212 * V_213 )
{
F_85 ( & V_213 -> V_2 ) ;
return 0 ;
}
