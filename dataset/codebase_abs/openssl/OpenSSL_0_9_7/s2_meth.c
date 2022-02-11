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
F_3 ( V_5 ) ;
if ( V_3 )
{
memcpy ( ( char * ) & V_4 , ( char * ) F_4 () ,
sizeof( T_1 ) ) ;
V_4 . V_6 = V_7 ;
V_4 . V_8 = V_9 ;
V_4 . V_10 = F_1 ;
V_3 = 0 ;
}
F_5 ( V_5 ) ;
}
return ( & V_4 ) ;
}
