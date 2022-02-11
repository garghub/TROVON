void F_1 ( T_1 * V_1 , int V_2 , const unsigned char * V_3 )
#ifdef F_2
{
F_3 ( V_4 ) ;
F_4 ( V_1 , V_2 , V_3 ) ;
}
void F_4 ( T_1 * V_1 , int V_2 , const unsigned char * V_3 )
#endif
{
int V_5 ;
T_2 * V_6 , V_7 , V_8 [ 2 ] ;
const unsigned char * V_9 , * V_10 ;
memcpy ( V_1 , & V_11 , sizeof( T_1 ) ) ;
V_6 = V_1 -> V_12 ;
if ( V_2 > ( ( V_13 + 2 ) * 4 ) ) V_2 = ( V_13 + 2 ) * 4 ;
V_9 = V_3 ;
V_10 = & ( V_3 [ V_2 ] ) ;
for ( V_5 = 0 ; V_5 < ( V_13 + 2 ) ; V_5 ++ )
{
V_7 = * ( V_9 ++ ) ;
if ( V_9 >= V_10 ) V_9 = V_3 ;
V_7 <<= 8 ;
V_7 |= * ( V_9 ++ ) ;
if ( V_9 >= V_10 ) V_9 = V_3 ;
V_7 <<= 8 ;
V_7 |= * ( V_9 ++ ) ;
if ( V_9 >= V_10 ) V_9 = V_3 ;
V_7 <<= 8 ;
V_7 |= * ( V_9 ++ ) ;
if ( V_9 >= V_10 ) V_9 = V_3 ;
V_6 [ V_5 ] ^= V_7 ;
}
V_8 [ 0 ] = 0L ;
V_8 [ 1 ] = 0L ;
for ( V_5 = 0 ; V_5 < ( V_13 + 2 ) ; V_5 += 2 )
{
F_5 ( V_8 , V_1 ) ;
V_6 [ V_5 ] = V_8 [ 0 ] ;
V_6 [ V_5 + 1 ] = V_8 [ 1 ] ;
}
V_6 = V_1 -> V_14 ;
for ( V_5 = 0 ; V_5 < 4 * 256 ; V_5 += 2 )
{
F_5 ( V_8 , V_1 ) ;
V_6 [ V_5 ] = V_8 [ 0 ] ;
V_6 [ V_5 + 1 ] = V_8 [ 1 ] ;
}
}
