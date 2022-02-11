int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
T_2 * V_3 [ 3 ] ;
T_3 V_4 ;
unsigned int V_5 , V_6 , V_7 = 0 , V_8 , V_9 = 0 ;
int V_10 , V_11 = - 1 ;
unsigned char * V_12 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_3 [ 0 ] = V_1 -> V_12 ;
V_3 [ 1 ] = V_1 -> V_13 ;
V_3 [ 2 ] = V_1 -> V_14 ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
{
if ( V_3 [ V_6 ] == NULL ) continue;
V_5 = F_2 ( V_3 [ V_6 ] ) ;
V_8 = ( ( V_5 == 0 ) ? 0 : ( ( V_5 / 8 ) + 1 ) ) ;
if ( V_8 > V_9 ) V_9 = V_8 ;
V_8 = F_3 ( 0 , V_8 ,
( V_3 [ V_6 ] -> V_15 ) ? V_16 : V_17 ) ;
V_7 += V_8 ;
}
V_10 = F_3 ( 1 , V_7 , V_18 ) ;
if ( V_2 == NULL ) return ( V_10 ) ;
V_12 = * V_2 ;
F_4 ( & V_12 , 1 , V_7 , V_18 , V_19 ) ;
V_4 . type = V_17 ;
V_4 . V_20 = ( unsigned char * ) Malloc ( V_9 + 4 ) ;
if ( V_4 . V_20 == NULL )
{
F_5 ( V_21 , V_22 ) ;
goto V_23;
}
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
{
if ( V_3 [ V_6 ] == NULL ) continue;
V_4 . V_24 = F_6 ( V_3 [ V_6 ] , V_4 . V_20 ) ;
F_7 ( & V_4 , & V_12 ) ;
}
Free ( V_4 . V_20 ) ;
V_11 = V_10 ;
V_23:
* V_2 = V_12 ;
return ( V_11 ) ;
}
