int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
T_2 * V_3 [ 2 ] ;
T_3 V_4 ;
unsigned int V_5 , V_6 , V_7 = 0 , V_8 , V_9 = 0 , V_10 ;
unsigned char * V_11 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_3 [ 0 ] = V_1 -> V_12 ;
V_3 [ 1 ] = V_1 -> V_13 ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ )
{
V_5 = F_2 ( V_3 [ V_6 ] ) ;
V_8 = ( ( V_5 == 0 ) ? 0 : ( ( V_5 / 8 ) + 1 ) ) ;
if ( V_8 > V_9 ) V_9 = V_8 ;
V_8 = F_3 ( 0 , V_8 ,
( V_3 [ V_6 ] -> V_14 ) ? V_15 : V_16 ) ;
V_7 += V_8 ;
}
V_10 = F_3 ( 1 , V_7 , V_17 ) ;
if ( V_2 == NULL ) return ( V_10 ) ;
V_11 = * V_2 ;
F_4 ( & V_11 , 1 , V_7 , V_17 , V_18 ) ;
V_4 . type = V_16 ;
V_4 . V_19 = ( unsigned char * ) Malloc ( V_9 + 4 ) ;
if ( V_4 . V_19 == NULL )
{
F_5 ( V_20 , V_21 ) ;
return ( - 1 ) ;
}
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ )
{
V_4 . V_22 = F_6 ( V_3 [ V_6 ] , V_4 . V_19 ) ;
F_7 ( & V_4 , & V_11 ) ;
}
Free ( ( char * ) V_4 . V_19 ) ;
* V_2 = V_11 ;
return ( V_10 ) ;
}
