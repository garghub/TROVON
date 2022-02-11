T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_2 V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
union V_5 * V_8 = NULL ;
T_1 V_9 ;
const struct V_10 * V_11 ;
F_2 ( V_12 ) ;
V_11 = F_3 ( V_2 -> V_13 ,
V_2 -> V_14 ,
V_4 ) ;
if ( V_11 ) {
if ( ! V_7 ) {
F_4 ( ( V_15 , V_2 -> V_16 ,
V_17 ,
L_1 ) ) ;
}
V_9 = V_11 -> V_18 ( V_2 -> V_13 , V_7 ,
& V_8 ) ;
if ( F_5 ( V_9 ) ) {
F_6 ( ( V_15 , V_9 ,
L_2 ) ) ;
return ( V_9 ) ;
}
if ( V_8 ) {
goto V_19;
}
}
if ( V_2 -> V_14 & V_3 ) {
return ( V_20 ) ;
}
if ( ! V_7 ) {
if ( V_3 && ( ! ( V_3 & V_21 ) ) ) {
if ( V_4 != V_22 ) {
F_4 ( ( V_15 ,
V_2 -> V_16 ,
V_17 ,
L_3 ) ) ;
V_9 =
F_7 ( V_2 ,
V_3 ,
V_4 ,
V_6 ) ;
if ( F_8 ( V_9 ) ) {
return ( V_20 ) ;
}
} else {
F_4 ( ( V_15 ,
V_2 -> V_16 ,
V_17 ,
L_1 ) ) ;
}
return ( V_23 ) ;
}
}
if ( V_3 & V_24 ) {
V_9 = F_9 ( V_7 , & V_8 ) ;
if ( F_8 ( V_9 ) ) {
goto V_19;
}
}
if ( V_3 & V_25 ) {
V_9 = F_10 ( V_7 , & V_8 ) ;
if ( F_8 ( V_9 ) ) {
goto V_19;
}
}
if ( V_3 & V_26 ) {
V_9 = F_11 ( V_7 , & V_8 ) ;
if ( F_8 ( V_9 ) ) {
goto V_19;
}
}
if ( V_3 & V_27 ) {
V_9 =
F_12 ( V_2 , V_7 , & V_8 ) ;
if ( F_8 ( V_9 ) ) {
* V_6 = V_8 ;
V_2 -> V_28 |= V_29 ;
return ( V_20 ) ;
}
}
return ( V_30 ) ;
V_19:
if ( V_4 != V_22 ) {
if ( ! ( V_2 -> V_28 & V_31 ) ) {
V_8 -> V_32 . V_33 =
V_7 -> V_32 . V_33 ;
}
F_13 ( ( V_34 ,
L_4 ,
V_2 -> V_16 ,
F_14 ( V_7 ) ,
F_14 ( V_8 ) ,
V_4 ) ) ;
} else {
F_13 ( ( V_34 ,
L_5 ,
V_2 -> V_16 ,
F_14 ( V_7 ) ,
F_14 ( V_8 ) ) ) ;
}
F_15 ( V_7 ) ;
* V_6 = V_8 ;
V_2 -> V_28 |= V_29 ;
return ( V_20 ) ;
}
static const struct V_10 * F_3 ( struct
V_35
* V_13 ,
T_2
V_14 ,
T_2
V_4 )
{
const struct V_10 * V_36 ;
V_36 = V_37 ;
while ( V_36 -> V_18 ) {
if ( F_16 ( V_13 -> V_38 . V_39 , V_36 -> V_38 ) ) {
if ( ( V_14 & V_36 -> V_40 ) &&
( V_36 -> V_4 ==
V_41
|| V_4 == V_36 -> V_4 ) ) {
return ( V_36 ) ;
}
return ( NULL ) ;
}
V_36 ++ ;
}
return ( NULL ) ;
}
T_1
F_7 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_2 V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
union V_5 * V_8 ;
F_2 ( V_42 ) ;
if ( V_7 ) {
return ( V_20 ) ;
}
if ( V_3 & V_24 ) {
V_8 = F_17 ( ( V_43 ) 0 ) ;
} else if ( V_3 & V_25 ) {
V_8 = F_18 ( 0 ) ;
} else if ( V_3 & V_26 ) {
V_8 = F_19 ( 0 ) ;
} else {
return ( V_30 ) ;
}
if ( ! V_8 ) {
return ( V_44 ) ;
}
V_8 -> V_32 . V_33 =
V_2 -> V_45 -> V_32 . V_33 ;
F_13 ( ( V_34 ,
L_6 ,
V_2 -> V_16 ,
F_14 ( V_8 ) ,
V_4 ) ) ;
* V_6 = V_8 ;
V_2 -> V_28 |= V_29 ;
return ( V_20 ) ;
}
void
F_20 ( struct V_1 * V_2 ,
T_3 V_46 ,
union V_5 * V_47 )
{
union V_5 * * V_48 ;
union V_5 * * V_49 ;
T_2 V_50 ;
T_2 V_51 ;
T_2 V_52 ;
F_2 ( V_53 ) ;
switch ( V_46 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
break;
default:
case V_62 :
case V_63 :
case V_64 :
return;
}
V_50 = V_47 -> V_65 . V_50 ;
V_51 = V_50 ;
V_48 = V_47 -> V_65 . V_66 ;
V_49 = V_48 ;
for ( V_52 = 0 ; V_52 < V_50 ; V_52 ++ ) {
if ( ! * V_48 ) {
V_51 -- ;
} else {
* V_49 = * V_48 ;
V_49 ++ ;
}
V_48 ++ ;
}
if ( V_51 < V_50 ) {
F_13 ( ( V_34 ,
L_7 ,
V_2 -> V_16 , ( V_50 - V_51 ) ) ) ;
* V_49 = NULL ;
V_47 -> V_65 . V_50 = V_51 ;
}
}
T_1
F_12 ( struct V_1 * V_2 ,
union V_5 * V_67 ,
union V_5 * * V_68 )
{
union V_5 * V_69 ;
F_2 ( V_70 ) ;
V_69 = F_21 ( 1 ) ;
if ( ! V_69 ) {
return ( V_44 ) ;
}
V_69 -> V_65 . V_66 [ 0 ] = V_67 ;
F_13 ( ( V_34 ,
L_8 ,
V_2 -> V_16 ,
F_14 ( V_67 ) ) ) ;
* V_68 = V_69 ;
V_2 -> V_28 |= V_29 | V_31 ;
return ( V_20 ) ;
}
