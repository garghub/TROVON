T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
T_1 V_8 = V_9 ;
const union V_10 * V_11 ;
char * V_12 ;
struct V_13 * V_14 ;
V_11 = F_2 ( V_2 ) ;
V_12 = F_3 ( V_2 ) ;
if ( ! V_12 ) {
return ( V_9 ) ;
}
F_4 ( V_12 , V_2 , V_3 ,
V_11 ) ;
if ( ! V_11 ) {
goto V_15;
}
if ( ( V_4 != V_9 ) && ( V_4 != V_16 ) ) {
goto V_15;
}
if ( ! V_7 ) {
if ( ( V_11 -> V_17 . V_18 ) &&
( ! ( V_11 -> V_17 . V_18 & V_19 ) ) ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_1 ) ) ;
V_8 = V_22 ;
}
goto V_15;
}
if ( V_23 ||
( ! V_11 -> V_17 . V_18 ) ||
( V_11 -> V_17 . V_18 == V_24 ) ) {
goto V_15;
}
V_14 = F_6 ( sizeof( struct V_13 ) ) ;
if ( ! V_14 ) {
goto V_15;
}
V_14 -> V_11 = V_11 ;
V_14 -> V_2 = V_2 ;
V_14 -> V_25 = V_2 -> V_26 ;
V_14 -> V_12 = V_12 ;
V_8 = F_7 ( V_14 , V_6 ,
V_11 -> V_17 . V_18 ,
V_27 ) ;
if ( F_8 ( V_8 ) ) {
goto exit;
}
if ( ( * V_6 ) -> V_28 . type == V_29 ) {
V_14 -> V_30 = * V_6 ;
V_8 = F_9 ( V_14 , V_6 ) ;
if ( F_8 ( V_8 ) ) {
goto exit;
}
}
V_8 = F_10 ( V_14 , V_2 , V_8 , V_6 ) ;
exit:
if ( F_8 ( V_8 ) || ( V_14 -> V_26 & V_31 ) ) {
V_2 -> V_26 |= V_32 ;
}
F_11 ( V_14 ) ;
V_15:
F_11 ( V_12 ) ;
return ( V_8 ) ;
}
void
F_4 ( char * V_12 ,
struct V_1 * V_2 ,
T_2 V_3 ,
const union V_10 * V_11 )
{
T_2 V_33 ;
T_2 V_34 ;
T_2 V_35 ;
V_33 = 0 ;
if ( V_2 -> type == V_36 ) {
V_33 = V_2 -> V_37 -> V_38 . V_33 ;
}
if ( ! V_11 ) {
if ( V_3 < V_33 ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_2 ,
V_33 , V_3 ) ) ;
} else if ( V_3 > V_33 ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_3 ,
V_33 , V_3 ) ) ;
}
return;
}
V_34 = V_11 -> V_17 . V_33 & 0x0F ;
V_35 = V_11 -> V_17 . V_33 >> 4 ;
if ( V_3 != V_39 ) {
if ( ( V_3 != V_34 ) &&
( V_3 != V_35 ) ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_4
L_5 ,
V_3 ,
V_34 ) ) ;
}
}
if ( ( V_33 != V_34 ) &&
( V_33 != V_35 ) ) {
F_5 ( ( V_20 , V_12 , V_2 -> V_26 ,
L_6 ,
V_33 , V_34 ) ) ;
}
}
const union V_10 * F_2 ( struct
V_1
* V_2 )
{
const union V_10 * V_40 ;
if ( V_2 -> V_41 . V_42 [ 0 ] != '_' ) {
return ( NULL ) ;
}
V_40 = V_43 ;
while ( V_40 -> V_17 . V_41 [ 0 ] ) {
if ( F_12 ( V_2 -> V_41 . V_42 , V_40 -> V_17 . V_41 ) ) {
return ( V_40 ) ;
}
if ( V_40 -> V_17 . V_18 & V_44 ) {
V_40 ++ ;
}
V_40 ++ ;
}
return ( NULL ) ;
}
T_1
F_7 ( struct V_13 * V_14 ,
union V_5 * * V_6 ,
T_2 V_18 , T_2 V_45 )
{
union V_5 * V_7 = * V_6 ;
T_1 V_8 = V_9 ;
T_2 V_46 ;
char V_47 [ 48 ] ;
if ( ! V_7 ) {
V_8 = F_13 ( V_14 , V_18 ,
V_45 ,
V_6 ) ;
if ( F_14 ( V_8 ) ) {
return ( V_9 ) ;
}
goto V_48;
}
if ( F_15 ( V_7 ) == V_49 ) {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_7 ,
V_7 -> V_2 . V_41 . V_42 ,
F_16 ( V_7 -> V_2 .
type ) ) ) ;
return ( V_50 ) ;
}
switch ( V_7 -> V_28 . type ) {
case V_51 :
V_46 = V_52 ;
break;
case V_53 :
V_46 = V_54 ;
break;
case V_55 :
V_46 = V_56 ;
break;
case V_29 :
V_46 = V_44 ;
break;
case V_57 :
V_46 = V_58 ;
break;
default:
goto V_48;
}
if ( V_46 & V_18 ) {
if ( V_7 -> V_28 . type == V_57 ) {
V_8 = F_17 ( V_14 , V_7 ) ;
}
return ( V_8 ) ;
}
V_8 = F_18 ( V_14 , V_18 ,
V_45 , V_6 ) ;
if ( F_14 ( V_8 ) ) {
return ( V_9 ) ;
}
V_48:
F_19 ( V_47 , V_18 ) ;
if ( V_45 == V_27 ) {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_8 ,
F_20
( V_7 ) , V_47 ) ) ;
} else {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_9
L_10 , V_45 ,
F_20
( V_7 ) , V_47 ) ) ;
}
return ( V_50 ) ;
}
static T_1
F_17 ( struct V_13 * V_14 ,
union V_5 * V_7 )
{
if ( V_7 -> V_59 . V_60 == V_61 ) {
return ( V_9 ) ;
}
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_11 ,
F_21 ( V_7 ) ,
V_7 -> V_59 . V_60 ) ) ;
return ( V_50 ) ;
}
static void F_19 ( char * V_62 , T_2 V_18 )
{
T_2 V_63 ;
T_2 V_64 ;
T_2 V_65 ;
V_65 = 1 ;
V_62 [ 0 ] = 0 ;
V_63 = V_52 ;
for ( V_64 = 0 ; V_64 < V_66 ; V_64 ++ ) {
if ( V_18 & V_63 ) {
F_22 ( V_62 , & V_67 [ V_64 ] [ V_65 ] ) ;
V_65 = 0 ;
}
V_63 <<= 1 ;
}
}
