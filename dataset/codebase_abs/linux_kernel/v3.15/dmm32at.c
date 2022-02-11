static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned char V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_7 ) ;
if ( ( V_8 & V_10 ) == 0 )
return 0 ;
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
int V_13 ;
unsigned int V_14 ;
unsigned short V_15 , V_16 ;
unsigned char V_17 ;
int V_18 ;
int V_19 ;
V_17 = F_4 ( V_6 -> V_20 ) & ( V_4 -> V_21 - 1 ) ;
V_18 = F_5 ( V_6 -> V_20 ) ;
F_6 ( V_22 , V_2 -> V_9 + V_23 ) ;
F_6 ( V_17 , V_2 -> V_9 + V_24 ) ;
F_6 ( V_17 , V_2 -> V_9 + V_25 ) ;
F_6 ( V_26 [ V_18 ] , V_2 -> V_9 + V_27 ) ;
V_19 = F_7 ( V_2 , V_4 , V_6 , F_1 , V_28 ) ;
if ( V_19 )
return V_19 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
F_6 ( 0xff , V_2 -> V_9 + V_29 ) ;
V_19 = F_7 ( V_2 , V_4 , V_6 , F_1 ,
V_30 ) ;
if ( V_19 )
return V_19 ;
V_16 = F_2 ( V_2 -> V_9 + V_31 ) ;
V_15 = F_2 ( V_2 -> V_9 + V_32 ) ;
V_14 = ( ( V_15 ^ 0x0080 ) << 8 ) + V_16 ;
V_12 [ V_13 ] = V_14 ;
}
return V_13 ;
}
static int F_8 ( unsigned int * V_33 , int V_34 )
{
return * V_33 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
int V_37 = 0 ;
int V_38 ;
int V_39 , V_40 , V_41 ;
V_37 |= F_10 ( & V_36 -> V_42 , V_43 ) ;
V_37 |= F_10 ( & V_36 -> V_44 ,
V_45 ) ;
V_37 |= F_10 ( & V_36 -> V_46 ,
V_45 ) ;
V_37 |= F_10 ( & V_36 -> V_47 , V_48 ) ;
V_37 |= F_10 ( & V_36 -> V_49 , V_48 | V_50 ) ;
if ( V_37 )
return 1 ;
V_37 |= F_11 ( V_36 -> V_44 ) ;
V_37 |= F_11 ( V_36 -> V_46 ) ;
V_37 |= F_11 ( V_36 -> V_49 ) ;
if ( V_37 )
return 2 ;
V_37 |= F_12 ( & V_36 -> V_51 , 0 ) ;
#define F_13 1000000
#define F_14 1000000000
if ( V_36 -> V_44 == V_45 ) {
V_37 |= F_15 ( & V_36 -> V_52 ,
F_13 ) ;
V_37 |= F_16 ( & V_36 -> V_52 ,
F_14 ) ;
} else {
V_37 |= F_16 ( & V_36 -> V_52 , 9 ) ;
}
if ( V_36 -> V_46 == V_45 ) {
if ( V_36 -> V_53 >= 17500 )
V_36 -> V_53 = 20000 ;
else if ( V_36 -> V_53 >= 12500 )
V_36 -> V_53 = 15000 ;
else if ( V_36 -> V_53 >= 7500 )
V_36 -> V_53 = 10000 ;
else
V_36 -> V_53 = 5000 ;
} else {
V_37 |= F_16 ( & V_36 -> V_53 , 9 ) ;
}
V_37 |= F_12 ( & V_36 -> V_54 , V_36 -> V_55 ) ;
if ( V_36 -> V_49 == V_48 ) {
V_37 |= F_16 ( & V_36 -> V_56 , 0xfffffff0 ) ;
V_37 |= F_15 ( & V_36 -> V_56 , 1 ) ;
} else {
V_37 |= F_12 ( & V_36 -> V_56 , 0 ) ;
}
if ( V_37 )
return 3 ;
if ( V_36 -> V_44 == V_45 ) {
V_38 = V_36 -> V_52 ;
F_8 ( & V_36 -> V_52 ,
V_36 -> V_57 & V_58 ) ;
if ( V_38 != V_36 -> V_52 )
V_37 ++ ;
}
if ( V_36 -> V_46 == V_45 ) {
V_38 = V_36 -> V_53 ;
F_8 ( & V_36 -> V_53 ,
V_36 -> V_57 & V_58 ) ;
if ( V_38 != V_36 -> V_53 )
V_37 ++ ;
if ( V_36 -> V_44 == V_45 &&
V_36 -> V_52 <
V_36 -> V_53 * V_36 -> V_54 ) {
V_36 -> V_52 =
V_36 -> V_53 * V_36 -> V_54 ;
V_37 ++ ;
}
}
if ( V_37 )
return 4 ;
if ( V_36 -> V_59 ) {
V_40 = F_5 ( V_36 -> V_59 [ 0 ] ) ;
V_39 = F_4 ( V_36 -> V_59 [ 0 ] ) ;
for ( V_41 = 1 ; V_41 < V_36 -> V_55 ; V_41 ++ ) {
if ( F_4 ( V_36 -> V_59 [ V_41 ] ) !=
( V_39 + V_41 ) % V_4 -> V_21 ) {
F_17 ( V_2 ,
L_1 ) ;
V_37 ++ ;
}
if ( F_5 ( V_36 -> V_59 [ V_41 ] ) != V_40 ) {
F_17 ( V_2 ,
L_2 ) ;
V_37 ++ ;
}
}
}
if ( V_37 )
return 5 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_60 )
{
unsigned char V_61 , V_62 , V_63 ;
unsigned short V_64 ;
V_61 = 200 ;
V_64 = V_60 / 20000 ;
V_63 = ( V_64 & 0xff00 ) >> 8 ;
V_62 = V_64 & 0x00ff ;
F_6 ( 0 , V_2 -> V_9 + V_65 ) ;
F_6 ( V_66 , V_2 -> V_9 + V_67 ) ;
F_6 ( V_68 , V_2 -> V_9 + V_69 ) ;
F_6 ( V_61 , V_2 -> V_9 + V_70 ) ;
F_6 ( V_71 , V_2 -> V_9 + V_69 ) ;
F_6 ( V_62 , V_2 -> V_9 + V_72 ) ;
F_6 ( V_63 , V_2 -> V_9 + V_72 ) ;
F_6 ( V_73 | V_74 , V_2 -> V_9 + V_75 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
struct V_35 * V_36 = & V_4 -> V_79 -> V_36 ;
int V_18 ;
unsigned char V_80 , V_81 ;
int V_19 ;
if ( ! V_36 -> V_59 )
return - V_82 ;
V_80 = F_4 ( V_36 -> V_59 [ 0 ] ) & ( V_4 -> V_21 - 1 ) ;
V_81 = V_80 + V_36 -> V_55 - 1 ;
if ( V_81 >= V_4 -> V_21 )
return - V_82 ;
V_18 = F_5 ( V_36 -> V_59 [ 0 ] ) ;
F_6 ( V_22 , V_2 -> V_9 + V_23 ) ;
F_6 ( V_83 , V_2 -> V_9 + V_23 ) ;
F_6 ( V_80 , V_2 -> V_9 + V_24 ) ;
F_6 ( V_81 , V_2 -> V_9 + V_25 ) ;
F_6 ( V_26 [ V_18 ] , V_2 -> V_9 + V_27 ) ;
F_6 ( V_84 , V_2 -> V_9 + V_67 ) ;
if ( V_36 -> V_49 == V_48 )
V_77 -> V_85 = V_36 -> V_56 ;
else {
V_77 -> V_85 = 0xffffffff ;
}
V_19 = F_7 ( V_2 , V_4 , NULL , F_1 , V_28 ) ;
if ( V_19 )
return V_19 ;
if ( V_77 -> V_85 > 1 ) {
F_18 ( V_2 , V_36 -> V_52 ) ;
} else {
F_6 ( V_73 , V_2 -> V_9 + V_75 ) ;
F_6 ( 0xff , V_2 -> V_9 + V_29 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
V_77 -> V_85 = 1 ;
return 0 ;
}
static T_1 F_21 ( int V_86 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_76 * V_77 = V_2 -> V_78 ;
unsigned char V_87 ;
unsigned int V_88 ;
unsigned short V_15 , V_16 ;
int V_41 ;
if ( ! V_2 -> V_89 ) {
F_17 ( V_2 , L_3 ) ;
return V_90 ;
}
V_87 = F_2 ( V_2 -> V_9 + V_75 ) ;
if ( V_87 & V_73 ) {
struct V_3 * V_4 = V_2 -> V_91 ;
struct V_35 * V_36 = & V_4 -> V_79 -> V_36 ;
for ( V_41 = 0 ; V_41 < V_36 -> V_55 ; V_41 ++ ) {
V_16 = F_2 ( V_2 -> V_9 + V_31 ) ;
V_15 = F_2 ( V_2 -> V_9 + V_32 ) ;
V_88 = ( ( V_15 ^ 0x0080 ) << 8 ) + V_16 ;
F_22 ( V_4 -> V_79 , V_88 ) ;
}
if ( V_77 -> V_85 != 0xffffffff ) {
V_77 -> V_85 -- ;
if ( V_77 -> V_85 == 0 ) {
F_6 ( 0x0 , V_2 -> V_9 + V_75 ) ;
V_4 -> V_79 -> V_92 |= V_93 ;
}
}
F_23 ( V_2 , V_4 ) ;
}
F_6 ( V_84 , V_2 -> V_9 + V_67 ) ;
return V_90 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned char V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_94 ) ;
if ( ( V_8 & V_95 ) == 0 )
return 0 ;
return - V_11 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
int V_41 ;
int V_17 = F_4 ( V_6 -> V_20 ) ;
unsigned char V_96 , V_97 , V_8 ;
int V_19 ;
for ( V_41 = 0 ; V_41 < V_6 -> V_13 ; V_41 ++ ) {
V_77 -> V_98 [ V_17 ] = V_12 [ V_41 ] ;
V_97 = V_12 [ V_41 ] & 0x00ff ;
V_96 = ( V_12 [ V_41 ] >> 8 ) + V_17 * ( 1 << 6 ) ;
F_6 ( V_97 , V_2 -> V_9 + V_99 ) ;
F_6 ( V_96 , V_2 -> V_9 + V_100 ) ;
V_19 = F_7 ( V_2 , V_4 , V_6 , F_24 , 0 ) ;
if ( V_19 )
return V_19 ;
V_8 = F_2 ( V_2 -> V_9 + V_100 ) ;
}
return V_41 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
int V_41 ;
int V_17 = F_4 ( V_6 -> V_20 ) ;
for ( V_41 = 0 ; V_41 < V_6 -> V_13 ; V_41 ++ )
V_12 [ V_41 ] = V_77 -> V_98 [ V_17 ] ;
return V_41 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
unsigned int V_101 ;
unsigned int V_102 ;
V_101 = F_28 ( V_4 , V_12 ) ;
if ( V_101 ) {
F_6 ( V_103 , V_2 -> V_9 + V_67 ) ;
if ( ( ( V_77 -> V_104 & V_105 ) == 0 ) ||
( ( V_77 -> V_104 & V_106 ) == 0 ) ) {
V_102 = ( V_4 -> V_107 & 0x00ff0000 ) >> 16 ;
F_6 ( V_102 , V_2 -> V_9 + V_108 ) ;
}
if ( ( V_77 -> V_104 & V_109 ) == 0 ) {
V_102 = ( V_4 -> V_107 & 0x0000ff00 ) >> 8 ;
F_6 ( V_102 , V_2 -> V_9 + V_110 ) ;
}
if ( ( V_77 -> V_104 & V_111 ) == 0 ) {
V_102 = ( V_4 -> V_107 & 0x000000ff ) ;
F_6 ( V_102 , V_2 -> V_9 + V_112 ) ;
}
}
V_102 = F_2 ( V_2 -> V_9 + V_112 ) ;
V_102 |= F_2 ( V_2 -> V_9 + V_110 ) << 8 ;
V_102 |= F_2 ( V_2 -> V_9 + V_108 ) << 16 ;
V_4 -> V_107 = V_102 ;
V_12 [ 1 ] = V_102 ;
return V_6 -> V_13 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
unsigned int V_17 = F_4 ( V_6 -> V_20 ) ;
unsigned int V_101 ;
unsigned char V_113 ;
int V_19 ;
if ( V_17 < 8 ) {
V_101 = 0x0000ff ;
V_113 = V_111 ;
} else if ( V_17 < 16 ) {
V_101 = 0x00ff00 ;
V_113 = V_109 ;
} else if ( V_17 < 20 ) {
V_101 = 0x0f0000 ;
V_113 = V_105 ;
} else {
V_101 = 0xf00000 ;
V_113 = V_106 ;
}
V_19 = F_30 ( V_2 , V_4 , V_6 , V_12 , V_101 ) ;
if ( V_19 )
return V_19 ;
if ( V_12 [ 0 ] == V_114 )
V_77 -> V_104 &= ~ V_113 ;
else
V_77 -> V_104 |= V_113 ;
F_6 ( V_103 , V_2 -> V_9 + V_67 ) ;
F_6 ( V_77 -> V_104 , V_2 -> V_9 + V_115 ) ;
return V_6 -> V_13 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
struct V_76 * V_77 ;
int V_19 ;
struct V_3 * V_4 ;
unsigned char V_118 , V_119 , V_120 , V_121 , V_87 , V_122 ;
V_19 = F_32 ( V_2 , V_117 -> V_123 [ 0 ] , V_124 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_125 , V_2 -> V_9 + V_67 ) ;
F_33 ( 1000 ) ;
F_6 ( 0x0 , V_2 -> V_9 + V_23 ) ;
F_6 ( 0x0 , V_2 -> V_9 + V_75 ) ;
F_6 ( 0x80 , V_2 -> V_9 + V_24 ) ;
F_6 ( 0xff , V_2 -> V_9 + V_25 ) ;
F_6 ( V_126 , V_2 -> V_9 + V_27 ) ;
F_33 ( 100 ) ;
V_119 = F_2 ( V_2 -> V_9 + V_24 ) ;
V_118 = F_2 ( V_2 -> V_9 + V_25 ) ;
V_120 = F_2 ( V_2 -> V_9 + V_127 ) ;
V_121 = F_2 ( V_2 -> V_9 + V_30 ) ;
V_87 = F_2 ( V_2 -> V_9 + V_75 ) ;
V_122 = F_2 ( V_2 -> V_9 + V_28 ) ;
if ( ( V_119 != 0x00 ) || ( V_118 != 0x1f ) || ( V_120 != 0x80 ) ||
( V_121 != 0x60 || ( V_87 != 0x00 ) || V_122 != 0x0c ) ) {
F_34 ( V_2 -> V_128 , L_4 ) ;
return - V_129 ;
}
if ( V_117 -> V_123 [ 1 ] ) {
V_19 = F_35 ( V_117 -> V_123 [ 1 ] , F_21 , 0 ,
V_2 -> V_130 , V_2 ) ;
if ( V_19 == 0 )
V_2 -> V_86 = V_117 -> V_123 [ 1 ] ;
}
V_77 = F_36 ( V_2 , sizeof( * V_77 ) ) ;
if ( ! V_77 )
return - V_131 ;
V_19 = F_37 ( V_2 , 3 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_132 [ 0 ] ;
V_4 -> type = V_133 ;
V_4 -> V_134 = V_135 | V_136 | V_137 ;
V_4 -> V_21 = 32 ;
V_4 -> V_138 = 0xffff ;
V_4 -> V_139 = & V_140 ;
V_4 -> V_141 = F_3 ;
if ( V_2 -> V_86 ) {
V_2 -> V_91 = V_4 ;
V_4 -> V_134 |= V_142 ;
V_4 -> V_143 = 32 ;
V_4 -> V_144 = F_19 ;
V_4 -> V_145 = F_9 ;
V_4 -> V_146 = F_20 ;
}
V_4 = & V_2 -> V_132 [ 1 ] ;
V_4 -> type = V_147 ;
V_4 -> V_134 = V_148 ;
V_4 -> V_21 = 4 ;
V_4 -> V_138 = 0x0fff ;
V_4 -> V_139 = & V_149 ;
V_4 -> V_150 = F_25 ;
V_4 -> V_141 = F_26 ;
V_4 = & V_2 -> V_132 [ 2 ] ;
F_6 ( V_103 , V_2 -> V_9 + V_67 ) ;
V_77 -> V_104 = V_111 | V_109 |
V_105 | V_106 | V_151 ;
F_6 ( V_77 -> V_104 , V_2 -> V_9 + V_115 ) ;
V_4 -> type = V_152 ;
V_4 -> V_134 = V_135 | V_148 ;
V_4 -> V_21 = 24 ;
V_4 -> V_138 = 1 ;
V_4 -> V_107 = 0 ;
V_4 -> V_139 = & V_153 ;
V_4 -> V_154 = F_27 ;
V_4 -> V_155 = F_29 ;
return 0 ;
}
