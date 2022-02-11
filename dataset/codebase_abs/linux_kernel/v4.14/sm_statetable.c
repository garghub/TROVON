const struct V_1 * F_1 (
struct V_2 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 ,
union V_7 V_8 )
{
switch ( V_4 ) {
case V_9 :
return F_2 ( V_2 , V_8 . V_10 , V_6 ) ;
case V_11 :
return F_3 ( V_12 , V_13 ,
V_14 ) ;
case V_15 :
return F_3 ( V_16 , V_17 ,
V_18 ) ;
case V_19 :
return F_3 ( V_20 , V_21 ,
V_22 ) ;
default:
return & V_23 ;
}
}
static const struct V_1 * F_2 (
struct V_2 * V_2 ,
enum V_24 V_25 ,
enum V_5 V_6 )
{
if ( V_6 > V_26 )
return & V_23 ;
if ( V_25 <= V_27 )
return & V_28 [ V_25 ] [ V_6 ] ;
if ( V_2 -> V_29 . V_30 ) {
if ( V_25 == V_31 )
return & V_32 [ 0 ] [ V_6 ] ;
}
if ( V_2 -> V_29 . V_33 ) {
if ( V_25 == V_34 )
return & V_35 [ 0 ] [ V_6 ] ;
if ( V_25 == V_36 )
return & V_35 [ 1 ] [ V_6 ] ;
}
if ( V_2 -> V_29 . V_37 )
if ( V_25 == V_38 )
return & V_39 [ 0 ] [ V_6 ] ;
if ( V_2 -> V_29 . V_40 ) {
if ( V_25 == V_41 )
return & V_42 [ 0 ] [ V_6 ] ;
}
return & V_43 [ V_6 ] ;
}
