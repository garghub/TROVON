static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_13 ;
if ( ( V_7 [ 0 ] != V_14 ) && ( V_7 [ 0 ] != V_15 ) )
return - 1 ;
V_11 -> V_16 = V_7 [ 2 ] ;
if ( V_7 [ 0 ] == V_15 ) {
for ( V_13 = 0 ; V_13 < V_7 [ 3 ] ; V_13 ++ ) {
if ( F_3 ( V_7 [ 4 + V_13 ] ) >=
V_9 -> V_17 ) {
F_4 ( L_1 ) ;
return - 2 ;
}
}
V_11 -> V_18 = V_15 ;
if ( V_7 [ 1 ] )
V_11 -> V_19 = V_20 ;
else
V_11 -> V_19 = V_21 ;
V_11 -> V_22 = V_7 [ 3 ] ;
for ( V_13 = 0 ; V_13 < V_11 -> V_22 ; V_13 ++ )
V_11 -> V_23 [ V_13 ] = V_7 [ 4 + V_13 ] ;
} else {
V_11 -> V_18 = V_14 ;
if ( V_7 [ 1 ] )
V_11 -> V_19 = V_20 ;
else
V_11 -> V_19 = V_21 ;
}
return V_6 -> V_24 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_25 ,
unsigned int * V_26 ,
char V_27 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_13 ;
unsigned int V_28 ;
unsigned short V_29 ;
if ( V_25 < 1 ) {
if ( ! V_27 )
F_6 ( V_2 , L_2 ) ;
return 0 ;
}
if ( V_27 )
return 1 ;
V_11 -> V_30 =
V_11 -> V_30 & V_31 ;
V_11 -> V_30 = ( ( V_25 - 1 ) & 0xf ) << 8 ;
F_7 ( V_11 -> V_30 , V_2 -> V_32 + V_33 ) ;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
V_29 = F_3 ( V_26 [ V_13 ] ) ;
if ( F_8 ( V_26 [ V_13 ] ) < V_34 )
V_29 &= ( ( ~ V_35 ) & 0xff ) ;
else
V_29 |= V_35 ;
V_28 = F_8 ( V_26 [ V_13 ] ) ;
V_29 |= ( ( V_28 & 0x03 ) << 4 ) ;
V_29 |= V_13 << 8 ;
F_7 ( V_29 , V_2 -> V_32 + V_36 ) ;
F_4 ( L_3 ,
( ( ( unsigned char ) F_8 ( V_26 [ V_13 ] ) & 0x03 ) << 2 ) ) ;
F_4 ( L_4 , F_3 ( V_26 [ V_13 ] ) ) ;
F_4 ( L_5 , V_29 & V_35 ) ;
}
return 1 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned short V_37 , V_29 , V_13 ;
unsigned char V_38 ;
if ( ! V_11 -> V_16 ) {
F_4 ( L_6 ) ;
V_37 = 10 ;
} else
V_37 = ( unsigned short ) ( V_11 -> V_16 / 1000 ) ;
V_11 -> V_39 = 0 ;
V_11 -> V_40 = 0 ;
V_11 -> V_30 = 0 ;
if ( V_6 -> V_41 [ 0 ] == 222 ) {
for ( V_13 = 0 ; V_13 < V_6 -> V_24 ; V_13 ++ )
V_7 [ V_13 ] = V_11 -> V_42 [ V_13 ] ;
} else {
V_11 -> V_43 = V_44 ;
V_29 =
( unsigned short ) F_10 ( V_11 -> V_32 + V_45 ) ;
if ( ( V_29 & 0x00B0 ) == 0x00B0
|| ! strcmp ( V_9 -> V_46 , L_7 ) ) {
V_37 = ( V_37 * 2 ) - 2 ;
} else {
V_37 =
( ( V_37 * 12926 ) / 10000 ) - 1 ;
}
V_29 = ( unsigned short ) V_11 -> V_18 ;
switch ( V_29 ) {
case V_14 :
F_10 ( V_11 -> V_32 + V_47 ) ;
if ( ! F_5 ( V_2 , V_4 , 1 ,
& V_6 -> V_48 , 0 ) )
return - V_49 ;
V_11 -> V_39 =
( V_11 ->
V_39 & 0xFC ) |
V_50 ;
F_11 ( V_11 -> V_39 ,
V_11 -> V_32 + V_51 ) ;
V_11 -> V_40 =
V_11 ->
V_40 & V_52 ;
if ( V_11 -> V_19 == V_20 ) {
V_11 -> V_40 =
( V_11 ->
V_40 &
V_53 ) |
V_54 ;
F_10 ( V_11 -> V_32 ) ;
} else {
V_11 -> V_40 =
V_11 ->
V_40 &
V_55 ;
}
F_11 ( V_11 -> V_40 ,
V_11 -> V_32 + V_56 ) ;
V_11 -> V_30 =
( V_11 ->
V_30 & V_31 ) |
V_57 ;
F_7 ( V_11 -> V_30 ,
V_11 -> V_32 + V_33 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_59 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
F_7 ( V_37 ,
V_11 -> V_32 + V_61 ) ;
V_29 =
( unsigned short ) F_10 ( V_2 -> V_32 + V_45 ) ;
if ( V_11 -> V_19 == V_21 ) {
do {
V_29 =
F_10 ( V_11 -> V_32 +
V_45 ) ;
} while ( ( V_29 & V_62 ) ==
V_62 );
V_29 = F_10 ( V_11 -> V_32 + 0 ) ;
* V_7 = V_29 ;
F_10 ( V_11 -> V_32 + V_47 ) ;
}
break;
case V_15 :
F_10 ( V_11 -> V_32 ) ;
F_10 ( V_11 -> V_32 + V_47 ) ;
V_11 -> V_30 =
( V_11 ->
V_30 & V_31 ) |
V_63 ;
F_7 ( V_11 -> V_30 ,
V_11 -> V_32 + V_33 ) ;
if ( ! F_5 ( V_2 , V_4 ,
V_11 -> V_22 ,
V_11 -> V_23 , 0 ) )
return - V_49 ;
V_11 -> V_39 =
( V_11 ->
V_39 & 0xFC ) |
V_64 ;
F_11 ( V_11 -> V_39 ,
V_11 -> V_32 + V_51 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_59 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
F_7 ( V_37 ,
V_11 -> V_32 + V_61 ) ;
V_11 -> V_40 =
V_11 ->
V_40 | V_65 ;
F_11 ( V_11 -> V_40 ,
V_11 -> V_32 + V_56 ) ;
if ( V_11 -> V_19 == V_20 ) {
V_11 -> V_40 =
( V_11 ->
V_40 &
V_66 ) |
V_67 ;
F_10 ( V_11 -> V_32 ) ;
} else
V_11 -> V_40 =
V_11 ->
V_40 &
V_55 ;
F_11 ( V_11 -> V_40 ,
V_11 -> V_32 + V_56 ) ;
F_10 ( V_11 -> V_32 + V_45 ) ;
V_11 -> V_30 =
V_11 ->
V_30 | V_57 ;
F_7 ( V_11 -> V_30 ,
V_11 -> V_32 + V_33 ) ;
F_7 ( 0 , V_11 -> V_32 + V_68 ) ;
if ( V_11 -> V_19 == V_21 ) {
do {
V_29 =
F_10 ( V_11 -> V_32 +
V_45 ) ;
} while ( ( V_29 & V_69 ) !=
V_69 );
for ( V_13 = 0 ; V_13 < V_11 -> V_22 ;
V_13 ++ ) {
V_29 = F_10 ( V_11 -> V_32 ) ;
V_7 [ V_13 ] = ( unsigned int ) V_29 ;
}
V_11 -> V_18 = V_14 ;
}
break;
default:
F_4 ( L_8 ) ;
}
V_11 -> V_16 = 0 ;
}
return V_6 -> V_24 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_13 ;
unsigned short V_29 ;
V_11 -> V_70 = 0 ;
V_11 -> V_19 = V_21 ;
V_11 -> V_18 = V_14 ;
V_11 -> V_16 = 0 ;
V_11 -> V_71 = 0 ;
V_11 -> V_72 = 0 ;
V_11 -> V_73 = 0 ;
V_11 -> V_40 = 0 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
V_11 -> V_30 = 0 ;
F_7 ( V_11 -> V_30 , V_2 -> V_32 + V_33 ) ;
F_7 ( 8191 | V_74 , V_2 -> V_32 + V_75 ) ;
F_7 ( 8191 | V_76 , V_2 -> V_32 + V_75 ) ;
F_7 ( 8191 | V_77 , V_2 -> V_32 + V_75 ) ;
F_7 ( 8191 | V_78 , V_2 -> V_32 + V_75 ) ;
F_7 ( 8191 | V_79 , V_2 -> V_32 + V_80 ) ;
F_7 ( 8191 | V_81 , V_2 -> V_32 + V_80 ) ;
F_7 ( 8191 | V_82 , V_2 -> V_32 + V_80 ) ;
F_7 ( 8191 | V_83 , V_2 -> V_32 + V_80 ) ;
F_13 ( 10 ) ;
F_10 ( V_2 -> V_32 + 0 ) ;
F_14 ( V_2 -> V_32 + V_47 ) ;
F_10 ( V_2 -> V_32 + V_45 ) ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ ) {
V_29 = V_13 << 8 ;
F_7 ( V_29 , V_2 -> V_32 + V_36 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_30 |= V_84 ;
F_7 ( V_11 -> V_30 , V_2 -> V_32 + V_33 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_30 &= ~ V_84 ;
F_7 ( V_11 -> V_30 , V_2 -> V_32 + V_33 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
F_7 ( 0 , V_11 -> V_85 + 4 ) ;
F_7 ( V_86 , V_11 -> V_85 + 0 ) ;
F_7 ( 0 , V_11 -> V_85 + 2 ) ;
F_7 ( V_87 , V_11 -> V_85 + 0 ) ;
F_7 ( 0 , V_11 -> V_85 + 2 ) ;
F_18 ( 0 , V_11 -> V_88 + V_89 ) ;
F_16 ( V_2 ) ;
V_11 -> V_30 = 0 ;
F_7 ( V_11 ->
V_30 & V_63 &
V_90 , V_2 -> V_32 + V_33 ) ;
F_7 ( V_91 , V_2 -> V_32 + V_33 ) ;
F_11 ( V_92 ,
V_2 -> V_32 + V_56 ) ;
F_14 ( V_2 -> V_32 + V_47 ) ;
F_10 ( V_2 -> V_32 + V_45 ) ;
V_11 -> V_93 = 0 ;
V_4 -> V_94 -> V_95 = 0 ;
V_11 -> V_96 = 0 ;
V_11 -> V_70 = 0 ;
V_11 -> V_18 = V_14 ;
V_11 -> V_19 = V_21 ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_97 * V_98 )
{
int V_99 = 0 ;
V_99 |= F_20 ( & V_98 -> V_100 , V_101 | V_102 ) ;
V_99 |= F_20 ( & V_98 -> V_103 ,
V_104 | V_105 ) ;
V_99 |= F_20 ( & V_98 -> V_106 , V_104 ) ;
V_99 |= F_20 ( & V_98 -> V_107 , V_108 ) ;
V_99 |= F_20 ( & V_98 -> V_109 , V_108 | V_110 ) ;
if ( V_99 )
return 1 ;
V_99 |= F_21 ( V_98 -> V_100 ) ;
V_99 |= F_21 ( V_98 -> V_103 ) ;
V_99 |= F_21 ( V_98 -> V_109 ) ;
if ( V_99 )
return 2 ;
V_99 |= F_22 ( & V_98 -> V_111 , 0 ) ;
if ( V_98 -> V_103 == V_104 )
V_99 |= F_23 ( & V_98 -> V_112 , 100000 ) ;
if ( V_98 -> V_103 == V_104 ) {
if ( V_98 -> V_113 )
V_99 |= F_23 ( & V_98 -> V_113 ,
10000 ) ;
} else {
V_99 |= F_23 ( & V_98 -> V_113 , 10000 ) ;
}
V_99 |= F_23 ( & V_98 -> V_114 , 1 ) ;
V_99 |= F_22 ( & V_98 -> V_115 , V_98 -> V_114 ) ;
if ( V_98 -> V_109 == V_108 )
V_99 |= F_23 ( & V_98 -> V_116 , 1 ) ;
else
V_99 |= F_22 ( & V_98 -> V_116 , 0 ) ;
if ( V_99 )
return 3 ;
if ( V_98 -> V_103 == V_104 &&
V_98 -> V_112 < V_98 -> V_113 * V_98 -> V_115 ) {
V_98 -> V_112 = V_98 -> V_113 * V_98 -> V_115 ;
V_99 |= - V_49 ;
}
if ( V_99 )
return 4 ;
return 0 ;
}
static int F_24 ( int V_117 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_97 * V_98 = & V_4 -> V_94 -> V_98 ;
unsigned char V_38 ;
unsigned int V_118 , V_119 = 0 , V_120 = 0 , V_121 =
0 , V_122 = 0 , V_123 =
0 , V_124 , V_125 ;
unsigned short V_29 ;
F_14 ( V_2 -> V_32 + V_47 ) ;
V_11 -> V_70 = 1 ;
V_11 -> V_39 = 0 ;
V_11 -> V_30 = 0 ;
V_11 -> V_40 = 0 ;
F_18 ( V_126 ,
V_11 -> V_88 + V_127 ) ;
V_11 -> V_30 = V_11 -> V_30 &
V_63 &
V_90 & V_31 ;
F_7 ( V_11 -> V_30 , V_2 -> V_32 + V_33 ) ;
F_14 ( V_11 -> V_32 + V_47 ) ;
V_11 -> V_93 = 0 ;
V_4 -> V_94 -> V_95 = 0 ;
V_11 -> V_96 = 0 ;
V_123 = V_98 -> V_116 - 2 ;
V_125 = V_98 -> V_113 ;
if ( V_117 == 2 )
V_119 = V_98 -> V_112 ;
if ( ! F_5 ( V_2 , V_4 , V_11 -> V_22 ,
V_98 -> V_26 , 0 ) )
return - V_49 ;
V_29 = ( unsigned short ) F_10 ( V_2 -> V_32 + V_45 ) ;
if ( ( V_29 & 0x00B0 ) == 0x00B0
|| ! strcmp ( V_9 -> V_46 , L_7 ) ) {
V_124 = V_125 * 2 - 2000 ;
V_124 = V_124 / 1000 ;
if ( V_117 == 2 ) {
V_119 = V_119 / 1000 ;
V_120 = V_119 * 2 - 200 ;
V_120 = V_120 / 100 ;
}
} else {
V_125 = V_125 / 1000 ;
V_124 = V_125 * 12926 - 10000 ;
V_124 = V_124 / 10000 ;
if ( V_117 == 2 ) {
V_119 = V_119 / 1000 ;
V_120 = V_119 * 12926 - 1 ;
V_120 = V_120 / 1000000 ;
}
}
if ( V_11 -> V_73 == V_20 )
F_15 ( V_2 ) ;
switch ( V_117 ) {
case 1 :
V_11 -> V_39 =
( V_11 ->
V_39 & 0xFC ) | V_64 ;
F_11 ( V_11 -> V_39 ,
V_2 -> V_32 + V_51 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_59 ;
F_11 ( V_38 , V_2 -> V_32 + V_60 ) ;
F_7 ( ( ( unsigned short ) V_124 ) ,
V_2 -> V_32 + V_61 ) ;
break;
case 2 :
V_11 -> V_39 =
( V_11 ->
V_39 & 0xF3 ) | V_128 ;
F_11 ( V_11 -> V_39 ,
V_2 -> V_32 + V_51 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_129 ;
F_11 ( V_38 , V_2 -> V_32 + V_60 ) ;
F_7 ( ( ( unsigned short ) V_120 ) ,
V_2 -> V_32 + V_61 ) ;
V_11 -> V_39 =
( V_11 ->
V_39 & 0xFC ) | V_64 ;
F_11 ( V_11 -> V_39 ,
V_2 -> V_32 + V_51 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_59 ;
F_11 ( V_38 , V_2 -> V_32 + V_60 ) ;
F_7 ( ( ( unsigned short ) V_124 ) ,
V_2 -> V_32 + V_61 ) ;
break;
}
V_11 -> V_40 = V_11 -> V_40 &
V_52 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
if ( V_11 -> V_130 == V_21 ) {
V_11 -> V_18 = V_15 ;
V_11 -> V_19 = V_20 ;
V_11 -> V_40 =
( V_11 ->
V_40 & V_66 ) |
V_67 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
if ( V_98 -> V_109 == V_108 ) {
V_11 -> V_30 =
V_11 ->
V_30 & V_131 ;
F_7 ( V_11 -> V_30 ,
V_2 -> V_32 + V_33 ) ;
V_11 -> V_40 =
V_11 ->
V_40 &
V_132 & 0xEF ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
V_11 -> V_39 =
( V_11 ->
V_39 & 0x0F ) |
V_133 ;
F_11 ( V_11 -> V_39 ,
V_2 -> V_32 + V_51 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_134 ;
F_11 ( V_38 , V_2 -> V_32 + V_60 ) ;
F_7 ( F_25 ( V_123 ) ,
V_2 -> V_32 + V_61 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_135 ;
F_11 ( V_38 , V_2 -> V_32 + V_60 ) ;
F_7 ( F_26 ( V_123 ) ,
V_2 -> V_32 + V_61 ) ;
F_14 ( V_2 -> V_32 + V_136 ) ;
V_11 -> V_40 =
( V_11 ->
V_40 |
V_137 ) &
V_138 ;
V_11 -> V_40 =
V_11 ->
V_40 |
V_139 ;
V_11 -> V_40 =
V_11 ->
V_40 |
V_140 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
V_11 -> V_71 = V_141 ;
V_11 -> V_72 = V_20 ;
}
} else {
unsigned int V_142 = V_98 -> V_115 * sizeof( short ) ;
V_11 -> V_18 = V_143 ;
V_11 -> V_40 = V_11 -> V_40 &
V_66 & V_53 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
V_121 = V_11 -> V_144 [ 0 ] ;
V_122 = V_11 -> V_144 [ 1 ] ;
if ( V_98 -> V_109 == V_108 ) {
if ( V_121 > ( V_98 -> V_116 * V_142 ) ) {
V_121 = V_98 -> V_116 * V_142 ;
} else if ( V_122 > ( V_98 -> V_116 * V_142 -
V_121 ) )
V_122 = V_98 -> V_116 * V_142 -
V_121 ;
}
if ( V_98 -> V_145 & V_146 ) {
if ( V_121 > V_142 ) {
V_121 = V_142 ;
if ( V_98 -> V_115 & 1 )
V_121 += 2 ;
}
if ( V_122 > V_142 ) {
V_122 = V_142 ;
if ( V_98 -> V_115 & 1 )
V_122 -= 2 ;
if ( V_122 < 4 )
V_122 = 4 ;
}
} else {
if ( V_121 > V_4 -> V_94 -> V_147 )
V_121 = V_4 -> V_94 -> V_147 ;
if ( V_122 > V_4 -> V_94 -> V_147 )
V_122 = V_4 -> V_94 -> V_147 ;
}
V_11 -> V_148 [ 0 ] = V_121 ;
V_11 -> V_148 [ 1 ] = V_122 ;
V_118 = V_149 | V_150 ;
F_18 ( V_118 , V_11 -> V_88 + V_151 ) ;
F_7 ( V_86 , V_11 -> V_85 + 0 ) ;
F_7 ( V_152 ,
V_11 -> V_85 + 2 ) ;
F_7 ( V_87 , V_11 -> V_85 + 0 ) ;
F_7 ( V_153 ,
V_11 -> V_85 + 2 ) ;
F_7 ( 0x1000 , V_11 -> V_85 + 2 ) ;
F_18 ( V_154 , V_11 -> V_88 +
V_155 ) ;
F_7 ( V_156 , V_11 -> V_85 + 0 ) ;
F_7 ( ( V_11 -> V_157 [ 0 ] & 0xFFFF ) ,
V_11 -> V_85 + 2 ) ;
F_7 ( V_158 , V_11 -> V_85 + 0 ) ;
F_7 ( ( V_11 -> V_157 [ 0 ] / 65536 ) ,
V_11 -> V_85 + 2 ) ;
F_7 ( V_159 , V_11 -> V_85 + 0 ) ;
F_7 ( ( V_11 -> V_148 [ 0 ] & 0xFFFF ) ,
V_11 -> V_85 + 2 ) ;
F_7 ( V_160 , V_11 -> V_85 + 0 ) ;
F_7 ( ( V_11 -> V_148 [ 0 ] / 65536 ) ,
V_11 -> V_85 + 2 ) ;
F_18 ( 0x04000000UL , V_11 -> V_88 + V_89 ) ;
F_18 ( ( V_161 |
V_162 ) ,
V_11 -> V_88 + V_163 ) ;
F_7 ( 3 , V_11 -> V_85 + 4 ) ;
F_18 ( 0x04000000UL ,
V_11 -> V_88 + V_155 ) ;
}
if ( V_11 -> V_130 == V_21 &&
V_98 -> V_109 == V_108 ) {
V_11 -> V_30 =
V_11 -> V_30 | V_164 ;
F_7 ( V_11 -> V_30 ,
V_2 -> V_32 + V_33 ) ;
}
switch ( V_117 ) {
case 1 :
V_11 -> V_30 =
V_11 -> V_30 | V_57 ;
F_7 ( V_11 -> V_30 ,
V_2 -> V_32 + V_33 ) ;
break;
case 2 :
V_11 -> V_30 =
V_11 -> V_30 | V_165 ;
V_11 -> V_30 =
V_11 -> V_30 | V_57 ;
F_7 ( V_11 -> V_30 ,
V_2 -> V_32 + V_33 ) ;
break;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_97 * V_98 = & V_4 -> V_94 -> V_98 ;
V_11 -> V_22 = V_98 -> V_114 ;
if ( V_98 -> V_100 == V_102 )
V_11 -> V_73 = V_20 ;
else
V_11 -> V_73 = V_21 ;
if ( V_98 -> V_103 == V_105 )
return F_24 ( 1 , V_2 , V_4 ) ;
else
return F_24 ( 2 , V_2 , V_4 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned short * V_166 ,
unsigned int V_167 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_97 * V_98 = & V_4 -> V_94 -> V_98 ;
V_11 -> V_93 +=
( V_4 -> V_94 -> V_95 + V_167 ) / V_98 -> V_115 ;
V_4 -> V_94 -> V_95 += V_167 ;
V_4 -> V_94 -> V_95 %= V_98 -> V_115 ;
F_29 ( V_4 , V_166 , V_167 * sizeof( short ) ) ;
}
static void F_30 ( int V_168 , void * V_169 )
{
struct V_1 * V_2 = V_169 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_3 * V_4 = V_2 -> V_170 ;
struct V_97 * V_98 = & V_4 -> V_94 -> V_98 ;
unsigned int V_171 , V_172 ;
unsigned long V_173 , V_174 , V_175 ;
unsigned int V_118 ;
V_172 =
V_11 -> V_148 [ V_11 -> V_96 ] -
F_31 ( V_11 -> V_88 + V_176 ) ;
if ( V_172 <
V_11 -> V_148 [ V_11 -> V_96 ] ) {
F_6 ( V_2 , L_9 ) ;
}
if ( V_172 & 1 ) {
F_6 ( V_2 , L_10 ) ;
F_17 ( V_2 , V_4 ) ;
return;
}
V_172 = V_172 >> 1 ;
if ( V_11 -> V_177 ) {
V_171 = 1 - V_11 -> V_96 ;
V_118 = V_149 | V_150 ;
F_18 ( V_118 , V_11 -> V_85 + V_151 ) ;
F_7 ( V_86 , V_11 -> V_85 + 0 ) ;
F_7 ( V_152 ,
V_11 -> V_85 + 2 ) ;
F_7 ( V_87 , V_11 -> V_85 + 0 ) ;
F_7 ( V_153 , V_11 -> V_85 + 2 ) ;
V_175 = V_11 -> V_157 [ V_171 ] ;
V_173 = V_175 & 0xffff ;
V_175 = V_11 -> V_157 [ V_171 ] ;
V_174 = V_175 / 65536 ;
F_7 ( V_156 , V_11 -> V_85 + 0 ) ;
F_7 ( V_173 , V_11 -> V_85 + 2 ) ;
F_7 ( V_158 , V_11 -> V_85 + 0 ) ;
F_7 ( V_174 , V_11 -> V_85 + 2 ) ;
V_175 = V_11 -> V_148 [ V_171 ] ;
V_173 = V_175 & 0xffff ;
V_175 = V_11 -> V_148 [ V_171 ] ;
V_174 = V_175 / 65536 ;
F_7 ( V_159 , V_11 -> V_85 + 0 ) ;
F_7 ( V_173 , V_11 -> V_85 + 2 ) ;
F_7 ( V_160 , V_11 -> V_85 + 0 ) ;
F_7 ( V_174 , V_11 -> V_85 + 2 ) ;
F_7 ( 3 , V_11 -> V_85 + 4 ) ;
F_18 ( ( V_161 |
V_162 ) ,
V_11 -> V_88 + V_163 ) ;
}
if ( V_172 ) {
F_28 ( V_2 , V_4 ,
V_11 -> V_178 [ V_11 ->
V_96 ] , V_172 ) ;
if ( ! ( V_98 -> V_145 & V_146 ) ) {
V_4 -> V_94 -> V_179 |= V_180 ;
F_32 ( V_2 , V_4 ) ;
}
}
if ( V_98 -> V_109 == V_108 )
if ( V_11 -> V_93 >= V_98 -> V_116 ) {
F_17 ( V_2 , V_4 ) ;
V_4 -> V_94 -> V_179 |= V_181 ;
F_32 ( V_2 , V_4 ) ;
return;
}
if ( V_11 -> V_177 ) {
V_11 -> V_96 = 1 - V_11 -> V_96 ;
} else {
V_118 = V_149 | V_150 ;
F_18 ( V_118 , V_11 -> V_85 + V_151 ) ;
F_7 ( V_86 , V_11 -> V_85 + 0 ) ;
F_7 ( V_152 ,
V_11 -> V_85 + 2 ) ;
F_7 ( V_87 , V_11 -> V_85 + 0 ) ;
F_7 ( V_153 , V_11 -> V_85 + 2 ) ;
F_18 ( V_154 ,
V_11 -> V_88 + V_89 ) ;
V_175 = V_11 -> V_157 [ 0 ] ;
V_173 = V_175 & 0xffff ;
V_175 = V_11 -> V_157 [ 0 ] ;
V_174 = V_175 / 65536 ;
F_7 ( V_156 , V_11 -> V_85 + 0 ) ;
F_7 ( V_173 , V_11 -> V_85 + 2 ) ;
F_7 ( V_158 , V_11 -> V_85 + 0 ) ;
F_7 ( V_174 , V_11 -> V_85 + 2 ) ;
V_175 = V_11 -> V_148 [ 0 ] ;
V_173 = V_175 & 0xffff ;
V_175 = V_11 -> V_148 [ 0 ] ;
V_174 = V_175 / 65536 ;
F_7 ( V_159 , V_11 -> V_85 + 0 ) ;
F_7 ( V_173 , V_11 -> V_85 + 2 ) ;
F_7 ( V_160 , V_11 -> V_85 + 0 ) ;
F_7 ( V_174 , V_11 -> V_85 + 2 ) ;
F_7 ( 3 , V_11 -> V_85 + 4 ) ;
F_18 ( ( V_161 |
V_162 ) ,
V_11 -> V_88 + V_163 ) ;
}
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_3 * V_4 = V_2 -> V_170 ;
int V_25 , V_13 ;
int V_99 = 1 ;
V_25 = V_11 -> V_22 ;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ )
V_99 &= F_34 ( V_4 , F_10 ( V_2 -> V_32 + 0 ) ) ;
V_4 -> V_94 -> V_179 |= V_180 ;
if ( V_99 == 0 )
V_4 -> V_94 -> V_179 |= V_182 ;
F_32 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_35 ( int V_168 , void * V_169 )
{
struct V_1 * V_2 = V_169 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_3 * V_4 = V_2 -> V_170 ;
unsigned short V_183 ;
unsigned int V_184 , V_185 , V_13 ;
unsigned short V_29 ;
unsigned char V_186 ;
V_185 = 1 ;
V_183 = F_10 ( V_2 -> V_32 + V_45 ) & 0xf000 ;
V_184 = F_31 ( V_11 -> V_88 + V_163 ) ;
if ( ( ! V_183 ) && ( ! ( V_184 & V_187 ) ) ) {
F_6 ( V_2 , L_11 ) ;
return;
}
F_18 ( V_184 | 0x00ff0000 , V_11 -> V_88 + V_163 ) ;
V_183 = ( V_183 >> 12 ) & 0xF ;
if ( V_11 -> V_73 == V_20 ) {
F_16 ( V_2 ) ;
V_11 -> V_73 = V_21 ;
}
F_14 ( V_11 -> V_88 + V_136 ) ;
if ( V_184 & V_188 )
F_6 ( V_2 , L_12 ) ;
if ( V_184 & V_189 )
F_6 ( V_2 , L_13 ) ;
if ( ( ( V_183 & 0x8 ) == 0 )
&& ( V_11 -> V_18 == V_14 ) ) {
if ( V_11 -> V_19 == V_20 ) {
V_11 -> V_42 [ 0 ] =
( unsigned int ) F_10 ( V_11 -> V_32 + 0 ) ;
V_11 -> V_19 = V_21 ;
F_36 ( V_190 , V_11 -> V_43 , 0 ) ;
} else {
V_11 -> V_40 =
V_11 ->
V_40 & V_66 ;
F_11 ( V_11 -> V_40 ,
V_11 -> V_32 + V_56 ) ;
}
}
if ( ( V_183 & 0x2 ) && ( V_11 -> V_18 == V_15 ) ) {
if ( V_11 -> V_19 == V_20 ) {
if ( V_11 -> V_70 ) {
V_185 = 0 ;
F_33 ( V_2 ) ;
V_11 -> V_93 ++ ;
V_11 -> V_40 =
V_11 ->
V_40 |
V_67 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 +
V_56 ) ;
} else {
V_185 = 0 ;
for ( V_13 = 0 ; V_13 < V_11 -> V_22 ;
V_13 ++ ) {
V_29 = F_10 ( V_11 -> V_32 + 0 ) ;
V_11 -> V_42 [ V_13 ] =
( unsigned int ) V_29 ;
}
V_11 -> V_19 = V_21 ;
V_11 -> V_18 = V_14 ;
F_36 ( V_190 , V_11 -> V_43 , 0 ) ;
}
} else {
V_11 -> V_40 =
V_11 ->
V_40 & V_53 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
V_11 -> V_19 = V_21 ;
V_11 -> V_18 = V_14 ;
}
}
if ( V_183 & 0x1 ) {
switch ( V_11 -> V_71 ) {
case V_141 :
V_11 -> V_40 =
V_11 ->
V_40 & V_53 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
V_11 -> V_30 =
V_11 ->
V_30 & V_91 ;
F_7 ( V_11 -> V_30 ,
V_2 -> V_32 + V_33 ) ;
F_17 ( V_2 , V_4 ) ;
V_4 -> V_94 -> V_179 |= V_181 ;
F_32 ( V_2 , V_4 ) ;
break;
case V_191 :
F_36 ( V_190 , V_11 -> V_43 , 0 ) ;
break;
case V_192 :
F_36 ( V_190 , V_11 -> V_43 , 0 ) ;
break;
default:
V_11 -> V_40 =
V_11 ->
V_40 &
V_132 ;
F_11 ( V_11 -> V_40 ,
V_2 -> V_32 + V_56 ) ;
}
V_186 = F_14 ( V_2 -> V_32 + V_136 ) ;
}
if ( ( V_183 & 0x4 ) && ( V_11 -> V_18 == V_143 ) ) {
if ( V_11 -> V_70 ) {
F_18 ( V_126 ,
V_11 -> V_88 +
V_127 ) ;
F_10 ( V_2 -> V_32 + V_136 ) ;
F_30 ( V_168 , V_169 ) ;
} else {
F_7 ( V_11 ->
V_30 & V_63 &
V_90 ,
V_2 -> V_32 + V_33 ) ;
}
}
return;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_193 ;
unsigned short V_29 ;
unsigned char V_38 ;
if ( ! V_7 [ 1 ] )
F_6 ( V_2 , L_14 ) ;
V_11 -> V_72 = ( unsigned char ) V_7 [ 2 ] ;
V_193 = V_7 [ 1 ] / 1000 ;
V_29 = ( unsigned short ) F_10 ( V_11 -> V_32 + V_45 ) ;
if ( ( V_29 & 0x00B0 ) == 0x00B0
|| ! strcmp ( V_9 -> V_46 , L_7 ) ) {
V_193 = V_193 / 50 ;
} else {
V_193 = V_193 / 70 ;
}
V_11 -> V_30 =
V_11 -> V_30 & V_131 ;
F_7 ( V_11 -> V_30 , V_11 -> V_32 + V_33 ) ;
V_11 -> V_40 =
V_11 ->
V_40 & V_132 & 0xEF ;
V_11 -> V_40 =
V_11 ->
V_40 & V_66 &
V_53 ;
F_11 ( V_11 -> V_40 ,
V_11 -> V_32 + V_56 ) ;
if ( V_7 [ 0 ] == V_191 ) {
V_11 -> V_39 =
( V_11 ->
V_39 & 0x0F ) | V_194 ;
F_11 ( V_11 -> V_39 ,
V_11 -> V_32 + V_51 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_134 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
F_7 ( F_25 ( V_193 ) ,
V_11 -> V_32 + V_61 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_135 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
F_7 ( F_26 ( V_193 ) ,
V_11 -> V_32 + V_61 ) ;
V_11 -> V_71 = V_191 ;
} else {
V_11 -> V_39 =
( V_11 ->
V_39 & 0x0F ) | V_195 ;
F_11 ( V_11 -> V_39 ,
V_11 -> V_32 + V_51 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_134 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
F_7 ( F_25 ( V_193 ) ,
V_11 -> V_32 + V_61 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_135 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
F_7 ( F_26 ( V_193 ) ,
V_11 -> V_32 + V_61 ) ;
V_11 -> V_71 = V_192 ;
}
return V_6 -> V_24 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_193 = 0 ;
unsigned short V_29 ;
unsigned char V_38 ;
if ( ( V_11 -> V_71 != V_192 )
&& ( V_11 -> V_71 != V_191 ) ) {
F_6 ( V_2 , L_15 ) ;
return - V_49 ;
}
if ( V_7 [ 0 ] == 2 ) {
if ( V_11 -> V_71 != V_191 ) {
F_6 ( V_2 ,
L_16 ) ;
return - V_49 ;
}
if ( V_7 [ 1 ] )
V_193 = V_7 [ 1 ] ;
else
V_193 = 0 ;
}
switch ( V_7 [ 0 ] ) {
case V_196 :
F_14 ( V_11 -> V_32 + V_136 ) ;
if ( V_11 -> V_71 == V_191 ) {
V_11 -> V_40 =
V_11 -> V_40 & 0x0B ;
} else {
V_11 -> V_40 =
( V_11 ->
V_40 & 0x0B ) |
V_197 ;
}
if ( ( V_11 -> V_72 ) == V_20 ) {
V_11 -> V_40 =
V_11 ->
V_40 |
V_140 ;
V_11 -> V_43 = V_44 ;
} else {
V_11 -> V_40 =
V_11 ->
V_40 &
V_132 ;
}
F_11 ( V_11 -> V_40 ,
V_11 -> V_32 + V_56 ) ;
if ( V_11 -> V_71 == V_191 ) {
V_11 -> V_30 =
V_11 ->
V_30 | V_164 ;
F_7 ( V_11 -> V_30 ,
V_11 -> V_32 + V_33 ) ;
}
break;
case V_198 :
if ( V_11 -> V_71 == V_191 ) {
V_11 -> V_40 =
V_11 ->
V_40 &
V_199 ;
} else {
V_11 -> V_40 =
V_11 ->
V_40 &
V_138 ;
}
V_11 -> V_40 =
V_11 ->
V_40 & V_132 ;
F_11 ( V_11 -> V_40 ,
V_11 -> V_32 + V_56 ) ;
V_11 -> V_30 =
V_11 -> V_30 & V_132 ;
F_7 ( V_11 -> V_30 ,
V_11 -> V_32 + V_33 ) ;
F_14 ( V_11 -> V_32 + V_136 ) ;
break;
case 2 :
if ( V_11 -> V_71 != V_191 ) {
F_6 ( V_2 ,
L_16 ) ;
return - V_49 ;
}
V_29 =
( unsigned short ) F_10 ( V_11 -> V_32 + V_45 ) ;
if ( ( V_29 & 0x00B0 ) == 0x00B0
|| ! strcmp ( V_9 -> V_46 , L_7 ) ) {
V_193 = V_193 / 50 ;
} else {
V_193 = V_193 / 70 ;
}
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_134 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
F_7 ( F_25 ( V_193 ) ,
V_11 -> V_32 + V_61 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_135 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
F_7 ( F_26 ( V_193 ) ,
V_11 -> V_32 + V_61 ) ;
break;
default:
return - V_49 ;
}
return V_6 -> V_24 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned char V_38 ;
unsigned short V_29 , V_200 , V_201 ;
if ( ( V_11 -> V_71 != V_192 )
&& ( V_11 -> V_71 != V_191 ) ) {
F_6 ( V_2 , L_17 ) ;
}
if ( V_11 -> V_71 == V_191 ) {
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_134 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
V_29 = F_10 ( V_11 -> V_32 + V_61 ) ;
V_38 = ( ( V_11 ->
V_58 ) & 0xF0 ) |
V_135 ;
F_11 ( V_38 , V_11 -> V_32 + V_60 ) ;
V_200 = F_10 ( V_11 -> V_32 + V_61 ) ;
V_7 [ 0 ] = ( unsigned int ) ( ( V_29 ) | ( ( V_200 ) << 16 ) ) ;
} else {
V_201 = F_10 ( V_11 -> V_32 + V_45 ) ;
V_201 =
( ( V_201 & V_202 ) >> 12 ) & 1 ;
if ( V_201 == 1 ) {
F_14 ( V_11 -> V_32 + V_136 ) ;
}
V_7 [ 0 ] = V_201 ;
}
return V_6 -> V_24 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_203 ;
V_203 = F_10 ( V_11 -> V_32 + V_45 ) ;
V_7 [ 1 ] = ( V_203 >> 8 ) & 0xf ;
return V_6 -> V_24 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
if ( F_42 ( V_4 , V_7 ) ) {
V_11 -> V_58 = V_4 -> V_204 << 4 ;
F_11 ( V_11 -> V_58 ,
V_11 -> V_32 + V_205 ) ;
}
V_7 [ 1 ] = V_4 -> V_204 ;
return V_6 -> V_24 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_206 , V_207 ;
unsigned short V_29 ;
V_206 = F_8 ( V_6 -> V_48 ) ;
V_207 = F_3 ( V_6 -> V_48 ) ;
if ( V_206 ) {
if ( V_7 [ 0 ] != 0 )
V_7 [ 0 ] =
( ( ( ( V_207 & 0x03 ) << 14 ) & 0xC000 ) | ( 1 <<
13 ) | ( V_7 [ 0 ] + 8191 ) ) ;
else
V_7 [ 0 ] =
( ( ( ( V_207 & 0x03 ) << 14 ) & 0xC000 ) | ( 1 <<
13 ) | 8192 ) ;
} else {
V_7 [ 0 ] =
( ( ( ( V_207 & 0x03 ) << 14 ) & 0xC000 ) | ( 0 << 13 ) |
V_7 [ 0 ] ) ;
}
do {
V_29 =
( ( unsigned short ) F_10 ( V_11 -> V_32 +
V_45 ) ) & 0x0001 ;
} while ( V_29 != 0x0001 );
if ( V_207 <= 3 )
F_7 ( ( unsigned short ) V_7 [ 0 ] ,
V_11 -> V_32 + V_75 ) ;
else
F_7 ( ( unsigned short ) V_7 [ 0 ] ,
V_11 -> V_32 + V_80 ) ;
return V_6 -> V_24 ;
}
