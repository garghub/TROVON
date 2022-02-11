static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] . V_5 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] . V_6 ;
}
static void F_3 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 , T_1 * V_11 )
{
unsigned int V_12 ;
unsigned int V_13 ;
if ( F_4 ( V_10 > 4 ) ||
F_4 ( V_9 > 1 ) )
return;
V_12 = V_9 ? V_14 : V_15 ;
V_12 += V_10 * ( V_16 << 1 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
F_5 ( V_8 , V_12 ++ , F_6 ( V_11 [ V_13 ] ) ) ;
F_5 ( V_8 , V_12 ++ , F_7 ( V_11 [ V_13 ] ) ) ;
}
}
static int F_8 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
unsigned int V_23 = V_20 -> V_24 . integer . V_24 [ 0 ] ;
V_22 -> V_25 = V_23 ;
F_11 ( V_8 , V_26 , V_27 ,
( 1 + V_23 ) << V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
V_20 -> V_24 . integer . V_24 [ 0 ] = V_22 -> V_25 ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
unsigned int V_23 = V_20 -> V_24 . integer . V_24 [ 0 ] ;
V_22 -> V_29 = V_23 ;
F_11 ( V_8 , V_30 , V_27 ,
( 1 + V_23 ) << V_28 ) ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
V_20 -> V_24 . integer . V_24 [ 0 ] = V_22 -> V_29 ;
return 0 ;
}
static int F_15 ( struct V_31 * V_32 ,
struct V_17 * V_18 , int V_33 )
{
struct V_7 * V_8 = F_16 ( V_32 -> V_34 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
switch ( V_33 ) {
case V_35 :
if ( V_32 -> V_3 == V_26 ) {
F_11 ( V_8 , V_32 -> V_3 , V_27 ,
( 1 + V_22 -> V_25 ) << V_28 ) ;
} else {
F_11 ( V_8 , V_32 -> V_3 , V_27 ,
( 1 + V_22 -> V_29 ) << V_28 ) ;
}
break;
case V_36 :
F_11 ( V_8 , V_32 -> V_3 , V_27 , 0 ) ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static int F_17 ( struct V_31 * V_32 ,
int V_33 , int line , T_2 V_38 )
{
struct V_7 * V_8 = F_16 ( V_32 -> V_34 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
T_2 * V_39 ;
if ( F_4 ( ! ( V_38 == 1 || V_38 == 2 ) ) )
return - V_37 ;
switch ( line ) {
case V_40 :
V_39 = & V_22 -> V_41 ;
break;
case V_42 :
V_39 = & V_22 -> V_43 ;
break;
default:
return - V_37 ;
}
switch ( V_33 ) {
case V_35 :
* V_39 |= V_38 ;
F_11 ( V_8 , V_32 -> V_3 ,
( 1 << V_32 -> V_44 ) , ( 1 << V_32 -> V_44 ) ) ;
break;
case V_36 :
* V_39 &= ~ V_38 ;
if ( * V_39 == 0 ) {
F_11 ( V_8 , V_32 -> V_3 ,
( 1 << V_32 -> V_44 ) , 0 ) ;
}
break;
default:
return - V_37 ;
}
return 0 ;
}
static int F_18 ( struct V_31 * V_32 ,
struct V_17 * V_45 , int V_33 )
{
return F_17 ( V_32 , V_33 , V_40 , 1 ) ;
}
static int F_19 ( struct V_31 * V_32 ,
struct V_17 * V_45 , int V_33 )
{
return F_17 ( V_32 , V_33 , V_40 , 2 ) ;
}
static int F_20 ( struct V_31 * V_32 ,
struct V_17 * V_45 , int V_33 )
{
return F_17 ( V_32 , V_33 , V_42 , 1 ) ;
}
static int F_21 ( struct V_31 * V_32 ,
struct V_17 * V_45 , int V_33 )
{
return F_17 ( V_32 , V_33 , V_42 , 2 ) ;
}
static inline int F_22 ( int V_46 , T_2 * V_24 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_23 ( V_47 ) ; V_13 ++ ) {
if ( V_47 [ V_13 ] . V_46 >= V_46 ) {
* V_24 = V_47 [ V_13 ] . V_48 ;
return 0 ;
}
}
* V_24 = V_47 [ 0 ] . V_48 ;
return - V_37 ;
}
static int F_24 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_53 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_54 * V_55 ;
unsigned long long V_56 ;
unsigned int V_46 ;
T_2 V_57 ;
V_55 = & V_22 -> V_9 [ 0 ] ;
V_46 = F_25 ( V_52 ) ;
switch ( F_26 ( V_52 ) ) {
case 16 :
F_11 ( V_8 , V_58 ,
V_59 , 0 ) ;
break;
case 24 :
F_11 ( V_8 , V_58 ,
V_59 , V_59 ) ;
break;
default:
return - V_37 ;
}
F_11 ( V_8 , V_60 , V_61 , 0 ) ;
if ( F_22 ( V_46 , & V_57 ) )
return - V_37 ;
F_11 ( V_8 , V_62 ,
V_63 , V_57 ) ;
V_55 -> V_46 = V_46 ;
if ( F_27 ( V_8 , V_58 )
& V_64 ) {
if ( V_22 -> V_65 == 0 ) {
F_28 ( V_8 -> V_2 , L_1 ) ;
return - V_37 ;
}
V_56 = 65536ULL * ( V_46 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_46 ;
F_29 ( V_56 , ( unsigned long long int ) V_22 -> V_65 ) ;
F_5 ( V_8 , V_66 ,
( V_56 >> 8 ) & 0x7F ) ;
F_5 ( V_8 , V_67 ,
V_56 & 0xFF ) ;
}
if ( V_46 < 50000 )
F_11 ( V_8 , V_68 ,
V_69 , 0 ) ;
else
F_11 ( V_8 , V_68 ,
V_69 , V_69 ) ;
F_11 ( V_8 , V_60 , V_61 ,
V_61 ) ;
return 0 ;
}
static int F_30 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_53 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_54 * V_55 ;
unsigned long long V_56 ;
unsigned int V_46 ;
T_2 V_57 ;
V_55 = & V_22 -> V_9 [ 1 ] ;
V_46 = F_25 ( V_52 ) ;
switch ( F_26 ( V_52 ) ) {
case 16 :
F_11 ( V_8 , V_70 ,
V_59 , 0 ) ;
break;
case 24 :
F_11 ( V_8 , V_70 ,
V_59 , V_59 ) ;
break;
default:
return - V_37 ;
}
F_11 ( V_8 , V_60 , V_61 , 0 ) ;
if ( F_22 ( V_46 , & V_57 ) )
return - V_37 ;
F_11 ( V_8 , V_71 ,
V_63 , V_57 ) ;
V_55 -> V_46 = V_46 ;
if ( F_27 ( V_8 , V_70 )
& V_64 ) {
if ( V_22 -> V_65 == 0 ) {
F_28 ( V_8 -> V_2 , L_1 ) ;
return - V_37 ;
}
V_56 = 65536ULL * ( V_46 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_46 ;
F_29 ( V_56 , ( unsigned long long int ) V_22 -> V_65 ) ;
F_5 ( V_8 , V_72 ,
( V_56 >> 8 ) & 0x7F ) ;
F_5 ( V_8 , V_73 ,
V_56 & 0xFF ) ;
}
if ( V_46 < 50000 )
F_11 ( V_8 , V_74 ,
V_69 , 0 ) ;
else
F_11 ( V_8 , V_74 ,
V_69 , V_69 ) ;
F_11 ( V_8 , V_60 , V_61 ,
V_61 ) ;
return 0 ;
}
static int F_31 ( struct V_53 * V_9 ,
int V_75 , unsigned int V_76 , int V_77 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
if ( V_76 == V_22 -> V_65 )
return 0 ;
if ( ( V_76 >= 10000000 ) && ( V_76 < 20000000 ) ) {
F_5 ( V_8 , V_78 , 0x10 ) ;
} else if ( ( V_76 >= 20000000 ) && ( V_76 < 30000000 ) ) {
F_5 ( V_8 , V_78 , 0x20 ) ;
} else {
F_28 ( V_8 -> V_2 , L_2 ) ;
return - V_37 ;
}
if ( F_27 ( V_8 , V_60 ) & V_61 ) {
F_11 ( V_8 , V_60 ,
V_61 , 0 ) ;
F_11 ( V_8 , V_60 ,
V_61 , V_61 ) ;
}
F_32 ( V_9 -> V_2 , L_3 , V_75 , V_76 ) ;
V_22 -> V_65 = V_76 ;
return 0 ;
}
static int F_33 ( struct V_53 * V_79 ,
unsigned int V_80 )
{
struct V_7 * V_8 = V_79 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_54 * V_55 ;
T_2 V_81 ;
T_2 V_82 = 0 ;
V_55 = & V_22 -> V_9 [ 0 ] ;
if ( V_80 != V_55 -> V_80 ) {
V_55 -> V_80 = V_80 ;
switch ( V_80 & V_83 ) {
case V_84 :
F_5 ( V_8 , V_66 ,
0x80 ) ;
F_5 ( V_8 , V_67 ,
0x00 ) ;
break;
case V_85 :
V_82 |= V_64 ;
break;
case V_86 :
case V_87 :
default:
F_28 ( V_8 -> V_2 , L_4 ) ;
return - V_37 ;
}
switch ( V_80 & V_88 ) {
case V_89 :
V_82 |= V_90 ;
break;
case V_91 :
break;
default:
return - V_37 ;
}
switch ( V_80 & V_92 ) {
case V_93 :
break;
case V_94 :
V_82 |= V_95 ;
break;
case V_96 :
V_82 |= V_97 ;
break;
case V_98 :
V_82 |= V_97 | V_95 ;
break;
default:
return - V_37 ;
}
F_11 ( V_8 , V_58 ,
V_64 | V_90 | V_97 |
V_95 , V_82 ) ;
V_81 = V_99 ;
if ( V_22 -> V_100 )
V_81 |= V_101 ;
F_5 ( V_8 , V_102 , V_81 ) ;
}
return 0 ;
}
static int F_34 ( struct V_53 * V_79 ,
unsigned int V_80 )
{
struct V_7 * V_8 = V_79 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_54 * V_55 ;
T_2 V_103 = 0 ;
V_55 = & V_22 -> V_9 [ 1 ] ;
if ( V_80 != V_55 -> V_80 ) {
V_55 -> V_80 = V_80 ;
switch ( V_80 & V_83 ) {
case V_84 :
F_5 ( V_8 , V_72 ,
0x80 ) ;
F_5 ( V_8 , V_73 ,
0x00 ) ;
break;
case V_85 :
V_103 |= V_64 ;
break;
case V_86 :
case V_87 :
default:
F_28 ( V_8 -> V_2 , L_4 ) ;
return - V_37 ;
}
switch ( V_80 & V_88 ) {
case V_89 :
V_103 |= V_90 ;
break;
case V_91 :
break;
default:
return - V_37 ;
}
switch ( V_80 & V_92 ) {
case V_93 :
break;
case V_94 :
V_103 |= V_95 ;
break;
case V_96 :
V_103 |= V_97 ;
break;
case V_98 :
V_103 |= V_97 | V_95 ;
break;
default:
return - V_37 ;
}
F_11 ( V_8 , V_70 ,
V_64 | V_90 | V_97 |
V_95 , V_103 ) ;
F_5 ( V_8 , V_104 ,
V_99 ) ;
}
return 0 ;
}
static int F_35 ( struct V_53 * V_79 , int V_105 )
{
struct V_7 * V_8 = V_79 -> V_8 ;
int V_3 ;
if ( V_105 )
V_3 = V_106 ;
else
V_3 = 0 ;
F_11 ( V_8 , V_107 ,
V_108 , V_3 ) ;
return 0 ;
}
static int F_36 ( struct V_53 * V_79 , int V_105 )
{
struct V_7 * V_8 = V_79 -> V_8 ;
int V_3 ;
if ( V_105 )
V_3 = V_106 ;
else
V_3 = 0 ;
F_11 ( V_8 , V_109 ,
V_108 , V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_7 * V_8 ,
enum V_110 V_111 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
switch ( V_111 ) {
case V_112 :
break;
case V_113 :
break;
case V_114 :
if ( F_38 ( V_8 ) == V_115 )
F_39 ( V_22 -> V_116 ) ;
F_11 ( V_8 , V_117 ,
V_118 , V_118 ) ;
break;
case V_115 :
F_11 ( V_8 , V_117 ,
V_118 , 0 ) ;
F_40 ( V_22 -> V_116 ) ;
break;
}
return 0 ;
}
static int F_41 ( struct V_7 * V_8 , const char * V_119 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_23 ( V_120 ) ; V_13 ++ )
if ( strcmp ( V_119 , V_120 [ V_13 ] ) == 0 )
return V_13 ;
F_28 ( V_8 -> V_2 , L_5 , V_119 ) ;
return - V_37 ;
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_121 * V_122 = V_22 -> V_122 ;
struct V_123 * V_124 ;
int V_125 , V_126 , V_127 , V_13 , V_23 , V_128 ;
struct V_54 * V_55 ;
V_55 = & V_22 -> V_9 [ 0 ] ;
if ( ! V_122 || ! V_22 -> V_129 )
return;
V_128 = V_55 -> V_46 ;
V_23 = V_55 -> V_130 ;
V_125 = 0 ;
V_126 = V_131 ;
for ( V_13 = 0 ; V_13 < V_122 -> V_132 ; V_13 ++ ) {
if ( strcmp ( V_122 -> V_133 [ V_13 ] . V_119 , V_22 -> V_134 [ V_23 ] ) == 0 &&
abs ( V_122 -> V_133 [ V_13 ] . V_46 - V_128 ) < V_126 ) {
V_125 = V_13 ;
V_126 = abs ( V_122 -> V_133 [ V_13 ] . V_46 - V_128 ) ;
}
}
F_32 ( V_8 -> V_2 , L_6 ,
V_122 -> V_133 [ V_125 ] . V_119 ,
V_122 -> V_133 [ V_125 ] . V_46 , V_128 ) ;
V_127 = F_27 ( V_8 , V_135 ) ;
F_11 ( V_8 , V_135 , V_136 , 0 ) ;
V_124 = & V_122 -> V_133 [ V_23 ] ;
F_3 ( V_8 , 0 , 0 , V_124 -> V_137 ) ;
F_3 ( V_8 , 0 , 1 , V_124 -> V_138 ) ;
F_3 ( V_8 , 0 , 2 , V_124 -> V_139 ) ;
F_3 ( V_8 , 0 , 3 , V_124 -> V_140 ) ;
F_3 ( V_8 , 0 , 4 , V_124 -> V_141 ) ;
F_11 ( V_8 , V_135 , V_136 , V_127 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_121 * V_122 = V_22 -> V_122 ;
struct V_123 * V_124 ;
int V_125 , V_126 , V_127 , V_13 , V_23 , V_128 ;
struct V_54 * V_55 ;
V_55 = & V_22 -> V_9 [ 1 ] ;
if ( ! V_122 || ! V_22 -> V_129 )
return;
V_128 = V_55 -> V_46 ;
V_23 = V_55 -> V_130 ;
V_125 = 0 ;
V_126 = V_131 ;
for ( V_13 = 0 ; V_13 < V_122 -> V_132 ; V_13 ++ ) {
if ( strcmp ( V_122 -> V_133 [ V_13 ] . V_119 , V_22 -> V_134 [ V_23 ] ) == 0 &&
abs ( V_122 -> V_133 [ V_13 ] . V_46 - V_128 ) < V_126 ) {
V_125 = V_13 ;
V_126 = abs ( V_122 -> V_133 [ V_13 ] . V_46 - V_128 ) ;
}
}
F_32 ( V_8 -> V_2 , L_6 ,
V_122 -> V_133 [ V_125 ] . V_119 ,
V_122 -> V_133 [ V_125 ] . V_46 , V_128 ) ;
V_127 = F_27 ( V_8 , V_135 ) ;
F_11 ( V_8 , V_135 , V_142 , 0 ) ;
V_124 = & V_122 -> V_133 [ V_23 ] ;
F_3 ( V_8 , 1 , 0 , V_124 -> V_137 ) ;
F_3 ( V_8 , 1 , 1 , V_124 -> V_138 ) ;
F_3 ( V_8 , 1 , 2 , V_124 -> V_139 ) ;
F_3 ( V_8 , 1 , 3 , V_124 -> V_140 ) ;
F_3 ( V_8 , 1 , 4 , V_124 -> V_141 ) ;
F_11 ( V_8 , V_135 , V_142 ,
V_127 ) ;
}
static int F_44 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_121 * V_122 = V_22 -> V_122 ;
int V_38 = F_41 ( V_8 , V_18 -> V_143 . V_119 ) ;
struct V_54 * V_55 ;
int V_23 = V_20 -> V_24 . integer . V_24 [ 0 ] ;
if ( V_38 < 0 )
return V_38 ;
V_55 = & V_22 -> V_9 [ V_38 ] ;
if ( V_23 >= V_122 -> V_132 )
return - V_37 ;
V_55 -> V_130 = V_23 ;
switch ( V_38 ) {
case 0 :
F_42 ( V_8 ) ;
break;
case 1 :
F_43 ( V_8 ) ;
break;
}
return 0 ;
}
static int F_45 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
int V_38 = F_41 ( V_8 , V_18 -> V_143 . V_119 ) ;
struct V_54 * V_55 ;
if ( V_38 < 0 )
return V_38 ;
V_55 = & V_22 -> V_9 [ V_38 ] ;
V_20 -> V_24 . V_144 . V_145 [ 0 ] = V_55 -> V_130 ;
return 0 ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_121 * V_122 = V_22 -> V_122 ;
struct V_123 * V_146 ;
unsigned int V_147 ;
int V_13 , V_148 ;
const char * * V_149 ;
int V_150 ;
struct V_151 V_152 [] = {
F_47 ( ( char * ) V_120 [ 0 ] ,
V_22 -> V_153 ,
F_45 ,
F_44 ) ,
F_47 ( ( char * ) V_120 [ 1 ] ,
V_22 -> V_153 ,
F_45 ,
F_44 ) ,
} ;
F_48 ( F_23 ( V_152 ) != F_23 ( V_120 ) ) ;
V_146 = V_122 -> V_133 ;
V_147 = V_122 -> V_132 ;
V_22 -> V_129 = 0 ;
V_22 -> V_134 = NULL ;
for ( V_13 = 0 ; V_13 < V_147 ; V_13 ++ ) {
for ( V_148 = 0 ; V_148 < V_22 -> V_129 ; V_148 ++ ) {
if ( strcmp ( V_146 [ V_13 ] . V_119 , V_22 -> V_134 [ V_148 ] ) == 0 )
break;
}
if ( V_148 != V_22 -> V_129 )
continue;
V_149 = F_49 ( V_22 -> V_134 ,
sizeof( char * ) * ( V_22 -> V_129 + 1 ) ,
V_154 ) ;
if ( V_149 == NULL )
continue;
V_149 [ V_22 -> V_129 ] = V_146 [ V_13 ] . V_119 ;
V_22 -> V_129 ++ ;
V_22 -> V_134 = V_149 ;
}
V_22 -> V_153 . V_155 = V_22 -> V_134 ;
V_22 -> V_153 . V_156 = V_22 -> V_129 ;
V_150 = F_50 ( V_8 , V_152 , F_23 ( V_152 ) ) ;
if ( V_150 != 0 )
F_28 ( V_8 -> V_2 , L_7 , V_150 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_121 * V_122 = V_22 -> V_122 ;
T_2 V_57 = 0 ;
if ( ! V_122 ) {
F_32 ( V_8 -> V_2 , L_8 ) ;
return;
}
if ( V_122 -> V_157 )
V_57 |= V_158 ;
if ( V_122 -> V_159 )
V_57 |= V_160 ;
V_22 -> V_100 = ( V_57 ? 1 : 0 ) ;
F_5 ( V_8 , V_161 , V_57 ) ;
V_57 = ( ( V_122 -> V_162 ) ? V_163 : 0 ) ;
F_11 ( V_8 , V_164 ,
V_165 , V_57 ) ;
if ( V_122 -> V_132 )
F_46 ( V_8 ) ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_54 * V_55 ;
int V_150 = 0 ;
F_40 ( V_22 -> V_116 ) ;
V_22 -> V_65 = ( unsigned ) - 1 ;
V_22 -> V_129 = 0 ;
V_55 = & V_22 -> V_9 [ 0 ] ;
V_55 -> V_46 = ( unsigned ) - 1 ;
V_55 -> V_80 = ( unsigned ) - 1 ;
V_55 -> V_130 = 0 ;
V_55 = & V_22 -> V_9 [ 1 ] ;
V_55 -> V_46 = ( unsigned ) - 1 ;
V_55 -> V_80 = ( unsigned ) - 1 ;
V_55 -> V_130 = 0 ;
V_22 -> V_41 = 0 ;
V_22 -> V_43 = 0 ;
V_22 -> V_166 = 0 ;
V_22 -> V_100 = 0 ;
V_22 -> V_25 = 0 ;
V_22 -> V_29 = 0 ;
V_150 = F_27 ( V_8 , V_167 ) ;
if ( V_150 < 0 ) {
F_28 ( V_8 -> V_2 , L_9 ,
V_150 ) ;
goto V_168;
}
F_53 ( V_8 -> V_2 , L_10 , V_150 - 0x40 + 'A' ) ;
F_5 ( V_8 , V_60 , V_169 ) ;
F_5 ( V_8 , V_170 , 0x00 ) ;
F_5 ( V_8 , V_171 ,
V_172 | V_173 |
V_174 | V_175 ) ;
F_5 ( V_8 , V_176 , 0xF0 ) ;
F_5 ( V_8 , V_177 , 0x0F ) ;
F_5 ( V_8 , V_178 ,
V_179 | V_180 ) ;
F_5 ( V_8 , V_181 ,
V_182 | V_180 ) ;
F_51 ( V_8 ) ;
V_168:
return V_150 ;
}
static int F_54 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
F_55 ( V_22 -> V_134 ) ;
return 0 ;
}
static int F_56 ( struct V_183 * V_184 ,
const struct V_185 * V_143 )
{
struct V_21 * V_22 ;
int V_150 ;
V_22 = F_57 ( & V_184 -> V_2 , sizeof( struct V_21 ) ,
V_154 ) ;
if ( V_22 == NULL )
return - V_186 ;
V_22 -> V_116 = F_58 ( V_184 , & V_187 ) ;
if ( F_59 ( V_22 -> V_116 ) )
return F_60 ( V_22 -> V_116 ) ;
V_22 -> V_188 = V_143 -> V_189 ;
F_61 ( V_184 , V_22 ) ;
V_22 -> V_122 = V_184 -> V_2 . V_190 ;
V_150 = F_62 ( & V_184 -> V_2 ,
& V_191 , & V_192 [ 0 ] , 2 ) ;
return V_150 ;
}
static int F_63 ( struct V_183 * V_193 )
{
F_64 ( & V_193 -> V_2 ) ;
return 0 ;
}
