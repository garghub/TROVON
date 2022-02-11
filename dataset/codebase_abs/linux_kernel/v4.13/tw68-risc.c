static T_1 * F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_4 , T_2 V_5 ,
unsigned int V_6 , unsigned int V_7 ,
unsigned int V_8 , bool V_9 )
{
struct V_2 * V_10 ;
unsigned int line , V_11 , V_12 ;
if ( V_9 ) {
* ( V_1 ++ ) = F_2 ( V_13 ) ;
* ( V_1 ++ ) = 0 ;
}
if ( V_5 == 1 )
* ( V_1 ++ ) = F_2 ( V_14 ) ;
else
* ( V_1 ++ ) = F_2 ( V_15 ) ;
* ( V_1 ++ ) = 0 ;
V_10 = V_3 ;
for ( line = 0 ; line < V_8 ; line ++ ) {
while ( V_4 && V_4 >= F_3 ( V_10 ) ) {
V_4 -= F_3 ( V_10 ) ;
V_10 = F_4 ( V_10 ) ;
}
if ( V_6 <= F_3 ( V_10 ) - V_4 ) {
* ( V_1 ++ ) = F_2 ( V_16 |
V_6 ) ;
* ( V_1 ++ ) = F_2 ( F_5 ( V_10 ) + V_4 ) ;
V_4 += V_6 ;
} else {
V_11 = V_6 ;
V_12 = ( F_3 ( V_10 ) - V_4 ) ;
* ( V_1 ++ ) = F_2 ( V_16 |
( 7 << 24 ) |
V_12 ) ;
* ( V_1 ++ ) = F_2 ( F_5 ( V_10 ) + V_4 ) ;
V_11 -= V_12 ;
V_10 = F_4 ( V_10 ) ;
while ( V_11 > F_3 ( V_10 ) ) {
* ( V_1 ++ ) = F_2 ( V_17 |
( V_12 << 12 ) |
F_3 ( V_10 ) ) ;
* ( V_1 ++ ) = F_2 ( F_5 ( V_10 ) ) ;
V_11 -= F_3 ( V_10 ) ;
V_10 = F_4 ( V_10 ) ;
V_12 += F_3 ( V_10 ) ;
}
if ( V_11 ) {
* ( V_1 ++ ) = F_2 ( V_17 |
( V_12 << 12 ) |
V_11 ) ;
* ( V_1 ++ ) = F_2 ( F_5 ( V_10 ) ) ;
}
V_4 = V_11 ;
}
V_4 += V_7 ;
}
return V_1 ;
}
int F_6 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_2 * V_3 ,
unsigned int V_22 ,
unsigned int V_23 ,
unsigned int V_6 ,
unsigned int V_7 ,
unsigned int V_8 )
{
T_2 V_24 , V_25 ;
T_1 * V_1 ;
V_25 = 0 ;
if ( V_26 != V_22 )
V_25 ++ ;
if ( V_26 != V_23 )
V_25 ++ ;
V_24 = V_25 * ( 1 + ( ( ( V_6 + V_7 ) * V_8 ) /
V_27 ) + V_8 ) + 4 ;
V_21 -> V_28 = V_24 * 8 ;
V_21 -> V_29 = F_7 ( V_19 , V_21 -> V_28 , & V_21 -> V_30 ) ;
if ( V_21 -> V_29 == NULL )
return - V_31 ;
V_1 = V_21 -> V_29 ;
if ( V_26 != V_22 )
V_1 = F_1 ( V_1 , V_3 , V_22 , 1 ,
V_6 , V_7 , V_8 , true ) ;
if ( V_26 != V_23 )
V_1 = F_1 ( V_1 , V_3 , V_23 , 2 ,
V_6 , V_7 , V_8 , V_22 == V_26 ) ;
V_21 -> V_32 = V_1 ;
V_21 -> V_29 [ 1 ] = F_2 ( V_21 -> V_30 + 8 ) ;
F_8 ( ( V_21 -> V_32 - V_21 -> V_29 + 2 ) * sizeof( V_21 -> V_29 [ 0 ] ) > V_21 -> V_28 ) ;
return 0 ;
}
