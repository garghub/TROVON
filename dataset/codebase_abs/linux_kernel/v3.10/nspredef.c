T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_4 ,
union V_5 * * V_6 )
{
T_1 V_7 = V_8 ;
const union V_9 * V_10 ;
char * V_11 ;
struct V_12 * V_13 ;
V_10 = F_2 ( V_2 -> V_14 . V_15 ) ;
V_11 = F_3 ( V_2 ) ;
if ( ! V_11 ) {
return ( V_8 ) ;
}
F_4 ( V_11 , V_2 , V_3 ,
V_10 ) ;
if ( ! V_10 ) {
goto V_16;
}
if ( ( V_4 != V_8 ) && ( V_4 != V_17 ) ) {
goto V_16;
}
if ( V_18 ||
( ! V_10 -> V_19 . V_20 ) ||
( V_10 -> V_19 . V_20 == V_21 ) ) {
goto V_16;
}
V_13 = F_5 ( sizeof( struct V_12 ) ) ;
if ( ! V_13 ) {
goto V_16;
}
V_13 -> V_10 = V_10 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_22 = V_2 -> V_23 ;
V_13 -> V_11 = V_11 ;
V_7 = F_6 ( V_13 , V_6 ,
V_10 -> V_19 . V_20 ,
V_24 ) ;
if ( F_7 ( V_7 ) ) {
goto exit;
}
if ( ( * V_6 ) -> V_25 . type == V_26 ) {
V_13 -> V_27 = * V_6 ;
V_7 = F_8 ( V_13 , V_6 ) ;
if ( F_7 ( V_7 ) ) {
goto exit;
}
}
V_7 = F_9 ( V_13 , V_2 , V_7 , V_6 ) ;
exit:
if ( F_7 ( V_7 ) || ( V_13 -> V_23 & V_28 ) ) {
V_2 -> V_23 |= V_29 ;
}
F_10 ( V_13 ) ;
V_16:
F_10 ( V_11 ) ;
return ( V_7 ) ;
}
void
F_4 ( char * V_11 ,
struct V_1 * V_2 ,
T_2 V_3 ,
const union V_9 * V_10 )
{
T_2 V_30 ;
T_2 V_31 ;
T_2 V_32 ;
V_30 = 0 ;
if ( V_2 -> type == V_33 ) {
V_30 = V_2 -> V_34 -> V_35 . V_30 ;
}
if ( ! V_10 ) {
if ( V_3 < V_30 ) {
F_11 ( ( V_36 , V_11 ,
V_37 ,
L_1 ,
V_30 , V_3 ) ) ;
} else if ( V_3 > V_30 ) {
F_11 ( ( V_36 , V_11 ,
V_37 ,
L_2 ,
V_30 , V_3 ) ) ;
}
return;
}
V_31 =
V_10 -> V_19 . V_38 & V_39 ;
V_32 =
V_10 -> V_19 . V_38 >> V_40 ;
if ( V_3 != V_41 ) {
if ( ( V_3 != V_31 ) &&
( V_3 != V_32 ) ) {
F_11 ( ( V_36 , V_11 ,
V_37 ,
L_3
L_4 ,
V_3 ,
V_31 ) ) ;
}
}
if ( ( V_30 != V_31 ) &&
( V_30 != V_32 ) ) {
F_11 ( ( V_36 , V_11 , V_2 -> V_23 ,
L_5 ,
V_30 , V_31 ) ) ;
}
}
T_1
F_6 ( struct V_12 * V_13 ,
union V_5 * * V_6 ,
T_2 V_20 , T_2 V_42 )
{
union V_5 * V_43 = * V_6 ;
T_1 V_7 = V_8 ;
char V_44 [ 48 ] ;
if ( V_43 &&
F_12 ( V_43 ) == V_45 ) {
F_11 ( ( V_36 , V_13 -> V_11 , V_13 -> V_22 ,
L_6 ,
V_43 -> V_2 . V_14 . V_15 ,
F_13 ( V_43 -> V_2 .
type ) ) ) ;
return ( V_46 ) ;
}
V_13 -> V_47 = F_14 ( V_43 ) ;
if ( V_13 -> V_47 == V_48 ) {
goto V_49;
}
if ( ( V_13 -> V_47 & V_20 ) == V_50 ) {
V_7 = F_15 ( V_13 , V_43 ) ;
return ( V_7 ) ;
}
V_7 = F_16 ( V_13 , V_20 ,
V_42 , V_6 ) ;
return ( V_7 ) ;
V_49:
F_17 ( V_44 , V_20 ) ;
if ( V_42 == V_24 ) {
F_11 ( ( V_36 , V_13 -> V_11 , V_13 -> V_22 ,
L_7 ,
F_18
( V_43 ) , V_44 ) ) ;
} else {
F_11 ( ( V_36 , V_13 -> V_11 , V_13 -> V_22 ,
L_8
L_9 , V_42 ,
F_18
( V_43 ) , V_44 ) ) ;
}
return ( V_46 ) ;
}
static T_1
F_15 ( struct V_12 * V_13 ,
union V_5 * V_43 )
{
if ( V_43 -> V_51 . V_52 == V_53 ) {
return ( V_8 ) ;
}
F_11 ( ( V_36 , V_13 -> V_11 , V_13 -> V_22 ,
L_10 ,
F_19 ( V_43 ) ,
V_43 -> V_51 . V_52 ) ) ;
return ( V_46 ) ;
}
static T_2 F_14 ( union V_5 * V_43 )
{
T_2 V_47 ;
if ( ! V_43 ) {
return ( V_54 ) ;
}
switch ( V_43 -> V_25 . type ) {
case V_55 :
V_47 = V_56 ;
break;
case V_57 :
V_47 = V_58 ;
break;
case V_59 :
V_47 = V_60 ;
break;
case V_26 :
V_47 = V_61 ;
break;
case V_62 :
V_47 = V_50 ;
break;
default:
V_47 = V_48 ;
break;
}
return ( V_47 ) ;
}
