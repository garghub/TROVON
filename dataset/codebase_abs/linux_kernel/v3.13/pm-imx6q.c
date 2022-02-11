void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 + V_3 ) ;
V_1 |= V_4 ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static void F_4 ( bool V_5 )
{
T_1 V_1 ;
F_5 () ;
V_1 = F_2 ( V_2 + V_6 ) ;
V_1 &= ~ V_7 ;
V_1 |= V_5 ? V_7 : 0 ;
F_3 ( V_1 , V_2 + V_6 ) ;
V_1 = F_2 ( V_2 + V_6 ) ;
V_1 &= ~ V_8 ;
V_1 |= V_5 ? V_8 : 0 ;
F_6 ( V_1 , V_2 + V_6 ) ;
F_7 ( 65 ) ;
F_8 () ;
}
static void F_9 ( bool V_5 )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + V_9 ) ;
V_1 &= ~ V_10 ;
V_1 |= V_5 ? V_10 : 0 ;
F_3 ( V_1 , V_2 + V_9 ) ;
V_1 = F_2 ( V_2 + V_6 ) ;
V_1 &= ~ V_11 ;
V_1 |= V_5 ? V_11 : 0 ;
F_3 ( V_1 , V_2 + V_6 ) ;
}
int F_10 ( enum V_12 V_13 )
{
struct V_14 * V_15 ;
T_1 V_1 = F_2 ( V_2 + V_9 ) ;
V_1 &= ~ V_16 ;
switch ( V_13 ) {
case V_17 :
break;
case V_18 :
V_1 |= 0x1 << V_19 ;
V_1 |= V_20 ;
break;
case V_21 :
V_1 |= 0x2 << V_19 ;
break;
case V_22 :
V_1 |= 0x1 << V_19 ;
V_1 &= ~ V_23 ;
V_1 &= ~ V_24 ;
break;
case V_25 :
V_1 |= 0x2 << V_19 ;
V_1 |= 0x3 << V_26 ;
V_1 |= V_23 ;
V_1 |= V_24 ;
if ( F_11 () ) {
V_1 |= V_27 ;
V_1 |= V_28 ;
} else {
V_1 |= V_29 ;
}
break;
default:
return - V_30 ;
}
V_15 = F_12 ( 32 ) ;
F_13 ( & V_15 -> V_31 ) ;
F_3 ( V_1 , V_2 + V_9 ) ;
F_14 ( & V_15 -> V_31 ) ;
return 0 ;
}
static int F_15 ( unsigned long V_1 )
{
F_16 () ;
return 0 ;
}
static int F_17 ( T_2 V_32 )
{
switch ( V_32 ) {
case V_33 :
F_10 ( V_25 ) ;
F_9 ( true ) ;
F_4 ( true ) ;
F_18 () ;
F_19 () ;
F_20 ( 0 , V_34 ) ;
F_21 ( 0 , F_15 ) ;
if ( F_22 () || F_23 () )
F_24 () ;
F_25 () ;
F_26 () ;
F_4 ( false ) ;
F_9 ( false ) ;
F_10 ( V_17 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
void T_3 F_27 ( void T_4 * V_35 )
{
V_2 = V_35 ;
}
void T_3 F_28 ( void )
{
struct V_36 * V_37 ;
F_29 ( ! V_2 ) ;
V_37 = F_30 ( L_1 ) ;
if ( ! F_31 ( V_37 ) )
F_32 ( V_37 , V_38 , V_39 ,
V_39 ) ;
F_10 ( V_17 ) ;
F_33 ( & V_40 ) ;
}
