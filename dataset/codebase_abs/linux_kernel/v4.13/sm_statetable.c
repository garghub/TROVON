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
enum V_20 V_21 ,
T_3 V_3 )
{
if ( V_3 > V_22 )
return & V_19 ;
if ( V_21 <= V_23 )
return & V_24 [ V_21 ] [ V_3 ] ;
if ( V_1 -> V_25 . V_26 ) {
if ( V_21 == V_27 )
return & V_28 [ 0 ] [ V_3 ] ;
}
if ( V_1 -> V_25 . V_29 ) {
if ( V_21 == V_30 )
return & V_31 [ 0 ] [ V_3 ] ;
if ( V_21 == V_32 )
return & V_31 [ 1 ] [ V_3 ] ;
}
if ( V_1 -> V_25 . V_33 )
if ( V_21 == V_34 )
return & V_35 [ 0 ] [ V_3 ] ;
if ( V_1 -> V_25 . V_36 ) {
if ( V_21 == V_37 )
return & V_38 [ 0 ] [ V_3 ] ;
}
return & V_39 [ V_3 ] ;
}
