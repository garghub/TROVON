void F_1 ( const unsigned char * V_1 , unsigned char * V_2 , int V_3 ,
long V_4 , T_1 * V_5 ,
T_2 * V_6 )
{
register T_3 V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 = ( V_3 + 7 ) / 8 ;
register T_3 V_14 , V_15 ;
register long V_16 = V_4 ;
register int V_17 = V_3 ;
T_3 V_18 [ 2 ] ;
unsigned char * V_19 ;
if ( V_17 > 64 ) return;
if ( V_17 > 32 )
{
V_14 = 0xffffffffL ;
if ( V_17 >= 64 )
V_15 = V_14 ;
else
V_15 = ( 1L << ( V_17 - 32 ) ) - 1 ;
}
else
{
if ( V_17 == 32 )
V_14 = 0xffffffffL ;
else
V_14 = ( 1L << V_17 ) - 1 ;
V_15 = 0x00000000L ;
}
V_19 = & ( * V_6 ) [ 0 ] ;
F_2 ( V_19 , V_11 ) ;
F_2 ( V_19 , V_12 ) ;
V_18 [ 0 ] = V_11 ;
V_18 [ 1 ] = V_12 ;
while ( V_16 -- > 0 )
{
V_18 [ 0 ] = V_11 ;
V_18 [ 1 ] = V_12 ;
F_3 ( ( T_3 * ) V_18 , V_5 , V_20 ) ;
V_9 = V_18 [ 0 ] ;
V_10 = V_18 [ 1 ] ;
F_4 ( V_1 , V_7 , V_8 , V_13 ) ;
V_1 += V_13 ;
V_7 = ( V_7 ^ V_9 ) & V_14 ;
V_8 = ( V_8 ^ V_10 ) & V_15 ;
F_5 ( V_7 , V_8 , V_2 , V_13 ) ;
V_2 += V_13 ;
if ( V_17 == 32 )
{ V_11 = V_12 ; V_12 = V_9 ; }
else if ( V_17 == 64 )
{ V_11 = V_9 ; V_12 = V_10 ; }
else if ( V_17 > 32 )
{
V_11 = ( ( V_12 >> ( V_17 - 32 ) ) | ( V_9 << ( 64 - V_17 ) ) ) & 0xffffffffL ;
V_12 = ( ( V_9 >> ( V_17 - 32 ) ) | ( V_10 << ( 64 - V_17 ) ) ) & 0xffffffffL ;
}
else
{
V_11 = ( ( V_11 >> V_17 ) | ( V_12 << ( 32 - V_17 ) ) ) & 0xffffffffL ;
V_12 = ( ( V_12 >> V_17 ) | ( V_9 << ( 32 - V_17 ) ) ) & 0xffffffffL ;
}
}
V_19 = & ( * V_6 ) [ 0 ] ;
F_6 ( V_11 , V_19 ) ;
F_6 ( V_12 , V_19 ) ;
V_11 = V_12 = V_7 = V_8 = V_18 [ 0 ] = V_18 [ 1 ] = V_9 = V_10 = 0 ;
}
