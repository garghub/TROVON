void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= V_3 ;
F_3 ( V_1 , V_2 ) ;
V_1 &= ~ V_3 ;
F_3 ( V_1 , V_2 ) ;
V_1 = F_2 ( V_2 ) ;
}
void F_4 ( T_2 V_4 )
{
unsigned long V_5 = V_6 + F_5 ( 100 ) ;
T_1 V_7 ;
if ( V_4 ) {
V_7 = F_2 ( V_8 ) ;
V_7 &= ~ ( V_9 | V_10 | V_11 ) ;
V_7 |= V_12 ;
F_3 ( V_7 , V_8 ) ;
F_6 ( V_13 L_1 ) ;
while ( ! ( F_2 ( V_8 )
& V_14 ) ) {
F_7 () ;
if ( F_8 ( V_6 , V_5 ) ) {
F_9 ( V_15 L_2 ) ;
break;
}
}
} else {
V_7 = F_2 ( V_8 ) ;
V_7 &= ~ V_12 ;
V_7 |= V_10 | V_11 ;
F_3 ( V_7 , V_8 ) ;
}
}
void F_10 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_16 ) ;
V_1 |= V_17 ;
F_3 ( V_1 , V_16 ) ;
V_1 = F_2 ( V_16 ) ;
}
void F_11 ( T_2 V_18 )
{
T_1 V_7 = F_2 ( V_8 ) ;
V_7 &= ~ V_19 ;
switch ( V_18 ) {
case V_20 :
V_7 |= V_21 ;
break;
case V_22 :
V_7 |= V_23 ;
break;
case V_24 :
V_7 |= V_25 ;
break;
default:
F_6 ( V_13 L_3 , V_18 ) ;
}
F_3 ( V_7 , V_8 ) ;
}
void F_12 ( T_2 V_4 )
{
void T_3 * V_26 = NULL ;
T_1 V_27 ;
V_26 = F_13 ( V_28 , V_29 ) ;
if ( ! V_26 ) {
F_9 ( L_4 ) ;
return;
}
V_27 = F_14 ( V_26 + V_30 ) ;
if ( V_4 ) {
if ( F_15 () ) {
V_27 |= V_31 ;
V_27 &= ~ V_32 ;
} else if ( F_16 () ) {
V_27 &= ~ ( V_33 | V_34
| V_35 | V_36 ) ;
V_27 |= ( V_37 | V_38
| V_39 | V_40 ) ;
}
} else {
if ( F_15 () )
V_27 &= ~ V_31 ;
else if ( F_16 () )
V_27 |= V_33 | V_34 ;
}
F_17 ( V_27 , V_26 + V_30 ) ;
F_18 ( V_26 ) ;
}
