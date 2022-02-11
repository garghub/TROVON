static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] . V_5 ;
}
static void F_2 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_7 , T_1 * V_8 )
{
unsigned int V_9 ;
unsigned int V_10 ;
F_3 ( V_7 > 4 ) ;
F_3 ( V_6 > 1 ) ;
V_9 = V_6 ? V_11 : V_12 ;
V_9 += V_7 * ( V_13 << 1 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
F_4 ( V_2 , V_9 ++ , F_5 ( V_8 [ V_10 ] ) ) ;
F_4 ( V_2 , V_9 ++ , F_6 ( V_8 [ V_10 ] ) ) ;
}
}
static int F_7 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
unsigned int V_20 = V_17 -> V_21 . integer . V_21 [ 0 ] ;
V_19 -> V_22 = V_20 ;
F_10 ( V_2 , V_23 , V_24 ,
( 1 + V_20 ) << V_25 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
V_17 -> V_21 . integer . V_21 [ 0 ] = V_19 -> V_22 ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
unsigned int V_20 = V_17 -> V_21 . integer . V_21 [ 0 ] ;
V_19 -> V_26 = V_20 ;
F_10 ( V_2 , V_27 , V_24 ,
( 1 + V_20 ) << V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
V_17 -> V_21 . integer . V_21 [ 0 ] = V_19 -> V_26 ;
return 0 ;
}
static int F_14 ( struct V_28 * V_29 ,
struct V_14 * V_15 , int V_30 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
switch ( V_30 ) {
case V_31 :
if ( V_29 -> V_3 == V_23 ) {
F_10 ( V_2 , V_29 -> V_3 , V_24 ,
( 1 + V_19 -> V_22 ) << V_25 ) ;
} else {
F_10 ( V_2 , V_29 -> V_3 , V_24 ,
( 1 + V_19 -> V_26 ) << V_25 ) ;
}
break;
case V_32 :
F_10 ( V_2 , V_29 -> V_3 , V_24 , 0 ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_15 ( struct V_28 * V_29 ,
int V_30 , int line , T_2 V_34 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
T_2 * V_35 ;
F_3 ( ! ( ( V_34 == 1 ) || ( V_34 == 2 ) ) ) ;
switch ( line ) {
case V_36 :
V_35 = & V_19 -> V_37 ;
break;
case V_38 :
V_35 = & V_19 -> V_39 ;
break;
default:
return - V_33 ;
}
switch ( V_30 ) {
case V_31 :
* V_35 |= V_34 ;
F_10 ( V_2 , V_29 -> V_3 ,
( 1 << V_29 -> V_40 ) , ( 1 << V_29 -> V_40 ) ) ;
break;
case V_32 :
* V_35 &= ~ V_34 ;
if ( * V_35 == 0 ) {
F_10 ( V_2 , V_29 -> V_3 ,
( 1 << V_29 -> V_40 ) , 0 ) ;
}
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_16 ( struct V_28 * V_29 ,
struct V_14 * V_41 , int V_30 )
{
return F_15 ( V_29 , V_30 , V_36 , 1 ) ;
}
static int F_17 ( struct V_28 * V_29 ,
struct V_14 * V_41 , int V_30 )
{
return F_15 ( V_29 , V_30 , V_36 , 2 ) ;
}
static int F_18 ( struct V_28 * V_29 ,
struct V_14 * V_41 , int V_30 )
{
return F_15 ( V_29 , V_30 , V_38 , 1 ) ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_14 * V_41 , int V_30 )
{
return F_15 ( V_29 , V_30 , V_38 , 2 ) ;
}
static inline int F_20 ( int V_42 , T_2 * V_21 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_21 ( V_43 ) ; V_10 ++ ) {
if ( V_43 [ V_10 ] . V_42 >= V_42 ) {
* V_21 = V_43 [ V_10 ] . V_44 ;
return 0 ;
}
}
* V_21 = V_43 [ 0 ] . V_44 ;
return - V_33 ;
}
static int F_22 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_50 * V_51 ;
unsigned long long V_52 ;
unsigned int V_42 ;
T_2 V_53 ;
V_51 = & V_19 -> V_6 [ 0 ] ;
V_42 = F_23 ( V_48 ) ;
switch ( F_24 ( V_48 ) ) {
case V_54 :
F_10 ( V_2 , V_55 ,
V_56 , 0 ) ;
break;
case V_57 :
F_10 ( V_2 , V_55 ,
V_56 , V_56 ) ;
break;
default:
return - V_33 ;
}
F_10 ( V_2 , V_58 , V_59 , 0 ) ;
if ( F_20 ( V_42 , & V_53 ) )
return - V_33 ;
F_10 ( V_2 , V_60 ,
V_61 , V_53 ) ;
V_51 -> V_42 = V_42 ;
if ( F_25 ( V_2 , V_55 )
& V_62 ) {
if ( V_19 -> V_63 == 0 ) {
F_26 ( V_2 -> V_64 , L_1 ) ;
return - V_33 ;
}
V_52 = 65536ULL * ( V_42 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_42 ;
F_27 ( V_52 , ( unsigned long long int ) V_19 -> V_63 ) ;
F_4 ( V_2 , V_65 ,
( V_52 >> 8 ) & 0x7F ) ;
F_4 ( V_2 , V_66 ,
V_52 & 0xFF ) ;
}
if ( V_42 < 50000 )
F_10 ( V_2 , V_67 ,
V_68 , 0 ) ;
else
F_10 ( V_2 , V_67 ,
V_68 , V_68 ) ;
F_10 ( V_2 , V_58 , V_59 ,
V_59 ) ;
return 0 ;
}
static int F_28 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_50 * V_51 ;
unsigned long long V_52 ;
unsigned int V_42 ;
T_2 V_53 ;
V_51 = & V_19 -> V_6 [ 1 ] ;
V_42 = F_23 ( V_48 ) ;
switch ( F_24 ( V_48 ) ) {
case V_54 :
F_10 ( V_2 , V_69 ,
V_56 , 0 ) ;
break;
case V_57 :
F_10 ( V_2 , V_69 ,
V_56 , V_56 ) ;
break;
default:
return - V_33 ;
}
F_10 ( V_2 , V_58 , V_59 , 0 ) ;
if ( F_20 ( V_42 , & V_53 ) )
return - V_33 ;
F_10 ( V_2 , V_70 ,
V_61 , V_53 ) ;
V_51 -> V_42 = V_42 ;
if ( F_25 ( V_2 , V_69 )
& V_62 ) {
if ( V_19 -> V_63 == 0 ) {
F_26 ( V_2 -> V_64 , L_1 ) ;
return - V_33 ;
}
V_52 = 65536ULL * ( V_42 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_42 ;
F_27 ( V_52 , ( unsigned long long int ) V_19 -> V_63 ) ;
F_4 ( V_2 , V_71 ,
( V_52 >> 8 ) & 0x7F ) ;
F_4 ( V_2 , V_72 ,
V_52 & 0xFF ) ;
}
if ( V_42 < 50000 )
F_10 ( V_2 , V_73 ,
V_68 , 0 ) ;
else
F_10 ( V_2 , V_73 ,
V_68 , V_68 ) ;
F_10 ( V_2 , V_58 , V_59 ,
V_59 ) ;
return 0 ;
}
static int F_29 ( struct V_49 * V_6 ,
int V_74 , unsigned int V_75 , int V_76 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
if ( V_75 == V_19 -> V_63 )
return 0 ;
if ( ( V_75 >= 10000000 ) && ( V_75 < 20000000 ) ) {
F_4 ( V_2 , V_77 , 0x10 ) ;
} else if ( ( V_75 >= 20000000 ) && ( V_75 < 30000000 ) ) {
F_4 ( V_2 , V_77 , 0x20 ) ;
} else {
F_26 ( V_2 -> V_64 , L_2 ) ;
return - V_33 ;
}
if ( F_25 ( V_2 , V_58 ) & V_59 ) {
F_10 ( V_2 , V_58 ,
V_59 , 0 ) ;
F_10 ( V_2 , V_58 ,
V_59 , V_59 ) ;
}
F_30 ( V_6 -> V_64 , L_3 , V_74 , V_75 ) ;
V_19 -> V_63 = V_75 ;
return 0 ;
}
static int F_31 ( struct V_49 * V_78 ,
unsigned int V_79 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_50 * V_51 ;
T_2 V_80 ;
T_2 V_81 = 0 ;
V_51 = & V_19 -> V_6 [ 0 ] ;
if ( V_79 != V_51 -> V_79 ) {
V_51 -> V_79 = V_79 ;
switch ( V_79 & V_82 ) {
case V_83 :
F_4 ( V_2 , V_65 ,
0x80 ) ;
F_4 ( V_2 , V_66 ,
0x00 ) ;
break;
case V_84 :
V_81 |= V_62 ;
break;
case V_85 :
case V_86 :
default:
F_26 ( V_2 -> V_64 , L_4 ) ;
return - V_33 ;
}
switch ( V_79 & V_87 ) {
case V_88 :
V_81 |= V_89 ;
break;
case V_90 :
break;
default:
return - V_33 ;
}
switch ( V_79 & V_91 ) {
case V_92 :
break;
case V_93 :
V_81 |= V_94 ;
break;
case V_95 :
V_81 |= V_96 ;
break;
case V_97 :
V_81 |= V_96 | V_94 ;
break;
default:
return - V_33 ;
}
F_10 ( V_2 , V_55 ,
V_62 | V_89 | V_96 |
V_94 , V_81 ) ;
V_80 = V_98 ;
if ( V_19 -> V_99 )
V_80 |= V_100 ;
F_4 ( V_2 , V_101 , V_80 ) ;
}
return 0 ;
}
static int F_32 ( struct V_49 * V_78 ,
unsigned int V_79 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_50 * V_51 ;
T_2 V_102 = 0 ;
V_51 = & V_19 -> V_6 [ 1 ] ;
if ( V_79 != V_51 -> V_79 ) {
V_51 -> V_79 = V_79 ;
switch ( V_79 & V_82 ) {
case V_83 :
F_4 ( V_2 , V_71 ,
0x80 ) ;
F_4 ( V_2 , V_72 ,
0x00 ) ;
break;
case V_84 :
V_102 |= V_62 ;
break;
case V_85 :
case V_86 :
default:
F_26 ( V_2 -> V_64 , L_4 ) ;
return - V_33 ;
}
switch ( V_79 & V_87 ) {
case V_88 :
V_102 |= V_89 ;
break;
case V_90 :
break;
default:
return - V_33 ;
}
switch ( V_79 & V_91 ) {
case V_92 :
break;
case V_93 :
V_102 |= V_94 ;
break;
case V_95 :
V_102 |= V_96 ;
break;
case V_97 :
V_102 |= V_96 | V_94 ;
break;
default:
return - V_33 ;
}
F_10 ( V_2 , V_69 ,
V_62 | V_89 | V_96 |
V_94 , V_102 ) ;
F_4 ( V_2 , V_103 ,
V_98 ) ;
}
return 0 ;
}
static int F_33 ( struct V_49 * V_78 , int V_104 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
int V_3 ;
if ( V_104 )
V_3 = V_105 ;
else
V_3 = 0 ;
F_10 ( V_2 , V_106 ,
V_107 , V_3 ) ;
return 0 ;
}
static int F_34 ( struct V_49 * V_78 , int V_104 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
int V_3 ;
if ( V_104 )
V_3 = V_105 ;
else
V_3 = 0 ;
F_10 ( V_2 , V_108 ,
V_107 , V_3 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 * V_109 = V_2 -> V_109 ;
int V_10 ;
if ( ! V_2 -> V_110 )
return;
V_2 -> V_111 = 0 ;
for ( V_10 = 1 ; V_10 < V_2 -> V_112 -> V_113 ; V_10 ++ ) {
if ( ! V_4 [ V_10 ] . V_114 )
continue;
if ( V_109 [ V_10 ] == V_115 [ V_10 ] )
continue;
F_4 ( V_2 , V_10 , V_109 [ V_10 ] ) ;
}
V_2 -> V_110 = 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
enum V_116 V_117 )
{
switch ( V_117 ) {
case V_118 :
break;
case V_119 :
break;
case V_120 :
if ( V_2 -> V_121 . V_122 == V_123 )
F_35 ( V_2 ) ;
F_10 ( V_2 , V_124 ,
V_125 , V_125 ) ;
break;
case V_123 :
F_10 ( V_2 , V_124 ,
V_125 , 0 ) ;
V_2 -> V_110 = 1 ;
break;
}
V_2 -> V_121 . V_122 = V_117 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , const char * V_126 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_21 ( V_127 ) ; V_10 ++ )
if ( strcmp ( V_126 , V_127 [ V_10 ] ) == 0 )
return V_10 ;
F_26 ( V_2 -> V_64 , L_5 , V_126 ) ;
return - V_33 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_128 * V_129 = V_19 -> V_129 ;
struct V_130 * V_131 ;
int V_132 , V_133 , V_134 , V_10 , V_20 , V_135 ;
struct V_50 * V_51 ;
V_51 = & V_19 -> V_6 [ 0 ] ;
if ( ! V_129 || ! V_19 -> V_136 )
return;
V_135 = V_51 -> V_42 ;
V_20 = V_51 -> V_137 ;
V_132 = 0 ;
V_133 = V_138 ;
for ( V_10 = 0 ; V_10 < V_129 -> V_139 ; V_10 ++ ) {
if ( strcmp ( V_129 -> V_140 [ V_10 ] . V_126 , V_19 -> V_141 [ V_20 ] ) == 0 &&
abs ( V_129 -> V_140 [ V_10 ] . V_42 - V_135 ) < V_133 ) {
V_132 = V_10 ;
V_133 = abs ( V_129 -> V_140 [ V_10 ] . V_42 - V_135 ) ;
}
}
F_30 ( V_2 -> V_64 , L_6 ,
V_129 -> V_140 [ V_132 ] . V_126 ,
V_129 -> V_140 [ V_132 ] . V_42 , V_135 ) ;
V_134 = F_25 ( V_2 , V_142 ) ;
F_10 ( V_2 , V_142 , V_143 , 0 ) ;
V_131 = & V_129 -> V_140 [ V_20 ] ;
F_2 ( V_2 , 0 , 0 , V_131 -> V_144 ) ;
F_2 ( V_2 , 0 , 1 , V_131 -> V_145 ) ;
F_2 ( V_2 , 0 , 2 , V_131 -> V_146 ) ;
F_2 ( V_2 , 0 , 3 , V_131 -> V_147 ) ;
F_2 ( V_2 , 0 , 4 , V_131 -> V_148 ) ;
F_10 ( V_2 , V_142 , V_143 , V_134 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_128 * V_129 = V_19 -> V_129 ;
struct V_130 * V_131 ;
int V_132 , V_133 , V_134 , V_10 , V_20 , V_135 ;
struct V_50 * V_51 ;
V_51 = & V_19 -> V_6 [ 1 ] ;
if ( ! V_129 || ! V_19 -> V_136 )
return;
V_135 = V_51 -> V_42 ;
V_20 = V_51 -> V_137 ;
V_132 = 0 ;
V_133 = V_138 ;
for ( V_10 = 0 ; V_10 < V_129 -> V_139 ; V_10 ++ ) {
if ( strcmp ( V_129 -> V_140 [ V_10 ] . V_126 , V_19 -> V_141 [ V_20 ] ) == 0 &&
abs ( V_129 -> V_140 [ V_10 ] . V_42 - V_135 ) < V_133 ) {
V_132 = V_10 ;
V_133 = abs ( V_129 -> V_140 [ V_10 ] . V_42 - V_135 ) ;
}
}
F_30 ( V_2 -> V_64 , L_6 ,
V_129 -> V_140 [ V_132 ] . V_126 ,
V_129 -> V_140 [ V_132 ] . V_42 , V_135 ) ;
V_134 = F_25 ( V_2 , V_142 ) ;
F_10 ( V_2 , V_142 , V_149 , 0 ) ;
V_131 = & V_129 -> V_140 [ V_20 ] ;
F_2 ( V_2 , 1 , 0 , V_131 -> V_144 ) ;
F_2 ( V_2 , 1 , 1 , V_131 -> V_145 ) ;
F_2 ( V_2 , 1 , 2 , V_131 -> V_146 ) ;
F_2 ( V_2 , 1 , 3 , V_131 -> V_147 ) ;
F_2 ( V_2 , 1 , 4 , V_131 -> V_148 ) ;
F_10 ( V_2 , V_142 , V_149 ,
V_134 ) ;
}
static int F_40 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_128 * V_129 = V_19 -> V_129 ;
int V_34 = F_37 ( V_2 , V_15 -> V_150 . V_126 ) ;
struct V_50 * V_51 ;
int V_20 = V_17 -> V_21 . integer . V_21 [ 0 ] ;
if ( V_34 < 0 )
return V_34 ;
V_51 = & V_19 -> V_6 [ V_34 ] ;
if ( V_20 >= V_129 -> V_139 )
return - V_33 ;
V_51 -> V_137 = V_20 ;
switch ( V_34 ) {
case 0 :
F_38 ( V_2 ) ;
break;
case 1 :
F_39 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_41 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
int V_34 = F_37 ( V_2 , V_15 -> V_150 . V_126 ) ;
struct V_50 * V_51 ;
if ( V_34 < 0 )
return V_34 ;
V_51 = & V_19 -> V_6 [ V_34 ] ;
V_17 -> V_21 . V_151 . V_152 [ 0 ] = V_51 -> V_137 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_128 * V_129 = V_19 -> V_129 ;
struct V_130 * V_153 ;
unsigned int V_154 ;
int V_10 , V_155 ;
const char * * V_156 ;
int V_157 ;
struct V_158 V_159 [] = {
F_43 ( ( char * ) V_127 [ 0 ] ,
V_19 -> V_160 ,
F_41 ,
F_40 ) ,
F_43 ( ( char * ) V_127 [ 1 ] ,
V_19 -> V_160 ,
F_41 ,
F_40 ) ,
} ;
F_44 ( F_21 ( V_159 ) != F_21 ( V_127 ) ) ;
V_153 = V_129 -> V_140 ;
V_154 = V_129 -> V_139 ;
V_19 -> V_136 = 0 ;
V_19 -> V_141 = NULL ;
for ( V_10 = 0 ; V_10 < V_154 ; V_10 ++ ) {
for ( V_155 = 0 ; V_155 < V_19 -> V_136 ; V_155 ++ ) {
if ( strcmp ( V_153 [ V_10 ] . V_126 , V_19 -> V_141 [ V_155 ] ) == 0 )
break;
}
if ( V_155 != V_19 -> V_136 )
continue;
V_156 = F_45 ( V_19 -> V_141 ,
sizeof( char * ) * ( V_19 -> V_136 + 1 ) ,
V_161 ) ;
if ( V_156 == NULL )
continue;
V_156 [ V_19 -> V_136 ] = V_153 [ V_10 ] . V_126 ;
V_19 -> V_136 ++ ;
V_19 -> V_141 = V_156 ;
}
V_19 -> V_160 . V_162 = V_19 -> V_141 ;
V_19 -> V_160 . V_163 = V_19 -> V_136 ;
V_157 = F_46 ( V_2 , V_159 , F_21 ( V_159 ) ) ;
if ( V_157 != 0 )
F_26 ( V_2 -> V_64 , L_7 , V_157 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_128 * V_129 = V_19 -> V_129 ;
T_2 V_53 = 0 ;
if ( ! V_129 ) {
F_30 ( V_2 -> V_64 , L_8 ) ;
return;
}
if ( V_129 -> V_164 )
V_53 |= V_165 ;
if ( V_129 -> V_166 )
V_53 |= V_167 ;
V_19 -> V_99 = ( V_53 ? 1 : 0 ) ;
F_4 ( V_2 , V_168 , V_53 ) ;
V_53 = ( ( V_129 -> V_169 ) ? V_170 : 0 ) ;
F_10 ( V_2 , V_171 ,
V_172 , V_53 ) ;
if ( V_129 -> V_139 )
F_42 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_3 V_35 )
{
F_36 ( V_2 , V_123 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_36 ( V_2 , V_120 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_50 * V_51 ;
int V_157 = 0 ;
V_2 -> V_110 = 1 ;
V_157 = F_51 ( V_2 , 8 , 8 , V_173 ) ;
if ( V_157 != 0 ) {
F_26 ( V_2 -> V_64 , L_9 , V_157 ) ;
return V_157 ;
}
V_19 -> V_63 = ( unsigned ) - 1 ;
V_19 -> V_136 = 0 ;
V_51 = & V_19 -> V_6 [ 0 ] ;
V_51 -> V_42 = ( unsigned ) - 1 ;
V_51 -> V_79 = ( unsigned ) - 1 ;
V_51 -> V_137 = 0 ;
V_51 = & V_19 -> V_6 [ 1 ] ;
V_51 -> V_42 = ( unsigned ) - 1 ;
V_51 -> V_79 = ( unsigned ) - 1 ;
V_51 -> V_137 = 0 ;
V_19 -> V_37 = 0 ;
V_19 -> V_39 = 0 ;
V_19 -> V_174 = 0 ;
V_19 -> V_99 = 0 ;
V_19 -> V_22 = 0 ;
V_19 -> V_26 = 0 ;
V_157 = F_25 ( V_2 , V_175 ) ;
if ( V_157 < 0 ) {
F_26 ( V_2 -> V_64 , L_10 ,
V_157 ) ;
goto V_176;
}
F_52 ( V_2 -> V_64 , L_11 , V_157 + 'A' ) ;
F_4 ( V_2 , V_58 , V_177 ) ;
F_36 ( V_2 , V_120 ) ;
F_4 ( V_2 , V_178 , 0x00 ) ;
F_4 ( V_2 , V_179 ,
V_180 | V_181 |
V_182 | V_183 ) ;
F_4 ( V_2 , V_184 , 0xF0 ) ;
F_4 ( V_2 , V_185 , 0x0F ) ;
F_4 ( V_2 , V_186 ,
V_187 | V_188 ) ;
F_4 ( V_2 , V_189 ,
V_190 | V_188 ) ;
F_47 ( V_2 ) ;
F_46 ( V_2 , V_191 ,
F_21 ( V_191 ) ) ;
V_176:
return V_157 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
F_36 ( V_2 , V_123 ) ;
F_54 ( V_19 -> V_141 ) ;
return 0 ;
}
static int F_55 ( struct V_192 * V_193 ,
const struct V_194 * V_150 )
{
struct V_18 * V_19 ;
int V_157 ;
V_19 = F_56 ( sizeof( struct V_18 ) , V_161 ) ;
if ( V_19 == NULL )
return - V_195 ;
V_19 -> V_196 = V_150 -> V_197 ;
F_57 ( V_193 , V_19 ) ;
V_19 -> V_129 = V_193 -> V_64 . V_198 ;
V_157 = F_58 ( & V_193 -> V_64 ,
& V_199 , & V_200 [ 0 ] , 2 ) ;
if ( V_157 < 0 )
F_54 ( V_19 ) ;
return V_157 ;
}
static int T_4 F_59 ( struct V_192 * V_201 )
{
F_60 ( & V_201 -> V_64 ) ;
F_54 ( F_61 ( V_201 ) ) ;
return 0 ;
}
static int T_5 F_62 ( void )
{
int V_157 ;
V_157 = F_63 ( & V_202 ) ;
if ( V_157 )
F_64 ( L_12 , V_157 ) ;
return V_157 ;
}
static void T_6 F_65 ( void )
{
F_66 ( & V_202 ) ;
}
