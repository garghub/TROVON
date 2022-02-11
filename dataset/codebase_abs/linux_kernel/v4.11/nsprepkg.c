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
if ( V_7 -> V_18 . type == V_19 ) {
return ( V_10 ) ;
}
F_5 ( ( V_20 , V_2 -> V_17 ,
V_2 -> V_21 ,
L_2 ) ) ;
return ( V_22 ) ;
}
switch ( V_7 -> V_18 . type ) {
case V_23 :
V_9 = F_6 ( V_2 , V_8 , V_12 ) ;
break;
case V_24 :
V_11 =
V_7 -> V_18 . V_25 + V_7 -> V_18 . V_26 ;
if ( V_12 < V_11 ) {
goto V_27;
} else if ( V_12 > V_11 ) {
F_3 ( ( V_28 ,
L_3
L_4 ,
V_2 -> V_17 , V_12 ,
V_11 ) ) ;
}
V_9 = F_7 ( V_2 , V_8 ,
V_7 -> V_18 .
V_29 ,
V_7 -> V_18 .
V_25 ,
V_7 -> V_18 .
V_30 ,
V_7 -> V_18 .
V_26 , 0 ) ;
break;
case V_19 :
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_9 = F_8 ( V_2 , V_8 ,
V_7 -> V_18 .
V_29 , V_13 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_8 ++ ;
}
break;
case V_31 :
V_11 = V_7 -> V_32 . V_12 ;
if ( V_12 < V_11 ) {
goto V_27;
}
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_13 < V_7 -> V_32 . V_12 ) {
V_9 =
F_8 ( V_2 , V_8 ,
V_7 ->
V_32 .
V_33 [ V_13 ] ,
V_13 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
} else {
V_9 =
F_8 ( V_2 , V_8 ,
V_7 ->
V_32 .
V_34 ,
V_13 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
}
V_8 ++ ;
}
break;
case V_35 :
V_9 =
F_8 ( V_2 , V_8 ,
V_36 , 0 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_8 ++ ;
V_12 -- ;
V_9 =
F_10 ( V_2 , V_7 , V_8 , V_12 ) ;
break;
case V_37 :
V_9 =
F_8 ( V_2 , V_8 ,
V_36 , 0 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_11 = ( T_2 ) ( * V_8 ) -> integer . V_38 ;
if ( V_11 >= V_12 ) {
goto V_27;
}
V_12 = V_11 ;
V_8 ++ ;
V_9 =
F_10 ( V_2 , V_7 , V_8 , V_12 ) ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
if ( * V_8
&& ( ( * V_8 ) -> V_44 . type != V_45 ) ) {
V_9 =
F_11 ( V_2 , V_5 ,
V_4 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_5 = * V_4 ;
V_8 = V_5 -> V_7 . V_8 ;
V_12 = 1 ;
}
V_9 =
F_10 ( V_2 , V_7 , V_8 , V_12 ) ;
break;
case V_46 :
break;
case V_47 :
if ( V_12 & 1 ) {
V_11 = V_12 + 1 ;
goto V_27;
}
while ( V_12 > 0 ) {
V_9 = F_8 ( V_2 , V_8 ,
V_7 -> V_18 .
V_29 , 0 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
if ( ( * V_8 ) -> V_48 . V_49 != 16 ) {
F_5 ( ( V_20 ,
V_2 -> V_17 ,
V_2 -> V_21 ,
L_5 ) ) ;
return ( V_22 ) ;
}
V_9 = F_8 ( V_2 , V_8 + 1 ,
V_7 -> V_18 .
V_30 , 0 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_8 += 2 ;
V_12 -= 2 ;
}
break;
default:
F_5 ( ( V_20 , V_2 -> V_17 ,
V_2 -> V_21 ,
L_6 ,
V_7 -> V_18 . type ) ) ;
return ( V_50 ) ;
}
return ( V_9 ) ;
V_27:
F_5 ( ( V_20 , V_2 -> V_17 , V_2 -> V_21 ,
L_7 ,
V_12 , V_11 ) ) ;
return ( V_22 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 ,
const union V_6 * V_7 ,
union V_3 * * V_8 , T_2 V_12 )
{
union V_3 * V_51 ;
union V_3 * * V_52 ;
T_1 V_9 ;
T_2 V_11 ;
T_2 V_13 ;
T_2 V_53 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_51 = * V_8 ;
V_52 = V_51 -> V_7 . V_8 ;
V_2 -> V_54 = V_51 ;
V_9 = F_8 ( V_2 , & V_51 ,
V_55 , V_13 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_2 -> V_54 = V_51 ;
switch ( V_7 -> V_18 . type ) {
case V_39 :
case V_37 :
case V_35 :
V_11 =
V_7 -> V_18 . V_25 + V_7 -> V_18 . V_26 ;
if ( V_51 -> V_7 . V_12 < V_11 ) {
goto V_27;
}
V_9 =
F_7 ( V_2 , V_52 ,
V_7 -> V_18 .
V_29 ,
V_7 -> V_18 .
V_25 ,
V_7 -> V_18 .
V_30 ,
V_7 -> V_18 .
V_26 , 0 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_43 :
V_11 =
V_7 -> V_18 . V_25 + V_7 -> V_18 . V_26 ;
if ( V_51 -> V_7 . V_12 < V_11 ) {
goto V_27;
}
V_9 =
F_7 ( V_2 , V_52 ,
V_7 -> V_18 .
V_29 ,
V_7 -> V_18 .
V_25 ,
V_7 -> V_18 .
V_30 ,
V_51 -> V_7 .
V_12 -
V_7 -> V_18 .
V_25 , 0 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_46 :
break;
case V_40 :
V_11 = V_7 -> V_56 . V_12 ;
if ( V_51 -> V_7 . V_12 < V_11 ) {
goto V_27;
}
for ( V_53 = 0 ; V_53 < V_11 ; V_53 ++ ) {
V_9 =
F_8 ( V_2 ,
& V_52 [ V_53 ] ,
V_7 ->
V_56 .
V_33 [ V_53 ] ,
V_53 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
}
break;
case V_41 :
V_11 = V_7 -> V_18 . V_25 ;
if ( V_51 -> V_7 . V_12 < V_11 ) {
goto V_27;
}
V_9 =
F_7 ( V_2 , V_52 ,
V_7 -> V_18 .
V_29 ,
V_51 -> V_7 .
V_12 , 0 , 0 , 0 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_42 :
V_9 = F_8 ( V_2 , V_52 ,
V_36 ,
0 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_11 = ( T_2 ) ( * V_52 ) -> integer . V_38 ;
if ( V_51 -> V_7 . V_12 < V_11 ) {
goto V_27;
}
if ( V_51 -> V_7 . V_12 <
V_7 -> V_18 . V_25 ) {
V_11 = V_7 -> V_18 . V_25 ;
goto V_27;
}
if ( V_11 == 0 ) {
V_11 = V_51 -> V_7 . V_12 ;
( * V_52 ) -> integer . V_38 = V_11 ;
}
V_9 =
F_7 ( V_2 ,
( V_52 + 1 ) ,
V_7 -> V_18 .
V_29 ,
( V_11 - 1 ) ,
0 , 0 , 1 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
default:
return ( V_50 ) ;
}
V_8 ++ ;
}
return ( V_10 ) ;
V_27:
F_5 ( ( V_20 , V_2 -> V_17 , V_2 -> V_21 ,
L_8 ,
V_13 , V_51 -> V_7 . V_12 , V_11 ) ) ;
return ( V_22 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 ,
union V_3 * * V_8 , T_2 V_12 )
{
T_2 V_11 ;
T_2 V_57 ;
T_1 V_9 = V_10 ;
F_2 ( V_58 ) ;
if ( ( * V_8 ) -> V_44 . type != V_59 ) {
F_5 ( ( V_20 , V_2 -> V_17 ,
V_2 -> V_21 ,
L_9 ) ) ;
F_12 ( V_60 ) ;
}
V_57 = ( T_2 ) ( * V_8 ) -> integer . V_38 ;
V_11 = 21 ;
if ( V_57 == 0 ) {
V_11 = 20 ;
}
if ( V_12 < V_11 ) {
F_5 ( ( V_20 , V_2 -> V_17 ,
V_2 -> V_21 ,
L_7 ,
V_12 , V_11 ) ) ;
F_12 ( V_22 ) ;
} else if ( V_12 > V_11 ) {
F_3 ( ( V_28 ,
L_3
L_4 ,
V_2 -> V_17 , V_12 , V_11 ) ) ;
}
V_9 = F_7 ( V_2 , V_8 ,
V_36 , 16 ,
V_61 , 4 , 0 ) ;
if ( F_9 ( V_9 ) ) {
F_12 ( V_9 ) ;
}
if ( V_57 > 0 ) {
V_9 = F_7 ( V_2 , V_8 + 20 ,
V_36 , 1 ,
0 , 0 , 20 ) ;
}
F_12 ( V_9 ) ;
}
static T_1
F_7 ( struct V_1 * V_2 ,
union V_3 * * V_8 ,
T_3 V_62 ,
T_2 V_25 ,
T_3 V_63 , T_2 V_26 , T_2 V_64 )
{
union V_3 * * V_65 = V_8 ;
T_1 V_9 ;
T_2 V_13 ;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
V_9 = F_8 ( V_2 , V_65 ,
V_62 , V_13 + V_64 ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_65 ++ ;
}
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ ) {
V_9 = F_8 ( V_2 , V_65 ,
V_63 ,
( V_13 + V_25 + V_64 ) ) ;
if ( F_9 ( V_9 ) ) {
return ( V_9 ) ;
}
V_65 ++ ;
}
return ( V_10 ) ;
}
