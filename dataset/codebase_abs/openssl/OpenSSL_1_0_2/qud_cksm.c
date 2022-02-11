T_1 F_1 ( const unsigned char * V_1 , T_2 V_2 [] ,
long V_3 , int V_4 , T_2 * V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
int V_10 ;
long V_11 ;
const unsigned char * V_12 ;
#ifdef F_2
struct V_13 {
int V_14 : 32 ;
int V_15 : 32 ;
} * V_16 ;
#else
T_1 * V_16 ;
#endif
if ( V_4 < 1 )
V_4 = 1 ;
#ifdef F_2
V_16 = (struct V_13 * ) & ( V_2 [ 0 ] ) [ 0 ] ;
#else
V_16 = ( T_1 * ) & ( V_2 [ 0 ] ) [ 0 ] ;
#endif
V_6 = F_3 ( ( * V_5 ) [ 0 ] ) | F_4 ( ( * V_5 ) [ 1 ] ) | F_5 ( ( * V_5 ) [ 2 ] ) |
F_6 ( ( * V_5 ) [ 3 ] ) ;
V_7 = F_3 ( ( * V_5 ) [ 4 ] ) | F_4 ( ( * V_5 ) [ 5 ] ) | F_5 ( ( * V_5 ) [ 6 ] ) |
F_6 ( ( * V_5 ) [ 7 ] ) ;
for ( V_10 = 0 ; ( ( V_10 < 4 ) && ( V_10 < V_4 ) ) ; V_10 ++ ) {
V_12 = V_1 ;
V_11 = V_3 ;
while ( V_11 > 0 ) {
if ( V_11 > 1 ) {
V_8 = ( T_1 ) ( * ( V_12 ++ ) ) ;
V_8 |= ( T_1 ) F_4 ( * ( V_12 ++ ) ) ;
V_11 -- ;
} else
V_8 = ( T_1 ) ( * ( V_12 ++ ) ) ;
V_11 -- ;
V_8 += V_6 ;
V_8 &= 0xffffffffL ;
V_9 = V_7 ;
V_6 = ( ( ( ( V_8 * V_8 ) & 0xffffffffL ) + ( ( V_9 * V_9 ) & 0xffffffffL ) )
& 0xffffffffL ) % 0x7fffffffL ;
V_7 = ( ( V_8 * ( ( V_9 + V_17 ) & 0xffffffffL ) ) & 0xffffffffL ) %
0x7fffffffL ;
}
if ( V_16 != NULL ) {
#ifdef F_2
( * V_16 ) . V_14 = V_6 ;
( * V_16 ) . V_15 = V_7 ;
V_16 ++ ;
#else
* V_16 ++ = V_6 ;
* V_16 ++ = V_7 ;
#endif
}
}
return ( V_6 ) ;
}
