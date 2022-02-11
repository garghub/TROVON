T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( int V_2 , T_2 * * V_3 , const T_3 * V_4 )
{
if( V_2 == V_5 ) {
* V_3 = ( T_2 * ) F_3 () ;
if( * V_3 ) return 2 ;
return 0 ;
} else if( V_2 == V_6 ) {
F_4 ( ( V_7 * ) * V_3 ) ;
* V_3 = NULL ;
return 2 ;
}
return 1 ;
}
V_7 * F_5 ( V_7 * V_8 )
{
return F_6 ( F_7 ( V_9 ) , V_8 ) ;
}
