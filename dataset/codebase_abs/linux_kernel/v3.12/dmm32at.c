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
if ( V_9 == 40000 ) {
F_6 ( V_27 L_1 ) ;
return - V_28 ;
}
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_4 ( 0xff , V_2 -> V_19 + V_29 ) ;
for ( V_9 = 0 ; V_9 < 40000 ; V_9 ++ ) {
V_11 = F_5 ( V_2 -> V_19 + V_30 ) ;
if ( ( V_11 & V_26 ) == 0 )
break;
}
if ( V_9 == 40000 ) {
F_6 ( V_27 L_1 ) ;
return - V_28 ;
}
V_13 = F_5 ( V_2 -> V_19 + V_31 ) ;
V_12 = F_5 ( V_2 -> V_19 + V_32 ) ;
V_10 = ( ( V_12 ^ 0x0080 ) << 8 ) + V_13 ;
V_7 [ V_8 ] = V_10 ;
}
return V_8 ;
}
static int F_7 ( unsigned int * V_33 , int V_34 )
{
return * V_33 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
int V_37 = 0 ;
int V_38 ;
int V_39 , V_40 , V_9 ;
V_37 |= F_9 ( & V_36 -> V_41 , V_42 ) ;
V_37 |= F_9 ( & V_36 -> V_43 ,
V_44 ) ;
V_37 |= F_9 ( & V_36 -> V_45 ,
V_44 ) ;
V_37 |= F_9 ( & V_36 -> V_46 , V_47 ) ;
V_37 |= F_9 ( & V_36 -> V_48 , V_47 | V_49 ) ;
if ( V_37 )
return 1 ;
V_37 |= F_10 ( V_36 -> V_43 ) ;
V_37 |= F_10 ( V_36 -> V_45 ) ;
V_37 |= F_10 ( V_36 -> V_48 ) ;
if ( V_37 )
return 2 ;
V_37 |= F_11 ( & V_36 -> V_50 , 0 ) ;
#define F_12 1000000
#define F_13 1000000000
if ( V_36 -> V_43 == V_44 ) {
V_37 |= F_14 ( & V_36 -> V_51 ,
F_12 ) ;
V_37 |= F_15 ( & V_36 -> V_51 ,
F_13 ) ;
} else {
V_37 |= F_15 ( & V_36 -> V_51 , 9 ) ;
}
if ( V_36 -> V_45 == V_44 ) {
if ( V_36 -> V_52 >= 17500 )
V_36 -> V_52 = 20000 ;
else if ( V_36 -> V_52 >= 12500 )
V_36 -> V_52 = 15000 ;
else if ( V_36 -> V_52 >= 7500 )
V_36 -> V_52 = 10000 ;
else
V_36 -> V_52 = 5000 ;
} else {
V_37 |= F_15 ( & V_36 -> V_52 , 9 ) ;
}
V_37 |= F_11 ( & V_36 -> V_53 , V_36 -> V_54 ) ;
if ( V_36 -> V_48 == V_47 ) {
V_37 |= F_15 ( & V_36 -> V_55 , 0xfffffff0 ) ;
V_37 |= F_14 ( & V_36 -> V_55 , 1 ) ;
} else {
V_37 |= F_11 ( & V_36 -> V_55 , 0 ) ;
}
if ( V_37 )
return 3 ;
if ( V_36 -> V_43 == V_44 ) {
V_38 = V_36 -> V_51 ;
F_7 ( & V_36 -> V_51 ,
V_36 -> V_56 & V_57 ) ;
if ( V_38 != V_36 -> V_51 )
V_37 ++ ;
}
if ( V_36 -> V_45 == V_44 ) {
V_38 = V_36 -> V_52 ;
F_7 ( & V_36 -> V_52 ,
V_36 -> V_56 & V_57 ) ;
if ( V_38 != V_36 -> V_52 )
V_37 ++ ;
if ( V_36 -> V_43 == V_44 &&
V_36 -> V_51 <
V_36 -> V_52 * V_36 -> V_53 ) {
V_36 -> V_51 =
V_36 -> V_52 * V_36 -> V_53 ;
V_37 ++ ;
}
}
if ( V_37 )
return 4 ;
if ( V_36 -> V_58 ) {
V_40 = F_3 ( V_36 -> V_58 [ 0 ] ) ;
V_39 = F_2 ( V_36 -> V_58 [ 0 ] ) ;
for ( V_9 = 1 ; V_9 < V_36 -> V_54 ; V_9 ++ ) {
if ( F_2 ( V_36 -> V_58 [ V_9 ] ) !=
( V_39 + V_9 ) % V_4 -> V_17 ) {
F_16 ( V_2 ,
L_2 ) ;
V_37 ++ ;
}
if ( F_3 ( V_36 -> V_58 [ V_9 ] ) != V_40 ) {
F_16 ( V_2 ,
L_3 ) ;
V_37 ++ ;
}
}
}
if ( V_37 )
return 5 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned char V_60 , V_61 , V_62 ;
unsigned short V_63 ;
V_60 = 200 ;
V_63 = V_59 / 20000 ;
V_62 = ( V_63 & 0xff00 ) >> 8 ;
V_61 = V_63 & 0x00ff ;
F_4 ( 0 , V_2 -> V_19 + V_64 ) ;
F_4 ( V_65 , V_2 -> V_19 + V_66 ) ;
F_4 ( V_67 , V_2 -> V_19 + V_68 ) ;
F_4 ( V_60 , V_2 -> V_19 + V_69 ) ;
F_4 ( V_70 , V_2 -> V_19 + V_68 ) ;
F_4 ( V_61 , V_2 -> V_19 + V_71 ) ;
F_4 ( V_62 , V_2 -> V_19 + V_71 ) ;
F_4 ( V_72 | V_73 , V_2 -> V_19 + V_74 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
struct V_35 * V_36 = & V_4 -> V_78 -> V_36 ;
int V_9 , V_15 ;
unsigned char V_79 , V_80 , V_11 ;
if ( ! V_36 -> V_58 )
return - V_81 ;
V_79 = F_2 ( V_36 -> V_58 [ 0 ] ) & ( V_4 -> V_17 - 1 ) ;
V_80 = V_79 + V_36 -> V_54 - 1 ;
if ( V_80 >= V_4 -> V_17 )
return - V_81 ;
V_15 = F_3 ( V_36 -> V_58 [ 0 ] ) ;
F_4 ( V_18 , V_2 -> V_19 + V_20 ) ;
F_4 ( V_82 , V_2 -> V_19 + V_20 ) ;
F_4 ( V_79 , V_2 -> V_19 + V_21 ) ;
F_4 ( V_80 , V_2 -> V_19 + V_22 ) ;
F_4 ( V_23 [ V_15 ] , V_2 -> V_19 + V_24 ) ;
F_4 ( V_83 , V_2 -> V_19 + V_66 ) ;
if ( V_36 -> V_48 == V_47 )
V_76 -> V_84 = V_36 -> V_55 ;
else {
V_76 -> V_84 = 0xffffffff ;
}
for ( V_9 = 0 ; V_9 < 40000 ; V_9 ++ ) {
V_11 = F_5 ( V_2 -> V_19 + V_25 ) ;
if ( ( V_11 & V_26 ) == 0 )
break;
}
if ( V_9 == 40000 ) {
F_6 ( V_27 L_1 ) ;
return - V_28 ;
}
if ( V_76 -> V_84 > 1 ) {
F_17 ( V_2 , V_36 -> V_51 ) ;
} else {
F_4 ( V_72 , V_2 -> V_19 + V_74 ) ;
F_4 ( 0xff , V_2 -> V_19 + V_29 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
V_76 -> V_84 = 1 ;
return 0 ;
}
static T_1 F_20 ( int V_85 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
struct V_75 * V_76 = V_2 -> V_77 ;
unsigned char V_86 ;
unsigned int V_87 ;
unsigned short V_12 , V_13 ;
int V_9 ;
if ( ! V_2 -> V_88 ) {
F_16 ( V_2 , L_4 ) ;
return V_89 ;
}
V_86 = F_5 ( V_2 -> V_19 + V_74 ) ;
if ( V_86 & V_72 ) {
struct V_3 * V_4 = V_2 -> V_90 ;
struct V_35 * V_36 = & V_4 -> V_78 -> V_36 ;
for ( V_9 = 0 ; V_9 < V_36 -> V_54 ; V_9 ++ ) {
V_13 = F_5 ( V_2 -> V_19 + V_31 ) ;
V_12 = F_5 ( V_2 -> V_19 + V_32 ) ;
V_87 = ( ( V_12 ^ 0x0080 ) << 8 ) + V_13 ;
F_21 ( V_4 -> V_78 , V_87 ) ;
}
if ( V_76 -> V_84 != 0xffffffff ) {
V_76 -> V_84 -- ;
if ( V_76 -> V_84 == 0 ) {
F_4 ( 0x0 , V_2 -> V_19 + V_74 ) ;
V_4 -> V_78 -> V_91 |= V_92 ;
}
}
F_22 ( V_2 , V_4 ) ;
}
F_4 ( V_83 , V_2 -> V_19 + V_66 ) ;
return V_89 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
int V_9 ;
int V_14 = F_2 ( V_6 -> V_16 ) ;
unsigned char V_93 , V_94 , V_11 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_8 ; V_9 ++ ) {
V_76 -> V_95 [ V_14 ] = V_7 [ V_9 ] ;
V_94 = V_7 [ V_9 ] & 0x00ff ;
V_93 = ( V_7 [ V_9 ] >> 8 ) + V_14 * ( 1 << 6 ) ;
F_4 ( V_94 , V_2 -> V_19 + V_96 ) ;
F_4 ( V_93 , V_2 -> V_19 + V_97 ) ;
for ( V_9 = 0 ; V_9 < 40000 ; V_9 ++ ) {
V_11 = F_5 ( V_2 -> V_19 + V_98 ) ;
if ( ( V_11 & V_99 ) == 0 )
break;
}
if ( V_9 == 40000 ) {
F_6 ( V_27 L_1 ) ;
return - V_28 ;
}
V_11 = F_5 ( V_2 -> V_19 + V_97 ) ;
}
return V_9 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
int V_9 ;
int V_14 = F_2 ( V_6 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_8 ; V_9 ++ )
V_7 [ V_9 ] = V_76 -> V_95 [ V_14 ] ;
return V_9 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
unsigned char V_100 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_101 &= ~ V_7 [ 0 ] ;
V_4 -> V_101 |= V_7 [ 0 ] & V_7 [ 1 ] ;
}
F_4 ( V_102 , V_2 -> V_19 + V_66 ) ;
if ( ( ( V_76 -> V_103 & V_104 ) == 0 ) ||
( ( V_76 -> V_103 & V_105 ) == 0 ) ) {
V_100 = ( V_4 -> V_101 & 0x00ff0000 ) >> 16 ;
F_4 ( V_100 , V_2 -> V_19 + V_106 ) ;
}
if ( ( V_76 -> V_103 & V_107 ) == 0 ) {
V_100 = ( V_4 -> V_101 & 0x0000ff00 ) >> 8 ;
F_4 ( V_100 , V_2 -> V_19 + V_108 ) ;
}
if ( ( V_76 -> V_103 & V_109 ) == 0 ) {
V_100 = ( V_4 -> V_101 & 0x000000ff ) ;
F_4 ( V_100 , V_2 -> V_19 + V_110 ) ;
}
V_4 -> V_101 = F_5 ( V_2 -> V_19 + V_106 ) ;
V_4 -> V_101 <<= 8 ;
V_4 -> V_101 |= F_5 ( V_2 -> V_19 + V_108 ) ;
V_4 -> V_101 <<= 8 ;
V_4 -> V_101 |= F_5 ( V_2 -> V_19 + V_110 ) ;
V_7 [ 1 ] = V_4 -> V_101 ;
return V_6 -> V_8 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
unsigned int V_14 = F_2 ( V_6 -> V_16 ) ;
unsigned int V_111 ;
unsigned char V_112 ;
int V_113 ;
if ( V_14 < 8 ) {
V_111 = 0x0000ff ;
V_112 = V_109 ;
} else if ( V_14 < 16 ) {
V_111 = 0x00ff00 ;
V_112 = V_107 ;
} else if ( V_14 < 20 ) {
V_111 = 0x0f0000 ;
V_112 = V_104 ;
} else {
V_111 = 0xf00000 ;
V_112 = V_105 ;
}
V_113 = F_27 ( V_2 , V_4 , V_6 , V_7 , V_111 ) ;
if ( V_113 )
return V_113 ;
if ( V_7 [ 0 ] == V_114 )
V_76 -> V_103 &= ~ V_112 ;
else
V_76 -> V_103 |= V_112 ;
F_4 ( V_102 , V_2 -> V_19 + V_66 ) ;
F_4 ( V_76 -> V_103 , V_2 -> V_19 + V_115 ) ;
return V_6 -> V_8 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
struct V_75 * V_76 ;
int V_113 ;
struct V_3 * V_4 ;
unsigned char V_118 , V_119 , V_120 , V_121 , V_86 , V_122 ;
unsigned int V_85 ;
V_85 = V_117 -> V_123 [ 1 ] ;
V_113 = F_29 ( V_2 , V_117 -> V_123 [ 0 ] , V_124 ) ;
if ( V_113 )
return V_113 ;
F_4 ( V_125 , V_2 -> V_19 + V_66 ) ;
F_30 ( 1000 ) ;
F_4 ( 0x0 , V_2 -> V_19 + V_20 ) ;
F_4 ( 0x0 , V_2 -> V_19 + V_74 ) ;
F_4 ( 0x80 , V_2 -> V_19 + V_21 ) ;
F_4 ( 0xff , V_2 -> V_19 + V_22 ) ;
F_4 ( V_126 , V_2 -> V_19 + V_24 ) ;
F_30 ( 100 ) ;
V_119 = F_5 ( V_2 -> V_19 + V_21 ) ;
V_118 = F_5 ( V_2 -> V_19 + V_22 ) ;
V_120 = F_5 ( V_2 -> V_19 + V_127 ) ;
V_121 = F_5 ( V_2 -> V_19 + V_30 ) ;
V_86 = F_5 ( V_2 -> V_19 + V_74 ) ;
V_122 = F_5 ( V_2 -> V_19 + V_25 ) ;
F_6 ( V_128 L_5 ,
V_119 , V_118 , V_120 ) ;
F_6 ( V_128
L_6 ,
V_121 , V_86 , V_122 ) ;
if ( ( V_119 != 0x00 ) || ( V_118 != 0x1f ) || ( V_120 != 0x80 ) ||
( V_121 != 0x60 || ( V_86 != 0x00 ) || V_122 != 0x0c ) ) {
F_6 ( V_129 L_7 ) ;
return - V_130 ;
}
if ( V_85 ) {
V_113 = F_31 ( V_85 , F_20 , 0 , V_2 -> V_131 , V_2 ) ;
if ( V_113 < 0 ) {
F_6 ( V_129 L_8 ) ;
return V_113 ;
}
V_2 -> V_85 = V_85 ;
}
V_76 = F_32 ( V_2 , sizeof( * V_76 ) ) ;
if ( ! V_76 )
return - V_132 ;
V_113 = F_33 ( V_2 , 3 ) ;
if ( V_113 )
return V_113 ;
V_4 = & V_2 -> V_133 [ 0 ] ;
V_2 -> V_90 = V_4 ;
V_4 -> type = V_134 ;
V_4 -> V_135 = V_136 | V_137 | V_138 | V_139 ;
V_4 -> V_17 = 32 ;
V_4 -> V_140 = 0xffff ;
V_4 -> V_141 = & V_142 ;
V_4 -> V_143 = 32 ;
V_4 -> V_144 = F_1 ;
V_4 -> V_145 = F_18 ;
V_4 -> V_146 = F_8 ;
V_4 -> V_147 = F_19 ;
V_4 = & V_2 -> V_133 [ 1 ] ;
V_4 -> type = V_148 ;
V_4 -> V_135 = V_149 ;
V_4 -> V_17 = 4 ;
V_4 -> V_140 = 0x0fff ;
V_4 -> V_141 = & V_150 ;
V_4 -> V_151 = F_23 ;
V_4 -> V_144 = F_24 ;
V_4 = & V_2 -> V_133 [ 2 ] ;
F_4 ( V_102 , V_2 -> V_19 + V_66 ) ;
V_76 -> V_103 = V_109 | V_107 |
V_104 | V_105 | V_152 ;
F_4 ( V_76 -> V_103 , V_2 -> V_19 + V_115 ) ;
V_4 -> type = V_153 ;
V_4 -> V_135 = V_136 | V_149 ;
V_4 -> V_17 = 24 ;
V_4 -> V_140 = 1 ;
V_4 -> V_101 = 0 ;
V_4 -> V_141 = & V_154 ;
V_4 -> V_155 = F_25 ;
V_4 -> V_156 = F_26 ;
F_6 ( V_157 L_9 , V_2 -> V_158 ) ;
return 1 ;
}
