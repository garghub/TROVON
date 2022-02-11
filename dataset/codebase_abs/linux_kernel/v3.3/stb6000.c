static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_3 ;
int V_6 ;
T_1 V_7 [] = { 10 , 0 } ;
struct V_8 V_9 = {
. V_10 = V_5 -> V_11 ,
. V_12 = 0 ,
. V_7 = V_7 ,
. V_13 = 2
} ;
F_4 ( L_1 , V_14 ) ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
V_6 = F_5 ( V_5 -> V_17 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_4 ( L_2 , V_14 ) ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 0 ) ;
return ( V_6 == 1 ) ? 0 : V_6 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_20 ;
struct V_4 * V_5 = V_2 -> V_3 ;
unsigned int V_21 , V_22 ;
int V_6 ;
T_2 V_23 ;
int V_24 ;
T_1 V_7 [ 12 ] ;
struct V_8 V_9 = {
. V_10 = V_5 -> V_11 ,
. V_12 = 0 ,
. V_7 = V_7 ,
. V_13 = 12
} ;
F_4 ( L_1 , V_14 ) ;
V_23 = V_19 -> V_25 / 1000 ;
V_24 = V_19 -> V_26 / 1000000 ;
if ( V_24 > 31 )
V_24 = 31 ;
if ( ( V_23 > 949 ) && ( V_23 < 2151 ) ) {
V_7 [ 0 ] = 0x01 ;
V_7 [ 1 ] = 0xac ;
if ( V_23 < 1950 )
V_7 [ 1 ] = 0xaa ;
if ( V_23 < 1800 )
V_7 [ 1 ] = 0xa8 ;
if ( V_23 < 1650 )
V_7 [ 1 ] = 0xa6 ;
if ( V_23 < 1530 )
V_7 [ 1 ] = 0xa5 ;
if ( V_23 < 1470 )
V_7 [ 1 ] = 0xa4 ;
if ( V_23 < 1370 )
V_7 [ 1 ] = 0xa2 ;
if ( V_23 < 1300 )
V_7 [ 1 ] = 0xa1 ;
if ( V_23 < 1200 )
V_7 [ 1 ] = 0xa0 ;
if ( V_23 < 1075 )
V_7 [ 1 ] = 0xbc ;
if ( V_23 < 1000 )
V_7 [ 1 ] = 0xba ;
if ( V_23 < 1075 ) {
V_21 = V_23 / 8 ;
V_22 = 2 ;
} else {
V_21 = V_23 / 16 ;
V_22 = 1 ;
}
V_7 [ 2 ] = V_21 >> 1 ;
V_7 [ 3 ] = ( unsigned char ) ( ( ( V_21 & 1 ) << 7 ) |
( V_22 * V_23 - V_21 * 16 ) | 0x60 ) ;
V_7 [ 4 ] = 0x04 ;
V_7 [ 5 ] = 0x0e ;
V_7 [ 6 ] = ( unsigned char ) ( V_24 ) ;
V_7 [ 7 ] = 0xd8 ;
V_7 [ 8 ] = 0xd0 ;
V_7 [ 9 ] = 0x50 ;
V_7 [ 10 ] = 0xeb ;
V_7 [ 11 ] = 0x4f ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
V_6 = F_5 ( V_5 -> V_17 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_4 ( L_2 , V_14 ) ;
F_7 ( 10 ) ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 0 ) ;
V_7 [ 0 ] = 0x07 ;
V_7 [ 1 ] = 0xdf ;
V_7 [ 2 ] = 0xd0 ;
V_7 [ 3 ] = 0x50 ;
V_7 [ 4 ] = 0xfb ;
V_9 . V_13 = 5 ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
V_6 = F_5 ( V_5 -> V_17 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_4 ( L_2 , V_14 ) ;
F_7 ( 10 ) ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 0 ) ;
V_5 -> V_25 = V_23 * 1000 ;
return ( V_6 == 1 ) ? 0 : V_6 ;
}
return - 1 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_3 ;
* V_25 = V_5 -> V_25 ;
return 0 ;
}
struct V_1 * F_9 ( struct V_1 * V_2 , int V_10 ,
struct V_27 * V_17 )
{
struct V_4 * V_5 = NULL ;
T_1 V_28 [] = { 0 } ;
T_1 V_29 [] = { 0 , 0 } ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_10 ,
. V_12 = 0 ,
. V_7 = V_28 ,
. V_13 = 0
} , {
. V_10 = V_10 ,
. V_12 = V_30 ,
. V_7 = V_29 ,
. V_13 = 2
}
} ;
int V_6 ;
F_4 ( L_1 , V_14 ) ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 1 ) ;
V_6 = F_5 ( V_17 , V_9 , 2 ) ;
if ( V_2 -> V_15 . V_16 )
V_2 -> V_15 . V_16 ( V_2 , 0 ) ;
if ( V_6 != 2 )
return NULL ;
V_5 = F_10 ( sizeof( struct V_4 ) , V_31 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_11 = V_10 ;
V_5 -> V_17 = V_17 ;
memcpy ( & V_2 -> V_15 . V_32 , & V_33 ,
sizeof( struct V_34 ) ) ;
V_2 -> V_3 = V_5 ;
return V_2 ;
}
