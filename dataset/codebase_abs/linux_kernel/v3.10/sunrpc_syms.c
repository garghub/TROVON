static T_1 int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
struct V_3 * V_4 = F_2 ( V_1 , V_5 ) ;
V_2 = F_3 ( V_1 ) ;
if ( V_2 )
goto V_6;
V_2 = F_4 ( V_1 ) ;
if ( V_2 )
goto V_7;
V_2 = F_5 ( V_1 ) ;
if ( V_2 )
goto V_8;
F_6 ( V_1 ) ;
F_7 ( & V_4 -> V_9 ) ;
F_8 ( & V_4 -> V_10 ) ;
F_8 ( & V_4 -> V_11 ) ;
return 0 ;
V_8:
F_9 ( V_1 ) ;
V_7:
F_10 ( V_1 ) ;
V_6:
return V_2 ;
}
static T_2 void F_11 ( struct V_1 * V_1 )
{
F_12 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
}
static int T_3
F_13 ( void )
{
int V_2 = F_14 () ;
if ( V_2 )
goto V_12;
V_2 = F_15 () ;
if ( V_2 )
goto V_13;
F_16 () ;
V_2 = F_17 ( & V_14 ) ;
if ( V_2 )
goto V_15;
V_2 = F_18 () ;
if ( V_2 )
goto V_16;
#ifdef F_19
F_20 () ;
#endif
F_21 () ;
F_22 () ;
return 0 ;
V_16:
F_23 ( & V_14 ) ;
V_15:
F_24 () ;
V_13:
F_25 () ;
V_12:
return V_2 ;
}
static void T_4
F_26 ( void )
{
F_24 () ;
F_27 () ;
F_28 () ;
F_29 () ;
F_25 () ;
F_23 ( & V_14 ) ;
#ifdef F_19
F_30 () ;
#endif
F_31 () ;
}
