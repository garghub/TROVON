void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , int * V_6 ,
int V_7 , T_2 V_8 )
{
unsigned int V_9 ;
T_1 V_10 = 0 ;
assert ( V_1 && V_2 && V_4 && V_5 && V_6 ) ;
V_9 = * V_6 ;
if ( V_7 ) {
#if ! F_2 ( V_11 )
if ( 16 % sizeof( T_1 ) == 0 ) do {
while ( V_9 && V_3 ) {
* ( V_2 ++ ) = V_5 [ V_9 ] ^= * ( V_1 ++ ) ;
-- V_3 ;
V_9 = ( V_9 + 1 ) % 16 ;
}
#if F_2 ( V_12 )
if ( ( ( T_1 ) V_1 | ( T_1 ) V_2 | ( T_1 ) V_5 ) % sizeof( T_1 ) != 0 )
break;
#endif
while ( V_3 >= 16 ) {
(* V_8)( V_5 , V_5 , V_4 ) ;
for (; V_9 < 16 ; V_9 += sizeof( T_1 ) ) {
* ( T_1 * ) ( V_2 + V_9 ) =
* ( T_1 * ) ( V_5 + V_9 ) ^= * ( T_1 * ) ( V_1 + V_9 ) ;
}
V_3 -= 16 ;
V_2 += 16 ;
V_1 += 16 ;
V_9 = 0 ;
}
if ( V_3 ) {
(* V_8)( V_5 , V_5 , V_4 ) ;
while ( V_3 -- ) {
V_2 [ V_9 ] = V_5 [ V_9 ] ^= V_1 [ V_9 ] ;
++ V_9 ;
}
}
* V_6 = V_9 ;
return;
} while ( 0 );
#endif
while ( V_10 < V_3 ) {
if ( V_9 == 0 ) {
(* V_8)( V_5 , V_5 , V_4 ) ;
}
V_2 [ V_10 ] = V_5 [ V_9 ] ^= V_1 [ V_10 ] ;
++ V_10 ;
V_9 = ( V_9 + 1 ) % 16 ;
}
* V_6 = V_9 ;
} else {
#if ! F_2 ( V_11 )
if ( 16 % sizeof( T_1 ) == 0 ) do {
while ( V_9 && V_3 ) {
unsigned char V_13 ;
* ( V_2 ++ ) = V_5 [ V_9 ] ^ ( V_13 = * ( V_1 ++ ) ) ; V_5 [ V_9 ] = V_13 ;
-- V_3 ;
V_9 = ( V_9 + 1 ) % 16 ;
}
#if F_2 ( V_12 )
if ( ( ( T_1 ) V_1 | ( T_1 ) V_2 | ( T_1 ) V_5 ) % sizeof( T_1 ) != 0 )
break;
#endif
while ( V_3 >= 16 ) {
(* V_8)( V_5 , V_5 , V_4 ) ;
for (; V_9 < 16 ; V_9 += sizeof( T_1 ) ) {
T_1 V_14 = * ( T_1 * ) ( V_1 + V_9 ) ;
* ( T_1 * ) ( V_2 + V_9 ) = * ( T_1 * ) ( V_5 + V_9 ) ^ V_14 ;
* ( T_1 * ) ( V_5 + V_9 ) = V_14 ;
}
V_3 -= 16 ;
V_2 += 16 ;
V_1 += 16 ;
V_9 = 0 ;
}
if ( V_3 ) {
(* V_8)( V_5 , V_5 , V_4 ) ;
while ( V_3 -- ) {
unsigned char V_13 ;
V_2 [ V_9 ] = V_5 [ V_9 ] ^ ( V_13 = V_1 [ V_9 ] ) ; V_5 [ V_9 ] = V_13 ;
++ V_9 ;
}
}
* V_6 = V_9 ;
return;
} while ( 0 );
#endif
while ( V_10 < V_3 ) {
unsigned char V_13 ;
if ( V_9 == 0 ) {
(* V_8)( V_5 , V_5 , V_4 ) ;
}
V_2 [ V_10 ] = V_5 [ V_9 ] ^ ( V_13 = V_1 [ V_10 ] ) ; V_5 [ V_9 ] = V_13 ;
++ V_10 ;
V_9 = ( V_9 + 1 ) % 16 ;
}
* V_6 = V_9 ;
}
}
static void F_3 ( const unsigned char * V_1 , unsigned char * V_2 ,
int V_15 , const void * V_4 ,
unsigned char V_5 [ 16 ] , int V_7 ,
T_2 V_8 )
{
int V_9 , V_16 , V_6 ;
unsigned char V_17 [ 16 * 2 + 1 ] ;
if ( V_15 <= 0 || V_15 > 128 ) return;
memcpy ( V_17 , V_5 , 16 ) ;
(* V_8)( V_5 , V_5 , V_4 ) ;
V_6 = ( V_15 + 7 ) / 8 ;
if ( V_7 )
for( V_9 = 0 ; V_9 < V_6 ; ++ V_9 )
V_2 [ V_9 ] = ( V_17 [ 16 + V_9 ] = V_1 [ V_9 ] ^ V_5 [ V_9 ] ) ;
else
for( V_9 = 0 ; V_9 < V_6 ; ++ V_9 )
V_2 [ V_9 ] = ( V_17 [ 16 + V_9 ] = V_1 [ V_9 ] ) ^ V_5 [ V_9 ] ;
V_16 = V_15 % 8 ;
V_6 = V_15 / 8 ;
if( V_16 == 0 )
memcpy ( V_5 , V_17 + V_6 , 16 ) ;
else
for( V_9 = 0 ; V_9 < 16 ; ++ V_9 )
V_5 [ V_9 ] = V_17 [ V_9 + V_6 ] << V_16 | V_17 [ V_9 + V_6 + 1 ] >> ( 8 - V_16 ) ;
}
void F_4 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_18 , const void * V_4 ,
unsigned char V_5 [ 16 ] , int * V_6 ,
int V_7 , T_2 V_8 )
{
T_1 V_9 ;
unsigned char V_13 [ 1 ] , V_19 [ 1 ] ;
assert ( V_1 && V_2 && V_4 && V_5 && V_6 ) ;
assert ( * V_6 == 0 ) ;
for( V_9 = 0 ; V_9 < V_18 ; ++ V_9 )
{
V_13 [ 0 ] = ( V_1 [ V_9 / 8 ] & ( 1 << ( 7 - V_9 % 8 ) ) ) ? 0x80 : 0 ;
F_3 ( V_13 , V_19 , 1 , V_4 , V_5 , V_7 , V_8 ) ;
V_2 [ V_9 / 8 ] = ( V_2 [ V_9 / 8 ] & ~ ( 1 << ( unsigned int ) ( 7 - V_9 % 8 ) ) ) |
( ( V_19 [ 0 ] & 0x80 ) >> ( unsigned int ) ( V_9 % 8 ) ) ;
}
}
void F_5 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_20 , const void * V_4 ,
unsigned char V_5 [ 16 ] , int * V_6 ,
int V_7 , T_2 V_8 )
{
T_1 V_9 ;
assert ( V_1 && V_2 && V_4 && V_5 && V_6 ) ;
assert ( * V_6 == 0 ) ;
for( V_9 = 0 ; V_9 < V_20 ; ++ V_9 )
F_3 ( & V_1 [ V_9 ] , & V_2 [ V_9 ] , 8 , V_4 , V_5 , V_7 , V_8 ) ;
}
