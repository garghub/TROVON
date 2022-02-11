T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 ;
T_1 V_8 ;
F_2 ( V_9 ) ;
* V_6 = NULL ;
if ( V_4 -> V_10 . V_11 == V_12 ) {
if ( ! V_4 -> V_10 . V_13 ) {
if ( ( V_4 -> V_10 . V_14 -> V_10 . V_11 ==
V_15 )
|| ( V_4 -> V_10 . V_14 -> V_10 . V_11 ==
V_16 ) ) {
goto V_17;
} else {
V_8 = F_3 ( V_2 -> V_18 ,
V_4 -> V_10 . V_19 . string ,
V_20 ,
V_21 ,
V_22 |
V_23 ,
NULL ,
F_4
( struct
V_24 ,
& ( V_4 -> V_10 . V_13 ) ) ) ;
if ( F_5 ( V_8 ) ) {
F_6 ( V_4 -> V_10 . V_19 .
string , V_8 ) ;
F_7 ( V_8 ) ;
}
}
}
}
V_17:
V_7 = F_8 ( ( F_9
( V_4 -> V_10 . V_11 ) ) ->
V_25 ) ;
if ( ! V_7 ) {
F_7 ( V_26 ) ;
}
V_8 =
F_10 ( V_2 , V_4 , V_4 -> V_10 . V_11 ,
& V_7 ) ;
if ( F_5 ( V_8 ) ) {
F_11 ( V_7 ) ;
F_7 ( V_8 ) ;
}
if ( ( V_4 -> V_10 . V_14 -> V_10 . V_11 == V_15 ) ||
( V_4 -> V_10 . V_14 -> V_10 . V_11 == V_16 ) ) {
V_7 -> V_27 . V_28 = TRUE ;
if ( ( V_4 -> V_10 . V_11 == V_12 ) &&
! V_7 -> V_27 . V_13 ) {
V_7 -> V_27 . V_13 =
V_2 -> V_18 -> V_29 . V_13 ;
V_7 -> V_27 . V_30 = V_4 -> V_10 . V_30 ;
V_7 -> V_27 . V_28 = FALSE ;
}
}
* V_6 = V_7 ;
F_7 ( V_8 ) ;
}
T_1
F_12 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
T_2 V_31 ,
union V_5 * * V_6 )
{
union V_3 * V_32 ;
union V_5 * V_7 ;
union V_3 * V_33 ;
T_2 V_34 = 0 ;
F_2 ( V_35 ) ;
V_7 = * V_6 ;
if ( ! V_7 ) {
V_7 = F_8 ( V_36 ) ;
* V_6 = V_7 ;
if ( ! V_7 ) {
F_7 ( V_26 ) ;
}
}
V_32 = V_4 -> V_10 . V_19 . V_32 ;
V_33 = V_32 -> V_37 . V_38 ;
if ( V_33 ) {
if ( V_33 -> V_10 . V_11 != V_39 ) {
F_13 ( ( V_40 ,
L_1 ,
V_33 -> V_10 . V_11 , V_33 ) ) ;
F_11 ( V_7 ) ;
return ( V_41 ) ;
}
V_34 = ( T_2 ) V_33 -> V_10 . V_19 . integer ;
}
V_7 -> V_42 . V_43 = V_31 ;
if ( V_34 > V_31 ) {
V_7 -> V_42 . V_43 = V_34 ;
}
if ( V_7 -> V_42 . V_43 == 0 ) {
V_7 -> V_42 . V_44 = NULL ;
F_14 ( ( V_45 ,
L_2 ) ) ;
} else {
V_7 -> V_42 . V_44 =
F_15 ( V_7 -> V_42 . V_43 ) ;
if ( ! V_7 -> V_42 . V_44 ) {
F_16 ( V_7 ) ;
F_7 ( V_26 ) ;
}
if ( V_33 ) {
memcpy ( V_7 -> V_42 . V_44 , V_33 -> V_37 . V_46 ,
V_34 ) ;
}
}
V_7 -> V_42 . V_47 |= V_48 ;
V_4 -> V_10 . V_13 = F_17 ( struct V_24 , V_7 ) ;
F_7 ( V_49 ) ;
}
T_1
F_18 ( struct V_1 * V_2 ,
struct V_24 * V_13 ,
union V_3 * V_4 )
{
T_1 V_8 ;
union V_5 * V_7 ;
F_19 ( V_50 , V_4 ) ;
if ( F_20 ( V_13 ) ) {
F_7 ( V_49 ) ;
}
if ( ! V_4 -> V_10 . V_19 . V_32 ) {
F_7 ( V_49 ) ;
}
V_8 =
F_1 ( V_2 , V_4 -> V_10 . V_19 . V_32 ,
& V_7 ) ;
if ( F_5 ( V_8 ) ) {
F_7 ( V_8 ) ;
}
V_13 -> type = V_7 -> V_10 . type ;
V_8 = F_21 ( V_13 , V_7 , V_13 -> type ) ;
F_11 ( V_7 ) ;
F_7 ( V_8 ) ;
}
T_1
F_10 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
T_3 V_51 ,
union V_5 * * V_52 )
{
const struct V_53 * V_54 ;
union V_5 * V_7 ;
T_1 V_8 = V_49 ;
F_2 ( V_55 ) ;
V_7 = * V_52 ;
V_54 = F_9 ( V_51 ) ;
if ( V_54 -> V_56 == V_57 ) {
F_7 ( V_41 ) ;
}
switch ( V_7 -> V_10 . type ) {
case V_36 :
V_7 -> V_42 . V_13 =
F_17 ( struct V_24 ,
V_2 -> V_58 [ 0 ] ) ;
V_7 -> V_42 . V_59 = V_4 -> V_37 . V_46 ;
V_7 -> V_42 . V_60 = V_4 -> V_37 . V_43 ;
break;
case V_61 :
V_7 -> V_62 . V_13 =
F_17 ( struct V_24 ,
V_2 -> V_58 [ 0 ] ) ;
if ( ! V_4 -> V_37 . V_46 ) {
F_7 ( V_49 ) ;
}
V_7 -> V_62 . V_59 = V_4 -> V_37 . V_46 ;
V_7 -> V_62 . V_60 = V_4 -> V_37 . V_43 ;
break;
case V_63 :
switch ( V_54 -> type ) {
case V_64 :
V_7 -> V_10 . V_47 = V_65 ;
switch ( V_51 ) {
case V_66 :
V_7 -> integer . V_19 = 0 ;
break;
case V_67 :
V_7 -> integer . V_19 = 1 ;
break;
case V_68 :
V_7 -> integer . V_19 = V_69 ;
#ifndef F_22
( void ) F_23 ( V_7 ) ;
#endif
break;
case V_70 :
V_7 -> integer . V_19 = V_71 ;
break;
default:
F_13 ( ( V_40 ,
L_3 ,
V_51 ) ) ;
V_8 = V_72 ;
break;
}
break;
case V_73 :
V_7 -> integer . V_19 = V_4 -> V_10 . V_19 . integer ;
#ifndef F_22
if ( F_23 ( V_7 ) ) {
F_24 ( ( V_40 ,
L_4 ,
F_25 ( V_4 -> V_10 .
V_19 . integer ) ,
( T_2 ) V_7 -> integer . V_19 ) ) ;
}
#endif
break;
default:
F_13 ( ( V_40 , L_5 ,
V_54 -> type ) ) ;
V_8 = V_72 ;
break;
}
break;
case V_74 :
V_7 -> string . V_44 = V_4 -> V_10 . V_19 . string ;
V_7 -> string . V_43 = ( T_2 ) strlen ( V_4 -> V_10 . V_19 . string ) ;
V_7 -> V_10 . V_47 |= V_75 ;
break;
case V_76 :
break;
case V_77 :
switch ( V_54 -> type ) {
case V_78 :
V_7 -> V_27 . V_19 =
( ( T_2 ) V_51 ) - V_79 ;
V_7 -> V_27 . V_56 = V_80 ;
#ifndef F_22
V_8 =
F_26 ( V_80 ,
V_7 -> V_27 .
V_19 , V_2 ,
F_4
( struct
V_24 ,
& V_7 -> V_27 .
V_81 ) ) ;
#endif
break;
case V_82 :
V_7 -> V_27 . V_19 =
( ( T_2 ) V_51 ) - V_83 ;
V_7 -> V_27 . V_56 = V_84 ;
#ifndef F_22
V_8 = F_26 ( V_84 ,
V_7 ->
V_27 . V_19 ,
V_2 ,
F_4
( struct
V_24 ,
& V_7 ->
V_27 .
V_81 ) ) ;
#endif
break;
default:
switch ( V_4 -> V_10 . V_11 ) {
case V_12 :
V_7 -> V_27 . V_13 = V_4 -> V_10 . V_13 ;
V_7 -> V_27 . V_56 = V_85 ;
if ( V_4 -> V_10 . V_13 ) {
V_7 -> V_27 . V_81 =
V_4 -> V_10 . V_13 -> V_81 ;
}
break;
case V_86 :
V_7 -> V_27 . V_56 = V_87 ;
break;
default:
F_13 ( ( V_40 ,
L_6 ,
V_51 ) ) ;
F_7 ( V_72 ) ;
}
break;
}
break;
default:
F_13 ( ( V_40 , L_7 ,
V_7 -> V_10 . type ) ) ;
V_8 = V_72 ;
break;
}
F_7 ( V_8 ) ;
}
