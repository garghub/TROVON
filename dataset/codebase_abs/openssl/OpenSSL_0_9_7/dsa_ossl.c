const T_1 * F_1 ( void )
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
if ( ! V_4 -> V_15 || ! V_4 -> V_16 || ! V_4 -> V_17 )
{
V_12 = V_18 ;
goto V_19;
}
F_3 ( & V_8 ) ;
F_3 ( & V_9 ) ;
V_7 = F_4 () ;
if ( V_7 == NULL ) goto V_19;
V_11 = F_5 ( V_4 -> V_16 ) ;
if ( ( V_3 > V_11 ) || ( V_3 > 50 ) )
{
V_12 = V_20 ;
goto V_19;
}
V_10 = F_6 () ;
if ( V_10 == NULL ) goto V_19;
if ( ( V_4 -> V_5 == NULL ) || ( V_4 -> V_6 == NULL ) )
{
if ( ! F_7 ( V_4 , V_10 , & V_5 , & V_6 ) ) goto V_19;
}
else
{
V_5 = V_4 -> V_5 ;
V_4 -> V_5 = NULL ;
V_6 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
}
if ( F_8 ( V_2 , V_3 , & V_8 ) == NULL ) goto V_19;
if ( ! F_9 ( & V_9 , V_4 -> V_21 , V_6 , V_4 -> V_16 , V_10 ) ) goto V_19;
if ( ! F_10 ( V_7 , & V_9 , & V_8 ) ) goto V_19;
if ( F_11 ( V_7 , V_4 -> V_16 ) > 0 )
F_12 ( V_7 , V_7 , V_4 -> V_16 ) ;
if ( ! F_9 ( V_7 , V_7 , V_5 , V_4 -> V_16 , V_10 ) ) goto V_19;
V_14 = F_13 () ;
if ( V_14 == NULL ) goto V_19;
V_14 -> V_6 = V_6 ;
V_14 -> V_7 = V_7 ;
V_19:
if ( ! V_14 )
{
F_14 ( V_22 , V_12 ) ;
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
static int F_18 ( T_3 * V_4 , T_5 * V_23 , T_4 * * V_24 , T_4 * * V_25 )
{
T_5 * V_10 ;
T_4 V_26 , * V_5 = NULL , * V_6 = NULL ;
int V_14 = 0 ;
if ( ! V_4 -> V_15 || ! V_4 -> V_16 || ! V_4 -> V_17 )
{
F_14 ( V_27 , V_18 ) ;
return 0 ;
}
if ( V_23 == NULL )
{
if ( ( V_10 = F_6 () ) == NULL ) goto V_19;
}
else
V_10 = V_23 ;
F_3 ( & V_26 ) ;
if ( ( V_6 = F_4 () ) == NULL ) goto V_19;
V_5 = NULL ;
do
if ( ! F_19 ( & V_26 , V_4 -> V_16 ) ) goto V_19;
while ( F_20 ( & V_26 ) );
if ( ( V_4 -> V_28 == NULL ) && ( V_4 -> V_29 & V_30 ) )
{
if ( ( V_4 -> V_28 = ( char * ) F_21 () ) != NULL )
if ( ! F_22 ( ( V_31 * ) V_4 -> V_28 ,
V_4 -> V_15 , V_10 ) ) goto V_19;
}
if ( ! V_4 -> V_32 -> V_33 ( V_4 , V_6 , V_4 -> V_17 , & V_26 , V_4 -> V_15 , V_10 ,
( V_31 * ) V_4 -> V_28 ) ) goto V_19;
if ( ! F_23 ( V_6 , V_6 , V_4 -> V_16 , V_10 ) ) goto V_19;
if ( ( V_5 = F_24 ( NULL , & V_26 , V_4 -> V_16 , V_10 ) ) == NULL ) goto V_19;
if ( * V_24 != NULL ) F_17 ( * V_24 ) ;
* V_24 = V_5 ;
V_5 = NULL ;
if ( * V_25 != NULL ) F_17 ( * V_25 ) ;
* V_25 = V_6 ;
V_14 = 1 ;
V_19:
if ( ! V_14 )
{
F_14 ( V_27 , V_13 ) ;
if ( V_5 != NULL ) F_17 ( V_5 ) ;
if ( V_6 != NULL ) F_17 ( V_6 ) ;
}
if ( V_23 == NULL ) F_16 ( V_10 ) ;
if ( V_5 != NULL ) F_17 ( V_5 ) ;
F_17 ( & V_26 ) ;
return ( V_14 ) ;
}
static int F_25 ( const unsigned char * V_2 , int V_34 , T_2 * V_35 ,
T_3 * V_4 )
{
T_5 * V_10 ;
T_4 V_36 , V_37 , V_38 ;
V_31 * V_39 = NULL ;
int V_14 = - 1 ;
if ( ! V_4 -> V_15 || ! V_4 -> V_16 || ! V_4 -> V_17 )
{
F_14 ( V_40 , V_18 ) ;
return - 1 ;
}
if ( ( V_10 = F_6 () ) == NULL ) goto V_19;
F_3 ( & V_36 ) ;
F_3 ( & V_37 ) ;
F_3 ( & V_38 ) ;
if ( F_20 ( V_35 -> V_6 ) || V_35 -> V_6 -> V_41 || F_26 ( V_35 -> V_6 , V_4 -> V_16 ) >= 0 )
{
V_14 = 0 ;
goto V_19;
}
if ( F_20 ( V_35 -> V_7 ) || V_35 -> V_7 -> V_41 || F_26 ( V_35 -> V_7 , V_4 -> V_16 ) >= 0 )
{
V_14 = 0 ;
goto V_19;
}
if ( ( F_24 ( & V_37 , V_35 -> V_7 , V_4 -> V_16 , V_10 ) ) == NULL ) goto V_19;
if ( F_8 ( V_2 , V_34 , & V_36 ) == NULL ) goto V_19;
if ( ! F_9 ( & V_36 , & V_36 , & V_37 , V_4 -> V_16 , V_10 ) ) goto V_19;
if ( ! F_9 ( & V_37 , V_35 -> V_6 , & V_37 , V_4 -> V_16 , V_10 ) ) goto V_19;
if ( ( V_4 -> V_28 == NULL ) && ( V_4 -> V_29 & V_30 ) )
{
if ( ( V_4 -> V_28 = ( char * ) F_21 () ) != NULL )
if ( ! F_22 ( ( V_31 * ) V_4 -> V_28 ,
V_4 -> V_15 , V_10 ) ) goto V_19;
}
V_39 = ( V_31 * ) V_4 -> V_28 ;
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
if ( ! V_4 -> V_32 -> V_42 ( V_4 , & V_38 , V_4 -> V_17 , & V_36 , V_4 -> V_43 , & V_37 ,
V_4 -> V_15 , V_10 , V_39 ) ) goto V_19;
if ( ! F_23 ( & V_36 , & V_38 , V_4 -> V_16 , V_10 ) ) goto V_19;
}
#endif
V_14 = ( F_26 ( & V_36 , V_35 -> V_6 ) == 0 ) ;
V_19:
if ( V_14 != 1 ) F_14 ( V_40 , V_13 ) ;
if ( V_10 != NULL ) F_16 ( V_10 ) ;
F_15 ( & V_36 ) ;
F_15 ( & V_37 ) ;
F_15 ( & V_38 ) ;
return ( V_14 ) ;
}
static int F_27 ( T_3 * V_4 )
{
V_4 -> V_29 |= V_30 ;
return ( 1 ) ;
}
static int F_28 ( T_3 * V_4 )
{
if( V_4 -> V_28 )
F_29 ( ( V_31 * ) V_4 -> V_28 ) ;
return ( 1 ) ;
}
static int V_42 ( T_3 * V_4 , T_4 * V_44 , T_4 * V_45 , T_4 * V_46 ,
T_4 * V_47 , T_4 * V_48 , T_4 * V_8 , T_5 * V_10 ,
V_31 * V_49 )
{
return F_30 ( V_44 , V_45 , V_46 , V_47 , V_48 , V_8 , V_10 , V_49 ) ;
}
static int F_31 ( T_3 * V_4 , T_4 * V_6 , T_4 * V_50 , const T_4 * V_15 ,
const T_4 * V_8 , T_5 * V_10 ,
V_31 * V_51 )
{
return F_32 ( V_6 , V_50 , V_15 , V_8 , V_10 , V_51 ) ;
}
