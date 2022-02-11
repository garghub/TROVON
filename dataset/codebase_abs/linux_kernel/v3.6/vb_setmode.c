void F_1 ( unsigned char V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = (struct V_5 * ) & V_6 ;
V_3 -> V_7 = (struct V_8 * ) V_9 ;
V_3 -> V_10 = (struct V_11 * ) V_12 ;
V_3 -> V_13
= (struct V_14 * ) V_15 ;
V_3 -> V_16 = (struct V_17 * ) V_18 ;
V_3 -> V_19 = (struct V_20 * ) V_21 ;
V_3 -> V_22 = (struct V_23 * ) V_24 ;
V_3 -> V_25 = (struct V_26 * ) V_27 ;
V_3 -> V_28 = V_29 ;
V_3 -> V_30 = (struct V_31 * ) V_32 ;
V_3 -> V_33
= (struct V_34 * ) V_35 ;
V_3 -> V_36 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_38 = 0 ;
V_3 -> V_39 = 0 ;
V_3 -> V_40 = 0 ;
V_3 -> V_41 = V_42 ;
V_3 -> V_43 = V_44 ;
V_3 -> V_45 = V_46 ;
V_3 -> V_47 = V_48 ;
V_3 -> V_49 = V_50 ;
V_3 -> V_51 = V_52 ;
V_3 -> V_53 = V_54 ;
V_3 -> V_55 = V_56 ;
V_3 -> V_57 = 0xa3 ;
V_3 -> V_58 = 0xfb ;
V_3 -> V_59 = V_60 ;
V_3 -> V_61 = V_62 ;
V_3 -> V_63 = V_64 ;
V_3 -> V_65 = V_66 ;
V_3 -> V_67 = V_68 ;
V_3 -> V_69 = V_70 ;
V_3 -> V_71 = V_72 ;
V_3 -> V_73 = V_74 ;
V_3 -> V_75 = V_76 ;
V_3 -> V_77 = V_78 ;
V_3 -> V_79 = V_80 ;
V_3 -> V_81 = V_82 ;
V_3 -> V_83 = V_84 ;
V_3 -> V_85 = V_86 ;
V_3 -> V_87 = (struct V_88 * ) V_89 ;
V_3 -> V_90 = (struct V_91 * ) V_92 ;
V_3 -> V_93 = (struct V_94 * ) V_95 ;
if ( ( V_3 -> V_96 & V_97 ) || ( V_3 -> V_96 & V_98 ) )
V_3 -> V_99 = V_100 ;
else
V_3 -> V_99 = V_101 ;
if ( V_1 >= V_102 )
V_3 -> V_103 = 0x10 ;
if ( V_1 == V_104 ) {
unsigned char V_105 ;
V_3 -> V_16
= (struct V_17 * ) V_106 ;
V_3 -> V_43 = V_107 ;
V_3 -> V_103 = 0xc1 ;
V_3 -> V_41 = V_108 ;
V_105 = F_2 ( V_3 -> V_109 , 0x3B ) ;
if ( ( ( V_105 & 0x88 ) == 0x80 ) || ( ( V_105 & 0x88 ) == 0x08 ) )
V_3 -> V_103 = 0x80 ;
}
}
static void F_3 ( unsigned short V_110 ,
unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned char V_112 , V_113 ;
unsigned short V_114 , V_115 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
F_4 ( V_3 -> V_109 , 0x00 , 0x03 ) ;
V_112 = V_3 -> V_4 -> V_117 [ 0 ] ;
V_114 = V_118 ;
if ( V_3 -> V_39 & V_118 ) {
V_112 |= 0x01 ;
} else {
if ( V_3 -> V_39 & ( V_119 | V_120 ) ) {
if ( V_3 -> V_39 & V_121 )
V_112 |= 0x01 ;
}
}
V_112 |= 0x20 ;
F_4 ( V_3 -> V_109 , 0x01 , V_112 ) ;
for ( V_114 = 02 ; V_114 <= 04 ; V_114 ++ ) {
V_113 = V_3 -> V_4 -> V_117 [ V_114 - 1 ] ;
F_4 ( V_3 -> V_109 , V_114 , V_113 ) ;
}
}
static void F_5 ( struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned char V_124 ;
unsigned short V_114 ;
V_124 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x11 ) ;
V_124 &= 0x7f ;
F_4 ( V_3 -> V_125 , 0x11 , V_124 ) ;
for ( V_114 = 0 ; V_114 <= 0x18 ; V_114 ++ ) {
V_124 = V_3 -> V_4 -> V_126 [ V_114 ] ;
F_4 ( V_3 -> V_125 , V_114 , V_124 ) ;
}
}
static void F_6 ( unsigned short V_110 ,
unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned char V_127 ;
unsigned short V_114 , V_115 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
for ( V_114 = 0 ; V_114 <= 0x13 ; V_114 ++ ) {
V_127 = V_3 -> V_4 -> V_128 [ V_114 ] ;
if ( ( V_115 & V_129 ) && V_114 == 0x13 ) {
if ( V_3 -> V_39 & V_118 ) {
V_127 = 0 ;
} else {
if ( ( V_3 -> V_39 &
( V_119 | V_120 ) ) &&
( V_3 -> V_39 & V_121 ) )
V_127 = 0 ;
}
}
F_7 ( V_3 -> V_130 ) ;
F_8 ( V_114 , V_3 -> V_131 ) ;
F_8 ( V_127 , V_3 -> V_131 ) ;
}
F_7 ( V_3 -> V_130 ) ;
F_8 ( 0x14 , V_3 -> V_131 ) ;
F_8 ( 0x00 , V_3 -> V_131 ) ;
F_7 ( V_3 -> V_130 ) ;
F_8 ( 0x20 , V_3 -> V_131 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
unsigned char V_132 ;
unsigned short V_114 ;
for ( V_114 = 0 ; V_114 <= 0x08 ; V_114 ++ ) {
V_132 = V_3 -> V_4 -> V_133 [ V_114 ] ;
F_4 ( V_3 -> V_134 , V_114 , V_132 ) ;
}
if ( V_3 -> V_135 > V_136 ) {
V_132 = ( unsigned char ) F_2 ( V_3 -> V_134 , 0x05 ) ;
V_132 &= 0xBF ;
F_4 ( V_3 -> V_134 , 0x05 , V_132 ) ;
}
}
static void F_10 ( struct V_2 * V_3 )
{
unsigned short V_114 ;
for ( V_114 = 0x0A ; V_114 <= 0x0E ; V_114 ++ )
F_4 ( V_3 -> V_109 , V_114 , 0x00 ) ;
}
static unsigned char F_11 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_109 , 0x31 , ~ 0x30 , 0x20 ) ;
F_4 ( V_3 -> V_109 , 0x2B , V_3 -> V_22 [ 0 ] . V_137 ) ;
F_4 ( V_3 -> V_109 , 0x2C , V_3 -> V_22 [ 0 ] . V_138 ) ;
F_12 ( V_3 -> V_109 , 0x31 , ~ 0x30 , 0x10 ) ;
F_4 ( V_3 -> V_109 , 0x2B , V_3 -> V_22 [ 1 ] . V_137 ) ;
F_4 ( V_3 -> V_109 , 0x2C , V_3 -> V_22 [ 1 ] . V_138 ) ;
F_13 ( V_3 -> V_109 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_14 ( unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 , unsigned short * V_114 ,
struct V_2 * V_3 )
{
unsigned short V_140 , V_141 , V_142 , V_115 , V_143 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_141 = V_3 -> V_10 [ V_139 + ( * V_114 ) ] . V_145 ;
V_140 = 0 ;
if ( V_3 -> V_146 == 0 ) {
if ( V_3 -> V_39 & V_147 ) {
V_140 |= V_148 ;
if ( V_3 -> V_96 & V_149 )
V_140 |= V_150 ;
}
if ( V_3 -> V_39 & ( V_120 | V_118 ) ) {
V_140 |= V_151 ;
if ( V_3 -> V_36 != V_152 &&
V_3 -> V_36 != V_153 &&
( V_3 -> V_38 & V_154 ) &&
V_142 >= 9 )
return 0 ;
}
if ( V_3 -> V_39 & V_155 ) {
if ( ( V_3 -> V_96 & V_97 ) &&
( V_3 -> V_156 == V_157 ) ) {
V_140 |= V_158 ;
if ( ( V_3 -> V_39 & V_121 ) &&
( ( V_142 == 3 ) ||
( V_142 == 4 ) ||
( V_142 > 7 ) ) )
return 0 ;
} else {
V_140 |= V_159 ;
if ( ( V_3 -> V_39 & V_121 ) &&
( ( V_142 == 4 ) ||
( V_142 == 3 &&
( V_3 -> V_160 & V_161 ) ) ||
( V_142 > 7 ) ) )
return 0 ;
}
} else {
if ( V_3 -> V_39 & ( V_162 |
V_163 |
V_164 |
V_165 |
V_155 ) ) {
V_140 |= V_166 ;
if ( V_3 -> V_96 & ( V_167 |
V_168 |
V_97 |
V_98 |
V_149 ) )
V_140 |= V_169 ;
if ( ! ( V_3 -> V_39 & V_170 ) &&
( V_115 & V_171 ) &&
( V_3 -> V_39 & V_121 ) &&
( ! ( V_3 -> V_39 & V_172 ) ) )
return 0 ;
}
}
} else {
if ( V_3 -> V_39 & V_120 ) {
V_140 |= V_151 ;
if ( V_142 > 0x08 )
return 0 ;
if ( V_3 -> V_36 < V_173 ) {
if ( V_142 > 0x07 )
return 0 ;
if ( V_142 == 0x04 )
return 0 ;
}
}
}
for (; V_3 -> V_10 [ V_139 + ( * V_114 ) ] . V_145 ==
V_141 ; ( * V_114 ) -- ) {
V_143 = V_3 -> V_10 [ V_139 + ( * V_114 ) ] .
V_174 ;
if ( V_143 & V_140 )
return 1 ;
if ( ( * V_114 ) == 0 )
break;
}
for ( ( * V_114 ) = 0 ; ; ( * V_114 ) ++ ) {
V_143 = V_3 -> V_10 [ V_139 + ( * V_114 ) ] .
V_174 ;
if ( V_3 -> V_10 [ V_139 + ( * V_114 ) ] . V_145
!= V_141 ) {
return 0 ;
}
if ( V_143 & V_140 )
return 1 ;
}
return 1 ;
}
static void F_15 ( unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_175 , V_105 ;
V_175 = V_3 -> V_10 [ V_139 ] . V_174 >> 8 ;
V_175 &= 0xC0 ;
V_105 = 0x2F ;
V_105 |= V_175 ;
F_8 ( V_105 , V_3 -> V_176 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_122 * V_123 )
{
unsigned char V_177 , V_178 , V_179 ;
unsigned short V_114 , V_180 ;
V_177 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x11 ) ;
V_177 &= 0x7F ;
F_4 ( V_3 -> V_125 , 0x11 , V_177 ) ;
V_177 = V_3 -> V_87 [ 0 ] . V_177 [ 0 ] ;
F_4 ( V_3 -> V_125 , 0 , V_177 ) ;
for ( V_114 = 0x01 ; V_114 <= 0x04 ; V_114 ++ ) {
V_177 = V_3 -> V_87 [ 0 ] . V_177 [ V_114 ] ;
F_4 ( V_3 -> V_125 , ( unsigned short ) ( V_114 + 1 ) , V_177 ) ;
}
for ( V_114 = 0x05 ; V_114 <= 0x06 ; V_114 ++ ) {
V_177 = V_3 -> V_87 [ 0 ] . V_177 [ V_114 ] ;
F_4 ( V_3 -> V_109 , ( unsigned short ) ( V_114 + 6 ) , V_177 ) ;
}
V_180 = ( unsigned char ) F_2 ( V_3 -> V_109 , 0x0e ) ;
V_180 &= 0x1F ;
V_177 = V_3 -> V_87 [ 0 ] . V_177 [ 7 ] ;
V_177 &= 0xE0 ;
V_177 |= V_180 ;
F_4 ( V_3 -> V_109 , 0x0e , V_177 ) ;
if ( V_123 -> V_181 >= V_102 ) {
V_177 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x04 ) ;
V_177 = V_177 - 1 ;
F_4 ( V_3 -> V_125 , 0x04 , V_177 ) ;
V_177 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x05 ) ;
V_178 = V_177 ;
V_178 &= 0xE0 ;
V_177 &= 0x1F ;
if ( V_177 == 0 ) {
V_179 = V_177 ;
V_177 = ( unsigned char ) F_2 ( V_3 -> V_109 ,
0x0c ) ;
V_177 &= 0xFB ;
F_4 ( V_3 -> V_109 , 0x0c , V_177 ) ;
V_177 = V_179 ;
}
V_177 = V_177 - 1 ;
V_177 |= V_178 ;
F_4 ( V_3 -> V_125 , 0x05 , V_177 ) ;
V_177 = ( unsigned char ) F_2 ( V_3 -> V_109 , 0x0e ) ;
V_177 = V_177 >> 5 ;
V_177 = V_177 + 3 ;
if ( V_177 > 7 )
V_177 = V_177 - 7 ;
V_177 = V_177 << 5 ;
F_12 ( V_3 -> V_109 , 0x0e , ~ 0xE0 , V_177 ) ;
}
}
static void F_17 ( unsigned short V_111 ,
unsigned short V_110 ,
struct V_2 * V_3 )
{
unsigned char V_177 ;
unsigned short V_114 , V_180 ;
for ( V_114 = 0x00 ; V_114 <= 0x01 ; V_114 ++ ) {
V_177 = V_3 -> V_90 [ 0 ] . V_177 [ V_114 ] ;
F_4 ( V_3 -> V_125 , ( unsigned short ) ( V_114 + 6 ) , V_177 ) ;
}
for ( V_114 = 0x02 ; V_114 <= 0x03 ; V_114 ++ ) {
V_177 = V_3 -> V_90 [ 0 ] . V_177 [ V_114 ] ;
F_4 ( V_3 -> V_125 , ( unsigned short ) ( V_114 + 0x0e ) , V_177 ) ;
}
for ( V_114 = 0x04 ; V_114 <= 0x05 ; V_114 ++ ) {
V_177 = V_3 -> V_90 [ 0 ] . V_177 [ V_114 ] ;
F_4 ( V_3 -> V_125 , ( unsigned short ) ( V_114 + 0x11 ) , V_177 ) ;
}
V_180 = ( unsigned char ) F_2 ( V_3 -> V_109 , 0x0a ) ;
V_180 &= 0xC0 ;
V_177 = V_3 -> V_90 [ 0 ] . V_177 [ 6 ] ;
V_177 &= 0x3F ;
V_177 |= V_180 ;
F_4 ( V_3 -> V_109 , 0x0a , V_177 ) ;
V_177 = V_3 -> V_90 [ 0 ] . V_177 [ 6 ] ;
V_177 &= 0x80 ;
V_177 = V_177 >> 2 ;
V_114 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_114 &= V_182 ;
if ( V_114 )
V_177 |= 0x80 ;
V_180 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x09 ) ;
V_180 &= 0x5F ;
V_177 |= V_180 ;
F_4 ( V_3 -> V_125 , 0x09 , V_177 ) ;
}
static void F_18 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 ,
struct V_122 * V_123 )
{
unsigned char V_183 , V_177 ;
unsigned short V_114 ;
V_183 = V_3 -> V_10 [ V_139 ] . V_184 ;
V_183 = V_183 & V_185 ;
V_177 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x11 ) ;
V_177 &= 0x7F ;
F_4 ( V_3 -> V_125 , 0x11 , V_177 ) ;
for ( V_114 = 0 ; V_114 < 8 ; V_114 ++ )
V_3 -> V_87 [ 0 ] . V_177 [ V_114 ]
= V_3 -> V_13 [ V_183 ] . V_186 [ V_114 ] ;
for ( V_114 = 0 ; V_114 < 7 ; V_114 ++ )
V_3 -> V_90 [ 0 ] . V_177 [ V_114 ]
= V_3 -> V_13 [ V_183 ] . V_186 [ V_114 + 8 ] ;
F_16 ( V_3 , V_123 ) ;
F_17 ( V_111 , V_110 , V_3 ) ;
if ( V_3 -> V_135 > 0x03 )
F_4 ( V_3 -> V_125 , 0x14 , 0x4F ) ;
}
static void F_19 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned char V_183 , V_187 , V_188 , V_189 , V_190 ;
unsigned short V_191 , V_192 , V_193 ;
V_183 = V_3 -> V_10 [ V_139 ] . V_184 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 3 ] ;
V_189 = V_187 ;
F_4 ( V_3 -> V_109 , 0x2E , V_187 ) ;
V_190 = V_3 -> V_13 [ V_183 ] . V_186 [ 5 ] ;
V_190 &= 0xC0 ;
V_191 = V_190 ;
V_191 <<= 2 ;
V_191 |= V_187 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 4 ] ;
V_187 &= 0x1F ;
V_188 = V_3 -> V_13 [ V_183 ] . V_186 [ 6 ] ;
V_188 &= 0x04 ;
V_188 <<= 3 ;
V_187 |= V_188 ;
V_192 = V_191 & 0x3C0 ;
V_192 |= V_187 ;
V_189 &= 0x3F ;
if ( V_187 < V_189 )
V_192 |= 0x40 ;
V_192 &= 0xFF ;
V_187 = ( unsigned char ) V_192 ;
V_187 <<= 2 ;
V_190 >>= 6 ;
V_187 |= V_190 ;
F_4 ( V_3 -> V_109 , 0x2F , V_187 ) ;
F_12 ( V_3 -> V_109 , 0x30 , 0xE3 , 00 ) ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 10 ] ;
V_188 = V_187 ;
V_187 &= 0x01 ;
F_20 ( V_3 -> V_109 , 0x33 , V_187 ) ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 9 ] ;
V_189 = V_188 >> 1 ;
V_190 = V_187 & 0x04 ;
V_190 <<= 5 ;
V_189 |= V_190 ;
F_4 ( V_3 -> V_109 , 0x34 , V_189 ) ;
V_191 = V_190 ;
V_191 <<= 1 ;
V_191 |= V_188 ;
V_187 &= 0x80 ;
V_192 = V_187 << 2 ;
V_191 |= V_192 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 14 ] ;
V_187 &= 0x08 ;
V_192 = V_187 ;
V_192 <<= 7 ;
V_191 |= V_192 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 11 ] ;
V_187 &= 0x0F ;
V_188 = V_3 -> V_13 [ V_183 ] . V_186 [ 14 ] ;
V_188 &= 0x20 ;
V_188 >>= 1 ;
V_187 |= V_188 ;
V_192 = V_191 & 0x7E0 ;
V_192 |= V_187 ;
V_193 = V_191 & 0x1F ;
if ( V_187 < V_193 )
V_192 |= 0x20 ;
V_192 &= 0xFF ;
V_187 = ( unsigned char ) V_192 ;
V_187 <<= 2 ;
V_191 &= 0x600 ;
V_191 >>= 9 ;
V_188 = ( unsigned char ) V_191 ;
V_187 |= V_188 ;
V_187 &= 0x7F ;
F_4 ( V_3 -> V_109 , 0x3F , V_187 ) ;
}
static void F_21 ( unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_183 , V_187 , V_188 , V_189 ;
V_183 = V_3 -> V_10 [ V_139 ] . V_184 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 3 ] ;
V_188 = V_187 ;
F_4 ( V_3 -> V_109 , 0x2E , V_187 ) ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 5 ] ;
V_187 &= 0xC0 ;
V_188 |= ( V_187 << 2 ) ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 4 ] ;
V_187 &= 0x1F ;
V_189 = V_187 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 6 ] ;
V_187 &= 0x04 ;
V_187 <<= 3 ;
V_189 |= V_187 ;
V_188 = V_188 & 0x3C0 ;
V_188 |= V_189 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 3 ] ;
V_187 &= 0x3F ;
if ( V_189 <= V_187 )
V_188 += 0x40 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 5 ] ;
V_187 &= 0xC0 ;
V_187 >>= 6 ;
V_187 |= ( ( V_188 << 2 ) & 0xFF ) ;
F_4 ( V_3 -> V_109 , 0x2F , V_187 ) ;
F_12 ( V_3 -> V_109 , 0x30 , 0xE3 , 00 ) ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 10 ] ;
F_4 ( V_3 -> V_109 , 0x34 , V_187 ) ;
V_189 = V_187 ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 9 ] ;
V_188 = V_187 ;
V_187 = V_187 & 0x04 ;
V_187 >>= 2 ;
F_12 ( V_3 -> V_109 , 0x35 , ~ 0x01 , V_187 ) ;
V_189 |= ( V_187 << 8 ) ;
V_189 |= ( ( V_188 & 0x80 ) << 2 ) ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 14 ] ;
V_187 &= 0x08 ;
V_189 |= ( V_187 << 7 ) ;
V_187 = V_3 -> V_13 [ V_183 ] . V_186 [ 11 ] ;
V_187 &= 0x0F ;
V_188 = V_3 -> V_13 [ V_183 ] . V_186 [ 14 ] ;
V_188 &= 0x20 ;
V_188 >>= 1 ;
V_187 |= V_188 ;
V_188 = V_189 ;
V_188 &= 0x7E0 ;
V_188 |= V_187 ;
if ( V_188 <= V_189 )
V_188 |= 0x20 ;
V_187 = ( V_188 << 2 ) & 0xFF ;
F_12 ( V_3 -> V_109 , 0x3F , ~ 0xFC , V_187 ) ;
V_187 = V_189 >> 8 ;
F_12 ( V_3 -> V_109 , 0x35 , ~ 0x07 , V_187 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned char V_105 ;
V_105 = F_2 ( V_3 -> V_125 , 0x37 ) ;
V_105 = ( V_105 & 3 ) << 6 ;
F_12 ( V_3 -> V_109 , 0x06 , ~ 0xc0 , V_105 & 0x80 ) ;
F_12 ( V_3 -> V_109 , 0x09 , ~ 0xc0 , V_105 | 0x80 ) ;
}
static void F_23 ( int V_194 ,
struct V_2 * V_3 ,
unsigned short V_139 ,
unsigned short V_110 )
{
unsigned short V_195 , V_196 ;
unsigned short V_197 ;
V_197 = V_3 -> V_198 ;
F_4 ( V_3 -> V_125 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_125 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_125 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_125 , 0x47 , 0x00 ) ;
if ( V_194 == V_104 ) {
V_196 = F_2 ( V_3 -> V_125 , 0x37 ) ;
if ( ( V_196 & 0x03 ) == 0 ) {
F_4 ( V_3 -> V_125 , 0x46 , 0x13 ) ;
F_4 ( V_3 -> V_125 , 0x47 , 0x13 ) ;
}
}
if ( V_194 == V_104 ) {
F_22 ( V_3 ) ;
} else {
V_196 = F_2 ( V_3 -> V_125 , 0x37 ) ;
if ( V_196 & 0x01 ) {
F_20 ( V_3 -> V_109 , 0x06 , 0x40 ) ;
F_20 ( V_3 -> V_109 , 0x09 , 0x40 ) ;
}
}
F_20 ( V_3 -> V_109 , 0x1E , 0x01 ) ;
F_13 ( V_3 -> V_109 , 0x30 , ~ 0x20 ) ;
F_13 ( V_3 -> V_109 , 0x35 , ~ 0x80 ) ;
V_195 = V_3 -> V_10 [ V_139 ] . V_174 ;
if ( V_195 & 0x4000 )
F_20 ( V_3 -> V_109 , 0x30 , 0x20 ) ;
if ( V_195 & 0x8000 )
F_20 ( V_3 -> V_109 , 0x35 , 0x80 ) ;
}
static void F_24 ( unsigned short V_110 ,
struct V_2 * V_3 ,
unsigned short V_139 )
{
int V_183 = - 1 ;
F_13 ( V_3 -> V_125 , 0x11 , 0x7F ) ;
if ( V_110 == 0x2E &&
( V_3 -> V_10 [ V_139 ] . V_184 ==
V_199 ) )
V_183 = 12 ;
else if ( V_110 == 0x2E && ( V_3 -> V_10 [ V_139 ] .
V_184 == V_200 ) )
V_183 = 13 ;
else if ( V_110 == 0x2F )
V_183 = 14 ;
else if ( V_110 == 0x50 )
V_183 = 15 ;
else if ( V_110 == 0x59 )
V_183 = 16 ;
if ( V_183 != - 1 ) {
F_4 ( V_3 -> V_125 , 0x02 ,
V_3 -> V_93 [ V_183 ] . V_201 ) ;
F_4 ( V_3 -> V_125 , 0x03 ,
V_3 -> V_93 [ V_183 ] . V_202 ) ;
F_4 ( V_3 -> V_125 , 0x15 ,
V_3 -> V_93 [ V_183 ] . V_203 ) ;
F_4 ( V_3 -> V_125 , 0x16 ,
V_3 -> V_93 [ V_183 ] . V_204 ) ;
}
}
static void F_25 ( struct V_122 * V_123 ,
unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_205 , V_140 , V_141 , V_206 , V_105 , V_115 ;
unsigned char V_177 ;
V_205 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_140 = V_3 -> V_33 [ V_205 ] . V_207 ;
V_141 = V_3 -> V_33 [ V_205 ] . V_208 ;
if ( V_115 & V_209 )
V_140 = V_140 >> 1 ;
if ( V_115 & V_209 )
V_140 = V_140 << 1 ;
V_105 = V_3 -> V_10 [ V_139 ] . V_174 ;
if ( V_105 & V_210 )
V_141 = V_141 >> 1 ;
if ( V_115 & V_182 )
V_141 = V_141 << 1 ;
V_206 = 8 ;
V_140 /= V_206 ;
V_140 -= 1 ;
V_141 -= 1 ;
V_206 = V_140 ;
V_105 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x11 ) ;
V_177 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x11 ) ;
V_177 &= 0x7F ;
F_4 ( V_3 -> V_125 , 0x11 , V_177 ) ;
F_4 ( V_3 -> V_125 , 0x01 , ( unsigned short ) ( V_206 & 0xff ) ) ;
F_12 ( V_3 -> V_125 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_206 & 0x0ff00 ) >> 10 ) ) ;
F_4 ( V_3 -> V_125 , 0x12 , ( unsigned short ) ( V_141 & 0xff ) ) ;
V_140 = 0 ;
V_141 = V_141 >> 8 ;
if ( V_141 & 0x01 )
V_140 |= 0x02 ;
if ( V_141 & 0x02 )
V_140 |= 0x40 ;
F_12 ( V_3 -> V_125 , 0x07 , ~ 0x42 , V_140 ) ;
V_177 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x07 ) ;
V_177 &= 0xFF ;
V_140 = 0 ;
if ( V_141 & 0x04 )
V_140 |= 0x02 ;
F_12 ( V_3 -> V_125 , 0x0a , ~ 0x02 , V_140 ) ;
F_4 ( V_3 -> V_125 , 0x11 , V_105 ) ;
}
static void F_26 ( unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_105 , V_211 , V_212 , V_213 , V_114 , V_214 ;
V_105 = V_3 -> V_7 [ V_111 ] . V_215 ;
V_105 = V_105 >> 8 ;
V_105 = V_3 -> V_28 [ V_105 ] ;
V_213 = V_3 -> V_10 [ V_139 ] . V_174 ;
V_213 &= V_210 ;
if ( V_213 )
V_105 = V_105 << 1 ;
V_213 = V_3 -> V_135 - V_216 ;
switch ( V_213 ) {
case 0 :
V_213 = 1 ;
break;
case 1 :
V_213 = 2 ;
break;
case 2 :
V_213 = 4 ;
break;
case 3 :
V_213 = 4 ;
break;
case 4 :
V_213 = 6 ;
break;
case 5 :
V_213 = 8 ;
break;
default:
break;
}
if ( ( V_110 >= 0x26 ) && ( V_110 <= 0x28 ) )
V_105 = V_105 * V_213 + V_213 / 2 ;
else
V_105 *= V_213 ;
V_214 = V_105 ;
V_213 = V_105 ;
V_105 = V_105 >> 8 ;
V_105 &= 0x0F ;
V_114 = F_2 ( V_3 -> V_109 , 0x0E ) ;
V_114 &= 0xF0 ;
V_114 |= V_105 ;
F_4 ( V_3 -> V_109 , 0x0E , V_114 ) ;
V_105 = ( unsigned char ) V_213 ;
V_105 &= 0xFF ;
F_4 ( V_3 -> V_125 , 0x13 , V_105 ) ;
V_213 = V_3 -> V_10 [ V_139 ] . V_174 ;
V_213 &= V_210 ;
if ( V_213 )
V_214 >>= 1 ;
V_214 = V_214 << 5 ;
V_211 = ( V_214 & 0xff00 ) >> 8 ;
V_212 = V_214 & 0x00ff ;
if ( V_212 == 0 )
V_211 += 1 ;
else
V_211 += 2 ;
if ( V_123 -> V_181 >= V_102 )
if ( ( V_110 == 0x4A ) | ( V_110 == 0x49 ) )
V_211 -= 1 ;
F_4 ( V_3 -> V_109 , 0x10 , V_211 ) ;
}
static unsigned short F_27 ( unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_217 , V_218 ;
unsigned short V_115 , V_142 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_217 = V_3 -> V_10 [ V_139 ] . V_219 ;
if ( V_3 -> V_146 == 0 ) {
V_217 = V_217 >> 6 ;
if ( V_3 -> V_39 &
( V_120 | V_118 ) ) {
if ( V_3 -> V_36 != V_173 )
V_218 = V_220 + 5 ;
else
V_218 = V_221 + 2 ;
} else if ( V_3 -> V_39 & V_155 ) {
if ( V_3 -> V_160 & V_222 )
V_218 = V_223 + V_224 ;
else
V_218 = V_223 + V_225 ;
if ( V_3 -> V_160 & V_161 ) {
if ( V_115 & V_129 ) {
V_218 = V_223 +
V_226 ;
} else {
V_218 = V_223 +
V_227 ;
}
}
if ( ( V_3 -> V_96 & V_97 ) &&
! ( V_3 -> V_156 == V_157 ) ) {
if ( V_3 -> V_156 == V_228 )
V_218 = V_229 ;
else if ( V_3 -> V_156 == V_230 )
V_218 = V_231 ;
else if ( V_3 -> V_160 & V_222 )
V_218 = V_232 ;
else
V_218 = V_233 ;
}
} else if ( V_3 -> V_39 & V_119 ) {
if ( V_3 -> V_160 & V_222 )
V_218 = V_223 + V_234 ;
else
V_218 = V_223 + V_235 ;
} else {
V_218 = V_3 -> V_10 [ V_139 ] .
V_236 ;
V_218 &= V_185 ;
}
} else {
if ( ( V_3 -> V_36 == V_237 ) ||
( V_3 -> V_36 == V_238 ) )
V_218 = V_239 ;
else
V_218 = V_221 + 2 ;
}
return V_218 ;
}
static void F_28 ( unsigned short V_110 ,
unsigned short V_111 ,
struct V_122 * V_123 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned char V_183 , V_177 ;
unsigned short V_240 ;
if ( V_3 -> V_146 == 1 ) {
V_183 = V_3 -> V_10 [ V_139 ] . V_236 ;
V_177 = F_2 ( V_3 -> V_109 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_109 , 0x31 , V_177 ) ;
F_4 ( V_3 -> V_109 , 0x2B ,
V_3 -> V_22 [ V_183 ] . V_137 ) ;
F_4 ( V_3 -> V_109 , 0x2C ,
V_3 -> V_22 [ V_183 ] . V_138 ) ;
F_4 ( V_3 -> V_109 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) && ( V_3 -> V_39
& V_118 ) ) {
V_240 = F_27 ( V_110 , V_111 ,
V_139 , V_123 ,
V_3 ) ;
V_177 = F_2 ( V_3 -> V_109 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_109 , 0x31 , V_177 ) ;
V_177 = V_3 -> V_25 [ V_240 ] . V_241 ;
F_4 ( V_3 -> V_109 , 0x2B , V_177 ) ;
V_177 = V_3 -> V_25 [ V_240 ] . V_242 ;
F_4 ( V_3 -> V_109 , 0x2C , V_177 ) ;
F_4 ( V_3 -> V_109 , 0x2D , 0x01 ) ;
} else {
V_183 = V_3 -> V_10 [ V_139 ] . V_236 ;
V_177 = F_2 ( V_3 -> V_109 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_109 , 0x31 , V_177 ) ;
F_4 ( V_3 -> V_109 , 0x2B ,
V_3 -> V_22 [ V_183 ] . V_137 ) ;
F_4 ( V_3 -> V_109 , 0x2C ,
V_3 -> V_22 [ V_183 ] . V_138 ) ;
F_4 ( V_3 -> V_109 , 0x2D , 0x01 ) ;
}
if ( V_123 -> V_181 >= V_102 ) {
if ( V_3 -> V_7 [ V_111 ] . V_116 &
V_209 ) {
V_177 = F_2 ( V_3 -> V_109 , 0x2B ) ;
F_4 ( V_3 -> V_109 , 0x2B , V_177 ) ;
V_177 = F_2 ( V_3 -> V_109 , 0x2C ) ;
V_183 = V_177 ;
V_183 &= 0xE0 ;
V_177 &= 0x1F ;
V_177 = V_177 << 1 ;
V_177 += 1 ;
V_177 |= V_183 ;
F_4 ( V_3 -> V_109 , 0x2C , V_177 ) ;
}
}
}
static void F_29 ( struct V_2 * V_3 )
{
unsigned char V_105 ;
V_105 = F_2 ( V_3 -> V_125 , 0x37 ) ;
V_105 = ( V_105 & 1 ) << 6 ;
F_12 ( V_3 -> V_109 , 0x06 , ~ 0x40 , V_105 ) ;
F_12 ( V_3 -> V_109 , 0x09 , ~ 0xc0 , V_105 | 0x80 ) ;
}
static void F_30 ( unsigned short V_110 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_177 ;
V_177 = F_2 ( V_3 -> V_109 , 0x3D ) ;
V_177 &= 0xfe ;
F_4 ( V_3 -> V_109 , 0x3D , V_177 ) ;
F_4 ( V_3 -> V_109 , 0x08 , 0x34 ) ;
V_177 = F_2 ( V_3 -> V_109 , 0x09 ) ;
V_177 &= 0xC0 ;
F_4 ( V_3 -> V_109 , 0x09 , V_177 | 0x30 ) ;
V_177 = F_2 ( V_3 -> V_109 , 0x3D ) ;
V_177 |= 0x01 ;
F_4 ( V_3 -> V_109 , 0x3D , V_177 ) ;
if ( V_123 -> V_181 == V_243 )
F_29 ( V_3 ) ;
}
static void F_31 ( struct V_122 * V_123 ,
unsigned short V_110 , unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_177 , V_244 = 0 ;
short V_245 ;
unsigned char V_183 ;
V_183 = V_3 -> V_10 [ V_139 ] . V_236 ;
V_183 &= V_185 ;
V_245 = V_3 -> V_22 [ V_183 ] . CLOCK ;
V_177 = F_2 ( V_3 -> V_109 , 0x32 ) ;
V_177 &= 0xf3 ;
if ( V_245 >= 200 )
V_177 |= 0x0c ;
if ( V_123 -> V_181 >= V_102 )
V_177 &= ~ 0x04 ;
F_4 ( V_3 -> V_109 , 0x32 , V_177 ) ;
if ( V_123 -> V_181 < V_102 ) {
V_177 = F_2 ( V_3 -> V_109 , 0x1F ) ;
V_177 &= 0xE7 ;
if ( V_245 < 200 )
V_177 |= 0x10 ;
F_4 ( V_3 -> V_109 , 0x1F , V_177 ) ;
}
V_244 = 0x00 ;
F_12 ( V_3 -> V_109 , 0x07 , 0xFC , V_244 ) ;
if ( V_123 -> V_181 >= V_104 )
F_12 ( V_3 -> V_109 , 0x40 , 0xFC , V_244 & 0x03 ) ;
}
static void F_32 ( struct V_122 * V_123 ,
unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_177 , V_244 , V_246 , V_143 = 0 , V_115 , V_205 ,
V_247 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_174 ;
if ( F_2 ( V_3 -> V_125 , 0x31 ) & 0x01 )
F_12 ( V_3 -> V_109 , 0x1F , 0x3F , 0x00 ) ;
V_177 = V_143 ;
V_244 = 0 ;
V_244 |= 0x02 ;
V_246 = V_3 -> V_135 - V_136 ;
V_246 = V_246 << 2 ;
V_244 |= V_246 ;
V_177 &= V_210 ;
if ( V_177 )
V_244 |= 0x20 ;
F_12 ( V_3 -> V_109 , 0x06 , ~ 0x3F , V_244 ) ;
V_205 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_247 = V_3 -> V_33 [ V_205 ] . V_207 ;
V_177 = 0x0000 ;
if ( V_143 & V_210 ) {
if ( V_247 == 1024 )
V_177 = 0x0035 ;
else if ( V_247 == 1280 )
V_177 = 0x0048 ;
}
V_244 = V_177 & 0x00FF ;
F_12 ( V_3 -> V_125 , 0x19 , 0xFF , V_244 ) ;
V_244 = ( V_177 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_125 , 0x19 , 0xFC , V_244 ) ;
if ( V_115 & V_209 )
F_12 ( V_3 -> V_109 , 0x01 , 0xF7 , 0x08 ) ;
V_244 = 0 ;
if ( V_115 & V_248 )
V_244 |= 0x08 ;
F_12 ( V_3 -> V_109 , 0x0F , ~ 0x48 , V_244 ) ;
V_177 = 0x60 ;
V_177 = V_177 ^ 0x60 ;
V_177 = V_177 ^ 0xA0 ;
F_12 ( V_3 -> V_109 , 0x21 , 0x1F , V_177 ) ;
F_31 ( V_123 , V_110 , V_139 ,
V_3 ) ;
V_177 = F_2 ( V_3 -> V_125 , 0x31 ) ;
if ( V_123 -> V_181 == V_104 ) {
if ( V_177 & 0x40 )
V_177 = 0x2c ;
else
V_177 = 0x6c ;
F_4 ( V_3 -> V_125 , 0x52 , V_177 ) ;
F_20 ( V_3 -> V_125 , 0x51 , 0x10 ) ;
} else if ( V_123 -> V_181 >= V_102 ) {
if ( V_177 & 0x40 )
V_177 = 0x33 ;
else
V_177 = 0x73 ;
F_4 ( V_3 -> V_125 , 0x52 , V_177 ) ;
F_4 ( V_3 -> V_125 , 0x51 , 0x02 ) ;
} else {
if ( V_177 & 0x40 )
V_177 = 0x2c ;
else
V_177 = 0x6c ;
F_4 ( V_3 -> V_125 , 0x52 , V_177 ) ;
}
}
static void F_33 ( unsigned short V_249 ,
unsigned short V_211 ,
unsigned short V_212 ,
unsigned short V_250 ,
struct V_2 * V_3 )
{
unsigned short V_105 , V_251 , V_252 ;
V_251 = V_211 ;
V_252 = V_212 ;
if ( V_249 != 0 ) {
V_105 = V_251 ;
V_251 = V_250 ;
V_250 = V_105 ;
if ( V_249 == 1 ) {
V_105 = V_252 ;
V_252 = V_250 ;
V_250 = V_105 ;
} else {
V_105 = V_252 ;
V_252 = V_251 ;
V_251 = V_105 ;
}
}
F_8 ( ( unsigned short ) V_250 , V_3 -> V_253 ) ;
F_8 ( ( unsigned short ) V_251 , V_3 -> V_253 ) ;
F_8 ( ( unsigned short ) V_252 , V_3 -> V_253 ) ;
}
static void F_34 ( unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_177 , V_244 , V_114 , V_254 , V_255 , V_256 , V_257 , V_258 , V_259 , V_260 , V_249 , V_212 , V_211 , V_250 ;
const unsigned short * V_261 = V_262 ;
F_8 ( 0xFF , V_3 -> V_263 ) ;
F_8 ( 0x00 , V_3 -> V_264 ) ;
for ( V_114 = 0 ; V_114 < 16 ; V_114 ++ ) {
V_177 = V_261 [ V_114 ] ;
for ( V_254 = 0 ; V_254 < 3 ; V_254 ++ ) {
V_244 = 0 ;
if ( V_177 & 0x01 )
V_244 = 0x2A ;
if ( V_177 & 0x02 )
V_244 += 0x15 ;
F_8 ( V_244 , V_3 -> V_253 ) ;
V_177 = V_177 >> 2 ;
}
}
for ( V_114 = 16 ; V_114 < 32 ; V_114 ++ ) {
V_177 = V_261 [ V_114 ] ;
for ( V_254 = 0 ; V_254 < 3 ; V_254 ++ )
F_8 ( V_177 , V_3 -> V_253 ) ;
}
V_258 = 32 ;
for ( V_255 = 0 ; V_255 < 9 ; V_255 ++ ) {
V_259 = V_258 ;
V_260 = V_258 + 0x04 ;
V_249 = 0 ;
for ( V_256 = 0 ; V_256 < 3 ; V_256 ++ ) {
for ( V_257 = 0 ; V_257 < 5 ; V_257 ++ ) {
V_250 = V_261 [ V_258 ] ;
V_211 = V_261 [ V_259 ] ;
V_212 = V_261 [ V_260 ] ;
V_258 ++ ;
F_33 ( V_249 , V_211 , V_212 , V_250 , V_3 ) ;
}
V_258 -= 2 ;
for ( V_257 = 0 ; V_257 < 3 ; V_257 ++ ) {
V_250 = V_261 [ V_260 ] ;
V_211 = V_261 [ V_259 ] ;
V_212 = V_261 [ V_258 ] ;
V_258 -- ;
F_33 ( V_249 , V_211 , V_212 , V_250 , V_3 ) ;
}
V_249 ++ ;
}
V_258 += 5 ;
}
}
static void F_35 ( unsigned short V_110 ,
unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_205 , V_247 , V_265 , V_115 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_205 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_247 = V_3 -> V_33 [ V_205 ] . V_207 ;
V_265 = V_3 -> V_33 [ V_205 ] . V_208 ;
if ( V_115 & V_209 )
V_247 = V_247 << 1 ;
if ( V_115 & V_182 )
V_265 = V_265 << 1 ;
if ( V_247 == 720 )
V_247 = 640 ;
V_3 -> V_266 = V_247 ;
V_3 -> V_267 = V_247 ;
V_3 -> V_268 = V_265 ;
V_3 -> V_269 = V_265 ;
}
static void * F_36 ( unsigned short V_270 , unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_114 , V_271 , V_206 , V_141 , V_272 , V_115 , V_261 ;
struct V_273 * V_274 = NULL ;
V_141 = V_270 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_272 = V_3 -> V_10 [ V_139 ] . V_219 ;
V_272 = V_272 & 0x0f ;
if ( V_141 <= 1 ) {
V_272 = V_3 -> V_10 [ V_139 ] . V_219 ;
if ( V_3 -> V_39 & V_118 ) {
V_272 = V_3 -> V_10 [ V_139 ] .
V_275 ;
}
if ( V_141 & 0x01 )
V_272 = ( V_272 >> 4 ) ;
V_272 = ( V_272 & 0x0f ) ;
}
V_206 = V_276 [ V_141 ] ;
if ( V_3 -> V_38 & V_277 ) {
if ( ( V_141 == 5 ) || ( V_141 ) == 7 )
V_206 = V_278 ;
else if ( ( V_141 == 3 ) || ( V_141 == 8 ) )
V_206 = V_279 ;
}
switch ( V_141 ) {
case 0 :
case 1 :
V_274 = V_280 ;
break;
case 2 :
V_274 = V_281 ;
break;
case 3 :
V_274 = V_282 ;
break;
case 4 :
V_274 = V_283 ;
break;
case 5 :
V_274 = V_284 ;
break;
case 6 :
V_274 = V_285 ;
break;
case 7 :
case 8 :
case 9 :
V_274 = NULL ;
break;
default:
break;
}
if ( V_274 == NULL )
return NULL ;
V_261 = V_141 ;
V_114 = 0 ;
while ( V_274 [ V_114 ] . V_286 != 0xff ) {
V_271 = V_3 -> V_36 ;
if ( V_141 & 0x0080 ) {
V_141 &= ( ~ 0x0080 ) ;
V_271 = V_3 -> V_37 ;
}
if ( V_3 -> V_38 & V_277 )
V_271 &= ( ~ V_287 ) ;
if ( V_274 [ V_114 ] . V_286 == V_271 ) {
V_141 = V_274 [ V_114 ] . V_288 ;
V_271 = V_3 -> V_38 ;
if ( V_115 & V_209 )
V_271 |= V_289 ;
V_141 &= V_271 ;
if ( V_141 == V_274 [ V_114 ] . V_290 )
break;
}
V_114 ++ ;
}
if ( V_261 == 0 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_292 [ V_272 ] ;
break;
case 1 :
return & V_293 [ V_272 ] ;
break;
case 2 :
return & V_294 [ V_272 ] ;
break;
case 3 :
return & V_295 [ V_272 ] ;
break;
case 4 :
return & V_296 [ V_272 ] ;
break;
case 5 :
return & V_297 [ V_272 ] ;
break;
case 6 :
return & V_298 [ V_272 ] ;
break;
case 7 :
return & V_299 [ V_272 ] ;
break;
case 8 :
return & V_300 [ V_272 ] ;
break;
case 9 :
return & V_301 [ V_272 ] ;
break;
case 10 :
return & V_302 [ V_272 ] ;
break;
default:
break;
}
} else if ( V_261 == 1 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_303 [ V_272 ] ;
break;
case 1 :
return & V_304 [ V_272 ] ;
break;
case 2 :
return & V_305 [ V_272 ] ;
break;
case 3 :
return & V_306 [ V_272 ] ;
break;
case 4 :
return & V_307 [ V_272 ] ;
break;
case 5 :
return & V_308 [ V_272 ] ;
break;
case 6 :
return & V_309 [ V_272 ] ;
break;
case 7 :
return & V_310 [ V_272 ] ;
break;
case 8 :
return & V_311 [ V_272 ] ;
break;
case 9 :
return & V_312 [ V_272 ] ;
break;
case 10 :
return & V_313 [ V_272 ] ;
break;
default:
break;
}
} else if ( V_261 == 2 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_314 [ V_272 ] ;
break;
case 1 :
return & V_315 [ V_272 ] ;
break;
case 2 :
return & V_316 [ V_272 ] ;
break;
case 3 :
return & V_317 [ V_272 ] ;
break;
case 4 :
return & V_318 [ V_272 ] ;
break;
case 5 :
return & V_319 [ V_272 ] ;
break;
case 6 :
return & V_320 [ V_272 ] ;
break;
case 7 :
return & V_321 [ V_272 ] ;
break;
case 8 :
return & V_322 [ V_272 ] ;
break;
case 9 :
return & V_323 [ V_272 ] ;
break;
case 10 :
return & V_324 [ V_272 ] ;
break;
case 11 :
return & V_325 [ V_272 ] ;
break;
case 12 :
return & V_326 [ V_272 ] ;
break;
default:
break;
}
} else if ( V_261 == 3 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_327 [ V_272 ] ;
break;
case 1 :
return & V_328 [ V_272 ] ;
break;
case 2 :
return & V_329 [ V_272 ] ;
break;
case 3 :
return & V_330 [ V_272 ] ;
break;
case 4 :
return & V_331 [ V_272 ] ;
break;
case 5 :
return & V_332 [ V_272 ] ;
break;
case 6 :
return & V_333 [ V_272 ] ;
break;
case 7 :
return & V_334 [ V_272 ] ;
break;
case 8 :
return & V_335 [ V_272 ] ;
break;
case 9 :
return & V_336 [ V_272 ] ;
break;
case 10 :
return & V_337 [ V_272 ] ;
break;
case 11 :
return & V_338 [ V_272 ] ;
break;
case 12 :
return & V_339 [ V_272 ] ;
break;
case 13 :
return & V_340 [ V_272 ] ;
break;
case 14 :
return & V_341 [ V_272 ] ;
break;
default:
break;
}
} else if ( V_261 == 4 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_342 [ V_272 ] ;
break;
case 1 :
return & V_343 [ V_272 ] ;
break;
case 2 :
return & V_344 [ V_272 ] ;
break;
case 3 :
return & V_345 [ V_272 ] ;
break;
case 4 :
return & V_346 [ V_272 ] ;
break;
case 5 :
return & V_347 [ V_272 ] ;
break;
case 6 :
case 7 :
return & V_348 [ V_272 ] ;
break;
case 8 :
return & V_349 [ V_272 ] ;
break;
case 9 :
return & V_350 [ V_272 ] ;
break;
case 10 :
return & V_351 [ V_272 ] ;
break;
case 11 :
return & V_352 [ V_272 ] ;
break;
case 12 :
return & V_353 [ V_272 ] ;
break;
case 13 :
return & V_353 [ V_272 ] ;
break;
case 14 :
return & V_354 [ V_272 ] ;
break;
case 15 :
case 16 :
return & V_355 [ V_272 ] ;
break;
case 17 :
return & V_356 [ V_272 ] ;
break;
case 18 :
return & V_357 [ V_272 ] ;
break;
default:
break;
}
} else if ( V_261 == 5 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_358 [ V_272 ] ;
break;
case 1 :
return & V_359 [ V_272 ] ;
break;
case 2 :
return & V_360 [ V_272 ] ;
break;
case 3 :
if ( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) )
return & V_361 [ V_272 ] ;
else
return & V_362 [ V_272 ] ;
break;
case 4 :
if ( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) )
return & V_363 [ V_272 ] ;
else
return & V_364 [ V_272 ] ;
break;
case 5 :
if ( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) )
return & V_365 [ V_272 ] ;
else
return & V_366 [ V_272 ] ;
break;
case 6 :
case 7 :
if ( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) )
return & V_367 [ V_272 ] ;
else
return & V_368 [ V_272 ] ;
break;
case 8 :
return & V_369 [ V_272 ] ;
break;
case 9 :
return & V_370 [ V_272 ] ;
break;
case 10 :
if ( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) )
return & V_371 [ V_272 ] ;
else
return & V_372 [ V_272 ] ;
break;
case 11 :
if ( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) )
return & V_373 [ V_272 ] ;
else
return & V_374 [ V_272 ] ;
break;
case 12 :
return & V_375 [ V_272 ] ;
break;
case 13 :
case 14 :
return & V_376 [ V_272 ] ;
break;
case 15 :
return & V_377 [ V_272 ] ;
break;
case 16 :
case 17 :
if ( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) )
return & V_378 [ V_272 ] ;
else
return & V_379 [ V_272 ] ;
break;
case 18 :
if ( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) )
return & V_380 [ V_272 ] ;
else
return & V_381 [ V_272 ] ;
break;
case 19 :
return & V_382 [ V_272 ] ;
break;
default:
break;
}
} else if ( V_261 == 6 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_383 [ V_272 ] ;
break;
case 1 :
return & V_384 [ V_272 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void * F_37 ( unsigned short V_270 , unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_114 , V_271 , V_141 , V_272 , V_115 , V_261 ;
struct V_385 * V_274 = NULL ;
V_141 = V_270 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_272 = V_3 -> V_10 [ V_139 ] . V_219 ;
V_272 = V_272 & 0x3f ;
V_261 = V_141 ;
switch ( V_141 ) {
case 0 :
V_274 = NULL ;
break;
case 1 :
V_274 = NULL ;
break;
case 2 :
case 6 :
V_274 = V_386 ;
break;
case 3 :
V_274 = NULL ;
break;
case 4 :
V_274 = V_387 ;
break;
case 5 :
V_274 = NULL ;
break;
default:
break;
}
if ( V_274 == NULL )
return NULL ;
V_271 = V_3 -> V_40 ;
if ( V_3 -> V_39 & V_121 )
V_271 = V_271 | V_388 ;
if ( V_115 & V_209 )
V_271 = V_271 | V_389 ;
V_114 = 0 ;
while ( V_274 [ V_114 ] . V_288 != 0xffff ) {
if ( ( V_271 & V_274 [ V_114 ] . V_288 ) == V_274 [ V_114 ] . V_290 )
break;
V_114 ++ ;
}
if ( V_261 == 0x04 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_390 [ V_272 ] ;
break;
case 1 :
return & V_391 [ V_272 ] ;
break;
case 2 :
return & V_392 [ V_272 ] ;
break;
case 3 :
return & V_393 [ V_272 ] ;
break;
case 4 :
return & V_394 [ V_272 ] ;
break;
case 5 :
return & V_395 [ V_272 ] ;
break;
case 6 :
return & V_396 [ V_272 ] ;
break;
case 7 :
return & V_397 [ V_272 ] ;
break;
case 8 :
return & V_398 [ V_272 ] ;
break;
case 9 :
return & V_399 [ V_272 ] ;
break;
case 10 :
return & V_400 [ V_272 ] ;
break;
case 11 :
return & V_401 [ V_272 ] ;
break;
case 12 :
return & V_391 [ V_272 ] ;
break;
case 13 :
return & V_402 [ V_272 ] ;
break;
default:
break;
}
} else if ( V_261 == 0x02 ) {
switch ( V_274 [ V_114 ] . V_291 ) {
case 0 :
return & V_403 [ V_272 ] ;
break;
case 1 :
return & V_404 [ V_272 ] ;
break;
case 2 :
return & V_405 [ V_272 ] ;
break;
case 3 :
return & V_406 [ V_272 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void F_38 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_141 ;
struct V_407 * V_408 = NULL ;
V_141 = 2 ;
if ( V_3 -> V_39 & ( V_120 | V_118 ) ) {
V_408 = (struct V_407 * ) F_36 ( V_141 ,
V_110 , V_111 , V_139 ,
V_3 ) ;
V_3 -> V_409 = V_408 -> V_409 ;
V_3 -> V_410 = V_408 -> V_410 ;
V_3 -> V_411 = V_408 -> V_412 ;
V_3 -> V_413 = V_408 -> V_414 ;
}
if ( V_3 -> V_39 & ( V_120 | V_118 ) ) {
if ( ! ( V_3 -> V_38 & ( V_415
| V_277 ) ) ) {
if ( ( V_3 -> V_36 == V_173 ) ||
( V_3 -> V_36 == V_416 ) ) {
V_3 -> V_267 = 1024 ;
V_3 -> V_269 = 768 ;
} else if ( ( V_3 -> V_36 == V_152 ) ||
( V_3 -> V_36 ==
V_417 ) ) {
V_3 -> V_267 = 1280 ;
V_3 -> V_269 = 1024 ;
} else if ( V_3 -> V_36 == V_418 ) {
V_3 -> V_267 = 1400 ;
V_3 -> V_269 = 1050 ;
} else {
V_3 -> V_267 = 1600 ;
V_3 -> V_269 = 1200 ;
}
}
}
}
static void F_39 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned char V_183 ;
unsigned short V_141 , V_114 ;
struct V_419 * V_408 = NULL ;
struct V_420 * V_421 = NULL ;
V_183 = V_3 -> V_10 [ V_139 ] . V_219 ;
V_183 = V_183 & V_185 ;
V_141 = 0 ;
if ( V_3 -> V_39 & ( V_120 | V_118 ) ) {
V_408 = (struct V_419 * )
F_36 ( V_141 , V_110 ,
V_111 ,
V_139 ,
V_3 ) ;
for ( V_114 = 0 ; V_114 < 8 ; V_114 ++ )
V_3 -> V_87 [ 0 ] . V_177 [ V_114 ] = V_408 [ 0 ] . V_422 [ V_114 ] ;
}
F_16 ( V_3 , V_123 ) ;
V_141 = 1 ;
if ( V_3 -> V_39 & ( V_120 | V_118 ) ) {
V_421 = (struct V_420 * )
F_36 (
V_141 ,
V_110 ,
V_111 ,
V_139 ,
V_3 ) ;
for ( V_114 = 0 ; V_114 < 7 ; V_114 ++ )
V_3 -> V_90 [ 0 ] . V_177 [ V_114 ] = V_421 [ 0 ] . V_422 [ V_114 ] ;
}
F_17 ( V_111 , V_110 , V_3 ) ;
}
static unsigned short F_40 ( struct V_2 * V_3 )
{
unsigned char V_272 , V_112 , V_423 , V_114 ;
V_112 = F_2 ( V_3 -> V_125 , 0x36 ) ;
V_272 = V_112 & 0x0F ;
V_112 = V_112 & 0xF0 ;
V_114 = 0 ;
V_423 = V_3 -> V_99 [ V_114 ] . V_424 ;
while ( V_423 != 0xFF ) {
if ( V_423 & 0x80 ) {
V_272 = V_112 ;
V_423 = V_423 & ~ ( 0x80 ) ;
}
if ( V_272 == V_423 )
break;
V_114 ++ ;
V_423 = V_3 -> V_99 [ V_114 ] . V_424 ;
}
return V_114 ;
}
static unsigned short F_41 ( struct V_2 * V_3 )
{
unsigned short V_112 , V_272 , V_423 , V_114 ;
V_272 = V_3 -> V_36 ;
V_112 = V_3 -> V_37 ;
V_114 = 0 ;
V_423 = V_3 -> V_99 [ V_114 ] . V_424 ;
while ( V_423 != 0xFF ) {
if ( ( V_423 & 0x80 ) && ( V_423 != 0x80 ) ) {
V_272 = V_112 ;
V_423 &= ~ 0x80 ;
}
if ( V_272 == V_423 )
break;
V_114 ++ ;
V_423 = V_3 -> V_99 [ V_114 ] . V_424 ;
}
if ( V_423 == 0xFF ) {
V_3 -> V_36 = V_173 ;
V_3 -> V_37 = 0 ;
V_114 = 0 ;
}
return V_114 ;
}
static void F_42 ( unsigned short * V_425 ,
unsigned short * V_426 ,
struct V_2 * V_3 )
{
unsigned short V_427 ;
V_427 = F_40 ( V_3 ) ;
* V_425 = V_3 -> V_99 [ V_427 ] . V_428 ;
* V_426 = V_3 -> V_99 [ V_427 ] . V_429 ;
return;
}
static void F_43 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_141 , V_140 , V_206 , V_271 , V_430 , V_431 , V_115 ;
unsigned long V_105 , V_432 , V_213 , V_433 , V_434 ;
struct V_435 * V_408 = NULL ;
struct V_436 * V_421 = NULL ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_141 = 3 ;
if ( V_3 -> V_38 & V_277 )
V_421 =
(struct V_436 * )
F_36 (
V_141 ,
V_110 ,
V_111 ,
V_139 ,
V_3 ) ;
else
V_408 =
(struct V_435 * )
F_36 (
V_141 ,
V_110 ,
V_111 ,
V_139 ,
V_3 ) ;
F_42 ( & V_140 , & V_141 , V_3 ) ;
V_430 = V_141 ;
V_431 = V_140 ;
if ( ( V_3 -> V_36 == V_173 ) ||
( V_3 -> V_36 == V_416 ) ) {
V_140 = 1024 ;
V_141 = 768 ;
} else if ( ( V_3 -> V_36 == V_152 ) ||
( V_3 -> V_36 == V_417 ) ) {
V_140 = 1280 ;
V_141 = 1024 ;
} else if ( V_3 -> V_36 == V_418 ) {
V_140 = 1400 ;
V_141 = 1050 ;
} else {
V_140 = 1600 ;
V_141 = 1200 ;
}
if ( V_3 -> V_38 & V_415 ) {
V_3 -> V_267 = V_140 ;
V_3 -> V_269 = V_141 ;
V_3 -> V_266 = V_140 ;
V_3 -> V_268 = V_141 ;
}
V_140 = V_3 -> V_411 ;
if ( V_3 -> V_38 & V_277 )
V_141 = V_421 -> V_437 ;
else
V_141 = V_408 -> V_437 ;
V_206 = V_3 -> V_267 ;
V_141 = V_141 & 0x0fff ;
V_206 += V_141 ;
if ( V_206 >= V_140 )
V_206 -= V_140 ;
F_4 ( V_3 -> V_438 , 0x1A , V_141 & 0x07 ) ;
V_206 = V_206 >> 3 ;
V_141 = V_141 >> 3 ;
F_4 ( V_3 -> V_438 , 0x16 ,
( unsigned short ) ( V_141 & 0xff ) ) ;
F_4 ( V_3 -> V_438 , 0x17 ,
( unsigned short ) ( V_206 & 0xff ) ) ;
V_140 = V_3 -> V_411 ;
if ( V_3 -> V_38 & V_277 )
V_141 = V_421 -> V_439 ;
else
V_141 = V_408 -> V_439 ;
V_206 = V_431 ;
if ( V_3 -> V_38 & V_277 )
V_206 = V_421 -> V_440 ;
V_206 += V_141 ;
if ( V_206 >= V_140 )
V_206 -= V_140 ;
V_140 = V_141 & 0x07 ;
V_140 = V_140 >> 5 ;
V_206 = V_206 >> 3 ;
V_141 = V_141 >> 3 ;
V_206 &= 0x1f ;
V_140 |= V_206 ;
F_4 ( V_3 -> V_438 , 0x15 , V_140 ) ;
F_4 ( V_3 -> V_438 , 0x14 ,
( unsigned short ) ( V_141 & 0xff ) ) ;
V_140 = V_3 -> V_413 ;
if ( V_3 -> V_38 & V_277 )
V_141 = V_421 -> V_441 ;
else
V_141 = V_408 -> V_441 ;
V_206 = V_3 -> V_269 ;
V_141 = V_141 & 0x0fff ;
V_206 += V_141 ;
if ( V_206 >= V_140 )
V_206 -= V_140 ;
F_4 ( V_3 -> V_438 , 0x1b ,
( unsigned short ) ( V_141 & 0xff ) ) ;
F_4 ( V_3 -> V_438 , 0x1c ,
( unsigned short ) ( V_206 & 0xff ) ) ;
V_141 = ( V_141 >> 8 ) & 0x07 ;
V_206 = ( V_206 >> 8 ) & 0x07 ;
F_4 ( V_3 -> V_438 , 0x1d ,
( unsigned short ) ( ( V_206 << 3 )
| V_141 ) ) ;
V_140 = V_3 -> V_413 ;
if ( V_3 -> V_38 & V_277 )
V_141 = V_421 -> V_442 ;
else
V_141 = V_408 -> V_442 ;
V_206 = V_430 ;
if ( V_3 -> V_38 & V_277 )
V_206 = V_421 -> V_443 ;
V_206 += V_141 ;
if ( V_206 >= V_140 )
V_206 -= V_140 ;
F_4 ( V_3 -> V_438 , 0x18 ,
( unsigned short ) ( V_141 & 0xff ) ) ;
F_12 ( V_3 -> V_438 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_206 & 0x0f ) ) ;
V_140 = ( ( V_141 >> 8 ) & 0x07 ) << 3 ;
V_141 = V_3 -> V_268 ;
if ( V_141 != V_3 -> V_269 )
V_140 |= 0x40 ;
if ( V_3 -> V_38 & V_444 )
V_140 |= 0x40 ;
F_12 ( V_3 -> V_438 , 0x1a , 0x07 ,
V_140 ) ;
V_206 = V_3 -> V_410 ;
V_141 = V_3 -> V_269 ;
V_140 = V_3 -> V_268 ;
V_206 -= V_140 ;
V_105 = V_140 ;
V_432 = ( V_105 << 18 ) / V_141 ;
V_271 = ( unsigned short ) ( ( V_105 << 18 ) % V_141 ) ;
if ( V_271 != 0 )
V_432 += 1 ;
V_213 = V_432 ;
V_434 = V_213 ;
F_4 ( V_3 -> V_438 , 0x37 ,
( unsigned short ) ( V_213 & 0xff ) ) ;
F_4 ( V_3 -> V_438 , 0x36 ,
( unsigned short ) ( ( V_213 >> 8 ) & 0xff ) ) ;
V_141 = ( unsigned short ) ( V_213 >> 16 ) ;
V_140 = V_141 & 0x03 ;
V_141 = V_3 -> V_268 ;
if ( V_141 == V_3 -> V_269 )
V_140 |= 0x04 ;
F_4 ( V_3 -> V_438 , 0x35 , V_140 ) ;
if ( V_3 -> V_96 & V_149 ) {
V_213 = V_434 ;
F_4 ( V_3 -> V_445 ,
0x3c ,
( unsigned short ) ( V_213 & 0xff ) ) ;
F_4 ( V_3 -> V_445 ,
0x3b ,
( unsigned short ) ( ( V_213 >> 8 ) &
0xff ) ) ;
V_141 = ( unsigned short ) ( V_213 >> 16 ) ;
F_12 ( V_3 -> V_445 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_141 &
0xff ) << 6 ) ) ;
V_206 = V_3 -> V_268 ;
if ( V_206 == V_3 -> V_269 )
F_12 ( V_3 -> V_445 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_12 ( V_3 -> V_445 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_206 = V_3 -> V_266 ;
V_141 = V_3 -> V_267 ;
V_432 = V_206 << 16 ;
V_140 = ( unsigned short ) ( V_432 / V_141 ) ;
if ( ( V_141 & 0xffff ) == ( V_206 & 0xffff ) )
V_140 = 65535 ;
V_433 = V_140 ;
V_432 = V_3 -> V_266 << 16 ;
V_432 /= V_433 ;
V_433 = V_433 << 16 ;
V_432 -= 1 ;
V_433 = ( V_433 & 0xffff0000 ) + ( V_432 & 0xffff ) ;
V_140 = ( unsigned short ) ( V_433 & 0xff ) ;
F_4 ( V_3 -> V_438 , 0x1f , V_140 ) ;
V_432 = V_3 -> V_268 << 18 ;
V_432 = V_432 / V_434 ;
V_141 = ( unsigned short ) ( V_432 & 0xffff ) ;
if ( V_3 -> V_36 == V_173 )
V_141 -= 1 ;
V_140 = ( ( V_141 >> 8 ) & 0xff ) << 3 ;
V_140 |= ( unsigned short ) ( ( V_433 >> 8 ) & 0x07 ) ;
F_4 ( V_3 -> V_438 , 0x20 ,
( unsigned short ) ( V_140 & 0xff ) ) ;
F_4 ( V_3 -> V_438 , 0x21 ,
( unsigned short ) ( V_141 & 0xff ) ) ;
V_433 = V_433 >> 16 ;
if ( V_115 & V_209 )
V_433 = V_433 >> 1 ;
F_4 ( V_3 -> V_438 , 0x22 ,
( unsigned short ) ( ( V_433 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 -> V_438 , 0x23 ,
( unsigned short ) ( V_433 & 0xff ) ) ;
}
static void F_44 ( unsigned char * V_446 , unsigned char * V_447 ,
struct V_2 * V_3 )
{
unsigned short V_183 ;
if ( V_3 -> V_39 & ( V_120 | V_118 ) ) {
V_183 = F_41 ( V_3 ) ;
if ( V_3 -> V_39 & V_120 ) {
* V_446 = V_3 -> V_99 [ V_183 ] . V_448 ;
* V_447 = V_3 -> V_99 [ V_183 ] . V_449 ;
} else {
* V_446 = V_3 -> V_99 [ V_183 ] . V_450 ;
* V_447 = V_3 -> V_99 [ V_183 ] . V_451 ;
}
}
return;
}
static unsigned char F_45 ( unsigned short V_139 ,
unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_183 , V_115 ;
unsigned char V_272 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
if ( ( V_3 -> V_160 & V_452 ) &&
( ! ( V_3 -> V_38 & V_277 ) ) ) {
V_183 = F_40 ( V_3 ) ;
V_272 = V_3 -> V_99 [ V_183 ] . V_453 ;
if ( V_3 -> V_39 & ( V_120 | V_118 ) )
return V_272 ;
if ( V_3 -> V_96 &
( V_167 |
V_168 |
V_97 |
V_98 |
V_149 ) ) {
if ( V_3 -> V_39 & V_155 ) {
V_272 = V_454 + V_224 ;
if ( ! ( V_3 -> V_40 & V_222 ) )
V_272 = V_454 + V_225 ;
if ( V_3 -> V_40 & V_161 ) {
V_272 = V_454 + V_226 ;
if ( ! ( V_115 & V_129 ) )
V_272 = V_454 +
V_227 ;
}
return V_272 ;
}
if ( V_3 -> V_40 & V_455 ) {
V_272 = V_229 ;
return V_272 ;
}
if ( V_3 -> V_40 & V_456 ) {
V_272 = V_231 ;
return V_272 ;
}
V_272 = V_457 ;
if ( ! ( V_3 -> V_40 & V_458 ) ) {
V_272 = V_454 + V_234 ;
if ( ! ( V_3 -> V_40 & V_222 ) )
V_272 = V_454 + V_235 ;
}
if ( V_3 -> V_39 & V_119 )
return V_272 ;
}
}
V_272 = ( unsigned char ) F_7 ( ( V_3 -> V_459 + 0x02 ) ) ;
V_272 = V_272 >> 2 ;
V_272 &= 0x03 ;
if ( ( V_3 -> V_38 & V_277 ) && ( V_115 & V_129 ) )
V_272 = V_272 ^ V_272 ;
V_272 = V_3 -> V_10 [ V_139 ] . V_236 ;
return V_272 ;
}
static void F_46 ( unsigned char V_272 , unsigned char * V_446 ,
unsigned char * V_447 , struct V_2 * V_3 )
{
if ( V_3 -> V_96 & ( V_460 | V_167 | V_168
| V_97 | V_98 | V_149 ) ) {
if ( ( ! ( V_3 -> V_39 & V_118 ) ) &&
( V_3 -> V_160 & V_452 ) ) {
* V_446 = ( unsigned char ) V_27 [ V_272 ] . V_137 ;
* V_447 = V_27 [ V_272 ] . V_138 ;
}
} else {
* V_446 = V_24 [ V_272 ] . V_137 ;
* V_447 = V_24 [ V_272 ] . V_138 ;
}
}
static void F_47 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned char V_446 , V_447 , V_272 ;
int V_114 ;
V_272 = F_45 ( V_139 , V_110 , V_111 ,
V_3 ) ;
F_46 ( V_272 , & V_446 , & V_447 , V_3 ) ;
F_44 ( & V_446 , & V_447 , V_3 ) ;
for ( V_114 = 0 ; V_114 < 4 ; V_114 ++ ) {
F_12 ( V_3 -> V_125 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_114 ) ) ;
if ( ( ! ( V_3 -> V_39 & V_118 ) )
&& ( ! ( V_3 -> V_39 & V_121 ) ) ) {
F_4 ( V_3 -> V_109 , 0x2e , V_446 ) ;
F_4 ( V_3 -> V_109 , 0x2f , V_447 ) ;
} else {
F_4 ( V_3 -> V_109 , 0x2b , V_446 ) ;
F_4 ( V_3 -> V_109 , 0x2c , V_447 ) ;
}
}
}
static void F_48 ( struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_461 , V_462 , V_105 , V_423 , V_140 ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
V_461 = 0 ;
V_462 = 0 ;
V_105 = F_2 ( V_3 -> V_109 , 0x01 ) ;
if ( ! ( V_105 & 0x20 ) ) {
V_105 = F_2 ( V_3 -> V_125 , 0x17 ) ;
if ( V_105 & 0x80 ) {
V_105 = F_2 ( V_3 -> V_125 , 0x53 ) ;
if ( ! ( V_105 & 0x40 ) )
V_461 |= V_463 ;
}
}
V_105 = F_2 ( V_3 -> V_438 , 0x2e ) ;
V_105 &= 0x0f ;
if ( ! ( V_105 == 0x08 ) ) {
V_140 = F_2 ( V_3 -> V_438 , 0x13 ) ;
if ( V_140 & 0x04 )
V_461 = V_461 | V_464 ;
V_105 &= 0x05 ;
if ( ! ( V_461 & V_464 ) )
if ( V_105 == 0x01 )
V_461 |= V_465 ;
if ( V_105 == 0x04 )
V_461 |= V_464 ;
if ( V_105 == 0x05 ) {
V_105 = F_2 ( V_3 -> V_466 , 0x00 ) ;
if ( ! ( V_105 & 0x08 ) )
V_462 |= V_467 ;
if ( ! ( V_105 & 0x04 ) )
V_462 |= V_468 ;
if ( V_105 & 0x02 )
V_462 |= V_469 ;
if ( V_3 -> V_39 & V_155 ) {
if ( V_105 & 0x01 )
V_462 |= V_470 ;
}
if ( V_3 -> V_39 & V_165 ) {
V_105 = F_2 (
V_3 -> V_466 ,
0x4d ) ;
if ( V_105 & 0x10 )
V_462 |= V_471 ;
}
if ( V_462 != 0 )
V_461 |= V_472 ;
}
}
V_105 = F_2 ( V_3 -> V_125 , 0x3d ) ;
if ( V_461 & V_464 ) {
if ( ( V_3 -> V_160 & V_473 ) ) {
if ( V_105 & V_472 )
V_461 |= V_472 ;
}
}
V_105 = V_461 ;
V_423 = ~ V_474 ;
F_12 ( V_3 -> V_125 , 0x3d , V_423 , V_105 ) ;
if ( ! ( V_3 -> V_160 & V_473 ) )
F_4 ( V_3 -> V_125 , 0x3e , V_462 ) ;
} else {
return;
}
}
void F_49 ( struct V_2 * V_3 )
{
unsigned short V_475 , V_141 , V_112 ;
if ( V_3 -> V_146 != 0 )
return;
V_141 = V_168 ;
V_475 = F_2 ( V_3 -> V_445 , 0x00 ) ;
if ( V_475 == 0x02 )
goto V_476;
V_141 = V_460 ;
V_475 = F_2 ( V_3 -> V_445 , 0x01 ) ;
if ( V_475 < 0xB0 )
goto V_476;
V_141 = V_167 ;
if ( V_475 < 0xC0 )
goto V_477;
V_141 = V_149 ;
if ( V_475 < 0xD0 )
goto V_477;
V_141 = V_97 ;
if ( V_475 < 0xE0 )
goto V_477;
V_141 = V_98 ;
V_112 = F_2 ( V_3 -> V_445 , 0x39 ) ;
if ( V_112 != 0xFF )
V_141 = V_149 ;
V_477:
if ( V_141 & ( V_167 | V_168 ) ) {
V_475 = F_2 ( V_3 -> V_445 , 0x23 ) ;
if ( ! ( V_475 & 0x02 ) )
V_141 = V_141 | V_478 ;
}
V_476:
V_3 -> V_96 = V_141 ;
}
static void F_50 ( unsigned short V_110 , unsigned short V_111 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_140 , V_479 , V_141 , V_105 , V_115 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_3 -> V_160 = 0 ;
V_3 -> V_135 = V_115 & V_480 ;
V_141 = 0 ;
if ( ! ( V_3 -> V_96 & 0xFFFF ) )
return;
V_105 = F_2 ( V_3 -> V_125 , 0x30 ) ;
V_141 = V_141 | V_105 ;
V_105 = F_2 ( V_3 -> V_125 , 0x31 ) ;
V_479 = V_105 ;
V_479 = V_479 << 8 ;
V_140 = V_105 << 8 ;
V_141 = V_141 | V_140 ;
V_105 = ( V_481 | V_165 | V_118
| V_121 | V_482 ) ;
V_105 = 0xFFFF ^ V_105 ;
V_141 &= V_105 ;
V_105 = F_2 ( V_3 -> V_125 , 0x38 ) ;
if ( V_3 -> V_483 == 1 ) {
if ( ( ( V_123 -> V_181 >= V_102 ) ||
( V_123 -> V_181 >= V_484 ) ) &&
( V_3 -> V_146 == 0 ) ) {
if ( V_3 -> V_96 &
( V_168 |
V_97 |
V_98 |
V_149 ) ) {
if ( V_105 & V_485 ) {
V_141 |= V_481 ;
if ( V_105 & V_486 )
V_141 |= V_118 ;
}
}
}
}
if ( V_3 -> V_487 == 1 ) {
if ( ( ( V_3 -> V_146 == 0 ) &&
( ( V_3 -> V_96 & V_97 ) ||
( V_3 -> V_96 & V_98 ) ||
( V_3 -> V_96 & V_149 ) ) ) ) {
if ( V_105 & V_488 ) {
if ( V_3 -> V_489 == 1 ) {
V_105 = F_2 (
V_3 -> V_125 ,
0x35 ) ;
V_105 &= V_490 ;
V_141 |= V_155 ;
if ( V_105 != V_491 ) {
V_141 &=
( ~ V_155 ) ;
V_141 |=
V_165 ;
}
}
}
}
}
V_140 = V_479 ;
if ( V_3 -> V_146 == 0 ) {
if ( V_3 -> V_487 == 1 ) {
if ( V_3 -> V_489 == 1 )
V_105 = 0x09FC ;
else
V_105 = 0x097C ;
} else {
if ( V_3 -> V_489 == 1 )
V_105 = 0x01FC ;
else
V_105 = 0x017C ;
}
} else {
V_105 = V_120 ;
}
if ( ! ( V_141 & V_105 ) ) {
V_140 |= V_482 ;
V_141 = 0 ;
}
if ( V_3 -> V_483 == 1 ) {
if ( ! ( V_3 -> V_96 & V_478 ) ) {
if ( V_141 & V_118 ) {
if ( V_141 & V_492 )
V_141 &= ( ~ ( V_120 |
V_147 |
V_493 ) ) ;
else
V_141 &= ( ~ ( V_120 |
V_147 |
V_119 |
V_493 ) ) ;
}
}
}
if ( ! ( V_141 & ( V_493 | V_492 ) ) ) {
if ( V_3 -> V_494 == 1 ) {
if ( V_141 & V_147 ) {
V_141 &= ( 0xFF00 |
V_147 |
V_493 |
V_492 ) ;
V_141 &= ( 0x00FF | ( ~ V_165 ) ) ;
}
} else {
V_141 &= ( ~ ( V_147 |
V_120 |
V_119 ) ) ;
}
}
if ( ! ( V_3 -> V_96 & V_478 ) ) {
if ( V_141 & V_120 ) {
V_141 &= ( 0xFF00 |
V_120 |
V_493 |
V_492 ) ;
V_141 &= ( 0x00FF | ( ~ V_165 ) ) ;
}
}
if ( V_141 & V_164 ) {
V_141 &= ( 0xFF00 |
V_164 |
V_493 |
V_492 ) ;
V_141 &= ( 0x00FF | ( ~ V_165 ) ) ;
}
if ( V_3 -> V_487 == 1 ) {
if ( V_141 & V_165 )
V_141 &= ( 0xFF00 |
V_493 |
V_492 ) ;
}
if ( V_3 -> V_489 == 1 ) {
if ( V_141 & V_155 )
V_141 &= ( 0xFF00 |
V_155 |
V_493 |
V_492 ) ;
}
if ( V_140 & V_482 ) {
if ( ! ( V_141 & ( V_493 | V_492 ) ) )
V_141 = V_482 ;
}
if ( ! ( V_141 & V_482 ) ) {
if ( ( ! ( V_141 & V_495 ) ) ||
( ! ( V_115 & V_496 ) ) ) {
if ( V_3 -> V_483 == 1 ) {
if ( ! ( V_141 & V_118 ) )
V_141 |= ( V_121 |
V_492 ) ;
}
}
if ( ( V_141 & V_121 ) &&
( V_141 & V_118 ) ) {
V_141 ^= ( V_120 |
V_118 |
V_481 ) ;
V_3 -> V_160 |= V_473 ;
}
}
V_3 -> V_39 = V_141 ;
}
static void F_51 ( unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_105 , V_141 = 0 , V_142 = 0 , V_115 , V_497 ;
V_141 = 0 ;
V_142 = 0 ;
if ( V_3 -> V_39 & V_119 ) {
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
if ( V_3 -> V_39 & V_119 ) {
V_105 = F_2 ( V_3 -> V_125 , 0x35 ) ;
V_141 = V_105 ;
if ( V_141 & V_170 ) {
V_141 &= ( V_498 |
V_499 |
V_500 |
V_170 ) ;
if ( V_141 & V_499 )
V_141 &= ~ V_170 ;
} else
V_141 &= ( V_498 |
V_501 |
V_170 ) ;
}
if ( V_3 -> V_146 == 0 ) {
if ( V_3 -> V_39 & V_164 )
V_141 |= V_170 ;
}
if ( V_3 -> V_487 == 1 ) {
if ( V_3 -> V_39 & V_165 ) {
V_497 = F_2 ( V_3 -> V_125 , 0x35 ) ;
V_497 &= V_490 ;
if ( V_497 == V_502 )
V_141 |= V_503 ;
if ( V_497 == V_504 )
V_141 = V_141 | V_456 ;
if ( V_497 == V_505 )
V_141 = V_141 | V_455 ;
}
}
if ( V_3 -> V_489 == 1 ) {
if ( V_3 -> V_39 & V_155 )
V_141 = V_141 | V_506 | V_170 ;
}
if ( V_3 -> V_146 == 0 ) {
if ( ( V_3 -> V_39 & V_121 ) &&
( ! ( V_3 -> V_39 & V_172 ) ) )
V_141 |= V_161 ;
if ( ! ( V_141 & V_170 ) &&
( V_115 > 13 ) &&
( V_142 == 8 ) )
V_141 |= V_458 ;
V_141 |= V_222 ;
if ( V_3 -> V_39 & V_155 ) {
if ( V_3 -> V_39 & V_121 )
V_141 &= ( ~ V_222 ) ;
} else {
if ( V_141 &
( V_456 | V_455 ) )
V_141 &= ( ~ V_222 ) ;
else if ( ! ( V_3 -> V_96 &
( V_167 |
V_168 |
V_97 |
V_98 |
V_149 ) ) ) {
if ( V_141 & V_161 )
V_141 &= ( ~ V_222 ) ;
}
}
}
}
V_3 -> V_40 = V_141 ;
}
static unsigned char F_52 ( unsigned short V_110 ,
unsigned short V_111 , struct V_2 * V_3 )
{
unsigned short V_105 , V_140 , V_141 , V_115 , V_142 = 0 , V_507 ;
V_3 -> V_36 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_38 = 0 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_105 = F_2 ( V_3 -> V_125 , 0x36 ) ;
V_141 = V_105 & 0x0F ;
if ( V_141 == 0 )
V_141 = V_173 ;
if ( ( V_141 == V_173 ) || ( V_141 == V_152 ) ) {
if ( V_3 -> V_39 & V_495 ) {
V_140 = F_2 ( V_3 -> V_125 , 0x33 ) ;
if ( V_3 -> V_39 & V_118 )
V_140 &= 0x0F ;
else
V_140 = V_140 >> 4 ;
if ( ( V_142 == 6 ) || ( V_142 == 9 ) ) {
if ( V_140 >= 3 )
V_141 |= V_508 ;
} else if ( ( V_142 == 7 ) || ( V_142 == 8 ) ) {
if ( V_140 >= 4 )
V_141 |= V_508 ;
}
}
}
V_3 -> V_36 = V_141 ;
if ( ! ( V_3 -> V_39 & ( V_120 | V_118 ) ) )
return 0 ;
V_141 = 0 ;
V_105 = F_2 ( V_3 -> V_125 , 0x37 ) ;
V_105 &= ( V_509 | V_154 | V_510 | V_511 ) ;
V_141 |= V_105 ;
V_507 = F_41 ( V_3 ) ;
V_140 = V_3 -> V_99 [ V_507 ] . V_512 ;
if ( V_3 -> V_146 == 0 ) {
if ( ( ( V_3 -> V_96 & V_98 ) || ( V_3 -> V_96
& V_149 ) ) && ( V_140 & V_513 ) ) {
V_141 |= V_514 ;
}
}
if ( V_3 -> V_146 == 0 ) {
if ( ( V_3 -> V_36 == V_418 ) && ( V_3 -> V_39
& V_120 ) && ( V_142 == 9 ) &&
( ! ( V_141 & V_277 ) ) )
V_141 |= V_415 ;
}
if ( V_3 -> V_515 == 1 ) {
if ( V_115 & V_209 ) {
if ( ! ( V_141 & V_415 ) ) {
V_141 |= V_444 ;
} else {
if ( V_3 -> V_36 == V_173 ) {
if ( V_142 == 4 ) {
V_141 |= V_444 ;
}
}
}
}
}
if ( V_3 -> V_39 & V_121 ) {
if ( V_3 -> V_39 & V_172 )
V_141 |= V_516 ;
} else {
V_141 |= V_516 ;
}
V_3 -> V_38 = V_141 ;
return 1 ;
}
unsigned char F_53 ( unsigned short V_110 ,
unsigned short * V_111 , struct V_2 * V_3 )
{
for ( * V_111 = 0 ; ; ( * V_111 ) ++ ) {
if ( V_3 -> V_7 [ * V_111 ] . V_517 == V_110 )
break;
if ( V_3 -> V_7 [ * V_111 ] . V_517 == 0xFF )
return 0 ;
}
return 1 ;
}
static unsigned char F_54 ( unsigned char V_518 )
{
unsigned char V_519 = 0 ;
unsigned char V_114 = 0 ;
for ( V_114 = 0 ; V_114 < 8 ; V_114 ++ ) {
V_519 = V_519 << 1 ;
V_519 |= ( V_518 >> V_114 ) & 1 ;
}
return V_519 ;
}
static unsigned char F_55 ( struct V_2 * V_3 )
{
unsigned char V_520 , V_105 ;
V_520 = F_2 ( V_3 -> V_125 , 0x4A ) ;
F_13 ( V_3 -> V_125 , 0x4A , ~ 0x23 ) ;
V_105 = F_2 ( V_3 -> V_125 , 0x48 ) ;
V_105 = F_54 ( V_105 ) ;
V_105 &= 0x23 ;
F_4 ( V_3 -> V_125 , 0x4A , V_520 ) ;
return V_105 ;
}
static unsigned char F_56 ( struct V_2 * V_3 )
{
unsigned char V_520 , V_521 , V_105 ;
V_520 = F_2 ( V_3 -> V_125 , 0x4A ) ;
F_13 ( V_3 -> V_125 , 0x4A , ~ 0x0C ) ;
V_105 = F_2 ( V_3 -> V_125 , 0x48 ) ;
V_105 &= 0x0C ;
V_105 >>= 2 ;
F_4 ( V_3 -> V_125 , 0x4A , V_520 ) ;
V_521 = F_2 ( V_3 -> V_125 , 0xB4 ) ;
V_105 |= ( ( V_521 & 0x04 ) << 3 ) ;
return V_105 ;
}
static void F_57 ( unsigned short V_522 , unsigned short V_423 ,
struct V_2 * V_3 )
{
unsigned char V_520 , V_105 ;
V_520 = F_2 ( V_3 -> V_125 , 0x4A ) ;
V_522 &= 0x23 ;
V_423 &= 0x23 ;
F_13 ( V_3 -> V_125 , 0x4A , ~ V_522 ) ;
if ( V_522 & 0x20 ) {
V_105 = ( V_423 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_125 , 0xB4 , ~ 0x02 , V_105 ) ;
}
V_105 = F_2 ( V_3 -> V_125 , 0x48 ) ;
V_105 = F_54 ( V_105 ) ;
V_105 &= ~ V_522 ;
V_105 |= V_423 ;
F_4 ( V_3 -> V_125 , 0x48 , V_105 ) ;
}
static void F_58 ( unsigned short V_522 , unsigned short V_423 ,
struct V_2 * V_3 )
{
unsigned char V_520 , V_105 ;
unsigned short V_523 , V_524 ;
V_523 = V_522 ;
V_524 = V_423 ;
V_523 &= 0x20 ;
V_524 &= 0x20 ;
V_523 >>= 3 ;
V_524 >>= 3 ;
if ( V_522 & 0x20 ) {
V_105 = ( V_423 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_125 , 0xB4 , ~ 0x02 , V_105 ) ;
}
F_12 ( V_3 -> V_125 , 0xB4 , ~ V_523 , V_524 ) ;
V_520 = F_2 ( V_3 -> V_125 , 0x4A ) ;
V_522 &= 0x03 ;
V_423 &= 0x03 ;
V_522 <<= 2 ;
V_423 <<= 2 ;
F_13 ( V_3 -> V_125 , 0x4A , ~ V_522 ) ;
F_12 ( V_3 -> V_125 , 0x48 , ~ V_522 , V_423 ) ;
}
static void F_59 ( struct V_525 * V_526 ,
unsigned short V_423 ,
struct V_2 * V_3 )
{
if ( V_423 == 1 )
F_60 ( V_526 -> V_527 . V_528 ) ;
if ( V_423 == 2 )
F_60 ( V_526 -> V_527 . V_529 ) ;
if ( V_423 == 3 )
F_60 ( V_526 -> V_527 . V_530 ) ;
if ( V_423 == 4 )
F_60 ( V_526 -> V_527 . V_531 ) ;
}
static void F_61 ( struct V_525 * V_526 ,
struct V_122 * V_532 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_109 , 0x01 , 0xDF , 0x00 ) ;
if ( V_532 -> V_181 == V_243 ) {
if ( V_3 -> V_146 == 1 ) {
if ( ! ( F_55 ( V_3 ) & 0x1 ) ) {
F_57 ( 0x01 , 0x01 , V_3 ) ;
F_59 ( V_526 , 2 , V_3 ) ;
}
if ( ! ( F_55 ( V_3 ) & 0x20 ) )
F_57 ( 0x20 , 0x20 , V_3 ) ;
F_59 ( V_526 , 3 , V_3 ) ;
F_57 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_57 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_532 -> V_181 == V_104 ) {
if ( V_3 -> V_146 == 1 ) {
if ( ! ( F_56 ( V_3 ) & 0x1 ) ) {
F_58 ( 0x01 , 0x01 , V_3 ) ;
F_59 ( V_526 , 2 , V_3 ) ;
}
if ( ! ( F_56 ( V_3 ) & 0x20 ) )
F_58 ( 0x20 , 0x20 , V_3 ) ;
F_59 ( V_526 , 3 , V_3 ) ;
F_58 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_58 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_62 ( struct V_525 * V_526 ,
struct V_122 * V_532 ,
struct V_2 * V_3 )
{
if ( V_532 -> V_181 == V_243 ) {
if ( V_3 -> V_146 == 1 ) {
F_57 ( 0x02 , 0x00 , V_3 ) ;
F_59 ( V_526 , 3 , V_3 ) ;
} else {
F_57 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_532 -> V_181 == V_104 ) {
if ( ( F_56 ( V_3 ) & 0x2 ) ) {
F_58 ( 0x02 , 0x00 , V_3 ) ;
F_59 ( V_526 , 3 , V_3 ) ;
}
if ( V_3 -> V_146 == 0 )
F_58 ( 0x20 , 0x00 , V_3 ) ;
}
F_12 ( V_3 -> V_109 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_63 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 -> V_130 ) & 0x01 ) )
break;
while ( ! ( F_7 ( V_3 -> V_130 ) & 0x01 ) )
break;
}
static void F_64 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_438 , 0x01 , 0x40 ) ;
}
static void F_65 ( unsigned short V_110 ,
struct V_2 * V_3 )
{
unsigned short V_432 , V_213 ;
F_4 ( V_3 -> V_125 , 0x34 , V_110 ) ;
V_432 = ( V_3 -> V_39 & V_121 ) >> 8 ;
V_213 = ~ ( V_121 >> 8 ) ;
F_12 ( V_3 -> V_125 , 0x31 , V_213 , V_432 ) ;
}
static void F_66 ( unsigned short V_110 ,
unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_247 , V_265 , V_115 , V_205 ;
V_205 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_247 = V_3 -> V_33 [ V_205 ] . V_207 ;
V_265 = V_3 -> V_33 [ V_205 ] . V_208 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
if ( V_115 & V_209 )
V_247 *= 2 ;
if ( V_115 & V_182 )
V_265 *= 2 ;
if ( ! ( V_3 -> V_39 & V_120 ) )
goto exit;
if ( V_3 -> V_146 == 0 ) {
if ( V_3 -> V_36 == V_533 ) {
if ( ! ( V_3 -> V_38 & V_516 ) ) {
if ( V_265 == 1024 )
V_265 = 1056 ;
}
}
if ( V_3 -> V_36 == V_152 ) {
if ( V_265 == 400 )
V_265 = 405 ;
else if ( V_265 == 350 )
V_265 = 360 ;
if ( V_3 -> V_38 & V_516 ) {
if ( V_265 == 360 )
V_265 = 375 ;
}
}
if ( V_3 -> V_36 == V_173 ) {
if ( ! ( V_3 -> V_38 & V_516 ) ) {
if ( ! ( V_3 -> V_38 & V_154 ) ) {
if ( V_265 == 350 )
V_265 = 357 ;
else if ( V_265 == 400 )
V_265 = 420 ;
else if ( V_265 == 480 )
V_265 = 525 ;
}
}
}
}
if ( V_247 == 720 )
V_247 = 640 ;
exit:
V_3 -> V_266 = V_247 ;
V_3 -> V_267 = V_247 ;
V_3 -> V_268 = V_265 ;
V_3 -> V_269 = V_265 ;
}
static unsigned char F_67 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_39 & ( V_120 | V_118 ) ) &&
( V_3 -> V_38 & V_514 ) )
return 1 ;
return 0 ;
}
static void F_68 ( unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_140 , V_141 , V_432 , V_213 , V_115 = 0 , V_206 ,
V_534 ;
V_3 -> V_535 = 1 ;
V_3 -> V_536 = 1 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_534 = V_3 -> V_10 [ V_139 ] . V_184 ;
V_534 &= V_185 ;
V_432 = ( unsigned short ) V_3 -> V_13 [ V_534 ] . V_186 [ 0 ] ;
V_213 = ( unsigned short ) V_3 -> V_13 [ V_534 ] . V_186 [ 5 ] ;
V_140 = ( V_432 & 0xFF ) | ( ( V_213 & 0x03 ) << 8 ) ;
V_141 = ( unsigned short ) V_3 -> V_13 [ V_534 ] . V_186 [ 8 ] ;
V_206 = ( unsigned short )
V_3 -> V_13 [ V_534 ] . V_186 [ 14 ] << 8 ;
V_206 &= 0x0100 ;
V_206 = V_206 << 2 ;
V_141 |= V_206 ;
V_432 = ( unsigned short ) V_3 -> V_13 [ V_534 ] . V_186 [ 9 ] ;
if ( V_432 & 0x01 )
V_141 |= 0x0100 ;
if ( V_432 & 0x20 )
V_141 |= 0x0200 ;
V_140 += 5 ;
if ( V_115 & V_129 )
V_140 *= 8 ;
else
V_140 *= 9 ;
V_3 -> V_409 = V_140 ;
V_3 -> V_411 = V_140 ;
V_141 ++ ;
V_3 -> V_410 = V_141 ;
V_3 -> V_413 = V_141 ;
}
static void F_69 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_140 = 0 , V_141 , V_115 , V_142 ;
struct V_537 * V_408 = NULL ;
struct V_538 * V_539 = NULL ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_3 -> V_540 = 0 ;
V_3 -> V_541 = 50 ;
if ( V_3 -> V_39 & V_147 ) {
F_68 ( V_110 , V_111 , V_139 ,
V_3 ) ;
return;
}
V_141 = 4 ;
if ( V_3 -> V_39 & ( V_120 | V_118 ) ) {
V_408 = (struct V_537 * ) F_36 ( V_141 ,
V_110 , V_111 , V_139 ,
V_3 ) ;
V_3 -> V_535 = V_408 -> V_535 ;
V_3 -> V_536 = V_408 -> V_536 ;
V_3 -> V_409 = V_408 -> V_409 ;
V_3 -> V_410 = V_408 -> V_410 ;
V_3 -> V_411 = V_408 -> V_412 ;
V_3 -> V_413 = V_408 -> V_414 ;
if ( V_3 -> V_36 == V_173 ) {
V_140 = 1024 ;
V_141 = 768 ;
if ( ! ( V_3 -> V_38 & V_516 ) ) {
if ( V_3 -> V_268 == 357 )
V_141 = 527 ;
else if ( V_3 -> V_268 == 420 )
V_141 = 620 ;
else if ( V_3 -> V_268 == 525 )
V_141 = 775 ;
else if ( V_3 -> V_268 == 600 )
V_141 = 775 ;
else
V_141 = 768 ;
} else
V_141 = 768 ;
} else if ( V_3 -> V_36 == V_416 ) {
V_140 = 1024 ;
V_141 = 768 ;
} else if ( V_3 -> V_36 == V_152 ) {
V_140 = 1280 ;
if ( V_3 -> V_268 == 360 )
V_141 = 768 ;
else if ( V_3 -> V_268 == 375 )
V_141 = 800 ;
else if ( V_3 -> V_268 == 405 )
V_141 = 864 ;
else
V_141 = 1024 ;
} else if ( V_3 -> V_36 == V_417 ) {
V_140 = 1280 ;
V_141 = 1024 ;
} else if ( V_3 -> V_36 == V_153 ) {
V_140 = 1280 ;
if ( V_3 -> V_268 == 350 )
V_141 = 700 ;
else if ( V_3 -> V_268 == 400 )
V_141 = 800 ;
else if ( V_3 -> V_268 == 1024 )
V_141 = 960 ;
else
V_141 = 960 ;
} else if ( V_3 -> V_36 == V_418 ) {
V_140 = 1400 ;
V_141 = 1050 ;
if ( V_3 -> V_268 == 1024 ) {
V_140 = 1280 ;
V_141 = 1024 ;
}
} else if ( V_3 -> V_36 == V_533 ) {
V_140 = 1600 ;
V_141 = 1200 ;
if ( ! ( V_3 -> V_38 & V_516 ) ) {
if ( V_3 -> V_268 == 350 )
V_141 = 875 ;
else if ( V_3 -> V_268 == 400 )
V_141 = 1000 ;
}
}
if ( V_3 -> V_38 & V_154 ) {
V_140 = V_3 -> V_266 ;
V_141 = V_3 -> V_268 ;
}
V_3 -> V_267 = V_140 ;
V_3 -> V_269 = V_141 ;
return;
}
if ( V_3 -> V_39 & ( V_119 ) ) {
V_141 = 4 ;
V_539 = (struct V_538 * ) F_37 ( V_141 ,
V_110 , V_111 , V_139 ,
V_3 ) ;
V_3 -> V_535 = V_539 -> V_535 ;
V_3 -> V_536 = V_539 -> V_536 ;
V_3 -> V_409 = V_539 -> V_409 ;
V_3 -> V_410 = V_539 -> V_410 ;
V_3 -> V_267 = V_539 -> V_542 ;
V_3 -> V_269 = V_539 -> V_543 ;
V_3 -> V_541 = V_539 -> V_541 ;
V_3 -> V_540 = V_539 -> V_544 ;
if ( V_3 -> V_39 & V_155 ) {
if ( V_142 == 0x08 )
V_3 -> V_540 = 0x40 ;
else if ( V_142 == 0x09 )
V_3 -> V_540 = 0x40 ;
else if ( V_142 == 0x12 )
V_3 -> V_540 = 0x40 ;
if ( V_3 -> V_268 == 350 )
V_3 -> V_40 |= V_161 ;
V_140 = V_545 ;
V_141 = V_546 ;
if ( V_3 -> V_39 & V_121 ) {
if ( V_3 -> V_40 & V_161 ) {
V_140 = V_547 ;
V_141 = V_548 ;
if ( ! ( V_115 & V_129 ) ) {
V_140 = V_549 ;
V_141 = V_550 ;
}
}
}
} else if ( V_3 -> V_39 & V_165 ) {
if ( V_3 -> V_40 & V_455 ) {
V_140 = V_551 ;
V_141 = V_552 ;
}
if ( V_3 -> V_40 & V_456 ) {
V_140 = V_553 ;
V_141 = V_554 ;
} else if ( V_3 -> V_40 & V_503 ) {
V_140 = V_555 ;
V_141 = V_556 ;
if ( V_3 -> V_40 & V_458 )
V_140 = V_557 ;
}
} else {
V_140 = V_558 ;
V_141 = V_559 ;
if ( ! ( V_3 -> V_40 & V_170 ) ) {
V_140 = V_560 ;
V_141 = V_561 ;
if ( V_3 -> V_40 & V_458 )
V_140 = V_557 ;
}
}
V_3 -> V_411 = V_140 ;
V_3 -> V_413 = V_141 ;
return;
}
}
static void F_70 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned char V_446 , V_447 , V_272 ;
V_272 = F_45 ( V_139 , V_110 , V_111 ,
V_3 ) ;
F_46 ( V_272 , & V_446 , & V_447 , V_3 ) ;
F_44 ( & V_446 , & V_447 , V_3 ) ;
if ( V_3 -> V_96 & V_460 ) {
F_4 ( V_3 -> V_445 , 0x0A , 0x10 ) ;
F_4 ( V_3 -> V_445 , 0x0B , V_447 ) ;
F_4 ( V_3 -> V_445 , 0x0A , V_446 ) ;
} else {
F_4 ( V_3 -> V_445 , 0x0A , V_446 ) ;
F_4 ( V_3 -> V_445 , 0x0B , V_447 ) ;
}
F_4 ( V_3 -> V_445 , 0x00 , 0x12 ) ;
if ( V_3 -> V_39 & V_147 )
F_20 ( V_3 -> V_445 , 0x12 , 0x28 ) ;
else
F_20 ( V_3 -> V_445 , 0x12 , 0x08 ) ;
}
static unsigned short F_71 ( unsigned short V_110 ,
unsigned short V_111 , struct V_2 * V_3 )
{
unsigned short V_562 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_183 ;
unsigned short V_115 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_183 = ( V_115 & V_480 ) - V_216 ;
if ( V_183 < 0 )
V_183 = 0 ;
return V_562 [ V_183 ] ;
}
static unsigned short F_72 ( unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_105 , V_563 , V_564 , V_183 , V_143 ,
V_562 [] = { 0x01 , 0x02 , 0x04 } ;
V_564 = V_3 -> V_7 [ V_111 ] . V_215 ;
V_143 = V_3 -> V_10 [ V_139 ] . V_174 ;
V_183 = ( V_564 >> 8 ) & 0xFF ;
V_105 = V_3 -> V_28 [ V_183 ] ;
if ( V_143 & V_210 )
V_105 = V_105 << 1 ;
V_563 = F_71 ( V_110 , V_111 , V_3 ) ;
if ( ( V_110 >= 0x7C ) && ( V_110 <= 0x7E ) ) {
V_105 = V_110 - 0x7C ;
V_563 = V_562 [ V_105 ] ;
V_105 = 0x6B ;
if ( V_143 & V_210 )
V_105 = V_105 << 1 ;
return V_105 * V_563 ;
} else {
return V_105 * V_563 ;
}
}
static void F_73 ( unsigned short V_110 ,
unsigned short V_111 ,
unsigned short V_139 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_565 ;
unsigned char V_105 ;
if ( V_3 -> V_39 & V_121 )
return;
V_565 = F_72 ( V_110 , V_111 , V_139 ,
V_123 , V_3 ) ;
V_105 = ( unsigned char ) ( V_565 & 0xFF ) ;
F_4 ( V_3 -> V_438 , 0x07 , V_105 ) ;
V_105 = ( unsigned char ) ( ( V_565 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_438 , 0x09 , V_105 ) ;
V_105 = ( unsigned char ) ( ( ( V_565 >> 3 ) & 0xFF ) + 1 ) ;
F_4 ( V_3 -> V_438 , 0x03 , V_105 ) ;
}
static void F_74 ( struct V_2 * V_3 )
{
F_4 ( V_3 -> V_438 , 0x01 , 0x3B ) ;
F_12 ( V_3 -> V_438 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_75 ( unsigned short V_110 , unsigned short V_111 ,
struct V_122 * V_123 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_206 = 0 , V_534 = 0 , V_142 = 0 ;
V_534 = V_3 -> V_10 [ V_139 ] . V_184 ;
V_534 &= V_185 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
F_73 ( V_110 , V_111 , V_139 ,
V_123 , V_3 ) ;
F_74 ( V_3 ) ;
for ( V_206 = 4 ; V_206 < 7 ; V_206 ++ )
F_4 ( V_3 -> V_438 , V_206 , 0x0 ) ;
F_4 ( V_3 -> V_438 , 0x50 , 0x00 ) ;
F_4 ( V_3 -> V_438 , 0x02 , 0x44 ) ;
}
static void F_76 ( unsigned short V_110 , unsigned short V_111 ,
struct V_122 * V_123 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_105 = 0 , V_140 = 0 , V_141 = 0 , V_206 = 0 ,
V_566 = 0 , V_534 = 0 , V_115 , V_142 = 0 ;
V_534 = V_3 -> V_10 [ V_139 ] . V_184 ;
V_534 &= V_185 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
if ( V_115 & V_209 ) {
V_105 = ( V_3 -> V_409 / 2 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_438 , 0x08 , V_105 ) ;
V_105 = ( ( ( V_3 -> V_409 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_438 , 0x09 , ~ 0x0F0 , V_105 ) ;
V_105 = ( V_3 -> V_266 / 2 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_438 , 0x0A , V_105 ) ;
V_206 = ( ( V_3 -> V_409 - V_3 -> V_266 ) / 2 ) >> 2 ;
V_566 = V_3 -> V_266 / 2 + 16 ;
V_206 = V_206 >> 1 ;
V_141 = V_566 + V_206 ;
V_206 += V_141 ;
if ( V_3 -> V_39 & V_147 ) {
V_141 = V_3 -> V_13 [ V_534 ] . V_186 [ 4 ] ;
V_141 |= ( ( V_3 ->
V_13 [ V_534 ] . V_186 [ 14 ] &
0xC0 ) << 2 ) ;
V_141 = ( V_141 - 3 ) << 3 ;
V_206 = V_3 -> V_13 [ V_534 ] . V_186 [ 5 ] ;
V_206 &= 0x1F ;
V_105 = V_3 -> V_13 [ V_534 ] . V_186 [ 15 ] ;
V_105 = ( V_105 & 0x04 ) << ( 5 - 2 ) ;
V_206 = ( ( V_206 | V_105 ) - 3 ) << 3 ;
}
V_141 += 4 ;
V_206 += 4 ;
if ( V_206 > ( V_3 -> V_409 / 2 ) )
V_206 = V_3 -> V_409 / 2 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x0B , V_105 ) ;
} else {
V_105 = ( V_3 -> V_409 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_438 , 0x08 , V_105 ) ;
V_105 = ( ( ( V_3 -> V_409 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_438 , 0x09 , ~ 0x0F0 , V_105 ) ;
V_105 = ( V_3 -> V_266 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_438 , 0x0A , V_105 ) ;
V_206 = ( V_3 -> V_409 - V_3 -> V_266 ) >> 2 ;
V_566 = V_3 -> V_266 + 16 ;
V_206 = V_206 >> 1 ;
V_141 = V_566 + V_206 ;
V_206 += V_141 ;
if ( V_3 -> V_39 & V_147 ) {
V_141 = V_3 -> V_13 [ V_534 ] . V_186 [ 3 ] ;
V_141 |= ( ( V_3 ->
V_13 [ V_534 ] . V_186 [ 5 ] &
0xC0 ) << 2 ) ;
V_141 = ( V_141 - 3 ) << 3 ;
V_206 = V_3 -> V_13 [ V_534 ] . V_186 [ 4 ] ;
V_206 &= 0x1F ;
V_105 = V_3 -> V_13 [ V_534 ] . V_186 [ 6 ] ;
V_105 = ( V_105 & 0x04 ) << ( 5 - 2 ) ;
V_206 = ( ( V_206 | V_105 ) - 3 ) << 3 ;
V_141 += 16 ;
V_206 += 16 ;
}
if ( V_206 > V_3 -> V_409 )
V_206 = V_3 -> V_409 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x0B , V_105 ) ;
}
V_140 = ( V_140 & 0x00FF ) | ( V_141 & 0xFF00 ) ;
V_141 = V_566 ;
V_141 = ( V_141 & 0x00FF ) | ( ( V_141 & 0xFF00 ) << 4 ) ;
V_140 |= ( V_141 & 0xFF00 ) ;
V_105 = ( V_140 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_438 , 0x0C , V_105 ) ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x0D , V_105 ) ;
V_206 = ( V_3 -> V_410 - 1 ) ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x0E , V_105 ) ;
V_141 = V_3 -> V_268 - 1 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x0F , V_105 ) ;
V_105 = ( ( V_141 & 0xFF00 ) << 3 ) >> 8 ;
V_105 |= ( ( V_206 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_438 , 0x12 , V_105 ) ;
V_140 = V_3 -> V_268 ;
V_141 = V_3 -> V_268 ;
V_206 = V_3 -> V_410 ;
V_141 = ( V_3 -> V_410 + V_3 -> V_268 ) >> 1 ;
V_206 = ( ( V_3 -> V_410 - V_3 -> V_268 ) >> 4 ) + V_141 + 1 ;
if ( V_3 -> V_39 & V_147 ) {
V_141 = V_3 -> V_13 [ V_534 ] . V_186 [ 10 ] ;
V_105 = V_3 -> V_13 [ V_534 ] . V_186 [ 9 ] ;
if ( V_105 & 0x04 )
V_141 |= 0x0100 ;
if ( V_105 & 0x080 )
V_141 |= 0x0200 ;
V_105 = V_3 -> V_13 [ V_534 ] . V_186 [ 14 ] ;
if ( V_105 & 0x08 )
V_141 |= 0x0400 ;
V_105 = V_3 -> V_13 [ V_534 ] . V_186 [ 11 ] ;
V_206 = ( V_206 & 0xFF00 ) | ( V_105 & 0x00FF ) ;
}
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x10 , V_105 ) ;
V_105 = ( ( V_141 & 0xFF00 ) >> 8 ) << 4 ;
V_105 = ( ( V_206 & 0x000F ) | ( V_105 ) ) ;
F_4 ( V_3 -> V_438 , 0x11 , V_105 ) ;
V_140 = 0 ;
if ( V_115 & V_182 )
V_140 |= 0x80 ;
if ( V_115 & V_209 )
V_140 |= 0x40 ;
F_12 ( V_3 -> V_438 , 0x2C , ~ 0x0C0 , V_140 ) ;
}
static unsigned short F_77 ( struct V_2 * V_3 )
{
unsigned long V_140 , V_141 ;
V_141 = ( ( V_3 -> V_410 - V_3 -> V_268 ) * V_3 -> V_535 )
& 0xFFFF ;
V_140 = ( V_3 -> V_413 - V_3 -> V_269 ) * V_3 -> V_536 ;
V_140 = ( V_140 * V_3 -> V_411 ) / V_141 ;
return ( unsigned short ) V_140 ;
}
static void F_78 ( unsigned short V_110 , unsigned short V_111 ,
struct V_122 * V_123 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_430 , V_431 , V_140 , V_141 = 0 , V_206 , V_105 , V_142 ,
V_115 , V_534 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_534 = V_3 -> V_10 [ V_139 ] . V_184 ;
V_534 &= V_185 ;
if ( ! ( V_3 -> V_39 & V_121 ) )
return;
V_105 = 0xFF ;
F_4 ( V_3 -> V_438 , 0x03 , V_105 ) ;
V_206 = 0x08 ;
if ( V_3 -> V_96 & ( V_97 | V_98 | V_149 ) )
V_115 |= V_129 ;
V_140 = V_3 -> V_266 ;
if ( V_115 & V_209 )
V_140 = V_140 >> 1 ;
V_140 = ( V_140 / V_206 ) - 1 ;
V_141 |= ( ( V_140 & 0x00FF ) << 8 ) ;
V_105 = V_140 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x04 , V_105 ) ;
V_105 = ( V_141 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_39 & V_119 ) {
if ( ! ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) )
V_105 += 2 ;
if ( V_3 -> V_39 & V_155 ) {
if ( V_3 -> V_96 & V_97 ) {
if ( V_3 -> V_156 == V_157 ) {
if ( V_142 == 7 )
V_105 -= 2 ;
}
} else if ( V_142 == 7 ) {
V_105 -= 2 ;
}
}
}
F_4 ( V_3 -> V_438 , 0x05 , V_105 ) ;
F_4 ( V_3 -> V_438 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_39 & V_482 ) ) {
if ( V_3 -> V_39 & V_119 )
V_140 = V_3 -> V_409 ;
else
V_140 = F_77 ( V_3 ) ;
}
if ( V_140 >= V_3 -> V_409 )
V_140 = V_3 -> V_409 ;
if ( V_115 & V_209 )
V_140 = V_140 >> 1 ;
V_140 = ( V_140 / V_206 ) - 5 ;
V_206 = V_140 ;
if ( V_3 -> V_39 & V_155 ) {
V_105 = ( V_141 & 0x00FF ) - 1 ;
if ( ! ( V_115 & V_209 ) ) {
V_105 -= 6 ;
if ( V_3 -> V_40 & V_161 ) {
V_105 -= 4 ;
V_105 -= 10 ;
}
}
} else {
V_141 = ( V_141 & 0xFF00 ) >> 8 ;
V_206 = ( V_206 + V_141 ) >> 1 ;
V_105 = ( V_206 & 0x00FF ) + 2 ;
if ( V_3 -> V_39 & V_119 ) {
V_105 -= 1 ;
if ( ! ( V_115 & V_209 ) ) {
if ( ( V_115 & V_129 ) ) {
V_105 += 4 ;
if ( V_3 -> V_266 >= 800 )
V_105 -= 6 ;
}
}
} else if ( ! ( V_115 & V_209 ) ) {
V_105 -= 4 ;
if ( V_3 -> V_36 != V_153 &&
V_3 -> V_266 >= 800 ) {
V_105 -= 7 ;
if ( V_3 -> V_266 >= 1280 &&
V_3 -> V_36 != V_153 &&
( V_3 -> V_38 & V_154 ) )
V_105 += 28 ;
}
}
}
F_4 ( V_3 -> V_438 , 0x07 , V_105 ) ;
F_4 ( V_3 -> V_438 , 0x08 , 0 ) ;
if ( V_3 -> V_39 & V_119 ) {
if ( V_3 -> V_40 & V_161 ) {
if ( V_110 == 0x50 ) {
if ( V_3 -> V_40 & V_567 ) {
F_4 ( V_3 -> V_438 ,
0x07 , 0x30 ) ;
F_4 ( V_3 -> V_438 ,
0x08 , 0x03 ) ;
} else {
F_4 ( V_3 -> V_438 ,
0x07 , 0x2f ) ;
F_4 ( V_3 -> V_438 ,
0x08 , 0x02 ) ;
}
}
}
}
F_4 ( V_3 -> V_438 , 0x18 , 0x03 ) ;
F_12 ( V_3 -> V_438 , 0x19 , 0xF0 , 0x00 ) ;
F_4 ( V_3 -> V_438 , 0x09 , 0xFF ) ;
V_141 = V_3 -> V_410 ;
V_430 = V_141 ;
V_206 = 0x121 ;
V_141 = V_3 -> V_268 ;
if ( V_141 == 357 )
V_141 = 350 ;
if ( V_141 == 360 )
V_141 = 350 ;
if ( V_141 == 375 )
V_141 = 350 ;
if ( V_141 == 405 )
V_141 = 400 ;
if ( V_141 == 525 )
V_141 = 480 ;
V_431 = V_141 ;
if ( V_3 -> V_39 & V_120 ) {
if ( V_3 -> V_36 == V_173 ) {
if ( ! ( V_3 -> V_38 & V_516 ) ) {
if ( V_141 == 350 )
V_141 += 5 ;
if ( V_141 == 480 )
V_141 += 5 ;
}
}
}
V_141 -- ;
V_105 = V_141 & 0x00FF ;
V_141 -- ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x10 , V_105 ) ;
V_141 = V_431 ;
V_141 -- ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x0E , V_105 ) ;
if ( V_141 & 0x0100 )
V_206 |= 0x0002 ;
V_140 = 0x000B ;
if ( V_115 & V_182 )
V_140 |= 0x08000 ;
if ( V_141 & 0x0200 )
V_206 |= 0x0040 ;
V_105 = ( V_140 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_438 , 0x0B , V_105 ) ;
if ( V_141 & 0x0400 )
V_206 |= 0x0600 ;
F_4 ( V_3 -> V_438 , 0x11 , 0x00 ) ;
V_140 = V_430 ;
V_140 -= V_141 ;
V_140 = V_140 >> 2 ;
V_430 = V_140 ;
if ( V_142 != 0x09 ) {
V_140 = V_140 << 1 ;
V_141 += V_140 ;
}
if ( V_3 -> V_39 & V_155 ) {
if ( ( V_3 -> V_96 & V_97 ) &&
! ( V_3 -> V_40 & V_506 ) ) {
if ( ( V_3 -> V_40 & V_161 ) &&
( V_3 -> V_40 & V_170 ) ) {
if ( ! ( V_3 -> V_96 & V_97 ) ||
! ( V_3 -> V_40 &
( V_456 |
V_455 |
V_506 ) ) )
V_141 += 40 ;
}
} else {
V_141 -= 10 ;
}
} else {
if ( V_3 -> V_40 & V_161 ) {
if ( V_3 -> V_40 & V_170 ) {
if ( V_3 -> V_96 & V_97 ) {
if ( ! ( V_3 -> V_40 &
( V_456 |
V_455 |
V_506 ) ) )
V_141 += 40 ;
} else {
V_141 += 40 ;
}
}
}
}
V_140 = V_430 ;
V_140 = V_140 >> 2 ;
V_140 ++ ;
V_140 += V_141 ;
V_430 = V_140 ;
if ( ( V_3 -> V_40 & V_170 ) ) {
if ( V_141 <= 513 ) {
if ( V_140 >= 513 )
V_141 = 513 ;
}
}
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x0C , V_105 ) ;
V_141 -- ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x10 , V_105 ) ;
if ( V_141 & 0x0100 )
V_206 |= 0x0008 ;
if ( V_141 & 0x0200 )
F_12 ( V_3 -> V_438 , 0x0B , 0x0FF , 0x20 ) ;
V_141 ++ ;
if ( V_141 & 0x0100 )
V_206 |= 0x0004 ;
if ( V_141 & 0x0200 )
V_206 |= 0x0080 ;
if ( V_141 & 0x0400 )
V_206 |= 0x0C00 ;
V_141 = V_430 ;
V_105 = V_141 & 0x00FF ;
V_105 &= 0x0F ;
F_4 ( V_3 -> V_438 , 0x0D , V_105 ) ;
if ( V_141 & 0x0010 )
V_206 |= 0x2000 ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_438 , 0x0A , V_105 ) ;
V_105 = ( V_206 & 0x0FF00 ) >> 8 ;
F_4 ( V_3 -> V_438 , 0x17 , V_105 ) ;
V_140 = V_115 ;
V_105 = ( V_140 & 0xFF00 ) >> 8 ;
V_105 = ( V_105 >> 1 ) & 0x09 ;
if ( V_3 -> V_96 & ( V_97 | V_98 | V_149 ) )
V_105 |= 0x01 ;
F_4 ( V_3 -> V_438 , 0x16 , V_105 ) ;
F_4 ( V_3 -> V_438 , 0x0F , 0 ) ;
F_4 ( V_3 -> V_438 , 0x12 , 0 ) ;
if ( V_3 -> V_38 & V_568 )
V_105 = 0x80 ;
else
V_105 = 0x00 ;
F_4 ( V_3 -> V_438 , 0x1A , V_105 ) ;
return;
}
static void F_79 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_114 , V_180 , V_140 , V_141 , V_206 , V_105 , V_430 , V_431 ,
V_115 , V_142 , V_569 ;
unsigned char * V_570 ;
unsigned long V_571 , V_572 , V_573 , V_213 , V_574 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_569 = V_3 -> V_10 [ V_139 ] . V_219 ;
V_140 = 0 ;
if ( ! ( V_3 -> V_39 & V_162 ) )
V_140 |= 0x0800 ;
if ( ! ( V_3 -> V_39 & V_163 ) )
V_140 |= 0x0400 ;
if ( V_3 -> V_39 & V_164 )
V_140 |= 0x0200 ;
if ( ! ( V_3 -> V_40 & V_170 ) )
V_140 |= 0x1000 ;
if ( V_3 -> V_39 & V_155 )
V_140 |= 0x0100 ;
if ( V_3 -> V_40 & ( V_456 | V_455 ) )
V_140 &= 0xfe00 ;
V_140 = ( V_140 & 0xff00 ) >> 8 ;
F_4 ( V_3 -> V_466 , 0x0 , V_140 ) ;
V_570 = V_3 -> V_59 ;
if ( V_3 -> V_40 & V_170 )
V_570 = V_3 -> V_61 ;
if ( V_3 -> V_39 & V_155 ) {
V_570 = V_3 -> V_63 ;
if ( V_3 -> V_39 & V_121 )
V_570 = V_3 -> V_67 ;
if ( V_3 -> V_160 & V_161 )
V_570 = V_3 -> V_65 ;
if ( ! ( V_115 & V_129 ) )
V_570 = V_3 -> V_69 ;
}
if ( V_3 -> V_39 & V_165 ) {
if ( V_3 -> V_40 & V_503 )
V_570 = V_3 -> V_75 ;
if ( V_3 -> V_40 & V_456 )
V_570 = V_3 -> V_73 ;
if ( V_3 -> V_40 & V_455 )
V_570 = V_3 -> V_71 ;
}
for ( V_114 = 0x01 , V_180 = 0 ; V_114 <= 0x2D ; V_114 ++ , V_180 ++ )
F_4 ( V_3 -> V_466 , V_114 , V_570 [ V_180 ] ) ;
for ( V_114 = 0x39 ; V_114 <= 0x45 ; V_114 ++ , V_180 ++ )
F_4 ( V_3 -> V_466 , V_114 , V_570 [ V_180 ] ) ;
if ( V_3 -> V_39 & V_119 )
F_12 ( V_3 -> V_466 , 0x3A , 0x1F , 0x00 ) ;
V_105 = V_3 -> V_540 ;
V_105 &= 0x80 ;
F_12 ( V_3 -> V_466 , 0x0A , 0xFF , V_105 ) ;
if ( V_3 -> V_39 & V_155 )
V_140 = 950 ;
if ( V_3 -> V_40 & V_170 )
V_140 = 520 ;
else
V_140 = 440 ;
if ( V_3 -> V_269 <= V_140 ) {
V_140 -= V_3 -> V_269 ;
V_140 = V_140 >> 2 ;
V_140 = ( V_140 & 0x00FF ) | ( ( V_140 & 0x00FF ) << 8 ) ;
V_430 = V_140 ;
V_105 = ( V_140 & 0xFF00 ) >> 8 ;
V_105 += ( unsigned short ) V_570 [ 0 ] ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
if ( V_3 -> V_39 & ( V_162
| V_163 | V_164
| V_165 ) ) {
V_206 = V_3 -> V_266 ;
if ( V_206 >= 1024 ) {
V_105 = 0x17 ;
if ( V_3 -> V_40 & V_170 )
V_105 = 0x19 ;
}
}
}
F_4 ( V_3 -> V_466 , 0x01 , V_105 ) ;
V_140 = V_430 ;
V_105 = ( V_140 & 0xFF00 ) >> 8 ;
V_105 += V_570 [ 1 ] ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
if ( ( V_3 -> V_39 & ( V_162
| V_163 | V_164
| V_165 ) ) ) {
V_206 = V_3 -> V_266 ;
if ( V_206 >= 1024 ) {
V_105 = 0x1D ;
if ( V_3 -> V_40 & V_170 )
V_105 = 0x52 ;
}
}
}
F_4 ( V_3 -> V_466 , 0x02 , V_105 ) ;
}
V_206 = V_3 -> V_411 ;
if ( F_67 ( V_3 ) )
V_206 = V_206 >> 1 ;
V_206 -= 2 ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x1B , V_105 ) ;
V_105 = ( V_206 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_466 , 0x1D , ~ 0x0F , V_105 ) ;
V_206 = V_3 -> V_411 >> 1 ;
V_430 = V_206 ;
V_206 += 7 ;
if ( V_3 -> V_39 & V_155 )
V_206 -= 4 ;
V_105 = V_206 & 0x00FF ;
V_105 = V_105 << 4 ;
F_12 ( V_3 -> V_466 , 0x22 , 0x0F , V_105 ) ;
V_141 = V_570 [ V_180 ] | ( ( V_570 [ V_180 + 1 ] ) << 8 ) ;
V_141 += V_206 ;
V_431 = V_141 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x24 , V_105 ) ;
V_105 = ( V_141 & 0xFF00 ) >> 8 ;
V_105 = V_105 << 4 ;
F_12 ( V_3 -> V_466 , 0x25 , 0x0F , V_105 ) ;
V_141 = V_431 ;
V_141 = V_141 + 8 ;
if ( V_3 -> V_39 & V_155 ) {
V_141 = V_141 - 4 ;
V_206 = V_141 ;
}
V_105 = ( V_141 & 0x00FF ) << 4 ;
F_12 ( V_3 -> V_466 , 0x29 , 0x0F , V_105 ) ;
V_180 += 2 ;
V_206 += ( V_570 [ V_180 ] | ( ( V_570 [ V_180 + 1 ] ) << 8 ) ) ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x27 , V_105 ) ;
V_105 = ( ( V_206 & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_466 , 0x28 , 0x0F , V_105 ) ;
V_206 += 8 ;
if ( V_3 -> V_39 & V_155 )
V_206 -= 4 ;
V_105 = V_206 & 0xFF ;
V_105 = V_105 << 4 ;
F_12 ( V_3 -> V_466 , 0x2A , 0x0F , V_105 ) ;
V_206 = V_430 ;
V_180 += 2 ;
V_105 = V_570 [ V_180 ] | ( ( V_570 [ V_180 + 1 ] ) << 8 ) ;
V_206 -= V_105 ;
V_105 = V_206 & 0x00FF ;
V_105 = V_105 << 4 ;
F_12 ( V_3 -> V_466 , 0x2D , 0x0F , V_105 ) ;
V_206 -= 11 ;
if ( ! ( V_3 -> V_39 & V_119 ) ) {
V_140 = F_77 ( V_3 ) ;
V_206 = V_140 - 1 ;
}
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x2E , V_105 ) ;
V_141 = V_3 -> V_269 ;
if ( V_3 -> V_268 == 360 )
V_141 = 746 ;
if ( V_3 -> V_268 == 375 )
V_141 = 746 ;
if ( V_3 -> V_268 == 405 )
V_141 = 853 ;
if ( V_3 -> V_39 & V_119 ) {
if ( V_3 -> V_96 &
( V_97 | V_98 | V_149 ) ) {
if ( ! ( V_3 -> V_40 &
( V_456 | V_455 ) ) )
V_141 = V_141 >> 1 ;
} else
V_141 = V_141 >> 1 ;
}
V_141 -= 2 ;
V_105 = V_141 & 0x00FF ;
if ( V_3 -> V_39 & V_155 ) {
if ( V_3 -> V_96 & V_97 ) {
if ( V_3 -> V_40 & V_506 ) {
if ( V_3 -> V_39 & V_121 ) {
if ( V_110 == 0x2f )
V_105 += 1 ;
}
}
} else {
if ( V_3 -> V_39 & V_121 ) {
if ( V_110 == 0x2f )
V_105 += 1 ;
}
}
}
F_4 ( V_3 -> V_466 , 0x2F , V_105 ) ;
V_105 = ( V_206 & 0xFF00 ) >> 8 ;
V_105 |= ( ( V_141 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_39 & V_155 ) ) {
if ( V_3 -> V_96 & V_97 ) {
if ( V_3 -> V_40 & V_506 ) {
V_105 |= 0x10 ;
if ( ! ( V_3 -> V_39 & V_163 ) )
V_105 |= 0x20 ;
}
} else {
V_105 |= 0x10 ;
if ( ! ( V_3 -> V_39 & V_163 ) )
V_105 |= 0x20 ;
}
}
F_4 ( V_3 -> V_466 , 0x30 , V_105 ) ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
V_141 = V_3 -> V_269 ;
V_206 = V_141 - 2 ;
if ( V_3 -> V_39 & V_119 ) {
if ( ! ( V_3 -> V_40 & ( V_456
| V_455 ) ) )
V_141 = V_141 >> 1 ;
}
if ( V_3 -> V_96 & ( V_98 | V_149 ) ) {
V_105 = 0 ;
if ( V_206 & 0x0400 )
V_105 |= 0x20 ;
if ( V_141 & 0x0400 )
V_105 |= 0x40 ;
F_4 ( V_3 -> V_445 , 0x10 , V_105 ) ;
}
V_105 = ( ( ( V_141 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_4 ( V_3 -> V_466 , 0x46 , V_105 ) ;
V_105 = ( V_141 - 3 ) & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x47 , V_105 ) ;
}
V_141 = V_141 & 0x00FF ;
if ( ! ( V_115 & V_209 ) ) {
V_206 = V_3 -> V_266 ;
if ( V_206 >= V_3 -> V_267 ) {
V_141 |= 0x2000 ;
V_140 &= 0x00FF ;
}
}
V_206 = 0x0101 ;
if ( V_3 -> V_39 & V_119 ) {
if ( V_3 -> V_266 >= 1024 ) {
V_206 = 0x1920 ;
if ( V_3 -> V_266 >= 1280 ) {
V_206 = 0x1420 ;
V_141 = V_141 & 0xDFFF ;
}
}
}
if ( ! ( V_141 & 0x2000 ) ) {
if ( V_115 & V_209 )
V_206 = ( V_206 & 0xFF00 ) | ( ( V_206 & 0x00FF ) << 1 ) ;
V_430 = V_141 ;
V_572 = V_3 -> V_266 ;
V_573 = ( V_206 & 0xFF00 ) >> 8 ;
V_571 = V_572 * V_573 ;
V_574 = V_206 & 0x00FF ;
V_571 = V_571 / V_574 ;
V_574 = 8 * 1024 ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
V_574 = V_574 * 8 ;
}
V_571 = V_571 * V_574 ;
V_574 = V_3 -> V_267 ;
V_213 = V_571 % V_574 ;
V_572 = V_571 / V_574 ;
if ( V_213 != 0 )
V_572 += 1 ;
V_140 = ( unsigned short ) V_572 ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
V_206 = ( ( V_140 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_141 = V_430 ;
V_141 = ( unsigned short ) ( ( ( V_572 & 0x0000FF00 ) & 0x1F00 )
| ( V_141 & 0x00FF ) ) ;
V_140 = ( unsigned short ) ( ( ( V_572 & 0x000000FF ) << 8 )
| ( V_140 & 0x00FF ) ) ;
V_105 = ( V_140 & 0xFF00 ) >> 8 ;
} else {
V_105 = ( V_140 & 0x00FF ) >> 8 ;
}
F_4 ( V_3 -> V_466 , 0x44 , V_105 ) ;
V_105 = ( V_141 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_466 , 0x45 , ~ 0x03F , V_105 ) ;
V_105 = V_206 & 0x00FF ;
if ( V_141 & 0x2000 )
V_105 = 0 ;
if ( ! ( V_3 -> V_39 & V_120 ) )
V_105 |= 0x18 ;
F_12 ( V_3 -> V_466 , 0x46 , ~ 0x1F , V_105 ) ;
if ( V_3 -> V_40 & V_170 ) {
V_141 = 0x0382 ;
V_206 = 0x007e ;
} else {
V_141 = 0x0369 ;
V_206 = 0x0061 ;
}
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x4b , V_105 ) ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x4c , V_105 ) ;
V_105 = ( ( V_206 & 0xFF00 ) >> 8 ) & 0x03 ;
V_105 = V_105 << 2 ;
V_105 |= ( ( V_141 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_39 & V_165 ) {
V_105 |= 0x10 ;
if ( V_3 -> V_40 & V_456 )
V_105 |= 0x20 ;
if ( V_3 -> V_40 & V_455 )
V_105 |= 0x60 ;
}
F_4 ( V_3 -> V_466 , 0x4d , V_105 ) ;
V_105 = F_2 ( V_3 -> V_466 , 0x43 ) ;
F_4 ( V_3 -> V_466 , 0x43 , ( unsigned short ) ( V_105 - 3 ) ) ;
if ( ! ( V_3 -> V_40 & ( V_456 | V_455 ) ) ) {
if ( V_3 -> V_40 & V_458 ) {
V_570 = V_575 ;
for ( V_114 = 0x1c , V_180 = 0 ; V_114 <= 0x30 ; V_114 ++ , V_180 ++ ) {
F_4 ( V_3 -> V_466 , V_114 ,
V_570 [ V_180 ] ) ;
}
F_4 ( V_3 -> V_466 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_96 & V_149 ) {
if ( V_3 -> V_40 & V_499 )
F_12 ( V_3 -> V_466 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_40 & V_499 ) {
V_140 = ( unsigned char ) F_2 ( V_3 -> V_466 ,
0x01 ) ;
V_140 -- ;
F_13 ( V_3 -> V_466 , 0x01 , V_140 ) ;
F_13 ( V_3 -> V_466 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_39 & V_155 ) {
if ( ! ( V_3 -> V_39 & V_121 ) )
F_4 ( V_3 -> V_466 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_39 & V_119 )
return;
}
static void F_80 ( unsigned short V_110 , unsigned short V_111 ,
struct V_122 * V_123 ,
unsigned short V_139 ,
struct V_2 * V_3 )
{
unsigned short V_430 , V_431 , V_566 , V_140 , V_141 , V_206 , V_105 ,
V_112 , V_522 , V_462 , V_142 , V_115 , V_534 ;
struct V_435 * V_576 = NULL ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_142 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_534 = V_3 -> V_10 [ V_139 ] . V_184 ;
V_534 &= V_185 ;
if ( ! ( V_3 -> V_39 & V_120 ) )
return;
V_141 = V_3 -> V_267 ;
if ( F_67 ( V_3 ) )
V_141 = V_141 >> 1 ;
V_141 -= 1 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x2C , V_105 ) ;
V_105 = ( V_141 & 0xFF00 ) >> 8 ;
V_105 = V_105 << 4 ;
F_12 ( V_3 -> V_466 , 0x2B , 0x0F , V_105 ) ;
V_105 = 0x01 ;
F_4 ( V_3 -> V_466 , 0x0B , V_105 ) ;
V_141 = V_3 -> V_269 ;
V_430 = V_141 ;
V_141 -- ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x03 , V_105 ) ;
V_105 = ( ( V_141 & 0xFF00 ) >> 8 ) & 0x07 ;
F_12 ( V_3 -> V_466 , 0x0C , ~ 0x07 , V_105 ) ;
V_206 = V_3 -> V_413 - 1 ;
V_431 = V_206 + 1 ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x19 , V_105 ) ;
V_105 = ( V_206 & 0xFF00 ) >> 8 ;
V_105 = V_105 << 5 ;
F_4 ( V_3 -> V_466 , 0x1A , V_105 ) ;
F_12 ( V_3 -> V_466 , 0x09 , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_466 , 0x0A , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_466 , 0x17 , 0xFB , 0x00 ) ;
F_12 ( V_3 -> V_466 , 0x18 , 0xDF , 0x00 ) ;
V_141 = 5 ;
V_576 = (struct V_435 * ) F_36 ( V_141 , V_110 ,
V_111 , V_139 , V_3 ) ;
V_112 = V_3 -> V_36 ;
V_112 &= V_287 ;
if ( ( V_112 == V_173 ) || ( V_112 == V_416 ) ) {
V_141 = 1024 ;
V_206 = 768 ;
} else if ( ( V_112 == V_152 ) ||
( V_112 == V_417 ) ) {
V_141 = 1280 ;
V_206 = 1024 ;
} else if ( V_112 == V_418 ) {
V_141 = 1400 ;
V_206 = 1050 ;
} else {
V_141 = 1600 ;
V_206 = 1200 ;
}
if ( V_3 -> V_38 & V_277 ) {
V_141 = V_3 -> V_267 ;
V_206 = V_3 -> V_269 ;
}
V_566 = V_141 ;
V_140 = V_3 -> V_413 ;
V_3 -> V_437 = V_576 -> V_437 ;
V_3 -> V_439 = V_576 -> V_439 ;
V_3 -> V_441 = V_576 -> V_441 ;
V_3 -> V_442 = V_576 -> V_442 ;
V_141 = V_3 -> V_441 ;
V_206 += V_141 ;
if ( V_206 >= V_140 )
V_206 -= V_140 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x05 , V_105 ) ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x06 , V_105 ) ;
V_462 = ( ( V_206 & 0xFF00 ) >> 8 ) & 0x07 ;
V_522 = ( ( V_141 & 0xFF00 ) >> 8 ) & 0x07 ;
V_112 = V_462 ;
V_112 = V_112 << 3 ;
V_112 |= V_522 ;
F_4 ( V_3 -> V_466 , 0x02 , V_112 ) ;
F_42 ( & V_140 , & V_141 , V_3 ) ;
V_206 = V_141 ;
V_140 = V_3 -> V_413 ;
V_141 = V_3 -> V_442 ;
V_206 += V_141 ;
if ( V_206 >= V_140 )
V_206 -= V_140 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x04 , V_105 ) ;
V_105 = ( V_141 & 0xFF00 ) >> 8 ;
V_105 = V_105 << 4 ;
V_105 |= ( V_206 & 0x000F ) ;
F_4 ( V_3 -> V_466 , 0x01 , V_105 ) ;
V_206 = V_566 ;
V_140 = V_3 -> V_411 ;
V_141 = V_3 -> V_437 ;
V_141 &= 0x0FFF ;
if ( F_67 ( V_3 ) ) {
V_140 = V_140 >> 1 ;
V_141 = V_141 >> 1 ;
V_206 = V_206 >> 1 ;
}
if ( V_3 -> V_96 & V_98 )
V_141 += 1 ;
if ( V_3 -> V_96 & V_149 )
V_141 += 1 ;
V_206 += V_141 ;
if ( V_206 >= V_140 )
V_206 -= V_140 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x1F , V_105 ) ;
V_105 = ( ( V_141 & 0xFF00 ) >> 8 ) << 4 ;
F_4 ( V_3 -> V_466 , 0x20 , V_105 ) ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x23 , V_105 ) ;
V_105 = ( V_206 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_466 , 0x25 , V_105 ) ;
F_42 ( & V_140 , & V_141 , V_3 ) ;
V_206 = V_140 ;
V_140 = V_3 -> V_411 ;
V_141 = V_3 -> V_439 ;
if ( F_67 ( V_3 ) ) {
V_140 = V_140 >> 1 ;
V_141 = V_141 >> 1 ;
V_206 = V_206 >> 1 ;
}
if ( V_3 -> V_96 & V_98 )
V_141 += 1 ;
V_206 += V_141 ;
if ( V_206 >= V_140 )
V_206 -= V_140 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x1C , V_105 ) ;
V_105 = ( V_141 & 0xFF00 ) >> 8 ;
V_105 = V_105 << 4 ;
F_12 ( V_3 -> V_466 , 0x1D , ~ 0x0F0 , V_105 ) ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_466 , 0x21 , V_105 ) ;
if ( ! ( V_3 -> V_38 & V_516 ) ) {
if ( V_3 -> V_268 == 525 ) {
if ( V_3 -> V_96 & ( V_167 | V_168
| V_97 | V_98
| V_149 ) ) {
V_105 = 0xC6 ;
} else
V_105 = 0xC4 ;
F_4 ( V_3 -> V_466 , 0x2f , V_105 ) ;
F_4 ( V_3 -> V_466 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_268 == 420 ) {
if ( V_3 -> V_96 & ( V_167 | V_168
| V_97 | V_98
| V_149 ) ) {
V_105 = 0x4F ;
} else
V_105 = 0x4E ;
F_4 ( V_3 -> V_466 , 0x2f , V_105 ) ;
}
}
}
static struct V_577 * F_81 ( unsigned short V_206 ,
struct V_2 * V_3 )
{
unsigned short V_140 , V_141 , V_114 ;
struct V_577 * V_578 ;
if ( V_206 == 0 ) {
V_140 = V_3 -> V_266 ;
V_141 = V_3 -> V_267 ;
} else {
V_140 = V_3 -> V_268 ;
V_141 = V_3 -> V_269 ;
}
if ( V_140 <= V_141 )
return & V_579 [ 0 ] ;
else
V_578 = V_580 ;
if ( V_3 -> V_40 & V_170 )
V_578 = V_581 ;
if ( V_3 -> V_39 & V_165 ) {
if ( ( V_3 -> V_40 & V_503 ) ||
( V_3 -> V_40 & V_456 ) )
V_578 = V_580 ;
if ( V_3 -> V_40 & V_455 )
V_578 = V_582 ;
}
if ( V_3 -> V_39 & V_155 )
V_578 = V_579 ;
V_114 = 0 ;
while ( V_578 [ V_114 ] . V_583 != 0xFFFF ) {
if ( V_578 [ V_114 ] . V_583 == V_140 )
break;
V_114 ++ ;
}
return & V_578 [ V_114 ] ;
}
static void F_82 ( struct V_2 * V_3 )
{
unsigned short V_114 , V_180 ;
struct V_577 * V_578 ;
if ( ! ( V_3 -> V_96 & V_149 ) )
return;
V_578 = F_81 ( 0 , V_3 ) ;
for ( V_114 = 0x80 , V_180 = 0 ; V_114 <= 0xBF ; V_114 ++ , V_180 ++ )
F_4 ( V_3 -> V_466 , V_114 , V_578 -> V_422 [ V_180 ] ) ;
if ( ( V_3 -> V_39 & V_119 ) &&
( ! ( V_3 -> V_39 & V_155 ) ) ) {
V_578 = F_81 ( 1 , V_3 ) ;
for ( V_114 = 0xC0 , V_180 = 0 ; V_114 < 0xFF ; V_114 ++ , V_180 ++ )
F_4 ( V_3 -> V_466 ,
V_114 ,
V_578 -> V_422 [ V_180 ] ) ;
}
if ( ( V_3 -> V_39 & V_119 ) &&
( ! ( V_3 -> V_39 & V_155 ) ) )
F_12 ( V_3 -> V_466 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_12 ( V_3 -> V_466 , 0x4E , ~ 0x14 , 0x10 ) ;
}
static void F_83 ( unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_114 ;
unsigned char * V_274 ;
unsigned short V_115 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
F_4 ( V_3 -> V_584 , 0x00 , 0x00 ) ;
if ( V_3 -> V_40 & V_170 ) {
F_4 ( V_3 -> V_584 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_584 , 0x14 , 0xC8 ) ;
} else {
F_4 ( V_3 -> V_584 , 0x13 , 0xF5 ) ;
F_4 ( V_3 -> V_584 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_39 & V_119 ) )
return;
if ( V_3 -> V_40 & V_499 ) {
F_4 ( V_3 -> V_584 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_584 , 0x14 , 0xC8 ) ;
F_4 ( V_3 -> V_584 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_39 & V_155 ) || ( V_3 -> V_39
& V_165 ) ) {
if ( V_3 -> V_40 & V_503 )
return;
V_274 = V_3 -> V_77 ;
if ( V_3 -> V_160 & V_161 ) {
V_274 = V_3 -> V_79 ;
if ( ! ( V_115 & V_129 ) )
V_274 = V_3 -> V_81 ;
}
if ( V_3 -> V_40 & V_456 )
V_274 = V_3 -> V_83 ;
if ( V_3 -> V_40 & V_455 )
V_274 = V_3 -> V_85 ;
for ( V_114 = 0 ; V_114 <= 0x3E ; V_114 ++ )
F_4 ( V_3 -> V_584 , V_114 , V_274 [ V_114 ] ) ;
if ( V_3 -> V_96 & V_149 ) {
if ( V_3 -> V_40 & V_456 )
F_4 ( V_3 -> V_584 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_84 ( unsigned short V_110 , unsigned short V_111 ,
unsigned short V_139 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_140 , V_206 , V_141 , V_115 , V_105 , V_213 ;
unsigned long V_573 , V_572 , V_585 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_105 = V_3 -> V_536 ;
F_4 ( V_3 -> V_445 , 0x13 , V_105 ) ;
V_141 = V_3 -> V_535 ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_445 , 0x14 , V_105 ) ;
V_213 = ( ( V_141 & 0xFF00 ) >> 8 ) << 7 ;
V_206 = V_3 -> V_409 - 1 ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_445 , 0x16 , V_105 ) ;
V_105 = ( ( V_206 & 0xFF00 ) >> 8 ) << 3 ;
V_213 |= V_105 ;
V_206 = V_3 -> V_410 - 1 ;
if ( ! ( V_3 -> V_39 & V_119 ) )
V_206 -= 5 ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_445 , 0x17 , V_105 ) ;
V_105 = V_213 | ( ( V_206 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_445 , 0x15 , V_105 ) ;
F_20 ( V_3 -> V_445 , 0x0D , 0x08 ) ;
V_206 = V_3 -> V_39 ;
V_141 = V_3 -> V_266 ;
if ( V_115 & V_209 )
V_141 = V_141 >> 1 ;
if ( F_67 ( V_3 ) )
V_141 = V_141 >> 1 ;
if ( V_206 & V_155 ) {
V_105 = 0 ;
if ( V_141 <= 1024 )
V_105 = 0xA0 ;
if ( V_141 == 1280 )
V_105 = 0xC0 ;
} else if ( V_206 & V_119 ) {
V_105 = 0xA0 ;
if ( V_141 <= 800 )
V_105 = 0x80 ;
} else {
V_105 = 0x80 ;
if ( V_3 -> V_39 & V_120 ) {
V_105 = 0 ;
if ( V_141 > 800 )
V_105 = 0x60 ;
}
}
if ( V_3 -> V_40 & ( V_456 | V_455 ) ) {
V_105 = 0x00 ;
if ( V_3 -> V_266 == 1280 )
V_105 = 0x40 ;
if ( V_3 -> V_266 == 1024 )
V_105 = 0x20 ;
}
F_12 ( V_3 -> V_445 , 0x0E , ~ 0xEF , V_105 ) ;
V_573 = V_3 -> V_269 ;
if ( V_206 & V_155 ) {
if ( ! ( V_105 & 0xE000 ) )
V_141 = V_141 >> 1 ;
}
V_206 = V_3 -> V_541 ;
V_105 = V_206 & 0x00FF ;
F_4 ( V_3 -> V_445 , 0x18 , V_105 ) ;
V_572 = V_3 -> V_268 ;
V_206 |= 0x04000 ;
if ( V_572 <= V_573 ) {
V_206 = ( V_206 & ( ~ 0x4000 ) ) ;
V_572 = V_3 -> V_268 ;
} else {
V_572 -= V_573 ;
}
V_585 = ( V_572 * 256 * 1024 ) % V_573 ;
V_572 = ( V_572 * 256 * 1024 ) / V_573 ;
V_573 = V_572 ;
if ( V_585 != 0 )
V_573 ++ ;
V_105 = ( unsigned short ) ( V_573 & 0x000000FF ) ;
F_4 ( V_3 -> V_445 , 0x1B , V_105 ) ;
V_105 = ( unsigned short ) ( ( V_573 & 0x0000FF00 ) >> 8 ) ;
F_4 ( V_3 -> V_445 , 0x1A , V_105 ) ;
V_141 = ( unsigned short ) ( V_573 >> 16 ) ;
V_105 = V_141 & 0x00FF ;
V_105 = V_105 << 4 ;
V_105 |= ( ( V_206 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_445 , 0x19 , V_105 ) ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
V_105 = 0x0028 ;
F_4 ( V_3 -> V_445 , 0x1C , V_105 ) ;
V_140 = V_3 -> V_266 ;
if ( V_115 & V_209 )
V_140 = V_140 >> 1 ;
if ( F_67 ( V_3 ) )
V_140 = V_140 >> 1 ;
if ( V_3 -> V_39 & V_120 ) {
if ( V_140 > 800 )
V_140 -= 800 ;
} else {
if ( V_3 -> V_266 > 800 ) {
if ( V_3 -> V_266 == 1024 )
V_140 = ( V_140 * 25 / 32 ) - 1 ;
else
V_140 = ( V_140 * 20 / 32 ) - 1 ;
}
}
V_140 -= 1 ;
V_105 = ( V_140 & 0xFF00 ) >> 8 ;
V_105 = ( ( V_105 & 0x0003 ) << 4 ) ;
F_4 ( V_3 -> V_445 , 0x1E , V_105 ) ;
V_105 = ( V_140 & 0x00FF ) ;
F_4 ( V_3 -> V_445 , 0x1D , V_105 ) ;
if ( V_3 -> V_39 & ( V_119 | V_155 ) ) {
if ( V_3 -> V_266 > 800 )
F_20 ( V_3 -> V_445 , 0x1E , 0x08 ) ;
}
V_105 = 0x0036 ;
if ( V_3 -> V_39 & V_119 ) {
if ( ! ( V_3 -> V_40 & ( V_458
| V_456 | V_455
| V_506 ) ) ) {
V_105 |= 0x0001 ;
if ( ( V_3 -> V_39 & V_121 )
&& ( ! ( V_3 -> V_40
& V_161 ) ) )
V_105 &= ( ~ 0x0001 ) ;
}
}
F_12 ( V_3 -> V_445 , 0x1F , 0x00C0 , V_105 ) ;
V_141 = V_3 -> V_411 ;
if ( F_67 ( V_3 ) )
V_141 = V_141 >> 1 ;
V_141 = ( V_141 >> 1 ) - 2 ;
V_105 = ( ( V_141 & 0x0700 ) >> 8 ) << 3 ;
F_12 ( V_3 -> V_445 , 0x21 , 0x00C0 , V_105 ) ;
V_105 = V_141 & 0x00FF ;
F_4 ( V_3 -> V_445 , 0x22 , V_105 ) ;
}
if ( V_3 -> V_586 == 0 )
F_70 ( V_110 , V_111 , V_139 ,
V_3 ) ;
}
static void F_85 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_109 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_86 ( unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_587 , V_588 ;
V_587 = V_3 -> V_589 ;
V_588 = V_3 -> V_589 + 1 ;
if ( V_3 -> V_135 == V_136 ) {
if ( ! ( V_3 -> V_39 & ( V_121 | V_590
| V_482 ) ) ) {
F_85 ( V_3 ) ;
}
}
return;
}
static void F_87 ( struct V_122 * V_123 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_125 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_88 ( struct V_122 * V_123 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_125 , 0x63 , 0xBF , 0x00 ) ;
}
static unsigned char F_89 ( struct V_525 * V_526 ,
unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_247 , V_265 , V_563 , V_115 , V_205 ;
V_205 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_247 = V_3 -> V_33 [ V_205 ] . V_207 ;
V_265 = V_3 -> V_33 [ V_205 ] . V_208 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
if ( ! ( V_115 & V_129 ) ) {
V_247 /= 9 ;
V_247 *= 8 ;
}
if ( ( V_110 > 0x13 ) && ( V_115 & V_209 ) )
V_247 *= 2 ;
if ( ( V_110 > 0x13 ) && ( V_115 & V_182 ) )
V_265 *= 2 ;
if ( V_247 > V_526 -> V_527 . V_591 )
return 0 ;
if ( V_265 > V_526 -> V_527 . V_592 )
return 0 ;
if ( V_247 != V_526 -> V_527 . V_591 ||
V_265 != V_526 -> V_527 . V_592 ) {
V_563 = F_71 ( V_110 , V_111 , V_3 ) ;
if ( V_563 > 2 )
return 0 ;
}
return 1 ;
}
static void F_90 ( struct V_525 * V_526 ,
int V_194 ,
unsigned short V_110 ,
unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned char V_105 , V_593 ;
unsigned short V_247 , V_265 , V_115 , V_205 ;
unsigned short V_594 , V_595 , V_596 , V_597 , V_598 ;
unsigned short V_599 , V_600 , V_601 , V_602 , V_603 ;
unsigned short V_604 ;
V_105 = ( unsigned char ) ( ( V_526 -> V_527 . V_605 &
( V_606 << 8 ) ) >> 8 ) ;
V_105 &= V_606 ;
V_593 = ( unsigned char ) F_7 ( V_3 -> V_198 ) ;
F_8 ( ( V_593 & 0x3F ) | V_105 , V_3 -> V_176 ) ;
V_105 = V_526 -> V_527 . V_605 & V_606 ;
F_12 ( V_3 -> V_109 , 0x35 , ~ 0x80 , V_105 & 0x80 ) ;
F_12 ( V_3 -> V_109 , 0x30 , ~ 0x20 , ( V_105 & 0x40 ) >> 1 ) ;
if ( V_194 == V_104 )
F_22 ( V_3 ) ;
else
F_29 ( V_3 ) ;
V_205 = V_3 -> V_7 [ V_111 ] . V_144 ;
V_247 = V_3 -> V_33 [ V_205 ] . V_207 ;
V_265 = V_3 -> V_33 [ V_205 ] . V_208 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
if ( ! ( V_115 & V_129 ) )
V_247 = V_247 * 8 / 9 ;
V_594 = V_526 -> V_527 . V_594 ;
V_595 = V_247 + ( V_526 -> V_527 . V_591 - V_247 ) / 2 ;
if ( V_595 > V_594 )
V_595 -= V_594 ;
V_596 = V_595 + V_526 -> V_527 . V_607 ;
if ( V_596 > V_594 )
V_596 -= V_594 ;
V_597 = V_596 + V_526 -> V_527 . V_608 ;
if ( V_597 > V_594 )
V_597 -= V_594 ;
V_598 = V_595 + V_594 - V_526 -> V_527 . V_591 ;
V_599 = V_526 -> V_527 . V_599 ;
V_600 = V_265 + ( V_526 -> V_527 . V_592 - V_265 ) / 2 ;
if ( V_115 & V_182 )
V_600 += V_265 / 2 ;
if ( V_600 > V_599 )
V_600 -= V_599 ;
V_601 = V_600 + V_526 -> V_527 . V_609 ;
if ( V_601 > V_599 )
V_601 -= V_599 ;
V_602 = V_601 + V_526 -> V_527 . V_610 ;
if ( V_602 > V_599 )
V_602 -= V_599 ;
V_603 = V_600 + V_599 - V_526 -> V_527 . V_592 ;
V_105 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x11 ) ;
F_4 ( V_3 -> V_125 , 0x11 , V_105 & 0x7f ) ;
if ( ! ( V_115 & V_129 ) )
F_20 ( V_3 -> V_109 , 0x1 , 0x1 ) ;
V_604 = ( V_594 >> 3 ) - 5 ;
F_12 ( V_3 -> V_109 , 0x0B , ~ 0x03 , ( V_604 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_125 , 0x0 , ( V_604 & 0xFF ) ) ;
V_604 = ( V_595 >> 3 ) - 1 ;
F_12 ( V_3 -> V_109 , 0x0B , ~ 0x30 , ( V_604 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_125 , 0x2 , ( V_604 & 0xFF ) ) ;
V_604 = ( V_598 >> 3 ) - 1 ;
F_12 ( V_3 -> V_109 , 0x0C , ~ 0x03 , ( V_604 & 0xC0 ) >> 6 ) ;
F_12 ( V_3 -> V_125 , 0x05 , ~ 0x80 , ( V_604 & 0x20 ) << 2 ) ;
F_12 ( V_3 -> V_125 , 0x03 , ~ 0x1F , V_604 & 0x1F ) ;
V_604 = ( V_596 >> 3 ) + 2 ;
F_12 ( V_3 -> V_109 , 0x0B , ~ 0xC0 , ( V_604 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_125 , 0x4 , ( V_604 & 0xFF ) ) ;
V_604 -- ;
F_12 ( V_3 -> V_109 , 0x2F , ~ 0x03 , ( V_604 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_109 , 0x2E , ( V_604 & 0xFF ) ) ;
V_604 = ( V_597 >> 3 ) + 2 ;
F_12 ( V_3 -> V_109 , 0x0C , ~ 0x04 , ( V_604 & 0x20 ) >> 3 ) ;
F_12 ( V_3 -> V_125 , 0x05 , ~ 0x1F , V_604 & 0x1F ) ;
V_604 -- ;
F_12 ( V_3 -> V_109 , 0x2F , ~ 0xFC , V_604 << 2 ) ;
V_604 = V_599 - 2 ;
F_12 ( V_3 -> V_109 , 0x0A , ~ 0x01 , ( V_604 & 0x400 ) >> 10 ) ;
F_12 ( V_3 -> V_125 , 0x07 , ~ 0x20 , ( V_604 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_125 , 0x07 , ~ 0x01 , ( V_604 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_125 , 0x06 , ( V_604 & 0xFF ) ) ;
V_604 = V_600 - 1 ;
F_12 ( V_3 -> V_109 , 0x0A , ~ 0x04 , ( V_604 & 0x400 ) >> 8 ) ;
F_12 ( V_3 -> V_125 , 0x09 , ~ 0x20 , ( V_604 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_125 , 0x07 , ~ 0x08 , ( V_604 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_125 , 0x15 , ( V_604 & 0xFF ) ) ;
V_604 = V_603 - 1 ;
F_12 ( V_3 -> V_109 , 0x0A , ~ 0x10 , ( V_604 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_125 , 0x16 , ( V_604 & 0xFF ) ) ;
V_604 = V_601 - 1 ;
F_12 ( V_3 -> V_109 , 0x0A , ~ 0x08 , ( V_604 & 0x400 ) >> 7 ) ;
F_12 ( V_3 -> V_125 , 0x07 , ~ 0x80 , ( V_604 & 0x200 ) >> 2 ) ;
F_12 ( V_3 -> V_125 , 0x07 , ~ 0x04 , ( V_604 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_125 , 0x10 , ( V_604 & 0xFF ) ) ;
if ( V_194 == V_104 ) {
F_12 ( V_3 -> V_109 , 0x35 , ~ 0x07 ,
( V_604 & 0x700 ) >> 8 ) ;
F_4 ( V_3 -> V_109 , 0x34 , V_604 & 0xFF ) ;
} else {
F_12 ( V_3 -> V_109 , 0x3F , ~ 0x03 ,
( V_604 & 0x600 ) >> 9 ) ;
F_4 ( V_3 -> V_109 , 0x34 , ( V_604 >> 1 ) & 0xFF ) ;
F_12 ( V_3 -> V_125 , 0x33 , ~ 0x01 , V_604 & 0x01 ) ;
}
V_604 = V_602 - 1 ;
F_12 ( V_3 -> V_109 , 0x0A , ~ 0x20 , ( V_604 & 0x10 ) << 1 ) ;
F_12 ( V_3 -> V_125 , 0x11 , ~ 0x0F , V_604 & 0x0F ) ;
if ( V_194 == V_104 )
F_12 ( V_3 -> V_109 , 0x3F , ~ 0xFC ,
( V_604 << 2 ) & 0xFC ) ;
else
F_12 ( V_3 -> V_109 , 0x3F , ~ 0xFC ,
( V_604 << 2 ) & 0x7C ) ;
for ( V_105 = 0 , V_604 = 0 ; V_105 < 3 ; V_105 ++ ) {
F_12 ( V_3 -> V_109 , 0x31 , ~ 0x30 , V_604 ) ;
F_4 ( V_3 -> V_109 ,
0x2B , V_526 -> V_527 . V_611 ) ;
F_4 ( V_3 -> V_109 ,
0x2C , V_526 -> V_527 . V_612 ) ;
V_604 += 0x10 ;
}
if ( ! ( V_115 & V_129 ) ) {
F_7 ( V_3 -> V_130 ) ;
F_8 ( 0x13 , V_3 -> V_131 ) ;
F_8 ( 0x00 , V_3 -> V_131 ) ;
F_7 ( V_3 -> V_130 ) ;
F_8 ( 0x20 , V_3 -> V_131 ) ;
F_7 ( V_3 -> V_130 ) ;
}
}
static unsigned char F_91 ( struct V_2 * V_3 )
{
unsigned short V_140 ;
V_140 = V_3 -> V_39 ;
if ( V_140 & V_481 )
return 0 ;
else if ( V_140 & ( V_482 | V_493 | V_492 ) )
return 1 ;
return 0 ;
}
static unsigned char F_92 ( struct V_2 * V_3 )
{
unsigned short V_141 , V_112 ;
V_141 = V_3 -> V_160 & ( V_613 | V_614 ) ;
V_112 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_438 , 0x2E ) ) ;
if ( V_141 & ( V_615 | V_613 ) ) {
if ( ! ( V_112 & 0x08 ) )
return 0 ;
}
if ( ! ( V_141 & ( V_616 | V_614 ) ) )
return 0 ;
if ( V_112 & 0x01 )
return 1 ;
return 0 ;
}
static unsigned char F_93 ( struct V_2 * V_3 )
{
unsigned short V_141 , V_112 ;
V_141 = V_3 -> V_160 & ( V_615 | V_616 ) ;
V_112 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_438 , 0x2E ) ) ;
if ( V_141 & ( V_615 | V_613 ) ) {
if ( ! ( V_112 & 0x08 ) )
return 0 ;
}
if ( ! ( V_141 & ( V_616 | V_614 ) ) )
return 0 ;
if ( V_112 & 0x01 )
return 1 ;
return 0 ;
}
static void F_94 ( struct V_525 * V_526 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_112 = 0 ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
V_112 = 0x3F ;
if ( ! ( V_3 -> V_39 &
( V_482 | V_492 ) ) ) {
if ( V_3 -> V_39 & V_118 ) {
if ( V_3 -> V_39 & V_481 ) {
V_112 = 0x7F ;
if ( ! ( V_3 -> V_39 &
V_118 ) )
V_112 = 0xBF ;
if ( V_3 -> V_160 & V_614 )
V_112 &= 0xBF ;
if ( V_3 -> V_160 & V_613 )
V_112 &= 0x7F ;
}
}
}
F_13 ( V_3 -> V_445 , 0x1F , V_112 ) ;
if ( V_3 -> V_96 & ( V_98 | V_149 ) ) {
if ( ( ( V_3 -> V_39 &
( V_120 | V_118 ) ) )
|| ( F_92 ( V_3 ) )
|| ( F_91 ( V_3 ) ) )
F_20 ( V_3 -> V_445 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_160 & V_613 ) || ( V_3 -> V_39
& ( V_482 | V_118
| V_492 ) ) ) {
if ( V_3 -> V_160 & V_617 )
F_87 ( V_123 , V_3 ) ;
F_62 ( V_526 , V_123 , V_3 ) ;
}
if ( V_3 -> V_39 & V_118 ) {
if ( ( V_3 -> V_160 & V_613 ) || ( V_3 -> V_39
& V_118 ) )
F_13 ( V_3 -> V_438 , 0x1e , 0xdf ) ;
}
F_13 ( V_3 -> V_109 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_39 & ( V_492 | V_481 ) ) )
F_13 ( V_3 -> V_466 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_160 & V_614 ) ||
( V_3 -> V_39 &
( V_482 | V_492 ) ) ||
( ( ! ( V_3 -> V_39 & V_118 ) ) &&
( V_3 -> V_39 &
( V_147 | V_120 | V_119 ) ) ) )
F_20 ( V_3 -> V_438 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_160 & V_614 ) ||
( V_3 -> V_39 &
( V_482 | V_492 ) ) ||
( ! ( V_3 -> V_39 & V_118 ) ) ||
( V_3 -> V_39 &
( V_147 | V_120 | V_119 ) ) ) {
V_112 = F_2 ( V_3 -> V_438 , 0x00 ) ;
F_20 ( V_3 -> V_438 , 0x00 , 0x10 ) ;
F_13 ( V_3 -> V_438 , 0x1E , 0xDF ) ;
F_4 ( V_3 -> V_438 , 0x00 , V_112 ) ;
}
} else {
if ( V_3 -> V_39 & ( V_120 | V_119 ) ) {
F_20 ( V_3 -> V_438 , 0x00 , 0x80 ) ;
F_13 ( V_3 -> V_438 , 0x1E , 0xDF ) ;
F_13 ( V_3 -> V_109 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_39 & ( V_482 | V_118
| V_492 ) )
F_62 ( V_526 , V_123 , V_3 ) ;
}
}
static unsigned short F_95 ( struct V_2 * V_3 )
{
unsigned short V_141 = 0 ;
if ( V_3 -> V_40 & V_170 )
V_141 = 2 ;
if ( V_3 -> V_40 & V_506 )
V_141 = 4 ;
if ( V_3 -> V_40 & V_503 )
V_141 = 6 ;
if ( V_3 -> V_40 & V_456 )
V_141 = 8 ;
if ( V_3 -> V_40 & V_455 )
V_141 = 10 ;
if ( V_3 -> V_40 & V_161 )
V_141 ++ ;
return V_141 ;
}
static void F_96 ( unsigned short * V_141 , unsigned char * V_461 ,
unsigned char * V_462 , struct V_2 * V_3 )
{
* V_141 = 0 ;
* V_461 = 0 ;
* V_462 = 0 ;
if ( V_3 -> V_40 & V_170 )
* V_141 = 1 ;
if ( V_3 -> V_40 & V_499 )
* V_141 = 2 ;
if ( V_3 -> V_40 & V_500 )
* V_141 = 3 ;
if ( V_3 -> V_40 & V_458 ) {
* V_141 = 4 ;
if ( V_3 -> V_40 & V_499 )
* V_141 = 5 ;
}
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
if ( ( ! ( V_3 -> V_39 & V_121 ) ) || ( V_3 -> V_40
& V_161 ) ) {
* V_141 += 8 ;
* V_461 += 1 ;
}
}
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) )
( * V_462 ) ++ ;
}
static void F_97 ( struct V_2 * V_3 )
{
unsigned char V_112 , V_423 , V_522 ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
if ( V_3 -> V_39 & ( V_120 | V_118
| V_119 | V_147 ) ) {
V_522 = 0 ;
V_423 = V_618 ;
if ( V_3 -> V_39 & V_481 )
V_423 = V_423 >> 4 ;
if ( V_3 -> V_39 &
( V_120 | V_118 ) ) {
V_522 = V_619 ;
if ( ! ( V_3 -> V_39 & V_118 ) )
V_423 = V_522 ;
}
V_423 &= 0x0F ;
V_522 &= 0xF0 ;
V_112 = F_2 ( V_3 -> V_438 , 0x2D ) ;
if ( V_3 -> V_39 & ( V_147 | V_120
| V_119 ) ) {
V_112 &= 0xF0 ;
V_112 |= V_423 ;
}
if ( V_3 -> V_39 & V_118 ) {
V_112 &= 0x0F ;
V_112 |= V_522 ;
}
F_4 ( V_3 -> V_438 , 0x2D , V_112 ) ;
}
} else if ( V_3 -> V_146 == 1 ) {
V_423 = 0 ;
V_522 = 0 ;
if ( V_3 -> V_39 & V_120 ) {
V_112 = V_619 ;
V_112 &= 0x0f ;
V_112 = V_112 << 4 ;
F_12 ( V_3 -> V_438 , 0x2D , 0x0f ,
V_112 ) ;
}
}
}
static void F_98 ( unsigned short V_206 ,
struct V_2 * V_3 )
{
unsigned short V_105 ;
V_105 = F_2 ( V_3 -> V_125 , 0x37 ) ;
if ( V_105 & V_568 ) {
F_12 ( V_3 -> V_438 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_206 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_438 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_12 ( V_3 -> V_438 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_206 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_438 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_99 ( unsigned short V_206 ,
struct V_2 * V_3 )
{
if ( V_206 & V_620 )
F_12 ( V_3 -> V_466 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_206 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_12 ( V_3 -> V_466 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_206 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
unsigned short V_114 ;
V_114 = F_2 ( V_3 -> V_109 , 0x1F ) ;
if ( ! ( V_114 & 0xC0 ) ) {
for ( V_114 = 0 ; V_114 < 0xFFFF ; V_114 ++ ) {
if ( ! ( F_7 ( V_3 -> V_130 ) & 0x08 ) )
break;
}
for ( V_114 = 0 ; V_114 < 0xFFFF ; V_114 ++ ) {
if ( ( F_7 ( V_3 -> V_130 ) & 0x08 ) )
break;
}
}
}
static void F_101 ( struct V_2 * V_3 )
{
unsigned short V_183 ;
V_183 = F_40 ( V_3 ) ;
F_13 ( V_3 -> V_445 , 0x30 , 0x8F ) ;
F_100 ( V_3 ) ;
F_20 ( V_3 -> V_445 , 0x30 , 0x20 ) ;
F_100 ( V_3 ) ;
F_4 ( V_3 -> V_445 , 0x31 ,
V_3 -> V_99 [ V_183 ] . V_621 ) ;
F_4 ( V_3 -> V_445 , 0x32 ,
V_3 -> V_99 [ V_183 ] . V_622 ) ;
F_4 ( V_3 -> V_445 , 0x33 ,
V_3 -> V_99 [ V_183 ] . V_623 ) ;
F_4 ( V_3 -> V_445 , 0x34 ,
V_3 -> V_99 [ V_183 ] . V_624 ) ;
F_100 ( V_3 ) ;
F_20 ( V_3 -> V_445 , 0x30 , 0x40 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
unsigned short V_206 ;
V_206 = V_3 -> V_99 [ F_40 ( V_3 ) ] . V_512 ;
if ( V_3 -> V_96 &
( V_167 |
V_168 |
V_97 |
V_98 |
V_149 ) ) {
if ( V_3 -> V_96 &
( V_97 | V_98 | V_149 ) ) {
F_4 ( V_3 -> V_445 , 0x24 ,
( unsigned char ) ( V_206 & 0x1F ) ) ;
}
F_12 ( V_3 -> V_445 , 0x0D ,
~ ( ( V_625 | V_626 ) >> 8 ) ,
( unsigned short ) ( ( V_206 & ( V_625
| V_626 ) ) >> 8 ) ) ;
}
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
if ( V_3 -> V_39 & V_120 )
F_99 ( V_206 , V_3 ) ;
else if ( V_3 -> V_39 & V_118 )
F_98 ( V_206 , V_3 ) ;
if ( V_3 -> V_96 & ( V_98 | V_149 ) ) {
if ( V_206 & V_627 )
F_101 ( V_3 ) ;
}
} else {
F_98 ( V_206 , V_3 ) ;
}
}
static void F_103 ( unsigned short V_110 ,
unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_141 ;
unsigned char V_112 ;
if ( V_3 -> V_40 & ( V_456 | V_455 ) )
return;
V_141 = F_95 ( V_3 ) ;
V_141 &= 0xFE ;
V_112 = V_628 [ V_141 ] ;
V_112 = V_112 << 4 ;
F_12 ( V_3 -> V_466 , 0x0A , 0x8F , V_112 ) ;
}
static void F_104 ( unsigned short V_110 ,
unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_141 ;
unsigned char V_112 ;
V_141 = F_95 ( V_3 ) ;
V_141 &= 0xFE ;
V_112 = V_629 [ V_141 ] ;
V_112 = V_112 << 5 ;
F_12 ( V_3 -> V_466 , 0x3A , 0x1F , V_112 ) ;
}
static void F_105 ( struct V_2 * V_3 )
{
unsigned short V_141 ;
unsigned char V_461 , V_462 ;
unsigned long V_630 ;
F_96 ( & V_141 , & V_461 , & V_462 , V_3 ) ;
V_630 = V_631 [ V_141 ] ;
F_4 ( V_3 -> V_466 , 0x31 , ( unsigned short ) ( V_630
& 0x000000FF ) ) ;
F_4 ( V_3 -> V_466 , 0x32 , ( unsigned short ) ( ( V_630
& 0x0000FF00 ) >> 8 ) ) ;
F_4 ( V_3 -> V_466 , 0x33 , ( unsigned short ) ( ( V_630
& 0x00FF0000 ) >> 16 ) ) ;
F_4 ( V_3 -> V_466 , 0x34 , ( unsigned short ) ( ( V_630
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_106 ( unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_141 , V_183 ;
unsigned char V_461 , V_462 , V_272 , * V_632 ;
F_96 ( & V_141 , & V_461 , & V_462 , V_3 ) ;
switch ( V_141 ) {
case 0x00 :
case 0x04 :
V_632 = V_633 ;
break;
case 0x01 :
V_632 = V_634 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
case 0x03 :
V_632 = V_635 ;
break;
case 0x08 :
case 0x0C :
case 0x0A :
case 0x0B :
case 0x09 :
V_632 = V_636 ;
break;
default:
return;
}
V_272 = V_3 -> V_7 [ V_111 ] . V_637 ;
if ( V_461 == 0 )
V_183 = V_272 * 4 ;
else
V_183 = V_272 * 7 ;
if ( ( V_461 == 0 ) && ( V_462 == 1 ) ) {
F_4 ( V_3 -> V_466 , 0x35 , 0 ) ;
F_4 ( V_3 -> V_466 , 0x36 , 0 ) ;
F_4 ( V_3 -> V_466 , 0x37 , 0 ) ;
F_4 ( V_3 -> V_466 , 0x38 , V_632 [ V_183 ++ ] ) ;
} else {
F_4 ( V_3 -> V_466 , 0x35 , V_632 [ V_183 ++ ] ) ;
F_4 ( V_3 -> V_466 , 0x36 , V_632 [ V_183 ++ ] ) ;
F_4 ( V_3 -> V_466 , 0x37 , V_632 [ V_183 ++ ] ) ;
F_4 ( V_3 -> V_466 , 0x38 , V_632 [ V_183 ++ ] ) ;
}
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
F_4 ( V_3 -> V_466 , 0x48 , V_632 [ V_183 ++ ] ) ;
F_4 ( V_3 -> V_466 , 0x49 , V_632 [ V_183 ++ ] ) ;
F_4 ( V_3 -> V_466 , 0x4A , V_632 [ V_183 ++ ] ) ;
}
}
static void F_107 ( unsigned short V_110 ,
unsigned short V_111 ,
struct V_2 * V_3 )
{
F_97 ( V_3 ) ;
if ( V_3 -> V_39 & ( V_120 | V_118 ) )
F_102 ( V_3 ) ;
if ( V_3 -> V_39 & V_119 ) {
F_105 ( V_3 ) ;
F_106 ( V_110 , V_111 , V_3 ) ;
F_103 ( V_110 , V_111 , V_3 ) ;
if ( V_3 -> V_96 & V_460 )
F_104 ( V_110 , V_111 , V_3 ) ;
}
}
static void F_108 ( unsigned short V_110 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_423 ;
short V_461 ;
unsigned char V_112 ;
V_112 = 0 ;
if ( ! ( V_3 -> V_39 & V_482 ) ) {
V_112 = F_2 ( V_3 -> V_438 , 0x00 ) ;
V_112 &= ~ 0x10 ;
V_112 |= 0x40 ;
if ( V_3 -> V_39 & ( V_147 | V_119
| V_120 ) ) {
V_112 = 0x40 ;
V_461 = V_3 -> V_135 ;
V_461 -= V_136 ;
if ( V_461 >= 0 ) {
V_112 = ( 0x008 >> V_461 ) ;
if ( V_112 == 0 )
V_112 = 1 ;
V_112 |= 0x040 ;
}
if ( V_3 -> V_39 & V_121 )
V_112 ^= 0x50 ;
}
}
F_4 ( V_3 -> V_438 , 0x00 , V_112 ) ;
V_112 = 0x08 ;
V_423 = 0xf0 ;
if ( V_3 -> V_39 & V_482 )
goto V_638;
V_112 = 0x00 ;
V_423 = 0xff ;
if ( ! ( V_3 -> V_39 & ( V_147 | V_119 |
V_120 | V_118 ) ) )
goto V_638;
if ( ( V_3 -> V_39 & V_118 ) &&
( ! ( V_3 -> V_39 & V_492 ) ) ) {
V_423 &= 0xf7 ;
V_112 |= 0x01 ;
goto V_638;
}
if ( V_3 -> V_39 & V_118 ) {
V_423 &= 0xf7 ;
V_112 |= 0x01 ;
}
if ( ! ( V_3 -> V_39 & ( V_147 | V_119 | V_120 ) ) )
goto V_638;
V_423 &= 0xf8 ;
V_112 = 0x01 ;
if ( ! ( V_3 -> V_39 & V_121 ) )
V_112 |= 0x02 ;
if ( ! ( V_3 -> V_39 & V_147 ) ) {
V_112 = V_112 ^ 0x05 ;
if ( ! ( V_3 -> V_39 & V_120 ) )
V_112 = V_112 ^ 0x01 ;
}
if ( ! ( V_3 -> V_39 & V_481 ) )
V_112 |= 0x08 ;
V_638:
F_12 ( V_3 -> V_438 , 0x2e , V_423 , V_112 ) ;
if ( V_3 -> V_39 & ( V_147 | V_119 | V_120
| V_118 ) ) {
V_112 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_135 == V_136 ) && ( ! ( V_3 -> V_39
& V_121 ) ) ) {
V_112 |= 0x010 ;
}
V_112 |= 0x080 ;
if ( V_3 -> V_39 & V_119 ) {
V_112 |= 0x020 ;
if ( V_3 -> V_39 & V_495 )
V_112 = V_112 ^ 0x20 ;
}
F_12 ( V_3 -> V_445 , 0x0D , ~ 0x0BF , V_112 ) ;
V_112 = 0 ;
if ( V_3 -> V_38 & V_514 )
V_112 |= 0x40 ;
if ( V_3 -> V_39 & V_119 ) {
if ( V_3 -> V_40 & V_222 )
V_112 |= 0x40 ;
}
if ( ( V_3 -> V_36 == V_152 )
|| ( V_3 -> V_36 == V_417 ) )
V_112 |= 0x80 ;
if ( V_3 -> V_36 == V_153 )
V_112 |= 0x80 ;
F_4 ( V_3 -> V_445 , 0x0C , V_112 ) ;
}
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
V_112 = 0 ;
V_423 = 0xfb ;
if ( V_3 -> V_39 & V_481 ) {
V_423 = 0xff ;
if ( V_3 -> V_39 & V_118 )
V_112 |= 0x04 ;
}
F_12 ( V_3 -> V_438 , 0x13 , V_423 , V_112 ) ;
V_112 = 0x00 ;
V_423 = 0xcf ;
if ( ! ( V_3 -> V_39 & V_482 ) ) {
if ( V_3 -> V_39 & V_481 )
V_112 |= 0x30 ;
}
F_12 ( V_3 -> V_438 , 0x2c , V_423 , V_112 ) ;
V_112 = 0 ;
V_423 = 0x3f ;
if ( ! ( V_3 -> V_39 & V_482 ) ) {
if ( V_3 -> V_39 & V_481 )
V_112 |= 0xc0 ;
}
F_12 ( V_3 -> V_445 , 0x21 , V_423 , V_112 ) ;
}
V_112 = 0 ;
V_423 = 0x7f ;
if ( ! ( V_3 -> V_39 & V_118 ) ) {
V_423 = 0xff ;
if ( ! ( V_3 -> V_39 & V_481 ) )
V_112 |= 0x80 ;
}
F_12 ( V_3 -> V_445 , 0x23 , V_423 , V_112 ) ;
if ( V_3 -> V_96 & ( V_98 | V_149 ) ) {
if ( V_3 -> V_38 & V_514 ) {
F_20 ( V_3 -> V_445 , 0x27 , 0x20 ) ;
F_20 ( V_3 -> V_445 , 0x34 , 0x10 ) ;
}
}
}
void F_109 ( struct V_122 * V_123 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_438 , 0x2f , 0xFF , 0x01 ) ;
}
void F_110 ( struct V_122 * V_123 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_438 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_111 ( struct V_2 * V_3 )
{
unsigned short V_475 ;
if ( V_3 -> V_146 == 1 ) {
return 1 ;
} else {
V_475 = F_2 ( V_3 -> V_445 , 0x00 ) ;
if ( ( V_475 == 1 ) || ( V_475 == 2 ) )
return 1 ;
else
return 0 ;
}
}
unsigned short F_112 ( struct V_122 * V_532 ,
unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
short V_639 [] = { 0x00 , 0x00 , 0x03 , 0x01 } ,
V_640 [] = { 0x00 , 0x00 , 0x03 , 0x01 , 0x01 ,
0x01 , 0x01 } ;
unsigned short V_139 , V_114 , V_115 , V_183 , V_105 ;
V_115 = V_3 -> V_7 [ V_111 ] . V_116 ;
V_183 = F_2 ( V_3 -> V_125 , 0x33 ) ;
V_183 = V_183 >> V_3 -> V_641 ;
V_183 &= 0x0F ;
if ( V_3 -> V_38 & V_154 )
V_183 = 0 ;
if ( V_183 > 0 )
V_183 -- ;
if ( V_3 -> V_160 & V_452 ) {
if ( V_3 -> V_39 & ( V_120 | V_118 ) ) {
if ( V_3 -> V_146 == 0 ) {
if ( V_3 -> V_96 & ( V_167 | V_168
| V_97 | V_98
| V_149 ) )
V_105 = V_640 [
V_3 -> V_36 & 0x0F ] ;
else
V_105 = V_639 [
V_3 -> V_36 & 0x0F ] ;
if ( V_183 > V_105 )
V_183 = V_105 ;
} else {
V_183 = 0 ;
}
}
}
V_139 = V_3 -> V_7 [ V_111 ] . V_642 ;
V_110 = V_3 -> V_10 [ V_139 ] . V_145 ;
if ( V_532 -> V_181 >= V_102 ) {
if ( ( V_3 -> V_10 [ V_139 ] . V_643 == 800 ) &&
( V_3 -> V_10 [ V_139 ] . V_644 == 600 ) ) {
V_183 ++ ;
}
if ( ( V_3 -> V_10 [ V_139 ] . V_643 == 1024 ) &&
( V_3 -> V_10 [ V_139 ] . V_644 == 768 ) ) {
V_183 ++ ;
}
if ( ( V_3 -> V_10 [ V_139 ] . V_643 == 1280 ) &&
( V_3 -> V_10 [ V_139 ] . V_644 == 1024 ) ) {
V_183 ++ ;
}
}
V_114 = 0 ;
do {
if ( V_3 -> V_10 [ V_139 + V_114 ] .
V_145 != V_110 )
break;
V_105 = V_3 -> V_10 [ V_139 + V_114 ] .
V_174 ;
V_105 &= V_480 ;
if ( V_105 < V_3 -> V_135 )
break;
V_114 ++ ;
V_183 -- ;
} while ( V_183 != 0xFFFF );
if ( ! ( V_3 -> V_39 & V_147 ) ) {
if ( V_3 -> V_39 & V_121 ) {
V_105 = V_3 -> V_10 [ V_139 + V_114 - 1 ] .
V_174 ;
if ( V_105 & V_210 )
V_114 ++ ;
}
}
V_114 -- ;
if ( ( V_3 -> V_160 & V_452 ) ) {
V_105 = F_14 ( V_110 , V_111 ,
V_139 , & V_114 , V_3 ) ;
}
return V_139 + V_114 ;
}
static void F_113 ( unsigned short V_110 , unsigned short V_111 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_139 ;
V_3 -> V_160 |= V_452 ;
V_139 = F_112 ( V_123 , V_110 ,
V_111 , V_3 ) ;
F_35 ( V_110 , V_111 , V_3 ) ;
F_38 ( V_110 , V_111 , V_139 , V_3 ) ;
F_39 ( V_110 , V_111 , V_139 ,
V_123 , V_3 ) ;
F_43 ( V_110 , V_111 , V_139 , V_3 ) ;
F_47 ( V_110 , V_111 , V_139 , V_3 ) ;
}
static unsigned char F_114 ( unsigned short V_110 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_141 , V_111 , V_139 ;
V_141 = V_3 -> V_39 ;
V_3 -> V_160 |= V_452 ;
F_53 ( V_110 , & V_111 , V_3 ) ;
V_3 -> V_641 = 4 ;
V_139 = F_112 ( V_123 , V_110 ,
V_111 , V_3 ) ;
F_65 ( V_110 , V_3 ) ;
F_66 ( V_110 , V_111 , V_3 ) ;
F_69 ( V_110 , V_111 , V_139 , V_3 ) ;
F_75 ( V_110 , V_111 , V_123 ,
V_139 , V_3 ) ;
F_76 ( V_110 , V_111 , V_123 ,
V_139 , V_3 ) ;
F_78 ( V_110 , V_111 , V_123 ,
V_139 , V_3 ) ;
F_79 ( V_110 , V_111 , V_139 ,
V_123 , V_3 ) ;
F_80 ( V_110 , V_111 , V_123 ,
V_139 , V_3 ) ;
F_82 ( V_3 ) ;
F_83 ( V_110 , V_111 , V_3 ) ;
F_84 ( V_110 , V_111 , V_139 ,
V_123 , V_3 ) ;
F_70 ( V_110 , V_111 , V_139 , V_3 ) ;
F_86 ( V_110 , V_111 , V_3 ) ;
F_64 ( V_3 ) ;
return 1 ;
}
void F_115 ( struct V_2 * V_3 )
{
unsigned char V_645 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_646 = 0 , V_647 = 0 , V_648 = 0 , V_649 = 0 ;
unsigned char V_650 , V_651 , V_652 ;
unsigned short V_105 ;
unsigned char V_653 [ 3 ] = { 0x0F , 0x0F , 0x0F } ;
int V_114 ;
F_4 ( V_3 -> V_109 , 0x05 , 0x86 ) ;
F_4 ( V_3 -> V_125 , 0x57 , 0x4A ) ;
F_4 ( V_3 -> V_125 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_125 , 0x53 ) | 0x02 ) ) ;
V_652 = ( unsigned char ) F_2 ( V_3 -> V_109 , 0x31 ) ;
V_651 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x63 ) ;
V_646 = ( unsigned char ) F_2 ( V_3 -> V_109 , 0x01 ) ;
F_4 ( V_3 -> V_109 , 0x01 , ( unsigned char ) ( V_646 & 0xDF ) ) ;
F_4 ( V_3 -> V_125 , 0x63 , ( unsigned char ) ( V_651 & 0xBF ) ) ;
V_650 = ( unsigned char ) F_2 ( V_3 -> V_125 , 0x17 ) ;
F_4 ( V_3 -> V_125 , 0x17 , ( unsigned char ) ( V_650 | 0x80 ) ) ;
V_647 = ( unsigned char ) F_2 ( V_3 -> V_109 , 0x1F ) ;
F_4 ( V_3 -> V_109 , 0x1F , ( unsigned char ) ( V_647 | 0x04 ) ) ;
V_648 = ( unsigned char ) F_2 ( V_3 -> V_109 , 0x07 ) ;
F_4 ( V_3 -> V_109 , 0x07 , ( unsigned char ) ( V_648 & 0xFB ) ) ;
V_649 = ( unsigned char ) F_2 ( V_3 -> V_109 , 0x06 ) ;
F_4 ( V_3 -> V_109 , 0x06 , ( unsigned char ) ( V_649 & 0xC3 ) ) ;
F_4 ( V_3 -> V_125 , 0x11 , 0x00 ) ;
for ( V_114 = 0 ; V_114 < 8 ; V_114 ++ )
F_4 ( V_3 -> V_125 , ( unsigned short ) V_114 , V_645 [ V_114 ] ) ;
for ( V_114 = 8 ; V_114 < 11 ; V_114 ++ )
F_4 ( V_3 -> V_125 , ( unsigned short ) ( V_114 + 8 ) ,
V_645 [ V_114 ] ) ;
for ( V_114 = 11 ; V_114 < 13 ; V_114 ++ )
F_4 ( V_3 -> V_125 , ( unsigned short ) ( V_114 + 4 ) ,
V_645 [ V_114 ] ) ;
for ( V_114 = 13 ; V_114 < 16 ; V_114 ++ )
F_4 ( V_3 -> V_109 , ( unsigned short ) ( V_114 - 3 ) ,
V_645 [ V_114 ] ) ;
F_4 ( V_3 -> V_109 , 0x0E , ( unsigned char ) ( V_645 [ 16 ]
& 0xE0 ) ) ;
F_4 ( V_3 -> V_109 , 0x31 , 0x00 ) ;
F_4 ( V_3 -> V_109 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_109 , 0x2C , 0xE1 ) ;
F_8 ( 0x00 , V_3 -> V_264 ) ;
for ( V_114 = 0 ; V_114 < 256 ; V_114 ++ ) {
F_8 ( ( unsigned char ) V_653 [ 0 ] , ( V_3 -> V_264 + 1 ) ) ;
F_8 ( ( unsigned char ) V_653 [ 1 ] , ( V_3 -> V_264 + 1 ) ) ;
F_8 ( ( unsigned char ) V_653 [ 2 ] , ( V_3 -> V_264 + 1 ) ) ;
}
F_60 ( 1 ) ;
F_63 ( V_3 ) ;
V_105 = F_7 ( V_3 -> V_176 ) ;
if ( V_105 & 0x10 )
F_12 ( V_3 -> V_125 , 0x32 , 0xDF , 0x20 ) ;
else
F_12 ( V_3 -> V_125 , 0x32 , 0xDF , 0x00 ) ;
F_8 ( 0x00 , V_3 -> V_264 ) ;
for ( V_114 = 0 ; V_114 < 256 ; V_114 ++ ) {
F_8 ( 0 , ( V_3 -> V_264 + 1 ) ) ;
F_8 ( 0 , ( V_3 -> V_264 + 1 ) ) ;
F_8 ( 0 , ( V_3 -> V_264 + 1 ) ) ;
}
F_4 ( V_3 -> V_109 , 0x01 , V_646 ) ;
F_4 ( V_3 -> V_125 , 0x63 , V_651 ) ;
F_4 ( V_3 -> V_109 , 0x31 , V_652 ) ;
F_4 ( V_3 -> V_125 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_125 , 0x53 ) & 0xFD ) ) ;
F_4 ( V_3 -> V_109 , 0x1F , ( unsigned char ) V_647 ) ;
}
static void F_116 ( struct V_525 * V_526 ,
struct V_122 * V_123 ,
struct V_2 * V_3 )
{
unsigned short V_112 ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
if ( ! ( V_3 -> V_160 & V_613 ) ) {
if ( V_3 -> V_160 & V_615 ) {
F_4 ( V_3 -> V_438 , 0x1E , 0x20 ) ;
} else {
if ( V_3 -> V_39 & V_481 ) {
F_4 ( V_3 -> V_438 ,
0x1E , 0x20 ) ;
}
}
}
if ( ! ( V_3 -> V_160 & V_614 ) ) {
if ( ( V_3 -> V_160 & V_616 ) || ( V_3 -> V_39
& ( V_120 | V_119
| V_147 ) ) ) {
V_112 = ( unsigned char ) F_2 (
V_3 -> V_109 , 0x32 ) ;
V_112 &= 0xDF ;
if ( V_3 -> V_39 & V_121 ) {
if ( ! ( V_3 -> V_39 &
V_147 ) )
V_112 |= 0x20 ;
}
F_4 ( V_3 -> V_109 , 0x32 , V_112 ) ;
F_20 ( V_3 -> V_109 , 0x1E , 0x20 ) ;
V_112 = ( unsigned char ) F_2 (
V_3 -> V_438 , 0x2E ) ;
if ( ! ( V_112 & 0x80 ) )
F_20 ( V_3 -> V_438 ,
0x2E , 0x80 ) ;
F_13 ( V_3 -> V_438 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_160 & ( V_615 | V_616 ) )
|| ( ! ( V_3 -> V_39 & V_482 ) ) ) {
F_12 ( V_3 -> V_466 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_96 & ( V_98 | V_149 ) ) {
if ( ! F_92 ( V_3 ) ) {
if ( F_93 ( V_3 ) ||
( V_3 -> V_39 &
( V_120 | V_118 ) ) )
F_13 (
V_3 -> V_445 ,
0x2A ,
0x7F ) ;
}
F_13 ( V_3 -> V_445 , 0x30 , 0x7F ) ;
}
}
V_112 = 0x00 ;
if ( ! ( V_3 -> V_39 & V_482 ) ) {
V_112 = 0xc0 ;
if ( ! ( V_3 -> V_39 & V_492 ) &&
( V_3 -> V_39 & V_118 ) &&
( V_3 -> V_39 & V_481 ) ) {
V_112 = V_112 & 0x40 ;
if ( V_3 -> V_39 & V_118 )
V_112 = V_112 ^ 0xC0 ;
if ( V_3 -> V_160 & V_614 )
V_112 &= 0xBF ;
if ( V_3 -> V_160 & V_613 )
V_112 &= 0x7F ;
if ( V_3 -> V_160 & V_616 )
V_112 |= 0x40 ;
if ( V_3 -> V_160 & V_615 )
V_112 |= 0x80 ;
}
}
F_20 ( V_3 -> V_445 , 0x1F , V_112 ) ;
if ( ! ( V_3 -> V_160 & V_613 ) ) {
if ( ! ( V_3 -> V_160 & V_617 ) ) {
F_88 ( V_123 ,
V_3 ) ;
F_61 ( V_526 , V_123 ,
V_3 ) ;
}
}
}
else {
if ( V_3 -> V_39 & ( V_119 | V_120
| V_118 ) )
F_20 ( V_3 -> V_438 , 0x1E , 0x20 ) ;
V_112 = ( unsigned char ) F_2 ( V_3 -> V_438 ,
0x2E ) ;
if ( ! ( V_112 & 0x80 ) )
F_20 ( V_3 -> V_438 , 0x2E , 0x80 ) ;
F_13 ( V_3 -> V_438 , 0x00 , 0x7F ) ;
F_61 ( V_526 , V_123 , V_3 ) ;
}
}
static void F_117 ( struct V_525 * V_526 ,
struct V_122 * V_123 ,
unsigned short V_110 , unsigned short V_111 ,
struct V_2 * V_3 )
{
unsigned short V_139 , V_105 ;
F_3 ( V_110 , V_111 , V_3 ) ;
F_8 ( V_3 -> V_4 -> V_654 , V_3 -> V_176 ) ;
F_5 ( V_123 , V_3 ) ;
F_6 ( V_110 , V_111 , V_3 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
if ( V_123 -> V_181 == V_104 ) {
if ( V_3 -> V_146 == 0 )
F_11 ( V_3 ) ;
}
V_105 = ~ V_452 ;
V_3 -> V_160 &= V_105 ;
V_3 -> V_641 = 0 ;
if ( V_3 -> V_96 & ( V_167 | V_168 | V_97
| V_98 | V_149 ) ) {
if ( V_3 -> V_39 & ( V_492 | V_118
| V_121 ) ) {
V_3 -> V_160 |= V_452 ;
}
}
V_139 = F_112 ( V_123 , V_110 ,
V_111 , V_3 ) ;
if ( V_139 != 0xFFFF ) {
F_15 ( V_139 , V_3 ) ;
F_18 ( V_110 , V_111 , V_139 ,
V_3 , V_123 ) ;
F_25 ( V_123 , V_110 , V_111 ,
V_139 , V_3 ) ;
F_26 ( V_110 , V_111 , V_139 ,
V_123 , V_3 ) ;
F_28 ( V_110 , V_111 , V_123 ,
V_139 , V_3 ) ;
}
if ( V_123 -> V_181 >= V_243 ) {
V_105 = F_2 ( V_3 -> V_125 , 0x38 ) ;
if ( V_105 & 0xA0 ) {
if ( V_123 -> V_181 == V_104 )
F_21 ( V_110 , V_111 ,
V_139 , V_3 ) ;
else
F_19 ( V_110 , V_111 ,
V_139 , V_3 ) ;
F_24 ( V_110 , V_3 ,
V_139 ) ;
F_23 ( V_123 -> V_181 ,
V_3 , V_139 , V_110 ) ;
if ( V_3 -> V_146 == 1 )
F_90 ( V_526 ,
V_123 -> V_181 ,
V_110 , V_111 , V_3 ) ;
}
}
V_3 -> V_160 &= ( ~ V_452 ) ;
F_30 ( V_110 , V_123 , V_3 ) ;
F_32 ( V_123 , V_110 , V_111 ,
V_139 , V_3 ) ;
F_34 ( V_110 , V_111 , V_3 ) ;
}
unsigned char F_118 ( struct V_525 * V_526 ,
struct V_122 * V_123 ,
unsigned short V_110 )
{
unsigned short V_111 ;
struct V_2 V_655 ;
struct V_2 * V_3 = & V_655 ;
V_3 -> V_656 = V_526 -> V_657 ;
V_3 -> V_146 = 0 ;
V_3 -> V_483 = 1 ;
if ( V_123 -> V_181 >= V_102 ) {
V_3 -> V_487 = 0 ;
V_3 -> V_489 = 0 ;
V_3 -> V_494 = 0 ;
V_3 -> V_96 = 0 ;
} else {
V_3 -> V_487 = 1 ;
V_3 -> V_489 = 1 ;
V_3 -> V_494 = 1 ;
}
V_3 -> V_109 = V_3 -> V_656 + 0x14 ;
V_3 -> V_125 = V_3 -> V_656 + 0x24 ;
V_3 -> V_131 = V_3 -> V_656 + 0x10 ;
V_3 -> V_134 = V_3 -> V_656 + 0x1e ;
V_3 -> V_176 = V_3 -> V_656 + 0x12 ;
V_3 -> V_198 = V_3 -> V_656 + 0x1C ;
V_3 -> V_459 = V_3 -> V_656 + 0x1a ;
V_3 -> V_263 = V_3 -> V_656 + 0x16 ;
V_3 -> V_658 = V_3 -> V_656 + 0x17 ;
V_3 -> V_264 = V_3 -> V_656 + 0x18 ;
V_3 -> V_253 = V_3 -> V_656 + 0x19 ;
V_3 -> V_130 = V_3 -> V_656 + 0x2A ;
V_3 -> V_659 = V_3 -> V_656 + V_660 ;
V_3 -> V_438 = V_3 -> V_656 + V_661 ;
V_3 -> V_466 = V_3 -> V_656 + V_662 ;
V_3 -> V_584 = V_3 -> V_656 + V_663 ;
V_3 -> V_445 = V_3 -> V_656 + V_664 ;
V_3 -> V_589 = V_3 -> V_656 + V_664 + 2 ;
if ( V_123 -> V_181 == V_243 ) {
if ( ( F_2 ( V_3 -> V_125 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_146 = 1 ;
}
if ( V_123 -> V_181 == V_104 ) {
if ( ( F_2 ( V_3 -> V_125 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_2 ( V_3 -> V_125 , 0x30 ) & 0x20 )
V_3 -> V_146 = 1 ;
}
}
if ( V_123 -> V_181 < V_102 )
F_49 ( V_3 ) ;
F_1 ( V_123 -> V_181 , V_3 ) ;
if ( V_110 & 0x80 )
V_110 = V_110 & 0x7F ;
F_4 ( V_3 -> V_109 , 0x05 , 0x86 ) ;
if ( V_123 -> V_181 < V_102 )
F_109 ( V_123 , V_3 ) ;
F_53 ( V_110 , & V_111 , V_3 ) ;
if ( V_123 -> V_181 < V_102 ) {
F_50 ( V_110 , V_111 , V_123 , V_3 ) ;
F_51 ( V_110 , V_111 , V_3 ) ;
F_52 ( V_110 , V_111 , V_3 ) ;
F_94 ( V_526 , V_123 , V_3 ) ;
if ( V_3 -> V_39 & ( V_492 | V_118 ) ) {
F_117 ( V_526 , V_123 , V_110 ,
V_111 , V_3 ) ;
if ( V_3 -> V_39 & V_118 ) {
F_113 ( V_110 , V_111 ,
V_123 , V_3 ) ;
}
} else {
if ( ! ( V_3 -> V_39 & V_493 ) ) {
F_117 ( V_526 ,
V_123 , V_110 ,
V_111 , V_3 ) ;
if ( V_3 -> V_39 & V_118 ) {
F_113 ( V_110 , V_111 ,
V_123 ,
V_3 ) ;
}
}
}
if ( V_3 -> V_39 & ( V_492 | V_493 ) ) {
switch ( V_123 -> V_665 ) {
case V_666 :
F_114 ( V_110 , V_123 ,
V_3 ) ;
break;
case V_667 :
F_114 ( V_110 , V_123 ,
V_3 ) ;
break;
default:
break;
}
}
F_108 ( V_110 , V_123 , V_3 ) ;
F_107 ( V_110 , V_111 , V_3 ) ;
F_116 ( V_526 , V_123 , V_3 ) ;
}
else {
if ( V_3 -> V_146 == 1 )
if ( ! F_89 ( V_526 , V_110 ,
V_111 ,
V_3 ) )
return 0 ;
V_3 -> V_135 = V_3 -> V_7 [ V_111 ] .
V_116 & V_480 ;
V_3 -> V_160 = 0 ;
V_3 -> V_39 = V_482 ;
F_62 ( V_526 , V_123 , V_3 ) ;
F_117 ( V_526 , V_123 , V_110 ,
V_111 , V_3 ) ;
F_61 ( V_526 , V_123 , V_3 ) ;
}
F_48 ( V_123 , V_3 ) ;
if ( V_123 -> V_181 < V_102 )
F_110 ( V_123 , V_3 ) ;
return 1 ;
}
