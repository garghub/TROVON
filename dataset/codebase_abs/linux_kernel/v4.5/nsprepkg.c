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
V_11 =
V_7 -> V_18 . V_24 + V_7 -> V_18 . V_25 ;
if ( V_12 < V_11 ) {
goto V_26;
} else if ( V_12 > V_11 ) {
F_3 ( ( V_27 ,
L_3
L_4 ,
V_2 -> V_17 , V_12 ,
V_11 ) ) ;
}
V_9 = F_6 ( V_2 , V_8 ,
V_7 -> V_18 .
V_28 ,
V_7 -> V_18 .
V_24 ,
V_7 -> V_18 .
V_29 ,
V_7 -> V_18 .
V_25 , 0 ) ;
break;
case V_19 :
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_9 = F_7 ( V_2 , V_8 ,
V_7 -> V_18 .
V_28 , V_13 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_8 ++ ;
}
break;
case V_30 :
V_11 = V_7 -> V_31 . V_12 ;
if ( V_12 < V_11 ) {
goto V_26;
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
V_9 =
F_7 ( V_2 , V_8 ,
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
V_9 =
F_7 ( V_2 , V_8 ,
V_35 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_11 = ( T_2 ) ( * V_8 ) -> integer . V_37 ;
if ( V_11 >= V_12 ) {
goto V_26;
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
case V_45 :
break;
case V_46 :
if ( V_12 & 1 ) {
V_11 = V_12 + 1 ;
goto V_26;
}
while ( V_12 > 0 ) {
V_9 = F_7 ( V_2 , V_8 ,
V_7 -> V_18 .
V_28 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
if ( ( * V_8 ) -> V_47 . V_48 != 16 ) {
F_5 ( ( V_20 ,
V_2 -> V_17 ,
V_2 -> V_21 ,
L_5 ) ) ;
return ( V_22 ) ;
}
V_9 = F_7 ( V_2 , V_8 + 1 ,
V_7 -> V_18 .
V_29 , 0 ) ;
if ( F_8 ( V_9 ) ) {
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
return ( V_49 ) ;
}
return ( V_9 ) ;
V_26:
F_5 ( ( V_20 , V_2 -> V_17 , V_2 -> V_21 ,
L_7 ,
V_12 , V_11 ) ) ;
return ( V_22 ) ;
}
static T_1
F_9 ( struct V_1 * V_2 ,
const union V_6 * V_7 ,
union V_3 * * V_8 , T_2 V_12 )
{
union V_3 * V_50 ;
union V_3 * * V_51 ;
T_1 V_9 ;
T_2 V_11 ;
T_2 V_13 ;
T_2 V_52 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_50 = * V_8 ;
V_51 = V_50 -> V_7 . V_8 ;
V_2 -> V_53 = V_50 ;
V_9 = F_7 ( V_2 , & V_50 ,
V_54 , V_13 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_2 -> V_53 = V_50 ;
switch ( V_7 -> V_18 . type ) {
case V_38 :
case V_36 :
case V_34 :
V_11 =
V_7 -> V_18 . V_24 + V_7 -> V_18 . V_25 ;
if ( V_50 -> V_7 . V_12 < V_11 ) {
goto V_26;
}
V_9 =
F_6 ( V_2 , V_51 ,
V_7 -> V_18 .
V_28 ,
V_7 -> V_18 .
V_24 ,
V_7 -> V_18 .
V_29 ,
V_7 -> V_18 .
V_25 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_42 :
V_11 =
V_7 -> V_18 . V_24 + V_7 -> V_18 . V_25 ;
if ( V_50 -> V_7 . V_12 < V_11 ) {
goto V_26;
}
V_9 =
F_6 ( V_2 , V_51 ,
V_7 -> V_18 .
V_28 ,
V_7 -> V_18 .
V_24 ,
V_7 -> V_18 .
V_29 ,
V_50 -> V_7 .
V_12 -
V_7 -> V_18 .
V_24 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_45 :
break;
case V_39 :
V_11 = V_7 -> V_55 . V_12 ;
if ( V_50 -> V_7 . V_12 < V_11 ) {
goto V_26;
}
for ( V_52 = 0 ; V_52 < V_11 ; V_52 ++ ) {
V_9 =
F_7 ( V_2 ,
& V_51 [ V_52 ] ,
V_7 ->
V_55 .
V_32 [ V_52 ] ,
V_52 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
}
break;
case V_40 :
V_11 = V_7 -> V_18 . V_24 ;
if ( V_50 -> V_7 . V_12 < V_11 ) {
goto V_26;
}
V_9 =
F_6 ( V_2 , V_51 ,
V_7 -> V_18 .
V_28 ,
V_50 -> V_7 .
V_12 , 0 , 0 , 0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_41 :
V_9 = F_7 ( V_2 , V_51 ,
V_35 ,
0 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_11 = ( T_2 ) ( * V_51 ) -> integer . V_37 ;
if ( V_50 -> V_7 . V_12 < V_11 ) {
goto V_26;
}
if ( V_50 -> V_7 . V_12 <
V_7 -> V_18 . V_24 ) {
V_11 = V_7 -> V_18 . V_24 ;
goto V_26;
}
if ( V_11 == 0 ) {
V_11 = V_50 -> V_7 . V_12 ;
( * V_51 ) -> integer . V_37 = V_11 ;
}
V_9 =
F_6 ( V_2 ,
( V_51 + 1 ) ,
V_7 -> V_18 .
V_28 ,
( V_11 - 1 ) ,
0 , 0 , 1 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
default:
return ( V_49 ) ;
}
V_8 ++ ;
}
return ( V_10 ) ;
V_26:
F_5 ( ( V_20 , V_2 -> V_17 , V_2 -> V_21 ,
L_8 ,
V_13 , V_50 -> V_7 . V_12 , V_11 ) ) ;
return ( V_22 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 ,
union V_3 * * V_8 ,
T_3 V_56 ,
T_2 V_24 ,
T_3 V_57 , T_2 V_25 , T_2 V_58 )
{
union V_3 * * V_59 = V_8 ;
T_1 V_9 ;
T_2 V_13 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
V_9 = F_7 ( V_2 , V_59 ,
V_56 , V_13 + V_58 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_59 ++ ;
}
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
V_9 = F_7 ( V_2 , V_59 ,
V_57 ,
( V_13 + V_24 + V_58 ) ) ;
if ( F_8 ( V_9 ) ) {
return ( V_9 ) ;
}
V_59 ++ ;
}
return ( V_10 ) ;
}
