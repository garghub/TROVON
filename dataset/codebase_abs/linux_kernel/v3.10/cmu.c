void F_1 ( T_1 clock )
{
F_2 ( & V_1 ) ;
switch ( clock ) {
case V_2 :
V_3 |= V_4 ;
break;
case V_5 :
V_3 |= V_6 | V_7 ;
break;
case V_8 :
V_3 |= V_9 ;
break;
case V_10 :
V_3 |= V_11 ;
break;
case V_12 :
V_3 |= V_13 | V_14 ;
break;
case V_15 :
if ( F_3 () == V_16 ||
F_3 () == V_17 )
V_3 |= V_18 ;
else
V_3 |= V_6 | V_18 ;
break;
case V_19 :
V_3 |= V_20 | V_21 ;
break;
case V_22 :
V_3 |= V_23 ;
break;
case V_24 :
V_3 |= V_25 ;
break;
case V_26 :
V_3 |= V_27 ;
break;
case V_28 :
V_29 |= V_30 ;
break;
case V_31 :
V_29 |= V_32 ;
break;
case V_33 :
V_29 |= V_34 ;
break;
default:
break;
}
if ( clock == V_28 || clock == V_31 ||
clock == V_33 )
F_4 ( V_35 , V_29 ) ;
else
F_4 ( V_36 , V_3 ) ;
F_5 ( & V_1 ) ;
}
void F_6 ( T_1 clock )
{
F_2 ( & V_1 ) ;
switch ( clock ) {
case V_2 :
V_3 &= ~ V_4 ;
break;
case V_5 :
if ( F_3 () == V_16 ||
F_3 () == V_17 ) {
V_3 &= ~ ( V_6 | V_7 ) ;
} else {
if ( V_3 & V_18 )
V_3 &= ~ V_7 ;
else
V_3 &= ~ ( V_6 | V_7 ) ;
}
break;
case V_8 :
V_3 &= ~ V_9 ;
break;
case V_10 :
V_3 &= ~ V_11 ;
break;
case V_12 :
V_3 &= ~ ( V_13 | V_14 ) ;
break;
case V_15 :
if ( F_3 () == V_16 ||
F_3 () == V_17 ) {
V_3 &= ~ V_18 ;
} else {
if ( V_3 & V_7 )
V_3 &= ~ V_18 ;
else
V_3 &= ~ ( V_6 | V_18 ) ;
}
break;
case V_19 :
V_3 &= ~ ( V_20 | V_21 ) ;
break;
case V_22 :
V_3 &= ~ V_23 ;
break;
case V_24 :
V_3 &= ~ V_25 ;
break;
case V_26 :
V_3 &= ~ V_27 ;
break;
case V_28 :
V_29 &= ~ V_30 ;
break;
case V_31 :
V_29 &= ~ V_32 ;
break;
case V_33 :
V_29 &= ~ V_34 ;
break;
default:
break;
}
if ( clock == V_28 || clock == V_31 ||
clock == V_33 )
F_4 ( V_35 , V_29 ) ;
else
F_4 ( V_36 , V_3 ) ;
F_5 ( & V_1 ) ;
}
static int T_2 F_7 ( void )
{
unsigned long V_37 , V_38 ;
switch ( F_3 () ) {
case V_16 :
case V_17 :
V_37 = V_39 ;
V_38 = V_40 ;
break;
case V_41 :
case V_42 :
V_37 = V_43 ;
V_38 = V_44 ;
break;
case V_45 :
V_37 = V_46 ;
V_38 = V_47 ;
break;
default:
F_8 ( L_1 ) ;
break;
}
if ( F_9 ( V_37 , V_38 , L_2 ) == NULL )
return - V_48 ;
V_49 = F_10 ( V_37 , V_38 ) ;
if ( V_49 == NULL ) {
F_11 ( V_37 , V_38 ) ;
return - V_48 ;
}
V_3 = F_12 ( V_36 ) ;
if ( F_3 () == V_45 )
V_29 = F_12 ( V_35 ) ;
F_13 ( & V_1 ) ;
return 0 ;
}
