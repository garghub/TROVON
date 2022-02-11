static void T_1 F_1 ( void )
{
int V_1 ;
F_2 ( V_2 , V_3 ) ;
V_1 = F_3 ( V_2 , V_4 , L_1 ) ;
if ( V_1 < 0 ) {
F_4 ( V_5 L_2 ,
V_2 ) ;
return;
}
V_6 [ 0 ] . V_7 = F_5 ( V_2 ) ;
}
static int T_1 F_6 ( void )
{
F_7 ( 1 , 400 , NULL , 0 ) ;
F_7 ( 2 , 400 , V_8 ,
F_8 ( V_8 ) ) ;
F_7 ( 3 , 400 , V_9 ,
F_8 ( V_9 ) ) ;
return 0 ;
}
static void T_1 F_9 ( void )
{
F_3 ( V_10 , V_11 , L_3 ) ;
F_10 ( & V_12 ) ;
F_11 ( & V_13 ) ;
F_11 ( & V_14 ) ;
F_11 ( & V_15 ) ;
F_11 ( & V_16 ) ;
}
static T_1 void F_12 ( void )
{
T_2 V_17 ;
V_17 = F_13 ( V_18 ) ;
V_17 &= ~ ( V_19 | V_20 | V_21 ) ;
V_17 |= V_22 | V_23 | V_24
| V_25 ;
F_14 ( V_17 , V_18 ) ;
F_15 ( & V_26 ) ;
}
static T_1 void F_16 ( void )
{
T_2 V_27 ;
V_27 = F_13 ( V_28 ) ;
V_27 |= V_29 | V_30 ;
F_14 ( V_27 , V_28 ) ;
}
static void F_17 ( struct V_31 * V_32 )
{
V_33 . V_34 . V_35 = V_32 ;
F_11 ( & V_33 ) ;
}
static void T_1 F_18 ( void )
{
F_19 ( V_36 , V_37 ) ;
F_6 () ;
F_9 () ;
F_20 () ;
F_21 ( NULL , NULL ) ;
F_2 ( 57 , V_38 ) ;
F_22 ( V_39 , F_8 ( V_39 ) ) ;
F_23 ( & V_40 ) ;
F_17 ( & V_41 ) ;
F_1 () ;
F_24 ( 1 , V_6 ,
F_8 ( V_6 ) ) ;
F_25 ( V_42 , 1 ) ;
F_12 () ;
F_16 () ;
F_26 ( V_43 ) ;
}
