void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_2 V_6 )
{
T_1 V_7 ;
const unsigned char * V_8 = V_5 ;
#if ! F_2 ( V_9 )
if ( V_10 &&
( ( T_1 ) V_1 | ( T_1 ) V_2 | ( T_1 ) V_5 ) % sizeof( T_1 ) != 0 ) {
while ( V_3 >= 16 ) {
for ( V_7 = 0 ; V_7 < 16 ; ++ V_7 )
V_2 [ V_7 ] = V_1 [ V_7 ] ^ V_8 [ V_7 ] ;
(* V_6) ( V_2 , V_2 , V_4 ) ;
V_8 = V_2 ;
V_3 -= 16 ;
V_1 += 16 ;
V_2 += 16 ;
}
} else {
while ( V_3 >= 16 ) {
for ( V_7 = 0 ; V_7 < 16 ; V_7 += sizeof( T_1 ) )
* ( T_1 * ) ( V_2 + V_7 ) =
* ( T_1 * ) ( V_1 + V_7 ) ^ * ( T_1 * ) ( V_8 + V_7 ) ;
(* V_6) ( V_2 , V_2 , V_4 ) ;
V_8 = V_2 ;
V_3 -= 16 ;
V_1 += 16 ;
V_2 += 16 ;
}
}
#endif
while ( V_3 ) {
for ( V_7 = 0 ; V_7 < 16 && V_7 < V_3 ; ++ V_7 )
V_2 [ V_7 ] = V_1 [ V_7 ] ^ V_8 [ V_7 ] ;
for (; V_7 < 16 ; ++ V_7 )
V_2 [ V_7 ] = V_8 [ V_7 ] ;
(* V_6) ( V_2 , V_2 , V_4 ) ;
V_8 = V_2 ;
if ( V_3 <= 16 )
break;
V_3 -= 16 ;
V_1 += 16 ;
V_2 += 16 ;
}
memcpy ( V_5 , V_8 , 16 ) ;
}
void F_3 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_2 V_6 )
{
T_1 V_7 ;
union {
T_1 V_11 [ 16 / sizeof( T_1 ) ] ;
unsigned char V_12 [ 16 ] ;
} V_13 ;
#if ! F_2 ( V_9 )
if ( V_1 != V_2 ) {
const unsigned char * V_8 = V_5 ;
if ( V_10 &&
( ( T_1 ) V_1 | ( T_1 ) V_2 | ( T_1 ) V_5 ) % sizeof( T_1 ) != 0 ) {
while ( V_3 >= 16 ) {
(* V_6) ( V_1 , V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < 16 ; ++ V_7 )
V_2 [ V_7 ] ^= V_8 [ V_7 ] ;
V_8 = V_1 ;
V_3 -= 16 ;
V_1 += 16 ;
V_2 += 16 ;
}
} else if ( 16 % sizeof( T_1 ) == 0 ) {
while ( V_3 >= 16 ) {
T_1 * V_14 = ( T_1 * ) V_2 , * V_15 = ( T_1 * ) V_8 ;
(* V_6) ( V_1 , V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < 16 / sizeof( T_1 ) ; V_7 ++ )
V_14 [ V_7 ] ^= V_15 [ V_7 ] ;
V_8 = V_1 ;
V_3 -= 16 ;
V_1 += 16 ;
V_2 += 16 ;
}
}
memcpy ( V_5 , V_8 , 16 ) ;
} else {
if ( V_10 &&
( ( T_1 ) V_1 | ( T_1 ) V_2 | ( T_1 ) V_5 ) % sizeof( T_1 ) != 0 ) {
unsigned char V_12 ;
while ( V_3 >= 16 ) {
(* V_6) ( V_1 , V_13 . V_12 , V_4 ) ;
for ( V_7 = 0 ; V_7 < 16 ; ++ V_7 ) {
V_12 = V_1 [ V_7 ] ;
V_2 [ V_7 ] = V_13 . V_12 [ V_7 ] ^ V_5 [ V_7 ] ;
V_5 [ V_7 ] = V_12 ;
}
V_3 -= 16 ;
V_1 += 16 ;
V_2 += 16 ;
}
} else if ( 16 % sizeof( T_1 ) == 0 ) {
while ( V_3 >= 16 ) {
T_1 V_12 , * V_14 = ( T_1 * ) V_2 , * V_16 = ( T_1 * ) V_5 ;
const T_1 * V_17 = ( const T_1 * ) V_1 ;
(* V_6) ( V_1 , V_13 . V_12 , V_4 ) ;
for ( V_7 = 0 ; V_7 < 16 / sizeof( T_1 ) ; V_7 ++ ) {
V_12 = V_17 [ V_7 ] ;
V_14 [ V_7 ] = V_13 . V_11 [ V_7 ] ^ V_16 [ V_7 ] ;
V_16 [ V_7 ] = V_12 ;
}
V_3 -= 16 ;
V_1 += 16 ;
V_2 += 16 ;
}
}
}
#endif
while ( V_3 ) {
unsigned char V_12 ;
(* V_6) ( V_1 , V_13 . V_12 , V_4 ) ;
for ( V_7 = 0 ; V_7 < 16 && V_7 < V_3 ; ++ V_7 ) {
V_12 = V_1 [ V_7 ] ;
V_2 [ V_7 ] = V_13 . V_12 [ V_7 ] ^ V_5 [ V_7 ] ;
V_5 [ V_7 ] = V_12 ;
}
if ( V_3 <= 16 ) {
for (; V_7 < 16 ; ++ V_7 )
V_5 [ V_7 ] = V_1 [ V_7 ] ;
break;
}
V_3 -= 16 ;
V_1 += 16 ;
V_2 += 16 ;
}
}
