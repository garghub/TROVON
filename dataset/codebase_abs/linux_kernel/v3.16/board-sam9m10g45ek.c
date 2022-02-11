static void T_1 F_1 ( void )
{
F_2 ( 12000000 ) ;
}
static void T_1 F_3 ( void )
{
V_1 . V_2 = F_4 () ;
if ( V_1 . V_2 )
V_3 . V_4 |= V_5 ;
else
V_3 . V_4 |= V_6 ;
F_5 ( 0 , 3 , & V_3 ) ;
F_6 ( & V_1 ) ;
}
static unsigned long F_7 ( struct V_7 * V_8 )
{
return V_9 ;
}
static int F_8 ( struct V_10 * V_11 , int V_12 )
{
F_9 ( L_1 , V_13 , V_12 ? L_2 : L_3 ) ;
F_10 ( V_14 , ! V_12 ) ;
if ( ! V_12 )
goto V_15;
F_10 ( V_16 , 0 ) ;
F_11 ( 20 ) ;
F_10 ( V_16 , 1 ) ;
F_11 ( 100 ) ;
V_15:
return 0 ;
}
static void T_1 F_12 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_13 ( V_18 ) ; V_17 ++ ) {
F_14 ( V_18 [ V_17 ] . V_19 , 1 ) ;
F_15 ( V_18 [ V_17 ] . V_19 , 1 ) ;
}
F_16 ( & V_20 ) ;
}
static void T_1 F_12 ( void ) {}
static void T_1 F_17 ( void )
{
F_18 ( 0 , 0 , 0 ) ;
F_18 ( V_21 , 2 , V_22 | V_23 ) ;
F_19 () ;
F_20 ( & V_24 ) ;
F_21 ( & V_24 ) ;
F_22 ( & V_25 ) ;
F_23 ( V_26 , F_13 ( V_26 ) ) ;
F_24 ( 0 , & V_27 ) ;
F_24 ( 1 , & V_28 ) ;
F_25 ( & V_29 ) ;
F_3 () ;
F_26 ( 0 , NULL , 0 ) ;
F_27 ( & V_30 , true ) ;
F_28 ( & V_31 ) ;
F_29 ( & V_32 ) ;
F_12 () ;
F_30 ( & V_33 ) ;
F_31 ( V_34 , F_13 ( V_34 ) ) ;
F_32 ( V_35 , F_13 ( V_35 ) ) ;
F_33 ( V_36 , F_13 ( V_36 ) ) ;
}
