T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_1 V_3 ;
F_2 ( F_1 ) ;
V_2 = & V_4 . V_5 ;
if ( ! ( V_4 . V_6 & V_7 ) ||
! V_2 -> V_8 ) {
F_3 ( V_9 ) ;
}
if ( V_2 -> V_10 == V_11 ) {
V_3 =
F_4 ( ( V_12 ) V_2 -> V_8 ,
V_4 . V_13 ,
V_14 ) ;
} else {
V_3 = F_5 ( V_4 . V_13 , V_2 ) ;
}
F_3 ( V_3 ) ;
}
T_1 F_6 ( T_2 * V_15 , struct V_1 * V_16 )
{
T_3 V_17 ;
T_3 V_18 ;
T_3 V_19 ;
T_2 V_8 ;
T_1 V_3 ;
F_7 ( F_6 ) ;
if ( ! V_15 ) {
return ( V_20 ) ;
}
V_3 = F_8 ( V_16 , 64 , & V_8 ) ;
if ( F_9 ( V_3 ) ) {
return ( V_3 ) ;
}
if ( V_16 -> V_10 == V_21 ) {
V_3 = F_10 ( ( V_22 )
V_8 , V_15 ,
V_16 -> V_23 ) ;
if ( F_9 ( V_3 ) ) {
return ( V_3 ) ;
}
} else {
V_17 = 0 ;
V_18 = 0 ;
V_19 = V_16 -> V_23 ;
if ( V_19 == 64 ) {
V_19 = 32 ;
}
V_3 = F_11 ( ( V_12 )
V_8 , & V_17 , V_19 ) ;
if ( F_9 ( V_3 ) ) {
return ( V_3 ) ;
}
if ( V_16 -> V_23 == 64 ) {
V_3 = F_11 ( ( V_12 )
( V_8 + 4 ) , & V_18 ,
32 ) ;
if ( F_9 ( V_3 ) ) {
return ( V_3 ) ;
}
}
* V_15 = ( V_17 | ( ( T_2 ) V_18 << 32 ) ) ;
}
F_12 ( ( V_24 ,
L_1 ,
F_13 ( * V_15 ) , V_16 -> V_23 ,
F_13 ( V_8 ) ,
F_14 ( V_16 -> V_10 ) ) ) ;
return ( V_25 ) ;
}
T_1 F_15 ( T_2 V_26 , struct V_1 * V_16 )
{
T_3 V_19 ;
T_2 V_8 ;
T_1 V_3 ;
F_7 ( F_15 ) ;
V_3 = F_8 ( V_16 , 64 , & V_8 ) ;
if ( F_9 ( V_3 ) ) {
return ( V_3 ) ;
}
if ( V_16 -> V_10 == V_21 ) {
V_3 = F_16 ( ( V_22 )
V_8 , V_26 , V_16 -> V_23 ) ;
if ( F_9 ( V_3 ) ) {
return ( V_3 ) ;
}
} else {
V_19 = V_16 -> V_23 ;
if ( V_19 == 64 ) {
V_19 = 32 ;
}
V_3 = F_17 ( ( V_12 )
V_8 , F_18 ( V_26 ) ,
V_19 ) ;
if ( F_9 ( V_3 ) ) {
return ( V_3 ) ;
}
if ( V_16 -> V_23 == 64 ) {
V_3 = F_17 ( ( V_12 )
( V_8 + 4 ) ,
F_19 ( V_26 ) , 32 ) ;
if ( F_9 ( V_3 ) ) {
return ( V_3 ) ;
}
}
}
F_12 ( ( V_24 ,
L_2 ,
F_13 ( V_26 ) , V_16 -> V_23 ,
F_13 ( V_8 ) ,
F_14 ( V_16 -> V_10 ) ) ) ;
return ( V_3 ) ;
}
T_1 F_20 ( T_3 V_27 , T_3 * V_15 )
{
struct V_28 * V_29 ;
T_3 V_30 ;
T_3 V_26 ;
T_1 V_3 ;
F_21 ( F_20 , V_27 ) ;
V_29 = F_22 ( V_27 ) ;
if ( ! V_29 ) {
F_3 ( V_20 ) ;
}
V_3 = F_23 ( V_29 -> V_31 ,
& V_30 ) ;
if ( F_9 ( V_3 ) ) {
F_3 ( V_3 ) ;
}
V_26 = ( ( V_30 & V_29 -> V_32 )
>> V_29 -> V_33 ) ;
F_12 ( ( V_24 ,
L_3 ,
V_27 , V_29 -> V_31 ,
V_30 , V_26 ) ) ;
* V_15 = V_26 ;
F_3 ( V_25 ) ;
}
T_1 F_24 ( T_3 V_27 , T_3 V_26 )
{
struct V_28 * V_29 ;
T_4 V_34 ;
T_3 V_30 ;
T_1 V_3 = V_25 ;
F_21 ( F_24 , V_27 ) ;
V_29 = F_22 ( V_27 ) ;
if ( ! V_29 ) {
F_3 ( V_20 ) ;
}
V_34 = F_25 ( V_35 ) ;
if ( V_29 -> V_31 != V_36 ) {
V_3 = F_23 ( V_29 -> V_31 ,
& V_30 ) ;
if ( F_9 ( V_3 ) ) {
goto V_37;
}
F_26 ( V_30 ,
V_29 -> V_33 ,
V_29 -> V_32 ,
V_26 ) ;
V_3 = F_27 ( V_29 -> V_31 ,
V_30 ) ;
} else {
V_30 = F_28 ( V_26 ,
V_29 ->
V_33 ,
V_29 ->
V_32 ) ;
if ( V_30 ) {
V_3 =
F_27 ( V_36 ,
V_30 ) ;
}
}
F_12 ( ( V_24 ,
L_4 ,
V_27 , V_29 -> V_31 , V_26 ,
V_30 ) ) ;
V_37:
F_29 ( V_35 , V_34 ) ;
F_3 ( V_3 ) ;
}
T_1
F_30 ( T_5 V_38 , T_5 * V_39 , T_5 * V_40 )
{
T_1 V_3 ;
struct V_41 * V_42 ;
union V_43 * * V_44 ;
F_2 ( F_30 ) ;
if ( ( V_38 > V_45 ) || ! V_39 || ! V_40 ) {
F_3 ( V_20 ) ;
}
V_42 = F_31 ( sizeof( struct V_41 ) ) ;
if ( ! V_42 ) {
F_3 ( V_46 ) ;
}
V_42 -> V_47 =
F_32 ( char , V_48 [ V_38 ] ) ;
V_3 = F_33 ( V_42 ) ;
if ( F_9 ( V_3 ) ) {
goto V_49;
}
if ( ! V_42 -> V_50 ) {
F_34 ( ( V_51 , L_5 ,
V_42 -> V_47 ) ) ;
V_3 = V_52 ;
goto V_49;
}
if ( V_42 -> V_50 -> V_53 . type != V_54 ) {
F_34 ( ( V_51 ,
L_6 ) ) ;
V_3 = V_55 ;
goto V_56;
}
V_44 = V_42 -> V_50 -> V_57 . V_44 ;
switch ( V_42 -> V_50 -> V_57 . V_58 ) {
case 0 :
V_3 = V_59 ;
break;
case 1 :
if ( V_44 [ 0 ] -> V_53 . type != V_60 ) {
V_3 = V_55 ;
break;
}
* V_39 = ( T_5 ) V_44 [ 0 ] -> integer . V_26 ;
* V_40 = ( T_5 ) ( V_44 [ 0 ] -> integer . V_26 >> 8 ) ;
break;
case 2 :
default:
if ( ( V_44 [ 0 ] -> V_53 . type != V_60 ) ||
( V_44 [ 1 ] -> V_53 . type != V_60 ) ) {
V_3 = V_55 ;
break;
}
* V_39 = ( T_5 ) V_44 [ 0 ] -> integer . V_26 ;
* V_40 = ( T_5 ) V_44 [ 1 ] -> integer . V_26 ;
break;
}
V_56:
F_35 ( V_42 -> V_50 ) ;
V_49:
if ( F_9 ( V_3 ) ) {
F_36 ( ( V_51 , V_3 ,
L_7 ,
V_42 -> V_47 ) ) ;
}
F_37 ( V_42 ) ;
F_3 ( V_3 ) ;
}
