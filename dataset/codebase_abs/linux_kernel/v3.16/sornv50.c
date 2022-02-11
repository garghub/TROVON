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
const T_2 type = ( V_10 & V_13 ) >> 12 ;
const T_2 V_14 = ( V_10 & V_15 ) >> 3 ;
const T_2 V_16 = ( V_10 & V_17 ) >> 2 ;
const T_2 V_3 = ( V_10 & V_18 ) ;
const T_3 V_19 = ( 0x0100 << V_14 ) | ( 0x0040 << V_16 ) | ( 0x0001 << V_3 ) ;
struct V_20 * V_21 = NULL , * V_22 ;
T_1 V_4 ;
int V_23 = - V_24 ;
if ( V_11 < sizeof( T_1 ) )
return - V_24 ;
V_4 = * ( T_1 * ) args ;
F_5 (temp, &priv->base.outp, head) {
if ( ( V_22 -> V_25 . V_26 & 0xff ) == type &&
( V_22 -> V_25 . V_27 & V_19 ) == V_19 ) {
V_21 = V_22 ;
break;
}
}
switch ( V_10 & ~ 0x3f ) {
case V_28 :
V_23 = V_2 -> V_29 . V_30 ( V_2 , V_3 , V_4 ) ;
break;
case V_31 :
V_23 = V_2 -> V_29 . V_32 ( V_2 , V_3 , args , V_11 ) ;
break;
case V_33 :
V_23 = V_2 -> V_29 . V_34 ( V_2 , V_14 , V_3 , V_4 ) ;
break;
case V_35 :
V_2 -> V_29 . V_36 = V_4 & V_37 ;
V_23 = 0 ;
break;
case V_38 :
if ( V_21 ) {
struct V_39 * V_40 = ( void * ) V_21 ;
switch ( V_4 ) {
case V_41 :
F_6 ( V_40 -> V_42 ) ;
( (struct V_43 * ) F_7 ( V_21 ) )
-> F_8 ( V_40 , 0 ) ;
F_9 ( & V_40 -> V_44 . V_45 , 0 ) ;
break;
case V_46 :
F_10 ( & V_40 -> V_47 , 0 , true ) ;
break;
default:
return - V_24 ;
}
}
break;
default:
F_11 ( 1 ) ;
}
return V_23 ;
}
