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
F_12 ( V_23 , V_1 , L_6 ,
V_1 -> V_24 , V_1 -> V_25 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_27 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_25 = V_1 -> V_25 ;
int V_28 ;
if ( V_10 -> V_29 < 0x020000 ) {
V_28 = ( ( V_25 [ 1 ] & 0x80 ) >> 7 ) +
( ( V_25 [ 1 ] & 0x30 ) >> 4 ) ;
} else {
V_28 = ( V_25 [ 0 ] & 0xc0 ) >> 6 ;
}
if ( V_10 -> V_30 ) {
if ( V_28 != 1 ) {
V_10 -> V_31 = 0 ;
} else if ( V_10 -> V_31 < 2 ) {
V_10 -> V_31 ++ ;
F_7 ( L_7 ) ;
return;
}
}
F_14 ( V_27 , V_32 , V_28 != 0 ) ;
if ( V_28 ) {
F_15 ( V_27 , V_33 ,
( ( V_25 [ 1 ] & 0x0c ) << 6 ) | V_25 [ 2 ] ) ;
F_15 ( V_27 , V_34 ,
V_10 -> V_35 - ( ( ( V_25 [ 1 ] & 0x03 ) << 8 ) | V_25 [ 3 ] ) ) ;
}
F_14 ( V_27 , V_36 , V_28 == 1 ) ;
F_14 ( V_27 , V_37 , V_28 == 2 ) ;
F_14 ( V_27 , V_38 , V_28 == 3 ) ;
F_14 ( V_27 , V_39 , V_25 [ 0 ] & 0x01 ) ;
F_14 ( V_27 , V_40 , V_25 [ 0 ] & 0x02 ) ;
if ( V_10 -> V_29 < 0x020000 &&
( V_10 -> V_41 [ 0 ] & V_42 ) ) {
F_14 ( V_27 , V_43 , V_25 [ 0 ] & 0x40 ) ;
F_14 ( V_27 , V_44 , V_25 [ 0 ] & 0x80 ) ;
}
F_16 ( V_27 ) ;
}
static void F_17 ( struct V_26 * V_27 , int V_45 , bool V_46 ,
unsigned int V_47 , unsigned int V_48 )
{
F_18 ( V_27 , V_45 ) ;
F_19 ( V_27 , V_49 , V_46 ) ;
if ( V_46 ) {
F_15 ( V_27 , V_50 , V_47 ) ;
F_15 ( V_27 , V_51 , V_48 ) ;
}
}
static void F_20 ( struct V_26 * V_27 ,
unsigned int V_52 ,
unsigned int V_53 , unsigned int y1 ,
unsigned int V_54 , unsigned int V_55 )
{
F_17 ( V_27 , 0 , V_52 != 0 , V_53 , y1 ) ;
F_17 ( V_27 , 1 , V_52 >= 2 , V_54 , V_55 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_26 * V_27 = V_1 -> V_27 ;
unsigned char * V_25 = V_1 -> V_25 ;
unsigned int V_28 , V_53 = 0 , y1 = 0 , V_54 = 0 , V_55 = 0 ;
unsigned int V_56 = 0 , V_57 = 0 ;
V_28 = ( V_25 [ 0 ] & 0xc0 ) >> 6 ;
switch ( V_28 ) {
case 3 :
if ( V_25 [ 3 ] & 0x80 )
V_28 = 4 ;
case 1 :
V_53 = ( ( V_25 [ 1 ] & 0x0f ) << 8 ) | V_25 [ 2 ] ;
y1 = V_10 -> V_35 - ( ( ( V_25 [ 4 ] & 0x0f ) << 8 ) | V_25 [ 5 ] ) ;
V_57 = ( V_25 [ 1 ] & 0xf0 ) | ( ( V_25 [ 4 ] & 0xf0 ) >> 4 ) ;
V_56 = ( ( V_25 [ 0 ] & 0x30 ) >> 2 ) | ( ( V_25 [ 3 ] & 0x30 ) >> 4 ) ;
break;
case 2 :
V_53 = ( ( ( V_25 [ 0 ] & 0x10 ) << 4 ) | V_25 [ 1 ] ) << 2 ;
y1 = V_10 -> V_35 -
( ( ( ( V_25 [ 0 ] & 0x20 ) << 3 ) | V_25 [ 2 ] ) << 2 ) ;
V_54 = ( ( ( V_25 [ 3 ] & 0x10 ) << 4 ) | V_25 [ 4 ] ) << 2 ;
V_55 = V_10 -> V_35 -
( ( ( ( V_25 [ 3 ] & 0x20 ) << 3 ) | V_25 [ 5 ] ) << 2 ) ;
V_57 = 127 ;
V_56 = 7 ;
break;
}
F_14 ( V_27 , V_32 , V_28 != 0 ) ;
if ( V_28 != 0 ) {
F_15 ( V_27 , V_33 , V_53 ) ;
F_15 ( V_27 , V_34 , y1 ) ;
}
F_20 ( V_27 , V_28 , V_53 , y1 , V_54 , V_55 ) ;
F_14 ( V_27 , V_36 , V_28 == 1 ) ;
F_14 ( V_27 , V_37 , V_28 == 2 ) ;
F_14 ( V_27 , V_38 , V_28 == 3 ) ;
F_14 ( V_27 , V_58 , V_28 == 4 ) ;
F_14 ( V_27 , V_39 , V_25 [ 0 ] & 0x01 ) ;
F_14 ( V_27 , V_40 , V_25 [ 0 ] & 0x02 ) ;
if ( V_10 -> V_59 ) {
F_15 ( V_27 , V_60 , V_57 ) ;
F_15 ( V_27 , V_61 , V_56 ) ;
}
F_16 ( V_27 ) ;
}
static void F_22 ( struct V_1 * V_1 ,
int V_62 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_26 * V_63 = V_10 -> V_63 ;
unsigned char * V_25 = V_1 -> V_25 ;
int V_47 , V_48 ;
T_1 V_64 ;
V_64 = F_23 ( & V_25 [ 0 ] ) ;
switch ( V_64 & ~ 7U ) {
case 0x06000030U :
case 0x16008020U :
case 0x26800010U :
case 0x36808000U :
V_47 = V_25 [ 4 ] - ( int ) ( ( V_25 [ 1 ] ^ 0x80 ) << 1 ) ;
V_48 = ( int ) ( ( V_25 [ 2 ] ^ 0x80 ) << 1 ) - V_25 [ 5 ] ;
F_14 ( V_63 , V_39 , V_25 [ 0 ] & 0x01 ) ;
F_14 ( V_63 , V_40 , V_25 [ 0 ] & 0x02 ) ;
F_14 ( V_63 , V_65 , V_25 [ 0 ] & 0x04 ) ;
F_24 ( V_63 , V_66 , V_47 ) ;
F_24 ( V_63 , V_67 , V_48 ) ;
F_16 ( V_63 ) ;
break;
default:
if ( V_10 -> V_68 == 1 )
F_11 ( V_1 ) ;
break;
}
}
static void F_25 ( struct V_1 * V_1 ,
int V_62 )
{
struct V_26 * V_27 = V_1 -> V_27 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_25 = V_1 -> V_25 ;
unsigned int V_28 = 0 , V_53 = 0 , y1 = 0 , V_54 = 0 , V_55 = 0 ;
unsigned int V_56 = 0 , V_57 = 0 ;
V_28 = ( V_25 [ 0 ] & 0xc0 ) >> 6 ;
switch ( V_28 ) {
case 3 :
case 1 :
V_53 = ( ( V_25 [ 1 ] & 0x0f ) << 8 ) | V_25 [ 2 ] ;
y1 = V_10 -> V_35 - ( ( ( V_25 [ 4 ] & 0x0f ) << 8 ) | V_25 [ 5 ] ) ;
break;
case 2 :
if ( V_62 == V_69 ) {
V_10 -> V_70 [ 0 ] . V_47 = ( ( V_25 [ 1 ] & 0x0f ) << 8 ) | V_25 [ 2 ] ;
V_10 -> V_70 [ 0 ] . V_48 = V_10 -> V_35 -
( ( ( V_25 [ 4 ] & 0x0f ) << 8 ) | V_25 [ 5 ] ) ;
return;
}
V_53 = V_10 -> V_70 [ 0 ] . V_47 ;
y1 = V_10 -> V_70 [ 0 ] . V_48 ;
V_54 = ( ( V_25 [ 1 ] & 0x0f ) << 8 ) | V_25 [ 2 ] ;
V_55 = V_10 -> V_35 - ( ( ( V_25 [ 4 ] & 0x0f ) << 8 ) | V_25 [ 5 ] ) ;
break;
}
V_57 = ( V_25 [ 1 ] & 0xf0 ) | ( ( V_25 [ 4 ] & 0xf0 ) >> 4 ) ;
V_56 = ( ( V_25 [ 0 ] & 0x30 ) >> 2 ) | ( ( V_25 [ 3 ] & 0x30 ) >> 4 ) ;
F_14 ( V_27 , V_32 , V_28 != 0 ) ;
if ( V_28 != 0 ) {
F_15 ( V_27 , V_33 , V_53 ) ;
F_15 ( V_27 , V_34 , y1 ) ;
}
F_20 ( V_27 , V_28 , V_53 , y1 , V_54 , V_55 ) ;
F_14 ( V_27 , V_36 , V_28 == 1 ) ;
F_14 ( V_27 , V_37 , V_28 == 2 ) ;
F_14 ( V_27 , V_38 , V_28 == 3 ) ;
if ( V_10 -> V_29 & 0x001000 ) {
F_14 ( V_27 , V_39 , V_25 [ 0 ] & 0x03 ) ;
} else {
F_14 ( V_27 , V_39 , V_25 [ 0 ] & 0x01 ) ;
F_14 ( V_27 , V_40 , V_25 [ 0 ] & 0x02 ) ;
}
F_15 ( V_27 , V_60 , V_57 ) ;
F_15 ( V_27 , V_61 , V_56 ) ;
F_16 ( V_27 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_27 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_25 = V_1 -> V_25 ;
if ( V_10 -> V_29 & 0x001000 ) {
F_14 ( V_27 , V_39 , V_25 [ 0 ] & 0x03 ) ;
} else {
F_14 ( V_27 , V_39 , V_25 [ 0 ] & 0x01 ) ;
F_14 ( V_27 , V_40 , V_25 [ 0 ] & 0x02 ) ;
F_14 ( V_27 , V_65 , V_25 [ 0 ] & 0x04 ) ;
}
F_27 ( V_27 , true ) ;
F_16 ( V_27 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_27 ;
unsigned char * V_25 = V_1 -> V_25 ;
unsigned V_28 ;
int V_71 ;
V_28 = V_25 [ 1 ] & 0x1f ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
if ( ( V_28 & ( 1 << V_71 ) ) == 0 ) {
F_18 ( V_27 , V_71 ) ;
F_19 ( V_27 , V_49 , false ) ;
}
}
F_26 ( V_1 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_27 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_25 = V_1 -> V_25 ;
int V_73 = ( ( V_25 [ 3 ] & 0xe0 ) >> 5 ) - 1 ;
int V_57 , V_74 ;
if ( V_73 < 0 )
return;
V_10 -> V_70 [ V_73 ] . V_47 = ( ( V_25 [ 1 ] & 0x0f ) << 8 ) | V_25 [ 2 ] ;
V_10 -> V_70 [ V_73 ] . V_48 = V_10 -> V_35 - ( ( ( V_25 [ 4 ] & 0x0f ) << 8 ) | V_25 [ 5 ] ) ;
V_57 = ( V_25 [ 1 ] & 0xf0 ) | ( ( V_25 [ 4 ] & 0xf0 ) >> 4 ) ;
V_74 = ( V_25 [ 0 ] & 0xf0 ) >> 4 ;
F_18 ( V_27 , V_73 ) ;
F_19 ( V_27 , V_49 , true ) ;
F_15 ( V_27 , V_50 , V_10 -> V_70 [ V_73 ] . V_47 ) ;
F_15 ( V_27 , V_51 , V_10 -> V_70 [ V_73 ] . V_48 ) ;
F_15 ( V_27 , V_75 , V_57 ) ;
F_15 ( V_27 , V_76 , V_74 * V_10 -> V_56 ) ;
F_15 ( V_27 , V_61 , V_74 ) ;
F_26 ( V_1 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_27 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_25 = V_1 -> V_25 ;
int V_77 , V_78 = 0 , V_79 = 0 , V_80 = 0 , V_81 = 0 ;
int V_73 , V_82 ;
V_73 = ( ( V_25 [ 0 ] & 0xe0 ) >> 5 ) - 1 ;
if ( V_73 < 0 )
return;
V_82 = ( ( V_25 [ 3 ] & 0xe0 ) >> 5 ) - 1 ;
V_77 = ( V_25 [ 0 ] & 0x10 ) ? V_83 : 1 ;
V_78 = ( signed char ) V_25 [ 1 ] ;
V_79 = ( signed char ) V_25 [ 2 ] ;
V_80 = ( signed char ) V_25 [ 4 ] ;
V_81 = ( signed char ) V_25 [ 5 ] ;
V_10 -> V_70 [ V_73 ] . V_47 += V_78 * V_77 ;
V_10 -> V_70 [ V_73 ] . V_48 -= V_79 * V_77 ;
F_18 ( V_27 , V_73 ) ;
F_15 ( V_27 , V_50 , V_10 -> V_70 [ V_73 ] . V_47 ) ;
F_15 ( V_27 , V_51 , V_10 -> V_70 [ V_73 ] . V_48 ) ;
if ( V_82 >= 0 ) {
V_10 -> V_70 [ V_82 ] . V_47 += V_80 * V_77 ;
V_10 -> V_70 [ V_82 ] . V_48 -= V_81 * V_77 ;
F_18 ( V_27 , V_82 ) ;
F_15 ( V_27 , V_50 , V_10 -> V_70 [ V_82 ] . V_47 ) ;
F_15 ( V_27 , V_51 , V_10 -> V_70 [ V_82 ] . V_48 ) ;
}
F_26 ( V_1 ) ;
}
static void F_31 ( struct V_1 * V_1 ,
int V_62 )
{
switch ( V_62 ) {
case V_84 :
F_28 ( V_1 ) ;
break;
case V_85 :
F_29 ( V_1 ) ;
break;
case V_86 :
F_30 ( V_1 ) ;
break;
case V_87 :
default:
break;
}
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_25 = V_1 -> V_25 ;
unsigned char V_88 , V_89 , V_90 ;
if ( V_10 -> V_29 < 0x020000 ) {
V_88 = ( V_25 [ 0 ] & 0x20 ) >> 5 ;
V_89 = ( V_25 [ 0 ] & 0x10 ) >> 4 ;
} else {
V_88 = ( V_25 [ 0 ] & 0x10 ) >> 4 ;
V_89 = ( V_25 [ 0 ] & 0x20 ) >> 5 ;
}
V_90 = ( V_25 [ 0 ] & 0x04 ) >> 2 ;
return V_10 -> V_91 [ V_25 [ 1 ] ] == V_88 &&
V_10 -> V_91 [ V_25 [ 2 ] ] == V_89 &&
V_10 -> V_91 [ V_25 [ 3 ] ] == V_90 ;
}
static int F_33 ( struct V_1 * V_1 )
{
const T_2 V_92 [] = { 0x84 , 0xff , 0xff , 0x02 , 0xff , 0xff } ;
unsigned char * V_25 = V_1 -> V_25 ;
return ! memcmp ( V_25 , V_92 , sizeof( V_92 ) ) ;
}
static int F_34 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_25 = V_1 -> V_25 ;
if ( V_10 -> V_59 )
return ( V_25 [ 0 ] & 0x0c ) == 0x04 &&
( V_25 [ 3 ] & 0x0f ) == 0x02 ;
if ( ( V_25 [ 0 ] & 0xc0 ) == 0x80 )
return ( V_25 [ 0 ] & 0x0c ) == 0x0c &&
( V_25 [ 3 ] & 0x0e ) == 0x08 ;
return ( V_25 [ 0 ] & 0x3c ) == 0x3c &&
( V_25 [ 1 ] & 0xf0 ) == 0x00 &&
( V_25 [ 3 ] & 0x3e ) == 0x38 &&
( V_25 [ 4 ] & 0xf0 ) == 0x00 ;
}
static int F_35 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
const T_2 V_92 [] = { 0xc4 , 0xff , 0xff , 0x02 , 0xff , 0xff } ;
unsigned char * V_25 = V_1 -> V_25 ;
if ( ! memcmp ( V_25 , V_92 , sizeof( V_92 ) ) )
return V_93 ;
if ( V_10 -> V_94 ) {
if ( ( V_25 [ 3 ] & 0x09 ) == 0x08 )
return V_69 ;
if ( ( V_25 [ 3 ] & 0x09 ) == 0x09 )
return V_95 ;
} else {
if ( ( V_25 [ 0 ] & 0x0c ) == 0x04 && ( V_25 [ 3 ] & 0xcf ) == 0x02 )
return V_69 ;
if ( ( V_25 [ 0 ] & 0x0c ) == 0x0c && ( V_25 [ 3 ] & 0xce ) == 0x0c )
return V_95 ;
if ( ( V_25 [ 3 ] & 0x0f ) == 0x06 )
return V_96 ;
}
return V_87 ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_25 = V_1 -> V_25 ;
unsigned char V_62 = V_25 [ 3 ] & 0x03 ;
unsigned int V_97 ;
bool V_98 ;
if ( V_10 -> V_63 && ( V_25 [ 3 ] & 0x0f ) == 0x06 )
return V_96 ;
V_97 = ( V_10 -> V_29 & 0x0f0000 ) >> 16 ;
if ( V_10 -> V_94 )
V_98 = ( ( V_25 [ 3 ] & 0x08 ) == 0x00 ) ;
else if ( V_97 == 7 && V_10 -> V_99 [ 1 ] == 0x2A )
V_98 = ( ( V_25 [ 3 ] & 0x1c ) == 0x10 ) ;
else
V_98 = ( ( V_25 [ 0 ] & 0x0c ) == 0x04 &&
( V_25 [ 3 ] & 0x1c ) == 0x10 ) ;
if ( ! V_98 )
return V_87 ;
switch ( V_62 ) {
case 0 :
return V_84 ;
case 1 :
return V_85 ;
case 2 :
return V_86 ;
}
return V_87 ;
}
static T_3 F_37 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
int V_62 ;
if ( V_1 -> V_100 < V_1 -> V_24 )
return V_101 ;
if ( V_10 -> V_68 > 1 )
F_11 ( V_1 ) ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( V_10 -> V_102 && ! F_32 ( V_1 ) )
return V_103 ;
F_13 ( V_1 ) ;
break;
case 2 :
if ( F_33 ( V_1 ) )
return V_104 ;
if ( V_10 -> V_102 && ! F_34 ( V_1 ) )
return V_103 ;
F_21 ( V_1 ) ;
break;
case 3 :
V_62 = F_35 ( V_1 ) ;
switch ( V_62 ) {
case V_87 :
return V_103 ;
case V_93 :
break;
case V_96 :
F_22 ( V_1 , V_62 ) ;
break;
default:
F_25 ( V_1 , V_62 ) ;
break;
}
break;
case 4 :
V_62 = F_36 ( V_1 ) ;
switch ( V_62 ) {
case V_87 :
return V_103 ;
case V_96 :
F_22 ( V_1 , V_62 ) ;
break;
default:
F_31 ( V_1 , V_62 ) ;
break;
}
break;
}
return V_104 ;
}
static void F_38 ( struct V_1 * V_1 ,
unsigned int V_105 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
V_10 -> V_106 ( V_1 , V_105 ) ;
if ( F_10 ( V_1 , 0x07 , V_10 -> V_107 ) )
F_4 ( V_1 , L_8 ) ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_17 ;
int V_13 = V_108 ;
int V_12 = 0 ;
switch ( V_10 -> V_18 ) {
case 1 :
V_10 -> V_109 = 0x16 ;
V_10 -> V_110 = 0x8f ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_109 ) ||
F_10 ( V_1 , 0x11 , V_10 -> V_110 ) ) {
V_12 = - 1 ;
}
break;
case 2 :
V_10 -> V_109 = 0x54 ;
V_10 -> V_110 = 0x88 ;
V_10 -> V_111 = 0x60 ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_109 ) ||
F_10 ( V_1 , 0x11 , V_10 -> V_110 ) ||
F_10 ( V_1 , 0x21 , V_10 -> V_111 ) ) {
V_12 = - 1 ;
}
break;
case 3 :
if ( V_10 -> V_112 )
V_10 -> V_109 = 0x0b ;
else
V_10 -> V_109 = 0x01 ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_109 ) )
V_12 = - 1 ;
break;
case 4 :
V_10 -> V_107 = 0x01 ;
if ( F_10 ( V_1 , 0x07 , V_10 -> V_107 ) )
V_12 = - 1 ;
goto V_113;
}
if ( V_12 == 0 ) {
do {
V_12 = F_9 ( V_1 , 0x10 , & V_17 ) ;
if ( V_12 == 0 )
break;
V_13 -- ;
F_7 ( L_9 , V_13 ) ;
F_8 ( V_114 ) ;
} while ( V_13 > 0 );
if ( V_12 ) {
F_4 ( V_1 ,
L_10 ) ;
} else if ( V_10 -> V_18 == 1 &&
! ( V_17 & V_115 ) ) {
F_4 ( V_1 ,
L_11 ) ;
V_12 = - 1 ;
}
}
V_113:
if ( V_12 )
F_4 ( V_1 , L_12 ) ;
return V_12 ;
}
static int F_40 ( struct V_1 * V_1 ,
unsigned int * V_116 , unsigned int * V_117 ,
unsigned int * V_118 , unsigned int * V_35 ,
unsigned int * V_56 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_3 [ 3 ] ;
unsigned char V_74 ;
switch ( V_10 -> V_18 ) {
case 1 :
* V_116 = V_119 ;
* V_117 = V_120 ;
* V_118 = V_121 ;
* V_35 = V_122 ;
break;
case 2 :
if ( V_10 -> V_29 == 0x020800 ||
V_10 -> V_29 == 0x020b00 ||
V_10 -> V_29 == 0x020030 ) {
* V_116 = V_123 ;
* V_117 = V_124 ;
* V_118 = V_125 ;
* V_35 = V_126 ;
} else {
int V_71 ;
int V_127 ;
V_71 = ( V_10 -> V_29 > 0x020800 &&
V_10 -> V_29 < 0x020900 ) ? 1 : 2 ;
if ( V_10 -> V_128 ( V_1 , V_129 , V_3 ) )
return - 1 ;
V_127 = V_3 [ 1 ] & 0x10 ;
if ( ( ( V_10 -> V_29 >> 16 ) == 0x14 ) && V_127 ) {
if ( V_10 -> V_128 ( V_1 , V_130 , V_3 ) )
return - 1 ;
* V_118 = ( V_10 -> V_41 [ 1 ] - V_71 ) * V_3 [ 1 ] / 2 ;
* V_35 = ( V_10 -> V_41 [ 2 ] - V_71 ) * V_3 [ 2 ] / 2 ;
} else if ( V_10 -> V_29 == 0x040216 ) {
* V_118 = 819 ;
* V_35 = 405 ;
} else if ( V_10 -> V_29 == 0x040219 || V_10 -> V_29 == 0x040215 ) {
* V_118 = 900 ;
* V_35 = 500 ;
} else {
* V_118 = ( V_10 -> V_41 [ 1 ] - V_71 ) * 64 ;
* V_35 = ( V_10 -> V_41 [ 2 ] - V_71 ) * 64 ;
}
}
break;
case 3 :
if ( V_10 -> V_128 ( V_1 , V_129 , V_3 ) )
return - 1 ;
* V_118 = ( 0x0f & V_3 [ 0 ] ) << 8 | V_3 [ 1 ] ;
* V_35 = ( 0xf0 & V_3 [ 0 ] ) << 4 | V_3 [ 2 ] ;
break;
case 4 :
if ( V_10 -> V_128 ( V_1 , V_129 , V_3 ) )
return - 1 ;
* V_118 = ( 0x0f & V_3 [ 0 ] ) << 8 | V_3 [ 1 ] ;
* V_35 = ( 0xf0 & V_3 [ 0 ] ) << 4 | V_3 [ 2 ] ;
V_74 = V_10 -> V_41 [ 1 ] ;
if ( ( V_74 < 2 ) || ( V_74 > * V_118 ) )
return - 1 ;
* V_56 = * V_118 / ( V_74 - 1 ) ;
break;
}
return 0 ;
}
static unsigned int F_41 ( unsigned int V_17 )
{
return ( V_17 * 10 + 790 ) * 10 / 254 ;
}
static int F_42 ( struct V_1 * V_1 ,
unsigned int * V_131 ,
unsigned int * V_132 )
{
unsigned char V_3 [ 3 ] ;
if ( F_5 ( V_1 , V_133 , V_3 ) )
return - 1 ;
* V_131 = F_41 ( V_3 [ 1 ] & 0x0f ) ;
* V_132 = F_41 ( ( V_3 [ 1 ] & 0xf0 ) >> 4 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_27 ;
struct V_9 * V_10 = V_1 -> V_11 ;
if ( V_10 -> V_29 & 0x001000 ) {
F_44 ( V_134 , V_27 -> V_135 ) ;
F_45 ( V_40 , V_27 -> V_136 ) ;
}
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_27 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned int V_116 = 0 , V_117 = 0 , V_118 = 0 , V_35 = 0 , V_56 = 0 ;
unsigned int V_131 = 31 , V_132 = 31 ;
if ( F_40 ( V_1 , & V_116 , & V_117 , & V_118 , & V_35 , & V_56 ) )
return - 1 ;
F_44 ( V_137 , V_27 -> V_135 ) ;
F_44 ( V_138 , V_27 -> V_139 ) ;
F_44 ( V_140 , V_27 -> V_139 ) ;
F_45 ( V_141 , V_27 -> V_139 ) ;
F_44 ( V_39 , V_27 -> V_136 ) ;
if ( F_47 ( V_142 ) )
F_44 ( V_65 , V_27 -> V_136 ) ;
F_44 ( V_40 , V_27 -> V_136 ) ;
F_44 ( V_32 , V_27 -> V_136 ) ;
F_44 ( V_36 , V_27 -> V_136 ) ;
F_44 ( V_37 , V_27 -> V_136 ) ;
F_44 ( V_38 , V_27 -> V_136 ) ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( V_10 -> V_29 < 0x020000 &&
( V_10 -> V_41 [ 0 ] & V_42 ) ) {
F_44 ( V_43 , V_27 -> V_136 ) ;
F_44 ( V_44 , V_27 -> V_136 ) ;
}
F_48 ( V_27 , V_33 , V_116 , V_118 , 0 , 0 ) ;
F_48 ( V_27 , V_34 , V_117 , V_35 , 0 , 0 ) ;
break;
case 2 :
F_44 ( V_58 , V_27 -> V_136 ) ;
F_44 ( V_143 , V_27 -> V_135 ) ;
case 3 :
if ( V_10 -> V_18 == 3 )
F_43 ( V_1 ) ;
F_48 ( V_27 , V_33 , V_116 , V_118 , 0 , 0 ) ;
F_48 ( V_27 , V_34 , V_117 , V_35 , 0 , 0 ) ;
if ( V_10 -> V_59 ) {
F_48 ( V_27 , V_60 , V_144 ,
V_145 , 0 , 0 ) ;
F_48 ( V_27 , V_61 , V_146 ,
V_147 , 0 , 0 ) ;
}
F_49 ( V_27 , 2 , V_148 ) ;
F_48 ( V_27 , V_50 , V_116 , V_118 , 0 , 0 ) ;
F_48 ( V_27 , V_51 , V_117 , V_35 , 0 , 0 ) ;
break;
case 4 :
if ( F_42 ( V_1 , & V_131 , & V_132 ) ) {
F_50 ( V_1 , L_13 ) ;
}
F_43 ( V_1 ) ;
F_44 ( V_58 , V_27 -> V_136 ) ;
F_48 ( V_27 , V_33 , V_116 , V_118 , 0 , 0 ) ;
F_48 ( V_27 , V_34 , V_117 , V_35 , 0 , 0 ) ;
F_48 ( V_27 , V_60 , V_144 ,
V_145 , 0 , 0 ) ;
F_48 ( V_27 , V_61 , V_146 ,
V_147 , 0 , 0 ) ;
F_49 ( V_27 , V_72 , 0 ) ;
F_48 ( V_27 , V_50 , V_116 , V_118 , 0 , 0 ) ;
F_48 ( V_27 , V_51 , V_117 , V_35 , 0 , 0 ) ;
F_48 ( V_27 , V_75 , V_144 ,
V_145 , 0 , 0 ) ;
F_48 ( V_27 , V_76 , 0 ,
V_147 * V_56 , 0 , 0 ) ;
break;
}
F_51 ( V_27 , V_33 , V_131 ) ;
F_51 ( V_27 , V_34 , V_132 ) ;
if ( V_10 -> V_18 > 1 ) {
F_51 ( V_27 , V_50 , V_131 ) ;
F_51 ( V_27 , V_51 , V_132 ) ;
}
V_10 -> V_35 = V_35 ;
V_10 -> V_56 = V_56 ;
return 0 ;
}
static T_4 F_52 ( struct V_1 * V_1 , void * V_149 ,
char * V_150 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_151 * V_152 = V_149 ;
unsigned char * V_16 = ( unsigned char * ) V_10 + V_152 -> V_153 ;
int V_12 = 0 ;
if ( V_152 -> V_16 )
V_12 = F_9 ( V_1 , V_152 -> V_16 , V_16 ) ;
return sprintf ( V_150 , L_14 , ( V_152 -> V_16 && V_12 ) ? - 1 : * V_16 ) ;
}
static T_4 F_53 ( struct V_1 * V_1 ,
void * V_149 , const char * V_150 , T_5 V_154 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_151 * V_152 = V_149 ;
unsigned char * V_16 = ( unsigned char * ) V_10 + V_152 -> V_153 ;
unsigned char V_155 ;
int V_156 ;
V_156 = F_54 ( V_150 , 16 , & V_155 ) ;
if ( V_156 )
return V_156 ;
if ( V_10 -> V_18 == 1 ) {
if ( V_152 -> V_16 == 0x10 )
V_155 |= V_115 ;
else if ( V_152 -> V_16 == 0x11 )
V_155 |= V_157 ;
}
if ( ! V_152 -> V_16 || F_10 ( V_1 , V_152 -> V_16 , V_155 ) == 0 )
* V_16 = V_155 ;
return V_154 ;
}
static bool F_55 ( const unsigned char * V_3 )
{
static const unsigned char V_158 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 } ;
int V_71 ;
if ( V_3 [ 0 ] == 0 )
return false ;
if ( V_3 [ 1 ] == 0 )
return true ;
if ( ( V_3 [ 0 ] & 0x0f ) >= 0x06 && ( V_3 [ 1 ] & 0xaf ) == 0x0f &&
V_3 [ 2 ] < 40 )
return true ;
for ( V_71 = 0 ; V_71 < F_56 ( V_158 ) ; V_71 ++ )
if ( V_3 [ 2 ] == V_158 [ V_71 ] )
return false ;
return true ;
}
int F_57 ( struct V_1 * V_1 , bool V_159 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
unsigned char V_3 [ 3 ] ;
F_3 ( V_4 , NULL , V_160 ) ;
if ( F_3 ( V_4 , NULL , V_161 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , V_3 , V_5 ) ) {
F_58 ( V_1 , L_15 ) ;
return - 1 ;
}
if ( V_3 [ 0 ] != 0x3c || V_3 [ 1 ] != 0x03 ||
( V_3 [ 2 ] != 0xc8 && V_3 [ 2 ] != 0x00 ) ) {
F_58 ( V_1 ,
L_16 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_162 , V_3 ) ) {
F_58 ( V_1 , L_17 ) ;
return - 1 ;
}
F_58 ( V_1 ,
L_18 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( ! F_55 ( V_3 ) ) {
F_58 ( V_1 ,
L_19 ) ;
return - 1 ;
}
if ( V_159 ) {
V_1 -> V_163 = L_20 ;
V_1 -> V_164 = L_21 ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
if ( V_10 -> V_63 )
F_60 ( V_10 -> V_63 ) ;
F_61 ( & V_1 -> V_4 . V_165 -> V_27 . V_166 ,
& V_167 ) ;
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
L_22 ) ;
return - 1 ;
}
return 0 ;
}
static int F_65 ( struct V_9 * V_10 )
{
int V_168 = ( V_10 -> V_29 & 0x0f0000 ) >> 16 ;
if ( V_10 -> V_29 < 0x020030 || V_10 -> V_29 == 0x020600 )
V_10 -> V_18 = 1 ;
else {
switch ( V_168 ) {
case 2 :
case 4 :
V_10 -> V_18 = 2 ;
break;
case 5 :
V_10 -> V_18 = 3 ;
break;
case 6 ... 14 :
V_10 -> V_18 = 4 ;
break;
default:
return - 1 ;
}
}
V_10 -> V_128 = V_10 -> V_18 >= 3 ? F_5 :
F_1 ;
V_10 -> V_102 = 1 ;
V_10 -> V_30 =
( V_10 -> V_29 == 0x020022 || V_10 -> V_29 == 0x020600 ) ;
if ( V_10 -> V_18 > 1 ) {
V_10 -> V_68 = 1 ;
if ( V_10 -> V_29 >= 0x020800 )
V_10 -> V_59 = true ;
}
V_10 -> V_94 = ( V_10 -> V_29 & 0x4000 ) == 0x4000 ||
F_47 ( V_169 ) ;
V_10 -> V_112 = ! F_47 ( V_170 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_1 )
{
struct V_9 * V_10 ;
int V_71 ;
int error = - V_171 ;
unsigned char V_3 [ 3 ] ;
struct V_26 * V_63 ;
V_1 -> V_11 = V_10 = F_67 ( sizeof( struct V_9 ) , V_172 ) ;
if ( ! V_10 )
return - V_173 ;
F_64 ( V_1 ) ;
V_10 -> V_91 [ 0 ] = 1 ;
for ( V_71 = 1 ; V_71 < 256 ; V_71 ++ )
V_10 -> V_91 [ V_71 ] = V_10 -> V_91 [ V_71 & ( V_71 - 1 ) ] ^ 1 ;
if ( F_1 ( V_1 , V_162 , V_3 ) ) {
F_4 ( V_1 , L_17 ) ;
goto V_174;
}
V_10 -> V_29 = ( V_3 [ 0 ] << 16 ) | ( V_3 [ 1 ] << 8 ) | V_3 [ 2 ] ;
if ( F_65 ( V_10 ) ) {
F_4 ( V_1 , L_23 ) ;
goto V_174;
}
F_68 ( V_1 ,
L_24 ,
V_10 -> V_18 , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( V_10 -> V_128 ( V_1 , V_175 ,
V_10 -> V_41 ) ) {
F_4 ( V_1 , L_25 ) ;
goto V_174;
}
F_68 ( V_1 ,
L_26 ,
V_10 -> V_41 [ 0 ] , V_10 -> V_41 [ 1 ] ,
V_10 -> V_41 [ 2 ] ) ;
if ( V_10 -> V_18 != 1 ) {
if ( V_10 -> V_128 ( V_1 , V_130 , V_10 -> V_99 ) ) {
F_4 ( V_1 , L_27 ) ;
goto V_174;
}
F_68 ( V_1 ,
L_28 ,
V_10 -> V_99 [ 0 ] , V_10 -> V_99 [ 1 ] , V_10 -> V_99 [ 2 ] ) ;
}
if ( V_10 -> V_99 [ 1 ] == 0x74 && V_10 -> V_18 == 0x03 ) {
F_68 ( V_1 ,
L_29 ) ;
goto V_174;
}
if ( F_39 ( V_1 ) ) {
F_4 ( V_1 ,
L_30 ) ;
goto V_174;
}
if ( V_10 -> V_29 == 0x381f17 ) {
V_10 -> V_106 = V_1 -> V_176 ;
V_1 -> V_176 = F_38 ;
}
if ( F_46 ( V_1 ) ) {
F_4 ( V_1 , L_31 ) ;
goto V_174;
}
error = F_69 ( & V_1 -> V_4 . V_165 -> V_27 . V_166 ,
& V_167 ) ;
if ( error ) {
F_4 ( V_1 ,
L_32 ,
error ) ;
goto V_174;
}
if ( ( V_10 -> V_41 [ 0 ] & 0x80 ) == 0x80 ) {
V_63 = F_70 () ;
if ( ! V_63 ) {
error = - V_173 ;
goto V_177;
}
V_10 -> V_63 = V_63 ;
snprintf ( V_10 -> V_178 , sizeof( V_10 -> V_178 ) , L_33 ,
V_1 -> V_4 . V_165 -> V_179 ) ;
V_63 -> V_179 = V_10 -> V_178 ;
V_63 -> V_164 = L_34 ;
V_63 -> V_73 . V_180 = V_181 ;
V_63 -> V_73 . V_163 = 0x0002 ;
V_63 -> V_73 . V_182 = V_183 ;
V_63 -> V_73 . V_184 = 0x0000 ;
V_63 -> V_27 . V_185 = & V_1 -> V_4 . V_165 -> V_27 ;
V_63 -> V_139 [ 0 ] = F_71 ( V_138 ) | F_71 ( V_141 ) ;
V_63 -> V_186 [ F_72 ( V_66 ) ] =
F_71 ( V_66 ) | F_71 ( V_67 ) ;
V_63 -> V_136 [ F_72 ( V_39 ) ] =
F_71 ( V_39 ) | F_71 ( V_65 ) |
F_71 ( V_40 ) ;
F_44 ( V_137 , V_63 -> V_135 ) ;
F_44 ( V_187 , V_63 -> V_135 ) ;
error = F_73 ( V_10 -> V_63 ) ;
if ( error < 0 )
goto V_188;
}
V_1 -> V_189 = F_37 ;
V_1 -> V_190 = F_59 ;
V_1 -> V_191 = F_63 ;
V_1 -> V_24 = V_10 -> V_18 > 1 ? 6 : 4 ;
return 0 ;
V_188:
F_74 ( V_63 ) ;
V_177:
F_61 ( & V_1 -> V_4 . V_165 -> V_27 . V_166 ,
& V_167 ) ;
V_174:
F_64 ( V_1 ) ;
F_62 ( V_10 ) ;
return error ;
}
