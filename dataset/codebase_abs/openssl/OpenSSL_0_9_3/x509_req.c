T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 )
{
T_1 * V_4 ;
T_5 * V_5 ;
int V_6 ;
T_3 * V_7 ;
V_4 = F_2 () ;
if ( V_4 == NULL )
{
F_3 ( V_8 , V_9 ) ;
goto V_10;
}
V_5 = V_4 -> V_11 ;
V_5 -> V_12 -> V_13 = 1 ;
V_5 -> V_12 -> V_14 = ( unsigned char * ) Malloc ( 1 ) ;
if ( V_5 -> V_12 -> V_14 == NULL ) goto V_10;
V_5 -> V_12 -> V_14 [ 0 ] = 0 ;
if ( ! F_4 ( V_4 , F_5 ( V_1 ) ) )
goto V_10;
V_7 = F_6 ( V_1 ) ;
V_6 = F_7 ( V_4 , V_7 ) ;
F_8 ( V_7 ) ;
if ( ! V_6 ) goto V_10;
if ( V_2 != NULL )
{
if ( ! F_9 ( V_4 , V_2 , V_3 ) )
goto V_10;
}
return ( V_4 ) ;
V_10:
F_10 ( V_4 ) ;
return ( NULL ) ;
}
T_3 * F_11 ( T_1 * V_15 )
{
if ( ( V_15 == NULL ) || ( V_15 -> V_11 == NULL ) )
return ( NULL ) ;
return ( F_12 ( V_15 -> V_11 -> V_16 ) ) ;
}
