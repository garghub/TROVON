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
T_1 V_102 = 1 ;
T_1 V_103 = 1 ;
T_1 V_104 = V_105 ;
T_1 V_106 = V_107 ;
T_1 V_108 = 0x0113 ;
T_1 V_109 = 1 ;
T_1 V_110 = 0 ;
T_1 V_111 = V_112 ;
T_1 V_113 = V_114 ;
T_1 V_115 = 50000000 ;
T_1 V_116 = V_117 * 8 ;
T_1 V_118 = 0 ;
T_1 V_119 = 1 ;
T_1 V_120 = 0 ;
F_12 ( 1 , L_3 ) ;
V_2 -> V_121 = false ;
V_2 -> V_122 = false ;
V_2 -> V_123 = false ;
V_2 -> V_124 = false ;
V_2 -> V_125 = false ;
V_2 -> V_126 = false ;
V_2 -> V_59 = 124 ;
V_2 -> V_127 = 0 ;
V_2 -> V_128 = false ;
V_2 -> V_129 = false ;
V_2 -> V_130 = 151875 ;
V_2 -> V_131 = ( ( V_2 -> V_130 / 1000 ) *
V_132 ) / 1000 ;
if ( V_2 -> V_131 > V_133 )
V_2 -> V_131 = V_133 ;
V_2 -> V_134 = ( V_2 -> V_47 << 1 ) ;
V_2 -> V_135 = V_136 ;
V_2 -> V_137 = ( V_120 != 0 ) ;
V_2 -> V_8 = false ;
V_2 -> V_9 = false ;
V_2 -> V_138 = false ;
V_2 -> V_139 = false ;
V_2 -> V_140 = false ;
V_2 -> V_141 = false ;
V_2 -> V_142 . V_143 = ( V_72 ) ;
V_2 -> V_142 . V_144 = ( V_74 ) ;
V_2 -> V_142 . V_145 = ( V_75 ) ;
V_2 -> V_142 . V_146 = ( V_76 ) ;
V_2 -> V_142 . V_147 = ( V_77 ) ;
V_2 -> V_148 = 140 ;
V_2 -> V_149 . V_143 = ( V_78 ) ;
V_2 -> V_149 . V_144 = ( V_79 ) ;
V_2 -> V_149 . V_145 = ( V_80 ) ;
V_2 -> V_149 . V_146 = ( V_81 ) ;
V_2 -> V_149 . V_147 = ( V_82 ) ;
V_2 -> V_149 . V_150 = ( V_83 ) ;
V_2 -> V_149 . V_151 = ( V_84 ) ;
V_2 -> V_152 . V_153 = 0x07 ;
V_2 -> V_152 . V_154 = true ;
V_2 -> V_155 = V_99 ;
V_2 -> V_156 = V_101 ;
if ( V_100 <= 500 && V_98 < V_100 ) {
V_2 -> V_155 = V_98 ;
V_2 -> V_156 = V_100 ;
}
V_2 -> V_157 . V_143 = ( V_85 ) ;
V_2 -> V_157 . V_144 = ( V_86 ) ;
V_2 -> V_157 . V_145 = ( V_87 ) ;
V_2 -> V_157 . V_146 = ( V_88 ) ;
V_2 -> V_157 . V_147 = ( V_89 ) ;
V_2 -> V_158 . V_143 = ( V_90 ) ;
V_2 -> V_158 . V_144 = ( V_92 ) ;
V_2 -> V_158 . V_145 = ( V_93 ) ;
V_2 -> V_158 . V_146 = ( V_94 ) ;
V_2 -> V_158 . V_147 = ( V_97 ) ;
V_2 -> V_158 . V_150 = ( V_95 ) ;
V_2 -> V_158 . V_151 = ( V_96 ) ;
V_2 -> V_159 . V_153 = 0x04 ;
V_2 -> V_159 . V_154 = true ;
V_2 -> V_160 . V_143 = V_91 ;
V_2 -> V_160 . V_144 = 0 ;
V_2 -> V_160 . V_145 = 0 ;
V_2 -> V_160 . V_146 = 0xFFFF ;
V_2 -> V_160 . V_150 = 0x2100 ;
V_2 -> V_160 . V_151 = 4000 ;
V_2 -> V_160 . V_147 = 1 ;
V_2 -> V_161 . V_143 = V_73 ;
V_2 -> V_161 . V_144 = 0 ;
V_2 -> V_161 . V_145 = 0 ;
V_2 -> V_161 . V_146 = 9000 ;
V_2 -> V_161 . V_150 = 13424 ;
V_2 -> V_161 . V_151 = 0 ;
V_2 -> V_161 . V_147 = 3 ;
V_2 -> V_161 . V_162 = 30 ;
V_2 -> V_161 . V_163 = 30000 ;
V_2 -> V_164 . V_153 = 4 ;
V_2 -> V_164 . V_154 = false ;
V_2 -> V_165 . V_143 = V_91 ;
V_2 -> V_165 . V_144 = 0 ;
V_2 -> V_165 . V_145 = 6023 ;
V_2 -> V_165 . V_146 = 27000 ;
V_2 -> V_165 . V_150 = 0x2380 ;
V_2 -> V_165 . V_151 = 4000 ;
V_2 -> V_165 . V_147 = 3 ;
V_2 -> V_166 . V_143 = V_73 ;
V_2 -> V_166 . V_144 = 0 ;
V_2 -> V_166 . V_145 = 0 ;
V_2 -> V_166 . V_146 = 9000 ;
V_2 -> V_166 . V_150 = 0x0511 ;
V_2 -> V_166 . V_151 = 0 ;
V_2 -> V_166 . V_147 = 3 ;
V_2 -> V_166 . V_163 = 5119 ;
V_2 -> V_166 . V_162 = 50 ;
V_2 -> V_167 = 140 ;
V_2 -> V_168 . V_153 = 4 ;
V_2 -> V_168 . V_154 = false ;
V_2 -> V_3 = V_169 ;
V_2 -> V_170 = V_171 ;
V_2 -> V_172 = true ;
V_2 -> V_173 = false ;
V_2 -> V_174 = true ;
V_2 -> V_175 = false ;
V_2 -> V_176 = false ;
V_2 -> V_177 = false ;
V_2 -> V_178 = false ;
V_2 -> V_179 = ( V_110 != 0 ) ;
V_2 -> V_180 = ( V_102 != 0 ) ;
V_2 -> V_181 = ( V_103 != 0 ) ;
V_2 -> V_182 = V_115 ;
V_2 -> V_183 = V_116 ;
V_2 -> V_184 = ( V_111 & 0x07 ) ;
V_2 -> V_185 = ( V_113 & 0x07 ) ;
V_2 -> V_186 = 19392658 ;
V_2 -> V_187 = false ;
if ( V_118 )
V_2 -> V_173 = true ;
V_2 -> V_188 = V_105 ;
if ( V_104 < 10000 )
V_2 -> V_188 = V_104 ;
V_2 -> V_189 = V_107 ;
if ( V_106 < 10000 )
V_2 -> V_189 = V_106 ;
V_2 -> V_190 = V_191 ;
V_2 -> V_192 = V_193 ;
V_2 -> V_194 = 204 * 8 ;
V_2 -> V_195 = 1 ;
V_2 -> V_196 = V_197 ;
V_2 -> V_198 = 0 ;
V_2 -> V_199 = ( V_108 ) ;
V_2 -> V_137 = false ;
V_2 -> V_70 = V_200 ;
V_2 -> V_174 = ( V_109 == 0 ) ;
V_2 -> V_201 = ( V_119 == 0 ) ;
V_2 -> V_202 = false ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
T_1 V_203 = 0 ;
T_4 V_204 = 0 ;
T_4 V_205 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_206 , V_207 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_208 , & V_205 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_208 , V_209 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_19 ( V_2 , V_210 , & V_203 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_211 , & V_204 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_208 , V_205 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_4 V_212 = 0 ;
T_1 V_213 = 0 ;
int V_38 ;
const char * V_214 = L_14 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_206 , V_207 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_208 , 0xFABA ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_215 , & V_212 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_208 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
switch ( ( V_212 & V_216 ) ) {
case 0 :
break;
case 1 :
V_2 -> V_127 = 27000 ;
break;
case 2 :
V_2 -> V_127 = 20250 ;
break;
case 3 :
V_2 -> V_127 = 20250 ;
break;
default:
F_13 ( V_43 L_15 ) ;
return - V_217 ;
}
V_38 = F_19 ( V_2 , V_210 , & V_213 ) ;
if ( V_38 < 0 )
goto error;
switch ( ( V_213 >> 29 ) & 0xF ) {
case 0 :
V_2 -> V_218 = V_219 ;
V_214 = L_16 ;
break;
case 2 :
V_2 -> V_218 = V_220 ;
V_214 = L_17 ;
break;
case 3 :
V_2 -> V_218 = V_221 ;
V_214 = L_18 ;
break;
default:
V_2 -> V_218 = V_222 ;
V_38 = - V_217 ;
F_13 ( V_43 L_19 ) ;
goto V_223;
}
switch ( ( V_213 >> 12 ) & 0xFF ) {
case 0x13 :
V_2 -> V_121 = false ;
V_2 -> V_125 = false ;
V_2 -> V_124 = false ;
V_2 -> V_126 = false ;
V_2 -> V_122 = true ;
V_2 -> V_123 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = false ;
V_2 -> V_226 = false ;
V_2 -> V_227 = false ;
break;
case 0x15 :
V_2 -> V_121 = false ;
V_2 -> V_125 = false ;
V_2 -> V_124 = true ;
V_2 -> V_126 = false ;
V_2 -> V_122 = true ;
V_2 -> V_123 = false ;
V_2 -> V_224 = true ;
V_2 -> V_225 = true ;
V_2 -> V_226 = true ;
V_2 -> V_227 = false ;
break;
case 0x16 :
V_2 -> V_121 = false ;
V_2 -> V_125 = false ;
V_2 -> V_124 = true ;
V_2 -> V_126 = false ;
V_2 -> V_122 = true ;
V_2 -> V_123 = false ;
V_2 -> V_224 = true ;
V_2 -> V_225 = true ;
V_2 -> V_226 = true ;
V_2 -> V_227 = false ;
break;
case 0x18 :
V_2 -> V_121 = false ;
V_2 -> V_125 = false ;
V_2 -> V_124 = true ;
V_2 -> V_126 = true ;
V_2 -> V_122 = true ;
V_2 -> V_123 = false ;
V_2 -> V_224 = true ;
V_2 -> V_225 = true ;
V_2 -> V_226 = true ;
V_2 -> V_227 = false ;
break;
case 0x21 :
V_2 -> V_121 = false ;
V_2 -> V_125 = false ;
V_2 -> V_124 = true ;
V_2 -> V_126 = true ;
V_2 -> V_122 = true ;
V_2 -> V_123 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = true ;
V_2 -> V_226 = true ;
V_2 -> V_227 = false ;
break;
case 0x23 :
V_2 -> V_121 = false ;
V_2 -> V_125 = false ;
V_2 -> V_124 = true ;
V_2 -> V_126 = true ;
V_2 -> V_122 = true ;
V_2 -> V_123 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = true ;
V_2 -> V_226 = true ;
V_2 -> V_227 = false ;
break;
case 0x25 :
V_2 -> V_121 = false ;
V_2 -> V_125 = false ;
V_2 -> V_124 = true ;
V_2 -> V_126 = true ;
V_2 -> V_122 = true ;
V_2 -> V_123 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = true ;
V_2 -> V_226 = true ;
V_2 -> V_227 = false ;
break;
case 0x26 :
V_2 -> V_121 = false ;
V_2 -> V_125 = false ;
V_2 -> V_124 = true ;
V_2 -> V_126 = false ;
V_2 -> V_122 = true ;
V_2 -> V_123 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = true ;
V_2 -> V_226 = true ;
V_2 -> V_227 = false ;
break;
default:
F_13 ( V_43 L_20 ,
( ( V_213 >> 12 ) & 0xFF ) ) ;
V_38 = - V_217 ;
goto V_223;
}
F_13 ( V_228
L_21 ,
( ( V_213 >> 12 ) & 0xFF ) , V_214 ,
V_2 -> V_127 / 1000 ,
V_2 -> V_127 % 1000 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_223:
return V_38 ;
}
static int F_30 ( struct V_1 * V_2 , T_4 V_229 , T_4 * V_230 )
{
int V_38 ;
bool V_231 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_232 , V_229 ) ;
if ( V_38 < 0 )
goto error;
if ( V_229 == V_233 )
F_26 ( 1 ) ;
V_231 =
( bool ) ( ( V_229 == V_234 ) &&
( ( V_2 -> V_135 ) &
V_235 ) ==
V_236 ) ;
if ( V_231 == false ) {
T_1 V_63 = 0 ;
T_4 V_237 ;
do {
F_26 ( 1 ) ;
V_63 += 1 ;
V_38 = F_17 ( V_2 , V_232 ,
& V_237 ) ;
} while ( ( V_38 < 0 ) && ( V_63 < V_238 )
&& ( V_237 != 0 ) );
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_239 , V_230 ) ;
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
F_32 ( & V_2 -> V_240 ) ;
V_38 = F_21 ( V_2 , V_241 , V_2 -> V_242 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_243 , V_2 -> V_135 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_244 , V_2 -> V_134 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_245 , V_2 -> V_246 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_247 , V_2 -> V_131 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_248 , V_249 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_30 ( V_2 , V_234 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_135 &= ~ V_236 ;
error:
F_33 ( & V_2 -> V_240 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_34 ( struct V_1 * V_2 )
{
F_12 ( 1 , L_3 ) ;
V_2 -> V_134 = ( V_2 -> V_47 << 1 ) ;
V_2 -> V_242 = 0x96FF ;
V_2 -> V_135 = V_136 ;
return F_31 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 , bool V_250 )
{
int V_38 = - 1 ;
T_4 V_251 = 0 ;
T_4 V_252 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_206 , V_207 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_208 , 0xFABA ) ;
if ( V_38 < 0 )
goto error;
if ( V_250 == false ) {
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
V_38 = F_21 ( V_2 , V_258 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_259 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_260 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_261 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_262 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_263 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_264 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_252 =
( ( V_2 -> V_184 <<
V_265 ) | 0x0003 ) ;
V_251 = ( ( V_2 -> V_185 <<
V_266 ) |
0x0003 ) ;
V_38 = F_21 ( V_2 , V_253 , V_252 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_254 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_256 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_174 == true ) {
V_38 = F_21 ( V_2 , V_258 , V_252 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_259 , V_252 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_260 , V_252 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_261 , V_252 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_262 , V_252 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_263 , V_252 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_264 , V_252 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_252 = ( ( V_2 -> V_184 <<
V_265 )
| 0x0003 ) ;
V_38 = F_21 ( V_2 , V_258 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_259 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_260 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_261 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_262 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_263 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_264 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_255 , V_251 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_257 , V_252 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_267 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_208 , 0x0000 ) ;
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
T_4 V_268 , T_4 V_269 , T_1 V_270 )
{
T_4 V_271 = 0 ;
int V_38 ;
unsigned long V_272 ;
F_12 ( 1 , L_3 ) ;
F_32 ( & V_2 -> V_240 ) ;
V_38 = F_21 ( V_2 , V_273 , V_274 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_275 , V_268 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_276 , V_269 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_277 , V_278 ) ;
if ( V_38 < 0 )
goto error;
V_272 = V_279 + F_38 ( V_270 ) ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_280 , & V_271 ) ;
if ( V_38 < 0 )
goto error;
} while ( ( V_271 == 0x1 ) &&
( ( F_39 ( V_272 ) ) ) );
if ( V_271 == 0x1 ) {
F_13 ( V_43 L_22 ) ;
V_38 = - V_217 ;
goto V_223;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_223:
F_33 ( & V_2 -> V_240 ) ;
return V_38 ;
}
static int F_40 ( struct V_1 * V_2 ,
const T_3 V_281 [] , T_1 V_282 )
{
const T_3 * V_283 = V_281 ;
T_4 V_57 ;
T_4 V_284 ;
T_1 V_53 ;
T_4 V_285 ;
T_4 V_54 ;
T_4 V_286 ;
T_1 V_287 = 0 ;
T_1 V_14 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_284 = ( V_283 [ 0 ] << 8 ) | V_283 [ 1 ] ;
V_283 += sizeof( T_4 ) ;
V_287 += sizeof( T_4 ) ;
V_285 = ( V_283 [ 0 ] << 8 ) | V_283 [ 1 ] ;
V_283 += sizeof( T_4 ) ;
V_287 += sizeof( T_4 ) ;
for ( V_14 = 0 ; V_14 < V_285 ; V_14 += 1 ) {
V_53 = ( V_283 [ 0 ] << 24 ) | ( V_283 [ 1 ] << 16 ) |
( V_283 [ 2 ] << 8 ) | V_283 [ 3 ] ;
V_283 += sizeof( T_1 ) ;
V_287 += sizeof( T_1 ) ;
V_54 = ( ( V_283 [ 0 ] << 8 ) | V_283 [ 1 ] ) * sizeof( T_4 ) ;
V_283 += sizeof( T_4 ) ;
V_287 += sizeof( T_4 ) ;
V_57 = ( V_283 [ 0 ] << 8 ) | V_283 [ 1 ] ;
V_283 += sizeof( T_4 ) ;
V_287 += sizeof( T_4 ) ;
V_286 = ( V_283 [ 0 ] << 8 ) | V_283 [ 1 ] ;
V_283 += sizeof( T_4 ) ;
V_287 += sizeof( T_4 ) ;
if ( V_287 + V_54 > V_282 ) {
F_13 ( V_43 L_23 ) ;
return - V_217 ;
}
V_38 = F_24 ( V_2 , V_53 , V_54 , V_283 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_24 , V_38 ) ;
break;
}
V_283 += V_54 ;
V_287 += V_54 ;
}
return V_38 ;
}
static int F_41 ( struct V_1 * V_2 , bool V_288 )
{
int V_38 ;
T_4 V_37 = 0 ;
T_4 V_289 = V_290 ;
T_4 V_291 = V_292 ;
unsigned long V_272 ;
F_12 ( 1 , L_3 ) ;
if ( V_288 == false ) {
V_289 = V_293 ;
V_291 = V_294 ;
}
V_38 = F_17 ( V_2 , V_295 , & V_37 ) ;
if ( V_38 >= 0 && V_37 == V_291 ) {
return V_38 ;
}
V_38 = F_21 ( V_2 , V_296 , V_289 ) ;
V_272 = V_279 + F_38 ( V_297 ) ;
do {
V_38 = F_17 ( V_2 , V_295 , & V_37 ) ;
if ( ( V_38 >= 0 && V_37 == V_291 ) || F_39 ( V_272 ) )
break;
F_26 ( 1 ) ;
} while ( 1 );
if ( V_37 != V_291 ) {
F_13 ( V_43 L_22 ) ;
return - V_217 ;
}
return V_38 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
T_4 V_298 = 0 ;
T_4 V_299 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_300 , & V_298 ) ;
if ( V_38 < 0 )
goto error;
V_298 |= V_301 ;
V_38 = F_21 ( V_2 , V_300 , V_298 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_302 , & V_299 ) ;
if ( V_38 < 0 )
goto error;
V_299 |= V_303 ;
V_38 = F_21 ( V_2 , V_302 , V_299 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_4 V_229 , T_3 V_304 ,
T_4 * V_305 , T_3 V_306 , T_4 * V_307 )
{
#if ( V_308 - V_309 ) != 15
#error DRXK register mapping no longer compatible with this routine!
#endif
T_4 V_310 = 0 ;
int V_38 = - V_217 ;
unsigned long V_272 ;
T_3 V_311 [ 34 ] ;
int V_312 = 0 , V_313 ;
const char * V_314 ;
char V_315 [ 30 ] ;
F_12 ( 1 , L_3 ) ;
if ( ( V_229 == 0 ) || ( ( V_304 > 0 ) && ( V_305 == NULL ) ) ||
( ( V_306 > 0 ) && ( V_307 == NULL ) ) )
goto error;
F_32 ( & V_2 -> V_240 ) ;
for ( V_313 = V_304 - 1 ; V_313 >= 0 ; V_313 -= 1 ) {
V_311 [ V_312 ++ ] = ( V_305 [ V_313 ] & 0xFF ) ;
V_311 [ V_312 ++ ] = ( ( V_305 [ V_313 ] >> 8 ) & 0xFF ) ;
}
V_311 [ V_312 ++ ] = ( V_229 & 0xFF ) ;
V_311 [ V_312 ++ ] = ( ( V_229 >> 8 ) & 0xFF ) ;
F_24 ( V_2 , V_308 -
( V_304 - 1 ) , V_312 , V_311 ) ;
V_272 = V_279 + F_38 ( V_316 ) ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_317 , & V_310 ) ;
if ( V_38 < 0 )
goto error;
} while ( ! ( V_310 == V_318 ) && ( F_39 ( V_272 ) ) );
if ( V_310 != V_318 ) {
F_13 ( V_43 L_25 ) ;
V_38 = - V_42 ;
goto V_223;
}
if ( ( V_306 > 0 ) && ( V_307 != NULL ) ) {
T_5 V_319 ;
int V_313 ;
for ( V_313 = V_306 - 1 ; V_313 >= 0 ; V_313 -= 1 ) {
V_38 = F_17 ( V_2 , V_308 - V_313 , & V_307 [ V_313 ] ) ;
if ( V_38 < 0 )
goto error;
}
V_319 = ( T_5 ) V_307 [ 0 ] ;
if ( V_319 >= 0 )
goto error;
switch ( V_319 ) {
case V_320 :
V_314 = L_26 ;
break;
case V_321 :
V_314 = L_27 ;
break;
case V_322 :
V_314 = L_28 ;
break;
case V_323 :
V_314 = L_29 ;
break;
default:
sprintf ( V_315 , L_30 , V_319 ) ;
V_314 = V_315 ;
}
F_13 ( V_43 L_31 , V_314 , V_229 ) ;
F_44 ( L_32 , V_324 , V_311 , V_312 ) ;
V_38 = - V_217 ;
goto V_223;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_223:
F_33 ( & V_2 -> V_240 ) ;
return V_38 ;
}
static int F_45 ( struct V_1 * V_2 , bool V_325 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_326 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_325 ) {
V_37 |= ( V_327
| V_328
| V_329
| V_330
| V_331 ) ;
} else {
V_37 &= ( ( ~ V_327 )
& ( ~ V_328 )
& ( ~ V_329 )
& ( ~ V_330 )
& ( ~ V_331 )
) ;
}
V_38 = F_21 ( V_2 , V_326 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_46 ( struct V_1 * V_2 , enum V_332 * V_333 )
{
int V_38 = 0 ;
T_4 V_334 = 0 ;
F_12 ( 1 , L_3 ) ;
if ( V_333 == NULL )
return - V_217 ;
switch ( * V_333 ) {
case V_71 :
V_334 = V_66 ;
break;
case V_335 :
V_334 = V_336 ;
break;
case V_337 :
V_334 = V_338 ;
break;
case V_339 :
V_334 = V_340 ;
break;
case V_200 :
V_334 = V_341 ;
break;
default:
return - V_217 ;
}
if ( V_2 -> V_70 == * V_333 )
return 0 ;
if ( V_2 -> V_70 != V_71 ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_41 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
}
if ( * V_333 == V_71 ) {
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
V_38 = F_21 ( V_2 , V_65 , V_334 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
if ( * V_333 != V_335 ) {
V_2 -> V_135 |=
V_236 ;
V_38 = F_31 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
}
}
V_2 -> V_70 = * V_333 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_47 ( struct V_1 * V_2 , bool V_342 )
{
enum V_332 V_343 = V_335 ;
T_4 V_344 = 0 ;
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_345 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == V_346 ) {
V_38 = F_43 ( V_2 , V_347 | V_348 , 0 , NULL , 1 , & V_344 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_347 | V_349 , 0 , NULL , 1 , & V_344 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_350 , V_351 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_352 , V_353 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_354 , V_355 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
if ( V_342 ) {
V_38 = F_46 ( V_2 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_49 ( struct V_1 * V_2 ,
enum V_356 V_357 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_206 , V_207 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_3 == V_357 )
return 0 ;
switch ( V_2 -> V_3 ) {
case V_169 :
break;
case V_4 :
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_47 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_3 = V_169 ;
break;
case V_5 :
case V_7 :
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_48 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_3 = V_169 ;
break;
case V_6 :
default:
V_38 = - V_217 ;
goto error;
}
switch ( V_357 ) {
case V_4 :
V_2 -> V_3 = V_357 ;
V_38 = F_50 ( V_2 , V_357 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_5 :
case V_7 :
V_2 -> V_3 = V_357 ;
V_38 = F_51 ( V_2 , V_357 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_6 :
default:
V_38 = - V_217 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_52 ( struct V_1 * V_2 , T_6 V_358 ,
T_6 V_359 )
{
int V_38 = - V_217 ;
T_4 V_360 ;
T_6 V_361 = V_358 / 1000 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_170 != V_362 &&
V_2 -> V_170 != V_363 )
goto error;
V_2 -> V_364 = ( V_2 -> V_365 . V_366 == V_367 ) ;
if ( V_359 < 0 ) {
V_2 -> V_364 = ! V_2 -> V_364 ;
V_359 = - V_359 ;
}
switch ( V_2 -> V_3 ) {
case V_5 :
case V_7 :
V_360 = ( V_359 / 1000 ) ;
V_38 = F_53 ( V_2 , V_360 , V_361 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_170 = V_363 ;
break;
case V_4 :
V_360 = ( V_359 / 1000 ) ;
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_54 ( V_2 , V_360 , V_361 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_55 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_170 = V_363 ;
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
static int F_57 ( struct V_1 * V_2 , T_1 * V_368 ,
T_1 Time )
{
int V_38 = - V_217 ;
F_12 ( 1 , L_3 ) ;
if ( V_368 == NULL )
goto error;
* V_368 = V_369 ;
switch ( V_2 -> V_3 ) {
case V_5 :
case V_6 :
case V_7 :
V_38 = F_58 ( V_2 , V_368 ) ;
break;
case V_4 :
V_38 = F_59 ( V_2 , V_368 ) ;
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
T_4 V_298 = 0 ;
V_38 = F_17 ( V_2 , V_300 , & V_298 ) ;
if ( V_38 < 0 )
goto error;
V_298 &= ~ V_301 ;
V_38 = F_21 ( V_2 , V_300 , V_298 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_370 , 1 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_371 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_372 , 0x000C ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_373 , 0x000A ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_374 , 0x0008 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_375 , 0x0006 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_376 , 0x0680 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_377 , 0x0080 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_378 , 0x03F4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_379 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_380 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_381 , 12 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_62 ( struct V_1 * V_2 ,
enum V_356 V_357 )
{
int V_38 ;
T_4 V_382 = 0 ;
T_4 V_383 = 0 ;
T_4 V_384 = 0 ;
T_4 V_385 = 0 ;
T_4 V_386 = 2 ;
T_4 V_387 = 188 ;
T_1 V_388 = 0 ;
T_4 V_389 = 0 ;
T_4 V_390 = 0 ;
T_1 V_391 = 0 ;
bool V_392 = false ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_393 , & V_382 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_302 , & V_383 ) ;
if ( V_38 < 0 )
goto error;
V_382 &= ( ~ V_394 ) ;
V_383 &= ( ~ V_395 ) ;
if ( V_2 -> V_173 == true ) {
V_382 |= V_394 ;
V_383 |= V_395 ;
V_387 = 204 ;
}
V_383 &= ( ~ ( V_396 ) ) ;
if ( V_2 -> V_174 == false ) {
V_383 |= V_396 ;
}
switch ( V_357 ) {
case V_4 :
V_391 = V_2 -> V_182 ;
V_389 = 3 ;
V_388 = 0xC00000 ;
V_392 = V_2 -> V_180 ;
break;
case V_5 :
case V_7 :
V_389 = 0x0004 ;
V_388 = 0xD2B4EE ;
V_391 = V_2 -> V_183 ;
V_392 = V_2 -> V_181 ;
break;
default:
V_38 = - V_217 ;
}
if ( V_38 < 0 )
goto error;
if ( V_392 ) {
T_1 V_397 = 0 ;
V_384 = ( V_398 |
V_399 ) ;
V_385 = ( V_400 |
V_401 ) ;
V_397 = V_391 ;
if ( V_397 > 75900000UL ) {
V_397 = 75900000UL ;
}
V_386 = ( T_4 ) ( ( ( V_2 -> V_130 )
* 1000 ) / V_397 ) ;
if ( V_386 <= 2 )
V_386 = 0 ;
else
V_386 -= 2 ;
V_390 = 8 ;
} else {
V_384 = V_398 ;
V_385 = V_402 ;
V_390 = 5 ;
}
V_38 = F_21 ( V_2 , V_403 , V_387 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_404 , V_386 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_405 , V_384 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_406 , V_385 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_393 , V_382 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_302 , V_383 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_23 ( V_2 , V_407 , V_388 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_408 , V_390 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_409 , V_389 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_4 V_410 = 0 ;
T_4 V_411 =
V_412 | V_413 |
V_414 | V_415 |
V_416 | V_417 |
V_418 | V_419 ;
F_12 ( 1 , L_3 ) ;
V_410 &= ( ~ ( V_411 ) ) ;
if ( V_2 -> V_175 == true )
V_410 |= V_411 ;
V_410 &= ( ~ ( V_420 ) ) ;
if ( V_2 -> V_176 == true )
V_410 |= V_420 ;
V_410 &= ( ~ ( V_421 ) ) ;
if ( V_2 -> V_177 == true )
V_410 |= V_421 ;
V_410 &= ( ~ ( V_422 ) ) ;
if ( V_2 -> V_178 == true )
V_410 |= V_422 ;
V_410 &= ( ~ ( V_423 ) ) ;
if ( V_2 -> V_179 == true )
V_410 |= V_423 ;
return F_21 ( V_2 , V_424 , V_410 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_425 * V_426 , bool V_427 )
{
int V_38 = - V_217 ;
T_4 V_37 = 0 ;
struct V_425 * V_428 ;
F_12 ( 1 , L_3 ) ;
if ( V_426 == NULL )
goto error;
switch ( V_426 -> V_143 ) {
case V_73 :
V_38 = F_17 ( V_2 , V_326 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_331 ;
V_38 = F_21 ( V_2 , V_326 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_429 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_430 ;
if ( V_2 -> V_431 )
V_37 |= V_432 ;
else
V_37 &= ~ V_432 ;
V_38 = F_21 ( V_2 , V_429 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_433 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_434 ;
V_37 |= ( ~ ( V_426 -> V_147 <<
V_435 )
& V_434 ) ;
V_38 = F_21 ( V_2 , V_433 , V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( F_1 ( V_2 ) )
V_428 = & V_2 -> V_161 ;
else if ( F_2 ( V_2 ) )
V_428 = & V_2 -> V_166 ;
else
V_428 = & V_2 -> V_157 ;
if ( V_428 == NULL ) {
V_38 = - V_217 ;
goto error;
}
if ( V_428 -> V_143 == V_73 )
V_38 = F_21 ( V_2 , V_436 , V_426 -> V_150 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_437 , V_426 -> V_151 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_438 , V_426 -> V_146 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_439 :
V_38 = F_17 ( V_2 , V_326 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_331 ;
V_38 = F_21 ( V_2 , V_326 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_429 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_430 ;
if ( V_2 -> V_431 )
V_37 |= V_432 ;
else
V_37 &= ~ V_432 ;
V_38 = F_21 ( V_2 , V_429 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_437 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_440 , V_426 -> V_144 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_91 :
V_38 = F_17 ( V_2 , V_326 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_331 ;
V_38 = F_21 ( V_2 , V_326 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_429 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_430 ;
V_38 = F_21 ( V_2 , V_429 , V_37 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
V_38 = - V_217 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_425 * V_426 , bool V_427 )
{
T_4 V_37 = 0 ;
int V_38 = 0 ;
struct V_425 * V_441 ;
F_12 ( 1 , L_3 ) ;
switch ( V_426 -> V_143 ) {
case V_73 :
V_38 = F_17 ( V_2 , V_326 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_330 ;
V_38 = F_21 ( V_2 , V_326 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_429 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_442 ;
if ( V_2 -> V_202 )
V_37 |= V_443 ;
else
V_37 &= ~ V_443 ;
V_38 = F_21 ( V_2 , V_429 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_433 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_444 ;
V_37 |= ( ~ ( V_426 -> V_147 <<
V_445 )
& V_444 ) ;
V_38 = F_21 ( V_2 , V_433 , V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( F_2 ( V_2 ) )
V_441 = & V_2 -> V_165 ;
else
V_441 = & V_2 -> V_158 ;
if ( V_441 == NULL )
return - 1 ;
V_38 = F_21 ( V_2 , V_436 , V_441 -> V_150 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_439 :
V_38 = F_17 ( V_2 , V_326 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_330 ;
V_38 = F_21 ( V_2 , V_326 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_429 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_442 ;
if ( V_2 -> V_202 )
V_37 |= V_443 ;
else
V_37 &= ~ V_443 ;
V_38 = F_21 ( V_2 , V_429 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_436 , V_426 -> V_144 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_91 :
V_38 = F_17 ( V_2 , V_326 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_330 ;
V_38 = F_21 ( V_2 , V_326 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_429 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_442 ;
V_38 = F_21 ( V_2 , V_429 , V_37 ) ;
if ( V_38 < 0 )
goto error;
break;
}
V_38 = F_21 ( V_2 , V_446 , V_426 -> V_150 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 * V_447 )
{
T_4 V_448 ;
int V_38 ;
T_4 V_449 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_450 , & V_448 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
* V_447 = 0 ;
if ( V_448 > V_451 )
V_449 = V_448 - V_451 ;
if ( V_449 < 14000 )
* V_447 = ( 14000 - V_449 ) / 4 ;
else
* V_447 = 0 ;
return V_38 ;
}
static int F_67 ( struct V_1 * V_2 ,
T_6 * V_452 )
{
int V_38 = 0 ;
T_4 V_453 = 0 ;
T_1 V_454 = 0 ;
T_1 V_455 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_456 , & V_453 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return - V_217 ;
}
switch ( V_2 -> V_365 . V_457 . V_458 . V_459 ) {
case V_460 :
V_454 = V_461 << 2 ;
break;
case V_462 :
V_454 = V_463 << 2 ;
break;
case V_464 :
V_454 = V_465 << 2 ;
break;
case V_466 :
V_454 = V_467 << 2 ;
break;
default:
case V_468 :
V_454 = V_469 << 2 ;
break;
}
if ( V_453 > 0 ) {
V_455 = F_8 ( V_454 ) -
F_8 ( ( T_1 ) V_453 ) ;
}
* V_452 = V_455 ;
return V_38 ;
}
static int F_68 ( struct V_1 * V_2 ,
T_6 * V_452 )
{
int V_38 ;
T_4 V_470 = 0 ;
T_1 V_471 = 0 ;
T_1 V_472 = 0 ;
T_4 V_473 = 0 ;
T_4 V_474 = 0 ;
T_4 V_475 = 0 ;
T_1 V_476 = 0 ;
T_1 V_477 = 0 ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
T_1 V_478 = 0 ;
T_4 V_479 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_480 , & V_474 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_481 , & V_475 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_482 , & V_473 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_483 , & V_470 ) ;
if ( V_38 < 0 )
goto error;
V_471 = ( T_1 ) V_470 ;
if ( ( V_473 > 11 ) &&
( V_471 < 0x00000FFFUL ) ) {
V_471 += 0x00010000UL ;
}
V_38 = F_17 ( V_2 , V_484 , & V_470 ) ;
if ( V_38 < 0 )
goto error;
V_472 = ( T_1 ) V_470 ;
if ( ( V_473 > 11 ) &&
( V_472 < 0x00000FFFUL ) )
V_472 += 0x00010000UL ;
V_38 = F_17 ( V_2 , V_485 , & V_479 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_474 == 0 ) || ( V_475 == 0 ) )
V_478 = 0 ;
else if ( ( V_471 + V_472 ) == 0 ) {
V_478 = 0 ;
} else {
V_477 = ( V_471 + V_472 ) <<
V_473 ;
if ( ( V_479 &
V_486 )
== V_487 )
V_476 = 17 ;
else
V_476 = 68 ;
V_10 = F_8 ( V_474 *
V_474 ) ;
V_11 = F_8 ( V_475 * V_476 ) ;
V_12 = F_8 ( V_477 ) ;
V_478 = V_10 + V_11 ;
if ( V_478 > V_12 )
V_478 -= V_12 ;
else
V_478 = 0 ;
}
* V_452 = V_478 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_69 ( struct V_1 * V_2 , T_6 * V_452 )
{
F_12 ( 1 , L_3 ) ;
* V_452 = 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
return F_68 ( V_2 , V_452 ) ;
case V_5 :
case V_7 :
return F_67 ( V_2 , V_452 ) ;
default:
break;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , bool V_488 )
{
int V_38 = - V_217 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_170 == V_171 )
goto error;
if ( V_2 -> V_170 == V_489 )
goto error;
if ( V_2 -> V_490 )
return 0 ;
V_38 = F_21 ( V_2 , V_248 , V_249 ) ;
if ( V_38 < 0 )
goto error;
if ( V_488 ) {
V_38 = F_21 ( V_2 , V_247 , V_491 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_38 = F_21 ( V_2 , V_247 , V_492 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_30 ( V_2 , V_493 , 0 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_494 * V_495 )
{
int V_38 = - V_217 ;
F_12 ( 1 , L_3 ) ;
if ( ( V_495 == NULL )
|| ( V_495 -> V_153 > V_496 ) )
goto error;
V_38 = F_21 ( V_2 , V_497 , V_495 -> V_153 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 V_498 ,
T_4 V_268 , T_4 V_269 , T_1 V_270 )
{
T_4 V_271 = 0 ;
T_4 V_287 = ( T_4 ) ( ( V_498 >> 0 ) & 0x00FFFF ) ;
T_4 V_499 = ( T_4 ) ( ( V_498 >> 16 ) & 0x000FFF ) ;
int V_38 ;
unsigned long V_272 ;
F_12 ( 1 , L_3 ) ;
F_32 ( & V_2 -> V_240 ) ;
V_38 = F_21 ( V_2 , V_273 , V_500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_501 , V_499 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_502 , V_287 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_503 , V_268 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_504 , V_269 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_277 , V_278 ) ;
if ( V_38 < 0 )
goto error;
V_272 = V_279 + F_38 ( V_270 ) ;
do {
V_38 = F_17 ( V_2 , V_280 , & V_271 ) ;
if ( V_38 < 0 )
goto error;
} while ( ( V_271 == 0x1 ) && F_39 ( V_272 ) );
if ( V_271 == 0x1 ) {
F_13 ( V_43 L_22 ) ;
V_38 = - V_217 ;
goto V_223;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_223:
F_33 ( & V_2 -> V_240 ) ;
return V_38 ;
}
static int F_73 ( struct V_1 * V_2 , T_4 * V_505 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_506 , V_507 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_508 , 1 ) ;
if ( V_38 < 0 )
goto error;
* V_505 = 0 ;
V_38 = F_17 ( V_2 , V_509 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_505 = * V_505 + 1 ;
V_38 = F_17 ( V_2 , V_510 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_505 = * V_505 + 1 ;
V_38 = F_17 ( V_2 , V_511 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_505 = * V_505 + 1 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_74 ( struct V_1 * V_2 )
{
T_4 V_505 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_73 ( V_2 , & V_505 ) ;
if ( V_38 < 0 )
goto error;
if ( V_505 == 1 ) {
T_4 V_512 = 0 ;
V_38 = F_17 ( V_2 , V_513 , & V_512 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_512 | V_514 ) ==
V_515 ) {
V_512 &= ( ~ ( V_514 ) ) ;
V_512 |=
V_516 ;
} else {
V_512 &= ( ~ ( V_514 ) ) ;
V_512 |=
V_515 ;
}
V_38 = F_21 ( V_2 , V_513 , V_512 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_73 ( V_2 , & V_505 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_505 < 2 )
V_38 = - V_217 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_4 V_517 ,
T_6 V_518 , bool V_427 )
{
bool V_519 = false ;
T_1 V_520 = V_518 ;
T_1 V_521 = 0 ;
bool V_522 = ! V_2 -> V_364 ;
T_1 V_523 ;
bool V_524 ;
int V_38 ;
T_1 V_525 ;
T_1 V_526 = ( T_1 ) ( V_2 -> V_130 / 3 ) ;
T_1 V_527 ;
bool V_528 ;
F_12 ( 1 , L_3 ) ;
if ( V_427 ) {
if ( ( V_2 -> V_3 == V_5 ) ||
( V_2 -> V_3 == V_7 ) ||
( V_2 -> V_3 == V_4 ) )
V_519 = true ;
else
V_519 = false ;
}
if ( V_522 )
V_525 = V_517 +
V_520 + V_521 ;
else
V_525 = V_517 -
V_520 - V_521 ;
if ( V_525 > V_526 / 2 ) {
V_523 = V_526 - V_525 ;
V_524 = true ;
} else {
V_523 = V_525 ;
V_524 = false ;
}
V_527 = V_523 ;
V_528 = V_2 -> V_201 ^ V_522 ^
V_524 ^ V_519 ;
V_2 -> V_529 =
F_7 ( ( V_527 ) , V_526 ) ;
if ( V_528 )
V_2 -> V_529 = ~ V_2 -> V_529 + 1 ;
V_38 = F_23 ( V_2 , V_530 ,
V_2 -> V_529 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_76 ( struct V_1 * V_2 , bool V_427 )
{
T_4 V_531 = 0 ;
T_4 V_532 = 0 ;
T_4 V_533 = 0 ;
T_4 V_534 = 0 ;
T_4 V_535 = 0 ;
T_4 V_536 = 0 ;
T_4 V_537 = 0 ;
T_4 V_538 = 0 ;
T_4 V_539 = 0 ;
T_4 V_540 = 0 ;
T_4 V_541 = 0 ;
T_4 V_542 = 0 ;
T_4 V_543 = 0 ;
T_4 V_544 = 0 ;
T_4 V_37 = 0 ;
T_4 V_545 = 0 ;
T_4 V_546 = 0 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_538 = 1023 ;
V_543 = 2047 ;
V_534 = 500 ;
V_539 = 1023 ;
if ( ! F_2 ( V_2 ) ) {
F_13 ( V_43 L_33 , V_62 , V_2 -> V_3 ) ;
return - V_217 ;
}
V_535 = 8 ;
V_536 = ( T_4 ) - 9 ;
V_546 = 0 ;
V_537 = 8 ;
V_540 = ( T_4 ) - 9 ;
V_541 = ( T_4 ) - 1030 ;
V_544 = 0x2380 ;
V_542 = 0x2380 ;
V_532 = 0x0511 ;
V_531 = 0x0511 ;
V_533 = 5119 ;
V_545 = V_2 -> V_166 . V_162 ;
V_38 = F_21 ( V_2 , V_547 , V_545 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_548 , V_546 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_549 , V_531 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_446 , V_532 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_550 , V_533 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_551 , V_543 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_436 , V_544 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_552 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_553 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_440 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_554 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_555 , V_539 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_556 , V_538 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_557 , V_541 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_558 , V_542 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_559 , V_534 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_560 , 1023 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_561 , ( T_4 ) - 1023 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_562 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_563 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_564 , V_535 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_565 , V_537 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_566 , V_536 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_567 , V_540 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_568 , 0x7fff ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_569 , 0x0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_570 , 0x0117 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_571 , 0x0657 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_572 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_573 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_574 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_575 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_576 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_577 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_578 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_579 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_580 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_581 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_582 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 = 0x0657 ;
V_37 &= ~ V_583 ;
V_37 |= ( V_584 << V_585 ) ;
V_37 &= ~ V_586 ;
V_37 |= ( V_587 << V_588 ) ;
V_38 = F_21 ( V_2 , V_582 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_77 ( struct V_1 * V_2 , T_4 * V_589 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( V_589 == NULL )
V_38 = F_21 ( V_2 , V_590 , 0 ) ;
else
V_38 = F_17 ( V_2 , V_590 , V_589 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_78 ( struct V_1 * V_2 ,
T_4 V_229 , T_4 V_591 ,
T_4 V_592 , T_4 V_593 , T_4 V_594 ,
T_4 V_595 , T_4 V_596 )
{
T_4 V_310 = 0 ;
T_4 V_597 = 0 ;
T_4 V_598 = 0 ;
T_4 V_599 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_350 , & V_599 ) ;
if ( V_599 != 1 ) {
V_38 = - V_217 ;
}
if ( V_38 < 0 )
goto error;
V_598 = 0 ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_600 , & V_310 ) ;
V_598 ++ ;
} while ( ( V_310 != 0 ) && ( V_598 < V_238 ) );
if ( V_598 >= V_238 && ( V_38 < 0 ) )
goto error;
switch ( V_229 ) {
case V_601 :
case V_602 :
case V_603 :
V_38 = F_21 ( V_2 , V_604 , V_591 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
break;
}
switch ( V_229 ) {
case V_601 :
case V_602 :
case V_603 :
V_38 = F_21 ( V_2 , V_605 , V_593 ) ;
case V_606 :
case V_607 :
V_38 = F_21 ( V_2 , V_608 , V_592 ) ;
case V_609 :
case V_610 :
V_38 = F_21 ( V_2 , V_600 , V_229 ) ;
break;
default:
V_38 = - V_217 ;
}
if ( V_38 < 0 )
goto error;
V_598 = 0 ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_600 , & V_310 ) ;
V_598 ++ ;
} while ( ( V_310 != 0 ) && ( V_598 < V_238 ) );
if ( V_598 >= V_238 && ( V_38 < 0 ) )
goto error;
V_38 = F_17 ( V_2 , V_604 , & V_597 ) ;
if ( V_597 == 0xFFFF ) {
V_38 = - V_217 ;
}
if ( V_38 < 0 )
goto error;
switch ( V_229 ) {
case V_607 :
case V_609 :
V_38 = F_17 ( V_2 , V_608 , & ( V_592 ) ) ;
case V_606 :
case V_611 :
case V_601 :
case V_602 :
case V_603 :
case V_610 :
break;
default:
V_38 = - V_217 ;
break;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_79 ( struct V_1 * V_2 )
{
enum V_332 V_343 = V_71 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_46 ( V_2 , & V_343 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_80 ( struct V_1 * V_2 , bool * V_612 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( * V_612 == true )
V_38 = F_21 ( V_2 , V_613 , 0 ) ;
else
V_38 = F_21 ( V_2 , V_613 , 1 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_81 ( struct V_1 * V_2 , bool * V_612 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( * V_612 == true ) {
V_38 = F_21 ( V_2 , V_614 ,
V_615 ) ;
} else {
V_38 = F_21 ( V_2 , V_614 , 0 ) ;
}
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_616 * V_617 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_618 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_617 -> V_619 ) {
case V_620 :
V_37 &= ~ V_621 ;
V_37 |= ( ( V_617 -> V_622 <<
V_623 )
& ( V_621 ) ) ;
break;
case V_624 :
V_37 &= ~ V_625 ;
V_37 |= ( ( V_617 -> V_622 <<
V_626 )
& ( V_625 ) ) ;
break;
default:
return - V_217 ;
}
V_38 = F_21 ( V_2 , V_618 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_83 ( struct V_1 * V_2 ,
enum V_627 * V_147 )
{
int V_38 = - V_217 ;
F_12 ( 1 , L_3 ) ;
switch ( * V_147 ) {
case V_628 :
case V_197 :
case V_629 :
break;
default:
goto error;
}
V_38 = F_21 ( V_2 , V_630 ,
( T_4 ) * V_147 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_38 ;
bool V_631 = false ;
bool V_632 = true ;
struct V_616 V_633 = { 0 , V_620 } ;
struct V_616 V_634 = { 0 , V_624 } ;
F_12 ( 1 , L_3 ) ;
V_38 = F_80 ( V_2 , & V_631 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_81 ( V_2 , & V_632 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_82 ( V_2 , & V_633 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_82 ( V_2 , & V_634 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_550 , V_2 -> V_161 . V_163 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_50 ( struct V_1 * V_2 ,
enum V_356 V_357 )
{
T_4 V_344 = 0 ;
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
F_79 ( V_2 ) ;
F_85 ( V_2 ) ;
V_38 = F_43 ( V_2 , V_347 | V_349 , 0 , NULL , 1 , & V_344 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_347 | V_635 , 0 , NULL , 1 , & V_344 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_350 , V_351 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_352 , V_353 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_354 , V_355 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_636 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_637 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_638 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_639 , V_640 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_641 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_642 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_643 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_644 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_645 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_646 , 0x4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_647 , 0x4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_648 , 1600 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_649 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_650 , 448 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_651 , 495 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_37 ( V_2 , V_652 , V_653 , V_654 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_655 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_656 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_657 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_354 , V_658 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_74 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_71 ( V_2 , & V_2 -> V_164 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_659 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_64 ( V_2 , & V_2 -> V_160 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_65 ( V_2 , & V_2 -> V_161 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_660 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_661 ;
V_38 = F_21 ( V_2 , V_660 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_139 ) {
V_38 = F_21 ( V_2 , V_547 , V_2 -> V_161 . V_162 ) ;
if ( V_38 < 0 )
goto error;
}
#ifdef F_86
V_38 = F_21 ( V_2 , V_662 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_663 , 2 ) ;
if ( V_38 < 0 )
goto error;
#endif
V_38 = F_21 ( V_2 , V_664 , 1 ) ;
if ( V_38 < 0 )
goto error;
#ifdef F_86
V_38 = F_21 ( V_2 , V_665 , 0x400 ) ;
if ( V_38 < 0 )
goto error;
#else
V_38 = F_21 ( V_2 , V_665 , 0x1000 ) ;
if ( V_38 < 0 )
goto error;
#endif
V_38 = F_21 ( V_2 , V_666 , 0x0001 ) ;
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
T_4 V_593 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_593 = V_667 ;
V_38 = F_78 ( V_2 , V_601 , 0 , V_668 , V_593 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_60 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_669 , V_670 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_54 ( struct V_1 * V_2 , T_4 V_671 ,
T_6 V_518 )
{
T_4 V_344 = 0 ;
T_4 V_479 = 0 ;
T_4 V_672 = 0 ;
T_1 V_673 = 0 ;
T_1 V_674 = 0 ;
T_4 V_593 ;
int V_38 ;
F_12 ( 1 , L_34 , V_671 , V_518 ) ;
V_38 = F_43 ( V_2 , V_347 | V_348 , 0 , NULL , 1 , & V_344 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_659 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_350 , V_351 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_352 , V_353 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_675 , V_676 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_365 . V_457 . V_677 . V_678 ) {
case V_679 :
default:
V_672 |= V_680 ;
case V_681 :
V_479 |= V_682 ;
break;
case V_683 :
V_479 |= V_487 ;
break;
}
switch ( V_2 -> V_365 . V_457 . V_677 . V_684 ) {
default:
case V_685 :
V_672 |= V_686 ;
case V_687 :
V_479 |= V_688 ;
break;
case V_689 :
V_479 |= V_690 ;
break;
case V_691 :
V_479 |= V_692 ;
break;
case V_693 :
V_479 |= V_694 ;
break;
}
switch ( V_2 -> V_365 . V_457 . V_677 . V_695 ) {
case V_696 :
case V_697 :
default:
V_672 |= V_698 ;
case V_699 :
V_479 |= V_700 ;
break;
case V_701 :
V_479 |= V_702 ;
break;
case V_703 :
V_479 |= V_704 ;
break;
}
switch ( V_2 -> V_365 . V_457 . V_677 . V_705 ) {
case V_706 :
default:
V_672 |= V_707 ;
case V_464 :
V_479 |= V_708 ;
break;
case V_709 :
V_479 |= V_710 ;
break;
case V_460 :
V_479 |= V_711 ;
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
V_479 |= V_712 ;
V_38 = F_21 ( V_2 , V_713 , V_714 ) ;
if ( V_38 < 0 )
goto error;
#endif
switch ( V_2 -> V_365 . V_457 . V_677 . V_715 ) {
case V_716 :
default:
V_672 |= V_717 ;
case V_718 :
V_479 |= V_719 ;
break;
case V_720 :
V_479 |= V_721 ;
break;
case V_722 :
V_479 |= V_723 ;
break;
case V_724 :
V_479 |= V_725 ;
break;
case V_726 :
V_479 |= V_727 ;
break;
}
switch ( V_2 -> V_365 . V_457 . V_677 . V_674 ) {
case V_728 :
case V_729 :
V_674 = V_730 ;
V_38 = F_21 ( V_2 , V_731 , 3052 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_732 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_733 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_734 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_735 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_736 :
V_674 = V_737 ;
V_38 = F_21 ( V_2 , V_731 , 3491 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_732 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_733 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_734 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_735 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_738 :
V_674 = V_739 ;
V_38 = F_21 ( V_2 , V_731 , 4073 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_732 , 19 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_733 , 19 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_734 , 14 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_735 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
V_38 = - V_217 ;
goto error;
}
if ( V_673 == 0 ) {
V_673 = F_7 ( ( T_1 )
( ( V_2 -> V_130 *
1000 ) / 3 ) , V_674 ) ;
if ( ( V_673 & 0x7fL ) >= 0x40 )
V_673 += 0x80L ;
V_673 = V_673 >> 7 ;
V_673 = V_673 - ( 1 << 23 ) ;
}
V_673 &=
( ( ( ( T_1 ) V_740 ) <<
V_741 ) | V_742 ) ;
V_38 = F_23 ( V_2 , V_743 , V_673 ) ;
if ( V_38 < 0 )
goto error;
#if 0
status = DVBTSetFrequencyShift(demod, channel, tunerOffset);
if (status < 0)
goto error;
#endif
V_38 = F_75 ( V_2 , V_671 , V_518 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_744 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_350 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_347 | V_745 , 0 , NULL , 1 , & V_344 ) ;
if ( V_38 < 0 )
goto error;
V_593 = ( V_680 |
V_686 |
V_707 |
V_698 |
V_717 ) ;
V_38 = F_78 ( V_2 , V_602 ,
0 , V_479 , V_593 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_139 )
V_38 = F_83 ( V_2 , & V_2 -> V_196 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 * V_368 )
{
int V_38 ;
const T_4 V_746 = ( V_747 |
V_748 ) ;
const T_4 V_749 = ( V_748 ) ;
const T_4 V_750 = V_751 ;
T_4 V_752 = 0 ;
T_4 V_753 = 0 ;
F_12 ( 1 , L_3 ) ;
* V_368 = V_369 ;
V_38 = F_17 ( V_2 , V_350 , & V_753 ) ;
if ( V_38 < 0 )
goto V_272;
if ( V_753 == V_351 )
goto V_272;
V_38 = F_17 ( V_2 , V_754 , & V_752 ) ;
if ( V_38 < 0 )
goto V_272;
if ( ( V_752 & V_746 ) == V_746 )
* V_368 = V_755 ;
else if ( ( V_752 & V_749 ) == V_749 )
* V_368 = V_756 ;
else if ( ( V_752 & V_750 ) == V_750 )
* V_368 = V_757 ;
else if ( V_752 & V_758 )
* V_368 = V_759 ;
V_272:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_87 ( struct V_1 * V_2 )
{
enum V_332 V_343 = V_335 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_46 ( V_2 , & V_343 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_48 ( struct V_1 * V_2 )
{
T_4 V_37 = 0 ;
T_4 V_344 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_345 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == V_346 ) {
V_38 = F_21 ( V_2 , V_760 , V_761 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_762 | V_348 , 0 , NULL , 1 , & V_344 ) ;
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
enum V_763 V_705 ,
T_1 V_764 )
{
T_1 V_765 = 0 ;
T_1 V_766 = 0 ;
T_4 V_767 = 0 ;
T_4 V_768 = 0 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_767 = 1 ;
switch ( V_705 ) {
case V_769 :
V_765 = 4 * V_764 ;
break;
case V_770 :
V_765 = 5 * V_764 ;
break;
case V_771 :
V_765 = 6 * V_764 ;
break;
case V_772 :
V_765 = 7 * V_764 ;
break;
case V_773 :
V_765 = 8 * V_764 ;
break;
default:
V_38 = - V_217 ;
}
if ( V_38 < 0 )
goto error;
V_765 /= 1000 ;
V_765 *= 500 ;
V_766 = ( V_765 / 1632UL ) + 1 ;
V_767 = 1 + ( T_4 ) ( V_766 >> 16 ) ;
if ( V_767 == 0 ) {
V_38 = - V_217 ;
if ( V_38 < 0 )
goto error;
}
V_768 =
( ( T_4 ) V_766 +
( V_767 >> 1 ) ) / V_767 ;
V_38 = F_21 ( V_2 , V_665 , V_768 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_666 , V_767 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , V_768 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_775 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , V_461 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 32 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , 95 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , 120 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , 230 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , 105 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_819 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_820 , ( T_4 ) 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_821 , ( T_4 ) 220 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_822 , ( T_4 ) 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_823 , ( T_4 ) 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_824 , ( T_4 ) - 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_825 , ( T_4 ) - 65 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_826 , ( T_4 ) - 127 ) ;
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
V_38 = F_21 ( V_2 , V_775 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , V_463 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 90 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , 170 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_819 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_820 , ( T_4 ) 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_821 , ( T_4 ) 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_822 , ( T_4 ) - 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_823 , ( T_4 ) - 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_824 , ( T_4 ) - 26 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_825 , ( T_4 ) - 56 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_826 , ( T_4 ) - 86 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_775 , 13336 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 12618 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 11988 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 13809 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 13809 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 15609 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , V_465 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 30 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 30 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 48 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , 110 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , 200 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , 95 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_819 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_820 , ( T_4 ) 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_821 , ( T_4 ) 141 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_822 , ( T_4 ) 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_823 , ( T_4 ) 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_824 , ( T_4 ) - 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_825 , ( T_4 ) - 45 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_826 , ( T_4 ) - 80 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_775 , 6564 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 6598 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 6394 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 6409 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 6656 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 7238 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , V_467 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 120 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 64 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_819 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_820 , ( T_4 ) 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_821 , ( T_4 ) 65 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_822 , ( T_4 ) 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_823 , ( T_4 ) 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_824 , ( T_4 ) - 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_825 , ( T_4 ) - 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_826 , ( T_4 ) - 23 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_775 , 11502 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 12084 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 12543 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 12931 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 13629 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 15385 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , V_469 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 125 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 48 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , 150 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , 110 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_819 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_820 , ( T_4 ) 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_821 , ( T_4 ) 74 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_822 , ( T_4 ) 18 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_823 , ( T_4 ) 13 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_824 , ( T_4 ) 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_825 , ( T_4 ) 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_826 , ( T_4 ) - 8 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_344 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_760 , V_761 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_762 | V_349 , 0 , NULL , 1 , & V_344 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_95 ( struct V_1 * V_2 )
{
T_1 V_827 = 0 ;
T_1 V_828 = 0 ;
T_1 V_829 = 0 ;
T_4 V_830 = 0 ;
T_1 V_831 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_827 = ( V_2 -> V_130 * 1000 ) / 3 ;
V_830 = 0 ;
if ( V_2 -> V_365 . V_457 . V_458 . V_832 <= 1188750 )
V_830 = 3 ;
else if ( V_2 -> V_365 . V_457 . V_458 . V_832 <= 2377500 )
V_830 = 2 ;
else if ( V_2 -> V_365 . V_457 . V_458 . V_832 <= 4755000 )
V_830 = 1 ;
V_38 = F_21 ( V_2 , V_833 , V_830 ) ;
if ( V_38 < 0 )
goto error;
V_828 = V_2 -> V_365 . V_457 . V_458 . V_832 * ( 1 << V_830 ) ;
if ( V_828 == 0 ) {
V_38 = - V_217 ;
goto error;
}
V_829 = ( V_827 / V_828 ) * ( 1 << 21 ) +
( F_7 ( ( V_827 % V_828 ) , V_828 ) >> 7 ) -
( 1 << 23 ) ;
V_38 = F_23 ( V_2 , V_743 , V_829 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_834 = V_829 ;
V_828 = V_2 -> V_365 . V_457 . V_458 . V_832 ;
if ( V_827 == 0 ) {
V_38 = - V_217 ;
goto error;
}
V_831 = ( V_828 / V_827 ) * ( 1 << 12 ) +
( F_7 ( ( V_828 % V_827 ) , V_827 ) >>
16 ) ;
if ( V_831 > 511 )
V_831 = 511 ;
V_38 = F_21 ( V_2 , V_835 , ( T_4 ) V_831 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_58 ( struct V_1 * V_2 , T_1 * V_368 )
{
int V_38 ;
T_4 V_836 [ 2 ] = { 0 , 0 } ;
F_12 ( 1 , L_3 ) ;
* V_368 = V_369 ;
V_38 = F_43 ( V_2 ,
V_762 |
V_837 , 0 , NULL , 2 ,
V_836 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_35 , V_62 , V_38 ) ;
if ( V_836 [ 1 ] < V_838 ) {
} else if ( V_836 [ 1 ] < V_839 ) {
* V_368 = V_757 ;
} else if ( V_836 [ 1 ] < V_840 ) {
* V_368 = V_755 ;
} else {
* V_368 = V_759 ;
}
return V_38 ;
}
static int F_53 ( struct V_1 * V_2 , T_4 V_671 ,
T_6 V_518 )
{
int V_38 ;
T_4 V_841 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 V_344 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_842 , V_843 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_844 , V_845 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_94 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_95 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_365 . V_457 . V_458 . V_459 ) {
case V_468 :
V_2 -> V_190 = V_773 ;
break;
case V_706 :
case V_464 :
V_2 -> V_190 = V_771 ;
break;
case V_460 :
V_2 -> V_190 = V_769 ;
break;
case V_462 :
V_2 -> V_190 = V_770 ;
break;
case V_466 :
V_2 -> V_190 = V_772 ;
break;
default:
V_38 = - V_217 ;
break;
}
if ( V_38 < 0 )
goto error;
V_841 [ 0 ] = V_2 -> V_190 ;
V_841 [ 1 ] = V_193 ;
if ( V_2 -> V_3 == V_7 )
V_841 [ 2 ] = V_846 ;
else
V_841 [ 2 ] = V_847 ;
V_841 [ 3 ] |= ( V_848 ) ;
V_38 = F_43 ( V_2 , V_762 | V_849 , 4 , V_841 , 1 , & V_344 ) ;
if ( V_38 < 0 ) {
if ( V_2 -> V_3 == V_7 )
V_841 [ 0 ] = V_846 ;
else
V_841 [ 0 ] = V_847 ;
V_38 = F_43 ( V_2 , V_762 | V_635 , 1 , V_841 , 1 , & V_344 ) ;
if ( V_38 < 0 )
goto error;
V_841 [ 0 ] = V_2 -> V_190 ;
V_841 [ 1 ] = V_193 ;
V_38 = F_43 ( V_2 , V_762 | V_849 , 2 , V_841 , 1 , & V_344 ) ;
}
if ( V_38 < 0 )
goto error;
#if 0
status = SetFrequency(channel, tunerFreqOffset));
if (status < 0)
goto error;
#endif
V_38 = F_75 ( V_2 , V_671 , V_518 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_88 ( V_2 , V_2 -> V_190 , V_2 -> V_365 . V_457 . V_458 . V_832 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_649 , V_850 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_851 , V_852 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_853 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_854 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_855 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_856 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_857 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_858 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_859 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_860 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_861 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_862 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_863 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_864 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_865 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_866 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_867 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_868 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_869 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_870 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_871 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_872 , V_873 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_659 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_365 . V_457 . V_458 . V_459 ) {
case V_460 :
V_38 = F_89 ( V_2 ) ;
break;
case V_462 :
V_38 = F_90 ( V_2 ) ;
break;
case V_706 :
case V_464 :
V_38 = F_91 ( V_2 ) ;
break;
case V_466 :
V_38 = F_92 ( V_2 ) ;
break;
case V_468 :
V_38 = F_93 ( V_2 ) ;
break;
default:
V_38 = - V_217 ;
break;
}
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_62 ( V_2 , V_2 -> V_3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_60 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_669 , V_670 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_760 , V_874 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_354 , V_658 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_762 | V_745 , 0 , NULL , 1 , & V_344 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_356 V_357 )
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
V_38 = F_21 ( V_2 , V_354 , V_355 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_639 , V_640 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_357 ) {
case V_5 :
V_38 = F_37 ( V_2 , V_875 , V_653 , V_654 ) ;
break;
case V_7 :
V_38 = F_72 ( V_2 , V_876 , V_877 , V_878 , V_654 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_72 ( V_2 , V_879 , V_877 , V_878 , V_654 ) ;
break;
default:
V_38 = - V_217 ;
}
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_646 , ( 1 << V_880 ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_881 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_882 , ( ( 1 << V_883 ) | ( 1 << V_884 ) ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_645 , 21 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_637 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_650 , 448 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_638 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_656 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_885 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_886 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_887 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_636 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_888 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_651 , 1000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_613 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_643 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_644 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_655 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_889 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_508 , 0x01 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_74 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_890 , 2000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_659 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_76 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_71 ( V_2 , & ( V_2 -> V_168 ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_64 ( V_2 , & ( V_2 -> V_165 ) , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_65 ( V_2 , & ( V_2 -> V_166 ) , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_891 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_206 , V_207 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_208 , V_209 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_224 ) {
if ( V_2 -> V_892 & 0x0001 ) {
V_38 = F_21 ( V_2 , V_893 , V_2 -> V_199 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_894 , & V_891 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_895 & 0x0001 ) == 0 )
V_891 &= 0x7FFF ;
else
V_891 |= 0x8000 ;
V_38 = F_21 ( V_2 , V_894 , V_891 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_2 -> V_892 & 0x0002 ) {
V_38 = F_21 ( V_2 , V_893 , V_2 -> V_199 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_894 , & V_891 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_895 & 0x0002 ) == 0 )
V_891 &= 0xBFFF ;
else
V_891 |= 0x4000 ;
V_38 = F_21 ( V_2 , V_894 , V_891 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_2 -> V_892 & 0x0004 ) {
V_38 = F_21 ( V_2 , V_893 , V_2 -> V_199 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_894 , & V_891 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_895 & 0x0004 ) == 0 )
V_891 &= 0xFFFB ;
else
V_891 |= 0x0004 ;
V_38 = F_21 ( V_2 , V_894 , V_891 ) ;
if ( V_38 < 0 )
goto error;
}
}
V_38 = F_21 ( V_2 , V_208 , 0x0000 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
bool V_896 ;
F_12 ( 1 , L_3 ) ;
if ( ! V_2 -> V_897 )
return 0 ;
V_896 = V_2 -> V_895 & V_2 -> V_897 ;
if ( V_2 -> V_898 ^ V_896 ) {
if ( V_2 -> V_898 )
V_2 -> V_895 &= ~ V_2 -> V_897 ;
else
V_2 -> V_895 |= V_2 -> V_897 ;
V_38 = F_99 ( V_2 ) ;
}
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
bool V_896 ;
F_12 ( 1 , L_3 ) ;
if ( ! V_2 -> V_897 )
return 0 ;
V_896 = V_2 -> V_895 & V_2 -> V_897 ;
if ( ! ( V_2 -> V_898 ^ V_896 ) ) {
if ( V_2 -> V_898 )
V_2 -> V_895 |= V_2 -> V_897 ;
else
V_2 -> V_895 &= ~ V_2 -> V_897 ;
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
if ( V_2 -> V_129 ) {
V_38 = F_70 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_41 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_65 , V_338 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_135 |= V_236 ;
V_38 = F_31 ( V_2 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_101 ( struct V_1 * V_2 , const char * V_899 )
{
const struct V_900 * V_901 = NULL ;
int V_319 = 0 ;
F_12 ( 1 , L_3 ) ;
V_319 = F_102 ( & V_901 , V_899 , V_2 -> V_51 -> V_902 . V_903 ) ;
if ( V_319 < 0 ) {
F_13 ( V_43
L_36 , V_899 ) ;
F_13 ( V_228
L_37 , V_899 ) ;
return V_319 ;
}
V_319 = F_40 ( V_2 , V_901 -> V_37 , V_901 -> V_904 ) ;
F_103 ( V_901 ) ;
return V_319 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
enum V_332 V_343 = V_335 ;
T_4 V_905 ;
F_12 ( 1 , L_3 ) ;
if ( ( V_2 -> V_170 == V_171 ) ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_28 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_906 , V_907 | V_908 | V_909 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
F_26 ( 1 ) ;
V_2 -> V_141 = true ;
V_38 = F_29 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_246 =
( T_4 ) ( ( V_2 -> V_127 / 1000 ) *
V_910 ) / 1000 ;
if ( V_2 -> V_246 >
V_911 ) {
V_2 -> V_246 =
V_911 ;
}
V_2 -> V_246 +=
V_2 -> V_246 <<
V_912 ;
V_38 = F_34 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
#if V_913
if ( ! ( V_2 -> V_9 )
&& ! ( V_2 -> V_138 ) )
#endif
{
V_38 = F_21 ( V_2 , V_206 , V_207 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_36 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_914 , V_915 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_916 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_296 , V_290 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_917 , V_918 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_37 ( V_2 , 0 , 6 , 100 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_919 )
F_101 ( V_2 , L_38 ) ;
else
F_101 ( V_2 , V_2 -> V_919 ) ;
V_38 = F_21 ( V_2 , V_296 , V_293 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_345 , V_346 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_28 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
F_26 ( 30 ) ;
V_343 = V_335 ;
V_38 = F_46 ( V_2 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
V_905 =
( ( ( V_920 / 100 ) % 10 ) << 12 ) +
( ( ( V_920 / 10 ) % 10 ) << 8 ) +
( ( V_920 % 10 ) << 4 ) +
( V_921 % 10 ) ;
V_38 = F_21 ( V_2 , V_922 , V_905 ) ;
if ( V_38 < 0 )
goto error;
V_905 =
( ( ( V_923 / 1000 ) % 10 ) << 12 ) +
( ( ( V_923 / 100 ) % 10 ) << 8 ) +
( ( ( V_923 / 10 ) % 10 ) << 4 ) +
( V_923 % 10 ) ;
V_38 = F_21 ( V_2 , V_924 , V_905 ) ;
if ( V_38 < 0 )
goto error;
F_13 ( V_228 L_39 ,
V_920 , V_921 ,
V_923 ) ;
V_38 = F_21 ( V_2 , V_925 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_669 , V_926 ) ;
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
V_38 = F_35 ( V_2 , V_2 -> V_172 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_99 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_170 = V_362 ;
if ( V_2 -> V_137 ) {
V_38 = F_100 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_170 = V_489 ;
} else
V_2 -> V_170 = V_362 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static void F_105 ( struct V_927 * V_928 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
F_12 ( 1 , L_3 ) ;
F_106 ( V_2 ) ;
}
static int F_107 ( struct V_927 * V_928 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
F_12 ( 1 , L_3 ) ;
if ( F_108 ( & V_2 -> V_930 ) == 0 )
return - V_931 ;
F_49 ( V_2 , V_5 ) ;
return 0 ;
}
static int F_109 ( struct V_927 * V_928 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
F_12 ( 1 , L_3 ) ;
F_56 ( V_2 ) ;
F_33 ( & V_2 -> V_930 ) ;
return 0 ;
}
static int F_110 ( struct V_927 * V_928 , int V_288 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
F_12 ( 1 , L_40 , V_288 ? L_41 : L_42 ) ;
return F_70 ( V_2 , V_288 ? true : false ) ;
}
static int F_111 ( struct V_927 * V_928 ,
struct V_932 * V_314 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
T_1 IF ;
F_12 ( 1 , L_3 ) ;
if ( ! V_928 -> V_933 . V_934 . V_935 ) {
F_13 ( V_43
L_43 ) ;
return - V_217 ;
}
if ( V_928 -> V_933 . V_936 )
V_928 -> V_933 . V_936 ( V_928 , 1 ) ;
if ( V_928 -> V_933 . V_934 . V_937 )
V_928 -> V_933 . V_934 . V_937 ( V_928 , V_314 ) ;
if ( V_928 -> V_933 . V_936 )
V_928 -> V_933 . V_936 ( V_928 , 0 ) ;
V_2 -> V_365 = * V_314 ;
V_928 -> V_933 . V_934 . V_935 ( V_928 , & IF ) ;
F_52 ( V_2 , 0 , IF ) ;
return 0 ;
}
static int F_112 ( struct V_927 * V_928 ,
struct V_932 * V_314 )
{
F_12 ( 1 , L_3 ) ;
return 0 ;
}
static int F_113 ( struct V_927 * V_928 , T_7 * V_38 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
T_1 V_938 ;
F_12 ( 1 , L_3 ) ;
* V_38 = 0 ;
F_57 ( V_2 , & V_938 , 0 ) ;
if ( V_938 == V_755 )
* V_38 |= 0x1f ;
if ( V_938 == V_756 )
* V_38 |= 0x0f ;
if ( V_938 == V_757 )
* V_38 |= 0x07 ;
return 0 ;
}
static int F_114 ( struct V_927 * V_928 , T_1 * V_939 )
{
F_12 ( 1 , L_3 ) ;
* V_939 = 0 ;
return 0 ;
}
static int F_115 ( struct V_927 * V_928 ,
T_4 * V_940 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
T_1 V_28 = 0 ;
F_12 ( 1 , L_3 ) ;
F_66 ( V_2 , & V_28 ) ;
* V_940 = V_28 & 0xffff ;
return 0 ;
}
static int F_116 ( struct V_927 * V_928 , T_4 * V_941 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
T_6 V_942 ;
F_12 ( 1 , L_3 ) ;
F_69 ( V_2 , & V_942 ) ;
* V_941 = V_942 & 0xffff ;
return 0 ;
}
static int F_117 ( struct V_927 * V_928 , T_1 * V_943 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
T_4 V_319 ;
F_12 ( 1 , L_3 ) ;
F_77 ( V_2 , & V_319 ) ;
* V_943 = ( T_1 ) V_319 ;
return 0 ;
}
static int F_118 ( struct V_927 * V_928 , struct V_944
* V_945 )
{
F_12 ( 1 , L_3 ) ;
V_945 -> V_946 = 3000 ;
V_945 -> V_947 = 0 ;
V_945 -> V_948 = 0 ;
return 0 ;
}
static void F_119 ( struct V_927 * V_928 )
{
}
static int F_120 ( struct V_927 * V_928 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
F_12 ( 1 , L_3 ) ;
if ( F_108 ( & V_2 -> V_930 ) == 0 )
return - V_931 ;
F_49 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_121 ( struct V_927 * V_928 )
{
struct V_1 * V_2 = V_928 -> V_929 ;
F_12 ( 1 , L_3 ) ;
F_33 ( & V_2 -> V_930 ) ;
return 0 ;
}
static int F_122 ( struct V_927 * V_928 ,
struct V_932 * V_314 )
{
F_12 ( 1 , L_3 ) ;
return 0 ;
}
struct V_927 * F_123 ( const struct V_949 * V_950 ,
struct V_25 * V_51 ,
struct V_927 * * V_951 )
{
struct V_1 * V_2 = NULL ;
T_3 V_27 = V_950 -> V_27 ;
F_12 ( 1 , L_3 ) ;
V_2 = F_124 ( sizeof( struct V_1 ) , V_952 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_51 = V_51 ;
V_2 -> V_47 = V_27 ;
V_2 -> V_50 = V_950 -> V_50 ;
V_2 -> V_919 = V_950 -> V_919 ;
V_2 -> V_490 = V_950 -> V_490 ;
V_2 -> V_897 = V_950 -> V_897 ;
V_2 -> V_898 = V_950 -> V_898 ;
V_2 -> V_892 = V_950 -> V_897 ;
if ( ! V_2 -> V_898 && V_2 -> V_897 )
V_2 -> V_895 |= V_2 -> V_897 ;
else
V_2 -> V_895 &= ~ V_2 -> V_897 ;
F_125 ( & V_2 -> V_240 ) ;
F_125 ( & V_2 -> V_930 ) ;
memcpy ( & V_2 -> V_953 . V_933 , & V_954 ,
sizeof( struct V_955 ) ) ;
memcpy ( & V_2 -> V_956 . V_933 , & V_957 ,
sizeof( struct V_955 ) ) ;
V_2 -> V_953 . V_929 = V_2 ;
V_2 -> V_956 . V_929 = V_2 ;
F_27 ( V_2 ) ;
if ( F_104 ( V_2 ) < 0 )
goto error;
* V_951 = & V_2 -> V_956 ;
return & V_2 -> V_953 ;
error:
F_13 ( V_43 L_44 ) ;
F_106 ( V_2 ) ;
return NULL ;
}
