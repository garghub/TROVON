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
static int F_8 ( unsigned int * V_33 , unsigned int V_34 )
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
F_8 ( & V_45 , V_36 -> V_34 ) ;
V_44 |= F_14 ( & V_36 -> V_56 , V_45 ) ;
}
if ( V_36 -> V_50 == V_49 ) {
V_45 = V_36 -> V_57 ;
F_8 ( & V_45 , V_36 -> V_34 ) ;
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
static void F_19 ( struct V_1 * V_2 , unsigned int V_60 )
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
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
struct V_35 * V_36 = & V_4 -> V_79 -> V_36 ;
int V_18 ;
unsigned char V_80 , V_81 ;
int V_19 ;
if ( ! V_36 -> V_38 )
return - V_43 ;
V_80 = F_4 ( V_36 -> V_38 [ 0 ] ) & ( V_4 -> V_21 - 1 ) ;
V_81 = V_80 + V_36 -> V_41 - 1 ;
if ( V_81 >= V_4 -> V_21 )
return - V_43 ;
V_18 = F_5 ( V_36 -> V_38 [ 0 ] ) ;
F_6 ( V_22 , V_2 -> V_9 + V_23 ) ;
F_6 ( V_82 , V_2 -> V_9 + V_23 ) ;
F_6 ( V_80 , V_2 -> V_9 + V_24 ) ;
F_6 ( V_81 , V_2 -> V_9 + V_25 ) ;
F_6 ( V_26 [ V_18 ] , V_2 -> V_9 + V_27 ) ;
F_6 ( V_83 , V_2 -> V_9 + V_67 ) ;
if ( V_36 -> V_53 == V_52 )
V_77 -> V_84 = V_36 -> V_59 ;
else {
V_77 -> V_84 = 0xffffffff ;
}
V_19 = F_7 ( V_2 , V_4 , NULL , F_1 , V_28 ) ;
if ( V_19 )
return V_19 ;
if ( V_77 -> V_84 > 1 ) {
F_19 ( V_2 , V_36 -> V_56 ) ;
} else {
F_6 ( V_73 , V_2 -> V_9 + V_75 ) ;
F_6 ( 0xff , V_2 -> V_9 + V_29 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
V_77 -> V_84 = 1 ;
return 0 ;
}
static T_1 F_22 ( int V_85 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_76 * V_77 = V_2 -> V_78 ;
unsigned char V_86 ;
unsigned int V_87 ;
unsigned short V_15 , V_16 ;
int V_40 ;
if ( ! V_2 -> V_88 ) {
F_23 ( V_2 -> V_42 , L_3 ) ;
return V_89 ;
}
V_86 = F_2 ( V_2 -> V_9 + V_75 ) ;
if ( V_86 & V_73 ) {
struct V_3 * V_4 = V_2 -> V_90 ;
struct V_35 * V_36 = & V_4 -> V_79 -> V_36 ;
for ( V_40 = 0 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
V_16 = F_2 ( V_2 -> V_9 + V_31 ) ;
V_15 = F_2 ( V_2 -> V_9 + V_32 ) ;
V_87 = ( ( V_15 ^ 0x0080 ) << 8 ) + V_16 ;
F_24 ( V_4 , V_87 ) ;
}
if ( V_77 -> V_84 != 0xffffffff ) {
V_77 -> V_84 -- ;
if ( V_77 -> V_84 == 0 ) {
F_6 ( 0x0 , V_2 -> V_9 + V_75 ) ;
V_4 -> V_79 -> V_91 |= V_92 ;
}
}
F_25 ( V_2 , V_4 ) ;
}
F_6 ( V_83 , V_2 -> V_9 + V_67 ) ;
return V_89 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned char V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_93 ) ;
if ( ( V_8 & V_94 ) == 0 )
return 0 ;
return - V_11 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
unsigned int V_17 = F_4 ( V_6 -> V_20 ) ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_6 -> V_13 ; V_40 ++ ) {
unsigned int V_95 = V_12 [ V_40 ] ;
int V_19 ;
F_6 ( V_95 & 0xff , V_2 -> V_9 + V_96 ) ;
F_6 ( ( V_95 >> 8 ) | F_28 ( V_17 ) ,
V_2 -> V_9 + V_97 ) ;
V_19 = F_7 ( V_2 , V_4 , V_6 , F_26 , 0 ) ;
if ( V_19 )
return V_19 ;
F_2 ( V_2 -> V_9 + V_97 ) ;
V_4 -> V_98 [ V_17 ] = V_95 ;
}
return V_6 -> V_13 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
unsigned int V_99 ;
unsigned int V_95 ;
V_99 = F_30 ( V_4 , V_12 ) ;
if ( V_99 ) {
F_6 ( V_100 , V_2 -> V_9 + V_67 ) ;
if ( ( ( V_77 -> V_101 & V_102 ) == 0 ) ||
( ( V_77 -> V_101 & V_103 ) == 0 ) ) {
V_95 = ( V_4 -> V_104 & 0x00ff0000 ) >> 16 ;
F_6 ( V_95 , V_2 -> V_9 + V_105 ) ;
}
if ( ( V_77 -> V_101 & V_106 ) == 0 ) {
V_95 = ( V_4 -> V_104 & 0x0000ff00 ) >> 8 ;
F_6 ( V_95 , V_2 -> V_9 + V_107 ) ;
}
if ( ( V_77 -> V_101 & V_108 ) == 0 ) {
V_95 = ( V_4 -> V_104 & 0x000000ff ) ;
F_6 ( V_95 , V_2 -> V_9 + V_109 ) ;
}
}
V_95 = F_2 ( V_2 -> V_9 + V_109 ) ;
V_95 |= F_2 ( V_2 -> V_9 + V_107 ) << 8 ;
V_95 |= F_2 ( V_2 -> V_9 + V_105 ) << 16 ;
V_4 -> V_104 = V_95 ;
V_12 [ 1 ] = V_95 ;
return V_6 -> V_13 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
unsigned int V_17 = F_4 ( V_6 -> V_20 ) ;
unsigned int V_99 ;
unsigned char V_110 ;
int V_19 ;
if ( V_17 < 8 ) {
V_99 = 0x0000ff ;
V_110 = V_108 ;
} else if ( V_17 < 16 ) {
V_99 = 0x00ff00 ;
V_110 = V_106 ;
} else if ( V_17 < 20 ) {
V_99 = 0x0f0000 ;
V_110 = V_102 ;
} else {
V_99 = 0xf00000 ;
V_110 = V_103 ;
}
V_19 = F_32 ( V_2 , V_4 , V_6 , V_12 , V_99 ) ;
if ( V_19 )
return V_19 ;
if ( V_12 [ 0 ] == V_111 )
V_77 -> V_101 &= ~ V_110 ;
else
V_77 -> V_101 |= V_110 ;
F_6 ( V_100 , V_2 -> V_9 + V_67 ) ;
F_6 ( V_77 -> V_101 , V_2 -> V_9 + V_112 ) ;
return V_6 -> V_13 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
struct V_76 * V_77 ;
int V_19 ;
struct V_3 * V_4 ;
unsigned char V_115 , V_116 , V_117 , V_118 , V_86 , V_119 ;
V_19 = F_34 ( V_2 , V_114 -> V_120 [ 0 ] , 0x10 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_121 , V_2 -> V_9 + V_67 ) ;
F_35 ( 1000 ) ;
F_6 ( 0x0 , V_2 -> V_9 + V_23 ) ;
F_6 ( 0x0 , V_2 -> V_9 + V_75 ) ;
F_6 ( 0x80 , V_2 -> V_9 + V_24 ) ;
F_6 ( 0xff , V_2 -> V_9 + V_25 ) ;
F_6 ( V_122 , V_2 -> V_9 + V_27 ) ;
F_35 ( 100 ) ;
V_116 = F_2 ( V_2 -> V_9 + V_24 ) ;
V_115 = F_2 ( V_2 -> V_9 + V_25 ) ;
V_117 = F_2 ( V_2 -> V_9 + V_123 ) ;
V_118 = F_2 ( V_2 -> V_9 + V_30 ) ;
V_86 = F_2 ( V_2 -> V_9 + V_75 ) ;
V_119 = F_2 ( V_2 -> V_9 + V_28 ) ;
if ( ( V_116 != 0x00 ) || ( V_115 != 0x1f ) || ( V_117 != 0x80 ) ||
( V_118 != 0x60 || ( V_86 != 0x00 ) || V_119 != 0x0c ) ) {
F_23 ( V_2 -> V_42 , L_4 ) ;
return - V_124 ;
}
if ( V_114 -> V_120 [ 1 ] ) {
V_19 = F_36 ( V_114 -> V_120 [ 1 ] , F_22 , 0 ,
V_2 -> V_125 , V_2 ) ;
if ( V_19 == 0 )
V_2 -> V_85 = V_114 -> V_120 [ 1 ] ;
}
V_77 = F_37 ( V_2 , sizeof( * V_77 ) ) ;
if ( ! V_77 )
return - V_126 ;
V_19 = F_38 ( V_2 , 3 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_127 [ 0 ] ;
V_4 -> type = V_128 ;
V_4 -> V_129 = V_130 | V_131 | V_132 ;
V_4 -> V_21 = 32 ;
V_4 -> V_133 = 0xffff ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_136 = F_3 ;
if ( V_2 -> V_85 ) {
V_2 -> V_90 = V_4 ;
V_4 -> V_129 |= V_137 ;
V_4 -> V_138 = 32 ;
V_4 -> V_139 = F_20 ;
V_4 -> V_140 = F_11 ;
V_4 -> V_141 = F_21 ;
}
V_4 = & V_2 -> V_127 [ 1 ] ;
V_4 -> type = V_142 ;
V_4 -> V_129 = V_143 ;
V_4 -> V_21 = 4 ;
V_4 -> V_133 = 0x0fff ;
V_4 -> V_134 = & V_144 ;
V_4 -> V_145 = F_27 ;
V_4 -> V_136 = V_146 ;
V_19 = F_39 ( V_4 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_127 [ 2 ] ;
F_6 ( V_100 , V_2 -> V_9 + V_67 ) ;
V_77 -> V_101 = V_108 | V_106 |
V_102 | V_103 | V_147 ;
F_6 ( V_77 -> V_101 , V_2 -> V_9 + V_112 ) ;
V_4 -> type = V_148 ;
V_4 -> V_129 = V_130 | V_143 ;
V_4 -> V_21 = 24 ;
V_4 -> V_133 = 1 ;
V_4 -> V_104 = 0 ;
V_4 -> V_134 = & V_149 ;
V_4 -> V_150 = F_29 ;
V_4 -> V_151 = F_31 ;
return 0 ;
}
