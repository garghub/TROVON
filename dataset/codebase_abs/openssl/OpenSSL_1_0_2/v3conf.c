int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 ;
T_3 * V_5 ;
char * V_6 ;
int V_7 ;
int V_8 ;
T_4 * V_9 ;
F_1 () ;
F_2 () ;
if ( ! V_2 [ 1 ] ) {
fprintf ( V_10 , L_1 ) ;
exit ( 1 ) ;
}
V_6 = V_2 [ 2 ] ;
if ( ! V_6 )
V_6 = L_2 ;
V_3 = F_3 ( NULL , L_2 , NULL ) ;
if ( ! V_3 ) {
fprintf ( V_10 , L_3 , V_6 ) ;
F_4 ( V_10 ) ;
exit ( 1 ) ;
}
V_5 = fopen ( V_2 [ 1 ] , L_4 ) ;
if ( ! V_5 ) {
fprintf ( V_10 , L_5 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
V_4 = F_5 ( V_5 , NULL , NULL ) ;
if ( ! V_4 ) {
fprintf ( V_10 , L_6 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
fclose ( V_5 ) ;
F_6 ( V_4 -> V_11 -> V_12 , V_13 ) ;
V_4 -> V_11 -> V_12 = NULL ;
if ( ! F_7 ( V_3 , NULL , L_7 , V_4 ) ) {
fprintf ( V_10 , L_8 ) ;
F_4 ( V_10 ) ;
exit ( 1 ) ;
}
V_8 = F_8 ( V_4 ) ;
printf ( L_9 , V_8 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_9 = F_9 ( V_4 , V_7 ) ;
printf ( L_10 , F_10 ( F_11 ( V_9 -> V_14 ) ) ) ;
if ( V_9 -> V_15 )
printf ( L_11 ) ;
else
printf ( L_12 ) ;
F_12 ( stdout , V_9 , 0 , 0 ) ;
printf ( L_13 ) ;
}
return 0 ;
}
