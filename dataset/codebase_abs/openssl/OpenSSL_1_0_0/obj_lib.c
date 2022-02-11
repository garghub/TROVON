T_1 * F_1 ( const T_1 * V_1 )
{
T_1 * V_2 ;
int V_3 ;
char * V_4 = NULL , * V_5 = NULL ;
unsigned char * V_6 = NULL ;
if ( V_1 == NULL ) return ( NULL ) ;
if ( ! ( V_1 -> V_7 & V_8 ) )
return ( ( T_1 * ) V_1 ) ;
V_2 = F_2 () ;
if ( V_2 == NULL )
{
F_3 ( V_9 , V_10 ) ;
return ( NULL ) ;
}
V_6 = F_4 ( V_1 -> V_11 ) ;
if ( V_6 == NULL )
goto V_12;
if ( V_1 -> V_6 != NULL )
memcpy ( V_6 , V_1 -> V_6 , V_1 -> V_11 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = V_1 -> V_11 ;
V_2 -> V_13 = V_1 -> V_13 ;
V_2 -> V_4 = V_2 -> V_5 = NULL ;
if ( V_1 -> V_4 != NULL )
{
V_3 = strlen ( V_1 -> V_4 ) + 1 ;
V_4 = F_4 ( V_3 ) ;
if ( V_4 == NULL ) goto V_12;
memcpy ( V_4 , V_1 -> V_4 , V_3 ) ;
V_2 -> V_4 = V_4 ;
}
if ( V_1 -> V_5 != NULL )
{
V_3 = strlen ( V_1 -> V_5 ) + 1 ;
V_5 = F_4 ( V_3 ) ;
if ( V_5 == NULL ) goto V_12;
memcpy ( V_5 , V_1 -> V_5 , V_3 ) ;
V_2 -> V_5 = V_5 ;
}
V_2 -> V_7 = V_1 -> V_7 | ( V_8 |
V_14 | V_15 ) ;
return ( V_2 ) ;
V_12:
F_3 ( V_9 , V_16 ) ;
if ( V_4 != NULL ) F_5 ( V_4 ) ;
if ( V_5 != NULL ) F_5 ( V_5 ) ;
if ( V_6 != NULL ) F_5 ( V_6 ) ;
if ( V_2 != NULL ) F_5 ( V_2 ) ;
return ( NULL ) ;
}
int F_6 ( const T_1 * V_17 , const T_1 * V_18 )
{
int V_19 ;
V_19 = ( V_17 -> V_11 - V_18 -> V_11 ) ;
if ( V_19 ) return ( V_19 ) ;
return ( memcmp ( V_17 -> V_6 , V_18 -> V_6 , V_17 -> V_11 ) ) ;
}
