T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_5 ,
T_1 V_6 ,
union V_7 * * V_8 )
{
T_1 V_9 ;
const union V_10 * V_11 ;
V_11 = V_4 -> V_11 ;
if ( ! V_11 ) {
return ( V_12 ) ;
}
if ( ( V_6 != V_12 ) && ( V_6 != V_13 ) ) {
return ( V_12 ) ;
}
if ( V_14 ||
( ! V_11 -> V_4 . V_15 ) ||
( V_11 -> V_4 . V_15 == V_16 ) ) {
return ( V_12 ) ;
}
V_9 = F_2 ( V_4 , V_8 ,
V_11 -> V_4 . V_15 ,
V_17 ) ;
if ( F_3 ( V_9 ) ) {
goto exit;
}
if ( ! ( * V_8 ) ) {
goto exit;
}
if ( ( * V_8 ) -> V_18 . type == V_19 ) {
V_4 -> V_20 = * V_8 ;
V_9 = F_4 ( V_4 , V_8 ) ;
if ( F_3 ( V_9 ) ) {
if ( ( V_9 != V_21 ) &&
( V_9 != V_22 ) ) {
goto exit;
}
}
}
V_9 = F_5 ( V_4 , V_2 , V_9 , V_8 ) ;
exit:
if ( F_3 ( V_9 ) || ( V_4 -> V_23 & V_24 ) ) {
V_2 -> V_25 |= V_26 ;
}
return ( V_9 ) ;
}
T_1
F_2 ( struct V_3 * V_4 ,
union V_7 * * V_8 ,
T_2 V_15 , T_2 V_27 )
{
union V_7 * V_28 = * V_8 ;
T_1 V_9 = V_12 ;
char V_29 [ 96 ] ;
if ( V_28 &&
F_6 ( V_28 ) == V_30 ) {
F_7 ( ( V_31 , V_4 -> V_32 ,
V_4 -> V_33 ,
L_1 ,
V_28 -> V_2 . V_34 . V_35 ,
F_8 ( V_28 -> V_2 .
type ) ) ) ;
return ( V_21 ) ;
}
V_4 -> V_36 = F_9 ( V_28 ) ;
if ( V_4 -> V_36 == V_37 ) {
goto V_38;
}
if ( ( V_4 -> V_36 & V_15 ) == V_39 ) {
V_9 = F_10 ( V_4 , V_28 ) ;
return ( V_9 ) ;
}
V_9 = F_11 ( V_4 , V_15 ,
V_27 , V_8 ) ;
if ( F_12 ( V_9 ) ) {
return ( V_12 ) ;
}
V_38:
F_13 ( V_29 , V_15 ) ;
if ( ! V_28 ) {
F_7 ( ( V_31 , V_4 -> V_32 ,
V_4 -> V_33 ,
L_2 ,
V_29 ) ) ;
} else if ( V_27 == V_17 ) {
F_7 ( ( V_31 , V_4 -> V_32 ,
V_4 -> V_33 ,
L_3 ,
F_14
( V_28 ) , V_29 ) ) ;
} else {
F_7 ( ( V_31 , V_4 -> V_32 ,
V_4 -> V_33 ,
L_4
L_5 , V_27 ,
F_14
( V_28 ) , V_29 ) ) ;
}
return ( V_21 ) ;
}
static T_1
F_10 ( struct V_3 * V_4 ,
union V_7 * V_28 )
{
if ( V_28 -> V_40 . V_41 == V_42 ) {
return ( V_12 ) ;
}
F_7 ( ( V_31 , V_4 -> V_32 , V_4 -> V_33 ,
L_6 ,
F_15 ( V_28 ) ,
V_28 -> V_40 . V_41 ) ) ;
return ( V_21 ) ;
}
static T_2 F_9 ( union V_7 * V_28 )
{
T_2 V_36 ;
if ( ! V_28 ) {
return ( V_43 ) ;
}
switch ( V_28 -> V_18 . type ) {
case V_44 :
V_36 = V_45 ;
break;
case V_46 :
V_36 = V_47 ;
break;
case V_48 :
V_36 = V_49 ;
break;
case V_19 :
V_36 = V_50 ;
break;
case V_51 :
V_36 = V_39 ;
break;
default:
V_36 = V_37 ;
break;
}
return ( V_36 ) ;
}
