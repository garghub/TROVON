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
V_1 -> V_6 = NULL ;
V_1 -> V_7 = NULL ;
V_1 -> V_8 = 0 ;
V_1 -> V_9 = NULL ;
V_1 -> V_10 = NULL ;
V_1 -> V_11 = V_12 ;
V_1 -> V_13 = NULL ;
return ( V_1 ) ;
}
void F_3 ( T_1 * V_14 )
{
if( V_14 == NULL ) return;
if ( V_14 -> V_6 != NULL ) F_4 ( V_14 -> V_6 ) ;
if ( V_14 -> V_7 != NULL ) F_4 ( V_14 -> V_7 ) ;
if ( V_14 -> V_9 != NULL ) F_4 ( V_14 -> V_9 ) ;
if ( V_14 -> V_10 != NULL ) F_4 ( V_14 -> V_10 ) ;
if ( V_14 -> V_13 != NULL )
F_5 ( ( V_15 * ) V_14 -> V_13 ) ;
Free ( V_14 ) ;
}
int F_6 ( T_1 * V_16 )
{
return ( F_7 ( V_16 -> V_6 ) ) ;
}
