int F_1 ( const T_1 * V_1 )
{
int V_2 ;
if ( V_1 == NULL )
return 0 ;
F_2 () ;
V_2 = F_3 ( F_4 ( V_1 -> V_3 ) , V_4 ,
( const char * ) V_1 ) ;
if ( V_2 == 0 )
return ( 0 ) ;
F_5 ( V_1 -> V_3 ) ;
V_2 = F_3 ( F_6 ( V_1 -> V_3 ) , V_4 ,
( const char * ) V_1 ) ;
return ( V_2 ) ;
}
int F_7 ( const T_2 * V_5 )
{
int V_2 ;
const char * V_6 ;
F_2 () ;
V_6 = F_4 ( V_5 -> type ) ;
V_2 = F_3 ( V_6 , V_7 , ( const char * ) V_5 ) ;
if ( V_2 == 0 )
return ( 0 ) ;
F_5 ( V_5 -> type ) ;
V_2 = F_3 ( F_6 ( V_5 -> type ) , V_7 ,
( const char * ) V_5 ) ;
if ( V_2 == 0 )
return ( 0 ) ;
if ( V_5 -> V_8 && V_5 -> type != V_5 -> V_8 ) {
V_2 = F_3 ( F_4 ( V_5 -> V_8 ) ,
V_7 | V_9 , V_6 ) ;
if ( V_2 == 0 )
return ( 0 ) ;
F_5 ( V_5 -> V_8 ) ;
V_2 = F_3 ( F_6 ( V_5 -> V_8 ) ,
V_7 | V_9 , V_6 ) ;
}
return ( V_2 ) ;
}
const T_1 * F_8 ( const char * V_6 )
{
const T_1 * V_10 ;
V_10 = ( const T_1 * ) F_9 ( V_6 , V_4 ) ;
return ( V_10 ) ;
}
const T_2 * F_10 ( const char * V_6 )
{
const T_2 * V_10 ;
V_10 = ( const T_2 * ) F_9 ( V_6 , V_7 ) ;
return ( V_10 ) ;
}
void F_11 ( void )
{
F_12 ( V_4 ) ;
F_12 ( V_7 ) ;
F_12 ( - 1 ) ;
F_13 () ;
if ( V_11 == 2 ) {
V_11 = 0 ;
F_14 () ;
}
F_15 () ;
}
static void F_16 ( const T_3 * V_12 , void * V_13 )
{
struct V_14 * V_15 = V_13 ;
if ( V_12 -> V_16 )
V_15 -> V_17 ( NULL , V_12 -> V_6 , V_12 -> V_18 , V_15 -> V_13 ) ;
else
V_15 -> V_17 ( ( const T_1 * ) V_12 -> V_18 , V_12 -> V_6 , NULL , V_15 -> V_13 ) ;
}
void F_17 ( void (* V_17) ( const T_1 * V_19 ,
const char * V_20 , const char * V_21 , void * V_22 ) ,
void * V_13 )
{
struct V_14 V_15 ;
V_15 . V_17 = V_17 ;
V_15 . V_13 = V_13 ;
F_18 ( V_4 , F_16 , & V_15 ) ;
}
void F_19 ( void (* V_17) ( const T_1 * V_19 ,
const char * V_20 , const char * V_21 ,
void * V_22 ) , void * V_13 )
{
struct V_14 V_15 ;
V_15 . V_17 = V_17 ;
V_15 . V_13 = V_13 ;
F_20 ( V_4 , F_16 , & V_15 ) ;
}
static void F_21 ( const T_3 * V_12 , void * V_13 )
{
struct V_23 * V_15 = V_13 ;
if ( V_12 -> V_16 )
V_15 -> V_17 ( NULL , V_12 -> V_6 , V_12 -> V_18 , V_15 -> V_13 ) ;
else
V_15 -> V_17 ( ( const T_2 * ) V_12 -> V_18 , V_12 -> V_6 , NULL , V_15 -> V_13 ) ;
}
void F_22 ( void (* V_17) ( const T_2 * V_5 ,
const char * V_20 , const char * V_21 , void * V_22 ) ,
void * V_13 )
{
struct V_23 V_15 ;
V_15 . V_17 = V_17 ;
V_15 . V_13 = V_13 ;
F_18 ( V_7 , F_21 , & V_15 ) ;
}
void F_23 ( void (* V_17) ( const T_2 * V_5 ,
const char * V_20 , const char * V_21 ,
void * V_22 ) , void * V_13 )
{
struct V_23 V_15 ;
V_15 . V_17 = V_17 ;
V_15 . V_13 = V_13 ;
F_20 ( V_7 , F_21 , & V_15 ) ;
}
