void F_1 ( unsigned char V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = V_5 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = 0 ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = V_12 ;
V_3 -> V_13 = V_14 ;
if ( ( V_3 -> V_15 & V_16 ) || ( V_3 -> V_15 & V_17 ) )
V_3 -> V_18 = V_19 ;
else
V_3 -> V_18 = V_20 ;
if ( V_1 >= V_21 )
V_3 -> V_22 = 0x10 ;
if ( V_1 == V_23 ) {
unsigned char V_24 ;
V_3 -> V_4 = V_25 ;
V_3 -> V_13 = V_26 ;
V_3 -> V_22 = 0xc1 ;
V_3 -> V_11 = V_27 ;
V_24 = F_2 ( V_3 -> V_28 , 0x3B ) ;
if ( ( ( V_24 & 0x88 ) == 0x80 ) || ( ( V_24 & 0x88 ) == 0x08 ) )
V_3 -> V_22 = 0x80 ;
}
}
static void F_3 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned char V_31 , V_32 ;
unsigned short V_33 , V_34 ;
V_34 = V_35 [ V_30 ] . V_36 ;
F_4 ( V_3 -> V_28 , 0x00 , 0x03 ) ;
V_31 = V_37 . V_38 [ 0 ] ;
V_33 = V_39 ;
if ( V_3 -> V_9 & V_39 ) {
V_31 |= 0x01 ;
} else if ( V_3 -> V_9 & ( V_40 | V_41 ) ) {
if ( V_3 -> V_9 & V_42 )
V_31 |= 0x01 ;
}
V_31 |= 0x20 ;
F_4 ( V_3 -> V_28 , 0x01 , V_31 ) ;
for ( V_33 = 02 ; V_33 <= 04 ; V_33 ++ ) {
V_32 = V_37 . V_38 [ V_33 - 1 ] ;
F_4 ( V_3 -> V_28 , V_33 , V_32 ) ;
}
}
static void F_5 ( struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned char V_45 ;
unsigned short V_33 ;
V_45 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x11 ) ;
V_45 &= 0x7f ;
F_4 ( V_3 -> V_46 , 0x11 , V_45 ) ;
for ( V_33 = 0 ; V_33 <= 0x18 ; V_33 ++ ) {
V_45 = V_37 . V_47 [ V_33 ] ;
F_4 ( V_3 -> V_46 , V_33 , V_45 ) ;
}
}
static void F_6 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned char V_48 ;
unsigned short V_33 , V_34 ;
V_34 = V_35 [ V_30 ] . V_36 ;
for ( V_33 = 0 ; V_33 <= 0x13 ; V_33 ++ ) {
V_48 = V_37 . V_49 [ V_33 ] ;
if ( ( V_34 & V_50 ) && V_33 == 0x13 ) {
if ( V_3 -> V_9 & V_39 ) {
V_48 = 0 ;
} else if ( ( V_3 -> V_9 &
( V_40 | V_41 ) ) &&
( V_3 -> V_9 & V_42 ) ) {
V_48 = 0 ;
}
}
F_7 ( V_3 -> V_51 ) ;
F_8 ( V_33 , V_3 -> V_52 ) ;
F_8 ( V_48 , V_3 -> V_52 ) ;
}
F_7 ( V_3 -> V_51 ) ;
F_8 ( 0x14 , V_3 -> V_52 ) ;
F_8 ( 0x00 , V_3 -> V_52 ) ;
F_7 ( V_3 -> V_51 ) ;
F_8 ( 0x20 , V_3 -> V_52 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
unsigned char V_53 ;
unsigned short V_33 ;
for ( V_33 = 0 ; V_33 <= 0x08 ; V_33 ++ ) {
V_53 = V_37 . V_54 [ V_33 ] ;
F_4 ( V_3 -> V_55 , V_33 , V_53 ) ;
}
if ( V_3 -> V_56 > V_57 ) {
V_53 = ( unsigned char ) F_2 ( V_3 -> V_55 , 0x05 ) ;
V_53 &= 0xBF ;
F_4 ( V_3 -> V_55 , 0x05 , V_53 ) ;
}
}
static void F_10 ( struct V_2 * V_3 )
{
unsigned short V_33 ;
for ( V_33 = 0x0A ; V_33 <= 0x0E ; V_33 ++ )
F_4 ( V_3 -> V_28 , V_33 , 0x00 ) ;
}
static unsigned char F_11 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_28 , 0x31 , ~ 0x30 , 0x20 ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_58 [ 0 ] . V_59 ) ;
F_4 ( V_3 -> V_28 , 0x2C , V_58 [ 0 ] . V_60 ) ;
F_12 ( V_3 -> V_28 , 0x31 , ~ 0x30 , 0x10 ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_58 [ 1 ] . V_59 ) ;
F_4 ( V_3 -> V_28 , 0x2C , V_58 [ 1 ] . V_60 ) ;
F_13 ( V_3 -> V_28 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_14 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 , unsigned short * V_33 ,
struct V_2 * V_3 )
{
unsigned short V_62 , V_63 , V_64 , V_34 , V_65 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_64 = V_35 [ V_30 ] . V_66 ;
V_63 = V_67 [ V_61 + ( * V_33 ) ] . V_68 ;
V_62 = 0 ;
if ( V_3 -> V_69 == 0 ) {
if ( V_3 -> V_9 & V_70 ) {
V_62 |= V_71 ;
if ( V_3 -> V_15 & V_72 )
V_62 |= V_73 ;
}
if ( V_3 -> V_9 & ( V_41 | V_39 ) ) {
V_62 |= V_74 ;
if ( V_3 -> V_6 != V_75 &&
V_3 -> V_6 != V_76 &&
( V_3 -> V_8 & V_77 ) &&
V_64 >= 9 )
return 0 ;
}
if ( V_3 -> V_9 & V_78 ) {
V_62 |= V_79 ;
if ( ( V_3 -> V_9 & V_42 ) &&
( ( V_64 == 4 ) ||
( V_64 == 3 &&
( V_3 -> V_80 & V_81 ) ) ||
( V_64 > 7 ) ) )
return 0 ;
} else if ( V_3 -> V_9 & ( V_82 |
V_83 |
V_84 |
V_85 |
V_78 ) ) {
V_62 |= V_86 ;
if ( V_3 -> V_15 & ( V_87 |
V_88 |
V_16 |
V_17 |
V_72 ) )
V_62 |= V_89 ;
if ( ! ( V_3 -> V_9 & V_90 ) &&
( V_34 & V_91 ) &&
( V_3 -> V_9 & V_42 ) &&
( ! ( V_3 -> V_9 & V_92 ) ) )
return 0 ;
}
} else if ( V_3 -> V_9 & V_41 ) {
V_62 |= V_74 ;
if ( V_64 > 0x08 )
return 0 ;
if ( V_3 -> V_6 < V_93 ) {
if ( V_64 > 0x07 )
return 0 ;
if ( V_64 == 0x04 )
return 0 ;
}
}
for (; V_67 [ V_61 + ( * V_33 ) ] . V_68 ==
V_63 ; ( * V_33 ) -- ) {
V_65 = V_67 [ V_61 + ( * V_33 ) ] .
V_94 ;
if ( V_65 & V_62 )
return 1 ;
if ( ( * V_33 ) == 0 )
break;
}
for ( ( * V_33 ) = 0 ; ; ( * V_33 ) ++ ) {
V_65 = V_67 [ V_61 + ( * V_33 ) ] .
V_94 ;
if ( V_67 [ V_61 + ( * V_33 ) ] . V_68
!= V_63 ) {
return 0 ;
}
if ( V_65 & V_62 )
return 1 ;
}
return 1 ;
}
static void F_15 ( unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_95 , V_24 ;
V_95 = V_67 [ V_61 ] . V_94 >> 8 ;
V_95 &= 0xC0 ;
V_24 = 0x2F ;
V_24 |= V_95 ;
F_8 ( V_24 , V_3 -> V_96 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
unsigned char V_97 , V_98 , V_99 ;
unsigned short V_33 , V_100 ;
V_97 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x11 ) ;
V_97 &= 0x7F ;
F_4 ( V_3 -> V_46 , 0x11 , V_97 ) ;
V_97 = V_3 -> V_101 . V_97 [ 0 ] ;
F_4 ( V_3 -> V_46 , 0 , V_97 ) ;
for ( V_33 = 0x01 ; V_33 <= 0x04 ; V_33 ++ ) {
V_97 = V_3 -> V_101 . V_97 [ V_33 ] ;
F_4 ( V_3 -> V_46 , ( unsigned short ) ( V_33 + 1 ) , V_97 ) ;
}
for ( V_33 = 0x05 ; V_33 <= 0x06 ; V_33 ++ ) {
V_97 = V_3 -> V_101 . V_97 [ V_33 ] ;
F_4 ( V_3 -> V_28 , ( unsigned short ) ( V_33 + 6 ) , V_97 ) ;
}
V_100 = ( unsigned char ) F_2 ( V_3 -> V_28 , 0x0e ) ;
V_100 &= 0x1F ;
V_97 = V_3 -> V_101 . V_97 [ 7 ] ;
V_97 &= 0xE0 ;
V_97 |= V_100 ;
F_4 ( V_3 -> V_28 , 0x0e , V_97 ) ;
if ( V_44 -> V_102 >= V_21 ) {
V_97 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x04 ) ;
V_97 = V_97 - 1 ;
F_4 ( V_3 -> V_46 , 0x04 , V_97 ) ;
V_97 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x05 ) ;
V_98 = V_97 ;
V_98 &= 0xE0 ;
V_97 &= 0x1F ;
if ( V_97 == 0 ) {
V_99 = V_97 ;
V_97 = ( unsigned char ) F_2 ( V_3 -> V_28 ,
0x0c ) ;
V_97 &= 0xFB ;
F_4 ( V_3 -> V_28 , 0x0c , V_97 ) ;
V_97 = V_99 ;
}
V_97 = V_97 - 1 ;
V_97 |= V_98 ;
F_4 ( V_3 -> V_46 , 0x05 , V_97 ) ;
V_97 = ( unsigned char ) F_2 ( V_3 -> V_28 , 0x0e ) ;
V_97 = V_97 >> 5 ;
V_97 = V_97 + 3 ;
if ( V_97 > 7 )
V_97 = V_97 - 7 ;
V_97 = V_97 << 5 ;
F_12 ( V_3 -> V_28 , 0x0e , ~ 0xE0 , V_97 ) ;
}
}
static void F_17 ( unsigned short V_30 ,
unsigned short V_29 ,
struct V_2 * V_3 )
{
unsigned char V_97 ;
unsigned short V_33 , V_100 ;
for ( V_33 = 0x00 ; V_33 <= 0x01 ; V_33 ++ ) {
V_97 = V_3 -> V_103 . V_97 [ V_33 ] ;
F_4 ( V_3 -> V_46 , ( unsigned short ) ( V_33 + 6 ) , V_97 ) ;
}
for ( V_33 = 0x02 ; V_33 <= 0x03 ; V_33 ++ ) {
V_97 = V_3 -> V_103 . V_97 [ V_33 ] ;
F_4 ( V_3 -> V_46 , ( unsigned short ) ( V_33 + 0x0e ) , V_97 ) ;
}
for ( V_33 = 0x04 ; V_33 <= 0x05 ; V_33 ++ ) {
V_97 = V_3 -> V_103 . V_97 [ V_33 ] ;
F_4 ( V_3 -> V_46 , ( unsigned short ) ( V_33 + 0x11 ) , V_97 ) ;
}
V_100 = ( unsigned char ) F_2 ( V_3 -> V_28 , 0x0a ) ;
V_100 &= 0xC0 ;
V_97 = V_3 -> V_103 . V_97 [ 6 ] ;
V_97 &= 0x3F ;
V_97 |= V_100 ;
F_4 ( V_3 -> V_28 , 0x0a , V_97 ) ;
V_97 = V_3 -> V_103 . V_97 [ 6 ] ;
V_97 &= 0x80 ;
V_97 = V_97 >> 2 ;
V_33 = V_35 [ V_30 ] . V_36 ;
V_33 &= V_104 ;
if ( V_33 )
V_97 |= 0x80 ;
V_100 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x09 ) ;
V_100 &= 0x5F ;
V_97 |= V_100 ;
F_4 ( V_3 -> V_46 , 0x09 , V_97 ) ;
}
static void F_18 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 ,
struct V_43 * V_44 )
{
unsigned char V_105 , V_97 ;
unsigned short V_33 ;
V_105 = V_67 [ V_61 ] . V_106 ;
V_105 = V_105 & V_107 ;
V_97 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x11 ) ;
V_97 &= 0x7F ;
F_4 ( V_3 -> V_46 , 0x11 , V_97 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
V_3 -> V_101 . V_97 [ V_33 ]
= V_108 [ V_105 ] . V_109 [ V_33 ] ;
for ( V_33 = 0 ; V_33 < 7 ; V_33 ++ )
V_3 -> V_103 . V_97 [ V_33 ]
= V_108 [ V_105 ] . V_109 [ V_33 + 8 ] ;
F_16 ( V_3 , V_44 ) ;
F_17 ( V_30 , V_29 , V_3 ) ;
if ( V_3 -> V_56 > 0x03 )
F_4 ( V_3 -> V_46 , 0x14 , 0x4F ) ;
}
static void F_19 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned char V_105 , V_110 , V_111 , V_112 , V_113 ;
unsigned short V_114 , V_115 , V_116 ;
V_105 = V_67 [ V_61 ] . V_106 ;
V_110 = V_108 [ V_105 ] . V_109 [ 3 ] ;
V_112 = V_110 ;
F_4 ( V_3 -> V_28 , 0x2E , V_110 ) ;
V_113 = V_108 [ V_105 ] . V_109 [ 5 ] ;
V_113 &= 0xC0 ;
V_114 = V_113 ;
V_114 <<= 2 ;
V_114 |= V_110 ;
V_110 = V_108 [ V_105 ] . V_109 [ 4 ] ;
V_110 &= 0x1F ;
V_111 = V_108 [ V_105 ] . V_109 [ 6 ] ;
V_111 &= 0x04 ;
V_111 <<= 3 ;
V_110 |= V_111 ;
V_115 = V_114 & 0x3C0 ;
V_115 |= V_110 ;
V_112 &= 0x3F ;
if ( V_110 < V_112 )
V_115 |= 0x40 ;
V_115 &= 0xFF ;
V_110 = ( unsigned char ) V_115 ;
V_110 <<= 2 ;
V_113 >>= 6 ;
V_110 |= V_113 ;
F_4 ( V_3 -> V_28 , 0x2F , V_110 ) ;
F_12 ( V_3 -> V_28 , 0x30 , 0xE3 , 00 ) ;
V_110 = V_108 [ V_105 ] . V_109 [ 10 ] ;
V_111 = V_110 ;
V_110 &= 0x01 ;
F_20 ( V_3 -> V_28 , 0x33 , V_110 ) ;
V_110 = V_108 [ V_105 ] . V_109 [ 9 ] ;
V_112 = V_111 >> 1 ;
V_113 = V_110 & 0x04 ;
V_113 <<= 5 ;
V_112 |= V_113 ;
F_4 ( V_3 -> V_28 , 0x34 , V_112 ) ;
V_114 = V_113 ;
V_114 <<= 1 ;
V_114 |= V_111 ;
V_110 &= 0x80 ;
V_115 = V_110 << 2 ;
V_114 |= V_115 ;
V_110 = V_108 [ V_105 ] . V_109 [ 14 ] ;
V_110 &= 0x08 ;
V_115 = V_110 ;
V_115 <<= 7 ;
V_114 |= V_115 ;
V_110 = V_108 [ V_105 ] . V_109 [ 11 ] ;
V_110 &= 0x0F ;
V_111 = V_108 [ V_105 ] . V_109 [ 14 ] ;
V_111 &= 0x20 ;
V_111 >>= 1 ;
V_110 |= V_111 ;
V_115 = V_114 & 0x7E0 ;
V_115 |= V_110 ;
V_116 = V_114 & 0x1F ;
if ( V_110 < V_116 )
V_115 |= 0x20 ;
V_115 &= 0xFF ;
V_110 = ( unsigned char ) V_115 ;
V_110 <<= 2 ;
V_114 &= 0x600 ;
V_114 >>= 9 ;
V_111 = ( unsigned char ) V_114 ;
V_110 |= V_111 ;
V_110 &= 0x7F ;
F_4 ( V_3 -> V_28 , 0x3F , V_110 ) ;
}
static void F_21 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_105 , V_110 , V_111 , V_112 ;
V_105 = V_67 [ V_61 ] . V_106 ;
V_110 = V_108 [ V_105 ] . V_109 [ 3 ] ;
V_111 = V_110 ;
F_4 ( V_3 -> V_28 , 0x2E , V_110 ) ;
V_110 = V_108 [ V_105 ] . V_109 [ 5 ] ;
V_110 &= 0xC0 ;
V_111 |= ( V_110 << 2 ) ;
V_110 = V_108 [ V_105 ] . V_109 [ 4 ] ;
V_110 &= 0x1F ;
V_112 = V_110 ;
V_110 = V_108 [ V_105 ] . V_109 [ 6 ] ;
V_110 &= 0x04 ;
V_110 <<= 3 ;
V_112 |= V_110 ;
V_111 = V_111 & 0x3C0 ;
V_111 |= V_112 ;
V_110 = V_108 [ V_105 ] . V_109 [ 3 ] ;
V_110 &= 0x3F ;
if ( V_112 <= V_110 )
V_111 += 0x40 ;
V_110 = V_108 [ V_105 ] . V_109 [ 5 ] ;
V_110 &= 0xC0 ;
V_110 >>= 6 ;
V_110 |= ( ( V_111 << 2 ) & 0xFF ) ;
F_4 ( V_3 -> V_28 , 0x2F , V_110 ) ;
F_12 ( V_3 -> V_28 , 0x30 , 0xE3 , 00 ) ;
V_110 = V_108 [ V_105 ] . V_109 [ 10 ] ;
F_4 ( V_3 -> V_28 , 0x34 , V_110 ) ;
V_112 = V_110 ;
V_110 = V_108 [ V_105 ] . V_109 [ 9 ] ;
V_111 = V_110 ;
V_110 = V_110 & 0x04 ;
V_110 >>= 2 ;
F_12 ( V_3 -> V_28 , 0x35 , ~ 0x01 , V_110 ) ;
V_112 |= ( V_110 << 8 ) ;
V_112 |= ( ( V_111 & 0x80 ) << 2 ) ;
V_110 = V_108 [ V_105 ] . V_109 [ 14 ] ;
V_110 &= 0x08 ;
V_112 |= ( V_110 << 7 ) ;
V_110 = V_108 [ V_105 ] . V_109 [ 11 ] ;
V_110 &= 0x0F ;
V_111 = V_108 [ V_105 ] . V_109 [ 14 ] ;
V_111 &= 0x20 ;
V_111 >>= 1 ;
V_110 |= V_111 ;
V_111 = V_112 ;
V_111 &= 0x7E0 ;
V_111 |= V_110 ;
if ( V_111 <= V_112 )
V_111 |= 0x20 ;
V_110 = ( V_111 << 2 ) & 0xFF ;
F_12 ( V_3 -> V_28 , 0x3F , ~ 0xFC , V_110 ) ;
V_110 = V_112 >> 8 ;
F_12 ( V_3 -> V_28 , 0x35 , ~ 0x07 , V_110 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned char V_24 ;
V_24 = F_2 ( V_3 -> V_46 , 0x37 ) ;
V_24 = ( V_24 & 3 ) << 6 ;
F_12 ( V_3 -> V_28 , 0x06 , ~ 0xc0 , V_24 & 0x80 ) ;
F_12 ( V_3 -> V_28 , 0x09 , ~ 0xc0 , V_24 | 0x80 ) ;
}
static void F_23 ( int V_117 ,
struct V_2 * V_3 ,
unsigned short V_61 ,
unsigned short V_29 )
{
unsigned short V_118 , V_119 ;
unsigned short V_120 ;
V_120 = V_3 -> V_121 ;
F_4 ( V_3 -> V_46 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_46 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_46 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_46 , 0x47 , 0x00 ) ;
if ( V_117 == V_23 ) {
V_119 = F_2 ( V_3 -> V_46 , 0x37 ) ;
if ( ( V_119 & 0x03 ) == 0 ) {
F_4 ( V_3 -> V_46 , 0x46 , 0x13 ) ;
F_4 ( V_3 -> V_46 , 0x47 , 0x13 ) ;
}
}
if ( V_117 == V_23 ) {
F_22 ( V_3 ) ;
} else {
V_119 = F_2 ( V_3 -> V_46 , 0x37 ) ;
if ( V_119 & 0x01 ) {
F_20 ( V_3 -> V_28 , 0x06 , 0x40 ) ;
F_20 ( V_3 -> V_28 , 0x09 , 0x40 ) ;
}
}
F_20 ( V_3 -> V_28 , 0x1E , 0x01 ) ;
F_13 ( V_3 -> V_28 , 0x30 , ~ 0x20 ) ;
F_13 ( V_3 -> V_28 , 0x35 , ~ 0x80 ) ;
V_118 = V_67 [ V_61 ] . V_94 ;
if ( V_118 & 0x4000 )
F_20 ( V_3 -> V_28 , 0x30 , 0x20 ) ;
if ( V_118 & 0x8000 )
F_20 ( V_3 -> V_28 , 0x35 , 0x80 ) ;
}
static void F_24 ( unsigned short V_29 ,
struct V_2 * V_3 ,
unsigned short V_61 )
{
int V_105 = - 1 ;
F_13 ( V_3 -> V_46 , 0x11 , 0x7F ) ;
if ( V_29 == 0x2E &&
( V_67 [ V_61 ] . V_106 ==
V_122 ) )
V_105 = 12 ;
else if ( V_29 == 0x2E && ( V_67 [ V_61 ] .
V_106 == V_123 ) )
V_105 = 13 ;
else if ( V_29 == 0x2F )
V_105 = 14 ;
else if ( V_29 == 0x50 )
V_105 = 15 ;
else if ( V_29 == 0x59 )
V_105 = 16 ;
if ( V_105 != - 1 ) {
F_4 ( V_3 -> V_46 , 0x02 ,
V_124 [ V_105 ] . V_125 ) ;
F_4 ( V_3 -> V_46 , 0x03 ,
V_124 [ V_105 ] . V_126 ) ;
F_4 ( V_3 -> V_46 , 0x15 ,
V_124 [ V_105 ] . V_127 ) ;
F_4 ( V_3 -> V_46 , 0x16 ,
V_124 [ V_105 ] . V_128 ) ;
}
}
static void F_25 ( struct V_43 * V_44 ,
unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_129 , V_62 , V_63 , V_130 , V_24 , V_34 ;
unsigned char V_97 ;
V_129 = V_35 [ V_30 ] . V_66 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_62 = V_131 [ V_129 ] . V_132 ;
V_63 = V_131 [ V_129 ] . V_133 ;
if ( V_34 & V_134 )
V_62 = V_62 >> 1 ;
if ( V_34 & V_134 )
V_62 = V_62 << 1 ;
V_24 = V_67 [ V_61 ] . V_94 ;
if ( V_24 & V_135 )
V_63 = V_63 >> 1 ;
if ( V_34 & V_104 )
V_63 = V_63 << 1 ;
V_130 = 8 ;
V_62 /= V_130 ;
V_62 -= 1 ;
V_63 -= 1 ;
V_130 = V_62 ;
V_24 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x11 ) ;
V_97 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x11 ) ;
V_97 &= 0x7F ;
F_4 ( V_3 -> V_46 , 0x11 , V_97 ) ;
F_4 ( V_3 -> V_46 , 0x01 , ( unsigned short ) ( V_130 & 0xff ) ) ;
F_12 ( V_3 -> V_46 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_130 & 0x0ff00 ) >> 10 ) ) ;
F_4 ( V_3 -> V_46 , 0x12 , ( unsigned short ) ( V_63 & 0xff ) ) ;
V_62 = 0 ;
V_63 = V_63 >> 8 ;
if ( V_63 & 0x01 )
V_62 |= 0x02 ;
if ( V_63 & 0x02 )
V_62 |= 0x40 ;
F_12 ( V_3 -> V_46 , 0x07 , ~ 0x42 , V_62 ) ;
V_97 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x07 ) ;
V_97 &= 0xFF ;
V_62 = 0 ;
if ( V_63 & 0x04 )
V_62 |= 0x02 ;
F_12 ( V_3 -> V_46 , 0x0a , ~ 0x02 , V_62 ) ;
F_4 ( V_3 -> V_46 , 0x11 , V_24 ) ;
}
static void F_26 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_24 , V_136 , V_137 , V_138 , V_33 , V_139 ;
V_24 = V_35 [ V_30 ] . V_140 ;
V_24 = V_24 >> 8 ;
V_24 = V_141 [ V_24 ] ;
V_138 = V_67 [ V_61 ] . V_94 ;
V_138 &= V_135 ;
if ( V_138 )
V_24 = V_24 << 1 ;
V_138 = V_3 -> V_56 - V_142 ;
switch ( V_138 ) {
case 0 :
V_138 = 1 ;
break;
case 1 :
V_138 = 2 ;
break;
case 2 :
V_138 = 4 ;
break;
case 3 :
V_138 = 4 ;
break;
case 4 :
V_138 = 6 ;
break;
case 5 :
V_138 = 8 ;
break;
default:
break;
}
if ( ( V_29 >= 0x26 ) && ( V_29 <= 0x28 ) )
V_24 = V_24 * V_138 + V_138 / 2 ;
else
V_24 *= V_138 ;
V_139 = V_24 ;
V_138 = V_24 ;
V_24 = V_24 >> 8 ;
V_24 &= 0x0F ;
V_33 = F_2 ( V_3 -> V_28 , 0x0E ) ;
V_33 &= 0xF0 ;
V_33 |= V_24 ;
F_4 ( V_3 -> V_28 , 0x0E , V_33 ) ;
V_24 = ( unsigned char ) V_138 ;
V_24 &= 0xFF ;
F_4 ( V_3 -> V_46 , 0x13 , V_24 ) ;
V_138 = V_67 [ V_61 ] . V_94 ;
V_138 &= V_135 ;
if ( V_138 )
V_139 >>= 1 ;
V_139 = V_139 << 5 ;
V_136 = ( V_139 & 0xff00 ) >> 8 ;
V_137 = V_139 & 0x00ff ;
if ( V_137 == 0 )
V_136 += 1 ;
else
V_136 += 2 ;
if ( V_44 -> V_102 >= V_21 )
if ( ( V_29 == 0x4A ) | ( V_29 == 0x49 ) )
V_136 -= 1 ;
F_4 ( V_3 -> V_28 , 0x10 , V_136 ) ;
}
static unsigned short F_27 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_143 , V_144 ;
unsigned short V_34 , V_64 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_64 = V_35 [ V_30 ] . V_66 ;
V_143 = V_67 [ V_61 ] . V_145 ;
if ( V_3 -> V_69 == 0 ) {
V_143 = V_143 >> 6 ;
if ( V_3 -> V_9 &
( V_41 | V_39 ) ) {
if ( V_3 -> V_6 != V_93 )
V_144 = V_146 + 5 ;
else
V_144 = V_147 + 2 ;
} else if ( V_3 -> V_9 & V_78 ) {
if ( V_3 -> V_80 & V_148 )
V_144 = V_149 + V_150 ;
else
V_144 = V_149 + V_151 ;
if ( V_3 -> V_80 & V_81 ) {
if ( V_34 & V_50 ) {
V_144 = V_149 +
V_152 ;
} else {
V_144 = V_149 +
V_153 ;
}
}
if ( V_3 -> V_15 & V_16 ) {
if ( V_3 -> V_80 & V_148 )
V_144 = V_154 ;
else
V_144 = V_155 ;
}
} else if ( V_3 -> V_9 & V_40 ) {
if ( V_3 -> V_80 & V_148 )
V_144 = V_149 + V_156 ;
else
V_144 = V_149 + V_157 ;
} else {
V_144 = V_67 [ V_61 ] .
V_158 ;
V_144 &= V_107 ;
}
} else if ( ( V_3 -> V_6 == V_159 ) ||
( V_3 -> V_6 == V_160 ) ) {
V_144 = V_161 ;
} else {
V_144 = V_147 + 2 ;
}
return V_144 ;
}
static void F_28 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_43 * V_44 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned char V_105 , V_97 ;
unsigned short V_162 ;
if ( V_3 -> V_69 == 1 ) {
V_105 = V_67 [ V_61 ] . V_158 ;
V_97 = F_2 ( V_3 -> V_28 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_28 , 0x31 , V_97 ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_58 [ V_105 ] . V_59 ) ;
F_4 ( V_3 -> V_28 , 0x2C , V_58 [ V_105 ] . V_60 ) ;
F_4 ( V_3 -> V_28 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) && ( V_3 -> V_9
& V_39 ) ) {
V_162 = F_27 ( V_29 , V_30 ,
V_61 , V_44 ,
V_3 ) ;
V_97 = F_2 ( V_3 -> V_28 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_28 , 0x31 , V_97 ) ;
V_97 = V_163 [ V_162 ] . V_164 ;
F_4 ( V_3 -> V_28 , 0x2B , V_97 ) ;
V_97 = V_163 [ V_162 ] . V_165 ;
F_4 ( V_3 -> V_28 , 0x2C , V_97 ) ;
F_4 ( V_3 -> V_28 , 0x2D , 0x01 ) ;
} else {
V_105 = V_67 [ V_61 ] . V_158 ;
V_97 = F_2 ( V_3 -> V_28 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_28 , 0x31 , V_97 ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_58 [ V_105 ] . V_59 ) ;
F_4 ( V_3 -> V_28 , 0x2C , V_58 [ V_105 ] . V_60 ) ;
F_4 ( V_3 -> V_28 , 0x2D , 0x01 ) ;
}
if ( V_44 -> V_102 >= V_21 ) {
if ( V_35 [ V_30 ] . V_36 &
V_134 ) {
V_97 = F_2 ( V_3 -> V_28 , 0x2B ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_97 ) ;
V_97 = F_2 ( V_3 -> V_28 , 0x2C ) ;
V_105 = V_97 ;
V_105 &= 0xE0 ;
V_97 &= 0x1F ;
V_97 = V_97 << 1 ;
V_97 += 1 ;
V_97 |= V_105 ;
F_4 ( V_3 -> V_28 , 0x2C , V_97 ) ;
}
}
}
static void F_29 ( struct V_2 * V_3 )
{
unsigned char V_24 ;
V_24 = F_2 ( V_3 -> V_46 , 0x37 ) ;
V_24 = ( V_24 & 1 ) << 6 ;
F_12 ( V_3 -> V_28 , 0x06 , ~ 0x40 , V_24 ) ;
F_12 ( V_3 -> V_28 , 0x09 , ~ 0xc0 , V_24 | 0x80 ) ;
}
static void F_30 ( unsigned short V_29 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_97 ;
V_97 = F_2 ( V_3 -> V_28 , 0x3D ) ;
V_97 &= 0xfe ;
F_4 ( V_3 -> V_28 , 0x3D , V_97 ) ;
F_4 ( V_3 -> V_28 , 0x08 , 0x34 ) ;
V_97 = F_2 ( V_3 -> V_28 , 0x09 ) ;
V_97 &= 0xC0 ;
F_4 ( V_3 -> V_28 , 0x09 , V_97 | 0x30 ) ;
V_97 = F_2 ( V_3 -> V_28 , 0x3D ) ;
V_97 |= 0x01 ;
F_4 ( V_3 -> V_28 , 0x3D , V_97 ) ;
if ( V_44 -> V_102 == V_166 )
F_29 ( V_3 ) ;
}
static void F_31 ( struct V_43 * V_44 ,
unsigned short V_29 , unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_97 , V_167 = 0 ;
short V_168 ;
unsigned char V_105 ;
V_105 = V_67 [ V_61 ] . V_158 ;
V_105 &= V_107 ;
V_168 = V_58 [ V_105 ] . CLOCK ;
V_97 = F_2 ( V_3 -> V_28 , 0x32 ) ;
V_97 &= 0xf3 ;
if ( V_168 >= 200 )
V_97 |= 0x0c ;
if ( V_44 -> V_102 >= V_21 )
V_97 &= ~ 0x04 ;
F_4 ( V_3 -> V_28 , 0x32 , V_97 ) ;
if ( V_44 -> V_102 < V_21 ) {
V_97 = F_2 ( V_3 -> V_28 , 0x1F ) ;
V_97 &= 0xE7 ;
if ( V_168 < 200 )
V_97 |= 0x10 ;
F_4 ( V_3 -> V_28 , 0x1F , V_97 ) ;
}
V_167 = 0x00 ;
F_12 ( V_3 -> V_28 , 0x07 , 0xFC , V_167 ) ;
if ( V_44 -> V_102 >= V_23 )
F_12 ( V_3 -> V_28 , 0x40 , 0xFC , V_167 & 0x03 ) ;
}
static void F_32 ( struct V_43 * V_44 ,
unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_97 , V_167 , V_169 , V_65 = 0 , V_34 , V_129 ,
V_170 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_65 = V_67 [ V_61 ] . V_94 ;
if ( F_2 ( V_3 -> V_46 , 0x31 ) & 0x01 )
F_12 ( V_3 -> V_28 , 0x1F , 0x3F , 0x00 ) ;
V_97 = V_65 ;
V_167 = 0 ;
V_167 |= 0x02 ;
V_169 = V_3 -> V_56 - V_57 ;
V_169 = V_169 << 2 ;
V_167 |= V_169 ;
V_97 &= V_135 ;
if ( V_97 )
V_167 |= 0x20 ;
F_12 ( V_3 -> V_28 , 0x06 , ~ 0x3F , V_167 ) ;
V_129 = V_35 [ V_30 ] . V_66 ;
V_170 = V_131 [ V_129 ] . V_132 ;
V_97 = 0x0000 ;
if ( V_65 & V_135 ) {
if ( V_170 == 1024 )
V_97 = 0x0035 ;
else if ( V_170 == 1280 )
V_97 = 0x0048 ;
}
V_167 = V_97 & 0x00FF ;
F_12 ( V_3 -> V_46 , 0x19 , 0xFF , V_167 ) ;
V_167 = ( V_97 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_46 , 0x19 , 0xFC , V_167 ) ;
if ( V_34 & V_134 )
F_12 ( V_3 -> V_28 , 0x01 , 0xF7 , 0x08 ) ;
V_167 = 0 ;
if ( V_34 & V_171 )
V_167 |= 0x08 ;
F_12 ( V_3 -> V_28 , 0x0F , ~ 0x48 , V_167 ) ;
V_97 = 0x60 ;
V_97 = V_97 ^ 0x60 ;
V_97 = V_97 ^ 0xA0 ;
F_12 ( V_3 -> V_28 , 0x21 , 0x1F , V_97 ) ;
F_31 ( V_44 , V_29 , V_61 ,
V_3 ) ;
V_97 = F_2 ( V_3 -> V_46 , 0x31 ) ;
if ( V_44 -> V_102 == V_23 ) {
if ( V_97 & 0x40 )
V_97 = 0x2c ;
else
V_97 = 0x6c ;
F_4 ( V_3 -> V_46 , 0x52 , V_97 ) ;
F_20 ( V_3 -> V_46 , 0x51 , 0x10 ) ;
} else if ( V_44 -> V_102 >= V_21 ) {
if ( V_97 & 0x40 )
V_97 = 0x33 ;
else
V_97 = 0x73 ;
F_4 ( V_3 -> V_46 , 0x52 , V_97 ) ;
F_4 ( V_3 -> V_46 , 0x51 , 0x02 ) ;
} else {
if ( V_97 & 0x40 )
V_97 = 0x2c ;
else
V_97 = 0x6c ;
F_4 ( V_3 -> V_46 , 0x52 , V_97 ) ;
}
}
static void F_33 ( unsigned short V_172 ,
unsigned short V_136 ,
unsigned short V_137 ,
unsigned short V_173 ,
struct V_2 * V_3 )
{
unsigned short V_24 , V_174 , V_175 ;
V_174 = V_136 ;
V_175 = V_137 ;
if ( V_172 != 0 ) {
V_24 = V_174 ;
V_174 = V_173 ;
V_173 = V_24 ;
if ( V_172 == 1 ) {
V_24 = V_175 ;
V_175 = V_173 ;
V_173 = V_24 ;
} else {
V_24 = V_175 ;
V_175 = V_174 ;
V_174 = V_24 ;
}
}
F_8 ( ( unsigned short ) V_173 , V_3 -> V_176 ) ;
F_8 ( ( unsigned short ) V_174 , V_3 -> V_176 ) ;
F_8 ( ( unsigned short ) V_175 , V_3 -> V_176 ) ;
}
static void F_34 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_97 , V_167 , V_33 , V_177 , V_178 , V_179 , V_180 , V_181 , V_182 , V_183 , V_172 , V_137 , V_136 , V_173 ;
const unsigned short * V_184 = V_185 ;
F_8 ( 0xFF , V_3 -> V_186 ) ;
F_8 ( 0x00 , V_3 -> V_187 ) ;
for ( V_33 = 0 ; V_33 < 16 ; V_33 ++ ) {
V_97 = V_184 [ V_33 ] ;
for ( V_177 = 0 ; V_177 < 3 ; V_177 ++ ) {
V_167 = 0 ;
if ( V_97 & 0x01 )
V_167 = 0x2A ;
if ( V_97 & 0x02 )
V_167 += 0x15 ;
F_8 ( V_167 , V_3 -> V_176 ) ;
V_97 = V_97 >> 2 ;
}
}
for ( V_33 = 16 ; V_33 < 32 ; V_33 ++ ) {
V_97 = V_184 [ V_33 ] ;
for ( V_177 = 0 ; V_177 < 3 ; V_177 ++ )
F_8 ( V_97 , V_3 -> V_176 ) ;
}
V_181 = 32 ;
for ( V_178 = 0 ; V_178 < 9 ; V_178 ++ ) {
V_182 = V_181 ;
V_183 = V_181 + 0x04 ;
V_172 = 0 ;
for ( V_179 = 0 ; V_179 < 3 ; V_179 ++ ) {
for ( V_180 = 0 ; V_180 < 5 ; V_180 ++ ) {
V_173 = V_184 [ V_181 ] ;
V_136 = V_184 [ V_182 ] ;
V_137 = V_184 [ V_183 ] ;
V_181 ++ ;
F_33 ( V_172 , V_136 , V_137 , V_173 , V_3 ) ;
}
V_181 -= 2 ;
for ( V_180 = 0 ; V_180 < 3 ; V_180 ++ ) {
V_173 = V_184 [ V_183 ] ;
V_136 = V_184 [ V_182 ] ;
V_137 = V_184 [ V_181 ] ;
V_181 -- ;
F_33 ( V_172 , V_136 , V_137 , V_173 , V_3 ) ;
}
V_172 ++ ;
}
V_181 += 5 ;
}
}
static void F_35 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_129 , V_170 , V_188 , V_34 ;
V_34 = V_35 [ V_30 ] . V_66 ;
V_129 = V_35 [ V_30 ] . V_66 ;
V_170 = V_131 [ V_129 ] . V_132 ;
V_188 = V_131 [ V_129 ] . V_133 ;
if ( V_34 & V_134 )
V_170 = V_170 << 1 ;
if ( V_34 & V_104 )
V_188 = V_188 << 1 ;
if ( V_170 == 720 )
V_170 = 640 ;
V_3 -> V_189 = V_170 ;
V_3 -> V_190 = V_170 ;
V_3 -> V_191 = V_188 ;
V_3 -> V_192 = V_188 ;
}
static void const * F_36 ( struct V_193 const * V_184 ,
unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_33 , V_194 , V_63 , V_34 ;
V_63 = 0 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_33 = 0 ;
while ( V_184 [ V_33 ] . V_195 != 0xff ) {
V_194 = V_3 -> V_6 ;
if ( V_63 & 0x0080 ) {
V_63 &= ( ~ 0x0080 ) ;
V_194 = V_3 -> V_7 ;
}
if ( V_3 -> V_8 & V_196 )
V_194 &= ( ~ V_197 ) ;
if ( V_184 [ V_33 ] . V_195 == V_194 ) {
V_63 = V_184 [ V_33 ] . V_198 ;
V_194 = V_3 -> V_8 ;
if ( V_34 & V_134 )
V_194 |= V_199 ;
V_63 &= V_194 ;
if ( V_63 == V_184 [ V_33 ] . V_200 )
break;
}
V_33 ++ ;
}
return V_184 [ V_33 ] . V_201 ;
}
static struct V_202 const * F_37 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_33 , V_194 , V_203 , V_34 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_203 = V_67 [ V_61 ] . V_145 ;
V_203 = V_203 & 0x3f ;
V_194 = V_3 -> V_10 ;
if ( V_3 -> V_9 & V_42 )
V_194 = V_194 | V_204 ;
if ( V_34 & V_134 )
V_194 = V_194 | V_205 ;
V_33 = 0 ;
while ( V_206 [ V_33 ] . V_198 != 0xffff ) {
if ( ( V_194 & V_206 [ V_33 ] . V_198 ) ==
V_206 [ V_33 ] . V_200 )
break;
V_33 ++ ;
}
return & V_206 [ V_33 ] . V_201 [ V_203 ] ;
}
static void F_38 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
struct V_207 const * V_208 ;
if ( ! ( V_3 -> V_9 & ( V_41 | V_39 ) ) )
return;
V_208 = F_36 ( V_209 , V_29 , V_30 ,
V_61 , V_3 ) ;
V_3 -> V_210 = V_208 -> V_210 ;
V_3 -> V_211 = V_208 -> V_211 ;
V_3 -> V_212 = V_208 -> V_213 ;
V_3 -> V_214 = V_208 -> V_215 ;
if ( V_3 -> V_8 & ( V_216 | V_196 ) )
return;
if ( ( V_3 -> V_6 == V_93 ) ||
( V_3 -> V_6 == V_217 ) ) {
V_3 -> V_190 = 1024 ;
V_3 -> V_192 = 768 ;
} else if ( ( V_3 -> V_6 == V_75 ) ||
( V_3 -> V_6 == V_218 ) ) {
V_3 -> V_190 = 1280 ;
V_3 -> V_192 = 1024 ;
} else if ( V_3 -> V_6 == V_219 ) {
V_3 -> V_190 = 1400 ;
V_3 -> V_192 = 1050 ;
} else {
V_3 -> V_190 = 1600 ;
V_3 -> V_192 = 1200 ;
}
}
static void F_39 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned char V_105 ;
unsigned short V_33 ;
struct V_220 const * V_208 = NULL ;
struct V_221 const * V_222 = NULL ;
V_105 = V_67 [ V_61 ] . V_145 ;
V_105 = V_105 & V_107 ;
if ( V_3 -> V_9 & ( V_41 | V_39 ) ) {
V_208 = F_36 ( V_223 , V_29 , V_30 ,
V_61 , V_3 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
V_3 -> V_101 . V_97 [ V_33 ] = V_208 [ 0 ] . V_224 [ V_33 ] ;
}
F_16 ( V_3 , V_44 ) ;
if ( V_3 -> V_9 & ( V_41 | V_39 ) ) {
V_222 = F_36 ( V_225 , V_29 ,
V_30 , V_61 ,
V_3 ) ;
for ( V_33 = 0 ; V_33 < 7 ; V_33 ++ )
V_3 -> V_103 . V_97 [ V_33 ] = V_222 [ 0 ] . V_224 [ V_33 ] ;
}
F_17 ( V_30 , V_29 , V_3 ) ;
}
static unsigned short F_40 ( struct V_2 * V_3 )
{
unsigned char V_203 , V_31 , V_226 , V_33 ;
V_31 = F_2 ( V_3 -> V_46 , 0x36 ) ;
V_203 = V_31 & 0x0F ;
V_31 = V_31 & 0xF0 ;
V_33 = 0 ;
V_226 = V_3 -> V_18 [ V_33 ] . V_227 ;
while ( V_226 != 0xFF ) {
if ( V_226 & 0x80 ) {
V_203 = V_31 ;
V_226 = V_226 & ~ ( 0x80 ) ;
}
if ( V_203 == V_226 )
break;
V_33 ++ ;
V_226 = V_3 -> V_18 [ V_33 ] . V_227 ;
}
return V_33 ;
}
static unsigned short F_41 ( struct V_2 * V_3 )
{
unsigned short V_31 , V_203 , V_226 , V_33 ;
V_203 = V_3 -> V_6 ;
V_31 = V_3 -> V_7 ;
V_33 = 0 ;
V_226 = V_3 -> V_18 [ V_33 ] . V_227 ;
while ( V_226 != 0xFF ) {
if ( ( V_226 & 0x80 ) && ( V_226 != 0x80 ) ) {
V_203 = V_31 ;
V_226 &= ~ 0x80 ;
}
if ( V_203 == V_226 )
break;
V_33 ++ ;
V_226 = V_3 -> V_18 [ V_33 ] . V_227 ;
}
if ( V_226 == 0xFF ) {
V_3 -> V_6 = V_93 ;
V_3 -> V_7 = 0 ;
V_33 = 0 ;
}
return V_33 ;
}
static void F_42 ( unsigned short * V_228 ,
unsigned short * V_229 ,
struct V_2 * V_3 )
{
unsigned short V_230 ;
V_230 = F_40 ( V_3 ) ;
* V_228 = V_3 -> V_18 [ V_230 ] . V_231 ;
* V_229 = V_3 -> V_18 [ V_230 ] . V_232 ;
return;
}
static void F_43 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_63 , V_62 , V_130 , V_194 , V_233 , V_234 , V_34 ;
unsigned long V_24 , V_235 , V_138 , V_236 , V_237 ;
struct V_238 const * V_208 = NULL ;
struct V_239 const * V_222 = NULL ;
V_34 = V_35 [ V_30 ] . V_36 ;
if ( V_3 -> V_8 & V_196 )
V_222 = F_36 ( V_240 , V_29 ,
V_30 , V_61 ,
V_3 ) ;
else
V_208 = F_36 ( V_240 , V_29 ,
V_30 , V_61 ,
V_3 ) ;
F_42 ( & V_62 , & V_63 , V_3 ) ;
V_233 = V_63 ;
V_234 = V_62 ;
if ( ( V_3 -> V_6 == V_93 ) ||
( V_3 -> V_6 == V_217 ) ) {
V_62 = 1024 ;
V_63 = 768 ;
} else if ( ( V_3 -> V_6 == V_75 ) ||
( V_3 -> V_6 == V_218 ) ) {
V_62 = 1280 ;
V_63 = 1024 ;
} else if ( V_3 -> V_6 == V_219 ) {
V_62 = 1400 ;
V_63 = 1050 ;
} else {
V_62 = 1600 ;
V_63 = 1200 ;
}
if ( V_3 -> V_8 & V_216 ) {
V_3 -> V_190 = V_62 ;
V_3 -> V_192 = V_63 ;
V_3 -> V_189 = V_62 ;
V_3 -> V_191 = V_63 ;
}
V_62 = V_3 -> V_212 ;
if ( V_3 -> V_8 & V_196 )
V_63 = V_222 -> V_241 ;
else
V_63 = V_208 -> V_241 ;
V_130 = V_3 -> V_190 ;
V_63 = V_63 & 0x0fff ;
V_130 += V_63 ;
if ( V_130 >= V_62 )
V_130 -= V_62 ;
F_4 ( V_3 -> V_242 , 0x1A , V_63 & 0x07 ) ;
V_130 = V_130 >> 3 ;
V_63 = V_63 >> 3 ;
F_4 ( V_3 -> V_242 , 0x16 ,
( unsigned short ) ( V_63 & 0xff ) ) ;
F_4 ( V_3 -> V_242 , 0x17 ,
( unsigned short ) ( V_130 & 0xff ) ) ;
V_62 = V_3 -> V_212 ;
if ( V_3 -> V_8 & V_196 )
V_63 = V_222 -> V_243 ;
else
V_63 = V_208 -> V_243 ;
V_130 = V_234 ;
if ( V_3 -> V_8 & V_196 )
V_130 = V_222 -> V_244 ;
V_130 += V_63 ;
if ( V_130 >= V_62 )
V_130 -= V_62 ;
V_62 = V_63 & 0x07 ;
V_62 = V_62 >> 5 ;
V_130 = V_130 >> 3 ;
V_63 = V_63 >> 3 ;
V_130 &= 0x1f ;
V_62 |= V_130 ;
F_4 ( V_3 -> V_242 , 0x15 , V_62 ) ;
F_4 ( V_3 -> V_242 , 0x14 ,
( unsigned short ) ( V_63 & 0xff ) ) ;
V_62 = V_3 -> V_214 ;
if ( V_3 -> V_8 & V_196 )
V_63 = V_222 -> V_245 ;
else
V_63 = V_208 -> V_245 ;
V_130 = V_3 -> V_192 ;
V_63 = V_63 & 0x0fff ;
V_130 += V_63 ;
if ( V_130 >= V_62 )
V_130 -= V_62 ;
F_4 ( V_3 -> V_242 , 0x1b ,
( unsigned short ) ( V_63 & 0xff ) ) ;
F_4 ( V_3 -> V_242 , 0x1c ,
( unsigned short ) ( V_130 & 0xff ) ) ;
V_63 = ( V_63 >> 8 ) & 0x07 ;
V_130 = ( V_130 >> 8 ) & 0x07 ;
F_4 ( V_3 -> V_242 , 0x1d ,
( unsigned short ) ( ( V_130 << 3 )
| V_63 ) ) ;
V_62 = V_3 -> V_214 ;
if ( V_3 -> V_8 & V_196 )
V_63 = V_222 -> V_246 ;
else
V_63 = V_208 -> V_246 ;
V_130 = V_233 ;
if ( V_3 -> V_8 & V_196 )
V_130 = V_222 -> V_247 ;
V_130 += V_63 ;
if ( V_130 >= V_62 )
V_130 -= V_62 ;
F_4 ( V_3 -> V_242 , 0x18 ,
( unsigned short ) ( V_63 & 0xff ) ) ;
F_12 ( V_3 -> V_242 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_130 & 0x0f ) ) ;
V_62 = ( ( V_63 >> 8 ) & 0x07 ) << 3 ;
V_63 = V_3 -> V_191 ;
if ( V_63 != V_3 -> V_192 )
V_62 |= 0x40 ;
if ( V_3 -> V_8 & V_248 )
V_62 |= 0x40 ;
F_12 ( V_3 -> V_242 , 0x1a , 0x07 ,
V_62 ) ;
V_130 = V_3 -> V_211 ;
V_63 = V_3 -> V_192 ;
V_62 = V_3 -> V_191 ;
V_130 -= V_62 ;
V_24 = V_62 ;
V_235 = ( V_24 << 18 ) / V_63 ;
V_194 = ( unsigned short ) ( ( V_24 << 18 ) % V_63 ) ;
if ( V_194 != 0 )
V_235 += 1 ;
V_138 = V_235 ;
V_237 = V_138 ;
F_4 ( V_3 -> V_242 , 0x37 ,
( unsigned short ) ( V_138 & 0xff ) ) ;
F_4 ( V_3 -> V_242 , 0x36 ,
( unsigned short ) ( ( V_138 >> 8 ) & 0xff ) ) ;
V_63 = ( unsigned short ) ( V_138 >> 16 ) ;
V_62 = V_63 & 0x03 ;
V_63 = V_3 -> V_191 ;
if ( V_63 == V_3 -> V_192 )
V_62 |= 0x04 ;
F_4 ( V_3 -> V_242 , 0x35 , V_62 ) ;
if ( V_3 -> V_15 & V_72 ) {
V_138 = V_237 ;
F_4 ( V_3 -> V_249 ,
0x3c ,
( unsigned short ) ( V_138 & 0xff ) ) ;
F_4 ( V_3 -> V_249 ,
0x3b ,
( unsigned short ) ( ( V_138 >> 8 ) &
0xff ) ) ;
V_63 = ( unsigned short ) ( V_138 >> 16 ) ;
F_12 ( V_3 -> V_249 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_63 &
0xff ) << 6 ) ) ;
V_130 = V_3 -> V_191 ;
if ( V_130 == V_3 -> V_192 )
F_12 ( V_3 -> V_249 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_12 ( V_3 -> V_249 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_130 = V_3 -> V_189 ;
V_63 = V_3 -> V_190 ;
V_235 = V_130 << 16 ;
V_62 = ( unsigned short ) ( V_235 / V_63 ) ;
if ( ( V_63 & 0xffff ) == ( V_130 & 0xffff ) )
V_62 = 65535 ;
V_236 = V_62 ;
V_235 = V_3 -> V_189 << 16 ;
V_235 /= V_236 ;
V_236 = V_236 << 16 ;
V_235 -= 1 ;
V_236 = ( V_236 & 0xffff0000 ) + ( V_235 & 0xffff ) ;
V_62 = ( unsigned short ) ( V_236 & 0xff ) ;
F_4 ( V_3 -> V_242 , 0x1f , V_62 ) ;
V_235 = V_3 -> V_191 << 18 ;
V_235 = V_235 / V_237 ;
V_63 = ( unsigned short ) ( V_235 & 0xffff ) ;
if ( V_3 -> V_6 == V_93 )
V_63 -= 1 ;
V_62 = ( ( V_63 >> 8 ) & 0xff ) << 3 ;
V_62 |= ( unsigned short ) ( ( V_236 >> 8 ) & 0x07 ) ;
F_4 ( V_3 -> V_242 , 0x20 ,
( unsigned short ) ( V_62 & 0xff ) ) ;
F_4 ( V_3 -> V_242 , 0x21 ,
( unsigned short ) ( V_63 & 0xff ) ) ;
V_236 = V_236 >> 16 ;
if ( V_34 & V_134 )
V_236 = V_236 >> 1 ;
F_4 ( V_3 -> V_242 , 0x22 ,
( unsigned short ) ( ( V_236 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 -> V_242 , 0x23 ,
( unsigned short ) ( V_236 & 0xff ) ) ;
}
static void F_44 ( unsigned char * V_250 , unsigned char * V_251 ,
struct V_2 * V_3 )
{
unsigned short V_105 ;
if ( V_3 -> V_9 & ( V_41 | V_39 ) ) {
V_105 = F_41 ( V_3 ) ;
if ( V_3 -> V_9 & V_41 ) {
* V_250 = V_3 -> V_18 [ V_105 ] . V_252 ;
* V_251 = V_3 -> V_18 [ V_105 ] . V_253 ;
} else {
* V_250 = V_3 -> V_18 [ V_105 ] . V_254 ;
* V_251 = V_3 -> V_18 [ V_105 ] . V_255 ;
}
}
return;
}
static unsigned char F_45 ( unsigned short V_61 ,
unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_105 , V_34 ;
unsigned char V_203 ;
V_34 = V_35 [ V_30 ] . V_36 ;
if ( ( V_3 -> V_80 & V_256 ) &&
( ! ( V_3 -> V_8 & V_196 ) ) ) {
V_105 = F_40 ( V_3 ) ;
V_203 = V_3 -> V_18 [ V_105 ] . V_257 ;
if ( V_3 -> V_9 & ( V_41 | V_39 ) )
return V_203 ;
if ( V_3 -> V_15 &
( V_87 |
V_88 |
V_16 |
V_17 |
V_72 ) ) {
if ( V_3 -> V_9 & V_78 ) {
V_203 = V_258 + V_150 ;
if ( ! ( V_3 -> V_10 & V_148 ) )
V_203 = V_258 + V_151 ;
if ( V_3 -> V_10 & V_81 ) {
V_203 = V_258 + V_152 ;
if ( ! ( V_34 & V_50 ) )
V_203 = V_258 +
V_153 ;
}
return V_203 ;
}
if ( V_3 -> V_10 & V_259 ) {
V_203 = V_260 ;
return V_203 ;
}
if ( V_3 -> V_10 & V_261 ) {
V_203 = V_262 ;
return V_203 ;
}
V_203 = V_263 ;
if ( ! ( V_3 -> V_10 & V_264 ) ) {
V_203 = V_258 + V_156 ;
if ( ! ( V_3 -> V_10 & V_148 ) )
V_203 = V_258 + V_157 ;
}
if ( V_3 -> V_9 & V_40 )
return V_203 ;
}
}
V_203 = ( unsigned char ) F_7 ( ( V_3 -> V_265 + 0x02 ) ) ;
V_203 = V_203 >> 2 ;
V_203 &= 0x03 ;
if ( ( V_3 -> V_8 & V_196 ) && ( V_34 & V_50 ) )
V_203 = V_203 ^ V_203 ;
V_203 = V_67 [ V_61 ] . V_158 ;
return V_203 ;
}
static void F_46 ( unsigned char V_203 , unsigned char * V_250 ,
unsigned char * V_251 , struct V_2 * V_3 )
{
if ( V_3 -> V_15 & ( V_266 | V_87 | V_88
| V_16 | V_17 | V_72 ) ) {
if ( ( ! ( V_3 -> V_9 & V_39 ) ) &&
( V_3 -> V_80 & V_256 ) ) {
* V_250 = V_163 [ V_203 ] . V_164 ;
* V_251 = V_163 [ V_203 ] . V_165 ;
}
} else {
* V_250 = V_58 [ V_203 ] . V_59 ;
* V_251 = V_58 [ V_203 ] . V_60 ;
}
}
static void F_47 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned char V_250 , V_251 , V_203 ;
int V_33 ;
V_203 = F_45 ( V_61 , V_29 , V_30 ,
V_3 ) ;
F_46 ( V_203 , & V_250 , & V_251 , V_3 ) ;
F_44 ( & V_250 , & V_251 , V_3 ) ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
F_12 ( V_3 -> V_46 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_33 ) ) ;
if ( ( ! ( V_3 -> V_9 & V_39 ) )
&& ( ! ( V_3 -> V_9 & V_42 ) ) ) {
F_4 ( V_3 -> V_28 , 0x2e , V_250 ) ;
F_4 ( V_3 -> V_28 , 0x2f , V_251 ) ;
} else {
F_4 ( V_3 -> V_28 , 0x2b , V_250 ) ;
F_4 ( V_3 -> V_28 , 0x2c , V_251 ) ;
}
}
}
static void F_48 ( struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_267 , V_268 , V_24 , V_226 , V_62 ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
V_267 = 0 ;
V_268 = 0 ;
V_24 = F_2 ( V_3 -> V_28 , 0x01 ) ;
if ( ! ( V_24 & 0x20 ) ) {
V_24 = F_2 ( V_3 -> V_46 , 0x17 ) ;
if ( V_24 & 0x80 ) {
V_24 = F_2 ( V_3 -> V_46 , 0x53 ) ;
if ( ! ( V_24 & 0x40 ) )
V_267 |= V_269 ;
}
}
V_24 = F_2 ( V_3 -> V_242 , 0x2e ) ;
V_24 &= 0x0f ;
if ( ! ( V_24 == 0x08 ) ) {
V_62 = F_2 ( V_3 -> V_242 , 0x13 ) ;
if ( V_62 & 0x04 )
V_267 = V_267 | V_270 ;
V_24 &= 0x05 ;
if ( ! ( V_267 & V_270 ) )
if ( V_24 == 0x01 )
V_267 |= V_271 ;
if ( V_24 == 0x04 )
V_267 |= V_270 ;
if ( V_24 == 0x05 ) {
V_24 = F_2 ( V_3 -> V_272 , 0x00 ) ;
if ( ! ( V_24 & 0x08 ) )
V_268 |= V_273 ;
if ( ! ( V_24 & 0x04 ) )
V_268 |= V_274 ;
if ( V_24 & 0x02 )
V_268 |= V_275 ;
if ( V_3 -> V_9 & V_78 ) {
if ( V_24 & 0x01 )
V_268 |= V_276 ;
}
if ( V_3 -> V_9 & V_85 ) {
V_24 = F_2 (
V_3 -> V_272 ,
0x4d ) ;
if ( V_24 & 0x10 )
V_268 |= V_277 ;
}
if ( V_268 != 0 )
V_267 |= V_278 ;
}
}
V_24 = F_2 ( V_3 -> V_46 , 0x3d ) ;
if ( V_267 & V_270 ) {
if ( ( V_3 -> V_80 & V_279 ) ) {
if ( V_24 & V_278 )
V_267 |= V_278 ;
}
}
V_24 = V_267 ;
V_226 = ~ V_280 ;
F_12 ( V_3 -> V_46 , 0x3d , V_226 , V_24 ) ;
if ( ! ( V_3 -> V_80 & V_279 ) )
F_4 ( V_3 -> V_46 , 0x3e , V_268 ) ;
} else {
return;
}
}
void F_49 ( struct V_2 * V_3 )
{
unsigned short V_281 , V_63 , V_31 ;
if ( V_3 -> V_69 != 0 )
return;
V_63 = V_88 ;
V_281 = F_2 ( V_3 -> V_249 , 0x00 ) ;
if ( V_281 == 0x02 )
goto V_282;
V_63 = V_266 ;
V_281 = F_2 ( V_3 -> V_249 , 0x01 ) ;
if ( V_281 < 0xB0 )
goto V_282;
V_63 = V_87 ;
if ( V_281 < 0xC0 )
goto V_283;
V_63 = V_72 ;
if ( V_281 < 0xD0 )
goto V_283;
V_63 = V_16 ;
if ( V_281 < 0xE0 )
goto V_283;
V_63 = V_17 ;
V_31 = F_2 ( V_3 -> V_249 , 0x39 ) ;
if ( V_31 != 0xFF )
V_63 = V_72 ;
V_283:
if ( V_63 & ( V_87 | V_88 ) ) {
V_281 = F_2 ( V_3 -> V_249 , 0x23 ) ;
if ( ! ( V_281 & 0x02 ) )
V_63 = V_63 | V_284 ;
}
V_282:
V_3 -> V_15 = V_63 ;
}
static void F_50 ( unsigned short V_29 , unsigned short V_30 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_62 , V_285 , V_63 , V_24 , V_34 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_3 -> V_80 = 0 ;
V_3 -> V_56 = V_34 & V_286 ;
V_63 = 0 ;
if ( ! ( V_3 -> V_15 & 0xFFFF ) )
return;
V_24 = F_2 ( V_3 -> V_46 , 0x30 ) ;
V_63 = V_63 | V_24 ;
V_24 = F_2 ( V_3 -> V_46 , 0x31 ) ;
V_285 = V_24 ;
V_285 = V_285 << 8 ;
V_62 = V_24 << 8 ;
V_63 = V_63 | V_62 ;
V_24 = ( V_287 | V_85 | V_39
| V_42 | V_288 ) ;
V_24 = 0xFFFF ^ V_24 ;
V_63 &= V_24 ;
V_24 = F_2 ( V_3 -> V_46 , 0x38 ) ;
if ( V_3 -> V_69 == 0 ) {
if ( V_3 -> V_15 &
( V_88 |
V_16 |
V_17 |
V_72 ) ) {
if ( V_24 & V_289 ) {
V_63 |= V_287 ;
if ( V_24 & V_290 )
V_63 |= V_39 ;
}
}
}
if ( V_3 -> V_291 == 1 ) {
if ( ( ( V_3 -> V_69 == 0 ) &&
( ( V_3 -> V_15 & V_16 ) ||
( V_3 -> V_15 & V_17 ) ||
( V_3 -> V_15 & V_72 ) ) ) ) {
if ( V_24 & V_292 ) {
if ( V_3 -> V_293 == 1 ) {
V_24 = F_2 (
V_3 -> V_46 ,
0x35 ) ;
V_24 &= V_294 ;
V_63 |= V_78 ;
if ( V_24 != V_295 ) {
V_63 &=
( ~ V_78 ) ;
V_63 |=
V_85 ;
}
}
}
}
}
V_62 = V_285 ;
if ( V_3 -> V_69 == 0 ) {
if ( V_3 -> V_291 == 1 ) {
if ( V_3 -> V_293 == 1 )
V_24 = 0x09FC ;
else
V_24 = 0x097C ;
} else if ( V_3 -> V_293 == 1 ) {
V_24 = 0x01FC ;
} else {
V_24 = 0x017C ;
}
} else {
V_24 = V_41 ;
}
if ( ! ( V_63 & V_24 ) ) {
V_62 |= V_288 ;
V_63 = 0 ;
}
if ( ! ( V_3 -> V_15 & V_284 ) ) {
if ( V_63 & V_39 ) {
if ( V_63 & V_296 )
V_63 &= ( ~ ( V_41 |
V_70 |
V_297 ) ) ;
else
V_63 &= ( ~ ( V_41 |
V_70 |
V_40 |
V_297 ) ) ;
}
}
if ( ! ( V_63 & ( V_297 | V_296 ) ) ) {
if ( V_3 -> V_298 == 1 ) {
if ( V_63 & V_70 ) {
V_63 &= ( 0xFF00 |
V_70 |
V_297 |
V_296 ) ;
V_63 &= ( 0x00FF | ( ~ V_85 ) ) ;
}
} else {
V_63 &= ( ~ ( V_70 |
V_41 |
V_40 ) ) ;
}
}
if ( ! ( V_3 -> V_15 & V_284 ) ) {
if ( V_63 & V_41 ) {
V_63 &= ( 0xFF00 |
V_41 |
V_297 |
V_296 ) ;
V_63 &= ( 0x00FF | ( ~ V_85 ) ) ;
}
}
if ( V_63 & V_84 ) {
V_63 &= ( 0xFF00 |
V_84 |
V_297 |
V_296 ) ;
V_63 &= ( 0x00FF | ( ~ V_85 ) ) ;
}
if ( V_3 -> V_291 == 1 ) {
if ( V_63 & V_85 )
V_63 &= ( 0xFF00 |
V_297 |
V_296 ) ;
}
if ( V_3 -> V_293 == 1 ) {
if ( V_63 & V_78 )
V_63 &= ( 0xFF00 |
V_78 |
V_297 |
V_296 ) ;
}
if ( V_62 & V_288 ) {
if ( ! ( V_63 & ( V_297 | V_296 ) ) )
V_63 = V_288 ;
}
if ( ! ( V_63 & V_288 ) ) {
if ( ( ! ( V_63 & V_299 ) ) ||
( ! ( V_34 & V_300 ) ) ) {
if ( ! ( V_63 & V_39 ) )
V_63 |= ( V_42 |
V_296 ) ;
}
if ( ( V_63 & V_42 ) &&
( V_63 & V_39 ) ) {
V_63 ^= ( V_41 |
V_39 |
V_287 ) ;
V_3 -> V_80 |= V_279 ;
}
}
V_3 -> V_9 = V_63 ;
}
static void F_51 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_24 , V_63 = 0 , V_64 = 0 , V_34 , V_301 ;
V_63 = 0 ;
V_64 = 0 ;
if ( V_3 -> V_9 & V_40 ) {
V_34 = V_35 [ V_30 ] . V_36 ;
V_64 = V_35 [ V_30 ] . V_66 ;
if ( V_3 -> V_9 & V_40 ) {
V_24 = F_2 ( V_3 -> V_46 , 0x35 ) ;
V_63 = V_24 ;
if ( V_63 & V_90 ) {
V_63 &= ( V_302 |
V_303 |
V_304 |
V_90 ) ;
if ( V_63 & V_303 )
V_63 &= ~ V_90 ;
} else
V_63 &= ( V_302 |
V_305 |
V_90 ) ;
}
if ( V_3 -> V_69 == 0 ) {
if ( V_3 -> V_9 & V_84 )
V_63 |= V_90 ;
}
if ( V_3 -> V_291 == 1 ) {
if ( V_3 -> V_9 & V_85 ) {
V_301 = F_2 ( V_3 -> V_46 , 0x35 ) ;
V_301 &= V_294 ;
if ( V_301 == V_306 )
V_63 |= V_307 ;
if ( V_301 == V_308 )
V_63 = V_63 | V_261 ;
if ( V_301 == V_309 )
V_63 = V_63 | V_259 ;
}
}
if ( V_3 -> V_293 == 1 ) {
if ( V_3 -> V_9 & V_78 )
V_63 = V_63 | V_310 | V_90 ;
}
if ( V_3 -> V_69 == 0 ) {
if ( ( V_3 -> V_9 & V_42 ) &&
( ! ( V_3 -> V_9 & V_92 ) ) )
V_63 |= V_81 ;
if ( ! ( V_63 & V_90 ) &&
( V_34 > 13 ) &&
( V_64 == 8 ) )
V_63 |= V_264 ;
V_63 |= V_148 ;
if ( V_3 -> V_9 & V_78 ) {
if ( V_3 -> V_9 & V_42 )
V_63 &= ( ~ V_148 ) ;
} else if ( V_63 &
( V_261 | V_259 ) ) {
V_63 &= ( ~ V_148 ) ;
} else if ( ! ( V_3 -> V_15 &
( V_87 |
V_88 |
V_16 |
V_17 |
V_72 ) ) ) {
if ( V_63 & V_81 )
V_63 &= ( ~ V_148 ) ;
}
}
}
V_3 -> V_10 = V_63 ;
}
static unsigned char F_52 ( unsigned short V_29 ,
unsigned short V_30 , struct V_2 * V_3 )
{
unsigned short V_24 , V_62 , V_63 , V_34 , V_64 = 0 , V_311 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = 0 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_64 = V_35 [ V_30 ] . V_66 ;
V_24 = F_2 ( V_3 -> V_46 , 0x36 ) ;
V_63 = V_24 & 0x0F ;
if ( V_63 == 0 )
V_63 = V_93 ;
if ( ( V_63 == V_93 ) || ( V_63 == V_75 ) ) {
if ( V_3 -> V_9 & V_299 ) {
V_62 = F_2 ( V_3 -> V_46 , 0x33 ) ;
if ( V_3 -> V_9 & V_39 )
V_62 &= 0x0F ;
else
V_62 = V_62 >> 4 ;
if ( ( V_64 == 6 ) || ( V_64 == 9 ) ) {
if ( V_62 >= 3 )
V_63 |= V_312 ;
} else if ( ( V_64 == 7 ) || ( V_64 == 8 ) ) {
if ( V_62 >= 4 )
V_63 |= V_312 ;
}
}
}
V_3 -> V_6 = V_63 ;
if ( ! ( V_3 -> V_9 & ( V_41 | V_39 ) ) )
return 0 ;
V_63 = 0 ;
V_24 = F_2 ( V_3 -> V_46 , 0x37 ) ;
V_24 &= ( V_313 | V_77 | V_314 | V_315 ) ;
V_63 |= V_24 ;
V_311 = F_41 ( V_3 ) ;
V_62 = V_3 -> V_18 [ V_311 ] . V_316 ;
if ( V_3 -> V_69 == 0 ) {
if ( ( ( V_3 -> V_15 & V_17 ) || ( V_3 -> V_15
& V_72 ) ) && ( V_62 & V_317 ) ) {
V_63 |= V_318 ;
}
}
if ( V_3 -> V_69 == 0 ) {
if ( ( V_3 -> V_6 == V_219 ) && ( V_3 -> V_9
& V_41 ) && ( V_64 == 9 ) &&
( ! ( V_63 & V_196 ) ) )
V_63 |= V_216 ;
}
if ( V_3 -> V_9 & V_42 ) {
if ( V_3 -> V_9 & V_92 )
V_63 |= V_319 ;
} else {
V_63 |= V_319 ;
}
V_3 -> V_8 = V_63 ;
return 1 ;
}
unsigned char F_53 ( unsigned short V_29 ,
unsigned short * V_30 , struct V_2 * V_3 )
{
for ( * V_30 = 0 ; ; ( * V_30 ) ++ ) {
if ( V_35 [ * V_30 ] . V_320 == V_29 )
break;
if ( V_35 [ * V_30 ] . V_320 == 0xFF )
return 0 ;
}
return 1 ;
}
static unsigned char F_54 ( unsigned char V_321 )
{
unsigned char V_322 = 0 ;
unsigned char V_33 = 0 ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ ) {
V_322 = V_322 << 1 ;
V_322 |= ( V_321 >> V_33 ) & 1 ;
}
return V_322 ;
}
static unsigned char F_55 ( struct V_2 * V_3 )
{
unsigned char V_323 , V_24 ;
V_323 = F_2 ( V_3 -> V_46 , 0x4A ) ;
F_13 ( V_3 -> V_46 , 0x4A , ~ 0x23 ) ;
V_24 = F_2 ( V_3 -> V_46 , 0x48 ) ;
V_24 = F_54 ( V_24 ) ;
V_24 &= 0x23 ;
F_4 ( V_3 -> V_46 , 0x4A , V_323 ) ;
return V_24 ;
}
static unsigned char F_56 ( struct V_2 * V_3 )
{
unsigned char V_323 , V_324 , V_24 ;
V_323 = F_2 ( V_3 -> V_46 , 0x4A ) ;
F_13 ( V_3 -> V_46 , 0x4A , ~ 0x0C ) ;
V_24 = F_2 ( V_3 -> V_46 , 0x48 ) ;
V_24 &= 0x0C ;
V_24 >>= 2 ;
F_4 ( V_3 -> V_46 , 0x4A , V_323 ) ;
V_324 = F_2 ( V_3 -> V_46 , 0xB4 ) ;
V_24 |= ( ( V_324 & 0x04 ) << 3 ) ;
return V_24 ;
}
static void F_57 ( unsigned short V_325 , unsigned short V_226 ,
struct V_2 * V_3 )
{
unsigned char V_323 , V_24 ;
V_323 = F_2 ( V_3 -> V_46 , 0x4A ) ;
V_325 &= 0x23 ;
V_226 &= 0x23 ;
F_13 ( V_3 -> V_46 , 0x4A , ~ V_325 ) ;
if ( V_325 & 0x20 ) {
V_24 = ( V_226 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_46 , 0xB4 , ~ 0x02 , V_24 ) ;
}
V_24 = F_2 ( V_3 -> V_46 , 0x48 ) ;
V_24 = F_54 ( V_24 ) ;
V_24 &= ~ V_325 ;
V_24 |= V_226 ;
F_4 ( V_3 -> V_46 , 0x48 , V_24 ) ;
}
static void F_58 ( unsigned short V_325 , unsigned short V_226 ,
struct V_2 * V_3 )
{
unsigned char V_323 , V_24 ;
unsigned short V_326 , V_327 ;
V_326 = V_325 ;
V_327 = V_226 ;
V_326 &= 0x20 ;
V_327 &= 0x20 ;
V_326 >>= 3 ;
V_327 >>= 3 ;
if ( V_325 & 0x20 ) {
V_24 = ( V_226 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_46 , 0xB4 , ~ 0x02 , V_24 ) ;
}
F_12 ( V_3 -> V_46 , 0xB4 , ~ V_326 , V_327 ) ;
V_323 = F_2 ( V_3 -> V_46 , 0x4A ) ;
V_325 &= 0x03 ;
V_226 &= 0x03 ;
V_325 <<= 2 ;
V_226 <<= 2 ;
F_13 ( V_3 -> V_46 , 0x4A , ~ V_325 ) ;
F_12 ( V_3 -> V_46 , 0x48 , ~ V_325 , V_226 ) ;
}
static void F_59 ( struct V_328 * V_329 ,
struct V_43 * V_330 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_28 , 0x01 , 0xDF , 0x00 ) ;
if ( V_330 -> V_102 == V_166 ) {
if ( V_3 -> V_69 == 1 ) {
if ( ! ( F_55 ( V_3 ) & 0x1 ) ) {
F_57 ( 0x01 , 0x01 , V_3 ) ;
F_60 ( V_329 -> V_331 . V_332 ) ;
}
if ( ! ( F_55 ( V_3 ) & 0x20 ) )
F_57 ( 0x20 , 0x20 , V_3 ) ;
F_60 ( V_329 -> V_331 . V_333 ) ;
F_57 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_57 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_330 -> V_102 == V_23 ) {
if ( V_3 -> V_69 == 1 ) {
if ( ! ( F_56 ( V_3 ) & 0x1 ) ) {
F_58 ( 0x01 , 0x01 , V_3 ) ;
F_60 ( V_329 -> V_331 . V_332 ) ;
}
if ( ! ( F_56 ( V_3 ) & 0x20 ) )
F_58 ( 0x20 , 0x20 , V_3 ) ;
F_60 ( V_329 -> V_331 . V_333 ) ;
F_58 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_58 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_61 ( struct V_328 * V_329 ,
struct V_43 * V_330 ,
struct V_2 * V_3 )
{
if ( V_330 -> V_102 == V_166 ) {
if ( V_3 -> V_69 == 1 ) {
F_57 ( 0x02 , 0x00 , V_3 ) ;
F_60 ( V_329 -> V_331 . V_333 ) ;
} else {
F_57 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_330 -> V_102 == V_23 ) {
if ( ( F_56 ( V_3 ) & 0x2 ) ) {
F_58 ( 0x02 , 0x00 , V_3 ) ;
F_60 ( V_329 -> V_331 . V_333 ) ;
}
if ( V_3 -> V_69 == 0 )
F_58 ( 0x20 , 0x00 , V_3 ) ;
}
F_12 ( V_3 -> V_28 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_62 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 -> V_51 ) & 0x01 ) )
break;
while ( ! ( F_7 ( V_3 -> V_51 ) & 0x01 ) )
break;
}
static void F_63 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_242 , 0x01 , 0x40 ) ;
}
static void F_64 ( unsigned short V_29 ,
struct V_2 * V_3 )
{
unsigned short V_235 , V_138 ;
F_4 ( V_3 -> V_46 , 0x34 , V_29 ) ;
V_235 = ( V_3 -> V_9 & V_42 ) >> 8 ;
V_138 = ~ ( V_42 >> 8 ) ;
F_12 ( V_3 -> V_46 , 0x31 , V_138 , V_235 ) ;
}
static void F_65 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_170 , V_188 , V_34 , V_129 ;
V_129 = V_35 [ V_30 ] . V_66 ;
V_170 = V_131 [ V_129 ] . V_132 ;
V_188 = V_131 [ V_129 ] . V_133 ;
V_34 = V_35 [ V_30 ] . V_36 ;
if ( V_34 & V_134 )
V_170 *= 2 ;
if ( V_34 & V_104 )
V_188 *= 2 ;
if ( ! ( V_3 -> V_9 & V_41 ) )
goto exit;
if ( V_3 -> V_69 == 0 ) {
if ( V_3 -> V_6 == V_334 ) {
if ( ! ( V_3 -> V_8 & V_319 ) ) {
if ( V_188 == 1024 )
V_188 = 1056 ;
}
}
if ( V_3 -> V_6 == V_75 ) {
if ( V_188 == 400 )
V_188 = 405 ;
else if ( V_188 == 350 )
V_188 = 360 ;
if ( V_3 -> V_8 & V_319 ) {
if ( V_188 == 360 )
V_188 = 375 ;
}
}
if ( V_3 -> V_6 == V_93 ) {
if ( ! ( V_3 -> V_8 & V_319 ) ) {
if ( ! ( V_3 -> V_8 & V_77 ) ) {
if ( V_188 == 350 )
V_188 = 357 ;
else if ( V_188 == 400 )
V_188 = 420 ;
else if ( V_188 == 480 )
V_188 = 525 ;
}
}
}
}
if ( V_170 == 720 )
V_170 = 640 ;
exit:
V_3 -> V_189 = V_170 ;
V_3 -> V_190 = V_170 ;
V_3 -> V_191 = V_188 ;
V_3 -> V_192 = V_188 ;
}
static unsigned char F_66 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_9 & ( V_41 | V_39 ) ) &&
( V_3 -> V_8 & V_318 ) )
return 1 ;
return 0 ;
}
static void F_67 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_62 , V_63 , V_235 , V_138 , V_34 = 0 , V_130 ,
V_335 ;
V_3 -> V_336 = 1 ;
V_3 -> V_337 = 1 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_335 = V_67 [ V_61 ] . V_106 ;
V_335 &= V_107 ;
V_235 = ( unsigned short ) V_108 [ V_335 ] . V_109 [ 0 ] ;
V_138 = ( unsigned short ) V_108 [ V_335 ] . V_109 [ 5 ] ;
V_62 = ( V_235 & 0xFF ) | ( ( V_138 & 0x03 ) << 8 ) ;
V_63 = ( unsigned short ) V_108 [ V_335 ] . V_109 [ 8 ] ;
V_130 = ( unsigned short )
V_108 [ V_335 ] . V_109 [ 14 ] << 8 ;
V_130 &= 0x0100 ;
V_130 = V_130 << 2 ;
V_63 |= V_130 ;
V_235 = ( unsigned short ) V_108 [ V_335 ] . V_109 [ 9 ] ;
if ( V_235 & 0x01 )
V_63 |= 0x0100 ;
if ( V_235 & 0x20 )
V_63 |= 0x0200 ;
V_62 += 5 ;
if ( V_34 & V_50 )
V_62 *= 8 ;
else
V_62 *= 9 ;
V_3 -> V_210 = V_62 ;
V_3 -> V_212 = V_62 ;
V_63 ++ ;
V_3 -> V_211 = V_63 ;
V_3 -> V_214 = V_63 ;
}
static void F_68 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_62 = 0 , V_63 = 0 , V_34 , V_64 ;
struct V_338 const * V_208 = NULL ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_64 = V_35 [ V_30 ] . V_66 ;
V_3 -> V_339 = 0 ;
V_3 -> V_340 = 50 ;
if ( V_3 -> V_9 & V_70 ) {
F_67 ( V_29 , V_30 , V_61 ,
V_3 ) ;
return;
}
if ( V_3 -> V_9 & ( V_41 | V_39 ) ) {
V_208 = F_36 ( V_341 , V_29 , V_30 ,
V_61 , V_3 ) ;
V_3 -> V_336 = V_208 -> V_336 ;
V_3 -> V_337 = V_208 -> V_337 ;
V_3 -> V_210 = V_208 -> V_210 ;
V_3 -> V_211 = V_208 -> V_211 ;
V_3 -> V_212 = V_208 -> V_213 ;
V_3 -> V_214 = V_208 -> V_215 ;
if ( V_3 -> V_6 == V_93 ) {
V_62 = 1024 ;
V_63 = 768 ;
if ( ! ( V_3 -> V_8 & V_319 ) ) {
if ( V_3 -> V_191 == 357 )
V_63 = 527 ;
else if ( V_3 -> V_191 == 420 )
V_63 = 620 ;
else if ( V_3 -> V_191 == 525 )
V_63 = 775 ;
else if ( V_3 -> V_191 == 600 )
V_63 = 775 ;
else
V_63 = 768 ;
} else
V_63 = 768 ;
} else if ( V_3 -> V_6 == V_217 ) {
V_62 = 1024 ;
V_63 = 768 ;
} else if ( V_3 -> V_6 == V_75 ) {
V_62 = 1280 ;
if ( V_3 -> V_191 == 360 )
V_63 = 768 ;
else if ( V_3 -> V_191 == 375 )
V_63 = 800 ;
else if ( V_3 -> V_191 == 405 )
V_63 = 864 ;
else
V_63 = 1024 ;
} else if ( V_3 -> V_6 == V_218 ) {
V_62 = 1280 ;
V_63 = 1024 ;
} else if ( V_3 -> V_6 == V_76 ) {
V_62 = 1280 ;
if ( V_3 -> V_191 == 350 )
V_63 = 700 ;
else if ( V_3 -> V_191 == 400 )
V_63 = 800 ;
else if ( V_3 -> V_191 == 1024 )
V_63 = 960 ;
else
V_63 = 960 ;
} else if ( V_3 -> V_6 == V_219 ) {
V_62 = 1400 ;
V_63 = 1050 ;
if ( V_3 -> V_191 == 1024 ) {
V_62 = 1280 ;
V_63 = 1024 ;
}
} else if ( V_3 -> V_6 == V_334 ) {
V_62 = 1600 ;
V_63 = 1200 ;
if ( ! ( V_3 -> V_8 & V_319 ) ) {
if ( V_3 -> V_191 == 350 )
V_63 = 875 ;
else if ( V_3 -> V_191 == 400 )
V_63 = 1000 ;
}
}
if ( V_3 -> V_8 & V_77 ) {
V_62 = V_3 -> V_189 ;
V_63 = V_3 -> V_191 ;
}
V_3 -> V_190 = V_62 ;
V_3 -> V_192 = V_63 ;
return;
}
if ( V_3 -> V_9 & ( V_40 ) ) {
struct V_202 const * V_342 ;
V_342 = F_37 ( V_29 , V_30 , V_61 ,
V_3 ) ;
V_3 -> V_336 = V_342 -> V_336 ;
V_3 -> V_337 = V_342 -> V_337 ;
V_3 -> V_210 = V_342 -> V_210 ;
V_3 -> V_211 = V_342 -> V_211 ;
V_3 -> V_190 = V_342 -> V_343 ;
V_3 -> V_192 = V_342 -> V_344 ;
V_3 -> V_340 = V_342 -> V_340 ;
V_3 -> V_339 = V_342 -> V_345 ;
if ( V_3 -> V_9 & V_78 ) {
if ( V_64 == 0x08 )
V_3 -> V_339 = 0x40 ;
else if ( V_64 == 0x09 )
V_3 -> V_339 = 0x40 ;
else if ( V_64 == 0x12 )
V_3 -> V_339 = 0x40 ;
if ( V_3 -> V_191 == 350 )
V_3 -> V_10 |= V_81 ;
V_62 = V_346 ;
V_63 = V_347 ;
if ( V_3 -> V_9 & V_42 ) {
if ( V_3 -> V_10 & V_81 ) {
V_62 = V_348 ;
V_63 = V_349 ;
if ( ! ( V_34 & V_50 ) ) {
V_62 = V_350 ;
V_63 = V_351 ;
}
}
}
} else if ( V_3 -> V_9 & V_85 ) {
if ( V_3 -> V_10 & V_259 ) {
V_62 = V_352 ;
V_63 = V_353 ;
}
if ( V_3 -> V_10 & V_261 ) {
V_62 = V_354 ;
V_63 = V_355 ;
} else if ( V_3 -> V_10 & V_307 ) {
V_62 = V_356 ;
V_63 = V_357 ;
if ( V_3 -> V_10 & V_264 )
V_62 = V_358 ;
}
} else {
V_62 = V_359 ;
V_63 = V_360 ;
if ( ! ( V_3 -> V_10 & V_90 ) ) {
V_62 = V_361 ;
V_63 = V_362 ;
if ( V_3 -> V_10 & V_264 )
V_62 = V_358 ;
}
}
V_3 -> V_212 = V_62 ;
V_3 -> V_214 = V_63 ;
return;
}
}
static void F_69 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned char V_250 , V_251 , V_203 ;
V_203 = F_45 ( V_61 , V_29 , V_30 ,
V_3 ) ;
F_46 ( V_203 , & V_250 , & V_251 , V_3 ) ;
F_44 ( & V_250 , & V_251 , V_3 ) ;
if ( V_3 -> V_15 & V_266 ) {
F_4 ( V_3 -> V_249 , 0x0A , 0x10 ) ;
F_4 ( V_3 -> V_249 , 0x0B , V_251 ) ;
F_4 ( V_3 -> V_249 , 0x0A , V_250 ) ;
} else {
F_4 ( V_3 -> V_249 , 0x0A , V_250 ) ;
F_4 ( V_3 -> V_249 , 0x0B , V_251 ) ;
}
F_4 ( V_3 -> V_249 , 0x00 , 0x12 ) ;
if ( V_3 -> V_9 & V_70 )
F_20 ( V_3 -> V_249 , 0x12 , 0x28 ) ;
else
F_20 ( V_3 -> V_249 , 0x12 , 0x08 ) ;
}
static unsigned short F_70 ( unsigned short V_29 ,
unsigned short V_30 , struct V_2 * V_3 )
{
unsigned short V_363 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_105 ;
unsigned short V_34 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_105 = ( V_34 & V_286 ) - V_142 ;
if ( V_105 < 0 )
V_105 = 0 ;
return V_363 [ V_105 ] ;
}
static unsigned short F_71 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_24 , V_364 , V_365 , V_105 , V_65 ,
V_363 [] = { 0x01 , 0x02 , 0x04 } ;
V_365 = V_35 [ V_30 ] . V_140 ;
V_65 = V_67 [ V_61 ] . V_94 ;
V_105 = ( V_365 >> 8 ) & 0xFF ;
V_24 = V_141 [ V_105 ] ;
if ( V_65 & V_135 )
V_24 = V_24 << 1 ;
V_364 = F_70 ( V_29 , V_30 , V_3 ) ;
if ( ( V_29 >= 0x7C ) && ( V_29 <= 0x7E ) ) {
V_24 = V_29 - 0x7C ;
V_364 = V_363 [ V_24 ] ;
V_24 = 0x6B ;
if ( V_65 & V_135 )
V_24 = V_24 << 1 ;
return V_24 * V_364 ;
} else {
return V_24 * V_364 ;
}
}
static void F_72 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_61 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_366 ;
unsigned char V_24 ;
if ( V_3 -> V_9 & V_42 )
return;
V_366 = F_71 ( V_29 , V_30 , V_61 ,
V_44 , V_3 ) ;
V_24 = ( unsigned char ) ( V_366 & 0xFF ) ;
F_4 ( V_3 -> V_242 , 0x07 , V_24 ) ;
V_24 = ( unsigned char ) ( ( V_366 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_242 , 0x09 , V_24 ) ;
V_24 = ( unsigned char ) ( ( ( V_366 >> 3 ) & 0xFF ) + 1 ) ;
F_4 ( V_3 -> V_242 , 0x03 , V_24 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
F_4 ( V_3 -> V_242 , 0x01 , 0x3B ) ;
F_12 ( V_3 -> V_242 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_74 ( unsigned short V_29 , unsigned short V_30 ,
struct V_43 * V_44 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_130 = 0 , V_335 = 0 , V_64 = 0 ;
V_335 = V_67 [ V_61 ] . V_106 ;
V_335 &= V_107 ;
V_64 = V_35 [ V_30 ] . V_66 ;
F_72 ( V_29 , V_30 , V_61 ,
V_44 , V_3 ) ;
F_73 ( V_3 ) ;
for ( V_130 = 4 ; V_130 < 7 ; V_130 ++ )
F_4 ( V_3 -> V_242 , V_130 , 0x0 ) ;
F_4 ( V_3 -> V_242 , 0x50 , 0x00 ) ;
F_4 ( V_3 -> V_242 , 0x02 , 0x44 ) ;
}
static void F_75 ( unsigned short V_29 , unsigned short V_30 ,
struct V_43 * V_44 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_24 = 0 , V_62 = 0 , V_63 = 0 , V_130 = 0 ,
V_367 = 0 , V_335 = 0 , V_34 , V_64 = 0 ;
V_335 = V_67 [ V_61 ] . V_106 ;
V_335 &= V_107 ;
V_64 = V_35 [ V_30 ] . V_66 ;
V_34 = V_35 [ V_30 ] . V_36 ;
if ( V_34 & V_134 ) {
V_24 = ( V_3 -> V_210 / 2 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_242 , 0x08 , V_24 ) ;
V_24 = ( ( ( V_3 -> V_210 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_242 , 0x09 , ~ 0x0F0 , V_24 ) ;
V_24 = ( V_3 -> V_189 / 2 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_242 , 0x0A , V_24 ) ;
V_130 = ( ( V_3 -> V_210 - V_3 -> V_189 ) / 2 ) >> 2 ;
V_367 = V_3 -> V_189 / 2 + 16 ;
V_130 = V_130 >> 1 ;
V_63 = V_367 + V_130 ;
V_130 += V_63 ;
if ( V_3 -> V_9 & V_70 ) {
V_63 = V_108 [ V_335 ] . V_109 [ 4 ] ;
V_63 |= ( ( V_108 [ V_335 ] . V_109 [ 14 ] &
0xC0 ) << 2 ) ;
V_63 = ( V_63 - 3 ) << 3 ;
V_130 = V_108 [ V_335 ] . V_109 [ 5 ] ;
V_130 &= 0x1F ;
V_24 = V_108 [ V_335 ] . V_109 [ 15 ] ;
V_24 = ( V_24 & 0x04 ) << ( 5 - 2 ) ;
V_130 = ( ( V_130 | V_24 ) - 3 ) << 3 ;
}
V_63 += 4 ;
V_130 += 4 ;
if ( V_130 > ( V_3 -> V_210 / 2 ) )
V_130 = V_3 -> V_210 / 2 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x0B , V_24 ) ;
} else {
V_24 = ( V_3 -> V_210 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_242 , 0x08 , V_24 ) ;
V_24 = ( ( ( V_3 -> V_210 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_242 , 0x09 , ~ 0x0F0 , V_24 ) ;
V_24 = ( V_3 -> V_189 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_242 , 0x0A , V_24 ) ;
V_130 = ( V_3 -> V_210 - V_3 -> V_189 ) >> 2 ;
V_367 = V_3 -> V_189 + 16 ;
V_130 = V_130 >> 1 ;
V_63 = V_367 + V_130 ;
V_130 += V_63 ;
if ( V_3 -> V_9 & V_70 ) {
V_63 = V_108 [ V_335 ] . V_109 [ 3 ] ;
V_63 |= ( ( V_108 [ V_335 ] . V_109 [ 5 ] &
0xC0 ) << 2 ) ;
V_63 = ( V_63 - 3 ) << 3 ;
V_130 = V_108 [ V_335 ] . V_109 [ 4 ] ;
V_130 &= 0x1F ;
V_24 = V_108 [ V_335 ] . V_109 [ 6 ] ;
V_24 = ( V_24 & 0x04 ) << ( 5 - 2 ) ;
V_130 = ( ( V_130 | V_24 ) - 3 ) << 3 ;
V_63 += 16 ;
V_130 += 16 ;
}
if ( V_130 > V_3 -> V_210 )
V_130 = V_3 -> V_210 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x0B , V_24 ) ;
}
V_62 = ( V_62 & 0x00FF ) | ( V_63 & 0xFF00 ) ;
V_63 = V_367 ;
V_63 = ( V_63 & 0x00FF ) | ( ( V_63 & 0xFF00 ) << 4 ) ;
V_62 |= ( V_63 & 0xFF00 ) ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_242 , 0x0C , V_24 ) ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x0D , V_24 ) ;
V_130 = ( V_3 -> V_211 - 1 ) ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x0E , V_24 ) ;
V_63 = V_3 -> V_191 - 1 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x0F , V_24 ) ;
V_24 = ( ( V_63 & 0xFF00 ) << 3 ) >> 8 ;
V_24 |= ( ( V_130 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_242 , 0x12 , V_24 ) ;
V_62 = V_3 -> V_191 ;
V_63 = V_3 -> V_191 ;
V_130 = V_3 -> V_211 ;
V_63 = ( V_3 -> V_211 + V_3 -> V_191 ) >> 1 ;
V_130 = ( ( V_3 -> V_211 - V_3 -> V_191 ) >> 4 ) + V_63 + 1 ;
if ( V_3 -> V_9 & V_70 ) {
V_63 = V_108 [ V_335 ] . V_109 [ 10 ] ;
V_24 = V_108 [ V_335 ] . V_109 [ 9 ] ;
if ( V_24 & 0x04 )
V_63 |= 0x0100 ;
if ( V_24 & 0x080 )
V_63 |= 0x0200 ;
V_24 = V_108 [ V_335 ] . V_109 [ 14 ] ;
if ( V_24 & 0x08 )
V_63 |= 0x0400 ;
V_24 = V_108 [ V_335 ] . V_109 [ 11 ] ;
V_130 = ( V_130 & 0xFF00 ) | ( V_24 & 0x00FF ) ;
}
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x10 , V_24 ) ;
V_24 = ( ( V_63 & 0xFF00 ) >> 8 ) << 4 ;
V_24 = ( ( V_130 & 0x000F ) | ( V_24 ) ) ;
F_4 ( V_3 -> V_242 , 0x11 , V_24 ) ;
V_62 = 0 ;
if ( V_34 & V_104 )
V_62 |= 0x80 ;
if ( V_34 & V_134 )
V_62 |= 0x40 ;
F_12 ( V_3 -> V_242 , 0x2C , ~ 0x0C0 , V_62 ) ;
}
static unsigned short F_76 ( struct V_2 * V_3 )
{
unsigned long V_62 , V_63 ;
V_63 = ( ( V_3 -> V_211 - V_3 -> V_191 ) * V_3 -> V_336 )
& 0xFFFF ;
V_62 = ( V_3 -> V_214 - V_3 -> V_192 ) * V_3 -> V_337 ;
V_62 = ( V_62 * V_3 -> V_212 ) / V_63 ;
return ( unsigned short ) V_62 ;
}
static void F_77 ( unsigned short V_29 , unsigned short V_30 ,
struct V_43 * V_44 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_233 , V_234 , V_62 , V_63 = 0 , V_130 , V_24 , V_64 ,
V_34 , V_335 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_64 = V_35 [ V_30 ] . V_66 ;
V_335 = V_67 [ V_61 ] . V_106 ;
V_335 &= V_107 ;
if ( ! ( V_3 -> V_9 & V_42 ) )
return;
V_24 = 0xFF ;
F_4 ( V_3 -> V_242 , 0x03 , V_24 ) ;
V_130 = 0x08 ;
if ( V_3 -> V_15 & ( V_16 | V_17 | V_72 ) )
V_34 |= V_50 ;
V_62 = V_3 -> V_189 ;
if ( V_34 & V_134 )
V_62 = V_62 >> 1 ;
V_62 = ( V_62 / V_130 ) - 1 ;
V_63 |= ( ( V_62 & 0x00FF ) << 8 ) ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x04 , V_24 ) ;
V_24 = ( V_63 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_9 & V_40 ) {
if ( ! ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) )
V_24 += 2 ;
if ( ( V_3 -> V_9 & V_78 ) &&
! ( V_3 -> V_15 & V_16 ) && ( V_64 == 7 ) )
V_24 -= 2 ;
}
F_4 ( V_3 -> V_242 , 0x05 , V_24 ) ;
F_4 ( V_3 -> V_242 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_9 & V_288 ) ) {
if ( V_3 -> V_9 & V_40 )
V_62 = V_3 -> V_210 ;
else
V_62 = F_76 ( V_3 ) ;
}
if ( V_62 >= V_3 -> V_210 )
V_62 = V_3 -> V_210 ;
if ( V_34 & V_134 )
V_62 = V_62 >> 1 ;
V_62 = ( V_62 / V_130 ) - 5 ;
V_130 = V_62 ;
if ( V_3 -> V_9 & V_78 ) {
V_24 = ( V_63 & 0x00FF ) - 1 ;
if ( ! ( V_34 & V_134 ) ) {
V_24 -= 6 ;
if ( V_3 -> V_10 & V_81 ) {
V_24 -= 4 ;
V_24 -= 10 ;
}
}
} else {
V_63 = ( V_63 & 0xFF00 ) >> 8 ;
V_130 = ( V_130 + V_63 ) >> 1 ;
V_24 = ( V_130 & 0x00FF ) + 2 ;
if ( V_3 -> V_9 & V_40 ) {
V_24 -= 1 ;
if ( ! ( V_34 & V_134 ) ) {
if ( ( V_34 & V_50 ) ) {
V_24 += 4 ;
if ( V_3 -> V_189 >= 800 )
V_24 -= 6 ;
}
}
} else if ( ! ( V_34 & V_134 ) ) {
V_24 -= 4 ;
if ( V_3 -> V_6 != V_76 &&
V_3 -> V_189 >= 800 ) {
V_24 -= 7 ;
if ( V_3 -> V_189 >= 1280 &&
V_3 -> V_6 != V_76 &&
( V_3 -> V_8 & V_77 ) )
V_24 += 28 ;
}
}
}
F_4 ( V_3 -> V_242 , 0x07 , V_24 ) ;
F_4 ( V_3 -> V_242 , 0x08 , 0 ) ;
if ( V_3 -> V_9 & V_40 ) {
if ( V_3 -> V_10 & V_81 ) {
if ( V_29 == 0x50 ) {
if ( V_3 -> V_10 & V_368 ) {
F_4 ( V_3 -> V_242 ,
0x07 , 0x30 ) ;
F_4 ( V_3 -> V_242 ,
0x08 , 0x03 ) ;
} else {
F_4 ( V_3 -> V_242 ,
0x07 , 0x2f ) ;
F_4 ( V_3 -> V_242 ,
0x08 , 0x02 ) ;
}
}
}
}
F_4 ( V_3 -> V_242 , 0x18 , 0x03 ) ;
F_12 ( V_3 -> V_242 , 0x19 , 0xF0 , 0x00 ) ;
F_4 ( V_3 -> V_242 , 0x09 , 0xFF ) ;
V_63 = V_3 -> V_211 ;
V_233 = V_63 ;
V_130 = 0x121 ;
V_63 = V_3 -> V_191 ;
if ( V_63 == 357 )
V_63 = 350 ;
if ( V_63 == 360 )
V_63 = 350 ;
if ( V_63 == 375 )
V_63 = 350 ;
if ( V_63 == 405 )
V_63 = 400 ;
if ( V_63 == 525 )
V_63 = 480 ;
V_234 = V_63 ;
if ( V_3 -> V_9 & V_41 ) {
if ( V_3 -> V_6 == V_93 ) {
if ( ! ( V_3 -> V_8 & V_319 ) ) {
if ( V_63 == 350 )
V_63 += 5 ;
if ( V_63 == 480 )
V_63 += 5 ;
}
}
}
V_63 -- ;
V_24 = V_63 & 0x00FF ;
V_63 -- ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x10 , V_24 ) ;
V_63 = V_234 ;
V_63 -- ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x0E , V_24 ) ;
if ( V_63 & 0x0100 )
V_130 |= 0x0002 ;
V_62 = 0x000B ;
if ( V_34 & V_104 )
V_62 |= 0x08000 ;
if ( V_63 & 0x0200 )
V_130 |= 0x0040 ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_242 , 0x0B , V_24 ) ;
if ( V_63 & 0x0400 )
V_130 |= 0x0600 ;
F_4 ( V_3 -> V_242 , 0x11 , 0x00 ) ;
V_62 = V_233 ;
V_62 -= V_63 ;
V_62 = V_62 >> 2 ;
V_233 = V_62 ;
if ( V_64 != 0x09 ) {
V_62 = V_62 << 1 ;
V_63 += V_62 ;
}
if ( V_3 -> V_9 & V_78 ) {
if ( ( V_3 -> V_15 & V_16 ) &&
! ( V_3 -> V_10 & V_310 ) ) {
if ( ( V_3 -> V_10 & V_81 ) &&
( V_3 -> V_10 & V_90 ) ) {
if ( ! ( V_3 -> V_15 & V_16 ) ||
! ( V_3 -> V_10 &
( V_261 |
V_259 |
V_310 ) ) )
V_63 += 40 ;
}
} else {
V_63 -= 10 ;
}
} else if ( V_3 -> V_10 & V_81 ) {
if ( V_3 -> V_10 & V_90 ) {
if ( V_3 -> V_15 & V_16 ) {
if ( ! ( V_3 -> V_10 &
( V_261 |
V_259 |
V_310 ) ) )
V_63 += 40 ;
} else {
V_63 += 40 ;
}
}
}
V_62 = V_233 ;
V_62 = V_62 >> 2 ;
V_62 ++ ;
V_62 += V_63 ;
V_233 = V_62 ;
if ( ( V_3 -> V_10 & V_90 ) ) {
if ( V_63 <= 513 ) {
if ( V_62 >= 513 )
V_63 = 513 ;
}
}
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x0C , V_24 ) ;
V_63 -- ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x10 , V_24 ) ;
if ( V_63 & 0x0100 )
V_130 |= 0x0008 ;
if ( V_63 & 0x0200 )
F_12 ( V_3 -> V_242 , 0x0B , 0x0FF , 0x20 ) ;
V_63 ++ ;
if ( V_63 & 0x0100 )
V_130 |= 0x0004 ;
if ( V_63 & 0x0200 )
V_130 |= 0x0080 ;
if ( V_63 & 0x0400 )
V_130 |= 0x0C00 ;
V_63 = V_233 ;
V_24 = V_63 & 0x00FF ;
V_24 &= 0x0F ;
F_4 ( V_3 -> V_242 , 0x0D , V_24 ) ;
if ( V_63 & 0x0010 )
V_130 |= 0x2000 ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_242 , 0x0A , V_24 ) ;
V_24 = ( V_130 & 0x0FF00 ) >> 8 ;
F_4 ( V_3 -> V_242 , 0x17 , V_24 ) ;
V_62 = V_34 ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
V_24 = ( V_24 >> 1 ) & 0x09 ;
if ( V_3 -> V_15 & ( V_16 | V_17 | V_72 ) )
V_24 |= 0x01 ;
F_4 ( V_3 -> V_242 , 0x16 , V_24 ) ;
F_4 ( V_3 -> V_242 , 0x0F , 0 ) ;
F_4 ( V_3 -> V_242 , 0x12 , 0 ) ;
if ( V_3 -> V_8 & V_369 )
V_24 = 0x80 ;
else
V_24 = 0x00 ;
F_4 ( V_3 -> V_242 , 0x1A , V_24 ) ;
return;
}
static void F_78 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_33 , V_100 , V_62 , V_63 , V_130 , V_24 , V_233 , V_234 ,
V_34 , V_64 , V_370 ;
unsigned char const * V_371 ;
unsigned long V_372 , V_373 , V_374 , V_138 , V_375 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_64 = V_35 [ V_30 ] . V_66 ;
V_370 = V_67 [ V_61 ] . V_145 ;
V_62 = 0 ;
if ( ! ( V_3 -> V_9 & V_82 ) )
V_62 |= 0x0800 ;
if ( ! ( V_3 -> V_9 & V_83 ) )
V_62 |= 0x0400 ;
if ( V_3 -> V_9 & V_84 )
V_62 |= 0x0200 ;
if ( ! ( V_3 -> V_10 & V_90 ) )
V_62 |= 0x1000 ;
if ( V_3 -> V_9 & V_78 )
V_62 |= 0x0100 ;
if ( V_3 -> V_10 & ( V_261 | V_259 ) )
V_62 &= 0xfe00 ;
V_62 = ( V_62 & 0xff00 ) >> 8 ;
F_4 ( V_3 -> V_272 , 0x0 , V_62 ) ;
V_371 = V_376 ;
if ( V_3 -> V_10 & V_90 )
V_371 = V_377 ;
if ( V_3 -> V_9 & V_78 ) {
V_371 = V_378 ;
if ( V_3 -> V_9 & V_42 )
V_371 = V_379 ;
if ( V_3 -> V_80 & V_81 )
V_371 = V_380 ;
if ( ! ( V_34 & V_50 ) )
V_371 = V_381 ;
}
if ( V_3 -> V_9 & V_85 ) {
if ( V_3 -> V_10 & V_307 )
V_371 = V_382 ;
if ( V_3 -> V_10 & V_261 )
V_371 = V_383 ;
if ( V_3 -> V_10 & V_259 )
V_371 = V_384 ;
}
for ( V_33 = 0x01 , V_100 = 0 ; V_33 <= 0x2D ; V_33 ++ , V_100 ++ )
F_4 ( V_3 -> V_272 , V_33 , V_371 [ V_100 ] ) ;
for ( V_33 = 0x39 ; V_33 <= 0x45 ; V_33 ++ , V_100 ++ )
F_4 ( V_3 -> V_272 , V_33 , V_371 [ V_100 ] ) ;
if ( V_3 -> V_9 & V_40 )
F_12 ( V_3 -> V_272 , 0x3A , 0x1F , 0x00 ) ;
V_24 = V_3 -> V_339 ;
V_24 &= 0x80 ;
F_12 ( V_3 -> V_272 , 0x0A , 0xFF , V_24 ) ;
if ( V_3 -> V_9 & V_78 )
V_62 = 950 ;
if ( V_3 -> V_10 & V_90 )
V_62 = 520 ;
else
V_62 = 440 ;
if ( V_3 -> V_192 <= V_62 ) {
V_62 -= V_3 -> V_192 ;
V_62 = V_62 >> 2 ;
V_62 = ( V_62 & 0x00FF ) | ( ( V_62 & 0x00FF ) << 8 ) ;
V_233 = V_62 ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
V_24 += ( unsigned short ) V_371 [ 0 ] ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
if ( V_3 -> V_9 & ( V_82
| V_83 | V_84
| V_85 ) ) {
V_130 = V_3 -> V_189 ;
if ( V_130 >= 1024 ) {
V_24 = 0x17 ;
if ( V_3 -> V_10 & V_90 )
V_24 = 0x19 ;
}
}
}
F_4 ( V_3 -> V_272 , 0x01 , V_24 ) ;
V_62 = V_233 ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
V_24 += V_371 [ 1 ] ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
if ( ( V_3 -> V_9 & ( V_82
| V_83 | V_84
| V_85 ) ) ) {
V_130 = V_3 -> V_189 ;
if ( V_130 >= 1024 ) {
V_24 = 0x1D ;
if ( V_3 -> V_10 & V_90 )
V_24 = 0x52 ;
}
}
}
F_4 ( V_3 -> V_272 , 0x02 , V_24 ) ;
}
V_130 = V_3 -> V_212 ;
if ( F_66 ( V_3 ) )
V_130 = V_130 >> 1 ;
V_130 -= 2 ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x1B , V_24 ) ;
V_24 = ( V_130 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_272 , 0x1D , ~ 0x0F , V_24 ) ;
V_130 = V_3 -> V_212 >> 1 ;
V_233 = V_130 ;
V_130 += 7 ;
if ( V_3 -> V_9 & V_78 )
V_130 -= 4 ;
V_24 = V_130 & 0x00FF ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_272 , 0x22 , 0x0F , V_24 ) ;
V_63 = V_371 [ V_100 ] | ( ( V_371 [ V_100 + 1 ] ) << 8 ) ;
V_63 += V_130 ;
V_234 = V_63 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x24 , V_24 ) ;
V_24 = ( V_63 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_272 , 0x25 , 0x0F , V_24 ) ;
V_63 = V_234 ;
V_63 = V_63 + 8 ;
if ( V_3 -> V_9 & V_78 ) {
V_63 = V_63 - 4 ;
V_130 = V_63 ;
}
V_24 = ( V_63 & 0x00FF ) << 4 ;
F_12 ( V_3 -> V_272 , 0x29 , 0x0F , V_24 ) ;
V_100 += 2 ;
V_130 += ( V_371 [ V_100 ] | ( ( V_371 [ V_100 + 1 ] ) << 8 ) ) ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x27 , V_24 ) ;
V_24 = ( ( V_130 & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_272 , 0x28 , 0x0F , V_24 ) ;
V_130 += 8 ;
if ( V_3 -> V_9 & V_78 )
V_130 -= 4 ;
V_24 = V_130 & 0xFF ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_272 , 0x2A , 0x0F , V_24 ) ;
V_130 = V_233 ;
V_100 += 2 ;
V_24 = V_371 [ V_100 ] | ( ( V_371 [ V_100 + 1 ] ) << 8 ) ;
V_130 -= V_24 ;
V_24 = V_130 & 0x00FF ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_272 , 0x2D , 0x0F , V_24 ) ;
V_130 -= 11 ;
if ( ! ( V_3 -> V_9 & V_40 ) ) {
V_62 = F_76 ( V_3 ) ;
V_130 = V_62 - 1 ;
}
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x2E , V_24 ) ;
V_63 = V_3 -> V_192 ;
if ( V_3 -> V_191 == 360 )
V_63 = 746 ;
if ( V_3 -> V_191 == 375 )
V_63 = 746 ;
if ( V_3 -> V_191 == 405 )
V_63 = 853 ;
if ( V_3 -> V_9 & V_40 ) {
if ( V_3 -> V_15 &
( V_16 | V_17 | V_72 ) ) {
if ( ! ( V_3 -> V_10 &
( V_261 | V_259 ) ) )
V_63 = V_63 >> 1 ;
} else
V_63 = V_63 >> 1 ;
}
V_63 -= 2 ;
V_24 = V_63 & 0x00FF ;
if ( V_3 -> V_9 & V_78 ) {
if ( V_3 -> V_15 & V_16 ) {
if ( V_3 -> V_10 & V_310 ) {
if ( V_3 -> V_9 & V_42 ) {
if ( V_29 == 0x2f )
V_24 += 1 ;
}
}
} else if ( V_3 -> V_9 & V_42 ) {
if ( V_29 == 0x2f )
V_24 += 1 ;
}
}
F_4 ( V_3 -> V_272 , 0x2F , V_24 ) ;
V_24 = ( V_130 & 0xFF00 ) >> 8 ;
V_24 |= ( ( V_63 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_9 & V_78 ) ) {
if ( V_3 -> V_15 & V_16 ) {
if ( V_3 -> V_10 & V_310 ) {
V_24 |= 0x10 ;
if ( ! ( V_3 -> V_9 & V_83 ) )
V_24 |= 0x20 ;
}
} else {
V_24 |= 0x10 ;
if ( ! ( V_3 -> V_9 & V_83 ) )
V_24 |= 0x20 ;
}
}
F_4 ( V_3 -> V_272 , 0x30 , V_24 ) ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
V_63 = V_3 -> V_192 ;
V_130 = V_63 - 2 ;
if ( V_3 -> V_9 & V_40 ) {
if ( ! ( V_3 -> V_10 & ( V_261
| V_259 ) ) )
V_63 = V_63 >> 1 ;
}
if ( V_3 -> V_15 & ( V_17 | V_72 ) ) {
V_24 = 0 ;
if ( V_130 & 0x0400 )
V_24 |= 0x20 ;
if ( V_63 & 0x0400 )
V_24 |= 0x40 ;
F_4 ( V_3 -> V_249 , 0x10 , V_24 ) ;
}
V_24 = ( ( ( V_63 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_4 ( V_3 -> V_272 , 0x46 , V_24 ) ;
V_24 = ( V_63 - 3 ) & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x47 , V_24 ) ;
}
V_63 = V_63 & 0x00FF ;
if ( ! ( V_34 & V_134 ) ) {
V_130 = V_3 -> V_189 ;
if ( V_130 >= V_3 -> V_190 ) {
V_63 |= 0x2000 ;
V_62 &= 0x00FF ;
}
}
V_130 = 0x0101 ;
if ( V_3 -> V_9 & V_40 ) {
if ( V_3 -> V_189 >= 1024 ) {
V_130 = 0x1920 ;
if ( V_3 -> V_189 >= 1280 ) {
V_130 = 0x1420 ;
V_63 = V_63 & 0xDFFF ;
}
}
}
if ( ! ( V_63 & 0x2000 ) ) {
if ( V_34 & V_134 )
V_130 = ( V_130 & 0xFF00 ) | ( ( V_130 & 0x00FF ) << 1 ) ;
V_233 = V_63 ;
V_373 = V_3 -> V_189 ;
V_374 = ( V_130 & 0xFF00 ) >> 8 ;
V_372 = V_373 * V_374 ;
V_375 = V_130 & 0x00FF ;
V_372 = V_372 / V_375 ;
V_375 = 8 * 1024 ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
V_375 = V_375 * 8 ;
}
V_372 = V_372 * V_375 ;
V_375 = V_3 -> V_190 ;
V_138 = V_372 % V_375 ;
V_373 = V_372 / V_375 ;
if ( V_138 != 0 )
V_373 += 1 ;
V_62 = ( unsigned short ) V_373 ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
V_130 = ( ( V_62 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_63 = V_233 ;
V_63 = ( unsigned short ) ( ( ( V_373 & 0x0000FF00 ) & 0x1F00 )
| ( V_63 & 0x00FF ) ) ;
V_62 = ( unsigned short ) ( ( ( V_373 & 0x000000FF ) << 8 )
| ( V_62 & 0x00FF ) ) ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
} else {
V_24 = ( V_62 & 0x00FF ) >> 8 ;
}
F_4 ( V_3 -> V_272 , 0x44 , V_24 ) ;
V_24 = ( V_63 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_272 , 0x45 , ~ 0x03F , V_24 ) ;
V_24 = V_130 & 0x00FF ;
if ( V_63 & 0x2000 )
V_24 = 0 ;
if ( ! ( V_3 -> V_9 & V_41 ) )
V_24 |= 0x18 ;
F_12 ( V_3 -> V_272 , 0x46 , ~ 0x1F , V_24 ) ;
if ( V_3 -> V_10 & V_90 ) {
V_63 = 0x0382 ;
V_130 = 0x007e ;
} else {
V_63 = 0x0369 ;
V_130 = 0x0061 ;
}
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x4b , V_24 ) ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x4c , V_24 ) ;
V_24 = ( ( V_130 & 0xFF00 ) >> 8 ) & 0x03 ;
V_24 = V_24 << 2 ;
V_24 |= ( ( V_63 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_9 & V_85 ) {
V_24 |= 0x10 ;
if ( V_3 -> V_10 & V_261 )
V_24 |= 0x20 ;
if ( V_3 -> V_10 & V_259 )
V_24 |= 0x60 ;
}
F_4 ( V_3 -> V_272 , 0x4d , V_24 ) ;
V_24 = F_2 ( V_3 -> V_272 , 0x43 ) ;
F_4 ( V_3 -> V_272 , 0x43 , ( unsigned short ) ( V_24 - 3 ) ) ;
if ( ! ( V_3 -> V_10 & ( V_261 | V_259 ) ) ) {
if ( V_3 -> V_10 & V_264 ) {
V_371 = V_385 ;
for ( V_33 = 0x1c , V_100 = 0 ; V_33 <= 0x30 ; V_33 ++ , V_100 ++ ) {
F_4 ( V_3 -> V_272 , V_33 ,
V_371 [ V_100 ] ) ;
}
F_4 ( V_3 -> V_272 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_15 & V_72 ) {
if ( V_3 -> V_10 & V_303 )
F_12 ( V_3 -> V_272 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_10 & V_303 ) {
V_62 = ( unsigned char ) F_2 ( V_3 -> V_272 ,
0x01 ) ;
V_62 -- ;
F_13 ( V_3 -> V_272 , 0x01 , V_62 ) ;
F_13 ( V_3 -> V_272 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_9 & V_78 ) {
if ( ! ( V_3 -> V_9 & V_42 ) )
F_4 ( V_3 -> V_272 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_9 & V_40 )
return;
}
static void F_79 ( unsigned short V_29 , unsigned short V_30 ,
struct V_43 * V_44 ,
unsigned short V_61 ,
struct V_2 * V_3 )
{
unsigned short V_233 , V_234 , V_367 , V_62 , V_63 , V_130 , V_24 ,
V_31 , V_325 , V_268 , V_64 , V_34 , V_335 ;
struct V_238 const * V_386 = NULL ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_64 = V_35 [ V_30 ] . V_66 ;
V_335 = V_67 [ V_61 ] . V_106 ;
V_335 &= V_107 ;
if ( ! ( V_3 -> V_9 & V_41 ) )
return;
V_63 = V_3 -> V_190 ;
if ( F_66 ( V_3 ) )
V_63 = V_63 >> 1 ;
V_63 -= 1 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x2C , V_24 ) ;
V_24 = ( V_63 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_272 , 0x2B , 0x0F , V_24 ) ;
V_24 = 0x01 ;
F_4 ( V_3 -> V_272 , 0x0B , V_24 ) ;
V_63 = V_3 -> V_192 ;
V_233 = V_63 ;
V_63 -- ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x03 , V_24 ) ;
V_24 = ( ( V_63 & 0xFF00 ) >> 8 ) & 0x07 ;
F_12 ( V_3 -> V_272 , 0x0C , ~ 0x07 , V_24 ) ;
V_130 = V_3 -> V_214 - 1 ;
V_234 = V_130 + 1 ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x19 , V_24 ) ;
V_24 = ( V_130 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 5 ;
F_4 ( V_3 -> V_272 , 0x1A , V_24 ) ;
F_12 ( V_3 -> V_272 , 0x09 , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_272 , 0x0A , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_272 , 0x17 , 0xFB , 0x00 ) ;
F_12 ( V_3 -> V_272 , 0x18 , 0xDF , 0x00 ) ;
if ( ( V_3 -> V_15 & V_16 ) || ( V_3 -> V_15 & V_17 ) )
V_386 = F_36 ( V_387 , V_29 , V_30 ,
V_61 , V_3 ) ;
else
V_386 = F_36 ( V_388 , V_29 ,
V_30 , V_61 ,
V_3 ) ;
V_31 = V_3 -> V_6 ;
V_31 &= V_197 ;
if ( ( V_31 == V_93 ) || ( V_31 == V_217 ) ) {
V_63 = 1024 ;
V_130 = 768 ;
} else if ( ( V_31 == V_75 ) ||
( V_31 == V_218 ) ) {
V_63 = 1280 ;
V_130 = 1024 ;
} else if ( V_31 == V_219 ) {
V_63 = 1400 ;
V_130 = 1050 ;
} else {
V_63 = 1600 ;
V_130 = 1200 ;
}
if ( V_3 -> V_8 & V_196 ) {
V_63 = V_3 -> V_190 ;
V_130 = V_3 -> V_192 ;
}
V_367 = V_63 ;
V_62 = V_3 -> V_214 ;
V_3 -> V_241 = V_386 -> V_241 ;
V_3 -> V_243 = V_386 -> V_243 ;
V_3 -> V_245 = V_386 -> V_245 ;
V_3 -> V_246 = V_386 -> V_246 ;
V_63 = V_3 -> V_245 ;
V_130 += V_63 ;
if ( V_130 >= V_62 )
V_130 -= V_62 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x05 , V_24 ) ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x06 , V_24 ) ;
V_268 = ( ( V_130 & 0xFF00 ) >> 8 ) & 0x07 ;
V_325 = ( ( V_63 & 0xFF00 ) >> 8 ) & 0x07 ;
V_31 = V_268 ;
V_31 = V_31 << 3 ;
V_31 |= V_325 ;
F_4 ( V_3 -> V_272 , 0x02 , V_31 ) ;
F_42 ( & V_62 , & V_63 , V_3 ) ;
V_130 = V_63 ;
V_62 = V_3 -> V_214 ;
V_63 = V_3 -> V_246 ;
V_130 += V_63 ;
if ( V_130 >= V_62 )
V_130 -= V_62 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x04 , V_24 ) ;
V_24 = ( V_63 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 4 ;
V_24 |= ( V_130 & 0x000F ) ;
F_4 ( V_3 -> V_272 , 0x01 , V_24 ) ;
V_130 = V_367 ;
V_62 = V_3 -> V_212 ;
V_63 = V_3 -> V_241 ;
V_63 &= 0x0FFF ;
if ( F_66 ( V_3 ) ) {
V_62 = V_62 >> 1 ;
V_63 = V_63 >> 1 ;
V_130 = V_130 >> 1 ;
}
if ( V_3 -> V_15 & V_17 )
V_63 += 1 ;
if ( V_3 -> V_15 & V_72 )
V_63 += 1 ;
V_130 += V_63 ;
if ( V_130 >= V_62 )
V_130 -= V_62 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x1F , V_24 ) ;
V_24 = ( ( V_63 & 0xFF00 ) >> 8 ) << 4 ;
F_4 ( V_3 -> V_272 , 0x20 , V_24 ) ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x23 , V_24 ) ;
V_24 = ( V_130 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_272 , 0x25 , V_24 ) ;
F_42 ( & V_62 , & V_63 , V_3 ) ;
V_130 = V_62 ;
V_62 = V_3 -> V_212 ;
V_63 = V_3 -> V_243 ;
if ( F_66 ( V_3 ) ) {
V_62 = V_62 >> 1 ;
V_63 = V_63 >> 1 ;
V_130 = V_130 >> 1 ;
}
if ( V_3 -> V_15 & V_17 )
V_63 += 1 ;
V_130 += V_63 ;
if ( V_130 >= V_62 )
V_130 -= V_62 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x1C , V_24 ) ;
V_24 = ( V_63 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_272 , 0x1D , ~ 0x0F0 , V_24 ) ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_272 , 0x21 , V_24 ) ;
if ( ! ( V_3 -> V_8 & V_319 ) ) {
if ( V_3 -> V_191 == 525 ) {
if ( V_3 -> V_15 & ( V_87 | V_88
| V_16 | V_17
| V_72 ) ) {
V_24 = 0xC6 ;
} else
V_24 = 0xC4 ;
F_4 ( V_3 -> V_272 , 0x2f , V_24 ) ;
F_4 ( V_3 -> V_272 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_191 == 420 ) {
if ( V_3 -> V_15 & ( V_87 | V_88
| V_16 | V_17
| V_72 ) ) {
V_24 = 0x4F ;
} else
V_24 = 0x4E ;
F_4 ( V_3 -> V_272 , 0x2f , V_24 ) ;
}
}
}
static struct V_389 const
* F_80 ( unsigned short V_130 , struct V_2 * V_3 )
{
unsigned short V_62 , V_63 , V_33 ;
struct V_389 const * V_390 ;
if ( V_130 == 0 ) {
V_62 = V_3 -> V_189 ;
V_63 = V_3 -> V_190 ;
} else {
V_62 = V_3 -> V_191 ;
V_63 = V_3 -> V_192 ;
}
if ( V_62 <= V_63 )
return & V_391 [ 0 ] ;
else
V_390 = V_392 ;
if ( V_3 -> V_10 & V_90 )
V_390 = V_393 ;
if ( V_3 -> V_9 & V_85 ) {
if ( ( V_3 -> V_10 & V_307 ) ||
( V_3 -> V_10 & V_261 ) )
V_390 = V_392 ;
if ( V_3 -> V_10 & V_259 )
V_390 = V_394 ;
}
if ( V_3 -> V_9 & V_78 )
V_390 = V_391 ;
V_33 = 0 ;
while ( V_390 [ V_33 ] . V_395 != 0xFFFF ) {
if ( V_390 [ V_33 ] . V_395 == V_62 )
break;
V_33 ++ ;
}
return & V_390 [ V_33 ] ;
}
static void F_81 ( struct V_2 * V_3 )
{
unsigned short V_33 , V_100 ;
struct V_389 const * V_390 ;
if ( ! ( V_3 -> V_15 & V_72 ) )
return;
V_390 = F_80 ( 0 , V_3 ) ;
for ( V_33 = 0x80 , V_100 = 0 ; V_33 <= 0xBF ; V_33 ++ , V_100 ++ )
F_4 ( V_3 -> V_272 , V_33 , V_390 -> V_224 [ V_100 ] ) ;
if ( ( V_3 -> V_9 & V_40 ) &&
( ! ( V_3 -> V_9 & V_78 ) ) ) {
V_390 = F_80 ( 1 , V_3 ) ;
for ( V_33 = 0xC0 , V_100 = 0 ; V_33 < 0xFF ; V_33 ++ , V_100 ++ )
F_4 ( V_3 -> V_272 ,
V_33 ,
V_390 -> V_224 [ V_100 ] ) ;
}
if ( ( V_3 -> V_9 & V_40 ) &&
( ! ( V_3 -> V_9 & V_78 ) ) )
F_12 ( V_3 -> V_272 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_12 ( V_3 -> V_272 , 0x4E , ~ 0x14 , 0x10 ) ;
}
static void F_82 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_33 ;
unsigned char const * V_396 ;
unsigned short V_34 ;
V_34 = V_35 [ V_30 ] . V_36 ;
F_4 ( V_3 -> V_397 , 0x00 , 0x00 ) ;
if ( V_3 -> V_10 & V_90 ) {
F_4 ( V_3 -> V_397 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_397 , 0x14 , 0xC8 ) ;
} else {
F_4 ( V_3 -> V_397 , 0x13 , 0xF5 ) ;
F_4 ( V_3 -> V_397 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_9 & V_40 ) )
return;
if ( V_3 -> V_10 & V_303 ) {
F_4 ( V_3 -> V_397 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_397 , 0x14 , 0xC8 ) ;
F_4 ( V_3 -> V_397 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_9 & V_78 ) || ( V_3 -> V_9
& V_85 ) ) {
if ( V_3 -> V_10 & V_307 )
return;
V_396 = V_398 ;
if ( V_3 -> V_80 & V_81 ) {
V_396 = V_399 ;
if ( ! ( V_34 & V_50 ) )
V_396 = V_400 ;
}
if ( V_3 -> V_10 & V_261 )
V_396 = V_401 ;
if ( V_3 -> V_10 & V_259 )
V_396 = V_402 ;
for ( V_33 = 0 ; V_33 <= 0x3E ; V_33 ++ )
F_4 ( V_3 -> V_397 , V_33 , V_396 [ V_33 ] ) ;
if ( V_3 -> V_15 & V_72 ) {
if ( V_3 -> V_10 & V_261 )
F_4 ( V_3 -> V_397 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_83 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_61 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_62 , V_130 , V_63 , V_34 , V_24 , V_138 ;
unsigned long V_374 , V_373 , V_403 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_24 = V_3 -> V_337 ;
F_4 ( V_3 -> V_249 , 0x13 , V_24 ) ;
V_63 = V_3 -> V_336 ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_249 , 0x14 , V_24 ) ;
V_138 = ( ( V_63 & 0xFF00 ) >> 8 ) << 7 ;
V_130 = V_3 -> V_210 - 1 ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_249 , 0x16 , V_24 ) ;
V_24 = ( ( V_130 & 0xFF00 ) >> 8 ) << 3 ;
V_138 |= V_24 ;
V_130 = V_3 -> V_211 - 1 ;
if ( ! ( V_3 -> V_9 & V_40 ) )
V_130 -= 5 ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_249 , 0x17 , V_24 ) ;
V_24 = V_138 | ( ( V_130 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_249 , 0x15 , V_24 ) ;
F_20 ( V_3 -> V_249 , 0x0D , 0x08 ) ;
V_130 = V_3 -> V_9 ;
V_63 = V_3 -> V_189 ;
if ( V_34 & V_134 )
V_63 = V_63 >> 1 ;
if ( F_66 ( V_3 ) )
V_63 = V_63 >> 1 ;
if ( V_130 & V_78 ) {
V_24 = 0 ;
if ( V_63 <= 1024 )
V_24 = 0xA0 ;
if ( V_63 == 1280 )
V_24 = 0xC0 ;
} else if ( V_130 & V_40 ) {
V_24 = 0xA0 ;
if ( V_63 <= 800 )
V_24 = 0x80 ;
} else {
V_24 = 0x80 ;
if ( V_3 -> V_9 & V_41 ) {
V_24 = 0 ;
if ( V_63 > 800 )
V_24 = 0x60 ;
}
}
if ( V_3 -> V_10 & ( V_261 | V_259 ) ) {
V_24 = 0x00 ;
if ( V_3 -> V_189 == 1280 )
V_24 = 0x40 ;
if ( V_3 -> V_189 == 1024 )
V_24 = 0x20 ;
}
F_12 ( V_3 -> V_249 , 0x0E , ~ 0xEF , V_24 ) ;
V_374 = V_3 -> V_192 ;
if ( V_130 & V_78 ) {
if ( ! ( V_24 & 0xE000 ) )
V_63 = V_63 >> 1 ;
}
V_130 = V_3 -> V_340 ;
V_24 = V_130 & 0x00FF ;
F_4 ( V_3 -> V_249 , 0x18 , V_24 ) ;
V_373 = V_3 -> V_191 ;
V_130 |= 0x04000 ;
if ( V_373 <= V_374 ) {
V_130 = ( V_130 & ( ~ 0x4000 ) ) ;
V_373 = V_3 -> V_191 ;
} else {
V_373 -= V_374 ;
}
V_403 = ( V_373 * 256 * 1024 ) % V_374 ;
V_373 = ( V_373 * 256 * 1024 ) / V_374 ;
V_374 = V_373 ;
if ( V_403 != 0 )
V_374 ++ ;
V_24 = ( unsigned short ) ( V_374 & 0x000000FF ) ;
F_4 ( V_3 -> V_249 , 0x1B , V_24 ) ;
V_24 = ( unsigned short ) ( ( V_374 & 0x0000FF00 ) >> 8 ) ;
F_4 ( V_3 -> V_249 , 0x1A , V_24 ) ;
V_63 = ( unsigned short ) ( V_374 >> 16 ) ;
V_24 = V_63 & 0x00FF ;
V_24 = V_24 << 4 ;
V_24 |= ( ( V_130 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_249 , 0x19 , V_24 ) ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
V_24 = 0x0028 ;
F_4 ( V_3 -> V_249 , 0x1C , V_24 ) ;
V_62 = V_3 -> V_189 ;
if ( V_34 & V_134 )
V_62 = V_62 >> 1 ;
if ( F_66 ( V_3 ) )
V_62 = V_62 >> 1 ;
if ( V_3 -> V_9 & V_41 ) {
if ( V_62 > 800 )
V_62 -= 800 ;
} else if ( V_3 -> V_189 > 800 ) {
if ( V_3 -> V_189 == 1024 )
V_62 = ( V_62 * 25 / 32 ) - 1 ;
else
V_62 = ( V_62 * 20 / 32 ) - 1 ;
}
V_62 -= 1 ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
V_24 = ( ( V_24 & 0x0003 ) << 4 ) ;
F_4 ( V_3 -> V_249 , 0x1E , V_24 ) ;
V_24 = ( V_62 & 0x00FF ) ;
F_4 ( V_3 -> V_249 , 0x1D , V_24 ) ;
if ( V_3 -> V_9 & ( V_40 | V_78 ) ) {
if ( V_3 -> V_189 > 800 )
F_20 ( V_3 -> V_249 , 0x1E , 0x08 ) ;
}
V_24 = 0x0036 ;
if ( V_3 -> V_9 & V_40 ) {
if ( ! ( V_3 -> V_10 & ( V_264
| V_261 | V_259
| V_310 ) ) ) {
V_24 |= 0x0001 ;
if ( ( V_3 -> V_9 & V_42 )
&& ( ! ( V_3 -> V_10
& V_81 ) ) )
V_24 &= ( ~ 0x0001 ) ;
}
}
F_12 ( V_3 -> V_249 , 0x1F , 0x00C0 , V_24 ) ;
V_63 = V_3 -> V_212 ;
if ( F_66 ( V_3 ) )
V_63 = V_63 >> 1 ;
V_63 = ( V_63 >> 1 ) - 2 ;
V_24 = ( ( V_63 & 0x0700 ) >> 8 ) << 3 ;
F_12 ( V_3 -> V_249 , 0x21 , 0x00C0 , V_24 ) ;
V_24 = V_63 & 0x00FF ;
F_4 ( V_3 -> V_249 , 0x22 , V_24 ) ;
}
F_69 ( V_29 , V_30 , V_61 , V_3 ) ;
}
static void F_84 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_28 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_85 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_404 , V_405 ;
V_404 = V_3 -> V_406 ;
V_405 = V_3 -> V_406 + 1 ;
if ( V_3 -> V_56 == V_57 ) {
if ( ! ( V_3 -> V_9 & ( V_42 | V_407
| V_288 ) ) ) {
F_84 ( V_3 ) ;
}
}
return;
}
static void F_86 ( struct V_43 * V_44 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_46 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_87 ( struct V_43 * V_44 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_46 , 0x63 , 0xBF , 0x00 ) ;
}
static unsigned char F_88 ( struct V_328 * V_329 ,
unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_170 , V_188 , V_364 , V_34 , V_129 ;
V_129 = V_35 [ V_30 ] . V_66 ;
V_170 = V_131 [ V_129 ] . V_132 ;
V_188 = V_131 [ V_129 ] . V_133 ;
V_34 = V_35 [ V_30 ] . V_36 ;
if ( ! ( V_34 & V_50 ) ) {
V_170 /= 9 ;
V_170 *= 8 ;
}
if ( ( V_29 > 0x13 ) && ( V_34 & V_134 ) )
V_170 *= 2 ;
if ( ( V_29 > 0x13 ) && ( V_34 & V_104 ) )
V_188 *= 2 ;
if ( V_170 > V_329 -> V_331 . V_408 )
return 0 ;
if ( V_188 > V_329 -> V_331 . V_409 )
return 0 ;
if ( V_170 != V_329 -> V_331 . V_408 ||
V_188 != V_329 -> V_331 . V_409 ) {
V_364 = F_70 ( V_29 , V_30 , V_3 ) ;
if ( V_364 > 2 )
return 0 ;
}
return 1 ;
}
static void F_89 ( struct V_328 * V_329 ,
int V_117 ,
unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned char V_24 , V_410 ;
unsigned short V_170 , V_188 , V_34 , V_129 ;
unsigned short V_411 , V_412 , V_413 , V_414 , V_415 ;
unsigned short V_416 , V_417 , V_418 , V_419 , V_420 ;
unsigned short V_421 ;
V_24 = ( unsigned char ) ( ( V_329 -> V_331 . V_422 &
( V_423 << 8 ) ) >> 8 ) ;
V_24 &= V_423 ;
V_410 = ( unsigned char ) F_7 ( V_3 -> V_121 ) ;
F_8 ( ( V_410 & 0x3F ) | V_24 , V_3 -> V_96 ) ;
V_24 = V_329 -> V_331 . V_422 & V_423 ;
F_12 ( V_3 -> V_28 , 0x35 , ~ 0x80 , V_24 & 0x80 ) ;
F_12 ( V_3 -> V_28 , 0x30 , ~ 0x20 , ( V_24 & 0x40 ) >> 1 ) ;
if ( V_117 == V_23 )
F_22 ( V_3 ) ;
else
F_29 ( V_3 ) ;
V_129 = V_35 [ V_30 ] . V_66 ;
V_170 = V_131 [ V_129 ] . V_132 ;
V_188 = V_131 [ V_129 ] . V_133 ;
V_34 = V_35 [ V_30 ] . V_36 ;
if ( ! ( V_34 & V_50 ) )
V_170 = V_170 * 8 / 9 ;
V_411 = V_329 -> V_331 . V_411 ;
V_412 = V_170 + ( V_329 -> V_331 . V_408 - V_170 ) / 2 ;
if ( V_412 > V_411 )
V_412 -= V_411 ;
V_413 = V_412 + V_329 -> V_331 . V_424 ;
if ( V_413 > V_411 )
V_413 -= V_411 ;
V_414 = V_413 + V_329 -> V_331 . V_425 ;
if ( V_414 > V_411 )
V_414 -= V_411 ;
V_415 = V_412 + V_411 - V_329 -> V_331 . V_408 ;
V_416 = V_329 -> V_331 . V_416 ;
V_417 = V_188 + ( V_329 -> V_331 . V_409 - V_188 ) / 2 ;
if ( V_34 & V_104 )
V_417 += V_188 / 2 ;
if ( V_417 > V_416 )
V_417 -= V_416 ;
V_418 = V_417 + V_329 -> V_331 . V_426 ;
if ( V_418 > V_416 )
V_418 -= V_416 ;
V_419 = V_418 + V_329 -> V_331 . V_427 ;
if ( V_419 > V_416 )
V_419 -= V_416 ;
V_420 = V_417 + V_416 - V_329 -> V_331 . V_409 ;
V_24 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x11 ) ;
F_4 ( V_3 -> V_46 , 0x11 , V_24 & 0x7f ) ;
if ( ! ( V_34 & V_50 ) )
F_20 ( V_3 -> V_28 , 0x1 , 0x1 ) ;
V_421 = ( V_411 >> 3 ) - 5 ;
F_12 ( V_3 -> V_28 , 0x0B , ~ 0x03 , ( V_421 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_46 , 0x0 , ( V_421 & 0xFF ) ) ;
V_421 = ( V_412 >> 3 ) - 1 ;
F_12 ( V_3 -> V_28 , 0x0B , ~ 0x30 , ( V_421 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_46 , 0x2 , ( V_421 & 0xFF ) ) ;
V_421 = ( V_415 >> 3 ) - 1 ;
F_12 ( V_3 -> V_28 , 0x0C , ~ 0x03 , ( V_421 & 0xC0 ) >> 6 ) ;
F_12 ( V_3 -> V_46 , 0x05 , ~ 0x80 , ( V_421 & 0x20 ) << 2 ) ;
F_12 ( V_3 -> V_46 , 0x03 , ~ 0x1F , V_421 & 0x1F ) ;
V_421 = ( V_413 >> 3 ) + 2 ;
F_12 ( V_3 -> V_28 , 0x0B , ~ 0xC0 , ( V_421 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_46 , 0x4 , ( V_421 & 0xFF ) ) ;
V_421 -- ;
F_12 ( V_3 -> V_28 , 0x2F , ~ 0x03 , ( V_421 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_28 , 0x2E , ( V_421 & 0xFF ) ) ;
V_421 = ( V_414 >> 3 ) + 2 ;
F_12 ( V_3 -> V_28 , 0x0C , ~ 0x04 , ( V_421 & 0x20 ) >> 3 ) ;
F_12 ( V_3 -> V_46 , 0x05 , ~ 0x1F , V_421 & 0x1F ) ;
V_421 -- ;
F_12 ( V_3 -> V_28 , 0x2F , ~ 0xFC , V_421 << 2 ) ;
V_421 = V_416 - 2 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x01 , ( V_421 & 0x400 ) >> 10 ) ;
F_12 ( V_3 -> V_46 , 0x07 , ~ 0x20 , ( V_421 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_46 , 0x07 , ~ 0x01 , ( V_421 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_46 , 0x06 , ( V_421 & 0xFF ) ) ;
V_421 = V_417 - 1 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x04 , ( V_421 & 0x400 ) >> 8 ) ;
F_12 ( V_3 -> V_46 , 0x09 , ~ 0x20 , ( V_421 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_46 , 0x07 , ~ 0x08 , ( V_421 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_46 , 0x15 , ( V_421 & 0xFF ) ) ;
V_421 = V_420 - 1 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x10 , ( V_421 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_46 , 0x16 , ( V_421 & 0xFF ) ) ;
V_421 = V_418 - 1 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x08 , ( V_421 & 0x400 ) >> 7 ) ;
F_12 ( V_3 -> V_46 , 0x07 , ~ 0x80 , ( V_421 & 0x200 ) >> 2 ) ;
F_12 ( V_3 -> V_46 , 0x07 , ~ 0x04 , ( V_421 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_46 , 0x10 , ( V_421 & 0xFF ) ) ;
if ( V_117 == V_23 ) {
F_12 ( V_3 -> V_28 , 0x35 , ~ 0x07 ,
( V_421 & 0x700 ) >> 8 ) ;
F_4 ( V_3 -> V_28 , 0x34 , V_421 & 0xFF ) ;
} else {
F_12 ( V_3 -> V_28 , 0x3F , ~ 0x03 ,
( V_421 & 0x600 ) >> 9 ) ;
F_4 ( V_3 -> V_28 , 0x34 , ( V_421 >> 1 ) & 0xFF ) ;
F_12 ( V_3 -> V_46 , 0x33 , ~ 0x01 , V_421 & 0x01 ) ;
}
V_421 = V_419 - 1 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x20 , ( V_421 & 0x10 ) << 1 ) ;
F_12 ( V_3 -> V_46 , 0x11 , ~ 0x0F , V_421 & 0x0F ) ;
if ( V_117 == V_23 )
F_12 ( V_3 -> V_28 , 0x3F , ~ 0xFC ,
( V_421 << 2 ) & 0xFC ) ;
else
F_12 ( V_3 -> V_28 , 0x3F , ~ 0xFC ,
( V_421 << 2 ) & 0x7C ) ;
for ( V_24 = 0 , V_421 = 0 ; V_24 < 3 ; V_24 ++ ) {
F_12 ( V_3 -> V_28 , 0x31 , ~ 0x30 , V_421 ) ;
F_4 ( V_3 -> V_28 ,
0x2B , V_329 -> V_331 . V_428 ) ;
F_4 ( V_3 -> V_28 ,
0x2C , V_329 -> V_331 . V_429 ) ;
V_421 += 0x10 ;
}
if ( ! ( V_34 & V_50 ) ) {
F_7 ( V_3 -> V_51 ) ;
F_8 ( 0x13 , V_3 -> V_52 ) ;
F_8 ( 0x00 , V_3 -> V_52 ) ;
F_7 ( V_3 -> V_51 ) ;
F_8 ( 0x20 , V_3 -> V_52 ) ;
F_7 ( V_3 -> V_51 ) ;
}
}
static unsigned char F_90 ( struct V_2 * V_3 )
{
unsigned short V_62 ;
V_62 = V_3 -> V_9 ;
if ( V_62 & V_287 )
return 0 ;
else if ( V_62 & ( V_288 | V_297 | V_296 ) )
return 1 ;
return 0 ;
}
static unsigned char F_91 ( struct V_2 * V_3 )
{
unsigned short V_63 , V_31 ;
V_63 = V_3 -> V_80 & ( V_430 | V_431 ) ;
V_31 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_242 , 0x2E ) ) ;
if ( V_63 & ( V_432 | V_430 ) ) {
if ( ! ( V_31 & 0x08 ) )
return 0 ;
}
if ( ! ( V_63 & ( V_433 | V_431 ) ) )
return 0 ;
if ( V_31 & 0x01 )
return 1 ;
return 0 ;
}
static unsigned char F_92 ( struct V_2 * V_3 )
{
unsigned short V_63 , V_31 ;
V_63 = V_3 -> V_80 & ( V_432 | V_433 ) ;
V_31 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_242 , 0x2E ) ) ;
if ( V_63 & ( V_432 | V_430 ) ) {
if ( ! ( V_31 & 0x08 ) )
return 0 ;
}
if ( ! ( V_63 & ( V_433 | V_431 ) ) )
return 0 ;
if ( V_31 & 0x01 )
return 1 ;
return 0 ;
}
static void F_93 ( struct V_328 * V_329 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_31 = 0 ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
V_31 = 0x3F ;
if ( ! ( V_3 -> V_9 &
( V_288 | V_296 ) ) ) {
if ( V_3 -> V_9 & V_39 ) {
if ( V_3 -> V_9 & V_287 ) {
V_31 = 0x7F ;
if ( ! ( V_3 -> V_9 &
V_39 ) )
V_31 = 0xBF ;
if ( V_3 -> V_80 & V_431 )
V_31 &= 0xBF ;
if ( V_3 -> V_80 & V_430 )
V_31 &= 0x7F ;
}
}
}
F_13 ( V_3 -> V_249 , 0x1F , V_31 ) ;
if ( V_3 -> V_15 & ( V_17 | V_72 ) ) {
if ( ( ( V_3 -> V_9 &
( V_41 | V_39 ) ) )
|| ( F_91 ( V_3 ) )
|| ( F_90 ( V_3 ) ) )
F_20 ( V_3 -> V_249 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_80 & V_430 ) || ( V_3 -> V_9
& ( V_288 | V_39
| V_296 ) ) ) {
if ( V_3 -> V_80 & V_434 )
F_86 ( V_44 , V_3 ) ;
F_61 ( V_329 , V_44 , V_3 ) ;
}
if ( V_3 -> V_9 & V_39 ) {
if ( ( V_3 -> V_80 & V_430 ) || ( V_3 -> V_9
& V_39 ) )
F_13 ( V_3 -> V_242 , 0x1e , 0xdf ) ;
}
F_13 ( V_3 -> V_28 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_9 & ( V_296 | V_287 ) ) )
F_13 ( V_3 -> V_272 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_80 & V_431 ) ||
( V_3 -> V_9 &
( V_288 | V_296 ) ) ||
( ( ! ( V_3 -> V_9 & V_39 ) ) &&
( V_3 -> V_9 &
( V_70 | V_41 | V_40 ) ) ) )
F_20 ( V_3 -> V_242 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_80 & V_431 ) ||
( V_3 -> V_9 &
( V_288 | V_296 ) ) ||
( ! ( V_3 -> V_9 & V_39 ) ) ||
( V_3 -> V_9 &
( V_70 | V_41 | V_40 ) ) ) {
V_31 = F_2 ( V_3 -> V_242 , 0x00 ) ;
F_20 ( V_3 -> V_242 , 0x00 , 0x10 ) ;
F_13 ( V_3 -> V_242 , 0x1E , 0xDF ) ;
F_4 ( V_3 -> V_242 , 0x00 , V_31 ) ;
}
} else {
if ( V_3 -> V_9 & ( V_41 | V_40 ) ) {
F_20 ( V_3 -> V_242 , 0x00 , 0x80 ) ;
F_13 ( V_3 -> V_242 , 0x1E , 0xDF ) ;
F_13 ( V_3 -> V_28 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_9 & ( V_288 | V_39
| V_296 ) )
F_61 ( V_329 , V_44 , V_3 ) ;
}
}
static unsigned short F_94 ( struct V_2 * V_3 )
{
unsigned short V_63 = 0 ;
if ( V_3 -> V_10 & V_90 )
V_63 = 2 ;
if ( V_3 -> V_10 & V_310 )
V_63 = 4 ;
if ( V_3 -> V_10 & V_307 )
V_63 = 6 ;
if ( V_3 -> V_10 & V_261 )
V_63 = 8 ;
if ( V_3 -> V_10 & V_259 )
V_63 = 10 ;
if ( V_3 -> V_10 & V_81 )
V_63 ++ ;
return V_63 ;
}
static void F_95 ( unsigned short * V_63 , unsigned char * V_267 ,
unsigned char * V_268 , struct V_2 * V_3 )
{
* V_63 = 0 ;
* V_267 = 0 ;
* V_268 = 0 ;
if ( V_3 -> V_10 & V_90 )
* V_63 = 1 ;
if ( V_3 -> V_10 & V_303 )
* V_63 = 2 ;
if ( V_3 -> V_10 & V_304 )
* V_63 = 3 ;
if ( V_3 -> V_10 & V_264 ) {
* V_63 = 4 ;
if ( V_3 -> V_10 & V_303 )
* V_63 = 5 ;
}
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
if ( ( ! ( V_3 -> V_9 & V_42 ) ) || ( V_3 -> V_10
& V_81 ) ) {
* V_63 += 8 ;
* V_267 += 1 ;
}
}
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) )
( * V_268 ) ++ ;
}
static void F_96 ( struct V_2 * V_3 )
{
unsigned char V_31 , V_226 , V_325 ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
if ( V_3 -> V_9 & ( V_41 | V_39
| V_40 | V_70 ) ) {
V_325 = 0 ;
V_226 = V_435 ;
if ( V_3 -> V_9 & V_287 )
V_226 = V_226 >> 4 ;
if ( V_3 -> V_9 &
( V_41 | V_39 ) ) {
V_325 = V_436 ;
if ( ! ( V_3 -> V_9 & V_39 ) )
V_226 = V_325 ;
}
V_226 &= 0x0F ;
V_325 &= 0xF0 ;
V_31 = F_2 ( V_3 -> V_242 , 0x2D ) ;
if ( V_3 -> V_9 & ( V_70 | V_41
| V_40 ) ) {
V_31 &= 0xF0 ;
V_31 |= V_226 ;
}
if ( V_3 -> V_9 & V_39 ) {
V_31 &= 0x0F ;
V_31 |= V_325 ;
}
F_4 ( V_3 -> V_242 , 0x2D , V_31 ) ;
}
} else if ( V_3 -> V_69 == 1 ) {
V_226 = 0 ;
V_325 = 0 ;
if ( V_3 -> V_9 & V_41 ) {
V_31 = V_436 ;
V_31 &= 0x0f ;
V_31 = V_31 << 4 ;
F_12 ( V_3 -> V_242 , 0x2D , 0x0f ,
V_31 ) ;
}
}
}
static void F_97 ( unsigned short V_130 ,
struct V_2 * V_3 )
{
unsigned short V_24 ;
V_24 = F_2 ( V_3 -> V_46 , 0x37 ) ;
if ( V_24 & V_369 ) {
F_12 ( V_3 -> V_242 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_130 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_242 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_12 ( V_3 -> V_242 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_130 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_242 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_98 ( unsigned short V_130 ,
struct V_2 * V_3 )
{
if ( V_130 & V_437 )
F_12 ( V_3 -> V_272 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_130 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_12 ( V_3 -> V_272 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_130 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
unsigned short V_33 ;
V_33 = F_2 ( V_3 -> V_28 , 0x1F ) ;
if ( ! ( V_33 & 0xC0 ) ) {
for ( V_33 = 0 ; V_33 < 0xFFFF ; V_33 ++ ) {
if ( ! ( F_7 ( V_3 -> V_51 ) & 0x08 ) )
break;
}
for ( V_33 = 0 ; V_33 < 0xFFFF ; V_33 ++ ) {
if ( ( F_7 ( V_3 -> V_51 ) & 0x08 ) )
break;
}
}
}
static void F_100 ( struct V_2 * V_3 )
{
unsigned short V_105 ;
V_105 = F_40 ( V_3 ) ;
F_13 ( V_3 -> V_249 , 0x30 , 0x8F ) ;
F_99 ( V_3 ) ;
F_20 ( V_3 -> V_249 , 0x30 , 0x20 ) ;
F_99 ( V_3 ) ;
F_4 ( V_3 -> V_249 , 0x31 ,
V_3 -> V_18 [ V_105 ] . V_438 ) ;
F_4 ( V_3 -> V_249 , 0x32 ,
V_3 -> V_18 [ V_105 ] . V_439 ) ;
F_4 ( V_3 -> V_249 , 0x33 ,
V_3 -> V_18 [ V_105 ] . V_440 ) ;
F_4 ( V_3 -> V_249 , 0x34 ,
V_3 -> V_18 [ V_105 ] . V_441 ) ;
F_99 ( V_3 ) ;
F_20 ( V_3 -> V_249 , 0x30 , 0x40 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
unsigned short V_130 ;
V_130 = V_3 -> V_18 [ F_40 ( V_3 ) ] . V_316 ;
if ( V_3 -> V_15 &
( V_87 |
V_88 |
V_16 |
V_17 |
V_72 ) ) {
if ( V_3 -> V_15 &
( V_16 | V_17 | V_72 ) ) {
F_4 ( V_3 -> V_249 , 0x24 ,
( unsigned char ) ( V_130 & 0x1F ) ) ;
}
F_12 ( V_3 -> V_249 , 0x0D ,
~ ( ( V_442 | V_443 ) >> 8 ) ,
( unsigned short ) ( ( V_130 & ( V_442
| V_443 ) ) >> 8 ) ) ;
}
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
if ( V_3 -> V_9 & V_41 )
F_98 ( V_130 , V_3 ) ;
else if ( V_3 -> V_9 & V_39 )
F_97 ( V_130 , V_3 ) ;
if ( V_3 -> V_15 & ( V_17 | V_72 ) ) {
if ( V_130 & V_444 )
F_100 ( V_3 ) ;
}
} else {
F_97 ( V_130 , V_3 ) ;
}
}
static void F_102 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_63 ;
unsigned char V_31 ;
if ( V_3 -> V_10 & ( V_261 | V_259 ) )
return;
V_63 = F_94 ( V_3 ) ;
V_63 &= 0xFE ;
V_31 = V_445 [ V_63 ] ;
V_31 = V_31 << 4 ;
F_12 ( V_3 -> V_272 , 0x0A , 0x8F , V_31 ) ;
}
static void F_103 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_63 ;
unsigned char V_31 ;
V_63 = F_94 ( V_3 ) ;
V_63 &= 0xFE ;
V_31 = V_446 [ V_63 ] ;
V_31 = V_31 << 5 ;
F_12 ( V_3 -> V_272 , 0x3A , 0x1F , V_31 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
unsigned short V_63 ;
unsigned char V_267 , V_268 ;
unsigned long V_447 ;
F_95 ( & V_63 , & V_267 , & V_268 , V_3 ) ;
V_447 = V_448 [ V_63 ] ;
F_4 ( V_3 -> V_272 , 0x31 , ( unsigned short ) ( V_447
& 0x000000FF ) ) ;
F_4 ( V_3 -> V_272 , 0x32 , ( unsigned short ) ( ( V_447
& 0x0000FF00 ) >> 8 ) ) ;
F_4 ( V_3 -> V_272 , 0x33 , ( unsigned short ) ( ( V_447
& 0x00FF0000 ) >> 16 ) ) ;
F_4 ( V_3 -> V_272 , 0x34 , ( unsigned short ) ( ( V_447
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_105 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_63 , V_105 ;
unsigned char const * V_449 ;
unsigned char V_267 , V_268 , V_203 ;
F_95 ( & V_63 , & V_267 , & V_268 , V_3 ) ;
switch ( V_63 ) {
case 0x00 :
case 0x04 :
V_449 = V_450 ;
break;
case 0x01 :
V_449 = V_451 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
case 0x03 :
V_449 = V_452 ;
break;
case 0x08 :
case 0x0C :
case 0x0A :
case 0x0B :
case 0x09 :
V_449 = V_453 ;
break;
default:
return;
}
V_203 = V_35 [ V_30 ] . V_454 ;
if ( V_267 == 0 )
V_105 = V_203 * 4 ;
else
V_105 = V_203 * 7 ;
if ( ( V_267 == 0 ) && ( V_268 == 1 ) ) {
F_4 ( V_3 -> V_272 , 0x35 , 0 ) ;
F_4 ( V_3 -> V_272 , 0x36 , 0 ) ;
F_4 ( V_3 -> V_272 , 0x37 , 0 ) ;
F_4 ( V_3 -> V_272 , 0x38 , V_449 [ V_105 ++ ] ) ;
} else {
F_4 ( V_3 -> V_272 , 0x35 , V_449 [ V_105 ++ ] ) ;
F_4 ( V_3 -> V_272 , 0x36 , V_449 [ V_105 ++ ] ) ;
F_4 ( V_3 -> V_272 , 0x37 , V_449 [ V_105 ++ ] ) ;
F_4 ( V_3 -> V_272 , 0x38 , V_449 [ V_105 ++ ] ) ;
}
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
F_4 ( V_3 -> V_272 , 0x48 , V_449 [ V_105 ++ ] ) ;
F_4 ( V_3 -> V_272 , 0x49 , V_449 [ V_105 ++ ] ) ;
F_4 ( V_3 -> V_272 , 0x4A , V_449 [ V_105 ++ ] ) ;
}
}
static void F_106 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
F_96 ( V_3 ) ;
if ( V_3 -> V_9 & ( V_41 | V_39 ) )
F_101 ( V_3 ) ;
if ( V_3 -> V_9 & V_40 ) {
F_104 ( V_3 ) ;
F_105 ( V_29 , V_30 , V_3 ) ;
F_102 ( V_29 , V_30 , V_3 ) ;
if ( V_3 -> V_15 & V_266 )
F_103 ( V_29 , V_30 , V_3 ) ;
}
}
static void F_107 ( unsigned short V_29 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_226 ;
short V_267 ;
unsigned char V_31 ;
V_31 = 0 ;
if ( ! ( V_3 -> V_9 & V_288 ) ) {
V_31 = F_2 ( V_3 -> V_242 , 0x00 ) ;
V_31 &= ~ 0x10 ;
V_31 |= 0x40 ;
if ( V_3 -> V_9 & ( V_70 | V_40
| V_41 ) ) {
V_31 = 0x40 ;
V_267 = V_3 -> V_56 ;
V_267 -= V_57 ;
if ( V_267 >= 0 ) {
V_31 = ( 0x008 >> V_267 ) ;
if ( V_31 == 0 )
V_31 = 1 ;
V_31 |= 0x040 ;
}
if ( V_3 -> V_9 & V_42 )
V_31 ^= 0x50 ;
}
}
F_4 ( V_3 -> V_242 , 0x00 , V_31 ) ;
V_31 = 0x08 ;
V_226 = 0xf0 ;
if ( V_3 -> V_9 & V_288 )
goto V_455;
V_31 = 0x00 ;
V_226 = 0xff ;
if ( ! ( V_3 -> V_9 & ( V_70 | V_40 |
V_41 | V_39 ) ) )
goto V_455;
if ( ( V_3 -> V_9 & V_39 ) &&
( ! ( V_3 -> V_9 & V_296 ) ) ) {
V_226 &= 0xf7 ;
V_31 |= 0x01 ;
goto V_455;
}
if ( V_3 -> V_9 & V_39 ) {
V_226 &= 0xf7 ;
V_31 |= 0x01 ;
}
if ( ! ( V_3 -> V_9 & ( V_70 | V_40 | V_41 ) ) )
goto V_455;
V_226 &= 0xf8 ;
V_31 = 0x01 ;
if ( ! ( V_3 -> V_9 & V_42 ) )
V_31 |= 0x02 ;
if ( ! ( V_3 -> V_9 & V_70 ) ) {
V_31 = V_31 ^ 0x05 ;
if ( ! ( V_3 -> V_9 & V_41 ) )
V_31 = V_31 ^ 0x01 ;
}
if ( ! ( V_3 -> V_9 & V_287 ) )
V_31 |= 0x08 ;
V_455:
F_12 ( V_3 -> V_242 , 0x2e , V_226 , V_31 ) ;
if ( V_3 -> V_9 & ( V_70 | V_40 | V_41
| V_39 ) ) {
V_31 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_56 == V_57 ) && ( ! ( V_3 -> V_9
& V_42 ) ) ) {
V_31 |= 0x010 ;
}
V_31 |= 0x080 ;
if ( V_3 -> V_9 & V_40 ) {
V_31 |= 0x020 ;
if ( V_3 -> V_9 & V_299 )
V_31 = V_31 ^ 0x20 ;
}
F_12 ( V_3 -> V_249 , 0x0D , ~ 0x0BF , V_31 ) ;
V_31 = 0 ;
if ( V_3 -> V_8 & V_318 )
V_31 |= 0x40 ;
if ( V_3 -> V_9 & V_40 ) {
if ( V_3 -> V_10 & V_148 )
V_31 |= 0x40 ;
}
if ( ( V_3 -> V_6 == V_75 )
|| ( V_3 -> V_6 == V_218 ) )
V_31 |= 0x80 ;
if ( V_3 -> V_6 == V_76 )
V_31 |= 0x80 ;
F_4 ( V_3 -> V_249 , 0x0C , V_31 ) ;
}
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
V_31 = 0 ;
V_226 = 0xfb ;
if ( V_3 -> V_9 & V_287 ) {
V_226 = 0xff ;
if ( V_3 -> V_9 & V_39 )
V_31 |= 0x04 ;
}
F_12 ( V_3 -> V_242 , 0x13 , V_226 , V_31 ) ;
V_31 = 0x00 ;
V_226 = 0xcf ;
if ( ! ( V_3 -> V_9 & V_288 ) ) {
if ( V_3 -> V_9 & V_287 )
V_31 |= 0x30 ;
}
F_12 ( V_3 -> V_242 , 0x2c , V_226 , V_31 ) ;
V_31 = 0 ;
V_226 = 0x3f ;
if ( ! ( V_3 -> V_9 & V_288 ) ) {
if ( V_3 -> V_9 & V_287 )
V_31 |= 0xc0 ;
}
F_12 ( V_3 -> V_249 , 0x21 , V_226 , V_31 ) ;
}
V_31 = 0 ;
V_226 = 0x7f ;
if ( ! ( V_3 -> V_9 & V_39 ) ) {
V_226 = 0xff ;
if ( ! ( V_3 -> V_9 & V_287 ) )
V_31 |= 0x80 ;
}
F_12 ( V_3 -> V_249 , 0x23 , V_226 , V_31 ) ;
if ( V_3 -> V_15 & ( V_17 | V_72 ) ) {
if ( V_3 -> V_8 & V_318 ) {
F_20 ( V_3 -> V_249 , 0x27 , 0x20 ) ;
F_20 ( V_3 -> V_249 , 0x34 , 0x10 ) ;
}
}
}
void F_108 ( struct V_43 * V_44 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_242 , 0x2f , 0xFF , 0x01 ) ;
}
void F_109 ( struct V_43 * V_44 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_242 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_110 ( struct V_2 * V_3 )
{
unsigned short V_281 ;
if ( V_3 -> V_69 == 1 ) {
return 1 ;
} else {
V_281 = F_2 ( V_3 -> V_249 , 0x00 ) ;
if ( ( V_281 == 1 ) || ( V_281 == 2 ) )
return 1 ;
else
return 0 ;
}
}
unsigned short F_111 ( struct V_43 * V_330 ,
unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
short V_456 [] = { 0x00 , 0x00 , 0x03 , 0x01 } ,
V_457 [] = { 0x00 , 0x00 , 0x03 , 0x01 , 0x01 ,
0x01 , 0x01 } ;
unsigned short V_61 , V_33 , V_34 , V_105 , V_24 ;
V_34 = V_35 [ V_30 ] . V_36 ;
V_105 = F_2 ( V_3 -> V_46 , 0x33 ) ;
V_105 = V_105 >> V_3 -> V_458 ;
V_105 &= 0x0F ;
if ( V_3 -> V_8 & V_77 )
V_105 = 0 ;
if ( V_105 > 0 )
V_105 -- ;
if ( V_3 -> V_80 & V_256 ) {
if ( V_3 -> V_9 & ( V_41 | V_39 ) ) {
if ( V_3 -> V_69 == 0 ) {
if ( V_3 -> V_15 & ( V_87 | V_88
| V_16 | V_17
| V_72 ) )
V_24 = V_457 [
V_3 -> V_6 & 0x0F ] ;
else
V_24 = V_456 [
V_3 -> V_6 & 0x0F ] ;
if ( V_105 > V_24 )
V_105 = V_24 ;
} else {
V_105 = 0 ;
}
}
}
V_61 = V_35 [ V_30 ] . V_459 ;
V_29 = V_67 [ V_61 ] . V_68 ;
if ( V_330 -> V_102 >= V_21 ) {
if ( ( V_67 [ V_61 ] . V_460 == 800 ) &&
( V_67 [ V_61 ] . V_461 == 600 ) ) {
V_105 ++ ;
}
if ( ( V_67 [ V_61 ] . V_460 == 1024 ) &&
( V_67 [ V_61 ] . V_461 == 768 ) ) {
V_105 ++ ;
}
if ( ( V_67 [ V_61 ] . V_460 == 1280 ) &&
( V_67 [ V_61 ] . V_461 == 1024 ) ) {
V_105 ++ ;
}
}
V_33 = 0 ;
do {
if ( V_67 [ V_61 + V_33 ] .
V_68 != V_29 )
break;
V_24 = V_67 [ V_61 + V_33 ] . V_94 ;
V_24 &= V_286 ;
if ( V_24 < V_3 -> V_56 )
break;
V_33 ++ ;
V_105 -- ;
} while ( V_105 != 0xFFFF );
if ( ! ( V_3 -> V_9 & V_70 ) ) {
if ( V_3 -> V_9 & V_42 ) {
V_24 = V_67 [ V_61 + V_33 - 1 ] .
V_94 ;
if ( V_24 & V_135 )
V_33 ++ ;
}
}
V_33 -- ;
if ( ( V_3 -> V_80 & V_256 ) ) {
V_24 = F_14 ( V_29 , V_30 ,
V_61 , & V_33 , V_3 ) ;
}
return V_61 + V_33 ;
}
static void F_112 ( unsigned short V_29 , unsigned short V_30 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_61 ;
V_3 -> V_80 |= V_256 ;
V_61 = F_111 ( V_44 , V_29 ,
V_30 , V_3 ) ;
F_35 ( V_29 , V_30 , V_3 ) ;
F_38 ( V_29 , V_30 , V_61 , V_3 ) ;
F_39 ( V_29 , V_30 , V_61 ,
V_44 , V_3 ) ;
F_43 ( V_29 , V_30 , V_61 , V_3 ) ;
F_47 ( V_29 , V_30 , V_61 , V_3 ) ;
}
static unsigned char F_113 ( unsigned short V_29 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_63 , V_30 , V_61 ;
V_63 = V_3 -> V_9 ;
V_3 -> V_80 |= V_256 ;
F_53 ( V_29 , & V_30 , V_3 ) ;
V_3 -> V_458 = 4 ;
V_61 = F_111 ( V_44 , V_29 ,
V_30 , V_3 ) ;
F_64 ( V_29 , V_3 ) ;
F_65 ( V_29 , V_30 , V_3 ) ;
F_68 ( V_29 , V_30 , V_61 , V_3 ) ;
F_74 ( V_29 , V_30 , V_44 ,
V_61 , V_3 ) ;
F_75 ( V_29 , V_30 , V_44 ,
V_61 , V_3 ) ;
F_77 ( V_29 , V_30 , V_44 ,
V_61 , V_3 ) ;
F_78 ( V_29 , V_30 , V_61 ,
V_44 , V_3 ) ;
F_79 ( V_29 , V_30 , V_44 ,
V_61 , V_3 ) ;
F_81 ( V_3 ) ;
F_82 ( V_29 , V_30 , V_3 ) ;
F_83 ( V_29 , V_30 , V_61 ,
V_44 , V_3 ) ;
F_69 ( V_29 , V_30 , V_61 , V_3 ) ;
F_85 ( V_29 , V_30 , V_3 ) ;
F_63 ( V_3 ) ;
return 1 ;
}
void F_114 ( struct V_2 * V_3 )
{
unsigned char V_462 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_463 = 0 , V_464 = 0 , V_465 = 0 , V_466 = 0 ;
unsigned char V_467 , V_468 , V_469 ;
unsigned short V_24 ;
unsigned char V_470 [ 3 ] = { 0x0F , 0x0F , 0x0F } ;
int V_33 ;
F_4 ( V_3 -> V_28 , 0x05 , 0x86 ) ;
F_4 ( V_3 -> V_46 , 0x57 , 0x4A ) ;
F_4 ( V_3 -> V_46 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_46 , 0x53 ) | 0x02 ) ) ;
V_469 = ( unsigned char ) F_2 ( V_3 -> V_28 , 0x31 ) ;
V_468 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x63 ) ;
V_463 = ( unsigned char ) F_2 ( V_3 -> V_28 , 0x01 ) ;
F_4 ( V_3 -> V_28 , 0x01 , ( unsigned char ) ( V_463 & 0xDF ) ) ;
F_4 ( V_3 -> V_46 , 0x63 , ( unsigned char ) ( V_468 & 0xBF ) ) ;
V_467 = ( unsigned char ) F_2 ( V_3 -> V_46 , 0x17 ) ;
F_4 ( V_3 -> V_46 , 0x17 , ( unsigned char ) ( V_467 | 0x80 ) ) ;
V_464 = ( unsigned char ) F_2 ( V_3 -> V_28 , 0x1F ) ;
F_4 ( V_3 -> V_28 , 0x1F , ( unsigned char ) ( V_464 | 0x04 ) ) ;
V_465 = ( unsigned char ) F_2 ( V_3 -> V_28 , 0x07 ) ;
F_4 ( V_3 -> V_28 , 0x07 , ( unsigned char ) ( V_465 & 0xFB ) ) ;
V_466 = ( unsigned char ) F_2 ( V_3 -> V_28 , 0x06 ) ;
F_4 ( V_3 -> V_28 , 0x06 , ( unsigned char ) ( V_466 & 0xC3 ) ) ;
F_4 ( V_3 -> V_46 , 0x11 , 0x00 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
F_4 ( V_3 -> V_46 , ( unsigned short ) V_33 , V_462 [ V_33 ] ) ;
for ( V_33 = 8 ; V_33 < 11 ; V_33 ++ )
F_4 ( V_3 -> V_46 , ( unsigned short ) ( V_33 + 8 ) ,
V_462 [ V_33 ] ) ;
for ( V_33 = 11 ; V_33 < 13 ; V_33 ++ )
F_4 ( V_3 -> V_46 , ( unsigned short ) ( V_33 + 4 ) ,
V_462 [ V_33 ] ) ;
for ( V_33 = 13 ; V_33 < 16 ; V_33 ++ )
F_4 ( V_3 -> V_28 , ( unsigned short ) ( V_33 - 3 ) ,
V_462 [ V_33 ] ) ;
F_4 ( V_3 -> V_28 , 0x0E , ( unsigned char ) ( V_462 [ 16 ]
& 0xE0 ) ) ;
F_4 ( V_3 -> V_28 , 0x31 , 0x00 ) ;
F_4 ( V_3 -> V_28 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_28 , 0x2C , 0xE1 ) ;
F_8 ( 0x00 , V_3 -> V_187 ) ;
for ( V_33 = 0 ; V_33 < 256 ; V_33 ++ ) {
F_8 ( ( unsigned char ) V_470 [ 0 ] , ( V_3 -> V_187 + 1 ) ) ;
F_8 ( ( unsigned char ) V_470 [ 1 ] , ( V_3 -> V_187 + 1 ) ) ;
F_8 ( ( unsigned char ) V_470 [ 2 ] , ( V_3 -> V_187 + 1 ) ) ;
}
F_60 ( 1 ) ;
F_62 ( V_3 ) ;
V_24 = F_7 ( V_3 -> V_96 ) ;
if ( V_24 & 0x10 )
F_12 ( V_3 -> V_46 , 0x32 , 0xDF , 0x20 ) ;
else
F_12 ( V_3 -> V_46 , 0x32 , 0xDF , 0x00 ) ;
F_8 ( 0x00 , V_3 -> V_187 ) ;
for ( V_33 = 0 ; V_33 < 256 ; V_33 ++ ) {
F_8 ( 0 , ( V_3 -> V_187 + 1 ) ) ;
F_8 ( 0 , ( V_3 -> V_187 + 1 ) ) ;
F_8 ( 0 , ( V_3 -> V_187 + 1 ) ) ;
}
F_4 ( V_3 -> V_28 , 0x01 , V_463 ) ;
F_4 ( V_3 -> V_46 , 0x63 , V_468 ) ;
F_4 ( V_3 -> V_28 , 0x31 , V_469 ) ;
F_4 ( V_3 -> V_46 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_46 , 0x53 ) & 0xFD ) ) ;
F_4 ( V_3 -> V_28 , 0x1F , ( unsigned char ) V_464 ) ;
}
static void F_115 ( struct V_328 * V_329 ,
struct V_43 * V_44 ,
struct V_2 * V_3 )
{
unsigned short V_31 ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
if ( ! ( V_3 -> V_80 & V_430 ) ) {
if ( V_3 -> V_80 & V_432 ) {
F_4 ( V_3 -> V_242 , 0x1E , 0x20 ) ;
} else if ( V_3 -> V_9 & V_287 ) {
F_4 ( V_3 -> V_242 ,
0x1E , 0x20 ) ;
}
}
if ( ! ( V_3 -> V_80 & V_431 ) ) {
if ( ( V_3 -> V_80 & V_433 ) || ( V_3 -> V_9
& ( V_41 | V_40
| V_70 ) ) ) {
V_31 = ( unsigned char ) F_2 (
V_3 -> V_28 , 0x32 ) ;
V_31 &= 0xDF ;
if ( V_3 -> V_9 & V_42 ) {
if ( ! ( V_3 -> V_9 &
V_70 ) )
V_31 |= 0x20 ;
}
F_4 ( V_3 -> V_28 , 0x32 , V_31 ) ;
F_20 ( V_3 -> V_28 , 0x1E , 0x20 ) ;
V_31 = ( unsigned char ) F_2 (
V_3 -> V_242 , 0x2E ) ;
if ( ! ( V_31 & 0x80 ) )
F_20 ( V_3 -> V_242 ,
0x2E , 0x80 ) ;
F_13 ( V_3 -> V_242 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_80 & ( V_432 | V_433 ) )
|| ( ! ( V_3 -> V_9 & V_288 ) ) ) {
F_12 ( V_3 -> V_272 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_15 & ( V_17 | V_72 ) ) {
if ( ! F_91 ( V_3 ) ) {
if ( F_92 ( V_3 ) ||
( V_3 -> V_9 &
( V_41 | V_39 ) ) )
F_13 (
V_3 -> V_249 ,
0x2A ,
0x7F ) ;
}
F_13 ( V_3 -> V_249 , 0x30 , 0x7F ) ;
}
}
V_31 = 0x00 ;
if ( ! ( V_3 -> V_9 & V_288 ) ) {
V_31 = 0xc0 ;
if ( ! ( V_3 -> V_9 & V_296 ) &&
( V_3 -> V_9 & V_39 ) &&
( V_3 -> V_9 & V_287 ) ) {
V_31 = V_31 & 0x40 ;
if ( V_3 -> V_9 & V_39 )
V_31 = V_31 ^ 0xC0 ;
if ( V_3 -> V_80 & V_431 )
V_31 &= 0xBF ;
if ( V_3 -> V_80 & V_430 )
V_31 &= 0x7F ;
if ( V_3 -> V_80 & V_433 )
V_31 |= 0x40 ;
if ( V_3 -> V_80 & V_432 )
V_31 |= 0x80 ;
}
}
F_20 ( V_3 -> V_249 , 0x1F , V_31 ) ;
if ( ! ( V_3 -> V_80 & V_430 ) ) {
if ( ! ( V_3 -> V_80 & V_434 ) ) {
F_87 ( V_44 ,
V_3 ) ;
F_59 ( V_329 , V_44 ,
V_3 ) ;
}
}
}
else {
if ( V_3 -> V_9 & ( V_40 | V_41
| V_39 ) )
F_20 ( V_3 -> V_242 , 0x1E , 0x20 ) ;
V_31 = ( unsigned char ) F_2 ( V_3 -> V_242 ,
0x2E ) ;
if ( ! ( V_31 & 0x80 ) )
F_20 ( V_3 -> V_242 , 0x2E , 0x80 ) ;
F_13 ( V_3 -> V_242 , 0x00 , 0x7F ) ;
F_59 ( V_329 , V_44 , V_3 ) ;
}
}
static void F_116 ( struct V_328 * V_329 ,
struct V_43 * V_44 ,
unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_61 , V_24 ;
F_3 ( V_29 , V_30 , V_3 ) ;
F_8 ( V_37 . V_471 , V_3 -> V_96 ) ;
F_5 ( V_44 , V_3 ) ;
F_6 ( V_29 , V_30 , V_3 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
if ( V_44 -> V_102 == V_23 ) {
if ( V_3 -> V_69 == 0 )
F_11 ( V_3 ) ;
}
V_24 = ~ V_256 ;
V_3 -> V_80 &= V_24 ;
V_3 -> V_458 = 0 ;
if ( V_3 -> V_15 & ( V_87 | V_88 | V_16
| V_17 | V_72 ) ) {
if ( V_3 -> V_9 & ( V_296 | V_39
| V_42 ) ) {
V_3 -> V_80 |= V_256 ;
}
}
V_61 = F_111 ( V_44 , V_29 ,
V_30 , V_3 ) ;
if ( V_61 != 0xFFFF ) {
F_15 ( V_61 , V_3 ) ;
F_18 ( V_29 , V_30 , V_61 ,
V_3 , V_44 ) ;
F_25 ( V_44 , V_29 , V_30 ,
V_61 , V_3 ) ;
F_26 ( V_29 , V_30 , V_61 ,
V_44 , V_3 ) ;
F_28 ( V_29 , V_30 , V_44 ,
V_61 , V_3 ) ;
}
if ( V_44 -> V_102 >= V_166 ) {
V_24 = F_2 ( V_3 -> V_46 , 0x38 ) ;
if ( V_24 & 0xA0 ) {
if ( V_44 -> V_102 == V_23 )
F_21 ( V_29 , V_30 ,
V_61 , V_3 ) ;
else
F_19 ( V_29 , V_30 ,
V_61 , V_3 ) ;
F_24 ( V_29 , V_3 ,
V_61 ) ;
F_23 ( V_44 -> V_102 ,
V_3 , V_61 , V_29 ) ;
if ( V_3 -> V_69 == 1 )
F_89 ( V_329 ,
V_44 -> V_102 ,
V_29 , V_30 , V_3 ) ;
}
}
V_3 -> V_80 &= ( ~ V_256 ) ;
F_30 ( V_29 , V_44 , V_3 ) ;
F_32 ( V_44 , V_29 , V_30 ,
V_61 , V_3 ) ;
F_34 ( V_29 , V_30 , V_3 ) ;
}
unsigned char F_117 ( struct V_328 * V_329 ,
struct V_43 * V_44 ,
unsigned short V_29 )
{
unsigned short V_30 ;
struct V_2 V_472 ;
struct V_2 * V_3 = & V_472 ;
V_3 -> V_473 = V_329 -> V_474 ;
V_3 -> V_69 = 0 ;
if ( V_44 -> V_102 >= V_21 ) {
V_3 -> V_291 = 0 ;
V_3 -> V_293 = 0 ;
V_3 -> V_298 = 0 ;
V_3 -> V_15 = 0 ;
} else {
V_3 -> V_291 = 1 ;
V_3 -> V_293 = 1 ;
V_3 -> V_298 = 1 ;
}
V_3 -> V_28 = V_3 -> V_473 + 0x14 ;
V_3 -> V_46 = V_3 -> V_473 + 0x24 ;
V_3 -> V_52 = V_3 -> V_473 + 0x10 ;
V_3 -> V_55 = V_3 -> V_473 + 0x1e ;
V_3 -> V_96 = V_3 -> V_473 + 0x12 ;
V_3 -> V_121 = V_3 -> V_473 + 0x1C ;
V_3 -> V_265 = V_3 -> V_473 + 0x1a ;
V_3 -> V_186 = V_3 -> V_473 + 0x16 ;
V_3 -> V_475 = V_3 -> V_473 + 0x17 ;
V_3 -> V_187 = V_3 -> V_473 + 0x18 ;
V_3 -> V_176 = V_3 -> V_473 + 0x19 ;
V_3 -> V_51 = V_3 -> V_473 + 0x2A ;
V_3 -> V_476 = V_3 -> V_473 + V_477 ;
V_3 -> V_242 = V_3 -> V_473 + V_478 ;
V_3 -> V_272 = V_3 -> V_473 + V_479 ;
V_3 -> V_397 = V_3 -> V_473 + V_480 ;
V_3 -> V_249 = V_3 -> V_473 + V_481 ;
V_3 -> V_406 = V_3 -> V_473 + V_481 + 2 ;
if ( V_44 -> V_102 == V_166 ) {
if ( ( F_2 ( V_3 -> V_46 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_69 = 1 ;
}
if ( V_44 -> V_102 == V_23 ) {
if ( ( F_2 ( V_3 -> V_46 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_2 ( V_3 -> V_46 , 0x30 ) & 0x20 )
V_3 -> V_69 = 1 ;
}
}
if ( V_44 -> V_102 < V_21 )
F_49 ( V_3 ) ;
F_1 ( V_44 -> V_102 , V_3 ) ;
if ( V_29 & 0x80 )
V_29 = V_29 & 0x7F ;
F_4 ( V_3 -> V_28 , 0x05 , 0x86 ) ;
if ( V_44 -> V_102 < V_21 )
F_108 ( V_44 , V_3 ) ;
F_53 ( V_29 , & V_30 , V_3 ) ;
if ( V_44 -> V_102 < V_21 ) {
F_50 ( V_29 , V_30 , V_44 , V_3 ) ;
F_51 ( V_29 , V_30 , V_3 ) ;
F_52 ( V_29 , V_30 , V_3 ) ;
F_93 ( V_329 , V_44 , V_3 ) ;
if ( V_3 -> V_9 & ( V_296 | V_39 ) ) {
F_116 ( V_329 , V_44 , V_29 ,
V_30 , V_3 ) ;
if ( V_3 -> V_9 & V_39 ) {
F_112 ( V_29 , V_30 ,
V_44 , V_3 ) ;
}
} else if ( ! ( V_3 -> V_9 & V_297 ) ) {
F_116 ( V_329 ,
V_44 , V_29 ,
V_30 , V_3 ) ;
if ( V_3 -> V_9 & V_39 ) {
F_112 ( V_29 , V_30 ,
V_44 ,
V_3 ) ;
}
}
if ( V_3 -> V_9 & ( V_296 | V_297 ) ) {
switch ( V_44 -> V_482 ) {
case V_483 :
F_113 ( V_29 , V_44 ,
V_3 ) ;
break;
case V_484 :
F_113 ( V_29 , V_44 ,
V_3 ) ;
break;
default:
break;
}
}
F_107 ( V_29 , V_44 , V_3 ) ;
F_106 ( V_29 , V_30 , V_3 ) ;
F_115 ( V_329 , V_44 , V_3 ) ;
}
else {
if ( V_3 -> V_69 == 1 )
if ( ! F_88 ( V_329 , V_29 ,
V_30 ,
V_3 ) )
return 0 ;
V_3 -> V_56 = V_35 [ V_30 ] .
V_36 & V_286 ;
V_3 -> V_80 = 0 ;
V_3 -> V_9 = V_288 ;
F_61 ( V_329 , V_44 , V_3 ) ;
F_116 ( V_329 , V_44 , V_29 ,
V_30 , V_3 ) ;
F_59 ( V_329 , V_44 , V_3 ) ;
}
F_48 ( V_44 , V_3 ) ;
if ( V_44 -> V_102 < V_21 )
F_109 ( V_44 , V_3 ) ;
return 1 ;
}
