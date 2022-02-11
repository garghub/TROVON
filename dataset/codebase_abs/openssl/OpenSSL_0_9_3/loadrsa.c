void F_1 ( T_1 , T_2 , T_3 )
int T_1 , T_2 ;
char * T_3 ;
{
T_4 * V_1 ;
V_1 = ( T_4 * ) T_3 ;
fprintf ( V_1 , L_1 , T_1 ) ;
if ( T_1 == 3 )
fprintf ( V_1 , L_2 ) ;
fflush ( V_1 ) ;
}
main ()
{
T_5 * V_2 , * V_3 , * V_4 ;
int V_5 ;
unsigned char V_6 [ 1024 ] , * V_7 ;
V_2 = F_2 ( 512 , V_8 , F_1 , ( char * ) stdout ) ;
V_7 = V_6 ;
V_5 = F_3 ( V_2 , & V_7 ) ;
V_5 += F_4 ( V_2 , & V_7 ) ;
printf ( L_3 ) ;
printf ( L_4 , V_5 ) ;
F_5 ( V_2 ) ;
V_7 = V_6 ;
V_3 = F_6 ( NULL , & V_7 , ( long ) V_5 ) ;
V_5 -= ( V_7 - V_6 ) ;
V_4 = F_7 ( NULL , & V_7 , ( long ) V_5 ) ;
if ( ( V_3 == NULL ) || ( V_4 == NULL ) )
F_8 ( V_9 ) ;
F_5 ( V_3 ) ;
F_5 ( V_4 ) ;
}
