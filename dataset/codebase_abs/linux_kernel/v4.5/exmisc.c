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
T_1
F_9 ( union V_1 * V_26 ,
union V_1 * V_27 ,
union V_1 * * V_28 ,
struct V_4 * V_5 )
{
T_1 V_29 ;
union V_1 * V_3 ;
T_2 * V_30 ;
T_2 * V_31 ;
T_3 V_32 ;
T_3 V_33 ;
T_3 V_34 ;
F_10 ( V_35 ) ;
V_29 = F_11 ( V_26 , & V_31 ) ;
if ( F_12 ( V_29 ) ) {
F_4 ( V_29 ) ;
}
V_32 = F_13 ( V_31 , V_26 -> V_36 . V_37 ) ;
V_29 = F_11 ( V_27 , & V_31 ) ;
if ( F_12 ( V_29 ) ) {
F_4 ( V_29 ) ;
}
V_33 = F_13 ( V_31 , V_27 -> V_36 . V_37 ) ;
V_34 = V_32 + V_33 + sizeof( struct V_38 ) ;
V_3 = F_14 ( V_34 ) ;
if ( ! V_3 ) {
F_4 ( V_22 ) ;
}
V_30 = V_3 -> V_36 . V_37 ;
memcpy ( V_30 , V_26 -> V_36 . V_37 , V_32 ) ;
memcpy ( V_30 + V_32 , V_27 -> V_36 . V_37 , V_33 ) ;
V_30 [ V_34 - 1 ] = 0 ;
V_30 [ V_34 - 2 ] = V_39 | 1 ;
* V_28 = V_3 ;
F_4 ( V_25 ) ;
}
T_1
F_15 ( union V_1 * V_26 ,
union V_1 * V_27 ,
union V_1 * * V_28 ,
struct V_4 * V_5 )
{
union V_1 * V_40 = V_27 ;
union V_1 * V_3 ;
char * V_30 ;
const char * V_41 ;
T_1 V_29 ;
F_10 ( V_42 ) ;
switch ( V_26 -> V_10 . type ) {
case V_43 :
V_29 =
F_16 ( V_27 , & V_40 , 16 ) ;
break;
case V_44 :
switch ( V_27 -> V_10 . type ) {
case V_43 :
case V_44 :
case V_45 :
V_29 =
F_17 ( V_27 , & V_40 ,
V_46 ) ;
break;
default:
V_41 =
F_18 ( V_27 -> V_10 . type ) ;
V_40 = F_19 ( ( ( T_3 ) strlen ( V_41 ) + 9 ) ) ;
if ( ! V_40 ) {
V_29 = V_22 ;
goto V_47;
}
strcpy ( V_40 -> string . V_37 , L_4 ) ;
strcat ( V_40 -> string . V_37 , V_41 ) ;
strcat ( V_40 -> string . V_37 , L_5 ) ;
V_29 = V_25 ;
break;
}
break;
case V_45 :
V_29 = F_20 ( V_27 , & V_40 ) ;
break;
default:
F_5 ( ( V_19 , L_6 ,
V_26 -> V_10 . type ) ) ;
V_29 = V_48 ;
}
if ( F_12 ( V_29 ) ) {
goto V_47;
}
switch ( V_26 -> V_10 . type ) {
case V_43 :
V_3 = F_14 ( ( T_3 )
F_21
( V_49 ) ) ;
if ( ! V_3 ) {
V_29 = V_22 ;
goto V_47;
}
V_30 = ( char * ) V_3 -> V_36 . V_37 ;
memcpy ( V_30 , & V_26 -> integer . V_50 ,
V_49 ) ;
memcpy ( V_30 + V_49 ,
& V_40 -> integer . V_50 ,
V_49 ) ;
break;
case V_44 :
V_3 = F_19 ( ( ( T_3 )
V_26 -> string .
V_51 +
V_40 ->
string . V_51 ) ) ;
if ( ! V_3 ) {
V_29 = V_22 ;
goto V_47;
}
V_30 = V_3 -> string . V_37 ;
strcpy ( V_30 , V_26 -> string . V_37 ) ;
strcat ( V_30 , V_40 -> string . V_37 ) ;
break;
case V_45 :
V_3 = F_14 ( ( ( T_3 )
V_26 -> V_36 .
V_51 +
V_40 ->
V_36 . V_51 ) ) ;
if ( ! V_3 ) {
V_29 = V_22 ;
goto V_47;
}
V_30 = ( char * ) V_3 -> V_36 . V_37 ;
memcpy ( V_30 , V_26 -> V_36 . V_37 ,
V_26 -> V_36 . V_51 ) ;
memcpy ( V_30 + V_26 -> V_36 . V_51 ,
V_40 -> V_36 . V_37 ,
V_40 -> V_36 . V_51 ) ;
break;
default:
F_5 ( ( V_19 , L_6 ,
V_26 -> V_10 . type ) ) ;
V_29 = V_48 ;
goto V_47;
}
* V_28 = V_3 ;
V_47:
if ( V_40 != V_27 ) {
F_22 ( V_40 ) ;
}
F_4 ( V_29 ) ;
}
T_4 F_23 ( T_5 V_52 , T_4 V_53 , T_4 V_54 )
{
F_24 () ;
switch ( V_52 ) {
case V_55 :
return ( V_53 + V_54 ) ;
case V_56 :
return ( V_53 & V_54 ) ;
case V_57 :
return ( ~ ( V_53 & V_54 ) ) ;
case V_58 :
return ( V_53 | V_54 ) ;
case V_59 :
return ( ~ ( V_53 | V_54 ) ) ;
case V_60 :
return ( V_53 ^ V_54 ) ;
case V_61 :
return ( V_53 * V_54 ) ;
case V_62 :
if ( V_54 >= V_63 ) {
return ( 0 ) ;
}
return ( V_53 << V_54 ) ;
case V_64 :
if ( V_54 >= V_63 ) {
return ( 0 ) ;
}
return ( V_53 >> V_54 ) ;
case V_65 :
return ( V_53 - V_54 ) ;
default:
return ( 0 ) ;
}
}
T_1
F_25 ( T_5 V_52 ,
T_4 V_53 , T_4 V_54 , T_2 * V_66 )
{
T_1 V_29 = V_25 ;
T_2 V_67 = FALSE ;
F_10 ( V_68 ) ;
switch ( V_52 ) {
case V_69 :
if ( V_53 && V_54 ) {
V_67 = TRUE ;
}
break;
case V_70 :
if ( V_53 || V_54 ) {
V_67 = TRUE ;
}
break;
default:
V_29 = V_48 ;
break;
}
* V_66 = V_67 ;
F_4 ( V_29 ) ;
}
T_1
F_26 ( T_5 V_52 ,
union V_1 * V_26 ,
union V_1 * V_27 , T_2 * V_66 )
{
union V_1 * V_40 = V_27 ;
T_4 V_53 ;
T_4 V_54 ;
T_6 V_32 ;
T_6 V_33 ;
T_1 V_29 = V_25 ;
T_2 V_67 = FALSE ;
int V_71 ;
F_10 ( V_72 ) ;
switch ( V_26 -> V_10 . type ) {
case V_43 :
V_29 =
F_16 ( V_27 , & V_40 , 16 ) ;
break;
case V_44 :
V_29 =
F_17 ( V_27 , & V_40 ,
V_46 ) ;
break;
case V_45 :
V_29 = F_20 ( V_27 , & V_40 ) ;
break;
default:
V_29 = V_48 ;
break;
}
if ( F_12 ( V_29 ) ) {
goto V_47;
}
if ( V_26 -> V_10 . type == V_43 ) {
V_53 = V_26 -> integer . V_50 ;
V_54 = V_40 -> integer . V_50 ;
switch ( V_52 ) {
case V_73 :
if ( V_53 == V_54 ) {
V_67 = TRUE ;
}
break;
case V_74 :
if ( V_53 > V_54 ) {
V_67 = TRUE ;
}
break;
case V_75 :
if ( V_53 < V_54 ) {
V_67 = TRUE ;
}
break;
default:
V_29 = V_48 ;
break;
}
} else {
V_32 = V_26 -> V_36 . V_51 ;
V_33 = V_40 -> V_36 . V_51 ;
V_71 = memcmp ( V_26 -> V_36 . V_37 ,
V_40 -> V_36 . V_37 ,
( V_32 > V_33 ) ? V_33 : V_32 ) ;
switch ( V_52 ) {
case V_73 :
if ( ( V_32 == V_33 ) && ( V_71 == 0 ) ) {
V_67 = TRUE ;
}
break;
case V_74 :
if ( V_71 > 0 ) {
V_67 = TRUE ;
goto V_47;
}
if ( V_71 < 0 ) {
goto V_47;
}
if ( V_32 > V_33 ) {
V_67 = TRUE ;
}
break;
case V_75 :
if ( V_71 > 0 ) {
goto V_47;
}
if ( V_71 < 0 ) {
V_67 = TRUE ;
goto V_47;
}
if ( V_32 < V_33 ) {
V_67 = TRUE ;
}
break;
default:
V_29 = V_48 ;
break;
}
}
V_47:
if ( V_40 != V_27 ) {
F_22 ( V_40 ) ;
}
* V_66 = V_67 ;
F_4 ( V_29 ) ;
}
