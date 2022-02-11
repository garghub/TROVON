T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
if ( ! V_2 ) {
return ( V_5 ) ;
}
F_2 ( V_4 , & V_2 -> V_4 ) ;
if ( ! ( * V_4 ) ) {
return ( V_6 ) ;
}
if ( ( V_2 -> V_7 != V_8 ) &&
( V_2 -> V_7 != V_9 ) ) {
F_3 ( ( V_10 ,
L_1 , V_2 -> V_7 ) ) ;
return ( V_11 ) ;
}
if ( ( V_2 -> V_12 != 8 ) &&
( V_2 -> V_12 != 16 ) &&
( V_2 -> V_12 != 32 ) && ( V_2 -> V_12 != V_3 ) ) {
F_3 ( ( V_10 ,
L_2 ,
V_2 -> V_12 ) ) ;
return ( V_11 ) ;
}
if ( V_2 -> V_13 != 0 ) {
F_4 ( ( V_10 ,
L_3 ,
V_2 -> V_13 ) ) ;
}
return ( V_14 ) ;
}
T_1 F_5 ( T_4 * V_15 , struct V_1 * V_2 )
{
T_3 V_4 ;
T_1 V_16 ;
F_6 ( V_17 ) ;
V_16 = F_1 ( V_2 , 32 , & V_4 ) ;
if ( F_7 ( V_16 ) ) {
return ( V_16 ) ;
}
* V_15 = 0 ;
if ( V_2 -> V_7 == V_8 ) {
V_16 = F_8 ( ( V_18 )
V_4 , V_15 , V_2 -> V_12 ) ;
} else {
V_16 = F_9 ( ( V_19 )
V_4 , V_15 , V_2 -> V_12 ) ;
}
F_10 ( ( V_20 ,
L_4 ,
* V_15 , V_2 -> V_12 , F_11 ( V_4 ) ,
F_12 ( V_2 -> V_7 ) ) ) ;
return ( V_16 ) ;
}
T_1 F_13 ( T_4 V_15 , struct V_1 * V_2 )
{
T_3 V_4 ;
T_1 V_16 ;
F_6 ( V_21 ) ;
V_16 = F_1 ( V_2 , 32 , & V_4 ) ;
if ( F_7 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_2 -> V_7 == V_8 ) {
V_16 = F_14 ( ( V_18 )
V_4 , V_15 , V_2 -> V_12 ) ;
} else {
V_16 = F_15 ( ( V_19 )
V_4 , V_15 , V_2 -> V_12 ) ;
}
F_10 ( ( V_20 ,
L_5 ,
V_15 , V_2 -> V_12 , F_11 ( V_4 ) ,
F_12 ( V_2 -> V_7 ) ) ) ;
return ( V_16 ) ;
}
T_1 F_16 ( void )
{
T_1 V_16 ;
T_5 V_22 = 0 ;
F_17 ( V_23 ) ;
F_10 ( ( V_20 , L_6 ,
V_24 ,
F_11 ( V_25 . V_4 ) ) ) ;
V_22 = F_18 ( V_26 ) ;
V_16 = F_19 ( V_27 ,
V_24 ) ;
F_20 ( V_26 , V_22 ) ;
if ( F_7 ( V_16 ) )
goto exit;
V_16 = F_21 ( V_28 , NULL ) ;
exit:
F_22 ( V_16 ) ;
}
struct V_29 * F_23 ( T_4 V_30 )
{
F_24 () ;
if ( V_30 > V_31 ) {
F_3 ( ( V_10 , L_7 ,
V_30 ) ) ;
return ( NULL ) ;
}
return ( & V_32 [ V_30 ] ) ;
}
T_1 F_25 ( T_4 V_33 , T_4 V_34 )
{
T_1 V_16 ;
F_17 ( V_35 ) ;
V_16 =
F_13 ( V_33 , & V_36 . V_37 ) ;
if ( F_7 ( V_16 ) ) {
F_22 ( V_16 ) ;
}
if ( V_36 . V_38 . V_4 ) {
V_16 =
F_13 ( V_34 ,
& V_36 . V_38 ) ;
}
F_22 ( V_16 ) ;
}
T_1
F_26 ( T_4 V_30 , T_4 * V_39 )
{
T_4 V_15 = 0 ;
T_1 V_16 ;
F_17 ( V_40 ) ;
switch ( V_30 ) {
case V_27 :
V_16 = F_27 ( & V_15 ,
& V_25 ,
& V_41 ) ;
break;
case V_42 :
V_16 = F_27 ( & V_15 ,
& V_43 ,
& V_44 ) ;
break;
case V_45 :
V_16 = F_27 ( & V_15 ,
& V_36 .
V_37 ,
& V_36 .
V_38 ) ;
V_15 &= ~ V_46 ;
break;
case V_47 :
V_16 =
F_5 ( & V_15 , & V_36 . V_48 ) ;
break;
case V_49 :
V_16 = F_5 ( & V_15 , & V_36 . V_50 ) ;
break;
case V_51 :
V_16 =
F_9 ( V_36 . V_52 , & V_15 , 8 ) ;
break;
default:
F_3 ( ( V_10 , L_8 , V_30 ) ) ;
V_16 = V_5 ;
break;
}
if ( F_28 ( V_16 ) ) {
* V_39 = V_15 ;
}
F_22 ( V_16 ) ;
}
T_1 F_19 ( T_4 V_30 , T_4 V_15 )
{
T_1 V_16 ;
T_4 V_53 ;
F_17 ( V_54 ) ;
switch ( V_30 ) {
case V_27 :
V_15 &= ~ V_55 ;
V_16 = F_29 ( V_15 ,
& V_25 ,
& V_41 ) ;
break;
case V_42 :
V_16 = F_29 ( V_15 ,
& V_43 ,
& V_44 ) ;
break;
case V_45 :
V_16 = F_27 ( & V_53 ,
& V_36 .
V_37 ,
& V_36 .
V_38 ) ;
if ( F_7 ( V_16 ) ) {
goto exit;
}
F_30 ( V_15 , V_56 ,
V_53 ) ;
V_16 = F_29 ( V_15 ,
& V_36 .
V_37 ,
& V_36 .
V_38 ) ;
break;
case V_47 :
V_16 =
F_5 ( & V_53 ,
& V_36 . V_48 ) ;
if ( F_7 ( V_16 ) ) {
goto exit;
}
F_30 ( V_15 , V_57 ,
V_53 ) ;
V_16 =
F_13 ( V_15 , & V_36 . V_48 ) ;
break;
case V_49 :
V_16 = F_13 ( V_15 , & V_36 . V_50 ) ;
break;
case V_51 :
V_16 =
F_15 ( V_36 . V_52 , V_15 , 8 ) ;
break;
default:
F_3 ( ( V_10 , L_8 , V_30 ) ) ;
V_16 = V_5 ;
break;
}
exit:
F_22 ( V_16 ) ;
}
static T_1
F_27 ( T_4 * V_15 ,
struct V_1 * V_58 ,
struct V_1 * V_59 )
{
T_4 V_60 = 0 ;
T_4 V_61 = 0 ;
T_1 V_16 ;
V_16 = F_5 ( & V_60 , V_58 ) ;
if ( F_7 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_59 -> V_4 ) {
V_16 = F_5 ( & V_61 , V_59 ) ;
if ( F_7 ( V_16 ) ) {
return ( V_16 ) ;
}
}
* V_15 = ( V_60 | V_61 ) ;
return ( V_14 ) ;
}
static T_1
F_29 ( T_4 V_15 ,
struct V_1 * V_58 ,
struct V_1 * V_59 )
{
T_1 V_16 ;
V_16 = F_13 ( V_15 , V_58 ) ;
if ( F_7 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_59 -> V_4 ) {
V_16 = F_13 ( V_15 , V_59 ) ;
}
return ( V_16 ) ;
}
