int F_1 ( int V_1 , const T_1 * V_2 , T_2 V_3 )
{
register T_3 V_4 , V_5 , V_6 , V_7 ;
V_3 [ 0 ] = V_4 = F_2 ( V_2 ) ;
V_3 [ 1 ] = V_5 = F_2 ( V_2 + 4 ) ;
V_3 [ 2 ] = V_6 = F_2 ( V_2 + 8 ) ;
V_3 [ 3 ] = V_7 = F_2 ( V_2 + 12 ) ;
if ( V_1 != 128 )
{
V_3 [ 8 ] = V_4 = F_2 ( V_2 + 16 ) ;
V_3 [ 9 ] = V_5 = F_2 ( V_2 + 20 ) ;
if ( V_1 == 192 )
{
V_3 [ 10 ] = V_6 = ~ V_4 ;
V_3 [ 11 ] = V_7 = ~ V_5 ;
}
else
{
V_3 [ 10 ] = V_6 = F_2 ( V_2 + 24 ) ;
V_3 [ 11 ] = V_7 = F_2 ( V_2 + 28 ) ;
}
V_4 ^= V_3 [ 0 ] , V_5 ^= V_3 [ 1 ] , V_6 ^= V_3 [ 2 ] , V_7 ^= V_3 [ 3 ] ;
}
F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 + 0 ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , V_8 + 2 ) ;
V_4 ^= V_3 [ 0 ] , V_5 ^= V_3 [ 1 ] , V_6 ^= V_3 [ 2 ] , V_7 ^= V_3 [ 3 ] ;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 + 4 ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , V_8 + 6 ) ;
if ( V_1 == 128 )
{
V_3 [ 4 ] = V_4 , V_3 [ 5 ] = V_5 , V_3 [ 6 ] = V_6 , V_3 [ 7 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 12 ] = V_4 , V_3 [ 13 ] = V_5 , V_3 [ 14 ] = V_6 , V_3 [ 15 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 16 ] = V_4 , V_3 [ 17 ] = V_5 , V_3 [ 18 ] = V_6 , V_3 [ 19 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 24 ] = V_4 , V_3 [ 25 ] = V_5 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 28 ] = V_4 , V_3 [ 29 ] = V_5 , V_3 [ 30 ] = V_6 , V_3 [ 31 ] = V_7 ;
F_4 ( V_5 , V_6 , V_7 , V_4 , 2 ) ;
V_3 [ 40 ] = V_5 , V_3 [ 41 ] = V_6 , V_3 [ 42 ] = V_7 , V_3 [ 43 ] = V_4 ;
F_4 ( V_5 , V_6 , V_7 , V_4 , 17 ) ;
V_3 [ 48 ] = V_5 , V_3 [ 49 ] = V_6 , V_3 [ 50 ] = V_7 , V_3 [ 51 ] = V_4 ;
V_4 = V_3 [ 0 ] , V_5 = V_3 [ 1 ] , V_6 = V_3 [ 2 ] , V_7 = V_3 [ 3 ] ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 8 ] = V_4 , V_3 [ 9 ] = V_5 , V_3 [ 10 ] = V_6 , V_3 [ 11 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 30 ) ;
V_3 [ 20 ] = V_4 , V_3 [ 21 ] = V_5 , V_3 [ 22 ] = V_6 , V_3 [ 23 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 26 ] = V_6 , V_3 [ 27 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 17 ) ;
V_3 [ 32 ] = V_4 , V_3 [ 33 ] = V_5 , V_3 [ 34 ] = V_6 , V_3 [ 35 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 17 ) ;
V_3 [ 36 ] = V_4 , V_3 [ 37 ] = V_5 , V_3 [ 38 ] = V_6 , V_3 [ 39 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 17 ) ;
V_3 [ 44 ] = V_4 , V_3 [ 45 ] = V_5 , V_3 [ 46 ] = V_6 , V_3 [ 47 ] = V_7 ;
return 3 ;
}
else
{
V_3 [ 12 ] = V_4 , V_3 [ 13 ] = V_5 , V_3 [ 14 ] = V_6 , V_3 [ 15 ] = V_7 ;
V_4 ^= V_3 [ 8 ] , V_5 ^= V_3 [ 9 ] , V_6 ^= V_3 [ 10 ] , V_7 ^= V_3 [ 11 ] ;
F_3 ( V_4 , V_5 , V_6 , V_7 , ( V_8 + 8 ) ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , ( V_8 + 10 ) ) ;
V_3 [ 4 ] = V_4 , V_3 [ 5 ] = V_5 , V_3 [ 6 ] = V_6 , V_3 [ 7 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 30 ) ;
V_3 [ 20 ] = V_4 , V_3 [ 21 ] = V_5 , V_3 [ 22 ] = V_6 , V_3 [ 23 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 30 ) ;
V_3 [ 40 ] = V_4 , V_3 [ 41 ] = V_5 , V_3 [ 42 ] = V_6 , V_3 [ 43 ] = V_7 ;
F_4 ( V_5 , V_6 , V_7 , V_4 , 19 ) ;
V_3 [ 64 ] = V_5 , V_3 [ 65 ] = V_6 , V_3 [ 66 ] = V_7 , V_3 [ 67 ] = V_4 ;
V_4 = V_3 [ 8 ] , V_5 = V_3 [ 9 ] , V_6 = V_3 [ 10 ] , V_7 = V_3 [ 11 ] ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 8 ] = V_4 , V_3 [ 9 ] = V_5 , V_3 [ 10 ] = V_6 , V_3 [ 11 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 16 ] = V_4 , V_3 [ 17 ] = V_5 , V_3 [ 18 ] = V_6 , V_3 [ 19 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 30 ) ;
V_3 [ 36 ] = V_4 , V_3 [ 37 ] = V_5 , V_3 [ 38 ] = V_6 , V_3 [ 39 ] = V_7 ;
F_4 ( V_5 , V_6 , V_7 , V_4 , 2 ) ;
V_3 [ 52 ] = V_5 , V_3 [ 53 ] = V_6 , V_3 [ 54 ] = V_7 , V_3 [ 55 ] = V_4 ;
V_4 = V_3 [ 12 ] , V_5 = V_3 [ 13 ] , V_6 = V_3 [ 14 ] , V_7 = V_3 [ 15 ] ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 15 ) ;
V_3 [ 12 ] = V_4 , V_3 [ 13 ] = V_5 , V_3 [ 14 ] = V_6 , V_3 [ 15 ] = V_7 ;
F_4 ( V_4 , V_5 , V_6 , V_7 , 30 ) ;
V_3 [ 28 ] = V_4 , V_3 [ 29 ] = V_5 , V_3 [ 30 ] = V_6 , V_3 [ 31 ] = V_7 ;
V_3 [ 48 ] = V_5 , V_3 [ 49 ] = V_6 , V_3 [ 50 ] = V_7 , V_3 [ 51 ] = V_4 ;
F_4 ( V_5 , V_6 , V_7 , V_4 , 17 ) ;
V_3 [ 56 ] = V_5 , V_3 [ 57 ] = V_6 , V_3 [ 58 ] = V_7 , V_3 [ 59 ] = V_4 ;
V_4 = V_3 [ 0 ] , V_5 = V_3 [ 1 ] , V_6 = V_3 [ 2 ] , V_7 = V_3 [ 3 ] ;
F_4 ( V_5 , V_6 , V_7 , V_4 , 13 ) ;
V_3 [ 24 ] = V_5 , V_3 [ 25 ] = V_6 , V_3 [ 26 ] = V_7 , V_3 [ 27 ] = V_4 ;
F_4 ( V_5 , V_6 , V_7 , V_4 , 15 ) ;
V_3 [ 32 ] = V_5 , V_3 [ 33 ] = V_6 , V_3 [ 34 ] = V_7 , V_3 [ 35 ] = V_4 ;
F_4 ( V_5 , V_6 , V_7 , V_4 , 17 ) ;
V_3 [ 44 ] = V_5 , V_3 [ 45 ] = V_6 , V_3 [ 46 ] = V_7 , V_3 [ 47 ] = V_4 ;
F_4 ( V_6 , V_7 , V_4 , V_5 , 2 ) ;
V_3 [ 60 ] = V_6 , V_3 [ 61 ] = V_7 , V_3 [ 62 ] = V_4 , V_3 [ 63 ] = V_5 ;
return 4 ;
}
}
void F_5 ( int V_9 , const T_1 V_10 [] ,
const T_2 V_11 , T_1 V_12 [] )
{
register T_3 V_4 , V_5 , V_6 , V_7 ;
const T_3 * V_3 = V_11 , * V_13 = V_11 + V_9 * 16 ;
V_4 = F_2 ( V_10 ) ^ V_3 [ 0 ] ;
V_5 = F_2 ( V_10 + 4 ) ^ V_3 [ 1 ] ;
V_6 = F_2 ( V_10 + 8 ) ^ V_3 [ 2 ] ;
V_7 = F_2 ( V_10 + 12 ) ^ V_3 [ 3 ] ;
V_3 += 4 ;
while ( 1 )
{
F_3 ( V_4 , V_5 , V_6 , V_7 , V_3 + 0 ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , V_3 + 2 ) ;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_3 + 4 ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , V_3 + 6 ) ;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_3 + 8 ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , V_3 + 10 ) ;
V_3 += 12 ;
if ( V_3 == V_13 ) break;
V_5 ^= F_6 ( V_4 & V_3 [ 0 ] , 1 ) ;
V_6 ^= V_7 | V_3 [ 3 ] ;
V_4 ^= V_5 | V_3 [ 1 ] ;
V_7 ^= F_6 ( V_6 & V_3 [ 2 ] , 1 ) ;
V_3 += 4 ;
}
V_6 ^= V_3 [ 0 ] , V_7 ^= V_3 [ 1 ] , V_4 ^= V_3 [ 2 ] , V_5 ^= V_3 [ 3 ] ;
F_7 ( V_12 , V_6 ) ;
F_7 ( V_12 + 4 , V_7 ) ;
F_7 ( V_12 + 8 , V_4 ) ;
F_7 ( V_12 + 12 , V_5 ) ;
}
void F_8 ( int V_1 , const T_1 V_10 [] ,
const T_2 V_11 , T_1 V_12 [] )
{
F_5 ( V_1 == 128 ? 3 : 4 ,
V_10 , V_11 , V_12 ) ;
}
void F_9 ( int V_9 , const T_1 V_12 [] ,
const T_2 V_11 , T_1 V_10 [] )
{
T_3 V_4 , V_5 , V_6 , V_7 ;
const T_3 * V_3 = V_11 + V_9 * 16 , * V_13 = V_11 + 4 ;
V_4 = F_2 ( V_12 ) ^ V_3 [ 0 ] ;
V_5 = F_2 ( V_12 + 4 ) ^ V_3 [ 1 ] ;
V_6 = F_2 ( V_12 + 8 ) ^ V_3 [ 2 ] ;
V_7 = F_2 ( V_12 + 12 ) ^ V_3 [ 3 ] ;
while ( 1 )
{
V_3 -= 12 ;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_3 + 10 ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , V_3 + 8 ) ;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_3 + 6 ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , V_3 + 4 ) ;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_3 + 2 ) ;
F_3 ( V_6 , V_7 , V_4 , V_5 , V_3 + 0 ) ;
if ( V_3 == V_13 ) break;
V_3 -= 4 ;
V_5 ^= F_6 ( V_4 & V_3 [ 2 ] , 1 ) ;
V_6 ^= V_7 | V_3 [ 1 ] ;
V_4 ^= V_5 | V_3 [ 3 ] ;
V_7 ^= F_6 ( V_6 & V_3 [ 0 ] , 1 ) ;
}
V_3 -= 4 ;
V_6 ^= V_3 [ 0 ] , V_7 ^= V_3 [ 1 ] , V_4 ^= V_3 [ 2 ] , V_5 ^= V_3 [ 3 ] ;
F_7 ( V_10 , V_6 ) ;
F_7 ( V_10 + 4 , V_7 ) ;
F_7 ( V_10 + 8 , V_4 ) ;
F_7 ( V_10 + 12 , V_5 ) ;
}
void F_10 ( int V_1 , const T_1 V_10 [] ,
const T_2 V_11 , T_1 V_12 [] )
{
F_9 ( V_1 == 128 ? 3 : 4 ,
V_10 , V_11 , V_12 ) ;
}
