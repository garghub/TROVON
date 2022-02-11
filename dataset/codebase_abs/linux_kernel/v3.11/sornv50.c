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
const T_2 V_13 = ( V_10 & V_14 ) >> 3 ;
const T_2 V_3 = ( V_10 & V_15 ) ;
T_1 V_4 ;
int V_16 = - V_17 ;
if ( V_11 < sizeof( T_1 ) )
return - V_17 ;
V_4 = * ( T_1 * ) args ;
switch ( V_10 & ~ 0x3f ) {
case V_18 :
V_16 = V_2 -> V_19 . V_20 ( V_2 , V_3 , V_4 ) ;
break;
case V_21 :
V_16 = V_2 -> V_19 . V_22 ( V_2 , V_3 , args , V_11 ) ;
break;
case V_23 :
V_16 = V_2 -> V_19 . V_24 ( V_2 , V_13 , V_3 , V_4 ) ;
break;
case V_25 :
V_2 -> V_19 . V_26 = V_4 & V_27 ;
V_16 = 0 ;
break;
default:
F_5 ( 1 ) ;
}
return V_16 ;
}
