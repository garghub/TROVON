static inline T_1 F_1 ( const T_2 V_1 )
{
return ( ( ( V_1 >> 3 ) & 0x001f ) |
( ( V_1 >> 5 ) & 0x07e0 ) |
( ( V_1 >> 8 ) & 0xf800 ) ) ;
}
static inline T_1 F_2 ( const T_3 * V_1 , int V_2 )
{
T_1 V_3 = 0 ;
if ( V_2 == 2 )
V_3 = * ( const V_4 * ) V_1 ;
else if ( V_2 == 4 )
V_3 = F_1 ( * ( const T_2 * ) V_1 ) ;
return V_3 ;
}
static void F_3 (
const T_4 * * V_5 ,
const T_4 * const V_6 ,
T_2 * V_7 ,
T_3 * * V_8 ,
const T_3 * const V_9 , int V_2 )
{
const T_4 * V_1 = * V_5 ;
T_2 V_10 = * V_7 ;
T_3 * V_11 = * V_8 ;
while ( ( V_6 > V_1 ) &&
( V_9 - V_12 > V_11 ) ) {
T_3 * V_13 = NULL ;
T_3 * V_14 = NULL ;
const T_4 * V_15 = NULL ;
const T_4 * V_16 , * V_17 = NULL ;
V_4 V_3 ;
F_4 ( ( void * ) V_11 ) ;
* V_11 ++ = 0xaf ;
* V_11 ++ = 0x6b ;
* V_11 ++ = ( T_3 ) ( ( V_10 >> 16 ) & 0xFF ) ;
* V_11 ++ = ( T_3 ) ( ( V_10 >> 8 ) & 0xFF ) ;
* V_11 ++ = ( T_3 ) ( ( V_10 ) & 0xFF ) ;
V_14 = V_11 ++ ;
V_16 = V_1 ;
V_13 = V_11 ++ ;
V_15 = V_1 ;
V_17 = V_1 + ( F_5 ( V_18 + 1 ,
F_5 ( ( int ) ( V_6 - V_1 ) / V_2 ,
( int ) ( V_9 - V_11 ) / 2 ) ) ) * V_2 ;
F_6 ( ( void * ) V_1 , ( V_17 - V_1 ) * V_2 ) ;
V_3 = F_2 ( V_1 , V_2 ) ;
while ( V_1 < V_17 ) {
const T_4 * const V_19 = V_1 ;
const V_4 V_20 = V_3 ;
F_7 ( V_3 , V_11 ) ;
V_11 += 2 ;
V_1 += V_2 ;
while ( V_1 < V_17 ) {
V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 != V_20 )
break;
V_1 += V_2 ;
}
if ( F_8 ( V_1 > V_19 + V_2 ) ) {
* V_13 = ( ( ( V_19 -
V_15 ) / V_2 ) + 1 ) & 0xFF ;
* V_11 ++ = ( ( ( V_1 - V_19 ) / V_2 ) - 1 ) & 0xFF ;
V_15 = V_1 ;
V_13 = V_11 ++ ;
}
}
if ( V_1 > V_15 ) {
* V_13 = ( ( V_1 - V_15 ) / V_2 ) & 0xFF ;
}
* V_14 = ( ( V_1 - V_16 ) / V_2 ) & 0xFF ;
V_10 += ( ( V_1 - V_16 ) / V_2 ) * 2 ;
}
if ( V_9 <= V_12 + V_11 ) {
if ( V_9 > V_11 )
memset ( V_11 , 0xAF , V_9 - V_11 ) ;
V_11 = ( T_3 * ) V_9 ;
}
* V_8 = V_11 ;
* V_5 = V_1 ;
* V_7 = V_10 ;
return;
}
int F_9 ( struct V_21 * V_22 , int V_2 , struct V_23 * * V_24 ,
const char * V_25 , char * * V_26 ,
T_5 V_27 , T_5 V_28 ,
T_5 V_29 ,
int * V_30 , int * V_31 )
{
const T_4 * V_32 , * V_33 , * V_34 ;
T_5 V_35 = 0 + ( V_28 / V_2 ) * 2 ;
struct V_23 * V_23 = * V_24 ;
T_4 * V_11 = * V_26 ;
T_4 * V_36 = ( T_4 * ) V_23 -> V_37 + V_23 -> V_38 ;
F_10 ( ! ( V_2 == 2 || V_2 == 4 ) ) ;
V_32 = ( T_4 * ) ( V_25 + V_27 ) ;
V_34 = V_32 ;
V_33 = V_34 + V_29 ;
while ( V_34 < V_33 ) {
F_3 ( & V_34 ,
V_33 , & V_35 ,
( T_4 * * ) & V_11 , ( T_4 * ) V_36 , V_2 ) ;
if ( V_11 >= V_36 ) {
int V_39 = V_11 - ( T_4 * ) V_23 -> V_37 ;
if ( F_11 ( V_22 , V_23 , V_39 ) )
return 1 ;
* V_31 += V_39 ;
V_23 = F_12 ( V_22 ) ;
if ( ! V_23 )
return 1 ;
* V_24 = V_23 ;
V_11 = V_23 -> V_37 ;
V_36 = & V_11 [ V_23 -> V_38 ] ;
}
}
* V_26 = V_11 ;
return 0 ;
}
