static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 ) ;
F_4 () ;
F_5 ( & V_2 ) ;
F_6 ( & V_3 ,
F_7 ( 8 ) ) ;
F_8 () ;
F_9 () ;
F_10 ( V_4 ,
V_5 ) ;
F_11 ( & V_6 ) ;
F_12 ( 0 , & V_7 , 1 ) ;
}
static int T_1
F_13 ( struct V_8 * V_9 , T_2 V_10 , T_2 V_11 )
{
int V_12 ;
V_12 = F_14 ( V_9 , V_10 , V_11 ) ;
if ( V_12 != - 1 )
return V_12 ;
if ( V_11 == 1 )
return F_7 ( 4 ) ;
else
return F_7 ( 10 ) ;
}
static int T_1 F_15 ( void )
{
if ( F_16 () ) {
F_17 () ;
F_18 ( & V_13 ) ;
}
return 0 ;
}
