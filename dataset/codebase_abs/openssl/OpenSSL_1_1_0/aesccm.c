void F_1 ( void )
{
T_1 * V_1 ;
int V_2 , V_3 ;
unsigned char V_4 [ 1024 ] ;
printf ( L_1 ) ;
printf ( L_2 ) ;
F_2 ( stdout , V_5 , sizeof( V_5 ) ) ;
V_1 = F_3 () ;
F_4 ( V_1 , F_5 () , NULL , NULL , NULL ) ;
F_6 ( V_1 , V_6 , sizeof( V_7 ) ,
NULL ) ;
F_6 ( V_1 , V_8 , sizeof( V_9 ) , NULL ) ;
F_4 ( V_1 , NULL , NULL , V_10 , V_7 ) ;
F_7 ( V_1 , NULL , & V_2 , NULL , sizeof( V_5 ) ) ;
F_7 ( V_1 , NULL , & V_2 , V_11 , sizeof( V_11 ) ) ;
F_7 ( V_1 , V_4 , & V_2 , V_5 , sizeof( V_5 ) ) ;
printf ( L_3 ) ;
F_2 ( stdout , V_4 , V_2 ) ;
F_8 ( V_1 , V_4 , & V_2 ) ;
F_6 ( V_1 , V_12 , 16 , V_4 ) ;
printf ( L_4 ) ;
F_2 ( stdout , V_4 , 16 ) ;
F_9 ( V_1 ) ;
}
void F_10 ( void )
{
T_1 * V_1 ;
int V_2 , V_3 , V_13 ;
unsigned char V_4 [ 1024 ] ;
printf ( L_5 ) ;
printf ( L_3 ) ;
F_2 ( stdout , V_14 , sizeof( V_14 ) ) ;
V_1 = F_3 () ;
F_11 ( V_1 , F_5 () , NULL , NULL , NULL ) ;
F_6 ( V_1 , V_6 , sizeof( V_7 ) ,
NULL ) ;
F_6 ( V_1 , V_8 ,
sizeof( V_9 ) , ( void * ) V_9 ) ;
F_11 ( V_1 , NULL , NULL , V_10 , V_7 ) ;
F_12 ( V_1 , NULL , & V_2 , NULL , sizeof( V_14 ) ) ;
F_12 ( V_1 , NULL , & V_2 , V_11 , sizeof( V_11 ) ) ;
V_13 = F_12 ( V_1 , V_4 , & V_2 , V_14 , sizeof( V_14 ) ) ;
if ( V_13 > 0 ) {
printf ( L_2 ) ;
F_2 ( stdout , V_4 , V_2 ) ;
} else
printf ( L_6 ) ;
F_9 ( V_1 ) ;
}
int main ( int V_15 , char * * V_16 )
{
F_1 () ;
F_10 () ;
}
