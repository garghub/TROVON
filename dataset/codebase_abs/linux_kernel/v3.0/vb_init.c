static unsigned char
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_5 , V_6 ;
if ( V_2 -> V_7 < V_8 ) {
if ( * V_4 -> V_9 & V_10 ) {
V_5 = * V_4 -> V_9 & 0x07 ;
return V_5 ;
} else {
V_5 = F_2 ( V_4 -> V_11 , 0x39 ) & 0x02 ;
if ( V_5 == 0 )
V_5 = ( F_2 ( V_4 -> V_11 , 0x3A ) &
0x02 ) >> 1 ;
return V_5 ;
}
} else if ( V_2 -> V_7 == V_12 ) {
if ( * V_4 -> V_9 & V_10 ) {
V_5 = * V_4 -> V_9 & 0x07 ;
return V_5 ;
}
V_6 = F_2 ( V_4 -> V_11 , 0x3B ) ;
if ( ( V_6 & 0x88 ) == 0x80 )
V_5 = 0 ;
else
V_5 = 1 ;
return V_5 ;
} else if ( V_2 -> V_7 == V_13 ) {
F_3 ( V_4 -> V_14 , 0xB4 , ~ 0x02 ) ;
F_4 ( 800 ) ;
F_5 ( V_4 -> V_14 , 0x4A , 0x80 ) ;
V_6 = F_2 ( V_4 -> V_14 , 0x48 ) ;
if ( V_6 & 0x01 )
V_5 = 1 ;
else
V_5 = 0 ;
F_5 ( V_4 -> V_14 , 0xB4 , 0x02 ) ;
return V_5 ;
} else {
V_5 = F_2 ( V_4 -> V_14 , 0x97 ) & 0x01 ;
if ( V_5 == 1 )
V_5 ++ ;
return V_5 ;
}
}
static void F_6 ( unsigned long V_11 ,
struct V_3 * V_4 )
{
F_7 ( V_11 , 0x18 , 0x01 ) ;
F_7 ( V_11 , 0x19 , 0x20 ) ;
F_7 ( V_11 , 0x16 , 0x00 ) ;
F_7 ( V_11 , 0x16 , 0x80 ) ;
if ( * V_4 -> V_15 != 0x0C ) {
F_8 ( 3 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0x20 ) ;
F_7 ( V_11 , 0x16 , 0x00 ) ;
F_7 ( V_11 , 0x16 , 0x80 ) ;
}
F_4 ( 60 ) ;
F_7 ( V_11 , 0x18 , V_4 -> V_16 [ 2 ] [ V_17 ] ) ;
F_7 ( V_11 , 0x19 , 0x01 ) ;
F_7 ( V_11 , 0x16 , V_4 -> V_18 [ 0 ] ) ;
F_7 ( V_11 , 0x16 , V_4 -> V_18 [ 1 ] ) ;
F_8 ( 1 ) ;
F_7 ( V_11 , 0x1B , 0x03 ) ;
F_4 ( 500 ) ;
F_7 ( V_11 , 0x18 , V_4 -> V_16 [ 2 ] [ V_17 ] ) ;
F_7 ( V_11 , 0x19 , 0x00 ) ;
F_7 ( V_11 , 0x16 , V_4 -> V_18 [ 2 ] ) ;
F_7 ( V_11 , 0x16 , V_4 -> V_18 [ 3 ] ) ;
F_7 ( V_11 , 0x1B , 0x00 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_7 ( V_4 -> V_11 ,
0x28 ,
V_4 -> V_19 [ V_17 ] . V_20 ) ;
F_7 ( V_4 -> V_11 ,
0x29 ,
V_4 -> V_19 [ V_17 ] . V_21 ) ;
F_7 ( V_4 -> V_11 ,
0x2A ,
V_4 -> V_19 [ V_17 ] . V_22 ) ;
F_7 ( V_4 -> V_11 ,
0x2E ,
V_4 -> V_23 [ V_17 ] . V_24 ) ;
F_7 ( V_4 -> V_11 ,
0x2F ,
V_4 -> V_23 [ V_17 ] . V_25 ) ;
F_7 ( V_4 -> V_11 ,
0x30 ,
V_4 -> V_23 [ V_17 ] . V_26 ) ;
if ( V_2 -> V_7 == V_27 ) {
if ( ( V_4 -> V_19 [ V_17 ] . V_20 == 0x1C ) &&
( V_4 -> V_19 [ V_17 ] . V_21 == 0x01 ) &&
( ( ( V_4 -> V_23 [ V_17 ] . V_24 == 0x1C ) &&
( V_4 -> V_23 [ V_17 ] . V_25 == 0x01 ) ) ||
( ( V_4 -> V_23 [ V_17 ] . V_24 == 0x22 ) &&
( V_4 -> V_23 [ V_17 ] . V_25 == 0x01 ) ) ) )
F_7 ( V_4 -> V_11 ,
0x32 ,
( ( unsigned char ) F_2 (
V_4 -> V_11 , 0x32 ) & 0xFC ) | 0x02 ) ;
}
}
static void F_10 (
struct V_1 * V_2 ,
unsigned long V_11 , struct V_3 * V_4 )
{
unsigned long V_14 = V_11 + 0x10 ;
V_17 = ( int ) F_1 ( V_2 ,
V_4 ) ;
F_9 ( V_2 , V_4 ) ;
F_7 ( V_14 , 0x97 , * V_4 -> V_28 ) ;
F_4 ( 200 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0x80 ) ;
F_7 ( V_11 , 0x16 , 0x20 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x16 , 0xA0 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0xC0 ) ;
F_7 ( V_11 , 0x16 , 0x20 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x16 , 0xA0 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0x40 ) ;
F_7 ( V_11 , 0x16 , 0x20 ) ;
F_4 ( 30 ) ;
F_7 ( V_11 , 0x16 , 0xA0 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x18 , 0x42 ) ;
F_7 ( V_11 , 0x19 , 0x0A ) ;
F_7 ( V_11 , 0x16 , 0x00 ) ;
F_4 ( 30 ) ;
F_7 ( V_11 , 0x16 , 0x00 ) ;
F_7 ( V_11 , 0x16 , 0x80 ) ;
F_7 ( V_11 , 0x1B , 0x04 ) ;
F_4 ( 60 ) ;
F_7 ( V_11 , 0x1B , 0x00 ) ;
F_7 ( V_11 , 0x18 , 0x42 ) ;
F_7 ( V_11 , 0x19 , 0x08 ) ;
F_7 ( V_11 , 0x16 , 0x00 ) ;
F_4 ( 30 ) ;
F_7 ( V_11 , 0x16 , 0x83 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x18 , 0x80 ) ;
F_7 ( V_11 , 0x19 , 0x46 ) ;
F_7 ( V_11 , 0x16 , 0x20 ) ;
F_4 ( 30 ) ;
F_7 ( V_11 , 0x16 , 0xA0 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0x40 ) ;
F_7 ( V_11 , 0x16 , 0x20 ) ;
F_4 ( 30 ) ;
F_7 ( V_11 , 0x16 , 0xA0 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x1B , 0x04 ) ;
F_4 ( 200 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned long V_11 , struct V_3 * V_4 )
{
unsigned long V_14 = V_11 + 0x10 ;
V_17 = ( int ) F_1 ( V_2 ,
V_4 ) ;
F_9 ( V_2 , V_4 ) ;
F_7 ( V_14 , 0x97 , 0x11 ) ;
F_4 ( 200 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0x80 ) ;
F_7 ( V_11 , 0x16 , 0x05 ) ;
F_7 ( V_11 , 0x16 , 0x85 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0xC0 ) ;
F_7 ( V_11 , 0x16 , 0x05 ) ;
F_7 ( V_11 , 0x16 , 0x85 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0x40 ) ;
F_7 ( V_11 , 0x16 , 0x05 ) ;
F_7 ( V_11 , 0x16 , 0x85 ) ;
F_7 ( V_11 , 0x18 , 0x42 ) ;
F_7 ( V_11 , 0x19 , 0x02 ) ;
F_7 ( V_11 , 0x16 , 0x05 ) ;
F_7 ( V_11 , 0x16 , 0x85 ) ;
F_4 ( 15 ) ;
F_7 ( V_11 , 0x1B , 0x04 ) ;
F_4 ( 30 ) ;
F_7 ( V_11 , 0x1B , 0x00 ) ;
F_4 ( 100 ) ;
F_7 ( V_11 , 0x18 , 0x42 ) ;
F_7 ( V_11 , 0x19 , 0x00 ) ;
F_7 ( V_11 , 0x16 , 0x05 ) ;
F_7 ( V_11 , 0x16 , 0x85 ) ;
F_4 ( 200 ) ;
}
static void F_12 ( unsigned long V_11 ,
struct V_3 * V_4 )
{
F_7 ( V_11 , 0x18 , 0x01 ) ;
F_7 ( V_11 , 0x19 , 0x40 ) ;
F_7 ( V_11 , 0x16 , 0x00 ) ;
F_7 ( V_11 , 0x16 , 0x80 ) ;
F_4 ( 60 ) ;
F_7 ( V_11 , 0x18 , 0x00 ) ;
F_7 ( V_11 , 0x19 , 0x40 ) ;
F_7 ( V_11 , 0x16 , 0x00 ) ;
F_7 ( V_11 , 0x16 , 0x80 ) ;
F_4 ( 60 ) ;
F_7 ( V_11 , 0x18 , V_4 -> V_16 [ 2 ] [ V_17 ] ) ;
F_7 ( V_11 , 0x19 , 0x01 ) ;
F_7 ( V_11 , 0x16 , 0x03 ) ;
F_7 ( V_11 , 0x16 , 0x83 ) ;
F_8 ( 1 ) ;
F_7 ( V_11 , 0x1B , 0x03 ) ;
F_4 ( 500 ) ;
F_7 ( V_11 , 0x18 , V_4 -> V_16 [ 2 ] [ V_17 ] ) ;
F_7 ( V_11 , 0x19 , 0x00 ) ;
F_7 ( V_11 , 0x16 , 0x03 ) ;
F_7 ( V_11 , 0x16 , 0x83 ) ;
F_7 ( V_11 , 0x1B , 0x00 ) ;
}
static void F_13 (
struct V_1 * V_2 ,
unsigned long V_29 , struct V_3 * V_4 )
{
unsigned long V_14 = V_29 , V_11 = V_29 - 0x10 ;
if ( V_2 -> V_7 >= V_8 ) {
F_9 ( V_2 , V_4 ) ;
F_7 ( V_14 ,
0x82 ,
V_4 -> V_30 [ 11 ] [ V_17 ] ) ;
F_7 ( V_14 ,
0x85 ,
V_4 -> V_30 [ 12 ] [ V_17 ] ) ;
F_7 ( V_14 ,
0x86 ,
V_4 -> V_30 [ 13 ] [ V_17 ] ) ;
F_7 ( V_14 , 0x98 , 0x01 ) ;
F_7 ( V_14 , 0x9A , 0x02 ) ;
F_12 ( V_11 , V_4 ) ;
} else {
F_9 ( V_2 , V_4 ) ;
switch ( V_2 -> V_7 ) {
case V_31 :
case V_27 :
F_7 ( V_14 ,
0x82 ,
V_4 -> V_30 [ 11 ] [ V_17 ] ) ;
F_7 ( V_14 ,
0x85 ,
V_4 -> V_30 [ 12 ] [ V_17 ] ) ;
F_7 ( V_14 ,
0x86 ,
V_4 -> V_30 [ 13 ] [ V_17 ] ) ;
break;
default:
F_7 ( V_14 , 0x82 , 0x88 ) ;
F_7 ( V_14 , 0x86 , 0x00 ) ;
F_2 ( V_14 , 0x86 ) ;
F_7 ( V_14 , 0x86 , 0x88 ) ;
F_2 ( V_14 , 0x86 ) ;
F_7 ( V_14 ,
0x86 ,
V_4 -> V_30 [ 13 ] [ V_17 ] ) ;
F_7 ( V_14 , 0x82 , 0x77 ) ;
F_7 ( V_14 , 0x85 , 0x00 ) ;
F_2 ( V_14 , 0x85 ) ;
F_7 ( V_14 , 0x85 , 0x88 ) ;
F_2 ( V_14 , 0x85 ) ;
F_7 ( V_14 ,
0x85 ,
V_4 -> V_30 [ 12 ] [ V_17 ] ) ;
F_7 ( V_14 ,
0x82 ,
V_4 -> V_30 [ 11 ] [ V_17 ] ) ;
break;
}
F_7 ( V_14 , 0x97 , 0x00 ) ;
F_7 ( V_14 , 0x98 , 0x01 ) ;
F_7 ( V_14 , 0x9A , 0x02 ) ;
F_6 ( V_11 , V_4 ) ;
}
}
static void F_14 (
struct V_1 * V_2 ,
unsigned long V_29 , struct V_3 * V_4 )
{
unsigned long V_14 = V_29 , V_11 = V_29 - 0x10 ;
F_7 ( V_14 , 0x82 , 0x77 ) ;
F_7 ( V_14 , 0x86 , 0x00 ) ;
F_2 ( V_14 , 0x86 ) ;
F_7 ( V_14 , 0x86 , 0x88 ) ;
F_2 ( V_14 , 0x86 ) ;
F_7 ( V_14 , 0x86 , V_4 -> V_30 [ 13 ] [ V_17 ] ) ;
F_7 ( V_14 , 0x82 , 0x77 ) ;
F_7 ( V_14 , 0x85 , 0x00 ) ;
F_2 ( V_14 , 0x85 ) ;
F_7 ( V_14 , 0x85 , 0x88 ) ;
F_2 ( V_14 , 0x85 ) ;
F_7 ( V_14 , 0x85 , V_4 -> V_30 [ 12 ] [ V_17 ] ) ;
if ( V_2 -> V_7 == V_12 )
F_7 ( V_14 , 0x82 , V_4 -> V_30 [ 11 ] [ V_17 ] ) ;
else
F_7 ( V_14 , 0x82 , 0xA8 ) ;
F_7 ( V_14 , 0x98 , 0x01 ) ;
F_7 ( V_14 , 0x9A , 0x02 ) ;
if ( V_2 -> V_7 == V_12 )
F_10 ( V_2 , V_11 , V_4 ) ;
else
F_11 ( V_2 , V_11 , V_4 ) ;
}
static void F_15 (
struct V_1 * V_2 ,
unsigned long V_29 , struct V_3 * V_4 )
{
unsigned char V_6 , V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
unsigned long V_14 = V_29 , V_11 = V_29 - 0x10 ;
F_7 ( V_14 , 0x6D , V_4 -> V_30 [ 8 ] [ V_17 ] ) ;
F_7 ( V_14 , 0x68 , V_4 -> V_30 [ 5 ] [ V_17 ] ) ;
F_7 ( V_14 , 0x69 , V_4 -> V_30 [ 6 ] [ V_17 ] ) ;
F_7 ( V_14 , 0x6A , V_4 -> V_30 [ 7 ] [ V_17 ] ) ;
V_33 = 0 ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
V_6 = V_4 -> V_38 [ V_17 ] [ V_35 ] ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_32 = ( ( V_6 >> ( 2 * V_36 ) ) & 0x03 ) << 2 ;
V_33 |= V_32 ;
F_7 ( V_14 , 0x6B , V_33 ) ;
F_2 ( V_14 , 0x6B ) ;
V_33 &= 0xF0 ;
V_33 += 0x10 ;
}
}
V_33 = 0 ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
V_6 = V_4 -> V_39 [ V_17 ] [ V_35 ] ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_32 = ( ( V_6 >> ( 2 * V_36 ) ) & 0x03 ) << 2 ;
V_33 |= V_32 ;
F_7 ( V_14 , 0x6E , V_33 ) ;
F_2 ( V_14 , 0x6E ) ;
V_33 &= 0xF0 ;
V_33 += 0x10 ;
}
}
V_34 = 0 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
F_16 ( V_14 , 0x6E , 0xFC , V_34 ) ;
V_33 = 0 ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
V_6 = V_4 -> V_40 [ V_17 ] [ 8 * V_37 + V_35 ] ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_32 = ( V_6 >> ( 2 * V_36 ) ) & 0x03 ;
V_33 |= V_32 ;
F_7 ( V_14 , 0x6F , V_33 ) ;
F_2 ( V_14 , 0x6F ) ;
V_33 &= 0xF8 ;
V_33 += 0x08 ;
}
}
V_34 += 0x01 ;
}
F_7 ( V_14 , 0x80 , V_4 -> V_30 [ 9 ] [ V_17 ] ) ;
F_7 ( V_14 , 0x81 , V_4 -> V_30 [ 10 ] [ V_17 ] ) ;
V_33 = 0x80 ;
V_6 = V_4 -> V_41 [ V_17 ] [ 0 ] ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_32 = ( V_6 >> ( 2 * V_36 ) ) & 0x03 ;
V_33 |= V_32 ;
F_7 ( V_14 , 0x89 , V_33 ) ;
F_2 ( V_14 , 0x89 ) ;
V_33 &= 0xF0 ;
V_33 += 0x10 ;
}
V_6 = V_4 -> V_41 [ V_17 ] [ 1 ] ;
V_32 = V_6 & 0x03 ;
V_33 |= V_32 ;
F_7 ( V_14 , 0x89 , V_33 ) ;
V_6 = V_4 -> V_30 [ 3 ] [ V_17 ] ;
V_32 = V_6 & 0x0F ;
V_33 = ( V_6 >> 4 ) & 0x07 ;
V_34 = V_6 & 0x80 ;
F_7 ( V_14 , 0x45 , V_32 ) ;
F_7 ( V_14 , 0x99 , V_33 ) ;
F_5 ( V_14 , 0x40 , V_34 ) ;
F_7 ( V_14 , 0x41 , V_4 -> V_30 [ 0 ] [ V_17 ] ) ;
if ( V_2 -> V_7 == V_12 )
F_7 ( V_14 , 0x8F , * V_4 -> V_42 ) ;
for ( V_36 = 0 ; V_36 <= 6 ; V_36 ++ )
F_7 ( V_14 , ( 0x90 + V_36 ) ,
V_4 -> V_30 [ 14 + V_36 ] [ V_17 ] ) ;
for ( V_36 = 0 ; V_36 <= 2 ; V_36 ++ )
F_7 ( V_14 , ( 0xC3 + V_36 ) ,
V_4 -> V_30 [ 21 + V_36 ] [ V_17 ] ) ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ )
F_7 ( V_14 , ( 0x8A + V_36 ) ,
V_4 -> V_30 [ 1 + V_36 ] [ V_17 ] ) ;
if ( ( V_2 -> V_7 == V_31 ) ||
( V_2 -> V_7 == V_27 ) )
F_7 ( V_14 , 0x8C , 0x87 ) ;
F_7 ( V_14 , 0x59 , V_4 -> V_30 [ 4 ] [ V_17 ] ) ;
F_7 ( V_14 , 0x83 , 0x09 ) ;
F_7 ( V_14 , 0x87 , 0x00 ) ;
F_7 ( V_14 , 0xCF , * V_4 -> V_43 ) ;
if ( V_17 ) {
F_7 ( V_11 , 0x17 , 0x80 ) ;
if ( V_2 -> V_7 == V_12 )
F_7 ( V_11 , 0x17 , 0x02 ) ;
} else {
F_7 ( V_11 , 0x17 , 0x00 ) ;
}
F_7 ( V_11 , 0x1A , 0x87 ) ;
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 == 0 ) {
F_13 ( V_2 , V_14 , V_4 ) ;
} else {
F_7 ( V_14 , 0xB0 , 0x80 ) ;
F_14 ( V_2 , V_14 , V_4 ) ;
}
F_7 ( V_11 , 0x1B , V_4 -> V_16 [ 3 ] [ V_17 ] ) ;
}
static void F_17 ( int V_44 ,
unsigned short V_45 [] [ 5 ] ,
struct V_3 * V_4 )
{
unsigned short V_5 ;
V_5 = V_45 [ V_44 ] [ 4 ] ;
F_16 ( V_4 -> V_11 , 0x13 , 0x80 , V_5 ) ;
F_4 ( 15 ) ;
}
static unsigned short F_18 ( int V_44 ,
unsigned short V_45 [] [ 5 ] ,
struct V_3 * V_4 )
{
unsigned short V_5 = 0 , V_46 = 0 ;
int V_47 ;
unsigned char V_48 ;
V_47 = V_45 [ V_44 ] [ 3 ] * V_49 / 32 ;
V_5 = F_2 ( V_4 -> V_11 , 0x13 ) ;
V_5 &= 0x80 ;
if ( V_5 == 0x80 )
V_47 *= 2 ;
V_5 = 0 ;
if ( V_50 == 3 )
V_48 = 4 ;
else
V_48 = V_50 ;
if ( V_48 * V_47 <= 256 ) {
while ( ( V_47 >>= 1 ) > 0 )
V_5 += 0x10 ;
V_46 = V_5 >> 4 ;
F_7 ( V_4 -> V_11 ,
0x14 ,
( F_2 ( V_4 -> V_11 , 0x14 ) & 0x0F ) |
( V_5 & 0xF0 ) ) ;
}
return V_46 ;
}
static unsigned short F_19 ( int V_44 ,
unsigned short V_45 [] [ 5 ] ,
struct V_3 * V_4 )
{
unsigned short V_5 = 0 , V_46 = 0 ;
int V_47 ;
unsigned char V_48 ;
V_47 = V_45 [ V_44 ] [ 3 ] * V_49 / 8 ;
V_5 = F_2 ( V_4 -> V_11 , 0x13 ) ;
V_5 &= 0x80 ;
if ( V_5 == 0x80 )
V_47 *= 2 ;
V_5 = 0 ;
if ( V_50 == 3 )
V_48 = 4 ;
else
V_48 = V_50 ;
if ( V_48 * V_47 <= 256 ) {
while ( ( V_47 >>= 1 ) > 0 )
V_5 += 0x10 ;
V_46 = V_5 >> 4 ;
F_7 ( V_4 -> V_11 ,
0x14 ,
( F_2 ( V_4 -> V_11 , 0x14 ) & 0x0F ) |
( V_5 & 0xF0 ) ) ;
F_4 ( 15 ) ;
}
return V_46 ;
}
static int F_20 ( unsigned short V_51 ,
unsigned short V_52 , struct V_3 * V_4 )
{
int V_35 ;
unsigned long V_53 = 0 ;
* ( ( unsigned long * ) ( V_4 -> V_54 + V_53 ) ) = V_53 ;
for ( V_35 = V_52 ; V_35 <= V_51 ; V_35 ++ ) {
V_53 = 1 << V_35 ;
* ( ( unsigned long * ) ( V_4 -> V_54 + V_53 ) ) = V_53 ;
}
F_4 ( 500 ) ;
V_53 = 0 ;
if ( ( * ( unsigned long * ) ( V_4 -> V_54 + V_53 ) ) != V_53 )
return 0 ;
for ( V_35 = V_52 ; V_35 <= V_51 ; V_35 ++ ) {
V_53 = 1 << V_35 ;
if ( ( * ( unsigned long * ) ( V_4 -> V_54 + V_53 ) ) !=
V_53 )
return 0 ;
}
return 1 ;
}
static unsigned char F_21 ( struct V_3 * V_4 )
{
unsigned char V_5 ;
V_5 = F_2 ( V_4 -> V_14 , 0x97 ) ;
if ( ( V_5 & 0x10 ) == 0 ) {
V_5 = F_2 ( V_4 -> V_11 , 0x39 ) ;
V_5 = ( V_5 & 0x02 ) >> 1 ;
return V_5 ;
} else {
return V_5 & 0x01 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_5 ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_13 :
V_5 = F_2 ( V_4 -> V_14 , 0x97 ) ;
V_5 = V_5 & 0x01 ;
V_50 = 1 ;
if ( V_5 == 0 ) {
if ( ( V_2 -> V_55 - 1 )
> 0x1000000 ) {
V_49 = 32 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xB1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x52 ) ;
F_4 ( 15 ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
if ( ( V_2 -> V_55 - 1 ) >
0x800000 ) {
F_7 ( V_4 -> V_11 ,
0x13 ,
0x31 ) ;
F_7 ( V_4 -> V_11 ,
0x14 ,
0x42 ) ;
F_4 ( 15 ) ;
if ( F_20 ( 23 ,
23 ,
V_4 ) == 1 )
return;
}
}
if ( ( V_2 -> V_55 - 1 ) >
0x800000 ) {
V_49 = 16 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xB1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x41 ) ;
F_4 ( 15 ) ;
if ( F_20 ( 23 , 22 , V_4 ) == 1 )
return;
else
F_7 ( V_4 -> V_11 ,
0x13 ,
0x31 ) ;
F_4 ( 15 ) ;
}
} else {
if ( ( V_2 -> V_55 - 1 ) >
0x800000 ) {
V_49 = 16 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xB1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x41 ) ;
F_4 ( 15 ) ;
if ( F_20 ( 23 , 22 , V_4 ) == 1 )
return;
if ( ( V_2 -> V_55 - 1 ) >
0x400000 ) {
F_7 ( V_4 -> V_11 ,
0x13 ,
0x31 ) ;
F_7 ( V_4 -> V_11 ,
0x14 ,
0x31 ) ;
F_4 ( 15 ) ;
if ( F_20 ( 22 ,
22 ,
V_4 ) == 1 )
return;
}
}
if ( ( V_2 -> V_55 - 1 ) >
0x400000 ) {
V_49 = 8 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xB1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x30 ) ;
F_4 ( 15 ) ;
if ( F_20 ( 22 , 21 , V_4 ) == 1 )
return;
else
F_7 ( V_4 -> V_11 ,
0x13 ,
0x31 ) ;
F_4 ( 15 ) ;
}
}
break;
case V_12 :
V_49 = 16 ;
V_50 = 1 ;
F_7 ( V_4 -> V_11 , 0x14 , 0x51 ) ;
break;
case V_31 :
if ( F_21 ( V_4 ) == 1 ) {
V_49 = 32 ;
V_50 = 3 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xA1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x4C ) ;
if ( F_20 ( 25 , 23 , V_4 ) == 1 )
return;
V_50 = 2 ;
F_7 ( V_4 -> V_11 , 0x14 , 0x48 ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
F_7 ( V_4 -> V_11 , 0x14 , 0x49 ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
V_50 = 3 ;
F_7 ( V_4 -> V_11 , 0x13 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x3C ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
F_7 ( V_4 -> V_11 , 0x14 , 0x38 ) ;
if ( F_20 ( 8 , 4 , V_4 ) == 1 )
return;
else
F_7 ( V_4 -> V_11 , 0x14 , 0x39 ) ;
} else {
V_49 = 64 ;
V_50 = 2 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xA1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x5A ) ;
if ( F_20 ( 25 , 24 , V_4 ) == 1 )
return;
V_50 = 1 ;
F_7 ( V_4 -> V_11 , 0x14 , 0x52 ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
F_7 ( V_4 -> V_11 , 0x14 , 0x53 ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
V_50 = 2 ;
F_7 ( V_4 -> V_11 , 0x13 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x4A ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
V_50 = 1 ;
F_7 ( V_4 -> V_11 , 0x14 , 0x42 ) ;
if ( F_20 ( 8 , 4 , V_4 ) == 1 )
return;
else
F_7 ( V_4 -> V_11 , 0x14 , 0x43 ) ;
}
break;
case V_27 :
if ( F_21 ( V_4 ) == 1 ) {
V_49 = 32 ;
V_50 = 2 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xA1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x44 ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
F_7 ( V_4 -> V_11 , 0x13 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x34 ) ;
if ( F_20 ( 23 , 22 , V_4 ) == 1 )
return;
V_50 = 1 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xA1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x40 ) ;
if ( F_20 ( 23 , 22 , V_4 ) == 1 )
return;
else {
F_7 ( V_4 -> V_11 , 0x13 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x30 ) ;
}
} else {
V_49 = 64 ;
V_50 = 1 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xA1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x52 ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
else {
F_7 ( V_4 -> V_11 , 0x13 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x42 ) ;
}
}
break;
default:
if ( F_21 ( V_4 ) == 1 ) {
V_49 = 32 ;
V_50 = 3 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xA1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x4C ) ;
if ( F_20 ( 25 , 23 , V_4 ) == 1 )
return;
V_50 = 2 ;
F_7 ( V_4 -> V_11 , 0x14 , 0x48 ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 )
return;
F_7 ( V_4 -> V_11 , 0x13 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x3C ) ;
if ( F_20 ( 24 , 23 , V_4 ) == 1 ) {
V_50 = 3 ;
} else {
V_50 = 2 ;
F_7 ( V_4 -> V_11 , 0x14 , 0x38 ) ;
}
} else {
V_49 = 64 ;
V_50 = 2 ;
F_7 ( V_4 -> V_11 , 0x13 , 0xA1 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x5A ) ;
if ( F_20 ( 25 , 24 , V_4 ) == 1 ) {
return;
} else {
F_7 ( V_4 -> V_11 , 0x13 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x4A ) ;
}
}
break;
}
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_35 ;
unsigned short V_46 , V_56 ;
F_7 ( V_4 -> V_11 , 0x15 , 0x00 ) ;
F_7 ( V_4 -> V_11 , 0x1C , 0x00 ) ;
F_22 ( V_2 , V_4 ) ;
if ( V_2 -> V_7 >= V_8 ) {
for ( V_35 = 0 ; V_35 < 12 ; V_35 ++ ) {
F_17 ( V_35 ,
V_57 ,
V_4 ) ;
V_46 = F_19 ( V_35 ,
V_57 ,
V_4 ) ;
if ( V_46 == 0 )
continue;
V_56 = V_46 + ( V_50 - 2 ) + 20 ;
if ( ( V_2 -> V_55 - 1 ) <
( unsigned long ) ( 1 << V_56 ) )
continue;
if ( F_20 ( V_56 , 5 , V_4 ) == 1 )
return 1 ;
}
} else {
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
F_17 ( V_35 ,
V_58 ,
V_4 ) ;
V_46 = F_18 ( V_35 ,
V_58 ,
V_4 ) ;
if ( V_46 == 0 )
continue;
V_56 = V_46 + ( V_50 - 2 ) + 20 ;
if ( ( V_2 -> V_55 - 1 ) <
( unsigned long ) ( 1 << V_56 ) )
continue;
if ( F_20 ( V_56 , 9 , V_4 ) == 1 )
return 1 ;
}
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned short V_5 ;
V_4 -> V_59 = V_2 -> V_60 ;
V_4 -> V_54 = V_2 -> V_61 ;
F_25 ( V_2 , 0x2e ) ;
V_5 = F_2 ( V_4 -> V_11 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x21 , ( unsigned short ) ( V_5 & 0xDF ) ) ;
F_26 ( V_2 , V_4 ) ;
F_23 ( V_2 , V_4 ) ;
V_5 = F_2 ( V_4 -> V_11 , 0x21 ) ;
F_7 ( V_4 -> V_11 , 0x21 , ( unsigned short ) ( V_5 | 0x20 ) ) ;
}
static void F_27 ( unsigned char V_62 ,
struct V_3 * V_4 )
{
volatile unsigned char * V_63 =
( unsigned char * ) V_4 -> V_59 ;
unsigned long V_35 ;
unsigned char V_36 , V_37 ;
if ( V_62 == V_13 ) {
V_4 -> V_64 = 0 ;
if ( V_63 [ 0x65 ] & 0x1 ) {
V_4 -> V_64 = 1 ;
V_35 = V_63 [ 0x316 ] | ( V_63 [ 0x317 ] << 8 ) ;
V_36 = V_63 [ V_35 - 1 ] ;
if ( V_36 != 0xff ) {
V_37 = 0 ;
do {
V_4 -> V_65 [ V_37 ] .
V_66
= V_63 [ V_35 ] |
( V_63 [ V_35 + 1 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_67
= V_63 [ V_35 + 2 ] |
( V_63 [ V_35 + 3 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_68
= V_63 [ V_35 + 4 ] |
( V_63 [ V_35 + 5 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_69
= V_63 [ V_35 + 6 ] |
( V_63 [ V_35 + 7 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_70
= V_63 [ V_35 + 8 ] |
( V_63 [ V_35 + 9 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_71
= V_63 [ V_35 + 10 ] |
( V_63 [ V_35 + 11 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_72
= V_63 [ V_35 + 12 ] |
( V_63 [ V_35 + 13 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_73
= V_63 [ V_35 + 14 ] |
( V_63 [ V_35 + 15 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_74
= V_63 [ V_35 + 16 ] |
( V_63 [ V_35 + 17 ] << 8 ) ;
V_4 -> V_65 [ V_37 ] . V_75
= V_63 [ V_35 + 18 ] ;
V_4 -> V_65 [ V_37 ] . V_76
= V_63 [ V_35 + 19 ] ;
V_4 -> V_65 [ V_37 ] . V_77
= V_63 [ V_35 + 20 ] ;
V_4 -> V_65 [ V_37 ] . V_78
= V_63 [ V_35 + 21 ] ;
V_4 -> V_65 [ V_37 ] . V_79
= V_63 [ V_35 + 22 ] ;
V_4 -> V_65 [ V_37 ] . V_80
= V_63 [ V_35 + 23 ] ;
V_4 -> V_65 [ V_37 ] . V_81
= V_63 [ V_35 + 24 ] ;
V_35 += 25 ;
V_36 -- ;
V_37 ++ ;
} while ( ( V_36 > 0 ) &&
( V_37 < ( sizeof( V_82 ) /
sizeof( struct
V_83 ) ) ) );
} else {
V_4 -> V_65 [ 0 ] . V_66
= V_63 [ V_35 ] |
( V_63 [ V_35 + 1 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_67
= V_63 [ V_35 + 2 ] |
( V_63 [ V_35 + 3 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_68
= V_63 [ V_35 + 4 ] |
( V_63 [ V_35 + 5 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_69
= V_63 [ V_35 + 6 ] |
( V_63 [ V_35 + 7 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_70
= V_63 [ V_35 + 8 ] |
( V_63 [ V_35 + 9 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_71
= V_63 [ V_35 + 10 ] |
( V_63 [ V_35 + 11 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_72
= V_63 [ V_35 + 12 ] |
( V_63 [ V_35 + 13 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_73
= V_63 [ V_35 + 14 ] |
( V_63 [ V_35 + 15 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_74
= V_63 [ V_35 + 16 ] |
( V_63 [ V_35 + 17 ] << 8 ) ;
V_4 -> V_65 [ 0 ] . V_75
= V_63 [ V_35 + 18 ] ;
V_4 -> V_65 [ 0 ] . V_76
= V_63 [ V_35 + 19 ] ;
V_4 -> V_65 [ 0 ] . V_77
= V_63 [ V_35 + 20 ] ;
V_4 -> V_65 [ 0 ] . V_78
= V_63 [ V_35 + 21 ] ;
V_4 -> V_65 [ 0 ] . V_79
= V_63 [ V_35 + 22 ] ;
V_4 -> V_65 [ 0 ] . V_80
= V_63 [ V_35 + 23 ] ;
V_4 -> V_65 [ 0 ] . V_81
= V_63 [ V_35 + 24 ] ;
}
}
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned short V_84 = 0 , V_6 , V_85 , V_86 ;
V_6 = F_2 ( V_4 -> V_14 , 0x32 ) ;
if ( V_6 & V_87 )
V_84 |= V_88 ;
if ( V_6 & V_89 )
V_84 |= V_90 ;
if ( V_6 & V_91 )
V_84 |= V_92 ;
if ( V_6 & V_93 ) {
V_84 |= V_94 ;
if ( V_6 & V_95 )
V_84 |= ( V_96 << 8 ) ;
if ( V_6 & V_97 )
V_84 |= ( V_98 << 8 ) ;
if ( V_6 & V_99 )
V_84 |= ( V_100 << 8 ) ;
if ( V_6 & V_101 )
V_84 |= ( V_102 << 8 ) ;
if ( V_6 & V_103 )
V_84 |= ( V_104 << 8 ) ;
}
V_85 = F_2 ( V_4 -> V_14 , 0x3d ) ;
V_85 |= ( F_2 ( V_4 -> V_14 , 0x3e ) << 8 ) ;
if ( V_84 & V_85 ) {
V_86 = F_2 ( V_4 -> V_14 , 0x3c ) ;
if ( ! ( V_86 & V_105 ) ) {
V_85 = 0x1FF0 ;
if ( * V_4 -> V_9 & V_106 )
V_84 = 0x1FF0 ;
}
} else {
V_85 = 0x1FF0 ;
if ( * V_4 -> V_9 & V_106 )
V_84 = 0x1FF0 ;
}
V_84 &= V_85 ;
F_7 ( V_4 -> V_14 , 0x3d , ( V_84 & 0x00FF ) ) ;
F_7 ( V_4 -> V_14 , 0x3e , ( ( V_84 & 0xFF00 ) >> 8 ) ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned short V_6 , V_107 = 0 , V_108 = 0 , V_109 , V_110 ;
V_6 = F_2 ( V_4 -> V_14 , 0x3d ) ;
V_6 |= F_2 ( V_4 -> V_14 , 0x3e ) << 8 ;
V_6 |= ( F_2 ( V_4 -> V_14 , 0x31 ) & ( V_111 >> 8 ) ) << 8 ;
if ( V_4 -> V_112 == 1 ) {
if ( V_6 & V_92 )
V_107 = V_113 ;
}
if ( V_6 & V_90 ) {
V_107 |= V_114 ;
if ( V_6 & V_111 ) {
if ( V_6 & V_94 ) {
V_108 = V_115 | V_116 ;
V_6 ^= V_114 ;
if ( ( V_6 >> 8 ) & V_96 )
V_107 |= V_117 ;
if ( ( V_6 >> 8 ) & V_98 )
V_107 |= V_118 ;
if ( ( V_6 >> 8 ) & V_100 )
V_107 |= V_119 ;
if ( V_4 -> V_120 == 1 ) {
if ( ( V_6 >> 8 ) & V_102 )
V_107 |= V_121 ;
}
if ( V_4 -> V_122 == 1 ) {
if ( ( V_6 >> 8 ) & V_104 )
V_108 |= V_123 ;
}
}
}
} else {
if ( ( V_6 >> 8 ) & V_96 )
V_107 |= V_117 ;
if ( ( V_6 >> 8 ) & V_98 )
V_107 |= V_118 ;
if ( ( V_6 >> 8 ) & V_100 )
V_107 |= V_119 ;
if ( V_4 -> V_120 == 1 ) {
if ( ( V_6 >> 8 ) & V_102 )
V_107 |= V_121 ;
}
if ( V_4 -> V_122 == 1 ) {
if ( ( V_6 >> 8 ) & V_104 )
V_108 |= V_123 ;
}
}
V_107 |= V_124 ;
if ( ( ! ( V_6 & V_88 ) ) && ( ( V_6 & V_90 ) || ( V_6 & V_94 )
|| ( V_6 & V_92 ) ) )
V_107 ^= ( V_124 | V_125 ) ;
if ( ( V_6 & V_90 ) && ( V_6 & V_94 ) )
V_107 ^= ( V_124 | V_125 ) ;
F_7 ( V_4 -> V_14 , 0x30 , V_107 ) ;
V_109 = F_2 ( V_4 -> V_14 , 0x31 ) ;
V_109 &= ~ ( V_126 >> 8 ) ;
if ( ! ( V_6 & V_88 ) )
V_109 |= ( V_126 >> 8 ) ;
V_109 &= ~ ( V_127 >> 8 ) ;
if ( ! ( ( V_6 & V_90 ) || ( V_6 & V_94 ) || ( V_6 & V_92 ) ) )
V_109 |= ( V_127 >> 8 ) ;
F_7 ( V_4 -> V_14 , 0x31 , V_109 ) ;
V_110 = F_2 ( V_4 -> V_14 , 0x38 ) ;
V_110 &= ~ V_123 ;
V_110 |= V_108 ;
F_7 ( V_4 -> V_14 , 0x38 , V_110 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_128 ;
volatile unsigned char * V_63 =
( unsigned char * ) V_4 -> V_59 ;
V_4 -> V_64 = 0 ;
#if 1
if ( ( V_63 [ 0x65 ] & 0x01 ) ) {
V_4 -> V_64 = 1 ;
F_5 ( V_4 -> V_14 , 0x32 , V_89 ) ;
F_16 ( V_4 -> V_14 , 0x38 , ~ 0xE0 , 0xC0 ) ;
} else {
#endif
F_16 ( V_4 -> V_14 , 0x4A , ~ 0x03 , 0x03 ) ;
V_128 = F_2 ( V_4 -> V_14 , 0x48 ) & 0xC0 ;
if ( V_128 == 0xC0 ) {
F_31 ( V_2 , V_4 ) ;
F_5 ( V_4 -> V_14 , 0x32 , V_89 ) ;
F_16 ( V_4 -> V_14 , 0x4A , ~ 0x20 , 0x20 ) ;
V_128 = F_2 ( V_4 -> V_14 , 0x48 ) & 0x04 ;
if ( ! V_128 )
F_16 ( V_4 -> V_14 ,
0x38 ,
~ 0xE0 ,
0x80 ) ;
else
F_16 ( V_4 -> V_14 ,
0x38 ,
~ 0xE0 ,
0xA0 ) ;
F_3 ( V_4 -> V_14 , 0x4A , ~ 0x20 ) ;
}
#if 1
}
#endif
}
static void F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_128 , V_129 ;
V_4 -> V_64 = 0 ;
V_129 = F_2 ( V_4 -> V_14 , 0x4A ) ;
F_16 ( V_4 -> V_14 , 0x4A , ~ 0x07 , 0x07 ) ;
V_128 = F_2 ( V_4 -> V_14 , 0x48 ) & 0x07 ;
F_7 ( V_4 -> V_14 , 0x4A , V_129 ) ;
if ( V_128 <= 0x02 ) {
V_4 -> V_64 = 1 ;
F_16 ( V_4 -> V_14 , 0x38 , ~ 0xE0 , 0xC0 ) ;
F_7 ( V_4 -> V_14 , 0x30 , 0x21 ) ;
} else {
F_16 ( V_4 -> V_14 , 0x38 , ~ 0xE0 , 0xA0 ) ;
}
F_5 ( V_4 -> V_14 , 0x32 , V_89 ) ;
}
static unsigned char F_33 ( struct V_3 * V_4 )
{
unsigned char V_130 , V_131 , V_6 ;
V_131 = F_2 ( V_4 -> V_14 , 0x4A ) ;
F_16 ( V_4 -> V_14 , 0x4A , ~ 0x10 , 0x10 ) ;
V_130 = F_2 ( V_4 -> V_14 , 0x38 ) ;
V_6 = 0 ;
if ( ( V_130 & 0xE0 ) > 0x80 ) {
V_6 = F_2 ( V_4 -> V_14 , 0x48 ) ;
V_6 &= 0x08 ;
V_6 >>= 3 ;
}
F_7 ( V_4 -> V_14 , 0x4A , V_131 ) ;
return V_6 ;
}
static unsigned char F_34 ( struct V_3 * V_4 )
{
unsigned char V_131 , V_6 ;
V_131 = F_2 ( V_4 -> V_14 , 0x4A ) ;
F_16 ( V_4 -> V_14 , 0x4A , ~ 0x03 , 0x03 ) ;
V_6 = F_2 ( V_4 -> V_14 , 0x48 ) ;
if ( V_6 <= 2 )
V_6 &= 0x03 ;
else
V_6 = ( ( V_6 & 0x04 ) >> 1 ) || ( ( ~ V_6 ) & 0x01 ) ;
F_7 ( V_4 -> V_14 , 0x4A , V_131 ) ;
return V_6 ;
}
unsigned char F_35 ( struct V_1 * V_2 )
{
struct V_3 V_132 ;
struct V_3 * V_4 = & V_132 ;
unsigned char V_35 , V_6 = 0 , V_32 ;
volatile unsigned char * V_63 ;
unsigned long V_128 ;
V_4 -> V_59 = V_2 -> V_60 ;
V_4 -> V_54 = V_2 -> V_61 ;
V_4 -> V_133 = ( unsigned long ) V_2 -> V_134 ;
V_63 = ( unsigned char * ) V_4 -> V_59 ;
if ( V_4 -> V_54 == NULL ) {
F_36 ( L_1 ) ;
return 0 ;
}
F_36 ( L_2 ) ;
if ( V_4 -> V_133 == 0 ) {
F_36 ( L_3 ) ;
return 0 ;
}
F_36 ( L_4 ) ;
F_37 ( 0x67 , ( V_4 -> V_133 + 0x12 ) ) ;
V_4 -> V_135 = 0 ;
F_36 ( L_5 ) ;
F_36 ( L_6 ) ;
V_4 -> V_11 = V_4 -> V_133 + 0x14 ;
V_4 -> V_14 = V_4 -> V_133 + 0x24 ;
V_4 -> V_136 = V_4 -> V_133 + 0x10 ;
V_4 -> V_137 = V_4 -> V_133 + 0x1e ;
V_4 -> V_138 = V_4 -> V_133 + 0x12 ;
V_4 -> V_139 = V_4 -> V_133 + 0x1a ;
V_4 -> V_140 = V_4 -> V_133 + 0x16 ;
V_4 -> V_141 = V_4 -> V_133 + 0x17 ;
V_4 -> V_142 = V_4 -> V_133 + 0x18 ;
V_4 -> V_143 = V_4 -> V_133 + 0x19 ;
V_4 -> V_144 = V_4 -> V_133 + 0x2A ;
V_4 -> V_145 = V_4 -> V_133 + V_146 ;
V_4 -> V_147 = V_4 -> V_133 + V_148 ;
V_4 -> V_149 = V_4 -> V_133 + V_150 ;
V_4 -> V_151 = V_4 -> V_133 + V_152 ;
V_4 -> V_153 = V_4 -> V_133 + V_154 ;
V_4 -> V_155 = V_4 -> V_133 + V_154 + 2 ;
F_36 ( L_7 ) ;
if ( V_2 -> V_7 < V_8 )
F_38 ( V_4 ) ;
F_39 ( V_2 -> V_7 , V_4 ) ;
F_27 ( V_2 -> V_7 , V_4 ) ;
F_7 ( V_4 -> V_11 , 0x05 , 0x86 ) ;
F_36 ( L_8 ) ;
if ( V_2 -> V_7 == V_13 )
F_30 ( V_2 , V_4 ) ;
if ( V_2 -> V_7 == V_12 )
F_32 ( V_2 , V_4 ) ;
F_36 ( L_9 ) ;
for ( V_35 = 0x06 ; V_35 < 0x20 ; V_35 ++ )
F_7 ( V_4 -> V_11 , V_35 , 0 ) ;
for ( V_35 = 0x21 ; V_35 <= 0x27 ; V_35 ++ )
F_7 ( V_4 -> V_11 , V_35 , 0 ) ;
F_36 ( L_10 ) ;
for ( V_35 = 0x31 ; V_35 <= 0x3B ; V_35 ++ )
F_7 ( V_4 -> V_11 , V_35 , 0 ) ;
F_36 ( L_11 ) ;
if ( V_2 -> V_7 == V_27 )
F_7 ( V_4 -> V_11 , 0x3B , 0xC0 ) ;
for ( V_35 = 0x79 ; V_35 <= 0x7C ; V_35 ++ )
F_7 ( V_4 -> V_14 , V_35 , 0 ) ;
F_36 ( L_12 ) ;
if ( V_2 -> V_7 >= V_8 )
F_7 ( V_4 -> V_14 , 0x97 , * V_4 -> V_28 ) ;
F_36 ( L_13 ) ;
F_7 ( V_4 -> V_11 , 0x07 , * V_4 -> V_156 ) ;
if ( V_2 -> V_7 == V_12 ) {
F_7 ( V_4 -> V_11 , 0x40 , * V_4 -> V_157 ) ;
F_7 ( V_4 -> V_11 , 0x41 , * V_4 -> V_158 ) ;
}
F_7 ( V_4 -> V_11 , 0x11 , 0x0F ) ;
F_7 ( V_4 -> V_11 , 0x1F , * V_4 -> V_159 ) ;
F_7 ( V_4 -> V_11 , 0x20 , 0xA0 ) ;
F_7 ( V_4 -> V_11 , 0x36 , 0x70 ) ;
if ( V_2 -> V_7 == V_12 )
F_7 ( V_4 -> V_11 , 0x36 , * V_4 -> V_160 ) ;
F_36 ( L_14 ) ;
if ( V_2 -> V_7 < V_8 ) {
F_36 ( L_15 ) ;
for ( V_35 = 0x47 ; V_35 <= 0x4C ; V_35 ++ )
F_7 ( V_4 -> V_14 ,
V_35 ,
V_4 -> V_161 [ V_35 - 0x47 ] ) ;
for ( V_35 = 0x70 ; V_35 <= 0x71 ; V_35 ++ )
F_7 ( V_4 -> V_14 ,
V_35 ,
V_4 -> V_161 [ 6 + V_35 - 0x70 ] ) ;
for ( V_35 = 0x74 ; V_35 <= 0x77 ; V_35 ++ )
F_7 ( V_4 -> V_14 ,
V_35 ,
V_4 -> V_161 [ 8 + V_35 - 0x74 ] ) ;
V_2 -> V_162 ( V_2 ,
0x50 ,
0 ,
& V_128 ) ;
V_128 >>= 20 ;
V_128 &= 0xF ;
if ( V_128 == 1 )
F_7 ( V_4 -> V_14 , 0x48 , 0x20 ) ;
F_36 ( L_16 ) ;
}
F_7 ( V_4 -> V_11 , 0x23 , * V_4 -> V_163 ) ;
F_7 ( V_4 -> V_11 , 0x24 , * V_4 -> V_164 ) ;
F_7 ( V_4 -> V_11 , 0x25 , V_4 -> V_165 [ 0 ] ) ;
F_36 ( L_17 ) ;
if ( V_2 -> V_7 < V_8 ) {
F_40 ( V_2 , V_4 ) ;
F_16 ( V_4 -> V_145 , 0x3F , 0xEF , 0x00 ) ;
F_7 ( V_4 -> V_147 , 0x00 , 0x00 ) ;
V_32 = ( unsigned char ) F_2 ( V_4 -> V_14 , 0x7B ) ;
V_6 = ( unsigned char ) ( ( V_32 >> 4 ) & 0x0F ) ;
F_7 ( V_4 -> V_147 ,
0x02 ,
( * V_4 -> V_166 ) ) ;
F_36 ( L_18 ) ;
F_7 ( V_4 -> V_147 , 0x2E , 0x08 ) ;
}
F_7 ( V_4 -> V_11 , 0x27 , 0x1F ) ;
if ( ( V_2 -> V_7 == V_27 ) &&
F_1 ( V_2 , V_4 ) != 0 ) {
F_7 ( V_4 -> V_11 ,
0x31 ,
( * V_4 -> V_167 & 0x3F ) | 0x40 ) ;
F_7 ( V_4 -> V_11 ,
0x32 ,
( * V_4 -> V_168 & 0xFC ) | 0x01 ) ;
} else {
F_7 ( V_4 -> V_11 , 0x31 , * V_4 -> V_167 ) ;
F_7 ( V_4 -> V_11 , 0x32 , * V_4 -> V_168 ) ;
}
F_7 ( V_4 -> V_11 , 0x33 , * V_4 -> V_169 ) ;
F_36 ( L_19 ) ;
if ( V_2 -> V_7 < V_8 ) {
if ( F_41 ( V_4 ) == 1 ) {
if ( V_4 -> V_64 == 0 ) {
F_7 ( V_4 -> V_149 , 0x00 , 0x1C ) ;
F_7 ( V_4 -> V_153 ,
0x0D ,
* V_4 -> V_170 ) ;
F_7 ( V_4 -> V_153 ,
0x0E ,
* V_4 -> V_171 ) ;
F_7 ( V_4 -> V_153 ,
0x10 ,
* V_4 -> V_172 ) ;
F_7 ( V_4 -> V_153 , 0x0F , 0x3F ) ;
}
F_42 ( V_2 , V_4 ) ;
}
}
F_36 ( L_20 ) ;
F_36 ( L_21 ) ;
F_36 ( L_22 ) ;
F_43 ( V_4 ) ;
F_36 ( L_23 ) ;
V_4 -> V_173 = 0 ;
if ( ( V_2 -> V_7 == V_13 ) &&
( V_4 -> V_173 ) ) {
F_36 ( L_24 ) ;
F_44 ( V_2 , V_4 ) ;
F_36 ( L_25 ) ;
}
if ( V_2 -> V_7 == V_13 ) {
F_36 ( L_26 ) ;
F_16 ( V_4 -> V_14 ,
0x32 ,
~ V_87 ,
V_87 ) ;
V_6 = F_33 ( V_4 ) ;
F_16 ( V_4 -> V_14 , 0x37 , ~ 0x01 , V_6 ) ;
F_36 ( L_27 ) ;
}
if ( V_2 -> V_7 == V_12 ) {
F_16 ( V_4 -> V_14 ,
0x32 ,
~ V_87 ,
V_87 ) ;
V_6 = F_34 ( V_4 ) ;
F_16 ( V_4 -> V_14 , 0x37 , ~ 0x03 , V_6 ) ;
}
F_36 ( L_28 ) ;
V_17 = ( int ) F_1 ( V_2 ,
V_4 ) ;
F_15 ( V_2 ,
V_4 -> V_14 ,
V_4 ) ;
F_36 ( L_29 ) ;
F_24 ( V_2 , V_4 ) ;
F_36 ( L_30 ) ;
F_36 ( L_31 ) ;
F_7 ( V_4 -> V_11 ,
0x22 ,
( unsigned char ) ( ( * V_4 -> V_174 ) & 0xFE ) ) ;
F_7 ( V_4 -> V_11 , 0x21 , * V_4 -> V_175 ) ;
F_36 ( L_32 ) ;
F_28 ( V_2 , V_4 ) ;
F_29 ( V_2 , V_4 ) ;
F_36 ( L_33 ) ;
F_7 ( V_4 -> V_14 , 0x8c , 0x87 ) ;
F_7 ( V_4 -> V_11 , 0x14 , 0x31 ) ;
F_36 ( L_34 ) ;
return 1 ;
}
