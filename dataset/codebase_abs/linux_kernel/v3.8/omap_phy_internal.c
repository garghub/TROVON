static int T_1 F_1 ( void )
{
void T_2 * V_1 ;
if ( ! F_2 () )
return 0 ;
V_1 = F_3 ( V_2 , V_3 ) ;
if ( ! V_1 ) {
F_4 ( L_1 ) ;
return - V_4 ;
}
F_5 ( V_5 , V_1 + V_6 ) ;
F_6 ( V_1 ) ;
return 0 ;
}
void F_7 ( void )
{
T_3 V_7 ;
V_7 = F_8 ( V_8 ) ;
V_7 |= V_9 ;
F_9 ( V_7 , V_8 ) ;
V_7 &= ~ V_9 ;
F_9 ( V_7 , V_8 ) ;
V_7 = F_8 ( V_8 ) ;
}
void F_10 ( T_4 V_10 )
{
unsigned long V_11 = V_12 + F_11 ( 100 ) ;
T_3 V_13 ;
if ( V_10 ) {
V_13 = F_8 ( V_14 ) ;
V_13 &= ~ ( V_15 | V_16 | V_17 ) ;
V_13 |= V_18 ;
F_9 ( V_13 , V_14 ) ;
F_12 ( V_19 L_2 ) ;
while ( ! ( F_8 ( V_14 )
& V_20 ) ) {
F_13 () ;
if ( F_14 ( V_12 , V_11 ) ) {
F_4 ( V_21 L_3 ) ;
break;
}
}
} else {
V_13 = F_8 ( V_14 ) ;
V_13 &= ~ V_18 ;
V_13 |= V_16 | V_17 ;
F_9 ( V_13 , V_14 ) ;
}
}
void F_15 ( void )
{
T_3 V_7 ;
V_7 = F_8 ( V_22 ) ;
V_7 |= V_23 ;
F_9 ( V_7 , V_22 ) ;
V_7 = F_8 ( V_22 ) ;
}
void F_16 ( T_4 V_24 )
{
T_3 V_13 = F_8 ( V_14 ) ;
V_13 &= ~ V_25 ;
switch ( V_24 ) {
case V_26 :
V_13 |= V_27 ;
break;
case V_28 :
V_13 |= V_29 ;
break;
case V_30 :
V_13 |= V_31 ;
break;
default:
F_12 ( V_19 L_4 , V_24 ) ;
}
F_9 ( V_13 , V_14 ) ;
}
void F_17 ( T_4 V_10 )
{
void T_2 * V_32 = NULL ;
T_3 V_33 ;
V_32 = F_3 ( V_34 , V_35 ) ;
if ( ! V_32 ) {
F_4 ( L_5 ) ;
return;
}
V_33 = F_18 ( V_32 + V_36 ) ;
if ( V_10 ) {
if ( F_19 () ) {
V_33 |= V_37 ;
V_33 &= ~ V_38 ;
} else if ( F_20 () ) {
V_33 &= ~ ( V_39 | V_40
| V_41 | V_42 ) ;
V_33 |= ( V_43 | V_44
| V_45 | V_46 ) ;
}
} else {
if ( F_19 () )
V_33 &= ~ V_37 ;
else if ( F_20 () )
V_33 |= V_39 | V_40 ;
}
F_5 ( V_33 , V_32 + V_36 ) ;
F_6 ( V_32 ) ;
}
