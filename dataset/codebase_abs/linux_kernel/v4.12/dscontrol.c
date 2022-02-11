T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
T_1 V_5 = V_6 ;
union V_7 * V_8 ;
F_2 ( V_9 ) ;
F_3 ( ( V_10 , L_1 ,
V_4 , V_4 -> V_11 . V_12 , V_2 ) ) ;
switch ( V_4 -> V_11 . V_12 ) {
case V_13 :
if ( V_2 -> V_8 ) {
if ( V_2 -> V_8 -> V_14 .
V_15 ==
( V_2 -> V_16 . V_17 - 1 ) ) {
V_2 -> V_8 -> V_11 . V_18 =
V_19 ;
break;
}
}
case V_20 :
V_8 = F_4 () ;
if ( ! V_8 ) {
V_5 = V_21 ;
break;
}
V_8 -> V_14 . V_15 =
V_2 -> V_16 . V_17 - 1 ;
V_8 -> V_14 . V_22 =
V_2 -> V_16 . V_23 ;
V_8 -> V_14 . V_24 = V_4 -> V_11 . V_12 ;
F_5 ( & V_2 -> V_8 ,
V_8 ) ;
break;
case V_25 :
if ( V_2 -> V_26 ) {
V_5 = V_27 ;
}
break;
case V_28 :
break;
default:
break;
}
return ( V_5 ) ;
}
T_1
F_6 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
T_1 V_5 = V_6 ;
union V_7 * V_8 ;
F_2 ( V_29 ) ;
switch ( V_4 -> V_11 . V_12 ) {
case V_20 :
F_3 ( ( V_10 , L_2 , V_4 ) ) ;
V_2 -> V_26 =
( V_30 ) V_2 -> V_8 -> V_11 . V_31 ;
V_8 =
F_7 ( & V_2 -> V_8 ) ;
F_8 ( V_8 ) ;
break;
case V_25 :
break;
case V_13 :
F_3 ( ( V_10 , L_3 , V_4 ) ) ;
V_8 = V_2 -> V_8 ;
if ( V_8 -> V_11 . V_31 ) {
V_8 -> V_14 . V_32 ++ ;
if ( V_8 -> V_14 . V_32 >
V_33 ) {
V_5 = V_34 ;
break;
}
V_5 = V_35 ;
V_2 -> V_36 =
V_8 -> V_14 . V_15 ;
break;
}
F_3 ( ( V_10 ,
L_4 , V_4 ) ) ;
V_8 =
F_7 ( & V_2 -> V_8 ) ;
F_8 ( V_8 ) ;
break;
case V_28 :
F_3 ( ( V_10 ,
L_5 , V_4 ,
V_4 -> V_11 . V_31 . V_37 ) ) ;
if ( V_4 -> V_11 . V_31 . V_37 ) {
F_9 ( V_2 ) ;
V_5 =
F_10 ( V_2 ,
V_4 -> V_11 . V_31 . V_37 ) ;
if ( F_11 ( V_5 ) ) {
return ( V_5 ) ;
}
V_5 =
F_12 ( & V_2 -> V_38 [ 0 ] ,
V_2 ) ;
if ( F_11 ( V_5 ) ) {
return ( V_5 ) ;
}
V_2 -> V_39 = V_2 -> V_38 [ 0 ] ;
} else if ( V_2 -> V_40 ) {
F_9 ( V_2 ) ;
if ( ( F_13
( V_2 -> V_41 -> V_41 . V_42 [ 0 ] ) ==
V_43 )
&& ( ( V_2 -> V_41 -> V_41 . V_42 [ 0 ] ) ->
V_11 . type == V_44 )
&& ( ( V_2 -> V_41 -> V_41 . V_42 [ 0 ] ) ->
V_45 . V_46 != V_47 ) ) {
V_5 =
F_12 ( & V_2 ->
V_41 -> V_41 .
V_42 [ 0 ] ,
V_2 ) ;
if ( F_11 ( V_5 ) ) {
return ( V_5 ) ;
}
}
V_2 -> V_39 =
V_2 -> V_41 -> V_41 . V_42 [ 0 ] ;
} else {
if ( V_2 -> V_48 ) {
F_14 ( V_2 ->
V_38 [ 0 ] ) ;
}
V_2 -> V_38 [ 0 ] = NULL ;
V_2 -> V_48 = 0 ;
V_2 -> V_39 = NULL ;
}
F_3 ( ( V_10 ,
L_6 ,
V_2 , V_2 -> V_39 ) ) ;
V_5 = V_49 ;
break;
case V_50 :
break;
case V_51 :
F_15 ( V_2 ) ;
V_5 = F_16 ( V_52 ,
L_7 ) ;
break;
case V_53 :
case V_54 :
while ( V_2 -> V_8 &&
( V_2 -> V_8 -> V_14 . V_24 !=
V_13 ) ) {
V_8 =
F_7 ( & V_2 ->
V_8 ) ;
F_8 ( V_8 ) ;
}
if ( ! V_2 -> V_8 ) {
return ( V_55 ) ;
}
V_2 -> V_36 =
V_2 -> V_8 -> V_14 . V_22 ;
if ( V_4 -> V_11 . V_12 == V_53 ) {
V_5 = V_56 ;
} else {
V_5 = V_57 ;
}
break;
default:
F_17 ( ( V_58 , L_8 ,
V_4 -> V_11 . V_12 , V_4 ) ) ;
V_5 = V_59 ;
break;
}
return ( V_5 ) ;
}
