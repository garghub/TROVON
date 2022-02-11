static void F_1 ( unsigned char * V_1 ) {
T_1 V_2 = 16 ;
T_2 V_3 ;
do {
-- V_2 ;
V_3 = V_1 [ V_2 ] ;
++ V_3 ;
V_1 [ V_2 ] = V_3 ;
if ( V_3 ) return;
} while ( V_2 );
}
static void F_2 ( unsigned char * V_1 ) {
T_3 * V_4 , V_3 , V_2 ;
const union { long V_5 ; char V_6 ; } V_7 = { 1 } ;
if ( V_7 . V_6 ) {
F_1 ( V_1 ) ;
return;
}
V_4 = ( T_3 * ) V_1 ;
V_2 = 16 / sizeof( T_3 ) ;
do {
-- V_2 ;
V_3 = V_4 [ V_2 ] ;
++ V_3 ;
V_4 [ V_2 ] = V_3 ;
if ( V_3 ) return;
} while ( V_2 );
}
void F_3 ( const unsigned char * V_8 , unsigned char * V_9 ,
T_3 V_10 , const void * V_11 ,
unsigned char V_12 [ 16 ] , unsigned char V_13 [ 16 ] ,
unsigned int * V_14 , T_4 V_15 )
{
unsigned int V_2 ;
T_3 V_16 = 0 ;
assert ( V_8 && V_9 && V_11 && V_13 && V_14 ) ;
assert ( * V_14 < 16 ) ;
V_2 = * V_14 ;
#if ! F_4 ( V_17 )
if ( 16 % sizeof( T_3 ) == 0 ) do {
while ( V_2 && V_10 ) {
* ( V_9 ++ ) = * ( V_8 ++ ) ^ V_13 [ V_2 ] ;
-- V_10 ;
V_2 = ( V_2 + 1 ) % 16 ;
}
#if F_4 ( V_18 )
if ( ( ( T_3 ) V_8 | ( T_3 ) V_9 | ( T_3 ) V_12 ) % sizeof( T_3 ) != 0 )
break;
#endif
while ( V_10 >= 16 ) {
(* V_15)( V_12 , V_13 , V_11 ) ;
F_2 ( V_12 ) ;
for (; V_2 < 16 ; V_2 += sizeof( T_3 ) )
* ( T_3 * ) ( V_9 + V_2 ) =
* ( T_3 * ) ( V_8 + V_2 ) ^ * ( T_3 * ) ( V_13 + V_2 ) ;
V_10 -= 16 ;
V_9 += 16 ;
V_8 += 16 ;
V_2 = 0 ;
}
if ( V_10 ) {
(* V_15)( V_12 , V_13 , V_11 ) ;
F_2 ( V_12 ) ;
while ( V_10 -- ) {
V_9 [ V_2 ] = V_8 [ V_2 ] ^ V_13 [ V_2 ] ;
++ V_2 ;
}
}
* V_14 = V_2 ;
return;
} while( 0 );
#endif
while ( V_16 < V_10 ) {
if ( V_2 == 0 ) {
(* V_15)( V_12 , V_13 , V_11 ) ;
F_1 ( V_12 ) ;
}
V_9 [ V_16 ] = V_8 [ V_16 ] ^ V_13 [ V_2 ] ;
++ V_16 ;
V_2 = ( V_2 + 1 ) % 16 ;
}
* V_14 = V_2 ;
}
static void F_5 ( unsigned char * V_1 ) {
T_1 V_2 = 12 ;
T_2 V_3 ;
do {
-- V_2 ;
V_3 = V_1 [ V_2 ] ;
++ V_3 ;
V_1 [ V_2 ] = V_3 ;
if ( V_3 ) return;
} while ( V_2 );
}
void F_6 ( const unsigned char * V_8 , unsigned char * V_9 ,
T_3 V_10 , const void * V_11 ,
unsigned char V_12 [ 16 ] , unsigned char V_13 [ 16 ] ,
unsigned int * V_14 , T_5 V_19 )
{
unsigned int V_2 , V_20 ;
assert ( V_8 && V_9 && V_11 && V_13 && V_14 ) ;
assert ( * V_14 < 16 ) ;
V_2 = * V_14 ;
while ( V_2 && V_10 ) {
* ( V_9 ++ ) = * ( V_8 ++ ) ^ V_13 [ V_2 ] ;
-- V_10 ;
V_2 = ( V_2 + 1 ) % 16 ;
}
V_20 = F_7 ( V_12 + 12 ) ;
while ( V_10 >= 16 ) {
T_3 V_21 = V_10 / 16 ;
if ( sizeof( T_3 ) >sizeof( unsigned int ) && V_21 > ( 1U << 28 ) )
V_21 = ( 1U << 28 ) ;
V_20 += ( T_1 ) V_21 ;
if ( V_20 < V_21 ) {
V_21 -= V_20 ;
V_20 = 0 ;
}
(* V_19)( V_8 , V_9 , V_21 , V_11 , V_12 ) ;
F_8 ( V_12 + 12 , V_20 ) ;
if ( V_20 == 0 ) F_5 ( V_12 ) ;
V_21 *= 16 ;
V_10 -= V_21 ;
V_9 += V_21 ;
V_8 += V_21 ;
}
if ( V_10 ) {
memset ( V_13 , 0 , 16 ) ;
(* V_19)( V_13 , V_13 , 1 , V_11 , V_12 ) ;
++ V_20 ;
F_8 ( V_12 + 12 , V_20 ) ;
if ( V_20 == 0 ) F_5 ( V_12 ) ;
while ( V_10 -- ) {
V_9 [ V_2 ] = V_8 [ V_2 ] ^ V_13 [ V_2 ] ;
++ V_2 ;
}
}
* V_14 = V_2 ;
}
