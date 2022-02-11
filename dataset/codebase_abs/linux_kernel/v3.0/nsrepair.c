T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_2 V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
union V_5 * V_8 ;
T_1 V_9 ;
F_2 ( V_10 ) ;
if ( V_3 & V_11 ) {
V_9 = F_3 ( V_7 , & V_8 ) ;
if ( F_4 ( V_9 ) ) {
goto V_12;
}
}
if ( V_3 & V_13 ) {
V_9 = F_5 ( V_7 , & V_8 ) ;
if ( F_4 ( V_9 ) ) {
goto V_12;
}
}
if ( V_3 & V_14 ) {
V_9 = F_6 ( V_7 , & V_8 ) ;
if ( F_4 ( V_9 ) ) {
goto V_12;
}
}
if ( V_3 & V_15 ) {
V_9 = F_7 ( V_7 , & V_8 ) ;
if ( F_4 ( V_9 ) ) {
goto V_12;
}
}
return ( V_16 ) ;
V_12:
if ( V_4 != V_17 ) {
V_8 -> V_18 . V_19 =
V_7 -> V_18 . V_19 ;
if ( V_7 -> V_18 . V_19 > 1 ) {
V_7 -> V_18 . V_19 -- ;
}
F_8 ( ( V_20 ,
L_1 ,
V_2 -> V_21 ,
F_9 ( V_7 ) ,
F_9 ( V_8 ) ,
V_4 ) ) ;
} else {
F_8 ( ( V_20 ,
L_2 ,
V_2 -> V_21 ,
F_9 ( V_7 ) ,
F_9 ( V_8 ) ) ) ;
}
F_10 ( V_7 ) ;
* V_6 = V_8 ;
V_2 -> V_22 |= V_23 ;
return ( V_24 ) ;
}
static T_1
F_3 ( union V_5 * V_25 ,
union V_5 * * V_7 )
{
union V_5 * V_8 ;
T_1 V_9 ;
T_3 V_26 = 0 ;
T_2 V_27 ;
switch ( V_25 -> V_18 . type ) {
case V_28 :
V_9 = F_11 ( V_25 -> string . V_29 ,
V_30 , & V_26 ) ;
if ( F_12 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_31 :
if ( V_25 -> V_32 . V_33 > 8 ) {
return ( V_16 ) ;
}
for ( V_27 = 0 ; V_27 < V_25 -> V_32 . V_33 ; V_27 ++ ) {
V_26 |=
( ( T_3 ) V_25 -> V_32 .
V_29 [ V_27 ] << ( V_27 * 8 ) ) ;
}
break;
default:
return ( V_16 ) ;
}
V_8 = F_13 ( V_26 ) ;
if ( ! V_8 ) {
return ( V_34 ) ;
}
* V_7 = V_8 ;
return ( V_24 ) ;
}
static T_1
F_5 ( union V_5 * V_25 ,
union V_5 * * V_7 )
{
union V_5 * V_8 ;
T_4 V_33 ;
T_1 V_9 ;
switch ( V_25 -> V_18 . type ) {
case V_35 :
if ( V_25 -> integer . V_26 == 0 ) {
V_8 = F_14 ( 0 ) ;
if ( ! V_8 ) {
return ( V_34 ) ;
}
} else {
V_9 =
F_15 ( V_25 ,
& V_8 ,
V_36 ) ;
if ( F_12 ( V_9 ) ) {
return ( V_9 ) ;
}
}
break;
case V_31 :
V_33 = 0 ;
while ( ( V_33 < V_25 -> V_32 . V_33 ) &&
( V_25 -> V_32 . V_29 [ V_33 ] ) ) {
V_33 ++ ;
}
V_8 = F_14 ( V_33 ) ;
if ( ! V_8 ) {
return ( V_34 ) ;
}
F_16 ( V_8 -> string . V_29 ,
V_25 -> V_32 . V_29 , V_33 ) ;
break;
default:
return ( V_16 ) ;
}
* V_7 = V_8 ;
return ( V_24 ) ;
}
static T_1
F_6 ( union V_5 * V_25 ,
union V_5 * * V_7 )
{
union V_5 * V_8 ;
T_1 V_9 ;
union V_5 * * V_37 ;
T_2 * V_38 ;
T_2 V_39 ;
T_2 V_27 ;
switch ( V_25 -> V_18 . type ) {
case V_35 :
V_9 =
F_17 ( V_25 , & V_8 ) ;
if ( F_12 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_28 :
V_8 =
F_18 ( V_25 -> string .
V_33 ) ;
if ( ! V_8 ) {
return ( V_34 ) ;
}
F_16 ( V_8 -> V_32 . V_29 ,
V_25 -> string . V_29 ,
V_25 -> string . V_33 ) ;
break;
case V_40 :
V_37 = V_25 -> V_41 . V_37 ;
V_39 = V_25 -> V_41 . V_39 ;
for ( V_27 = 0 ; V_27 < V_39 ; V_27 ++ ) {
if ( ( ! * V_37 ) ||
( ( * V_37 ) -> V_18 . type != V_35 ) ) {
return ( V_16 ) ;
}
V_37 ++ ;
}
V_8 = F_18 ( F_19 ( V_39 ) ) ;
if ( ! V_8 ) {
return ( V_34 ) ;
}
V_37 = V_25 -> V_41 . V_37 ;
V_38 = F_20 ( T_2 , V_8 -> V_32 . V_29 ) ;
for ( V_27 = 0 ; V_27 < V_39 ; V_27 ++ ) {
* V_38 = ( T_2 ) ( * V_37 ) -> integer . V_26 ;
V_38 ++ ;
V_37 ++ ;
}
break;
default:
return ( V_16 ) ;
}
* V_7 = V_8 ;
return ( V_24 ) ;
}
static T_1
F_7 ( union V_5 * V_25 ,
union V_5 * * V_7 )
{
union V_5 * V_8 ;
union V_5 * * V_37 ;
T_2 V_33 ;
T_5 * V_32 ;
switch ( V_25 -> V_18 . type ) {
case V_31 :
V_33 = V_25 -> V_32 . V_33 ;
V_8 = F_21 ( V_33 ) ;
if ( ! V_8 ) {
return ( V_34 ) ;
}
V_37 = V_8 -> V_41 . V_37 ;
V_32 = V_25 -> V_32 . V_29 ;
while ( V_33 -- ) {
* V_37 =
F_13 ( ( T_3 ) * V_32 ) ;
if ( ! * V_37 ) {
F_10 ( V_8 ) ;
return ( V_34 ) ;
}
V_37 ++ ;
V_32 ++ ;
}
break;
default:
return ( V_16 ) ;
}
* V_7 = V_8 ;
return ( V_24 ) ;
}
T_1
F_22 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_2 V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
union V_5 * V_8 ;
F_2 ( V_42 ) ;
if ( V_7 ) {
return ( V_24 ) ;
}
if ( V_3 & V_11 ) {
V_8 = F_13 ( ( T_3 ) 0 ) ;
} else if ( V_3 & V_13 ) {
V_8 = F_14 ( 0 ) ;
} else if ( V_3 & V_14 ) {
V_8 = F_18 ( 0 ) ;
} else {
return ( V_16 ) ;
}
if ( ! V_8 ) {
return ( V_34 ) ;
}
V_8 -> V_18 . V_19 =
V_2 -> V_43 -> V_18 . V_19 ;
F_8 ( ( V_20 ,
L_3 ,
V_2 -> V_21 ,
F_9 ( V_8 ) ,
V_4 ) ) ;
* V_6 = V_8 ;
V_2 -> V_22 |= V_23 ;
return ( V_24 ) ;
}
void
F_23 ( struct V_1 * V_2 ,
T_5 V_44 ,
union V_5 * V_45 )
{
union V_5 * * V_46 ;
union V_5 * * V_47 ;
T_2 V_39 ;
T_2 V_48 ;
T_2 V_27 ;
F_2 ( V_49 ) ;
switch ( V_44 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
break;
default:
case V_57 :
case V_58 :
return;
}
V_39 = V_45 -> V_41 . V_39 ;
V_48 = V_39 ;
V_46 = V_45 -> V_41 . V_37 ;
V_47 = V_46 ;
for ( V_27 = 0 ; V_27 < V_39 ; V_27 ++ ) {
if ( ! * V_46 ) {
V_48 -- ;
} else {
* V_47 = * V_46 ;
V_47 ++ ;
}
V_46 ++ ;
}
if ( V_48 < V_39 ) {
F_8 ( ( V_20 ,
L_4 ,
V_2 -> V_21 , ( V_39 - V_48 ) ) ) ;
* V_47 = NULL ;
V_45 -> V_41 . V_39 = V_48 ;
}
}
T_1
F_24 ( struct V_1 * V_2 ,
union V_5 * * V_59 )
{
union V_5 * V_60 ;
F_2 ( V_61 ) ;
V_60 = F_21 ( 1 ) ;
if ( ! V_60 ) {
return ( V_34 ) ;
}
V_60 -> V_41 . V_37 [ 0 ] = * V_59 ;
* V_59 = V_60 ;
V_2 -> V_22 |= V_23 ;
F_8 ( ( V_20 ,
L_5 ,
V_2 -> V_21 ) ) ;
return ( V_24 ) ;
}
