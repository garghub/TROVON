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
V_2 = F_6 ( V_1 ) ;
if ( V_2 )
goto V_9;
F_7 ( & V_4 -> V_10 ) ;
F_8 ( & V_4 -> V_11 ) ;
F_8 ( & V_4 -> V_12 ) ;
return 0 ;
V_9:
F_9 ( V_1 ) ;
V_8:
F_10 ( V_1 ) ;
V_7:
F_11 ( V_1 ) ;
V_6:
return V_2 ;
}
static T_2 void F_12 ( struct V_1 * V_1 )
{
F_13 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
F_11 ( V_1 ) ;
}
static int T_3
F_14 ( void )
{
int V_2 = F_15 () ;
if ( V_2 )
goto V_13;
V_2 = F_16 () ;
if ( V_2 )
goto V_14;
F_17 () ;
V_2 = F_18 ( & V_15 ) ;
if ( V_2 )
goto V_16;
V_2 = F_19 () ;
if ( V_2 )
goto V_17;
#ifdef F_20
F_21 () ;
#endif
F_22 () ;
F_23 () ;
return 0 ;
V_17:
F_24 ( & V_15 ) ;
V_16:
F_25 () ;
V_14:
F_26 () ;
V_13:
return V_2 ;
}
static void T_4
F_27 ( void )
{
F_25 () ;
F_28 () ;
F_29 () ;
F_30 () ;
F_26 () ;
F_24 ( & V_15 ) ;
#ifdef F_20
F_31 () ;
#endif
F_32 () ;
}
