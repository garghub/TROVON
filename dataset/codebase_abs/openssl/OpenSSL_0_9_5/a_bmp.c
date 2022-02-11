T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_2 , unsigned char * * V_3 )
{
return ( F_6 ( ( V_4 * ) V_2 , V_3 ,
V_5 , V_6 ) ) ;
}
T_1 * F_7 ( T_1 * * V_2 , unsigned char * * V_3 ,
long V_7 )
{
T_1 * V_8 = NULL ;
V_8 = ( T_1 * ) F_8 ( ( V_4 * * ) V_2 ,
V_3 , V_7 , V_5 , V_6 ) ;
if ( V_8 == NULL )
{
F_9 ( V_9 , V_10 ) ;
return ( NULL ) ;
}
return ( V_8 ) ;
}
