void F_1 ( T_1 * V_1 ,
unsigned int V_2 , unsigned int V_3 , void * V_4 ,
T_2 V_5 )
{
memset ( V_1 -> V_6 . V_7 , 0 , sizeof( V_1 -> V_6 . V_7 ) ) ;
V_1 -> V_6 . V_7 [ 0 ] = ( ( V_8 ) ( V_3 - 1 ) & 7 ) | ( V_8 ) ( ( ( V_2 - 2 ) / 2 ) & 7 ) << 3 ;
V_1 -> V_9 = 0 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_4 = V_4 ;
}
int F_2 ( T_1 * V_1 ,
const unsigned char * V_6 , T_3 V_10 , T_3 V_11 )
{
unsigned int V_3 = V_1 -> V_6 . V_7 [ 0 ] & 7 ;
if ( V_10 < ( 14 - V_3 ) )
return - 1 ;
if ( sizeof( V_11 ) == 8 && V_3 >= 3 ) {
V_1 -> V_6 . V_7 [ 8 ] = ( V_8 ) ( V_11 >> ( 56 % ( sizeof( V_11 ) * 8 ) ) ) ;
V_1 -> V_6 . V_7 [ 9 ] = ( V_8 ) ( V_11 >> ( 48 % ( sizeof( V_11 ) * 8 ) ) ) ;
V_1 -> V_6 . V_7 [ 10 ] = ( V_8 ) ( V_11 >> ( 40 % ( sizeof( V_11 ) * 8 ) ) ) ;
V_1 -> V_6 . V_7 [ 11 ] = ( V_8 ) ( V_11 >> ( 32 % ( sizeof( V_11 ) * 8 ) ) ) ;
} else
V_1 -> V_6 . V_12 [ 1 ] = 0 ;
V_1 -> V_6 . V_7 [ 12 ] = ( V_8 ) ( V_11 >> 24 ) ;
V_1 -> V_6 . V_7 [ 13 ] = ( V_8 ) ( V_11 >> 16 ) ;
V_1 -> V_6 . V_7 [ 14 ] = ( V_8 ) ( V_11 >> 8 ) ;
V_1 -> V_6 . V_7 [ 15 ] = ( V_8 ) V_11 ;
V_1 -> V_6 . V_7 [ 0 ] &= ~ 0x40 ;
memcpy ( & V_1 -> V_6 . V_7 [ 1 ] , V_6 , 14 - V_3 ) ;
return 0 ;
}
void F_3 ( T_1 * V_1 ,
const unsigned char * V_13 , T_3 V_14 )
{
unsigned int V_15 ;
T_2 V_5 = V_1 -> V_5 ;
if ( V_14 == 0 )
return;
V_1 -> V_6 . V_7 [ 0 ] |= 0x40 ;
(* V_5) ( V_1 -> V_6 . V_7 , V_1 -> V_16 . V_7 , V_1 -> V_4 ) , V_1 -> V_9 ++ ;
if ( V_14 < ( 0x10000 - 0x100 ) ) {
V_1 -> V_16 . V_7 [ 0 ] ^= ( V_8 ) ( V_14 >> 8 ) ;
V_1 -> V_16 . V_7 [ 1 ] ^= ( V_8 ) V_14 ;
V_15 = 2 ;
} else if ( sizeof( V_14 ) == 8
&& V_14 >= ( T_3 ) 1 << ( 32 % ( sizeof( V_14 ) * 8 ) ) ) {
V_1 -> V_16 . V_7 [ 0 ] ^= 0xFF ;
V_1 -> V_16 . V_7 [ 1 ] ^= 0xFF ;
V_1 -> V_16 . V_7 [ 2 ] ^= ( V_8 ) ( V_14 >> ( 56 % ( sizeof( V_14 ) * 8 ) ) ) ;
V_1 -> V_16 . V_7 [ 3 ] ^= ( V_8 ) ( V_14 >> ( 48 % ( sizeof( V_14 ) * 8 ) ) ) ;
V_1 -> V_16 . V_7 [ 4 ] ^= ( V_8 ) ( V_14 >> ( 40 % ( sizeof( V_14 ) * 8 ) ) ) ;
V_1 -> V_16 . V_7 [ 5 ] ^= ( V_8 ) ( V_14 >> ( 32 % ( sizeof( V_14 ) * 8 ) ) ) ;
V_1 -> V_16 . V_7 [ 6 ] ^= ( V_8 ) ( V_14 >> 24 ) ;
V_1 -> V_16 . V_7 [ 7 ] ^= ( V_8 ) ( V_14 >> 16 ) ;
V_1 -> V_16 . V_7 [ 8 ] ^= ( V_8 ) ( V_14 >> 8 ) ;
V_1 -> V_16 . V_7 [ 9 ] ^= ( V_8 ) V_14 ;
V_15 = 10 ;
} else {
V_1 -> V_16 . V_7 [ 0 ] ^= 0xFF ;
V_1 -> V_16 . V_7 [ 1 ] ^= 0xFE ;
V_1 -> V_16 . V_7 [ 2 ] ^= ( V_8 ) ( V_14 >> 24 ) ;
V_1 -> V_16 . V_7 [ 3 ] ^= ( V_8 ) ( V_14 >> 16 ) ;
V_1 -> V_16 . V_7 [ 4 ] ^= ( V_8 ) ( V_14 >> 8 ) ;
V_1 -> V_16 . V_7 [ 5 ] ^= ( V_8 ) V_14 ;
V_15 = 6 ;
}
do {
for (; V_15 < 16 && V_14 ; ++ V_15 , ++ V_13 , -- V_14 )
V_1 -> V_16 . V_7 [ V_15 ] ^= * V_13 ;
(* V_5) ( V_1 -> V_16 . V_7 , V_1 -> V_16 . V_7 , V_1 -> V_4 ) , V_1 -> V_9 ++ ;
V_15 = 0 ;
} while ( V_14 );
}
static void F_4 ( unsigned char * V_17 )
{
unsigned int V_18 = 8 ;
V_8 V_7 ;
V_17 += 8 ;
do {
-- V_18 ;
V_7 = V_17 [ V_18 ] ;
++ V_7 ;
V_17 [ V_18 ] = V_7 ;
if ( V_7 )
return;
} while ( V_18 );
}
int F_5 ( T_1 * V_1 ,
const unsigned char * V_19 , unsigned char * V_20 ,
T_3 V_21 )
{
T_3 V_18 ;
unsigned int V_15 , V_3 ;
unsigned char V_22 = V_1 -> V_6 . V_7 [ 0 ] ;
T_2 V_5 = V_1 -> V_5 ;
void * V_4 = V_1 -> V_4 ;
union {
T_4 V_12 [ 2 ] ;
V_8 V_7 [ 16 ] ;
} V_23 ;
if ( ! ( V_22 & 0x40 ) )
(* V_5) ( V_1 -> V_6 . V_7 , V_1 -> V_16 . V_7 , V_4 ) , V_1 -> V_9 ++ ;
V_1 -> V_6 . V_7 [ 0 ] = V_3 = V_22 & 7 ;
for ( V_18 = 0 , V_15 = 15 - V_3 ; V_15 < 15 ; ++ V_15 ) {
V_18 |= V_1 -> V_6 . V_7 [ V_15 ] ;
V_1 -> V_6 . V_7 [ V_15 ] = 0 ;
V_18 <<= 8 ;
}
V_18 |= V_1 -> V_6 . V_7 [ 15 ] ;
V_1 -> V_6 . V_7 [ 15 ] = 1 ;
if ( V_18 != V_21 )
return - 1 ;
V_1 -> V_9 += ( ( V_21 + 15 ) >> 3 ) | 1 ;
if ( V_1 -> V_9 > ( F_6 ( 1 ) << 61 ) )
return - 2 ;
while ( V_21 >= 16 ) {
#if F_7 ( V_24 )
union {
T_4 V_12 [ 2 ] ;
V_8 V_7 [ 16 ] ;
} V_25 ;
memcpy ( V_25 . V_7 , V_19 , 16 ) ;
V_1 -> V_16 . V_12 [ 0 ] ^= V_25 . V_12 [ 0 ] ;
V_1 -> V_16 . V_12 [ 1 ] ^= V_25 . V_12 [ 1 ] ;
#else
V_1 -> V_16 . V_12 [ 0 ] ^= ( ( T_4 * ) V_19 ) [ 0 ] ;
V_1 -> V_16 . V_12 [ 1 ] ^= ( ( T_4 * ) V_19 ) [ 1 ] ;
#endif
(* V_5) ( V_1 -> V_16 . V_7 , V_1 -> V_16 . V_7 , V_4 ) ;
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
F_4 ( V_1 -> V_6 . V_7 ) ;
#if F_7 ( V_24 )
V_25 . V_12 [ 0 ] ^= V_23 . V_12 [ 0 ] ;
V_25 . V_12 [ 1 ] ^= V_23 . V_12 [ 1 ] ;
memcpy ( V_20 , V_25 . V_7 , 16 ) ;
#else
( ( T_4 * ) V_20 ) [ 0 ] = V_23 . V_12 [ 0 ] ^ ( ( T_4 * ) V_19 ) [ 0 ] ;
( ( T_4 * ) V_20 ) [ 1 ] = V_23 . V_12 [ 1 ] ^ ( ( T_4 * ) V_19 ) [ 1 ] ;
#endif
V_19 += 16 ;
V_20 += 16 ;
V_21 -= 16 ;
}
if ( V_21 ) {
for ( V_15 = 0 ; V_15 < V_21 ; ++ V_15 )
V_1 -> V_16 . V_7 [ V_15 ] ^= V_19 [ V_15 ] ;
(* V_5) ( V_1 -> V_16 . V_7 , V_1 -> V_16 . V_7 , V_4 ) ;
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
for ( V_15 = 0 ; V_15 < V_21 ; ++ V_15 )
V_20 [ V_15 ] = V_23 . V_7 [ V_15 ] ^ V_19 [ V_15 ] ;
}
for ( V_15 = 15 - V_3 ; V_15 < 16 ; ++ V_15 )
V_1 -> V_6 . V_7 [ V_15 ] = 0 ;
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
V_1 -> V_16 . V_12 [ 0 ] ^= V_23 . V_12 [ 0 ] ;
V_1 -> V_16 . V_12 [ 1 ] ^= V_23 . V_12 [ 1 ] ;
V_1 -> V_6 . V_7 [ 0 ] = V_22 ;
return 0 ;
}
int F_8 ( T_1 * V_1 ,
const unsigned char * V_19 , unsigned char * V_20 ,
T_3 V_21 )
{
T_3 V_18 ;
unsigned int V_15 , V_3 ;
unsigned char V_22 = V_1 -> V_6 . V_7 [ 0 ] ;
T_2 V_5 = V_1 -> V_5 ;
void * V_4 = V_1 -> V_4 ;
union {
T_4 V_12 [ 2 ] ;
V_8 V_7 [ 16 ] ;
} V_23 ;
if ( ! ( V_22 & 0x40 ) )
(* V_5) ( V_1 -> V_6 . V_7 , V_1 -> V_16 . V_7 , V_4 ) ;
V_1 -> V_6 . V_7 [ 0 ] = V_3 = V_22 & 7 ;
for ( V_18 = 0 , V_15 = 15 - V_3 ; V_15 < 15 ; ++ V_15 ) {
V_18 |= V_1 -> V_6 . V_7 [ V_15 ] ;
V_1 -> V_6 . V_7 [ V_15 ] = 0 ;
V_18 <<= 8 ;
}
V_18 |= V_1 -> V_6 . V_7 [ 15 ] ;
V_1 -> V_6 . V_7 [ 15 ] = 1 ;
if ( V_18 != V_21 )
return - 1 ;
while ( V_21 >= 16 ) {
#if F_7 ( V_24 )
union {
T_4 V_12 [ 2 ] ;
V_8 V_7 [ 16 ] ;
} V_25 ;
#endif
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
F_4 ( V_1 -> V_6 . V_7 ) ;
#if F_7 ( V_24 )
memcpy ( V_25 . V_7 , V_19 , 16 ) ;
V_1 -> V_16 . V_12 [ 0 ] ^= ( V_23 . V_12 [ 0 ] ^= V_25 . V_12 [ 0 ] ) ;
V_1 -> V_16 . V_12 [ 1 ] ^= ( V_23 . V_12 [ 1 ] ^= V_25 . V_12 [ 1 ] ) ;
memcpy ( V_20 , V_23 . V_7 , 16 ) ;
#else
V_1 -> V_16 . V_12 [ 0 ] ^= ( ( ( T_4 * ) V_20 ) [ 0 ] = V_23 . V_12 [ 0 ] ^ ( ( T_4 * ) V_19 ) [ 0 ] ) ;
V_1 -> V_16 . V_12 [ 1 ] ^= ( ( ( T_4 * ) V_20 ) [ 1 ] = V_23 . V_12 [ 1 ] ^ ( ( T_4 * ) V_19 ) [ 1 ] ) ;
#endif
(* V_5) ( V_1 -> V_16 . V_7 , V_1 -> V_16 . V_7 , V_4 ) ;
V_19 += 16 ;
V_20 += 16 ;
V_21 -= 16 ;
}
if ( V_21 ) {
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
for ( V_15 = 0 ; V_15 < V_21 ; ++ V_15 )
V_1 -> V_16 . V_7 [ V_15 ] ^= ( V_20 [ V_15 ] = V_23 . V_7 [ V_15 ] ^ V_19 [ V_15 ] ) ;
(* V_5) ( V_1 -> V_16 . V_7 , V_1 -> V_16 . V_7 , V_4 ) ;
}
for ( V_15 = 15 - V_3 ; V_15 < 16 ; ++ V_15 )
V_1 -> V_6 . V_7 [ V_15 ] = 0 ;
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
V_1 -> V_16 . V_12 [ 0 ] ^= V_23 . V_12 [ 0 ] ;
V_1 -> V_16 . V_12 [ 1 ] ^= V_23 . V_12 [ 1 ] ;
V_1 -> V_6 . V_7 [ 0 ] = V_22 ;
return 0 ;
}
static void F_9 ( unsigned char * V_17 , T_3 V_26 )
{
T_3 V_18 = 8 , V_27 = 0 ;
V_17 += 8 ;
do {
-- V_18 ;
V_27 += V_17 [ V_18 ] + ( V_26 & 0xff ) ;
V_17 [ V_18 ] = ( unsigned char ) V_27 ;
V_27 >>= 8 ;
V_26 >>= 8 ;
} while ( V_18 && ( V_26 || V_27 ) );
}
int F_10 ( T_1 * V_1 ,
const unsigned char * V_19 , unsigned char * V_20 ,
T_3 V_21 , T_5 V_28 )
{
T_3 V_18 ;
unsigned int V_15 , V_3 ;
unsigned char V_22 = V_1 -> V_6 . V_7 [ 0 ] ;
T_2 V_5 = V_1 -> V_5 ;
void * V_4 = V_1 -> V_4 ;
union {
T_4 V_12 [ 2 ] ;
V_8 V_7 [ 16 ] ;
} V_23 ;
if ( ! ( V_22 & 0x40 ) )
(* V_5) ( V_1 -> V_6 . V_7 , V_1 -> V_16 . V_7 , V_4 ) , V_1 -> V_9 ++ ;
V_1 -> V_6 . V_7 [ 0 ] = V_3 = V_22 & 7 ;
for ( V_18 = 0 , V_15 = 15 - V_3 ; V_15 < 15 ; ++ V_15 ) {
V_18 |= V_1 -> V_6 . V_7 [ V_15 ] ;
V_1 -> V_6 . V_7 [ V_15 ] = 0 ;
V_18 <<= 8 ;
}
V_18 |= V_1 -> V_6 . V_7 [ 15 ] ;
V_1 -> V_6 . V_7 [ 15 ] = 1 ;
if ( V_18 != V_21 )
return - 1 ;
V_1 -> V_9 += ( ( V_21 + 15 ) >> 3 ) | 1 ;
if ( V_1 -> V_9 > ( F_6 ( 1 ) << 61 ) )
return - 2 ;
if ( ( V_18 = V_21 / 16 ) ) {
(* V_28) ( V_19 , V_20 , V_18 , V_4 , V_1 -> V_6 . V_7 , V_1 -> V_16 . V_7 ) ;
V_18 *= 16 ;
V_19 += V_18 ;
V_20 += V_18 ;
V_21 -= V_18 ;
if ( V_21 )
F_9 ( V_1 -> V_6 . V_7 , V_18 / 16 ) ;
}
if ( V_21 ) {
for ( V_15 = 0 ; V_15 < V_21 ; ++ V_15 )
V_1 -> V_16 . V_7 [ V_15 ] ^= V_19 [ V_15 ] ;
(* V_5) ( V_1 -> V_16 . V_7 , V_1 -> V_16 . V_7 , V_4 ) ;
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
for ( V_15 = 0 ; V_15 < V_21 ; ++ V_15 )
V_20 [ V_15 ] = V_23 . V_7 [ V_15 ] ^ V_19 [ V_15 ] ;
}
for ( V_15 = 15 - V_3 ; V_15 < 16 ; ++ V_15 )
V_1 -> V_6 . V_7 [ V_15 ] = 0 ;
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
V_1 -> V_16 . V_12 [ 0 ] ^= V_23 . V_12 [ 0 ] ;
V_1 -> V_16 . V_12 [ 1 ] ^= V_23 . V_12 [ 1 ] ;
V_1 -> V_6 . V_7 [ 0 ] = V_22 ;
return 0 ;
}
int F_11 ( T_1 * V_1 ,
const unsigned char * V_19 , unsigned char * V_20 ,
T_3 V_21 , T_5 V_28 )
{
T_3 V_18 ;
unsigned int V_15 , V_3 ;
unsigned char V_22 = V_1 -> V_6 . V_7 [ 0 ] ;
T_2 V_5 = V_1 -> V_5 ;
void * V_4 = V_1 -> V_4 ;
union {
T_4 V_12 [ 2 ] ;
V_8 V_7 [ 16 ] ;
} V_23 ;
if ( ! ( V_22 & 0x40 ) )
(* V_5) ( V_1 -> V_6 . V_7 , V_1 -> V_16 . V_7 , V_4 ) ;
V_1 -> V_6 . V_7 [ 0 ] = V_3 = V_22 & 7 ;
for ( V_18 = 0 , V_15 = 15 - V_3 ; V_15 < 15 ; ++ V_15 ) {
V_18 |= V_1 -> V_6 . V_7 [ V_15 ] ;
V_1 -> V_6 . V_7 [ V_15 ] = 0 ;
V_18 <<= 8 ;
}
V_18 |= V_1 -> V_6 . V_7 [ 15 ] ;
V_1 -> V_6 . V_7 [ 15 ] = 1 ;
if ( V_18 != V_21 )
return - 1 ;
if ( ( V_18 = V_21 / 16 ) ) {
(* V_28) ( V_19 , V_20 , V_18 , V_4 , V_1 -> V_6 . V_7 , V_1 -> V_16 . V_7 ) ;
V_18 *= 16 ;
V_19 += V_18 ;
V_20 += V_18 ;
V_21 -= V_18 ;
if ( V_21 )
F_9 ( V_1 -> V_6 . V_7 , V_18 / 16 ) ;
}
if ( V_21 ) {
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
for ( V_15 = 0 ; V_15 < V_21 ; ++ V_15 )
V_1 -> V_16 . V_7 [ V_15 ] ^= ( V_20 [ V_15 ] = V_23 . V_7 [ V_15 ] ^ V_19 [ V_15 ] ) ;
(* V_5) ( V_1 -> V_16 . V_7 , V_1 -> V_16 . V_7 , V_4 ) ;
}
for ( V_15 = 15 - V_3 ; V_15 < 16 ; ++ V_15 )
V_1 -> V_6 . V_7 [ V_15 ] = 0 ;
(* V_5) ( V_1 -> V_6 . V_7 , V_23 . V_7 , V_4 ) ;
V_1 -> V_16 . V_12 [ 0 ] ^= V_23 . V_12 [ 0 ] ;
V_1 -> V_16 . V_12 [ 1 ] ^= V_23 . V_12 [ 1 ] ;
V_1 -> V_6 . V_7 [ 0 ] = V_22 ;
return 0 ;
}
T_3 F_12 ( T_1 * V_1 , unsigned char * V_29 , T_3 V_21 )
{
unsigned int V_2 = ( V_1 -> V_6 . V_7 [ 0 ] >> 3 ) & 7 ;
V_2 *= 2 ;
V_2 += 2 ;
if ( V_21 < V_2 )
return 0 ;
memcpy ( V_29 , V_1 -> V_16 . V_7 , V_2 ) ;
return V_2 ;
}
