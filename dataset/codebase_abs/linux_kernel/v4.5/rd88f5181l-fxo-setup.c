static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 ) ;
F_4 () ;
F_5 ( & V_2 ) ;
F_6 ( & V_3 , V_4 ) ;
F_7 () ;
F_8 ( V_5 ,
V_6 ,
V_7 ,
V_8 ) ;
F_9 ( & V_9 ) ;
}
static int T_1
F_10 ( const struct V_10 * V_11 , T_2 V_12 , T_2 V_13 )
{
int V_14 ;
V_14 = F_11 ( V_11 , V_12 , V_13 ) ;
if ( V_14 != - 1 )
return V_14 ;
return F_12 ( 1 ) ;
}
static int T_1 F_13 ( void )
{
if ( F_14 () ) {
F_15 () ;
F_16 ( & V_15 ) ;
}
return 0 ;
}
