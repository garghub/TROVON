void F_1 ( const unsigned char * V_1 , unsigned char * V_2 , int V_3 ,
long V_4 , T_1 V_5 , T_2 * V_6 , int V_7 )
{
register T_3 V_8 , V_9 , V_10 , V_11 , V_12 = ( V_3 + 7 ) / 8 ;
register T_3 V_13 , V_14 ;
register unsigned long V_15 = V_4 ;
register int V_16 = V_3 ;
T_3 V_17 [ 2 ] ;
unsigned char * V_18 ;
if ( V_16 > 64 ) return;
if ( V_16 > 32 )
{
V_13 = 0xffffffffL ;
if ( V_16 == 64 )
V_14 = V_13 ;
else V_14 = ( 1L << ( V_16 - 32 ) ) - 1 ;
}
else
{
if ( V_16 == 32 )
V_13 = 0xffffffffL ;
else V_13 = ( 1L << V_16 ) - 1 ;
V_14 = 0x00000000L ;
}
V_18 = & ( * V_6 ) [ 0 ] ;
F_2 ( V_18 , V_10 ) ;
F_2 ( V_18 , V_11 ) ;
if ( V_7 )
{
while ( V_15 >= V_12 )
{
V_15 -= V_12 ;
V_17 [ 0 ] = V_10 ;
V_17 [ 1 ] = V_11 ;
F_3 ( ( T_3 * ) V_17 , V_5 , V_19 ) ;
F_4 ( V_1 , V_8 , V_9 , V_12 ) ;
V_1 += V_12 ;
V_8 = ( V_8 ^ V_17 [ 0 ] ) & V_13 ;
V_9 = ( V_9 ^ V_17 [ 1 ] ) & V_14 ;
F_5 ( V_8 , V_9 , V_2 , V_12 ) ;
V_2 += V_12 ;
if ( V_16 == 32 )
{ V_10 = V_11 ; V_11 = V_8 ; }
else if ( V_16 == 64 )
{ V_10 = V_8 ; V_11 = V_9 ; }
else if ( V_16 > 32 )
{
V_10 = ( ( V_11 >> ( V_16 - 32 ) ) | ( V_8 << ( 64 - V_16 ) ) ) & 0xffffffffL ;
V_11 = ( ( V_8 >> ( V_16 - 32 ) ) | ( V_9 << ( 64 - V_16 ) ) ) & 0xffffffffL ;
}
else
{
V_10 = ( ( V_10 >> V_16 ) | ( V_11 << ( 32 - V_16 ) ) ) & 0xffffffffL ;
V_11 = ( ( V_11 >> V_16 ) | ( V_8 << ( 32 - V_16 ) ) ) & 0xffffffffL ;
}
}
}
else
{
while ( V_15 >= V_12 )
{
V_15 -= V_12 ;
V_17 [ 0 ] = V_10 ;
V_17 [ 1 ] = V_11 ;
F_3 ( ( T_3 * ) V_17 , V_5 , V_19 ) ;
F_4 ( V_1 , V_8 , V_9 , V_12 ) ;
V_1 += V_12 ;
if ( V_16 == 32 )
{ V_10 = V_11 ; V_11 = V_8 ; }
else if ( V_16 == 64 )
{ V_10 = V_8 ; V_11 = V_9 ; }
else if ( V_16 > 32 )
{
V_10 = ( ( V_11 >> ( V_16 - 32 ) ) | ( V_8 << ( 64 - V_16 ) ) ) & 0xffffffffL ;
V_11 = ( ( V_8 >> ( V_16 - 32 ) ) | ( V_9 << ( 64 - V_16 ) ) ) & 0xffffffffL ;
}
else
{
V_10 = ( ( V_10 >> V_16 ) | ( V_11 << ( 32 - V_16 ) ) ) & 0xffffffffL ;
V_11 = ( ( V_11 >> V_16 ) | ( V_8 << ( 32 - V_16 ) ) ) & 0xffffffffL ;
}
V_8 = ( V_8 ^ V_17 [ 0 ] ) & V_13 ;
V_9 = ( V_9 ^ V_17 [ 1 ] ) & V_14 ;
F_5 ( V_8 , V_9 , V_2 , V_12 ) ;
V_2 += V_12 ;
}
}
V_18 = & ( * V_6 ) [ 0 ] ;
F_6 ( V_10 , V_18 ) ;
F_6 ( V_11 , V_18 ) ;
V_10 = V_11 = V_8 = V_9 = V_17 [ 0 ] = V_17 [ 1 ] = 0 ;
}
