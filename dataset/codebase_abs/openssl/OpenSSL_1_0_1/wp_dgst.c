int F_1 ( T_1 * V_1 , const void * V_2 , T_2 V_3 )
{
T_2 V_4 = ( ( T_2 ) 1 ) << ( sizeof( T_2 ) * 8 - 4 ) ;
const unsigned char * V_5 = V_2 ;
while ( V_3 >= V_4 )
{
F_2 ( V_1 , V_5 , V_4 * 8 ) ;
V_3 -= V_4 ;
V_5 += V_4 ;
}
if ( V_3 )
F_2 ( V_1 , V_5 , V_3 * 8 ) ;
return ( 1 ) ;
}
void F_2 ( T_1 * V_1 , const void * V_2 , T_2 V_6 )
{
T_2 V_7 ;
unsigned int V_8 = V_1 -> V_8 ,
V_9 = V_8 % 8 ,
V_10 = ( 8 - ( unsigned int ) V_6 % 8 ) & 7 ;
const unsigned char * V_5 = V_2 ;
V_1 -> V_11 [ 0 ] += V_6 ;
if ( V_1 -> V_11 [ 0 ] < V_6 )
{
V_7 = 1 ;
do { V_1 -> V_11 [ V_7 ] ++ ;
} while( V_1 -> V_11 [ V_7 ] == 0
&& ++ V_7 < ( V_12 / sizeof( T_2 ) ) );
}
#ifndef F_3
V_13:
if ( V_10 == 0 && V_9 == 0 )
{
while ( V_6 )
{
if ( V_8 == 0 && ( V_7 = V_6 / V_14 ) )
{
F_4 ( V_1 , V_5 , V_7 ) ;
V_5 += V_7 * V_14 / 8 ;
V_6 %= V_14 ;
}
else
{
unsigned int V_15 = V_8 / 8 ;
V_9 = V_14 - V_8 ;
if ( V_6 >= V_9 )
{
V_6 -= V_9 ;
V_9 /= 8 ;
memcpy ( V_1 -> V_16 + V_15 , V_5 , V_9 ) ;
V_5 += V_9 ;
F_4 ( V_1 , V_1 -> V_16 , 1 ) ;
V_8 = 0 ;
}
else
{
memcpy ( V_1 -> V_16 + V_15 , V_5 , V_6 / 8 ) ;
V_8 += ( unsigned int ) V_6 ;
V_6 = 0 ;
}
V_1 -> V_8 = V_8 ;
}
}
}
else
#endif
{
while ( V_6 )
{
unsigned int V_15 = V_8 / 8 ;
unsigned char V_17 ;
#ifndef F_3
if ( V_9 == V_10 )
{
V_1 -> V_16 [ V_15 ++ ] |= V_5 [ 0 ] & ( 0xff >> V_10 ) ;
V_10 = 8 - V_10 ;
V_8 += V_10 ; V_9 = 0 ;
V_6 -= V_10 ; V_10 = 0 ;
V_5 ++ ;
if ( V_8 == V_14 )
{
F_4 ( V_1 , V_1 -> V_16 , 1 ) ;
V_8 = 0 ;
}
V_1 -> V_8 = V_8 ;
goto V_13;
}
else
#endif
if ( V_6 >= 8 )
{
V_17 = ( ( V_5 [ 0 ] << V_10 ) | ( V_5 [ 1 ] >> ( 8 - V_10 ) ) ) ;
V_17 &= 0xff ;
if ( V_9 ) V_1 -> V_16 [ V_15 ++ ] |= V_17 >> V_9 ;
else V_1 -> V_16 [ V_15 ++ ] = V_17 ;
V_8 += 8 ;
V_6 -= 8 ;
V_5 ++ ;
if ( V_8 >= V_14 )
{
F_4 ( V_1 , V_1 -> V_16 , 1 ) ;
V_15 = 0 ;
V_8 %= V_14 ;
}
if ( V_9 ) V_1 -> V_16 [ V_15 ] = V_17 << ( 8 - V_9 ) ;
}
else
{
V_17 = ( V_5 [ 0 ] << V_10 ) & 0xff ;
if ( V_9 ) V_1 -> V_16 [ V_15 ++ ] |= V_17 >> V_9 ;
else V_1 -> V_16 [ V_15 ++ ] = V_17 ;
V_8 += ( unsigned int ) V_6 ;
if ( V_8 == V_14 )
{
F_4 ( V_1 , V_1 -> V_16 , 1 ) ;
V_15 = 0 ;
V_8 %= V_14 ;
}
if ( V_9 ) V_1 -> V_16 [ V_15 ] = V_17 << ( 8 - V_9 ) ;
V_6 = 0 ;
}
V_1 -> V_8 = V_8 ;
}
}
}
int F_5 ( unsigned char * V_18 , T_1 * V_1 )
{
unsigned int V_8 = V_1 -> V_8 ,
V_15 = V_8 / 8 ;
T_2 V_19 , V_20 , V_21 ;
unsigned char * V_22 ;
V_8 %= 8 ;
if ( V_8 ) V_1 -> V_16 [ V_15 ] |= 0x80 >> V_8 ;
else V_1 -> V_16 [ V_15 ] = 0x80 ;
V_15 ++ ;
if ( V_15 > ( V_14 / 8 - V_12 ) )
{
if ( V_15 < V_14 / 8 )
memset ( & V_1 -> V_16 [ V_15 ] , 0 , V_14 / 8 - V_15 ) ;
F_4 ( V_1 , V_1 -> V_16 , 1 ) ;
V_15 = 0 ;
}
if ( V_15 < ( V_14 / 8 - V_12 ) )
memset ( & V_1 -> V_16 [ V_15 ] , 0 ,
( V_14 / 8 - V_12 ) - V_15 ) ;
V_22 = & V_1 -> V_16 [ V_14 / 8 - 1 ] ;
for( V_19 = 0 ; V_19 < V_12 / sizeof( T_2 ) ; V_19 ++ )
for( V_21 = V_1 -> V_11 [ V_19 ] , V_20 = 0 ; V_20 < sizeof( T_2 ) ; V_20 ++ , V_21 >>= 8 )
* V_22 -- = ( unsigned char ) ( V_21 & 0xff ) ;
F_4 ( V_1 , V_1 -> V_16 , 1 ) ;
if ( V_18 ) {
memcpy ( V_18 , V_1 -> V_23 . V_1 , V_24 ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
unsigned char * F_6 ( const void * V_5 , T_2 V_3 , unsigned char * V_18 )
{
T_1 V_25 ;
static unsigned char V_26 [ V_24 ] ;
if ( V_18 == NULL ) V_18 = V_26 ;
F_7 ( & V_25 ) ;
F_1 ( & V_25 , V_5 , V_3 ) ;
F_5 ( V_18 , & V_25 ) ;
return ( V_18 ) ;
}
