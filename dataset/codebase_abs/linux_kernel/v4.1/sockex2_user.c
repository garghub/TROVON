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
int V_11 = 0 , V_12 ;
struct V_13 V_14 ;
while ( F_5 ( V_15 [ 0 ] , & V_11 , & V_12 ) == 0 ) {
F_6 ( V_15 [ 0 ] , & V_12 , & V_14 ) ;
printf ( L_6 ,
inet_ntoa((struct in_addr){htonl(next_key)}),
value.bytes, value.packets) ;
V_11 = V_12 ;
}
F_7 ( 1 ) ;
}
return 0 ;
}
