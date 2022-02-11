T_1 * F_1 ( void )
{
return & V_1 ;
}
static T_2 * F_2 ( const unsigned char * V_2 , int V_3 , T_3 * V_4 )
{
T_4 * V_5 = NULL , * V_6 = NULL , * V_7 = NULL ;
T_4 V_8 ;
T_4 V_9 ;
T_5 * V_10 = NULL ;
int V_11 , V_12 = V_13 ;
T_2 * V_14 = NULL ;
F_3 ( & V_8 ) ;
F_3 ( & V_9 ) ;
V_7 = F_4 () ;
if ( V_7 == NULL ) goto V_15;
V_11 = F_5 ( V_4 -> V_16 ) ;
if ( ( V_3 > V_11 ) || ( V_3 > 50 ) )
{
V_12 = V_17 ;
goto V_15;
}
V_10 = F_6 () ;
if ( V_10 == NULL ) goto V_15;
if ( ( V_4 -> V_5 == NULL ) || ( V_4 -> V_6 == NULL ) )
{
if ( ! F_7 ( V_4 , V_10 , & V_5 , & V_6 ) ) goto V_15;
}
else
{
V_5 = V_4 -> V_5 ;
V_4 -> V_5 = NULL ;
V_6 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
}
if ( F_8 ( V_2 , V_3 , & V_8 ) == NULL ) goto V_15;
if ( ! F_9 ( & V_9 , V_4 -> V_18 , V_6 , V_4 -> V_16 , V_10 ) ) goto V_15;
if ( ! F_10 ( V_7 , & V_9 , & V_8 ) ) goto V_15;
if ( F_11 ( V_7 , V_4 -> V_16 ) > 0 )
F_12 ( V_7 , V_7 , V_4 -> V_16 ) ;
if ( ! F_9 ( V_7 , V_7 , V_5 , V_4 -> V_16 , V_10 ) ) goto V_15;
V_14 = F_13 () ;
if ( V_14 == NULL ) goto V_15;
V_14 -> V_6 = V_6 ;
V_14 -> V_7 = V_7 ;
V_15:
if ( ! V_14 )
{
F_14 ( V_19 , V_12 ) ;
F_15 ( V_6 ) ;
F_15 ( V_7 ) ;
}
if ( V_10 != NULL ) F_16 ( V_10 ) ;
F_17 ( & V_8 ) ;
F_17 ( & V_9 ) ;
if ( V_5 != NULL )
F_17 ( V_5 ) ;
return ( V_14 ) ;
}
static int F_18 ( T_3 * V_4 , T_5 * V_20 , T_4 * * V_21 , T_4 * * V_22 )
{
T_5 * V_10 ;
T_4 V_23 , * V_5 = NULL , * V_6 = NULL ;
int V_14 = 0 ;
if ( V_20 == NULL )
{
if ( ( V_10 = F_6 () ) == NULL ) goto V_15;
}
else
V_10 = V_20 ;
F_3 ( & V_23 ) ;
if ( ( V_6 = F_4 () ) == NULL ) goto V_15;
V_5 = NULL ;
for (; ; )
{
if ( ! F_19 ( & V_23 , F_20 ( V_4 -> V_16 ) , 1 , 0 ) ) goto V_15;
if ( F_11 ( & V_23 , V_4 -> V_16 ) >= 0 )
F_12 ( & V_23 , & V_23 , V_4 -> V_16 ) ;
if ( ! F_21 ( & V_23 ) ) break;
}
if ( ( V_4 -> V_24 == NULL ) && ( V_4 -> V_25 & V_26 ) )
{
if ( ( V_4 -> V_24 = ( char * ) F_22 () ) != NULL )
if ( ! F_23 ( ( V_27 * ) V_4 -> V_24 ,
V_4 -> V_28 , V_10 ) ) goto V_15;
}
if ( ! V_4 -> V_29 -> V_30 ( V_4 , V_6 , V_4 -> V_31 , & V_23 , V_4 -> V_28 , V_10 ,
( V_27 * ) V_4 -> V_24 ) ) goto V_15;
if ( ! F_24 ( V_6 , V_6 , V_4 -> V_16 , V_10 ) ) goto V_15;
if ( ( V_5 = F_25 ( NULL , & V_23 , V_4 -> V_16 , V_10 ) ) == NULL ) goto V_15;
if ( * V_21 != NULL ) F_17 ( * V_21 ) ;
* V_21 = V_5 ;
V_5 = NULL ;
if ( * V_22 != NULL ) F_17 ( * V_22 ) ;
* V_22 = V_6 ;
V_14 = 1 ;
V_15:
if ( ! V_14 )
{
F_14 ( V_32 , V_13 ) ;
if ( V_5 != NULL ) F_17 ( V_5 ) ;
if ( V_6 != NULL ) F_17 ( V_6 ) ;
}
if ( V_20 == NULL ) F_16 ( V_10 ) ;
if ( V_5 != NULL ) F_17 ( V_5 ) ;
F_17 ( & V_23 ) ;
return ( V_14 ) ;
}
static int F_26 ( const unsigned char * V_2 , int V_33 , T_2 * V_34 ,
T_3 * V_4 )
{
T_5 * V_10 ;
T_4 V_35 , V_36 , V_37 ;
V_27 * V_38 = NULL ;
int V_14 = - 1 ;
if ( ( V_10 = F_6 () ) == NULL ) goto V_15;
F_3 ( & V_35 ) ;
F_3 ( & V_36 ) ;
F_3 ( & V_37 ) ;
if ( ( F_25 ( & V_36 , V_34 -> V_7 , V_4 -> V_16 , V_10 ) ) == NULL ) goto V_15;
if ( F_8 ( V_2 , V_33 , & V_35 ) == NULL ) goto V_15;
if ( ! F_9 ( & V_35 , & V_35 , & V_36 , V_4 -> V_16 , V_10 ) ) goto V_15;
if ( ! F_9 ( & V_36 , V_34 -> V_6 , & V_36 , V_4 -> V_16 , V_10 ) ) goto V_15;
if ( ( V_4 -> V_24 == NULL ) && ( V_4 -> V_25 & V_26 ) )
{
if ( ( V_4 -> V_24 = ( char * ) F_22 () ) != NULL )
if ( ! F_23 ( ( V_27 * ) V_4 -> V_24 ,
V_4 -> V_28 , V_10 ) ) goto V_15;
}
V_38 = ( V_27 * ) V_4 -> V_24 ;
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
if ( ! V_4 -> V_29 -> V_39 ( V_4 , & V_37 , V_4 -> V_31 , & V_35 , V_4 -> V_40 , & V_36 ,
V_4 -> V_28 , V_10 , V_38 ) ) goto V_15;
if ( ! F_24 ( & V_35 , & V_37 , V_4 -> V_16 , V_10 ) ) goto V_15;
}
#endif
V_14 = ( F_27 ( & V_35 , V_34 -> V_6 ) == 0 ) ;
V_15:
if ( V_14 != 1 ) F_14 ( V_41 , V_13 ) ;
if ( V_10 != NULL ) F_16 ( V_10 ) ;
F_15 ( & V_35 ) ;
F_15 ( & V_36 ) ;
F_15 ( & V_37 ) ;
return ( V_14 ) ;
}
static int F_28 ( T_3 * V_4 )
{
V_4 -> V_25 |= V_26 ;
return ( 1 ) ;
}
static int F_29 ( T_3 * V_4 )
{
if( V_4 -> V_24 )
F_30 ( ( V_27 * ) V_4 -> V_24 ) ;
return ( 1 ) ;
}
static int V_39 ( T_3 * V_4 , T_4 * V_42 , T_4 * V_43 , T_4 * V_44 ,
T_4 * V_45 , T_4 * V_46 , T_4 * V_8 , T_5 * V_10 ,
V_27 * V_47 )
{
return F_31 ( V_42 , V_43 , V_44 , V_45 , V_46 , V_8 , V_10 , V_47 ) ;
}
static int F_32 ( T_3 * V_4 , T_4 * V_6 , T_4 * V_48 , const T_4 * V_28 ,
const T_4 * V_8 , T_5 * V_10 ,
V_27 * V_49 )
{
return F_33 ( V_6 , V_48 , V_28 , V_8 , V_10 , V_49 ) ;
}
