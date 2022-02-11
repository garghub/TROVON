void F_1 ( const T_1 * V_1 )
{
V_2 = V_1 ;
}
const T_1 * F_2 ( void )
{
if( ! V_2 )
V_2 = F_3 () ;
return V_2 ;
}
int F_4 ( T_2 * V_3 , const T_1 * V_1 )
{
const T_1 * V_4 ;
T_3 * V_5 ;
V_5 = F_5 ( V_3 ) ;
if ( V_5 == NULL )
return 0 ;
V_4 = V_5 -> V_1 ;
#if 0
if (mtmp->finish)
mtmp->finish(eckey);
#endif
#ifndef F_6
if ( V_5 -> V_6 )
{
F_7 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
}
#endif
V_5 -> V_1 = V_1 ;
#if 0
if (meth->init)
meth->init(eckey);
#endif
return 1 ;
}
static T_3 * F_8 ( T_4 * V_6 )
{
T_3 * V_7 ;
V_7 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
if ( V_7 == NULL )
{
F_10 ( V_8 , V_9 ) ;
return ( NULL ) ;
}
V_7 -> V_10 = NULL ;
V_7 -> V_1 = F_2 () ;
V_7 -> V_6 = V_6 ;
#ifndef F_6
if ( ! V_7 -> V_6 )
V_7 -> V_6 = F_11 () ;
if ( V_7 -> V_6 )
{
V_7 -> V_1 = F_12 ( V_7 -> V_6 ) ;
if ( ! V_7 -> V_1 )
{
F_10 ( V_8 , V_11 ) ;
F_7 ( V_7 -> V_6 ) ;
F_13 ( V_7 ) ;
return NULL ;
}
}
#endif
V_7 -> V_12 = V_7 -> V_1 -> V_12 ;
F_14 ( V_13 , V_7 , & V_7 -> V_14 ) ;
#if 0
if ((ret->meth->init != NULL) && !ret->meth->init(ret))
{
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_ECDH, ret, &ret->ex_data);
OPENSSL_free(ret);
ret=NULL;
}
#endif
return ( V_7 ) ;
}
static void * F_15 ( void )
{
return ( void * ) F_8 ( NULL ) ;
}
static void * F_16 ( void * V_15 )
{
T_3 * V_16 = ( T_3 * ) V_15 ;
if ( V_16 == NULL )
return NULL ;
return ( void * ) F_15 () ;
}
void F_17 ( void * V_15 )
{
T_3 * V_16 = ( T_3 * ) V_15 ;
#ifndef F_6
if ( V_16 -> V_6 )
F_7 ( V_16 -> V_6 ) ;
#endif
F_18 ( V_13 , V_16 , & V_16 -> V_14 ) ;
F_19 ( ( void * ) V_16 , sizeof( T_3 ) ) ;
F_13 ( V_16 ) ;
}
T_3 * F_5 ( T_2 * V_17 )
{
T_3 * V_18 ;
void * V_15 = F_20 ( V_17 , F_16 ,
F_17 , F_17 ) ;
if ( V_15 == NULL )
{
V_18 = ( T_3 * ) F_15 () ;
if ( V_18 == NULL )
return NULL ;
F_21 ( V_17 , ( void * ) V_18 ,
F_16 , F_17 , F_17 ) ;
}
else
V_18 = ( T_3 * ) V_15 ;
return V_18 ;
}
int F_22 ( long V_19 , void * V_20 , T_5 * V_21 ,
T_6 * V_22 , T_7 * V_23 )
{
return F_23 ( V_13 , V_19 , V_20 ,
V_21 , V_22 , V_23 ) ;
}
int F_24 ( T_2 * V_24 , int V_25 , void * V_26 )
{
T_3 * V_5 ;
V_5 = F_5 ( V_24 ) ;
if ( V_5 == NULL )
return 0 ;
return ( F_25 ( & V_5 -> V_14 , V_25 , V_26 ) ) ;
}
void * F_26 ( T_2 * V_24 , int V_25 )
{
T_3 * V_5 ;
V_5 = F_5 ( V_24 ) ;
if ( V_5 == NULL )
return NULL ;
return ( F_27 ( & V_5 -> V_14 , V_25 ) ) ;
}
