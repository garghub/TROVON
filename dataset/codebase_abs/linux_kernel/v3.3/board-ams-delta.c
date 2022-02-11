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
static int F_3 ( struct V_9 * V_10 , int V_11 )
{
if ( V_11 )
F_4 ( V_12 , V_13 ) ;
else
F_4 ( V_12 , V_14 ) ;
return 0 ;
}
static void T_3 F_5 ( void )
{
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
F_6 ( V_17 ) ;
F_6 ( V_18 ) ;
F_6 ( V_19 ) ;
F_6 ( V_20 ) ;
F_6 ( V_21 ) ;
F_6 ( V_22 ) ;
F_6 ( V_23 ) ;
F_6 ( V_24 ) ;
F_6 ( V_25 ) ;
F_6 ( V_26 ) ;
F_6 ( V_27 ) ;
F_6 ( V_28 ) ;
V_29 = V_30 ;
V_31 = F_7 ( V_30 ) ;
F_8 () ;
F_9 ( 1 , 100 , NULL , 0 ) ;
F_2 ( ~ 0 , 0 ) ;
F_10 ( & V_32 ) ;
F_11 ( & V_33 ) ;
#ifdef F_12
F_13 ( L_1 ,
& V_12 ) ;
#endif
F_14 ( V_34 , F_7 ( V_34 ) ) ;
F_15 () ;
F_16 ( F_17 ( V_35 ) | 0x0004 , V_35 ) ;
}
static int T_3 F_18 ( void )
{
int V_36 ;
if ( ! F_19 () )
return - V_37 ;
F_6 ( V_38 ) ;
V_39 [ 0 ] . V_40 =
F_20 ( V_41 ) ;
V_36 = F_21 ( V_41 , L_2 ) ;
if ( V_36 ) {
F_22 ( L_3 ) ;
return V_36 ;
}
F_23 ( V_41 ) ;
F_2 (
V_42 | V_43 ,
V_42 | V_43 ) ;
return F_24 ( & V_44 ) ;
}
static void T_3 F_25 ( void )
{
F_26 () ;
F_27 ( V_45 , F_7 ( V_45 ) ) ;
}
