int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
const T_1 V_5 = ( V_4 & V_6 ) |
( V_4 & V_7 ) |
( V_4 & V_8 ) |
( V_4 & V_9 ) ;
const T_1 V_10 = ( V_3 * 0x800 ) ;
F_2 ( V_2 , 0x61a004 + V_10 , 0x80000000 , 0x00000000 ) ;
F_3 ( V_2 , 0x61a004 + V_10 , 0xc000007f , 0x80000000 | V_5 ) ;
F_2 ( V_2 , 0x61a004 + V_10 , 0x80000000 , 0x00000000 ) ;
return 0 ;
}
int
F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_11 )
{
const T_1 V_10 = ( V_3 * 0x800 ) ;
F_3 ( V_2 , 0x61a004 + V_10 , 0x807f0000 , 0x80150000 ) ;
F_2 ( V_2 , 0x61a004 + V_10 , 0x80000000 , 0x00000000 ) ;
F_5 ( V_2 , 0x61a00c + V_10 , 0x00100000 | V_11 ) ;
F_6 ( 9 ) ;
F_7 ( 500 ) ;
V_11 = F_3 ( V_2 , 0x61a00c + V_10 , 0xffffffff , 0x00000000 ) ;
F_3 ( V_2 , 0x61a004 + V_10 , 0x807f0000 , 0x80550000 ) ;
F_2 ( V_2 , 0x61a004 + V_10 , 0x80000000 , 0x00000000 ) ;
F_8 ( V_2 , L_1 , V_3 , V_11 ) ;
if ( ! ( V_11 & 0x80000000 ) )
return - V_12 ;
return ( V_11 & 0x38000000 ) >> 27 ;
}
int
F_9 ( struct V_13 * V_14 , T_1 V_15 , void * args , T_1 V_16 )
{
struct V_1 * V_2 = ( void * ) V_14 -> V_17 ;
const T_2 V_3 = ( V_15 & V_18 ) ;
T_1 * V_4 = args ;
int V_19 ;
if ( V_16 < sizeof( T_1 ) )
return - V_20 ;
switch ( V_15 & ~ 0x3f ) {
case V_21 :
V_19 = V_2 -> V_22 . V_23 ( V_2 , V_3 , V_4 [ 0 ] ) ;
break;
case V_24 :
V_19 = V_2 -> V_22 . V_25 ( V_2 , V_3 , V_4 [ 0 ] ) ;
if ( V_19 >= 0 ) {
V_4 [ 0 ] = V_19 ;
V_19 = 0 ;
}
break;
default:
F_10 ( 1 ) ;
}
return V_19 ;
}
