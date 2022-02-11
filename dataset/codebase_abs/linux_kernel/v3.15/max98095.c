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
if ( ( V_96 >= 10000000 ) && ( V_96 < 20000000 ) ) {
F_5 ( V_24 , V_98 , 0x10 ) ;
} else if ( ( V_96 >= 20000000 ) && ( V_96 < 40000000 ) ) {
F_5 ( V_24 , V_98 , 0x20 ) ;
} else if ( ( V_96 >= 40000000 ) && ( V_96 < 60000000 ) ) {
F_5 ( V_24 , V_98 , 0x30 ) ;
} else {
F_27 ( V_24 -> V_2 , L_2 ) ;
return - V_55 ;
}
F_33 ( V_25 -> V_2 , L_3 , V_95 , V_96 ) ;
V_41 -> V_78 = V_96 ;
return 0 ;
}
static int F_34 ( struct V_68 * V_99 ,
unsigned int V_100 )
{
struct V_23 * V_24 = V_99 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 0 ] ;
if ( V_100 != V_70 -> V_100 ) {
V_70 -> V_100 = V_100 ;
switch ( V_100 & V_101 ) {
case V_102 :
F_5 ( V_24 , V_79 ,
0x80 ) ;
F_5 ( V_24 , V_80 ,
0x00 ) ;
break;
case V_103 :
V_72 |= V_77 ;
break;
case V_104 :
case V_105 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_100 & V_106 ) {
case V_107 :
V_72 |= V_108 ;
break;
case V_109 :
break;
default:
return - V_55 ;
}
switch ( V_100 & V_110 ) {
case V_111 :
break;
case V_112 :
V_72 |= V_113 ;
break;
case V_114 :
V_72 |= V_115 ;
break;
case V_116 :
V_72 |= V_115 | V_113 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_73 ,
V_77 | V_108 | V_115 |
V_113 , V_72 ) ;
F_5 ( V_24 , V_117 , V_118 ) ;
}
return 0 ;
}
static int F_35 ( struct V_68 * V_99 ,
unsigned int V_100 )
{
struct V_23 * V_24 = V_99 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 1 ] ;
if ( V_100 != V_70 -> V_100 ) {
V_70 -> V_100 = V_100 ;
switch ( V_100 & V_101 ) {
case V_102 :
F_5 ( V_24 , V_87 ,
0x80 ) ;
F_5 ( V_24 , V_88 ,
0x00 ) ;
break;
case V_103 :
V_72 |= V_77 ;
break;
case V_104 :
case V_105 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_100 & V_106 ) {
case V_107 :
V_72 |= V_108 ;
break;
case V_109 :
break;
default:
return - V_55 ;
}
switch ( V_100 & V_110 ) {
case V_111 :
break;
case V_112 :
V_72 |= V_113 ;
break;
case V_114 :
V_72 |= V_115 ;
break;
case V_116 :
V_72 |= V_115 | V_113 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_84 ,
V_77 | V_108 | V_115 |
V_113 , V_72 ) ;
F_5 ( V_24 , V_119 ,
V_118 ) ;
}
return 0 ;
}
static int F_36 ( struct V_68 * V_99 ,
unsigned int V_100 )
{
struct V_23 * V_24 = V_99 -> V_24 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
T_2 V_72 = 0 ;
V_70 = & V_41 -> V_25 [ 2 ] ;
if ( V_100 != V_70 -> V_100 ) {
V_70 -> V_100 = V_100 ;
switch ( V_100 & V_101 ) {
case V_102 :
F_5 ( V_24 , V_92 ,
0x80 ) ;
F_5 ( V_24 , V_93 ,
0x00 ) ;
break;
case V_103 :
V_72 |= V_77 ;
break;
case V_104 :
case V_105 :
default:
F_27 ( V_24 -> V_2 , L_4 ) ;
return - V_55 ;
}
switch ( V_100 & V_106 ) {
case V_107 :
V_72 |= V_108 ;
break;
case V_109 :
break;
default:
return - V_55 ;
}
switch ( V_100 & V_110 ) {
case V_111 :
break;
case V_112 :
V_72 |= V_113 ;
break;
case V_114 :
V_72 |= V_115 ;
break;
case V_116 :
V_72 |= V_115 | V_113 ;
break;
default:
return - V_55 ;
}
F_12 ( V_24 , V_90 ,
V_77 | V_108 | V_115 |
V_113 , V_72 ) ;
F_5 ( V_24 , V_120 ,
V_118 ) ;
}
return 0 ;
}
static int F_37 ( struct V_23 * V_24 ,
enum V_121 V_122 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_123 ;
switch ( V_122 ) {
case V_124 :
break;
case V_125 :
break;
case V_126 :
if ( V_24 -> V_127 . V_128 == V_129 ) {
V_123 = F_38 ( V_41 -> V_130 ) ;
if ( V_123 != 0 ) {
F_27 ( V_24 -> V_2 , L_5 , V_123 ) ;
return V_123 ;
}
}
F_12 ( V_24 , V_131 ,
V_132 , V_132 ) ;
break;
case V_129 :
F_12 ( V_24 , V_131 ,
V_132 , 0 ) ;
F_39 ( V_41 -> V_130 ) ;
break;
}
V_24 -> V_127 . V_128 = V_122 ;
return 0 ;
}
static int F_40 ( const char * V_133 )
{
if ( strcmp ( V_133 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_133 , L_7 ) == 0 )
return 1 ;
return - V_55 ;
}
static int F_41 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_134 * V_135 = V_41 -> V_135 ;
int V_56 = F_40 ( V_37 -> V_136 . V_133 ) ;
struct V_69 * V_70 ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
struct V_137 * V_138 ;
int V_139 , V_140 , V_141 , V_29 ;
int V_142 , V_143 ;
if ( F_4 ( V_56 > 1 ) )
return - V_55 ;
if ( ! V_135 || ! V_41 -> V_144 )
return 0 ;
if ( V_42 >= V_135 -> V_145 )
return - V_55 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_70 -> V_146 = V_42 ;
V_139 = V_70 -> V_61 ;
V_140 = 0 ;
V_141 = V_147 ;
for ( V_29 = 0 ; V_29 < V_135 -> V_145 ; V_29 ++ ) {
if ( strcmp ( V_135 -> V_148 [ V_29 ] . V_133 , V_41 -> V_149 [ V_42 ] ) == 0 &&
abs ( V_135 -> V_148 [ V_29 ] . V_61 - V_139 ) < V_141 ) {
V_140 = V_29 ;
V_141 = abs ( V_135 -> V_148 [ V_29 ] . V_61 - V_139 ) ;
}
}
F_33 ( V_24 -> V_2 , L_8 ,
V_135 -> V_148 [ V_140 ] . V_133 ,
V_135 -> V_148 [ V_140 ] . V_61 , V_139 ) ;
V_138 = & V_135 -> V_148 [ V_140 ] ;
V_142 = ( V_56 == 0 ) ? V_150 : V_151 ;
V_143 = F_26 ( V_24 , V_152 ) ;
F_12 ( V_24 , V_152 , V_142 , 0 ) ;
F_42 ( & V_24 -> V_153 ) ;
F_12 ( V_24 , V_154 , V_155 , V_155 ) ;
F_3 ( V_24 , V_56 , 0 , V_138 -> V_156 ) ;
F_3 ( V_24 , V_56 , 1 , V_138 -> V_157 ) ;
F_3 ( V_24 , V_56 , 2 , V_138 -> V_158 ) ;
F_3 ( V_24 , V_56 , 3 , V_138 -> V_159 ) ;
F_3 ( V_24 , V_56 , 4 , V_138 -> V_160 ) ;
F_12 ( V_24 , V_154 , V_155 , 0 ) ;
F_43 ( & V_24 -> V_153 ) ;
F_12 ( V_24 , V_152 , V_142 , V_143 ) ;
return 0 ;
}
static int F_44 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_56 = F_40 ( V_37 -> V_136 . V_133 ) ;
struct V_69 * V_70 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_39 -> V_43 . V_161 . V_162 [ 0 ] = V_70 -> V_146 ;
return 0 ;
}
static void F_45 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_134 * V_135 = V_41 -> V_135 ;
struct V_137 * V_163 ;
unsigned int V_164 ;
int V_29 , V_165 ;
const char * * V_166 ;
int V_123 ;
struct V_167 V_168 [] = {
F_46 ( L_6 ,
V_41 -> V_169 ,
F_44 ,
F_41 ) ,
F_46 ( L_7 ,
V_41 -> V_169 ,
F_44 ,
F_41 ) ,
} ;
V_163 = V_135 -> V_148 ;
V_164 = V_135 -> V_145 ;
V_41 -> V_144 = 0 ;
V_41 -> V_149 = NULL ;
for ( V_29 = 0 ; V_29 < V_164 ; V_29 ++ ) {
for ( V_165 = 0 ; V_165 < V_41 -> V_144 ; V_165 ++ ) {
if ( strcmp ( V_163 [ V_29 ] . V_133 , V_41 -> V_149 [ V_165 ] ) == 0 )
break;
}
if ( V_165 != V_41 -> V_144 )
continue;
V_166 = F_47 ( V_41 -> V_149 ,
sizeof( char * ) * ( V_41 -> V_144 + 1 ) ,
V_170 ) ;
if ( V_166 == NULL )
continue;
V_166 [ V_41 -> V_144 ] = V_163 [ V_29 ] . V_133 ;
V_41 -> V_144 ++ ;
V_41 -> V_149 = V_166 ;
}
V_41 -> V_169 . V_171 = V_41 -> V_149 ;
V_41 -> V_169 . V_172 = V_41 -> V_144 ;
V_123 = F_48 ( V_24 , V_168 , F_22 ( V_168 ) ) ;
if ( V_123 != 0 )
F_27 ( V_24 -> V_2 , L_9 , V_123 ) ;
}
static int F_49 ( struct V_23 * V_24 ,
const char * V_133 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_22 ( V_173 ) ; V_29 ++ )
if ( strcmp ( V_133 , V_173 [ V_29 ] ) == 0 )
return V_29 ;
F_27 ( V_24 -> V_2 , L_10 , V_133 ) ;
return - V_55 ;
}
static int F_50 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_134 * V_135 = V_41 -> V_135 ;
int V_56 = F_49 ( V_24 , V_37 -> V_136 . V_133 ) ;
struct V_69 * V_70 ;
unsigned int V_42 = V_39 -> V_43 . integer . V_43 [ 0 ] ;
struct V_174 * V_138 ;
int V_139 , V_140 , V_141 , V_29 ;
int V_142 , V_143 ;
if ( V_56 < 0 )
return V_56 ;
if ( ! V_135 || ! V_41 -> V_175 )
return 0 ;
if ( V_42 >= V_135 -> V_176 )
return - V_55 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_70 -> V_177 = V_42 ;
V_139 = V_70 -> V_61 ;
V_140 = 0 ;
V_141 = V_147 ;
for ( V_29 = 0 ; V_29 < V_135 -> V_176 ; V_29 ++ ) {
if ( strcmp ( V_135 -> V_178 [ V_29 ] . V_133 , V_41 -> V_179 [ V_42 ] ) == 0 &&
abs ( V_135 -> V_178 [ V_29 ] . V_61 - V_139 ) < V_141 ) {
V_140 = V_29 ;
V_141 = abs ( V_135 -> V_178 [ V_29 ] . V_61 - V_139 ) ;
}
}
F_33 ( V_24 -> V_2 , L_8 ,
V_135 -> V_178 [ V_140 ] . V_133 ,
V_135 -> V_178 [ V_140 ] . V_61 , V_139 ) ;
V_138 = & V_135 -> V_178 [ V_140 ] ;
V_142 = ( V_56 == 0 ) ? V_180 : V_181 ;
V_143 = F_26 ( V_24 , V_152 ) ;
F_12 ( V_24 , V_152 , V_142 , 0 ) ;
F_42 ( & V_24 -> V_153 ) ;
F_12 ( V_24 , V_154 , V_155 , V_155 ) ;
F_8 ( V_24 , V_56 , 0 , V_138 -> V_156 ) ;
F_8 ( V_24 , V_56 , 1 , V_138 -> V_157 ) ;
F_12 ( V_24 , V_154 , V_155 , 0 ) ;
F_43 ( & V_24 -> V_153 ) ;
F_12 ( V_24 , V_152 , V_142 , V_143 ) ;
return 0 ;
}
static int F_51 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_23 * V_24 = F_10 ( V_37 ) ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_56 = F_49 ( V_24 , V_37 -> V_136 . V_133 ) ;
struct V_69 * V_70 ;
if ( V_56 < 0 )
return V_56 ;
V_70 = & V_41 -> V_25 [ V_56 ] ;
V_39 -> V_43 . V_161 . V_162 [ 0 ] = V_70 -> V_177 ;
return 0 ;
}
static void F_52 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_134 * V_135 = V_41 -> V_135 ;
struct V_174 * V_163 ;
unsigned int V_164 ;
int V_29 , V_165 ;
const char * * V_166 ;
int V_123 ;
struct V_167 V_168 [] = {
F_46 ( ( char * ) V_173 [ 0 ] ,
V_41 -> V_182 ,
F_51 ,
F_50 ) ,
F_46 ( ( char * ) V_173 [ 1 ] ,
V_41 -> V_182 ,
F_51 ,
F_50 ) ,
} ;
F_53 ( F_22 ( V_168 ) != F_22 ( V_173 ) ) ;
V_163 = V_135 -> V_178 ;
V_164 = V_135 -> V_176 ;
V_41 -> V_175 = 0 ;
V_41 -> V_179 = NULL ;
for ( V_29 = 0 ; V_29 < V_164 ; V_29 ++ ) {
for ( V_165 = 0 ; V_165 < V_41 -> V_175 ; V_165 ++ ) {
if ( strcmp ( V_163 [ V_29 ] . V_133 , V_41 -> V_179 [ V_165 ] ) == 0 )
break;
}
if ( V_165 != V_41 -> V_175 )
continue;
V_166 = F_47 ( V_41 -> V_179 ,
sizeof( char * ) * ( V_41 -> V_175 + 1 ) ,
V_170 ) ;
if ( V_166 == NULL )
continue;
V_166 [ V_41 -> V_175 ] = V_163 [ V_29 ] . V_133 ;
V_41 -> V_175 ++ ;
V_41 -> V_179 = V_166 ;
}
V_41 -> V_182 . V_171 = V_41 -> V_179 ;
V_41 -> V_182 . V_172 = V_41 -> V_175 ;
V_123 = F_48 ( V_24 , V_168 , F_22 ( V_168 ) ) ;
if ( V_123 != 0 )
F_27 ( V_24 -> V_2 , L_11 , V_123 ) ;
}
static void F_54 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_134 * V_135 = V_41 -> V_135 ;
T_2 V_72 = 0 ;
if ( ! V_135 ) {
F_33 ( V_24 -> V_2 , L_12 ) ;
return;
}
if ( V_135 -> V_183 )
V_72 |= V_184 ;
if ( V_135 -> V_185 )
V_72 |= V_186 ;
F_5 ( V_24 , V_187 , V_72 ) ;
if ( V_135 -> V_145 )
F_45 ( V_24 ) ;
if ( V_135 -> V_176 )
F_52 ( V_24 ) ;
}
static T_3 F_55 ( int V_188 , void * V_189 )
{
struct V_23 * V_24 = V_189 ;
struct V_40 * V_41 = F_11 ( V_24 ) ;
unsigned int V_43 ;
int V_190 = 0 ;
int V_191 = 0 ;
V_43 = F_26 ( V_24 , V_15 ) ;
if ( ( V_43 & V_192 ) == 0 )
return V_193 ;
if ( ( V_43 & V_194 || V_43 & V_195 ) &&
V_41 -> V_196 )
V_190 |= V_197 ;
if ( ( V_43 & V_198 ) && V_41 -> V_199 )
V_191 |= V_200 ;
if ( V_41 -> V_196 == V_41 -> V_199 ) {
F_56 ( V_41 -> V_196 ,
V_190 | V_191 ,
V_201 ) ;
} else {
if ( V_41 -> V_196 )
F_56 ( V_41 -> V_196 ,
V_190 , V_197 ) ;
if ( V_41 -> V_199 )
F_56 ( V_41 -> V_199 ,
V_191 , V_200 ) ;
}
return V_202 ;
}
static int F_57 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
int V_123 = 0 ;
int V_203 = V_204 ;
unsigned int V_205 = V_206 ;
if ( V_41 -> V_135 -> V_207 )
V_203 |= V_208 ;
if ( V_41 -> V_135 -> V_209 )
V_205 = V_41 -> V_135 -> V_209 ;
V_123 = F_5 ( V_24 , V_210 , V_205 ) ;
if ( V_123 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_123 ) ;
return V_123 ;
}
V_123 = F_5 ( V_24 , V_211 , V_203 ) ;
if ( V_123 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_123 ) ;
return V_123 ;
}
return V_123 ;
}
static int F_58 ( struct V_23 * V_24 )
{
int V_123 = 0 ;
V_123 = F_5 ( V_24 , V_211 , 0x0 ) ;
if ( V_123 < 0 ) {
F_27 ( V_24 -> V_2 , L_13 , V_123 ) ;
return V_123 ;
}
return V_123 ;
}
int F_59 ( struct V_23 * V_24 ,
struct V_212 * V_213 , struct V_212 * V_199 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_214 * V_215 = F_60 ( V_24 -> V_2 ) ;
int V_123 = 0 ;
V_41 -> V_196 = V_213 ;
V_41 -> V_199 = V_199 ;
if ( ! V_213 && ! V_199 )
return - V_55 ;
F_57 ( V_24 ) ;
V_123 = F_12 ( V_24 , V_216 ,
V_217 , V_217 ) ;
if ( V_123 < 0 ) {
F_27 ( V_24 -> V_2 , L_14 , V_123 ) ;
return V_123 ;
}
F_55 ( V_215 -> V_188 , V_24 ) ;
return 0 ;
}
static int F_61 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
if ( V_41 -> V_196 || V_41 -> V_199 )
F_58 ( V_24 ) ;
F_37 ( V_24 , V_129 ) ;
return 0 ;
}
static int F_62 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_214 * V_215 = F_60 ( V_24 -> V_2 ) ;
F_37 ( V_24 , V_126 ) ;
if ( V_41 -> V_196 || V_41 -> V_199 ) {
F_57 ( V_24 ) ;
F_55 ( V_215 -> V_188 , V_24 ) ;
}
return 0 ;
}
static int F_63 ( struct V_23 * V_24 )
{
int V_29 , V_123 ;
V_123 = F_5 ( V_24 , V_154 , 0 ) ;
if ( V_123 < 0 ) {
F_27 ( V_24 -> V_2 , L_15 , V_123 ) ;
return V_123 ;
}
V_123 = F_5 ( V_24 , V_218 , 0 ) ;
if ( V_123 < 0 ) {
F_27 ( V_24 -> V_2 , L_16 , V_123 ) ;
return V_123 ;
}
for ( V_29 = V_219 ; V_29 < V_7 ; V_29 ++ ) {
V_123 = F_5 ( V_24 , V_29 , F_26 ( V_24 , V_29 ) ) ;
if ( V_123 < 0 ) {
F_27 ( V_24 -> V_2 , L_17 , V_123 ) ;
return V_123 ;
}
}
return V_123 ;
}
static int F_64 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_69 * V_70 ;
struct V_214 * V_215 ;
int V_123 = 0 ;
F_63 ( V_24 ) ;
V_215 = F_60 ( V_24 -> V_2 ) ;
V_41 -> V_78 = ( unsigned ) - 1 ;
V_41 -> V_144 = 0 ;
V_41 -> V_175 = 0 ;
V_70 = & V_41 -> V_25 [ 0 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_100 = ( unsigned ) - 1 ;
V_70 -> V_146 = 0 ;
V_70 -> V_177 = 0 ;
V_70 = & V_41 -> V_25 [ 1 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_100 = ( unsigned ) - 1 ;
V_70 -> V_146 = 0 ;
V_70 -> V_177 = 0 ;
V_70 = & V_41 -> V_25 [ 2 ] ;
V_70 -> V_61 = ( unsigned ) - 1 ;
V_70 -> V_100 = ( unsigned ) - 1 ;
V_70 -> V_146 = 0 ;
V_70 -> V_177 = 0 ;
V_41 -> V_58 = 0 ;
V_41 -> V_44 = 0 ;
V_41 -> V_48 = 0 ;
if ( V_215 -> V_188 ) {
V_123 = F_65 ( V_215 -> V_188 , NULL ,
F_55 ,
V_220 | V_221 ,
L_18 , V_24 ) ;
if ( V_123 ) {
F_27 ( V_24 -> V_2 , L_19 , V_123 ) ;
goto V_222;
}
}
V_123 = F_26 ( V_24 , V_223 ) ;
if ( V_123 < 0 ) {
F_27 ( V_24 -> V_2 , L_20 ,
V_123 ) ;
goto V_224;
}
F_66 ( V_24 -> V_2 , L_21 , V_123 - 0x40 + 'A' ) ;
F_5 ( V_24 , V_218 , V_225 ) ;
F_37 ( V_24 , V_126 ) ;
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
F_54 ( V_24 ) ;
F_12 ( V_24 , V_218 , V_245 ,
V_245 ) ;
return 0 ;
V_224:
if ( V_215 -> V_188 )
F_67 ( V_215 -> V_188 , V_24 ) ;
V_222:
return V_123 ;
}
static int F_68 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = F_11 ( V_24 ) ;
struct V_214 * V_215 = F_60 ( V_24 -> V_2 ) ;
F_37 ( V_24 , V_129 ) ;
if ( V_41 -> V_196 || V_41 -> V_199 )
F_58 ( V_24 ) ;
if ( V_215 -> V_188 )
F_67 ( V_215 -> V_188 , V_24 ) ;
return 0 ;
}
static int F_69 ( struct V_214 * V_246 ,
const struct V_247 * V_136 )
{
struct V_40 * V_41 ;
int V_123 ;
V_41 = F_70 ( & V_246 -> V_2 , sizeof( struct V_40 ) ,
V_170 ) ;
if ( V_41 == NULL )
return - V_248 ;
V_41 -> V_130 = F_71 ( V_246 , & V_249 ) ;
if ( F_72 ( V_41 -> V_130 ) ) {
V_123 = F_73 ( V_41 -> V_130 ) ;
F_27 ( & V_246 -> V_2 , L_22 , V_123 ) ;
return V_123 ;
}
V_41 -> V_250 = V_136 -> V_251 ;
F_74 ( V_246 , V_41 ) ;
V_41 -> V_135 = V_246 -> V_2 . V_252 ;
V_123 = F_75 ( & V_246 -> V_2 , & V_253 ,
V_254 , F_22 ( V_254 ) ) ;
return V_123 ;
}
static int F_76 ( struct V_214 * V_215 )
{
F_77 ( & V_215 -> V_2 ) ;
return 0 ;
}
