static int F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_5 , false ,
& V_6 ) ;
if ( V_2 == NULL )
return - 1 ;
if ( V_7 )
F_3 ( V_2 , & V_6 ) ;
F_4 ( V_2 , stdout , V_7 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_6 ( int V_8 , const char * * V_9 , const char * T_1 V_10 )
{
V_8 = F_7 ( V_8 , V_9 , V_11 , V_12 , 0 ) ;
F_8 () ;
return F_1 () ;
}
