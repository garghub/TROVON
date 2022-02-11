T_1 * F_1 ( T_1 * * V_1 , unsigned char * * V_2 , long V_3 )
{
int V_4 = V_5 ;
T_2 * V_6 = NULL ;
F_2 ( V_1 , T_1 * , V_7 ) ;
F_3 () ;
F_4 () ;
F_5 ( V_6 , V_8 ) ;
if ( V_6 -> V_3 == 0 )
V_9 -> V_10 = 0 ;
else V_9 -> V_10 = V_6 -> V_11 [ 0 ] ;
F_5 ( V_6 , V_8 ) ;
if ( ( V_9 -> V_12 = F_6 ( V_6 -> V_11 , V_6 -> V_3 , V_9 -> V_12 ) ) == NULL ) goto V_13;
F_5 ( V_6 , V_8 ) ;
if ( ( V_9 -> V_14 = F_6 ( V_6 -> V_11 , V_6 -> V_3 , V_9 -> V_14 ) ) == NULL ) goto V_13;
F_5 ( V_6 , V_8 ) ;
if ( ( V_9 -> V_15 = F_6 ( V_6 -> V_11 , V_6 -> V_3 , V_9 -> V_15 ) ) == NULL ) goto V_13;
F_5 ( V_6 , V_8 ) ;
if ( ( V_9 -> V_16 = F_6 ( V_6 -> V_11 , V_6 -> V_3 , V_9 -> V_16 ) )
== NULL ) goto V_13;
F_5 ( V_6 , V_8 ) ;
if ( ( V_9 -> V_17 = F_6 ( V_6 -> V_11 , V_6 -> V_3 , V_9 -> V_17 ) )
== NULL ) goto V_13;
F_7 ( V_6 ) ;
F_8 ( V_1 ) ;
V_13:
V_4 = V_18 ;
V_19:
F_9 ( V_20 , V_4 ) ;
if ( ( V_9 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_9 ) ) ) F_10 ( V_9 ) ;
if ( V_6 != NULL ) F_7 ( V_6 ) ;
return ( NULL ) ;
}
