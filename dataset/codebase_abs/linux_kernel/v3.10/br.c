static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( & V_2 ) ;
if ( V_1 < 0 ) {
F_3 ( L_1 ) ;
return V_1 ;
}
V_1 = F_4 () ;
if ( V_1 )
goto V_3;
V_1 = F_5 ( & V_4 ) ;
if ( V_1 )
goto V_5;
V_1 = F_6 () ;
if ( V_1 )
goto V_6;
V_1 = F_7 ( & V_7 ) ;
if ( V_1 )
goto V_8;
V_1 = F_8 () ;
if ( V_1 )
goto V_9;
F_9 ( V_10 ) ;
#if F_10 ( V_11 )
V_12 = V_13 ;
#endif
return 0 ;
V_9:
F_11 ( & V_7 ) ;
V_8:
F_12 () ;
V_6:
F_13 ( & V_4 ) ;
V_5:
F_14 () ;
V_3:
F_15 ( & V_2 ) ;
return V_1 ;
}
static void T_2 F_16 ( void )
{
F_15 ( & V_2 ) ;
F_17 () ;
F_11 ( & V_7 ) ;
F_9 ( NULL ) ;
F_13 ( & V_4 ) ;
F_18 () ;
F_12 () ;
#if F_10 ( V_11 )
V_12 = NULL ;
#endif
F_14 () ;
}
