const T_1 * F_1 ( struct V_1 * V_1 ,
T_2 V_2 ,
T_3 V_3 ,
T_4 V_4 )
{
switch ( V_2 ) {
case V_5 :
return F_2 ( V_1 , V_4 . V_6 , V_3 ) ;
case V_7 :
return F_3 ( V_8 , V_9 ,
V_10 ) ;
case V_11 :
return F_3 ( V_12 , V_13 ,
V_14 ) ;
case V_15 :
return F_3 ( V_16 , V_17 ,
V_18 ) ;
default:
return & V_19 ;
}
}
static const T_1 * F_2 ( struct V_1 * V_1 ,
T_5 V_20 ,
T_3 V_3 )
{
if ( V_3 > V_21 )
return & V_19 ;
if ( V_20 <= V_22 )
return & V_23 [ V_20 ] [ V_3 ] ;
if ( V_1 -> V_24 . V_25 ) {
if ( V_20 == V_26 )
return & V_27 [ 0 ] [ V_3 ] ;
}
if ( V_1 -> V_24 . V_28 ) {
if ( V_20 == V_29 )
return & V_30 [ 0 ] [ V_3 ] ;
if ( V_20 == V_31 )
return & V_30 [ 1 ] [ V_3 ] ;
}
if ( V_1 -> V_24 . V_32 )
if ( V_20 == V_33 )
return & V_34 [ 0 ] [ V_3 ] ;
if ( V_1 -> V_24 . V_35 ) {
if ( V_20 == V_36 )
return & V_37 [ 0 ] [ V_3 ] ;
}
return & V_38 [ V_3 ] ;
}
