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
T_1 V_109 = 0 ;
T_1 V_110 = V_111 ;
T_1 V_112 = V_113 ;
T_1 V_114 = 50000000 ;
T_1 V_115 = V_116 * 8 ;
T_1 V_117 = 0 ;
T_1 V_118 = 1 ;
T_1 V_119 = 0 ;
F_12 ( 1 , L_3 ) ;
V_2 -> V_120 = false ;
V_2 -> V_121 = false ;
V_2 -> V_122 = false ;
V_2 -> V_123 = false ;
V_2 -> V_124 = false ;
V_2 -> V_125 = false ;
if ( ! V_2 -> V_59 )
V_2 -> V_59 = 124 ;
V_2 -> V_126 = 0 ;
V_2 -> V_127 = false ;
V_2 -> V_128 = false ;
V_2 -> V_129 = 151875 ;
V_2 -> V_130 = ( ( V_2 -> V_129 / 1000 ) *
V_131 ) / 1000 ;
if ( V_2 -> V_130 > V_132 )
V_2 -> V_130 = V_132 ;
V_2 -> V_133 = ( V_2 -> V_47 << 1 ) ;
V_2 -> V_134 = V_135 ;
V_2 -> V_136 = ( V_119 != 0 ) ;
V_2 -> V_8 = false ;
V_2 -> V_9 = false ;
V_2 -> V_137 = false ;
V_2 -> V_138 = false ;
V_2 -> V_139 = false ;
V_2 -> V_140 = false ;
V_2 -> V_141 . V_142 = ( V_72 ) ;
V_2 -> V_141 . V_143 = ( V_74 ) ;
V_2 -> V_141 . V_144 = ( V_75 ) ;
V_2 -> V_141 . V_145 = ( V_76 ) ;
V_2 -> V_141 . V_146 = ( V_77 ) ;
V_2 -> V_147 = 140 ;
V_2 -> V_148 . V_142 = ( V_78 ) ;
V_2 -> V_148 . V_143 = ( V_79 ) ;
V_2 -> V_148 . V_144 = ( V_80 ) ;
V_2 -> V_148 . V_145 = ( V_81 ) ;
V_2 -> V_148 . V_146 = ( V_82 ) ;
V_2 -> V_148 . V_149 = ( V_83 ) ;
V_2 -> V_148 . V_150 = ( V_84 ) ;
V_2 -> V_151 . V_152 = 0x07 ;
V_2 -> V_151 . V_153 = true ;
V_2 -> V_154 = V_99 ;
V_2 -> V_155 = V_101 ;
if ( V_100 <= 500 && V_98 < V_100 ) {
V_2 -> V_154 = V_98 ;
V_2 -> V_155 = V_100 ;
}
V_2 -> V_156 . V_142 = ( V_85 ) ;
V_2 -> V_156 . V_143 = ( V_86 ) ;
V_2 -> V_156 . V_144 = ( V_87 ) ;
V_2 -> V_156 . V_145 = ( V_88 ) ;
V_2 -> V_156 . V_146 = ( V_89 ) ;
V_2 -> V_157 . V_142 = ( V_90 ) ;
V_2 -> V_157 . V_143 = ( V_92 ) ;
V_2 -> V_157 . V_144 = ( V_93 ) ;
V_2 -> V_157 . V_145 = ( V_94 ) ;
V_2 -> V_157 . V_146 = ( V_97 ) ;
V_2 -> V_157 . V_149 = ( V_95 ) ;
V_2 -> V_157 . V_150 = ( V_96 ) ;
V_2 -> V_158 . V_152 = 0x04 ;
V_2 -> V_158 . V_153 = true ;
V_2 -> V_159 . V_142 = V_91 ;
V_2 -> V_159 . V_143 = 0 ;
V_2 -> V_159 . V_144 = 0 ;
V_2 -> V_159 . V_145 = 0xFFFF ;
V_2 -> V_159 . V_149 = 0x2100 ;
V_2 -> V_159 . V_150 = 4000 ;
V_2 -> V_159 . V_146 = 1 ;
V_2 -> V_160 . V_142 = V_73 ;
V_2 -> V_160 . V_143 = 0 ;
V_2 -> V_160 . V_144 = 0 ;
V_2 -> V_160 . V_145 = 9000 ;
V_2 -> V_160 . V_149 = 13424 ;
V_2 -> V_160 . V_150 = 0 ;
V_2 -> V_160 . V_146 = 3 ;
V_2 -> V_160 . V_161 = 30 ;
V_2 -> V_160 . V_162 = 30000 ;
V_2 -> V_163 . V_152 = 4 ;
V_2 -> V_163 . V_153 = false ;
V_2 -> V_164 . V_142 = V_91 ;
V_2 -> V_164 . V_143 = 0 ;
V_2 -> V_164 . V_144 = 6023 ;
V_2 -> V_164 . V_145 = 27000 ;
V_2 -> V_164 . V_149 = 0x2380 ;
V_2 -> V_164 . V_150 = 4000 ;
V_2 -> V_164 . V_146 = 3 ;
V_2 -> V_165 . V_142 = V_73 ;
V_2 -> V_165 . V_143 = 0 ;
V_2 -> V_165 . V_144 = 0 ;
V_2 -> V_165 . V_145 = 9000 ;
V_2 -> V_165 . V_149 = 0x0511 ;
V_2 -> V_165 . V_150 = 0 ;
V_2 -> V_165 . V_146 = 3 ;
V_2 -> V_165 . V_162 = 5119 ;
V_2 -> V_165 . V_161 = 50 ;
V_2 -> V_166 = 140 ;
V_2 -> V_167 . V_152 = 4 ;
V_2 -> V_167 . V_153 = false ;
V_2 -> V_3 = V_168 ;
V_2 -> V_169 = V_170 ;
V_2 -> V_171 = true ;
V_2 -> V_172 = false ;
V_2 -> V_173 = false ;
V_2 -> V_174 = false ;
V_2 -> V_175 = false ;
V_2 -> V_176 = false ;
V_2 -> V_177 = ( V_109 != 0 ) ;
V_2 -> V_178 = ( V_102 != 0 ) ;
V_2 -> V_179 = ( V_103 != 0 ) ;
V_2 -> V_180 = V_114 ;
V_2 -> V_181 = V_115 ;
V_2 -> V_182 = ( V_110 & 0x07 ) ;
V_2 -> V_183 = ( V_112 & 0x07 ) ;
V_2 -> V_184 = 19392658 ;
V_2 -> V_185 = false ;
if ( V_117 )
V_2 -> V_172 = true ;
V_2 -> V_186 = V_105 ;
if ( V_104 < 10000 )
V_2 -> V_186 = V_104 ;
V_2 -> V_187 = V_107 ;
if ( V_106 < 10000 )
V_2 -> V_187 = V_106 ;
V_2 -> V_188 = V_189 ;
V_2 -> V_190 = V_191 ;
V_2 -> V_192 = 204 * 8 ;
V_2 -> V_193 = 1 ;
V_2 -> V_194 = V_195 ;
V_2 -> V_196 = 0 ;
V_2 -> V_197 = ( V_108 ) ;
V_2 -> V_136 = false ;
V_2 -> V_70 = V_198 ;
V_2 -> V_199 = ( V_118 == 0 ) ;
V_2 -> V_200 = false ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
T_1 V_201 = 0 ;
T_4 V_202 = 0 ;
T_4 V_203 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_204 , V_205 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_206 , & V_203 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_206 , V_207 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_19 ( V_2 , V_208 , & V_201 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_209 , & V_202 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_206 , V_203 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_4 V_210 = 0 ;
T_1 V_211 = 0 ;
int V_38 ;
const char * V_212 = L_14 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_204 , V_205 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_206 , 0xFABA ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_213 , & V_210 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_206 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
switch ( ( V_210 & V_214 ) ) {
case 0 :
break;
case 1 :
V_2 -> V_126 = 27000 ;
break;
case 2 :
V_2 -> V_126 = 20250 ;
break;
case 3 :
V_2 -> V_126 = 20250 ;
break;
default:
F_13 ( V_43 L_15 ) ;
return - V_215 ;
}
V_38 = F_19 ( V_2 , V_208 , & V_211 ) ;
if ( V_38 < 0 )
goto error;
F_13 ( V_43 L_16 , V_211 ) ;
switch ( ( V_211 >> 29 ) & 0xF ) {
case 0 :
V_2 -> V_216 = V_217 ;
V_212 = L_17 ;
break;
case 2 :
V_2 -> V_216 = V_218 ;
V_212 = L_18 ;
break;
case 3 :
V_2 -> V_216 = V_219 ;
V_212 = L_19 ;
break;
default:
V_2 -> V_216 = V_220 ;
V_38 = - V_215 ;
F_13 ( V_43 L_20 ,
( V_211 >> 29 ) & 0xF ) ;
goto V_221;
}
switch ( ( V_211 >> 12 ) & 0xFF ) {
case 0x13 :
V_2 -> V_120 = false ;
V_2 -> V_124 = false ;
V_2 -> V_123 = false ;
V_2 -> V_125 = false ;
V_2 -> V_121 = true ;
V_2 -> V_122 = true ;
V_2 -> V_222 = true ;
V_2 -> V_223 = false ;
V_2 -> V_224 = false ;
V_2 -> V_225 = false ;
break;
case 0x15 :
V_2 -> V_120 = false ;
V_2 -> V_124 = false ;
V_2 -> V_123 = true ;
V_2 -> V_125 = false ;
V_2 -> V_121 = true ;
V_2 -> V_122 = false ;
V_2 -> V_222 = true ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = false ;
break;
case 0x16 :
V_2 -> V_120 = false ;
V_2 -> V_124 = false ;
V_2 -> V_123 = true ;
V_2 -> V_125 = false ;
V_2 -> V_121 = true ;
V_2 -> V_122 = false ;
V_2 -> V_222 = true ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = false ;
break;
case 0x18 :
V_2 -> V_120 = false ;
V_2 -> V_124 = false ;
V_2 -> V_123 = true ;
V_2 -> V_125 = true ;
V_2 -> V_121 = true ;
V_2 -> V_122 = false ;
V_2 -> V_222 = true ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = false ;
break;
case 0x21 :
V_2 -> V_120 = false ;
V_2 -> V_124 = false ;
V_2 -> V_123 = true ;
V_2 -> V_125 = true ;
V_2 -> V_121 = true ;
V_2 -> V_122 = true ;
V_2 -> V_222 = true ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = false ;
break;
case 0x23 :
V_2 -> V_120 = false ;
V_2 -> V_124 = false ;
V_2 -> V_123 = true ;
V_2 -> V_125 = true ;
V_2 -> V_121 = true ;
V_2 -> V_122 = true ;
V_2 -> V_222 = true ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = false ;
break;
case 0x25 :
V_2 -> V_120 = false ;
V_2 -> V_124 = false ;
V_2 -> V_123 = true ;
V_2 -> V_125 = true ;
V_2 -> V_121 = true ;
V_2 -> V_122 = true ;
V_2 -> V_222 = true ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = false ;
break;
case 0x26 :
V_2 -> V_120 = false ;
V_2 -> V_124 = false ;
V_2 -> V_123 = true ;
V_2 -> V_125 = false ;
V_2 -> V_121 = true ;
V_2 -> V_122 = true ;
V_2 -> V_222 = true ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
V_2 -> V_225 = false ;
break;
default:
F_13 ( V_43 L_21 ,
( ( V_211 >> 12 ) & 0xFF ) ) ;
V_38 = - V_215 ;
goto V_221;
}
F_13 ( V_226
L_22 ,
( ( V_211 >> 12 ) & 0xFF ) , V_212 ,
V_2 -> V_126 / 1000 ,
V_2 -> V_126 % 1000 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_221:
return V_38 ;
}
static int F_30 ( struct V_1 * V_2 , T_4 V_227 , T_4 * V_228 )
{
int V_38 ;
bool V_229 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_230 , V_227 ) ;
if ( V_38 < 0 )
goto error;
if ( V_227 == V_231 )
F_26 ( 1 ) ;
V_229 =
( bool ) ( ( V_227 == V_232 ) &&
( ( V_2 -> V_134 ) &
V_233 ) ==
V_234 ) ;
if ( V_229 == false ) {
T_1 V_63 = 0 ;
T_4 V_235 ;
do {
F_26 ( 1 ) ;
V_63 += 1 ;
V_38 = F_17 ( V_2 , V_230 ,
& V_235 ) ;
} while ( ( V_38 < 0 ) && ( V_63 < V_236 )
&& ( V_235 != 0 ) );
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_237 , V_228 ) ;
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
F_32 ( & V_2 -> V_238 ) ;
V_38 = F_21 ( V_2 , V_239 , V_2 -> V_240 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_241 , V_2 -> V_134 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_242 , V_2 -> V_133 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_243 , V_2 -> V_244 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_245 , V_2 -> V_130 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_246 , V_247 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_30 ( V_2 , V_232 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_134 &= ~ V_234 ;
error:
F_33 ( & V_2 -> V_238 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_34 ( struct V_1 * V_2 )
{
F_12 ( 1 , L_3 ) ;
V_2 -> V_133 = ( V_2 -> V_47 << 1 ) ;
V_2 -> V_240 = 0x96FF ;
V_2 -> V_134 = V_135 ;
return F_31 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 , bool V_248 )
{
int V_38 = - 1 ;
T_4 V_249 = 0 ;
T_4 V_250 = 0 ;
F_12 ( 1 , L_23 ,
V_248 ? L_24 : L_25 ,
V_2 -> V_251 ? L_26 : L_27 ) ;
V_38 = F_21 ( V_2 , V_204 , V_205 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_206 , 0xFABA ) ;
if ( V_38 < 0 )
goto error;
if ( V_248 == false ) {
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
} else {
V_250 =
( ( V_2 -> V_182 <<
V_264 ) | 0x0003 ) ;
V_249 = ( ( V_2 -> V_183 <<
V_265 ) |
0x0003 ) ;
V_38 = F_21 ( V_2 , V_252 , V_250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_253 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_255 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_251 == true ) {
V_38 = F_21 ( V_2 , V_257 , V_250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_258 , V_250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_259 , V_250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_260 , V_250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_261 , V_250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_262 , V_250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_263 , V_250 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_250 = ( ( V_2 -> V_182 <<
V_264 )
| 0x0003 ) ;
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
}
V_38 = F_21 ( V_2 , V_254 , V_249 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_256 , V_250 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_266 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_206 , 0x0000 ) ;
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
T_4 V_267 , T_4 V_268 , T_1 V_269 )
{
T_4 V_270 = 0 ;
int V_38 ;
unsigned long V_271 ;
F_12 ( 1 , L_3 ) ;
F_32 ( & V_2 -> V_238 ) ;
V_38 = F_21 ( V_2 , V_272 , V_273 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_274 , V_267 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_275 , V_268 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_276 , V_277 ) ;
if ( V_38 < 0 )
goto error;
V_271 = V_278 + F_38 ( V_269 ) ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_279 , & V_270 ) ;
if ( V_38 < 0 )
goto error;
} while ( ( V_270 == 0x1 ) &&
( ( F_39 ( V_271 ) ) ) );
if ( V_270 == 0x1 ) {
F_13 ( V_43 L_28 ) ;
V_38 = - V_215 ;
goto V_221;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_221:
F_33 ( & V_2 -> V_238 ) ;
return V_38 ;
}
static int F_40 ( struct V_1 * V_2 ,
const T_3 V_280 [] , T_1 V_281 )
{
const T_3 * V_282 = V_280 ;
T_4 V_57 ;
T_4 V_283 ;
T_1 V_53 ;
T_4 V_284 ;
T_4 V_54 ;
T_4 V_285 ;
T_1 V_286 = 0 ;
T_1 V_14 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_283 = ( V_282 [ 0 ] << 8 ) | V_282 [ 1 ] ;
V_282 += sizeof( T_4 ) ;
V_286 += sizeof( T_4 ) ;
V_284 = ( V_282 [ 0 ] << 8 ) | V_282 [ 1 ] ;
V_282 += sizeof( T_4 ) ;
V_286 += sizeof( T_4 ) ;
for ( V_14 = 0 ; V_14 < V_284 ; V_14 += 1 ) {
V_53 = ( V_282 [ 0 ] << 24 ) | ( V_282 [ 1 ] << 16 ) |
( V_282 [ 2 ] << 8 ) | V_282 [ 3 ] ;
V_282 += sizeof( T_1 ) ;
V_286 += sizeof( T_1 ) ;
V_54 = ( ( V_282 [ 0 ] << 8 ) | V_282 [ 1 ] ) * sizeof( T_4 ) ;
V_282 += sizeof( T_4 ) ;
V_286 += sizeof( T_4 ) ;
V_57 = ( V_282 [ 0 ] << 8 ) | V_282 [ 1 ] ;
V_282 += sizeof( T_4 ) ;
V_286 += sizeof( T_4 ) ;
V_285 = ( V_282 [ 0 ] << 8 ) | V_282 [ 1 ] ;
V_282 += sizeof( T_4 ) ;
V_286 += sizeof( T_4 ) ;
if ( V_286 + V_54 > V_281 ) {
F_13 ( V_43 L_29 ) ;
return - V_215 ;
}
V_38 = F_24 ( V_2 , V_53 , V_54 , V_282 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_30 , V_38 ) ;
break;
}
V_282 += V_54 ;
V_286 += V_54 ;
}
return V_38 ;
}
static int F_41 ( struct V_1 * V_2 , bool V_287 )
{
int V_38 ;
T_4 V_37 = 0 ;
T_4 V_288 = V_289 ;
T_4 V_290 = V_291 ;
unsigned long V_271 ;
F_12 ( 1 , L_3 ) ;
if ( V_287 == false ) {
V_288 = V_292 ;
V_290 = V_293 ;
}
V_38 = F_17 ( V_2 , V_294 , & V_37 ) ;
if ( V_38 >= 0 && V_37 == V_290 ) {
return V_38 ;
}
V_38 = F_21 ( V_2 , V_295 , V_288 ) ;
V_271 = V_278 + F_38 ( V_296 ) ;
do {
V_38 = F_17 ( V_2 , V_294 , & V_37 ) ;
if ( ( V_38 >= 0 && V_37 == V_290 ) || F_39 ( V_271 ) )
break;
F_26 ( 1 ) ;
} while ( 1 );
if ( V_37 != V_290 ) {
F_13 ( V_43 L_28 ) ;
return - V_215 ;
}
return V_38 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
T_4 V_297 = 0 ;
T_4 V_298 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_299 , & V_297 ) ;
if ( V_38 < 0 )
goto error;
V_297 |= V_300 ;
V_38 = F_21 ( V_2 , V_299 , V_297 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_301 , & V_298 ) ;
if ( V_38 < 0 )
goto error;
V_298 |= V_302 ;
V_38 = F_21 ( V_2 , V_301 , V_298 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_4 V_227 , T_3 V_303 ,
T_4 * V_304 , T_3 V_305 , T_4 * V_306 )
{
#if ( V_307 - V_308 ) != 15
#error DRXK register mapping no longer compatible with this routine!
#endif
T_4 V_309 = 0 ;
int V_38 = - V_215 ;
unsigned long V_271 ;
T_3 V_310 [ 34 ] ;
int V_311 = 0 , V_312 ;
const char * V_313 ;
char V_314 [ 30 ] ;
F_12 ( 1 , L_3 ) ;
if ( ( V_227 == 0 ) || ( ( V_303 > 0 ) && ( V_304 == NULL ) ) ||
( ( V_305 > 0 ) && ( V_306 == NULL ) ) )
goto error;
F_32 ( & V_2 -> V_238 ) ;
for ( V_312 = V_303 - 1 ; V_312 >= 0 ; V_312 -= 1 ) {
V_310 [ V_311 ++ ] = ( V_304 [ V_312 ] & 0xFF ) ;
V_310 [ V_311 ++ ] = ( ( V_304 [ V_312 ] >> 8 ) & 0xFF ) ;
}
V_310 [ V_311 ++ ] = ( V_227 & 0xFF ) ;
V_310 [ V_311 ++ ] = ( ( V_227 >> 8 ) & 0xFF ) ;
F_24 ( V_2 , V_307 -
( V_303 - 1 ) , V_311 , V_310 ) ;
V_271 = V_278 + F_38 ( V_315 ) ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_316 , & V_309 ) ;
if ( V_38 < 0 )
goto error;
} while ( ! ( V_309 == V_317 ) && ( F_39 ( V_271 ) ) );
if ( V_309 != V_317 ) {
F_13 ( V_43 L_31 ) ;
V_38 = - V_42 ;
goto V_221;
}
if ( ( V_305 > 0 ) && ( V_306 != NULL ) ) {
T_5 V_318 ;
int V_312 ;
for ( V_312 = V_305 - 1 ; V_312 >= 0 ; V_312 -= 1 ) {
V_38 = F_17 ( V_2 , V_307 - V_312 , & V_306 [ V_312 ] ) ;
if ( V_38 < 0 )
goto error;
}
V_318 = ( T_5 ) V_306 [ 0 ] ;
if ( V_318 >= 0 )
goto error;
switch ( V_318 ) {
case V_319 :
V_313 = L_32 ;
break;
case V_320 :
V_313 = L_33 ;
break;
case V_321 :
V_313 = L_34 ;
break;
case V_322 :
V_313 = L_35 ;
break;
default:
sprintf ( V_314 , L_36 , V_318 ) ;
V_313 = V_314 ;
}
F_13 ( V_43 L_37 , V_313 , V_227 ) ;
F_44 ( L_38 , V_323 , V_310 , V_311 ) ;
V_38 = - V_215 ;
goto V_221;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_221:
F_33 ( & V_2 -> V_238 ) ;
return V_38 ;
}
static int F_45 ( struct V_1 * V_2 , bool V_324 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_325 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_324 ) {
V_37 |= ( V_326
| V_327
| V_328
| V_329
| V_330 ) ;
} else {
V_37 &= ( ( ~ V_326 )
& ( ~ V_327 )
& ( ~ V_328 )
& ( ~ V_329 )
& ( ~ V_330 )
) ;
}
V_38 = F_21 ( V_2 , V_325 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_46 ( struct V_1 * V_2 , enum V_331 * V_332 )
{
int V_38 = 0 ;
T_4 V_333 = 0 ;
F_12 ( 1 , L_3 ) ;
if ( V_332 == NULL )
return - V_215 ;
switch ( * V_332 ) {
case V_71 :
V_333 = V_66 ;
break;
case V_334 :
V_333 = V_335 ;
break;
case V_336 :
V_333 = V_337 ;
break;
case V_338 :
V_333 = V_339 ;
break;
case V_198 :
V_333 = V_340 ;
break;
default:
return - V_215 ;
}
if ( V_2 -> V_70 == * V_332 )
return 0 ;
if ( V_2 -> V_70 != V_71 ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_41 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
}
if ( * V_332 == V_71 ) {
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
V_38 = F_21 ( V_2 , V_65 , V_333 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
if ( * V_332 != V_334 ) {
V_2 -> V_134 |=
V_234 ;
V_38 = F_31 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
}
}
V_2 -> V_70 = * V_332 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_47 ( struct V_1 * V_2 , bool V_341 )
{
enum V_331 V_342 = V_334 ;
T_4 V_343 = 0 ;
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_344 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == V_345 ) {
V_38 = F_43 ( V_2 , V_346 | V_347 , 0 , NULL , 1 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_346 | V_348 , 0 , NULL , 1 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_21 ( V_2 , V_349 , V_350 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_351 , V_352 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_353 , V_354 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
if ( V_341 ) {
V_38 = F_46 ( V_2 , & V_342 ) ;
if ( V_38 < 0 )
goto error;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_49 ( struct V_1 * V_2 ,
enum V_355 V_356 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_204 , V_205 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_3 == V_356 )
return 0 ;
switch ( V_2 -> V_3 ) {
case V_168 :
break;
case V_4 :
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_47 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_3 = V_168 ;
break;
case V_5 :
case V_7 :
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_48 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_3 = V_168 ;
break;
case V_6 :
default:
V_38 = - V_215 ;
goto error;
}
switch ( V_356 ) {
case V_4 :
F_12 ( 1 , L_39 ) ;
V_2 -> V_3 = V_356 ;
V_38 = F_50 ( V_2 , V_356 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_5 :
case V_7 :
F_12 ( 1 , L_40 ,
( V_2 -> V_3 == V_5 ) ? 'A' : 'C' ) ;
V_2 -> V_3 = V_356 ;
V_38 = F_51 ( V_2 , V_356 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_6 :
default:
V_38 = - V_215 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_52 ( struct V_1 * V_2 , T_6 V_357 ,
T_6 V_358 )
{
int V_38 = - V_215 ;
T_4 V_359 ;
T_6 V_360 = V_357 / 1000 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_169 != V_361 &&
V_2 -> V_169 != V_362 )
goto error;
V_2 -> V_363 = ( V_2 -> V_364 . V_365 == V_366 ) ;
if ( V_358 < 0 ) {
V_2 -> V_363 = ! V_2 -> V_363 ;
V_358 = - V_358 ;
}
switch ( V_2 -> V_3 ) {
case V_5 :
case V_7 :
V_359 = ( V_358 / 1000 ) ;
V_38 = F_53 ( V_2 , V_359 , V_360 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_169 = V_362 ;
break;
case V_4 :
V_359 = ( V_358 / 1000 ) ;
V_38 = F_42 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_54 ( V_2 , V_359 , V_360 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_55 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_169 = V_362 ;
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
static int F_57 ( struct V_1 * V_2 , T_1 * V_367 ,
T_1 Time )
{
int V_38 = - V_215 ;
F_12 ( 1 , L_3 ) ;
if ( V_367 == NULL )
goto error;
* V_367 = V_368 ;
switch ( V_2 -> V_3 ) {
case V_5 :
case V_6 :
case V_7 :
V_38 = F_58 ( V_2 , V_367 ) ;
break;
case V_4 :
V_38 = F_59 ( V_2 , V_367 ) ;
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
T_4 V_297 = 0 ;
V_38 = F_17 ( V_2 , V_299 , & V_297 ) ;
if ( V_38 < 0 )
goto error;
V_297 &= ~ V_300 ;
V_38 = F_21 ( V_2 , V_299 , V_297 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_369 , 1 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_370 , 0x0000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_371 , 0x000C ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_372 , 0x000A ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_373 , 0x0008 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_374 , 0x0006 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_375 , 0x0680 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_376 , 0x0080 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_377 , 0x03F4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_378 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_379 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_380 , 12 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_62 ( struct V_1 * V_2 ,
enum V_355 V_356 )
{
int V_38 ;
T_4 V_381 = 0 ;
T_4 V_382 = 0 ;
T_4 V_383 = 0 ;
T_4 V_384 = 0 ;
T_4 V_385 = 2 ;
T_4 V_386 = 188 ;
T_1 V_387 = 0 ;
T_4 V_388 = 0 ;
T_4 V_389 = 0 ;
T_1 V_390 = 0 ;
bool V_391 = false ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_392 , & V_381 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_301 , & V_382 ) ;
if ( V_38 < 0 )
goto error;
V_381 &= ( ~ V_393 ) ;
V_382 &= ( ~ V_394 ) ;
if ( V_2 -> V_172 == true ) {
V_381 |= V_393 ;
V_382 |= V_394 ;
V_386 = 204 ;
}
V_382 &= ( ~ ( V_395 ) ) ;
if ( V_2 -> V_251 == false ) {
V_382 |= V_395 ;
}
switch ( V_356 ) {
case V_4 :
V_390 = V_2 -> V_180 ;
V_388 = 3 ;
V_387 = 0xC00000 ;
V_391 = V_2 -> V_178 ;
break;
case V_5 :
case V_7 :
V_388 = 0x0004 ;
V_387 = 0xD2B4EE ;
V_390 = V_2 -> V_181 ;
V_391 = V_2 -> V_179 ;
break;
default:
V_38 = - V_215 ;
}
if ( V_38 < 0 )
goto error;
if ( V_391 ) {
T_1 V_396 = 0 ;
V_383 = ( V_397 |
V_398 ) ;
V_384 = ( V_399 |
V_400 ) ;
V_396 = V_390 ;
if ( V_396 > 75900000UL ) {
V_396 = 75900000UL ;
}
V_385 = ( T_4 ) ( ( ( V_2 -> V_129 )
* 1000 ) / V_396 ) ;
if ( V_385 <= 2 )
V_385 = 0 ;
else
V_385 -= 2 ;
V_389 = 8 ;
} else {
V_383 = V_397 ;
V_384 = V_401 ;
V_389 = 5 ;
}
V_38 = F_21 ( V_2 , V_402 , V_386 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_403 , V_385 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_404 , V_383 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_405 , V_384 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_392 , V_381 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_301 , V_382 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_23 ( V_2 , V_406 , V_387 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_407 , V_389 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_408 , V_388 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_4 V_409 = 0 ;
T_4 V_410 =
V_411 | V_412 |
V_413 | V_414 |
V_415 | V_416 |
V_417 | V_418 ;
F_12 ( 1 , L_3 ) ;
V_409 &= ( ~ ( V_410 ) ) ;
if ( V_2 -> V_173 == true )
V_409 |= V_410 ;
V_409 &= ( ~ ( V_419 ) ) ;
if ( V_2 -> V_174 == true )
V_409 |= V_419 ;
V_409 &= ( ~ ( V_420 ) ) ;
if ( V_2 -> V_175 == true )
V_409 |= V_420 ;
V_409 &= ( ~ ( V_421 ) ) ;
if ( V_2 -> V_176 == true )
V_409 |= V_421 ;
V_409 &= ( ~ ( V_422 ) ) ;
if ( V_2 -> V_177 == true )
V_409 |= V_422 ;
return F_21 ( V_2 , V_423 , V_409 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_424 * V_425 , bool V_426 )
{
int V_38 = - V_215 ;
T_4 V_37 = 0 ;
struct V_424 * V_427 ;
F_12 ( 1 , L_3 ) ;
if ( V_425 == NULL )
goto error;
switch ( V_425 -> V_142 ) {
case V_73 :
V_38 = F_17 ( V_2 , V_325 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_330 ;
V_38 = F_21 ( V_2 , V_325 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_428 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_429 ;
if ( V_2 -> V_430 )
V_37 |= V_431 ;
else
V_37 &= ~ V_431 ;
V_38 = F_21 ( V_2 , V_428 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_432 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_433 ;
V_37 |= ( ~ ( V_425 -> V_146 <<
V_434 )
& V_433 ) ;
V_38 = F_21 ( V_2 , V_432 , V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( F_1 ( V_2 ) )
V_427 = & V_2 -> V_160 ;
else if ( F_2 ( V_2 ) )
V_427 = & V_2 -> V_165 ;
else
V_427 = & V_2 -> V_156 ;
if ( V_427 == NULL ) {
V_38 = - V_215 ;
goto error;
}
if ( V_427 -> V_142 == V_73 )
V_38 = F_21 ( V_2 , V_435 , V_425 -> V_149 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_436 , V_425 -> V_150 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_437 , V_425 -> V_145 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_438 :
V_38 = F_17 ( V_2 , V_325 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_330 ;
V_38 = F_21 ( V_2 , V_325 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_428 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_429 ;
if ( V_2 -> V_430 )
V_37 |= V_431 ;
else
V_37 &= ~ V_431 ;
V_38 = F_21 ( V_2 , V_428 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_436 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_439 , V_425 -> V_143 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_91 :
V_38 = F_17 ( V_2 , V_325 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_330 ;
V_38 = F_21 ( V_2 , V_325 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_428 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_429 ;
V_38 = F_21 ( V_2 , V_428 , V_37 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
V_38 = - V_215 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_424 * V_425 , bool V_426 )
{
T_4 V_37 = 0 ;
int V_38 = 0 ;
struct V_424 * V_440 ;
F_12 ( 1 , L_3 ) ;
switch ( V_425 -> V_142 ) {
case V_73 :
V_38 = F_17 ( V_2 , V_325 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_329 ;
V_38 = F_21 ( V_2 , V_325 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_428 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_441 ;
if ( V_2 -> V_200 )
V_37 |= V_442 ;
else
V_37 &= ~ V_442 ;
V_38 = F_21 ( V_2 , V_428 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_432 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_443 ;
V_37 |= ( ~ ( V_425 -> V_146 <<
V_444 )
& V_443 ) ;
V_38 = F_21 ( V_2 , V_432 , V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( F_2 ( V_2 ) )
V_440 = & V_2 -> V_164 ;
else
V_440 = & V_2 -> V_157 ;
if ( V_440 == NULL )
return - 1 ;
V_38 = F_21 ( V_2 , V_435 , V_440 -> V_149 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_438 :
V_38 = F_17 ( V_2 , V_325 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 &= ~ V_329 ;
V_38 = F_21 ( V_2 , V_325 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_428 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_441 ;
if ( V_2 -> V_200 )
V_37 |= V_442 ;
else
V_37 &= ~ V_442 ;
V_38 = F_21 ( V_2 , V_428 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_435 , V_425 -> V_143 ) ;
if ( V_38 < 0 )
goto error;
break;
case V_91 :
V_38 = F_17 ( V_2 , V_325 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_329 ;
V_38 = F_21 ( V_2 , V_325 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_428 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_441 ;
V_38 = F_21 ( V_2 , V_428 , V_37 ) ;
if ( V_38 < 0 )
goto error;
break;
}
V_38 = F_21 ( V_2 , V_445 , V_425 -> V_149 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 * V_446 )
{
T_4 V_447 ;
int V_38 ;
T_4 V_448 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_449 , & V_447 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
* V_446 = 0 ;
if ( V_447 > V_450 )
V_448 = V_447 - V_450 ;
if ( V_448 < 14000 )
* V_446 = ( 14000 - V_448 ) / 4 ;
else
* V_446 = 0 ;
return V_38 ;
}
static int F_67 ( struct V_1 * V_2 ,
T_6 * V_451 )
{
int V_38 = 0 ;
T_4 V_452 = 0 ;
T_1 V_453 = 0 ;
T_1 V_454 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_455 , & V_452 ) ;
if ( V_38 < 0 ) {
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return - V_215 ;
}
switch ( V_2 -> V_364 . V_456 ) {
case V_457 :
V_453 = V_458 << 2 ;
break;
case V_459 :
V_453 = V_460 << 2 ;
break;
case V_461 :
V_453 = V_462 << 2 ;
break;
case V_463 :
V_453 = V_464 << 2 ;
break;
default:
case V_465 :
V_453 = V_466 << 2 ;
break;
}
if ( V_452 > 0 ) {
V_454 = F_8 ( V_453 ) -
F_8 ( ( T_1 ) V_452 ) ;
}
* V_451 = V_454 ;
return V_38 ;
}
static int F_68 ( struct V_1 * V_2 ,
T_6 * V_451 )
{
int V_38 ;
T_4 V_467 = 0 ;
T_1 V_468 = 0 ;
T_1 V_469 = 0 ;
T_4 V_470 = 0 ;
T_4 V_471 = 0 ;
T_4 V_472 = 0 ;
T_1 V_473 = 0 ;
T_1 V_474 = 0 ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
T_1 V_475 = 0 ;
T_4 V_476 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_477 , & V_471 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_478 , & V_472 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_479 , & V_470 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_480 , & V_467 ) ;
if ( V_38 < 0 )
goto error;
V_468 = ( T_1 ) V_467 ;
if ( ( V_470 > 11 ) &&
( V_468 < 0x00000FFFUL ) ) {
V_468 += 0x00010000UL ;
}
V_38 = F_17 ( V_2 , V_481 , & V_467 ) ;
if ( V_38 < 0 )
goto error;
V_469 = ( T_1 ) V_467 ;
if ( ( V_470 > 11 ) &&
( V_469 < 0x00000FFFUL ) )
V_469 += 0x00010000UL ;
V_38 = F_17 ( V_2 , V_482 , & V_476 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_471 == 0 ) || ( V_472 == 0 ) )
V_475 = 0 ;
else if ( ( V_468 + V_469 ) == 0 ) {
V_475 = 0 ;
} else {
V_474 = ( V_468 + V_469 ) <<
V_470 ;
if ( ( V_476 &
V_483 )
== V_484 )
V_473 = 17 ;
else
V_473 = 68 ;
V_10 = F_8 ( V_471 *
V_471 ) ;
V_11 = F_8 ( V_472 * V_473 ) ;
V_12 = F_8 ( V_474 ) ;
V_475 = V_10 + V_11 ;
if ( V_475 > V_12 )
V_475 -= V_12 ;
else
V_475 = 0 ;
}
* V_451 = V_475 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_69 ( struct V_1 * V_2 , T_6 * V_451 )
{
F_12 ( 1 , L_3 ) ;
* V_451 = 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
return F_68 ( V_2 , V_451 ) ;
case V_5 :
case V_7 :
return F_67 ( V_2 , V_451 ) ;
default:
break;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , bool V_485 )
{
int V_38 = - V_215 ;
F_12 ( 1 , L_3 ) ;
if ( V_2 -> V_169 == V_170 )
goto error;
if ( V_2 -> V_169 == V_486 )
goto error;
if ( V_2 -> V_487 )
return 0 ;
V_38 = F_21 ( V_2 , V_246 , V_247 ) ;
if ( V_38 < 0 )
goto error;
if ( V_485 ) {
V_38 = F_21 ( V_2 , V_245 , V_488 ) ;
if ( V_38 < 0 )
goto error;
} else {
V_38 = F_21 ( V_2 , V_245 , V_489 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_30 ( V_2 , V_490 , 0 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_491 * V_492 )
{
int V_38 = - V_215 ;
F_12 ( 1 , L_3 ) ;
if ( ( V_492 == NULL )
|| ( V_492 -> V_152 > V_493 ) )
goto error;
V_38 = F_21 ( V_2 , V_494 , V_492 -> V_152 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 V_495 ,
T_4 V_267 , T_4 V_268 , T_1 V_269 )
{
T_4 V_270 = 0 ;
T_4 V_286 = ( T_4 ) ( ( V_495 >> 0 ) & 0x00FFFF ) ;
T_4 V_496 = ( T_4 ) ( ( V_495 >> 16 ) & 0x000FFF ) ;
int V_38 ;
unsigned long V_271 ;
F_12 ( 1 , L_3 ) ;
F_32 ( & V_2 -> V_238 ) ;
V_38 = F_21 ( V_2 , V_272 , V_497 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_498 , V_496 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_499 , V_286 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_500 , V_267 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_501 , V_268 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_276 , V_277 ) ;
if ( V_38 < 0 )
goto error;
V_271 = V_278 + F_38 ( V_269 ) ;
do {
V_38 = F_17 ( V_2 , V_279 , & V_270 ) ;
if ( V_38 < 0 )
goto error;
} while ( ( V_270 == 0x1 ) && F_39 ( V_271 ) );
if ( V_270 == 0x1 ) {
F_13 ( V_43 L_28 ) ;
V_38 = - V_215 ;
goto V_221;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
V_221:
F_33 ( & V_2 -> V_238 ) ;
return V_38 ;
}
static int F_73 ( struct V_1 * V_2 , T_4 * V_502 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_503 , V_504 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_505 , 1 ) ;
if ( V_38 < 0 )
goto error;
* V_502 = 0 ;
V_38 = F_17 ( V_2 , V_506 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_502 = * V_502 + 1 ;
V_38 = F_17 ( V_2 , V_507 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_502 = * V_502 + 1 ;
V_38 = F_17 ( V_2 , V_508 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == 127 )
* V_502 = * V_502 + 1 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_74 ( struct V_1 * V_2 )
{
T_4 V_502 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_73 ( V_2 , & V_502 ) ;
if ( V_38 < 0 )
goto error;
if ( V_502 == 1 ) {
T_4 V_509 = 0 ;
V_38 = F_17 ( V_2 , V_510 , & V_509 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_509 | V_511 ) ==
V_512 ) {
V_509 &= ( ~ ( V_511 ) ) ;
V_509 |=
V_513 ;
} else {
V_509 &= ( ~ ( V_511 ) ) ;
V_509 |=
V_512 ;
}
V_38 = F_21 ( V_2 , V_510 , V_509 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_73 ( V_2 , & V_502 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_502 < 2 )
V_38 = - V_215 ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_4 V_514 ,
T_6 V_515 , bool V_426 )
{
bool V_516 = false ;
T_1 V_517 = V_515 ;
T_1 V_518 = 0 ;
bool V_519 = ! V_2 -> V_363 ;
T_1 V_520 ;
bool V_521 ;
int V_38 ;
T_1 V_522 ;
T_1 V_523 = ( T_1 ) ( V_2 -> V_129 / 3 ) ;
T_1 V_524 ;
bool V_525 ;
F_12 ( 1 , L_3 ) ;
if ( V_426 ) {
if ( ( V_2 -> V_3 == V_5 ) ||
( V_2 -> V_3 == V_7 ) ||
( V_2 -> V_3 == V_4 ) )
V_516 = true ;
else
V_516 = false ;
}
if ( V_519 )
V_522 = V_514 +
V_517 + V_518 ;
else
V_522 = V_514 -
V_517 - V_518 ;
if ( V_522 > V_523 / 2 ) {
V_520 = V_523 - V_522 ;
V_521 = true ;
} else {
V_520 = V_522 ;
V_521 = false ;
}
V_524 = V_520 ;
V_525 = V_2 -> V_199 ^ V_519 ^
V_521 ^ V_516 ;
V_2 -> V_526 =
F_7 ( ( V_524 ) , V_523 ) ;
if ( V_525 )
V_2 -> V_526 = ~ V_2 -> V_526 + 1 ;
V_38 = F_23 ( V_2 , V_527 ,
V_2 -> V_526 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_76 ( struct V_1 * V_2 , bool V_426 )
{
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
T_4 V_540 = 0 ;
T_4 V_541 = 0 ;
T_4 V_37 = 0 ;
T_4 V_542 = 0 ;
T_4 V_543 = 0 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_535 = 1023 ;
V_540 = 2047 ;
V_531 = 500 ;
V_536 = 1023 ;
if ( ! F_2 ( V_2 ) ) {
F_13 ( V_43 L_41 , V_62 , V_2 -> V_3 ) ;
return - V_215 ;
}
V_532 = 8 ;
V_533 = ( T_4 ) - 9 ;
V_543 = 0 ;
V_534 = 8 ;
V_537 = ( T_4 ) - 9 ;
V_538 = ( T_4 ) - 1030 ;
V_541 = 0x2380 ;
V_539 = 0x2380 ;
V_529 = 0x0511 ;
V_528 = 0x0511 ;
V_530 = 5119 ;
V_542 = V_2 -> V_165 . V_161 ;
V_38 = F_21 ( V_2 , V_544 , V_542 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_545 , V_543 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_546 , V_528 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_445 , V_529 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_547 , V_530 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_548 , V_540 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_435 , V_541 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_549 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_550 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_439 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_551 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_552 , V_536 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_553 , V_535 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_554 , V_538 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_555 , V_539 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_556 , V_531 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_557 , 1023 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_558 , ( T_4 ) - 1023 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_559 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_560 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_561 , V_532 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_562 , V_534 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_563 , V_533 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_564 , V_537 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_565 , 0x7fff ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_566 , 0x0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_567 , 0x0117 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_568 , 0x0657 ) ;
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
V_38 = F_21 ( V_2 , V_573 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_574 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_575 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_576 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_577 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_578 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_579 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 = 0x0657 ;
V_37 &= ~ V_580 ;
V_37 |= ( V_581 << V_582 ) ;
V_37 &= ~ V_583 ;
V_37 |= ( V_584 << V_585 ) ;
V_38 = F_21 ( V_2 , V_579 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_77 ( struct V_1 * V_2 , T_4 * V_586 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( V_586 == NULL )
V_38 = F_21 ( V_2 , V_587 , 0 ) ;
else
V_38 = F_17 ( V_2 , V_587 , V_586 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_78 ( struct V_1 * V_2 ,
T_4 V_227 , T_4 V_588 ,
T_4 V_589 , T_4 V_590 , T_4 V_591 ,
T_4 V_592 , T_4 V_593 )
{
T_4 V_309 = 0 ;
T_4 V_594 = 0 ;
T_4 V_595 = 0 ;
T_4 V_596 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_349 , & V_596 ) ;
if ( V_596 != 1 ) {
V_38 = - V_215 ;
}
if ( V_38 < 0 )
goto error;
V_595 = 0 ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_597 , & V_309 ) ;
V_595 ++ ;
} while ( ( V_309 != 0 ) && ( V_595 < V_236 ) );
if ( V_595 >= V_236 && ( V_38 < 0 ) )
goto error;
switch ( V_227 ) {
case V_598 :
case V_599 :
case V_600 :
V_38 = F_21 ( V_2 , V_601 , V_588 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
break;
}
switch ( V_227 ) {
case V_598 :
case V_599 :
case V_600 :
V_38 = F_21 ( V_2 , V_602 , V_590 ) ;
case V_603 :
case V_604 :
V_38 = F_21 ( V_2 , V_605 , V_589 ) ;
case V_606 :
case V_607 :
V_38 = F_21 ( V_2 , V_597 , V_227 ) ;
break;
default:
V_38 = - V_215 ;
}
if ( V_38 < 0 )
goto error;
V_595 = 0 ;
do {
F_26 ( 1 ) ;
V_38 = F_17 ( V_2 , V_597 , & V_309 ) ;
V_595 ++ ;
} while ( ( V_309 != 0 ) && ( V_595 < V_236 ) );
if ( V_595 >= V_236 && ( V_38 < 0 ) )
goto error;
V_38 = F_17 ( V_2 , V_601 , & V_594 ) ;
if ( V_594 == 0xFFFF ) {
V_38 = - V_215 ;
}
if ( V_38 < 0 )
goto error;
switch ( V_227 ) {
case V_604 :
case V_606 :
V_38 = F_17 ( V_2 , V_605 , & ( V_589 ) ) ;
case V_603 :
case V_608 :
case V_598 :
case V_599 :
case V_600 :
case V_607 :
break;
default:
V_38 = - V_215 ;
break;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_79 ( struct V_1 * V_2 )
{
enum V_331 V_342 = V_71 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_46 ( V_2 , & V_342 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_80 ( struct V_1 * V_2 , bool * V_609 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( * V_609 == true )
V_38 = F_21 ( V_2 , V_610 , 0 ) ;
else
V_38 = F_21 ( V_2 , V_610 , 1 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_81 ( struct V_1 * V_2 , bool * V_609 )
{
int V_38 ;
F_12 ( 1 , L_3 ) ;
if ( * V_609 == true ) {
V_38 = F_21 ( V_2 , V_611 ,
V_612 ) ;
} else {
V_38 = F_21 ( V_2 , V_611 , 0 ) ;
}
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_613 * V_614 )
{
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_615 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_614 -> V_616 ) {
case V_617 :
V_37 &= ~ V_618 ;
V_37 |= ( ( V_614 -> V_619 <<
V_620 )
& ( V_618 ) ) ;
break;
case V_621 :
V_37 &= ~ V_622 ;
V_37 |= ( ( V_614 -> V_619 <<
V_623 )
& ( V_622 ) ) ;
break;
default:
return - V_215 ;
}
V_38 = F_21 ( V_2 , V_615 , V_37 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_83 ( struct V_1 * V_2 ,
enum V_624 * V_146 )
{
int V_38 = - V_215 ;
F_12 ( 1 , L_3 ) ;
switch ( * V_146 ) {
case V_625 :
case V_195 :
case V_626 :
break;
default:
goto error;
}
V_38 = F_21 ( V_2 , V_627 ,
( T_4 ) * V_146 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_38 ;
bool V_628 = false ;
bool V_629 = true ;
struct V_613 V_630 = { 0 , V_617 } ;
struct V_613 V_631 = { 0 , V_621 } ;
F_12 ( 1 , L_3 ) ;
V_38 = F_80 ( V_2 , & V_628 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_81 ( V_2 , & V_629 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_82 ( V_2 , & V_630 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_82 ( V_2 , & V_631 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_547 , V_2 -> V_160 . V_162 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_50 ( struct V_1 * V_2 ,
enum V_355 V_356 )
{
T_4 V_343 = 0 ;
T_4 V_37 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
F_79 ( V_2 ) ;
F_85 ( V_2 ) ;
V_38 = F_43 ( V_2 , V_346 | V_348 , 0 , NULL , 1 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_346 | V_632 , 0 , NULL , 1 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_349 , V_350 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_351 , V_352 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_353 , V_354 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_633 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_634 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_635 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_636 , V_637 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_638 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_639 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_640 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_641 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_642 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_643 , 0x4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_644 , 0x4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_645 , 1600 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_646 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_647 , 448 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_648 , 495 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_37 ( V_2 , V_649 , V_650 , V_651 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_652 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_653 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_654 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_353 , V_655 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_74 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_71 ( V_2 , & V_2 -> V_163 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_656 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_64 ( V_2 , & V_2 -> V_159 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_65 ( V_2 , & V_2 -> V_160 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_657 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
V_37 |= V_658 ;
V_38 = F_21 ( V_2 , V_657 , V_37 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_345 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_138 ) {
V_38 = F_21 ( V_2 , V_544 , V_2 -> V_160 . V_161 ) ;
if ( V_38 < 0 )
goto error;
}
#ifdef F_86
V_38 = F_21 ( V_2 , V_659 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_660 , 2 ) ;
if ( V_38 < 0 )
goto error;
#endif
V_38 = F_21 ( V_2 , V_661 , 1 ) ;
if ( V_38 < 0 )
goto error;
#ifdef F_86
V_38 = F_21 ( V_2 , V_662 , 0x400 ) ;
if ( V_38 < 0 )
goto error;
#else
V_38 = F_21 ( V_2 , V_662 , 0x1000 ) ;
if ( V_38 < 0 )
goto error;
#endif
V_38 = F_21 ( V_2 , V_663 , 0x0001 ) ;
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
T_4 V_590 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_590 = V_664 ;
V_38 = F_78 ( V_2 , V_598 , 0 , V_665 , V_590 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_60 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_666 , V_667 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_54 ( struct V_1 * V_2 , T_4 V_668 ,
T_6 V_515 )
{
T_4 V_343 = 0 ;
T_4 V_476 = 0 ;
T_4 V_669 = 0 ;
T_1 V_670 = 0 ;
T_1 V_671 = 0 ;
T_4 V_590 ;
int V_38 ;
F_12 ( 1 , L_42 , V_668 , V_515 ) ;
V_38 = F_43 ( V_2 , V_346 | V_347 , 0 , NULL , 1 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_656 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_349 , V_350 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_351 , V_352 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_672 , V_673 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_364 . V_674 ) {
case V_675 :
default:
V_669 |= V_676 ;
case V_677 :
V_476 |= V_678 ;
break;
case V_679 :
V_476 |= V_484 ;
break;
}
switch ( V_2 -> V_364 . V_680 ) {
default:
case V_681 :
V_669 |= V_682 ;
case V_683 :
V_476 |= V_684 ;
break;
case V_685 :
V_476 |= V_686 ;
break;
case V_687 :
V_476 |= V_688 ;
break;
case V_689 :
V_476 |= V_690 ;
break;
}
switch ( V_2 -> V_364 . V_691 ) {
case V_692 :
case V_693 :
default:
V_669 |= V_694 ;
case V_695 :
V_476 |= V_696 ;
break;
case V_697 :
V_476 |= V_698 ;
break;
case V_699 :
V_476 |= V_700 ;
break;
}
switch ( V_2 -> V_364 . V_456 ) {
case V_701 :
default:
V_669 |= V_702 ;
case V_461 :
V_476 |= V_703 ;
break;
case V_704 :
V_476 |= V_705 ;
break;
case V_457 :
V_476 |= V_706 ;
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
V_476 |= V_707 ;
V_38 = F_21 ( V_2 , V_708 , V_709 ) ;
if ( V_38 < 0 )
goto error;
#endif
switch ( V_2 -> V_364 . V_710 ) {
case V_711 :
default:
V_669 |= V_712 ;
case V_713 :
V_476 |= V_714 ;
break;
case V_715 :
V_476 |= V_716 ;
break;
case V_717 :
V_476 |= V_718 ;
break;
case V_719 :
V_476 |= V_720 ;
break;
case V_721 :
V_476 |= V_722 ;
break;
}
switch ( V_2 -> V_364 . V_723 ) {
case 0 :
V_2 -> V_364 . V_723 = 8000000 ;
case 8000000 :
V_671 = V_724 ;
V_38 = F_21 ( V_2 , V_725 , 3052 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_726 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_727 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_728 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_729 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
case 7000000 :
V_671 = V_730 ;
V_38 = F_21 ( V_2 , V_725 , 3491 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_726 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_727 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_728 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_729 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
case 6000000 :
V_671 = V_731 ;
V_38 = F_21 ( V_2 , V_725 , 4073 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_726 , 19 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_727 , 19 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_728 , 14 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_729 , 1 ) ;
if ( V_38 < 0 )
goto error;
break;
default:
V_38 = - V_215 ;
goto error;
}
if ( V_670 == 0 ) {
V_670 = F_7 ( ( T_1 )
( ( V_2 -> V_129 *
1000 ) / 3 ) , V_671 ) ;
if ( ( V_670 & 0x7fL ) >= 0x40 )
V_670 += 0x80L ;
V_670 = V_670 >> 7 ;
V_670 = V_670 - ( 1 << 23 ) ;
}
V_670 &=
( ( ( ( T_1 ) V_732 ) <<
V_733 ) | V_734 ) ;
V_38 = F_23 ( V_2 , V_735 , V_670 ) ;
if ( V_38 < 0 )
goto error;
#if 0
status = DVBTSetFrequencyShift(demod, channel, tunerOffset);
if (status < 0)
goto error;
#endif
V_38 = F_75 ( V_2 , V_668 , V_515 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_345 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_736 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_349 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_346 | V_737 , 0 , NULL , 1 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
V_590 = ( V_676 |
V_682 |
V_702 |
V_694 |
V_712 ) ;
V_38 = F_78 ( V_2 , V_599 ,
0 , V_476 , V_590 , 0 , 0 , 0 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_138 )
V_38 = F_83 ( V_2 , & V_2 -> V_194 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 * V_367 )
{
int V_38 ;
const T_4 V_738 = ( V_739 |
V_740 ) ;
const T_4 V_741 = ( V_740 ) ;
const T_4 V_742 = V_743 ;
T_4 V_744 = 0 ;
T_4 V_745 = 0 ;
F_12 ( 1 , L_3 ) ;
* V_367 = V_368 ;
V_38 = F_17 ( V_2 , V_349 , & V_745 ) ;
if ( V_38 < 0 )
goto V_271;
if ( V_745 == V_350 )
goto V_271;
V_38 = F_17 ( V_2 , V_746 , & V_744 ) ;
if ( V_38 < 0 )
goto V_271;
if ( ( V_744 & V_738 ) == V_738 )
* V_367 = V_747 ;
else if ( ( V_744 & V_741 ) == V_741 )
* V_367 = V_748 ;
else if ( ( V_744 & V_742 ) == V_742 )
* V_367 = V_749 ;
else if ( V_744 & V_750 )
* V_367 = V_751 ;
V_271:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_87 ( struct V_1 * V_2 )
{
enum V_331 V_342 = V_334 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_46 ( V_2 , & V_342 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_48 ( struct V_1 * V_2 )
{
T_4 V_37 = 0 ;
T_4 V_343 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_17 ( V_2 , V_344 , & V_37 ) ;
if ( V_38 < 0 )
goto error;
if ( V_37 == V_345 ) {
V_38 = F_21 ( V_2 , V_752 , V_753 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_754 | V_347 , 0 , NULL , 1 , & V_343 ) ;
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
enum V_755 V_456 ,
T_1 V_756 )
{
T_1 V_757 = 0 ;
T_1 V_758 = 0 ;
T_4 V_759 = 0 ;
T_4 V_760 = 0 ;
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_759 = 1 ;
switch ( V_456 ) {
case V_761 :
V_757 = 4 * V_756 ;
break;
case V_762 :
V_757 = 5 * V_756 ;
break;
case V_763 :
V_757 = 6 * V_756 ;
break;
case V_764 :
V_757 = 7 * V_756 ;
break;
case V_765 :
V_757 = 8 * V_756 ;
break;
default:
V_38 = - V_215 ;
}
if ( V_38 < 0 )
goto error;
V_757 /= 1000 ;
V_757 *= 500 ;
V_758 = ( V_757 / 1632UL ) + 1 ;
V_759 = 1 + ( T_4 ) ( V_758 >> 16 ) ;
if ( V_759 == 0 ) {
V_38 = - V_215 ;
if ( V_38 < 0 )
goto error;
}
V_760 =
( ( T_4 ) V_758 +
( V_759 >> 1 ) ) / V_759 ;
V_38 = F_21 ( V_2 , V_662 , V_760 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_663 , V_759 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_766 , V_760 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
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
V_38 = F_21 ( V_2 , V_771 , 13517 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 13517 ) ;
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
V_38 = F_21 ( V_2 , V_776 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , V_458 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 32 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 95 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 120 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 230 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 105 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 220 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , ( T_4 ) - 65 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , ( T_4 ) - 127 ) ;
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
V_38 = F_21 ( V_2 , V_771 , 6707 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 6707 ) ;
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
V_38 = F_21 ( V_2 , V_776 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , V_460 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 20 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 90 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 170 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) - 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) - 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 26 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , ( T_4 ) - 56 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , ( T_4 ) - 86 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_767 , 13336 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 12618 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 11988 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 13809 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 13809 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 15609 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , V_462 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 30 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 30 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 48 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 110 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 200 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 95 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 141 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , ( T_4 ) - 45 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , ( T_4 ) - 80 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_767 , 6564 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 6598 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 6394 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 6409 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 6656 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 7238 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , V_464 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 120 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 64 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 140 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 65 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) - 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , ( T_4 ) - 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , ( T_4 ) - 23 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_767 , 11502 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_768 , 12084 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_769 , 12543 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_770 , 12931 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_771 , 13629 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_772 , 15385 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_773 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_774 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_775 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_776 , 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_777 , 6 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_778 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_779 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_780 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_781 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_782 , V_466 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_783 , 15 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_784 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_785 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_786 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_787 , 24 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_788 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_789 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_790 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_791 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_792 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_793 , 250 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_794 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_795 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_796 , 125 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_797 , 16 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_798 , 25 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_799 , 48 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_800 , 5 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_801 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_802 , 10 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_803 , 50 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_804 , 60 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_805 , 80 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_806 , 100 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_807 , 150 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_808 , 110 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_809 , 40 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_810 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_811 , 12 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_812 , ( T_4 ) 8 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_813 , ( T_4 ) 74 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_814 , ( T_4 ) 18 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_815 , ( T_4 ) 13 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_816 , ( T_4 ) 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_817 , ( T_4 ) 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_818 , ( T_4 ) - 8 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_343 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_752 , V_753 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_754 | V_348 , 0 , NULL , 1 , & V_343 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_95 ( struct V_1 * V_2 )
{
T_1 V_819 = 0 ;
T_1 V_820 = 0 ;
T_1 V_821 = 0 ;
T_4 V_822 = 0 ;
T_1 V_823 = 0 ;
int V_38 ;
F_12 ( 1 , L_3 ) ;
V_819 = ( V_2 -> V_129 * 1000 ) / 3 ;
V_822 = 0 ;
if ( V_2 -> V_364 . V_824 <= 1188750 )
V_822 = 3 ;
else if ( V_2 -> V_364 . V_824 <= 2377500 )
V_822 = 2 ;
else if ( V_2 -> V_364 . V_824 <= 4755000 )
V_822 = 1 ;
V_38 = F_21 ( V_2 , V_825 , V_822 ) ;
if ( V_38 < 0 )
goto error;
V_820 = V_2 -> V_364 . V_824 * ( 1 << V_822 ) ;
if ( V_820 == 0 ) {
V_38 = - V_215 ;
goto error;
}
V_821 = ( V_819 / V_820 ) * ( 1 << 21 ) +
( F_7 ( ( V_819 % V_820 ) , V_820 ) >> 7 ) -
( 1 << 23 ) ;
V_38 = F_23 ( V_2 , V_735 , V_821 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_826 = V_821 ;
V_820 = V_2 -> V_364 . V_824 ;
if ( V_819 == 0 ) {
V_38 = - V_215 ;
goto error;
}
V_823 = ( V_820 / V_819 ) * ( 1 << 12 ) +
( F_7 ( ( V_820 % V_819 ) , V_819 ) >>
16 ) ;
if ( V_823 > 511 )
V_823 = 511 ;
V_38 = F_21 ( V_2 , V_827 , ( T_4 ) V_823 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_58 ( struct V_1 * V_2 , T_1 * V_367 )
{
int V_38 ;
T_4 V_828 [ 2 ] = { 0 , 0 } ;
F_12 ( 1 , L_3 ) ;
* V_367 = V_368 ;
V_38 = F_43 ( V_2 ,
V_754 |
V_829 , 0 , NULL , 2 ,
V_828 ) ;
if ( V_38 < 0 )
F_13 ( V_43 L_43 , V_62 , V_38 ) ;
if ( V_828 [ 1 ] < V_830 ) {
} else if ( V_828 [ 1 ] < V_831 ) {
* V_367 = V_749 ;
} else if ( V_828 [ 1 ] < V_832 ) {
* V_367 = V_747 ;
} else {
* V_367 = V_751 ;
}
return V_38 ;
}
static int F_53 ( struct V_1 * V_2 , T_4 V_668 ,
T_6 V_515 )
{
int V_38 ;
T_4 V_833 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_4 V_343 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_834 , V_835 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_836 , V_837 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_94 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_95 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_364 . V_456 ) {
case V_465 :
V_2 -> V_188 = V_765 ;
break;
case V_701 :
case V_461 :
V_2 -> V_188 = V_763 ;
break;
case V_457 :
V_2 -> V_188 = V_761 ;
break;
case V_459 :
V_2 -> V_188 = V_762 ;
break;
case V_463 :
V_2 -> V_188 = V_764 ;
break;
default:
V_38 = - V_215 ;
break;
}
if ( V_38 < 0 )
goto error;
V_833 [ 0 ] = V_2 -> V_188 ;
V_833 [ 1 ] = V_191 ;
if ( V_2 -> V_3 == V_7 )
V_833 [ 2 ] = V_838 ;
else
V_833 [ 2 ] = V_839 ;
V_833 [ 3 ] |= ( V_840 ) ;
V_38 = F_43 ( V_2 , V_754 | V_841 , 4 , V_833 , 1 , & V_343 ) ;
if ( V_38 < 0 ) {
if ( V_2 -> V_3 == V_7 )
V_833 [ 0 ] = V_838 ;
else
V_833 [ 0 ] = V_839 ;
V_38 = F_43 ( V_2 , V_754 | V_632 , 1 , V_833 , 1 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
V_833 [ 0 ] = V_2 -> V_188 ;
V_833 [ 1 ] = V_191 ;
V_38 = F_43 ( V_2 , V_754 | V_841 , 2 , V_833 , 1 , & V_343 ) ;
}
if ( V_38 < 0 )
goto error;
#if 0
status = SetFrequency(channel, tunerFreqOffset));
if (status < 0)
goto error;
#endif
V_38 = F_75 ( V_2 , V_668 , V_515 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_88 ( V_2 , V_2 -> V_188 , V_2 -> V_364 . V_824 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_646 , V_842 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_843 , V_844 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_845 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_846 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_847 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_848 , 7 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_849 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_850 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_851 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_852 , 1 ) ;
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
V_38 = F_21 ( V_2 , V_858 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_859 , 2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_860 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_861 , 3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_862 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_863 , 4 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_864 , V_865 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_656 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_2 -> V_364 . V_456 ) {
case V_457 :
V_38 = F_89 ( V_2 ) ;
break;
case V_459 :
V_38 = F_90 ( V_2 ) ;
break;
case V_701 :
case V_461 :
V_38 = F_91 ( V_2 ) ;
break;
case V_463 :
V_38 = F_92 ( V_2 ) ;
break;
case V_465 :
V_38 = F_93 ( V_2 ) ;
break;
default:
V_38 = - V_215 ;
break;
}
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_345 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_62 ( V_2 , V_2 -> V_3 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_60 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_666 , V_667 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_752 , V_866 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_353 , V_655 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_43 ( V_2 , V_754 | V_737 , 0 , NULL , 1 , & V_343 ) ;
if ( V_38 < 0 )
goto error;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_355 V_356 )
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
V_38 = F_21 ( V_2 , V_353 , V_354 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_636 , V_637 ) ;
if ( V_38 < 0 )
goto error;
switch ( V_356 ) {
case V_5 :
V_38 = F_37 ( V_2 , V_867 , V_650 , V_651 ) ;
break;
case V_7 :
V_38 = F_72 ( V_2 , V_868 , V_869 , V_870 , V_651 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_72 ( V_2 , V_871 , V_869 , V_870 , V_651 ) ;
break;
default:
V_38 = - V_215 ;
}
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_643 , ( 1 << V_872 ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_873 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_874 , ( ( 1 << V_875 ) | ( 1 << V_876 ) ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_642 , 21 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_634 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_647 , 448 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_635 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_653 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_877 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_878 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_879 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_633 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_880 , 500 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_648 , 1000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_610 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_640 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_641 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_652 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_881 , 1 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_45 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_505 , 0x01 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_74 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_882 , 2000 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_656 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_76 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_71 ( V_2 , & ( V_2 -> V_167 ) ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_64 ( V_2 , & ( V_2 -> V_164 ) , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_65 ( V_2 , & ( V_2 -> V_165 ) , true ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_345 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_38 ;
T_4 V_883 = 0 ;
F_12 ( 1 , L_3 ) ;
V_38 = F_21 ( V_2 , V_204 , V_205 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_206 , V_207 ) ;
if ( V_38 < 0 )
goto error;
if ( V_2 -> V_222 ) {
if ( V_2 -> V_884 & 0x0001 ) {
V_38 = F_21 ( V_2 , V_885 , V_2 -> V_197 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_886 , & V_883 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_887 & 0x0001 ) == 0 )
V_883 &= 0x7FFF ;
else
V_883 |= 0x8000 ;
V_38 = F_21 ( V_2 , V_886 , V_883 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_2 -> V_884 & 0x0002 ) {
V_38 = F_21 ( V_2 , V_885 , V_2 -> V_197 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_886 , & V_883 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_887 & 0x0002 ) == 0 )
V_883 &= 0xBFFF ;
else
V_883 |= 0x4000 ;
V_38 = F_21 ( V_2 , V_886 , V_883 ) ;
if ( V_38 < 0 )
goto error;
}
if ( V_2 -> V_884 & 0x0004 ) {
V_38 = F_21 ( V_2 , V_885 , V_2 -> V_197 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_17 ( V_2 , V_886 , & V_883 ) ;
if ( V_38 < 0 )
goto error;
if ( ( V_2 -> V_887 & 0x0004 ) == 0 )
V_883 &= 0xFFFB ;
else
V_883 |= 0x0004 ;
V_38 = F_21 ( V_2 , V_886 , V_883 ) ;
if ( V_38 < 0 )
goto error;
}
}
V_38 = F_21 ( V_2 , V_206 , 0x0000 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
bool V_888 ;
F_12 ( 1 , L_3 ) ;
if ( ! V_2 -> V_889 )
return 0 ;
V_888 = V_2 -> V_887 & V_2 -> V_889 ;
if ( V_2 -> V_890 ^ V_888 ) {
if ( V_2 -> V_890 )
V_2 -> V_887 &= ~ V_2 -> V_889 ;
else
V_2 -> V_887 |= V_2 -> V_889 ;
V_38 = F_99 ( V_2 ) ;
}
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
bool V_888 ;
F_12 ( 1 , L_3 ) ;
if ( ! V_2 -> V_889 )
return 0 ;
V_888 = V_2 -> V_887 & V_2 -> V_889 ;
if ( ! ( V_2 -> V_890 ^ V_888 ) ) {
if ( V_2 -> V_890 )
V_2 -> V_887 |= V_2 -> V_889 ;
else
V_2 -> V_887 &= ~ V_2 -> V_889 ;
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
if ( V_2 -> V_128 ) {
V_38 = F_70 ( V_2 , true ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_41 ( V_2 , false ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_65 , V_337 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_134 |= V_234 ;
V_38 = F_31 ( V_2 ) ;
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static int F_101 ( struct V_1 * V_2 , const char * V_891 )
{
const struct V_892 * V_893 = NULL ;
int V_318 = 0 ;
F_12 ( 1 , L_3 ) ;
V_318 = F_102 ( & V_893 , V_891 , V_2 -> V_51 -> V_894 . V_895 ) ;
if ( V_318 < 0 ) {
F_13 ( V_43
L_44 , V_891 ) ;
F_13 ( V_226
L_45 , V_891 ) ;
return V_318 ;
}
V_318 = F_40 ( V_2 , V_893 -> V_37 , V_893 -> V_896 ) ;
F_103 ( V_893 ) ;
return V_318 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
enum V_331 V_342 = V_334 ;
T_4 V_897 ;
F_12 ( 1 , L_3 ) ;
if ( ( V_2 -> V_169 == V_170 ) ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_28 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_898 , V_899 | V_900 | V_901 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_67 , V_68 ) ;
if ( V_38 < 0 )
goto error;
F_26 ( 1 ) ;
V_2 -> V_140 = true ;
V_38 = F_29 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_244 =
( T_4 ) ( ( V_2 -> V_126 / 1000 ) *
V_902 ) / 1000 ;
if ( V_2 -> V_244 >
V_903 ) {
V_2 -> V_244 =
V_903 ;
}
V_2 -> V_244 +=
V_2 -> V_244 <<
V_904 ;
V_38 = F_34 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
#if V_905
if ( ! ( V_2 -> V_9 )
&& ! ( V_2 -> V_137 ) )
#endif
{
V_38 = F_21 ( V_2 , V_204 , V_205 ) ;
if ( V_38 < 0 )
goto error;
}
V_38 = F_36 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_906 , V_907 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_908 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_295 , V_289 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_909 , V_910 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_37 ( V_2 , 0 , 6 , 100 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_2 -> V_911 )
F_101 ( V_2 , L_46 ) ;
else
F_101 ( V_2 , V_2 -> V_911 ) ;
V_38 = F_21 ( V_2 , V_295 , V_292 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_344 , V_345 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_28 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
F_26 ( 30 ) ;
V_342 = V_334 ;
V_38 = F_46 ( V_2 , & V_342 ) ;
if ( V_38 < 0 )
goto error;
V_897 =
( ( ( V_912 / 100 ) % 10 ) << 12 ) +
( ( ( V_912 / 10 ) % 10 ) << 8 ) +
( ( V_912 % 10 ) << 4 ) +
( V_913 % 10 ) ;
V_38 = F_21 ( V_2 , V_914 , V_897 ) ;
if ( V_38 < 0 )
goto error;
V_897 =
( ( ( V_915 / 1000 ) % 10 ) << 12 ) +
( ( ( V_915 / 100 ) % 10 ) << 8 ) +
( ( ( V_915 / 10 ) % 10 ) << 4 ) +
( V_915 % 10 ) ;
V_38 = F_21 ( V_2 , V_916 , V_897 ) ;
if ( V_38 < 0 )
goto error;
F_13 ( V_226 L_47 ,
V_912 , V_913 ,
V_915 ) ;
V_38 = F_21 ( V_2 , V_917 , 0 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_21 ( V_2 , V_666 , V_918 ) ;
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
V_38 = F_35 ( V_2 , V_2 -> V_171 ) ;
if ( V_38 < 0 )
goto error;
V_38 = F_99 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_169 = V_361 ;
if ( V_2 -> V_136 ) {
V_38 = F_100 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
V_2 -> V_169 = V_486 ;
} else
V_2 -> V_169 = V_361 ;
}
error:
if ( V_38 < 0 )
F_13 ( V_43 L_13 , V_38 , V_62 ) ;
return V_38 ;
}
static void F_105 ( struct V_919 * V_920 )
{
struct V_1 * V_2 = V_920 -> V_921 ;
F_12 ( 1 , L_3 ) ;
F_106 ( V_2 ) ;
}
static int F_107 ( struct V_919 * V_920 )
{
struct V_1 * V_2 = V_920 -> V_921 ;
F_12 ( 1 , L_3 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_108 ( struct V_919 * V_920 , int V_287 )
{
struct V_1 * V_2 = V_920 -> V_921 ;
F_12 ( 1 , L_48 , V_287 ? L_24 : L_25 ) ;
return F_70 ( V_2 , V_287 ? true : false ) ;
}
static int F_109 ( struct V_919 * V_920 )
{
struct V_922 * V_313 = & V_920 -> V_923 ;
T_1 V_924 = V_313 -> V_925 , V_926 ;
struct V_1 * V_2 = V_920 -> V_921 ;
T_1 IF ;
F_12 ( 1 , L_3 ) ;
if ( ! V_920 -> V_927 . V_928 . V_929 ) {
F_13 ( V_43
L_49 ) ;
return - V_215 ;
}
if ( V_920 -> V_927 . V_930 )
V_920 -> V_927 . V_930 ( V_920 , 1 ) ;
if ( V_920 -> V_927 . V_928 . V_931 )
V_920 -> V_927 . V_928 . V_931 ( V_920 ) ;
if ( V_920 -> V_927 . V_930 )
V_920 -> V_927 . V_930 ( V_920 , 0 ) ;
V_926 = V_2 -> V_364 . V_925 ;
V_2 -> V_364 = * V_313 ;
if ( V_926 != V_924 ) {
F_56 ( V_2 ) ;
switch ( V_924 ) {
case V_932 :
case V_933 :
if ( ! V_2 -> V_122 )
return - V_215 ;
V_2 -> V_934 = ( V_924 == V_933 ) ? true : false ;
if ( V_2 -> V_934 )
F_49 ( V_2 , V_7 ) ;
else
F_49 ( V_2 , V_5 ) ;
break;
case V_935 :
if ( ! V_2 -> V_121 )
return - V_215 ;
F_49 ( V_2 , V_4 ) ;
break;
default:
return - V_215 ;
}
}
V_920 -> V_927 . V_928 . V_929 ( V_920 , & IF ) ;
F_52 ( V_2 , 0 , IF ) ;
return 0 ;
}
static int F_110 ( struct V_919 * V_920 , T_7 * V_38 )
{
struct V_1 * V_2 = V_920 -> V_921 ;
T_1 V_936 ;
F_12 ( 1 , L_3 ) ;
* V_38 = 0 ;
F_57 ( V_2 , & V_936 , 0 ) ;
if ( V_936 == V_747 )
* V_38 |= 0x1f ;
if ( V_936 == V_748 )
* V_38 |= 0x0f ;
if ( V_936 == V_749 )
* V_38 |= 0x07 ;
return 0 ;
}
static int F_111 ( struct V_919 * V_920 , T_1 * V_937 )
{
F_12 ( 1 , L_3 ) ;
* V_937 = 0 ;
return 0 ;
}
static int F_112 ( struct V_919 * V_920 ,
T_4 * V_938 )
{
struct V_1 * V_2 = V_920 -> V_921 ;
T_1 V_28 = 0 ;
F_12 ( 1 , L_3 ) ;
F_66 ( V_2 , & V_28 ) ;
* V_938 = V_28 & 0xffff ;
return 0 ;
}
static int F_113 ( struct V_919 * V_920 , T_4 * V_939 )
{
struct V_1 * V_2 = V_920 -> V_921 ;
T_6 V_940 ;
F_12 ( 1 , L_3 ) ;
F_69 ( V_2 , & V_940 ) ;
* V_939 = V_940 & 0xffff ;
return 0 ;
}
static int F_114 ( struct V_919 * V_920 , T_1 * V_941 )
{
struct V_1 * V_2 = V_920 -> V_921 ;
T_4 V_318 ;
F_12 ( 1 , L_3 ) ;
F_77 ( V_2 , & V_318 ) ;
* V_941 = ( T_1 ) V_318 ;
return 0 ;
}
static int F_115 ( struct V_919 * V_920 , struct V_942
* V_943 )
{
struct V_922 * V_313 = & V_920 -> V_923 ;
F_12 ( 1 , L_3 ) ;
switch ( V_313 -> V_925 ) {
case V_932 :
case V_933 :
V_943 -> V_944 = 3000 ;
V_943 -> V_945 = 0 ;
V_943 -> V_946 = 0 ;
return 0 ;
default:
return - V_215 ;
}
}
struct V_919 * F_116 ( const struct V_947 * V_948 ,
struct V_25 * V_51 )
{
int V_949 ;
struct V_1 * V_2 = NULL ;
T_3 V_27 = V_948 -> V_27 ;
F_12 ( 1 , L_3 ) ;
V_2 = F_117 ( sizeof( struct V_1 ) , V_950 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_51 = V_51 ;
V_2 -> V_47 = V_27 ;
V_2 -> V_50 = V_948 -> V_50 ;
V_2 -> V_911 = V_948 -> V_911 ;
V_2 -> V_487 = V_948 -> V_487 ;
V_2 -> V_889 = V_948 -> V_889 ;
V_2 -> V_890 = V_948 -> V_890 ;
V_2 -> V_59 = V_948 -> V_951 ;
if ( V_948 -> V_952 )
V_2 -> V_251 = true ;
else
V_2 -> V_251 = false ;
V_2 -> V_884 = V_948 -> V_889 ;
if ( ! V_2 -> V_890 && V_2 -> V_889 )
V_2 -> V_887 |= V_2 -> V_889 ;
else
V_2 -> V_887 &= ~ V_2 -> V_889 ;
F_118 ( & V_2 -> V_238 ) ;
memcpy ( & V_2 -> V_953 . V_927 , & V_954 , sizeof( V_954 ) ) ;
V_2 -> V_953 . V_921 = V_2 ;
F_27 ( V_2 ) ;
if ( F_104 ( V_2 ) < 0 )
goto error;
V_949 = 0 ;
if ( V_2 -> V_122 ) {
V_2 -> V_953 . V_927 . V_924 [ V_949 ++ ] = V_932 ;
V_2 -> V_953 . V_927 . V_924 [ V_949 ++ ] = V_933 ;
F_119 ( V_2 -> V_953 . V_927 . V_955 . V_956 , L_50 ,
sizeof( V_2 -> V_953 . V_927 . V_955 . V_956 ) ) ;
}
if ( V_2 -> V_121 ) {
V_2 -> V_953 . V_927 . V_924 [ V_949 ++ ] = V_935 ;
F_119 ( V_2 -> V_953 . V_927 . V_955 . V_956 , L_51 ,
sizeof( V_2 -> V_953 . V_927 . V_955 . V_956 ) ) ;
}
F_13 ( V_226 L_52 ) ;
return & V_2 -> V_953 ;
error:
F_13 ( V_43 L_53 ) ;
F_106 ( V_2 ) ;
return NULL ;
}
