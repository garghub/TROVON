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
F_12 ( L_2 ) ;
while ( ! ( F_8 ( V_14 )
& V_19 ) ) {
F_13 () ;
if ( F_14 ( V_12 , V_11 ) ) {
F_4 ( L_3 ) ;
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
V_7 = F_8 ( V_20 ) ;
V_7 |= V_21 ;
F_9 ( V_7 , V_20 ) ;
V_7 = F_8 ( V_20 ) ;
}
void F_16 ( T_4 V_22 )
{
T_3 V_13 = F_8 ( V_14 ) ;
V_13 &= ~ V_23 ;
switch ( V_22 ) {
case V_24 :
V_13 |= V_25 ;
break;
case V_26 :
V_13 |= V_27 ;
break;
case V_28 :
V_13 |= V_29 ;
break;
default:
F_12 ( L_4 , V_22 ) ;
}
F_9 ( V_13 , V_14 ) ;
}
