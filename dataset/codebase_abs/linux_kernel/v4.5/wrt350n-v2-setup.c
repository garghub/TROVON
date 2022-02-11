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
F_9 ( & V_10 ) ;
F_9 ( & V_11 ) ;
}
static int T_1 F_10 ( const struct V_12 * V_13 , T_2 V_14 ,
T_2 V_15 )
{
int V_16 ;
V_16 = F_11 ( V_13 , V_14 , V_15 ) ;
if ( V_16 != - 1 )
return V_16 ;
if ( V_14 == 7 )
return F_12 ( 4 ) ;
return - 1 ;
}
static int T_1 F_13 ( void )
{
if ( F_14 () )
F_15 ( & V_17 ) ;
return 0 ;
}
