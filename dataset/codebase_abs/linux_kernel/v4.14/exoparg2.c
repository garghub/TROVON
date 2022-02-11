T_1 F_1 ( struct V_1 * V_2 )
{
union V_3 * * V_4 = & V_2 -> V_5 [ 0 ] ;
struct V_6 * V_7 ;
T_2 V_8 ;
T_1 V_9 = V_10 ;
F_2 ( V_11 ,
F_3 ( V_2 -> V_12 ) ) ;
switch ( V_2 -> V_12 ) {
case V_13 :
V_7 = (struct V_6 * ) V_4 [ 0 ] ;
V_8 = ( T_2 ) V_4 [ 1 ] -> integer . V_8 ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( ( V_14 ,
L_1 ,
F_6 ( V_7 -> type ) ) ) ;
V_9 = V_15 ;
break;
}
V_9 = F_7 ( V_7 , V_8 ) ;
break;
default:
F_5 ( ( V_14 , L_2 ,
V_2 -> V_12 ) ) ;
V_9 = V_16 ;
}
F_8 ( V_9 ) ;
}
T_1 F_9 ( struct V_1 * V_2 )
{
union V_3 * * V_4 = & V_2 -> V_5 [ 0 ] ;
union V_3 * V_17 = NULL ;
union V_3 * V_18 = NULL ;
T_1 V_9 ;
F_2 ( V_19 ,
F_3 ( V_2 -> V_12 ) ) ;
switch ( V_2 -> V_12 ) {
case V_20 :
V_17 =
F_10 ( V_21 ) ;
if ( ! V_17 ) {
V_9 = V_22 ;
goto V_23;
}
V_18 =
F_10 ( V_21 ) ;
if ( ! V_18 ) {
V_9 = V_22 ;
goto V_23;
}
V_9 = F_11 ( V_4 [ 0 ] -> integer . V_8 ,
V_4 [ 1 ] -> integer . V_8 ,
& V_17 -> integer . V_8 ,
& V_18 -> integer . V_8 ) ;
if ( F_12 ( V_9 ) ) {
goto V_23;
}
break;
default:
F_5 ( ( V_14 , L_2 ,
V_2 -> V_12 ) ) ;
V_9 = V_16 ;
goto V_23;
}
V_9 = F_13 ( V_18 , V_4 [ 2 ] , V_2 ) ;
if ( F_12 ( V_9 ) ) {
goto V_23;
}
V_9 = F_13 ( V_17 , V_4 [ 3 ] , V_2 ) ;
if ( F_12 ( V_9 ) ) {
goto V_23;
}
V_23:
F_14 ( V_18 ) ;
if ( F_12 ( V_9 ) ) {
F_14 ( V_17 ) ;
}
else {
V_2 -> V_24 = V_17 ;
}
F_8 ( V_9 ) ;
}
T_1 F_15 ( struct V_1 * V_2 )
{
union V_3 * * V_4 = & V_2 -> V_5 [ 0 ] ;
union V_3 * V_25 = NULL ;
T_3 V_26 ;
T_1 V_9 = V_10 ;
T_4 V_27 = 0 ;
F_2 ( V_28 ,
F_3 ( V_2 -> V_12 ) ) ;
if ( V_2 -> V_29 -> V_30 & V_31 ) {
V_25 = F_10 ( V_21 ) ;
if ( ! V_25 ) {
V_9 = V_22 ;
goto V_23;
}
V_25 -> integer . V_8 =
F_16 ( V_2 -> V_12 ,
V_4 [ 0 ] -> integer . V_8 ,
V_4 [ 1 ] -> integer . V_8 ) ;
goto V_32;
}
switch ( V_2 -> V_12 ) {
case V_33 :
V_25 = F_10 ( V_21 ) ;
if ( ! V_25 ) {
V_9 = V_22 ;
goto V_23;
}
V_9 = F_11 ( V_4 [ 0 ] -> integer . V_8 ,
V_4 [ 1 ] -> integer . V_8 ,
NULL , & V_25 -> integer . V_8 ) ;
break;
case V_34 :
V_9 =
F_17 ( V_4 [ 0 ] , V_4 [ 1 ] , & V_25 ,
V_2 ) ;
break;
case V_35 :
while ( ( V_27 < V_4 [ 0 ] -> V_36 . V_27 ) &&
( V_27 < V_4 [ 1 ] -> integer . V_8 ) &&
( V_4 [ 0 ] -> V_36 . V_37 [ V_27 ] ) ) {
V_27 ++ ;
}
V_25 = F_18 ( V_27 ) ;
if ( ! V_25 ) {
V_9 = V_22 ;
goto V_23;
}
memcpy ( V_25 -> string . V_37 ,
V_4 [ 0 ] -> V_36 . V_37 , V_27 ) ;
break;
case V_38 :
V_9 =
F_19 ( V_4 [ 0 ] , V_4 [ 1 ] ,
& V_25 , V_2 ) ;
break;
case V_39 :
V_25 =
F_10 ( V_40 ) ;
if ( ! V_25 ) {
V_9 = V_22 ;
goto V_23;
}
V_26 = V_4 [ 1 ] -> integer . V_8 ;
V_25 -> V_41 . V_8 = ( T_2 ) V_26 ;
V_25 -> V_41 . V_42 = V_43 ;
switch ( ( V_4 [ 0 ] ) -> V_44 . type ) {
case V_45 :
if ( V_26 >= V_4 [ 0 ] -> string . V_27 ) {
V_27 = V_4 [ 0 ] -> string . V_27 ;
V_9 = V_46 ;
}
V_25 -> V_41 . V_47 =
V_48 ;
V_25 -> V_41 . V_49 =
& ( V_4 [ 0 ] -> V_36 . V_37 [ V_26 ] ) ;
break;
case V_50 :
if ( V_26 >= V_4 [ 0 ] -> V_36 . V_27 ) {
V_27 = V_4 [ 0 ] -> V_36 . V_27 ;
V_9 = V_51 ;
}
V_25 -> V_41 . V_47 =
V_48 ;
V_25 -> V_41 . V_49 =
& ( V_4 [ 0 ] -> V_36 . V_37 [ V_26 ] ) ;
break;
case V_52 :
if ( V_26 >= V_4 [ 0 ] -> V_53 . V_54 ) {
V_27 = V_4 [ 0 ] -> V_53 . V_54 ;
V_9 = V_55 ;
}
V_25 -> V_41 . V_47 = V_52 ;
V_25 -> V_41 . V_56 =
& V_4 [ 0 ] -> V_53 . V_57 [ V_26 ] ;
break;
default:
F_5 ( ( V_14 ,
L_3 ,
( V_4 [ 0 ] ) -> V_44 . type ) ) ;
V_9 = V_58 ;
goto V_23;
}
if ( F_12 ( V_9 ) ) {
F_20 ( ( V_14 , V_9 ,
L_4 ,
F_21 ( V_26 ) ,
( T_2 ) V_27 ) ) ;
goto V_23;
}
V_25 -> V_41 . V_59 = V_4 [ 0 ] ;
F_22 ( V_4 [ 0 ] ) ;
V_9 = F_13 ( V_25 , V_4 [ 2 ] , V_2 ) ;
V_2 -> V_24 = V_25 ;
goto V_23;
default:
F_5 ( ( V_14 , L_2 ,
V_2 -> V_12 ) ) ;
V_9 = V_16 ;
break;
}
V_32:
if ( F_23 ( V_9 ) ) {
V_9 = F_13 ( V_25 , V_4 [ 2 ] , V_2 ) ;
if ( F_12 ( V_9 ) ) {
goto V_23;
}
if ( ! V_2 -> V_24 ) {
V_2 -> V_24 = V_25 ;
}
}
V_23:
if ( F_12 ( V_9 ) ) {
F_14 ( V_25 ) ;
V_2 -> V_24 = NULL ;
}
F_8 ( V_9 ) ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
union V_3 * * V_4 = & V_2 -> V_5 [ 0 ] ;
union V_3 * V_25 = NULL ;
T_1 V_9 = V_10 ;
T_5 V_60 = FALSE ;
F_2 ( V_61 ,
F_3 ( V_2 -> V_12 ) ) ;
V_25 = F_10 ( V_21 ) ;
if ( ! V_25 ) {
V_9 = V_22 ;
goto V_23;
}
if ( V_2 -> V_29 -> V_30 & V_62 ) {
V_9 = F_25 ( V_2 -> V_12 ,
V_4 [ 0 ] -> integer .
V_8 ,
V_4 [ 1 ] -> integer .
V_8 , & V_60 ) ;
goto V_63;
} else if ( V_2 -> V_29 -> V_30 & V_64 ) {
V_9 = F_26 ( V_2 -> V_12 , V_4 [ 0 ] ,
V_4 [ 1 ] , & V_60 ) ;
goto V_63;
}
switch ( V_2 -> V_12 ) {
case V_65 :
V_9 =
F_27 ( V_4 [ 1 ] , V_4 [ 0 ] , V_2 ) ;
if ( V_9 == V_66 ) {
V_60 = TRUE ;
V_9 = V_10 ;
}
break;
case V_67 :
V_9 = F_28 ( V_4 [ 1 ] , V_4 [ 0 ] ) ;
if ( V_9 == V_66 ) {
V_60 = TRUE ;
V_9 = V_10 ;
}
break;
default:
F_5 ( ( V_14 , L_2 ,
V_2 -> V_12 ) ) ;
V_9 = V_16 ;
goto V_23;
}
V_63:
if ( V_60 ) {
V_25 -> integer . V_8 = V_68 ;
}
V_23:
if ( F_12 ( V_9 ) ) {
F_14 ( V_25 ) ;
}
else {
V_2 -> V_24 = V_25 ;
}
F_8 ( V_9 ) ;
}
