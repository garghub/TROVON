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
F_4 ( 0 , L_2 , V_12 ) ;
F_5 () ;
F_6 () ;
F_7 () ;
F_8 () ;
F_9 () ;
V_11 = F_10 () ;
if ( V_11 < 0 )
goto V_13;
F_11 ( & V_14 ) ;
#ifdef F_12
F_13 () ;
#endif
#ifdef F_14
V_11 = F_15 () ;
if ( V_11 < 0 )
goto V_15;
#endif
V_11 = F_16 () ;
if ( V_11 < 0 )
goto V_16;
return 0 ;
V_16:
#ifdef F_14
F_17 () ;
V_15:
#endif
#ifdef F_12
F_18 () ;
#endif
F_19 ( & V_14 ) ;
F_20 () ;
V_13:
F_21 () ;
F_22 () ;
F_23 () ;
F_24 () ;
F_25 () ;
return V_11 ;
}
static void T_3 F_26 ( void )
{
F_27 () ;
#ifdef F_14
F_17 () ;
#endif
#ifdef F_12
F_18 () ;
#endif
F_19 ( & V_14 ) ;
F_20 () ;
F_21 () ;
F_22 () ;
F_23 () ;
F_24 () ;
F_25 () ;
}
