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
switch ( V_9 -> V_14 -> V_15 ) {
case V_16 :
V_13 = V_17 ;
break;
case V_18 :
V_13 = V_19 ;
break;
default:
return;
} ;
F_3 ( V_12 -> V_20 , V_21 ,
V_13 , V_10 ? 0 : V_13 ) ;
}
static void F_4 ( struct V_8 * V_9 , bool V_10 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
T_1 V_24 ;
T_1 V_25 ;
switch ( V_9 -> V_14 -> V_15 ) {
case V_16 :
V_23 = V_26 ;
V_22 = V_27 ;
break;
case V_18 :
V_23 = V_28 ;
V_22 = V_29 |
V_30 ;
break;
} ;
if ( V_10 ) {
F_5 ( V_12 -> V_31 , V_12 -> V_32 + V_33 ) ;
V_25 = F_6 ( V_12 -> V_32 + V_34 ) ;
V_25 &= ~ V_23 ;
F_5 ( V_25 , V_12 -> V_32 + V_34 ) ;
V_24 = F_6 ( V_12 -> V_32 + V_35 ) ;
V_24 |= V_22 ;
F_5 ( V_24 , V_12 -> V_32 + V_35 ) ;
F_7 ( 10 ) ;
V_24 &= ~ V_22 ;
F_5 ( V_24 , V_12 -> V_32 + V_35 ) ;
} else {
V_25 = F_6 ( V_12 -> V_32 + V_34 ) ;
V_25 |= V_23 ;
F_5 ( V_25 , V_12 -> V_32 + V_34 ) ;
}
}
static int F_8 ( struct V_8 * V_9 )
{
F_2 ( V_9 , 0 ) ;
F_4 ( V_9 , 1 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
F_4 ( V_9 , 0 ) ;
F_2 ( V_9 , 1 ) ;
return 0 ;
}
