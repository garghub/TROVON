T_1 * F_1 ( int (* F_2)( const char * const * , const char * const * ) )
{
T_1 * V_1 ;
int V_2 ;
if ( ( V_1 = ( T_1 * ) F_3 ( sizeof( T_1 ) ) ) == NULL )
goto V_3;
if ( ( V_1 -> V_4 = ( char * * ) F_3 ( sizeof( char * ) * V_5 ) ) == NULL )
goto V_3;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ )
V_1 -> V_4 [ V_2 ] = NULL ;
V_1 -> V_6 = F_2 ;
V_1 -> V_7 = V_5 ;
V_1 -> V_8 = 0 ;
V_1 -> V_9 = 0 ;
return ( V_1 ) ;
V_3:
if( V_1 )
F_4 ( V_1 ) ;
return ( NULL ) ;
}
int F_5 ( T_1 * V_10 , char * V_4 , int V_11 )
{
char * * V_12 ;
if( V_10 == NULL ) return 0 ;
if ( V_10 -> V_7 <= V_10 -> V_8 + 1 )
{
V_12 = ( char * * ) F_6 ( ( char * ) V_10 -> V_4 ,
( unsigned int ) sizeof( char * ) * V_10 -> V_7 * 2 ) ;
if ( V_12 == NULL )
return ( 0 ) ;
V_10 -> V_4 = V_12 ;
V_10 -> V_7 *= 2 ;
}
if ( ( V_11 >= ( int ) V_10 -> V_8 ) || ( V_11 < 0 ) )
V_10 -> V_4 [ V_10 -> V_8 ] = V_4 ;
else
{
int V_2 ;
char * * V_13 , * * V_14 ;
V_13 = ( char * * ) V_10 -> V_4 ;
V_14 = ( char * * ) & ( V_10 -> V_4 [ 1 ] ) ;
for ( V_2 = V_10 -> V_8 ; V_2 >= V_11 ; V_2 -- )
V_14 [ V_2 ] = V_13 [ V_2 ] ;
#ifdef undef
memmove ( ( char * ) & ( V_10 -> V_4 [ V_11 + 1 ] ) ,
( char * ) & ( V_10 -> V_4 [ V_11 ] ) ,
sizeof( char * ) * ( V_10 -> V_8 - V_11 ) ) ;
#endif
V_10 -> V_4 [ V_11 ] = V_4 ;
}
V_10 -> V_8 ++ ;
V_10 -> V_9 = 0 ;
return ( V_10 -> V_8 ) ;
}
char * F_7 ( T_1 * V_10 , char * V_15 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_10 -> V_8 ; V_2 ++ )
if ( V_10 -> V_4 [ V_2 ] == V_15 )
return ( F_8 ( V_10 , V_2 ) ) ;
return ( NULL ) ;
}
char * F_8 ( T_1 * V_10 , int V_11 )
{
char * V_1 ;
int V_2 , V_16 ;
if( ! V_10 || ( V_11 < 0 ) || ( V_11 >= V_10 -> V_8 ) ) return NULL ;
V_1 = V_10 -> V_4 [ V_11 ] ;
if ( V_11 != V_10 -> V_8 - 1 )
{
V_16 = V_10 -> V_8 - 1 ;
for ( V_2 = V_11 ; V_2 < V_16 ; V_2 ++ )
V_10 -> V_4 [ V_2 ] = V_10 -> V_4 [ V_2 + 1 ] ;
}
V_10 -> V_8 -- ;
return ( V_1 ) ;
}
static int F_9 ( T_1 * V_10 , char * V_4 , int V_17 )
{
char * * V_18 ;
int V_2 ;
int (* F_10)( const void * , const void * );
if( V_10 == NULL ) return - 1 ;
if ( V_10 -> V_6 == NULL )
{
for ( V_2 = 0 ; V_2 < V_10 -> V_8 ; V_2 ++ )
if ( V_10 -> V_4 [ V_2 ] == V_4 )
return ( V_2 ) ;
return ( - 1 ) ;
}
F_11 ( V_10 ) ;
if ( V_4 == NULL ) return ( - 1 ) ;
F_10 = ( int ( * ) ( const void * , const void * ) ) ( V_10 -> V_6 ) ;
V_18 = ( char * * ) F_12 ( ( char * ) & V_4 , ( char * ) V_10 -> V_4 ,
V_10 -> V_8 , sizeof( char * ) , F_10 , V_17 ) ;
if ( V_18 == NULL ) return ( - 1 ) ;
return ( ( int ) ( V_18 - V_10 -> V_4 ) ) ;
}
int F_13 ( T_1 * V_10 , char * V_4 )
{
return F_9 ( V_10 , V_4 , V_19 ) ;
}
int F_14 ( T_1 * V_10 , char * V_4 )
{
return F_9 ( V_10 , V_4 , V_20 ) ;
}
int F_15 ( T_1 * V_10 , char * V_4 )
{
return ( F_5 ( V_10 , V_4 , V_10 -> V_8 ) ) ;
}
int F_16 ( T_1 * V_10 , char * V_4 )
{
return ( F_5 ( V_10 , V_4 , 0 ) ) ;
}
char * F_17 ( T_1 * V_10 )
{
if ( V_10 == NULL ) return ( NULL ) ;
if ( V_10 -> V_8 <= 0 ) return ( NULL ) ;
return ( F_8 ( V_10 , 0 ) ) ;
}
char * F_18 ( T_1 * V_10 )
{
if ( V_10 == NULL ) return ( NULL ) ;
if ( V_10 -> V_8 <= 0 ) return ( NULL ) ;
return ( F_8 ( V_10 , V_10 -> V_8 - 1 ) ) ;
}
void F_19 ( T_1 * V_10 )
{
if ( V_10 == NULL ) return;
if ( V_10 -> V_8 <= 0 ) return;
memset ( ( char * ) V_10 -> V_4 , 0 , sizeof( V_10 -> V_4 ) * V_10 -> V_8 ) ;
V_10 -> V_8 = 0 ;
}
void F_20 ( T_1 * V_10 , void (* F_21)( void * ) )
{
int V_2 ;
if ( V_10 == NULL ) return;
for ( V_2 = 0 ; V_2 < V_10 -> V_8 ; V_2 ++ )
if ( V_10 -> V_4 [ V_2 ] != NULL )
F_21 ( V_10 -> V_4 [ V_2 ] ) ;
F_22 ( V_10 ) ;
}
void F_22 ( T_1 * V_10 )
{
if ( V_10 == NULL ) return;
if ( V_10 -> V_4 != NULL ) F_4 ( V_10 -> V_4 ) ;
F_4 ( V_10 ) ;
}
int F_23 ( const T_1 * V_10 )
{
if( V_10 == NULL ) return - 1 ;
return V_10 -> V_8 ;
}
char * F_24 ( const T_1 * V_10 , int V_2 )
{
if( ! V_10 || ( V_2 < 0 ) || ( V_2 >= V_10 -> V_8 ) ) return NULL ;
return V_10 -> V_4 [ V_2 ] ;
}
char * F_25 ( T_1 * V_10 , int V_2 , char * V_21 )
{
if( ! V_10 || ( V_2 < 0 ) || ( V_2 >= V_10 -> V_8 ) ) return NULL ;
return ( V_10 -> V_4 [ V_2 ] = V_21 ) ;
}
void F_11 ( T_1 * V_10 )
{
if ( V_10 && ! V_10 -> V_9 )
{
int (* F_10)( const void * , const void * );
F_10 = ( int ( * ) ( const void * , const void * ) ) ( V_10 -> V_6 ) ;
qsort ( V_10 -> V_4 , V_10 -> V_8 , sizeof( char * ) , F_10 ) ;
V_10 -> V_9 = 1 ;
}
}
int F_26 ( const T_1 * V_10 )
{
if ( ! V_10 )
return 1 ;
return V_10 -> V_9 ;
}
