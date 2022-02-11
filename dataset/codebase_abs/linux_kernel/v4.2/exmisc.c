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
F_4 ( V_20 ) ;
}
break;
case V_21 :
V_7 = V_2 ;
break;
default:
F_5 ( ( V_19 , L_2 ,
F_3 ( V_2 ) ) ) ;
F_4 ( V_22 ) ;
}
V_6 =
F_6 ( V_11 ) ;
if ( ! V_6 ) {
F_4 ( V_23 ) ;
}
V_6 -> V_13 . V_14 = V_24 ;
V_6 -> V_13 . V_18 = V_7 ;
* V_3 = V_6 ;
F_7 ( ( V_25 ,
L_3 ,
V_2 , F_8 ( V_2 ) ,
* V_3 ) ) ;
F_4 ( V_26 ) ;
}
T_1
F_9 ( union V_1 * V_27 ,
union V_1 * V_28 ,
union V_1 * * V_29 ,
struct V_4 * V_5 )
{
T_1 V_30 ;
union V_1 * V_3 ;
T_2 * V_31 ;
T_2 * V_32 ;
T_3 V_33 ;
T_3 V_34 ;
T_3 V_35 ;
F_10 ( V_36 ) ;
V_30 = F_11 ( V_27 , & V_32 ) ;
if ( F_12 ( V_30 ) ) {
F_4 ( V_30 ) ;
}
V_33 = F_13 ( V_32 , V_27 -> V_37 . V_38 ) ;
V_30 = F_11 ( V_28 , & V_32 ) ;
if ( F_12 ( V_30 ) ) {
F_4 ( V_30 ) ;
}
V_34 = F_13 ( V_32 , V_28 -> V_37 . V_38 ) ;
V_35 = V_33 + V_34 + sizeof( struct V_39 ) ;
V_3 = F_14 ( V_35 ) ;
if ( ! V_3 ) {
F_4 ( V_23 ) ;
}
V_31 = V_3 -> V_37 . V_38 ;
memcpy ( V_31 , V_27 -> V_37 . V_38 , V_33 ) ;
memcpy ( V_31 + V_33 , V_28 -> V_37 . V_38 , V_34 ) ;
V_31 [ V_35 - 1 ] = 0 ;
V_31 [ V_35 - 2 ] = V_40 | 1 ;
* V_29 = V_3 ;
F_4 ( V_26 ) ;
}
T_1
F_15 ( union V_1 * V_27 ,
union V_1 * V_28 ,
union V_1 * * V_29 ,
struct V_4 * V_5 )
{
union V_1 * V_41 = V_28 ;
union V_1 * V_3 ;
char * V_31 ;
T_1 V_30 ;
F_10 ( V_42 ) ;
switch ( V_27 -> V_10 . type ) {
case V_43 :
V_30 =
F_16 ( V_28 , & V_41 , 16 ) ;
break;
case V_44 :
V_30 = F_17 ( V_28 , & V_41 ,
V_45 ) ;
break;
case V_46 :
V_30 = F_18 ( V_28 , & V_41 ) ;
break;
default:
F_5 ( ( V_19 , L_4 ,
V_27 -> V_10 . type ) ) ;
V_30 = V_20 ;
}
if ( F_12 ( V_30 ) ) {
goto V_47;
}
switch ( V_27 -> V_10 . type ) {
case V_43 :
V_3 = F_14 ( ( T_3 )
F_19
( V_48 ) ) ;
if ( ! V_3 ) {
V_30 = V_23 ;
goto V_47;
}
V_31 = ( char * ) V_3 -> V_37 . V_38 ;
memcpy ( V_31 , & V_27 -> integer . V_49 ,
V_48 ) ;
memcpy ( V_31 + V_48 ,
& V_41 -> integer . V_49 ,
V_48 ) ;
break;
case V_44 :
V_3 = F_20 ( ( ( T_3 )
V_27 -> string .
V_50 +
V_41 ->
string . V_50 ) ) ;
if ( ! V_3 ) {
V_30 = V_23 ;
goto V_47;
}
V_31 = V_3 -> string . V_38 ;
strcpy ( V_31 , V_27 -> string . V_38 ) ;
strcpy ( V_31 + V_27 -> string . V_50 ,
V_41 -> string . V_38 ) ;
break;
case V_46 :
V_3 = F_14 ( ( ( T_3 )
V_27 -> V_37 .
V_50 +
V_41 ->
V_37 . V_50 ) ) ;
if ( ! V_3 ) {
V_30 = V_23 ;
goto V_47;
}
V_31 = ( char * ) V_3 -> V_37 . V_38 ;
memcpy ( V_31 , V_27 -> V_37 . V_38 ,
V_27 -> V_37 . V_50 ) ;
memcpy ( V_31 + V_27 -> V_37 . V_50 ,
V_41 -> V_37 . V_38 ,
V_41 -> V_37 . V_50 ) ;
break;
default:
F_5 ( ( V_19 , L_4 ,
V_27 -> V_10 . type ) ) ;
V_30 = V_20 ;
goto V_47;
}
* V_29 = V_3 ;
V_47:
if ( V_41 != V_28 ) {
F_21 ( V_41 ) ;
}
F_4 ( V_30 ) ;
}
T_4 F_22 ( T_5 V_51 , T_4 V_52 , T_4 V_53 )
{
F_23 () ;
switch ( V_51 ) {
case V_54 :
return ( V_52 + V_53 ) ;
case V_55 :
return ( V_52 & V_53 ) ;
case V_56 :
return ( ~ ( V_52 & V_53 ) ) ;
case V_57 :
return ( V_52 | V_53 ) ;
case V_58 :
return ( ~ ( V_52 | V_53 ) ) ;
case V_59 :
return ( V_52 ^ V_53 ) ;
case V_60 :
return ( V_52 * V_53 ) ;
case V_61 :
if ( V_53 >= V_62 ) {
return ( 0 ) ;
}
return ( V_52 << V_53 ) ;
case V_63 :
if ( V_53 >= V_62 ) {
return ( 0 ) ;
}
return ( V_52 >> V_53 ) ;
case V_64 :
return ( V_52 - V_53 ) ;
default:
return ( 0 ) ;
}
}
T_1
F_24 ( T_5 V_51 ,
T_4 V_52 , T_4 V_53 , T_2 * V_65 )
{
T_1 V_30 = V_26 ;
T_2 V_66 = FALSE ;
F_10 ( V_67 ) ;
switch ( V_51 ) {
case V_68 :
if ( V_52 && V_53 ) {
V_66 = TRUE ;
}
break;
case V_69 :
if ( V_52 || V_53 ) {
V_66 = TRUE ;
}
break;
default:
V_30 = V_20 ;
break;
}
* V_65 = V_66 ;
F_4 ( V_30 ) ;
}
T_1
F_25 ( T_5 V_51 ,
union V_1 * V_27 ,
union V_1 * V_28 , T_2 * V_65 )
{
union V_1 * V_41 = V_28 ;
T_4 V_52 ;
T_4 V_53 ;
T_6 V_33 ;
T_6 V_34 ;
T_1 V_30 = V_26 ;
T_2 V_66 = FALSE ;
int V_70 ;
F_10 ( V_71 ) ;
switch ( V_27 -> V_10 . type ) {
case V_43 :
V_30 =
F_16 ( V_28 , & V_41 , 16 ) ;
break;
case V_44 :
V_30 = F_17 ( V_28 , & V_41 ,
V_45 ) ;
break;
case V_46 :
V_30 = F_18 ( V_28 , & V_41 ) ;
break;
default:
V_30 = V_20 ;
break;
}
if ( F_12 ( V_30 ) ) {
goto V_47;
}
if ( V_27 -> V_10 . type == V_43 ) {
V_52 = V_27 -> integer . V_49 ;
V_53 = V_41 -> integer . V_49 ;
switch ( V_51 ) {
case V_72 :
if ( V_52 == V_53 ) {
V_66 = TRUE ;
}
break;
case V_73 :
if ( V_52 > V_53 ) {
V_66 = TRUE ;
}
break;
case V_74 :
if ( V_52 < V_53 ) {
V_66 = TRUE ;
}
break;
default:
V_30 = V_20 ;
break;
}
} else {
V_33 = V_27 -> V_37 . V_50 ;
V_34 = V_41 -> V_37 . V_50 ;
V_70 = memcmp ( V_27 -> V_37 . V_38 ,
V_41 -> V_37 . V_38 ,
( V_33 > V_34 ) ? V_34 : V_33 ) ;
switch ( V_51 ) {
case V_72 :
if ( ( V_33 == V_34 ) && ( V_70 == 0 ) ) {
V_66 = TRUE ;
}
break;
case V_73 :
if ( V_70 > 0 ) {
V_66 = TRUE ;
goto V_47;
}
if ( V_70 < 0 ) {
goto V_47;
}
if ( V_33 > V_34 ) {
V_66 = TRUE ;
}
break;
case V_74 :
if ( V_70 > 0 ) {
goto V_47;
}
if ( V_70 < 0 ) {
V_66 = TRUE ;
goto V_47;
}
if ( V_33 < V_34 ) {
V_66 = TRUE ;
}
break;
default:
V_30 = V_20 ;
break;
}
}
V_47:
if ( V_41 != V_28 ) {
F_21 ( V_41 ) ;
}
* V_65 = V_66 ;
F_4 ( V_30 ) ;
}
