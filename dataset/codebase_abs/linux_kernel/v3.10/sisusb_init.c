static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
}
static void
F_2 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned short V_18 , unsigned short V_19 )
{
F_3 ( V_2 -> V_20 , V_17 , V_18 , V_19 ) ;
}
static void
F_4 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned short V_19 )
{
F_5 ( V_2 -> V_20 , V_17 , V_19 ) ;
}
static unsigned char
F_6 ( struct V_1 * V_2 , unsigned long V_17 , unsigned short V_18 )
{
T_1 V_19 ;
F_7 ( V_2 -> V_20 , V_17 , V_18 , & V_19 ) ;
return V_19 ;
}
static unsigned char
F_8 ( struct V_1 * V_2 , unsigned long V_17 )
{
T_1 V_19 ;
F_9 ( V_2 -> V_20 , V_17 , & V_19 ) ;
return V_19 ;
}
static void
F_10 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned short V_18 , unsigned short V_21 ,
unsigned short V_22 )
{
F_11 ( V_2 -> V_20 , V_17 , V_18 , V_21 , V_22 ) ;
}
static void
F_12 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned short V_18 , unsigned short V_21 )
{
F_13 ( V_2 -> V_20 , V_17 , V_18 , V_21 ) ;
}
static void
F_14 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned short V_18 , unsigned short V_22 )
{
F_15 ( V_2 -> V_20 , V_17 , V_18 , V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_2 -> V_23 , 0x01 , 0xDF ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned long V_24 )
{
V_2 -> V_23 = V_24 + 0x14 ;
V_2 -> V_25 = V_24 + 0x24 ;
V_2 -> V_26 = V_24 + 0x10 ;
V_2 -> V_27 = V_24 + 0x1e ;
V_2 -> V_28 = V_24 + 0x12 ;
V_2 -> V_29 = V_24 + 0x1a ;
V_2 -> V_30 = V_24 + 0x16 ;
V_2 -> V_31 = V_24 + 0x17 ;
V_2 -> V_32 = V_24 + 0x18 ;
V_2 -> V_33 = V_24 + 0x19 ;
V_2 -> V_34 = V_24 + 0x1b ;
V_2 -> V_35 = V_24 + 0x1c ;
V_2 -> V_36 = V_24 + 0x1d ;
V_2 -> V_37 = V_24 + 0x2a ;
V_2 -> V_38 = V_24 + V_39 ;
}
static void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_40 = 0x63 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_2 -> V_23 , 0x20 , 0xa1 ) ;
F_14 ( V_2 , V_2 -> V_23 , 0x1E , 0xDA ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned short V_41 )
{
unsigned short V_42 ;
V_41 &= 0x00ff ;
V_42 = F_8 ( V_2 , V_2 -> V_34 ) & 0xf0 ;
V_42 |= ( V_41 >> 4 ) ;
F_4 ( V_2 , V_2 -> V_34 , V_42 ) ;
V_42 = F_8 ( V_2 , V_2 -> V_36 ) & 0xf0 ;
V_42 |= ( V_41 & 0x0f ) ;
F_4 ( V_2 , V_2 -> V_36 , V_42 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned short V_41 )
{
unsigned short V_42 ;
V_41 &= 0x00ff ;
V_42 = F_8 ( V_2 , V_2 -> V_34 ) & 0x0f ;
V_42 |= ( V_41 & 0xf0 ) ;
F_4 ( V_2 , V_2 -> V_34 , V_42 ) ;
V_42 = F_8 ( V_2 , V_2 -> V_36 ) & 0x0f ;
V_42 |= ( V_41 << 4 ) ;
F_4 ( V_2 , V_2 -> V_36 , V_42 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned short V_41 )
{
F_20 ( V_2 , V_41 ) ;
F_21 ( V_2 , V_41 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 , 0 ) ;
}
static void
F_24 ( struct V_1 * V_2 , unsigned short V_41 )
{
unsigned short V_42 = V_41 >> 8 ;
V_42 &= 0x07 ;
V_42 |= ( V_42 << 4 ) ;
F_2 ( V_2 , V_2 -> V_23 , 0x1d , V_42 ) ;
F_22 ( V_2 , V_41 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 , 0 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_25 ( V_2 ) ;
}
static int
F_27 ( struct V_1 * V_2 , unsigned short * V_43 ,
unsigned short * V_44 )
{
if ( ( * V_43 ) <= 0x13 ) {
if ( ( * V_43 ) != 0x03 )
return 0 ;
( * V_44 ) = 0 ;
} else {
for ( * V_44 = 0 ; ; ( * V_44 ) ++ ) {
if ( V_2 -> V_9 [ * V_44 ] . V_45 ==
( * V_43 ) )
break;
if ( V_2 -> V_9 [ * V_44 ] . V_45 ==
0xFF )
return 0 ;
}
}
return 1 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_2 -> V_25 , V_2 -> V_40 , 0xbf ) ;
}
static unsigned short
F_29 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_44 )
{
static const unsigned short V_46 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
unsigned short V_47 ;
short V_18 ;
if ( V_43 <= 0x13 ) {
V_47 = V_2 -> V_7 [ V_44 ] . V_48 ;
} else {
V_47 = V_2 -> V_9 [ V_44 ] . V_49 ;
}
V_18 = ( V_47 & V_50 ) - V_51 ;
if ( V_18 < 0 )
V_18 = 0 ;
return V_46 [ V_18 ] ;
}
static unsigned short
F_30 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_44 , unsigned short V_52 )
{
unsigned short V_53 , V_42 , V_54 , V_55 ;
V_55 = V_2 -> V_11 [ V_52 ] . V_56 ;
V_53 = V_2 -> V_11 [ V_52 ] . V_57 ;
V_54 = F_29 ( V_2 , V_43 , V_44 ) ;
V_42 = V_53 / 16 ;
if ( V_55 & V_58 )
V_42 <<= 1 ;
V_42 *= V_54 ;
if ( V_53 % 16 )
V_42 += ( V_54 >> 1 ) ;
return V_42 ;
}
static void
F_31 ( struct V_1 * V_2 , unsigned short V_59 )
{
unsigned char V_60 ;
int V_61 ;
F_2 ( V_2 , V_2 -> V_23 , 0x00 , 0x03 ) ;
V_60 = V_2 -> V_5 [ V_59 ] . V_62 [ 0 ] | 0x20 ;
F_2 ( V_2 , V_2 -> V_23 , 0x01 , V_60 ) ;
for ( V_61 = 2 ; V_61 <= 4 ; V_61 ++ ) {
V_60 = V_2 -> V_5 [ V_59 ] . V_62 [ V_61 - 1 ] ;
F_2 ( V_2 , V_2 -> V_23 , V_61 , V_60 ) ;
}
}
static void
F_32 ( struct V_1 * V_2 , unsigned short V_59 )
{
unsigned char V_63 = V_2 -> V_5 [ V_59 ] . V_64 ;
F_4 ( V_2 , V_2 -> V_28 , V_63 ) ;
}
static void
F_33 ( struct V_1 * V_2 , unsigned short V_59 )
{
unsigned char V_65 ;
unsigned short V_61 ;
F_12 ( V_2 , V_2 -> V_25 , 0x11 , 0x7f ) ;
for ( V_61 = 0 ; V_61 <= 0x18 ; V_61 ++ ) {
V_65 = V_2 -> V_5 [ V_59 ] . V_66 [ V_61 ] ;
F_2 ( V_2 , V_2 -> V_25 , V_61 , V_65 ) ;
}
}
static void
F_34 ( struct V_1 * V_2 , unsigned short V_59 )
{
unsigned char V_67 ;
unsigned short V_61 ;
for ( V_61 = 0 ; V_61 <= 0x13 ; V_61 ++ ) {
V_67 = V_2 -> V_5 [ V_59 ] . V_68 [ V_61 ] ;
F_8 ( V_2 , V_2 -> V_37 ) ;
F_4 ( V_2 , V_2 -> V_26 , V_61 ) ;
F_4 ( V_2 , V_2 -> V_26 , V_67 ) ;
}
F_8 ( V_2 , V_2 -> V_37 ) ;
F_4 ( V_2 , V_2 -> V_26 , 0x14 ) ;
F_4 ( V_2 , V_2 -> V_26 , 0x00 ) ;
F_8 ( V_2 , V_2 -> V_37 ) ;
F_4 ( V_2 , V_2 -> V_26 , 0x20 ) ;
F_8 ( V_2 , V_2 -> V_37 ) ;
}
static void
F_35 ( struct V_1 * V_2 , unsigned short V_59 )
{
unsigned char V_69 ;
unsigned short V_61 ;
for ( V_61 = 0 ; V_61 <= 0x08 ; V_61 ++ ) {
V_69 = V_2 -> V_5 [ V_59 ] . V_70 [ V_61 ] ;
F_2 ( V_2 , V_2 -> V_27 , V_61 , V_69 ) ;
}
if ( V_2 -> V_71 > V_72 ) {
F_12 ( V_2 , V_2 -> V_27 , 0x05 , 0xBF ) ;
}
}
static void F_36 ( struct V_1 * V_2 , unsigned short V_43 )
{
int V_61 ;
for ( V_61 = 0x0A ; V_61 <= 0x0E ; V_61 ++ ) {
F_2 ( V_2 , V_2 -> V_23 , V_61 , 0x00 ) ;
}
F_12 ( V_2 , V_2 -> V_23 , 0x37 , 0xFE ) ;
}
static unsigned short
F_37 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_44 )
{
unsigned short V_52 , V_61 , V_18 , V_42 ;
if ( V_43 <= 0x13 )
return 0xFFFF ;
V_18 = F_6 ( V_2 , V_2 -> V_25 , 0x33 ) & 0x0F ;
if ( V_18 > 0 )
V_18 -- ;
V_52 = V_2 -> V_9 [ V_44 ] . V_73 ;
V_43 = V_2 -> V_11 [ V_52 ] . V_74 ;
V_61 = 0 ;
do {
if ( V_2 -> V_11 [ V_52 + V_61 ] . V_74 != V_43 )
break;
V_42 =
V_2 -> V_11 [ V_52 + V_61 ] . V_56 & V_50 ;
if ( V_42 < V_2 -> V_71 )
break;
V_61 ++ ;
V_18 -- ;
} while ( V_18 != 0xFFFF );
V_61 -- ;
return ( V_52 + V_61 ) ;
}
static void F_38 ( struct V_1 * V_2 , unsigned short V_52 )
{
unsigned short V_75 = V_2 -> V_11 [ V_52 ] . V_56 >> 8 ;
V_75 &= 0xC0 ;
V_75 |= 0x2f ;
F_4 ( V_2 , V_2 -> V_28 , V_75 ) ;
}
static void
F_39 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_44 , unsigned short V_52 )
{
unsigned char V_18 ;
unsigned short V_42 , V_61 , V_76 , V_47 ;
F_12 ( V_2 , V_2 -> V_25 , 0x11 , 0x7f ) ;
V_47 = V_2 -> V_9 [ V_44 ] . V_49 ;
V_18 = V_2 -> V_11 [ V_52 ] . V_77 ;
for ( V_61 = 0 , V_76 = 0 ; V_61 <= 7 ; V_61 ++ , V_76 ++ ) {
F_2 ( V_2 , V_2 -> V_25 , V_76 ,
V_2 -> V_13 [ V_18 ] . V_78 [ V_61 ] ) ;
}
for ( V_76 = 0x10 ; V_61 <= 10 ; V_61 ++ , V_76 ++ ) {
F_2 ( V_2 , V_2 -> V_25 , V_76 ,
V_2 -> V_13 [ V_18 ] . V_78 [ V_61 ] ) ;
}
for ( V_76 = 0x15 ; V_61 <= 12 ; V_61 ++ , V_76 ++ ) {
F_2 ( V_2 , V_2 -> V_25 , V_76 ,
V_2 -> V_13 [ V_18 ] . V_78 [ V_61 ] ) ;
}
for ( V_76 = 0x0A ; V_61 <= 15 ; V_61 ++ , V_76 ++ ) {
F_2 ( V_2 , V_2 -> V_23 , V_76 ,
V_2 -> V_13 [ V_18 ] . V_78 [ V_61 ] ) ;
}
V_42 = V_2 -> V_13 [ V_18 ] . V_78 [ 16 ] & 0xE0 ;
F_2 ( V_2 , V_2 -> V_23 , 0x0E , V_42 ) ;
V_42 = ( ( V_2 -> V_13 [ V_18 ] . V_78 [ 16 ] ) & 0x01 ) << 5 ;
if ( V_47 & V_79 )
V_42 |= 0x80 ;
F_10 ( V_2 , V_2 -> V_25 , 0x09 , 0x5F , V_42 ) ;
if ( V_2 -> V_71 > V_72 )
F_2 ( V_2 , V_2 -> V_25 , 0x14 , 0x4F ) ;
}
static void
F_40 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_44 , unsigned short V_52 )
{
unsigned short V_80 = F_30 ( V_2 , V_43 , V_44 , V_52 ) ;
unsigned short V_55 = V_2 -> V_11 [ V_52 ] . V_56 ;
unsigned short V_42 ;
V_42 = ( V_80 >> 8 ) & 0x0f ;
F_10 ( V_2 , V_2 -> V_23 , 0x0E , 0xF0 , V_42 ) ;
F_2 ( V_2 , V_2 -> V_25 , 0x13 , ( V_80 & 0xFF ) ) ;
if ( V_55 & V_58 )
V_80 >>= 1 ;
V_80 <<= 5 ;
V_42 = ( V_80 >> 8 ) & 0xff ;
if ( V_80 & 0xff )
V_42 ++ ;
V_42 ++ ;
F_2 ( V_2 , V_2 -> V_23 , 0x10 , V_42 ) ;
}
static void
F_41 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_52 )
{
unsigned short V_18 = V_2 -> V_11 [ V_52 ] . V_81 ;
unsigned short V_82 = V_2 -> V_15 [ V_18 ] . V_83 ;
unsigned short V_84 = V_2 -> V_15 [ V_18 ] . V_85 ;
F_12 ( V_2 , V_2 -> V_23 , 0x31 , 0xCF ) ;
F_2 ( V_2 , V_2 -> V_23 , 0x2B , V_82 ) ;
F_2 ( V_2 , V_2 -> V_23 , 0x2C , V_84 ) ;
F_2 ( V_2 , V_2 -> V_23 , 0x2D , 0x01 ) ;
}
static void
F_42 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_86 )
{
unsigned short V_47 = V_2 -> V_9 [ V_86 ] . V_49 ;
F_12 ( V_2 , V_2 -> V_23 , 0x3D , 0xFE ) ;
F_2 ( V_2 , V_2 -> V_23 , 0x08 , 0xAE ) ;
F_12 ( V_2 , V_2 -> V_23 , 0x09 , 0xF0 ) ;
if ( V_43 <= 0x13 )
return;
if ( ( ! ( V_47 & V_79 ) ) || ( ! ( V_47 & V_87 ) ) ) {
F_2 ( V_2 , V_2 -> V_23 , 0x08 , 0x34 ) ;
F_14 ( V_2 , V_2 -> V_23 , 0x3D , 0x01 ) ;
}
}
static void
F_43 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_52 )
{
unsigned short V_19 = 0 , V_88 = 0 , V_18 = 0 ;
if ( V_43 > 0x13 ) {
V_18 = V_2 -> V_11 [ V_52 ] . V_81 ;
V_88 = V_2 -> V_15 [ V_18 ] . CLOCK ;
}
if ( V_88 >= 166 )
V_19 |= 0x0c ;
F_10 ( V_2 , V_2 -> V_23 , 0x32 , 0xf3 , V_19 ) ;
if ( V_88 >= 166 )
F_12 ( V_2 , V_2 -> V_23 , 0x1f , 0xe7 ) ;
V_19 = 0x03 ;
if ( V_88 >= 260 )
V_19 = 0x00 ;
else if ( V_88 >= 160 )
V_19 = 0x01 ;
else if ( V_88 >= 135 )
V_19 = 0x02 ;
F_10 ( V_2 , V_2 -> V_23 , 0x07 , 0xF8 , V_19 ) ;
}
static void
F_44 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_44 , unsigned short V_52 )
{
unsigned short V_19 , V_55 = 0 , V_47 ;
if ( V_43 <= 0x13 )
V_47 = V_2 -> V_7 [ V_44 ] . V_48 ;
else {
V_47 = V_2 -> V_9 [ V_44 ] . V_49 ;
V_55 = V_2 -> V_11 [ V_52 ] . V_56 ;
}
F_12 ( V_2 , V_2 -> V_23 , 0x1F , 0x3F ) ;
V_19 = 0 ;
if ( V_43 > 0x13 ) {
if ( V_2 -> V_71 > V_51 ) {
V_19 |= 0x02 ;
V_19 |= ( ( V_2 -> V_71 - V_72 ) << 2 ) ;
}
if ( V_55 & V_58 )
V_19 |= 0x20 ;
}
F_10 ( V_2 , V_2 -> V_23 , 0x06 , 0xC0 , V_19 ) ;
V_19 = 0 ;
if ( V_55 & V_58 ) {
unsigned short V_89 =
( F_6 ( V_2 , V_2 -> V_25 , 0x04 ) |
( ( F_6 ( V_2 , V_2 -> V_23 , 0x0b ) & 0xc0 ) << 2 ) )
- 3 ;
unsigned short V_90 =
( F_6 ( V_2 , V_2 -> V_25 , 0x00 ) |
( ( F_6 ( V_2 , V_2 -> V_23 , 0x0b ) & 0x03 ) << 8 ) )
+ 5 ;
V_19 = V_89 - ( V_90 >> 1 ) + 3 ;
}
F_2 ( V_2 , V_2 -> V_25 , 0x19 , ( V_19 & 0xFF ) ) ;
F_10 ( V_2 , V_2 -> V_25 , 0x1a , 0xFC , ( V_19 >> 8 ) ) ;
if ( V_47 & V_87 )
F_14 ( V_2 , V_2 -> V_23 , 0x01 , 0x08 ) ;
V_19 = 0 ;
if ( V_47 & V_91 )
V_19 = 0x08 ;
F_10 ( V_2 , V_2 -> V_23 , 0x0F , 0xB7 , V_19 ) ;
if ( ( V_2 -> V_71 == V_51 ) && ( V_43 > 0x13 ) )
F_14 ( V_2 , V_2 -> V_23 , 0x0F , 0x40 ) ;
F_12 ( V_2 , V_2 -> V_23 , 0x31 , 0xfb ) ;
V_19 = 0x60 ;
if ( V_2 -> V_71 != V_92 ) {
V_19 ^= 0x60 ;
if ( V_2 -> V_71 != V_51 )
V_19 ^= 0xA0 ;
}
F_10 ( V_2 , V_2 -> V_23 , 0x21 , 0x1F , V_19 ) ;
F_43 ( V_2 , V_43 , V_52 ) ;
if ( F_6 ( V_2 , V_2 -> V_25 , 0x31 ) & 0x40 )
F_2 ( V_2 , V_2 -> V_25 , 0x52 , 0x2c ) ;
else
F_2 ( V_2 , V_2 -> V_25 , 0x52 , 0x6c ) ;
}
static void
F_45 ( struct V_1 * V_2 , unsigned long V_93 ,
unsigned short V_94 , unsigned short V_95 , unsigned short V_96 ,
unsigned short V_97 , unsigned short V_98 )
{
unsigned short V_99 , V_100 , V_101 ;
switch ( V_95 ) {
case 0 :
V_99 = V_98 ;
V_100 = V_96 ;
V_101 = V_97 ;
break;
case 1 :
V_99 = V_96 ;
V_100 = V_97 ;
V_101 = V_98 ;
break;
default:
V_99 = V_97 ;
V_100 = V_98 ;
V_101 = V_96 ;
}
F_4 ( V_2 , V_93 , ( V_99 << V_94 ) ) ;
F_4 ( V_2 , V_93 , ( V_100 << V_94 ) ) ;
F_4 ( V_2 , V_93 , ( V_101 << V_94 ) ) ;
}
static void
F_46 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_86 )
{
unsigned short V_19 , V_102 , time , V_61 , V_76 , V_103 , V_104 , V_105 , V_106 ;
unsigned short V_107 , V_108 , V_109 , V_110 ;
unsigned long V_111 , V_93 ;
const unsigned char * V_112 = NULL ;
if ( V_43 < 0x13 )
V_19 = V_2 -> V_7 [ V_86 ] . V_48 ;
else
V_19 = V_2 -> V_9 [ V_86 ] . V_49 ;
V_19 &= V_113 ;
V_76 = time = 64 ;
if ( V_19 == 0x00 )
V_112 = V_114 ;
else if ( V_19 == 0x08 )
V_112 = V_115 ;
else if ( V_19 == 0x10 )
V_112 = V_116 ;
else {
V_76 = 16 ;
time = 256 ;
V_112 = V_117 ;
}
V_111 = V_2 -> V_32 ;
V_93 = V_2 -> V_33 ;
V_110 = 0 ;
F_4 ( V_2 , V_2 -> V_30 , 0xFF ) ;
F_4 ( V_2 , V_111 , 0x00 ) ;
for ( V_61 = 0 ; V_61 < V_76 ; V_61 ++ ) {
V_19 = V_112 [ V_61 ] ;
for ( V_103 = 0 ; V_103 < 3 ; V_103 ++ ) {
V_102 = 0 ;
if ( V_19 & 0x01 )
V_102 += 0x2A ;
if ( V_19 & 0x02 )
V_102 += 0x15 ;
F_4 ( V_2 , V_93 , ( V_102 << V_110 ) ) ;
V_19 >>= 2 ;
}
}
if ( time == 256 ) {
for ( V_61 = 16 ; V_61 < 32 ; V_61 ++ ) {
V_19 = V_112 [ V_61 ] << V_110 ;
for ( V_103 = 0 ; V_103 < 3 ; V_103 ++ )
F_4 ( V_2 , V_93 , V_19 ) ;
}
V_107 = 32 ;
for ( V_104 = 0 ; V_104 < 9 ; V_104 ++ ) {
V_108 = V_107 ;
V_109 = V_107 + 4 ;
for ( V_105 = 0 ; V_105 < 3 ; V_105 ++ ) {
for ( V_106 = 0 ; V_106 < 5 ; V_106 ++ ) {
F_45 ( V_2 , V_93 , V_110 , V_105 ,
V_112 [ V_108 ] , V_112 [ V_109 ] ,
V_112 [ V_107 ] ) ;
V_107 ++ ;
}
V_107 -= 2 ;
for ( V_106 = 0 ; V_106 < 3 ; V_106 ++ ) {
F_45 ( V_2 , V_93 , V_110 , V_105 ,
V_112 [ V_108 ] , V_112 [ V_107 ] ,
V_112 [ V_109 ] ) ;
V_107 -- ;
}
}
V_107 += 5 ;
}
}
}
static void
F_47 ( struct V_1 * V_2 , unsigned short V_43 ,
unsigned short V_44 )
{
unsigned short V_59 , V_52 ;
V_2 -> V_118 = V_43 ;
if ( V_43 <= 0x13 )
V_59 = 0 ;
else
V_59 = 1 ;
F_26 ( V_2 ) ;
F_31 ( V_2 , V_59 ) ;
F_32 ( V_2 , V_59 ) ;
F_33 ( V_2 , V_59 ) ;
F_34 ( V_2 , V_59 ) ;
F_35 ( V_2 , V_59 ) ;
F_36 ( V_2 , V_43 ) ;
V_52 = F_37 ( V_2 , V_43 , V_44 ) ;
if ( V_52 != 0xFFFF ) {
F_38 ( V_2 , V_52 ) ;
F_39 ( V_2 , V_43 , V_44 , V_52 ) ;
F_40 ( V_2 , V_43 , V_44 , V_52 ) ;
F_41 ( V_2 , V_43 , V_52 ) ;
}
F_42 ( V_2 , V_43 , V_44 ) ;
F_44 ( V_2 , V_43 , V_44 , V_52 ) ;
F_46 ( V_2 , V_43 , V_44 ) ;
F_16 ( V_2 ) ;
}
int F_48 ( struct V_1 * V_2 , unsigned short V_43 )
{
unsigned short V_44 ;
unsigned long V_24 = V_2 -> V_119 ;
F_1 ( V_2 ) ;
F_17 ( V_2 , V_24 ) ;
F_18 ( V_2 ) ;
if ( ! ( F_27 ( V_2 , & V_43 , & V_44 ) ) )
return 0 ;
F_2 ( V_2 , V_2 -> V_23 , 0x05 , 0x86 ) ;
F_19 ( V_2 ) ;
V_43 &= 0x7f ;
V_2 -> V_71 =
V_2 -> V_9 [ V_44 ] . V_49 & V_50 ;
V_2 -> V_120 = V_121 ;
F_47 ( V_2 , V_43 , V_44 ) ;
F_28 ( V_2 ) ;
F_16 ( V_2 ) ;
F_4 ( V_2 , V_2 -> V_30 , 0xFF ) ;
F_2 ( V_2 , V_2 -> V_25 , 0x34 , V_43 ) ;
return 1 ;
}
int F_49 ( struct V_1 * V_2 , unsigned short V_122 )
{
unsigned short V_43 = 0 ;
int V_61 ;
F_1 ( V_2 ) ;
if ( V_122 == 0x03 ) {
V_43 = 0x03 ;
} else {
V_61 = 0 ;
do {
if ( V_2 -> V_9 [ V_61 ] . V_123 == V_122 ) {
V_43 = V_2 -> V_9 [ V_61 ] . V_45 ;
break;
}
} while ( V_2 -> V_9 [ V_61 ++ ] . V_45 != 0xff );
}
if ( ! V_43 )
return 0 ;
return F_48 ( V_2 , V_43 ) ;
}
