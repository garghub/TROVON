const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , const unsigned char * V_3 ,
const unsigned char * V_4 , int V_5 )
{
return 1 ;
}
static int F_3 ( T_2 * V_2 , unsigned char * V_6 ,
const unsigned char * V_7 , unsigned int V_8 )
{
if ( V_7 != V_6 )
memcpy ( ( char * ) V_6 , ( char * ) V_7 , ( int ) V_8 ) ;
return 1 ;
}
