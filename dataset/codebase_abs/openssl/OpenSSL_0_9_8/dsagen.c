int F_1 ( int V_1 , int V_2 )
{
char V_3 = '*' ;
if ( V_1 == 0 ) V_3 = '.' ;
if ( V_1 == 1 ) V_3 = '+' ;
if ( V_1 == 2 ) V_3 = '*' ;
if ( V_1 == 3 ) V_3 = '\n' ;
printf ( L_1 , V_3 ) ;
fflush ( stdout ) ;
}
main ()
{
int V_4 ;
T_1 * V_2 ;
T_2 * V_5 ;
unsigned char V_6 [ 20 ] ;
T_3 * V_7 ;
int V_8 , V_9 ;
T_4 * V_10 = NULL ;
if ( V_10 == NULL )
V_10 = F_2 ( V_11 , V_12 ) ;
memcpy ( V_6 , V_13 , 20 ) ;
V_7 = F_3 ( 1024 , V_13 , 20 , & V_8 , & V_9 , F_1 , V_10 ) ;
if ( V_7 == NULL )
F_4 ( V_10 , V_7 , 0 ) ;
}
