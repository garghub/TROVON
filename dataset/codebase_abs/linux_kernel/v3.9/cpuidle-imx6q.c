static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_6 = V_2 -> V_6 ;
F_2 ( V_7 , & V_6 ) ;
if ( F_3 ( & V_8 ) == F_4 () ) {
if ( ! F_5 ( & V_9 ) )
goto V_10;
F_6 ( V_11 ) ;
F_7 () ;
F_6 ( V_12 ) ;
F_8 ( & V_9 ) ;
goto V_13;
}
V_10:
F_7 () ;
V_13:
F_9 ( & V_8 ) ;
F_2 ( V_14 , & V_6 ) ;
return V_5 ;
}
static void F_10 ( void * V_15 )
{
int V_6 = F_11 () ;
F_2 ( V_16 , & V_6 ) ;
}
int T_1 F_12 ( void )
{
F_13 () ;
F_14 () ;
F_15 ( F_10 , NULL , 1 ) ;
return F_16 ( & V_17 ) ;
}
