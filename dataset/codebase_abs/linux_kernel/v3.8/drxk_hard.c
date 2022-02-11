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
static int F_61 ( struct V_1 * V_2 , T_1 * V_354 ,
T_1 Time )
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
static int F_70 ( struct V_1 * V_2 , T_1 * V_435 )
{
T_4 V_436 ;
int V_35 ;
T_4 V_437 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_438 , & V_436 ) ;
if ( V_35 < 0 ) {
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
* V_435 = 0 ;
if ( V_436 > V_439 )
V_437 = V_436 - V_439 ;
if ( V_437 < 14000 )
* V_435 = ( 14000 - V_437 ) / 4 ;
else
* V_435 = 0 ;
return V_35 ;
}
static int F_71 ( struct V_1 * V_2 ,
T_6 * V_440 )
{
int V_35 = 0 ;
T_4 V_441 = 0 ;
T_1 V_442 = 0 ;
T_1 V_443 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_444 , & V_441 ) ;
if ( V_35 < 0 ) {
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return - V_201 ;
}
switch ( V_2 -> V_351 . V_445 ) {
case V_446 :
V_442 = V_447 << 2 ;
break;
case V_448 :
V_442 = V_449 << 2 ;
break;
case V_450 :
V_442 = V_451 << 2 ;
break;
case V_452 :
V_442 = V_453 << 2 ;
break;
default:
case V_454 :
V_442 = V_455 << 2 ;
break;
}
if ( V_441 > 0 ) {
V_443 = F_6 ( V_442 ) -
F_6 ( ( T_1 ) V_441 ) ;
}
* V_440 = V_443 ;
return V_35 ;
}
static int F_72 ( struct V_1 * V_2 ,
T_6 * V_440 )
{
int V_35 ;
T_4 V_456 = 0 ;
T_1 V_457 = 0 ;
T_1 V_458 = 0 ;
T_4 V_459 = 0 ;
T_4 V_460 = 0 ;
T_4 V_461 = 0 ;
T_1 V_462 = 0 ;
T_1 V_463 = 0 ;
T_1 V_8 = 0 ;
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
T_1 V_464 = 0 ;
T_4 V_465 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_466 , & V_460 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_467 , & V_461 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_468 , & V_459 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_469 , & V_456 ) ;
if ( V_35 < 0 )
goto error;
V_457 = ( T_1 ) V_456 ;
if ( ( V_459 > 11 ) &&
( V_457 < 0x00000FFFUL ) ) {
V_457 += 0x00010000UL ;
}
V_35 = F_21 ( V_2 , V_470 , & V_456 ) ;
if ( V_35 < 0 )
goto error;
V_458 = ( T_1 ) V_456 ;
if ( ( V_459 > 11 ) &&
( V_458 < 0x00000FFFUL ) )
V_458 += 0x00010000UL ;
V_35 = F_21 ( V_2 , V_471 , & V_465 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_460 == 0 ) || ( V_461 == 0 ) )
V_464 = 0 ;
else if ( ( V_457 + V_458 ) == 0 ) {
V_464 = 0 ;
} else {
V_463 = ( V_457 + V_458 ) <<
V_459 ;
if ( ( V_465 &
V_472 )
== V_473 )
V_462 = 17 ;
else
V_462 = 68 ;
V_8 = F_6 ( V_460 *
V_460 ) ;
V_9 = F_6 ( V_461 * V_462 ) ;
V_10 = F_6 ( V_463 ) ;
V_464 = V_8 + V_9 ;
if ( V_464 > V_10 )
V_464 -= V_10 ;
else
V_464 = 0 ;
}
* V_440 = V_464 ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_73 ( struct V_1 * V_2 , T_6 * V_440 )
{
F_16 ( 1 , L_3 ) ;
* V_440 = 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
return F_72 ( V_2 , V_440 ) ;
case V_5 :
case V_7 :
return F_71 ( V_2 , V_440 ) ;
default:
break;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , bool V_474 )
{
int V_35 = - V_201 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_159 )
return 0 ;
if ( V_2 -> V_158 == V_475 )
goto error;
if ( V_2 -> V_476 )
return 0 ;
V_35 = F_25 ( V_2 , V_232 , V_233 ) ;
if ( V_35 < 0 )
goto error;
if ( V_474 ) {
V_35 = F_25 ( V_2 , V_231 , V_477 ) ;
if ( V_35 < 0 )
goto error;
} else {
V_35 = F_25 ( V_2 , V_231 , V_478 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_34 ( V_2 , V_479 , 0 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_480 * V_481 )
{
int V_35 = - V_201 ;
F_16 ( 1 , L_3 ) ;
if ( ( V_481 == NULL )
|| ( V_481 -> V_141 > V_482 ) )
goto error;
V_35 = F_25 ( V_2 , V_483 , V_481 -> V_141 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_76 ( struct V_1 * V_2 , T_1 V_484 ,
T_4 V_256 , T_4 V_257 , T_1 V_258 )
{
T_4 V_259 = 0 ;
T_4 V_273 = ( T_4 ) ( ( V_484 >> 0 ) & 0x00FFFF ) ;
T_4 V_485 = ( T_4 ) ( ( V_484 >> 16 ) & 0x000FFF ) ;
int V_35 ;
unsigned long V_260 ;
F_16 ( 1 , L_3 ) ;
F_36 ( & V_2 -> V_224 ) ;
V_35 = F_25 ( V_2 , V_261 , V_486 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_487 , V_485 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_488 , V_273 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_489 , V_256 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_490 , V_257 ) ;
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
static int F_77 ( struct V_1 * V_2 , T_4 * V_491 )
{
T_4 V_34 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_492 , V_493 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_494 , 1 ) ;
if ( V_35 < 0 )
goto error;
* V_491 = 0 ;
V_35 = F_21 ( V_2 , V_495 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( V_34 == 127 )
* V_491 = * V_491 + 1 ;
V_35 = F_21 ( V_2 , V_496 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( V_34 == 127 )
* V_491 = * V_491 + 1 ;
V_35 = F_21 ( V_2 , V_497 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
if ( V_34 == 127 )
* V_491 = * V_491 + 1 ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_78 ( struct V_1 * V_2 )
{
T_4 V_491 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_77 ( V_2 , & V_491 ) ;
if ( V_35 < 0 )
goto error;
if ( V_491 == 1 ) {
T_4 V_498 = 0 ;
V_35 = F_21 ( V_2 , V_499 , & V_498 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_498 & V_500 ) ==
V_501 ) {
V_498 &= ( ~ ( V_500 ) ) ;
V_498 |=
V_502 ;
} else {
V_498 &= ( ~ ( V_500 ) ) ;
V_498 |=
V_501 ;
}
V_35 = F_25 ( V_2 , V_499 , V_498 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_77 ( V_2 , & V_491 ) ;
if ( V_35 < 0 )
goto error;
}
if ( V_491 < 2 )
V_35 = - V_201 ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_79 ( struct V_1 * V_2 ,
T_4 V_503 ,
T_6 V_504 , bool V_415 )
{
bool V_505 = false ;
T_1 V_506 = V_504 ;
T_1 V_507 = 0 ;
bool V_508 = ! V_2 -> V_350 ;
T_1 V_509 ;
bool V_510 ;
int V_35 ;
T_1 V_511 ;
T_1 V_512 = ( T_1 ) ( V_2 -> V_121 / 3 ) ;
T_1 V_513 ;
bool V_514 ;
F_16 ( 1 , L_3 ) ;
if ( V_415 ) {
if ( ( V_2 -> V_3 == V_5 ) ||
( V_2 -> V_3 == V_7 ) ||
( V_2 -> V_3 == V_4 ) )
V_505 = true ;
else
V_505 = false ;
}
if ( V_508 )
V_511 = V_503 +
V_506 + V_507 ;
else
V_511 = V_503 -
V_506 - V_507 ;
if ( V_511 > V_512 / 2 ) {
V_509 = V_512 - V_511 ;
V_510 = true ;
} else {
V_509 = V_511 ;
V_510 = false ;
}
V_513 = V_509 ;
V_514 = V_2 -> V_185 ^ V_508 ^
V_510 ^ V_505 ;
V_2 -> V_515 =
F_5 ( ( V_513 ) , V_512 ) ;
if ( V_514 )
V_2 -> V_515 = ~ V_2 -> V_515 + 1 ;
V_35 = F_27 ( V_2 , V_516 ,
V_2 -> V_515 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_80 ( struct V_1 * V_2 , bool V_415 )
{
T_4 V_517 = 0 ;
T_4 V_518 = 0 ;
T_4 V_519 = 0 ;
T_4 V_520 = 0 ;
T_4 V_521 = 0 ;
T_4 V_522 = 0 ;
T_4 V_523 = 0 ;
T_4 V_524 = 0 ;
T_4 V_525 = 0 ;
T_4 V_526 = 0 ;
T_4 V_527 = 0 ;
T_4 V_528 = 0 ;
T_4 V_529 = 0 ;
T_4 V_530 = 0 ;
T_4 V_34 = 0 ;
T_4 V_531 = 0 ;
T_4 V_532 = 0 ;
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_524 = 1023 ;
V_529 = 2047 ;
V_520 = 500 ;
V_525 = 1023 ;
if ( ! F_2 ( V_2 ) ) {
F_17 ( V_40 L_41 , V_58 , V_2 -> V_3 ) ;
return - V_201 ;
}
V_521 = 8 ;
V_522 = ( T_4 ) - 9 ;
V_532 = 0 ;
V_523 = 8 ;
V_526 = ( T_4 ) - 9 ;
V_527 = ( T_4 ) - 1030 ;
V_530 = 0x2380 ;
V_528 = 0x2380 ;
V_518 = 0x0511 ;
V_517 = 0x0511 ;
V_519 = 5119 ;
V_531 = V_2 -> V_154 . V_150 ;
V_35 = F_25 ( V_2 , V_533 , V_531 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_534 , V_532 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_535 , V_517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_434 , V_518 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_536 , V_519 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_537 , V_529 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_424 , V_530 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_538 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_539 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_428 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_540 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_541 , V_525 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_542 , V_524 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_543 , V_527 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_544 , V_528 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_545 , V_520 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_546 , 1023 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_547 , ( T_4 ) - 1023 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_548 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_549 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_550 , V_521 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_551 , V_523 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_552 , V_522 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_553 , V_526 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_554 , 0x7fff ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_555 , 0x0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_556 , 0x0117 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_557 , 0x0657 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_558 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_559 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_560 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_561 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_562 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_563 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_564 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_565 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_566 , 500 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_567 , 500 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_568 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 = 0x0657 ;
V_34 &= ~ V_569 ;
V_34 |= ( V_570 << V_571 ) ;
V_34 &= ~ V_572 ;
V_34 |= ( V_573 << V_574 ) ;
V_35 = F_25 ( V_2 , V_568 , V_34 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_81 ( struct V_1 * V_2 , T_4 * V_575 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
if ( V_575 == NULL )
V_35 = F_25 ( V_2 , V_576 , 0 ) ;
else
V_35 = F_21 ( V_2 , V_576 , V_575 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_82 ( struct V_1 * V_2 ,
T_4 V_213 , T_4 V_577 ,
T_4 V_578 , T_4 V_579 , T_4 V_580 ,
T_4 V_581 , T_4 V_582 )
{
T_4 V_296 = 0 ;
T_4 V_583 = 0 ;
T_4 V_584 = 0 ;
T_4 V_585 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_336 , & V_585 ) ;
if ( V_585 != 1 ) {
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
V_584 = 0 ;
do {
F_30 ( 1 ) ;
V_35 = F_21 ( V_2 , V_586 , & V_296 ) ;
V_584 ++ ;
} while ( ( V_296 != 0 ) && ( V_584 < V_222 ) );
if ( V_584 >= V_222 && ( V_35 < 0 ) )
goto error;
switch ( V_213 ) {
case V_587 :
case V_588 :
case V_589 :
V_35 = F_25 ( V_2 , V_590 , V_577 ) ;
if ( V_35 < 0 )
goto error;
break;
default:
break;
}
switch ( V_213 ) {
case V_587 :
case V_588 :
case V_589 :
V_35 = F_25 ( V_2 , V_591 , V_579 ) ;
case V_592 :
case V_593 :
V_35 = F_25 ( V_2 , V_594 , V_578 ) ;
case V_595 :
case V_596 :
V_35 = F_25 ( V_2 , V_586 , V_213 ) ;
break;
default:
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
V_584 = 0 ;
do {
F_30 ( 1 ) ;
V_35 = F_21 ( V_2 , V_586 , & V_296 ) ;
V_584 ++ ;
} while ( ( V_296 != 0 ) && ( V_584 < V_222 ) );
if ( V_584 >= V_222 && ( V_35 < 0 ) )
goto error;
V_35 = F_21 ( V_2 , V_590 , & V_583 ) ;
if ( V_583 == 0xFFFF ) {
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
switch ( V_213 ) {
case V_593 :
case V_595 :
V_35 = F_21 ( V_2 , V_594 , & ( V_578 ) ) ;
case V_592 :
case V_597 :
case V_587 :
case V_588 :
case V_589 :
case V_596 :
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
static int F_83 ( struct V_1 * V_2 )
{
enum V_318 V_329 = V_67 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_50 ( V_2 , & V_329 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_84 ( struct V_1 * V_2 , bool * V_598 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
if ( * V_598 == true )
V_35 = F_25 ( V_2 , V_599 , 0 ) ;
else
V_35 = F_25 ( V_2 , V_599 , 1 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_85 ( struct V_1 * V_2 , bool * V_598 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
if ( * V_598 == true ) {
V_35 = F_25 ( V_2 , V_600 ,
V_601 ) ;
} else {
V_35 = F_25 ( V_2 , V_600 , 0 ) ;
}
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_602 * V_603 )
{
T_4 V_34 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_21 ( V_2 , V_604 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_603 -> V_605 ) {
case V_606 :
V_34 &= ~ V_607 ;
V_34 |= ( ( V_603 -> V_608 <<
V_609 )
& ( V_607 ) ) ;
break;
case V_610 :
V_34 &= ~ V_611 ;
V_34 |= ( ( V_603 -> V_608 <<
V_612 )
& ( V_611 ) ) ;
break;
default:
return - V_201 ;
}
V_35 = F_25 ( V_2 , V_604 , V_34 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_87 ( struct V_1 * V_2 ,
enum V_613 * V_135 )
{
int V_35 = - V_201 ;
F_16 ( 1 , L_3 ) ;
switch ( * V_135 ) {
case V_614 :
case V_181 :
case V_615 :
break;
default:
goto error;
}
V_35 = F_25 ( V_2 , V_616 ,
( T_4 ) * V_135 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_35 ;
bool V_617 = false ;
bool V_618 = true ;
struct V_602 V_619 = { 0 , V_606 } ;
struct V_602 V_620 = { 0 , V_610 } ;
F_16 ( 1 , L_3 ) ;
V_35 = F_84 ( V_2 , & V_617 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_85 ( V_2 , & V_618 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_86 ( V_2 , & V_619 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_86 ( V_2 , & V_620 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_536 , V_2 -> V_149 . V_151 ) ;
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
F_83 ( V_2 ) ;
F_89 ( V_2 ) ;
V_35 = F_47 ( V_2 , V_333 | V_335 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_333 | V_621 , 0 , NULL , 1 , & V_330 ) ;
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
V_35 = F_25 ( V_2 , V_622 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_623 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_624 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_625 , V_626 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_49 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_627 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_628 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_629 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_630 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_631 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_632 , 0x4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_633 , 0x4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_634 , 1600 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_635 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_636 , 448 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_637 , 495 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_41 ( V_2 , V_638 , V_639 , V_640 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_641 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_642 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_643 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_340 , V_644 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_78 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_75 ( V_2 , & V_2 -> V_152 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_645 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_68 ( V_2 , & V_2 -> V_148 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_69 ( V_2 , & V_2 -> V_149 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_646 , & V_34 ) ;
if ( V_35 < 0 )
goto error;
V_34 |= V_647 ;
V_35 = F_25 ( V_2 , V_646 , V_34 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_332 ) ;
if ( V_35 < 0 )
goto error;
if ( ! V_2 -> V_648 ) {
V_35 = F_25 ( V_2 , V_533 , V_2 -> V_149 . V_150 ) ;
if ( V_35 < 0 )
goto error;
}
#ifdef F_90
V_35 = F_25 ( V_2 , V_649 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_650 , 2 ) ;
if ( V_35 < 0 )
goto error;
#endif
V_35 = F_25 ( V_2 , V_651 , 1 ) ;
if ( V_35 < 0 )
goto error;
#ifdef F_90
V_35 = F_25 ( V_2 , V_652 , 0x400 ) ;
if ( V_35 < 0 )
goto error;
#else
V_35 = F_25 ( V_2 , V_652 , 0x1000 ) ;
if ( V_35 < 0 )
goto error;
#endif
V_35 = F_25 ( V_2 , V_653 , 0x0001 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_66 ( V_2 , V_4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_88 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_59 ( struct V_1 * V_2 )
{
T_4 V_579 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_579 = V_654 ;
V_35 = F_82 ( V_2 , V_587 , 0 , V_655 , V_579 , 0 , 0 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_64 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_656 , V_657 ) ;
if ( V_35 < 0 )
goto error;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_58 ( struct V_1 * V_2 , T_4 V_658 ,
T_6 V_504 )
{
T_4 V_330 = 0 ;
T_4 V_465 = 0 ;
T_4 V_659 = 0 ;
T_1 V_660 = 0 ;
T_1 V_661 = 0 ;
T_4 V_579 ;
int V_35 ;
F_16 ( 1 , L_42 , V_658 , V_504 ) ;
V_35 = F_47 ( V_2 , V_333 | V_334 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_645 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_336 , V_337 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_338 , V_339 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_662 , V_663 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_2 -> V_351 . V_664 ) {
case V_665 :
default:
V_659 |= V_666 ;
case V_667 :
V_465 |= V_668 ;
break;
case V_669 :
V_465 |= V_473 ;
break;
}
switch ( V_2 -> V_351 . V_670 ) {
default:
case V_671 :
V_659 |= V_672 ;
case V_673 :
V_465 |= V_674 ;
break;
case V_675 :
V_465 |= V_676 ;
break;
case V_677 :
V_465 |= V_678 ;
break;
case V_679 :
V_465 |= V_680 ;
break;
}
switch ( V_2 -> V_351 . V_681 ) {
case V_682 :
case V_683 :
default:
V_659 |= V_684 ;
case V_685 :
V_465 |= V_686 ;
break;
case V_687 :
V_465 |= V_688 ;
break;
case V_689 :
V_465 |= V_690 ;
break;
}
switch ( V_2 -> V_351 . V_445 ) {
case V_691 :
default:
V_659 |= V_692 ;
case V_450 :
V_465 |= V_693 ;
break;
case V_694 :
V_465 |= V_695 ;
break;
case V_446 :
V_465 |= V_696 ;
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
V_465 |= V_697 ;
V_35 = F_25 ( V_2 , V_698 , V_699 ) ;
if ( V_35 < 0 )
goto error;
#endif
switch ( V_2 -> V_351 . V_700 ) {
case V_701 :
default:
V_659 |= V_702 ;
case V_703 :
V_465 |= V_704 ;
break;
case V_705 :
V_465 |= V_706 ;
break;
case V_707 :
V_465 |= V_708 ;
break;
case V_709 :
V_465 |= V_710 ;
break;
case V_711 :
V_465 |= V_712 ;
break;
}
switch ( V_2 -> V_351 . V_713 ) {
case 0 :
V_2 -> V_351 . V_713 = 8000000 ;
case 8000000 :
V_661 = V_714 ;
V_35 = F_25 ( V_2 , V_715 , 3052 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_716 , 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_717 , 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_718 , 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_719 , 1 ) ;
if ( V_35 < 0 )
goto error;
break;
case 7000000 :
V_661 = V_720 ;
V_35 = F_25 ( V_2 , V_715 , 3491 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_716 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_717 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_718 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_719 , 1 ) ;
if ( V_35 < 0 )
goto error;
break;
case 6000000 :
V_661 = V_721 ;
V_35 = F_25 ( V_2 , V_715 , 4073 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_716 , 19 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_717 , 19 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_718 , 14 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_719 , 1 ) ;
if ( V_35 < 0 )
goto error;
break;
default:
V_35 = - V_201 ;
goto error;
}
if ( V_660 == 0 ) {
V_660 = F_5 ( ( T_1 )
( ( V_2 -> V_121 *
1000 ) / 3 ) , V_661 ) ;
if ( ( V_660 & 0x7fL ) >= 0x40 )
V_660 += 0x80L ;
V_660 = V_660 >> 7 ;
V_660 = V_660 - ( 1 << 23 ) ;
}
V_660 &=
( ( ( ( T_1 ) V_722 ) <<
V_723 ) | V_724 ) ;
V_35 = F_27 ( V_2 , V_725 , V_660 ) ;
if ( V_35 < 0 )
goto error;
#if 0
status = DVBTSetFrequencyShift(demod, channel, tunerOffset);
if (status < 0)
goto error;
#endif
V_35 = F_79 ( V_2 , V_658 , V_504 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_332 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_726 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_336 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_333 | V_727 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_579 = ( V_666 |
V_672 |
V_692 |
V_684 |
V_702 ) ;
V_35 = F_82 ( V_2 , V_588 ,
0 , V_465 , V_579 , 0 , 0 , 0 ) ;
if ( V_35 < 0 )
goto error;
if ( ! V_2 -> V_648 )
V_35 = F_87 ( V_2 , & V_2 -> V_180 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_63 ( struct V_1 * V_2 , T_1 * V_354 )
{
int V_35 ;
const T_4 V_728 = ( V_729 |
V_730 ) ;
const T_4 V_731 = ( V_730 ) ;
const T_4 V_732 = V_733 ;
T_4 V_734 = 0 ;
T_4 V_735 = 0 ;
F_16 ( 1 , L_3 ) ;
* V_354 = V_355 ;
V_35 = F_21 ( V_2 , V_336 , & V_735 ) ;
if ( V_35 < 0 )
goto V_260;
if ( V_735 == V_337 )
goto V_260;
V_35 = F_21 ( V_2 , V_736 , & V_734 ) ;
if ( V_35 < 0 )
goto V_260;
if ( ( V_734 & V_728 ) == V_728 )
* V_354 = V_737 ;
else if ( ( V_734 & V_731 ) == V_731 )
* V_354 = V_738 ;
else if ( ( V_734 & V_732 ) == V_732 )
* V_354 = V_739 ;
else if ( V_734 & V_740 )
* V_354 = V_741 ;
V_260:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_91 ( struct V_1 * V_2 )
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
V_35 = F_25 ( V_2 , V_742 , V_743 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_744 | V_334 , 0 , NULL , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_49 ( V_2 , false ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_92 ( struct V_1 * V_2 ,
enum V_745 V_445 ,
T_1 V_746 )
{
T_1 V_747 = 0 ;
T_1 V_748 = 0 ;
T_4 V_749 = 0 ;
T_4 V_750 = 0 ;
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_749 = 1 ;
switch ( V_445 ) {
case V_751 :
V_747 = 4 * V_746 ;
break;
case V_752 :
V_747 = 5 * V_746 ;
break;
case V_753 :
V_747 = 6 * V_746 ;
break;
case V_754 :
V_747 = 7 * V_746 ;
break;
case V_755 :
V_747 = 8 * V_746 ;
break;
default:
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
V_747 /= 1000 ;
V_747 *= 500 ;
V_748 = ( V_747 / 1632UL ) + 1 ;
V_749 = 1 + ( T_4 ) ( V_748 >> 16 ) ;
if ( V_749 == 0 ) {
V_35 = - V_201 ;
if ( V_35 < 0 )
goto error;
}
V_750 =
( ( T_4 ) V_748 +
( V_749 >> 1 ) ) / V_749 ;
V_35 = F_25 ( V_2 , V_652 , V_750 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_653 , V_749 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_756 , V_750 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_757 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 13517 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , V_447 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 32 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 140 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 95 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 120 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , 230 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , 105 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) 220 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_804 , ( T_4 ) 25 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_805 , ( T_4 ) 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_806 , ( T_4 ) - 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_807 , ( T_4 ) - 65 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_808 , ( T_4 ) - 127 ) ;
if ( V_35 < 0 )
goto error;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_757 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 6707 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , V_449 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 20 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 90 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , 170 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) 140 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_804 , ( T_4 ) - 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_805 , ( T_4 ) - 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_806 , ( T_4 ) - 26 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_807 , ( T_4 ) - 56 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_808 , ( T_4 ) - 86 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_757 , 13336 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 12618 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 11988 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 13809 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 13809 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 15609 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , V_451 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 30 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 30 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 25 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 48 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 60 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 110 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , 200 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , 95 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) 141 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_804 , ( T_4 ) 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_805 , ( T_4 ) 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_806 , ( T_4 ) - 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_807 , ( T_4 ) - 45 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_808 , ( T_4 ) - 80 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_757 , 6564 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 6598 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 6394 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 6409 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 6656 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 7238 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , V_453 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 120 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 60 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 25 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 64 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 60 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , 140 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) 65 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_804 , ( T_4 ) 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_805 , ( T_4 ) 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_806 , ( T_4 ) - 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_807 , ( T_4 ) - 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_808 , ( T_4 ) - 23 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_757 , 11502 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_758 , 12084 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_759 , 12543 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_760 , 12931 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_761 , 13629 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_762 , 15385 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_763 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_764 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_765 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_766 , 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_767 , 6 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_768 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_769 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_770 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_771 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_772 , V_455 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_773 , 15 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_774 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_775 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_776 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_777 , 24 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_778 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_779 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_780 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_781 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_782 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_783 , 250 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_784 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_785 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_786 , 125 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_787 , 16 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_788 , 25 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_789 , 48 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_790 , 5 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_791 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_792 , 10 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_793 , 50 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_794 , 60 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_795 , 80 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_796 , 100 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_797 , 150 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_798 , 110 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_799 , 40 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_800 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_801 , 12 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_802 , ( T_4 ) 8 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_803 , ( T_4 ) 74 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_804 , ( T_4 ) 18 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_805 , ( T_4 ) 13 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_806 , ( T_4 ) 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_807 , ( T_4 ) 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_808 , ( T_4 ) - 8 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_35 ;
T_4 V_330 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_742 , V_743 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_744 | V_335 , 0 , NULL , 1 , & V_330 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_99 ( struct V_1 * V_2 )
{
T_1 V_809 = 0 ;
T_1 V_810 = 0 ;
T_1 V_811 = 0 ;
T_4 V_812 = 0 ;
T_1 V_813 = 0 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_809 = ( V_2 -> V_121 * 1000 ) / 3 ;
V_812 = 0 ;
if ( V_2 -> V_351 . V_814 <= 1188750 )
V_812 = 3 ;
else if ( V_2 -> V_351 . V_814 <= 2377500 )
V_812 = 2 ;
else if ( V_2 -> V_351 . V_814 <= 4755000 )
V_812 = 1 ;
V_35 = F_25 ( V_2 , V_815 , V_812 ) ;
if ( V_35 < 0 )
goto error;
V_810 = V_2 -> V_351 . V_814 * ( 1 << V_812 ) ;
if ( V_810 == 0 ) {
V_35 = - V_201 ;
goto error;
}
V_811 = ( V_809 / V_810 ) * ( 1 << 21 ) +
( F_5 ( ( V_809 % V_810 ) , V_810 ) >> 7 ) -
( 1 << 23 ) ;
V_35 = F_27 ( V_2 , V_725 , V_811 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_816 = V_811 ;
V_810 = V_2 -> V_351 . V_814 ;
if ( V_809 == 0 ) {
V_35 = - V_201 ;
goto error;
}
V_813 = ( V_810 / V_809 ) * ( 1 << 12 ) +
( F_5 ( ( V_810 % V_809 ) , V_809 ) >>
16 ) ;
if ( V_813 > 511 )
V_813 = 511 ;
V_35 = F_25 ( V_2 , V_817 , ( T_4 ) V_813 ) ;
error:
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_62 ( struct V_1 * V_2 , T_1 * V_354 )
{
int V_35 ;
T_4 V_818 [ 2 ] = { 0 , 0 } ;
F_16 ( 1 , L_3 ) ;
* V_354 = V_355 ;
V_35 = F_47 ( V_2 ,
V_744 |
V_819 , 0 , NULL , 2 ,
V_818 ) ;
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
if ( V_818 [ 1 ] < V_820 ) {
} else if ( V_818 [ 1 ] < V_821 ) {
* V_354 = V_739 ;
} else if ( V_818 [ 1 ] < V_822 ) {
* V_354 = V_737 ;
} else {
* V_354 = V_741 ;
}
return V_35 ;
}
static int F_100 ( struct V_1 * V_2 ,
int V_823 )
{
int V_35 ;
T_4 V_330 ;
T_4 V_824 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_824 [ 0 ] = V_2 -> V_174 ;
V_824 [ 1 ] = V_177 ;
if ( V_823 == 2 ) {
T_4 V_825 [ 1 ] = { 0 } ;
if ( V_2 -> V_3 == V_7 )
V_825 [ 0 ] = V_826 ;
else
V_825 [ 0 ] = V_827 ;
V_35 = F_47 ( V_2 ,
V_744 | V_621 ,
1 , V_825 , 1 , & V_330 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 ,
V_744 | V_828 ,
V_823 , V_824 ,
1 , & V_330 ) ;
} else if ( V_823 == 4 ) {
if ( V_2 -> V_3 == V_7 )
V_824 [ 2 ] = V_826 ;
else
V_824 [ 2 ] = V_827 ;
V_824 [ 3 ] |= ( V_829 ) ;
V_35 = F_47 ( V_2 ,
V_744 | V_828 ,
V_823 , V_824 ,
1 , & V_330 ) ;
} else {
F_17 ( V_830 L_43
L_44 , V_823 ) ;
V_35 = - V_201 ;
}
error:
if ( V_35 < 0 )
F_17 ( V_830 L_45 ,
V_35 , V_58 ) ;
return V_35 ;
}
static int F_57 ( struct V_1 * V_2 , T_4 V_658 ,
T_6 V_504 )
{
int V_35 ;
T_4 V_330 ;
int V_831 = V_2 -> V_832 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_833 , V_834 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_835 , V_836 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_98 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_99 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_2 -> V_351 . V_445 ) {
case V_454 :
V_2 -> V_174 = V_755 ;
break;
case V_691 :
case V_450 :
V_2 -> V_174 = V_753 ;
break;
case V_446 :
V_2 -> V_174 = V_751 ;
break;
case V_448 :
V_2 -> V_174 = V_752 ;
break;
case V_452 :
V_2 -> V_174 = V_754 ;
break;
default:
V_35 = - V_201 ;
break;
}
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_832 == 4
|| ! V_2 -> V_832 ) {
V_831 = 4 ;
V_35 = F_100 ( V_2 , V_831 ) ;
}
if ( V_2 -> V_832 == 2
|| ( ! V_2 -> V_832 && V_35 < 0 ) ) {
V_831 = 2 ;
V_35 = F_100 ( V_2 , V_831 ) ;
}
if ( V_35 < 0 ) {
F_16 ( 1 , L_46
L_47
L_48 ,
V_2 -> V_832 ,
V_2 -> V_837 ) ;
goto error;
} else if ( ! V_2 -> V_832 ) {
F_16 ( 1 , L_49
L_50 ,
V_831 ) ;
V_2 -> V_832 = V_831 ;
}
#if 0
status = SetFrequency(channel, tunerFreqOffset));
if (status < 0)
goto error;
#endif
V_35 = F_79 ( V_2 , V_658 , V_504 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_92 ( V_2 , V_2 -> V_174 , V_2 -> V_351 . V_814 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_635 , V_838 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_839 , V_840 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_841 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_842 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_843 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_844 , 7 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_845 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_846 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_847 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_848 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_849 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_850 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_851 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_852 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_853 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_854 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_855 , 2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_856 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_857 , 3 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_858 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_859 , 4 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_860 , V_861 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_645 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_2 -> V_351 . V_445 ) {
case V_446 :
V_35 = F_93 ( V_2 ) ;
break;
case V_448 :
V_35 = F_94 ( V_2 ) ;
break;
case V_691 :
case V_450 :
V_35 = F_95 ( V_2 ) ;
break;
case V_452 :
V_35 = F_96 ( V_2 ) ;
break;
case V_454 :
V_35 = F_97 ( V_2 ) ;
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
V_35 = F_25 ( V_2 , V_656 , V_657 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_742 , V_862 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_340 , V_644 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_47 ( V_2 , V_744 | V_727 , 0 , NULL , 1 , & V_330 ) ;
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
#ifdef F_101
#define F_102
#include "drxk_filters.h"
#undef F_102
#endif
F_16 ( 1 , L_3 ) ;
F_103 ( V_2 ) ;
V_35 = F_91 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_98 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_340 , V_341 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_625 , V_626 ) ;
if ( V_35 < 0 )
goto error;
switch ( V_343 ) {
case V_5 :
V_35 = F_41 ( V_2 , V_863 , V_639 , V_640 ) ;
break;
case V_7 :
V_35 = F_76 ( V_2 , V_864 , V_865 , V_866 , V_640 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_76 ( V_2 , V_867 , V_865 , V_866 , V_640 ) ;
break;
default:
V_35 = - V_201 ;
}
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_632 , ( 1 << V_868 ) ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_869 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_870 , ( ( 1 << V_871 ) | ( 1 << V_872 ) ) ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_631 , 21 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_623 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_636 , 448 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_624 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_642 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_873 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_874 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_875 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_622 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_876 , 500 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_637 , 1000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_599 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_629 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_630 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_641 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_877 , 1 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_49 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_494 , 0x01 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_78 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_878 , 2000 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_645 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_80 ( V_2 , true ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_75 ( V_2 , & ( V_2 -> V_156 ) ) ;
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
static int F_104 ( struct V_1 * V_2 )
{
int V_35 ;
T_4 V_879 = 0 ;
F_16 ( 1 , L_3 ) ;
V_35 = F_25 ( V_2 , V_190 , V_191 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_192 , V_193 ) ;
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_209 ) {
if ( V_2 -> V_880 & 0x0001 ) {
V_35 = F_25 ( V_2 , V_881 , V_2 -> V_183 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_882 , & V_879 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_2 -> V_883 & 0x0001 ) == 0 )
V_879 &= 0x7FFF ;
else
V_879 |= 0x8000 ;
V_35 = F_25 ( V_2 , V_882 , V_879 ) ;
if ( V_35 < 0 )
goto error;
}
if ( V_2 -> V_880 & 0x0002 ) {
V_35 = F_25 ( V_2 , V_884 , V_2 -> V_183 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_882 , & V_879 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_2 -> V_883 & 0x0002 ) == 0 )
V_879 &= 0xBFFF ;
else
V_879 |= 0x4000 ;
V_35 = F_25 ( V_2 , V_882 , V_879 ) ;
if ( V_35 < 0 )
goto error;
}
if ( V_2 -> V_880 & 0x0004 ) {
V_35 = F_25 ( V_2 , V_885 , V_2 -> V_183 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_21 ( V_2 , V_882 , & V_879 ) ;
if ( V_35 < 0 )
goto error;
if ( ( V_2 -> V_883 & 0x0004 ) == 0 )
V_879 &= 0xFFFB ;
else
V_879 |= 0x0004 ;
V_35 = F_25 ( V_2 , V_882 , V_879 ) ;
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
static int F_103 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
bool V_886 ;
F_16 ( 1 , L_3 ) ;
if ( ! V_2 -> V_887 )
return 0 ;
V_886 = V_2 -> V_883 & V_2 -> V_887 ;
if ( V_2 -> V_888 ^ V_886 ) {
if ( V_2 -> V_888 )
V_2 -> V_883 &= ~ V_2 -> V_887 ;
else
V_2 -> V_883 |= V_2 -> V_887 ;
V_35 = F_104 ( V_2 ) ;
}
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
bool V_886 ;
F_16 ( 1 , L_3 ) ;
if ( ! V_2 -> V_887 )
return 0 ;
V_886 = V_2 -> V_883 & V_2 -> V_887 ;
if ( ! ( V_2 -> V_888 ^ V_886 ) ) {
if ( V_2 -> V_888 )
V_2 -> V_883 |= V_2 -> V_887 ;
else
V_2 -> V_883 &= ~ V_2 -> V_887 ;
V_35 = F_104 ( V_2 ) ;
}
if ( V_35 < 0 )
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
return V_35 ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_35 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_120 ) {
V_35 = F_74 ( V_2 , true ) ;
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
static int F_106 ( struct V_1 * V_2 )
{
int V_35 = 0 , V_889 = 0 ;
enum V_318 V_329 = V_321 ;
T_4 V_890 ;
F_16 ( 1 , L_3 ) ;
if ( ( V_2 -> V_158 == V_159 ) ) {
F_7 ( V_2 ) ;
V_35 = F_29 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_32 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_891 , V_892 | V_893 | V_894 ) ;
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
V_895 ) / 1000 ;
if ( V_2 -> V_230 >
V_896 ) {
V_2 -> V_230 =
V_896 ;
}
V_2 -> V_230 +=
V_2 -> V_230 <<
V_897 ;
V_35 = F_38 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
#if V_898
if ( ! ( V_2 -> V_899 )
&& ! ( V_2 -> V_900 ) )
#endif
{
V_35 = F_25 ( V_2 , V_190 , V_191 ) ;
if ( V_35 < 0 )
goto error;
}
V_35 = F_40 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_901 , V_902 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_331 , V_903 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_282 , V_276 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_904 , V_905 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_41 ( V_2 , 0 , 6 , 100 ) ;
if ( V_35 < 0 )
goto error;
if ( V_2 -> V_906 ) {
V_35 = F_44 ( V_2 , V_2 -> V_906 -> V_34 ,
V_2 -> V_906 -> V_907 ) ;
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
V_890 =
( ( ( V_908 / 100 ) % 10 ) << 12 ) +
( ( ( V_908 / 10 ) % 10 ) << 8 ) +
( ( V_908 % 10 ) << 4 ) +
( V_909 % 10 ) ;
V_35 = F_25 ( V_2 , V_910 , V_890 ) ;
if ( V_35 < 0 )
goto error;
V_890 =
( ( ( V_911 / 1000 ) % 10 ) << 12 ) +
( ( ( V_911 / 100 ) % 10 ) << 8 ) +
( ( ( V_911 / 10 ) % 10 ) << 4 ) +
( V_911 % 10 ) ;
V_35 = F_25 ( V_2 , V_912 , V_890 ) ;
if ( V_35 < 0 )
goto error;
F_17 ( V_202 L_51 ,
V_908 , V_909 ,
V_911 ) ;
V_35 = F_25 ( V_2 , V_913 , 0 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_25 ( V_2 , V_656 , V_914 ) ;
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
V_35 = F_104 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_158 = V_348 ;
if ( V_2 -> V_128 ) {
V_35 = F_105 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_158 = V_475 ;
} else
V_2 -> V_158 = V_348 ;
V_889 = 0 ;
if ( V_2 -> V_114 ) {
V_2 -> V_915 . V_916 . V_917 [ V_889 ++ ] = V_918 ;
V_2 -> V_915 . V_916 . V_917 [ V_889 ++ ] = V_919 ;
F_107 ( V_2 -> V_915 . V_916 . V_920 . V_921 , L_52 ,
sizeof( V_2 -> V_915 . V_916 . V_920 . V_921 ) ) ;
}
if ( V_2 -> V_113 ) {
V_2 -> V_915 . V_916 . V_917 [ V_889 ++ ] = V_922 ;
F_107 ( V_2 -> V_915 . V_916 . V_920 . V_921 , L_53 ,
sizeof( V_2 -> V_915 . V_916 . V_920 . V_921 ) ) ;
}
F_9 ( V_2 ) ;
}
error:
if ( V_35 < 0 ) {
V_2 -> V_158 = V_923 ;
F_9 ( V_2 ) ;
F_17 ( V_40 L_13 , V_35 , V_58 ) ;
}
return V_35 ;
}
static void F_108 ( const struct V_924 * V_906 ,
void * V_925 )
{
struct V_1 * V_2 = V_925 ;
F_16 ( 1 , L_54 , V_906 ? L_55 : L_56 ) ;
if ( ! V_906 ) {
F_17 ( V_40
L_57 ,
V_2 -> V_837 ) ;
F_17 ( V_202
L_58 ,
V_2 -> V_837 ) ;
V_2 -> V_837 = NULL ;
}
V_2 -> V_906 = V_906 ;
F_106 ( V_2 ) ;
}
static void F_109 ( struct V_926 * V_927 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_906 )
F_110 ( V_2 -> V_906 ) ;
F_111 ( V_2 ) ;
}
static int F_112 ( struct V_926 * V_927 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
if ( V_2 -> V_158 == V_159 )
return 0 ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_926 * V_927 , int V_274 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
F_16 ( 1 , L_54 , V_274 ? L_24 : L_25 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
return F_74 ( V_2 , V_274 ? true : false ) ;
}
static int F_114 ( struct V_926 * V_927 )
{
struct V_930 * V_300 = & V_927 -> V_931 ;
T_1 V_917 = V_300 -> V_932 , V_933 ;
struct V_1 * V_2 = V_927 -> V_928 ;
T_1 IF ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
if ( V_2 -> V_158 == V_159 )
return - V_934 ;
if ( ! V_927 -> V_916 . V_935 . V_936 ) {
F_17 ( V_40
L_59 ) ;
return - V_201 ;
}
if ( V_927 -> V_916 . V_937 )
V_927 -> V_916 . V_937 ( V_927 , 1 ) ;
if ( V_927 -> V_916 . V_935 . V_938 )
V_927 -> V_916 . V_935 . V_938 ( V_927 ) ;
if ( V_927 -> V_916 . V_937 )
V_927 -> V_916 . V_937 ( V_927 , 0 ) ;
V_933 = V_2 -> V_351 . V_932 ;
V_2 -> V_351 = * V_300 ;
if ( V_933 != V_917 ) {
F_60 ( V_2 ) ;
switch ( V_917 ) {
case V_918 :
case V_919 :
if ( ! V_2 -> V_114 )
return - V_201 ;
V_2 -> V_939 = ( V_917 == V_919 ) ? true : false ;
if ( V_2 -> V_939 )
F_53 ( V_2 , V_7 ) ;
else
F_53 ( V_2 , V_5 ) ;
break;
case V_922 :
if ( ! V_2 -> V_113 )
return - V_201 ;
F_53 ( V_2 , V_4 ) ;
break;
default:
return - V_201 ;
}
}
V_927 -> V_916 . V_935 . V_936 ( V_927 , & IF ) ;
F_56 ( V_2 , 0 , IF ) ;
return 0 ;
}
static int F_115 ( struct V_926 * V_927 , T_7 * V_35 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
T_1 V_940 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
if ( V_2 -> V_158 == V_159 )
return - V_934 ;
* V_35 = 0 ;
F_61 ( V_2 , & V_940 , 0 ) ;
if ( V_940 == V_737 )
* V_35 |= 0x1f ;
if ( V_940 == V_738 )
* V_35 |= 0x0f ;
if ( V_940 == V_739 )
* V_35 |= 0x07 ;
return 0 ;
}
static int F_116 ( struct V_926 * V_927 , T_1 * V_941 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
if ( V_2 -> V_158 == V_159 )
return - V_934 ;
* V_941 = 0 ;
return 0 ;
}
static int F_117 ( struct V_926 * V_927 ,
T_4 * V_942 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
T_1 V_29 = 0 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
if ( V_2 -> V_158 == V_159 )
return - V_934 ;
F_70 ( V_2 , & V_29 ) ;
* V_942 = V_29 & 0xffff ;
return 0 ;
}
static int F_118 ( struct V_926 * V_927 , T_4 * V_943 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
T_6 V_944 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
if ( V_2 -> V_158 == V_159 )
return - V_934 ;
F_73 ( V_2 , & V_944 ) ;
* V_943 = V_944 & 0xffff ;
return 0 ;
}
static int F_119 ( struct V_926 * V_927 , T_1 * V_945 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
T_4 V_305 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
if ( V_2 -> V_158 == V_159 )
return - V_934 ;
F_81 ( V_2 , & V_305 ) ;
* V_945 = ( T_1 ) V_305 ;
return 0 ;
}
static int F_120 ( struct V_926 * V_927 , struct V_946
* V_947 )
{
struct V_1 * V_2 = V_927 -> V_928 ;
struct V_930 * V_300 = & V_927 -> V_931 ;
F_16 ( 1 , L_3 ) ;
if ( V_2 -> V_158 == V_923 )
return - V_929 ;
if ( V_2 -> V_158 == V_159 )
return - V_934 ;
switch ( V_300 -> V_932 ) {
case V_918 :
case V_919 :
case V_922 :
V_947 -> V_948 = 3000 ;
V_947 -> V_949 = 0 ;
V_947 -> V_950 = 0 ;
return 0 ;
default:
return - V_201 ;
}
}
struct V_926 * F_121 ( const struct V_951 * V_952 ,
struct V_953 * V_23 )
{
struct V_1 * V_2 = NULL ;
T_3 V_28 = V_952 -> V_28 ;
int V_35 ;
F_16 ( 1 , L_3 ) ;
V_2 = F_122 ( sizeof( struct V_1 ) , V_954 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_23 = V_23 ;
V_2 -> V_44 = V_28 ;
V_2 -> V_47 = V_952 -> V_47 ;
V_2 -> V_837 = V_952 -> V_837 ;
V_2 -> V_832 = V_952 -> V_832 ;
V_2 -> V_476 = V_952 -> V_476 ;
V_2 -> V_887 = V_952 -> V_887 ;
V_2 -> V_888 = V_952 -> V_888 ;
V_2 -> V_55 = V_952 -> V_955 ;
V_2 -> V_254 = V_952 -> V_254 ;
if ( V_952 -> V_956 ) {
V_2 -> V_383 = 0 ;
V_2 -> V_384 = 0 ;
} else {
V_2 -> V_383 = 1 ;
V_2 -> V_384 = 1 ;
}
if ( V_952 -> V_957 )
V_2 -> V_252 = V_952 -> V_957 & 0x07 ;
else
V_2 -> V_252 = 0x06 ;
if ( V_952 -> V_958 )
V_2 -> V_238 = true ;
else
V_2 -> V_238 = false ;
V_2 -> V_880 = V_952 -> V_887 ;
if ( ! V_2 -> V_888 && V_2 -> V_887 )
V_2 -> V_883 |= V_2 -> V_887 ;
else
V_2 -> V_883 &= ~ V_2 -> V_887 ;
F_123 ( & V_2 -> V_224 ) ;
memcpy ( & V_2 -> V_915 . V_916 , & V_959 , sizeof( V_959 ) ) ;
V_2 -> V_915 . V_928 = V_2 ;
F_31 ( V_2 ) ;
if ( V_2 -> V_837 ) {
if ( V_952 -> V_960 ) {
const struct V_924 * V_906 = NULL ;
V_35 = F_124 ( & V_906 , V_2 -> V_837 ,
V_2 -> V_23 -> V_961 . V_962 ) ;
if ( V_35 < 0 )
V_906 = NULL ;
F_108 ( V_906 , V_2 ) ;
} else {
V_35 = F_125 ( V_963 , 1 ,
V_2 -> V_837 ,
V_2 -> V_23 -> V_961 . V_962 ,
V_954 ,
V_2 , F_108 ) ;
if ( V_35 < 0 ) {
F_17 ( V_40
L_60 ) ;
return NULL ;
}
}
} else if ( F_106 ( V_2 ) < 0 )
goto error;
F_17 ( V_202 L_61 ) ;
return & V_2 -> V_915 ;
error:
F_17 ( V_40 L_62 ) ;
F_111 ( V_2 ) ;
return NULL ;
}
