T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , const unsigned char * V_3 ,
const unsigned char * V_4 , int V_5 )
{
memset ( & ( V_2 -> V_6 ) , 0 , sizeof( V_2 -> V_6 ) ) ;
return 1 ;
}
static int F_3 ( T_2 * V_2 , unsigned char * V_7 ,
const unsigned char * V_8 , unsigned int V_9 )
{
if ( V_8 != V_7 )
memcpy ( ( char * ) V_7 , ( char * ) V_8 , ( int ) V_9 ) ;
return 1 ;
}
