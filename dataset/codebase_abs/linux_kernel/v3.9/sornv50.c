int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
const T_1 V_5 = V_4 & V_6 ;
const T_1 V_7 = ( V_3 * 0x800 ) ;
F_2 ( V_2 , 0x61c004 + V_7 , 0x80000000 , 0x00000000 ) ;
F_3 ( V_2 , 0x61c004 + V_7 , 0x80000001 , 0x80000000 | V_5 ) ;
F_2 ( V_2 , 0x61c004 + V_7 , 0x80000000 , 0x00000000 ) ;
F_2 ( V_2 , 0x61c030 + V_7 , 0x10000000 , 0x00000000 ) ;
return 0 ;
}
int
F_4 ( struct V_8 * V_9 , T_1 V_10 , void * args , T_1 V_11 )
{
struct V_1 * V_2 = ( void * ) V_9 -> V_12 ;
struct V_13 * V_14 = V_13 ( V_2 ) ;
const T_2 type = ( V_10 & V_15 ) >> 12 ;
const T_3 V_16 = ( V_10 & V_17 ) >> 3 ;
const T_3 V_18 = ( V_10 & V_19 ) >> 2 ;
const T_3 V_3 = ( V_10 & V_20 ) ;
const T_2 V_21 = ( 0x0100 << V_16 ) | ( 0x0040 << V_18 ) | ( 0x0001 << V_3 ) ;
struct V_22 V_23 ;
T_3 V_24 , V_25 ;
T_1 V_4 ;
int V_26 = - V_27 ;
if ( V_11 < sizeof( T_1 ) )
return - V_27 ;
V_4 = * ( T_1 * ) args ;
if ( type && ! F_5 ( V_14 , type , V_21 , & V_24 , & V_25 , & V_23 ) )
return - V_28 ;
switch ( V_10 & ~ 0x3f ) {
case V_29 :
V_26 = V_2 -> V_30 . V_31 ( V_2 , V_3 , V_4 ) ;
break;
case V_32 :
V_26 = V_2 -> V_30 . V_33 ( V_2 , V_3 , args , V_11 ) ;
break;
case V_34 :
V_26 = V_2 -> V_30 . V_35 ( V_2 , V_16 , V_3 , V_4 ) ;
break;
case V_36 :
V_2 -> V_30 . V_37 = V_4 & V_38 ;
V_26 = 0 ;
break;
default:
F_6 ( 1 ) ;
}
return V_26 ;
}
