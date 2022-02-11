T_1
F_1 ( union V_1 * V_2 ,
union V_1 * * V_3 ,
struct V_4 * V_5 )
{
union V_1 * V_6 ;
union V_1 * V_7 ;
F_2 ( V_8 , V_2 ) ;
* V_3 = NULL ;
switch ( F_3 ( V_2 ) ) {
case V_9 :
if ( V_2 -> V_10 . type != V_11 ) {
F_4 ( V_12 ) ;
}
switch ( V_2 -> V_13 . V_14 ) {
case V_15 :
case V_16 :
case V_17 :
V_7 = V_2 -> V_13 . V_18 ;
break;
default:
F_5 ( ( V_19 , L_1 ,
V_2 -> V_13 . V_14 ) ) ;
F_4 ( V_12 ) ;
}
break;
case V_20 :
V_7 = V_2 ;
break;
default:
F_5 ( ( V_19 , L_2 ,
F_3 ( V_2 ) ) ) ;
F_4 ( V_21 ) ;
}
V_6 =
F_6 ( V_11 ) ;
if ( ! V_6 ) {
F_4 ( V_22 ) ;
}
V_6 -> V_13 . V_14 = V_23 ;
V_6 -> V_13 . V_18 = V_7 ;
* V_3 = V_6 ;
F_7 ( ( V_24 ,
L_3 ,
V_2 , F_8 ( V_2 ) ,
* V_3 ) ) ;
F_4 ( V_25 ) ;
}
T_2 F_9 ( T_3 V_26 , T_2 V_27 , T_2 V_28 )
{
F_10 () ;
switch ( V_26 ) {
case V_29 :
return ( V_27 + V_28 ) ;
case V_30 :
return ( V_27 & V_28 ) ;
case V_31 :
return ( ~ ( V_27 & V_28 ) ) ;
case V_32 :
return ( V_27 | V_28 ) ;
case V_33 :
return ( ~ ( V_27 | V_28 ) ) ;
case V_34 :
return ( V_27 ^ V_28 ) ;
case V_35 :
return ( V_27 * V_28 ) ;
case V_36 :
if ( V_28 >= V_37 ) {
return ( 0 ) ;
}
return ( V_27 << V_28 ) ;
case V_38 :
if ( V_28 >= V_37 ) {
return ( 0 ) ;
}
return ( V_27 >> V_28 ) ;
case V_39 :
return ( V_27 - V_28 ) ;
default:
return ( 0 ) ;
}
}
T_1
F_11 ( T_3 V_26 ,
T_2 V_27 , T_2 V_28 , T_4 * V_40 )
{
T_1 V_41 = V_25 ;
T_4 V_42 = FALSE ;
F_12 ( V_43 ) ;
switch ( V_26 ) {
case V_44 :
if ( V_27 && V_28 ) {
V_42 = TRUE ;
}
break;
case V_45 :
if ( V_27 || V_28 ) {
V_42 = TRUE ;
}
break;
default:
F_5 ( ( V_19 ,
L_4 , V_26 ) ) ;
V_41 = V_46 ;
break;
}
* V_40 = V_42 ;
F_4 ( V_41 ) ;
}
T_1
F_13 ( T_3 V_26 ,
union V_1 * V_47 ,
union V_1 * V_48 , T_4 * V_40 )
{
union V_1 * V_49 = V_48 ;
T_2 V_27 ;
T_2 V_28 ;
T_5 V_50 ;
T_5 V_51 ;
T_1 V_41 = V_25 ;
T_4 V_42 = FALSE ;
int V_52 ;
F_12 ( V_53 ) ;
switch ( V_47 -> V_10 . type ) {
case V_54 :
V_41 = F_14 ( V_48 , & V_49 ,
V_55 ) ;
break;
case V_56 :
V_41 =
F_15 ( V_48 , & V_49 ,
V_57 ) ;
break;
case V_58 :
V_41 = F_16 ( V_48 , & V_49 ) ;
break;
default:
F_5 ( ( V_19 ,
L_5 ,
V_47 -> V_10 . type ) ) ;
V_41 = V_46 ;
break;
}
if ( F_17 ( V_41 ) ) {
goto V_59;
}
if ( V_47 -> V_10 . type == V_54 ) {
V_27 = V_47 -> integer . V_60 ;
V_28 = V_49 -> integer . V_60 ;
switch ( V_26 ) {
case V_61 :
if ( V_27 == V_28 ) {
V_42 = TRUE ;
}
break;
case V_62 :
if ( V_27 > V_28 ) {
V_42 = TRUE ;
}
break;
case V_63 :
if ( V_27 < V_28 ) {
V_42 = TRUE ;
}
break;
default:
F_5 ( ( V_19 ,
L_6 , V_26 ) ) ;
V_41 = V_46 ;
break;
}
} else {
V_50 = V_47 -> V_64 . V_65 ;
V_51 = V_49 -> V_64 . V_65 ;
V_52 = memcmp ( V_47 -> V_64 . V_66 ,
V_49 -> V_64 . V_66 ,
( V_50 > V_51 ) ? V_51 : V_50 ) ;
switch ( V_26 ) {
case V_61 :
if ( ( V_50 == V_51 ) && ( V_52 == 0 ) ) {
V_42 = TRUE ;
}
break;
case V_62 :
if ( V_52 > 0 ) {
V_42 = TRUE ;
goto V_59;
}
if ( V_52 < 0 ) {
goto V_59;
}
if ( V_50 > V_51 ) {
V_42 = TRUE ;
}
break;
case V_63 :
if ( V_52 > 0 ) {
goto V_59;
}
if ( V_52 < 0 ) {
V_42 = TRUE ;
goto V_59;
}
if ( V_50 < V_51 ) {
V_42 = TRUE ;
}
break;
default:
F_5 ( ( V_19 ,
L_6 , V_26 ) ) ;
V_41 = V_46 ;
break;
}
}
V_59:
if ( V_49 != V_48 ) {
F_18 ( V_49 ) ;
}
* V_40 = V_42 ;
F_4 ( V_41 ) ;
}
