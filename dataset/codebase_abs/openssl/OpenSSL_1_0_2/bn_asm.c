T_1 F_1 ( T_1 * V_1 , const T_1 * V_2 , int V_3 ,
T_1 V_4 )
{
T_1 V_5 = 0 ;
assert ( V_3 >= 0 ) ;
if ( V_3 <= 0 )
return ( V_5 ) ;
# ifndef F_2
while ( V_3 & ~ 3 ) {
F_3 ( V_1 [ 0 ] , V_2 [ 0 ] , V_4 , V_5 ) ;
F_3 ( V_1 [ 1 ] , V_2 [ 1 ] , V_4 , V_5 ) ;
F_3 ( V_1 [ 2 ] , V_2 [ 2 ] , V_4 , V_5 ) ;
F_3 ( V_1 [ 3 ] , V_2 [ 3 ] , V_4 , V_5 ) ;
V_2 += 4 ;
V_1 += 4 ;
V_3 -= 4 ;
}
# endif
while ( V_3 ) {
F_3 ( V_1 [ 0 ] , V_2 [ 0 ] , V_4 , V_5 ) ;
V_2 ++ ;
V_1 ++ ;
V_3 -- ;
}
return ( V_5 ) ;
}
T_1 F_4 ( T_1 * V_1 , const T_1 * V_2 , int V_3 , T_1 V_4 )
{
T_1 V_5 = 0 ;
assert ( V_3 >= 0 ) ;
if ( V_3 <= 0 )
return ( V_5 ) ;
# ifndef F_2
while ( V_3 & ~ 3 ) {
F_5 ( V_1 [ 0 ] , V_2 [ 0 ] , V_4 , V_5 ) ;
F_5 ( V_1 [ 1 ] , V_2 [ 1 ] , V_4 , V_5 ) ;
F_5 ( V_1 [ 2 ] , V_2 [ 2 ] , V_4 , V_5 ) ;
F_5 ( V_1 [ 3 ] , V_2 [ 3 ] , V_4 , V_5 ) ;
V_2 += 4 ;
V_1 += 4 ;
V_3 -= 4 ;
}
# endif
while ( V_3 ) {
F_5 ( V_1 [ 0 ] , V_2 [ 0 ] , V_4 , V_5 ) ;
V_2 ++ ;
V_1 ++ ;
V_3 -- ;
}
return ( V_5 ) ;
}
void F_6 ( T_1 * V_6 , const T_1 * V_7 , int V_8 )
{
assert ( V_8 >= 0 ) ;
if ( V_8 <= 0 )
return;
# ifndef F_2
while ( V_8 & ~ 3 ) {
F_7 ( V_6 [ 0 ] , V_6 [ 1 ] , V_7 [ 0 ] ) ;
F_7 ( V_6 [ 2 ] , V_6 [ 3 ] , V_7 [ 1 ] ) ;
F_7 ( V_6 [ 4 ] , V_6 [ 5 ] , V_7 [ 2 ] ) ;
F_7 ( V_6 [ 6 ] , V_6 [ 7 ] , V_7 [ 3 ] ) ;
V_7 += 4 ;
V_6 += 8 ;
V_8 -= 4 ;
}
# endif
while ( V_8 ) {
F_7 ( V_6 [ 0 ] , V_6 [ 1 ] , V_7 [ 0 ] ) ;
V_7 ++ ;
V_6 += 2 ;
V_8 -- ;
}
}
T_1 F_1 ( T_1 * V_1 , const T_1 * V_2 , int V_3 ,
T_1 V_4 )
{
T_1 V_9 = 0 ;
T_1 V_10 , V_11 ;
assert ( V_3 >= 0 ) ;
if ( V_3 <= 0 )
return ( ( T_1 ) 0 ) ;
V_10 = F_8 ( V_4 ) ;
V_11 = F_9 ( V_4 ) ;
# ifndef F_2
while ( V_3 & ~ 3 ) {
F_3 ( V_1 [ 0 ] , V_2 [ 0 ] , V_10 , V_11 , V_9 ) ;
F_3 ( V_1 [ 1 ] , V_2 [ 1 ] , V_10 , V_11 , V_9 ) ;
F_3 ( V_1 [ 2 ] , V_2 [ 2 ] , V_10 , V_11 , V_9 ) ;
F_3 ( V_1 [ 3 ] , V_2 [ 3 ] , V_10 , V_11 , V_9 ) ;
V_2 += 4 ;
V_1 += 4 ;
V_3 -= 4 ;
}
# endif
while ( V_3 ) {
F_3 ( V_1 [ 0 ] , V_2 [ 0 ] , V_10 , V_11 , V_9 ) ;
V_2 ++ ;
V_1 ++ ;
V_3 -- ;
}
return ( V_9 ) ;
}
T_1 F_4 ( T_1 * V_1 , const T_1 * V_2 , int V_3 , T_1 V_4 )
{
T_1 V_12 = 0 ;
T_1 V_10 , V_11 ;
assert ( V_3 >= 0 ) ;
if ( V_3 <= 0 )
return ( ( T_1 ) 0 ) ;
V_10 = F_8 ( V_4 ) ;
V_11 = F_9 ( V_4 ) ;
# ifndef F_2
while ( V_3 & ~ 3 ) {
F_5 ( V_1 [ 0 ] , V_2 [ 0 ] , V_10 , V_11 , V_12 ) ;
F_5 ( V_1 [ 1 ] , V_2 [ 1 ] , V_10 , V_11 , V_12 ) ;
F_5 ( V_1 [ 2 ] , V_2 [ 2 ] , V_10 , V_11 , V_12 ) ;
F_5 ( V_1 [ 3 ] , V_2 [ 3 ] , V_10 , V_11 , V_12 ) ;
V_2 += 4 ;
V_1 += 4 ;
V_3 -= 4 ;
}
# endif
while ( V_3 ) {
F_5 ( V_1 [ 0 ] , V_2 [ 0 ] , V_10 , V_11 , V_12 ) ;
V_2 ++ ;
V_1 ++ ;
V_3 -- ;
}
return ( V_12 ) ;
}
void F_6 ( T_1 * V_6 , const T_1 * V_7 , int V_8 )
{
assert ( V_8 >= 0 ) ;
if ( V_8 <= 0 )
return;
# ifndef F_2
while ( V_8 & ~ 3 ) {
F_10 ( V_6 [ 0 ] , V_6 [ 1 ] , V_7 [ 0 ] ) ;
F_10 ( V_6 [ 2 ] , V_6 [ 3 ] , V_7 [ 1 ] ) ;
F_10 ( V_6 [ 4 ] , V_6 [ 5 ] , V_7 [ 2 ] ) ;
F_10 ( V_6 [ 6 ] , V_6 [ 7 ] , V_7 [ 3 ] ) ;
V_7 += 4 ;
V_6 += 8 ;
V_8 -= 4 ;
}
# endif
while ( V_8 ) {
F_10 ( V_6 [ 0 ] , V_6 [ 1 ] , V_7 [ 0 ] ) ;
V_7 ++ ;
V_6 += 2 ;
V_8 -- ;
}
}
T_1 F_11 ( T_1 V_13 , T_1 V_14 , T_1 V_15 )
{
return ( ( T_1 ) ( ( ( ( ( V_16 ) V_13 ) << V_17 ) | V_14 ) / ( V_16 ) V_15 ) ) ;
}
T_1 F_11 ( T_1 V_13 , T_1 V_14 , T_1 V_15 )
{
T_1 V_18 , V_19 , V_20 , V_21 = 0 , V_22 , V_23 , V_24 ;
int V_25 , V_26 = 2 ;
if ( V_15 == 0 )
return ( V_27 ) ;
V_25 = F_12 ( V_15 ) ;
assert ( ( V_25 == V_17 ) || ( V_13 <= ( T_1 ) 1 << V_25 ) ) ;
V_25 = V_17 - V_25 ;
if ( V_13 >= V_15 )
V_13 -= V_15 ;
if ( V_25 ) {
V_15 <<= V_25 ;
V_13 = ( V_13 << V_25 ) | ( V_14 >> ( V_17 - V_25 ) ) ;
V_14 <<= V_25 ;
}
V_18 = ( V_15 & V_28 ) >> V_29 ;
V_19 = ( V_15 & V_30 ) ;
for (; ; ) {
if ( ( V_13 >> V_29 ) == V_18 )
V_20 = V_30 ;
else
V_20 = V_13 / V_18 ;
V_22 = V_20 * V_18 ;
V_23 = V_19 * V_20 ;
for (; ; ) {
V_24 = V_13 - V_22 ;
if ( ( V_24 & V_28 ) ||
( ( V_23 ) <= ( ( V_24 << V_29 ) | ( ( V_14 & V_28 ) >> V_29 ) ) ) )
break;
V_20 -- ;
V_22 -= V_18 ;
V_23 -= V_19 ;
}
V_24 = ( V_23 >> V_29 ) ;
V_23 = ( V_23 << V_29 ) & V_28 ;
V_22 += V_24 ;
if ( V_14 < V_23 )
V_22 ++ ;
V_14 -= V_23 ;
if ( V_13 < V_22 ) {
V_13 += V_15 ;
V_20 -- ;
}
V_13 -= V_22 ;
if ( -- V_26 == 0 )
break;
V_21 = V_20 << V_29 ;
V_13 = ( ( V_13 << V_29 ) | ( V_14 >> V_29 ) ) & V_27 ;
V_14 = ( V_14 & V_30 ) << V_29 ;
}
V_21 |= V_20 ;
return ( V_21 ) ;
}
T_1 F_13 ( T_1 * V_6 , const T_1 * V_7 , const T_1 * V_31 ,
int V_8 )
{
V_16 V_32 = 0 ;
assert ( V_8 >= 0 ) ;
if ( V_8 <= 0 )
return ( ( T_1 ) 0 ) ;
# ifndef F_2
while ( V_8 & ~ 3 ) {
V_32 += ( V_16 ) V_7 [ 0 ] + V_31 [ 0 ] ;
V_6 [ 0 ] = ( T_1 ) V_32 & V_27 ;
V_32 >>= V_17 ;
V_32 += ( V_16 ) V_7 [ 1 ] + V_31 [ 1 ] ;
V_6 [ 1 ] = ( T_1 ) V_32 & V_27 ;
V_32 >>= V_17 ;
V_32 += ( V_16 ) V_7 [ 2 ] + V_31 [ 2 ] ;
V_6 [ 2 ] = ( T_1 ) V_32 & V_27 ;
V_32 >>= V_17 ;
V_32 += ( V_16 ) V_7 [ 3 ] + V_31 [ 3 ] ;
V_6 [ 3 ] = ( T_1 ) V_32 & V_27 ;
V_32 >>= V_17 ;
V_7 += 4 ;
V_31 += 4 ;
V_6 += 4 ;
V_8 -= 4 ;
}
# endif
while ( V_8 ) {
V_32 += ( V_16 ) V_7 [ 0 ] + V_31 [ 0 ] ;
V_6 [ 0 ] = ( T_1 ) V_32 & V_27 ;
V_32 >>= V_17 ;
V_7 ++ ;
V_31 ++ ;
V_6 ++ ;
V_8 -- ;
}
return ( ( T_1 ) V_32 ) ;
}
T_1 F_13 ( T_1 * V_6 , const T_1 * V_7 , const T_1 * V_31 ,
int V_8 )
{
T_1 V_9 , V_14 , V_24 ;
assert ( V_8 >= 0 ) ;
if ( V_8 <= 0 )
return ( ( T_1 ) 0 ) ;
V_9 = 0 ;
# ifndef F_2
while ( V_8 & ~ 3 ) {
V_24 = V_7 [ 0 ] ;
V_24 = ( V_24 + V_9 ) & V_27 ;
V_9 = ( V_24 < V_9 ) ;
V_14 = ( V_24 + V_31 [ 0 ] ) & V_27 ;
V_9 += ( V_14 < V_24 ) ;
V_6 [ 0 ] = V_14 ;
V_24 = V_7 [ 1 ] ;
V_24 = ( V_24 + V_9 ) & V_27 ;
V_9 = ( V_24 < V_9 ) ;
V_14 = ( V_24 + V_31 [ 1 ] ) & V_27 ;
V_9 += ( V_14 < V_24 ) ;
V_6 [ 1 ] = V_14 ;
V_24 = V_7 [ 2 ] ;
V_24 = ( V_24 + V_9 ) & V_27 ;
V_9 = ( V_24 < V_9 ) ;
V_14 = ( V_24 + V_31 [ 2 ] ) & V_27 ;
V_9 += ( V_14 < V_24 ) ;
V_6 [ 2 ] = V_14 ;
V_24 = V_7 [ 3 ] ;
V_24 = ( V_24 + V_9 ) & V_27 ;
V_9 = ( V_24 < V_9 ) ;
V_14 = ( V_24 + V_31 [ 3 ] ) & V_27 ;
V_9 += ( V_14 < V_24 ) ;
V_6 [ 3 ] = V_14 ;
V_7 += 4 ;
V_31 += 4 ;
V_6 += 4 ;
V_8 -= 4 ;
}
# endif
while ( V_8 ) {
V_24 = V_7 [ 0 ] ;
V_24 = ( V_24 + V_9 ) & V_27 ;
V_9 = ( V_24 < V_9 ) ;
V_14 = ( V_24 + V_31 [ 0 ] ) & V_27 ;
V_9 += ( V_14 < V_24 ) ;
V_6 [ 0 ] = V_14 ;
V_7 ++ ;
V_31 ++ ;
V_6 ++ ;
V_8 -- ;
}
return ( ( T_1 ) V_9 ) ;
}
T_1 F_14 ( T_1 * V_6 , const T_1 * V_7 , const T_1 * V_31 ,
int V_8 )
{
T_1 V_33 , V_34 ;
int V_9 = 0 ;
assert ( V_8 >= 0 ) ;
if ( V_8 <= 0 )
return ( ( T_1 ) 0 ) ;
#ifndef F_2
while ( V_8 & ~ 3 ) {
V_33 = V_7 [ 0 ] ;
V_34 = V_31 [ 0 ] ;
V_6 [ 0 ] = ( V_33 - V_34 - V_9 ) & V_27 ;
if ( V_33 != V_34 )
V_9 = ( V_33 < V_34 ) ;
V_33 = V_7 [ 1 ] ;
V_34 = V_31 [ 1 ] ;
V_6 [ 1 ] = ( V_33 - V_34 - V_9 ) & V_27 ;
if ( V_33 != V_34 )
V_9 = ( V_33 < V_34 ) ;
V_33 = V_7 [ 2 ] ;
V_34 = V_31 [ 2 ] ;
V_6 [ 2 ] = ( V_33 - V_34 - V_9 ) & V_27 ;
if ( V_33 != V_34 )
V_9 = ( V_33 < V_34 ) ;
V_33 = V_7 [ 3 ] ;
V_34 = V_31 [ 3 ] ;
V_6 [ 3 ] = ( V_33 - V_34 - V_9 ) & V_27 ;
if ( V_33 != V_34 )
V_9 = ( V_33 < V_34 ) ;
V_7 += 4 ;
V_31 += 4 ;
V_6 += 4 ;
V_8 -= 4 ;
}
#endif
while ( V_8 ) {
V_33 = V_7 [ 0 ] ;
V_34 = V_31 [ 0 ] ;
V_6 [ 0 ] = ( V_33 - V_34 - V_9 ) & V_27 ;
if ( V_33 != V_34 )
V_9 = ( V_33 < V_34 ) ;
V_7 ++ ;
V_31 ++ ;
V_6 ++ ;
V_8 -- ;
}
return ( V_9 ) ;
}
void F_15 ( T_1 * V_6 , T_1 * V_7 , T_1 * V_31 )
{
T_1 V_5 , V_35 , V_36 ;
V_5 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
F_16 ( V_7 [ 0 ] , V_31 [ 0 ] , V_5 , V_35 , V_36 ) ;
V_6 [ 0 ] = V_5 ;
V_5 = 0 ;
F_16 ( V_7 [ 0 ] , V_31 [ 1 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 0 ] , V_35 , V_36 , V_5 ) ;
V_6 [ 1 ] = V_35 ;
V_35 = 0 ;
F_16 ( V_7 [ 2 ] , V_31 [ 0 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 1 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 0 ] , V_31 [ 2 ] , V_36 , V_5 , V_35 ) ;
V_6 [ 2 ] = V_36 ;
V_36 = 0 ;
F_16 ( V_7 [ 0 ] , V_31 [ 3 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 2 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 2 ] , V_31 [ 1 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 0 ] , V_5 , V_35 , V_36 ) ;
V_6 [ 3 ] = V_5 ;
V_5 = 0 ;
F_16 ( V_7 [ 4 ] , V_31 [ 0 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 1 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 2 ] , V_31 [ 2 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 3 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 0 ] , V_31 [ 4 ] , V_35 , V_36 , V_5 ) ;
V_6 [ 4 ] = V_35 ;
V_35 = 0 ;
F_16 ( V_7 [ 0 ] , V_31 [ 5 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 4 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 2 ] , V_31 [ 3 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 2 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 4 ] , V_31 [ 1 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 5 ] , V_31 [ 0 ] , V_36 , V_5 , V_35 ) ;
V_6 [ 5 ] = V_36 ;
V_36 = 0 ;
F_16 ( V_7 [ 6 ] , V_31 [ 0 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 5 ] , V_31 [ 1 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 4 ] , V_31 [ 2 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 3 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 2 ] , V_31 [ 4 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 5 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 0 ] , V_31 [ 6 ] , V_5 , V_35 , V_36 ) ;
V_6 [ 6 ] = V_5 ;
V_5 = 0 ;
F_16 ( V_7 [ 0 ] , V_31 [ 7 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 6 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 2 ] , V_31 [ 5 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 4 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 4 ] , V_31 [ 3 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 5 ] , V_31 [ 2 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 6 ] , V_31 [ 1 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 7 ] , V_31 [ 0 ] , V_35 , V_36 , V_5 ) ;
V_6 [ 7 ] = V_35 ;
V_35 = 0 ;
F_16 ( V_7 [ 7 ] , V_31 [ 1 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 6 ] , V_31 [ 2 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 5 ] , V_31 [ 3 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 4 ] , V_31 [ 4 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 5 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 2 ] , V_31 [ 6 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 7 ] , V_36 , V_5 , V_35 ) ;
V_6 [ 8 ] = V_36 ;
V_36 = 0 ;
F_16 ( V_7 [ 2 ] , V_31 [ 7 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 6 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 4 ] , V_31 [ 5 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 5 ] , V_31 [ 4 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 6 ] , V_31 [ 3 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 7 ] , V_31 [ 2 ] , V_5 , V_35 , V_36 ) ;
V_6 [ 9 ] = V_5 ;
V_5 = 0 ;
F_16 ( V_7 [ 7 ] , V_31 [ 3 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 6 ] , V_31 [ 4 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 5 ] , V_31 [ 5 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 4 ] , V_31 [ 6 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 7 ] , V_35 , V_36 , V_5 ) ;
V_6 [ 10 ] = V_35 ;
V_35 = 0 ;
F_16 ( V_7 [ 4 ] , V_31 [ 7 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 5 ] , V_31 [ 6 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 6 ] , V_31 [ 5 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 7 ] , V_31 [ 4 ] , V_36 , V_5 , V_35 ) ;
V_6 [ 11 ] = V_36 ;
V_36 = 0 ;
F_16 ( V_7 [ 7 ] , V_31 [ 5 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 6 ] , V_31 [ 6 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 5 ] , V_31 [ 7 ] , V_5 , V_35 , V_36 ) ;
V_6 [ 12 ] = V_5 ;
V_5 = 0 ;
F_16 ( V_7 [ 6 ] , V_31 [ 7 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 7 ] , V_31 [ 6 ] , V_35 , V_36 , V_5 ) ;
V_6 [ 13 ] = V_35 ;
V_35 = 0 ;
F_16 ( V_7 [ 7 ] , V_31 [ 7 ] , V_36 , V_5 , V_35 ) ;
V_6 [ 14 ] = V_36 ;
V_6 [ 15 ] = V_5 ;
}
void F_17 ( T_1 * V_6 , T_1 * V_7 , T_1 * V_31 )
{
T_1 V_5 , V_35 , V_36 ;
V_5 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
F_16 ( V_7 [ 0 ] , V_31 [ 0 ] , V_5 , V_35 , V_36 ) ;
V_6 [ 0 ] = V_5 ;
V_5 = 0 ;
F_16 ( V_7 [ 0 ] , V_31 [ 1 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 0 ] , V_35 , V_36 , V_5 ) ;
V_6 [ 1 ] = V_35 ;
V_35 = 0 ;
F_16 ( V_7 [ 2 ] , V_31 [ 0 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 1 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 0 ] , V_31 [ 2 ] , V_36 , V_5 , V_35 ) ;
V_6 [ 2 ] = V_36 ;
V_36 = 0 ;
F_16 ( V_7 [ 0 ] , V_31 [ 3 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 2 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 2 ] , V_31 [ 1 ] , V_5 , V_35 , V_36 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 0 ] , V_5 , V_35 , V_36 ) ;
V_6 [ 3 ] = V_5 ;
V_5 = 0 ;
F_16 ( V_7 [ 3 ] , V_31 [ 1 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 2 ] , V_31 [ 2 ] , V_35 , V_36 , V_5 ) ;
F_16 ( V_7 [ 1 ] , V_31 [ 3 ] , V_35 , V_36 , V_5 ) ;
V_6 [ 4 ] = V_35 ;
V_35 = 0 ;
F_16 ( V_7 [ 2 ] , V_31 [ 3 ] , V_36 , V_5 , V_35 ) ;
F_16 ( V_7 [ 3 ] , V_31 [ 2 ] , V_36 , V_5 , V_35 ) ;
V_6 [ 5 ] = V_36 ;
V_36 = 0 ;
F_16 ( V_7 [ 3 ] , V_31 [ 3 ] , V_5 , V_35 , V_36 ) ;
V_6 [ 6 ] = V_5 ;
V_6 [ 7 ] = V_35 ;
}
void F_18 ( T_1 * V_6 , const T_1 * V_7 )
{
T_1 V_5 , V_35 , V_36 ;
V_5 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
F_19 ( V_7 , 0 , V_5 , V_35 , V_36 ) ;
V_6 [ 0 ] = V_5 ;
V_5 = 0 ;
F_20 ( V_7 , 1 , 0 , V_35 , V_36 , V_5 ) ;
V_6 [ 1 ] = V_35 ;
V_35 = 0 ;
F_19 ( V_7 , 1 , V_36 , V_5 , V_35 ) ;
F_20 ( V_7 , 2 , 0 , V_36 , V_5 , V_35 ) ;
V_6 [ 2 ] = V_36 ;
V_36 = 0 ;
F_20 ( V_7 , 3 , 0 , V_5 , V_35 , V_36 ) ;
F_20 ( V_7 , 2 , 1 , V_5 , V_35 , V_36 ) ;
V_6 [ 3 ] = V_5 ;
V_5 = 0 ;
F_19 ( V_7 , 2 , V_35 , V_36 , V_5 ) ;
F_20 ( V_7 , 3 , 1 , V_35 , V_36 , V_5 ) ;
F_20 ( V_7 , 4 , 0 , V_35 , V_36 , V_5 ) ;
V_6 [ 4 ] = V_35 ;
V_35 = 0 ;
F_20 ( V_7 , 5 , 0 , V_36 , V_5 , V_35 ) ;
F_20 ( V_7 , 4 , 1 , V_36 , V_5 , V_35 ) ;
F_20 ( V_7 , 3 , 2 , V_36 , V_5 , V_35 ) ;
V_6 [ 5 ] = V_36 ;
V_36 = 0 ;
F_19 ( V_7 , 3 , V_5 , V_35 , V_36 ) ;
F_20 ( V_7 , 4 , 2 , V_5 , V_35 , V_36 ) ;
F_20 ( V_7 , 5 , 1 , V_5 , V_35 , V_36 ) ;
F_20 ( V_7 , 6 , 0 , V_5 , V_35 , V_36 ) ;
V_6 [ 6 ] = V_5 ;
V_5 = 0 ;
F_20 ( V_7 , 7 , 0 , V_35 , V_36 , V_5 ) ;
F_20 ( V_7 , 6 , 1 , V_35 , V_36 , V_5 ) ;
F_20 ( V_7 , 5 , 2 , V_35 , V_36 , V_5 ) ;
F_20 ( V_7 , 4 , 3 , V_35 , V_36 , V_5 ) ;
V_6 [ 7 ] = V_35 ;
V_35 = 0 ;
F_19 ( V_7 , 4 , V_36 , V_5 , V_35 ) ;
F_20 ( V_7 , 5 , 3 , V_36 , V_5 , V_35 ) ;
F_20 ( V_7 , 6 , 2 , V_36 , V_5 , V_35 ) ;
F_20 ( V_7 , 7 , 1 , V_36 , V_5 , V_35 ) ;
V_6 [ 8 ] = V_36 ;
V_36 = 0 ;
F_20 ( V_7 , 7 , 2 , V_5 , V_35 , V_36 ) ;
F_20 ( V_7 , 6 , 3 , V_5 , V_35 , V_36 ) ;
F_20 ( V_7 , 5 , 4 , V_5 , V_35 , V_36 ) ;
V_6 [ 9 ] = V_5 ;
V_5 = 0 ;
F_19 ( V_7 , 5 , V_35 , V_36 , V_5 ) ;
F_20 ( V_7 , 6 , 4 , V_35 , V_36 , V_5 ) ;
F_20 ( V_7 , 7 , 3 , V_35 , V_36 , V_5 ) ;
V_6 [ 10 ] = V_35 ;
V_35 = 0 ;
F_20 ( V_7 , 7 , 4 , V_36 , V_5 , V_35 ) ;
F_20 ( V_7 , 6 , 5 , V_36 , V_5 , V_35 ) ;
V_6 [ 11 ] = V_36 ;
V_36 = 0 ;
F_19 ( V_7 , 6 , V_5 , V_35 , V_36 ) ;
F_20 ( V_7 , 7 , 5 , V_5 , V_35 , V_36 ) ;
V_6 [ 12 ] = V_5 ;
V_5 = 0 ;
F_20 ( V_7 , 7 , 6 , V_35 , V_36 , V_5 ) ;
V_6 [ 13 ] = V_35 ;
V_35 = 0 ;
F_19 ( V_7 , 7 , V_36 , V_5 , V_35 ) ;
V_6 [ 14 ] = V_36 ;
V_6 [ 15 ] = V_5 ;
}
void F_21 ( T_1 * V_6 , const T_1 * V_7 )
{
T_1 V_5 , V_35 , V_36 ;
V_5 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
F_19 ( V_7 , 0 , V_5 , V_35 , V_36 ) ;
V_6 [ 0 ] = V_5 ;
V_5 = 0 ;
F_20 ( V_7 , 1 , 0 , V_35 , V_36 , V_5 ) ;
V_6 [ 1 ] = V_35 ;
V_35 = 0 ;
F_19 ( V_7 , 1 , V_36 , V_5 , V_35 ) ;
F_20 ( V_7 , 2 , 0 , V_36 , V_5 , V_35 ) ;
V_6 [ 2 ] = V_36 ;
V_36 = 0 ;
F_20 ( V_7 , 3 , 0 , V_5 , V_35 , V_36 ) ;
F_20 ( V_7 , 2 , 1 , V_5 , V_35 , V_36 ) ;
V_6 [ 3 ] = V_5 ;
V_5 = 0 ;
F_19 ( V_7 , 2 , V_35 , V_36 , V_5 ) ;
F_20 ( V_7 , 3 , 1 , V_35 , V_36 , V_5 ) ;
V_6 [ 4 ] = V_35 ;
V_35 = 0 ;
F_20 ( V_7 , 3 , 2 , V_36 , V_5 , V_35 ) ;
V_6 [ 5 ] = V_36 ;
V_36 = 0 ;
F_19 ( V_7 , 3 , V_5 , V_35 , V_36 ) ;
V_6 [ 6 ] = V_5 ;
V_6 [ 7 ] = V_35 ;
}
int F_22 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_37 ,
const T_1 * V_38 , const T_1 * V_39 , int V_3 )
{
T_1 V_40 , V_5 , V_41 , * V_42 , V_43 ;
# ifdef F_23
T_1 V_44 ;
# endif
volatile T_1 * V_45 ;
int V_25 = 0 , V_46 ;
# if 0
if (ap == bp)
return bn_sqr_mont(rp, ap, np, n0p, num);
# endif
V_45 = V_42 = F_24 ( ( V_3 + 2 ) * sizeof( T_1 ) ) ;
V_43 = * V_39 ;
V_40 = 0 ;
V_41 = V_37 [ 0 ] ;
# ifdef F_23
V_44 = F_9 ( V_41 ) ;
V_41 = F_8 ( V_41 ) ;
for ( V_46 = 0 ; V_46 < V_3 ; ++ V_46 )
F_5 ( V_42 [ V_46 ] , V_2 [ V_46 ] , V_41 , V_44 , V_40 ) ;
# else
for ( V_46 = 0 ; V_46 < V_3 ; ++ V_46 )
F_5 ( V_42 [ V_46 ] , V_2 [ V_46 ] , V_41 , V_40 ) ;
# endif
V_42 [ V_3 ] = V_40 ;
V_42 [ V_3 + 1 ] = 0 ;
goto V_47;
for ( V_25 = 0 ; V_25 < V_3 ; V_25 ++ ) {
V_40 = 0 ;
V_41 = V_37 [ V_25 ] ;
# ifdef F_23
V_44 = F_9 ( V_41 ) ;
V_41 = F_8 ( V_41 ) ;
for ( V_46 = 0 ; V_46 < V_3 ; ++ V_46 )
F_3 ( V_42 [ V_46 ] , V_2 [ V_46 ] , V_41 , V_44 , V_40 ) ;
# else
for ( V_46 = 0 ; V_46 < V_3 ; ++ V_46 )
F_3 ( V_42 [ V_46 ] , V_2 [ V_46 ] , V_41 , V_40 ) ;
# endif
V_5 = ( V_42 [ V_3 ] + V_40 ) & V_27 ;
V_42 [ V_3 ] = V_5 ;
V_42 [ V_3 + 1 ] = ( V_5 < V_40 ? 1 : 0 ) ;
V_47:
V_5 = V_42 [ 0 ] ;
V_41 = ( V_5 * V_43 ) & V_27 ;
V_40 = 0 ;
# ifdef F_23
V_44 = F_9 ( V_41 ) ;
V_41 = F_8 ( V_41 ) ;
F_3 ( V_5 , V_38 [ 0 ] , V_41 , V_44 , V_40 ) ;
# else
F_3 ( V_5 , V_41 , V_38 [ 0 ] , V_40 ) ;
# endif
for ( V_46 = 1 ; V_46 < V_3 ; V_46 ++ ) {
V_5 = V_42 [ V_46 ] ;
# ifdef F_23
F_3 ( V_5 , V_38 [ V_46 ] , V_41 , V_44 , V_40 ) ;
# else
F_3 ( V_5 , V_41 , V_38 [ V_46 ] , V_40 ) ;
# endif
V_42 [ V_46 - 1 ] = V_5 & V_27 ;
}
V_5 = ( V_42 [ V_3 ] + V_40 ) & V_27 ;
V_42 [ V_3 - 1 ] = V_5 ;
V_42 [ V_3 ] = V_42 [ V_3 + 1 ] + ( V_5 < V_40 ? 1 : 0 ) ;
}
if ( V_42 [ V_3 ] != 0 || V_42 [ V_3 - 1 ] >= V_38 [ V_3 - 1 ] ) {
V_40 = F_14 ( V_1 , V_42 , V_38 , V_3 ) ;
if ( V_42 [ V_3 ] != 0 || V_40 == 0 ) {
for ( V_25 = 0 ; V_25 < V_3 + 2 ; V_25 ++ )
V_45 [ V_25 ] = 0 ;
return 1 ;
}
}
for ( V_25 = 0 ; V_25 < V_3 ; V_25 ++ )
V_1 [ V_25 ] = V_42 [ V_25 ] , V_45 [ V_25 ] = 0 ;
V_45 [ V_3 ] = 0 ;
V_45 [ V_3 + 1 ] = 0 ;
return 1 ;
}
int F_22 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_37 ,
const T_1 * V_38 , const T_1 * V_43 , int V_3 )
{
return 0 ;
}
void F_21 ( T_1 * V_6 , const T_1 * V_7 )
{
T_1 V_24 [ 8 ] ;
F_25 ( V_6 , V_7 , 4 , V_24 ) ;
}
void F_18 ( T_1 * V_6 , const T_1 * V_7 )
{
T_1 V_24 [ 16 ] ;
F_25 ( V_6 , V_7 , 8 , V_24 ) ;
}
void F_17 ( T_1 * V_6 , T_1 * V_7 , T_1 * V_31 )
{
V_6 [ 4 ] = F_4 ( & ( V_6 [ 0 ] ) , V_7 , 4 , V_31 [ 0 ] ) ;
V_6 [ 5 ] = F_1 ( & ( V_6 [ 1 ] ) , V_7 , 4 , V_31 [ 1 ] ) ;
V_6 [ 6 ] = F_1 ( & ( V_6 [ 2 ] ) , V_7 , 4 , V_31 [ 2 ] ) ;
V_6 [ 7 ] = F_1 ( & ( V_6 [ 3 ] ) , V_7 , 4 , V_31 [ 3 ] ) ;
}
void F_15 ( T_1 * V_6 , T_1 * V_7 , T_1 * V_31 )
{
V_6 [ 8 ] = F_4 ( & ( V_6 [ 0 ] ) , V_7 , 8 , V_31 [ 0 ] ) ;
V_6 [ 9 ] = F_1 ( & ( V_6 [ 1 ] ) , V_7 , 8 , V_31 [ 1 ] ) ;
V_6 [ 10 ] = F_1 ( & ( V_6 [ 2 ] ) , V_7 , 8 , V_31 [ 2 ] ) ;
V_6 [ 11 ] = F_1 ( & ( V_6 [ 3 ] ) , V_7 , 8 , V_31 [ 3 ] ) ;
V_6 [ 12 ] = F_1 ( & ( V_6 [ 4 ] ) , V_7 , 8 , V_31 [ 4 ] ) ;
V_6 [ 13 ] = F_1 ( & ( V_6 [ 5 ] ) , V_7 , 8 , V_31 [ 5 ] ) ;
V_6 [ 14 ] = F_1 ( & ( V_6 [ 6 ] ) , V_7 , 8 , V_31 [ 6 ] ) ;
V_6 [ 15 ] = F_1 ( & ( V_6 [ 7 ] ) , V_7 , 8 , V_31 [ 7 ] ) ;
}
int F_22 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_37 ,
const T_1 * V_38 , const T_1 * V_39 , int V_3 )
{
T_1 V_40 , V_5 , * V_42 , V_43 = * V_39 ;
volatile T_1 * V_45 ;
int V_25 = 0 , V_46 ;
V_45 = V_42 = F_24 ( ( V_3 + 2 ) * sizeof( T_1 ) ) ;
for ( V_25 = 0 ; V_25 <= V_3 ; V_25 ++ )
V_42 [ V_25 ] = 0 ;
for ( V_25 = 0 ; V_25 < V_3 ; V_25 ++ ) {
V_40 = F_1 ( V_42 , V_2 , V_3 , V_37 [ V_25 ] ) ;
V_5 = ( V_42 [ V_3 ] + V_40 ) & V_27 ;
V_42 [ V_3 ] = V_5 ;
V_42 [ V_3 + 1 ] = ( V_5 < V_40 ? 1 : 0 ) ;
V_40 = F_1 ( V_42 , V_38 , V_3 , V_42 [ 0 ] * V_43 ) ;
V_5 = ( V_42 [ V_3 ] + V_40 ) & V_27 ;
V_42 [ V_3 ] = V_5 ;
V_42 [ V_3 + 1 ] += ( V_5 < V_40 ? 1 : 0 ) ;
for ( V_46 = 0 ; V_46 <= V_3 ; V_46 ++ )
V_42 [ V_46 ] = V_42 [ V_46 + 1 ] ;
}
if ( V_42 [ V_3 ] != 0 || V_42 [ V_3 - 1 ] >= V_38 [ V_3 - 1 ] ) {
V_40 = F_14 ( V_1 , V_42 , V_38 , V_3 ) ;
if ( V_42 [ V_3 ] != 0 || V_40 == 0 ) {
for ( V_25 = 0 ; V_25 < V_3 + 2 ; V_25 ++ )
V_45 [ V_25 ] = 0 ;
return 1 ;
}
}
for ( V_25 = 0 ; V_25 < V_3 ; V_25 ++ )
V_1 [ V_25 ] = V_42 [ V_25 ] , V_45 [ V_25 ] = 0 ;
V_45 [ V_3 ] = 0 ;
V_45 [ V_3 + 1 ] = 0 ;
return 1 ;
}
int F_22 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_37 ,
const T_1 * V_38 , const T_1 * V_43 , int V_3 )
{
return 0 ;
}
