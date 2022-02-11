T_1
F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_6 ;
union V_7 * V_8 ;
union V_7 * V_9 = NULL ;
struct V_1 * V_10 ;
T_2 V_11 ;
F_2 ( V_12 ) ;
V_10 = * V_2 ;
V_8 = F_3 ( V_10 ) ;
V_11 = F_4 ( ( V_13 ) V_10 ) ;
F_5 ( ( V_14 , L_1 ,
V_10 , V_8 ,
F_6 ( V_11 ) ) ) ;
if ( ( V_11 == V_15 ) ||
( V_11 == V_16 ) ) {
V_10 = F_7 ( struct V_1 , V_10 -> V_17 ) ;
V_8 = F_3 ( V_10 ) ;
V_11 = F_4 ( ( V_13 ) V_10 ) ;
* V_2 = V_10 ;
}
if ( ( V_11 == V_18 ) ||
( V_11 == V_19 ) ||
( V_11 == V_20 ) ||
( V_10 -> V_21 & ( V_22 | V_23 ) ) ) {
F_8 ( V_6 ) ;
}
if ( ! V_8 ) {
F_9 ( ( V_24 , L_2 , V_10 ) ) ;
F_8 ( V_25 ) ;
}
switch ( V_11 ) {
case V_26 :
if ( V_8 -> V_27 . type != V_26 ) {
F_9 ( ( V_24 , L_3 ,
F_10 ( V_8 ) ) ) ;
F_8 ( V_28 ) ;
}
V_5 = F_11 ( V_8 ) ;
if ( F_12 ( V_5 ) ) {
V_9 = V_8 ;
F_13 ( V_9 ) ;
}
break;
case V_29 :
if ( V_8 -> V_27 . type != V_29 ) {
F_9 ( ( V_24 , L_4 ,
F_10 ( V_8 ) ) ) ;
F_8 ( V_28 ) ;
}
V_5 = F_14 ( V_8 ) ;
if ( F_12 ( V_5 ) ) {
V_9 = V_8 ;
F_13 ( V_9 ) ;
}
break;
case V_30 :
if ( V_8 -> V_27 . type != V_30 ) {
F_9 ( ( V_24 , L_5 ,
F_10 ( V_8 ) ) ) ;
F_8 ( V_28 ) ;
}
V_9 = V_8 ;
F_13 ( V_9 ) ;
break;
case V_31 :
if ( V_8 -> V_27 . type != V_31 ) {
F_9 ( ( V_24 , L_6 ,
F_10 ( V_8 ) ) ) ;
F_8 ( V_28 ) ;
}
V_9 = V_8 ;
F_13 ( V_9 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
F_5 ( ( V_14 ,
L_7 ,
V_10 , V_8 , V_11 ) ) ;
V_5 =
F_15 ( V_4 , V_8 ,
& V_9 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_9 = V_8 ;
F_13 ( V_9 ) ;
break;
case V_41 :
F_9 ( ( V_24 ,
L_8 , V_10 ) ) ;
F_8 ( V_28 ) ;
case V_42 :
switch ( V_8 -> V_43 . V_44 ) {
case V_45 :
case V_46 :
case V_47 :
V_9 = V_8 ;
F_13 ( V_9 ) ;
break;
default:
F_9 ( ( V_24 ,
L_9 ,
V_8 -> V_43 . V_44 ) ) ;
F_8 ( V_28 ) ;
}
break;
default:
F_9 ( ( V_24 ,
L_10 ,
V_10 , V_11 ) ) ;
F_8 ( V_28 ) ;
}
* V_2 = ( void * ) V_9 ;
F_8 ( V_5 ) ;
}
