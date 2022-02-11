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
static inline T_1 F_3 ( T_1 V_8 , T_1 V_9 , T_1 V_10 )
{
T_2 V_11 ;
V_11 = ( T_2 ) V_8 * ( T_2 ) V_9 ;
F_4 ( V_11 , V_10 ) ;
return ( T_1 ) V_11 ;
}
static inline T_1 F_5 ( T_1 V_8 , T_1 V_10 )
{
int V_12 = 0 ;
T_1 V_13 = 0 ;
T_1 V_14 = 0 ;
V_14 = ( V_8 % V_10 ) << 4 ;
V_13 = V_8 / V_10 ;
for ( V_12 = 0 ; V_12 < 7 ; V_12 ++ ) {
V_13 = ( V_13 << 4 ) | ( V_14 / V_10 ) ;
V_14 = ( V_14 % V_10 ) << 4 ;
}
if ( ( V_14 >> 3 ) >= V_10 )
V_13 ++ ;
return V_13 ;
}
static T_1 F_6 ( T_1 V_15 )
{
static const T_3 V_16 = 15 ;
static const T_3 V_17 = 5 ;
T_3 V_12 = 0 ;
T_1 V_18 = 0 ;
T_1 V_19 = 0 ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
static const T_1 V_22 [] = {
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
if ( V_15 == 0 )
return 0 ;
if ( ( V_15 & ( ( 0xffffffff ) << ( V_16 + 1 ) ) ) == 0 ) {
for ( V_20 = V_16 ; V_20 > 0 ; V_20 -- ) {
if ( V_15 & ( ( ( T_1 ) 1 ) << V_16 ) )
break;
V_15 <<= 1 ;
}
} else {
for ( V_20 = V_16 ; V_20 < 31 ; V_20 ++ ) {
if ( ( V_15 & ( ( ( T_1 ) ( - 1 ) ) << ( V_16 + 1 ) ) ) == 0 )
break;
V_15 >>= 1 ;
}
}
V_18 = V_20 * ( ( ( ( T_1 ) 1 ) << V_16 ) * 200 ) ;
V_15 &= ( ( ( ( T_1 ) 1 ) << V_16 ) - 1 ) ;
V_12 = ( T_3 ) ( V_15 >> ( V_16 - V_17 ) ) ;
V_19 = V_15 & ( ( ( ( T_1 ) 1 ) << ( V_16 - V_17 ) ) - 1 ) ;
V_18 += V_22 [ V_12 ] +
( ( V_19 * ( V_22 [ V_12 + 1 ] - V_22 [ V_12 ] ) ) >> ( V_16 - V_17 ) ) ;
V_18 /= 108853 ;
V_21 = ( V_18 >> 1 ) ;
if ( V_18 & ( ( T_1 ) 1 ) )
V_21 ++ ;
return V_21 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_23 ) ;
V_2 -> V_24 = true ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 )
return;
F_10 ( V_2 -> V_23 ) ;
V_2 -> V_24 = false ;
}
static int F_11 ( struct V_1 * V_2 , struct V_25 * V_26 ,
unsigned V_27 )
{
if ( V_2 -> V_24 )
return F_12 ( V_2 -> V_23 , V_26 , V_27 ) ;
else
return F_13 ( V_2 -> V_23 , V_26 , V_27 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_3 V_28 , T_3 * V_29 )
{
struct V_25 V_26 [ 1 ] = { { . V_30 = V_28 , . V_31 = V_32 ,
. V_33 = V_29 , . V_27 = 1 }
} ;
return F_11 ( V_2 , V_26 , 1 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_3 V_28 , T_3 * V_34 , int V_27 )
{
int V_35 ;
struct V_25 V_36 = {
. V_30 = V_28 , . V_31 = 0 , . V_33 = V_34 , . V_27 = V_27 } ;
F_16 ( 3 , L_1 ) ;
if ( V_37 > 2 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ )
F_17 ( V_38 L_2 , V_34 [ V_12 ] ) ;
F_17 ( V_38 L_3 ) ;
}
V_35 = F_11 ( V_2 , & V_36 , 1 ) ;
if ( V_35 >= 0 && V_35 != 1 )
V_35 = - V_39 ;
if ( V_35 < 0 )
F_17 ( V_40 L_4 , V_28 ) ;
return V_35 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_3 V_28 , T_3 * V_36 , int V_27 , T_3 * V_41 , int V_42 )
{
int V_35 ;
struct V_25 V_26 [ 2 ] = {
{ . V_30 = V_28 , . V_31 = 0 ,
. V_33 = V_36 , . V_27 = V_27 } ,
{ . V_30 = V_28 , . V_31 = V_32 ,
. V_33 = V_41 , . V_27 = V_42 }
} ;
V_35 = F_11 ( V_2 , V_26 , 2 ) ;
if ( V_35 != 2 ) {
if ( V_37 > 2 )
F_17 ( V_38 L_5 ) ;
if ( V_35 >= 0 )
V_35 = - V_39 ;
F_17 ( V_40 L_6 , V_28 ) ;
return V_35 ;
}
if ( V_37 > 2 ) {
int V_12 ;
F_16 ( 2 , L_7 ) ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ )
F_17 ( V_38 L_2 , V_36 [ V_12 ] ) ;
F_17 ( V_38 L_8 ) ;
for ( V_12 = 0 ; V_12 < V_42 ; V_12 ++ )
F_17 ( V_38 L_2 , V_41 [ V_12 ] ) ;
F_17 ( V_38 L_3 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_43 , T_4 * V_34 , T_3 V_31 )
{
int V_35 ;
T_3 V_28 = V_2 -> V_44 , V_45 [ 4 ] , V_46 [ 2 ] , V_27 ;
if ( V_2 -> V_47 )
V_31 |= 0xC0 ;
if ( F_20 ( V_43 ) || ( V_31 != 0 ) ) {
V_45 [ 0 ] = ( ( ( V_43 << 1 ) & 0xFF ) | 0x01 ) ;
V_45 [ 1 ] = ( ( V_43 >> 16 ) & 0xFF ) ;
V_45 [ 2 ] = ( ( V_43 >> 24 ) & 0xFF ) | V_31 ;
V_45 [ 3 ] = ( ( V_43 >> 7 ) & 0xFF ) ;
V_27 = 4 ;
} else {
V_45 [ 0 ] = ( ( V_43 << 1 ) & 0xFF ) ;
V_45 [ 1 ] = ( ( ( V_43 >> 16 ) & 0x0F ) | ( ( V_43 >> 18 ) & 0xF0 ) ) ;
V_27 = 2 ;
}
F_16 ( 2 , L_9 , V_43 , V_31 ) ;
V_35 = F_18 ( V_2 , V_28 , V_45 , V_27 , V_46 , 2 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_34 )
* V_34 = V_46 [ 0 ] | ( V_46 [ 1 ] << 8 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_43 , T_4 * V_34 )
{
return F_19 ( V_2 , V_43 , V_34 , 0 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_43 , T_1 * V_34 , T_3 V_31 )
{
int V_35 ;
T_3 V_28 = V_2 -> V_44 , V_45 [ 4 ] , V_46 [ 4 ] , V_27 ;
if ( V_2 -> V_47 )
V_31 |= 0xC0 ;
if ( F_20 ( V_43 ) || ( V_31 != 0 ) ) {
V_45 [ 0 ] = ( ( ( V_43 << 1 ) & 0xFF ) | 0x01 ) ;
V_45 [ 1 ] = ( ( V_43 >> 16 ) & 0xFF ) ;
V_45 [ 2 ] = ( ( V_43 >> 24 ) & 0xFF ) | V_31 ;
V_45 [ 3 ] = ( ( V_43 >> 7 ) & 0xFF ) ;
V_27 = 4 ;
} else {
V_45 [ 0 ] = ( ( V_43 << 1 ) & 0xFF ) ;
V_45 [ 1 ] = ( ( ( V_43 >> 16 ) & 0x0F ) | ( ( V_43 >> 18 ) & 0xF0 ) ) ;
V_27 = 2 ;
}
F_16 ( 2 , L_9 , V_43 , V_31 ) ;
V_35 = F_18 ( V_2 , V_28 , V_45 , V_27 , V_46 , 4 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_34 )
* V_34 = V_46 [ 0 ] | ( V_46 [ 1 ] << 8 ) |
( V_46 [ 2 ] << 16 ) | ( V_46 [ 3 ] << 24 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_43 , T_1 * V_34 )
{
return F_22 ( V_2 , V_43 , V_34 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_43 , T_4 V_34 , T_3 V_31 )
{
T_3 V_28 = V_2 -> V_44 , V_48 [ 6 ] , V_27 ;
if ( V_2 -> V_47 )
V_31 |= 0xC0 ;
if ( F_20 ( V_43 ) || ( V_31 != 0 ) ) {
V_48 [ 0 ] = ( ( ( V_43 << 1 ) & 0xFF ) | 0x01 ) ;
V_48 [ 1 ] = ( ( V_43 >> 16 ) & 0xFF ) ;
V_48 [ 2 ] = ( ( V_43 >> 24 ) & 0xFF ) | V_31 ;
V_48 [ 3 ] = ( ( V_43 >> 7 ) & 0xFF ) ;
V_27 = 4 ;
} else {
V_48 [ 0 ] = ( ( V_43 << 1 ) & 0xFF ) ;
V_48 [ 1 ] = ( ( ( V_43 >> 16 ) & 0x0F ) | ( ( V_43 >> 18 ) & 0xF0 ) ) ;
V_27 = 2 ;
}
V_48 [ V_27 ] = V_34 & 0xff ;
V_48 [ V_27 + 1 ] = ( V_34 >> 8 ) & 0xff ;
F_16 ( 2 , L_10 , V_43 , V_34 , V_31 ) ;
return F_15 ( V_2 , V_28 , V_48 , V_27 + 2 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_43 , T_4 V_34 )
{
return F_24 ( V_2 , V_43 , V_34 , 0 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_43 , T_1 V_34 , T_3 V_31 )
{
T_3 V_28 = V_2 -> V_44 , V_48 [ 8 ] , V_27 ;
if ( V_2 -> V_47 )
V_31 |= 0xC0 ;
if ( F_20 ( V_43 ) || ( V_31 != 0 ) ) {
V_48 [ 0 ] = ( ( ( V_43 << 1 ) & 0xFF ) | 0x01 ) ;
V_48 [ 1 ] = ( ( V_43 >> 16 ) & 0xFF ) ;
V_48 [ 2 ] = ( ( V_43 >> 24 ) & 0xFF ) | V_31 ;
V_48 [ 3 ] = ( ( V_43 >> 7 ) & 0xFF ) ;
V_27 = 4 ;
} else {
V_48 [ 0 ] = ( ( V_43 << 1 ) & 0xFF ) ;
V_48 [ 1 ] = ( ( ( V_43 >> 16 ) & 0x0F ) | ( ( V_43 >> 18 ) & 0xF0 ) ) ;
V_27 = 2 ;
}
V_48 [ V_27 ] = V_34 & 0xff ;
V_48 [ V_27 + 1 ] = ( V_34 >> 8 ) & 0xff ;
V_48 [ V_27 + 2 ] = ( V_34 >> 16 ) & 0xff ;
V_48 [ V_27 + 3 ] = ( V_34 >> 24 ) & 0xff ;
F_16 ( 2 , L_11 , V_43 , V_34 , V_31 ) ;
return F_15 ( V_2 , V_28 , V_48 , V_27 + 4 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_43 , T_1 V_34 )
{
return F_26 ( V_2 , V_43 , V_34 , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_49 ,
const int V_50 , const T_3 V_51 [] )
{
int V_35 = 0 , V_52 = V_50 ;
T_3 V_53 = 0 ;
if ( V_2 -> V_47 )
V_53 |= 0xC0 ;
while ( V_52 > 0 ) {
int V_54 = V_52 > V_2 -> V_55 ?
V_2 -> V_55 : V_52 ;
T_3 * V_56 = & V_2 -> V_54 [ 0 ] ;
T_1 V_57 = 0 ;
if ( F_20 ( V_49 ) || ( V_53 != 0 ) ) {
V_56 [ 0 ] = ( ( ( V_49 << 1 ) & 0xFF ) | 0x01 ) ;
V_56 [ 1 ] = ( ( V_49 >> 16 ) & 0xFF ) ;
V_56 [ 2 ] = ( ( V_49 >> 24 ) & 0xFF ) ;
V_56 [ 3 ] = ( ( V_49 >> 7 ) & 0xFF ) ;
V_56 [ 2 ] |= V_53 ;
V_57 = 4 ;
if ( V_54 == V_2 -> V_55 )
V_54 -= 2 ;
} else {
V_56 [ 0 ] = ( ( V_49 << 1 ) & 0xFF ) ;
V_56 [ 1 ] = ( ( ( V_49 >> 16 ) & 0x0F ) |
( ( V_49 >> 18 ) & 0xF0 ) ) ;
V_57 = 2 ;
}
memcpy ( & V_2 -> V_54 [ V_57 ] , V_51 , V_54 ) ;
F_16 ( 2 , L_9 , V_49 , V_53 ) ;
if ( V_37 > 1 ) {
int V_12 ;
if ( V_51 )
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ )
F_17 ( V_38 L_2 , V_51 [ V_12 ] ) ;
F_17 ( V_38 L_3 ) ;
}
V_35 = F_15 ( V_2 , V_2 -> V_44 ,
& V_2 -> V_54 [ 0 ] , V_54 + V_57 ) ;
if ( V_35 < 0 ) {
F_17 ( V_40 L_12 ,
V_58 , V_49 ) ;
break;
}
V_51 += V_54 ;
V_49 += ( V_54 >> 1 ) ;
V_52 -= V_54 ;
}
return V_35 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_35 ;
T_3 V_34 = 0 ;
T_4 V_59 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_14 ( V_2 , V_2 -> V_44 , & V_34 ) ;
if ( V_35 < 0 ) {
do {
V_34 = 0 ;
V_35 = F_15 ( V_2 , V_2 -> V_44 ,
& V_34 , 1 ) ;
F_30 ( 10 ) ;
V_59 ++ ;
if ( V_35 < 0 )
continue;
V_35 = F_14 ( V_2 , V_2 -> V_44 ,
& V_34 ) ;
} while ( V_35 < 0 &&
( V_59 < V_60 ) );
if ( V_35 < 0 && V_59 >= V_60 )
goto error;
}
V_35 = F_25 ( V_2 , V_61 , V_62 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_63 , V_64 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_65 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_66 = V_67 ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_68 = V_69 ;
T_1 V_70 = 0 ;
T_1 V_71 = 0 ;
T_1 V_72 = 0x7FFF ;
T_1 V_73 = 3 ;
T_1 V_74 = V_69 ;
T_1 V_75 = 0 ;
T_1 V_76 = 0 ;
T_1 V_77 = 0x7FFF ;
T_1 V_78 = 3 ;
T_1 V_79 = 9500 ;
T_1 V_80 = 4000 ;
T_1 V_81 = V_69 ;
T_1 V_82 = 0 ;
T_1 V_83 = 0 ;
T_1 V_84 = 0 ;
T_1 V_85 = 3 ;
T_1 V_86 = V_87 ;
T_1 V_88 = 0 ;
T_1 V_89 = 0 ;
T_1 V_90 = 0 ;
T_1 V_91 = 9500 ;
T_1 V_92 = 4000 ;
T_1 V_93 = 3 ;
T_1 V_94 = V_95 ;
T_1 V_96 = V_97 ;
T_1 V_98 = V_99 ;
T_1 V_100 = V_101 ;
T_1 V_102 = 0x0113 ;
T_1 V_103 = 0 ;
T_1 V_104 = V_105 ;
T_1 V_106 = 50000000 ;
T_1 V_107 = V_108 * 8 ;
T_1 V_109 = 0 ;
T_1 V_110 = 1 ;
T_1 V_111 = 0 ;
F_16 ( 1 , L_3 ) ;
V_2 -> V_112 = false ;
V_2 -> V_113 = false ;
V_2 -> V_114 = false ;
V_2 -> V_115 = false ;
V_2 -> V_116 = false ;
V_2 -> V_117 = false ;
if ( ! V_2 -> V_55 )
V_2 -> V_55 = 124 ;
V_2 -> V_118 = 0 ;
V_2 -> V_119 = false ;
V_2 -> V_120 = false ;
V_2 -> V_121 = 151875 ;
V_2 -> V_122 = ( ( V_2 -> V_121 / 1000 ) *
V_123 ) / 1000 ;
if ( V_2 -> V_122 > V_124 )
V_2 -> V_122 = V_124 ;
V_2 -> V_125 = ( V_2 -> V_44 << 1 ) ;
V_2 -> V_126 = V_127 ;
V_2 -> V_128 = ( V_111 != 0 ) ;
V_2 -> V_129 = false ;
V_2 -> V_130 . V_131 = ( V_68 ) ;
V_2 -> V_130 . V_132 = ( V_70 ) ;
V_2 -> V_130 . V_133 = ( V_71 ) ;
V_2 -> V_130 . V_134 = ( V_72 ) ;
V_2 -> V_130 . V_135 = ( V_73 ) ;
V_2 -> V_136 = 140 ;
V_2 -> V_137 . V_131 = ( V_74 ) ;
V_2 -> V_137 . V_132 = ( V_75 ) ;
V_2 -> V_137 . V_133 = ( V_76 ) ;
V_2 -> V_137 . V_134 = ( V_77 ) ;
V_2 -> V_137 . V_135 = ( V_78 ) ;
V_2 -> V_137 . V_138 = ( V_79 ) ;
V_2 -> V_137 . V_139 = ( V_80 ) ;
V_2 -> V_140 . V_141 = 0x07 ;
V_2 -> V_140 . V_142 = true ;
V_2 -> V_143 = V_95 ;
V_2 -> V_144 = V_97 ;
if ( V_96 <= 500 && V_94 < V_96 ) {
V_2 -> V_143 = V_94 ;
V_2 -> V_144 = V_96 ;
}
V_2 -> V_145 . V_131 = ( V_81 ) ;
V_2 -> V_145 . V_132 = ( V_82 ) ;
V_2 -> V_145 . V_133 = ( V_83 ) ;
V_2 -> V_145 . V_134 = ( V_84 ) ;
V_2 -> V_145 . V_135 = ( V_85 ) ;
V_2 -> V_146 . V_131 = ( V_86 ) ;
V_2 -> V_146 . V_132 = ( V_88 ) ;
V_2 -> V_146 . V_133 = ( V_89 ) ;
V_2 -> V_146 . V_134 = ( V_90 ) ;
V_2 -> V_146 . V_135 = ( V_93 ) ;
V_2 -> V_146 . V_138 = ( V_91 ) ;
V_2 -> V_146 . V_139 = ( V_92 ) ;
V_2 -> V_147 . V_141 = 0x04 ;
V_2 -> V_147 . V_142 = true ;
V_2 -> V_148 . V_131 = V_87 ;
V_2 -> V_148 . V_132 = 0 ;
V_2 -> V_148 . V_133 = 0 ;
V_2 -> V_148 . V_134 = 0xFFFF ;
V_2 -> V_148 . V_138 = 0x2100 ;
V_2 -> V_148 . V_139 = 4000 ;
V_2 -> V_148 . V_135 = 1 ;
V_2 -> V_149 . V_131 = V_69 ;
V_2 -> V_149 . V_132 = 0 ;
V_2 -> V_149 . V_133 = 0 ;
V_2 -> V_149 . V_134 = 9000 ;
V_2 -> V_149 . V_138 = 13424 ;
V_2 -> V_149 . V_139 = 0 ;
V_2 -> V_149 . V_135 = 3 ;
V_2 -> V_149 . V_150 = 30 ;
V_2 -> V_149 . V_151 = 30000 ;
V_2 -> V_152 . V_141 = 4 ;
V_2 -> V_152 . V_142 = false ;
V_2 -> V_153 . V_131 = V_87 ;
V_2 -> V_153 . V_132 = 0 ;
V_2 -> V_153 . V_133 = 6023 ;
V_2 -> V_153 . V_134 = 27000 ;
V_2 -> V_153 . V_138 = 0x2380 ;
V_2 -> V_153 . V_139 = 4000 ;
V_2 -> V_153 . V_135 = 3 ;
V_2 -> V_154 . V_131 = V_69 ;
V_2 -> V_154 . V_132 = 0 ;
V_2 -> V_154 . V_133 = 0 ;
V_2 -> V_154 . V_134 = 9000 ;
V_2 -> V_154 . V_138 = 0x0511 ;
V_2 -> V_154 . V_139 = 0 ;
V_2 -> V_154 . V_135 = 3 ;
V_2 -> V_154 . V_151 = 5119 ;
V_2 -> V_154 . V_150 = 50 ;
V_2 -> V_155 = 140 ;
V_2 -> V_156 . V_141 = 4 ;
V_2 -> V_156 . V_142 = false ;
V_2 -> V_3 = V_157 ;
V_2 -> V_158 = V_159 ;
V_2 -> V_160 = true ;
V_2 -> V_161 = false ;
V_2 -> V_162 = false ;
V_2 -> V_163 = false ;
V_2 -> V_164 = false ;
V_2 -> V_165 = false ;
V_2 -> V_166 = ( V_103 != 0 ) ;
V_2 -> V_167 = V_106 ;
V_2 -> V_168 = V_107 ;
V_2 -> V_169 = ( V_104 & 0x07 ) ;
V_2 -> V_170 = 19392658 ;
V_2 -> V_171 = false ;
if ( V_109 )
V_2 -> V_161 = true ;
V_2 -> V_172 = V_99 ;
if ( V_98 < 10000 )
V_2 -> V_172 = V_98 ;
V_2 -> V_173 = V_101 ;
if ( V_100 < 10000 )
V_2 -> V_173 = V_100 ;
V_2 -> V_174 = V_175 ;
V_2 -> V_176 = V_177 ;
V_2 -> V_178 = 204 * 8 ;
V_2 -> V_179 = 1 ;
V_2 -> V_180 = V_181 ;
V_2 -> V_182 = 0 ;
V_2 -> V_183 = ( V_102 ) ;
V_2 -> V_128 = false ;
V_2 -> V_66 = V_184 ;
V_2 -> V_185 = ( V_110 == 0 ) ;
V_2 -> V_186 = false ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
T_1 V_187 = 0 ;
T_4 V_188 = 0 ;
T_4 V_189 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_190 , V_191 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_192 , & V_189 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_192 , V_193 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_23 ( V_2 , V_194 , & V_187 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_195 , & V_188 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_192 , V_189 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_4 V_196 = 0 ;
T_1 V_197 = 0 ;
int V_35 ;
const char * V_198 = L_14 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_190 , V_191 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_192 , V_193 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_199 , & V_196 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_192 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
switch ( ( V_196 & V_200 ) ) {
case 0 :
break;
case 1 :
V_2 -> V_118 = 27000 ;
break;
case 2 :
V_2 -> V_118 = 20250 ;
break;
case 3 :
V_2 -> V_118 = 20250 ;
break;
default:
F_17 ( V_40 L_15 ) ;
return - V_201 ;
}
V_35 = F_23 ( V_2 , V_194 , & V_197 ) ;
if ( V_35 < 0 )
goto error;
F_17 ( V_202 L_16 , V_197 ) ;
switch ( ( V_197 >> 29 ) & 0xF ) {
case 0 :
V_2 -> V_203 = V_204 ;
V_198 = L_17 ;
break;
case 2 :
V_2 -> V_203 = V_205 ;
V_198 = L_18 ;
break;
case 3 :
V_2 -> V_203 = V_206 ;
V_198 = L_19 ;
break;
default:
V_2 -> V_203 = V_207 ;
V_35 = - V_201 ;
F_17 ( V_40 L_20 ,
( V_197 >> 29 ) & 0xF ) ;
goto V_208;
}
switch ( ( V_197 >> 12 ) & 0xFF ) {
case 0x13 :
V_2 -> V_112 = false ;
V_2 -> V_116 = false ;
V_2 -> V_115 = false ;
V_2 -> V_117 = false ;
V_2 -> V_113 = true ;
V_2 -> V_114 = true ;
V_2 -> V_209 = true ;
V_2 -> V_210 = false ;
V_2 -> V_211 = false ;
V_2 -> V_212 = false ;
break;
case 0x15 :
V_2 -> V_112 = false ;
V_2 -> V_116 = false ;
V_2 -> V_115 = true ;
V_2 -> V_117 = false ;
V_2 -> V_113 = true ;
V_2 -> V_114 = false ;
V_2 -> V_209 = true ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = false ;
break;
case 0x16 :
V_2 -> V_112 = false ;
V_2 -> V_116 = false ;
V_2 -> V_115 = true ;
V_2 -> V_117 = false ;
V_2 -> V_113 = true ;
V_2 -> V_114 = false ;
V_2 -> V_209 = true ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = false ;
break;
case 0x18 :
V_2 -> V_112 = false ;
V_2 -> V_116 = false ;
V_2 -> V_115 = true ;
V_2 -> V_117 = true ;
V_2 -> V_113 = true ;
V_2 -> V_114 = false ;
V_2 -> V_209 = true ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = false ;
break;
case 0x21 :
V_2 -> V_112 = false ;
V_2 -> V_116 = false ;
V_2 -> V_115 = true ;
V_2 -> V_117 = true ;
V_2 -> V_113 = true ;
V_2 -> V_114 = true ;
V_2 -> V_209 = true ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = false ;
break;
case 0x23 :
V_2 -> V_112 = false ;
V_2 -> V_116 = false ;
V_2 -> V_115 = true ;
V_2 -> V_117 = true ;
V_2 -> V_113 = true ;
V_2 -> V_114 = true ;
V_2 -> V_209 = true ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = false ;
break;
case 0x25 :
V_2 -> V_112 = false ;
V_2 -> V_116 = false ;
V_2 -> V_115 = true ;
V_2 -> V_117 = true ;
V_2 -> V_113 = true ;
V_2 -> V_114 = true ;
V_2 -> V_209 = true ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = false ;
break;
case 0x26 :
V_2 -> V_112 = false ;
V_2 -> V_116 = false ;
V_2 -> V_115 = true ;
V_2 -> V_117 = false ;
V_2 -> V_113 = true ;
V_2 -> V_114 = true ;
V_2 -> V_209 = true ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = false ;
break;
default:
F_17 ( V_40 L_21 ,
( ( V_197 >> 12 ) & 0xFF ) ) ;
V_35 = - V_201 ;
goto V_208;
}
F_17 ( V_202
L_22 ,
( ( V_197 >> 12 ) & 0xFF ) , V_198 ,
V_2 -> V_118 / 1000 ,
V_2 -> V_118 % 1000 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
V_208:
return V_35 ;
}
static int F_34 ( struct V_1 * V_2 , T_4 V_213 , T_4 * V_214 )
{
int V_35 ;
bool V_215 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_216 , V_213 ) ;
if ( V_35 < 0 )
goto error;
if ( V_213 == V_217 )
F_30 ( 1 ) ;
V_215 =
( bool ) ( ( V_213 == V_218 ) &&
( ( V_2 -> V_126 ) &
V_219 ) ==
V_220 ) ;
if ( V_215 == false ) {
T_1 V_59 = 0 ;
T_4 V_221 ;
do {
F_30 ( 1 ) ;
V_59 += 1 ;
V_35 = F_21 ( V_2 , V_216 ,
& V_221 ) ;
} while ( ( V_35 < 0 ) && ( V_59 < V_222 )
&& ( V_221 != 0 ) );
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_223 , V_214 ) ;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
F_36 ( & V_2 -> V_224 ) ;
V_35 = F_25 ( V_2 , V_225 , V_2 -> V_226 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_227 , V_2 -> V_126 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_228 , V_2 -> V_125 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_229 , V_2 -> V_230 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_231 , V_2 -> V_122 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_232 , V_233 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_34 ( V_2 , V_218 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_126 &= ~ V_220 ;
error:
F_37 ( & V_2 -> V_224 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_38 ( struct V_1 * V_2 )
{
F_16 ( 1 , L_3 ) ;
V_2 -> V_125 = ( V_2 -> V_44 << 1 ) ;
V_2 -> V_226 = 0x96FF ;
V_2 -> V_126 = V_127 ;
return F_35 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 , bool V_234 )
{
int V_35 = - 1 ;
T_4 V_235 = 0 ;
T_4 V_236 = 0 ;
T_4 V_237 = 0 ;
F_16 ( 1 , L_23 ,
V_234 ? L_24 : L_25 ,
V_2 -> V_238 ? L_26 : L_27 ) ;
V_35 = F_25 ( V_2 , V_190 , V_191 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_192 , V_193 ) ;
if ( V_35 < 0 )
goto error;
if ( V_234 == false ) {
V_35 = F_25 ( V_2 , V_239 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_240 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_241 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_242 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_243 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_244 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_245 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_246 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_247 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_248 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_249 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_250 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
} else {
V_236 =
( ( V_2 -> V_169 <<
V_251 ) | 0x0003 ) ;
V_235 = ( ( V_2 -> V_252 <<
V_253 ) |
0x0003 ) ;
V_35 = F_25 ( V_2 , V_239 , V_236 ) ;
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_254 )
V_237 = V_236 ;
V_35 = F_25 ( V_2 , V_240 , V_237 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_242 , V_237 ) ;
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_238 == true ) {
V_35 = F_25 ( V_2 , V_244 , V_236 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_245 , V_236 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_246 , V_236 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_247 , V_236 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_248 , V_236 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_249 , V_236 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_250 , V_236 ) ;
if ( V_35 < 0 )
goto error;
} else {
V_236 = ( ( V_2 -> V_169 <<
V_251 )
| 0x0003 ) ;
V_35 = F_25 ( V_2 , V_244 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_245 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_246 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_247 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_248 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_249 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_250 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_25 ( V_2 , V_241 , V_235 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_243 , V_236 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_25 ( V_2 , V_255 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_192 , 0x0000 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_16 ( 1 , L_3 ) ;
return F_39 ( V_2 , false ) ;
}
static int F_41 ( struct V_1 * V_2 ,
T_4 V_256 , T_4 V_257 , T_1 V_258 )
{
T_4 V_259 = 0 ;
int V_35 ;
unsigned long V_260 ;
F_16 ( 1 , L_3 ) ;
F_36 ( & V_2 -> V_224 ) ;
V_35 = F_25 ( V_2 , V_261 , V_262 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_263 , V_256 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_264 , V_257 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_265 , V_266 ) ;
if ( V_35 < 0 )
goto error;
V_260 = V_267 + F_42 ( V_258 ) ;
do {
F_30 ( 1 ) ;
V_35 = F_21 ( V_2 , V_268 , & V_259 ) ;
if ( V_35 < 0 )
goto error;
} while ( ( V_259 == 0x1 ) &&
( ( F_43 ( V_260 ) ) ) );
if ( V_259 == 0x1 ) {
F_17 ( V_40 L_28 ) ;
V_35 = - V_201 ;
goto V_208;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
V_208:
F_37 ( & V_2 -> V_224 ) ;
return V_35 ;
}
static int F_44 ( struct V_1 * V_2 ,
const T_3 V_269 [] , T_1 V_270 )
{
const T_3 * V_271 = V_269 ;
T_1 V_49 ;
T_4 V_272 ;
T_4 V_50 ;
T_1 V_273 = 0 ;
T_1 V_12 ;
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
#if 0
Drain = (pSrc[0] << 8) | pSrc[1];
#endif
V_271 += sizeof( T_4 ) ;
V_273 += sizeof( T_4 ) ;
V_272 = ( V_271 [ 0 ] << 8 ) | V_271 [ 1 ] ;
V_271 += sizeof( T_4 ) ;
V_273 += sizeof( T_4 ) ;
for ( V_12 = 0 ; V_12 < V_272 ; V_12 += 1 ) {
V_49 = ( V_271 [ 0 ] << 24 ) | ( V_271 [ 1 ] << 16 ) |
( V_271 [ 2 ] << 8 ) | V_271 [ 3 ] ;
V_271 += sizeof( T_1 ) ;
V_273 += sizeof( T_1 ) ;
V_50 = ( ( V_271 [ 0 ] << 8 ) | V_271 [ 1 ] ) * sizeof( T_4 ) ;
V_271 += sizeof( T_4 ) ;
V_273 += sizeof( T_4 ) ;
#if 0
Flags = (pSrc[0] << 8) | pSrc[1];
#endif
V_271 += sizeof( T_4 ) ;
V_273 += sizeof( T_4 ) ;
#if 0
BlockCRC = (pSrc[0] << 8) | pSrc[1];
#endif
V_271 += sizeof( T_4 ) ;
V_273 += sizeof( T_4 ) ;
if ( V_273 + V_50 > V_270 ) {
F_17 ( V_40 L_29 ) ;
return - V_201 ;
}
V_35 = F_28 ( V_2 , V_49 , V_50 , V_271 ) ;
if ( V_35 < 0 ) {
F_17 ( V_40 L_30 , V_35 ) ;
break;
}
V_271 += V_50 ;
V_273 += V_50 ;
}
return V_35 ;
}
static int F_45 ( struct V_1 * V_2 , bool V_274 )
{
int V_35 ;
T_4 V_34 = 0 ;
T_4 V_275 = V_276 ;
T_4 V_277 = V_278 ;
unsigned long V_260 ;
F_16 ( 1 , L_3 ) ;
if ( V_274 == false ) {
V_275 = V_279 ;
V_277 = V_280 ;
}
V_35 = F_21 ( V_2 , V_281 , & V_34 ) ;
if ( V_35 >= 0 && V_34 == V_277 ) {
return V_35 ;
}
V_35 = F_25 ( V_2 , V_282 , V_275 ) ;
V_260 = V_267 + F_42 ( V_283 ) ;
do {
V_35 = F_21 ( V_2 , V_281 , & V_34 ) ;
if ( ( V_35 >= 0 && V_34 == V_277 ) || F_43 ( V_260 ) )
break;
F_30 ( 1 ) ;
} while ( 1 );
if ( V_34 != V_277 ) {
F_17 ( V_40 L_28 ) ;
return - V_201 ;
}
return V_35 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
T_4 V_284 = 0 ;
T_4 V_285 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_286 , & V_284 ) ;
if ( V_35 < 0 )
goto error;
V_284 |= V_287 ;
V_35 = F_25 ( V_2 , V_286 , V_284 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_288 , & V_285 ) ;
if ( V_35 < 0 )
goto error;
V_285 |= V_289 ;
V_35 = F_25 ( V_2 , V_288 , V_285 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_47 ( struct V_1 * V_2 ,
T_4 V_213 , T_3 V_290 ,
T_4 * V_291 , T_3 V_292 , T_4 * V_293 )
{
#if ( V_294 - V_295 ) != 15
#error DRXK register mapping no longer compatible with this routine!
#endif
T_4 V_296 = 0 ;
int V_35 = - V_201 ;
unsigned long V_260 ;
T_3 V_297 [ 34 ] ;
int V_298 = 0 , V_299 ;
const char * V_300 ;
char V_301 [ 30 ] ;
F_16 ( 1 , L_3 ) ;
if ( ( V_213 == 0 ) || ( ( V_290 > 0 ) && ( V_291 == NULL ) ) ||
( ( V_292 > 0 ) && ( V_293 == NULL ) ) ) {
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
F_36 ( & V_2 -> V_224 ) ;
for ( V_299 = V_290 - 1 ; V_299 >= 0 ; V_299 -= 1 ) {
V_297 [ V_298 ++ ] = ( V_291 [ V_299 ] & 0xFF ) ;
V_297 [ V_298 ++ ] = ( ( V_291 [ V_299 ] >> 8 ) & 0xFF ) ;
}
V_297 [ V_298 ++ ] = ( V_213 & 0xFF ) ;
V_297 [ V_298 ++ ] = ( ( V_213 >> 8 ) & 0xFF ) ;
F_28 ( V_2 , V_294 -
( V_290 - 1 ) , V_298 , V_297 ) ;
V_260 = V_267 + F_42 ( V_302 ) ;
do {
F_30 ( 1 ) ;
V_35 = F_21 ( V_2 , V_303 , & V_296 ) ;
if ( V_35 < 0 )
goto error;
} while ( ! ( V_296 == V_304 ) && ( F_43 ( V_260 ) ) );
if ( V_296 != V_304 ) {
F_17 ( V_40 L_31 ) ;
V_35 = - V_39 ;
goto V_208;
}
if ( ( V_292 > 0 ) && ( V_293 != NULL ) ) {
T_5 V_305 ;
int V_299 ;
for ( V_299 = V_292 - 1 ; V_299 >= 0 ; V_299 -= 1 ) {
V_35 = F_21 ( V_2 , V_294 - V_299 , & V_293 [ V_299 ] ) ;
if ( V_35 < 0 )
goto error;
}
V_305 = ( T_5 ) V_293 [ 0 ] ;
if ( V_305 >= 0 )
goto error;
switch ( V_305 ) {
case V_306 :
V_300 = L_32 ;
break;
case V_307 :
V_300 = L_33 ;
break;
case V_308 :
V_300 = L_34 ;
break;
case V_309 :
V_300 = L_35 ;
break;
default:
sprintf ( V_301 , L_36 , V_305 ) ;
V_300 = V_301 ;
}
F_17 ( V_40 L_37 , V_300 , V_213 ) ;
F_48 ( L_38 , V_310 , V_297 , V_298 ) ;
V_35 = - V_201 ;
goto V_208;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
V_208:
F_37 ( & V_2 -> V_224 ) ;
return V_35 ;
}
static int F_49 ( struct V_1 * V_2 , bool V_311 )
{
T_4 V_34 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_312 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( ! V_311 ) {
V_34 |= ( V_313
| V_314
| V_315
| V_316
| V_317 ) ;
} else {
V_34 &= ( ( ~ V_313 )
& ( ~ V_314 )
& ( ~ V_315 )
& ( ~ V_316 )
& ( ~ V_317 )
) ;
}
V_35 = F_25 ( V_2 , V_312 , V_34 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_50 ( struct V_1 * V_2 , enum V_318 * V_319 )
{
int V_35 = 0 ;
T_4 V_320 = 0 ;
F_16 ( 1 , L_3 ) ;
if ( V_319 == NULL )
return - V_201 ;
switch ( * V_319 ) {
case V_67 :
V_320 = V_62 ;
break;
case V_321 :
V_320 = V_322 ;
break;
case V_323 :
V_320 = V_324 ;
break;
case V_325 :
V_320 = V_326 ;
break;
case V_184 :
V_320 = V_327 ;
break;
default:
return - V_201 ;
}
if ( V_2 -> V_66 == * V_319 )
return 0 ;
if ( V_2 -> V_66 != V_67 ) {
V_35 = F_29 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_45 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
}
if ( * V_319 == V_67 ) {
} else {
switch ( V_2 -> V_3 ) {
case V_4 :
V_35 = F_46 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_51 ( V_2 , false ) ;
if ( V_35 < 0 )
goto error;
break;
case V_5 :
case V_7 :
V_35 = F_46 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_52 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
break;
default:
break;
}
V_35 = F_45 ( V_2 , false ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_61 , V_320 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_63 , V_64 ) ;
if ( V_35 < 0 )
goto error;
if ( * V_319 != V_321 ) {
V_2 -> V_126 |=
V_220 ;
V_35 = F_35 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
}
}
V_2 -> V_66 = * V_319 ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_51 ( struct V_1 * V_2 , bool V_328 )
{
enum V_318 V_329 = V_321 ;
T_4 V_330 = 0 ;
T_4 V_34 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_331 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( V_34 == V_332 ) {
V_35 = F_47 ( V_2 , V_333 | V_334 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_333 | V_335 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_25 ( V_2 , V_336 , V_337 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_338 , V_339 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_340 , V_341 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_49 ( V_2 , false ) ;
if ( V_35 < 0 )
goto error;
if ( V_328 ) {
V_35 = F_50 ( V_2 , & V_329 ) ;
if ( V_35 < 0 )
goto error;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_53 ( struct V_1 * V_2 ,
enum V_342 V_343 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_190 , V_191 ) ;
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_3 == V_343 )
return 0 ;
switch ( V_2 -> V_3 ) {
case V_157 :
break;
case V_4 :
V_35 = F_46 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_51 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_3 = V_157 ;
break;
case V_5 :
case V_7 :
V_35 = F_46 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_52 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_3 = V_157 ;
break;
case V_6 :
default:
V_35 = - V_201 ;
goto error;
}
switch ( V_343 ) {
case V_4 :
F_16 ( 1 , L_39 ) ;
V_2 -> V_3 = V_343 ;
V_35 = F_54 ( V_2 , V_343 ) ;
if ( V_35 < 0 )
goto error;
break;
case V_5 :
case V_7 :
F_16 ( 1 , L_40 ,
( V_2 -> V_3 == V_5 ) ? 'A' : 'C' ) ;
V_2 -> V_3 = V_343 ;
V_35 = F_55 ( V_2 , V_343 ) ;
if ( V_35 < 0 )
goto error;
break;
case V_6 :
default:
V_35 = - V_201 ;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_56 ( struct V_1 * V_2 , T_6 V_344 ,
T_6 V_345 )
{
int V_35 = - V_201 ;
T_4 V_346 ;
T_6 V_347 = V_344 / 1000 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 != V_348 &&
V_2 -> V_158 != V_349 )
goto error;
V_2 -> V_350 = ( V_2 -> V_351 . V_352 == V_353 ) ;
if ( V_345 < 0 ) {
V_2 -> V_350 = ! V_2 -> V_350 ;
V_345 = - V_345 ;
}
switch ( V_2 -> V_3 ) {
case V_5 :
case V_7 :
V_346 = ( V_345 / 1000 ) ;
V_35 = F_57 ( V_2 , V_346 , V_347 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_158 = V_349 ;
break;
case V_4 :
V_346 = ( V_345 / 1000 ) ;
V_35 = F_46 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_58 ( V_2 , V_346 , V_347 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_59 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_158 = V_349 ;
break;
default:
break;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_60 ( struct V_1 * V_2 )
{
F_16 ( 1 , L_3 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , T_1 * V_354 )
{
int V_35 = - V_201 ;
F_16 ( 1 , L_3 ) ;
if ( V_354 == NULL )
goto error;
* V_354 = V_355 ;
switch ( V_2 -> V_3 ) {
case V_5 :
case V_6 :
case V_7 :
V_35 = F_62 ( V_2 , V_354 ) ;
break;
case V_4 :
V_35 = F_63 ( V_2 , V_354 ) ;
break;
default:
break;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_35 ;
T_4 V_284 = 0 ;
V_35 = F_21 ( V_2 , V_286 , & V_284 ) ;
if ( V_35 < 0 )
goto error;
V_284 &= ~ V_287 ;
V_35 = F_25 ( V_2 , V_286 , V_284 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_356 , 1 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_357 , 0x0000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_358 , 0x000C ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_359 , 0x000A ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_360 , 0x0008 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_361 , 0x0006 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_362 , 0x0680 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_363 , 0x0080 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_364 , 0x03F4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_365 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_366 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_367 , 12 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_66 ( struct V_1 * V_2 ,
enum V_342 V_343 )
{
int V_35 ;
T_4 V_368 = 0 ;
T_4 V_369 = 0 ;
T_4 V_370 = 0 ;
T_4 V_371 = 0 ;
T_4 V_372 = 2 ;
T_4 V_373 = 188 ;
T_1 V_374 = 0 ;
T_4 V_375 = 0 ;
T_4 V_376 = 0 ;
T_1 V_377 = 0 ;
bool V_378 = false ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_379 , & V_368 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_288 , & V_369 ) ;
if ( V_35 < 0 )
goto error;
V_368 &= ( ~ V_380 ) ;
V_369 &= ( ~ V_381 ) ;
if ( V_2 -> V_161 == true ) {
V_368 |= V_380 ;
V_369 |= V_381 ;
V_373 = 204 ;
}
V_369 &= ( ~ ( V_382 ) ) ;
if ( V_2 -> V_238 == false ) {
V_369 |= V_382 ;
}
switch ( V_343 ) {
case V_4 :
V_377 = V_2 -> V_167 ;
V_375 = 3 ;
V_374 = 0xC00000 ;
V_378 = V_2 -> V_383 ;
break;
case V_5 :
case V_7 :
V_375 = 0x0004 ;
V_374 = 0xD2B4EE ;
V_377 = V_2 -> V_168 ;
V_378 = V_2 -> V_384 ;
break;
default:
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
if ( V_378 ) {
T_1 V_385 = 0 ;
V_370 = ( V_386 |
V_387 ) ;
V_371 = ( V_388 |
V_389 ) ;
V_385 = V_377 ;
if ( V_385 > 75900000UL ) {
V_385 = 75900000UL ;
}
V_372 = ( T_4 ) ( ( ( V_2 -> V_121 )
* 1000 ) / V_385 ) ;
if ( V_372 <= 2 )
V_372 = 0 ;
else
V_372 -= 2 ;
V_376 = 8 ;
} else {
V_370 = V_386 ;
V_371 = V_390 ;
V_376 = 5 ;
}
V_35 = F_25 ( V_2 , V_391 , V_373 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_392 , V_372 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_393 , V_370 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_394 , V_371 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_379 , V_368 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_288 , V_369 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_27 ( V_2 , V_395 , V_374 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_396 , V_376 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_397 , V_375 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_67 ( struct V_1 * V_2 )
{
T_4 V_398 = 0 ;
T_4 V_399 =
V_400 | V_401 |
V_402 | V_403 |
V_404 | V_405 |
V_406 | V_407 ;
F_16 ( 1 , L_3 ) ;
V_398 &= ( ~ ( V_399 ) ) ;
if ( V_2 -> V_162 == true )
V_398 |= V_399 ;
V_398 &= ( ~ ( V_408 ) ) ;
if ( V_2 -> V_163 == true )
V_398 |= V_408 ;
V_398 &= ( ~ ( V_409 ) ) ;
if ( V_2 -> V_164 == true )
V_398 |= V_409 ;
V_398 &= ( ~ ( V_410 ) ) ;
if ( V_2 -> V_165 == true )
V_398 |= V_410 ;
V_398 &= ( ~ ( V_411 ) ) ;
if ( V_2 -> V_166 == true )
V_398 |= V_411 ;
return F_25 ( V_2 , V_412 , V_398 ) ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_413 * V_414 , bool V_415 )
{
int V_35 = - V_201 ;
T_4 V_34 = 0 ;
struct V_413 * V_416 ;
F_16 ( 1 , L_3 ) ;
if ( V_414 == NULL )
goto error;
switch ( V_414 -> V_131 ) {
case V_69 :
V_35 = F_21 ( V_2 , V_312 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 &= ~ V_317 ;
V_35 = F_25 ( V_2 , V_312 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_417 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 &= ~ V_418 ;
if ( V_2 -> V_419 )
V_34 |= V_420 ;
else
V_34 &= ~ V_420 ;
V_35 = F_25 ( V_2 , V_417 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_421 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 &= ~ V_422 ;
V_34 |= ( ~ ( V_414 -> V_135 <<
V_423 )
& V_422 ) ;
V_35 = F_25 ( V_2 , V_421 , V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( F_1 ( V_2 ) )
V_416 = & V_2 -> V_149 ;
else if ( F_2 ( V_2 ) )
V_416 = & V_2 -> V_154 ;
else
V_416 = & V_2 -> V_145 ;
if ( V_416 == NULL ) {
V_35 = - V_201 ;
goto error;
}
if ( V_416 -> V_131 == V_69 )
V_35 = F_25 ( V_2 , V_424 , V_414 -> V_138 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_425 , V_414 -> V_139 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_426 , V_414 -> V_134 ) ;
if ( V_35 < 0 )
goto error;
break;
case V_427 :
V_35 = F_21 ( V_2 , V_312 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 &= ~ V_317 ;
V_35 = F_25 ( V_2 , V_312 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_417 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 |= V_418 ;
if ( V_2 -> V_419 )
V_34 |= V_420 ;
else
V_34 &= ~ V_420 ;
V_35 = F_25 ( V_2 , V_417 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_425 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_428 , V_414 -> V_132 ) ;
if ( V_35 < 0 )
goto error;
break;
case V_87 :
V_35 = F_21 ( V_2 , V_312 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 |= V_317 ;
V_35 = F_25 ( V_2 , V_312 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_417 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 |= V_418 ;
V_35 = F_25 ( V_2 , V_417 , V_34 ) ;
if ( V_35 < 0 )
goto error;
break;
default:
V_35 = - V_201 ;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_413 * V_414 , bool V_415 )
{
T_4 V_34 = 0 ;
int V_35 = 0 ;
struct V_413 * V_429 ;
F_16 ( 1 , L_3 ) ;
switch ( V_414 -> V_131 ) {
case V_69 :
V_35 = F_21 ( V_2 , V_312 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 &= ~ V_316 ;
V_35 = F_25 ( V_2 , V_312 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_417 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 &= ~ V_430 ;
if ( V_2 -> V_186 )
V_34 |= V_431 ;
else
V_34 &= ~ V_431 ;
V_35 = F_25 ( V_2 , V_417 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_421 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 &= ~ V_432 ;
V_34 |= ( ~ ( V_414 -> V_135 <<
V_433 )
& V_432 ) ;
V_35 = F_25 ( V_2 , V_421 , V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( F_2 ( V_2 ) )
V_429 = & V_2 -> V_153 ;
else
V_429 = & V_2 -> V_146 ;
if ( V_429 == NULL )
return - 1 ;
V_35 = F_25 ( V_2 , V_424 , V_429 -> V_138 ) ;
if ( V_35 < 0 )
goto error;
break;
case V_427 :
V_35 = F_21 ( V_2 , V_312 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 &= ~ V_316 ;
V_35 = F_25 ( V_2 , V_312 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_417 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 |= V_430 ;
if ( V_2 -> V_186 )
V_34 |= V_431 ;
else
V_34 &= ~ V_431 ;
V_35 = F_25 ( V_2 , V_417 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_424 , V_414 -> V_132 ) ;
if ( V_35 < 0 )
goto error;
break;
case V_87 :
V_35 = F_21 ( V_2 , V_312 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 |= V_316 ;
V_35 = F_25 ( V_2 , V_312 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_417 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 |= V_430 ;
V_35 = F_25 ( V_2 , V_417 , V_34 ) ;
if ( V_35 < 0 )
goto error;
break;
}
V_35 = F_25 ( V_2 , V_434 , V_414 -> V_138 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_70 ( struct V_1 * V_2 ,
T_6 * V_435 )
{
int V_35 = 0 ;
T_4 V_436 = 0 ;
T_1 V_437 = 0 ;
T_1 V_438 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_439 , & V_436 ) ;
if ( V_35 < 0 ) {
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return - V_201 ;
}
switch ( V_2 -> V_351 . V_440 ) {
case V_441 :
V_437 = V_442 << 2 ;
break;
case V_443 :
V_437 = V_444 << 2 ;
break;
case V_445 :
V_437 = V_446 << 2 ;
break;
case V_447 :
V_437 = V_448 << 2 ;
break;
default:
case V_449 :
V_437 = V_450 << 2 ;
break;
}
if ( V_436 > 0 ) {
V_438 = F_6 ( V_437 ) -
F_6 ( ( T_1 ) V_436 ) ;
}
* V_435 = V_438 ;
return V_35 ;
}
static int F_71 ( struct V_1 * V_2 ,
T_6 * V_435 )
{
int V_35 ;
T_4 V_451 = 0 ;
T_1 V_452 = 0 ;
T_1 V_453 = 0 ;
T_4 V_454 = 0 ;
T_4 V_455 = 0 ;
T_4 V_456 = 0 ;
T_1 V_457 = 0 ;
T_1 V_458 = 0 ;
T_1 V_8 = 0 ;
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
T_1 V_459 = 0 ;
T_4 V_460 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_461 , & V_455 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_462 , & V_456 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_463 , & V_454 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_464 , & V_451 ) ;
if ( V_35 < 0 )
goto error;
V_452 = ( T_1 ) V_451 ;
if ( ( V_454 > 11 ) &&
( V_452 < 0x00000FFFUL ) ) {
V_452 += 0x00010000UL ;
}
V_35 = F_21 ( V_2 , V_465 , & V_451 ) ;
if ( V_35 < 0 )
goto error;
V_453 = ( T_1 ) V_451 ;
if ( ( V_454 > 11 ) &&
( V_453 < 0x00000FFFUL ) )
V_453 += 0x00010000UL ;
V_35 = F_21 ( V_2 , V_466 , & V_460 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_455 == 0 ) || ( V_456 == 0 ) )
V_459 = 0 ;
else if ( ( V_452 + V_453 ) == 0 ) {
V_459 = 0 ;
} else {
V_458 = ( V_452 + V_453 ) <<
V_454 ;
if ( ( V_460 &
V_467 )
== V_468 )
V_457 = 17 ;
else
V_457 = 68 ;
V_8 = F_6 ( V_455 *
V_455 ) ;
V_9 = F_6 ( V_456 * V_457 ) ;
V_10 = F_6 ( V_458 ) ;
V_459 = V_8 + V_9 - V_10 ;
}
* V_435 = V_459 ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_72 ( struct V_1 * V_2 , T_6 * V_435 )
{
F_16 ( 1 , L_3 ) ;
* V_435 = 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
return F_71 ( V_2 , V_435 ) ;
case V_5 :
case V_7 :
return F_70 ( V_2 , V_435 ) ;
default:
break;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , bool V_469 )
{
int V_35 = - V_201 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_159 )
return 0 ;
if ( V_2 -> V_158 == V_470 )
goto error;
if ( V_2 -> V_471 )
return 0 ;
V_35 = F_25 ( V_2 , V_232 , V_233 ) ;
if ( V_35 < 0 )
goto error;
if ( V_469 ) {
V_35 = F_25 ( V_2 , V_231 , V_472 ) ;
if ( V_35 < 0 )
goto error;
} else {
V_35 = F_25 ( V_2 , V_231 , V_473 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_34 ( V_2 , V_474 , 0 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_475 * V_476 )
{
int V_35 = - V_201 ;
F_16 ( 1 , L_3 ) ;
if ( ( V_476 == NULL )
|| ( V_476 -> V_141 > V_477 ) )
goto error;
V_35 = F_25 ( V_2 , V_478 , V_476 -> V_141 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_75 ( struct V_1 * V_2 , T_1 V_479 ,
T_4 V_256 , T_4 V_257 , T_1 V_258 )
{
T_4 V_259 = 0 ;
T_4 V_273 = ( T_4 ) ( ( V_479 >> 0 ) & 0x00FFFF ) ;
T_4 V_480 = ( T_4 ) ( ( V_479 >> 16 ) & 0x000FFF ) ;
int V_35 ;
unsigned long V_260 ;
F_16 ( 1 , L_3 ) ;
F_36 ( & V_2 -> V_224 ) ;
V_35 = F_25 ( V_2 , V_261 , V_481 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_482 , V_480 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_483 , V_273 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_484 , V_256 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_485 , V_257 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_265 , V_266 ) ;
if ( V_35 < 0 )
goto error;
V_260 = V_267 + F_42 ( V_258 ) ;
do {
V_35 = F_21 ( V_2 , V_268 , & V_259 ) ;
if ( V_35 < 0 )
goto error;
} while ( ( V_259 == 0x1 ) && F_43 ( V_260 ) );
if ( V_259 == 0x1 ) {
F_17 ( V_40 L_28 ) ;
V_35 = - V_201 ;
goto V_208;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
V_208:
F_37 ( & V_2 -> V_224 ) ;
return V_35 ;
}
static int F_76 ( struct V_1 * V_2 , T_4 * V_486 )
{
T_4 V_34 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_487 , V_488 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_489 , 1 ) ;
if ( V_35 < 0 )
goto error;
* V_486 = 0 ;
V_35 = F_21 ( V_2 , V_490 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( V_34 == 127 )
* V_486 = * V_486 + 1 ;
V_35 = F_21 ( V_2 , V_491 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( V_34 == 127 )
* V_486 = * V_486 + 1 ;
V_35 = F_21 ( V_2 , V_492 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( V_34 == 127 )
* V_486 = * V_486 + 1 ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_77 ( struct V_1 * V_2 )
{
T_4 V_486 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_76 ( V_2 , & V_486 ) ;
if ( V_35 < 0 )
goto error;
if ( V_486 == 1 ) {
T_4 V_493 = 0 ;
V_35 = F_21 ( V_2 , V_494 , & V_493 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_493 & V_495 ) ==
V_496 ) {
V_493 &= ( ~ ( V_495 ) ) ;
V_493 |=
V_497 ;
} else {
V_493 &= ( ~ ( V_495 ) ) ;
V_493 |=
V_496 ;
}
V_35 = F_25 ( V_2 , V_494 , V_493 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_76 ( V_2 , & V_486 ) ;
if ( V_35 < 0 )
goto error;
}
if ( V_486 < 2 )
V_35 = - V_201 ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_78 ( struct V_1 * V_2 ,
T_4 V_498 ,
T_6 V_499 , bool V_415 )
{
bool V_500 = false ;
T_1 V_501 = V_499 ;
T_1 V_502 = 0 ;
bool V_503 = ! V_2 -> V_350 ;
T_1 V_504 ;
bool V_505 ;
int V_35 ;
T_1 V_506 ;
T_1 V_507 = ( T_1 ) ( V_2 -> V_121 / 3 ) ;
T_1 V_508 ;
bool V_509 ;
F_16 ( 1 , L_3 ) ;
if ( V_415 ) {
if ( ( V_2 -> V_3 == V_5 ) ||
( V_2 -> V_3 == V_7 ) ||
( V_2 -> V_3 == V_4 ) )
V_500 = true ;
else
V_500 = false ;
}
if ( V_503 )
V_506 = V_498 +
V_501 + V_502 ;
else
V_506 = V_498 -
V_501 - V_502 ;
if ( V_506 > V_507 / 2 ) {
V_504 = V_507 - V_506 ;
V_505 = true ;
} else {
V_504 = V_506 ;
V_505 = false ;
}
V_508 = V_504 ;
V_509 = V_2 -> V_185 ^ V_503 ^
V_505 ^ V_500 ;
V_2 -> V_510 =
F_5 ( ( V_508 ) , V_507 ) ;
if ( V_509 )
V_2 -> V_510 = ~ V_2 -> V_510 + 1 ;
V_35 = F_27 ( V_2 , V_511 ,
V_2 -> V_510 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_79 ( struct V_1 * V_2 , bool V_415 )
{
T_4 V_512 = 0 ;
T_4 V_513 = 0 ;
T_4 V_514 = 0 ;
T_4 V_515 = 0 ;
T_4 V_516 = 0 ;
T_4 V_517 = 0 ;
T_4 V_518 = 0 ;
T_4 V_519 = 0 ;
T_4 V_520 = 0 ;
T_4 V_521 = 0 ;
T_4 V_522 = 0 ;
T_4 V_523 = 0 ;
T_4 V_524 = 0 ;
T_4 V_525 = 0 ;
T_4 V_34 = 0 ;
T_4 V_526 = 0 ;
T_4 V_527 = 0 ;
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_519 = 1023 ;
V_524 = 2047 ;
V_515 = 500 ;
V_520 = 1023 ;
if ( ! F_2 ( V_2 ) ) {
F_17 ( V_40 L_41 , V_58 , V_2 -> V_3 ) ;
return - V_201 ;
}
V_516 = 8 ;
V_517 = ( T_4 ) - 9 ;
V_527 = 0 ;
V_518 = 8 ;
V_521 = ( T_4 ) - 9 ;
V_522 = ( T_4 ) - 1030 ;
V_525 = 0x2380 ;
V_523 = 0x2380 ;
V_513 = 0x0511 ;
V_512 = 0x0511 ;
V_514 = 5119 ;
V_526 = V_2 -> V_154 . V_150 ;
V_35 = F_25 ( V_2 , V_528 , V_526 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_529 , V_527 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_530 , V_512 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_434 , V_513 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_531 , V_514 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_532 , V_524 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_424 , V_525 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_533 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_534 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_428 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_535 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_536 , V_520 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_537 , V_519 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_538 , V_522 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_539 , V_523 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_540 , V_515 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_541 , 1023 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_542 , ( T_4 ) - 1023 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_543 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_544 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_545 , V_516 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_546 , V_518 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_547 , V_517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_548 , V_521 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_549 , 0x7fff ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_550 , 0x0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_551 , 0x0117 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_552 , 0x0657 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_553 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_554 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_555 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_556 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_557 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_558 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_559 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_560 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_561 , 500 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_562 , 500 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_563 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 = 0x0657 ;
V_34 &= ~ V_564 ;
V_34 |= ( V_565 << V_566 ) ;
V_34 &= ~ V_567 ;
V_34 |= ( V_568 << V_569 ) ;
V_35 = F_25 ( V_2 , V_563 , V_34 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_80 ( struct V_1 * V_2 , T_4 * V_570 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
if ( V_570 == NULL )
V_35 = F_25 ( V_2 , V_571 , 0 ) ;
else
V_35 = F_21 ( V_2 , V_571 , V_570 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_4 V_213 , T_4 V_572 ,
T_4 V_573 , T_4 V_574 , T_4 V_575 ,
T_4 V_576 , T_4 V_577 )
{
T_4 V_296 = 0 ;
T_4 V_578 = 0 ;
T_4 V_579 = 0 ;
T_4 V_580 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_336 , & V_580 ) ;
if ( V_580 != 1 ) {
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
V_579 = 0 ;
do {
F_30 ( 1 ) ;
V_35 = F_21 ( V_2 , V_581 , & V_296 ) ;
V_579 ++ ;
} while ( ( V_296 != 0 ) && ( V_579 < V_222 ) );
if ( V_579 >= V_222 && ( V_35 < 0 ) )
goto error;
switch ( V_213 ) {
case V_582 :
case V_583 :
case V_584 :
V_35 = F_25 ( V_2 , V_585 , V_572 ) ;
if ( V_35 < 0 )
goto error;
break;
default:
break;
}
switch ( V_213 ) {
case V_582 :
case V_583 :
case V_584 :
V_35 = F_25 ( V_2 , V_586 , V_574 ) ;
case V_587 :
case V_588 :
V_35 = F_25 ( V_2 , V_589 , V_573 ) ;
case V_590 :
case V_591 :
V_35 = F_25 ( V_2 , V_581 , V_213 ) ;
break;
default:
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
V_579 = 0 ;
do {
F_30 ( 1 ) ;
V_35 = F_21 ( V_2 , V_581 , & V_296 ) ;
V_579 ++ ;
} while ( ( V_296 != 0 ) && ( V_579 < V_222 ) );
if ( V_579 >= V_222 && ( V_35 < 0 ) )
goto error;
V_35 = F_21 ( V_2 , V_585 , & V_578 ) ;
if ( V_578 == 0xFFFF ) {
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
switch ( V_213 ) {
case V_588 :
case V_590 :
V_35 = F_21 ( V_2 , V_589 , & ( V_573 ) ) ;
case V_587 :
case V_592 :
case V_582 :
case V_583 :
case V_584 :
case V_591 :
break;
default:
V_35 = - V_201 ;
break;
}
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_82 ( struct V_1 * V_2 )
{
enum V_318 V_329 = V_67 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_50 ( V_2 , & V_329 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_83 ( struct V_1 * V_2 , bool * V_593 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
if ( * V_593 == true )
V_35 = F_25 ( V_2 , V_594 , 0 ) ;
else
V_35 = F_25 ( V_2 , V_594 , 1 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_84 ( struct V_1 * V_2 , bool * V_593 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
if ( * V_593 == true ) {
V_35 = F_25 ( V_2 , V_595 ,
V_596 ) ;
} else {
V_35 = F_25 ( V_2 , V_595 , 0 ) ;
}
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_597 * V_598 )
{
T_4 V_34 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_599 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_598 -> V_600 ) {
case V_601 :
V_34 &= ~ V_602 ;
V_34 |= ( ( V_598 -> V_603 <<
V_604 )
& ( V_602 ) ) ;
break;
case V_605 :
V_34 &= ~ V_606 ;
V_34 |= ( ( V_598 -> V_603 <<
V_607 )
& ( V_606 ) ) ;
break;
default:
return - V_201 ;
}
V_35 = F_25 ( V_2 , V_599 , V_34 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_86 ( struct V_1 * V_2 ,
enum V_608 * V_135 )
{
int V_35 = - V_201 ;
F_16 ( 1 , L_3 ) ;
switch ( * V_135 ) {
case V_609 :
case V_181 :
case V_610 :
break;
default:
goto error;
}
V_35 = F_25 ( V_2 , V_611 ,
( T_4 ) * V_135 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_35 ;
bool V_612 = false ;
bool V_613 = true ;
struct V_597 V_614 = { 0 , V_601 } ;
struct V_597 V_615 = { 0 , V_605 } ;
F_16 ( 1 , L_3 ) ;
V_35 = F_83 ( V_2 , & V_612 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_84 ( V_2 , & V_613 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_85 ( V_2 , & V_614 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_85 ( V_2 , & V_615 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_531 , V_2 -> V_149 . V_151 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_54 ( struct V_1 * V_2 ,
enum V_342 V_343 )
{
T_4 V_330 = 0 ;
T_4 V_34 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
F_82 ( V_2 ) ;
F_88 ( V_2 ) ;
V_35 = F_47 ( V_2 , V_333 | V_335 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_333 | V_616 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_336 , V_337 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_338 , V_339 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_340 , V_341 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_617 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_618 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_619 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_620 , V_621 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_49 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_622 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_623 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_624 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_625 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_626 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_627 , 0x4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_628 , 0x4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_629 , 1600 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_630 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_631 , 448 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_632 , 495 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_41 ( V_2 , V_633 , V_634 , V_635 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_636 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_637 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_638 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_340 , V_639 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_77 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_74 ( V_2 , & V_2 -> V_152 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_640 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_68 ( V_2 , & V_2 -> V_148 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_69 ( V_2 , & V_2 -> V_149 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_641 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 |= V_642 ;
V_35 = F_25 ( V_2 , V_641 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_332 ) ;
if ( V_35 < 0 )
goto error;
if ( ! V_2 -> V_643 ) {
V_35 = F_25 ( V_2 , V_528 , V_2 -> V_149 . V_150 ) ;
if ( V_35 < 0 )
goto error;
}
#ifdef F_89
V_35 = F_25 ( V_2 , V_644 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_645 , 2 ) ;
if ( V_35 < 0 )
goto error;
#endif
V_35 = F_25 ( V_2 , V_646 , 1 ) ;
if ( V_35 < 0 )
goto error;
#ifdef F_89
V_35 = F_25 ( V_2 , V_647 , 0x400 ) ;
if ( V_35 < 0 )
goto error;
#else
V_35 = F_25 ( V_2 , V_647 , 0x1000 ) ;
if ( V_35 < 0 )
goto error;
#endif
V_35 = F_25 ( V_2 , V_648 , 0x0001 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_66 ( V_2 , V_4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_87 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_59 ( struct V_1 * V_2 )
{
T_4 V_574 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_574 = V_649 ;
V_35 = F_81 ( V_2 , V_582 , 0 , V_650 , V_574 , 0 , 0 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_64 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_651 , V_652 ) ;
if ( V_35 < 0 )
goto error;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_58 ( struct V_1 * V_2 , T_4 V_653 ,
T_6 V_499 )
{
T_4 V_330 = 0 ;
T_4 V_460 = 0 ;
T_4 V_654 = 0 ;
T_1 V_655 = 0 ;
T_1 V_656 = 0 ;
T_4 V_574 ;
int V_35 ;
F_16 ( 1 , L_42 , V_653 , V_499 ) ;
V_35 = F_47 ( V_2 , V_333 | V_334 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_640 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_336 , V_337 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_338 , V_339 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_657 , V_658 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_2 -> V_351 . V_659 ) {
case V_660 :
default:
V_654 |= V_661 ;
case V_662 :
V_460 |= V_663 ;
break;
case V_664 :
V_460 |= V_468 ;
break;
}
switch ( V_2 -> V_351 . V_665 ) {
default:
case V_666 :
V_654 |= V_667 ;
case V_668 :
V_460 |= V_669 ;
break;
case V_670 :
V_460 |= V_671 ;
break;
case V_672 :
V_460 |= V_673 ;
break;
case V_674 :
V_460 |= V_675 ;
break;
}
switch ( V_2 -> V_351 . V_676 ) {
case V_677 :
case V_678 :
default:
V_654 |= V_679 ;
case V_680 :
V_460 |= V_681 ;
break;
case V_682 :
V_460 |= V_683 ;
break;
case V_684 :
V_460 |= V_685 ;
break;
}
switch ( V_2 -> V_351 . V_440 ) {
case V_686 :
default:
V_654 |= V_687 ;
case V_445 :
V_460 |= V_688 ;
break;
case V_689 :
V_460 |= V_690 ;
break;
case V_441 :
V_460 |= V_691 ;
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
V_460 |= V_692 ;
V_35 = F_25 ( V_2 , V_693 , V_694 ) ;
if ( V_35 < 0 )
goto error;
#endif
switch ( V_2 -> V_351 . V_695 ) {
case V_696 :
default:
V_654 |= V_697 ;
case V_698 :
V_460 |= V_699 ;
break;
case V_700 :
V_460 |= V_701 ;
break;
case V_702 :
V_460 |= V_703 ;
break;
case V_704 :
V_460 |= V_705 ;
break;
case V_706 :
V_460 |= V_707 ;
break;
}
switch ( V_2 -> V_351 . V_708 ) {
case 0 :
V_2 -> V_351 . V_708 = 8000000 ;
case 8000000 :
V_656 = V_709 ;
V_35 = F_25 ( V_2 , V_710 , 3052 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_711 , 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_712 , 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_713 , 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_714 , 1 ) ;
if ( V_35 < 0 )
goto error;
break;
case 7000000 :
V_656 = V_715 ;
V_35 = F_25 ( V_2 , V_710 , 3491 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_711 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_712 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_713 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_714 , 1 ) ;
if ( V_35 < 0 )
goto error;
break;
case 6000000 :
V_656 = V_716 ;
V_35 = F_25 ( V_2 , V_710 , 4073 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_711 , 19 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_712 , 19 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_713 , 14 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_714 , 1 ) ;
if ( V_35 < 0 )
goto error;
break;
default:
V_35 = - V_201 ;
goto error;
}
if ( V_655 == 0 ) {
V_655 = F_5 ( ( T_1 )
( ( V_2 -> V_121 *
1000 ) / 3 ) , V_656 ) ;
if ( ( V_655 & 0x7fL ) >= 0x40 )
V_655 += 0x80L ;
V_655 = V_655 >> 7 ;
V_655 = V_655 - ( 1 << 23 ) ;
}
V_655 &=
( ( ( ( T_1 ) V_717 ) <<
V_718 ) | V_719 ) ;
V_35 = F_27 ( V_2 , V_720 , V_655 ) ;
if ( V_35 < 0 )
goto error;
#if 0
status = DVBTSetFrequencyShift(demod, channel, tunerOffset);
if (status < 0)
goto error;
#endif
V_35 = F_78 ( V_2 , V_653 , V_499 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_332 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_721 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_336 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_333 | V_722 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_574 = ( V_661 |
V_667 |
V_687 |
V_679 |
V_697 ) ;
V_35 = F_81 ( V_2 , V_583 ,
0 , V_460 , V_574 , 0 , 0 , 0 ) ;
if ( V_35 < 0 )
goto error;
if ( ! V_2 -> V_643 )
V_35 = F_86 ( V_2 , & V_2 -> V_180 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_63 ( struct V_1 * V_2 , T_1 * V_354 )
{
int V_35 ;
const T_4 V_723 = ( V_724 |
V_725 ) ;
const T_4 V_726 = ( V_725 ) ;
const T_4 V_727 = V_728 ;
T_4 V_729 = 0 ;
T_4 V_730 = 0 ;
F_16 ( 1 , L_3 ) ;
* V_354 = V_355 ;
V_35 = F_21 ( V_2 , V_336 , & V_730 ) ;
if ( V_35 < 0 )
goto V_260;
if ( V_730 == V_337 )
goto V_260;
V_35 = F_21 ( V_2 , V_731 , & V_729 ) ;
if ( V_35 < 0 )
goto V_260;
if ( ( V_729 & V_723 ) == V_723 )
* V_354 = V_732 ;
else if ( ( V_729 & V_726 ) == V_726 )
* V_354 = V_733 ;
else if ( ( V_729 & V_727 ) == V_727 )
* V_354 = V_734 ;
else if ( V_729 & V_735 )
* V_354 = V_736 ;
V_260:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_90 ( struct V_1 * V_2 )
{
enum V_318 V_329 = V_321 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_50 ( V_2 , & V_329 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_4 V_34 = 0 ;
T_4 V_330 ;
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_331 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( V_34 == V_332 ) {
V_35 = F_25 ( V_2 , V_737 , V_738 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_739 | V_334 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_49 ( V_2 , false ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_91 ( struct V_1 * V_2 ,
enum V_740 V_440 ,
T_1 V_741 )
{
T_1 V_742 = 0 ;
T_1 V_743 = 0 ;
T_4 V_744 = 0 ;
T_4 V_745 = 0 ;
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_744 = 1 ;
switch ( V_440 ) {
case V_746 :
V_742 = 4 * V_741 ;
break;
case V_747 :
V_742 = 5 * V_741 ;
break;
case V_748 :
V_742 = 6 * V_741 ;
break;
case V_749 :
V_742 = 7 * V_741 ;
break;
case V_750 :
V_742 = 8 * V_741 ;
break;
default:
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
V_742 /= 1000 ;
V_742 *= 500 ;
V_743 = ( V_742 / 1632UL ) + 1 ;
V_744 = 1 + ( T_4 ) ( V_743 >> 16 ) ;
if ( V_744 == 0 ) {
V_35 = - V_201 ;
if ( V_35 < 0 )
goto error;
}
V_745 =
( ( T_4 ) V_743 +
( V_744 >> 1 ) ) / V_744 ;
V_35 = F_25 ( V_2 , V_647 , V_745 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_648 , V_744 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_751 , V_745 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_752 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_753 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_754 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_755 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_756 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_757 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , V_442 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 32 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 140 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 95 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 120 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 230 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 105 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , ( T_4 ) 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , ( T_4 ) 220 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , ( T_4 ) 25 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , ( T_4 ) 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , ( T_4 ) - 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) - 65 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) - 127 ) ;
if ( V_35 < 0 )
goto error;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_752 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_753 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_754 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_755 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_756 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_757 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , V_444 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 90 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 170 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , ( T_4 ) 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , ( T_4 ) 140 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , ( T_4 ) - 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , ( T_4 ) - 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , ( T_4 ) - 26 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) - 56 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) - 86 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_752 , 13336 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_753 , 12618 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_754 , 11988 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_755 , 13809 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_756 , 13809 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_757 , 15609 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , V_446 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 30 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 30 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 25 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 48 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 60 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 110 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 200 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 95 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , ( T_4 ) 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , ( T_4 ) 141 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , ( T_4 ) 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , ( T_4 ) 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , ( T_4 ) - 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) - 45 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) - 80 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_752 , 6564 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_753 , 6598 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_754 , 6394 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_755 , 6409 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_756 , 6656 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_757 , 7238 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , V_448 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 120 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 60 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 25 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 64 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 60 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 140 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , ( T_4 ) 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , ( T_4 ) 65 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , ( T_4 ) 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , ( T_4 ) 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , ( T_4 ) - 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) - 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) - 23 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_752 , 11502 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_753 , 12084 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_754 , 12543 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_755 , 12931 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_756 , 13629 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_757 , 15385 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , V_450 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 250 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 125 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 25 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 48 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 60 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 150 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 110 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , ( T_4 ) 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , ( T_4 ) 74 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , ( T_4 ) 18 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , ( T_4 ) 13 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , ( T_4 ) 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) - 8 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_35 ;
T_4 V_330 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_737 , V_738 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_739 | V_335 , 0 , NULL , 1 , & V_330 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_98 ( struct V_1 * V_2 )
{
T_1 V_804 = 0 ;
T_1 V_805 = 0 ;
T_1 V_806 = 0 ;
T_4 V_807 = 0 ;
T_1 V_808 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_804 = ( V_2 -> V_121 * 1000 ) / 3 ;
V_807 = 0 ;
if ( V_2 -> V_351 . V_809 <= 1188750 )
V_807 = 3 ;
else if ( V_2 -> V_351 . V_809 <= 2377500 )
V_807 = 2 ;
else if ( V_2 -> V_351 . V_809 <= 4755000 )
V_807 = 1 ;
V_35 = F_25 ( V_2 , V_810 , V_807 ) ;
if ( V_35 < 0 )
goto error;
V_805 = V_2 -> V_351 . V_809 * ( 1 << V_807 ) ;
if ( V_805 == 0 ) {
V_35 = - V_201 ;
goto error;
}
V_806 = ( V_804 / V_805 ) * ( 1 << 21 ) +
( F_5 ( ( V_804 % V_805 ) , V_805 ) >> 7 ) -
( 1 << 23 ) ;
V_35 = F_27 ( V_2 , V_720 , V_806 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_811 = V_806 ;
V_805 = V_2 -> V_351 . V_809 ;
if ( V_804 == 0 ) {
V_35 = - V_201 ;
goto error;
}
V_808 = ( V_805 / V_804 ) * ( 1 << 12 ) +
( F_5 ( ( V_805 % V_804 ) , V_804 ) >>
16 ) ;
if ( V_808 > 511 )
V_808 = 511 ;
V_35 = F_25 ( V_2 , V_812 , ( T_4 ) V_808 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_62 ( struct V_1 * V_2 , T_1 * V_354 )
{
int V_35 ;
T_4 V_813 [ 2 ] = { 0 , 0 } ;
F_16 ( 1 , L_3 ) ;
* V_354 = V_355 ;
V_35 = F_47 ( V_2 ,
V_739 |
V_814 , 0 , NULL , 2 ,
V_813 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
if ( V_813 [ 1 ] < V_815 ) {
} else if ( V_813 [ 1 ] < V_816 ) {
* V_354 = V_734 ;
} else if ( V_813 [ 1 ] < V_817 ) {
* V_354 = V_732 ;
} else {
* V_354 = V_736 ;
}
return V_35 ;
}
static int F_99 ( struct V_1 * V_2 ,
int V_818 )
{
int V_35 ;
T_4 V_330 ;
T_4 V_819 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_819 [ 0 ] = V_2 -> V_174 ;
V_819 [ 1 ] = V_177 ;
if ( V_818 == 2 ) {
T_4 V_820 [ 1 ] = { 0 } ;
if ( V_2 -> V_3 == V_7 )
V_820 [ 0 ] = V_821 ;
else
V_820 [ 0 ] = V_822 ;
V_35 = F_47 ( V_2 ,
V_739 | V_616 ,
1 , V_820 , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 ,
V_739 | V_823 ,
V_818 , V_819 ,
1 , & V_330 ) ;
} else if ( V_818 == 4 ) {
if ( V_2 -> V_3 == V_7 )
V_819 [ 2 ] = V_821 ;
else
V_819 [ 2 ] = V_822 ;
V_819 [ 3 ] |= ( V_824 ) ;
V_35 = F_47 ( V_2 ,
V_739 | V_823 ,
V_818 , V_819 ,
1 , & V_330 ) ;
} else {
F_17 ( V_825 L_43
L_44 , V_818 ) ;
V_35 = - V_201 ;
}
error:
if ( V_35 < 0 )
F_17 ( V_825 L_45 ,
V_35 , V_58 ) ;
return V_35 ;
}
static int F_57 ( struct V_1 * V_2 , T_4 V_653 ,
T_6 V_499 )
{
int V_35 ;
T_4 V_330 ;
int V_826 = V_2 -> V_827 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_828 , V_829 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_830 , V_831 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_97 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_98 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_2 -> V_351 . V_440 ) {
case V_449 :
V_2 -> V_174 = V_750 ;
break;
case V_686 :
case V_445 :
V_2 -> V_174 = V_748 ;
break;
case V_441 :
V_2 -> V_174 = V_746 ;
break;
case V_443 :
V_2 -> V_174 = V_747 ;
break;
case V_447 :
V_2 -> V_174 = V_749 ;
break;
default:
V_35 = - V_201 ;
break;
}
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_827 == 4
|| ! V_2 -> V_827 ) {
V_826 = 4 ;
V_35 = F_99 ( V_2 , V_826 ) ;
}
if ( V_2 -> V_827 == 2
|| ( ! V_2 -> V_827 && V_35 < 0 ) ) {
V_826 = 2 ;
V_35 = F_99 ( V_2 , V_826 ) ;
}
if ( V_35 < 0 ) {
F_16 ( 1 , L_46
L_47
L_48 ,
V_2 -> V_827 ,
V_2 -> V_832 ) ;
goto error;
} else if ( ! V_2 -> V_827 ) {
F_16 ( 1 , L_49
L_50 ,
V_826 ) ;
V_2 -> V_827 = V_826 ;
}
#if 0
status = SetFrequency(channel, tunerFreqOffset));
if (status < 0)
goto error;
#endif
V_35 = F_78 ( V_2 , V_653 , V_499 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_91 ( V_2 , V_2 -> V_174 , V_2 -> V_351 . V_809 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_630 , V_833 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_834 , V_835 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_836 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_837 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_838 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_839 , 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_840 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_841 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_842 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_843 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_844 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_845 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_846 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_847 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_848 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_849 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_850 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_851 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_852 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_853 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_854 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_855 , V_856 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_640 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_2 -> V_351 . V_440 ) {
case V_441 :
V_35 = F_92 ( V_2 ) ;
break;
case V_443 :
V_35 = F_93 ( V_2 ) ;
break;
case V_686 :
case V_445 :
V_35 = F_94 ( V_2 ) ;
break;
case V_447 :
V_35 = F_95 ( V_2 ) ;
break;
case V_449 :
V_35 = F_96 ( V_2 ) ;
break;
default:
V_35 = - V_201 ;
break;
}
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_332 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_66 ( V_2 , V_2 -> V_3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_64 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_651 , V_652 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_737 , V_857 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_340 , V_639 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_739 | V_722 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_55 ( struct V_1 * V_2 ,
enum V_342 V_343 )
{
int V_35 ;
#ifdef F_100
#define F_101
#include "drxk_filters.h"
#undef F_101
#endif
F_16 ( 1 , L_3 ) ;
F_102 ( V_2 ) ;
V_35 = F_90 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_97 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_340 , V_341 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_620 , V_621 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_343 ) {
case V_5 :
V_35 = F_41 ( V_2 , V_858 , V_634 , V_635 ) ;
break;
case V_7 :
V_35 = F_75 ( V_2 , V_859 , V_860 , V_861 , V_635 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_75 ( V_2 , V_862 , V_860 , V_861 , V_635 ) ;
break;
default:
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_627 , ( 1 << V_863 ) ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_864 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_865 , ( ( 1 << V_866 ) | ( 1 << V_867 ) ) ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_626 , 21 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_618 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_631 , 448 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_619 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_637 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_868 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_869 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_870 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_617 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_871 , 500 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_632 , 1000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_594 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_624 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_625 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_636 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_872 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_49 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_489 , 0x01 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_77 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_873 , 2000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_640 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_79 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_74 ( V_2 , & ( V_2 -> V_156 ) ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_68 ( V_2 , & ( V_2 -> V_153 ) , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_69 ( V_2 , & ( V_2 -> V_154 ) , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_332 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_35 ;
T_4 V_874 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_190 , V_191 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_192 , V_193 ) ;
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_209 ) {
if ( V_2 -> V_875 & 0x0001 ) {
V_35 = F_25 ( V_2 , V_876 , V_2 -> V_183 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_877 , & V_874 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_2 -> V_878 & 0x0001 ) == 0 )
V_874 &= 0x7FFF ;
else
V_874 |= 0x8000 ;
V_35 = F_25 ( V_2 , V_877 , V_874 ) ;
if ( V_35 < 0 )
goto error;
}
if ( V_2 -> V_875 & 0x0002 ) {
V_35 = F_25 ( V_2 , V_879 , V_2 -> V_183 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_877 , & V_874 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_2 -> V_878 & 0x0002 ) == 0 )
V_874 &= 0xBFFF ;
else
V_874 |= 0x4000 ;
V_35 = F_25 ( V_2 , V_877 , V_874 ) ;
if ( V_35 < 0 )
goto error;
}
if ( V_2 -> V_875 & 0x0004 ) {
V_35 = F_25 ( V_2 , V_880 , V_2 -> V_183 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_877 , & V_874 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_2 -> V_878 & 0x0004 ) == 0 )
V_874 &= 0xFFFB ;
else
V_874 |= 0x0004 ;
V_35 = F_25 ( V_2 , V_877 , V_874 ) ;
if ( V_35 < 0 )
goto error;
}
}
V_35 = F_25 ( V_2 , V_192 , 0x0000 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
bool V_881 ;
F_16 ( 1 , L_3 ) ;
if ( ! V_2 -> V_882 )
return 0 ;
V_881 = V_2 -> V_878 & V_2 -> V_882 ;
if ( V_2 -> V_883 ^ V_881 ) {
if ( V_2 -> V_883 )
V_2 -> V_878 &= ~ V_2 -> V_882 ;
else
V_2 -> V_878 |= V_2 -> V_882 ;
V_35 = F_103 ( V_2 ) ;
}
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
bool V_881 ;
F_16 ( 1 , L_3 ) ;
if ( ! V_2 -> V_882 )
return 0 ;
V_881 = V_2 -> V_878 & V_2 -> V_882 ;
if ( ! ( V_2 -> V_883 ^ V_881 ) ) {
if ( V_2 -> V_883 )
V_2 -> V_878 |= V_2 -> V_882 ;
else
V_2 -> V_878 &= ~ V_2 -> V_882 ;
V_35 = F_103 ( V_2 ) ;
}
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_120 ) {
V_35 = F_73 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_45 ( V_2 , false ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_61 , V_324 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_63 , V_64 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_126 |= V_220 ;
V_35 = F_35 ( V_2 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_35 = 0 , V_884 = 0 ;
enum V_318 V_329 = V_321 ;
T_4 V_885 ;
F_16 ( 1 , L_3 ) ;
if ( ( V_2 -> V_158 == V_159 ) ) {
F_7 ( V_2 ) ;
V_35 = F_29 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_32 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_886 , V_887 | V_888 | V_889 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_63 , V_64 ) ;
if ( V_35 < 0 )
goto error;
F_30 ( 1 ) ;
V_2 -> V_129 = true ;
V_35 = F_33 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_230 =
( T_4 ) ( ( V_2 -> V_118 / 1000 ) *
V_890 ) / 1000 ;
if ( V_2 -> V_230 >
V_891 ) {
V_2 -> V_230 =
V_891 ;
}
V_2 -> V_230 +=
V_2 -> V_230 <<
V_892 ;
V_35 = F_38 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
#if V_893
if ( ! ( V_2 -> V_894 )
&& ! ( V_2 -> V_895 ) )
#endif
{
V_35 = F_25 ( V_2 , V_190 , V_191 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_40 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_896 , V_897 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_898 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_282 , V_276 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_899 , V_900 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_41 ( V_2 , 0 , 6 , 100 ) ;
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_901 ) {
V_35 = F_44 ( V_2 , V_2 -> V_901 -> V_34 ,
V_2 -> V_901 -> V_902 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_25 ( V_2 , V_282 , V_279 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_332 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_32 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
F_30 ( 30 ) ;
V_329 = V_321 ;
V_35 = F_50 ( V_2 , & V_329 ) ;
if ( V_35 < 0 )
goto error;
V_885 =
( ( ( V_903 / 100 ) % 10 ) << 12 ) +
( ( ( V_903 / 10 ) % 10 ) << 8 ) +
( ( V_903 % 10 ) << 4 ) +
( V_904 % 10 ) ;
V_35 = F_25 ( V_2 , V_905 , V_885 ) ;
if ( V_35 < 0 )
goto error;
V_885 =
( ( ( V_906 / 1000 ) % 10 ) << 12 ) +
( ( ( V_906 / 100 ) % 10 ) << 8 ) +
( ( ( V_906 / 10 ) % 10 ) << 4 ) +
( V_906 % 10 ) ;
V_35 = F_25 ( V_2 , V_907 , V_885 ) ;
if ( V_35 < 0 )
goto error;
F_17 ( V_202 L_51 ,
V_903 , V_904 ,
V_906 ) ;
V_35 = F_25 ( V_2 , V_908 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_651 , V_909 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_65 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_46 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_67 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_39 ( V_2 , V_2 -> V_160 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_103 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_158 = V_348 ;
if ( V_2 -> V_128 ) {
V_35 = F_104 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_158 = V_470 ;
} else
V_2 -> V_158 = V_348 ;
V_884 = 0 ;
if ( V_2 -> V_114 ) {
V_2 -> V_910 . V_911 . V_912 [ V_884 ++ ] = V_913 ;
V_2 -> V_910 . V_911 . V_912 [ V_884 ++ ] = V_914 ;
F_106 ( V_2 -> V_910 . V_911 . V_915 . V_916 , L_52 ,
sizeof( V_2 -> V_910 . V_911 . V_915 . V_916 ) ) ;
}
if ( V_2 -> V_113 ) {
V_2 -> V_910 . V_911 . V_912 [ V_884 ++ ] = V_917 ;
F_106 ( V_2 -> V_910 . V_911 . V_915 . V_916 , L_53 ,
sizeof( V_2 -> V_910 . V_911 . V_915 . V_916 ) ) ;
}
F_9 ( V_2 ) ;
}
error:
if ( V_35 < 0 ) {
V_2 -> V_158 = V_918 ;
F_9 ( V_2 ) ;
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
}
return V_35 ;
}
static void F_107 ( const struct V_919 * V_901 ,
void * V_920 )
{
struct V_1 * V_2 = V_920 ;
F_16 ( 1 , L_54 , V_901 ? L_55 : L_56 ) ;
if ( ! V_901 ) {
F_17 ( V_40
L_57 ,
V_2 -> V_832 ) ;
F_17 ( V_202
L_58 ,
V_2 -> V_832 ) ;
V_2 -> V_832 = NULL ;
}
V_2 -> V_901 = V_901 ;
F_105 ( V_2 ) ;
}
static void F_108 ( struct V_921 * V_922 )
{
struct V_1 * V_2 = V_922 -> V_923 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_901 )
F_109 ( V_2 -> V_901 ) ;
F_110 ( V_2 ) ;
}
static int F_111 ( struct V_921 * V_922 )
{
struct V_1 * V_2 = V_922 -> V_923 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_918 )
return - V_924 ;
if ( V_2 -> V_158 == V_159 )
return 0 ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_112 ( struct V_921 * V_922 , int V_274 )
{
struct V_1 * V_2 = V_922 -> V_923 ;
F_16 ( 1 , L_54 , V_274 ? L_24 : L_25 ) ;
if ( V_2 -> V_158 == V_918 )
return - V_924 ;
return F_73 ( V_2 , V_274 ? true : false ) ;
}
static int F_113 ( struct V_921 * V_922 )
{
struct V_925 * V_300 = & V_922 -> V_926 ;
T_1 V_912 = V_300 -> V_927 , V_928 ;
struct V_1 * V_2 = V_922 -> V_923 ;
T_1 IF ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_918 )
return - V_924 ;
if ( V_2 -> V_158 == V_159 )
return - V_929 ;
if ( ! V_922 -> V_911 . V_930 . V_931 ) {
F_17 ( V_40
L_59 ) ;
return - V_201 ;
}
if ( V_922 -> V_911 . V_932 )
V_922 -> V_911 . V_932 ( V_922 , 1 ) ;
if ( V_922 -> V_911 . V_930 . V_933 )
V_922 -> V_911 . V_930 . V_933 ( V_922 ) ;
if ( V_922 -> V_911 . V_932 )
V_922 -> V_911 . V_932 ( V_922 , 0 ) ;
V_928 = V_2 -> V_351 . V_927 ;
V_2 -> V_351 = * V_300 ;
if ( V_928 != V_912 ) {
F_60 ( V_2 ) ;
switch ( V_912 ) {
case V_913 :
case V_914 :
if ( ! V_2 -> V_114 )
return - V_201 ;
V_2 -> V_934 = ( V_912 == V_914 ) ? true : false ;
if ( V_2 -> V_934 )
F_53 ( V_2 , V_7 ) ;
else
F_53 ( V_2 , V_5 ) ;
break;
case V_917 :
if ( ! V_2 -> V_113 )
return - V_201 ;
F_53 ( V_2 , V_4 ) ;
break;
default:
return - V_201 ;
}
}
V_922 -> V_911 . V_930 . V_931 ( V_922 , & IF ) ;
F_56 ( V_2 , 0 , IF ) ;
V_300 -> V_935 . V_936 [ 0 ] . V_16 = V_937 ;
V_300 -> V_938 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_940 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_941 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_942 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_943 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_944 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_945 . V_936 [ 0 ] . V_16 = V_939 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , T_2 * V_935 )
{
int V_35 ;
struct V_413 V_946 , V_947 ;
T_1 V_948 = 0 ;
T_1 V_949 = 0 ;
T_1 V_950 = 0 ;
T_4 V_951 = 0 ;
T_4 V_952 = 0 ;
T_4 V_953 = 50 ;
T_4 V_954 = 40 ;
* V_935 = 0 ;
if ( F_1 ( V_2 ) ) {
V_946 = V_2 -> V_148 ;
V_947 = V_2 -> V_149 ;
} else if ( F_2 ( V_2 ) ) {
V_946 = V_2 -> V_153 ;
V_947 = V_2 -> V_154 ;
} else {
V_946 = V_2 -> V_146 ;
V_947 = V_2 -> V_145 ;
}
if ( V_946 . V_131 == V_69 ) {
V_35 = F_21 ( V_2 , V_428 , & V_951 ) ;
if ( V_35 < 0 )
return V_35 ;
F_21 ( V_2 , V_425 , & V_952 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( ( ( T_1 ) V_951 + ( T_1 ) V_952 ) < 0xffff )
V_946 . V_132 = V_951 + V_952 ;
else
V_946 . V_132 = 0xffff ;
V_948 += V_953 ;
if ( V_946 . V_132 < V_946 . V_133 )
V_946 . V_132 = V_946 . V_133 ;
if ( V_946 . V_132 > V_946 . V_134 )
V_946 . V_132 = V_946 . V_134 ;
V_950 = ( T_1 ) ( V_946 . V_134 - V_946 . V_133 ) ;
if ( V_950 > 0 ) {
V_949 += 100UL *
( ( T_1 ) ( V_953 ) ) *
( ( T_1 ) ( V_946 . V_132 - V_946 . V_133 ) )
/ V_950 ;
}
}
if ( V_947 . V_131 == V_69 ) {
V_35 = F_21 ( V_2 , V_533 ,
& V_947 . V_132 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_21 ( V_2 , V_434 ,
& V_947 . V_138 ) ;
if ( V_35 < 0 )
return V_35 ;
V_948 += ( T_1 ) V_954 ;
if ( V_947 . V_132 < V_947 . V_133 )
V_947 . V_132 = V_947 . V_133 ;
if ( V_947 . V_132 > V_947 . V_134 )
V_947 . V_132 = V_947 . V_134 ;
V_950 = ( T_1 ) ( V_947 . V_134 - V_947 . V_133 ) ;
if ( V_950 > 0 ) {
V_949 += 100UL *
( ( T_1 ) ( V_954 ) ) *
( ( T_1 ) ( V_947 . V_132 - V_947 . V_133 ) )
/ V_950 ;
}
}
if ( V_948 > 0 )
* V_935 = ( 65535UL * V_949 / V_948 / 100 ) ;
else
* V_935 = 65535 ;
return 0 ;
}
static int F_115 ( struct V_921 * V_922 )
{
struct V_925 * V_10 = & V_922 -> V_926 ;
struct V_1 * V_2 = V_922 -> V_923 ;
int V_35 ;
T_1 V_936 ;
T_4 V_955 ;
T_1 V_945 ;
T_1 V_956 ;
T_1 V_957 ;
T_1 V_958 ;
T_1 V_943 ;
T_1 V_959 ;
T_1 V_960 ;
T_6 V_938 ;
if ( V_2 -> V_158 == V_918 )
return - V_924 ;
if ( V_2 -> V_158 == V_159 )
return - V_929 ;
V_2 -> V_961 = 0 ;
F_61 ( V_2 , & V_936 ) ;
if ( V_936 == V_732 )
V_2 -> V_961 |= 0x1f ;
if ( V_936 == V_733 )
V_2 -> V_961 |= 0x0f ;
if ( V_936 == V_734 )
V_2 -> V_961 |= 0x07 ;
F_114 ( V_2 , & V_10 -> V_935 . V_936 [ 0 ] . V_962 ) ;
V_10 -> V_935 . V_936 [ 0 ] . V_16 = V_937 ;
if ( V_936 >= V_734 ) {
F_72 ( V_2 , & V_938 ) ;
V_10 -> V_938 . V_936 [ 0 ] . V_963 = V_938 * 100 ;
V_10 -> V_938 . V_936 [ 0 ] . V_16 = V_964 ;
} else {
V_10 -> V_938 . V_936 [ 0 ] . V_16 = V_939 ;
}
if ( V_936 < V_733 ) {
V_10 -> V_940 . V_936 [ 0 ] . V_16 = V_939 ;
V_10 -> V_941 . V_936 [ 0 ] . V_16 = V_939 ;
V_10 -> V_942 . V_936 [ 0 ] . V_16 = V_939 ;
V_10 -> V_943 . V_936 [ 0 ] . V_16 = V_939 ;
V_10 -> V_944 . V_936 [ 0 ] . V_16 = V_939 ;
V_10 -> V_945 . V_936 [ 0 ] . V_16 = V_939 ;
return 0 ;
}
V_35 = F_21 ( V_2 , V_965 , & V_955 ) ;
if ( V_35 < 0 )
goto error;
V_958 = V_955 ;
V_35 = F_21 ( V_2 , V_966 , & V_955 ) ;
if ( V_35 < 0 )
goto error;
V_943 = V_955 ;
V_35 = F_21 ( V_2 , V_967 , & V_955 ) ;
if ( V_35 < 0 )
goto error;
V_956 = V_955 ;
V_35 = F_21 ( V_2 , V_648 , & V_955 ) ;
if ( V_35 < 0 )
goto error;
V_957 = V_955 ;
V_35 = F_21 ( V_2 , V_647 , & V_955 ) ;
if ( V_35 < 0 )
goto error;
V_959 = V_955 ;
V_35 = F_21 ( V_2 , V_571 , & V_955 ) ;
if ( V_35 < 0 )
goto error;
V_960 = V_955 ;
F_25 ( V_2 , V_571 , 0 ) ;
V_956 *= V_957 ;
V_945 = V_959 * 204 * 8 ;
V_10 -> V_940 . V_936 [ 0 ] . V_16 = V_968 ;
V_10 -> V_940 . V_936 [ 0 ] . V_962 += V_960 ;
V_10 -> V_941 . V_936 [ 0 ] . V_16 = V_968 ;
V_10 -> V_941 . V_936 [ 0 ] . V_962 += V_959 ;
V_10 -> V_942 . V_936 [ 0 ] . V_16 = V_968 ;
V_10 -> V_942 . V_936 [ 0 ] . V_962 += V_958 ;
V_10 -> V_943 . V_936 [ 0 ] . V_16 = V_968 ;
V_10 -> V_943 . V_936 [ 0 ] . V_962 += V_943 ;
V_10 -> V_944 . V_936 [ 0 ] . V_16 = V_968 ;
V_10 -> V_944 . V_936 [ 0 ] . V_962 += V_956 ;
V_10 -> V_945 . V_936 [ 0 ] . V_16 = V_968 ;
V_10 -> V_945 . V_936 [ 0 ] . V_962 += V_945 ;
error:
return V_35 ;
}
static int F_116 ( struct V_921 * V_922 , T_7 * V_35 )
{
struct V_1 * V_2 = V_922 -> V_923 ;
int V_969 ;
F_16 ( 1 , L_3 ) ;
V_969 = F_115 ( V_922 ) ;
if ( V_969 < 0 )
return V_969 ;
* V_35 = V_2 -> V_961 ;
return 0 ;
}
static int F_117 ( struct V_921 * V_922 ,
T_4 * V_935 )
{
struct V_1 * V_2 = V_922 -> V_923 ;
struct V_925 * V_10 = & V_922 -> V_926 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_918 )
return - V_924 ;
if ( V_2 -> V_158 == V_159 )
return - V_929 ;
* V_935 = V_10 -> V_935 . V_936 [ 0 ] . V_962 ;
return 0 ;
}
static int F_118 ( struct V_921 * V_922 , T_4 * V_970 )
{
struct V_1 * V_2 = V_922 -> V_923 ;
T_6 V_971 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_918 )
return - V_924 ;
if ( V_2 -> V_158 == V_159 )
return - V_929 ;
F_72 ( V_2 , & V_971 ) ;
if ( V_971 < 0 )
V_971 = 0 ;
* V_970 = V_971 & 0xffff ;
return 0 ;
}
static int F_119 ( struct V_921 * V_922 , T_1 * V_972 )
{
struct V_1 * V_2 = V_922 -> V_923 ;
T_4 V_305 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_918 )
return - V_924 ;
if ( V_2 -> V_158 == V_159 )
return - V_929 ;
F_80 ( V_2 , & V_305 ) ;
* V_972 = ( T_1 ) V_305 ;
return 0 ;
}
static int F_120 ( struct V_921 * V_922 , struct V_973
* V_974 )
{
struct V_1 * V_2 = V_922 -> V_923 ;
struct V_925 * V_300 = & V_922 -> V_926 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_918 )
return - V_924 ;
if ( V_2 -> V_158 == V_159 )
return - V_929 ;
switch ( V_300 -> V_927 ) {
case V_913 :
case V_914 :
case V_917 :
V_974 -> V_975 = 3000 ;
V_974 -> V_976 = 0 ;
V_974 -> V_977 = 0 ;
return 0 ;
default:
return - V_201 ;
}
}
struct V_921 * F_121 ( const struct V_978 * V_979 ,
struct V_980 * V_23 )
{
struct V_925 * V_300 ;
struct V_1 * V_2 = NULL ;
T_3 V_28 = V_979 -> V_28 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_2 = F_122 ( sizeof( struct V_1 ) , V_981 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_23 = V_23 ;
V_2 -> V_44 = V_28 ;
V_2 -> V_47 = V_979 -> V_47 ;
V_2 -> V_832 = V_979 -> V_832 ;
V_2 -> V_827 = V_979 -> V_827 ;
V_2 -> V_471 = V_979 -> V_471 ;
V_2 -> V_882 = V_979 -> V_882 ;
V_2 -> V_883 = V_979 -> V_883 ;
V_2 -> V_55 = V_979 -> V_982 ;
V_2 -> V_254 = V_979 -> V_254 ;
if ( V_979 -> V_983 ) {
V_2 -> V_383 = 0 ;
V_2 -> V_384 = 0 ;
} else {
V_2 -> V_383 = 1 ;
V_2 -> V_384 = 1 ;
}
if ( V_979 -> V_984 )
V_2 -> V_252 = V_979 -> V_984 & 0x07 ;
else
V_2 -> V_252 = 0x06 ;
if ( V_979 -> V_985 )
V_2 -> V_238 = true ;
else
V_2 -> V_238 = false ;
V_2 -> V_875 = V_979 -> V_882 ;
if ( ! V_2 -> V_883 && V_2 -> V_882 )
V_2 -> V_878 |= V_2 -> V_882 ;
else
V_2 -> V_878 &= ~ V_2 -> V_882 ;
F_123 ( & V_2 -> V_224 ) ;
memcpy ( & V_2 -> V_910 . V_911 , & V_986 , sizeof( V_986 ) ) ;
V_2 -> V_910 . V_923 = V_2 ;
F_31 ( V_2 ) ;
if ( V_2 -> V_832 ) {
if ( V_979 -> V_987 ) {
const struct V_919 * V_901 = NULL ;
V_35 = F_124 ( & V_901 , V_2 -> V_832 ,
V_2 -> V_23 -> V_988 . V_989 ) ;
if ( V_35 < 0 )
V_901 = NULL ;
F_107 ( V_901 , V_2 ) ;
} else {
V_35 = F_125 ( V_990 , 1 ,
V_2 -> V_832 ,
V_2 -> V_23 -> V_988 . V_989 ,
V_981 ,
V_2 , F_107 ) ;
if ( V_35 < 0 ) {
F_17 ( V_40
L_60 ) ;
return NULL ;
}
}
} else if ( F_105 ( V_2 ) < 0 )
goto error;
V_300 = & V_2 -> V_910 . V_926 ;
V_300 -> V_935 . V_27 = 1 ;
V_300 -> V_938 . V_27 = 1 ;
V_300 -> V_940 . V_27 = 1 ;
V_300 -> V_941 . V_27 = 1 ;
V_300 -> V_942 . V_27 = 1 ;
V_300 -> V_943 . V_27 = 1 ;
V_300 -> V_944 . V_27 = 1 ;
V_300 -> V_945 . V_27 = 1 ;
V_300 -> V_935 . V_936 [ 0 ] . V_16 = V_937 ;
V_300 -> V_938 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_940 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_941 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_942 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_943 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_944 . V_936 [ 0 ] . V_16 = V_939 ;
V_300 -> V_945 . V_936 [ 0 ] . V_16 = V_939 ;
F_17 ( V_202 L_61 ) ;
return & V_2 -> V_910 ;
error:
F_17 ( V_40 L_62 ) ;
F_110 ( V_2 ) ;
return NULL ;
}
