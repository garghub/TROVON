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
F_4 ( V_3 -> V_28 , 0x00 , 0x03 ) ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_31 = V_33 . V_34 [ V_32 ] ;
F_4 ( V_3 -> V_28 , V_32 + 1 , V_31 ) ;
}
}
static void F_5 ( struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned char V_37 ;
unsigned short V_32 ;
V_37 = F_2 ( V_3 -> V_38 , 0x11 ) ;
V_37 &= 0x7f ;
F_4 ( V_3 -> V_38 , 0x11 , V_37 ) ;
for ( V_32 = 0 ; V_32 <= 0x18 ; V_32 ++ ) {
V_37 = V_33 . V_39 [ V_32 ] ;
F_4 ( V_3 -> V_38 , V_32 , V_37 ) ;
}
}
static void F_6 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned char V_40 ;
unsigned short V_32 , V_41 ;
V_41 = V_42 [ V_30 ] . V_43 ;
for ( V_32 = 0 ; V_32 <= 0x13 ; V_32 ++ ) {
V_40 = V_33 . V_44 [ V_32 ] ;
if ( ( V_41 & V_45 ) && V_32 == 0x13 ) {
if ( V_3 -> V_9 & V_46 ) {
V_40 = 0 ;
} else if ( ( V_3 -> V_9 &
( V_47 | V_48 ) ) &&
( V_3 -> V_9 & V_49 ) ) {
V_40 = 0 ;
}
}
F_7 ( V_3 -> V_50 ) ;
F_8 ( V_32 , V_3 -> V_51 ) ;
F_8 ( V_40 , V_3 -> V_51 ) ;
}
F_7 ( V_3 -> V_50 ) ;
F_8 ( 0x14 , V_3 -> V_51 ) ;
F_8 ( 0x00 , V_3 -> V_51 ) ;
F_7 ( V_3 -> V_50 ) ;
F_8 ( 0x20 , V_3 -> V_51 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
unsigned char V_52 ;
unsigned short V_32 ;
for ( V_32 = 0 ; V_32 <= 0x08 ; V_32 ++ ) {
V_52 = V_33 . V_53 [ V_32 ] ;
F_4 ( V_3 -> V_54 , V_32 , V_52 ) ;
}
if ( V_3 -> V_55 > V_56 ) {
V_52 = F_2 ( V_3 -> V_54 , 0x05 ) ;
V_52 &= 0xBF ;
F_4 ( V_3 -> V_54 , 0x05 , V_52 ) ;
}
}
static void F_10 ( struct V_2 * V_3 )
{
unsigned short V_32 ;
for ( V_32 = 0x0A ; V_32 <= 0x0E ; V_32 ++ )
F_4 ( V_3 -> V_28 , V_32 , 0x00 ) ;
}
static unsigned char F_11 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_28 , 0x31 , ~ 0x30 , 0x20 ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_57 [ 0 ] . V_58 ) ;
F_4 ( V_3 -> V_28 , 0x2C , V_57 [ 0 ] . V_59 ) ;
F_12 ( V_3 -> V_28 , 0x31 , ~ 0x30 , 0x10 ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_57 [ 1 ] . V_58 ) ;
F_4 ( V_3 -> V_28 , 0x2C , V_57 [ 1 ] . V_59 ) ;
F_13 ( V_3 -> V_28 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_14 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 , unsigned short * V_32 ,
struct V_2 * V_3 )
{
unsigned short V_61 , V_62 , V_63 , V_41 , V_64 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_63 = V_42 [ V_30 ] . V_65 ;
V_62 = V_66 [ V_60 + ( * V_32 ) ] . V_67 ;
V_61 = 0 ;
if ( V_3 -> V_68 == 0 ) {
if ( V_3 -> V_9 & V_69 ) {
V_61 |= V_70 ;
if ( V_3 -> V_15 & V_71 )
V_61 |= V_72 ;
}
if ( V_3 -> V_9 & ( V_48 | V_46 ) ) {
V_61 |= V_73 ;
if ( V_3 -> V_6 != V_74 &&
V_3 -> V_6 != V_75 &&
( V_3 -> V_8 & V_76 ) &&
V_63 >= 9 )
return 0 ;
}
if ( V_3 -> V_9 & V_77 ) {
V_61 |= V_78 ;
if ( ( V_3 -> V_9 & V_49 ) &&
( ( V_63 == 4 ) ||
( V_63 == 3 &&
( V_3 -> V_79 & V_80 ) ) ||
( V_63 > 7 ) ) )
return 0 ;
} else if ( V_3 -> V_9 & ( V_81 |
V_82 |
V_83 |
V_84 |
V_77 ) ) {
V_61 |= V_85 ;
if ( V_3 -> V_15 & ( V_86 |
V_87 |
V_16 |
V_17 |
V_71 ) )
V_61 |= V_88 ;
if ( ! ( V_3 -> V_9 & V_89 ) &&
( V_41 & V_90 ) &&
( V_3 -> V_9 & V_49 ) &&
( ! ( V_3 -> V_9 & V_91 ) ) )
return 0 ;
}
} else if ( V_3 -> V_9 & V_48 ) {
V_61 |= V_73 ;
if ( V_63 > 0x08 )
return 0 ;
if ( V_3 -> V_6 < V_92 ) {
if ( V_63 > 0x07 )
return 0 ;
if ( V_63 == 0x04 )
return 0 ;
}
}
for (; V_66 [ V_60 + ( * V_32 ) ] . V_67 ==
V_62 ; ( * V_32 ) -- ) {
V_64 = V_66 [ V_60 + ( * V_32 ) ] .
V_93 ;
if ( V_64 & V_61 )
return 1 ;
if ( ( * V_32 ) == 0 )
break;
}
for ( ( * V_32 ) = 0 ; ; ( * V_32 ) ++ ) {
V_64 = V_66 [ V_60 + ( * V_32 ) ] .
V_93 ;
if ( V_66 [ V_60 + ( * V_32 ) ] . V_67
!= V_62 ) {
return 0 ;
}
if ( V_64 & V_61 )
return 1 ;
}
return 1 ;
}
static void F_15 ( unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_94 , V_24 ;
V_94 = V_66 [ V_60 ] . V_93 >> 8 ;
V_94 &= 0xC0 ;
V_24 = 0x2F ;
V_24 |= V_94 ;
F_8 ( V_24 , V_3 -> V_95 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
unsigned char V_96 , V_97 , V_98 ;
unsigned short V_32 , V_99 ;
V_96 = F_2 ( V_3 -> V_38 , 0x11 ) ;
V_96 &= 0x7F ;
F_4 ( V_3 -> V_38 , 0x11 , V_96 ) ;
V_96 = V_3 -> V_100 . V_96 [ 0 ] ;
F_4 ( V_3 -> V_38 , 0 , V_96 ) ;
for ( V_32 = 0x01 ; V_32 <= 0x04 ; V_32 ++ ) {
V_96 = V_3 -> V_100 . V_96 [ V_32 ] ;
F_4 ( V_3 -> V_38 , ( unsigned short ) ( V_32 + 1 ) , V_96 ) ;
}
for ( V_32 = 0x05 ; V_32 <= 0x06 ; V_32 ++ ) {
V_96 = V_3 -> V_100 . V_96 [ V_32 ] ;
F_4 ( V_3 -> V_28 , ( unsigned short ) ( V_32 + 6 ) , V_96 ) ;
}
V_99 = F_2 ( V_3 -> V_28 , 0x0e ) ;
V_99 &= 0x1F ;
V_96 = V_3 -> V_100 . V_96 [ 7 ] ;
V_96 &= 0xE0 ;
V_96 |= V_99 ;
F_4 ( V_3 -> V_28 , 0x0e , V_96 ) ;
if ( V_36 -> V_101 >= V_21 ) {
V_96 = F_2 ( V_3 -> V_38 , 0x04 ) ;
V_96 = V_96 - 1 ;
F_4 ( V_3 -> V_38 , 0x04 , V_96 ) ;
V_96 = F_2 ( V_3 -> V_38 , 0x05 ) ;
V_97 = V_96 ;
V_97 &= 0xE0 ;
V_96 &= 0x1F ;
if ( V_96 == 0 ) {
V_98 = V_96 ;
V_96 = F_2 ( V_3 -> V_28 , 0x0c ) ;
V_96 &= 0xFB ;
F_4 ( V_3 -> V_28 , 0x0c , V_96 ) ;
V_96 = V_98 ;
}
V_96 = V_96 - 1 ;
V_96 |= V_97 ;
F_4 ( V_3 -> V_38 , 0x05 , V_96 ) ;
V_96 = F_2 ( V_3 -> V_28 , 0x0e ) ;
V_96 = V_96 >> 5 ;
V_96 = V_96 + 3 ;
if ( V_96 > 7 )
V_96 = V_96 - 7 ;
V_96 = V_96 << 5 ;
F_12 ( V_3 -> V_28 , 0x0e , ~ 0xE0 , V_96 ) ;
}
}
static void F_17 ( unsigned short V_30 ,
unsigned short V_29 ,
struct V_2 * V_3 )
{
unsigned char V_96 ;
unsigned short V_32 , V_99 ;
for ( V_32 = 0x00 ; V_32 <= 0x01 ; V_32 ++ ) {
V_96 = V_3 -> V_102 . V_96 [ V_32 ] ;
F_4 ( V_3 -> V_38 , ( unsigned short ) ( V_32 + 6 ) , V_96 ) ;
}
for ( V_32 = 0x02 ; V_32 <= 0x03 ; V_32 ++ ) {
V_96 = V_3 -> V_102 . V_96 [ V_32 ] ;
F_4 ( V_3 -> V_38 , ( unsigned short ) ( V_32 + 0x0e ) , V_96 ) ;
}
for ( V_32 = 0x04 ; V_32 <= 0x05 ; V_32 ++ ) {
V_96 = V_3 -> V_102 . V_96 [ V_32 ] ;
F_4 ( V_3 -> V_38 , ( unsigned short ) ( V_32 + 0x11 ) , V_96 ) ;
}
V_99 = F_2 ( V_3 -> V_28 , 0x0a ) ;
V_99 &= 0xC0 ;
V_96 = V_3 -> V_102 . V_96 [ 6 ] ;
V_96 &= 0x3F ;
V_96 |= V_99 ;
F_4 ( V_3 -> V_28 , 0x0a , V_96 ) ;
V_96 = V_3 -> V_102 . V_96 [ 6 ] ;
V_96 &= 0x80 ;
V_96 = V_96 >> 2 ;
V_32 = V_42 [ V_30 ] . V_43 ;
V_32 &= V_103 ;
if ( V_32 )
V_96 |= 0x80 ;
V_99 = F_2 ( V_3 -> V_38 , 0x09 ) ;
V_99 &= 0x5F ;
V_96 |= V_99 ;
F_4 ( V_3 -> V_38 , 0x09 , V_96 ) ;
}
static void F_18 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 ,
struct V_35 * V_36 )
{
unsigned char V_104 , V_96 ;
unsigned short V_32 ;
V_104 = V_66 [ V_60 ] . V_105 ;
V_104 = V_104 & V_106 ;
V_96 = F_2 ( V_3 -> V_38 , 0x11 ) ;
V_96 &= 0x7F ;
F_4 ( V_3 -> V_38 , 0x11 , V_96 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_3 -> V_100 . V_96 [ V_32 ]
= V_107 [ V_104 ] . V_108 [ V_32 ] ;
for ( V_32 = 0 ; V_32 < 7 ; V_32 ++ )
V_3 -> V_102 . V_96 [ V_32 ]
= V_107 [ V_104 ] . V_108 [ V_32 + 8 ] ;
F_16 ( V_3 , V_36 ) ;
F_17 ( V_30 , V_29 , V_3 ) ;
if ( V_3 -> V_55 > 0x03 )
F_4 ( V_3 -> V_38 , 0x14 , 0x4F ) ;
}
static void F_19 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned char V_104 , V_109 , V_110 , V_111 , V_112 ;
unsigned short V_113 , V_114 , V_115 ;
V_104 = V_66 [ V_60 ] . V_105 ;
V_109 = V_107 [ V_104 ] . V_108 [ 3 ] ;
V_111 = V_109 ;
F_4 ( V_3 -> V_28 , 0x2E , V_109 ) ;
V_112 = V_107 [ V_104 ] . V_108 [ 5 ] ;
V_112 &= 0xC0 ;
V_113 = V_112 ;
V_113 <<= 2 ;
V_113 |= V_109 ;
V_109 = V_107 [ V_104 ] . V_108 [ 4 ] ;
V_109 &= 0x1F ;
V_110 = V_107 [ V_104 ] . V_108 [ 6 ] ;
V_110 &= 0x04 ;
V_110 <<= 3 ;
V_109 |= V_110 ;
V_114 = V_113 & 0x3C0 ;
V_114 |= V_109 ;
V_111 &= 0x3F ;
if ( V_109 < V_111 )
V_114 |= 0x40 ;
V_114 &= 0xFF ;
V_109 = ( unsigned char ) V_114 ;
V_109 <<= 2 ;
V_112 >>= 6 ;
V_109 |= V_112 ;
F_4 ( V_3 -> V_28 , 0x2F , V_109 ) ;
F_12 ( V_3 -> V_28 , 0x30 , 0xE3 , 00 ) ;
V_109 = V_107 [ V_104 ] . V_108 [ 10 ] ;
V_110 = V_109 ;
V_109 &= 0x01 ;
F_20 ( V_3 -> V_28 , 0x33 , V_109 ) ;
V_109 = V_107 [ V_104 ] . V_108 [ 9 ] ;
V_111 = V_110 >> 1 ;
V_112 = V_109 & 0x04 ;
V_112 <<= 5 ;
V_111 |= V_112 ;
F_4 ( V_3 -> V_28 , 0x34 , V_111 ) ;
V_113 = V_112 ;
V_113 <<= 1 ;
V_113 |= V_110 ;
V_109 &= 0x80 ;
V_114 = V_109 << 2 ;
V_113 |= V_114 ;
V_109 = V_107 [ V_104 ] . V_108 [ 14 ] ;
V_109 &= 0x08 ;
V_114 = V_109 ;
V_114 <<= 7 ;
V_113 |= V_114 ;
V_109 = V_107 [ V_104 ] . V_108 [ 11 ] ;
V_109 &= 0x0F ;
V_110 = V_107 [ V_104 ] . V_108 [ 14 ] ;
V_110 &= 0x20 ;
V_110 >>= 1 ;
V_109 |= V_110 ;
V_114 = V_113 & 0x7E0 ;
V_114 |= V_109 ;
V_115 = V_113 & 0x1F ;
if ( V_109 < V_115 )
V_114 |= 0x20 ;
V_114 &= 0xFF ;
V_109 = ( unsigned char ) V_114 ;
V_109 <<= 2 ;
V_113 &= 0x600 ;
V_113 >>= 9 ;
V_110 = ( unsigned char ) V_113 ;
V_109 |= V_110 ;
V_109 &= 0x7F ;
F_4 ( V_3 -> V_28 , 0x3F , V_109 ) ;
}
static void F_21 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_104 , V_109 , V_110 , V_111 ;
V_104 = V_66 [ V_60 ] . V_105 ;
V_109 = V_107 [ V_104 ] . V_108 [ 3 ] ;
V_110 = V_109 ;
F_4 ( V_3 -> V_28 , 0x2E , V_109 ) ;
V_109 = V_107 [ V_104 ] . V_108 [ 5 ] ;
V_109 &= 0xC0 ;
V_110 |= ( V_109 << 2 ) ;
V_109 = V_107 [ V_104 ] . V_108 [ 4 ] ;
V_109 &= 0x1F ;
V_111 = V_109 ;
V_109 = V_107 [ V_104 ] . V_108 [ 6 ] ;
V_109 &= 0x04 ;
V_109 <<= 3 ;
V_111 |= V_109 ;
V_110 = V_110 & 0x3C0 ;
V_110 |= V_111 ;
V_109 = V_107 [ V_104 ] . V_108 [ 3 ] ;
V_109 &= 0x3F ;
if ( V_111 <= V_109 )
V_110 += 0x40 ;
V_109 = V_107 [ V_104 ] . V_108 [ 5 ] ;
V_109 &= 0xC0 ;
V_109 >>= 6 ;
V_109 |= ( ( V_110 << 2 ) & 0xFF ) ;
F_4 ( V_3 -> V_28 , 0x2F , V_109 ) ;
F_12 ( V_3 -> V_28 , 0x30 , 0xE3 , 00 ) ;
V_109 = V_107 [ V_104 ] . V_108 [ 10 ] ;
F_4 ( V_3 -> V_28 , 0x34 , V_109 ) ;
V_111 = V_109 ;
V_109 = V_107 [ V_104 ] . V_108 [ 9 ] ;
V_110 = V_109 ;
V_109 = V_109 & 0x04 ;
V_109 >>= 2 ;
F_12 ( V_3 -> V_28 , 0x35 , ~ 0x01 , V_109 ) ;
V_111 |= ( V_109 << 8 ) ;
V_111 |= ( ( V_110 & 0x80 ) << 2 ) ;
V_109 = V_107 [ V_104 ] . V_108 [ 14 ] ;
V_109 &= 0x08 ;
V_111 |= ( V_109 << 7 ) ;
V_109 = V_107 [ V_104 ] . V_108 [ 11 ] ;
V_109 &= 0x0F ;
V_110 = V_107 [ V_104 ] . V_108 [ 14 ] ;
V_110 &= 0x20 ;
V_110 >>= 1 ;
V_109 |= V_110 ;
V_110 = V_111 ;
V_110 &= 0x7E0 ;
V_110 |= V_109 ;
if ( V_110 <= V_111 )
V_110 |= 0x20 ;
V_109 = ( V_110 << 2 ) & 0xFF ;
F_12 ( V_3 -> V_28 , 0x3F , ~ 0xFC , V_109 ) ;
V_109 = V_111 >> 8 ;
F_12 ( V_3 -> V_28 , 0x35 , ~ 0x07 , V_109 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned char V_24 ;
V_24 = F_2 ( V_3 -> V_38 , 0x37 ) ;
V_24 = ( V_24 & 3 ) << 6 ;
F_12 ( V_3 -> V_28 , 0x06 , ~ 0xc0 , V_24 & 0x80 ) ;
F_12 ( V_3 -> V_28 , 0x09 , ~ 0xc0 , V_24 | 0x80 ) ;
}
static void F_23 ( int V_116 ,
struct V_2 * V_3 ,
unsigned short V_60 ,
unsigned short V_29 )
{
unsigned short V_24 ;
F_4 ( V_3 -> V_38 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_38 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_38 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_38 , 0x47 , 0x00 ) ;
if ( V_116 == V_23 ) {
V_24 = F_2 ( V_3 -> V_38 , 0x37 ) ;
if ( ( V_24 & 0x03 ) == 0 ) {
F_4 ( V_3 -> V_38 , 0x46 , 0x13 ) ;
F_4 ( V_3 -> V_38 , 0x47 , 0x13 ) ;
}
}
if ( V_116 == V_23 ) {
F_22 ( V_3 ) ;
} else {
V_24 = F_2 ( V_3 -> V_38 , 0x37 ) ;
if ( V_24 & 0x01 ) {
F_20 ( V_3 -> V_28 , 0x06 , 0x40 ) ;
F_20 ( V_3 -> V_28 , 0x09 , 0x40 ) ;
}
}
F_20 ( V_3 -> V_28 , 0x1E , 0x01 ) ;
F_13 ( V_3 -> V_28 , 0x30 , ~ 0x20 ) ;
F_13 ( V_3 -> V_28 , 0x35 , ~ 0x80 ) ;
V_24 = V_66 [ V_60 ] . V_93 ;
if ( V_24 & 0x4000 )
F_20 ( V_3 -> V_28 , 0x30 , 0x20 ) ;
if ( V_24 & 0x8000 )
F_20 ( V_3 -> V_28 , 0x35 , 0x80 ) ;
}
static void F_24 ( unsigned short V_29 ,
struct V_2 * V_3 ,
unsigned short V_60 )
{
int V_104 = - 1 ;
F_13 ( V_3 -> V_38 , 0x11 , 0x7F ) ;
if ( V_29 == 0x2E &&
( V_66 [ V_60 ] . V_105 ==
V_117 ) )
V_104 = 12 ;
else if ( V_29 == 0x2E && ( V_66 [ V_60 ] .
V_105 == V_118 ) )
V_104 = 13 ;
else if ( V_29 == 0x2F )
V_104 = 14 ;
else if ( V_29 == 0x50 )
V_104 = 15 ;
else if ( V_29 == 0x59 )
V_104 = 16 ;
if ( V_104 != - 1 ) {
F_4 ( V_3 -> V_38 , 0x02 ,
V_119 [ V_104 ] . V_120 ) ;
F_4 ( V_3 -> V_38 , 0x03 ,
V_119 [ V_104 ] . V_121 ) ;
F_4 ( V_3 -> V_38 , 0x15 ,
V_119 [ V_104 ] . V_122 ) ;
F_4 ( V_3 -> V_38 , 0x16 ,
V_119 [ V_104 ] . V_123 ) ;
}
}
static void F_25 ( struct V_35 * V_36 ,
unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_124 , V_61 , V_62 , V_125 , V_24 , V_41 ;
unsigned char V_96 ;
V_124 = V_42 [ V_30 ] . V_65 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_61 = V_126 [ V_124 ] . V_127 ;
V_62 = V_126 [ V_124 ] . V_128 ;
if ( V_41 & V_129 )
V_61 = V_61 >> 1 ;
if ( V_41 & V_129 )
V_61 = V_61 << 1 ;
V_24 = V_66 [ V_60 ] . V_93 ;
if ( V_24 & V_130 )
V_62 = V_62 >> 1 ;
if ( V_41 & V_103 )
V_62 = V_62 << 1 ;
V_125 = 8 ;
V_61 /= V_125 ;
V_61 -= 1 ;
V_62 -= 1 ;
V_125 = V_61 ;
V_24 = F_2 ( V_3 -> V_38 , 0x11 ) ;
V_96 = F_2 ( V_3 -> V_38 , 0x11 ) ;
V_96 &= 0x7F ;
F_4 ( V_3 -> V_38 , 0x11 , V_96 ) ;
F_4 ( V_3 -> V_38 , 0x01 , ( unsigned short ) ( V_125 & 0xff ) ) ;
F_12 ( V_3 -> V_38 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_125 & 0x0ff00 ) >> 10 ) ) ;
F_4 ( V_3 -> V_38 , 0x12 , ( unsigned short ) ( V_62 & 0xff ) ) ;
V_61 = 0 ;
V_62 = V_62 >> 8 ;
if ( V_62 & 0x01 )
V_61 |= 0x02 ;
if ( V_62 & 0x02 )
V_61 |= 0x40 ;
F_12 ( V_3 -> V_38 , 0x07 , ~ 0x42 , V_61 ) ;
V_96 = F_2 ( V_3 -> V_38 , 0x07 ) ;
V_96 &= 0xFF ;
V_61 = 0 ;
if ( V_62 & 0x04 )
V_61 |= 0x02 ;
F_12 ( V_3 -> V_38 , 0x0a , ~ 0x02 , V_61 ) ;
F_4 ( V_3 -> V_38 , 0x11 , V_24 ) ;
}
static void F_26 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_24 , V_131 , V_132 , V_133 , V_32 , V_134 ;
V_24 = V_42 [ V_30 ] . V_135 ;
V_24 = V_24 >> 8 ;
V_24 = V_136 [ V_24 ] ;
V_133 = V_66 [ V_60 ] . V_93 ;
V_133 &= V_130 ;
if ( V_133 )
V_24 = V_24 << 1 ;
V_133 = V_3 -> V_55 - V_137 ;
switch ( V_133 ) {
case 0 :
V_133 = 1 ;
break;
case 1 :
V_133 = 2 ;
break;
case 2 :
V_133 = 4 ;
break;
case 3 :
V_133 = 4 ;
break;
case 4 :
V_133 = 6 ;
break;
case 5 :
V_133 = 8 ;
break;
default:
break;
}
if ( ( V_29 >= 0x26 ) && ( V_29 <= 0x28 ) )
V_24 = V_24 * V_133 + V_133 / 2 ;
else
V_24 *= V_133 ;
V_134 = V_24 ;
V_133 = V_24 ;
V_24 = V_24 >> 8 ;
V_24 &= 0x0F ;
V_32 = F_2 ( V_3 -> V_28 , 0x0E ) ;
V_32 &= 0xF0 ;
V_32 |= V_24 ;
F_4 ( V_3 -> V_28 , 0x0E , V_32 ) ;
V_24 = ( unsigned char ) V_133 ;
V_24 &= 0xFF ;
F_4 ( V_3 -> V_38 , 0x13 , V_24 ) ;
V_133 = V_66 [ V_60 ] . V_93 ;
V_133 &= V_130 ;
if ( V_133 )
V_134 >>= 1 ;
V_134 = V_134 << 5 ;
V_131 = ( V_134 & 0xff00 ) >> 8 ;
V_132 = V_134 & 0x00ff ;
if ( V_132 == 0 )
V_131 += 1 ;
else
V_131 += 2 ;
if ( V_36 -> V_101 >= V_21 )
if ( ( V_29 == 0x4A ) | ( V_29 == 0x49 ) )
V_131 -= 1 ;
F_4 ( V_3 -> V_28 , 0x10 , V_131 ) ;
}
static unsigned short F_27 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_138 , V_41 ;
V_41 = V_42 [ V_30 ] . V_43 ;
if ( V_3 -> V_9 & ( V_48 | V_46 ) ) {
if ( V_3 -> V_6 != V_92 )
V_138 = V_139 + 5 ;
else
V_138 = V_140 + 2 ;
} else if ( V_3 -> V_9 & V_77 ) {
if ( V_3 -> V_79 & V_141 )
V_138 = V_142 + V_143 ;
else
V_138 = V_142 + V_144 ;
if ( V_3 -> V_79 & V_80 ) {
if ( V_41 & V_45 ) {
V_138 = V_142 + V_145 ;
} else {
V_138 = V_142 + V_146 ;
}
}
if ( V_3 -> V_15 & V_16 ) {
if ( V_3 -> V_79 & V_141 )
V_138 = V_147 ;
else
V_138 = V_148 ;
}
} else if ( V_3 -> V_9 & V_47 ) {
if ( V_3 -> V_79 & V_141 )
V_138 = V_142 + V_149 ;
else
V_138 = V_142 + V_150 ;
} else {
V_138 = V_66 [ V_60 ] . V_151 ;
V_138 &= V_106 ;
}
return V_138 ;
}
static void F_28 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_35 * V_36 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned char V_104 , V_96 ;
unsigned short V_152 ;
if ( V_3 -> V_68 == 1 ) {
V_104 = V_66 [ V_60 ] . V_151 ;
V_96 = F_2 ( V_3 -> V_28 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_28 , 0x31 , V_96 ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_57 [ V_104 ] . V_58 ) ;
F_4 ( V_3 -> V_28 , 0x2C , V_57 [ V_104 ] . V_59 ) ;
F_4 ( V_3 -> V_28 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) && ( V_3 -> V_9
& V_46 ) ) {
V_152 = F_27 ( V_29 , V_30 ,
V_60 , V_36 ,
V_3 ) ;
V_96 = F_2 ( V_3 -> V_28 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_28 , 0x31 , V_96 ) ;
V_96 = V_153 [ V_152 ] . V_154 ;
F_4 ( V_3 -> V_28 , 0x2B , V_96 ) ;
V_96 = V_153 [ V_152 ] . V_155 ;
F_4 ( V_3 -> V_28 , 0x2C , V_96 ) ;
F_4 ( V_3 -> V_28 , 0x2D , 0x01 ) ;
} else {
V_104 = V_66 [ V_60 ] . V_151 ;
V_96 = F_2 ( V_3 -> V_28 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_28 , 0x31 , V_96 ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_57 [ V_104 ] . V_58 ) ;
F_4 ( V_3 -> V_28 , 0x2C , V_57 [ V_104 ] . V_59 ) ;
F_4 ( V_3 -> V_28 , 0x2D , 0x01 ) ;
}
if ( V_36 -> V_101 >= V_21 ) {
if ( V_42 [ V_30 ] . V_43 &
V_129 ) {
V_96 = F_2 ( V_3 -> V_28 , 0x2B ) ;
F_4 ( V_3 -> V_28 , 0x2B , V_96 ) ;
V_96 = F_2 ( V_3 -> V_28 , 0x2C ) ;
V_104 = V_96 ;
V_104 &= 0xE0 ;
V_96 &= 0x1F ;
V_96 = V_96 << 1 ;
V_96 += 1 ;
V_96 |= V_104 ;
F_4 ( V_3 -> V_28 , 0x2C , V_96 ) ;
}
}
}
static void F_29 ( struct V_2 * V_3 )
{
unsigned char V_24 ;
V_24 = F_2 ( V_3 -> V_38 , 0x37 ) ;
V_24 = ( V_24 & 1 ) << 6 ;
F_12 ( V_3 -> V_28 , 0x06 , ~ 0x40 , V_24 ) ;
F_12 ( V_3 -> V_28 , 0x09 , ~ 0xc0 , V_24 | 0x80 ) ;
}
static void F_30 ( unsigned short V_29 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_96 ;
V_96 = F_2 ( V_3 -> V_28 , 0x3D ) ;
V_96 &= 0xfe ;
F_4 ( V_3 -> V_28 , 0x3D , V_96 ) ;
F_4 ( V_3 -> V_28 , 0x08 , 0x34 ) ;
V_96 = F_2 ( V_3 -> V_28 , 0x09 ) ;
V_96 &= 0xC0 ;
F_4 ( V_3 -> V_28 , 0x09 , V_96 | 0x30 ) ;
V_96 = F_2 ( V_3 -> V_28 , 0x3D ) ;
V_96 |= 0x01 ;
F_4 ( V_3 -> V_28 , 0x3D , V_96 ) ;
if ( V_36 -> V_101 == V_156 )
F_29 ( V_3 ) ;
}
static void F_31 ( struct V_35 * V_36 ,
unsigned short V_29 , unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_96 , V_157 = 0 ;
short V_158 ;
unsigned char V_104 ;
V_104 = V_66 [ V_60 ] . V_151 ;
V_104 &= V_106 ;
V_158 = V_57 [ V_104 ] . CLOCK ;
V_96 = F_2 ( V_3 -> V_28 , 0x32 ) ;
V_96 &= 0xf3 ;
if ( V_158 >= 200 )
V_96 |= 0x0c ;
if ( V_36 -> V_101 >= V_21 )
V_96 &= ~ 0x04 ;
F_4 ( V_3 -> V_28 , 0x32 , V_96 ) ;
if ( V_36 -> V_101 < V_21 ) {
V_96 = F_2 ( V_3 -> V_28 , 0x1F ) ;
V_96 &= 0xE7 ;
if ( V_158 < 200 )
V_96 |= 0x10 ;
F_4 ( V_3 -> V_28 , 0x1F , V_96 ) ;
}
V_157 = 0x00 ;
F_12 ( V_3 -> V_28 , 0x07 , 0xFC , V_157 ) ;
if ( V_36 -> V_101 >= V_23 )
F_12 ( V_3 -> V_28 , 0x40 , 0xFC , V_157 & 0x03 ) ;
}
static void F_32 ( struct V_35 * V_36 ,
unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_96 , V_157 , V_159 , V_64 = 0 , V_41 , V_124 ,
V_160 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_64 = V_66 [ V_60 ] . V_93 ;
if ( F_2 ( V_3 -> V_38 , 0x31 ) & 0x01 )
F_12 ( V_3 -> V_28 , 0x1F , 0x3F , 0x00 ) ;
V_96 = V_64 ;
V_157 = 0 ;
V_157 |= 0x02 ;
V_159 = V_3 -> V_55 - V_56 ;
V_159 = V_159 << 2 ;
V_157 |= V_159 ;
V_96 &= V_130 ;
if ( V_96 )
V_157 |= 0x20 ;
F_12 ( V_3 -> V_28 , 0x06 , ~ 0x3F , V_157 ) ;
V_124 = V_42 [ V_30 ] . V_65 ;
V_160 = V_126 [ V_124 ] . V_127 ;
V_96 = 0x0000 ;
if ( V_64 & V_130 ) {
if ( V_160 == 1024 )
V_96 = 0x0035 ;
else if ( V_160 == 1280 )
V_96 = 0x0048 ;
}
F_12 ( V_3 -> V_38 , 0x19 , 0xFF , V_96 ) ;
F_12 ( V_3 -> V_38 , 0x19 , 0xFC , 0 ) ;
if ( V_41 & V_129 )
F_12 ( V_3 -> V_28 , 0x01 , 0xF7 , 0x08 ) ;
V_157 = 0 ;
if ( V_41 & V_161 )
V_157 |= 0x08 ;
F_12 ( V_3 -> V_28 , 0x0F , ~ 0x48 , V_157 ) ;
V_96 = 0x60 ;
V_96 = V_96 ^ 0x60 ;
V_96 = V_96 ^ 0xA0 ;
F_12 ( V_3 -> V_28 , 0x21 , 0x1F , V_96 ) ;
F_31 ( V_36 , V_29 , V_60 ,
V_3 ) ;
V_96 = F_2 ( V_3 -> V_38 , 0x31 ) ;
if ( V_36 -> V_101 == V_23 ) {
if ( V_96 & 0x40 )
V_96 = 0x2c ;
else
V_96 = 0x6c ;
F_4 ( V_3 -> V_38 , 0x52 , V_96 ) ;
F_20 ( V_3 -> V_38 , 0x51 , 0x10 ) ;
} else if ( V_36 -> V_101 >= V_21 ) {
if ( V_96 & 0x40 )
V_96 = 0x33 ;
else
V_96 = 0x73 ;
F_4 ( V_3 -> V_38 , 0x52 , V_96 ) ;
F_4 ( V_3 -> V_38 , 0x51 , 0x02 ) ;
} else {
if ( V_96 & 0x40 )
V_96 = 0x2c ;
else
V_96 = 0x6c ;
F_4 ( V_3 -> V_38 , 0x52 , V_96 ) ;
}
}
static void F_33 ( unsigned short V_162 ,
unsigned short V_131 ,
unsigned short V_132 ,
unsigned short V_163 ,
struct V_2 * V_3 )
{
unsigned short V_24 , V_164 , V_165 ;
V_164 = V_131 ;
V_165 = V_132 ;
if ( V_162 != 0 ) {
V_24 = V_164 ;
V_164 = V_163 ;
V_163 = V_24 ;
if ( V_162 == 1 ) {
V_24 = V_165 ;
V_165 = V_163 ;
V_163 = V_24 ;
} else {
V_24 = V_165 ;
V_165 = V_164 ;
V_164 = V_24 ;
}
}
F_8 ( ( unsigned short ) V_163 , V_3 -> V_166 ) ;
F_8 ( ( unsigned short ) V_164 , V_3 -> V_166 ) ;
F_8 ( ( unsigned short ) V_165 , V_3 -> V_166 ) ;
}
static void F_34 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_96 , V_157 , V_32 , V_167 , V_168 , V_169 , V_170 , V_171 , V_172 , V_173 , V_162 , V_132 , V_131 , V_163 ;
const unsigned short * V_174 = V_175 ;
F_8 ( 0xFF , V_3 -> V_176 ) ;
F_8 ( 0x00 , V_3 -> V_177 ) ;
for ( V_32 = 0 ; V_32 < 16 ; V_32 ++ ) {
V_96 = V_174 [ V_32 ] ;
for ( V_167 = 0 ; V_167 < 3 ; V_167 ++ ) {
V_157 = 0 ;
if ( V_96 & 0x01 )
V_157 = 0x2A ;
if ( V_96 & 0x02 )
V_157 += 0x15 ;
F_8 ( V_157 , V_3 -> V_166 ) ;
V_96 = V_96 >> 2 ;
}
}
for ( V_32 = 16 ; V_32 < 32 ; V_32 ++ ) {
V_96 = V_174 [ V_32 ] ;
for ( V_167 = 0 ; V_167 < 3 ; V_167 ++ )
F_8 ( V_96 , V_3 -> V_166 ) ;
}
V_171 = 32 ;
for ( V_168 = 0 ; V_168 < 9 ; V_168 ++ ) {
V_172 = V_171 ;
V_173 = V_171 + 0x04 ;
V_162 = 0 ;
for ( V_169 = 0 ; V_169 < 3 ; V_169 ++ ) {
for ( V_170 = 0 ; V_170 < 5 ; V_170 ++ ) {
V_163 = V_174 [ V_171 ] ;
V_131 = V_174 [ V_172 ] ;
V_132 = V_174 [ V_173 ] ;
V_171 ++ ;
F_33 ( V_162 , V_131 , V_132 , V_163 , V_3 ) ;
}
V_171 -= 2 ;
for ( V_170 = 0 ; V_170 < 3 ; V_170 ++ ) {
V_163 = V_174 [ V_173 ] ;
V_131 = V_174 [ V_172 ] ;
V_132 = V_174 [ V_171 ] ;
V_171 -- ;
F_33 ( V_162 , V_131 , V_132 , V_163 , V_3 ) ;
}
V_162 ++ ;
}
V_171 += 5 ;
}
}
static void F_35 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_124 , V_160 , V_178 , V_41 ;
V_41 = V_42 [ V_30 ] . V_65 ;
V_124 = V_42 [ V_30 ] . V_65 ;
V_160 = V_126 [ V_124 ] . V_127 ;
V_178 = V_126 [ V_124 ] . V_128 ;
if ( V_41 & V_129 )
V_160 = V_160 << 1 ;
if ( V_41 & V_103 )
V_178 = V_178 << 1 ;
if ( V_160 == 720 )
V_160 = 640 ;
V_3 -> V_179 = V_160 ;
V_3 -> V_180 = V_160 ;
V_3 -> V_181 = V_178 ;
V_3 -> V_182 = V_178 ;
}
static void const * F_36 ( struct V_183 const * V_174 ,
unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_32 , V_184 , V_62 , V_41 ;
V_62 = 0 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_32 = 0 ;
while ( V_174 [ V_32 ] . V_185 != 0xff ) {
V_184 = V_3 -> V_6 ;
if ( V_62 & 0x0080 ) {
V_62 &= ( ~ 0x0080 ) ;
V_184 = V_3 -> V_7 ;
}
if ( V_3 -> V_8 & V_186 )
V_184 &= ( ~ V_187 ) ;
if ( V_174 [ V_32 ] . V_185 == V_184 ) {
V_62 = V_174 [ V_32 ] . V_188 ;
V_184 = V_3 -> V_8 ;
if ( V_41 & V_129 )
V_184 |= V_189 ;
V_62 &= V_184 ;
if ( V_62 == V_174 [ V_32 ] . V_190 )
break;
}
V_32 ++ ;
}
return V_174 [ V_32 ] . V_191 ;
}
static struct V_192 const * F_37 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_32 , V_184 , V_193 , V_41 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_193 = V_66 [ V_60 ] . V_194 ;
V_193 = V_193 & 0x3f ;
V_184 = V_3 -> V_10 ;
if ( V_3 -> V_9 & V_49 )
V_184 = V_184 | V_195 ;
if ( V_41 & V_129 )
V_184 = V_184 | V_196 ;
V_32 = 0 ;
while ( V_197 [ V_32 ] . V_188 != 0xffff ) {
if ( ( V_184 & V_197 [ V_32 ] . V_188 ) ==
V_197 [ V_32 ] . V_190 )
break;
V_32 ++ ;
}
return & V_197 [ V_32 ] . V_191 [ V_193 ] ;
}
static void F_38 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
struct V_198 const * V_199 ;
if ( ! ( V_3 -> V_9 & ( V_48 | V_46 ) ) )
return;
V_199 = F_36 ( V_200 , V_29 , V_30 ,
V_60 , V_3 ) ;
V_3 -> V_201 = V_199 -> V_201 ;
V_3 -> V_202 = V_199 -> V_202 ;
V_3 -> V_203 = V_199 -> V_204 ;
V_3 -> V_205 = V_199 -> V_206 ;
if ( V_3 -> V_8 & ( V_207 | V_186 ) )
return;
if ( ( V_3 -> V_6 == V_92 ) ||
( V_3 -> V_6 == V_208 ) ) {
V_3 -> V_180 = 1024 ;
V_3 -> V_182 = 768 ;
} else if ( ( V_3 -> V_6 == V_74 ) ||
( V_3 -> V_6 == V_209 ) ) {
V_3 -> V_180 = 1280 ;
V_3 -> V_182 = 1024 ;
} else if ( V_3 -> V_6 == V_210 ) {
V_3 -> V_180 = 1400 ;
V_3 -> V_182 = 1050 ;
} else {
V_3 -> V_180 = 1600 ;
V_3 -> V_182 = 1200 ;
}
}
static void F_39 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_32 ;
struct V_211 const * V_199 = NULL ;
struct V_212 const * V_213 = NULL ;
if ( V_3 -> V_9 & ( V_48 | V_46 ) ) {
V_199 = F_36 ( V_214 , V_29 , V_30 ,
V_60 , V_3 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_3 -> V_100 . V_96 [ V_32 ] = V_199 [ 0 ] . V_215 [ V_32 ] ;
}
F_16 ( V_3 , V_36 ) ;
if ( V_3 -> V_9 & ( V_48 | V_46 ) ) {
V_213 = F_36 ( V_216 , V_29 ,
V_30 , V_60 ,
V_3 ) ;
for ( V_32 = 0 ; V_32 < 7 ; V_32 ++ )
V_3 -> V_102 . V_96 [ V_32 ] = V_213 [ 0 ] . V_215 [ V_32 ] ;
}
F_17 ( V_30 , V_29 , V_3 ) ;
}
static unsigned short F_40 ( struct V_2 * V_3 )
{
unsigned char V_193 , V_217 , V_218 , V_32 ;
V_217 = F_2 ( V_3 -> V_38 , 0x36 ) ;
V_193 = V_217 & 0x0F ;
V_217 = V_217 & 0xF0 ;
V_32 = 0 ;
V_218 = V_3 -> V_18 [ V_32 ] . V_219 ;
while ( V_218 != 0xFF ) {
if ( V_218 & 0x80 ) {
V_193 = V_217 ;
V_218 = V_218 & ~ ( 0x80 ) ;
}
if ( V_193 == V_218 )
break;
V_32 ++ ;
V_218 = V_3 -> V_18 [ V_32 ] . V_219 ;
}
return V_32 ;
}
static unsigned short F_41 ( struct V_2 * V_3 )
{
unsigned short V_217 , V_193 , V_218 , V_32 ;
V_193 = V_3 -> V_6 ;
V_217 = V_3 -> V_7 ;
V_32 = 0 ;
V_218 = V_3 -> V_18 [ V_32 ] . V_219 ;
while ( V_218 != 0xFF ) {
if ( ( V_218 & 0x80 ) && ( V_218 != 0x80 ) ) {
V_193 = V_217 ;
V_218 &= ~ 0x80 ;
}
if ( V_193 == V_218 )
break;
V_32 ++ ;
V_218 = V_3 -> V_18 [ V_32 ] . V_219 ;
}
if ( V_218 == 0xFF ) {
V_3 -> V_6 = V_92 ;
V_3 -> V_7 = 0 ;
V_32 = 0 ;
}
return V_32 ;
}
static void F_42 ( unsigned short * V_220 ,
unsigned short * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_222 ;
V_222 = F_40 ( V_3 ) ;
* V_220 = V_3 -> V_18 [ V_222 ] . V_223 ;
* V_221 = V_3 -> V_18 [ V_222 ] . V_224 ;
return;
}
static void F_43 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_62 , V_61 , V_125 , V_184 , V_225 , V_226 , V_41 ;
unsigned long V_24 , V_227 , V_133 , V_228 , V_229 ;
struct V_230 const * V_213 = NULL ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_213 = F_36 ( V_231 , V_29 , V_30 ,
V_60 , V_3 ) ;
F_42 ( & V_61 , & V_62 , V_3 ) ;
V_225 = V_62 ;
V_226 = V_61 ;
if ( ( V_3 -> V_6 == V_92 ) ||
( V_3 -> V_6 == V_208 ) ) {
V_61 = 1024 ;
V_62 = 768 ;
} else if ( ( V_3 -> V_6 == V_74 ) ||
( V_3 -> V_6 == V_209 ) ) {
V_61 = 1280 ;
V_62 = 1024 ;
} else if ( V_3 -> V_6 == V_210 ) {
V_61 = 1400 ;
V_62 = 1050 ;
} else {
V_61 = 1600 ;
V_62 = 1200 ;
}
if ( V_3 -> V_8 & V_207 ) {
V_3 -> V_180 = V_61 ;
V_3 -> V_182 = V_62 ;
V_3 -> V_179 = V_61 ;
V_3 -> V_181 = V_62 ;
}
V_61 = V_3 -> V_203 ;
V_62 = V_213 -> V_232 ;
V_125 = V_3 -> V_180 ;
V_62 = V_62 & 0x0fff ;
V_125 += V_62 ;
if ( V_125 >= V_61 )
V_125 -= V_61 ;
F_4 ( V_3 -> V_233 , 0x1A , V_62 & 0x07 ) ;
V_125 = V_125 >> 3 ;
V_62 = V_62 >> 3 ;
F_4 ( V_3 -> V_233 , 0x16 ,
( unsigned short ) ( V_62 & 0xff ) ) ;
F_4 ( V_3 -> V_233 , 0x17 ,
( unsigned short ) ( V_125 & 0xff ) ) ;
V_61 = V_3 -> V_203 ;
V_62 = V_213 -> V_234 ;
V_125 = V_226 ;
if ( V_3 -> V_8 & V_186 )
V_125 = V_213 -> V_235 ;
V_125 += V_62 ;
if ( V_125 >= V_61 )
V_125 -= V_61 ;
V_61 = V_62 & 0x07 ;
V_61 = V_61 >> 5 ;
V_125 = V_125 >> 3 ;
V_62 = V_62 >> 3 ;
V_125 &= 0x1f ;
V_61 |= V_125 ;
F_4 ( V_3 -> V_233 , 0x15 , V_61 ) ;
F_4 ( V_3 -> V_233 , 0x14 ,
( unsigned short ) ( V_62 & 0xff ) ) ;
V_61 = V_3 -> V_205 ;
V_62 = V_213 -> V_236 ;
V_125 = V_3 -> V_182 ;
V_62 = V_62 & 0x0fff ;
V_125 += V_62 ;
if ( V_125 >= V_61 )
V_125 -= V_61 ;
F_4 ( V_3 -> V_233 , 0x1b ,
( unsigned short ) ( V_62 & 0xff ) ) ;
F_4 ( V_3 -> V_233 , 0x1c ,
( unsigned short ) ( V_125 & 0xff ) ) ;
V_62 = ( V_62 >> 8 ) & 0x07 ;
V_125 = ( V_125 >> 8 ) & 0x07 ;
F_4 ( V_3 -> V_233 , 0x1d ,
( unsigned short ) ( ( V_125 << 3 )
| V_62 ) ) ;
V_61 = V_3 -> V_205 ;
V_62 = V_213 -> V_237 ;
V_125 = V_225 ;
if ( V_3 -> V_8 & V_186 )
V_125 = V_213 -> V_238 ;
V_125 += V_62 ;
if ( V_125 >= V_61 )
V_125 -= V_61 ;
F_4 ( V_3 -> V_233 , 0x18 ,
( unsigned short ) ( V_62 & 0xff ) ) ;
F_12 ( V_3 -> V_233 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_125 & 0x0f ) ) ;
V_61 = ( ( V_62 >> 8 ) & 0x07 ) << 3 ;
V_62 = V_3 -> V_181 ;
if ( V_62 != V_3 -> V_182 )
V_61 |= 0x40 ;
if ( V_3 -> V_8 & V_239 )
V_61 |= 0x40 ;
F_12 ( V_3 -> V_233 , 0x1a , 0x07 ,
V_61 ) ;
V_125 = V_3 -> V_202 ;
V_62 = V_3 -> V_182 ;
V_61 = V_3 -> V_181 ;
V_125 -= V_61 ;
V_24 = V_61 ;
V_227 = ( V_24 << 18 ) / V_62 ;
V_184 = ( unsigned short ) ( ( V_24 << 18 ) % V_62 ) ;
if ( V_184 != 0 )
V_227 += 1 ;
V_133 = V_227 ;
V_229 = V_133 ;
F_4 ( V_3 -> V_233 , 0x37 ,
( unsigned short ) ( V_133 & 0xff ) ) ;
F_4 ( V_3 -> V_233 , 0x36 ,
( unsigned short ) ( ( V_133 >> 8 ) & 0xff ) ) ;
V_62 = ( unsigned short ) ( V_133 >> 16 ) ;
V_61 = V_62 & 0x03 ;
V_62 = V_3 -> V_181 ;
if ( V_62 == V_3 -> V_182 )
V_61 |= 0x04 ;
F_4 ( V_3 -> V_233 , 0x35 , V_61 ) ;
if ( V_3 -> V_15 & V_71 ) {
V_133 = V_229 ;
F_4 ( V_3 -> V_240 ,
0x3c ,
( unsigned short ) ( V_133 & 0xff ) ) ;
F_4 ( V_3 -> V_240 ,
0x3b ,
( unsigned short ) ( ( V_133 >> 8 ) &
0xff ) ) ;
V_62 = ( unsigned short ) ( V_133 >> 16 ) ;
F_12 ( V_3 -> V_240 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_62 &
0xff ) << 6 ) ) ;
V_125 = V_3 -> V_181 ;
if ( V_125 == V_3 -> V_182 )
F_12 ( V_3 -> V_240 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_12 ( V_3 -> V_240 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_125 = V_3 -> V_179 ;
V_62 = V_3 -> V_180 ;
V_227 = V_125 << 16 ;
V_61 = ( unsigned short ) ( V_227 / V_62 ) ;
if ( ( V_62 & 0xffff ) == ( V_125 & 0xffff ) )
V_61 = 65535 ;
V_228 = V_61 ;
V_227 = V_3 -> V_179 << 16 ;
V_227 /= V_228 ;
V_228 = V_228 << 16 ;
V_227 -= 1 ;
V_228 = ( V_228 & 0xffff0000 ) + ( V_227 & 0xffff ) ;
V_61 = ( unsigned short ) ( V_228 & 0xff ) ;
F_4 ( V_3 -> V_233 , 0x1f , V_61 ) ;
V_227 = V_3 -> V_181 << 18 ;
V_227 = V_227 / V_229 ;
V_62 = ( unsigned short ) ( V_227 & 0xffff ) ;
if ( V_3 -> V_6 == V_92 )
V_62 -= 1 ;
V_61 = ( ( V_62 >> 8 ) & 0xff ) << 3 ;
V_61 |= ( unsigned short ) ( ( V_228 >> 8 ) & 0x07 ) ;
F_4 ( V_3 -> V_233 , 0x20 ,
( unsigned short ) ( V_61 & 0xff ) ) ;
F_4 ( V_3 -> V_233 , 0x21 ,
( unsigned short ) ( V_62 & 0xff ) ) ;
V_228 = V_228 >> 16 ;
if ( V_41 & V_129 )
V_228 = V_228 >> 1 ;
F_4 ( V_3 -> V_233 , 0x22 ,
( unsigned short ) ( ( V_228 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 -> V_233 , 0x23 ,
( unsigned short ) ( V_228 & 0xff ) ) ;
}
static void F_44 ( unsigned char * V_241 , unsigned char * V_242 ,
struct V_2 * V_3 )
{
unsigned short V_104 ;
if ( V_3 -> V_9 & ( V_48 | V_46 ) ) {
V_104 = F_41 ( V_3 ) ;
if ( V_3 -> V_9 & V_48 ) {
* V_241 = V_3 -> V_18 [ V_104 ] . V_243 ;
* V_242 = V_3 -> V_18 [ V_104 ] . V_244 ;
} else {
* V_241 = V_3 -> V_18 [ V_104 ] . V_245 ;
* V_242 = V_3 -> V_18 [ V_104 ] . V_246 ;
}
}
return;
}
static unsigned char F_45 ( unsigned short V_60 ,
unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_104 , V_41 ;
unsigned char V_193 ;
V_41 = V_42 [ V_30 ] . V_43 ;
if ( ( V_3 -> V_79 & V_247 ) &&
( ! ( V_3 -> V_8 & V_186 ) ) ) {
V_104 = F_40 ( V_3 ) ;
V_193 = V_3 -> V_18 [ V_104 ] . V_248 ;
if ( V_3 -> V_9 & ( V_48 | V_46 ) )
return V_193 ;
if ( V_3 -> V_15 &
( V_86 |
V_87 |
V_16 |
V_17 |
V_71 ) ) {
if ( V_3 -> V_9 & V_77 ) {
V_193 = V_249 + V_143 ;
if ( ! ( V_3 -> V_10 & V_141 ) )
V_193 = V_249 + V_144 ;
if ( V_3 -> V_10 & V_80 ) {
V_193 = V_249 + V_145 ;
if ( ! ( V_41 & V_45 ) )
V_193 = V_249 +
V_146 ;
}
return V_193 ;
}
if ( V_3 -> V_10 & V_250 ) {
V_193 = V_251 ;
return V_193 ;
}
if ( V_3 -> V_10 & V_252 ) {
V_193 = V_253 ;
return V_193 ;
}
V_193 = V_254 ;
if ( ! ( V_3 -> V_10 & V_255 ) ) {
V_193 = V_249 + V_149 ;
if ( ! ( V_3 -> V_10 & V_141 ) )
V_193 = V_249 + V_150 ;
}
if ( V_3 -> V_9 & V_47 )
return V_193 ;
}
}
F_7 ( ( V_3 -> V_256 + 0x02 ) ) ;
V_193 = V_66 [ V_60 ] . V_151 ;
return V_193 ;
}
static void F_46 ( unsigned char V_193 , unsigned char * V_241 ,
unsigned char * V_242 , struct V_2 * V_3 )
{
if ( V_3 -> V_15 & ( V_257 | V_86 | V_87
| V_16 | V_17 | V_71 ) ) {
if ( ( ! ( V_3 -> V_9 & V_46 ) ) &&
( V_3 -> V_79 & V_247 ) ) {
* V_241 = V_153 [ V_193 ] . V_154 ;
* V_242 = V_153 [ V_193 ] . V_155 ;
}
} else {
* V_241 = V_57 [ V_193 ] . V_58 ;
* V_242 = V_57 [ V_193 ] . V_59 ;
}
}
static void F_47 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned char V_241 , V_242 , V_193 ;
int V_32 ;
V_193 = F_45 ( V_60 , V_29 , V_30 ,
V_3 ) ;
F_46 ( V_193 , & V_241 , & V_242 , V_3 ) ;
F_44 ( & V_241 , & V_242 , V_3 ) ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
F_12 ( V_3 -> V_38 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_32 ) ) ;
if ( ( ! ( V_3 -> V_9 & V_46 ) )
&& ( ! ( V_3 -> V_9 & V_49 ) ) ) {
F_4 ( V_3 -> V_28 , 0x2e , V_241 ) ;
F_4 ( V_3 -> V_28 , 0x2f , V_242 ) ;
} else {
F_4 ( V_3 -> V_28 , 0x2b , V_241 ) ;
F_4 ( V_3 -> V_28 , 0x2c , V_242 ) ;
}
}
}
static void F_48 ( struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_258 , V_259 , V_24 , V_218 , V_61 ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
V_258 = 0 ;
V_259 = 0 ;
V_24 = F_2 ( V_3 -> V_28 , 0x01 ) ;
if ( ! ( V_24 & 0x20 ) ) {
V_24 = F_2 ( V_3 -> V_38 , 0x17 ) ;
if ( V_24 & 0x80 ) {
V_24 = F_2 ( V_3 -> V_38 , 0x53 ) ;
if ( ! ( V_24 & 0x40 ) )
V_258 |= V_260 ;
}
}
V_24 = F_2 ( V_3 -> V_233 , 0x2e ) ;
V_24 &= 0x0f ;
if ( ! ( V_24 == 0x08 ) ) {
V_61 = F_2 ( V_3 -> V_233 , 0x13 ) ;
if ( V_61 & 0x04 )
V_258 = V_258 | V_261 ;
V_24 &= 0x05 ;
if ( ! ( V_258 & V_261 ) )
if ( V_24 == 0x01 )
V_258 |= V_262 ;
if ( V_24 == 0x04 )
V_258 |= V_261 ;
if ( V_24 == 0x05 ) {
V_24 = F_2 ( V_3 -> V_263 , 0x00 ) ;
if ( ! ( V_24 & 0x08 ) )
V_259 |= V_264 ;
if ( ! ( V_24 & 0x04 ) )
V_259 |= V_265 ;
if ( V_24 & 0x02 )
V_259 |= V_266 ;
if ( V_3 -> V_9 & V_77 ) {
if ( V_24 & 0x01 )
V_259 |= V_267 ;
}
if ( V_3 -> V_9 & V_84 ) {
V_24 = F_2 (
V_3 -> V_263 ,
0x4d ) ;
if ( V_24 & 0x10 )
V_259 |= V_268 ;
}
if ( V_259 != 0 )
V_258 |= V_269 ;
}
}
V_24 = F_2 ( V_3 -> V_38 , 0x3d ) ;
if ( V_258 & V_261 ) {
if ( ( V_3 -> V_79 & V_270 ) ) {
if ( V_24 & V_269 )
V_258 |= V_269 ;
}
}
V_24 = V_258 ;
V_218 = ~ V_271 ;
F_12 ( V_3 -> V_38 , 0x3d , V_218 , V_24 ) ;
if ( ! ( V_3 -> V_79 & V_270 ) )
F_4 ( V_3 -> V_38 , 0x3e , V_259 ) ;
} else {
return;
}
}
void F_49 ( struct V_2 * V_3 )
{
unsigned short V_272 , V_62 , V_217 ;
if ( V_3 -> V_68 != 0 )
return;
V_62 = V_87 ;
V_272 = F_2 ( V_3 -> V_240 , 0x00 ) ;
if ( V_272 == 0x02 )
goto V_273;
V_62 = V_257 ;
V_272 = F_2 ( V_3 -> V_240 , 0x01 ) ;
if ( V_272 < 0xB0 )
goto V_273;
V_62 = V_86 ;
if ( V_272 < 0xC0 )
goto V_274;
V_62 = V_71 ;
if ( V_272 < 0xD0 )
goto V_274;
V_62 = V_16 ;
if ( V_272 < 0xE0 )
goto V_274;
V_62 = V_17 ;
V_217 = F_2 ( V_3 -> V_240 , 0x39 ) ;
if ( V_217 != 0xFF )
V_62 = V_71 ;
V_274:
if ( V_62 & ( V_86 | V_87 ) ) {
V_272 = F_2 ( V_3 -> V_240 , 0x23 ) ;
if ( ! ( V_272 & 0x02 ) )
V_62 = V_62 | V_275 ;
}
V_273:
V_3 -> V_15 = V_62 ;
}
static void F_50 ( unsigned short V_29 , unsigned short V_30 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_61 , V_276 , V_62 , V_24 , V_41 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_3 -> V_79 = 0 ;
V_3 -> V_55 = V_41 & V_277 ;
V_62 = 0 ;
if ( ! ( V_3 -> V_15 & 0xFFFF ) )
return;
V_24 = F_2 ( V_3 -> V_38 , 0x30 ) ;
V_62 = V_62 | V_24 ;
V_24 = F_2 ( V_3 -> V_38 , 0x31 ) ;
V_276 = V_24 ;
V_276 = V_276 << 8 ;
V_61 = V_24 << 8 ;
V_62 = V_62 | V_61 ;
V_24 = ( V_278 | V_84 | V_46
| V_49 | V_279 ) ;
V_24 = 0xFFFF ^ V_24 ;
V_62 &= V_24 ;
V_24 = F_2 ( V_3 -> V_38 , 0x38 ) ;
if ( V_3 -> V_15 & ( V_87 | V_16 | V_17 |
V_71 ) ) {
if ( V_24 & V_280 ) {
V_62 |= V_278 ;
if ( V_24 & V_281 )
V_62 |= V_46 ;
}
}
if ( V_3 -> V_282 == 1 ) {
if ( V_3 -> V_15 & ( V_16 | V_17 | V_71 ) ) {
if ( V_24 & V_283 ) {
if ( V_3 -> V_284 == 1 ) {
V_24 = F_2 ( V_3 -> V_38 ,
0x35 ) ;
V_24 &= V_285 ;
V_62 |= V_77 ;
if ( V_24 != V_286 ) {
V_62 &= ( ~ V_77 ) ;
V_62 |= V_84 ;
}
}
}
}
}
V_61 = V_276 ;
if ( V_3 -> V_282 == 1 ) {
if ( V_3 -> V_284 == 1 )
V_24 = 0x09FC ;
else
V_24 = 0x097C ;
} else if ( V_3 -> V_284 == 1 ) {
V_24 = 0x01FC ;
} else {
V_24 = 0x017C ;
}
if ( ! ( V_62 & V_24 ) ) {
V_61 |= V_279 ;
V_62 = 0 ;
}
if ( ! ( V_3 -> V_15 & V_275 ) ) {
if ( V_62 & V_46 ) {
if ( V_62 & V_287 )
V_62 &= ( ~ ( V_48 | V_69 |
V_288 ) ) ;
else
V_62 &= ( ~ ( V_48 | V_69 |
V_47 | V_288 ) ) ;
}
}
if ( ! ( V_62 & ( V_288 | V_287 ) ) ) {
if ( V_3 -> V_289 == 1 ) {
if ( V_62 & V_69 ) {
V_62 &= ( 0xFF00 | V_69 |
V_288 | V_287 ) ;
V_62 &= ( 0x00FF | ( ~ V_84 ) ) ;
}
} else {
V_62 &= ( ~ ( V_69 | V_48 |
V_47 ) ) ;
}
}
if ( ! ( V_3 -> V_15 & V_275 ) ) {
if ( V_62 & V_48 ) {
V_62 &= ( 0xFF00 | V_48 | V_288 |
V_287 ) ;
V_62 &= ( 0x00FF | ( ~ V_84 ) ) ;
}
}
if ( V_62 & V_83 ) {
V_62 &= ( 0xFF00 | V_83 | V_288 |
V_287 ) ;
V_62 &= ( 0x00FF | ( ~ V_84 ) ) ;
}
if ( V_3 -> V_282 == 1 ) {
if ( V_62 & V_84 )
V_62 &= ( 0xFF00 | V_288 | V_287 ) ;
}
if ( V_3 -> V_284 == 1 ) {
if ( V_62 & V_77 )
V_62 &= ( 0xFF00 | V_77 | V_288 |
V_287 ) ;
}
if ( V_61 & V_279 ) {
if ( ! ( V_62 & ( V_288 | V_287 ) ) )
V_62 = V_279 ;
}
if ( ! ( V_62 & V_279 ) ) {
if ( ( ! ( V_62 & V_290 ) ) || ( ! ( V_41 & V_291 ) ) ) {
if ( ! ( V_62 & V_46 ) )
V_62 |= ( V_49 | V_287 ) ;
}
if ( ( V_62 & V_49 ) && ( V_62 & V_46 ) ) {
V_62 ^= ( V_48 | V_46 |
V_278 ) ;
V_3 -> V_79 |= V_270 ;
}
}
V_3 -> V_9 = V_62 ;
}
static void F_51 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_62 = 0 , V_63 = 0 , V_41 , V_292 ;
if ( V_3 -> V_9 & V_47 ) {
V_41 = V_42 [ V_30 ] . V_43 ;
V_63 = V_42 [ V_30 ] . V_65 ;
V_62 = F_2 ( V_3 -> V_38 , 0x35 ) ;
if ( V_62 & V_89 ) {
V_62 &= ( V_293 |
V_294 |
V_295 |
V_89 ) ;
if ( V_62 & V_294 )
V_62 &= ~ V_89 ;
} else
V_62 &= ( V_293 |
V_296 |
V_89 ) ;
if ( V_3 -> V_9 & V_83 )
V_62 |= V_89 ;
if ( V_3 -> V_282 == 1 ) {
if ( V_3 -> V_9 & V_84 ) {
V_292 = F_2 ( V_3 -> V_38 , 0x35 ) ;
V_292 &= V_285 ;
if ( V_292 == V_297 )
V_62 |= V_298 ;
if ( V_292 == V_299 )
V_62 = V_62 | V_252 ;
if ( V_292 == V_300 )
V_62 = V_62 | V_250 ;
}
}
if ( V_3 -> V_284 == 1 ) {
if ( V_3 -> V_9 & V_77 )
V_62 = V_62 | V_301 | V_89 ;
}
if ( ( V_3 -> V_9 & V_49 ) &&
( ! ( V_3 -> V_9 & V_91 ) ) )
V_62 |= V_80 ;
if ( ! ( V_62 & V_89 ) && ( V_41 > 13 ) && ( V_63 == 8 ) )
V_62 |= V_255 ;
V_62 |= V_141 ;
if ( V_3 -> V_9 & V_77 ) {
if ( V_3 -> V_9 & V_49 )
V_62 &= ( ~ V_141 ) ;
} else if ( V_62 & ( V_252 | V_250 ) ) {
V_62 &= ( ~ V_141 ) ;
} else if ( ! ( V_3 -> V_15 & ( V_86 | V_87 |
V_16 | V_17 |
V_71 ) ) ) {
if ( V_62 & V_80 )
V_62 &= ( ~ V_141 ) ;
}
}
V_3 -> V_10 = V_62 ;
}
static unsigned char F_52 ( unsigned short V_29 ,
unsigned short V_30 , struct V_2 * V_3 )
{
unsigned short V_24 , V_61 , V_62 , V_63 = 0 , V_302 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = 0 ;
V_63 = V_42 [ V_30 ] . V_65 ;
V_24 = F_2 ( V_3 -> V_38 , 0x36 ) ;
V_62 = V_24 & 0x0F ;
if ( V_62 == 0 )
V_62 = V_92 ;
if ( ( V_62 == V_92 ) || ( V_62 == V_74 ) ) {
if ( V_3 -> V_9 & V_290 ) {
V_61 = F_2 ( V_3 -> V_38 , 0x33 ) ;
if ( V_3 -> V_9 & V_46 )
V_61 &= 0x0F ;
else
V_61 = V_61 >> 4 ;
if ( ( V_63 == 6 ) || ( V_63 == 9 ) ) {
if ( V_61 >= 3 )
V_62 |= V_303 ;
} else if ( ( V_63 == 7 ) || ( V_63 == 8 ) ) {
if ( V_61 >= 4 )
V_62 |= V_303 ;
}
}
}
V_3 -> V_6 = V_62 ;
if ( ! ( V_3 -> V_9 & ( V_48 | V_46 ) ) )
return 0 ;
V_62 = 0 ;
V_24 = F_2 ( V_3 -> V_38 , 0x37 ) ;
V_24 &= ( V_304 | V_76 | V_305 | V_306 ) ;
V_62 |= V_24 ;
V_302 = F_41 ( V_3 ) ;
V_61 = V_3 -> V_18 [ V_302 ] . V_307 ;
if ( ( ( V_3 -> V_15 & V_17 ) ||
( V_3 -> V_15 & V_71 ) ) && ( V_61 & V_308 ) )
V_62 |= V_309 ;
if ( ( V_3 -> V_6 == V_210 ) &&
( V_3 -> V_9 & V_48 ) && ( V_63 == 9 ) &&
( ! ( V_62 & V_186 ) ) )
V_62 |= V_207 ;
if ( V_3 -> V_9 & V_49 ) {
if ( V_3 -> V_9 & V_91 )
V_62 |= V_310 ;
} else {
V_62 |= V_310 ;
}
V_3 -> V_8 = V_62 ;
return 1 ;
}
unsigned char F_53 ( unsigned short V_29 ,
unsigned short * V_30 , struct V_2 * V_3 )
{
for ( * V_30 = 0 ; ; ( * V_30 ) ++ ) {
if ( V_42 [ * V_30 ] . V_311 == V_29 )
break;
if ( V_42 [ * V_30 ] . V_311 == 0xFF )
return 0 ;
}
return 1 ;
}
static unsigned char F_54 ( unsigned char V_312 )
{
unsigned char V_313 = 0 ;
unsigned char V_32 = 0 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
V_313 = V_313 << 1 ;
V_313 |= ( V_312 >> V_32 ) & 1 ;
}
return V_313 ;
}
static unsigned char F_55 ( struct V_2 * V_3 )
{
unsigned char V_314 , V_24 ;
V_314 = F_2 ( V_3 -> V_38 , 0x4A ) ;
F_13 ( V_3 -> V_38 , 0x4A , ~ 0x23 ) ;
V_24 = F_2 ( V_3 -> V_38 , 0x48 ) ;
V_24 = F_54 ( V_24 ) ;
V_24 &= 0x23 ;
F_4 ( V_3 -> V_38 , 0x4A , V_314 ) ;
return V_24 ;
}
static unsigned char F_56 ( struct V_2 * V_3 )
{
unsigned char V_314 , V_315 , V_24 ;
V_314 = F_2 ( V_3 -> V_38 , 0x4A ) ;
F_13 ( V_3 -> V_38 , 0x4A , ~ 0x0C ) ;
V_24 = F_2 ( V_3 -> V_38 , 0x48 ) ;
V_24 &= 0x0C ;
V_24 >>= 2 ;
F_4 ( V_3 -> V_38 , 0x4A , V_314 ) ;
V_315 = F_2 ( V_3 -> V_38 , 0xB4 ) ;
V_24 |= ( ( V_315 & 0x04 ) << 3 ) ;
return V_24 ;
}
static void F_57 ( unsigned short V_316 , unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned char V_314 , V_24 ;
V_314 = F_2 ( V_3 -> V_38 , 0x4A ) ;
V_316 &= 0x23 ;
V_218 &= 0x23 ;
F_13 ( V_3 -> V_38 , 0x4A , ~ V_316 ) ;
if ( V_316 & 0x20 ) {
V_24 = ( V_218 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_38 , 0xB4 , ~ 0x02 , V_24 ) ;
}
V_24 = F_2 ( V_3 -> V_38 , 0x48 ) ;
V_24 = F_54 ( V_24 ) ;
V_24 &= ~ V_316 ;
V_24 |= V_218 ;
F_4 ( V_3 -> V_38 , 0x48 , V_24 ) ;
}
static void F_58 ( unsigned short V_316 , unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned char V_314 , V_24 ;
unsigned short V_317 , V_318 ;
V_317 = V_316 ;
V_318 = V_218 ;
V_317 &= 0x20 ;
V_318 &= 0x20 ;
V_317 >>= 3 ;
V_318 >>= 3 ;
if ( V_316 & 0x20 ) {
V_24 = ( V_218 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_38 , 0xB4 , ~ 0x02 , V_24 ) ;
}
F_12 ( V_3 -> V_38 , 0xB4 , ~ V_317 , V_318 ) ;
V_314 = F_2 ( V_3 -> V_38 , 0x4A ) ;
V_316 &= 0x03 ;
V_218 &= 0x03 ;
V_316 <<= 2 ;
V_218 <<= 2 ;
F_13 ( V_3 -> V_38 , 0x4A , ~ V_316 ) ;
F_12 ( V_3 -> V_38 , 0x48 , ~ V_316 , V_218 ) ;
}
static void F_59 ( struct V_319 * V_320 ,
struct V_35 * V_321 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_28 , 0x01 , 0xDF , 0x00 ) ;
if ( V_321 -> V_101 == V_156 ) {
if ( V_3 -> V_68 == 1 ) {
if ( ! ( F_55 ( V_3 ) & 0x1 ) ) {
F_57 ( 0x01 , 0x01 , V_3 ) ;
F_60 ( V_320 -> V_322 . V_323 ) ;
}
if ( ! ( F_55 ( V_3 ) & 0x20 ) )
F_57 ( 0x20 , 0x20 , V_3 ) ;
F_60 ( V_320 -> V_322 . V_324 ) ;
F_57 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_57 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_321 -> V_101 == V_23 ) {
if ( V_3 -> V_68 == 1 ) {
if ( ! ( F_56 ( V_3 ) & 0x1 ) ) {
F_58 ( 0x01 , 0x01 , V_3 ) ;
F_60 ( V_320 -> V_322 . V_323 ) ;
}
if ( ! ( F_56 ( V_3 ) & 0x20 ) )
F_58 ( 0x20 , 0x20 , V_3 ) ;
F_60 ( V_320 -> V_322 . V_324 ) ;
F_58 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_58 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_61 ( struct V_319 * V_320 ,
struct V_35 * V_321 ,
struct V_2 * V_3 )
{
if ( V_321 -> V_101 == V_156 ) {
if ( V_3 -> V_68 == 1 ) {
F_57 ( 0x02 , 0x00 , V_3 ) ;
F_60 ( V_320 -> V_322 . V_324 ) ;
} else {
F_57 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_321 -> V_101 == V_23 ) {
if ( ( F_56 ( V_3 ) & 0x2 ) ) {
F_58 ( 0x02 , 0x00 , V_3 ) ;
F_60 ( V_320 -> V_322 . V_324 ) ;
}
if ( V_3 -> V_68 == 0 )
F_58 ( 0x20 , 0x00 , V_3 ) ;
}
F_12 ( V_3 -> V_28 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_62 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 -> V_50 ) & 0x01 ) )
break;
while ( ! ( F_7 ( V_3 -> V_50 ) & 0x01 ) )
break;
}
static void F_63 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_233 , 0x01 , 0x40 ) ;
}
static void F_64 ( unsigned short V_29 ,
struct V_2 * V_3 )
{
unsigned short V_227 , V_133 ;
F_4 ( V_3 -> V_38 , 0x34 , V_29 ) ;
V_227 = ( V_3 -> V_9 & V_49 ) >> 8 ;
V_133 = ~ ( V_49 >> 8 ) ;
F_12 ( V_3 -> V_38 , 0x31 , V_133 , V_227 ) ;
}
static void F_65 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_160 , V_178 , V_41 , V_124 ;
V_124 = V_42 [ V_30 ] . V_65 ;
V_160 = V_126 [ V_124 ] . V_127 ;
V_178 = V_126 [ V_124 ] . V_128 ;
V_41 = V_42 [ V_30 ] . V_43 ;
if ( V_41 & V_129 )
V_160 *= 2 ;
if ( V_41 & V_103 )
V_178 *= 2 ;
if ( ! ( V_3 -> V_9 & V_48 ) )
goto exit;
if ( V_3 -> V_6 == V_325 ) {
if ( ! ( V_3 -> V_8 & V_310 ) ) {
if ( V_178 == 1024 )
V_178 = 1056 ;
}
}
if ( V_3 -> V_6 == V_74 ) {
if ( V_178 == 400 )
V_178 = 405 ;
else if ( V_178 == 350 )
V_178 = 360 ;
if ( V_3 -> V_8 & V_310 ) {
if ( V_178 == 360 )
V_178 = 375 ;
}
}
if ( V_3 -> V_6 == V_92 ) {
if ( ! ( V_3 -> V_8 & V_310 ) ) {
if ( ! ( V_3 -> V_8 & V_76 ) ) {
if ( V_178 == 350 )
V_178 = 357 ;
else if ( V_178 == 400 )
V_178 = 420 ;
else if ( V_178 == 480 )
V_178 = 525 ;
}
}
}
if ( V_160 == 720 )
V_160 = 640 ;
exit:
V_3 -> V_179 = V_160 ;
V_3 -> V_180 = V_160 ;
V_3 -> V_181 = V_178 ;
V_3 -> V_182 = V_178 ;
}
static unsigned char F_66 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_9 & ( V_48 | V_46 ) ) &&
( V_3 -> V_8 & V_309 ) )
return 1 ;
return 0 ;
}
static void F_67 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_61 , V_62 , V_227 , V_133 , V_41 = 0 , V_125 ,
V_326 ;
V_3 -> V_327 = 1 ;
V_3 -> V_328 = 1 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_326 = V_66 [ V_60 ] . V_105 ;
V_326 &= V_106 ;
V_227 = ( unsigned short ) V_107 [ V_326 ] . V_108 [ 0 ] ;
V_133 = ( unsigned short ) V_107 [ V_326 ] . V_108 [ 5 ] ;
V_61 = ( V_227 & 0xFF ) | ( ( V_133 & 0x03 ) << 8 ) ;
V_62 = ( unsigned short ) V_107 [ V_326 ] . V_108 [ 8 ] ;
V_125 = ( unsigned short )
V_107 [ V_326 ] . V_108 [ 14 ] << 8 ;
V_125 &= 0x0100 ;
V_125 = V_125 << 2 ;
V_62 |= V_125 ;
V_227 = ( unsigned short ) V_107 [ V_326 ] . V_108 [ 9 ] ;
if ( V_227 & 0x01 )
V_62 |= 0x0100 ;
if ( V_227 & 0x20 )
V_62 |= 0x0200 ;
V_61 += 5 ;
if ( V_41 & V_45 )
V_61 *= 8 ;
else
V_61 *= 9 ;
V_3 -> V_201 = V_61 ;
V_3 -> V_203 = V_61 ;
V_62 ++ ;
V_3 -> V_202 = V_62 ;
V_3 -> V_205 = V_62 ;
}
static void F_68 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_61 = 0 , V_62 = 0 , V_41 , V_63 ;
struct V_329 const * V_199 = NULL ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_63 = V_42 [ V_30 ] . V_65 ;
V_3 -> V_330 = 0 ;
V_3 -> V_331 = 50 ;
if ( V_3 -> V_9 & V_69 ) {
F_67 ( V_29 , V_30 , V_60 ,
V_3 ) ;
return;
}
if ( V_3 -> V_9 & ( V_48 | V_46 ) ) {
V_199 = F_36 ( V_332 , V_29 , V_30 ,
V_60 , V_3 ) ;
V_3 -> V_327 = V_199 -> V_327 ;
V_3 -> V_328 = V_199 -> V_328 ;
V_3 -> V_201 = V_199 -> V_201 ;
V_3 -> V_202 = V_199 -> V_202 ;
V_3 -> V_203 = V_199 -> V_204 ;
V_3 -> V_205 = V_199 -> V_206 ;
if ( V_3 -> V_6 == V_92 ) {
V_61 = 1024 ;
V_62 = 768 ;
if ( ! ( V_3 -> V_8 & V_310 ) ) {
if ( V_3 -> V_181 == 357 )
V_62 = 527 ;
else if ( V_3 -> V_181 == 420 )
V_62 = 620 ;
else if ( V_3 -> V_181 == 525 )
V_62 = 775 ;
else if ( V_3 -> V_181 == 600 )
V_62 = 775 ;
else
V_62 = 768 ;
} else
V_62 = 768 ;
} else if ( V_3 -> V_6 == V_208 ) {
V_61 = 1024 ;
V_62 = 768 ;
} else if ( V_3 -> V_6 == V_74 ) {
V_61 = 1280 ;
if ( V_3 -> V_181 == 360 )
V_62 = 768 ;
else if ( V_3 -> V_181 == 375 )
V_62 = 800 ;
else if ( V_3 -> V_181 == 405 )
V_62 = 864 ;
else
V_62 = 1024 ;
} else if ( V_3 -> V_6 == V_209 ) {
V_61 = 1280 ;
V_62 = 1024 ;
} else if ( V_3 -> V_6 == V_75 ) {
V_61 = 1280 ;
if ( V_3 -> V_181 == 350 )
V_62 = 700 ;
else if ( V_3 -> V_181 == 400 )
V_62 = 800 ;
else if ( V_3 -> V_181 == 1024 )
V_62 = 960 ;
else
V_62 = 960 ;
} else if ( V_3 -> V_6 == V_210 ) {
V_61 = 1400 ;
V_62 = 1050 ;
if ( V_3 -> V_181 == 1024 ) {
V_61 = 1280 ;
V_62 = 1024 ;
}
} else if ( V_3 -> V_6 == V_325 ) {
V_61 = 1600 ;
V_62 = 1200 ;
if ( ! ( V_3 -> V_8 & V_310 ) ) {
if ( V_3 -> V_181 == 350 )
V_62 = 875 ;
else if ( V_3 -> V_181 == 400 )
V_62 = 1000 ;
}
}
if ( V_3 -> V_8 & V_76 ) {
V_61 = V_3 -> V_179 ;
V_62 = V_3 -> V_181 ;
}
V_3 -> V_180 = V_61 ;
V_3 -> V_182 = V_62 ;
return;
}
if ( V_3 -> V_9 & ( V_47 ) ) {
struct V_192 const * V_333 ;
V_333 = F_37 ( V_29 , V_30 , V_60 ,
V_3 ) ;
V_3 -> V_327 = V_333 -> V_327 ;
V_3 -> V_328 = V_333 -> V_328 ;
V_3 -> V_201 = V_333 -> V_201 ;
V_3 -> V_202 = V_333 -> V_202 ;
V_3 -> V_180 = V_333 -> V_334 ;
V_3 -> V_182 = V_333 -> V_335 ;
V_3 -> V_331 = V_333 -> V_331 ;
V_3 -> V_330 = V_333 -> V_336 ;
if ( V_3 -> V_9 & V_77 ) {
if ( V_63 == 0x08 )
V_3 -> V_330 = 0x40 ;
else if ( V_63 == 0x09 )
V_3 -> V_330 = 0x40 ;
else if ( V_63 == 0x12 )
V_3 -> V_330 = 0x40 ;
if ( V_3 -> V_181 == 350 )
V_3 -> V_10 |= V_80 ;
V_61 = V_337 ;
V_62 = V_338 ;
if ( V_3 -> V_9 & V_49 ) {
if ( V_3 -> V_10 & V_80 ) {
V_61 = V_339 ;
V_62 = V_340 ;
if ( ! ( V_41 & V_45 ) ) {
V_61 = V_341 ;
V_62 = V_342 ;
}
}
}
} else if ( V_3 -> V_9 & V_84 ) {
if ( V_3 -> V_10 & V_250 ) {
V_61 = V_343 ;
V_62 = V_344 ;
}
if ( V_3 -> V_10 & V_252 ) {
V_61 = V_345 ;
V_62 = V_346 ;
} else if ( V_3 -> V_10 & V_298 ) {
V_61 = V_347 ;
V_62 = V_348 ;
if ( V_3 -> V_10 & V_255 )
V_61 = V_349 ;
}
} else {
V_61 = V_350 ;
V_62 = V_351 ;
if ( ! ( V_3 -> V_10 & V_89 ) ) {
V_61 = V_352 ;
V_62 = V_353 ;
if ( V_3 -> V_10 & V_255 )
V_61 = V_349 ;
}
}
V_3 -> V_203 = V_61 ;
V_3 -> V_205 = V_62 ;
return;
}
}
static void F_69 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned char V_241 , V_242 , V_193 ;
V_193 = F_45 ( V_60 , V_29 , V_30 ,
V_3 ) ;
F_46 ( V_193 , & V_241 , & V_242 , V_3 ) ;
F_44 ( & V_241 , & V_242 , V_3 ) ;
if ( V_3 -> V_15 & V_257 ) {
F_4 ( V_3 -> V_240 , 0x0A , 0x10 ) ;
F_4 ( V_3 -> V_240 , 0x0B , V_242 ) ;
F_4 ( V_3 -> V_240 , 0x0A , V_241 ) ;
} else {
F_4 ( V_3 -> V_240 , 0x0A , V_241 ) ;
F_4 ( V_3 -> V_240 , 0x0B , V_242 ) ;
}
F_4 ( V_3 -> V_240 , 0x00 , 0x12 ) ;
if ( V_3 -> V_9 & V_69 )
F_20 ( V_3 -> V_240 , 0x12 , 0x28 ) ;
else
F_20 ( V_3 -> V_240 , 0x12 , 0x08 ) ;
}
static unsigned short F_70 ( unsigned short V_29 ,
unsigned short V_30 , struct V_2 * V_3 )
{
unsigned short V_354 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_104 ;
unsigned short V_41 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_104 = ( V_41 & V_277 ) - V_137 ;
if ( V_104 < 0 )
V_104 = 0 ;
return V_354 [ V_104 ] ;
}
static unsigned short F_71 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_24 , V_355 , V_356 , V_104 , V_64 ,
V_354 [] = { 0x01 , 0x02 , 0x04 } ;
V_356 = V_42 [ V_30 ] . V_135 ;
V_64 = V_66 [ V_60 ] . V_93 ;
V_104 = ( V_356 >> 8 ) & 0xFF ;
V_24 = V_136 [ V_104 ] ;
if ( V_64 & V_130 )
V_24 = V_24 << 1 ;
V_355 = F_70 ( V_29 , V_30 , V_3 ) ;
if ( ( V_29 >= 0x7C ) && ( V_29 <= 0x7E ) ) {
V_24 = V_29 - 0x7C ;
V_355 = V_354 [ V_24 ] ;
V_24 = 0x6B ;
if ( V_64 & V_130 )
V_24 = V_24 << 1 ;
}
return V_24 * V_355 ;
}
static void F_72 ( unsigned short V_29 ,
unsigned short V_30 ,
unsigned short V_60 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_357 ;
unsigned char V_24 ;
if ( V_3 -> V_9 & V_49 )
return;
V_357 = F_71 ( V_29 , V_30 , V_60 ,
V_36 , V_3 ) ;
V_24 = ( unsigned char ) ( V_357 & 0xFF ) ;
F_4 ( V_3 -> V_233 , 0x07 , V_24 ) ;
V_24 = ( unsigned char ) ( ( V_357 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_233 , 0x09 , V_24 ) ;
V_24 = ( unsigned char ) ( ( ( V_357 >> 3 ) & 0xFF ) + 1 ) ;
F_4 ( V_3 -> V_233 , 0x03 , V_24 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
F_4 ( V_3 -> V_233 , 0x01 , 0x3B ) ;
F_12 ( V_3 -> V_233 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_74 ( unsigned short V_29 , unsigned short V_30 ,
struct V_35 * V_36 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
T_1 V_125 ;
F_72 ( V_29 , V_30 , V_60 ,
V_36 , V_3 ) ;
F_73 ( V_3 ) ;
for ( V_125 = 4 ; V_125 < 7 ; V_125 ++ )
F_4 ( V_3 -> V_233 , V_125 , 0x0 ) ;
F_4 ( V_3 -> V_233 , 0x50 , 0x00 ) ;
F_4 ( V_3 -> V_233 , 0x02 , 0x44 ) ;
}
static void F_75 ( unsigned short V_29 , unsigned short V_30 ,
struct V_35 * V_36 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_24 = 0 , V_61 = 0 , V_62 = 0 , V_125 = 0 ,
V_358 = 0 , V_326 , V_41 ;
V_326 = V_66 [ V_60 ] . V_105 ;
V_326 &= V_106 ;
V_41 = V_42 [ V_30 ] . V_43 ;
if ( V_41 & V_129 ) {
V_24 = ( V_3 -> V_201 / 2 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_233 , 0x08 , V_24 ) ;
V_24 = ( ( ( V_3 -> V_201 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_233 , 0x09 , ~ 0x0F0 , V_24 ) ;
V_24 = ( V_3 -> V_179 / 2 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_233 , 0x0A , V_24 ) ;
V_125 = ( ( V_3 -> V_201 - V_3 -> V_179 ) / 2 ) >> 2 ;
V_358 = V_3 -> V_179 / 2 + 16 ;
V_125 = V_125 >> 1 ;
V_62 = V_358 + V_125 ;
V_125 += V_62 ;
if ( V_3 -> V_9 & V_69 ) {
V_62 = V_107 [ V_326 ] . V_108 [ 4 ] ;
V_62 |= ( ( V_107 [ V_326 ] . V_108 [ 14 ] &
0xC0 ) << 2 ) ;
V_62 = ( V_62 - 3 ) << 3 ;
V_125 = V_107 [ V_326 ] . V_108 [ 5 ] ;
V_125 &= 0x1F ;
V_24 = V_107 [ V_326 ] . V_108 [ 15 ] ;
V_24 = ( V_24 & 0x04 ) << ( 5 - 2 ) ;
V_125 = ( ( V_125 | V_24 ) - 3 ) << 3 ;
}
V_62 += 4 ;
V_125 += 4 ;
if ( V_125 > ( V_3 -> V_201 / 2 ) )
V_125 = V_3 -> V_201 / 2 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x0B , V_24 ) ;
} else {
V_24 = ( V_3 -> V_201 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_233 , 0x08 , V_24 ) ;
V_24 = ( ( ( V_3 -> V_201 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_233 , 0x09 , ~ 0x0F0 , V_24 ) ;
V_24 = ( V_3 -> V_179 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_233 , 0x0A , V_24 ) ;
V_125 = ( V_3 -> V_201 - V_3 -> V_179 ) >> 2 ;
V_358 = V_3 -> V_179 + 16 ;
V_125 = V_125 >> 1 ;
V_62 = V_358 + V_125 ;
V_125 += V_62 ;
if ( V_3 -> V_9 & V_69 ) {
V_62 = V_107 [ V_326 ] . V_108 [ 3 ] ;
V_62 |= ( ( V_107 [ V_326 ] . V_108 [ 5 ] &
0xC0 ) << 2 ) ;
V_62 = ( V_62 - 3 ) << 3 ;
V_125 = V_107 [ V_326 ] . V_108 [ 4 ] ;
V_125 &= 0x1F ;
V_24 = V_107 [ V_326 ] . V_108 [ 6 ] ;
V_24 = ( V_24 & 0x04 ) << ( 5 - 2 ) ;
V_125 = ( ( V_125 | V_24 ) - 3 ) << 3 ;
V_62 += 16 ;
V_125 += 16 ;
}
if ( V_125 > V_3 -> V_201 )
V_125 = V_3 -> V_201 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x0B , V_24 ) ;
}
V_61 = ( V_61 & 0x00FF ) | ( V_62 & 0xFF00 ) ;
V_62 = V_358 ;
V_62 = ( V_62 & 0x00FF ) | ( ( V_62 & 0xFF00 ) << 4 ) ;
V_61 |= ( V_62 & 0xFF00 ) ;
V_24 = ( V_61 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_233 , 0x0C , V_24 ) ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x0D , V_24 ) ;
V_125 = ( V_3 -> V_202 - 1 ) ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x0E , V_24 ) ;
V_62 = V_3 -> V_181 - 1 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x0F , V_24 ) ;
V_24 = ( ( V_62 & 0xFF00 ) << 3 ) >> 8 ;
V_24 |= ( ( V_125 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_233 , 0x12 , V_24 ) ;
V_61 = V_3 -> V_181 ;
V_62 = V_3 -> V_181 ;
V_125 = V_3 -> V_202 ;
V_62 = ( V_3 -> V_202 + V_3 -> V_181 ) >> 1 ;
V_125 = ( ( V_3 -> V_202 - V_3 -> V_181 ) >> 4 ) + V_62 + 1 ;
if ( V_3 -> V_9 & V_69 ) {
V_62 = V_107 [ V_326 ] . V_108 [ 10 ] ;
V_24 = V_107 [ V_326 ] . V_108 [ 9 ] ;
if ( V_24 & 0x04 )
V_62 |= 0x0100 ;
if ( V_24 & 0x080 )
V_62 |= 0x0200 ;
V_24 = V_107 [ V_326 ] . V_108 [ 14 ] ;
if ( V_24 & 0x08 )
V_62 |= 0x0400 ;
V_24 = V_107 [ V_326 ] . V_108 [ 11 ] ;
V_125 = ( V_125 & 0xFF00 ) | ( V_24 & 0x00FF ) ;
}
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x10 , V_24 ) ;
V_24 = ( ( V_62 & 0xFF00 ) >> 8 ) << 4 ;
V_24 = ( ( V_125 & 0x000F ) | ( V_24 ) ) ;
F_4 ( V_3 -> V_233 , 0x11 , V_24 ) ;
V_61 = 0 ;
if ( V_41 & V_103 )
V_61 |= 0x80 ;
if ( V_41 & V_129 )
V_61 |= 0x40 ;
F_12 ( V_3 -> V_233 , 0x2C , ~ 0x0C0 , V_61 ) ;
}
static unsigned short F_76 ( struct V_2 * V_3 )
{
unsigned long V_61 , V_62 ;
V_62 = ( ( V_3 -> V_202 - V_3 -> V_181 ) * V_3 -> V_327 )
& 0xFFFF ;
V_61 = ( V_3 -> V_205 - V_3 -> V_182 ) * V_3 -> V_328 ;
V_61 = ( V_61 * V_3 -> V_203 ) / V_62 ;
return ( unsigned short ) V_61 ;
}
static void F_77 ( unsigned short V_29 , unsigned short V_30 ,
struct V_35 * V_36 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_225 , V_226 , V_61 , V_62 = 0 , V_125 , V_24 , V_63 ,
V_41 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_63 = V_42 [ V_30 ] . V_65 ;
if ( ! ( V_3 -> V_9 & V_49 ) )
return;
V_24 = 0xFF ;
F_4 ( V_3 -> V_233 , 0x03 , V_24 ) ;
V_125 = 0x08 ;
if ( V_3 -> V_15 & ( V_16 | V_17 | V_71 ) )
V_41 |= V_45 ;
V_61 = V_3 -> V_179 ;
if ( V_41 & V_129 )
V_61 = V_61 >> 1 ;
V_61 = ( V_61 / V_125 ) - 1 ;
V_62 |= ( ( V_61 & 0x00FF ) << 8 ) ;
V_24 = V_61 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x04 , V_24 ) ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_9 & V_47 ) {
if ( ! ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) )
V_24 += 2 ;
if ( ( V_3 -> V_9 & V_77 ) &&
! ( V_3 -> V_15 & V_16 ) && ( V_63 == 7 ) )
V_24 -= 2 ;
}
F_4 ( V_3 -> V_233 , 0x05 , V_24 ) ;
F_4 ( V_3 -> V_233 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_9 & V_279 ) ) {
if ( V_3 -> V_9 & V_47 )
V_61 = V_3 -> V_201 ;
else
V_61 = F_76 ( V_3 ) ;
}
if ( V_61 >= V_3 -> V_201 )
V_61 = V_3 -> V_201 ;
if ( V_41 & V_129 )
V_61 = V_61 >> 1 ;
V_61 = ( V_61 / V_125 ) - 5 ;
V_125 = V_61 ;
if ( V_3 -> V_9 & V_77 ) {
V_24 = ( V_62 & 0x00FF ) - 1 ;
if ( ! ( V_41 & V_129 ) ) {
V_24 -= 6 ;
if ( V_3 -> V_10 & V_80 ) {
V_24 -= 4 ;
V_24 -= 10 ;
}
}
} else {
V_62 = ( V_62 & 0xFF00 ) >> 8 ;
V_125 = ( V_125 + V_62 ) >> 1 ;
V_24 = ( V_125 & 0x00FF ) + 2 ;
if ( V_3 -> V_9 & V_47 ) {
V_24 -= 1 ;
if ( ! ( V_41 & V_129 ) ) {
if ( ( V_41 & V_45 ) ) {
V_24 += 4 ;
if ( V_3 -> V_179 >= 800 )
V_24 -= 6 ;
}
}
} else if ( ! ( V_41 & V_129 ) ) {
V_24 -= 4 ;
if ( V_3 -> V_6 != V_75 &&
V_3 -> V_179 >= 800 ) {
V_24 -= 7 ;
if ( V_3 -> V_179 >= 1280 &&
V_3 -> V_6 != V_75 &&
( V_3 -> V_8 & V_76 ) )
V_24 += 28 ;
}
}
}
F_4 ( V_3 -> V_233 , 0x07 , V_24 ) ;
F_4 ( V_3 -> V_233 , 0x08 , 0 ) ;
if ( V_3 -> V_9 & V_47 ) {
if ( V_3 -> V_10 & V_80 ) {
if ( V_29 == 0x50 ) {
if ( V_3 -> V_10 & V_359 ) {
F_4 ( V_3 -> V_233 ,
0x07 , 0x30 ) ;
F_4 ( V_3 -> V_233 ,
0x08 , 0x03 ) ;
} else {
F_4 ( V_3 -> V_233 ,
0x07 , 0x2f ) ;
F_4 ( V_3 -> V_233 ,
0x08 , 0x02 ) ;
}
}
}
}
F_4 ( V_3 -> V_233 , 0x18 , 0x03 ) ;
F_12 ( V_3 -> V_233 , 0x19 , 0xF0 , 0x00 ) ;
F_4 ( V_3 -> V_233 , 0x09 , 0xFF ) ;
V_62 = V_3 -> V_202 ;
V_225 = V_62 ;
V_125 = 0x121 ;
V_62 = V_3 -> V_181 ;
if ( V_62 == 357 )
V_62 = 350 ;
if ( V_62 == 360 )
V_62 = 350 ;
if ( V_62 == 375 )
V_62 = 350 ;
if ( V_62 == 405 )
V_62 = 400 ;
if ( V_62 == 525 )
V_62 = 480 ;
V_226 = V_62 ;
if ( V_3 -> V_9 & V_48 ) {
if ( V_3 -> V_6 == V_92 ) {
if ( ! ( V_3 -> V_8 & V_310 ) ) {
if ( V_62 == 350 )
V_62 += 5 ;
if ( V_62 == 480 )
V_62 += 5 ;
}
}
}
V_62 -- ;
V_24 = V_62 & 0x00FF ;
V_62 -- ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x10 , V_24 ) ;
V_62 = V_226 ;
V_62 -- ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x0E , V_24 ) ;
if ( V_62 & 0x0100 )
V_125 |= 0x0002 ;
V_61 = 0x000B ;
if ( V_41 & V_103 )
V_61 |= 0x08000 ;
if ( V_62 & 0x0200 )
V_125 |= 0x0040 ;
V_24 = ( V_61 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_233 , 0x0B , V_24 ) ;
if ( V_62 & 0x0400 )
V_125 |= 0x0600 ;
F_4 ( V_3 -> V_233 , 0x11 , 0x00 ) ;
V_61 = V_225 ;
V_61 -= V_62 ;
V_61 = V_61 >> 2 ;
V_225 = V_61 ;
if ( V_63 != 0x09 ) {
V_61 = V_61 << 1 ;
V_62 += V_61 ;
}
if ( V_3 -> V_9 & V_77 ) {
if ( ( V_3 -> V_15 & V_16 ) &&
! ( V_3 -> V_10 & V_301 ) ) {
if ( ( V_3 -> V_10 & V_80 ) &&
( V_3 -> V_10 & V_89 ) ) {
if ( ! ( V_3 -> V_15 & V_16 ) ||
! ( V_3 -> V_10 &
( V_252 |
V_250 |
V_301 ) ) )
V_62 += 40 ;
}
} else {
V_62 -= 10 ;
}
} else if ( V_3 -> V_10 & V_80 ) {
if ( V_3 -> V_10 & V_89 ) {
if ( V_3 -> V_15 & V_16 ) {
if ( ! ( V_3 -> V_10 &
( V_252 |
V_250 |
V_301 ) ) )
V_62 += 40 ;
} else {
V_62 += 40 ;
}
}
}
V_61 = V_225 ;
V_61 = V_61 >> 2 ;
V_61 ++ ;
V_61 += V_62 ;
V_225 = V_61 ;
if ( ( V_3 -> V_10 & V_89 ) ) {
if ( V_62 <= 513 ) {
if ( V_61 >= 513 )
V_62 = 513 ;
}
}
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x0C , V_24 ) ;
V_62 -- ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x10 , V_24 ) ;
if ( V_62 & 0x0100 )
V_125 |= 0x0008 ;
if ( V_62 & 0x0200 )
F_12 ( V_3 -> V_233 , 0x0B , 0x0FF , 0x20 ) ;
V_62 ++ ;
if ( V_62 & 0x0100 )
V_125 |= 0x0004 ;
if ( V_62 & 0x0200 )
V_125 |= 0x0080 ;
if ( V_62 & 0x0400 )
V_125 |= 0x0C00 ;
V_62 = V_225 ;
V_24 = V_62 & 0x00FF ;
V_24 &= 0x0F ;
F_4 ( V_3 -> V_233 , 0x0D , V_24 ) ;
if ( V_62 & 0x0010 )
V_125 |= 0x2000 ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_233 , 0x0A , V_24 ) ;
V_24 = ( V_125 & 0x0FF00 ) >> 8 ;
F_4 ( V_3 -> V_233 , 0x17 , V_24 ) ;
V_61 = V_41 ;
V_24 = ( V_61 & 0xFF00 ) >> 8 ;
V_24 = ( V_24 >> 1 ) & 0x09 ;
if ( V_3 -> V_15 & ( V_16 | V_17 | V_71 ) )
V_24 |= 0x01 ;
F_4 ( V_3 -> V_233 , 0x16 , V_24 ) ;
F_4 ( V_3 -> V_233 , 0x0F , 0 ) ;
F_4 ( V_3 -> V_233 , 0x12 , 0 ) ;
if ( V_3 -> V_8 & V_360 )
V_24 = 0x80 ;
else
V_24 = 0x00 ;
F_4 ( V_3 -> V_233 , 0x1A , V_24 ) ;
return;
}
static void F_78 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_32 , V_99 , V_61 , V_62 , V_125 , V_24 , V_225 , V_226 ,
V_41 ;
unsigned char const * V_361 ;
unsigned long V_362 , V_363 , V_364 , V_133 , V_365 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_61 = 0 ;
if ( ! ( V_3 -> V_9 & V_81 ) )
V_61 |= 0x0800 ;
if ( ! ( V_3 -> V_9 & V_82 ) )
V_61 |= 0x0400 ;
if ( V_3 -> V_9 & V_83 )
V_61 |= 0x0200 ;
if ( ! ( V_3 -> V_10 & V_89 ) )
V_61 |= 0x1000 ;
if ( V_3 -> V_9 & V_77 )
V_61 |= 0x0100 ;
if ( V_3 -> V_10 & ( V_252 | V_250 ) )
V_61 &= 0xfe00 ;
V_61 = ( V_61 & 0xff00 ) >> 8 ;
F_4 ( V_3 -> V_263 , 0x0 , V_61 ) ;
V_361 = V_366 ;
if ( V_3 -> V_10 & V_89 )
V_361 = V_367 ;
if ( V_3 -> V_9 & V_77 ) {
V_361 = V_368 ;
if ( V_3 -> V_9 & V_49 )
V_361 = V_369 ;
if ( V_3 -> V_79 & V_80 )
V_361 = V_370 ;
if ( ! ( V_41 & V_45 ) )
V_361 = V_371 ;
}
if ( V_3 -> V_9 & V_84 ) {
if ( V_3 -> V_10 & V_298 )
V_361 = V_372 ;
if ( V_3 -> V_10 & V_252 )
V_361 = V_373 ;
if ( V_3 -> V_10 & V_250 )
V_361 = V_374 ;
}
for ( V_32 = 0x01 , V_99 = 0 ; V_32 <= 0x2D ; V_32 ++ , V_99 ++ )
F_4 ( V_3 -> V_263 , V_32 , V_361 [ V_99 ] ) ;
for ( V_32 = 0x39 ; V_32 <= 0x45 ; V_32 ++ , V_99 ++ )
F_4 ( V_3 -> V_263 , V_32 , V_361 [ V_99 ] ) ;
if ( V_3 -> V_9 & V_47 )
F_12 ( V_3 -> V_263 , 0x3A , 0x1F , 0x00 ) ;
V_24 = V_3 -> V_330 ;
V_24 &= 0x80 ;
F_12 ( V_3 -> V_263 , 0x0A , 0xFF , V_24 ) ;
if ( V_3 -> V_9 & V_77 )
V_61 = 950 ;
if ( V_3 -> V_10 & V_89 )
V_61 = 520 ;
else
V_61 = 440 ;
if ( V_3 -> V_182 <= V_61 ) {
V_61 -= V_3 -> V_182 ;
V_61 = V_61 >> 2 ;
V_61 = ( V_61 & 0x00FF ) | ( ( V_61 & 0x00FF ) << 8 ) ;
V_225 = V_61 ;
V_24 = ( V_61 & 0xFF00 ) >> 8 ;
V_24 += ( unsigned short ) V_361 [ 0 ] ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
if ( V_3 -> V_9 & ( V_81
| V_82 | V_83
| V_84 ) ) {
V_125 = V_3 -> V_179 ;
if ( V_125 >= 1024 ) {
V_24 = 0x17 ;
if ( V_3 -> V_10 & V_89 )
V_24 = 0x19 ;
}
}
}
F_4 ( V_3 -> V_263 , 0x01 , V_24 ) ;
V_61 = V_225 ;
V_24 = ( V_61 & 0xFF00 ) >> 8 ;
V_24 += V_361 [ 1 ] ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
if ( ( V_3 -> V_9 & ( V_81
| V_82 | V_83
| V_84 ) ) ) {
V_125 = V_3 -> V_179 ;
if ( V_125 >= 1024 ) {
V_24 = 0x1D ;
if ( V_3 -> V_10 & V_89 )
V_24 = 0x52 ;
}
}
}
F_4 ( V_3 -> V_263 , 0x02 , V_24 ) ;
}
V_125 = V_3 -> V_203 ;
if ( F_66 ( V_3 ) )
V_125 = V_125 >> 1 ;
V_125 -= 2 ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x1B , V_24 ) ;
V_24 = ( V_125 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_263 , 0x1D , ~ 0x0F , V_24 ) ;
V_125 = V_3 -> V_203 >> 1 ;
V_225 = V_125 ;
V_125 += 7 ;
if ( V_3 -> V_9 & V_77 )
V_125 -= 4 ;
V_24 = V_125 & 0x00FF ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_263 , 0x22 , 0x0F , V_24 ) ;
V_62 = V_361 [ V_99 ] | ( ( V_361 [ V_99 + 1 ] ) << 8 ) ;
V_62 += V_125 ;
V_226 = V_62 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x24 , V_24 ) ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_263 , 0x25 , 0x0F , V_24 ) ;
V_62 = V_226 ;
V_62 = V_62 + 8 ;
if ( V_3 -> V_9 & V_77 ) {
V_62 = V_62 - 4 ;
V_125 = V_62 ;
}
V_24 = ( V_62 & 0x00FF ) << 4 ;
F_12 ( V_3 -> V_263 , 0x29 , 0x0F , V_24 ) ;
V_99 += 2 ;
V_125 += ( V_361 [ V_99 ] | ( ( V_361 [ V_99 + 1 ] ) << 8 ) ) ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x27 , V_24 ) ;
V_24 = ( ( V_125 & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_263 , 0x28 , 0x0F , V_24 ) ;
V_125 += 8 ;
if ( V_3 -> V_9 & V_77 )
V_125 -= 4 ;
V_24 = V_125 & 0xFF ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_263 , 0x2A , 0x0F , V_24 ) ;
V_125 = V_225 ;
V_99 += 2 ;
V_24 = V_361 [ V_99 ] | ( ( V_361 [ V_99 + 1 ] ) << 8 ) ;
V_125 -= V_24 ;
V_24 = V_125 & 0x00FF ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_263 , 0x2D , 0x0F , V_24 ) ;
V_125 -= 11 ;
if ( ! ( V_3 -> V_9 & V_47 ) ) {
V_61 = F_76 ( V_3 ) ;
V_125 = V_61 - 1 ;
}
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x2E , V_24 ) ;
V_62 = V_3 -> V_182 ;
if ( V_3 -> V_181 == 360 )
V_62 = 746 ;
if ( V_3 -> V_181 == 375 )
V_62 = 746 ;
if ( V_3 -> V_181 == 405 )
V_62 = 853 ;
if ( V_3 -> V_9 & V_47 ) {
if ( V_3 -> V_15 &
( V_16 | V_17 | V_71 ) ) {
if ( ! ( V_3 -> V_10 &
( V_252 | V_250 ) ) )
V_62 = V_62 >> 1 ;
} else
V_62 = V_62 >> 1 ;
}
V_62 -= 2 ;
V_24 = V_62 & 0x00FF ;
if ( V_3 -> V_9 & V_77 ) {
if ( V_3 -> V_15 & V_16 ) {
if ( V_3 -> V_10 & V_301 ) {
if ( V_3 -> V_9 & V_49 ) {
if ( V_29 == 0x2f )
V_24 += 1 ;
}
}
} else if ( V_3 -> V_9 & V_49 ) {
if ( V_29 == 0x2f )
V_24 += 1 ;
}
}
F_4 ( V_3 -> V_263 , 0x2F , V_24 ) ;
V_24 = ( V_125 & 0xFF00 ) >> 8 ;
V_24 |= ( ( V_62 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_9 & V_77 ) ) {
if ( V_3 -> V_15 & V_16 ) {
if ( V_3 -> V_10 & V_301 ) {
V_24 |= 0x10 ;
if ( ! ( V_3 -> V_9 & V_82 ) )
V_24 |= 0x20 ;
}
} else {
V_24 |= 0x10 ;
if ( ! ( V_3 -> V_9 & V_82 ) )
V_24 |= 0x20 ;
}
}
F_4 ( V_3 -> V_263 , 0x30 , V_24 ) ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
V_62 = V_3 -> V_182 ;
V_125 = V_62 - 2 ;
if ( V_3 -> V_9 & V_47 ) {
if ( ! ( V_3 -> V_10 & ( V_252
| V_250 ) ) )
V_62 = V_62 >> 1 ;
}
if ( V_3 -> V_15 & ( V_17 | V_71 ) ) {
V_24 = 0 ;
if ( V_125 & 0x0400 )
V_24 |= 0x20 ;
if ( V_62 & 0x0400 )
V_24 |= 0x40 ;
F_4 ( V_3 -> V_240 , 0x10 , V_24 ) ;
}
V_24 = ( ( ( V_62 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_4 ( V_3 -> V_263 , 0x46 , V_24 ) ;
V_24 = ( V_62 - 3 ) & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x47 , V_24 ) ;
}
V_62 = V_62 & 0x00FF ;
if ( ! ( V_41 & V_129 ) ) {
V_125 = V_3 -> V_179 ;
if ( V_125 >= V_3 -> V_180 ) {
V_62 |= 0x2000 ;
V_61 &= 0x00FF ;
}
}
V_125 = 0x0101 ;
if ( V_3 -> V_9 & V_47 ) {
if ( V_3 -> V_179 >= 1024 ) {
V_125 = 0x1920 ;
if ( V_3 -> V_179 >= 1280 ) {
V_125 = 0x1420 ;
V_62 = V_62 & 0xDFFF ;
}
}
}
if ( ! ( V_62 & 0x2000 ) ) {
if ( V_41 & V_129 )
V_125 = ( V_125 & 0xFF00 ) | ( ( V_125 & 0x00FF ) << 1 ) ;
V_225 = V_62 ;
V_363 = V_3 -> V_179 ;
V_364 = ( V_125 & 0xFF00 ) >> 8 ;
V_362 = V_363 * V_364 ;
V_365 = V_125 & 0x00FF ;
V_362 = V_362 / V_365 ;
V_365 = 8 * 1024 ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
V_365 = V_365 * 8 ;
}
V_362 = V_362 * V_365 ;
V_365 = V_3 -> V_180 ;
V_133 = V_362 % V_365 ;
V_363 = V_362 / V_365 ;
if ( V_133 != 0 )
V_363 += 1 ;
V_61 = ( unsigned short ) V_363 ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
V_125 = ( ( V_61 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_62 = V_225 ;
V_62 = ( unsigned short ) ( ( ( V_363 & 0x0000FF00 ) & 0x1F00 )
| ( V_62 & 0x00FF ) ) ;
V_61 = ( unsigned short ) ( ( ( V_363 & 0x000000FF ) << 8 )
| ( V_61 & 0x00FF ) ) ;
V_24 = ( V_61 & 0xFF00 ) >> 8 ;
} else {
V_24 = ( V_61 & 0x00FF ) >> 8 ;
}
F_4 ( V_3 -> V_263 , 0x44 , V_24 ) ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_263 , 0x45 , ~ 0x03F , V_24 ) ;
V_24 = V_125 & 0x00FF ;
if ( V_62 & 0x2000 )
V_24 = 0 ;
if ( ! ( V_3 -> V_9 & V_48 ) )
V_24 |= 0x18 ;
F_12 ( V_3 -> V_263 , 0x46 , ~ 0x1F , V_24 ) ;
if ( V_3 -> V_10 & V_89 ) {
V_62 = 0x0382 ;
V_125 = 0x007e ;
} else {
V_62 = 0x0369 ;
V_125 = 0x0061 ;
}
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x4b , V_24 ) ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x4c , V_24 ) ;
V_24 = ( ( V_125 & 0xFF00 ) >> 8 ) & 0x03 ;
V_24 = V_24 << 2 ;
V_24 |= ( ( V_62 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_9 & V_84 ) {
V_24 |= 0x10 ;
if ( V_3 -> V_10 & V_252 )
V_24 |= 0x20 ;
if ( V_3 -> V_10 & V_250 )
V_24 |= 0x60 ;
}
F_4 ( V_3 -> V_263 , 0x4d , V_24 ) ;
V_24 = F_2 ( V_3 -> V_263 , 0x43 ) ;
F_4 ( V_3 -> V_263 , 0x43 , ( unsigned short ) ( V_24 - 3 ) ) ;
if ( ! ( V_3 -> V_10 & ( V_252 | V_250 ) ) ) {
if ( V_3 -> V_10 & V_255 ) {
V_361 = V_375 ;
for ( V_32 = 0x1c , V_99 = 0 ; V_32 <= 0x30 ; V_32 ++ , V_99 ++ ) {
F_4 ( V_3 -> V_263 , V_32 ,
V_361 [ V_99 ] ) ;
}
F_4 ( V_3 -> V_263 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_15 & V_71 ) {
if ( V_3 -> V_10 & V_294 )
F_12 ( V_3 -> V_263 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_10 & V_294 ) {
V_61 = F_2 ( V_3 -> V_263 , 0x01 ) ;
V_61 -- ;
F_13 ( V_3 -> V_263 , 0x01 , V_61 ) ;
F_13 ( V_3 -> V_263 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_9 & V_77 ) {
if ( ! ( V_3 -> V_9 & V_49 ) )
F_4 ( V_3 -> V_263 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_9 & V_47 )
return;
}
static void F_79 ( unsigned short V_29 , unsigned short V_30 ,
struct V_35 * V_36 ,
unsigned short V_60 ,
struct V_2 * V_3 )
{
unsigned short V_358 , V_61 , V_62 , V_125 , V_24 , V_217 ,
V_316 , V_259 ;
struct V_376 const * V_377 = NULL ;
if ( ! ( V_3 -> V_9 & V_48 ) )
return;
V_62 = V_3 -> V_180 ;
if ( F_66 ( V_3 ) )
V_62 = V_62 >> 1 ;
V_62 -= 1 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x2C , V_24 ) ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_263 , 0x2B , 0x0F , V_24 ) ;
V_24 = 0x01 ;
F_4 ( V_3 -> V_263 , 0x0B , V_24 ) ;
V_62 = V_3 -> V_182 ;
V_62 -- ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x03 , V_24 ) ;
V_24 = ( ( V_62 & 0xFF00 ) >> 8 ) & 0x07 ;
F_12 ( V_3 -> V_263 , 0x0C , ~ 0x07 , V_24 ) ;
V_125 = V_3 -> V_205 - 1 ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x19 , V_24 ) ;
V_24 = ( V_125 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 5 ;
F_4 ( V_3 -> V_263 , 0x1A , V_24 ) ;
F_12 ( V_3 -> V_263 , 0x09 , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_263 , 0x0A , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_263 , 0x17 , 0xFB , 0x00 ) ;
F_12 ( V_3 -> V_263 , 0x18 , 0xDF , 0x00 ) ;
if ( ( V_3 -> V_15 & V_16 ) || ( V_3 -> V_15 & V_17 ) )
V_377 = F_36 ( V_378 , V_29 , V_30 ,
V_60 , V_3 ) ;
else
V_377 = F_36 ( V_379 , V_29 ,
V_30 , V_60 ,
V_3 ) ;
V_217 = V_3 -> V_6 ;
V_217 &= V_187 ;
if ( ( V_217 == V_92 ) || ( V_217 == V_208 ) ) {
V_62 = 1024 ;
V_125 = 768 ;
} else if ( ( V_217 == V_74 ) ||
( V_217 == V_209 ) ) {
V_62 = 1280 ;
V_125 = 1024 ;
} else if ( V_217 == V_210 ) {
V_62 = 1400 ;
V_125 = 1050 ;
} else {
V_62 = 1600 ;
V_125 = 1200 ;
}
if ( V_3 -> V_8 & V_186 ) {
V_62 = V_3 -> V_180 ;
V_125 = V_3 -> V_182 ;
}
V_358 = V_62 ;
V_61 = V_3 -> V_205 ;
V_3 -> V_232 = V_377 -> V_232 ;
V_3 -> V_234 = V_377 -> V_234 ;
V_3 -> V_236 = V_377 -> V_236 ;
V_3 -> V_237 = V_377 -> V_237 ;
V_62 = V_3 -> V_236 ;
V_125 += V_62 ;
if ( V_125 >= V_61 )
V_125 -= V_61 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x05 , V_24 ) ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x06 , V_24 ) ;
V_259 = ( ( V_125 & 0xFF00 ) >> 8 ) & 0x07 ;
V_316 = ( ( V_62 & 0xFF00 ) >> 8 ) & 0x07 ;
V_217 = V_259 ;
V_217 = V_217 << 3 ;
V_217 |= V_316 ;
F_4 ( V_3 -> V_263 , 0x02 , V_217 ) ;
F_42 ( & V_61 , & V_62 , V_3 ) ;
V_125 = V_62 ;
V_61 = V_3 -> V_205 ;
V_62 = V_3 -> V_237 ;
V_125 += V_62 ;
if ( V_125 >= V_61 )
V_125 -= V_61 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x04 , V_24 ) ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 4 ;
V_24 |= ( V_125 & 0x000F ) ;
F_4 ( V_3 -> V_263 , 0x01 , V_24 ) ;
V_125 = V_358 ;
V_61 = V_3 -> V_203 ;
V_62 = V_3 -> V_232 ;
V_62 &= 0x0FFF ;
if ( F_66 ( V_3 ) ) {
V_61 = V_61 >> 1 ;
V_62 = V_62 >> 1 ;
V_125 = V_125 >> 1 ;
}
if ( V_3 -> V_15 & V_17 )
V_62 += 1 ;
if ( V_3 -> V_15 & V_71 )
V_62 += 1 ;
V_125 += V_62 ;
if ( V_125 >= V_61 )
V_125 -= V_61 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x1F , V_24 ) ;
V_24 = ( ( V_62 & 0xFF00 ) >> 8 ) << 4 ;
F_4 ( V_3 -> V_263 , 0x20 , V_24 ) ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x23 , V_24 ) ;
V_24 = ( V_125 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_263 , 0x25 , V_24 ) ;
F_42 ( & V_61 , & V_62 , V_3 ) ;
V_125 = V_61 ;
V_61 = V_3 -> V_203 ;
V_62 = V_3 -> V_234 ;
if ( F_66 ( V_3 ) ) {
V_61 = V_61 >> 1 ;
V_62 = V_62 >> 1 ;
V_125 = V_125 >> 1 ;
}
if ( V_3 -> V_15 & V_17 )
V_62 += 1 ;
V_125 += V_62 ;
if ( V_125 >= V_61 )
V_125 -= V_61 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x1C , V_24 ) ;
V_24 = ( V_62 & 0xFF00 ) >> 8 ;
V_24 = V_24 << 4 ;
F_12 ( V_3 -> V_263 , 0x1D , ~ 0x0F0 , V_24 ) ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_263 , 0x21 , V_24 ) ;
if ( ! ( V_3 -> V_8 & V_310 ) ) {
if ( V_3 -> V_181 == 525 ) {
if ( V_3 -> V_15 & ( V_86 | V_87
| V_16 | V_17
| V_71 ) ) {
V_24 = 0xC6 ;
} else
V_24 = 0xC4 ;
F_4 ( V_3 -> V_263 , 0x2f , V_24 ) ;
F_4 ( V_3 -> V_263 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_181 == 420 ) {
if ( V_3 -> V_15 & ( V_86 | V_87
| V_16 | V_17
| V_71 ) ) {
V_24 = 0x4F ;
} else
V_24 = 0x4E ;
F_4 ( V_3 -> V_263 , 0x2f , V_24 ) ;
}
}
}
static struct V_380 const
* F_80 ( unsigned short V_125 , struct V_2 * V_3 )
{
unsigned short V_61 , V_62 , V_32 ;
struct V_380 const * V_381 ;
if ( V_125 == 0 ) {
V_61 = V_3 -> V_179 ;
V_62 = V_3 -> V_180 ;
} else {
V_61 = V_3 -> V_181 ;
V_62 = V_3 -> V_182 ;
}
if ( V_61 <= V_62 )
return & V_382 [ 0 ] ;
else
V_381 = V_383 ;
if ( V_3 -> V_10 & V_89 )
V_381 = V_384 ;
if ( V_3 -> V_9 & V_84 ) {
if ( ( V_3 -> V_10 & V_298 ) ||
( V_3 -> V_10 & V_252 ) )
V_381 = V_383 ;
if ( V_3 -> V_10 & V_250 )
V_381 = V_385 ;
}
if ( V_3 -> V_9 & V_77 )
V_381 = V_382 ;
V_32 = 0 ;
while ( V_381 [ V_32 ] . V_386 != 0xFFFF ) {
if ( V_381 [ V_32 ] . V_386 == V_61 )
break;
V_32 ++ ;
}
return & V_381 [ V_32 ] ;
}
static void F_81 ( struct V_2 * V_3 )
{
unsigned short V_32 , V_99 ;
struct V_380 const * V_381 ;
if ( ! ( V_3 -> V_15 & V_71 ) )
return;
V_381 = F_80 ( 0 , V_3 ) ;
for ( V_32 = 0x80 , V_99 = 0 ; V_32 <= 0xBF ; V_32 ++ , V_99 ++ )
F_4 ( V_3 -> V_263 , V_32 , V_381 -> V_215 [ V_99 ] ) ;
if ( ( V_3 -> V_9 & V_47 ) &&
( ! ( V_3 -> V_9 & V_77 ) ) ) {
V_381 = F_80 ( 1 , V_3 ) ;
for ( V_32 = 0xC0 , V_99 = 0 ; V_32 < 0xFF ; V_32 ++ , V_99 ++ )
F_4 ( V_3 -> V_263 ,
V_32 ,
V_381 -> V_215 [ V_99 ] ) ;
}
if ( ( V_3 -> V_9 & V_47 ) &&
( ! ( V_3 -> V_9 & V_77 ) ) )
F_12 ( V_3 -> V_263 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_12 ( V_3 -> V_263 , 0x4E , ~ 0x14 , 0x10 ) ;
}
static void F_82 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_32 ;
unsigned char const * V_387 ;
unsigned short V_41 ;
V_41 = V_42 [ V_30 ] . V_43 ;
F_4 ( V_3 -> V_388 , 0x00 , 0x00 ) ;
if ( V_3 -> V_10 & V_89 ) {
F_4 ( V_3 -> V_388 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_388 , 0x14 , 0xC8 ) ;
} else {
F_4 ( V_3 -> V_388 , 0x13 , 0xF5 ) ;
F_4 ( V_3 -> V_388 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_9 & V_47 ) )
return;
if ( V_3 -> V_10 & V_294 ) {
F_4 ( V_3 -> V_388 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_388 , 0x14 , 0xC8 ) ;
F_4 ( V_3 -> V_388 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_9 & V_77 ) || ( V_3 -> V_9
& V_84 ) ) {
if ( V_3 -> V_10 & V_298 )
return;
V_387 = V_389 ;
if ( V_3 -> V_79 & V_80 ) {
V_387 = V_390 ;
if ( ! ( V_41 & V_45 ) )
V_387 = V_391 ;
}
if ( V_3 -> V_10 & V_252 )
V_387 = V_392 ;
if ( V_3 -> V_10 & V_250 )
V_387 = V_393 ;
for ( V_32 = 0 ; V_32 <= 0x3E ; V_32 ++ )
F_4 ( V_3 -> V_388 , V_32 , V_387 [ V_32 ] ) ;
if ( V_3 -> V_15 & V_71 ) {
if ( V_3 -> V_10 & V_252 )
F_4 ( V_3 -> V_388 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_83 ( unsigned short V_29 , unsigned short V_30 ,
unsigned short V_60 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_61 , V_125 , V_62 , V_41 , V_24 , V_133 ;
unsigned long V_364 , V_363 , V_394 ;
V_41 = V_42 [ V_30 ] . V_43 ;
V_24 = V_3 -> V_328 ;
F_4 ( V_3 -> V_240 , 0x13 , V_24 ) ;
V_62 = V_3 -> V_327 ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_240 , 0x14 , V_24 ) ;
V_133 = ( ( V_62 & 0xFF00 ) >> 8 ) << 7 ;
V_125 = V_3 -> V_201 - 1 ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_240 , 0x16 , V_24 ) ;
V_24 = ( ( V_125 & 0xFF00 ) >> 8 ) << 3 ;
V_133 |= V_24 ;
V_125 = V_3 -> V_202 - 1 ;
if ( ! ( V_3 -> V_9 & V_47 ) )
V_125 -= 5 ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_240 , 0x17 , V_24 ) ;
V_24 = V_133 | ( ( V_125 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_240 , 0x15 , V_24 ) ;
F_20 ( V_3 -> V_240 , 0x0D , 0x08 ) ;
V_125 = V_3 -> V_9 ;
V_62 = V_3 -> V_179 ;
if ( V_41 & V_129 )
V_62 = V_62 >> 1 ;
if ( F_66 ( V_3 ) )
V_62 = V_62 >> 1 ;
if ( V_125 & V_77 ) {
V_24 = 0 ;
if ( V_62 <= 1024 )
V_24 = 0xA0 ;
if ( V_62 == 1280 )
V_24 = 0xC0 ;
} else if ( V_125 & V_47 ) {
V_24 = 0xA0 ;
if ( V_62 <= 800 )
V_24 = 0x80 ;
} else {
V_24 = 0x80 ;
if ( V_3 -> V_9 & V_48 ) {
V_24 = 0 ;
if ( V_62 > 800 )
V_24 = 0x60 ;
}
}
if ( V_3 -> V_10 & ( V_252 | V_250 ) ) {
V_24 = 0x00 ;
if ( V_3 -> V_179 == 1280 )
V_24 = 0x40 ;
if ( V_3 -> V_179 == 1024 )
V_24 = 0x20 ;
}
F_12 ( V_3 -> V_240 , 0x0E , ~ 0xEF , V_24 ) ;
V_364 = V_3 -> V_182 ;
if ( V_125 & V_77 ) {
if ( ! ( V_24 & 0xE000 ) )
V_62 = V_62 >> 1 ;
}
V_125 = V_3 -> V_331 ;
V_24 = V_125 & 0x00FF ;
F_4 ( V_3 -> V_240 , 0x18 , V_24 ) ;
V_363 = V_3 -> V_181 ;
V_125 |= 0x04000 ;
if ( V_363 <= V_364 ) {
V_125 = ( V_125 & ( ~ 0x4000 ) ) ;
V_363 = V_3 -> V_181 ;
} else {
V_363 -= V_364 ;
}
V_394 = ( V_363 * 256 * 1024 ) % V_364 ;
V_363 = ( V_363 * 256 * 1024 ) / V_364 ;
V_364 = V_363 ;
if ( V_394 != 0 )
V_364 ++ ;
V_24 = ( unsigned short ) ( V_364 & 0x000000FF ) ;
F_4 ( V_3 -> V_240 , 0x1B , V_24 ) ;
V_24 = ( unsigned short ) ( ( V_364 & 0x0000FF00 ) >> 8 ) ;
F_4 ( V_3 -> V_240 , 0x1A , V_24 ) ;
V_62 = ( unsigned short ) ( V_364 >> 16 ) ;
V_24 = V_62 & 0x00FF ;
V_24 = V_24 << 4 ;
V_24 |= ( ( V_125 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_240 , 0x19 , V_24 ) ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
V_24 = 0x0028 ;
F_4 ( V_3 -> V_240 , 0x1C , V_24 ) ;
V_61 = V_3 -> V_179 ;
if ( V_41 & V_129 )
V_61 = V_61 >> 1 ;
if ( F_66 ( V_3 ) )
V_61 = V_61 >> 1 ;
if ( V_3 -> V_9 & V_48 ) {
if ( V_61 > 800 )
V_61 -= 800 ;
} else if ( V_3 -> V_179 > 800 ) {
if ( V_3 -> V_179 == 1024 )
V_61 = ( V_61 * 25 / 32 ) - 1 ;
else
V_61 = ( V_61 * 20 / 32 ) - 1 ;
}
V_61 -= 1 ;
V_24 = ( V_61 & 0xFF00 ) >> 8 ;
V_24 = ( ( V_24 & 0x0003 ) << 4 ) ;
F_4 ( V_3 -> V_240 , 0x1E , V_24 ) ;
V_24 = ( V_61 & 0x00FF ) ;
F_4 ( V_3 -> V_240 , 0x1D , V_24 ) ;
if ( V_3 -> V_9 & ( V_47 | V_77 ) ) {
if ( V_3 -> V_179 > 800 )
F_20 ( V_3 -> V_240 , 0x1E , 0x08 ) ;
}
V_24 = 0x0036 ;
if ( V_3 -> V_9 & V_47 ) {
if ( ! ( V_3 -> V_10 & ( V_255
| V_252 | V_250
| V_301 ) ) ) {
V_24 |= 0x0001 ;
if ( ( V_3 -> V_9 & V_49 )
&& ( ! ( V_3 -> V_10
& V_80 ) ) )
V_24 &= ( ~ 0x0001 ) ;
}
}
F_12 ( V_3 -> V_240 , 0x1F , 0x00C0 , V_24 ) ;
V_62 = V_3 -> V_203 ;
if ( F_66 ( V_3 ) )
V_62 = V_62 >> 1 ;
V_62 = ( V_62 >> 1 ) - 2 ;
V_24 = ( ( V_62 & 0x0700 ) >> 8 ) << 3 ;
F_12 ( V_3 -> V_240 , 0x21 , 0x00C0 , V_24 ) ;
V_24 = V_62 & 0x00FF ;
F_4 ( V_3 -> V_240 , 0x22 , V_24 ) ;
}
F_69 ( V_29 , V_30 , V_60 , V_3 ) ;
}
static void F_84 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_28 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_85 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
if ( V_3 -> V_55 == V_56 ) {
if ( ! ( V_3 -> V_9 & ( V_49 | V_395
| V_279 ) ) ) {
F_84 ( V_3 ) ;
}
}
return;
}
static void F_86 ( struct V_35 * V_36 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_38 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_87 ( struct V_35 * V_36 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_38 , 0x63 , 0xBF , 0x00 ) ;
}
static unsigned char F_88 ( struct V_319 * V_320 ,
unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_160 , V_178 , V_355 , V_41 , V_124 ;
V_124 = V_42 [ V_30 ] . V_65 ;
V_160 = V_126 [ V_124 ] . V_127 ;
V_178 = V_126 [ V_124 ] . V_128 ;
V_41 = V_42 [ V_30 ] . V_43 ;
if ( ! ( V_41 & V_45 ) ) {
V_160 /= 9 ;
V_160 *= 8 ;
}
if ( ( V_29 > 0x13 ) && ( V_41 & V_129 ) )
V_160 *= 2 ;
if ( ( V_29 > 0x13 ) && ( V_41 & V_103 ) )
V_178 *= 2 ;
if ( V_160 > V_320 -> V_322 . V_396 )
return 0 ;
if ( V_178 > V_320 -> V_322 . V_397 )
return 0 ;
if ( V_160 != V_320 -> V_322 . V_396 ||
V_178 != V_320 -> V_322 . V_397 ) {
V_355 = F_70 ( V_29 , V_30 , V_3 ) ;
if ( V_355 > 2 )
return 0 ;
}
return 1 ;
}
static void F_89 ( struct V_319 * V_320 ,
int V_116 ,
unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned char V_24 , V_398 ;
unsigned short V_160 , V_178 , V_41 , V_124 ;
unsigned short V_399 , V_400 , V_401 , V_402 , V_403 ;
unsigned short V_404 , V_405 , V_406 , V_407 , V_408 ;
unsigned short V_409 ;
V_24 = ( unsigned char ) ( ( V_320 -> V_322 . V_410 &
( V_411 << 8 ) ) >> 8 ) ;
V_24 &= V_411 ;
V_398 = F_7 ( V_3 -> V_412 ) ;
F_8 ( ( V_398 & 0x3F ) | V_24 , V_3 -> V_95 ) ;
V_24 = V_320 -> V_322 . V_410 & V_411 ;
F_12 ( V_3 -> V_28 , 0x35 , ~ 0x80 , V_24 & 0x80 ) ;
F_12 ( V_3 -> V_28 , 0x30 , ~ 0x20 , ( V_24 & 0x40 ) >> 1 ) ;
if ( V_116 == V_23 )
F_22 ( V_3 ) ;
else
F_29 ( V_3 ) ;
V_124 = V_42 [ V_30 ] . V_65 ;
V_160 = V_126 [ V_124 ] . V_127 ;
V_178 = V_126 [ V_124 ] . V_128 ;
V_41 = V_42 [ V_30 ] . V_43 ;
if ( ! ( V_41 & V_45 ) )
V_160 = V_160 * 8 / 9 ;
V_399 = V_320 -> V_322 . V_399 ;
V_400 = V_160 + ( V_320 -> V_322 . V_396 - V_160 ) / 2 ;
if ( V_400 > V_399 )
V_400 -= V_399 ;
V_401 = V_400 + V_320 -> V_322 . V_413 ;
if ( V_401 > V_399 )
V_401 -= V_399 ;
V_402 = V_401 + V_320 -> V_322 . V_414 ;
if ( V_402 > V_399 )
V_402 -= V_399 ;
V_403 = V_400 + V_399 - V_320 -> V_322 . V_396 ;
V_404 = V_320 -> V_322 . V_404 ;
V_405 = V_178 + ( V_320 -> V_322 . V_397 - V_178 ) / 2 ;
if ( V_41 & V_103 )
V_405 += V_178 / 2 ;
if ( V_405 > V_404 )
V_405 -= V_404 ;
V_406 = V_405 + V_320 -> V_322 . V_415 ;
if ( V_406 > V_404 )
V_406 -= V_404 ;
V_407 = V_406 + V_320 -> V_322 . V_416 ;
if ( V_407 > V_404 )
V_407 -= V_404 ;
V_408 = V_405 + V_404 - V_320 -> V_322 . V_397 ;
V_24 = F_2 ( V_3 -> V_38 , 0x11 ) ;
F_4 ( V_3 -> V_38 , 0x11 , V_24 & 0x7f ) ;
if ( ! ( V_41 & V_45 ) )
F_20 ( V_3 -> V_28 , 0x1 , 0x1 ) ;
V_409 = ( V_399 >> 3 ) - 5 ;
F_12 ( V_3 -> V_28 , 0x0B , ~ 0x03 , ( V_409 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_38 , 0x0 , ( V_409 & 0xFF ) ) ;
V_409 = ( V_400 >> 3 ) - 1 ;
F_12 ( V_3 -> V_28 , 0x0B , ~ 0x30 , ( V_409 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_38 , 0x2 , ( V_409 & 0xFF ) ) ;
V_409 = ( V_403 >> 3 ) - 1 ;
F_12 ( V_3 -> V_28 , 0x0C , ~ 0x03 , ( V_409 & 0xC0 ) >> 6 ) ;
F_12 ( V_3 -> V_38 , 0x05 , ~ 0x80 , ( V_409 & 0x20 ) << 2 ) ;
F_12 ( V_3 -> V_38 , 0x03 , ~ 0x1F , V_409 & 0x1F ) ;
V_409 = ( V_401 >> 3 ) + 2 ;
F_12 ( V_3 -> V_28 , 0x0B , ~ 0xC0 , ( V_409 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_38 , 0x4 , ( V_409 & 0xFF ) ) ;
V_409 -- ;
F_12 ( V_3 -> V_28 , 0x2F , ~ 0x03 , ( V_409 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_28 , 0x2E , ( V_409 & 0xFF ) ) ;
V_409 = ( V_402 >> 3 ) + 2 ;
F_12 ( V_3 -> V_28 , 0x0C , ~ 0x04 , ( V_409 & 0x20 ) >> 3 ) ;
F_12 ( V_3 -> V_38 , 0x05 , ~ 0x1F , V_409 & 0x1F ) ;
V_409 -- ;
F_12 ( V_3 -> V_28 , 0x2F , ~ 0xFC , V_409 << 2 ) ;
V_409 = V_404 - 2 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x01 , ( V_409 & 0x400 ) >> 10 ) ;
F_12 ( V_3 -> V_38 , 0x07 , ~ 0x20 , ( V_409 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_38 , 0x07 , ~ 0x01 , ( V_409 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_38 , 0x06 , ( V_409 & 0xFF ) ) ;
V_409 = V_405 - 1 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x04 , ( V_409 & 0x400 ) >> 8 ) ;
F_12 ( V_3 -> V_38 , 0x09 , ~ 0x20 , ( V_409 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_38 , 0x07 , ~ 0x08 , ( V_409 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_38 , 0x15 , ( V_409 & 0xFF ) ) ;
V_409 = V_408 - 1 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x10 , ( V_409 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_38 , 0x16 , ( V_409 & 0xFF ) ) ;
V_409 = V_406 - 1 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x08 , ( V_409 & 0x400 ) >> 7 ) ;
F_12 ( V_3 -> V_38 , 0x07 , ~ 0x80 , ( V_409 & 0x200 ) >> 2 ) ;
F_12 ( V_3 -> V_38 , 0x07 , ~ 0x04 , ( V_409 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_38 , 0x10 , ( V_409 & 0xFF ) ) ;
if ( V_116 == V_23 ) {
F_12 ( V_3 -> V_28 , 0x35 , ~ 0x07 ,
( V_409 & 0x700 ) >> 8 ) ;
F_4 ( V_3 -> V_28 , 0x34 , V_409 & 0xFF ) ;
} else {
F_12 ( V_3 -> V_28 , 0x3F , ~ 0x03 ,
( V_409 & 0x600 ) >> 9 ) ;
F_4 ( V_3 -> V_28 , 0x34 , ( V_409 >> 1 ) & 0xFF ) ;
F_12 ( V_3 -> V_38 , 0x33 , ~ 0x01 , V_409 & 0x01 ) ;
}
V_409 = V_407 - 1 ;
F_12 ( V_3 -> V_28 , 0x0A , ~ 0x20 , ( V_409 & 0x10 ) << 1 ) ;
F_12 ( V_3 -> V_38 , 0x11 , ~ 0x0F , V_409 & 0x0F ) ;
if ( V_116 == V_23 )
F_12 ( V_3 -> V_28 , 0x3F , ~ 0xFC ,
( V_409 << 2 ) & 0xFC ) ;
else
F_12 ( V_3 -> V_28 , 0x3F , ~ 0xFC ,
( V_409 << 2 ) & 0x7C ) ;
for ( V_24 = 0 , V_409 = 0 ; V_24 < 3 ; V_24 ++ ) {
F_12 ( V_3 -> V_28 , 0x31 , ~ 0x30 , V_409 ) ;
F_4 ( V_3 -> V_28 ,
0x2B , V_320 -> V_322 . V_417 ) ;
F_4 ( V_3 -> V_28 ,
0x2C , V_320 -> V_322 . V_418 ) ;
V_409 += 0x10 ;
}
if ( ! ( V_41 & V_45 ) ) {
F_7 ( V_3 -> V_50 ) ;
F_8 ( 0x13 , V_3 -> V_51 ) ;
F_8 ( 0x00 , V_3 -> V_51 ) ;
F_7 ( V_3 -> V_50 ) ;
F_8 ( 0x20 , V_3 -> V_51 ) ;
F_7 ( V_3 -> V_50 ) ;
}
}
static unsigned char F_90 ( struct V_2 * V_3 )
{
unsigned short V_61 ;
V_61 = V_3 -> V_9 ;
if ( V_61 & V_278 )
return 0 ;
else if ( V_61 & ( V_279 | V_288 | V_287 ) )
return 1 ;
return 0 ;
}
static unsigned char F_91 ( struct V_2 * V_3 ,
bool V_419 )
{
unsigned short V_62 , V_217 ;
if ( V_419 )
V_62 = V_3 -> V_79 & ( V_420 | V_421 ) ;
else
V_62 = V_3 -> V_79 & ( V_422 | V_423 ) ;
V_217 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_233 , 0x2E ) ) ;
if ( V_62 & ( V_420 | V_422 ) ) {
if ( ! ( V_217 & 0x08 ) )
return 0 ;
}
if ( ! ( V_62 & ( V_421 | V_423 ) ) )
return 0 ;
if ( V_217 & 0x01 )
return 1 ;
return 0 ;
}
static void F_92 ( struct V_319 * V_320 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_217 = 0 ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
V_217 = 0x3F ;
if ( ! ( V_3 -> V_9 &
( V_279 | V_287 ) ) ) {
if ( V_3 -> V_9 & V_46 ) {
if ( V_3 -> V_9 & V_278 ) {
V_217 = 0x7F ;
if ( ! ( V_3 -> V_9 &
V_46 ) )
V_217 = 0xBF ;
if ( V_3 -> V_79 & V_423 )
V_217 &= 0xBF ;
if ( V_3 -> V_79 & V_422 )
V_217 &= 0x7F ;
}
}
}
F_13 ( V_3 -> V_240 , 0x1F , V_217 ) ;
if ( V_3 -> V_15 & ( V_17 | V_71 ) ) {
if ( ( ( V_3 -> V_9 &
( V_48 | V_46 ) ) ) ||
( F_91 ( V_3 , false ) ) ||
( F_90 ( V_3 ) ) )
F_20 ( V_3 -> V_240 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_79 & V_422 ) || ( V_3 -> V_9
& ( V_279 | V_46
| V_287 ) ) ) {
if ( V_3 -> V_79 & V_424 )
F_86 ( V_36 , V_3 ) ;
F_61 ( V_320 , V_36 , V_3 ) ;
}
if ( V_3 -> V_9 & V_46 ) {
if ( ( V_3 -> V_79 & V_422 ) || ( V_3 -> V_9
& V_46 ) )
F_13 ( V_3 -> V_233 , 0x1e , 0xdf ) ;
}
F_13 ( V_3 -> V_28 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_9 & ( V_287 | V_278 ) ) )
F_13 ( V_3 -> V_263 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_79 & V_423 ) ||
( V_3 -> V_9 &
( V_279 | V_287 ) ) ||
( ( ! ( V_3 -> V_9 & V_46 ) ) &&
( V_3 -> V_9 &
( V_69 | V_48 | V_47 ) ) ) )
F_20 ( V_3 -> V_233 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_79 & V_423 ) ||
( V_3 -> V_9 &
( V_279 | V_287 ) ) ||
( ! ( V_3 -> V_9 & V_46 ) ) ||
( V_3 -> V_9 &
( V_69 | V_48 | V_47 ) ) ) {
V_217 = F_2 ( V_3 -> V_233 , 0x00 ) ;
F_20 ( V_3 -> V_233 , 0x00 , 0x10 ) ;
F_13 ( V_3 -> V_233 , 0x1E , 0xDF ) ;
F_4 ( V_3 -> V_233 , 0x00 , V_217 ) ;
}
} else {
if ( V_3 -> V_9 & ( V_48 | V_47 ) ) {
F_20 ( V_3 -> V_233 , 0x00 , 0x80 ) ;
F_13 ( V_3 -> V_233 , 0x1E , 0xDF ) ;
F_13 ( V_3 -> V_28 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_9 & ( V_279 | V_46
| V_287 ) )
F_61 ( V_320 , V_36 , V_3 ) ;
}
}
static unsigned short F_93 ( struct V_2 * V_3 )
{
unsigned short V_62 = 0 ;
if ( V_3 -> V_10 & V_89 )
V_62 = 2 ;
if ( V_3 -> V_10 & V_301 )
V_62 = 4 ;
if ( V_3 -> V_10 & V_298 )
V_62 = 6 ;
if ( V_3 -> V_10 & V_252 )
V_62 = 8 ;
if ( V_3 -> V_10 & V_250 )
V_62 = 10 ;
if ( V_3 -> V_10 & V_80 )
V_62 ++ ;
return V_62 ;
}
static void F_94 ( unsigned short * V_62 , unsigned char * V_258 ,
unsigned char * V_259 , struct V_2 * V_3 )
{
* V_62 = 0 ;
* V_258 = 0 ;
* V_259 = 0 ;
if ( V_3 -> V_10 & V_89 )
* V_62 = 1 ;
if ( V_3 -> V_10 & V_294 )
* V_62 = 2 ;
if ( V_3 -> V_10 & V_295 )
* V_62 = 3 ;
if ( V_3 -> V_10 & V_255 ) {
* V_62 = 4 ;
if ( V_3 -> V_10 & V_294 )
* V_62 = 5 ;
}
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
if ( ( ! ( V_3 -> V_9 & V_49 ) ) || ( V_3 -> V_10
& V_80 ) ) {
* V_62 += 8 ;
* V_258 += 1 ;
}
}
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) )
( * V_259 ) ++ ;
}
static void F_95 ( struct V_2 * V_3 )
{
unsigned char V_217 , V_218 , V_316 ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
if ( V_3 -> V_9 & ( V_48 | V_46
| V_47 | V_69 ) ) {
V_316 = 0 ;
V_218 = V_425 ;
if ( V_3 -> V_9 & V_278 )
V_218 = V_218 >> 4 ;
if ( V_3 -> V_9 &
( V_48 | V_46 ) ) {
V_316 = V_426 ;
if ( ! ( V_3 -> V_9 & V_46 ) )
V_218 = V_316 ;
}
V_218 &= 0x0F ;
V_316 &= 0xF0 ;
V_217 = F_2 ( V_3 -> V_233 , 0x2D ) ;
if ( V_3 -> V_9 & ( V_69 | V_48
| V_47 ) ) {
V_217 &= 0xF0 ;
V_217 |= V_218 ;
}
if ( V_3 -> V_9 & V_46 ) {
V_217 &= 0x0F ;
V_217 |= V_316 ;
}
F_4 ( V_3 -> V_233 , 0x2D , V_217 ) ;
}
}
}
static void F_96 ( unsigned short V_125 ,
struct V_2 * V_3 )
{
unsigned short V_24 ;
V_24 = F_2 ( V_3 -> V_38 , 0x37 ) ;
if ( V_24 & V_360 ) {
F_12 ( V_3 -> V_233 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_125 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_233 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_12 ( V_3 -> V_233 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_125 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_233 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_97 ( unsigned short V_125 ,
struct V_2 * V_3 )
{
if ( V_125 & V_427 )
F_12 ( V_3 -> V_263 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_125 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_12 ( V_3 -> V_263 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_125 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_98 ( struct V_2 * V_3 )
{
unsigned short V_32 ;
V_32 = F_2 ( V_3 -> V_28 , 0x1F ) ;
if ( ! ( V_32 & 0xC0 ) ) {
for ( V_32 = 0 ; V_32 < 0xFFFF ; V_32 ++ ) {
if ( ! ( F_7 ( V_3 -> V_50 ) & 0x08 ) )
break;
}
for ( V_32 = 0 ; V_32 < 0xFFFF ; V_32 ++ ) {
if ( ( F_7 ( V_3 -> V_50 ) & 0x08 ) )
break;
}
}
}
static void F_99 ( struct V_2 * V_3 )
{
unsigned short V_104 ;
V_104 = F_40 ( V_3 ) ;
F_13 ( V_3 -> V_240 , 0x30 , 0x8F ) ;
F_98 ( V_3 ) ;
F_20 ( V_3 -> V_240 , 0x30 , 0x20 ) ;
F_98 ( V_3 ) ;
F_4 ( V_3 -> V_240 , 0x31 ,
V_3 -> V_18 [ V_104 ] . V_428 ) ;
F_4 ( V_3 -> V_240 , 0x32 ,
V_3 -> V_18 [ V_104 ] . V_429 ) ;
F_4 ( V_3 -> V_240 , 0x33 ,
V_3 -> V_18 [ V_104 ] . V_430 ) ;
F_4 ( V_3 -> V_240 , 0x34 ,
V_3 -> V_18 [ V_104 ] . V_431 ) ;
F_98 ( V_3 ) ;
F_20 ( V_3 -> V_240 , 0x30 , 0x40 ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
unsigned short V_125 ;
V_125 = V_3 -> V_18 [ F_40 ( V_3 ) ] . V_307 ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16 |
V_17 | V_71 ) ) {
if ( V_3 -> V_15 &
( V_16 | V_17 | V_71 ) ) {
F_4 ( V_3 -> V_240 , 0x24 ,
( unsigned char ) ( V_125 & 0x1F ) ) ;
}
F_12 ( V_3 -> V_240 , 0x0D ,
~ ( ( V_432 | V_433 ) >> 8 ) ,
( unsigned short ) ( ( V_125 & ( V_432
| V_433 ) ) >> 8 ) ) ;
if ( V_3 -> V_9 & V_48 )
F_97 ( V_125 , V_3 ) ;
else if ( V_3 -> V_9 & V_46 )
F_96 ( V_125 , V_3 ) ;
if ( V_3 -> V_15 & ( V_17 | V_71 ) ) {
if ( V_125 & V_434 )
F_99 ( V_3 ) ;
}
} else {
F_96 ( V_125 , V_3 ) ;
}
}
static void F_101 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_62 ;
unsigned char V_217 ;
if ( V_3 -> V_10 & ( V_252 | V_250 ) )
return;
V_62 = F_93 ( V_3 ) ;
V_62 &= 0xFE ;
V_217 = V_435 [ V_62 ] ;
V_217 = V_217 << 4 ;
F_12 ( V_3 -> V_263 , 0x0A , 0x8F , V_217 ) ;
}
static void F_102 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_62 ;
unsigned char V_217 ;
V_62 = F_93 ( V_3 ) ;
V_62 &= 0xFE ;
V_217 = V_436 [ V_62 ] ;
V_217 = V_217 << 5 ;
F_12 ( V_3 -> V_263 , 0x3A , 0x1F , V_217 ) ;
}
static void F_103 ( struct V_2 * V_3 )
{
unsigned short V_62 ;
unsigned char V_258 , V_259 ;
unsigned long V_437 ;
F_94 ( & V_62 , & V_258 , & V_259 , V_3 ) ;
V_437 = V_438 [ V_62 ] ;
F_4 ( V_3 -> V_263 , 0x31 , ( unsigned short ) ( V_437
& 0x000000FF ) ) ;
F_4 ( V_3 -> V_263 , 0x32 , ( unsigned short ) ( ( V_437
& 0x0000FF00 ) >> 8 ) ) ;
F_4 ( V_3 -> V_263 , 0x33 , ( unsigned short ) ( ( V_437
& 0x00FF0000 ) >> 16 ) ) ;
F_4 ( V_3 -> V_263 , 0x34 , ( unsigned short ) ( ( V_437
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_104 ( unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_62 , V_104 ;
unsigned char const * V_439 ;
unsigned char V_258 , V_259 , V_193 ;
F_94 ( & V_62 , & V_258 , & V_259 , V_3 ) ;
switch ( V_62 ) {
case 0x00 :
case 0x04 :
V_439 = V_440 ;
break;
case 0x01 :
V_439 = V_441 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
case 0x03 :
V_439 = V_442 ;
break;
case 0x08 :
case 0x0C :
case 0x0A :
case 0x0B :
case 0x09 :
V_439 = V_443 ;
break;
default:
return;
}
V_193 = V_42 [ V_30 ] . V_444 ;
if ( V_258 == 0 )
V_104 = V_193 * 4 ;
else
V_104 = V_193 * 7 ;
if ( ( V_258 == 0 ) && ( V_259 == 1 ) ) {
F_4 ( V_3 -> V_263 , 0x35 , 0 ) ;
F_4 ( V_3 -> V_263 , 0x36 , 0 ) ;
F_4 ( V_3 -> V_263 , 0x37 , 0 ) ;
F_4 ( V_3 -> V_263 , 0x38 , V_439 [ V_104 ++ ] ) ;
} else {
F_4 ( V_3 -> V_263 , 0x35 , V_439 [ V_104 ++ ] ) ;
F_4 ( V_3 -> V_263 , 0x36 , V_439 [ V_104 ++ ] ) ;
F_4 ( V_3 -> V_263 , 0x37 , V_439 [ V_104 ++ ] ) ;
F_4 ( V_3 -> V_263 , 0x38 , V_439 [ V_104 ++ ] ) ;
}
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
F_4 ( V_3 -> V_263 , 0x48 , V_439 [ V_104 ++ ] ) ;
F_4 ( V_3 -> V_263 , 0x49 , V_439 [ V_104 ++ ] ) ;
F_4 ( V_3 -> V_263 , 0x4A , V_439 [ V_104 ++ ] ) ;
}
}
static void F_105 ( unsigned short V_29 ,
unsigned short V_30 ,
struct V_2 * V_3 )
{
F_95 ( V_3 ) ;
if ( V_3 -> V_9 & ( V_48 | V_46 ) )
F_100 ( V_3 ) ;
if ( V_3 -> V_9 & V_47 ) {
F_103 ( V_3 ) ;
F_104 ( V_29 , V_30 , V_3 ) ;
F_101 ( V_29 , V_30 , V_3 ) ;
if ( V_3 -> V_15 & V_257 )
F_102 ( V_29 , V_30 , V_3 ) ;
}
}
static void F_106 ( unsigned short V_29 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_218 ;
short V_258 ;
unsigned char V_217 ;
V_217 = 0 ;
if ( ! ( V_3 -> V_9 & V_279 ) ) {
V_217 = F_2 ( V_3 -> V_233 , 0x00 ) ;
V_217 &= ~ 0x10 ;
V_217 |= 0x40 ;
if ( V_3 -> V_9 & ( V_69 | V_47
| V_48 ) ) {
V_217 = 0x40 ;
V_258 = V_3 -> V_55 ;
V_258 -= V_56 ;
if ( V_258 >= 0 ) {
V_217 = ( 0x008 >> V_258 ) ;
if ( V_217 == 0 )
V_217 = 1 ;
V_217 |= 0x040 ;
}
if ( V_3 -> V_9 & V_49 )
V_217 ^= 0x50 ;
}
}
F_4 ( V_3 -> V_233 , 0x00 , V_217 ) ;
V_217 = 0x08 ;
V_218 = 0xf0 ;
if ( V_3 -> V_9 & V_279 )
goto V_445;
V_217 = 0x00 ;
V_218 = 0xff ;
if ( ! ( V_3 -> V_9 & ( V_69 | V_47 |
V_48 | V_46 ) ) )
goto V_445;
if ( ( V_3 -> V_9 & V_46 ) &&
( ! ( V_3 -> V_9 & V_287 ) ) ) {
V_218 &= 0xf7 ;
V_217 |= 0x01 ;
goto V_445;
}
if ( V_3 -> V_9 & V_46 ) {
V_218 &= 0xf7 ;
V_217 |= 0x01 ;
}
if ( ! ( V_3 -> V_9 & ( V_69 | V_47 | V_48 ) ) )
goto V_445;
V_218 &= 0xf8 ;
V_217 = 0x01 ;
if ( ! ( V_3 -> V_9 & V_49 ) )
V_217 |= 0x02 ;
if ( ! ( V_3 -> V_9 & V_69 ) ) {
V_217 = V_217 ^ 0x05 ;
if ( ! ( V_3 -> V_9 & V_48 ) )
V_217 = V_217 ^ 0x01 ;
}
if ( ! ( V_3 -> V_9 & V_278 ) )
V_217 |= 0x08 ;
V_445:
F_12 ( V_3 -> V_233 , 0x2e , V_218 , V_217 ) ;
if ( V_3 -> V_9 & ( V_69 | V_47 | V_48
| V_46 ) ) {
V_217 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_55 == V_56 ) && ( ! ( V_3 -> V_9
& V_49 ) ) ) {
V_217 |= 0x010 ;
}
V_217 |= 0x080 ;
if ( V_3 -> V_9 & V_47 ) {
V_217 |= 0x020 ;
if ( V_3 -> V_9 & V_290 )
V_217 = V_217 ^ 0x20 ;
}
F_12 ( V_3 -> V_240 , 0x0D , ~ 0x0BF , V_217 ) ;
V_217 = 0 ;
if ( V_3 -> V_8 & V_309 )
V_217 |= 0x40 ;
if ( V_3 -> V_9 & V_47 ) {
if ( V_3 -> V_10 & V_141 )
V_217 |= 0x40 ;
}
if ( ( V_3 -> V_6 == V_74 )
|| ( V_3 -> V_6 == V_209 ) )
V_217 |= 0x80 ;
if ( V_3 -> V_6 == V_75 )
V_217 |= 0x80 ;
F_4 ( V_3 -> V_240 , 0x0C , V_217 ) ;
}
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
V_217 = 0 ;
V_218 = 0xfb ;
if ( V_3 -> V_9 & V_278 ) {
V_218 = 0xff ;
if ( V_3 -> V_9 & V_46 )
V_217 |= 0x04 ;
}
F_12 ( V_3 -> V_233 , 0x13 , V_218 , V_217 ) ;
V_217 = 0x00 ;
V_218 = 0xcf ;
if ( ! ( V_3 -> V_9 & V_279 ) ) {
if ( V_3 -> V_9 & V_278 )
V_217 |= 0x30 ;
}
F_12 ( V_3 -> V_233 , 0x2c , V_218 , V_217 ) ;
V_217 = 0 ;
V_218 = 0x3f ;
if ( ! ( V_3 -> V_9 & V_279 ) ) {
if ( V_3 -> V_9 & V_278 )
V_217 |= 0xc0 ;
}
F_12 ( V_3 -> V_240 , 0x21 , V_218 , V_217 ) ;
}
V_217 = 0 ;
V_218 = 0x7f ;
if ( ! ( V_3 -> V_9 & V_46 ) ) {
V_218 = 0xff ;
if ( ! ( V_3 -> V_9 & V_278 ) )
V_217 |= 0x80 ;
}
F_12 ( V_3 -> V_240 , 0x23 , V_218 , V_217 ) ;
if ( V_3 -> V_15 & ( V_17 | V_71 ) ) {
if ( V_3 -> V_8 & V_309 ) {
F_20 ( V_3 -> V_240 , 0x27 , 0x20 ) ;
F_20 ( V_3 -> V_240 , 0x34 , 0x10 ) ;
}
}
}
void F_107 ( struct V_35 * V_36 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_233 , 0x2f , 0xFF , 0x01 ) ;
}
void F_108 ( struct V_35 * V_36 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_233 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_109 ( struct V_2 * V_3 )
{
unsigned short V_272 ;
if ( V_3 -> V_68 == 1 ) {
return 1 ;
} else {
V_272 = F_2 ( V_3 -> V_240 , 0x00 ) ;
if ( ( V_272 == 1 ) || ( V_272 == 2 ) )
return 1 ;
else
return 0 ;
}
}
unsigned short F_110 ( struct V_35 * V_321 ,
unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
const T_1 V_446 [] = {
0x00 , 0x00 , 0x03 , 0x01 , 0x01 , 0x01 , 0x01 , 0x00 } ;
unsigned short V_60 , V_32 , V_104 , V_24 ;
V_104 = F_2 ( V_3 -> V_38 , 0x33 ) ;
V_104 = V_104 >> V_3 -> V_447 ;
V_104 &= 0x0F ;
if ( V_3 -> V_8 & V_76 )
V_104 = 0 ;
if ( V_104 > 0 )
V_104 -- ;
if ( V_3 -> V_79 & V_247 ) {
if ( V_3 -> V_9 & ( V_48 | V_46 ) ) {
if ( V_3 -> V_68 == 0 ) {
V_24 = V_446 [
V_3 -> V_6 & 0x07 ] ;
if ( V_104 > V_24 )
V_104 = V_24 ;
} else {
V_104 = 0 ;
}
}
}
V_60 = V_42 [ V_30 ] . V_448 ;
V_29 = V_66 [ V_60 ] . V_67 ;
if ( V_321 -> V_101 >= V_21 ) {
if ( ( V_66 [ V_60 ] . V_449 == 800 ) &&
( V_66 [ V_60 ] . V_450 == 600 ) ) {
V_104 ++ ;
}
if ( ( V_66 [ V_60 ] . V_449 == 1024 ) &&
( V_66 [ V_60 ] . V_450 == 768 ) ) {
V_104 ++ ;
}
if ( ( V_66 [ V_60 ] . V_449 == 1280 ) &&
( V_66 [ V_60 ] . V_450 == 1024 ) ) {
V_104 ++ ;
}
}
V_32 = 0 ;
do {
if ( V_66 [ V_60 + V_32 ] .
V_67 != V_29 )
break;
V_24 = V_66 [ V_60 + V_32 ] . V_93 ;
V_24 &= V_277 ;
if ( V_24 < V_3 -> V_55 )
break;
V_32 ++ ;
V_104 -- ;
} while ( V_104 != 0xFFFF );
if ( ! ( V_3 -> V_9 & V_69 ) ) {
if ( V_3 -> V_9 & V_49 ) {
V_24 = V_66 [ V_60 + V_32 - 1 ] .
V_93 ;
if ( V_24 & V_130 )
V_32 ++ ;
}
}
V_32 -- ;
if ( ( V_3 -> V_79 & V_247 ) ) {
V_24 = F_14 ( V_29 , V_30 ,
V_60 , & V_32 , V_3 ) ;
}
return V_60 + V_32 ;
}
static void F_111 ( unsigned short V_29 , unsigned short V_30 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_60 ;
V_3 -> V_79 |= V_247 ;
V_60 = F_110 ( V_36 , V_29 ,
V_30 , V_3 ) ;
F_35 ( V_29 , V_30 , V_3 ) ;
F_38 ( V_29 , V_30 , V_60 , V_3 ) ;
F_39 ( V_29 , V_30 , V_60 ,
V_36 , V_3 ) ;
F_43 ( V_29 , V_30 , V_60 , V_3 ) ;
F_47 ( V_29 , V_30 , V_60 , V_3 ) ;
}
static unsigned char F_112 ( unsigned short V_29 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_30 , V_60 ;
V_3 -> V_79 |= V_247 ;
F_53 ( V_29 , & V_30 , V_3 ) ;
V_3 -> V_447 = 4 ;
V_60 = F_110 ( V_36 , V_29 ,
V_30 , V_3 ) ;
F_64 ( V_29 , V_3 ) ;
F_65 ( V_29 , V_30 , V_3 ) ;
F_68 ( V_29 , V_30 , V_60 , V_3 ) ;
F_74 ( V_29 , V_30 , V_36 ,
V_60 , V_3 ) ;
F_75 ( V_29 , V_30 , V_36 ,
V_60 , V_3 ) ;
F_77 ( V_29 , V_30 , V_36 ,
V_60 , V_3 ) ;
F_78 ( V_29 , V_30 , V_60 ,
V_36 , V_3 ) ;
F_79 ( V_29 , V_30 , V_36 ,
V_60 , V_3 ) ;
F_81 ( V_3 ) ;
F_82 ( V_29 , V_30 , V_3 ) ;
F_83 ( V_29 , V_30 , V_60 ,
V_36 , V_3 ) ;
F_69 ( V_29 , V_30 , V_60 , V_3 ) ;
F_85 ( V_29 , V_30 , V_3 ) ;
F_63 ( V_3 ) ;
return 1 ;
}
void F_113 ( struct V_2 * V_3 )
{
unsigned char V_451 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_452 = 0 , V_453 = 0 , V_454 = 0 , V_455 = 0 ;
unsigned char V_456 , V_457 , V_458 ;
unsigned short V_24 ;
int V_32 ;
F_4 ( V_3 -> V_28 , 0x05 , 0x86 ) ;
F_4 ( V_3 -> V_38 , 0x57 , 0x4A ) ;
F_4 ( V_3 -> V_38 , 0x53 , ( F_2 (
V_3 -> V_38 , 0x53 ) | 0x02 ) ) ;
V_458 = F_2 ( V_3 -> V_28 , 0x31 ) ;
V_457 = F_2 ( V_3 -> V_38 , 0x63 ) ;
V_452 = F_2 ( V_3 -> V_28 , 0x01 ) ;
F_4 ( V_3 -> V_28 , 0x01 , ( unsigned char ) ( V_452 & 0xDF ) ) ;
F_4 ( V_3 -> V_38 , 0x63 , ( unsigned char ) ( V_457 & 0xBF ) ) ;
V_456 = F_2 ( V_3 -> V_38 , 0x17 ) ;
F_4 ( V_3 -> V_38 , 0x17 , ( unsigned char ) ( V_456 | 0x80 ) ) ;
V_453 = F_2 ( V_3 -> V_28 , 0x1F ) ;
F_4 ( V_3 -> V_28 , 0x1F , ( unsigned char ) ( V_453 | 0x04 ) ) ;
V_454 = F_2 ( V_3 -> V_28 , 0x07 ) ;
F_4 ( V_3 -> V_28 , 0x07 , ( unsigned char ) ( V_454 & 0xFB ) ) ;
V_455 = F_2 ( V_3 -> V_28 , 0x06 ) ;
F_4 ( V_3 -> V_28 , 0x06 , ( unsigned char ) ( V_455 & 0xC3 ) ) ;
F_4 ( V_3 -> V_38 , 0x11 , 0x00 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
F_4 ( V_3 -> V_38 , ( unsigned short ) V_32 , V_451 [ V_32 ] ) ;
for ( V_32 = 8 ; V_32 < 11 ; V_32 ++ )
F_4 ( V_3 -> V_38 , ( unsigned short ) ( V_32 + 8 ) ,
V_451 [ V_32 ] ) ;
for ( V_32 = 11 ; V_32 < 13 ; V_32 ++ )
F_4 ( V_3 -> V_38 , ( unsigned short ) ( V_32 + 4 ) ,
V_451 [ V_32 ] ) ;
for ( V_32 = 13 ; V_32 < 16 ; V_32 ++ )
F_4 ( V_3 -> V_28 , ( unsigned short ) ( V_32 - 3 ) ,
V_451 [ V_32 ] ) ;
F_4 ( V_3 -> V_28 , 0x0E , ( unsigned char ) ( V_451 [ 16 ]
& 0xE0 ) ) ;
F_4 ( V_3 -> V_28 , 0x31 , 0x00 ) ;
F_4 ( V_3 -> V_28 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_28 , 0x2C , 0xE1 ) ;
F_8 ( 0x00 , V_3 -> V_177 ) ;
for ( V_32 = 0 ; V_32 < 256 * 3 ; V_32 ++ ) {
F_8 ( 0x0F , ( V_3 -> V_177 + 1 ) ) ;
}
F_60 ( 1 ) ;
F_62 ( V_3 ) ;
V_24 = F_7 ( V_3 -> V_95 ) ;
if ( V_24 & 0x10 )
F_12 ( V_3 -> V_38 , 0x32 , 0xDF , 0x20 ) ;
else
F_12 ( V_3 -> V_38 , 0x32 , 0xDF , 0x00 ) ;
F_8 ( 0x00 , V_3 -> V_177 ) ;
for ( V_32 = 0 ; V_32 < 256 * 3 ; V_32 ++ ) {
F_8 ( 0 , ( V_3 -> V_177 + 1 ) ) ;
}
F_4 ( V_3 -> V_28 , 0x01 , V_452 ) ;
F_4 ( V_3 -> V_38 , 0x63 , V_457 ) ;
F_4 ( V_3 -> V_28 , 0x31 , V_458 ) ;
F_4 ( V_3 -> V_38 , 0x53 , ( F_2 (
V_3 -> V_38 , 0x53 ) & 0xFD ) ) ;
F_4 ( V_3 -> V_28 , 0x1F , ( unsigned char ) V_453 ) ;
}
static void F_114 ( struct V_319 * V_320 ,
struct V_35 * V_36 ,
struct V_2 * V_3 )
{
unsigned short V_217 ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
if ( ! ( V_3 -> V_79 & V_422 ) ) {
if ( ( V_3 -> V_79 & V_420 ) ||
( V_3 -> V_9 & V_278 ) ) {
F_4 ( V_3 -> V_233 , 0x1E , 0x20 ) ;
}
}
if ( ! ( V_3 -> V_79 & V_423 ) ) {
if ( ( V_3 -> V_79 & V_421 ) || ( V_3 -> V_9
& ( V_48 | V_47
| V_69 ) ) ) {
V_217 = F_2 ( V_3 -> V_28 , 0x32 ) ;
V_217 &= 0xDF ;
if ( V_3 -> V_9 & V_49 ) {
if ( ! ( V_3 -> V_9 &
V_69 ) )
V_217 |= 0x20 ;
}
F_4 ( V_3 -> V_28 , 0x32 , V_217 ) ;
F_20 ( V_3 -> V_28 , 0x1E , 0x20 ) ;
V_217 = F_2 ( V_3 -> V_233 ,
0x2E ) ;
if ( ! ( V_217 & 0x80 ) )
F_20 ( V_3 -> V_233 ,
0x2E , 0x80 ) ;
F_13 ( V_3 -> V_233 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_79 & ( V_420 | V_421 ) )
|| ( ! ( V_3 -> V_9 & V_279 ) ) ) {
F_12 ( V_3 -> V_263 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_15 & ( V_17 | V_71 ) ) {
if ( ! F_91 ( V_3 , false ) ) {
if ( F_91 ( V_3 , true ) ||
( V_3 -> V_9 &
( V_48 | V_46 ) ) )
F_13 (
V_3 -> V_240 ,
0x2A ,
0x7F ) ;
}
F_13 ( V_3 -> V_240 , 0x30 , 0x7F ) ;
}
}
V_217 = 0x00 ;
if ( ! ( V_3 -> V_9 & V_279 ) ) {
V_217 = 0xc0 ;
if ( ! ( V_3 -> V_9 & V_287 ) &&
( V_3 -> V_9 & V_46 ) &&
( V_3 -> V_9 & V_278 ) ) {
V_217 = V_217 & 0x40 ;
if ( V_3 -> V_9 & V_46 )
V_217 = V_217 ^ 0xC0 ;
if ( V_3 -> V_79 & V_423 )
V_217 &= 0xBF ;
if ( V_3 -> V_79 & V_422 )
V_217 &= 0x7F ;
if ( V_3 -> V_79 & V_421 )
V_217 |= 0x40 ;
if ( V_3 -> V_79 & V_420 )
V_217 |= 0x80 ;
}
}
F_20 ( V_3 -> V_240 , 0x1F , V_217 ) ;
if ( ! ( V_3 -> V_79 & V_422 ) ) {
if ( ! ( V_3 -> V_79 & V_424 ) ) {
F_87 ( V_36 ,
V_3 ) ;
F_59 ( V_320 , V_36 ,
V_3 ) ;
}
}
}
else {
if ( V_3 -> V_9 & ( V_47 | V_48
| V_46 ) )
F_20 ( V_3 -> V_233 , 0x1E , 0x20 ) ;
V_217 = F_2 ( V_3 -> V_233 , 0x2E ) ;
if ( ! ( V_217 & 0x80 ) )
F_20 ( V_3 -> V_233 , 0x2E , 0x80 ) ;
F_13 ( V_3 -> V_233 , 0x00 , 0x7F ) ;
F_59 ( V_320 , V_36 , V_3 ) ;
}
}
static void F_115 ( struct V_319 * V_320 ,
struct V_35 * V_36 ,
unsigned short V_29 , unsigned short V_30 ,
struct V_2 * V_3 )
{
unsigned short V_60 , V_24 ;
F_3 ( V_29 , V_30 , V_3 ) ;
F_8 ( V_33 . V_459 , V_3 -> V_95 ) ;
F_5 ( V_36 , V_3 ) ;
F_6 ( V_29 , V_30 , V_3 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
if ( V_36 -> V_101 == V_23 ) {
if ( V_3 -> V_68 == 0 )
F_11 ( V_3 ) ;
}
V_24 = ~ V_247 ;
V_3 -> V_79 &= V_24 ;
V_3 -> V_447 = 0 ;
if ( V_3 -> V_15 & ( V_86 | V_87 | V_16
| V_17 | V_71 ) ) {
if ( V_3 -> V_9 & ( V_287 | V_46
| V_49 ) ) {
V_3 -> V_79 |= V_247 ;
}
}
V_60 = F_110 ( V_36 , V_29 ,
V_30 , V_3 ) ;
if ( V_60 != 0xFFFF ) {
F_15 ( V_60 , V_3 ) ;
F_18 ( V_29 , V_30 , V_60 ,
V_3 , V_36 ) ;
F_25 ( V_36 , V_29 , V_30 ,
V_60 , V_3 ) ;
F_26 ( V_29 , V_30 , V_60 ,
V_36 , V_3 ) ;
F_28 ( V_29 , V_30 , V_36 ,
V_60 , V_3 ) ;
}
if ( V_36 -> V_101 >= V_156 ) {
V_24 = F_2 ( V_3 -> V_38 , 0x38 ) ;
if ( V_24 & 0xA0 ) {
if ( V_36 -> V_101 == V_23 )
F_21 ( V_29 , V_30 ,
V_60 , V_3 ) ;
else
F_19 ( V_29 , V_30 ,
V_60 , V_3 ) ;
F_24 ( V_29 , V_3 ,
V_60 ) ;
F_23 ( V_36 -> V_101 ,
V_3 , V_60 , V_29 ) ;
if ( V_3 -> V_68 == 1 )
F_89 ( V_320 ,
V_36 -> V_101 ,
V_29 , V_30 , V_3 ) ;
}
}
V_3 -> V_79 &= ( ~ V_247 ) ;
F_30 ( V_29 , V_36 , V_3 ) ;
F_32 ( V_36 , V_29 , V_30 ,
V_60 , V_3 ) ;
F_34 ( V_29 , V_30 , V_3 ) ;
}
unsigned char F_116 ( struct V_319 * V_320 ,
struct V_35 * V_36 ,
unsigned short V_29 )
{
unsigned short V_30 ;
struct V_2 V_460 ;
struct V_2 * V_3 = & V_460 ;
V_3 -> V_68 = 0 ;
if ( V_36 -> V_101 >= V_21 ) {
V_3 -> V_282 = 0 ;
V_3 -> V_284 = 0 ;
V_3 -> V_289 = 0 ;
V_3 -> V_15 = 0 ;
} else {
V_3 -> V_282 = 1 ;
V_3 -> V_284 = 1 ;
V_3 -> V_289 = 1 ;
}
F_117 ( V_3 , V_320 -> V_461 ) ;
if ( V_36 -> V_101 == V_156 ) {
if ( ( F_2 ( V_3 -> V_38 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_68 = 1 ;
}
if ( V_36 -> V_101 == V_23 ) {
if ( ( F_2 ( V_3 -> V_38 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_2 ( V_3 -> V_38 , 0x30 ) & 0x20 )
V_3 -> V_68 = 1 ;
}
}
if ( V_36 -> V_101 < V_21 )
F_49 ( V_3 ) ;
F_1 ( V_36 -> V_101 , V_3 ) ;
if ( V_29 & 0x80 )
V_29 = V_29 & 0x7F ;
F_4 ( V_3 -> V_28 , 0x05 , 0x86 ) ;
if ( V_36 -> V_101 < V_21 )
F_107 ( V_36 , V_3 ) ;
F_53 ( V_29 , & V_30 , V_3 ) ;
if ( V_36 -> V_101 < V_21 ) {
F_50 ( V_29 , V_30 , V_36 , V_3 ) ;
F_51 ( V_29 , V_30 , V_3 ) ;
F_52 ( V_29 , V_30 , V_3 ) ;
F_92 ( V_320 , V_36 , V_3 ) ;
if ( V_3 -> V_9 & ( V_287 | V_46 ) ||
( ! ( V_3 -> V_9 & V_288 ) ) ) {
F_115 ( V_320 , V_36 , V_29 ,
V_30 , V_3 ) ;
if ( V_3 -> V_9 & V_46 ) {
F_111 ( V_29 , V_30 ,
V_36 , V_3 ) ;
}
}
if ( V_3 -> V_9 & ( V_287 | V_288 ) ) {
switch ( V_36 -> V_462 ) {
case V_463 :
case V_464 :
F_112 ( V_29 , V_36 ,
V_3 ) ;
break;
default:
break;
}
}
F_106 ( V_29 , V_36 , V_3 ) ;
F_105 ( V_29 , V_30 , V_3 ) ;
F_114 ( V_320 , V_36 , V_3 ) ;
}
else {
if ( V_3 -> V_68 == 1 )
if ( ! F_88 ( V_320 , V_29 ,
V_30 ,
V_3 ) )
return 0 ;
V_3 -> V_55 = V_42 [ V_30 ] .
V_43 & V_277 ;
V_3 -> V_79 = 0 ;
V_3 -> V_9 = V_279 ;
F_61 ( V_320 , V_36 , V_3 ) ;
F_115 ( V_320 , V_36 , V_29 ,
V_30 , V_3 ) ;
F_59 ( V_320 , V_36 , V_3 ) ;
}
F_48 ( V_36 , V_3 ) ;
if ( V_36 -> V_101 < V_21 )
F_108 ( V_36 , V_3 ) ;
return 1 ;
}
