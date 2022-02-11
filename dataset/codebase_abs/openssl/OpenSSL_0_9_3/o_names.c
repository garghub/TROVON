int F_1 ( void )
{
if ( V_1 != NULL ) return ( 1 ) ;
F_2 () ;
V_1 = F_3 ( V_2 , V_3 ) ;
F_4 () ;
return ( V_1 != NULL ) ;
}
static int V_3 ( T_1 * V_4 , T_1 * V_5 )
{
int V_6 ;
int (* F_5)();
V_6 = V_4 -> type - V_5 -> type ;
if ( V_6 == 0 )
{
if ( ( V_7 != NULL ) && ( F_6 ( V_7 ) > V_4 -> type ) )
{
F_5 = ( int ( * ) () ) F_7 ( V_7 , V_4 -> type ) ;
V_6 = F_5 ( V_4 -> V_8 , V_5 -> V_8 ) ;
}
else
V_6 = strcmp ( V_4 -> V_8 , V_5 -> V_8 ) ;
}
return ( V_6 ) ;
}
static unsigned long V_2 ( T_1 * V_4 )
{
unsigned long V_6 ;
unsigned long ( * V_9 ) () ;
if ( ( V_10 != NULL ) && ( F_6 ( V_10 ) > V_4 -> type ) )
{
V_9 = ( unsigned long ( * ) () ) F_7 ( V_10 , V_4 -> type ) ;
V_6 = V_9 ( V_4 -> V_8 ) ;
}
else
{
V_6 = F_8 ( V_4 -> V_8 ) ;
}
V_6 ^= V_4 -> type ;
return ( V_6 ) ;
}
const char * F_9 ( const char * V_8 , int type )
{
T_1 V_11 , * V_6 ;
int V_12 = 0 , V_13 ;
if ( V_8 == NULL ) return ( NULL ) ;
if ( ( V_1 == NULL ) && ! F_1 () ) return ( NULL ) ;
V_13 = type & V_14 ;
type &= ~ V_14 ;
V_11 . V_8 = V_8 ;
V_11 . type = type ;
for (; ; )
{
V_6 = ( T_1 * ) F_10 ( V_1 , ( char * ) & V_11 ) ;
if ( V_6 == NULL ) return ( NULL ) ;
if ( ( V_6 -> V_13 ) && ! V_13 )
{
if ( ++ V_12 > 10 ) return ( NULL ) ;
V_11 . V_8 = V_6 -> V_15 ;
}
else
{
return ( V_6 -> V_15 ) ;
}
}
}
int F_11 ( const char * V_8 , int type , const char * V_15 )
{
void (* F_12)();
T_1 * V_16 , * V_6 ;
int V_13 ;
if ( ( V_1 == NULL ) && ! F_1 () ) return ( 0 ) ;
V_13 = type & V_14 ;
type &= ~ V_14 ;
V_16 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_16 == NULL )
{
return ( 0 ) ;
}
V_16 -> V_8 = V_8 ;
V_16 -> V_13 = V_13 ;
V_16 -> type = type ;
V_16 -> V_15 = V_15 ;
V_6 = ( T_1 * ) F_13 ( V_1 , ( char * ) V_16 ) ;
if ( V_6 != NULL )
{
if ( ( V_17 != NULL ) && ( F_6 ( V_17 ) > V_6 -> type ) )
{
F_12 = ( void ( * ) () ) F_7 ( V_17 , V_6 -> type ) ;
F_12 ( V_6 -> V_8 , V_6 -> type , V_6 -> V_15 ) ;
}
Free ( ( char * ) V_6 ) ;
}
else
{
if ( F_14 ( V_1 ) )
{
return ( 0 ) ;
}
}
return ( 1 ) ;
}
int F_15 ( const char * V_8 , int type )
{
T_1 V_11 , * V_6 ;
void (* F_12)();
if ( V_1 == NULL ) return ( 0 ) ;
type &= ~ V_14 ;
V_11 . V_8 = V_8 ;
V_11 . type = type ;
V_6 = ( T_1 * ) F_16 ( V_1 , ( char * ) & V_11 ) ;
if ( V_6 != NULL )
{
if ( ( V_17 != NULL ) && ( F_6 ( V_17 ) > type ) )
{
F_12 = ( void ( * ) () ) F_7 ( V_17 , type ) ;
F_12 ( V_6 -> V_8 , V_6 -> type , V_6 -> V_15 ) ;
}
Free ( ( char * ) V_6 ) ;
return ( 1 ) ;
}
else
return ( 0 ) ;
}
static void F_17 ( T_1 * V_16 , int type )
{
if( V_16 == NULL )
return;
if ( ( V_18 < 0 ) || ( V_18 == V_16 -> type ) )
{
F_15 ( V_16 -> V_8 , V_16 -> type ) ;
}
}
void F_18 ( int type )
{
unsigned long V_19 ;
if ( V_1 == NULL ) return;
V_18 = type ;
V_19 = V_1 -> V_19 ;
V_1 -> V_19 = 0 ;
F_19 ( V_1 , F_17 ) ;
if ( type < 0 )
{
F_20 ( V_1 ) ;
F_21 ( V_10 ) ;
F_21 ( V_7 ) ;
F_21 ( V_17 ) ;
V_1 = NULL ;
V_10 = NULL ;
V_7 = NULL ;
V_17 = NULL ;
}
else
V_1 -> V_19 = V_19 ;
}
