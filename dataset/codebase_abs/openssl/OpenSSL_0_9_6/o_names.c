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
V_6 = V_4 -> type - V_5 -> type ;
if ( V_6 == 0 )
{
if ( ( V_7 != NULL )
&& ( F_5 ( V_7 ) > V_4 -> type ) )
{
V_6 = F_6 ( V_7 , V_4 -> type )
-> F_7 ( V_4 -> V_8 , V_5 -> V_8 ) ;
}
else
V_6 = strcmp ( V_4 -> V_8 , V_5 -> V_8 ) ;
}
return ( V_6 ) ;
}
static unsigned long V_2 ( T_1 * V_4 )
{
unsigned long V_6 ;
if ( ( V_7 != NULL ) && ( F_5 ( V_7 ) > V_4 -> type ) )
{
V_6 = F_6 ( V_7 , V_4 -> type )
-> F_8 ( V_4 -> V_8 ) ;
}
else
{
V_6 = F_9 ( V_4 -> V_8 ) ;
}
V_6 ^= V_4 -> type ;
return ( V_6 ) ;
}
const char * F_10 ( const char * V_8 , int type )
{
T_1 V_9 , * V_6 ;
int V_10 = 0 , V_11 ;
if ( V_8 == NULL ) return ( NULL ) ;
if ( ( V_1 == NULL ) && ! F_1 () ) return ( NULL ) ;
V_11 = type & V_12 ;
type &= ~ V_12 ;
V_9 . V_8 = V_8 ;
V_9 . type = type ;
for (; ; )
{
V_6 = ( T_1 * ) F_11 ( V_1 , & V_9 ) ;
if ( V_6 == NULL ) return ( NULL ) ;
if ( ( V_6 -> V_11 ) && ! V_11 )
{
if ( ++ V_10 > 10 ) return ( NULL ) ;
V_9 . V_8 = V_6 -> V_13 ;
}
else
{
return ( V_6 -> V_13 ) ;
}
}
}
int F_12 ( const char * V_8 , int type , const char * V_13 )
{
T_1 * V_14 , * V_6 ;
int V_11 ;
if ( ( V_1 == NULL ) && ! F_1 () ) return ( 0 ) ;
V_11 = type & V_12 ;
type &= ~ V_12 ;
V_14 = ( T_1 * ) F_13 ( sizeof( T_1 ) ) ;
if ( V_14 == NULL )
{
return ( 0 ) ;
}
V_14 -> V_8 = V_8 ;
V_14 -> V_11 = V_11 ;
V_14 -> type = type ;
V_14 -> V_13 = V_13 ;
V_6 = ( T_1 * ) F_14 ( V_1 , V_14 ) ;
if ( V_6 != NULL )
{
if ( ( V_7 != NULL ) && ( F_5 ( V_7 ) > V_6 -> type ) )
{
F_6 ( V_7 , V_6 -> type )
-> F_15 ( V_6 -> V_8 , V_6 -> type , V_6 -> V_13 ) ;
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
int F_18 ( const char * V_8 , int type )
{
T_1 V_9 , * V_6 ;
if ( V_1 == NULL ) return ( 0 ) ;
type &= ~ V_12 ;
V_9 . V_8 = V_8 ;
V_9 . type = type ;
V_6 = ( T_1 * ) F_19 ( V_1 , & V_9 ) ;
if ( V_6 != NULL )
{
if ( ( V_7 != NULL ) && ( F_5 ( V_7 ) > V_6 -> type ) )
{
F_6 ( V_7 , V_6 -> type )
-> F_15 ( V_6 -> V_8 , V_6 -> type , V_6 -> V_13 ) ;
}
F_16 ( V_6 ) ;
return ( 1 ) ;
}
else
return ( 0 ) ;
}
static void F_20 ( T_1 * V_14 , int type )
{
if( V_14 == NULL )
return;
if ( ( V_15 < 0 ) || ( V_15 == V_14 -> type ) )
{
F_18 ( V_14 -> V_8 , V_14 -> type ) ;
}
}
static void F_21 ( T_2 * V_16 )
{
F_16 ( V_16 ) ;
}
void F_22 ( int type )
{
unsigned long V_17 ;
if ( V_1 == NULL ) return;
V_15 = type ;
V_17 = V_1 -> V_17 ;
V_1 -> V_17 = 0 ;
F_23 ( V_1 , F_20 ) ;
if ( type < 0 )
{
F_24 ( V_1 ) ;
F_25 ( V_7 , F_21 ) ;
V_1 = NULL ;
V_7 = NULL ;
}
else
V_1 -> V_17 = V_17 ;
}
