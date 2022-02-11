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
T_3 V_16 ;
T_1 V_17 ;
F_6 ( V_18 ) ;
V_17 = F_1 ( V_2 , 32 , & V_4 ) ;
if ( F_7 ( V_17 ) ) {
return ( V_17 ) ;
}
* V_15 = 0 ;
if ( V_2 -> V_7 == V_8 ) {
V_17 = F_8 ( ( V_19 )
V_4 , & V_16 , V_2 -> V_12 ) ;
* V_15 = ( T_4 ) V_16 ;
} else {
V_17 = F_9 ( ( V_20 )
V_4 , V_15 , V_2 -> V_12 ) ;
}
F_10 ( ( V_21 ,
L_4 ,
* V_15 , V_2 -> V_12 , F_11 ( V_4 ) ,
F_12 ( V_2 -> V_7 ) ) ) ;
return ( V_17 ) ;
}
T_1 F_13 ( T_4 V_15 , struct V_1 * V_2 )
{
T_3 V_4 ;
T_1 V_17 ;
F_6 ( V_22 ) ;
V_17 = F_1 ( V_2 , 32 , & V_4 ) ;
if ( F_7 ( V_17 ) ) {
return ( V_17 ) ;
}
if ( V_2 -> V_7 == V_8 ) {
V_17 = F_14 ( ( V_19 )
V_4 , ( T_3 ) V_15 ,
V_2 -> V_12 ) ;
} else {
V_17 = F_15 ( ( V_20 )
V_4 , V_15 , V_2 -> V_12 ) ;
}
F_10 ( ( V_21 ,
L_5 ,
V_15 , V_2 -> V_12 , F_11 ( V_4 ) ,
F_12 ( V_2 -> V_7 ) ) ) ;
return ( V_17 ) ;
}
T_1 F_16 ( void )
{
T_1 V_17 ;
T_5 V_23 = 0 ;
F_17 ( V_24 ) ;
F_10 ( ( V_21 , L_6 ,
V_25 ,
F_11 ( V_26 . V_4 ) ) ) ;
V_23 = F_18 ( V_27 ) ;
V_17 = F_19 ( V_28 ,
V_25 ) ;
F_20 ( V_27 , V_23 ) ;
if ( F_7 ( V_17 ) )
goto exit;
V_17 = F_21 ( V_29 , NULL ) ;
exit:
F_22 ( V_17 ) ;
}
struct V_30 * F_23 ( T_4 V_31 )
{
F_24 () ;
if ( V_31 > V_32 ) {
F_3 ( ( V_10 , L_7 ,
V_31 ) ) ;
return ( NULL ) ;
}
return ( & V_33 [ V_31 ] ) ;
}
T_1 F_25 ( T_4 V_34 , T_4 V_35 )
{
T_1 V_17 ;
F_17 ( V_36 ) ;
V_17 =
F_13 ( V_34 , & V_37 . V_38 ) ;
if ( F_7 ( V_17 ) ) {
F_22 ( V_17 ) ;
}
if ( V_37 . V_39 . V_4 ) {
V_17 =
F_13 ( V_35 ,
& V_37 . V_39 ) ;
}
F_22 ( V_17 ) ;
}
T_1 F_26 ( T_4 V_31 , T_4 * V_40 )
{
T_4 V_15 = 0 ;
T_1 V_17 ;
F_17 ( V_41 ) ;
switch ( V_31 ) {
case V_28 :
V_17 = F_27 ( & V_15 ,
& V_26 ,
& V_42 ) ;
break;
case V_43 :
V_17 = F_27 ( & V_15 ,
& V_44 ,
& V_45 ) ;
break;
case V_46 :
V_17 = F_27 ( & V_15 ,
& V_37 .
V_38 ,
& V_37 .
V_39 ) ;
V_15 &= ~ V_47 ;
break;
case V_48 :
V_17 =
F_5 ( & V_15 , & V_37 . V_49 ) ;
break;
case V_50 :
V_17 = F_5 ( & V_15 , & V_37 . V_51 ) ;
break;
case V_52 :
V_17 =
F_9 ( V_37 . V_53 , & V_15 , 8 ) ;
break;
default:
F_3 ( ( V_10 , L_8 , V_31 ) ) ;
V_17 = V_5 ;
break;
}
if ( F_28 ( V_17 ) ) {
* V_40 = V_15 ;
}
F_22 ( V_17 ) ;
}
T_1 F_19 ( T_4 V_31 , T_4 V_15 )
{
T_1 V_17 ;
T_4 V_54 ;
F_17 ( V_55 ) ;
switch ( V_31 ) {
case V_28 :
V_15 &= ~ V_56 ;
V_17 = F_29 ( V_15 ,
& V_26 ,
& V_42 ) ;
break;
case V_43 :
V_17 = F_29 ( V_15 ,
& V_44 ,
& V_45 ) ;
break;
case V_46 :
V_17 = F_27 ( & V_54 ,
& V_37 .
V_38 ,
& V_37 .
V_39 ) ;
if ( F_7 ( V_17 ) ) {
goto exit;
}
F_30 ( V_15 , V_57 ,
V_54 ) ;
V_17 = F_29 ( V_15 ,
& V_37 .
V_38 ,
& V_37 .
V_39 ) ;
break;
case V_48 :
V_17 =
F_5 ( & V_54 ,
& V_37 . V_49 ) ;
if ( F_7 ( V_17 ) ) {
goto exit;
}
F_30 ( V_15 , V_58 ,
V_54 ) ;
V_17 =
F_13 ( V_15 , & V_37 . V_49 ) ;
break;
case V_50 :
V_17 = F_13 ( V_15 , & V_37 . V_51 ) ;
break;
case V_52 :
V_17 =
F_15 ( V_37 . V_53 , V_15 , 8 ) ;
break;
default:
F_3 ( ( V_10 , L_8 , V_31 ) ) ;
V_17 = V_5 ;
break;
}
exit:
F_22 ( V_17 ) ;
}
static T_1
F_27 ( T_4 * V_15 ,
struct V_1 * V_59 ,
struct V_1 * V_60 )
{
T_4 V_61 = 0 ;
T_4 V_62 = 0 ;
T_1 V_17 ;
V_17 = F_5 ( & V_61 , V_59 ) ;
if ( F_7 ( V_17 ) ) {
return ( V_17 ) ;
}
if ( V_60 -> V_4 ) {
V_17 = F_5 ( & V_62 , V_60 ) ;
if ( F_7 ( V_17 ) ) {
return ( V_17 ) ;
}
}
* V_15 = ( V_61 | V_62 ) ;
return ( V_14 ) ;
}
static T_1
F_29 ( T_4 V_15 ,
struct V_1 * V_59 ,
struct V_1 * V_60 )
{
T_1 V_17 ;
V_17 = F_13 ( V_15 , V_59 ) ;
if ( F_7 ( V_17 ) ) {
return ( V_17 ) ;
}
if ( V_60 -> V_4 ) {
V_17 = F_13 ( V_15 , V_60 ) ;
}
return ( V_17 ) ;
}
