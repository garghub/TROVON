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
static T_1 void F_9 ( void )
{
T_2 V_10 ;
V_10 = F_10 ( V_11 ) ;
V_10 &= ~ ( V_12 | V_13 | V_14 ) ;
V_10 |= V_15 | V_16 | V_17
| V_18 ;
F_11 ( V_10 , V_11 ) ;
F_12 ( & V_19 ) ;
}
static T_1 void F_13 ( void )
{
T_2 V_20 ;
V_20 = F_10 ( V_21 ) ;
V_20 |= V_22 | V_23 ;
F_11 ( V_20 , V_21 ) ;
}
static void F_14 ( struct V_24 * V_25 )
{
V_26 . V_27 . V_28 = V_25 ;
F_15 ( & V_26 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_29 , V_30 ) ;
F_6 () ;
F_18 ( & V_31 ) ;
F_19 () ;
F_20 ( NULL , NULL ) ;
F_2 ( 57 , V_32 ) ;
F_21 ( V_33 , F_8 ( V_33 ) ) ;
F_22 ( & V_34 ) ;
F_14 ( & V_35 ) ;
F_1 () ;
F_23 ( 1 , V_6 ,
F_8 ( V_6 ) ) ;
F_24 ( V_36 , 1 ) ;
F_9 () ;
F_13 () ;
F_25 ( V_37 ) ;
}
