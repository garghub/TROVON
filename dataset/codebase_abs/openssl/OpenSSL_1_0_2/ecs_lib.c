void F_1 ( const T_1 * V_1 )
{
V_2 = V_1 ;
}
const T_1 * F_2 ( void )
{
if ( ! V_2 ) {
#ifdef F_3
if ( F_4 () )
return F_5 () ;
else
return F_6 () ;
#else
V_2 = F_6 () ;
#endif
}
return V_2 ;
}
int F_7 ( T_2 * V_3 , const T_1 * V_1 )
{
T_3 * V_4 ;
V_4 = F_8 ( V_3 ) ;
if ( V_4 == NULL )
return 0 ;
#ifndef F_9
if ( V_4 -> V_5 ) {
F_10 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
}
#endif
V_4 -> V_1 = V_1 ;
return 1 ;
}
static T_3 * F_11 ( T_4 * V_5 )
{
T_3 * V_6 ;
V_6 = ( T_3 * ) F_12 ( sizeof( T_3 ) ) ;
if ( V_6 == NULL ) {
F_13 ( V_7 , V_8 ) ;
return ( NULL ) ;
}
V_6 -> V_9 = NULL ;
V_6 -> V_1 = F_2 () ;
V_6 -> V_5 = V_5 ;
#ifndef F_9
if ( ! V_6 -> V_5 )
V_6 -> V_5 = F_14 () ;
if ( V_6 -> V_5 ) {
V_6 -> V_1 = F_15 ( V_6 -> V_5 ) ;
if ( ! V_6 -> V_1 ) {
F_13 ( V_7 , V_10 ) ;
F_10 ( V_6 -> V_5 ) ;
F_16 ( V_6 ) ;
return NULL ;
}
}
#endif
V_6 -> V_11 = V_6 -> V_1 -> V_11 ;
F_17 ( V_12 , V_6 , & V_6 -> V_13 ) ;
#if 0
if ((ret->meth->init != NULL) && !ret->meth->init(ret)) {
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_ECDSA, ret, &ret->ex_data);
OPENSSL_free(ret);
ret = NULL;
}
#endif
return ( V_6 ) ;
}
static void * F_18 ( void )
{
return ( void * ) F_11 ( NULL ) ;
}
static void * F_19 ( void * V_14 )
{
T_3 * V_15 = ( T_3 * ) V_14 ;
if ( V_15 == NULL )
return NULL ;
return F_18 () ;
}
static void F_20 ( void * V_14 )
{
T_3 * V_15 = ( T_3 * ) V_14 ;
#ifndef F_9
if ( V_15 -> V_5 )
F_10 ( V_15 -> V_5 ) ;
#endif
F_21 ( V_12 , V_15 , & V_15 -> V_13 ) ;
F_22 ( ( void * ) V_15 , sizeof( T_3 ) ) ;
F_16 ( V_15 ) ;
}
T_3 * F_8 ( T_2 * V_16 )
{
T_3 * V_17 ;
void * V_14 = F_23 ( V_16 , F_19 ,
F_20 , F_20 ) ;
if ( V_14 == NULL ) {
V_17 = ( T_3 * ) F_18 () ;
if ( V_17 == NULL )
return NULL ;
V_14 = F_24 ( V_16 , ( void * ) V_17 ,
F_19 , F_20 ,
F_20 ) ;
if ( V_14 != NULL ) {
F_20 ( V_17 ) ;
V_17 = ( T_3 * ) V_14 ;
}
} else
V_17 = ( T_3 * ) V_14 ;
#ifdef F_3
if ( F_4 () && ! ( V_17 -> V_11 & V_18 )
&& ! ( F_25 ( V_16 ) & V_19 ) ) {
F_13 ( V_20 , V_21 ) ;
return NULL ;
}
#endif
return V_17 ;
}
int F_26 ( const T_2 * V_15 )
{
int V_6 , V_22 ;
T_5 V_23 ;
T_6 * V_24 = NULL ;
unsigned char V_25 [ 4 ] ;
const T_7 * V_26 ;
if ( V_15 == NULL )
return 0 ;
V_26 = F_27 ( V_15 ) ;
if ( V_26 == NULL )
return 0 ;
if ( ( V_24 = F_28 () ) == NULL )
return 0 ;
if ( ! F_29 ( V_26 , V_24 , NULL ) ) {
F_30 ( V_24 ) ;
return 0 ;
}
V_22 = F_31 ( V_24 ) ;
V_23 . V_27 = ( V_22 + 7 ) / 8 ;
V_23 . V_14 = V_25 ;
V_23 . type = V_28 ;
V_25 [ 0 ] = 0xff ;
V_22 = F_32 ( & V_23 , NULL ) ;
V_22 += V_22 ;
V_6 = F_33 ( 1 , V_22 , V_29 ) ;
F_30 ( V_24 ) ;
return ( V_6 ) ;
}
int F_34 ( long V_30 , void * V_31 , T_8 * V_32 ,
T_9 * V_33 , T_10 * V_34 )
{
return F_35 ( V_12 , V_30 , V_31 ,
V_32 , V_33 , V_34 ) ;
}
int F_36 ( T_2 * V_35 , int V_36 , void * V_37 )
{
T_3 * V_4 ;
V_4 = F_8 ( V_35 ) ;
if ( V_4 == NULL )
return 0 ;
return ( F_37 ( & V_4 -> V_13 , V_36 , V_37 ) ) ;
}
void * F_38 ( T_2 * V_35 , int V_36 )
{
T_3 * V_4 ;
V_4 = F_8 ( V_35 ) ;
if ( V_4 == NULL )
return NULL ;
return ( F_39 ( & V_4 -> V_13 , V_36 ) ) ;
}
T_1 * F_40 ( T_1 * V_38 )
{
T_1 * V_6 ;
V_6 = F_12 ( sizeof( T_1 ) ) ;
if ( V_6 == NULL ) {
F_13 ( V_39 , V_8 ) ;
return NULL ;
}
if ( V_38 )
* V_6 = * V_38 ;
else {
V_6 -> V_40 = 0 ;
V_6 -> V_41 = 0 ;
V_6 -> V_42 = 0 ;
V_6 -> V_43 = NULL ;
V_6 -> V_11 = 0 ;
}
V_6 -> V_11 |= V_44 ;
return V_6 ;
}
void F_41 ( T_1 * V_45 ,
T_11 * (* V_41) ( const unsigned char
* V_46 , int V_47 ,
const T_6 * V_48 ,
const T_6 * V_49 ,
T_2 * V_3 ) )
{
V_45 -> V_41 = V_41 ;
}
void F_42 ( T_1 * V_45 ,
int (* V_40) ( T_2 * V_3 ,
T_12 * V_50 ,
T_6 * * V_51 ,
T_6 * * V_15 ) )
{
V_45 -> V_40 = V_40 ;
}
void F_43 ( T_1 * V_45 ,
int (* V_42) ( const unsigned char
* V_46 , int V_47 ,
const T_11 * V_52 ,
T_2 * V_3 ) )
{
V_45 -> V_42 = V_42 ;
}
void F_44 ( T_1 * V_45 , int V_11 )
{
V_45 -> V_11 = V_11 | V_44 ;
}
void F_45 ( T_1 * V_45 , char * V_43 )
{
V_45 -> V_43 = V_43 ;
}
void F_46 ( T_1 * V_45 )
{
if ( V_45 -> V_11 & V_44 )
F_16 ( V_45 ) ;
}
void F_47 ( T_1 * V_45 , void * V_53 )
{
V_45 -> V_54 = V_53 ;
}
void * F_48 ( T_1 * V_45 )
{
return V_45 -> V_54 ;
}
