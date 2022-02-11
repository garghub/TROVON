static int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( F_2 () && ( V_3 == 8 ) )
return V_5 ;
return V_6 ;
}
static void T_2 F_3 ( void )
{
F_4 ( V_7 , V_8 ) ;
if ( F_2 () )
F_4 ( V_9 , V_8 ) ;
F_5 ( & V_10 ) ;
}
static void T_2 F_6 ( void )
{
unsigned int V_11 = 1 ;
if ( F_2 () )
V_11 = 2 ;
else if ( F_7 () )
V_11 = 0 ;
F_8 ( V_11 , L_1 ) ;
F_9 ( V_11 , 0 ) ;
F_10 ( V_11 , 1 ) ;
F_10 ( V_11 , 0 ) ;
F_11 ( 100 ) ;
F_10 ( V_11 , 1 ) ;
F_11 ( 100 ) ;
}
static void T_2 F_12 ( void )
{
F_13 () ;
if ( F_14 () ) {
F_4 ( V_9 , V_12 ) ;
F_15 ( V_13 , F_16 ( V_13 ) ) ;
F_17 ( V_14 , F_16 ( V_14 ) ) ;
} else {
F_6 () ;
F_3 () ;
}
F_18 () ;
F_19 () ;
}
