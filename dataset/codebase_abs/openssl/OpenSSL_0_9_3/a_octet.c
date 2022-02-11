int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
return ( F_2 ( ( V_3 * ) V_1 , V_2 ,
V_4 , V_5 ) ) ;
}
T_1 * F_3 ( T_1 * * V_1 ,
unsigned char * * V_2 , long V_6 )
{
T_1 * V_7 = NULL ;
V_7 = ( T_1 * ) F_4 ( ( V_3 * * ) V_1 ,
V_2 , V_6 , V_4 , V_5 ) ;
if ( V_7 == NULL )
{
F_5 ( V_8 , V_9 ) ;
return ( NULL ) ;
}
return ( V_7 ) ;
}
