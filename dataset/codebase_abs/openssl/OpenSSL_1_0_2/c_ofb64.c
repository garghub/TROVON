void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
long V_3 , const T_1 * V_4 ,
unsigned char * V_5 , int * V_6 )
{
register T_2 V_7 , V_8 , V_9 ;
register int V_10 = * V_6 ;
register long V_11 = V_3 ;
unsigned char V_12 [ 8 ] ;
register char * V_13 ;
T_2 V_14 [ 2 ] ;
unsigned char * V_15 ;
int V_16 = 0 ;
V_15 = V_5 ;
F_2 ( V_15 , V_7 ) ;
F_2 ( V_15 , V_8 ) ;
V_14 [ 0 ] = V_7 ;
V_14 [ 1 ] = V_8 ;
V_13 = ( char * ) V_12 ;
F_3 ( V_7 , V_13 ) ;
F_3 ( V_8 , V_13 ) ;
while ( V_11 -- ) {
if ( V_10 == 0 ) {
F_4 ( ( T_2 * ) V_14 , V_4 ) ;
V_13 = ( char * ) V_12 ;
V_9 = V_14 [ 0 ] ;
F_3 ( V_9 , V_13 ) ;
V_9 = V_14 [ 1 ] ;
F_3 ( V_9 , V_13 ) ;
V_16 ++ ;
}
* ( V_2 ++ ) = * ( V_1 ++ ) ^ V_12 [ V_10 ] ;
V_10 = ( V_10 + 1 ) & 0x07 ;
}
if ( V_16 ) {
V_7 = V_14 [ 0 ] ;
V_8 = V_14 [ 1 ] ;
V_15 = V_5 ;
F_3 ( V_7 , V_15 ) ;
F_3 ( V_8 , V_15 ) ;
}
V_9 = V_7 = V_8 = V_14 [ 0 ] = V_14 [ 1 ] = 0 ;
* V_6 = V_10 ;
}
