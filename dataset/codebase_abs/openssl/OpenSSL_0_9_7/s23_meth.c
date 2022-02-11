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
T_1 * F_5 ( void )
{
static int V_5 = 1 ;
static T_1 V_6 ;
if ( V_5 )
{
F_6 ( V_7 ) ;
if ( V_5 )
{
memcpy ( ( char * ) & V_6 , ( char * ) F_7 () ,
sizeof( T_1 ) ) ;
V_6 . V_8 = V_9 ;
V_6 . V_10 = V_11 ;
V_6 . V_12 = F_1 ;
V_5 = 0 ;
}
F_8 ( V_7 ) ;
}
return ( & V_6 ) ;
}
