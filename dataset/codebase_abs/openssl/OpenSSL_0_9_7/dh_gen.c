T_1 * F_1 ( int V_1 , int V_2 ,
void (* F_2)( int , int , void * ) , void * V_3 )
{
T_2 * V_4 = NULL , * V_5 , * V_6 ;
T_1 * V_7 = NULL ;
int V_8 , V_9 = - 1 ;
T_3 * V_10 = NULL ;
V_7 = F_3 () ;
if ( V_7 == NULL ) goto V_11;
V_10 = F_4 () ;
if ( V_10 == NULL ) goto V_11;
F_5 ( V_10 ) ;
V_5 = F_6 ( V_10 ) ;
V_6 = F_6 ( V_10 ) ;
if ( V_5 == NULL || V_6 == NULL ) goto V_11;
if ( V_2 <= 1 )
{
F_7 ( V_12 , V_13 ) ;
goto V_11;
}
if ( V_2 == V_14 )
{
if ( ! F_8 ( V_5 , 24 ) ) goto V_11;
if ( ! F_8 ( V_6 , 11 ) ) goto V_11;
V_8 = 2 ;
}
#if 0
else if (generator == DH_GENERATOR_3)
{
if (!BN_set_word(t1,12)) goto err;
if (!BN_set_word(t2,5)) goto err;
g=3;
}
#endif
else if ( V_2 == V_15 )
{
if ( ! F_8 ( V_5 , 10 ) ) goto V_11;
if ( ! F_8 ( V_6 , 3 ) ) goto V_11;
V_8 = 5 ;
}
else
{
if ( ! F_8 ( V_5 , 2 ) ) goto V_11;
if ( ! F_8 ( V_6 , 1 ) ) goto V_11;
V_8 = V_2 ;
}
V_4 = F_9 ( NULL , V_1 , 1 , V_5 , V_6 , F_2 , V_3 ) ;
if ( V_4 == NULL ) goto V_11;
if ( F_2 != NULL ) F_2 ( 3 , 0 , V_3 ) ;
V_7 -> V_4 = V_4 ;
V_7 -> V_8 = F_10 () ;
if ( ! F_8 ( V_7 -> V_8 , V_8 ) ) goto V_11;
V_9 = 1 ;
V_11:
if ( V_9 == - 1 )
{
F_7 ( V_12 , V_16 ) ;
V_9 = 0 ;
}
if ( V_10 != NULL )
{
F_11 ( V_10 ) ;
F_12 ( V_10 ) ;
}
if ( ! V_9 && ( V_7 != NULL ) )
{
F_13 ( V_7 ) ;
V_7 = NULL ;
}
return ( V_7 ) ;
}
