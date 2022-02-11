int F_1 ( T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
if( V_1 -> V_5 -> V_6 )
return V_1 -> V_5 -> V_6 ( V_1 , V_2 , V_3 , V_4 ) ;
return F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_2 ( T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
T_3 * V_7 , * V_8 ;
int V_9 , V_10 = - 1 ;
T_4 * V_11 = NULL ;
V_11 = F_3 () ;
if ( V_11 == NULL ) goto V_12;
F_4 ( V_11 ) ;
V_7 = F_5 ( V_11 ) ;
V_8 = F_5 ( V_11 ) ;
if ( V_7 == NULL || V_8 == NULL ) goto V_12;
if( ! V_1 -> V_13 && ( ( V_1 -> V_13 = F_6 () ) == NULL ) ) goto V_12;
if( ! V_1 -> V_9 && ( ( V_1 -> V_9 = F_6 () ) == NULL ) ) goto V_12;
if ( V_3 <= 1 )
{
F_7 ( V_14 , V_15 ) ;
goto V_12;
}
if ( V_3 == V_16 )
{
if ( ! F_8 ( V_7 , 24 ) ) goto V_12;
if ( ! F_8 ( V_8 , 11 ) ) goto V_12;
V_9 = 2 ;
}
#if 0
else if (generator == DH_GENERATOR_3)
{
if (!BN_set_word(t1,12)) goto err;
if (!BN_set_word(t2,5)) goto err;
g=3;
}
#endif
else if ( V_3 == V_17 )
{
if ( ! F_8 ( V_7 , 10 ) ) goto V_12;
if ( ! F_8 ( V_8 , 3 ) ) goto V_12;
V_9 = 5 ;
}
else
{
if ( ! F_8 ( V_7 , 2 ) ) goto V_12;
if ( ! F_8 ( V_8 , 1 ) ) goto V_12;
V_9 = V_3 ;
}
if( ! F_9 ( V_1 -> V_13 , V_2 , 1 , V_7 , V_8 , V_4 ) ) goto V_12;
if( ! F_10 ( V_4 , 3 , 0 ) ) goto V_12;
if ( ! F_8 ( V_1 -> V_9 , V_9 ) ) goto V_12;
V_10 = 1 ;
V_12:
if ( V_10 == - 1 )
{
F_7 ( V_14 , V_18 ) ;
V_10 = 0 ;
}
if ( V_11 != NULL )
{
F_11 ( V_11 ) ;
F_12 ( V_11 ) ;
}
return V_10 ;
}
