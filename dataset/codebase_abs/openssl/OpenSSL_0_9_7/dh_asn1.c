static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 )
{
if( V_1 == V_4 ) {
* V_2 = ( T_1 * ) F_2 () ;
if( * V_2 ) return 2 ;
return 0 ;
} else if( V_1 == V_5 ) {
F_3 ( ( V_6 * ) * V_2 ) ;
* V_2 = NULL ;
return 2 ;
}
return 1 ;
}
