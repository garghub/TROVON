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
if ( V_63 == V_64 ) {
V_10 -> V_65 [ 0 ] . V_48 = ( ( V_26 [ 1 ] & 0x0f ) << 8 ) | V_26 [ 2 ] ;
V_10 -> V_65 [ 0 ] . V_49 = V_10 -> V_36 -
( ( ( V_26 [ 4 ] & 0x0f ) << 8 ) | V_26 [ 5 ] ) ;
return;
}
V_54 = V_10 -> V_65 [ 0 ] . V_48 ;
y1 = V_10 -> V_65 [ 0 ] . V_49 ;
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
F_15 ( V_28 , V_40 , V_26 [ 0 ] & 0x01 ) ;
F_15 ( V_28 , V_41 , V_26 [ 0 ] & 0x02 ) ;
F_16 ( V_28 , V_61 , V_58 ) ;
F_16 ( V_28 , V_62 , V_57 ) ;
F_17 ( V_28 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
unsigned char * V_26 = V_1 -> V_26 ;
F_15 ( V_28 , V_40 , V_26 [ 0 ] & 0x01 ) ;
F_25 ( V_28 , true ) ;
F_17 ( V_28 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
unsigned char * V_26 = V_1 -> V_26 ;
unsigned V_29 ;
int V_23 ;
V_29 = V_26 [ 1 ] & 0x1f ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
if ( ( V_29 & ( 1 << V_23 ) ) == 0 ) {
F_19 ( V_28 , V_23 ) ;
F_20 ( V_28 , V_50 , false ) ;
}
}
F_24 ( V_1 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
int V_67 = ( ( V_26 [ 3 ] & 0xe0 ) >> 5 ) - 1 ;
int V_58 , V_68 ;
if ( V_67 < 0 )
return;
V_10 -> V_65 [ V_67 ] . V_48 = ( ( V_26 [ 1 ] & 0x0f ) << 8 ) | V_26 [ 2 ] ;
V_10 -> V_65 [ V_67 ] . V_49 = V_10 -> V_36 - ( ( ( V_26 [ 4 ] & 0x0f ) << 8 ) | V_26 [ 5 ] ) ;
V_58 = ( V_26 [ 1 ] & 0xf0 ) | ( ( V_26 [ 4 ] & 0xf0 ) >> 4 ) ;
V_68 = ( V_26 [ 0 ] & 0xf0 ) >> 4 ;
F_19 ( V_28 , V_67 ) ;
F_20 ( V_28 , V_50 , true ) ;
F_16 ( V_28 , V_51 , V_10 -> V_65 [ V_67 ] . V_48 ) ;
F_16 ( V_28 , V_52 , V_10 -> V_65 [ V_67 ] . V_49 ) ;
F_16 ( V_28 , V_69 , V_58 ) ;
F_16 ( V_28 , V_70 , V_68 * V_10 -> V_57 ) ;
F_16 ( V_28 , V_62 , V_68 ) ;
F_24 ( V_1 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
int V_71 , V_72 = 0 , V_73 = 0 , V_74 = 0 , V_75 = 0 ;
int V_67 , V_76 ;
V_67 = ( ( V_26 [ 0 ] & 0xe0 ) >> 5 ) - 1 ;
if ( V_67 < 0 )
return;
V_76 = ( ( V_26 [ 3 ] & 0xe0 ) >> 5 ) - 1 ;
V_71 = ( V_26 [ 0 ] & 0x10 ) ? V_77 : 1 ;
V_72 = ( signed char ) V_26 [ 1 ] ;
V_73 = ( signed char ) V_26 [ 2 ] ;
V_74 = ( signed char ) V_26 [ 4 ] ;
V_75 = ( signed char ) V_26 [ 5 ] ;
V_10 -> V_65 [ V_67 ] . V_48 += V_72 * V_71 ;
V_10 -> V_65 [ V_67 ] . V_49 -= V_73 * V_71 ;
F_19 ( V_28 , V_67 ) ;
F_16 ( V_28 , V_51 , V_10 -> V_65 [ V_67 ] . V_48 ) ;
F_16 ( V_28 , V_52 , V_10 -> V_65 [ V_67 ] . V_49 ) ;
if ( V_76 >= 0 ) {
V_10 -> V_65 [ V_76 ] . V_48 += V_74 * V_71 ;
V_10 -> V_65 [ V_76 ] . V_49 -= V_75 * V_71 ;
F_19 ( V_28 , V_76 ) ;
F_16 ( V_28 , V_51 , V_10 -> V_65 [ V_76 ] . V_48 ) ;
F_16 ( V_28 , V_52 , V_10 -> V_65 [ V_76 ] . V_49 ) ;
}
F_24 ( V_1 ) ;
}
static void F_29 ( struct V_1 * V_1 ,
int V_63 )
{
switch ( V_63 ) {
case V_78 :
F_26 ( V_1 ) ;
break;
case V_79 :
F_27 ( V_1 ) ;
break;
case V_80 :
F_28 ( V_1 ) ;
break;
case V_81 :
default:
break;
}
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char * V_26 = V_1 -> V_26 ;
unsigned char V_82 , V_83 , V_84 ;
if ( V_10 -> V_30 < 0x020000 ) {
V_82 = ( V_26 [ 0 ] & 0x20 ) >> 5 ;
V_83 = ( V_26 [ 0 ] & 0x10 ) >> 4 ;
} else {
V_82 = ( V_26 [ 0 ] & 0x10 ) >> 4 ;
V_83 = ( V_26 [ 0 ] & 0x20 ) >> 5 ;
}
V_84 = ( V_26 [ 0 ] & 0x04 ) >> 2 ;
return V_10 -> V_85 [ V_26 [ 1 ] ] == V_82 &&
V_10 -> V_85 [ V_26 [ 2 ] ] == V_83 &&
V_10 -> V_85 [ V_26 [ 3 ] ] == V_84 ;
}
static int F_31 ( struct V_1 * V_1 )
{
const T_1 V_86 [] = { 0x84 , 0xff , 0xff , 0x02 , 0xff , 0xff } ;
unsigned char * V_26 = V_1 -> V_26 ;
return ! memcmp ( V_26 , V_86 , sizeof( V_86 ) ) ;
}
static int F_32 ( struct V_1 * V_1 )
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
static int F_33 ( struct V_1 * V_1 )
{
const T_1 V_86 [] = { 0xc4 , 0xff , 0xff , 0x02 , 0xff , 0xff } ;
unsigned char * V_26 = V_1 -> V_26 ;
if ( ! memcmp ( V_26 , V_86 , sizeof( V_86 ) ) )
return V_87 ;
if ( ( V_26 [ 0 ] & 0x0c ) == 0x04 && ( V_26 [ 3 ] & 0xcf ) == 0x02 )
return V_64 ;
if ( ( V_26 [ 0 ] & 0x0c ) == 0x0c && ( V_26 [ 3 ] & 0xce ) == 0x0c )
return V_88 ;
return V_81 ;
}
static int F_34 ( struct V_1 * V_1 )
{
unsigned char * V_26 = V_1 -> V_26 ;
if ( ( V_26 [ 0 ] & 0x0c ) == 0x04 &&
( V_26 [ 3 ] & 0x1f ) == 0x11 )
return V_79 ;
if ( ( V_26 [ 0 ] & 0x0c ) == 0x04 &&
( V_26 [ 3 ] & 0x1f ) == 0x12 )
return V_80 ;
if ( ( V_26 [ 0 ] & 0x0c ) == 0x04 &&
( V_26 [ 3 ] & 0x1f ) == 0x10 )
return V_78 ;
return V_81 ;
}
static T_2 F_35 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
int V_63 ;
if ( V_1 -> V_89 < V_1 -> V_25 )
return V_90 ;
if ( V_10 -> V_91 > 1 )
F_11 ( V_1 ) ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( V_10 -> V_92 && ! F_30 ( V_1 ) )
return V_93 ;
F_14 ( V_1 ) ;
break;
case 2 :
if ( F_31 ( V_1 ) )
return V_94 ;
if ( V_10 -> V_92 && ! F_32 ( V_1 ) )
return V_93 ;
F_22 ( V_1 ) ;
break;
case 3 :
V_63 = F_33 ( V_1 ) ;
if ( V_63 == V_87 )
return V_94 ;
if ( V_63 == V_81 )
return V_93 ;
F_23 ( V_1 , V_63 ) ;
break;
case 4 :
V_63 = F_34 ( V_1 ) ;
if ( V_63 == V_81 )
return V_93 ;
F_29 ( V_1 , V_63 ) ;
break;
}
return V_94 ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_17 ;
int V_13 = V_95 ;
int V_12 = 0 ;
switch ( V_10 -> V_18 ) {
case 1 :
V_10 -> V_96 = 0x16 ;
V_10 -> V_97 = 0x8f ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_96 ) ||
F_10 ( V_1 , 0x11 , V_10 -> V_97 ) ) {
V_12 = - 1 ;
}
break;
case 2 :
V_10 -> V_96 = 0x54 ;
V_10 -> V_97 = 0x88 ;
V_10 -> V_98 = 0x60 ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_96 ) ||
F_10 ( V_1 , 0x11 , V_10 -> V_97 ) ||
F_10 ( V_1 , 0x21 , V_10 -> V_98 ) ) {
V_12 = - 1 ;
}
break;
case 3 :
V_10 -> V_96 = 0x0b ;
if ( F_10 ( V_1 , 0x10 , V_10 -> V_96 ) )
V_12 = - 1 ;
break;
case 4 :
V_10 -> V_99 = 0x01 ;
if ( F_10 ( V_1 , 0x07 , V_10 -> V_99 ) )
V_12 = - 1 ;
goto V_100;
}
if ( V_12 == 0 ) {
do {
V_12 = F_9 ( V_1 , 0x10 , & V_17 ) ;
if ( V_12 == 0 )
break;
V_13 -- ;
F_7 ( L_12 , V_13 ) ;
F_8 ( V_101 ) ;
} while ( V_13 > 0 );
if ( V_12 ) {
F_4 ( V_1 ,
L_13 ) ;
} else if ( V_10 -> V_18 == 1 &&
! ( V_17 & V_102 ) ) {
F_4 ( V_1 ,
L_14 ) ;
V_12 = - 1 ;
}
}
V_100:
if ( V_12 )
F_4 ( V_1 , L_15 ) ;
return V_12 ;
}
static int F_37 ( struct V_1 * V_1 ,
unsigned int * V_103 , unsigned int * V_104 ,
unsigned int * V_105 , unsigned int * V_36 ,
unsigned int * V_57 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned char V_3 [ 3 ] ;
unsigned char V_68 ;
switch ( V_10 -> V_18 ) {
case 1 :
* V_103 = V_106 ;
* V_104 = V_107 ;
* V_105 = V_108 ;
* V_36 = V_109 ;
break;
case 2 :
if ( V_10 -> V_30 == 0x020800 ||
V_10 -> V_30 == 0x020b00 ||
V_10 -> V_30 == 0x020030 ) {
* V_103 = V_110 ;
* V_104 = V_111 ;
* V_105 = V_112 ;
* V_36 = V_113 ;
} else {
int V_23 ;
int V_114 ;
V_23 = ( V_10 -> V_30 > 0x020800 &&
V_10 -> V_30 < 0x020900 ) ? 1 : 2 ;
if ( V_10 -> V_115 ( V_1 , V_116 , V_3 ) )
return - 1 ;
V_114 = V_3 [ 1 ] & 0x10 ;
if ( ( ( V_10 -> V_30 >> 16 ) == 0x14 ) && V_114 ) {
if ( V_10 -> V_115 ( V_1 , V_117 , V_3 ) )
return - 1 ;
* V_105 = ( V_10 -> V_42 [ 1 ] - V_23 ) * V_3 [ 1 ] / 2 ;
* V_36 = ( V_10 -> V_42 [ 2 ] - V_23 ) * V_3 [ 2 ] / 2 ;
} else if ( V_10 -> V_30 == 0x040216 ) {
* V_105 = 819 ;
* V_36 = 405 ;
} else if ( V_10 -> V_30 == 0x040219 || V_10 -> V_30 == 0x040215 ) {
* V_105 = 900 ;
* V_36 = 500 ;
} else {
* V_105 = ( V_10 -> V_42 [ 1 ] - V_23 ) * 64 ;
* V_36 = ( V_10 -> V_42 [ 2 ] - V_23 ) * 64 ;
}
}
break;
case 3 :
if ( V_10 -> V_115 ( V_1 , V_116 , V_3 ) )
return - 1 ;
* V_105 = ( 0x0f & V_3 [ 0 ] ) << 8 | V_3 [ 1 ] ;
* V_36 = ( 0xf0 & V_3 [ 0 ] ) << 4 | V_3 [ 2 ] ;
break;
case 4 :
if ( V_10 -> V_115 ( V_1 , V_116 , V_3 ) )
return - 1 ;
* V_105 = ( 0x0f & V_3 [ 0 ] ) << 8 | V_3 [ 1 ] ;
* V_36 = ( 0xf0 & V_3 [ 0 ] ) << 4 | V_3 [ 2 ] ;
V_68 = V_10 -> V_42 [ 1 ] ;
if ( ( V_68 < 2 ) || ( V_68 > * V_105 ) )
return - 1 ;
* V_57 = * V_105 / ( V_68 - 1 ) ;
break;
}
return 0 ;
}
static unsigned int F_38 ( unsigned int V_17 )
{
return ( V_17 * 10 + 790 ) * 10 / 254 ;
}
static int F_39 ( struct V_1 * V_1 ,
unsigned int * V_118 ,
unsigned int * V_119 )
{
unsigned char V_3 [ 3 ] ;
if ( F_5 ( V_1 , V_120 , V_3 ) )
return - 1 ;
* V_118 = F_38 ( V_3 [ 1 ] & 0x0f ) ;
* V_119 = F_38 ( ( V_3 [ 1 ] & 0xf0 ) >> 4 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = V_1 -> V_28 ;
struct V_9 * V_10 = V_1 -> V_11 ;
unsigned int V_103 = 0 , V_104 = 0 , V_105 = 0 , V_36 = 0 , V_57 = 0 ;
unsigned int V_118 = 0 , V_119 = 0 ;
if ( F_37 ( V_1 , & V_103 , & V_104 , & V_105 , & V_36 , & V_57 ) )
return - 1 ;
F_41 ( V_121 , V_28 -> V_122 ) ;
F_41 ( V_123 , V_28 -> V_124 ) ;
F_41 ( V_125 , V_28 -> V_124 ) ;
F_42 ( V_126 , V_28 -> V_124 ) ;
F_41 ( V_40 , V_28 -> V_127 ) ;
F_41 ( V_41 , V_28 -> V_127 ) ;
F_41 ( V_33 , V_28 -> V_127 ) ;
F_41 ( V_37 , V_28 -> V_127 ) ;
F_41 ( V_38 , V_28 -> V_127 ) ;
F_41 ( V_39 , V_28 -> V_127 ) ;
switch ( V_10 -> V_18 ) {
case 1 :
if ( V_10 -> V_30 < 0x020000 &&
( V_10 -> V_42 [ 0 ] & V_43 ) ) {
F_41 ( V_44 , V_28 -> V_127 ) ;
F_41 ( V_45 , V_28 -> V_127 ) ;
}
F_43 ( V_28 , V_34 , V_103 , V_105 , 0 , 0 ) ;
F_43 ( V_28 , V_35 , V_104 , V_36 , 0 , 0 ) ;
break;
case 2 :
F_41 ( V_59 , V_28 -> V_127 ) ;
F_41 ( V_128 , V_28 -> V_122 ) ;
case 3 :
F_43 ( V_28 , V_34 , V_103 , V_105 , 0 , 0 ) ;
F_43 ( V_28 , V_35 , V_104 , V_36 , 0 , 0 ) ;
if ( V_10 -> V_60 ) {
F_43 ( V_28 , V_61 , V_129 ,
V_130 , 0 , 0 ) ;
F_43 ( V_28 , V_62 , V_131 ,
V_132 , 0 , 0 ) ;
}
F_44 ( V_28 , 2 ) ;
F_43 ( V_28 , V_51 , V_103 , V_105 , 0 , 0 ) ;
F_43 ( V_28 , V_52 , V_104 , V_36 , 0 , 0 ) ;
break;
case 4 :
if ( F_39 ( V_1 , & V_118 , & V_119 ) ) {
F_45 ( V_1 , L_16 ) ;
}
F_41 ( V_133 , V_28 -> V_122 ) ;
F_42 ( V_41 , V_28 -> V_127 ) ;
F_41 ( V_59 , V_28 -> V_127 ) ;
F_43 ( V_28 , V_34 , V_103 , V_105 , 0 , 0 ) ;
F_43 ( V_28 , V_35 , V_104 , V_36 , 0 , 0 ) ;
F_46 ( V_28 , V_34 , V_118 ) ;
F_46 ( V_28 , V_35 , V_119 ) ;
F_43 ( V_28 , V_61 , V_129 ,
V_130 , 0 , 0 ) ;
F_43 ( V_28 , V_62 , V_131 ,
V_132 , 0 , 0 ) ;
F_44 ( V_28 , V_66 ) ;
F_43 ( V_28 , V_51 , V_103 , V_105 , 0 , 0 ) ;
F_43 ( V_28 , V_52 , V_104 , V_36 , 0 , 0 ) ;
F_46 ( V_28 , V_51 , V_118 ) ;
F_46 ( V_28 , V_52 , V_119 ) ;
F_43 ( V_28 , V_69 , V_129 ,
V_130 , 0 , 0 ) ;
F_43 ( V_28 , V_70 , 0 ,
V_132 * V_57 , 0 , 0 ) ;
break;
}
V_10 -> V_36 = V_36 ;
V_10 -> V_57 = V_57 ;
return 0 ;
}
static T_3 F_47 ( struct V_1 * V_1 , void * V_134 ,
char * V_135 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_136 * V_137 = V_134 ;
unsigned char * V_16 = ( unsigned char * ) V_10 + V_137 -> V_138 ;
int V_12 = 0 ;
if ( V_137 -> V_16 )
V_12 = F_9 ( V_1 , V_137 -> V_16 , V_16 ) ;
return sprintf ( V_135 , L_17 , ( V_137 -> V_16 && V_12 ) ? - 1 : * V_16 ) ;
}
static T_3 F_48 ( struct V_1 * V_1 ,
void * V_134 , const char * V_135 , T_4 V_139 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_136 * V_137 = V_134 ;
unsigned char * V_16 = ( unsigned char * ) V_10 + V_137 -> V_138 ;
unsigned char V_140 ;
int V_141 ;
V_141 = F_49 ( V_135 , 16 , & V_140 ) ;
if ( V_141 )
return V_141 ;
if ( V_10 -> V_18 == 1 ) {
if ( V_137 -> V_16 == 0x10 )
V_140 |= V_102 ;
else if ( V_137 -> V_16 == 0x11 )
V_140 |= V_142 ;
}
if ( ! V_137 -> V_16 || F_10 ( V_1 , V_137 -> V_16 , V_140 ) == 0 )
* V_16 = V_140 ;
return V_139 ;
}
static bool F_50 ( const unsigned char * V_3 )
{
static const unsigned char V_143 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 } ;
int V_23 ;
if ( V_3 [ 0 ] == 0 )
return false ;
if ( V_3 [ 1 ] == 0 )
return true ;
for ( V_23 = 0 ; V_23 < F_51 ( V_143 ) ; V_23 ++ )
if ( V_3 [ 2 ] == V_143 [ V_23 ] )
return false ;
return true ;
}
int F_52 ( struct V_1 * V_1 , bool V_144 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
unsigned char V_3 [ 3 ] ;
F_3 ( & V_1 -> V_4 , NULL , V_145 ) ;
if ( F_3 ( V_4 , NULL , V_146 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , NULL , V_22 ) ||
F_3 ( V_4 , V_3 , V_5 ) ) {
F_53 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( V_3 [ 0 ] != 0x3c || V_3 [ 1 ] != 0x03 ||
( V_3 [ 2 ] != 0xc8 && V_3 [ 2 ] != 0x00 ) ) {
F_53 ( V_1 ,
L_19 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_147 , V_3 ) ) {
F_53 ( V_1 , L_20 ) ;
return - 1 ;
}
F_53 ( V_1 ,
L_21 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( ! F_50 ( V_3 ) ) {
F_53 ( V_1 ,
L_22 ) ;
return - 1 ;
}
if ( V_144 ) {
V_1 -> V_148 = L_23 ;
V_1 -> V_149 = L_24 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_1 )
{
F_55 ( & V_1 -> V_4 . V_150 -> V_28 . V_151 ,
& V_152 ) ;
F_56 ( V_1 -> V_11 ) ;
V_1 -> V_11 = NULL ;
}
static int F_57 ( struct V_1 * V_1 )
{
F_58 ( V_1 ) ;
if ( F_52 ( V_1 , 0 ) )
return - 1 ;
if ( F_36 ( V_1 ) ) {
F_4 ( V_1 ,
L_25 ) ;
return - 1 ;
}
return 0 ;
}
static int F_59 ( struct V_9 * V_10 )
{
int V_153 = ( V_10 -> V_30 & 0x0f0000 ) >> 16 ;
if ( V_10 -> V_30 < 0x020030 || V_10 -> V_30 == 0x020600 )
V_10 -> V_18 = 1 ;
else {
switch ( V_153 ) {
case 2 :
case 4 :
V_10 -> V_18 = 2 ;
break;
case 5 :
V_10 -> V_18 = 3 ;
break;
case 6 :
V_10 -> V_18 = 4 ;
break;
default:
return - 1 ;
}
}
V_10 -> V_115 = V_10 -> V_18 >= 3 ? F_5 :
F_1 ;
V_10 -> V_92 = 1 ;
V_10 -> V_31 =
( V_10 -> V_30 == 0x020022 || V_10 -> V_30 == 0x020600 ) ;
if ( V_10 -> V_18 > 1 ) {
V_10 -> V_91 = 1 ;
if ( V_10 -> V_30 >= 0x020800 )
V_10 -> V_60 = true ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_1 )
{
struct V_9 * V_10 ;
int V_23 , error ;
unsigned char V_3 [ 3 ] ;
V_1 -> V_11 = V_10 = F_61 ( sizeof( struct V_9 ) , V_154 ) ;
if ( ! V_10 )
return - V_155 ;
F_58 ( V_1 ) ;
V_10 -> V_85 [ 0 ] = 1 ;
for ( V_23 = 1 ; V_23 < 256 ; V_23 ++ )
V_10 -> V_85 [ V_23 ] = V_10 -> V_85 [ V_23 & ( V_23 - 1 ) ] ^ 1 ;
if ( F_1 ( V_1 , V_147 , V_3 ) ) {
F_4 ( V_1 , L_20 ) ;
goto V_156;
}
V_10 -> V_30 = ( V_3 [ 0 ] << 16 ) | ( V_3 [ 1 ] << 8 ) | V_3 [ 2 ] ;
if ( F_59 ( V_10 ) ) {
F_4 ( V_1 , L_26 ) ;
goto V_156;
}
F_62 ( V_1 ,
L_27 ,
V_10 -> V_18 , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( V_10 -> V_115 ( V_1 , V_157 ,
V_10 -> V_42 ) ) {
F_4 ( V_1 , L_28 ) ;
goto V_156;
}
F_62 ( V_1 ,
L_29 ,
V_10 -> V_42 [ 0 ] , V_10 -> V_42 [ 1 ] ,
V_10 -> V_42 [ 2 ] ) ;
if ( F_36 ( V_1 ) ) {
F_4 ( V_1 ,
L_30 ) ;
goto V_156;
}
if ( F_40 ( V_1 ) ) {
F_4 ( V_1 , L_31 ) ;
goto V_156;
}
error = F_63 ( & V_1 -> V_4 . V_150 -> V_28 . V_151 ,
& V_152 ) ;
if ( error ) {
F_4 ( V_1 ,
L_32 ,
error ) ;
goto V_156;
}
V_1 -> V_158 = F_35 ;
V_1 -> V_159 = F_54 ;
V_1 -> V_160 = F_57 ;
V_1 -> V_25 = V_10 -> V_18 > 1 ? 6 : 4 ;
return 0 ;
V_156:
F_56 ( V_10 ) ;
return - 1 ;
}
