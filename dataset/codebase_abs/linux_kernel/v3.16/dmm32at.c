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
unsigned int V_37 = F_4 ( V_36 -> V_38 [ 0 ] ) ;
unsigned int V_39 = F_5 ( V_36 -> V_38 [ 0 ] ) ;
int V_40 ;
for ( V_40 = 1 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
unsigned int V_17 = F_4 ( V_36 -> V_38 [ V_40 ] ) ;
unsigned int V_18 = F_5 ( V_36 -> V_38 [ V_40 ] ) ;
if ( V_17 != ( V_37 + V_40 ) % V_4 -> V_21 ) {
F_10 ( V_2 -> V_42 ,
L_1 ) ;
return - V_43 ;
}
if ( V_18 != V_39 ) {
F_10 ( V_2 -> V_42 ,
L_2 ) ;
return - V_43 ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
int V_44 = 0 ;
unsigned int V_45 ;
V_44 |= F_12 ( & V_36 -> V_46 , V_47 ) ;
V_44 |= F_12 ( & V_36 -> V_48 ,
V_49 ) ;
V_44 |= F_12 ( & V_36 -> V_50 ,
V_49 ) ;
V_44 |= F_12 ( & V_36 -> V_51 , V_52 ) ;
V_44 |= F_12 ( & V_36 -> V_53 , V_52 | V_54 ) ;
if ( V_44 )
return 1 ;
V_44 |= F_13 ( V_36 -> V_48 ) ;
V_44 |= F_13 ( V_36 -> V_50 ) ;
V_44 |= F_13 ( V_36 -> V_53 ) ;
if ( V_44 )
return 2 ;
V_44 |= F_14 ( & V_36 -> V_55 , 0 ) ;
#define F_15 1000000
#define F_16 1000000000
if ( V_36 -> V_48 == V_49 ) {
V_44 |= F_17 ( & V_36 -> V_56 ,
F_15 ) ;
V_44 |= F_18 ( & V_36 -> V_56 ,
F_16 ) ;
} else {
V_44 |= F_18 ( & V_36 -> V_56 , 9 ) ;
}
if ( V_36 -> V_50 == V_49 ) {
if ( V_36 -> V_57 >= 17500 )
V_36 -> V_57 = 20000 ;
else if ( V_36 -> V_57 >= 12500 )
V_36 -> V_57 = 15000 ;
else if ( V_36 -> V_57 >= 7500 )
V_36 -> V_57 = 10000 ;
else
V_36 -> V_57 = 5000 ;
} else {
V_44 |= F_18 ( & V_36 -> V_57 , 9 ) ;
}
V_44 |= F_14 ( & V_36 -> V_58 , V_36 -> V_41 ) ;
if ( V_36 -> V_53 == V_52 ) {
V_44 |= F_18 ( & V_36 -> V_59 , 0xfffffff0 ) ;
V_44 |= F_17 ( & V_36 -> V_59 , 1 ) ;
} else {
V_44 |= F_14 ( & V_36 -> V_59 , 0 ) ;
}
if ( V_44 )
return 3 ;
if ( V_36 -> V_48 == V_49 ) {
V_45 = V_36 -> V_56 ;
F_8 ( & V_45 , V_36 -> V_60 & V_61 ) ;
V_44 |= F_14 ( & V_36 -> V_56 , V_45 ) ;
}
if ( V_36 -> V_50 == V_49 ) {
V_45 = V_36 -> V_57 ;
F_8 ( & V_45 , V_36 -> V_60 & V_61 ) ;
V_44 |= F_14 ( & V_36 -> V_57 , V_45 ) ;
if ( V_36 -> V_48 == V_49 ) {
V_45 = V_36 -> V_57 * V_36 -> V_58 ;
V_44 |= F_17 ( & V_36 -> V_56 ,
V_45 ) ;
}
}
if ( V_44 )
return 4 ;
if ( V_36 -> V_38 && V_36 -> V_41 > 0 )
V_44 |= F_9 ( V_2 , V_4 , V_36 ) ;
if ( V_44 )
return 5 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned char V_63 , V_64 , V_65 ;
unsigned short V_66 ;
V_63 = 200 ;
V_66 = V_62 / 20000 ;
V_65 = ( V_66 & 0xff00 ) >> 8 ;
V_64 = V_66 & 0x00ff ;
F_6 ( 0 , V_2 -> V_9 + V_67 ) ;
F_6 ( V_68 , V_2 -> V_9 + V_69 ) ;
F_6 ( V_70 , V_2 -> V_9 + V_71 ) ;
F_6 ( V_63 , V_2 -> V_9 + V_72 ) ;
F_6 ( V_73 , V_2 -> V_9 + V_71 ) ;
F_6 ( V_64 , V_2 -> V_9 + V_74 ) ;
F_6 ( V_65 , V_2 -> V_9 + V_74 ) ;
F_6 ( V_75 | V_76 , V_2 -> V_9 + V_77 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
struct V_35 * V_36 = & V_4 -> V_81 -> V_36 ;
int V_18 ;
unsigned char V_82 , V_83 ;
int V_19 ;
if ( ! V_36 -> V_38 )
return - V_43 ;
V_82 = F_4 ( V_36 -> V_38 [ 0 ] ) & ( V_4 -> V_21 - 1 ) ;
V_83 = V_82 + V_36 -> V_41 - 1 ;
if ( V_83 >= V_4 -> V_21 )
return - V_43 ;
V_18 = F_5 ( V_36 -> V_38 [ 0 ] ) ;
F_6 ( V_22 , V_2 -> V_9 + V_23 ) ;
F_6 ( V_84 , V_2 -> V_9 + V_23 ) ;
F_6 ( V_82 , V_2 -> V_9 + V_24 ) ;
F_6 ( V_83 , V_2 -> V_9 + V_25 ) ;
F_6 ( V_26 [ V_18 ] , V_2 -> V_9 + V_27 ) ;
F_6 ( V_85 , V_2 -> V_9 + V_69 ) ;
if ( V_36 -> V_53 == V_52 )
V_79 -> V_86 = V_36 -> V_59 ;
else {
V_79 -> V_86 = 0xffffffff ;
}
V_19 = F_7 ( V_2 , V_4 , NULL , F_1 , V_28 ) ;
if ( V_19 )
return V_19 ;
if ( V_79 -> V_86 > 1 ) {
F_19 ( V_2 , V_36 -> V_56 ) ;
} else {
F_6 ( V_75 , V_2 -> V_9 + V_77 ) ;
F_6 ( 0xff , V_2 -> V_9 + V_29 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
V_79 -> V_86 = 1 ;
return 0 ;
}
static T_1 F_22 ( int V_87 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_78 * V_79 = V_2 -> V_80 ;
unsigned char V_88 ;
unsigned int V_89 ;
unsigned short V_15 , V_16 ;
int V_40 ;
if ( ! V_2 -> V_90 ) {
F_23 ( V_2 , L_3 ) ;
return V_91 ;
}
V_88 = F_2 ( V_2 -> V_9 + V_77 ) ;
if ( V_88 & V_75 ) {
struct V_3 * V_4 = V_2 -> V_92 ;
struct V_35 * V_36 = & V_4 -> V_81 -> V_36 ;
for ( V_40 = 0 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
V_16 = F_2 ( V_2 -> V_9 + V_31 ) ;
V_15 = F_2 ( V_2 -> V_9 + V_32 ) ;
V_89 = ( ( V_15 ^ 0x0080 ) << 8 ) + V_16 ;
F_24 ( V_4 , V_89 ) ;
}
if ( V_79 -> V_86 != 0xffffffff ) {
V_79 -> V_86 -- ;
if ( V_79 -> V_86 == 0 ) {
F_6 ( 0x0 , V_2 -> V_9 + V_77 ) ;
V_4 -> V_81 -> V_93 |= V_94 ;
}
}
F_25 ( V_2 , V_4 ) ;
}
F_6 ( V_85 , V_2 -> V_9 + V_69 ) ;
return V_91 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned char V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_95 ) ;
if ( ( V_8 & V_96 ) == 0 )
return 0 ;
return - V_11 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
int V_40 ;
int V_17 = F_4 ( V_6 -> V_20 ) ;
unsigned char V_97 , V_98 , V_8 ;
int V_19 ;
for ( V_40 = 0 ; V_40 < V_6 -> V_13 ; V_40 ++ ) {
V_79 -> V_99 [ V_17 ] = V_12 [ V_40 ] ;
V_98 = V_12 [ V_40 ] & 0x00ff ;
V_97 = ( V_12 [ V_40 ] >> 8 ) + V_17 * ( 1 << 6 ) ;
F_6 ( V_98 , V_2 -> V_9 + V_100 ) ;
F_6 ( V_97 , V_2 -> V_9 + V_101 ) ;
V_19 = F_7 ( V_2 , V_4 , V_6 , F_26 , 0 ) ;
if ( V_19 )
return V_19 ;
V_8 = F_2 ( V_2 -> V_9 + V_101 ) ;
}
return V_40 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
int V_40 ;
int V_17 = F_4 ( V_6 -> V_20 ) ;
for ( V_40 = 0 ; V_40 < V_6 -> V_13 ; V_40 ++ )
V_12 [ V_40 ] = V_79 -> V_99 [ V_17 ] ;
return V_40 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
unsigned int V_102 ;
unsigned int V_103 ;
V_102 = F_30 ( V_4 , V_12 ) ;
if ( V_102 ) {
F_6 ( V_104 , V_2 -> V_9 + V_69 ) ;
if ( ( ( V_79 -> V_105 & V_106 ) == 0 ) ||
( ( V_79 -> V_105 & V_107 ) == 0 ) ) {
V_103 = ( V_4 -> V_108 & 0x00ff0000 ) >> 16 ;
F_6 ( V_103 , V_2 -> V_9 + V_109 ) ;
}
if ( ( V_79 -> V_105 & V_110 ) == 0 ) {
V_103 = ( V_4 -> V_108 & 0x0000ff00 ) >> 8 ;
F_6 ( V_103 , V_2 -> V_9 + V_111 ) ;
}
if ( ( V_79 -> V_105 & V_112 ) == 0 ) {
V_103 = ( V_4 -> V_108 & 0x000000ff ) ;
F_6 ( V_103 , V_2 -> V_9 + V_113 ) ;
}
}
V_103 = F_2 ( V_2 -> V_9 + V_113 ) ;
V_103 |= F_2 ( V_2 -> V_9 + V_111 ) << 8 ;
V_103 |= F_2 ( V_2 -> V_9 + V_109 ) << 16 ;
V_4 -> V_108 = V_103 ;
V_12 [ 1 ] = V_103 ;
return V_6 -> V_13 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
unsigned int V_17 = F_4 ( V_6 -> V_20 ) ;
unsigned int V_102 ;
unsigned char V_114 ;
int V_19 ;
if ( V_17 < 8 ) {
V_102 = 0x0000ff ;
V_114 = V_112 ;
} else if ( V_17 < 16 ) {
V_102 = 0x00ff00 ;
V_114 = V_110 ;
} else if ( V_17 < 20 ) {
V_102 = 0x0f0000 ;
V_114 = V_106 ;
} else {
V_102 = 0xf00000 ;
V_114 = V_107 ;
}
V_19 = F_32 ( V_2 , V_4 , V_6 , V_12 , V_102 ) ;
if ( V_19 )
return V_19 ;
if ( V_12 [ 0 ] == V_115 )
V_79 -> V_105 &= ~ V_114 ;
else
V_79 -> V_105 |= V_114 ;
F_6 ( V_104 , V_2 -> V_9 + V_69 ) ;
F_6 ( V_79 -> V_105 , V_2 -> V_9 + V_116 ) ;
return V_6 -> V_13 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
struct V_78 * V_79 ;
int V_19 ;
struct V_3 * V_4 ;
unsigned char V_119 , V_120 , V_121 , V_122 , V_88 , V_123 ;
V_19 = F_34 ( V_2 , V_118 -> V_124 [ 0 ] , V_125 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_126 , V_2 -> V_9 + V_69 ) ;
F_35 ( 1000 ) ;
F_6 ( 0x0 , V_2 -> V_9 + V_23 ) ;
F_6 ( 0x0 , V_2 -> V_9 + V_77 ) ;
F_6 ( 0x80 , V_2 -> V_9 + V_24 ) ;
F_6 ( 0xff , V_2 -> V_9 + V_25 ) ;
F_6 ( V_127 , V_2 -> V_9 + V_27 ) ;
F_35 ( 100 ) ;
V_120 = F_2 ( V_2 -> V_9 + V_24 ) ;
V_119 = F_2 ( V_2 -> V_9 + V_25 ) ;
V_121 = F_2 ( V_2 -> V_9 + V_128 ) ;
V_122 = F_2 ( V_2 -> V_9 + V_30 ) ;
V_88 = F_2 ( V_2 -> V_9 + V_77 ) ;
V_123 = F_2 ( V_2 -> V_9 + V_28 ) ;
if ( ( V_120 != 0x00 ) || ( V_119 != 0x1f ) || ( V_121 != 0x80 ) ||
( V_122 != 0x60 || ( V_88 != 0x00 ) || V_123 != 0x0c ) ) {
F_36 ( V_2 -> V_42 , L_4 ) ;
return - V_129 ;
}
if ( V_118 -> V_124 [ 1 ] ) {
V_19 = F_37 ( V_118 -> V_124 [ 1 ] , F_22 , 0 ,
V_2 -> V_130 , V_2 ) ;
if ( V_19 == 0 )
V_2 -> V_87 = V_118 -> V_124 [ 1 ] ;
}
V_79 = F_38 ( V_2 , sizeof( * V_79 ) ) ;
if ( ! V_79 )
return - V_131 ;
V_19 = F_39 ( V_2 , 3 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_132 [ 0 ] ;
V_4 -> type = V_133 ;
V_4 -> V_134 = V_135 | V_136 | V_137 ;
V_4 -> V_21 = 32 ;
V_4 -> V_138 = 0xffff ;
V_4 -> V_139 = & V_140 ;
V_4 -> V_141 = F_3 ;
if ( V_2 -> V_87 ) {
V_2 -> V_92 = V_4 ;
V_4 -> V_134 |= V_142 ;
V_4 -> V_143 = 32 ;
V_4 -> V_144 = F_20 ;
V_4 -> V_145 = F_11 ;
V_4 -> V_146 = F_21 ;
}
V_4 = & V_2 -> V_132 [ 1 ] ;
V_4 -> type = V_147 ;
V_4 -> V_134 = V_148 ;
V_4 -> V_21 = 4 ;
V_4 -> V_138 = 0x0fff ;
V_4 -> V_139 = & V_149 ;
V_4 -> V_150 = F_27 ;
V_4 -> V_141 = F_28 ;
V_4 = & V_2 -> V_132 [ 2 ] ;
F_6 ( V_104 , V_2 -> V_9 + V_69 ) ;
V_79 -> V_105 = V_112 | V_110 |
V_106 | V_107 | V_151 ;
F_6 ( V_79 -> V_105 , V_2 -> V_9 + V_116 ) ;
V_4 -> type = V_152 ;
V_4 -> V_134 = V_135 | V_148 ;
V_4 -> V_21 = 24 ;
V_4 -> V_138 = 1 ;
V_4 -> V_108 = 0 ;
V_4 -> V_139 = & V_153 ;
V_4 -> V_154 = F_29 ;
V_4 -> V_155 = F_31 ;
return 0 ;
}
