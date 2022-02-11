static void F_1 ( unsigned char * V_1 ) {
T_1 V_2 , V_3 = 16 ;
do {
V_3 -= 4 ;
V_2 = F_2 ( V_1 + V_3 ) ;
++ V_2 ; V_2 &= 0xFFFFFFFF ;
F_3 ( V_1 + V_3 , V_2 ) ;
if ( V_2 ) return;
} while ( V_3 );
}
static void F_4 ( unsigned char * V_1 ) {
T_2 * V_4 , V_2 , V_3 ;
const union { long V_5 ; char V_6 ; } V_7 = { 1 } ;
if ( V_7 . V_6 ) {
F_1 ( V_1 ) ;
return;
}
V_4 = ( T_2 * ) V_1 ;
V_3 = 16 / sizeof( T_2 ) ;
do {
-- V_3 ;
V_2 = V_4 [ V_3 ] ;
++ V_2 ;
V_4 [ V_3 ] = V_2 ;
if ( V_2 ) return;
} while ( V_3 );
}
void F_5 ( const unsigned char * V_8 , unsigned char * V_9 ,
T_2 V_10 , const void * V_11 ,
unsigned char V_12 [ 16 ] , unsigned char V_13 [ 16 ] ,
unsigned int * V_14 , T_3 V_15 )
{
unsigned int V_3 ;
T_2 V_16 = 0 ;
assert ( V_8 && V_9 && V_11 && V_13 && V_14 ) ;
assert ( * V_14 < 16 ) ;
V_3 = * V_14 ;
#if ! F_6 ( V_17 )
if ( 16 % sizeof( T_2 ) == 0 ) do {
while ( V_3 && V_10 ) {
* ( V_9 ++ ) = * ( V_8 ++ ) ^ V_13 [ V_3 ] ;
-- V_10 ;
V_3 = ( V_3 + 1 ) % 16 ;
}
#if F_6 ( V_18 )
if ( ( ( T_2 ) V_8 | ( T_2 ) V_9 | ( T_2 ) V_12 ) % sizeof( T_2 ) != 0 )
break;
#endif
while ( V_10 >= 16 ) {
(* V_15)( V_12 , V_13 , V_11 ) ;
F_4 ( V_12 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 += sizeof( T_2 ) )
* ( T_2 * ) ( V_9 + V_3 ) =
* ( T_2 * ) ( V_8 + V_3 ) ^ * ( T_2 * ) ( V_13 + V_3 ) ;
V_10 -= 16 ;
V_9 += 16 ;
V_8 += 16 ;
}
V_3 = 0 ;
if ( V_10 ) {
(* V_15)( V_12 , V_13 , V_11 ) ;
F_4 ( V_12 ) ;
while ( V_10 -- ) {
V_9 [ V_3 ] = V_8 [ V_3 ] ^ V_13 [ V_3 ] ;
++ V_3 ;
}
}
* V_14 = V_3 ;
return;
} while( 0 );
#endif
while ( V_16 < V_10 ) {
if ( V_3 == 0 ) {
(* V_15)( V_12 , V_13 , V_11 ) ;
F_1 ( V_12 ) ;
}
V_9 [ V_16 ] = V_8 [ V_16 ] ^ V_13 [ V_3 ] ;
++ V_16 ;
V_3 = ( V_3 + 1 ) % 16 ;
}
* V_14 = V_3 ;
}
