int F_1 ( const T_1 * V_1 , int * V_2 )
{
int V_3 = 0 ;
T_2 * V_4 = NULL ;
T_3 V_5 ;
T_4 * V_6 = NULL ;
* V_2 = 0 ;
V_4 = F_2 () ;
if ( V_4 == NULL ) goto V_7;
V_6 = F_3 () ;
if ( V_6 == NULL ) goto V_7;
if ( F_4 ( V_1 -> V_8 , V_9 ) )
{
V_5 = F_5 ( V_1 -> V_10 , 24 ) ;
if ( V_5 != 11 ) * V_2 |= V_11 ;
}
#if 0
else if (BN_is_word(dh->g,DH_GENERATOR_3))
{
l=BN_mod_word(dh->p,12);
if (l != 5) *ret|=DH_NOT_SUITABLE_GENERATOR;
}
#endif
else if ( F_4 ( V_1 -> V_8 , V_12 ) )
{
V_5 = F_5 ( V_1 -> V_10 , 10 ) ;
if ( ( V_5 != 3 ) && ( V_5 != 7 ) )
* V_2 |= V_11 ;
}
else
* V_2 |= V_13 ;
if ( ! F_6 ( V_1 -> V_10 , V_14 , V_4 , NULL ) )
* V_2 |= V_15 ;
else
{
if ( ! F_7 ( V_6 , V_1 -> V_10 ) ) goto V_7;
if ( ! F_6 ( V_6 , V_14 , V_4 , NULL ) )
* V_2 |= V_16 ;
}
V_3 = 1 ;
V_7:
if ( V_4 != NULL ) F_8 ( V_4 ) ;
if ( V_6 != NULL ) F_9 ( V_6 ) ;
return ( V_3 ) ;
}
int F_10 ( const T_1 * V_1 , const T_4 * V_17 , int * V_2 )
{
int V_3 = 0 ;
T_4 * V_6 = NULL ;
* V_2 = 0 ;
V_6 = F_3 () ;
if ( V_6 == NULL ) goto V_7;
F_11 ( V_6 , 1 ) ;
if ( F_12 ( V_17 , V_6 ) <= 0 )
* V_2 |= V_18 ;
F_13 ( V_6 , V_1 -> V_10 ) ;
F_14 ( V_6 , 1 ) ;
if ( F_12 ( V_17 , V_6 ) >= 0 )
* V_2 |= V_19 ;
V_3 = 1 ;
V_7:
if ( V_6 != NULL ) F_9 ( V_6 ) ;
return ( V_3 ) ;
}
