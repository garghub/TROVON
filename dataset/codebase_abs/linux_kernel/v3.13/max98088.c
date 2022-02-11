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
case V_57 :
F_11 ( V_8 , V_58 ,
V_59 , 0 ) ;
break;
case V_60 :
F_11 ( V_8 , V_58 ,
V_59 , V_59 ) ;
break;
default:
return - V_36 ;
}
F_11 ( V_8 , V_61 , V_62 , 0 ) ;
if ( F_21 ( V_45 , & V_56 ) )
return - V_36 ;
F_11 ( V_8 , V_63 ,
V_64 , V_56 ) ;
V_54 -> V_45 = V_45 ;
if ( F_26 ( V_8 , V_58 )
& V_65 ) {
if ( V_22 -> V_66 == 0 ) {
F_27 ( V_8 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_55 = 65536ULL * ( V_45 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_45 ;
F_28 ( V_55 , ( unsigned long long int ) V_22 -> V_66 ) ;
F_5 ( V_8 , V_67 ,
( V_55 >> 8 ) & 0x7F ) ;
F_5 ( V_8 , V_68 ,
V_55 & 0xFF ) ;
}
if ( V_45 < 50000 )
F_11 ( V_8 , V_69 ,
V_70 , 0 ) ;
else
F_11 ( V_8 , V_69 ,
V_70 , V_70 ) ;
F_11 ( V_8 , V_61 , V_62 ,
V_62 ) ;
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
case V_57 :
F_11 ( V_8 , V_71 ,
V_59 , 0 ) ;
break;
case V_60 :
F_11 ( V_8 , V_71 ,
V_59 , V_59 ) ;
break;
default:
return - V_36 ;
}
F_11 ( V_8 , V_61 , V_62 , 0 ) ;
if ( F_21 ( V_45 , & V_56 ) )
return - V_36 ;
F_11 ( V_8 , V_72 ,
V_64 , V_56 ) ;
V_54 -> V_45 = V_45 ;
if ( F_26 ( V_8 , V_71 )
& V_65 ) {
if ( V_22 -> V_66 == 0 ) {
F_27 ( V_8 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_55 = 65536ULL * ( V_45 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_45 ;
F_28 ( V_55 , ( unsigned long long int ) V_22 -> V_66 ) ;
F_5 ( V_8 , V_73 ,
( V_55 >> 8 ) & 0x7F ) ;
F_5 ( V_8 , V_74 ,
V_55 & 0xFF ) ;
}
if ( V_45 < 50000 )
F_11 ( V_8 , V_75 ,
V_70 , 0 ) ;
else
F_11 ( V_8 , V_75 ,
V_70 , V_70 ) ;
F_11 ( V_8 , V_61 , V_62 ,
V_62 ) ;
return 0 ;
}
static int F_30 ( struct V_52 * V_9 ,
int V_76 , unsigned int V_77 , int V_78 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
if ( V_77 == V_22 -> V_66 )
return 0 ;
if ( ( V_77 >= 10000000 ) && ( V_77 < 20000000 ) ) {
F_5 ( V_8 , V_79 , 0x10 ) ;
} else if ( ( V_77 >= 20000000 ) && ( V_77 < 30000000 ) ) {
F_5 ( V_8 , V_79 , 0x20 ) ;
} else {
F_27 ( V_8 -> V_2 , L_2 ) ;
return - V_36 ;
}
if ( F_26 ( V_8 , V_61 ) & V_62 ) {
F_11 ( V_8 , V_61 ,
V_62 , 0 ) ;
F_11 ( V_8 , V_61 ,
V_62 , V_62 ) ;
}
F_31 ( V_9 -> V_2 , L_3 , V_76 , V_77 ) ;
V_22 -> V_66 = V_77 ;
return 0 ;
}
static int F_32 ( struct V_52 * V_80 ,
unsigned int V_81 )
{
struct V_7 * V_8 = V_80 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
T_2 V_82 ;
T_2 V_83 = 0 ;
V_54 = & V_22 -> V_9 [ 0 ] ;
if ( V_81 != V_54 -> V_81 ) {
V_54 -> V_81 = V_81 ;
switch ( V_81 & V_84 ) {
case V_85 :
F_5 ( V_8 , V_67 ,
0x80 ) ;
F_5 ( V_8 , V_68 ,
0x00 ) ;
break;
case V_86 :
V_83 |= V_65 ;
break;
case V_87 :
case V_88 :
default:
F_27 ( V_8 -> V_2 , L_4 ) ;
return - V_36 ;
}
switch ( V_81 & V_89 ) {
case V_90 :
V_83 |= V_91 ;
break;
case V_92 :
break;
default:
return - V_36 ;
}
switch ( V_81 & V_93 ) {
case V_94 :
break;
case V_95 :
V_83 |= V_96 ;
break;
case V_97 :
V_83 |= V_98 ;
break;
case V_99 :
V_83 |= V_98 | V_96 ;
break;
default:
return - V_36 ;
}
F_11 ( V_8 , V_58 ,
V_65 | V_91 | V_98 |
V_96 , V_83 ) ;
V_82 = V_100 ;
if ( V_22 -> V_101 )
V_82 |= V_102 ;
F_5 ( V_8 , V_103 , V_82 ) ;
}
return 0 ;
}
static int F_33 ( struct V_52 * V_80 ,
unsigned int V_81 )
{
struct V_7 * V_8 = V_80 -> V_8 ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
T_2 V_104 = 0 ;
V_54 = & V_22 -> V_9 [ 1 ] ;
if ( V_81 != V_54 -> V_81 ) {
V_54 -> V_81 = V_81 ;
switch ( V_81 & V_84 ) {
case V_85 :
F_5 ( V_8 , V_73 ,
0x80 ) ;
F_5 ( V_8 , V_74 ,
0x00 ) ;
break;
case V_86 :
V_104 |= V_65 ;
break;
case V_87 :
case V_88 :
default:
F_27 ( V_8 -> V_2 , L_4 ) ;
return - V_36 ;
}
switch ( V_81 & V_89 ) {
case V_90 :
V_104 |= V_91 ;
break;
case V_92 :
break;
default:
return - V_36 ;
}
switch ( V_81 & V_93 ) {
case V_94 :
break;
case V_95 :
V_104 |= V_96 ;
break;
case V_97 :
V_104 |= V_98 ;
break;
case V_99 :
V_104 |= V_98 | V_96 ;
break;
default:
return - V_36 ;
}
F_11 ( V_8 , V_71 ,
V_65 | V_91 | V_98 |
V_96 , V_104 ) ;
F_5 ( V_8 , V_105 ,
V_100 ) ;
}
return 0 ;
}
static int F_34 ( struct V_52 * V_80 , int V_106 )
{
struct V_7 * V_8 = V_80 -> V_8 ;
int V_3 ;
if ( V_106 )
V_3 = V_107 ;
else
V_3 = 0 ;
F_11 ( V_8 , V_108 ,
V_109 , V_3 ) ;
return 0 ;
}
static int F_35 ( struct V_52 * V_80 , int V_106 )
{
struct V_7 * V_8 = V_80 -> V_8 ;
int V_3 ;
if ( V_106 )
V_3 = V_107 ;
else
V_3 = 0 ;
F_11 ( V_8 , V_110 ,
V_109 , V_3 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 ,
enum V_111 V_112 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
switch ( V_112 ) {
case V_113 :
break;
case V_114 :
break;
case V_115 :
if ( V_8 -> V_116 . V_117 == V_118 )
F_37 ( V_22 -> V_119 ) ;
F_11 ( V_8 , V_120 ,
V_121 , V_121 ) ;
break;
case V_118 :
F_11 ( V_8 , V_120 ,
V_121 , 0 ) ;
F_38 ( V_22 -> V_119 ) ;
break;
}
V_8 -> V_116 . V_117 = V_112 ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 , const char * V_122 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_22 ( V_123 ) ; V_13 ++ )
if ( strcmp ( V_122 , V_123 [ V_13 ] ) == 0 )
return V_13 ;
F_27 ( V_8 -> V_2 , L_5 , V_122 ) ;
return - V_36 ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_124 * V_125 = V_22 -> V_125 ;
struct V_126 * V_127 ;
int V_128 , V_129 , V_130 , V_13 , V_23 , V_131 ;
struct V_53 * V_54 ;
V_54 = & V_22 -> V_9 [ 0 ] ;
if ( ! V_125 || ! V_22 -> V_132 )
return;
V_131 = V_54 -> V_45 ;
V_23 = V_54 -> V_133 ;
V_128 = 0 ;
V_129 = V_134 ;
for ( V_13 = 0 ; V_13 < V_125 -> V_135 ; V_13 ++ ) {
if ( strcmp ( V_125 -> V_136 [ V_13 ] . V_122 , V_22 -> V_137 [ V_23 ] ) == 0 &&
abs ( V_125 -> V_136 [ V_13 ] . V_45 - V_131 ) < V_129 ) {
V_128 = V_13 ;
V_129 = abs ( V_125 -> V_136 [ V_13 ] . V_45 - V_131 ) ;
}
}
F_31 ( V_8 -> V_2 , L_6 ,
V_125 -> V_136 [ V_128 ] . V_122 ,
V_125 -> V_136 [ V_128 ] . V_45 , V_131 ) ;
V_130 = F_26 ( V_8 , V_138 ) ;
F_11 ( V_8 , V_138 , V_139 , 0 ) ;
V_127 = & V_125 -> V_136 [ V_23 ] ;
F_3 ( V_8 , 0 , 0 , V_127 -> V_140 ) ;
F_3 ( V_8 , 0 , 1 , V_127 -> V_141 ) ;
F_3 ( V_8 , 0 , 2 , V_127 -> V_142 ) ;
F_3 ( V_8 , 0 , 3 , V_127 -> V_143 ) ;
F_3 ( V_8 , 0 , 4 , V_127 -> V_144 ) ;
F_11 ( V_8 , V_138 , V_139 , V_130 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_124 * V_125 = V_22 -> V_125 ;
struct V_126 * V_127 ;
int V_128 , V_129 , V_130 , V_13 , V_23 , V_131 ;
struct V_53 * V_54 ;
V_54 = & V_22 -> V_9 [ 1 ] ;
if ( ! V_125 || ! V_22 -> V_132 )
return;
V_131 = V_54 -> V_45 ;
V_23 = V_54 -> V_133 ;
V_128 = 0 ;
V_129 = V_134 ;
for ( V_13 = 0 ; V_13 < V_125 -> V_135 ; V_13 ++ ) {
if ( strcmp ( V_125 -> V_136 [ V_13 ] . V_122 , V_22 -> V_137 [ V_23 ] ) == 0 &&
abs ( V_125 -> V_136 [ V_13 ] . V_45 - V_131 ) < V_129 ) {
V_128 = V_13 ;
V_129 = abs ( V_125 -> V_136 [ V_13 ] . V_45 - V_131 ) ;
}
}
F_31 ( V_8 -> V_2 , L_6 ,
V_125 -> V_136 [ V_128 ] . V_122 ,
V_125 -> V_136 [ V_128 ] . V_45 , V_131 ) ;
V_130 = F_26 ( V_8 , V_138 ) ;
F_11 ( V_8 , V_138 , V_145 , 0 ) ;
V_127 = & V_125 -> V_136 [ V_23 ] ;
F_3 ( V_8 , 1 , 0 , V_127 -> V_140 ) ;
F_3 ( V_8 , 1 , 1 , V_127 -> V_141 ) ;
F_3 ( V_8 , 1 , 2 , V_127 -> V_142 ) ;
F_3 ( V_8 , 1 , 3 , V_127 -> V_143 ) ;
F_3 ( V_8 , 1 , 4 , V_127 -> V_144 ) ;
F_11 ( V_8 , V_138 , V_145 ,
V_130 ) ;
}
static int F_42 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_124 * V_125 = V_22 -> V_125 ;
int V_37 = F_39 ( V_8 , V_18 -> V_146 . V_122 ) ;
struct V_53 * V_54 ;
int V_23 = V_20 -> V_24 . integer . V_24 [ 0 ] ;
if ( V_37 < 0 )
return V_37 ;
V_54 = & V_22 -> V_9 [ V_37 ] ;
if ( V_23 >= V_125 -> V_135 )
return - V_36 ;
V_54 -> V_133 = V_23 ;
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
int V_37 = F_39 ( V_8 , V_18 -> V_146 . V_122 ) ;
struct V_53 * V_54 ;
if ( V_37 < 0 )
return V_37 ;
V_54 = & V_22 -> V_9 [ V_37 ] ;
V_20 -> V_24 . V_147 . V_148 [ 0 ] = V_54 -> V_133 ;
return 0 ;
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_124 * V_125 = V_22 -> V_125 ;
struct V_126 * V_149 ;
unsigned int V_150 ;
int V_13 , V_151 ;
const char * * V_152 ;
int V_153 ;
struct V_154 V_155 [] = {
F_45 ( ( char * ) V_123 [ 0 ] ,
V_22 -> V_156 ,
F_43 ,
F_42 ) ,
F_45 ( ( char * ) V_123 [ 1 ] ,
V_22 -> V_156 ,
F_43 ,
F_42 ) ,
} ;
F_46 ( F_22 ( V_155 ) != F_22 ( V_123 ) ) ;
V_149 = V_125 -> V_136 ;
V_150 = V_125 -> V_135 ;
V_22 -> V_132 = 0 ;
V_22 -> V_137 = NULL ;
for ( V_13 = 0 ; V_13 < V_150 ; V_13 ++ ) {
for ( V_151 = 0 ; V_151 < V_22 -> V_132 ; V_151 ++ ) {
if ( strcmp ( V_149 [ V_13 ] . V_122 , V_22 -> V_137 [ V_151 ] ) == 0 )
break;
}
if ( V_151 != V_22 -> V_132 )
continue;
V_152 = F_47 ( V_22 -> V_137 ,
sizeof( char * ) * ( V_22 -> V_132 + 1 ) ,
V_157 ) ;
if ( V_152 == NULL )
continue;
V_152 [ V_22 -> V_132 ] = V_149 [ V_13 ] . V_122 ;
V_22 -> V_132 ++ ;
V_22 -> V_137 = V_152 ;
}
V_22 -> V_156 . V_158 = V_22 -> V_137 ;
V_22 -> V_156 . V_159 = V_22 -> V_132 ;
V_153 = F_48 ( V_8 , V_155 , F_22 ( V_155 ) ) ;
if ( V_153 != 0 )
F_27 ( V_8 -> V_2 , L_7 , V_153 ) ;
}
static void F_49 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_124 * V_125 = V_22 -> V_125 ;
T_2 V_56 = 0 ;
if ( ! V_125 ) {
F_31 ( V_8 -> V_2 , L_8 ) ;
return;
}
if ( V_125 -> V_160 )
V_56 |= V_161 ;
if ( V_125 -> V_162 )
V_56 |= V_163 ;
V_22 -> V_101 = ( V_56 ? 1 : 0 ) ;
F_5 ( V_8 , V_164 , V_56 ) ;
V_56 = ( ( V_125 -> V_165 ) ? V_166 : 0 ) ;
F_11 ( V_8 , V_167 ,
V_168 , V_56 ) ;
if ( V_125 -> V_135 )
F_44 ( V_8 ) ;
}
static int F_50 ( struct V_7 * V_8 )
{
F_36 ( V_8 , V_118 ) ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 )
{
F_36 ( V_8 , V_115 ) ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
int V_153 = 0 ;
F_38 ( V_22 -> V_119 ) ;
V_153 = F_53 ( V_8 , 8 , 8 , V_169 ) ;
if ( V_153 != 0 ) {
F_27 ( V_8 -> V_2 , L_9 , V_153 ) ;
return V_153 ;
}
V_22 -> V_66 = ( unsigned ) - 1 ;
V_22 -> V_132 = 0 ;
V_54 = & V_22 -> V_9 [ 0 ] ;
V_54 -> V_45 = ( unsigned ) - 1 ;
V_54 -> V_81 = ( unsigned ) - 1 ;
V_54 -> V_133 = 0 ;
V_54 = & V_22 -> V_9 [ 1 ] ;
V_54 -> V_45 = ( unsigned ) - 1 ;
V_54 -> V_81 = ( unsigned ) - 1 ;
V_54 -> V_133 = 0 ;
V_22 -> V_40 = 0 ;
V_22 -> V_42 = 0 ;
V_22 -> V_170 = 0 ;
V_22 -> V_101 = 0 ;
V_22 -> V_25 = 0 ;
V_22 -> V_29 = 0 ;
V_153 = F_26 ( V_8 , V_171 ) ;
if ( V_153 < 0 ) {
F_27 ( V_8 -> V_2 , L_10 ,
V_153 ) ;
goto V_172;
}
F_54 ( V_8 -> V_2 , L_11 , V_153 - 0x40 + 'A' ) ;
F_5 ( V_8 , V_61 , V_173 ) ;
F_36 ( V_8 , V_115 ) ;
F_5 ( V_8 , V_174 , 0x00 ) ;
F_5 ( V_8 , V_175 ,
V_176 | V_177 |
V_178 | V_179 ) ;
F_5 ( V_8 , V_180 , 0xF0 ) ;
F_5 ( V_8 , V_181 , 0x0F ) ;
F_5 ( V_8 , V_182 ,
V_183 | V_184 ) ;
F_5 ( V_8 , V_185 ,
V_186 | V_184 ) ;
F_49 ( V_8 ) ;
V_172:
return V_153 ;
}
static int F_55 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_10 ( V_8 ) ;
F_36 ( V_8 , V_118 ) ;
F_56 ( V_22 -> V_137 ) ;
return 0 ;
}
static int F_57 ( struct V_187 * V_188 ,
const struct V_189 * V_146 )
{
struct V_21 * V_22 ;
int V_153 ;
V_22 = F_58 ( & V_188 -> V_2 , sizeof( struct V_21 ) ,
V_157 ) ;
if ( V_22 == NULL )
return - V_190 ;
V_22 -> V_119 = F_59 ( V_188 , & V_191 ) ;
if ( F_60 ( V_22 -> V_119 ) )
return F_61 ( V_22 -> V_119 ) ;
V_22 -> V_192 = V_146 -> V_193 ;
F_62 ( V_188 , V_22 ) ;
V_22 -> V_125 = V_188 -> V_2 . V_194 ;
V_153 = F_63 ( & V_188 -> V_2 ,
& V_195 , & V_196 [ 0 ] , 2 ) ;
return V_153 ;
}
static int F_64 ( struct V_187 * V_197 )
{
F_65 ( & V_197 -> V_2 ) ;
return 0 ;
}
