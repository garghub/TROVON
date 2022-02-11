void
F_1 ( union V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_5 ;
F_2 ( V_6 , V_2 ) ;
if ( ! V_7 &&
! ( V_8 & V_9 ) ) {
V_10 ;
}
if ( ! ( ( V_3 > 0 ) && V_4 == 0 ) ) {
F_3 ( L_1 , V_3 , L_2 ) ;
}
if ( V_4 > 0 ) {
F_3 ( L_3 , V_4 - 1 ) ;
}
if ( ! V_2 ) {
F_3 ( L_4 ) ;
V_10 ;
}
if ( F_4 ( V_2 ) == V_11 ) {
F_3 ( L_5 ,
F_5 ( V_2 ) ) ;
if ( ! F_6 ( V_2 ) ) {
F_3 ( L_6 ,
V_2 ) ;
V_10 ;
}
} else if ( F_4 ( V_2 ) ==
V_12 ) {
F_3 ( L_7 ,
F_7 ( ( (struct
V_13 * )
V_2 ) -> type ) ,
V_2 ) ;
V_10 ;
} else {
V_10 ;
}
switch ( V_2 -> V_14 . type ) {
case V_15 :
if ( V_16 == 4 ) {
F_3 ( L_8 ,
( T_1 ) V_2 -> integer . V_17 ) ;
} else {
F_3 ( L_9 ,
F_8 ( V_2 -> integer .
V_17 ) ) ;
}
break;
case V_18 :
F_3 ( L_10 , ( T_1 ) V_2 -> V_19 . V_20 ) ;
F_9 ( V_2 -> V_19 . V_21 ,
( V_2 -> V_19 . V_20 < 256 ) ?
V_2 -> V_19 . V_20 : 256 ,
V_22 , 0 ) ;
break;
case V_23 :
F_3 ( L_11 ,
V_2 -> string . V_20 ,
V_2 -> string . V_21 ) ;
break;
case V_24 :
F_3 ( L_12 ,
V_2 -> V_25 . V_26 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_25 . V_26 ; V_5 ++ ) {
F_1 ( V_2 -> V_25 .
V_27 [ V_5 ] , V_3 + 4 , V_5 + 1 ) ;
}
break;
case V_28 :
F_3 ( L_13 ,
F_10 ( V_2 ) ) ;
switch ( V_2 -> V_29 . V_30 ) {
case V_31 :
F_3 ( L_14 , V_2 -> V_29 . V_17 ) ;
break;
case V_32 :
F_3 ( L_15 ,
V_2 -> V_29 . V_17 ) ;
V_10 ;
default:
break;
}
F_3 ( L_2 ) ;
if ( V_2 -> V_29 . V_33 ) {
if ( F_4
( V_2 -> V_29 . V_33 ) !=
V_12 ) {
F_3
( L_16 ,
V_2 -> V_29 . V_33 ) ;
} else {
F_3 ( L_17 ,
V_2 -> V_29 . V_33 ,
( V_2 -> V_29 . V_33 ) ->
V_34 . V_35 ) ;
switch ( ( V_2 -> V_29 . V_33 ) -> type ) {
case V_36 :
F_3 ( L_18 ) ;
break;
case V_37 :
F_3 ( L_19 ) ;
break;
default:
F_1 ( ( V_2 ->
V_29 .
V_33 ) -> V_38 ,
V_3 + 4 , 0 ) ;
break;
}
}
} else if ( V_2 -> V_29 . V_38 ) {
if ( F_4
( V_2 -> V_29 . V_38 ) ==
V_12 ) {
F_1 ( ( (struct
V_13 * )
V_2 -> V_29 .
V_38 ) -> V_38 ,
V_3 + 4 , 0 ) ;
} else {
F_1 ( V_2 -> V_29 .
V_38 , V_3 + 4 , 0 ) ;
}
}
break;
default:
F_3 ( L_20 , V_2 ) ;
break;
}
F_11 ( ( V_39 , L_21 ) ) ;
V_10 ;
}
