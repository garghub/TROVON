static int F_1 ( struct V_1 * V_1 , unsigned char V_2 ,
unsigned char * V_3 )
{
if ( F_2 ( V_1 , V_2 ) ||
F_3 ( & V_1 -> V_4 , V_3 , V_5 ) ) {
F_4 ( V_1 , L_1 , V_6 , V_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned char V_2 ,
unsigned char * V_3 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
if ( F_3 ( V_4 , NULL , V_7 ) ||
F_3 ( V_4 , NULL , V_2 ) ||
F_3 ( V_4 , V_3 , V_5 ) ) {
F_4 ( V_1 , L_1 , V_6 , V_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_1 ,
unsigned char * V_3 , int V_8 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_9 * V_10 = V_1 -> V_11 ;
int V_12 ;
int V_13 = V_14 ;
do {
V_12 = F_3 ( V_4 , V_3 , V_8 ) ;
if ( V_12 == 0 )
break;
V_13 -- ;
F_7 ( L_2 ,
V_8 , V_13 ) ;
F_8 ( V_15 ) ;
} while ( V_13 > 0 );
if ( V_12 )
F_4 ( V_1 , L_3 , V_8 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_1 , unsigned char V_16 ,
unsigned char * V_17 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_3 [ 3 ] ;
int V_12 = 0 ;
if ( V_16 < 0x07 || V_16 > 0x26 )
return - 1 ;
if ( V_16 > 0x11 && V_16 < 0x20 )
return - 1 ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( F_2 ( V_1 , V_19 ) ||
F_2 ( V_1 , V_16 ) ||
F_3 ( & V_1 -> V_4 , V_3 , V_5 ) ) {
V_12 = - 1 ;
}
break;
case 2 :
if ( F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_19 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_16 ) ||
F_6 ( V_1 , V_3 , V_5 ) ) {
V_12 = - 1 ;
}
break;
case 3 ... 4 :
if ( F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_20 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_16 ) ||
F_6 ( V_1 , V_3 , V_5 ) ) {
V_12 = - 1 ;
}
break;
}
if ( V_12 )
F_4 ( V_1 , L_4 , V_16 ) ;
else if ( V_10 -> V_18 != 4 )
* V_17 = V_3 [ 0 ] ;
else
* V_17 = V_3 [ 1 ] ;
return V_12 ;
}
static int F_10 ( struct V_1 * V_1 , unsigned char V_16 ,
unsigned char V_17 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
int V_12 = 0 ;
if ( V_16 < 0x07 || V_16 > 0x26 )
return - 1 ;
if ( V_16 > 0x11 && V_16 < 0x20 )
return - 1 ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( F_2 ( V_1 , V_21 ) ||
F_2 ( V_1 , V_16 ) ||
F_2 ( V_1 , V_17 ) ||
F_3 ( & V_1 -> V_4 , NULL , V_22 ) ) {
V_12 = - 1 ;
}
break;
case 2 :
if ( F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_21 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_16 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_17 ) ||
F_6 ( V_1 , NULL , V_22 ) ) {
V_12 = - 1 ;
}
break;
case 3 :
if ( F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_20 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_16 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_17 ) ||
F_6 ( V_1 , NULL , V_22 ) ) {
V_12 = - 1 ;
}
break;
case 4 :
if ( F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_20 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_16 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_20 ) ||
F_6 ( V_1 , NULL , V_7 ) ||
F_6 ( V_1 , NULL , V_17 ) ||
F_6 ( V_1 , NULL , V_22 ) ) {
V_12 = - 1 ;
}
break;
}
if ( V_12 )
F_4 ( V_1 ,
L_5 ,
V_16 , V_17 ) ;
return V_12 ;
}
static void F_11 ( struct V_1 * V_1 )
{
int V_23 ;
F_12 ( V_24 , V_1 , L_6 ) ;
for ( V_23 = 0 ; V_23 < V_1 -> V_25 ; V_23 ++ )
F_13 ( L_7 , V_23 ? L_8 : L_9 , V_1 -> V_26 [ V_23 ] ) ;
F_13 ( L_10 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
int V_29 ;
if ( V_10 -> V_30 < 0x020000 ) {
V_29 = ( ( V_26 [ 1 ] & 0x80 ) >> 7 ) +
( ( V_26 [ 1 ] & 0x30 ) >> 4 ) ;
} else {
V_29 = ( V_26 [ 0 ] & 0xc0 ) >> 6 ;
}
if ( V_10 -> V_31 ) {
if ( V_29 != 1 ) {
V_10 -> V_32 = 0 ;
} else if ( V_10 -> V_32 < 2 ) {
V_10 -> V_32 ++ ;
F_7 ( L_11 ) ;
return;
}
}
F_15 ( V_28 , V_33 , V_29 != 0 ) ;
if ( V_29 ) {
F_16 ( V_28 , V_34 ,
( ( V_26 [ 1 ] & 0x0c ) << 6 ) | V_26 [ 2 ] ) ;
F_16 ( V_28 , V_35 ,
V_10 -> V_36 - ( ( ( V_26 [ 1 ] & 0x03 ) << 8 ) | V_26 [ 3 ] ) ) ;
}
F_15 ( V_28 , V_37 , V_29 == 1 ) ;
F_15 ( V_28 , V_38 , V_29 == 2 ) ;
F_15 ( V_28 , V_39 , V_29 == 3 ) ;
F_15 ( V_28 , V_40 , V_26 [ 0 ] & 0x01 ) ;
F_15 ( V_28 , V_41 , V_26 [ 0 ] & 0x02 ) ;
if ( V_10 -> V_30 < 0x020000 &&
( V_10 -> V_42 [ 0 ] & V_43 ) ) {
F_15 ( V_28 , V_44 , V_26 [ 0 ] & 0x40 ) ;
F_15 ( V_28 , V_45 , V_26 [ 0 ] & 0x80 ) ;
}
F_17 ( V_28 ) ;
}
static void F_18 ( struct V_27 * V_28 , int V_46 , bool V_47 ,
unsigned int V_48 , unsigned int V_49 )
{
F_19 ( V_28 , V_46 ) ;
F_20 ( V_28 , V_50 , V_47 ) ;
if ( V_47 ) {
F_16 ( V_28 , V_51 , V_48 ) ;
F_16 ( V_28 , V_52 , V_49 ) ;
}
}
static void F_21 ( struct V_27 * V_28 ,
unsigned int V_53 ,
unsigned int V_54 , unsigned int y1 ,
unsigned int V_55 , unsigned int V_56 )
{
F_18 ( V_28 , 0 , V_53 != 0 , V_54 , y1 ) ;
F_18 ( V_28 , 1 , V_53 == 2 , V_55 , V_56 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_27 * V_28 = V_1 -> V_28 ;
unsigned char * V_26 = V_1 -> V_26 ;
unsigned int V_29 , V_54 = 0 , y1 = 0 , V_55 = 0 , V_56 = 0 ;
unsigned int V_57 = 0 , V_58 = 0 ;
V_29 = ( V_26 [ 0 ] & 0xc0 ) >> 6 ;
switch ( V_29 ) {
case 3 :
if ( V_26 [ 3 ] & 0x80 )
V_29 = 4 ;
case 1 :
V_54 = ( ( V_26 [ 1 ] & 0x0f ) << 8 ) | V_26 [ 2 ] ;
y1 = V_10 -> V_36 - ( ( ( V_26 [ 4 ] & 0x0f ) << 8 ) | V_26 [ 5 ] ) ;
V_58 = ( V_26 [ 1 ] & 0xf0 ) | ( ( V_26 [ 4 ] & 0xf0 ) >> 4 ) ;
V_57 = ( ( V_26 [ 0 ] & 0x30 ) >> 2 ) | ( ( V_26 [ 3 ] & 0x30 ) >> 4 ) ;
break;
case 2 :
V_54 = ( ( ( V_26 [ 0 ] & 0x10 ) << 4 ) | V_26 [ 1 ] ) << 2 ;
y1 = V_10 -> V_36 -
( ( ( ( V_26 [ 0 ] & 0x20 ) << 3 ) | V_26 [ 2 ] ) << 2 ) ;
V_55 = ( ( ( V_26 [ 3 ] & 0x10 ) << 4 ) | V_26 [ 4 ] ) << 2 ;
V_56 = V_10 -> V_36 -
( ( ( ( V_26 [ 3 ] & 0x20 ) << 3 ) | V_26 [ 5 ] ) << 2 ) ;
V_58 = 127 ;
V_57 = 7 ;
break;
}
F_15 ( V_28 , V_33 , V_29 != 0 ) ;
if ( V_29 != 0 ) {
F_16 ( V_28 , V_34 , V_54 ) ;
F_16 ( V_28 , V_35 , y1 ) ;
}
F_21 ( V_28 , V_29 , V_54 , y1 , V_55 , V_56 ) ;
F_15 ( V_28 , V_37 , V_29 == 1 ) ;
F_15 ( V_28 , V_38 , V_29 == 2 ) ;
F_15 ( V_28 , V_39 , V_29 == 3 ) ;
F_15 ( V_28 , V_59 , V_29 == 4 ) ;
F_15 ( V_28 , V_40 , V_26 [ 0 ] & 0x01 ) ;
F_15 ( V_28 , V_41 , V_26 [ 0 ] & 0x02 ) ;
if ( V_10 -> V_60 ) {
F_16 ( V_28 , V_61 , V_58 ) ;
F_16 ( V_28 , V_62 , V_57 ) ;
}
F_17 ( V_28 ) ;
}
static void F_23 ( struct V_1 * V_1 ,
int V_63 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_27 * V_64 = V_10 -> V_64 ;
unsigned char * V_26 = V_1 -> V_26 ;
int V_48 , V_49 ;
T_1 V_65 ;
V_65 = F_24 ( & V_26 [ 0 ] ) ;
switch ( V_65 & ~ 7U ) {
case 0x06000030U :
case 0x16008020U :
case 0x26800010U :
case 0x36808000U :
V_48 = V_26 [ 4 ] - ( int ) ( ( V_26 [ 1 ] ^ 0x80 ) << 1 ) ;
V_49 = ( int ) ( ( V_26 [ 2 ] ^ 0x80 ) << 1 ) - V_26 [ 5 ] ;
F_15 ( V_64 , V_40 , V_26 [ 0 ] & 0x01 ) ;
F_15 ( V_64 , V_41 , V_26 [ 0 ] & 0x02 ) ;
F_15 ( V_64 , V_66 , V_26 [ 0 ] & 0x04 ) ;
F_25 ( V_64 , V_67 , V_48 ) ;
F_25 ( V_64 , V_68 , V_49 ) ;
F_17 ( V_64 ) ;
break;
default:
if ( V_10 -> V_69 == 1 )
F_11 ( V_1 ) ;
break;
}
}
static void F_26 ( struct V_1 * V_1 ,
int V_63 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
unsigned int V_29 = 0 , V_54 = 0 , y1 = 0 , V_55 = 0 , V_56 = 0 ;
unsigned int V_57 = 0 , V_58 = 0 ;
V_29 = ( V_26 [ 0 ] & 0xc0 ) >> 6 ;
switch ( V_29 ) {
case 3 :
case 1 :
V_54 = ( ( V_26 [ 1 ] & 0x0f ) << 8 ) | V_26 [ 2 ] ;
y1 = V_10 -> V_36 - ( ( ( V_26 [ 4 ] & 0x0f ) << 8 ) | V_26 [ 5 ] ) ;
break;
case 2 :
if ( V_63 == V_70 ) {
V_10 -> V_71 [ 0 ] . V_48 = ( ( V_26 [ 1 ] & 0x0f ) << 8 ) | V_26 [ 2 ] ;
V_10 -> V_71 [ 0 ] . V_49 = V_10 -> V_36 -
( ( ( V_26 [ 4 ] & 0x0f ) << 8 ) | V_26 [ 5 ] ) ;
return;
}
V_54 = V_10 -> V_71 [ 0 ] . V_48 ;
y1 = V_10 -> V_71 [ 0 ] . V_49 ;
V_55 = ( ( V_26 [ 1 ] & 0x0f ) << 8 ) | V_26 [ 2 ] ;
V_56 = V_10 -> V_36 - ( ( ( V_26 [ 4 ] & 0x0f ) << 8 ) | V_26 [ 5 ] ) ;
break;
}
V_58 = ( V_26 [ 1 ] & 0xf0 ) | ( ( V_26 [ 4 ] & 0xf0 ) >> 4 ) ;
V_57 = ( ( V_26 [ 0 ] & 0x30 ) >> 2 ) | ( ( V_26 [ 3 ] & 0x30 ) >> 4 ) ;
F_15 ( V_28 , V_33 , V_29 != 0 ) ;
if ( V_29 != 0 ) {
F_16 ( V_28 , V_34 , V_54 ) ;
F_16 ( V_28 , V_35 , y1 ) ;
}
F_21 ( V_28 , V_29 , V_54 , y1 , V_55 , V_56 ) ;
F_15 ( V_28 , V_37 , V_29 == 1 ) ;
F_15 ( V_28 , V_38 , V_29 == 2 ) ;
F_15 ( V_28 , V_39 , V_29 == 3 ) ;
if ( V_10 -> V_30 & 0x001000 ) {
F_15 ( V_28 , V_40 , V_26 [ 0 ] & 0x03 ) ;
} else {
F_15 ( V_28 , V_40 , V_26 [ 0 ] & 0x01 ) ;
F_15 ( V_28 , V_41 , V_26 [ 0 ] & 0x02 ) ;
}
F_16 ( V_28 , V_61 , V_58 ) ;
F_16 ( V_28 , V_62 , V_57 ) ;
F_17 ( V_28 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
if ( V_10 -> V_30 & 0x001000 ) {
F_15 ( V_28 , V_40 , V_26 [ 0 ] & 0x03 ) ;
} else {
F_15 ( V_28 , V_40 , V_26 [ 0 ] & 0x01 ) ;
F_15 ( V_28 , V_41 , V_26 [ 0 ] & 0x02 ) ;
F_15 ( V_28 , V_66 , V_26 [ 0 ] & 0x04 ) ;
}
F_28 ( V_28 , true ) ;
F_17 ( V_28 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
unsigned char * V_26 = V_1 -> V_26 ;
unsigned V_29 ;
int V_23 ;
V_29 = V_26 [ 1 ] & 0x1f ;
for ( V_23 = 0 ; V_23 < V_72 ; V_23 ++ ) {
if ( ( V_29 & ( 1 << V_23 ) ) == 0 ) {
F_19 ( V_28 , V_23 ) ;
F_20 ( V_28 , V_50 , false ) ;
}
}
F_27 ( V_1 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
int V_73 = ( ( V_26 [ 3 ] & 0xe0 ) >> 5 ) - 1 ;
int V_58 , V_74 ;
if ( V_73 < 0 )
return;
V_10 -> V_71 [ V_73 ] . V_48 = ( ( V_26 [ 1 ] & 0x0f ) << 8 ) | V_26 [ 2 ] ;
V_10 -> V_71 [ V_73 ] . V_49 = V_10 -> V_36 - ( ( ( V_26 [ 4 ] & 0x0f ) << 8 ) | V_26 [ 5 ] ) ;
V_58 = ( V_26 [ 1 ] & 0xf0 ) | ( ( V_26 [ 4 ] & 0xf0 ) >> 4 ) ;
V_74 = ( V_26 [ 0 ] & 0xf0 ) >> 4 ;
F_19 ( V_28 , V_73 ) ;
F_20 ( V_28 , V_50 , true ) ;
F_16 ( V_28 , V_51 , V_10 -> V_71 [ V_73 ] . V_48 ) ;
F_16 ( V_28 , V_52 , V_10 -> V_71 [ V_73 ] . V_49 ) ;
F_16 ( V_28 , V_75 , V_58 ) ;
F_16 ( V_28 , V_76 , V_74 * V_10 -> V_57 ) ;
F_16 ( V_28 , V_62 , V_74 ) ;
F_27 ( V_1 ) ;
}
static void F_31 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
int V_77 , V_78 = 0 , V_79 = 0 , V_80 = 0 , V_81 = 0 ;
int V_73 , V_82 ;
V_73 = ( ( V_26 [ 0 ] & 0xe0 ) >> 5 ) - 1 ;
if ( V_73 < 0 )
return;
V_82 = ( ( V_26 [ 3 ] & 0xe0 ) >> 5 ) - 1 ;
V_77 = ( V_26 [ 0 ] & 0x10 ) ? V_83 : 1 ;
V_78 = ( signed char ) V_26 [ 1 ] ;
V_79 = ( signed char ) V_26 [ 2 ] ;
V_80 = ( signed char ) V_26 [ 4 ] ;
V_81 = ( signed char ) V_26 [ 5 ] ;
V_10 -> V_71 [ V_73 ] . V_48 += V_78 * V_77 ;
V_10 -> V_71 [ V_73 ] . V_49 -= V_79 * V_77 ;
F_19 ( V_28 , V_73 ) ;
F_16 ( V_28 , V_51 , V_10 -> V_71 [ V_73 ] . V_48 ) ;
F_16 ( V_28 , V_52 , V_10 -> V_71 [ V_73 ] . V_49 ) ;
if ( V_82 >= 0 ) {
V_10 -> V_71 [ V_82 ] . V_48 += V_80 * V_77 ;
V_10 -> V_71 [ V_82 ] . V_49 -= V_81 * V_77 ;
F_19 ( V_28 , V_82 ) ;
F_16 ( V_28 , V_51 , V_10 -> V_71 [ V_82 ] . V_48 ) ;
F_16 ( V_28 , V_52 , V_10 -> V_71 [ V_82 ] . V_49 ) ;
}
F_27 ( V_1 ) ;
}
static void F_32 ( struct V_1 * V_1 ,
int V_63 )
{
switch ( V_63 ) {
case V_84 :
F_29 ( V_1 ) ;
break;
case V_85 :
F_30 ( V_1 ) ;
break;
case V_86 :
F_31 ( V_1 ) ;
break;
case V_87 :
default:
break;
}
}
static int F_33 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
unsigned char V_88 , V_89 , V_90 ;
if ( V_10 -> V_30 < 0x020000 ) {
V_88 = ( V_26 [ 0 ] & 0x20 ) >> 5 ;
V_89 = ( V_26 [ 0 ] & 0x10 ) >> 4 ;
} else {
V_88 = ( V_26 [ 0 ] & 0x10 ) >> 4 ;
V_89 = ( V_26 [ 0 ] & 0x20 ) >> 5 ;
}
V_90 = ( V_26 [ 0 ] & 0x04 ) >> 2 ;
return V_10 -> V_91 [ V_26 [ 1 ] ] == V_88 &&
V_10 -> V_91 [ V_26 [ 2 ] ] == V_89 &&
V_10 -> V_91 [ V_26 [ 3 ] ] == V_90 ;
}
static int F_34 ( struct V_1 * V_1 )
{
const T_2 V_92 [] = { 0x84 , 0xff , 0xff , 0x02 , 0xff , 0xff } ;
unsigned char * V_26 = V_1 -> V_26 ;
return ! memcmp ( V_26 , V_92 , sizeof( V_92 ) ) ;
}
static int F_35 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
if ( V_10 -> V_60 )
return ( V_26 [ 0 ] & 0x0c ) == 0x04 &&
( V_26 [ 3 ] & 0x0f ) == 0x02 ;
if ( ( V_26 [ 0 ] & 0xc0 ) == 0x80 )
return ( V_26 [ 0 ] & 0x0c ) == 0x0c &&
( V_26 [ 3 ] & 0x0e ) == 0x08 ;
return ( V_26 [ 0 ] & 0x3c ) == 0x3c &&
( V_26 [ 1 ] & 0xf0 ) == 0x00 &&
( V_26 [ 3 ] & 0x3e ) == 0x38 &&
( V_26 [ 4 ] & 0xf0 ) == 0x00 ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
const T_2 V_92 [] = { 0xc4 , 0xff , 0xff , 0x02 , 0xff , 0xff } ;
unsigned char * V_26 = V_1 -> V_26 ;
if ( ! memcmp ( V_26 , V_92 , sizeof( V_92 ) ) )
return V_93 ;
if ( V_10 -> V_94 ) {
if ( ( V_26 [ 3 ] & 0x09 ) == 0x08 )
return V_70 ;
if ( ( V_26 [ 3 ] & 0x09 ) == 0x09 )
return V_95 ;
} else {
if ( ( V_26 [ 0 ] & 0x0c ) == 0x04 && ( V_26 [ 3 ] & 0xcf ) == 0x02 )
return V_70 ;
if ( ( V_26 [ 0 ] & 0x0c ) == 0x0c && ( V_26 [ 3 ] & 0xce ) == 0x0c )
return V_95 ;
if ( ( V_26 [ 3 ] & 0x0f ) == 0x06 )
return V_96 ;
}
return V_87 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
unsigned char V_63 = V_26 [ 3 ] & 0x03 ;
bool V_97 ;
if ( V_10 -> V_64 && ( V_26 [ 3 ] & 0x0f ) == 0x06 )
return V_96 ;
if ( V_10 -> V_94 )
V_97 = ( ( V_26 [ 3 ] & 0x08 ) == 0x00 ) ;
else
V_97 = ( ( V_26 [ 0 ] & 0x0c ) == 0x04 &&
( V_26 [ 3 ] & 0x1c ) == 0x10 ) ;
if ( ! V_97 )
return V_87 ;
switch ( V_63 ) {
case 0 :
return V_84 ;
case 1 :
return V_85 ;
case 2 :
return V_86 ;
}
return V_87 ;
}
static T_3 F_38 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
int V_63 ;
if ( V_1 -> V_98 < V_1 -> V_25 )
return V_99 ;
if ( V_10 -> V_69 > 1 )
F_11 ( V_1 ) ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( V_10 -> V_100 && ! F_33 ( V_1 ) )
return V_101 ;
F_14 ( V_1 ) ;
break;
case 2 :
if ( F_34 ( V_1 ) )
return V_102 ;
if ( V_10 -> V_100 && ! F_35 ( V_1 ) )
return V_101 ;
F_22 ( V_1 ) ;
break;
case 3 :
V_63 = F_36 ( V_1 ) ;
switch ( V_63 ) {
case V_87 :
return V_101 ;
case V_93 :
break;
case V_96 :
F_23 ( V_1 , V_63 ) ;
break;
default:
F_26 ( V_1 , V_63 ) ;
break;
}
break;
case 4 :
V_63 = F_37 ( V_1 ) ;
switch ( V_63 ) {
case V_87 :
return V_101 ;
case V_96 :
F_23 ( V_1 , V_63 ) ;
break;
default:
F_32 ( V_1 , V_63 ) ;
break;
}
break;
}
return V_102 ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_17 ;
int V_13 = V_103 ;
int V_12 = 0 ;
switch ( V_10 -> V_18 ) {
case 1 :
V_10 -> V_104 = 0x16 ;
V_10 -> V_105 = 0x8f ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_104 ) ||
F_10 ( V_1 , 0x11 , V_10 -> V_105 ) ) {
V_12 = - 1 ;
}
break;
case 2 :
V_10 -> V_104 = 0x54 ;
V_10 -> V_105 = 0x88 ;
V_10 -> V_106 = 0x60 ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_104 ) ||
F_10 ( V_1 , 0x11 , V_10 -> V_105 ) ||
F_10 ( V_1 , 0x21 , V_10 -> V_106 ) ) {
V_12 = - 1 ;
}
break;
case 3 :
if ( V_10 -> V_107 )
V_10 -> V_104 = 0x0b ;
else
V_10 -> V_104 = 0x01 ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_104 ) )
V_12 = - 1 ;
break;
case 4 :
V_10 -> V_108 = 0x01 ;
if ( F_10 ( V_1 , 0x07 , V_10 -> V_108 ) )
V_12 = - 1 ;
goto V_109;
}
if ( V_12 == 0 ) {
do {
V_12 = F_9 ( V_1 , 0x10 , & V_17 ) ;
if ( V_12 == 0 )
break;
V_13 -- ;
F_7 ( L_12 , V_13 ) ;
F_8 ( V_110 ) ;
} while ( V_13 > 0 );
if ( V_12 ) {
F_4 ( V_1 ,
L_13 ) ;
} else if ( V_10 -> V_18 == 1 &&
! ( V_17 & V_111 ) ) {
F_4 ( V_1 ,
L_14 ) ;
V_12 = - 1 ;
}
}
V_109:
if ( V_12 )
F_4 ( V_1 , L_15 ) ;
return V_12 ;
}
static int F_40 ( struct V_1 * V_1 ,
unsigned int * V_112 , unsigned int * V_113 ,
unsigned int * V_114 , unsigned int * V_36 ,
unsigned int * V_57 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_3 [ 3 ] ;
unsigned char V_74 ;
switch ( V_10 -> V_18 ) {
case 1 :
* V_112 = V_115 ;
* V_113 = V_116 ;
* V_114 = V_117 ;
* V_36 = V_118 ;
break;
case 2 :
if ( V_10 -> V_30 == 0x020800 ||
V_10 -> V_30 == 0x020b00 ||
V_10 -> V_30 == 0x020030 ) {
* V_112 = V_119 ;
* V_113 = V_120 ;
* V_114 = V_121 ;
* V_36 = V_122 ;
} else {
int V_23 ;
int V_123 ;
V_23 = ( V_10 -> V_30 > 0x020800 &&
V_10 -> V_30 < 0x020900 ) ? 1 : 2 ;
if ( V_10 -> V_124 ( V_1 , V_125 , V_3 ) )
return - 1 ;
V_123 = V_3 [ 1 ] & 0x10 ;
if ( ( ( V_10 -> V_30 >> 16 ) == 0x14 ) && V_123 ) {
if ( V_10 -> V_124 ( V_1 , V_126 , V_3 ) )
return - 1 ;
* V_114 = ( V_10 -> V_42 [ 1 ] - V_23 ) * V_3 [ 1 ] / 2 ;
* V_36 = ( V_10 -> V_42 [ 2 ] - V_23 ) * V_3 [ 2 ] / 2 ;
} else if ( V_10 -> V_30 == 0x040216 ) {
* V_114 = 819 ;
* V_36 = 405 ;
} else if ( V_10 -> V_30 == 0x040219 || V_10 -> V_30 == 0x040215 ) {
* V_114 = 900 ;
* V_36 = 500 ;
} else {
* V_114 = ( V_10 -> V_42 [ 1 ] - V_23 ) * 64 ;
* V_36 = ( V_10 -> V_42 [ 2 ] - V_23 ) * 64 ;
}
}
break;
case 3 :
if ( V_10 -> V_124 ( V_1 , V_125 , V_3 ) )
return - 1 ;
* V_114 = ( 0x0f & V_3 [ 0 ] ) << 8 | V_3 [ 1 ] ;
* V_36 = ( 0xf0 & V_3 [ 0 ] ) << 4 | V_3 [ 2 ] ;
break;
case 4 :
if ( V_10 -> V_124 ( V_1 , V_125 , V_3 ) )
return - 1 ;
* V_114 = ( 0x0f & V_3 [ 0 ] ) << 8 | V_3 [ 1 ] ;
* V_36 = ( 0xf0 & V_3 [ 0 ] ) << 4 | V_3 [ 2 ] ;
V_74 = V_10 -> V_42 [ 1 ] ;
if ( ( V_74 < 2 ) || ( V_74 > * V_114 ) )
return - 1 ;
* V_57 = * V_114 / ( V_74 - 1 ) ;
break;
}
return 0 ;
}
static unsigned int F_41 ( unsigned int V_17 )
{
return ( V_17 * 10 + 790 ) * 10 / 254 ;
}
static int F_42 ( struct V_1 * V_1 ,
unsigned int * V_127 ,
unsigned int * V_128 )
{
unsigned char V_3 [ 3 ] ;
if ( F_5 ( V_1 , V_129 , V_3 ) )
return - 1 ;
* V_127 = F_41 ( V_3 [ 1 ] & 0x0f ) ;
* V_128 = F_41 ( ( V_3 [ 1 ] & 0xf0 ) >> 4 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
if ( V_10 -> V_30 & 0x001000 ) {
F_44 ( V_130 , V_28 -> V_131 ) ;
F_45 ( V_41 , V_28 -> V_132 ) ;
}
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned int V_112 = 0 , V_113 = 0 , V_114 = 0 , V_36 = 0 , V_57 = 0 ;
unsigned int V_127 = 0 , V_128 = 0 ;
if ( F_40 ( V_1 , & V_112 , & V_113 , & V_114 , & V_36 , & V_57 ) )
return - 1 ;
F_44 ( V_133 , V_28 -> V_131 ) ;
F_44 ( V_134 , V_28 -> V_135 ) ;
F_44 ( V_136 , V_28 -> V_135 ) ;
F_45 ( V_137 , V_28 -> V_135 ) ;
F_44 ( V_40 , V_28 -> V_132 ) ;
if ( F_47 ( V_138 ) )
F_44 ( V_66 , V_28 -> V_132 ) ;
F_44 ( V_41 , V_28 -> V_132 ) ;
F_44 ( V_33 , V_28 -> V_132 ) ;
F_44 ( V_37 , V_28 -> V_132 ) ;
F_44 ( V_38 , V_28 -> V_132 ) ;
F_44 ( V_39 , V_28 -> V_132 ) ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( V_10 -> V_30 < 0x020000 &&
( V_10 -> V_42 [ 0 ] & V_43 ) ) {
F_44 ( V_44 , V_28 -> V_132 ) ;
F_44 ( V_45 , V_28 -> V_132 ) ;
}
F_48 ( V_28 , V_34 , V_112 , V_114 , 0 , 0 ) ;
F_48 ( V_28 , V_35 , V_113 , V_36 , 0 , 0 ) ;
break;
case 2 :
F_44 ( V_59 , V_28 -> V_132 ) ;
F_44 ( V_139 , V_28 -> V_131 ) ;
case 3 :
if ( V_10 -> V_18 == 3 )
F_43 ( V_1 ) ;
F_48 ( V_28 , V_34 , V_112 , V_114 , 0 , 0 ) ;
F_48 ( V_28 , V_35 , V_113 , V_36 , 0 , 0 ) ;
if ( V_10 -> V_60 ) {
F_48 ( V_28 , V_61 , V_140 ,
V_141 , 0 , 0 ) ;
F_48 ( V_28 , V_62 , V_142 ,
V_143 , 0 , 0 ) ;
}
F_49 ( V_28 , 2 , 0 ) ;
F_48 ( V_28 , V_51 , V_112 , V_114 , 0 , 0 ) ;
F_48 ( V_28 , V_52 , V_113 , V_36 , 0 , 0 ) ;
break;
case 4 :
if ( F_42 ( V_1 , & V_127 , & V_128 ) ) {
F_50 ( V_1 , L_16 ) ;
}
F_43 ( V_1 ) ;
F_44 ( V_59 , V_28 -> V_132 ) ;
F_48 ( V_28 , V_34 , V_112 , V_114 , 0 , 0 ) ;
F_48 ( V_28 , V_35 , V_113 , V_36 , 0 , 0 ) ;
F_51 ( V_28 , V_34 , V_127 ) ;
F_51 ( V_28 , V_35 , V_128 ) ;
F_48 ( V_28 , V_61 , V_140 ,
V_141 , 0 , 0 ) ;
F_48 ( V_28 , V_62 , V_142 ,
V_143 , 0 , 0 ) ;
F_49 ( V_28 , V_72 , 0 ) ;
F_48 ( V_28 , V_51 , V_112 , V_114 , 0 , 0 ) ;
F_48 ( V_28 , V_52 , V_113 , V_36 , 0 , 0 ) ;
F_51 ( V_28 , V_51 , V_127 ) ;
F_51 ( V_28 , V_52 , V_128 ) ;
F_48 ( V_28 , V_75 , V_140 ,
V_141 , 0 , 0 ) ;
F_48 ( V_28 , V_76 , 0 ,
V_143 * V_57 , 0 , 0 ) ;
break;
}
V_10 -> V_36 = V_36 ;
V_10 -> V_57 = V_57 ;
return 0 ;
}
static T_4 F_52 ( struct V_1 * V_1 , void * V_144 ,
char * V_145 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_146 * V_147 = V_144 ;
unsigned char * V_16 = ( unsigned char * ) V_10 + V_147 -> V_148 ;
int V_12 = 0 ;
if ( V_147 -> V_16 )
V_12 = F_9 ( V_1 , V_147 -> V_16 , V_16 ) ;
return sprintf ( V_145 , L_17 , ( V_147 -> V_16 && V_12 ) ? - 1 : * V_16 ) ;
}
static T_4 F_53 ( struct V_1 * V_1 ,
void * V_144 , const char * V_145 , T_5 V_149 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_146 * V_147 = V_144 ;
unsigned char * V_16 = ( unsigned char * ) V_10 + V_147 -> V_148 ;
unsigned char V_150 ;
int V_151 ;
V_151 = F_54 ( V_145 , 16 , & V_150 ) ;
if ( V_151 )
return V_151 ;
if ( V_10 -> V_18 == 1 ) {
if ( V_147 -> V_16 == 0x10 )
V_150 |= V_111 ;
else if ( V_147 -> V_16 == 0x11 )
V_150 |= V_152 ;
}
if ( ! V_147 -> V_16 || F_10 ( V_1 , V_147 -> V_16 , V_150 ) == 0 )
* V_16 = V_150 ;
return V_149 ;
}
static bool F_55 ( const unsigned char * V_3 )
{
static const unsigned char V_153 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 } ;
int V_23 ;
if ( V_3 [ 0 ] == 0 )
return false ;
if ( V_3 [ 1 ] == 0 )
return true ;
if ( V_3 [ 0 ] == 0x46 && ( V_3 [ 1 ] & 0xef ) == 0x0f && V_3 [ 2 ] < 40 )
return true ;
for ( V_23 = 0 ; V_23 < F_56 ( V_153 ) ; V_23 ++ )
if ( V_3 [ 2 ] == V_153 [ V_23 ] )
return false ;
return true ;
}
int F_57 ( struct V_1 * V_1 , bool V_154 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
unsigned char V_3 [ 3 ] ;
F_3 ( & V_1 -> V_4 , NULL , V_155 ) ;
if ( F_3 ( V_4 , NULL , V_156 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , V_3 , V_5 ) ) {
F_58 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( V_3 [ 0 ] != 0x3c || V_3 [ 1 ] != 0x03 ||
( V_3 [ 2 ] != 0xc8 && V_3 [ 2 ] != 0x00 ) ) {
F_58 ( V_1 ,
L_19 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_157 , V_3 ) ) {
F_58 ( V_1 , L_20 ) ;
return - 1 ;
}
F_58 ( V_1 ,
L_21 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( ! F_55 ( V_3 ) ) {
F_58 ( V_1 ,
L_22 ) ;
return - 1 ;
}
if ( V_154 ) {
V_1 -> V_158 = L_23 ;
V_1 -> V_159 = L_24 ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
if ( V_10 -> V_64 )
F_60 ( V_10 -> V_64 ) ;
F_61 ( & V_1 -> V_4 . V_160 -> V_28 . V_161 ,
& V_162 ) ;
F_62 ( V_1 -> V_11 ) ;
V_1 -> V_11 = NULL ;
}
static int F_63 ( struct V_1 * V_1 )
{
F_64 ( V_1 ) ;
if ( F_57 ( V_1 , 0 ) )
return - 1 ;
if ( F_39 ( V_1 ) ) {
F_4 ( V_1 ,
L_25 ) ;
return - 1 ;
}
return 0 ;
}
static int F_65 ( struct V_9 * V_10 )
{
int V_163 = ( V_10 -> V_30 & 0x0f0000 ) >> 16 ;
if ( V_10 -> V_30 < 0x020030 || V_10 -> V_30 == 0x020600 )
V_10 -> V_18 = 1 ;
else {
switch ( V_163 ) {
case 2 :
case 4 :
V_10 -> V_18 = 2 ;
break;
case 5 :
V_10 -> V_18 = 3 ;
break;
case 6 :
case 7 :
case 8 :
case 9 :
case 10 :
case 13 :
V_10 -> V_18 = 4 ;
break;
default:
return - 1 ;
}
}
V_10 -> V_124 = V_10 -> V_18 >= 3 ? F_5 :
F_1 ;
V_10 -> V_100 = 1 ;
V_10 -> V_31 =
( V_10 -> V_30 == 0x020022 || V_10 -> V_30 == 0x020600 ) ;
if ( V_10 -> V_18 > 1 ) {
V_10 -> V_69 = 1 ;
if ( V_10 -> V_30 >= 0x020800 )
V_10 -> V_60 = true ;
}
V_10 -> V_94 = ( V_10 -> V_30 & 0x4000 ) == 0x4000 ||
F_47 ( V_164 ) ;
V_10 -> V_107 = ! F_47 ( V_165 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_1 )
{
struct V_9 * V_10 ;
int V_23 ;
int error = - V_166 ;
unsigned char V_3 [ 3 ] ;
struct V_27 * V_64 ;
V_1 -> V_11 = V_10 = F_67 ( sizeof( struct V_9 ) , V_167 ) ;
if ( ! V_10 )
return - V_168 ;
F_64 ( V_1 ) ;
V_10 -> V_91 [ 0 ] = 1 ;
for ( V_23 = 1 ; V_23 < 256 ; V_23 ++ )
V_10 -> V_91 [ V_23 ] = V_10 -> V_91 [ V_23 & ( V_23 - 1 ) ] ^ 1 ;
if ( F_1 ( V_1 , V_157 , V_3 ) ) {
F_4 ( V_1 , L_20 ) ;
goto V_169;
}
V_10 -> V_30 = ( V_3 [ 0 ] << 16 ) | ( V_3 [ 1 ] << 8 ) | V_3 [ 2 ] ;
if ( F_65 ( V_10 ) ) {
F_4 ( V_1 , L_26 ) ;
goto V_169;
}
F_68 ( V_1 ,
L_27 ,
V_10 -> V_18 , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( V_10 -> V_124 ( V_1 , V_170 ,
V_10 -> V_42 ) ) {
F_4 ( V_1 , L_28 ) ;
goto V_169;
}
F_68 ( V_1 ,
L_29 ,
V_10 -> V_42 [ 0 ] , V_10 -> V_42 [ 1 ] ,
V_10 -> V_42 [ 2 ] ) ;
if ( F_39 ( V_1 ) ) {
F_4 ( V_1 ,
L_30 ) ;
goto V_169;
}
if ( F_46 ( V_1 ) ) {
F_4 ( V_1 , L_31 ) ;
goto V_169;
}
error = F_69 ( & V_1 -> V_4 . V_160 -> V_28 . V_161 ,
& V_162 ) ;
if ( error ) {
F_4 ( V_1 ,
L_32 ,
error ) ;
goto V_169;
}
if ( ( V_10 -> V_42 [ 0 ] & 0x80 ) == 0x80 ) {
V_64 = F_70 () ;
if ( ! V_64 ) {
error = - V_168 ;
goto V_171;
}
V_10 -> V_64 = V_64 ;
snprintf ( V_10 -> V_172 , sizeof( V_10 -> V_172 ) , L_33 ,
V_1 -> V_4 . V_160 -> V_173 ) ;
V_64 -> V_173 = V_10 -> V_172 ;
V_64 -> V_159 = L_34 ;
V_64 -> V_73 . V_174 = V_175 ;
V_64 -> V_73 . V_158 = 0x0002 ;
V_64 -> V_73 . V_176 = V_177 ;
V_64 -> V_73 . V_178 = 0x0000 ;
V_64 -> V_28 . V_179 = & V_1 -> V_4 . V_160 -> V_28 ;
V_64 -> V_135 [ 0 ] = F_71 ( V_134 ) | F_71 ( V_137 ) ;
V_64 -> V_180 [ F_72 ( V_67 ) ] =
F_71 ( V_67 ) | F_71 ( V_68 ) ;
V_64 -> V_132 [ F_72 ( V_40 ) ] =
F_71 ( V_40 ) | F_71 ( V_66 ) |
F_71 ( V_41 ) ;
F_44 ( V_133 , V_64 -> V_131 ) ;
F_44 ( V_181 , V_64 -> V_131 ) ;
error = F_73 ( V_10 -> V_64 ) ;
if ( error < 0 )
goto V_182;
}
V_1 -> V_183 = F_38 ;
V_1 -> V_184 = F_59 ;
V_1 -> V_185 = F_63 ;
V_1 -> V_25 = V_10 -> V_18 > 1 ? 6 : 4 ;
return 0 ;
V_182:
F_74 ( V_64 ) ;
V_171:
F_61 ( & V_1 -> V_4 . V_160 -> V_28 . V_161 ,
& V_162 ) ;
V_169:
F_64 ( V_1 ) ;
F_62 ( V_10 ) ;
return error ;
}
