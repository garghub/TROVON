T_1 * F_1 ( T_2 * V_1 , T_2 * V_2 , T_2 * V_3 )
{
T_1 * V_4 = NULL ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( ( V_4 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ) == NULL )
{
F_3 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
memset ( V_4 , 0 , sizeof( T_1 ) ) ;
if ( ( V_4 -> V_1 = F_4 () ) == NULL ) goto V_7;
if ( ( V_4 -> V_2 = F_4 () ) == NULL ) goto V_7;
if ( ! F_5 ( V_4 -> V_1 , V_1 ) ) goto V_7;
if ( ! F_5 ( V_4 -> V_2 , V_2 ) ) goto V_7;
V_4 -> V_3 = V_3 ;
return ( V_4 ) ;
V_7:
if ( V_4 != NULL ) F_6 ( V_4 ) ;
return ( NULL ) ;
}
void F_6 ( T_1 * V_8 )
{
if( V_8 == NULL )
return;
if ( V_8 -> V_1 != NULL ) F_7 ( V_8 -> V_1 ) ;
if ( V_8 -> V_2 != NULL ) F_7 ( V_8 -> V_2 ) ;
Free ( V_8 ) ;
}
int F_8 ( T_1 * V_9 , T_3 * V_10 )
{
int V_4 = 0 ;
if ( ( V_9 -> V_1 == NULL ) || ( V_9 -> V_2 == NULL ) )
{
F_3 ( V_11 , V_12 ) ;
goto V_7;
}
if ( ! F_9 ( V_9 -> V_1 , V_9 -> V_1 , V_9 -> V_1 , V_9 -> V_3 , V_10 ) ) goto V_7;
if ( ! F_9 ( V_9 -> V_2 , V_9 -> V_2 , V_9 -> V_2 , V_9 -> V_3 , V_10 ) ) goto V_7;
V_4 = 1 ;
V_7:
return ( V_4 ) ;
}
int F_10 ( T_2 * V_13 , T_1 * V_9 , T_3 * V_10 )
{
F_2 ( V_13 ) ;
if ( ( V_9 -> V_1 == NULL ) || ( V_9 -> V_2 == NULL ) )
{
F_3 ( V_14 , V_12 ) ;
return ( 0 ) ;
}
return ( F_9 ( V_13 , V_13 , V_9 -> V_1 , V_9 -> V_3 , V_10 ) ) ;
}
int F_11 ( T_2 * V_13 , T_1 * V_9 , T_3 * V_10 )
{
int V_4 ;
F_2 ( V_13 ) ;
if ( ( V_9 -> V_1 == NULL ) || ( V_9 -> V_2 == NULL ) )
{
F_3 ( V_15 , V_12 ) ;
return ( 0 ) ;
}
if ( ( V_4 = F_9 ( V_13 , V_13 , V_9 -> V_2 , V_9 -> V_3 , V_10 ) ) >= 0 )
{
if ( ! F_8 ( V_9 , V_10 ) )
return ( 0 ) ;
}
return ( V_4 ) ;
}
