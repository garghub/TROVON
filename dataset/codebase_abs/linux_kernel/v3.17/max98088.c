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
struct V_7 * V_8 = V_32 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
switch ( V_33 ) {
case V_34 :
if ( V_32 -> V_3 == V_26 ) {
F_11 ( V_8 , V_32 -> V_3 , V_27 ,
( 1 + V_22 -> V_25 ) << V_28 ) ;
} else {
F_11 ( V_8 , V_32 -> V_3 , V_27 ,
( 1 + V_22 -> V_29 ) << V_28 ) ;
}
break;
case V_35 :
F_11 ( V_8 , V_32 -> V_3 , V_27 , 0 ) ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static int F_16 ( struct V_31 * V_32 ,
int V_33 , int line , T_2 V_37 )
{
struct V_7 * V_8 = V_32 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
T_2 * V_38 ;
if ( F_4 ( ! ( V_37 == 1 || V_37 == 2 ) ) )
return - V_36 ;
switch ( line ) {
case V_39 :
V_38 = & V_22 -> V_40 ;
break;
case V_41 :
V_38 = & V_22 -> V_42 ;
break;
default:
return - V_36 ;
}
switch ( V_33 ) {
case V_34 :
* V_38 |= V_37 ;
F_11 ( V_8 , V_32 -> V_3 ,
( 1 << V_32 -> V_43 ) , ( 1 << V_32 -> V_43 ) ) ;
break;
case V_35 :
* V_38 &= ~ V_37 ;
if ( * V_38 == 0 ) {
F_11 ( V_8 , V_32 -> V_3 ,
( 1 << V_32 -> V_43 ) , 0 ) ;
}
break;
default:
return - V_36 ;
}
return 0 ;
}
static int F_17 ( struct V_31 * V_32 ,
struct V_17 * V_44 , int V_33 )
{
return F_16 ( V_32 , V_33 , V_39 , 1 ) ;
}
static int F_18 ( struct V_31 * V_32 ,
struct V_17 * V_44 , int V_33 )
{
return F_16 ( V_32 , V_33 , V_39 , 2 ) ;
}
static int F_19 ( struct V_31 * V_32 ,
struct V_17 * V_44 , int V_33 )
{
return F_16 ( V_32 , V_33 , V_41 , 1 ) ;
}
static int F_20 ( struct V_31 * V_32 ,
struct V_17 * V_44 , int V_33 )
{
return F_16 ( V_32 , V_33 , V_41 , 2 ) ;
}
static inline int F_21 ( int V_45 , T_2 * V_24 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_22 ( V_46 ) ; V_13 ++ ) {
if ( V_46 [ V_13 ] . V_45 >= V_45 ) {
* V_24 = V_46 [ V_13 ] . V_47 ;
return 0 ;
}
}
* V_24 = V_46 [ 0 ] . V_47 ;
return - V_36 ;
}
static int F_23 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_52 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
unsigned long long V_55 ;
unsigned int V_45 ;
T_2 V_56 ;
V_54 = & V_22 -> V_9 [ 0 ] ;
V_45 = F_24 ( V_51 ) ;
switch ( F_25 ( V_51 ) ) {
case 16 :
F_11 ( V_8 , V_57 ,
V_58 , 0 ) ;
break;
case 24 :
F_11 ( V_8 , V_57 ,
V_58 , V_58 ) ;
break;
default:
return - V_36 ;
}
F_11 ( V_8 , V_59 , V_60 , 0 ) ;
if ( F_21 ( V_45 , & V_56 ) )
return - V_36 ;
F_11 ( V_8 , V_61 ,
V_62 , V_56 ) ;
V_54 -> V_45 = V_45 ;
if ( F_26 ( V_8 , V_57 )
& V_63 ) {
if ( V_22 -> V_64 == 0 ) {
F_27 ( V_8 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_55 = 65536ULL * ( V_45 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_45 ;
F_28 ( V_55 , ( unsigned long long int ) V_22 -> V_64 ) ;
F_5 ( V_8 , V_65 ,
( V_55 >> 8 ) & 0x7F ) ;
F_5 ( V_8 , V_66 ,
V_55 & 0xFF ) ;
}
if ( V_45 < 50000 )
F_11 ( V_8 , V_67 ,
V_68 , 0 ) ;
else
F_11 ( V_8 , V_67 ,
V_68 , V_68 ) ;
F_11 ( V_8 , V_59 , V_60 ,
V_60 ) ;
return 0 ;
}
static int F_29 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_52 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
unsigned long long V_55 ;
unsigned int V_45 ;
T_2 V_56 ;
V_54 = & V_22 -> V_9 [ 1 ] ;
V_45 = F_24 ( V_51 ) ;
switch ( F_25 ( V_51 ) ) {
case 16 :
F_11 ( V_8 , V_69 ,
V_58 , 0 ) ;
break;
case 24 :
F_11 ( V_8 , V_69 ,
V_58 , V_58 ) ;
break;
default:
return - V_36 ;
}
F_11 ( V_8 , V_59 , V_60 , 0 ) ;
if ( F_21 ( V_45 , & V_56 ) )
return - V_36 ;
F_11 ( V_8 , V_70 ,
V_62 , V_56 ) ;
V_54 -> V_45 = V_45 ;
if ( F_26 ( V_8 , V_69 )
& V_63 ) {
if ( V_22 -> V_64 == 0 ) {
F_27 ( V_8 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_55 = 65536ULL * ( V_45 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_45 ;
F_28 ( V_55 , ( unsigned long long int ) V_22 -> V_64 ) ;
F_5 ( V_8 , V_71 ,
( V_55 >> 8 ) & 0x7F ) ;
F_5 ( V_8 , V_72 ,
V_55 & 0xFF ) ;
}
if ( V_45 < 50000 )
F_11 ( V_8 , V_73 ,
V_68 , 0 ) ;
else
F_11 ( V_8 , V_73 ,
V_68 , V_68 ) ;
F_11 ( V_8 , V_59 , V_60 ,
V_60 ) ;
return 0 ;
}
static int F_30 ( struct V_52 * V_9 ,
int V_74 , unsigned int V_75 , int V_76 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
if ( V_75 == V_22 -> V_64 )
return 0 ;
if ( ( V_75 >= 10000000 ) && ( V_75 < 20000000 ) ) {
F_5 ( V_8 , V_77 , 0x10 ) ;
} else if ( ( V_75 >= 20000000 ) && ( V_75 < 30000000 ) ) {
F_5 ( V_8 , V_77 , 0x20 ) ;
} else {
F_27 ( V_8 -> V_2 , L_2 ) ;
return - V_36 ;
}
if ( F_26 ( V_8 , V_59 ) & V_60 ) {
F_11 ( V_8 , V_59 ,
V_60 , 0 ) ;
F_11 ( V_8 , V_59 ,
V_60 , V_60 ) ;
}
F_31 ( V_9 -> V_2 , L_3 , V_74 , V_75 ) ;
V_22 -> V_64 = V_75 ;
return 0 ;
}
static int F_32 ( struct V_52 * V_78 ,
unsigned int V_79 )
{
struct V_7 * V_8 = V_78 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
T_2 V_80 ;
T_2 V_81 = 0 ;
V_54 = & V_22 -> V_9 [ 0 ] ;
if ( V_79 != V_54 -> V_79 ) {
V_54 -> V_79 = V_79 ;
switch ( V_79 & V_82 ) {
case V_83 :
F_5 ( V_8 , V_65 ,
0x80 ) ;
F_5 ( V_8 , V_66 ,
0x00 ) ;
break;
case V_84 :
V_81 |= V_63 ;
break;
case V_85 :
case V_86 :
default:
F_27 ( V_8 -> V_2 , L_4 ) ;
return - V_36 ;
}
switch ( V_79 & V_87 ) {
case V_88 :
V_81 |= V_89 ;
break;
case V_90 :
break;
default:
return - V_36 ;
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
return - V_36 ;
}
F_11 ( V_8 , V_57 ,
V_63 | V_89 | V_96 |
V_94 , V_81 ) ;
V_80 = V_98 ;
if ( V_22 -> V_99 )
V_80 |= V_100 ;
F_5 ( V_8 , V_101 , V_80 ) ;
}
return 0 ;
}
static int F_33 ( struct V_52 * V_78 ,
unsigned int V_79 )
{
struct V_7 * V_8 = V_78 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
T_2 V_102 = 0 ;
V_54 = & V_22 -> V_9 [ 1 ] ;
if ( V_79 != V_54 -> V_79 ) {
V_54 -> V_79 = V_79 ;
switch ( V_79 & V_82 ) {
case V_83 :
F_5 ( V_8 , V_71 ,
0x80 ) ;
F_5 ( V_8 , V_72 ,
0x00 ) ;
break;
case V_84 :
V_102 |= V_63 ;
break;
case V_85 :
case V_86 :
default:
F_27 ( V_8 -> V_2 , L_4 ) ;
return - V_36 ;
}
switch ( V_79 & V_87 ) {
case V_88 :
V_102 |= V_89 ;
break;
case V_90 :
break;
default:
return - V_36 ;
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
return - V_36 ;
}
F_11 ( V_8 , V_69 ,
V_63 | V_89 | V_96 |
V_94 , V_102 ) ;
F_5 ( V_8 , V_103 ,
V_98 ) ;
}
return 0 ;
}
static int F_34 ( struct V_52 * V_78 , int V_104 )
{
struct V_7 * V_8 = V_78 -> V_8 ;
int V_3 ;
if ( V_104 )
V_3 = V_105 ;
else
V_3 = 0 ;
F_11 ( V_8 , V_106 ,
V_107 , V_3 ) ;
return 0 ;
}
static int F_35 ( struct V_52 * V_78 , int V_104 )
{
struct V_7 * V_8 = V_78 -> V_8 ;
int V_3 ;
if ( V_104 )
V_3 = V_105 ;
else
V_3 = 0 ;
F_11 ( V_8 , V_108 ,
V_107 , V_3 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 ,
enum V_109 V_110 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
switch ( V_110 ) {
case V_111 :
break;
case V_112 :
break;
case V_113 :
if ( V_8 -> V_114 . V_115 == V_116 )
F_37 ( V_22 -> V_117 ) ;
F_11 ( V_8 , V_118 ,
V_119 , V_119 ) ;
break;
case V_116 :
F_11 ( V_8 , V_118 ,
V_119 , 0 ) ;
F_38 ( V_22 -> V_117 ) ;
break;
}
V_8 -> V_114 . V_115 = V_110 ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 , const char * V_120 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_22 ( V_121 ) ; V_13 ++ )
if ( strcmp ( V_120 , V_121 [ V_13 ] ) == 0 )
return V_13 ;
F_27 ( V_8 -> V_2 , L_5 , V_120 ) ;
return - V_36 ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_122 * V_123 = V_22 -> V_123 ;
struct V_124 * V_125 ;
int V_126 , V_127 , V_128 , V_13 , V_23 , V_129 ;
struct V_53 * V_54 ;
V_54 = & V_22 -> V_9 [ 0 ] ;
if ( ! V_123 || ! V_22 -> V_130 )
return;
V_129 = V_54 -> V_45 ;
V_23 = V_54 -> V_131 ;
V_126 = 0 ;
V_127 = V_132 ;
for ( V_13 = 0 ; V_13 < V_123 -> V_133 ; V_13 ++ ) {
if ( strcmp ( V_123 -> V_134 [ V_13 ] . V_120 , V_22 -> V_135 [ V_23 ] ) == 0 &&
abs ( V_123 -> V_134 [ V_13 ] . V_45 - V_129 ) < V_127 ) {
V_126 = V_13 ;
V_127 = abs ( V_123 -> V_134 [ V_13 ] . V_45 - V_129 ) ;
}
}
F_31 ( V_8 -> V_2 , L_6 ,
V_123 -> V_134 [ V_126 ] . V_120 ,
V_123 -> V_134 [ V_126 ] . V_45 , V_129 ) ;
V_128 = F_26 ( V_8 , V_136 ) ;
F_11 ( V_8 , V_136 , V_137 , 0 ) ;
V_125 = & V_123 -> V_134 [ V_23 ] ;
F_3 ( V_8 , 0 , 0 , V_125 -> V_138 ) ;
F_3 ( V_8 , 0 , 1 , V_125 -> V_139 ) ;
F_3 ( V_8 , 0 , 2 , V_125 -> V_140 ) ;
F_3 ( V_8 , 0 , 3 , V_125 -> V_141 ) ;
F_3 ( V_8 , 0 , 4 , V_125 -> V_142 ) ;
F_11 ( V_8 , V_136 , V_137 , V_128 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_122 * V_123 = V_22 -> V_123 ;
struct V_124 * V_125 ;
int V_126 , V_127 , V_128 , V_13 , V_23 , V_129 ;
struct V_53 * V_54 ;
V_54 = & V_22 -> V_9 [ 1 ] ;
if ( ! V_123 || ! V_22 -> V_130 )
return;
V_129 = V_54 -> V_45 ;
V_23 = V_54 -> V_131 ;
V_126 = 0 ;
V_127 = V_132 ;
for ( V_13 = 0 ; V_13 < V_123 -> V_133 ; V_13 ++ ) {
if ( strcmp ( V_123 -> V_134 [ V_13 ] . V_120 , V_22 -> V_135 [ V_23 ] ) == 0 &&
abs ( V_123 -> V_134 [ V_13 ] . V_45 - V_129 ) < V_127 ) {
V_126 = V_13 ;
V_127 = abs ( V_123 -> V_134 [ V_13 ] . V_45 - V_129 ) ;
}
}
F_31 ( V_8 -> V_2 , L_6 ,
V_123 -> V_134 [ V_126 ] . V_120 ,
V_123 -> V_134 [ V_126 ] . V_45 , V_129 ) ;
V_128 = F_26 ( V_8 , V_136 ) ;
F_11 ( V_8 , V_136 , V_143 , 0 ) ;
V_125 = & V_123 -> V_134 [ V_23 ] ;
F_3 ( V_8 , 1 , 0 , V_125 -> V_138 ) ;
F_3 ( V_8 , 1 , 1 , V_125 -> V_139 ) ;
F_3 ( V_8 , 1 , 2 , V_125 -> V_140 ) ;
F_3 ( V_8 , 1 , 3 , V_125 -> V_141 ) ;
F_3 ( V_8 , 1 , 4 , V_125 -> V_142 ) ;
F_11 ( V_8 , V_136 , V_143 ,
V_128 ) ;
}
static int F_42 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_122 * V_123 = V_22 -> V_123 ;
int V_37 = F_39 ( V_8 , V_18 -> V_144 . V_120 ) ;
struct V_53 * V_54 ;
int V_23 = V_20 -> V_24 . integer . V_24 [ 0 ] ;
if ( V_37 < 0 )
return V_37 ;
V_54 = & V_22 -> V_9 [ V_37 ] ;
if ( V_23 >= V_123 -> V_133 )
return - V_36 ;
V_54 -> V_131 = V_23 ;
switch ( V_37 ) {
case 0 :
F_40 ( V_8 ) ;
break;
case 1 :
F_41 ( V_8 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
int V_37 = F_39 ( V_8 , V_18 -> V_144 . V_120 ) ;
struct V_53 * V_54 ;
if ( V_37 < 0 )
return V_37 ;
V_54 = & V_22 -> V_9 [ V_37 ] ;
V_20 -> V_24 . V_145 . V_146 [ 0 ] = V_54 -> V_131 ;
return 0 ;
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_122 * V_123 = V_22 -> V_123 ;
struct V_124 * V_147 ;
unsigned int V_148 ;
int V_13 , V_149 ;
const char * * V_150 ;
int V_151 ;
struct V_152 V_153 [] = {
F_45 ( ( char * ) V_121 [ 0 ] ,
V_22 -> V_154 ,
F_43 ,
F_42 ) ,
F_45 ( ( char * ) V_121 [ 1 ] ,
V_22 -> V_154 ,
F_43 ,
F_42 ) ,
} ;
F_46 ( F_22 ( V_153 ) != F_22 ( V_121 ) ) ;
V_147 = V_123 -> V_134 ;
V_148 = V_123 -> V_133 ;
V_22 -> V_130 = 0 ;
V_22 -> V_135 = NULL ;
for ( V_13 = 0 ; V_13 < V_148 ; V_13 ++ ) {
for ( V_149 = 0 ; V_149 < V_22 -> V_130 ; V_149 ++ ) {
if ( strcmp ( V_147 [ V_13 ] . V_120 , V_22 -> V_135 [ V_149 ] ) == 0 )
break;
}
if ( V_149 != V_22 -> V_130 )
continue;
V_150 = F_47 ( V_22 -> V_135 ,
sizeof( char * ) * ( V_22 -> V_130 + 1 ) ,
V_155 ) ;
if ( V_150 == NULL )
continue;
V_150 [ V_22 -> V_130 ] = V_147 [ V_13 ] . V_120 ;
V_22 -> V_130 ++ ;
V_22 -> V_135 = V_150 ;
}
V_22 -> V_154 . V_156 = V_22 -> V_135 ;
V_22 -> V_154 . V_157 = V_22 -> V_130 ;
V_151 = F_48 ( V_8 , V_153 , F_22 ( V_153 ) ) ;
if ( V_151 != 0 )
F_27 ( V_8 -> V_2 , L_7 , V_151 ) ;
}
static void F_49 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_122 * V_123 = V_22 -> V_123 ;
T_2 V_56 = 0 ;
if ( ! V_123 ) {
F_31 ( V_8 -> V_2 , L_8 ) ;
return;
}
if ( V_123 -> V_158 )
V_56 |= V_159 ;
if ( V_123 -> V_160 )
V_56 |= V_161 ;
V_22 -> V_99 = ( V_56 ? 1 : 0 ) ;
F_5 ( V_8 , V_162 , V_56 ) ;
V_56 = ( ( V_123 -> V_163 ) ? V_164 : 0 ) ;
F_11 ( V_8 , V_165 ,
V_166 , V_56 ) ;
if ( V_123 -> V_133 )
F_44 ( V_8 ) ;
}
static int F_50 ( struct V_7 * V_8 )
{
F_36 ( V_8 , V_116 ) ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 )
{
F_36 ( V_8 , V_113 ) ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
int V_151 = 0 ;
F_38 ( V_22 -> V_117 ) ;
V_22 -> V_64 = ( unsigned ) - 1 ;
V_22 -> V_130 = 0 ;
V_54 = & V_22 -> V_9 [ 0 ] ;
V_54 -> V_45 = ( unsigned ) - 1 ;
V_54 -> V_79 = ( unsigned ) - 1 ;
V_54 -> V_131 = 0 ;
V_54 = & V_22 -> V_9 [ 1 ] ;
V_54 -> V_45 = ( unsigned ) - 1 ;
V_54 -> V_79 = ( unsigned ) - 1 ;
V_54 -> V_131 = 0 ;
V_22 -> V_40 = 0 ;
V_22 -> V_42 = 0 ;
V_22 -> V_167 = 0 ;
V_22 -> V_99 = 0 ;
V_22 -> V_25 = 0 ;
V_22 -> V_29 = 0 ;
V_151 = F_26 ( V_8 , V_168 ) ;
if ( V_151 < 0 ) {
F_27 ( V_8 -> V_2 , L_9 ,
V_151 ) ;
goto V_169;
}
F_53 ( V_8 -> V_2 , L_10 , V_151 - 0x40 + 'A' ) ;
F_5 ( V_8 , V_59 , V_170 ) ;
F_36 ( V_8 , V_113 ) ;
F_5 ( V_8 , V_171 , 0x00 ) ;
F_5 ( V_8 , V_172 ,
V_173 | V_174 |
V_175 | V_176 ) ;
F_5 ( V_8 , V_177 , 0xF0 ) ;
F_5 ( V_8 , V_178 , 0x0F ) ;
F_5 ( V_8 , V_179 ,
V_180 | V_181 ) ;
F_5 ( V_8 , V_182 ,
V_183 | V_181 ) ;
F_49 ( V_8 ) ;
V_169:
return V_151 ;
}
static int F_54 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
F_36 ( V_8 , V_116 ) ;
F_55 ( V_22 -> V_135 ) ;
return 0 ;
}
static int F_56 ( struct V_184 * V_185 ,
const struct V_186 * V_144 )
{
struct V_21 * V_22 ;
int V_151 ;
V_22 = F_57 ( & V_185 -> V_2 , sizeof( struct V_21 ) ,
V_155 ) ;
if ( V_22 == NULL )
return - V_187 ;
V_22 -> V_117 = F_58 ( V_185 , & V_188 ) ;
if ( F_59 ( V_22 -> V_117 ) )
return F_60 ( V_22 -> V_117 ) ;
V_22 -> V_189 = V_144 -> V_190 ;
F_61 ( V_185 , V_22 ) ;
V_22 -> V_123 = V_185 -> V_2 . V_191 ;
V_151 = F_62 ( & V_185 -> V_2 ,
& V_192 , & V_193 [ 0 ] , 2 ) ;
return V_151 ;
}
static int F_63 ( struct V_184 * V_194 )
{
F_64 ( & V_194 -> V_2 ) ;
return 0 ;
}
