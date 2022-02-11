static int F_1 ( unsigned long V_1 , T_1 * V_2 )
{
switch ( V_1 ) {
case 9600 * V_3 :
* V_2 = V_4 ;
break;
case 10 * V_5 :
* V_2 = V_6 ;
break;
case 12 * V_5 :
* V_2 = V_7 ;
break;
case 19200 * V_3 :
* V_2 = V_8 ;
break;
case 20 * V_5 :
* V_2 = V_9 ;
break;
case 24 * V_5 :
* V_2 = V_10 ;
break;
case 50 * V_5 :
* V_2 = V_11 ;
break;
default:
return - V_12 ;
}
return 0 ;
}
static void F_2 ( struct V_13 * V_14 , bool V_15 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
T_1 V_18 ;
T_1 V_19 ;
switch ( V_14 -> V_20 -> V_21 ) {
case V_22 :
case V_23 :
V_18 = V_24 ;
V_19 = V_25 ;
break;
case V_26 :
V_18 = V_27 ;
V_19 = V_28 ;
break;
case V_29 :
V_18 = V_30 ;
V_19 = V_31 ;
break;
default:
return;
}
F_3 ( V_17 -> V_32 , V_18 , V_19 , V_15 ? 0 : V_19 ) ;
}
static void F_4 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
T_1 V_33 ;
V_33 = F_5 ( V_17 -> V_34 + V_35 ) ;
V_33 &= ~ V_36 ;
if ( V_17 -> V_20 -> V_37 )
V_33 = V_38 ;
V_33 |= V_17 -> V_39 << V_40 ;
V_33 |= V_41 ;
F_6 ( V_33 , V_17 -> V_34 + V_35 ) ;
}
static void F_7 ( struct V_13 * V_14 , bool V_15 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
T_1 V_42 = 0 ;
T_1 V_43 = 0 ;
T_1 V_44 ;
T_1 V_45 ;
switch ( V_14 -> V_20 -> V_21 ) {
case V_22 :
V_43 = V_46 ;
V_42 = V_47 ;
break;
case V_23 :
V_43 = V_48 ;
V_42 = V_49 |
V_50 |
V_51 ;
break;
case V_26 :
V_43 = V_52 ;
V_42 = V_53 |
V_54 ;
break;
case V_29 :
V_43 = V_55 ;
V_42 = V_56 |
V_54 ;
break;
}
if ( V_15 ) {
V_45 = F_5 ( V_17 -> V_34 + V_57 ) ;
V_45 &= ~ V_43 ;
F_6 ( V_45 , V_17 -> V_34 + V_57 ) ;
V_44 = F_5 ( V_17 -> V_34 + V_58 ) ;
V_44 |= V_42 ;
F_6 ( V_44 , V_17 -> V_34 + V_58 ) ;
F_8 ( 10 ) ;
V_44 &= ~ V_42 ;
F_6 ( V_44 , V_17 -> V_34 + V_58 ) ;
F_8 ( 80 ) ;
} else {
V_45 = F_5 ( V_17 -> V_34 + V_57 ) ;
V_45 |= V_43 ;
F_6 ( V_45 , V_17 -> V_34 + V_57 ) ;
}
}
static void F_9 ( struct V_13 * V_14 )
{
if ( V_14 -> V_59 ++ > 0 )
return;
F_4 ( V_14 ) ;
F_2 ( V_14 , 0 ) ;
F_7 ( V_14 , 1 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
if ( V_14 -> V_60 ++ > 0 )
return 0 ;
if ( V_14 -> V_20 -> V_21 == V_23 ) {
F_3 ( V_17 -> V_61 , V_62 ,
V_63 ,
V_64 ) ;
F_9 ( & V_17 -> V_65 [ V_22 ] ) ;
}
if ( V_14 -> V_20 -> V_21 == V_22 && V_17 -> V_20 -> V_66 )
F_3 ( V_17 -> V_61 , V_62 ,
V_63 ,
V_67 ) ;
if ( V_14 -> V_20 -> V_21 == V_26 ||
V_14 -> V_20 -> V_21 == V_29 ) {
F_9 ( & V_17 -> V_65 [ V_22 ] ) ;
F_9 ( & V_17 -> V_65 [ V_23 ] ) ;
}
F_9 ( V_14 ) ;
return 0 ;
}
static void F_11 ( struct V_13 * V_14 )
{
if ( V_14 -> V_59 -- > 1 )
return;
F_2 ( V_14 , 1 ) ;
F_7 ( V_14 , 0 ) ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
if ( V_14 -> V_60 -- > 1 )
return 0 ;
if ( V_14 -> V_20 -> V_21 == V_22 && V_17 -> V_20 -> V_66 )
F_3 ( V_17 -> V_61 , V_62 ,
V_63 ,
V_64 ) ;
if ( V_14 -> V_20 -> V_21 == V_23 )
F_11 ( & V_17 -> V_65 [ V_22 ] ) ;
if ( V_14 -> V_20 -> V_21 == V_26 ||
V_14 -> V_20 -> V_21 == V_29 ) {
F_11 ( & V_17 -> V_65 [ V_22 ] ) ;
F_11 ( & V_17 -> V_65 [ V_23 ] ) ;
}
F_11 ( V_14 ) ;
return 0 ;
}
