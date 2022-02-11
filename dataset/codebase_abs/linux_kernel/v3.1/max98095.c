static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 >= V_4 )
return 0 ;
return V_5 [ V_3 ] . V_6 != 0 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_3 )
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
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_23 )
{
T_1 V_24 [ 2 ] ;
V_24 [ 0 ] = V_3 ;
V_24 [ 1 ] = V_23 ;
if ( V_2 -> V_25 ( V_2 -> V_26 , V_24 , 2 ) == 2 )
return 0 ;
else
return - V_27 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_28 ,
unsigned int V_29 , T_2 * V_30 )
{
unsigned int V_31 ;
unsigned int V_32 ;
F_5 ( V_29 > 4 ) ;
F_5 ( V_28 > 1 ) ;
V_31 = V_28 ? V_33 : V_34 ;
V_31 += V_29 * ( V_35 << 1 ) ;
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
F_3 ( V_2 , V_31 ++ , F_6 ( V_30 [ V_32 ] ) ) ;
F_3 ( V_2 , V_31 ++ , F_7 ( V_30 [ V_32 ] ) ) ;
}
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_28 ,
unsigned int V_29 , T_2 * V_30 )
{
unsigned int V_36 ;
unsigned int V_32 ;
F_5 ( V_29 > 1 ) ;
F_5 ( V_28 > 1 ) ;
V_36 = V_28 ? V_37 : V_38 ;
V_36 += V_29 * ( V_35 << 1 ) ;
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
F_3 ( V_2 , V_36 ++ , F_6 ( V_30 [ V_32 ] ) ) ;
F_3 ( V_2 , V_36 ++ , F_7 ( V_30 [ V_32 ] ) ) ;
}
}
static int F_9 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
unsigned int V_45 = V_42 -> V_23 . integer . V_23 [ 0 ] ;
V_44 -> V_46 = V_45 ;
F_12 ( V_2 , V_47 , V_48 ,
( 1 + V_45 ) << V_49 ) ;
return 0 ;
}
static int F_13 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
V_42 -> V_23 . integer . V_23 [ 0 ] = V_44 -> V_46 ;
return 0 ;
}
static int F_14 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
unsigned int V_45 = V_42 -> V_23 . integer . V_23 [ 0 ] ;
V_44 -> V_50 = V_45 ;
F_12 ( V_2 , V_51 , V_48 ,
( 1 + V_45 ) << V_49 ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
V_42 -> V_23 . integer . V_23 [ 0 ] = V_44 -> V_50 ;
return 0 ;
}
static int F_16 ( struct V_52 * V_53 ,
struct V_39 * V_40 , int V_54 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
switch ( V_54 ) {
case V_55 :
if ( V_53 -> V_3 == V_47 ) {
F_12 ( V_2 , V_53 -> V_3 , V_48 ,
( 1 + V_44 -> V_46 ) << V_49 ) ;
} else {
F_12 ( V_2 , V_53 -> V_3 , V_48 ,
( 1 + V_44 -> V_50 ) << V_49 ) ;
}
break;
case V_56 :
F_12 ( V_2 , V_53 -> V_3 , V_48 , 0 ) ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_17 ( struct V_52 * V_53 ,
int V_54 , T_1 V_58 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
T_1 * V_59 ;
F_5 ( ! ( ( V_58 == 1 ) || ( V_58 == 2 ) ) ) ;
V_59 = & V_44 -> V_60 ;
switch ( V_54 ) {
case V_55 :
* V_59 |= V_58 ;
F_12 ( V_2 , V_53 -> V_3 ,
( 1 << V_53 -> V_61 ) , ( 1 << V_53 -> V_61 ) ) ;
break;
case V_56 :
* V_59 &= ~ V_58 ;
if ( * V_59 == 0 ) {
F_12 ( V_2 , V_53 -> V_3 ,
( 1 << V_53 -> V_61 ) , 0 ) ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_18 ( struct V_52 * V_53 ,
struct V_39 * V_62 , int V_54 )
{
return F_17 ( V_53 , V_54 , 1 ) ;
}
static int F_19 ( struct V_52 * V_53 ,
struct V_39 * V_62 , int V_54 )
{
return F_17 ( V_53 , V_54 , 2 ) ;
}
static int F_20 ( struct V_52 * V_53 ,
struct V_39 * V_40 , int V_54 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
switch ( V_54 ) {
case V_55 :
F_12 ( V_2 , V_53 -> V_3 ,
( 1 << ( V_53 -> V_61 + 2 ) ) , ( 1 << ( V_53 -> V_61 + 2 ) ) ) ;
break;
case V_56 :
F_12 ( V_2 , V_53 -> V_3 ,
( 1 << ( V_53 -> V_61 + 2 ) ) , 0 ) ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_63 ,
F_23 ( V_63 ) ) ;
return 0 ;
}
static int F_24 ( int V_64 , T_1 * V_23 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < F_23 ( V_65 ) ; V_32 ++ ) {
if ( V_65 [ V_32 ] . V_64 >= V_64 ) {
* V_23 = V_65 [ V_32 ] . V_66 ;
return 0 ;
}
}
* V_23 = V_65 [ 0 ] . V_66 ;
return - V_57 ;
}
static int F_25 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_72 * V_73 ;
unsigned long long V_74 ;
unsigned int V_64 ;
T_1 V_75 ;
V_73 = & V_44 -> V_28 [ 0 ] ;
V_64 = F_26 ( V_70 ) ;
switch ( F_27 ( V_70 ) ) {
case V_76 :
F_12 ( V_2 , V_77 ,
V_78 , 0 ) ;
break;
case V_79 :
F_12 ( V_2 , V_77 ,
V_78 , V_78 ) ;
break;
default:
return - V_57 ;
}
if ( F_24 ( V_64 , & V_75 ) )
return - V_57 ;
F_12 ( V_2 , V_80 ,
V_81 , V_75 ) ;
V_73 -> V_64 = V_64 ;
if ( F_28 ( V_2 , V_77 ) & V_82 ) {
if ( V_44 -> V_83 == 0 ) {
F_29 ( V_2 -> V_84 , L_1 ) ;
return - V_57 ;
}
V_74 = 65536ULL * ( V_64 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_64 ;
F_30 ( V_74 , ( unsigned long long int ) V_44 -> V_83 ) ;
F_31 ( V_2 , V_85 ,
( V_74 >> 8 ) & 0x7F ) ;
F_31 ( V_2 , V_86 ,
V_74 & 0xFF ) ;
}
if ( V_64 < 50000 )
F_12 ( V_2 , V_87 ,
V_88 , 0 ) ;
else
F_12 ( V_2 , V_87 ,
V_88 , V_88 ) ;
return 0 ;
}
static int F_32 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_72 * V_73 ;
unsigned long long V_74 ;
unsigned int V_64 ;
T_1 V_75 ;
V_73 = & V_44 -> V_28 [ 1 ] ;
V_64 = F_26 ( V_70 ) ;
switch ( F_27 ( V_70 ) ) {
case V_76 :
F_12 ( V_2 , V_89 ,
V_78 , 0 ) ;
break;
case V_79 :
F_12 ( V_2 , V_89 ,
V_78 , V_78 ) ;
break;
default:
return - V_57 ;
}
if ( F_24 ( V_64 , & V_75 ) )
return - V_57 ;
F_12 ( V_2 , V_90 ,
V_81 , V_75 ) ;
V_73 -> V_64 = V_64 ;
if ( F_28 ( V_2 , V_89 ) & V_82 ) {
if ( V_44 -> V_83 == 0 ) {
F_29 ( V_2 -> V_84 , L_1 ) ;
return - V_57 ;
}
V_74 = 65536ULL * ( V_64 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_64 ;
F_30 ( V_74 , ( unsigned long long int ) V_44 -> V_83 ) ;
F_31 ( V_2 , V_91 ,
( V_74 >> 8 ) & 0x7F ) ;
F_31 ( V_2 , V_92 ,
V_74 & 0xFF ) ;
}
if ( V_64 < 50000 )
F_12 ( V_2 , V_93 ,
V_88 , 0 ) ;
else
F_12 ( V_2 , V_93 ,
V_88 , V_88 ) ;
return 0 ;
}
static int F_33 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_72 * V_73 ;
unsigned long long V_74 ;
unsigned int V_64 ;
T_1 V_75 ;
V_73 = & V_44 -> V_28 [ 2 ] ;
V_64 = F_26 ( V_70 ) ;
switch ( F_27 ( V_70 ) ) {
case V_76 :
F_12 ( V_2 , V_94 ,
V_78 , 0 ) ;
break;
case V_79 :
F_12 ( V_2 , V_94 ,
V_78 , V_78 ) ;
break;
default:
return - V_57 ;
}
if ( F_24 ( V_64 , & V_75 ) )
return - V_57 ;
F_12 ( V_2 , V_95 ,
V_81 , V_75 ) ;
V_73 -> V_64 = V_64 ;
if ( F_28 ( V_2 , V_94 ) & V_82 ) {
if ( V_44 -> V_83 == 0 ) {
F_29 ( V_2 -> V_84 , L_1 ) ;
return - V_57 ;
}
V_74 = 65536ULL * ( V_64 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_64 ;
F_30 ( V_74 , ( unsigned long long int ) V_44 -> V_83 ) ;
F_31 ( V_2 , V_96 ,
( V_74 >> 8 ) & 0x7F ) ;
F_31 ( V_2 , V_97 ,
V_74 & 0xFF ) ;
}
if ( V_64 < 50000 )
F_12 ( V_2 , V_98 ,
V_88 , 0 ) ;
else
F_12 ( V_2 , V_98 ,
V_88 , V_88 ) ;
return 0 ;
}
static int F_34 ( struct V_71 * V_28 ,
int V_99 , unsigned int V_100 , int V_101 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
if ( V_100 == V_44 -> V_83 )
return 0 ;
if ( ( V_100 >= 10000000 ) && ( V_100 < 20000000 ) ) {
F_31 ( V_2 , V_102 , 0x10 ) ;
} else if ( ( V_100 >= 20000000 ) && ( V_100 < 40000000 ) ) {
F_31 ( V_2 , V_102 , 0x20 ) ;
} else if ( ( V_100 >= 40000000 ) && ( V_100 < 60000000 ) ) {
F_31 ( V_2 , V_102 , 0x30 ) ;
} else {
F_29 ( V_2 -> V_84 , L_2 ) ;
return - V_57 ;
}
F_35 ( V_28 -> V_84 , L_3 , V_99 , V_100 ) ;
V_44 -> V_83 = V_100 ;
return 0 ;
}
static int F_36 ( struct V_71 * V_103 ,
unsigned int V_104 )
{
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_72 * V_73 ;
T_1 V_75 = 0 ;
V_73 = & V_44 -> V_28 [ 0 ] ;
if ( V_104 != V_73 -> V_104 ) {
V_73 -> V_104 = V_104 ;
switch ( V_104 & V_105 ) {
case V_106 :
F_31 ( V_2 , V_85 ,
0x80 ) ;
F_31 ( V_2 , V_86 ,
0x00 ) ;
break;
case V_107 :
V_75 |= V_82 ;
break;
case V_108 :
case V_109 :
default:
F_29 ( V_2 -> V_84 , L_4 ) ;
return - V_57 ;
}
switch ( V_104 & V_110 ) {
case V_111 :
V_75 |= V_112 ;
break;
case V_113 :
break;
default:
return - V_57 ;
}
switch ( V_104 & V_114 ) {
case V_115 :
break;
case V_116 :
V_75 |= V_117 ;
break;
case V_118 :
V_75 |= V_119 ;
break;
case V_120 :
V_75 |= V_119 | V_117 ;
break;
default:
return - V_57 ;
}
F_12 ( V_2 , V_77 ,
V_82 | V_112 | V_119 |
V_117 , V_75 ) ;
F_31 ( V_2 , V_121 , V_122 ) ;
}
return 0 ;
}
static int F_37 ( struct V_71 * V_103 ,
unsigned int V_104 )
{
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_72 * V_73 ;
T_1 V_75 = 0 ;
V_73 = & V_44 -> V_28 [ 1 ] ;
if ( V_104 != V_73 -> V_104 ) {
V_73 -> V_104 = V_104 ;
switch ( V_104 & V_105 ) {
case V_106 :
F_31 ( V_2 , V_91 ,
0x80 ) ;
F_31 ( V_2 , V_92 ,
0x00 ) ;
break;
case V_107 :
V_75 |= V_82 ;
break;
case V_108 :
case V_109 :
default:
F_29 ( V_2 -> V_84 , L_4 ) ;
return - V_57 ;
}
switch ( V_104 & V_110 ) {
case V_111 :
V_75 |= V_112 ;
break;
case V_113 :
break;
default:
return - V_57 ;
}
switch ( V_104 & V_114 ) {
case V_115 :
break;
case V_116 :
V_75 |= V_117 ;
break;
case V_118 :
V_75 |= V_119 ;
break;
case V_120 :
V_75 |= V_119 | V_117 ;
break;
default:
return - V_57 ;
}
F_12 ( V_2 , V_89 ,
V_82 | V_112 | V_119 |
V_117 , V_75 ) ;
F_31 ( V_2 , V_123 ,
V_122 ) ;
}
return 0 ;
}
static int F_38 ( struct V_71 * V_103 ,
unsigned int V_104 )
{
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_72 * V_73 ;
T_1 V_75 = 0 ;
V_73 = & V_44 -> V_28 [ 2 ] ;
if ( V_104 != V_73 -> V_104 ) {
V_73 -> V_104 = V_104 ;
switch ( V_104 & V_105 ) {
case V_106 :
F_31 ( V_2 , V_96 ,
0x80 ) ;
F_31 ( V_2 , V_97 ,
0x00 ) ;
break;
case V_107 :
V_75 |= V_82 ;
break;
case V_108 :
case V_109 :
default:
F_29 ( V_2 -> V_84 , L_4 ) ;
return - V_57 ;
}
switch ( V_104 & V_110 ) {
case V_111 :
V_75 |= V_112 ;
break;
case V_113 :
break;
default:
return - V_57 ;
}
switch ( V_104 & V_114 ) {
case V_115 :
break;
case V_116 :
V_75 |= V_117 ;
break;
case V_118 :
V_75 |= V_119 ;
break;
case V_120 :
V_75 |= V_119 | V_117 ;
break;
default:
return - V_57 ;
}
F_12 ( V_2 , V_94 ,
V_82 | V_112 | V_119 |
V_117 , V_75 ) ;
F_31 ( V_2 , V_124 ,
V_122 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
enum V_125 V_126 )
{
int V_127 ;
switch ( V_126 ) {
case V_128 :
break;
case V_129 :
break;
case V_130 :
if ( V_2 -> V_131 . V_132 == V_133 ) {
V_127 = F_40 ( V_2 ) ;
if ( V_127 != 0 ) {
F_29 ( V_2 -> V_84 , L_5 , V_127 ) ;
return V_127 ;
}
}
F_12 ( V_2 , V_134 ,
V_135 , V_135 ) ;
break;
case V_133 :
F_12 ( V_2 , V_134 ,
V_135 , 0 ) ;
V_2 -> V_136 = 1 ;
break;
}
V_2 -> V_131 . V_132 = V_126 ;
return 0 ;
}
static int F_41 ( const char * V_137 )
{
if ( strcmp ( V_137 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_137 , L_7 ) == 0 )
return 1 ;
return - V_57 ;
}
static int F_42 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_138 * V_139 = V_44 -> V_139 ;
int V_58 = F_41 ( V_40 -> V_140 . V_137 ) ;
struct V_72 * V_73 ;
int V_45 = V_42 -> V_23 . integer . V_23 [ 0 ] ;
struct V_141 * V_142 ;
int V_143 , V_144 , V_145 , V_32 ;
int V_146 , V_147 ;
F_5 ( V_58 > 1 ) ;
if ( ! V_139 || ! V_44 -> V_148 )
return 0 ;
if ( V_45 >= V_139 -> V_149 )
return - V_57 ;
V_73 = & V_44 -> V_28 [ V_58 ] ;
V_73 -> V_150 = V_45 ;
V_143 = V_73 -> V_64 ;
V_144 = 0 ;
V_145 = V_151 ;
for ( V_32 = 0 ; V_32 < V_139 -> V_149 ; V_32 ++ ) {
if ( strcmp ( V_139 -> V_152 [ V_32 ] . V_137 , V_44 -> V_153 [ V_45 ] ) == 0 &&
abs ( V_139 -> V_152 [ V_32 ] . V_64 - V_143 ) < V_145 ) {
V_144 = V_32 ;
V_145 = abs ( V_139 -> V_152 [ V_32 ] . V_64 - V_143 ) ;
}
}
F_35 ( V_2 -> V_84 , L_8 ,
V_139 -> V_152 [ V_144 ] . V_137 ,
V_139 -> V_152 [ V_144 ] . V_64 , V_143 ) ;
V_142 = & V_139 -> V_152 [ V_144 ] ;
V_146 = ( V_58 == 0 ) ? V_154 : V_155 ;
V_147 = F_28 ( V_2 , V_156 ) ;
F_12 ( V_2 , V_156 , V_146 , 0 ) ;
F_43 ( & V_2 -> V_157 ) ;
F_12 ( V_2 , V_158 , V_159 , V_159 ) ;
F_4 ( V_2 , V_58 , 0 , V_142 -> V_160 ) ;
F_4 ( V_2 , V_58 , 1 , V_142 -> V_161 ) ;
F_4 ( V_2 , V_58 , 2 , V_142 -> V_162 ) ;
F_4 ( V_2 , V_58 , 3 , V_142 -> V_163 ) ;
F_4 ( V_2 , V_58 , 4 , V_142 -> V_164 ) ;
F_12 ( V_2 , V_158 , V_159 , 0 ) ;
F_44 ( & V_2 -> V_157 ) ;
F_12 ( V_2 , V_156 , V_146 , V_147 ) ;
return 0 ;
}
static int F_45 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
int V_58 = F_41 ( V_40 -> V_140 . V_137 ) ;
struct V_72 * V_73 ;
V_73 = & V_44 -> V_28 [ V_58 ] ;
V_42 -> V_23 . V_165 . V_166 [ 0 ] = V_73 -> V_150 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_138 * V_139 = V_44 -> V_139 ;
struct V_141 * V_167 ;
unsigned int V_168 ;
int V_32 , V_169 ;
const char * * V_170 ;
int V_127 ;
struct V_171 V_172 [] = {
F_47 ( L_6 ,
V_44 -> V_173 ,
F_45 ,
F_42 ) ,
F_47 ( L_7 ,
V_44 -> V_173 ,
F_45 ,
F_42 ) ,
} ;
V_167 = V_139 -> V_152 ;
V_168 = V_139 -> V_149 ;
V_44 -> V_148 = 0 ;
V_44 -> V_153 = NULL ;
for ( V_32 = 0 ; V_32 < V_168 ; V_32 ++ ) {
for ( V_169 = 0 ; V_169 < V_44 -> V_148 ; V_169 ++ ) {
if ( strcmp ( V_167 [ V_32 ] . V_137 , V_44 -> V_153 [ V_169 ] ) == 0 )
break;
}
if ( V_169 != V_44 -> V_148 )
continue;
V_170 = F_48 ( V_44 -> V_153 ,
sizeof( char * ) * ( V_44 -> V_148 + 1 ) ,
V_174 ) ;
if ( V_170 == NULL )
continue;
V_170 [ V_44 -> V_148 ] = V_167 [ V_32 ] . V_137 ;
V_44 -> V_148 ++ ;
V_44 -> V_153 = V_170 ;
}
V_44 -> V_173 . V_175 = V_44 -> V_153 ;
V_44 -> V_173 . V_176 = V_44 -> V_148 ;
V_127 = F_22 ( V_2 , V_172 , F_23 ( V_172 ) ) ;
if ( V_127 != 0 )
F_29 ( V_2 -> V_84 , L_9 , V_127 ) ;
}
static int F_49 ( const char * V_137 )
{
if ( strcmp ( V_137 , L_10 ) == 0 )
return 0 ;
if ( strcmp ( V_137 , L_11 ) == 0 )
return 1 ;
return - V_57 ;
}
static int F_50 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_138 * V_139 = V_44 -> V_139 ;
int V_58 = F_49 ( V_40 -> V_140 . V_137 ) ;
struct V_72 * V_73 ;
int V_45 = V_42 -> V_23 . integer . V_23 [ 0 ] ;
struct V_177 * V_142 ;
int V_143 , V_144 , V_145 , V_32 ;
int V_146 , V_147 ;
F_5 ( V_58 > 1 ) ;
if ( ! V_139 || ! V_44 -> V_178 )
return 0 ;
if ( V_45 >= V_139 -> V_179 )
return - V_57 ;
V_73 = & V_44 -> V_28 [ V_58 ] ;
V_73 -> V_180 = V_45 ;
V_143 = V_73 -> V_64 ;
V_144 = 0 ;
V_145 = V_151 ;
for ( V_32 = 0 ; V_32 < V_139 -> V_179 ; V_32 ++ ) {
if ( strcmp ( V_139 -> V_181 [ V_32 ] . V_137 , V_44 -> V_182 [ V_45 ] ) == 0 &&
abs ( V_139 -> V_181 [ V_32 ] . V_64 - V_143 ) < V_145 ) {
V_144 = V_32 ;
V_145 = abs ( V_139 -> V_181 [ V_32 ] . V_64 - V_143 ) ;
}
}
F_35 ( V_2 -> V_84 , L_8 ,
V_139 -> V_181 [ V_144 ] . V_137 ,
V_139 -> V_181 [ V_144 ] . V_64 , V_143 ) ;
V_142 = & V_139 -> V_181 [ V_144 ] ;
V_146 = ( V_58 == 0 ) ? V_183 : V_184 ;
V_147 = F_28 ( V_2 , V_156 ) ;
F_12 ( V_2 , V_156 , V_146 , 0 ) ;
F_43 ( & V_2 -> V_157 ) ;
F_12 ( V_2 , V_158 , V_159 , V_159 ) ;
F_8 ( V_2 , V_58 , 0 , V_142 -> V_160 ) ;
F_8 ( V_2 , V_58 , 1 , V_142 -> V_161 ) ;
F_12 ( V_2 , V_158 , V_159 , 0 ) ;
F_44 ( & V_2 -> V_157 ) ;
F_12 ( V_2 , V_156 , V_146 , V_147 ) ;
return 0 ;
}
static int F_51 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
struct V_43 * V_44 = F_11 ( V_2 ) ;
int V_58 = F_49 ( V_40 -> V_140 . V_137 ) ;
struct V_72 * V_73 ;
V_73 = & V_44 -> V_28 [ V_58 ] ;
V_42 -> V_23 . V_165 . V_166 [ 0 ] = V_73 -> V_180 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_138 * V_139 = V_44 -> V_139 ;
struct V_177 * V_167 ;
unsigned int V_168 ;
int V_32 , V_169 ;
const char * * V_170 ;
int V_127 ;
struct V_171 V_172 [] = {
F_47 ( L_10 ,
V_44 -> V_185 ,
F_51 ,
F_50 ) ,
F_47 ( L_11 ,
V_44 -> V_185 ,
F_51 ,
F_50 ) ,
} ;
V_167 = V_139 -> V_181 ;
V_168 = V_139 -> V_179 ;
V_44 -> V_178 = 0 ;
V_44 -> V_182 = NULL ;
for ( V_32 = 0 ; V_32 < V_168 ; V_32 ++ ) {
for ( V_169 = 0 ; V_169 < V_44 -> V_178 ; V_169 ++ ) {
if ( strcmp ( V_167 [ V_32 ] . V_137 , V_44 -> V_182 [ V_169 ] ) == 0 )
break;
}
if ( V_169 != V_44 -> V_178 )
continue;
V_170 = F_48 ( V_44 -> V_182 ,
sizeof( char * ) * ( V_44 -> V_178 + 1 ) ,
V_174 ) ;
if ( V_170 == NULL )
continue;
V_170 [ V_44 -> V_178 ] = V_167 [ V_32 ] . V_137 ;
V_44 -> V_178 ++ ;
V_44 -> V_182 = V_170 ;
}
V_44 -> V_185 . V_175 = V_44 -> V_182 ;
V_44 -> V_185 . V_176 = V_44 -> V_178 ;
V_127 = F_22 ( V_2 , V_172 , F_23 ( V_172 ) ) ;
if ( V_127 != 0 )
F_29 ( V_2 -> V_84 , L_12 , V_127 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_138 * V_139 = V_44 -> V_139 ;
T_1 V_75 = 0 ;
if ( ! V_139 ) {
F_35 ( V_2 -> V_84 , L_13 ) ;
return;
}
if ( V_139 -> V_186 )
V_75 |= V_187 ;
if ( V_139 -> V_188 )
V_75 |= V_189 ;
F_31 ( V_2 , V_190 , V_75 ) ;
if ( V_139 -> V_149 )
F_46 ( V_2 ) ;
if ( V_139 -> V_179 )
F_52 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_3 V_59 )
{
F_39 ( V_2 , V_133 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_130 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_32 , V_127 ;
V_127 = F_31 ( V_2 , V_158 , 0 ) ;
if ( V_127 < 0 ) {
F_29 ( V_2 -> V_84 , L_14 , V_127 ) ;
return V_127 ;
}
V_127 = F_31 ( V_2 , V_191 , 0 ) ;
if ( V_127 < 0 ) {
F_29 ( V_2 -> V_84 , L_15 , V_127 ) ;
return V_127 ;
}
for ( V_32 = V_192 ; V_32 < V_7 ; V_32 ++ ) {
V_127 = F_31 ( V_2 , V_32 , V_193 [ V_32 ] ) ;
if ( V_127 < 0 ) {
F_29 ( V_2 -> V_84 , L_16 , V_127 ) ;
return V_127 ;
}
}
return V_127 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = F_11 ( V_2 ) ;
struct V_72 * V_73 ;
int V_127 = 0 ;
V_127 = F_58 ( V_2 , 8 , 8 , V_194 ) ;
if ( V_127 != 0 ) {
F_29 ( V_2 -> V_84 , L_17 , V_127 ) ;
return V_127 ;
}
F_56 ( V_2 ) ;
V_44 -> V_83 = ( unsigned ) - 1 ;
V_44 -> V_148 = 0 ;
V_44 -> V_178 = 0 ;
V_73 = & V_44 -> V_28 [ 0 ] ;
V_73 -> V_64 = ( unsigned ) - 1 ;
V_73 -> V_104 = ( unsigned ) - 1 ;
V_73 -> V_150 = 0 ;
V_73 -> V_180 = 0 ;
V_73 = & V_44 -> V_28 [ 1 ] ;
V_73 -> V_64 = ( unsigned ) - 1 ;
V_73 -> V_104 = ( unsigned ) - 1 ;
V_73 -> V_150 = 0 ;
V_73 -> V_180 = 0 ;
V_73 = & V_44 -> V_28 [ 2 ] ;
V_73 -> V_64 = ( unsigned ) - 1 ;
V_73 -> V_104 = ( unsigned ) - 1 ;
V_73 -> V_150 = 0 ;
V_73 -> V_180 = 0 ;
V_44 -> V_60 = 0 ;
V_44 -> V_46 = 0 ;
V_44 -> V_50 = 0 ;
V_127 = F_28 ( V_2 , V_195 ) ;
if ( V_127 < 0 ) {
F_29 ( V_2 -> V_84 , L_18 ,
V_127 ) ;
goto V_196;
}
F_59 ( V_2 -> V_84 , L_19 , V_127 - 0x40 + 'A' ) ;
F_31 ( V_2 , V_191 , V_197 ) ;
F_39 ( V_2 , V_130 ) ;
F_31 ( V_2 , V_198 ,
V_199 | V_200 ) ;
F_31 ( V_2 , V_201 ,
V_202 | V_203 ) ;
F_31 ( V_2 , V_204 , V_205 ) ;
F_31 ( V_2 , V_206 , V_207 ) ;
F_31 ( V_2 , V_208 , V_209 ) ;
F_31 ( V_2 , V_210 ,
V_211 | V_212 ) ;
F_31 ( V_2 , V_213 ,
V_214 | V_212 ) ;
F_31 ( V_2 , V_215 ,
V_216 | V_212 ) ;
F_53 ( V_2 ) ;
F_12 ( V_2 , V_191 , V_217 ,
V_217 ) ;
F_21 ( V_2 ) ;
V_196:
return V_127 ;
}
static int F_60 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_133 ) ;
return 0 ;
}
static int F_61 ( struct V_218 * V_219 ,
const struct V_220 * V_140 )
{
struct V_43 * V_44 ;
int V_127 ;
V_44 = F_62 ( sizeof( struct V_43 ) , V_174 ) ;
if ( V_44 == NULL )
return - V_221 ;
V_44 -> V_222 = V_140 -> V_223 ;
F_63 ( V_219 , V_44 ) ;
V_44 -> V_26 = V_219 ;
V_44 -> V_139 = V_219 -> V_84 . V_224 ;
V_127 = F_64 ( & V_219 -> V_84 , & V_225 ,
V_226 , F_23 ( V_226 ) ) ;
if ( V_127 < 0 )
F_65 ( V_44 ) ;
return V_127 ;
}
static int T_4 F_66 ( struct V_218 * V_227 )
{
F_67 ( & V_227 -> V_84 ) ;
F_65 ( F_68 ( V_227 ) ) ;
return 0 ;
}
static int T_5 F_69 ( void )
{
int V_127 ;
V_127 = F_70 ( & V_228 ) ;
if ( V_127 )
F_71 ( L_20 , V_127 ) ;
return V_127 ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_228 ) ;
}
