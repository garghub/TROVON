void F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = NULL ;
V_1 -> V_3 = NULL ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
V_1 -> V_6 = NULL ;
V_1 -> V_7 = NULL ;
V_1 -> V_8 = NULL ;
V_1 -> V_9 = NULL ;
F_2 ( V_1 -> V_10 , L_1 , sizeof( V_1 -> V_10 ) ) ;
}
static int T_2 F_3 ( void )
{
int V_11 = 0 ;
F_4 () ;
F_5 () ;
F_6 () ;
F_7 () ;
F_8 () ;
V_11 = F_9 () ;
if ( V_11 < 0 )
goto V_12;
F_10 ( & V_13 ) ;
#ifdef F_11
F_12 () ;
#endif
#ifdef F_13
V_11 = F_14 () ;
if ( V_11 < 0 )
goto V_14;
#endif
V_11 = F_15 () ;
if ( V_11 < 0 )
goto V_15;
return 0 ;
V_15:
#ifdef F_13
F_16 () ;
V_14:
#endif
#ifdef F_11
F_17 () ;
#endif
F_18 ( & V_13 ) ;
F_19 () ;
V_12:
F_20 () ;
F_21 () ;
F_22 () ;
F_23 () ;
F_24 () ;
return V_11 ;
}
static void T_3 F_25 ( void )
{
F_26 () ;
#ifdef F_13
F_16 () ;
#endif
#ifdef F_11
F_17 () ;
#endif
F_18 ( & V_13 ) ;
F_19 () ;
F_20 () ;
F_21 () ;
F_22 () ;
F_23 () ;
F_24 () ;
}
