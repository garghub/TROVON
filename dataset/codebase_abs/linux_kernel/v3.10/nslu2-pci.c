void T_1 F_1 ( void )
{
F_2 ( F_3 ( V_1 ) , V_2 ) ;
F_2 ( F_3 ( V_3 ) , V_2 ) ;
F_2 ( F_3 ( V_4 ) , V_2 ) ;
F_4 () ;
}
static int T_1 F_5 ( const struct V_5 * V_6 , T_2 V_7 , T_2 V_8 )
{
static int V_9 [ V_10 ] = {
F_3 ( V_1 ) ,
F_3 ( V_3 ) ,
F_3 ( V_4 ) ,
} ;
if ( V_7 >= 1 && V_7 <= V_11 && V_8 >= 1 && V_8 <= V_10 )
return V_9 [ ( V_7 + V_8 - 2 ) % V_10 ] ;
return - 1 ;
}
int T_1 F_6 ( void )
{
if ( F_7 () )
F_8 ( & V_12 ) ;
return 0 ;
}
