T_1 * F_1 ( const T_1 * V_1 )
{
T_1 * V_2 ;
int V_3 ;
char * V_4 = NULL ;
if ( V_1 == NULL ) return ( NULL ) ;
if ( ! ( V_1 -> V_5 & V_6 ) )
return ( ( T_1 * ) V_1 ) ;
V_2 = F_2 () ;
if ( V_2 == NULL )
{
F_3 ( V_7 , V_8 ) ;
return ( NULL ) ;
}
V_2 -> V_9 = F_4 ( V_1 -> V_10 ) ;
if ( V_2 -> V_9 == NULL )
goto V_11;
memcpy ( V_2 -> V_9 , V_1 -> V_9 , V_1 -> V_10 ) ;
V_2 -> V_10 = V_1 -> V_10 ;
V_2 -> V_12 = V_1 -> V_12 ;
V_2 -> V_4 = V_2 -> V_13 = NULL ;
if ( V_1 -> V_4 != NULL )
{
V_3 = strlen ( V_1 -> V_4 ) + 1 ;
V_2 -> V_4 = V_4 = F_4 ( V_3 ) ;
if ( V_2 -> V_4 == NULL ) goto V_11;
memcpy ( V_4 , V_1 -> V_4 , V_3 ) ;
}
if ( V_1 -> V_13 != NULL )
{
char * V_14 ;
V_3 = strlen ( V_1 -> V_13 ) + 1 ;
V_2 -> V_13 = V_14 = F_4 ( V_3 ) ;
if ( V_2 -> V_13 == NULL ) goto V_11;
memcpy ( V_14 , V_1 -> V_13 , V_3 ) ;
}
V_2 -> V_5 = V_1 -> V_5 | ( V_6 |
V_15 | V_16 ) ;
return ( V_2 ) ;
V_11:
F_3 ( V_7 , V_17 ) ;
if ( V_2 != NULL )
{
if ( V_4 != NULL ) F_5 ( V_4 ) ;
if ( V_2 -> V_9 != NULL ) F_5 ( V_2 -> V_9 ) ;
F_5 ( V_2 ) ;
}
return ( NULL ) ;
}
int F_6 ( const T_1 * V_18 , const T_1 * V_19 )
{
int V_20 ;
V_20 = ( V_18 -> V_10 - V_19 -> V_10 ) ;
if ( V_20 ) return ( V_20 ) ;
return ( memcmp ( V_18 -> V_9 , V_19 -> V_9 , V_18 -> V_10 ) ) ;
}
