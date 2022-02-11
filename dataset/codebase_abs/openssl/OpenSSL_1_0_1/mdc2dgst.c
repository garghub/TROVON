int F_1 ( T_1 * V_1 , const unsigned char * V_2 , T_2 V_3 )
{
T_2 V_4 , V_5 ;
V_4 = V_1 -> V_6 ;
if ( V_4 != 0 )
{
if ( V_4 + V_3 < V_7 )
{
memcpy ( & ( V_1 -> V_8 [ V_4 ] ) , V_2 , V_3 ) ;
V_1 -> V_6 += ( int ) V_3 ;
return 1 ;
}
else
{
V_5 = V_7 - V_4 ;
memcpy ( & ( V_1 -> V_8 [ V_4 ] ) , V_2 , V_5 ) ;
V_3 -= V_5 ;
V_2 += V_5 ;
V_1 -> V_6 = 0 ;
F_2 ( V_1 , & ( V_1 -> V_8 [ 0 ] ) , V_7 ) ;
}
}
V_4 = V_3 & ~ ( ( T_2 ) V_7 - 1 ) ;
if ( V_4 > 0 ) F_2 ( V_1 , V_2 , V_4 ) ;
V_5 = V_3 - V_4 ;
if ( V_5 > 0 )
{
memcpy ( & ( V_1 -> V_8 [ 0 ] ) , & ( V_2 [ V_4 ] ) , V_5 ) ;
V_1 -> V_6 = ( int ) V_5 ;
}
return 1 ;
}
static void F_2 ( T_1 * V_1 , const unsigned char * V_2 , T_2 V_3 )
{
register T_3 V_9 , V_10 ;
register T_3 V_11 , V_12 ;
T_3 V_13 [ 2 ] , V_14 [ 2 ] ;
T_4 V_15 ;
unsigned char * V_16 ;
T_2 V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 += 8 )
{
F_3 ( V_2 , V_9 ) ; V_13 [ 0 ] = V_14 [ 0 ] = V_9 ;
F_3 ( V_2 , V_10 ) ; V_13 [ 1 ] = V_14 [ 1 ] = V_10 ;
V_1 -> V_17 [ 0 ] = ( V_1 -> V_17 [ 0 ] & 0x9f ) | 0x40 ;
V_1 -> V_18 [ 0 ] = ( V_1 -> V_18 [ 0 ] & 0x9f ) | 0x20 ;
F_4 ( & V_1 -> V_17 ) ;
F_5 ( & V_1 -> V_17 , & V_15 ) ;
F_6 ( V_13 , & V_15 , 1 ) ;
F_4 ( & V_1 -> V_18 ) ;
F_5 ( & V_1 -> V_18 , & V_15 ) ;
F_6 ( V_14 , & V_15 , 1 ) ;
V_11 = V_9 ^ V_14 [ 0 ] ;
V_12 = V_10 ^ V_14 [ 1 ] ;
V_9 ^= V_13 [ 0 ] ;
V_10 ^= V_13 [ 1 ] ;
V_16 = V_1 -> V_17 ;
F_7 ( V_9 , V_16 ) ;
F_7 ( V_12 , V_16 ) ;
V_16 = V_1 -> V_18 ;
F_7 ( V_11 , V_16 ) ;
F_7 ( V_10 , V_16 ) ;
}
}
int F_8 ( unsigned char * V_19 , T_1 * V_1 )
{
unsigned int V_4 ;
int V_5 ;
V_4 = V_1 -> V_6 ;
V_5 = V_1 -> V_20 ;
if ( ( V_4 > 0 ) || ( V_5 == 2 ) )
{
if ( V_5 == 2 )
V_1 -> V_8 [ V_4 ++ ] = 0x80 ;
memset ( & ( V_1 -> V_8 [ V_4 ] ) , 0 , V_7 - V_4 ) ;
F_2 ( V_1 , V_1 -> V_8 , V_7 ) ;
}
memcpy ( V_19 , ( char * ) V_1 -> V_17 , V_7 ) ;
memcpy ( & ( V_19 [ V_7 ] ) , ( char * ) V_1 -> V_18 , V_7 ) ;
return 1 ;
}
main ()
{
unsigned char V_19 [ V_21 ] ;
int V_4 ;
T_1 V_1 ;
static char * V_22 = L_1 ;
F_9 ( & V_1 ) ;
F_1 ( & V_1 , V_22 , strlen ( V_22 ) ) ;
F_8 ( & ( V_19 [ 0 ] ) , & V_1 ) ;
for ( V_4 = 0 ; V_4 < V_21 ; V_4 ++ )
printf ( L_2 , V_19 [ V_4 ] ) ;
printf ( L_3 ) ;
}
