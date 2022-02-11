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
F_7 ( V_10 ,
F_8 ( V_10 ) ) ;
F_9 ( NULL ) ;
F_10 ( NULL ) ;
F_11 ( & V_11 ) ;
F_12 ( & V_12 ) ;
F_13 ( 0 , V_13 ,
F_8 ( V_13 ) ) ;
F_14 ( & V_14 ) ;
if ( V_9 )
F_15 ( & V_15 ) ;
else
F_16 ( & V_16 ) ;
F_17 ( & V_17 ) ;
#ifdef F_18
F_19 () ;
#endif
}
static void T_1 F_20 ( void )
{
F_21 () ;
}
