int main ( int V_1 , char * * V_2 )
{
char V_3 [ 256 ] ;
T_1 * V_4 ;
int V_5 , V_6 ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_2 [ 0 ] ) ;
if ( F_1 ( V_3 ) ) {
printf ( L_2 , V_7 ) ;
return 1 ;
}
V_6 = F_2 ( L_3 ) ;
assert ( F_3 ( V_6 , V_8 , V_9 , V_10 ,
sizeof( V_10 [ 0 ] ) ) == 0 ) ;
V_4 = F_4 ( L_4 , L_5 ) ;
( void ) V_4 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
long long V_11 , V_12 , V_13 ;
int V_14 ;
V_14 = V_15 ;
assert ( F_5 ( V_16 [ 0 ] , & V_14 , & V_11 ) == 0 ) ;
V_14 = V_17 ;
assert ( F_5 ( V_16 [ 0 ] , & V_14 , & V_12 ) == 0 ) ;
V_14 = V_18 ;
assert ( F_5 ( V_16 [ 0 ] , & V_14 , & V_13 ) == 0 ) ;
printf ( L_6 ,
V_11 , V_12 , V_13 ) ;
F_6 ( 1 ) ;
}
return 0 ;
}
