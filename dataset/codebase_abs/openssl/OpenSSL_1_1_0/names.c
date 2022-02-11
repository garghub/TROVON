int F_1 ( const T_1 * V_1 )
{
int V_2 ;
if ( V_1 == NULL )
return 0 ;
V_2 = F_2 ( F_3 ( V_1 -> V_3 ) , V_4 ,
( const char * ) V_1 ) ;
if ( V_2 == 0 )
return ( 0 ) ;
V_2 = F_2 ( F_4 ( V_1 -> V_3 ) , V_4 ,
( const char * ) V_1 ) ;
return ( V_2 ) ;
}
int F_5 ( const T_2 * V_5 )
{
int V_2 ;
const char * V_6 ;
V_6 = F_3 ( V_5 -> type ) ;
V_2 = F_2 ( V_6 , V_7 , ( const char * ) V_5 ) ;
if ( V_2 == 0 )
return ( 0 ) ;
V_2 = F_2 ( F_4 ( V_5 -> type ) , V_7 ,
( const char * ) V_5 ) ;
if ( V_2 == 0 )
return ( 0 ) ;
if ( V_5 -> V_8 && V_5 -> type != V_5 -> V_8 ) {
V_2 = F_2 ( F_3 ( V_5 -> V_8 ) ,
V_7 | V_9 , V_6 ) ;
if ( V_2 == 0 )
return ( 0 ) ;
V_2 = F_2 ( F_4 ( V_5 -> V_8 ) ,
V_7 | V_9 , V_6 ) ;
}
return ( V_2 ) ;
}
const T_1 * F_6 ( const char * V_6 )
{
const T_1 * V_10 ;
if ( ! F_7 ( V_11 , NULL ) )
return NULL ;
V_10 = ( const T_1 * ) F_8 ( V_6 , V_4 ) ;
return ( V_10 ) ;
}
const T_2 * F_9 ( const char * V_6 )
{
const T_2 * V_10 ;
if ( ! F_7 ( V_12 , NULL ) )
return NULL ;
V_10 = ( const T_2 * ) F_8 ( V_6 , V_7 ) ;
return ( V_10 ) ;
}
void F_10 ( void )
{
F_11 ( V_4 ) ;
F_11 ( V_7 ) ;
F_11 ( - 1 ) ;
F_12 () ;
F_13 () ;
}
static void F_14 ( const T_3 * V_13 , void * V_14 )
{
struct V_15 * V_16 = V_14 ;
if ( V_13 -> V_17 )
V_16 -> V_18 ( NULL , V_13 -> V_6 , V_13 -> V_19 , V_16 -> V_14 ) ;
else
V_16 -> V_18 ( ( const T_1 * ) V_13 -> V_19 , V_13 -> V_6 , NULL , V_16 -> V_14 ) ;
}
void F_15 ( void (* V_18) ( const T_1 * V_20 ,
const char * V_21 , const char * V_22 , void * V_23 ) ,
void * V_14 )
{
struct V_15 V_16 ;
F_7 ( V_11 , NULL ) ;
V_16 . V_18 = V_18 ;
V_16 . V_14 = V_14 ;
F_16 ( V_4 , F_14 , & V_16 ) ;
}
void F_17 ( void (* V_18) ( const T_1 * V_20 ,
const char * V_21 , const char * V_22 ,
void * V_23 ) , void * V_14 )
{
struct V_15 V_16 ;
F_7 ( V_11 , NULL ) ;
V_16 . V_18 = V_18 ;
V_16 . V_14 = V_14 ;
F_18 ( V_4 , F_14 , & V_16 ) ;
}
static void F_19 ( const T_3 * V_13 , void * V_14 )
{
struct V_24 * V_16 = V_14 ;
if ( V_13 -> V_17 )
V_16 -> V_18 ( NULL , V_13 -> V_6 , V_13 -> V_19 , V_16 -> V_14 ) ;
else
V_16 -> V_18 ( ( const T_2 * ) V_13 -> V_19 , V_13 -> V_6 , NULL , V_16 -> V_14 ) ;
}
void F_20 ( void (* V_18) ( const T_2 * V_5 ,
const char * V_21 , const char * V_22 , void * V_23 ) ,
void * V_14 )
{
struct V_24 V_16 ;
F_7 ( V_12 , NULL ) ;
V_16 . V_18 = V_18 ;
V_16 . V_14 = V_14 ;
F_16 ( V_7 , F_19 , & V_16 ) ;
}
void F_21 ( void (* V_18) ( const T_2 * V_5 ,
const char * V_21 , const char * V_22 ,
void * V_23 ) , void * V_14 )
{
struct V_24 V_16 ;
F_7 ( V_12 , NULL ) ;
V_16 . V_18 = V_18 ;
V_16 . V_14 = V_14 ;
F_18 ( V_7 , F_19 , & V_16 ) ;
}
