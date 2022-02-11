void F_1 ( T_1 * V_1 , int V_2 , const unsigned char * V_3 , int V_4 )
#ifdef F_2
{
F_3 ( V_5 ) ;
F_4 ( V_1 , V_2 , V_3 , V_4 ) ;
}
void F_4 ( T_1 * V_1 , int V_2 , const unsigned char * V_3 , int V_4 )
#endif
{
int V_6 , V_7 ;
unsigned char * V_8 ;
T_2 * V_9 ;
unsigned int V_10 , V_11 ;
V_8 = ( unsigned char * ) & ( V_1 -> V_3 [ 0 ] ) ;
* V_8 = 0 ;
if ( V_2 > 128 ) V_2 = 128 ;
if ( V_4 <= 0 ) V_4 = 1024 ;
if ( V_4 > 1024 ) V_4 = 1024 ;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ )
V_8 [ V_6 ] = V_3 [ V_6 ] ;
V_11 = V_8 [ V_2 - 1 ] ;
V_7 = 0 ;
for ( V_6 = V_2 ; V_6 < 128 ; V_6 ++ , V_7 ++ )
{
V_11 = V_12 [ ( V_8 [ V_7 ] + V_11 ) & 0xff ] ;
V_8 [ V_6 ] = V_11 ;
}
V_7 = ( V_4 + 7 ) >> 3 ;
V_6 = 128 - V_7 ;
V_10 = ( 0xff >> ( - V_4 & 0x07 ) ) ;
V_11 = V_12 [ V_8 [ V_6 ] & V_10 ] ;
V_8 [ V_6 ] = V_11 ;
while ( V_6 -- )
{
V_11 = V_12 [ V_8 [ V_6 + V_7 ] ^ V_11 ] ;
V_8 [ V_6 ] = V_11 ;
}
V_9 = & ( V_1 -> V_3 [ 63 ] ) ;
for ( V_6 = 127 ; V_6 >= 0 ; V_6 -= 2 )
* ( V_9 -- ) = ( ( V_8 [ V_6 ] << 8 ) | V_8 [ V_6 - 1 ] ) & 0xffff ;
}
