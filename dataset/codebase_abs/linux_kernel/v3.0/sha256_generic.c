static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 )
{
return V_3 ^ ( V_1 & ( V_2 ^ V_3 ) ) ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_2 , T_1 V_3 )
{
return ( V_1 & V_2 ) | ( V_3 & ( V_1 | V_2 ) ) ;
}
static inline void F_3 ( int V_4 , T_1 * V_5 , const T_2 * V_6 )
{
V_5 [ V_4 ] = F_4 ( ( ( V_7 * ) ( V_6 ) ) [ V_4 ] ) ;
}
static inline void F_5 ( int V_4 , T_1 * V_5 )
{
V_5 [ V_4 ] = F_6 ( V_5 [ V_4 - 2 ] ) + V_5 [ V_4 - 7 ] + F_7 ( V_5 [ V_4 - 15 ] ) + V_5 [ V_4 - 16 ] ;
}
static void F_8 ( T_1 * V_8 , const T_2 * V_6 )
{
T_1 V_9 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 ;
T_1 V_5 [ 64 ] ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ )
F_3 ( V_19 , V_5 , V_6 ) ;
for ( V_19 = 16 ; V_19 < 64 ; V_19 ++ )
F_5 ( V_19 , V_5 ) ;
V_9 = V_8 [ 0 ] ; V_10 = V_8 [ 1 ] ; V_11 = V_8 [ 2 ] ; V_12 = V_8 [ 3 ] ;
V_13 = V_8 [ 4 ] ; V_14 = V_8 [ 5 ] ; V_15 = V_8 [ 6 ] ; V_16 = V_8 [ 7 ] ;
V_17 = V_16 + F_9 ( V_13 ) + F_1 ( V_13 , V_14 , V_15 ) + 0x428a2f98 + V_5 [ 0 ] ;
V_18 = F_10 ( V_9 ) + F_2 ( V_9 , V_10 , V_11 ) ; V_12 += V_17 ; V_16 = V_17 + V_18 ;
V_17 = V_15 + F_9 ( V_12 ) + F_1 ( V_12 , V_13 , V_14 ) + 0x71374491 + V_5 [ 1 ] ;
V_18 = F_10 ( V_16 ) + F_2 ( V_16 , V_9 , V_10 ) ; V_11 += V_17 ; V_15 = V_17 + V_18 ;
V_17 = V_14 + F_9 ( V_11 ) + F_1 ( V_11 , V_12 , V_13 ) + 0xb5c0fbcf + V_5 [ 2 ] ;
V_18 = F_10 ( V_15 ) + F_2 ( V_15 , V_16 , V_9 ) ; V_10 += V_17 ; V_14 = V_17 + V_18 ;
V_17 = V_13 + F_9 ( V_10 ) + F_1 ( V_10 , V_11 , V_12 ) + 0xe9b5dba5 + V_5 [ 3 ] ;
V_18 = F_10 ( V_14 ) + F_2 ( V_14 , V_15 , V_16 ) ; V_9 += V_17 ; V_13 = V_17 + V_18 ;
V_17 = V_12 + F_9 ( V_9 ) + F_1 ( V_9 , V_10 , V_11 ) + 0x3956c25b + V_5 [ 4 ] ;
V_18 = F_10 ( V_13 ) + F_2 ( V_13 , V_14 , V_15 ) ; V_16 += V_17 ; V_12 = V_17 + V_18 ;
V_17 = V_11 + F_9 ( V_16 ) + F_1 ( V_16 , V_9 , V_10 ) + 0x59f111f1 + V_5 [ 5 ] ;
V_18 = F_10 ( V_12 ) + F_2 ( V_12 , V_13 , V_14 ) ; V_15 += V_17 ; V_11 = V_17 + V_18 ;
V_17 = V_10 + F_9 ( V_15 ) + F_1 ( V_15 , V_16 , V_9 ) + 0x923f82a4 + V_5 [ 6 ] ;
V_18 = F_10 ( V_11 ) + F_2 ( V_11 , V_12 , V_13 ) ; V_14 += V_17 ; V_10 = V_17 + V_18 ;
V_17 = V_9 + F_9 ( V_14 ) + F_1 ( V_14 , V_15 , V_16 ) + 0xab1c5ed5 + V_5 [ 7 ] ;
V_18 = F_10 ( V_10 ) + F_2 ( V_10 , V_11 , V_12 ) ; V_13 += V_17 ; V_9 = V_17 + V_18 ;
V_17 = V_16 + F_9 ( V_13 ) + F_1 ( V_13 , V_14 , V_15 ) + 0xd807aa98 + V_5 [ 8 ] ;
V_18 = F_10 ( V_9 ) + F_2 ( V_9 , V_10 , V_11 ) ; V_12 += V_17 ; V_16 = V_17 + V_18 ;
V_17 = V_15 + F_9 ( V_12 ) + F_1 ( V_12 , V_13 , V_14 ) + 0x12835b01 + V_5 [ 9 ] ;
V_18 = F_10 ( V_16 ) + F_2 ( V_16 , V_9 , V_10 ) ; V_11 += V_17 ; V_15 = V_17 + V_18 ;
V_17 = V_14 + F_9 ( V_11 ) + F_1 ( V_11 , V_12 , V_13 ) + 0x243185be + V_5 [ 10 ] ;
V_18 = F_10 ( V_15 ) + F_2 ( V_15 , V_16 , V_9 ) ; V_10 += V_17 ; V_14 = V_17 + V_18 ;
V_17 = V_13 + F_9 ( V_10 ) + F_1 ( V_10 , V_11 , V_12 ) + 0x550c7dc3 + V_5 [ 11 ] ;
V_18 = F_10 ( V_14 ) + F_2 ( V_14 , V_15 , V_16 ) ; V_9 += V_17 ; V_13 = V_17 + V_18 ;
V_17 = V_12 + F_9 ( V_9 ) + F_1 ( V_9 , V_10 , V_11 ) + 0x72be5d74 + V_5 [ 12 ] ;
V_18 = F_10 ( V_13 ) + F_2 ( V_13 , V_14 , V_15 ) ; V_16 += V_17 ; V_12 = V_17 + V_18 ;
V_17 = V_11 + F_9 ( V_16 ) + F_1 ( V_16 , V_9 , V_10 ) + 0x80deb1fe + V_5 [ 13 ] ;
V_18 = F_10 ( V_12 ) + F_2 ( V_12 , V_13 , V_14 ) ; V_15 += V_17 ; V_11 = V_17 + V_18 ;
V_17 = V_10 + F_9 ( V_15 ) + F_1 ( V_15 , V_16 , V_9 ) + 0x9bdc06a7 + V_5 [ 14 ] ;
V_18 = F_10 ( V_11 ) + F_2 ( V_11 , V_12 , V_13 ) ; V_14 += V_17 ; V_10 = V_17 + V_18 ;
V_17 = V_9 + F_9 ( V_14 ) + F_1 ( V_14 , V_15 , V_16 ) + 0xc19bf174 + V_5 [ 15 ] ;
V_18 = F_10 ( V_10 ) + F_2 ( V_10 , V_11 , V_12 ) ; V_13 += V_17 ; V_9 = V_17 + V_18 ;
V_17 = V_16 + F_9 ( V_13 ) + F_1 ( V_13 , V_14 , V_15 ) + 0xe49b69c1 + V_5 [ 16 ] ;
V_18 = F_10 ( V_9 ) + F_2 ( V_9 , V_10 , V_11 ) ; V_12 += V_17 ; V_16 = V_17 + V_18 ;
V_17 = V_15 + F_9 ( V_12 ) + F_1 ( V_12 , V_13 , V_14 ) + 0xefbe4786 + V_5 [ 17 ] ;
V_18 = F_10 ( V_16 ) + F_2 ( V_16 , V_9 , V_10 ) ; V_11 += V_17 ; V_15 = V_17 + V_18 ;
V_17 = V_14 + F_9 ( V_11 ) + F_1 ( V_11 , V_12 , V_13 ) + 0x0fc19dc6 + V_5 [ 18 ] ;
V_18 = F_10 ( V_15 ) + F_2 ( V_15 , V_16 , V_9 ) ; V_10 += V_17 ; V_14 = V_17 + V_18 ;
V_17 = V_13 + F_9 ( V_10 ) + F_1 ( V_10 , V_11 , V_12 ) + 0x240ca1cc + V_5 [ 19 ] ;
V_18 = F_10 ( V_14 ) + F_2 ( V_14 , V_15 , V_16 ) ; V_9 += V_17 ; V_13 = V_17 + V_18 ;
V_17 = V_12 + F_9 ( V_9 ) + F_1 ( V_9 , V_10 , V_11 ) + 0x2de92c6f + V_5 [ 20 ] ;
V_18 = F_10 ( V_13 ) + F_2 ( V_13 , V_14 , V_15 ) ; V_16 += V_17 ; V_12 = V_17 + V_18 ;
V_17 = V_11 + F_9 ( V_16 ) + F_1 ( V_16 , V_9 , V_10 ) + 0x4a7484aa + V_5 [ 21 ] ;
V_18 = F_10 ( V_12 ) + F_2 ( V_12 , V_13 , V_14 ) ; V_15 += V_17 ; V_11 = V_17 + V_18 ;
V_17 = V_10 + F_9 ( V_15 ) + F_1 ( V_15 , V_16 , V_9 ) + 0x5cb0a9dc + V_5 [ 22 ] ;
V_18 = F_10 ( V_11 ) + F_2 ( V_11 , V_12 , V_13 ) ; V_14 += V_17 ; V_10 = V_17 + V_18 ;
V_17 = V_9 + F_9 ( V_14 ) + F_1 ( V_14 , V_15 , V_16 ) + 0x76f988da + V_5 [ 23 ] ;
V_18 = F_10 ( V_10 ) + F_2 ( V_10 , V_11 , V_12 ) ; V_13 += V_17 ; V_9 = V_17 + V_18 ;
V_17 = V_16 + F_9 ( V_13 ) + F_1 ( V_13 , V_14 , V_15 ) + 0x983e5152 + V_5 [ 24 ] ;
V_18 = F_10 ( V_9 ) + F_2 ( V_9 , V_10 , V_11 ) ; V_12 += V_17 ; V_16 = V_17 + V_18 ;
V_17 = V_15 + F_9 ( V_12 ) + F_1 ( V_12 , V_13 , V_14 ) + 0xa831c66d + V_5 [ 25 ] ;
V_18 = F_10 ( V_16 ) + F_2 ( V_16 , V_9 , V_10 ) ; V_11 += V_17 ; V_15 = V_17 + V_18 ;
V_17 = V_14 + F_9 ( V_11 ) + F_1 ( V_11 , V_12 , V_13 ) + 0xb00327c8 + V_5 [ 26 ] ;
V_18 = F_10 ( V_15 ) + F_2 ( V_15 , V_16 , V_9 ) ; V_10 += V_17 ; V_14 = V_17 + V_18 ;
V_17 = V_13 + F_9 ( V_10 ) + F_1 ( V_10 , V_11 , V_12 ) + 0xbf597fc7 + V_5 [ 27 ] ;
V_18 = F_10 ( V_14 ) + F_2 ( V_14 , V_15 , V_16 ) ; V_9 += V_17 ; V_13 = V_17 + V_18 ;
V_17 = V_12 + F_9 ( V_9 ) + F_1 ( V_9 , V_10 , V_11 ) + 0xc6e00bf3 + V_5 [ 28 ] ;
V_18 = F_10 ( V_13 ) + F_2 ( V_13 , V_14 , V_15 ) ; V_16 += V_17 ; V_12 = V_17 + V_18 ;
V_17 = V_11 + F_9 ( V_16 ) + F_1 ( V_16 , V_9 , V_10 ) + 0xd5a79147 + V_5 [ 29 ] ;
V_18 = F_10 ( V_12 ) + F_2 ( V_12 , V_13 , V_14 ) ; V_15 += V_17 ; V_11 = V_17 + V_18 ;
V_17 = V_10 + F_9 ( V_15 ) + F_1 ( V_15 , V_16 , V_9 ) + 0x06ca6351 + V_5 [ 30 ] ;
V_18 = F_10 ( V_11 ) + F_2 ( V_11 , V_12 , V_13 ) ; V_14 += V_17 ; V_10 = V_17 + V_18 ;
V_17 = V_9 + F_9 ( V_14 ) + F_1 ( V_14 , V_15 , V_16 ) + 0x14292967 + V_5 [ 31 ] ;
V_18 = F_10 ( V_10 ) + F_2 ( V_10 , V_11 , V_12 ) ; V_13 += V_17 ; V_9 = V_17 + V_18 ;
V_17 = V_16 + F_9 ( V_13 ) + F_1 ( V_13 , V_14 , V_15 ) + 0x27b70a85 + V_5 [ 32 ] ;
V_18 = F_10 ( V_9 ) + F_2 ( V_9 , V_10 , V_11 ) ; V_12 += V_17 ; V_16 = V_17 + V_18 ;
V_17 = V_15 + F_9 ( V_12 ) + F_1 ( V_12 , V_13 , V_14 ) + 0x2e1b2138 + V_5 [ 33 ] ;
V_18 = F_10 ( V_16 ) + F_2 ( V_16 , V_9 , V_10 ) ; V_11 += V_17 ; V_15 = V_17 + V_18 ;
V_17 = V_14 + F_9 ( V_11 ) + F_1 ( V_11 , V_12 , V_13 ) + 0x4d2c6dfc + V_5 [ 34 ] ;
V_18 = F_10 ( V_15 ) + F_2 ( V_15 , V_16 , V_9 ) ; V_10 += V_17 ; V_14 = V_17 + V_18 ;
V_17 = V_13 + F_9 ( V_10 ) + F_1 ( V_10 , V_11 , V_12 ) + 0x53380d13 + V_5 [ 35 ] ;
V_18 = F_10 ( V_14 ) + F_2 ( V_14 , V_15 , V_16 ) ; V_9 += V_17 ; V_13 = V_17 + V_18 ;
V_17 = V_12 + F_9 ( V_9 ) + F_1 ( V_9 , V_10 , V_11 ) + 0x650a7354 + V_5 [ 36 ] ;
V_18 = F_10 ( V_13 ) + F_2 ( V_13 , V_14 , V_15 ) ; V_16 += V_17 ; V_12 = V_17 + V_18 ;
V_17 = V_11 + F_9 ( V_16 ) + F_1 ( V_16 , V_9 , V_10 ) + 0x766a0abb + V_5 [ 37 ] ;
V_18 = F_10 ( V_12 ) + F_2 ( V_12 , V_13 , V_14 ) ; V_15 += V_17 ; V_11 = V_17 + V_18 ;
V_17 = V_10 + F_9 ( V_15 ) + F_1 ( V_15 , V_16 , V_9 ) + 0x81c2c92e + V_5 [ 38 ] ;
V_18 = F_10 ( V_11 ) + F_2 ( V_11 , V_12 , V_13 ) ; V_14 += V_17 ; V_10 = V_17 + V_18 ;
V_17 = V_9 + F_9 ( V_14 ) + F_1 ( V_14 , V_15 , V_16 ) + 0x92722c85 + V_5 [ 39 ] ;
V_18 = F_10 ( V_10 ) + F_2 ( V_10 , V_11 , V_12 ) ; V_13 += V_17 ; V_9 = V_17 + V_18 ;
V_17 = V_16 + F_9 ( V_13 ) + F_1 ( V_13 , V_14 , V_15 ) + 0xa2bfe8a1 + V_5 [ 40 ] ;
V_18 = F_10 ( V_9 ) + F_2 ( V_9 , V_10 , V_11 ) ; V_12 += V_17 ; V_16 = V_17 + V_18 ;
V_17 = V_15 + F_9 ( V_12 ) + F_1 ( V_12 , V_13 , V_14 ) + 0xa81a664b + V_5 [ 41 ] ;
V_18 = F_10 ( V_16 ) + F_2 ( V_16 , V_9 , V_10 ) ; V_11 += V_17 ; V_15 = V_17 + V_18 ;
V_17 = V_14 + F_9 ( V_11 ) + F_1 ( V_11 , V_12 , V_13 ) + 0xc24b8b70 + V_5 [ 42 ] ;
V_18 = F_10 ( V_15 ) + F_2 ( V_15 , V_16 , V_9 ) ; V_10 += V_17 ; V_14 = V_17 + V_18 ;
V_17 = V_13 + F_9 ( V_10 ) + F_1 ( V_10 , V_11 , V_12 ) + 0xc76c51a3 + V_5 [ 43 ] ;
V_18 = F_10 ( V_14 ) + F_2 ( V_14 , V_15 , V_16 ) ; V_9 += V_17 ; V_13 = V_17 + V_18 ;
V_17 = V_12 + F_9 ( V_9 ) + F_1 ( V_9 , V_10 , V_11 ) + 0xd192e819 + V_5 [ 44 ] ;
V_18 = F_10 ( V_13 ) + F_2 ( V_13 , V_14 , V_15 ) ; V_16 += V_17 ; V_12 = V_17 + V_18 ;
V_17 = V_11 + F_9 ( V_16 ) + F_1 ( V_16 , V_9 , V_10 ) + 0xd6990624 + V_5 [ 45 ] ;
V_18 = F_10 ( V_12 ) + F_2 ( V_12 , V_13 , V_14 ) ; V_15 += V_17 ; V_11 = V_17 + V_18 ;
V_17 = V_10 + F_9 ( V_15 ) + F_1 ( V_15 , V_16 , V_9 ) + 0xf40e3585 + V_5 [ 46 ] ;
V_18 = F_10 ( V_11 ) + F_2 ( V_11 , V_12 , V_13 ) ; V_14 += V_17 ; V_10 = V_17 + V_18 ;
V_17 = V_9 + F_9 ( V_14 ) + F_1 ( V_14 , V_15 , V_16 ) + 0x106aa070 + V_5 [ 47 ] ;
V_18 = F_10 ( V_10 ) + F_2 ( V_10 , V_11 , V_12 ) ; V_13 += V_17 ; V_9 = V_17 + V_18 ;
V_17 = V_16 + F_9 ( V_13 ) + F_1 ( V_13 , V_14 , V_15 ) + 0x19a4c116 + V_5 [ 48 ] ;
V_18 = F_10 ( V_9 ) + F_2 ( V_9 , V_10 , V_11 ) ; V_12 += V_17 ; V_16 = V_17 + V_18 ;
V_17 = V_15 + F_9 ( V_12 ) + F_1 ( V_12 , V_13 , V_14 ) + 0x1e376c08 + V_5 [ 49 ] ;
V_18 = F_10 ( V_16 ) + F_2 ( V_16 , V_9 , V_10 ) ; V_11 += V_17 ; V_15 = V_17 + V_18 ;
V_17 = V_14 + F_9 ( V_11 ) + F_1 ( V_11 , V_12 , V_13 ) + 0x2748774c + V_5 [ 50 ] ;
V_18 = F_10 ( V_15 ) + F_2 ( V_15 , V_16 , V_9 ) ; V_10 += V_17 ; V_14 = V_17 + V_18 ;
V_17 = V_13 + F_9 ( V_10 ) + F_1 ( V_10 , V_11 , V_12 ) + 0x34b0bcb5 + V_5 [ 51 ] ;
V_18 = F_10 ( V_14 ) + F_2 ( V_14 , V_15 , V_16 ) ; V_9 += V_17 ; V_13 = V_17 + V_18 ;
V_17 = V_12 + F_9 ( V_9 ) + F_1 ( V_9 , V_10 , V_11 ) + 0x391c0cb3 + V_5 [ 52 ] ;
V_18 = F_10 ( V_13 ) + F_2 ( V_13 , V_14 , V_15 ) ; V_16 += V_17 ; V_12 = V_17 + V_18 ;
V_17 = V_11 + F_9 ( V_16 ) + F_1 ( V_16 , V_9 , V_10 ) + 0x4ed8aa4a + V_5 [ 53 ] ;
V_18 = F_10 ( V_12 ) + F_2 ( V_12 , V_13 , V_14 ) ; V_15 += V_17 ; V_11 = V_17 + V_18 ;
V_17 = V_10 + F_9 ( V_15 ) + F_1 ( V_15 , V_16 , V_9 ) + 0x5b9cca4f + V_5 [ 54 ] ;
V_18 = F_10 ( V_11 ) + F_2 ( V_11 , V_12 , V_13 ) ; V_14 += V_17 ; V_10 = V_17 + V_18 ;
V_17 = V_9 + F_9 ( V_14 ) + F_1 ( V_14 , V_15 , V_16 ) + 0x682e6ff3 + V_5 [ 55 ] ;
V_18 = F_10 ( V_10 ) + F_2 ( V_10 , V_11 , V_12 ) ; V_13 += V_17 ; V_9 = V_17 + V_18 ;
V_17 = V_16 + F_9 ( V_13 ) + F_1 ( V_13 , V_14 , V_15 ) + 0x748f82ee + V_5 [ 56 ] ;
V_18 = F_10 ( V_9 ) + F_2 ( V_9 , V_10 , V_11 ) ; V_12 += V_17 ; V_16 = V_17 + V_18 ;
V_17 = V_15 + F_9 ( V_12 ) + F_1 ( V_12 , V_13 , V_14 ) + 0x78a5636f + V_5 [ 57 ] ;
V_18 = F_10 ( V_16 ) + F_2 ( V_16 , V_9 , V_10 ) ; V_11 += V_17 ; V_15 = V_17 + V_18 ;
V_17 = V_14 + F_9 ( V_11 ) + F_1 ( V_11 , V_12 , V_13 ) + 0x84c87814 + V_5 [ 58 ] ;
V_18 = F_10 ( V_15 ) + F_2 ( V_15 , V_16 , V_9 ) ; V_10 += V_17 ; V_14 = V_17 + V_18 ;
V_17 = V_13 + F_9 ( V_10 ) + F_1 ( V_10 , V_11 , V_12 ) + 0x8cc70208 + V_5 [ 59 ] ;
V_18 = F_10 ( V_14 ) + F_2 ( V_14 , V_15 , V_16 ) ; V_9 += V_17 ; V_13 = V_17 + V_18 ;
V_17 = V_12 + F_9 ( V_9 ) + F_1 ( V_9 , V_10 , V_11 ) + 0x90befffa + V_5 [ 60 ] ;
V_18 = F_10 ( V_13 ) + F_2 ( V_13 , V_14 , V_15 ) ; V_16 += V_17 ; V_12 = V_17 + V_18 ;
V_17 = V_11 + F_9 ( V_16 ) + F_1 ( V_16 , V_9 , V_10 ) + 0xa4506ceb + V_5 [ 61 ] ;
V_18 = F_10 ( V_12 ) + F_2 ( V_12 , V_13 , V_14 ) ; V_15 += V_17 ; V_11 = V_17 + V_18 ;
V_17 = V_10 + F_9 ( V_15 ) + F_1 ( V_15 , V_16 , V_9 ) + 0xbef9a3f7 + V_5 [ 62 ] ;
V_18 = F_10 ( V_11 ) + F_2 ( V_11 , V_12 , V_13 ) ; V_14 += V_17 ; V_10 = V_17 + V_18 ;
V_17 = V_9 + F_9 ( V_14 ) + F_1 ( V_14 , V_15 , V_16 ) + 0xc67178f2 + V_5 [ 63 ] ;
V_18 = F_10 ( V_10 ) + F_2 ( V_10 , V_11 , V_12 ) ; V_13 += V_17 ; V_9 = V_17 + V_18 ;
V_8 [ 0 ] += V_9 ; V_8 [ 1 ] += V_10 ; V_8 [ 2 ] += V_11 ; V_8 [ 3 ] += V_12 ;
V_8 [ 4 ] += V_13 ; V_8 [ 5 ] += V_14 ; V_8 [ 6 ] += V_15 ; V_8 [ 7 ] += V_16 ;
V_9 = V_10 = V_11 = V_12 = V_13 = V_14 = V_15 = V_16 = V_17 = V_18 = 0 ;
memset ( V_5 , 0 , 64 * sizeof( T_1 ) ) ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_12 ( V_21 ) ;
V_23 -> V_8 [ 0 ] = V_24 ;
V_23 -> V_8 [ 1 ] = V_25 ;
V_23 -> V_8 [ 2 ] = V_26 ;
V_23 -> V_8 [ 3 ] = V_27 ;
V_23 -> V_8 [ 4 ] = V_28 ;
V_23 -> V_8 [ 5 ] = V_29 ;
V_23 -> V_8 [ 6 ] = V_30 ;
V_23 -> V_8 [ 7 ] = V_31 ;
V_23 -> V_32 = 0 ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_12 ( V_21 ) ;
V_23 -> V_8 [ 0 ] = V_33 ;
V_23 -> V_8 [ 1 ] = V_34 ;
V_23 -> V_8 [ 2 ] = V_35 ;
V_23 -> V_8 [ 3 ] = V_36 ;
V_23 -> V_8 [ 4 ] = V_37 ;
V_23 -> V_8 [ 5 ] = V_38 ;
V_23 -> V_8 [ 6 ] = V_39 ;
V_23 -> V_8 [ 7 ] = V_40 ;
V_23 -> V_32 = 0 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 , const T_2 * V_41 ,
unsigned int V_42 )
{
struct V_22 * V_23 = F_12 ( V_21 ) ;
unsigned int V_43 , V_44 ;
const T_2 * V_45 ;
V_43 = V_23 -> V_32 & 0x3f ;
V_23 -> V_32 += V_42 ;
V_44 = 0 ;
V_45 = V_41 ;
if ( ( V_43 + V_42 ) > 63 ) {
if ( V_43 ) {
V_44 = - V_43 ;
memcpy ( V_23 -> V_46 + V_43 , V_41 , V_44 + 64 ) ;
V_45 = V_23 -> V_46 ;
}
do {
F_8 ( V_23 -> V_8 , V_45 ) ;
V_44 += 64 ;
V_45 = V_41 + V_44 ;
} while ( V_44 + 63 < V_42 );
V_43 = 0 ;
}
memcpy ( V_23 -> V_46 + V_43 , V_45 , V_42 - V_44 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , T_2 * V_47 )
{
struct V_22 * V_23 = F_12 ( V_21 ) ;
V_7 * V_48 = ( V_7 * ) V_47 ;
T_3 V_49 ;
unsigned int V_50 , V_51 ;
int V_19 ;
static const T_2 V_52 [ 64 ] = { 0x80 , } ;
V_49 = F_16 ( V_23 -> V_32 << 3 ) ;
V_50 = V_23 -> V_32 & 0x3f ;
V_51 = ( V_50 < 56 ) ? ( 56 - V_50 ) : ( ( 64 + 56 ) - V_50 ) ;
F_14 ( V_21 , V_52 , V_51 ) ;
F_14 ( V_21 , ( const T_2 * ) & V_49 , sizeof( V_49 ) ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
V_48 [ V_19 ] = F_17 ( V_23 -> V_8 [ V_19 ] ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
return 0 ;
}
static int F_18 ( struct V_20 * V_21 , T_2 * V_53 )
{
T_2 V_54 [ V_55 ] ;
F_15 ( V_21 , V_54 ) ;
memcpy ( V_53 , V_54 , V_56 ) ;
memset ( V_54 , 0 , V_55 ) ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 , void * V_47 )
{
struct V_22 * V_23 = F_12 ( V_21 ) ;
memcpy ( V_47 , V_23 , sizeof( * V_23 ) ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 , const void * V_57 )
{
struct V_22 * V_23 = F_12 ( V_21 ) ;
memcpy ( V_23 , V_57 , sizeof( * V_23 ) ) ;
return 0 ;
}
static int T_4 F_21 ( void )
{
int V_58 = 0 ;
V_58 = F_22 ( & V_59 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_22 ( & V_60 ) ;
if ( V_58 < 0 )
F_23 ( & V_59 ) ;
return V_58 ;
}
static void T_5 F_24 ( void )
{
F_23 ( & V_59 ) ;
F_23 ( & V_60 ) ;
}
