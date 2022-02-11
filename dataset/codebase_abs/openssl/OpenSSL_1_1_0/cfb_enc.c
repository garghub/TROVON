void F_1 ( const unsigned char * V_1 , unsigned char * V_2 , int V_3 ,
long V_4 , T_1 * V_5 ,
T_2 * V_6 , int V_7 )
{
register T_3 V_8 , V_9 , V_10 , V_11 ;
register unsigned long V_12 = V_4 ;
register int V_13 = V_3 / 8 , V_14 = ( V_3 + 7 ) / 8 , V_15 , V_16 =
V_3 % 8 ;
T_3 V_17 [ 2 ] ;
unsigned char * V_18 ;
#ifndef F_2
unsigned char V_19 [ 16 ] ;
#else
unsigned int V_20 [ 4 ] ;
unsigned char * V_19 = ( unsigned char * ) V_20 ;
assert ( sizeof( V_20 [ 0 ] ) == 4 ) ;
#endif
if ( V_3 <= 0 || V_3 > 64 )
return;
V_18 = & ( * V_6 ) [ 0 ] ;
F_3 ( V_18 , V_10 ) ;
F_3 ( V_18 , V_11 ) ;
if ( V_7 ) {
while ( V_12 >= ( unsigned long ) V_14 ) {
V_12 -= V_14 ;
V_17 [ 0 ] = V_10 ;
V_17 [ 1 ] = V_11 ;
F_4 ( ( T_3 * ) V_17 , V_5 , V_21 ) ;
F_5 ( V_1 , V_8 , V_9 , V_14 ) ;
V_1 += V_14 ;
V_8 ^= V_17 [ 0 ] ;
V_9 ^= V_17 [ 1 ] ;
F_6 ( V_8 , V_9 , V_2 , V_14 ) ;
V_2 += V_14 ;
if ( V_3 == 32 ) {
V_10 = V_11 ;
V_11 = V_8 ;
} else if ( V_3 == 64 ) {
V_10 = V_8 ;
V_11 = V_9 ;
} else {
#ifndef F_2
V_18 = & V_19 [ 0 ] ;
F_7 ( V_10 , V_18 ) ;
F_7 ( V_11 , V_18 ) ;
F_7 ( V_8 , V_18 ) ;
F_7 ( V_9 , V_18 ) ;
#else
V_20 [ 0 ] = V_10 , V_20 [ 1 ] = V_11 , V_20 [ 2 ] = V_8 , V_20 [ 3 ] = V_9 ;
#endif
if ( V_16 == 0 )
memmove ( V_19 , V_19 + V_13 , 8 ) ;
else
for ( V_15 = 0 ; V_15 < 8 ; ++ V_15 )
V_19 [ V_15 ] = V_19 [ V_15 + V_13 ] << V_16 |
V_19 [ V_15 + V_13 + 1 ] >> ( 8 - V_16 ) ;
#ifdef F_2
V_10 = V_20 [ 0 ] , V_11 = V_20 [ 1 ] ;
#else
V_18 = & V_19 [ 0 ] ;
F_3 ( V_18 , V_10 ) ;
F_3 ( V_18 , V_11 ) ;
#endif
}
}
} else {
while ( V_12 >= ( unsigned long ) V_14 ) {
V_12 -= V_14 ;
V_17 [ 0 ] = V_10 ;
V_17 [ 1 ] = V_11 ;
F_4 ( ( T_3 * ) V_17 , V_5 , V_21 ) ;
F_5 ( V_1 , V_8 , V_9 , V_14 ) ;
V_1 += V_14 ;
if ( V_3 == 32 ) {
V_10 = V_11 ;
V_11 = V_8 ;
} else if ( V_3 == 64 ) {
V_10 = V_8 ;
V_11 = V_9 ;
} else {
#ifndef F_2
V_18 = & V_19 [ 0 ] ;
F_7 ( V_10 , V_18 ) ;
F_7 ( V_11 , V_18 ) ;
F_7 ( V_8 , V_18 ) ;
F_7 ( V_9 , V_18 ) ;
#else
V_20 [ 0 ] = V_10 , V_20 [ 1 ] = V_11 , V_20 [ 2 ] = V_8 , V_20 [ 3 ] = V_9 ;
#endif
if ( V_16 == 0 )
memmove ( V_19 , V_19 + V_13 , 8 ) ;
else
for ( V_15 = 0 ; V_15 < 8 ; ++ V_15 )
V_19 [ V_15 ] = V_19 [ V_15 + V_13 ] << V_16 |
V_19 [ V_15 + V_13 + 1 ] >> ( 8 - V_16 ) ;
#ifdef F_2
V_10 = V_20 [ 0 ] , V_11 = V_20 [ 1 ] ;
#else
V_18 = & V_19 [ 0 ] ;
F_3 ( V_18 , V_10 ) ;
F_3 ( V_18 , V_11 ) ;
#endif
}
V_8 ^= V_17 [ 0 ] ;
V_9 ^= V_17 [ 1 ] ;
F_6 ( V_8 , V_9 , V_2 , V_14 ) ;
V_2 += V_14 ;
}
}
V_18 = & ( * V_6 ) [ 0 ] ;
F_7 ( V_10 , V_18 ) ;
F_7 ( V_11 , V_18 ) ;
V_10 = V_11 = V_8 = V_9 = V_17 [ 0 ] = V_17 [ 1 ] = 0 ;
}
