static void F_1 ( void )
{
struct V_1 V_2 [] = {
F_2 ( V_3 + V_4 , V_5 ) ,
} ;
struct V_6 V_7 = {
. V_8 = ( unsigned short ) ( sizeof( V_2 ) / sizeof( V_2 [ 0 ] ) ) ,
. V_2 = V_2 ,
} ;
if ( F_3 ( V_9 , 2 , & V_7 ) )
perror ( L_1 ) ;
}
int main ( int V_10 , char * * V_11 )
{
T_1 * V_12 ;
char V_13 [ 256 ] ;
struct V_14 V_15 = { V_16 , V_16 } ;
snprintf ( V_13 , sizeof( V_13 ) , L_2 , V_11 [ 0 ] ) ;
F_4 ( V_17 , & V_15 ) ;
if ( F_5 ( V_13 ) ) {
printf ( L_3 , V_18 ) ;
return 1 ;
}
F_1 () ;
V_12 = F_6 ( L_4 , L_5 ) ;
( void ) V_12 ;
F_7 () ;
return 0 ;
}
