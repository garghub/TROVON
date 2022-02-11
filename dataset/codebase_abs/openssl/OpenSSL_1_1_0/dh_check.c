int F_1 ( const T_1 * V_1 , int * V_2 )
{
int V_3 = 0 , V_4 ;
T_2 * V_5 = NULL ;
T_3 V_6 ;
T_4 * V_7 = NULL , * V_8 = NULL ;
* V_2 = 0 ;
V_5 = F_2 () ;
if ( V_5 == NULL )
goto V_9;
F_3 ( V_5 ) ;
V_7 = F_4 ( V_5 ) ;
if ( V_7 == NULL )
goto V_9;
V_8 = F_4 ( V_5 ) ;
if ( V_8 == NULL )
goto V_9;
if ( V_1 -> V_10 ) {
if ( F_5 ( V_1 -> V_11 , F_6 () ) <= 0 )
* V_2 |= V_12 ;
else if ( F_5 ( V_1 -> V_11 , V_1 -> V_13 ) >= 0 )
* V_2 |= V_12 ;
else {
if ( ! F_7 ( V_7 , V_1 -> V_11 , V_1 -> V_10 , V_1 -> V_13 , V_5 ) )
goto V_9;
if ( ! F_8 ( V_7 ) )
* V_2 |= V_12 ;
}
V_4 = F_9 ( V_1 -> V_10 , V_14 , V_5 , NULL ) ;
if ( V_4 < 0 )
goto V_9;
if ( ! V_4 )
* V_2 |= V_15 ;
if ( ! F_10 ( V_7 , V_8 , V_1 -> V_13 , V_1 -> V_10 , V_5 ) )
goto V_9;
if ( ! F_8 ( V_8 ) )
* V_2 |= V_16 ;
if ( V_1 -> V_17 && F_5 ( V_1 -> V_17 , V_7 ) )
* V_2 |= V_18 ;
} else if ( F_11 ( V_1 -> V_11 , V_19 ) ) {
V_6 = F_12 ( V_1 -> V_13 , 24 ) ;
if ( V_6 == ( T_3 ) - 1 )
goto V_9;
if ( V_6 != 11 )
* V_2 |= V_12 ;
} else if ( F_11 ( V_1 -> V_11 , V_20 ) ) {
V_6 = F_12 ( V_1 -> V_13 , 10 ) ;
if ( V_6 == ( T_3 ) - 1 )
goto V_9;
if ( ( V_6 != 3 ) && ( V_6 != 7 ) )
* V_2 |= V_12 ;
} else
* V_2 |= V_21 ;
V_4 = F_9 ( V_1 -> V_13 , V_14 , V_5 , NULL ) ;
if ( V_4 < 0 )
goto V_9;
if ( ! V_4 )
* V_2 |= V_22 ;
else if ( ! V_1 -> V_10 ) {
if ( ! F_13 ( V_7 , V_1 -> V_13 ) )
goto V_9;
V_4 = F_9 ( V_7 , V_14 , V_5 , NULL ) ;
if ( V_4 < 0 )
goto V_9;
if ( ! V_4 )
* V_2 |= V_23 ;
}
V_3 = 1 ;
V_9:
if ( V_5 != NULL ) {
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
}
return ( V_3 ) ;
}
int F_16 ( const T_1 * V_1 , const T_4 * V_24 , int * V_2 )
{
int V_3 = 0 ;
T_4 * V_25 = NULL ;
T_2 * V_5 = NULL ;
* V_2 = 0 ;
V_5 = F_2 () ;
if ( V_5 == NULL )
goto V_9;
F_3 ( V_5 ) ;
V_25 = F_4 ( V_5 ) ;
if ( V_25 == NULL || ! F_17 ( V_25 , 1 ) )
goto V_9;
if ( F_5 ( V_24 , V_25 ) <= 0 )
* V_2 |= V_26 ;
if ( F_18 ( V_25 , V_1 -> V_13 ) == NULL || ! F_19 ( V_25 , 1 ) )
goto V_9;
if ( F_5 ( V_24 , V_25 ) >= 0 )
* V_2 |= V_27 ;
if ( V_1 -> V_10 != NULL ) {
if ( ! F_7 ( V_25 , V_24 , V_1 -> V_10 , V_1 -> V_13 , V_5 ) )
goto V_9;
if ( ! F_8 ( V_25 ) )
* V_2 |= V_28 ;
}
V_3 = 1 ;
V_9:
if ( V_5 != NULL ) {
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
}
return ( V_3 ) ;
}
