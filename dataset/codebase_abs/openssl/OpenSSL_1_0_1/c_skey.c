void F_1 ( T_1 * V_1 , int V_2 , const unsigned char * V_3 )
#ifdef F_2
{
F_3 ( V_4 ) ;
F_4 ( V_1 , V_2 , V_3 ) ;
}
void F_4 ( T_1 * V_1 , int V_2 , const unsigned char * V_3 )
#endif
{
T_2 V_5 [ 16 ] ;
T_2 V_6 [ 16 ] ;
T_2 V_7 [ 32 ] ;
T_2 V_8 [ 4 ] , V_9 [ 4 ] ;
T_2 V_10 , * V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) V_5 [ V_12 ] = 0 ;
if ( V_2 > 16 ) V_2 = 16 ;
for ( V_12 = 0 ; V_12 < V_2 ; V_12 ++ )
V_5 [ V_12 ] = V_3 [ V_12 ] ;
if( V_2 <= 10 )
V_1 -> V_13 = 1 ;
else
V_1 -> V_13 = 0 ;
V_11 = & V_7 [ 0 ] ;
V_8 [ 0 ] = ( ( V_5 [ 0 ] << 24 ) | ( V_5 [ 1 ] << 16 ) | ( V_5 [ 2 ] << 8 ) | V_5 [ 3 ] ) & 0xffffffffL ;
V_8 [ 1 ] = ( ( V_5 [ 4 ] << 24 ) | ( V_5 [ 5 ] << 16 ) | ( V_5 [ 6 ] << 8 ) | V_5 [ 7 ] ) & 0xffffffffL ;
V_8 [ 2 ] = ( ( V_5 [ 8 ] << 24 ) | ( V_5 [ 9 ] << 16 ) | ( V_5 [ 10 ] << 8 ) | V_5 [ 11 ] ) & 0xffffffffL ;
V_8 [ 3 ] = ( ( V_5 [ 12 ] << 24 ) | ( V_5 [ 13 ] << 16 ) | ( V_5 [ 14 ] << 8 ) | V_5 [ 15 ] ) & 0xffffffffL ;
for (; ; )
{
V_10 = V_8 [ 0 ] ^ V_14 [ V_5 [ 13 ] ] ^ V_15 [ V_5 [ 15 ] ] ^ V_16 [ V_5 [ 12 ] ] ^ V_17 [ V_5 [ 14 ] ] ^ V_16 [ V_5 [ 8 ] ] ;
F_5 ( V_10 , V_9 , V_6 , 0 ) ;
V_10 = V_8 [ 2 ] ^ V_14 [ V_6 [ 0 ] ] ^ V_15 [ V_6 [ 2 ] ] ^ V_16 [ V_6 [ 1 ] ] ^ V_17 [ V_6 [ 3 ] ] ^ V_17 [ V_5 [ 10 ] ] ;
F_5 ( V_10 , V_9 , V_6 , 4 ) ;
V_10 = V_8 [ 3 ] ^ V_14 [ V_6 [ 7 ] ] ^ V_15 [ V_6 [ 6 ] ] ^ V_16 [ V_6 [ 5 ] ] ^ V_17 [ V_6 [ 4 ] ] ^ V_14 [ V_5 [ 9 ] ] ;
F_5 ( V_10 , V_9 , V_6 , 8 ) ;
V_10 = V_8 [ 1 ] ^ V_14 [ V_6 [ 10 ] ] ^ V_15 [ V_6 [ 9 ] ] ^ V_16 [ V_6 [ 11 ] ] ^ V_17 [ V_6 [ 8 ] ] ^ V_15 [ V_5 [ 11 ] ] ;
F_5 ( V_10 , V_9 , V_6 , 12 ) ;
V_11 [ 0 ] = V_14 [ V_6 [ 8 ] ] ^ V_15 [ V_6 [ 9 ] ] ^ V_16 [ V_6 [ 7 ] ] ^ V_17 [ V_6 [ 6 ] ] ^ V_14 [ V_6 [ 2 ] ] ;
V_11 [ 1 ] = V_14 [ V_6 [ 10 ] ] ^ V_15 [ V_6 [ 11 ] ] ^ V_16 [ V_6 [ 5 ] ] ^ V_17 [ V_6 [ 4 ] ] ^ V_15 [ V_6 [ 6 ] ] ;
V_11 [ 2 ] = V_14 [ V_6 [ 12 ] ] ^ V_15 [ V_6 [ 13 ] ] ^ V_16 [ V_6 [ 3 ] ] ^ V_17 [ V_6 [ 2 ] ] ^ V_16 [ V_6 [ 9 ] ] ;
V_11 [ 3 ] = V_14 [ V_6 [ 14 ] ] ^ V_15 [ V_6 [ 15 ] ] ^ V_16 [ V_6 [ 1 ] ] ^ V_17 [ V_6 [ 0 ] ] ^ V_17 [ V_6 [ 12 ] ] ;
V_10 = V_9 [ 2 ] ^ V_14 [ V_6 [ 5 ] ] ^ V_15 [ V_6 [ 7 ] ] ^ V_16 [ V_6 [ 4 ] ] ^ V_17 [ V_6 [ 6 ] ] ^ V_16 [ V_6 [ 0 ] ] ;
F_5 ( V_10 , V_8 , V_5 , 0 ) ;
V_10 = V_9 [ 0 ] ^ V_14 [ V_5 [ 0 ] ] ^ V_15 [ V_5 [ 2 ] ] ^ V_16 [ V_5 [ 1 ] ] ^ V_17 [ V_5 [ 3 ] ] ^ V_17 [ V_6 [ 2 ] ] ;
F_5 ( V_10 , V_8 , V_5 , 4 ) ;
V_10 = V_9 [ 1 ] ^ V_14 [ V_5 [ 7 ] ] ^ V_15 [ V_5 [ 6 ] ] ^ V_16 [ V_5 [ 5 ] ] ^ V_17 [ V_5 [ 4 ] ] ^ V_14 [ V_6 [ 1 ] ] ;
F_5 ( V_10 , V_8 , V_5 , 8 ) ;
V_10 = V_9 [ 3 ] ^ V_14 [ V_5 [ 10 ] ] ^ V_15 [ V_5 [ 9 ] ] ^ V_16 [ V_5 [ 11 ] ] ^ V_17 [ V_5 [ 8 ] ] ^ V_15 [ V_6 [ 3 ] ] ;
F_5 ( V_10 , V_8 , V_5 , 12 ) ;
V_11 [ 4 ] = V_14 [ V_5 [ 3 ] ] ^ V_15 [ V_5 [ 2 ] ] ^ V_16 [ V_5 [ 12 ] ] ^ V_17 [ V_5 [ 13 ] ] ^ V_14 [ V_5 [ 8 ] ] ;
V_11 [ 5 ] = V_14 [ V_5 [ 1 ] ] ^ V_15 [ V_5 [ 0 ] ] ^ V_16 [ V_5 [ 14 ] ] ^ V_17 [ V_5 [ 15 ] ] ^ V_15 [ V_5 [ 13 ] ] ;
V_11 [ 6 ] = V_14 [ V_5 [ 7 ] ] ^ V_15 [ V_5 [ 6 ] ] ^ V_16 [ V_5 [ 8 ] ] ^ V_17 [ V_5 [ 9 ] ] ^ V_16 [ V_5 [ 3 ] ] ;
V_11 [ 7 ] = V_14 [ V_5 [ 5 ] ] ^ V_15 [ V_5 [ 4 ] ] ^ V_16 [ V_5 [ 10 ] ] ^ V_17 [ V_5 [ 11 ] ] ^ V_17 [ V_5 [ 7 ] ] ;
V_10 = V_8 [ 0 ] ^ V_14 [ V_5 [ 13 ] ] ^ V_15 [ V_5 [ 15 ] ] ^ V_16 [ V_5 [ 12 ] ] ^ V_17 [ V_5 [ 14 ] ] ^ V_16 [ V_5 [ 8 ] ] ;
F_5 ( V_10 , V_9 , V_6 , 0 ) ;
V_10 = V_8 [ 2 ] ^ V_14 [ V_6 [ 0 ] ] ^ V_15 [ V_6 [ 2 ] ] ^ V_16 [ V_6 [ 1 ] ] ^ V_17 [ V_6 [ 3 ] ] ^ V_17 [ V_5 [ 10 ] ] ;
F_5 ( V_10 , V_9 , V_6 , 4 ) ;
V_10 = V_8 [ 3 ] ^ V_14 [ V_6 [ 7 ] ] ^ V_15 [ V_6 [ 6 ] ] ^ V_16 [ V_6 [ 5 ] ] ^ V_17 [ V_6 [ 4 ] ] ^ V_14 [ V_5 [ 9 ] ] ;
F_5 ( V_10 , V_9 , V_6 , 8 ) ;
V_10 = V_8 [ 1 ] ^ V_14 [ V_6 [ 10 ] ] ^ V_15 [ V_6 [ 9 ] ] ^ V_16 [ V_6 [ 11 ] ] ^ V_17 [ V_6 [ 8 ] ] ^ V_15 [ V_5 [ 11 ] ] ;
F_5 ( V_10 , V_9 , V_6 , 12 ) ;
V_11 [ 8 ] = V_14 [ V_6 [ 3 ] ] ^ V_15 [ V_6 [ 2 ] ] ^ V_16 [ V_6 [ 12 ] ] ^ V_17 [ V_6 [ 13 ] ] ^ V_14 [ V_6 [ 9 ] ] ;
V_11 [ 9 ] = V_14 [ V_6 [ 1 ] ] ^ V_15 [ V_6 [ 0 ] ] ^ V_16 [ V_6 [ 14 ] ] ^ V_17 [ V_6 [ 15 ] ] ^ V_15 [ V_6 [ 12 ] ] ;
V_11 [ 10 ] = V_14 [ V_6 [ 7 ] ] ^ V_15 [ V_6 [ 6 ] ] ^ V_16 [ V_6 [ 8 ] ] ^ V_17 [ V_6 [ 9 ] ] ^ V_16 [ V_6 [ 2 ] ] ;
V_11 [ 11 ] = V_14 [ V_6 [ 5 ] ] ^ V_15 [ V_6 [ 4 ] ] ^ V_16 [ V_6 [ 10 ] ] ^ V_17 [ V_6 [ 11 ] ] ^ V_17 [ V_6 [ 6 ] ] ;
V_10 = V_9 [ 2 ] ^ V_14 [ V_6 [ 5 ] ] ^ V_15 [ V_6 [ 7 ] ] ^ V_16 [ V_6 [ 4 ] ] ^ V_17 [ V_6 [ 6 ] ] ^ V_16 [ V_6 [ 0 ] ] ;
F_5 ( V_10 , V_8 , V_5 , 0 ) ;
V_10 = V_9 [ 0 ] ^ V_14 [ V_5 [ 0 ] ] ^ V_15 [ V_5 [ 2 ] ] ^ V_16 [ V_5 [ 1 ] ] ^ V_17 [ V_5 [ 3 ] ] ^ V_17 [ V_6 [ 2 ] ] ;
F_5 ( V_10 , V_8 , V_5 , 4 ) ;
V_10 = V_9 [ 1 ] ^ V_14 [ V_5 [ 7 ] ] ^ V_15 [ V_5 [ 6 ] ] ^ V_16 [ V_5 [ 5 ] ] ^ V_17 [ V_5 [ 4 ] ] ^ V_14 [ V_6 [ 1 ] ] ;
F_5 ( V_10 , V_8 , V_5 , 8 ) ;
V_10 = V_9 [ 3 ] ^ V_14 [ V_5 [ 10 ] ] ^ V_15 [ V_5 [ 9 ] ] ^ V_16 [ V_5 [ 11 ] ] ^ V_17 [ V_5 [ 8 ] ] ^ V_15 [ V_6 [ 3 ] ] ;
F_5 ( V_10 , V_8 , V_5 , 12 ) ;
V_11 [ 12 ] = V_14 [ V_5 [ 8 ] ] ^ V_15 [ V_5 [ 9 ] ] ^ V_16 [ V_5 [ 7 ] ] ^ V_17 [ V_5 [ 6 ] ] ^ V_14 [ V_5 [ 3 ] ] ;
V_11 [ 13 ] = V_14 [ V_5 [ 10 ] ] ^ V_15 [ V_5 [ 11 ] ] ^ V_16 [ V_5 [ 5 ] ] ^ V_17 [ V_5 [ 4 ] ] ^ V_15 [ V_5 [ 7 ] ] ;
V_11 [ 14 ] = V_14 [ V_5 [ 12 ] ] ^ V_15 [ V_5 [ 13 ] ] ^ V_16 [ V_5 [ 3 ] ] ^ V_17 [ V_5 [ 2 ] ] ^ V_16 [ V_5 [ 8 ] ] ;
V_11 [ 15 ] = V_14 [ V_5 [ 14 ] ] ^ V_15 [ V_5 [ 15 ] ] ^ V_16 [ V_5 [ 1 ] ] ^ V_17 [ V_5 [ 0 ] ] ^ V_17 [ V_5 [ 13 ] ] ;
if ( V_11 != V_7 ) break;
V_11 += 16 ;
}
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
{
V_1 -> V_3 [ V_12 * 2 ] = V_7 [ V_12 ] ;
V_1 -> V_3 [ V_12 * 2 + 1 ] = ( ( V_7 [ V_12 + 16 ] ) + 16 ) & 0x1f ;
}
}
