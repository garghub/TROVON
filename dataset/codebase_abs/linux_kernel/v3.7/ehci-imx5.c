int F_1 ( int V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
void T_1 * V_4 ;
void T_1 * V_5 ;
void T_1 * V_6 ;
int V_7 = 0 ;
V_4 = F_2 ( V_8 , V_9 ) ;
if ( ! V_4 ) {
F_3 ( V_10 L_1 , V_11 ) ;
return - V_12 ;
}
switch ( V_1 ) {
case 0 :
V_5 = V_4 + V_13 ;
break;
case 1 :
V_5 = V_4 + V_14 ;
break;
case 2 :
V_5 = V_4 + V_15 ;
break;
default:
F_3 ( V_10 L_2 , V_11 , V_1 ) ;
V_7 = - V_16 ;
goto error;
}
V_6 = V_4 + V_17 ;
switch ( V_1 ) {
case 0 :
if ( V_2 & V_18 ) {
V_3 = F_4 ( V_6 + V_19 ) ;
if ( V_2 & V_20 )
V_3 |= V_21 ;
else
V_3 &= ~ V_21 ;
if ( V_2 & V_22 ) {
V_3 &= ~ V_23 ;
} else {
V_3 |= V_23 ;
}
if ( V_2 & V_24 )
V_3 |= V_25 ;
else
V_3 &= ~ V_25 ;
F_5 ( V_3 , V_6 + V_19 ) ;
V_3 = F_4 ( V_6 + V_26 ) ;
if ( V_2 & V_27 )
V_3 |= V_28 ;
else
V_3 &= ~ V_28 ;
if ( V_2 & V_22 )
V_3 &= ~ V_29 ;
else
V_3 |= V_29 ;
F_5 ( V_3 , V_6 + V_26 ) ;
}
break;
case 1 :
V_3 = F_4 ( V_6 + V_26 ) ;
if ( V_2 & V_27 ) {
V_3 |= ( V_30 | V_31 ) ;
} else {
V_3 &= ~ ( V_30 | V_31 ) ;
}
if ( V_2 & V_22 )
V_3 &= ~ V_32 ;
else
V_3 |= V_32 ;
F_5 ( V_3 , V_6 + V_26 ) ;
V_3 = F_4 ( V_6 + V_19 ) ;
if ( V_2 & V_20 )
V_3 |= V_33 ;
else
V_3 &= ~ V_33 ;
if ( V_2 & V_22 )
V_3 &= ~ V_34 ;
else
V_3 |= V_34 ;
F_5 ( V_3 , V_6 + V_19 ) ;
V_3 = F_4 ( V_5 + V_35 ) ;
if ( V_2 & V_36 )
V_3 &= V_37 ;
F_5 ( V_3 , V_5 + V_35 ) ;
break;
case 2 :
V_3 = F_4 ( V_6 + V_38 ) ;
if ( V_2 & V_27 ) {
V_3 |= ( V_39 | V_40 ) ;
} else {
V_3 &= ~ ( V_39 | V_40 ) ;
}
if ( V_2 & V_22 )
V_3 &= ~ V_41 ;
else
V_3 |= V_41 ;
F_5 ( V_3 , V_6 + V_38 ) ;
break;
}
error:
F_6 ( V_4 ) ;
return V_7 ;
}
