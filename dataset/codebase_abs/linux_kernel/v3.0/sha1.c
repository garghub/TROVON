void F_1 ( T_1 * V_1 , const char * V_2 , T_1 * V_3 )
{
T_1 V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_10 ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
V_3 [ V_10 ] = F_2 ( ( ( const V_11 * ) V_2 ) [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < 64 ; V_10 ++ )
V_3 [ V_10 + 16 ] = F_3 ( V_3 [ V_10 + 13 ] ^ V_3 [ V_10 + 8 ] ^ V_3 [ V_10 + 2 ] ^ V_3 [ V_10 ] , 1 ) ;
V_4 = V_1 [ 0 ] ;
V_5 = V_1 [ 1 ] ;
V_6 = V_1 [ 2 ] ;
V_7 = V_1 [ 3 ] ;
V_8 = V_1 [ 4 ] ;
for ( V_10 = 0 ; V_10 < 20 ; V_10 ++ ) {
V_9 = F_4 ( V_5 , V_6 , V_7 ) + V_12 + F_3 ( V_4 , 5 ) + V_8 + V_3 [ V_10 ] ;
V_8 = V_7 ; V_7 = V_6 ; V_6 = F_3 ( V_5 , 30 ) ; V_5 = V_4 ; V_4 = V_9 ;
}
for (; V_10 < 40 ; V_10 ++ ) {
V_9 = F_5 ( V_5 , V_6 , V_7 ) + V_13 + F_3 ( V_4 , 5 ) + V_8 + V_3 [ V_10 ] ;
V_8 = V_7 ; V_7 = V_6 ; V_6 = F_3 ( V_5 , 30 ) ; V_5 = V_4 ; V_4 = V_9 ;
}
for (; V_10 < 60 ; V_10 ++ ) {
V_9 = F_6 ( V_5 , V_6 , V_7 ) + V_14 + F_3 ( V_4 , 5 ) + V_8 + V_3 [ V_10 ] ;
V_8 = V_7 ; V_7 = V_6 ; V_6 = F_3 ( V_5 , 30 ) ; V_5 = V_4 ; V_4 = V_9 ;
}
for (; V_10 < 80 ; V_10 ++ ) {
V_9 = F_5 ( V_5 , V_6 , V_7 ) + V_15 + F_3 ( V_4 , 5 ) + V_8 + V_3 [ V_10 ] ;
V_8 = V_7 ; V_7 = V_6 ; V_6 = F_3 ( V_5 , 30 ) ; V_5 = V_4 ; V_4 = V_9 ;
}
V_1 [ 0 ] += V_4 ;
V_1 [ 1 ] += V_5 ;
V_1 [ 2 ] += V_6 ;
V_1 [ 3 ] += V_7 ;
V_1 [ 4 ] += V_8 ;
}
void F_7 ( T_1 * V_16 )
{
V_16 [ 0 ] = 0x67452301 ;
V_16 [ 1 ] = 0xefcdab89 ;
V_16 [ 2 ] = 0x98badcfe ;
V_16 [ 3 ] = 0x10325476 ;
V_16 [ 4 ] = 0xc3d2e1f0 ;
}
