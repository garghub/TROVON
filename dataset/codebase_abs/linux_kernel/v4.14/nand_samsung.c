static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 == 6 && ! F_3 ( V_2 ) &&
V_2 -> V_5 . V_7 [ 5 ] != 0x00 ) {
T_1 V_8 = V_2 -> V_5 . V_7 [ 3 ] ;
V_4 -> V_9 = 2048 << ( V_8 & 0x03 ) ;
V_8 >>= 2 ;
switch ( ( ( V_8 >> 2 ) & 0x4 ) | ( V_8 & 0x3 ) ) {
case 1 :
V_4 -> V_10 = 128 ;
break;
case 2 :
V_4 -> V_10 = 218 ;
break;
case 3 :
V_4 -> V_10 = 400 ;
break;
case 4 :
V_4 -> V_10 = 436 ;
break;
case 5 :
V_4 -> V_10 = 512 ;
break;
case 6 :
V_4 -> V_10 = 640 ;
break;
default:
F_4 ( 1 , L_1 ) ;
break;
}
V_8 >>= 2 ;
V_4 -> V_11 = ( 128 * 1024 ) <<
( ( ( V_8 >> 1 ) & 0x04 ) | ( V_8 & 0x03 ) ) ;
V_8 = ( V_2 -> V_5 . V_7 [ 4 ] >> 4 ) & 0x07 ;
if ( V_8 < 5 ) {
V_2 -> V_12 = 512 ;
V_2 -> V_13 = 1 << V_8 ;
} else {
V_2 -> V_12 = 1024 ;
switch ( V_8 ) {
case 5 :
V_2 -> V_13 = 24 ;
break;
case 6 :
V_2 -> V_13 = 40 ;
break;
case 7 :
V_2 -> V_13 = 60 ;
break;
default:
F_4 ( 1 , L_2 ) ;
V_2 -> V_12 = 0 ;
}
}
} else {
F_5 ( V_2 ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_9 > 512 )
V_2 -> V_14 |= V_15 ;
if ( ! F_3 ( V_2 ) )
V_2 -> V_16 |= V_17 ;
else
V_2 -> V_16 |= V_18 ;
return 0 ;
}
