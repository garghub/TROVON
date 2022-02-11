void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , int * V_6 ,
T_2 V_7 )
{
unsigned int V_8 ;
T_1 V_9 = 0 ;
assert ( V_1 && V_2 && V_4 && V_5 && V_6 ) ;
V_8 = * V_6 ;
#if ! F_2 ( V_10 )
if ( 16 % sizeof( T_1 ) == 0 ) do {
while ( V_8 && V_3 ) {
* ( V_2 ++ ) = * ( V_1 ++ ) ^ V_5 [ V_8 ] ;
-- V_3 ;
V_8 = ( V_8 + 1 ) % 16 ;
}
#if F_2 ( V_11 )
if ( ( ( T_1 ) V_1 | ( T_1 ) V_2 | ( T_1 ) V_5 ) % sizeof( T_1 ) != 0 )
break;
#endif
while ( V_3 >= 16 ) {
(* V_7)( V_5 , V_5 , V_4 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 += sizeof( T_1 ) )
* ( T_1 * ) ( V_2 + V_8 ) =
* ( T_1 * ) ( V_1 + V_8 ) ^ * ( T_1 * ) ( V_5 + V_8 ) ;
V_3 -= 16 ;
V_2 += 16 ;
V_1 += 16 ;
}
V_8 = 0 ;
if ( V_3 ) {
(* V_7)( V_5 , V_5 , V_4 ) ;
while ( V_3 -- ) {
V_2 [ V_8 ] = V_1 [ V_8 ] ^ V_5 [ V_8 ] ;
++ V_8 ;
}
}
* V_6 = V_8 ;
return;
} while( 0 );
#endif
while ( V_9 < V_3 ) {
if ( V_8 == 0 ) {
(* V_7)( V_5 , V_5 , V_4 ) ;
}
V_2 [ V_9 ] = V_1 [ V_9 ] ^ V_5 [ V_8 ] ;
++ V_9 ;
V_8 = ( V_8 + 1 ) % 16 ;
}
* V_6 = V_8 ;
}
