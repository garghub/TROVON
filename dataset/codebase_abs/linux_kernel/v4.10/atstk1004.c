static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_1 * V_3 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( F_3 ( V_2 ) )
goto V_4;
V_3 = F_2 ( NULL , L_2 ) ;
if ( F_3 ( V_3 ) )
goto V_5;
if ( F_4 ( V_2 , V_3 ) ) {
F_5 ( L_3 ) ;
goto V_6;
}
F_6 ( V_7 , ( 1 << 30 ) , V_8 , 0 ) ;
V_9 . V_10 = V_2 ;
V_6:
F_7 ( V_3 ) ;
V_5:
F_7 ( V_2 ) ;
V_4:
return;
}
static void T_1 F_1 ( void )
{
}
void T_1 F_8 ( void )
{
#ifdef F_9
F_10 ( 0 , 1 , 0 ) ;
#else
F_10 ( 1 , 0 , 0 ) ;
#endif
F_10 ( 3 , 2 , 0 ) ;
F_11 ( 0 ) ;
}
static int T_1 F_12 ( void )
{
#ifdef F_9
F_13 ( 1 ) ;
#else
F_13 ( 0 ) ;
#endif
F_13 ( 2 ) ;
#ifndef F_14
F_15 ( 0 , V_11 , F_16 ( V_11 ) ) ;
#endif
#ifdef F_17
F_15 ( 1 , V_12 , F_16 ( V_12 ) ) ;
#endif
#ifndef F_9
F_18 ( 0 , & V_13 ) ;
#endif
F_19 ( 0 , & V_14 ,
V_15 , V_16 ,
V_17 | V_18 ) ;
F_20 ( 0 , NULL ) ;
#ifndef F_21
F_22 ( 0 , V_19 ) ;
#endif
F_23 () ;
F_1 () ;
return 0 ;
}
