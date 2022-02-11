static T_1 int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_2 ( V_1 ) ;
if ( V_2 )
goto V_3;
V_2 = F_3 ( V_1 ) ;
if ( V_2 )
goto V_4;
return 0 ;
V_4:
F_4 ( V_1 ) ;
V_3:
return V_2 ;
}
static T_2 void F_5 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
F_4 ( V_1 ) ;
}
static int T_3
F_7 ( void )
{
int V_2 = F_8 () ;
if ( V_2 )
goto V_5;
V_2 = F_9 () ;
if ( V_2 )
goto V_6;
V_2 = F_10 () ;
if ( V_2 )
goto V_7;
F_11 () ;
V_2 = F_12 ( & V_8 ) ;
if ( V_2 )
goto V_9;
#ifdef F_13
F_14 () ;
#endif
F_15 ( & V_10 ) ;
F_16 () ;
F_17 () ;
return 0 ;
V_9:
F_18 () ;
V_7:
F_19 () ;
V_6:
F_20 () ;
V_5:
return V_2 ;
}
static void T_4
F_21 ( void )
{
F_18 () ;
F_22 () ;
F_23 () ;
F_20 () ;
F_19 () ;
F_24 ( & V_10 ) ;
F_25 ( & V_8 ) ;
#ifdef F_13
F_26 () ;
#endif
F_27 () ;
}
