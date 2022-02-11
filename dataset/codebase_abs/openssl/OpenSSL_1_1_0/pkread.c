int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 ;
T_3 * V_5 ;
F_1 ( T_3 ) * V_6 = NULL ;
T_4 * V_7 ;
int V_8 ;
if ( V_1 != 4 ) {
fprintf ( V_9 , L_1 ) ;
exit ( 1 ) ;
}
F_2 () ;
F_3 () ;
if ( ( V_3 = fopen ( V_2 [ 1 ] , L_2 ) ) == NULL ) {
fprintf ( V_9 , L_3 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
V_7 = F_4 ( V_3 , NULL ) ;
fclose ( V_3 ) ;
if ( ! V_7 ) {
fprintf ( V_9 , L_4 ) ;
F_5 ( V_9 ) ;
exit ( 1 ) ;
}
if ( ! F_6 ( V_7 , V_2 [ 2 ] , & V_4 , & V_5 , & V_6 ) ) {
fprintf ( V_9 , L_5 ) ;
F_5 ( V_9 ) ;
exit ( 1 ) ;
}
F_7 ( V_7 ) ;
if ( ( V_3 = fopen ( V_2 [ 3 ] , L_6 ) ) == NULL ) {
fprintf ( V_9 , L_3 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
if ( V_4 ) {
fprintf ( V_3 , L_7 ) ;
F_8 ( V_3 , V_4 , NULL , NULL , 0 , NULL , NULL ) ;
}
if ( V_5 ) {
fprintf ( V_3 , L_8 ) ;
F_9 ( V_3 , V_5 ) ;
}
if ( V_6 && F_10 ( V_6 ) ) {
fprintf ( V_3 , L_9 ) ;
for ( V_8 = 0 ; V_8 < F_10 ( V_6 ) ; V_8 ++ )
F_9 ( V_3 , F_11 ( V_6 , V_8 ) ) ;
}
fclose ( V_3 ) ;
return 0 ;
}
