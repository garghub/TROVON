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
static int F_9 ( struct V_25 * V_26 , T_3 V_27 , T_3 * V_28 )
{
struct V_29 V_30 [ 1 ] = { { . V_31 = V_27 , . V_32 = V_33 ,
. V_34 = V_28 , . V_35 = 1 }
} ;
return F_10 ( V_26 , V_30 , 1 ) ;
}
static int F_11 ( struct V_25 * V_36 , T_3 V_27 , T_3 * V_37 , int V_35 )
{
int V_38 ;
struct V_29 V_39 = {
. V_31 = V_27 , . V_32 = 0 , . V_34 = V_37 , . V_35 = V_35 } ;
F_12 ( 3 , L_1 ) ;
if ( V_40 > 2 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ )
F_13 ( V_41 L_2 , V_37 [ V_14 ] ) ;
F_13 ( V_41 L_3 ) ;
}
V_38 = F_10 ( V_36 , & V_39 , 1 ) ;
if ( V_38 >= 0 && V_38 != 1 )
V_38 = - V_42 ;
if ( V_38 < 0 )
F_13 ( V_43 L_4 , V_27 ) ;
return V_38 ;
}
static int F_14 ( struct V_25 * V_36 ,
T_3 V_27 , T_3 * V_39 , int V_35 , T_3 * V_44 , int V_45 )
{
int V_38 ;
struct V_29 V_30 [ 2 ] = {
{ . V_31 = V_27 , . V_32 = 0 ,
. V_34 = V_39 , . V_35 = V_35 } ,
{ . V_31 = V_27 , . V_32 = V_33 ,
. V_34 = V_44 , . V_35 = V_45 }
} ;
V_38 = F_10 ( V_36 , V_30 , 2 ) ;
if ( V_38 != 2 ) {
if ( V_40 > 2 )
F_13 ( V_41 L_5 ) ;
if ( V_38 >= 0 )
V_38 = - V_42 ;
F_13 ( V_43 L_6 , V_27 ) ;
return V_38 ;
}
if ( V_40 > 2 ) {
int V_14 ;
F_12 ( 2 , L_7 ) ;
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ )
F_13 ( V_41 L_2 , V_39 [ V_14 ] ) ;
F_13 ( V_41 L_8 ) ;
for ( V_14 = 0 ; V_14 < V_45 ; V_14 ++ )
F_13 ( V_41 L_2 , V_44 [ V_14 ] ) ;
F_13 ( V_41 L_3 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_46 , T_4 * V_37 , T_3 V_32 )
{
int V_38 ;
T_3 V_27 = V_2 -> V_47 , V_48 [ 4 ] , V_49 [ 2 ] , V_35 ;
if ( V_2 -> V_50 )
V_32 |= 0xC0 ;
if ( F_16 ( V_46 ) || ( V_32 != 0 ) ) {
V_48 [ 0 ] = ( ( ( V_46 << 1 ) & 0xFF ) | 0x01 ) ;
V_48 [ 1 ] = ( ( V_46 >> 16 ) & 0xFF ) ;
V_48 [ 2 ] = ( ( V_46 >> 24 ) & 0xFF ) | V_32 ;
V_48 [ 3 ] = ( ( V_46 >> 7 ) & 0xFF ) ;
V_35 = 4 ;
} else {
V_48 [ 0 ] = ( ( V_46 << 1 ) & 0xFF ) ;
V_48 [ 1 ] = ( ( ( V_46 >> 16 ) & 0x0F ) | ( ( V_46 >> 18 ) & 0xF0 ) ) ;
V_35 = 2 ;
}
F_12 ( 2 , L_9 , V_46 , V_32 ) ;
V_38 = F_14 ( V_2 -> V_51 , V_27 , V_48 , V_35 , V_49 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_37 )
* V_37 = V_49 [ 0 ] | ( V_49 [ 1 ] << 8 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_46 , T_4 * V_37 )
{
return F_15 ( V_2 , V_46 , V_37 , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_46 , T_1 * V_37 , T_3 V_32 )
{
int V_38 ;
T_3 V_27 = V_2 -> V_47 , V_48 [ 4 ] , V_49 [ 4 ] , V_35 ;
if ( V_2 -> V_50 )
V_32 |= 0xC0 ;
if ( F_16 ( V_46 ) || ( V_32 != 0 ) ) {
V_48 [ 0 ] = ( ( ( V_46 << 1 ) & 0xFF ) | 0x01 ) ;
V_48 [ 1 ] = ( ( V_46 >> 16 ) & 0xFF ) ;
V_48 [ 2 ] = ( ( V_46 >> 24 ) & 0xFF ) | V_32 ;
V_48 [ 3 ] = ( ( V_46 >> 7 ) & 0xFF ) ;
V_35 = 4 ;
} else {
V_48 [ 0 ] = ( ( V_46 << 1 ) & 0xFF ) ;
V_48 [ 1 ] = ( ( ( V_46 >> 16 ) & 0x0F ) | ( ( V_46 >> 18 ) & 0xF0 ) ) ;
V_35 = 2 ;
}
F_12 ( 2 , L_9 , V_46 , V_32 ) ;
V_38 = F_14 ( V_2 -> V_51 , V_27 , V_48 , V_35 , V_49 , 4 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_37 )
* V_37 = V_49 [ 0 ] | ( V_49 [ 1 ] << 8 ) |
( V_49 [ 2 ] << 16 ) | ( V_49 [ 3 ] << 24 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_46 , T_1 * V_37 )
{
return F_18 ( V_2 , V_46 , V_37 , 0 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_46 , T_4 V_37 , T_3 V_32 )
{
T_3 V_27 = V_2 -> V_47 , V_52 [ 6 ] , V_35 ;
if ( V_2 -> V_50 )
V_32 |= 0xC0 ;
if ( F_16 ( V_46 ) || ( V_32 != 0 ) ) {
V_52 [ 0 ] = ( ( ( V_46 << 1 ) & 0xFF ) | 0x01 ) ;
V_52 [ 1 ] = ( ( V_46 >> 16 ) & 0xFF ) ;
V_52 [ 2 ] = ( ( V_46 >> 24 ) & 0xFF ) | V_32 ;
V_52 [ 3 ] = ( ( V_46 >> 7 ) & 0xFF ) ;
V_35 = 4 ;
} else {
V_52 [ 0 ] = ( ( V_46 << 1 ) & 0xFF ) ;
V_52 [ 1 ] = ( ( ( V_46 >> 16 ) & 0x0F ) | ( ( V_46 >> 18 ) & 0xF0 ) ) ;
V_35 = 2 ;
}
V_52 [ V_35 ] = V_37 & 0xff ;
V_52 [ V_35 + 1 ] = ( V_37 >> 8 ) & 0xff ;
F_12 ( 2 , L_10 , V_46 , V_37 , V_32 ) ;
return F_11 ( V_2 -> V_51 , V_27 , V_52 , V_35 + 2 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_46 , T_4 V_37 )
{
return F_20 ( V_2 , V_46 , V_37 , 0 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_46 , T_1 V_37 , T_3 V_32 )
{
T_3 V_27 = V_2 -> V_47 , V_52 [ 8 ] , V_35 ;
if ( V_2 -> V_50 )
V_32 |= 0xC0 ;
if ( F_16 ( V_46 ) || ( V_32 != 0 ) ) {
V_52 [ 0 ] = ( ( ( V_46 << 1 ) & 0xFF ) | 0x01 ) ;
V_52 [ 1 ] = ( ( V_46 >> 16 ) & 0xFF ) ;
V_52 [ 2 ] = ( ( V_46 >> 24 ) & 0xFF ) | V_32 ;
V_52 [ 3 ] = ( ( V_46 >> 7 ) & 0xFF ) ;
V_35 = 4 ;
} else {
V_52 [ 0 ] = ( ( V_46 << 1 ) & 0xFF ) ;
V_52 [ 1 ] = ( ( ( V_46 >> 16 ) & 0x0F ) | ( ( V_46 >> 18 ) & 0xF0 ) ) ;
V_35 = 2 ;
}
V_52 [ V_35 ] = V_37 & 0xff ;
V_52 [ V_35 + 1 ] = ( V_37 >> 8 ) & 0xff ;
V_52 [ V_35 + 2 ] = ( V_37 >> 16 ) & 0xff ;
V_52 [ V_35 + 3 ] = ( V_37 >> 24 ) & 0xff ;
F_12 ( 2 , L_11 , V_46 , V_37 , V_32 ) ;
return F_11 ( V_2 -> V_51 , V_27 , V_52 , V_35 + 4 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_46 , T_1 V_37 )
{
return F_22 ( V_2 , V_46 , V_37 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_53 ,
const int V_54 , const T_3 V_55 [] )
{
int V_38 = 0 , V_56 = V_54 ;
T_3 V_57 = 0 ;
if ( V_2 -> V_50 )
V_57 |= 0xC0 ;
while ( V_56 > 0 ) {
int V_58 = V_56 > V_2 -> V_59 ?
V_2 -> V_59 : V_56 ;
T_3 * V_60 = & V_2 -> V_58 [ 0 ] ;
T_1 V_61 = 0 ;
if ( F_16 ( V_53 ) || ( V_57 != 0 ) ) {
V_60 [ 0 ] = ( ( ( V_53 << 1 ) & 0xFF ) | 0x01 ) ;
V_60 [ 1 ] = ( ( V_53 >> 16 ) & 0xFF ) ;
V_60 [ 2 ] = ( ( V_53 >> 24 ) & 0xFF ) ;
V_60 [ 3 ] = ( ( V_53 >> 7 ) & 0xFF ) ;
V_60 [ 2 ] |= V_57 ;
V_61 = 4 ;
if ( V_58 == V_2 -> V_59 )
V_58 -= 2 ;
} else {
V_60 [ 0 ] = ( ( V_53 << 1 ) & 0xFF ) ;
V_60 [ 1 ] = ( ( ( V_53 >> 16 ) & 0x0F ) |
( ( V_53 >> 18 ) & 0xF0 ) ) ;
V_61 = 2 ;
}
memcpy ( & V_2 -> V_58 [ V_61 ] , V_55 , V_58 ) ;
F_12 ( 2 , L_9 , V_53 , V_57 ) ;
if ( V_40 > 1 ) {
int V_14 ;
if ( V_55 )
for ( V_14 = 0 ; V_14 < V_58 ; V_14 ++ )
F_13 ( V_41 L_2 , V_55 [ V_14 ] ) ;
F_13 ( V_41 L_3 ) ;
}
V_38 = F_11 ( V_2 -> V_51 , V_2 -> V_47 ,
& V_2 -> V_58 [ 0 ] , V_58 + V_61 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_12 ,
V_62 , V_53 ) ;
break;
}
V_55 += V_58 ;
V_53 += ( V_58 >> 1 ) ;
V_56 -= V_58 ;
}
return V_38 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_38 ;
T_3 V_37 = 0 ;
T_4 V_63 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_9 ( V_2 -> V_51 , V_2 -> V_47 , & V_37 ) ;
if ( V_38 < 0 ) {
do {
V_37 = 0 ;
V_38 = F_11 ( V_2 -> V_51 , V_2 -> V_47 ,
& V_37 , 1 ) ;
F_26 ( 10 ) ;
V_63 ++ ;
if ( V_38 < 0 )
continue;
V_38 = F_9 ( V_2 -> V_51 , V_2 -> V_47 ,
& V_37 ) ;
} while ( V_38 < 0 &&
( V_63 < V_64 ) );
if ( V_38 < 0 && V_63 >= V_64 )
goto error;
}
V_38 = F_21 ( V_2 , V_65 , V_66 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_69 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_70 = V_71 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 V_72 = V_73 ;
T_1 V_74 = 0 ;
T_1 V_75 = 0 ;
T_1 V_76 = 0x7FFF ;
T_1 V_77 = 3 ;
T_1 V_78 = V_73 ;
T_1 V_79 = 0 ;
T_1 V_80 = 0 ;
T_1 V_81 = 0x7FFF ;
T_1 V_82 = 3 ;
T_1 V_83 = 9500 ;
T_1 V_84 = 4000 ;
T_1 V_85 = V_73 ;
T_1 V_86 = 0 ;
T_1 V_87 = 0 ;
T_1 V_88 = 0 ;
T_1 V_89 = 3 ;
T_1 V_90 = V_91 ;
T_1 V_92 = 0 ;
T_1 V_93 = 0 ;
T_1 V_94 = 0 ;
T_1 V_95 = 9500 ;
T_1 V_96 = 4000 ;
T_1 V_97 = 3 ;
T_1 V_98 = V_99 ;
T_1 V_100 = V_101 ;
T_1 V_102 = V_103 ;
T_1 V_104 = V_105 ;
T_1 V_106 = 0x0113 ;
T_1 V_107 = 0 ;
T_1 V_108 = V_109 ;
T_1 V_110 = 50000000 ;
T_1 V_111 = V_112 * 8 ;
T_1 V_113 = 0 ;
T_1 V_114 = 1 ;
T_1 V_115 = 0 ;
F_12 ( 1 , L_3 ) ;
V_2 -> V_116 = false ;
V_2 -> V_117 = false ;
V_2 -> V_118 = false ;
V_2 -> V_119 = false ;
V_2 -> V_120 = false ;
V_2 -> V_121 = false ;
if ( ! V_2 -> V_59 )
V_2 -> V_59 = 124 ;
V_2 -> V_122 = 0 ;
V_2 -> V_123 = false ;
V_2 -> V_124 = false ;
V_2 -> V_125 = 151875 ;
V_2 -> V_126 = ( ( V_2 -> V_125 / 1000 ) *
V_127 ) / 1000 ;
if ( V_2 -> V_126 > V_128 )
V_2 -> V_126 = V_128 ;
V_2 -> V_129 = ( V_2 -> V_47 << 1 ) ;
V_2 -> V_130 = V_131 ;
V_2 -> V_132 = ( V_115 != 0 ) ;
V_2 -> V_8 = false ;
V_2 -> V_9 = false ;
V_2 -> V_133 = false ;
V_2 -> V_134 = false ;
V_2 -> V_135 = false ;
V_2 -> V_136 = false ;
V_2 -> V_137 . V_138 = ( V_72 ) ;
V_2 -> V_137 . V_139 = ( V_74 ) ;
V_2 -> V_137 . V_140 = ( V_75 ) ;
V_2 -> V_137 . V_141 = ( V_76 ) ;
V_2 -> V_137 . V_142 = ( V_77 ) ;
V_2 -> V_143 = 140 ;
V_2 -> V_144 . V_138 = ( V_78 ) ;
V_2 -> V_144 . V_139 = ( V_79 ) ;
V_2 -> V_144 . V_140 = ( V_80 ) ;
V_2 -> V_144 . V_141 = ( V_81 ) ;
V_2 -> V_144 . V_142 = ( V_82 ) ;
V_2 -> V_144 . V_145 = ( V_83 ) ;
V_2 -> V_144 . V_146 = ( V_84 ) ;
V_2 -> V_147 . V_148 = 0x07 ;
V_2 -> V_147 . V_149 = true ;
V_2 -> V_150 = V_99 ;
V_2 -> V_151 = V_101 ;
if ( V_100 <= 500 && V_98 < V_100 ) {
V_2 -> V_150 = V_98 ;
V_2 -> V_151 = V_100 ;
}
V_2 -> V_152 . V_138 = ( V_85 ) ;
V_2 -> V_152 . V_139 = ( V_86 ) ;
V_2 -> V_152 . V_140 = ( V_87 ) ;
V_2 -> V_152 . V_141 = ( V_88 ) ;
V_2 -> V_152 . V_142 = ( V_89 ) ;
V_2 -> V_153 . V_138 = ( V_90 ) ;
V_2 -> V_153 . V_139 = ( V_92 ) ;
V_2 -> V_153 . V_140 = ( V_93 ) ;
V_2 -> V_153 . V_141 = ( V_94 ) ;
V_2 -> V_153 . V_142 = ( V_97 ) ;
V_2 -> V_153 . V_145 = ( V_95 ) ;
V_2 -> V_153 . V_146 = ( V_96 ) ;
V_2 -> V_154 . V_148 = 0x04 ;
V_2 -> V_154 . V_149 = true ;
V_2 -> V_155 . V_138 = V_91 ;
V_2 -> V_155 . V_139 = 0 ;
V_2 -> V_155 . V_140 = 0 ;
V_2 -> V_155 . V_141 = 0xFFFF ;
V_2 -> V_155 . V_145 = 0x2100 ;
V_2 -> V_155 . V_146 = 4000 ;
V_2 -> V_155 . V_142 = 1 ;
V_2 -> V_156 . V_138 = V_73 ;
V_2 -> V_156 . V_139 = 0 ;
V_2 -> V_156 . V_140 = 0 ;
V_2 -> V_156 . V_141 = 9000 ;
V_2 -> V_156 . V_145 = 13424 ;
V_2 -> V_156 . V_146 = 0 ;
V_2 -> V_156 . V_142 = 3 ;
V_2 -> V_156 . V_157 = 30 ;
V_2 -> V_156 . V_158 = 30000 ;
V_2 -> V_159 . V_148 = 4 ;
V_2 -> V_159 . V_149 = false ;
V_2 -> V_160 . V_138 = V_91 ;
V_2 -> V_160 . V_139 = 0 ;
V_2 -> V_160 . V_140 = 6023 ;
V_2 -> V_160 . V_141 = 27000 ;
V_2 -> V_160 . V_145 = 0x2380 ;
V_2 -> V_160 . V_146 = 4000 ;
V_2 -> V_160 . V_142 = 3 ;
V_2 -> V_161 . V_138 = V_73 ;
V_2 -> V_161 . V_139 = 0 ;
V_2 -> V_161 . V_140 = 0 ;
V_2 -> V_161 . V_141 = 9000 ;
V_2 -> V_161 . V_145 = 0x0511 ;
V_2 -> V_161 . V_146 = 0 ;
V_2 -> V_161 . V_142 = 3 ;
V_2 -> V_161 . V_158 = 5119 ;
V_2 -> V_161 . V_157 = 50 ;
V_2 -> V_162 = 140 ;
V_2 -> V_163 . V_148 = 4 ;
V_2 -> V_163 . V_149 = false ;
V_2 -> V_3 = V_164 ;
V_2 -> V_165 = V_166 ;
V_2 -> V_167 = true ;
V_2 -> V_168 = false ;
V_2 -> V_169 = false ;
V_2 -> V_170 = false ;
V_2 -> V_171 = false ;
V_2 -> V_172 = false ;
V_2 -> V_173 = ( V_107 != 0 ) ;
V_2 -> V_174 = V_110 ;
V_2 -> V_175 = V_111 ;
V_2 -> V_176 = ( V_108 & 0x07 ) ;
V_2 -> V_177 = 19392658 ;
V_2 -> V_178 = false ;
if ( V_113 )
V_2 -> V_168 = true ;
V_2 -> V_179 = V_103 ;
if ( V_102 < 10000 )
V_2 -> V_179 = V_102 ;
V_2 -> V_180 = V_105 ;
if ( V_104 < 10000 )
V_2 -> V_180 = V_104 ;
V_2 -> V_181 = V_182 ;
V_2 -> V_183 = V_184 ;
V_2 -> V_185 = 204 * 8 ;
V_2 -> V_186 = 1 ;
V_2 -> V_187 = V_188 ;
V_2 -> V_189 = 0 ;
V_2 -> V_190 = ( V_106 ) ;
V_2 -> V_132 = false ;
V_2 -> V_70 = V_191 ;
V_2 -> V_192 = ( V_114 == 0 ) ;
V_2 -> V_193 = false ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
T_1 V_194 = 0 ;
T_4 V_195 = 0 ;
T_4 V_196 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_197 , V_198 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_199 , & V_196 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_199 , V_200 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_19 ( V_2 , V_201 , & V_194 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_202 , & V_195 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_199 , V_196 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_4 V_203 = 0 ;
T_1 V_204 = 0 ;
int V_38 ;
const char * V_205 = L_14 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_197 , V_198 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_199 , 0xFABA ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_206 , & V_203 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_199 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
switch ( ( V_203 & V_207 ) ) {
case 0 :
break;
case 1 :
V_2 -> V_122 = 27000 ;
break;
case 2 :
V_2 -> V_122 = 20250 ;
break;
case 3 :
V_2 -> V_122 = 20250 ;
break;
default:
F_13 ( V_43 L_15 ) ;
return - V_208 ;
}
V_38 = F_19 ( V_2 , V_201 , & V_204 ) ;
if ( V_38 < 0 )
goto error;
F_13 ( V_43 L_16 , V_204 ) ;
switch ( ( V_204 >> 29 ) & 0xF ) {
case 0 :
V_2 -> V_209 = V_210 ;
V_205 = L_17 ;
break;
case 2 :
V_2 -> V_209 = V_211 ;
V_205 = L_18 ;
break;
case 3 :
V_2 -> V_209 = V_212 ;
V_205 = L_19 ;
break;
default:
V_2 -> V_209 = V_213 ;
V_38 = - V_208 ;
F_13 ( V_43 L_20 ,
( V_204 >> 29 ) & 0xF ) ;
goto V_214;
}
switch ( ( V_204 >> 12 ) & 0xFF ) {
case 0x13 :
V_2 -> V_116 = false ;
V_2 -> V_120 = false ;
V_2 -> V_119 = false ;
V_2 -> V_121 = false ;
V_2 -> V_117 = true ;
V_2 -> V_118 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = false ;
V_2 -> V_217 = false ;
V_2 -> V_218 = false ;
break;
case 0x15 :
V_2 -> V_116 = false ;
V_2 -> V_120 = false ;
V_2 -> V_119 = true ;
V_2 -> V_121 = false ;
V_2 -> V_117 = true ;
V_2 -> V_118 = false ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = true ;
V_2 -> V_218 = false ;
break;
case 0x16 :
V_2 -> V_116 = false ;
V_2 -> V_120 = false ;
V_2 -> V_119 = true ;
V_2 -> V_121 = false ;
V_2 -> V_117 = true ;
V_2 -> V_118 = false ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = true ;
V_2 -> V_218 = false ;
break;
case 0x18 :
V_2 -> V_116 = false ;
V_2 -> V_120 = false ;
V_2 -> V_119 = true ;
V_2 -> V_121 = true ;
V_2 -> V_117 = true ;
V_2 -> V_118 = false ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = true ;
V_2 -> V_218 = false ;
break;
case 0x21 :
V_2 -> V_116 = false ;
V_2 -> V_120 = false ;
V_2 -> V_119 = true ;
V_2 -> V_121 = true ;
V_2 -> V_117 = true ;
V_2 -> V_118 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = true ;
V_2 -> V_218 = false ;
break;
case 0x23 :
V_2 -> V_116 = false ;
V_2 -> V_120 = false ;
V_2 -> V_119 = true ;
V_2 -> V_121 = true ;
V_2 -> V_117 = true ;
V_2 -> V_118 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = true ;
V_2 -> V_218 = false ;
break;
case 0x25 :
V_2 -> V_116 = false ;
V_2 -> V_120 = false ;
V_2 -> V_119 = true ;
V_2 -> V_121 = true ;
V_2 -> V_117 = true ;
V_2 -> V_118 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = true ;
V_2 -> V_218 = false ;
break;
case 0x26 :
V_2 -> V_116 = false ;
V_2 -> V_120 = false ;
V_2 -> V_119 = true ;
V_2 -> V_121 = false ;
V_2 -> V_117 = true ;
V_2 -> V_118 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = true ;
V_2 -> V_218 = false ;
break;
default:
F_13 ( V_43 L_21 ,
( ( V_204 >> 12 ) & 0xFF ) ) ;
V_38 = - V_208 ;
goto V_214;
}
F_13 ( V_219
L_22 ,
( ( V_204 >> 12 ) & 0xFF ) , V_205 ,
V_2 -> V_122 / 1000 ,
V_2 -> V_122 % 1000 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_214:
return V_38 ;
}
static int F_30 ( struct V_1 * V_2 , T_4 V_220 , T_4 * V_221 )
{
int V_38 ;
bool V_222 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_223 , V_220 ) ;
if ( V_38 < 0 )
goto error;
if ( V_220 == V_224 )
F_26 ( 1 ) ;
V_222 =
( bool ) ( ( V_220 == V_225 ) &&
( ( V_2 -> V_130 ) &
V_226 ) ==
V_227 ) ;
if ( V_222 == false ) {
T_1 V_63 = 0 ;
T_4 V_228 ;
do {
F_26 ( 1 ) ;
V_63 += 1 ;
V_38 = F_17 ( V_2 , V_223 ,
& V_228 ) ;
} while ( ( V_38 < 0 ) && ( V_63 < V_229 )
&& ( V_228 != 0 ) );
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_230 , V_221 ) ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
F_32 ( & V_2 -> V_231 ) ;
V_38 = F_21 ( V_2 , V_232 , V_2 -> V_233 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_234 , V_2 -> V_130 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_235 , V_2 -> V_129 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_236 , V_2 -> V_237 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_238 , V_2 -> V_126 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_239 , V_240 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_30 ( V_2 , V_225 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_130 &= ~ V_227 ;
error:
F_33 ( & V_2 -> V_231 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_34 ( struct V_1 * V_2 )
{
F_12 ( 1 , L_3 ) ;
V_2 -> V_129 = ( V_2 -> V_47 << 1 ) ;
V_2 -> V_233 = 0x96FF ;
V_2 -> V_130 = V_131 ;
return F_31 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 , bool V_241 )
{
int V_38 = - 1 ;
T_4 V_242 = 0 ;
T_4 V_243 = 0 ;
T_4 V_244 = 0 ;
F_12 ( 1 , L_23 ,
V_241 ? L_24 : L_25 ,
V_2 -> V_245 ? L_26 : L_27 ) ;
V_38 = F_21 ( V_2 , V_197 , V_198 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_199 , 0xFABA ) ;
if ( V_38 < 0 )
goto error;
if ( V_241 == false ) {
V_38 = F_21 ( V_2 , V_246 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_247 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_248 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_249 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_250 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_251 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_252 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_253 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_254 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_255 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_256 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_257 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_243 =
( ( V_2 -> V_176 <<
V_258 ) | 0x0003 ) ;
V_242 = ( ( V_2 -> V_259 <<
V_260 ) |
0x0003 ) ;
V_38 = F_21 ( V_2 , V_246 , V_243 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_261 )
V_244 = V_243 ;
V_38 = F_21 ( V_2 , V_247 , V_244 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_249 , V_244 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_245 == true ) {
V_38 = F_21 ( V_2 , V_251 , V_243 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_252 , V_243 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_253 , V_243 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_254 , V_243 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_255 , V_243 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_256 , V_243 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_257 , V_243 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_243 = ( ( V_2 -> V_176 <<
V_258 )
| 0x0003 ) ;
V_38 = F_21 ( V_2 , V_251 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_252 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_253 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_254 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_255 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_256 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_257 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_248 , V_242 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_250 , V_243 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_262 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_199 , 0x0000 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_36 ( struct V_1 * V_2 )
{
F_12 ( 1 , L_3 ) ;
return F_35 ( V_2 , false ) ;
}
static int F_37 ( struct V_1 * V_2 ,
T_4 V_263 , T_4 V_264 , T_1 V_265 )
{
T_4 V_266 = 0 ;
int V_38 ;
unsigned long V_267 ;
F_12 ( 1 , L_3 ) ;
F_32 ( & V_2 -> V_231 ) ;
V_38 = F_21 ( V_2 , V_268 , V_269 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_270 , V_263 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_271 , V_264 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_272 , V_273 ) ;
if ( V_38 < 0 )
goto error;
V_267 = V_274 + F_38 ( V_265 ) ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_275 , & V_266 ) ;
if ( V_38 < 0 )
goto error;
} while ( ( V_266 == 0x1 ) &&
( ( F_39 ( V_267 ) ) ) );
if ( V_266 == 0x1 ) {
F_13 ( V_43 L_28 ) ;
V_38 = - V_208 ;
goto V_214;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_214:
F_33 ( & V_2 -> V_231 ) ;
return V_38 ;
}
static int F_40 ( struct V_1 * V_2 ,
const T_3 V_276 [] , T_1 V_277 )
{
const T_3 * V_278 = V_276 ;
T_4 V_57 ;
T_4 V_279 ;
T_1 V_53 ;
T_4 V_280 ;
T_4 V_54 ;
T_4 V_281 ;
T_1 V_282 = 0 ;
T_1 V_14 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_279 = ( V_278 [ 0 ] << 8 ) | V_278 [ 1 ] ;
V_278 += sizeof( T_4 ) ;
V_282 += sizeof( T_4 ) ;
V_280 = ( V_278 [ 0 ] << 8 ) | V_278 [ 1 ] ;
V_278 += sizeof( T_4 ) ;
V_282 += sizeof( T_4 ) ;
for ( V_14 = 0 ; V_14 < V_280 ; V_14 += 1 ) {
V_53 = ( V_278 [ 0 ] << 24 ) | ( V_278 [ 1 ] << 16 ) |
( V_278 [ 2 ] << 8 ) | V_278 [ 3 ] ;
V_278 += sizeof( T_1 ) ;
V_282 += sizeof( T_1 ) ;
V_54 = ( ( V_278 [ 0 ] << 8 ) | V_278 [ 1 ] ) * sizeof( T_4 ) ;
V_278 += sizeof( T_4 ) ;
V_282 += sizeof( T_4 ) ;
V_57 = ( V_278 [ 0 ] << 8 ) | V_278 [ 1 ] ;
V_278 += sizeof( T_4 ) ;
V_282 += sizeof( T_4 ) ;
V_281 = ( V_278 [ 0 ] << 8 ) | V_278 [ 1 ] ;
V_278 += sizeof( T_4 ) ;
V_282 += sizeof( T_4 ) ;
if ( V_282 + V_54 > V_277 ) {
F_13 ( V_43 L_29 ) ;
return - V_208 ;
}
V_38 = F_24 ( V_2 , V_53 , V_54 , V_278 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_30 , V_38 ) ;
break;
}
V_278 += V_54 ;
V_282 += V_54 ;
}
return V_38 ;
}
static int F_41 ( struct V_1 * V_2 , bool V_283 )
{
int V_38 ;
T_4 V_37 = 0 ;
T_4 V_284 = V_285 ;
T_4 V_286 = V_287 ;
unsigned long V_267 ;
F_12 ( 1 , L_3 ) ;
if ( V_283 == false ) {
V_284 = V_288 ;
V_286 = V_289 ;
}
V_38 = F_17 ( V_2 , V_290 , & V_37 ) ;
if ( V_38 >= 0 && V_37 == V_286 ) {
return V_38 ;
}
V_38 = F_21 ( V_2 , V_291 , V_284 ) ;
V_267 = V_274 + F_38 ( V_292 ) ;
do {
V_38 = F_17 ( V_2 , V_290 , & V_37 ) ;
if ( ( V_38 >= 0 && V_37 == V_286 ) || F_39 ( V_267 ) )
break;
F_26 ( 1 ) ;
} while ( 1 );
if ( V_37 != V_286 ) {
F_13 ( V_43 L_28 ) ;
return - V_208 ;
}
return V_38 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
T_4 V_293 = 0 ;
T_4 V_294 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_295 , & V_293 ) ;
if ( V_38 < 0 )
goto error;
V_293 |= V_296 ;
V_38 = F_21 ( V_2 , V_295 , V_293 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_297 , & V_294 ) ;
if ( V_38 < 0 )
goto error;
V_294 |= V_298 ;
V_38 = F_21 ( V_2 , V_297 , V_294 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_4 V_220 , T_3 V_299 ,
T_4 * V_300 , T_3 V_301 , T_4 * V_302 )
{
#if ( V_303 - V_304 ) != 15
#error DRXK register mapping no longer compatible with this routine!
#endif
T_4 V_305 = 0 ;
int V_38 = - V_208 ;
unsigned long V_267 ;
T_3 V_306 [ 34 ] ;
int V_307 = 0 , V_308 ;
const char * V_309 ;
char V_310 [ 30 ] ;
F_12 ( 1 , L_3 ) ;
if ( ( V_220 == 0 ) || ( ( V_299 > 0 ) && ( V_300 == NULL ) ) ||
( ( V_301 > 0 ) && ( V_302 == NULL ) ) ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
F_32 ( & V_2 -> V_231 ) ;
for ( V_308 = V_299 - 1 ; V_308 >= 0 ; V_308 -= 1 ) {
V_306 [ V_307 ++ ] = ( V_300 [ V_308 ] & 0xFF ) ;
V_306 [ V_307 ++ ] = ( ( V_300 [ V_308 ] >> 8 ) & 0xFF ) ;
}
V_306 [ V_307 ++ ] = ( V_220 & 0xFF ) ;
V_306 [ V_307 ++ ] = ( ( V_220 >> 8 ) & 0xFF ) ;
F_24 ( V_2 , V_303 -
( V_299 - 1 ) , V_307 , V_306 ) ;
V_267 = V_274 + F_38 ( V_311 ) ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_312 , & V_305 ) ;
if ( V_38 < 0 )
goto error;
} while ( ! ( V_305 == V_313 ) && ( F_39 ( V_267 ) ) );
if ( V_305 != V_313 ) {
F_13 ( V_43 L_31 ) ;
V_38 = - V_42 ;
goto V_214;
}
if ( ( V_301 > 0 ) && ( V_302 != NULL ) ) {
T_5 V_314 ;
int V_308 ;
for ( V_308 = V_301 - 1 ; V_308 >= 0 ; V_308 -= 1 ) {
V_38 = F_17 ( V_2 , V_303 - V_308 , & V_302 [ V_308 ] ) ;
if ( V_38 < 0 )
goto error;
}
V_314 = ( T_5 ) V_302 [ 0 ] ;
if ( V_314 >= 0 )
goto error;
switch ( V_314 ) {
case V_315 :
V_309 = L_32 ;
break;
case V_316 :
V_309 = L_33 ;
break;
case V_317 :
V_309 = L_34 ;
break;
case V_318 :
V_309 = L_35 ;
break;
default:
sprintf ( V_310 , L_36 , V_314 ) ;
V_309 = V_310 ;
}
F_13 ( V_43 L_37 , V_309 , V_220 ) ;
F_44 ( L_38 , V_319 , V_306 , V_307 ) ;
V_38 = - V_208 ;
goto V_214;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_214:
F_33 ( & V_2 -> V_231 ) ;
return V_38 ;
}
static int F_45 ( struct V_1 * V_2 , bool V_320 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_321 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_320 ) {
V_37 |= ( V_322
| V_323
| V_324
| V_325
| V_326 ) ;
} else {
V_37 &= ( ( ~ V_322 )
& ( ~ V_323 )
& ( ~ V_324 )
& ( ~ V_325 )
& ( ~ V_326 )
) ;
}
V_38 = F_21 ( V_2 , V_321 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_46 ( struct V_1 * V_2 , enum V_327 * V_328 )
{
int V_38 = 0 ;
T_4 V_329 = 0 ;
F_12 ( 1 , L_3 ) ;
if ( V_328 == NULL )
return - V_208 ;
switch ( * V_328 ) {
case V_71 :
V_329 = V_66 ;
break;
case V_330 :
V_329 = V_331 ;
break;
case V_332 :
V_329 = V_333 ;
break;
case V_334 :
V_329 = V_335 ;
break;
case V_191 :
V_329 = V_336 ;
break;
default:
return - V_208 ;
}
if ( V_2 -> V_70 == * V_328 )
return 0 ;
if ( V_2 -> V_70 != V_71 ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_41 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
}
if ( * V_328 == V_71 ) {
} else {
switch ( V_2 -> V_3 ) {
case V_4 :
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_47 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
break;
case V_5 :
case V_7 :
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_48 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
break;
}
V_38 = F_41 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_65 , V_329 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
if ( * V_328 != V_330 ) {
V_2 -> V_130 |=
V_227 ;
V_38 = F_31 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
}
}
V_2 -> V_70 = * V_328 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_47 ( struct V_1 * V_2 , bool V_337 )
{
enum V_327 V_338 = V_330 ;
T_4 V_339 = 0 ;
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_340 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == V_341 ) {
V_38 = F_43 ( V_2 , V_342 | V_343 , 0 , NULL , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_342 | V_344 , 0 , NULL , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_347 , V_348 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_349 , V_350 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
if ( V_337 ) {
V_38 = F_46 ( V_2 , & V_338 ) ;
if ( V_38 < 0 )
goto error;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_49 ( struct V_1 * V_2 ,
enum V_351 V_352 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_197 , V_198 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_3 == V_352 )
return 0 ;
switch ( V_2 -> V_3 ) {
case V_164 :
break;
case V_4 :
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_47 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_3 = V_164 ;
break;
case V_5 :
case V_7 :
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_48 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_3 = V_164 ;
break;
case V_6 :
default:
V_38 = - V_208 ;
goto error;
}
switch ( V_352 ) {
case V_4 :
F_12 ( 1 , L_39 ) ;
V_2 -> V_3 = V_352 ;
V_38 = F_50 ( V_2 , V_352 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_5 :
case V_7 :
F_12 ( 1 , L_40 ,
( V_2 -> V_3 == V_5 ) ? 'A' : 'C' ) ;
V_2 -> V_3 = V_352 ;
V_38 = F_51 ( V_2 , V_352 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_6 :
default:
V_38 = - V_208 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_52 ( struct V_1 * V_2 , T_6 V_353 ,
T_6 V_354 )
{
int V_38 = - V_208 ;
T_4 V_355 ;
T_6 V_356 = V_353 / 1000 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_165 != V_357 &&
V_2 -> V_165 != V_358 )
goto error;
V_2 -> V_359 = ( V_2 -> V_360 . V_361 == V_362 ) ;
if ( V_354 < 0 ) {
V_2 -> V_359 = ! V_2 -> V_359 ;
V_354 = - V_354 ;
}
switch ( V_2 -> V_3 ) {
case V_5 :
case V_7 :
V_355 = ( V_354 / 1000 ) ;
V_38 = F_53 ( V_2 , V_355 , V_356 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_165 = V_358 ;
break;
case V_4 :
V_355 = ( V_354 / 1000 ) ;
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_54 ( V_2 , V_355 , V_356 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_55 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_165 = V_358 ;
break;
default:
break;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_56 ( struct V_1 * V_2 )
{
F_12 ( 1 , L_3 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 * V_363 ,
T_1 Time )
{
int V_38 = - V_208 ;
F_12 ( 1 , L_3 ) ;
if ( V_363 == NULL )
goto error;
* V_363 = V_364 ;
switch ( V_2 -> V_3 ) {
case V_5 :
case V_6 :
case V_7 :
V_38 = F_58 ( V_2 , V_363 ) ;
break;
case V_4 :
V_38 = F_59 ( V_2 , V_363 ) ;
break;
default:
break;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_293 = 0 ;
V_38 = F_17 ( V_2 , V_295 , & V_293 ) ;
if ( V_38 < 0 )
goto error;
V_293 &= ~ V_296 ;
V_38 = F_21 ( V_2 , V_295 , V_293 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_365 , 1 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_366 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_367 , 0x000C ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_368 , 0x000A ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_369 , 0x0008 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_370 , 0x0006 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_371 , 0x0680 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_372 , 0x0080 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_373 , 0x03F4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_374 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_375 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_376 , 12 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_62 ( struct V_1 * V_2 ,
enum V_351 V_352 )
{
int V_38 ;
T_4 V_377 = 0 ;
T_4 V_378 = 0 ;
T_4 V_379 = 0 ;
T_4 V_380 = 0 ;
T_4 V_381 = 2 ;
T_4 V_382 = 188 ;
T_1 V_383 = 0 ;
T_4 V_384 = 0 ;
T_4 V_385 = 0 ;
T_1 V_386 = 0 ;
bool V_387 = false ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_388 , & V_377 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_297 , & V_378 ) ;
if ( V_38 < 0 )
goto error;
V_377 &= ( ~ V_389 ) ;
V_378 &= ( ~ V_390 ) ;
if ( V_2 -> V_168 == true ) {
V_377 |= V_389 ;
V_378 |= V_390 ;
V_382 = 204 ;
}
V_378 &= ( ~ ( V_391 ) ) ;
if ( V_2 -> V_245 == false ) {
V_378 |= V_391 ;
}
switch ( V_352 ) {
case V_4 :
V_386 = V_2 -> V_174 ;
V_384 = 3 ;
V_383 = 0xC00000 ;
V_387 = V_2 -> V_392 ;
break;
case V_5 :
case V_7 :
V_384 = 0x0004 ;
V_383 = 0xD2B4EE ;
V_386 = V_2 -> V_175 ;
V_387 = V_2 -> V_393 ;
break;
default:
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
if ( V_387 ) {
T_1 V_394 = 0 ;
V_379 = ( V_395 |
V_396 ) ;
V_380 = ( V_397 |
V_398 ) ;
V_394 = V_386 ;
if ( V_394 > 75900000UL ) {
V_394 = 75900000UL ;
}
V_381 = ( T_4 ) ( ( ( V_2 -> V_125 )
* 1000 ) / V_394 ) ;
if ( V_381 <= 2 )
V_381 = 0 ;
else
V_381 -= 2 ;
V_385 = 8 ;
} else {
V_379 = V_395 ;
V_380 = V_399 ;
V_385 = 5 ;
}
V_38 = F_21 ( V_2 , V_400 , V_382 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_401 , V_381 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_402 , V_379 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_403 , V_380 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_388 , V_377 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_297 , V_378 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_23 ( V_2 , V_404 , V_383 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_405 , V_385 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_406 , V_384 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_4 V_407 = 0 ;
T_4 V_408 =
V_409 | V_410 |
V_411 | V_412 |
V_413 | V_414 |
V_415 | V_416 ;
F_12 ( 1 , L_3 ) ;
V_407 &= ( ~ ( V_408 ) ) ;
if ( V_2 -> V_169 == true )
V_407 |= V_408 ;
V_407 &= ( ~ ( V_417 ) ) ;
if ( V_2 -> V_170 == true )
V_407 |= V_417 ;
V_407 &= ( ~ ( V_418 ) ) ;
if ( V_2 -> V_171 == true )
V_407 |= V_418 ;
V_407 &= ( ~ ( V_419 ) ) ;
if ( V_2 -> V_172 == true )
V_407 |= V_419 ;
V_407 &= ( ~ ( V_420 ) ) ;
if ( V_2 -> V_173 == true )
V_407 |= V_420 ;
return F_21 ( V_2 , V_421 , V_407 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_422 * V_423 , bool V_424 )
{
int V_38 = - V_208 ;
T_4 V_37 = 0 ;
struct V_422 * V_425 ;
F_12 ( 1 , L_3 ) ;
if ( V_423 == NULL )
goto error;
switch ( V_423 -> V_138 ) {
case V_73 :
V_38 = F_17 ( V_2 , V_321 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_326 ;
V_38 = F_21 ( V_2 , V_321 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_426 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_427 ;
if ( V_2 -> V_428 )
V_37 |= V_429 ;
else
V_37 &= ~ V_429 ;
V_38 = F_21 ( V_2 , V_426 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_430 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_431 ;
V_37 |= ( ~ ( V_423 -> V_142 <<
V_432 )
& V_431 ) ;
V_38 = F_21 ( V_2 , V_430 , V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( F_1 ( V_2 ) )
V_425 = & V_2 -> V_156 ;
else if ( F_2 ( V_2 ) )
V_425 = & V_2 -> V_161 ;
else
V_425 = & V_2 -> V_152 ;
if ( V_425 == NULL ) {
V_38 = - V_208 ;
goto error;
}
if ( V_425 -> V_138 == V_73 )
V_38 = F_21 ( V_2 , V_433 , V_423 -> V_145 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_434 , V_423 -> V_146 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_435 , V_423 -> V_141 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_436 :
V_38 = F_17 ( V_2 , V_321 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_326 ;
V_38 = F_21 ( V_2 , V_321 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_426 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_427 ;
if ( V_2 -> V_428 )
V_37 |= V_429 ;
else
V_37 &= ~ V_429 ;
V_38 = F_21 ( V_2 , V_426 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_434 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_437 , V_423 -> V_139 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_91 :
V_38 = F_17 ( V_2 , V_321 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_326 ;
V_38 = F_21 ( V_2 , V_321 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_426 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_427 ;
V_38 = F_21 ( V_2 , V_426 , V_37 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
V_38 = - V_208 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_422 * V_423 , bool V_424 )
{
T_4 V_37 = 0 ;
int V_38 = 0 ;
struct V_422 * V_438 ;
F_12 ( 1 , L_3 ) ;
switch ( V_423 -> V_138 ) {
case V_73 :
V_38 = F_17 ( V_2 , V_321 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_325 ;
V_38 = F_21 ( V_2 , V_321 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_426 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_439 ;
if ( V_2 -> V_193 )
V_37 |= V_440 ;
else
V_37 &= ~ V_440 ;
V_38 = F_21 ( V_2 , V_426 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_430 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_441 ;
V_37 |= ( ~ ( V_423 -> V_142 <<
V_442 )
& V_441 ) ;
V_38 = F_21 ( V_2 , V_430 , V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( F_2 ( V_2 ) )
V_438 = & V_2 -> V_160 ;
else
V_438 = & V_2 -> V_153 ;
if ( V_438 == NULL )
return - 1 ;
V_38 = F_21 ( V_2 , V_433 , V_438 -> V_145 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_436 :
V_38 = F_17 ( V_2 , V_321 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_325 ;
V_38 = F_21 ( V_2 , V_321 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_426 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_439 ;
if ( V_2 -> V_193 )
V_37 |= V_440 ;
else
V_37 &= ~ V_440 ;
V_38 = F_21 ( V_2 , V_426 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_433 , V_423 -> V_139 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_91 :
V_38 = F_17 ( V_2 , V_321 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_325 ;
V_38 = F_21 ( V_2 , V_321 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_426 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_439 ;
V_38 = F_21 ( V_2 , V_426 , V_37 ) ;
if ( V_38 < 0 )
goto error;
break;
}
V_38 = F_21 ( V_2 , V_443 , V_423 -> V_145 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 * V_444 )
{
T_4 V_445 ;
int V_38 ;
T_4 V_446 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_447 , & V_445 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
* V_444 = 0 ;
if ( V_445 > V_448 )
V_446 = V_445 - V_448 ;
if ( V_446 < 14000 )
* V_444 = ( 14000 - V_446 ) / 4 ;
else
* V_444 = 0 ;
return V_38 ;
}
static int F_67 ( struct V_1 * V_2 ,
T_6 * V_449 )
{
int V_38 = 0 ;
T_4 V_450 = 0 ;
T_1 V_451 = 0 ;
T_1 V_452 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_453 , & V_450 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return - V_208 ;
}
switch ( V_2 -> V_360 . V_454 ) {
case V_455 :
V_451 = V_456 << 2 ;
break;
case V_457 :
V_451 = V_458 << 2 ;
break;
case V_459 :
V_451 = V_460 << 2 ;
break;
case V_461 :
V_451 = V_462 << 2 ;
break;
default:
case V_463 :
V_451 = V_464 << 2 ;
break;
}
if ( V_450 > 0 ) {
V_452 = F_8 ( V_451 ) -
F_8 ( ( T_1 ) V_450 ) ;
}
* V_449 = V_452 ;
return V_38 ;
}
static int F_68 ( struct V_1 * V_2 ,
T_6 * V_449 )
{
int V_38 ;
T_4 V_465 = 0 ;
T_1 V_466 = 0 ;
T_1 V_467 = 0 ;
T_4 V_468 = 0 ;
T_4 V_469 = 0 ;
T_4 V_470 = 0 ;
T_1 V_471 = 0 ;
T_1 V_472 = 0 ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
T_1 V_473 = 0 ;
T_4 V_474 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_475 , & V_469 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_476 , & V_470 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_477 , & V_468 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_478 , & V_465 ) ;
if ( V_38 < 0 )
goto error;
V_466 = ( T_1 ) V_465 ;
if ( ( V_468 > 11 ) &&
( V_466 < 0x00000FFFUL ) ) {
V_466 += 0x00010000UL ;
}
V_38 = F_17 ( V_2 , V_479 , & V_465 ) ;
if ( V_38 < 0 )
goto error;
V_467 = ( T_1 ) V_465 ;
if ( ( V_468 > 11 ) &&
( V_467 < 0x00000FFFUL ) )
V_467 += 0x00010000UL ;
V_38 = F_17 ( V_2 , V_480 , & V_474 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_469 == 0 ) || ( V_470 == 0 ) )
V_473 = 0 ;
else if ( ( V_466 + V_467 ) == 0 ) {
V_473 = 0 ;
} else {
V_472 = ( V_466 + V_467 ) <<
V_468 ;
if ( ( V_474 &
V_481 )
== V_482 )
V_471 = 17 ;
else
V_471 = 68 ;
V_10 = F_8 ( V_469 *
V_469 ) ;
V_11 = F_8 ( V_470 * V_471 ) ;
V_12 = F_8 ( V_472 ) ;
V_473 = V_10 + V_11 ;
if ( V_473 > V_12 )
V_473 -= V_12 ;
else
V_473 = 0 ;
}
* V_449 = V_473 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_69 ( struct V_1 * V_2 , T_6 * V_449 )
{
F_12 ( 1 , L_3 ) ;
* V_449 = 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
return F_68 ( V_2 , V_449 ) ;
case V_5 :
case V_7 :
return F_67 ( V_2 , V_449 ) ;
default:
break;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , bool V_483 )
{
int V_38 = - V_208 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_165 == V_166 )
goto error;
if ( V_2 -> V_165 == V_484 )
goto error;
if ( V_2 -> V_485 )
return 0 ;
V_38 = F_21 ( V_2 , V_239 , V_240 ) ;
if ( V_38 < 0 )
goto error;
if ( V_483 ) {
V_38 = F_21 ( V_2 , V_238 , V_486 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_38 = F_21 ( V_2 , V_238 , V_487 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_30 ( V_2 , V_488 , 0 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_489 * V_490 )
{
int V_38 = - V_208 ;
F_12 ( 1 , L_3 ) ;
if ( ( V_490 == NULL )
|| ( V_490 -> V_148 > V_491 ) )
goto error;
V_38 = F_21 ( V_2 , V_492 , V_490 -> V_148 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 V_493 ,
T_4 V_263 , T_4 V_264 , T_1 V_265 )
{
T_4 V_266 = 0 ;
T_4 V_282 = ( T_4 ) ( ( V_493 >> 0 ) & 0x00FFFF ) ;
T_4 V_494 = ( T_4 ) ( ( V_493 >> 16 ) & 0x000FFF ) ;
int V_38 ;
unsigned long V_267 ;
F_12 ( 1 , L_3 ) ;
F_32 ( & V_2 -> V_231 ) ;
V_38 = F_21 ( V_2 , V_268 , V_495 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_496 , V_494 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_497 , V_282 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_498 , V_263 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_499 , V_264 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_272 , V_273 ) ;
if ( V_38 < 0 )
goto error;
V_267 = V_274 + F_38 ( V_265 ) ;
do {
V_38 = F_17 ( V_2 , V_275 , & V_266 ) ;
if ( V_38 < 0 )
goto error;
} while ( ( V_266 == 0x1 ) && F_39 ( V_267 ) );
if ( V_266 == 0x1 ) {
F_13 ( V_43 L_28 ) ;
V_38 = - V_208 ;
goto V_214;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_214:
F_33 ( & V_2 -> V_231 ) ;
return V_38 ;
}
static int F_73 ( struct V_1 * V_2 , T_4 * V_500 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_501 , V_502 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_503 , 1 ) ;
if ( V_38 < 0 )
goto error;
* V_500 = 0 ;
V_38 = F_17 ( V_2 , V_504 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_500 = * V_500 + 1 ;
V_38 = F_17 ( V_2 , V_505 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_500 = * V_500 + 1 ;
V_38 = F_17 ( V_2 , V_506 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_500 = * V_500 + 1 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_74 ( struct V_1 * V_2 )
{
T_4 V_500 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_73 ( V_2 , & V_500 ) ;
if ( V_38 < 0 )
goto error;
if ( V_500 == 1 ) {
T_4 V_507 = 0 ;
V_38 = F_17 ( V_2 , V_508 , & V_507 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_507 | V_509 ) ==
V_510 ) {
V_507 &= ( ~ ( V_509 ) ) ;
V_507 |=
V_511 ;
} else {
V_507 &= ( ~ ( V_509 ) ) ;
V_507 |=
V_510 ;
}
V_38 = F_21 ( V_2 , V_508 , V_507 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_73 ( V_2 , & V_500 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_500 < 2 )
V_38 = - V_208 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_4 V_512 ,
T_6 V_513 , bool V_424 )
{
bool V_514 = false ;
T_1 V_515 = V_513 ;
T_1 V_516 = 0 ;
bool V_517 = ! V_2 -> V_359 ;
T_1 V_518 ;
bool V_519 ;
int V_38 ;
T_1 V_520 ;
T_1 V_521 = ( T_1 ) ( V_2 -> V_125 / 3 ) ;
T_1 V_522 ;
bool V_523 ;
F_12 ( 1 , L_3 ) ;
if ( V_424 ) {
if ( ( V_2 -> V_3 == V_5 ) ||
( V_2 -> V_3 == V_7 ) ||
( V_2 -> V_3 == V_4 ) )
V_514 = true ;
else
V_514 = false ;
}
if ( V_517 )
V_520 = V_512 +
V_515 + V_516 ;
else
V_520 = V_512 -
V_515 - V_516 ;
if ( V_520 > V_521 / 2 ) {
V_518 = V_521 - V_520 ;
V_519 = true ;
} else {
V_518 = V_520 ;
V_519 = false ;
}
V_522 = V_518 ;
V_523 = V_2 -> V_192 ^ V_517 ^
V_519 ^ V_514 ;
V_2 -> V_524 =
F_7 ( ( V_522 ) , V_521 ) ;
if ( V_523 )
V_2 -> V_524 = ~ V_2 -> V_524 + 1 ;
V_38 = F_23 ( V_2 , V_525 ,
V_2 -> V_524 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_76 ( struct V_1 * V_2 , bool V_424 )
{
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
T_4 V_536 = 0 ;
T_4 V_537 = 0 ;
T_4 V_538 = 0 ;
T_4 V_539 = 0 ;
T_4 V_37 = 0 ;
T_4 V_540 = 0 ;
T_4 V_541 = 0 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_533 = 1023 ;
V_538 = 2047 ;
V_529 = 500 ;
V_534 = 1023 ;
if ( ! F_2 ( V_2 ) ) {
F_13 ( V_43 L_41 , V_62 , V_2 -> V_3 ) ;
return - V_208 ;
}
V_530 = 8 ;
V_531 = ( T_4 ) - 9 ;
V_541 = 0 ;
V_532 = 8 ;
V_535 = ( T_4 ) - 9 ;
V_536 = ( T_4 ) - 1030 ;
V_539 = 0x2380 ;
V_537 = 0x2380 ;
V_527 = 0x0511 ;
V_526 = 0x0511 ;
V_528 = 5119 ;
V_540 = V_2 -> V_161 . V_157 ;
V_38 = F_21 ( V_2 , V_542 , V_540 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_543 , V_541 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_544 , V_526 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_443 , V_527 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_545 , V_528 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_546 , V_538 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_433 , V_539 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_547 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_548 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_437 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_549 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_550 , V_534 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_551 , V_533 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_552 , V_536 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_553 , V_537 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_554 , V_529 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_555 , 1023 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_556 , ( T_4 ) - 1023 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_557 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_558 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_559 , V_530 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_560 , V_532 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_561 , V_531 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_562 , V_535 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_563 , 0x7fff ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_564 , 0x0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_565 , 0x0117 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_566 , 0x0657 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_567 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_568 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_569 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_570 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_571 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_572 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_573 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_574 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_575 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_576 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_577 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 = 0x0657 ;
V_37 &= ~ V_578 ;
V_37 |= ( V_579 << V_580 ) ;
V_37 &= ~ V_581 ;
V_37 |= ( V_582 << V_583 ) ;
V_38 = F_21 ( V_2 , V_577 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_77 ( struct V_1 * V_2 , T_4 * V_584 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( V_584 == NULL )
V_38 = F_21 ( V_2 , V_585 , 0 ) ;
else
V_38 = F_17 ( V_2 , V_585 , V_584 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_78 ( struct V_1 * V_2 ,
T_4 V_220 , T_4 V_586 ,
T_4 V_587 , T_4 V_588 , T_4 V_589 ,
T_4 V_590 , T_4 V_591 )
{
T_4 V_305 = 0 ;
T_4 V_592 = 0 ;
T_4 V_593 = 0 ;
T_4 V_594 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_345 , & V_594 ) ;
if ( V_594 != 1 ) {
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
V_593 = 0 ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_595 , & V_305 ) ;
V_593 ++ ;
} while ( ( V_305 != 0 ) && ( V_593 < V_229 ) );
if ( V_593 >= V_229 && ( V_38 < 0 ) )
goto error;
switch ( V_220 ) {
case V_596 :
case V_597 :
case V_598 :
V_38 = F_21 ( V_2 , V_599 , V_586 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
break;
}
switch ( V_220 ) {
case V_596 :
case V_597 :
case V_598 :
V_38 = F_21 ( V_2 , V_600 , V_588 ) ;
case V_601 :
case V_602 :
V_38 = F_21 ( V_2 , V_603 , V_587 ) ;
case V_604 :
case V_605 :
V_38 = F_21 ( V_2 , V_595 , V_220 ) ;
break;
default:
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
V_593 = 0 ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_595 , & V_305 ) ;
V_593 ++ ;
} while ( ( V_305 != 0 ) && ( V_593 < V_229 ) );
if ( V_593 >= V_229 && ( V_38 < 0 ) )
goto error;
V_38 = F_17 ( V_2 , V_599 , & V_592 ) ;
if ( V_592 == 0xFFFF ) {
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
switch ( V_220 ) {
case V_602 :
case V_604 :
V_38 = F_17 ( V_2 , V_603 , & ( V_587 ) ) ;
case V_601 :
case V_606 :
case V_596 :
case V_597 :
case V_598 :
case V_605 :
break;
default:
V_38 = - V_208 ;
break;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_79 ( struct V_1 * V_2 )
{
enum V_327 V_338 = V_71 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_46 ( V_2 , & V_338 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_80 ( struct V_1 * V_2 , bool * V_607 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( * V_607 == true )
V_38 = F_21 ( V_2 , V_608 , 0 ) ;
else
V_38 = F_21 ( V_2 , V_608 , 1 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_81 ( struct V_1 * V_2 , bool * V_607 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( * V_607 == true ) {
V_38 = F_21 ( V_2 , V_609 ,
V_610 ) ;
} else {
V_38 = F_21 ( V_2 , V_609 , 0 ) ;
}
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_611 * V_612 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_613 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_612 -> V_614 ) {
case V_615 :
V_37 &= ~ V_616 ;
V_37 |= ( ( V_612 -> V_617 <<
V_618 )
& ( V_616 ) ) ;
break;
case V_619 :
V_37 &= ~ V_620 ;
V_37 |= ( ( V_612 -> V_617 <<
V_621 )
& ( V_620 ) ) ;
break;
default:
return - V_208 ;
}
V_38 = F_21 ( V_2 , V_613 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_83 ( struct V_1 * V_2 ,
enum V_622 * V_142 )
{
int V_38 = - V_208 ;
F_12 ( 1 , L_3 ) ;
switch ( * V_142 ) {
case V_623 :
case V_188 :
case V_624 :
break;
default:
goto error;
}
V_38 = F_21 ( V_2 , V_625 ,
( T_4 ) * V_142 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_38 ;
bool V_626 = false ;
bool V_627 = true ;
struct V_611 V_628 = { 0 , V_615 } ;
struct V_611 V_629 = { 0 , V_619 } ;
F_12 ( 1 , L_3 ) ;
V_38 = F_80 ( V_2 , & V_626 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_81 ( V_2 , & V_627 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_82 ( V_2 , & V_628 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_82 ( V_2 , & V_629 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_545 , V_2 -> V_156 . V_158 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_50 ( struct V_1 * V_2 ,
enum V_351 V_352 )
{
T_4 V_339 = 0 ;
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
F_79 ( V_2 ) ;
F_85 ( V_2 ) ;
V_38 = F_43 ( V_2 , V_342 | V_344 , 0 , NULL , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_342 | V_630 , 0 , NULL , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_347 , V_348 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_349 , V_350 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_631 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_632 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_633 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_634 , V_635 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_636 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_637 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_638 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_639 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_640 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_641 , 0x4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_642 , 0x4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_643 , 1600 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_644 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_645 , 448 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_646 , 495 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_37 ( V_2 , V_647 , V_648 , V_649 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_650 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_651 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_652 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_349 , V_653 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_74 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_71 ( V_2 , & V_2 -> V_159 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_654 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_64 ( V_2 , & V_2 -> V_155 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_65 ( V_2 , & V_2 -> V_156 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_655 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_656 ;
V_38 = F_21 ( V_2 , V_655 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_341 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_134 ) {
V_38 = F_21 ( V_2 , V_542 , V_2 -> V_156 . V_157 ) ;
if ( V_38 < 0 )
goto error;
}
#ifdef F_86
V_38 = F_21 ( V_2 , V_657 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_658 , 2 ) ;
if ( V_38 < 0 )
goto error;
#endif
V_38 = F_21 ( V_2 , V_659 , 1 ) ;
if ( V_38 < 0 )
goto error;
#ifdef F_86
V_38 = F_21 ( V_2 , V_660 , 0x400 ) ;
if ( V_38 < 0 )
goto error;
#else
V_38 = F_21 ( V_2 , V_660 , 0x1000 ) ;
if ( V_38 < 0 )
goto error;
#endif
V_38 = F_21 ( V_2 , V_661 , 0x0001 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_62 ( V_2 , V_4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_84 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_55 ( struct V_1 * V_2 )
{
T_4 V_588 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_588 = V_662 ;
V_38 = F_78 ( V_2 , V_596 , 0 , V_663 , V_588 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_60 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_664 , V_665 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_54 ( struct V_1 * V_2 , T_4 V_666 ,
T_6 V_513 )
{
T_4 V_339 = 0 ;
T_4 V_474 = 0 ;
T_4 V_667 = 0 ;
T_1 V_668 = 0 ;
T_1 V_669 = 0 ;
T_4 V_588 ;
int V_38 ;
F_12 ( 1 , L_42 , V_666 , V_513 ) ;
V_38 = F_43 ( V_2 , V_342 | V_343 , 0 , NULL , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_654 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_347 , V_348 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_670 , V_671 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_360 . V_672 ) {
case V_673 :
default:
V_667 |= V_674 ;
case V_675 :
V_474 |= V_676 ;
break;
case V_677 :
V_474 |= V_482 ;
break;
}
switch ( V_2 -> V_360 . V_678 ) {
default:
case V_679 :
V_667 |= V_680 ;
case V_681 :
V_474 |= V_682 ;
break;
case V_683 :
V_474 |= V_684 ;
break;
case V_685 :
V_474 |= V_686 ;
break;
case V_687 :
V_474 |= V_688 ;
break;
}
switch ( V_2 -> V_360 . V_689 ) {
case V_690 :
case V_691 :
default:
V_667 |= V_692 ;
case V_693 :
V_474 |= V_694 ;
break;
case V_695 :
V_474 |= V_696 ;
break;
case V_697 :
V_474 |= V_698 ;
break;
}
switch ( V_2 -> V_360 . V_454 ) {
case V_699 :
default:
V_667 |= V_700 ;
case V_459 :
V_474 |= V_701 ;
break;
case V_702 :
V_474 |= V_703 ;
break;
case V_455 :
V_474 |= V_704 ;
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
V_474 |= V_705 ;
V_38 = F_21 ( V_2 , V_706 , V_707 ) ;
if ( V_38 < 0 )
goto error;
#endif
switch ( V_2 -> V_360 . V_708 ) {
case V_709 :
default:
V_667 |= V_710 ;
case V_711 :
V_474 |= V_712 ;
break;
case V_713 :
V_474 |= V_714 ;
break;
case V_715 :
V_474 |= V_716 ;
break;
case V_717 :
V_474 |= V_718 ;
break;
case V_719 :
V_474 |= V_720 ;
break;
}
switch ( V_2 -> V_360 . V_721 ) {
case 0 :
V_2 -> V_360 . V_721 = 8000000 ;
case 8000000 :
V_669 = V_722 ;
V_38 = F_21 ( V_2 , V_723 , 3052 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_724 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_725 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_726 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_727 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
case 7000000 :
V_669 = V_728 ;
V_38 = F_21 ( V_2 , V_723 , 3491 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_724 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_725 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_726 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_727 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
case 6000000 :
V_669 = V_729 ;
V_38 = F_21 ( V_2 , V_723 , 4073 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_724 , 19 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_725 , 19 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_726 , 14 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_727 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
V_38 = - V_208 ;
goto error;
}
if ( V_668 == 0 ) {
V_668 = F_7 ( ( T_1 )
( ( V_2 -> V_125 *
1000 ) / 3 ) , V_669 ) ;
if ( ( V_668 & 0x7fL ) >= 0x40 )
V_668 += 0x80L ;
V_668 = V_668 >> 7 ;
V_668 = V_668 - ( 1 << 23 ) ;
}
V_668 &=
( ( ( ( T_1 ) V_730 ) <<
V_731 ) | V_732 ) ;
V_38 = F_23 ( V_2 , V_733 , V_668 ) ;
if ( V_38 < 0 )
goto error;
#if 0
status = DVBTSetFrequencyShift(demod, channel, tunerOffset);
if (status < 0)
goto error;
#endif
V_38 = F_75 ( V_2 , V_666 , V_513 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_341 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_734 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_342 | V_735 , 0 , NULL , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
V_588 = ( V_674 |
V_680 |
V_700 |
V_692 |
V_710 ) ;
V_38 = F_78 ( V_2 , V_597 ,
0 , V_474 , V_588 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_134 )
V_38 = F_83 ( V_2 , & V_2 -> V_187 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 * V_363 )
{
int V_38 ;
const T_4 V_736 = ( V_737 |
V_738 ) ;
const T_4 V_739 = ( V_738 ) ;
const T_4 V_740 = V_741 ;
T_4 V_742 = 0 ;
T_4 V_743 = 0 ;
F_12 ( 1 , L_3 ) ;
* V_363 = V_364 ;
V_38 = F_17 ( V_2 , V_345 , & V_743 ) ;
if ( V_38 < 0 )
goto V_267;
if ( V_743 == V_346 )
goto V_267;
V_38 = F_17 ( V_2 , V_744 , & V_742 ) ;
if ( V_38 < 0 )
goto V_267;
if ( ( V_742 & V_736 ) == V_736 )
* V_363 = V_745 ;
else if ( ( V_742 & V_739 ) == V_739 )
* V_363 = V_746 ;
else if ( ( V_742 & V_740 ) == V_740 )
* V_363 = V_747 ;
else if ( V_742 & V_748 )
* V_363 = V_749 ;
V_267:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_87 ( struct V_1 * V_2 )
{
enum V_327 V_338 = V_330 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_46 ( V_2 , & V_338 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_48 ( struct V_1 * V_2 )
{
T_4 V_37 = 0 ;
T_4 V_339 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_340 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == V_341 ) {
V_38 = F_21 ( V_2 , V_750 , V_751 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_752 | V_343 , 0 , NULL , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_45 ( V_2 , false ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_88 ( struct V_1 * V_2 ,
enum V_753 V_454 ,
T_1 V_754 )
{
T_1 V_755 = 0 ;
T_1 V_756 = 0 ;
T_4 V_757 = 0 ;
T_4 V_758 = 0 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_757 = 1 ;
switch ( V_454 ) {
case V_759 :
V_755 = 4 * V_754 ;
break;
case V_760 :
V_755 = 5 * V_754 ;
break;
case V_761 :
V_755 = 6 * V_754 ;
break;
case V_762 :
V_755 = 7 * V_754 ;
break;
case V_763 :
V_755 = 8 * V_754 ;
break;
default:
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
V_755 /= 1000 ;
V_755 *= 500 ;
V_756 = ( V_755 / 1632UL ) + 1 ;
V_757 = 1 + ( T_4 ) ( V_756 >> 16 ) ;
if ( V_757 == 0 ) {
V_38 = - V_208 ;
if ( V_38 < 0 )
goto error;
}
V_758 =
( ( T_4 ) V_756 +
( V_757 >> 1 ) ) / V_757 ;
V_38 = F_21 ( V_2 , V_660 , V_758 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_661 , V_757 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_764 , V_758 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_765 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_767 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , V_456 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 32 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 95 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 120 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 230 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 105 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 220 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) - 65 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 127 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_765 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_767 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , V_458 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 90 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 170 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) - 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) - 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 26 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) - 56 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 86 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_765 , 13336 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , 12618 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_767 , 11988 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 13809 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 13809 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 15609 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , V_460 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 30 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 30 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 48 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 110 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 200 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 95 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 141 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) - 45 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 80 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_765 , 6564 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , 6598 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_767 , 6394 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 6409 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 6656 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 7238 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , V_462 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 120 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 64 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 65 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) - 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 23 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_765 , 11502 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , 12084 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_767 , 12543 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 12931 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 13629 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 15385 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , V_464 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 125 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 48 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 150 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 110 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 74 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 18 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 13 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 8 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_339 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_750 , V_751 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_752 | V_344 , 0 , NULL , 1 , & V_339 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_95 ( struct V_1 * V_2 )
{
T_1 V_817 = 0 ;
T_1 V_818 = 0 ;
T_1 V_819 = 0 ;
T_4 V_820 = 0 ;
T_1 V_821 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_817 = ( V_2 -> V_125 * 1000 ) / 3 ;
V_820 = 0 ;
if ( V_2 -> V_360 . V_822 <= 1188750 )
V_820 = 3 ;
else if ( V_2 -> V_360 . V_822 <= 2377500 )
V_820 = 2 ;
else if ( V_2 -> V_360 . V_822 <= 4755000 )
V_820 = 1 ;
V_38 = F_21 ( V_2 , V_823 , V_820 ) ;
if ( V_38 < 0 )
goto error;
V_818 = V_2 -> V_360 . V_822 * ( 1 << V_820 ) ;
if ( V_818 == 0 ) {
V_38 = - V_208 ;
goto error;
}
V_819 = ( V_817 / V_818 ) * ( 1 << 21 ) +
( F_7 ( ( V_817 % V_818 ) , V_818 ) >> 7 ) -
( 1 << 23 ) ;
V_38 = F_23 ( V_2 , V_733 , V_819 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_824 = V_819 ;
V_818 = V_2 -> V_360 . V_822 ;
if ( V_817 == 0 ) {
V_38 = - V_208 ;
goto error;
}
V_821 = ( V_818 / V_817 ) * ( 1 << 12 ) +
( F_7 ( ( V_818 % V_817 ) , V_817 ) >>
16 ) ;
if ( V_821 > 511 )
V_821 = 511 ;
V_38 = F_21 ( V_2 , V_825 , ( T_4 ) V_821 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_58 ( struct V_1 * V_2 , T_1 * V_363 )
{
int V_38 ;
T_4 V_826 [ 2 ] = { 0 , 0 } ;
F_12 ( 1 , L_3 ) ;
* V_363 = V_364 ;
V_38 = F_43 ( V_2 ,
V_752 |
V_827 , 0 , NULL , 2 ,
V_826 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_43 , V_62 , V_38 ) ;
if ( V_826 [ 1 ] < V_828 ) {
} else if ( V_826 [ 1 ] < V_829 ) {
* V_363 = V_747 ;
} else if ( V_826 [ 1 ] < V_830 ) {
* V_363 = V_745 ;
} else {
* V_363 = V_749 ;
}
return V_38 ;
}
static int F_53 ( struct V_1 * V_2 , T_4 V_666 ,
T_6 V_513 )
{
int V_38 ;
T_4 V_831 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 V_339 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_832 , V_833 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_834 , V_835 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_94 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_95 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_360 . V_454 ) {
case V_463 :
V_2 -> V_181 = V_763 ;
break;
case V_699 :
case V_459 :
V_2 -> V_181 = V_761 ;
break;
case V_455 :
V_2 -> V_181 = V_759 ;
break;
case V_457 :
V_2 -> V_181 = V_760 ;
break;
case V_461 :
V_2 -> V_181 = V_762 ;
break;
default:
V_38 = - V_208 ;
break;
}
if ( V_38 < 0 )
goto error;
V_831 [ 0 ] = V_2 -> V_181 ;
V_831 [ 1 ] = V_184 ;
if ( V_2 -> V_3 == V_7 )
V_831 [ 2 ] = V_836 ;
else
V_831 [ 2 ] = V_837 ;
V_831 [ 3 ] |= ( V_838 ) ;
V_38 = F_43 ( V_2 , V_752 | V_839 , 4 , V_831 , 1 , & V_339 ) ;
if ( V_38 < 0 ) {
if ( V_2 -> V_3 == V_7 )
V_831 [ 0 ] = V_836 ;
else
V_831 [ 0 ] = V_837 ;
V_38 = F_43 ( V_2 , V_752 | V_630 , 1 , V_831 , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
V_831 [ 0 ] = V_2 -> V_181 ;
V_831 [ 1 ] = V_184 ;
V_38 = F_43 ( V_2 , V_752 | V_839 , 2 , V_831 , 1 , & V_339 ) ;
}
if ( V_38 < 0 )
goto error;
#if 0
status = SetFrequency(channel, tunerFreqOffset));
if (status < 0)
goto error;
#endif
V_38 = F_75 ( V_2 , V_666 , V_513 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_88 ( V_2 , V_2 -> V_181 , V_2 -> V_360 . V_822 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_644 , V_840 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_841 , V_842 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_843 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_844 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_845 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_846 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_847 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_848 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_849 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_850 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_851 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_852 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_853 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_854 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_855 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_856 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_857 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_858 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_859 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_860 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_861 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_862 , V_863 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_654 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_360 . V_454 ) {
case V_455 :
V_38 = F_89 ( V_2 ) ;
break;
case V_457 :
V_38 = F_90 ( V_2 ) ;
break;
case V_699 :
case V_459 :
V_38 = F_91 ( V_2 ) ;
break;
case V_461 :
V_38 = F_92 ( V_2 ) ;
break;
case V_463 :
V_38 = F_93 ( V_2 ) ;
break;
default:
V_38 = - V_208 ;
break;
}
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_341 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_62 ( V_2 , V_2 -> V_3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_60 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_664 , V_665 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_750 , V_864 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_349 , V_653 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_752 | V_735 , 0 , NULL , 1 , & V_339 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_351 V_352 )
{
int V_38 ;
#ifdef F_96
#define F_97
#include "drxk_filters.h"
#undef F_97
#endif
F_12 ( 1 , L_3 ) ;
F_98 ( V_2 ) ;
V_38 = F_87 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_94 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_349 , V_350 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_634 , V_635 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_352 ) {
case V_5 :
V_38 = F_37 ( V_2 , V_865 , V_648 , V_649 ) ;
break;
case V_7 :
V_38 = F_72 ( V_2 , V_866 , V_867 , V_868 , V_649 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_72 ( V_2 , V_869 , V_867 , V_868 , V_649 ) ;
break;
default:
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_641 , ( 1 << V_870 ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_871 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_872 , ( ( 1 << V_873 ) | ( 1 << V_874 ) ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_640 , 21 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_632 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_645 , 448 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_633 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_651 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_875 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_876 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_877 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_631 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_878 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_646 , 1000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_608 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_638 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_639 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_650 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_879 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_503 , 0x01 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_74 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_880 , 2000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_654 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_76 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_71 ( V_2 , & ( V_2 -> V_163 ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_64 ( V_2 , & ( V_2 -> V_160 ) , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_65 ( V_2 , & ( V_2 -> V_161 ) , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_341 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_881 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_197 , V_198 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_199 , V_200 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_215 ) {
if ( V_2 -> V_882 & 0x0001 ) {
V_38 = F_21 ( V_2 , V_883 , V_2 -> V_190 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_884 , & V_881 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_885 & 0x0001 ) == 0 )
V_881 &= 0x7FFF ;
else
V_881 |= 0x8000 ;
V_38 = F_21 ( V_2 , V_884 , V_881 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_2 -> V_882 & 0x0002 ) {
V_38 = F_21 ( V_2 , V_883 , V_2 -> V_190 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_884 , & V_881 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_885 & 0x0002 ) == 0 )
V_881 &= 0xBFFF ;
else
V_881 |= 0x4000 ;
V_38 = F_21 ( V_2 , V_884 , V_881 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_2 -> V_882 & 0x0004 ) {
V_38 = F_21 ( V_2 , V_883 , V_2 -> V_190 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_884 , & V_881 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_885 & 0x0004 ) == 0 )
V_881 &= 0xFFFB ;
else
V_881 |= 0x0004 ;
V_38 = F_21 ( V_2 , V_884 , V_881 ) ;
if ( V_38 < 0 )
goto error;
}
}
V_38 = F_21 ( V_2 , V_199 , 0x0000 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
bool V_886 ;
F_12 ( 1 , L_3 ) ;
if ( ! V_2 -> V_887 )
return 0 ;
V_886 = V_2 -> V_885 & V_2 -> V_887 ;
if ( V_2 -> V_888 ^ V_886 ) {
if ( V_2 -> V_888 )
V_2 -> V_885 &= ~ V_2 -> V_887 ;
else
V_2 -> V_885 |= V_2 -> V_887 ;
V_38 = F_99 ( V_2 ) ;
}
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
bool V_886 ;
F_12 ( 1 , L_3 ) ;
if ( ! V_2 -> V_887 )
return 0 ;
V_886 = V_2 -> V_885 & V_2 -> V_887 ;
if ( ! ( V_2 -> V_888 ^ V_886 ) ) {
if ( V_2 -> V_888 )
V_2 -> V_885 |= V_2 -> V_887 ;
else
V_2 -> V_885 &= ~ V_2 -> V_887 ;
V_38 = F_99 ( V_2 ) ;
}
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_124 ) {
V_38 = F_70 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_41 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_65 , V_333 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_130 |= V_227 ;
V_38 = F_31 ( V_2 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_101 ( struct V_1 * V_2 , const char * V_889 )
{
const struct V_890 * V_891 = NULL ;
int V_314 = 0 ;
F_12 ( 1 , L_3 ) ;
V_314 = F_102 ( & V_891 , V_889 , V_2 -> V_51 -> V_892 . V_893 ) ;
if ( V_314 < 0 ) {
F_13 ( V_43
L_44 , V_889 ) ;
F_13 ( V_219
L_45 , V_889 ) ;
return V_314 ;
}
V_314 = F_40 ( V_2 , V_891 -> V_37 , V_891 -> V_894 ) ;
F_103 ( V_891 ) ;
return V_314 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
enum V_327 V_338 = V_330 ;
T_4 V_895 ;
F_12 ( 1 , L_3 ) ;
if ( ( V_2 -> V_165 == V_166 ) ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_28 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_896 , V_897 | V_898 | V_899 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
F_26 ( 1 ) ;
V_2 -> V_136 = true ;
V_38 = F_29 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_237 =
( T_4 ) ( ( V_2 -> V_122 / 1000 ) *
V_900 ) / 1000 ;
if ( V_2 -> V_237 >
V_901 ) {
V_2 -> V_237 =
V_901 ;
}
V_2 -> V_237 +=
V_2 -> V_237 <<
V_902 ;
V_38 = F_34 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
#if V_903
if ( ! ( V_2 -> V_9 )
&& ! ( V_2 -> V_133 ) )
#endif
{
V_38 = F_21 ( V_2 , V_197 , V_198 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_36 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_904 , V_905 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_906 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_291 , V_285 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_907 , V_908 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_37 ( V_2 , 0 , 6 , 100 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_909 )
F_101 ( V_2 , V_2 -> V_909 ) ;
V_38 = F_21 ( V_2 , V_291 , V_288 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_340 , V_341 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_28 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
F_26 ( 30 ) ;
V_338 = V_330 ;
V_38 = F_46 ( V_2 , & V_338 ) ;
if ( V_38 < 0 )
goto error;
V_895 =
( ( ( V_910 / 100 ) % 10 ) << 12 ) +
( ( ( V_910 / 10 ) % 10 ) << 8 ) +
( ( V_910 % 10 ) << 4 ) +
( V_911 % 10 ) ;
V_38 = F_21 ( V_2 , V_912 , V_895 ) ;
if ( V_38 < 0 )
goto error;
V_895 =
( ( ( V_913 / 1000 ) % 10 ) << 12 ) +
( ( ( V_913 / 100 ) % 10 ) << 8 ) +
( ( ( V_913 / 10 ) % 10 ) << 4 ) +
( V_913 % 10 ) ;
V_38 = F_21 ( V_2 , V_914 , V_895 ) ;
if ( V_38 < 0 )
goto error;
F_13 ( V_219 L_46 ,
V_910 , V_911 ,
V_913 ) ;
V_38 = F_21 ( V_2 , V_915 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_664 , V_916 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_61 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_63 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_35 ( V_2 , V_2 -> V_167 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_99 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_165 = V_357 ;
if ( V_2 -> V_132 ) {
V_38 = F_100 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_165 = V_484 ;
} else
V_2 -> V_165 = V_357 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static void F_105 ( struct V_917 * V_918 )
{
struct V_1 * V_2 = V_918 -> V_919 ;
F_12 ( 1 , L_3 ) ;
F_106 ( V_2 ) ;
}
static int F_107 ( struct V_917 * V_918 )
{
struct V_1 * V_2 = V_918 -> V_919 ;
F_12 ( 1 , L_3 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_108 ( struct V_917 * V_918 , int V_283 )
{
struct V_1 * V_2 = V_918 -> V_919 ;
F_12 ( 1 , L_47 , V_283 ? L_24 : L_25 ) ;
return F_70 ( V_2 , V_283 ? true : false ) ;
}
static int F_109 ( struct V_917 * V_918 )
{
struct V_920 * V_309 = & V_918 -> V_921 ;
T_1 V_922 = V_309 -> V_923 , V_924 ;
struct V_1 * V_2 = V_918 -> V_919 ;
T_1 IF ;
F_12 ( 1 , L_3 ) ;
if ( ! V_918 -> V_925 . V_926 . V_927 ) {
F_13 ( V_43
L_48 ) ;
return - V_208 ;
}
if ( V_918 -> V_925 . V_928 )
V_918 -> V_925 . V_928 ( V_918 , 1 ) ;
if ( V_918 -> V_925 . V_926 . V_929 )
V_918 -> V_925 . V_926 . V_929 ( V_918 ) ;
if ( V_918 -> V_925 . V_928 )
V_918 -> V_925 . V_928 ( V_918 , 0 ) ;
V_924 = V_2 -> V_360 . V_923 ;
V_2 -> V_360 = * V_309 ;
if ( V_924 != V_922 ) {
F_56 ( V_2 ) ;
switch ( V_922 ) {
case V_930 :
case V_931 :
if ( ! V_2 -> V_118 )
return - V_208 ;
V_2 -> V_932 = ( V_922 == V_931 ) ? true : false ;
if ( V_2 -> V_932 )
F_49 ( V_2 , V_7 ) ;
else
F_49 ( V_2 , V_5 ) ;
break;
case V_933 :
if ( ! V_2 -> V_117 )
return - V_208 ;
F_49 ( V_2 , V_4 ) ;
break;
default:
return - V_208 ;
}
}
V_918 -> V_925 . V_926 . V_927 ( V_918 , & IF ) ;
F_52 ( V_2 , 0 , IF ) ;
return 0 ;
}
static int F_110 ( struct V_917 * V_918 , T_7 * V_38 )
{
struct V_1 * V_2 = V_918 -> V_919 ;
T_1 V_934 ;
F_12 ( 1 , L_3 ) ;
* V_38 = 0 ;
F_57 ( V_2 , & V_934 , 0 ) ;
if ( V_934 == V_745 )
* V_38 |= 0x1f ;
if ( V_934 == V_746 )
* V_38 |= 0x0f ;
if ( V_934 == V_747 )
* V_38 |= 0x07 ;
return 0 ;
}
static int F_111 ( struct V_917 * V_918 , T_1 * V_935 )
{
F_12 ( 1 , L_3 ) ;
* V_935 = 0 ;
return 0 ;
}
static int F_112 ( struct V_917 * V_918 ,
T_4 * V_936 )
{
struct V_1 * V_2 = V_918 -> V_919 ;
T_1 V_28 = 0 ;
F_12 ( 1 , L_3 ) ;
F_66 ( V_2 , & V_28 ) ;
* V_936 = V_28 & 0xffff ;
return 0 ;
}
static int F_113 ( struct V_917 * V_918 , T_4 * V_937 )
{
struct V_1 * V_2 = V_918 -> V_919 ;
T_6 V_938 ;
F_12 ( 1 , L_3 ) ;
F_69 ( V_2 , & V_938 ) ;
* V_937 = V_938 & 0xffff ;
return 0 ;
}
static int F_114 ( struct V_917 * V_918 , T_1 * V_939 )
{
struct V_1 * V_2 = V_918 -> V_919 ;
T_4 V_314 ;
F_12 ( 1 , L_3 ) ;
F_77 ( V_2 , & V_314 ) ;
* V_939 = ( T_1 ) V_314 ;
return 0 ;
}
static int F_115 ( struct V_917 * V_918 , struct V_940
* V_941 )
{
struct V_920 * V_309 = & V_918 -> V_921 ;
F_12 ( 1 , L_3 ) ;
switch ( V_309 -> V_923 ) {
case V_930 :
case V_931 :
case V_933 :
V_941 -> V_942 = 3000 ;
V_941 -> V_943 = 0 ;
V_941 -> V_944 = 0 ;
return 0 ;
default:
return - V_208 ;
}
}
struct V_917 * F_116 ( const struct V_945 * V_946 ,
struct V_25 * V_51 )
{
int V_947 ;
struct V_1 * V_2 = NULL ;
T_3 V_27 = V_946 -> V_27 ;
F_12 ( 1 , L_3 ) ;
V_2 = F_117 ( sizeof( struct V_1 ) , V_948 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_51 = V_51 ;
V_2 -> V_47 = V_27 ;
V_2 -> V_50 = V_946 -> V_50 ;
V_2 -> V_909 = V_946 -> V_909 ;
V_2 -> V_485 = V_946 -> V_485 ;
V_2 -> V_887 = V_946 -> V_887 ;
V_2 -> V_888 = V_946 -> V_888 ;
V_2 -> V_59 = V_946 -> V_949 ;
V_2 -> V_261 = V_946 -> V_261 ;
if ( V_946 -> V_950 ) {
V_2 -> V_392 = 0 ;
V_2 -> V_393 = 0 ;
} else {
V_2 -> V_392 = 1 ;
V_2 -> V_393 = 1 ;
}
if ( V_946 -> V_951 )
V_2 -> V_259 = V_946 -> V_951 & 0x07 ;
else
V_2 -> V_259 = 0x06 ;
if ( V_946 -> V_952 )
V_2 -> V_245 = true ;
else
V_2 -> V_245 = false ;
V_2 -> V_882 = V_946 -> V_887 ;
if ( ! V_2 -> V_888 && V_2 -> V_887 )
V_2 -> V_885 |= V_2 -> V_887 ;
else
V_2 -> V_885 &= ~ V_2 -> V_887 ;
F_118 ( & V_2 -> V_231 ) ;
memcpy ( & V_2 -> V_953 . V_925 , & V_954 , sizeof( V_954 ) ) ;
V_2 -> V_953 . V_919 = V_2 ;
F_27 ( V_2 ) ;
if ( F_104 ( V_2 ) < 0 )
goto error;
V_947 = 0 ;
if ( V_2 -> V_118 ) {
V_2 -> V_953 . V_925 . V_922 [ V_947 ++ ] = V_930 ;
V_2 -> V_953 . V_925 . V_922 [ V_947 ++ ] = V_931 ;
F_119 ( V_2 -> V_953 . V_925 . V_955 . V_956 , L_49 ,
sizeof( V_2 -> V_953 . V_925 . V_955 . V_956 ) ) ;
}
if ( V_2 -> V_117 ) {
V_2 -> V_953 . V_925 . V_922 [ V_947 ++ ] = V_933 ;
F_119 ( V_2 -> V_953 . V_925 . V_955 . V_956 , L_50 ,
sizeof( V_2 -> V_953 . V_925 . V_955 . V_956 ) ) ;
}
F_13 ( V_219 L_51 ) ;
return & V_2 -> V_953 ;
error:
F_13 ( V_43 L_52 ) ;
F_106 ( V_2 ) ;
return NULL ;
}
