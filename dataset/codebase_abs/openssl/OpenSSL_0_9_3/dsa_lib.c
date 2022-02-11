T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
{
F_2 ( V_2 , V_3 ) ;
return ( NULL ) ;
}
V_1 -> V_4 = 0 ;
V_1 -> V_5 = 0 ;
V_1 -> V_6 = 1 ;
V_1 -> V_7 = NULL ;
V_1 -> V_8 = NULL ;
V_1 -> V_9 = NULL ;
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = NULL ;
V_1 -> V_13 = NULL ;
V_1 -> V_14 = NULL ;
V_1 -> V_15 = NULL ;
V_1 -> V_16 = NULL ;
V_1 -> V_17 = 1 ;
return ( V_1 ) ;
}
void F_3 ( T_1 * V_15 )
{
int V_18 ;
if ( V_15 == NULL ) return;
V_18 = F_4 ( & V_15 -> V_17 , - 1 , V_19 ) ;
#ifdef F_5
F_5 ( L_1 , V_15 ) ;
#endif
if ( V_18 > 0 ) return;
#ifdef F_6
if ( V_18 < 0 )
{
fprintf ( V_20 , L_2 ) ;
abort () ;
}
#endif
if ( V_15 -> V_7 != NULL ) F_7 ( V_15 -> V_7 ) ;
if ( V_15 -> V_8 != NULL ) F_7 ( V_15 -> V_8 ) ;
if ( V_15 -> V_9 != NULL ) F_7 ( V_15 -> V_9 ) ;
if ( V_15 -> V_12 != NULL ) F_7 ( V_15 -> V_12 ) ;
if ( V_15 -> V_13 != NULL ) F_7 ( V_15 -> V_13 ) ;
if ( V_15 -> V_14 != NULL ) F_7 ( V_15 -> V_14 ) ;
if ( V_15 -> V_15 != NULL ) F_7 ( V_15 -> V_15 ) ;
if ( V_15 -> V_16 != NULL )
F_8 ( ( V_21 * ) V_15 -> V_16 ) ;
Free ( V_15 ) ;
}
int F_9 ( T_1 * V_15 )
{
int V_1 , V_18 ;
T_2 V_22 ;
unsigned char V_23 [ 4 ] ;
V_18 = F_10 ( V_15 -> V_8 ) ;
V_22 . V_24 = ( V_18 + 7 ) / 8 ;
V_22 . V_25 = V_23 ;
V_22 . type = V_26 ;
V_23 [ 0 ] = 0xff ;
V_18 = F_11 ( & V_22 , NULL ) ;
V_18 += V_18 ;
V_1 = F_12 ( 1 , V_18 , V_27 ) ;
return ( V_1 ) ;
}
