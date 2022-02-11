int F_1 ( const unsigned char * V_1 , int V_2 , T_1 * V_3 ,
T_2 * V_4 )
{
T_3 * V_5 ;
T_4 V_6 , V_7 , V_8 ;
T_5 * V_9 = NULL ;
int V_10 = - 1 ;
if ( ( V_5 = F_2 () ) == NULL ) goto V_11;
F_3 ( & V_6 ) ;
F_3 ( & V_7 ) ;
F_3 ( & V_8 ) ;
if ( ( F_4 ( & V_7 , V_3 -> V_12 , V_4 -> V_13 , V_5 ) ) == NULL ) goto V_11;
if ( F_5 ( V_1 , V_2 , & V_6 ) == NULL ) goto V_11;
if ( ! F_6 ( & V_6 , & V_6 , & V_7 , V_4 -> V_13 , V_5 ) ) goto V_11;
if ( ! F_6 ( & V_7 , V_3 -> V_14 , & V_7 , V_4 -> V_13 , V_5 ) ) goto V_11;
if ( ( V_4 -> V_15 == NULL ) && ( V_4 -> V_16 & V_17 ) )
{
if ( ( V_4 -> V_15 = ( char * ) F_7 () ) != NULL )
if ( ! F_8 ( ( T_5 * ) V_4 -> V_15 ,
V_4 -> V_18 , V_5 ) ) goto V_11;
}
V_9 = ( T_5 * ) V_4 -> V_15 ;
#if 0
{
BIGNUM t2;
BN_init(&t2);
if (!BN_mod_exp_mont(&t1,dsa->g,&u1,dsa->p,ctx,mont)) goto err;
if (!BN_mod_exp_mont(&t2,dsa->pub_key,&u2,dsa->p,ctx,mont)) goto err;
if (!BN_mod_mul(&u1,&t1,&t2,dsa->p,ctx)) goto err_bn;
BN_free(&t2);
}
if (!BN_mod(&u1,&u1,dsa->q,ctx)) goto err;
#else
{
if ( ! F_9 ( & V_8 , V_4 -> V_19 , & V_6 , V_4 -> V_20 , & V_7 , V_4 -> V_18 , V_5 , V_9 ) )
goto V_11;
if ( ! F_10 ( & V_6 , & V_8 , V_4 -> V_13 , V_5 ) ) goto V_11;
}
#endif
V_10 = ( F_11 ( & V_6 , V_3 -> V_14 ) == 0 ) ;
V_11:
if ( V_10 != 1 ) F_12 ( V_21 , V_22 ) ;
if ( V_5 != NULL ) F_13 ( V_5 ) ;
F_14 ( & V_6 ) ;
F_14 ( & V_7 ) ;
F_14 ( & V_8 ) ;
return ( V_10 ) ;
}
int F_15 ( int type , const unsigned char * V_1 , int V_2 ,
unsigned char * V_23 , int V_24 , T_2 * V_4 )
{
T_1 * V_12 ;
int V_10 = - 1 ;
V_12 = F_16 () ;
if ( V_12 == NULL ) return ( V_10 ) ;
if ( F_17 ( & V_12 , & V_23 , V_24 ) == NULL ) goto V_11;
V_10 = F_1 ( V_1 , V_2 , V_12 , V_4 ) ;
V_11:
F_18 ( V_12 ) ;
return ( V_10 ) ;
}
