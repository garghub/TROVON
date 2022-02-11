void F_1 ( T_1 * V_1 , int V_2 , const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
unsigned char * V_7 ;
T_2 * V_8 ;
unsigned int V_9 , V_10 ;
V_7 = ( unsigned char * ) & ( V_1 -> V_3 [ 0 ] ) ;
* V_7 = 0 ;
if ( V_2 > 128 )
V_2 = 128 ;
if ( V_4 <= 0 )
V_4 = 1024 ;
if ( V_4 > 1024 )
V_4 = 1024 ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ )
V_7 [ V_5 ] = V_3 [ V_5 ] ;
V_10 = V_7 [ V_2 - 1 ] ;
V_6 = 0 ;
for ( V_5 = V_2 ; V_5 < 128 ; V_5 ++ , V_6 ++ ) {
V_10 = V_11 [ ( V_7 [ V_6 ] + V_10 ) & 0xff ] ;
V_7 [ V_5 ] = V_10 ;
}
V_6 = ( V_4 + 7 ) >> 3 ;
V_5 = 128 - V_6 ;
V_9 = ( 0xff >> ( - V_4 & 0x07 ) ) ;
V_10 = V_11 [ V_7 [ V_5 ] & V_9 ] ;
V_7 [ V_5 ] = V_10 ;
while ( V_5 -- ) {
V_10 = V_11 [ V_7 [ V_5 + V_6 ] ^ V_10 ] ;
V_7 [ V_5 ] = V_10 ;
}
V_8 = & ( V_1 -> V_3 [ 63 ] ) ;
for ( V_5 = 127 ; V_5 >= 0 ; V_5 -= 2 )
* ( V_8 -- ) = ( ( V_7 [ V_5 ] << 8 ) | V_7 [ V_5 - 1 ] ) & 0xffff ;
}
