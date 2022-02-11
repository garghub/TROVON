int F_1 ( const T_1 * V_1 , unsigned char * V_2 )
{
int V_3 ;
int V_4 = 0 ;
int V_5 = 0 ;
long V_6 ;
V_3 = F_2 ( V_1 ) ;
V_4 = ( V_3 + 7 ) / 8 ;
if ( V_3 > 0 ) {
V_5 = ( ( V_3 & 0x07 ) == 0 ) ;
}
if ( V_2 == NULL )
return ( V_4 + 4 + V_5 ) ;
V_6 = V_4 + V_5 ;
V_2 [ 0 ] = ( unsigned char ) ( V_6 >> 24 ) & 0xff ;
V_2 [ 1 ] = ( unsigned char ) ( V_6 >> 16 ) & 0xff ;
V_2 [ 2 ] = ( unsigned char ) ( V_6 >> 8 ) & 0xff ;
V_2 [ 3 ] = ( unsigned char ) ( V_6 ) & 0xff ;
if ( V_5 )
V_2 [ 4 ] = 0 ;
V_4 = F_3 ( V_1 , & ( V_2 [ 4 + V_5 ] ) ) ;
if ( V_1 -> V_7 )
V_2 [ 4 ] |= 0x80 ;
return ( V_4 + 4 + V_5 ) ;
}
T_1 * F_4 ( const unsigned char * V_2 , int V_8 , T_1 * V_1 )
{
long V_9 ;
int V_7 = 0 ;
if ( V_8 < 4 ) {
F_5 ( V_10 , V_11 ) ;
return ( NULL ) ;
}
V_9 = ( ( long ) V_2 [ 0 ] << 24 ) | ( ( long ) V_2 [ 1 ] << 16 ) | ( ( int ) V_2 [ 2 ] << 8 ) | ( int )
V_2 [ 3 ] ;
if ( ( V_9 + 4 ) != V_8 ) {
F_5 ( V_10 , V_12 ) ;
return ( NULL ) ;
}
if ( V_1 == NULL )
V_1 = F_6 () ;
if ( V_1 == NULL )
return ( NULL ) ;
if ( V_9 == 0 ) {
V_1 -> V_7 = 0 ;
V_1 -> V_13 = 0 ;
return ( V_1 ) ;
}
V_2 += 4 ;
if ( ( * V_2 ) & 0x80 )
V_7 = 1 ;
if ( F_7 ( V_2 , ( int ) V_9 , V_1 ) == NULL )
return ( NULL ) ;
V_1 -> V_7 = V_7 ;
if ( V_7 ) {
F_8 ( V_1 , F_2 ( V_1 ) - 1 ) ;
}
F_9 ( V_1 ) ;
return ( V_1 ) ;
}
