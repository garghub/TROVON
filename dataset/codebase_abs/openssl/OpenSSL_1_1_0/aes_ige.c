void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const T_2 * V_4 ,
unsigned char * V_5 , const int V_6 )
{
T_1 V_7 ;
T_1 V_8 = V_3 ;
F_2 ( V_1 && V_2 && V_4 && V_5 ) ;
F_2 ( ( V_9 == V_6 ) || ( V_10 == V_6 ) ) ;
F_2 ( ( V_3 % V_11 ) == 0 ) ;
V_8 = V_3 / V_11 ;
if ( V_9 == V_6 ) {
if ( V_1 != V_2 &&
( V_12
|| ( ( T_1 ) V_1 | ( T_1 ) V_2 | ( T_1 ) V_5 ) % sizeof( long ) ==
0 ) ) {
T_3 * V_13 = ( T_3 * ) V_5 ;
T_3 * V_14 = ( T_3 * ) ( V_5 + V_11 ) ;
while ( V_8 ) {
T_3 * V_15 = ( T_3 * ) V_1 ;
T_3 * V_16 = ( T_3 * ) V_2 ;
for ( V_7 = 0 ; V_7 < V_17 ; ++ V_7 )
V_16 -> V_18 [ V_7 ] = V_15 -> V_18 [ V_7 ] ^ V_13 -> V_18 [ V_7 ] ;
F_3 ( ( unsigned char * ) V_16 -> V_18 ,
( unsigned char * ) V_16 -> V_18 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_17 ; ++ V_7 )
V_16 -> V_18 [ V_7 ] ^= V_14 -> V_18 [ V_7 ] ;
V_13 = V_16 ;
V_14 = V_15 ;
-- V_8 ;
V_1 += V_11 ;
V_2 += V_11 ;
}
memcpy ( V_5 , V_13 -> V_18 , V_11 ) ;
memcpy ( V_5 + V_11 , V_14 -> V_18 , V_11 ) ;
} else {
T_3 V_19 , V_20 ;
T_3 V_21 ;
T_3 V_22 ;
F_4 ( V_21 , V_5 ) ;
F_4 ( V_22 , V_5 + V_11 ) ;
while ( V_8 ) {
F_4 ( V_19 , V_1 ) ;
for ( V_7 = 0 ; V_7 < V_17 ; ++ V_7 )
V_20 . V_18 [ V_7 ] = V_19 . V_18 [ V_7 ] ^ V_21 . V_18 [ V_7 ] ;
F_3 ( ( unsigned char * ) V_20 . V_18 ,
( unsigned char * ) V_20 . V_18 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_17 ; ++ V_7 )
V_20 . V_18 [ V_7 ] ^= V_22 . V_18 [ V_7 ] ;
F_5 ( V_2 , V_20 ) ;
V_21 = V_20 ;
V_22 = V_19 ;
-- V_8 ;
V_1 += V_11 ;
V_2 += V_11 ;
}
memcpy ( V_5 , V_21 . V_18 , V_11 ) ;
memcpy ( V_5 + V_11 , V_22 . V_18 , V_11 ) ;
}
} else {
if ( V_1 != V_2 &&
( V_12
|| ( ( T_1 ) V_1 | ( T_1 ) V_2 | ( T_1 ) V_5 ) % sizeof( long ) ==
0 ) ) {
T_3 * V_13 = ( T_3 * ) V_5 ;
T_3 * V_14 = ( T_3 * ) ( V_5 + V_11 ) ;
while ( V_8 ) {
T_3 V_19 ;
T_3 * V_15 = ( T_3 * ) V_1 ;
T_3 * V_16 = ( T_3 * ) V_2 ;
for ( V_7 = 0 ; V_7 < V_17 ; ++ V_7 )
V_19 . V_18 [ V_7 ] = V_15 -> V_18 [ V_7 ] ^ V_14 -> V_18 [ V_7 ] ;
F_6 ( ( unsigned char * ) V_19 . V_18 ,
( unsigned char * ) V_16 -> V_18 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_17 ; ++ V_7 )
V_16 -> V_18 [ V_7 ] ^= V_13 -> V_18 [ V_7 ] ;
V_13 = V_15 ;
V_14 = V_16 ;
-- V_8 ;
V_1 += V_11 ;
V_2 += V_11 ;
}
memcpy ( V_5 , V_13 -> V_18 , V_11 ) ;
memcpy ( V_5 + V_11 , V_14 -> V_18 , V_11 ) ;
} else {
T_3 V_19 , V_20 ;
T_3 V_21 ;
T_3 V_22 ;
F_4 ( V_21 , V_5 ) ;
F_4 ( V_22 , V_5 + V_11 ) ;
while ( V_8 ) {
F_4 ( V_19 , V_1 ) ;
V_20 = V_19 ;
for ( V_7 = 0 ; V_7 < V_17 ; ++ V_7 )
V_19 . V_18 [ V_7 ] ^= V_22 . V_18 [ V_7 ] ;
F_6 ( ( unsigned char * ) V_19 . V_18 ,
( unsigned char * ) V_19 . V_18 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_17 ; ++ V_7 )
V_19 . V_18 [ V_7 ] ^= V_21 . V_18 [ V_7 ] ;
F_5 ( V_2 , V_19 ) ;
V_21 = V_20 ;
V_22 = V_19 ;
-- V_8 ;
V_1 += V_11 ;
V_2 += V_11 ;
}
memcpy ( V_5 , V_21 . V_18 , V_11 ) ;
memcpy ( V_5 + V_11 , V_22 . V_18 , V_11 ) ;
}
}
}
void F_7 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const T_2 * V_4 ,
const T_2 * V_23 , const unsigned char * V_5 ,
const int V_6 )
{
T_1 V_7 ;
T_1 V_8 = V_3 ;
unsigned char V_19 [ V_11 ] ;
unsigned char V_20 [ V_11 ] ;
unsigned char V_24 [ V_11 ] ;
unsigned char V_25 [ V_11 ] ;
const unsigned char * V_21 ;
const unsigned char * V_22 ;
F_2 ( V_1 && V_2 && V_4 && V_5 ) ;
F_2 ( ( V_9 == V_6 ) || ( V_10 == V_6 ) ) ;
F_2 ( ( V_3 % V_11 ) == 0 ) ;
if ( V_9 == V_6 ) {
V_21 = V_5 ;
V_22 = V_5 + V_11 ;
while ( V_8 >= V_11 ) {
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
V_2 [ V_7 ] = V_1 [ V_7 ] ^ V_21 [ V_7 ] ;
F_3 ( V_2 , V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
V_2 [ V_7 ] ^= V_22 [ V_7 ] ;
V_21 = V_2 ;
memcpy ( V_25 , V_1 , V_11 ) ;
V_22 = V_25 ;
V_8 -= V_11 ;
V_1 += V_11 ;
V_2 += V_11 ;
}
V_21 = V_5 + V_11 * 2 ;
V_22 = V_5 + V_11 * 3 ;
V_8 = V_3 ;
while ( V_8 >= V_11 ) {
V_2 -= V_11 ;
memcpy ( V_19 , V_2 , V_11 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
V_2 [ V_7 ] ^= V_21 [ V_7 ] ;
F_3 ( V_2 , V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
V_2 [ V_7 ] ^= V_22 [ V_7 ] ;
V_21 = V_2 ;
memcpy ( V_25 , V_19 , V_11 ) ;
V_22 = V_25 ;
V_8 -= V_11 ;
}
} else {
V_21 = V_5 + V_11 * 2 ;
V_22 = V_5 + V_11 * 3 ;
V_1 += V_3 ;
V_2 += V_3 ;
while ( V_8 >= V_11 ) {
V_1 -= V_11 ;
V_2 -= V_11 ;
memcpy ( V_19 , V_1 , V_11 ) ;
memcpy ( V_20 , V_1 , V_11 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
V_19 [ V_7 ] ^= V_22 [ V_7 ] ;
F_6 ( V_19 , V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
V_2 [ V_7 ] ^= V_21 [ V_7 ] ;
memcpy ( V_24 , V_20 , V_11 ) ;
V_21 = V_24 ;
V_22 = V_2 ;
V_8 -= V_11 ;
}
V_21 = V_5 ;
V_22 = V_5 + V_11 ;
V_8 = V_3 ;
while ( V_8 >= V_11 ) {
memcpy ( V_19 , V_2 , V_11 ) ;
memcpy ( V_20 , V_2 , V_11 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
V_19 [ V_7 ] ^= V_22 [ V_7 ] ;
F_6 ( V_19 , V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
V_2 [ V_7 ] ^= V_21 [ V_7 ] ;
memcpy ( V_24 , V_20 , V_11 ) ;
V_21 = V_24 ;
V_22 = V_2 ;
V_8 -= V_11 ;
V_1 += V_11 ;
V_2 += V_11 ;
}
}
}
