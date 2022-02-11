int F_1 ( T_1 * V_1 , const T_2 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_6 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_6 ( V_4 , V_2 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_6 ( T_3 * V_9 , const T_2 * V_2 , int V_3 )
{
T_4 * V_10 ;
int V_5 ;
V_10 = F_8 () ;
if ( ! V_10 || ! F_9 ( V_10 , ( T_2 * ) V_2 ) )
return 0 ;
V_5 = F_10 ( V_9 , V_10 , V_3 , NULL ) ;
F_11 ( V_10 ) ;
return V_5 ;
}
