int F_1 ( const T_1 * V_1 , int * V_2 )
{
int V_3 = 0 ;
T_2 * V_4 = NULL ;
T_3 V_5 ;
T_4 * V_6 = NULL , * V_7 = NULL ;
* V_2 = 0 ;
V_4 = F_2 () ;
if ( V_4 == NULL )
goto V_8;
F_3 ( V_4 ) ;
V_6 = F_4 ( V_4 ) ;
if ( V_6 == NULL )
goto V_8;
V_7 = F_4 ( V_4 ) ;
if ( V_7 == NULL )
goto V_8;
if ( V_1 -> V_9 ) {
if ( F_5 ( V_1 -> V_10 , F_6 () ) <= 0 )
* V_2 |= V_11 ;
else if ( F_5 ( V_1 -> V_10 , V_1 -> V_12 ) >= 0 )
* V_2 |= V_11 ;
else {
if ( ! F_7 ( V_6 , V_1 -> V_10 , V_1 -> V_9 , V_1 -> V_12 , V_4 ) )
goto V_8;
if ( ! F_8 ( V_6 ) )
* V_2 |= V_11 ;
}
if ( ! F_9 ( V_1 -> V_9 , V_13 , V_4 , NULL ) )
* V_2 |= V_14 ;
if ( ! F_10 ( V_6 , V_7 , V_1 -> V_12 , V_1 -> V_9 , V_4 ) )
goto V_8;
if ( ! F_8 ( V_7 ) )
* V_2 |= V_15 ;
if ( V_1 -> V_16 && F_5 ( V_1 -> V_16 , V_6 ) )
* V_2 |= V_17 ;
} else if ( F_11 ( V_1 -> V_10 , V_18 ) ) {
V_5 = F_12 ( V_1 -> V_12 , 24 ) ;
if ( V_5 != 11 )
* V_2 |= V_11 ;
}
#if 0
else if (BN_is_word(dh->g, DH_GENERATOR_3)) {
l = BN_mod_word(dh->p, 12);
if (l != 5)
*ret |= DH_NOT_SUITABLE_GENERATOR;
}
#endif
else if ( F_11 ( V_1 -> V_10 , V_19 ) ) {
V_5 = F_12 ( V_1 -> V_12 , 10 ) ;
if ( ( V_5 != 3 ) && ( V_5 != 7 ) )
* V_2 |= V_11 ;
} else
* V_2 |= V_20 ;
if ( ! F_9 ( V_1 -> V_12 , V_13 , V_4 , NULL ) )
* V_2 |= V_21 ;
else if ( ! V_1 -> V_9 ) {
if ( ! F_13 ( V_6 , V_1 -> V_12 ) )
goto V_8;
if ( ! F_9 ( V_6 , V_13 , V_4 , NULL ) )
* V_2 |= V_22 ;
}
V_3 = 1 ;
V_8:
if ( V_4 != NULL ) {
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
}
return ( V_3 ) ;
}
int F_16 ( const T_1 * V_1 , const T_4 * V_23 , int * V_2 )
{
int V_3 = 0 ;
T_4 * V_9 = NULL ;
* V_2 = 0 ;
V_9 = F_17 () ;
if ( V_9 == NULL )
goto V_8;
F_18 ( V_9 , 1 ) ;
if ( F_5 ( V_23 , V_9 ) <= 0 )
* V_2 |= V_24 ;
F_19 ( V_9 , V_1 -> V_12 ) ;
F_20 ( V_9 , 1 ) ;
if ( F_5 ( V_23 , V_9 ) >= 0 )
* V_2 |= V_25 ;
V_3 = 1 ;
V_8:
if ( V_9 != NULL )
F_21 ( V_9 ) ;
return ( V_3 ) ;
}
