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
if ( V_1 -> V_14 != 0 )
{
if ( ( V_3 [ 2 ] = F_2 () ) == NULL ) goto V_15;
if ( ! F_3 ( V_3 [ 2 ] , V_1 -> V_14 ) ) goto V_15;
}
else
V_3 [ 2 ] = NULL ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
{
if ( V_3 [ V_6 ] == NULL ) continue;
V_5 = F_4 ( V_3 [ V_6 ] ) ;
V_8 = ( ( V_5 == 0 ) ? 0 : ( ( V_5 / 8 ) + 1 ) ) ;
if ( V_8 > V_9 ) V_9 = V_8 ;
V_8 = F_5 ( 0 , V_8 ,
( V_3 [ V_6 ] -> V_16 ) ? V_17 : V_18 ) ;
V_7 += V_8 ;
}
V_10 = F_5 ( 1 , V_7 , V_19 ) ;
if ( V_2 == NULL ) return ( V_10 ) ;
V_12 = * V_2 ;
F_6 ( & V_12 , 1 , V_7 , V_19 , V_20 ) ;
V_4 . type = V_18 ;
V_4 . V_21 = ( unsigned char * ) Malloc ( V_9 + 4 ) ;
if ( V_4 . V_21 == NULL )
{
F_7 ( V_22 , V_23 ) ;
goto V_15;
}
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
{
if ( V_3 [ V_6 ] == NULL ) continue;
V_4 . V_14 = F_8 ( V_3 [ V_6 ] , V_4 . V_21 ) ;
F_9 ( & V_4 , & V_12 ) ;
}
Free ( ( char * ) V_4 . V_21 ) ;
V_11 = V_10 ;
V_15:
if ( V_3 [ 2 ] != NULL ) F_10 ( V_3 [ 2 ] ) ;
* V_2 = V_12 ;
return ( V_11 ) ;
}
