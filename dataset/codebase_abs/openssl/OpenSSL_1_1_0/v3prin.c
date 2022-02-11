int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 ;
int V_5 , V_6 ;
T_3 * V_7 ;
F_1 () ;
F_2 () ;
if ( ! V_2 [ 1 ] ) {
fprintf ( V_8 , L_1 ) ;
exit ( 1 ) ;
}
if ( ( V_4 = fopen ( V_2 [ 1 ] , L_2 ) ) == NULL ) {
fprintf ( V_8 , L_3 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
if ( ( V_3 = F_3 ( V_4 , NULL , NULL ) ) == NULL ) {
fprintf ( V_8 , L_4 , V_2 [ 1 ] ) ;
F_4 ( V_8 ) ;
exit ( 1 ) ;
}
fclose ( V_4 ) ;
V_6 = F_5 ( V_3 ) ;
printf ( L_5 , V_6 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_7 = F_6 ( V_3 , V_5 ) ;
printf ( L_6 , F_7 ( F_8 ( V_7 -> V_9 ) ) ) ;
if ( ! F_9 ( stdout , V_7 , 0 , 0 ) )
F_4 ( V_8 ) ;
printf ( L_7 ) ;
}
return 0 ;
}
