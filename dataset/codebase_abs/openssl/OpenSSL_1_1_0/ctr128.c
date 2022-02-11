static void F_1 ( unsigned char * V_1 )
{
T_1 V_2 = 16 , V_3 = 1 ;
do {
-- V_2 ;
V_3 += V_1 [ V_2 ] ;
V_1 [ V_2 ] = ( V_4 ) V_3 ;
V_3 >>= 8 ;
} while ( V_2 );
}
static void F_2 ( unsigned char * V_1 )
{
T_2 * V_5 , V_3 , V_6 , V_2 ;
const union {
long V_7 ;
char V_8 ;
} V_9 = {
1
} ;
if ( V_9 . V_8 || ( ( T_2 ) V_1 % sizeof( T_2 ) ) != 0 ) {
F_1 ( V_1 ) ;
return;
}
V_5 = ( T_2 * ) V_1 ;
V_3 = 1 ;
V_2 = 16 / sizeof( T_2 ) ;
do {
-- V_2 ;
V_6 = V_5 [ V_2 ] += V_3 ;
V_3 = ( ( V_6 - V_3 ) ^ V_6 ) >> ( sizeof( T_2 ) * 8 - 1 ) ;
} while ( V_2 );
}
void F_3 ( const unsigned char * V_10 , unsigned char * V_11 ,
T_2 V_12 , const void * V_13 ,
unsigned char V_14 [ 16 ] ,
unsigned char V_15 [ 16 ] , unsigned int * V_16 ,
T_3 V_17 )
{
unsigned int V_2 ;
T_2 V_18 = 0 ;
V_2 = * V_16 ;
#if ! F_4 ( V_19 )
if ( 16 % sizeof( T_2 ) == 0 ) {
do {
while ( V_2 && V_12 ) {
* ( V_11 ++ ) = * ( V_10 ++ ) ^ V_15 [ V_2 ] ;
-- V_12 ;
V_2 = ( V_2 + 1 ) % 16 ;
}
# if F_4 ( V_20 )
if ( ( ( T_2 ) V_10 | ( T_2 ) V_11 | ( T_2 ) V_15 )
% sizeof( T_2 ) != 0 )
break;
# endif
while ( V_12 >= 16 ) {
(* V_17) ( V_14 , V_15 , V_13 ) ;
F_2 ( V_14 ) ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 += sizeof( T_2 ) )
* ( T_2 * ) ( V_11 + V_2 ) =
* ( T_2 * ) ( V_10 + V_2 ) ^ * ( T_2 * ) ( V_15 + V_2 ) ;
V_12 -= 16 ;
V_11 += 16 ;
V_10 += 16 ;
V_2 = 0 ;
}
if ( V_12 ) {
(* V_17) ( V_14 , V_15 , V_13 ) ;
F_2 ( V_14 ) ;
while ( V_12 -- ) {
V_11 [ V_2 ] = V_10 [ V_2 ] ^ V_15 [ V_2 ] ;
++ V_2 ;
}
}
* V_16 = V_2 ;
return;
} while ( 0 );
}
#endif
while ( V_18 < V_12 ) {
if ( V_2 == 0 ) {
(* V_17) ( V_14 , V_15 , V_13 ) ;
F_1 ( V_14 ) ;
}
V_11 [ V_18 ] = V_10 [ V_18 ] ^ V_15 [ V_2 ] ;
++ V_18 ;
V_2 = ( V_2 + 1 ) % 16 ;
}
* V_16 = V_2 ;
}
static void F_5 ( unsigned char * V_1 )
{
T_1 V_2 = 12 , V_3 = 1 ;
do {
-- V_2 ;
V_3 += V_1 [ V_2 ] ;
V_1 [ V_2 ] = ( V_4 ) V_3 ;
V_3 >>= 8 ;
} while ( V_2 );
}
void F_6 ( const unsigned char * V_10 , unsigned char * V_11 ,
T_2 V_12 , const void * V_13 ,
unsigned char V_14 [ 16 ] ,
unsigned char V_15 [ 16 ] ,
unsigned int * V_16 , T_4 V_21 )
{
unsigned int V_2 , V_22 ;
V_2 = * V_16 ;
while ( V_2 && V_12 ) {
* ( V_11 ++ ) = * ( V_10 ++ ) ^ V_15 [ V_2 ] ;
-- V_12 ;
V_2 = ( V_2 + 1 ) % 16 ;
}
V_22 = F_7 ( V_14 + 12 ) ;
while ( V_12 >= 16 ) {
T_2 V_23 = V_12 / 16 ;
if ( sizeof( T_2 ) > sizeof( unsigned int ) && V_23 > ( 1U << 28 ) )
V_23 = ( 1U << 28 ) ;
V_22 += ( T_1 ) V_23 ;
if ( V_22 < V_23 ) {
V_23 -= V_22 ;
V_22 = 0 ;
}
(* V_21) ( V_10 , V_11 , V_23 , V_13 , V_14 ) ;
F_8 ( V_14 + 12 , V_22 ) ;
if ( V_22 == 0 )
F_5 ( V_14 ) ;
V_23 *= 16 ;
V_12 -= V_23 ;
V_11 += V_23 ;
V_10 += V_23 ;
}
if ( V_12 ) {
memset ( V_15 , 0 , 16 ) ;
(* V_21) ( V_15 , V_15 , 1 , V_13 , V_14 ) ;
++ V_22 ;
F_8 ( V_14 + 12 , V_22 ) ;
if ( V_22 == 0 )
F_5 ( V_14 ) ;
while ( V_12 -- ) {
V_11 [ V_2 ] = V_10 [ V_2 ] ^ V_15 [ V_2 ] ;
++ V_2 ;
}
}
* V_16 = V_2 ;
}
