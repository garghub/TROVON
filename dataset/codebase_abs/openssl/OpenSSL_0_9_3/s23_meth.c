static T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else if ( V_1 == V_3 )
return ( F_3 () ) ;
else if ( V_1 == V_4 )
return ( F_4 () ) ;
else
return ( NULL ) ;
}
T_1 * F_2 ( void )
{
static int V_5 = 1 ;
static T_1 V_6 ;
if ( V_5 )
{
memcpy ( ( char * ) & V_6 , ( char * ) F_5 () ,
sizeof( T_1 ) ) ;
V_6 . V_7 = V_8 ;
V_6 . V_9 = V_10 ;
V_6 . V_11 = F_1 ;
V_5 = 0 ;
}
return ( & V_6 ) ;
}
