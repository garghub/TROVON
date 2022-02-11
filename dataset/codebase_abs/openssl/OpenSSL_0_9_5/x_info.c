T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
V_1 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
{
F_2 ( V_2 , V_3 ) ;
return ( NULL ) ;
}
V_1 -> V_4 . V_5 = NULL ;
V_1 -> V_6 = 0 ;
V_1 -> V_7 = NULL ;
V_1 -> V_8 = 1 ;
V_1 -> V_9 = NULL ;
V_1 -> V_10 = NULL ;
V_1 -> V_11 = NULL ;
return ( V_1 ) ;
}
void F_3 ( T_1 * V_12 )
{
int V_13 ;
if ( V_12 == NULL ) return;
V_13 = F_4 ( & V_12 -> V_8 , - 1 , V_14 ) ;
#ifdef F_5
F_5 ( L_1 , V_12 ) ;
#endif
if ( V_13 > 0 ) return;
#ifdef F_6
if ( V_13 < 0 )
{
fprintf ( V_15 , L_2 ) ;
abort () ;
}
#endif
if ( V_12 -> V_9 != NULL ) F_7 ( V_12 -> V_9 ) ;
if ( V_12 -> V_10 != NULL ) F_8 ( V_12 -> V_10 ) ;
if ( V_12 -> V_11 != NULL ) F_9 ( V_12 -> V_11 ) ;
if ( V_12 -> V_7 != NULL ) Free ( V_12 -> V_7 ) ;
Free ( V_12 ) ;
}
