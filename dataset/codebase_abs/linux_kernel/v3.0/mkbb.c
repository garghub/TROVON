int main ( int V_1 , char * * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
int V_5 , V_6 ;
int V_7 ;
int V_8 ;
if( V_1 != 3 ) {
fprintf ( V_9 , L_1 , V_2 [ 0 ] ) ;
exit ( 0 ) ;
}
V_5 = F_1 ( V_2 [ 1 ] , V_10 ) ;
if( V_5 < 0 ) {
perror ( V_2 [ 1 ] ) ;
exit ( 0 ) ;
}
V_6 = F_1 ( V_2 [ 2 ] , V_11 ) ;
if( V_6 < 0 ) {
perror ( V_2 [ 2 ] ) ;
F_2 ( V_5 ) ;
exit ( 0 ) ;
}
V_8 = F_3 ( V_6 , & V_4 , sizeof( T_1 ) ) ;
if( V_8 != sizeof( T_1 ) ) {
perror ( L_2 ) ;
fprintf ( V_9 , L_3 , sizeof( T_1 ) , V_8 ) ;
exit ( 0 ) ;
}
V_8 = F_3 ( V_5 , & V_3 , sizeof( T_1 ) ) ;
if( V_8 != sizeof( T_1 ) ) {
perror ( L_4 ) ;
fprintf ( V_9 , L_3 , sizeof( T_1 ) , V_8 ) ;
exit ( 0 ) ;
}
V_4 . V_12 = V_3 . V_12 ;
V_4 . V_13 = 0 ;
for( V_7 = 0 ; V_7 < 63 ; V_7 ++ ) {
V_4 . V_13 +=
V_4 . V_14 [ V_7 ] ;
}
F_4 ( V_5 , 0L , V_15 ) ;
if( F_5 ( V_5 , & V_4 , sizeof( T_1 ) ) != sizeof( T_1 ) ) {
perror ( L_5 ) ;
exit ( 0 ) ;
}
F_2 ( V_6 ) ;
F_2 ( V_5 ) ;
exit ( 0 ) ;
}
