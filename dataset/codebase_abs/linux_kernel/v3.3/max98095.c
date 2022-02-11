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
int V_24 ;
V_2 -> V_25 = 1 ;
V_24 = F_4 ( V_2 , V_3 , V_23 ) ;
V_2 -> V_25 = 0 ;
return V_24 ? - V_26 : 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_27 ,
unsigned int V_28 , T_1 * V_29 )
{
unsigned int V_30 ;
unsigned int V_31 ;
F_6 ( V_28 > 4 ) ;
F_6 ( V_27 > 1 ) ;
V_30 = V_27 ? V_32 : V_33 ;
V_30 += V_28 * ( V_34 << 1 ) ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ ) {
F_3 ( V_2 , V_30 ++ , F_7 ( V_29 [ V_31 ] ) ) ;
F_3 ( V_2 , V_30 ++ , F_8 ( V_29 [ V_31 ] ) ) ;
}
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_27 ,
unsigned int V_28 , T_1 * V_29 )
{
unsigned int V_35 ;
unsigned int V_31 ;
F_6 ( V_28 > 1 ) ;
F_6 ( V_27 > 1 ) ;
V_35 = V_27 ? V_36 : V_37 ;
V_35 += V_28 * ( V_34 << 1 ) ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ ) {
F_3 ( V_2 , V_35 ++ , F_7 ( V_29 [ V_31 ] ) ) ;
F_3 ( V_2 , V_35 ++ , F_8 ( V_29 [ V_31 ] ) ) ;
}
}
static int F_10 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
unsigned int V_44 = V_41 -> V_23 . integer . V_23 [ 0 ] ;
V_43 -> V_45 = V_44 ;
F_13 ( V_2 , V_46 , V_47 ,
( 1 + V_44 ) << V_48 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
V_41 -> V_23 . integer . V_23 [ 0 ] = V_43 -> V_45 ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
unsigned int V_44 = V_41 -> V_23 . integer . V_23 [ 0 ] ;
V_43 -> V_49 = V_44 ;
F_13 ( V_2 , V_50 , V_47 ,
( 1 + V_44 ) << V_48 ) ;
return 0 ;
}
static int F_16 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
V_41 -> V_23 . integer . V_23 [ 0 ] = V_43 -> V_49 ;
return 0 ;
}
static int F_17 ( struct V_51 * V_52 ,
struct V_38 * V_39 , int V_53 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
switch ( V_53 ) {
case V_54 :
if ( V_52 -> V_3 == V_46 ) {
F_13 ( V_2 , V_52 -> V_3 , V_47 ,
( 1 + V_43 -> V_45 ) << V_48 ) ;
} else {
F_13 ( V_2 , V_52 -> V_3 , V_47 ,
( 1 + V_43 -> V_49 ) << V_48 ) ;
}
break;
case V_55 :
F_13 ( V_2 , V_52 -> V_3 , V_47 , 0 ) ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_18 ( struct V_51 * V_52 ,
int V_53 , T_2 V_57 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
T_2 * V_58 ;
F_6 ( ! ( ( V_57 == 1 ) || ( V_57 == 2 ) ) ) ;
V_58 = & V_43 -> V_59 ;
switch ( V_53 ) {
case V_54 :
* V_58 |= V_57 ;
F_13 ( V_2 , V_52 -> V_3 ,
( 1 << V_52 -> V_60 ) , ( 1 << V_52 -> V_60 ) ) ;
break;
case V_55 :
* V_58 &= ~ V_57 ;
if ( * V_58 == 0 ) {
F_13 ( V_2 , V_52 -> V_3 ,
( 1 << V_52 -> V_60 ) , 0 ) ;
}
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_19 ( struct V_51 * V_52 ,
struct V_38 * V_61 , int V_53 )
{
return F_18 ( V_52 , V_53 , 1 ) ;
}
static int F_20 ( struct V_51 * V_52 ,
struct V_38 * V_61 , int V_53 )
{
return F_18 ( V_52 , V_53 , 2 ) ;
}
static int F_21 ( struct V_51 * V_52 ,
struct V_38 * V_39 , int V_53 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
switch ( V_53 ) {
case V_54 :
F_13 ( V_2 , V_52 -> V_3 ,
( 1 << ( V_52 -> V_60 + 2 ) ) , ( 1 << ( V_52 -> V_60 + 2 ) ) ) ;
break;
case V_55 :
F_13 ( V_2 , V_52 -> V_3 ,
( 1 << ( V_52 -> V_60 + 2 ) ) , 0 ) ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_62 ,
F_24 ( V_62 ) ) ;
return 0 ;
}
static int F_25 ( int V_63 , T_2 * V_23 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_24 ( V_64 ) ; V_31 ++ ) {
if ( V_64 [ V_31 ] . V_63 >= V_63 ) {
* V_23 = V_64 [ V_31 ] . V_65 ;
return 0 ;
}
}
* V_23 = V_64 [ 0 ] . V_65 ;
return - V_56 ;
}
static int F_26 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_70 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_71 * V_72 ;
unsigned long long V_73 ;
unsigned int V_63 ;
T_2 V_74 ;
V_72 = & V_43 -> V_27 [ 0 ] ;
V_63 = F_27 ( V_69 ) ;
switch ( F_28 ( V_69 ) ) {
case V_75 :
F_13 ( V_2 , V_76 ,
V_77 , 0 ) ;
break;
case V_78 :
F_13 ( V_2 , V_76 ,
V_77 , V_77 ) ;
break;
default:
return - V_56 ;
}
if ( F_25 ( V_63 , & V_74 ) )
return - V_56 ;
F_13 ( V_2 , V_79 ,
V_80 , V_74 ) ;
V_72 -> V_63 = V_63 ;
if ( F_29 ( V_2 , V_76 ) & V_81 ) {
if ( V_43 -> V_82 == 0 ) {
F_30 ( V_2 -> V_83 , L_1 ) ;
return - V_56 ;
}
V_73 = 65536ULL * ( V_63 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_63 ;
F_31 ( V_73 , ( unsigned long long int ) V_43 -> V_82 ) ;
F_4 ( V_2 , V_84 ,
( V_73 >> 8 ) & 0x7F ) ;
F_4 ( V_2 , V_85 ,
V_73 & 0xFF ) ;
}
if ( V_63 < 50000 )
F_13 ( V_2 , V_86 ,
V_87 , 0 ) ;
else
F_13 ( V_2 , V_86 ,
V_87 , V_87 ) ;
return 0 ;
}
static int F_32 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_70 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_71 * V_72 ;
unsigned long long V_73 ;
unsigned int V_63 ;
T_2 V_74 ;
V_72 = & V_43 -> V_27 [ 1 ] ;
V_63 = F_27 ( V_69 ) ;
switch ( F_28 ( V_69 ) ) {
case V_75 :
F_13 ( V_2 , V_88 ,
V_77 , 0 ) ;
break;
case V_78 :
F_13 ( V_2 , V_88 ,
V_77 , V_77 ) ;
break;
default:
return - V_56 ;
}
if ( F_25 ( V_63 , & V_74 ) )
return - V_56 ;
F_13 ( V_2 , V_89 ,
V_80 , V_74 ) ;
V_72 -> V_63 = V_63 ;
if ( F_29 ( V_2 , V_88 ) & V_81 ) {
if ( V_43 -> V_82 == 0 ) {
F_30 ( V_2 -> V_83 , L_1 ) ;
return - V_56 ;
}
V_73 = 65536ULL * ( V_63 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_63 ;
F_31 ( V_73 , ( unsigned long long int ) V_43 -> V_82 ) ;
F_4 ( V_2 , V_90 ,
( V_73 >> 8 ) & 0x7F ) ;
F_4 ( V_2 , V_91 ,
V_73 & 0xFF ) ;
}
if ( V_63 < 50000 )
F_13 ( V_2 , V_92 ,
V_87 , 0 ) ;
else
F_13 ( V_2 , V_92 ,
V_87 , V_87 ) ;
return 0 ;
}
static int F_33 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_70 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_71 * V_72 ;
unsigned long long V_73 ;
unsigned int V_63 ;
T_2 V_74 ;
V_72 = & V_43 -> V_27 [ 2 ] ;
V_63 = F_27 ( V_69 ) ;
switch ( F_28 ( V_69 ) ) {
case V_75 :
F_13 ( V_2 , V_93 ,
V_77 , 0 ) ;
break;
case V_78 :
F_13 ( V_2 , V_93 ,
V_77 , V_77 ) ;
break;
default:
return - V_56 ;
}
if ( F_25 ( V_63 , & V_74 ) )
return - V_56 ;
F_13 ( V_2 , V_94 ,
V_80 , V_74 ) ;
V_72 -> V_63 = V_63 ;
if ( F_29 ( V_2 , V_93 ) & V_81 ) {
if ( V_43 -> V_82 == 0 ) {
F_30 ( V_2 -> V_83 , L_1 ) ;
return - V_56 ;
}
V_73 = 65536ULL * ( V_63 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_63 ;
F_31 ( V_73 , ( unsigned long long int ) V_43 -> V_82 ) ;
F_4 ( V_2 , V_95 ,
( V_73 >> 8 ) & 0x7F ) ;
F_4 ( V_2 , V_96 ,
V_73 & 0xFF ) ;
}
if ( V_63 < 50000 )
F_13 ( V_2 , V_97 ,
V_87 , 0 ) ;
else
F_13 ( V_2 , V_97 ,
V_87 , V_87 ) ;
return 0 ;
}
static int F_34 ( struct V_70 * V_27 ,
int V_98 , unsigned int V_99 , int V_100 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
if ( V_99 == V_43 -> V_82 )
return 0 ;
if ( ( V_99 >= 10000000 ) && ( V_99 < 20000000 ) ) {
F_4 ( V_2 , V_101 , 0x10 ) ;
} else if ( ( V_99 >= 20000000 ) && ( V_99 < 40000000 ) ) {
F_4 ( V_2 , V_101 , 0x20 ) ;
} else if ( ( V_99 >= 40000000 ) && ( V_99 < 60000000 ) ) {
F_4 ( V_2 , V_101 , 0x30 ) ;
} else {
F_30 ( V_2 -> V_83 , L_2 ) ;
return - V_56 ;
}
F_35 ( V_27 -> V_83 , L_3 , V_98 , V_99 ) ;
V_43 -> V_82 = V_99 ;
return 0 ;
}
static int F_36 ( struct V_70 * V_102 ,
unsigned int V_103 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_71 * V_72 ;
T_2 V_74 = 0 ;
V_72 = & V_43 -> V_27 [ 0 ] ;
if ( V_103 != V_72 -> V_103 ) {
V_72 -> V_103 = V_103 ;
switch ( V_103 & V_104 ) {
case V_105 :
F_4 ( V_2 , V_84 ,
0x80 ) ;
F_4 ( V_2 , V_85 ,
0x00 ) ;
break;
case V_106 :
V_74 |= V_81 ;
break;
case V_107 :
case V_108 :
default:
F_30 ( V_2 -> V_83 , L_4 ) ;
return - V_56 ;
}
switch ( V_103 & V_109 ) {
case V_110 :
V_74 |= V_111 ;
break;
case V_112 :
break;
default:
return - V_56 ;
}
switch ( V_103 & V_113 ) {
case V_114 :
break;
case V_115 :
V_74 |= V_116 ;
break;
case V_117 :
V_74 |= V_118 ;
break;
case V_119 :
V_74 |= V_118 | V_116 ;
break;
default:
return - V_56 ;
}
F_13 ( V_2 , V_76 ,
V_81 | V_111 | V_118 |
V_116 , V_74 ) ;
F_4 ( V_2 , V_120 , V_121 ) ;
}
return 0 ;
}
static int F_37 ( struct V_70 * V_102 ,
unsigned int V_103 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_71 * V_72 ;
T_2 V_74 = 0 ;
V_72 = & V_43 -> V_27 [ 1 ] ;
if ( V_103 != V_72 -> V_103 ) {
V_72 -> V_103 = V_103 ;
switch ( V_103 & V_104 ) {
case V_105 :
F_4 ( V_2 , V_90 ,
0x80 ) ;
F_4 ( V_2 , V_91 ,
0x00 ) ;
break;
case V_106 :
V_74 |= V_81 ;
break;
case V_107 :
case V_108 :
default:
F_30 ( V_2 -> V_83 , L_4 ) ;
return - V_56 ;
}
switch ( V_103 & V_109 ) {
case V_110 :
V_74 |= V_111 ;
break;
case V_112 :
break;
default:
return - V_56 ;
}
switch ( V_103 & V_113 ) {
case V_114 :
break;
case V_115 :
V_74 |= V_116 ;
break;
case V_117 :
V_74 |= V_118 ;
break;
case V_119 :
V_74 |= V_118 | V_116 ;
break;
default:
return - V_56 ;
}
F_13 ( V_2 , V_88 ,
V_81 | V_111 | V_118 |
V_116 , V_74 ) ;
F_4 ( V_2 , V_122 ,
V_121 ) ;
}
return 0 ;
}
static int F_38 ( struct V_70 * V_102 ,
unsigned int V_103 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_71 * V_72 ;
T_2 V_74 = 0 ;
V_72 = & V_43 -> V_27 [ 2 ] ;
if ( V_103 != V_72 -> V_103 ) {
V_72 -> V_103 = V_103 ;
switch ( V_103 & V_104 ) {
case V_105 :
F_4 ( V_2 , V_95 ,
0x80 ) ;
F_4 ( V_2 , V_96 ,
0x00 ) ;
break;
case V_106 :
V_74 |= V_81 ;
break;
case V_107 :
case V_108 :
default:
F_30 ( V_2 -> V_83 , L_4 ) ;
return - V_56 ;
}
switch ( V_103 & V_109 ) {
case V_110 :
V_74 |= V_111 ;
break;
case V_112 :
break;
default:
return - V_56 ;
}
switch ( V_103 & V_113 ) {
case V_114 :
break;
case V_115 :
V_74 |= V_116 ;
break;
case V_117 :
V_74 |= V_118 ;
break;
case V_119 :
V_74 |= V_118 | V_116 ;
break;
default:
return - V_56 ;
}
F_13 ( V_2 , V_93 ,
V_81 | V_111 | V_118 |
V_116 , V_74 ) ;
F_4 ( V_2 , V_123 ,
V_121 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
enum V_124 V_125 )
{
int V_24 ;
switch ( V_125 ) {
case V_126 :
break;
case V_127 :
break;
case V_128 :
if ( V_2 -> V_129 . V_130 == V_131 ) {
V_24 = F_40 ( V_2 ) ;
if ( V_24 != 0 ) {
F_30 ( V_2 -> V_83 , L_5 , V_24 ) ;
return V_24 ;
}
}
F_13 ( V_2 , V_132 ,
V_133 , V_133 ) ;
break;
case V_131 :
F_13 ( V_2 , V_132 ,
V_133 , 0 ) ;
V_2 -> V_134 = 1 ;
break;
}
V_2 -> V_129 . V_130 = V_125 ;
return 0 ;
}
static int F_41 ( const char * V_135 )
{
if ( strcmp ( V_135 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_135 , L_7 ) == 0 )
return 1 ;
return - V_56 ;
}
static int F_42 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_136 * V_137 = V_43 -> V_137 ;
int V_57 = F_41 ( V_39 -> V_138 . V_135 ) ;
struct V_71 * V_72 ;
int V_44 = V_41 -> V_23 . integer . V_23 [ 0 ] ;
struct V_139 * V_140 ;
int V_141 , V_142 , V_143 , V_31 ;
int V_144 , V_145 ;
F_6 ( V_57 > 1 ) ;
if ( ! V_137 || ! V_43 -> V_146 )
return 0 ;
if ( V_44 >= V_137 -> V_147 )
return - V_56 ;
V_72 = & V_43 -> V_27 [ V_57 ] ;
V_72 -> V_148 = V_44 ;
V_141 = V_72 -> V_63 ;
V_142 = 0 ;
V_143 = V_149 ;
for ( V_31 = 0 ; V_31 < V_137 -> V_147 ; V_31 ++ ) {
if ( strcmp ( V_137 -> V_150 [ V_31 ] . V_135 , V_43 -> V_151 [ V_44 ] ) == 0 &&
abs ( V_137 -> V_150 [ V_31 ] . V_63 - V_141 ) < V_143 ) {
V_142 = V_31 ;
V_143 = abs ( V_137 -> V_150 [ V_31 ] . V_63 - V_141 ) ;
}
}
F_35 ( V_2 -> V_83 , L_8 ,
V_137 -> V_150 [ V_142 ] . V_135 ,
V_137 -> V_150 [ V_142 ] . V_63 , V_141 ) ;
V_140 = & V_137 -> V_150 [ V_142 ] ;
V_144 = ( V_57 == 0 ) ? V_152 : V_153 ;
V_145 = F_29 ( V_2 , V_154 ) ;
F_13 ( V_2 , V_154 , V_144 , 0 ) ;
F_43 ( & V_2 -> V_155 ) ;
F_13 ( V_2 , V_156 , V_157 , V_157 ) ;
F_5 ( V_2 , V_57 , 0 , V_140 -> V_158 ) ;
F_5 ( V_2 , V_57 , 1 , V_140 -> V_159 ) ;
F_5 ( V_2 , V_57 , 2 , V_140 -> V_160 ) ;
F_5 ( V_2 , V_57 , 3 , V_140 -> V_161 ) ;
F_5 ( V_2 , V_57 , 4 , V_140 -> V_162 ) ;
F_13 ( V_2 , V_156 , V_157 , 0 ) ;
F_44 ( & V_2 -> V_155 ) ;
F_13 ( V_2 , V_154 , V_144 , V_145 ) ;
return 0 ;
}
static int F_45 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
int V_57 = F_41 ( V_39 -> V_138 . V_135 ) ;
struct V_71 * V_72 ;
V_72 = & V_43 -> V_27 [ V_57 ] ;
V_41 -> V_23 . V_163 . V_164 [ 0 ] = V_72 -> V_148 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_136 * V_137 = V_43 -> V_137 ;
struct V_139 * V_165 ;
unsigned int V_166 ;
int V_31 , V_167 ;
const char * * V_168 ;
int V_24 ;
struct V_169 V_170 [] = {
F_47 ( L_6 ,
V_43 -> V_171 ,
F_45 ,
F_42 ) ,
F_47 ( L_7 ,
V_43 -> V_171 ,
F_45 ,
F_42 ) ,
} ;
V_165 = V_137 -> V_150 ;
V_166 = V_137 -> V_147 ;
V_43 -> V_146 = 0 ;
V_43 -> V_151 = NULL ;
for ( V_31 = 0 ; V_31 < V_166 ; V_31 ++ ) {
for ( V_167 = 0 ; V_167 < V_43 -> V_146 ; V_167 ++ ) {
if ( strcmp ( V_165 [ V_31 ] . V_135 , V_43 -> V_151 [ V_167 ] ) == 0 )
break;
}
if ( V_167 != V_43 -> V_146 )
continue;
V_168 = F_48 ( V_43 -> V_151 ,
sizeof( char * ) * ( V_43 -> V_146 + 1 ) ,
V_172 ) ;
if ( V_168 == NULL )
continue;
V_168 [ V_43 -> V_146 ] = V_165 [ V_31 ] . V_135 ;
V_43 -> V_146 ++ ;
V_43 -> V_151 = V_168 ;
}
V_43 -> V_171 . V_173 = V_43 -> V_151 ;
V_43 -> V_171 . V_174 = V_43 -> V_146 ;
V_24 = F_23 ( V_2 , V_170 , F_24 ( V_170 ) ) ;
if ( V_24 != 0 )
F_30 ( V_2 -> V_83 , L_9 , V_24 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
const char * V_135 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_24 ( V_175 ) ; V_31 ++ )
if ( strcmp ( V_135 , V_175 [ V_31 ] ) == 0 )
return V_31 ;
F_30 ( V_2 -> V_83 , L_10 , V_135 ) ;
return - V_56 ;
}
static int F_50 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_136 * V_137 = V_43 -> V_137 ;
int V_57 = F_49 ( V_2 , V_39 -> V_138 . V_135 ) ;
struct V_71 * V_72 ;
int V_44 = V_41 -> V_23 . integer . V_23 [ 0 ] ;
struct V_176 * V_140 ;
int V_141 , V_142 , V_143 , V_31 ;
int V_144 , V_145 ;
if ( V_57 < 0 )
return V_57 ;
if ( ! V_137 || ! V_43 -> V_177 )
return 0 ;
if ( V_44 >= V_137 -> V_178 )
return - V_56 ;
V_72 = & V_43 -> V_27 [ V_57 ] ;
V_72 -> V_179 = V_44 ;
V_141 = V_72 -> V_63 ;
V_142 = 0 ;
V_143 = V_149 ;
for ( V_31 = 0 ; V_31 < V_137 -> V_178 ; V_31 ++ ) {
if ( strcmp ( V_137 -> V_180 [ V_31 ] . V_135 , V_43 -> V_181 [ V_44 ] ) == 0 &&
abs ( V_137 -> V_180 [ V_31 ] . V_63 - V_141 ) < V_143 ) {
V_142 = V_31 ;
V_143 = abs ( V_137 -> V_180 [ V_31 ] . V_63 - V_141 ) ;
}
}
F_35 ( V_2 -> V_83 , L_8 ,
V_137 -> V_180 [ V_142 ] . V_135 ,
V_137 -> V_180 [ V_142 ] . V_63 , V_141 ) ;
V_140 = & V_137 -> V_180 [ V_142 ] ;
V_144 = ( V_57 == 0 ) ? V_182 : V_183 ;
V_145 = F_29 ( V_2 , V_154 ) ;
F_13 ( V_2 , V_154 , V_144 , 0 ) ;
F_43 ( & V_2 -> V_155 ) ;
F_13 ( V_2 , V_156 , V_157 , V_157 ) ;
F_9 ( V_2 , V_57 , 0 , V_140 -> V_158 ) ;
F_9 ( V_2 , V_57 , 1 , V_140 -> V_159 ) ;
F_13 ( V_2 , V_156 , V_157 , 0 ) ;
F_44 ( & V_2 -> V_155 ) ;
F_13 ( V_2 , V_154 , V_144 , V_145 ) ;
return 0 ;
}
static int F_51 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_42 * V_43 = F_12 ( V_2 ) ;
int V_57 = F_49 ( V_2 , V_39 -> V_138 . V_135 ) ;
struct V_71 * V_72 ;
if ( V_57 < 0 )
return V_57 ;
V_72 = & V_43 -> V_27 [ V_57 ] ;
V_41 -> V_23 . V_163 . V_164 [ 0 ] = V_72 -> V_179 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_136 * V_137 = V_43 -> V_137 ;
struct V_176 * V_165 ;
unsigned int V_166 ;
int V_31 , V_167 ;
const char * * V_168 ;
int V_24 ;
struct V_169 V_170 [] = {
F_47 ( ( char * ) V_175 [ 0 ] ,
V_43 -> V_184 ,
F_51 ,
F_50 ) ,
F_47 ( ( char * ) V_175 [ 1 ] ,
V_43 -> V_184 ,
F_51 ,
F_50 ) ,
} ;
F_53 ( F_24 ( V_170 ) != F_24 ( V_175 ) ) ;
V_165 = V_137 -> V_180 ;
V_166 = V_137 -> V_178 ;
V_43 -> V_177 = 0 ;
V_43 -> V_181 = NULL ;
for ( V_31 = 0 ; V_31 < V_166 ; V_31 ++ ) {
for ( V_167 = 0 ; V_167 < V_43 -> V_177 ; V_167 ++ ) {
if ( strcmp ( V_165 [ V_31 ] . V_135 , V_43 -> V_181 [ V_167 ] ) == 0 )
break;
}
if ( V_167 != V_43 -> V_177 )
continue;
V_168 = F_48 ( V_43 -> V_181 ,
sizeof( char * ) * ( V_43 -> V_177 + 1 ) ,
V_172 ) ;
if ( V_168 == NULL )
continue;
V_168 [ V_43 -> V_177 ] = V_165 [ V_31 ] . V_135 ;
V_43 -> V_177 ++ ;
V_43 -> V_181 = V_168 ;
}
V_43 -> V_184 . V_173 = V_43 -> V_181 ;
V_43 -> V_184 . V_174 = V_43 -> V_177 ;
V_24 = F_23 ( V_2 , V_170 , F_24 ( V_170 ) ) ;
if ( V_24 != 0 )
F_30 ( V_2 -> V_83 , L_11 , V_24 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_136 * V_137 = V_43 -> V_137 ;
T_2 V_74 = 0 ;
if ( ! V_137 ) {
F_35 ( V_2 -> V_83 , L_12 ) ;
return;
}
if ( V_137 -> V_185 )
V_74 |= V_186 ;
if ( V_137 -> V_187 )
V_74 |= V_188 ;
F_4 ( V_2 , V_189 , V_74 ) ;
if ( V_137 -> V_147 )
F_46 ( V_2 ) ;
if ( V_137 -> V_178 )
F_52 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_131 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_128 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_31 , V_24 ;
V_24 = F_4 ( V_2 , V_156 , 0 ) ;
if ( V_24 < 0 ) {
F_30 ( V_2 -> V_83 , L_13 , V_24 ) ;
return V_24 ;
}
V_24 = F_4 ( V_2 , V_190 , 0 ) ;
if ( V_24 < 0 ) {
F_30 ( V_2 -> V_83 , L_14 , V_24 ) ;
return V_24 ;
}
for ( V_31 = V_191 ; V_31 < V_7 ; V_31 ++ ) {
V_24 = F_4 ( V_2 , V_31 , V_192 [ V_31 ] ) ;
if ( V_24 < 0 ) {
F_30 ( V_2 -> V_83 , L_15 , V_24 ) ;
return V_24 ;
}
}
return V_24 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_12 ( V_2 ) ;
struct V_71 * V_72 ;
int V_24 = 0 ;
V_24 = F_59 ( V_2 , 8 , 8 , V_193 ) ;
if ( V_24 != 0 ) {
F_30 ( V_2 -> V_83 , L_16 , V_24 ) ;
return V_24 ;
}
F_57 ( V_2 ) ;
V_43 -> V_82 = ( unsigned ) - 1 ;
V_43 -> V_146 = 0 ;
V_43 -> V_177 = 0 ;
V_72 = & V_43 -> V_27 [ 0 ] ;
V_72 -> V_63 = ( unsigned ) - 1 ;
V_72 -> V_103 = ( unsigned ) - 1 ;
V_72 -> V_148 = 0 ;
V_72 -> V_179 = 0 ;
V_72 = & V_43 -> V_27 [ 1 ] ;
V_72 -> V_63 = ( unsigned ) - 1 ;
V_72 -> V_103 = ( unsigned ) - 1 ;
V_72 -> V_148 = 0 ;
V_72 -> V_179 = 0 ;
V_72 = & V_43 -> V_27 [ 2 ] ;
V_72 -> V_63 = ( unsigned ) - 1 ;
V_72 -> V_103 = ( unsigned ) - 1 ;
V_72 -> V_148 = 0 ;
V_72 -> V_179 = 0 ;
V_43 -> V_59 = 0 ;
V_43 -> V_45 = 0 ;
V_43 -> V_49 = 0 ;
V_24 = F_29 ( V_2 , V_194 ) ;
if ( V_24 < 0 ) {
F_30 ( V_2 -> V_83 , L_17 ,
V_24 ) ;
goto V_195;
}
F_60 ( V_2 -> V_83 , L_18 , V_24 - 0x40 + 'A' ) ;
F_4 ( V_2 , V_190 , V_196 ) ;
F_39 ( V_2 , V_128 ) ;
F_4 ( V_2 , V_197 ,
V_198 | V_199 ) ;
F_4 ( V_2 , V_200 ,
V_201 | V_202 ) ;
F_4 ( V_2 , V_203 , V_204 ) ;
F_4 ( V_2 , V_205 , V_206 ) ;
F_4 ( V_2 , V_207 , V_208 ) ;
F_4 ( V_2 , V_209 ,
V_210 | V_211 ) ;
F_4 ( V_2 , V_212 ,
V_213 | V_211 ) ;
F_4 ( V_2 , V_214 ,
V_215 | V_211 ) ;
F_54 ( V_2 ) ;
F_13 ( V_2 , V_190 , V_216 ,
V_216 ) ;
F_22 ( V_2 ) ;
V_195:
return V_24 ;
}
static int F_61 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_131 ) ;
return 0 ;
}
static int F_62 ( struct V_217 * V_218 ,
const struct V_219 * V_138 )
{
struct V_42 * V_43 ;
int V_24 ;
V_43 = F_63 ( & V_218 -> V_83 , sizeof( struct V_42 ) ,
V_172 ) ;
if ( V_43 == NULL )
return - V_220 ;
V_43 -> V_221 = V_138 -> V_222 ;
F_64 ( V_218 , V_43 ) ;
V_43 -> V_137 = V_218 -> V_83 . V_223 ;
V_24 = F_65 ( & V_218 -> V_83 , & V_224 ,
V_225 , F_24 ( V_225 ) ) ;
return V_24 ;
}
static int T_3 F_66 ( struct V_217 * V_226 )
{
F_67 ( & V_226 -> V_83 ) ;
return 0 ;
}
static int T_4 F_68 ( void )
{
int V_24 ;
V_24 = F_69 ( & V_227 ) ;
if ( V_24 )
F_70 ( L_19 , V_24 ) ;
return V_24 ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_227 ) ;
}
