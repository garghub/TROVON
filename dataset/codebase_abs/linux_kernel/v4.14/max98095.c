static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_8 ... V_9 :
case V_10 + 1 ... V_6 :
return true ;
default:
return false ;
}
}
static void F_4 ( struct V_11 * V_12 , unsigned int V_13 ,
unsigned int V_14 , T_1 * V_15 )
{
unsigned int V_16 ;
unsigned int V_17 ;
if ( F_5 ( V_14 > 4 ) ||
F_5 ( V_13 > 1 ) )
return;
V_16 = V_13 ? V_18 : V_19 ;
V_16 += V_14 * ( V_20 << 1 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
F_6 ( V_12 , V_16 ++ , F_7 ( V_15 [ V_17 ] ) ) ;
F_6 ( V_12 , V_16 ++ , F_8 ( V_15 [ V_17 ] ) ) ;
}
}
static void F_9 ( struct V_11 * V_12 , unsigned int V_13 ,
unsigned int V_14 , T_1 * V_15 )
{
unsigned int V_21 ;
unsigned int V_17 ;
if ( F_5 ( V_14 > 1 ) ||
F_5 ( V_13 > 1 ) )
return;
V_21 = V_13 ? V_22 : V_23 ;
V_21 += V_14 * ( V_20 << 1 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
F_6 ( V_12 , V_21 ++ , F_7 ( V_15 [ V_17 ] ) ) ;
F_6 ( V_12 , V_21 ++ , F_8 ( V_15 [ V_17 ] ) ) ;
}
}
static int F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_11 ( V_25 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
unsigned int V_30 = V_27 -> V_31 . integer . V_31 [ 0 ] ;
V_29 -> V_32 = V_30 ;
F_13 ( V_12 , V_33 , V_34 ,
( 1 + V_30 ) << V_35 ) ;
return 0 ;
}
static int F_14 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_11 ( V_25 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
V_27 -> V_31 . integer . V_31 [ 0 ] = V_29 -> V_32 ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_11 ( V_25 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
unsigned int V_30 = V_27 -> V_31 . integer . V_31 [ 0 ] ;
V_29 -> V_36 = V_30 ;
F_13 ( V_12 , V_37 , V_34 ,
( 1 + V_30 ) << V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_11 ( V_25 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
V_27 -> V_31 . integer . V_31 [ 0 ] = V_29 -> V_36 ;
return 0 ;
}
static int F_17 ( struct V_38 * V_39 ,
struct V_24 * V_25 , int V_40 )
{
struct V_11 * V_12 = F_18 ( V_39 -> V_41 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
switch ( V_40 ) {
case V_42 :
if ( V_39 -> V_3 == V_33 ) {
F_13 ( V_12 , V_39 -> V_3 , V_34 ,
( 1 + V_29 -> V_32 ) << V_35 ) ;
} else {
F_13 ( V_12 , V_39 -> V_3 , V_34 ,
( 1 + V_29 -> V_36 ) << V_35 ) ;
}
break;
case V_43 :
F_13 ( V_12 , V_39 -> V_3 , V_34 , 0 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_19 ( struct V_38 * V_39 ,
int V_40 , T_2 V_45 )
{
struct V_11 * V_12 = F_18 ( V_39 -> V_41 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
T_2 * V_46 ;
if ( F_5 ( ! ( V_45 == 1 || V_45 == 2 ) ) )
return - V_44 ;
V_46 = & V_29 -> V_47 ;
switch ( V_40 ) {
case V_42 :
* V_46 |= V_45 ;
F_13 ( V_12 , V_39 -> V_3 ,
( 1 << V_39 -> V_48 ) , ( 1 << V_39 -> V_48 ) ) ;
break;
case V_43 :
* V_46 &= ~ V_45 ;
if ( * V_46 == 0 ) {
F_13 ( V_12 , V_39 -> V_3 ,
( 1 << V_39 -> V_48 ) , 0 ) ;
}
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_20 ( struct V_38 * V_39 ,
struct V_24 * V_49 , int V_40 )
{
return F_19 ( V_39 , V_40 , 1 ) ;
}
static int F_21 ( struct V_38 * V_39 ,
struct V_24 * V_49 , int V_40 )
{
return F_19 ( V_39 , V_40 , 2 ) ;
}
static int F_22 ( struct V_38 * V_39 ,
struct V_24 * V_25 , int V_40 )
{
struct V_11 * V_12 = F_18 ( V_39 -> V_41 ) ;
switch ( V_40 ) {
case V_42 :
F_13 ( V_12 , V_39 -> V_3 ,
( 1 << ( V_39 -> V_48 + 2 ) ) , ( 1 << ( V_39 -> V_48 + 2 ) ) ) ;
break;
case V_43 :
F_13 ( V_12 , V_39 -> V_3 ,
( 1 << ( V_39 -> V_48 + 2 ) ) , 0 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_23 ( int V_50 , T_2 * V_31 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_24 ( V_51 ) ; V_17 ++ ) {
if ( V_51 [ V_17 ] . V_50 >= V_50 ) {
* V_31 = V_51 [ V_17 ] . V_52 ;
return 0 ;
}
}
* V_31 = V_51 [ 0 ] . V_52 ;
return - V_44 ;
}
static int F_25 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_58 * V_59 ;
unsigned long long V_60 ;
unsigned int V_50 ;
T_2 V_61 ;
V_59 = & V_29 -> V_13 [ 0 ] ;
V_50 = F_26 ( V_56 ) ;
switch ( F_27 ( V_56 ) ) {
case 16 :
F_13 ( V_12 , V_62 ,
V_63 , 0 ) ;
break;
case 24 :
F_13 ( V_12 , V_62 ,
V_63 , V_63 ) ;
break;
default:
return - V_44 ;
}
if ( F_23 ( V_50 , & V_61 ) )
return - V_44 ;
F_13 ( V_12 , V_64 ,
V_65 , V_61 ) ;
V_59 -> V_50 = V_50 ;
if ( F_28 ( V_12 , V_62 ) & V_66 ) {
if ( V_29 -> V_67 == 0 ) {
F_29 ( V_12 -> V_2 , L_1 ) ;
return - V_44 ;
}
V_60 = 65536ULL * ( V_50 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_50 ;
F_30 ( V_60 , ( unsigned long long int ) V_29 -> V_67 ) ;
F_6 ( V_12 , V_68 ,
( V_60 >> 8 ) & 0x7F ) ;
F_6 ( V_12 , V_69 ,
V_60 & 0xFF ) ;
}
if ( V_50 < 50000 )
F_13 ( V_12 , V_70 ,
V_71 , 0 ) ;
else
F_13 ( V_12 , V_70 ,
V_71 , V_71 ) ;
return 0 ;
}
static int F_31 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_58 * V_59 ;
unsigned long long V_60 ;
unsigned int V_50 ;
T_2 V_61 ;
V_59 = & V_29 -> V_13 [ 1 ] ;
V_50 = F_26 ( V_56 ) ;
switch ( F_27 ( V_56 ) ) {
case 16 :
F_13 ( V_12 , V_72 ,
V_63 , 0 ) ;
break;
case 24 :
F_13 ( V_12 , V_72 ,
V_63 , V_63 ) ;
break;
default:
return - V_44 ;
}
if ( F_23 ( V_50 , & V_61 ) )
return - V_44 ;
F_13 ( V_12 , V_73 ,
V_65 , V_61 ) ;
V_59 -> V_50 = V_50 ;
if ( F_28 ( V_12 , V_72 ) & V_66 ) {
if ( V_29 -> V_67 == 0 ) {
F_29 ( V_12 -> V_2 , L_1 ) ;
return - V_44 ;
}
V_60 = 65536ULL * ( V_50 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_50 ;
F_30 ( V_60 , ( unsigned long long int ) V_29 -> V_67 ) ;
F_6 ( V_12 , V_74 ,
( V_60 >> 8 ) & 0x7F ) ;
F_6 ( V_12 , V_75 ,
V_60 & 0xFF ) ;
}
if ( V_50 < 50000 )
F_13 ( V_12 , V_76 ,
V_71 , 0 ) ;
else
F_13 ( V_12 , V_76 ,
V_71 , V_71 ) ;
return 0 ;
}
static int F_32 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_58 * V_59 ;
unsigned long long V_60 ;
unsigned int V_50 ;
T_2 V_61 ;
V_59 = & V_29 -> V_13 [ 2 ] ;
V_50 = F_26 ( V_56 ) ;
switch ( F_27 ( V_56 ) ) {
case 16 :
F_13 ( V_12 , V_77 ,
V_63 , 0 ) ;
break;
case 24 :
F_13 ( V_12 , V_77 ,
V_63 , V_63 ) ;
break;
default:
return - V_44 ;
}
if ( F_23 ( V_50 , & V_61 ) )
return - V_44 ;
F_13 ( V_12 , V_78 ,
V_65 , V_61 ) ;
V_59 -> V_50 = V_50 ;
if ( F_28 ( V_12 , V_77 ) & V_66 ) {
if ( V_29 -> V_67 == 0 ) {
F_29 ( V_12 -> V_2 , L_1 ) ;
return - V_44 ;
}
V_60 = 65536ULL * ( V_50 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_50 ;
F_30 ( V_60 , ( unsigned long long int ) V_29 -> V_67 ) ;
F_6 ( V_12 , V_79 ,
( V_60 >> 8 ) & 0x7F ) ;
F_6 ( V_12 , V_80 ,
V_60 & 0xFF ) ;
}
if ( V_50 < 50000 )
F_13 ( V_12 , V_81 ,
V_71 , 0 ) ;
else
F_13 ( V_12 , V_81 ,
V_71 , V_71 ) ;
return 0 ;
}
static int F_33 ( struct V_57 * V_13 ,
int V_82 , unsigned int V_83 , int V_84 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
if ( V_83 == V_29 -> V_67 )
return 0 ;
if ( ! F_34 ( V_29 -> V_85 ) ) {
V_83 = F_35 ( V_29 -> V_85 , V_83 ) ;
F_36 ( V_29 -> V_85 , V_83 ) ;
}
if ( ( V_83 >= 10000000 ) && ( V_83 < 20000000 ) ) {
F_6 ( V_12 , V_86 , 0x10 ) ;
} else if ( ( V_83 >= 20000000 ) && ( V_83 < 40000000 ) ) {
F_6 ( V_12 , V_86 , 0x20 ) ;
} else if ( ( V_83 >= 40000000 ) && ( V_83 < 60000000 ) ) {
F_6 ( V_12 , V_86 , 0x30 ) ;
} else {
F_29 ( V_12 -> V_2 , L_2 ) ;
return - V_44 ;
}
F_37 ( V_13 -> V_2 , L_3 , V_82 , V_83 ) ;
V_29 -> V_67 = V_83 ;
return 0 ;
}
static int F_38 ( struct V_57 * V_87 ,
unsigned int V_88 )
{
struct V_11 * V_12 = V_87 -> V_12 ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_58 * V_59 ;
T_2 V_61 = 0 ;
V_59 = & V_29 -> V_13 [ 0 ] ;
if ( V_88 != V_59 -> V_88 ) {
V_59 -> V_88 = V_88 ;
switch ( V_88 & V_89 ) {
case V_90 :
F_6 ( V_12 , V_68 ,
0x80 ) ;
F_6 ( V_12 , V_69 ,
0x00 ) ;
break;
case V_91 :
V_61 |= V_66 ;
break;
case V_92 :
case V_93 :
default:
F_29 ( V_12 -> V_2 , L_4 ) ;
return - V_44 ;
}
switch ( V_88 & V_94 ) {
case V_95 :
V_61 |= V_96 ;
break;
case V_97 :
break;
default:
return - V_44 ;
}
switch ( V_88 & V_98 ) {
case V_99 :
break;
case V_100 :
V_61 |= V_101 ;
break;
case V_102 :
V_61 |= V_103 ;
break;
case V_104 :
V_61 |= V_103 | V_101 ;
break;
default:
return - V_44 ;
}
F_13 ( V_12 , V_62 ,
V_66 | V_96 | V_103 |
V_101 , V_61 ) ;
F_6 ( V_12 , V_105 , V_106 ) ;
}
return 0 ;
}
static int F_39 ( struct V_57 * V_87 ,
unsigned int V_88 )
{
struct V_11 * V_12 = V_87 -> V_12 ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_58 * V_59 ;
T_2 V_61 = 0 ;
V_59 = & V_29 -> V_13 [ 1 ] ;
if ( V_88 != V_59 -> V_88 ) {
V_59 -> V_88 = V_88 ;
switch ( V_88 & V_89 ) {
case V_90 :
F_6 ( V_12 , V_74 ,
0x80 ) ;
F_6 ( V_12 , V_75 ,
0x00 ) ;
break;
case V_91 :
V_61 |= V_66 ;
break;
case V_92 :
case V_93 :
default:
F_29 ( V_12 -> V_2 , L_4 ) ;
return - V_44 ;
}
switch ( V_88 & V_94 ) {
case V_95 :
V_61 |= V_96 ;
break;
case V_97 :
break;
default:
return - V_44 ;
}
switch ( V_88 & V_98 ) {
case V_99 :
break;
case V_100 :
V_61 |= V_101 ;
break;
case V_102 :
V_61 |= V_103 ;
break;
case V_104 :
V_61 |= V_103 | V_101 ;
break;
default:
return - V_44 ;
}
F_13 ( V_12 , V_72 ,
V_66 | V_96 | V_103 |
V_101 , V_61 ) ;
F_6 ( V_12 , V_107 ,
V_106 ) ;
}
return 0 ;
}
static int F_40 ( struct V_57 * V_87 ,
unsigned int V_88 )
{
struct V_11 * V_12 = V_87 -> V_12 ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_58 * V_59 ;
T_2 V_61 = 0 ;
V_59 = & V_29 -> V_13 [ 2 ] ;
if ( V_88 != V_59 -> V_88 ) {
V_59 -> V_88 = V_88 ;
switch ( V_88 & V_89 ) {
case V_90 :
F_6 ( V_12 , V_79 ,
0x80 ) ;
F_6 ( V_12 , V_80 ,
0x00 ) ;
break;
case V_91 :
V_61 |= V_66 ;
break;
case V_92 :
case V_93 :
default:
F_29 ( V_12 -> V_2 , L_4 ) ;
return - V_44 ;
}
switch ( V_88 & V_94 ) {
case V_95 :
V_61 |= V_96 ;
break;
case V_97 :
break;
default:
return - V_44 ;
}
switch ( V_88 & V_98 ) {
case V_99 :
break;
case V_100 :
V_61 |= V_101 ;
break;
case V_102 :
V_61 |= V_103 ;
break;
case V_104 :
V_61 |= V_103 | V_101 ;
break;
default:
return - V_44 ;
}
F_13 ( V_12 , V_77 ,
V_66 | V_96 | V_103 |
V_101 , V_61 ) ;
F_6 ( V_12 , V_108 ,
V_106 ) ;
}
return 0 ;
}
static int F_41 ( struct V_11 * V_12 ,
enum V_109 V_110 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
int V_111 ;
switch ( V_110 ) {
case V_112 :
break;
case V_113 :
if ( F_34 ( V_29 -> V_85 ) )
break;
if ( F_42 ( V_12 ) == V_112 ) {
F_43 ( V_29 -> V_85 ) ;
} else {
V_111 = F_44 ( V_29 -> V_85 ) ;
if ( V_111 )
return V_111 ;
}
break;
case V_114 :
if ( F_42 ( V_12 ) == V_115 ) {
V_111 = F_45 ( V_29 -> V_116 ) ;
if ( V_111 != 0 ) {
F_29 ( V_12 -> V_2 , L_5 , V_111 ) ;
return V_111 ;
}
}
F_13 ( V_12 , V_117 ,
V_118 , V_118 ) ;
break;
case V_115 :
F_13 ( V_12 , V_117 ,
V_118 , 0 ) ;
F_46 ( V_29 -> V_116 ) ;
break;
}
return 0 ;
}
static int F_47 ( const char * V_119 )
{
if ( strcmp ( V_119 , L_6 ) == 0 )
return 0 ;
if ( strcmp ( V_119 , L_7 ) == 0 )
return 1 ;
return - V_44 ;
}
static int F_48 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_11 ( V_25 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_120 * V_121 = V_29 -> V_121 ;
int V_45 = F_47 ( V_25 -> V_122 . V_119 ) ;
struct V_58 * V_59 ;
unsigned int V_30 = V_27 -> V_31 . V_123 . V_124 [ 0 ] ;
struct V_125 * V_126 ;
int V_127 , V_128 , V_129 , V_17 ;
int V_130 , V_131 ;
if ( F_5 ( V_45 > 1 ) )
return - V_44 ;
if ( ! V_121 || ! V_29 -> V_132 )
return 0 ;
if ( V_30 >= V_121 -> V_133 )
return - V_44 ;
V_59 = & V_29 -> V_13 [ V_45 ] ;
V_59 -> V_134 = V_30 ;
V_127 = V_59 -> V_50 ;
V_128 = 0 ;
V_129 = V_135 ;
for ( V_17 = 0 ; V_17 < V_121 -> V_133 ; V_17 ++ ) {
if ( strcmp ( V_121 -> V_136 [ V_17 ] . V_119 , V_29 -> V_137 [ V_30 ] ) == 0 &&
abs ( V_121 -> V_136 [ V_17 ] . V_50 - V_127 ) < V_129 ) {
V_128 = V_17 ;
V_129 = abs ( V_121 -> V_136 [ V_17 ] . V_50 - V_127 ) ;
}
}
F_37 ( V_12 -> V_2 , L_8 ,
V_121 -> V_136 [ V_128 ] . V_119 ,
V_121 -> V_136 [ V_128 ] . V_50 , V_127 ) ;
V_126 = & V_121 -> V_136 [ V_128 ] ;
V_130 = ( V_45 == 0 ) ? V_138 : V_139 ;
V_131 = F_28 ( V_12 , V_140 ) ;
F_13 ( V_12 , V_140 , V_130 , 0 ) ;
F_49 ( & V_29 -> V_141 ) ;
F_13 ( V_12 , V_7 , V_142 , V_142 ) ;
F_4 ( V_12 , V_45 , 0 , V_126 -> V_143 ) ;
F_4 ( V_12 , V_45 , 1 , V_126 -> V_144 ) ;
F_4 ( V_12 , V_45 , 2 , V_126 -> V_145 ) ;
F_4 ( V_12 , V_45 , 3 , V_126 -> V_146 ) ;
F_4 ( V_12 , V_45 , 4 , V_126 -> V_147 ) ;
F_13 ( V_12 , V_7 , V_142 , 0 ) ;
F_50 ( & V_29 -> V_141 ) ;
F_13 ( V_12 , V_140 , V_130 , V_131 ) ;
return 0 ;
}
static int F_51 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_11 ( V_25 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
int V_45 = F_47 ( V_25 -> V_122 . V_119 ) ;
struct V_58 * V_59 ;
V_59 = & V_29 -> V_13 [ V_45 ] ;
V_27 -> V_31 . V_123 . V_124 [ 0 ] = V_59 -> V_134 ;
return 0 ;
}
static void F_52 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_120 * V_121 = V_29 -> V_121 ;
struct V_125 * V_148 ;
unsigned int V_149 ;
int V_17 , V_150 ;
const char * * V_151 ;
int V_111 ;
struct V_152 V_153 [] = {
F_53 ( L_6 ,
V_29 -> V_154 ,
F_51 ,
F_48 ) ,
F_53 ( L_7 ,
V_29 -> V_154 ,
F_51 ,
F_48 ) ,
} ;
V_148 = V_121 -> V_136 ;
V_149 = V_121 -> V_133 ;
V_29 -> V_132 = 0 ;
V_29 -> V_137 = NULL ;
for ( V_17 = 0 ; V_17 < V_149 ; V_17 ++ ) {
for ( V_150 = 0 ; V_150 < V_29 -> V_132 ; V_150 ++ ) {
if ( strcmp ( V_148 [ V_17 ] . V_119 , V_29 -> V_137 [ V_150 ] ) == 0 )
break;
}
if ( V_150 != V_29 -> V_132 )
continue;
V_151 = F_54 ( V_29 -> V_137 ,
sizeof( char * ) * ( V_29 -> V_132 + 1 ) ,
V_155 ) ;
if ( V_151 == NULL )
continue;
V_151 [ V_29 -> V_132 ] = V_148 [ V_17 ] . V_119 ;
V_29 -> V_132 ++ ;
V_29 -> V_137 = V_151 ;
}
V_29 -> V_154 . V_156 = V_29 -> V_137 ;
V_29 -> V_154 . V_157 = V_29 -> V_132 ;
V_111 = F_55 ( V_12 , V_153 , F_24 ( V_153 ) ) ;
if ( V_111 != 0 )
F_29 ( V_12 -> V_2 , L_9 , V_111 ) ;
}
static int F_56 ( struct V_11 * V_12 ,
const char * V_119 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_24 ( V_158 ) ; V_17 ++ )
if ( strcmp ( V_119 , V_158 [ V_17 ] ) == 0 )
return V_17 ;
F_29 ( V_12 -> V_2 , L_10 , V_119 ) ;
return - V_44 ;
}
static int F_57 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_11 ( V_25 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_120 * V_121 = V_29 -> V_121 ;
int V_45 = F_56 ( V_12 , V_25 -> V_122 . V_119 ) ;
struct V_58 * V_59 ;
unsigned int V_30 = V_27 -> V_31 . V_123 . V_124 [ 0 ] ;
struct V_159 * V_126 ;
int V_127 , V_128 , V_129 , V_17 ;
int V_130 , V_131 ;
if ( V_45 < 0 )
return V_45 ;
if ( ! V_121 || ! V_29 -> V_160 )
return 0 ;
if ( V_30 >= V_121 -> V_161 )
return - V_44 ;
V_59 = & V_29 -> V_13 [ V_45 ] ;
V_59 -> V_162 = V_30 ;
V_127 = V_59 -> V_50 ;
V_128 = 0 ;
V_129 = V_135 ;
for ( V_17 = 0 ; V_17 < V_121 -> V_161 ; V_17 ++ ) {
if ( strcmp ( V_121 -> V_163 [ V_17 ] . V_119 , V_29 -> V_164 [ V_30 ] ) == 0 &&
abs ( V_121 -> V_163 [ V_17 ] . V_50 - V_127 ) < V_129 ) {
V_128 = V_17 ;
V_129 = abs ( V_121 -> V_163 [ V_17 ] . V_50 - V_127 ) ;
}
}
F_37 ( V_12 -> V_2 , L_8 ,
V_121 -> V_163 [ V_128 ] . V_119 ,
V_121 -> V_163 [ V_128 ] . V_50 , V_127 ) ;
V_126 = & V_121 -> V_163 [ V_128 ] ;
V_130 = ( V_45 == 0 ) ? V_165 : V_166 ;
V_131 = F_28 ( V_12 , V_140 ) ;
F_13 ( V_12 , V_140 , V_130 , 0 ) ;
F_49 ( & V_29 -> V_141 ) ;
F_13 ( V_12 , V_7 , V_142 , V_142 ) ;
F_9 ( V_12 , V_45 , 0 , V_126 -> V_143 ) ;
F_9 ( V_12 , V_45 , 1 , V_126 -> V_144 ) ;
F_13 ( V_12 , V_7 , V_142 , 0 ) ;
F_50 ( & V_29 -> V_141 ) ;
F_13 ( V_12 , V_140 , V_130 , V_131 ) ;
return 0 ;
}
static int F_58 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = F_11 ( V_25 ) ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
int V_45 = F_56 ( V_12 , V_25 -> V_122 . V_119 ) ;
struct V_58 * V_59 ;
if ( V_45 < 0 )
return V_45 ;
V_59 = & V_29 -> V_13 [ V_45 ] ;
V_27 -> V_31 . V_123 . V_124 [ 0 ] = V_59 -> V_162 ;
return 0 ;
}
static void F_59 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_120 * V_121 = V_29 -> V_121 ;
struct V_159 * V_148 ;
unsigned int V_149 ;
int V_17 , V_150 ;
const char * * V_151 ;
int V_111 ;
struct V_152 V_153 [] = {
F_53 ( ( char * ) V_158 [ 0 ] ,
V_29 -> V_167 ,
F_58 ,
F_57 ) ,
F_53 ( ( char * ) V_158 [ 1 ] ,
V_29 -> V_167 ,
F_58 ,
F_57 ) ,
} ;
F_60 ( F_24 ( V_153 ) != F_24 ( V_158 ) ) ;
V_148 = V_121 -> V_163 ;
V_149 = V_121 -> V_161 ;
V_29 -> V_160 = 0 ;
V_29 -> V_164 = NULL ;
for ( V_17 = 0 ; V_17 < V_149 ; V_17 ++ ) {
for ( V_150 = 0 ; V_150 < V_29 -> V_160 ; V_150 ++ ) {
if ( strcmp ( V_148 [ V_17 ] . V_119 , V_29 -> V_164 [ V_150 ] ) == 0 )
break;
}
if ( V_150 != V_29 -> V_160 )
continue;
V_151 = F_54 ( V_29 -> V_164 ,
sizeof( char * ) * ( V_29 -> V_160 + 1 ) ,
V_155 ) ;
if ( V_151 == NULL )
continue;
V_151 [ V_29 -> V_160 ] = V_148 [ V_17 ] . V_119 ;
V_29 -> V_160 ++ ;
V_29 -> V_164 = V_151 ;
}
V_29 -> V_167 . V_156 = V_29 -> V_164 ;
V_29 -> V_167 . V_157 = V_29 -> V_160 ;
V_111 = F_55 ( V_12 , V_153 , F_24 ( V_153 ) ) ;
if ( V_111 != 0 )
F_29 ( V_12 -> V_2 , L_11 , V_111 ) ;
}
static void F_61 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_120 * V_121 = V_29 -> V_121 ;
T_2 V_61 = 0 ;
if ( ! V_121 ) {
F_37 ( V_12 -> V_2 , L_12 ) ;
return;
}
if ( V_121 -> V_168 )
V_61 |= V_169 ;
if ( V_121 -> V_170 )
V_61 |= V_171 ;
F_6 ( V_12 , V_172 , V_61 ) ;
if ( V_121 -> V_133 )
F_52 ( V_12 ) ;
if ( V_121 -> V_161 )
F_59 ( V_12 ) ;
}
static T_3 F_62 ( int V_173 , void * V_174 )
{
struct V_11 * V_12 = V_174 ;
struct V_28 * V_29 = F_12 ( V_12 ) ;
unsigned int V_31 ;
int V_175 = 0 ;
int V_176 = 0 ;
V_31 = F_28 ( V_12 , V_177 ) ;
if ( ( V_31 & V_178 ) == 0 )
return V_179 ;
if ( ( V_31 & V_180 || V_31 & V_181 ) &&
V_29 -> V_182 )
V_175 |= V_183 ;
if ( ( V_31 & V_184 ) && V_29 -> V_185 )
V_176 |= V_186 ;
if ( V_29 -> V_182 == V_29 -> V_185 ) {
F_63 ( V_29 -> V_182 ,
V_175 | V_176 ,
V_187 ) ;
} else {
if ( V_29 -> V_182 )
F_63 ( V_29 -> V_182 ,
V_175 , V_183 ) ;
if ( V_29 -> V_185 )
F_63 ( V_29 -> V_185 ,
V_176 , V_186 ) ;
}
return V_188 ;
}
static int F_64 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
int V_111 = 0 ;
int V_189 = V_190 ;
unsigned int V_191 = V_192 ;
if ( V_29 -> V_121 -> V_193 )
V_189 |= V_194 ;
if ( V_29 -> V_121 -> V_195 )
V_191 = V_29 -> V_121 -> V_195 ;
V_111 = F_6 ( V_12 , V_196 , V_191 ) ;
if ( V_111 < 0 ) {
F_29 ( V_12 -> V_2 , L_13 , V_111 ) ;
return V_111 ;
}
V_111 = F_6 ( V_12 , V_197 , V_189 ) ;
if ( V_111 < 0 ) {
F_29 ( V_12 -> V_2 , L_13 , V_111 ) ;
return V_111 ;
}
return V_111 ;
}
static int F_65 ( struct V_11 * V_12 )
{
int V_111 = 0 ;
V_111 = F_6 ( V_12 , V_197 , 0x0 ) ;
if ( V_111 < 0 ) {
F_29 ( V_12 -> V_2 , L_13 , V_111 ) ;
return V_111 ;
}
return V_111 ;
}
int F_66 ( struct V_11 * V_12 ,
struct V_198 * V_199 , struct V_198 * V_185 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_200 * V_201 = F_67 ( V_12 -> V_2 ) ;
int V_111 = 0 ;
V_29 -> V_182 = V_199 ;
V_29 -> V_185 = V_185 ;
if ( ! V_199 && ! V_185 )
return - V_44 ;
F_64 ( V_12 ) ;
V_111 = F_13 ( V_12 , V_202 ,
V_203 , V_203 ) ;
if ( V_111 < 0 ) {
F_29 ( V_12 -> V_2 , L_14 , V_111 ) ;
return V_111 ;
}
F_62 ( V_201 -> V_173 , V_12 ) ;
return 0 ;
}
static int F_68 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
if ( V_29 -> V_182 || V_29 -> V_185 )
F_65 ( V_12 ) ;
F_69 ( V_12 , V_115 ) ;
return 0 ;
}
static int F_70 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_200 * V_201 = F_67 ( V_12 -> V_2 ) ;
F_69 ( V_12 , V_114 ) ;
if ( V_29 -> V_182 || V_29 -> V_185 ) {
F_64 ( V_12 ) ;
F_62 ( V_201 -> V_173 , V_12 ) ;
}
return 0 ;
}
static int F_71 ( struct V_11 * V_12 )
{
int V_17 , V_111 ;
V_111 = F_6 ( V_12 , V_7 , 0 ) ;
if ( V_111 < 0 ) {
F_29 ( V_12 -> V_2 , L_15 , V_111 ) ;
return V_111 ;
}
V_111 = F_6 ( V_12 , V_5 , 0 ) ;
if ( V_111 < 0 ) {
F_29 ( V_12 -> V_2 , L_16 , V_111 ) ;
return V_111 ;
}
for ( V_17 = V_204 ; V_17 < V_10 ; V_17 ++ ) {
V_111 = F_6 ( V_12 , V_17 , F_28 ( V_12 , V_17 ) ) ;
if ( V_111 < 0 ) {
F_29 ( V_12 -> V_2 , L_17 , V_111 ) ;
return V_111 ;
}
}
return V_111 ;
}
static int F_72 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_58 * V_59 ;
struct V_200 * V_201 ;
int V_111 = 0 ;
V_29 -> V_85 = F_73 ( V_12 -> V_2 , L_18 ) ;
if ( F_74 ( V_29 -> V_85 ) == - V_205 )
return - V_205 ;
F_71 ( V_12 ) ;
V_201 = F_67 ( V_12 -> V_2 ) ;
V_29 -> V_67 = ( unsigned ) - 1 ;
V_29 -> V_132 = 0 ;
V_29 -> V_160 = 0 ;
V_59 = & V_29 -> V_13 [ 0 ] ;
V_59 -> V_50 = ( unsigned ) - 1 ;
V_59 -> V_88 = ( unsigned ) - 1 ;
V_59 -> V_134 = 0 ;
V_59 -> V_162 = 0 ;
V_59 = & V_29 -> V_13 [ 1 ] ;
V_59 -> V_50 = ( unsigned ) - 1 ;
V_59 -> V_88 = ( unsigned ) - 1 ;
V_59 -> V_134 = 0 ;
V_59 -> V_162 = 0 ;
V_59 = & V_29 -> V_13 [ 2 ] ;
V_59 -> V_50 = ( unsigned ) - 1 ;
V_59 -> V_88 = ( unsigned ) - 1 ;
V_59 -> V_134 = 0 ;
V_59 -> V_162 = 0 ;
V_29 -> V_47 = 0 ;
V_29 -> V_32 = 0 ;
V_29 -> V_36 = 0 ;
if ( V_201 -> V_173 ) {
V_111 = F_75 ( V_201 -> V_173 , NULL ,
F_62 ,
V_206 | V_207 |
V_208 , L_19 , V_12 ) ;
if ( V_111 ) {
F_29 ( V_12 -> V_2 , L_20 , V_111 ) ;
goto V_209;
}
}
V_111 = F_28 ( V_12 , V_6 ) ;
if ( V_111 < 0 ) {
F_29 ( V_12 -> V_2 , L_21 ,
V_111 ) ;
goto V_210;
}
F_76 ( V_12 -> V_2 , L_22 , V_111 - 0x40 + 'A' ) ;
F_6 ( V_12 , V_5 , V_211 ) ;
F_6 ( V_12 , V_212 ,
V_213 | V_214 ) ;
F_6 ( V_12 , V_215 ,
V_216 | V_217 ) ;
F_6 ( V_12 , V_218 , V_219 ) ;
F_6 ( V_12 , V_220 , V_221 ) ;
F_6 ( V_12 , V_222 , V_223 ) ;
F_6 ( V_12 , V_224 ,
V_225 | V_226 ) ;
F_6 ( V_12 , V_227 ,
V_228 | V_226 ) ;
F_6 ( V_12 , V_229 ,
V_230 | V_226 ) ;
F_61 ( V_12 ) ;
F_13 ( V_12 , V_5 , V_231 ,
V_231 ) ;
return 0 ;
V_210:
if ( V_201 -> V_173 )
F_77 ( V_201 -> V_173 , V_12 ) ;
V_209:
return V_111 ;
}
static int F_78 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_12 ( V_12 ) ;
struct V_200 * V_201 = F_67 ( V_12 -> V_2 ) ;
if ( V_29 -> V_182 || V_29 -> V_185 )
F_65 ( V_12 ) ;
if ( V_201 -> V_173 )
F_77 ( V_201 -> V_173 , V_12 ) ;
return 0 ;
}
static int F_79 ( struct V_200 * V_232 ,
const struct V_233 * V_122 )
{
struct V_28 * V_29 ;
int V_111 ;
V_29 = F_80 ( & V_232 -> V_2 , sizeof( struct V_28 ) ,
V_155 ) ;
if ( V_29 == NULL )
return - V_234 ;
F_81 ( & V_29 -> V_141 ) ;
V_29 -> V_116 = F_82 ( V_232 , & V_235 ) ;
if ( F_34 ( V_29 -> V_116 ) ) {
V_111 = F_74 ( V_29 -> V_116 ) ;
F_29 ( & V_232 -> V_2 , L_23 , V_111 ) ;
return V_111 ;
}
V_29 -> V_236 = V_122 -> V_237 ;
F_83 ( V_232 , V_29 ) ;
V_29 -> V_121 = V_232 -> V_2 . V_238 ;
V_111 = F_84 ( & V_232 -> V_2 , & V_239 ,
V_240 , F_24 ( V_240 ) ) ;
return V_111 ;
}
static int F_85 ( struct V_200 * V_201 )
{
F_86 ( & V_201 -> V_2 ) ;
return 0 ;
}
