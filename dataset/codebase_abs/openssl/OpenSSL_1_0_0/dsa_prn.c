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
int F_8 ( T_1 * V_1 , const T_2 * V_2 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_9 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_9 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_6 ( T_3 * V_10 , const T_2 * V_2 , int V_3 )
{
T_4 * V_11 ;
int V_5 ;
V_11 = F_10 () ;
if ( ! V_11 || ! F_11 ( V_11 , ( T_2 * ) V_2 ) )
return 0 ;
V_5 = F_12 ( V_10 , V_11 , V_3 , NULL ) ;
F_13 ( V_11 ) ;
return V_5 ;
}
int F_9 ( T_3 * V_10 , const T_2 * V_2 )
{
T_4 * V_11 ;
int V_5 ;
V_11 = F_10 () ;
if ( ! V_11 || ! F_11 ( V_11 , ( T_2 * ) V_2 ) )
return 0 ;
V_5 = F_14 ( V_10 , V_11 , 4 , NULL ) ;
F_13 ( V_11 ) ;
return V_5 ;
}
