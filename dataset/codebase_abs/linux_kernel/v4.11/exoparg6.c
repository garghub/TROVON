static T_1
F_1 ( T_2 V_1 ,
union V_2 * V_3 ,
union V_2 * V_4 )
{
T_1 V_5 = TRUE ;
T_3 V_6 ;
switch ( V_1 ) {
case V_7 :
break;
case V_8 :
V_6 =
F_2 ( V_9 , V_4 , V_3 ,
& V_5 ) ;
if ( F_3 ( V_6 ) ) {
return ( FALSE ) ;
}
break;
case V_10 :
V_6 =
F_2 ( V_11 , V_4 , V_3 ,
& V_5 ) ;
if ( F_3 ( V_6 ) ) {
return ( FALSE ) ;
}
V_5 = ( T_1 ) ! V_5 ;
break;
case V_12 :
V_6 =
F_2 ( V_13 , V_4 ,
V_3 , & V_5 ) ;
if ( F_3 ( V_6 ) ) {
return ( FALSE ) ;
}
break;
case V_14 :
V_6 =
F_2 ( V_13 , V_4 ,
V_3 , & V_5 ) ;
if ( F_3 ( V_6 ) ) {
return ( FALSE ) ;
}
V_5 = ( T_1 ) ! V_5 ;
break;
case V_15 :
V_6 =
F_2 ( V_11 , V_4 , V_3 ,
& V_5 ) ;
if ( F_3 ( V_6 ) ) {
return ( FALSE ) ;
}
break;
default:
return ( FALSE ) ;
}
return ( V_5 ) ;
}
T_3 F_4 ( struct V_16 * V_17 )
{
union V_2 * * V_18 = & V_17 -> V_19 [ 0 ] ;
union V_2 * V_20 = NULL ;
T_3 V_6 = V_21 ;
T_4 V_22 ;
union V_2 * V_23 ;
F_5 ( V_24 ,
F_6 ( V_17 -> V_25 ) ) ;
switch ( V_17 -> V_25 ) {
case V_26 :
if ( ( V_18 [ 1 ] -> integer . V_27 > V_28 ) ||
( V_18 [ 3 ] -> integer . V_27 > V_28 ) ) {
F_7 ( ( V_29 , L_1 ) ) ;
V_6 = V_30 ;
goto V_31;
}
V_22 = V_18 [ 5 ] -> integer . V_27 ;
if ( V_22 >= V_18 [ 0 ] -> V_32 . V_33 ) {
F_7 ( ( V_29 ,
L_2 ,
F_8 ( V_22 ) ,
V_18 [ 0 ] -> V_32 . V_33 ) ) ;
V_6 = V_34 ;
goto V_31;
}
V_20 = F_9 ( V_35 ) ;
if ( ! V_20 ) {
V_6 = V_36 ;
goto V_31;
}
for (; V_22 < V_18 [ 0 ] -> V_32 . V_33 ; V_22 ++ ) {
V_23 = V_18 [ 0 ] -> V_32 . V_37 [ V_22 ] ;
if ( ! V_23 ) {
continue;
}
if ( ! F_1 ( ( T_2 ) V_18 [ 1 ] -> integer . V_27 ,
V_23 , V_18 [ 2 ] ) ) {
continue;
}
if ( ! F_1 ( ( T_2 ) V_18 [ 3 ] -> integer . V_27 ,
V_23 , V_18 [ 4 ] ) ) {
continue;
}
V_20 -> integer . V_27 = V_22 ;
break;
}
break;
case V_38 :
V_6 = F_10 ( V_17 , & V_20 ) ;
break;
default:
F_7 ( ( V_29 , L_3 ,
V_17 -> V_25 ) ) ;
V_6 = V_39 ;
goto V_31;
}
V_31:
if ( F_3 ( V_6 ) ) {
F_11 ( V_20 ) ;
}
else {
V_17 -> V_40 = V_20 ;
}
F_12 ( V_6 ) ;
}
