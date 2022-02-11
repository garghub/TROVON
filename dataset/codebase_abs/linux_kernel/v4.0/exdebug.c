void
F_1 ( union V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
F_2 ( V_7 , V_2 ) ;
if ( ! V_8 &&
! ( V_9 & V_10 ) ) {
V_11 ;
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
V_11 ;
}
if ( F_5 ( V_2 ) == V_12 ) {
F_4 ( L_5 ,
F_6 ( V_2 ) ) ;
if ( ! F_7 ( V_2 ) ) {
F_4 ( L_6 ,
V_2 ) ;
V_11 ;
}
} else if ( F_5 ( V_2 ) ==
V_13 ) {
F_4 ( L_7 ,
F_8 ( ( (struct
V_14 * )
V_2 ) -> type ) ,
V_2 ) ;
V_11 ;
} else {
V_11 ;
}
switch ( V_2 -> V_15 . type ) {
case V_16 :
if ( V_17 == 4 ) {
F_4 ( L_8 ,
( T_1 ) V_2 -> integer . V_18 ) ;
} else {
F_4 ( L_9 ,
F_9 ( V_2 -> integer .
V_18 ) ) ;
}
break;
case V_19 :
F_4 ( L_10 , ( T_1 ) V_2 -> V_20 . V_21 ) ;
F_10 ( V_2 -> V_20 . V_22 ,
( V_2 -> V_20 . V_21 < 256 ) ?
V_2 -> V_20 . V_21 : 256 ,
V_23 , 0 ) ;
break;
case V_24 :
F_4 ( L_11 ,
V_2 -> string . V_21 ,
V_2 -> string . V_22 ) ;
break;
case V_25 :
F_4 ( L_12 ,
V_2 -> V_26 . V_27 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_26 . V_27 ; V_5 ++ ) {
F_1 ( V_2 -> V_26 .
V_28 [ V_5 ] , V_3 + 4 , V_5 + 1 ) ;
}
break;
case V_29 :
F_4 ( L_13 ,
F_11 ( V_2 ) ) ;
switch ( V_2 -> V_30 . V_31 ) {
case V_32 :
F_4 ( L_14 , V_2 -> V_30 . V_18 ) ;
break;
case V_33 :
F_4 ( L_15 ,
V_2 -> V_30 . V_18 ) ;
V_11 ;
default:
break;
}
F_4 ( L_2 ) ;
if ( V_2 -> V_30 . V_34 ) {
if ( F_5
( V_2 -> V_30 . V_34 ) !=
V_13 ) {
F_4
( L_16 ,
V_2 -> V_30 . V_34 ) ;
} else {
F_4 ( L_17 ,
V_2 -> V_30 . V_34 ,
( V_2 -> V_30 . V_34 ) ->
V_35 . V_36 ) ;
switch ( ( V_2 -> V_30 . V_34 ) -> type ) {
case V_37 :
F_4 ( L_18 ) ;
break;
case V_38 :
F_4 ( L_19 ) ;
break;
default:
F_1 ( ( V_2 ->
V_30 .
V_34 ) -> V_39 ,
V_3 + 4 , 0 ) ;
break;
}
}
} else if ( V_2 -> V_30 . V_39 ) {
if ( F_5
( V_2 -> V_30 . V_39 ) ==
V_13 ) {
F_1 ( ( (struct
V_14 * )
V_2 -> V_30 .
V_39 ) -> V_39 ,
V_3 + 4 , 0 ) ;
} else {
F_1 ( V_2 -> V_30 .
V_39 , V_3 + 4 , 0 ) ;
}
}
break;
default:
F_4 ( L_20 , V_2 ) ;
break;
}
F_12 ( ( V_40 , L_21 ) ) ;
V_11 ;
}
