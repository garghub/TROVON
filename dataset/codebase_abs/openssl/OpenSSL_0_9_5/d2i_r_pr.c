T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_2 * F_2 ( T_2 * * V_2 , unsigned char * * V_3 , long V_4 )
{
int V_5 = V_6 ;
T_3 * V_7 = NULL ;
F_3 ( V_2 , T_2 * , V_8 ) ;
F_4 () ;
F_5 () ;
F_6 ( V_7 , V_9 ) ;
if ( V_7 -> V_4 == 0 )
V_10 -> V_11 = 0 ;
else V_10 -> V_11 = V_7 -> V_12 [ 0 ] ;
F_6 ( V_7 , V_9 ) ;
if ( ( V_10 -> V_13 = F_7 ( V_7 -> V_12 , V_7 -> V_4 , V_10 -> V_13 ) ) == NULL ) goto V_14;
F_6 ( V_7 , V_9 ) ;
if ( ( V_10 -> V_15 = F_7 ( V_7 -> V_12 , V_7 -> V_4 , V_10 -> V_15 ) ) == NULL ) goto V_14;
F_6 ( V_7 , V_9 ) ;
if ( ( V_10 -> V_16 = F_7 ( V_7 -> V_12 , V_7 -> V_4 , V_10 -> V_16 ) ) == NULL ) goto V_14;
F_6 ( V_7 , V_9 ) ;
if ( ( V_10 -> V_17 = F_7 ( V_7 -> V_12 , V_7 -> V_4 , V_10 -> V_17 ) ) == NULL ) goto V_14;
F_6 ( V_7 , V_9 ) ;
if ( ( V_10 -> V_18 = F_7 ( V_7 -> V_12 , V_7 -> V_4 , V_10 -> V_18 ) ) == NULL ) goto V_14;
F_6 ( V_7 , V_9 ) ;
if ( ( V_10 -> V_19 = F_7 ( V_7 -> V_12 , V_7 -> V_4 , V_10 -> V_19 ) ) == NULL )
goto V_14;
F_6 ( V_7 , V_9 ) ;
if ( ( V_10 -> V_20 = F_7 ( V_7 -> V_12 , V_7 -> V_4 , V_10 -> V_20 ) ) == NULL )
goto V_14;
F_6 ( V_7 , V_9 ) ;
if ( ( V_10 -> V_21 = F_7 ( V_7 -> V_12 , V_7 -> V_4 , V_10 -> V_21 ) ) == NULL )
goto V_14;
F_8 ( V_7 ) ;
F_9 ( V_2 ) ;
V_14:
V_5 = V_22 ;
V_23:
F_10 ( V_24 , V_5 ) ;
if ( ( V_10 != NULL ) && ( ( V_2 == NULL ) || ( * V_2 != V_10 ) ) ) F_11 ( V_10 ) ;
if ( V_7 != NULL ) F_8 ( V_7 ) ;
return ( NULL ) ;
}
