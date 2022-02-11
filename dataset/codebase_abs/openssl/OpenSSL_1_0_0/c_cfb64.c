void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
long V_3 , const T_1 * V_4 , unsigned char * V_5 ,
int * V_6 , int V_7 )
{
register T_2 V_8 , V_9 , V_10 ;
register int V_11 = * V_6 ;
register long V_12 = V_3 ;
T_2 V_13 [ 2 ] ;
unsigned char * V_14 , V_15 , V_16 ;
V_14 = V_5 ;
if ( V_7 )
{
while ( V_12 -- )
{
if ( V_11 == 0 )
{
F_2 ( V_14 , V_8 ) ; V_13 [ 0 ] = V_8 ;
F_2 ( V_14 , V_9 ) ; V_13 [ 1 ] = V_9 ;
F_3 ( ( T_2 * ) V_13 , V_4 ) ;
V_14 = V_5 ;
V_10 = V_13 [ 0 ] ; F_4 ( V_10 , V_14 ) ;
V_10 = V_13 [ 1 ] ; F_4 ( V_10 , V_14 ) ;
V_14 = V_5 ;
}
V_15 = * ( V_1 ++ ) ^ V_14 [ V_11 ] ;
* ( V_2 ++ ) = V_15 ;
V_14 [ V_11 ] = V_15 ;
V_11 = ( V_11 + 1 ) & 0x07 ;
}
}
else
{
while ( V_12 -- )
{
if ( V_11 == 0 )
{
F_2 ( V_14 , V_8 ) ; V_13 [ 0 ] = V_8 ;
F_2 ( V_14 , V_9 ) ; V_13 [ 1 ] = V_9 ;
F_3 ( ( T_2 * ) V_13 , V_4 ) ;
V_14 = V_5 ;
V_10 = V_13 [ 0 ] ; F_4 ( V_10 , V_14 ) ;
V_10 = V_13 [ 1 ] ; F_4 ( V_10 , V_14 ) ;
V_14 = V_5 ;
}
V_16 = * ( V_1 ++ ) ;
V_15 = V_14 [ V_11 ] ;
V_14 [ V_11 ] = V_16 ;
* ( V_2 ++ ) = V_15 ^ V_16 ;
V_11 = ( V_11 + 1 ) & 0x07 ;
}
}
V_8 = V_9 = V_13 [ 0 ] = V_13 [ 1 ] = V_10 = V_15 = V_16 = 0 ;
* V_6 = V_11 ;
}
