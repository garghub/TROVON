static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
const T_1 * V_5 = V_2 -> V_6 ;
const T_1 * V_7 = V_2 -> V_8 ;
T_1 V_9 = V_4 [ 0 ] ;
T_1 V_10 = V_4 [ 1 ] ;
F_2 ( V_10 , V_9 , 0 ) ;
F_2 ( V_9 , V_10 , 1 ) ;
F_2 ( V_10 , V_9 , 2 ) ;
F_2 ( V_9 , V_10 , 3 ) ;
F_2 ( V_10 , V_9 , 4 ) ;
F_2 ( V_9 , V_10 , 5 ) ;
F_2 ( V_10 , V_9 , 6 ) ;
F_2 ( V_9 , V_10 , 7 ) ;
F_2 ( V_10 , V_9 , 8 ) ;
F_2 ( V_9 , V_10 , 9 ) ;
F_2 ( V_10 , V_9 , 10 ) ;
F_2 ( V_9 , V_10 , 11 ) ;
F_2 ( V_10 , V_9 , 12 ) ;
F_2 ( V_9 , V_10 , 13 ) ;
F_2 ( V_10 , V_9 , 14 ) ;
F_2 ( V_9 , V_10 , 15 ) ;
V_9 ^= V_5 [ 16 ] ;
V_10 ^= V_5 [ 17 ] ;
V_3 [ 0 ] = V_10 ;
V_3 [ 1 ] = V_9 ;
}
int F_3 ( struct V_11 * V_12 , const T_2 * V_13 , unsigned int V_14 )
{
struct V_1 * V_15 = F_4 ( V_12 ) ;
T_1 * V_5 = V_15 -> V_6 ;
T_1 * V_7 = V_15 -> V_8 ;
short V_16 , V_17 , V_18 ;
T_1 V_19 [ 2 ] , V_20 ;
for ( V_16 = 0 , V_18 = 0 ; V_16 < 256 ; V_16 ++ )
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ , V_18 ++ )
V_7 [ V_18 ] = V_21 [ V_18 ] ;
for ( V_16 = 0 ; V_16 < 16 + 2 ; V_16 ++ )
V_5 [ V_16 ] = V_22 [ V_16 ] ;
for ( V_17 = 0 , V_16 = 0 ; V_16 < 16 + 2 ; V_16 ++ ) {
V_20 = ( ( ( T_1 ) V_13 [ V_17 ] << 24 ) |
( ( T_1 ) V_13 [ ( V_17 + 1 ) % V_14 ] << 16 ) |
( ( T_1 ) V_13 [ ( V_17 + 2 ) % V_14 ] << 8 ) |
( ( T_1 ) V_13 [ ( V_17 + 3 ) % V_14 ] ) ) ;
V_5 [ V_16 ] = V_5 [ V_16 ] ^ V_20 ;
V_17 = ( V_17 + 4 ) % V_14 ;
}
V_19 [ 0 ] = 0x00000000 ;
V_19 [ 1 ] = 0x00000000 ;
for ( V_16 = 0 ; V_16 < 16 + 2 ; V_16 += 2 ) {
F_1 ( (struct V_1 * ) V_15 , V_19 , V_19 ) ;
V_5 [ V_16 ] = V_19 [ 0 ] ;
V_5 [ V_16 + 1 ] = V_19 [ 1 ] ;
}
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
for ( V_17 = 0 , V_18 = V_16 * 256 ; V_17 < 256 ; V_17 += 2 , V_18 += 2 ) {
F_1 ( (struct V_1 * ) V_15 , V_19 , V_19 ) ;
V_7 [ V_18 ] = V_19 [ 0 ] ;
V_7 [ V_18 + 1 ] = V_19 [ 1 ] ;
}
}
return 0 ;
}
