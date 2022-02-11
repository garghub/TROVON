void T_1 F_1 ( void )
{
F_2 ( F_3 ( V_1 ) , V_2 ) ;
F_2 ( F_3 ( V_3 ) , V_2 ) ;
F_2 ( F_3 ( V_4 ) , V_2 ) ;
F_2 ( F_3 ( V_5 ) , V_2 ) ;
F_2 ( F_3 ( V_6 ) , V_2 ) ;
F_4 () ;
}
static int T_1 F_5 ( const struct V_7 * V_8 , T_2 V_9 , T_2 V_10 )
{
static int V_11 [ V_12 ] [ V_13 ] = {
{ F_3 ( V_1 ) , - 1 , - 1 } ,
{ F_3 ( V_3 ) , - 1 , - 1 } ,
{ F_3 ( V_4 ) , F_3 ( V_5 ) ,
F_3 (INTE) } ,
} ;
if ( V_9 >= 1 && V_9 <= V_12 && V_10 >= 1 && V_10 <= V_13 )
return V_11 [ V_9 - 1 ] [ V_10 - 1 ] ;
return - 1 ;
}
int T_1 F_6 ( void )
{
if ( F_7 () )
F_8 ( & V_14 ) ;
return 0 ;
}
