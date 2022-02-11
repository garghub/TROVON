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
if ( V_2 &&
( F_3 ( V_2 ) == V_14 ) &&
( V_2 -> V_15 . type == V_16 ) ) {
if ( ( V_2 -> string . V_17 == 0 ) ||
( ( V_2 -> string . V_17 == 1 ) &&
( * V_2 -> string . V_18 == '\n' ) ) ) {
F_4 ( L_1 ) ;
V_13 ;
}
}
if ( ! ( ( V_3 > 0 ) && V_4 == 0 ) ) {
if ( V_19 ) {
V_6 = ( ( T_1 ) F_5 () / 10 ) ;
V_6 &= 0x03FFFFFF ;
F_4 ( L_2 , V_6 ,
V_3 , L_3 ) ;
} else {
F_4 ( L_4 , V_3 , L_3 ) ;
}
}
if ( V_4 > 0 ) {
F_4 ( L_5 , V_4 - 1 ) ;
}
if ( ! V_2 ) {
F_4 ( L_6 ) ;
V_13 ;
}
if ( F_3 ( V_2 ) == V_14 ) {
if ( ( V_2 -> V_15 . type != V_20 ) &&
( V_2 -> V_15 . type != V_16 ) ) {
F_4 ( L_7 ,
F_6
( V_2 ) ) ;
}
if ( ! F_7 ( V_2 ) ) {
F_4 ( L_8 ,
V_2 ) ;
V_13 ;
}
} else if ( F_3 ( V_2 ) ==
V_21 ) {
F_4 ( L_9 ,
F_8 ( ( (struct
V_22 * )
V_2 ) -> type ) ,
V_2 ) ;
V_13 ;
} else {
V_13 ;
}
switch ( V_2 -> V_15 . type ) {
case V_20 :
if ( V_23 == 4 ) {
F_4 ( L_10 ,
( T_1 ) V_2 -> integer . V_8 ) ;
} else {
F_4 ( L_11 ,
F_9 ( V_2 -> integer .
V_8 ) ) ;
}
break;
case V_24 :
F_4 ( L_12 , ( T_1 ) V_2 -> V_25 . V_17 ) ;
F_10 ( V_2 -> V_25 . V_18 ,
( V_2 -> V_25 . V_17 < 256 ) ?
V_2 -> V_25 . V_17 : 256 ,
V_26 , 0 ) ;
break;
case V_16 :
F_4 ( L_13 , V_2 -> string . V_18 ) ;
break;
case V_27 :
F_4 ( L_14 ,
V_2 -> V_28 . V_29 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_28 . V_29 ; V_5 ++ ) {
F_1 ( V_2 -> V_28 .
V_30 [ V_5 ] , V_3 + 4 , V_5 + 1 ) ;
}
break;
case V_31 :
F_4 ( L_15 ,
F_11 ( V_2 ) ) ;
switch ( V_2 -> V_32 . V_33 ) {
case V_34 :
F_4 ( L_16 , V_2 -> V_32 . V_8 ) ;
break;
case V_35 :
F_4 ( L_17 ,
V_2 -> V_32 . V_8 ) ;
V_13 ;
default:
break;
}
F_4 ( L_3 ) ;
if ( V_2 -> V_32 . V_36 ) {
if ( F_3
( V_2 -> V_32 . V_36 ) !=
V_21 ) {
F_4
( L_18 ,
V_2 -> V_32 . V_36 ) ;
} else {
F_4 ( L_19 ,
V_2 -> V_32 . V_36 ,
( V_2 -> V_32 . V_36 ) ->
V_37 . V_38 ) ;
switch ( ( V_2 -> V_32 . V_36 ) -> type ) {
case V_39 :
F_4 ( L_20 ) ;
break;
case V_40 :
F_4 ( L_21 ) ;
break;
default:
F_1 ( ( V_2 ->
V_32 .
V_36 ) -> V_41 ,
V_3 + 4 , 0 ) ;
break;
}
}
} else if ( V_2 -> V_32 . V_41 ) {
if ( F_3
( V_2 -> V_32 . V_41 ) ==
V_21 ) {
F_1 ( F_12
( union
V_1 ,
V_2 -> V_32 .
V_41 ) , V_3 + 4 , 0 ) ;
} else {
V_7 = V_2 -> V_32 . V_41 ;
V_8 = V_2 -> V_32 . V_8 ;
switch ( V_7 -> V_15 . type ) {
case V_24 :
F_4 ( L_22 ,
V_8 ,
* V_2 -> V_32 .
V_42 ) ;
break;
case V_16 :
F_4
( L_23 ,
V_8 ,
* V_2 -> V_32 .
V_42 ,
* V_2 -> V_32 .
V_42 ) ;
break;
case V_27 :
F_4 ( L_24 , V_8 ) ;
if ( ! ( * V_2 -> V_32 . V_43 ) ) {
F_4
( L_25 ) ;
} else {
F_1
( * V_2 -> V_32 .
V_43 , V_3 + 4 , 0 ) ;
}
break;
default:
F_4
( L_26 ,
V_7 -> V_15 . type ) ;
break;
}
}
}
break;
default:
F_4 ( L_27 , V_2 ) ;
break;
}
F_13 ( ( V_44 , L_1 ) ) ;
V_13 ;
}
