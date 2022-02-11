T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
T_1 * F_5 ( T_1 * V_1 )
{ return F_6 ( V_1 ) ; }
int F_7 ( T_1 * V_2 , T_1 * V_3 )
{ return F_8 ( V_2 , V_3 ) ; }
int F_9 ( T_1 * V_1 , unsigned char * V_4 , int V_5 )
{ return F_10 ( V_1 , V_4 , V_5 ) ; }
int F_11 ( T_1 * V_2 , unsigned char * * V_6 )
{ return F_12 ( V_2 , V_6 ) ; }
T_1 * F_13 ( T_1 * * V_2 ,
unsigned char * * V_6 , long V_7 )
{
T_1 * V_8 = NULL ;
V_8 = ( T_1 * ) F_14 ( ( V_9 * * ) V_2 ,
V_6 , V_7 , V_10 , V_11 ) ;
if ( V_8 == NULL )
{
F_15 ( V_12 , V_13 ) ;
return ( NULL ) ;
}
return ( V_8 ) ;
}
