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
assert ( F_3 ( V_6 , V_8 , V_9 , & V_10 [ 4 ] ,
sizeof( V_11 ) ) == 0 ) ;
if ( V_1 > 1 )
V_4 = F_4 ( L_4 , L_5 ) ;
else
V_4 = F_4 ( L_6 , L_5 ) ;
( void ) V_4 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
struct V_12 V_13 = {} , V_14 ;
struct V_15 V_16 ;
F_5 ( 1 ) ;
printf ( L_7 ) ;
while ( F_6 ( V_17 [ 2 ] , & V_13 , & V_14 ) == 0 ) {
F_7 ( V_17 [ 2 ] , & V_14 , & V_16 ) ;
printf ( L_8 ,
inet_ntoa((struct in_addr){htonl(next_key.src)}),
next_key.port16[0],
inet_ntoa((struct in_addr){htonl(next_key.dst)}),
next_key.port16[1],
value.bytes, value.packets) ;
V_13 = V_14 ;
}
}
return 0 ;
}
