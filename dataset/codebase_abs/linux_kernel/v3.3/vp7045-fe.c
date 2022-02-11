static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 = F_2 ( V_5 -> V_8 , 0x00 ) ,
V_9 = F_2 ( V_5 -> V_8 , 0x01 ) ,
V_10 = F_2 ( V_5 -> V_8 , 0x03 ) ;
* V_3 = 0 ;
if ( V_7 & ( 1 << 4 ) )
* V_3 |= V_11 ;
if ( V_7 & ( 1 << 1 ) )
* V_3 |= V_12 ;
if ( V_7 & ( 1 << 5 ) )
* V_3 |= V_13 ;
if ( V_9 & ( 1 << 1 ) )
* V_3 |= V_14 ;
if ( V_10 & ( 1 << 6 ) )
* V_3 |= V_15 ;
if ( ( * V_3 & ( V_11 | V_12 | V_14 ) ) !=
( V_11 | V_12 | V_14 ) )
* V_3 &= ~ V_13 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_3 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_16 = ( F_2 ( V_5 -> V_8 , 0x0D ) << 16 ) |
( F_2 ( V_5 -> V_8 , 0x0E ) << 8 ) |
F_2 ( V_5 -> V_8 , 0x0F ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_3 * V_17 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_17 = ( F_2 ( V_5 -> V_8 , 0x10 ) << 8 ) |
F_2 ( V_5 -> V_8 , 0x11 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_4 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_4 signal = ( F_2 ( V_5 -> V_8 , 0x14 ) << 8 ) |
F_2 ( V_5 -> V_8 , 0x15 ) ;
* V_18 = ~ signal ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_4 * V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_20 = F_2 ( V_5 -> V_8 , 0x09 ) ;
* V_19 = ( V_20 << 8 ) | V_20 ;
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
static int F_9 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
V_22 -> V_23 = 800 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = & V_2 -> V_26 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_27 [ 5 ] ;
T_3 V_28 = V_25 -> V_29 / 1000 ;
V_27 [ 0 ] = ( V_28 >> 16 ) & 0xff ;
V_27 [ 1 ] = ( V_28 >> 8 ) & 0xff ;
V_27 [ 2 ] = V_28 & 0xff ;
V_27 [ 3 ] = 0 ;
switch ( V_25 -> V_30 ) {
case 8000000 :
V_27 [ 4 ] = 8 ;
break;
case 7000000 :
V_27 [ 4 ] = 7 ;
break;
case 6000000 :
V_27 [ 4 ] = 6 ;
break;
default:
return - V_31 ;
}
F_11 ( V_5 -> V_8 , V_32 , V_27 , 5 , NULL , 0 , 200 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_13 ( V_5 ) ;
}
struct V_1 * F_14 ( struct V_33 * V_8 )
{
struct V_4 * V_34 = F_15 ( sizeof( struct V_4 ) , V_35 ) ;
if ( V_34 == NULL )
goto error;
V_34 -> V_8 = V_8 ;
memcpy ( & V_34 -> V_2 . V_36 , & V_37 , sizeof( struct V_38 ) ) ;
V_34 -> V_2 . V_6 = V_34 ;
return & V_34 -> V_2 ;
error:
return NULL ;
}
