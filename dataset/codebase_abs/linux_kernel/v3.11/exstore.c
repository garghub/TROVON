T_1
F_1 ( union V_1 * V_2 ,
union V_1 * V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 = V_7 ;
union V_1 * V_8 = V_3 ;
F_2 ( V_9 , V_3 ) ;
if ( ! V_2 || ! V_3 ) {
F_3 ( ( V_10 , L_1 ) ) ;
F_4 ( V_11 ) ;
}
if ( F_5 ( V_3 ) == V_12 ) {
V_6 = F_6 ( V_2 ,
(struct
V_13 * )
V_3 , V_5 ,
V_14 ) ;
F_4 ( V_6 ) ;
}
switch ( V_3 -> V_15 . type ) {
case V_16 :
break;
case V_17 :
if ( V_3 -> V_15 . V_18 & V_19 ) {
F_4 ( V_7 ) ;
}
default:
F_3 ( ( V_10 ,
L_2 ,
F_7 ( V_3 ) ,
V_3 ) ) ;
F_4 ( V_20 ) ;
}
switch ( V_8 -> V_21 . V_22 ) {
case V_23 :
V_6 = F_6 ( V_2 ,
V_8 -> V_21 .
V_24 , V_5 ,
V_14 ) ;
break;
case V_25 :
V_6 =
F_8 ( V_2 , V_8 ,
V_5 ) ;
break;
case V_26 :
case V_27 :
V_6 =
F_9 ( V_8 -> V_21 . V_22 ,
V_8 -> V_21 . V_28 ,
V_2 , V_5 ) ;
break;
case V_29 :
F_10 ( ( V_30 ,
L_3 ,
V_2 ,
F_7 ( V_2 ) ) ) ;
F_11 ( V_2 , 0 , 0 ) ;
break;
default:
F_3 ( ( V_10 , L_4 ,
V_8 -> V_21 . V_22 ) ) ;
F_12 ( V_8 , V_31 ) ;
V_6 = V_32 ;
break;
}
F_4 ( V_6 ) ;
}
static T_1
F_8 ( union V_1 * V_2 ,
union V_1 * V_33 ,
struct V_4 * V_5 )
{
T_1 V_6 = V_7 ;
union V_1 * V_34 ;
union V_1 * V_35 ;
T_2 V_28 = 0 ;
T_3 V_36 ;
F_13 ( V_37 ) ;
switch ( V_33 -> V_21 . V_38 ) {
case V_39 :
V_34 = * ( V_33 -> V_21 . V_40 ) ;
if ( V_2 -> V_15 . type == V_16 &&
V_2 -> V_21 . V_22 == V_41 ) {
F_14 ( V_2 ) ;
V_35 = V_2 ;
} else {
V_6 =
F_15 ( V_2 ,
& V_35 ,
V_5 ) ;
if ( F_16 ( V_6 ) ) {
F_4 ( V_6 ) ;
}
}
if ( V_34 ) {
for ( V_36 = 0 ; V_36 < ( (union V_1 * )
V_33 -> V_21 . V_24 ) -> V_15 .
V_42 ; V_36 ++ ) {
F_17 ( V_34 ) ;
}
}
* ( V_33 -> V_21 . V_40 ) = V_35 ;
for ( V_36 = 1 ; V_36 < ( (union V_1 * )
V_33 -> V_21 . V_24 ) -> V_15 .
V_42 ; V_36 ++ ) {
F_14 ( V_35 ) ;
}
break;
case V_43 :
V_34 = V_33 -> V_21 . V_24 ;
if ( ( V_34 -> V_15 . type != V_44 ) &&
( V_34 -> V_15 . type != V_45 ) ) {
F_4 ( V_20 ) ;
}
switch ( V_2 -> V_15 . type ) {
case V_17 :
V_28 = ( T_2 ) ( V_2 -> integer . V_28 ) ;
break;
case V_44 :
case V_45 :
V_28 = V_2 -> V_46 . V_47 [ 0 ] ;
break;
default:
F_3 ( ( V_10 ,
L_5 ,
F_7 ( V_2 ) ) ) ;
F_4 ( V_20 ) ;
}
V_34 -> V_46 . V_47 [ V_33 -> V_21 . V_28 ] = V_28 ;
break;
default:
F_3 ( ( V_10 , L_6 ) ) ;
V_6 = V_20 ;
break;
}
F_4 ( V_6 ) ;
}
T_1
F_6 ( union V_1 * V_2 ,
struct V_13 * V_48 ,
struct V_4 * V_5 ,
T_2 V_49 )
{
T_1 V_6 = V_7 ;
union V_1 * V_50 ;
union V_1 * V_35 ;
T_4 V_38 ;
F_2 ( V_51 , V_2 ) ;
V_38 = F_18 ( V_48 ) ;
V_50 = F_19 ( V_48 ) ;
F_10 ( ( V_30 , L_7 ,
V_2 ,
F_7 ( V_2 ) , V_48 ,
F_20 ( V_38 ) ) ) ;
V_6 = F_21 ( & V_2 , V_38 , V_5 ) ;
if ( F_16 ( V_6 ) ) {
F_4 ( V_6 ) ;
}
if ( ( ! V_49 ) ||
( ( V_5 -> V_52 == V_53 ) &&
( V_38 != V_54 ) &&
( V_38 != V_55 ) &&
( V_38 != V_56 ) ) ) {
V_38 = V_57 ;
}
switch ( V_38 ) {
case V_43 :
case V_54 :
case V_55 :
case V_56 :
V_6 = F_22 ( V_2 , V_50 ,
& V_5 -> V_58 ) ;
break;
case V_17 :
case V_45 :
case V_44 :
V_6 =
F_23 ( V_2 , V_50 ,
& V_35 , V_5 ) ;
if ( F_16 ( V_6 ) ) {
F_4 ( V_6 ) ;
}
if ( V_35 != V_50 ) {
V_6 =
F_24 ( V_48 , V_35 ,
V_35 -> V_15 . type ) ;
F_10 ( ( V_30 ,
L_8 ,
F_7
( V_2 ) ,
F_7
( V_35 ) ) ) ;
}
break;
default:
F_10 ( ( V_30 ,
L_9
L_10 ,
F_7 ( V_2 ) ,
V_2 ,
F_7 ( V_50 ) ,
V_48 ) ) ;
V_6 =
F_15 ( V_2 , & V_35 ,
V_5 ) ;
if ( F_16 ( V_6 ) ) {
F_4 ( V_6 ) ;
}
V_6 =
F_24 ( V_48 , V_35 ,
V_35 -> V_15 . type ) ;
F_17 ( V_35 ) ;
break;
}
F_4 ( V_6 ) ;
}
