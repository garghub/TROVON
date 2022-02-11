int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
char V_4 [ 256 ] ;
snprintf ( V_4 , sizeof( V_4 ) , L_1 , V_2 [ 0 ] ) ;
if ( F_1 ( V_4 ) ) {
printf ( L_2 , V_5 ) ;
return 1 ;
}
V_3 = F_2 ( L_3 , L_4 ) ;
( void ) V_3 ;
F_3 () ;
return 0 ;
}
