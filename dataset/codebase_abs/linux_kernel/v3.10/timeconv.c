static int F_1 ( long V_1 )
{
return ( V_1 ) % 4 == 0 && ( ( V_1 ) % 100 != 0 || ( V_1 ) % 400 == 0 ) ;
}
static long F_2 ( long V_2 , long V_3 )
{
return V_2 / V_3 - ( V_2 % V_3 < 0 ) ;
}
static long F_3 ( long y1 , long V_4 )
{
long V_5 = F_2 ( y1 - 1 , 4 ) - F_2 ( y1 - 1 , 100 )
+ F_2 ( y1 - 1 , 400 ) ;
long V_6 = F_2 ( V_4 - 1 , 4 ) - F_2 ( V_4 - 1 , 100 )
+ F_2 ( V_4 - 1 , 400 ) ;
return V_6 - V_5 ;
}
void F_4 ( T_1 V_7 , int V_8 , struct V_9 * V_10 )
{
long V_11 , V_12 , V_13 ;
const unsigned short * V_14 ;
V_11 = V_7 / V_15 ;
V_12 = V_7 % V_15 ;
V_12 += V_8 ;
while ( V_12 < 0 ) {
V_12 += V_15 ;
-- V_11 ;
}
while ( V_12 >= V_15 ) {
V_12 -= V_15 ;
++ V_11 ;
}
V_10 -> V_16 = V_12 / V_17 ;
V_12 %= V_17 ;
V_10 -> V_18 = V_12 / 60 ;
V_10 -> V_19 = V_12 % 60 ;
V_10 -> V_20 = ( 4 + V_11 ) % 7 ;
if ( V_10 -> V_20 < 0 )
V_10 -> V_20 += 7 ;
V_13 = 1970 ;
while ( V_11 < 0 || V_11 >= ( F_1 ( V_13 ) ? 366 : 365 ) ) {
long V_21 = V_13 + F_2 ( V_11 , 365 ) ;
V_11 -= ( V_21 - V_13 ) * 365 + F_3 ( V_13 , V_21 ) ;
V_13 = V_21 ;
}
V_10 -> V_22 = V_13 - 1900 ;
V_10 -> V_23 = V_11 ;
V_14 = V_24 [ F_1 ( V_13 ) ] ;
for ( V_13 = 11 ; V_11 < V_14 [ V_13 ] ; V_13 -- )
continue;
V_11 -= V_14 [ V_13 ] ;
V_10 -> V_25 = V_13 ;
V_10 -> V_26 = V_11 + 1 ;
}
