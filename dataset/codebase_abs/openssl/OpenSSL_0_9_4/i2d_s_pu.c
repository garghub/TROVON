int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
T_2 * V_3 [ 4 ] ;
T_3 V_4 ;
unsigned int V_5 , V_6 , V_7 = 0 , V_8 , V_9 = 0 , V_10 = 0 , V_11 , V_12 = 1 ;
unsigned char * V_13 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_11 = V_1 -> V_14 ;
V_3 [ 0 ] = V_1 -> V_15 ;
if ( V_11 )
{
V_3 [ 1 ] = V_1 -> V_13 ;
V_3 [ 2 ] = V_1 -> V_16 ;
V_3 [ 3 ] = V_1 -> V_17 ;
V_12 = 4 ;
}
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ )
{
V_5 = F_2 ( V_3 [ V_6 ] ) ;
V_8 = ( ( V_5 == 0 ) ? 0 : ( ( V_5 / 8 ) + 1 ) ) ;
if ( V_8 > V_9 ) V_9 = V_8 ;
V_8 = F_3 ( 0 , V_8 ,
( V_3 [ V_6 ] -> V_18 ) ? V_19 : V_20 ) ;
V_7 += V_8 ;
}
if ( V_11 )
{
V_10 = F_3 ( 1 , V_7 , V_21 ) ;
if ( V_2 == NULL ) return ( V_10 ) ;
}
else
{
if ( V_2 == NULL ) return ( V_7 ) ;
}
V_13 = * V_2 ;
if ( V_11 )
F_4 ( & V_13 , 1 , V_7 , V_21 , V_22 ) ;
V_4 . type = V_20 ;
V_4 . V_23 = ( unsigned char * ) Malloc ( V_9 + 4 ) ;
if ( V_4 . V_23 == NULL )
{
F_5 ( V_24 , V_25 ) ;
return ( - 1 ) ;
}
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ )
{
V_4 . V_26 = F_6 ( V_3 [ V_6 ] , V_4 . V_23 ) ;
F_7 ( & V_4 , & V_13 ) ;
}
Free ( ( char * ) V_4 . V_23 ) ;
* V_2 = V_13 ;
if( V_11 ) return ( V_10 ) ;
else return ( V_7 ) ;
}
