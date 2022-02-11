static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_5 |
V_6 | V_7 ) ;
}
static int T_1 F_4 ( char * V_8 )
{
if ( ! strcmp ( V_8 , L_1 ) )
V_9 = 1 ;
else if ( ! strcmp ( V_8 , L_2 ) )
V_9 = 0 ;
else
F_5 ( L_3
L_4 ) ;
return 0 ;
}
static void T_1 F_6 ( void )
{
F_7 () ;
if ( F_8 ( V_10 ,
F_9 ( V_10 ) ) )
F_10 ( V_11 L_5 ) ;
F_11 ( & V_12 ) ;
F_12 ( & V_13 ) ;
F_13 ( NULL ) ;
F_14 ( & V_14 ) ;
F_15 ( NULL ) ;
F_16 ( 0 , V_15 ,
F_9 ( V_15 ) ) ;
F_17 ( & V_16 ) ;
if ( V_9 )
F_18 ( & V_17 ) ;
else
F_19 ( & V_18 ) ;
F_20 ( & V_19 ) ;
#ifdef F_21
F_22 () ;
#endif
}
static void T_1 F_23 ( void )
{
F_24 () ;
}
