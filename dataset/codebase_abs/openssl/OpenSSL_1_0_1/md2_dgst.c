const char * F_1 ( void )
{
if ( sizeof( V_1 ) == 1 )
return ( L_1 ) ;
else
return ( L_2 ) ;
}
int F_2 ( T_1 * V_2 , const unsigned char * V_3 , T_2 V_4 )
{
register T_3 * V_5 ;
if ( V_4 == 0 ) return 1 ;
V_5 = V_2 -> V_3 ;
if ( V_2 -> V_6 != 0 )
{
if ( ( V_2 -> V_6 + V_4 ) >= V_7 )
{
memcpy ( & ( V_5 [ V_2 -> V_6 ] ) , V_3 , V_7 - V_2 -> V_6 ) ;
F_3 ( V_2 , V_2 -> V_3 ) ;
V_3 += ( V_7 - V_2 -> V_6 ) ;
V_4 -= ( V_7 - V_2 -> V_6 ) ;
V_2 -> V_6 = 0 ;
}
else
{
memcpy ( & ( V_5 [ V_2 -> V_6 ] ) , V_3 , V_4 ) ;
V_2 -> V_6 += ( int ) V_4 ;
return 1 ;
}
}
while ( V_4 >= V_7 )
{
F_3 ( V_2 , V_3 ) ;
V_3 += V_7 ;
V_4 -= V_7 ;
}
memcpy ( V_5 , V_3 , V_4 ) ;
V_2 -> V_6 = ( int ) V_4 ;
return 1 ;
}
static void F_3 ( T_1 * V_2 , const unsigned char * V_8 )
{
register V_1 V_9 , * V_10 , * V_11 ;
register int V_12 , V_13 ;
V_1 V_14 [ 48 ] ;
V_10 = V_2 -> V_14 ;
V_11 = V_2 -> V_15 ;
V_13 = V_11 [ V_7 - 1 ] ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
{
V_14 [ V_12 ] = V_10 [ V_12 ] ;
V_14 [ V_12 + 16 ] = V_9 = V_8 [ V_12 ] ;
V_14 [ V_12 + 32 ] = ( V_9 ^ V_10 [ V_12 ] ) ;
V_13 = V_11 [ V_12 ] ^= V_16 [ V_9 ^ V_13 ] ;
}
V_9 = 0 ;
for ( V_12 = 0 ; V_12 < 18 ; V_12 ++ )
{
for ( V_13 = 0 ; V_13 < 48 ; V_13 += 8 )
{
V_9 = V_14 [ V_13 + 0 ] ^= V_16 [ V_9 ] ;
V_9 = V_14 [ V_13 + 1 ] ^= V_16 [ V_9 ] ;
V_9 = V_14 [ V_13 + 2 ] ^= V_16 [ V_9 ] ;
V_9 = V_14 [ V_13 + 3 ] ^= V_16 [ V_9 ] ;
V_9 = V_14 [ V_13 + 4 ] ^= V_16 [ V_9 ] ;
V_9 = V_14 [ V_13 + 5 ] ^= V_16 [ V_9 ] ;
V_9 = V_14 [ V_13 + 6 ] ^= V_16 [ V_9 ] ;
V_9 = V_14 [ V_13 + 7 ] ^= V_16 [ V_9 ] ;
}
V_9 = ( V_9 + V_12 ) & 0xff ;
}
memcpy ( V_10 , V_14 , 16 * sizeof( V_1 ) ) ;
F_4 ( V_14 , 48 * sizeof( V_1 ) ) ;
}
int F_5 ( unsigned char * V_17 , T_1 * V_2 )
{
int V_12 , V_18 ;
register T_3 * V_19 ;
register V_1 * V_20 , * V_21 ;
V_19 = V_2 -> V_3 ;
V_20 = V_2 -> V_14 ;
V_21 = V_2 -> V_15 ;
V_18 = V_7 - V_2 -> V_6 ;
for ( V_12 = V_2 -> V_6 ; V_12 < V_7 ; V_12 ++ )
V_19 [ V_12 ] = ( T_3 ) V_18 ;
F_3 ( V_2 , V_19 ) ;
for ( V_12 = 0 ; V_12 < V_7 ; V_12 ++ )
V_19 [ V_12 ] = ( T_3 ) V_21 [ V_12 ] ;
F_3 ( V_2 , V_19 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
V_17 [ V_12 ] = ( T_3 ) ( V_20 [ V_12 ] & 0xff ) ;
memset ( ( char * ) & V_2 , 0 , sizeof( V_2 ) ) ;
return 1 ;
}
