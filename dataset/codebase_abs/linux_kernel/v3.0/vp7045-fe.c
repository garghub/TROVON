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
static int F_10 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_26 [ 5 ] ;
T_3 V_27 = V_25 -> V_28 / 1000 ;
V_26 [ 0 ] = ( V_27 >> 16 ) & 0xff ;
V_26 [ 1 ] = ( V_27 >> 8 ) & 0xff ;
V_26 [ 2 ] = V_27 & 0xff ;
V_26 [ 3 ] = 0 ;
switch ( V_25 -> V_29 . V_30 . V_31 ) {
case V_32 : V_26 [ 4 ] = 8 ; break;
case V_33 : V_26 [ 4 ] = 7 ; break;
case V_34 : V_26 [ 4 ] = 6 ; break;
case V_35 : return - V_36 ;
default:
return - V_37 ;
}
F_11 ( V_5 -> V_8 , V_38 , V_26 , 5 , NULL , 0 , 200 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_14 ( V_5 ) ;
}
struct V_1 * F_15 ( struct V_39 * V_8 )
{
struct V_4 * V_40 = F_16 ( sizeof( struct V_4 ) , V_41 ) ;
if ( V_40 == NULL )
goto error;
V_40 -> V_8 = V_8 ;
memcpy ( & V_40 -> V_2 . V_42 , & V_43 , sizeof( struct V_44 ) ) ;
V_40 -> V_2 . V_6 = V_40 ;
return & V_40 -> V_2 ;
error:
return NULL ;
}
