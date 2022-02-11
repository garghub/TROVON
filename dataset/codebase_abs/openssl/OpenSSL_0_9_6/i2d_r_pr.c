int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
T_2 * V_3 [ 9 ] ;
unsigned char V_4 [ 1 ] ;
T_3 V_5 ;
unsigned int V_6 , V_7 , V_8 , V_9 , V_10 , V_11 = 0 ;
unsigned char * V_12 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_3 [ 1 ] = V_1 -> V_13 ;
V_3 [ 2 ] = V_1 -> V_14 ;
V_3 [ 3 ] = V_1 -> V_15 ;
V_3 [ 4 ] = V_1 -> V_12 ;
V_3 [ 5 ] = V_1 -> V_16 ;
V_3 [ 6 ] = V_1 -> V_17 ;
V_3 [ 7 ] = V_1 -> V_18 ;
V_3 [ 8 ] = V_1 -> V_19 ;
V_5 . V_20 = 1 ;
V_5 . V_4 = V_4 ;
V_5 . type = V_21 ;
V_4 [ 0 ] = V_1 -> V_22 & 0x7f ;
V_8 = F_2 ( & ( V_5 ) , NULL ) ;
for ( V_7 = 1 ; V_7 < 9 ; V_7 ++ )
{
V_6 = F_3 ( V_3 [ V_7 ] ) ;
V_10 = ( ( V_6 == 0 ) ? 0 : ( ( V_6 / 8 ) + 1 ) ) ;
if ( V_10 > V_11 ) V_11 = V_10 ;
V_10 = F_4 ( 0 , V_10 ,
( V_3 [ V_7 ] -> V_23 ) ? V_24 : V_21 ) ;
V_8 += V_10 ;
}
V_9 = F_4 ( 1 , V_8 , V_25 ) ;
if ( V_2 == NULL ) return ( V_9 ) ;
V_12 = * V_2 ;
F_5 ( & V_12 , 1 , V_8 , V_25 , V_26 ) ;
F_2 ( & V_5 , & V_12 ) ;
V_5 . V_4 = ( unsigned char * ) F_6 ( V_11 + 4 ) ;
if ( V_5 . V_4 == NULL )
{
F_7 ( V_27 , V_28 ) ;
return ( - 1 ) ;
}
for ( V_7 = 1 ; V_7 < 9 ; V_7 ++ )
{
V_5 . V_20 = F_8 ( V_3 [ V_7 ] , V_5 . V_4 ) ;
F_2 ( & V_5 , & V_12 ) ;
}
F_9 ( V_5 . V_4 ) ;
* V_2 = V_12 ;
return ( V_9 ) ;
}
