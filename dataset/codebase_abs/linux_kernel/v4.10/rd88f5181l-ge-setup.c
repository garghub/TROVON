static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 ) ;
F_4 () ;
F_5 ( & V_2 ) ;
F_6 ( & V_3 ) ;
F_7 () ;
F_8 () ;
F_9 ( V_4 ,
V_5 ,
V_6 ,
V_7 ) ;
F_10 ( & V_8 ) ;
F_11 ( 0 , & V_9 , 1 ) ;
}
static int T_1
F_12 ( const struct V_10 * V_11 , T_2 V_12 , T_2 V_13 )
{
int V_14 ;
V_14 = F_13 ( V_11 , V_12 , V_13 ) ;
if ( V_14 != - 1 )
return V_14 ;
if ( V_13 == 1 )
return F_14 ( 4 ) ;
else
return F_14 ( 10 ) ;
}
static int T_1 F_15 ( void )
{
if ( F_16 () ) {
F_17 () ;
F_18 ( & V_15 ) ;
}
return 0 ;
}
