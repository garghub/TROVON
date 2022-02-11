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
if ( F_5 ( V_10 ) )
F_6 ( & V_11 ) ;
}
static void T_2 F_7 ( void )
{
unsigned int V_12 = 1 ;
if ( F_2 () )
V_12 = 2 ;
else if ( F_8 () )
V_12 = 0 ;
F_9 ( V_12 , L_1 ) ;
F_10 ( V_12 , 0 ) ;
F_11 ( V_12 , 1 ) ;
F_11 ( V_12 , 0 ) ;
F_12 ( 100 ) ;
F_11 ( V_12 , 1 ) ;
F_12 ( 100 ) ;
}
static void T_2 F_13 ( void )
{
F_14 () ;
if ( F_15 () ) {
F_4 ( V_9 , V_13 ) ;
F_16 ( V_14 , F_17 ( V_14 ) ) ;
F_18 ( V_15 , F_17 ( V_15 ) ) ;
} else {
F_7 () ;
F_3 () ;
}
F_19 () ;
F_20 () ;
}
