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
T_1 V_53 ;
T_4 V_279 ;
T_4 V_54 ;
T_1 V_280 = 0 ;
T_1 V_14 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
#if 0
Drain = (pSrc[0] << 8) | pSrc[1];
#endif
V_278 += sizeof( T_4 ) ;
V_280 += sizeof( T_4 ) ;
V_279 = ( V_278 [ 0 ] << 8 ) | V_278 [ 1 ] ;
V_278 += sizeof( T_4 ) ;
V_280 += sizeof( T_4 ) ;
for ( V_14 = 0 ; V_14 < V_279 ; V_14 += 1 ) {
V_53 = ( V_278 [ 0 ] << 24 ) | ( V_278 [ 1 ] << 16 ) |
( V_278 [ 2 ] << 8 ) | V_278 [ 3 ] ;
V_278 += sizeof( T_1 ) ;
V_280 += sizeof( T_1 ) ;
V_54 = ( ( V_278 [ 0 ] << 8 ) | V_278 [ 1 ] ) * sizeof( T_4 ) ;
V_278 += sizeof( T_4 ) ;
V_280 += sizeof( T_4 ) ;
#if 0
Flags = (pSrc[0] << 8) | pSrc[1];
#endif
V_278 += sizeof( T_4 ) ;
V_280 += sizeof( T_4 ) ;
#if 0
BlockCRC = (pSrc[0] << 8) | pSrc[1];
#endif
V_278 += sizeof( T_4 ) ;
V_280 += sizeof( T_4 ) ;
if ( V_280 + V_54 > V_277 ) {
F_13 ( V_43 L_29 ) ;
return - V_208 ;
}
V_38 = F_24 ( V_2 , V_53 , V_54 , V_278 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_30 , V_38 ) ;
break;
}
V_278 += V_54 ;
V_280 += V_54 ;
}
return V_38 ;
}
static int F_41 ( struct V_1 * V_2 , bool V_281 )
{
int V_38 ;
T_4 V_37 = 0 ;
T_4 V_282 = V_283 ;
T_4 V_284 = V_285 ;
unsigned long V_267 ;
F_12 ( 1 , L_3 ) ;
if ( V_281 == false ) {
V_282 = V_286 ;
V_284 = V_287 ;
}
V_38 = F_17 ( V_2 , V_288 , & V_37 ) ;
if ( V_38 >= 0 && V_37 == V_284 ) {
return V_38 ;
}
V_38 = F_21 ( V_2 , V_289 , V_282 ) ;
V_267 = V_274 + F_38 ( V_290 ) ;
do {
V_38 = F_17 ( V_2 , V_288 , & V_37 ) ;
if ( ( V_38 >= 0 && V_37 == V_284 ) || F_39 ( V_267 ) )
break;
F_26 ( 1 ) ;
} while ( 1 );
if ( V_37 != V_284 ) {
F_13 ( V_43 L_28 ) ;
return - V_208 ;
}
return V_38 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
T_4 V_291 = 0 ;
T_4 V_292 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_293 , & V_291 ) ;
if ( V_38 < 0 )
goto error;
V_291 |= V_294 ;
V_38 = F_21 ( V_2 , V_293 , V_291 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_295 , & V_292 ) ;
if ( V_38 < 0 )
goto error;
V_292 |= V_296 ;
V_38 = F_21 ( V_2 , V_295 , V_292 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_4 V_220 , T_3 V_297 ,
T_4 * V_298 , T_3 V_299 , T_4 * V_300 )
{
#if ( V_301 - V_302 ) != 15
#error DRXK register mapping no longer compatible with this routine!
#endif
T_4 V_303 = 0 ;
int V_38 = - V_208 ;
unsigned long V_267 ;
T_3 V_304 [ 34 ] ;
int V_305 = 0 , V_306 ;
const char * V_307 ;
char V_308 [ 30 ] ;
F_12 ( 1 , L_3 ) ;
if ( ( V_220 == 0 ) || ( ( V_297 > 0 ) && ( V_298 == NULL ) ) ||
( ( V_299 > 0 ) && ( V_300 == NULL ) ) ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
F_32 ( & V_2 -> V_231 ) ;
for ( V_306 = V_297 - 1 ; V_306 >= 0 ; V_306 -= 1 ) {
V_304 [ V_305 ++ ] = ( V_298 [ V_306 ] & 0xFF ) ;
V_304 [ V_305 ++ ] = ( ( V_298 [ V_306 ] >> 8 ) & 0xFF ) ;
}
V_304 [ V_305 ++ ] = ( V_220 & 0xFF ) ;
V_304 [ V_305 ++ ] = ( ( V_220 >> 8 ) & 0xFF ) ;
F_24 ( V_2 , V_301 -
( V_297 - 1 ) , V_305 , V_304 ) ;
V_267 = V_274 + F_38 ( V_309 ) ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_310 , & V_303 ) ;
if ( V_38 < 0 )
goto error;
} while ( ! ( V_303 == V_311 ) && ( F_39 ( V_267 ) ) );
if ( V_303 != V_311 ) {
F_13 ( V_43 L_31 ) ;
V_38 = - V_42 ;
goto V_214;
}
if ( ( V_299 > 0 ) && ( V_300 != NULL ) ) {
T_5 V_312 ;
int V_306 ;
for ( V_306 = V_299 - 1 ; V_306 >= 0 ; V_306 -= 1 ) {
V_38 = F_17 ( V_2 , V_301 - V_306 , & V_300 [ V_306 ] ) ;
if ( V_38 < 0 )
goto error;
}
V_312 = ( T_5 ) V_300 [ 0 ] ;
if ( V_312 >= 0 )
goto error;
switch ( V_312 ) {
case V_313 :
V_307 = L_32 ;
break;
case V_314 :
V_307 = L_33 ;
break;
case V_315 :
V_307 = L_34 ;
break;
case V_316 :
V_307 = L_35 ;
break;
default:
sprintf ( V_308 , L_36 , V_312 ) ;
V_307 = V_308 ;
}
F_13 ( V_43 L_37 , V_307 , V_220 ) ;
F_44 ( L_38 , V_317 , V_304 , V_305 ) ;
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
static int F_45 ( struct V_1 * V_2 , bool V_318 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_319 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_318 ) {
V_37 |= ( V_320
| V_321
| V_322
| V_323
| V_324 ) ;
} else {
V_37 &= ( ( ~ V_320 )
& ( ~ V_321 )
& ( ~ V_322 )
& ( ~ V_323 )
& ( ~ V_324 )
) ;
}
V_38 = F_21 ( V_2 , V_319 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_46 ( struct V_1 * V_2 , enum V_325 * V_326 )
{
int V_38 = 0 ;
T_4 V_327 = 0 ;
F_12 ( 1 , L_3 ) ;
if ( V_326 == NULL )
return - V_208 ;
switch ( * V_326 ) {
case V_71 :
V_327 = V_66 ;
break;
case V_328 :
V_327 = V_329 ;
break;
case V_330 :
V_327 = V_331 ;
break;
case V_332 :
V_327 = V_333 ;
break;
case V_191 :
V_327 = V_334 ;
break;
default:
return - V_208 ;
}
if ( V_2 -> V_70 == * V_326 )
return 0 ;
if ( V_2 -> V_70 != V_71 ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_41 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
}
if ( * V_326 == V_71 ) {
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
V_38 = F_21 ( V_2 , V_65 , V_327 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
if ( * V_326 != V_328 ) {
V_2 -> V_130 |=
V_227 ;
V_38 = F_31 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
}
}
V_2 -> V_70 = * V_326 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_47 ( struct V_1 * V_2 , bool V_335 )
{
enum V_325 V_336 = V_328 ;
T_4 V_337 = 0 ;
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_338 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == V_339 ) {
V_38 = F_43 ( V_2 , V_340 | V_341 , 0 , NULL , 1 , & V_337 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_340 | V_342 , 0 , NULL , 1 , & V_337 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_343 , V_344 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_347 , V_348 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
if ( V_335 ) {
V_38 = F_46 ( V_2 , & V_336 ) ;
if ( V_38 < 0 )
goto error;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_49 ( struct V_1 * V_2 ,
enum V_349 V_350 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_197 , V_198 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_3 == V_350 )
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
switch ( V_350 ) {
case V_4 :
F_12 ( 1 , L_39 ) ;
V_2 -> V_3 = V_350 ;
V_38 = F_50 ( V_2 , V_350 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_5 :
case V_7 :
F_12 ( 1 , L_40 ,
( V_2 -> V_3 == V_5 ) ? 'A' : 'C' ) ;
V_2 -> V_3 = V_350 ;
V_38 = F_51 ( V_2 , V_350 ) ;
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
static int F_52 ( struct V_1 * V_2 , T_6 V_351 ,
T_6 V_352 )
{
int V_38 = - V_208 ;
T_4 V_353 ;
T_6 V_354 = V_351 / 1000 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_165 != V_355 &&
V_2 -> V_165 != V_356 )
goto error;
V_2 -> V_357 = ( V_2 -> V_358 . V_359 == V_360 ) ;
if ( V_352 < 0 ) {
V_2 -> V_357 = ! V_2 -> V_357 ;
V_352 = - V_352 ;
}
switch ( V_2 -> V_3 ) {
case V_5 :
case V_7 :
V_353 = ( V_352 / 1000 ) ;
V_38 = F_53 ( V_2 , V_353 , V_354 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_165 = V_356 ;
break;
case V_4 :
V_353 = ( V_352 / 1000 ) ;
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_54 ( V_2 , V_353 , V_354 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_55 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_165 = V_356 ;
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
static int F_57 ( struct V_1 * V_2 , T_1 * V_361 ,
T_1 Time )
{
int V_38 = - V_208 ;
F_12 ( 1 , L_3 ) ;
if ( V_361 == NULL )
goto error;
* V_361 = V_362 ;
switch ( V_2 -> V_3 ) {
case V_5 :
case V_6 :
case V_7 :
V_38 = F_58 ( V_2 , V_361 ) ;
break;
case V_4 :
V_38 = F_59 ( V_2 , V_361 ) ;
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
T_4 V_291 = 0 ;
V_38 = F_17 ( V_2 , V_293 , & V_291 ) ;
if ( V_38 < 0 )
goto error;
V_291 &= ~ V_294 ;
V_38 = F_21 ( V_2 , V_293 , V_291 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_363 , 1 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_364 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_365 , 0x000C ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_366 , 0x000A ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_367 , 0x0008 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_368 , 0x0006 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_369 , 0x0680 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_370 , 0x0080 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_371 , 0x03F4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_372 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_373 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_374 , 12 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_62 ( struct V_1 * V_2 ,
enum V_349 V_350 )
{
int V_38 ;
T_4 V_375 = 0 ;
T_4 V_376 = 0 ;
T_4 V_377 = 0 ;
T_4 V_378 = 0 ;
T_4 V_379 = 2 ;
T_4 V_380 = 188 ;
T_1 V_381 = 0 ;
T_4 V_382 = 0 ;
T_4 V_383 = 0 ;
T_1 V_384 = 0 ;
bool V_385 = false ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_386 , & V_375 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_295 , & V_376 ) ;
if ( V_38 < 0 )
goto error;
V_375 &= ( ~ V_387 ) ;
V_376 &= ( ~ V_388 ) ;
if ( V_2 -> V_168 == true ) {
V_375 |= V_387 ;
V_376 |= V_388 ;
V_380 = 204 ;
}
V_376 &= ( ~ ( V_389 ) ) ;
if ( V_2 -> V_245 == false ) {
V_376 |= V_389 ;
}
switch ( V_350 ) {
case V_4 :
V_384 = V_2 -> V_174 ;
V_382 = 3 ;
V_381 = 0xC00000 ;
V_385 = V_2 -> V_390 ;
break;
case V_5 :
case V_7 :
V_382 = 0x0004 ;
V_381 = 0xD2B4EE ;
V_384 = V_2 -> V_175 ;
V_385 = V_2 -> V_391 ;
break;
default:
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
if ( V_385 ) {
T_1 V_392 = 0 ;
V_377 = ( V_393 |
V_394 ) ;
V_378 = ( V_395 |
V_396 ) ;
V_392 = V_384 ;
if ( V_392 > 75900000UL ) {
V_392 = 75900000UL ;
}
V_379 = ( T_4 ) ( ( ( V_2 -> V_125 )
* 1000 ) / V_392 ) ;
if ( V_379 <= 2 )
V_379 = 0 ;
else
V_379 -= 2 ;
V_383 = 8 ;
} else {
V_377 = V_393 ;
V_378 = V_397 ;
V_383 = 5 ;
}
V_38 = F_21 ( V_2 , V_398 , V_380 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_399 , V_379 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_400 , V_377 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_401 , V_378 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_386 , V_375 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_295 , V_376 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_23 ( V_2 , V_402 , V_381 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_403 , V_383 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_404 , V_382 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_4 V_405 = 0 ;
T_4 V_406 =
V_407 | V_408 |
V_409 | V_410 |
V_411 | V_412 |
V_413 | V_414 ;
F_12 ( 1 , L_3 ) ;
V_405 &= ( ~ ( V_406 ) ) ;
if ( V_2 -> V_169 == true )
V_405 |= V_406 ;
V_405 &= ( ~ ( V_415 ) ) ;
if ( V_2 -> V_170 == true )
V_405 |= V_415 ;
V_405 &= ( ~ ( V_416 ) ) ;
if ( V_2 -> V_171 == true )
V_405 |= V_416 ;
V_405 &= ( ~ ( V_417 ) ) ;
if ( V_2 -> V_172 == true )
V_405 |= V_417 ;
V_405 &= ( ~ ( V_418 ) ) ;
if ( V_2 -> V_173 == true )
V_405 |= V_418 ;
return F_21 ( V_2 , V_419 , V_405 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_420 * V_421 , bool V_422 )
{
int V_38 = - V_208 ;
T_4 V_37 = 0 ;
struct V_420 * V_423 ;
F_12 ( 1 , L_3 ) ;
if ( V_421 == NULL )
goto error;
switch ( V_421 -> V_138 ) {
case V_73 :
V_38 = F_17 ( V_2 , V_319 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_324 ;
V_38 = F_21 ( V_2 , V_319 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_424 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_425 ;
if ( V_2 -> V_426 )
V_37 |= V_427 ;
else
V_37 &= ~ V_427 ;
V_38 = F_21 ( V_2 , V_424 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_428 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_429 ;
V_37 |= ( ~ ( V_421 -> V_142 <<
V_430 )
& V_429 ) ;
V_38 = F_21 ( V_2 , V_428 , V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( F_1 ( V_2 ) )
V_423 = & V_2 -> V_156 ;
else if ( F_2 ( V_2 ) )
V_423 = & V_2 -> V_161 ;
else
V_423 = & V_2 -> V_152 ;
if ( V_423 == NULL ) {
V_38 = - V_208 ;
goto error;
}
if ( V_423 -> V_138 == V_73 )
V_38 = F_21 ( V_2 , V_431 , V_421 -> V_145 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_432 , V_421 -> V_146 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_433 , V_421 -> V_141 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_434 :
V_38 = F_17 ( V_2 , V_319 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_324 ;
V_38 = F_21 ( V_2 , V_319 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_424 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_425 ;
if ( V_2 -> V_426 )
V_37 |= V_427 ;
else
V_37 &= ~ V_427 ;
V_38 = F_21 ( V_2 , V_424 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_432 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_435 , V_421 -> V_139 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_91 :
V_38 = F_17 ( V_2 , V_319 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_324 ;
V_38 = F_21 ( V_2 , V_319 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_424 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_425 ;
V_38 = F_21 ( V_2 , V_424 , V_37 ) ;
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
struct V_420 * V_421 , bool V_422 )
{
T_4 V_37 = 0 ;
int V_38 = 0 ;
struct V_420 * V_436 ;
F_12 ( 1 , L_3 ) ;
switch ( V_421 -> V_138 ) {
case V_73 :
V_38 = F_17 ( V_2 , V_319 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_323 ;
V_38 = F_21 ( V_2 , V_319 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_424 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_437 ;
if ( V_2 -> V_193 )
V_37 |= V_438 ;
else
V_37 &= ~ V_438 ;
V_38 = F_21 ( V_2 , V_424 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_428 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_439 ;
V_37 |= ( ~ ( V_421 -> V_142 <<
V_440 )
& V_439 ) ;
V_38 = F_21 ( V_2 , V_428 , V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( F_2 ( V_2 ) )
V_436 = & V_2 -> V_160 ;
else
V_436 = & V_2 -> V_153 ;
if ( V_436 == NULL )
return - 1 ;
V_38 = F_21 ( V_2 , V_431 , V_436 -> V_145 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_434 :
V_38 = F_17 ( V_2 , V_319 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_323 ;
V_38 = F_21 ( V_2 , V_319 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_424 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_437 ;
if ( V_2 -> V_193 )
V_37 |= V_438 ;
else
V_37 &= ~ V_438 ;
V_38 = F_21 ( V_2 , V_424 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_431 , V_421 -> V_139 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_91 :
V_38 = F_17 ( V_2 , V_319 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_323 ;
V_38 = F_21 ( V_2 , V_319 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_424 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_437 ;
V_38 = F_21 ( V_2 , V_424 , V_37 ) ;
if ( V_38 < 0 )
goto error;
break;
}
V_38 = F_21 ( V_2 , V_441 , V_421 -> V_145 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 * V_442 )
{
T_4 V_443 ;
int V_38 ;
T_4 V_444 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_445 , & V_443 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
* V_442 = 0 ;
if ( V_443 > V_446 )
V_444 = V_443 - V_446 ;
if ( V_444 < 14000 )
* V_442 = ( 14000 - V_444 ) / 4 ;
else
* V_442 = 0 ;
return V_38 ;
}
static int F_67 ( struct V_1 * V_2 ,
T_6 * V_447 )
{
int V_38 = 0 ;
T_4 V_448 = 0 ;
T_1 V_449 = 0 ;
T_1 V_450 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_451 , & V_448 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return - V_208 ;
}
switch ( V_2 -> V_358 . V_452 ) {
case V_453 :
V_449 = V_454 << 2 ;
break;
case V_455 :
V_449 = V_456 << 2 ;
break;
case V_457 :
V_449 = V_458 << 2 ;
break;
case V_459 :
V_449 = V_460 << 2 ;
break;
default:
case V_461 :
V_449 = V_462 << 2 ;
break;
}
if ( V_448 > 0 ) {
V_450 = F_8 ( V_449 ) -
F_8 ( ( T_1 ) V_448 ) ;
}
* V_447 = V_450 ;
return V_38 ;
}
static int F_68 ( struct V_1 * V_2 ,
T_6 * V_447 )
{
int V_38 ;
T_4 V_463 = 0 ;
T_1 V_464 = 0 ;
T_1 V_465 = 0 ;
T_4 V_466 = 0 ;
T_4 V_467 = 0 ;
T_4 V_468 = 0 ;
T_1 V_469 = 0 ;
T_1 V_470 = 0 ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
T_1 V_471 = 0 ;
T_4 V_472 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_473 , & V_467 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_474 , & V_468 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_475 , & V_466 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_476 , & V_463 ) ;
if ( V_38 < 0 )
goto error;
V_464 = ( T_1 ) V_463 ;
if ( ( V_466 > 11 ) &&
( V_464 < 0x00000FFFUL ) ) {
V_464 += 0x00010000UL ;
}
V_38 = F_17 ( V_2 , V_477 , & V_463 ) ;
if ( V_38 < 0 )
goto error;
V_465 = ( T_1 ) V_463 ;
if ( ( V_466 > 11 ) &&
( V_465 < 0x00000FFFUL ) )
V_465 += 0x00010000UL ;
V_38 = F_17 ( V_2 , V_478 , & V_472 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_467 == 0 ) || ( V_468 == 0 ) )
V_471 = 0 ;
else if ( ( V_464 + V_465 ) == 0 ) {
V_471 = 0 ;
} else {
V_470 = ( V_464 + V_465 ) <<
V_466 ;
if ( ( V_472 &
V_479 )
== V_480 )
V_469 = 17 ;
else
V_469 = 68 ;
V_10 = F_8 ( V_467 *
V_467 ) ;
V_11 = F_8 ( V_468 * V_469 ) ;
V_12 = F_8 ( V_470 ) ;
V_471 = V_10 + V_11 ;
if ( V_471 > V_12 )
V_471 -= V_12 ;
else
V_471 = 0 ;
}
* V_447 = V_471 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_69 ( struct V_1 * V_2 , T_6 * V_447 )
{
F_12 ( 1 , L_3 ) ;
* V_447 = 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
return F_68 ( V_2 , V_447 ) ;
case V_5 :
case V_7 :
return F_67 ( V_2 , V_447 ) ;
default:
break;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , bool V_481 )
{
int V_38 = - V_208 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_165 == V_166 )
goto error;
if ( V_2 -> V_165 == V_482 )
goto error;
if ( V_2 -> V_483 )
return 0 ;
V_38 = F_21 ( V_2 , V_239 , V_240 ) ;
if ( V_38 < 0 )
goto error;
if ( V_481 ) {
V_38 = F_21 ( V_2 , V_238 , V_484 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_38 = F_21 ( V_2 , V_238 , V_485 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_30 ( V_2 , V_486 , 0 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_487 * V_488 )
{
int V_38 = - V_208 ;
F_12 ( 1 , L_3 ) ;
if ( ( V_488 == NULL )
|| ( V_488 -> V_148 > V_489 ) )
goto error;
V_38 = F_21 ( V_2 , V_490 , V_488 -> V_148 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 V_491 ,
T_4 V_263 , T_4 V_264 , T_1 V_265 )
{
T_4 V_266 = 0 ;
T_4 V_280 = ( T_4 ) ( ( V_491 >> 0 ) & 0x00FFFF ) ;
T_4 V_492 = ( T_4 ) ( ( V_491 >> 16 ) & 0x000FFF ) ;
int V_38 ;
unsigned long V_267 ;
F_12 ( 1 , L_3 ) ;
F_32 ( & V_2 -> V_231 ) ;
V_38 = F_21 ( V_2 , V_268 , V_493 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_494 , V_492 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_495 , V_280 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_496 , V_263 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_497 , V_264 ) ;
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
static int F_73 ( struct V_1 * V_2 , T_4 * V_498 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_499 , V_500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_501 , 1 ) ;
if ( V_38 < 0 )
goto error;
* V_498 = 0 ;
V_38 = F_17 ( V_2 , V_502 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_498 = * V_498 + 1 ;
V_38 = F_17 ( V_2 , V_503 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_498 = * V_498 + 1 ;
V_38 = F_17 ( V_2 , V_504 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_498 = * V_498 + 1 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_74 ( struct V_1 * V_2 )
{
T_4 V_498 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_73 ( V_2 , & V_498 ) ;
if ( V_38 < 0 )
goto error;
if ( V_498 == 1 ) {
T_4 V_505 = 0 ;
V_38 = F_17 ( V_2 , V_506 , & V_505 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_505 | V_507 ) ==
V_508 ) {
V_505 &= ( ~ ( V_507 ) ) ;
V_505 |=
V_509 ;
} else {
V_505 &= ( ~ ( V_507 ) ) ;
V_505 |=
V_508 ;
}
V_38 = F_21 ( V_2 , V_506 , V_505 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_73 ( V_2 , & V_498 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_498 < 2 )
V_38 = - V_208 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_4 V_510 ,
T_6 V_511 , bool V_422 )
{
bool V_512 = false ;
T_1 V_513 = V_511 ;
T_1 V_514 = 0 ;
bool V_515 = ! V_2 -> V_357 ;
T_1 V_516 ;
bool V_517 ;
int V_38 ;
T_1 V_518 ;
T_1 V_519 = ( T_1 ) ( V_2 -> V_125 / 3 ) ;
T_1 V_520 ;
bool V_521 ;
F_12 ( 1 , L_3 ) ;
if ( V_422 ) {
if ( ( V_2 -> V_3 == V_5 ) ||
( V_2 -> V_3 == V_7 ) ||
( V_2 -> V_3 == V_4 ) )
V_512 = true ;
else
V_512 = false ;
}
if ( V_515 )
V_518 = V_510 +
V_513 + V_514 ;
else
V_518 = V_510 -
V_513 - V_514 ;
if ( V_518 > V_519 / 2 ) {
V_516 = V_519 - V_518 ;
V_517 = true ;
} else {
V_516 = V_518 ;
V_517 = false ;
}
V_520 = V_516 ;
V_521 = V_2 -> V_192 ^ V_515 ^
V_517 ^ V_512 ;
V_2 -> V_522 =
F_7 ( ( V_520 ) , V_519 ) ;
if ( V_521 )
V_2 -> V_522 = ~ V_2 -> V_522 + 1 ;
V_38 = F_23 ( V_2 , V_523 ,
V_2 -> V_522 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_76 ( struct V_1 * V_2 , bool V_422 )
{
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
T_4 V_536 = 0 ;
T_4 V_537 = 0 ;
T_4 V_37 = 0 ;
T_4 V_538 = 0 ;
T_4 V_539 = 0 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_531 = 1023 ;
V_536 = 2047 ;
V_527 = 500 ;
V_532 = 1023 ;
if ( ! F_2 ( V_2 ) ) {
F_13 ( V_43 L_41 , V_62 , V_2 -> V_3 ) ;
return - V_208 ;
}
V_528 = 8 ;
V_529 = ( T_4 ) - 9 ;
V_539 = 0 ;
V_530 = 8 ;
V_533 = ( T_4 ) - 9 ;
V_534 = ( T_4 ) - 1030 ;
V_537 = 0x2380 ;
V_535 = 0x2380 ;
V_525 = 0x0511 ;
V_524 = 0x0511 ;
V_526 = 5119 ;
V_538 = V_2 -> V_161 . V_157 ;
V_38 = F_21 ( V_2 , V_540 , V_538 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_541 , V_539 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_542 , V_524 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_441 , V_525 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_543 , V_526 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_544 , V_536 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_431 , V_537 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_545 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_546 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_435 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_547 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_548 , V_532 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_549 , V_531 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_550 , V_534 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_551 , V_535 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_552 , V_527 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_553 , 1023 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_554 , ( T_4 ) - 1023 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_555 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_556 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_557 , V_528 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_558 , V_530 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_559 , V_529 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_560 , V_533 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_561 , 0x7fff ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_562 , 0x0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_563 , 0x0117 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_564 , 0x0657 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_565 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_566 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_567 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_568 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_569 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_570 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_571 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_572 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_573 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_574 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_575 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 = 0x0657 ;
V_37 &= ~ V_576 ;
V_37 |= ( V_577 << V_578 ) ;
V_37 &= ~ V_579 ;
V_37 |= ( V_580 << V_581 ) ;
V_38 = F_21 ( V_2 , V_575 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_77 ( struct V_1 * V_2 , T_4 * V_582 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( V_582 == NULL )
V_38 = F_21 ( V_2 , V_583 , 0 ) ;
else
V_38 = F_17 ( V_2 , V_583 , V_582 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_78 ( struct V_1 * V_2 ,
T_4 V_220 , T_4 V_584 ,
T_4 V_585 , T_4 V_586 , T_4 V_587 ,
T_4 V_588 , T_4 V_589 )
{
T_4 V_303 = 0 ;
T_4 V_590 = 0 ;
T_4 V_591 = 0 ;
T_4 V_592 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_343 , & V_592 ) ;
if ( V_592 != 1 ) {
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
V_591 = 0 ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_593 , & V_303 ) ;
V_591 ++ ;
} while ( ( V_303 != 0 ) && ( V_591 < V_229 ) );
if ( V_591 >= V_229 && ( V_38 < 0 ) )
goto error;
switch ( V_220 ) {
case V_594 :
case V_595 :
case V_596 :
V_38 = F_21 ( V_2 , V_597 , V_584 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
break;
}
switch ( V_220 ) {
case V_594 :
case V_595 :
case V_596 :
V_38 = F_21 ( V_2 , V_598 , V_586 ) ;
case V_599 :
case V_600 :
V_38 = F_21 ( V_2 , V_601 , V_585 ) ;
case V_602 :
case V_603 :
V_38 = F_21 ( V_2 , V_593 , V_220 ) ;
break;
default:
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
V_591 = 0 ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_593 , & V_303 ) ;
V_591 ++ ;
} while ( ( V_303 != 0 ) && ( V_591 < V_229 ) );
if ( V_591 >= V_229 && ( V_38 < 0 ) )
goto error;
V_38 = F_17 ( V_2 , V_597 , & V_590 ) ;
if ( V_590 == 0xFFFF ) {
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
switch ( V_220 ) {
case V_600 :
case V_602 :
V_38 = F_17 ( V_2 , V_601 , & ( V_585 ) ) ;
case V_599 :
case V_604 :
case V_594 :
case V_595 :
case V_596 :
case V_603 :
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
enum V_325 V_336 = V_71 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_46 ( V_2 , & V_336 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_80 ( struct V_1 * V_2 , bool * V_605 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( * V_605 == true )
V_38 = F_21 ( V_2 , V_606 , 0 ) ;
else
V_38 = F_21 ( V_2 , V_606 , 1 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_81 ( struct V_1 * V_2 , bool * V_605 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( * V_605 == true ) {
V_38 = F_21 ( V_2 , V_607 ,
V_608 ) ;
} else {
V_38 = F_21 ( V_2 , V_607 , 0 ) ;
}
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_609 * V_610 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_611 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_610 -> V_612 ) {
case V_613 :
V_37 &= ~ V_614 ;
V_37 |= ( ( V_610 -> V_615 <<
V_616 )
& ( V_614 ) ) ;
break;
case V_617 :
V_37 &= ~ V_618 ;
V_37 |= ( ( V_610 -> V_615 <<
V_619 )
& ( V_618 ) ) ;
break;
default:
return - V_208 ;
}
V_38 = F_21 ( V_2 , V_611 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_83 ( struct V_1 * V_2 ,
enum V_620 * V_142 )
{
int V_38 = - V_208 ;
F_12 ( 1 , L_3 ) ;
switch ( * V_142 ) {
case V_621 :
case V_188 :
case V_622 :
break;
default:
goto error;
}
V_38 = F_21 ( V_2 , V_623 ,
( T_4 ) * V_142 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_38 ;
bool V_624 = false ;
bool V_625 = true ;
struct V_609 V_626 = { 0 , V_613 } ;
struct V_609 V_627 = { 0 , V_617 } ;
F_12 ( 1 , L_3 ) ;
V_38 = F_80 ( V_2 , & V_624 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_81 ( V_2 , & V_625 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_82 ( V_2 , & V_626 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_82 ( V_2 , & V_627 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_543 , V_2 -> V_156 . V_158 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_50 ( struct V_1 * V_2 ,
enum V_349 V_350 )
{
T_4 V_337 = 0 ;
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
F_79 ( V_2 ) ;
F_85 ( V_2 ) ;
V_38 = F_43 ( V_2 , V_340 | V_342 , 0 , NULL , 1 , & V_337 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_340 | V_628 , 0 , NULL , 1 , & V_337 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_343 , V_344 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_347 , V_348 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_629 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_630 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_631 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_632 , V_633 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_634 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_635 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_636 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_637 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_638 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_639 , 0x4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_640 , 0x4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_641 , 1600 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_642 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_643 , 448 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_644 , 495 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_37 ( V_2 , V_645 , V_646 , V_647 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_648 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_649 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_650 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_347 , V_651 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_74 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_71 ( V_2 , & V_2 -> V_159 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_338 , V_652 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_64 ( V_2 , & V_2 -> V_155 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_65 ( V_2 , & V_2 -> V_156 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_653 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_654 ;
V_38 = F_21 ( V_2 , V_653 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_338 , V_339 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_134 ) {
V_38 = F_21 ( V_2 , V_540 , V_2 -> V_156 . V_157 ) ;
if ( V_38 < 0 )
goto error;
}
#ifdef F_86
V_38 = F_21 ( V_2 , V_655 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_656 , 2 ) ;
if ( V_38 < 0 )
goto error;
#endif
V_38 = F_21 ( V_2 , V_657 , 1 ) ;
if ( V_38 < 0 )
goto error;
#ifdef F_86
V_38 = F_21 ( V_2 , V_658 , 0x400 ) ;
if ( V_38 < 0 )
goto error;
#else
V_38 = F_21 ( V_2 , V_658 , 0x1000 ) ;
if ( V_38 < 0 )
goto error;
#endif
V_38 = F_21 ( V_2 , V_659 , 0x0001 ) ;
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
T_4 V_586 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_586 = V_660 ;
V_38 = F_78 ( V_2 , V_594 , 0 , V_661 , V_586 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_60 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_662 , V_663 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_54 ( struct V_1 * V_2 , T_4 V_664 ,
T_6 V_511 )
{
T_4 V_337 = 0 ;
T_4 V_472 = 0 ;
T_4 V_665 = 0 ;
T_1 V_666 = 0 ;
T_1 V_667 = 0 ;
T_4 V_586 ;
int V_38 ;
F_12 ( 1 , L_42 , V_664 , V_511 ) ;
V_38 = F_43 ( V_2 , V_340 | V_341 , 0 , NULL , 1 , & V_337 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_338 , V_652 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_343 , V_344 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_668 , V_669 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_358 . V_670 ) {
case V_671 :
default:
V_665 |= V_672 ;
case V_673 :
V_472 |= V_674 ;
break;
case V_675 :
V_472 |= V_480 ;
break;
}
switch ( V_2 -> V_358 . V_676 ) {
default:
case V_677 :
V_665 |= V_678 ;
case V_679 :
V_472 |= V_680 ;
break;
case V_681 :
V_472 |= V_682 ;
break;
case V_683 :
V_472 |= V_684 ;
break;
case V_685 :
V_472 |= V_686 ;
break;
}
switch ( V_2 -> V_358 . V_687 ) {
case V_688 :
case V_689 :
default:
V_665 |= V_690 ;
case V_691 :
V_472 |= V_692 ;
break;
case V_693 :
V_472 |= V_694 ;
break;
case V_695 :
V_472 |= V_696 ;
break;
}
switch ( V_2 -> V_358 . V_452 ) {
case V_697 :
default:
V_665 |= V_698 ;
case V_457 :
V_472 |= V_699 ;
break;
case V_700 :
V_472 |= V_701 ;
break;
case V_453 :
V_472 |= V_702 ;
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
V_472 |= V_703 ;
V_38 = F_21 ( V_2 , V_704 , V_705 ) ;
if ( V_38 < 0 )
goto error;
#endif
switch ( V_2 -> V_358 . V_706 ) {
case V_707 :
default:
V_665 |= V_708 ;
case V_709 :
V_472 |= V_710 ;
break;
case V_711 :
V_472 |= V_712 ;
break;
case V_713 :
V_472 |= V_714 ;
break;
case V_715 :
V_472 |= V_716 ;
break;
case V_717 :
V_472 |= V_718 ;
break;
}
switch ( V_2 -> V_358 . V_719 ) {
case 0 :
V_2 -> V_358 . V_719 = 8000000 ;
case 8000000 :
V_667 = V_720 ;
V_38 = F_21 ( V_2 , V_721 , 3052 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_722 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_723 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_724 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_725 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
case 7000000 :
V_667 = V_726 ;
V_38 = F_21 ( V_2 , V_721 , 3491 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_722 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_723 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_724 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_725 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
case 6000000 :
V_667 = V_727 ;
V_38 = F_21 ( V_2 , V_721 , 4073 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_722 , 19 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_723 , 19 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_724 , 14 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_725 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
V_38 = - V_208 ;
goto error;
}
if ( V_666 == 0 ) {
V_666 = F_7 ( ( T_1 )
( ( V_2 -> V_125 *
1000 ) / 3 ) , V_667 ) ;
if ( ( V_666 & 0x7fL ) >= 0x40 )
V_666 += 0x80L ;
V_666 = V_666 >> 7 ;
V_666 = V_666 - ( 1 << 23 ) ;
}
V_666 &=
( ( ( ( T_1 ) V_728 ) <<
V_729 ) | V_730 ) ;
V_38 = F_23 ( V_2 , V_731 , V_666 ) ;
if ( V_38 < 0 )
goto error;
#if 0
status = DVBTSetFrequencyShift(demod, channel, tunerOffset);
if (status < 0)
goto error;
#endif
V_38 = F_75 ( V_2 , V_664 , V_511 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_338 , V_339 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_732 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_343 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_340 | V_733 , 0 , NULL , 1 , & V_337 ) ;
if ( V_38 < 0 )
goto error;
V_586 = ( V_672 |
V_678 |
V_698 |
V_690 |
V_708 ) ;
V_38 = F_78 ( V_2 , V_595 ,
0 , V_472 , V_586 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_134 )
V_38 = F_83 ( V_2 , & V_2 -> V_187 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 * V_361 )
{
int V_38 ;
const T_4 V_734 = ( V_735 |
V_736 ) ;
const T_4 V_737 = ( V_736 ) ;
const T_4 V_738 = V_739 ;
T_4 V_740 = 0 ;
T_4 V_741 = 0 ;
F_12 ( 1 , L_3 ) ;
* V_361 = V_362 ;
V_38 = F_17 ( V_2 , V_343 , & V_741 ) ;
if ( V_38 < 0 )
goto V_267;
if ( V_741 == V_344 )
goto V_267;
V_38 = F_17 ( V_2 , V_742 , & V_740 ) ;
if ( V_38 < 0 )
goto V_267;
if ( ( V_740 & V_734 ) == V_734 )
* V_361 = V_743 ;
else if ( ( V_740 & V_737 ) == V_737 )
* V_361 = V_744 ;
else if ( ( V_740 & V_738 ) == V_738 )
* V_361 = V_745 ;
else if ( V_740 & V_746 )
* V_361 = V_747 ;
V_267:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_87 ( struct V_1 * V_2 )
{
enum V_325 V_336 = V_328 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_46 ( V_2 , & V_336 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_48 ( struct V_1 * V_2 )
{
T_4 V_37 = 0 ;
T_4 V_337 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_338 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == V_339 ) {
V_38 = F_21 ( V_2 , V_748 , V_749 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_750 | V_341 , 0 , NULL , 1 , & V_337 ) ;
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
enum V_751 V_452 ,
T_1 V_752 )
{
T_1 V_753 = 0 ;
T_1 V_754 = 0 ;
T_4 V_755 = 0 ;
T_4 V_756 = 0 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_755 = 1 ;
switch ( V_452 ) {
case V_757 :
V_753 = 4 * V_752 ;
break;
case V_758 :
V_753 = 5 * V_752 ;
break;
case V_759 :
V_753 = 6 * V_752 ;
break;
case V_760 :
V_753 = 7 * V_752 ;
break;
case V_761 :
V_753 = 8 * V_752 ;
break;
default:
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
V_753 /= 1000 ;
V_753 *= 500 ;
V_754 = ( V_753 / 1632UL ) + 1 ;
V_755 = 1 + ( T_4 ) ( V_754 >> 16 ) ;
if ( V_755 == 0 ) {
V_38 = - V_208 ;
if ( V_38 < 0 )
goto error;
}
V_756 =
( ( T_4 ) V_754 +
( V_755 >> 1 ) ) / V_755 ;
V_38 = F_21 ( V_2 , V_658 , V_756 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_659 , V_755 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_762 , V_756 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_763 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_764 , 13517 ) ;
if ( V_38 < 0 )
goto error;
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
V_38 = F_21 ( V_2 , V_769 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 2 ) ;
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
V_38 = F_21 ( V_2 , V_774 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , V_454 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 32 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 95 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 120 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 230 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 105 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , ( T_4 ) 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , ( T_4 ) 220 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) - 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) - 65 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 127 ) ;
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
V_38 = F_21 ( V_2 , V_763 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_764 , 6707 ) ;
if ( V_38 < 0 )
goto error;
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
V_38 = F_21 ( V_2 , V_769 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 3 ) ;
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
V_38 = F_21 ( V_2 , V_774 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , V_456 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 90 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 170 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , ( T_4 ) 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , ( T_4 ) 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) - 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) - 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) - 26 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) - 56 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 86 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_763 , 13336 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_764 , 12618 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_765 , 11988 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , 13809 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_767 , 13809 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 15609 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , V_458 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 30 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 30 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 48 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 110 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 200 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 95 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , ( T_4 ) 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , ( T_4 ) 141 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) - 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) - 45 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 80 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_763 , 6564 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_764 , 6598 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_765 , 6394 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , 6409 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_767 , 6656 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 7238 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , V_460 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 120 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 64 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , ( T_4 ) 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , ( T_4 ) 65 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) - 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) - 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 23 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_763 , 11502 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_764 , 12084 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_765 , 12543 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , 12931 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_767 , 13629 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 15385 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , V_462 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 125 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 48 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 150 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 110 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , ( T_4 ) 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , ( T_4 ) 74 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , ( T_4 ) 18 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , ( T_4 ) 13 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 8 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_337 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_748 , V_749 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_750 | V_342 , 0 , NULL , 1 , & V_337 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_95 ( struct V_1 * V_2 )
{
T_1 V_815 = 0 ;
T_1 V_816 = 0 ;
T_1 V_817 = 0 ;
T_4 V_818 = 0 ;
T_1 V_819 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_815 = ( V_2 -> V_125 * 1000 ) / 3 ;
V_818 = 0 ;
if ( V_2 -> V_358 . V_820 <= 1188750 )
V_818 = 3 ;
else if ( V_2 -> V_358 . V_820 <= 2377500 )
V_818 = 2 ;
else if ( V_2 -> V_358 . V_820 <= 4755000 )
V_818 = 1 ;
V_38 = F_21 ( V_2 , V_821 , V_818 ) ;
if ( V_38 < 0 )
goto error;
V_816 = V_2 -> V_358 . V_820 * ( 1 << V_818 ) ;
if ( V_816 == 0 ) {
V_38 = - V_208 ;
goto error;
}
V_817 = ( V_815 / V_816 ) * ( 1 << 21 ) +
( F_7 ( ( V_815 % V_816 ) , V_816 ) >> 7 ) -
( 1 << 23 ) ;
V_38 = F_23 ( V_2 , V_731 , V_817 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_822 = V_817 ;
V_816 = V_2 -> V_358 . V_820 ;
if ( V_815 == 0 ) {
V_38 = - V_208 ;
goto error;
}
V_819 = ( V_816 / V_815 ) * ( 1 << 12 ) +
( F_7 ( ( V_816 % V_815 ) , V_815 ) >>
16 ) ;
if ( V_819 > 511 )
V_819 = 511 ;
V_38 = F_21 ( V_2 , V_823 , ( T_4 ) V_819 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_58 ( struct V_1 * V_2 , T_1 * V_361 )
{
int V_38 ;
T_4 V_824 [ 2 ] = { 0 , 0 } ;
F_12 ( 1 , L_3 ) ;
* V_361 = V_362 ;
V_38 = F_43 ( V_2 ,
V_750 |
V_825 , 0 , NULL , 2 ,
V_824 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_43 , V_62 , V_38 ) ;
if ( V_824 [ 1 ] < V_826 ) {
} else if ( V_824 [ 1 ] < V_827 ) {
* V_361 = V_745 ;
} else if ( V_824 [ 1 ] < V_828 ) {
* V_361 = V_743 ;
} else {
* V_361 = V_747 ;
}
return V_38 ;
}
static int F_53 ( struct V_1 * V_2 , T_4 V_664 ,
T_6 V_511 )
{
int V_38 ;
T_4 V_829 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 V_337 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_830 , V_831 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_832 , V_833 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_94 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_95 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_358 . V_452 ) {
case V_461 :
V_2 -> V_181 = V_761 ;
break;
case V_697 :
case V_457 :
V_2 -> V_181 = V_759 ;
break;
case V_453 :
V_2 -> V_181 = V_757 ;
break;
case V_455 :
V_2 -> V_181 = V_758 ;
break;
case V_459 :
V_2 -> V_181 = V_760 ;
break;
default:
V_38 = - V_208 ;
break;
}
if ( V_38 < 0 )
goto error;
V_829 [ 0 ] = V_2 -> V_181 ;
V_829 [ 1 ] = V_184 ;
if ( V_2 -> V_3 == V_7 )
V_829 [ 2 ] = V_834 ;
else
V_829 [ 2 ] = V_835 ;
V_829 [ 3 ] |= ( V_836 ) ;
V_38 = F_43 ( V_2 , V_750 | V_837 , 4 , V_829 , 1 , & V_337 ) ;
if ( V_38 < 0 ) {
if ( V_2 -> V_3 == V_7 )
V_829 [ 0 ] = V_834 ;
else
V_829 [ 0 ] = V_835 ;
V_38 = F_43 ( V_2 , V_750 | V_628 , 1 , V_829 , 1 , & V_337 ) ;
if ( V_38 < 0 )
goto error;
V_829 [ 0 ] = V_2 -> V_181 ;
V_829 [ 1 ] = V_184 ;
V_38 = F_43 ( V_2 , V_750 | V_837 , 2 , V_829 , 1 , & V_337 ) ;
}
if ( V_38 < 0 )
goto error;
#if 0
status = SetFrequency(channel, tunerFreqOffset));
if (status < 0)
goto error;
#endif
V_38 = F_75 ( V_2 , V_664 , V_511 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_88 ( V_2 , V_2 -> V_181 , V_2 -> V_358 . V_820 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_642 , V_838 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_839 , V_840 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_841 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_842 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_843 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_844 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_845 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_846 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_847 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_848 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_849 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_850 , 2 ) ;
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
V_38 = F_21 ( V_2 , V_856 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_857 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_858 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_859 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_860 , V_861 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_338 , V_652 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_358 . V_452 ) {
case V_453 :
V_38 = F_89 ( V_2 ) ;
break;
case V_455 :
V_38 = F_90 ( V_2 ) ;
break;
case V_697 :
case V_457 :
V_38 = F_91 ( V_2 ) ;
break;
case V_459 :
V_38 = F_92 ( V_2 ) ;
break;
case V_461 :
V_38 = F_93 ( V_2 ) ;
break;
default:
V_38 = - V_208 ;
break;
}
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_338 , V_339 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_62 ( V_2 , V_2 -> V_3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_60 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_662 , V_663 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_748 , V_862 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_347 , V_651 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_750 | V_733 , 0 , NULL , 1 , & V_337 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_349 V_350 )
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
V_38 = F_21 ( V_2 , V_347 , V_348 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_632 , V_633 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_350 ) {
case V_5 :
V_38 = F_37 ( V_2 , V_863 , V_646 , V_647 ) ;
break;
case V_7 :
V_38 = F_72 ( V_2 , V_864 , V_865 , V_866 , V_647 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_72 ( V_2 , V_867 , V_865 , V_866 , V_647 ) ;
break;
default:
V_38 = - V_208 ;
}
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_639 , ( 1 << V_868 ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_869 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_870 , ( ( 1 << V_871 ) | ( 1 << V_872 ) ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_638 , 21 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_630 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_643 , 448 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_631 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_649 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_873 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_874 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_875 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_629 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_876 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_644 , 1000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_606 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_636 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_637 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_648 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_877 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_501 , 0x01 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_74 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_878 , 2000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_338 , V_652 ) ;
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
V_38 = F_21 ( V_2 , V_338 , V_339 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_879 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_197 , V_198 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_199 , V_200 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_215 ) {
if ( V_2 -> V_880 & 0x0001 ) {
V_38 = F_21 ( V_2 , V_881 , V_2 -> V_190 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_882 , & V_879 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_883 & 0x0001 ) == 0 )
V_879 &= 0x7FFF ;
else
V_879 |= 0x8000 ;
V_38 = F_21 ( V_2 , V_882 , V_879 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_2 -> V_880 & 0x0002 ) {
V_38 = F_21 ( V_2 , V_884 , V_2 -> V_190 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_882 , & V_879 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_883 & 0x0002 ) == 0 )
V_879 &= 0xBFFF ;
else
V_879 |= 0x4000 ;
V_38 = F_21 ( V_2 , V_882 , V_879 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_2 -> V_880 & 0x0004 ) {
V_38 = F_21 ( V_2 , V_885 , V_2 -> V_190 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_882 , & V_879 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_883 & 0x0004 ) == 0 )
V_879 &= 0xFFFB ;
else
V_879 |= 0x0004 ;
V_38 = F_21 ( V_2 , V_882 , V_879 ) ;
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
V_886 = V_2 -> V_883 & V_2 -> V_887 ;
if ( V_2 -> V_888 ^ V_886 ) {
if ( V_2 -> V_888 )
V_2 -> V_883 &= ~ V_2 -> V_887 ;
else
V_2 -> V_883 |= V_2 -> V_887 ;
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
V_886 = V_2 -> V_883 & V_2 -> V_887 ;
if ( ! ( V_2 -> V_888 ^ V_886 ) ) {
if ( V_2 -> V_888 )
V_2 -> V_883 |= V_2 -> V_887 ;
else
V_2 -> V_883 &= ~ V_2 -> V_887 ;
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
V_38 = F_21 ( V_2 , V_65 , V_331 ) ;
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
int V_312 = 0 ;
F_12 ( 1 , L_3 ) ;
V_312 = F_102 ( & V_891 , V_889 , V_2 -> V_51 -> V_892 . V_893 ) ;
if ( V_312 < 0 ) {
F_13 ( V_43
L_44 , V_889 ) ;
F_13 ( V_219
L_45 , V_889 ) ;
return V_312 ;
}
V_312 = F_40 ( V_2 , V_891 -> V_37 , V_891 -> V_894 ) ;
F_103 ( V_891 ) ;
return V_312 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
enum V_325 V_336 = V_328 ;
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
V_38 = F_21 ( V_2 , V_338 , V_906 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_289 , V_283 ) ;
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
V_38 = F_21 ( V_2 , V_289 , V_286 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_338 , V_339 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_28 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
F_26 ( 30 ) ;
V_336 = V_328 ;
V_38 = F_46 ( V_2 , & V_336 ) ;
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
V_38 = F_21 ( V_2 , V_662 , V_916 ) ;
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
V_2 -> V_165 = V_355 ;
if ( V_2 -> V_132 ) {
V_38 = F_100 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_165 = V_482 ;
} else
V_2 -> V_165 = V_355 ;
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
static int F_108 ( struct V_917 * V_918 , int V_281 )
{
struct V_1 * V_2 = V_918 -> V_919 ;
F_12 ( 1 , L_47 , V_281 ? L_24 : L_25 ) ;
return F_70 ( V_2 , V_281 ? true : false ) ;
}
static int F_109 ( struct V_917 * V_918 )
{
struct V_920 * V_307 = & V_918 -> V_921 ;
T_1 V_922 = V_307 -> V_923 , V_924 ;
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
V_924 = V_2 -> V_358 . V_923 ;
V_2 -> V_358 = * V_307 ;
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
if ( V_934 == V_743 )
* V_38 |= 0x1f ;
if ( V_934 == V_744 )
* V_38 |= 0x0f ;
if ( V_934 == V_745 )
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
T_4 V_312 ;
F_12 ( 1 , L_3 ) ;
F_77 ( V_2 , & V_312 ) ;
* V_939 = ( T_1 ) V_312 ;
return 0 ;
}
static int F_115 ( struct V_917 * V_918 , struct V_940
* V_941 )
{
struct V_920 * V_307 = & V_918 -> V_921 ;
F_12 ( 1 , L_3 ) ;
switch ( V_307 -> V_923 ) {
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
V_2 -> V_483 = V_946 -> V_483 ;
V_2 -> V_887 = V_946 -> V_887 ;
V_2 -> V_888 = V_946 -> V_888 ;
V_2 -> V_59 = V_946 -> V_949 ;
V_2 -> V_261 = V_946 -> V_261 ;
if ( V_946 -> V_950 ) {
V_2 -> V_390 = 0 ;
V_2 -> V_391 = 0 ;
} else {
V_2 -> V_390 = 1 ;
V_2 -> V_391 = 1 ;
}
if ( V_946 -> V_951 )
V_2 -> V_259 = V_946 -> V_951 & 0x07 ;
else
V_2 -> V_259 = 0x06 ;
if ( V_946 -> V_952 )
V_2 -> V_245 = true ;
else
V_2 -> V_245 = false ;
V_2 -> V_880 = V_946 -> V_887 ;
if ( ! V_2 -> V_888 && V_2 -> V_887 )
V_2 -> V_883 |= V_2 -> V_887 ;
else
V_2 -> V_883 &= ~ V_2 -> V_887 ;
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
