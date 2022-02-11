const T_1 * F_1 ( T_2 V_1 ,
T_3 V_2 ,
T_4 V_3 )
{
switch ( V_1 ) {
case V_4 :
return F_2 ( V_3 . V_5 , V_2 ) ;
case V_6 :
return F_3 ( V_7 , V_8 ,
V_9 ) ;
case V_10 :
return F_3 ( V_11 , V_12 ,
V_13 ) ;
case V_14 :
return F_3 ( V_15 , V_16 ,
V_17 ) ;
default:
return & V_18 ;
}
}
static const T_1 * F_2 ( T_5 V_19 ,
T_3 V_2 )
{
if ( V_2 > V_20 )
return & V_18 ;
if ( V_19 <= V_21 )
return & V_22 [ V_19 ] [ V_2 ] ;
if ( V_23 ) {
if ( V_19 == V_24 )
return & V_25 [ 0 ] [ V_2 ] ;
}
if ( V_26 ) {
if ( V_19 == V_27 )
return & V_28 [ 0 ] [ V_2 ] ;
if ( V_19 == V_29 )
return & V_28 [ 1 ] [ V_2 ] ;
}
if ( V_30 ) {
if ( V_19 == V_31 )
return & V_32 [ 0 ] [ V_2 ] ;
}
return & V_33 [ V_2 ] ;
}
