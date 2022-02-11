T_1 F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 ;
F_2 ( V_3 ) ;
V_1 = F_3 ( V_4 ) ;
if ( F_4 ( V_1 ) ) {
F_5 ( V_1 ) ;
}
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
V_1 = F_6 ( V_6 ,
V_7
[ V_2 ] ,
V_8 ,
NULL , NULL ) ;
switch ( V_1 ) {
case V_9 :
case V_10 :
case V_11 :
V_1 = V_9 ;
break;
default:
goto V_12;
}
}
V_12:
( void ) F_7 ( V_4 ) ;
F_5 ( V_1 ) ;
}
T_3
F_8 ( struct V_13 * V_14 ,
T_4 V_15 )
{
union V_16 * V_17 ;
union V_16 * V_18 ;
V_17 = F_9 ( V_14 ) ;
if ( V_17 ) {
V_18 = V_17 -> V_19 . V_20 ;
while ( V_18 ) {
if ( V_18 -> V_21 . V_15 == V_15 ) {
if ( V_18 -> V_21 . V_22 &
V_23 ) {
return ( TRUE ) ;
}
}
V_18 = V_18 -> V_21 . V_24 ;
}
}
return ( FALSE ) ;
}
static T_1
F_10 ( T_5 V_25 ,
T_2 V_26 , void * V_27 , void * * V_28 )
{
union V_16 * V_18 ;
union V_16 * V_29 ;
union V_16 * V_17 ;
struct V_13 * V_14 ;
T_1 V_1 ;
F_11 ( V_30 ) ;
V_18 = (union V_16 * ) V_27 ;
if ( ! V_18 ) {
return ( V_9 ) ;
}
V_14 = F_12 ( V_25 ) ;
if ( ! V_14 ) {
return ( V_31 ) ;
}
if ( ( V_14 -> type != V_32 ) &&
( V_14 -> type != V_33 ) && ( V_14 != V_6 ) ) {
return ( V_9 ) ;
}
V_17 = F_9 ( V_14 ) ;
if ( ! V_17 ) {
return ( V_9 ) ;
}
if ( V_17 -> V_34 . type == V_32 ) {
V_29 = V_17 -> V_19 . V_20 ;
while ( V_29 ) {
if ( V_29 -> V_21 . V_15 ==
V_18 -> V_21 . V_15 ) {
F_13 ( ( V_35 ,
L_1
L_2 ,
F_14
( V_18 -> V_21 .
V_15 ) , V_17 ,
V_29 ,
V_18 ) ) ;
return ( V_36 ) ;
}
V_29 = V_29 -> V_21 . V_24 ;
}
return ( V_9 ) ;
}
if ( V_17 -> V_37 . V_15 != V_18 -> V_21 . V_15 ) {
return ( V_9 ) ;
}
F_15 ( V_17 , FALSE ) ;
V_1 = F_16 ( V_18 , V_17 , FALSE ) ;
return ( V_1 ) ;
}
T_1
F_6 ( struct V_13 * V_14 ,
T_4 V_15 ,
T_6 V_20 ,
T_7 V_38 , void * V_27 )
{
union V_16 * V_17 ;
union V_16 * V_18 ;
T_1 V_1 ;
T_8 type ;
T_3 V_39 = 0 ;
F_2 ( V_40 ) ;
if ( ( V_14 -> type != V_32 ) &&
( V_14 -> type != V_41 ) &&
( V_14 -> type != V_42 ) && ( V_14 != V_6 ) ) {
V_1 = V_31 ;
goto V_12;
}
if ( V_20 == V_8 ) {
V_39 = V_23 ;
switch ( V_15 ) {
case V_43 :
V_20 = V_44 ;
V_38 = V_45 ;
break;
case V_46 :
V_20 = V_47 ;
V_38 = V_48 ;
break;
case V_49 :
V_20 = V_50 ;
V_38 = V_51 ;
break;
case V_52 :
V_20 = V_53 ;
V_38 = V_54 ;
break;
case V_55 :
V_20 = V_56 ;
V_38 = V_57 ;
break;
case V_58 :
V_20 = V_59 ;
V_38 = NULL ;
break;
default:
V_1 = V_31 ;
goto V_12;
}
}
if ( ! V_38 ) {
V_38 = V_60 ;
}
V_17 = F_9 ( V_14 ) ;
if ( V_17 ) {
V_18 = V_17 -> V_19 . V_20 ;
while ( V_18 ) {
if ( V_18 -> V_21 . V_15 == V_15 ) {
if ( V_18 -> V_21 . V_20 ==
V_20 ) {
V_1 = V_10 ;
goto V_12;
} else {
V_1 = V_11 ;
}
goto V_12;
}
V_18 = V_18 -> V_21 . V_24 ;
}
} else {
F_13 ( ( V_35 ,
L_3 ,
V_14 ) ) ;
if ( V_14 -> type == V_61 ) {
type = V_32 ;
} else {
type = V_14 -> type ;
}
V_17 = F_17 ( type ) ;
if ( ! V_17 ) {
V_1 = V_62 ;
goto V_12;
}
V_17 -> V_34 . type = ( T_3 ) type ;
V_1 = F_18 ( V_14 , V_17 , type ) ;
F_19 ( V_17 ) ;
if ( F_4 ( V_1 ) ) {
goto V_12;
}
}
F_13 ( ( V_35 ,
L_4 ,
F_14 ( V_15 ) , V_15 ,
F_20 ( V_14 ) , V_14 , V_17 ) ) ;
V_18 =
F_17 ( V_63 ) ;
if ( ! V_18 ) {
V_1 = V_62 ;
goto V_12;
}
V_18 -> V_21 . V_15 = ( T_3 ) V_15 ;
V_18 -> V_21 . V_22 = V_39 ;
V_18 -> V_21 . V_64 = NULL ;
V_18 -> V_21 . V_14 = V_14 ;
V_18 -> V_21 . V_20 = V_20 ;
V_18 -> V_21 . V_27 = V_27 ;
V_18 -> V_21 . V_38 = V_38 ;
V_18 -> V_21 . V_24 = V_17 -> V_19 . V_20 ;
V_17 -> V_19 . V_20 = V_18 ;
V_1 = F_21 ( V_61 , V_14 , V_65 ,
V_66 ,
F_10 , NULL ,
V_18 , NULL ) ;
V_12:
F_5 ( V_1 ) ;
}
