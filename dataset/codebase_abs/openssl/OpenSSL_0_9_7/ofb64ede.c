void F_1 ( register const unsigned char * V_1 ,
register unsigned char * V_2 , long V_3 ,
T_1 * V_4 , T_1 * V_5 ,
T_1 * V_6 , T_2 * V_7 ,
int * V_8 )
{
register T_3 V_9 , V_10 ;
register int V_11 = * V_8 ;
register long V_12 = V_3 ;
T_2 V_13 ;
register char * V_14 ;
T_3 V_15 [ 2 ] ;
unsigned char * V_16 ;
int V_17 = 0 ;
V_16 = & ( * V_7 ) [ 0 ] ;
F_2 ( V_16 , V_9 ) ;
F_2 ( V_16 , V_10 ) ;
V_15 [ 0 ] = V_9 ;
V_15 [ 1 ] = V_10 ;
V_14 = ( char * ) V_13 ;
F_3 ( V_9 , V_14 ) ;
F_3 ( V_10 , V_14 ) ;
while ( V_12 -- )
{
if ( V_11 == 0 )
{
F_4 ( V_15 , V_4 , V_5 , V_6 ) ;
V_9 = V_15 [ 0 ] ;
V_10 = V_15 [ 1 ] ;
V_14 = ( char * ) V_13 ;
F_3 ( V_9 , V_14 ) ;
F_3 ( V_10 , V_14 ) ;
V_17 ++ ;
}
* ( V_2 ++ ) = * ( V_1 ++ ) ^ V_13 [ V_11 ] ;
V_11 = ( V_11 + 1 ) & 0x07 ;
}
if ( V_17 )
{
V_16 = & ( * V_7 ) [ 0 ] ;
F_3 ( V_9 , V_16 ) ;
F_3 ( V_10 , V_16 ) ;
}
V_9 = V_10 = V_15 [ 0 ] = V_15 [ 1 ] = 0 ;
* V_8 = V_11 ;
}
