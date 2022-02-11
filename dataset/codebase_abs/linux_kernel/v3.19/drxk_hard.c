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
static inline T_1 F_6 ( T_1 V_15 )
{
return ( 100L * F_7 ( V_15 ) ) >> 24 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_16 ) ;
V_2 -> V_17 = true ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_17 )
return;
F_11 ( V_2 -> V_16 ) ;
V_2 -> V_17 = false ;
}
static int F_12 ( struct V_1 * V_2 , struct V_18 * V_19 ,
unsigned V_20 )
{
if ( V_2 -> V_17 )
return F_13 ( V_2 -> V_16 , V_19 , V_20 ) ;
else
return F_14 ( V_2 -> V_16 , V_19 , V_20 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_3 V_21 , T_3 * V_22 )
{
struct V_18 V_19 [ 1 ] = { { . V_23 = V_21 , . V_24 = V_25 ,
. V_26 = V_22 , . V_20 = 1 }
} ;
return F_12 ( V_2 , V_19 , 1 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_3 V_21 , T_3 * V_27 , int V_20 )
{
int V_28 ;
struct V_18 V_29 = {
. V_23 = V_21 , . V_24 = 0 , . V_26 = V_27 , . V_20 = V_20 } ;
F_17 ( 3 , L_1 ) ;
if ( V_30 > 2 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ )
F_18 ( L_2 , V_27 [ V_12 ] ) ;
F_18 ( L_3 ) ;
}
V_28 = F_12 ( V_2 , & V_29 , 1 ) ;
if ( V_28 >= 0 && V_28 != 1 )
V_28 = - V_31 ;
if ( V_28 < 0 )
F_19 ( L_4 , V_21 ) ;
return V_28 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_3 V_21 , T_3 * V_29 , int V_20 , T_3 * V_32 , int V_33 )
{
int V_28 ;
struct V_18 V_19 [ 2 ] = {
{ . V_23 = V_21 , . V_24 = 0 ,
. V_26 = V_29 , . V_20 = V_20 } ,
{ . V_23 = V_21 , . V_24 = V_25 ,
. V_26 = V_32 , . V_20 = V_33 }
} ;
V_28 = F_12 ( V_2 , V_19 , 2 ) ;
if ( V_28 != 2 ) {
if ( V_30 > 2 )
F_18 ( L_5 ) ;
if ( V_28 >= 0 )
V_28 = - V_31 ;
F_19 ( L_6 , V_21 ) ;
return V_28 ;
}
if ( V_30 > 2 ) {
int V_12 ;
F_17 ( 2 , L_7 ) ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ )
F_18 ( L_2 , V_29 [ V_12 ] ) ;
F_18 ( L_8 ) ;
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ )
F_18 ( L_2 , V_32 [ V_12 ] ) ;
F_18 ( L_3 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_34 , T_4 * V_27 , T_3 V_24 )
{
int V_28 ;
T_3 V_21 = V_2 -> V_35 , V_36 [ 4 ] , V_37 [ 2 ] , V_20 ;
if ( V_2 -> V_38 )
V_24 |= 0xC0 ;
if ( F_22 ( V_34 ) || ( V_24 != 0 ) ) {
V_36 [ 0 ] = ( ( ( V_34 << 1 ) & 0xFF ) | 0x01 ) ;
V_36 [ 1 ] = ( ( V_34 >> 16 ) & 0xFF ) ;
V_36 [ 2 ] = ( ( V_34 >> 24 ) & 0xFF ) | V_24 ;
V_36 [ 3 ] = ( ( V_34 >> 7 ) & 0xFF ) ;
V_20 = 4 ;
} else {
V_36 [ 0 ] = ( ( V_34 << 1 ) & 0xFF ) ;
V_36 [ 1 ] = ( ( ( V_34 >> 16 ) & 0x0F ) | ( ( V_34 >> 18 ) & 0xF0 ) ) ;
V_20 = 2 ;
}
F_17 ( 2 , L_9 , V_34 , V_24 ) ;
V_28 = F_20 ( V_2 , V_21 , V_36 , V_20 , V_37 , 2 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_27 )
* V_27 = V_37 [ 0 ] | ( V_37 [ 1 ] << 8 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_34 , T_4 * V_27 )
{
return F_21 ( V_2 , V_34 , V_27 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_34 , T_1 * V_27 , T_3 V_24 )
{
int V_28 ;
T_3 V_21 = V_2 -> V_35 , V_36 [ 4 ] , V_37 [ 4 ] , V_20 ;
if ( V_2 -> V_38 )
V_24 |= 0xC0 ;
if ( F_22 ( V_34 ) || ( V_24 != 0 ) ) {
V_36 [ 0 ] = ( ( ( V_34 << 1 ) & 0xFF ) | 0x01 ) ;
V_36 [ 1 ] = ( ( V_34 >> 16 ) & 0xFF ) ;
V_36 [ 2 ] = ( ( V_34 >> 24 ) & 0xFF ) | V_24 ;
V_36 [ 3 ] = ( ( V_34 >> 7 ) & 0xFF ) ;
V_20 = 4 ;
} else {
V_36 [ 0 ] = ( ( V_34 << 1 ) & 0xFF ) ;
V_36 [ 1 ] = ( ( ( V_34 >> 16 ) & 0x0F ) | ( ( V_34 >> 18 ) & 0xF0 ) ) ;
V_20 = 2 ;
}
F_17 ( 2 , L_9 , V_34 , V_24 ) ;
V_28 = F_20 ( V_2 , V_21 , V_36 , V_20 , V_37 , 4 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_27 )
* V_27 = V_37 [ 0 ] | ( V_37 [ 1 ] << 8 ) |
( V_37 [ 2 ] << 16 ) | ( V_37 [ 3 ] << 24 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_34 , T_1 * V_27 )
{
return F_24 ( V_2 , V_34 , V_27 , 0 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_34 , T_4 V_27 , T_3 V_24 )
{
T_3 V_21 = V_2 -> V_35 , V_39 [ 6 ] , V_20 ;
if ( V_2 -> V_38 )
V_24 |= 0xC0 ;
if ( F_22 ( V_34 ) || ( V_24 != 0 ) ) {
V_39 [ 0 ] = ( ( ( V_34 << 1 ) & 0xFF ) | 0x01 ) ;
V_39 [ 1 ] = ( ( V_34 >> 16 ) & 0xFF ) ;
V_39 [ 2 ] = ( ( V_34 >> 24 ) & 0xFF ) | V_24 ;
V_39 [ 3 ] = ( ( V_34 >> 7 ) & 0xFF ) ;
V_20 = 4 ;
} else {
V_39 [ 0 ] = ( ( V_34 << 1 ) & 0xFF ) ;
V_39 [ 1 ] = ( ( ( V_34 >> 16 ) & 0x0F ) | ( ( V_34 >> 18 ) & 0xF0 ) ) ;
V_20 = 2 ;
}
V_39 [ V_20 ] = V_27 & 0xff ;
V_39 [ V_20 + 1 ] = ( V_27 >> 8 ) & 0xff ;
F_17 ( 2 , L_10 , V_34 , V_27 , V_24 ) ;
return F_16 ( V_2 , V_21 , V_39 , V_20 + 2 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_34 , T_4 V_27 )
{
return F_26 ( V_2 , V_34 , V_27 , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_34 , T_1 V_27 , T_3 V_24 )
{
T_3 V_21 = V_2 -> V_35 , V_39 [ 8 ] , V_20 ;
if ( V_2 -> V_38 )
V_24 |= 0xC0 ;
if ( F_22 ( V_34 ) || ( V_24 != 0 ) ) {
V_39 [ 0 ] = ( ( ( V_34 << 1 ) & 0xFF ) | 0x01 ) ;
V_39 [ 1 ] = ( ( V_34 >> 16 ) & 0xFF ) ;
V_39 [ 2 ] = ( ( V_34 >> 24 ) & 0xFF ) | V_24 ;
V_39 [ 3 ] = ( ( V_34 >> 7 ) & 0xFF ) ;
V_20 = 4 ;
} else {
V_39 [ 0 ] = ( ( V_34 << 1 ) & 0xFF ) ;
V_39 [ 1 ] = ( ( ( V_34 >> 16 ) & 0x0F ) | ( ( V_34 >> 18 ) & 0xF0 ) ) ;
V_20 = 2 ;
}
V_39 [ V_20 ] = V_27 & 0xff ;
V_39 [ V_20 + 1 ] = ( V_27 >> 8 ) & 0xff ;
V_39 [ V_20 + 2 ] = ( V_27 >> 16 ) & 0xff ;
V_39 [ V_20 + 3 ] = ( V_27 >> 24 ) & 0xff ;
F_17 ( 2 , L_11 , V_34 , V_27 , V_24 ) ;
return F_16 ( V_2 , V_21 , V_39 , V_20 + 4 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_34 , T_1 V_27 )
{
return F_28 ( V_2 , V_34 , V_27 , 0 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_40 ,
const int V_41 , const T_3 V_42 [] )
{
int V_28 = 0 , V_43 = V_41 ;
T_3 V_24 = 0 ;
if ( V_2 -> V_38 )
V_24 |= 0xC0 ;
while ( V_43 > 0 ) {
int V_44 = V_43 > V_2 -> V_45 ?
V_2 -> V_45 : V_43 ;
T_3 * V_46 = & V_2 -> V_44 [ 0 ] ;
T_1 V_47 = 0 ;
if ( F_22 ( V_40 ) || ( V_24 != 0 ) ) {
V_46 [ 0 ] = ( ( ( V_40 << 1 ) & 0xFF ) | 0x01 ) ;
V_46 [ 1 ] = ( ( V_40 >> 16 ) & 0xFF ) ;
V_46 [ 2 ] = ( ( V_40 >> 24 ) & 0xFF ) ;
V_46 [ 3 ] = ( ( V_40 >> 7 ) & 0xFF ) ;
V_46 [ 2 ] |= V_24 ;
V_47 = 4 ;
if ( V_44 == V_2 -> V_45 )
V_44 -= 2 ;
} else {
V_46 [ 0 ] = ( ( V_40 << 1 ) & 0xFF ) ;
V_46 [ 1 ] = ( ( ( V_40 >> 16 ) & 0x0F ) |
( ( V_40 >> 18 ) & 0xF0 ) ) ;
V_47 = 2 ;
}
memcpy ( & V_2 -> V_44 [ V_47 ] , V_42 , V_44 ) ;
F_17 ( 2 , L_9 , V_40 , V_24 ) ;
if ( V_30 > 1 ) {
int V_12 ;
if ( V_42 )
for ( V_12 = 0 ; V_12 < V_44 ; V_12 ++ )
F_18 ( L_2 , V_42 [ V_12 ] ) ;
F_18 ( L_3 ) ;
}
V_28 = F_16 ( V_2 , V_2 -> V_35 ,
& V_2 -> V_44 [ 0 ] , V_44 + V_47 ) ;
if ( V_28 < 0 ) {
F_19 ( L_12 ,
V_48 , V_40 ) ;
break;
}
V_42 += V_44 ;
V_40 += ( V_44 >> 1 ) ;
V_43 -= V_44 ;
}
return V_28 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_28 ;
T_3 V_27 = 0 ;
T_4 V_49 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_15 ( V_2 , V_2 -> V_35 , & V_27 ) ;
if ( V_28 < 0 ) {
do {
V_27 = 0 ;
V_28 = F_16 ( V_2 , V_2 -> V_35 ,
& V_27 , 1 ) ;
F_32 ( 10000 , 11000 ) ;
V_49 ++ ;
if ( V_28 < 0 )
continue;
V_28 = F_15 ( V_2 , V_2 -> V_35 ,
& V_27 ) ;
} while ( V_28 < 0 &&
( V_49 < V_50 ) );
if ( V_28 < 0 && V_49 >= V_50 )
goto error;
}
V_28 = F_27 ( V_2 , V_51 , V_52 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_53 , V_54 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_55 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_56 = V_57 ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_1 V_58 = V_59 ;
T_1 V_60 = 0 ;
T_1 V_61 = 0 ;
T_1 V_62 = 0x7FFF ;
T_1 V_63 = 3 ;
T_1 V_64 = V_59 ;
T_1 V_65 = 0 ;
T_1 V_66 = 0 ;
T_1 V_67 = 0x7FFF ;
T_1 V_68 = 3 ;
T_1 V_69 = 9500 ;
T_1 V_70 = 4000 ;
T_1 V_71 = V_59 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
T_1 V_75 = 3 ;
T_1 V_76 = V_77 ;
T_1 V_78 = 0 ;
T_1 V_79 = 0 ;
T_1 V_80 = 0 ;
T_1 V_81 = 9500 ;
T_1 V_82 = 4000 ;
T_1 V_83 = 3 ;
T_1 V_84 = V_85 ;
T_1 V_86 = V_87 ;
T_1 V_88 = V_89 ;
T_1 V_90 = V_91 ;
T_1 V_92 = 0x0113 ;
T_1 V_93 = 0 ;
T_1 V_94 = V_95 ;
T_1 V_96 = 50000000 ;
T_1 V_97 = V_98 * 8 ;
T_1 V_99 = 0 ;
T_1 V_100 = 1 ;
T_1 V_101 = 0 ;
F_17 ( 1 , L_3 ) ;
V_2 -> V_102 = false ;
V_2 -> V_103 = false ;
V_2 -> V_104 = false ;
V_2 -> V_105 = false ;
V_2 -> V_106 = false ;
V_2 -> V_107 = false ;
if ( ! V_2 -> V_45 )
V_2 -> V_45 = 124 ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = false ;
V_2 -> V_110 = false ;
V_2 -> V_111 = 151875 ;
V_2 -> V_112 = ( ( V_2 -> V_111 / 1000 ) *
V_113 ) / 1000 ;
if ( V_2 -> V_112 > V_114 )
V_2 -> V_112 = V_114 ;
V_2 -> V_115 = ( V_2 -> V_35 << 1 ) ;
V_2 -> V_116 = V_117 ;
V_2 -> V_118 = ( V_101 != 0 ) ;
V_2 -> V_119 = false ;
V_2 -> V_120 . V_121 = V_58 ;
V_2 -> V_120 . V_122 = V_60 ;
V_2 -> V_120 . V_123 = V_61 ;
V_2 -> V_120 . V_124 = V_62 ;
V_2 -> V_120 . V_125 = V_63 ;
V_2 -> V_126 = 140 ;
V_2 -> V_127 . V_121 = V_64 ;
V_2 -> V_127 . V_122 = V_65 ;
V_2 -> V_127 . V_123 = V_66 ;
V_2 -> V_127 . V_124 = V_67 ;
V_2 -> V_127 . V_125 = V_68 ;
V_2 -> V_127 . V_128 = V_69 ;
V_2 -> V_127 . V_129 = V_70 ;
V_2 -> V_130 . V_131 = 0x07 ;
V_2 -> V_130 . V_132 = true ;
V_2 -> V_133 = V_85 ;
V_2 -> V_134 = V_87 ;
if ( V_86 <= 500 && V_84 < V_86 ) {
V_2 -> V_133 = V_84 ;
V_2 -> V_134 = V_86 ;
}
V_2 -> V_135 . V_121 = V_71 ;
V_2 -> V_135 . V_122 = V_72 ;
V_2 -> V_135 . V_123 = V_73 ;
V_2 -> V_135 . V_124 = V_74 ;
V_2 -> V_135 . V_125 = V_75 ;
V_2 -> V_136 . V_121 = V_76 ;
V_2 -> V_136 . V_122 = V_78 ;
V_2 -> V_136 . V_123 = V_79 ;
V_2 -> V_136 . V_124 = V_80 ;
V_2 -> V_136 . V_125 = V_83 ;
V_2 -> V_136 . V_128 = V_81 ;
V_2 -> V_136 . V_129 = V_82 ;
V_2 -> V_137 . V_131 = 0x04 ;
V_2 -> V_137 . V_132 = true ;
V_2 -> V_138 . V_121 = V_77 ;
V_2 -> V_138 . V_122 = 0 ;
V_2 -> V_138 . V_123 = 0 ;
V_2 -> V_138 . V_124 = 0xFFFF ;
V_2 -> V_138 . V_128 = 0x2100 ;
V_2 -> V_138 . V_129 = 4000 ;
V_2 -> V_138 . V_125 = 1 ;
V_2 -> V_139 . V_121 = V_59 ;
V_2 -> V_139 . V_122 = 0 ;
V_2 -> V_139 . V_123 = 0 ;
V_2 -> V_139 . V_124 = 9000 ;
V_2 -> V_139 . V_128 = 13424 ;
V_2 -> V_139 . V_129 = 0 ;
V_2 -> V_139 . V_125 = 3 ;
V_2 -> V_139 . V_140 = 30 ;
V_2 -> V_139 . V_141 = 30000 ;
V_2 -> V_142 . V_131 = 4 ;
V_2 -> V_142 . V_132 = false ;
V_2 -> V_143 . V_121 = V_77 ;
V_2 -> V_143 . V_122 = 0 ;
V_2 -> V_143 . V_123 = 6023 ;
V_2 -> V_143 . V_124 = 27000 ;
V_2 -> V_143 . V_128 = 0x2380 ;
V_2 -> V_143 . V_129 = 4000 ;
V_2 -> V_143 . V_125 = 3 ;
V_2 -> V_144 . V_121 = V_59 ;
V_2 -> V_144 . V_122 = 0 ;
V_2 -> V_144 . V_123 = 0 ;
V_2 -> V_144 . V_124 = 9000 ;
V_2 -> V_144 . V_128 = 0x0511 ;
V_2 -> V_144 . V_129 = 0 ;
V_2 -> V_144 . V_125 = 3 ;
V_2 -> V_144 . V_141 = 5119 ;
V_2 -> V_144 . V_140 = 50 ;
V_2 -> V_145 = 140 ;
V_2 -> V_146 . V_131 = 4 ;
V_2 -> V_146 . V_132 = false ;
V_2 -> V_3 = V_147 ;
V_2 -> V_148 = V_149 ;
V_2 -> V_150 = true ;
V_2 -> V_151 = false ;
V_2 -> V_152 = false ;
V_2 -> V_153 = false ;
V_2 -> V_154 = false ;
V_2 -> V_155 = false ;
V_2 -> V_156 = ( V_93 != 0 ) ;
V_2 -> V_157 = V_96 ;
V_2 -> V_158 = V_97 ;
V_2 -> V_159 = ( V_94 & 0x07 ) ;
V_2 -> V_160 = 19392658 ;
V_2 -> V_161 = false ;
if ( V_99 )
V_2 -> V_151 = true ;
V_2 -> V_162 = V_89 ;
if ( V_88 < 10000 )
V_2 -> V_162 = V_88 ;
V_2 -> V_163 = V_91 ;
if ( V_90 < 10000 )
V_2 -> V_163 = V_90 ;
V_2 -> V_164 = V_165 ;
V_2 -> V_166 = V_167 ;
V_2 -> V_168 = 204 * 8 ;
V_2 -> V_169 = 1 ;
V_2 -> V_170 = V_171 ;
V_2 -> V_172 = 0 ;
V_2 -> V_173 = V_92 ;
V_2 -> V_118 = false ;
V_2 -> V_56 = V_174 ;
V_2 -> V_175 = ( V_100 == 0 ) ;
V_2 -> V_176 = false ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
T_1 V_177 = 0 ;
T_4 V_178 = 0 ;
T_4 V_179 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_180 ,
V_181 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_182 , & V_179 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_182 , V_183 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_25 ( V_2 , V_184 , & V_177 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_185 , & V_178 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_182 , V_179 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_4 V_186 = 0 ;
T_1 V_187 = 0 ;
int V_28 ;
const char * V_188 = L_14 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_180 ,
V_181 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_182 , V_183 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_189 , & V_186 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_182 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
switch ( ( V_186 & V_190 ) ) {
case 0 :
break;
case 1 :
V_2 -> V_108 = 27000 ;
break;
case 2 :
V_2 -> V_108 = 20250 ;
break;
case 3 :
V_2 -> V_108 = 20250 ;
break;
default:
F_19 ( L_15 ) ;
return - V_191 ;
}
V_28 = F_25 ( V_2 , V_184 , & V_187 ) ;
if ( V_28 < 0 )
goto error;
F_36 ( L_16 , V_187 ) ;
switch ( ( V_187 >> 29 ) & 0xF ) {
case 0 :
V_2 -> V_192 = V_193 ;
V_188 = L_17 ;
break;
case 2 :
V_2 -> V_192 = V_194 ;
V_188 = L_18 ;
break;
case 3 :
V_2 -> V_192 = V_195 ;
V_188 = L_19 ;
break;
default:
V_2 -> V_192 = V_196 ;
V_28 = - V_191 ;
F_19 ( L_20 , ( V_187 >> 29 ) & 0xF ) ;
goto V_197;
}
switch ( ( V_187 >> 12 ) & 0xFF ) {
case 0x13 :
V_2 -> V_102 = false ;
V_2 -> V_106 = false ;
V_2 -> V_105 = false ;
V_2 -> V_107 = false ;
V_2 -> V_103 = true ;
V_2 -> V_104 = true ;
V_2 -> V_198 = true ;
V_2 -> V_199 = false ;
V_2 -> V_200 = false ;
V_2 -> V_201 = false ;
break;
case 0x15 :
V_2 -> V_102 = false ;
V_2 -> V_106 = false ;
V_2 -> V_105 = true ;
V_2 -> V_107 = false ;
V_2 -> V_103 = true ;
V_2 -> V_104 = false ;
V_2 -> V_198 = true ;
V_2 -> V_199 = true ;
V_2 -> V_200 = true ;
V_2 -> V_201 = false ;
break;
case 0x16 :
V_2 -> V_102 = false ;
V_2 -> V_106 = false ;
V_2 -> V_105 = true ;
V_2 -> V_107 = false ;
V_2 -> V_103 = true ;
V_2 -> V_104 = false ;
V_2 -> V_198 = true ;
V_2 -> V_199 = true ;
V_2 -> V_200 = true ;
V_2 -> V_201 = false ;
break;
case 0x18 :
V_2 -> V_102 = false ;
V_2 -> V_106 = false ;
V_2 -> V_105 = true ;
V_2 -> V_107 = true ;
V_2 -> V_103 = true ;
V_2 -> V_104 = false ;
V_2 -> V_198 = true ;
V_2 -> V_199 = true ;
V_2 -> V_200 = true ;
V_2 -> V_201 = false ;
break;
case 0x21 :
V_2 -> V_102 = false ;
V_2 -> V_106 = false ;
V_2 -> V_105 = true ;
V_2 -> V_107 = true ;
V_2 -> V_103 = true ;
V_2 -> V_104 = true ;
V_2 -> V_198 = true ;
V_2 -> V_199 = true ;
V_2 -> V_200 = true ;
V_2 -> V_201 = false ;
break;
case 0x23 :
V_2 -> V_102 = false ;
V_2 -> V_106 = false ;
V_2 -> V_105 = true ;
V_2 -> V_107 = true ;
V_2 -> V_103 = true ;
V_2 -> V_104 = true ;
V_2 -> V_198 = true ;
V_2 -> V_199 = true ;
V_2 -> V_200 = true ;
V_2 -> V_201 = false ;
break;
case 0x25 :
V_2 -> V_102 = false ;
V_2 -> V_106 = false ;
V_2 -> V_105 = true ;
V_2 -> V_107 = true ;
V_2 -> V_103 = true ;
V_2 -> V_104 = true ;
V_2 -> V_198 = true ;
V_2 -> V_199 = true ;
V_2 -> V_200 = true ;
V_2 -> V_201 = false ;
break;
case 0x26 :
V_2 -> V_102 = false ;
V_2 -> V_106 = false ;
V_2 -> V_105 = true ;
V_2 -> V_107 = false ;
V_2 -> V_103 = true ;
V_2 -> V_104 = true ;
V_2 -> V_198 = true ;
V_2 -> V_199 = true ;
V_2 -> V_200 = true ;
V_2 -> V_201 = false ;
break;
default:
F_19 ( L_21 ,
( ( V_187 >> 12 ) & 0xFF ) ) ;
V_28 = - V_191 ;
goto V_197;
}
F_36 ( L_22 ,
( ( V_187 >> 12 ) & 0xFF ) , V_188 ,
V_2 -> V_108 / 1000 ,
V_2 -> V_108 % 1000 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
V_197:
return V_28 ;
}
static int F_37 ( struct V_1 * V_2 , T_4 V_202 , T_4 * V_203 )
{
int V_28 ;
bool V_204 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_205 , V_202 ) ;
if ( V_28 < 0 )
goto error;
if ( V_202 == V_206 )
F_32 ( 1000 , 2000 ) ;
V_204 =
( bool ) ( ( V_202 == V_207 ) &&
( ( V_2 -> V_116 ) &
V_208 ) ==
V_209 ) ;
if ( ! V_204 ) {
T_1 V_49 = 0 ;
T_4 V_210 ;
do {
F_32 ( 1000 , 2000 ) ;
V_49 += 1 ;
V_28 = F_23 ( V_2 , V_205 ,
& V_210 ) ;
} while ( ( V_28 < 0 ) && ( V_49 < V_211 )
&& ( V_210 != 0 ) );
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_212 , V_203 ) ;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_28 ;
F_17 ( 1 , L_3 ) ;
F_39 ( & V_2 -> V_213 ) ;
V_28 = F_27 ( V_2 , V_214 ,
V_2 -> V_215 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_216 ,
V_2 -> V_116 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_217 ,
V_2 -> V_115 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_218 ,
V_2 -> V_219 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_220 ,
V_2 -> V_112 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_221 ,
V_222 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_37 ( V_2 , V_207 , NULL ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_116 &= ~ V_209 ;
error:
F_40 ( & V_2 -> V_213 ) ;
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_41 ( struct V_1 * V_2 )
{
F_17 ( 1 , L_3 ) ;
V_2 -> V_115 = ( V_2 -> V_35 << 1 ) ;
V_2 -> V_215 = 0x96FF ;
V_2 -> V_116 = V_117 ;
return F_38 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 , bool V_223 )
{
int V_28 = - 1 ;
T_4 V_224 = 0 ;
T_4 V_225 = 0 ;
T_4 V_226 = 0 ;
F_17 ( 1 , L_23 ,
V_223 ? L_24 : L_25 ,
V_2 -> V_227 ? L_26 : L_27 ) ;
V_28 = F_27 ( V_2 , V_180 ,
V_181 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_182 , V_183 ) ;
if ( V_28 < 0 )
goto error;
if ( ! V_223 ) {
V_28 = F_27 ( V_2 , V_228 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_229 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_230 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_231 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_232 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_233 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_234 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_235 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_236 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_237 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_238 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_239 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
} else {
V_225 =
( ( V_2 -> V_159 <<
V_240 ) | 0x0003 ) ;
V_224 = ( ( V_2 -> V_241 <<
V_242 ) |
0x0003 ) ;
V_28 = F_27 ( V_2 , V_228 , V_225 ) ;
if ( V_28 < 0 )
goto error;
if ( V_2 -> V_243 )
V_226 = V_225 ;
V_28 = F_27 ( V_2 , V_229 , V_226 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_231 , V_226 ) ;
if ( V_28 < 0 )
goto error;
if ( V_2 -> V_227 ) {
V_28 = F_27 ( V_2 , V_233 ,
V_225 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_234 ,
V_225 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_235 ,
V_225 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_236 ,
V_225 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_237 ,
V_225 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_238 ,
V_225 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_239 ,
V_225 ) ;
if ( V_28 < 0 )
goto error;
} else {
V_225 = ( ( V_2 -> V_159 <<
V_240 )
| 0x0003 ) ;
V_28 = F_27 ( V_2 , V_233 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_234 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_235 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_236 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_237 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_238 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_239 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_27 ( V_2 , V_230 , V_224 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_232 , V_225 ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_27 ( V_2 , V_244 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_182 , 0x0000 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_43 ( struct V_1 * V_2 )
{
F_17 ( 1 , L_3 ) ;
return F_42 ( V_2 , false ) ;
}
static int F_44 ( struct V_1 * V_2 ,
T_4 V_245 , T_4 V_246 , T_1 V_247 )
{
T_4 V_248 = 0 ;
int V_28 ;
unsigned long V_249 ;
F_17 ( 1 , L_3 ) ;
F_39 ( & V_2 -> V_213 ) ;
V_28 = F_27 ( V_2 , V_250 , V_251 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_252 , V_245 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_253 , V_246 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_254 , V_255 ) ;
if ( V_28 < 0 )
goto error;
V_249 = V_256 + F_45 ( V_247 ) ;
do {
F_32 ( 1000 , 2000 ) ;
V_28 = F_23 ( V_2 , V_257 , & V_248 ) ;
if ( V_28 < 0 )
goto error;
} while ( ( V_248 == 0x1 ) &&
( ( F_46 ( V_249 ) ) ) );
if ( V_248 == 0x1 ) {
F_19 ( L_28 ) ;
V_28 = - V_191 ;
goto V_197;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
V_197:
F_40 ( & V_2 -> V_213 ) ;
return V_28 ;
}
static int F_47 ( struct V_1 * V_2 ,
const T_3 V_258 [] , T_1 V_259 )
{
const T_3 * V_260 = V_258 ;
T_1 V_40 ;
T_4 V_261 ;
T_4 V_41 ;
T_1 V_262 = 0 ;
T_1 V_12 ;
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
#if 0
drain = (p_src[0] << 8) | p_src[1];
#endif
V_260 += sizeof( T_4 ) ;
V_262 += sizeof( T_4 ) ;
V_261 = ( V_260 [ 0 ] << 8 ) | V_260 [ 1 ] ;
V_260 += sizeof( T_4 ) ;
V_262 += sizeof( T_4 ) ;
for ( V_12 = 0 ; V_12 < V_261 ; V_12 += 1 ) {
V_40 = ( V_260 [ 0 ] << 24 ) | ( V_260 [ 1 ] << 16 ) |
( V_260 [ 2 ] << 8 ) | V_260 [ 3 ] ;
V_260 += sizeof( T_1 ) ;
V_262 += sizeof( T_1 ) ;
V_41 = ( ( V_260 [ 0 ] << 8 ) | V_260 [ 1 ] ) * sizeof( T_4 ) ;
V_260 += sizeof( T_4 ) ;
V_262 += sizeof( T_4 ) ;
#if 0
flags = (p_src[0] << 8) | p_src[1];
#endif
V_260 += sizeof( T_4 ) ;
V_262 += sizeof( T_4 ) ;
#if 0
block_crc = (p_src[0] << 8) | p_src[1];
#endif
V_260 += sizeof( T_4 ) ;
V_262 += sizeof( T_4 ) ;
if ( V_262 + V_41 > V_259 ) {
F_19 ( L_29 ) ;
return - V_191 ;
}
V_28 = F_30 ( V_2 , V_40 , V_41 , V_260 ) ;
if ( V_28 < 0 ) {
F_19 ( L_30 , V_28 ) ;
break;
}
V_260 += V_41 ;
V_262 += V_41 ;
}
return V_28 ;
}
static int F_48 ( struct V_1 * V_2 , bool V_263 )
{
int V_28 ;
T_4 V_27 = 0 ;
T_4 V_264 = V_265 ;
T_4 V_266 = V_267 ;
unsigned long V_249 ;
F_17 ( 1 , L_3 ) ;
if ( ! V_263 ) {
V_264 = V_268 ;
V_266 = V_269 ;
}
V_28 = F_23 ( V_2 , V_270 , & V_27 ) ;
if ( V_28 >= 0 && V_27 == V_266 ) {
return V_28 ;
}
V_28 = F_27 ( V_2 , V_271 , V_264 ) ;
V_249 = V_256 + F_45 ( V_272 ) ;
do {
V_28 = F_23 ( V_2 , V_270 , & V_27 ) ;
if ( ( V_28 >= 0 && V_27 == V_266 )
|| F_46 ( V_249 ) )
break;
F_32 ( 1000 , 2000 ) ;
} while ( 1 );
if ( V_27 != V_266 ) {
F_19 ( L_28 ) ;
return - V_191 ;
}
return V_28 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
T_4 V_273 = 0 ;
T_4 V_274 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_275 , & V_273 ) ;
if ( V_28 < 0 )
goto error;
V_273 |= V_276 ;
V_28 = F_27 ( V_2 , V_275 , V_273 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_277 , & V_274 ) ;
if ( V_28 < 0 )
goto error;
V_274 |= V_278 ;
V_28 = F_27 ( V_2 , V_277 , V_274 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_50 ( struct V_1 * V_2 ,
T_4 V_202 , T_3 V_279 ,
T_4 * V_280 , T_3 V_281 , T_4 * V_282 )
{
#if ( V_283 - V_284 ) != 15
#error DRXK register mapping no longer compatible with this routine!
#endif
T_4 V_285 = 0 ;
int V_28 = - V_191 ;
unsigned long V_249 ;
T_3 V_286 [ 34 ] ;
int V_287 = 0 , V_288 ;
const char * V_289 ;
char V_290 [ 30 ] ;
F_17 ( 1 , L_3 ) ;
if ( ( V_202 == 0 ) || ( ( V_279 > 0 ) && ( V_280 == NULL ) ) ||
( ( V_281 > 0 ) && ( V_282 == NULL ) ) ) {
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
F_39 ( & V_2 -> V_213 ) ;
for ( V_288 = V_279 - 1 ; V_288 >= 0 ; V_288 -= 1 ) {
V_286 [ V_287 ++ ] = ( V_280 [ V_288 ] & 0xFF ) ;
V_286 [ V_287 ++ ] = ( ( V_280 [ V_288 ] >> 8 ) & 0xFF ) ;
}
V_286 [ V_287 ++ ] = ( V_202 & 0xFF ) ;
V_286 [ V_287 ++ ] = ( ( V_202 >> 8 ) & 0xFF ) ;
F_30 ( V_2 , V_283 -
( V_279 - 1 ) , V_287 , V_286 ) ;
V_249 = V_256 + F_45 ( V_291 ) ;
do {
F_32 ( 1000 , 2000 ) ;
V_28 = F_23 ( V_2 , V_292 , & V_285 ) ;
if ( V_28 < 0 )
goto error;
} while ( ! ( V_285 == V_293 ) && ( F_46 ( V_249 ) ) );
if ( V_285 != V_293 ) {
F_19 ( L_31 ) ;
V_28 = - V_31 ;
goto V_197;
}
if ( ( V_281 > 0 ) && ( V_282 != NULL ) ) {
T_5 V_294 ;
int V_288 ;
for ( V_288 = V_281 - 1 ; V_288 >= 0 ; V_288 -= 1 ) {
V_28 = F_23 ( V_2 , V_283 - V_288 ,
& V_282 [ V_288 ] ) ;
if ( V_28 < 0 )
goto error;
}
V_294 = ( T_5 ) V_282 [ 0 ] ;
if ( V_294 >= 0 )
goto error;
switch ( V_294 ) {
case V_295 :
V_289 = L_32 ;
break;
case V_296 :
V_289 = L_33 ;
break;
case V_297 :
V_289 = L_34 ;
break;
case V_298 :
V_289 = L_35 ;
break;
default:
sprintf ( V_290 , L_36 , V_294 ) ;
V_289 = V_290 ;
}
F_19 ( L_37 , V_289 , V_202 ) ;
F_51 ( L_38 , V_299 , V_286 , V_287 ) ;
V_28 = - V_191 ;
goto V_197;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
V_197:
F_40 ( & V_2 -> V_213 ) ;
return V_28 ;
}
static int F_52 ( struct V_1 * V_2 , bool V_300 )
{
T_4 V_27 = 0 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_301 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
if ( ! V_300 ) {
V_27 |= ( V_302
| V_303
| V_304
| V_305
| V_306 ) ;
} else {
V_27 &= ( ( ~ V_302 )
& ( ~ V_303 )
& ( ~ V_304 )
& ( ~ V_305 )
& ( ~ V_306 )
) ;
}
V_28 = F_27 ( V_2 , V_301 , V_27 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_53 ( struct V_1 * V_2 , enum V_307 * V_308 )
{
int V_28 = 0 ;
T_4 V_309 = 0 ;
F_17 ( 1 , L_3 ) ;
if ( V_308 == NULL )
return - V_191 ;
switch ( * V_308 ) {
case V_57 :
V_309 = V_52 ;
break;
case V_310 :
V_309 = V_311 ;
break;
case V_312 :
V_309 = V_313 ;
break;
case V_314 :
V_309 = V_315 ;
break;
case V_174 :
V_309 = V_316 ;
break;
default:
return - V_191 ;
}
if ( V_2 -> V_56 == * V_308 )
return 0 ;
if ( V_2 -> V_56 != V_57 ) {
V_28 = F_31 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_48 ( V_2 , true ) ;
if ( V_28 < 0 )
goto error;
}
if ( * V_308 == V_57 ) {
} else {
switch ( V_2 -> V_3 ) {
case V_4 :
V_28 = F_49 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_54 ( V_2 , false ) ;
if ( V_28 < 0 )
goto error;
break;
case V_5 :
case V_7 :
V_28 = F_49 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_55 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
break;
default:
break;
}
V_28 = F_48 ( V_2 , false ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_51 , V_309 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_53 , V_54 ) ;
if ( V_28 < 0 )
goto error;
if ( * V_308 != V_310 ) {
V_2 -> V_116 |=
V_209 ;
V_28 = F_38 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
}
}
V_2 -> V_56 = * V_308 ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_54 ( struct V_1 * V_2 , bool V_317 )
{
enum V_307 V_318 = V_310 ;
T_4 V_319 = 0 ;
T_4 V_27 = 0 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_320 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
if ( V_27 == V_321 ) {
V_28 = F_50 ( V_2 ,
V_322
| V_323 ,
0 , NULL , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_50 ( V_2 ,
V_322
| V_324 ,
0 , NULL , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_27 ( V_2 , V_325 , V_326 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_327 , V_328 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_329 , V_330 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_52 ( V_2 , false ) ;
if ( V_28 < 0 )
goto error;
if ( V_317 ) {
V_28 = F_53 ( V_2 , & V_318 ) ;
if ( V_28 < 0 )
goto error;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_56 ( struct V_1 * V_2 ,
enum V_331 V_332 )
{
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_180 ,
V_181 ) ;
if ( V_28 < 0 )
goto error;
if ( V_2 -> V_3 == V_332 )
return 0 ;
switch ( V_2 -> V_3 ) {
case V_147 :
break;
case V_4 :
V_28 = F_49 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_54 ( V_2 , true ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_3 = V_147 ;
break;
case V_5 :
case V_7 :
V_28 = F_49 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_55 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_3 = V_147 ;
break;
case V_6 :
default:
V_28 = - V_191 ;
goto error;
}
switch ( V_332 ) {
case V_4 :
F_17 ( 1 , L_39 ) ;
V_2 -> V_3 = V_332 ;
V_28 = F_57 ( V_2 , V_332 ) ;
if ( V_28 < 0 )
goto error;
break;
case V_5 :
case V_7 :
F_17 ( 1 , L_40 ,
( V_2 -> V_3 == V_5 ) ? 'A' : 'C' ) ;
V_2 -> V_3 = V_332 ;
V_28 = F_58 ( V_2 , V_332 ) ;
if ( V_28 < 0 )
goto error;
break;
case V_6 :
default:
V_28 = - V_191 ;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_59 ( struct V_1 * V_2 , T_6 V_333 ,
T_6 V_334 )
{
int V_28 = - V_191 ;
T_4 V_335 ;
T_6 V_336 = V_333 / 1000 ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_148 != V_337 &&
V_2 -> V_148 != V_338 )
goto error;
V_2 -> V_339 = ( V_2 -> V_340 . V_341 == V_342 ) ;
if ( V_334 < 0 ) {
V_2 -> V_339 = ! V_2 -> V_339 ;
V_334 = - V_334 ;
}
switch ( V_2 -> V_3 ) {
case V_5 :
case V_7 :
V_335 = ( V_334 / 1000 ) ;
V_28 = F_60 ( V_2 , V_335 , V_336 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_148 = V_338 ;
break;
case V_4 :
V_335 = ( V_334 / 1000 ) ;
V_28 = F_49 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_61 ( V_2 , V_335 , V_336 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_62 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_148 = V_338 ;
break;
default:
break;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_63 ( struct V_1 * V_2 )
{
F_17 ( 1 , L_3 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , T_1 * V_343 )
{
int V_28 = - V_191 ;
F_17 ( 1 , L_3 ) ;
if ( V_343 == NULL )
goto error;
* V_343 = V_344 ;
switch ( V_2 -> V_3 ) {
case V_5 :
case V_6 :
case V_7 :
V_28 = F_65 ( V_2 , V_343 ) ;
break;
case V_4 :
V_28 = F_66 ( V_2 , V_343 ) ;
break;
default:
break;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_28 ;
T_4 V_273 = 0 ;
V_28 = F_23 ( V_2 , V_275 , & V_273 ) ;
if ( V_28 < 0 )
goto error;
V_273 &= ~ V_276 ;
V_28 = F_27 ( V_2 , V_275 , V_273 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_345 , 1 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_346 , 0x0000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_347 , 0x000C ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_348 , 0x000A ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_349 , 0x0008 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_350 , 0x0006 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_351 , 0x0680 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_352 , 0x0080 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_353 , 0x03F4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_354 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_355 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_356 , 12 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_69 ( struct V_1 * V_2 ,
enum V_331 V_332 )
{
int V_28 ;
T_4 V_357 = 0 ;
T_4 V_358 = 0 ;
T_4 V_359 = 0 ;
T_4 V_360 = 0 ;
T_4 V_361 = 2 ;
T_4 V_362 = 188 ;
T_1 V_363 = 0 ;
T_4 V_364 = 0 ;
T_4 V_365 = 0 ;
T_1 V_366 = 0 ;
bool V_367 = false ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_368 , & V_357 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_277 , & V_358 ) ;
if ( V_28 < 0 )
goto error;
V_357 &= ( ~ V_369 ) ;
V_358 &= ( ~ V_370 ) ;
if ( V_2 -> V_151 ) {
V_357 |= V_369 ;
V_358 |= V_370 ;
V_362 = 204 ;
}
V_358 &= ( ~ ( V_371 ) ) ;
if ( ! V_2 -> V_227 ) {
V_358 |= V_371 ;
}
switch ( V_332 ) {
case V_4 :
V_366 = V_2 -> V_157 ;
V_364 = 3 ;
V_363 = 0xC00000 ;
V_367 = V_2 -> V_372 ;
break;
case V_5 :
case V_7 :
V_364 = 0x0004 ;
V_363 = 0xD2B4EE ;
V_366 = V_2 -> V_158 ;
V_367 = V_2 -> V_373 ;
break;
default:
V_28 = - V_191 ;
}
if ( V_28 < 0 )
goto error;
if ( V_367 ) {
T_1 V_374 = 0 ;
V_359 = ( V_375 |
V_376 ) ;
V_360 = ( V_377 |
V_378 ) ;
V_374 = V_366 ;
if ( V_374 > 75900000UL ) {
V_374 = 75900000UL ;
}
V_361 = ( T_4 ) ( ( ( V_2 -> V_111 )
* 1000 ) / V_374 ) ;
if ( V_361 <= 2 )
V_361 = 0 ;
else
V_361 -= 2 ;
V_365 = 8 ;
} else {
V_359 = V_375 ;
V_360 = V_379 ;
V_365 = 5 ;
}
V_28 = F_27 ( V_2 , V_380 , V_362 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_381 , V_361 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_382 , V_359 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_383 , V_360 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_368 , V_357 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_277 , V_358 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_29 ( V_2 , V_384 , V_363 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_385 ,
V_365 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_386 , V_364 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_70 ( struct V_1 * V_2 )
{
T_4 V_387 = 0 ;
T_4 V_388 =
V_389 | V_390 |
V_391 | V_392 |
V_393 | V_394 |
V_395 | V_396 ;
F_17 ( 1 , L_3 ) ;
V_387 &= ( ~ ( V_388 ) ) ;
if ( V_2 -> V_152 )
V_387 |= V_388 ;
V_387 &= ( ~ ( V_397 ) ) ;
if ( V_2 -> V_153 )
V_387 |= V_397 ;
V_387 &= ( ~ ( V_398 ) ) ;
if ( V_2 -> V_154 )
V_387 |= V_398 ;
V_387 &= ( ~ ( V_399 ) ) ;
if ( V_2 -> V_155 )
V_387 |= V_399 ;
V_387 &= ( ~ ( V_400 ) ) ;
if ( V_2 -> V_156 )
V_387 |= V_400 ;
return F_27 ( V_2 , V_401 , V_387 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_402 * V_403 , bool V_404 )
{
int V_28 = - V_191 ;
T_4 V_27 = 0 ;
struct V_402 * V_405 ;
F_17 ( 1 , L_3 ) ;
if ( V_403 == NULL )
goto error;
switch ( V_403 -> V_121 ) {
case V_59 :
V_28 = F_23 ( V_2 , V_301 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 &= ~ V_306 ;
V_28 = F_27 ( V_2 , V_301 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_406 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 &= ~ V_407 ;
if ( V_2 -> V_408 )
V_27 |= V_409 ;
else
V_27 &= ~ V_409 ;
V_28 = F_27 ( V_2 , V_406 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_410 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 &= ~ V_411 ;
V_27 |= ( ~ ( V_403 -> V_125 <<
V_412 )
& V_411 ) ;
V_28 = F_27 ( V_2 , V_410 , V_27 ) ;
if ( V_28 < 0 )
goto error;
if ( F_1 ( V_2 ) )
V_405 = & V_2 -> V_139 ;
else if ( F_2 ( V_2 ) )
V_405 = & V_2 -> V_144 ;
else
V_405 = & V_2 -> V_135 ;
if ( V_405 == NULL ) {
V_28 = - V_191 ;
goto error;
}
if ( V_405 -> V_121 == V_59 ) {
V_28 = F_27 ( V_2 ,
V_413 ,
V_403 -> V_128 ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_27 ( V_2 , V_414 ,
V_403 -> V_129 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_415 ,
V_403 -> V_124 ) ;
if ( V_28 < 0 )
goto error;
break;
case V_416 :
V_28 = F_23 ( V_2 , V_301 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 &= ~ V_306 ;
V_28 = F_27 ( V_2 , V_301 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_406 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 |= V_407 ;
if ( V_2 -> V_408 )
V_27 |= V_409 ;
else
V_27 &= ~ V_409 ;
V_28 = F_27 ( V_2 , V_406 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_414 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_417 ,
V_403 -> V_122 ) ;
if ( V_28 < 0 )
goto error;
break;
case V_77 :
V_28 = F_23 ( V_2 , V_301 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 |= V_306 ;
V_28 = F_27 ( V_2 , V_301 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_406 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 |= V_407 ;
V_28 = F_27 ( V_2 , V_406 , V_27 ) ;
if ( V_28 < 0 )
goto error;
break;
default:
V_28 = - V_191 ;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_402 * V_403 , bool V_404 )
{
T_4 V_27 = 0 ;
int V_28 = 0 ;
struct V_402 * V_418 ;
F_17 ( 1 , L_3 ) ;
switch ( V_403 -> V_121 ) {
case V_59 :
V_28 = F_23 ( V_2 , V_301 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 &= ~ V_305 ;
V_28 = F_27 ( V_2 , V_301 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_406 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 &= ~ V_419 ;
if ( V_2 -> V_176 )
V_27 |= V_420 ;
else
V_27 &= ~ V_420 ;
V_28 = F_27 ( V_2 , V_406 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_410 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 &= ~ V_421 ;
V_27 |= ( ~ ( V_403 -> V_125 <<
V_422 )
& V_421 ) ;
V_28 = F_27 ( V_2 , V_410 , V_27 ) ;
if ( V_28 < 0 )
goto error;
if ( F_2 ( V_2 ) )
V_418 = & V_2 -> V_143 ;
else
V_418 = & V_2 -> V_136 ;
if ( V_418 == NULL )
return - 1 ;
V_28 = F_27 ( V_2 , V_413 ,
V_418 -> V_128 ) ;
if ( V_28 < 0 )
goto error;
break;
case V_416 :
V_28 = F_23 ( V_2 , V_301 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 &= ~ V_305 ;
V_28 = F_27 ( V_2 , V_301 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_406 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 |= V_419 ;
if ( V_2 -> V_176 )
V_27 |= V_420 ;
else
V_27 &= ~ V_420 ;
V_28 = F_27 ( V_2 , V_406 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_413 ,
V_403 -> V_122 ) ;
if ( V_28 < 0 )
goto error;
break;
case V_77 :
V_28 = F_23 ( V_2 , V_301 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 |= V_305 ;
V_28 = F_27 ( V_2 , V_301 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_406 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 |= V_419 ;
V_28 = F_27 ( V_2 , V_406 , V_27 ) ;
if ( V_28 < 0 )
goto error;
break;
}
V_28 = F_27 ( V_2 , V_423 , V_403 -> V_128 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_73 ( struct V_1 * V_2 ,
T_6 * V_424 )
{
int V_28 = 0 ;
T_4 V_425 = 0 ;
T_1 V_426 = 0 ;
T_1 V_427 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_428 , & V_425 ) ;
if ( V_28 < 0 ) {
F_19 ( L_13 , V_28 , V_48 ) ;
return - V_191 ;
}
switch ( V_2 -> V_340 . V_429 ) {
case V_430 :
V_426 = V_431 << 2 ;
break;
case V_432 :
V_426 = V_433 << 2 ;
break;
case V_434 :
V_426 = V_435 << 2 ;
break;
case V_436 :
V_426 = V_437 << 2 ;
break;
default:
case V_438 :
V_426 = V_439 << 2 ;
break;
}
if ( V_425 > 0 ) {
V_427 = F_6 ( V_426 ) -
F_6 ( ( T_1 ) V_425 ) ;
}
* V_424 = V_427 ;
return V_28 ;
}
static int F_74 ( struct V_1 * V_2 ,
T_6 * V_424 )
{
int V_28 ;
T_4 V_440 = 0 ;
T_1 V_441 = 0 ;
T_1 V_442 = 0 ;
T_4 V_443 = 0 ;
T_4 V_444 = 0 ;
T_4 V_445 = 0 ;
T_1 V_446 = 0 ;
T_1 V_447 = 0 ;
T_1 V_8 = 0 ;
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
T_1 V_448 = 0 ;
T_4 V_449 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_450 ,
& V_444 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_451 ,
& V_445 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_452 ,
& V_443 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_453 ,
& V_440 ) ;
if ( V_28 < 0 )
goto error;
V_441 = ( T_1 ) V_440 ;
if ( ( V_443 > 11 ) &&
( V_441 < 0x00000FFFUL ) ) {
V_441 += 0x00010000UL ;
}
V_28 = F_23 ( V_2 , V_454 , & V_440 ) ;
if ( V_28 < 0 )
goto error;
V_442 = ( T_1 ) V_440 ;
if ( ( V_443 > 11 ) &&
( V_442 < 0x00000FFFUL ) )
V_442 += 0x00010000UL ;
V_28 = F_23 ( V_2 , V_455 ,
& V_449 ) ;
if ( V_28 < 0 )
goto error;
if ( ( V_444 == 0 ) || ( V_445 == 0 ) )
V_448 = 0 ;
else if ( ( V_441 + V_442 ) == 0 ) {
V_448 = 0 ;
} else {
V_447 = ( V_441 + V_442 ) <<
V_443 ;
if ( ( V_449 &
V_456 )
== V_457 )
V_446 = 17 ;
else
V_446 = 68 ;
V_8 = F_6 ( V_444 *
V_444 ) ;
V_9 = F_6 ( V_445 * V_446 ) ;
V_10 = F_6 ( V_447 ) ;
V_448 = V_8 + V_9 - V_10 ;
}
* V_424 = V_448 ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_75 ( struct V_1 * V_2 , T_6 * V_424 )
{
F_17 ( 1 , L_3 ) ;
* V_424 = 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
return F_74 ( V_2 , V_424 ) ;
case V_5 :
case V_7 :
return F_73 ( V_2 , V_424 ) ;
default:
break;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , bool V_458 )
{
int V_28 = - V_191 ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_148 == V_149 )
return 0 ;
if ( V_2 -> V_148 == V_459 )
goto error;
if ( V_2 -> V_460 )
return 0 ;
V_28 = F_27 ( V_2 , V_221 ,
V_222 ) ;
if ( V_28 < 0 )
goto error;
if ( V_458 ) {
V_28 = F_27 ( V_2 , V_220 ,
V_461 ) ;
if ( V_28 < 0 )
goto error;
} else {
V_28 = F_27 ( V_2 , V_220 ,
V_462 ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_37 ( V_2 , V_463 , NULL ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_464 * V_465 )
{
int V_28 = - V_191 ;
F_17 ( 1 , L_3 ) ;
if ( ( V_465 == NULL )
|| ( V_465 -> V_131 > V_466 ) )
goto error;
V_28 = F_27 ( V_2 , V_467 , V_465 -> V_131 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_78 ( struct V_1 * V_2 , T_1 V_468 ,
T_4 V_245 , T_4 V_246 , T_1 V_247 )
{
T_4 V_248 = 0 ;
T_4 V_262 = ( T_4 ) ( ( V_468 >> 0 ) & 0x00FFFF ) ;
T_4 V_469 = ( T_4 ) ( ( V_468 >> 16 ) & 0x000FFF ) ;
int V_28 ;
unsigned long V_249 ;
F_17 ( 1 , L_3 ) ;
F_39 ( & V_2 -> V_213 ) ;
V_28 = F_27 ( V_2 , V_250 , V_470 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_471 , V_469 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_472 , V_262 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_473 , V_245 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_474 , V_246 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_254 , V_255 ) ;
if ( V_28 < 0 )
goto error;
V_249 = V_256 + F_45 ( V_247 ) ;
do {
V_28 = F_23 ( V_2 , V_257 , & V_248 ) ;
if ( V_28 < 0 )
goto error;
} while ( ( V_248 == 0x1 ) && F_46 ( V_249 ) );
if ( V_248 == 0x1 ) {
F_19 ( L_28 ) ;
V_28 = - V_191 ;
goto V_197;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
V_197:
F_40 ( & V_2 -> V_213 ) ;
return V_28 ;
}
static int F_79 ( struct V_1 * V_2 , T_4 * V_475 )
{
T_4 V_27 = 0 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_476 , V_477 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_478 , 1 ) ;
if ( V_28 < 0 )
goto error;
* V_475 = 0 ;
V_28 = F_23 ( V_2 , V_479 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
if ( V_27 == 127 )
* V_475 = * V_475 + 1 ;
V_28 = F_23 ( V_2 , V_480 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
if ( V_27 == 127 )
* V_475 = * V_475 + 1 ;
V_28 = F_23 ( V_2 , V_481 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
if ( V_27 == 127 )
* V_475 = * V_475 + 1 ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_80 ( struct V_1 * V_2 )
{
T_4 V_475 = 0 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_79 ( V_2 , & V_475 ) ;
if ( V_28 < 0 )
goto error;
if ( V_475 == 1 ) {
T_4 V_482 = 0 ;
V_28 = F_23 ( V_2 , V_483 , & V_482 ) ;
if ( V_28 < 0 )
goto error;
if ( ( V_482 & V_484 ) ==
V_485 ) {
V_482 &= ( ~ ( V_484 ) ) ;
V_482 |=
V_486 ;
} else {
V_482 &= ( ~ ( V_484 ) ) ;
V_482 |=
V_485 ;
}
V_28 = F_27 ( V_2 , V_483 , V_482 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_79 ( V_2 , & V_475 ) ;
if ( V_28 < 0 )
goto error;
}
if ( V_475 < 2 )
V_28 = - V_191 ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_4 V_487 ,
T_6 V_488 , bool V_404 )
{
bool V_489 = false ;
T_1 V_490 = V_488 ;
T_1 V_491 = 0 ;
bool V_492 = ! V_2 -> V_339 ;
T_1 V_493 ;
bool V_494 ;
int V_28 ;
T_1 V_495 ;
T_1 V_496 = ( T_1 ) ( V_2 -> V_111 / 3 ) ;
T_1 V_497 ;
bool V_498 ;
F_17 ( 1 , L_3 ) ;
if ( V_404 ) {
if ( ( V_2 -> V_3 == V_5 ) ||
( V_2 -> V_3 == V_7 ) ||
( V_2 -> V_3 == V_4 ) )
V_489 = true ;
else
V_489 = false ;
}
if ( V_492 )
V_495 = V_487 +
V_490 + V_491 ;
else
V_495 = V_487 -
V_490 - V_491 ;
if ( V_495 > V_496 / 2 ) {
V_493 = V_496 - V_495 ;
V_494 = true ;
} else {
V_493 = V_495 ;
V_494 = false ;
}
V_497 = V_493 ;
V_498 = V_2 -> V_175 ^ V_492 ^
V_494 ^ V_489 ;
V_2 -> V_499 =
F_5 ( ( V_497 ) , V_496 ) ;
if ( V_498 )
V_2 -> V_499 = ~ V_2 -> V_499 + 1 ;
V_28 = F_29 ( V_2 , V_500 ,
V_2 -> V_499 ) ;
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_82 ( struct V_1 * V_2 , bool V_404 )
{
T_4 V_501 = 0 ;
T_4 V_502 = 0 ;
T_4 V_141 = 0 ;
T_4 V_503 = 0 ;
T_4 V_504 = 0 ;
T_4 V_505 = 0 ;
T_4 V_506 = 0 ;
T_4 V_507 = 0 ;
T_4 V_508 = 0 ;
T_4 V_509 = 0 ;
T_4 V_510 = 0 ;
T_4 V_511 = 0 ;
T_4 V_512 = 0 ;
T_4 V_513 = 0 ;
T_4 V_27 = 0 ;
T_4 V_514 = 0 ;
T_4 V_515 = 0 ;
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_507 = 1023 ;
V_512 = 2047 ;
V_503 = 500 ;
V_508 = 1023 ;
if ( ! F_2 ( V_2 ) ) {
F_19 ( L_41 ,
V_48 , V_2 -> V_3 ) ;
return - V_191 ;
}
V_504 = 8 ;
V_505 = ( T_4 ) - 9 ;
V_515 = 0 ;
V_506 = 8 ;
V_509 = ( T_4 ) - 9 ;
V_510 = ( T_4 ) - 1030 ;
V_513 = 0x2380 ;
V_511 = 0x2380 ;
V_502 = 0x0511 ;
V_501 = 0x0511 ;
V_141 = 5119 ;
V_514 = V_2 -> V_144 . V_140 ;
V_28 = F_27 ( V_2 , V_516 ,
V_514 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_517 , V_515 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_518 , V_501 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_423 , V_502 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_519 , V_141 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_520 ,
V_512 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_413 ,
V_513 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_521 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_522 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_417 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_523 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_524 , V_508 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_525 , V_507 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_526 ,
V_510 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_527 ,
V_511 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_528 , V_503 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_529 , 1023 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_530 , ( T_4 ) - 1023 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_531 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_532 , 20 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_533 , V_504 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_534 , V_506 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_535 , V_505 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_536 , V_509 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_537 , 0x7fff ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_538 , 0x0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_539 , 0x0117 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_540 , 0x0657 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_541 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_542 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_543 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_544 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_545 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_546 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_547 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_548 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_549 , 500 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_550 , 500 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_551 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 = 0x0657 ;
V_27 &= ~ V_552 ;
V_27 |= ( V_553 << V_554 ) ;
V_27 &= ~ V_555 ;
V_27 |= ( V_556 << V_557 ) ;
V_28 = F_27 ( V_2 , V_551 , V_27 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_83 ( struct V_1 * V_2 , T_4 * V_558 )
{
int V_28 ;
F_17 ( 1 , L_3 ) ;
if ( V_558 == NULL )
V_28 = F_27 ( V_2 , V_559 , 0 ) ;
else
V_28 = F_23 ( V_2 , V_559 ,
V_558 ) ;
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_84 ( struct V_1 * V_2 ,
T_4 V_202 , T_4 V_560 ,
T_4 V_561 , T_4 V_562 , T_4 V_563 ,
T_4 V_564 , T_4 V_565 )
{
T_4 V_285 = 0 ;
T_4 V_566 = 0 ;
T_4 V_567 = 0 ;
T_4 V_568 = 0 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_325 , & V_568 ) ;
if ( V_568 != 1 ) {
V_28 = - V_191 ;
}
if ( V_28 < 0 )
goto error;
V_567 = 0 ;
do {
F_32 ( 1000 , 2000 ) ;
V_28 = F_23 ( V_2 , V_569 , & V_285 ) ;
V_567 ++ ;
} while ( ( V_285 != 0 ) && ( V_567 < V_211 ) );
if ( V_567 >= V_211 && ( V_28 < 0 ) )
goto error;
switch ( V_202 ) {
case V_570 :
case V_571 :
case V_572 :
V_28 = F_27 ( V_2 , V_573 , V_560 ) ;
if ( V_28 < 0 )
goto error;
break;
default:
break;
}
switch ( V_202 ) {
case V_570 :
case V_571 :
case V_572 :
V_28 = F_27 ( V_2 , V_574 , V_562 ) ;
case V_575 :
case V_576 :
V_28 = F_27 ( V_2 , V_577 , V_561 ) ;
case V_578 :
case V_579 :
V_28 = F_27 ( V_2 , V_569 , V_202 ) ;
break;
default:
V_28 = - V_191 ;
}
if ( V_28 < 0 )
goto error;
V_567 = 0 ;
do {
F_32 ( 1000 , 2000 ) ;
V_28 = F_23 ( V_2 , V_569 , & V_285 ) ;
V_567 ++ ;
} while ( ( V_285 != 0 ) && ( V_567 < V_211 ) );
if ( V_567 >= V_211 && ( V_28 < 0 ) )
goto error;
V_28 = F_23 ( V_2 , V_573 , & V_566 ) ;
if ( V_566 == 0xFFFF ) {
V_28 = - V_191 ;
}
if ( V_28 < 0 )
goto error;
switch ( V_202 ) {
case V_576 :
case V_578 :
V_28 = F_23 ( V_2 , V_577 , & ( V_561 ) ) ;
case V_575 :
case V_580 :
case V_570 :
case V_571 :
case V_572 :
case V_579 :
break;
default:
V_28 = - V_191 ;
break;
}
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_85 ( struct V_1 * V_2 )
{
enum V_307 V_318 = V_57 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_53 ( V_2 , & V_318 ) ;
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_86 ( struct V_1 * V_2 , bool * V_581 )
{
int V_28 ;
F_17 ( 1 , L_3 ) ;
if ( * V_581 )
V_28 = F_27 ( V_2 , V_582 , 0 ) ;
else
V_28 = F_27 ( V_2 , V_582 , 1 ) ;
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_87 ( struct V_1 * V_2 , bool * V_581 )
{
int V_28 ;
F_17 ( 1 , L_3 ) ;
if ( * V_581 ) {
V_28 = F_27 ( V_2 , V_583 ,
V_584 ) ;
} else {
V_28 = F_27 ( V_2 , V_583 , 0 ) ;
}
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_585 * V_586 )
{
T_4 V_27 = 0 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_587 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
switch ( V_586 -> V_588 ) {
case V_589 :
V_27 &= ~ V_590 ;
V_27 |= ( ( V_586 -> V_591 <<
V_592 )
& ( V_590 ) ) ;
break;
case V_593 :
V_27 &= ~ V_594 ;
V_27 |= ( ( V_586 -> V_591 <<
V_595 )
& ( V_594 ) ) ;
break;
default:
return - V_191 ;
}
V_28 = F_27 ( V_2 , V_587 , V_27 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_89 ( struct V_1 * V_2 ,
enum V_596 * V_125 )
{
int V_28 = - V_191 ;
F_17 ( 1 , L_3 ) ;
switch ( * V_125 ) {
case V_597 :
case V_171 :
case V_598 :
break;
default:
goto error;
}
V_28 = F_27 ( V_2 , V_599 ,
( T_4 ) * V_125 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_28 ;
bool V_600 = false ;
bool V_601 = true ;
struct V_585 V_602 = { 0 , V_589 } ;
struct V_585 V_603 = { 0 , V_593 } ;
F_17 ( 1 , L_3 ) ;
V_28 = F_86 ( V_2 , & V_600 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_87 ( V_2 , & V_601 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_88 ( V_2 , & V_602 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_88 ( V_2 , & V_603 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_519 ,
V_2 -> V_139 . V_141 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_57 ( struct V_1 * V_2 ,
enum V_331 V_332 )
{
T_4 V_319 = 0 ;
T_4 V_27 = 0 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
F_85 ( V_2 ) ;
F_91 ( V_2 ) ;
V_28 = F_50 ( V_2 ,
V_322
| V_324 ,
0 , NULL , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_50 ( V_2 , V_322
| V_604 ,
0 , NULL , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_325 , V_326 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_327 , V_328 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_329 , V_330 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_605 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_606 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_607 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_608 , V_609 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_52 ( V_2 , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_610 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_611 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_612 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_613 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_614 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_615 , 0x4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_616 , 0x4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_617 , 1600 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_618 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_619 , 448 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_620 , 495 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_44 ( V_2 , V_621 ,
V_622 , V_623 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_624 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_625 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_626 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_329 , V_627 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_80 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_77 ( V_2 , & V_2 -> V_142 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_628 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_71 ( V_2 , & V_2 -> V_138 , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_72 ( V_2 , & V_2 -> V_139 , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_629 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
V_27 |= V_630 ;
V_28 = F_27 ( V_2 , V_629 , V_27 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_321 ) ;
if ( V_28 < 0 )
goto error;
if ( ! V_2 -> V_631 ) {
V_28 = F_27 ( V_2 , V_516 ,
V_2 -> V_139 . V_140 ) ;
if ( V_28 < 0 )
goto error;
}
#ifdef F_92
V_28 = F_27 ( V_2 , V_632 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_633 , 2 ) ;
if ( V_28 < 0 )
goto error;
#endif
V_28 = F_27 ( V_2 , V_634 , 1 ) ;
if ( V_28 < 0 )
goto error;
#ifdef F_92
V_28 = F_27 ( V_2 , V_635 , 0x400 ) ;
if ( V_28 < 0 )
goto error;
#else
V_28 = F_27 ( V_2 , V_635 , 0x1000 ) ;
if ( V_28 < 0 )
goto error;
#endif
V_28 = F_27 ( V_2 , V_636 , 0x0001 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_69 ( V_2 , V_4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_90 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_62 ( struct V_1 * V_2 )
{
T_4 V_562 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_562 = V_637 ;
V_28 = F_84 ( V_2 , V_570 , 0 ,
V_638 , V_562 ,
0 , 0 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_67 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_639 , V_640 ) ;
if ( V_28 < 0 )
goto error;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_61 ( struct V_1 * V_2 , T_4 V_487 ,
T_6 V_488 )
{
T_4 V_319 = 0 ;
T_4 V_449 = 0 ;
T_4 V_331 = 0 ;
T_1 V_641 = 0 ;
T_1 V_642 = 0 ;
T_4 V_562 ;
int V_28 ;
F_17 ( 1 , L_42 ,
V_487 , V_488 ) ;
V_28 = F_50 ( V_2 , V_322
| V_323 ,
0 , NULL , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_628 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_325 , V_326 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_327 , V_328 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_643 , V_644 ) ;
if ( V_28 < 0 )
goto error;
switch ( V_2 -> V_340 . V_645 ) {
case V_646 :
default:
V_331 |= V_647 ;
case V_648 :
V_449 |= V_649 ;
break;
case V_650 :
V_449 |= V_457 ;
break;
}
switch ( V_2 -> V_340 . V_651 ) {
default:
case V_652 :
V_331 |= V_653 ;
case V_654 :
V_449 |= V_655 ;
break;
case V_656 :
V_449 |= V_657 ;
break;
case V_658 :
V_449 |= V_659 ;
break;
case V_660 :
V_449 |= V_661 ;
break;
}
switch ( V_2 -> V_340 . V_662 ) {
case V_663 :
case V_664 :
default:
V_331 |= V_665 ;
case V_666 :
V_449 |= V_667 ;
break;
case V_668 :
V_449 |= V_669 ;
break;
case V_670 :
V_449 |= V_671 ;
break;
}
switch ( V_2 -> V_340 . V_429 ) {
case V_672 :
default:
V_331 |= V_673 ;
case V_434 :
V_449 |= V_674 ;
break;
case V_675 :
V_449 |= V_676 ;
break;
case V_430 :
V_449 |= V_677 ;
break;
}
#if 0
switch (channel->priority) {
case DRX_PRIORITY_LOW:
transmission_params |= OFDM_SC_RA_RAM_OP_PARAM_PRIO_LO;
WR16(dev_addr, OFDM_EC_SB_PRIOR__A,
OFDM_EC_SB_PRIOR_LO);
break;
case DRX_PRIORITY_HIGH:
transmission_params |= OFDM_SC_RA_RAM_OP_PARAM_PRIO_HI;
WR16(dev_addr, OFDM_EC_SB_PRIOR__A,
OFDM_EC_SB_PRIOR_HI));
break;
case DRX_PRIORITY_UNKNOWN:
default:
status = -EINVAL;
goto error;
}
#else
V_449 |= V_678 ;
V_28 = F_27 ( V_2 , V_679 , V_680 ) ;
if ( V_28 < 0 )
goto error;
#endif
switch ( V_2 -> V_340 . V_681 ) {
case V_682 :
default:
V_331 |= V_683 ;
case V_684 :
V_449 |= V_685 ;
break;
case V_686 :
V_449 |= V_687 ;
break;
case V_688 :
V_449 |= V_689 ;
break;
case V_690 :
V_449 |= V_691 ;
break;
case V_692 :
V_449 |= V_693 ;
break;
}
switch ( V_2 -> V_340 . V_694 ) {
case 0 :
V_2 -> V_340 . V_694 = 8000000 ;
case 8000000 :
V_642 = V_695 ;
V_28 = F_27 ( V_2 , V_696 ,
3052 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_697 ,
7 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_698 ,
7 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_699 ,
7 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_700 ,
1 ) ;
if ( V_28 < 0 )
goto error;
break;
case 7000000 :
V_642 = V_701 ;
V_28 = F_27 ( V_2 , V_696 ,
3491 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_697 ,
8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_698 ,
8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_699 ,
4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_700 ,
1 ) ;
if ( V_28 < 0 )
goto error;
break;
case 6000000 :
V_642 = V_702 ;
V_28 = F_27 ( V_2 , V_696 ,
4073 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_697 ,
19 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_698 ,
19 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_699 ,
14 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_700 ,
1 ) ;
if ( V_28 < 0 )
goto error;
break;
default:
V_28 = - V_191 ;
goto error;
}
if ( V_641 == 0 ) {
V_641 = F_5 ( ( T_1 )
( ( V_2 -> V_111 *
1000 ) / 3 ) , V_642 ) ;
if ( ( V_641 & 0x7fL ) >= 0x40 )
V_641 += 0x80L ;
V_641 = V_641 >> 7 ;
V_641 = V_641 - ( 1 << 23 ) ;
}
V_641 &=
( ( ( ( T_1 ) V_703 ) <<
V_704 ) | V_705 ) ;
V_28 = F_29 ( V_2 , V_706 , V_641 ) ;
if ( V_28 < 0 )
goto error;
#if 0
status = dvbt_set_frequency_shift(demod, channel, tuner_offset);
if (status < 0)
goto error;
#endif
V_28 = F_81 ( V_2 , V_487 ,
V_488 , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_321 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_707 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_325 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_50 ( V_2 , V_322
| V_708 ,
0 , NULL , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
V_562 = ( V_647 |
V_653 |
V_673 |
V_665 |
V_683 ) ;
V_28 = F_84 ( V_2 , V_571 ,
0 , V_449 , V_562 , 0 , 0 , 0 ) ;
if ( V_28 < 0 )
goto error;
if ( ! V_2 -> V_631 )
V_28 = F_89 ( V_2 , & V_2 -> V_170 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 * V_343 )
{
int V_28 ;
const T_4 V_709 = ( V_710 |
V_711 ) ;
const T_4 V_712 = ( V_711 ) ;
const T_4 V_713 = V_714 ;
T_4 V_715 = 0 ;
T_4 V_716 = 0 ;
F_17 ( 1 , L_3 ) ;
* V_343 = V_344 ;
V_28 = F_23 ( V_2 , V_325 , & V_716 ) ;
if ( V_28 < 0 )
goto V_249;
if ( V_716 == V_326 )
goto V_249;
V_28 = F_23 ( V_2 , V_717 , & V_715 ) ;
if ( V_28 < 0 )
goto V_249;
if ( ( V_715 & V_709 ) == V_709 )
* V_343 = V_718 ;
else if ( ( V_715 & V_712 ) == V_712 )
* V_343 = V_719 ;
else if ( ( V_715 & V_713 ) == V_713 )
* V_343 = V_720 ;
else if ( V_715 & V_721 )
* V_343 = V_722 ;
V_249:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_93 ( struct V_1 * V_2 )
{
enum V_307 V_318 = V_310 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_53 ( V_2 , & V_318 ) ;
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_55 ( struct V_1 * V_2 )
{
T_4 V_27 = 0 ;
T_4 V_319 ;
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_23 ( V_2 , V_320 , & V_27 ) ;
if ( V_28 < 0 )
goto error;
if ( V_27 == V_321 ) {
V_28 = F_27 ( V_2 , V_723 , V_724 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_50 ( V_2 , V_725
| V_323 ,
0 , NULL , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_52 ( V_2 , false ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_94 ( struct V_1 * V_2 ,
enum V_726 V_429 ,
T_1 V_727 )
{
T_1 V_728 = 0 ;
T_1 V_729 = 0 ;
T_4 V_730 = 0 ;
T_4 V_731 = 0 ;
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_730 = 1 ;
switch ( V_429 ) {
case V_732 :
V_728 = 4 * V_727 ;
break;
case V_733 :
V_728 = 5 * V_727 ;
break;
case V_734 :
V_728 = 6 * V_727 ;
break;
case V_735 :
V_728 = 7 * V_727 ;
break;
case V_736 :
V_728 = 8 * V_727 ;
break;
default:
V_28 = - V_191 ;
}
if ( V_28 < 0 )
goto error;
V_728 /= 1000 ;
V_728 *= 500 ;
V_729 = ( V_728 / 1632UL ) + 1 ;
V_730 = 1 + ( T_4 ) ( V_729 >> 16 ) ;
if ( V_730 == 0 ) {
V_28 = - V_191 ;
if ( V_28 < 0 )
goto error;
}
V_731 =
( ( T_4 ) V_729 +
( V_730 >> 1 ) ) / V_730 ;
V_28 = F_27 ( V_2 , V_635 , V_731 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_636 ,
V_730 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_737 , V_731 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_738 , 13517 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_739 , 13517 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_740 , 13517 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_741 , 13517 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_742 , 13517 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_743 , 13517 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_744 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_745 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_746 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_747 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_748 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_749 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_750 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_751 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_752 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_753 ,
V_431 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_754 , 15 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_755 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_756 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_757 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_758 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_759 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_760 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_761 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_762 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_763 , 20 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_764 , 80 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_765 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_766 , 20 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_767 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_768 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_769 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_770 , 32 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_771 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_772 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_773 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_774 , 140 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_775 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_776 , 95 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_777 , 120 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_778 , 230 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_779 , 105 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_780 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_781 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_782 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_783 , ( T_4 ) 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_784 , ( T_4 ) 220 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_785 , ( T_4 ) 25 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_786 , ( T_4 ) 6 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_787 , ( T_4 ) - 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_788 , ( T_4 ) - 65 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_789 , ( T_4 ) - 127 ) ;
if ( V_28 < 0 )
goto error;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_738 , 6707 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_739 , 6707 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_740 , 6707 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_741 , 6707 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_742 , 6707 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_743 , 6707 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_744 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_745 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_746 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_747 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_748 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_749 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_750 , 6 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_751 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_752 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_753 ,
V_433 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_754 , 15 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_755 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_756 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_757 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_758 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_759 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_760 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_761 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_762 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_763 , 20 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_764 , 80 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_765 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_766 , 20 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_767 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_768 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_769 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_770 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_771 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_772 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_773 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_774 , 90 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_775 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_776 , 80 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_777 , 100 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_778 , 170 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_779 , 100 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_780 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_781 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_782 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_783 , ( T_4 ) 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_784 , ( T_4 ) 140 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_785 , ( T_4 ) - 8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_786 , ( T_4 ) - 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_787 , ( T_4 ) - 26 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_788 , ( T_4 ) - 56 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_789 , ( T_4 ) - 86 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_738 , 13336 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_739 , 12618 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_740 , 11988 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_741 , 13809 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_742 , 13809 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_743 , 15609 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_744 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_745 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_746 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_747 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_748 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_749 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_750 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_751 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_752 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_753 ,
V_435 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_754 , 15 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_755 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_756 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_757 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_758 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_759 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_760 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_761 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_762 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_763 , 30 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_764 , 100 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_765 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_766 , 30 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_767 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_768 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_769 , 25 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_770 , 48 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_771 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_772 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_773 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_774 , 100 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_775 , 60 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_776 , 80 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_777 , 110 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_778 , 200 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_779 , 95 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_780 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_781 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_782 , 15 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_783 , ( T_4 ) 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_784 , ( T_4 ) 141 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_785 , ( T_4 ) 7 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_786 , ( T_4 ) 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_787 , ( T_4 ) - 15 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_788 , ( T_4 ) - 45 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_789 , ( T_4 ) - 80 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_738 , 6564 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_739 , 6598 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_740 , 6394 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_741 , 6409 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_742 , 6656 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_743 , 7238 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_744 , 6 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_745 , 6 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_746 , 6 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_747 , 6 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_748 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_749 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_750 , 6 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_751 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_752 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_753 ,
V_437 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_754 , 15 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_755 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_756 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_757 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_758 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_759 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_760 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_761 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_762 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_763 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_764 , 120 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_765 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_766 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_767 , 60 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_768 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_769 , 25 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_770 , 64 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_771 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_772 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_773 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_774 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_775 , 60 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_776 , 80 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_777 , 100 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_778 , 140 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_779 , 100 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_780 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_781 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_782 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_783 , ( T_4 ) 8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_784 , ( T_4 ) 65 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_785 , ( T_4 ) 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_786 , ( T_4 ) 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_787 , ( T_4 ) - 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_788 , ( T_4 ) - 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_789 , ( T_4 ) - 23 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_738 , 11502 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_739 , 12084 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_740 , 12543 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_741 , 12931 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_742 , 13629 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_743 , 15385 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_744 , 8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_745 , 8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_746 , 8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_747 , 8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_748 , 6 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_749 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_750 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_751 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_752 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_753 ,
V_439 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_754 , 15 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_755 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_756 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_757 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_758 , 24 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_759 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_760 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_761 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_762 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_763 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_764 , 250 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_765 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_766 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_767 , 125 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_768 , 16 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_769 , 25 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_770 , 48 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_771 , 5 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_772 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_773 , 10 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_774 , 50 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_775 , 60 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_776 , 80 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_777 , 100 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_778 , 150 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_779 , 110 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_780 , 40 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_781 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_782 , 12 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_783 , ( T_4 ) 8 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_784 , ( T_4 ) 74 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_785 , ( T_4 ) 18 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_786 , ( T_4 ) 13 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_787 , ( T_4 ) 7 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_788 , ( T_4 ) 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_789 , ( T_4 ) - 8 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_28 ;
T_4 V_319 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_723 , V_724 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_50 ( V_2 , V_725
| V_324 ,
0 , NULL , 1 , & V_319 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_101 ( struct V_1 * V_2 )
{
T_1 V_790 = 0 ;
T_1 V_791 = 0 ;
T_1 V_792 = 0 ;
T_4 V_793 = 0 ;
T_1 V_794 = 0 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_790 = ( V_2 -> V_111 * 1000 ) / 3 ;
V_793 = 0 ;
if ( V_2 -> V_340 . V_727 <= 1188750 )
V_793 = 3 ;
else if ( V_2 -> V_340 . V_727 <= 2377500 )
V_793 = 2 ;
else if ( V_2 -> V_340 . V_727 <= 4755000 )
V_793 = 1 ;
V_28 = F_27 ( V_2 , V_795 , V_793 ) ;
if ( V_28 < 0 )
goto error;
V_791 = V_2 -> V_340 . V_727 * ( 1 << V_793 ) ;
if ( V_791 == 0 ) {
V_28 = - V_191 ;
goto error;
}
V_792 = ( V_790 / V_791 ) * ( 1 << 21 ) +
( F_5 ( ( V_790 % V_791 ) , V_791 ) >> 7 ) -
( 1 << 23 ) ;
V_28 = F_29 ( V_2 , V_706 , V_792 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_796 = V_792 ;
V_791 = V_2 -> V_340 . V_727 ;
if ( V_790 == 0 ) {
V_28 = - V_191 ;
goto error;
}
V_794 = ( V_791 / V_790 ) * ( 1 << 12 ) +
( F_5 ( ( V_791 % V_790 ) , V_790 ) >>
16 ) ;
if ( V_794 > 511 )
V_794 = 511 ;
V_28 = F_27 ( V_2 , V_797 , ( T_4 ) V_794 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 * V_343 )
{
int V_28 ;
T_4 V_282 [ 2 ] = { 0 , 0 } ;
F_17 ( 1 , L_3 ) ;
* V_343 = V_344 ;
V_28 = F_50 ( V_2 ,
V_725 |
V_798 , 0 , NULL , 2 ,
V_282 ) ;
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
if ( V_282 [ 1 ] < V_799 ) {
} else if ( V_282 [ 1 ] < V_800 ) {
* V_343 = V_720 ;
} else if ( V_282 [ 1 ] < V_801 ) {
* V_343 = V_718 ;
} else {
* V_343 = V_722 ;
}
return V_28 ;
}
static int F_102 ( struct V_1 * V_2 ,
int V_802 )
{
int V_28 ;
T_4 V_319 ;
T_4 V_803 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_803 [ 0 ] = V_2 -> V_164 ;
V_803 [ 1 ] = V_167 ;
if ( V_802 == 2 ) {
T_4 V_804 [ 1 ] = { 0 } ;
if ( V_2 -> V_3 == V_7 )
V_804 [ 0 ] = V_805 ;
else
V_804 [ 0 ] = V_806 ;
V_28 = F_50 ( V_2 ,
V_725
| V_604 ,
1 , V_804 , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_50 ( V_2 ,
V_725
| V_807 ,
V_802 , V_803 ,
1 , & V_319 ) ;
} else if ( V_802 == 4 ) {
if ( V_2 -> V_3 == V_7 )
V_803 [ 2 ] = V_805 ;
else
V_803 [ 2 ] = V_806 ;
V_803 [ 3 ] |= ( V_808 ) ;
V_28 = F_50 ( V_2 ,
V_725
| V_807 ,
V_802 , V_803 ,
1 , & V_319 ) ;
} else {
F_103 ( L_43 ,
V_802 ) ;
V_28 = - V_191 ;
}
error:
if ( V_28 < 0 )
F_103 ( L_44 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_60 ( struct V_1 * V_2 , T_4 V_487 ,
T_6 V_488 )
{
int V_28 ;
T_4 V_319 ;
int V_809 = V_2 -> V_810 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_811 , V_812 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_813 , V_814 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_100 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_101 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
switch ( V_2 -> V_340 . V_429 ) {
case V_438 :
V_2 -> V_164 = V_736 ;
break;
case V_672 :
case V_434 :
V_2 -> V_164 = V_734 ;
break;
case V_430 :
V_2 -> V_164 = V_732 ;
break;
case V_432 :
V_2 -> V_164 = V_733 ;
break;
case V_436 :
V_2 -> V_164 = V_735 ;
break;
default:
V_28 = - V_191 ;
break;
}
if ( V_28 < 0 )
goto error;
if ( V_2 -> V_810 == 4
|| ! V_2 -> V_810 ) {
V_809 = 4 ;
V_28 = F_102 ( V_2 , V_809 ) ;
}
if ( V_2 -> V_810 == 2
|| ( ! V_2 -> V_810 && V_28 < 0 ) ) {
V_809 = 2 ;
V_28 = F_102 ( V_2 , V_809 ) ;
}
if ( V_28 < 0 ) {
F_17 ( 1 , L_45 ) ;
F_17 ( 1 ,
L_46 ,
V_2 -> V_810 ,
V_2 -> V_815 ) ;
goto error;
} else if ( ! V_2 -> V_810 ) {
F_17 ( 1 ,
L_47 ,
V_809 ) ;
V_2 -> V_810 = V_809 ;
}
#if 0
status = set_frequency(channel, tuner_freq_offset));
if (status < 0)
goto error;
#endif
V_28 = F_81 ( V_2 , V_487 ,
V_488 , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_94 ( V_2 , V_2 -> V_164 ,
V_2 -> V_340 . V_727 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_618 , V_816 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_817 , V_818 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_819 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_820 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_821 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_822 , 7 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_823 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_824 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_825 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_826 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_827 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_828 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_829 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_830 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_831 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_832 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_833 , 2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_834 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_835 , 3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_836 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_837 , 4 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_838 ,
V_839 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_628 ) ;
if ( V_28 < 0 )
goto error;
switch ( V_2 -> V_340 . V_429 ) {
case V_430 :
V_28 = F_95 ( V_2 ) ;
break;
case V_432 :
V_28 = F_96 ( V_2 ) ;
break;
case V_672 :
case V_434 :
V_28 = F_97 ( V_2 ) ;
break;
case V_436 :
V_28 = F_98 ( V_2 ) ;
break;
case V_438 :
V_28 = F_99 ( V_2 ) ;
break;
default:
V_28 = - V_191 ;
break;
}
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_321 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_69 ( V_2 , V_2 -> V_3 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_67 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_639 , V_640 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_723 , V_840 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_329 , V_627 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_50 ( V_2 , V_725
| V_708 ,
0 , NULL , 1 , & V_319 ) ;
if ( V_28 < 0 )
goto error;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_58 ( struct V_1 * V_2 ,
enum V_331 V_332 )
{
int V_28 ;
#ifdef F_104
#define F_105
#include "drxk_filters.h"
#undef F_105
#endif
F_17 ( 1 , L_3 ) ;
F_106 ( V_2 ) ;
V_28 = F_93 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_100 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_329 , V_330 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_608 , V_609 ) ;
if ( V_28 < 0 )
goto error;
switch ( V_332 ) {
case V_5 :
V_28 = F_44 ( V_2 , V_841 ,
V_622 ,
V_623 ) ;
break;
case V_7 :
V_28 = F_78 ( V_2 , V_842 ,
V_843 ,
V_844 ,
V_623 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_78 ( V_2 ,
V_845 ,
V_843 ,
V_844 ,
V_623 ) ;
break;
default:
V_28 = - V_191 ;
}
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_615 , 1 << V_846 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_847 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_848 ,
( ( 1 << V_849 ) | ( 1 << V_850 ) ) ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_614 , 21 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_606 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_619 , 448 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_607 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_625 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_851 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_852 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_853 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_605 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_854 , 500 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_620 , 1000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_582 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_612 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_613 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_624 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_855 , 1 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_52 ( V_2 , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_478 , 0x01 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_80 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_856 , 2000 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_628 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_82 ( V_2 , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_77 ( V_2 , & ( V_2 -> V_146 ) ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_71 ( V_2 , & ( V_2 -> V_143 ) , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_72 ( V_2 , & ( V_2 -> V_144 ) , true ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_321 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_28 ;
T_4 V_15 = 0 ;
F_17 ( 1 , L_3 ) ;
V_28 = F_27 ( V_2 , V_180 ,
V_181 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_182 , V_183 ) ;
if ( V_28 < 0 )
goto error;
if ( V_2 -> V_198 ) {
if ( V_2 -> V_857 & 0x0001 ) {
V_28 = F_27 ( V_2 , V_858 ,
V_2 -> V_173 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_859 , & V_15 ) ;
if ( V_28 < 0 )
goto error;
if ( ( V_2 -> V_860 & 0x0001 ) == 0 )
V_15 &= 0x7FFF ;
else
V_15 |= 0x8000 ;
V_28 = F_27 ( V_2 , V_859 , V_15 ) ;
if ( V_28 < 0 )
goto error;
}
if ( V_2 -> V_857 & 0x0002 ) {
V_28 = F_27 ( V_2 , V_861 ,
V_2 -> V_173 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_859 , & V_15 ) ;
if ( V_28 < 0 )
goto error;
if ( ( V_2 -> V_860 & 0x0002 ) == 0 )
V_15 &= 0xBFFF ;
else
V_15 |= 0x4000 ;
V_28 = F_27 ( V_2 , V_859 , V_15 ) ;
if ( V_28 < 0 )
goto error;
}
if ( V_2 -> V_857 & 0x0004 ) {
V_28 = F_27 ( V_2 , V_862 ,
V_2 -> V_173 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_2 , V_859 , & V_15 ) ;
if ( V_28 < 0 )
goto error;
if ( ( V_2 -> V_860 & 0x0004 ) == 0 )
V_15 &= 0xFFFB ;
else
V_15 |= 0x0004 ;
V_28 = F_27 ( V_2 , V_859 , V_15 ) ;
if ( V_28 < 0 )
goto error;
}
}
V_28 = F_27 ( V_2 , V_182 , 0x0000 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
bool V_863 ;
F_17 ( 1 , L_3 ) ;
if ( ! V_2 -> V_864 )
return 0 ;
V_863 = V_2 -> V_860 & V_2 -> V_864 ;
if ( V_2 -> V_865 ^ V_863 ) {
if ( V_2 -> V_865 )
V_2 -> V_860 &= ~ V_2 -> V_864 ;
else
V_2 -> V_860 |= V_2 -> V_864 ;
V_28 = F_107 ( V_2 ) ;
}
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
bool V_863 ;
F_17 ( 1 , L_3 ) ;
if ( ! V_2 -> V_864 )
return 0 ;
V_863 = V_2 -> V_860 & V_2 -> V_864 ;
if ( ! ( V_2 -> V_865 ^ V_863 ) ) {
if ( V_2 -> V_865 )
V_2 -> V_860 |= V_2 -> V_864 ;
else
V_2 -> V_860 &= ~ V_2 -> V_864 ;
V_28 = F_107 ( V_2 ) ;
}
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_28 ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_110 ) {
V_28 = F_76 ( V_2 , true ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_48 ( V_2 , false ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_51 ,
V_313 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_53 , V_54 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_116 |= V_209 ;
V_28 = F_38 ( V_2 ) ;
error:
if ( V_28 < 0 )
F_19 ( L_13 , V_28 , V_48 ) ;
return V_28 ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_28 = 0 , V_866 = 0 ;
enum V_307 V_318 = V_310 ;
T_4 V_867 ;
F_17 ( 1 , L_3 ) ;
if ( ( V_2 -> V_148 == V_149 ) ) {
F_8 ( V_2 ) ;
V_28 = F_31 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_34 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_868 ,
V_869
| V_870
| V_871 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_53 , V_54 ) ;
if ( V_28 < 0 )
goto error;
F_32 ( 1000 , 2000 ) ;
V_2 -> V_119 = true ;
V_28 = F_35 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_219 =
( T_4 ) ( ( V_2 -> V_108 / 1000 ) *
V_872 ) / 1000 ;
if ( V_2 -> V_219 >
V_873 ) {
V_2 -> V_219 =
V_873 ;
}
V_2 -> V_219 +=
V_2 -> V_219 <<
V_874 ;
V_28 = F_41 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
#if V_875
if ( ! ( V_2 -> V_876 )
&& ! ( V_2 -> V_877 ) )
#endif
{
V_28 = F_27 ( V_2 , V_180 ,
V_181 ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_43 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_878 , V_879 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_880 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_271 ,
V_265 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_881 ,
V_882 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_44 ( V_2 , 0 , 6 , 100 ) ;
if ( V_28 < 0 )
goto error;
if ( V_2 -> V_883 ) {
V_28 = F_47 ( V_2 , V_2 -> V_883 -> V_27 ,
V_2 -> V_883 -> V_884 ) ;
if ( V_28 < 0 )
goto error;
}
V_28 = F_27 ( V_2 , V_271 ,
V_268 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_320 , V_321 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_34 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
F_110 ( 30 ) ;
V_318 = V_310 ;
V_28 = F_53 ( V_2 , & V_318 ) ;
if ( V_28 < 0 )
goto error;
V_867 =
( ( ( V_885 / 100 ) % 10 ) << 12 ) +
( ( ( V_885 / 10 ) % 10 ) << 8 ) +
( ( V_885 % 10 ) << 4 ) +
( V_886 % 10 ) ;
V_28 = F_27 ( V_2 , V_887 ,
V_867 ) ;
if ( V_28 < 0 )
goto error;
V_867 =
( ( ( V_888 / 1000 ) % 10 ) << 12 ) +
( ( ( V_888 / 100 ) % 10 ) << 8 ) +
( ( ( V_888 / 10 ) % 10 ) << 4 ) +
( V_888 % 10 ) ;
V_28 = F_27 ( V_2 , V_889 ,
V_867 ) ;
if ( V_28 < 0 )
goto error;
F_36 ( L_48 ,
V_885 , V_886 ,
V_888 ) ;
V_28 = F_27 ( V_2 , V_890 , 0 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_27 ( V_2 , V_639 , V_891 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_68 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_49 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_70 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_42 ( V_2 , V_2 -> V_150 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_107 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_148 = V_337 ;
if ( V_2 -> V_118 ) {
V_28 = F_108 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_148 = V_459 ;
} else
V_2 -> V_148 = V_337 ;
V_866 = 0 ;
if ( V_2 -> V_104 ) {
V_2 -> V_892 . V_893 . V_894 [ V_866 ++ ] = V_895 ;
V_2 -> V_892 . V_893 . V_894 [ V_866 ++ ] = V_896 ;
F_111 ( V_2 -> V_892 . V_893 . V_897 . V_898 , L_49 ,
sizeof( V_2 -> V_892 . V_893 . V_897 . V_898 ) ) ;
}
if ( V_2 -> V_103 ) {
V_2 -> V_892 . V_893 . V_894 [ V_866 ++ ] = V_899 ;
F_111 ( V_2 -> V_892 . V_893 . V_897 . V_898 , L_50 ,
sizeof( V_2 -> V_892 . V_893 . V_897 . V_898 ) ) ;
}
F_10 ( V_2 ) ;
}
error:
if ( V_28 < 0 ) {
V_2 -> V_148 = V_900 ;
F_10 ( V_2 ) ;
F_19 ( L_13 , V_28 , V_48 ) ;
}
return V_28 ;
}
static void F_112 ( const struct V_901 * V_883 ,
void * V_902 )
{
struct V_1 * V_2 = V_902 ;
F_17 ( 1 , L_51 , V_883 ? L_52 : L_53 ) ;
if ( ! V_883 ) {
F_19 ( L_54 ,
V_2 -> V_815 ) ;
F_36 ( L_55 ,
V_2 -> V_815 ) ;
V_2 -> V_815 = NULL ;
}
V_2 -> V_883 = V_883 ;
F_109 ( V_2 ) ;
}
static void F_113 ( struct V_903 * V_904 )
{
struct V_1 * V_2 = V_904 -> V_905 ;
F_17 ( 1 , L_3 ) ;
F_114 ( V_2 -> V_883 ) ;
F_115 ( V_2 ) ;
}
static int F_116 ( struct V_903 * V_904 )
{
struct V_1 * V_2 = V_904 -> V_905 ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_148 == V_900 )
return - V_906 ;
if ( V_2 -> V_148 == V_149 )
return 0 ;
F_63 ( V_2 ) ;
return 0 ;
}
static int F_117 ( struct V_903 * V_904 , int V_263 )
{
struct V_1 * V_2 = V_904 -> V_905 ;
F_17 ( 1 , L_51 , V_263 ? L_24 : L_25 ) ;
if ( V_2 -> V_148 == V_900 )
return - V_906 ;
return F_76 ( V_2 , V_263 ? true : false ) ;
}
static int F_118 ( struct V_903 * V_904 )
{
struct V_907 * V_289 = & V_904 -> V_908 ;
T_1 V_894 = V_289 -> V_909 , V_910 ;
struct V_1 * V_2 = V_904 -> V_905 ;
T_1 IF ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_148 == V_900 )
return - V_906 ;
if ( V_2 -> V_148 == V_149 )
return - V_911 ;
if ( ! V_904 -> V_893 . V_912 . V_913 ) {
F_19 ( L_56 ) ;
return - V_191 ;
}
if ( V_904 -> V_893 . V_914 )
V_904 -> V_893 . V_914 ( V_904 , 1 ) ;
if ( V_904 -> V_893 . V_912 . V_915 )
V_904 -> V_893 . V_912 . V_915 ( V_904 ) ;
if ( V_904 -> V_893 . V_914 )
V_904 -> V_893 . V_914 ( V_904 , 0 ) ;
V_910 = V_2 -> V_340 . V_909 ;
V_2 -> V_340 = * V_289 ;
if ( V_910 != V_894 ) {
F_63 ( V_2 ) ;
switch ( V_894 ) {
case V_895 :
case V_896 :
if ( ! V_2 -> V_104 )
return - V_191 ;
V_2 -> V_916 = ( V_894 == V_896 ) ?
true : false ;
if ( V_2 -> V_916 )
F_56 ( V_2 , V_7 ) ;
else
F_56 ( V_2 , V_5 ) ;
break;
case V_899 :
if ( ! V_2 -> V_103 )
return - V_191 ;
F_56 ( V_2 , V_4 ) ;
break;
default:
return - V_191 ;
}
}
V_904 -> V_893 . V_912 . V_913 ( V_904 , & IF ) ;
F_59 ( V_2 , 0 , IF ) ;
V_289 -> V_917 . V_918 [ 0 ] . V_919 = V_920 ;
V_289 -> V_921 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_923 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_924 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_925 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_926 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_927 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_928 . V_918 [ 0 ] . V_919 = V_922 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , T_2 * V_917 )
{
int V_28 ;
struct V_402 V_929 , V_930 ;
T_1 V_931 = 0 ;
T_1 V_932 = 0 ;
T_1 V_933 = 0 ;
T_4 V_934 = 0 ;
T_4 V_935 = 0 ;
T_4 V_936 = 50 ;
T_4 V_937 = 40 ;
* V_917 = 0 ;
if ( F_1 ( V_2 ) ) {
V_929 = V_2 -> V_138 ;
V_930 = V_2 -> V_139 ;
} else if ( F_2 ( V_2 ) ) {
V_929 = V_2 -> V_143 ;
V_930 = V_2 -> V_144 ;
} else {
V_929 = V_2 -> V_136 ;
V_930 = V_2 -> V_135 ;
}
if ( V_929 . V_121 == V_59 ) {
V_28 = F_23 ( V_2 , V_417 , & V_934 ) ;
if ( V_28 < 0 )
return V_28 ;
F_23 ( V_2 , V_414 , & V_935 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( ( T_1 ) V_934 + ( T_1 ) V_935 ) < 0xffff )
V_929 . V_122 = V_934 + V_935 ;
else
V_929 . V_122 = 0xffff ;
V_931 += V_936 ;
if ( V_929 . V_122 < V_929 . V_123 )
V_929 . V_122 = V_929 . V_123 ;
if ( V_929 . V_122 > V_929 . V_124 )
V_929 . V_122 = V_929 . V_124 ;
V_933 = ( T_1 ) ( V_929 . V_124 - V_929 . V_123 ) ;
if ( V_933 > 0 ) {
V_932 += 100UL *
( ( T_1 ) ( V_936 ) ) *
( ( T_1 ) ( V_929 . V_122 - V_929 . V_123 ) )
/ V_933 ;
}
}
if ( V_930 . V_121 == V_59 ) {
V_28 = F_23 ( V_2 , V_521 ,
& V_930 . V_122 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_23 ( V_2 , V_423 ,
& V_930 . V_128 ) ;
if ( V_28 < 0 )
return V_28 ;
V_931 += ( T_1 ) V_937 ;
if ( V_930 . V_122 < V_930 . V_123 )
V_930 . V_122 = V_930 . V_123 ;
if ( V_930 . V_122 > V_930 . V_124 )
V_930 . V_122 = V_930 . V_124 ;
V_933 = ( T_1 ) ( V_930 . V_124 - V_930 . V_123 ) ;
if ( V_933 > 0 ) {
V_932 += 100UL *
( ( T_1 ) ( V_937 ) ) *
( ( T_1 ) ( V_930 . V_122 - V_930 . V_123 ) )
/ V_933 ;
}
}
if ( V_931 > 0 )
* V_917 = ( 65535UL * V_932 / V_931 / 100 ) ;
else
* V_917 = 65535 ;
return 0 ;
}
static int F_120 ( struct V_903 * V_904 )
{
struct V_907 * V_10 = & V_904 -> V_908 ;
struct V_1 * V_2 = V_904 -> V_905 ;
int V_28 ;
T_1 V_918 ;
T_4 V_938 ;
T_1 V_928 ;
T_1 V_939 ;
T_1 V_940 ;
T_1 V_941 ;
T_1 V_926 ;
T_1 V_942 ;
T_1 V_943 ;
T_6 V_921 ;
if ( V_2 -> V_148 == V_900 )
return - V_906 ;
if ( V_2 -> V_148 == V_149 )
return - V_911 ;
V_2 -> V_944 = 0 ;
F_64 ( V_2 , & V_918 ) ;
if ( V_918 == V_718 )
V_2 -> V_944 |= 0x1f ;
if ( V_918 == V_719 )
V_2 -> V_944 |= 0x0f ;
if ( V_918 == V_720 )
V_2 -> V_944 |= 0x07 ;
F_119 ( V_2 , & V_10 -> V_917 . V_918 [ 0 ] . V_945 ) ;
V_10 -> V_917 . V_918 [ 0 ] . V_919 = V_920 ;
if ( V_918 >= V_720 ) {
F_75 ( V_2 , & V_921 ) ;
V_10 -> V_921 . V_918 [ 0 ] . V_946 = V_921 * 100 ;
V_10 -> V_921 . V_918 [ 0 ] . V_919 = V_947 ;
} else {
V_10 -> V_921 . V_918 [ 0 ] . V_919 = V_922 ;
}
if ( V_918 < V_719 ) {
V_10 -> V_923 . V_918 [ 0 ] . V_919 = V_922 ;
V_10 -> V_924 . V_918 [ 0 ] . V_919 = V_922 ;
V_10 -> V_925 . V_918 [ 0 ] . V_919 = V_922 ;
V_10 -> V_926 . V_918 [ 0 ] . V_919 = V_922 ;
V_10 -> V_927 . V_918 [ 0 ] . V_919 = V_922 ;
V_10 -> V_928 . V_918 [ 0 ] . V_919 = V_922 ;
return 0 ;
}
V_28 = F_23 ( V_2 , V_948 , & V_938 ) ;
if ( V_28 < 0 )
goto error;
V_941 = V_938 ;
V_28 = F_23 ( V_2 , V_949 , & V_938 ) ;
if ( V_28 < 0 )
goto error;
V_926 = V_938 ;
V_28 = F_23 ( V_2 , V_950 , & V_938 ) ;
if ( V_28 < 0 )
goto error;
V_939 = V_938 ;
V_28 = F_23 ( V_2 , V_636 , & V_938 ) ;
if ( V_28 < 0 )
goto error;
V_940 = V_938 ;
V_28 = F_23 ( V_2 , V_635 , & V_938 ) ;
if ( V_28 < 0 )
goto error;
V_942 = V_938 ;
V_28 = F_23 ( V_2 , V_559 , & V_938 ) ;
if ( V_28 < 0 )
goto error;
V_943 = V_938 ;
F_27 ( V_2 , V_559 , 0 ) ;
V_939 *= V_940 ;
V_928 = V_942 * 204 * 8 ;
V_10 -> V_923 . V_918 [ 0 ] . V_919 = V_951 ;
V_10 -> V_923 . V_918 [ 0 ] . V_945 += V_943 ;
V_10 -> V_924 . V_918 [ 0 ] . V_919 = V_951 ;
V_10 -> V_924 . V_918 [ 0 ] . V_945 += V_942 ;
V_10 -> V_925 . V_918 [ 0 ] . V_919 = V_951 ;
V_10 -> V_925 . V_918 [ 0 ] . V_945 += V_941 ;
V_10 -> V_926 . V_918 [ 0 ] . V_919 = V_951 ;
V_10 -> V_926 . V_918 [ 0 ] . V_945 += V_926 ;
V_10 -> V_927 . V_918 [ 0 ] . V_919 = V_951 ;
V_10 -> V_927 . V_918 [ 0 ] . V_945 += V_939 ;
V_10 -> V_928 . V_918 [ 0 ] . V_919 = V_951 ;
V_10 -> V_928 . V_918 [ 0 ] . V_945 += V_928 ;
error:
return V_28 ;
}
static int F_121 ( struct V_903 * V_904 , T_7 * V_28 )
{
struct V_1 * V_2 = V_904 -> V_905 ;
int V_952 ;
F_17 ( 1 , L_3 ) ;
V_952 = F_120 ( V_904 ) ;
if ( V_952 < 0 )
return V_952 ;
* V_28 = V_2 -> V_944 ;
return 0 ;
}
static int F_122 ( struct V_903 * V_904 ,
T_4 * V_917 )
{
struct V_1 * V_2 = V_904 -> V_905 ;
struct V_907 * V_10 = & V_904 -> V_908 ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_148 == V_900 )
return - V_906 ;
if ( V_2 -> V_148 == V_149 )
return - V_911 ;
* V_917 = V_10 -> V_917 . V_918 [ 0 ] . V_945 ;
return 0 ;
}
static int F_123 ( struct V_903 * V_904 , T_4 * V_953 )
{
struct V_1 * V_2 = V_904 -> V_905 ;
T_6 V_954 ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_148 == V_900 )
return - V_906 ;
if ( V_2 -> V_148 == V_149 )
return - V_911 ;
F_75 ( V_2 , & V_954 ) ;
if ( V_954 < 0 )
V_954 = 0 ;
* V_953 = V_954 & 0xffff ;
return 0 ;
}
static int F_124 ( struct V_903 * V_904 , T_1 * V_955 )
{
struct V_1 * V_2 = V_904 -> V_905 ;
T_4 V_294 ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_148 == V_900 )
return - V_906 ;
if ( V_2 -> V_148 == V_149 )
return - V_911 ;
F_83 ( V_2 , & V_294 ) ;
* V_955 = ( T_1 ) V_294 ;
return 0 ;
}
static int F_125 ( struct V_903 * V_904 ,
struct V_956 * V_957 )
{
struct V_1 * V_2 = V_904 -> V_905 ;
struct V_907 * V_289 = & V_904 -> V_908 ;
F_17 ( 1 , L_3 ) ;
if ( V_2 -> V_148 == V_900 )
return - V_906 ;
if ( V_2 -> V_148 == V_149 )
return - V_911 ;
switch ( V_289 -> V_909 ) {
case V_895 :
case V_896 :
case V_899 :
V_957 -> V_958 = 3000 ;
V_957 -> V_959 = 0 ;
V_957 -> V_960 = 0 ;
return 0 ;
default:
return - V_191 ;
}
}
struct V_903 * F_126 ( const struct V_961 * V_962 ,
struct V_963 * V_16 )
{
struct V_907 * V_289 ;
struct V_1 * V_2 = NULL ;
T_3 V_21 = V_962 -> V_21 ;
int V_28 ;
F_17 ( 1 , L_3 ) ;
V_2 = F_127 ( sizeof( struct V_1 ) , V_964 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_16 = V_16 ;
V_2 -> V_35 = V_21 ;
V_2 -> V_38 = V_962 -> V_38 ;
V_2 -> V_815 = V_962 -> V_815 ;
V_2 -> V_810 = V_962 -> V_810 ;
V_2 -> V_460 = V_962 -> V_460 ;
V_2 -> V_864 = V_962 -> V_864 ;
V_2 -> V_865 = V_962 -> V_865 ;
V_2 -> V_45 = V_962 -> V_965 ;
V_2 -> V_243 = V_962 -> V_243 ;
if ( V_962 -> V_966 ) {
V_2 -> V_372 = false ;
V_2 -> V_373 = false ;
} else {
V_2 -> V_372 = true ;
V_2 -> V_373 = true ;
}
if ( V_962 -> V_967 )
V_2 -> V_241 = V_962 -> V_967 & 0x07 ;
else
V_2 -> V_241 = 0x06 ;
if ( V_962 -> V_968 )
V_2 -> V_227 = true ;
else
V_2 -> V_227 = false ;
V_2 -> V_857 = V_962 -> V_864 ;
if ( ! V_2 -> V_865 && V_2 -> V_864 )
V_2 -> V_860 |= V_2 -> V_864 ;
else
V_2 -> V_860 &= ~ V_2 -> V_864 ;
F_128 ( & V_2 -> V_213 ) ;
memcpy ( & V_2 -> V_892 . V_893 , & V_969 , sizeof( V_969 ) ) ;
V_2 -> V_892 . V_905 = V_2 ;
F_33 ( V_2 ) ;
if ( V_2 -> V_815 ) {
const struct V_901 * V_883 = NULL ;
V_28 = F_129 ( & V_883 , V_2 -> V_815 ,
V_2 -> V_16 -> V_970 . V_971 ) ;
if ( V_28 < 0 )
V_883 = NULL ;
F_112 ( V_883 , V_2 ) ;
} else if ( F_109 ( V_2 ) < 0 )
goto error;
V_289 = & V_2 -> V_892 . V_908 ;
V_289 -> V_917 . V_20 = 1 ;
V_289 -> V_921 . V_20 = 1 ;
V_289 -> V_923 . V_20 = 1 ;
V_289 -> V_924 . V_20 = 1 ;
V_289 -> V_925 . V_20 = 1 ;
V_289 -> V_926 . V_20 = 1 ;
V_289 -> V_927 . V_20 = 1 ;
V_289 -> V_928 . V_20 = 1 ;
V_289 -> V_917 . V_918 [ 0 ] . V_919 = V_920 ;
V_289 -> V_921 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_923 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_924 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_925 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_926 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_927 . V_918 [ 0 ] . V_919 = V_922 ;
V_289 -> V_928 . V_918 [ 0 ] . V_919 = V_922 ;
F_36 ( L_57 ) ;
return & V_2 -> V_892 ;
error:
F_19 ( L_58 ) ;
F_115 ( V_2 ) ;
return NULL ;
}
