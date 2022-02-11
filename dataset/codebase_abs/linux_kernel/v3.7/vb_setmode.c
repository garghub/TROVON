void F_1 ( unsigned char V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = & V_5 ;
V_3 -> V_6 = V_7 ;
V_3 -> V_8 = V_9 ;
V_3 -> V_10 = V_11 ;
V_3 -> V_12 = V_13 ;
V_3 -> V_14 = V_15 ;
V_3 -> V_16 = V_17 ;
V_3 -> V_18 = V_19 ;
V_3 -> V_20 = V_21 ;
V_3 -> V_22 = V_23 ;
V_3 -> V_24 = V_25 ;
V_3 -> V_26 = 0 ;
V_3 -> V_27 = 0 ;
V_3 -> V_28 = 0 ;
V_3 -> V_29 = 0 ;
V_3 -> V_30 = 0 ;
V_3 -> V_31 = V_32 ;
V_3 -> V_33 = V_34 ;
V_3 -> V_35 = V_36 ;
V_3 -> V_37 = V_38 ;
V_3 -> V_39 = V_40 ;
V_3 -> V_41 = V_42 ;
V_3 -> V_43 = V_44 ;
V_3 -> V_45 = V_46 ;
V_3 -> V_47 = 0xa3 ;
V_3 -> V_48 = 0xfb ;
V_3 -> V_49 = V_50 ;
V_3 -> V_51 = V_52 ;
V_3 -> V_53 = V_54 ;
if ( ( V_3 -> V_55 & V_56 ) || ( V_3 -> V_55 & V_57 ) )
V_3 -> V_58 = V_59 ;
else
V_3 -> V_58 = V_60 ;
if ( V_1 >= V_61 )
V_3 -> V_62 = 0x10 ;
if ( V_1 == V_63 ) {
unsigned char V_64 ;
V_3 -> V_12 = V_65 ;
V_3 -> V_33 = V_66 ;
V_3 -> V_62 = 0xc1 ;
V_3 -> V_31 = V_67 ;
V_64 = F_2 ( V_3 -> V_68 , 0x3B ) ;
if ( ( ( V_64 & 0x88 ) == 0x80 ) || ( ( V_64 & 0x88 ) == 0x08 ) )
V_3 -> V_62 = 0x80 ;
}
}
static void F_3 ( unsigned short V_69 ,
unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned char V_71 , V_72 ;
unsigned short V_73 , V_74 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
F_4 ( V_3 -> V_68 , 0x00 , 0x03 ) ;
V_71 = V_3 -> V_4 -> V_76 [ 0 ] ;
V_73 = V_77 ;
if ( V_3 -> V_29 & V_77 ) {
V_71 |= 0x01 ;
} else if ( V_3 -> V_29 & ( V_78 | V_79 ) ) {
if ( V_3 -> V_29 & V_80 )
V_71 |= 0x01 ;
}
V_71 |= 0x20 ;
F_4 ( V_3 -> V_68 , 0x01 , V_71 ) ;
for ( V_73 = 02 ; V_73 <= 04 ; V_73 ++ ) {
V_72 = V_3 -> V_4 -> V_76 [ V_73 - 1 ] ;
F_4 ( V_3 -> V_68 , V_73 , V_72 ) ;
}
}
static void F_5 ( struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned char V_83 ;
unsigned short V_73 ;
V_83 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x11 ) ;
V_83 &= 0x7f ;
F_4 ( V_3 -> V_84 , 0x11 , V_83 ) ;
for ( V_73 = 0 ; V_73 <= 0x18 ; V_73 ++ ) {
V_83 = V_3 -> V_4 -> V_85 [ V_73 ] ;
F_4 ( V_3 -> V_84 , V_73 , V_83 ) ;
}
}
static void F_6 ( unsigned short V_69 ,
unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned char V_86 ;
unsigned short V_73 , V_74 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
for ( V_73 = 0 ; V_73 <= 0x13 ; V_73 ++ ) {
V_86 = V_3 -> V_4 -> V_87 [ V_73 ] ;
if ( ( V_74 & V_88 ) && V_73 == 0x13 ) {
if ( V_3 -> V_29 & V_77 ) {
V_86 = 0 ;
} else if ( ( V_3 -> V_29 &
( V_78 | V_79 ) ) &&
( V_3 -> V_29 & V_80 ) ) {
V_86 = 0 ;
}
}
F_7 ( V_3 -> V_89 ) ;
F_8 ( V_73 , V_3 -> V_90 ) ;
F_8 ( V_86 , V_3 -> V_90 ) ;
}
F_7 ( V_3 -> V_89 ) ;
F_8 ( 0x14 , V_3 -> V_90 ) ;
F_8 ( 0x00 , V_3 -> V_90 ) ;
F_7 ( V_3 -> V_89 ) ;
F_8 ( 0x20 , V_3 -> V_90 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
unsigned char V_91 ;
unsigned short V_73 ;
for ( V_73 = 0 ; V_73 <= 0x08 ; V_73 ++ ) {
V_91 = V_3 -> V_4 -> V_92 [ V_73 ] ;
F_4 ( V_3 -> V_93 , V_73 , V_91 ) ;
}
if ( V_3 -> V_94 > V_95 ) {
V_91 = ( unsigned char ) F_2 ( V_3 -> V_93 , 0x05 ) ;
V_91 &= 0xBF ;
F_4 ( V_3 -> V_93 , 0x05 , V_91 ) ;
}
}
static void F_10 ( struct V_2 * V_3 )
{
unsigned short V_73 ;
for ( V_73 = 0x0A ; V_73 <= 0x0E ; V_73 ++ )
F_4 ( V_3 -> V_68 , V_73 , 0x00 ) ;
}
static unsigned char F_11 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_68 , 0x31 , ~ 0x30 , 0x20 ) ;
F_4 ( V_3 -> V_68 , 0x2B , V_3 -> V_16 [ 0 ] . V_96 ) ;
F_4 ( V_3 -> V_68 , 0x2C , V_3 -> V_16 [ 0 ] . V_97 ) ;
F_12 ( V_3 -> V_68 , 0x31 , ~ 0x30 , 0x10 ) ;
F_4 ( V_3 -> V_68 , 0x2B , V_3 -> V_16 [ 1 ] . V_96 ) ;
F_4 ( V_3 -> V_68 , 0x2C , V_3 -> V_16 [ 1 ] . V_97 ) ;
F_13 ( V_3 -> V_68 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_14 ( unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 , unsigned short * V_73 ,
struct V_2 * V_3 )
{
unsigned short V_99 , V_100 , V_101 , V_74 , V_102 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_100 = V_3 -> V_8 [ V_98 + ( * V_73 ) ] . V_104 ;
V_99 = 0 ;
if ( V_3 -> V_105 == 0 ) {
if ( V_3 -> V_29 & V_106 ) {
V_99 |= V_107 ;
if ( V_3 -> V_55 & V_108 )
V_99 |= V_109 ;
}
if ( V_3 -> V_29 & ( V_79 | V_77 ) ) {
V_99 |= V_110 ;
if ( V_3 -> V_26 != V_111 &&
V_3 -> V_26 != V_112 &&
( V_3 -> V_28 & V_113 ) &&
V_101 >= 9 )
return 0 ;
}
if ( V_3 -> V_29 & V_114 ) {
V_99 |= V_115 ;
if ( ( V_3 -> V_29 & V_80 ) &&
( ( V_101 == 4 ) ||
( V_101 == 3 &&
( V_3 -> V_116 & V_117 ) ) ||
( V_101 > 7 ) ) )
return 0 ;
} else if ( V_3 -> V_29 & ( V_118 |
V_119 |
V_120 |
V_121 |
V_114 ) ) {
V_99 |= V_122 ;
if ( V_3 -> V_55 & ( V_123 |
V_124 |
V_56 |
V_57 |
V_108 ) )
V_99 |= V_125 ;
if ( ! ( V_3 -> V_29 & V_126 ) &&
( V_74 & V_127 ) &&
( V_3 -> V_29 & V_80 ) &&
( ! ( V_3 -> V_29 & V_128 ) ) )
return 0 ;
}
} else if ( V_3 -> V_29 & V_79 ) {
V_99 |= V_110 ;
if ( V_101 > 0x08 )
return 0 ;
if ( V_3 -> V_26 < V_129 ) {
if ( V_101 > 0x07 )
return 0 ;
if ( V_101 == 0x04 )
return 0 ;
}
}
for (; V_3 -> V_8 [ V_98 + ( * V_73 ) ] . V_104 ==
V_100 ; ( * V_73 ) -- ) {
V_102 = V_3 -> V_8 [ V_98 + ( * V_73 ) ] .
V_130 ;
if ( V_102 & V_99 )
return 1 ;
if ( ( * V_73 ) == 0 )
break;
}
for ( ( * V_73 ) = 0 ; ; ( * V_73 ) ++ ) {
V_102 = V_3 -> V_8 [ V_98 + ( * V_73 ) ] .
V_130 ;
if ( V_3 -> V_8 [ V_98 + ( * V_73 ) ] . V_104
!= V_100 ) {
return 0 ;
}
if ( V_102 & V_99 )
return 1 ;
}
return 1 ;
}
static void F_15 ( unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_131 , V_64 ;
V_131 = V_3 -> V_8 [ V_98 ] . V_130 >> 8 ;
V_131 &= 0xC0 ;
V_64 = 0x2F ;
V_64 |= V_131 ;
F_8 ( V_64 , V_3 -> V_132 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_81 * V_82 )
{
unsigned char V_133 , V_134 , V_135 ;
unsigned short V_73 , V_136 ;
V_133 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x11 ) ;
V_133 &= 0x7F ;
F_4 ( V_3 -> V_84 , 0x11 , V_133 ) ;
V_133 = V_3 -> V_49 [ 0 ] . V_133 [ 0 ] ;
F_4 ( V_3 -> V_84 , 0 , V_133 ) ;
for ( V_73 = 0x01 ; V_73 <= 0x04 ; V_73 ++ ) {
V_133 = V_3 -> V_49 [ 0 ] . V_133 [ V_73 ] ;
F_4 ( V_3 -> V_84 , ( unsigned short ) ( V_73 + 1 ) , V_133 ) ;
}
for ( V_73 = 0x05 ; V_73 <= 0x06 ; V_73 ++ ) {
V_133 = V_3 -> V_49 [ 0 ] . V_133 [ V_73 ] ;
F_4 ( V_3 -> V_68 , ( unsigned short ) ( V_73 + 6 ) , V_133 ) ;
}
V_136 = ( unsigned char ) F_2 ( V_3 -> V_68 , 0x0e ) ;
V_136 &= 0x1F ;
V_133 = V_3 -> V_49 [ 0 ] . V_133 [ 7 ] ;
V_133 &= 0xE0 ;
V_133 |= V_136 ;
F_4 ( V_3 -> V_68 , 0x0e , V_133 ) ;
if ( V_82 -> V_137 >= V_61 ) {
V_133 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x04 ) ;
V_133 = V_133 - 1 ;
F_4 ( V_3 -> V_84 , 0x04 , V_133 ) ;
V_133 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x05 ) ;
V_134 = V_133 ;
V_134 &= 0xE0 ;
V_133 &= 0x1F ;
if ( V_133 == 0 ) {
V_135 = V_133 ;
V_133 = ( unsigned char ) F_2 ( V_3 -> V_68 ,
0x0c ) ;
V_133 &= 0xFB ;
F_4 ( V_3 -> V_68 , 0x0c , V_133 ) ;
V_133 = V_135 ;
}
V_133 = V_133 - 1 ;
V_133 |= V_134 ;
F_4 ( V_3 -> V_84 , 0x05 , V_133 ) ;
V_133 = ( unsigned char ) F_2 ( V_3 -> V_68 , 0x0e ) ;
V_133 = V_133 >> 5 ;
V_133 = V_133 + 3 ;
if ( V_133 > 7 )
V_133 = V_133 - 7 ;
V_133 = V_133 << 5 ;
F_12 ( V_3 -> V_68 , 0x0e , ~ 0xE0 , V_133 ) ;
}
}
static void F_17 ( unsigned short V_70 ,
unsigned short V_69 ,
struct V_2 * V_3 )
{
unsigned char V_133 ;
unsigned short V_73 , V_136 ;
for ( V_73 = 0x00 ; V_73 <= 0x01 ; V_73 ++ ) {
V_133 = V_3 -> V_51 [ 0 ] . V_133 [ V_73 ] ;
F_4 ( V_3 -> V_84 , ( unsigned short ) ( V_73 + 6 ) , V_133 ) ;
}
for ( V_73 = 0x02 ; V_73 <= 0x03 ; V_73 ++ ) {
V_133 = V_3 -> V_51 [ 0 ] . V_133 [ V_73 ] ;
F_4 ( V_3 -> V_84 , ( unsigned short ) ( V_73 + 0x0e ) , V_133 ) ;
}
for ( V_73 = 0x04 ; V_73 <= 0x05 ; V_73 ++ ) {
V_133 = V_3 -> V_51 [ 0 ] . V_133 [ V_73 ] ;
F_4 ( V_3 -> V_84 , ( unsigned short ) ( V_73 + 0x11 ) , V_133 ) ;
}
V_136 = ( unsigned char ) F_2 ( V_3 -> V_68 , 0x0a ) ;
V_136 &= 0xC0 ;
V_133 = V_3 -> V_51 [ 0 ] . V_133 [ 6 ] ;
V_133 &= 0x3F ;
V_133 |= V_136 ;
F_4 ( V_3 -> V_68 , 0x0a , V_133 ) ;
V_133 = V_3 -> V_51 [ 0 ] . V_133 [ 6 ] ;
V_133 &= 0x80 ;
V_133 = V_133 >> 2 ;
V_73 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_73 &= V_138 ;
if ( V_73 )
V_133 |= 0x80 ;
V_136 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x09 ) ;
V_136 &= 0x5F ;
V_133 |= V_136 ;
F_4 ( V_3 -> V_84 , 0x09 , V_133 ) ;
}
static void F_18 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 ,
struct V_81 * V_82 )
{
unsigned char V_139 , V_133 ;
unsigned short V_73 ;
V_139 = V_3 -> V_8 [ V_98 ] . V_140 ;
V_139 = V_139 & V_141 ;
V_133 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x11 ) ;
V_133 &= 0x7F ;
F_4 ( V_3 -> V_84 , 0x11 , V_133 ) ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ )
V_3 -> V_49 [ 0 ] . V_133 [ V_73 ]
= V_3 -> V_10 [ V_139 ] . V_142 [ V_73 ] ;
for ( V_73 = 0 ; V_73 < 7 ; V_73 ++ )
V_3 -> V_51 [ 0 ] . V_133 [ V_73 ]
= V_3 -> V_10 [ V_139 ] . V_142 [ V_73 + 8 ] ;
F_16 ( V_3 , V_82 ) ;
F_17 ( V_70 , V_69 , V_3 ) ;
if ( V_3 -> V_94 > 0x03 )
F_4 ( V_3 -> V_84 , 0x14 , 0x4F ) ;
}
static void F_19 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned char V_139 , V_143 , V_144 , V_145 , V_146 ;
unsigned short V_147 , V_148 , V_149 ;
V_139 = V_3 -> V_8 [ V_98 ] . V_140 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 3 ] ;
V_145 = V_143 ;
F_4 ( V_3 -> V_68 , 0x2E , V_143 ) ;
V_146 = V_3 -> V_10 [ V_139 ] . V_142 [ 5 ] ;
V_146 &= 0xC0 ;
V_147 = V_146 ;
V_147 <<= 2 ;
V_147 |= V_143 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 4 ] ;
V_143 &= 0x1F ;
V_144 = V_3 -> V_10 [ V_139 ] . V_142 [ 6 ] ;
V_144 &= 0x04 ;
V_144 <<= 3 ;
V_143 |= V_144 ;
V_148 = V_147 & 0x3C0 ;
V_148 |= V_143 ;
V_145 &= 0x3F ;
if ( V_143 < V_145 )
V_148 |= 0x40 ;
V_148 &= 0xFF ;
V_143 = ( unsigned char ) V_148 ;
V_143 <<= 2 ;
V_146 >>= 6 ;
V_143 |= V_146 ;
F_4 ( V_3 -> V_68 , 0x2F , V_143 ) ;
F_12 ( V_3 -> V_68 , 0x30 , 0xE3 , 00 ) ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 10 ] ;
V_144 = V_143 ;
V_143 &= 0x01 ;
F_20 ( V_3 -> V_68 , 0x33 , V_143 ) ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 9 ] ;
V_145 = V_144 >> 1 ;
V_146 = V_143 & 0x04 ;
V_146 <<= 5 ;
V_145 |= V_146 ;
F_4 ( V_3 -> V_68 , 0x34 , V_145 ) ;
V_147 = V_146 ;
V_147 <<= 1 ;
V_147 |= V_144 ;
V_143 &= 0x80 ;
V_148 = V_143 << 2 ;
V_147 |= V_148 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 14 ] ;
V_143 &= 0x08 ;
V_148 = V_143 ;
V_148 <<= 7 ;
V_147 |= V_148 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 11 ] ;
V_143 &= 0x0F ;
V_144 = V_3 -> V_10 [ V_139 ] . V_142 [ 14 ] ;
V_144 &= 0x20 ;
V_144 >>= 1 ;
V_143 |= V_144 ;
V_148 = V_147 & 0x7E0 ;
V_148 |= V_143 ;
V_149 = V_147 & 0x1F ;
if ( V_143 < V_149 )
V_148 |= 0x20 ;
V_148 &= 0xFF ;
V_143 = ( unsigned char ) V_148 ;
V_143 <<= 2 ;
V_147 &= 0x600 ;
V_147 >>= 9 ;
V_144 = ( unsigned char ) V_147 ;
V_143 |= V_144 ;
V_143 &= 0x7F ;
F_4 ( V_3 -> V_68 , 0x3F , V_143 ) ;
}
static void F_21 ( unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_139 , V_143 , V_144 , V_145 ;
V_139 = V_3 -> V_8 [ V_98 ] . V_140 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 3 ] ;
V_144 = V_143 ;
F_4 ( V_3 -> V_68 , 0x2E , V_143 ) ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 5 ] ;
V_143 &= 0xC0 ;
V_144 |= ( V_143 << 2 ) ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 4 ] ;
V_143 &= 0x1F ;
V_145 = V_143 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 6 ] ;
V_143 &= 0x04 ;
V_143 <<= 3 ;
V_145 |= V_143 ;
V_144 = V_144 & 0x3C0 ;
V_144 |= V_145 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 3 ] ;
V_143 &= 0x3F ;
if ( V_145 <= V_143 )
V_144 += 0x40 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 5 ] ;
V_143 &= 0xC0 ;
V_143 >>= 6 ;
V_143 |= ( ( V_144 << 2 ) & 0xFF ) ;
F_4 ( V_3 -> V_68 , 0x2F , V_143 ) ;
F_12 ( V_3 -> V_68 , 0x30 , 0xE3 , 00 ) ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 10 ] ;
F_4 ( V_3 -> V_68 , 0x34 , V_143 ) ;
V_145 = V_143 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 9 ] ;
V_144 = V_143 ;
V_143 = V_143 & 0x04 ;
V_143 >>= 2 ;
F_12 ( V_3 -> V_68 , 0x35 , ~ 0x01 , V_143 ) ;
V_145 |= ( V_143 << 8 ) ;
V_145 |= ( ( V_144 & 0x80 ) << 2 ) ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 14 ] ;
V_143 &= 0x08 ;
V_145 |= ( V_143 << 7 ) ;
V_143 = V_3 -> V_10 [ V_139 ] . V_142 [ 11 ] ;
V_143 &= 0x0F ;
V_144 = V_3 -> V_10 [ V_139 ] . V_142 [ 14 ] ;
V_144 &= 0x20 ;
V_144 >>= 1 ;
V_143 |= V_144 ;
V_144 = V_145 ;
V_144 &= 0x7E0 ;
V_144 |= V_143 ;
if ( V_144 <= V_145 )
V_144 |= 0x20 ;
V_143 = ( V_144 << 2 ) & 0xFF ;
F_12 ( V_3 -> V_68 , 0x3F , ~ 0xFC , V_143 ) ;
V_143 = V_145 >> 8 ;
F_12 ( V_3 -> V_68 , 0x35 , ~ 0x07 , V_143 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned char V_64 ;
V_64 = F_2 ( V_3 -> V_84 , 0x37 ) ;
V_64 = ( V_64 & 3 ) << 6 ;
F_12 ( V_3 -> V_68 , 0x06 , ~ 0xc0 , V_64 & 0x80 ) ;
F_12 ( V_3 -> V_68 , 0x09 , ~ 0xc0 , V_64 | 0x80 ) ;
}
static void F_23 ( int V_150 ,
struct V_2 * V_3 ,
unsigned short V_98 ,
unsigned short V_69 )
{
unsigned short V_151 , V_152 ;
unsigned short V_153 ;
V_153 = V_3 -> V_154 ;
F_4 ( V_3 -> V_84 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_84 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_84 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_84 , 0x47 , 0x00 ) ;
if ( V_150 == V_63 ) {
V_152 = F_2 ( V_3 -> V_84 , 0x37 ) ;
if ( ( V_152 & 0x03 ) == 0 ) {
F_4 ( V_3 -> V_84 , 0x46 , 0x13 ) ;
F_4 ( V_3 -> V_84 , 0x47 , 0x13 ) ;
}
}
if ( V_150 == V_63 ) {
F_22 ( V_3 ) ;
} else {
V_152 = F_2 ( V_3 -> V_84 , 0x37 ) ;
if ( V_152 & 0x01 ) {
F_20 ( V_3 -> V_68 , 0x06 , 0x40 ) ;
F_20 ( V_3 -> V_68 , 0x09 , 0x40 ) ;
}
}
F_20 ( V_3 -> V_68 , 0x1E , 0x01 ) ;
F_13 ( V_3 -> V_68 , 0x30 , ~ 0x20 ) ;
F_13 ( V_3 -> V_68 , 0x35 , ~ 0x80 ) ;
V_151 = V_3 -> V_8 [ V_98 ] . V_130 ;
if ( V_151 & 0x4000 )
F_20 ( V_3 -> V_68 , 0x30 , 0x20 ) ;
if ( V_151 & 0x8000 )
F_20 ( V_3 -> V_68 , 0x35 , 0x80 ) ;
}
static void F_24 ( unsigned short V_69 ,
struct V_2 * V_3 ,
unsigned short V_98 )
{
int V_139 = - 1 ;
F_13 ( V_3 -> V_84 , 0x11 , 0x7F ) ;
if ( V_69 == 0x2E &&
( V_3 -> V_8 [ V_98 ] . V_140 ==
V_155 ) )
V_139 = 12 ;
else if ( V_69 == 0x2E && ( V_3 -> V_8 [ V_98 ] .
V_140 == V_156 ) )
V_139 = 13 ;
else if ( V_69 == 0x2F )
V_139 = 14 ;
else if ( V_69 == 0x50 )
V_139 = 15 ;
else if ( V_69 == 0x59 )
V_139 = 16 ;
if ( V_139 != - 1 ) {
F_4 ( V_3 -> V_84 , 0x02 ,
V_3 -> V_53 [ V_139 ] . V_157 ) ;
F_4 ( V_3 -> V_84 , 0x03 ,
V_3 -> V_53 [ V_139 ] . V_158 ) ;
F_4 ( V_3 -> V_84 , 0x15 ,
V_3 -> V_53 [ V_139 ] . V_159 ) ;
F_4 ( V_3 -> V_84 , 0x16 ,
V_3 -> V_53 [ V_139 ] . V_160 ) ;
}
}
static void F_25 ( struct V_81 * V_82 ,
unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_161 , V_99 , V_100 , V_162 , V_64 , V_74 ;
unsigned char V_133 ;
V_161 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_99 = V_3 -> V_24 [ V_161 ] . V_163 ;
V_100 = V_3 -> V_24 [ V_161 ] . V_164 ;
if ( V_74 & V_165 )
V_99 = V_99 >> 1 ;
if ( V_74 & V_165 )
V_99 = V_99 << 1 ;
V_64 = V_3 -> V_8 [ V_98 ] . V_130 ;
if ( V_64 & V_166 )
V_100 = V_100 >> 1 ;
if ( V_74 & V_138 )
V_100 = V_100 << 1 ;
V_162 = 8 ;
V_99 /= V_162 ;
V_99 -= 1 ;
V_100 -= 1 ;
V_162 = V_99 ;
V_64 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x11 ) ;
V_133 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x11 ) ;
V_133 &= 0x7F ;
F_4 ( V_3 -> V_84 , 0x11 , V_133 ) ;
F_4 ( V_3 -> V_84 , 0x01 , ( unsigned short ) ( V_162 & 0xff ) ) ;
F_12 ( V_3 -> V_84 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_162 & 0x0ff00 ) >> 10 ) ) ;
F_4 ( V_3 -> V_84 , 0x12 , ( unsigned short ) ( V_100 & 0xff ) ) ;
V_99 = 0 ;
V_100 = V_100 >> 8 ;
if ( V_100 & 0x01 )
V_99 |= 0x02 ;
if ( V_100 & 0x02 )
V_99 |= 0x40 ;
F_12 ( V_3 -> V_84 , 0x07 , ~ 0x42 , V_99 ) ;
V_133 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x07 ) ;
V_133 &= 0xFF ;
V_99 = 0 ;
if ( V_100 & 0x04 )
V_99 |= 0x02 ;
F_12 ( V_3 -> V_84 , 0x0a , ~ 0x02 , V_99 ) ;
F_4 ( V_3 -> V_84 , 0x11 , V_64 ) ;
}
static void F_26 ( unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_64 , V_167 , V_168 , V_169 , V_73 , V_170 ;
V_64 = V_3 -> V_6 [ V_70 ] . V_171 ;
V_64 = V_64 >> 8 ;
V_64 = V_3 -> V_20 [ V_64 ] ;
V_169 = V_3 -> V_8 [ V_98 ] . V_130 ;
V_169 &= V_166 ;
if ( V_169 )
V_64 = V_64 << 1 ;
V_169 = V_3 -> V_94 - V_172 ;
switch ( V_169 ) {
case 0 :
V_169 = 1 ;
break;
case 1 :
V_169 = 2 ;
break;
case 2 :
V_169 = 4 ;
break;
case 3 :
V_169 = 4 ;
break;
case 4 :
V_169 = 6 ;
break;
case 5 :
V_169 = 8 ;
break;
default:
break;
}
if ( ( V_69 >= 0x26 ) && ( V_69 <= 0x28 ) )
V_64 = V_64 * V_169 + V_169 / 2 ;
else
V_64 *= V_169 ;
V_170 = V_64 ;
V_169 = V_64 ;
V_64 = V_64 >> 8 ;
V_64 &= 0x0F ;
V_73 = F_2 ( V_3 -> V_68 , 0x0E ) ;
V_73 &= 0xF0 ;
V_73 |= V_64 ;
F_4 ( V_3 -> V_68 , 0x0E , V_73 ) ;
V_64 = ( unsigned char ) V_169 ;
V_64 &= 0xFF ;
F_4 ( V_3 -> V_84 , 0x13 , V_64 ) ;
V_169 = V_3 -> V_8 [ V_98 ] . V_130 ;
V_169 &= V_166 ;
if ( V_169 )
V_170 >>= 1 ;
V_170 = V_170 << 5 ;
V_167 = ( V_170 & 0xff00 ) >> 8 ;
V_168 = V_170 & 0x00ff ;
if ( V_168 == 0 )
V_167 += 1 ;
else
V_167 += 2 ;
if ( V_82 -> V_137 >= V_61 )
if ( ( V_69 == 0x4A ) | ( V_69 == 0x49 ) )
V_167 -= 1 ;
F_4 ( V_3 -> V_68 , 0x10 , V_167 ) ;
}
static unsigned short F_27 ( unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_173 , V_174 ;
unsigned short V_74 , V_101 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_173 = V_3 -> V_8 [ V_98 ] . V_175 ;
if ( V_3 -> V_105 == 0 ) {
V_173 = V_173 >> 6 ;
if ( V_3 -> V_29 &
( V_79 | V_77 ) ) {
if ( V_3 -> V_26 != V_129 )
V_174 = V_176 + 5 ;
else
V_174 = V_177 + 2 ;
} else if ( V_3 -> V_29 & V_114 ) {
if ( V_3 -> V_116 & V_178 )
V_174 = V_179 + V_180 ;
else
V_174 = V_179 + V_181 ;
if ( V_3 -> V_116 & V_117 ) {
if ( V_74 & V_88 ) {
V_174 = V_179 +
V_182 ;
} else {
V_174 = V_179 +
V_183 ;
}
}
if ( V_3 -> V_55 & V_56 ) {
if ( V_3 -> V_116 & V_178 )
V_174 = V_184 ;
else
V_174 = V_185 ;
}
} else if ( V_3 -> V_29 & V_78 ) {
if ( V_3 -> V_116 & V_178 )
V_174 = V_179 + V_186 ;
else
V_174 = V_179 + V_187 ;
} else {
V_174 = V_3 -> V_8 [ V_98 ] .
V_188 ;
V_174 &= V_141 ;
}
} else if ( ( V_3 -> V_26 == V_189 ) ||
( V_3 -> V_26 == V_190 ) ) {
V_174 = V_191 ;
} else {
V_174 = V_177 + 2 ;
}
return V_174 ;
}
static void F_28 ( unsigned short V_69 ,
unsigned short V_70 ,
struct V_81 * V_82 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned char V_139 , V_133 ;
unsigned short V_192 ;
if ( V_3 -> V_105 == 1 ) {
V_139 = V_3 -> V_8 [ V_98 ] . V_188 ;
V_133 = F_2 ( V_3 -> V_68 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_68 , 0x31 , V_133 ) ;
F_4 ( V_3 -> V_68 , 0x2B ,
V_3 -> V_16 [ V_139 ] . V_96 ) ;
F_4 ( V_3 -> V_68 , 0x2C ,
V_3 -> V_16 [ V_139 ] . V_97 ) ;
F_4 ( V_3 -> V_68 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) && ( V_3 -> V_29
& V_77 ) ) {
V_192 = F_27 ( V_69 , V_70 ,
V_98 , V_82 ,
V_3 ) ;
V_133 = F_2 ( V_3 -> V_68 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_68 , 0x31 , V_133 ) ;
V_133 = V_3 -> V_18 [ V_192 ] . V_193 ;
F_4 ( V_3 -> V_68 , 0x2B , V_133 ) ;
V_133 = V_3 -> V_18 [ V_192 ] . V_194 ;
F_4 ( V_3 -> V_68 , 0x2C , V_133 ) ;
F_4 ( V_3 -> V_68 , 0x2D , 0x01 ) ;
} else {
V_139 = V_3 -> V_8 [ V_98 ] . V_188 ;
V_133 = F_2 ( V_3 -> V_68 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_68 , 0x31 , V_133 ) ;
F_4 ( V_3 -> V_68 , 0x2B ,
V_3 -> V_16 [ V_139 ] . V_96 ) ;
F_4 ( V_3 -> V_68 , 0x2C ,
V_3 -> V_16 [ V_139 ] . V_97 ) ;
F_4 ( V_3 -> V_68 , 0x2D , 0x01 ) ;
}
if ( V_82 -> V_137 >= V_61 ) {
if ( V_3 -> V_6 [ V_70 ] . V_75 &
V_165 ) {
V_133 = F_2 ( V_3 -> V_68 , 0x2B ) ;
F_4 ( V_3 -> V_68 , 0x2B , V_133 ) ;
V_133 = F_2 ( V_3 -> V_68 , 0x2C ) ;
V_139 = V_133 ;
V_139 &= 0xE0 ;
V_133 &= 0x1F ;
V_133 = V_133 << 1 ;
V_133 += 1 ;
V_133 |= V_139 ;
F_4 ( V_3 -> V_68 , 0x2C , V_133 ) ;
}
}
}
static void F_29 ( struct V_2 * V_3 )
{
unsigned char V_64 ;
V_64 = F_2 ( V_3 -> V_84 , 0x37 ) ;
V_64 = ( V_64 & 1 ) << 6 ;
F_12 ( V_3 -> V_68 , 0x06 , ~ 0x40 , V_64 ) ;
F_12 ( V_3 -> V_68 , 0x09 , ~ 0xc0 , V_64 | 0x80 ) ;
}
static void F_30 ( unsigned short V_69 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_133 ;
V_133 = F_2 ( V_3 -> V_68 , 0x3D ) ;
V_133 &= 0xfe ;
F_4 ( V_3 -> V_68 , 0x3D , V_133 ) ;
F_4 ( V_3 -> V_68 , 0x08 , 0x34 ) ;
V_133 = F_2 ( V_3 -> V_68 , 0x09 ) ;
V_133 &= 0xC0 ;
F_4 ( V_3 -> V_68 , 0x09 , V_133 | 0x30 ) ;
V_133 = F_2 ( V_3 -> V_68 , 0x3D ) ;
V_133 |= 0x01 ;
F_4 ( V_3 -> V_68 , 0x3D , V_133 ) ;
if ( V_82 -> V_137 == V_195 )
F_29 ( V_3 ) ;
}
static void F_31 ( struct V_81 * V_82 ,
unsigned short V_69 , unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_133 , V_196 = 0 ;
short V_197 ;
unsigned char V_139 ;
V_139 = V_3 -> V_8 [ V_98 ] . V_188 ;
V_139 &= V_141 ;
V_197 = V_3 -> V_16 [ V_139 ] . CLOCK ;
V_133 = F_2 ( V_3 -> V_68 , 0x32 ) ;
V_133 &= 0xf3 ;
if ( V_197 >= 200 )
V_133 |= 0x0c ;
if ( V_82 -> V_137 >= V_61 )
V_133 &= ~ 0x04 ;
F_4 ( V_3 -> V_68 , 0x32 , V_133 ) ;
if ( V_82 -> V_137 < V_61 ) {
V_133 = F_2 ( V_3 -> V_68 , 0x1F ) ;
V_133 &= 0xE7 ;
if ( V_197 < 200 )
V_133 |= 0x10 ;
F_4 ( V_3 -> V_68 , 0x1F , V_133 ) ;
}
V_196 = 0x00 ;
F_12 ( V_3 -> V_68 , 0x07 , 0xFC , V_196 ) ;
if ( V_82 -> V_137 >= V_63 )
F_12 ( V_3 -> V_68 , 0x40 , 0xFC , V_196 & 0x03 ) ;
}
static void F_32 ( struct V_81 * V_82 ,
unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_133 , V_196 , V_198 , V_102 = 0 , V_74 , V_161 ,
V_199 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_102 = V_3 -> V_8 [ V_98 ] . V_130 ;
if ( F_2 ( V_3 -> V_84 , 0x31 ) & 0x01 )
F_12 ( V_3 -> V_68 , 0x1F , 0x3F , 0x00 ) ;
V_133 = V_102 ;
V_196 = 0 ;
V_196 |= 0x02 ;
V_198 = V_3 -> V_94 - V_95 ;
V_198 = V_198 << 2 ;
V_196 |= V_198 ;
V_133 &= V_166 ;
if ( V_133 )
V_196 |= 0x20 ;
F_12 ( V_3 -> V_68 , 0x06 , ~ 0x3F , V_196 ) ;
V_161 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_199 = V_3 -> V_24 [ V_161 ] . V_163 ;
V_133 = 0x0000 ;
if ( V_102 & V_166 ) {
if ( V_199 == 1024 )
V_133 = 0x0035 ;
else if ( V_199 == 1280 )
V_133 = 0x0048 ;
}
V_196 = V_133 & 0x00FF ;
F_12 ( V_3 -> V_84 , 0x19 , 0xFF , V_196 ) ;
V_196 = ( V_133 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_84 , 0x19 , 0xFC , V_196 ) ;
if ( V_74 & V_165 )
F_12 ( V_3 -> V_68 , 0x01 , 0xF7 , 0x08 ) ;
V_196 = 0 ;
if ( V_74 & V_200 )
V_196 |= 0x08 ;
F_12 ( V_3 -> V_68 , 0x0F , ~ 0x48 , V_196 ) ;
V_133 = 0x60 ;
V_133 = V_133 ^ 0x60 ;
V_133 = V_133 ^ 0xA0 ;
F_12 ( V_3 -> V_68 , 0x21 , 0x1F , V_133 ) ;
F_31 ( V_82 , V_69 , V_98 ,
V_3 ) ;
V_133 = F_2 ( V_3 -> V_84 , 0x31 ) ;
if ( V_82 -> V_137 == V_63 ) {
if ( V_133 & 0x40 )
V_133 = 0x2c ;
else
V_133 = 0x6c ;
F_4 ( V_3 -> V_84 , 0x52 , V_133 ) ;
F_20 ( V_3 -> V_84 , 0x51 , 0x10 ) ;
} else if ( V_82 -> V_137 >= V_61 ) {
if ( V_133 & 0x40 )
V_133 = 0x33 ;
else
V_133 = 0x73 ;
F_4 ( V_3 -> V_84 , 0x52 , V_133 ) ;
F_4 ( V_3 -> V_84 , 0x51 , 0x02 ) ;
} else {
if ( V_133 & 0x40 )
V_133 = 0x2c ;
else
V_133 = 0x6c ;
F_4 ( V_3 -> V_84 , 0x52 , V_133 ) ;
}
}
static void F_33 ( unsigned short V_201 ,
unsigned short V_167 ,
unsigned short V_168 ,
unsigned short V_202 ,
struct V_2 * V_3 )
{
unsigned short V_64 , V_203 , V_204 ;
V_203 = V_167 ;
V_204 = V_168 ;
if ( V_201 != 0 ) {
V_64 = V_203 ;
V_203 = V_202 ;
V_202 = V_64 ;
if ( V_201 == 1 ) {
V_64 = V_204 ;
V_204 = V_202 ;
V_202 = V_64 ;
} else {
V_64 = V_204 ;
V_204 = V_203 ;
V_203 = V_64 ;
}
}
F_8 ( ( unsigned short ) V_202 , V_3 -> V_205 ) ;
F_8 ( ( unsigned short ) V_203 , V_3 -> V_205 ) ;
F_8 ( ( unsigned short ) V_204 , V_3 -> V_205 ) ;
}
static void F_34 ( unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_133 , V_196 , V_73 , V_206 , V_207 , V_208 , V_209 , V_210 , V_211 , V_212 , V_201 , V_168 , V_167 , V_202 ;
const unsigned short * V_213 = V_214 ;
F_8 ( 0xFF , V_3 -> V_215 ) ;
F_8 ( 0x00 , V_3 -> V_216 ) ;
for ( V_73 = 0 ; V_73 < 16 ; V_73 ++ ) {
V_133 = V_213 [ V_73 ] ;
for ( V_206 = 0 ; V_206 < 3 ; V_206 ++ ) {
V_196 = 0 ;
if ( V_133 & 0x01 )
V_196 = 0x2A ;
if ( V_133 & 0x02 )
V_196 += 0x15 ;
F_8 ( V_196 , V_3 -> V_205 ) ;
V_133 = V_133 >> 2 ;
}
}
for ( V_73 = 16 ; V_73 < 32 ; V_73 ++ ) {
V_133 = V_213 [ V_73 ] ;
for ( V_206 = 0 ; V_206 < 3 ; V_206 ++ )
F_8 ( V_133 , V_3 -> V_205 ) ;
}
V_210 = 32 ;
for ( V_207 = 0 ; V_207 < 9 ; V_207 ++ ) {
V_211 = V_210 ;
V_212 = V_210 + 0x04 ;
V_201 = 0 ;
for ( V_208 = 0 ; V_208 < 3 ; V_208 ++ ) {
for ( V_209 = 0 ; V_209 < 5 ; V_209 ++ ) {
V_202 = V_213 [ V_210 ] ;
V_167 = V_213 [ V_211 ] ;
V_168 = V_213 [ V_212 ] ;
V_210 ++ ;
F_33 ( V_201 , V_167 , V_168 , V_202 , V_3 ) ;
}
V_210 -= 2 ;
for ( V_209 = 0 ; V_209 < 3 ; V_209 ++ ) {
V_202 = V_213 [ V_212 ] ;
V_167 = V_213 [ V_211 ] ;
V_168 = V_213 [ V_210 ] ;
V_210 -- ;
F_33 ( V_201 , V_167 , V_168 , V_202 , V_3 ) ;
}
V_201 ++ ;
}
V_210 += 5 ;
}
}
static void F_35 ( unsigned short V_69 ,
unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_161 , V_199 , V_217 , V_74 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_161 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_199 = V_3 -> V_24 [ V_161 ] . V_163 ;
V_217 = V_3 -> V_24 [ V_161 ] . V_164 ;
if ( V_74 & V_165 )
V_199 = V_199 << 1 ;
if ( V_74 & V_138 )
V_217 = V_217 << 1 ;
if ( V_199 == 720 )
V_199 = 640 ;
V_3 -> V_218 = V_199 ;
V_3 -> V_219 = V_199 ;
V_3 -> V_220 = V_217 ;
V_3 -> V_221 = V_217 ;
}
static void * F_36 ( unsigned short V_222 , unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_73 , V_223 , V_100 , V_224 , V_74 , V_213 ;
struct V_225 * V_226 = NULL ;
V_100 = V_222 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_224 = V_3 -> V_8 [ V_98 ] . V_175 ;
V_224 = V_224 & 0x0f ;
if ( V_100 <= 1 ) {
V_224 = V_3 -> V_8 [ V_98 ] . V_175 ;
if ( V_3 -> V_29 & V_77 ) {
V_224 = V_3 -> V_8 [ V_98 ] .
V_227 ;
}
if ( V_100 & 0x01 )
V_224 = ( V_224 >> 4 ) ;
V_224 = ( V_224 & 0x0f ) ;
}
switch ( V_100 ) {
case 0 :
case 1 :
V_226 = V_228 ;
break;
case 2 :
V_226 = V_229 ;
break;
case 3 :
V_226 = V_230 ;
break;
case 4 :
V_226 = V_231 ;
break;
case 5 :
V_226 = V_232 ;
break;
default:
break;
}
if ( V_226 == NULL )
return NULL ;
V_213 = V_100 ;
V_73 = 0 ;
while ( V_226 [ V_73 ] . V_233 != 0xff ) {
V_223 = V_3 -> V_26 ;
if ( V_100 & 0x0080 ) {
V_100 &= ( ~ 0x0080 ) ;
V_223 = V_3 -> V_27 ;
}
if ( V_3 -> V_28 & V_234 )
V_223 &= ( ~ V_235 ) ;
if ( V_226 [ V_73 ] . V_233 == V_223 ) {
V_100 = V_226 [ V_73 ] . V_236 ;
V_223 = V_3 -> V_28 ;
if ( V_74 & V_165 )
V_223 |= V_237 ;
V_100 &= V_223 ;
if ( V_100 == V_226 [ V_73 ] . V_238 )
break;
}
V_73 ++ ;
}
if ( V_213 == 0 ) {
switch ( V_226 [ V_73 ] . V_239 ) {
case 0 :
return & V_240 [ V_224 ] ;
break;
case 1 :
return & V_241 [ V_224 ] ;
break;
case 2 :
return & V_242 [ V_224 ] ;
break;
case 3 :
return & V_243 [ V_224 ] ;
break;
case 4 :
return & V_244 [ V_224 ] ;
break;
case 5 :
return & V_245 [ V_224 ] ;
break;
case 6 :
return & V_246 [ V_224 ] ;
break;
case 7 :
return & V_247 [ V_224 ] ;
break;
case 8 :
return & V_248 [ V_224 ] ;
break;
case 9 :
return & V_249 [ V_224 ] ;
break;
case 10 :
return & V_250 [ V_224 ] ;
break;
default:
break;
}
} else if ( V_213 == 1 ) {
switch ( V_226 [ V_73 ] . V_239 ) {
case 0 :
return & V_251 [ V_224 ] ;
break;
case 1 :
return & V_252 [ V_224 ] ;
break;
case 2 :
return & V_253 [ V_224 ] ;
break;
case 3 :
return & V_254 [ V_224 ] ;
break;
case 4 :
return & V_255 [ V_224 ] ;
break;
case 5 :
return & V_256 [ V_224 ] ;
break;
case 6 :
return & V_257 [ V_224 ] ;
break;
case 7 :
return & V_258 [ V_224 ] ;
break;
case 8 :
return & V_259 [ V_224 ] ;
break;
case 9 :
return & V_260 [ V_224 ] ;
break;
case 10 :
return & V_261 [ V_224 ] ;
break;
default:
break;
}
} else if ( V_213 == 2 ) {
switch ( V_226 [ V_73 ] . V_239 ) {
case 0 :
return & V_262 [ V_224 ] ;
break;
case 1 :
return & V_263 [ V_224 ] ;
break;
case 2 :
return & V_264 [ V_224 ] ;
break;
case 3 :
return & V_265 [ V_224 ] ;
break;
case 4 :
return & V_266 [ V_224 ] ;
break;
case 5 :
return & V_267 [ V_224 ] ;
break;
case 6 :
return & V_268 [ V_224 ] ;
break;
case 7 :
return & V_269 [ V_224 ] ;
break;
case 8 :
return & V_270 [ V_224 ] ;
break;
case 9 :
return & V_271 [ V_224 ] ;
break;
case 10 :
return & V_272 [ V_224 ] ;
break;
case 11 :
return & V_273 [ V_224 ] ;
break;
case 12 :
return & V_274 [ V_224 ] ;
break;
default:
break;
}
} else if ( V_213 == 3 ) {
switch ( V_226 [ V_73 ] . V_239 ) {
case 0 :
return & V_275 [ V_224 ] ;
break;
case 1 :
return & V_276 [ V_224 ] ;
break;
case 2 :
return & V_277 [ V_224 ] ;
break;
case 3 :
return & V_278 [ V_224 ] ;
break;
case 4 :
return & V_279 [ V_224 ] ;
break;
case 5 :
return & V_280 [ V_224 ] ;
break;
case 6 :
return & V_281 [ V_224 ] ;
break;
case 7 :
return & V_282 [ V_224 ] ;
break;
case 8 :
return & V_283 [ V_224 ] ;
break;
case 9 :
return & V_284 [ V_224 ] ;
break;
case 10 :
return & V_285 [ V_224 ] ;
break;
case 11 :
return & V_286 [ V_224 ] ;
break;
case 12 :
return & V_287 [ V_224 ] ;
break;
case 13 :
return & V_288 [ V_224 ] ;
break;
case 14 :
return & V_289 [ V_224 ] ;
break;
default:
break;
}
} else if ( V_213 == 4 ) {
switch ( V_226 [ V_73 ] . V_239 ) {
case 0 :
return & V_290 [ V_224 ] ;
break;
case 1 :
return & V_291 [ V_224 ] ;
break;
case 2 :
return & V_292 [ V_224 ] ;
break;
case 3 :
return & V_293 [ V_224 ] ;
break;
case 4 :
return & V_294 [ V_224 ] ;
break;
case 5 :
return & V_295 [ V_224 ] ;
break;
case 6 :
case 7 :
return & V_296 [ V_224 ] ;
break;
case 8 :
return & V_297 [ V_224 ] ;
break;
case 9 :
return & V_298 [ V_224 ] ;
break;
case 10 :
return & V_299 [ V_224 ] ;
break;
case 11 :
return & V_300 [ V_224 ] ;
break;
case 12 :
return & V_301 [ V_224 ] ;
break;
case 13 :
return & V_301 [ V_224 ] ;
break;
case 14 :
return & V_302 [ V_224 ] ;
break;
case 15 :
case 16 :
return & V_303 [ V_224 ] ;
break;
case 17 :
return & V_304 [ V_224 ] ;
break;
case 18 :
return & V_305 [ V_224 ] ;
break;
default:
break;
}
} else if ( V_213 == 5 ) {
switch ( V_226 [ V_73 ] . V_239 ) {
case 0 :
return & V_306 [ V_224 ] ;
break;
case 1 :
return & V_307 [ V_224 ] ;
break;
case 2 :
return & V_308 [ V_224 ] ;
break;
case 3 :
if ( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) )
return & V_309 [ V_224 ] ;
else
return & V_310 [ V_224 ] ;
break;
case 4 :
if ( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) )
return & V_311 [ V_224 ] ;
else
return & V_312 [ V_224 ] ;
break;
case 5 :
if ( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) )
return & V_313 [ V_224 ] ;
else
return & V_314 [ V_224 ] ;
break;
case 6 :
case 7 :
if ( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) )
return & V_315 [ V_224 ] ;
else
return & V_316 [ V_224 ] ;
break;
case 8 :
return & V_317 [ V_224 ] ;
break;
case 9 :
return & V_318 [ V_224 ] ;
break;
case 10 :
if ( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) )
return & V_319 [ V_224 ] ;
else
return & V_320 [ V_224 ] ;
break;
case 11 :
if ( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) )
return & V_321 [ V_224 ] ;
else
return & V_322 [ V_224 ] ;
break;
case 12 :
return & V_323 [ V_224 ] ;
break;
case 13 :
case 14 :
return & V_324 [ V_224 ] ;
break;
case 15 :
return & V_325 [ V_224 ] ;
break;
case 16 :
case 17 :
if ( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) )
return & V_326 [ V_224 ] ;
else
return & V_327 [ V_224 ] ;
break;
case 18 :
if ( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) )
return & V_328 [ V_224 ] ;
else
return & V_329 [ V_224 ] ;
break;
case 19 :
return & V_330 [ V_224 ] ;
break;
default:
break;
}
}
return NULL ;
}
static struct V_331 const * F_37 ( unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_73 , V_223 , V_224 , V_74 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_224 = V_3 -> V_8 [ V_98 ] . V_175 ;
V_224 = V_224 & 0x3f ;
V_223 = V_3 -> V_30 ;
if ( V_3 -> V_29 & V_80 )
V_223 = V_223 | V_332 ;
if ( V_74 & V_165 )
V_223 = V_223 | V_333 ;
V_73 = 0 ;
while ( V_334 [ V_73 ] . V_236 != 0xffff ) {
if ( ( V_223 & V_334 [ V_73 ] . V_236 ) ==
V_334 [ V_73 ] . V_238 )
break;
V_73 ++ ;
}
return & V_334 [ V_73 ] . V_239 [ V_224 ] ;
}
static void F_38 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_100 ;
struct V_335 * V_336 = NULL ;
V_100 = 2 ;
if ( V_3 -> V_29 & ( V_79 | V_77 ) ) {
V_336 = F_36 ( V_100 , V_69 , V_70 ,
V_98 , V_3 ) ;
V_3 -> V_337 = V_336 -> V_337 ;
V_3 -> V_338 = V_336 -> V_338 ;
V_3 -> V_339 = V_336 -> V_340 ;
V_3 -> V_341 = V_336 -> V_342 ;
}
if ( V_3 -> V_29 & ( V_79 | V_77 ) ) {
if ( ! ( V_3 -> V_28 & ( V_343
| V_234 ) ) ) {
if ( ( V_3 -> V_26 == V_129 ) ||
( V_3 -> V_26 == V_344 ) ) {
V_3 -> V_219 = 1024 ;
V_3 -> V_221 = 768 ;
} else if ( ( V_3 -> V_26 == V_111 ) ||
( V_3 -> V_26 ==
V_345 ) ) {
V_3 -> V_219 = 1280 ;
V_3 -> V_221 = 1024 ;
} else if ( V_3 -> V_26 == V_346 ) {
V_3 -> V_219 = 1400 ;
V_3 -> V_221 = 1050 ;
} else {
V_3 -> V_219 = 1600 ;
V_3 -> V_221 = 1200 ;
}
}
}
}
static void F_39 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned char V_139 ;
unsigned short V_100 , V_73 ;
struct V_347 * V_336 = NULL ;
struct V_348 * V_349 = NULL ;
V_139 = V_3 -> V_8 [ V_98 ] . V_175 ;
V_139 = V_139 & V_141 ;
V_100 = 0 ;
if ( V_3 -> V_29 & ( V_79 | V_77 ) ) {
V_336 = F_36 ( V_100 , V_69 , V_70 ,
V_98 , V_3 ) ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ )
V_3 -> V_49 [ 0 ] . V_133 [ V_73 ] = V_336 [ 0 ] . V_350 [ V_73 ] ;
}
F_16 ( V_3 , V_82 ) ;
V_100 = 1 ;
if ( V_3 -> V_29 & ( V_79 | V_77 ) ) {
V_349 = F_36 ( V_100 , V_69 , V_70 ,
V_98 , V_3 ) ;
for ( V_73 = 0 ; V_73 < 7 ; V_73 ++ )
V_3 -> V_51 [ 0 ] . V_133 [ V_73 ] = V_349 [ 0 ] . V_350 [ V_73 ] ;
}
F_17 ( V_70 , V_69 , V_3 ) ;
}
static unsigned short F_40 ( struct V_2 * V_3 )
{
unsigned char V_224 , V_71 , V_351 , V_73 ;
V_71 = F_2 ( V_3 -> V_84 , 0x36 ) ;
V_224 = V_71 & 0x0F ;
V_71 = V_71 & 0xF0 ;
V_73 = 0 ;
V_351 = V_3 -> V_58 [ V_73 ] . V_352 ;
while ( V_351 != 0xFF ) {
if ( V_351 & 0x80 ) {
V_224 = V_71 ;
V_351 = V_351 & ~ ( 0x80 ) ;
}
if ( V_224 == V_351 )
break;
V_73 ++ ;
V_351 = V_3 -> V_58 [ V_73 ] . V_352 ;
}
return V_73 ;
}
static unsigned short F_41 ( struct V_2 * V_3 )
{
unsigned short V_71 , V_224 , V_351 , V_73 ;
V_224 = V_3 -> V_26 ;
V_71 = V_3 -> V_27 ;
V_73 = 0 ;
V_351 = V_3 -> V_58 [ V_73 ] . V_352 ;
while ( V_351 != 0xFF ) {
if ( ( V_351 & 0x80 ) && ( V_351 != 0x80 ) ) {
V_224 = V_71 ;
V_351 &= ~ 0x80 ;
}
if ( V_224 == V_351 )
break;
V_73 ++ ;
V_351 = V_3 -> V_58 [ V_73 ] . V_352 ;
}
if ( V_351 == 0xFF ) {
V_3 -> V_26 = V_129 ;
V_3 -> V_27 = 0 ;
V_73 = 0 ;
}
return V_73 ;
}
static void F_42 ( unsigned short * V_353 ,
unsigned short * V_354 ,
struct V_2 * V_3 )
{
unsigned short V_355 ;
V_355 = F_40 ( V_3 ) ;
* V_353 = V_3 -> V_58 [ V_355 ] . V_356 ;
* V_354 = V_3 -> V_58 [ V_355 ] . V_357 ;
return;
}
static void F_43 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_100 , V_99 , V_162 , V_223 , V_358 , V_359 , V_74 ;
unsigned long V_64 , V_360 , V_169 , V_361 , V_362 ;
struct V_363 * V_336 = NULL ;
struct V_364 * V_349 = NULL ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_100 = 3 ;
if ( V_3 -> V_28 & V_234 )
V_349 = F_36 ( V_100 , V_69 , V_70 ,
V_98 , V_3 ) ;
else
V_336 = F_36 ( V_100 , V_69 , V_70 ,
V_98 , V_3 ) ;
F_42 ( & V_99 , & V_100 , V_3 ) ;
V_358 = V_100 ;
V_359 = V_99 ;
if ( ( V_3 -> V_26 == V_129 ) ||
( V_3 -> V_26 == V_344 ) ) {
V_99 = 1024 ;
V_100 = 768 ;
} else if ( ( V_3 -> V_26 == V_111 ) ||
( V_3 -> V_26 == V_345 ) ) {
V_99 = 1280 ;
V_100 = 1024 ;
} else if ( V_3 -> V_26 == V_346 ) {
V_99 = 1400 ;
V_100 = 1050 ;
} else {
V_99 = 1600 ;
V_100 = 1200 ;
}
if ( V_3 -> V_28 & V_343 ) {
V_3 -> V_219 = V_99 ;
V_3 -> V_221 = V_100 ;
V_3 -> V_218 = V_99 ;
V_3 -> V_220 = V_100 ;
}
V_99 = V_3 -> V_339 ;
if ( V_3 -> V_28 & V_234 )
V_100 = V_349 -> V_365 ;
else
V_100 = V_336 -> V_365 ;
V_162 = V_3 -> V_219 ;
V_100 = V_100 & 0x0fff ;
V_162 += V_100 ;
if ( V_162 >= V_99 )
V_162 -= V_99 ;
F_4 ( V_3 -> V_366 , 0x1A , V_100 & 0x07 ) ;
V_162 = V_162 >> 3 ;
V_100 = V_100 >> 3 ;
F_4 ( V_3 -> V_366 , 0x16 ,
( unsigned short ) ( V_100 & 0xff ) ) ;
F_4 ( V_3 -> V_366 , 0x17 ,
( unsigned short ) ( V_162 & 0xff ) ) ;
V_99 = V_3 -> V_339 ;
if ( V_3 -> V_28 & V_234 )
V_100 = V_349 -> V_367 ;
else
V_100 = V_336 -> V_367 ;
V_162 = V_359 ;
if ( V_3 -> V_28 & V_234 )
V_162 = V_349 -> V_368 ;
V_162 += V_100 ;
if ( V_162 >= V_99 )
V_162 -= V_99 ;
V_99 = V_100 & 0x07 ;
V_99 = V_99 >> 5 ;
V_162 = V_162 >> 3 ;
V_100 = V_100 >> 3 ;
V_162 &= 0x1f ;
V_99 |= V_162 ;
F_4 ( V_3 -> V_366 , 0x15 , V_99 ) ;
F_4 ( V_3 -> V_366 , 0x14 ,
( unsigned short ) ( V_100 & 0xff ) ) ;
V_99 = V_3 -> V_341 ;
if ( V_3 -> V_28 & V_234 )
V_100 = V_349 -> V_369 ;
else
V_100 = V_336 -> V_369 ;
V_162 = V_3 -> V_221 ;
V_100 = V_100 & 0x0fff ;
V_162 += V_100 ;
if ( V_162 >= V_99 )
V_162 -= V_99 ;
F_4 ( V_3 -> V_366 , 0x1b ,
( unsigned short ) ( V_100 & 0xff ) ) ;
F_4 ( V_3 -> V_366 , 0x1c ,
( unsigned short ) ( V_162 & 0xff ) ) ;
V_100 = ( V_100 >> 8 ) & 0x07 ;
V_162 = ( V_162 >> 8 ) & 0x07 ;
F_4 ( V_3 -> V_366 , 0x1d ,
( unsigned short ) ( ( V_162 << 3 )
| V_100 ) ) ;
V_99 = V_3 -> V_341 ;
if ( V_3 -> V_28 & V_234 )
V_100 = V_349 -> V_370 ;
else
V_100 = V_336 -> V_370 ;
V_162 = V_358 ;
if ( V_3 -> V_28 & V_234 )
V_162 = V_349 -> V_371 ;
V_162 += V_100 ;
if ( V_162 >= V_99 )
V_162 -= V_99 ;
F_4 ( V_3 -> V_366 , 0x18 ,
( unsigned short ) ( V_100 & 0xff ) ) ;
F_12 ( V_3 -> V_366 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_162 & 0x0f ) ) ;
V_99 = ( ( V_100 >> 8 ) & 0x07 ) << 3 ;
V_100 = V_3 -> V_220 ;
if ( V_100 != V_3 -> V_221 )
V_99 |= 0x40 ;
if ( V_3 -> V_28 & V_372 )
V_99 |= 0x40 ;
F_12 ( V_3 -> V_366 , 0x1a , 0x07 ,
V_99 ) ;
V_162 = V_3 -> V_338 ;
V_100 = V_3 -> V_221 ;
V_99 = V_3 -> V_220 ;
V_162 -= V_99 ;
V_64 = V_99 ;
V_360 = ( V_64 << 18 ) / V_100 ;
V_223 = ( unsigned short ) ( ( V_64 << 18 ) % V_100 ) ;
if ( V_223 != 0 )
V_360 += 1 ;
V_169 = V_360 ;
V_362 = V_169 ;
F_4 ( V_3 -> V_366 , 0x37 ,
( unsigned short ) ( V_169 & 0xff ) ) ;
F_4 ( V_3 -> V_366 , 0x36 ,
( unsigned short ) ( ( V_169 >> 8 ) & 0xff ) ) ;
V_100 = ( unsigned short ) ( V_169 >> 16 ) ;
V_99 = V_100 & 0x03 ;
V_100 = V_3 -> V_220 ;
if ( V_100 == V_3 -> V_221 )
V_99 |= 0x04 ;
F_4 ( V_3 -> V_366 , 0x35 , V_99 ) ;
if ( V_3 -> V_55 & V_108 ) {
V_169 = V_362 ;
F_4 ( V_3 -> V_373 ,
0x3c ,
( unsigned short ) ( V_169 & 0xff ) ) ;
F_4 ( V_3 -> V_373 ,
0x3b ,
( unsigned short ) ( ( V_169 >> 8 ) &
0xff ) ) ;
V_100 = ( unsigned short ) ( V_169 >> 16 ) ;
F_12 ( V_3 -> V_373 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_100 &
0xff ) << 6 ) ) ;
V_162 = V_3 -> V_220 ;
if ( V_162 == V_3 -> V_221 )
F_12 ( V_3 -> V_373 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_12 ( V_3 -> V_373 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_162 = V_3 -> V_218 ;
V_100 = V_3 -> V_219 ;
V_360 = V_162 << 16 ;
V_99 = ( unsigned short ) ( V_360 / V_100 ) ;
if ( ( V_100 & 0xffff ) == ( V_162 & 0xffff ) )
V_99 = 65535 ;
V_361 = V_99 ;
V_360 = V_3 -> V_218 << 16 ;
V_360 /= V_361 ;
V_361 = V_361 << 16 ;
V_360 -= 1 ;
V_361 = ( V_361 & 0xffff0000 ) + ( V_360 & 0xffff ) ;
V_99 = ( unsigned short ) ( V_361 & 0xff ) ;
F_4 ( V_3 -> V_366 , 0x1f , V_99 ) ;
V_360 = V_3 -> V_220 << 18 ;
V_360 = V_360 / V_362 ;
V_100 = ( unsigned short ) ( V_360 & 0xffff ) ;
if ( V_3 -> V_26 == V_129 )
V_100 -= 1 ;
V_99 = ( ( V_100 >> 8 ) & 0xff ) << 3 ;
V_99 |= ( unsigned short ) ( ( V_361 >> 8 ) & 0x07 ) ;
F_4 ( V_3 -> V_366 , 0x20 ,
( unsigned short ) ( V_99 & 0xff ) ) ;
F_4 ( V_3 -> V_366 , 0x21 ,
( unsigned short ) ( V_100 & 0xff ) ) ;
V_361 = V_361 >> 16 ;
if ( V_74 & V_165 )
V_361 = V_361 >> 1 ;
F_4 ( V_3 -> V_366 , 0x22 ,
( unsigned short ) ( ( V_361 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 -> V_366 , 0x23 ,
( unsigned short ) ( V_361 & 0xff ) ) ;
}
static void F_44 ( unsigned char * V_374 , unsigned char * V_375 ,
struct V_2 * V_3 )
{
unsigned short V_139 ;
if ( V_3 -> V_29 & ( V_79 | V_77 ) ) {
V_139 = F_41 ( V_3 ) ;
if ( V_3 -> V_29 & V_79 ) {
* V_374 = V_3 -> V_58 [ V_139 ] . V_376 ;
* V_375 = V_3 -> V_58 [ V_139 ] . V_377 ;
} else {
* V_374 = V_3 -> V_58 [ V_139 ] . V_378 ;
* V_375 = V_3 -> V_58 [ V_139 ] . V_379 ;
}
}
return;
}
static unsigned char F_45 ( unsigned short V_98 ,
unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_139 , V_74 ;
unsigned char V_224 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
if ( ( V_3 -> V_116 & V_380 ) &&
( ! ( V_3 -> V_28 & V_234 ) ) ) {
V_139 = F_40 ( V_3 ) ;
V_224 = V_3 -> V_58 [ V_139 ] . V_381 ;
if ( V_3 -> V_29 & ( V_79 | V_77 ) )
return V_224 ;
if ( V_3 -> V_55 &
( V_123 |
V_124 |
V_56 |
V_57 |
V_108 ) ) {
if ( V_3 -> V_29 & V_114 ) {
V_224 = V_382 + V_180 ;
if ( ! ( V_3 -> V_30 & V_178 ) )
V_224 = V_382 + V_181 ;
if ( V_3 -> V_30 & V_117 ) {
V_224 = V_382 + V_182 ;
if ( ! ( V_74 & V_88 ) )
V_224 = V_382 +
V_183 ;
}
return V_224 ;
}
if ( V_3 -> V_30 & V_383 ) {
V_224 = V_384 ;
return V_224 ;
}
if ( V_3 -> V_30 & V_385 ) {
V_224 = V_386 ;
return V_224 ;
}
V_224 = V_387 ;
if ( ! ( V_3 -> V_30 & V_388 ) ) {
V_224 = V_382 + V_186 ;
if ( ! ( V_3 -> V_30 & V_178 ) )
V_224 = V_382 + V_187 ;
}
if ( V_3 -> V_29 & V_78 )
return V_224 ;
}
}
V_224 = ( unsigned char ) F_7 ( ( V_3 -> V_389 + 0x02 ) ) ;
V_224 = V_224 >> 2 ;
V_224 &= 0x03 ;
if ( ( V_3 -> V_28 & V_234 ) && ( V_74 & V_88 ) )
V_224 = V_224 ^ V_224 ;
V_224 = V_3 -> V_8 [ V_98 ] . V_188 ;
return V_224 ;
}
static void F_46 ( unsigned char V_224 , unsigned char * V_374 ,
unsigned char * V_375 , struct V_2 * V_3 )
{
if ( V_3 -> V_55 & ( V_390 | V_123 | V_124
| V_56 | V_57 | V_108 ) ) {
if ( ( ! ( V_3 -> V_29 & V_77 ) ) &&
( V_3 -> V_116 & V_380 ) ) {
* V_374 = V_19 [ V_224 ] . V_193 ;
* V_375 = V_19 [ V_224 ] . V_194 ;
}
} else {
* V_374 = V_17 [ V_224 ] . V_96 ;
* V_375 = V_17 [ V_224 ] . V_97 ;
}
}
static void F_47 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned char V_374 , V_375 , V_224 ;
int V_73 ;
V_224 = F_45 ( V_98 , V_69 , V_70 ,
V_3 ) ;
F_46 ( V_224 , & V_374 , & V_375 , V_3 ) ;
F_44 ( & V_374 , & V_375 , V_3 ) ;
for ( V_73 = 0 ; V_73 < 4 ; V_73 ++ ) {
F_12 ( V_3 -> V_84 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_73 ) ) ;
if ( ( ! ( V_3 -> V_29 & V_77 ) )
&& ( ! ( V_3 -> V_29 & V_80 ) ) ) {
F_4 ( V_3 -> V_68 , 0x2e , V_374 ) ;
F_4 ( V_3 -> V_68 , 0x2f , V_375 ) ;
} else {
F_4 ( V_3 -> V_68 , 0x2b , V_374 ) ;
F_4 ( V_3 -> V_68 , 0x2c , V_375 ) ;
}
}
}
static void F_48 ( struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_391 , V_392 , V_64 , V_351 , V_99 ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
V_391 = 0 ;
V_392 = 0 ;
V_64 = F_2 ( V_3 -> V_68 , 0x01 ) ;
if ( ! ( V_64 & 0x20 ) ) {
V_64 = F_2 ( V_3 -> V_84 , 0x17 ) ;
if ( V_64 & 0x80 ) {
V_64 = F_2 ( V_3 -> V_84 , 0x53 ) ;
if ( ! ( V_64 & 0x40 ) )
V_391 |= V_393 ;
}
}
V_64 = F_2 ( V_3 -> V_366 , 0x2e ) ;
V_64 &= 0x0f ;
if ( ! ( V_64 == 0x08 ) ) {
V_99 = F_2 ( V_3 -> V_366 , 0x13 ) ;
if ( V_99 & 0x04 )
V_391 = V_391 | V_394 ;
V_64 &= 0x05 ;
if ( ! ( V_391 & V_394 ) )
if ( V_64 == 0x01 )
V_391 |= V_395 ;
if ( V_64 == 0x04 )
V_391 |= V_394 ;
if ( V_64 == 0x05 ) {
V_64 = F_2 ( V_3 -> V_396 , 0x00 ) ;
if ( ! ( V_64 & 0x08 ) )
V_392 |= V_397 ;
if ( ! ( V_64 & 0x04 ) )
V_392 |= V_398 ;
if ( V_64 & 0x02 )
V_392 |= V_399 ;
if ( V_3 -> V_29 & V_114 ) {
if ( V_64 & 0x01 )
V_392 |= V_400 ;
}
if ( V_3 -> V_29 & V_121 ) {
V_64 = F_2 (
V_3 -> V_396 ,
0x4d ) ;
if ( V_64 & 0x10 )
V_392 |= V_401 ;
}
if ( V_392 != 0 )
V_391 |= V_402 ;
}
}
V_64 = F_2 ( V_3 -> V_84 , 0x3d ) ;
if ( V_391 & V_394 ) {
if ( ( V_3 -> V_116 & V_403 ) ) {
if ( V_64 & V_402 )
V_391 |= V_402 ;
}
}
V_64 = V_391 ;
V_351 = ~ V_404 ;
F_12 ( V_3 -> V_84 , 0x3d , V_351 , V_64 ) ;
if ( ! ( V_3 -> V_116 & V_403 ) )
F_4 ( V_3 -> V_84 , 0x3e , V_392 ) ;
} else {
return;
}
}
void F_49 ( struct V_2 * V_3 )
{
unsigned short V_405 , V_100 , V_71 ;
if ( V_3 -> V_105 != 0 )
return;
V_100 = V_124 ;
V_405 = F_2 ( V_3 -> V_373 , 0x00 ) ;
if ( V_405 == 0x02 )
goto V_406;
V_100 = V_390 ;
V_405 = F_2 ( V_3 -> V_373 , 0x01 ) ;
if ( V_405 < 0xB0 )
goto V_406;
V_100 = V_123 ;
if ( V_405 < 0xC0 )
goto V_407;
V_100 = V_108 ;
if ( V_405 < 0xD0 )
goto V_407;
V_100 = V_56 ;
if ( V_405 < 0xE0 )
goto V_407;
V_100 = V_57 ;
V_71 = F_2 ( V_3 -> V_373 , 0x39 ) ;
if ( V_71 != 0xFF )
V_100 = V_108 ;
V_407:
if ( V_100 & ( V_123 | V_124 ) ) {
V_405 = F_2 ( V_3 -> V_373 , 0x23 ) ;
if ( ! ( V_405 & 0x02 ) )
V_100 = V_100 | V_408 ;
}
V_406:
V_3 -> V_55 = V_100 ;
}
static void F_50 ( unsigned short V_69 , unsigned short V_70 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_99 , V_409 , V_100 , V_64 , V_74 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_3 -> V_116 = 0 ;
V_3 -> V_94 = V_74 & V_410 ;
V_100 = 0 ;
if ( ! ( V_3 -> V_55 & 0xFFFF ) )
return;
V_64 = F_2 ( V_3 -> V_84 , 0x30 ) ;
V_100 = V_100 | V_64 ;
V_64 = F_2 ( V_3 -> V_84 , 0x31 ) ;
V_409 = V_64 ;
V_409 = V_409 << 8 ;
V_99 = V_64 << 8 ;
V_100 = V_100 | V_99 ;
V_64 = ( V_411 | V_121 | V_77
| V_80 | V_412 ) ;
V_64 = 0xFFFF ^ V_64 ;
V_100 &= V_64 ;
V_64 = F_2 ( V_3 -> V_84 , 0x38 ) ;
if ( V_3 -> V_105 == 0 ) {
if ( V_3 -> V_55 &
( V_124 |
V_56 |
V_57 |
V_108 ) ) {
if ( V_64 & V_413 ) {
V_100 |= V_411 ;
if ( V_64 & V_414 )
V_100 |= V_77 ;
}
}
}
if ( V_3 -> V_415 == 1 ) {
if ( ( ( V_3 -> V_105 == 0 ) &&
( ( V_3 -> V_55 & V_56 ) ||
( V_3 -> V_55 & V_57 ) ||
( V_3 -> V_55 & V_108 ) ) ) ) {
if ( V_64 & V_416 ) {
if ( V_3 -> V_417 == 1 ) {
V_64 = F_2 (
V_3 -> V_84 ,
0x35 ) ;
V_64 &= V_418 ;
V_100 |= V_114 ;
if ( V_64 != V_419 ) {
V_100 &=
( ~ V_114 ) ;
V_100 |=
V_121 ;
}
}
}
}
}
V_99 = V_409 ;
if ( V_3 -> V_105 == 0 ) {
if ( V_3 -> V_415 == 1 ) {
if ( V_3 -> V_417 == 1 )
V_64 = 0x09FC ;
else
V_64 = 0x097C ;
} else if ( V_3 -> V_417 == 1 ) {
V_64 = 0x01FC ;
} else {
V_64 = 0x017C ;
}
} else {
V_64 = V_79 ;
}
if ( ! ( V_100 & V_64 ) ) {
V_99 |= V_412 ;
V_100 = 0 ;
}
if ( ! ( V_3 -> V_55 & V_408 ) ) {
if ( V_100 & V_77 ) {
if ( V_100 & V_420 )
V_100 &= ( ~ ( V_79 |
V_106 |
V_421 ) ) ;
else
V_100 &= ( ~ ( V_79 |
V_106 |
V_78 |
V_421 ) ) ;
}
}
if ( ! ( V_100 & ( V_421 | V_420 ) ) ) {
if ( V_3 -> V_422 == 1 ) {
if ( V_100 & V_106 ) {
V_100 &= ( 0xFF00 |
V_106 |
V_421 |
V_420 ) ;
V_100 &= ( 0x00FF | ( ~ V_121 ) ) ;
}
} else {
V_100 &= ( ~ ( V_106 |
V_79 |
V_78 ) ) ;
}
}
if ( ! ( V_3 -> V_55 & V_408 ) ) {
if ( V_100 & V_79 ) {
V_100 &= ( 0xFF00 |
V_79 |
V_421 |
V_420 ) ;
V_100 &= ( 0x00FF | ( ~ V_121 ) ) ;
}
}
if ( V_100 & V_120 ) {
V_100 &= ( 0xFF00 |
V_120 |
V_421 |
V_420 ) ;
V_100 &= ( 0x00FF | ( ~ V_121 ) ) ;
}
if ( V_3 -> V_415 == 1 ) {
if ( V_100 & V_121 )
V_100 &= ( 0xFF00 |
V_421 |
V_420 ) ;
}
if ( V_3 -> V_417 == 1 ) {
if ( V_100 & V_114 )
V_100 &= ( 0xFF00 |
V_114 |
V_421 |
V_420 ) ;
}
if ( V_99 & V_412 ) {
if ( ! ( V_100 & ( V_421 | V_420 ) ) )
V_100 = V_412 ;
}
if ( ! ( V_100 & V_412 ) ) {
if ( ( ! ( V_100 & V_423 ) ) ||
( ! ( V_74 & V_424 ) ) ) {
if ( ! ( V_100 & V_77 ) )
V_100 |= ( V_80 |
V_420 ) ;
}
if ( ( V_100 & V_80 ) &&
( V_100 & V_77 ) ) {
V_100 ^= ( V_79 |
V_77 |
V_411 ) ;
V_3 -> V_116 |= V_403 ;
}
}
V_3 -> V_29 = V_100 ;
}
static void F_51 ( unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_64 , V_100 = 0 , V_101 = 0 , V_74 , V_425 ;
V_100 = 0 ;
V_101 = 0 ;
if ( V_3 -> V_29 & V_78 ) {
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
if ( V_3 -> V_29 & V_78 ) {
V_64 = F_2 ( V_3 -> V_84 , 0x35 ) ;
V_100 = V_64 ;
if ( V_100 & V_126 ) {
V_100 &= ( V_426 |
V_427 |
V_428 |
V_126 ) ;
if ( V_100 & V_427 )
V_100 &= ~ V_126 ;
} else
V_100 &= ( V_426 |
V_429 |
V_126 ) ;
}
if ( V_3 -> V_105 == 0 ) {
if ( V_3 -> V_29 & V_120 )
V_100 |= V_126 ;
}
if ( V_3 -> V_415 == 1 ) {
if ( V_3 -> V_29 & V_121 ) {
V_425 = F_2 ( V_3 -> V_84 , 0x35 ) ;
V_425 &= V_418 ;
if ( V_425 == V_430 )
V_100 |= V_431 ;
if ( V_425 == V_432 )
V_100 = V_100 | V_385 ;
if ( V_425 == V_433 )
V_100 = V_100 | V_383 ;
}
}
if ( V_3 -> V_417 == 1 ) {
if ( V_3 -> V_29 & V_114 )
V_100 = V_100 | V_434 | V_126 ;
}
if ( V_3 -> V_105 == 0 ) {
if ( ( V_3 -> V_29 & V_80 ) &&
( ! ( V_3 -> V_29 & V_128 ) ) )
V_100 |= V_117 ;
if ( ! ( V_100 & V_126 ) &&
( V_74 > 13 ) &&
( V_101 == 8 ) )
V_100 |= V_388 ;
V_100 |= V_178 ;
if ( V_3 -> V_29 & V_114 ) {
if ( V_3 -> V_29 & V_80 )
V_100 &= ( ~ V_178 ) ;
} else if ( V_100 &
( V_385 | V_383 ) ) {
V_100 &= ( ~ V_178 ) ;
} else if ( ! ( V_3 -> V_55 &
( V_123 |
V_124 |
V_56 |
V_57 |
V_108 ) ) ) {
if ( V_100 & V_117 )
V_100 &= ( ~ V_178 ) ;
}
}
}
V_3 -> V_30 = V_100 ;
}
static unsigned char F_52 ( unsigned short V_69 ,
unsigned short V_70 , struct V_2 * V_3 )
{
unsigned short V_64 , V_99 , V_100 , V_74 , V_101 = 0 , V_435 ;
V_3 -> V_26 = 0 ;
V_3 -> V_27 = 0 ;
V_3 -> V_28 = 0 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_64 = F_2 ( V_3 -> V_84 , 0x36 ) ;
V_100 = V_64 & 0x0F ;
if ( V_100 == 0 )
V_100 = V_129 ;
if ( ( V_100 == V_129 ) || ( V_100 == V_111 ) ) {
if ( V_3 -> V_29 & V_423 ) {
V_99 = F_2 ( V_3 -> V_84 , 0x33 ) ;
if ( V_3 -> V_29 & V_77 )
V_99 &= 0x0F ;
else
V_99 = V_99 >> 4 ;
if ( ( V_101 == 6 ) || ( V_101 == 9 ) ) {
if ( V_99 >= 3 )
V_100 |= V_436 ;
} else if ( ( V_101 == 7 ) || ( V_101 == 8 ) ) {
if ( V_99 >= 4 )
V_100 |= V_436 ;
}
}
}
V_3 -> V_26 = V_100 ;
if ( ! ( V_3 -> V_29 & ( V_79 | V_77 ) ) )
return 0 ;
V_100 = 0 ;
V_64 = F_2 ( V_3 -> V_84 , 0x37 ) ;
V_64 &= ( V_437 | V_113 | V_438 | V_439 ) ;
V_100 |= V_64 ;
V_435 = F_41 ( V_3 ) ;
V_99 = V_3 -> V_58 [ V_435 ] . V_440 ;
if ( V_3 -> V_105 == 0 ) {
if ( ( ( V_3 -> V_55 & V_57 ) || ( V_3 -> V_55
& V_108 ) ) && ( V_99 & V_441 ) ) {
V_100 |= V_442 ;
}
}
if ( V_3 -> V_105 == 0 ) {
if ( ( V_3 -> V_26 == V_346 ) && ( V_3 -> V_29
& V_79 ) && ( V_101 == 9 ) &&
( ! ( V_100 & V_234 ) ) )
V_100 |= V_343 ;
}
if ( V_3 -> V_29 & V_80 ) {
if ( V_3 -> V_29 & V_128 )
V_100 |= V_443 ;
} else {
V_100 |= V_443 ;
}
V_3 -> V_28 = V_100 ;
return 1 ;
}
unsigned char F_53 ( unsigned short V_69 ,
unsigned short * V_70 , struct V_2 * V_3 )
{
for ( * V_70 = 0 ; ; ( * V_70 ) ++ ) {
if ( V_3 -> V_6 [ * V_70 ] . V_444 == V_69 )
break;
if ( V_3 -> V_6 [ * V_70 ] . V_444 == 0xFF )
return 0 ;
}
return 1 ;
}
static unsigned char F_54 ( unsigned char V_445 )
{
unsigned char V_446 = 0 ;
unsigned char V_73 = 0 ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ ) {
V_446 = V_446 << 1 ;
V_446 |= ( V_445 >> V_73 ) & 1 ;
}
return V_446 ;
}
static unsigned char F_55 ( struct V_2 * V_3 )
{
unsigned char V_447 , V_64 ;
V_447 = F_2 ( V_3 -> V_84 , 0x4A ) ;
F_13 ( V_3 -> V_84 , 0x4A , ~ 0x23 ) ;
V_64 = F_2 ( V_3 -> V_84 , 0x48 ) ;
V_64 = F_54 ( V_64 ) ;
V_64 &= 0x23 ;
F_4 ( V_3 -> V_84 , 0x4A , V_447 ) ;
return V_64 ;
}
static unsigned char F_56 ( struct V_2 * V_3 )
{
unsigned char V_447 , V_448 , V_64 ;
V_447 = F_2 ( V_3 -> V_84 , 0x4A ) ;
F_13 ( V_3 -> V_84 , 0x4A , ~ 0x0C ) ;
V_64 = F_2 ( V_3 -> V_84 , 0x48 ) ;
V_64 &= 0x0C ;
V_64 >>= 2 ;
F_4 ( V_3 -> V_84 , 0x4A , V_447 ) ;
V_448 = F_2 ( V_3 -> V_84 , 0xB4 ) ;
V_64 |= ( ( V_448 & 0x04 ) << 3 ) ;
return V_64 ;
}
static void F_57 ( unsigned short V_449 , unsigned short V_351 ,
struct V_2 * V_3 )
{
unsigned char V_447 , V_64 ;
V_447 = F_2 ( V_3 -> V_84 , 0x4A ) ;
V_449 &= 0x23 ;
V_351 &= 0x23 ;
F_13 ( V_3 -> V_84 , 0x4A , ~ V_449 ) ;
if ( V_449 & 0x20 ) {
V_64 = ( V_351 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_84 , 0xB4 , ~ 0x02 , V_64 ) ;
}
V_64 = F_2 ( V_3 -> V_84 , 0x48 ) ;
V_64 = F_54 ( V_64 ) ;
V_64 &= ~ V_449 ;
V_64 |= V_351 ;
F_4 ( V_3 -> V_84 , 0x48 , V_64 ) ;
}
static void F_58 ( unsigned short V_449 , unsigned short V_351 ,
struct V_2 * V_3 )
{
unsigned char V_447 , V_64 ;
unsigned short V_450 , V_451 ;
V_450 = V_449 ;
V_451 = V_351 ;
V_450 &= 0x20 ;
V_451 &= 0x20 ;
V_450 >>= 3 ;
V_451 >>= 3 ;
if ( V_449 & 0x20 ) {
V_64 = ( V_351 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_84 , 0xB4 , ~ 0x02 , V_64 ) ;
}
F_12 ( V_3 -> V_84 , 0xB4 , ~ V_450 , V_451 ) ;
V_447 = F_2 ( V_3 -> V_84 , 0x4A ) ;
V_449 &= 0x03 ;
V_351 &= 0x03 ;
V_449 <<= 2 ;
V_351 <<= 2 ;
F_13 ( V_3 -> V_84 , 0x4A , ~ V_449 ) ;
F_12 ( V_3 -> V_84 , 0x48 , ~ V_449 , V_351 ) ;
}
static void F_59 ( struct V_452 * V_453 ,
struct V_81 * V_454 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_68 , 0x01 , 0xDF , 0x00 ) ;
if ( V_454 -> V_137 == V_195 ) {
if ( V_3 -> V_105 == 1 ) {
if ( ! ( F_55 ( V_3 ) & 0x1 ) ) {
F_57 ( 0x01 , 0x01 , V_3 ) ;
F_60 ( V_453 -> V_455 . V_456 ) ;
}
if ( ! ( F_55 ( V_3 ) & 0x20 ) )
F_57 ( 0x20 , 0x20 , V_3 ) ;
F_60 ( V_453 -> V_455 . V_457 ) ;
F_57 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_57 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_454 -> V_137 == V_63 ) {
if ( V_3 -> V_105 == 1 ) {
if ( ! ( F_56 ( V_3 ) & 0x1 ) ) {
F_58 ( 0x01 , 0x01 , V_3 ) ;
F_60 ( V_453 -> V_455 . V_456 ) ;
}
if ( ! ( F_56 ( V_3 ) & 0x20 ) )
F_58 ( 0x20 , 0x20 , V_3 ) ;
F_60 ( V_453 -> V_455 . V_457 ) ;
F_58 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_58 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_61 ( struct V_452 * V_453 ,
struct V_81 * V_454 ,
struct V_2 * V_3 )
{
if ( V_454 -> V_137 == V_195 ) {
if ( V_3 -> V_105 == 1 ) {
F_57 ( 0x02 , 0x00 , V_3 ) ;
F_60 ( V_453 -> V_455 . V_457 ) ;
} else {
F_57 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_454 -> V_137 == V_63 ) {
if ( ( F_56 ( V_3 ) & 0x2 ) ) {
F_58 ( 0x02 , 0x00 , V_3 ) ;
F_60 ( V_453 -> V_455 . V_457 ) ;
}
if ( V_3 -> V_105 == 0 )
F_58 ( 0x20 , 0x00 , V_3 ) ;
}
F_12 ( V_3 -> V_68 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_62 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 -> V_89 ) & 0x01 ) )
break;
while ( ! ( F_7 ( V_3 -> V_89 ) & 0x01 ) )
break;
}
static void F_63 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_366 , 0x01 , 0x40 ) ;
}
static void F_64 ( unsigned short V_69 ,
struct V_2 * V_3 )
{
unsigned short V_360 , V_169 ;
F_4 ( V_3 -> V_84 , 0x34 , V_69 ) ;
V_360 = ( V_3 -> V_29 & V_80 ) >> 8 ;
V_169 = ~ ( V_80 >> 8 ) ;
F_12 ( V_3 -> V_84 , 0x31 , V_169 , V_360 ) ;
}
static void F_65 ( unsigned short V_69 ,
unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_199 , V_217 , V_74 , V_161 ;
V_161 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_199 = V_3 -> V_24 [ V_161 ] . V_163 ;
V_217 = V_3 -> V_24 [ V_161 ] . V_164 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
if ( V_74 & V_165 )
V_199 *= 2 ;
if ( V_74 & V_138 )
V_217 *= 2 ;
if ( ! ( V_3 -> V_29 & V_79 ) )
goto exit;
if ( V_3 -> V_105 == 0 ) {
if ( V_3 -> V_26 == V_458 ) {
if ( ! ( V_3 -> V_28 & V_443 ) ) {
if ( V_217 == 1024 )
V_217 = 1056 ;
}
}
if ( V_3 -> V_26 == V_111 ) {
if ( V_217 == 400 )
V_217 = 405 ;
else if ( V_217 == 350 )
V_217 = 360 ;
if ( V_3 -> V_28 & V_443 ) {
if ( V_217 == 360 )
V_217 = 375 ;
}
}
if ( V_3 -> V_26 == V_129 ) {
if ( ! ( V_3 -> V_28 & V_443 ) ) {
if ( ! ( V_3 -> V_28 & V_113 ) ) {
if ( V_217 == 350 )
V_217 = 357 ;
else if ( V_217 == 400 )
V_217 = 420 ;
else if ( V_217 == 480 )
V_217 = 525 ;
}
}
}
}
if ( V_199 == 720 )
V_199 = 640 ;
exit:
V_3 -> V_218 = V_199 ;
V_3 -> V_219 = V_199 ;
V_3 -> V_220 = V_217 ;
V_3 -> V_221 = V_217 ;
}
static unsigned char F_66 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_29 & ( V_79 | V_77 ) ) &&
( V_3 -> V_28 & V_442 ) )
return 1 ;
return 0 ;
}
static void F_67 ( unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_99 , V_100 , V_360 , V_169 , V_74 = 0 , V_162 ,
V_459 ;
V_3 -> V_460 = 1 ;
V_3 -> V_461 = 1 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_459 = V_3 -> V_8 [ V_98 ] . V_140 ;
V_459 &= V_141 ;
V_360 = ( unsigned short ) V_3 -> V_10 [ V_459 ] . V_142 [ 0 ] ;
V_169 = ( unsigned short ) V_3 -> V_10 [ V_459 ] . V_142 [ 5 ] ;
V_99 = ( V_360 & 0xFF ) | ( ( V_169 & 0x03 ) << 8 ) ;
V_100 = ( unsigned short ) V_3 -> V_10 [ V_459 ] . V_142 [ 8 ] ;
V_162 = ( unsigned short )
V_3 -> V_10 [ V_459 ] . V_142 [ 14 ] << 8 ;
V_162 &= 0x0100 ;
V_162 = V_162 << 2 ;
V_100 |= V_162 ;
V_360 = ( unsigned short ) V_3 -> V_10 [ V_459 ] . V_142 [ 9 ] ;
if ( V_360 & 0x01 )
V_100 |= 0x0100 ;
if ( V_360 & 0x20 )
V_100 |= 0x0200 ;
V_99 += 5 ;
if ( V_74 & V_88 )
V_99 *= 8 ;
else
V_99 *= 9 ;
V_3 -> V_337 = V_99 ;
V_3 -> V_339 = V_99 ;
V_100 ++ ;
V_3 -> V_338 = V_100 ;
V_3 -> V_341 = V_100 ;
}
static void F_68 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_99 = 0 , V_100 , V_74 , V_101 ;
struct V_462 * V_336 = NULL ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_3 -> V_463 = 0 ;
V_3 -> V_464 = 50 ;
if ( V_3 -> V_29 & V_106 ) {
F_67 ( V_69 , V_70 , V_98 ,
V_3 ) ;
return;
}
V_100 = 4 ;
if ( V_3 -> V_29 & ( V_79 | V_77 ) ) {
V_336 = F_36 ( V_100 , V_69 , V_70 ,
V_98 , V_3 ) ;
V_3 -> V_460 = V_336 -> V_460 ;
V_3 -> V_461 = V_336 -> V_461 ;
V_3 -> V_337 = V_336 -> V_337 ;
V_3 -> V_338 = V_336 -> V_338 ;
V_3 -> V_339 = V_336 -> V_340 ;
V_3 -> V_341 = V_336 -> V_342 ;
if ( V_3 -> V_26 == V_129 ) {
V_99 = 1024 ;
V_100 = 768 ;
if ( ! ( V_3 -> V_28 & V_443 ) ) {
if ( V_3 -> V_220 == 357 )
V_100 = 527 ;
else if ( V_3 -> V_220 == 420 )
V_100 = 620 ;
else if ( V_3 -> V_220 == 525 )
V_100 = 775 ;
else if ( V_3 -> V_220 == 600 )
V_100 = 775 ;
else
V_100 = 768 ;
} else
V_100 = 768 ;
} else if ( V_3 -> V_26 == V_344 ) {
V_99 = 1024 ;
V_100 = 768 ;
} else if ( V_3 -> V_26 == V_111 ) {
V_99 = 1280 ;
if ( V_3 -> V_220 == 360 )
V_100 = 768 ;
else if ( V_3 -> V_220 == 375 )
V_100 = 800 ;
else if ( V_3 -> V_220 == 405 )
V_100 = 864 ;
else
V_100 = 1024 ;
} else if ( V_3 -> V_26 == V_345 ) {
V_99 = 1280 ;
V_100 = 1024 ;
} else if ( V_3 -> V_26 == V_112 ) {
V_99 = 1280 ;
if ( V_3 -> V_220 == 350 )
V_100 = 700 ;
else if ( V_3 -> V_220 == 400 )
V_100 = 800 ;
else if ( V_3 -> V_220 == 1024 )
V_100 = 960 ;
else
V_100 = 960 ;
} else if ( V_3 -> V_26 == V_346 ) {
V_99 = 1400 ;
V_100 = 1050 ;
if ( V_3 -> V_220 == 1024 ) {
V_99 = 1280 ;
V_100 = 1024 ;
}
} else if ( V_3 -> V_26 == V_458 ) {
V_99 = 1600 ;
V_100 = 1200 ;
if ( ! ( V_3 -> V_28 & V_443 ) ) {
if ( V_3 -> V_220 == 350 )
V_100 = 875 ;
else if ( V_3 -> V_220 == 400 )
V_100 = 1000 ;
}
}
if ( V_3 -> V_28 & V_113 ) {
V_99 = V_3 -> V_218 ;
V_100 = V_3 -> V_220 ;
}
V_3 -> V_219 = V_99 ;
V_3 -> V_221 = V_100 ;
return;
}
if ( V_3 -> V_29 & ( V_78 ) ) {
struct V_331 const * V_465 ;
V_465 = F_37 ( V_69 , V_70 , V_98 ,
V_3 ) ;
V_3 -> V_460 = V_465 -> V_460 ;
V_3 -> V_461 = V_465 -> V_461 ;
V_3 -> V_337 = V_465 -> V_337 ;
V_3 -> V_338 = V_465 -> V_338 ;
V_3 -> V_219 = V_465 -> V_466 ;
V_3 -> V_221 = V_465 -> V_467 ;
V_3 -> V_464 = V_465 -> V_464 ;
V_3 -> V_463 = V_465 -> V_468 ;
if ( V_3 -> V_29 & V_114 ) {
if ( V_101 == 0x08 )
V_3 -> V_463 = 0x40 ;
else if ( V_101 == 0x09 )
V_3 -> V_463 = 0x40 ;
else if ( V_101 == 0x12 )
V_3 -> V_463 = 0x40 ;
if ( V_3 -> V_220 == 350 )
V_3 -> V_30 |= V_117 ;
V_99 = V_469 ;
V_100 = V_470 ;
if ( V_3 -> V_29 & V_80 ) {
if ( V_3 -> V_30 & V_117 ) {
V_99 = V_471 ;
V_100 = V_472 ;
if ( ! ( V_74 & V_88 ) ) {
V_99 = V_473 ;
V_100 = V_474 ;
}
}
}
} else if ( V_3 -> V_29 & V_121 ) {
if ( V_3 -> V_30 & V_383 ) {
V_99 = V_475 ;
V_100 = V_476 ;
}
if ( V_3 -> V_30 & V_385 ) {
V_99 = V_477 ;
V_100 = V_478 ;
} else if ( V_3 -> V_30 & V_431 ) {
V_99 = V_479 ;
V_100 = V_480 ;
if ( V_3 -> V_30 & V_388 )
V_99 = V_481 ;
}
} else {
V_99 = V_482 ;
V_100 = V_483 ;
if ( ! ( V_3 -> V_30 & V_126 ) ) {
V_99 = V_484 ;
V_100 = V_485 ;
if ( V_3 -> V_30 & V_388 )
V_99 = V_481 ;
}
}
V_3 -> V_339 = V_99 ;
V_3 -> V_341 = V_100 ;
return;
}
}
static void F_69 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned char V_374 , V_375 , V_224 ;
V_224 = F_45 ( V_98 , V_69 , V_70 ,
V_3 ) ;
F_46 ( V_224 , & V_374 , & V_375 , V_3 ) ;
F_44 ( & V_374 , & V_375 , V_3 ) ;
if ( V_3 -> V_55 & V_390 ) {
F_4 ( V_3 -> V_373 , 0x0A , 0x10 ) ;
F_4 ( V_3 -> V_373 , 0x0B , V_375 ) ;
F_4 ( V_3 -> V_373 , 0x0A , V_374 ) ;
} else {
F_4 ( V_3 -> V_373 , 0x0A , V_374 ) ;
F_4 ( V_3 -> V_373 , 0x0B , V_375 ) ;
}
F_4 ( V_3 -> V_373 , 0x00 , 0x12 ) ;
if ( V_3 -> V_29 & V_106 )
F_20 ( V_3 -> V_373 , 0x12 , 0x28 ) ;
else
F_20 ( V_3 -> V_373 , 0x12 , 0x08 ) ;
}
static unsigned short F_70 ( unsigned short V_69 ,
unsigned short V_70 , struct V_2 * V_3 )
{
unsigned short V_486 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_139 ;
unsigned short V_74 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_139 = ( V_74 & V_410 ) - V_172 ;
if ( V_139 < 0 )
V_139 = 0 ;
return V_486 [ V_139 ] ;
}
static unsigned short F_71 ( unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_64 , V_487 , V_488 , V_139 , V_102 ,
V_486 [] = { 0x01 , 0x02 , 0x04 } ;
V_488 = V_3 -> V_6 [ V_70 ] . V_171 ;
V_102 = V_3 -> V_8 [ V_98 ] . V_130 ;
V_139 = ( V_488 >> 8 ) & 0xFF ;
V_64 = V_3 -> V_20 [ V_139 ] ;
if ( V_102 & V_166 )
V_64 = V_64 << 1 ;
V_487 = F_70 ( V_69 , V_70 , V_3 ) ;
if ( ( V_69 >= 0x7C ) && ( V_69 <= 0x7E ) ) {
V_64 = V_69 - 0x7C ;
V_487 = V_486 [ V_64 ] ;
V_64 = 0x6B ;
if ( V_102 & V_166 )
V_64 = V_64 << 1 ;
return V_64 * V_487 ;
} else {
return V_64 * V_487 ;
}
}
static void F_72 ( unsigned short V_69 ,
unsigned short V_70 ,
unsigned short V_98 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_489 ;
unsigned char V_64 ;
if ( V_3 -> V_29 & V_80 )
return;
V_489 = F_71 ( V_69 , V_70 , V_98 ,
V_82 , V_3 ) ;
V_64 = ( unsigned char ) ( V_489 & 0xFF ) ;
F_4 ( V_3 -> V_366 , 0x07 , V_64 ) ;
V_64 = ( unsigned char ) ( ( V_489 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_366 , 0x09 , V_64 ) ;
V_64 = ( unsigned char ) ( ( ( V_489 >> 3 ) & 0xFF ) + 1 ) ;
F_4 ( V_3 -> V_366 , 0x03 , V_64 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
F_4 ( V_3 -> V_366 , 0x01 , 0x3B ) ;
F_12 ( V_3 -> V_366 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_74 ( unsigned short V_69 , unsigned short V_70 ,
struct V_81 * V_82 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_162 = 0 , V_459 = 0 , V_101 = 0 ;
V_459 = V_3 -> V_8 [ V_98 ] . V_140 ;
V_459 &= V_141 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
F_72 ( V_69 , V_70 , V_98 ,
V_82 , V_3 ) ;
F_73 ( V_3 ) ;
for ( V_162 = 4 ; V_162 < 7 ; V_162 ++ )
F_4 ( V_3 -> V_366 , V_162 , 0x0 ) ;
F_4 ( V_3 -> V_366 , 0x50 , 0x00 ) ;
F_4 ( V_3 -> V_366 , 0x02 , 0x44 ) ;
}
static void F_75 ( unsigned short V_69 , unsigned short V_70 ,
struct V_81 * V_82 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_64 = 0 , V_99 = 0 , V_100 = 0 , V_162 = 0 ,
V_490 = 0 , V_459 = 0 , V_74 , V_101 = 0 ;
V_459 = V_3 -> V_8 [ V_98 ] . V_140 ;
V_459 &= V_141 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
if ( V_74 & V_165 ) {
V_64 = ( V_3 -> V_337 / 2 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_366 , 0x08 , V_64 ) ;
V_64 = ( ( ( V_3 -> V_337 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_366 , 0x09 , ~ 0x0F0 , V_64 ) ;
V_64 = ( V_3 -> V_218 / 2 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_366 , 0x0A , V_64 ) ;
V_162 = ( ( V_3 -> V_337 - V_3 -> V_218 ) / 2 ) >> 2 ;
V_490 = V_3 -> V_218 / 2 + 16 ;
V_162 = V_162 >> 1 ;
V_100 = V_490 + V_162 ;
V_162 += V_100 ;
if ( V_3 -> V_29 & V_106 ) {
V_100 = V_3 -> V_10 [ V_459 ] . V_142 [ 4 ] ;
V_100 |= ( ( V_3 ->
V_10 [ V_459 ] . V_142 [ 14 ] &
0xC0 ) << 2 ) ;
V_100 = ( V_100 - 3 ) << 3 ;
V_162 = V_3 -> V_10 [ V_459 ] . V_142 [ 5 ] ;
V_162 &= 0x1F ;
V_64 = V_3 -> V_10 [ V_459 ] . V_142 [ 15 ] ;
V_64 = ( V_64 & 0x04 ) << ( 5 - 2 ) ;
V_162 = ( ( V_162 | V_64 ) - 3 ) << 3 ;
}
V_100 += 4 ;
V_162 += 4 ;
if ( V_162 > ( V_3 -> V_337 / 2 ) )
V_162 = V_3 -> V_337 / 2 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x0B , V_64 ) ;
} else {
V_64 = ( V_3 -> V_337 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_366 , 0x08 , V_64 ) ;
V_64 = ( ( ( V_3 -> V_337 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_366 , 0x09 , ~ 0x0F0 , V_64 ) ;
V_64 = ( V_3 -> V_218 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_366 , 0x0A , V_64 ) ;
V_162 = ( V_3 -> V_337 - V_3 -> V_218 ) >> 2 ;
V_490 = V_3 -> V_218 + 16 ;
V_162 = V_162 >> 1 ;
V_100 = V_490 + V_162 ;
V_162 += V_100 ;
if ( V_3 -> V_29 & V_106 ) {
V_100 = V_3 -> V_10 [ V_459 ] . V_142 [ 3 ] ;
V_100 |= ( ( V_3 ->
V_10 [ V_459 ] . V_142 [ 5 ] &
0xC0 ) << 2 ) ;
V_100 = ( V_100 - 3 ) << 3 ;
V_162 = V_3 -> V_10 [ V_459 ] . V_142 [ 4 ] ;
V_162 &= 0x1F ;
V_64 = V_3 -> V_10 [ V_459 ] . V_142 [ 6 ] ;
V_64 = ( V_64 & 0x04 ) << ( 5 - 2 ) ;
V_162 = ( ( V_162 | V_64 ) - 3 ) << 3 ;
V_100 += 16 ;
V_162 += 16 ;
}
if ( V_162 > V_3 -> V_337 )
V_162 = V_3 -> V_337 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x0B , V_64 ) ;
}
V_99 = ( V_99 & 0x00FF ) | ( V_100 & 0xFF00 ) ;
V_100 = V_490 ;
V_100 = ( V_100 & 0x00FF ) | ( ( V_100 & 0xFF00 ) << 4 ) ;
V_99 |= ( V_100 & 0xFF00 ) ;
V_64 = ( V_99 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_366 , 0x0C , V_64 ) ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x0D , V_64 ) ;
V_162 = ( V_3 -> V_338 - 1 ) ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x0E , V_64 ) ;
V_100 = V_3 -> V_220 - 1 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x0F , V_64 ) ;
V_64 = ( ( V_100 & 0xFF00 ) << 3 ) >> 8 ;
V_64 |= ( ( V_162 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_366 , 0x12 , V_64 ) ;
V_99 = V_3 -> V_220 ;
V_100 = V_3 -> V_220 ;
V_162 = V_3 -> V_338 ;
V_100 = ( V_3 -> V_338 + V_3 -> V_220 ) >> 1 ;
V_162 = ( ( V_3 -> V_338 - V_3 -> V_220 ) >> 4 ) + V_100 + 1 ;
if ( V_3 -> V_29 & V_106 ) {
V_100 = V_3 -> V_10 [ V_459 ] . V_142 [ 10 ] ;
V_64 = V_3 -> V_10 [ V_459 ] . V_142 [ 9 ] ;
if ( V_64 & 0x04 )
V_100 |= 0x0100 ;
if ( V_64 & 0x080 )
V_100 |= 0x0200 ;
V_64 = V_3 -> V_10 [ V_459 ] . V_142 [ 14 ] ;
if ( V_64 & 0x08 )
V_100 |= 0x0400 ;
V_64 = V_3 -> V_10 [ V_459 ] . V_142 [ 11 ] ;
V_162 = ( V_162 & 0xFF00 ) | ( V_64 & 0x00FF ) ;
}
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x10 , V_64 ) ;
V_64 = ( ( V_100 & 0xFF00 ) >> 8 ) << 4 ;
V_64 = ( ( V_162 & 0x000F ) | ( V_64 ) ) ;
F_4 ( V_3 -> V_366 , 0x11 , V_64 ) ;
V_99 = 0 ;
if ( V_74 & V_138 )
V_99 |= 0x80 ;
if ( V_74 & V_165 )
V_99 |= 0x40 ;
F_12 ( V_3 -> V_366 , 0x2C , ~ 0x0C0 , V_99 ) ;
}
static unsigned short F_76 ( struct V_2 * V_3 )
{
unsigned long V_99 , V_100 ;
V_100 = ( ( V_3 -> V_338 - V_3 -> V_220 ) * V_3 -> V_460 )
& 0xFFFF ;
V_99 = ( V_3 -> V_341 - V_3 -> V_221 ) * V_3 -> V_461 ;
V_99 = ( V_99 * V_3 -> V_339 ) / V_100 ;
return ( unsigned short ) V_99 ;
}
static void F_77 ( unsigned short V_69 , unsigned short V_70 ,
struct V_81 * V_82 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_358 , V_359 , V_99 , V_100 = 0 , V_162 , V_64 , V_101 ,
V_74 , V_459 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_459 = V_3 -> V_8 [ V_98 ] . V_140 ;
V_459 &= V_141 ;
if ( ! ( V_3 -> V_29 & V_80 ) )
return;
V_64 = 0xFF ;
F_4 ( V_3 -> V_366 , 0x03 , V_64 ) ;
V_162 = 0x08 ;
if ( V_3 -> V_55 & ( V_56 | V_57 | V_108 ) )
V_74 |= V_88 ;
V_99 = V_3 -> V_218 ;
if ( V_74 & V_165 )
V_99 = V_99 >> 1 ;
V_99 = ( V_99 / V_162 ) - 1 ;
V_100 |= ( ( V_99 & 0x00FF ) << 8 ) ;
V_64 = V_99 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x04 , V_64 ) ;
V_64 = ( V_100 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_29 & V_78 ) {
if ( ! ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) )
V_64 += 2 ;
if ( ( V_3 -> V_29 & V_114 ) &&
! ( V_3 -> V_55 & V_56 ) && ( V_101 == 7 ) )
V_64 -= 2 ;
}
F_4 ( V_3 -> V_366 , 0x05 , V_64 ) ;
F_4 ( V_3 -> V_366 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_29 & V_412 ) ) {
if ( V_3 -> V_29 & V_78 )
V_99 = V_3 -> V_337 ;
else
V_99 = F_76 ( V_3 ) ;
}
if ( V_99 >= V_3 -> V_337 )
V_99 = V_3 -> V_337 ;
if ( V_74 & V_165 )
V_99 = V_99 >> 1 ;
V_99 = ( V_99 / V_162 ) - 5 ;
V_162 = V_99 ;
if ( V_3 -> V_29 & V_114 ) {
V_64 = ( V_100 & 0x00FF ) - 1 ;
if ( ! ( V_74 & V_165 ) ) {
V_64 -= 6 ;
if ( V_3 -> V_30 & V_117 ) {
V_64 -= 4 ;
V_64 -= 10 ;
}
}
} else {
V_100 = ( V_100 & 0xFF00 ) >> 8 ;
V_162 = ( V_162 + V_100 ) >> 1 ;
V_64 = ( V_162 & 0x00FF ) + 2 ;
if ( V_3 -> V_29 & V_78 ) {
V_64 -= 1 ;
if ( ! ( V_74 & V_165 ) ) {
if ( ( V_74 & V_88 ) ) {
V_64 += 4 ;
if ( V_3 -> V_218 >= 800 )
V_64 -= 6 ;
}
}
} else if ( ! ( V_74 & V_165 ) ) {
V_64 -= 4 ;
if ( V_3 -> V_26 != V_112 &&
V_3 -> V_218 >= 800 ) {
V_64 -= 7 ;
if ( V_3 -> V_218 >= 1280 &&
V_3 -> V_26 != V_112 &&
( V_3 -> V_28 & V_113 ) )
V_64 += 28 ;
}
}
}
F_4 ( V_3 -> V_366 , 0x07 , V_64 ) ;
F_4 ( V_3 -> V_366 , 0x08 , 0 ) ;
if ( V_3 -> V_29 & V_78 ) {
if ( V_3 -> V_30 & V_117 ) {
if ( V_69 == 0x50 ) {
if ( V_3 -> V_30 & V_491 ) {
F_4 ( V_3 -> V_366 ,
0x07 , 0x30 ) ;
F_4 ( V_3 -> V_366 ,
0x08 , 0x03 ) ;
} else {
F_4 ( V_3 -> V_366 ,
0x07 , 0x2f ) ;
F_4 ( V_3 -> V_366 ,
0x08 , 0x02 ) ;
}
}
}
}
F_4 ( V_3 -> V_366 , 0x18 , 0x03 ) ;
F_12 ( V_3 -> V_366 , 0x19 , 0xF0 , 0x00 ) ;
F_4 ( V_3 -> V_366 , 0x09 , 0xFF ) ;
V_100 = V_3 -> V_338 ;
V_358 = V_100 ;
V_162 = 0x121 ;
V_100 = V_3 -> V_220 ;
if ( V_100 == 357 )
V_100 = 350 ;
if ( V_100 == 360 )
V_100 = 350 ;
if ( V_100 == 375 )
V_100 = 350 ;
if ( V_100 == 405 )
V_100 = 400 ;
if ( V_100 == 525 )
V_100 = 480 ;
V_359 = V_100 ;
if ( V_3 -> V_29 & V_79 ) {
if ( V_3 -> V_26 == V_129 ) {
if ( ! ( V_3 -> V_28 & V_443 ) ) {
if ( V_100 == 350 )
V_100 += 5 ;
if ( V_100 == 480 )
V_100 += 5 ;
}
}
}
V_100 -- ;
V_64 = V_100 & 0x00FF ;
V_100 -- ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x10 , V_64 ) ;
V_100 = V_359 ;
V_100 -- ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x0E , V_64 ) ;
if ( V_100 & 0x0100 )
V_162 |= 0x0002 ;
V_99 = 0x000B ;
if ( V_74 & V_138 )
V_99 |= 0x08000 ;
if ( V_100 & 0x0200 )
V_162 |= 0x0040 ;
V_64 = ( V_99 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_366 , 0x0B , V_64 ) ;
if ( V_100 & 0x0400 )
V_162 |= 0x0600 ;
F_4 ( V_3 -> V_366 , 0x11 , 0x00 ) ;
V_99 = V_358 ;
V_99 -= V_100 ;
V_99 = V_99 >> 2 ;
V_358 = V_99 ;
if ( V_101 != 0x09 ) {
V_99 = V_99 << 1 ;
V_100 += V_99 ;
}
if ( V_3 -> V_29 & V_114 ) {
if ( ( V_3 -> V_55 & V_56 ) &&
! ( V_3 -> V_30 & V_434 ) ) {
if ( ( V_3 -> V_30 & V_117 ) &&
( V_3 -> V_30 & V_126 ) ) {
if ( ! ( V_3 -> V_55 & V_56 ) ||
! ( V_3 -> V_30 &
( V_385 |
V_383 |
V_434 ) ) )
V_100 += 40 ;
}
} else {
V_100 -= 10 ;
}
} else if ( V_3 -> V_30 & V_117 ) {
if ( V_3 -> V_30 & V_126 ) {
if ( V_3 -> V_55 & V_56 ) {
if ( ! ( V_3 -> V_30 &
( V_385 |
V_383 |
V_434 ) ) )
V_100 += 40 ;
} else {
V_100 += 40 ;
}
}
}
V_99 = V_358 ;
V_99 = V_99 >> 2 ;
V_99 ++ ;
V_99 += V_100 ;
V_358 = V_99 ;
if ( ( V_3 -> V_30 & V_126 ) ) {
if ( V_100 <= 513 ) {
if ( V_99 >= 513 )
V_100 = 513 ;
}
}
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x0C , V_64 ) ;
V_100 -- ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x10 , V_64 ) ;
if ( V_100 & 0x0100 )
V_162 |= 0x0008 ;
if ( V_100 & 0x0200 )
F_12 ( V_3 -> V_366 , 0x0B , 0x0FF , 0x20 ) ;
V_100 ++ ;
if ( V_100 & 0x0100 )
V_162 |= 0x0004 ;
if ( V_100 & 0x0200 )
V_162 |= 0x0080 ;
if ( V_100 & 0x0400 )
V_162 |= 0x0C00 ;
V_100 = V_358 ;
V_64 = V_100 & 0x00FF ;
V_64 &= 0x0F ;
F_4 ( V_3 -> V_366 , 0x0D , V_64 ) ;
if ( V_100 & 0x0010 )
V_162 |= 0x2000 ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_366 , 0x0A , V_64 ) ;
V_64 = ( V_162 & 0x0FF00 ) >> 8 ;
F_4 ( V_3 -> V_366 , 0x17 , V_64 ) ;
V_99 = V_74 ;
V_64 = ( V_99 & 0xFF00 ) >> 8 ;
V_64 = ( V_64 >> 1 ) & 0x09 ;
if ( V_3 -> V_55 & ( V_56 | V_57 | V_108 ) )
V_64 |= 0x01 ;
F_4 ( V_3 -> V_366 , 0x16 , V_64 ) ;
F_4 ( V_3 -> V_366 , 0x0F , 0 ) ;
F_4 ( V_3 -> V_366 , 0x12 , 0 ) ;
if ( V_3 -> V_28 & V_492 )
V_64 = 0x80 ;
else
V_64 = 0x00 ;
F_4 ( V_3 -> V_366 , 0x1A , V_64 ) ;
return;
}
static void F_78 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_73 , V_136 , V_99 , V_100 , V_162 , V_64 , V_358 , V_359 ,
V_74 , V_101 , V_493 ;
unsigned char const * V_494 ;
unsigned long V_495 , V_496 , V_497 , V_169 , V_498 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_493 = V_3 -> V_8 [ V_98 ] . V_175 ;
V_99 = 0 ;
if ( ! ( V_3 -> V_29 & V_118 ) )
V_99 |= 0x0800 ;
if ( ! ( V_3 -> V_29 & V_119 ) )
V_99 |= 0x0400 ;
if ( V_3 -> V_29 & V_120 )
V_99 |= 0x0200 ;
if ( ! ( V_3 -> V_30 & V_126 ) )
V_99 |= 0x1000 ;
if ( V_3 -> V_29 & V_114 )
V_99 |= 0x0100 ;
if ( V_3 -> V_30 & ( V_385 | V_383 ) )
V_99 &= 0xfe00 ;
V_99 = ( V_99 & 0xff00 ) >> 8 ;
F_4 ( V_3 -> V_396 , 0x0 , V_99 ) ;
V_494 = V_499 ;
if ( V_3 -> V_30 & V_126 )
V_494 = V_500 ;
if ( V_3 -> V_29 & V_114 ) {
V_494 = V_501 ;
if ( V_3 -> V_29 & V_80 )
V_494 = V_502 ;
if ( V_3 -> V_116 & V_117 )
V_494 = V_503 ;
if ( ! ( V_74 & V_88 ) )
V_494 = V_504 ;
}
if ( V_3 -> V_29 & V_121 ) {
if ( V_3 -> V_30 & V_431 )
V_494 = V_505 ;
if ( V_3 -> V_30 & V_385 )
V_494 = V_506 ;
if ( V_3 -> V_30 & V_383 )
V_494 = V_507 ;
}
for ( V_73 = 0x01 , V_136 = 0 ; V_73 <= 0x2D ; V_73 ++ , V_136 ++ )
F_4 ( V_3 -> V_396 , V_73 , V_494 [ V_136 ] ) ;
for ( V_73 = 0x39 ; V_73 <= 0x45 ; V_73 ++ , V_136 ++ )
F_4 ( V_3 -> V_396 , V_73 , V_494 [ V_136 ] ) ;
if ( V_3 -> V_29 & V_78 )
F_12 ( V_3 -> V_396 , 0x3A , 0x1F , 0x00 ) ;
V_64 = V_3 -> V_463 ;
V_64 &= 0x80 ;
F_12 ( V_3 -> V_396 , 0x0A , 0xFF , V_64 ) ;
if ( V_3 -> V_29 & V_114 )
V_99 = 950 ;
if ( V_3 -> V_30 & V_126 )
V_99 = 520 ;
else
V_99 = 440 ;
if ( V_3 -> V_221 <= V_99 ) {
V_99 -= V_3 -> V_221 ;
V_99 = V_99 >> 2 ;
V_99 = ( V_99 & 0x00FF ) | ( ( V_99 & 0x00FF ) << 8 ) ;
V_358 = V_99 ;
V_64 = ( V_99 & 0xFF00 ) >> 8 ;
V_64 += ( unsigned short ) V_494 [ 0 ] ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
if ( V_3 -> V_29 & ( V_118
| V_119 | V_120
| V_121 ) ) {
V_162 = V_3 -> V_218 ;
if ( V_162 >= 1024 ) {
V_64 = 0x17 ;
if ( V_3 -> V_30 & V_126 )
V_64 = 0x19 ;
}
}
}
F_4 ( V_3 -> V_396 , 0x01 , V_64 ) ;
V_99 = V_358 ;
V_64 = ( V_99 & 0xFF00 ) >> 8 ;
V_64 += V_494 [ 1 ] ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
if ( ( V_3 -> V_29 & ( V_118
| V_119 | V_120
| V_121 ) ) ) {
V_162 = V_3 -> V_218 ;
if ( V_162 >= 1024 ) {
V_64 = 0x1D ;
if ( V_3 -> V_30 & V_126 )
V_64 = 0x52 ;
}
}
}
F_4 ( V_3 -> V_396 , 0x02 , V_64 ) ;
}
V_162 = V_3 -> V_339 ;
if ( F_66 ( V_3 ) )
V_162 = V_162 >> 1 ;
V_162 -= 2 ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x1B , V_64 ) ;
V_64 = ( V_162 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_396 , 0x1D , ~ 0x0F , V_64 ) ;
V_162 = V_3 -> V_339 >> 1 ;
V_358 = V_162 ;
V_162 += 7 ;
if ( V_3 -> V_29 & V_114 )
V_162 -= 4 ;
V_64 = V_162 & 0x00FF ;
V_64 = V_64 << 4 ;
F_12 ( V_3 -> V_396 , 0x22 , 0x0F , V_64 ) ;
V_100 = V_494 [ V_136 ] | ( ( V_494 [ V_136 + 1 ] ) << 8 ) ;
V_100 += V_162 ;
V_359 = V_100 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x24 , V_64 ) ;
V_64 = ( V_100 & 0xFF00 ) >> 8 ;
V_64 = V_64 << 4 ;
F_12 ( V_3 -> V_396 , 0x25 , 0x0F , V_64 ) ;
V_100 = V_359 ;
V_100 = V_100 + 8 ;
if ( V_3 -> V_29 & V_114 ) {
V_100 = V_100 - 4 ;
V_162 = V_100 ;
}
V_64 = ( V_100 & 0x00FF ) << 4 ;
F_12 ( V_3 -> V_396 , 0x29 , 0x0F , V_64 ) ;
V_136 += 2 ;
V_162 += ( V_494 [ V_136 ] | ( ( V_494 [ V_136 + 1 ] ) << 8 ) ) ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x27 , V_64 ) ;
V_64 = ( ( V_162 & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_396 , 0x28 , 0x0F , V_64 ) ;
V_162 += 8 ;
if ( V_3 -> V_29 & V_114 )
V_162 -= 4 ;
V_64 = V_162 & 0xFF ;
V_64 = V_64 << 4 ;
F_12 ( V_3 -> V_396 , 0x2A , 0x0F , V_64 ) ;
V_162 = V_358 ;
V_136 += 2 ;
V_64 = V_494 [ V_136 ] | ( ( V_494 [ V_136 + 1 ] ) << 8 ) ;
V_162 -= V_64 ;
V_64 = V_162 & 0x00FF ;
V_64 = V_64 << 4 ;
F_12 ( V_3 -> V_396 , 0x2D , 0x0F , V_64 ) ;
V_162 -= 11 ;
if ( ! ( V_3 -> V_29 & V_78 ) ) {
V_99 = F_76 ( V_3 ) ;
V_162 = V_99 - 1 ;
}
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x2E , V_64 ) ;
V_100 = V_3 -> V_221 ;
if ( V_3 -> V_220 == 360 )
V_100 = 746 ;
if ( V_3 -> V_220 == 375 )
V_100 = 746 ;
if ( V_3 -> V_220 == 405 )
V_100 = 853 ;
if ( V_3 -> V_29 & V_78 ) {
if ( V_3 -> V_55 &
( V_56 | V_57 | V_108 ) ) {
if ( ! ( V_3 -> V_30 &
( V_385 | V_383 ) ) )
V_100 = V_100 >> 1 ;
} else
V_100 = V_100 >> 1 ;
}
V_100 -= 2 ;
V_64 = V_100 & 0x00FF ;
if ( V_3 -> V_29 & V_114 ) {
if ( V_3 -> V_55 & V_56 ) {
if ( V_3 -> V_30 & V_434 ) {
if ( V_3 -> V_29 & V_80 ) {
if ( V_69 == 0x2f )
V_64 += 1 ;
}
}
} else if ( V_3 -> V_29 & V_80 ) {
if ( V_69 == 0x2f )
V_64 += 1 ;
}
}
F_4 ( V_3 -> V_396 , 0x2F , V_64 ) ;
V_64 = ( V_162 & 0xFF00 ) >> 8 ;
V_64 |= ( ( V_100 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_29 & V_114 ) ) {
if ( V_3 -> V_55 & V_56 ) {
if ( V_3 -> V_30 & V_434 ) {
V_64 |= 0x10 ;
if ( ! ( V_3 -> V_29 & V_119 ) )
V_64 |= 0x20 ;
}
} else {
V_64 |= 0x10 ;
if ( ! ( V_3 -> V_29 & V_119 ) )
V_64 |= 0x20 ;
}
}
F_4 ( V_3 -> V_396 , 0x30 , V_64 ) ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
V_100 = V_3 -> V_221 ;
V_162 = V_100 - 2 ;
if ( V_3 -> V_29 & V_78 ) {
if ( ! ( V_3 -> V_30 & ( V_385
| V_383 ) ) )
V_100 = V_100 >> 1 ;
}
if ( V_3 -> V_55 & ( V_57 | V_108 ) ) {
V_64 = 0 ;
if ( V_162 & 0x0400 )
V_64 |= 0x20 ;
if ( V_100 & 0x0400 )
V_64 |= 0x40 ;
F_4 ( V_3 -> V_373 , 0x10 , V_64 ) ;
}
V_64 = ( ( ( V_100 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_4 ( V_3 -> V_396 , 0x46 , V_64 ) ;
V_64 = ( V_100 - 3 ) & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x47 , V_64 ) ;
}
V_100 = V_100 & 0x00FF ;
if ( ! ( V_74 & V_165 ) ) {
V_162 = V_3 -> V_218 ;
if ( V_162 >= V_3 -> V_219 ) {
V_100 |= 0x2000 ;
V_99 &= 0x00FF ;
}
}
V_162 = 0x0101 ;
if ( V_3 -> V_29 & V_78 ) {
if ( V_3 -> V_218 >= 1024 ) {
V_162 = 0x1920 ;
if ( V_3 -> V_218 >= 1280 ) {
V_162 = 0x1420 ;
V_100 = V_100 & 0xDFFF ;
}
}
}
if ( ! ( V_100 & 0x2000 ) ) {
if ( V_74 & V_165 )
V_162 = ( V_162 & 0xFF00 ) | ( ( V_162 & 0x00FF ) << 1 ) ;
V_358 = V_100 ;
V_496 = V_3 -> V_218 ;
V_497 = ( V_162 & 0xFF00 ) >> 8 ;
V_495 = V_496 * V_497 ;
V_498 = V_162 & 0x00FF ;
V_495 = V_495 / V_498 ;
V_498 = 8 * 1024 ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
V_498 = V_498 * 8 ;
}
V_495 = V_495 * V_498 ;
V_498 = V_3 -> V_219 ;
V_169 = V_495 % V_498 ;
V_496 = V_495 / V_498 ;
if ( V_169 != 0 )
V_496 += 1 ;
V_99 = ( unsigned short ) V_496 ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
V_162 = ( ( V_99 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_100 = V_358 ;
V_100 = ( unsigned short ) ( ( ( V_496 & 0x0000FF00 ) & 0x1F00 )
| ( V_100 & 0x00FF ) ) ;
V_99 = ( unsigned short ) ( ( ( V_496 & 0x000000FF ) << 8 )
| ( V_99 & 0x00FF ) ) ;
V_64 = ( V_99 & 0xFF00 ) >> 8 ;
} else {
V_64 = ( V_99 & 0x00FF ) >> 8 ;
}
F_4 ( V_3 -> V_396 , 0x44 , V_64 ) ;
V_64 = ( V_100 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_396 , 0x45 , ~ 0x03F , V_64 ) ;
V_64 = V_162 & 0x00FF ;
if ( V_100 & 0x2000 )
V_64 = 0 ;
if ( ! ( V_3 -> V_29 & V_79 ) )
V_64 |= 0x18 ;
F_12 ( V_3 -> V_396 , 0x46 , ~ 0x1F , V_64 ) ;
if ( V_3 -> V_30 & V_126 ) {
V_100 = 0x0382 ;
V_162 = 0x007e ;
} else {
V_100 = 0x0369 ;
V_162 = 0x0061 ;
}
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x4b , V_64 ) ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x4c , V_64 ) ;
V_64 = ( ( V_162 & 0xFF00 ) >> 8 ) & 0x03 ;
V_64 = V_64 << 2 ;
V_64 |= ( ( V_100 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_29 & V_121 ) {
V_64 |= 0x10 ;
if ( V_3 -> V_30 & V_385 )
V_64 |= 0x20 ;
if ( V_3 -> V_30 & V_383 )
V_64 |= 0x60 ;
}
F_4 ( V_3 -> V_396 , 0x4d , V_64 ) ;
V_64 = F_2 ( V_3 -> V_396 , 0x43 ) ;
F_4 ( V_3 -> V_396 , 0x43 , ( unsigned short ) ( V_64 - 3 ) ) ;
if ( ! ( V_3 -> V_30 & ( V_385 | V_383 ) ) ) {
if ( V_3 -> V_30 & V_388 ) {
V_494 = V_508 ;
for ( V_73 = 0x1c , V_136 = 0 ; V_73 <= 0x30 ; V_73 ++ , V_136 ++ ) {
F_4 ( V_3 -> V_396 , V_73 ,
V_494 [ V_136 ] ) ;
}
F_4 ( V_3 -> V_396 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_55 & V_108 ) {
if ( V_3 -> V_30 & V_427 )
F_12 ( V_3 -> V_396 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_30 & V_427 ) {
V_99 = ( unsigned char ) F_2 ( V_3 -> V_396 ,
0x01 ) ;
V_99 -- ;
F_13 ( V_3 -> V_396 , 0x01 , V_99 ) ;
F_13 ( V_3 -> V_396 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_29 & V_114 ) {
if ( ! ( V_3 -> V_29 & V_80 ) )
F_4 ( V_3 -> V_396 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_29 & V_78 )
return;
}
static void F_79 ( unsigned short V_69 , unsigned short V_70 ,
struct V_81 * V_82 ,
unsigned short V_98 ,
struct V_2 * V_3 )
{
unsigned short V_358 , V_359 , V_490 , V_99 , V_100 , V_162 , V_64 ,
V_71 , V_449 , V_392 , V_101 , V_74 , V_459 ;
struct V_363 * V_509 = NULL ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_101 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_459 = V_3 -> V_8 [ V_98 ] . V_140 ;
V_459 &= V_141 ;
if ( ! ( V_3 -> V_29 & V_79 ) )
return;
V_100 = V_3 -> V_219 ;
if ( F_66 ( V_3 ) )
V_100 = V_100 >> 1 ;
V_100 -= 1 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x2C , V_64 ) ;
V_64 = ( V_100 & 0xFF00 ) >> 8 ;
V_64 = V_64 << 4 ;
F_12 ( V_3 -> V_396 , 0x2B , 0x0F , V_64 ) ;
V_64 = 0x01 ;
F_4 ( V_3 -> V_396 , 0x0B , V_64 ) ;
V_100 = V_3 -> V_221 ;
V_358 = V_100 ;
V_100 -- ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x03 , V_64 ) ;
V_64 = ( ( V_100 & 0xFF00 ) >> 8 ) & 0x07 ;
F_12 ( V_3 -> V_396 , 0x0C , ~ 0x07 , V_64 ) ;
V_162 = V_3 -> V_341 - 1 ;
V_359 = V_162 + 1 ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x19 , V_64 ) ;
V_64 = ( V_162 & 0xFF00 ) >> 8 ;
V_64 = V_64 << 5 ;
F_4 ( V_3 -> V_396 , 0x1A , V_64 ) ;
F_12 ( V_3 -> V_396 , 0x09 , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_396 , 0x0A , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_396 , 0x17 , 0xFB , 0x00 ) ;
F_12 ( V_3 -> V_396 , 0x18 , 0xDF , 0x00 ) ;
V_100 = 5 ;
V_509 = F_36 ( V_100 , V_69 , V_70 ,
V_98 , V_3 ) ;
V_71 = V_3 -> V_26 ;
V_71 &= V_235 ;
if ( ( V_71 == V_129 ) || ( V_71 == V_344 ) ) {
V_100 = 1024 ;
V_162 = 768 ;
} else if ( ( V_71 == V_111 ) ||
( V_71 == V_345 ) ) {
V_100 = 1280 ;
V_162 = 1024 ;
} else if ( V_71 == V_346 ) {
V_100 = 1400 ;
V_162 = 1050 ;
} else {
V_100 = 1600 ;
V_162 = 1200 ;
}
if ( V_3 -> V_28 & V_234 ) {
V_100 = V_3 -> V_219 ;
V_162 = V_3 -> V_221 ;
}
V_490 = V_100 ;
V_99 = V_3 -> V_341 ;
V_3 -> V_365 = V_509 -> V_365 ;
V_3 -> V_367 = V_509 -> V_367 ;
V_3 -> V_369 = V_509 -> V_369 ;
V_3 -> V_370 = V_509 -> V_370 ;
V_100 = V_3 -> V_369 ;
V_162 += V_100 ;
if ( V_162 >= V_99 )
V_162 -= V_99 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x05 , V_64 ) ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x06 , V_64 ) ;
V_392 = ( ( V_162 & 0xFF00 ) >> 8 ) & 0x07 ;
V_449 = ( ( V_100 & 0xFF00 ) >> 8 ) & 0x07 ;
V_71 = V_392 ;
V_71 = V_71 << 3 ;
V_71 |= V_449 ;
F_4 ( V_3 -> V_396 , 0x02 , V_71 ) ;
F_42 ( & V_99 , & V_100 , V_3 ) ;
V_162 = V_100 ;
V_99 = V_3 -> V_341 ;
V_100 = V_3 -> V_370 ;
V_162 += V_100 ;
if ( V_162 >= V_99 )
V_162 -= V_99 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x04 , V_64 ) ;
V_64 = ( V_100 & 0xFF00 ) >> 8 ;
V_64 = V_64 << 4 ;
V_64 |= ( V_162 & 0x000F ) ;
F_4 ( V_3 -> V_396 , 0x01 , V_64 ) ;
V_162 = V_490 ;
V_99 = V_3 -> V_339 ;
V_100 = V_3 -> V_365 ;
V_100 &= 0x0FFF ;
if ( F_66 ( V_3 ) ) {
V_99 = V_99 >> 1 ;
V_100 = V_100 >> 1 ;
V_162 = V_162 >> 1 ;
}
if ( V_3 -> V_55 & V_57 )
V_100 += 1 ;
if ( V_3 -> V_55 & V_108 )
V_100 += 1 ;
V_162 += V_100 ;
if ( V_162 >= V_99 )
V_162 -= V_99 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x1F , V_64 ) ;
V_64 = ( ( V_100 & 0xFF00 ) >> 8 ) << 4 ;
F_4 ( V_3 -> V_396 , 0x20 , V_64 ) ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x23 , V_64 ) ;
V_64 = ( V_162 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_396 , 0x25 , V_64 ) ;
F_42 ( & V_99 , & V_100 , V_3 ) ;
V_162 = V_99 ;
V_99 = V_3 -> V_339 ;
V_100 = V_3 -> V_367 ;
if ( F_66 ( V_3 ) ) {
V_99 = V_99 >> 1 ;
V_100 = V_100 >> 1 ;
V_162 = V_162 >> 1 ;
}
if ( V_3 -> V_55 & V_57 )
V_100 += 1 ;
V_162 += V_100 ;
if ( V_162 >= V_99 )
V_162 -= V_99 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x1C , V_64 ) ;
V_64 = ( V_100 & 0xFF00 ) >> 8 ;
V_64 = V_64 << 4 ;
F_12 ( V_3 -> V_396 , 0x1D , ~ 0x0F0 , V_64 ) ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_396 , 0x21 , V_64 ) ;
if ( ! ( V_3 -> V_28 & V_443 ) ) {
if ( V_3 -> V_220 == 525 ) {
if ( V_3 -> V_55 & ( V_123 | V_124
| V_56 | V_57
| V_108 ) ) {
V_64 = 0xC6 ;
} else
V_64 = 0xC4 ;
F_4 ( V_3 -> V_396 , 0x2f , V_64 ) ;
F_4 ( V_3 -> V_396 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_220 == 420 ) {
if ( V_3 -> V_55 & ( V_123 | V_124
| V_56 | V_57
| V_108 ) ) {
V_64 = 0x4F ;
} else
V_64 = 0x4E ;
F_4 ( V_3 -> V_396 , 0x2f , V_64 ) ;
}
}
}
static struct V_510 * F_80 ( unsigned short V_162 ,
struct V_2 * V_3 )
{
unsigned short V_99 , V_100 , V_73 ;
struct V_510 * V_511 ;
if ( V_162 == 0 ) {
V_99 = V_3 -> V_218 ;
V_100 = V_3 -> V_219 ;
} else {
V_99 = V_3 -> V_220 ;
V_100 = V_3 -> V_221 ;
}
if ( V_99 <= V_100 )
return & V_512 [ 0 ] ;
else
V_511 = V_513 ;
if ( V_3 -> V_30 & V_126 )
V_511 = V_514 ;
if ( V_3 -> V_29 & V_121 ) {
if ( ( V_3 -> V_30 & V_431 ) ||
( V_3 -> V_30 & V_385 ) )
V_511 = V_513 ;
if ( V_3 -> V_30 & V_383 )
V_511 = V_515 ;
}
if ( V_3 -> V_29 & V_114 )
V_511 = V_512 ;
V_73 = 0 ;
while ( V_511 [ V_73 ] . V_516 != 0xFFFF ) {
if ( V_511 [ V_73 ] . V_516 == V_99 )
break;
V_73 ++ ;
}
return & V_511 [ V_73 ] ;
}
static void F_81 ( struct V_2 * V_3 )
{
unsigned short V_73 , V_136 ;
struct V_510 * V_511 ;
if ( ! ( V_3 -> V_55 & V_108 ) )
return;
V_511 = F_80 ( 0 , V_3 ) ;
for ( V_73 = 0x80 , V_136 = 0 ; V_73 <= 0xBF ; V_73 ++ , V_136 ++ )
F_4 ( V_3 -> V_396 , V_73 , V_511 -> V_350 [ V_136 ] ) ;
if ( ( V_3 -> V_29 & V_78 ) &&
( ! ( V_3 -> V_29 & V_114 ) ) ) {
V_511 = F_80 ( 1 , V_3 ) ;
for ( V_73 = 0xC0 , V_136 = 0 ; V_73 < 0xFF ; V_73 ++ , V_136 ++ )
F_4 ( V_3 -> V_396 ,
V_73 ,
V_511 -> V_350 [ V_136 ] ) ;
}
if ( ( V_3 -> V_29 & V_78 ) &&
( ! ( V_3 -> V_29 & V_114 ) ) )
F_12 ( V_3 -> V_396 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_12 ( V_3 -> V_396 , 0x4E , ~ 0x14 , 0x10 ) ;
}
static void F_82 ( unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_73 ;
unsigned char const * V_226 ;
unsigned short V_74 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
F_4 ( V_3 -> V_517 , 0x00 , 0x00 ) ;
if ( V_3 -> V_30 & V_126 ) {
F_4 ( V_3 -> V_517 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_517 , 0x14 , 0xC8 ) ;
} else {
F_4 ( V_3 -> V_517 , 0x13 , 0xF5 ) ;
F_4 ( V_3 -> V_517 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_29 & V_78 ) )
return;
if ( V_3 -> V_30 & V_427 ) {
F_4 ( V_3 -> V_517 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_517 , 0x14 , 0xC8 ) ;
F_4 ( V_3 -> V_517 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_29 & V_114 ) || ( V_3 -> V_29
& V_121 ) ) {
if ( V_3 -> V_30 & V_431 )
return;
V_226 = V_518 ;
if ( V_3 -> V_116 & V_117 ) {
V_226 = V_519 ;
if ( ! ( V_74 & V_88 ) )
V_226 = V_520 ;
}
if ( V_3 -> V_30 & V_385 )
V_226 = V_521 ;
if ( V_3 -> V_30 & V_383 )
V_226 = V_522 ;
for ( V_73 = 0 ; V_73 <= 0x3E ; V_73 ++ )
F_4 ( V_3 -> V_517 , V_73 , V_226 [ V_73 ] ) ;
if ( V_3 -> V_55 & V_108 ) {
if ( V_3 -> V_30 & V_385 )
F_4 ( V_3 -> V_517 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_83 ( unsigned short V_69 , unsigned short V_70 ,
unsigned short V_98 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_99 , V_162 , V_100 , V_74 , V_64 , V_169 ;
unsigned long V_497 , V_496 , V_523 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_64 = V_3 -> V_461 ;
F_4 ( V_3 -> V_373 , 0x13 , V_64 ) ;
V_100 = V_3 -> V_460 ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_373 , 0x14 , V_64 ) ;
V_169 = ( ( V_100 & 0xFF00 ) >> 8 ) << 7 ;
V_162 = V_3 -> V_337 - 1 ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_373 , 0x16 , V_64 ) ;
V_64 = ( ( V_162 & 0xFF00 ) >> 8 ) << 3 ;
V_169 |= V_64 ;
V_162 = V_3 -> V_338 - 1 ;
if ( ! ( V_3 -> V_29 & V_78 ) )
V_162 -= 5 ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_373 , 0x17 , V_64 ) ;
V_64 = V_169 | ( ( V_162 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_373 , 0x15 , V_64 ) ;
F_20 ( V_3 -> V_373 , 0x0D , 0x08 ) ;
V_162 = V_3 -> V_29 ;
V_100 = V_3 -> V_218 ;
if ( V_74 & V_165 )
V_100 = V_100 >> 1 ;
if ( F_66 ( V_3 ) )
V_100 = V_100 >> 1 ;
if ( V_162 & V_114 ) {
V_64 = 0 ;
if ( V_100 <= 1024 )
V_64 = 0xA0 ;
if ( V_100 == 1280 )
V_64 = 0xC0 ;
} else if ( V_162 & V_78 ) {
V_64 = 0xA0 ;
if ( V_100 <= 800 )
V_64 = 0x80 ;
} else {
V_64 = 0x80 ;
if ( V_3 -> V_29 & V_79 ) {
V_64 = 0 ;
if ( V_100 > 800 )
V_64 = 0x60 ;
}
}
if ( V_3 -> V_30 & ( V_385 | V_383 ) ) {
V_64 = 0x00 ;
if ( V_3 -> V_218 == 1280 )
V_64 = 0x40 ;
if ( V_3 -> V_218 == 1024 )
V_64 = 0x20 ;
}
F_12 ( V_3 -> V_373 , 0x0E , ~ 0xEF , V_64 ) ;
V_497 = V_3 -> V_221 ;
if ( V_162 & V_114 ) {
if ( ! ( V_64 & 0xE000 ) )
V_100 = V_100 >> 1 ;
}
V_162 = V_3 -> V_464 ;
V_64 = V_162 & 0x00FF ;
F_4 ( V_3 -> V_373 , 0x18 , V_64 ) ;
V_496 = V_3 -> V_220 ;
V_162 |= 0x04000 ;
if ( V_496 <= V_497 ) {
V_162 = ( V_162 & ( ~ 0x4000 ) ) ;
V_496 = V_3 -> V_220 ;
} else {
V_496 -= V_497 ;
}
V_523 = ( V_496 * 256 * 1024 ) % V_497 ;
V_496 = ( V_496 * 256 * 1024 ) / V_497 ;
V_497 = V_496 ;
if ( V_523 != 0 )
V_497 ++ ;
V_64 = ( unsigned short ) ( V_497 & 0x000000FF ) ;
F_4 ( V_3 -> V_373 , 0x1B , V_64 ) ;
V_64 = ( unsigned short ) ( ( V_497 & 0x0000FF00 ) >> 8 ) ;
F_4 ( V_3 -> V_373 , 0x1A , V_64 ) ;
V_100 = ( unsigned short ) ( V_497 >> 16 ) ;
V_64 = V_100 & 0x00FF ;
V_64 = V_64 << 4 ;
V_64 |= ( ( V_162 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_373 , 0x19 , V_64 ) ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
V_64 = 0x0028 ;
F_4 ( V_3 -> V_373 , 0x1C , V_64 ) ;
V_99 = V_3 -> V_218 ;
if ( V_74 & V_165 )
V_99 = V_99 >> 1 ;
if ( F_66 ( V_3 ) )
V_99 = V_99 >> 1 ;
if ( V_3 -> V_29 & V_79 ) {
if ( V_99 > 800 )
V_99 -= 800 ;
} else if ( V_3 -> V_218 > 800 ) {
if ( V_3 -> V_218 == 1024 )
V_99 = ( V_99 * 25 / 32 ) - 1 ;
else
V_99 = ( V_99 * 20 / 32 ) - 1 ;
}
V_99 -= 1 ;
V_64 = ( V_99 & 0xFF00 ) >> 8 ;
V_64 = ( ( V_64 & 0x0003 ) << 4 ) ;
F_4 ( V_3 -> V_373 , 0x1E , V_64 ) ;
V_64 = ( V_99 & 0x00FF ) ;
F_4 ( V_3 -> V_373 , 0x1D , V_64 ) ;
if ( V_3 -> V_29 & ( V_78 | V_114 ) ) {
if ( V_3 -> V_218 > 800 )
F_20 ( V_3 -> V_373 , 0x1E , 0x08 ) ;
}
V_64 = 0x0036 ;
if ( V_3 -> V_29 & V_78 ) {
if ( ! ( V_3 -> V_30 & ( V_388
| V_385 | V_383
| V_434 ) ) ) {
V_64 |= 0x0001 ;
if ( ( V_3 -> V_29 & V_80 )
&& ( ! ( V_3 -> V_30
& V_117 ) ) )
V_64 &= ( ~ 0x0001 ) ;
}
}
F_12 ( V_3 -> V_373 , 0x1F , 0x00C0 , V_64 ) ;
V_100 = V_3 -> V_339 ;
if ( F_66 ( V_3 ) )
V_100 = V_100 >> 1 ;
V_100 = ( V_100 >> 1 ) - 2 ;
V_64 = ( ( V_100 & 0x0700 ) >> 8 ) << 3 ;
F_12 ( V_3 -> V_373 , 0x21 , 0x00C0 , V_64 ) ;
V_64 = V_100 & 0x00FF ;
F_4 ( V_3 -> V_373 , 0x22 , V_64 ) ;
}
F_69 ( V_69 , V_70 , V_98 , V_3 ) ;
}
static void F_84 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_68 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_85 ( unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_524 , V_525 ;
V_524 = V_3 -> V_526 ;
V_525 = V_3 -> V_526 + 1 ;
if ( V_3 -> V_94 == V_95 ) {
if ( ! ( V_3 -> V_29 & ( V_80 | V_527
| V_412 ) ) ) {
F_84 ( V_3 ) ;
}
}
return;
}
static void F_86 ( struct V_81 * V_82 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_84 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_87 ( struct V_81 * V_82 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_84 , 0x63 , 0xBF , 0x00 ) ;
}
static unsigned char F_88 ( struct V_452 * V_453 ,
unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_199 , V_217 , V_487 , V_74 , V_161 ;
V_161 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_199 = V_3 -> V_24 [ V_161 ] . V_163 ;
V_217 = V_3 -> V_24 [ V_161 ] . V_164 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
if ( ! ( V_74 & V_88 ) ) {
V_199 /= 9 ;
V_199 *= 8 ;
}
if ( ( V_69 > 0x13 ) && ( V_74 & V_165 ) )
V_199 *= 2 ;
if ( ( V_69 > 0x13 ) && ( V_74 & V_138 ) )
V_217 *= 2 ;
if ( V_199 > V_453 -> V_455 . V_528 )
return 0 ;
if ( V_217 > V_453 -> V_455 . V_529 )
return 0 ;
if ( V_199 != V_453 -> V_455 . V_528 ||
V_217 != V_453 -> V_455 . V_529 ) {
V_487 = F_70 ( V_69 , V_70 , V_3 ) ;
if ( V_487 > 2 )
return 0 ;
}
return 1 ;
}
static void F_89 ( struct V_452 * V_453 ,
int V_150 ,
unsigned short V_69 ,
unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned char V_64 , V_530 ;
unsigned short V_199 , V_217 , V_74 , V_161 ;
unsigned short V_531 , V_532 , V_533 , V_534 , V_535 ;
unsigned short V_536 , V_537 , V_538 , V_539 , V_540 ;
unsigned short V_541 ;
V_64 = ( unsigned char ) ( ( V_453 -> V_455 . V_542 &
( V_543 << 8 ) ) >> 8 ) ;
V_64 &= V_543 ;
V_530 = ( unsigned char ) F_7 ( V_3 -> V_154 ) ;
F_8 ( ( V_530 & 0x3F ) | V_64 , V_3 -> V_132 ) ;
V_64 = V_453 -> V_455 . V_542 & V_543 ;
F_12 ( V_3 -> V_68 , 0x35 , ~ 0x80 , V_64 & 0x80 ) ;
F_12 ( V_3 -> V_68 , 0x30 , ~ 0x20 , ( V_64 & 0x40 ) >> 1 ) ;
if ( V_150 == V_63 )
F_22 ( V_3 ) ;
else
F_29 ( V_3 ) ;
V_161 = V_3 -> V_6 [ V_70 ] . V_103 ;
V_199 = V_3 -> V_24 [ V_161 ] . V_163 ;
V_217 = V_3 -> V_24 [ V_161 ] . V_164 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
if ( ! ( V_74 & V_88 ) )
V_199 = V_199 * 8 / 9 ;
V_531 = V_453 -> V_455 . V_531 ;
V_532 = V_199 + ( V_453 -> V_455 . V_528 - V_199 ) / 2 ;
if ( V_532 > V_531 )
V_532 -= V_531 ;
V_533 = V_532 + V_453 -> V_455 . V_544 ;
if ( V_533 > V_531 )
V_533 -= V_531 ;
V_534 = V_533 + V_453 -> V_455 . V_545 ;
if ( V_534 > V_531 )
V_534 -= V_531 ;
V_535 = V_532 + V_531 - V_453 -> V_455 . V_528 ;
V_536 = V_453 -> V_455 . V_536 ;
V_537 = V_217 + ( V_453 -> V_455 . V_529 - V_217 ) / 2 ;
if ( V_74 & V_138 )
V_537 += V_217 / 2 ;
if ( V_537 > V_536 )
V_537 -= V_536 ;
V_538 = V_537 + V_453 -> V_455 . V_546 ;
if ( V_538 > V_536 )
V_538 -= V_536 ;
V_539 = V_538 + V_453 -> V_455 . V_547 ;
if ( V_539 > V_536 )
V_539 -= V_536 ;
V_540 = V_537 + V_536 - V_453 -> V_455 . V_529 ;
V_64 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x11 ) ;
F_4 ( V_3 -> V_84 , 0x11 , V_64 & 0x7f ) ;
if ( ! ( V_74 & V_88 ) )
F_20 ( V_3 -> V_68 , 0x1 , 0x1 ) ;
V_541 = ( V_531 >> 3 ) - 5 ;
F_12 ( V_3 -> V_68 , 0x0B , ~ 0x03 , ( V_541 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_84 , 0x0 , ( V_541 & 0xFF ) ) ;
V_541 = ( V_532 >> 3 ) - 1 ;
F_12 ( V_3 -> V_68 , 0x0B , ~ 0x30 , ( V_541 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_84 , 0x2 , ( V_541 & 0xFF ) ) ;
V_541 = ( V_535 >> 3 ) - 1 ;
F_12 ( V_3 -> V_68 , 0x0C , ~ 0x03 , ( V_541 & 0xC0 ) >> 6 ) ;
F_12 ( V_3 -> V_84 , 0x05 , ~ 0x80 , ( V_541 & 0x20 ) << 2 ) ;
F_12 ( V_3 -> V_84 , 0x03 , ~ 0x1F , V_541 & 0x1F ) ;
V_541 = ( V_533 >> 3 ) + 2 ;
F_12 ( V_3 -> V_68 , 0x0B , ~ 0xC0 , ( V_541 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_84 , 0x4 , ( V_541 & 0xFF ) ) ;
V_541 -- ;
F_12 ( V_3 -> V_68 , 0x2F , ~ 0x03 , ( V_541 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_68 , 0x2E , ( V_541 & 0xFF ) ) ;
V_541 = ( V_534 >> 3 ) + 2 ;
F_12 ( V_3 -> V_68 , 0x0C , ~ 0x04 , ( V_541 & 0x20 ) >> 3 ) ;
F_12 ( V_3 -> V_84 , 0x05 , ~ 0x1F , V_541 & 0x1F ) ;
V_541 -- ;
F_12 ( V_3 -> V_68 , 0x2F , ~ 0xFC , V_541 << 2 ) ;
V_541 = V_536 - 2 ;
F_12 ( V_3 -> V_68 , 0x0A , ~ 0x01 , ( V_541 & 0x400 ) >> 10 ) ;
F_12 ( V_3 -> V_84 , 0x07 , ~ 0x20 , ( V_541 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_84 , 0x07 , ~ 0x01 , ( V_541 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_84 , 0x06 , ( V_541 & 0xFF ) ) ;
V_541 = V_537 - 1 ;
F_12 ( V_3 -> V_68 , 0x0A , ~ 0x04 , ( V_541 & 0x400 ) >> 8 ) ;
F_12 ( V_3 -> V_84 , 0x09 , ~ 0x20 , ( V_541 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_84 , 0x07 , ~ 0x08 , ( V_541 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_84 , 0x15 , ( V_541 & 0xFF ) ) ;
V_541 = V_540 - 1 ;
F_12 ( V_3 -> V_68 , 0x0A , ~ 0x10 , ( V_541 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_84 , 0x16 , ( V_541 & 0xFF ) ) ;
V_541 = V_538 - 1 ;
F_12 ( V_3 -> V_68 , 0x0A , ~ 0x08 , ( V_541 & 0x400 ) >> 7 ) ;
F_12 ( V_3 -> V_84 , 0x07 , ~ 0x80 , ( V_541 & 0x200 ) >> 2 ) ;
F_12 ( V_3 -> V_84 , 0x07 , ~ 0x04 , ( V_541 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_84 , 0x10 , ( V_541 & 0xFF ) ) ;
if ( V_150 == V_63 ) {
F_12 ( V_3 -> V_68 , 0x35 , ~ 0x07 ,
( V_541 & 0x700 ) >> 8 ) ;
F_4 ( V_3 -> V_68 , 0x34 , V_541 & 0xFF ) ;
} else {
F_12 ( V_3 -> V_68 , 0x3F , ~ 0x03 ,
( V_541 & 0x600 ) >> 9 ) ;
F_4 ( V_3 -> V_68 , 0x34 , ( V_541 >> 1 ) & 0xFF ) ;
F_12 ( V_3 -> V_84 , 0x33 , ~ 0x01 , V_541 & 0x01 ) ;
}
V_541 = V_539 - 1 ;
F_12 ( V_3 -> V_68 , 0x0A , ~ 0x20 , ( V_541 & 0x10 ) << 1 ) ;
F_12 ( V_3 -> V_84 , 0x11 , ~ 0x0F , V_541 & 0x0F ) ;
if ( V_150 == V_63 )
F_12 ( V_3 -> V_68 , 0x3F , ~ 0xFC ,
( V_541 << 2 ) & 0xFC ) ;
else
F_12 ( V_3 -> V_68 , 0x3F , ~ 0xFC ,
( V_541 << 2 ) & 0x7C ) ;
for ( V_64 = 0 , V_541 = 0 ; V_64 < 3 ; V_64 ++ ) {
F_12 ( V_3 -> V_68 , 0x31 , ~ 0x30 , V_541 ) ;
F_4 ( V_3 -> V_68 ,
0x2B , V_453 -> V_455 . V_548 ) ;
F_4 ( V_3 -> V_68 ,
0x2C , V_453 -> V_455 . V_549 ) ;
V_541 += 0x10 ;
}
if ( ! ( V_74 & V_88 ) ) {
F_7 ( V_3 -> V_89 ) ;
F_8 ( 0x13 , V_3 -> V_90 ) ;
F_8 ( 0x00 , V_3 -> V_90 ) ;
F_7 ( V_3 -> V_89 ) ;
F_8 ( 0x20 , V_3 -> V_90 ) ;
F_7 ( V_3 -> V_89 ) ;
}
}
static unsigned char F_90 ( struct V_2 * V_3 )
{
unsigned short V_99 ;
V_99 = V_3 -> V_29 ;
if ( V_99 & V_411 )
return 0 ;
else if ( V_99 & ( V_412 | V_421 | V_420 ) )
return 1 ;
return 0 ;
}
static unsigned char F_91 ( struct V_2 * V_3 )
{
unsigned short V_100 , V_71 ;
V_100 = V_3 -> V_116 & ( V_550 | V_551 ) ;
V_71 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_366 , 0x2E ) ) ;
if ( V_100 & ( V_552 | V_550 ) ) {
if ( ! ( V_71 & 0x08 ) )
return 0 ;
}
if ( ! ( V_100 & ( V_553 | V_551 ) ) )
return 0 ;
if ( V_71 & 0x01 )
return 1 ;
return 0 ;
}
static unsigned char F_92 ( struct V_2 * V_3 )
{
unsigned short V_100 , V_71 ;
V_100 = V_3 -> V_116 & ( V_552 | V_553 ) ;
V_71 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_366 , 0x2E ) ) ;
if ( V_100 & ( V_552 | V_550 ) ) {
if ( ! ( V_71 & 0x08 ) )
return 0 ;
}
if ( ! ( V_100 & ( V_553 | V_551 ) ) )
return 0 ;
if ( V_71 & 0x01 )
return 1 ;
return 0 ;
}
static void F_93 ( struct V_452 * V_453 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_71 = 0 ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
V_71 = 0x3F ;
if ( ! ( V_3 -> V_29 &
( V_412 | V_420 ) ) ) {
if ( V_3 -> V_29 & V_77 ) {
if ( V_3 -> V_29 & V_411 ) {
V_71 = 0x7F ;
if ( ! ( V_3 -> V_29 &
V_77 ) )
V_71 = 0xBF ;
if ( V_3 -> V_116 & V_551 )
V_71 &= 0xBF ;
if ( V_3 -> V_116 & V_550 )
V_71 &= 0x7F ;
}
}
}
F_13 ( V_3 -> V_373 , 0x1F , V_71 ) ;
if ( V_3 -> V_55 & ( V_57 | V_108 ) ) {
if ( ( ( V_3 -> V_29 &
( V_79 | V_77 ) ) )
|| ( F_91 ( V_3 ) )
|| ( F_90 ( V_3 ) ) )
F_20 ( V_3 -> V_373 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_116 & V_550 ) || ( V_3 -> V_29
& ( V_412 | V_77
| V_420 ) ) ) {
if ( V_3 -> V_116 & V_554 )
F_86 ( V_82 , V_3 ) ;
F_61 ( V_453 , V_82 , V_3 ) ;
}
if ( V_3 -> V_29 & V_77 ) {
if ( ( V_3 -> V_116 & V_550 ) || ( V_3 -> V_29
& V_77 ) )
F_13 ( V_3 -> V_366 , 0x1e , 0xdf ) ;
}
F_13 ( V_3 -> V_68 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_29 & ( V_420 | V_411 ) ) )
F_13 ( V_3 -> V_396 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_116 & V_551 ) ||
( V_3 -> V_29 &
( V_412 | V_420 ) ) ||
( ( ! ( V_3 -> V_29 & V_77 ) ) &&
( V_3 -> V_29 &
( V_106 | V_79 | V_78 ) ) ) )
F_20 ( V_3 -> V_366 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_116 & V_551 ) ||
( V_3 -> V_29 &
( V_412 | V_420 ) ) ||
( ! ( V_3 -> V_29 & V_77 ) ) ||
( V_3 -> V_29 &
( V_106 | V_79 | V_78 ) ) ) {
V_71 = F_2 ( V_3 -> V_366 , 0x00 ) ;
F_20 ( V_3 -> V_366 , 0x00 , 0x10 ) ;
F_13 ( V_3 -> V_366 , 0x1E , 0xDF ) ;
F_4 ( V_3 -> V_366 , 0x00 , V_71 ) ;
}
} else {
if ( V_3 -> V_29 & ( V_79 | V_78 ) ) {
F_20 ( V_3 -> V_366 , 0x00 , 0x80 ) ;
F_13 ( V_3 -> V_366 , 0x1E , 0xDF ) ;
F_13 ( V_3 -> V_68 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_29 & ( V_412 | V_77
| V_420 ) )
F_61 ( V_453 , V_82 , V_3 ) ;
}
}
static unsigned short F_94 ( struct V_2 * V_3 )
{
unsigned short V_100 = 0 ;
if ( V_3 -> V_30 & V_126 )
V_100 = 2 ;
if ( V_3 -> V_30 & V_434 )
V_100 = 4 ;
if ( V_3 -> V_30 & V_431 )
V_100 = 6 ;
if ( V_3 -> V_30 & V_385 )
V_100 = 8 ;
if ( V_3 -> V_30 & V_383 )
V_100 = 10 ;
if ( V_3 -> V_30 & V_117 )
V_100 ++ ;
return V_100 ;
}
static void F_95 ( unsigned short * V_100 , unsigned char * V_391 ,
unsigned char * V_392 , struct V_2 * V_3 )
{
* V_100 = 0 ;
* V_391 = 0 ;
* V_392 = 0 ;
if ( V_3 -> V_30 & V_126 )
* V_100 = 1 ;
if ( V_3 -> V_30 & V_427 )
* V_100 = 2 ;
if ( V_3 -> V_30 & V_428 )
* V_100 = 3 ;
if ( V_3 -> V_30 & V_388 ) {
* V_100 = 4 ;
if ( V_3 -> V_30 & V_427 )
* V_100 = 5 ;
}
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
if ( ( ! ( V_3 -> V_29 & V_80 ) ) || ( V_3 -> V_30
& V_117 ) ) {
* V_100 += 8 ;
* V_391 += 1 ;
}
}
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) )
( * V_392 ) ++ ;
}
static void F_96 ( struct V_2 * V_3 )
{
unsigned char V_71 , V_351 , V_449 ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
if ( V_3 -> V_29 & ( V_79 | V_77
| V_78 | V_106 ) ) {
V_449 = 0 ;
V_351 = V_555 ;
if ( V_3 -> V_29 & V_411 )
V_351 = V_351 >> 4 ;
if ( V_3 -> V_29 &
( V_79 | V_77 ) ) {
V_449 = V_556 ;
if ( ! ( V_3 -> V_29 & V_77 ) )
V_351 = V_449 ;
}
V_351 &= 0x0F ;
V_449 &= 0xF0 ;
V_71 = F_2 ( V_3 -> V_366 , 0x2D ) ;
if ( V_3 -> V_29 & ( V_106 | V_79
| V_78 ) ) {
V_71 &= 0xF0 ;
V_71 |= V_351 ;
}
if ( V_3 -> V_29 & V_77 ) {
V_71 &= 0x0F ;
V_71 |= V_449 ;
}
F_4 ( V_3 -> V_366 , 0x2D , V_71 ) ;
}
} else if ( V_3 -> V_105 == 1 ) {
V_351 = 0 ;
V_449 = 0 ;
if ( V_3 -> V_29 & V_79 ) {
V_71 = V_556 ;
V_71 &= 0x0f ;
V_71 = V_71 << 4 ;
F_12 ( V_3 -> V_366 , 0x2D , 0x0f ,
V_71 ) ;
}
}
}
static void F_97 ( unsigned short V_162 ,
struct V_2 * V_3 )
{
unsigned short V_64 ;
V_64 = F_2 ( V_3 -> V_84 , 0x37 ) ;
if ( V_64 & V_492 ) {
F_12 ( V_3 -> V_366 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_162 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_366 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_12 ( V_3 -> V_366 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_162 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_366 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_98 ( unsigned short V_162 ,
struct V_2 * V_3 )
{
if ( V_162 & V_557 )
F_12 ( V_3 -> V_396 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_162 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_12 ( V_3 -> V_396 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_162 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
unsigned short V_73 ;
V_73 = F_2 ( V_3 -> V_68 , 0x1F ) ;
if ( ! ( V_73 & 0xC0 ) ) {
for ( V_73 = 0 ; V_73 < 0xFFFF ; V_73 ++ ) {
if ( ! ( F_7 ( V_3 -> V_89 ) & 0x08 ) )
break;
}
for ( V_73 = 0 ; V_73 < 0xFFFF ; V_73 ++ ) {
if ( ( F_7 ( V_3 -> V_89 ) & 0x08 ) )
break;
}
}
}
static void F_100 ( struct V_2 * V_3 )
{
unsigned short V_139 ;
V_139 = F_40 ( V_3 ) ;
F_13 ( V_3 -> V_373 , 0x30 , 0x8F ) ;
F_99 ( V_3 ) ;
F_20 ( V_3 -> V_373 , 0x30 , 0x20 ) ;
F_99 ( V_3 ) ;
F_4 ( V_3 -> V_373 , 0x31 ,
V_3 -> V_58 [ V_139 ] . V_558 ) ;
F_4 ( V_3 -> V_373 , 0x32 ,
V_3 -> V_58 [ V_139 ] . V_559 ) ;
F_4 ( V_3 -> V_373 , 0x33 ,
V_3 -> V_58 [ V_139 ] . V_560 ) ;
F_4 ( V_3 -> V_373 , 0x34 ,
V_3 -> V_58 [ V_139 ] . V_561 ) ;
F_99 ( V_3 ) ;
F_20 ( V_3 -> V_373 , 0x30 , 0x40 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
unsigned short V_162 ;
V_162 = V_3 -> V_58 [ F_40 ( V_3 ) ] . V_440 ;
if ( V_3 -> V_55 &
( V_123 |
V_124 |
V_56 |
V_57 |
V_108 ) ) {
if ( V_3 -> V_55 &
( V_56 | V_57 | V_108 ) ) {
F_4 ( V_3 -> V_373 , 0x24 ,
( unsigned char ) ( V_162 & 0x1F ) ) ;
}
F_12 ( V_3 -> V_373 , 0x0D ,
~ ( ( V_562 | V_563 ) >> 8 ) ,
( unsigned short ) ( ( V_162 & ( V_562
| V_563 ) ) >> 8 ) ) ;
}
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
if ( V_3 -> V_29 & V_79 )
F_98 ( V_162 , V_3 ) ;
else if ( V_3 -> V_29 & V_77 )
F_97 ( V_162 , V_3 ) ;
if ( V_3 -> V_55 & ( V_57 | V_108 ) ) {
if ( V_162 & V_564 )
F_100 ( V_3 ) ;
}
} else {
F_97 ( V_162 , V_3 ) ;
}
}
static void F_102 ( unsigned short V_69 ,
unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_100 ;
unsigned char V_71 ;
if ( V_3 -> V_30 & ( V_385 | V_383 ) )
return;
V_100 = F_94 ( V_3 ) ;
V_100 &= 0xFE ;
V_71 = V_565 [ V_100 ] ;
V_71 = V_71 << 4 ;
F_12 ( V_3 -> V_396 , 0x0A , 0x8F , V_71 ) ;
}
static void F_103 ( unsigned short V_69 ,
unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_100 ;
unsigned char V_71 ;
V_100 = F_94 ( V_3 ) ;
V_100 &= 0xFE ;
V_71 = V_566 [ V_100 ] ;
V_71 = V_71 << 5 ;
F_12 ( V_3 -> V_396 , 0x3A , 0x1F , V_71 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
unsigned short V_100 ;
unsigned char V_391 , V_392 ;
unsigned long V_567 ;
F_95 ( & V_100 , & V_391 , & V_392 , V_3 ) ;
V_567 = V_568 [ V_100 ] ;
F_4 ( V_3 -> V_396 , 0x31 , ( unsigned short ) ( V_567
& 0x000000FF ) ) ;
F_4 ( V_3 -> V_396 , 0x32 , ( unsigned short ) ( ( V_567
& 0x0000FF00 ) >> 8 ) ) ;
F_4 ( V_3 -> V_396 , 0x33 , ( unsigned short ) ( ( V_567
& 0x00FF0000 ) >> 16 ) ) ;
F_4 ( V_3 -> V_396 , 0x34 , ( unsigned short ) ( ( V_567
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_105 ( unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_100 , V_139 ;
unsigned char V_391 , V_392 , V_224 , * V_569 ;
F_95 ( & V_100 , & V_391 , & V_392 , V_3 ) ;
switch ( V_100 ) {
case 0x00 :
case 0x04 :
V_569 = V_570 ;
break;
case 0x01 :
V_569 = V_571 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
case 0x03 :
V_569 = V_572 ;
break;
case 0x08 :
case 0x0C :
case 0x0A :
case 0x0B :
case 0x09 :
V_569 = V_573 ;
break;
default:
return;
}
V_224 = V_3 -> V_6 [ V_70 ] . V_574 ;
if ( V_391 == 0 )
V_139 = V_224 * 4 ;
else
V_139 = V_224 * 7 ;
if ( ( V_391 == 0 ) && ( V_392 == 1 ) ) {
F_4 ( V_3 -> V_396 , 0x35 , 0 ) ;
F_4 ( V_3 -> V_396 , 0x36 , 0 ) ;
F_4 ( V_3 -> V_396 , 0x37 , 0 ) ;
F_4 ( V_3 -> V_396 , 0x38 , V_569 [ V_139 ++ ] ) ;
} else {
F_4 ( V_3 -> V_396 , 0x35 , V_569 [ V_139 ++ ] ) ;
F_4 ( V_3 -> V_396 , 0x36 , V_569 [ V_139 ++ ] ) ;
F_4 ( V_3 -> V_396 , 0x37 , V_569 [ V_139 ++ ] ) ;
F_4 ( V_3 -> V_396 , 0x38 , V_569 [ V_139 ++ ] ) ;
}
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
F_4 ( V_3 -> V_396 , 0x48 , V_569 [ V_139 ++ ] ) ;
F_4 ( V_3 -> V_396 , 0x49 , V_569 [ V_139 ++ ] ) ;
F_4 ( V_3 -> V_396 , 0x4A , V_569 [ V_139 ++ ] ) ;
}
}
static void F_106 ( unsigned short V_69 ,
unsigned short V_70 ,
struct V_2 * V_3 )
{
F_96 ( V_3 ) ;
if ( V_3 -> V_29 & ( V_79 | V_77 ) )
F_101 ( V_3 ) ;
if ( V_3 -> V_29 & V_78 ) {
F_104 ( V_3 ) ;
F_105 ( V_69 , V_70 , V_3 ) ;
F_102 ( V_69 , V_70 , V_3 ) ;
if ( V_3 -> V_55 & V_390 )
F_103 ( V_69 , V_70 , V_3 ) ;
}
}
static void F_107 ( unsigned short V_69 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_351 ;
short V_391 ;
unsigned char V_71 ;
V_71 = 0 ;
if ( ! ( V_3 -> V_29 & V_412 ) ) {
V_71 = F_2 ( V_3 -> V_366 , 0x00 ) ;
V_71 &= ~ 0x10 ;
V_71 |= 0x40 ;
if ( V_3 -> V_29 & ( V_106 | V_78
| V_79 ) ) {
V_71 = 0x40 ;
V_391 = V_3 -> V_94 ;
V_391 -= V_95 ;
if ( V_391 >= 0 ) {
V_71 = ( 0x008 >> V_391 ) ;
if ( V_71 == 0 )
V_71 = 1 ;
V_71 |= 0x040 ;
}
if ( V_3 -> V_29 & V_80 )
V_71 ^= 0x50 ;
}
}
F_4 ( V_3 -> V_366 , 0x00 , V_71 ) ;
V_71 = 0x08 ;
V_351 = 0xf0 ;
if ( V_3 -> V_29 & V_412 )
goto V_575;
V_71 = 0x00 ;
V_351 = 0xff ;
if ( ! ( V_3 -> V_29 & ( V_106 | V_78 |
V_79 | V_77 ) ) )
goto V_575;
if ( ( V_3 -> V_29 & V_77 ) &&
( ! ( V_3 -> V_29 & V_420 ) ) ) {
V_351 &= 0xf7 ;
V_71 |= 0x01 ;
goto V_575;
}
if ( V_3 -> V_29 & V_77 ) {
V_351 &= 0xf7 ;
V_71 |= 0x01 ;
}
if ( ! ( V_3 -> V_29 & ( V_106 | V_78 | V_79 ) ) )
goto V_575;
V_351 &= 0xf8 ;
V_71 = 0x01 ;
if ( ! ( V_3 -> V_29 & V_80 ) )
V_71 |= 0x02 ;
if ( ! ( V_3 -> V_29 & V_106 ) ) {
V_71 = V_71 ^ 0x05 ;
if ( ! ( V_3 -> V_29 & V_79 ) )
V_71 = V_71 ^ 0x01 ;
}
if ( ! ( V_3 -> V_29 & V_411 ) )
V_71 |= 0x08 ;
V_575:
F_12 ( V_3 -> V_366 , 0x2e , V_351 , V_71 ) ;
if ( V_3 -> V_29 & ( V_106 | V_78 | V_79
| V_77 ) ) {
V_71 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_94 == V_95 ) && ( ! ( V_3 -> V_29
& V_80 ) ) ) {
V_71 |= 0x010 ;
}
V_71 |= 0x080 ;
if ( V_3 -> V_29 & V_78 ) {
V_71 |= 0x020 ;
if ( V_3 -> V_29 & V_423 )
V_71 = V_71 ^ 0x20 ;
}
F_12 ( V_3 -> V_373 , 0x0D , ~ 0x0BF , V_71 ) ;
V_71 = 0 ;
if ( V_3 -> V_28 & V_442 )
V_71 |= 0x40 ;
if ( V_3 -> V_29 & V_78 ) {
if ( V_3 -> V_30 & V_178 )
V_71 |= 0x40 ;
}
if ( ( V_3 -> V_26 == V_111 )
|| ( V_3 -> V_26 == V_345 ) )
V_71 |= 0x80 ;
if ( V_3 -> V_26 == V_112 )
V_71 |= 0x80 ;
F_4 ( V_3 -> V_373 , 0x0C , V_71 ) ;
}
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
V_71 = 0 ;
V_351 = 0xfb ;
if ( V_3 -> V_29 & V_411 ) {
V_351 = 0xff ;
if ( V_3 -> V_29 & V_77 )
V_71 |= 0x04 ;
}
F_12 ( V_3 -> V_366 , 0x13 , V_351 , V_71 ) ;
V_71 = 0x00 ;
V_351 = 0xcf ;
if ( ! ( V_3 -> V_29 & V_412 ) ) {
if ( V_3 -> V_29 & V_411 )
V_71 |= 0x30 ;
}
F_12 ( V_3 -> V_366 , 0x2c , V_351 , V_71 ) ;
V_71 = 0 ;
V_351 = 0x3f ;
if ( ! ( V_3 -> V_29 & V_412 ) ) {
if ( V_3 -> V_29 & V_411 )
V_71 |= 0xc0 ;
}
F_12 ( V_3 -> V_373 , 0x21 , V_351 , V_71 ) ;
}
V_71 = 0 ;
V_351 = 0x7f ;
if ( ! ( V_3 -> V_29 & V_77 ) ) {
V_351 = 0xff ;
if ( ! ( V_3 -> V_29 & V_411 ) )
V_71 |= 0x80 ;
}
F_12 ( V_3 -> V_373 , 0x23 , V_351 , V_71 ) ;
if ( V_3 -> V_55 & ( V_57 | V_108 ) ) {
if ( V_3 -> V_28 & V_442 ) {
F_20 ( V_3 -> V_373 , 0x27 , 0x20 ) ;
F_20 ( V_3 -> V_373 , 0x34 , 0x10 ) ;
}
}
}
void F_108 ( struct V_81 * V_82 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_366 , 0x2f , 0xFF , 0x01 ) ;
}
void F_109 ( struct V_81 * V_82 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_366 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_110 ( struct V_2 * V_3 )
{
unsigned short V_405 ;
if ( V_3 -> V_105 == 1 ) {
return 1 ;
} else {
V_405 = F_2 ( V_3 -> V_373 , 0x00 ) ;
if ( ( V_405 == 1 ) || ( V_405 == 2 ) )
return 1 ;
else
return 0 ;
}
}
unsigned short F_111 ( struct V_81 * V_454 ,
unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
short V_576 [] = { 0x00 , 0x00 , 0x03 , 0x01 } ,
V_577 [] = { 0x00 , 0x00 , 0x03 , 0x01 , 0x01 ,
0x01 , 0x01 } ;
unsigned short V_98 , V_73 , V_74 , V_139 , V_64 ;
V_74 = V_3 -> V_6 [ V_70 ] . V_75 ;
V_139 = F_2 ( V_3 -> V_84 , 0x33 ) ;
V_139 = V_139 >> V_3 -> V_578 ;
V_139 &= 0x0F ;
if ( V_3 -> V_28 & V_113 )
V_139 = 0 ;
if ( V_139 > 0 )
V_139 -- ;
if ( V_3 -> V_116 & V_380 ) {
if ( V_3 -> V_29 & ( V_79 | V_77 ) ) {
if ( V_3 -> V_105 == 0 ) {
if ( V_3 -> V_55 & ( V_123 | V_124
| V_56 | V_57
| V_108 ) )
V_64 = V_577 [
V_3 -> V_26 & 0x0F ] ;
else
V_64 = V_576 [
V_3 -> V_26 & 0x0F ] ;
if ( V_139 > V_64 )
V_139 = V_64 ;
} else {
V_139 = 0 ;
}
}
}
V_98 = V_3 -> V_6 [ V_70 ] . V_579 ;
V_69 = V_3 -> V_8 [ V_98 ] . V_104 ;
if ( V_454 -> V_137 >= V_61 ) {
if ( ( V_3 -> V_8 [ V_98 ] . V_580 == 800 ) &&
( V_3 -> V_8 [ V_98 ] . V_581 == 600 ) ) {
V_139 ++ ;
}
if ( ( V_3 -> V_8 [ V_98 ] . V_580 == 1024 ) &&
( V_3 -> V_8 [ V_98 ] . V_581 == 768 ) ) {
V_139 ++ ;
}
if ( ( V_3 -> V_8 [ V_98 ] . V_580 == 1280 ) &&
( V_3 -> V_8 [ V_98 ] . V_581 == 1024 ) ) {
V_139 ++ ;
}
}
V_73 = 0 ;
do {
if ( V_3 -> V_8 [ V_98 + V_73 ] .
V_104 != V_69 )
break;
V_64 = V_3 -> V_8 [ V_98 + V_73 ] .
V_130 ;
V_64 &= V_410 ;
if ( V_64 < V_3 -> V_94 )
break;
V_73 ++ ;
V_139 -- ;
} while ( V_139 != 0xFFFF );
if ( ! ( V_3 -> V_29 & V_106 ) ) {
if ( V_3 -> V_29 & V_80 ) {
V_64 = V_3 -> V_8 [ V_98 + V_73 - 1 ] .
V_130 ;
if ( V_64 & V_166 )
V_73 ++ ;
}
}
V_73 -- ;
if ( ( V_3 -> V_116 & V_380 ) ) {
V_64 = F_14 ( V_69 , V_70 ,
V_98 , & V_73 , V_3 ) ;
}
return V_98 + V_73 ;
}
static void F_112 ( unsigned short V_69 , unsigned short V_70 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_98 ;
V_3 -> V_116 |= V_380 ;
V_98 = F_111 ( V_82 , V_69 ,
V_70 , V_3 ) ;
F_35 ( V_69 , V_70 , V_3 ) ;
F_38 ( V_69 , V_70 , V_98 , V_3 ) ;
F_39 ( V_69 , V_70 , V_98 ,
V_82 , V_3 ) ;
F_43 ( V_69 , V_70 , V_98 , V_3 ) ;
F_47 ( V_69 , V_70 , V_98 , V_3 ) ;
}
static unsigned char F_113 ( unsigned short V_69 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_100 , V_70 , V_98 ;
V_100 = V_3 -> V_29 ;
V_3 -> V_116 |= V_380 ;
F_53 ( V_69 , & V_70 , V_3 ) ;
V_3 -> V_578 = 4 ;
V_98 = F_111 ( V_82 , V_69 ,
V_70 , V_3 ) ;
F_64 ( V_69 , V_3 ) ;
F_65 ( V_69 , V_70 , V_3 ) ;
F_68 ( V_69 , V_70 , V_98 , V_3 ) ;
F_74 ( V_69 , V_70 , V_82 ,
V_98 , V_3 ) ;
F_75 ( V_69 , V_70 , V_82 ,
V_98 , V_3 ) ;
F_77 ( V_69 , V_70 , V_82 ,
V_98 , V_3 ) ;
F_78 ( V_69 , V_70 , V_98 ,
V_82 , V_3 ) ;
F_79 ( V_69 , V_70 , V_82 ,
V_98 , V_3 ) ;
F_81 ( V_3 ) ;
F_82 ( V_69 , V_70 , V_3 ) ;
F_83 ( V_69 , V_70 , V_98 ,
V_82 , V_3 ) ;
F_69 ( V_69 , V_70 , V_98 , V_3 ) ;
F_85 ( V_69 , V_70 , V_3 ) ;
F_63 ( V_3 ) ;
return 1 ;
}
void F_114 ( struct V_2 * V_3 )
{
unsigned char V_582 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_583 = 0 , V_584 = 0 , V_585 = 0 , V_586 = 0 ;
unsigned char V_587 , V_588 , V_589 ;
unsigned short V_64 ;
unsigned char V_590 [ 3 ] = { 0x0F , 0x0F , 0x0F } ;
int V_73 ;
F_4 ( V_3 -> V_68 , 0x05 , 0x86 ) ;
F_4 ( V_3 -> V_84 , 0x57 , 0x4A ) ;
F_4 ( V_3 -> V_84 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_84 , 0x53 ) | 0x02 ) ) ;
V_589 = ( unsigned char ) F_2 ( V_3 -> V_68 , 0x31 ) ;
V_588 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x63 ) ;
V_583 = ( unsigned char ) F_2 ( V_3 -> V_68 , 0x01 ) ;
F_4 ( V_3 -> V_68 , 0x01 , ( unsigned char ) ( V_583 & 0xDF ) ) ;
F_4 ( V_3 -> V_84 , 0x63 , ( unsigned char ) ( V_588 & 0xBF ) ) ;
V_587 = ( unsigned char ) F_2 ( V_3 -> V_84 , 0x17 ) ;
F_4 ( V_3 -> V_84 , 0x17 , ( unsigned char ) ( V_587 | 0x80 ) ) ;
V_584 = ( unsigned char ) F_2 ( V_3 -> V_68 , 0x1F ) ;
F_4 ( V_3 -> V_68 , 0x1F , ( unsigned char ) ( V_584 | 0x04 ) ) ;
V_585 = ( unsigned char ) F_2 ( V_3 -> V_68 , 0x07 ) ;
F_4 ( V_3 -> V_68 , 0x07 , ( unsigned char ) ( V_585 & 0xFB ) ) ;
V_586 = ( unsigned char ) F_2 ( V_3 -> V_68 , 0x06 ) ;
F_4 ( V_3 -> V_68 , 0x06 , ( unsigned char ) ( V_586 & 0xC3 ) ) ;
F_4 ( V_3 -> V_84 , 0x11 , 0x00 ) ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ )
F_4 ( V_3 -> V_84 , ( unsigned short ) V_73 , V_582 [ V_73 ] ) ;
for ( V_73 = 8 ; V_73 < 11 ; V_73 ++ )
F_4 ( V_3 -> V_84 , ( unsigned short ) ( V_73 + 8 ) ,
V_582 [ V_73 ] ) ;
for ( V_73 = 11 ; V_73 < 13 ; V_73 ++ )
F_4 ( V_3 -> V_84 , ( unsigned short ) ( V_73 + 4 ) ,
V_582 [ V_73 ] ) ;
for ( V_73 = 13 ; V_73 < 16 ; V_73 ++ )
F_4 ( V_3 -> V_68 , ( unsigned short ) ( V_73 - 3 ) ,
V_582 [ V_73 ] ) ;
F_4 ( V_3 -> V_68 , 0x0E , ( unsigned char ) ( V_582 [ 16 ]
& 0xE0 ) ) ;
F_4 ( V_3 -> V_68 , 0x31 , 0x00 ) ;
F_4 ( V_3 -> V_68 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_68 , 0x2C , 0xE1 ) ;
F_8 ( 0x00 , V_3 -> V_216 ) ;
for ( V_73 = 0 ; V_73 < 256 ; V_73 ++ ) {
F_8 ( ( unsigned char ) V_590 [ 0 ] , ( V_3 -> V_216 + 1 ) ) ;
F_8 ( ( unsigned char ) V_590 [ 1 ] , ( V_3 -> V_216 + 1 ) ) ;
F_8 ( ( unsigned char ) V_590 [ 2 ] , ( V_3 -> V_216 + 1 ) ) ;
}
F_60 ( 1 ) ;
F_62 ( V_3 ) ;
V_64 = F_7 ( V_3 -> V_132 ) ;
if ( V_64 & 0x10 )
F_12 ( V_3 -> V_84 , 0x32 , 0xDF , 0x20 ) ;
else
F_12 ( V_3 -> V_84 , 0x32 , 0xDF , 0x00 ) ;
F_8 ( 0x00 , V_3 -> V_216 ) ;
for ( V_73 = 0 ; V_73 < 256 ; V_73 ++ ) {
F_8 ( 0 , ( V_3 -> V_216 + 1 ) ) ;
F_8 ( 0 , ( V_3 -> V_216 + 1 ) ) ;
F_8 ( 0 , ( V_3 -> V_216 + 1 ) ) ;
}
F_4 ( V_3 -> V_68 , 0x01 , V_583 ) ;
F_4 ( V_3 -> V_84 , 0x63 , V_588 ) ;
F_4 ( V_3 -> V_68 , 0x31 , V_589 ) ;
F_4 ( V_3 -> V_84 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_84 , 0x53 ) & 0xFD ) ) ;
F_4 ( V_3 -> V_68 , 0x1F , ( unsigned char ) V_584 ) ;
}
static void F_115 ( struct V_452 * V_453 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
unsigned short V_71 ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
if ( ! ( V_3 -> V_116 & V_550 ) ) {
if ( V_3 -> V_116 & V_552 ) {
F_4 ( V_3 -> V_366 , 0x1E , 0x20 ) ;
} else if ( V_3 -> V_29 & V_411 ) {
F_4 ( V_3 -> V_366 ,
0x1E , 0x20 ) ;
}
}
if ( ! ( V_3 -> V_116 & V_551 ) ) {
if ( ( V_3 -> V_116 & V_553 ) || ( V_3 -> V_29
& ( V_79 | V_78
| V_106 ) ) ) {
V_71 = ( unsigned char ) F_2 (
V_3 -> V_68 , 0x32 ) ;
V_71 &= 0xDF ;
if ( V_3 -> V_29 & V_80 ) {
if ( ! ( V_3 -> V_29 &
V_106 ) )
V_71 |= 0x20 ;
}
F_4 ( V_3 -> V_68 , 0x32 , V_71 ) ;
F_20 ( V_3 -> V_68 , 0x1E , 0x20 ) ;
V_71 = ( unsigned char ) F_2 (
V_3 -> V_366 , 0x2E ) ;
if ( ! ( V_71 & 0x80 ) )
F_20 ( V_3 -> V_366 ,
0x2E , 0x80 ) ;
F_13 ( V_3 -> V_366 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_116 & ( V_552 | V_553 ) )
|| ( ! ( V_3 -> V_29 & V_412 ) ) ) {
F_12 ( V_3 -> V_396 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_55 & ( V_57 | V_108 ) ) {
if ( ! F_91 ( V_3 ) ) {
if ( F_92 ( V_3 ) ||
( V_3 -> V_29 &
( V_79 | V_77 ) ) )
F_13 (
V_3 -> V_373 ,
0x2A ,
0x7F ) ;
}
F_13 ( V_3 -> V_373 , 0x30 , 0x7F ) ;
}
}
V_71 = 0x00 ;
if ( ! ( V_3 -> V_29 & V_412 ) ) {
V_71 = 0xc0 ;
if ( ! ( V_3 -> V_29 & V_420 ) &&
( V_3 -> V_29 & V_77 ) &&
( V_3 -> V_29 & V_411 ) ) {
V_71 = V_71 & 0x40 ;
if ( V_3 -> V_29 & V_77 )
V_71 = V_71 ^ 0xC0 ;
if ( V_3 -> V_116 & V_551 )
V_71 &= 0xBF ;
if ( V_3 -> V_116 & V_550 )
V_71 &= 0x7F ;
if ( V_3 -> V_116 & V_553 )
V_71 |= 0x40 ;
if ( V_3 -> V_116 & V_552 )
V_71 |= 0x80 ;
}
}
F_20 ( V_3 -> V_373 , 0x1F , V_71 ) ;
if ( ! ( V_3 -> V_116 & V_550 ) ) {
if ( ! ( V_3 -> V_116 & V_554 ) ) {
F_87 ( V_82 ,
V_3 ) ;
F_59 ( V_453 , V_82 ,
V_3 ) ;
}
}
}
else {
if ( V_3 -> V_29 & ( V_78 | V_79
| V_77 ) )
F_20 ( V_3 -> V_366 , 0x1E , 0x20 ) ;
V_71 = ( unsigned char ) F_2 ( V_3 -> V_366 ,
0x2E ) ;
if ( ! ( V_71 & 0x80 ) )
F_20 ( V_3 -> V_366 , 0x2E , 0x80 ) ;
F_13 ( V_3 -> V_366 , 0x00 , 0x7F ) ;
F_59 ( V_453 , V_82 , V_3 ) ;
}
}
static void F_116 ( struct V_452 * V_453 ,
struct V_81 * V_82 ,
unsigned short V_69 , unsigned short V_70 ,
struct V_2 * V_3 )
{
unsigned short V_98 , V_64 ;
F_3 ( V_69 , V_70 , V_3 ) ;
F_8 ( V_3 -> V_4 -> V_591 , V_3 -> V_132 ) ;
F_5 ( V_82 , V_3 ) ;
F_6 ( V_69 , V_70 , V_3 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
if ( V_82 -> V_137 == V_63 ) {
if ( V_3 -> V_105 == 0 )
F_11 ( V_3 ) ;
}
V_64 = ~ V_380 ;
V_3 -> V_116 &= V_64 ;
V_3 -> V_578 = 0 ;
if ( V_3 -> V_55 & ( V_123 | V_124 | V_56
| V_57 | V_108 ) ) {
if ( V_3 -> V_29 & ( V_420 | V_77
| V_80 ) ) {
V_3 -> V_116 |= V_380 ;
}
}
V_98 = F_111 ( V_82 , V_69 ,
V_70 , V_3 ) ;
if ( V_98 != 0xFFFF ) {
F_15 ( V_98 , V_3 ) ;
F_18 ( V_69 , V_70 , V_98 ,
V_3 , V_82 ) ;
F_25 ( V_82 , V_69 , V_70 ,
V_98 , V_3 ) ;
F_26 ( V_69 , V_70 , V_98 ,
V_82 , V_3 ) ;
F_28 ( V_69 , V_70 , V_82 ,
V_98 , V_3 ) ;
}
if ( V_82 -> V_137 >= V_195 ) {
V_64 = F_2 ( V_3 -> V_84 , 0x38 ) ;
if ( V_64 & 0xA0 ) {
if ( V_82 -> V_137 == V_63 )
F_21 ( V_69 , V_70 ,
V_98 , V_3 ) ;
else
F_19 ( V_69 , V_70 ,
V_98 , V_3 ) ;
F_24 ( V_69 , V_3 ,
V_98 ) ;
F_23 ( V_82 -> V_137 ,
V_3 , V_98 , V_69 ) ;
if ( V_3 -> V_105 == 1 )
F_89 ( V_453 ,
V_82 -> V_137 ,
V_69 , V_70 , V_3 ) ;
}
}
V_3 -> V_116 &= ( ~ V_380 ) ;
F_30 ( V_69 , V_82 , V_3 ) ;
F_32 ( V_82 , V_69 , V_70 ,
V_98 , V_3 ) ;
F_34 ( V_69 , V_70 , V_3 ) ;
}
unsigned char F_117 ( struct V_452 * V_453 ,
struct V_81 * V_82 ,
unsigned short V_69 )
{
unsigned short V_70 ;
struct V_2 V_592 ;
struct V_2 * V_3 = & V_592 ;
V_3 -> V_593 = V_453 -> V_594 ;
V_3 -> V_105 = 0 ;
if ( V_82 -> V_137 >= V_61 ) {
V_3 -> V_415 = 0 ;
V_3 -> V_417 = 0 ;
V_3 -> V_422 = 0 ;
V_3 -> V_55 = 0 ;
} else {
V_3 -> V_415 = 1 ;
V_3 -> V_417 = 1 ;
V_3 -> V_422 = 1 ;
}
V_3 -> V_68 = V_3 -> V_593 + 0x14 ;
V_3 -> V_84 = V_3 -> V_593 + 0x24 ;
V_3 -> V_90 = V_3 -> V_593 + 0x10 ;
V_3 -> V_93 = V_3 -> V_593 + 0x1e ;
V_3 -> V_132 = V_3 -> V_593 + 0x12 ;
V_3 -> V_154 = V_3 -> V_593 + 0x1C ;
V_3 -> V_389 = V_3 -> V_593 + 0x1a ;
V_3 -> V_215 = V_3 -> V_593 + 0x16 ;
V_3 -> V_595 = V_3 -> V_593 + 0x17 ;
V_3 -> V_216 = V_3 -> V_593 + 0x18 ;
V_3 -> V_205 = V_3 -> V_593 + 0x19 ;
V_3 -> V_89 = V_3 -> V_593 + 0x2A ;
V_3 -> V_596 = V_3 -> V_593 + V_597 ;
V_3 -> V_366 = V_3 -> V_593 + V_598 ;
V_3 -> V_396 = V_3 -> V_593 + V_599 ;
V_3 -> V_517 = V_3 -> V_593 + V_600 ;
V_3 -> V_373 = V_3 -> V_593 + V_601 ;
V_3 -> V_526 = V_3 -> V_593 + V_601 + 2 ;
if ( V_82 -> V_137 == V_195 ) {
if ( ( F_2 ( V_3 -> V_84 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_105 = 1 ;
}
if ( V_82 -> V_137 == V_63 ) {
if ( ( F_2 ( V_3 -> V_84 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_2 ( V_3 -> V_84 , 0x30 ) & 0x20 )
V_3 -> V_105 = 1 ;
}
}
if ( V_82 -> V_137 < V_61 )
F_49 ( V_3 ) ;
F_1 ( V_82 -> V_137 , V_3 ) ;
if ( V_69 & 0x80 )
V_69 = V_69 & 0x7F ;
F_4 ( V_3 -> V_68 , 0x05 , 0x86 ) ;
if ( V_82 -> V_137 < V_61 )
F_108 ( V_82 , V_3 ) ;
F_53 ( V_69 , & V_70 , V_3 ) ;
if ( V_82 -> V_137 < V_61 ) {
F_50 ( V_69 , V_70 , V_82 , V_3 ) ;
F_51 ( V_69 , V_70 , V_3 ) ;
F_52 ( V_69 , V_70 , V_3 ) ;
F_93 ( V_453 , V_82 , V_3 ) ;
if ( V_3 -> V_29 & ( V_420 | V_77 ) ) {
F_116 ( V_453 , V_82 , V_69 ,
V_70 , V_3 ) ;
if ( V_3 -> V_29 & V_77 ) {
F_112 ( V_69 , V_70 ,
V_82 , V_3 ) ;
}
} else if ( ! ( V_3 -> V_29 & V_421 ) ) {
F_116 ( V_453 ,
V_82 , V_69 ,
V_70 , V_3 ) ;
if ( V_3 -> V_29 & V_77 ) {
F_112 ( V_69 , V_70 ,
V_82 ,
V_3 ) ;
}
}
if ( V_3 -> V_29 & ( V_420 | V_421 ) ) {
switch ( V_82 -> V_602 ) {
case V_603 :
F_113 ( V_69 , V_82 ,
V_3 ) ;
break;
case V_604 :
F_113 ( V_69 , V_82 ,
V_3 ) ;
break;
default:
break;
}
}
F_107 ( V_69 , V_82 , V_3 ) ;
F_106 ( V_69 , V_70 , V_3 ) ;
F_115 ( V_453 , V_82 , V_3 ) ;
}
else {
if ( V_3 -> V_105 == 1 )
if ( ! F_88 ( V_453 , V_69 ,
V_70 ,
V_3 ) )
return 0 ;
V_3 -> V_94 = V_3 -> V_6 [ V_70 ] .
V_75 & V_410 ;
V_3 -> V_116 = 0 ;
V_3 -> V_29 = V_412 ;
F_61 ( V_453 , V_82 , V_3 ) ;
F_116 ( V_453 , V_82 , V_69 ,
V_70 , V_3 ) ;
F_59 ( V_453 , V_82 , V_3 ) ;
}
F_48 ( V_82 , V_3 ) ;
if ( V_82 -> V_137 < V_61 )
F_109 ( V_82 , V_3 ) ;
return 1 ;
}
