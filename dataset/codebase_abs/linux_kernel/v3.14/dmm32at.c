static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 , V_9 ;
unsigned int V_10 ;
unsigned char V_11 ;
unsigned short V_12 , V_13 ;
unsigned char V_14 ;
int V_15 ;
V_14 = F_2 ( V_6 -> V_16 ) & ( V_4 -> V_17 - 1 ) ;
V_15 = F_3 ( V_6 -> V_16 ) ;
F_4 ( V_18 , V_2 -> V_19 + V_20 ) ;
F_4 ( V_14 , V_2 -> V_19 + V_21 ) ;
F_4 ( V_14 , V_2 -> V_19 + V_22 ) ;
F_4 ( V_23 [ V_15 ] , V_2 -> V_19 + V_24 ) ;
for ( V_9 = 0 ; V_9 < 40000 ; V_9 ++ ) {
V_11 = F_5 ( V_2 -> V_19 + V_25 ) ;
if ( ( V_11 & V_26 ) == 0 )
break;
}
if ( V_9 == 40000 )
return - V_27 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_4 ( 0xff , V_2 -> V_19 + V_28 ) ;
for ( V_9 = 0 ; V_9 < 40000 ; V_9 ++ ) {
V_11 = F_5 ( V_2 -> V_19 + V_29 ) ;
if ( ( V_11 & V_26 ) == 0 )
break;
}
if ( V_9 == 40000 )
return - V_27 ;
V_13 = F_5 ( V_2 -> V_19 + V_30 ) ;
V_12 = F_5 ( V_2 -> V_19 + V_31 ) ;
V_10 = ( ( V_12 ^ 0x0080 ) << 8 ) + V_13 ;
V_7 [ V_8 ] = V_10 ;
}
return V_8 ;
}
static int F_6 ( unsigned int * V_32 , int V_33 )
{
return * V_32 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_34 * V_35 )
{
int V_36 = 0 ;
int V_37 ;
int V_38 , V_39 , V_9 ;
V_36 |= F_8 ( & V_35 -> V_40 , V_41 ) ;
V_36 |= F_8 ( & V_35 -> V_42 ,
V_43 ) ;
V_36 |= F_8 ( & V_35 -> V_44 ,
V_43 ) ;
V_36 |= F_8 ( & V_35 -> V_45 , V_46 ) ;
V_36 |= F_8 ( & V_35 -> V_47 , V_46 | V_48 ) ;
if ( V_36 )
return 1 ;
V_36 |= F_9 ( V_35 -> V_42 ) ;
V_36 |= F_9 ( V_35 -> V_44 ) ;
V_36 |= F_9 ( V_35 -> V_47 ) ;
if ( V_36 )
return 2 ;
V_36 |= F_10 ( & V_35 -> V_49 , 0 ) ;
#define F_11 1000000
#define F_12 1000000000
if ( V_35 -> V_42 == V_43 ) {
V_36 |= F_13 ( & V_35 -> V_50 ,
F_11 ) ;
V_36 |= F_14 ( & V_35 -> V_50 ,
F_12 ) ;
} else {
V_36 |= F_14 ( & V_35 -> V_50 , 9 ) ;
}
if ( V_35 -> V_44 == V_43 ) {
if ( V_35 -> V_51 >= 17500 )
V_35 -> V_51 = 20000 ;
else if ( V_35 -> V_51 >= 12500 )
V_35 -> V_51 = 15000 ;
else if ( V_35 -> V_51 >= 7500 )
V_35 -> V_51 = 10000 ;
else
V_35 -> V_51 = 5000 ;
} else {
V_36 |= F_14 ( & V_35 -> V_51 , 9 ) ;
}
V_36 |= F_10 ( & V_35 -> V_52 , V_35 -> V_53 ) ;
if ( V_35 -> V_47 == V_46 ) {
V_36 |= F_14 ( & V_35 -> V_54 , 0xfffffff0 ) ;
V_36 |= F_13 ( & V_35 -> V_54 , 1 ) ;
} else {
V_36 |= F_10 ( & V_35 -> V_54 , 0 ) ;
}
if ( V_36 )
return 3 ;
if ( V_35 -> V_42 == V_43 ) {
V_37 = V_35 -> V_50 ;
F_6 ( & V_35 -> V_50 ,
V_35 -> V_55 & V_56 ) ;
if ( V_37 != V_35 -> V_50 )
V_36 ++ ;
}
if ( V_35 -> V_44 == V_43 ) {
V_37 = V_35 -> V_51 ;
F_6 ( & V_35 -> V_51 ,
V_35 -> V_55 & V_56 ) ;
if ( V_37 != V_35 -> V_51 )
V_36 ++ ;
if ( V_35 -> V_42 == V_43 &&
V_35 -> V_50 <
V_35 -> V_51 * V_35 -> V_52 ) {
V_35 -> V_50 =
V_35 -> V_51 * V_35 -> V_52 ;
V_36 ++ ;
}
}
if ( V_36 )
return 4 ;
if ( V_35 -> V_57 ) {
V_39 = F_3 ( V_35 -> V_57 [ 0 ] ) ;
V_38 = F_2 ( V_35 -> V_57 [ 0 ] ) ;
for ( V_9 = 1 ; V_9 < V_35 -> V_53 ; V_9 ++ ) {
if ( F_2 ( V_35 -> V_57 [ V_9 ] ) !=
( V_38 + V_9 ) % V_4 -> V_17 ) {
F_15 ( V_2 ,
L_1 ) ;
V_36 ++ ;
}
if ( F_3 ( V_35 -> V_57 [ V_9 ] ) != V_39 ) {
F_15 ( V_2 ,
L_2 ) ;
V_36 ++ ;
}
}
}
if ( V_36 )
return 5 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_58 )
{
unsigned char V_59 , V_60 , V_61 ;
unsigned short V_62 ;
V_59 = 200 ;
V_62 = V_58 / 20000 ;
V_61 = ( V_62 & 0xff00 ) >> 8 ;
V_60 = V_62 & 0x00ff ;
F_4 ( 0 , V_2 -> V_19 + V_63 ) ;
F_4 ( V_64 , V_2 -> V_19 + V_65 ) ;
F_4 ( V_66 , V_2 -> V_19 + V_67 ) ;
F_4 ( V_59 , V_2 -> V_19 + V_68 ) ;
F_4 ( V_69 , V_2 -> V_19 + V_67 ) ;
F_4 ( V_60 , V_2 -> V_19 + V_70 ) ;
F_4 ( V_61 , V_2 -> V_19 + V_70 ) ;
F_4 ( V_71 | V_72 , V_2 -> V_19 + V_73 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_74 * V_75 = V_2 -> V_76 ;
struct V_34 * V_35 = & V_4 -> V_77 -> V_35 ;
int V_9 , V_15 ;
unsigned char V_78 , V_79 , V_11 ;
if ( ! V_35 -> V_57 )
return - V_80 ;
V_78 = F_2 ( V_35 -> V_57 [ 0 ] ) & ( V_4 -> V_17 - 1 ) ;
V_79 = V_78 + V_35 -> V_53 - 1 ;
if ( V_79 >= V_4 -> V_17 )
return - V_80 ;
V_15 = F_3 ( V_35 -> V_57 [ 0 ] ) ;
F_4 ( V_18 , V_2 -> V_19 + V_20 ) ;
F_4 ( V_81 , V_2 -> V_19 + V_20 ) ;
F_4 ( V_78 , V_2 -> V_19 + V_21 ) ;
F_4 ( V_79 , V_2 -> V_19 + V_22 ) ;
F_4 ( V_23 [ V_15 ] , V_2 -> V_19 + V_24 ) ;
F_4 ( V_82 , V_2 -> V_19 + V_65 ) ;
if ( V_35 -> V_47 == V_46 )
V_75 -> V_83 = V_35 -> V_54 ;
else {
V_75 -> V_83 = 0xffffffff ;
}
for ( V_9 = 0 ; V_9 < 40000 ; V_9 ++ ) {
V_11 = F_5 ( V_2 -> V_19 + V_25 ) ;
if ( ( V_11 & V_26 ) == 0 )
break;
}
if ( V_9 == 40000 )
return - V_27 ;
if ( V_75 -> V_83 > 1 ) {
F_16 ( V_2 , V_35 -> V_50 ) ;
} else {
F_4 ( V_71 , V_2 -> V_19 + V_73 ) ;
F_4 ( 0xff , V_2 -> V_19 + V_28 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_74 * V_75 = V_2 -> V_76 ;
V_75 -> V_83 = 1 ;
return 0 ;
}
static T_1 F_19 ( int V_84 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
struct V_74 * V_75 = V_2 -> V_76 ;
unsigned char V_85 ;
unsigned int V_86 ;
unsigned short V_12 , V_13 ;
int V_9 ;
if ( ! V_2 -> V_87 ) {
F_15 ( V_2 , L_3 ) ;
return V_88 ;
}
V_85 = F_5 ( V_2 -> V_19 + V_73 ) ;
if ( V_85 & V_71 ) {
struct V_3 * V_4 = V_2 -> V_89 ;
struct V_34 * V_35 = & V_4 -> V_77 -> V_35 ;
for ( V_9 = 0 ; V_9 < V_35 -> V_53 ; V_9 ++ ) {
V_13 = F_5 ( V_2 -> V_19 + V_30 ) ;
V_12 = F_5 ( V_2 -> V_19 + V_31 ) ;
V_86 = ( ( V_12 ^ 0x0080 ) << 8 ) + V_13 ;
F_20 ( V_4 -> V_77 , V_86 ) ;
}
if ( V_75 -> V_83 != 0xffffffff ) {
V_75 -> V_83 -- ;
if ( V_75 -> V_83 == 0 ) {
F_4 ( 0x0 , V_2 -> V_19 + V_73 ) ;
V_4 -> V_77 -> V_90 |= V_91 ;
}
}
F_21 ( V_2 , V_4 ) ;
}
F_4 ( V_82 , V_2 -> V_19 + V_65 ) ;
return V_88 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_74 * V_75 = V_2 -> V_76 ;
int V_9 ;
int V_14 = F_2 ( V_6 -> V_16 ) ;
unsigned char V_92 , V_93 , V_11 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_8 ; V_9 ++ ) {
V_75 -> V_94 [ V_14 ] = V_7 [ V_9 ] ;
V_93 = V_7 [ V_9 ] & 0x00ff ;
V_92 = ( V_7 [ V_9 ] >> 8 ) + V_14 * ( 1 << 6 ) ;
F_4 ( V_93 , V_2 -> V_19 + V_95 ) ;
F_4 ( V_92 , V_2 -> V_19 + V_96 ) ;
for ( V_9 = 0 ; V_9 < 40000 ; V_9 ++ ) {
V_11 = F_5 ( V_2 -> V_19 + V_97 ) ;
if ( ( V_11 & V_98 ) == 0 )
break;
}
if ( V_9 == 40000 )
return - V_27 ;
V_11 = F_5 ( V_2 -> V_19 + V_96 ) ;
}
return V_9 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_74 * V_75 = V_2 -> V_76 ;
int V_9 ;
int V_14 = F_2 ( V_6 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_8 ; V_9 ++ )
V_7 [ V_9 ] = V_75 -> V_94 [ V_14 ] ;
return V_9 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_74 * V_75 = V_2 -> V_76 ;
unsigned int V_99 ;
unsigned int V_100 ;
V_99 = F_25 ( V_4 , V_7 ) ;
if ( V_99 ) {
F_4 ( V_101 , V_2 -> V_19 + V_65 ) ;
if ( ( ( V_75 -> V_102 & V_103 ) == 0 ) ||
( ( V_75 -> V_102 & V_104 ) == 0 ) ) {
V_100 = ( V_4 -> V_105 & 0x00ff0000 ) >> 16 ;
F_4 ( V_100 , V_2 -> V_19 + V_106 ) ;
}
if ( ( V_75 -> V_102 & V_107 ) == 0 ) {
V_100 = ( V_4 -> V_105 & 0x0000ff00 ) >> 8 ;
F_4 ( V_100 , V_2 -> V_19 + V_108 ) ;
}
if ( ( V_75 -> V_102 & V_109 ) == 0 ) {
V_100 = ( V_4 -> V_105 & 0x000000ff ) ;
F_4 ( V_100 , V_2 -> V_19 + V_110 ) ;
}
}
V_100 = F_5 ( V_2 -> V_19 + V_110 ) ;
V_100 |= F_5 ( V_2 -> V_19 + V_108 ) << 8 ;
V_100 |= F_5 ( V_2 -> V_19 + V_106 ) << 16 ;
V_4 -> V_105 = V_100 ;
V_7 [ 1 ] = V_100 ;
return V_6 -> V_8 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_74 * V_75 = V_2 -> V_76 ;
unsigned int V_14 = F_2 ( V_6 -> V_16 ) ;
unsigned int V_99 ;
unsigned char V_111 ;
int V_112 ;
if ( V_14 < 8 ) {
V_99 = 0x0000ff ;
V_111 = V_109 ;
} else if ( V_14 < 16 ) {
V_99 = 0x00ff00 ;
V_111 = V_107 ;
} else if ( V_14 < 20 ) {
V_99 = 0x0f0000 ;
V_111 = V_103 ;
} else {
V_99 = 0xf00000 ;
V_111 = V_104 ;
}
V_112 = F_27 ( V_2 , V_4 , V_6 , V_7 , V_99 ) ;
if ( V_112 )
return V_112 ;
if ( V_7 [ 0 ] == V_113 )
V_75 -> V_102 &= ~ V_111 ;
else
V_75 -> V_102 |= V_111 ;
F_4 ( V_101 , V_2 -> V_19 + V_65 ) ;
F_4 ( V_75 -> V_102 , V_2 -> V_19 + V_114 ) ;
return V_6 -> V_8 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_115 * V_116 )
{
struct V_74 * V_75 ;
int V_112 ;
struct V_3 * V_4 ;
unsigned char V_117 , V_118 , V_119 , V_120 , V_85 , V_121 ;
V_112 = F_29 ( V_2 , V_116 -> V_122 [ 0 ] , V_123 ) ;
if ( V_112 )
return V_112 ;
F_4 ( V_124 , V_2 -> V_19 + V_65 ) ;
F_30 ( 1000 ) ;
F_4 ( 0x0 , V_2 -> V_19 + V_20 ) ;
F_4 ( 0x0 , V_2 -> V_19 + V_73 ) ;
F_4 ( 0x80 , V_2 -> V_19 + V_21 ) ;
F_4 ( 0xff , V_2 -> V_19 + V_22 ) ;
F_4 ( V_125 , V_2 -> V_19 + V_24 ) ;
F_30 ( 100 ) ;
V_118 = F_5 ( V_2 -> V_19 + V_21 ) ;
V_117 = F_5 ( V_2 -> V_19 + V_22 ) ;
V_119 = F_5 ( V_2 -> V_19 + V_126 ) ;
V_120 = F_5 ( V_2 -> V_19 + V_29 ) ;
V_85 = F_5 ( V_2 -> V_19 + V_73 ) ;
V_121 = F_5 ( V_2 -> V_19 + V_25 ) ;
if ( ( V_118 != 0x00 ) || ( V_117 != 0x1f ) || ( V_119 != 0x80 ) ||
( V_120 != 0x60 || ( V_85 != 0x00 ) || V_121 != 0x0c ) ) {
F_31 ( V_2 -> V_127 , L_4 ) ;
return - V_128 ;
}
if ( V_116 -> V_122 [ 1 ] ) {
V_112 = F_32 ( V_116 -> V_122 [ 1 ] , F_19 , 0 ,
V_2 -> V_129 , V_2 ) ;
if ( V_112 == 0 )
V_2 -> V_84 = V_116 -> V_122 [ 1 ] ;
}
V_75 = F_33 ( V_2 , sizeof( * V_75 ) ) ;
if ( ! V_75 )
return - V_130 ;
V_112 = F_34 ( V_2 , 3 ) ;
if ( V_112 )
return V_112 ;
V_4 = & V_2 -> V_131 [ 0 ] ;
V_4 -> type = V_132 ;
V_4 -> V_133 = V_134 | V_135 | V_136 ;
V_4 -> V_17 = 32 ;
V_4 -> V_137 = 0xffff ;
V_4 -> V_138 = & V_139 ;
V_4 -> V_140 = F_1 ;
if ( V_2 -> V_84 ) {
V_2 -> V_89 = V_4 ;
V_4 -> V_133 |= V_141 ;
V_4 -> V_142 = 32 ;
V_4 -> V_143 = F_17 ;
V_4 -> V_144 = F_7 ;
V_4 -> V_145 = F_18 ;
}
V_4 = & V_2 -> V_131 [ 1 ] ;
V_4 -> type = V_146 ;
V_4 -> V_133 = V_147 ;
V_4 -> V_17 = 4 ;
V_4 -> V_137 = 0x0fff ;
V_4 -> V_138 = & V_148 ;
V_4 -> V_149 = F_22 ;
V_4 -> V_140 = F_23 ;
V_4 = & V_2 -> V_131 [ 2 ] ;
F_4 ( V_101 , V_2 -> V_19 + V_65 ) ;
V_75 -> V_102 = V_109 | V_107 |
V_103 | V_104 | V_150 ;
F_4 ( V_75 -> V_102 , V_2 -> V_19 + V_114 ) ;
V_4 -> type = V_151 ;
V_4 -> V_133 = V_134 | V_147 ;
V_4 -> V_17 = 24 ;
V_4 -> V_137 = 1 ;
V_4 -> V_105 = 0 ;
V_4 -> V_138 = & V_152 ;
V_4 -> V_153 = F_24 ;
V_4 -> V_154 = F_26 ;
return 0 ;
}
