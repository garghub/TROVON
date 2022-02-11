static void F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 )
{
unsigned int div , V_4 ;
if ( V_5 & V_3 [ 0 ] )
F_2 ( L_1 ) ;
else
F_2 ( L_2 ) ;
if ( V_6 & V_3 [ 0 ] )
F_2 ( L_3 ) ;
else
F_2 ( L_4 ) ;
div = ( ( V_3 [ 0 ] & 0x3f ) << 8 ) | V_3 [ 1 ] ;
switch ( V_2 -> V_7 . V_8 ) {
case V_9 :
V_4 = ( div * 50000 - 700000 - 225000 ) / 4 ;
break;
case V_10 :
V_4 = ( div * 50000 + 700000 + 225000 ) / 4 ;
break;
case V_11 :
V_4 = ( div * 32768 + 700000 + 225000 ) / 4 ;
break;
case V_12 :
default:
V_4 = ( div * 32768 - 700000 - 225000 ) / 4 ;
break;
}
V_3 [ 0 ] = ( div >> 8 ) & 0x3f ;
V_3 [ 1 ] = div & 0xff ;
F_2 ( L_5 ,
V_4 / 1000 , V_4 % 1000 , div ) ;
if ( V_13 & V_3 [ 2 ] )
F_2 ( L_6 ) ;
else
F_2 ( L_7 ) ;
F_2 ( L_8 , V_3 [ 2 ] & V_14 ) ;
F_2 ( L_9 ,
( V_3 [ 3 ] & V_15 ) >> 4 ) ;
F_2 ( L_10 , ( V_3 [ 3 ] & V_16 ) ) ;
F_2 ( L_11 ,
( V_3 [ 4 ] & V_17 ) ) ;
}
static int F_3 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_19 -> V_22 ;
unsigned int V_4 = V_21 -> V_23 ;
unsigned char V_3 [ 5 ] ;
unsigned div ;
int V_24 ;
F_4 ( L_12 , V_4 / 16000 , ( V_4 / 16 ) % 1000 ) ;
V_3 [ 2 ] = 0 ;
if ( V_2 -> V_7 . V_25 )
V_3 [ 2 ] |= V_26 ;
if ( V_21 -> V_27 == V_28 ) {
F_4 ( L_13 ) ;
V_3 [ 2 ] |= V_29 ;
} else {
F_4 ( L_14 ) ;
}
V_3 [ 3 ] = 0 ;
if ( V_2 -> V_7 . V_30 )
V_3 [ 3 ] |= V_31 ;
if ( V_2 -> V_7 . V_32 )
V_3 [ 3 ] |= V_33 ;
if ( V_2 -> V_7 . V_34 )
V_3 [ 3 ] |= V_35 ;
if ( V_2 -> V_7 . V_36 )
V_3 [ 3 ] |= V_37 ;
if ( V_2 -> V_7 . V_38 )
V_3 [ 3 ] |= V_39 ;
V_3 [ 4 ] = 0 ;
if ( V_2 -> V_7 . V_40 )
V_3 [ 4 ] |= V_41 ;
if ( V_2 -> V_7 . V_42 )
V_3 [ 4 ] |= V_43 ;
switch ( V_2 -> V_7 . V_8 ) {
case V_9 :
F_4 ( L_15 ) ;
V_3 [ 2 ] |= V_44 ;
div = ( V_4 * ( 4000 / 16 ) + 700000 + 225000 + 25000 ) / 50000 ;
break;
case V_10 :
F_4 ( L_16 ) ;
div = ( V_4 * ( 4000 / 16 ) - 700000 - 225000 + 25000 ) / 50000 ;
break;
case V_11 :
F_4 ( L_17 ) ;
V_3 [ 3 ] |= V_45 ;
div = ( ( V_4 * ( 4000 / 16 ) - 700000 - 225000 ) + 16384 ) >> 15 ;
break;
case V_12 :
default:
F_4 ( L_18 ) ;
V_3 [ 2 ] |= V_44 ;
V_3 [ 3 ] |= V_45 ;
div = ( ( V_4 * ( 4000 / 16 ) + 700000 + 225000 ) + 16384 ) >> 15 ;
break;
}
V_3 [ 0 ] = ( div >> 8 ) & 0x3f ;
V_3 [ 1 ] = div & 0xff ;
if ( 5 != ( V_24 = F_5 ( & V_2 -> V_46 , V_3 , 5 ) ) )
F_6 ( L_19 , V_24 ) ;
if ( V_47 ) {
if ( 5 != ( V_24 = F_7 ( & V_2 -> V_46 , V_3 , 5 ) ) )
F_6 ( L_19 , V_24 ) ;
else
F_1 ( V_2 , V_3 ) ;
}
V_2 -> V_23 = V_4 * 125 / 2 ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 , char * V_3 )
{
struct V_1 * V_2 = V_19 -> V_22 ;
int V_24 ;
memset ( V_3 , 0 , 5 ) ;
if ( 5 != ( V_24 = F_7 ( & V_2 -> V_46 , V_3 , 5 ) ) ) {
F_6 ( L_19 , V_24 ) ;
return - V_48 ;
}
return 0 ;
}
static inline int F_9 ( struct V_18 * V_19 , const char * V_3 )
{
struct V_1 * V_2 = V_19 -> V_22 ;
int signal = ( ( V_3 [ 3 ] & V_15 ) << 8 ) ;
F_4 ( L_20 , signal ) ;
return signal ;
}
static inline int F_10 ( struct V_18 * V_19 , const char * V_3 )
{
struct V_1 * V_2 = V_19 -> V_22 ;
int V_49 = V_3 [ 2 ] & V_13 ;
F_4 ( L_21 , V_49 ) ;
return ( V_49 ? V_50 : 0 ) ;
}
static int F_11 ( struct V_18 * V_19 , T_1 * V_51 )
{
unsigned char V_3 [ 5 ] ;
* V_51 = 0 ;
if ( 0 == F_8 ( V_19 , V_3 ) ) {
if ( F_9 ( V_19 , V_3 ) )
* V_51 = V_52 ;
if ( F_10 ( V_19 , V_3 ) )
* V_51 |= V_53 ;
}
return 0 ;
}
static int F_12 ( struct V_18 * V_19 , T_2 * V_54 )
{
unsigned char V_3 [ 5 ] ;
* V_54 = 0 ;
if ( 0 == F_8 ( V_19 , V_3 ) )
* V_54 = F_9 ( V_19 , V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 )
{
unsigned char V_3 [ 5 ] ;
struct V_1 * V_2 = V_19 -> V_22 ;
unsigned div , V_24 ;
div = ( 87500 * 4 + 700 + 225 + 25 ) / 50 ;
V_3 [ 0 ] = ( div >> 8 ) & 0x3f ;
V_3 [ 1 ] = div & 0xff ;
V_3 [ 2 ] = V_26 ;
V_3 [ 3 ] = V_31 | V_33 |
V_35 | V_39 | V_55 ;
V_3 [ 4 ] = 0 ;
if ( 5 != ( V_24 = F_5 ( & V_2 -> V_46 , V_3 , 5 ) ) )
F_6 ( L_19 , V_24 ) ;
return 0 ;
}
int F_14 ( struct V_56 * V_57 , T_3 V_58 )
{
struct V_59 V_60 = { . V_61 = V_57 , . V_62 = V_58 } ;
unsigned char V_3 [ 7 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_24 ;
if ( ( V_24 = F_7 ( & V_60 , V_3 , 7 ) ) < 5 ) {
F_15 ( V_63 L_22 , V_24 ) ;
return - V_64 ;
}
if ( V_3 [ 0 ] == V_3 [ 1 ] && V_3 [ 0 ] == V_3 [ 2 ] &&
V_3 [ 0 ] == V_3 [ 3 ] && V_3 [ 0 ] == V_3 [ 4 ] ) {
F_15 ( V_63 L_23 ) ;
return - V_64 ;
}
if ( ( ( V_3 [ 3 ] & 0x0f ) != 0x00 ) || ( V_3 [ 4 ] != 0x00 ) ) {
F_15 ( V_63 L_24 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_16 ( struct V_18 * V_19 )
{
F_17 ( V_19 -> V_22 ) ;
V_19 -> V_22 = NULL ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 , T_1 * V_23 )
{
struct V_1 * V_2 = V_19 -> V_22 ;
* V_23 = V_2 -> V_23 ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 , void * V_65 )
{
struct V_1 * V_2 = V_19 -> V_22 ;
memcpy ( & V_2 -> V_7 , V_65 , sizeof( V_2 -> V_7 ) ) ;
return 0 ;
}
struct V_18 * F_20 ( struct V_18 * V_19 ,
struct V_56 * V_57 ,
T_3 V_58 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_66 ) ;
if ( V_2 == NULL )
return NULL ;
V_19 -> V_22 = V_2 ;
V_2 -> V_46 . V_62 = V_58 ;
V_2 -> V_46 . V_61 = V_57 ;
V_2 -> V_46 . V_67 = L_25 ;
V_2 -> V_7 . V_8 = V_12 ;
V_2 -> V_7 . V_25 = 1 ;
V_2 -> V_7 . V_30 = 1 ;
V_2 -> V_7 . V_32 = 1 ;
V_2 -> V_7 . V_34 = 1 ;
V_2 -> V_7 . V_38 = 1 ;
memcpy ( & V_19 -> V_68 . V_69 , & V_70 ,
sizeof( struct V_71 ) ) ;
F_2 ( L_26 , L_27 ) ;
return V_19 ;
}
