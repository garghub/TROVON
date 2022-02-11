T_1 * F_1 ( T_1 * * V_1 , unsigned char * * V_2 , long V_3 )
{
int V_4 = V_5 ;
T_2 * V_6 = NULL ;
F_2 ( V_1 , T_1 * , V_7 ) ;
F_3 () ;
if ( ( V_3 != 0 ) && ( ( V_8 & ( ~ V_9 ) )
== ( V_10 | ( V_11 ) ) ) )
{
V_12 . V_13 = V_3 ;
F_4 ( V_6 , V_14 ) ;
if ( ( V_15 -> V_16 = F_5 ( V_6 -> V_17 , V_6 -> V_3 , V_15 -> V_16 ) )
== NULL )
goto V_18;
V_15 -> V_19 = 0 ;
}
else
{
F_6 () ;
F_4 ( V_6 , V_14 ) ;
if ( ( V_15 -> V_16 = F_5 ( V_6 -> V_17 , V_6 -> V_3 , V_15 -> V_16 ) )
== NULL )
goto V_18;
F_4 ( V_6 , V_14 ) ;
if ( ( V_15 -> V_20 = F_5 ( V_6 -> V_17 , V_6 -> V_3 , V_15 -> V_20 ) ) == NULL )
goto V_18;
F_4 ( V_6 , V_14 ) ;
if ( ( V_15 -> V_21 = F_5 ( V_6 -> V_17 , V_6 -> V_3 , V_15 -> V_21 ) ) == NULL )
goto V_18;
F_4 ( V_6 , V_14 ) ;
if ( ( V_15 -> V_22 = F_5 ( V_6 -> V_17 , V_6 -> V_3 , V_15 -> V_22 ) ) == NULL )
goto V_18;
V_15 -> V_19 = 1 ;
}
F_7 ( V_6 ) ;
V_6 = NULL ;
F_8 ( V_1 ) ;
V_18:
V_4 = V_23 ;
V_24:
F_9 ( V_25 , V_4 ) ;
if ( ( V_15 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_15 ) ) ) F_10 ( V_15 ) ;
if ( V_6 != NULL ) F_7 ( V_6 ) ;
return ( NULL ) ;
}
