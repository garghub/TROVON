static void T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
F_2 ( V_4 ) ;
F_3 () ;
F_4 (net, dev)
if ( V_3 -> V_5 & V_6 )
F_5 ( V_3 , & V_4 ) ;
F_6 ( & V_4 ) ;
F_7 () ;
}
static int T_2 F_8 ( void )
{
int V_7 ;
V_7 = F_9 ( & V_8 ) ;
if ( V_7 < 0 ) {
F_10 ( L_1 ) ;
return V_7 ;
}
V_7 = F_11 () ;
if ( V_7 )
goto V_9;
V_7 = F_12 ( & V_10 ) ;
if ( V_7 )
goto V_11;
V_7 = F_13 () ;
if ( V_7 )
goto V_12;
V_7 = F_14 ( & V_13 ) ;
if ( V_7 )
goto V_14;
V_7 = F_15 () ;
if ( V_7 )
goto V_15;
F_16 ( V_16 ) ;
#if F_17 ( V_17 )
V_18 = V_19 ;
#endif
return 0 ;
V_15:
F_18 ( & V_13 ) ;
V_14:
F_19 () ;
V_12:
F_20 ( & V_10 ) ;
V_11:
F_21 () ;
V_9:
F_22 ( & V_8 ) ;
return V_7 ;
}
static void T_3 F_23 ( void )
{
F_22 ( & V_8 ) ;
F_24 () ;
F_18 ( & V_13 ) ;
F_16 ( NULL ) ;
F_20 ( & V_10 ) ;
F_25 () ;
F_19 () ;
#if F_17 ( V_17 )
V_18 = NULL ;
#endif
F_21 () ;
}
