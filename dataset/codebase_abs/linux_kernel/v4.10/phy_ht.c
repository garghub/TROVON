static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
static const T_1 V_5 [] = { V_6 , V_7 , V_8 , } ;
T_1 V_9 ;
int V_10 ;
F_2 ( V_2 , 0x16 , V_4 -> V_11 ) ;
F_2 ( V_2 , 0x17 , V_4 -> V_12 ) ;
F_2 ( V_2 , 0x22 , V_4 -> V_13 ) ;
F_2 ( V_2 , 0x25 , V_4 -> V_14 ) ;
F_2 ( V_2 , 0x27 , V_4 -> V_15 ) ;
F_2 ( V_2 , 0x28 , V_4 -> V_16 ) ;
F_2 ( V_2 , 0x29 , V_4 -> V_17 ) ;
F_2 ( V_2 , 0x2c , V_4 -> V_18 ) ;
F_2 ( V_2 , 0x2d , V_4 -> V_19 ) ;
F_2 ( V_2 , 0x37 , V_4 -> V_20 ) ;
F_2 ( V_2 , 0x41 , V_4 -> V_21 ) ;
F_2 ( V_2 , 0x43 , V_4 -> V_22 ) ;
F_2 ( V_2 , 0x47 , V_4 -> V_23 ) ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
V_9 = V_5 [ V_10 ] ;
F_2 ( V_2 , V_9 | 0x4a , V_4 -> V_24 ) ;
F_2 ( V_2 , V_9 | 0x58 , V_4 -> V_25 ) ;
F_2 ( V_2 , V_9 | 0x5a , V_4 -> V_26 ) ;
F_2 ( V_2 , V_9 | 0x6a , V_4 -> V_27 ) ;
F_2 ( V_2 , V_9 | 0x6d , V_4 -> V_28 ) ;
F_2 ( V_2 , V_9 | 0x6e , V_4 -> V_29 ) ;
F_2 ( V_2 , V_9 | 0x92 , V_4 -> V_30 ) ;
F_2 ( V_2 , V_9 | 0x98 , V_4 -> V_31 ) ;
}
F_3 ( 50 ) ;
F_4 ( V_2 , V_32 , ~ 0x1 ) ;
F_4 ( V_2 , V_33 , ~ 0x4 ) ;
F_5 ( V_2 , V_33 , 0x4 ) ;
F_5 ( V_2 , V_32 , 0x1 ) ;
F_3 ( 300 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_8 | V_34 , 0x1 ) ;
F_7 ( 10 , 20 ) ;
F_5 ( V_2 , V_8 | 0x0BF , 0x1 ) ;
F_8 ( V_2 , V_8 | 0x19B , 0x3 , 0x2 ) ;
F_5 ( V_2 , V_8 | V_34 , 0x2 ) ;
F_7 ( 100 , 200 ) ;
F_4 ( V_2 , V_8 | V_34 , ~ 0x2 ) ;
if ( ! F_9 ( V_2 , V_8 | V_35 , 1 , 1 , 100 ,
1000000 ) )
F_10 ( V_2 -> V_36 , L_1 ) ;
F_4 ( V_2 , V_8 | V_34 , ~ 0x1 ) ;
F_5 ( V_2 , 0xa , 0x60 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
const T_1 V_37 [ 3 ] [ 2 ] = {
{ 0x61 , 0xE9 } , { 0x69 , 0xD5 } , { 0x73 , 0x99 } ,
} ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
F_2 ( V_2 , V_39 , V_37 [ V_38 ] [ 0 ] ) ;
F_2 ( V_2 , V_40 , 0x6E ) ;
F_2 ( V_2 , V_41 , V_37 [ V_38 ] [ 1 ] ) ;
F_2 ( V_2 , V_42 , 0x55 ) ;
if ( ! F_9 ( V_2 , V_43 , 2 , 2 ,
500 , 5000000 ) )
F_10 ( V_2 -> V_36 , L_2 ) ;
F_2 ( V_2 , V_42 , 0x15 ) ;
}
F_4 ( V_2 , V_39 , ~ 0x1 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_44 , ~ V_45 ) ;
F_14 ( V_2 , V_44 , V_46 ) ;
F_13 ( V_2 , V_44 , ~ V_46 ) ;
F_14 ( V_2 , V_44 , V_45 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
const T_1 V_5 [] = { V_6 , V_7 , V_8 } ;
int V_38 ;
F_12 ( V_2 ) ;
F_16 ( V_2 ) ;
for ( V_38 = 0 ; V_38 < F_17 ( V_5 ) ; V_38 ++ )
F_5 ( V_2 , V_5 [ V_38 ] | 0x146 , 0x3 ) ;
F_5 ( V_2 , V_33 , 0x0078 ) ;
F_5 ( V_2 , V_47 , 0x0080 ) ;
F_18 ( 2 ) ;
F_4 ( V_2 , V_33 , ~ 0x0078 ) ;
F_4 ( V_2 , V_47 , ~ 0x0080 ) ;
if ( 1 ) {
F_6 ( V_2 ) ;
F_11 ( V_2 ) ;
}
F_4 ( V_2 , V_48 , ~ 0x0008 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_49 )
{
T_2 V_38 ;
T_1 V_50 = F_20 ( V_2 , V_51 ) ;
F_14 ( V_2 , V_51 , 0x3 ) ;
F_14 ( V_2 , V_52 , V_49 ) ;
for ( V_38 = 0 ; V_38 < 200 ; V_38 ++ ) {
if ( ! ( F_20 ( V_2 , V_53 ) & V_49 ) ) {
V_38 = 0 ;
break;
}
F_18 ( 1 ) ;
}
if ( V_38 )
F_10 ( V_2 -> V_36 , L_3 ) ;
F_21 ( V_2 , V_51 , V_50 ) ;
}
static void F_22 ( struct V_1 * V_2 , bool V_54 )
{
struct V_55 * V_56 = V_2 -> V_57 . V_58 ;
static const T_1 V_59 [ 3 ] = { V_60 ,
V_61 ,
V_62 } ;
int V_38 ;
if ( V_54 ) {
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ )
F_21 ( V_2 , V_59 [ V_38 ] , V_56 -> V_63 [ V_38 ] ) ;
} else {
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ )
V_56 -> V_63 [ V_38 ] = F_20 ( V_2 , V_59 [ V_38 ] ) ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ )
F_21 ( V_2 , V_59 [ V_38 ] , 0x0400 ) ;
}
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 V_64 , T_1 V_65 )
{
T_1 V_66 ;
T_1 V_67 = V_68 |
V_69 |
V_70 ;
V_66 = F_20 ( V_2 , V_71 ) ;
V_66 &= V_67 ;
V_66 &= ~ V_64 ;
V_66 |= ( V_65 & V_64 ) ;
F_24 ( V_2 , V_71 , ~ V_67 , V_66 ) ;
return V_66 ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_72 ;
F_26 ( V_2 , true ) ;
V_72 = F_20 ( V_2 , V_73 ) ;
F_21 ( V_2 , V_73 , V_72 | V_74 ) ;
F_3 ( 1 ) ;
F_21 ( V_2 , V_73 , V_72 & ~ V_74 ) ;
F_26 ( V_2 , false ) ;
F_19 ( V_2 , V_75 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_2 V_38 , V_76 ;
T_1 V_77 [] = { 0x40 , 0x60 , 0x80 } ;
for ( V_38 = 0 ; V_38 < F_17 ( V_77 ) ; V_38 ++ ) {
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ )
F_21 ( V_2 , F_28 ( V_77 [ V_38 ] + V_76 ) , 0 ) ;
}
for ( V_38 = 0 ; V_38 < F_17 ( V_77 ) ; V_38 ++ )
F_21 ( V_2 , F_28 ( V_77 [ V_38 ] + 0xc ) , 0 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_2 V_38 ;
static const T_1 V_78 [ 3 ] [ 2 ] = {
{ V_79 , V_80 } ,
{ V_81 , V_82 } ,
{ V_83 , V_84 } ,
} ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
F_14 ( V_2 , V_78 [ V_38 ] [ 1 ] , 0x4 ) ;
F_14 ( V_2 , V_78 [ V_38 ] [ 0 ] , 0x4 ) ;
F_13 ( V_2 , V_78 [ V_38 ] [ 1 ] , ~ 0x1 ) ;
F_14 ( V_2 , V_78 [ V_38 ] [ 0 ] , 0x1 ) ;
F_30 ( V_2 , F_31 ( 8 , 5 + ( V_38 * 0x10 ) ) , 0 ) ;
F_13 ( V_2 , V_78 [ V_38 ] [ 0 ] , ~ 0x4 ) ;
}
}
static void F_32 ( struct V_1 * V_2 , T_1 * V_85 )
{
V_85 [ 0 ] = F_20 ( V_2 , V_86 ) ;
V_85 [ 1 ] = F_20 ( V_2 , V_87 ) ;
V_85 [ 2 ] = F_20 ( V_2 , V_88 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned int V_38 ;
T_1 V_65 ;
V_65 = 0x1E1F ;
for ( V_38 = 0 ; V_38 < 16 ; V_38 ++ ) {
F_21 ( V_2 , F_34 ( 0x88 + V_38 ) , V_65 ) ;
V_65 -= 0x202 ;
}
V_65 = 0x3E3F ;
for ( V_38 = 0 ; V_38 < 16 ; V_38 ++ ) {
F_21 ( V_2 , F_34 ( 0x98 + V_38 ) , V_65 ) ;
V_65 -= 0x202 ;
}
F_21 ( V_2 , F_34 ( 0x38 ) , 0x668 ) ;
}
static void F_35 ( struct V_1 * V_2 , bool V_89 )
{
T_1 V_66 ;
V_66 = F_36 ( V_2 , V_90 ) ;
F_37 ( V_2 , V_90 ,
V_66 | V_91 ) ;
if ( V_89 )
F_14 ( V_2 , V_92 ,
V_93 | V_94 ) ;
else
F_13 ( V_2 , V_92 ,
( T_1 ) ~ ( V_93 |
V_94 ) ) ;
F_37 ( V_2 , V_90 , V_66 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_55 * V_95 = V_2 -> V_57 . V_58 ;
T_1 V_66 ;
int V_38 ;
V_66 = F_20 ( V_2 , V_96 ) ;
if ( V_66 & 0x1 )
F_14 ( V_2 , V_97 , V_98 ) ;
else if ( V_66 & 0x2 )
F_13 ( V_2 , V_99 , 0x7FFF ) ;
F_13 ( V_2 , V_97 , ~ 0x0004 ) ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
if ( V_95 -> V_100 [ V_38 ] >= 0 ) {
F_30 ( V_2 , F_31 ( 13 , 0x63 + V_38 * 4 ) ,
V_95 -> V_100 [ V_38 ] ) ;
F_30 ( V_2 , F_31 ( 13 , 0x67 + V_38 * 4 ) ,
V_95 -> V_100 [ V_38 ] ) ;
}
}
}
static T_1 F_39 ( struct V_1 * V_2 )
{
int V_38 ;
T_1 V_101 = 20 << 3 ;
F_21 ( V_2 , V_102 , 0x4400 ) ;
for ( V_38 = 0 ; V_38 < V_101 ; V_38 ++ ) {
F_21 ( V_2 , V_103 , 0 ) ;
F_21 ( V_2 , V_104 , 0 ) ;
}
return V_101 ;
}
static void F_40 ( struct V_1 * V_2 , T_1 V_105 , T_1 V_106 ,
T_1 V_107 )
{
struct V_55 * V_95 = V_2 -> V_57 . V_58 ;
T_1 V_50 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
if ( V_95 -> V_100 [ V_38 ] < 0 )
V_95 -> V_100 [ V_38 ] = F_41 ( V_2 , F_31 ( 13 , 0x63 + V_38 * 4 ) ) ;
}
F_21 ( V_2 , V_108 , V_105 - 1 ) ;
if ( V_106 != 0xFFFF )
V_106 -- ;
F_21 ( V_2 , V_109 , V_106 ) ;
F_21 ( V_2 , V_110 , V_107 ) ;
V_50 = F_20 ( V_2 , V_51 ) ;
F_14 ( V_2 , V_51 ,
V_111 ) ;
F_13 ( V_2 , V_97 , ~ 0 ) ;
F_13 ( V_2 , V_97 , ~ 0 ) ;
F_13 ( V_2 , V_99 , ~ 0 ) ;
F_14 ( V_2 , V_97 , 0x1 ) ;
for ( V_38 = 0 ; V_38 < 100 ; V_38 ++ ) {
if ( ! ( F_20 ( V_2 , V_53 ) & 1 ) ) {
V_38 = 0 ;
break;
}
F_3 ( 10 ) ;
}
if ( V_38 )
F_10 ( V_2 -> V_36 , L_4 ) ;
F_21 ( V_2 , V_51 , V_50 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_1 V_112 ;
V_112 = F_39 ( V_2 ) ;
F_40 ( V_2 , V_112 , 0xFFFF , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_2 V_113 ,
enum V_114 V_115 )
{
static const T_1 V_78 [ 3 ] [ 2 ] = {
{ V_80 , V_79 , } ,
{ V_82 , V_81 , } ,
{ V_84 , V_83 , } ,
} ;
static const T_1 V_116 [] = { V_6 , V_7 , V_8 , } ;
int V_10 ;
if ( V_113 == 0 ) {
F_10 ( V_2 -> V_36 , L_5 ) ;
} else {
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
if ( ( V_113 == 1 && V_10 != 0 ) ||
( V_113 == 2 && V_10 != 1 ) ||
( V_113 == 3 && V_10 != 2 ) )
continue;
switch ( V_115 ) {
case V_117 :
F_14 ( V_2 , V_78 [ V_10 ] [ 0 ] , 0x3 << 8 ) ;
F_14 ( V_2 , V_78 [ V_10 ] [ 0 ] , 0x3 << 10 ) ;
F_14 ( V_2 , V_78 [ V_10 ] [ 1 ] , 0x1 << 9 ) ;
F_14 ( V_2 , V_78 [ V_10 ] [ 1 ] , 0x1 << 10 ) ;
F_5 ( V_2 , V_8 | 0xbf , 0x1 ) ;
F_2 ( V_2 , V_116 [ V_10 ] | 0x159 ,
0x11 ) ;
break;
default:
F_10 ( V_2 -> V_36 , L_6 ,
V_115 ) ;
}
}
}
}
static void F_44 ( struct V_1 * V_2 , enum V_114 type ,
T_3 * V_118 , T_2 V_119 )
{
T_1 V_120 [ 12 ] ;
static const T_1 V_121 [] = {
V_80 , V_79 ,
0x848 , 0x841 ,
V_82 , V_81 ,
0x868 , 0x861 ,
V_84 , V_83 ,
0x888 , 0x881 ,
} ;
T_1 V_66 [ 3 ] ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 12 ; V_38 ++ )
V_120 [ V_38 ] = F_20 ( V_2 , V_121 [ V_38 ] ) ;
F_43 ( V_2 , 5 , type ) ;
for ( V_38 = 0 ; V_38 < 6 ; V_38 ++ )
V_118 [ V_38 ] = 0 ;
for ( V_38 = 0 ; V_38 < V_119 ; V_38 ++ ) {
V_66 [ 0 ] = F_20 ( V_2 , V_122 ) ;
V_66 [ 1 ] = F_20 ( V_2 , V_123 ) ;
V_66 [ 2 ] = F_20 ( V_2 , V_124 ) ;
V_118 [ 0 ] += ( ( V_125 ) ( ( V_66 [ 0 ] & 0x3F ) << 2 ) ) >> 2 ;
V_118 [ 1 ] += ( ( V_125 ) ( ( ( V_66 [ 0 ] >> 8 ) & 0x3F ) << 2 ) ) >> 2 ;
V_118 [ 2 ] += ( ( V_125 ) ( ( V_66 [ 1 ] & 0x3F ) << 2 ) ) >> 2 ;
V_118 [ 3 ] += ( ( V_125 ) ( ( ( V_66 [ 1 ] >> 8 ) & 0x3F ) << 2 ) ) >> 2 ;
V_118 [ 4 ] += ( ( V_125 ) ( ( V_66 [ 2 ] & 0x3F ) << 2 ) ) >> 2 ;
V_118 [ 5 ] += ( ( V_125 ) ( ( ( V_66 [ 2 ] >> 8 ) & 0x3F ) << 2 ) ) >> 2 ;
}
for ( V_38 = 0 ; V_38 < 12 ; V_38 ++ )
F_21 ( V_2 , V_121 [ V_38 ] , V_120 [ V_38 ] ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
T_1 V_64 ;
T_4 V_66 = F_41 ( V_2 , F_46 ( 26 , 0xE8 ) ) ;
if ( 0 )
V_64 = 0x2 << ( V_38 * 4 ) ;
else
V_64 = 0 ;
F_13 ( V_2 , F_28 ( 0x108 ) , V_64 ) ;
F_30 ( V_2 , F_31 ( 7 , 0x110 + V_38 ) , V_66 >> 16 ) ;
F_30 ( V_2 , F_47 ( 13 , 0x63 + ( V_38 * 4 ) ) ,
V_66 & 0xFF ) ;
F_30 ( V_2 , F_47 ( 13 , 0x73 + ( V_38 * 4 ) ) ,
V_66 & 0xFF ) ;
}
}
static void F_48 ( struct V_1 * V_2 , bool V_54 )
{
struct V_55 * V_95 = V_2 -> V_57 . V_58 ;
T_1 V_126 = V_127 |
V_128 |
V_129 ;
static const T_1 V_130 [ 3 ] = { V_131 ,
V_132 ,
V_133 } ;
static const T_1 V_134 [ 3 ] = { V_135 ,
V_136 ,
V_137 } ;
int V_38 ;
if ( ! V_54 ) {
if ( F_20 ( V_2 , V_131 ) & V_126 ) {
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ )
V_95 -> V_138 [ V_38 ] =
F_20 ( V_2 , V_134 [ V_38 ] ) ;
}
F_13 ( V_2 , V_131 , ~ V_126 ) ;
} else {
F_14 ( V_2 , V_131 , V_126 ) ;
if ( F_49 ( V_2 -> V_36 ) == V_139 ) {
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ )
F_21 ( V_2 , V_130 [ V_38 ] , 0x32 ) ;
}
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ )
if ( V_95 -> V_138 [ V_38 ] <=
V_140 )
F_21 ( V_2 , V_130 [ V_38 ] ,
V_95 -> V_138 [ V_38 ] ) ;
}
V_95 -> V_141 = V_54 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_55 * V_95 = V_2 -> V_57 . V_58 ;
static const T_1 V_77 [] = { 0x840 , 0x860 , 0x880 } ;
T_1 V_142 [ 3 ] [ 3 ] ;
T_3 V_143 [ 6 ] ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
V_142 [ V_10 ] [ 1 ] = F_20 ( V_2 , V_77 [ V_10 ] + 6 ) ;
V_142 [ V_10 ] [ 2 ] = F_20 ( V_2 , V_77 [ V_10 ] + 7 ) ;
V_142 [ V_10 ] [ 0 ] = F_20 ( V_2 , V_77 [ V_10 ] + 0 ) ;
F_21 ( V_2 , V_77 [ V_10 ] + 6 , 0 ) ;
F_13 ( V_2 , V_77 [ V_10 ] + 7 , ~ 0xF ) ;
F_14 ( V_2 , V_77 [ V_10 ] + 0 , 0x0400 ) ;
F_14 ( V_2 , V_77 [ V_10 ] + 0 , 0x1000 ) ;
}
F_42 ( V_2 ) ;
F_3 ( 20 ) ;
F_44 ( V_2 , V_117 , V_143 , 1 ) ;
F_38 ( V_2 ) ;
F_25 ( V_2 ) ;
V_95 -> V_144 [ 0 ] = V_143 [ 0 ] & 0xff ;
V_95 -> V_144 [ 1 ] = V_143 [ 2 ] & 0xff ;
V_95 -> V_144 [ 2 ] = V_143 [ 4 ] & 0xff ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
F_21 ( V_2 , V_77 [ V_10 ] + 0 , V_142 [ V_10 ] [ 0 ] ) ;
F_21 ( V_2 , V_77 [ V_10 ] + 6 , V_142 [ V_10 ] [ 1 ] ) ;
F_21 ( V_2 , V_77 [ V_10 ] + 7 , V_142 [ V_10 ] [ 2 ] ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
static const T_1 V_5 [] = { V_6 , V_7 , V_8 , } ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
F_5 ( V_2 , 0x8bf , 0x1 ) ;
F_2 ( V_2 , V_5 [ V_10 ] | 0x0159 , 0x0011 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_55 * V_95 = V_2 -> V_57 . V_58 ;
struct V_145 * V_146 = V_2 -> V_2 -> V_147 ;
T_2 * V_148 = V_95 -> V_144 ;
T_2 V_149 [ 3 ] ;
T_5 V_150 [ 3 ] , V_151 [ 3 ] , V_152 [ 3 ] ;
T_1 V_153 = V_2 -> V_57 . V_154 -> V_155 -> V_156 ;
int V_38 , V_157 ;
if ( F_49 ( V_2 -> V_36 ) == V_158 ) {
for ( V_157 = 0 ; V_157 < 3 ; V_157 ++ ) {
V_149 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_160 ;
V_150 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_161 [ 0 ] ;
V_151 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_161 [ 1 ] ;
V_152 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_161 [ 2 ] ;
}
} else if ( V_153 >= 4900 && V_153 < 5100 ) {
for ( V_157 = 0 ; V_157 < 3 ; V_157 ++ ) {
V_149 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_162 ;
V_150 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_163 [ 0 ] ;
V_151 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_163 [ 1 ] ;
V_152 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_163 [ 2 ] ;
}
} else if ( V_153 >= 5100 && V_153 < 5500 ) {
for ( V_157 = 0 ; V_157 < 3 ; V_157 ++ ) {
V_149 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_164 ;
V_150 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_165 [ 0 ] ;
V_151 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_165 [ 1 ] ;
V_152 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_165 [ 2 ] ;
}
} else if ( V_153 >= 5500 ) {
for ( V_157 = 0 ; V_157 < 3 ; V_157 ++ ) {
V_149 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_166 ;
V_150 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_167 [ 0 ] ;
V_151 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_167 [ 1 ] ;
V_152 [ V_157 ] = V_146 -> V_159 [ V_157 ] . V_167 [ 2 ] ;
}
} else {
V_149 [ 0 ] = V_149 [ 1 ] = V_149 [ 2 ] = 52 ;
V_150 [ 0 ] = V_150 [ 1 ] = V_150 [ 2 ] = - 424 ;
V_151 [ 0 ] = V_151 [ 1 ] = V_151 [ 2 ] = 5612 ;
V_152 [ 0 ] = V_152 [ 1 ] = V_152 [ 2 ] = - 1393 ;
}
F_14 ( V_2 , V_168 , V_169 ) ;
F_13 ( V_2 , V_131 ,
~ V_129 & 0xFFFF ) ;
F_14 ( V_2 , V_170 , 0x4000 ) ;
F_24 ( V_2 , V_131 ,
~ V_140 , 0x19 ) ;
F_24 ( V_2 , V_132 ,
~ V_171 , 0x19 ) ;
F_24 ( V_2 , V_133 ,
~ V_172 , 0x19 ) ;
F_14 ( V_2 , V_170 ,
V_173 ) ;
F_24 ( V_2 , V_170 ,
~ V_174 ,
V_148 [ 0 ] << V_175 ) ;
F_24 ( V_2 , V_170 ,
~ V_176 ,
V_148 [ 1 ] << V_177 ) ;
F_24 ( V_2 , V_178 ,
~ V_179 ,
V_148 [ 2 ] << V_180 ) ;
F_24 ( V_2 , V_181 , ~ V_182 ,
0xf0 ) ;
F_24 ( V_2 , V_181 , ~ V_183 ,
0x3 << V_184 ) ;
#if 0
b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_CMD_C1, 0x800, 0)
b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_CMD_C1, 0x400, 0)
#endif
F_24 ( V_2 , V_185 ,
~ V_186 ,
V_149 [ 0 ] << V_187 ) ;
F_24 ( V_2 , V_185 ,
~ V_188 & 0xFFFF ,
V_149 [ 1 ] << V_189 ) ;
F_24 ( V_2 , V_190 ,
~ V_191 ,
V_149 [ 2 ] << V_192 ) ;
for ( V_157 = 0 ; V_157 < 3 ; V_157 ++ ) {
T_3 V_193 , V_194 , V_195 ;
T_4 V_196 [ 64 ] ;
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ ) {
V_193 = 8 * ( 16 * V_151 [ V_157 ] + V_152 [ V_157 ] * V_38 ) ;
V_194 = 32768 + V_150 [ V_157 ] * V_38 ;
V_195 = F_53 ( ( 4 * V_193 + V_194 / 2 ) / V_194 , - 8 ) ;
V_196 [ V_38 ] = V_195 ;
}
F_54 ( V_2 , F_31 ( 26 + V_157 , 0 ) , 64 , V_196 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_197 * V_198 )
{
struct V_199 * V_10 = V_2 -> V_2 -> V_200 ;
int V_201 = 0 ;
if ( V_198 -> V_202 == 13 || V_198 -> V_202 == 14 )
V_201 = 1 ;
F_56 ( V_10 , V_203 , 0 , false ) ;
F_57 ( & V_10 -> V_204 -> V_205 , V_201 ) ;
F_56 ( V_10 ,
V_206 |
V_203 ,
V_207 |
V_208 , false ) ;
F_58 ( V_2 , V_201 ) ;
F_59 ( V_2 ) ;
if ( V_201 )
F_14 ( V_2 , V_73 , V_209 ) ;
else
F_13 ( V_2 , V_73 ,
~ V_209 & 0xFFFF ) ;
F_25 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
const struct V_210 * V_4 ,
struct V_197 * V_198 )
{
if ( V_198 -> V_211 == V_139 ) {
F_13 ( V_2 , V_212 , ~ V_213 ) ;
F_35 ( V_2 , true ) ;
F_14 ( V_2 , V_212 , V_213 ) ;
} else {
F_13 ( V_2 , V_212 , ~ V_213 ) ;
F_35 ( V_2 , false ) ;
}
F_21 ( V_2 , V_214 , V_4 -> V_215 ) ;
F_21 ( V_2 , V_216 , V_4 -> V_217 ) ;
F_21 ( V_2 , V_218 , V_4 -> V_219 ) ;
F_21 ( V_2 , V_220 , V_4 -> V_221 ) ;
F_21 ( V_2 , V_222 , V_4 -> V_223 ) ;
F_21 ( V_2 , V_224 , V_4 -> V_225 ) ;
if ( V_198 -> V_202 == 14 ) {
F_23 ( V_2 , V_69 , 0 ) ;
F_14 ( V_2 , V_226 , 0x0800 ) ;
} else {
F_23 ( V_2 , V_69 ,
V_69 ) ;
if ( V_198 -> V_211 == V_158 )
F_13 ( V_2 , V_226 , ~ 0x840 ) ;
}
if ( 1 )
F_45 ( V_2 ) ;
F_55 ( V_2 , V_198 ) ;
F_21 ( V_2 , 0x017e , 0x3830 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_197 * V_227 ,
enum V_228 V_229 )
{
struct V_230 * V_57 = & V_2 -> V_57 ;
const struct V_3 * V_231 = NULL ;
if ( V_57 -> V_232 == 0x2059 ) {
V_231 = F_62 ( V_2 ,
V_227 -> V_156 ) ;
if ( ! V_231 )
return - V_233 ;
} else {
return - V_233 ;
}
if ( V_57 -> V_232 == 0x2059 ) {
F_1 ( V_2 , V_231 ) ;
F_60 ( V_2 , & ( V_231 -> V_234 ) ,
V_227 ) ;
} else {
return - V_233 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_55 * V_95 ;
V_95 = F_64 ( sizeof( * V_95 ) , V_235 ) ;
if ( ! V_95 )
return - V_236 ;
V_2 -> V_57 . V_58 = V_95 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_230 * V_57 = & V_2 -> V_57 ;
struct V_55 * V_95 = V_57 -> V_58 ;
int V_38 ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_141 = true ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ )
V_95 -> V_138 [ V_38 ] = V_140 + 1 ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ )
V_95 -> V_100 [ V_38 ] = - 1 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_55 * V_95 = V_2 -> V_57 . V_58 ;
T_1 V_66 ;
T_1 V_237 [ 3 ] ;
bool V_238 ;
if ( V_2 -> V_2 -> V_239 != V_240 ) {
F_10 ( V_2 -> V_36 , L_7 ) ;
return - V_241 ;
}
F_67 ( V_2 ) ;
F_13 ( V_2 , 0x0be , ~ 0x2 ) ;
F_14 ( V_2 , 0x23f , 0x7ff ) ;
F_14 ( V_2 , 0x240 , 0x7ff ) ;
F_14 ( V_2 , 0x241 , 0x7ff ) ;
F_27 ( V_2 ) ;
F_13 ( V_2 , F_28 ( 0 ) , ~ 0x3 ) ;
F_21 ( V_2 , V_79 , 0 ) ;
F_21 ( V_2 , V_81 , 0 ) ;
F_21 ( V_2 , V_83 , 0 ) ;
F_21 ( V_2 , F_28 ( 0x103 ) , 0x20 ) ;
F_21 ( V_2 , F_28 ( 0x101 ) , 0x20 ) ;
F_21 ( V_2 , 0x20d , 0xb8 ) ;
F_21 ( V_2 , F_28 ( 0x14f ) , 0xc8 ) ;
F_21 ( V_2 , 0x70 , 0x50 ) ;
F_21 ( V_2 , 0x1ff , 0x30 ) ;
if ( 0 )
;
if ( F_49 ( V_2 -> V_36 ) == V_139 )
F_23 ( V_2 , V_68 , 0 ) ;
else
F_23 ( V_2 , V_68 ,
V_68 ) ;
F_14 ( V_2 , 0xb1 , 0x91 ) ;
F_21 ( V_2 , 0x32f , 0x0003 ) ;
F_21 ( V_2 , 0x077 , 0x0010 ) ;
F_21 ( V_2 , 0x0b4 , 0x0258 ) ;
F_13 ( V_2 , 0x17e , ~ 0x4000 ) ;
F_21 ( V_2 , 0x0b9 , 0x0072 ) ;
F_68 ( V_2 , F_31 ( 7 , 0x14e ) , 2 , 0x010f , 0x010f ) ;
F_68 ( V_2 , F_31 ( 7 , 0x15e ) , 2 , 0x010f , 0x010f ) ;
F_68 ( V_2 , F_31 ( 7 , 0x16e ) , 2 , 0x010f , 0x010f ) ;
F_29 ( V_2 ) ;
F_68 ( V_2 , F_31 ( 7 , 0x130 ) , 9 , 0x777 , 0x111 , 0x111 ,
0x777 , 0x111 , 0x111 , 0x777 , 0x111 , 0x111 ) ;
F_30 ( V_2 , F_31 ( 7 , 0x120 ) , 0x0777 ) ;
F_30 ( V_2 , F_31 ( 7 , 0x124 ) , 0x0777 ) ;
F_30 ( V_2 , F_31 ( 8 , 0x00 ) , 0x02 ) ;
F_30 ( V_2 , F_31 ( 8 , 0x10 ) , 0x02 ) ;
F_30 ( V_2 , F_31 ( 8 , 0x20 ) , 0x02 ) ;
F_68 ( V_2 , F_31 ( 8 , 0x08 ) , 4 ,
0x8e , 0x96 , 0x96 , 0x96 ) ;
F_68 ( V_2 , F_31 ( 8 , 0x18 ) , 4 ,
0x8f , 0x9f , 0x9f , 0x9f ) ;
F_68 ( V_2 , F_31 ( 8 , 0x28 ) , 4 ,
0x8f , 0x9f , 0x9f , 0x9f ) ;
F_68 ( V_2 , F_31 ( 8 , 0x0c ) , 4 , 0x2 , 0x2 , 0x2 , 0x2 ) ;
F_68 ( V_2 , F_31 ( 8 , 0x1c ) , 4 , 0x2 , 0x2 , 0x2 , 0x2 ) ;
F_68 ( V_2 , F_31 ( 8 , 0x2c ) , 4 , 0x2 , 0x2 , 0x2 , 0x2 ) ;
F_24 ( V_2 , 0x0280 , 0xff00 , 0x3e ) ;
F_24 ( V_2 , 0x0283 , 0xff00 , 0x3e ) ;
F_24 ( V_2 , F_69 ( 0x0141 ) , 0xff00 , 0x46 ) ;
F_24 ( V_2 , 0x0283 , 0xff00 , 0x40 ) ;
F_68 ( V_2 , F_31 ( 00 , 0x8 ) , 4 ,
0x09 , 0x0e , 0x13 , 0x18 ) ;
F_68 ( V_2 , F_31 ( 01 , 0x8 ) , 4 ,
0x09 , 0x0e , 0x13 , 0x18 ) ;
F_68 ( V_2 , F_31 ( 40 , 0x8 ) , 4 ,
0x09 , 0x0e , 0x13 , 0x18 ) ;
F_24 ( V_2 , F_69 ( 0x24 ) , 0x3f , 0xd ) ;
F_24 ( V_2 , F_69 ( 0x64 ) , 0x3f , 0xd ) ;
F_24 ( V_2 , F_69 ( 0xa4 ) , 0x3f , 0xd ) ;
F_14 ( V_2 , F_28 ( 0x060 ) , 0x1 ) ;
F_14 ( V_2 , F_28 ( 0x064 ) , 0x1 ) ;
F_14 ( V_2 , F_28 ( 0x080 ) , 0x1 ) ;
F_14 ( V_2 , F_28 ( 0x084 ) , 0x1 ) ;
V_66 = F_41 ( V_2 , F_31 ( 7 , 0x144 ) ) ;
F_30 ( V_2 , F_31 ( 7 , 0x14a ) , V_66 ) ;
V_66 = F_41 ( V_2 , F_31 ( 7 , 0x154 ) ) ;
F_30 ( V_2 , F_31 ( 7 , 0x15a ) , V_66 ) ;
V_66 = F_41 ( V_2 , F_31 ( 7 , 0x164 ) ) ;
F_30 ( V_2 , F_31 ( 7 , 0x16a ) , V_66 ) ;
F_26 ( V_2 , true ) ;
V_66 = F_20 ( V_2 , V_73 ) ;
F_21 ( V_2 , V_73 , V_66 | V_74 ) ;
F_21 ( V_2 , V_73 , V_66 & ~ V_74 ) ;
F_26 ( V_2 , false ) ;
F_70 ( V_2 , true ) ;
F_22 ( V_2 , false ) ;
F_19 ( V_2 , V_242 ) ;
F_19 ( V_2 , V_75 ) ;
F_22 ( V_2 , true ) ;
F_23 ( V_2 , 0 , 0 ) ;
F_32 ( V_2 , V_237 ) ;
if ( F_49 ( V_2 -> V_36 ) == V_158 )
F_33 ( V_2 ) ;
F_54 ( V_2 , F_46 ( 0x1a , 0xc0 ) ,
V_243 , V_244 ) ;
V_238 = V_95 -> V_141 ;
F_45 ( V_2 ) ;
F_48 ( V_2 , false ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
F_51 ( V_2 ) ;
F_48 ( V_2 , V_238 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_230 * V_57 = & V_2 -> V_57 ;
struct V_55 * V_95 = V_57 -> V_58 ;
F_72 ( V_95 ) ;
V_57 -> V_58 = NULL ;
}
static void F_73 ( struct V_1 * V_2 ,
bool V_245 )
{
if ( F_74 ( V_2 , V_246 ) & V_247 )
F_10 ( V_2 -> V_36 , L_8 ) ;
if ( V_245 ) {
F_13 ( V_2 , V_44 ,
~ V_45 ) ;
} else {
if ( V_2 -> V_57 . V_232 == 0x2059 )
F_15 ( V_2 ) ;
else
F_75 ( 1 ) ;
F_76 ( V_2 , V_2 -> V_57 . V_227 ) ;
}
}
static void F_77 ( struct V_1 * V_2 , bool V_248 )
{
if ( V_248 ) {
F_21 ( V_2 , V_80 , 0x00cd ) ;
F_21 ( V_2 , V_79 , 0x0000 ) ;
F_21 ( V_2 , V_82 , 0x00cd ) ;
F_21 ( V_2 , V_81 , 0x0000 ) ;
F_21 ( V_2 , V_84 , 0x00cd ) ;
F_21 ( V_2 , V_83 , 0x0000 ) ;
} else {
F_21 ( V_2 , V_79 , 0x07ff ) ;
F_21 ( V_2 , V_80 , 0x00fd ) ;
F_21 ( V_2 , V_81 , 0x07ff ) ;
F_21 ( V_2 , V_82 , 0x00fd ) ;
F_21 ( V_2 , V_83 , 0x07ff ) ;
F_21 ( V_2 , V_84 , 0x00fd ) ;
}
}
static int F_78 ( struct V_1 * V_2 ,
unsigned int V_198 )
{
struct V_197 * V_227 = V_2 -> V_36 -> V_249 -> V_250 . V_154 . V_155 ;
enum V_228 V_229 =
F_79 ( & V_2 -> V_36 -> V_249 -> V_250 . V_154 ) ;
if ( F_49 ( V_2 -> V_36 ) == V_158 ) {
if ( ( V_198 < 1 ) || ( V_198 > 14 ) )
return - V_251 ;
} else {
return - V_251 ;
}
return F_61 ( V_2 , V_227 , V_229 ) ;
}
static unsigned int F_80 ( struct V_1 * V_2 )
{
if ( F_49 ( V_2 -> V_36 ) == V_158 )
return 11 ;
return 36 ;
}
static void F_81 ( struct V_1 * V_2 , T_1 V_252 , T_1 V_64 ,
T_1 V_253 )
{
F_82 ( V_2 , V_254 , V_252 ) ;
F_37 ( V_2 , V_255 ,
( F_36 ( V_2 , V_255 ) & V_64 ) | V_253 ) ;
}
static T_1 F_83 ( struct V_1 * V_2 , T_1 V_252 )
{
V_252 |= 0x200 ;
F_82 ( V_2 , V_256 , V_252 ) ;
return F_36 ( V_2 , V_257 ) ;
}
static void F_84 ( struct V_1 * V_2 , T_1 V_252 ,
T_1 V_258 )
{
F_82 ( V_2 , V_256 , V_252 ) ;
F_37 ( V_2 , V_257 , V_258 ) ;
}
static enum V_259
F_85 ( struct V_1 * V_2 , bool V_260 )
{
return V_261 ;
}
static void F_86 ( struct V_1 * V_2 )
{
}
