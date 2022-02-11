const char * F_1 ( void )
{
if ( sizeof( V_1 ) == 1 )
return ( L_1 ) ;
else
return ( L_2 ) ;
}
void F_2 ( T_1 * V_2 )
{
V_2 -> V_3 = 0 ;
memset ( V_2 -> V_4 , 0 , V_5 * sizeof( V_1 ) ) ;
memset ( V_2 -> V_6 , 0 , V_5 * sizeof( V_1 ) ) ;
memset ( V_2 -> V_7 , 0 , V_5 ) ;
}
void F_3 ( T_1 * V_2 , register unsigned char * V_7 , unsigned long V_8 )
{
register T_2 * V_9 ;
if ( V_8 == 0 ) return;
V_9 = V_2 -> V_7 ;
if ( V_2 -> V_3 != 0 )
{
if ( ( V_2 -> V_3 + V_8 ) >= V_5 )
{
memcpy ( & ( V_9 [ V_2 -> V_3 ] ) , V_7 , V_5 - V_2 -> V_3 ) ;
F_4 ( V_2 , V_2 -> V_7 ) ;
V_7 += ( V_5 - V_2 -> V_3 ) ;
V_8 -= ( V_5 - V_2 -> V_3 ) ;
V_2 -> V_3 = 0 ;
}
else
{
memcpy ( & ( V_9 [ V_2 -> V_3 ] ) , V_7 , ( int ) V_8 ) ;
V_2 -> V_3 += ( int ) V_8 ;
return;
}
}
while ( V_8 >= V_5 )
{
F_4 ( V_2 , V_7 ) ;
V_7 += V_5 ;
V_8 -= V_5 ;
}
memcpy ( V_9 , V_7 , ( int ) V_8 ) ;
V_2 -> V_3 = ( int ) V_8 ;
}
static void F_4 ( T_1 * V_2 , unsigned char * V_10 )
{
register V_1 V_11 , * V_12 , * V_13 ;
register int V_14 , V_15 ;
V_1 V_4 [ 48 ] ;
V_12 = V_2 -> V_4 ;
V_13 = V_2 -> V_6 ;
V_15 = V_13 [ V_5 - 1 ] ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ )
{
V_4 [ V_14 ] = V_12 [ V_14 ] ;
V_4 [ V_14 + 16 ] = V_11 = V_10 [ V_14 ] ;
V_4 [ V_14 + 32 ] = ( V_11 ^ V_12 [ V_14 ] ) ;
V_15 = V_13 [ V_14 ] ^= V_16 [ V_11 ^ V_15 ] ;
}
V_11 = 0 ;
for ( V_14 = 0 ; V_14 < 18 ; V_14 ++ )
{
for ( V_15 = 0 ; V_15 < 48 ; V_15 += 8 )
{
V_11 = V_4 [ V_15 + 0 ] ^= V_16 [ V_11 ] ;
V_11 = V_4 [ V_15 + 1 ] ^= V_16 [ V_11 ] ;
V_11 = V_4 [ V_15 + 2 ] ^= V_16 [ V_11 ] ;
V_11 = V_4 [ V_15 + 3 ] ^= V_16 [ V_11 ] ;
V_11 = V_4 [ V_15 + 4 ] ^= V_16 [ V_11 ] ;
V_11 = V_4 [ V_15 + 5 ] ^= V_16 [ V_11 ] ;
V_11 = V_4 [ V_15 + 6 ] ^= V_16 [ V_11 ] ;
V_11 = V_4 [ V_15 + 7 ] ^= V_16 [ V_11 ] ;
}
V_11 = ( V_11 + V_14 ) & 0xff ;
}
memcpy ( V_12 , V_4 , 16 * sizeof( V_1 ) ) ;
memset ( V_4 , 0 , 48 * sizeof( V_1 ) ) ;
}
void F_5 ( unsigned char * V_17 , T_1 * V_2 )
{
int V_14 , V_18 ;
register T_2 * V_19 ;
register V_1 * V_20 , * V_21 ;
V_19 = V_2 -> V_7 ;
V_20 = V_2 -> V_4 ;
V_21 = V_2 -> V_6 ;
V_18 = V_5 - V_2 -> V_3 ;
for ( V_14 = V_2 -> V_3 ; V_14 < V_5 ; V_14 ++ )
V_19 [ V_14 ] = ( T_2 ) V_18 ;
F_4 ( V_2 , V_19 ) ;
for ( V_14 = 0 ; V_14 < V_5 ; V_14 ++ )
V_19 [ V_14 ] = ( T_2 ) V_21 [ V_14 ] ;
F_4 ( V_2 , V_19 ) ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ )
V_17 [ V_14 ] = ( T_2 ) ( V_20 [ V_14 ] & 0xff ) ;
memset ( ( char * ) & V_2 , 0 , sizeof( V_2 ) ) ;
}
