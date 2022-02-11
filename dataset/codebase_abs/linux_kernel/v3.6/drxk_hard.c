static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ||
V_2 -> V_3 == V_6 ||
V_2 -> V_3 == V_7 ;
}
bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_8 ;
}
bool F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_9 ;
}
static inline T_1 F_5 ( T_1 V_10 , T_1 V_11 , T_1 V_12 )
{
T_2 V_13 ;
V_13 = ( T_2 ) V_10 * ( T_2 ) V_11 ;
F_6 ( V_13 , V_12 ) ;
return ( T_1 ) V_13 ;
}
inline T_1 F_7 ( T_1 V_10 , T_1 V_12 )
{
int V_14 = 0 ;
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
V_16 = ( V_10 % V_12 ) << 4 ;
V_15 = V_10 / V_12 ;
for ( V_14 = 0 ; V_14 < 7 ; V_14 ++ ) {
V_15 = ( V_15 << 4 ) | ( V_16 / V_12 ) ;
V_16 = ( V_16 % V_12 ) << 4 ;
}
if ( ( V_16 >> 3 ) >= V_12 )
V_15 ++ ;
return V_15 ;
}
static T_1 F_8 ( T_1 V_17 )
{
static const T_3 V_18 = 15 ;
static const T_3 V_19 = 5 ;
T_3 V_14 = 0 ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
static const T_1 V_24 [] = {
0 ,
290941 ,
573196 ,
847269 ,
1113620 ,
1372674 ,
1624818 ,
1870412 ,
2109788 ,
2343253 ,
2571091 ,
2793569 ,
3010931 ,
3223408 ,
3431216 ,
3634553 ,
3833610 ,
4028562 ,
4219576 ,
4406807 ,
4590402 ,
4770499 ,
4947231 ,
5120719 ,
5291081 ,
5458428 ,
5622864 ,
5784489 ,
5943398 ,
6099680 ,
6253421 ,
6404702 ,
6553600 ,
} ;
if ( V_17 == 0 )
return 0 ;
if ( ( V_17 & ( ( 0xffffffff ) << ( V_18 + 1 ) ) ) == 0 ) {
for ( V_22 = V_18 ; V_22 > 0 ; V_22 -- ) {
if ( V_17 & ( ( ( T_1 ) 1 ) << V_18 ) )
break;
V_17 <<= 1 ;
}
} else {
for ( V_22 = V_18 ; V_22 < 31 ; V_22 ++ ) {
if ( ( V_17 & ( ( ( T_1 ) ( - 1 ) ) << ( V_18 + 1 ) ) ) == 0 )
break;
V_17 >>= 1 ;
}
}
V_20 = V_22 * ( ( ( ( T_1 ) 1 ) << V_18 ) * 200 ) ;
V_17 &= ( ( ( ( T_1 ) 1 ) << V_18 ) - 1 ) ;
V_14 = ( T_3 ) ( V_17 >> ( V_18 - V_19 ) ) ;
V_21 = V_17 & ( ( ( ( T_1 ) 1 ) << ( V_18 - V_19 ) ) - 1 ) ;
V_20 += V_24 [ V_14 ] +
( ( V_21 * ( V_24 [ V_14 + 1 ] - V_24 [ V_14 ] ) ) >> ( V_18 - V_19 ) ) ;
V_20 /= 108853 ;
V_23 = ( V_20 >> 1 ) ;
if ( V_20 & ( ( T_1 ) 1 ) )
V_23 ++ ;
return V_23 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_25 ) ;
V_2 -> V_26 = true ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_26 )
return;
F_12 ( V_2 -> V_25 ) ;
V_2 -> V_26 = false ;
}
static int F_13 ( struct V_1 * V_2 , struct V_27 * V_28 ,
unsigned V_29 )
{
if ( V_2 -> V_26 )
return F_14 ( V_2 -> V_25 , V_28 , V_29 ) ;
else
return F_15 ( V_2 -> V_25 , V_28 , V_29 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_3 V_30 , T_3 * V_31 )
{
struct V_27 V_28 [ 1 ] = { { . V_32 = V_30 , . V_33 = V_34 ,
. V_35 = V_31 , . V_29 = 1 }
} ;
return F_13 ( V_2 , V_28 , 1 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_30 , T_3 * V_36 , int V_29 )
{
int V_37 ;
struct V_27 V_38 = {
. V_32 = V_30 , . V_33 = 0 , . V_35 = V_36 , . V_29 = V_29 } ;
F_18 ( 3 , L_1 ) ;
if ( V_39 > 2 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_29 ; V_14 ++ )
F_19 ( V_40 L_2 , V_36 [ V_14 ] ) ;
F_19 ( V_40 L_3 ) ;
}
V_37 = F_13 ( V_2 , & V_38 , 1 ) ;
if ( V_37 >= 0 && V_37 != 1 )
V_37 = - V_41 ;
if ( V_37 < 0 )
F_19 ( V_42 L_4 , V_30 ) ;
return V_37 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_3 V_30 , T_3 * V_38 , int V_29 , T_3 * V_43 , int V_44 )
{
int V_37 ;
struct V_27 V_28 [ 2 ] = {
{ . V_32 = V_30 , . V_33 = 0 ,
. V_35 = V_38 , . V_29 = V_29 } ,
{ . V_32 = V_30 , . V_33 = V_34 ,
. V_35 = V_43 , . V_29 = V_44 }
} ;
V_37 = F_13 ( V_2 , V_28 , 2 ) ;
if ( V_37 != 2 ) {
if ( V_39 > 2 )
F_19 ( V_40 L_5 ) ;
if ( V_37 >= 0 )
V_37 = - V_41 ;
F_19 ( V_42 L_6 , V_30 ) ;
return V_37 ;
}
if ( V_39 > 2 ) {
int V_14 ;
F_18 ( 2 , L_7 ) ;
for ( V_14 = 0 ; V_14 < V_29 ; V_14 ++ )
F_19 ( V_40 L_2 , V_38 [ V_14 ] ) ;
F_19 ( V_40 L_8 ) ;
for ( V_14 = 0 ; V_14 < V_44 ; V_14 ++ )
F_19 ( V_40 L_2 , V_43 [ V_14 ] ) ;
F_19 ( V_40 L_3 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_45 , T_4 * V_36 , T_3 V_33 )
{
int V_37 ;
T_3 V_30 = V_2 -> V_46 , V_47 [ 4 ] , V_48 [ 2 ] , V_29 ;
if ( V_2 -> V_49 )
V_33 |= 0xC0 ;
if ( F_22 ( V_45 ) || ( V_33 != 0 ) ) {
V_47 [ 0 ] = ( ( ( V_45 << 1 ) & 0xFF ) | 0x01 ) ;
V_47 [ 1 ] = ( ( V_45 >> 16 ) & 0xFF ) ;
V_47 [ 2 ] = ( ( V_45 >> 24 ) & 0xFF ) | V_33 ;
V_47 [ 3 ] = ( ( V_45 >> 7 ) & 0xFF ) ;
V_29 = 4 ;
} else {
V_47 [ 0 ] = ( ( V_45 << 1 ) & 0xFF ) ;
V_47 [ 1 ] = ( ( ( V_45 >> 16 ) & 0x0F ) | ( ( V_45 >> 18 ) & 0xF0 ) ) ;
V_29 = 2 ;
}
F_18 ( 2 , L_9 , V_45 , V_33 ) ;
V_37 = F_20 ( V_2 , V_30 , V_47 , V_29 , V_48 , 2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_36 )
* V_36 = V_48 [ 0 ] | ( V_48 [ 1 ] << 8 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_45 , T_4 * V_36 )
{
return F_21 ( V_2 , V_45 , V_36 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_45 , T_1 * V_36 , T_3 V_33 )
{
int V_37 ;
T_3 V_30 = V_2 -> V_46 , V_47 [ 4 ] , V_48 [ 4 ] , V_29 ;
if ( V_2 -> V_49 )
V_33 |= 0xC0 ;
if ( F_22 ( V_45 ) || ( V_33 != 0 ) ) {
V_47 [ 0 ] = ( ( ( V_45 << 1 ) & 0xFF ) | 0x01 ) ;
V_47 [ 1 ] = ( ( V_45 >> 16 ) & 0xFF ) ;
V_47 [ 2 ] = ( ( V_45 >> 24 ) & 0xFF ) | V_33 ;
V_47 [ 3 ] = ( ( V_45 >> 7 ) & 0xFF ) ;
V_29 = 4 ;
} else {
V_47 [ 0 ] = ( ( V_45 << 1 ) & 0xFF ) ;
V_47 [ 1 ] = ( ( ( V_45 >> 16 ) & 0x0F ) | ( ( V_45 >> 18 ) & 0xF0 ) ) ;
V_29 = 2 ;
}
F_18 ( 2 , L_9 , V_45 , V_33 ) ;
V_37 = F_20 ( V_2 , V_30 , V_47 , V_29 , V_48 , 4 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_36 )
* V_36 = V_48 [ 0 ] | ( V_48 [ 1 ] << 8 ) |
( V_48 [ 2 ] << 16 ) | ( V_48 [ 3 ] << 24 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_45 , T_1 * V_36 )
{
return F_24 ( V_2 , V_45 , V_36 , 0 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_45 , T_4 V_36 , T_3 V_33 )
{
T_3 V_30 = V_2 -> V_46 , V_50 [ 6 ] , V_29 ;
if ( V_2 -> V_49 )
V_33 |= 0xC0 ;
if ( F_22 ( V_45 ) || ( V_33 != 0 ) ) {
V_50 [ 0 ] = ( ( ( V_45 << 1 ) & 0xFF ) | 0x01 ) ;
V_50 [ 1 ] = ( ( V_45 >> 16 ) & 0xFF ) ;
V_50 [ 2 ] = ( ( V_45 >> 24 ) & 0xFF ) | V_33 ;
V_50 [ 3 ] = ( ( V_45 >> 7 ) & 0xFF ) ;
V_29 = 4 ;
} else {
V_50 [ 0 ] = ( ( V_45 << 1 ) & 0xFF ) ;
V_50 [ 1 ] = ( ( ( V_45 >> 16 ) & 0x0F ) | ( ( V_45 >> 18 ) & 0xF0 ) ) ;
V_29 = 2 ;
}
V_50 [ V_29 ] = V_36 & 0xff ;
V_50 [ V_29 + 1 ] = ( V_36 >> 8 ) & 0xff ;
F_18 ( 2 , L_10 , V_45 , V_36 , V_33 ) ;
return F_17 ( V_2 , V_30 , V_50 , V_29 + 2 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_45 , T_4 V_36 )
{
return F_26 ( V_2 , V_45 , V_36 , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_45 , T_1 V_36 , T_3 V_33 )
{
T_3 V_30 = V_2 -> V_46 , V_50 [ 8 ] , V_29 ;
if ( V_2 -> V_49 )
V_33 |= 0xC0 ;
if ( F_22 ( V_45 ) || ( V_33 != 0 ) ) {
V_50 [ 0 ] = ( ( ( V_45 << 1 ) & 0xFF ) | 0x01 ) ;
V_50 [ 1 ] = ( ( V_45 >> 16 ) & 0xFF ) ;
V_50 [ 2 ] = ( ( V_45 >> 24 ) & 0xFF ) | V_33 ;
V_50 [ 3 ] = ( ( V_45 >> 7 ) & 0xFF ) ;
V_29 = 4 ;
} else {
V_50 [ 0 ] = ( ( V_45 << 1 ) & 0xFF ) ;
V_50 [ 1 ] = ( ( ( V_45 >> 16 ) & 0x0F ) | ( ( V_45 >> 18 ) & 0xF0 ) ) ;
V_29 = 2 ;
}
V_50 [ V_29 ] = V_36 & 0xff ;
V_50 [ V_29 + 1 ] = ( V_36 >> 8 ) & 0xff ;
V_50 [ V_29 + 2 ] = ( V_36 >> 16 ) & 0xff ;
V_50 [ V_29 + 3 ] = ( V_36 >> 24 ) & 0xff ;
F_18 ( 2 , L_11 , V_45 , V_36 , V_33 ) ;
return F_17 ( V_2 , V_30 , V_50 , V_29 + 4 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_45 , T_1 V_36 )
{
return F_28 ( V_2 , V_45 , V_36 , 0 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_51 ,
const int V_52 , const T_3 V_53 [] )
{
int V_37 = 0 , V_54 = V_52 ;
T_3 V_55 = 0 ;
if ( V_2 -> V_49 )
V_55 |= 0xC0 ;
while ( V_54 > 0 ) {
int V_56 = V_54 > V_2 -> V_57 ?
V_2 -> V_57 : V_54 ;
T_3 * V_58 = & V_2 -> V_56 [ 0 ] ;
T_1 V_59 = 0 ;
if ( F_22 ( V_51 ) || ( V_55 != 0 ) ) {
V_58 [ 0 ] = ( ( ( V_51 << 1 ) & 0xFF ) | 0x01 ) ;
V_58 [ 1 ] = ( ( V_51 >> 16 ) & 0xFF ) ;
V_58 [ 2 ] = ( ( V_51 >> 24 ) & 0xFF ) ;
V_58 [ 3 ] = ( ( V_51 >> 7 ) & 0xFF ) ;
V_58 [ 2 ] |= V_55 ;
V_59 = 4 ;
if ( V_56 == V_2 -> V_57 )
V_56 -= 2 ;
} else {
V_58 [ 0 ] = ( ( V_51 << 1 ) & 0xFF ) ;
V_58 [ 1 ] = ( ( ( V_51 >> 16 ) & 0x0F ) |
( ( V_51 >> 18 ) & 0xF0 ) ) ;
V_59 = 2 ;
}
memcpy ( & V_2 -> V_56 [ V_59 ] , V_53 , V_56 ) ;
F_18 ( 2 , L_9 , V_51 , V_55 ) ;
if ( V_39 > 1 ) {
int V_14 ;
if ( V_53 )
for ( V_14 = 0 ; V_14 < V_56 ; V_14 ++ )
F_19 ( V_40 L_2 , V_53 [ V_14 ] ) ;
F_19 ( V_40 L_3 ) ;
}
V_37 = F_17 ( V_2 , V_2 -> V_46 ,
& V_2 -> V_56 [ 0 ] , V_56 + V_59 ) ;
if ( V_37 < 0 ) {
F_19 ( V_42 L_12 ,
V_60 , V_51 ) ;
break;
}
V_53 += V_56 ;
V_51 += ( V_56 >> 1 ) ;
V_54 -= V_56 ;
}
return V_37 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_37 ;
T_3 V_36 = 0 ;
T_4 V_61 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_16 ( V_2 , V_2 -> V_46 , & V_36 ) ;
if ( V_37 < 0 ) {
do {
V_36 = 0 ;
V_37 = F_17 ( V_2 , V_2 -> V_46 ,
& V_36 , 1 ) ;
F_32 ( 10 ) ;
V_61 ++ ;
if ( V_37 < 0 )
continue;
V_37 = F_16 ( V_2 , V_2 -> V_46 ,
& V_36 ) ;
} while ( V_37 < 0 &&
( V_61 < V_62 ) );
if ( V_37 < 0 && V_61 >= V_62 )
goto error;
}
V_37 = F_27 ( V_2 , V_63 , V_64 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_65 , V_66 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_67 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_68 = V_69 ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_1 V_70 = V_71 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
T_1 V_74 = 0x7FFF ;
T_1 V_75 = 3 ;
T_1 V_76 = V_71 ;
T_1 V_77 = 0 ;
T_1 V_78 = 0 ;
T_1 V_79 = 0x7FFF ;
T_1 V_80 = 3 ;
T_1 V_81 = 9500 ;
T_1 V_82 = 4000 ;
T_1 V_83 = V_71 ;
T_1 V_84 = 0 ;
T_1 V_85 = 0 ;
T_1 V_86 = 0 ;
T_1 V_87 = 3 ;
T_1 V_88 = V_89 ;
T_1 V_90 = 0 ;
T_1 V_91 = 0 ;
T_1 V_92 = 0 ;
T_1 V_93 = 9500 ;
T_1 V_94 = 4000 ;
T_1 V_95 = 3 ;
T_1 V_96 = V_97 ;
T_1 V_98 = V_99 ;
T_1 V_100 = V_101 ;
T_1 V_102 = V_103 ;
T_1 V_104 = 0x0113 ;
T_1 V_105 = 0 ;
T_1 V_106 = V_107 ;
T_1 V_108 = 50000000 ;
T_1 V_109 = V_110 * 8 ;
T_1 V_111 = 0 ;
T_1 V_112 = 1 ;
T_1 V_113 = 0 ;
F_18 ( 1 , L_3 ) ;
V_2 -> V_114 = false ;
V_2 -> V_115 = false ;
V_2 -> V_116 = false ;
V_2 -> V_117 = false ;
V_2 -> V_118 = false ;
V_2 -> V_119 = false ;
if ( ! V_2 -> V_57 )
V_2 -> V_57 = 124 ;
V_2 -> V_120 = 0 ;
V_2 -> V_121 = false ;
V_2 -> V_122 = false ;
V_2 -> V_123 = 151875 ;
V_2 -> V_124 = ( ( V_2 -> V_123 / 1000 ) *
V_125 ) / 1000 ;
if ( V_2 -> V_124 > V_126 )
V_2 -> V_124 = V_126 ;
V_2 -> V_127 = ( V_2 -> V_46 << 1 ) ;
V_2 -> V_128 = V_129 ;
V_2 -> V_130 = ( V_113 != 0 ) ;
V_2 -> V_8 = false ;
V_2 -> V_9 = false ;
V_2 -> V_131 = false ;
V_2 -> V_132 = false ;
V_2 -> V_133 = false ;
V_2 -> V_134 = false ;
V_2 -> V_135 . V_136 = ( V_70 ) ;
V_2 -> V_135 . V_137 = ( V_72 ) ;
V_2 -> V_135 . V_138 = ( V_73 ) ;
V_2 -> V_135 . V_139 = ( V_74 ) ;
V_2 -> V_135 . V_140 = ( V_75 ) ;
V_2 -> V_141 = 140 ;
V_2 -> V_142 . V_136 = ( V_76 ) ;
V_2 -> V_142 . V_137 = ( V_77 ) ;
V_2 -> V_142 . V_138 = ( V_78 ) ;
V_2 -> V_142 . V_139 = ( V_79 ) ;
V_2 -> V_142 . V_140 = ( V_80 ) ;
V_2 -> V_142 . V_143 = ( V_81 ) ;
V_2 -> V_142 . V_144 = ( V_82 ) ;
V_2 -> V_145 . V_146 = 0x07 ;
V_2 -> V_145 . V_147 = true ;
V_2 -> V_148 = V_97 ;
V_2 -> V_149 = V_99 ;
if ( V_98 <= 500 && V_96 < V_98 ) {
V_2 -> V_148 = V_96 ;
V_2 -> V_149 = V_98 ;
}
V_2 -> V_150 . V_136 = ( V_83 ) ;
V_2 -> V_150 . V_137 = ( V_84 ) ;
V_2 -> V_150 . V_138 = ( V_85 ) ;
V_2 -> V_150 . V_139 = ( V_86 ) ;
V_2 -> V_150 . V_140 = ( V_87 ) ;
V_2 -> V_151 . V_136 = ( V_88 ) ;
V_2 -> V_151 . V_137 = ( V_90 ) ;
V_2 -> V_151 . V_138 = ( V_91 ) ;
V_2 -> V_151 . V_139 = ( V_92 ) ;
V_2 -> V_151 . V_140 = ( V_95 ) ;
V_2 -> V_151 . V_143 = ( V_93 ) ;
V_2 -> V_151 . V_144 = ( V_94 ) ;
V_2 -> V_152 . V_146 = 0x04 ;
V_2 -> V_152 . V_147 = true ;
V_2 -> V_153 . V_136 = V_89 ;
V_2 -> V_153 . V_137 = 0 ;
V_2 -> V_153 . V_138 = 0 ;
V_2 -> V_153 . V_139 = 0xFFFF ;
V_2 -> V_153 . V_143 = 0x2100 ;
V_2 -> V_153 . V_144 = 4000 ;
V_2 -> V_153 . V_140 = 1 ;
V_2 -> V_154 . V_136 = V_71 ;
V_2 -> V_154 . V_137 = 0 ;
V_2 -> V_154 . V_138 = 0 ;
V_2 -> V_154 . V_139 = 9000 ;
V_2 -> V_154 . V_143 = 13424 ;
V_2 -> V_154 . V_144 = 0 ;
V_2 -> V_154 . V_140 = 3 ;
V_2 -> V_154 . V_155 = 30 ;
V_2 -> V_154 . V_156 = 30000 ;
V_2 -> V_157 . V_146 = 4 ;
V_2 -> V_157 . V_147 = false ;
V_2 -> V_158 . V_136 = V_89 ;
V_2 -> V_158 . V_137 = 0 ;
V_2 -> V_158 . V_138 = 6023 ;
V_2 -> V_158 . V_139 = 27000 ;
V_2 -> V_158 . V_143 = 0x2380 ;
V_2 -> V_158 . V_144 = 4000 ;
V_2 -> V_158 . V_140 = 3 ;
V_2 -> V_159 . V_136 = V_71 ;
V_2 -> V_159 . V_137 = 0 ;
V_2 -> V_159 . V_138 = 0 ;
V_2 -> V_159 . V_139 = 9000 ;
V_2 -> V_159 . V_143 = 0x0511 ;
V_2 -> V_159 . V_144 = 0 ;
V_2 -> V_159 . V_140 = 3 ;
V_2 -> V_159 . V_156 = 5119 ;
V_2 -> V_159 . V_155 = 50 ;
V_2 -> V_160 = 140 ;
V_2 -> V_161 . V_146 = 4 ;
V_2 -> V_161 . V_147 = false ;
V_2 -> V_3 = V_162 ;
V_2 -> V_163 = V_164 ;
V_2 -> V_165 = true ;
V_2 -> V_166 = false ;
V_2 -> V_167 = false ;
V_2 -> V_168 = false ;
V_2 -> V_169 = false ;
V_2 -> V_170 = false ;
V_2 -> V_171 = ( V_105 != 0 ) ;
V_2 -> V_172 = V_108 ;
V_2 -> V_173 = V_109 ;
V_2 -> V_174 = ( V_106 & 0x07 ) ;
V_2 -> V_175 = 19392658 ;
V_2 -> V_176 = false ;
if ( V_111 )
V_2 -> V_166 = true ;
V_2 -> V_177 = V_101 ;
if ( V_100 < 10000 )
V_2 -> V_177 = V_100 ;
V_2 -> V_178 = V_103 ;
if ( V_102 < 10000 )
V_2 -> V_178 = V_102 ;
V_2 -> V_179 = V_180 ;
V_2 -> V_181 = V_182 ;
V_2 -> V_183 = 204 * 8 ;
V_2 -> V_184 = 1 ;
V_2 -> V_185 = V_186 ;
V_2 -> V_187 = 0 ;
V_2 -> V_188 = ( V_104 ) ;
V_2 -> V_130 = false ;
V_2 -> V_68 = V_189 ;
V_2 -> V_190 = ( V_112 == 0 ) ;
V_2 -> V_191 = false ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
T_1 V_192 = 0 ;
T_4 V_193 = 0 ;
T_4 V_194 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_195 , V_196 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_197 , & V_194 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_197 , V_198 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_25 ( V_2 , V_199 , & V_192 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_200 , & V_193 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_197 , V_194 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_4 V_201 = 0 ;
T_1 V_202 = 0 ;
int V_37 ;
const char * V_203 = L_14 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_195 , V_196 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_197 , 0xFABA ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_204 , & V_201 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_197 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
switch ( ( V_201 & V_205 ) ) {
case 0 :
break;
case 1 :
V_2 -> V_120 = 27000 ;
break;
case 2 :
V_2 -> V_120 = 20250 ;
break;
case 3 :
V_2 -> V_120 = 20250 ;
break;
default:
F_19 ( V_42 L_15 ) ;
return - V_206 ;
}
V_37 = F_25 ( V_2 , V_199 , & V_202 ) ;
if ( V_37 < 0 )
goto error;
F_19 ( V_207 L_16 , V_202 ) ;
switch ( ( V_202 >> 29 ) & 0xF ) {
case 0 :
V_2 -> V_208 = V_209 ;
V_203 = L_17 ;
break;
case 2 :
V_2 -> V_208 = V_210 ;
V_203 = L_18 ;
break;
case 3 :
V_2 -> V_208 = V_211 ;
V_203 = L_19 ;
break;
default:
V_2 -> V_208 = V_212 ;
V_37 = - V_206 ;
F_19 ( V_42 L_20 ,
( V_202 >> 29 ) & 0xF ) ;
goto V_213;
}
switch ( ( V_202 >> 12 ) & 0xFF ) {
case 0x13 :
V_2 -> V_114 = false ;
V_2 -> V_118 = false ;
V_2 -> V_117 = false ;
V_2 -> V_119 = false ;
V_2 -> V_115 = true ;
V_2 -> V_116 = true ;
V_2 -> V_214 = true ;
V_2 -> V_215 = false ;
V_2 -> V_216 = false ;
V_2 -> V_217 = false ;
break;
case 0x15 :
V_2 -> V_114 = false ;
V_2 -> V_118 = false ;
V_2 -> V_117 = true ;
V_2 -> V_119 = false ;
V_2 -> V_115 = true ;
V_2 -> V_116 = false ;
V_2 -> V_214 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = false ;
break;
case 0x16 :
V_2 -> V_114 = false ;
V_2 -> V_118 = false ;
V_2 -> V_117 = true ;
V_2 -> V_119 = false ;
V_2 -> V_115 = true ;
V_2 -> V_116 = false ;
V_2 -> V_214 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = false ;
break;
case 0x18 :
V_2 -> V_114 = false ;
V_2 -> V_118 = false ;
V_2 -> V_117 = true ;
V_2 -> V_119 = true ;
V_2 -> V_115 = true ;
V_2 -> V_116 = false ;
V_2 -> V_214 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = false ;
break;
case 0x21 :
V_2 -> V_114 = false ;
V_2 -> V_118 = false ;
V_2 -> V_117 = true ;
V_2 -> V_119 = true ;
V_2 -> V_115 = true ;
V_2 -> V_116 = true ;
V_2 -> V_214 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = false ;
break;
case 0x23 :
V_2 -> V_114 = false ;
V_2 -> V_118 = false ;
V_2 -> V_117 = true ;
V_2 -> V_119 = true ;
V_2 -> V_115 = true ;
V_2 -> V_116 = true ;
V_2 -> V_214 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = false ;
break;
case 0x25 :
V_2 -> V_114 = false ;
V_2 -> V_118 = false ;
V_2 -> V_117 = true ;
V_2 -> V_119 = true ;
V_2 -> V_115 = true ;
V_2 -> V_116 = true ;
V_2 -> V_214 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = false ;
break;
case 0x26 :
V_2 -> V_114 = false ;
V_2 -> V_118 = false ;
V_2 -> V_117 = true ;
V_2 -> V_119 = false ;
V_2 -> V_115 = true ;
V_2 -> V_116 = true ;
V_2 -> V_214 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = false ;
break;
default:
F_19 ( V_42 L_21 ,
( ( V_202 >> 12 ) & 0xFF ) ) ;
V_37 = - V_206 ;
goto V_213;
}
F_19 ( V_207
L_22 ,
( ( V_202 >> 12 ) & 0xFF ) , V_203 ,
V_2 -> V_120 / 1000 ,
V_2 -> V_120 % 1000 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
V_213:
return V_37 ;
}
static int F_36 ( struct V_1 * V_2 , T_4 V_218 , T_4 * V_219 )
{
int V_37 ;
bool V_220 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_221 , V_218 ) ;
if ( V_37 < 0 )
goto error;
if ( V_218 == V_222 )
F_32 ( 1 ) ;
V_220 =
( bool ) ( ( V_218 == V_223 ) &&
( ( V_2 -> V_128 ) &
V_224 ) ==
V_225 ) ;
if ( V_220 == false ) {
T_1 V_61 = 0 ;
T_4 V_226 ;
do {
F_32 ( 1 ) ;
V_61 += 1 ;
V_37 = F_23 ( V_2 , V_221 ,
& V_226 ) ;
} while ( ( V_37 < 0 ) && ( V_61 < V_227 )
&& ( V_226 != 0 ) );
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_228 , V_219 ) ;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_37 ;
F_18 ( 1 , L_3 ) ;
F_38 ( & V_2 -> V_229 ) ;
V_37 = F_27 ( V_2 , V_230 , V_2 -> V_231 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_232 , V_2 -> V_128 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_233 , V_2 -> V_127 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_234 , V_2 -> V_235 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_236 , V_2 -> V_124 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_237 , V_238 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_36 ( V_2 , V_223 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_128 &= ~ V_225 ;
error:
F_39 ( & V_2 -> V_229 ) ;
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_18 ( 1 , L_3 ) ;
V_2 -> V_127 = ( V_2 -> V_46 << 1 ) ;
V_2 -> V_231 = 0x96FF ;
V_2 -> V_128 = V_129 ;
return F_37 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 , bool V_239 )
{
int V_37 = - 1 ;
T_4 V_240 = 0 ;
T_4 V_241 = 0 ;
T_4 V_242 = 0 ;
F_18 ( 1 , L_23 ,
V_239 ? L_24 : L_25 ,
V_2 -> V_243 ? L_26 : L_27 ) ;
V_37 = F_27 ( V_2 , V_195 , V_196 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_197 , 0xFABA ) ;
if ( V_37 < 0 )
goto error;
if ( V_239 == false ) {
V_37 = F_27 ( V_2 , V_244 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_245 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_246 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_247 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_248 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_249 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_250 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_251 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_252 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_253 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_254 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_255 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
} else {
V_241 =
( ( V_2 -> V_174 <<
V_256 ) | 0x0003 ) ;
V_240 = ( ( V_2 -> V_257 <<
V_258 ) |
0x0003 ) ;
V_37 = F_27 ( V_2 , V_244 , V_241 ) ;
if ( V_37 < 0 )
goto error;
if ( V_2 -> V_259 )
V_242 = V_241 ;
V_37 = F_27 ( V_2 , V_245 , V_242 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_247 , V_242 ) ;
if ( V_37 < 0 )
goto error;
if ( V_2 -> V_243 == true ) {
V_37 = F_27 ( V_2 , V_249 , V_241 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_250 , V_241 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_251 , V_241 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_252 , V_241 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_253 , V_241 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_254 , V_241 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_255 , V_241 ) ;
if ( V_37 < 0 )
goto error;
} else {
V_241 = ( ( V_2 -> V_174 <<
V_256 )
| 0x0003 ) ;
V_37 = F_27 ( V_2 , V_249 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_250 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_251 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_252 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_253 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_254 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_255 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
}
V_37 = F_27 ( V_2 , V_246 , V_240 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_248 , V_241 ) ;
if ( V_37 < 0 )
goto error;
}
V_37 = F_27 ( V_2 , V_260 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_197 , 0x0000 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_42 ( struct V_1 * V_2 )
{
F_18 ( 1 , L_3 ) ;
return F_41 ( V_2 , false ) ;
}
static int F_43 ( struct V_1 * V_2 ,
T_4 V_261 , T_4 V_262 , T_1 V_263 )
{
T_4 V_264 = 0 ;
int V_37 ;
unsigned long V_265 ;
F_18 ( 1 , L_3 ) ;
F_38 ( & V_2 -> V_229 ) ;
V_37 = F_27 ( V_2 , V_266 , V_267 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_268 , V_261 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_269 , V_262 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_270 , V_271 ) ;
if ( V_37 < 0 )
goto error;
V_265 = V_272 + F_44 ( V_263 ) ;
do {
F_32 ( 1 ) ;
V_37 = F_23 ( V_2 , V_273 , & V_264 ) ;
if ( V_37 < 0 )
goto error;
} while ( ( V_264 == 0x1 ) &&
( ( F_45 ( V_265 ) ) ) );
if ( V_264 == 0x1 ) {
F_19 ( V_42 L_28 ) ;
V_37 = - V_206 ;
goto V_213;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
V_213:
F_39 ( & V_2 -> V_229 ) ;
return V_37 ;
}
static int F_46 ( struct V_1 * V_2 ,
const T_3 V_274 [] , T_1 V_275 )
{
const T_3 * V_276 = V_274 ;
T_1 V_51 ;
T_4 V_277 ;
T_4 V_52 ;
T_1 V_278 = 0 ;
T_1 V_14 ;
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
#if 0
Drain = (pSrc[0] << 8) | pSrc[1];
#endif
V_276 += sizeof( T_4 ) ;
V_278 += sizeof( T_4 ) ;
V_277 = ( V_276 [ 0 ] << 8 ) | V_276 [ 1 ] ;
V_276 += sizeof( T_4 ) ;
V_278 += sizeof( T_4 ) ;
for ( V_14 = 0 ; V_14 < V_277 ; V_14 += 1 ) {
V_51 = ( V_276 [ 0 ] << 24 ) | ( V_276 [ 1 ] << 16 ) |
( V_276 [ 2 ] << 8 ) | V_276 [ 3 ] ;
V_276 += sizeof( T_1 ) ;
V_278 += sizeof( T_1 ) ;
V_52 = ( ( V_276 [ 0 ] << 8 ) | V_276 [ 1 ] ) * sizeof( T_4 ) ;
V_276 += sizeof( T_4 ) ;
V_278 += sizeof( T_4 ) ;
#if 0
Flags = (pSrc[0] << 8) | pSrc[1];
#endif
V_276 += sizeof( T_4 ) ;
V_278 += sizeof( T_4 ) ;
#if 0
BlockCRC = (pSrc[0] << 8) | pSrc[1];
#endif
V_276 += sizeof( T_4 ) ;
V_278 += sizeof( T_4 ) ;
if ( V_278 + V_52 > V_275 ) {
F_19 ( V_42 L_29 ) ;
return - V_206 ;
}
V_37 = F_30 ( V_2 , V_51 , V_52 , V_276 ) ;
if ( V_37 < 0 ) {
F_19 ( V_42 L_30 , V_37 ) ;
break;
}
V_276 += V_52 ;
V_278 += V_52 ;
}
return V_37 ;
}
static int F_47 ( struct V_1 * V_2 , bool V_279 )
{
int V_37 ;
T_4 V_36 = 0 ;
T_4 V_280 = V_281 ;
T_4 V_282 = V_283 ;
unsigned long V_265 ;
F_18 ( 1 , L_3 ) ;
if ( V_279 == false ) {
V_280 = V_284 ;
V_282 = V_285 ;
}
V_37 = F_23 ( V_2 , V_286 , & V_36 ) ;
if ( V_37 >= 0 && V_36 == V_282 ) {
return V_37 ;
}
V_37 = F_27 ( V_2 , V_287 , V_280 ) ;
V_265 = V_272 + F_44 ( V_288 ) ;
do {
V_37 = F_23 ( V_2 , V_286 , & V_36 ) ;
if ( ( V_37 >= 0 && V_36 == V_282 ) || F_45 ( V_265 ) )
break;
F_32 ( 1 ) ;
} while ( 1 );
if ( V_36 != V_282 ) {
F_19 ( V_42 L_28 ) ;
return - V_206 ;
}
return V_37 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
T_4 V_289 = 0 ;
T_4 V_290 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_291 , & V_289 ) ;
if ( V_37 < 0 )
goto error;
V_289 |= V_292 ;
V_37 = F_27 ( V_2 , V_291 , V_289 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_293 , & V_290 ) ;
if ( V_37 < 0 )
goto error;
V_290 |= V_294 ;
V_37 = F_27 ( V_2 , V_293 , V_290 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_49 ( struct V_1 * V_2 ,
T_4 V_218 , T_3 V_295 ,
T_4 * V_296 , T_3 V_297 , T_4 * V_298 )
{
#if ( V_299 - V_300 ) != 15
#error DRXK register mapping no longer compatible with this routine!
#endif
T_4 V_301 = 0 ;
int V_37 = - V_206 ;
unsigned long V_265 ;
T_3 V_302 [ 34 ] ;
int V_303 = 0 , V_304 ;
const char * V_305 ;
char V_306 [ 30 ] ;
F_18 ( 1 , L_3 ) ;
if ( ( V_218 == 0 ) || ( ( V_295 > 0 ) && ( V_296 == NULL ) ) ||
( ( V_297 > 0 ) && ( V_298 == NULL ) ) ) {
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
F_38 ( & V_2 -> V_229 ) ;
for ( V_304 = V_295 - 1 ; V_304 >= 0 ; V_304 -= 1 ) {
V_302 [ V_303 ++ ] = ( V_296 [ V_304 ] & 0xFF ) ;
V_302 [ V_303 ++ ] = ( ( V_296 [ V_304 ] >> 8 ) & 0xFF ) ;
}
V_302 [ V_303 ++ ] = ( V_218 & 0xFF ) ;
V_302 [ V_303 ++ ] = ( ( V_218 >> 8 ) & 0xFF ) ;
F_30 ( V_2 , V_299 -
( V_295 - 1 ) , V_303 , V_302 ) ;
V_265 = V_272 + F_44 ( V_307 ) ;
do {
F_32 ( 1 ) ;
V_37 = F_23 ( V_2 , V_308 , & V_301 ) ;
if ( V_37 < 0 )
goto error;
} while ( ! ( V_301 == V_309 ) && ( F_45 ( V_265 ) ) );
if ( V_301 != V_309 ) {
F_19 ( V_42 L_31 ) ;
V_37 = - V_41 ;
goto V_213;
}
if ( ( V_297 > 0 ) && ( V_298 != NULL ) ) {
T_5 V_310 ;
int V_304 ;
for ( V_304 = V_297 - 1 ; V_304 >= 0 ; V_304 -= 1 ) {
V_37 = F_23 ( V_2 , V_299 - V_304 , & V_298 [ V_304 ] ) ;
if ( V_37 < 0 )
goto error;
}
V_310 = ( T_5 ) V_298 [ 0 ] ;
if ( V_310 >= 0 )
goto error;
switch ( V_310 ) {
case V_311 :
V_305 = L_32 ;
break;
case V_312 :
V_305 = L_33 ;
break;
case V_313 :
V_305 = L_34 ;
break;
case V_314 :
V_305 = L_35 ;
break;
default:
sprintf ( V_306 , L_36 , V_310 ) ;
V_305 = V_306 ;
}
F_19 ( V_42 L_37 , V_305 , V_218 ) ;
F_50 ( L_38 , V_315 , V_302 , V_303 ) ;
V_37 = - V_206 ;
goto V_213;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
V_213:
F_39 ( & V_2 -> V_229 ) ;
return V_37 ;
}
static int F_51 ( struct V_1 * V_2 , bool V_316 )
{
T_4 V_36 = 0 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_317 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
if ( ! V_316 ) {
V_36 |= ( V_318
| V_319
| V_320
| V_321
| V_322 ) ;
} else {
V_36 &= ( ( ~ V_318 )
& ( ~ V_319 )
& ( ~ V_320 )
& ( ~ V_321 )
& ( ~ V_322 )
) ;
}
V_37 = F_27 ( V_2 , V_317 , V_36 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_52 ( struct V_1 * V_2 , enum V_323 * V_324 )
{
int V_37 = 0 ;
T_4 V_325 = 0 ;
F_18 ( 1 , L_3 ) ;
if ( V_324 == NULL )
return - V_206 ;
switch ( * V_324 ) {
case V_69 :
V_325 = V_64 ;
break;
case V_326 :
V_325 = V_327 ;
break;
case V_328 :
V_325 = V_329 ;
break;
case V_330 :
V_325 = V_331 ;
break;
case V_189 :
V_325 = V_332 ;
break;
default:
return - V_206 ;
}
if ( V_2 -> V_68 == * V_324 )
return 0 ;
if ( V_2 -> V_68 != V_69 ) {
V_37 = F_31 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_47 ( V_2 , true ) ;
if ( V_37 < 0 )
goto error;
}
if ( * V_324 == V_69 ) {
} else {
switch ( V_2 -> V_3 ) {
case V_4 :
V_37 = F_48 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_53 ( V_2 , false ) ;
if ( V_37 < 0 )
goto error;
break;
case V_5 :
case V_7 :
V_37 = F_48 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_54 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
break;
default:
break;
}
V_37 = F_47 ( V_2 , false ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_63 , V_325 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_65 , V_66 ) ;
if ( V_37 < 0 )
goto error;
if ( * V_324 != V_326 ) {
V_2 -> V_128 |=
V_225 ;
V_37 = F_37 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
}
}
V_2 -> V_68 = * V_324 ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_53 ( struct V_1 * V_2 , bool V_333 )
{
enum V_323 V_334 = V_326 ;
T_4 V_335 = 0 ;
T_4 V_36 = 0 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_336 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
if ( V_36 == V_337 ) {
V_37 = F_49 ( V_2 , V_338 | V_339 , 0 , NULL , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_49 ( V_2 , V_338 | V_340 , 0 , NULL , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
}
V_37 = F_27 ( V_2 , V_341 , V_342 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_343 , V_344 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_345 , V_346 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_51 ( V_2 , false ) ;
if ( V_37 < 0 )
goto error;
if ( V_333 ) {
V_37 = F_52 ( V_2 , & V_334 ) ;
if ( V_37 < 0 )
goto error;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_55 ( struct V_1 * V_2 ,
enum V_347 V_348 )
{
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_195 , V_196 ) ;
if ( V_37 < 0 )
goto error;
if ( V_2 -> V_3 == V_348 )
return 0 ;
switch ( V_2 -> V_3 ) {
case V_162 :
break;
case V_4 :
V_37 = F_48 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_53 ( V_2 , true ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_3 = V_162 ;
break;
case V_5 :
case V_7 :
V_37 = F_48 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_54 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_3 = V_162 ;
break;
case V_6 :
default:
V_37 = - V_206 ;
goto error;
}
switch ( V_348 ) {
case V_4 :
F_18 ( 1 , L_39 ) ;
V_2 -> V_3 = V_348 ;
V_37 = F_56 ( V_2 , V_348 ) ;
if ( V_37 < 0 )
goto error;
break;
case V_5 :
case V_7 :
F_18 ( 1 , L_40 ,
( V_2 -> V_3 == V_5 ) ? 'A' : 'C' ) ;
V_2 -> V_3 = V_348 ;
V_37 = F_57 ( V_2 , V_348 ) ;
if ( V_37 < 0 )
goto error;
break;
case V_6 :
default:
V_37 = - V_206 ;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_58 ( struct V_1 * V_2 , T_6 V_349 ,
T_6 V_350 )
{
int V_37 = - V_206 ;
T_4 V_351 ;
T_6 V_352 = V_349 / 1000 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 != V_353 &&
V_2 -> V_163 != V_354 )
goto error;
V_2 -> V_355 = ( V_2 -> V_356 . V_357 == V_358 ) ;
if ( V_350 < 0 ) {
V_2 -> V_355 = ! V_2 -> V_355 ;
V_350 = - V_350 ;
}
switch ( V_2 -> V_3 ) {
case V_5 :
case V_7 :
V_351 = ( V_350 / 1000 ) ;
V_37 = F_59 ( V_2 , V_351 , V_352 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_163 = V_354 ;
break;
case V_4 :
V_351 = ( V_350 / 1000 ) ;
V_37 = F_48 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_60 ( V_2 , V_351 , V_352 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_61 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_163 = V_354 ;
break;
default:
break;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_62 ( struct V_1 * V_2 )
{
F_18 ( 1 , L_3 ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , T_1 * V_359 ,
T_1 Time )
{
int V_37 = - V_206 ;
F_18 ( 1 , L_3 ) ;
if ( V_359 == NULL )
goto error;
* V_359 = V_360 ;
switch ( V_2 -> V_3 ) {
case V_5 :
case V_6 :
case V_7 :
V_37 = F_64 ( V_2 , V_359 ) ;
break;
case V_4 :
V_37 = F_65 ( V_2 , V_359 ) ;
break;
default:
break;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_37 ;
T_4 V_289 = 0 ;
V_37 = F_23 ( V_2 , V_291 , & V_289 ) ;
if ( V_37 < 0 )
goto error;
V_289 &= ~ V_292 ;
V_37 = F_27 ( V_2 , V_291 , V_289 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_361 , 1 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_362 , 0x0000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_363 , 0x000C ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_364 , 0x000A ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_365 , 0x0008 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_366 , 0x0006 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_367 , 0x0680 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_368 , 0x0080 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_369 , 0x03F4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_370 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_371 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_372 , 12 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_68 ( struct V_1 * V_2 ,
enum V_347 V_348 )
{
int V_37 ;
T_4 V_373 = 0 ;
T_4 V_374 = 0 ;
T_4 V_375 = 0 ;
T_4 V_376 = 0 ;
T_4 V_377 = 2 ;
T_4 V_378 = 188 ;
T_1 V_379 = 0 ;
T_4 V_380 = 0 ;
T_4 V_381 = 0 ;
T_1 V_382 = 0 ;
bool V_383 = false ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_384 , & V_373 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_293 , & V_374 ) ;
if ( V_37 < 0 )
goto error;
V_373 &= ( ~ V_385 ) ;
V_374 &= ( ~ V_386 ) ;
if ( V_2 -> V_166 == true ) {
V_373 |= V_385 ;
V_374 |= V_386 ;
V_378 = 204 ;
}
V_374 &= ( ~ ( V_387 ) ) ;
if ( V_2 -> V_243 == false ) {
V_374 |= V_387 ;
}
switch ( V_348 ) {
case V_4 :
V_382 = V_2 -> V_172 ;
V_380 = 3 ;
V_379 = 0xC00000 ;
V_383 = V_2 -> V_388 ;
break;
case V_5 :
case V_7 :
V_380 = 0x0004 ;
V_379 = 0xD2B4EE ;
V_382 = V_2 -> V_173 ;
V_383 = V_2 -> V_389 ;
break;
default:
V_37 = - V_206 ;
}
if ( V_37 < 0 )
goto error;
if ( V_383 ) {
T_1 V_390 = 0 ;
V_375 = ( V_391 |
V_392 ) ;
V_376 = ( V_393 |
V_394 ) ;
V_390 = V_382 ;
if ( V_390 > 75900000UL ) {
V_390 = 75900000UL ;
}
V_377 = ( T_4 ) ( ( ( V_2 -> V_123 )
* 1000 ) / V_390 ) ;
if ( V_377 <= 2 )
V_377 = 0 ;
else
V_377 -= 2 ;
V_381 = 8 ;
} else {
V_375 = V_391 ;
V_376 = V_395 ;
V_381 = 5 ;
}
V_37 = F_27 ( V_2 , V_396 , V_378 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_397 , V_377 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_398 , V_375 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_399 , V_376 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_384 , V_373 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_293 , V_374 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_29 ( V_2 , V_400 , V_379 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_401 , V_381 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_402 , V_380 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_4 V_403 = 0 ;
T_4 V_404 =
V_405 | V_406 |
V_407 | V_408 |
V_409 | V_410 |
V_411 | V_412 ;
F_18 ( 1 , L_3 ) ;
V_403 &= ( ~ ( V_404 ) ) ;
if ( V_2 -> V_167 == true )
V_403 |= V_404 ;
V_403 &= ( ~ ( V_413 ) ) ;
if ( V_2 -> V_168 == true )
V_403 |= V_413 ;
V_403 &= ( ~ ( V_414 ) ) ;
if ( V_2 -> V_169 == true )
V_403 |= V_414 ;
V_403 &= ( ~ ( V_415 ) ) ;
if ( V_2 -> V_170 == true )
V_403 |= V_415 ;
V_403 &= ( ~ ( V_416 ) ) ;
if ( V_2 -> V_171 == true )
V_403 |= V_416 ;
return F_27 ( V_2 , V_417 , V_403 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_418 * V_419 , bool V_420 )
{
int V_37 = - V_206 ;
T_4 V_36 = 0 ;
struct V_418 * V_421 ;
F_18 ( 1 , L_3 ) ;
if ( V_419 == NULL )
goto error;
switch ( V_419 -> V_136 ) {
case V_71 :
V_37 = F_23 ( V_2 , V_317 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 &= ~ V_322 ;
V_37 = F_27 ( V_2 , V_317 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_422 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 &= ~ V_423 ;
if ( V_2 -> V_424 )
V_36 |= V_425 ;
else
V_36 &= ~ V_425 ;
V_37 = F_27 ( V_2 , V_422 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_426 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 &= ~ V_427 ;
V_36 |= ( ~ ( V_419 -> V_140 <<
V_428 )
& V_427 ) ;
V_37 = F_27 ( V_2 , V_426 , V_36 ) ;
if ( V_37 < 0 )
goto error;
if ( F_1 ( V_2 ) )
V_421 = & V_2 -> V_154 ;
else if ( F_2 ( V_2 ) )
V_421 = & V_2 -> V_159 ;
else
V_421 = & V_2 -> V_150 ;
if ( V_421 == NULL ) {
V_37 = - V_206 ;
goto error;
}
if ( V_421 -> V_136 == V_71 )
V_37 = F_27 ( V_2 , V_429 , V_419 -> V_143 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_430 , V_419 -> V_144 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_431 , V_419 -> V_139 ) ;
if ( V_37 < 0 )
goto error;
break;
case V_432 :
V_37 = F_23 ( V_2 , V_317 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 &= ~ V_322 ;
V_37 = F_27 ( V_2 , V_317 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_422 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 |= V_423 ;
if ( V_2 -> V_424 )
V_36 |= V_425 ;
else
V_36 &= ~ V_425 ;
V_37 = F_27 ( V_2 , V_422 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_430 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_433 , V_419 -> V_137 ) ;
if ( V_37 < 0 )
goto error;
break;
case V_89 :
V_37 = F_23 ( V_2 , V_317 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 |= V_322 ;
V_37 = F_27 ( V_2 , V_317 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_422 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 |= V_423 ;
V_37 = F_27 ( V_2 , V_422 , V_36 ) ;
if ( V_37 < 0 )
goto error;
break;
default:
V_37 = - V_206 ;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_418 * V_419 , bool V_420 )
{
T_4 V_36 = 0 ;
int V_37 = 0 ;
struct V_418 * V_434 ;
F_18 ( 1 , L_3 ) ;
switch ( V_419 -> V_136 ) {
case V_71 :
V_37 = F_23 ( V_2 , V_317 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 &= ~ V_321 ;
V_37 = F_27 ( V_2 , V_317 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_422 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 &= ~ V_435 ;
if ( V_2 -> V_191 )
V_36 |= V_436 ;
else
V_36 &= ~ V_436 ;
V_37 = F_27 ( V_2 , V_422 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_426 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 &= ~ V_437 ;
V_36 |= ( ~ ( V_419 -> V_140 <<
V_438 )
& V_437 ) ;
V_37 = F_27 ( V_2 , V_426 , V_36 ) ;
if ( V_37 < 0 )
goto error;
if ( F_2 ( V_2 ) )
V_434 = & V_2 -> V_158 ;
else
V_434 = & V_2 -> V_151 ;
if ( V_434 == NULL )
return - 1 ;
V_37 = F_27 ( V_2 , V_429 , V_434 -> V_143 ) ;
if ( V_37 < 0 )
goto error;
break;
case V_432 :
V_37 = F_23 ( V_2 , V_317 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 &= ~ V_321 ;
V_37 = F_27 ( V_2 , V_317 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_422 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 |= V_435 ;
if ( V_2 -> V_191 )
V_36 |= V_436 ;
else
V_36 &= ~ V_436 ;
V_37 = F_27 ( V_2 , V_422 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_429 , V_419 -> V_137 ) ;
if ( V_37 < 0 )
goto error;
break;
case V_89 :
V_37 = F_23 ( V_2 , V_317 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 |= V_321 ;
V_37 = F_27 ( V_2 , V_317 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_422 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 |= V_435 ;
V_37 = F_27 ( V_2 , V_422 , V_36 ) ;
if ( V_37 < 0 )
goto error;
break;
}
V_37 = F_27 ( V_2 , V_439 , V_419 -> V_143 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 * V_440 )
{
T_4 V_441 ;
int V_37 ;
T_4 V_442 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_443 , & V_441 ) ;
if ( V_37 < 0 ) {
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
* V_440 = 0 ;
if ( V_441 > V_444 )
V_442 = V_441 - V_444 ;
if ( V_442 < 14000 )
* V_440 = ( 14000 - V_442 ) / 4 ;
else
* V_440 = 0 ;
return V_37 ;
}
static int F_73 ( struct V_1 * V_2 ,
T_6 * V_445 )
{
int V_37 = 0 ;
T_4 V_446 = 0 ;
T_1 V_447 = 0 ;
T_1 V_448 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_449 , & V_446 ) ;
if ( V_37 < 0 ) {
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return - V_206 ;
}
switch ( V_2 -> V_356 . V_450 ) {
case V_451 :
V_447 = V_452 << 2 ;
break;
case V_453 :
V_447 = V_454 << 2 ;
break;
case V_455 :
V_447 = V_456 << 2 ;
break;
case V_457 :
V_447 = V_458 << 2 ;
break;
default:
case V_459 :
V_447 = V_460 << 2 ;
break;
}
if ( V_446 > 0 ) {
V_448 = F_8 ( V_447 ) -
F_8 ( ( T_1 ) V_446 ) ;
}
* V_445 = V_448 ;
return V_37 ;
}
static int F_74 ( struct V_1 * V_2 ,
T_6 * V_445 )
{
int V_37 ;
T_4 V_461 = 0 ;
T_1 V_462 = 0 ;
T_1 V_463 = 0 ;
T_4 V_464 = 0 ;
T_4 V_465 = 0 ;
T_4 V_466 = 0 ;
T_1 V_467 = 0 ;
T_1 V_468 = 0 ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
T_1 V_469 = 0 ;
T_4 V_470 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_471 , & V_465 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_472 , & V_466 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_473 , & V_464 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_474 , & V_461 ) ;
if ( V_37 < 0 )
goto error;
V_462 = ( T_1 ) V_461 ;
if ( ( V_464 > 11 ) &&
( V_462 < 0x00000FFFUL ) ) {
V_462 += 0x00010000UL ;
}
V_37 = F_23 ( V_2 , V_475 , & V_461 ) ;
if ( V_37 < 0 )
goto error;
V_463 = ( T_1 ) V_461 ;
if ( ( V_464 > 11 ) &&
( V_463 < 0x00000FFFUL ) )
V_463 += 0x00010000UL ;
V_37 = F_23 ( V_2 , V_476 , & V_470 ) ;
if ( V_37 < 0 )
goto error;
if ( ( V_465 == 0 ) || ( V_466 == 0 ) )
V_469 = 0 ;
else if ( ( V_462 + V_463 ) == 0 ) {
V_469 = 0 ;
} else {
V_468 = ( V_462 + V_463 ) <<
V_464 ;
if ( ( V_470 &
V_477 )
== V_478 )
V_467 = 17 ;
else
V_467 = 68 ;
V_10 = F_8 ( V_465 *
V_465 ) ;
V_11 = F_8 ( V_466 * V_467 ) ;
V_12 = F_8 ( V_468 ) ;
V_469 = V_10 + V_11 ;
if ( V_469 > V_12 )
V_469 -= V_12 ;
else
V_469 = 0 ;
}
* V_445 = V_469 ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_75 ( struct V_1 * V_2 , T_6 * V_445 )
{
F_18 ( 1 , L_3 ) ;
* V_445 = 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
return F_74 ( V_2 , V_445 ) ;
case V_5 :
case V_7 :
return F_73 ( V_2 , V_445 ) ;
default:
break;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , bool V_479 )
{
int V_37 = - V_206 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_164 )
return 0 ;
if ( V_2 -> V_163 == V_480 )
goto error;
if ( V_2 -> V_481 )
return 0 ;
V_37 = F_27 ( V_2 , V_237 , V_238 ) ;
if ( V_37 < 0 )
goto error;
if ( V_479 ) {
V_37 = F_27 ( V_2 , V_236 , V_482 ) ;
if ( V_37 < 0 )
goto error;
} else {
V_37 = F_27 ( V_2 , V_236 , V_483 ) ;
if ( V_37 < 0 )
goto error;
}
V_37 = F_36 ( V_2 , V_484 , 0 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_485 * V_486 )
{
int V_37 = - V_206 ;
F_18 ( 1 , L_3 ) ;
if ( ( V_486 == NULL )
|| ( V_486 -> V_146 > V_487 ) )
goto error;
V_37 = F_27 ( V_2 , V_488 , V_486 -> V_146 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_78 ( struct V_1 * V_2 , T_1 V_489 ,
T_4 V_261 , T_4 V_262 , T_1 V_263 )
{
T_4 V_264 = 0 ;
T_4 V_278 = ( T_4 ) ( ( V_489 >> 0 ) & 0x00FFFF ) ;
T_4 V_490 = ( T_4 ) ( ( V_489 >> 16 ) & 0x000FFF ) ;
int V_37 ;
unsigned long V_265 ;
F_18 ( 1 , L_3 ) ;
F_38 ( & V_2 -> V_229 ) ;
V_37 = F_27 ( V_2 , V_266 , V_491 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_492 , V_490 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_493 , V_278 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_494 , V_261 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_495 , V_262 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_270 , V_271 ) ;
if ( V_37 < 0 )
goto error;
V_265 = V_272 + F_44 ( V_263 ) ;
do {
V_37 = F_23 ( V_2 , V_273 , & V_264 ) ;
if ( V_37 < 0 )
goto error;
} while ( ( V_264 == 0x1 ) && F_45 ( V_265 ) );
if ( V_264 == 0x1 ) {
F_19 ( V_42 L_28 ) ;
V_37 = - V_206 ;
goto V_213;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
V_213:
F_39 ( & V_2 -> V_229 ) ;
return V_37 ;
}
static int F_79 ( struct V_1 * V_2 , T_4 * V_496 )
{
T_4 V_36 = 0 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_497 , V_498 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_499 , 1 ) ;
if ( V_37 < 0 )
goto error;
* V_496 = 0 ;
V_37 = F_23 ( V_2 , V_500 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
if ( V_36 == 127 )
* V_496 = * V_496 + 1 ;
V_37 = F_23 ( V_2 , V_501 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
if ( V_36 == 127 )
* V_496 = * V_496 + 1 ;
V_37 = F_23 ( V_2 , V_502 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
if ( V_36 == 127 )
* V_496 = * V_496 + 1 ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_80 ( struct V_1 * V_2 )
{
T_4 V_496 = 0 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_79 ( V_2 , & V_496 ) ;
if ( V_37 < 0 )
goto error;
if ( V_496 == 1 ) {
T_4 V_503 = 0 ;
V_37 = F_23 ( V_2 , V_504 , & V_503 ) ;
if ( V_37 < 0 )
goto error;
if ( ( V_503 & V_505 ) ==
V_506 ) {
V_503 &= ( ~ ( V_505 ) ) ;
V_503 |=
V_507 ;
} else {
V_503 &= ( ~ ( V_505 ) ) ;
V_503 |=
V_506 ;
}
V_37 = F_27 ( V_2 , V_504 , V_503 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_79 ( V_2 , & V_496 ) ;
if ( V_37 < 0 )
goto error;
}
if ( V_496 < 2 )
V_37 = - V_206 ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_4 V_508 ,
T_6 V_509 , bool V_420 )
{
bool V_510 = false ;
T_1 V_511 = V_509 ;
T_1 V_512 = 0 ;
bool V_513 = ! V_2 -> V_355 ;
T_1 V_514 ;
bool V_515 ;
int V_37 ;
T_1 V_516 ;
T_1 V_517 = ( T_1 ) ( V_2 -> V_123 / 3 ) ;
T_1 V_518 ;
bool V_519 ;
F_18 ( 1 , L_3 ) ;
if ( V_420 ) {
if ( ( V_2 -> V_3 == V_5 ) ||
( V_2 -> V_3 == V_7 ) ||
( V_2 -> V_3 == V_4 ) )
V_510 = true ;
else
V_510 = false ;
}
if ( V_513 )
V_516 = V_508 +
V_511 + V_512 ;
else
V_516 = V_508 -
V_511 - V_512 ;
if ( V_516 > V_517 / 2 ) {
V_514 = V_517 - V_516 ;
V_515 = true ;
} else {
V_514 = V_516 ;
V_515 = false ;
}
V_518 = V_514 ;
V_519 = V_2 -> V_190 ^ V_513 ^
V_515 ^ V_510 ;
V_2 -> V_520 =
F_7 ( ( V_518 ) , V_517 ) ;
if ( V_519 )
V_2 -> V_520 = ~ V_2 -> V_520 + 1 ;
V_37 = F_29 ( V_2 , V_521 ,
V_2 -> V_520 ) ;
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_82 ( struct V_1 * V_2 , bool V_420 )
{
T_4 V_522 = 0 ;
T_4 V_523 = 0 ;
T_4 V_524 = 0 ;
T_4 V_525 = 0 ;
T_4 V_526 = 0 ;
T_4 V_527 = 0 ;
T_4 V_528 = 0 ;
T_4 V_529 = 0 ;
T_4 V_530 = 0 ;
T_4 V_531 = 0 ;
T_4 V_532 = 0 ;
T_4 V_533 = 0 ;
T_4 V_534 = 0 ;
T_4 V_535 = 0 ;
T_4 V_36 = 0 ;
T_4 V_536 = 0 ;
T_4 V_537 = 0 ;
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_529 = 1023 ;
V_534 = 2047 ;
V_525 = 500 ;
V_530 = 1023 ;
if ( ! F_2 ( V_2 ) ) {
F_19 ( V_42 L_41 , V_60 , V_2 -> V_3 ) ;
return - V_206 ;
}
V_526 = 8 ;
V_527 = ( T_4 ) - 9 ;
V_537 = 0 ;
V_528 = 8 ;
V_531 = ( T_4 ) - 9 ;
V_532 = ( T_4 ) - 1030 ;
V_535 = 0x2380 ;
V_533 = 0x2380 ;
V_523 = 0x0511 ;
V_522 = 0x0511 ;
V_524 = 5119 ;
V_536 = V_2 -> V_159 . V_155 ;
V_37 = F_27 ( V_2 , V_538 , V_536 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_539 , V_537 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_540 , V_522 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_439 , V_523 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_541 , V_524 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_542 , V_534 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_429 , V_535 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_543 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_544 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_433 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_545 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_546 , V_530 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_547 , V_529 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_548 , V_532 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_549 , V_533 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_550 , V_525 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_551 , 1023 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_552 , ( T_4 ) - 1023 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_553 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_554 , 20 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_555 , V_526 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_556 , V_528 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_557 , V_527 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_558 , V_531 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_559 , 0x7fff ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_560 , 0x0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_561 , 0x0117 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_562 , 0x0657 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_563 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_564 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_565 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_566 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_567 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_568 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_569 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_570 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_571 , 500 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_572 , 500 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_573 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 = 0x0657 ;
V_36 &= ~ V_574 ;
V_36 |= ( V_575 << V_576 ) ;
V_36 &= ~ V_577 ;
V_36 |= ( V_578 << V_579 ) ;
V_37 = F_27 ( V_2 , V_573 , V_36 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_83 ( struct V_1 * V_2 , T_4 * V_580 )
{
int V_37 ;
F_18 ( 1 , L_3 ) ;
if ( V_580 == NULL )
V_37 = F_27 ( V_2 , V_581 , 0 ) ;
else
V_37 = F_23 ( V_2 , V_581 , V_580 ) ;
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_84 ( struct V_1 * V_2 ,
T_4 V_218 , T_4 V_582 ,
T_4 V_583 , T_4 V_584 , T_4 V_585 ,
T_4 V_586 , T_4 V_587 )
{
T_4 V_301 = 0 ;
T_4 V_588 = 0 ;
T_4 V_589 = 0 ;
T_4 V_590 = 0 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_341 , & V_590 ) ;
if ( V_590 != 1 ) {
V_37 = - V_206 ;
}
if ( V_37 < 0 )
goto error;
V_589 = 0 ;
do {
F_32 ( 1 ) ;
V_37 = F_23 ( V_2 , V_591 , & V_301 ) ;
V_589 ++ ;
} while ( ( V_301 != 0 ) && ( V_589 < V_227 ) );
if ( V_589 >= V_227 && ( V_37 < 0 ) )
goto error;
switch ( V_218 ) {
case V_592 :
case V_593 :
case V_594 :
V_37 = F_27 ( V_2 , V_595 , V_582 ) ;
if ( V_37 < 0 )
goto error;
break;
default:
break;
}
switch ( V_218 ) {
case V_592 :
case V_593 :
case V_594 :
V_37 = F_27 ( V_2 , V_596 , V_584 ) ;
case V_597 :
case V_598 :
V_37 = F_27 ( V_2 , V_599 , V_583 ) ;
case V_600 :
case V_601 :
V_37 = F_27 ( V_2 , V_591 , V_218 ) ;
break;
default:
V_37 = - V_206 ;
}
if ( V_37 < 0 )
goto error;
V_589 = 0 ;
do {
F_32 ( 1 ) ;
V_37 = F_23 ( V_2 , V_591 , & V_301 ) ;
V_589 ++ ;
} while ( ( V_301 != 0 ) && ( V_589 < V_227 ) );
if ( V_589 >= V_227 && ( V_37 < 0 ) )
goto error;
V_37 = F_23 ( V_2 , V_595 , & V_588 ) ;
if ( V_588 == 0xFFFF ) {
V_37 = - V_206 ;
}
if ( V_37 < 0 )
goto error;
switch ( V_218 ) {
case V_598 :
case V_600 :
V_37 = F_23 ( V_2 , V_599 , & ( V_583 ) ) ;
case V_597 :
case V_602 :
case V_592 :
case V_593 :
case V_594 :
case V_601 :
break;
default:
V_37 = - V_206 ;
break;
}
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_85 ( struct V_1 * V_2 )
{
enum V_323 V_334 = V_69 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_52 ( V_2 , & V_334 ) ;
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_86 ( struct V_1 * V_2 , bool * V_603 )
{
int V_37 ;
F_18 ( 1 , L_3 ) ;
if ( * V_603 == true )
V_37 = F_27 ( V_2 , V_604 , 0 ) ;
else
V_37 = F_27 ( V_2 , V_604 , 1 ) ;
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_87 ( struct V_1 * V_2 , bool * V_603 )
{
int V_37 ;
F_18 ( 1 , L_3 ) ;
if ( * V_603 == true ) {
V_37 = F_27 ( V_2 , V_605 ,
V_606 ) ;
} else {
V_37 = F_27 ( V_2 , V_605 , 0 ) ;
}
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_607 * V_608 )
{
T_4 V_36 = 0 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_609 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
switch ( V_608 -> V_610 ) {
case V_611 :
V_36 &= ~ V_612 ;
V_36 |= ( ( V_608 -> V_613 <<
V_614 )
& ( V_612 ) ) ;
break;
case V_615 :
V_36 &= ~ V_616 ;
V_36 |= ( ( V_608 -> V_613 <<
V_617 )
& ( V_616 ) ) ;
break;
default:
return - V_206 ;
}
V_37 = F_27 ( V_2 , V_609 , V_36 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_89 ( struct V_1 * V_2 ,
enum V_618 * V_140 )
{
int V_37 = - V_206 ;
F_18 ( 1 , L_3 ) ;
switch ( * V_140 ) {
case V_619 :
case V_186 :
case V_620 :
break;
default:
goto error;
}
V_37 = F_27 ( V_2 , V_621 ,
( T_4 ) * V_140 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_37 ;
bool V_622 = false ;
bool V_623 = true ;
struct V_607 V_624 = { 0 , V_611 } ;
struct V_607 V_625 = { 0 , V_615 } ;
F_18 ( 1 , L_3 ) ;
V_37 = F_86 ( V_2 , & V_622 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_87 ( V_2 , & V_623 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_88 ( V_2 , & V_624 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_88 ( V_2 , & V_625 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_541 , V_2 -> V_154 . V_156 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_56 ( struct V_1 * V_2 ,
enum V_347 V_348 )
{
T_4 V_335 = 0 ;
T_4 V_36 = 0 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
F_85 ( V_2 ) ;
F_91 ( V_2 ) ;
V_37 = F_49 ( V_2 , V_338 | V_340 , 0 , NULL , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_49 ( V_2 , V_338 | V_626 , 0 , NULL , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_341 , V_342 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_343 , V_344 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_345 , V_346 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_627 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_628 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_629 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_630 , V_631 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_51 ( V_2 , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_632 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_633 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_634 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_635 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_636 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_637 , 0x4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_638 , 0x4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_639 , 1600 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_640 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_641 , 448 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_642 , 495 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_43 ( V_2 , V_643 , V_644 , V_645 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_646 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_647 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_648 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_345 , V_649 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_80 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_77 ( V_2 , & V_2 -> V_157 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_650 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_70 ( V_2 , & V_2 -> V_153 , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_71 ( V_2 , & V_2 -> V_154 , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_651 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
V_36 |= V_652 ;
V_37 = F_27 ( V_2 , V_651 , V_36 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_337 ) ;
if ( V_37 < 0 )
goto error;
if ( ! V_2 -> V_132 ) {
V_37 = F_27 ( V_2 , V_538 , V_2 -> V_154 . V_155 ) ;
if ( V_37 < 0 )
goto error;
}
#ifdef F_92
V_37 = F_27 ( V_2 , V_653 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_654 , 2 ) ;
if ( V_37 < 0 )
goto error;
#endif
V_37 = F_27 ( V_2 , V_655 , 1 ) ;
if ( V_37 < 0 )
goto error;
#ifdef F_92
V_37 = F_27 ( V_2 , V_656 , 0x400 ) ;
if ( V_37 < 0 )
goto error;
#else
V_37 = F_27 ( V_2 , V_656 , 0x1000 ) ;
if ( V_37 < 0 )
goto error;
#endif
V_37 = F_27 ( V_2 , V_657 , 0x0001 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_68 ( V_2 , V_4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_90 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_61 ( struct V_1 * V_2 )
{
T_4 V_584 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_584 = V_658 ;
V_37 = F_84 ( V_2 , V_592 , 0 , V_659 , V_584 , 0 , 0 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_66 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_660 , V_661 ) ;
if ( V_37 < 0 )
goto error;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_60 ( struct V_1 * V_2 , T_4 V_662 ,
T_6 V_509 )
{
T_4 V_335 = 0 ;
T_4 V_470 = 0 ;
T_4 V_663 = 0 ;
T_1 V_664 = 0 ;
T_1 V_665 = 0 ;
T_4 V_584 ;
int V_37 ;
F_18 ( 1 , L_42 , V_662 , V_509 ) ;
V_37 = F_49 ( V_2 , V_338 | V_339 , 0 , NULL , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_650 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_341 , V_342 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_343 , V_344 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_666 , V_667 ) ;
if ( V_37 < 0 )
goto error;
switch ( V_2 -> V_356 . V_668 ) {
case V_669 :
default:
V_663 |= V_670 ;
case V_671 :
V_470 |= V_672 ;
break;
case V_673 :
V_470 |= V_478 ;
break;
}
switch ( V_2 -> V_356 . V_674 ) {
default:
case V_675 :
V_663 |= V_676 ;
case V_677 :
V_470 |= V_678 ;
break;
case V_679 :
V_470 |= V_680 ;
break;
case V_681 :
V_470 |= V_682 ;
break;
case V_683 :
V_470 |= V_684 ;
break;
}
switch ( V_2 -> V_356 . V_685 ) {
case V_686 :
case V_687 :
default:
V_663 |= V_688 ;
case V_689 :
V_470 |= V_690 ;
break;
case V_691 :
V_470 |= V_692 ;
break;
case V_693 :
V_470 |= V_694 ;
break;
}
switch ( V_2 -> V_356 . V_450 ) {
case V_695 :
default:
V_663 |= V_696 ;
case V_455 :
V_470 |= V_697 ;
break;
case V_698 :
V_470 |= V_699 ;
break;
case V_451 :
V_470 |= V_700 ;
break;
}
#if 0
switch (channel->priority) {
case DRX_PRIORITY_LOW:
transmissionParams |= OFDM_SC_RA_RAM_OP_PARAM_PRIO_LO;
WR16(devAddr, OFDM_EC_SB_PRIOR__A,
OFDM_EC_SB_PRIOR_LO);
break;
case DRX_PRIORITY_HIGH:
transmissionParams |= OFDM_SC_RA_RAM_OP_PARAM_PRIO_HI;
WR16(devAddr, OFDM_EC_SB_PRIOR__A,
OFDM_EC_SB_PRIOR_HI));
break;
case DRX_PRIORITY_UNKNOWN:
default:
status = -EINVAL;
goto error;
}
#else
V_470 |= V_701 ;
V_37 = F_27 ( V_2 , V_702 , V_703 ) ;
if ( V_37 < 0 )
goto error;
#endif
switch ( V_2 -> V_356 . V_704 ) {
case V_705 :
default:
V_663 |= V_706 ;
case V_707 :
V_470 |= V_708 ;
break;
case V_709 :
V_470 |= V_710 ;
break;
case V_711 :
V_470 |= V_712 ;
break;
case V_713 :
V_470 |= V_714 ;
break;
case V_715 :
V_470 |= V_716 ;
break;
}
switch ( V_2 -> V_356 . V_717 ) {
case 0 :
V_2 -> V_356 . V_717 = 8000000 ;
case 8000000 :
V_665 = V_718 ;
V_37 = F_27 ( V_2 , V_719 , 3052 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_720 , 7 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_721 , 7 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_722 , 7 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_723 , 1 ) ;
if ( V_37 < 0 )
goto error;
break;
case 7000000 :
V_665 = V_724 ;
V_37 = F_27 ( V_2 , V_719 , 3491 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_720 , 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_721 , 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_722 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_723 , 1 ) ;
if ( V_37 < 0 )
goto error;
break;
case 6000000 :
V_665 = V_725 ;
V_37 = F_27 ( V_2 , V_719 , 4073 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_720 , 19 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_721 , 19 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_722 , 14 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_723 , 1 ) ;
if ( V_37 < 0 )
goto error;
break;
default:
V_37 = - V_206 ;
goto error;
}
if ( V_664 == 0 ) {
V_664 = F_7 ( ( T_1 )
( ( V_2 -> V_123 *
1000 ) / 3 ) , V_665 ) ;
if ( ( V_664 & 0x7fL ) >= 0x40 )
V_664 += 0x80L ;
V_664 = V_664 >> 7 ;
V_664 = V_664 - ( 1 << 23 ) ;
}
V_664 &=
( ( ( ( T_1 ) V_726 ) <<
V_727 ) | V_728 ) ;
V_37 = F_29 ( V_2 , V_729 , V_664 ) ;
if ( V_37 < 0 )
goto error;
#if 0
status = DVBTSetFrequencyShift(demod, channel, tunerOffset);
if (status < 0)
goto error;
#endif
V_37 = F_81 ( V_2 , V_662 , V_509 , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_337 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_730 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_341 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_49 ( V_2 , V_338 | V_731 , 0 , NULL , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
V_584 = ( V_670 |
V_676 |
V_696 |
V_688 |
V_706 ) ;
V_37 = F_84 ( V_2 , V_593 ,
0 , V_470 , V_584 , 0 , 0 , 0 ) ;
if ( V_37 < 0 )
goto error;
if ( ! V_2 -> V_132 )
V_37 = F_89 ( V_2 , & V_2 -> V_185 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 * V_359 )
{
int V_37 ;
const T_4 V_732 = ( V_733 |
V_734 ) ;
const T_4 V_735 = ( V_734 ) ;
const T_4 V_736 = V_737 ;
T_4 V_738 = 0 ;
T_4 V_739 = 0 ;
F_18 ( 1 , L_3 ) ;
* V_359 = V_360 ;
V_37 = F_23 ( V_2 , V_341 , & V_739 ) ;
if ( V_37 < 0 )
goto V_265;
if ( V_739 == V_342 )
goto V_265;
V_37 = F_23 ( V_2 , V_740 , & V_738 ) ;
if ( V_37 < 0 )
goto V_265;
if ( ( V_738 & V_732 ) == V_732 )
* V_359 = V_741 ;
else if ( ( V_738 & V_735 ) == V_735 )
* V_359 = V_742 ;
else if ( ( V_738 & V_736 ) == V_736 )
* V_359 = V_743 ;
else if ( V_738 & V_744 )
* V_359 = V_745 ;
V_265:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_93 ( struct V_1 * V_2 )
{
enum V_323 V_334 = V_326 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_52 ( V_2 , & V_334 ) ;
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_54 ( struct V_1 * V_2 )
{
T_4 V_36 = 0 ;
T_4 V_335 ;
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_23 ( V_2 , V_336 , & V_36 ) ;
if ( V_37 < 0 )
goto error;
if ( V_36 == V_337 ) {
V_37 = F_27 ( V_2 , V_746 , V_747 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_49 ( V_2 , V_748 | V_339 , 0 , NULL , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
}
V_37 = F_51 ( V_2 , false ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_94 ( struct V_1 * V_2 ,
enum V_749 V_450 ,
T_1 V_750 )
{
T_1 V_751 = 0 ;
T_1 V_752 = 0 ;
T_4 V_753 = 0 ;
T_4 V_754 = 0 ;
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_753 = 1 ;
switch ( V_450 ) {
case V_755 :
V_751 = 4 * V_750 ;
break;
case V_756 :
V_751 = 5 * V_750 ;
break;
case V_757 :
V_751 = 6 * V_750 ;
break;
case V_758 :
V_751 = 7 * V_750 ;
break;
case V_759 :
V_751 = 8 * V_750 ;
break;
default:
V_37 = - V_206 ;
}
if ( V_37 < 0 )
goto error;
V_751 /= 1000 ;
V_751 *= 500 ;
V_752 = ( V_751 / 1632UL ) + 1 ;
V_753 = 1 + ( T_4 ) ( V_752 >> 16 ) ;
if ( V_753 == 0 ) {
V_37 = - V_206 ;
if ( V_37 < 0 )
goto error;
}
V_754 =
( ( T_4 ) V_752 +
( V_753 >> 1 ) ) / V_753 ;
V_37 = F_27 ( V_2 , V_656 , V_754 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_657 , V_753 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_760 , V_754 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_761 , 13517 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_762 , 13517 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_763 , 13517 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_764 , 13517 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_765 , 13517 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_766 , 13517 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_767 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_768 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_769 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_770 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_771 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_772 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_773 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_774 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_775 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_776 , V_452 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_777 , 15 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_778 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_779 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_780 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_781 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_782 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_783 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_784 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_785 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_786 , 20 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_787 , 80 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_788 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_789 , 20 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_790 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_791 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_792 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_793 , 32 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_794 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_795 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_796 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_797 , 140 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_798 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_799 , 95 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_800 , 120 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_801 , 230 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_802 , 105 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_803 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_804 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_805 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_806 , ( T_4 ) 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_807 , ( T_4 ) 220 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_808 , ( T_4 ) 25 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_809 , ( T_4 ) 6 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_810 , ( T_4 ) - 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_811 , ( T_4 ) - 65 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_812 , ( T_4 ) - 127 ) ;
if ( V_37 < 0 )
goto error;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_761 , 6707 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_762 , 6707 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_763 , 6707 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_764 , 6707 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_765 , 6707 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_766 , 6707 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_767 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_768 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_769 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_770 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_771 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_772 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_773 , 6 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_774 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_775 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_776 , V_454 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_777 , 15 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_778 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_779 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_780 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_781 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_782 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_783 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_784 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_785 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_786 , 20 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_787 , 80 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_788 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_789 , 20 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_790 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_791 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_792 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_793 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_794 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_795 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_796 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_797 , 90 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_798 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_799 , 80 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_800 , 100 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_801 , 170 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_802 , 100 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_803 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_804 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_805 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_806 , ( T_4 ) 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_807 , ( T_4 ) 140 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_808 , ( T_4 ) - 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_809 , ( T_4 ) - 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_810 , ( T_4 ) - 26 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_811 , ( T_4 ) - 56 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_812 , ( T_4 ) - 86 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_761 , 13336 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_762 , 12618 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_763 , 11988 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_764 , 13809 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_765 , 13809 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_766 , 15609 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_767 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_768 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_769 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_770 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_771 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_772 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_773 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_774 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_775 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_776 , V_456 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_777 , 15 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_778 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_779 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_780 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_781 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_782 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_783 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_784 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_785 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_786 , 30 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_787 , 100 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_788 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_789 , 30 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_790 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_791 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_792 , 25 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_793 , 48 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_794 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_795 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_796 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_797 , 100 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_798 , 60 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_799 , 80 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_800 , 110 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_801 , 200 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_802 , 95 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_803 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_804 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_805 , 15 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_806 , ( T_4 ) 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_807 , ( T_4 ) 141 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_808 , ( T_4 ) 7 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_809 , ( T_4 ) 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_810 , ( T_4 ) - 15 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_811 , ( T_4 ) - 45 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_812 , ( T_4 ) - 80 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_761 , 6564 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_762 , 6598 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_763 , 6394 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_764 , 6409 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_765 , 6656 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_766 , 7238 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_767 , 6 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_768 , 6 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_769 , 6 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_770 , 6 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_771 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_772 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_773 , 6 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_774 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_775 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_776 , V_458 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_777 , 15 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_778 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_779 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_780 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_781 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_782 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_783 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_784 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_785 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_786 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_787 , 120 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_788 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_789 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_790 , 60 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_791 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_792 , 25 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_793 , 64 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_794 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_795 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_796 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_797 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_798 , 60 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_799 , 80 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_800 , 100 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_801 , 140 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_802 , 100 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_803 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_804 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_805 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_806 , ( T_4 ) 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_807 , ( T_4 ) 65 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_808 , ( T_4 ) 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_809 , ( T_4 ) 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_810 , ( T_4 ) - 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_811 , ( T_4 ) - 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_812 , ( T_4 ) - 23 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_761 , 11502 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_762 , 12084 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_763 , 12543 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_764 , 12931 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_765 , 13629 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_766 , 15385 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_767 , 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_768 , 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_769 , 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_770 , 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_771 , 6 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_772 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_773 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_774 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_775 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_776 , V_460 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_777 , 15 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_778 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_779 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_780 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_781 , 24 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_782 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_783 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_784 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_785 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_786 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_787 , 250 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_788 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_789 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_790 , 125 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_791 , 16 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_792 , 25 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_793 , 48 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_794 , 5 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_795 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_796 , 10 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_797 , 50 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_798 , 60 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_799 , 80 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_800 , 100 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_801 , 150 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_802 , 110 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_803 , 40 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_804 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_805 , 12 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_806 , ( T_4 ) 8 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_807 , ( T_4 ) 74 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_808 , ( T_4 ) 18 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_809 , ( T_4 ) 13 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_810 , ( T_4 ) 7 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_811 , ( T_4 ) 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_812 , ( T_4 ) - 8 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_37 ;
T_4 V_335 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_746 , V_747 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_49 ( V_2 , V_748 | V_340 , 0 , NULL , 1 , & V_335 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_101 ( struct V_1 * V_2 )
{
T_1 V_813 = 0 ;
T_1 V_814 = 0 ;
T_1 V_815 = 0 ;
T_4 V_816 = 0 ;
T_1 V_817 = 0 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_813 = ( V_2 -> V_123 * 1000 ) / 3 ;
V_816 = 0 ;
if ( V_2 -> V_356 . V_818 <= 1188750 )
V_816 = 3 ;
else if ( V_2 -> V_356 . V_818 <= 2377500 )
V_816 = 2 ;
else if ( V_2 -> V_356 . V_818 <= 4755000 )
V_816 = 1 ;
V_37 = F_27 ( V_2 , V_819 , V_816 ) ;
if ( V_37 < 0 )
goto error;
V_814 = V_2 -> V_356 . V_818 * ( 1 << V_816 ) ;
if ( V_814 == 0 ) {
V_37 = - V_206 ;
goto error;
}
V_815 = ( V_813 / V_814 ) * ( 1 << 21 ) +
( F_7 ( ( V_813 % V_814 ) , V_814 ) >> 7 ) -
( 1 << 23 ) ;
V_37 = F_29 ( V_2 , V_729 , V_815 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_820 = V_815 ;
V_814 = V_2 -> V_356 . V_818 ;
if ( V_813 == 0 ) {
V_37 = - V_206 ;
goto error;
}
V_817 = ( V_814 / V_813 ) * ( 1 << 12 ) +
( F_7 ( ( V_814 % V_813 ) , V_813 ) >>
16 ) ;
if ( V_817 > 511 )
V_817 = 511 ;
V_37 = F_27 ( V_2 , V_821 , ( T_4 ) V_817 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_64 ( struct V_1 * V_2 , T_1 * V_359 )
{
int V_37 ;
T_4 V_822 [ 2 ] = { 0 , 0 } ;
F_18 ( 1 , L_3 ) ;
* V_359 = V_360 ;
V_37 = F_49 ( V_2 ,
V_748 |
V_823 , 0 , NULL , 2 ,
V_822 ) ;
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
if ( V_822 [ 1 ] < V_824 ) {
} else if ( V_822 [ 1 ] < V_825 ) {
* V_359 = V_743 ;
} else if ( V_822 [ 1 ] < V_826 ) {
* V_359 = V_741 ;
} else {
* V_359 = V_745 ;
}
return V_37 ;
}
static int F_102 ( struct V_1 * V_2 ,
int V_827 )
{
int V_37 ;
T_4 V_335 ;
T_4 V_828 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_828 [ 0 ] = V_2 -> V_179 ;
V_828 [ 1 ] = V_182 ;
if ( V_827 == 2 ) {
T_4 V_829 [ 1 ] = { 0 } ;
if ( V_2 -> V_3 == V_7 )
V_829 [ 0 ] = V_830 ;
else
V_829 [ 0 ] = V_831 ;
V_37 = F_49 ( V_2 ,
V_748 | V_626 ,
1 , V_829 , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_49 ( V_2 ,
V_748 | V_832 ,
V_827 , V_828 ,
1 , & V_335 ) ;
} else if ( V_827 == 4 ) {
if ( V_2 -> V_3 == V_7 )
V_828 [ 2 ] = V_830 ;
else
V_828 [ 2 ] = V_831 ;
V_828 [ 3 ] |= ( V_833 ) ;
V_37 = F_49 ( V_2 ,
V_748 | V_832 ,
V_827 , V_828 ,
1 , & V_335 ) ;
} else {
F_19 ( V_834 L_43
L_44 , V_827 ) ;
}
error:
if ( V_37 < 0 )
F_19 ( V_834 L_45 ,
V_37 , V_60 ) ;
return V_37 ;
}
static int F_59 ( struct V_1 * V_2 , T_4 V_662 ,
T_6 V_509 )
{
int V_37 ;
T_4 V_335 ;
int V_835 = V_2 -> V_836 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_837 , V_838 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_839 , V_840 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_100 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_101 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
switch ( V_2 -> V_356 . V_450 ) {
case V_459 :
V_2 -> V_179 = V_759 ;
break;
case V_695 :
case V_455 :
V_2 -> V_179 = V_757 ;
break;
case V_451 :
V_2 -> V_179 = V_755 ;
break;
case V_453 :
V_2 -> V_179 = V_756 ;
break;
case V_457 :
V_2 -> V_179 = V_758 ;
break;
default:
V_37 = - V_206 ;
break;
}
if ( V_37 < 0 )
goto error;
if ( V_2 -> V_836 == 4
|| ! V_2 -> V_836 ) {
V_835 = 4 ;
V_37 = F_102 ( V_2 , V_835 ) ;
}
if ( V_2 -> V_836 == 2
|| ( ! V_2 -> V_836 && V_37 < 0 ) ) {
V_835 = 2 ;
V_37 = F_102 ( V_2 , V_835 ) ;
}
if ( V_37 < 0 ) {
F_18 ( 1 , L_46
L_47
L_48 ,
V_2 -> V_836 ,
V_2 -> V_841 ) ;
goto error;
} else if ( ! V_2 -> V_836 ) {
F_18 ( 1 , L_49
L_50 ,
V_835 ) ;
V_2 -> V_836 = V_835 ;
}
#if 0
status = SetFrequency(channel, tunerFreqOffset));
if (status < 0)
goto error;
#endif
V_37 = F_81 ( V_2 , V_662 , V_509 , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_94 ( V_2 , V_2 -> V_179 , V_2 -> V_356 . V_818 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_640 , V_842 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_843 , V_844 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_845 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_846 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_847 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_848 , 7 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_849 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_850 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_851 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_852 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_853 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_854 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_855 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_856 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_857 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_858 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_859 , 2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_860 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_861 , 3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_862 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_863 , 4 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_864 , V_865 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_650 ) ;
if ( V_37 < 0 )
goto error;
switch ( V_2 -> V_356 . V_450 ) {
case V_451 :
V_37 = F_95 ( V_2 ) ;
break;
case V_453 :
V_37 = F_96 ( V_2 ) ;
break;
case V_695 :
case V_455 :
V_37 = F_97 ( V_2 ) ;
break;
case V_457 :
V_37 = F_98 ( V_2 ) ;
break;
case V_459 :
V_37 = F_99 ( V_2 ) ;
break;
default:
V_37 = - V_206 ;
break;
}
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_337 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_68 ( V_2 , V_2 -> V_3 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_66 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_660 , V_661 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_746 , V_866 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_345 , V_649 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_49 ( V_2 , V_748 | V_731 , 0 , NULL , 1 , & V_335 ) ;
if ( V_37 < 0 )
goto error;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_57 ( struct V_1 * V_2 ,
enum V_347 V_348 )
{
int V_37 ;
#ifdef F_103
#define F_104
#include "drxk_filters.h"
#undef F_104
#endif
F_18 ( 1 , L_3 ) ;
F_105 ( V_2 ) ;
V_37 = F_93 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_100 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_345 , V_346 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_630 , V_631 ) ;
if ( V_37 < 0 )
goto error;
switch ( V_348 ) {
case V_5 :
V_37 = F_43 ( V_2 , V_867 , V_644 , V_645 ) ;
break;
case V_7 :
V_37 = F_78 ( V_2 , V_868 , V_869 , V_870 , V_645 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_78 ( V_2 , V_871 , V_869 , V_870 , V_645 ) ;
break;
default:
V_37 = - V_206 ;
}
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_637 , ( 1 << V_872 ) ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_873 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_874 , ( ( 1 << V_875 ) | ( 1 << V_876 ) ) ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_636 , 21 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_628 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_641 , 448 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_629 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_647 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_877 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_878 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_879 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_627 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_880 , 500 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_642 , 1000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_604 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_634 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_635 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_646 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_881 , 1 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_51 ( V_2 , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_499 , 0x01 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_80 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_882 , 2000 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_650 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_82 ( V_2 , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_77 ( V_2 , & ( V_2 -> V_161 ) ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_70 ( V_2 , & ( V_2 -> V_158 ) , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_71 ( V_2 , & ( V_2 -> V_159 ) , true ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_337 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_37 ;
T_4 V_883 = 0 ;
F_18 ( 1 , L_3 ) ;
V_37 = F_27 ( V_2 , V_195 , V_196 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_197 , V_198 ) ;
if ( V_37 < 0 )
goto error;
if ( V_2 -> V_214 ) {
if ( V_2 -> V_884 & 0x0001 ) {
V_37 = F_27 ( V_2 , V_885 , V_2 -> V_188 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_886 , & V_883 ) ;
if ( V_37 < 0 )
goto error;
if ( ( V_2 -> V_887 & 0x0001 ) == 0 )
V_883 &= 0x7FFF ;
else
V_883 |= 0x8000 ;
V_37 = F_27 ( V_2 , V_886 , V_883 ) ;
if ( V_37 < 0 )
goto error;
}
if ( V_2 -> V_884 & 0x0002 ) {
V_37 = F_27 ( V_2 , V_888 , V_2 -> V_188 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_886 , & V_883 ) ;
if ( V_37 < 0 )
goto error;
if ( ( V_2 -> V_887 & 0x0002 ) == 0 )
V_883 &= 0xBFFF ;
else
V_883 |= 0x4000 ;
V_37 = F_27 ( V_2 , V_886 , V_883 ) ;
if ( V_37 < 0 )
goto error;
}
if ( V_2 -> V_884 & 0x0004 ) {
V_37 = F_27 ( V_2 , V_889 , V_2 -> V_188 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_23 ( V_2 , V_886 , & V_883 ) ;
if ( V_37 < 0 )
goto error;
if ( ( V_2 -> V_887 & 0x0004 ) == 0 )
V_883 &= 0xFFFB ;
else
V_883 |= 0x0004 ;
V_37 = F_27 ( V_2 , V_886 , V_883 ) ;
if ( V_37 < 0 )
goto error;
}
}
V_37 = F_27 ( V_2 , V_197 , 0x0000 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
bool V_890 ;
F_18 ( 1 , L_3 ) ;
if ( ! V_2 -> V_891 )
return 0 ;
V_890 = V_2 -> V_887 & V_2 -> V_891 ;
if ( V_2 -> V_892 ^ V_890 ) {
if ( V_2 -> V_892 )
V_2 -> V_887 &= ~ V_2 -> V_891 ;
else
V_2 -> V_887 |= V_2 -> V_891 ;
V_37 = F_106 ( V_2 ) ;
}
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
bool V_890 ;
F_18 ( 1 , L_3 ) ;
if ( ! V_2 -> V_891 )
return 0 ;
V_890 = V_2 -> V_887 & V_2 -> V_891 ;
if ( ! ( V_2 -> V_892 ^ V_890 ) ) {
if ( V_2 -> V_892 )
V_2 -> V_887 |= V_2 -> V_891 ;
else
V_2 -> V_887 &= ~ V_2 -> V_891 ;
V_37 = F_106 ( V_2 ) ;
}
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_37 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_122 ) {
V_37 = F_76 ( V_2 , true ) ;
if ( V_37 < 0 )
goto error;
}
V_37 = F_47 ( V_2 , false ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_63 , V_329 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_65 , V_66 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_128 |= V_225 ;
V_37 = F_37 ( V_2 ) ;
error:
if ( V_37 < 0 )
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
return V_37 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_37 = 0 , V_893 = 0 ;
enum V_323 V_334 = V_326 ;
T_4 V_894 ;
F_18 ( 1 , L_3 ) ;
if ( ( V_2 -> V_163 == V_164 ) ) {
F_9 ( V_2 ) ;
V_37 = F_31 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_34 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_895 , V_896 | V_897 | V_898 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_65 , V_66 ) ;
if ( V_37 < 0 )
goto error;
F_32 ( 1 ) ;
V_2 -> V_134 = true ;
V_37 = F_35 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_235 =
( T_4 ) ( ( V_2 -> V_120 / 1000 ) *
V_899 ) / 1000 ;
if ( V_2 -> V_235 >
V_900 ) {
V_2 -> V_235 =
V_900 ;
}
V_2 -> V_235 +=
V_2 -> V_235 <<
V_901 ;
V_37 = F_40 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
#if V_902
if ( ! ( V_2 -> V_9 )
&& ! ( V_2 -> V_131 ) )
#endif
{
V_37 = F_27 ( V_2 , V_195 , V_196 ) ;
if ( V_37 < 0 )
goto error;
}
V_37 = F_42 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_903 , V_904 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_905 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_287 , V_281 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_906 , V_907 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_43 ( V_2 , 0 , 6 , 100 ) ;
if ( V_37 < 0 )
goto error;
if ( V_2 -> V_908 ) {
V_37 = F_46 ( V_2 , V_2 -> V_908 -> V_36 ,
V_2 -> V_908 -> V_909 ) ;
if ( V_37 < 0 )
goto error;
}
V_37 = F_27 ( V_2 , V_287 , V_284 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_336 , V_337 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_34 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
F_32 ( 30 ) ;
V_334 = V_326 ;
V_37 = F_52 ( V_2 , & V_334 ) ;
if ( V_37 < 0 )
goto error;
V_894 =
( ( ( V_910 / 100 ) % 10 ) << 12 ) +
( ( ( V_910 / 10 ) % 10 ) << 8 ) +
( ( V_910 % 10 ) << 4 ) +
( V_911 % 10 ) ;
V_37 = F_27 ( V_2 , V_912 , V_894 ) ;
if ( V_37 < 0 )
goto error;
V_894 =
( ( ( V_913 / 1000 ) % 10 ) << 12 ) +
( ( ( V_913 / 100 ) % 10 ) << 8 ) +
( ( ( V_913 / 10 ) % 10 ) << 4 ) +
( V_913 % 10 ) ;
V_37 = F_27 ( V_2 , V_914 , V_894 ) ;
if ( V_37 < 0 )
goto error;
F_19 ( V_207 L_51 ,
V_910 , V_911 ,
V_913 ) ;
V_37 = F_27 ( V_2 , V_915 , 0 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_27 ( V_2 , V_660 , V_916 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_67 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_48 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_69 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_41 ( V_2 , V_2 -> V_165 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_106 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_163 = V_353 ;
if ( V_2 -> V_130 ) {
V_37 = F_107 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_163 = V_480 ;
} else
V_2 -> V_163 = V_353 ;
V_893 = 0 ;
if ( V_2 -> V_116 ) {
V_2 -> V_917 . V_918 . V_919 [ V_893 ++ ] = V_920 ;
V_2 -> V_917 . V_918 . V_919 [ V_893 ++ ] = V_921 ;
F_109 ( V_2 -> V_917 . V_918 . V_922 . V_923 , L_52 ,
sizeof( V_2 -> V_917 . V_918 . V_922 . V_923 ) ) ;
}
if ( V_2 -> V_115 ) {
V_2 -> V_917 . V_918 . V_919 [ V_893 ++ ] = V_924 ;
F_109 ( V_2 -> V_917 . V_918 . V_922 . V_923 , L_53 ,
sizeof( V_2 -> V_917 . V_918 . V_922 . V_923 ) ) ;
}
F_11 ( V_2 ) ;
}
error:
if ( V_37 < 0 ) {
V_2 -> V_163 = V_925 ;
F_11 ( V_2 ) ;
F_19 ( V_42 L_13 , V_37 , V_60 ) ;
}
return V_37 ;
}
static void F_110 ( const struct V_926 * V_908 ,
void * V_927 )
{
struct V_1 * V_2 = V_927 ;
F_18 ( 1 , L_54 , V_908 ? L_55 : L_56 ) ;
if ( ! V_908 ) {
F_19 ( V_42
L_57 ,
V_2 -> V_841 ) ;
F_19 ( V_207
L_58 ,
V_2 -> V_841 ) ;
V_2 -> V_841 = NULL ;
}
V_2 -> V_908 = V_908 ;
F_108 ( V_2 ) ;
}
static void F_111 ( struct V_928 * V_929 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_908 )
F_112 ( V_2 -> V_908 ) ;
F_113 ( V_2 ) ;
}
static int F_114 ( struct V_928 * V_929 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
if ( V_2 -> V_163 == V_164 )
return 0 ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_115 ( struct V_928 * V_929 , int V_279 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
F_18 ( 1 , L_54 , V_279 ? L_24 : L_25 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
return F_76 ( V_2 , V_279 ? true : false ) ;
}
static int F_116 ( struct V_928 * V_929 )
{
struct V_932 * V_305 = & V_929 -> V_933 ;
T_1 V_919 = V_305 -> V_934 , V_935 ;
struct V_1 * V_2 = V_929 -> V_930 ;
T_1 IF ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
if ( V_2 -> V_163 == V_164 )
return - V_936 ;
if ( ! V_929 -> V_918 . V_937 . V_938 ) {
F_19 ( V_42
L_59 ) ;
return - V_206 ;
}
if ( V_929 -> V_918 . V_939 )
V_929 -> V_918 . V_939 ( V_929 , 1 ) ;
if ( V_929 -> V_918 . V_937 . V_940 )
V_929 -> V_918 . V_937 . V_940 ( V_929 ) ;
if ( V_929 -> V_918 . V_939 )
V_929 -> V_918 . V_939 ( V_929 , 0 ) ;
V_935 = V_2 -> V_356 . V_934 ;
V_2 -> V_356 = * V_305 ;
if ( V_935 != V_919 ) {
F_62 ( V_2 ) ;
switch ( V_919 ) {
case V_920 :
case V_921 :
if ( ! V_2 -> V_116 )
return - V_206 ;
V_2 -> V_941 = ( V_919 == V_921 ) ? true : false ;
if ( V_2 -> V_941 )
F_55 ( V_2 , V_7 ) ;
else
F_55 ( V_2 , V_5 ) ;
break;
case V_924 :
if ( ! V_2 -> V_115 )
return - V_206 ;
F_55 ( V_2 , V_4 ) ;
break;
default:
return - V_206 ;
}
}
V_929 -> V_918 . V_937 . V_938 ( V_929 , & IF ) ;
F_58 ( V_2 , 0 , IF ) ;
return 0 ;
}
static int F_117 ( struct V_928 * V_929 , T_7 * V_37 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
T_1 V_942 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
if ( V_2 -> V_163 == V_164 )
return - V_936 ;
* V_37 = 0 ;
F_63 ( V_2 , & V_942 , 0 ) ;
if ( V_942 == V_741 )
* V_37 |= 0x1f ;
if ( V_942 == V_742 )
* V_37 |= 0x0f ;
if ( V_942 == V_743 )
* V_37 |= 0x07 ;
return 0 ;
}
static int F_118 ( struct V_928 * V_929 , T_1 * V_943 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
if ( V_2 -> V_163 == V_164 )
return - V_936 ;
* V_943 = 0 ;
return 0 ;
}
static int F_119 ( struct V_928 * V_929 ,
T_4 * V_944 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
T_1 V_31 = 0 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
if ( V_2 -> V_163 == V_164 )
return - V_936 ;
F_72 ( V_2 , & V_31 ) ;
* V_944 = V_31 & 0xffff ;
return 0 ;
}
static int F_120 ( struct V_928 * V_929 , T_4 * V_945 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
T_6 V_946 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
if ( V_2 -> V_163 == V_164 )
return - V_936 ;
F_75 ( V_2 , & V_946 ) ;
* V_945 = V_946 & 0xffff ;
return 0 ;
}
static int F_121 ( struct V_928 * V_929 , T_1 * V_947 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
T_4 V_310 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
if ( V_2 -> V_163 == V_164 )
return - V_936 ;
F_83 ( V_2 , & V_310 ) ;
* V_947 = ( T_1 ) V_310 ;
return 0 ;
}
static int F_122 ( struct V_928 * V_929 , struct V_948
* V_949 )
{
struct V_1 * V_2 = V_929 -> V_930 ;
struct V_932 * V_305 = & V_929 -> V_933 ;
F_18 ( 1 , L_3 ) ;
if ( V_2 -> V_163 == V_925 )
return - V_931 ;
if ( V_2 -> V_163 == V_164 )
return - V_936 ;
switch ( V_305 -> V_934 ) {
case V_920 :
case V_921 :
case V_924 :
V_949 -> V_950 = 3000 ;
V_949 -> V_951 = 0 ;
V_949 -> V_952 = 0 ;
return 0 ;
default:
return - V_206 ;
}
}
struct V_928 * F_123 ( const struct V_953 * V_954 ,
struct V_955 * V_25 )
{
struct V_1 * V_2 = NULL ;
T_3 V_30 = V_954 -> V_30 ;
int V_37 ;
F_18 ( 1 , L_3 ) ;
V_2 = F_124 ( sizeof( struct V_1 ) , V_956 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_25 = V_25 ;
V_2 -> V_46 = V_30 ;
V_2 -> V_49 = V_954 -> V_49 ;
V_2 -> V_841 = V_954 -> V_841 ;
V_2 -> V_836 = V_954 -> V_836 ;
V_2 -> V_481 = V_954 -> V_481 ;
V_2 -> V_891 = V_954 -> V_891 ;
V_2 -> V_892 = V_954 -> V_892 ;
V_2 -> V_57 = V_954 -> V_957 ;
V_2 -> V_259 = V_954 -> V_259 ;
if ( V_954 -> V_958 ) {
V_2 -> V_388 = 0 ;
V_2 -> V_389 = 0 ;
} else {
V_2 -> V_388 = 1 ;
V_2 -> V_389 = 1 ;
}
if ( V_954 -> V_959 )
V_2 -> V_257 = V_954 -> V_959 & 0x07 ;
else
V_2 -> V_257 = 0x06 ;
if ( V_954 -> V_960 )
V_2 -> V_243 = true ;
else
V_2 -> V_243 = false ;
V_2 -> V_884 = V_954 -> V_891 ;
if ( ! V_2 -> V_892 && V_2 -> V_891 )
V_2 -> V_887 |= V_2 -> V_891 ;
else
V_2 -> V_887 &= ~ V_2 -> V_891 ;
F_125 ( & V_2 -> V_229 ) ;
memcpy ( & V_2 -> V_917 . V_918 , & V_961 , sizeof( V_961 ) ) ;
V_2 -> V_917 . V_930 = V_2 ;
F_33 ( V_2 ) ;
if ( V_2 -> V_841 ) {
V_37 = F_126 ( V_962 , 1 ,
V_2 -> V_841 ,
V_2 -> V_25 -> V_963 . V_964 ,
V_956 ,
V_2 , F_110 ) ;
if ( V_37 < 0 ) {
F_19 ( V_42
L_60 ) ;
return NULL ;
}
} else if ( F_108 ( V_2 ) < 0 )
goto error;
F_19 ( V_207 L_61 ) ;
return & V_2 -> V_917 ;
error:
F_19 ( V_42 L_62 ) ;
F_113 ( V_2 ) ;
return NULL ;
}
