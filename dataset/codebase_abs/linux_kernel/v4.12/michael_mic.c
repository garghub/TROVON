static
void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
V_2 -> V_4 = F_2 ( V_3 , 0 ) ;
V_2 -> V_5 = F_2 ( V_3 , 4 ) ;
F_3 ( V_2 ) ;
}
static
void F_4 ( struct V_1 * V_2 , T_1 * V_6 , int V_7 )
{
int V_8 ;
if ( V_2 -> V_9 ) {
V_8 = 4 - V_2 -> V_9 ;
if ( V_8 > V_7 )
V_8 = V_7 ;
memcpy ( & V_2 -> V_10 [ V_2 -> V_9 ] , V_6 , V_8 ) ;
V_2 -> V_9 += V_8 ;
V_6 += V_8 ;
V_7 -= V_8 ;
if ( V_2 -> V_9 < 4 )
return;
V_2 -> V_11 ^= F_2 ( V_2 -> V_10 , 0 ) ;
F_5 ( V_2 -> V_11 , V_2 -> V_12 ) ;
V_2 -> V_9 = 0 ;
}
while ( V_7 >= 4 ) {
V_2 -> V_11 ^= F_2 ( V_6 , 0 ) ;
F_5 ( V_2 -> V_11 , V_2 -> V_12 ) ;
V_6 += 4 ;
V_7 -= 4 ;
}
if ( V_7 > 0 ) {
V_2 -> V_9 = V_7 ;
memcpy ( V_2 -> V_10 , V_6 , V_7 ) ;
}
}
static
void F_6 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_2 * V_14 = V_2 -> V_10 ;
switch ( V_2 -> V_9 ) {
case 0 :
V_2 -> V_11 ^= 0x5a ;
break;
case 1 :
V_2 -> V_11 ^= V_14 [ 0 ] | 0x5a00 ;
break;
case 2 :
V_2 -> V_11 ^= V_14 [ 0 ] | ( V_14 [ 1 ] << 8 ) | 0x5a0000 ;
break;
case 3 :
V_2 -> V_11 ^= V_14 [ 0 ] | ( V_14 [ 1 ] << 8 ) | ( V_14 [ 2 ] << 16 ) |
0x5a000000 ;
break;
}
F_5 ( V_2 -> V_11 , V_2 -> V_12 ) ;
F_5 ( V_2 -> V_11 , V_2 -> V_12 ) ;
F_7 ( V_13 , 0 , V_2 -> V_11 ) ;
F_7 ( V_13 , 4 , V_2 -> V_12 ) ;
F_3 ( V_2 ) ;
}
void F_8 ( struct V_1 * V_2 , T_2 * V_15 ,
T_2 * V_16 , int V_17 , T_2 V_18 ,
T_2 * V_19 )
{
T_2 V_20 [ 4 ] = { V_18 , 0 , 0 , 0 } ;
F_1 ( V_2 , V_15 ) ;
F_4 ( V_2 , ( T_1 * ) V_16 , 12 ) ;
F_4 ( V_2 , V_20 , 4 ) ;
F_4 ( V_2 , ( T_1 * ) ( V_16 + 12 ) , V_17 - 12 ) ;
F_6 ( V_2 , V_19 ) ;
}
