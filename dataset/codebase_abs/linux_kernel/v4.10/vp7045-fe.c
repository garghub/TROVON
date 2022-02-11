static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 = F_2 ( V_6 -> V_9 , 0x00 ) ,
V_10 = F_2 ( V_6 -> V_9 , 0x01 ) ,
V_11 = F_2 ( V_6 -> V_9 , 0x03 ) ;
* V_4 = 0 ;
if ( V_8 & ( 1 << 4 ) )
* V_4 |= V_12 ;
if ( V_8 & ( 1 << 1 ) )
* V_4 |= V_13 ;
if ( V_8 & ( 1 << 5 ) )
* V_4 |= V_14 ;
if ( V_10 & ( 1 << 1 ) )
* V_4 |= V_15 ;
if ( V_11 & ( 1 << 6 ) )
* V_4 |= V_16 ;
if ( ( * V_4 & ( V_12 | V_13 | V_15 ) ) !=
( V_12 | V_13 | V_15 ) )
* V_4 &= ~ V_14 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 * V_17 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_17 = ( F_2 ( V_6 -> V_9 , 0x0D ) << 16 ) |
( F_2 ( V_6 -> V_9 , 0x0E ) << 8 ) |
F_2 ( V_6 -> V_9 , 0x0F ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_18 = ( F_2 ( V_6 -> V_9 , 0x10 ) << 8 ) |
F_2 ( V_6 -> V_9 , 0x11 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_3 * V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 signal = ( F_2 ( V_6 -> V_9 , 0x14 ) << 8 ) |
F_2 ( V_6 -> V_9 , 0x15 ) ;
* V_19 = ~ signal ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_3 * V_20 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_21 = F_2 ( V_6 -> V_9 , 0x09 ) ;
* V_20 = ( V_21 << 8 ) | V_21 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
V_23 -> V_24 = 800 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_27 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_28 [ 5 ] ;
T_2 V_29 = V_26 -> V_30 / 1000 ;
V_28 [ 0 ] = ( V_29 >> 16 ) & 0xff ;
V_28 [ 1 ] = ( V_29 >> 8 ) & 0xff ;
V_28 [ 2 ] = V_29 & 0xff ;
V_28 [ 3 ] = 0 ;
switch ( V_26 -> V_31 ) {
case 8000000 :
V_28 [ 4 ] = 8 ;
break;
case 7000000 :
V_28 [ 4 ] = 7 ;
break;
case 6000000 :
V_28 [ 4 ] = 6 ;
break;
default:
return - V_32 ;
}
F_11 ( V_6 -> V_9 , V_33 , V_28 , 5 , NULL , 0 , 200 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_13 ( V_6 ) ;
}
struct V_1 * F_14 ( struct V_34 * V_9 )
{
struct V_5 * V_35 = F_15 ( sizeof( struct V_5 ) , V_36 ) ;
if ( V_35 == NULL )
goto error;
V_35 -> V_9 = V_9 ;
memcpy ( & V_35 -> V_2 . V_37 , & V_38 , sizeof( struct V_39 ) ) ;
V_35 -> V_2 . V_7 = V_35 ;
return & V_35 -> V_2 ;
error:
return NULL ;
}
