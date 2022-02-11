void
F_1 ( union V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
union V_1 * V_7 ;
T_1 V_8 ;
F_2 ( V_9 , V_2 ) ;
if ( ! V_10 &&
! ( V_11 & V_12 ) ) {
V_13 ;
}
V_6 = ( ( T_1 ) F_3 () / 10 ) ;
V_6 &= 0x03FFFFFF ;
if ( ! ( ( V_3 > 0 ) && V_4 == 0 ) ) {
F_4 ( L_1 , V_6 , V_3 , L_2 ) ;
}
if ( V_4 > 0 ) {
F_4 ( L_3 , V_4 - 1 ) ;
}
if ( ! V_2 ) {
F_4 ( L_4 ) ;
V_13 ;
}
if ( F_5 ( V_2 ) == V_14 ) {
F_4 ( L_5 ,
F_6 ( V_2 ) ) ;
if ( ! F_7 ( V_2 ) ) {
F_4 ( L_6 ,
V_2 ) ;
V_13 ;
}
} else if ( F_5 ( V_2 ) ==
V_15 ) {
F_4 ( L_7 ,
F_8 ( ( (struct
V_16 * )
V_2 ) -> type ) ,
V_2 ) ;
V_13 ;
} else {
V_13 ;
}
switch ( V_2 -> V_17 . type ) {
case V_18 :
if ( V_19 == 4 ) {
F_4 ( L_8 ,
( T_1 ) V_2 -> integer . V_8 ) ;
} else {
F_4 ( L_9 ,
F_9 ( V_2 -> integer .
V_8 ) ) ;
}
break;
case V_20 :
F_4 ( L_10 , ( T_1 ) V_2 -> V_21 . V_22 ) ;
F_10 ( V_2 -> V_21 . V_23 ,
( V_2 -> V_21 . V_22 < 256 ) ?
V_2 -> V_21 . V_22 : 256 ,
V_24 , 0 ) ;
break;
case V_25 :
F_4 ( L_11 ,
V_2 -> string . V_22 ,
V_2 -> string . V_23 ) ;
break;
case V_26 :
F_4 ( L_12 ,
V_2 -> V_27 . V_28 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_27 . V_28 ; V_5 ++ ) {
F_1 ( V_2 -> V_27 .
V_29 [ V_5 ] , V_3 + 4 , V_5 + 1 ) ;
}
break;
case V_30 :
F_4 ( L_13 ,
F_11 ( V_2 ) ) ;
switch ( V_2 -> V_31 . V_32 ) {
case V_33 :
F_4 ( L_14 , V_2 -> V_31 . V_8 ) ;
break;
case V_34 :
F_4 ( L_15 ,
V_2 -> V_31 . V_8 ) ;
V_13 ;
default:
break;
}
F_4 ( L_2 ) ;
if ( V_2 -> V_31 . V_35 ) {
if ( F_5
( V_2 -> V_31 . V_35 ) !=
V_15 ) {
F_4
( L_16 ,
V_2 -> V_31 . V_35 ) ;
} else {
F_4 ( L_17 ,
V_2 -> V_31 . V_35 ,
( V_2 -> V_31 . V_35 ) ->
V_36 . V_37 ) ;
switch ( ( V_2 -> V_31 . V_35 ) -> type ) {
case V_38 :
F_4 ( L_18 ) ;
break;
case V_39 :
F_4 ( L_19 ) ;
break;
default:
F_1 ( ( V_2 ->
V_31 .
V_35 ) -> V_40 ,
V_3 + 4 , 0 ) ;
break;
}
}
} else if ( V_2 -> V_31 . V_40 ) {
if ( F_5
( V_2 -> V_31 . V_40 ) ==
V_15 ) {
F_1 ( ( (struct
V_16 * )
V_2 -> V_31 .
V_40 ) -> V_40 ,
V_3 + 4 , 0 ) ;
} else {
V_7 = V_2 -> V_31 . V_40 ;
V_8 = V_2 -> V_31 . V_8 ;
switch ( V_7 -> V_17 . type ) {
case V_20 :
F_4 ( L_20 ,
V_8 ,
* V_2 -> V_31 .
V_41 ) ;
break;
case V_25 :
F_4
( L_21 ,
V_8 ,
* V_2 -> V_31 .
V_41 ,
* V_2 -> V_31 .
V_41 ) ;
break;
case V_26 :
F_4 ( L_22 , V_8 ) ;
F_1 ( * V_2 ->
V_31 . V_42 ,
V_3 + 4 , 0 ) ;
break;
default:
F_4
( L_23 ,
V_7 -> V_17 . type ) ;
break;
}
}
}
break;
default:
F_4 ( L_24 , V_2 ) ;
break;
}
F_12 ( ( V_43 , L_25 ) ) ;
V_13 ;
}
