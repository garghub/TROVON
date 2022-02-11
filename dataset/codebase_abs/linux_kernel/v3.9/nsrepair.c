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
V_9 =
F_7 ( V_2 , V_7 , & V_8 ) ;
if ( F_4 ( V_9 ) ) {
* V_6 = V_8 ;
V_2 -> V_16 |= V_17 ;
return ( V_18 ) ;
}
}
return ( V_19 ) ;
V_12:
if ( V_4 != V_20 ) {
if ( ! ( V_2 -> V_16 & V_21 ) ) {
V_8 -> V_22 . V_23 =
V_7 -> V_22 . V_23 ;
if ( V_7 -> V_22 . V_23 > 1 ) {
V_7 -> V_22 . V_23 -- ;
}
}
F_8 ( ( V_24 ,
L_1 ,
V_2 -> V_25 ,
F_9 ( V_7 ) ,
F_9 ( V_8 ) ,
V_4 ) ) ;
} else {
F_8 ( ( V_24 ,
L_2 ,
V_2 -> V_25 ,
F_9 ( V_7 ) ,
F_9 ( V_8 ) ) ) ;
}
F_10 ( V_7 ) ;
* V_6 = V_8 ;
V_2 -> V_16 |= V_17 ;
return ( V_18 ) ;
}
static T_1
F_3 ( union V_5 * V_26 ,
union V_5 * * V_7 )
{
union V_5 * V_8 ;
T_1 V_9 ;
T_3 V_27 = 0 ;
T_2 V_28 ;
switch ( V_26 -> V_22 . type ) {
case V_29 :
V_9 = F_11 ( V_26 -> string . V_30 ,
V_31 , & V_27 ) ;
if ( F_12 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_32 :
if ( V_26 -> V_33 . V_34 > 8 ) {
return ( V_19 ) ;
}
for ( V_28 = 0 ; V_28 < V_26 -> V_33 . V_34 ; V_28 ++ ) {
V_27 |=
( ( T_3 ) V_26 -> V_33 .
V_30 [ V_28 ] << ( V_28 * 8 ) ) ;
}
break;
default:
return ( V_19 ) ;
}
V_8 = F_13 ( V_27 ) ;
if ( ! V_8 ) {
return ( V_35 ) ;
}
* V_7 = V_8 ;
return ( V_18 ) ;
}
static T_1
F_5 ( union V_5 * V_26 ,
union V_5 * * V_7 )
{
union V_5 * V_8 ;
T_4 V_34 ;
T_1 V_9 ;
switch ( V_26 -> V_22 . type ) {
case V_36 :
if ( V_26 -> integer . V_27 == 0 ) {
V_8 = F_14 ( 0 ) ;
if ( ! V_8 ) {
return ( V_35 ) ;
}
} else {
V_9 =
F_15 ( V_26 ,
& V_8 ,
V_37 ) ;
if ( F_12 ( V_9 ) ) {
return ( V_9 ) ;
}
}
break;
case V_32 :
V_34 = 0 ;
while ( ( V_34 < V_26 -> V_33 . V_34 ) &&
( V_26 -> V_33 . V_30 [ V_34 ] ) ) {
V_34 ++ ;
}
V_8 = F_14 ( V_34 ) ;
if ( ! V_8 ) {
return ( V_35 ) ;
}
F_16 ( V_8 -> string . V_30 ,
V_26 -> V_33 . V_30 , V_34 ) ;
break;
default:
return ( V_19 ) ;
}
* V_7 = V_8 ;
return ( V_18 ) ;
}
static T_1
F_6 ( union V_5 * V_26 ,
union V_5 * * V_7 )
{
union V_5 * V_8 ;
T_1 V_9 ;
union V_5 * * V_38 ;
T_2 * V_39 ;
T_2 V_40 ;
T_2 V_28 ;
switch ( V_26 -> V_22 . type ) {
case V_36 :
V_9 =
F_17 ( V_26 , & V_8 ) ;
if ( F_12 ( V_9 ) ) {
return ( V_9 ) ;
}
break;
case V_29 :
V_8 =
F_18 ( V_26 -> string .
V_34 ) ;
if ( ! V_8 ) {
return ( V_35 ) ;
}
F_16 ( V_8 -> V_33 . V_30 ,
V_26 -> string . V_30 ,
V_26 -> string . V_34 ) ;
break;
case V_41 :
V_38 = V_26 -> V_42 . V_38 ;
V_40 = V_26 -> V_42 . V_40 ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
if ( ( ! * V_38 ) ||
( ( * V_38 ) -> V_22 . type != V_36 ) ) {
return ( V_19 ) ;
}
V_38 ++ ;
}
V_8 = F_18 ( F_19 ( V_40 ) ) ;
if ( ! V_8 ) {
return ( V_35 ) ;
}
V_38 = V_26 -> V_42 . V_38 ;
V_39 = F_20 ( T_2 , V_8 -> V_33 . V_30 ) ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
* V_39 = ( T_2 ) ( * V_38 ) -> integer . V_27 ;
V_39 ++ ;
V_38 ++ ;
}
break;
default:
return ( V_19 ) ;
}
* V_7 = V_8 ;
return ( V_18 ) ;
}
T_1
F_21 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_2 V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
union V_5 * V_8 ;
F_2 ( V_43 ) ;
if ( V_7 ) {
return ( V_18 ) ;
}
if ( V_3 & V_11 ) {
V_8 = F_13 ( ( T_3 ) 0 ) ;
} else if ( V_3 & V_13 ) {
V_8 = F_14 ( 0 ) ;
} else if ( V_3 & V_14 ) {
V_8 = F_18 ( 0 ) ;
} else {
return ( V_19 ) ;
}
if ( ! V_8 ) {
return ( V_35 ) ;
}
V_8 -> V_22 . V_23 =
V_2 -> V_44 -> V_22 . V_23 ;
F_8 ( ( V_24 ,
L_3 ,
V_2 -> V_25 ,
F_9 ( V_8 ) ,
V_4 ) ) ;
* V_6 = V_8 ;
V_2 -> V_16 |= V_17 ;
return ( V_18 ) ;
}
void
F_22 ( struct V_1 * V_2 ,
T_5 V_45 ,
union V_5 * V_46 )
{
union V_5 * * V_47 ;
union V_5 * * V_48 ;
T_2 V_40 ;
T_2 V_49 ;
T_2 V_28 ;
F_2 ( V_50 ) ;
switch ( V_45 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
break;
default:
case V_59 :
case V_60 :
return;
}
V_40 = V_46 -> V_42 . V_40 ;
V_49 = V_40 ;
V_47 = V_46 -> V_42 . V_38 ;
V_48 = V_47 ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
if ( ! * V_47 ) {
V_49 -- ;
} else {
* V_48 = * V_47 ;
V_48 ++ ;
}
V_47 ++ ;
}
if ( V_49 < V_40 ) {
F_8 ( ( V_24 ,
L_4 ,
V_2 -> V_25 , ( V_40 - V_49 ) ) ) ;
* V_48 = NULL ;
V_46 -> V_42 . V_40 = V_49 ;
}
}
T_1
F_7 ( struct V_1 * V_2 ,
union V_5 * V_26 ,
union V_5 * * V_61 )
{
union V_5 * V_62 ;
F_2 ( V_63 ) ;
V_62 = F_23 ( 1 ) ;
if ( ! V_62 ) {
return ( V_35 ) ;
}
V_62 -> V_42 . V_38 [ 0 ] = V_26 ;
F_8 ( ( V_24 ,
L_5 ,
V_2 -> V_25 ,
F_9 ( V_26 ) ) ) ;
* V_61 = V_62 ;
V_2 -> V_16 |= V_17 | V_21 ;
return ( V_18 ) ;
}
