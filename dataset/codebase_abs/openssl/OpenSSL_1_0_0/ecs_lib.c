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
#ifndef F_6
if ( V_5 -> V_6 )
{
F_7 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
}
#endif
V_5 -> V_1 = V_1 ;
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
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_ECDSA, ret, &ret->ex_data);
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
return F_15 () ;
}
static void F_17 ( void * V_15 )
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
int F_22 ( const T_2 * V_16 )
{
int V_7 , V_19 ;
T_5 V_20 ;
T_6 * V_21 = NULL ;
unsigned char V_22 [ 4 ] ;
const T_7 * V_23 ;
if ( V_16 == NULL )
return 0 ;
V_23 = F_23 ( V_16 ) ;
if ( V_23 == NULL )
return 0 ;
if ( ( V_21 = F_24 () ) == NULL ) return 0 ;
if ( ! F_25 ( V_23 , V_21 , NULL ) )
{
F_26 ( V_21 ) ;
return 0 ;
}
V_19 = F_27 ( V_21 ) ;
V_20 . V_24 = ( V_19 + 7 ) / 8 ;
V_20 . V_15 = V_22 ;
V_20 . type = V_25 ;
V_22 [ 0 ] = 0xff ;
V_19 = F_28 ( & V_20 , NULL ) ;
V_19 += V_19 ;
V_7 = F_29 ( 1 , V_19 , V_26 ) ;
F_26 ( V_21 ) ;
return ( V_7 ) ;
}
int F_30 ( long V_27 , void * V_28 , T_8 * V_29 ,
T_9 * V_30 , T_10 * V_31 )
{
return F_31 ( V_13 , V_27 , V_28 ,
V_29 , V_30 , V_31 ) ;
}
int F_32 ( T_2 * V_32 , int V_33 , void * V_34 )
{
T_3 * V_5 ;
V_5 = F_5 ( V_32 ) ;
if ( V_5 == NULL )
return 0 ;
return ( F_33 ( & V_5 -> V_14 , V_33 , V_34 ) ) ;
}
void * F_34 ( T_2 * V_32 , int V_33 )
{
T_3 * V_5 ;
V_5 = F_5 ( V_32 ) ;
if ( V_5 == NULL )
return NULL ;
return ( F_35 ( & V_5 -> V_14 , V_33 ) ) ;
}
