void F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = 0 ;
V_1 -> V_3 = 1 ;
memset ( & ( V_1 -> V_4 [ 0 ] ) , 0x52 , V_5 ) ;
memset ( & ( V_1 -> V_6 [ 0 ] ) , 0x25 , V_5 ) ;
}
void F_2 ( T_1 * V_1 , register unsigned char * V_7 , unsigned long V_8 )
{
int V_9 , V_10 ;
V_9 = V_1 -> V_2 ;
if ( V_9 != 0 )
{
if ( V_9 + V_8 < V_5 )
{
memcpy ( & ( V_1 -> V_11 [ V_9 ] ) , V_7 , ( int ) V_8 ) ;
V_1 -> V_2 += ( int ) V_8 ;
return;
}
else
{
V_10 = V_5 - V_9 ;
memcpy ( & ( V_1 -> V_11 [ V_9 ] ) , V_7 , V_10 ) ;
V_8 -= V_10 ;
V_7 += V_10 ;
V_1 -> V_2 = 0 ;
F_3 ( V_1 , & ( V_1 -> V_11 [ 0 ] ) , V_5 ) ;
}
}
V_9 = ( int ) ( V_8 & ( unsigned long ) ~ ( V_5 - 1 ) ) ;
if ( V_9 > 0 ) F_3 ( V_1 , V_7 , V_9 ) ;
V_10 = ( int ) V_8 - V_9 ;
if ( V_10 > 0 )
{
memcpy ( & ( V_1 -> V_11 [ 0 ] ) , & ( V_7 [ V_9 ] ) , V_10 ) ;
V_1 -> V_2 = V_10 ;
}
}
static void F_3 ( T_1 * V_1 , unsigned char * V_7 , unsigned int V_8 )
{
register T_2 V_12 , V_13 ;
register T_2 V_14 , V_15 ;
T_2 V_16 [ 2 ] , V_17 [ 2 ] ;
T_3 V_18 ;
unsigned char * V_19 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 += 8 )
{
F_4 ( V_7 , V_12 ) ; V_16 [ 0 ] = V_17 [ 0 ] = V_12 ;
F_4 ( V_7 , V_13 ) ; V_16 [ 1 ] = V_17 [ 1 ] = V_13 ;
V_1 -> V_4 [ 0 ] = ( V_1 -> V_4 [ 0 ] & 0x9f ) | 0x40 ;
V_1 -> V_6 [ 0 ] = ( V_1 -> V_6 [ 0 ] & 0x9f ) | 0x20 ;
F_5 ( & V_1 -> V_4 ) ;
F_6 ( & V_1 -> V_4 , V_18 ) ;
F_7 ( V_16 , V_18 , 1 ) ;
F_5 ( & V_1 -> V_6 ) ;
F_6 ( & V_1 -> V_6 , V_18 ) ;
F_7 ( V_17 , V_18 , 1 ) ;
V_14 = V_12 ^ V_17 [ 0 ] ;
V_15 = V_13 ^ V_17 [ 1 ] ;
V_12 ^= V_16 [ 0 ] ;
V_13 ^= V_16 [ 1 ] ;
V_19 = V_1 -> V_4 ;
F_8 ( V_12 , V_19 ) ;
F_8 ( V_15 , V_19 ) ;
V_19 = V_1 -> V_6 ;
F_8 ( V_14 , V_19 ) ;
F_8 ( V_13 , V_19 ) ;
}
}
void F_9 ( unsigned char * V_20 , T_1 * V_1 )
{
int V_9 , V_10 ;
V_9 = V_1 -> V_2 ;
V_10 = V_1 -> V_3 ;
if ( ( V_9 > 0 ) || ( V_10 == 2 ) )
{
if ( V_10 == 2 )
V_1 -> V_11 [ V_9 ++ ] = 0x80 ;
memset ( & ( V_1 -> V_11 [ V_9 ] ) , 0 , V_5 - V_9 ) ;
F_3 ( V_1 , V_1 -> V_11 , V_5 ) ;
}
memcpy ( V_20 , ( char * ) V_1 -> V_4 , V_5 ) ;
memcpy ( & ( V_20 [ V_5 ] ) , ( char * ) V_1 -> V_6 , V_5 ) ;
}
main ()
{
unsigned char V_20 [ V_21 ] ;
int V_9 ;
T_1 V_1 ;
static char * V_22 = L_1 ;
F_1 ( & V_1 ) ;
F_2 ( & V_1 , V_22 , strlen ( V_22 ) ) ;
F_9 ( & ( V_20 [ 0 ] ) , & V_1 ) ;
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ )
printf ( L_2 , V_20 [ V_9 ] ) ;
printf ( L_3 ) ;
}
