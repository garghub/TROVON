T_1
F_1 ( union V_1 * * V_2 ,
T_2 V_3 ,
struct V_4 * V_5 )
{
union V_1 * V_6 = * V_2 ;
T_1 V_7 = V_8 ;
F_2 ( V_9 ) ;
switch ( V_3 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
if ( V_6 -> V_17 . type == V_18 ) {
V_7 =
F_3 ( V_2 ,
V_5 ) ;
if ( F_4 ( V_7 ) ) {
break;
}
}
if ( V_5 -> V_19 == V_20 ) {
break;
}
if ( ( V_6 -> V_17 . type != V_14 ) &&
( V_6 -> V_17 . type != V_16 ) &&
( V_6 -> V_17 . type != V_15 ) &&
! ( ( V_6 -> V_17 . type == V_18 ) &&
( V_6 -> V_21 . V_22 == V_23 ) ) ) {
F_5 ( ( V_24 ,
L_1 ,
F_6 ( V_6 ) ,
F_7 ( V_3 ) ) ) ;
V_7 = V_25 ;
}
break;
case V_26 :
case V_27 :
F_5 ( ( V_24 , L_2 ) ) ;
V_7 = V_28 ;
break;
case V_29 :
default:
break;
}
F_8 ( V_7 ) ;
}
T_1
F_9 ( union V_1 * V_6 ,
union V_1 * V_30 ,
union V_1 * * V_31 ,
struct V_4 * V_5 )
{
union V_1 * V_32 ;
T_1 V_7 = V_8 ;
F_10 ( V_33 , V_6 ) ;
V_32 = V_6 ;
if ( ! V_30 ) {
V_7 =
F_11 ( V_32 , V_31 ,
V_5 ) ;
F_8 ( V_7 ) ;
}
if ( V_6 -> V_17 . type != V_30 -> V_17 . type ) {
V_7 = F_12 ( V_30 -> V_17 . type ,
V_6 ,
& V_32 ,
V_5 ) ;
if ( F_4 ( V_7 ) ) {
F_8 ( V_7 ) ;
}
if ( V_6 == V_32 ) {
* V_31 = V_6 ;
F_8 ( V_8 ) ;
}
}
switch ( V_30 -> V_17 . type ) {
case V_14 :
V_30 -> integer . V_34 = V_32 -> integer . V_34 ;
F_13 ( V_30 ) ;
break;
case V_15 :
V_7 =
F_14 ( V_32 , V_30 ) ;
break;
case V_16 :
V_7 =
F_15 ( V_32 , V_30 ) ;
break;
case V_29 :
V_7 =
F_11 ( V_32 , & V_30 ,
V_5 ) ;
break;
default:
F_16 ( ( V_24 , L_3 ,
F_6 ( V_30 ) ) ) ;
V_7 = V_35 ;
break;
}
if ( V_32 != V_6 ) {
F_17 ( V_32 ) ;
}
* V_31 = V_30 ;
F_8 ( V_7 ) ;
}
