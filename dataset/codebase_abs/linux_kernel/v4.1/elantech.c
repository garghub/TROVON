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
F_18 ( V_28 , 1 , V_53 >= 2 , V_55 , V_56 ) ;
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
static void F_39 ( struct V_1 * V_1 ,
unsigned int V_103 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
V_10 -> V_104 ( V_1 , V_103 ) ;
if ( F_10 ( V_1 , 0x07 , V_10 -> V_105 ) )
F_4 ( V_1 , L_12 ) ;
}
static int F_40 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_17 ;
int V_13 = V_106 ;
int V_12 = 0 ;
switch ( V_10 -> V_18 ) {
case 1 :
V_10 -> V_107 = 0x16 ;
V_10 -> V_108 = 0x8f ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_107 ) ||
F_10 ( V_1 , 0x11 , V_10 -> V_108 ) ) {
V_12 = - 1 ;
}
break;
case 2 :
V_10 -> V_107 = 0x54 ;
V_10 -> V_108 = 0x88 ;
V_10 -> V_109 = 0x60 ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_107 ) ||
F_10 ( V_1 , 0x11 , V_10 -> V_108 ) ||
F_10 ( V_1 , 0x21 , V_10 -> V_109 ) ) {
V_12 = - 1 ;
}
break;
case 3 :
if ( V_10 -> V_110 )
V_10 -> V_107 = 0x0b ;
else
V_10 -> V_107 = 0x01 ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_107 ) )
V_12 = - 1 ;
break;
case 4 :
V_10 -> V_105 = 0x01 ;
if ( F_10 ( V_1 , 0x07 , V_10 -> V_105 ) )
V_12 = - 1 ;
goto V_111;
}
if ( V_12 == 0 ) {
do {
V_12 = F_9 ( V_1 , 0x10 , & V_17 ) ;
if ( V_12 == 0 )
break;
V_13 -- ;
F_7 ( L_13 , V_13 ) ;
F_8 ( V_112 ) ;
} while ( V_13 > 0 );
if ( V_12 ) {
F_4 ( V_1 ,
L_14 ) ;
} else if ( V_10 -> V_18 == 1 &&
! ( V_17 & V_113 ) ) {
F_4 ( V_1 ,
L_15 ) ;
V_12 = - 1 ;
}
}
V_111:
if ( V_12 )
F_4 ( V_1 , L_16 ) ;
return V_12 ;
}
static int F_41 ( struct V_1 * V_1 ,
unsigned int * V_114 , unsigned int * V_115 ,
unsigned int * V_116 , unsigned int * V_36 ,
unsigned int * V_57 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_3 [ 3 ] ;
unsigned char V_74 ;
switch ( V_10 -> V_18 ) {
case 1 :
* V_114 = V_117 ;
* V_115 = V_118 ;
* V_116 = V_119 ;
* V_36 = V_120 ;
break;
case 2 :
if ( V_10 -> V_30 == 0x020800 ||
V_10 -> V_30 == 0x020b00 ||
V_10 -> V_30 == 0x020030 ) {
* V_114 = V_121 ;
* V_115 = V_122 ;
* V_116 = V_123 ;
* V_36 = V_124 ;
} else {
int V_23 ;
int V_125 ;
V_23 = ( V_10 -> V_30 > 0x020800 &&
V_10 -> V_30 < 0x020900 ) ? 1 : 2 ;
if ( V_10 -> V_126 ( V_1 , V_127 , V_3 ) )
return - 1 ;
V_125 = V_3 [ 1 ] & 0x10 ;
if ( ( ( V_10 -> V_30 >> 16 ) == 0x14 ) && V_125 ) {
if ( V_10 -> V_126 ( V_1 , V_128 , V_3 ) )
return - 1 ;
* V_116 = ( V_10 -> V_42 [ 1 ] - V_23 ) * V_3 [ 1 ] / 2 ;
* V_36 = ( V_10 -> V_42 [ 2 ] - V_23 ) * V_3 [ 2 ] / 2 ;
} else if ( V_10 -> V_30 == 0x040216 ) {
* V_116 = 819 ;
* V_36 = 405 ;
} else if ( V_10 -> V_30 == 0x040219 || V_10 -> V_30 == 0x040215 ) {
* V_116 = 900 ;
* V_36 = 500 ;
} else {
* V_116 = ( V_10 -> V_42 [ 1 ] - V_23 ) * 64 ;
* V_36 = ( V_10 -> V_42 [ 2 ] - V_23 ) * 64 ;
}
}
break;
case 3 :
if ( V_10 -> V_126 ( V_1 , V_127 , V_3 ) )
return - 1 ;
* V_116 = ( 0x0f & V_3 [ 0 ] ) << 8 | V_3 [ 1 ] ;
* V_36 = ( 0xf0 & V_3 [ 0 ] ) << 4 | V_3 [ 2 ] ;
break;
case 4 :
if ( V_10 -> V_126 ( V_1 , V_127 , V_3 ) )
return - 1 ;
* V_116 = ( 0x0f & V_3 [ 0 ] ) << 8 | V_3 [ 1 ] ;
* V_36 = ( 0xf0 & V_3 [ 0 ] ) << 4 | V_3 [ 2 ] ;
V_74 = V_10 -> V_42 [ 1 ] ;
if ( ( V_74 < 2 ) || ( V_74 > * V_116 ) )
return - 1 ;
* V_57 = * V_116 / ( V_74 - 1 ) ;
break;
}
return 0 ;
}
static unsigned int F_42 ( unsigned int V_17 )
{
return ( V_17 * 10 + 790 ) * 10 / 254 ;
}
static int F_43 ( struct V_1 * V_1 ,
unsigned int * V_129 ,
unsigned int * V_130 )
{
unsigned char V_3 [ 3 ] ;
if ( F_5 ( V_1 , V_131 , V_3 ) )
return - 1 ;
* V_129 = F_42 ( V_3 [ 1 ] & 0x0f ) ;
* V_130 = F_42 ( ( V_3 [ 1 ] & 0xf0 ) >> 4 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
if ( V_10 -> V_30 & 0x001000 ) {
F_45 ( V_132 , V_28 -> V_133 ) ;
F_46 ( V_41 , V_28 -> V_134 ) ;
}
}
static int F_47 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned int V_114 = 0 , V_115 = 0 , V_116 = 0 , V_36 = 0 , V_57 = 0 ;
unsigned int V_129 = 0 , V_130 = 0 ;
if ( F_41 ( V_1 , & V_114 , & V_115 , & V_116 , & V_36 , & V_57 ) )
return - 1 ;
F_45 ( V_135 , V_28 -> V_133 ) ;
F_45 ( V_136 , V_28 -> V_137 ) ;
F_45 ( V_138 , V_28 -> V_137 ) ;
F_46 ( V_139 , V_28 -> V_137 ) ;
F_45 ( V_40 , V_28 -> V_134 ) ;
if ( F_48 ( V_140 ) )
F_45 ( V_66 , V_28 -> V_134 ) ;
F_45 ( V_41 , V_28 -> V_134 ) ;
F_45 ( V_33 , V_28 -> V_134 ) ;
F_45 ( V_37 , V_28 -> V_134 ) ;
F_45 ( V_38 , V_28 -> V_134 ) ;
F_45 ( V_39 , V_28 -> V_134 ) ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( V_10 -> V_30 < 0x020000 &&
( V_10 -> V_42 [ 0 ] & V_43 ) ) {
F_45 ( V_44 , V_28 -> V_134 ) ;
F_45 ( V_45 , V_28 -> V_134 ) ;
}
F_49 ( V_28 , V_34 , V_114 , V_116 , 0 , 0 ) ;
F_49 ( V_28 , V_35 , V_115 , V_36 , 0 , 0 ) ;
break;
case 2 :
F_45 ( V_59 , V_28 -> V_134 ) ;
F_45 ( V_141 , V_28 -> V_133 ) ;
case 3 :
if ( V_10 -> V_18 == 3 )
F_44 ( V_1 ) ;
F_49 ( V_28 , V_34 , V_114 , V_116 , 0 , 0 ) ;
F_49 ( V_28 , V_35 , V_115 , V_36 , 0 , 0 ) ;
if ( V_10 -> V_60 ) {
F_49 ( V_28 , V_61 , V_142 ,
V_143 , 0 , 0 ) ;
F_49 ( V_28 , V_62 , V_144 ,
V_145 , 0 , 0 ) ;
}
F_50 ( V_28 , 2 , 0 ) ;
F_49 ( V_28 , V_51 , V_114 , V_116 , 0 , 0 ) ;
F_49 ( V_28 , V_52 , V_115 , V_36 , 0 , 0 ) ;
break;
case 4 :
if ( F_43 ( V_1 , & V_129 , & V_130 ) ) {
F_51 ( V_1 , L_17 ) ;
}
F_44 ( V_1 ) ;
F_45 ( V_59 , V_28 -> V_134 ) ;
F_49 ( V_28 , V_34 , V_114 , V_116 , 0 , 0 ) ;
F_49 ( V_28 , V_35 , V_115 , V_36 , 0 , 0 ) ;
F_52 ( V_28 , V_34 , V_129 ) ;
F_52 ( V_28 , V_35 , V_130 ) ;
F_49 ( V_28 , V_61 , V_142 ,
V_143 , 0 , 0 ) ;
F_49 ( V_28 , V_62 , V_144 ,
V_145 , 0 , 0 ) ;
F_50 ( V_28 , V_72 , 0 ) ;
F_49 ( V_28 , V_51 , V_114 , V_116 , 0 , 0 ) ;
F_49 ( V_28 , V_52 , V_115 , V_36 , 0 , 0 ) ;
F_52 ( V_28 , V_51 , V_129 ) ;
F_52 ( V_28 , V_52 , V_130 ) ;
F_49 ( V_28 , V_75 , V_142 ,
V_143 , 0 , 0 ) ;
F_49 ( V_28 , V_76 , 0 ,
V_145 * V_57 , 0 , 0 ) ;
break;
}
V_10 -> V_36 = V_36 ;
V_10 -> V_57 = V_57 ;
return 0 ;
}
static T_4 F_53 ( struct V_1 * V_1 , void * V_146 ,
char * V_147 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_148 * V_149 = V_146 ;
unsigned char * V_16 = ( unsigned char * ) V_10 + V_149 -> V_150 ;
int V_12 = 0 ;
if ( V_149 -> V_16 )
V_12 = F_9 ( V_1 , V_149 -> V_16 , V_16 ) ;
return sprintf ( V_147 , L_18 , ( V_149 -> V_16 && V_12 ) ? - 1 : * V_16 ) ;
}
static T_4 F_54 ( struct V_1 * V_1 ,
void * V_146 , const char * V_147 , T_5 V_151 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_148 * V_149 = V_146 ;
unsigned char * V_16 = ( unsigned char * ) V_10 + V_149 -> V_150 ;
unsigned char V_152 ;
int V_153 ;
V_153 = F_55 ( V_147 , 16 , & V_152 ) ;
if ( V_153 )
return V_153 ;
if ( V_10 -> V_18 == 1 ) {
if ( V_149 -> V_16 == 0x10 )
V_152 |= V_113 ;
else if ( V_149 -> V_16 == 0x11 )
V_152 |= V_154 ;
}
if ( ! V_149 -> V_16 || F_10 ( V_1 , V_149 -> V_16 , V_152 ) == 0 )
* V_16 = V_152 ;
return V_151 ;
}
static bool F_56 ( const unsigned char * V_3 )
{
static const unsigned char V_155 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 } ;
int V_23 ;
if ( V_3 [ 0 ] == 0 )
return false ;
if ( V_3 [ 1 ] == 0 )
return true ;
if ( ( V_3 [ 0 ] & 0x0f ) >= 0x06 && ( V_3 [ 1 ] & 0xaf ) == 0x0f &&
V_3 [ 2 ] < 40 )
return true ;
for ( V_23 = 0 ; V_23 < F_57 ( V_155 ) ; V_23 ++ )
if ( V_3 [ 2 ] == V_155 [ V_23 ] )
return false ;
return true ;
}
int F_58 ( struct V_1 * V_1 , bool V_156 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
unsigned char V_3 [ 3 ] ;
F_3 ( & V_1 -> V_4 , NULL , V_157 ) ;
if ( F_3 ( V_4 , NULL , V_158 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , V_3 , V_5 ) ) {
F_59 ( V_1 , L_19 ) ;
return - 1 ;
}
if ( V_3 [ 0 ] != 0x3c || V_3 [ 1 ] != 0x03 ||
( V_3 [ 2 ] != 0xc8 && V_3 [ 2 ] != 0x00 ) ) {
F_59 ( V_1 ,
L_20 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_159 , V_3 ) ) {
F_59 ( V_1 , L_21 ) ;
return - 1 ;
}
F_59 ( V_1 ,
L_22 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( ! F_56 ( V_3 ) ) {
F_59 ( V_1 ,
L_23 ) ;
return - 1 ;
}
if ( V_156 ) {
V_1 -> V_160 = L_24 ;
V_1 -> V_161 = L_25 ;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
if ( V_10 -> V_64 )
F_61 ( V_10 -> V_64 ) ;
F_62 ( & V_1 -> V_4 . V_162 -> V_28 . V_163 ,
& V_164 ) ;
F_63 ( V_1 -> V_11 ) ;
V_1 -> V_11 = NULL ;
}
static int F_64 ( struct V_1 * V_1 )
{
F_65 ( V_1 ) ;
if ( F_58 ( V_1 , 0 ) )
return - 1 ;
if ( F_40 ( V_1 ) ) {
F_4 ( V_1 ,
L_26 ) ;
return - 1 ;
}
return 0 ;
}
static int F_66 ( struct V_9 * V_10 )
{
int V_165 = ( V_10 -> V_30 & 0x0f0000 ) >> 16 ;
if ( V_10 -> V_30 < 0x020030 || V_10 -> V_30 == 0x020600 )
V_10 -> V_18 = 1 ;
else {
switch ( V_165 ) {
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
case 14 :
V_10 -> V_18 = 4 ;
break;
default:
return - 1 ;
}
}
V_10 -> V_126 = V_10 -> V_18 >= 3 ? F_5 :
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
F_48 ( V_166 ) ;
V_10 -> V_110 = ! F_48 ( V_167 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_1 )
{
struct V_9 * V_10 ;
int V_23 ;
int error = - V_168 ;
unsigned char V_3 [ 3 ] ;
struct V_27 * V_64 ;
V_1 -> V_11 = V_10 = F_68 ( sizeof( struct V_9 ) , V_169 ) ;
if ( ! V_10 )
return - V_170 ;
F_65 ( V_1 ) ;
V_10 -> V_91 [ 0 ] = 1 ;
for ( V_23 = 1 ; V_23 < 256 ; V_23 ++ )
V_10 -> V_91 [ V_23 ] = V_10 -> V_91 [ V_23 & ( V_23 - 1 ) ] ^ 1 ;
if ( F_1 ( V_1 , V_159 , V_3 ) ) {
F_4 ( V_1 , L_21 ) ;
goto V_171;
}
V_10 -> V_30 = ( V_3 [ 0 ] << 16 ) | ( V_3 [ 1 ] << 8 ) | V_3 [ 2 ] ;
if ( F_66 ( V_10 ) ) {
F_4 ( V_1 , L_27 ) ;
goto V_171;
}
F_69 ( V_1 ,
L_28 ,
V_10 -> V_18 , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( V_10 -> V_126 ( V_1 , V_172 ,
V_10 -> V_42 ) ) {
F_4 ( V_1 , L_29 ) ;
goto V_171;
}
F_69 ( V_1 ,
L_30 ,
V_10 -> V_42 [ 0 ] , V_10 -> V_42 [ 1 ] ,
V_10 -> V_42 [ 2 ] ) ;
if ( F_40 ( V_1 ) ) {
F_4 ( V_1 ,
L_31 ) ;
goto V_171;
}
if ( V_10 -> V_30 == 0x381f17 ) {
V_10 -> V_104 = V_1 -> V_173 ;
V_1 -> V_173 = F_39 ;
}
if ( F_47 ( V_1 ) ) {
F_4 ( V_1 , L_32 ) ;
goto V_171;
}
error = F_70 ( & V_1 -> V_4 . V_162 -> V_28 . V_163 ,
& V_164 ) ;
if ( error ) {
F_4 ( V_1 ,
L_33 ,
error ) ;
goto V_171;
}
if ( ( V_10 -> V_42 [ 0 ] & 0x80 ) == 0x80 ) {
V_64 = F_71 () ;
if ( ! V_64 ) {
error = - V_170 ;
goto V_174;
}
V_10 -> V_64 = V_64 ;
snprintf ( V_10 -> V_175 , sizeof( V_10 -> V_175 ) , L_34 ,
V_1 -> V_4 . V_162 -> V_176 ) ;
V_64 -> V_176 = V_10 -> V_175 ;
V_64 -> V_161 = L_35 ;
V_64 -> V_73 . V_177 = V_178 ;
V_64 -> V_73 . V_160 = 0x0002 ;
V_64 -> V_73 . V_179 = V_180 ;
V_64 -> V_73 . V_181 = 0x0000 ;
V_64 -> V_28 . V_182 = & V_1 -> V_4 . V_162 -> V_28 ;
V_64 -> V_137 [ 0 ] = F_72 ( V_136 ) | F_72 ( V_139 ) ;
V_64 -> V_183 [ F_73 ( V_67 ) ] =
F_72 ( V_67 ) | F_72 ( V_68 ) ;
V_64 -> V_134 [ F_73 ( V_40 ) ] =
F_72 ( V_40 ) | F_72 ( V_66 ) |
F_72 ( V_41 ) ;
F_45 ( V_135 , V_64 -> V_133 ) ;
F_45 ( V_184 , V_64 -> V_133 ) ;
error = F_74 ( V_10 -> V_64 ) ;
if ( error < 0 )
goto V_185;
}
V_1 -> V_186 = F_38 ;
V_1 -> V_187 = F_60 ;
V_1 -> V_188 = F_64 ;
V_1 -> V_25 = V_10 -> V_18 > 1 ? 6 : 4 ;
return 0 ;
V_185:
F_75 ( V_64 ) ;
V_174:
F_62 ( & V_1 -> V_4 . V_162 -> V_28 . V_163 ,
& V_164 ) ;
V_171:
F_65 ( V_1 ) ;
F_63 ( V_10 ) ;
return error ;
}
