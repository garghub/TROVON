void F_1 ( T_1 V_1 , T_1 V_2 )
{
V_3 &= ~ V_1 ;
V_3 |= V_2 ;
* ( volatile V_4 * ) V_5 = V_3 ;
}
void F_2 ( T_2 V_1 , T_2 V_2 )
{
V_6 &= ~ V_1 ;
V_6 |= V_2 ;
* ( volatile V_7 * ) V_8 = V_6 ;
}
static void T_3 F_3 ( void )
{
F_4 () ;
F_5 () ;
}
static int F_6 ( struct V_9 * V_10 , int V_11 )
{
if ( V_11 )
F_7 ( V_12 , V_13 ) ;
else
F_7 ( V_12 , V_14 ) ;
return 0 ;
}
static void T_3 F_8 ( void )
{
F_9 ( V_15 ) ;
F_9 ( V_16 ) ;
F_9 ( V_17 ) ;
F_9 ( V_18 ) ;
F_9 ( V_19 ) ;
F_9 ( V_20 ) ;
F_9 ( V_21 ) ;
F_9 ( V_22 ) ;
F_9 ( V_23 ) ;
F_9 ( V_24 ) ;
F_9 ( V_25 ) ;
F_9 ( V_26 ) ;
F_9 ( V_27 ) ;
F_9 ( V_28 ) ;
F_10 ( V_29 , F_11 ( V_29 ) ) ;
V_30 = V_31 ;
V_32 = F_11 ( V_31 ) ;
F_12 () ;
F_13 ( 1 , 100 , NULL , 0 ) ;
F_2 ( ~ 0 , 0 ) ;
F_14 ( & V_33 ) ;
F_15 ( & V_34 ) ;
#ifdef F_16
F_17 ( L_1 ,
& V_12 ) ;
#endif
F_18 ( V_35 , F_11 ( V_35 ) ) ;
F_19 () ;
F_20 ( F_21 ( V_36 ) | 0x0004 , V_36 ) ;
}
static int T_3 F_22 ( void )
{
int V_37 ;
if ( ! F_23 () )
return - V_38 ;
F_9 ( V_39 ) ;
V_40 [ 0 ] . V_41 =
F_24 ( V_42 ) ;
V_37 = F_25 ( V_42 , L_2 ) ;
if ( V_37 ) {
F_26 ( L_3 ) ;
return V_37 ;
}
F_27 ( V_42 ) ;
F_2 (
V_43 | V_44 ,
V_43 | V_44 ) ;
return F_28 ( & V_45 ) ;
}
static void T_3 F_29 ( void )
{
F_30 () ;
}
