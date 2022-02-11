T_1 * F_1 ( const T_1 * V_1 )
{
T_1 * V_2 ;
if ( V_1 == NULL )
return NULL ;
if ( ! ( V_1 -> V_3 & V_4 ) )
return ( ( T_1 * ) V_1 ) ;
V_2 = F_2 () ;
if ( V_2 == NULL ) {
F_3 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
V_2 -> V_3 = V_1 -> V_3 | ( V_4 |
V_7 |
V_8 ) ;
if ( V_1 -> V_9 > 0 && ( V_2 -> V_10 = F_4 ( V_1 -> V_10 , V_1 -> V_9 ) ) == NULL )
goto V_11;
V_2 -> V_9 = V_1 -> V_9 ;
V_2 -> V_12 = V_1 -> V_12 ;
if ( V_1 -> V_13 != NULL && ( V_2 -> V_13 = F_5 ( V_1 -> V_13 ) ) == NULL )
goto V_11;
if ( V_1 -> V_14 != NULL && ( V_2 -> V_14 = F_5 ( V_1 -> V_14 ) ) == NULL )
goto V_11;
return V_2 ;
V_11:
F_6 ( V_2 ) ;
F_3 ( V_5 , V_15 ) ;
return NULL ;
}
int F_7 ( const T_1 * V_16 , const T_1 * V_17 )
{
int V_18 ;
V_18 = ( V_16 -> V_9 - V_17 -> V_9 ) ;
if ( V_18 )
return ( V_18 ) ;
return ( memcmp ( V_16 -> V_10 , V_17 -> V_10 , V_16 -> V_9 ) ) ;
}
