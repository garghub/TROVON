int F_1 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
#ifdef F_2
if ( F_3 () && ! ( V_1 -> V_5 -> V_6 & V_7 )
&& ! ( V_1 -> V_6 & V_8 ) ) {
F_4 ( V_9 , V_10 ) ;
return 0 ;
}
#endif
if ( V_1 -> V_5 -> V_11 )
return V_1 -> V_5 -> V_11 ( V_1 , V_2 , V_3 , V_4 ) ;
#ifdef F_2
if ( F_3 () )
return F_5 ( V_1 , V_2 , V_3 , V_4 ) ;
#endif
return F_6 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_6 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 * V_12 , * V_13 ;
int V_14 , V_15 = - 1 ;
T_4 * V_16 = NULL ;
V_16 = F_7 () ;
if ( V_16 == NULL )
goto V_17;
F_8 ( V_16 ) ;
V_12 = F_9 ( V_16 ) ;
V_13 = F_9 ( V_16 ) ;
if ( V_12 == NULL || V_13 == NULL )
goto V_17;
if ( ! V_1 -> V_18 && ( ( V_1 -> V_18 = F_10 () ) == NULL ) )
goto V_17;
if ( ! V_1 -> V_14 && ( ( V_1 -> V_14 = F_10 () ) == NULL ) )
goto V_17;
if ( V_3 <= 1 ) {
F_4 ( V_19 , V_20 ) ;
goto V_17;
}
if ( V_3 == V_21 ) {
if ( ! F_11 ( V_12 , 24 ) )
goto V_17;
if ( ! F_11 ( V_13 , 11 ) )
goto V_17;
V_14 = 2 ;
}
#if 0
else if (generator == DH_GENERATOR_3) {
if (!BN_set_word(t1, 12))
goto err;
if (!BN_set_word(t2, 5))
goto err;
g = 3;
}
#endif
else if ( V_3 == V_22 ) {
if ( ! F_11 ( V_12 , 10 ) )
goto V_17;
if ( ! F_11 ( V_13 , 3 ) )
goto V_17;
V_14 = 5 ;
} else {
if ( ! F_11 ( V_12 , 2 ) )
goto V_17;
if ( ! F_11 ( V_13 , 1 ) )
goto V_17;
V_14 = V_3 ;
}
if ( ! F_12 ( V_1 -> V_18 , V_2 , 1 , V_12 , V_13 , V_4 ) )
goto V_17;
if ( ! F_13 ( V_4 , 3 , 0 ) )
goto V_17;
if ( ! F_11 ( V_1 -> V_14 , V_14 ) )
goto V_17;
V_15 = 1 ;
V_17:
if ( V_15 == - 1 ) {
F_4 ( V_19 , V_23 ) ;
V_15 = 0 ;
}
if ( V_16 != NULL ) {
F_14 ( V_16 ) ;
F_15 ( V_16 ) ;
}
return V_15 ;
}
