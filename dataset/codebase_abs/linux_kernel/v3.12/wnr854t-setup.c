static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 ) ;
F_4 ( & V_2 ) ;
F_5 ( & V_3 , V_4 ) ;
F_6 () ;
F_7 ( V_5 ,
V_6 ,
V_7 ,
V_8 ) ;
F_8 ( & V_9 ) ;
}
static int T_1 F_9 ( const struct V_10 * V_11 , T_2 V_12 ,
T_2 V_13 )
{
int V_14 ;
V_14 = F_10 ( V_11 , V_12 , V_13 ) ;
if ( V_14 != - 1 )
return V_14 ;
if ( V_12 == 7 )
return F_11 ( 4 ) ;
return - 1 ;
}
static int T_1 F_12 ( void )
{
if ( F_13 () )
F_14 ( & V_15 ) ;
return 0 ;
}
