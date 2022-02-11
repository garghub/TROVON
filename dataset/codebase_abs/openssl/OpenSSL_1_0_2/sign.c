int main ()
{
int V_1 ;
int V_2 ;
unsigned char V_3 [ 4096 ] ;
static char V_4 [] = L_1 ;
static char V_5 [] = L_2 ;
static char V_6 [] = L_3 ;
T_1 V_7 ;
T_2 * V_8 ;
T_3 * V_9 ;
T_4 * V_10 ;
F_1 () ;
V_9 = fopen ( V_5 , L_4 ) ;
if ( V_9 == NULL )
exit ( 1 ) ;
V_8 = F_2 ( V_9 , NULL , NULL , NULL ) ;
fclose ( V_9 ) ;
if ( V_8 == NULL ) {
F_3 ( V_11 ) ;
exit ( 1 ) ;
}
F_4 ( & V_7 , F_5 () ) ;
F_6 ( & V_7 , V_6 , strlen ( V_6 ) ) ;
V_2 = sizeof( V_3 ) ;
V_1 = F_7 ( & V_7 , V_3 , & V_2 , V_8 ) ;
if ( V_1 != 1 ) {
F_3 ( V_11 ) ;
exit ( 1 ) ;
}
F_8 ( V_8 ) ;
V_9 = fopen ( V_4 , L_4 ) ;
if ( V_9 == NULL )
exit ( 1 ) ;
V_10 = F_9 ( V_9 , NULL , NULL , NULL ) ;
fclose ( V_9 ) ;
if ( V_10 == NULL ) {
F_3 ( V_11 ) ;
exit ( 1 ) ;
}
V_8 = F_10 ( V_10 ) ;
if ( V_8 == NULL ) {
F_3 ( V_11 ) ;
exit ( 1 ) ;
}
F_11 ( & V_7 , F_5 () ) ;
F_12 ( & V_7 , V_6 , strlen ( ( char * ) V_6 ) ) ;
V_1 = F_13 ( & V_7 , V_3 , V_2 , V_8 ) ;
F_8 ( V_8 ) ;
if ( V_1 != 1 ) {
F_3 ( V_11 ) ;
exit ( 1 ) ;
}
printf ( L_5 ) ;
return ( 0 ) ;
}
