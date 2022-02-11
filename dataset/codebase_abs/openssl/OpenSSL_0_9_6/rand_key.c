void F_1 ( T_1 * V_1 )
{
F_2 ( V_1 , sizeof( T_1 ) ) ;
}
int F_3 ( T_1 * V_2 )
{
do
{
if ( F_4 ( ( unsigned char * ) V_2 , sizeof( T_1 ) ) != 1 )
return ( 0 ) ;
} while ( F_5 ( V_2 ) );
F_6 ( V_2 ) ;
return ( 1 ) ;
}
