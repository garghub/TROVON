int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_4 -> V_5 ) {
case V_6 :
* ( unsigned int * ) V_7 |= V_8 ;
break;
case V_9 :
case V_10 :
* ( unsigned int * ) V_7 &= ~ V_8 ;
* ( unsigned int * ) V_11 =
( ( V_12 * F_2 ( V_13 ) ) << 12 ) | ( ( V_14 * F_3 ( V_13 ) ) -
V_2 -> V_15 . V_16 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_17 * V_15 ,
struct V_1 * V_2 )
{
if ( V_15 -> V_18 || V_15 -> V_16 + V_15 -> V_19 > V_15 -> V_20 )
return - V_21 ;
* ( unsigned int * ) V_22 = V_15 -> V_16 * V_15 -> V_23 ;
return 0 ;
}
static int F_5 ( int V_24 , struct V_1 * V_2 )
{
if ( V_24 )
* ( unsigned int * ) V_7 |= V_25 ;
else
* ( unsigned int * ) V_7 &= ~ V_25 ;
return 0 ;
}
static int F_6 ( T_1 V_26 , T_1 V_27 , T_1 V_28 ,
T_1 V_29 , T_1 V_30 , struct V_1 * V_2 )
{
volatile unsigned int * V_31 = ( volatile unsigned int * ) V_32 ;
if ( V_26 > 255 )
return 1 ;
V_27 >>= 8 ;
V_28 >>= 8 ;
V_29 >>= 8 ;
V_31 [ V_26 << 1 ] = ( V_27 << 16 ) | ( V_28 << 8 ) | V_29 ;
return 0 ;
}
int T_2 F_7 ( void )
{
volatile unsigned int * V_33 =
( volatile unsigned int * ) V_32 ;
volatile unsigned int * V_34 =
( volatile unsigned int * ) V_35 ;
int V_36 , V_37 , V_38 ;
if ( F_8 ( L_1 , NULL ) )
return - V_39 ;
* ( volatile unsigned int * ) V_7 &= ~ V_40 ;
V_41 . V_23 =
( * ( ( volatile unsigned int * ) V_42 ) & 0x00ffffff ) * 4 ;
V_41 . V_19 =
( * ( ( volatile unsigned int * ) V_43 ) & 0x00ffffff ) / 2 ;
* ( volatile unsigned int * ) V_7 |= V_40 ;
V_34 [ 0 ] |= 0x00ffffff ;
V_34 [ 2 ] |= 0x00ffffff ;
V_34 [ 4 ] |= 0x00ffffff ;
for ( V_37 = 0 ; V_37 < 512 ; V_37 ++ )
* ( unsigned short * ) ( V_44 + V_37 * 8 ) = 0 ;
* ( unsigned short * ) ( V_44 + 14 * 64 ) = 0xffff ;
* ( unsigned short * ) ( V_44 + 15 * 64 ) = 0xffff ;
V_41 . V_45 = V_46 . V_23 ;
V_47 . V_48 = ( V_23 / 8 ) * V_41 . V_49 ;
V_47 . V_50 = 0x40000000 ;
V_36 = ( F_9 ( V_51 ) >> 8 ) & 3 ;
V_47 . V_52 = ( 1 << ( V_36 * 2 ) ) * 512 * 1024 ;
V_41 . V_20 = V_47 . V_52 / V_41 . V_23 ;
V_1 . V_53 = & V_54 ;
V_1 . V_55 = ( char * ) V_56 ;
V_1 . V_15 = V_41 ;
V_1 . V_57 = V_47 ;
V_1 . V_58 = V_59 | V_60 ;
F_10 ( & V_1 . V_61 , 255 , 0 ) ;
if ( F_11 ( & V_1 ) < 0 )
return - V_21 ;
return 0 ;
}
