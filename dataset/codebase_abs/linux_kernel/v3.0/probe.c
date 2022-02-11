void T_1 F_1 ( void )
{
unsigned long V_1 , V_2 , V_3 ;
unsigned long V_4 ;
static unsigned long V_5 [ 16 ] = {
[ 1 ] = ( 1 << 12 ) ,
[ 2 ] = ( 1 << 13 ) ,
[ 4 ] = ( 1 << 14 ) ,
[ 8 ] = ( 1 << 15 ) ,
[ 9 ] = ( 1 << 16 )
} ;
V_1 = ( F_2 ( V_6 ) >> 8 ) & 0xffffff ;
V_2 = ( F_2 ( V_7 ) >> 4 ) & 0xff ;
V_3 = ( F_2 ( V_8 ) ) ;
V_9 . V_10 . V_11 = ( 1 << 13 ) ;
V_9 . V_10 . V_12 = 5 ;
V_9 . V_10 . V_13 = 256 ;
V_9 . V_10 . V_14 = 1 ;
V_9 . V_10 . V_15 = V_16 ;
V_9 . V_17 . V_11 = ( 1 << 14 ) ;
V_9 . V_17 . V_12 = 5 ;
V_9 . V_17 . V_13 = 512 ;
V_9 . V_17 . V_14 = 1 ;
V_9 . V_17 . V_15 = V_16 ;
V_9 . V_18 = V_9 . V_19 = - 1 ;
if ( ( ( V_1 >> 16 ) & 0xff ) == 0x10 ) {
V_9 . V_20 = V_21 ;
if ( ( V_3 & 0x10000000 ) == 0 ) {
V_9 . V_22 |= V_23 ;
V_9 . V_20 = V_24 ;
}
V_9 . V_22 |= V_25 | V_26 ;
V_9 . V_18 = V_1 & 0x7f ;
V_9 . V_10 . V_14 = 4 ;
V_9 . V_17 . V_14 = 4 ;
} else {
V_9 . V_22 |= V_27 | V_28 ;
V_9 . V_20 = V_29 ;
}
if ( ( V_3 & 0x20000000 ) )
V_9 . V_22 |= V_28 ;
V_1 &= 0xffff ;
switch ( V_1 ) {
case 0x205 :
V_9 . type = V_30 ;
V_9 . V_22 |= V_31 |
V_26 ;
break;
case 0x206 :
V_9 . type = V_32 ;
V_9 . V_22 |= V_31 |
V_26 ;
break;
case 0x1100 :
V_9 . type = V_33 ;
break;
case 0x2001 :
case 0x2004 :
V_9 . type = V_34 ;
break;
case 0x2006 :
case 0x200A :
if ( V_2 == 0x61 )
V_9 . type = V_35 ;
else if ( V_2 == 0xa1 )
V_9 . type = V_36 ;
else
V_9 . type = V_37 ;
break;
case 0x3000 :
case 0x3003 :
case 0x3009 :
V_9 . type = V_38 ;
break;
case 0x3004 :
case 0x3007 :
V_9 . type = V_39 ;
break;
case 0x4004 :
case 0x4005 :
V_9 . type = V_40 ;
V_9 . V_22 |= V_41 | V_42 ;
break;
case 0x3008 :
switch ( V_2 ) {
case 0x50 :
case 0x51 :
V_9 . type = V_43 ;
V_9 . V_22 |= V_42 ;
break;
case 0x70 :
V_9 . type = V_44 ;
break;
case 0xa0 :
case 0xa1 :
V_9 . type = V_45 ;
break;
}
break;
case 0x300b :
switch ( V_2 ) {
case 0x20 :
V_9 . type = V_46 ;
V_9 . V_22 |= V_42 ;
break;
case 0x10 :
case 0x11 :
V_9 . type = V_47 ;
break;
case 0xd0 :
case 0x40 :
V_9 . type = V_48 ;
break;
}
break;
case 0x4000 :
case 0x4001 :
V_9 . type = V_49 ;
break;
case 0x700 :
V_9 . type = V_50 ;
V_9 . V_22 &= ~ V_28 ;
V_9 . V_10 . V_14 = 2 ;
V_9 . V_17 . V_14 = 2 ;
break;
case 0x600 :
V_9 . type = V_51 ;
V_9 . V_10 . V_14 = 2 ;
V_9 . V_17 . V_14 = 2 ;
break;
case 0x500 ... 0x501 :
switch ( V_2 ) {
case 0x10 :
V_9 . type = V_52 ;
break;
case 0x11 :
V_9 . type = V_53 ;
break;
case 0x50 ... 0x5f :
V_9 . type = V_54 ;
break;
}
V_9 . V_10 . V_14 = 2 ;
V_9 . V_17 . V_14 = 2 ;
break;
}
if ( V_9 . V_10 . V_14 > 1 ) {
V_4 = V_5 [ ( V_3 >> 20 ) & 0xf ] ;
V_9 . V_10 . V_11 = ( V_4 >> 1 ) ;
V_9 . V_10 . V_13 = ( V_4 >> 6 ) ;
}
if ( V_9 . V_17 . V_14 > 1 ) {
V_4 = V_5 [ ( V_3 >> 16 ) & 0xf ] ;
V_9 . V_17 . V_11 = ( V_4 >> 1 ) ;
V_9 . V_17 . V_13 = ( V_4 >> 6 ) ;
}
if ( V_9 . V_22 & V_42 ) {
if ( ( V_3 & 0xf ) == 0 )
V_9 . V_22 &= ~ V_42 ;
else {
V_3 ^= 0xf ;
V_4 = ( V_3 & 0xf ) << 17 ;
V_9 . V_55 . V_11 = ( 1 << 16 ) ;
V_9 . V_55 . V_12 = 5 ;
V_9 . V_55 . V_14 = 4 ;
V_9 . V_55 . V_15 = V_16 ;
V_9 . V_55 . V_56 =
( V_9 . V_55 . V_11 -
V_9 . V_55 . V_15 ) ;
V_9 . V_55 . V_13 = V_4 /
( V_9 . V_55 . V_15 *
V_9 . V_55 . V_14 ) ;
V_9 . V_55 . V_57 =
( V_9 . V_55 . V_13 *
V_9 . V_55 . V_15 ) ;
}
}
}
