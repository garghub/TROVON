int
F_1 ( const T_1 * V_1 , int V_2 )
{
register const T_2 * V_3 ;
register int V_4 = 0 ;
register int V_5 = 0 ;
int V_6 = 0 ;
union {
T_3 V_7 [ 2 ] ;
T_2 V_8 ;
} V_9 ;
union {
T_2 V_8 [ 2 ] ;
T_4 V_10 ;
} V_11 ;
for (; V_2 != 0 ; V_1 ++ , V_2 -- ) {
if ( V_1 -> V_12 == 0 )
continue;
V_3 = ( const T_2 * ) ( const void * ) V_1 -> V_13 ;
if ( V_5 == - 1 ) {
V_9 . V_7 [ 1 ] = * ( const T_3 * ) V_3 ;
V_4 += V_9 . V_8 ;
V_3 = ( const T_2 * ) ( const void * ) ( ( const T_3 * ) V_3 + 1 ) ;
V_5 = V_1 -> V_12 - 1 ;
} else
V_5 = V_1 -> V_12 ;
if ( ( 1 & ( V_14 ) V_3 ) && ( V_5 > 0 ) ) {
V_15 ;
V_4 <<= 8 ;
V_9 . V_7 [ 0 ] = * ( const T_3 * ) V_3 ;
V_3 = ( const T_2 * ) ( const void * ) ( ( const T_3 * ) V_3 + 1 ) ;
V_5 -- ;
V_6 = 1 ;
}
while ( ( V_5 -= 32 ) >= 0 ) {
V_4 += V_3 [ 0 ] ; V_4 += V_3 [ 1 ] ; V_4 += V_3 [ 2 ] ; V_4 += V_3 [ 3 ] ;
V_4 += V_3 [ 4 ] ; V_4 += V_3 [ 5 ] ; V_4 += V_3 [ 6 ] ; V_4 += V_3 [ 7 ] ;
V_4 += V_3 [ 8 ] ; V_4 += V_3 [ 9 ] ; V_4 += V_3 [ 10 ] ; V_4 += V_3 [ 11 ] ;
V_4 += V_3 [ 12 ] ; V_4 += V_3 [ 13 ] ; V_4 += V_3 [ 14 ] ; V_4 += V_3 [ 15 ] ;
V_3 += 16 ;
}
V_5 += 32 ;
while ( ( V_5 -= 8 ) >= 0 ) {
V_4 += V_3 [ 0 ] ; V_4 += V_3 [ 1 ] ; V_4 += V_3 [ 2 ] ; V_4 += V_3 [ 3 ] ;
V_3 += 4 ;
}
V_5 += 8 ;
if ( V_5 == 0 && V_6 == 0 )
continue;
V_15 ;
while ( ( V_5 -= 2 ) >= 0 ) {
V_4 += * V_3 ++ ;
}
if ( V_6 ) {
V_15 ;
V_4 <<= 8 ;
V_6 = 0 ;
if ( V_5 == - 1 ) {
V_9 . V_7 [ 1 ] = * ( const T_3 * ) V_3 ;
V_4 += V_9 . V_8 ;
V_5 = 0 ;
} else
V_5 = - 1 ;
} else if ( V_5 == - 1 )
V_9 . V_7 [ 0 ] = * ( const T_3 * ) V_3 ;
}
if ( V_5 == - 1 ) {
V_9 . V_7 [ 1 ] = 0 ;
V_4 += V_9 . V_8 ;
}
V_15 ;
return ( ~ V_4 & 0xffff ) ;
}
T_2
F_2 ( const T_3 * V_13 , int V_12 )
{
T_1 V_16 [ 1 ] ;
F_3 ( V_16 [ 0 ] , V_13 , V_12 ) ;
return F_1 ( & V_16 [ 0 ] , 1 ) ;
}
T_2
F_4 ( T_5 * V_17 , int V_18 , int V_12 )
{
T_1 V_16 [ 1 ] ;
F_5 ( V_16 [ 0 ] , V_17 , V_18 , V_12 ) ;
return F_1 ( & V_16 [ 0 ] , 1 ) ;
}
T_2
F_6 ( T_2 V_4 , T_2 V_19 )
{
T_4 V_20 ;
V_20 = V_4 ;
V_20 += F_7 ( V_19 ) ;
V_20 = ( V_20 & 0xFFFF ) + ( V_20 >> 16 ) ;
V_20 = ( V_20 & 0xFFFF ) + ( V_20 >> 16 ) ;
return V_20 ;
}
