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
F_9 ( ( V_24 , L_2 ,
V_10 -> V_25 . V_26 , V_10 ) ) ;
F_8 ( V_27 ) ;
}
switch ( V_11 ) {
case V_28 :
if ( V_8 -> V_29 . type != V_28 ) {
F_9 ( ( V_24 , L_3 ,
F_10 ( V_8 ) ) ) ;
F_8 ( V_30 ) ;
}
V_5 = F_11 ( V_8 ) ;
if ( F_12 ( V_5 ) ) {
V_9 = V_8 ;
F_13 ( V_9 ) ;
}
break;
case V_31 :
if ( V_8 -> V_29 . type != V_31 ) {
F_9 ( ( V_24 , L_4 ,
F_10 ( V_8 ) ) ) ;
F_8 ( V_30 ) ;
}
V_5 = F_14 ( V_8 ) ;
if ( F_12 ( V_5 ) ) {
V_9 = V_8 ;
F_13 ( V_9 ) ;
}
break;
case V_32 :
if ( V_8 -> V_29 . type != V_32 ) {
F_9 ( ( V_24 , L_5 ,
F_10 ( V_8 ) ) ) ;
F_8 ( V_30 ) ;
}
V_9 = V_8 ;
F_13 ( V_9 ) ;
break;
case V_33 :
if ( V_8 -> V_29 . type != V_33 ) {
F_9 ( ( V_24 , L_6 ,
F_10 ( V_8 ) ) ) ;
F_8 ( V_30 ) ;
}
V_9 = V_8 ;
F_13 ( V_9 ) ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
F_5 ( ( V_14 ,
L_7 ,
V_10 , V_8 , V_11 ) ) ;
V_5 =
F_15 ( V_4 , V_8 ,
& V_9 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
V_9 = V_8 ;
F_13 ( V_9 ) ;
break;
case V_43 :
F_9 ( ( V_24 ,
L_8 , V_10 ) ) ;
F_8 ( V_30 ) ;
case V_44 :
switch ( V_8 -> V_45 . V_46 ) {
case V_47 :
case V_48 :
case V_49 :
V_9 = V_8 ;
F_13 ( V_9 ) ;
break;
default:
F_9 ( ( V_24 ,
L_9 ,
V_8 -> V_45 . V_46 ) ) ;
F_8 ( V_30 ) ;
}
break;
default:
F_9 ( ( V_24 ,
L_10 ,
V_10 , V_11 ) ) ;
F_8 ( V_30 ) ;
}
* V_2 = ( void * ) V_9 ;
F_8 ( V_5 ) ;
}
