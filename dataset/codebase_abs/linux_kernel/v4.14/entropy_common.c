unsigned F_1 ( void ) { return V_1 ; }
unsigned F_2 ( T_1 V_2 ) { return F_3 ( V_2 ) ; }
unsigned F_4 ( T_1 V_2 ) { return F_3 ( V_2 ) ; }
T_1 F_5 ( short * V_3 , unsigned * V_4 , unsigned * V_5 , const void * V_6 , T_1 V_7 )
{
const T_2 * const V_8 = ( const T_2 * ) V_6 ;
const T_2 * const V_9 = V_8 + V_7 ;
const T_2 * V_10 = V_8 ;
int V_11 ;
int V_12 ;
int V_13 ;
T_3 V_14 ;
int V_15 ;
unsigned V_16 = 0 ;
int V_17 = 0 ;
if ( V_7 < 4 )
return ERROR ( V_18 ) ;
V_14 = F_6 ( V_10 ) ;
V_11 = ( V_14 & 0xF ) + V_19 ;
if ( V_11 > V_20 )
return ERROR ( V_21 ) ;
V_14 >>= 4 ;
V_15 = 4 ;
* V_5 = V_11 ;
V_12 = ( 1 << V_11 ) + 1 ;
V_13 = 1 << V_11 ;
V_11 ++ ;
while ( ( V_12 > 1 ) & ( V_16 <= * V_4 ) ) {
if ( V_17 ) {
unsigned V_22 = V_16 ;
while ( ( V_14 & 0xFFFF ) == 0xFFFF ) {
V_22 += 24 ;
if ( V_10 < V_9 - 5 ) {
V_10 += 2 ;
V_14 = F_6 ( V_10 ) >> V_15 ;
} else {
V_14 >>= 16 ;
V_15 += 16 ;
}
}
while ( ( V_14 & 3 ) == 3 ) {
V_22 += 3 ;
V_14 >>= 2 ;
V_15 += 2 ;
}
V_22 += V_14 & 3 ;
V_15 += 2 ;
if ( V_22 > * V_4 )
return ERROR ( V_23 ) ;
while ( V_16 < V_22 )
V_3 [ V_16 ++ ] = 0 ;
if ( ( V_10 <= V_9 - 7 ) || ( V_10 + ( V_15 >> 3 ) <= V_9 - 4 ) ) {
V_10 += V_15 >> 3 ;
V_15 &= 7 ;
V_14 = F_6 ( V_10 ) >> V_15 ;
} else {
V_14 >>= 2 ;
}
}
{
int const V_24 = ( 2 * V_13 - 1 ) - V_12 ;
int V_25 ;
if ( ( V_14 & ( V_13 - 1 ) ) < ( T_3 ) V_24 ) {
V_25 = V_14 & ( V_13 - 1 ) ;
V_15 += V_11 - 1 ;
} else {
V_25 = V_14 & ( 2 * V_13 - 1 ) ;
if ( V_25 >= V_13 )
V_25 -= V_24 ;
V_15 += V_11 ;
}
V_25 -- ;
V_12 -= V_25 < 0 ? - V_25 : V_25 ;
V_3 [ V_16 ++ ] = ( short ) V_25 ;
V_17 = ! V_25 ;
while ( V_12 < V_13 ) {
V_11 -- ;
V_13 >>= 1 ;
}
if ( ( V_10 <= V_9 - 7 ) || ( V_10 + ( V_15 >> 3 ) <= V_9 - 4 ) ) {
V_10 += V_15 >> 3 ;
V_15 &= 7 ;
} else {
V_15 -= ( int ) ( 8 * ( V_9 - 4 - V_10 ) ) ;
V_10 = V_9 - 4 ;
}
V_14 = F_6 ( V_10 ) >> ( V_15 & 31 ) ;
}
}
if ( V_12 != 1 )
return ERROR ( V_26 ) ;
if ( V_15 > 32 )
return ERROR ( V_26 ) ;
* V_4 = V_16 - 1 ;
V_10 += ( V_15 + 7 ) >> 3 ;
return V_10 - V_8 ;
}
T_1 F_7 ( T_2 * V_27 , T_1 V_28 , T_3 * V_29 , T_3 * V_30 , T_3 * V_5 , const void * V_31 , T_1 V_32 , void * V_33 , T_1 V_34 )
{
T_3 V_35 ;
const T_2 * V_10 = ( const T_2 * ) V_31 ;
T_1 V_36 ;
T_1 V_37 ;
if ( ! V_32 )
return ERROR ( V_18 ) ;
V_36 = V_10 [ 0 ] ;
if ( V_36 >= 128 ) {
V_37 = V_36 - 127 ;
V_36 = ( ( V_37 + 1 ) / 2 ) ;
if ( V_36 + 1 > V_32 )
return ERROR ( V_18 ) ;
if ( V_37 >= V_28 )
return ERROR ( V_26 ) ;
V_10 += 1 ;
{
T_3 V_38 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 += 2 ) {
V_27 [ V_38 ] = V_10 [ V_38 / 2 ] >> 4 ;
V_27 [ V_38 + 1 ] = V_10 [ V_38 / 2 ] & 15 ;
}
}
} else {
if ( V_36 + 1 > V_32 )
return ERROR ( V_18 ) ;
V_37 = F_8 ( V_27 , V_28 - 1 , V_10 + 1 , V_36 , 6 , V_33 , V_34 ) ;
if ( F_2 ( V_37 ) )
return V_37 ;
}
memset ( V_29 , 0 , ( V_39 + 1 ) * sizeof( T_3 ) ) ;
V_35 = 0 ;
{
T_3 V_38 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
if ( V_27 [ V_38 ] >= V_39 )
return ERROR ( V_26 ) ;
V_29 [ V_27 [ V_38 ] ] ++ ;
V_35 += ( 1 << V_27 [ V_38 ] ) >> 1 ;
}
}
if ( V_35 == 0 )
return ERROR ( V_26 ) ;
{
T_3 const V_40 = F_9 ( V_35 ) + 1 ;
if ( V_40 > V_39 )
return ERROR ( V_26 ) ;
* V_5 = V_40 ;
{
T_3 const V_41 = 1 << V_40 ;
T_3 const V_42 = V_41 - V_35 ;
T_3 const V_43 = 1 << F_9 ( V_42 ) ;
T_3 const V_44 = F_9 ( V_42 ) + 1 ;
if ( V_43 != V_42 )
return ERROR ( V_26 ) ;
V_27 [ V_37 ] = ( T_2 ) V_44 ;
V_29 [ V_44 ] ++ ;
}
}
if ( ( V_29 [ 1 ] < 2 ) || ( V_29 [ 1 ] & 1 ) )
return ERROR ( V_26 ) ;
* V_30 = ( T_3 ) ( V_37 + 1 ) ;
return V_36 + 1 ;
}
