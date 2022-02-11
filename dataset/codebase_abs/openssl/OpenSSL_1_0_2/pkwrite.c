int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
if ( V_1 != 5 ) {
fprintf ( V_7 , L_1 ) ;
exit ( 1 ) ;
}
F_1 () ;
F_2 () ;
if ( ! ( V_3 = fopen ( V_2 [ 1 ] , L_2 ) ) ) {
fprintf ( V_7 , L_3 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
V_5 = F_3 ( V_3 , NULL , NULL , NULL ) ;
rewind ( V_3 ) ;
V_4 = F_4 ( V_3 , NULL , NULL , NULL ) ;
fclose ( V_3 ) ;
V_6 = F_5 ( V_2 [ 2 ] , V_2 [ 3 ] , V_4 , V_5 , NULL , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_6 ) {
fprintf ( V_7 , L_4 ) ;
F_6 ( V_7 ) ;
exit ( 1 ) ;
}
if ( ! ( V_3 = fopen ( V_2 [ 4 ] , L_5 ) ) ) {
fprintf ( V_7 , L_3 , V_2 [ 1 ] ) ;
F_6 ( V_7 ) ;
exit ( 1 ) ;
}
F_7 ( V_3 , V_6 ) ;
F_8 ( V_6 ) ;
fclose ( V_3 ) ;
return 0 ;
}
