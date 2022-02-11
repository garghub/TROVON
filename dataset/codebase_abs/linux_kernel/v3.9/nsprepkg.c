T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * * V_4 )
{
union V_3 * V_5 = * V_4 ;
const union V_6 * V_7 ;
union V_3 * * V_8 ;
T_1 V_9 = V_10 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
F_2 ( V_14 ) ;
V_7 = V_2 -> V_15 + 1 ;
F_3 ( ( V_16 ,
L_1 ,
V_2 -> V_17 , V_7 -> V_18 . type ,
V_5 -> V_7 . V_12 ) ) ;
F_4 ( V_2 , V_7 -> V_18 . type ,
V_5 ) ;
V_8 = V_5 -> V_7 . V_8 ;
V_12 = V_5 -> V_7 . V_12 ;
if ( ! V_12 ) {
F_5 ( ( V_19 , V_2 -> V_17 , V_2 -> V_20 ,
L_2 ) ) ;
return ( V_21 ) ;
}
switch ( V_7 -> V_18 . type ) {
case V_22 :
V_11 =
V_7 -> V_18 . V_23 + V_7 -> V_18 . V_24 ;
if ( V_12 < V_11 ) {
goto V_25;
} else if ( V_12 > V_11 ) {
F_3 ( ( V_26 ,
L_3
L_4 ,
V_2 -> V_17 , V_12 ,
V_11 ) ) ;
}
V_9 = F_6 ( V_2 , V_8 ,
V_7 -> V_18 .
V_27 ,
V_7 -> V_18 .
V_23 ,
V_7 -> V_18 .
V_28 ,
V_7 -> V_18 .
V_24 , 0 ) ;
break;
case V_29 :
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_9 = F_7 ( V_2 , V_8 ,
V_7 -> V_18 .
V_27 , V_13 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_8 ++ ;
}
break;
case V_30 :
V_11 = V_7 -> V_31 . V_12 ;
if ( V_12 < V_11 ) {
goto V_25;
}
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_13 < V_7 -> V_31 . V_12 ) {
V_9 =
F_7 ( V_2 , V_8 ,
V_7 ->
V_31 .
V_32 [ V_13 ] ,
V_13 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
} else {
V_9 =
F_7 ( V_2 , V_8 ,
V_7 ->
V_31 .
V_33 ,
V_13 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
}
V_8 ++ ;
}
break;
case V_34 :
V_9 = F_7 ( V_2 , V_8 ,
V_35 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_8 ++ ;
V_12 -- ;
V_9 =
F_9 ( V_2 , V_7 , V_8 , V_12 ) ;
break;
case V_36 :
V_9 = F_7 ( V_2 , V_8 ,
V_35 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_11 = ( T_2 ) ( * V_8 ) -> integer . V_37 ;
if ( V_11 >= V_12 ) {
goto V_25;
}
V_12 = V_11 ;
V_8 ++ ;
V_9 =
F_9 ( V_2 , V_7 , V_8 , V_12 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
if ( * V_8
&& ( ( * V_8 ) -> V_43 . type != V_44 ) ) {
V_9 =
F_10 ( V_2 , V_5 ,
V_4 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_5 = * V_4 ;
V_8 = V_5 -> V_7 . V_8 ;
V_12 = 1 ;
}
V_9 =
F_9 ( V_2 , V_7 , V_8 , V_12 ) ;
break;
default:
F_5 ( ( V_19 , V_2 -> V_17 , V_2 -> V_20 ,
L_5 ,
V_7 -> V_18 . type ) ) ;
return ( V_45 ) ;
}
return ( V_9 ) ;
V_25:
F_5 ( ( V_19 , V_2 -> V_17 , V_2 -> V_20 ,
L_6 ,
V_12 , V_11 ) ) ;
return ( V_21 ) ;
}
static T_1
F_9 ( struct V_1 * V_2 ,
const union V_6 * V_7 ,
union V_3 * * V_8 , T_2 V_12 )
{
union V_3 * V_46 ;
union V_3 * * V_47 ;
T_1 V_9 ;
T_2 V_11 ;
T_2 V_13 ;
T_2 V_48 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_46 = * V_8 ;
V_47 = V_46 -> V_7 . V_8 ;
V_2 -> V_49 = V_46 ;
V_9 = F_7 ( V_2 , & V_46 ,
V_50 , V_13 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_2 -> V_49 = V_46 ;
switch ( V_7 -> V_18 . type ) {
case V_38 :
case V_36 :
case V_34 :
V_11 =
V_7 -> V_18 . V_23 + V_7 -> V_18 . V_24 ;
if ( V_46 -> V_7 . V_12 < V_11 ) {
goto V_25;
}
V_9 =
F_6 ( V_2 , V_47 ,
V_7 -> V_18 .
V_27 ,
V_7 -> V_18 .
V_23 ,
V_7 -> V_18 .
V_28 ,
V_7 -> V_18 .
V_24 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_42 :
V_11 =
V_7 -> V_18 . V_23 + V_7 -> V_18 . V_24 ;
if ( V_46 -> V_7 . V_12 < V_11 ) {
goto V_25;
}
V_9 =
F_6 ( V_2 , V_47 ,
V_7 -> V_18 .
V_27 ,
V_7 -> V_18 .
V_23 ,
V_7 -> V_18 .
V_28 ,
V_46 -> V_7 .
V_12 -
V_7 -> V_18 .
V_23 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_39 :
V_11 = V_7 -> V_51 . V_12 ;
if ( V_46 -> V_7 . V_12 < V_11 ) {
goto V_25;
}
for ( V_48 = 0 ; V_48 < V_11 ; V_48 ++ ) {
V_9 =
F_7 ( V_2 ,
& V_47 [ V_48 ] ,
V_7 ->
V_51 .
V_32 [ V_48 ] ,
V_48 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
}
break;
case V_40 :
V_11 = V_7 -> V_18 . V_23 ;
if ( V_46 -> V_7 . V_12 < V_11 ) {
goto V_25;
}
V_9 =
F_6 ( V_2 , V_47 ,
V_7 -> V_18 .
V_27 ,
V_46 -> V_7 .
V_12 , 0 , 0 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_41 :
V_9 = F_7 ( V_2 , V_47 ,
V_35 ,
0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_11 = ( T_2 ) ( * V_47 ) -> integer . V_37 ;
if ( V_46 -> V_7 . V_12 < V_11 ) {
goto V_25;
}
if ( V_46 -> V_7 . V_12 <
V_7 -> V_18 . V_23 ) {
V_11 = V_7 -> V_18 . V_23 ;
goto V_25;
}
if ( V_11 == 0 ) {
V_11 = V_46 -> V_7 . V_12 ;
( * V_47 ) -> integer . V_37 = V_11 ;
}
V_9 =
F_6 ( V_2 ,
( V_47 + 1 ) ,
V_7 -> V_18 .
V_27 ,
( V_11 - 1 ) ,
0 , 0 , 1 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
default:
return ( V_45 ) ;
}
V_8 ++ ;
}
return ( V_10 ) ;
V_25:
F_5 ( ( V_19 , V_2 -> V_17 , V_2 -> V_20 ,
L_7 ,
V_13 , V_46 -> V_7 . V_12 , V_11 ) ) ;
return ( V_21 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 ,
union V_3 * * V_8 ,
T_3 V_52 ,
T_2 V_23 ,
T_3 V_53 , T_2 V_24 , T_2 V_54 )
{
union V_3 * * V_55 = V_8 ;
T_1 V_9 ;
T_2 V_13 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_9 = F_7 ( V_2 , V_55 ,
V_52 , V_13 + V_54 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_55 ++ ;
}
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
V_9 = F_7 ( V_2 , V_55 ,
V_53 ,
( V_13 + V_23 + V_54 ) ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_55 ++ ;
}
return ( V_10 ) ;
}
