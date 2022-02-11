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
assert ( F_4 ( V_9 , V_12 , V_13 , & V_14 [ 4 ] ,
sizeof( V_15 ) ) == 0 ) ;
if ( V_1 > 1 )
V_7 = F_5 ( L_4 , L_5 ) ;
else
V_7 = F_5 ( L_6 , L_5 ) ;
( void ) V_7 ;
for ( V_8 = 0 ; V_8 < 5 ; V_8 ++ ) {
struct V_16 V_17 = {} , V_18 ;
struct V_19 V_20 ;
F_6 ( 1 ) ;
printf ( L_7 ) ;
while ( F_7 ( V_21 [ 2 ] , & V_17 , & V_18 ) == 0 ) {
F_8 ( V_21 [ 2 ] , & V_18 , & V_20 ) ;
printf ( L_8 ,
inet_ntoa((struct in_addr){htonl(next_key.src)}),
next_key.port16[0],
inet_ntoa((struct in_addr){htonl(next_key.dst)}),
next_key.port16[1],
value.bytes, value.packets) ;
V_17 = V_18 ;
}
}
return 0 ;
}
