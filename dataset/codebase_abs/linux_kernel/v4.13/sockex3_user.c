int main ( int V_1 , char * * V_2 )
{
struct V_3 V_4 = { V_5 , V_5 } ;
char V_6 [ 256 ] ;
T_1 * V_7 ;
int V_8 , V_9 , V_10 , V_11 , V_12 = V_13 ;
struct V_14 V_15 = {} ;
T_2 V_16 = sizeof( V_15 ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_1 , V_2 [ 0 ] ) ;
F_1 ( V_17 , & V_4 ) ;
if ( F_2 ( V_6 ) ) {
printf ( L_2 , V_18 ) ;
return 1 ;
}
V_10 = F_3 ( V_19 , & V_15 , & V_16 ) ;
assert ( ! V_10 ) ;
V_10 = F_4 ( V_20 , & V_12 , & V_11 ) ;
assert ( ! V_10 ) ;
assert ( V_11 == V_15 . V_11 ) ;
V_9 = F_5 ( L_3 ) ;
assert ( F_6 ( V_9 , V_21 , V_22 , & V_23 [ 4 ] ,
sizeof( V_24 ) ) == 0 ) ;
if ( V_1 > 1 )
V_7 = F_7 ( L_4 , L_5 ) ;
else
V_7 = F_7 ( L_6 , L_5 ) ;
( void ) V_7 ;
for ( V_8 = 0 ; V_8 < 5 ; V_8 ++ ) {
struct V_25 V_12 = {} , V_26 ;
struct V_27 V_28 ;
F_8 ( 1 ) ;
printf ( L_7 ) ;
while ( F_9 ( V_29 [ 2 ] , & V_12 , & V_26 ) == 0 ) {
F_4 ( V_29 [ 2 ] , & V_26 , & V_28 ) ;
printf ( L_8 ,
inet_ntoa((struct in_addr){htonl(next_key.src)}),
next_key.port16[0],
inet_ntoa((struct in_addr){htonl(next_key.dst)}),
next_key.port16[1],
value.bytes, value.packets) ;
V_12 = V_26 ;
}
}
return 0 ;
}
