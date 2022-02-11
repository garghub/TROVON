int main ( int V_1 , char * * V_2 )
{
struct V_3 V_4 = { V_5 , V_5 } ;
char V_6 [ 256 ] ;
T_1 * V_7 ;
int V_8 , V_9 ;
snprintf ( V_6 , sizeof( V_6 ) , L_1 , V_2 [ 0 ] ) ;
F_1 ( V_10 , & V_4 ) ;
if ( F_2 ( V_6 ) ) {
printf ( L_2 , V_11 ) ;
return 1 ;
}
V_9 = F_3 ( L_3 ) ;
assert ( F_4 ( V_9 , V_12 , V_13 , V_14 ,
sizeof( V_14 [ 0 ] ) ) == 0 ) ;
V_7 = F_5 ( L_4 , L_5 ) ;
( void ) V_7 ;
for ( V_8 = 0 ; V_8 < 5 ; V_8 ++ ) {
int V_15 = 0 , V_16 ;
struct V_17 V_18 ;
while ( F_6 ( V_19 [ 0 ] , & V_15 , & V_16 ) == 0 ) {
F_7 ( V_19 [ 0 ] , & V_16 , & V_18 ) ;
printf ( L_6 ,
inet_ntoa((struct in_addr){htonl(next_key)}),
value.bytes, value.packets) ;
V_15 = V_16 ;
}
F_8 ( 1 ) ;
}
return 0 ;
}
