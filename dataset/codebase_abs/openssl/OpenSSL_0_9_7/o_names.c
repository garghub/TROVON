int F_1 ( void )
{
if ( V_1 != NULL ) return ( 1 ) ;
F_2 () ;
V_1 = F_3 ( V_2 , V_3 ) ;
F_4 () ;
return ( V_1 != NULL ) ;
}
static int V_3 ( const void * V_4 , const void * V_5 )
{
int V_6 ;
T_1 * V_7 = ( T_1 * ) V_4 ;
T_1 * V_8 = ( T_1 * ) V_5 ;
V_6 = V_7 -> type - V_8 -> type ;
if ( V_6 == 0 )
{
if ( ( V_9 != NULL )
&& ( F_5 ( V_9 ) > V_7 -> type ) )
{
V_6 = F_6 ( V_9 ,
V_7 -> type ) -> F_7 ( V_7 -> V_10 , V_8 -> V_10 ) ;
}
else
V_6 = strcmp ( V_7 -> V_10 , V_8 -> V_10 ) ;
}
return ( V_6 ) ;
}
static unsigned long V_2 ( const void * V_4 )
{
unsigned long V_6 ;
T_1 * V_7 = ( T_1 * ) V_4 ;
if ( ( V_9 != NULL ) && ( F_5 ( V_9 ) > V_7 -> type ) )
{
V_6 = F_6 ( V_9 ,
V_7 -> type ) -> F_8 ( V_7 -> V_10 ) ;
}
else
{
V_6 = F_9 ( V_7 -> V_10 ) ;
}
V_6 ^= V_7 -> type ;
return ( V_6 ) ;
}
const char * F_10 ( const char * V_10 , int type )
{
T_1 V_11 , * V_6 ;
int V_12 = 0 , V_13 ;
if ( V_10 == NULL ) return ( NULL ) ;
if ( ( V_1 == NULL ) && ! F_1 () ) return ( NULL ) ;
V_13 = type & V_14 ;
type &= ~ V_14 ;
V_11 . V_10 = V_10 ;
V_11 . type = type ;
for (; ; )
{
V_6 = ( T_1 * ) F_11 ( V_1 , & V_11 ) ;
if ( V_6 == NULL ) return ( NULL ) ;
if ( ( V_6 -> V_13 ) && ! V_13 )
{
if ( ++ V_12 > 10 ) return ( NULL ) ;
V_11 . V_10 = V_6 -> V_15 ;
}
else
{
return ( V_6 -> V_15 ) ;
}
}
}
int F_12 ( const char * V_10 , int type , const char * V_15 )
{
T_1 * V_16 , * V_6 ;
int V_13 ;
if ( ( V_1 == NULL ) && ! F_1 () ) return ( 0 ) ;
V_13 = type & V_14 ;
type &= ~ V_14 ;
V_16 = ( T_1 * ) F_13 ( sizeof( T_1 ) ) ;
if ( V_16 == NULL )
{
return ( 0 ) ;
}
V_16 -> V_10 = V_10 ;
V_16 -> V_13 = V_13 ;
V_16 -> type = type ;
V_16 -> V_15 = V_15 ;
V_6 = ( T_1 * ) F_14 ( V_1 , V_16 ) ;
if ( V_6 != NULL )
{
if ( ( V_9 != NULL ) && ( F_5 ( V_9 ) > V_6 -> type ) )
{
F_6 ( V_9 ,
V_6 -> type ) -> F_15 ( V_6 -> V_10 , V_6 -> type , V_6 -> V_15 ) ;
}
F_16 ( V_6 ) ;
}
else
{
if ( F_17 ( V_1 ) )
{
return ( 0 ) ;
}
}
return ( 1 ) ;
}
int F_18 ( const char * V_10 , int type )
{
T_1 V_11 , * V_6 ;
if ( V_1 == NULL ) return ( 0 ) ;
type &= ~ V_14 ;
V_11 . V_10 = V_10 ;
V_11 . type = type ;
V_6 = ( T_1 * ) F_19 ( V_1 , & V_11 ) ;
if ( V_6 != NULL )
{
if ( ( V_9 != NULL ) && ( F_5 ( V_9 ) > V_6 -> type ) )
{
F_6 ( V_9 ,
V_6 -> type ) -> F_15 ( V_6 -> V_10 , V_6 -> type , V_6 -> V_15 ) ;
}
F_16 ( V_6 ) ;
return ( 1 ) ;
}
else
return ( 0 ) ;
}
static void F_20 ( const T_1 * V_10 , struct V_17 * V_18 )
{
if( V_10 -> type == V_18 -> type )
V_18 -> V_19 ( V_10 , V_18 -> V_20 ) ;
}
static void F_21 ( const T_1 * V_10 , void * V_21 )
{
struct V_22 * V_18 = V_21 ;
if( V_10 -> type != V_18 -> type )
return;
V_18 -> V_23 [ V_18 -> V_24 ++ ] = V_10 ;
}
static int F_22 ( const void * V_25 , const void * V_26 )
{
const T_1 * const * V_27 = V_25 ;
const T_1 * const * V_28 = V_26 ;
return strcmp ( ( * V_27 ) -> V_10 , ( * V_28 ) -> V_10 ) ;
}
void F_23 ( int type , void (* V_19)( const T_1 * , void * V_20 ) ,
void * V_20 )
{
struct V_22 V_18 ;
int V_24 ;
V_18 . type = type ;
V_18 . V_23 = F_13 ( F_24 ( V_1 ) * sizeof * V_18 . V_23 ) ;
V_18 . V_24 = 0 ;
F_25 ( type , F_21 , & V_18 ) ;
qsort ( ( void * ) V_18 . V_23 , V_18 . V_24 , sizeof * V_18 . V_23 , F_22 ) ;
for( V_24 = 0 ; V_24 < V_18 . V_24 ; ++ V_24 )
V_19 ( V_18 . V_23 [ V_24 ] , V_20 ) ;
F_16 ( ( void * ) V_18 . V_23 ) ;
}
static void F_26 ( T_1 * V_16 )
{
if( V_16 == NULL )
return;
if ( ( V_29 < 0 ) || ( V_29 == V_16 -> type ) )
{
F_18 ( V_16 -> V_10 , V_16 -> type ) ;
}
}
