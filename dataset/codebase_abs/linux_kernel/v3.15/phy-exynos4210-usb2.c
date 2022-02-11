static int F_1 ( unsigned long V_1 , T_1 * V_2 )
{
switch ( V_1 ) {
case 12 * V_3 :
* V_2 = V_4 ;
break;
case 24 * V_3 :
* V_2 = V_5 ;
break;
case 48 * V_3 :
* V_2 = V_6 ;
break;
default:
return - V_7 ;
}
return 0 ;
}
static void F_2 ( struct V_8 * V_9 , bool V_10 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
T_1 V_13 ;
T_1 V_14 ;
switch ( V_9 -> V_15 -> V_16 ) {
case V_17 :
V_13 = V_18 ;
V_14 = V_19 ;
break;
case V_20 :
V_13 = V_21 ;
V_14 = V_22 ;
break;
default:
return;
} ;
F_3 ( V_12 -> V_23 , V_13 , V_14 , V_10 ? 0 : V_14 ) ;
}
static void F_4 ( struct V_8 * V_9 , bool V_10 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
T_1 V_24 = 0 ;
T_1 V_25 = 0 ;
T_1 V_26 ;
T_1 V_27 ;
T_1 V_28 ;
switch ( V_9 -> V_15 -> V_16 ) {
case V_17 :
V_25 = V_29 ;
V_24 = V_30 ;
break;
case V_20 :
V_25 = V_31 ;
V_24 = V_32 |
V_33 |
V_34 |
V_35 |
V_36 ;
F_5 ( V_10 , V_12 -> V_37 + V_38 ) ;
break;
case V_39 :
V_25 = V_40 ;
V_24 = V_34 |
V_41 ;
break;
case V_42 :
V_25 = V_43 ;
V_24 = V_34 |
V_44 ;
break;
} ;
if ( V_10 ) {
V_28 = F_6 ( V_12 -> V_37 + V_45 ) ;
V_28 &= ~ V_46 ;
V_28 |= V_12 -> V_47 << V_48 ;
F_5 ( V_28 , V_12 -> V_37 + V_45 ) ;
V_27 = F_6 ( V_12 -> V_37 + V_49 ) ;
V_27 &= ~ V_25 ;
F_5 ( V_27 , V_12 -> V_37 + V_49 ) ;
V_26 = F_6 ( V_12 -> V_37 + V_50 ) ;
V_26 |= V_24 ;
F_5 ( V_26 , V_12 -> V_37 + V_50 ) ;
F_7 ( 10 ) ;
V_26 &= ~ V_24 ;
F_5 ( V_26 , V_12 -> V_37 + V_50 ) ;
F_7 ( 80 ) ;
} else {
V_27 = F_6 ( V_12 -> V_37 + V_49 ) ;
V_27 |= V_25 ;
F_5 ( V_27 , V_12 -> V_37 + V_49 ) ;
}
}
static int F_8 ( struct V_8 * V_9 )
{
F_4 ( V_9 , 1 ) ;
F_2 ( V_9 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
F_2 ( V_9 , 1 ) ;
F_4 ( V_9 , 0 ) ;
return 0 ;
}
