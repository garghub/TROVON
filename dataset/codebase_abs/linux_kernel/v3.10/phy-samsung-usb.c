int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 -> V_6 , L_1 ) ;
if ( ! V_4 ) {
F_3 ( V_2 -> V_5 , L_2 ) ;
return - V_7 ;
}
V_2 -> V_8 = F_4 ( V_4 , 0 ) ;
if ( V_2 -> V_8 == NULL ) {
F_3 ( V_2 -> V_5 , L_3 ) ;
goto V_9;
}
V_2 -> V_10 = F_4 ( V_4 , 1 ) ;
if ( V_2 -> V_10 == NULL )
F_5 ( V_2 -> V_5 , L_4 ) ;
F_6 ( V_4 ) ;
return 0 ;
V_9:
F_6 ( V_4 ) ;
return - V_11 ;
}
void F_7 ( struct V_1 * V_2 , bool V_12 )
{
void T_1 * V_13 = NULL ;
T_2 V_14 ;
T_2 V_15 = 0 ;
if ( ! V_2 -> V_8 ) {
F_5 ( V_2 -> V_5 , L_5 ) ;
return;
}
switch ( V_2 -> V_16 -> V_17 ) {
case V_18 :
break;
case V_19 :
case V_20 :
if ( V_2 -> V_21 == V_22 ) {
V_13 = V_2 -> V_8 +
V_2 -> V_16 -> V_23 ;
V_15 = V_2 -> V_16 -> V_24 ;
} else if ( V_2 -> V_21 == V_25 ) {
V_13 = V_2 -> V_8 +
V_2 -> V_16 -> V_26 ;
V_15 = V_2 -> V_16 -> V_27 ;
}
break;
default:
F_3 ( V_2 -> V_5 , L_6 ) ;
return;
}
V_14 = F_8 ( V_13 ) ;
if ( V_12 )
V_14 &= ~ V_15 ;
else
V_14 |= V_15 ;
F_9 ( V_14 , V_13 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
T_2 V_13 ;
if ( ! V_2 -> V_10 ) {
F_5 ( V_2 -> V_5 , L_7 ) ;
return;
}
V_13 = F_8 ( V_2 -> V_10 ) ;
if ( V_2 -> V_21 == V_22 )
V_13 &= ~ V_28 ;
else if ( V_2 -> V_21 == V_25 )
V_13 |= V_28 ;
F_9 ( V_13 , V_2 -> V_10 ) ;
}
int F_11 ( struct V_29 * V_30 ,
enum V_31 V_21 )
{
struct V_1 * V_2 = F_12 ( V_30 ) ;
V_2 -> V_21 = V_21 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
int V_34 = 0 ;
if ( V_2 -> V_16 -> V_17 == V_20 )
V_33 = F_14 ( V_2 -> V_5 , L_8 ) ;
else
V_33 = F_14 ( V_2 -> V_5 , L_9 ) ;
if ( F_15 ( V_33 ) ) {
F_3 ( V_2 -> V_5 , L_10 ) ;
return F_16 ( V_33 ) ;
}
if ( V_2 -> V_16 -> V_17 == V_20 ) {
switch ( F_17 ( V_33 ) ) {
case 9600 * V_35 :
V_34 = V_36 ;
break;
case 10 * V_37 :
V_34 = V_38 ;
break;
case 12 * V_37 :
V_34 = V_39 ;
break;
case 19200 * V_35 :
V_34 = V_40 ;
break;
case 20 * V_37 :
V_34 = V_41 ;
break;
case 50 * V_37 :
V_34 = V_42 ;
break;
case 24 * V_37 :
default:
V_34 = V_43 ;
break;
}
} else {
switch ( F_17 ( V_33 ) ) {
case 12 * V_37 :
V_34 = V_44 ;
break;
case 24 * V_37 :
V_34 = V_45 ;
break;
case 48 * V_37 :
V_34 = V_46 ;
break;
default:
if ( V_2 -> V_16 -> V_17 == V_18 )
V_34 = V_46 ;
else
V_34 = V_45 ;
break;
}
}
F_18 ( V_33 ) ;
return V_34 ;
}
