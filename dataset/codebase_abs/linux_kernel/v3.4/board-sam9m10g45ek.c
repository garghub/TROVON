static void T_1 F_1 ( void )
{
F_2 ( 12000000 ) ;
F_3 ( 0 , 0 , 0 ) ;
F_3 ( V_1 , 2 , V_2 | V_3 ) ;
F_4 ( 0 ) ;
}
static void T_1 F_5 ( void )
{
V_4 . V_5 = F_6 () ;
if ( V_4 . V_5 )
V_6 . V_7 |= V_8 ;
else
V_6 . V_7 |= V_9 ;
F_7 ( 0 , 3 , & V_6 ) ;
F_8 ( & V_4 ) ;
}
static unsigned long F_9 ( struct V_10 * V_11 )
{
return V_12 ;
}
static int F_10 ( struct V_13 * V_14 , int V_15 )
{
F_11 ( L_1 , V_16 , V_15 ? L_2 : L_3 ) ;
F_12 ( V_17 , ! V_15 ) ;
if ( ! V_15 )
goto V_18;
F_12 ( V_19 , 0 ) ;
F_13 ( 20 ) ;
F_12 ( V_19 , 1 ) ;
F_13 ( 100 ) ;
V_18:
return 0 ;
}
static void T_1 F_14 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_15 ( V_21 ) ; V_20 ++ ) {
F_16 ( V_21 [ V_20 ] . V_22 , 1 ) ;
F_17 ( V_21 [ V_20 ] . V_22 , 1 ) ;
}
F_18 ( & V_23 ) ;
}
static void T_1 F_14 ( void ) {}
static void T_1 F_19 ( void )
{
F_20 () ;
F_21 ( & V_24 ) ;
F_22 ( & V_24 ) ;
F_23 ( & V_25 ) ;
F_24 ( V_26 , F_15 ( V_26 ) ) ;
F_25 ( 0 , & V_27 ) ;
F_25 ( 1 , & V_28 ) ;
F_26 ( & V_29 ) ;
F_5 () ;
F_27 ( 0 , NULL , 0 ) ;
F_28 ( & V_30 , true ) ;
F_29 ( & V_31 ) ;
F_30 ( & V_32 ) ;
F_14 () ;
F_31 ( & V_33 ) ;
F_32 ( V_34 , F_15 ( V_34 ) ) ;
F_33 ( V_35 , F_15 ( V_35 ) ) ;
F_34 ( V_36 , F_15 ( V_36 ) ) ;
}
