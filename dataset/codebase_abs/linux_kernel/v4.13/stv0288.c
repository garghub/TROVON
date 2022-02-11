static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_6 = V_6 ,
. V_13 = 2
} ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1 ,
V_15 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - V_16 : 0 ;
}
static int F_4 ( struct V_17 * V_18 , const T_1 V_6 [] , int V_13 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_13 != 2 )
return - V_20 ;
return F_1 ( V_2 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_21 [] = { V_3 } ;
T_1 V_22 [] = { 0 } ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_6 = V_21 ,
. V_13 = 1
} , {
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = V_23 ,
. V_6 = V_22 ,
. V_13 = 1
}
} ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
F_3 ( L_2 ,
V_15 , V_3 , V_5 ) ;
return V_22 [ 0 ] ;
}
static int F_6 ( struct V_17 * V_18 , T_2 V_24 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
unsigned int V_25 ;
unsigned char V_26 [ 3 ] ;
if ( ( V_24 < 1000000 ) || ( V_24 > 45000000 ) )
return - V_20 ;
F_1 ( V_2 , 0x22 , 0 ) ;
F_1 ( V_2 , 0x23 , 0 ) ;
F_1 ( V_2 , 0x2b , 0xff ) ;
F_1 ( V_2 , 0x2c , 0xf7 ) ;
V_25 = ( unsigned int ) V_24 / 1000 ;
V_25 = V_25 * 32768 ;
V_25 = V_25 / 25 ;
V_25 = V_25 / 125 ;
V_26 [ 0 ] = ( unsigned char ) ( ( V_25 >> 12 ) & 0xff ) ;
V_26 [ 1 ] = ( unsigned char ) ( ( V_25 >> 4 ) & 0xff ) ;
V_26 [ 2 ] = ( unsigned char ) ( ( V_25 << 4 ) & 0xf0 ) ;
F_1 ( V_2 , 0x28 , 0x80 ) ;
F_1 ( V_2 , 0x29 , 0 ) ;
F_1 ( V_2 , 0x2a , 0 ) ;
F_1 ( V_2 , 0x28 , V_26 [ 0 ] ) ;
F_1 ( V_2 , 0x29 , V_26 [ 1 ] ) ;
F_1 ( V_2 , 0x2a , V_26 [ 2 ] ) ;
F_3 ( L_3 ) ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_29 ;
F_3 ( L_4 , V_15 ) ;
F_1 ( V_2 , 0x09 , 0 ) ;
F_8 ( 30 ) ;
F_1 ( V_2 , 0x05 , 0x12 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_30 ; V_29 ++ ) {
if ( F_1 ( V_2 , 0x06 , V_28 -> V_8 [ V_29 ] ) )
return - V_16 ;
}
F_8 ( V_28 -> V_30 * 12 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 ,
enum V_31 V_32 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_3 ( L_4 , V_15 ) ;
if ( F_1 ( V_2 , 0x05 , 0x03 ) )
return - V_16 ;
if ( F_1 ( V_2 , 0x06 , V_32 == V_33 ? 0x00 : 0xff ) )
return - V_16 ;
F_8 ( 15 ) ;
if ( F_1 ( V_2 , 0x05 , 0x12 ) )
return - V_16 ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 , enum V_34 V_35 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
switch ( V_35 ) {
case V_36 :
if ( F_1 ( V_2 , 0x05 , 0x10 ) )
return - V_16 ;
break;
case V_37 :
if ( F_1 ( V_2 , 0x05 , 0x12 ) )
return - V_16 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 ,
enum V_38 V_39 )
{
F_3 ( L_5 , V_15 ,
V_39 == V_40 ? L_6 :
V_39 == V_41 ? L_7 : L_8 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_29 ;
T_1 V_3 ;
T_1 V_42 ;
F_3 ( L_9 ) ;
F_1 ( V_2 , 0x41 , 0x04 ) ;
F_8 ( 50 ) ;
if ( V_2 -> V_10 -> V_43 == NULL ) {
for ( V_29 = 0 ; ! ( V_44 [ V_29 ] == 0xff &&
V_44 [ V_29 + 1 ] == 0xff ) ; V_29 += 2 )
F_1 ( V_2 , V_44 [ V_29 ] ,
V_44 [ V_29 + 1 ] ) ;
} else {
for ( V_29 = 0 ; ; V_29 += 2 ) {
V_3 = V_2 -> V_10 -> V_43 [ V_29 ] ;
V_42 = V_2 -> V_10 -> V_43 [ V_29 + 1 ] ;
if ( V_3 == 0xff && V_42 == 0xff )
break;
F_1 ( V_2 , V_3 , V_42 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_17 * V_18 , enum V_45 * V_46 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_47 = F_5 ( V_2 , 0x24 ) ;
if ( V_47 == 255 )
V_47 = 0 ;
F_3 ( L_10 , V_15 , V_47 ) ;
* V_46 = 0 ;
if ( V_47 & 0x80 )
* V_46 |= V_48 | V_49 ;
if ( V_47 & 0x10 )
* V_46 |= V_50 ;
if ( V_47 & 0x08 ) {
* V_46 |= V_51 ;
F_3 ( L_11 ) ;
}
return 0 ;
}
static int F_14 ( struct V_17 * V_18 , T_2 * V_52 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_2 -> V_53 != V_54 )
return 0 ;
* V_52 = ( F_5 ( V_2 , 0x26 ) << 8 ) |
F_5 ( V_2 , 0x27 ) ;
F_3 ( L_12 , * V_52 ) ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 , T_3 * V_55 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_4 signal = 0xffff - ( ( F_5 ( V_2 , 0x10 ) << 8 ) ) ;
signal = signal * 5 / 4 ;
* V_55 = ( signal > 0xffff ) ? 0xffff : ( signal < 0 ) ? 0 : signal ;
F_3 ( L_13 , * V_55 ) ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_1 ( V_2 , 0x41 , 0x84 ) ;
V_2 -> V_56 = 0 ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 , T_3 * V_57 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_4 V_58 = 0xffff - ( ( F_5 ( V_2 , 0x2d ) << 8 )
| F_5 ( V_2 , 0x2e ) ) ;
V_58 = 3 * ( V_58 - 0xa100 ) ;
* V_57 = ( V_58 > 0xffff ) ? 0xffff : ( V_58 < 0 ) ? 0 : V_58 ;
F_3 ( L_14 , * V_57 ) ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , T_2 * V_59 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_2 -> V_53 != V_54 )
return 0 ;
* V_59 = ( F_5 ( V_2 , 0x26 ) << 8 ) |
F_5 ( V_2 , 0x27 ) ;
F_3 ( L_12 , * V_59 ) ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 , struct V_60 * V_61 )
{
F_3 ( L_15 , V_15 ) ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_62 * V_63 = & V_18 -> V_64 ;
char V_65 ;
unsigned char V_66 [ 3 ] ;
T_1 V_3 , V_67 = 0 ;
F_3 ( L_16 , V_15 ) ;
if ( V_63 -> V_68 != V_69 ) {
F_3 ( L_17 ,
V_15 , V_63 -> V_68 ) ;
return - V_70 ;
}
if ( V_2 -> V_10 -> V_71 )
V_2 -> V_10 -> V_71 ( V_18 , 0 ) ;
if ( V_18 -> V_72 . V_73 . V_74 ) {
V_18 -> V_72 . V_73 . V_74 ( V_18 ) ;
if ( V_18 -> V_72 . V_75 )
V_18 -> V_72 . V_75 ( V_18 , 0 ) ;
}
F_21 ( 10 ) ;
F_6 ( V_18 , V_63 -> V_76 ) ;
F_1 ( V_2 , 0x15 , 0xc5 ) ;
V_66 [ 2 ] = 0x0 ;
for ( V_65 = - 9 ; V_65 < 7 ; ) {
V_3 = F_5 ( V_2 , 0x24 ) ;
if ( V_3 & 0x8 )
break;
if ( V_3 & 0x80 ) {
V_67 ++ ;
if ( V_67 > 10 )
break;
V_66 [ 2 ] += 40 ;
if ( V_66 [ 2 ] < 40 )
V_65 ++ ;
} else {
V_65 ++ ;
V_66 [ 2 ] = 0 ;
V_67 = 0 ;
}
V_66 [ 1 ] = ( unsigned char ) V_65 ;
F_1 ( V_2 , 0x2b , V_66 [ 1 ] ) ;
F_1 ( V_2 , 0x2c , V_66 [ 2 ] ) ;
F_8 ( 30 ) ;
}
V_2 -> V_77 = V_63 -> V_78 ;
V_2 -> V_79 = V_80 ;
V_2 -> V_76 = V_63 -> V_76 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 , int V_81 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_81 )
F_1 ( V_2 , 0x01 , 0xb5 ) ;
else
F_1 ( V_2 , 0x01 , 0x35 ) ;
F_21 ( 1 ) ;
return 0 ;
}
static void F_23 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_24 ( V_2 ) ;
}
struct V_17 * F_25 ( const struct V_82 * V_10 ,
struct V_83 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_84 ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_85 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_56 = 0 ;
V_2 -> V_77 = 0 ;
V_2 -> V_76 = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_53 = V_54 ;
F_1 ( V_2 , 0x41 , 0x04 ) ;
F_8 ( 200 ) ;
V_84 = F_5 ( V_2 , 0x00 ) ;
F_3 ( L_18 , V_84 ) ;
if ( V_84 != 0x11 )
goto error;
memcpy ( & V_2 -> V_86 . V_72 , & V_87 ,
sizeof( struct V_88 ) ) ;
V_2 -> V_86 . V_19 = V_2 ;
return & V_2 -> V_86 ;
error:
F_24 ( V_2 ) ;
return NULL ;
}
