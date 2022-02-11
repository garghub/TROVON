static T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else
return ( NULL ) ;
}
T_1 * F_2 ( void )
{
static int V_3 = 1 ;
static T_1 V_4 ;
if ( V_3 )
{
memcpy ( ( char * ) & V_4 , ( char * ) F_3 () ,
sizeof( T_1 ) ) ;
V_4 . V_5 = V_6 ;
V_4 . V_7 = F_1 ;
V_3 = 0 ;
}
return ( & V_4 ) ;
}
